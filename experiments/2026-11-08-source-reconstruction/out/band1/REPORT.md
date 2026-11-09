# Band 1 reconstruction — batch 1 (unverified)

Status: **unverified**. No PASS claim. No byte-match is possible: `cl` 13.10.3077 is
absent on this host, so nothing here compiles to a byte-comparable image and nothing
was added to `src/` or `build/units.json`. All reconstructions are clean-room from
shipped bytes (Ghidra 12.2 corpus `analysis/pseudocode/functions/<addr>.c`) plus the
existing deep dossiers; no leaked/unlicensed Gamebryo source was consulted or copied.

## Observed vs inferred

- **Observed (from corpus/triage/deep):** function spans and body ranges, call graphs
  (callee/caller address lists), literal strings (including save/load, quest, settings,
  loader, debug-overlay strings), data references (`DAT_*` corpus labels), the three deep
  dossiers (`0x00405d50`, `0x004c31a0`, `0x004aac10`), and the Windows message-loop /
  cursor-save / string-table / scene-alloc idioms described inline in `src/`.
- **Inferred (not observed):** every C++ signature, parameter name, global type/layout,
  callee arity, and the `FUN_*_recon` wrapper names. `DAT_*` / `FUN_*` names are corpus
  labels, not originals. Some string-table literal text (e.g. `"With the tide..."`,
  resolution labels) and several helper semantics (`FUN_004f14a0`, `FUN_004b06c0`, …)
  are marked inferred at each use site. Sizes above ~2000 bytes (e.g. the big dialog
  builders) were deliberately deferred so this batch stays faithful.

## Counts

- Slice: 1,023 functions (`0x00401000`–`0x004c3690`); matchable: 1,019 (1023 − 4 EH
  funclets: `0x004a0f58`, `0x004a0f64`, `0x004a10f3`, `0x004a1165`; zero thunks).
- This batch: **34 functions** in 6 files under `src/` (`core_engine.cpp`,
  `save_load.cpp`, `narrative_debug.cpp`, `epilogue_city.cpp`,
  `loaders_appearance.cpp`, `quest_lifetime_settings.cpp`, `menu_character.cpp` —
  7 files total), each with the shipped address in a comment above the definition.
  `manifest.json` has 34 entries; the count equals the source function count.
- `QUEUE.json`: 985 remaining matchable addresses, unique, within the slice, disjoint
  from the manifest, priority-ordered (small span + rich evidence first).

## By subsystem

- Save/load: `0x00401c10`, `0x00401d10`, `0x00401ee0`, `0x004022e0`, `0x004b5a40`.
- Core/engine: `0x00405d50`, `0x0042d320`, `0x0042e1d0`, `0x0042dd40`, `0x004879f0`.
- Narrative/debug: `0x0044ce60`, `0x004920a0`, `0x0044a3b0`, `0x0042e4f0`, `0x004a13c0`.
- Epilogue/city/land-battle text: `0x00456dd0`, `0x0043a0c0`, `0x004108a0`, `0x00444830`.
- Loaders/appearance/character: `0x00482ca0`, `0x004823f0`, `0x00482830`, `0x00482560`,
  `0x004af760`, `0x004813f0`, `0x004bd520`, `0x004bc7e0`.
- Quest/lifetime/settings: `0x004c31a0`, `0x004aac10`, `0x0044c4a0`, `0x0044c280`,
  `0x0044bfe0`, `0x004b2f10`, `0x004b3270`.

## Blockers

- No VC7.1 toolchain, so no compile or byte-compare; all entries remain `unverified`.
- Corpus pseudocode leaves register-passed parameters, string-handle layouts and several
  helper arities ambiguous; each is flagged in `unknowns` rather than guessed silently.
- The 4 EH funclets (`Catch@…`, near `0x004a0f58`) are excluded as non-matchable by
  the slice contract and are not queued.

## Next batch

Take the head of `QUEUE.json`: the small accessors/predicate helpers and the mid-size
string-verified functions, then the dialog mega-functions (`0x004772..`, `0x004612b0`,
`0x00471e00`, `0x004bcd90`, …) once their callees are known. No address is claimed twice.
