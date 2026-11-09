#!/usr/bin/env python3
"""Generate docs/progress.json + docs/progress.html from the match census.

Progress = matchable functions (build/functions.json) whose unit compiled with
the recovered VC7.1 toolchain and byte-compared identical against the shipped
Pirates!.exe (tools/match.py PASS). Three states, honest by construction:

- PASS        verdict from match.py in the pinned census run
- FAIL        verdict from match.py (compiled, bytes differ)
- UNVERIFIED  no verdict yet: unclaimed, or a census unit-level error where
              individual verdicts were never emitted

Reads:
- build/functions.json   denominator + per-function span/code bytes
- build/units.json       claimed units (id, source path for subsystem)
- build/progress-census.json  pinned census (tools/compare_census.py)

Writes:
- docs/progress.json     data consumed by the page (and shaped so a future
                         decompilati.onl POST needs no rethink)
- docs/progress.html     self-contained static page (inline JSON, no fetch)

Run tools/compare_census.py first; this file only reads. Deterministic for a
given census: no ambient time or network input.
"""
from __future__ import annotations

import hashlib
import html
import json
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
FUNC = ROOT / "build" / "functions.json"
UNIT = ROOT / "build" / "units.json"
MANIFEST = ROOT / "reconstruction" / "manifest.json"
CENSUS = ROOT / "build" / "progress-census.json"
OUT_JSON = ROOT / "docs" / "progress.json"
OUT_HTML = ROOT / "docs" / "index.html"

# Page shows subsystem (game/engine/crt/...) as "areas".
SUBSYSTEMS = ["game", "engine", "platform", "crt"]


def load(census_path: Path = CENSUS):
    functions = json.loads(FUNC.read_text())["functions"]
    matchable = [f for f in functions if f.get("category", "function") == "function" and not f.get("thunk", False)]
    units = json.loads(UNIT.read_text())["units"]
    manifest = json.loads(MANIFEST.read_text())
    census = json.loads(census_path.read_text())
    return functions, matchable, units, manifest, census


def subsystem_for(unit_source: str, unit_id: str) -> str | None:
    # Generated units compile from build/units-src/gen_*.cpp; only hand units
    # live under src/<subsystem>/. None lets classify() fall back to the
    # reconstruction manifest's per-address routing.
    for sub in SUBSYSTEMS:
        if unit_source.startswith(f"src/{sub}/"):
            return sub
    return None


def classify(matchable, units, manifest, census):
    """Map every matchable address to PASS / FAIL / UNVERIFIED.

    Precedence: the census's per-function verdicts win; they are the only
    source of PASS/FAIL. A unit-level census row without verdicts (error
    before any verdict line) leaves its claimed functions UNVERIFIED.
    Subsystem falls back to the reconstruction manifest's per-address routing.
    """
    manifest_sub = {
        fn["address"].lower(): fn.get("subsystem", "other")
        for fn in manifest["functions"]
    }
    unit_subsystem = {}
    claimed_by = {}
    for unit in units:
        sub = subsystem_for(unit["source"], unit["id"])
        for entry in unit["functions"]:
            address = entry["address"].lower()
            unit_subsystem[address] = sub
            # A repeated claim is a config error; match.py check guards it.
            claimed_by[address] = unit["id"]

    verdict_status = {}      # address -> PASS/FAIL/UNVERIFIED
    verdict_unit = {}        # address -> census unit id
    verdict_symbol = {}
    for unit_id, row in census["units"].items():
        for fn in row.get("functions") or []:
            address = fn["address"].lower()
            verdict_status[address] = fn["status"]
            verdict_unit[address] = unit_id
            verdict_symbol[address] = fn["symbol"]

    rows = []
    passed = failed = unverified = 0
    match_bytes = {"PASS": 0, "FAIL": 0, "UNVERIFIED": 0}
    total_bytes = 0
    for f in matchable:
        address = f["address"].lower()
        span = int(f.get("span") or 0)
        total_bytes += span
        status = verdict_status.get(address, "UNVERIFIED")
        if status == "PASS":
            passed += 1
        elif status == "FAIL":
            failed += 1
        else:
            unverified += 1
        match_bytes[status] += span
        rows.append({
            "address": f["address"],
            "symbol": verdict_symbol.get(address) or f["name"],
            "unit": verdict_unit.get(address) or claimed_by.get(address),
            "subsystem": unit_subsystem.get(address) or manifest_sub.get(address, "other"),
            "span": span,
            "status": status,
        })
    return rows, {"PASS": passed, "FAIL": failed, "UNVERIFIED": unverified}, match_bytes, total_bytes


