#!/usr/bin/env python3
"""Build build/functions.json from a Ghidra procedure inventory.

The inventory is the provider's function list (REA list_procedures). Sizes are
not reported there, so each function's span is bounded by the next function
entry inside .text. That span can include alignment padding; the matcher trims
trailing padding on both sides before comparing and records how much it trimmed.

Usage:
  python3 tools/build_inventory.py \
      --bundle analysis/rea-pirates-bundle.json \
      --image "experiments/.../output/extracted/app/Pirates!.exe" \
      --out build/functions.json
"""

from __future__ import annotations

import argparse
import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pe import PE  # noqa: E402


def load_rows(bundle_path: str) -> list[dict]:
    with open(bundle_path, "r", encoding="utf-8") as fh:
        bundle = json.load(fh)
    records = bundle["records"] if isinstance(bundle, dict) else bundle
    for record in records:
        if record.get("operation") == "list_procedures":
            return record["normalized_result"]
    raise SystemExit(f"{bundle_path}: no list_procedures record")


def build(rows: list[dict], pe: PE, image_path: str) -> dict:
    text = pe.text_section()
    text_start = pe.image_base + text.virtual_address
    text_end = text_start + text.span

    functions = []
    for row in rows:
        procedure = row.get("procedure") or {}
        if procedure.get("external"):
            continue
        address = row.get("address", "")
        if not address.startswith("0x"):
            continue
        va = int(address, 16)
        if not (text_start <= va < text_end):
            continue
        functions.append({
            "address": va,
            "name": row.get("value", ""),
            "thunk": bool(procedure.get("thunk")),
        })

    functions.sort(key=lambda row: row["address"])
    if not functions:
        raise SystemExit("no internal functions found")

    for index, function in enumerate(functions):
        next_va = functions[index + 1]["address"] if index + 1 < len(functions) else text_end
        function["span"] = next_va - function["address"]
        function["placeholder"] = (
            function["name"].startswith("FUN_")
            or function["name"].startswith("thunk_")
            or function["name"].startswith("Catch@")
            or function["name"].startswith("Unwind@")
        )
        if function["thunk"]:
            function["category"] = "thunk"
        elif function["name"].startswith(("Catch@", "Unwind@")):
            function["category"] = "eh-funclet"
        else:
            function["category"] = "function"

    matchable = [f for f in functions if f["category"] == "function"]
    return {
        "schema": 1,
        "image": {
            "path_hint": image_path,
            "sha256": pe.sha256,
            "size": pe.size,
            "image_base": pe.image_base,
            "entry_point": pe.image_base + pe.entry_point_rva,
            "text_start": text_start,
            "text_end": text_end,
        },
        "counts": {
            "functions": len(functions),
            "placeholders": sum(1 for f in functions if f["placeholder"]),
            "thunks": sum(1 for f in functions if f["thunk"]),
            "eh_funclets": sum(1 for f in functions if f["category"] == "eh-funclet"),
            "matchable": len(matchable),
            "matchable_text_bytes": sum(f["span"] for f in matchable),
            "text_bytes": sum(f["span"] for f in functions),
            "text_span": text_end - text_start,
        },
        "functions": [
            {
                "address": f"0x{f['address']:08x}",
                "name": f["name"],
                "span": f["span"],
                "thunk": f["thunk"],
                "placeholder": f["placeholder"],
                "category": f["category"],
            }
            for f in functions
        ],
    }


def print_stats(inventory: dict) -> None:
    counts = inventory["counts"]
    spans = [f["span"] for f in inventory["functions"]]
    spans_sorted = sorted(spans)
    median = spans_sorted[len(spans_sorted) // 2]
    print(f"functions        {counts['functions']}")
    print(f"placeholders     {counts['placeholders']}")
    print(f"thunks           {counts['thunks']}")
    print(f"eh funclets      {counts['eh_funclets']}")
    print(f"matchable        {counts['matchable']}")
    print(f"inventoried text {counts['text_bytes']} bytes")
    print(f"matchable text   {counts['matchable_text_bytes']} bytes")
    print(f".text span       {counts['text_span']} bytes")
    print(f"span min/median  {min(spans)} / {median} bytes")
    print(f"span max         {max(spans)} bytes")


def main(argv: list[str]) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--bundle", required=True, help="REA evidence bundle JSON")
    parser.add_argument("--image", required=True, help="shipped PE image")
    parser.add_argument("--out", default="build/functions.json")
    parser.add_argument("--stats", action="store_true")
    args = parser.parse_args(argv)

    pe = PE(args.image)
    inventory = build(load_rows(args.bundle), pe, args.image)

    if args.stats:
        print_stats(inventory)
        if args.out == "-":
            return 0

    os.makedirs(os.path.dirname(os.path.abspath(args.out)), exist_ok=True)
    with open(args.out, "w", encoding="utf-8") as fh:
        json.dump(inventory, fh, indent=1)
        fh.write("\n")
    print(f"wrote {args.out}: {inventory['counts']['functions']} functions", file=sys.stderr)
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
