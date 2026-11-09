#!/usr/bin/env python3
"""Validate reconstruction manifests and report coverage.

Reads every manifest.json under experiments/2026-11-08-source-reconstruction/out/,
checks source paths, addresses, duplicate claims, and matchable-category membership
against build/functions.json. Prints a status table and writes a machine-readable
summary to analysis/reconstruction-status.json (ignored).
"""
from __future__ import annotations

import json
import os
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
OUT = ROOT / "experiments" / "2026-11-08-source-reconstruction" / "out"
INVENTORY = ROOT / "build" / "functions.json"
SUMMARY = ROOT / "analysis" / "reconstruction-status.json"


def load_entries(path: Path) -> list[dict]:
    data = json.loads(path.read_text())
    if isinstance(data, list):
        return data
    return data.get("functions", data.get("entries", []))


def defines_address(text: str, address: str) -> bool:
    """True when the declared source carries this shipped address.

    Accepts either the raw ``0x...`` token or a ``FUN_<hex>`` identifier.
    This catches manifests that name an address no body was written for.
    """
    digits = address[2:].lower().lstrip("0")
    if not digits:
        return False
    raw = re.compile(r"0x0*" + re.escape(digits) + r"\b", re.IGNORECASE)
    fn = re.compile(r"\bFUN_0*" + re.escape(digits) + r"(?:\b|_)", re.IGNORECASE)
    return bool(raw.search(text) or fn.search(text))


def is_partial(text: str, entry: dict) -> bool:
    if entry.get("partial") or entry.get("completeness") == "partial":
        return True
    return bool(re.search(r"\b(?:stub|Stub|UNVERIFIED full)\b", text))


def main() -> int:
    inv = json.loads(INVENTORY.read_text())
    functions = {f["address"].lower(): f for f in inv["functions"]}
    matchable = {a for a, f in functions.items() if f.get("category") == "function"}

    claims: dict[str, list[str]] = defaultdict(list)
    manifests = sorted(OUT.glob("*/manifest.json"))
    manifests = [m for m in manifests if m.parent.name != "classes"]
    rows = []
    missing = []
    for manifest in manifests:
        band = manifest.parent.name
        entries = load_entries(manifest)
        if not entries:
            missing.append((band, "empty manifest"))
            continue
        bad_address = []
        bad_source = []
        bad_definition = []
        partial = 0
        source_count = 0
        for entry in entries:
            address = str(entry.get("address", "")).lower()
            source = manifest.parent / str(entry.get("source", ""))
            if address not in functions:
                bad_address.append(address)
            elif address not in matchable:
                bad_address.append(f"{address}({functions[address].get('category')})")
            if entry.get("source") and source.exists():
                source_count += 1
                text = source.read_text(errors="replace")
                if not defines_address(text, address):
                    bad_definition.append(address)
                if is_partial(text, entry):
                    partial += 1
            else:
                bad_source.append(str(entry.get("source")))
            if address:
                claims[address].append(band)
        rows.append(
            {
                "band": band,
                "entries": len(entries),
                "sources_present": source_count,
                "partial": partial,
                "bad_addresses": bad_address,
                "bad_definitions": bad_definition,
                "missing_sources": bad_source,
                "queue": (manifest.parent / "QUEUE.json").exists(),
                "report": (manifest.parent / "REPORT.md").exists(),
            }
        )

    duplicates = {a: bands for a, bands in claims.items() if len(bands) > 1}
    claimed = set(claims)
    unclaimed = sorted(matchable - claimed)
    summary = {
        "target": inv.get("image"),
        "inventory": inv.get("counts"),
        "manifests": rows,
        "claimed_unique": len(claimed),
        "partial_claims": sum(r["partial"] for r in rows),
        "duplicates": duplicates,
        "unclaimed_matchable": len(unclaimed),
        "unclaimed_addresses": unclaimed,
    }
    SUMMARY.parent.mkdir(parents=True, exist_ok=True)
    SUMMARY.write_text(json.dumps(summary, indent=1) + "\n")

    print(f"{'wave':22} {'entries':>7} {'src':>5} {'queue':>6} {'report':>7}  issues")
    for r in rows:
        issues = []
        if r["bad_addresses"]:
            issues.append(f"bad-addr={len(r['bad_addresses'])}")
        if r["missing_sources"]:
            issues.append(f"missing-src={len(r['missing_sources'])}")
        if r["bad_definitions"]:
            issues.append(f"no-def={len(r['bad_definitions'])}")
        if r["partial"]:
            issues.append(f"partial={r['partial']}")
        print(
            f"{r['band']:22} {r['entries']:7} {r['sources_present']:5} "
            f"{str(r['queue']):>6} {str(r['report']):>7}  {', '.join(issues) or 'ok'}"
        )
    print(f"\nunique claimed: {len(claimed)}")
    print(f"partial claims: {summary['partial_claims']}")
    print(f"duplicates: {len(duplicates)}")
    print(f"matchable unclaimed: {len(unclaimed)}")
    print(f"summary: {SUMMARY.relative_to(ROOT)}")
    return (
        1
        if duplicates
        or any(r["bad_addresses"] or r["bad_definitions"] or r["missing_sources"] for r in rows)
        else 0
    )


if __name__ == "__main__":
    sys.exit(main())