def areas_of(rows):
    areas = []
    per = defaultdict(lambda: {"PASS": 0, "FAIL": 0, "UNVERIFIED": 0, "total": 0, "bytes": 0, "match_bytes": 0})
    for row in rows:
        bucket = per[row["subsystem"]]
        bucket[row["status"]] += 1
        bucket["total"] += 1
        bucket["bytes"] += row["span"]
        if row["status"] == "PASS":
            bucket["match_bytes"] += row["span"]
    for name in sorted(per):
        data = per[name]
        areas.append({"name": name, **data})
    return areas


STATUS_ORDER = {"PASS": 0, "FAIL": 1, "UNVERIFIED": 2}


def build_doc(rows, counts, match_bytes, total_bytes, units, census, matchable_count):
    areas = areas_of(rows)
    rows = sorted(rows, key=lambda r: (STATUS_ORDER[r["status"]], int(r["address"], 16)))
    by_unit_fail = defaultdict(int)
    by_unit_pass = defaultdict(int)
    for row in rows:
        if row["status"] == "PASS":
            by_unit_pass[row["unit"]] += 1
        elif row["status"] == "FAIL":
            by_unit_fail[row["unit"]] += 1
    failing_units = sorted(
        ({u for u in by_unit_fail if by_unit_fail[u] > 0} | {u for u in by_unit_pass}) - {None},
        key=lambda u: (-(by_unit_pass[u] + by_unit_fail[u]), u),
    )[:12]
    doc = {
        "schema": "pirates-progress/1",
        "unit": "functions",
        # decompilati.onl-style counters, extended with `unverified` because
        # our census is three-state (a failing-to-compile unit has no verdict).
        "functions": {
            "total": matchable_count,
            "matching": counts["PASS"],
            "non_matching": counts["FAIL"],
            "unverified": counts["UNVERIFIED"],
        },
        "code": {
            "total": total_bytes,
            "matching": match_bytes["PASS"],
            "non_matching": match_bytes["FAIL"],
            "unverified": match_bytes["UNVERIFIED"],
        },
        "areas": areas,
        "units": {
            "declared": len(units),
            "with_verdicts": len({r["unit"] for r in rows if r["unit"] and by_unit_pass.get(r["unit"], 0) + by_unit_fail.get(r["unit"], 0) > 0}),
            "failing_top": [
                {"id": u, "pass": by_unit_pass[u], "fail": by_unit_fail[u]} for u in failing_units
            ],
        },
        "pin": census.get("pin", {}),
        "detail": rows,
    }
    return doc, areas, by_unit_pass, by_unit_fail


