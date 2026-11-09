# Team decompilation pass — 2026-11-08

Status: **UNVERIFIED.** No function has been matched to the shipped bytes. `cl` 13.10.3077 / `link` 7.10.3077 is still absent, so every candidate below is a hypothesis and `build/units.json` remains empty.

## What was done

The 3.32 MB image was divided into eight contiguous bands (1,023 functions each, except the tail), and twelve subagents were given read-only REA access plus the local Ghidra pseudocode corpus. One agent audited corpus coverage and schema; one mapped imports, thunks, and EH funclets; one tried the whole-engine map; one tried a candidate pilot. All team outputs are under `analysis/team/` (ignored; 14 MB, not committed); the 77 MB pseudocode corpus is `analysis/pseudocode/`.

| Deliverable | Result |
|---|---:|
| Internal functions | 8,181 |
| PE imports (import directory) | 348 |
| Ghidra external/import rows | 341 |
| Ghidra pseudocode files | 8,181 (77 MB) |
| Band triage rows | 8,181 (100% of inventory) |
| Deep dossiers | 85 |
| Candidate packages | 23 |
| Distinct REA evidence IDs | 319 |
| PASS claims | 0 |

Inventory correction from the tail band: 167 `Unwind@…` entries are compiler EH funclets, not source functions. They were previously counted as matchable. The corrected inventory has 179 EH funclets (12 `Catch@` + 167 `Unwind@`), 140 thunks, and **7,862 matchable source functions**. `build/functions.json` and the identity findings were regenerated.

## Triage

Per-band categories, from each `triage.json` (heuristic; labels are not subsystem proof):

| Band | Range | Game | Gamebryo | Unclassified | CRT | EH | Thunk | Platform |
|---|---|---:|---:|---:|---:|---:|---:|---:|
| 1 | `0x401000`–`0x4c3690` | 941 | 25 | 40 | 13 | 4 | 0 | 0 |
| 2 | `0x4c3790`–`0x514090` | 967 | 4 | 0 | 0 | 0 | 2 | 50 |
| 3 | `0x5141c0`–`0x54ada0` | 360 | 448 | 73 | 111 | 7 | 24 | 0 |
| 4 | `0x54ae10`–`0x5913a0` | 0 | 459 | 530 | 0 | 0 | 11 | 23 |
| 5 | `0x591460`–`0x5dab60` | 999 | 11 | 0 | 0 | 0 | 11 | 2 |
| 6 | `0x5db0a0`–`0x61003c` | 0 | 922 | 0 | 54 | 1 | 35 | 11 |
| 7 | `0x610165`–`0x672e90` | 0 | 0 | 1,023 | 0 | 0 | 0 | 0 |
| 8 | `0x672ecd`–`0x6bfc80` | 0 | 18 | 814 | 4 | 167 | 17 | 0 |
| **Total** | | **3,267** | **1,887** | **2,480** | **182** | **179** | **100** | **86** |

Caveats: `game` in bands 2 and 5 is mostly the script's default when no string matched; band 7 was deliberately left all-unclassified; band 6's 922 `gamebryo` labels are neighborhood evidence, not per-class truth. The triage skeleton is complete; the classification is uneven by design.

## Observed subsystem map

The binary is not monolithic game code. It statically links Gamebryo 10.1 and bundles library code, which explains much of the 2.88 MB `.text`.

| Region | Observed content | Confidence |
|---|---|---|
| `0x401000`–`0x4c3690` | earliest code; startup, game/UI entry paths; sampled functions are table/register logic | low–medium |
| `0x4c3790`–`0x514090` | UI/encyclopedia/options (`0x4c`–`0x4e`), Win32 platform (`0x4f`), Gamebryo/D3D adapters (`0x50`) | low–medium |
| `0x5141c0`–`0x54ada0` | Gamebryo Ni core: class/vtable, animation, collision, cell/landscape streaming, audio and loaders | medium |
| `0x54ae10`–`0x5913a0` | engine class-system globals, fog/enum printers, animation/hierarchy property dumps, KFM writer, NiCollision float kernels, refcounted-record factory | medium |
| `0x591460`–`0x5dab60` | game code by default label, sparse engine/platform hits; no reliable subsystem split | low |
| `0x5db0a0`–`0x61003c` | NiD3D/NiD3DX shader wrappers, shader-constant reflection, CRT, opdelete | medium–high |
| `0x610165`–`0x672e90` | high-`.text` support: hash-bucket lookup, frameless initializer, 6-constant membership predicate; unclassified | low |
| `0x672ecd`–`0x6bfc80` | bundled D3DX9 shader compiler `5.04.00.2904`, PNG/zlib codec code, MSVCR71 tail, 167-entry Unwind block, static-init forwards | high |

Named engine evidence includes `NiMain Gamebryo Version 10.1.0.0`, `NiDX9Renderer`, `NiDX9SourceTextureData`, `NiD3DXEffectShaderLib`, NIF/KFM strings, and the D3DX9 compiler banner. Game and engine class RTTI is absent; only four standard `.?AV` strings exist.

## Candidate queue

The first candidates are small, leaf-like, and fully observed; none is matched.

| Address | Body | Shape | Source |
|---|---:|---|---|
| `0x0069edd0` | 12 B | `__stdcall` argument identity (`RET 4`) | band 8 |
| `0x006ae430` | 8 B | `__stdcall` constant `1000000` | band 8 |
| `0x006b3da0` | 10 B | `__thiscall` member store | band 8 |
| `0x00673e38` | 49 B | `__stdcall` four-int match with `-1` wildcard | band 8 |
| `0x004d5850` | 6 B | constant `7` | band 2 |
| `0x005456b0` | 13 B | indexed field getter, `RET 4` | band 3 |
| `0x0054ae10` | 41 B | global refcount release | band 4 |
| `0x00591380` | 29 B | 5-argument thiscall forwarder | band 4 |
| `0x00610ba0` | 54 B | case-insensitive hash-bucket lookup | band 7 |

`0x00497420` remains a strong first target from the earlier pass (56 callers, immediate return), but the candidate-pilot agent produced no package for it.

## Limitations

- Compiler absent: no byte comparison, no flag proof, no PASS.
- PDB not loaded: `Pirates!.pdb` GUID `1f2eb43b-699e-4f99-b761-08b9a02f75cf`; original names/types unavailable.
- Ghidra call graphs omit indirect calls; `procedure_callees`/`procedure_callers` coverage is partial where virtual dispatch dominates.
- No data-layout matching: vtables, RTTI, and static data were not compared.
- Triage is corpus/string based; no per-function REA call was made for most of the 8,181 entries.
- Two specialist tracks (global engine map and candidate pilot) produced no deliverables; their questions remain open and are covered only partially by the band reports.
- Candidate symbols are invented spellings; they are not evidence of the original names.

## Next action

Superseded by the mass reconstruction wave (see
[2026-11-08-reconstruction.md](2026-11-08-reconstruction.md)): all 7,862
matchable functions now have decompiler-derived candidates under
`experiments/2026-11-08-source-reconstruction/out/` (queue empty), and the
compiler is installed and proven (`tiny_*` units PASS). Remaining:

1. Make mass candidates compile as `build/units.json` entries; fix the 341 `NEEDS_MANUAL` sites first.
2. Run `tools/match.py compare` at scale until functions are `PASS`.
3. Acquire or load the matching PDB; if unavailable, decode vtables and imports to recover class identity.
4. Do not match EH funclets, thunks, padding, or static-init fragments as standalone units.
