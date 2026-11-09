# 2026-11-09 — Candidate compile + compare pipeline (scale harness)

Target: `games/raw/pirates.exe` (SHA-256 `6e88b90e…81744 7c9`, 3,323,288 bytes).
Question: can every decompiled candidate in `src/` be compiled by the recovered
VC7.1 toolchain and compared against the shipped image at scale?

## Observed

- NEEDS_MANUAL census (grep over `src/**/*.cpp`): 336 markers in 112 files.
  Classes: register-modeling notes 91, elided/condensed transcriptions 54,
  x87/FPU 21, indirect calls 21, other/condensed-body notes 149.
  The authoritative corpus (`analysis/pseudocode/functions/0x*.c`, 8,181 files,
  hash-verified) is complete, so "elided" markers are transcription gaps, not
  corpus gaps.
- VC7.1 (cl 13.10.3077) ships no `<cstdint>` and no Windows SDK headers in the
  recovered install. Candidate files include both, so raw compiles fail.
- Harness fixes in `tools/match.py`:
  - COFF relocations: `IMAGE_SCN_LNK_NRELOC_OVFL` (0x01000000 + count 0xFFFF)
    sections carry the real count in the first relocation record's symbol-index
    field; parse accordingly.
  - Relocation symbol indices are **physical** symbol-table record indices
    (aux records included); the parsed logical symbol list therefore needs a
    `symbol_by_physical` map, and `apply_relocations` now receives the COFF
    object, not the list.
- New tools:
  - `tools/gen_win32_shim.py` → `build/shim/vc71shim.h`: generated compile
    shim (candidate typedef names, Win32 type vocabulary, extern "C"
    dllimport declarations for all 252 C-identifier imports from the image's
    import table, typed CRT signatures). Deterministic from the shipped image.
  - `tools/gen_units.py`: normalizes every `src/*/*/*.cpp` (strip includes,
    `extern "C"` linkage for address-headed definitions and extern decls,
    duplicate-extern dedupe keeping the longest param list, `nullptr`→0),
    maps every `// 0xADDR` header to its following definition, declares
    undefined `FUN_`/data externs by name-derived addresses, Win32 imports by
    `__imp__` IAT slots, and writes `gen_<wave>` units into `build/units.json`
    (hand units preserved; cross-unit duplicate claims dropped with a log).
  - `tools/compare_census.py`: serial per-unit `match.py compare` runs
    (one Wine prefix; concurrent cl runs serialize on prefix locks anyway),
    writing `analysis/units-census.json` with per-unit status and a
    first-difference histogram.
  - `tools/triage_census.py`: clusters census errors by class.

## Result at the time of writing

- 469 units (3 hand + 466 generated) declaring 7,435 of 7,862 matchable
  functions (94.61%); `tools/match.py check` passes (config OK, no duplicate
  claims). 16 files skipped: no address-headed definitions or fully
  hand-claimed.
- First census pass (in flight, results land in `analysis/units-census.json`):
  the dominant error class is file-level C++ compilation of Ghidra-flavored
  candidates (implicit int↔pointer conversions, duplicate extern arities,
  `__thiscall` keyword, `operator delete` definitions); byte-compare on the
  units that compile works end-to-end (band8 CRT helpers compare cleanly and
  honestly FAIL: the C transcription of `__aullshr`/`__allmul`/`__allshl`
  cannot reproduce the original hand-written asm sequences).

## Inferred

- Byte-matching at scale needs two passes: (1) mechanical compile repair of
  every candidate file (in flight via agents), (2) per-function fidelity
  triage of first-difference classes, where small leaf functions should pass
  under `/O2` and larger functions need flag and type discovery per unit.

## Blockers / next

1. Finish NEEDS_MANUAL elimination (8 agents, 336 markers, target 0) and
   wave-2 compile repair (4 agents, 108 files).
2. Regenerate units from the repaired tree; rerun the census; triage.
3. Grow the PASS set; record per-function flag provenance in units.json.

## Verification

- `python3 tools/match.py check --image experiments/2026-11-08-target-identification/output/extracted/app/Pirates!.exe`
  → config OK, 279→7,435 matchable claimed as units were generated.
- `python3 tools/match.py compare --unit gen_band8_crt --image …` → compare
  completes with honest per-function FAIL results (no harness crashes).
- Baseline 3 hand units still PASS via `compare --all` (confirmed earlier this
  session, 3/3).
