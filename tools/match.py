#!/usr/bin/env python3
"""Matching harness for Sid Meier's Pirates! (2004).

A unit is one translation unit: source file, compiler flags, and the image
addresses of every function and data symbol it is expected to reproduce. The
harness compiles the unit, resolves the object file's COFF relocations against
those declared addresses, and compares each function's bytes with the shipped
image.

Commands:
  check                 validate units.json against the image and inventory
  compare --unit ID     compile one unit and compare its functions
  compare --all         compile and compare every declared unit

An object file produced elsewhere can be compared with --obj, which skips
compilation. This is how the harness is validated without the original MSVC
toolchain installed.
"""

from __future__ import annotations

import argparse
import json
import os
import shutil
import struct
import subprocess
import sys
import tempfile

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pe import PE  # noqa: E402

PAD_BYTES = {0xCC, 0x90, 0x00}

IMAGE_REL_I386_ABSOLUTE = 0x0000
IMAGE_REL_I386_DIR16 = 0x0001
IMAGE_REL_I386_REL16 = 0x0002
IMAGE_REL_I386_DIR32 = 0x0006
IMAGE_REL_I386_DIR32NB = 0x0007
IMAGE_REL_I386_SECTION = 0x000A
IMAGE_REL_I386_SECREL = 0x000B
IMAGE_REL_I386_TOKEN = 0x000C
IMAGE_REL_I386_SECREL7 = 0x000D
IMAGE_REL_I386_REL32 = 0x0014


class HarnessError(Exception):
    pass


class COFF:
    def __init__(self, path: str):
        self.path = path
        with open(path, "rb") as fh:
            self.data = fh.read()
        if len(self.data) < 20:
            raise HarnessError(f"{path}: too small for a COFF object")
        self.machine = self.u16(0)
        self.number_of_sections = self.u16(2)
        self.timestamp = self.u32(4)
        self.pointer_to_symbol_table = self.u32(8)
        self.number_of_symbols = self.u32(12)
        self.optional_header_size = self.u16(16)
        self.characteristics = self.u16(18)
        if self.machine != 0x014C:
            raise HarnessError(f"{path}: expected i386 COFF (0x14c), got {self.machine:#06x}")
        if self.pointer_to_symbol_table == 0 or self.number_of_symbols == 0:
            raise HarnessError(f"{path}: object has no symbol table")

        self.sections = []
        section_offset = 20 + self.optional_header_size
        self.string_table_offset = self.pointer_to_symbol_table + self.number_of_symbols * 18
        self.string_table_size = self.u32(self.string_table_offset) if self.string_table_offset + 4 <= len(self.data) else 0

        for index in range(self.number_of_sections):
            off = section_offset + index * 40
            name = self.data[off:off + 8].rstrip(b"\0").decode("ascii", "replace")
            self.sections.append({
                "index": index + 1,
                "name": name,
                "virtual_size": self.u32(off + 8),
                "virtual_address": self.u32(off + 12),
                "raw_size": self.u32(off + 16),
                "raw_pointer": self.u32(off + 20),
                "reloc_pointer": self.u32(off + 24),
                "line_pointer": self.u32(off + 28),
                "reloc_count": self.u16(off + 32),
                "line_count": self.u16(off + 34),
                "characteristics": self.u32(off + 36),
            })

        self.symbols = []
        self.symbol_by_physical: dict[int, dict] = {}
        off = self.pointer_to_symbol_table
        index = 0
        while index < self.number_of_symbols:
            raw_name = self.data[off:off + 8]
            value = self.u32(off + 8)
            section_number = struct.unpack_from("<h", self.data, off + 12)[0]
            symbol_type = self.u16(off + 14)
            storage_class = self.data[off + 16]
            aux_count = self.data[off + 17]
            if raw_name[:4] == b"\0\0\0\0":
                name_offset = self.u32(off + 4)
                start = self.string_table_offset + name_offset
                end = self.data.find(b"\0", start)
                name = self.data[start:end if end >= 0 else len(self.data)].decode("ascii", "replace")
            else:
                name = raw_name.rstrip(b"\0").decode("ascii", "replace")
            symbol = {
                "index": index,
                "name": name,
                "value": value,
                "section": section_number,
                "type": symbol_type,
                "storage_class": storage_class,
                "aux": aux_count,
            }
            self.symbols.append(symbol)
            self.symbol_by_physical[index] = symbol
            off += 18 * (1 + aux_count)
            index += 1 + aux_count

    def u16(self, off: int) -> int:
        return struct.unpack_from("<H", self.data, off)[0]

    def u32(self, off: int) -> int:
        return struct.unpack_from("<I", self.data, off)[0]

    def section_bytes(self, section: dict) -> bytes:
        start = section["raw_pointer"]
        return self.data[start:start + section["raw_size"]]

    def relocations(self, section: dict) -> list[dict]:
        rows = []
        count = section["reloc_count"]
        offset = section["reloc_pointer"]
        if section["characteristics"] & 0x01000000 and count == 0xFFFF and offset + 14 <= len(self.data):
            # IMAGE_SCN_LNK_NRELOC_OVFL: the first relocation's symbol-index
            # field holds the real count; it is not itself a relocation.
            count = self.u32(offset + 4)
            offset += 10
        for i in range(count):
            off = offset + i * 10
            if off + 10 > len(self.data):
                break
            rows.append({
                "address": self.u32(off),
                "symbol_index": self.u32(off + 4),
                "type": self.u16(off + 8),
            })
        return rows

    def symbols_by_name(self) -> dict[str, list[dict]]:
        result: dict[str, list[dict]] = {}
        for symbol in self.symbols:
            result.setdefault(symbol["name"], []).append(symbol)
        return result


