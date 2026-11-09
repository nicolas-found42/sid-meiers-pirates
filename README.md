# Sid Meier's Pirates! (2004)

- Shared lab hub: [instructions](../../AGENTS.md), [tools](../../docs/toolchain.md). Paths are relative to this repository.
- Purpose: build a matching decompilation of the shipped Windows executable, function by function, and measure how much of it can be rebuilt byte-identically with the original toolchain.
- Target: Windows x86-32, *Sid Meier's Pirates!* v1.0.2.0 (build 30927), GOG "Live the Life" installer.
- Canonical input: `../../games/raw/pirates.exe`, 792,859,072 bytes, SHA-256 `8851023b95f10b37d5fd8d9cd2ba5d68094e92f0526a0e6eb27adc350b4d8e54`. See [games/INPUTS.json](../../games/INPUTS.json).
- Derived image: `experiments/2026-11-08-target-identification/output/extracted/app/Pirates!.exe`, 3,323,288 bytes, SHA-256 `6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9`.
- Engine: statically linked Gamebryo 10.1.0.0 (NiMain, NiAnimation, NiCollision, NiDX9), Miles sound, Bink video, dynamic VC7.1 CRT.
- Implementation: `tools/pe.py` (PE facts), `tools/build_inventory.py` (Ghidra inventory), `tools/match.py` (compile-and-compare harness), `tests/run_fixture.py` (harness validation).
- Status: observed and reproduced on 2026-11-08. Inventory and harness are complete and tested. No game function has been matched yet: the original compiler is not installed.
- Current blocker: `cl` 13.10.3077 / `link` 7.10.3077 (Visual C++ .NET 2003, available as the free Visual C++ Toolkit 2003) is not installed. The host is Apple Silicon, where 32-bit x86 execution is not assumed; verify a capable Wine/VM host before installing.
- Next action: verify the exact compiler on a 32-bit-capable host, then create `src/` for the first candidate unit and run `tools/match.py compare`.

## Layout

- `build/functions.json`: 8,181 internal functions with addresses and spans, generated from a Ghidra 12.2 inventory.
- `build/units.json`: image identity, compiler recipe, and the list of claimed translation units. Empty until the toolchain is verified.
- `src/`: C++ translation units, organized by subsystem, added only with a unit declaration.
- `tools/`: PE reader, inventory generator, matching harness.
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

See [findings/2026-11-08-target-identification.md](findings/2026-11-08-target-identification.md) and [docs/METHOD.md](docs/METHOD.md).
