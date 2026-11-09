# Reconstruction batch mass_0305

Target: Sid Meier's Pirates! (2004), PE32 i386, image `6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9`.
Root: `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates`
Corpus: Ghidra 12.2 pseudocode, one file per function.

## Assigned addresses

- `analysis/pseudocode/functions/0x650432.c` -> address `0x650432`
- `analysis/pseudocode/functions/0x650506.c` -> address `0x650506`
- `analysis/pseudocode/functions/0x6505a8.c` -> address `0x6505a8`
- `analysis/pseudocode/functions/0x6506fd.c` -> address `0x6506fd`
- `analysis/pseudocode/functions/0x6507b8.c` -> address `0x6507b8`
- `analysis/pseudocode/functions/0x65090d.c` -> address `0x65090d`
- `analysis/pseudocode/functions/0x6509c8.c` -> address `0x6509c8`
- `analysis/pseudocode/functions/0x650b55.c` -> address `0x650b55`
- `analysis/pseudocode/functions/0x650d47.c` -> address `0x650d47`
- `analysis/pseudocode/functions/0x650e41.c` -> address `0x650e41`
- `analysis/pseudocode/functions/0x650ed3.c` -> address `0x650ed3`
- `analysis/pseudocode/functions/0x651213.c` -> address `0x651213`
- `analysis/pseudocode/functions/0x6514f2.c` -> address `0x6514f2`
- `analysis/pseudocode/functions/0x651847.c` -> address `0x651847`
- `analysis/pseudocode/functions/0x651b11.c` -> address `0x651b11`
- `analysis/pseudocode/functions/0x651ea7.c` -> address `0x651ea7`
- `analysis/pseudocode/functions/0x65214a.c` -> address `0x65214a`
- `analysis/pseudocode/functions/0x652274.c` -> address `0x652274`
- `analysis/pseudocode/functions/0x6522f5.c` -> address `0x6522f5`
- `analysis/pseudocode/functions/0x6532a4.c` -> address `0x6532a4`

## Hard delivery rule

Create the output file before translating: write the first five definitions,
then append each next group. Never return without the file. If time or
context runs out, the file must still contain every completed definition;
list the missing addresses in your final message instead of leaving an
empty batch.

## Deliverable

Write exactly one file:

`/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/experiments/2026-11-08-source-reconstruction/out/mass_0305/src/mass_0305.cpp`

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
