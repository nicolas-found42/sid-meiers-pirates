# 2026-11-09 — NEEDS_MANUAL elimination + compile-and-compare at scale

Target: `games/raw/pirates.exe` candidates under `src/` (SHA-256-identified image; see build/units.json).

## Question

1. Can every `// NEEDS_MANUAL` marker in the decompiled candidate tree be
   resolved into faithful, compilable C++ (re-derived from the complete
   hash-verified corpus in `analysis/pseudocode/functions/0x*.c`), reaching
   zero markers?
2. Can every candidate file be compiled by the recovered VC7.1 toolchain and
   compared against the shipped image at scale, growing the byte-verified set
   beyond the initial 3 PASS units?

## Commands

- Marker census: `grep -rn NEEDS_MANUAL src --include='*.cpp'`
- Inventory: `experiments/2026-11-09-fix-needs-manual/inventory.json`
  (336 markers / 112 files, classified; batch slices in /tmp/nm_batches.json)
- Shim: `python3 tools/gen_win32_shim.py` (build/shim/vc71shim.h)
- Unit generation: `python3 tools/gen_units.py` (build/units.json + build/units-src/)
- Validate: `python3 tools/match.py check --image "experiments/2026-11-08-target-identification/output/extracted/app/Pirates!.exe"`
- Census: `python3 tools/compare_census.py` → `analysis/units-census.json`
- Triage: `python3 tools/triage_census.py`

## Resource limits

Wine prefix locks force serial compiles (~5-15 s per unit); 469-unit census ≈
1-2 h. One Wine prefix (`analysis/toolchain/prefix2`); no concurrent cl runs.

## Evidence

See `findings/2026-11-09-units-pipeline.md` (kept current) and
`analysis/units-census.json`.

## Result

In flight; this record is updated with the final marker count, compile
coverage, and PASS counts when the campaign completes.

## Next action

Regenerate units from the repaired tree, rerun the census, triage
first-difference classes, and grow the PASS set; then update PROJECT.md.
