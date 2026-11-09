# Reconstruction retry mass_0169

Target: Sid Meier's Pirates! (2004), PE32 i386.
Root: `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates`
Corpus: Ghidra 12.2 pseudocode, one complete file per function.

## Missing addresses

- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56dff0.c` -> address `0x0056dff0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56e040.c` -> address `0x0056e040`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56e240.c` -> address `0x0056e240`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56e300.c` -> address `0x0056e300`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56e330.c` -> address `0x0056e330`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56e410.c` -> address `0x0056e410`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56e4c0.c` -> address `0x0056e4c0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56e610.c` -> address `0x0056e610`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56e6a0.c` -> address `0x0056e6a0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56e700.c` -> address `0x0056e700`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56e790.c` -> address `0x0056e790`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56e7c0.c` -> address `0x0056e7c0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56e810.c` -> address `0x0056e810`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56e8c0.c` -> address `0x0056e8c0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56e940.c` -> address `0x0056e940`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56eb30.c` -> address `0x0056eb30`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56ee20.c` -> address `0x0056ee20`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56eed0.c` -> address `0x0056eed0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56f060.c` -> address `0x0056f060`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x56f230.c` -> address `0x0056f230`

## Deliverable

`experiments/2026-11-08-source-reconstruction/out/mass_0169/src/mass_0169.cpp`

The output file does not exist; create it with the batch header.
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
