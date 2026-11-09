# Band 2 wave 4 — report

`cl 13.10.3077` is absent and no PASS is claimed. All 20 reconstructions
are UNVERIFIED clean-room candidates built from
`analysis/pseudocode/functions/*.c`.

## Observed

- 20 unclaimed addresses from `out/band2_wave3/QUEUE.json`. Batch A (10):
  forwarder leaf (0x0050c6b0), ESI-store forwarder (0x004f17f0), globals
  store + vtable dispatch (0x00500920), fetch-then-pass pair
  (0x0050c6d0/0x0050c740), call-then-zero-byte (0x004dccd0), indexed
  divisions + counter (0x004ea8b0), CopyFileA wrapper (0x004f1370), flag
  predicate (0x004f4e60), scaled float accumulations (0x004ff5f0).
  Batch B (10): double vtable dispatch (0x00500bc0), store + negate
  (0x00507250), call + vtable at +0x15c (0x0050c4a0), modf split
  (0x00513cf0), range check (0x004cca70), conditional-delete destructors
  (0x004ccc30/0x004d45c0/0x004d4d80), alloc-helper flag store (0x004d05f0),
  two-call init + flag update (0x004d3ef0).
- All bodies preserve observed offsets, constants, and call order from the
  pseudocode (e.g. `+0x74` dispatch, `+0x24c` zero, `+0x2c`/`+4` predicate,
  `+0x5c`/`+0x60`/`0x64` float stores, `& 1` delete tests). Register
  (ECX/EAX/ESI/BL) inputs are passed through as explicit parameters;
  nothing was invented for them.
- Every source file exists (`src/band2_wave4_a.cpp`,
  `src/band2_wave4_b.cpp`). Queue remainder = parent minus all global
  claims and these 20 (947 entries). No duplicates against any
  `out/*/manifest.json` (classes excluded).

## Inferred

- `CONCAT31(x,1)` in 0x004f4e60 equals `(x & ~0xFF) | 1` — low byte forced
  to 1 while upper bytes kept.
- Pseudocode's decimal `100` in 0x004ff5f0/0x00507250 is byte offset
  `0x64`; reconstructed as `+ 0x64`.
- 0x004ccc30/0x004d45c0/0x004d4d80 are scalar-deleting-destructor shapes
  (`FUN_*(); if (flags & 1) operator_delete(ECX)`); kept as separate
  entries so each address links.

## Blockers

- `cl 13.10.3077` absent: no byte-match, no PASS.
- ECX/EAX/ESI/BL register conventions, `DAT_008ea08c` object semantics,
  `DAT_0085a164`/`DAT_007263ba`/`DAT_008cade0` global layouts, and
  callees (`FUN_0050c550`, `FUN_0050c5d0`, `FUN_004eaae0`,
  `FUN_00507c90`, `FUN_005bf9b0`/`FUN_005bf9e0`) are unverified.

## Next

- Continue down the remainder queue with the next strong-evidence picks.
