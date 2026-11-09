#!/usr/bin/env python3
"""Generate harness units for every decompiled candidate wave file.

For each `src/<subsystem>/<wave>/<wave>.cpp` this tool:

1. writes a compile-normalized copy to `build/units-src/` (strip #include
   lines; force-include the generated shim; deduplicate repeated extern
   declarations of the same FUN_ name keeping the longest parameter list;
   give every address-headed function definition and the file's extern
   data/function declarations C linkage so COFF symbols are plain),
2. maps every `// 0xADDR — ...` header to the function definition that
   follows it and declares that (address, symbol) pair,
3. declares undefined FUN_ callees / data externs by their name-derived
   addresses and Win32 import references through their __imp__ IAT slots,
4. emits `gen_<wave>` unit entries (flags /O2 + shim; env INCLUDE) merged
   into `build/units.json`, preserving hand-maintained units verbatim and
   dropping generated functions whose addresses hand units already claim.

Generated units compile from build/units-src snapshots, so src/ edits during
a compare run do not corrupt results; regenerate to refresh.
"""
from __future__ import annotations

import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
from pe import PE  # noqa: E402

IMAGE = ROOT / "experiments" / "2026-11-08-target-identification" / "output" / "extracted" / "app" / "Pirates!.exe"
INVENTORY = ROOT / "build" / "functions.json"
UNITS = ROOT / "build" / "units.json"
UNIT_SRC = ROOT / "build" / "units-src"
SHIM = ROOT / "build" / "shim" / "vc71shim.h"
VC71_INCLUDE = ROOT / "analysis" / "toolchain" / "vc71" / "include"

ADDR_HEADER = re.compile(r"//\s*0x([0-9A-Fa-f]{4,8})\b")
IDENT_NAME = re.compile(r"([A-Za-z_]\w*)\s*\(")
INCLUDE_LINE = re.compile(r"^[ \t]*#[ \t]*include[ \t]*(?:<[^>]*>|\"[^\"]*\")[^\n]*\n?", re.M)
EXTERN_DECL = re.compile(r"^([ \t]*)extern\b(?! \")", re.M)
DATA_NAME = re.compile(r"\b((?:PTR_)?(?:_?DAT_|LAB_|s_)[0-9A-Fa-f]{6,})\b")


def z(path: Path) -> str:
    return "Z:\\" + str(path.resolve())[len("/"):].replace("/", "\\")


def data_address(name: str) -> int:
    # 'DAT_0085a158' / '_DAT_00869a76' / 's_004069c0' / 'PTR_LAB_0070c160' -> VA.
    if name.startswith("_DAT_"):
        return int(name[5:], 16)
    token = name[4:] if name.startswith("PTR_") else name
    return int(token.split("_", 1)[1], 16)


def find_definition(text: str, start: int) -> tuple[str, int] | None:
    """From an address-header end offset, find the following definition.

    Returns (symbol_name, line_start_offset) or None when the next code
    construct is a declaration (a ';' before any '{') or non-code.
    """
    pos = start
    for line in text[start:start + 4000].split("\n"):
        line_start = pos
        pos += len(line) + 1
        stripped = line.strip()
        if not stripped or stripped.startswith("//") or stripped.startswith("#"):
            continue
        if ";" in line and "{" not in line:
            return None  # extern declaration or data statement: not a function body head
        match = IDENT_NAME.search(line)
        if not match:
            return None
        if match.group(1) in ("if", "for", "while", "switch", "return", "sizeof"):
            return None
        brace = text.find("{", line_start, pos + 4000)
        semi = text.find(";", line_start, pos + 4000)
        if brace == -1:
            return None
        if semi != -1 and semi < brace:
            return None
        return match.group(1), line_start
    return None