def write_html(doc, areas, match_bytes, total_bytes, by_unit_pass, by_unit_fail):
    pct = doc["functions"]["matching"] / doc["functions"]["total"] if doc["functions"]["total"] else 0.0
    byte_pct = match_bytes["PASS"] / total_bytes if total_bytes else 0.0
    unit_rows = "".join(
        "<tr><td>{u}</td><td>{p}</td><td>{f}</td></tr>".format(
            u=html.escape(str(u)), p=d["pass"], f=d["fail"]
        )
        for u, d in ((e["id"], e) for e in doc["units"]["failing_top"])
    )
    area_rows = "".join(
        "<tr><td>{name}</td><td>{total}</td><td>{passed}</td><td>{failed}</td><td>{unv}</td><td>{pb}</td></tr>".format(
            name=html.escape(a["name"]),
            total=a["total"],
            passed=a["PASS"],
            failed=a["FAIL"],
            unv=a["UNVERIFIED"],
            pb=f"{a['match_bytes']}/{a['bytes']}",
        )
        for a in areas
    )
    unit_rows = "".join(
        "<tr><td>{u}</td><td>{p}</td><td>{f}</td></tr>".format(
            u=html.escape(str(u)), p=d["pass"], f=d["fail"]
        )
        for u, d in ((e["id"], e) for e in doc["units"]["failing_top"])
    )
    stale = bool((doc["pin"] or {}).get("stale"))
    stale_note = (
        '<p><b>Stale census</b>: this page was generated from a census whose pinned '
        '<code>units.json</code> diverges from the current tree; verdicts remain the '
        "pinned run's truth until the census is rerun.</p>\n" if stale else ""
    )
    detail_rows = "".join(
        '<tr data-s="{st}" data-q="{q}"><td>{addr}</td><td>{sym}</td><td>{u}</td><td>{sub}</td><td class="num">{n}</td><td>{st}</td></tr>'.format(
            st=html.escape(r["status"]),
            q=html.escape(
                f'{r["address"]} {r["symbol"]} {r["unit"] or ""} {r["subsystem"]} {r["status"]}'.lower()
            ),
            addr=html.escape(r["address"]),
            sym=html.escape(r["symbol"]),
            u=html.escape(str(r["unit"] or "")),
            sub=html.escape(r["subsystem"]),
            n=r["span"],
        )
        for r in doc["detail"]
    )
    page = f"""<!doctype html>
<html lang="en">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>Sid Meier's Pirates! (2004) decompilation progress</title>
<style>
:root {{ color-scheme: light dark; }}
body {{ font-family: -apple-system, "Segoe UI", sans-serif; margin: 2rem auto; max-width: 60rem; padding: 0 1rem; }}
table {{ border-collapse: collapse; margin: 1rem 0; }}
td, th {{ border: 1px solid #8886; padding: .25rem .6rem; text-align: left; }}
.num {{ text-align: right; }}
.bar {{ display: inline-block; height: .8rem; background: #4caf50; vertical-align: middle; }}
.bar.fail {{ background: #e05a4e; }}
.bar.unv {{ background: #9994; }}
small.muted {{ opacity: .65; }}
tr[data-s] td {{ border-color: transparent #8886; }}
tr.PASS td:last-child {{ color: #1b7f3b; font-weight: 600; }}
tr.FAIL td:last-child {{ color: #c0392b; font-weight: 600; }}
</style>
</head>
<body>
<h1>Sid Meier's Pirates! (2004) — matching decompilation progress</h1>
<p>Matched = a function whose decompiled source compiles with the recovered
VC&nbsp;7.1 toolchain (<code>cl</code> 13.10.3077) and byte-compares identical to the shipped
executable under <code>tools/match.py</code>. <b>UNVERIFIED</b> means no byte verdict yet:
unit failed to compile in the last census run or is not yet claimed.
Raw data: <a href="progress.json">progress.json</a> (schema <code>pirates-progress/1</code>).</p>
{stale_note}<p>Functions matched: <b>{doc['functions']['matching']}</b> / {doc['functions']['total']} = {pct*100:.2f}%<br>
<span class="bar" style="width:{int(pct*400)}px"></span><span class="bar fail" style="width:{int(doc['functions']['non_matching']/doc['functions']['total']*400)}px"></span><span class="bar unv" style="width:{int(doc['functions']['unverified']/doc['functions']['total']*400)}px"></span>
<small class="muted">green PASS · red FAIL · grey UNVERIFIED</small></p>
<p>Matched code bytes: <b>{match_bytes['PASS']:,}</b> / {total_bytes:,} = {byte_pct*100:.2f}%</p>
<h2>By subsystem</h2>
<table>
<tr><th>subsystem</th><th>functions</th><th>PASS</th><th>FAIL</th><th>UNVERIFIED</th><th>code matched/total (B)</th></tr>
{area_rows}
</table>
<h2>Units with verdicts</h2>
<table>
<tr><th>unit</th><th>PASS</th><th>FAIL</th></tr>
{unit_rows}
</table>
<h2>Per-function detail</h2>
<p><input id="filter" type="text" placeholder="filter: symbol / address / unit / PASS|FAIL|UNVERIFIED" style="width: 24rem">
<span id="count"></span></p>
<table id="detail">
<tr><th>address</th><th>symbol</th><th>unit</th><th>subsystem</th><th>bytes</th><th>status</th></tr>
{detail_rows}
</table>
<p><small class="muted">Generated by tools/make_progress.py from the pinned census run
{html.escape(str(doc['pin'].get('generated_utc', '')))}
(units {str(doc['pin'].get('units_sha256', ''))[:16]}). Recommitted with each verified set growth.</small></p>
<script>
(function () {{
  const rows = Array.from(document.querySelectorAll('#detail tr[data-s]'));
  const count = document.getElementById('count');
  function apply() {{
    const q = document.getElementById('filter').value.trim().toLowerCase();
    let shown = 0;
    for (const tr of rows) {{
      const on = !q || tr.dataset.q.indexOf(q) !== -1;
      tr.hidden = !on;
      if (on) shown++;
    }}
    count.textContent = ' ' + shown + ' / ' + rows.length + ' functions';
  }}
  document.getElementById('filter').addEventListener('input', apply);
  apply();
}})();
</script>
</body>
</html>
"""
    OUT_HTML.write_text(page)
    OUT_JSON.write_text(json.dumps(doc, indent=1) + "\n")


