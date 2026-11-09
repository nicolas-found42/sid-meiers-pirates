# Target identification

Date: 2026-11-08. All values below were read from the canonical installer or the extracted image with the commands in [PROJECT.md](../PROJECT.md); external claims are marked separately. Facts were checked against those outputs with `jev_verify` (8/8 supported).

## Input and extraction

The canonical input is a GOG Inno Setup installer, not a raw game directory:

- file: hub `games/raw/pirates.exe`
- size: 792,859,072 bytes
- SHA-256: `8851023b95f10b37d5fd8d9cd2ba5d68094e92f0526a0e6eb27adc350b4d8e54`
- `innoextract --version`: 1.9 (`innoextract 1.9` supports Inno Setup 1.2.10–6.0.5)
- installer title: "Sid Meier's Pirates! - Live the Life", Inno setup data version 5.5.0 (unicode)
- archive inventory: 1,473 entries

Only the executable and its immediate runtime files were extracted, to stay inside the experiment budget. The extraction was reproduced byte-for-byte:

```sh
innoextract -q -d /tmp/pirates-extract \
  -I 'app/Pirates!.exe' -I 'app/readme.htm' \
  -I 'app/msvcr71.dll' -I 'app/msvcp71.dll' \
  -I 'app/binkw32.dll' -I 'app/Mss32.dll' \
  games/raw/pirates.exe
```

| Extracted file | Size | SHA-256 |
|---|---:|---|
| `Pirates!.exe` | 3,323,288 | `6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9` |
| `msvcr71.dll` | 348,160 | `8094af5ee310714caebccaeee7769ffb08048503ba478b879edfef5f1a24fefe` |
| `msvcp71.dll` | 499,712 | `df96156f6a548fd6fe5672918de5ae4509d3c810a57bffd2a91de45a3ed5b23b` |
| `binkw32.dll` | 338,944 | `9864b04caa66645b0040bcf46995400beb11050bca106a7eb60d93cf708311ec` |
| `Mss32.dll` | 372,736 | `24ea6b88e5dbcf9488a1d4e4adbf5d13a6f7c90705608e9735ba1d2009e5eee3` |
| `readme.htm` | 356 | `949db08cdb3a4f9282207fbb0a9debac28dde67440c736f8a4ee041d3dd0abbb` |

Not extracted: `Assets/Pak0.FPK`–`Pak8.FPK` (about 808 MiB), four Bink movies (about 88 MiB), `Assets/lang0.FPK` (371 KiB), and GOG wrapper files (`goggame-1445250653.dll`, `.hashdb`, `.ico`, `.info`). The asset payload is outside the decompilation target and would exceed the per-experiment output bound; it remains in the installer.

The installer is a 2007-era GOG repack with Inno Setup metadata. The executable's version resource still reports the Firaxis 2004 product and build (below). Equivalence to a retail CD 1.0.2.0 build was not tested; the GOG wrapper files were not extracted and may have patched the executable.

## Executable identity

| Field | Value |
|---|---|
| Size | 3,323,288 bytes |
| SHA-256 | `6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9` |
| Machine / optional magic | `0x014c` (i386) / `0x010b` (PE32) |
| Subsystem | 2 (Windows GUI) |
| Image base | `0x00400000` |
| Entry point | `0x005f09ac` (RVA `0x001f09ac`) |
| `.text` | VA `0x401000`–`0x6c0000`, raw 2,879,488 bytes, virtual 2,878,602 |
| `.rdata` | VA `0x6c0000`, raw 356,352, virtual 355,750 |
| `.data` | VA `0x717000`, raw 69,632, virtual 1,929,744 |
| `.rsrc` | VA `0x8ef000`, raw 8,192, virtual 6,920 |
| Linker version | 7.10 |
| PE timestamp | 2007-02-16 22:13:27 UTC |
| File / product version | 1.0.2.0, build 30927 |
| Company / description | Firaxis Games / Sid Meier's Pirates! |

The `.data` virtual size is much larger than its raw size: roughly 1.86 MB of zero-initialized globals. Data layout and BSS initialization will matter once functions reference globals, and are not covered by the current code-only harness.

### Debug identity

```text
type 2 (CODEVIEW), kind RSDS
GUID 1f2eb43b-699e-4f99-b761-08b9a02f75cf, age 5
path d:\projects\archive\PiratesPC\Pirates\Release\Pirates!.pdb
```

The PDB is not shipped and was not found. The path is build-machine provenance, not a symbol source. Ghidra therefore starts from placeholders.

### Toolchain identity

The optional header records linker 7.10. The Rich header's dominant build is 3077; other entries include build 3052, 2179, 2067, 4035, 8444, 9178 and 9210. Build 3077 is Visual C++ .NET 2003 RTM: `cl` 13.10.3077 for 80x86 and `link` 7.10.3077. Visual C++ Toolkit 2003, a free distribution, reports the same versions; VS .NET 2003 SP1 reports `cl` 13.10.6030 and is a different candidate. See [docs/TOOLCHAIN.md](../docs/TOOLCHAIN.md).

### Imports

348 imports from 13 DLLs:

| DLL | Imports |
|---|---:|
| `msvcr71.dll` | 113 |
| `kernel32.dll` | 87 |
| `mss32.dll` | 71 |
| `user32.dll` | 33 |
| `binkw32.dll` | 10 |
| `winmm.dll` | 8 |
| `advapi32.dll` | 6 |
| `msvcp71.dll` | 5 |
| `ole32.dll` | 4 |
| `version.dll` | 3 |
| `shell32.dll` | 3 |
| `oleaut32.dll` | 3 (ordinals) |
| `gdi32.dll` | 2 |

