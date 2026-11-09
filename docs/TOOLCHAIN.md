# Toolchain

## Required compiler

The image reports linker version 7.10 and Rich-header build 3077. That is the Visual C++ .NET 2003 RTM toolset:

| Tool | Version | Source |
|---|---|---|
| `cl.exe` | 13.10.3077 for 80x86 | Visual Studio .NET 2003 RTM; some Visual C++ Toolkit 2003 releases also report 13.10.3077 |
| `link.exe` | 7.10.3077 | same toolset |

VS .NET 2003 SP1 reports `cl` 13.10.6030 and is a different candidate; do not use it for a matching claim unless the bytes prove it. Toolkit 2003 builds vary: a Microsoft blog comment reports 13.10.3052 for one Toolkit release, while other installation guides report 13.10.3077. Verify the installed compiler's build; only 13.10.3077 is the current candidate.

Verify after installation:

```sh
wine cl 2>&1 | head -2     # Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3077 for 80x86
wine link 2>&1 | head -2   # Microsoft (R) Incremental Linker Version 7.10.3077
```

If either reports a different build, the toolchain does not match the image and the harness will not certify a unit.

## Why Wine

`cl.exe` is a 32-bit Windows x86 program and needs a Windows-compatible loader. Wine on an x86_64 Linux host is the well-trodden path: it keeps the original compiler and linker, which is the whole point of matching. A Windows x86 VM works equally well; a different compiler does not.

The New Vegas decompilation (the largest public PC x86 matching project) uses Wine with multiple Visual C++ versions; see [references/README.md](../references/README.md).

Apple Silicon is a special case: Rosetta translates x86_64, not i386, and a 32-bit Windows process needs either Wine's WoW64 layer on an x86_64 host, a 32-bit-capable CrossOver build, or a full x86 Windows VM. Do not assume `cl.exe` will run on this Mac. Verify with the version command before building any unit. The safest hosts are an x86_64 Linux machine with Wine, a Windows x86 VM, or an Intel Mac.

## Installation outline (not yet performed here)

1. Choose a host that can execute 32-bit Windows x86: x86_64 Linux with Wine (recommended), a Windows x86 VM, or a verified 32-bit-capable Wine/CrossOver build. On Apple Silicon, test this before installing the compiler.
2. Create an isolated 32-bit prefix, for example `WINEPREFIX="$HOME/.wine-vc71" WINEARCH=win32 winecfg` (or the equivalent for the host's WoW64 setup).
3. Obtain the Visual C++ Toolkit 2003 from Microsoft's archived download. Install it inside the prefix (`wine VCToolkitSetup.exe`) or copy its `bin`, `include`, and `lib` trees into the prefix.
4. Make the compiler and libraries visible to `cl`:
   - `PATH` includes `...\VC71\bin`;
   - `INCLUDE` includes `...\VC71\include`;
   - `LIB` includes `...\VC71\lib`.
   A wrapper script is the reliable form: set `PATH`, `INCLUDE`, `LIB`, then `exec wine cl "$@"`.
5. Point `build/units.json` at the wrapper in `compiler.compile_argv` (for example `["tools/wine-cl.sh"]` plus the flag placeholders) or set the wrapper as `wine cl` on `PATH`.
6. Verify the versions with the commands above, then compile the first unit.

## First-unit acceptance test

Do not start with a large function. The first unit must prove the whole chain:

- a real address from `build/functions.json`;
- a source file and a declared symbol;
- a COFF object produced by `cl` 13.10.3077;
- a PASS from `tools/match.py compare` for every declared function;
- a negative control: change one image byte and confirm the same unit fails.

Only after that should `src/` grow beyond one file.

## Known failure modes

- **Wine cannot run 32-bit `cl`.** Use a WoW64-capable Wine build or a 32-bit prefix under Rosetta/on x86_64.
- **Missing headers or libs.** Toolkit 2003 is a command-line toolset; it does not include MFC/ATL. The game imports `msvcr71.dll`/`msvcp71.dll`, so start with `/MD` (dynamic CRT) and the plain C/C++ runtime, and add only the headers a unit needs. `/MT` is a variant to test, not the default.
- **Wine paths.** `cl` cannot open `/Users/...` or temp paths inside the prefix. Set `path_style: "wine"` in the unit or compiler config; the harness converts `{src}`/`{obj}` with `winepath -w` (falling back to `Z:\...`). A `wine` wrapper as the first argv element enables this automatically.
- **Different code generation.** A wrong build or Service Pack changes instruction selection. Fix the toolchain before debugging source.
- **Path/timestamp inputs.** The harness compares bytes, not object metadata; absolute source paths do not affect code unless a unit embeds `__FILE__`. Avoid `__FILE__`, `__DATE__`, and `__TIME__` in matched code.
- **Host architecture.** The compiler must target x86 (`/arch:IA32` or the default for the 32-bit toolset), not x64.

## Status

Not installed on this machine as of 2026-11-08: `wine` and `cl` are absent, and the host is Apple Silicon, where 32-bit x86 execution is not assumed. The harness is validated with a fixture compiler only. Installing the exact toolset on a capable host is the current blocker and the next action.
