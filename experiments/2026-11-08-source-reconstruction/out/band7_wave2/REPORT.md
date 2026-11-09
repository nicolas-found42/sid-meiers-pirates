# Band7 wave2 report (UNVERIFIED)

UNVERIFIED clean-room candidates. `cl 13.10.3077` is absent; no byte-match, no PASS.

Wave: 20 smallest-span unclaimed addresses from `out/band7_batch1/QUEUE.json`, ordered by (span asc, address), spans 1–25. Source: `src/band7_wave2.cpp` only. All 20 status `unverified`, corpus-only, no REA calls this turn.

## Observed (corpus-verified)
- 0x006338c7: empty function, `return;` (span 1).
- 0x006321e1: zero u32 at self+0x04..0x14 (thiscall, ECX).
- 0x0065676f: zero 0x10 u32 words at param_2; param_1 unused.
- 0x0062952f: list init — pu=self+0x0c, `[0x14]=0`, `*pu=0`, `[0x1c]=pu`, `[0x18]=pu`, `[0x20]=0`.
- 0x006564c0: zero `(*param_1)+0x6c` and `+0x14`.
- 0x0065ac33: `FUN_0065ab96(1)`, `p[4]=0`, `*p=PTR_FUN_006edfdc`, return p (EDX convention unverified).
- 0x0065c3ac: `p[0]=param_1; p[1]=param_2` (thiscall).
- 0x006417d1: `p[0]=3; p[4]=0; p[5]=0; p[3]=0; p[6]=0` in that order.
- 0x00644faa: forward `FUN_0064121f(param_2)`; param_1 unused.
- 0x0062947f: `[3]=0; [2]=0; [0]=PTR_FUN_006e1934; [1]=1` in that order.
- 0x006412a1 / 0x0064137d / 0x00641395 / 0x006413ad: indirect calls via inner (`*(param+0x0c)`) vtable slots +0x10 / +0x30 / +0x34 / +0x44 with `(inner, param_2)`.
- 0x0065d07f: `DAT_0072be28=0; DAT_0072be2c=param_1`.
- 0x0065d5fa: `DAT_0072be30=0; DAT_0072be34=param_1`.
- 0x0062a46a: `*self=param_1; FUN_0060d291();` (thiscall).
- 0x0062a5d2: `[3]=0; [2]=0; [4]=self; [5]=0; [1]=0; [0]=0; [6]=0` in that order.
- 0x0062ee93: `FUN_0062d2ee(param_2,param_3,0)`; param_1 unused.
- 0x0062f5d8: `FUN_0062eccf(param_2,param_3,0)`; param_1 unused.

## Inferred
- thiscall (ECX) vs cdecl from `in_ECX`/`extraout_EDX` signals; Fn00 typedef for inner-vtable slots; `g_dat_*` / `g_ptr_*` externs as address hypotheses.

## Blockers
- `cl 13.10.3077` is absent — no compile, no PASS, no byte-match claim. Corpus headers (`// rea decompile_all`, Ghidra boilerplate) not reconstructed.

## Next
- QUEUE.json holds the remaining 985 addresses (parent 1005 minus all claimed incl. this wave); no duplicates.
