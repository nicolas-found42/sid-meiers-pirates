# Reconstruction retry mass_0076

Target: Sid Meier's Pirates! (2004), PE32 i386.
Root: `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates`
Corpus: Ghidra 12.2 pseudocode, one complete file per function.

## Missing addresses

- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x4fb400.c` -> address `0x004fb400`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x4fb640.c` -> address `0x004fb640`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x4fb6a0.c` -> address `0x004fb6a0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x4fb7c0.c` -> address `0x004fb7c0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x4fb970.c` -> address `0x004fb970`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x4fbd10.c` -> address `0x004fbd10`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x4fbe10.c` -> address `0x004fbe10`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x4fbe50.c` -> address `0x004fbe50`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x4fbe90.c` -> address `0x004fbe90`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x4fbec0.c` -> address `0x004fbec0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x4fbf10.c` -> address `0x004fbf10`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x4fbf80.c` -> address `0x004fbf80`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x4fbfd0.c` -> address `0x004fbfd0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x4fc050.c` -> address `0x004fc050`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x4fc070.c` -> address `0x004fc070`

## Deliverable

`experiments/2026-11-08-source-reconstruction/out/mass_0076/src/mass_0076.cpp`

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
