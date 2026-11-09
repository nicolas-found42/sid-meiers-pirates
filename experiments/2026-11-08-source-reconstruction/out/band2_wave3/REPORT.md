# Band 2 wave 3 — report

`cl 13.10.3077` is absent and no PASS is claimed. All 20 reconstructions
are UNVERIFIED clean-room candidates built from
`analysis/pseudocode/functions/*.c`.

## Observed

- 20 unclaimed addresses from `out/band2/QUEUE.json` (parent: 1011
  entries). Batch A (10): two-call init pair pair (0x004d3f50, 0x004d3f90),
  water texture scale setter (0x004e4530), single forwarder (0x004f17b0),
  EDX register forwarders (0x004f2600, 0x004f3540), FUN_004f60d0 selectors
  (0x004f6090/0x004f60b0), varargs formatter pair (0x004f8b40/0x004f8b80).
  Batch B (10): float floor (0x004e2490), inverted predicate (0x004fca80),
  lazy one-time init (0x004ffe50), singleton field getter (0x005002d0),
  vtable-indirect dispatch (0x00508340), clear-then-delete (0x00506a80),
  short equality (0x0050b070), zero-init pass-out (0x0050b1a0), increment
  (0x0050c650) and decrement (0x0050c680) wrappers.
- All bodies preserve observed offsets, constants, strings
  (`"fWaterTexScale"`, `0x3fc` buffer cap), and call order from the
  pseudocode. EDX/ECX-register inputs are passed through as explicit
  parameters; nothing was invented for them.
- Every source file exists (`src/band2_wave3_a.cpp`,
  `src/band2_wave3_b.cpp`). Queue remainder = parent minus all global
  claims and these 20 (967 entries). No duplicates against any
  `out/*/manifest.json` (classes excluded).

## Inferred

- Bodies 0x004d3f50 and 0x004d3f90 are identical (`FUN_004985e0(); 
  FUN_004a14b0();`); kept as separate entries so both addresses link.
- `FUN_004f8b80` target `PTR_FUN_007264d4` is an indirect debug hook
  analogous to the `OutputDebugStringA` path in 0x004f8b40.

## Blockers

- `cl 13.10.3077` absent: no byte-match, no PASS.
- EDX/ECX register convention, va_list layout, and the semantics of
  `DAT_008cad0c`, `DAT_008ea08c`, `DAT_00727c30`, `DAT_00727b28`,
  `PTR_FUN_007264d4`, `FUN_004f4ed0`/`FUN_0050b150`/counter helpers are
  unknown (see manifest `unknowns`).

## Next

- Continue down the queue by span; candidate callees referenced here
  (FUN_004fcd60/FUN_004985e0/FUN_004a14b0/FUN_005be280/FUN_004f2620/
  FUN_004f3560/FUN_004f60d0/FUN_004f4ed0/FUN_005002f0/FUN_0050b150/
  FUN_005f0ddc/FUN_0050c550) are unclaimed and matchable.
