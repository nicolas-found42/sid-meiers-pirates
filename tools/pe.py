#!/usr/bin/env python3
"""Minimal PE32 reader used by the Pirates! matching harness.

Reads headers, sections, imports, the debug directory (PDB identity), the
Rich header (toolchain build numbers) and the VS_VERSIONINFO resource.

No third-party dependencies. Every value returned here is read directly from
the shipped image; interpretation (for example compiler version names) lives in
the findings documents.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import struct
import sys
from dataclasses import dataclass, asdict


def align4(n: int) -> int:
    return (n + 3) & ~3


def u16(data: bytes, off: int) -> int:
    return struct.unpack_from("<H", data, off)[0]


def u32(data: bytes, off: int) -> int:
    return struct.unpack_from("<I", data, off)[0]


@dataclass
class Section:
    name: str
    virtual_size: int
    virtual_address: int
    raw_size: int
    raw_pointer: int
    characteristics: int

    @property
    def span(self) -> int:
        return max(self.virtual_size, self.raw_size)


class PE:
    def __init__(self, path: str):
        self.path = path
        with open(path, "rb") as fh:
            self.data = fh.read()
        if self.data[:2] != b"MZ":
            raise ValueError(f"{path}: not an MZ image")
        self.sha256 = hashlib.sha256(self.data).hexdigest()
        self.size = len(self.data)

        e_lfanew = u32(self.data, 0x3C)
        if self.data[e_lfanew:e_lfanew + 4] != b"PE\0\0":
            raise ValueError(f"{path}: missing PE signature")
        self.pe_offset = e_lfanew
        coff = e_lfanew + 4
        self.machine = u16(self.data, coff)
        self.number_of_sections = u16(self.data, coff + 2)
        self.timestamp = u32(self.data, coff + 4)
        self.pointer_to_symbol_table = u32(self.data, coff + 8)
        self.number_of_symbols = u32(self.data, coff + 12)
        self.optional_header_size = u16(self.data, coff + 16)
        self.characteristics = u16(self.data, coff + 18)

        opt = coff + 20
        self.optional_header_offset = opt
        self.magic = u16(self.data, opt)
        if self.magic == 0x10B:
            self.pe32_plus = False
            self.image_base = u32(self.data, opt + 28)
            self.number_of_rva_and_sizes = u32(self.data, opt + 92)
            self.data_directories_offset = opt + 96
        elif self.magic == 0x20B:
            self.pe32_plus = True
            self.image_base = struct.unpack_from("<Q", self.data, opt + 24)[0]
            self.number_of_rva_and_sizes = u32(self.data, opt + 108)
            self.data_directories_offset = opt + 112
        else:
            raise ValueError(f"{path}: unsupported optional header magic {self.magic:#x}")

        self.entry_point_rva = u32(self.data, opt + 16)
        self.section_alignment = u32(self.data, opt + 32)
        self.file_alignment = u32(self.data, opt + 36)
        self.size_of_image = u32(self.data, opt + 56)
        self.size_of_headers = u32(self.data, opt + 60)
        self.subsystem = u16(self.data, opt + 68)

        self.data_directories = []
        for i in range(min(self.number_of_rva_and_sizes, 16)):
            off = self.data_directories_offset + i * 8
            self.data_directories.append((u32(self.data, off), u32(self.data, off + 4)))

        self.sections: list[Section] = []
        sec_off = opt + self.optional_header_size
        for i in range(self.number_of_sections):
            off = sec_off + i * 40
            name = self.data[off:off + 8].rstrip(b"\0").decode("ascii", "replace")
            self.sections.append(Section(
                name=name,
                virtual_size=u32(self.data, off + 8),
                virtual_address=u32(self.data, off + 12),
                raw_size=u32(self.data, off + 16),
                raw_pointer=u32(self.data, off + 20),
                characteristics=u32(self.data, off + 36),
            ))

    # ---- address helpers -------------------------------------------------
    def rva_to_offset(self, rva: int) -> int:
        for sec in self.sections:
            if sec.virtual_address <= rva < sec.virtual_address + sec.span:
                delta = rva - sec.virtual_address
                if delta >= sec.raw_size:
                    raise ValueError(f"RVA {rva:#x} is in zero-filled tail of {sec.name}")
                return sec.raw_pointer + delta
        raise ValueError(f"RVA {rva:#x} is not mapped by any section")

    def section_for_rva(self, rva: int) -> Section:
        for sec in self.sections:
            if sec.virtual_address <= rva < sec.virtual_address + sec.span:
                return sec
        raise ValueError(f"RVA {rva:#x} is not mapped by any section")

    def read_rva(self, rva: int, size: int) -> bytes:
        off = self.rva_to_offset(rva)
        return self.data[off:off + size]

    def read_va(self, va: int, size: int) -> bytes:
        return self.read_rva(va - self.image_base, size)

    def text_section(self) -> Section:
        for sec in self.sections:
            if sec.name == ".text":
                return sec
        raise ValueError("no .text section")

    def data_directory(self, index: int) -> tuple[int, int]:
        if index >= len(self.data_directories):
            return (0, 0)
        return self.data_directories[index]

    # ---- imports ---------------------------------------------------------
    def imports(self) -> list[dict]:
        rva, size = self.data_directory(1)
        if not rva:
            return []
        results: list[dict] = []
        off = self.rva_to_offset(rva)
        seen = 0
        while True:
            base = off + seen * 20
            original_first_thunk = u32(self.data, base)
            name_rva = u32(self.data, base + 12)
            first_thunk = u32(self.data, base + 16)
            if original_first_thunk == 0 and name_rva == 0 and first_thunk == 0:
                break
            seen += 1
            if seen > 512:
                raise ValueError("import descriptor loop")
            dll = self.read_rva(name_rva, 256).split(b"\0", 1)[0].decode("ascii", "replace")
            thunk_rva = original_first_thunk or first_thunk
            index = 0
            while True:
                entry_rva = thunk_rva + index * 4
                entry = u32(self.read_rva(entry_rva, 4), 0)
                if entry == 0:
                    break
                iat_va = self.image_base + first_thunk + index * 4
                if entry & 0x80000000:
                    results.append({
                        "dll": dll, "name": None, "ordinal": entry & 0xFFFF,
                        "iat_va": iat_va, "hint_rva": None,
                    })
                else:
                    hint = u16(self.read_rva(entry, 2), 0)
                    import_name = self.read_rva(entry + 2, 512).split(b"\0", 1)[0]
                    results.append({
                        "dll": dll, "name": import_name.decode("ascii", "replace"),
                        "ordinal": None, "iat_va": iat_va, "hint_rva": entry,
                    })
                index += 1
                if index > 65536:
                    raise ValueError("import thunk loop")
        return results

    # ---- debug directory / PDB ------------------------------------------
    def debug_entries(self) -> list[dict]:
        rva, size = self.data_directory(6)
        if not rva or not size:
            return []
        off = self.rva_to_offset(rva)
        results = []
        for i in range(size // 28):
            base = off + i * 28
            characteristic = u32(self.data, base)
            timestamp = u32(self.data, base + 4)
            major = u16(self.data, base + 8)
            minor = u16(self.data, base + 10)
            entry_type = u32(self.data, base + 12)
            data_size = u32(self.data, base + 16)
            data_rva = u32(self.data, base + 20)
            data_pointer = u32(self.data, base + 24)
            entry = {
                "characteristics": characteristic, "timestamp": timestamp,
                "major": major, "minor": minor, "type": entry_type,
                "data_size": data_size, "data_rva": data_rva,
                "data_pointer": data_pointer, "codeview": None,
            }
            if entry_type == 2 and data_size >= 24 and data_pointer:
                raw = self.data[data_pointer:data_pointer + data_size]
                if raw[:4] == b"RSDS":
                    guid = raw[4:20]
                    age = u32(raw, 20)
                    path = raw[24:].split(b"\0", 1)[0]
                    entry["codeview"] = {
                        "kind": "RSDS",
                        "guid": format_guid(guid),
                        "age": age,
                        "path": path.decode("cp1252", "replace"),
                    }
                elif raw[:4] == b"NB10":
                    entry["codeview"] = {
                        "kind": "NB10",
                        "offset": u32(raw, 4),
                        "timestamp": u32(raw, 8),
                        "age": u32(raw, 12),
                        "path": raw[16:].split(b"\0", 1)[0].decode("cp1252", "replace"),
                    }
            results.append(entry)
        return results

    # ---- Rich header -----------------------------------------------------
    def rich_header(self) -> dict | None:
        limit = min(len(self.data), 0x1000)
        rich_pos = self.data.find(b"Rich", 0x40, limit)
        if rich_pos < 0 or rich_pos + 8 > len(self.data):
            return None
        key = u32(self.data, rich_pos + 4)
        dans_pos = -1
        for off in range(0x40, rich_pos):
            if u32(self.data, off) == (0x536E6144 ^ key):  # "DanS"
                dans_pos = off
                break
        if dans_pos < 0:
            return None
        entries = []
        off = dans_pos + 16
        while off + 8 <= rich_pos:
            comp_id = u32(self.data, off) ^ key
            count = u32(self.data, off + 4) ^ key
            if comp_id == 0 and count == 0:
                break
            entries.append({
                "product_id": comp_id >> 16,
                "build_id": comp_id & 0xFFFF,
                "count": count,
            })
            off += 8
        return {"key": key, "offset": dans_pos, "entries": entries}

    # ---- resources / version info ---------------------------------------
    def _resource_directory(self, rva: int) -> list[tuple[int | str, int, bool]]:
        # Each tuple: (id or name, offset (relative to resource base), is_directory)
        base = self.rva_to_offset(self.data_directory(2)[0])
        off = self.rva_to_offset(rva)
        named = u16(self.data, off + 12)
        ids = u16(self.data, off + 14)
        total = named + ids
        rows = []
        for i in range(total):
            ent = off + 16 + i * 8
            name_field = u32(self.data, ent)
            data_field = u32(self.data, ent + 4)
            if name_field & 0x80000000:
                name_off = base + (name_field & 0x7FFFFFFF)
                length = u16(self.data, name_off)
                name = self.data[name_off + 2:name_off + 2 + length * 2].decode("utf-16-le", "replace")
            else:
                name = name_field
            rows.append((name, data_field & 0x7FFFFFFF, bool(data_field & 0x80000000)))
        return rows

    def _first_resource(self, path: list[int], descend: bool = False) -> tuple[int, int] | None:
        resource_rva = self.data_directory(2)[0]
        if not resource_rva:
            return None
        rva = resource_rva
        for depth, wanted in enumerate(path):
            try:
                rows = self._resource_directory(rva)
            except (ValueError, struct.error):
                return None
            match = None
            for name, offset, is_dir in rows:
                if name == wanted:
                    match = (offset, is_dir)
                    break
            if match is None:
                return None
            offset, is_dir = match
            if depth == len(path) - 1:
                if descend:
                    # Walk first-child directories down to a data entry.
                    while is_dir:
                        child_rows = self._resource_directory(resource_rva + offset)
                        if not child_rows:
                            return None
                        offset, is_dir = child_rows[0][1], child_rows[0][2]
                if is_dir:
                    return None
                data_entry = self.rva_to_offset(resource_rva) + offset
                data_rva = u32(self.data, data_entry)
                data_size = u32(self.data, data_entry + 4)
                return data_rva, data_size
            if not is_dir:
                return None
            rva = resource_rva + offset
        return None

    def version_info(self) -> dict | None:
        found = self._first_resource([16, 1], descend=True)  # RT_VERSION, id 1, first language
        if not found:
            return None
        rva, size = found
        if not size or size > 1 << 20:
            return None
        buf = self.read_rva(rva, size)
        try:
            root = self._version_block(buf, 0, len(buf), 0)
        except (IndexError, struct.error, ValueError):
            return None
        return root

    def _version_block(self, buf: bytes, off: int, limit: int, depth: int) -> dict | None:
        if off + 6 > limit or depth > 8:
            return None
        length, value_length, value_type = struct.unpack_from("<HHH", buf, off)
        if length == 0 or off + length > limit:
            return None
        end = off + length
        cursor = off + 6
        key_chars = []
        while cursor + 1 < end:
            ch = u16(buf, cursor)
            cursor += 2
            if ch == 0:
                break
            key_chars.append(chr(ch))
        key = "".join(key_chars)
        value_off = off + align4(cursor - off)
        value = None
        if value_type == 1 and value_length:
            raw = buf[value_off:value_off + value_length * 2]
            value = raw.decode("utf-16-le", "replace").rstrip("\0")
            value_off += value_length * 2
        elif value_length:
            raw = buf[value_off:value_off + value_length]
            if key == "VS_VERSION_INFO" and len(raw) >= 52:
                signature, struct_version = struct.unpack_from("<II", raw, 0)
                file_ms, file_ls, prod_ms, prod_ls = struct.unpack_from("<IIII", raw, 8)
                value = {
                    "signature": f"{signature:#010x}",
                    "struct_version": struct_version,
                    "file_version": f"{file_ms >> 16}.{file_ms & 0xFFFF}.{file_ls >> 16}.{file_ls & 0xFFFF}",
                    "product_version": f"{prod_ms >> 16}.{prod_ms & 0xFFFF}.{prod_ls >> 16}.{prod_ls & 0xFFFF}",
                }
            else:
                value = raw.decode("cp1252", "replace").rstrip("\0")
            value_off += value_length
        children = []
        child_off = off + align4(value_off - off)
        while child_off + 6 <= end:
            child_length = u16(buf, child_off)
            if child_length == 0:
                break
            child = self._version_block(buf, child_off, end, depth + 1)
            if child is None:
                break
            children.append(child)
            child_off += align4(child_length)
        return {"key": key, "value": value, "children": children}

    # ---- summary ---------------------------------------------------------
    def info(self) -> dict:
        text = self.text_section()
        return {
            "path": self.path,
            "size": self.size,
            "sha256": self.sha256,
            "machine": f"{self.machine:#06x}",
            "optional_magic": f"{self.magic:#06x}",
            "image_base": f"{self.image_base:#010x}",
            "entry_point": f"{self.image_base + self.entry_point_rva:#010x}",
            "entry_point_rva": f"{self.entry_point_rva:#010x}",
            "subsystem": self.subsystem,
            "size_of_image": self.size_of_image,
            "sections": [asdict(sec) for sec in self.sections],
            "text": {
                "start": f"{self.image_base + text.virtual_address:#010x}",
                "end": f"{self.image_base + text.virtual_address + text.span:#010x}",
                "span": text.span,
            },
        }


def format_guid(raw: bytes) -> str:
    d1 = struct.unpack_from("<I", raw, 0)[0]
    d2 = struct.unpack_from("<H", raw, 4)[0]
    d3 = struct.unpack_from("<H", raw, 6)[0]
    rest = raw[8:].hex()
    return f"{d1:08x}-{d2:04x}-{d3:04x}-{rest[0:4]}-{rest[4:16]}"


def flatten_version(node: dict | None, out: dict | None = None) -> dict:
    if out is None:
        out = {}
    if not node:
        return out
    if node.get("value") and isinstance(node["value"], str):
        out[node["key"]] = node["value"]
    elif node.get("value") and isinstance(node["value"], dict):
        out[node["key"]] = node["value"]
    for child in node.get("children", []):
        flatten_version(child, out)
    return out


def main(argv: list[str]) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("command", choices=["info", "imports", "debug", "rich", "version", "verify"])
    parser.add_argument("image")
    parser.add_argument("--sha256", help="expected SHA-256 for the verify command")
    parser.add_argument("--json", action="store_true", help="machine-readable output")
    args = parser.parse_args(argv)

    pe = PE(args.image)

    if args.command == "info":
        result = pe.info()
    elif args.command == "imports":
        result = pe.imports()
    elif args.command == "debug":
        result = pe.debug_entries()
    elif args.command == "rich":
        result = pe.rich_header()
    elif args.command == "version":
        result = flatten_version(pe.version_info())
    elif args.command == "verify":
        if not args.sha256:
            parser.error("verify requires --sha256")
        ok = pe.sha256.lower() == args.sha256.lower()
        result = {"path": args.image, "expected": args.sha256, "actual": pe.sha256, "ok": ok}
        if args.json:
            print(json.dumps(result, indent=2))
        else:
            print(f"{result['actual']}  {'OK' if ok else 'MISMATCH'}")
        return 0 if ok else 1
    else:  # pragma: no cover
        raise AssertionError(args.command)

    if args.json:
        print(json.dumps(result, indent=2))
    elif isinstance(result, list):
        for row in result:
            print(json.dumps(row, ensure_ascii=False))
    else:
        print(json.dumps(result, indent=2))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
