# Reconstruction batch mass_0150

Target: Sid Meier's Pirates! (2004), PE32 i386, image `6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9`.
Root: `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates`
Corpus: Ghidra 12.2 pseudocode, one file per function.

## Assigned addresses

- `analysis/pseudocode/functions/0x557ab0.c` -> address `0x557ab0`
- `analysis/pseudocode/functions/0x557ae0.c` -> address `0x557ae0`
- `analysis/pseudocode/functions/0x557e70.c` -> address `0x557e70`
- `analysis/pseudocode/functions/0x557ec0.c` -> address `0x557ec0`
- `analysis/pseudocode/functions/0x558050.c` -> address `0x558050`
- `analysis/pseudocode/functions/0x558080.c` -> address `0x558080`
- `analysis/pseudocode/functions/0x5580b0.c` -> address `0x5580b0`
- `analysis/pseudocode/functions/0x5580f0.c` -> address `0x5580f0`
- `analysis/pseudocode/functions/0x558170.c` -> address `0x558170`
- `analysis/pseudocode/functions/0x558240.c` -> address `0x558240`
- `analysis/pseudocode/functions/0x558280.c` -> address `0x558280`
- `analysis/pseudocode/functions/0x558380.c` -> address `0x558380`
- `analysis/pseudocode/functions/0x558460.c` -> address `0x558460`
- `analysis/pseudocode/functions/0x5584b0.c` -> address `0x5584b0`
- `analysis/pseudocode/functions/0x5585f0.c` -> address `0x5585f0`
- `analysis/pseudocode/functions/0x558730.c` -> address `0x558730`
- `analysis/pseudocode/functions/0x558fc0.c` -> address `0x558fc0`
- `analysis/pseudocode/functions/0x559000.c` -> address `0x559000`
- `analysis/pseudocode/functions/0x559020.c` -> address `0x559020`
- `analysis/pseudocode/functions/0x559050.c` -> address `0x559050`

## Hard delivery rule

Create the output file before translating: write the first five definitions,
then append each next group. Never return without the file. If time or
context runs out, the file must still contain every completed definition;
list the missing addresses in your final message instead of leaving an
empty batch.

## Deliverable

Write exactly one file:

`/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/experiments/2026-11-08-source-reconstruction/out/mass_0150/src/mass_0150.cpp`

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
