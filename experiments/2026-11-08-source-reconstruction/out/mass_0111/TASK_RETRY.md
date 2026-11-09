# Reconstruction retry mass_0111

Target: Sid Meier's Pirates! (2004), PE32 i386.
Root: `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates`
Corpus: Ghidra 12.2 pseudocode, one complete file per function.

## Missing addresses

- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x52b5d0.c` -> address `0x0052b5d0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x52b640.c` -> address `0x0052b640`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x52b7e0.c` -> address `0x0052b7e0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x52b850.c` -> address `0x0052b850`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x52b990.c` -> address `0x0052b990`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x52ba00.c` -> address `0x0052ba00`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x52bc30.c` -> address `0x0052bc30`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x52bc70.c` -> address `0x0052bc70`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x52bd90.c` -> address `0x0052bd90`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x52be00.c` -> address `0x0052be00`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x52be40.c` -> address `0x0052be40`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x52bea0.c` -> address `0x0052bea0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x52bf10.c` -> address `0x0052bf10`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x52bfb0.c` -> address `0x0052bfb0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x52c060.c` -> address `0x0052c060`

## Deliverable

`experiments/2026-11-08-source-reconstruction/out/mass_0111/src/mass_0111.cpp`

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
