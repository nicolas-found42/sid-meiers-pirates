#!/usr/bin/env python3
"""Merge unverified reconstruction waves into one source tree.

Copies every non-class wave's sources into reconstruction/src/<wave>/, merges
manifests, copies the class/vtable map, and writes the remaining matchable queue.
Idempotent: rebuilds the generated tree from the wave outputs.
"""
from __future__ import annotations

import json
import shutil
import sys
from collections import Counter
from datetime import date
from pathlib import Path

from recon_status import defines_address, is_partial

ROOT = Path(__file__).resolve().parent.parent
OUT = ROOT / "experiments" / "2026-11-08-source-reconstruction" / "out"
DEST = ROOT / "reconstruction"
INVENTORY = ROOT / "build" / "functions.json"


def load_entries(path: Path) -> list[dict]:
    data = json.loads(path.read_text())
    if isinstance(data, list):
        return data
    return data.get("functions", data.get("entries", []))


def main() -> int:
    inv = json.loads(INVENTORY.read_text())
    functions = {f["address"].lower(): f for f in inv["functions"]}
    matchable = {a for a, f in functions.items() if f.get("category") == "function"}

    DEST.mkdir(parents=True, exist_ok=True)
    for generated in ("src", "include"):
        if (DEST / generated).exists():
            shutil.rmtree(DEST / generated)
    (DEST / "src").mkdir()
    (DEST / "include").mkdir()

    merged: list[dict] = []
    seen: dict[str, str] = {}
    duplicates: list[str] = []
    per_wave: Counter[str] = Counter()
    partial = 0
    bad: list[str] = []

    manifests = sorted(OUT.glob("*/manifest.json"))
    for manifest in manifests:
        wave = manifest.parent.name
        if wave == "classes":
            continue
        entries = load_entries(manifest)
        if not entries:
            bad.append(f"{wave}: empty manifest")
            continue
        wave_src = DEST / "src" / wave
        wave_src.mkdir(exist_ok=True)
        copied: set[str] = set()
        for entry in entries:
            address = str(entry.get("address", "")).lower()
            source = entry.get("source")
            if not address or not source:
                bad.append(f"{wave}: entry without address/source")
                continue
            src_path = manifest.parent / source
            if not src_path.exists():
                bad.append(f"{wave}: missing {source}")
                continue
            target_name = src_path.name
            target = wave_src / target_name
            if target_name not in copied:
                shutil.copy2(src_path, target)
                copied.add(target_name)
            if address in seen:
                duplicates.append(f"{address} ({seen[address]} + {wave})")
                continue
            text = src_path.read_text(errors="replace")
            if not defines_address(text, address):
                bad.append(f"{wave}: {address} absent from {source}")
                continue
            row = dict(entry)
            row["wave"] = wave
            row["source"] = str(target.relative_to(DEST))
            if is_partial(text, entry):
                row["partial"] = True
                partial += 1
            seen[address] = wave
            merged.append(row)
            per_wave[wave] += 1

    merged.sort(key=lambda r: r["address"])
    claimed = set(seen)
    remaining = sorted(matchable - claimed)

    classes = OUT / "classes"
    class_summary = {}
    if classes.exists():
        for name in ("manifest.json", "vtable-map.json"):
            src = classes / name
            if src.exists():
                shutil.copy2(src, DEST / "include" / name)
                class_summary[name] = len(json.loads(src.read_text()))
        include_src = classes / "include"
        if include_src.exists():
            shutil.copytree(include_src, DEST / "include" / "classes")

    manifest_out = {
        "target": inv.get("image"),
        "inventory": inv.get("counts"),
        "generated": date.today().isoformat(),
        "status": "unverified",
        "toolchain": "cl 13.10.3077 absent; no PASS and no byte-match claim",
        "coverage": {
            "matchable": len(matchable),
            "claimed": len(claimed),
            "full_body": len(claimed) - partial,
            "partial": partial,
            "remaining": len(remaining),
            "percent": round(100.0 * len(claimed) / len(matchable), 2) if matchable else 0.0,
        },
        "waves": dict(sorted(per_wave.items())),
        "classes": class_summary,
        "functions": merged,
    }
    (DEST / "manifest.json").write_text(json.dumps(manifest_out, indent=1) + "\n")
    (DEST / "QUEUE.json").write_text(
        json.dumps(
            {
                "count": len(remaining),
                "queue": remaining,
            },
            indent=1,
        )
        + "\n"
    )

    lines = [
        "# Reconstruction tree",
        "",
        "Generated from `experiments/2026-11-08-source-reconstruction/out/` by",
        "`tools/merge_reconstruction.py`. Every function is **UNVERIFIED**:",
        "`cl 13.10.3077` is absent, so no byte-match or PASS claim is made.",
        "",
        f"- matchable functions: {len(matchable)}",
        f"- claimed source functions: {len(claimed)} ({manifest_out['coverage']['percent']}%)",
        f"- full-body candidates: {len(claimed) - partial}",
        f"- partial skeletons: {partial}",
        f"- remaining: {len(remaining)}",
        f"- class/vtable entries: {class_summary.get('manifest.json', 0)}",
        "",
        "| wave | functions |",
        "|---|---:|",
    ]
    lines += [f"| `{wave}` | {count} |" for wave, count in sorted(per_wave.items())]
    lines += [
        "",
        "Sources live under `src/<wave>/`; headers from the class map live under",
        "`include/classes/`. `manifest.json` carries per-function evidence and",
        "unknowns; `QUEUE.json` is the remaining matchable set.",
        "",
    ]
    if duplicates:
        lines += ["## Duplicate claims", ""] + [f"- {d}" for d in duplicates] + [""]
    if bad:
        lines += ["## Bad entries", ""] + [f"- {b}" for b in bad] + [""]
    (DEST / "INDEX.md").write_text("\n".join(lines))

    print(f"waves={len(per_wave)} functions={len(claimed)} remaining={len(remaining)}")
    print(f"full_body={len(claimed) - partial} partial={partial}")
    print(f"duplicates={len(duplicates)} bad={len(bad)}")
    return 1 if duplicates or bad else 0


if __name__ == "__main__":
    sys.exit(main())