def collect_functions(text: str) -> tuple[list[dict], list[str]]:
    """Map address headers to definitions; return function entries plus the
    names that were injected with extern "C"."""
    functions: dict[str, dict] = {}
    injected: list[str] = []
    edits: list[tuple[int, int, str]] = []
    for match in ADDR_HEADER.finditer(text):
        line_end = text.find("\n", match.end())
        if line_end == -1:
            continue
        found = find_definition(text, line_end + 1)
        if not found:
            continue
        name, line_start = found
        address = f"0x{int(match.group(1), 16):08x}"
        if name in functions:
            continue
        functions[name] = {"symbol": "_" + name, "address": address, "name": name}
        prefix = text[max(0, line_start - 200):line_start]
        if not prefix.rstrip().endswith('extern "C"'):
            line_end = text.find("\n", line_start)
            head = text[line_start:line_end]
            indent = head[: len(head) - len(head.lstrip())]
            edits.append((line_start, line_end, indent + 'extern "C" ' + head.lstrip()))
            injected.append(name)
    for start, end, replacement in reversed(edits):
        text = text[:start] + replacement + text[end:]
    return list(functions.values()), injected, text


def dedupe_externs(text: str) -> tuple[str, int]:
    """Collapse repeated extern declarations of the same C symbol, keeping
    the declaration with the longest parameter list."""
    decls: dict[str, list[tuple[int, int, str]]] = {}
    for match in re.finditer(r'^[ \t]*extern[ \t]+[^;{=]*?\b([A-Za-z_]\w*)[ \t]*\([^;{]*?\)[ \t]*;', text, re.M):
        decls.setdefault(match.group(1), []).append((match.start(), match.end(), match.group(0)))
    drops = []
    for name, rows in decls.items():
        if len(rows) < 2:
            continue
        keep = max(rows, key=lambda row: row[2].count(","))
        drops.extend((row[0], row[1]) for row in rows if row is not keep)
    for start, end in reversed(sorted(drops)):
        text = text[:start] + text[end:]
    return text, len(drops)


def normalize(raw: str) -> tuple[str, list[dict], int]:
    text = INCLUDE_LINE.sub("", raw)
    text = EXTERN_DECL.sub(r'\1extern "C" ', text)
    text = re.sub(r"\bnullptr\b", "0", text)
    functions, injected, text = collect_functions(text)
    text, deduped = dedupe_externs(text)
    return text, functions, deduped


def unit_for(source: Path, inv_addrs: dict[str, dict], hand_addrs: dict[str, str],
             imports_by_ident: dict[str, int]) -> tuple[dict | None, str]:
    wave = source.stem
    text, functions, deduped = normalize(source.read_text(errors="replace"))
    if not functions:
        return None, "no address-headed definitions"
    dropped = [f for f in functions if f["address"] in hand_addrs]
    functions = [f for f in functions if f["address"] not in hand_addrs]
    if not functions:
        return None, f"all {len(dropped)} definitions already hand-claimed"
    seen_addrs: set[str] = set()
    deduped_functions = []
    for f in functions:
        if f["address"] in seen_addrs:
            continue
        seen_addrs.add(f["address"])
        deduped_functions.append(f)
    functions = deduped_functions
    unmatched = [f for f in functions if f["address"] not in inv_addrs]
    if unmatched:
        functions = [f for f in functions if f["address"] in inv_addrs]
    externals: dict[str, str] = {}
    defined_addrs = {f["address"] for f in functions}
    defined_syms = {f["name"] for f in functions}
    # Undefined FUN_ callees: COFF symbol is _FUN_..., address from the name.
    for name in sorted(set(re.findall(r"\bFUN_[0-9A-Fa-f]{8}\b", text))):
        addr = f"0x{int(name[4:], 16):08x}"
        if addr in defined_addrs:
            continue
        externals["_" + name] = addr
    # Data externs (C linkage -> COFF symbol _NAME).
    for name in sorted(set(DATA_NAME.findall(text))):
        try:
            externals["_" + name] = f"0x{data_address(name):08x}"
        except (ValueError, IndexError):
            print(f"  {wave}: unparseable data name {name!r}")
            return None, f"unparseable data name {name!r}"
    # Header-named shipped symbols (e.g. '// 0x006b9250 __aullshr'): if this
    # file references a name it does not define, resolve it by its address.
    for hexaddr, name in re.findall(r"//[ \t]*0x([0-9A-Fa-f]{4,8})[ \t]+([A-Za-z_]\w*)", text):
        if name in defined_syms:
            continue
        externals["_" + name] = f"0x{int(hexaddr, 16):08x}"
    # Win32 imports used by this file resolve through their IAT slots.
    for ident, iat in imports_by_ident.items():
        if re.search(rf"\b{re.escape(ident)}\s*\(", text):
            externals["__imp__" + ident.lstrip("_")] = f"0x{iat:08x}"
    unit = {
        "id": f"gen_{wave}",
        "source": str((UNIT_SRC / f"gen_{wave}.cpp").relative_to(ROOT)),
        "flags": ["/O2", f"/FI{z(SHIM)}"],
        "env": {"INCLUDE": f"{z(VC71_INCLUDE)};{z(SHIM.parent)}"},
        "functions": [{"symbol": f["symbol"], "address": f["address"]} for f in functions],
        "externals": externals,
        "generated": "tools/gen_units.py from src/<subsystem>/<wave>/",
    }
    return unit, f"{len(functions)} functions ({len(dropped)} hand-claimed dropped, {deduped} dup externs)"


