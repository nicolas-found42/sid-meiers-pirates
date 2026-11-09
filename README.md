# Sid Meier's Pirates! (2004)

- Shared lab hub: [instructions](../../AGENTS.md), [tools](../../docs/toolchain.md). Paths are relative to this repository.
- Purpose: build a matching decompilation of the shipped Windows executable, function by function, and measure how much of it can be rebuilt byte-identically with the original toolchain.
- Target: Windows x86-32, *Sid Meier's Pirates!* v1.0.2.0 (build 30927), GOG "Live the Life" installer.
- Canonical input: `../../games/raw/pirates.exe`, 792,859,072 bytes, SHA-256 `8851023b95f10b37d5fd8d9cd2ba5d68094e92f0526a0e6eb27adc350b4d8e54`. See [games/INPUTS.json](../../games/INPUTS.json).
- Derived image: `experiments/2026-11-08-target-identification/output/extracted/app/Pirates!.exe`, 3,323,288 bytes, SHA-256 `6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9`.
- Engine: statically linked Gamebryo 10.1.0.0 (NiMain, NiAnimation, NiCollision, NiDX9), Miles sound, Bink video, dynamic VC7.1 CRT.
- Implementation: `tools/pe.py` (PE facts), `tools/build_inventory.py` (Ghidra inventory), `tools/match.py` (compile-and-compare harness), `tests/run_fixture.py` (harness validation).
- Status: observed and reproduced on 2026-11-08. **Decompilation is complete**: all 8,181 analyzed internal functions have a Ghidra 12.2 listing, and 341 external imports are indexed; `tools/build_decompile_index.py` verifies 0 missing and 0 bad hashes. The readable reconstruction tree at `reconstruction/` holds an unverified C++ candidate for all 7,862 matchable functions (360 batch sources under `experiments/2026-11-08-source-reconstruction/out/`; 7,166 full-body, 696 manifest-partial, 340 `NEEDS_MANUAL` sites), 562 class/vtable records, and 57 headers with explicit 32-bit padding; 1,188 field offsets check clean. 3 PASS: the recovered VC7.1 compiler (`cl` 13.10.3077 under Mach9 Wine) has produced byte-identical code for `FUN_00547610`, `FUN_0054a9f0`, `FUN_005366b0` via `tools/match.py`; the remaining candidates are unverified.
- Current blocker: none for reconstruction coverage. Toolchain is installed and proven (see [findings/2026-11-08-compiler-availability.md](findings/2026-11-08-compiler-availability.md)); bulk candidate fidelity is the open question.
- Next action: turn mass candidates into compilable `build/units.json` entries (fix the 340 `NEEDS_MANUAL` sites first), then run `tools/match.py compare` at scale toward byte-identical matches. Load or acquire the matching `Pirates!.pdb` if it surfaces. `tools/recon_status.py`, `tools/check_class_layout.py`, and `tools/merge_reconstruction.py` validate the tree.

## Layout

- `build/functions.json`: 8,181 internal functions with addresses and spans, generated from a Ghidra 12.2 inventory.
- `build/units.json`: image identity, compiler recipe, and the list of claimed translation units. Empty until the toolchain is verified.
- `src/`: C++ translation units, organized by subsystem, added only with a unit declaration.
- `reconstruction/`: complete decompilation index (`DECOMPILATION.md`, `decompilation-index.json`), decompiler-derived unverified candidates, class headers, merged manifest, and remaining queue; regenerate with `tools/build_decompile_index.py` and `tools/merge_reconstruction.py`.
- `tools/`: PE reader, inventory generator, matching harness, reconstruction validators.
- `tests/`: end-to-end harness fixture (pass and negative control).
- `findings/`: conclusions with exact evidence.
- `references/`: source citations.
- `experiments/`: per-question records; `output/` is ignored and measured by the hub checker.
- `analysis/`: local REA evidence bundle and databases, ignored.

## Verified state

- `python3 tools/pe.py info …` reads the image headers; `debug` exposes the PDB identity; `version` exposes v1.0.2.0 build 30927; `rich` exposes toolchain build numbers.
- `python3 tools/build_inventory.py … --stats` reproduces `build/functions.json`: 8,181 functions, 2,879,488 bytes of `.text`, median span 128 bytes.
- `python3 tools/match.py check …` validates image hash, inventory hash, claimed addresses and duplicate claims. With no units it reports 0 of 8,181 claimed.
- `python3 tests/run_fixture.py` compiles a two-function C file, links it at a fixed image base, relocates a COFF object, compares both functions, and verifies that one flipped image byte makes the comparison fail.

See [findings/2026-11-08-target-identification.md](findings/2026-11-08-target-identification.md), [findings/2026-11-08-team-decompilation.md](findings/2026-11-08-team-decompilation.md) and [docs/METHOD.md](docs/METHOD.md).
