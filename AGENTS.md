# Project instructions

Shared lab hub: `../..` (relative to this repository root). At session start, read its `AGENTS.md` and `docs/toolchain.md`; follow its conditional references for tools and workflow/storage policies. This is an explicit read instruction: this project is a separate Git root, so parent instructions are not discovered automatically. If the hub is unavailable, report the missing path before starting lab-tool operations.

Read [README.md](README.md) and [PROJECT.md](PROJECT.md), then the latest relevant experiment. Check Git status. Keep this project an independent repository.

## Target rules

- The canonical input is the installer at hub `games/raw/pirates.exe`. Never copy it into this repository or into `experiments/*/output/`.
- The decompilation target is the extracted `Pirates!.exe` with SHA-256 `6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9`. A different image is a different project state.
- A function is matched only when `tools/match.py` compares its relocated compiled bytes with the shipped image and reports PASS. A plausible decompiler listing, a compiling source file, or a similar function is not a match.
- The compiler is Visual C++ .NET 2003, `cl` 13.10.3077 / `link` 7.10.3077. Do not weaken the claim by matching with another compiler; another compiler can help explore, not certify.
- Per-unit flags are part of the claim. Do not silently change them; record the flags that produced a match and why they are plausible for the original build.
- Do not copy source code from leaked or unlicensed engine sources. Gamebryo 10.1 is proprietary. Use shipped bytes, public documentation, and clean-room reconstruction.
- Do not commit game data, assets, extracted DLLs, object files, or PDB files. `build/functions.json` contains addresses and names only and is committed.
- Keep the harness deterministic: no network access during comparison, no ambient timestamp or path inputs, no source edits during a run.

## Workflow

Use `experiments/<id>/README.md` for every investigation. Record the exact image hash, command, observation, evidence location, retention state, and next action. Promote supported conclusions to `findings/`. Update `PROJECT.md` before finishing.
