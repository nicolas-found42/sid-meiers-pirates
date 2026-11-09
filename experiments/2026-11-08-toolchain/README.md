# Toolchain acquisition experiment — 2026-11-08

Question: can the free **Visual C++ Toolkit 2003** (`cl 13.10.3077` /
`link 7.10.3077`) be obtained and inspected on this host (macOS 27,
arm64, no Wine currently), and can 32-bit `cl.exe` execute here?

Scope: local feasibility only. No system installs, no GUI installers,
no license bypass, no untrusted installer execution. No project source
or system configuration modified; only this directory and
`findings/2026-11-08-toolchain-acquisition.md` were written.

## Verified (observed, not inferred)

- Archive download succeeded (HTTP 200) from Internet Archive item
  `microsoft-visual-c-toolkit-2003`:
  - URL fetched: `https://ia903202.us.archive.org/26/items/microsoft-visual-c-toolkit-2003/VCToolkitSetup.exe`
    (redirect target of `https://archive.org/download/microsoft-visual-c-toolkit-2003/VCToolkitSetup.exe`).
  - Size: **32,952,488 bytes**.
  - SHA-256: `03aad135c22e953e0928b118705338afdbd08abf8e4039038ef77945504e65fa`
  - MD5: `3e1e1cad2e4b4e2427dbe4616cccaa02` (matches archive.org `files`
    metadata for the same item/file; full MD5 computed locally).
  - PE32, machine `0x14c` (IMAGE_FILE_MACHINE_I386), 4 sections — the
- Installer format:
  - `innoextract -t VCToolkitSetup.exe` → `Not a supported Inno Setup
    installer!` (typed I386 stub, not Inno Setup).
  - The stub is an **InstallShield 7 wrapper**. 7-Zip extracts 21 files;
    `setup/[0]` is a single opaque **~31 MB** blob starting with
    `InstallShield`. No `Data.Cab` / `MSCF` container was detected, and the
    extracted set contains no `cl.exe` / `link.exe` / `msvcrt.lib` etc.
    A round-trip extraction of `setup/[0]` is byte-identical, so the
    extraction itself is reliable — the payload inside stays opaque to
    generic tools.
  - Consequence: the contained compiler tree is not recoverable by
    listing/extracting `setup/[0]` with generic tools alone; no `cl.exe`
    or `link.exe` was observed, and no version resource could be read
    from a tool binary — because none was reached.
  `/tmp/pirates-toolchain/VCToolkitSetup.exe` with the same hash. One
  shared copy is sufficient; this report quotes the hash, not a path.
- Installer format:
  - `innoextract -t VCToolkitSetup.exe` → `Not a supported Inno Setup
    installer!` (typed I386 stub, not Inno Setup).
  - 7-Zip extracts a single opaque **`setup/[0]`** member (~31 MB) with
    **no `Data.Cab` / `MSCF` container detected**. That member is not
    directly `cl.exe`/`link.exe`/`msvcrt.lib` etc.
  - Consequence: the contained compiler tree is not recoverable by
    listing/extracting `setup/[0]` with generic tools alone; no `cl.exe`
    or `link.exe` was observed, and no version resource could be read
    from a tool binary — because none was reached.
- `cl` availability on this host (observed 2026-11-08):
  - No `wine` / `wine64` / `wineserver` on `PATH`; no CrossOver app.
  - No `cl.exe` observed in any extracted payload.
- Microsoft direct links probed 2026-11-08 (all **HTTP 404**):
  - `download.microsoft.com/.../VCToolkitSetup.exe` (two legacy GUID
    paths),
  - `learn.microsoft.com/archive/blogs/...` (Toolkit announcement +
    author archive index).
  Microsoft no longer serves this download directly; archive.org is the
  practical source found.
- Archive metadata observed:
  - Item `microsoft-visual-c-toolkit-2003`: `VCToolkitSetup.exe`
    32,952,488 bytes, creator `Microsoft`, date 2004-04-14 on the item.
  - Item `20260623_202606` describes itself as
    `Microsoft Visual C++ Toolkit 2003 1.01.0000` and says it
    `Contains compiler version 13.10.3077`.
  - Item `vc-toolkit-2003-setup` holds a 32,948,392-byte
    `VC_Toolkit_2003_Setup.exe` (near-identical size, different hash).
  - Item descriptions state the installer does not work on later
    Windows, but 7-Zip can unpack it and `PATH`/`LIB`/`INCLUDE` can be
    set manually — consistent with the `setup/[0]` observation above.

## Not verified / explicitly not claimed

- Whether `setup/[0]` is a Microsoft Cabinet/InstallShield/compressed
  payload with a known unpacker path. **Not established in this pass.**
- Whether `cl.exe` in this package reports `13.10.3077` or the
  `13.10.3052` variant reported for some Toolkit releases. **No tool
  binary was obtained, so no version string was observed.**