def strip_padding(data: bytes) -> tuple[bytes, int]:
    end = len(data)
    while end > 0 and data[end - 1] in PAD_BYTES:
        end -= 1
    return data[:end], len(data) - end


def first_difference(left: bytes, right: bytes) -> str:
    limit = min(len(left), len(right))
    for index in range(limit):
        if left[index] != right[index]:
            start = max(0, index - 8)
            end = min(limit, index + 8)
            return (
                f"first difference at +{index:#x}\n"
                f"    expected {left[start:end].hex(' ')}\n"
                f"    actual   {right[start:end].hex(' ')}"
            )
    return f"length differs: expected {len(left)} bytes, actual {len(right)} bytes"


def resolve_va(symbol: dict, section_bases: dict[int, int], fn_map: dict[str, int],
               data_map: dict[str, int], externals: dict[str, int]) -> int:
    name = symbol["name"]
    if symbol["section"] > 0:
        if name in fn_map:
            return fn_map[name]
        if name in data_map:
            return data_map[name]
        raise HarnessError(
            f"unresolved symbol {name!r}: it is defined in object section {symbol['section']} "
            f"at offset {symbol['value']:#x}, but no address is declared for it. "
            "Declare the callee or global in the unit, or move it to another unit."
        )
    if symbol["section"] == 0:
        for candidate in (name, name.lstrip("_"), "_" + name, "__imp_" + name):
            if candidate in externals:
                return externals[candidate]
        raise HarnessError(f"unresolved external symbol {name!r}: add it to the unit's externals map")
    raise HarnessError(f"unsupported symbol {name!r} with section number {symbol['section']}")


