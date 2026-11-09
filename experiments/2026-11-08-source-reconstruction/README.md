# 2026-11-08-source-reconstruction: how much of `Pirates!.exe` can be decompiled and reconstructed?

- Status: completed for decompilation coverage and mass reconstruction; matching verification remains open (3 of 7,862 byte-identical)
- Target/build/platform/architecture: Sid Meier's Pirates! 2004, v1.0.2.0 build 30927, PE32 i386, Windows x86
- Canonical input: hub `games/raw/pirates.exe`, 792,859,072 bytes, SHA-256 `8851023b95f10b37d5fd8d9cd2ba5d68094e92f0526a0e6eb27adc350b4d8e54` (sparse installer; only ~3.3 MB physically allocated)
- Extracted target: `experiments/2026-11-08-target-identification/output/extracted/app/Pirates!.exe`, SHA-256 `6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9`
- Question: does every analyzed function have a decompiler listing, and how far can source reconstruction go with the original VC7.1 compiler now running?
- Expected observation: an index covering every inventory address, a verifiable corpus, and a manifest of reconstructed candidates with explicit unverified/partial states.
- Tool/provider/version: REA Ghidra 12.2 (`analysis_profile` `59fe0f4e…`); VC7.1 `cl` 13.10.3077 under Mach9 Wine for byte comparison; `i686-w64-mingw32-g++` for syntax checks only
- Working directory: `games/sid-meiers-pirates`
- Exact commands:
  - `python3 tools/build_decompile_index.py`
  - `python3 tools/recon_status.py`
  - `python3 tools/check_class_layout.py`
  - `python3 tools/merge_reconstruction.py`
  - `python3 tools/match.py compare --unit tiny_547610`, `--unit tiny_54a9f0` and `--unit tiny_5366b0` (byte comparison with VC7.1)
- `i686-w64-mingw32-g++ -std=c++17 -fsyntax-only -Ireconstruction/include/classes src/*/*.cpp src/*/*/*.cpp` (diagnostic; not a match)
- Limits before running: 512 MiB experiment output, 5 min per tool/agent call, 40 GiB free-space floor. The campaign spans multiple bounded calls; no single command exceeded 5 min.
- Free space before/after: 378 GiB free on the working volume at the final check; experiment output 5.2 MiB.
- Output locations: `experiments/2026-11-08-source-reconstruction/out/` (5.2 MiB), ignored corpus `analysis/pseudocode/` (77 MiB), generated tree `reconstruction/`.
- Started/finished and exit result: 2026-11-08 21:41–2026-11-09 01:4x; corpus verifier exit 0; mass wave 360 batches over ~26 min wall with 4 retry waves.

## Observations and evidence

- `build/functions.json` lists 8,181 functions: 7,862 matchable, 8,099 placeholders, 140 thunks, 179 EH funclets.
- `analysis/pseudocode/decompile-index.json` has 8,181 written internal entries and 341 external imports.
- `tools/build_decompile_index.py` re-hashed all 8,181 files: 0 missing, 0 extra, 0 bad hashes; status `complete`.
- `reconstruction/DECOMPILATION.md` and `reconstruction/decompilation-index.json` expose every address, name, byte span, and pseudocode hash.
- Reconstruction (mass wave, 360 `mass_XXXX` batch dirs under `out/`): 359 manifests, final ingest 7,862 unique matchable claims, 0 duplicate addresses, 0 unclaimed; `tools/merge_reconstruction.py` final: 7,166 full-body, 696 manifest-partial, queue empty.
- 340 `NEEDS_MANUAL` comment sites record provider-lost operands (x87 control-word stores, `extraout_EDX` receivers) instead of invented signatures.
- A ~40-batch retry audit found and fixed real translation defects (dropped second upload pass in `0x670fb9`; lost `(uint)(piVar9 == 0)` decision variable in `FUN_0067feb4` making a whole region unreachable; wrong 16-bit `CONCAT` shifts in `FUN_006b2a2b`); per-batch `TASK_RETRY.md` files record the audits.
- Class evidence: 562 vtable records; 57 headers; 1,188 field offsets; `check_class_layout.py` reports 0 errors.
- A cross-compiler syntax-only pass over the candidate tree reports missing declarations and type mismatches. That is expected evidence that candidates are not yet original-source equivalents; it is not a byte comparison.

## Conclusion and limits

The **decompiler-level decompilation is complete**: every analyzed internal function has a pseudocode listing, and every external import is indexed. The **readable C++ reconstruction covers the matchable surface**: all 7,862 matchable functions have a candidate body, of which 7,166 are full-body and 696 carry partial markers.

Candidate **fidelity is unproven**: no mass candidate has been byte-compared. The original compiler is available and runs: `cl 13.10.3077` produced byte-identical code for three shipped functions, `FUN_00547610`, `FUN_0054a9f0` and `FUN_005366b0` (`tiny_547610`, `tiny_54a9f0`, `tiny_5366b0`), verified by `tools/match.py`. That is 3 of 7,862 matchable functions; the mass candidates are unverified and mostly not compile-ready. The bulk reconstruction is not a matching decompilation.

## Retention

Preserve the original installer, the extracted target, `analysis/pseudocode/`, the REA bundle, all wave manifests/sources, and the generated reconstruction tree. The 77 MiB corpus is ignored but durable; it is the complete decompilation evidence. No output was deleted.

## Next action

The mass reconstruction is done; translation-fidelity work remains. The compiler path is proven; the next matching work is to make the mass candidates compile as units (`build/units.json`), fix the 341 `NEEDS_MANUAL` sites first, and run `tools/match.py compare` until each function is `PASS`.