- Licensing: archive.org redistributes a Microsoft freeware-era
  installer for preservation; no EULA was read (it is inside the opaque
  payload). No license bypass was attempted.

## Can 32-bit `cl.exe` run on this host?

**No — not via any currently installed path. Verdict: NO on this host as
configured; MAYBE only on a different host.**

- Rosetta 2 for macOS translates **x86_64 → arm64**, not i386 → arm64.
  A PE32 `cl.exe` needs translation of 32-bit x86 code; Rosetta alone
  does not provide that. (Observed: Rosetta runtime libraries present in
  the OS, but no translation path for i386 PE was confirmed.)
- Wine on Apple Silicon needs a WoW64 build (i386 PE support via Wine's
  new WoW64 layer, which upstream still marks
  `EXPERIMENTAL`/`not yet fully supported` as of Wine 10-era
  announcements). Third-party macOS-arm64 Wine forks (e.g.
  Apple-Silicon ports building native arm64 Wine with i386 PE support)
  exist but were **not tested, not installed, and are not assumed**.
- No Wine, CrossOver, VM, or other x86 execution layer is installed on
  this machine today, so there is no local path that could run
  `cl.exe` — this is a fact about the current host, not a claim that no
  future Apple-Silicon WoW64 build can ever do it.

## Concrete next steps (safe, in order)

1. On a **capable host** (x86_64 Linux with Wine, or a Windows x86 VM),
   copy `VCToolkitSetup.exe` by hash (`03aad135…045f` above), run the
   installer inside an isolated 32-bit prefix, and run:
   `wine cl 2>&1 | head -2` — accept only `13.10.3077`; also verify
   `link 7.10.3077`. Until then, **`cl 13.10.3077` is not available**
   anywhere in this project.
2. If staying on Apple Silicon, the only honest path is a WoW64-capable
   Apple-Silicon Wine build; **test it first** with a trivial 32-bit
   PE's version banner before installing anything, and treat it as an
   experiment (upstream WoW64 status is experimental). The alternative
   is obtaining a **pre-extracted Toolkit tree** (`bin`/`include`/`lib`
   with `cl.exe` present) from a trusted source.
3. Before any build claim, follow `docs/TOOLCHAIN.md`: isolated
   `WINEPREFIX`/`WINEARCH=win32`, manual `PATH`/`INCLUDE`/`LIB`, first
   positive fixture + negative control.

Commands used for verification (safe, no execution of `VCToolkitSetup.exe`):

```sh
curl -sI https://archive.org/download/microsoft-visual-c-toolkit-2003/VCToolkitSetup.exe
curl -L -o VCToolkitSetup.exe https://ia903202.us.archive.org/26/items/microsoft-visual-c-toolkit-2003/VCToolkitSetup.exe
shasum -a 256 VCToolkitSetup.exe   # 03aad135c22e...045f
md5 VCToolkitSetup.exe             # 3e1e1cad2e4b4e2427dbe4616cccaa02
innoextract -t VCToolkitSetup.exe  # Not a supported Inno Setup installer!
```

## Blocker update (2026-11-09) — the compiler now runs

The blocker recorded above is superseded. The InstallShield
`VCToolkitSetup.exe` payload is **not** required: archive.org item
`visual-studio-2003-unpacked` publishes a pre-unpacked VS 2003 tree
(`VisualStudio2003.zip`, 452,825,140 bytes, MD5 `d042ad27f42814691dedde8613b24f8d`),
whose central directory can be read over HTTP `Range` requests without
downloading the archive. Extracting `Vc7/bin`, `Vc7/include`, `Vc7/lib` and
staging `mspdb71.dll` + `msvcr71.dll`/`msvcp71.dll` beside `cl.exe` gives a
working toolchain under the Mach9 Wine runtime already used in the probe:

- `cl` → `Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3077 for 80x86`
- `link` → `Incremental Linker Version 7.10.3077`
- `cl /c` on `int main(void){return 0;}` → valid i386 COFF `t.obj`
- `link` → PE32 i386 `t.exe` (3,584 bytes), runs, exit 0

Key step the earlier pass missed: `cl.exe` hard-imports `mspdb71.dll`; without
it the loader fails with `status c0000135`. `WINEPREFIX` is the existing
`/tmp/pirates-wine-probe/prefix2`; no .NET/registry prerequisite is needed.

Details, hashes and the reproducible command list:
`findings/2026-11-08-compiler-availability.md`. Payloads stay in `/tmp`
(`/tmp/compiler-research/`), not in this repo. Byte matching is now proven
for three shipped functions (`tiny_547610`, `tiny_54a9f0`, `tiny_5366b0`); see
`findings/2026-11-08-first-match.md`.
