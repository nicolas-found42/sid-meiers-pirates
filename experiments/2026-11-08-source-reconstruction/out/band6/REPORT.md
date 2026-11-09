# Band 6 source-reconstruction report (batch 1)

Image: `Pirates!.exe` SHA-256 `6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9`, PE32 i386, base `0x400000`.
Range: `0x005db0a0-0x0061003c` (1,023 functions; 947 matchable, 75 thunks, 1 EH funclet).
Status: **UNVERIFIED** — no cl 13.10.3077 on this host; no PASS claims; `src/` and `build/units.json` untouched.

## Batch delivered (36 functions in 6 files)

| File | Addresses |
|---|---|
| `src/band6_shaders_a.cpp` (12) | `0x005db600`, `0x005edd70`, `0x005db6a0`, `0x005db810`, `0x005db220`, `0x005de120`, `0x005f124e`, `0x005f8d40`, `0x0060f79a`, `0x005e0270`, `0x005e0b30`, `0x005dbd60` |
| `src/band6_shaders_b.cpp` (4) | `0x005dc190`, `0x005dc360`, `0x005dc640`, `0x005dc900` |
| `src/band6_shader_variants.cpp` (5) | `0x005dce40`, `0x005dcf80`, `0x005dd0c0`, `0x005dd1b0`, `0x005e0880` |
| `src/band6_effects.cpp` (5) | `0x005e0b40`, `0x005e09d0`, `0x005f79a8`, `0x005f7a58`, `0x005f8042` |
| `src/band6_hlsl.cpp` (8) | `0x0060c029`, `0x0060c459`, `0x0060c598`, `0x0060d4a1`, `0x0060fef7`, `0x005e44d0`, `0x005e47a0`, `0x005e9fb0` |
| `src/band6_small.cpp` (2) | `0x005e1570`, `0x005e43e0` |

Manifest count (36) equals source function count (36). `QUEUE.json` holds the
remaining 911 matchable addresses (947 − 36), unique, in-slice, disjoint from
the manifest; priority: gamebryo high→medium→low, then CRT named helpers.

## Observed (grounded in corpus / REA dossiers / triage)

- Shader wrappers: `0x005db600`/`0x005edd70` are MSVC deleting destrtors
  (real dtor call + `test deleteFlag,1` + `operator_delete` at `0x005f08d6` +
  `MOV EAX,ESI` + `RET 0x4`). `0x005db6a0` writes vtable `0x006fd148` then
  `0x006c8e8c` with refcount `0x00727444` increment. `0x005dbd60` is
  `return this+8`; `0x005e0270` is a single vtable store (`0x006c93fc`);
  `0x005e0b30` returns global `0x007290b0`; `0x005e1570` is
  `return value % this[1]`; `0x005db810` clears `+8`, calls init from global
  `0x007275fc`, sets `+0xc=1`.
- Ctor `0x005db220` (723B): three `0x7fffffff`-pair fill loops (0x100/0x210/0x110
  at word offsets `0x4b`/`0x24b`/`0x66b`), flags `+4=0,+5=1,+6=1`, delegate to
  `0x005daa30`; remaining writes are dense data-only index tables.
- Loaders/assemblers: `0x005dc190` (6 params) and `0x005dc360` share the
  validate → compile (`0x005f7745`/`0x005f7876`) → vtable+0x10 size →
  `0x00533c78` copy pattern; strings: "Invalid shader file name",
  "Failed to find shader program file %s", "Failed to compile shader…",
  "Invalid shader buffer", "Failed to assemble shader…". Creators
  (`0x005dc640`/`0x005dc900`/`0x005dce40`/`0x005dcf80`/`0x005dd0c0`/`0x005dd1b0`)
  allocate `0x28/0x34/0x40` bytes, set vtable pockets (`0x6c8f88`/`0x6c8f30`/
  `0x6c8ed8`/`0x6c8e98`), assemble, then native create via `0x005de010`/
  `0x005de050`; strings: "Failed CreateVertexShader/PixelShader call on %s".
