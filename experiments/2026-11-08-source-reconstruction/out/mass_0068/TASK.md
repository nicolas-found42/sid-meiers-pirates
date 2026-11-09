# Reconstruction batch mass_0068

Target: Sid Meier's Pirates! (2004), PE32 i386, image `6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9`.
Root: `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates`
Corpus: Ghidra 12.2 pseudocode, one file per function.

## Assigned addresses

- `analysis/pseudocode/functions/0x4f1b70.c` -> address `0x4f1b70`
- `analysis/pseudocode/functions/0x4f1ba0.c` -> address `0x4f1ba0`
- `analysis/pseudocode/functions/0x4f1c20.c` -> address `0x4f1c20`
- `analysis/pseudocode/functions/0x4f1c80.c` -> address `0x4f1c80`
- `analysis/pseudocode/functions/0x4f1cc0.c` -> address `0x4f1cc0`
- `analysis/pseudocode/functions/0x4f1d50.c` -> address `0x4f1d50`
- `analysis/pseudocode/functions/0x4f1dc0.c` -> address `0x4f1dc0`
- `analysis/pseudocode/functions/0x4f1e40.c` -> address `0x4f1e40`
- `analysis/pseudocode/functions/0x4f1ec0.c` -> address `0x4f1ec0`
- `analysis/pseudocode/functions/0x4f1f80.c` -> address `0x4f1f80`
- `analysis/pseudocode/functions/0x4f20a0.c` -> address `0x4f20a0`
- `analysis/pseudocode/functions/0x4f20d0.c` -> address `0x4f20d0`
- `analysis/pseudocode/functions/0x4f22c0.c` -> address `0x4f22c0`
- `analysis/pseudocode/functions/0x4f24f0.c` -> address `0x4f24f0`
- `analysis/pseudocode/functions/0x4f2530.c` -> address `0x4f2530`
- `analysis/pseudocode/functions/0x4f2620.c` -> address `0x4f2620`
- `analysis/pseudocode/functions/0x4f2aa0.c` -> address `0x4f2aa0`
- `analysis/pseudocode/functions/0x4f3050.c` -> address `0x4f3050`
- `analysis/pseudocode/functions/0x4f30a0.c` -> address `0x4f30a0`
- `analysis/pseudocode/functions/0x4f30d0.c` -> address `0x4f30d0`

## Hard delivery rule

Create the output file before translating: write the first five definitions,
then append each next group. Never return without the file. If time or
context runs out, the file must still contain every completed definition;
list the missing addresses in your final message instead of leaving an
empty batch.

## Deliverable

Write exactly one file:

`/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/experiments/2026-11-08-source-reconstruction/out/mass_0068/src/mass_0068.cpp`

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
