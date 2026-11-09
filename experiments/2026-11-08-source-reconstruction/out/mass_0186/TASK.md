# Reconstruction batch mass_0186

Target: Sid Meier's Pirates! (2004), PE32 i386, image `6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9`.
Root: `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates`
Corpus: Ghidra 12.2 pseudocode, one file per function.

## Assigned addresses

- `analysis/pseudocode/functions/0x582fb0.c` -> address `0x582fb0`
- `analysis/pseudocode/functions/0x582ff0.c` -> address `0x582ff0`
- `analysis/pseudocode/functions/0x583070.c` -> address `0x583070`
- `analysis/pseudocode/functions/0x5831c0.c` -> address `0x5831c0`
- `analysis/pseudocode/functions/0x5831f0.c` -> address `0x5831f0`
- `analysis/pseudocode/functions/0x5832c0.c` -> address `0x5832c0`
- `analysis/pseudocode/functions/0x583390.c` -> address `0x583390`
- `analysis/pseudocode/functions/0x585ad0.c` -> address `0x585ad0`
- `analysis/pseudocode/functions/0x589bf0.c` -> address `0x589bf0`
- `analysis/pseudocode/functions/0x58a2e0.c` -> address `0x58a2e0`
- `analysis/pseudocode/functions/0x58ad60.c` -> address `0x58ad60`
- `analysis/pseudocode/functions/0x58b940.c` -> address `0x58b940`
- `analysis/pseudocode/functions/0x58edf0.c` -> address `0x58edf0`
- `analysis/pseudocode/functions/0x58ee90.c` -> address `0x58ee90`
- `analysis/pseudocode/functions/0x58ef10.c` -> address `0x58ef10`
- `analysis/pseudocode/functions/0x58ef70.c` -> address `0x58ef70`
- `analysis/pseudocode/functions/0x58f000.c` -> address `0x58f000`
- `analysis/pseudocode/functions/0x58f0c0.c` -> address `0x58f0c0`
- `analysis/pseudocode/functions/0x58f0e0.c` -> address `0x58f0e0`
- `analysis/pseudocode/functions/0x58f130.c` -> address `0x58f130`

## Hard delivery rule

Create the output file before translating: write the first five definitions,
then append each next group. Never return without the file. If time or
context runs out, the file must still contain every completed definition;
list the missing addresses in your final message instead of leaving an
empty batch.

## Deliverable

Write exactly one file:

`/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/experiments/2026-11-08-source-reconstruction/out/mass_0186/src/mass_0186.cpp`

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
