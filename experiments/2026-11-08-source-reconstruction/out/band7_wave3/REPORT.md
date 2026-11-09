# Band7 wave3 report (UNVERIFIED)

UNVERIFIED clean-room candidates. `cl 13.10.3077` is absent; no byte-match, no PASS.

Wave: 20 smallest-span unclaimed addresses from `out/band7_wave2/QUEUE.json`, ordered by (span asc, address), spans 18–19. Source: `src/band7_wave3.cpp` only. All 20 status `unverified`, corpus-only, no REA calls this turn.

## Observed (corpus-verified)
- 0x0063ef52: `return ~(u16*(p+0x42) * 0xb4 + s32*(p+0xa4))` (span 18, only non-forwarder).
- 0x00629ca0 / 0x00629dca: forward `(&p1,&p2,&p3)` to `FUN_00629bb0` / `FUN_00629cba`.
- 0x0062e228 / 0x0062e401: forward `(&p1,&p2,&p3,p4)` to `FUN_0062dfd6` / `FUN_0062e245`.
- 0x00641286 / 0x006412b9 / 0x006412d4 / 0x006412ef / 0x0064130a: indirect calls via inner vtable slots +0x0c / +0x14 / +0x18 / +0x1c / +0x20 with `(inner, p2, p3)`.
- 0x00641325 / 0x00641343 / 0x006413c5 / 0x006413e3 / 0x0064144c / 0x0064146a / 0x00641488: indirect calls via inner vtable slots +0x24 / +0x28 / +0x38 / +0x3c / +0x48 / +0x4c / +0x50 with `(inner, p2, p3, p4)`.
- 0x00641361: indirect call via inner vtable slot +0x2c with `(inner, p2)`.
- 0x0064487e / 0x0064ea67: forward `(p2, p3, 0)` to `FUN_0063ed81` / `FUN_0064d495`; param_1 unused.

## Inferred
- Fn01/Fn02/Fn03 cdecl typedefs for inner-vtable slots; `extern` callee declarations as address hypotheses.

## Blockers
- `cl 13.10.3077` is absent — no compile, no PASS, no byte-match claim. Corpus headers (`// rea decompile_all`, Ghidra boilerplate) not reconstructed.

## Next
- QUEUE.json holds the remaining 965 addresses (parent 985 minus all claimed incl. this wave); no duplicates.
