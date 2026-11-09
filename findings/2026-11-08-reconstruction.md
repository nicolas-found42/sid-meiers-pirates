# Source reconstruction — status and evidence

Date: 2026-11-08. Target: `Pirates!.exe`, PE32 i386, base `0x00400000`,
SHA-256 `6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9`,
linker 7.10, Gamebryo 10.1.

## Result

A decompiler-derived reconstruction tree exists at `reconstruction/`:

| Item | Count | Evidence |
|---|---:|---|
| decompiled internal functions | 8,181 | one Ghidra `.c` listing each |
| external imports indexed | 341 | `reconstruction/decompilation-index.json` |
| inventory functions without pseudocode | 0 | `tools/build_decompile_index.py` |
| matchable functions in inventory | 7,862 | `build/functions.json` |
| reconstructed C++ candidates | 7,862 | 359 mass/band manifests; all `unverified` |
| full-body candidates | 7,166 | `tools/merge_reconstruction.py` (final run) |
| partial claims | 696 | manifest flags, `tools/recon_status.py` final ingest |
| `NEEDS_MANUAL` annotation sites | 340 | grep over the 360 batch sources |
| remaining matchable queue | 0 | `reconstruction/QUEUE.json` empty after final ingest |
| class/vtable records | 562 | `out/classes/vtable-map.json` |
| class headers | 57, 562 structs | explicit 32-bit padding; 1,188 fields |
| field-offset assertions | 1,188 | `tools/check_class_layout.py` → 0 errors |
| i386 compile of all headers | pass | `i686-w64-mingw32-g++ -fsyntax-only` with `offsetof` static_asserts |

The Ghidra 12.2 pseudocode corpus is complete at
`analysis/pseudocode/functions/`: one `.c` per analyzed function. Its
tracked index, `reconstruction/DECOMPILATION.md`, lists all 8,181 internal
functions and 341 external imports; `tools/build_decompile_index.py` re-hashes
every file and reports `status: complete`. The `reconstruction/src/` layer is
the readable C++ reconstruction on top of that complete corpus, not the
decompilation itself.

## Verification performed

- `python3 tools/build_decompile_index.py` — 8,181 inventory functions,
  8,181 written files, 341 external imports, 0 missing, 0 extra, 0 bad
  hashes; `status: complete`.
- `python3 tools/ingest_mass_reconstruction.py` (final) — 359 mass
  manifests derived from the sources themselves: **7,862 unique claims,
  0 duplicates, 0 unclaimed matchable addresses**. 696 manifest flags
  declare partial bodies; 340 `NEEDS_MANUAL` comment sites mark
  provider-lost operands (x87 control-word stores, `extraout_EDX`
  receivers) — recorded, not invented. None of the candidates has been
  compiled.
- `python3 tools/merge_reconstruction.py` (final) — 391 waves, 7,862
  functions merged into `reconstruction/src/`, 7,166 full-body, 696
  manifest-partial, 0 duplicates, 0 bad; `reconstruction/QUEUE.json`
  count 0.
- A cross-batch duplicate-definition scan (regex over all 360 batch
  sources) found 2 double definitions (`FUN_00443a00`, `FUN_004be3f0`)
  and 1 empty stub overload (`FUN_00478690`); all three were removed in
  favor of the complete translation, rescan 0 duplicates.
- `python3 tools/check_class_layout.py` — 57 headers, 1,188 fields, 0 errors.
- Generated `/tmp/class_layout_check.cpp` including all 57 headers and one
  `static_assert(offsetof(...))` per field; compiled with
  `i686-w64-mingw32-g++ -std=c++17 -fsyntax-only` → exit 0.
- `python3 tools/merge_reconstruction.py` — merges every wave into
  `reconstruction/src/<wave>/`, copies class headers, recomputes the queue.

## Not verified / blockers

1. **Matching is only started.** `cl 13.10.3077` is extracted and runs under
   Mach9 Wine/FEX; it has produced byte-identical code for three functions,
   `FUN_00547610`, `FUN_0054a9f0` and `FUN_005366b0` (`tiny_547610`,
   `tiny_54a9f0`, `tiny_5366b0`). The bulk
   candidates are decompiler-derived and mostly do not compile as-is; the
   candidates remain unverified.
2. **No original symbols or PDB types.** Class names are from adjacent
   strings where present, otherwise synthetic; all field names are offsets.
3. **Register-only entries.** 340 `NEEDS_MANUAL` annotations mark places
   where the provider lost an operand (x87 control word, `extraout_EDX`
   receivers); the observed call shape is preserved with a comment instead
   of an invented signature.
4. **Candidate quality is unproven.** The decompiler corpus is complete
   (8,181/8,181) and all 7,862 matchable functions have a candidate
   body under `experiments/2026-11-08-source-reconstruction/out/
   mass_*/src/`, but translation fidelity is only
   proven for the three byte-identical matches. The bulk candidates follow
   one convention (`// 0xADDR — observed shape` headers, explicit
   `void* self` receivers, extern helpers, no `this`), so the next phase
   is mechanical: compile them as units and let `tools/match.py` decide.
5. **Known regression class.** Retries across ~40 batches found and fixed
   real translation defects (dropped second upload pass in `0x670fb9`,
   lost `(uint)(piVar9 == 0)` decision variable in `FUN_0067feb4`, shifted
   16-bit `CONCAT` shifts in `FUN_006b2a2b`); expect similar latent defects
   in the unverified remainder.

## Reproduce

```sh
cd games/sid-meiers-pirates
python3 tools/build_decompile_index.py
python3 tools/recon_status.py
python3 tools/check_class_layout.py
python3 tools/merge_reconstruction.py
```

## Related records

- `findings/2026-11-08-first-match.md` — original compiler and first two byte-identical functions.
- `findings/2026-11-08-compiler-availability.md` — VC7.1 extraction and runtime evidence.

- `findings/2026-11-08-target-identification.md` — PE/Gamebryo identity.
- `findings/2026-11-08-external-sources.md` — public format sources.
- `findings/2026-11-08-toolchain-acquisition.md` — compiler acquisition.
- `findings/2026-11-08-wine-probe.md` — i386 Wine probe.
- `experiments/2026-11-08-source-reconstruction/` — 360 `mass_XXXX` batch
  directories, each with `src/<batch>.cpp` (one candidate per address),
  `manifest.json`, `QUEUE.json`, `REPORT.md`, and `TASK_RETRY.md` where a
  retry wave ran; per-batch evidence.