def apply_relocations(section: dict, raw: bytearray, relocations: list[dict], symbols, section_bases: dict[int, int],
                      fn_map: dict[str, int], data_map: dict[str, int],
                      externals: dict[str, int], image_base: int) -> list[str]:
    # `symbols` is the COFF object itself when it exposes symbol_by_physical
    # (relocation symbol indices are physical record indices, aux included);
    # a plain list falls back to logical indexing for hand-built objects.
    lookup = symbols.symbol_by_physical if hasattr(symbols, "symbol_by_physical") else symbols
    problems: list[str] = []
    for reloc in relocations:
        offset = reloc["address"]
        if offset + 4 > len(raw):
            problems.append(f"relocation at {offset:#x} lies outside section {section['name']}")
            continue
        try:
            symbol = lookup[reloc["symbol_index"]]
        except (KeyError, IndexError):
            problems.append(
                f"relocation at {offset:#x} in {section['name']} references symbol index "
                f"{reloc['symbol_index']} outside the symbol table"
            )
            continue
        reloc_type = reloc["type"]
        if reloc_type == IMAGE_REL_I386_ABSOLUTE:
            continue
        addend = struct.unpack_from("<i", raw, offset)[0]
        field_va = section_bases.get(section["index"], 0) + offset
        if reloc_type == IMAGE_REL_I386_SECTION:
            struct.pack_into("<H", raw, offset, symbol["section"] & 0xFFFF)
            continue
        if reloc_type == IMAGE_REL_I386_SECREL:
            if symbol["section"] <= 0:
                problems.append(
                    f"SECREL relocation for {symbol['name']!r} does not name a defined section"
                )
                continue
            struct.pack_into("<I", raw, offset, (symbol["value"] + addend) & 0xFFFFFFFF)
            continue
        try:
            target_va = resolve_va(symbol, section_bases, fn_map, data_map, externals)
        except HarnessError as error:
            problems.append(str(error))
            continue
        if reloc_type == IMAGE_REL_I386_DIR32:
            struct.pack_into("<I", raw, offset, (target_va + addend) & 0xFFFFFFFF)
        elif reloc_type == IMAGE_REL_I386_DIR32NB:
            struct.pack_into("<I", raw, offset, (target_va + addend - image_base) & 0xFFFFFFFF)
        elif reloc_type == IMAGE_REL_I386_REL32:
            struct.pack_into("<I", raw, offset, (target_va + addend - (field_va + 4)) & 0xFFFFFFFF)
        elif reloc_type in (0x0015, 0x0016, 0x0017, 0x0018, 0x0019):  # REL32_1..REL32_5
            extra = reloc_type - IMAGE_REL_I386_REL32 + 1
            struct.pack_into("<I", raw, offset, (target_va + addend - (field_va + 4 + extra)) & 0xFFFFFFFF)
        else:
            problems.append(
                f"unsupported relocation type {reloc_type:#06x} for symbol {symbol['name']!r} "
                f"at {section['name']}+{offset:#x}"
            )
    return problems


