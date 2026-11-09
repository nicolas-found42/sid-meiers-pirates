# Compiler availability — VC7.1 (`cl` 13.10.3077) on macOS arm64

Date: 2026-11-08/09. Host: macOS 27 arm64 (Apple M5 Pro). Question: can
Visual C++ .NET 2003 (`cl` 13.10.3077, `link` 7.10.3077, PE32 i386) be
obtained and **run** on this host, without another machine?

## Verdict

**YES — obtained, extracted, and executed on this host.** `cl` 13.10.3077
compiled a trivial C file to an i386 COFF object, `link` 7.10.3077 linked it
to a PE32 i386 console executable, and that executable ran (exit 0) under the
Mach9 arm64 Wine + FEX runtime already installed at
`/tmp/pirates-wine-probe/mach9/`.

No installer was run. The toolchain came out of a *pre-extracted unpacked VS
2003 tree* posted on archive.org, read directly out of the ZIP over HTTPS
Range requests (central-directory parse). The earlier conclusion that the
InstallShield `VCToolkitSetup.exe` payload was the only source was **wrong /
superseded**: a second, unpacked archive item exposes the same shipped
`Vc7` tree as plain files.

Only 13.10.3077 is relevant here; no 13.10.3052 build was observed. The
Toolkit installer (`VCToolkitSetup.exe`, `03aad135…`) was **not** needed.

## Primary source (archive.org item + file)

- Item: `visual-studio-2003-unpacked` — *"Visual Studio Enterprise Architect
  2003 unpacked"*, uploader `neozeed@gmail.com`, added 2022-12-05.
  <https://archive.org/details/visual-studio-2003-unpacked>
- Metadata API: <https://archive.org/metadata/visual-studio-2003-unpacked>
- File used: `VisualStudio2003.zip`
  - canonical URL: `https://archive.org/download/visual-studio-2003-unpacked/VisualStudio2003.zip`
  - direct host: `https://ia801406.us.archive.org/2/items/visual-studio-2003-unpacked/VisualStudio2003.zip`
  - size: **452,825,140 bytes**
  - archive.org MD5: `d042ad27f42814691dedde8613b24f8d`
  - archive.org SHA-1: `298398e607a8e6033abe261987b94cab8fb57c24`
- Item also holds `MSDN-2003.zip` (1,834,144,971 B), `PreRequisites.zip`
  (159,393,623 B), `VisualStudio2003-sp1.zip` (162,527,745 B),
  `dotnet11-with_sp1.zip` (35,386,509 B), `Windows10-Patches.zip`
  (921,014 B) — all MD5s in the metadata API above.
- `VisualStudio2003-sp1.zip` central directory holds exactly one payload,
  `VisualStudio2003-sp1/VS7.1sp1-KB918007-X86.exe` — the **SP1 update only**,
  not a fresh compiler tree; not used here.

Second, independent copy of the same full installer payload (ISOs, not a
tree): item `vsnet2003` (`MSDN Visual Studio .NET 2003 - Enterprise
Architect (Disc 1/2/Prereqs).ISO`, 668,143,616 / 473,169,920 / 169,734,144 B).
Not needed.

## Extraction method (no installer, no full download)

The ZIP's central directory is far from the start of a 452 MB file, but
archive.org supports byte ranges, so only ~8 MB of tail + ~4 MB of directory
+ the individual member ranges were fetched.

1. `HEAD` → `Content-Length: 452825140`.
2. `Range: bytes=<len-8000000>-<len-1>` → tail; find `PK\x05\x06`; unpack
   `<IHHHHIIH` → `nrec=21314`, `cdsize=3930967`, `cdoff=448894151`.
3. `Range: bytes=448894151-4490nnnnn` → central directory (3,930,967 B).
4. Parse 21,314 `PK\x01\x02` headers → 4,887 `Vc7/…` entries, including the
   full `Vc7/bin` (27 files), `Vc7/include` (157 files) and `Vc7/lib` (46
   files) trees.
5. For each wanted member: `Range` read of its 30-byte local header
   (`<IHHHHHIIIHH` → method/csize/usz/crc/nlen/xlen), then
   `Range: bytes=<data_start>-<data_start+csize-1>` for the deflate stream,
   `zlib.decompress(raw, -15)`. Every member was validated against its CRC-32
   and uncompressed size; all matched.

Reconstructed toolchain tree: **`/tmp/compiler-research/vc71tree/`**
(`lib/` + `include/`, 200 files, ~37 MB uncompressed).
Staging dir with the executed binaries: **`/tmp/compiler-research/stage/`**.
Everything lives in `/tmp`; **no installer payload was copied into the repo.**

## Binaries and hashes (SHA-256, computed locally after CRC-verified extraction)

