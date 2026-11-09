# Band 1 wave 4 — 10 reconstructions (unverified)

Status: **unverified**. No PASS claim. `cl 13.10.3077` is absent on this host, so nothing here compiles to a byte-comparable image and nothing was added to `src/` or `build/units.json`. All reconstructions are clean-room from shipped bytes (Ghidra 12.2 corpus `analysis/pseudocode/functions/<addr>.c`) plus `analysis/team/band1/triage.json`; no external sources were consulted.

## Observed vs inferred

- **Observed:** spans 32–1712, body ranges (incl. non-contiguous 0x00473b70/0x004b40b0/0x00483ca0), call order, literal constants (`0x4a`, `0xd3`, `0x32`, `0x427a0000`, `+0xf`/`+0x17`, `0xd2`/`0xd4`, `0xbf800000`, `0xfffffff0|0x80000020`, `0xc0`, `0x3dcccccd`/`0x47c35000`, `0x12d`, `0xffc00000`, `0x210`/`0x1b`/`0x20`, `0x35`, `-8` byte offset), strings (`@NAVKEYHELP`..`@LBATTLESKEYHELP`, 10-second resolution prompt, `pauseMenuBG.dds`, `jailed_pc.kfm`, `Camera All`, `shadow_01`, `fx_lantern`/`fx_candle`/`fx_fireplace`, `Name: `, `%s_%03X`), vtable stores, register-only inputs (`EAX`/`ECX`/`EDX`/`ESI`).
- **Inferred:** every signature, parameter name, global type/layout, callee arity, `*_recon` wrapper names. `DAT_*`/`FUN_*`/`PTR_*` are corpus labels. Register-only inputs are taken as explicit arguments and flagged in `unknowns`.

## Counts

- Parent queue `out/band1_wave3/QUEUE.json`: 944 entries (`{address,priority,reason}` objects).
- This wave: **10 functions** in 2 files under `src/` (`priority.cpp` 5, `small_leaves.cpp` 5). `manifest.json` has 10 entries.
- `QUEUE.json`: parent minus all `out/*/manifest.json` claims (including this wave); 934 remaining.

## By subsystem

- Priority (largest/small-priority head): 0x00473b70, 0x004b40b0, 0x00450cf0, 0x00483ca0, 0x00470b90.
- Small leaves: 0x00412c90, 0x00419dc0, 0x00431910, 0x004842d0, 0x004bf420.

## Blockers

- No VC7.1 toolchain (`cl 13.10.3077` absent); no compile or byte-compare; all entries remain `unverified`.
- Register conventions, helper arities, and object layouts beyond observed offsets are ambiguous in the corpus; flagged in `unknowns`.

## Next

Take the next unclaimed head of `QUEUE.json` (parent minus wave claims), preferring small span + high string count first. No address is claimed twice.