def compare_unit(unit: dict, functions_by_address: dict[str, dict], pe: PE,
                 object_path: str) -> tuple[int, int, list[str]]:
    functions = unit.get("functions") or []
    if not functions:
        raise HarnessError(f"unit {unit.get('id')!r} declares no functions")
    fn_map = {entry["symbol"]: int(entry["address"], 16) for entry in functions}
    data_map = {name: int(address, 16) for name, address in (unit.get("data") or {}).items()}
    externals = {name: int(address, 16) for name, address in (unit.get("externals") or {}).items()}

    coff = COFF(object_path)
    symbols = coff.symbols
    by_name = coff.symbols_by_name()

    # Group requested symbols by object section and derive each section's base VA.
    section_bases: dict[int, int] = {}
    for entry in functions:
        symbol_name = entry["symbol"]
        matches = [sym for sym in by_name.get(symbol_name, []) if sym["section"] > 0]
        if not matches:
            raise HarnessError(f"object has no defined symbol named {symbol_name!r}")
        symbol = matches[0]
        base = int(entry["address"], 16) - symbol["value"]
        previous = section_bases.get(symbol["section"])
        if previous is not None and previous != base:
            raise HarnessError(
                f"section {symbol['section']} base is inconsistent: "
                f"{previous:#x} vs {base:#x} from {symbol_name!r}; "
                "put functions from one COMDAT section in separate units"
            )
        section_bases[symbol["section"]] = base

    for name, address in data_map.items():
        matches = [sym for sym in by_name.get(name, []) if sym["section"] > 0]
        if not matches:
            raise HarnessError(f"object has no defined data symbol named {name!r}")
        symbol = matches[0]
        base = address - symbol["value"]
        previous = section_bases.get(symbol["section"])
        if previous is not None and previous != base:
            raise HarnessError(
                f"data section {symbol['section']} base is inconsistent: "
                f"{previous:#x} vs {base:#x} from {name!r}"
            )
        section_bases[symbol["section"]] = base

    # Function extents inside the object: next requested symbol in the same section.
    extents: dict[str, tuple[dict, int, int]] = {}
    for entry in functions:
        symbol_name = entry["symbol"]
        symbol = [sym for sym in by_name.get(symbol_name, []) if sym["section"] > 0][0]
        section = coff.sections[symbol["section"] - 1]
        same_section = [
            sym for sym in symbols
            if sym["section"] == symbol["section"]
            and sym["name"] in fn_map
            and sym["value"] >= symbol["value"]
            and sym["index"] != symbol["index"]
        ]
        candidates = [sym["value"] for sym in same_section if sym["value"] > symbol["value"]]
        end = min(candidates) if candidates else section["raw_size"]
        extents[symbol_name] = (symbol, symbol["value"], end)

    # Relocate each touched section once.
    relocated: dict[int, bytearray] = {}
    problems: list[str] = []
    for entry in functions:
        symbol = extents[entry["symbol"]][0]
        section = coff.sections[symbol["section"] - 1]
        if section["index"] not in relocated:
            raw = bytearray(coff.section_bytes(section))
            problems.extend(apply_relocations(
                section, raw, coff.relocations(section), coff, section_bases,
                fn_map, data_map, externals, pe.image_base,
            ))
            relocated[section["index"]] = raw

    passed = 0
    failed = 0
    for entry in functions:
        address = int(entry["address"], 16)
        inventory = functions_by_address.get(f"0x{address:08x}")
        if inventory is None:
            problems.append(f"{entry['symbol']}: address {address:#x} is not in functions.json")
            failed += 1
            continue
        symbol, start, end = extents[entry["symbol"]]
        section = coff.sections[symbol["section"] - 1]
        actual = bytes(relocated[section["index"]][start:end])
        expected = pe.read_va(address, inventory["span"])
        actual_stripped, actual_trim = strip_padding(actual)
        expected_stripped, expected_trim = strip_padding(expected)
        if actual_stripped == expected_stripped:
            passed += 1
            print(f"  PASS {entry['symbol']} @ {address:#010x} "
                  f"({len(actual_stripped)} bytes, trimmed {actual_trim}/{expected_trim})")
        else:
            failed += 1
            print(f"  FAIL {entry['symbol']} @ {address:#010x}: {first_difference(expected_stripped, actual_stripped)}")
    return passed, failed, problems


def compiler_path_style(unit: dict, compiler: dict, argv_template: list) -> str:
    style = unit.get("path_style") or compiler.get("path_style")
    if style is None:
        first = os.path.basename(str(argv_template[0])).lower()
        style = "wine" if first in {"wine", "wine32", "wine64"} else "native"
    style = str(style).lower()
    if style not in {"native", "wine", "windows"}:
        raise HarnessError(f"unknown path_style {style!r}; use native, wine, or windows")
    return style


def compiler_path(path: str, style: str) -> str:
    path = os.path.abspath(path)
    if style == "native":
        return path
    if style == "windows":
        return path.replace("/", "\\")
    winepath = shutil.which("winepath")
    if winepath:
        result = subprocess.run([winepath, "-w", path], capture_output=True, text=True)
        if result.returncode == 0 and result.stdout.strip():
            return result.stdout.strip()
    # Default Wine prefix maps the host root to Z:.
    return "Z:" + path.replace("/", "\\")


