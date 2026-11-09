# band4_wave2 report

UNVERIFIED — `cl 13.10.3077` is absent; no build, no byte-match claim.

20 entries: 0x0054ae80, 0x0054b030, 0x0054b1a0, 0x0054b380, 0x0054b440,
0x0054b490, 0x0054b530, 0x0054b580, 0x0054b650, 0x0054b6c0, 0x0054b6f0,
0x0054b730, 0x0054b840, 0x0054b8c0, 0x0054b970, 0x0054b9a0, 0x0054ba20,
0x0054ba50, 0x0054ba80, 0x0054bc20.

## Observed (from pseudocode)
- 0x0054b030 / 0x0054b490: thread-flag intrusive-list push/unlink using
  0x727958/0x727940/0x72795c guard and +0x1c/+0x20 links; head/tail
  0x727930/0x727934.
- 0x0054ae80, 0x0054b440, 0x0054b650, 0x0054b6c0, 0x0054ba50: deleting
  destructors with vtable pre/post resets (0x6c1fb4→0x6fd148, 0x6c1fc8,
  0x6c2020→0x6c2064→0x6c2010, 0x6c2064→0x6c2010, 0x6c2088) and flag&1
  `operator_delete`.
- 0x0054b1a0: 0x24-byte alloc, vtable 0x6c1fc8, zero slots 3–8, peer at
  +0x14 (index 5), validator vcall +0x114 via 0x727c30.
- 0x0054b380: sink at +0x158, vcall +0x0c, +0x0c/+0x14 branches, 128-byte
  stack buffer path.
- 0x0054b530: array +0x08/+0x0c/+0x14, value FUN_00557b10(0x727938),
  grow 0x6b34a0, append FUN_005606f0.
- 0x0054b580: bucket iteration +0x38/+0x3c/+0x58, chain links +0x08/+0x0c,
  freelist +0x44.
- 0x0054b730: insert param_1 keyed by `(**(peer[10]+0x2c))+4`,
  bucket `key % (+0x3c)`, pool `<<4`, freelist +0x44.
- 0x0054b840, 0x0054bc20: addref at `param_1+0xb4`, flag/bit13 routing
  to 0x54b730 or alloc+FUN_00524a60.
- 0x0054b8c0/0x0054b970: ctors, 0xd4 buffer, constants 0x80/0x35.
- 0x0054b6f0: iterate FUN_0054b580, callback vcall +0x70 with
  `*(+0x0c)+0x188`, then FUN_00556430.
- 0x0054b9a0: copy +0x34/+0x35 via thunk_FUN_00538410; 0x0054ba20:
  bool over FUN_00556280.
- 0x0054ba80 (non-contiguous): buffers +0x28/+0x2c grown to count,
  floats at `*(+0x0c)+0x104/0x108/0x10c`, dot product, optional −0x34
  when +0x35 set, then FUN_00556330(0, count−1).

## Inferred
- Naming of vtables, flags, and object roles is descriptive.
- `__thiscall` / `__cdecl` splits follow pseudocode ECX use; all unverified.
- Refcount release helper used for peer/indirect releases is an inferred
  local pattern.

## Blockers
- `cl 13.10.3077` absent; all entries `status: "unverified"`, no passing claim.
- 0x0054ba80 is non-contiguous (0x54ba80–0x54bb09, 0x54bb10–0x54bbc0);
  second range not separately observed.
- Indirection-heavy vcall/alloc details (0x0054b380 sink, 0x0054b730
  token list, 0x0054b840/0x0054bc20 alloc) left schematic.

## Next
- Continue from QUEUE.json (949 remaining after subtracting this wave and
  all other `out/*/manifest.json` claims).
