# Project navigation

- Entry point: [README.md](README.md)
- Current question: can the v1.0.2.0 image be rebuilt as byte-identical functions with the original VC7.1 toolchain, and what is the first reproducible unit?
- Resume state: inventory and harness verified; toolchain missing. See [findings/2026-11-08-target-identification.md](findings/2026-11-08-target-identification.md) and [docs/TOOLCHAIN.md](docs/TOOLCHAIN.md).
- Method: [docs/METHOD.md](docs/METHOD.md)
- Research: [findings/2026-11-08-decompilation-landscape.md](findings/2026-11-08-decompilation-landscape.md)
- Harness evidence: [findings/2026-11-08-matching-harness.md](findings/2026-11-08-matching-harness.md)
- Sources: [references/README.md](references/README.md)

## Commands

```sh
# Identity and metadata
python3 tools/pe.py info   "experiments/2026-11-08-target-identification/output/extracted/app/Pirates!.exe"
python3 tools/pe.py debug  "experiments/2026-11-08-target-identification/output/extracted/app/Pirates!.exe"
python3 tools/pe.py version "experiments/2026-11-08-target-identification/output/extracted/app/Pirates!.exe"
python3 tools/pe.py rich   "experiments/2026-11-08-target-identification/output/extracted/app/Pirates!.exe"

# Regenerate the function inventory from the retained REA bundle
python3 tools/build_inventory.py \
  --bundle analysis/rea-pirates-bundle.json \
  --image "experiments/2026-11-08-target-identification/output/extracted/app/Pirates!.exe" \
  --out build/functions.json --stats

# Validate the unit config
python3 tools/match.py check \
  --image "experiments/2026-11-08-target-identification/output/extracted/app/Pirates!.exe"

# Compile and compare one unit (requires the VC7.1 toolchain)
python3 tools/match.py compare \
  --image "experiments/2026-11-08-target-identification/output/extracted/app/Pirates!.exe" \
  --unit <id>

# Validate the harness without the original compiler
python3 tests/run_fixture.py
```

## State

- `build/functions.json`: 8,181 functions, 2,879,488 bytes, 7,932 placeholders, 140 thunks.
- `build/units.json`: 0 claimed units.
- `analysis/rea-pirates-bundle.json`: ignored REA bundle (12 records) used to generate the inventory.
- Experiment output: `experiments/2026-11-08-target-identification/output/` (4,883,196 bytes, extracted app files only).
