#!/usr/bin/env python3
"""Merge unverified reconstruction waves into the src/ source tree.

Copies every non-class wave's sources into src/<subsystem>/<wave>/, where the
subsystem (game, engine, platform, crt) is the majority band of the wave's
declared addresses, merges manifests, copies the class/vtable map, and writes
the remaining matchable queue to reconstruction/ (index + generated evidence).
The src/<subsystem>/*.cpp unit files and src/README.md are hand-maintained and
never touched. Idempotent: rebuilds the generated wave dirs from the wave
outputs.
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
SRC = ROOT / "src"
INVENTORY = ROOT / "build" / "functions.json"

# Band table from findings/2026-11-08-team-decompilation.md (contiguous
# inventory ranges and their heuristic subsystem label).
BANDS = [
    ("game", 0x401000, 0x4C3690),
    ("game", 0x4C3790, 0x514090),
    ("engine", 0x5141C0, 0x54ADA0),
    ("engine", 0x54AE10, 0x5913A0),
    ("game", 0x591460, 0x5DAB60),
    ("engine", 0x5DB0A0, 0x61003C),
    ("engine", 0x610165, 0x672E90),
    ("crt", 0x672ECD, 0x6BFC80),
]


def subsystem_for_address(address: str) -> str:
    value = int(address, 16)
    best = BANDS[0][0]
    best_distance = None
    for name, start, end in BANDS:
        if start <= value <= end:
            return name
        distance = min(abs(value - start), abs(value - end))
        if best_distance is None or distance < best_distance:
            best, best_distance = name, distance
    return best


def route_wave(addresses: list[str]) -> str:
    counts = Counter(subsystem_for_address(a) for a in addresses)
    return sorted(counts.items(), key=lambda kv: (-kv[1], kv[0]))[0][0]


def clean_generated_wave_dirs() -> None:
    for subsystem in ("game", "engine", "platform", "crt"):
        base = SRC / subsystem
        if not base.exists():
            continue
        for child in base.iterdir():
            if (
                child.is_dir()
                and (child.name.startswith("band") or child.name.startswith("mass") or child.name == "lead")
            ):
                shutil.rmtree(child)


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
    for generated in ("include", "src"):
        if (DEST / generated).exists():
            shutil.rmtree(DEST / generated)
    (DEST / "include").mkdir()
    SRC.mkdir(parents=True, exist_ok=True)
    clean_generated_wave_dirs()

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
        addresses = [str(e.get("address", "")) for e in entries if e.get("address")]
        subsystem = route_wave(addresses)
        wave_src = SRC / subsystem / wave
        wave_src.mkdir(parents=True, exist_ok=True)
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
            row["subsystem"] = subsystem
            row["source"] = str(target.relative_to(ROOT))
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
        "toolchain": "cl 13.10.3077 installed (analysis/toolchain via tools/wine-cl.sh); "
        "3 units PASS (tiny_547610, tiny_54a9f0, tiny_5366b0); every other candidate is unverified",
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
        "`tools/merge_reconstruction.py` into `src/<subsystem>/<wave>/`. Wave",
        "candidates are **UNVERIFIED** by byte-match; the verified tier is the",
        "unit files declared in `build/units.json` (currently 3 PASS with",
        "`cl 13.10.3077`).",
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
        "Wave sources live under `src/<subsystem>/<wave>/` (subsystem is the",
        "majority band of the wave's addresses); headers from the class map live",
        "under `include/classes/`. `manifest.json` carries per-function evidence",
        "and unknowns; `QUEUE.json` is the remaining matchable set.",
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