def main() -> int:
    inv = json.loads(INVENTORY.read_text())
    inv_addrs = {f["address"]: f for f in inv["functions"] if f.get("category") == "function"}
    pe = PE(str(IMAGE))
    imports_by_ident = {}
    for row in pe.imports():
        name = row.get("name") or ""
        if re.match(r"^[A-Za-z_][A-Za-z0-9_]*$", name):
            imports_by_ident[name] = row["iat_va"]

    saved = json.loads(UNITS.read_text())
    hand_units = [u for u in saved["units"] if not u["id"].startswith("gen_")]
    hand_addrs = {fn["address"]: u["id"] for u in hand_units for fn in u.get("functions", [])}

    UNIT_SRC.mkdir(parents=True, exist_ok=True)
    for stale in UNIT_SRC.glob("gen_*.cpp"):
        stale.unlink()

    generated, skipped = [], []
    claimed: dict[str, str] = dict(hand_addrs)
    for source in sorted(ROOT.glob("src/*/*/*.cpp")):
        unit, note = unit_for(source, inv_addrs, hand_addrs, imports_by_ident)
        if not unit:
            skipped.append((str(source.relative_to(ROOT)), note))
            continue
        text, _fns, _d = normalize(source.read_text(errors="replace"))
        drop = [f for f in unit["functions"] if f["address"] in claimed]
        if drop:
            unit["functions"] = [f for f in unit["functions"] if f["address"] not in claimed]
            note += f"; {len(drop)} claimed earlier elsewhere"
        if not unit["functions"]:
            skipped.append((str(source.relative_to(ROOT)), note + " -> nothing left"))
            continue
        for f in unit["functions"]:
            claimed[f["address"]] = unit["id"]
        (UNIT_SRC / f"gen_{source.stem}.cpp").write_text(text)
        generated.append(unit)
        if drop:
            skipped.append((str(source.relative_to(ROOT)), note))

    merged = {
        "schema": 1,
        "image": saved["image"],
        "compiler": saved["compiler"],
        "units": hand_units + generated,
    }
    UNITS.write_text(json.dumps(merged, indent=1) + "\n")
    print(f"units: hand={len(hand_units)} generated={len(generated)} total={len(merged['units'])}")
    print(f"functions declared by generated units: {sum(len(u['functions']) for u in generated)}")
    print(f"skipped {len(skipped)}:")
    for path, why in skipped[:400]:
        print(f"  {path}: {why}")
    if False:
        print(f"  … {len(skipped) - 15} more")
    return 0


if __name__ == "__main__":
    sys.exit(main())
