# Reconstruction batch mass_0329

Target: Sid Meier's Pirates! (2004), PE32 i386, image `6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9`.
Root: `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates`
Corpus: Ghidra 12.2 pseudocode, one file per function.

## Assigned addresses

- `analysis/pseudocode/functions/0x683c4e.c` -> address `0x683c4e`
- `analysis/pseudocode/functions/0x684118.c` -> address `0x684118`
- `analysis/pseudocode/functions/0x684169.c` -> address `0x684169`
- `analysis/pseudocode/functions/0x68422a.c` -> address `0x68422a`
- `analysis/pseudocode/functions/0x684262.c` -> address `0x684262`
- `analysis/pseudocode/functions/0x684433.c` -> address `0x684433`
- `analysis/pseudocode/functions/0x68445a.c` -> address `0x68445a`
- `analysis/pseudocode/functions/0x6844c1.c` -> address `0x6844c1`
- `analysis/pseudocode/functions/0x68515d.c` -> address `0x68515d`
- `analysis/pseudocode/functions/0x6851d8.c` -> address `0x6851d8`
- `analysis/pseudocode/functions/0x6853b7.c` -> address `0x6853b7`
- `analysis/pseudocode/functions/0x6854e3.c` -> address `0x6854e3`
- `analysis/pseudocode/functions/0x685523.c` -> address `0x685523`
- `analysis/pseudocode/functions/0x68557c.c` -> address `0x68557c`
- `analysis/pseudocode/functions/0x6855b5.c` -> address `0x6855b5`
- `analysis/pseudocode/functions/0x685649.c` -> address `0x685649`
- `analysis/pseudocode/functions/0x6857ac.c` -> address `0x6857ac`
- `analysis/pseudocode/functions/0x685848.c` -> address `0x685848`
- `analysis/pseudocode/functions/0x6858fc.c` -> address `0x6858fc`
- `analysis/pseudocode/functions/0x685983.c` -> address `0x685983`

## Hard delivery rule

Create the output file before translating: write the first five definitions,
then append each next group. Never return without the file. If time or
context runs out, the file must still contain every completed definition;
list the missing addresses in your final message instead of leaving an
empty batch.

## Deliverable

Write exactly one file:

`/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/experiments/2026-11-08-source-reconstruction/out/mass_0329/src/mass_0329.cpp`

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