def main() -> int:
    census_path = CENSUS
    if "--census" in sys.argv:
        census_path = Path(sys.argv[sys.argv.index("--census") + 1])
    functions, matchable, units, manifest, census = load(census_path)
    pinned_units_sha = (census.get("pin") or {}).get("units_sha256")
    current_units_sha = hashlib.sha256(UNIT.read_bytes()).hexdigest()
    complete = census.get("complete")
    if complete is False:
        print(
            f"ERROR: {census_path} is a checkpoint (complete=false); "
            "rerun tools/compare_census.py to finish the run.",
            file=sys.stderr,
        )
        return 1
    if not complete:
        print(
            f"WARNING: {census_path} has no complete flag (older runner); "
            "proceeding on coverage counts.",
            file=sys.stderr,
        )
    stale = pinned_units_sha != current_units_sha
    if stale:
        print(
            f"WARNING: census pin (units {str(pinned_units_sha)[:16]}) != current units.json "
            f"({current_units_sha[:16]}); page published with stale_pin provenance, "
            "rerun tools/compare_census.py to refresh verdicts.",
            file=sys.stderr,
        )
    rows, counts, match_bytes, total_bytes = classify(matchable, units, manifest, census)
    doc, areas, by_unit_pass, by_unit_fail = build_doc(
        rows, counts, match_bytes, total_bytes, units, census, len(matchable)
    )
    if stale:
        doc["pin"]["stale"] = True
    covered = len(census["units"])
    if complete is not False and covered < len(units):
        doc["pin"]["stale"] = True
        doc["pin"]["census_units"] = covered
        doc["pin"]["declared_units"] = len(units)
    write_html(doc, areas, match_bytes, total_bytes, by_unit_pass, by_unit_fail)
    print(
        f"{doc['functions']['matching']}/{doc['functions']['total']} matched, "
        f"{doc['functions']['non_matching']} FAIL, {doc['functions']['unverified']} UNVERIFIED",
    )
    return 0


if __name__ == "__main__":
    sys.exit(main())
