# Toolchain acquisition — Visual C++ Toolkit 2003 (cl 13.10.3077)

Date: 2026-11-08. Host: macOS 27.0.1 arm64 (Apple M5 Pro). Question: can the
free Visual C++ Toolkit 2003 (`cl 13.10.3077` / `link 7.10.3077`) be obtained
and run locally? Answer: **obtained and hash-verified, but not runnable on
this host** — no `cl`/`link` was extracted and no Wine is installed. Full
detail: `experiments/2026-11-08-toolchain/README.md`.

## Observed (verified)

| Item | Value |
|---|---|
| archive.org item | `microsoft-visual-c-toolkit-2003` |
| download URL | `https://archive.org/download/microsoft-visual-c-toolkit-2003/VCToolkitSetup.exe` (redirects to `https://dn721804.ca.archive.org/0/items/microsoft-visual-c-toolkit-2003/VCToolkitSetup.exe`; direct: `https://ia903202.us.archive.org/26/items/microsoft-visual-c-toolkit-2003/VCToolkitSetup.exe`) |
| size | 32,952,488 bytes |
| SHA-256 | `03aad135c22e953e0928b118705338afdbd08abf8e4039038ef77945504e65fa` |
| MD5 | `3e1e1cad2e4b4e2427dbe4616cccaa02` |
| stub | PE32, `IMAGE_FILE_MACHINE_I386` (0x14c), 4 sections; InstallShield 7 wrapper |
| 7-Zip extraction | 21 files; `setup/[0]` is an opaque ~31 MB blob starting with `InstallShield`; no `Data.Cab`/`MSCF`, no `cl.exe`, no `link.exe` in the extracted set |
| 7-Zip round-trip | `setup/[0]` extracts byte-for-byte to a second copy; extraction is reliable, contents remain opaque |
| Inno extraction | `innoextract -t VCToolkitSetup.exe` → `Not a supported Inno Setup installer!` (correct: InstallShield, not Inno) |
| Microsoft direct links | 404: legacy `download.microsoft.com/.../VCToolkitSetup.exe` GUID paths and `learn.microsoft.com/archive/blogs/...` Toolkit announcement all returned HTTP 404 |
| local `cl` | **none** — no `cl.exe`/`link.exe` observed anywhere; no `wine`/`wine64`/`wineserver` on PATH; no CrossOver |
| Rosetta | Rosetta 2 translates x86_64→arm64, not i386→arm64; no local path executes PE32 i386 |
| excluded alternatives | archive items in this family differ by file and MD5 (e.g. item `vc-toolkit-2003-setup` holds a 32,948,392-byte `VC_Toolkit_2003_Setup.exe`); none was substituted for the hash-verified file above |
| version claim | **unverified**: `cl 13.10.3077` was NOT observed anywhere in this pass — no compiler binary was obtained to read a version resource from. Item `20260623_202606` *describes* itself as containing `13.10.3077`, but that is an item description, not an observed version string |

## Update: i386 Wine works, installer still blocks

Later on 2026-11-08, Mach9 (arm64 Wine + FEX, `wine-11.20-37-g2362fb0442`)
was downloaded to `/tmp/pirates-wine-probe/mach9/` and executed a locally
built i386 PE (`hello32.exe`) successfully. See
`findings/2026-11-08-wine-probe.md` for the observed commands and hashes.

`VCToolkitSetup.exe` was then run under that runtime. It immediately launched
`dotnetfx.exe /q:a /ver:v1.1.4322 ...` (the .NET Framework 1.1 prerequisite)
and did not reach the toolkit payload; silent `/s` also returned 1645 after
launching the prerequisite. The installer's `setup/[0]` payload is an
InstallShield container beginning `InstallShield\0\x06`; `unshield` 1.6.2,
`7z`, `cabextract`, and `binwalk` do not parse it, and it contains no `MSCF`
or `ISc(` signature. Extracting or completing the .NET 1.1 prerequisite is a
side quest, so `cl 13.10.3077` remains blocked. Kill the Wine tree if an
attempt is left running (`pkill -f VCToolkitSetup.exe`).

## Verdict

**Can 32-bit `cl.exe` run on this host? Not yet.** A 32-bit PE runtime now
exists (Mach9 Wine/FEX), but no `cl.exe` was extracted or installed. Third-party Apple-Silicon WoW64 Wine builds exist
upstream (still marked experimental); Mach9 is one and it does run i386
console PEs. The remaining blocker is the InstallShield/.NET 1.1 installer,
not PE execution. The archive is safe to keep by hash.

## Next safe step (exact)

On a capable host (x86_64 Linux with Wine, or a Windows x86 VM), copy
`VCToolkitSetup.exe` by SHA-256 `03aad135…045f`, run the installer inside an
isolated 32-bit prefix (`WINEPREFIX=… WINEARCH=win32`), then verify:

```sh
wine cl 2>&1 | head -2     # must read 13.10.3077
wine link 2>&1 | head -2   # must read 7.10.3077
```

If staying on Apple Silicon, first prove a WoW64-capable Wine build runs a
trivial 32-bit PE version banner before installing anything, or obtain a
pre-extracted Toolkit tree (`bin`/`include`/`lib` with `cl.exe`/`link.exe`
present) from a trusted source. Only after the two version banners read
`13.10.3077`/`7.10.3077` does `build/units.json` point at the wrapper per
`docs/TOOLCHAIN.md`. No byte-match claim is possible until then.
