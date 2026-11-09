#!/usr/bin/env python3
"""End-to-end fixture for tools/match.py.

Builds a two-function C file into a linked PE at .text = 0x401000, then builds
the same source into a COFF object and checks that the harness relocates and
compares it successfully.

Requires i686-w64-mingw32-gcc and i686-w64-mingw32-objdump (or llvm-objdump).
Run from the project root:
  python3 tests/run_fixture.py
"""

from __future__ import annotations

import json
import os
import re
import shutil
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
from pe import PE  # noqa: E402
from match import build_compile_argv  # noqa: E402

CC = "i686-w64-mingw32-gcc"
EXPECTED = ["_add", "_call_add"]


def run(argv: list[str], cwd: str | None = None) -> subprocess.CompletedProcess:
    print(f"+ {' '.join(argv)}")
    result = subprocess.run(argv, cwd=cwd, capture_output=True, text=True)
    if result.stdout:
        print(result.stdout.rstrip())
    if result.returncode != 0:
        sys.stderr.write(result.stdout)
        sys.stderr.write(result.stderr)
        raise SystemExit(f"command failed: {' '.join(argv)}")
    return result


def main() -> int:
    if not shutil.which(CC):
        raise SystemExit(f"{CC} is not installed")
    work = tempfile.mkdtemp(prefix="pirates-fixture-")
    try:
        source = os.path.join(ROOT, "tests", "fixture", "a.c")
        obj = os.path.join(work, "a.o")
        exe = os.path.join(work, "original.exe")
        mapfile = os.path.join(work, "link.map")

        run([CC, "-O2", "-fno-inline", "-c", source, "-o", obj], cwd=work)
        run([
            CC, "-nostdlib", "-Wl,-e,0", "-Wl,--section-start=.text=0x401000",
            f"-Wl,-Map,{mapfile}", obj, "-o", exe,
        ], cwd=work)

        with open(mapfile, "r", encoding="utf-8", errors="replace") as fh:
            text = fh.read()
        addresses: dict[str, int] = {}
        for name in EXPECTED:
            map_name = name.lstrip("_")
            matches = re.findall(
                rf"^\s+0x([0-9a-fA-F]+)\s+_?{re.escape(map_name)}\s*$", text, re.MULTILINE
            )
            if len(matches) != 1:
                raise SystemExit(f"map: expected one address for {name}, got {matches}")
            addresses[name] = int(matches[0], 16)
        ordered = sorted(addresses.items(), key=lambda item: item[1])
        pe = PE(exe)
        text = pe.text_section()
        text_start = pe.image_base + text.virtual_address
        text_end = text_start + text.span

        functions = []
        for index, (name, address) in enumerate(ordered):
            end = ordered[index + 1][1] if index + 1 < len(ordered) else text_end
            functions.append({
                "address": f"0x{address:08x}",
                "name": name,
                "span": end - address,
                "thunk": False,
                "placeholder": False,
                "category": "function",
            })

        inventory = {
            "schema": 1,
            "image": {
                "path_hint": exe,
                "sha256": pe.sha256,
                "size": pe.size,
                "image_base": pe.image_base,
                "entry_point": pe.image_base + pe.entry_point_rva,
                "text_start": text_start,
                "text_end": text_end,
            },
            "counts": {
                "functions": len(functions),
                "placeholders": 0,
                "thunks": 0,
                "eh_funclets": 0,
                "matchable": len(functions),
                "matchable_text_bytes": sum(row["span"] for row in functions),
                "text_bytes": sum(row["span"] for row in functions),
                "text_span": text_end - text_start,
            },
            "functions": functions,
        }
        config = {
            "schema": 1,
            "image": {"sha256": pe.sha256, "size": pe.size},
            "compiler": {
                "id": "fixture-gcc",
                "compile_argv": [CC, "{flags}", "-c", "{src}", "-o", "{obj}"],
            },
            "units": [{
                "id": "fixture",
                "source": source,
                "flags": ["-O2", "-fno-inline"],
                "functions": [
                    {"symbol": name, "address": f"0x{address:08x}"}
                    for name, address in ordered
                ],
            }],
        }

        # The Wine path and flag expansion must not smuggle one argv element.
        probe_unit = {"id": "probe", "source": source, "flags": ["/O2", "/MD"]}
        probe_config = {"compiler": {
            "compile_argv": ["cl", "/c", "{flags}", "{src}", "/Fo{obj}"],
            "path_style": "windows",
        }}
        probe_argv, _ = build_compile_argv(probe_unit, probe_config, work)
        if probe_argv[:4] != ["cl", "/c", "/O2", "/MD"]:
            raise SystemExit(f"flags were not expanded as separate arguments: {probe_argv}")
        if any(not arg for arg in probe_argv):
            raise SystemExit(f"empty argv element: {probe_argv}")
        if not all("\\" in arg for arg in probe_argv[4:]):
            raise SystemExit(f"Wine-visible paths were not converted: {probe_argv}")
        probe_unit["flags"] = []
        empty_argv, _ = build_compile_argv(probe_unit, probe_config, work)
        if "" in empty_argv:
            raise SystemExit(f"empty flags produced an empty argument: {empty_argv}")
        print("flag/path expansion OK")

        inv_path = os.path.join(work, "functions.json")
        cfg_path = os.path.join(work, "units.json")
        with open(inv_path, "w", encoding="utf-8") as fh:
            json.dump(inventory, fh, indent=1)
        with open(cfg_path, "w", encoding="utf-8") as fh:
            json.dump(config, fh, indent=1)

        run([
            sys.executable, os.path.join(ROOT, "tools", "match.py"), "check",
            "--image", exe, "--config", cfg_path, "--functions", inv_path,
        ], cwd=ROOT)
        run([
            sys.executable, os.path.join(ROOT, "tools", "match.py"), "compare",
            "--image", exe, "--config", cfg_path, "--functions", inv_path,
            "--unit", "fixture",
        ], cwd=ROOT)

        # Negative control: one changed byte in the first function must fail.
        tampered = os.path.join(work, "tampered.exe")
        with open(exe, "rb") as fh:
            image = bytearray(fh.read())
        first_address = int(functions[0]["address"], 16)
        file_offset = pe.rva_to_offset(first_address - pe.image_base) + 1
        image[file_offset] ^= 0x01
        with open(tampered, "wb") as fh:
            fh.write(image)
        negative = subprocess.run([
            sys.executable, os.path.join(ROOT, "tools", "match.py"), "compare",
            "--image", tampered, "--config", cfg_path, "--functions", inv_path,
            "--unit", "fixture",
        ], cwd=ROOT, capture_output=True, text=True)
        print(negative.stdout.rstrip())
        if negative.returncode == 0:
            raise SystemExit("negative control passed unexpectedly")
        print("negative control correctly failed")
        print("fixture OK")
        return 0
    finally:
        shutil.rmtree(work, ignore_errors=True)


if __name__ == "__main__":
    sys.exit(main())
