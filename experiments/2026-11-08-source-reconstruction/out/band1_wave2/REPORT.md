# Band 1 wave 2 — 20 reconstructions (unverified)

Status: **unverified**. No PASS claim. `cl 13.10.3077` is absent on this host, so nothing here compiles to a byte-comparable image and nothing was added to `src/` or `build/units.json`. All reconstructions are clean-room from shipped bytes (Ghidra 12.2 corpus `analysis/pseudocode/functions/<addr>.c`) plus `analysis/team/band1/triage.json`; no leaked/unlicensed Gamebryo source was consulted.

## Observed vs inferred

- **Observed:** spans/body ranges, call graphs, literal strings (difficulty help, loot-division, stage selectors, bribe/prison, mission caravan, war canoe, governor agriculture, `pc_lost_city.kfm`, `pc_hid_treas.kfm`, `assets\terrain\skydome006.nif`, `Incognito`, `Config.ini`, `merch_cap_*`/`milit_cpt_*`, `Name your @SHIPTYPE`, `bigParchment.dds`, `barmaid_%c.dds`, `mayo_%c%1d.dds`, `pc_govm.kfm`, camera names), data refs, flag constants (0x10000, 0x80000000, 0x3f800000, 0xff7ffff, 0x9a proximity), timed loops (`rand()%3+3`, `rand()%6+6`, `DAT_0085a150+=6000`), refcount idiom.
- **Inferred:** every signature, parameter name, global type/layout, callee arity, `*_recon` wrapper names. `DAT_*`/`FUN_*` are corpus labels. Long dialog state machines and cinematic frame loops are condensed to their observed call order and constants rather than invented verbatim.

## Counts

- Parent queue `out/band1/QUEUE.json`: 985 entries (bare list of `{address,priority,reason}`).
- This wave: **20 functions** in 4 files under `src/` (`quest_dialog.cpp` 8, `appearance.cpp` 4, `scene_cinematic.cpp` 4, `menu_systems.cpp` 4). `manifest.json` has 20 entries.
- `QUEUE.json`: parent minus these 20, minus every other `out/*/manifest.json` claim — see file for remaining length.

## By subsystem

- Quest/dialog/difficulty: 0x0046e080, 0x004102a0, 0x00419370, 0x004517b0, 0x0040b340, 0x0040a670, 0x0040ae10, 0x0040ba80.
- Appearance: 0x004bcd90, 0x00482a00, 0x00453030, 0x0044b8a0.
- Scene/cinematic: 0x00428fd0, 0x0044fa40, 0x00452890, 0x00418dd0.
- Menu/systems: 0x004b19e0, 0x0041a300, 0x00471120, 0x00466f00.

## Blockers

- No VC7.1 toolchain; no compile or byte-compare; all entries remain `unverified`.
- Register-passed params, string-handle layouts, several helper arities are ambiguous in the corpus; flagged in `unknowns`.

## Next

Take the next unclaimed head of `QUEUE.json` (parent minus wave claims), preferring small span + high string count first. No address is claimed twice.
