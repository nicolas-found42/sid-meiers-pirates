# Reconstruction batch mass_0238

Target: Sid Meier's Pirates! (2004), PE32 i386, image `6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9`.
Root: `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates`
Corpus: Ghidra 12.2 pseudocode, one file per function.

## Assigned addresses

- `analysis/pseudocode/functions/0x5e1740.c` -> address `0x5e1740`
- `analysis/pseudocode/functions/0x5e1890.c` -> address `0x5e1890`
- `analysis/pseudocode/functions/0x5e18b0.c` -> address `0x5e18b0`
- `analysis/pseudocode/functions/0x5e19a0.c` -> address `0x5e19a0`
- `analysis/pseudocode/functions/0x5e1a10.c` -> address `0x5e1a10`
- `analysis/pseudocode/functions/0x5e1aa0.c` -> address `0x5e1aa0`
- `analysis/pseudocode/functions/0x5e1b70.c` -> address `0x5e1b70`
- `analysis/pseudocode/functions/0x5e1c00.c` -> address `0x5e1c00`
- `analysis/pseudocode/functions/0x5e1ca0.c` -> address `0x5e1ca0`
- `analysis/pseudocode/functions/0x5e1da0.c` -> address `0x5e1da0`
- `analysis/pseudocode/functions/0x5e1ee0.c` -> address `0x5e1ee0`
- `analysis/pseudocode/functions/0x5e2030.c` -> address `0x5e2030`
- `analysis/pseudocode/functions/0x5e2060.c` -> address `0x5e2060`
- `analysis/pseudocode/functions/0x5e2120.c` -> address `0x5e2120`
- `analysis/pseudocode/functions/0x5e22f0.c` -> address `0x5e22f0`
- `analysis/pseudocode/functions/0x5e2340.c` -> address `0x5e2340`
- `analysis/pseudocode/functions/0x5e2380.c` -> address `0x5e2380`
- `analysis/pseudocode/functions/0x5e23b0.c` -> address `0x5e23b0`
- `analysis/pseudocode/functions/0x5e2560.c` -> address `0x5e2560`
- `analysis/pseudocode/functions/0x5e25a0.c` -> address `0x5e25a0`

## Hard delivery rule

Create the output file before translating: write the first five definitions,
then append each next group. Never return without the file. If time or
context runs out, the file must still contain every completed definition;
list the missing addresses in your final message instead of leaving an
empty batch.

## Deliverable

Write exactly one file:

`/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/experiments/2026-11-08-source-reconstruction/out/mass_0238/src/mass_0238.cpp`

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
