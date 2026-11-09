#!/usr/bin/env python3
"""Build and verify the complete decompilation index.

The Ghidra corpus under analysis/pseudocode/functions/ is one file per
analyzed function. This tool proves that every inventory function has a
written entry, re-hashes every function file, records the external imports,
and emits a tracked address/name/hash index at
reconstruction/decompilation-index.json.

It does not claim source equivalence or a byte match.
"""
from __future__ import annotations

import hashlib
import json
import sys
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
INVENTORY = ROOT / "build" / "functions.json"
INDEX = ROOT / "analysis" / "pseudocode" / "decompile-index.json"
OUT = ROOT / "reconstruction" / "decompilation-index.json"
OUT_MD = ROOT / "reconstruction" / "DECOMPILATION.md"
CANONICAL_SHA256 = "6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9"


def norm(address: str) -> str:
    return "0x%08x" % int(address, 16)


def main() -> int:
    inventory = json.loads(INVENTORY.read_text())
    index = json.loads(INDEX.read_text())
    if index.get("target_sha256") != CANONICAL_SHA256:
        print("target hash mismatch in decompile index", file=sys.stderr)
        return 1

    records = index["functions"]
    written = {norm(r["address"]): r for r in records if r.get("status") == "written"}
    external = [r for r in records if r.get("status") == "external"]
    wanted = {norm(f["address"]) for f in inventory["functions"]}

    missing = sorted(wanted - set(written))
    extra = sorted(set(written) - wanted)
    bad_hash = []
    out_functions = []
    for address in sorted(wanted):
        record = written[address]
        relative = record["relative_path"]
        path = INDEX.parent / relative
        if not path.exists():
            bad_hash.append((address, "missing-file"))
            continue
        digest = hashlib.sha256(path.read_bytes()).hexdigest()
        if digest != record.get("sha256"):
            bad_hash.append((address, "hash-mismatch"))
            continue
        out_functions.append(
            {
                "address": address,
                "name": record["name"],
                "pseudocode": str(path.relative_to(ROOT)),
                "sha256": digest,
                "ranges": record.get("body", {}).get("ranges", []),
                "non_contiguous": record.get("body", {}).get("non_contiguous", False),
            }
        )

    status = "complete" if not missing and not extra and not bad_hash else "incomplete"
    result = {
        "schema": 1,
        "target_sha256": index["target_sha256"],
        "provider": index["provider"],
        "analysis_profile_digest": index.get("analysis_profile_digest"),
        "inventory_functions": len(wanted),
        "written_functions": len(written),
        "external_imports": len(external),
        "status": status,
        "missing": missing,
        "extra": extra,
        "bad_files": bad_hash,
        "externals": [
            {"index": r["address"], "name": r["name"]} for r in sorted(external, key=lambda r: r["address"])
        ],
        "functions": out_functions,
    }
    OUT.write_text(json.dumps(result, indent=1) + "\n")

    md = [
        "# Complete decompilation index",
        "",
        f"Target SHA-256: `{index['target_sha256']}`  ",
        f"Provider: {index['provider']['name']} {index['provider']['version']}  ",
        f"Status: **{status}** — {len(out_functions)} internal functions, "
        f"{len(external)} external imports.",
        "",
        "One Ghidra pseudocode file per analyzed function. These are "
        "decompiler-derived listings, not original source and not byte-matched.",
        "",
        "| # | Address | Function | Bytes | Pseudocode |",
        "|---:|---|---|---:|---|",
    ]
    for n, fn in enumerate(out_functions, 1):
        size = 0
        for part in fn["ranges"]:
            size += int(part["end"], 16) - int(part["start"], 16) + 1
        md.append(
            f"| {n} | `{fn['address']}` | `{fn['name']}` | {size} | "
            f"[{fn['pseudocode']}](../{fn['pseudocode']}) |"
        )
    md += [
        "",
        "## External imports",
        "",
        "| # | Index | Symbol |",
        "|---:|---|---|",
    ]
    for n, ext in enumerate(result["externals"], 1):
        md.append(f"| {n} | `{ext['index']}` | `{ext['name']}` |")
    md += [""]
    OUT_MD.write_text("\n".join(md))

    print(f"inventory functions: {len(wanted)}")
    print(f"written functions:   {len(written)}")
    print(f"external imports:    {len(external)}")
    print(f"verified files:      {len(out_functions)}")
    print(f"missing/extra/bad:   {len(missing)}/{len(extra)}/{len(bad_hash)}")
    print(f"status:              {status}")
    print(f"index:               {OUT.relative_to(ROOT)}")
    return 0 if status == "complete" else 1


if __name__ == "__main__":
    sys.exit(main())
