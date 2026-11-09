# Wine/WoW64 probe — CLI `cl.exe` feasibility on Apple Silicon (macOS 27 arm64)

Date: 2026-11-08. Host: macOS 27.0.1 arm64 (Apple M5 Pro, `uname -m` = `arm64`).
Scope: CLI-only. No GUI apps installed. No VC installer executed. No project
source modified.

## Verdict

**YES — a CLI-accessible Wine runtime runs a trivial i386 (PE32) console PE
on this host, observed.** Version banner: `wine-11.20-37-g2362fb0442`
(Mach9 arm64 Wine, FEX). A locally built `hello32.exe` (PE32 `IMAGE_FILE_MACHINE_I386`)
printed `hello from i386 PE` with exit 0. A banner-shaped sim (`clbanner.exe`,
same shape as `cl`'s banner but **not** `cl.exe`) printed the `13.10.3077`
wording and ran. `cl.exe` itself could **not** be run yet — `VCToolkitSetup.exe`
was not executed per assignment; its payload remains the opaque InstallShield
blob from the toolchain probe. Whether the real installer would succeed under
this runtime is **not** established.

## Local baseline (before any install)

- `wine` / `wine64` / `wineserver`: **not on PATH**; `bash: wine: command not found`
  (exit 127). No `/Applications/*[Ww]ine*`, no `/opt/homebrew/cellar/wine*`,
  no CrossOver.
- mingw available: `i686-w64-mingw32-gcc` + `x86_64-w64-mingw32-gcc` (GCC 16.2.0).
- Target PE confirmed PE32 i386: `experiments/2026-11-08-target-identification/output/extracted/app/Pirates!.exe`
  — `file`: `PE32 executable (GUI) Intel 80386`; header `Machine: 014C (i386)`,
  linker version `7.10`, 4 sections, timestamp 2007-02-16. i.e. the shipped
  32-bit `cl`/`link` generation could, in principle, run through an i386-
  capable Wine layer.
- `VCToolkitSetup.exe` (SHA-256 `03aad135…045f`) present at `/tmp/pirates-toolchain/`
  but **not** executed (per assignment).

## Candidates investigated (public docs/releases)

### 1. Apple-Silicon WoW64 Wine forks (Rosetta x86_64 route)

- `athei/wine-build` (`https://github.com/athei/wine-build`): builds an **x86_64**
  WoW64 Wine (i386+x86_64) from CrossOver Wine, run under **Rosetta 2**
  (no native arm64). Now superseded in-repo by `athei/mach9` (same author):
  `https://github.com/athei/mach9` ("Play Windows games fast on Apple silicon
  Macs. Wine built in"). The repo redirect content now describes Mach9:
  "Wine is built for arm64 and runs without Rosetta. FEX runs the x86 code."
  `https://github.com/metalsharp/MetalSharp-Wine/blob/main/docs/STATUS.md` table:
  `Build | Wine 11.20 builds as native arm64 macOS (minimum 15.0), with PE
  archs arm64ec/aarch64/i386 and every requested feature`; `x86_64 Windows
  code | Runs through FEX-2610 (fork, ARM64EC)`.
- Porthole (`https://github.com/Bockit/porthole`, Bockit, 0 stars):
  builds CrossOver 26 (Wine 11.0) **as x86_64** under Rosetta, configures
  `--enable-archs=i386,x86_64` (WoW64 for 32-bit games), runs via
  `run_wine.sh`. README: "Currently targets 32-bit Windows games like
  Civilization IV: Beyond the Sword." Requires CrossOver 26.0.0 source tarball
  extracted to `sources/wine/` (not a plain CLI binary download) plus an
  isolated x86_64 Homebrew prefix. **Not downloaded/built here** (build-from-source).

### 2. MetalSharp 1.0.0 arm64-FEX (`metalsharp/MetalSharp`, tag `v1.0.0`)

- Release page `https://github.com/metalsharp/MetalSharp/releases/tag/v1.0.0`:
  two builds — **Arm64 FEX** (`MetalSharp-1.0.0-arm64-FEX.dmg`, 1,507,273,337
  bytes, macOS 26.4+, native Wine + FEX) and x86_64 (`MetalSharp-1.0.0-arm64.dmg`,
  Rosetta). Host macOS 27.0.1 satisfies the 26.4+ floor. License/signing:
  "Signed with a Developer ID, hardened runtime, notarized."
- MetalSharp Wine 4.0 (`https://github.com/metalsharp/MetalSharp-Wine/releases/tag/v4.0`):
  `metalsharp-wine-4.0-arm64.tar.xz` (954,950,572 bytes, SHA-256
  `88ab68b5…786f65`) and zip variant. SHA256SUMS file fetched directly.
- MetalSharp is a **GUI DMG app** (GPUI app, drag to /Applications). The
  runtime tarball exists, but it is ~955 MB and was **not** downloaded for
  this probe (Mach9 gave a smaller CLI tarball, 129 MB). Metadata only.

### 3. CrossOver (CodeWeavers)

Commercial GUI app; no CLI tarball. Porthole/athei both build from *CrossOver
Wine source* (open-source tree), not the commercial app. Not installed here.

## Observed attempts (Mach9 bundle — the CLI path)

Downloaded the Mach9 **CLI tarball** (not the DMG app):

- URL: `https://github.com/athei/mach9/releases/download/v0.2.0/wine-v0.2.0-macos-arm64.tar.xz`
  (GitHub release `v0.2.0`, asset `wine-v0.2.0-macos-arm64.tar.xz`, 129,197,644 bytes)
- SHA-256 (local `shasum -a 256`): `243bcc4523be6777e7b22fe3f30f92d9cdfbd3adbeb6e7371c15c7fc7f68a324`
- Extracted to `/tmp/pirates-wine-probe/mach9/wine/` — pure CLI tree
  (`bin/wine`, `bin/wineserver`, `bin/wineboot`, `lib/wine/…`). `file`:
  `wine` → `Mach-O 64-bit executable arm64` (symlink to
  `../lib/wine/aarch64-unix/wine.app/Contents/MacOS/wine`).

| Attempt | Command | Result |
|---|---|---|
| `wine --version` | `wine --version` (Mach9 bin) | `wine-11.20-37-g2362fb0442`, exit 0 |
| `wine --help` | `wine --help` | Usage banner, exit 0 |
| `WINEARCH=win32` prefix init | `WINEARCH=win32 wine wineboot --init` | `wine: WINEARCH is set to 'win32' but this is not supported in wow64 mode.`, exit 1 |
| WoW64 prefix init (no WINEARCH) | `WINEPREFIX=/tmp/pirates-wine-probe/prefix2 wine wineboot --init` | created config dir, exit 0; `drive_c/{Program Files,Program Files (x86),windows,…}` populated |
| Trivial i386 PE | `wine …/experiments/2026-11-08-toolchain/wine-probe/hello32.exe` | `compatdb: hello32.exe [i386]`; stdout `hello from i386 PE`; exit 0 |
| Banner-shape sim PE | `wine …/wine-probe/clbanner.exe` | `Microsoft (R) 32-Bit C/C++ Optimizing Compiler Version 13.10.3077 for 80x86` + argv dump; exit 0 |
| Headers via `winedump` (native) | `/tmp/…/bin/winedump Pirates!.exe` | `Machine: 014C (i386)`, `32BIT_MACHINE`, exit 0 |
| Headers via `wine winedump` | `wine winedump Pirates!.exe` | `Application could not be started… ShellExecuteEx failed: File not found.` (start.exe needs GUI association; use native `winedump` — not a runtime failure) |

`hello32.exe`: built with `i686-w64-mingw32-gcc` from `hello32.c` (`printf`
only). `file`: `PE32 executable (console) Intel 80386`. SHA-256
`8d938c3599b2c5ef79fb5afbfdea6ee135ee2c23d16dbffaf7696e0b3cb16328`,
126,547 bytes. `clbanner.exe` SHA-256
`47c9365a9198f93d874c5981083658b1515b20624e5d3515ba4994dc2f342645`.

Prefix notes: Mach9 sets `FEX_X87REDUCEDPRECISION=1` by default; compatdb
defaults (`d3d9=mtld3d`, `dxgi=dxmt`, `dpi_aware=true`, `force_nx=true`,
`opengl=egl`) are all printed per process (prefixed `compatdb:`). Non-fatal
noise: `ZwLoadDriver … winebth: c00000e5`, `set_native_thread_name` fixme,
actctx fixme. None blocked console PE execution.

## Can `cl.exe` be run?

**Not yet observed. Do not claim it.** The runtime demonstrably executes an
i386 console PE and a banner-shaped program with the right version string,
but:

1. `VCToolkitSetup.exe` was **not executed** (assignment). Its InstallShield
   payload is opaque to generic extraction (toolchain probe), so no
   `cl.exe`/`link.exe` was observed to place in the prefix.
2. If the installer payload could be extracted, the next gate would be
   running `wine cl` / `wine link` and confirming `13.10.3077` / `7.10.3077`
   banners — **not yet done**.
3. `cl.exe` is a console PE, so it shares the `hello32.exe` shape that
   passes; the installer wrapper (InstallShield, likely GUI) is a different
   risk surface.

Alternative not tested: MetalSharp Wine 4.0 tarball (955 MB) — a second
arm64+FEX CLI runtime. If Mach9 hits an installer blocker, it is the next
candidate. DMGs (`MetalSharp-1.0.0-arm64-FEX.dmg`, `Mach9.dmg`) are GUI and
were not installed.

## Repro (CLI only)

```sh
curl -L -o /tmp/pirates-wine-probe/wine-mach9.tar.xz \
  https://github.com/athei/mach9/releases/download/v0.2.0/wine-v0.2.0-macos-arm64.tar.xz
shasum -a 256 /tmp/pirates-wine-probe/wine-mach9.tar.xz
# 243bcc4523be6777e7b22fe3f30f92d9cdfbd3adbeb6e7371c15c7fc7f68a324
tar -xJf /tmp/pirates-wine-probe/wine-mach9.tar.xz -C /tmp/pirates-wine-probe/mach9
export WINEPREFIX=/tmp/pirates-wine-probe/prefix2   # do NOT set WINEARCH=win32
/tmp/pirates-wine-probe/mach9/wine/bin/wine --version        # wine-11.20-37-g2362fb0442
/tmp/pirates-wine-probe/mach9/wine/bin/wine wineboot --init
/tmp/pirates-wine-probe/mach9/wine/bin/wine "$PWD/experiments/2026-11-08-toolchain/wine-probe/hello32.exe"
# hello from i386 PE
```

Notes directory: `experiments/2026-11-08-toolchain/wine-probe/` (this report's
supporting files: `hello32.c`, `hello32.exe`, `clbanner.c`, `clbanner.exe`,
`probe-log.txt` with full command output).