The CRT is dynamic (`msvcr71`/`msvcp71`), so CRT code is mostly outside the image; local functions named `MSVCR71.DLL::…` are import thunks. There is no `d3d9.dll` import and no `dinput8.dll` import: Direct3D 9 is loaded dynamically (`Direct3DCreate9`, `d3d9.dll` strings, NiDX9 renderer), and input uses Win32/MMSYSTEM (`joyGetPosEx`, keyboard/mouse messages). Miles (`mss32`) and Bink are imported directly.

### Embedded engine

The image contains Gamebryo 10.1.0.0:

- `NiMain Gamebryo Version 10.1.0.0`
- `NiAnimation Gamebryo Version 10.1.0.0`
- `NiCollision Gamebryo Version 10.1.0.0`
- `NiDX9 Gamebryo Version 10.1.0.0`
- `NiDX9Renderer`, `NiDX9SourceTextureData`, `NiDX9IndexBufferManager`
- NIF and KFM format strings, `DEFAULTNIFPATH`, `NiMeshParticleSystem`, `NiMeshPSysData`, `NiD3DXEffectShaderLib`

The engine is statically linked: these are functions inside `Pirates!.exe`, not a separate DLL. That is a large part of the 2.88 MB of code.

Only four `.?AV` RTTI strings exist (`type_info`, `exception`, `logic_error`, `length_error`). Game/engine class RTTI is not available, so names cannot be recovered from RTTI. ATL is present (`ATL::CSimpleArray`, `CAtlBaseModule`), and 12 `Catch@…` exception funclets confirm C++ exceptions.

## Function inventory

Built from a Ghidra 12.2 session with REA (`list_procedures`), 8,522 rows:

| Metric | Value |
|---|---:|
| Rows (including imports) | 8,522 |
| External/import rows | 341 |
| Internal functions | 8,181 |
| Placeholder names | 7,932 |
| `FUN_` names | 7,840 |
| `thunk_` names | 80 |
| `Catch@` names | 12 |
| Non-placeholder names | 249 |
| Functions flagged as thunks | 140 |
| Sum of spans | 2,879,488 bytes |
| Span min / median / max | 3 / 128 / 40,256 bytes |

The entry point is the named local function `entry` at `0x5f09ac` (span 512 bytes). The largest span is `FUN_0041b1d0` (40,256 bytes). The 249 named functions are mostly import thunks, CRT glue, and ATL; game and engine code is almost entirely placeholder-named.

Spans are derived from the next function entry, not from Ghidra body lengths, and can include alignment padding. The matcher trims trailing padding on both sides and reports the trimmed counts. The inventory is committed as `build/functions.json` and is reproducible with `tools/build_inventory.py`.

## Prior art (external; not locally verified as a whole)

- A July 2026 Reddit post describes a "Pirates! Expanded Mod Framework": months of reverse engineering, an extension layer that interfaces with internal game systems, live state reading/writing, custom events, persistent mod-side save data, and a JSON/Lua foundation. It requires the user's own copy. The post was reviewed as a search snippet; no source repository was visible in the snippet.
- An October 2026 external RE notes page describes the same-era binary: graphics init at `0x4d2950`, device setup at `0x500080`, a caps check at `0x5c0963`. In the local inventory, `0x4d2950` is a 3,536-byte function, `0x500080` is a 560-byte function, and `0x5c0963` lies inside `FUN_005c0930` (608 bytes) — the addresses are consistent with the same code generation. The page also says the binary has a "statically linked (`d3d9.dll` import)"; the local import table has no `d3d9.dll` entry and the renderer resolves `d3d9` dynamically. Local observation wins; the discrepancy may be a different candidate binary or a wording error.

The reviewed material describes reverse engineering and modding, not a public matching decompilation. That is a lead, not proof that no decompilation exists; the search was not exhaustive.

## Feasibility and risks

- **Scale.** 8,181 functions and 2.88 MB of code are about 11.6% of the FNV function count and 25% of its code bytes. Denser functions (median 128 bytes) and a statically linked C++ engine make the average function harder, not easier. This is a community-scale effort, not a weekend script.
- **Toolchain.** Exact compiler build and per-unit flags are the main technical risk. Without `cl` 13.10.3077, no function can be certified. The free Toolkit 2003 is the practical path.
- **No symbols.** No public PDB, no class RTTI. Function and class names must come from behavior, strings, vtables, ATL/Gamebryo knowledge, and cross-references.
- **Engine code.** Gamebryo 10.1 is proprietary. Reconstruct it from shipped bytes and public documentation; do not copy leaked source.
- **Data.** The image has ~1.86 MB of zero-initialized globals, jump tables, strings, and vtables. The current harness compares code bytes and relocation targets, not data bytes. Data matching is the next harness milestone.
- **Build provenance.** The GOG installer may contain a repacked executable. The decompilation claims are relative to this exact SHA-256, not to every 2004 retail build.
- **Scale of assets.** The game's data is ~900 MB and is not part of the code project; do not extract it into experiment output without a storage decision.

## Next action

Install the exact VC7.1 toolset on a 32-bit-capable host, verify `cl`/`link` versions, then certify the first candidate: `0x497420` is a one-byte `RET` function with 30 callers, so an empty C++ function should reproduce it once compiled. Prove a PASS plus a negative control before expanding `src/`. See [docs/TOOLCHAIN.md](../docs/TOOLCHAIN.md) and [experiments/2026-11-08-target-identification/README.md](../experiments/2026-11-08-target-identification/README.md).
