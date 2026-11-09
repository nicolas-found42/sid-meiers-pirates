# Reconstruction batch mass_0275

Target: Sid Meier's Pirates! (2004), PE32 i386, image `6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9`.
Root: `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates`
Corpus: Ghidra 12.2 pseudocode, one file per function.

## Assigned addresses

- `analysis/pseudocode/functions/0x60f879.c` -> address `0x60f879`
- `analysis/pseudocode/functions/0x60fa04.c` -> address `0x60fa04`
- `analysis/pseudocode/functions/0x60fa88.c` -> address `0x60fa88`
- `analysis/pseudocode/functions/0x60fb96.c` -> address `0x60fb96`
- `analysis/pseudocode/functions/0x60fbe0.c` -> address `0x60fbe0`
- `analysis/pseudocode/functions/0x60fc69.c` -> address `0x60fc69`
- `analysis/pseudocode/functions/0x60fcd3.c` -> address `0x60fcd3`
- `analysis/pseudocode/functions/0x60fd9a.c` -> address `0x60fd9a`
- `analysis/pseudocode/functions/0x61003c.c` -> address `0x61003c`
- `analysis/pseudocode/functions/0x610165.c` -> address `0x610165`
- `analysis/pseudocode/functions/0x610209.c` -> address `0x610209`
- `analysis/pseudocode/functions/0x610287.c` -> address `0x610287`
- `analysis/pseudocode/functions/0x61032a.c` -> address `0x61032a`
- `analysis/pseudocode/functions/0x6104c3.c` -> address `0x6104c3`
- `analysis/pseudocode/functions/0x6105c8.c` -> address `0x6105c8`
- `analysis/pseudocode/functions/0x61060b.c` -> address `0x61060b`
- `analysis/pseudocode/functions/0x610755.c` -> address `0x610755`
- `analysis/pseudocode/functions/0x610918.c` -> address `0x610918`
- `analysis/pseudocode/functions/0x610b5f.c` -> address `0x610b5f`
- `analysis/pseudocode/functions/0x610bd6.c` -> address `0x610bd6`

## Hard delivery rule

Create the output file before translating: write the first five definitions,
then append each next group. Never return without the file. If time or
context runs out, the file must still contain every completed definition;
list the missing addresses in your final message instead of leaving an
empty batch.

## Deliverable

Write exactly one file:

`/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/experiments/2026-11-08-source-reconstruction/out/mass_0275/src/mass_0275.cpp`

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
