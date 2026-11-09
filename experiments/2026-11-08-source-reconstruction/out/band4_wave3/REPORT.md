# band4_wave3 report

UNVERIFIED — `cl 13.10.3077` is absent; no build, no byte-match claim.

20 entries: 0x0054bc90, 0x0054bfc0, 0x0054c050, 0x0054c1c0, 0x0054c210,
0x0054c2e0, 0x0054c420, 0x0054c4a0, 0x0054c570, 0x0054c5b0, 0x0054c720,
0x0054c750, 0x0054c780, 0x0054c7c0, 0x0054c9c0, 0x0054cc80, 0x0054ce20,
0x0054cf60, 0x0054d020, 0x0054d720.

## Observed (from pseudocode)
- 0x0054bc90: tiny ctor (FUN_005383d0, vtable 0x711788, +0x0c=0). 0x0054bfc0: alloc 0x34 factory + swap global DAT_00727980; 0x0054c050: release+zero that global.
- 0x0054c1c0: 0x40-byte ctor with vtable swap 0x6c0a50→0x6c215c and slots 6/2/3/0; 0x0054c210: pow2-guarded factory, fill +0x38/+0x3c/+0x20, validate vcall +0x104.
- 0x0054c2e0: vector assign/delete with 4-wide unrolled copy (non-contiguous 0x54c3b0 tail); 0x0054c420: float-vector equality with NaN-flag merge.
- 0x0054c4a0/0x0054c570: assign-ctor / deleting dtor (vtable 0x6c21ac, operator_delete +0x14, flag&1 self-delete). 0x0054c5b0: two vcall +0x0c via *(p+0x160).
- 0x0054c720/0x0054c750/0x0054c780: 9-dword copies DAT_00727484/DAT_00717a00 and 7-entry release table DAT_007279c8 (0x1c).
- 0x0054c7c0: texture compose (alloc 0x50, FUN_00539210(8,8), 8× FUN_005f0ddc packs by masks DAT_00717860-6c, 8×8 tile); 0x0054c9c0: indexed cache (−1..6) building 1.0f matrices, FUN_0054c7c0+FUN_0051ac30.
- 0x0054cc80: append via FUN_00541080/FUN_00557b10(DAT_007279a0), grow FUN_006b34a0, FUN_005606f0.
- 0x0054ce20/0x0054cf60/0x0054d020/0x0054d720: four unscale loops (3→16, 3→32, 4→16, 3+pad→16) with per-desc shift/mask CONCAT22/channel terms.

## Inferred
- Naming of vtables, flags, cache/table slots, and desc byte layout is descriptive.
- thiscall/cdecl splits follow ECX/stack use; all unverified.

## Blockers
- `cl 13.10.3077` absent; all entries `status: "unverified"`, no passing claim.
- 0x0054c2e0 and 0x0054c420 are non-contiguous; second ranges not separately observed.

## Next
- Continue from QUEUE.json (remaining after subtracting this wave and all other `out/*/manifest.json` claims).
