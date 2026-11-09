# Reconstruction batch mass_0143

Target: Sid Meier's Pirates! (2004), PE32 i386, image `6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9`.
Root: `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates`
Corpus: Ghidra 12.2 pseudocode, one file per function.

## Assigned addresses

- `analysis/pseudocode/functions/0x5512a0.c` -> address `0x5512a0`
- `analysis/pseudocode/functions/0x5512b0.c` -> address `0x5512b0`
- `analysis/pseudocode/functions/0x551370.c` -> address `0x551370`
- `analysis/pseudocode/functions/0x5513e0.c` -> address `0x5513e0`
- `analysis/pseudocode/functions/0x551500.c` -> address `0x551500`
- `analysis/pseudocode/functions/0x551550.c` -> address `0x551550`
- `analysis/pseudocode/functions/0x5515a0.c` -> address `0x5515a0`
- `analysis/pseudocode/functions/0x551600.c` -> address `0x551600`
- `analysis/pseudocode/functions/0x551680.c` -> address `0x551680`
- `analysis/pseudocode/functions/0x5516a0.c` -> address `0x5516a0`
- `analysis/pseudocode/functions/0x551730.c` -> address `0x551730`
- `analysis/pseudocode/functions/0x551750.c` -> address `0x551750`
- `analysis/pseudocode/functions/0x551770.c` -> address `0x551770`
- `analysis/pseudocode/functions/0x551790.c` -> address `0x551790`
- `analysis/pseudocode/functions/0x5517c0.c` -> address `0x5517c0`
- `analysis/pseudocode/functions/0x551810.c` -> address `0x551810`
- `analysis/pseudocode/functions/0x551880.c` -> address `0x551880`
- `analysis/pseudocode/functions/0x5518a0.c` -> address `0x5518a0`
- `analysis/pseudocode/functions/0x5518c0.c` -> address `0x5518c0`
- `analysis/pseudocode/functions/0x551930.c` -> address `0x551930`

## Hard delivery rule

Create the output file before translating: write the first five definitions,
then append each next group. Never return without the file. If time or
context runs out, the file must still contain every completed definition;
list the missing addresses in your final message instead of leaving an
empty batch.

## Deliverable

Write exactly one file:

`/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/experiments/2026-11-08-source-reconstruction/out/mass_0143/src/mass_0143.cpp`

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
