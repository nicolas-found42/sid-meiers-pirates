# Reconstruction batch mass_0088

Target: Sid Meier's Pirates! (2004), PE32 i386, image `6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9`.
Root: `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates`
Corpus: Ghidra 12.2 pseudocode, one file per function.

## Assigned addresses

- `analysis/pseudocode/functions/0x5075c0.c` -> address `0x5075c0`
- `analysis/pseudocode/functions/0x507640.c` -> address `0x507640`
- `analysis/pseudocode/functions/0x5076a0.c` -> address `0x5076a0`
- `analysis/pseudocode/functions/0x5077f0.c` -> address `0x5077f0`
- `analysis/pseudocode/functions/0x5079e0.c` -> address `0x5079e0`
- `analysis/pseudocode/functions/0x507a10.c` -> address `0x507a10`
- `analysis/pseudocode/functions/0x507ac0.c` -> address `0x507ac0`
- `analysis/pseudocode/functions/0x507b90.c` -> address `0x507b90`
- `analysis/pseudocode/functions/0x507c00.c` -> address `0x507c00`
- `analysis/pseudocode/functions/0x507c90.c` -> address `0x507c90`
- `analysis/pseudocode/functions/0x507d20.c` -> address `0x507d20`
- `analysis/pseudocode/functions/0x507e00.c` -> address `0x507e00`
- `analysis/pseudocode/functions/0x507ef0.c` -> address `0x507ef0`
- `analysis/pseudocode/functions/0x507fa0.c` -> address `0x507fa0`
- `analysis/pseudocode/functions/0x508120.c` -> address `0x508120`
- `analysis/pseudocode/functions/0x508190.c` -> address `0x508190`
- `analysis/pseudocode/functions/0x5082d0.c` -> address `0x5082d0`
- `analysis/pseudocode/functions/0x508360.c` -> address `0x508360`
- `analysis/pseudocode/functions/0x508670.c` -> address `0x508670`
- `analysis/pseudocode/functions/0x508e20.c` -> address `0x508e20`

## Hard delivery rule

Create the output file before translating: write the first five definitions,
then append each next group. Never return without the file. If time or
context runs out, the file must still contain every completed definition;
list the missing addresses in your final message instead of leaving an
empty batch.

## Deliverable

Write exactly one file:

`/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/experiments/2026-11-08-source-reconstruction/out/mass_0088/src/mass_0088.cpp`

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