| File | Size | SHA-256 |
|---|---|---|
| `cl.exe` | 86,016 | `2ecf86a3edfd3deae498e08298e210e984537ce9e11759930561e43f40bd2515` |
| `link.exe` | 647,168 | `0d5f9712d0da843d787bf4ce4e678abc6b737940996706b2c86101eac9df3e3c` |
| `lib.exe` | 5,120 | `3892c55821f628961ebf177537fdb002f3423166ead89c3aa7bc2ea1419fe1eb` |
| `c1.dll` | 933,888 | `11f452af93f8e686b36b348763b33d32ae2766f1b0c360a447053bf44ec50fcc` |
| `c1xx.dll` | 2,207,744 | `353f3d5dcd050b876e1c044b99c4bf47958d255f395a4919f406a19921be4dfa` |
| `c2.dll` | 1,867,776 | `bcd28f39b1798b07989c30a1df471cf87fc20e3802d130901a08f83800e6b81e` |
| `mspdb71.dll` | 241,664 | `85ebd7dcbe1b9fa756f23e5f811d7dfeccdac0de14271f2c18affbf918d8cb79` |
| `msvcr71.dll` | 348,160 | `8094af5ee310714caebccaeee7769ffb08048503ba478b879edfef5f1a24fefe` |
| `msvcp71.dll` | 499,712 | `df96156f6a548fd6fe5672918de5ae4509d3c810a57bffd2a91de45a3ed5b23b` |
| `lib/msvcrt.lib` | 431,200 | `e888617fbd2e153645b92122deab1c6ec437905431243c43aa7310164c0e7779` |
| `lib/kernel32.lib` | 191,866 | `4c6f8667c02e990c496b1054429e01f3d7d1160323ac46b7771013ceaa4cb389` |
| `lib/libc.lib` | 2,707,332 | (fetched by background pass; see tree) |
| `lib/oldnames.lib` | 69,512 | `ace6ebf2ef319936a64b7e1a27f508a2c03c4838908f12e790b6c198845cc6cb` |
| `stage/t.exe` (built) | 3,584 | `5c0e7a68d41be50e77119752f50c33fbac803ed1537e9dfef487eb8e1e20e726` |
| `stage/t3.exe` (built) | 3,584 | — (`link` without `/NODEFAULTLIB`) |

Version resources read from the binaries themselves: `cl.exe` has
`FileVersion = 13.10.3077` (UTF-16 resource) and the ASCII string
`13.10.3077` at file offset 57,392; `link.exe` and `lib.exe` carry
`Version 7.10.3077`. PE headers: `Machine 014C (i386)`, `32BIT_MACHINE`,
subsystem `0x3 Windows CUI`, linker version `7.10`.

## Runtime

- Wine: Mach9 (arm64 Wine + FEX), `wine-11.20-37-g2362fb0442`, tree at
  `/tmp/pirates-wine-probe/mach9/wine/bin/wine` (from
  `https://github.com/athei/mach9/releases/download/v0.2.0/wine-v0.2.0-macos-arm64.tar.xz`,
  SHA-256 `243bcc4523be6777e7b22fe3f30f92d9cdfbd3adbeb6e7371c15c7fc7f68a324`).
- `WINEPREFIX=/tmp/pirates-wine-probe/prefix2` (WoW64 prefix; **do not** set
  `WINEARCH=win32` — this runtime rejects it).
- Required next-to-exe DLLs: `mspdb71.dll` (hard import of `cl.exe`/`link.exe`,
  delay-load `imagehlp`/`version` are optional), `msvcr71.dll`,
  `msvcp71.dll`; plus `c1.dll`/`c1xx.dll`/`c2.dll` for actual compilation.

### First failure and fix (exact)

Without the CRT/PDB DLLs staged:

```
err:module:import_dll Library mspdb71.dll (which is needed by L"Z:\\tmp\\compiler-research\\stage\\cl.exe") not found
err:module:loader_init Importing dlls for L"...cl.exe" failed, status c0000135
```

Fix: extract `mspdb71.dll` (from
`VisualStudio2003/Program Files/Microsoft Visual Studio .NET 2003/Common7/IDE/mspdb71.dll`),
`msvcr71.dll`/`msvcp71.dll` (from `VisualStudio2003/`) into the same
directory as `cl.exe`, or add them to `WINEPATH`. **No .NET Framework, no
registry import, no `wineboot` step beyond the existing prefix was needed.**

## Observed banners and build results (verbatim)

```
Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3077 for 80x86
Copyright (C) Microsoft Corporation 1984-2002. All rights reserved.

usage: cl [ option... ] filename... [ /link linkoption... ]
```

```
Microsoft (R) Incremental Linker Version 7.10.3077
Copyright (C) Microsoft Corporation.  All rights reserved.
```

```
Microsoft (R) Library Manager Version 7.10.3077
Copyright (C) Microsoft Corporation. All rights reserved.
```

Compile (`t.c` = `int main(void){return 0;}`):

```
wine cl.exe /c t.c /I/tmp/compiler-research/vc71tree/include   → exit 0
t.obj → "Intel 80386 COFF object file, not stripped, 3 sections, 11 symbols"
        (596 bytes with /O2, 498 bytes with default flags)
```

Link + run:

```
wine link.exe /OUT:t3.exe t.obj /LIBPATH:/tmp/compiler-research/vc71tree/lib \
     kernel32.lib msvcrt.lib oldnames.lib        → exit 0
  (warning LNK4098: defaultlib 'LIBC' conflicts with use of other libs —
   because libc.lib was not on LIBPATH at that moment; harmless, and gone
   once Vc7/lib is complete)
t3.exe → "PE32 executable (console) Intel 80386"; wine t3.exe → exit 0
```

