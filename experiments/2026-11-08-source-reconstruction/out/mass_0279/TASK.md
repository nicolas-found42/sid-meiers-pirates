# Reconstruction batch mass_0279

Target: Sid Meier's Pirates! (2004), PE32 i386, image `6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9`.
Root: `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates`
Corpus: Ghidra 12.2 pseudocode, one file per function.

## Assigned addresses

- `analysis/pseudocode/functions/0x616cee.c` -> address `0x616cee`
- `analysis/pseudocode/functions/0x617590.c` -> address `0x617590`
- `analysis/pseudocode/functions/0x617b0e.c` -> address `0x617b0e`
- `analysis/pseudocode/functions/0x618334.c` -> address `0x618334`
- `analysis/pseudocode/functions/0x6186dd.c` -> address `0x6186dd`
- `analysis/pseudocode/functions/0x618b09.c` -> address `0x618b09`
- `analysis/pseudocode/functions/0x618c3e.c` -> address `0x618c3e`
- `analysis/pseudocode/functions/0x618ec0.c` -> address `0x618ec0`
- `analysis/pseudocode/functions/0x618f94.c` -> address `0x618f94`
- `analysis/pseudocode/functions/0x6190a2.c` -> address `0x6190a2`
- `analysis/pseudocode/functions/0x619457.c` -> address `0x619457`
- `analysis/pseudocode/functions/0x61a196.c` -> address `0x61a196`
- `analysis/pseudocode/functions/0x61afd4.c` -> address `0x61afd4`
- `analysis/pseudocode/functions/0x61b66c.c` -> address `0x61b66c`
- `analysis/pseudocode/functions/0x6213f0.c` -> address `0x6213f0`
- `analysis/pseudocode/functions/0x62241e.c` -> address `0x62241e`
- `analysis/pseudocode/functions/0x62254c.c` -> address `0x62254c`
- `analysis/pseudocode/functions/0x62294a.c` -> address `0x62294a`
- `analysis/pseudocode/functions/0x6233ff.c` -> address `0x6233ff`
- `analysis/pseudocode/functions/0x623505.c` -> address `0x623505`

## Hard delivery rule

Create the output file before translating: write the first five definitions,
then append each next group. Never return without the file. If time or
context runs out, the file must still contain every completed definition;
list the missing addresses in your final message instead of leaving an
empty batch.

## Deliverable

Write exactly one file:

`/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/experiments/2026-11-08-source-reconstruction/out/mass_0279/src/mass_0279.cpp`

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