def build_compile_argv(unit: dict, config: dict, workdir: str, base_dir: str = ".") -> tuple[list[str], str]:
    compiler = config.get("compiler") or {}
    argv_template = unit.get("compile_argv") or compiler.get("compile_argv")
    if not argv_template:
        raise HarnessError("no compile_argv in unit or config")
    if isinstance(argv_template, str):
        raise HarnessError("compile_argv must be a list, not a string")
    source = unit.get("source")
    if not source:
        raise HarnessError(f"unit {unit.get('id')!r} has no source path")
    if not os.path.exists(source):
        raise HarnessError(f"source not found: {source}")
    object_path = os.path.join(workdir, f"{unit['id']}.obj")
    style = compiler_path_style(unit, compiler, argv_template)
    source_arg = compiler_path(source, style)
    object_arg = compiler_path(object_path, style)
    flags = [str(flag) for flag in (unit.get("flags") or [])]
    argv: list[str] = []
    for part in argv_template:
        part = str(part)
        if part == "{flags}":
            argv.extend(flags)
            continue
        argv.append(
            part.replace("{src}", source_arg)
                .replace("{obj}", object_arg)
                .replace("{flags}", " ".join(flags))
        )
    # Wrapper/tool paths in the config are relative to the project root (the
    # config's parent directory); the compile itself runs in a temp workdir.
    if argv and not os.path.isabs(argv[0]):
        for base in (base_dir, os.path.dirname(base_dir), os.getcwd()):
            candidate = os.path.abspath(os.path.join(base, argv[0]))
            if os.path.exists(candidate):
                argv[0] = candidate
                break
    return argv, object_path


def compile_unit(unit: dict, config: dict, workdir: str, base_dir: str = ".") -> str:
    argv, object_path = build_compile_argv(unit, config, workdir, base_dir)
    env = os.environ.copy()
    env.update({str(key): str(value) for key, value in (unit.get("env") or {}).items()})
    print(f"  compile: {' '.join(argv)}")
    result = subprocess.run(argv, cwd=workdir, env=env, capture_output=True, text=True)
    if result.stdout.strip():
        print(result.stdout.rstrip())
    if result.stderr.strip():
        print(result.stderr.rstrip(), file=sys.stderr)
    if result.returncode != 0:
        raise HarnessError(f"compiler exited {result.returncode}")
    if not os.path.exists(object_path):
        # Some compilers write next to the source despite the output flag.
        candidate = os.path.join(workdir, os.path.basename(source) + ".obj")
        if os.path.exists(candidate):
            return candidate
        raise HarnessError(f"compiler produced no object at {object_path}")
    return object_path


def load_json(path: str) -> dict:
    with open(path, "r", encoding="utf-8") as fh:
        return json.load(fh)


def check_config(config: dict, inventory: dict, pe: PE) -> list[str]:
    errors: list[str] = []
    image = config.get("image") or {}
    if image.get("sha256") and image["sha256"].lower() != pe.sha256:
        errors.append(f"image SHA-256 mismatch: units.json {image['sha256']}, image {pe.sha256}")
    if image.get("size") and int(image["size"]) != pe.size:
        errors.append(f"image size mismatch: units.json {image['size']}, image {pe.size}")
    if inventory["image"]["sha256"] != pe.sha256:
        errors.append(
            f"functions.json was built from a different image: {inventory['image']['sha256']}"
        )
    by_address = {row["address"]: row for row in inventory["functions"]}
    seen: dict[str, str] = {}
    for unit in config.get("units") or []:
        unit_id = unit.get("id")
        if not unit_id:
            errors.append("a unit has no id")
        if not unit.get("source"):
            errors.append(f"unit {unit_id}: no source")
        elif not os.path.exists(unit["source"]):
            errors.append(f"unit {unit_id}: source not found: {unit['source']}")
        for entry in unit.get("functions") or []:
            address = int(entry["address"], 16) if isinstance(entry["address"], str) else entry["address"]
            key = f"0x{address:08x}"
            if key not in by_address:
                errors.append(f"unit {unit_id}: {entry.get('symbol')} address {key} not in inventory")
            if key in seen:
                errors.append(f"address {key} is claimed by both {seen[key]} and {unit_id}")
            seen[key] = unit_id
            if not entry.get("symbol"):
                errors.append(f"unit {unit_id}: entry at {key} has no symbol")
    return errors


