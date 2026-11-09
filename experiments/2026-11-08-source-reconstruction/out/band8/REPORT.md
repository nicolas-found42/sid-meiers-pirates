# Band 8 reconstruction report (batch 1)

**UNVERIFIED: no cl 13.10.3077 on this host. No candidate is a match; nothing was added to `build/units.json`; no PASS claims.**

## Scope

Band 8: `0x00672ecd-0x006bfc80`, 1,020 functions in `analysis/team/band8/{slice,triage}.json`.

| category | count | disposition |
|---|---|---|
| unclassified | 814 | matchable pool (see QUEUE priority) |
| eh-funclet (Unwind) | 167 | **excluded from manifest and queue** — EH stubs, not C++ units |
| gamebryo (D3DX9/PNG/zlib) | 18 | bundled third-party — see below |
| thunk (MSVCR71 imports) | 17 | **excluded from manifest and queue** — import jumps |
| crt (compiler helpers) | 4 (one is `0x006ae81b` library marker, not in batch) | CRT helpers linked, not matched |
| **batch 1 manifest** | **31** | this output |

Manifest = 31 functions. Queue = 805 remaining matchable addresses (1,020 − 184 EH/thunk − 31 manifest), disjoint, in priority order (gamebryo → small leaves → rest).

## Third-party bundling (critical)

Most of band 8 is **bundled third-party code shipped inside `Pirates!.exe`**, not Sid Meier's Pirates game logic:

- **`0x672-0x6a4`**: D3DX9 shader compiler (`Microsoft (R) D3DX9 Shader Compiler 5.04.00.2904`, `d3d9.dll`, `Direct3DShaderValidatorCreate9`, ps_1.x diagnostics). Reconstructions of these are clean-room equivalents, not Firaxis source, and must not be attributed to Gamebryo or to the game.
- **`0x692-0x6b5`**: PNG/zlib codec (lodepng-style chunk names IHDR/PLTE/gAMA/sRGB/tRNS/IEND, zlib inflate state machine, `invalid window size`, `Duplicate PLTE chunk`, etc.).
- **`0x6b920a-0x6b9310`**: MSVCR71 import thunks + CRT/compiler helpers (`__aullshr`, `__allmul`, `__allshl`).
- **`0x6b9310-0x6ba060`**: 167 Unwind EH funclets.
- **`0x6bec00+`**: static-init / tail forwards.

This batch reconstructs 31 of these faithfully from shipped bytes / REA pseudocode; none should be claimed as original game source.

## Observed vs inferred

Observed: spans, RET immediate (arg counts), instruction shapes, string literals, callee sets from triage + 21 deep dossiers (`analysis/team/band8/deep/*.md`).

Inferred: all C++ parameter names, struct layouts (offsets `+0x10`, `+0xe4`, `+0x58`, `+0x10c` are observed, the C++ types are not), class identities, subsystem labels from neighbourhood. Symbols `?FUN_...@@...` are hypotheses (PDB not loaded).

## Counts

- manifest entries: 31 (18 from deep dossiers + 13 PNG/zlib/shader/string leaves)
- QUEUE remaining: 805
- EH/thunk excluded: 184
- files: `src/band8_leaves.cpp` (4), `src/band8_dtor.cpp` (2), `src/band8_png.cpp` (9), `src/band8_zlib.cpp` (4), `src/band8_crt.cpp` (3), `src/band8_shader.cpp` (5), `src/band8_init.cpp` (3, fragments)

Excluded from batch deliberately: `0x0069310`/`0x006b9a78` EH funclets, `0x00697497` (7656B shader-codegen core — needs IR recovery, not a near-term unit), and all 17 thunks.

## Blockers

1. No cl 13.10.3077 — nothing can be byte-matched; all UNVERIFIED.
2. PDB GUID `1f2eb43b-…` not loaded — no original symbols/classes.
3. Phantom/padding spans: e.g. `0x006bfc80` span 896 = end-of-text artifact (body 10B); `0x006b9310` span 32 vs body 8. Queues/manifests use address list, not spans.
4. Complex shader bodies (`0x0067327b`, `0x006752d1`, `0x00675ec3`, `0x0067c8e9`, `0x00693ba4`) are approximations flagged low confidence in the manifest.

## Next batch (from QUEUE head)

Prioritized in `QUEUE.json`: remaining PNG chunk handlers (`0x00693f45`, `0x00694127`, `0x0069428a`, `0x0069438d`, `0x00694471`), zlib inflate entry (`0x0069323b`), decompression tail (`0x0069464e`), shader validator string tables (`0x0067bd0e`), then smallest unclassified leaves.