Single-step build also verified: `cl t.c /I<inc> /link /LIBPATH:<lib>
kernel32.lib msvcrt.lib oldnames.lib` → exit 0, `t.exe` PE32 i386, runs.

Non-fatal noise observed in every run (none blocked anything):
`err:ntoskrnl:ZwLoadDriver … winebth: c00000e5`,
`fixme:service:scmdatabase_autostart_services`,
`fixme:thread:set_native_thread_name`.

## Decision table

| Route | Evidence (primary) | Status | Blocker / next safe command |
|---|---|---|---|
| Pre-extracted VS 2003 tree via Range/CD parse of `VisualStudio2003.zip` | archive.org item `visual-studio-2003-unpacked`, file MD5 `d042ad27…`; CRC-verified members; banners 13.10.3077 / 7.10.3077 | **WORKS on this host** | none — re-run the command list below |
| `VCToolkitSetup.exe` (InstallShield wrapper) | item `microsoft-visual-c-toolkit-2003`, SHA-256 `03aad135…045f`; `setup/[0]` opaque | **not needed / remains opaque** | unshield/7z/cabextract/binwalk found no MSCF/ISc payload; do not pursue |
| `vc-toolkit-2003-setup` (`VC_Toolkit_2003_Setup.exe`) | same family, MD5 `90d8b963ca196aa9855b2ca6c3174c14`, 32,948,392 B | unverified variant | would also need an installer run; not needed |
| VS 2003 full ISOs (`vsnet2003`, `visual-studio-2003`) | ISO9660 `CD001` present; `Visual Studio 2003.zip` = 3 ISOs | unnecessary | the unpacked ZIP already yields the tree |
| `VisualStudio2003-sp1.zip` | single member `VS7.1sp1-KB918007-X86.exe` | SP1 only, no compiler | no |
| Rosetta 2 alone | OS x86_64→arm64 translator | **not a path** for i386 PE | — |
| WineHQ AppDB / Bugzilla / wiki | bot-walled from this host (challenge HTML) | **no primary citation obtainable here** | cite via browser manually if needed; runtime behaviour above is observed directly |

## Reproducible command list (as executed)

```sh
# 1. runtime (already present here)
export WINEPREFIX=/tmp/pirates-wine-probe/prefix2       # WoW64 prefix, not WINEARCH=win32
WINE=/tmp/pirates-wine-probe/mach9/wine/bin/wine
$WINE --version                                        # wine-11.20-37-g2362fb0442

# 2. stage the toolchain (CRC-verified Range extraction, see method above)
#    cl.exe link.exe lib.exe c1.dll c1xx.dll c2.dll mspdb71.dll msvcr71.dll msvcp71.dll
#    → /tmp/compiler-research/stage/
#    Vc7/include + Vc7/lib → /tmp/compiler-research/vc71tree/

# 3. verify banners
cd /tmp/compiler-research/stage
$WINE cl.exe      # "Version 13.10.3077 for 80x86"
$WINE link.exe    # "Incremental Linker Version 7.10.3077"
$WINE lib.exe     # "Library Manager Version 7.10.3077"

# 4. compile
printf 'int main(void){return 0;}\n' > t.c
$WINE cl.exe /c t.c /I/tmp/compiler-research/vc71tree/include
file t.obj            # Intel 80386 COFF object file

# 5. link + run
$WINE link.exe /OUT:t.exe t.obj /LIBPATH:/tmp/compiler-research/vc71tree/lib \
      kernel32.lib msvcrt.lib oldnames.lib
file t.exe           # PE32 executable (console) Intel 80386
$WINE t.exe          # exit 0
```

## What still fails / is not established

- **Not established:** that this compiler reproduces *this project's* bytes.
  Only a positive fixture + negative control against `build/units.json` can
  show that; no matching run was performed here.
- `cl.exe` needs `mspdb71.dll` **at process start**; without it every
  invocation dies with `status c0000135`. It is present in the same archive
  tree (two copies) but is *not* in `Vc7/bin` by default — it must be staged.
- `link.exe` emits `LNK4098` if `libc.lib` is missing from `LIBPATH`; harmless
  but noisy. Complete `Vc7/lib` avoids it.
- WineHQ AppDB / Bugzilla / wiki could not be fetched from this host
  (anti-bot challenge), so the "known-good under Wine" claim rests on the
  direct observation recorded above rather than an AppDB report.
- Licensing: this is Microsoft's shipped VS 2003 tree redistributed by a
  third party on archive.org for preservation; no EULA was read and no
  license bypass was attempted. Keep it in `/tmp`, out of the repo.

## Effect on the recorded blocker

The blocker recorded in `experiments/2026-11-08-toolchain/README.md`
("no `cl.exe` was extracted; InstallShield payload opaque; compiler not
runnable on this host") is **materially wrong as of now**: the compiler is
extracted and runs. See the appended note in that README.
