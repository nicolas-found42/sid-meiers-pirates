# Reconstruction batch mass_0114

Target: Sid Meier's Pirates! (2004), PE32 i386, image `6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9`.
Root: `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates`
Corpus: Ghidra 12.2 pseudocode, one file per function.

## Assigned addresses

- `analysis/pseudocode/functions/0x52f230.c` -> address `0x52f230`
- `analysis/pseudocode/functions/0x52f260.c` -> address `0x52f260`
- `analysis/pseudocode/functions/0x52f290.c` -> address `0x52f290`
- `analysis/pseudocode/functions/0x52f2c0.c` -> address `0x52f2c0`
- `analysis/pseudocode/functions/0x52f500.c` -> address `0x52f500`
- `analysis/pseudocode/functions/0x52f570.c` -> address `0x52f570`
- `analysis/pseudocode/functions/0x52f5d0.c` -> address `0x52f5d0`
- `analysis/pseudocode/functions/0x52f640.c` -> address `0x52f640`
- `analysis/pseudocode/functions/0x52f700.c` -> address `0x52f700`
- `analysis/pseudocode/functions/0x52faf0.c` -> address `0x52faf0`
- `analysis/pseudocode/functions/0x52fbb0.c` -> address `0x52fbb0`
- `analysis/pseudocode/functions/0x52fc20.c` -> address `0x52fc20`
- `analysis/pseudocode/functions/0x52fc80.c` -> address `0x52fc80`
- `analysis/pseudocode/functions/0x52fd00.c` -> address `0x52fd00`
- `analysis/pseudocode/functions/0x52fd30.c` -> address `0x52fd30`
- `analysis/pseudocode/functions/0x52fd80.c` -> address `0x52fd80`
- `analysis/pseudocode/functions/0x52fe10.c` -> address `0x52fe10`
- `analysis/pseudocode/functions/0x52fe60.c` -> address `0x52fe60`
- `analysis/pseudocode/functions/0x52fee0.c` -> address `0x52fee0`
- `analysis/pseudocode/functions/0x52ff60.c` -> address `0x52ff60`

## Hard delivery rule

Create the output file before translating: write the first five definitions,
then append each next group. Never return without the file. If time or
context runs out, the file must still contain every completed definition;
list the missing addresses in your final message instead of leaving an
empty batch.

## Deliverable

Write exactly one file:

`/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/experiments/2026-11-08-source-reconstruction/out/mass_0114/src/mass_0114.cpp`

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
