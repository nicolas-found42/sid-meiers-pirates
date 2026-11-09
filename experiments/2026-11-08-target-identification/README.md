# sid-meiers-pirates-2026-11-08-target-identification: what is the shipped executable?

- Status: completed
- Target/build/platform/architecture: *Sid Meier's Pirates!* v1.0.2.0 build 30927, Windows x86-32, GOG "Live the Life" installer
- Canonical input: `../../../../games/raw/pirates.exe`, 792,859,072 bytes, SHA-256 `8851023b95f10b37d5fd8d9cd2ba5d68094e92f0526a0e6eb27adc350b4d8e54`
- Question: which executable is inside the installer, which toolchain and engine produced it, and what function inventory must a matching build reproduce?
- Expected observation: a PE32 x86 image with a readable version resource, a CodeView PDB record, Rich-header build numbers, a Gamebryo version string, and a function inventory with addresses.
- Tool/provider/version: innoextract 1.9; REA with Ghidra 12.2; Python 3.15
- Working directory: project root `games/sid-meiers-pirates`
- Limits: no full asset extraction (about 900 MiB); output only the executable and immediate runtime files; no external downloads
- Output location: `output/extracted/app/`, `build/functions.json`, ignored `analysis/rea-pirates-bundle.json`

## Commands

```sh
# Inventory the installer and extract only the application files.
innoextract --list ../../../../games/raw/pirates.exe
innoextract -q -d output/extracted \
  -I 'app/Pirates!.exe' -I 'app/readme.htm' \
  -I 'app/msvcr71.dll' -I 'app/msvcp71.dll' \
  -I 'app/binkw32.dll' -I 'app/Mss32.dll' \
  ../../../../games/raw/pirates.exe

EXE='output/extracted/app/Pirates!.exe'
python3 tools/pe.py info "$EXE" --json
python3 tools/pe.py debug "$EXE" --json
python3 tools/pe.py version "$EXE" --json
python3 tools/pe.py rich "$EXE" --json
python3 tools/pe.py imports "$EXE" --json

# REA: open the image, list procedures, export the evidence bundle, then:
python3 tools/build_inventory.py \
  --bundle analysis/rea-pirates-bundle.json \
  --image "$EXE" --out build/functions.json --stats
```

The extraction was reproduced into `/tmp` and all six files matched the hashes in the table below.

## Observations and evidence

- The installer is an Inno Setup package titled "Sid Meier's Pirates! - Live the Life", setup data 5.5.0 (unicode), with 1,473 entries. The archive includes about 808 MiB of `Assets/Pak*.FPK`, four Bink movies, and GOG wrapper files; none were extracted.
- `Pirates!.exe` is 3,323,288 bytes, SHA-256 `6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9`, PE32 i386 GUI, image base `0x400000`, entry `0x5f09ac`.
- Version resource: file/product 1.0.2.0, build 30927, Firaxis Games.
- CodeView: `d:\projects\archive\PiratesPC\Pirates\Release\Pirates!.pdb`, GUID `1f2eb43b-699e-4f99-b761-08b9a02f75cf`, age 5. The PDB is not shipped.
- Linker 7.10; Rich header dominated by build 3077 (Visual C++ .NET 2003 RTM). PE timestamp 2007-02-16.
- Imports: dynamic VC7.1 CRT (`msvcr71` 113, `msvcp71` 5), Miles `mss32` 71, Bink 10, Win32, OLE/ATL; no `d3d9.dll` or `dinput8.dll` import (D3D9 is loaded dynamically).
- Engine strings: Gamebryo 10.1.0.0 for NiMain, NiAnimation, NiCollision, NiDX9; NIF/KFM; only four standard `.?AV` RTTI strings, so no class RTTI names.
- Ghidra 12.2 inventory: 8,522 rows, 341 external, 8,181 internal, 8,099 placeholders, 140 thunks, 179 EH funclets (12 `Catch@` + 167 `Unwind@`), 7,862 matchable source functions, 2,879,488 bytes of `.text`, median span 128 bytes.

Evidence paths:

- `output/extracted/app/Pirates!.exe` (and the five runtime files)
- `build/functions.json` (committed inventory)
- `analysis/rea-pirates-bundle.json` (ignored, 12 records)
- [findings/2026-11-08-target-identification.md](../../findings/2026-11-08-target-identification.md)

## Conclusion and limits

The target is a Gamebryo 10.1.0.0 game built with the VC7.1 RTM toolchain, with a dynamic CRT and almost no symbol information. The function inventory is complete enough to start matching (8,181 internal functions) but spans are next-entry deltas, not exact body lengths.

Open alternatives: the GOG executable may differ from a retail CD 1.0.2.0 build; the exact per-unit compiler flags are unknown; no public PDB or decompilation source was found in the reviewed search. A retail-vs-GOG byte comparison is not possible without a retail copy.

## Review gate

A `jev_gate` run on the harness diff returned **6 claims verified, 0 contradicted, 0 unsupported**, with 3 low-confidence claim flags. Composite `0.7125`, `safe_to_apply` `0.56`; the overall `escalate` was driven by test-gap confidence, not a contradiction. No game function had been matched at that point.

## Retention

Keep: the six extracted files, `build/functions.json`, the ignored REA bundle, and this record. Do not extract the ~900 MiB of assets without a storage decision. A 242,688-byte installer prefix left by an earlier probe was deleted; it was not needed for identity and is regenerable with `head -c` from the canonical installer. `output/` currently holds 4,883,196 bytes.

## First unit candidate

`0x497420` (`FUN_00497420`) is a one-byte function: the image contains `c3` followed by `cc` padding, and Ghidra reports a single `RET` body with 30 direct callers. A C++ empty function is the plausible source, so this is the first unit to try once the compiler is available:

```cpp
void FUN_00497420() {}
```

The inventory span is 16 bytes; the matcher trims the `0xCC` padding and compares the single `RET`. This candidate is documented, not claimed: `build/units.json` stays empty until `cl` 13.10.3077 produces a PASS and the negative control fails as expected. It is a trivial function and does not represent the harder game/engine units.

## Next action

Install `cl` 13.10.3077 / `link` 7.10.3077 on a 32-bit-capable host (x86_64 Linux with Wine, a Windows x86 VM, or a verified Wine build), verify the versions, then create the first unit. See [docs/TOOLCHAIN.md](../../docs/TOOLCHAIN.md).
