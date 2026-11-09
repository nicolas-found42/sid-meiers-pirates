# Reconstruction retry mass_0168

Target: Sid Meier's Pirates! (2004), PE32 i386.
Root: `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates`
Corpus: Ghidra 12.2 pseudocode, one complete file per function.

## Missing addresses

- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56d1d0.c` -> address `0x0056d1d0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56d280.c` -> address `0x0056d280`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56d3a0.c` -> address `0x0056d3a0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56d440.c` -> address `0x0056d440`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56d4a0.c` -> address `0x0056d4a0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56d5c0.c` -> address `0x0056d5c0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56d630.c` -> address `0x0056d630`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56d730.c` -> address `0x0056d730`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56d7d0.c` -> address `0x0056d7d0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56d850.c` -> address `0x0056d850`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56d980.c` -> address `0x0056d980`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56db90.c` -> address `0x0056db90`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56dbd0.c` -> address `0x0056dbd0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56df30.c` -> address `0x0056df30`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56df90.c` -> address `0x0056df90`

## Deliverable

`experiments/2026-11-08-source-reconstruction/out/mass_0168/src/mass_0168.cpp`

The output file already exists with other completed definitions. APPEND the missing definitions; keep every existing line and definition unchanged.
For every missing address, add one C++ candidate definition headed by
`// 0xADDR — observed shape` and named `FUN_ADDR` or `FUN_ADDR_recon`.

## Critical correction

The corpus files are intact on disk. Earlier agents wrongly reported listings
as "truncated": that was the `read` tool's display truncation. Read every
assigned `.c` file completely, using line ranges (for example `read path:1-200`,
then `:201-400`) until the documented total line count. Confirm with
`wc -l <file>`. NEVER omit a function because a display looked elided; NEVER
regenerate the corpus.

## Rules

1. Translate only the listed corpus files. Do not add other addresses.
2. Register receivers (`in_ECX`, `in_ESI`, `in_EDI`, `in_EBX`, `in_EAX`)
   become explicit `void* self` or concretely typed parameters. Never `this`
   in a free function.
3. Declare referenced helpers/globals `extern`; include `<cstdint>`,
   `<cstddef>`, `<windows.h>` only as the existing file does. Do not invent
   global addresses absent from the listing.
4. No placeholders, empty bodies, or `return 0` fillers. Preserve observed
   operations; use `// NEEDS_MANUAL: <reason>` only for genuinely unwritten
   pseudocode.
5. Do not edit any other file; no build, compiler, test, or git.
6. Return only after `grep -c 'observed shape'` and a definition check confirm
   every missing address is present and existing definitions remain intact.
