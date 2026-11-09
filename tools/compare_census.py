#!/usr/bin/env python3
"""Run match.py compare across all units and write a structured census.

Parallel: each worker gets its own Wine prefix (PIRATES_WINEPREFIX ->
tools/wine-cl.sh), so concurrent cl.exe runs no longer serialize on the shared
prefix locks. One-time per-worker `wineboot -u` bootstrap; prefixes persist in
analysis/prefixes/w<N>/ across runs and are reused when non-empty.

Output (build/progress-census.json):
- per-unit {status, passed, failed, problems, seconds, functions[]} with
  per-function {address, symbol, status} verdict rows
- totals, first-difference histogram, pin (input SHA-256s), complete: true only
  on the final write; checkpoints carry complete: false and never partial JSON
  (tmp + os.replace)
"""
from __future__ import annotations

import hashlib
import json
import os
import re
import shutil
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
UNITS = ROOT / "build" / "units.json"
IMAGE = ROOT / "experiments" / "2026-11-08-target-identification" / "output" / "extracted" / "app" / "Pirates!.exe"
PREFIX_ROOT = ROOT / "analysis" / "prefixes"
CENSUS = ROOT / "build" / "progress-census.json"
NOISE = re.compile(
    r"msync|esync|fsync|wined3d|dxgi|d3d9|compatdb|upstream|compile:|^\s*$|"
    "MESA|glx|libgl|err:|fixme:|winediag|OpenGL|Gdi|win32|ntdll",
    re.I,
)


VERDICT = re.compile(r"\b(PASS|FAIL)\s+(\S+)\s+@\s+(0x[0-9A-Fa-f]+)")


def find_wineboot() -> str:
    candidate = ROOT / "analysis" / "toolchain" / "wine" / "mach9" / "wine" / "bin" / "wineboot"
    if candidate.exists():
        return str(candidate)
    found = shutil.which("wineboot")
    if found:
        return found
    raise SystemExit("wineboot not found for prefix bootstrap")


def prepare_prefix(prefix: Path) -> None:
    """Create a fresh isolated Wine prefix unless one already exists there."""
    if (prefix / "system.reg").exists():
        return
    shutil.rmtree(prefix, ignore_errors=True)
    prefix.mkdir(parents=True, exist_ok=True)
    subprocess.run([find_wineboot(), "-u"], env={**os.environ, "WINEPREFIX": str(prefix)},
                   capture_output=True, text=True, timeout=300)


def run_unit(unit_id: str, prefix: Path) -> dict:
    start = time.time()
    proc = subprocess.run(
        [sys.executable, str(ROOT / "tools" / "match.py"), "compare", "--unit", unit_id,
         "--image", str(IMAGE)],
        cwd=ROOT, capture_output=True, text=True, timeout=600,
        env={**os.environ, "PIRATES_WINEPREFIX": str(prefix)},
    )
    seconds = round(time.time() - start, 1)
    lines = [l for l in (proc.stdout + proc.stderr).splitlines() if not NOISE.search(l)]
    passed = failed = 0
    diffs: list[str] = []
    problems: list[str] = []
    fns: dict[str, dict] = {}
    for line in lines:
        verdict = VERDICT.search(line)
        if verdict:
            fn = fns.setdefault(
                verdict.group(3).lower(),
                {"address": verdict.group(3).lower(), "symbol": verdict.group(2)},
            )
            fn["status"] = "PASS" if verdict.group(1) == "PASS" else "FAIL"
            if verdict.group(1) == "PASS":
                passed += 1
            else:
                failed += 1
        elif "PASS " in line and "@" in line:
            passed += 1
        elif "FAIL " in line and "@" in line:
            failed += 1
            match = re.search(r"first difference at \+\S+|length differs", line)
            diffs.append(match.group(0) if match else line.split(":", 1)[-1].strip()[:120])
        elif "error C" in line or "fatal error" in line:
            problems.append(line.strip()[:220])
        elif line.strip().startswith(("unresolved", "unresolved symbol", "compiler exited", "unresolved external")):
            problems.append(line.strip()[:200])
        elif re.match(r"\s*(ERROR|HarnessError|Traceback)", line):
            problems.append(line.strip()[:200])
    status = "pass" if proc.returncode == 0 and failed == 0 else ("mixed" if passed or failed else "error")
    return {
        "id": unit_id, "status": status, "passed": passed, "failed": failed,
        "rc": proc.returncode, "seconds": seconds,
        "diffs": sorted(set(diffs))[:6], "problems": problems[:4],
        "functions": sorted(fns.values(), key=lambda f: int(f["address"], 16)),
    }


