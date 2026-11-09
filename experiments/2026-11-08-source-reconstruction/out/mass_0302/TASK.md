# Reconstruction batch mass_0302

Target: Sid Meier's Pirates! (2004), PE32 i386, image `6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9`.
Root: `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates`
Corpus: Ghidra 12.2 pseudocode, one file per function.

## Assigned addresses

- `analysis/pseudocode/functions/0x64939b.c` -> address `0x64939b`
- `analysis/pseudocode/functions/0x649425.c` -> address `0x649425`
- `analysis/pseudocode/functions/0x6494ec.c` -> address `0x6494ec`
- `analysis/pseudocode/functions/0x6495a9.c` -> address `0x6495a9`
- `analysis/pseudocode/functions/0x6496c1.c` -> address `0x6496c1`
- `analysis/pseudocode/functions/0x649774.c` -> address `0x649774`
- `analysis/pseudocode/functions/0x649827.c` -> address `0x649827`
- `analysis/pseudocode/functions/0x6498da.c` -> address `0x6498da`
- `analysis/pseudocode/functions/0x649a50.c` -> address `0x649a50`
- `analysis/pseudocode/functions/0x64a9aa.c` -> address `0x64a9aa`
- `analysis/pseudocode/functions/0x64b919.c` -> address `0x64b919`
- `analysis/pseudocode/functions/0x64ba56.c` -> address `0x64ba56`
- `analysis/pseudocode/functions/0x64bdfa.c` -> address `0x64bdfa`
- `analysis/pseudocode/functions/0x64bedf.c` -> address `0x64bedf`
- `analysis/pseudocode/functions/0x64ceb8.c` -> address `0x64ceb8`
- `analysis/pseudocode/functions/0x64d072.c` -> address `0x64d072`
- `analysis/pseudocode/functions/0x64d09b.c` -> address `0x64d09b`
- `analysis/pseudocode/functions/0x64d12e.c` -> address `0x64d12e`
- `analysis/pseudocode/functions/0x64d17c.c` -> address `0x64d17c`
- `analysis/pseudocode/functions/0x64d1cd.c` -> address `0x64d1cd`

## Hard delivery rule

Create the output file before translating: write the first five definitions,
then append each next group. Never return without the file. If time or
context runs out, the file must still contain every completed definition;
list the missing addresses in your final message instead of leaving an
empty batch.

## Deliverable

Write exactly one file:

`/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/experiments/2026-11-08-source-reconstruction/out/mass_0302/src/mass_0302.cpp`

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
