#!/usr/bin/env python3
"""Cluster units-census.json errors into actionable classes.

Reads analysis/units-census.json and prints:
- error-class histogram (C4xxx/C2xxx compiler codes, unresolved externals,
  traceback/infra),
- per-class example units and error lines,
- the candidate src file for each errored gen_ unit (via build/units-src),
so fixes can be batched by class instead of by file.
"""
from __future__ import annotations

import json
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
CENSUS = ROOT / "analysis" / "units-census.json"

CODE = re.compile(r"error (C\d+)|fatal error (C\d+)|unresolved external symbol '([^']+)'|"
                  r"compiler exited (\d+)|references symbol index|IndexError|HarnessError")


def classify(line: str) -> str:
    match = CODE.search(line)
    if not match:
        return "other"
    if match.group(1) or match.group(2):
        return f"cl_{match.group(1) or match.group(2)}"
    if match.group(3):
        return "unresolved_external"
    if match.group(4):
        return f"compile_rc_{match.group(4)}"
    return match.group(0)[:30]


def main() -> int:
    census = json.loads(CENSUS.read_text())
    hist: Counter[str] = Counter()
    examples: dict[str, list] = defaultdict(list)
    for unit in census["units"].values():
        if unit["status"] != "error":
            continue
        for problem in unit.get("problems", []):
            cls = classify(problem)
            hist[cls] += 1
            if len(examples[cls]) < 3:
                examples[cls].append((unit["id"], problem))
    print("== error classes ==")
    for cls, count in hist.most_common():
        print(f"{count:5} {cls}")
    print("\n== examples ==")
    for cls in [c for c, _ in hist.most_common(12)]:
        print(f"\n[{cls}]")
        for unit_id, problem in examples[cls]:
            print(f"  {unit_id}: {problem[:150]}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
