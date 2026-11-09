# Reconstruction retry mass_0182

Target: Sid Meier's Pirates! (2004), PE32 i386.
Root: `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates`
Corpus: Ghidra 12.2 pseudocode, one complete file per function.

## Missing addresses

- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x57eef0.c` -> address `0x0057eef0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x57efe0.c` -> address `0x0057efe0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x57f0b0.c` -> address `0x0057f0b0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x57f160.c` -> address `0x0057f160`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x57f350.c` -> address `0x0057f350`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x57f490.c` -> address `0x0057f490`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x57f5c0.c` -> address `0x0057f5c0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x57f720.c` -> address `0x0057f720`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x57f740.c` -> address `0x0057f740`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x57f7f0.c` -> address `0x0057f7f0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x57f8f0.c` -> address `0x0057f8f0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x57fc00.c` -> address `0x0057fc00`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x57fc30.c` -> address `0x0057fc30`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x57fd30.c` -> address `0x0057fd30`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x57fed0.c` -> address `0x0057fed0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x57ff30.c` -> address `0x0057ff30`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x5800e0.c` -> address `0x005800e0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x5801b0.c` -> address `0x005801b0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x5802d0.c` -> address `0x005802d0`
- `/Users/nicolas/Documents/github/reverse-engineering/games/sid-meiers-pirates/analysis/pseudocode/functions/0x5804d0.c` -> address `0x005804d0`

## Deliverable

`experiments/2026-11-08-source-reconstruction/out/mass_0182/src/mass_0182.cpp`

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