- Effects: `0x005e0b40` checks ".fx" via `_stricmp` vs `0x006c95d0`, resolves
  via `0x005e09d0`; `0x005e09d0` handles `/` vs `\` join and "D3D Effect file
  not found". `0x005e44d0`/`0x005e47a0` log "Killing NiD3DXEffectTechnique[Set]".
  `0x005e9fb0` emits the seven "NSBShader::GetD3DShader – …" diagnostics.
  `0x005f79a8`/`0x005f7a58` map caps version to "ps_1_x"/"ps_2_x"/"ps_3_0" and
  "vs_2_0"/"vs_2_a"/"vs_3_0". `0x005f8042` scans a 0x2c-entry table.
  `0x005e0880` registers "NiD3DXEffectShaderLib" with 0x94-byte array alloc.
- HLSL: `0x0060c029` sets ctx `+0x44=1`, handles "syntax error" vs
  "invalid preprocessor command '%s'"; `0x0060c459` handles "unexpected #elif"
  (state at `+0x54`); `0x0060c598` maps "row_major"→`0x400`,
  "column_major"→`0x800`; `0x0060d4a1` handles "__LINE__" and two error
  strings; `0x0060fef7` prints token kinds (version/integer/float/token/
  string/end-of-line/end-of-file). `0x0060f79a` zeroes `+0/+4/+0x18/+0x2c/
  +0x30`, sets `+0x1c=1`. `0x005f8d40` copies 74 pointers (`0x00718930`→
  `0x00718808`) under mode state `0x00718a60`; registry strings
  "DisablePSGP"/"DisableD3DXPSGP". `0x005f124e` computes Hermite weights
  `h00=2t³−3t²+1, h10=t³−2t²+t, h01=−2t³+3t², h11=t³−t²` scaled by 0.5.
- CRT: `operator_delete` resolves to import thunk `0x005f08d6`;
  `__onexit`/`_atexit`/`__security_*`/`__SEH_*`/`__ArrayUnwind`/
  `eh_vector_*`/`__chkstk`/`__RTC_Initialize`/`__setdefaultprecision` are
  inventory-named VC7.1 CRT helpers — reconstructed only as externals, not
  as sources (no reimplementation attempted).

## Inferred (hypotheses — not proven)

- All class names (`Band6ShaderWrapper`, `Band6Object`, `NiD3DXEffectWrapper`,
  `HLSLParserContext`, …), field semantics, and Microsoft-decorated symbols
  are clean-room placeholders. `NiMathCubicBlend` arg order maps pseudocode
  `param_2..param_5` to the four vectors; `NiD3D` global names (`gBand6*`)
  are address-tagged hypotheses.
- Ctor's trailing index tables are data-only and summarised, not listed word
  by word; `0x005f8042` entry layout (triple) is inferred from the copy size;
  HLSL parser ctx layout beyond observed offsets is unknown.
- Creator-variant routing uses shipped `in_ECX` vtable readers (`+0x24`/
  `+0x28`); golden operand types are unknown. Effect `0x005e0880` field
  indices (`+0x1c` etc.) are word offsets, not named fields.
- `0x0060f79a` gap words (`+0x08..+0x14`, `+0x20..+0x28`) are untouched by the
  shipped body — padding vs. caller-owned is unknown.

## Counts

- Batch 1: 36 functions (30 high confidence, 6 medium). See `manifest.json`.
- Queue: 911 remaining (gamebryo high-first, then CRT). 75 thunks + 1 EH
  funclet excluded from QUEUE by the matchable definition (947 = 1023 − 76).
- Sub-regions covered: wrappers (`0x5d`), effect helpers (`0x5e`), shaders
  (`0x5f`), HLSL parser (`0x60`).

## Blockers

- No cl 13.10.3077 on this host: nothing can be byte-matched; all 36 are
  UNVERIFIED and must be handed to a VC7.1 toolchain host.
- Owner-class layouts for `0x5db600`/`0x5edd70` unknown (fields `+0/+4/+8/
  +0xc` only); vtable contents at `0x006c8xxx`/`0x006fd148` unrecovered.
- String-rich loaders still need middle-param typing confirmed against
  callers. HLSL yacc tables (`0x0060eb43` state tables) are data, not code —
  continue from corpus reads, not reconstruction.

## Next batch (unambiguous queue)

Take `QUEUE.json` in order. Recommended wave 2: the medium-confidence
`0x5dc000-0x5de00` NiD3D cluster (creator callees `0x5de010`/`0x5de050`/
`0x5de500`, `0x5e0120` table init, `0x5e8a70`/`0x5e9bf0` impl-select chain),
then `0x5e` effect helpers (`0x5e0880` done; next `0x5e0xxx` slots), then
the `0x60` parser spine (`0x0060d2cf`, `0x0060e245`, `0x0060fcd3`,
`0x0060f81e`, `0x00610755`). Skip CRT import thunks (not matchable).

## Evidence

- Per-function: `analysis/pseudocode/functions/0x*.c` (36 files) +
  `analysis/team/band6/deep/` (17 dossiers) + `analysis/team/band6/triage.json`
  (basis strings) + candidate sketches in `analysis/team/band6/candidates/`
  (9 files, reused structurally; unverified symbols stripped).
- This batch used the local corpus only; no new REA calls were needed.
