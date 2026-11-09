#!/usr/bin/env python3
"""Plan disjoint reconstruction batches from the remaining matchable queue.

Creates one directory per batch with a self-contained TASK.md. A batch is the
unit a subagent can finish in one pass: exact addresses, exact corpus paths,
exact output path, and no selection work.
"""
from __future__ import annotations

import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
QUEUE = ROOT / "reconstruction" / "QUEUE.json"
OUT = ROOT / "experiments" / "2026-11-08-source-reconstruction" / "out"
PLAN = ROOT / "experiments" / "2026-11-08-source-reconstruction" / "mass_batches.json"
CORPUS = "analysis/pseudocode/functions"
BATCH_SIZE = 20


def main() -> int:
    addresses = json.loads(QUEUE.read_text())["queue"]
    # Never reuse a directory that already has source/manifest output.
    used = {
        p.name
        for p in OUT.glob("mass_*")
        if p.is_dir() and (any((p / "src").glob("*.cpp")) or (p / "manifest.json").exists())
    }
    start = max([int(n.split("_")[1]) for n in used] + [0]) + 1
    batches = []
    for offset in range(0, len(addresses), BATCH_SIZE):
        batch_id = f"mass_{start + len(batches):04d}"
        if batch_id in used:
            continue
        chunk = addresses[offset : offset + BATCH_SIZE]
        bdir = OUT / batch_id
        (bdir / "src").mkdir(parents=True, exist_ok=True)
        files = "\n".join(
            f"- `{CORPUS}/0x{int(a, 16):x}.c` -> address `{a}`" for a in chunk
        )
        task = f"""# Reconstruction batch {batch_id}

Target: Sid Meier's Pirates! (2004), PE32 i386, image `6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9`.
Root: `{ROOT}`
Corpus: Ghidra 12.2 pseudocode, one file per function.

## Assigned addresses

{files}

## Deliverable

Write exactly one file:

`{bdir / 'src' / (batch_id + '.cpp')}`

For every assigned address, write one C++ candidate definition. Put
`// 0xADDR — observed shape` immediately above it and use the name
`FUN_ADDR` (or `FUN_ADDR_recon`) in the definition. Preserve the observed
field offsets, constants, call order, return shape, and conditional structure.

Rules:

1. Translate only the listed corpus files. Do not add other addresses.
2. The provider exposes register receivers as `in_ECX`, `in_ESI`, `in_EDI`,
   `in_EBX`, or `in_EAX`. Use an explicit `void* self` (or a concretely typed
   `self`) parameter for a receiver. Never use `this` inside a free function.
3. Declare referenced helpers and globals as `extern`; include `<cstdint>`,
   `<cstddef>`, and `<windows.h>` when needed. Do not invent a global address
   that is not used by the supplied listing.
4. Do not emit a placeholder, empty body, or `return 0` merely to fill a slot.
   If a listing is genuinely opaque, preserve the observed operations and add
   `// NEEDS_MANUAL: <reason>` above the definition.
5. Do not edit any other file and do not run a build, compiler, test, or git.
6. Return only after `wc -l` and `grep -c '0x'` confirm the file exists and
   contains all assigned addresses.
"""
        (bdir / "TASK.md").write_text(task)
        batches.append({"id": batch_id, "addresses": chunk, "dir": str(bdir)})

    PLAN.write_text(json.dumps({"count": len(batches), "batch_size": BATCH_SIZE, "batches": batches}, indent=1) + "\n")
    print(f"planned {len(batches)} batches for {len(addresses)} addresses")
    print(PLAN.relative_to(ROOT))
    return 0


if __name__ == "__main__":
    sys.exit(main())