def pin_inputs() -> dict:
    def dig(path: Path) -> str:
        return hashlib.sha256(path.read_bytes()).hexdigest()

    return {
        "units_sha256": dig(UNITS),
        "image_sha256": dig(IMAGE),
        "functions_sha256": dig(ROOT / "build" / "functions.json"),
        "generated_utc": time.strftime("%Y-%m-%dT%H:%M:%SZ", time.gmtime()),
        "tool": "tools/compare_census.py",
    }


def main() -> int:
    only = None
    if "--only" in sys.argv:
        only = set(Path(sys.argv[sys.argv.index("--only") + 1]).read_text().split())
    workers = 6
    if "--workers" in sys.argv:
        workers = max(1, int(sys.argv[sys.argv.index("--workers") + 1]))
    workers = min(workers, os.cpu_count() or 2)
    pin = pin_inputs()
    units = json.loads(UNITS.read_text())["units"]
    ids = [u["id"] for u in units if only is None or u["id"] in only]

    # One isolated prefix per worker; bootstrapped in parallel up front.
    prefixes = [PREFIX_ROOT / f"w{i}" for i in range(workers)]
    with ThreadPoolExecutor(max_workers=workers) as pool:
        bootstrap = [pool.submit(prepare_prefix, p) for p in prefixes]
        for task in bootstrap:
            task.result()

    census_path = CENSUS
    if only is not None and census_path.exists():
        census = json.loads(census_path.read_text())
    else:
        census = {"units": {}, "totals": {"pass": 0, "mixed": 0, "error": 0,
                                          "functions_passed": 0, "functions_failed": 0}}
    diff_hist: dict = {}

    def atomic_write(payload: dict) -> None:
        tmp = census_path.with_suffix(".json.tmp")
        tmp.write_text(json.dumps(payload, indent=1))
        os.replace(tmp, census_path)

    def totals_of(rows: dict) -> dict:
        totals = {"pass": 0, "mixed": 0, "error": 0, "functions_passed": 0, "functions_failed": 0}
        for existing in rows.values():
            totals[existing["status"]] += 1
            totals["functions_passed"] += existing["passed"]
            totals["functions_failed"] += existing["failed"]
        return totals

    print(f"workers={workers} prefixes={[p.name for p in prefixes]}", flush=True)
    with ThreadPoolExecutor(max_workers=workers) as pool:
        # submit → Future; each future carries its worker's prefix
        pending = {pool.submit(run_unit, unit_id, prefixes[index % workers]): unit_id
                   for index, unit_id in enumerate(ids)}
        done_count = 0
        for future in as_completed(pending):
            unit_id = pending[future]
            try:
                row = future.result()
            except Exception as error:  # timeout or crashed match.py
                row = {"id": unit_id, "status": "error", "passed": 0, "failed": 0,
                       "rc": -1, "seconds": 0.0, "diffs": [], "problems": [str(error)[:200]],
                       "functions": []}
            census["units"][unit_id] = row
            # Totals recomputed over all rows so reruns replace, not double-count.
            census["totals"] = totals_of(census["units"])
            for diff in row["diffs"]:
                key = diff.split(":", 1)[0][:60]
                diff_hist[key] = diff_hist.get(key, 0) + 1
            done_count += 1
            if done_count % 20 == 0 or done_count == len(ids):
                atomic_write({**census, "diff_histogram": diff_hist, "pin": pin,
                              "complete": done_count == len(ids)})
                tot = census["totals"]
                print(f"[{done_count}/{len(ids)}] pass={tot['pass']} mixed={tot['mixed']} "
                      f"error={tot['error']} fnPASS={tot['functions_passed']} "
                      f"fnFAIL={tot['functions_failed']} last={unit_id}", flush=True)
    atomic_write({**census, "diff_histogram": diff_hist, "pin": pin, "complete": True})
    print(json.dumps(census["totals"], indent=1))
    print("pin", json.dumps({k: v[:16] if k.endswith("sha256") else v for k, v in pin.items()}))
    return 0


if __name__ == "__main__":
    sys.exit(main())
