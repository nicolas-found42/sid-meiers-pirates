#!/usr/bin/env python3
"""Check 32-bit field offsets in the generated class headers.

Each header carries explicit `pad_0xNNNN` arrays. This asserts every
`field_0xNN` lands at 0xNN with a 4-byte vtable pointer and the declared
integer sizes. No compiler is needed.
"""
from __future__ import annotations

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
INCLUDE = ROOT / "experiments" / "2026-11-08-source-reconstruction" / "out" / "classes" / "include"


def size_of(type_name: str) -> int:
    t = type_name.lower()
    if "char" in t or "bool" in t:
        return 1
    if "short" in t or "wchar_t" in t:
        return 2
    if "double" in t or "long long" in t:
        return 8
    return 4


def check(path: Path) -> list[str]:
    errors: list[str] = []
    current = 0
    in_struct = False
    for number, line in enumerate(path.read_text().splitlines(), 1):
        if re.match(r"^struct\s+\w+\s*\{", line):
            in_struct = True
            current = 0
            continue
        if in_struct and line.startswith("};"):
            in_struct = False
            continue
        if not in_struct:
            continue
        if re.match(r"^\s*void\s*\*\s*vtable\s*;", line):
            current = 4
            continue
        m = re.match(r"^\s*unsigned char pad_0x([0-9a-f]+)\[(\d+)\]", line)
        if m:
            if int(m.group(1), 16) != current:
                errors.append(f"{path.name}:{number}: pad starts {m.group(1)}, expected {current:04x}")
            current += int(m.group(2))
            continue
        m = re.match(r"^\s*([A-Za-z_][\w\s\*]*?)\s+field_0x([0-9a-f]+)\s*;", line)
        if m:
            offset = int(m.group(2), 16)
            if offset != current:
                errors.append(f"{path.name}:{number}: field at {offset:04x}, layout {current:04x}")
            current = offset + size_of(m.group(1))
    return errors


def main() -> int:
    errors: list[str] = []
    paths = sorted(INCLUDE.glob("*.h"))
    for path in paths:
        errors.extend(check(path))
    for error in errors:
        print(error)
    print(f"headers={len(paths)} errors={len(errors)}")
    return 1 if errors else 0


if __name__ == "__main__":
    sys.exit(main())
