#!/usr/bin/env python3
"""Insert explicit 32-bit padding into generated class headers.

The class-map generator deposited observed fields without the bytes between
them, which would place fields at the wrong offsets if compiled. This rewrites
each struct so every `field_0xNN` sits at 0xNN in a 32-bit target layout.
Idempotent: existing `pad_0xNN` arrays are replaced.
"""
from __future__ import annotations

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
INCLUDE = ROOT / "experiments" / "2026-11-08-source-reconstruction" / "out" / "classes" / "include"

FIELD_RE = re.compile(r"^(\s*)([A-Za-z_][\w\s\*]*?)\s+field_0x([0-9a-fA-F]+)\s*;(.*)$")
PAD_RE = re.compile(r"^\s*unsigned char pad_0x[0-9a-fA-F]+\[")
STRUCT_RE = re.compile(r"^struct\s+(\w+)\s*\{")
END_RE = re.compile(r"^\};")


def type_size(type_name: str) -> int:
    t = type_name.replace("*", " * ").split()
    if not t:
        return 4
    base = t[0].lower()
    if base in ("char", "bool", "byte"):
        return 1
    if base in ("short", "wchar_t"):
        return 2
    if base in ("double", "long") and len(t) > 1 and t[1] == "long":
        return 8
    return 4


def fix_file(path: Path) -> tuple[int, int]:
    lines = path.read_text().splitlines()
    out: list[str] = []
    in_struct = False
    current = 0
    inserts = 0
    fields = 0
    for line in lines:
        if STRUCT_RE.match(line):
            in_struct = True
            current = 0
            out.append(line)
            continue
        if in_struct and END_RE.match(line):
            in_struct = False
            out.append(line)
            continue
        if not in_struct:
            out.append(line)
            continue
        if PAD_RE.match(line):
            continue
        if re.match(r"^\s*void\s*\*\s*vtable\s*;", line):
            current = type_size("void *")
            out.append(line)
            continue
        m = FIELD_RE.match(line)
        if not m:
            out.append(line)
            continue
        indent, type_name, hex_off, tail = m.groups()
        target = int(hex_off, 16)
        size = type_size(type_name)
        if target > current:
            gap = target - current
            out.append(f"{indent}unsigned char pad_0x{current:04x}[{gap}]; // padding to 0x{target:04x}")
            inserts += 1
        current = target + size
        fields += 1
        out.append(line)
    path.write_text("\n".join(out) + "\n")
    return inserts, fields


def main() -> int:
    total_files = total_inserts = total_fields = 0
    for path in sorted(INCLUDE.glob("*.h")):
        inserts, fields = fix_file(path)
        total_files += 1
        total_inserts += inserts
        total_fields += fields
    print(f"files={total_files} fields={total_fields} pads={total_inserts}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