def main(argv: list[str]) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("command", choices=["check", "compare"])
    parser.add_argument("--image", required=True)
    parser.add_argument("--config", default="build/units.json")
    parser.add_argument("--functions", default="build/functions.json")
    parser.add_argument("--unit")
    parser.add_argument("--all", action="store_true")
    parser.add_argument("--obj", help="compare this object instead of compiling")
    parser.add_argument("--keep", action="store_true", help="keep the temporary build directory")
    args = parser.parse_args(argv)

    pe = PE(args.image)
    inventory = load_json(args.functions)
    config = load_json(args.config)

    if args.command == "check":
        errors = check_config(config, inventory, pe)
        claimed = sum(len(unit.get("functions") or []) for unit in config.get("units") or [])
        total = inventory["counts"]["functions"]
        categories = {row["address"]: row.get("category", "function") for row in inventory["functions"]}
        claimed_addresses = [
            entry["address"] if isinstance(entry["address"], str) else f"0x{entry['address']:08x}"
            for unit in config.get("units") or []
            for entry in unit.get("functions") or []
        ]
        claimed_matchable = sum(1 for address in claimed_addresses if categories.get(address, "function") == "function")
        matchable = inventory["counts"].get("matchable", total)
        matchable_coverage = claimed_matchable / matchable * 100 if matchable else 0.0
        print(f"image            {pe.sha256}")
        print(f"functions        {claimed} claimed / {total} inventoried")
        print(f"matchable        {claimed_matchable} claimed / {matchable} matchable")
        print(f"coverage         {claimed / total * 100:.2f}% of all entries")
        print(f"matchable cov.   {matchable_coverage:.2f}% of matchable entries")
        if errors:
            for error in errors:
                print(f"ERROR {error}", file=sys.stderr)
            return 1
        print("config OK")
        return 0

    by_address = {row["address"]: row for row in inventory["functions"]}
    units = config.get("units") or []
    if args.all:
        selected = units
    elif args.unit:
        selected = [unit for unit in units if unit.get("id") == args.unit]
        if not selected:
            parser.error(f"unknown unit {args.unit!r}")
    elif args.obj:
        parser.error("--obj requires --unit")
    else:
        parser.error("compare requires --unit ID or --all")

    total_passed = 0
    total_failed = 0
    base_dir = os.path.dirname(os.path.abspath(args.config))
    for unit in selected:
        print(f"unit {unit.get('id')}")
        workdir = tempfile.mkdtemp(prefix="pirates-match-")
        try:
            object_path = args.obj or compile_unit(unit, config, workdir, base_dir)
            passed, failed, problems = compare_unit(unit, by_address, pe, object_path)
            total_passed += passed
            total_failed += failed
            for problem in problems:
                print(f"  ERROR {problem}", file=sys.stderr)
            print(f"  {passed} passed, {failed} failed")
        except HarnessError as error:
            print(f"  ERROR {error}", file=sys.stderr)
            total_failed += 1
        finally:
            if not args.keep:
                shutil.rmtree(workdir, ignore_errors=True)
            else:
                print(f"  kept {workdir}")

    print(f"total {total_passed} passed, {total_failed} failed")
    return 0 if total_failed == 0 else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
