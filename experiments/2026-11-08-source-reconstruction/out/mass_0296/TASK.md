# Reconstruction batch mass_0296

Target: Sid Meier's Pirates! (2004), PE32 i386, image `6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9`.
Root: `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates`
Corpus: Ghidra 12.2 pseudocode, one file per function.

## Assigned addresses

- `analysis/pseudocode/functions/0x63ea6b.c` -> address `0x63ea6b`
- `analysis/pseudocode/functions/0x63eb76.c` -> address `0x63eb76`
- `analysis/pseudocode/functions/0x63ec91.c` -> address `0x63ec91`
- `analysis/pseudocode/functions/0x63ed81.c` -> address `0x63ed81`
- `analysis/pseudocode/functions/0x63ef70.c` -> address `0x63ef70`
- `analysis/pseudocode/functions/0x63f23c.c` -> address `0x63f23c`
- `analysis/pseudocode/functions/0x63f27d.c` -> address `0x63f27d`
- `analysis/pseudocode/functions/0x63f34c.c` -> address `0x63f34c`
- `analysis/pseudocode/functions/0x63f375.c` -> address `0x63f375`
- `analysis/pseudocode/functions/0x63f418.c` -> address `0x63f418`
- `analysis/pseudocode/functions/0x63f448.c` -> address `0x63f448`
- `analysis/pseudocode/functions/0x63f4eb.c` -> address `0x63f4eb`
- `analysis/pseudocode/functions/0x63f756.c` -> address `0x63f756`
- `analysis/pseudocode/functions/0x63f785.c` -> address `0x63f785`
- `analysis/pseudocode/functions/0x63f7b4.c` -> address `0x63f7b4`
- `analysis/pseudocode/functions/0x63f7fa.c` -> address `0x63f7fa`
- `analysis/pseudocode/functions/0x63f86e.c` -> address `0x63f86e`
- `analysis/pseudocode/functions/0x63f926.c` -> address `0x63f926`
- `analysis/pseudocode/functions/0x63f9ca.c` -> address `0x63f9ca`
- `analysis/pseudocode/functions/0x63faf9.c` -> address `0x63faf9`

## Hard delivery rule

Create the output file before translating: write the first five definitions,
then append each next group. Never return without the file. If time or
context runs out, the file must still contain every completed definition;
list the missing addresses in your final message instead of leaving an
empty batch.

## Deliverable

Write exactly one file:

`/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/experiments/2026-11-08-source-reconstruction/out/mass_0296/src/mass_0296.cpp`

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
