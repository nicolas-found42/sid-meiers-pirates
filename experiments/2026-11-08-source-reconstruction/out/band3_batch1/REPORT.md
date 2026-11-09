# Band 3 batch 1 — reconstruction report (UNVERIFIED)

`cl 13.10.3077` is absent on this host, so every candidate below is
UNVERIFIED and no PASS / byte-match is claimed.

## Observed

- Matchable set: 992 functions from `analysis/team/band3/triage.json`
  (category `thunk` ×24 and `eh-funclet` ×7 excluded), sorted by
  `(span, address)` ascending. One smallest entry, `0x005456b0`, was
  already claimed in `out/lead/manifest.json`, so the first 15 unclaimed
  small leaves start at `0x00533b70`. The three mandatory deep-dives
  `0x00514ac0` / `0x005366b0` / `0x0054aae0` rank outside the first 15
  and were added on top: 18 entries total in `manifest.json`.
- Preserved observed facts per function: exact offsets (`+0x15c/+8`,
  `+0x90→+0x28`, `+0x188/+0x44`, `+0x194`, `+0x0c`, `+0x18`,
  `+0x18/+0x30` ATL dtor), constants (`4`, `0`, `-1/+1`), data refs
  (`DAT_00727444/007275a0/00727864/0072792c/00533b60`), call order
  (`0x00549b80` → `0x00538400`; `0x0054aae0` → `0x0055adf0` with
  `this+8` after the second vtable write), and the ATL
  `DeleteCriticalSection` + `0x533b80 RemoveAll` sequence at `0x00533bb7`.
- Deep-dive REA evidence used for the three mandatory addresses:
  - `0x00514ac0`: `MOV EAX,[ESP+4]; MOV ECX,[EAX+0x15c]; …; PUSH 4; PUSH EAX; CALL [EDX+8]; RET`
  - `0x005366b0`: `LEA EAX,[ECX+0x90]; …` 12-byte copy `+0x90→+0x28`
  - `0x0054aae0`: `PUSH ESI; MOV ESI,ECX; MOV [ESI],0x6fd148; MOV [ESI+4],0; INC [0x727444]; …; CALL 0x55adf0`
- Layout: `src/tiny_ctor.cpp` (6), `src/tiny_vcall.cpp` (6),
  `src/tiny_setters.cpp` (6). Every definition carries its
  `// 0x00xxxxxx` shipped-address comment; `manifest.json` maps each
  address to an existing source file.

## Inferred

- All C++ signatures, calling conventions, struct/parameter types, and
  the `AtlBaseModule_533bb7` stand-in are hypotheses inferred from
  pseudocode/assembly shape only; original class/symbol names were not
  invented beyond corpus labels (plus the corpus/library ATL name).
- Vtable slot semantics, `DAT_*` owners, and the ATL opaque layout are
  unknown.

## Blockers

- No `cl 13.10.3077` → nothing can be built or byte-matched; all
  candidates stay `status: "unverified"`.
- `0x00533bb7`'s true ATL layout (`CRITICAL_SECTION` at `+0x18`, array at
  `+0x30`) and `0x0054aae0`'s vtable identities (`0x6fd148/0x6c1fb4`)
  are unverified.

## Next

- Continue from `QUEUE.json` (973 remaining unclaimed matchable
  addresses, same `(span, address)` order): next smallest unclaimed
  leaves are the span-32 CRT stubs (`0x005185c0`, `0x00518730`, …),
  then larger span-48+ gamebryo thunks/leaves. Pair `0x0054a9f0`,
  `0x00547610` setters with their neighbouring getters before the
  larger blocks.
