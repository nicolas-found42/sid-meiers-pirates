# Reconstruction batch mass_0248

Target: Sid Meier's Pirates! (2004), PE32 i386, image `6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9`.
Root: `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates`
Corpus: Ghidra 12.2 pseudocode, one file per function.

## Assigned addresses

- `analysis/pseudocode/functions/0x5eb580.c` -> address `0x5eb580`
- `analysis/pseudocode/functions/0x5eb620.c` -> address `0x5eb620`
- `analysis/pseudocode/functions/0x5eb790.c` -> address `0x5eb790`
- `analysis/pseudocode/functions/0x5eb900.c` -> address `0x5eb900`
- `analysis/pseudocode/functions/0x5eb970.c` -> address `0x5eb970`
- `analysis/pseudocode/functions/0x5eb9e0.c` -> address `0x5eb9e0`
- `analysis/pseudocode/functions/0x5ebab0.c` -> address `0x5ebab0`
- `analysis/pseudocode/functions/0x5ebdf0.c` -> address `0x5ebdf0`
- `analysis/pseudocode/functions/0x5ebfa0.c` -> address `0x5ebfa0`
- `analysis/pseudocode/functions/0x5ec050.c` -> address `0x5ec050`
- `analysis/pseudocode/functions/0x5ec070.c` -> address `0x5ec070`
- `analysis/pseudocode/functions/0x5ec0a0.c` -> address `0x5ec0a0`
- `analysis/pseudocode/functions/0x5ec0c0.c` -> address `0x5ec0c0`
- `analysis/pseudocode/functions/0x5ec110.c` -> address `0x5ec110`
- `analysis/pseudocode/functions/0x5ec130.c` -> address `0x5ec130`
- `analysis/pseudocode/functions/0x5ec150.c` -> address `0x5ec150`
- `analysis/pseudocode/functions/0x5ec210.c` -> address `0x5ec210`
- `analysis/pseudocode/functions/0x5ec2a0.c` -> address `0x5ec2a0`
- `analysis/pseudocode/functions/0x5ec3c0.c` -> address `0x5ec3c0`
- `analysis/pseudocode/functions/0x5ec420.c` -> address `0x5ec420`

## Hard delivery rule

Create the output file before translating: write the first five definitions,
then append each next group. Never return without the file. If time or
context runs out, the file must still contain every completed definition;
list the missing addresses in your final message instead of leaving an
empty batch.

## Deliverable

Write exactly one file:

`/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/experiments/2026-11-08-source-reconstruction/out/mass_0248/src/mass_0248.cpp`

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
