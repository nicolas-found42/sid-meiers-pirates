# Band 8 reconstruction report (wave 2)

**UNVERIFIED: no cl 13.10.3077 on this host. No candidate is a match; nothing was added to `build/units.json`; no PASS claims.**

## Scope

Parent queue `out/band8/QUEUE.json` (805, disjoint from the wave-1 manifest of 31).
This wave takes the first 20 genuine matchable addresses — the PNG chunk
handlers, zlib inflate entry + IDAT tail, shader string tables, a validator
init, an empty tail stub, and 8 shader-opcode leaves — and writes only
`out/band8_wave2/`.

| file | functions | coverage |
|---|---|---|
| `src/band8_png.cpp` | 6 | IHDR `0x00693f45`, PLTE `0x00694127`, gAMA `0x0069428a`, sRGB `0x0069438d`, tRNS `0x00694471`, decompression tail `0x0069464e` |
| `src/band8_zlib.cpp` | 2 | inflate dispatcher `0x0069323b`, (tail uses `0x0069464e` via PNG file) |
| `src/band8_shader.cpp` | 12 | semantic parser `0x0067bd0e`, chunk writers `0x006a3628`/`0x006a2cbe`, validator init `0x006a3d1c`, empty stub `0x006bf6e0`, opcode leaves `0x006a679b`, `0x006a67a5`, `0x006a67cd`, `0x006a6831`, `0x006a683b`, `0x006a6845`, `0x006a684f`, `0x006a6859` |
| **manifest total** | **20** | all 20 queue-head addresses, unique, not in the wave-1 manifest |

Remaining queue (`QUEUE.json` in this directory) = 785 addresses,
disjoint from both manifests. EH/thunk/phantom spans were already excluded
upstream.

## Third-party bundling

As in wave 1: `0x00693xxx`–`0x00694xxx` is bundled lodepng-style PNG/zlib
code and `0x0067xxxx`/`0x006axxxx` is bundled D3DX9 shader-compiler code —
clean-room equivalents from shipped bytes + REA pseudocode, not Firaxis
game source, and must not be attributed to the game or Gamebryo.

## Observed vs inferred

Observed: spans, string literals ("Missing IHDR before gAMA/sRGB",
"Duplicate PLTE chunk", "invalid window size", semantic names
color/texcoord/position/fog/psize/diffuse, "d3d9.dll",
"Direct3DShaderValidatorCreate9"), RET immediates, state constants
(0,1,7,8,0xd), offsets `+0x58/+0xb8/+0xfc/+0x130/+0x15c`. Inferred: C++
names, struct layouts, table strides, the exact packing of the semantic
index in `0x0067bd0e`. Detailed per-function caveats live in
`manifest.json` (`unknowns`).

## Verification status

- Files exist: `src/band8_png.cpp`, `src/band8_zlib.cpp`, `src/band8_shader.cpp`.
- 20/20 manifest sources exist; 20 unique addresses, all in the parent queue.
- Queue disjoint from both manifests. No cl 13.10.3077 — no PASS claimed.

## Blockers

1. No cl 13.10.3077 — nothing can be byte-matched; all UNVERIFIED.
2. Decompiled bodies are semantically fragmented (e.g. `0x006a3628`,
   `0x006a2cbe`, `0x006a3d1c` emitter loops); the shader fragments above are
   documented entry/shape reconstructions, not complete bodies. Manifest
   flags them `medium` confidence deliberately.
3. The remaining 785 queue addresses follow in priority order (further
   opcode leaves `0x006a6863`–`0x006a693e`, then init/tail forwards).
