# Band5 wave2 report

UNVERIFIED clean-room candidates. `cl 13.10.3077` is absent; no byte-match, no PASS.

Wave: first 20 matchable addresses from `out/band5/QUEUE.json` (orders 1–20).
Source: `src/band5_wave2.cpp` only. All 20 status `unverified`, corpus-only, no REA calls this turn.

## Observed (corpus-verified)
- 0x005ae050: null-check inner ptr at self+0xc, then indirect call via inner vtable slot 0x40. Ghidra jumptable warning preserved as call.
- 0x005c9270: `if (DAT_00728dec==0) FUN_005c9200();`
- 0x005cce50: `*self = PTR_LAB_006c7db8`.
- 0x005cd3c0: `*(u32*)(self+0x3c) += 1`.
- 0x005d01f0: `*(u8*)(self+0x18) = param`.
- 0x005da350: `FUN_005bed20(); FUN_005cb3f0();`
- 0x00594f80: 4-arg forwarder returning `FUN_0059f180` byte.
- 0x005a03a0 / 0x005aa990 / 0x005ac9c0 / 0x005b0ed0: deleting-destructor shape `callee(self); if (flags&1) operator_delete(self);` with callees 005a19c0 / 005a8c00 / 005ac850 / 005bbd50.
- 0x005ac600: `FUN_005ae010(p); FUN_00545d20();`
- 0x005adcb0: `FUN_005ae060(p1,p2); *(p1+0x14)=*(self+0x14);` — ECX/dest roles medium confidence.
- 0x005ae010: `FUN_00538630(p); FUN_00545cc0(); FUN_00545cc0();`
- 0x005ae030: null inner returns 1, else tail-call slot 0x3c, Ghidra jumptable warning preserved.
- 0x005ae0d0: call then null-guarded inner slot 0x28 call.
- 0x005ae700: call, zero dwords 0x11/0x12, store PTR_FUN_006c5988 vtable.
- 0x005ae720: store vtable, `operator_delete(self[0x11])`, `FUN_00552d20()`.
- 0x005aea60: virtual slot 0x6c call then `FUN_005340b0(p1,p2)`.
- 0x005aec90: vtable store 006c5a40, `FUN_005edba0()`, vtable store 006c5a18.

## Inferred
- `__thiscall` (ECX=self) for in_ECX bodies; byte offsets 0x40/0x3c/0x28/0x6c treated as byte offsets into vtable slot index (offset/4).
- Deleting-destructor identification from `(param&1)` + operator_delete pattern.
- Opaque `void*` for unknown object params.
- Globals DAT_00728dec, PTR_LAB_006c7db8, PTR_FUN_006c5988, PTR_FUN_006c5a40, PTR_LAB_006c5a18 kept as extern hypotheses.

## Blockers
- `cl 13.10.3077` absent — nothing verifiable as byte-identical.
- 0x005adcb0 arg roles ambiguous (medium confidence).
- Vtable slot byte-offset interpretation and global types unverified.

## Next
- Remaining band5 queue after this wave: check `QUEUE.json` (count = parent minus all `out/*/manifest.json` claims).
- Suggested next slices: P1 small bodies orders 21+ per `out/band5/QUEUE.json`; larger functions need REA cross-checks for vtable/call identities.
