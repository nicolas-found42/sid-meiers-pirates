#!/usr/bin/env python3
"""Ingest mass-reconstruction source files and write auditable manifests.

Agents only write one source file per batch. This tool derives the manifest
from the source itself, so an agent cannot claim an address it did not write.
Missing addresses stay unclaimed and remain in the global queue.
"""
from __future__ import annotations

import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
OUT = ROOT / "experiments" / "2026-11-08-source-reconstruction" / "out"
PLAN = ROOT / "experiments" / "2026-11-08-source-reconstruction" / "mass_batches.json"
CORPUS = "analysis/pseudocode/functions"


def norm(a: str) -> str:
    return "0x%08x" % int(a, 16)


HEADER = r"^[ \t]*//[ \t]*0x0*{digits}\b.*$"
DEFN = r"\b[A-Za-z_]\w*\s*\([^;{{}}]{{0,1500}}\)\s*(?:const\s*)?(?:__\w+\s*)*[^;{{}}]{{0,200}}\{{"


def _definition_segment(text: str, address: str):
    """Return the text after the address header that contains the definition."""
    digits = address[2:].lower().lstrip("0")
    for m in re.finditer(HEADER.format(digits=re.escape(digits)), text, re.I | re.M):
        seg = text[m.end() : m.end() + 2500]
        if re.search(DEFN.format(), seg, re.S):
            return seg
    return None


def source_defines(text: str, address: str) -> bool:
    """True only for an address header followed by a function definition."""
    return _definition_segment(text, address) is not None


def find_signature(text: str, address: str) -> str:
    seg = _definition_segment(text, address)
    if seg is None:
        return "unknown (definition not parsed)"
    m = re.search(DEFN.format(), seg, re.S)
    line_start = seg.rfind("\n", 0, m.start()) + 1
    line_end = seg.find("\n", m.end())
    line = seg[line_start : line_end if line_end >= 0 else len(seg)]
    return line.strip()


def main() -> int:
    plan = json.loads(PLAN.read_text())
    claimed_elsewhere = set()
    for manifest in OUT.glob("*/manifest.json"):
        if manifest.parent.name.startswith("mass_"):
            continue
        data = json.loads(manifest.read_text())
        entries = data if isinstance(data, list) else data.get("functions", [])
        claimed_elsewhere.update(norm(e["address"]) for e in entries if e.get("address", "").startswith("0x"))
    global_queue = json.loads((ROOT / "reconstruction" / "QUEUE.json").read_text())["queue"]

    total = 0
    batches_done = 0
    for batch in plan["batches"]:
        bdir = Path(batch["dir"])
        srcs = sorted((bdir / "src").glob("*.cpp"))
        if not srcs:
            continue
        text = "\n\n".join(p.read_text(errors="replace") for p in srcs)
        entries = []
        missing = []
        for address in batch["addresses"]:
            address = norm(address)
            if not source_defines(text, address):
                missing.append(address)
                continue
            if address in claimed_elsewhere:
                missing.append(address)
                continue
            segment = _definition_segment(text, address) or ""
            partial = bool(re.search(r"NEEDS_MANUAL|\bStub\b|\bstub\b", segment))
            entries.append(
                {
                    "address": address,
                    "name": f"FUN_{address[2:]}",
                    "source": f"src/{srcs[0].name}",
                    "signature": find_signature(text, address),
                    "evidence": [f"{CORPUS}/0x{int(address, 16):x}.c"],
                    "confidence": "low" if partial else "medium",
                    "status": "unverified",
                    "partial": partial,
                    "unknowns": [
                        "batch reconstruction from a Ghidra listing; no compiler and no byte match",
                        "receiver and signature inferred from register use in the listing",
                    ],
                }
            )
            claimed_elsewhere.add(address)
        if entries:
            (bdir / "manifest.json").write_text(json.dumps(entries, indent=1) + "\n")
        remaining = [a for a in global_queue if norm(a) not in claimed_elsewhere]
        (bdir / "QUEUE.json").write_text(json.dumps({"count": len(remaining), "queue": remaining}, indent=1) + "\n")
        (bdir / "REPORT.md").write_text(
            f"# {batch['id']}\n\n"
            f"Status: **UNVERIFIED**. Source written from the Ghidra 12.2 listing; no VC7.1 compiler and no PASS.\n\n"
            f"- assigned: {len(batch['addresses'])}\n"
            f"- manifest entries: {len(entries)}\n"
            f"- missing/not-written: {len(missing)}\n"
            + ("- missing addresses: " + ", ".join(f"`{a}`" for a in missing) + "\n" if missing else "")
            + "\nThe manifest is derived from the source by `tools/ingest_mass_reconstruction.py`; "
            "an address absent from the source is not claimed.\n"
        )
        total += len(entries)
        batches_done += 1
    print(f"ingested {batches_done} batches, {total} new entries")
    return 0


if __name__ == "__main__":
    sys.exit(main())
