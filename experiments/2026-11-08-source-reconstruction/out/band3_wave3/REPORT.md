# band3_wave3 report — unverified

20 smallest unclaimed addresses from `out/band3_wave2/QUEUE.json` (span 32), reconstructed clean-room across `src/audio_ail.cpp`, `src/small_helpers.cpp`, `src/small_dtors3.cpp`, and `src/small_misc.cpp`. Every definition carries a `// 0x00xxxxxx` comment; offsets, constants, strings and call order preserved from `analysis/pseudocode/functions/*.c` and triage call lists.

- 0x52c130: float self-multiply guard (this+0x04 == 0.0)
- 0x52c150: singly-linked append at +0x04 tail
- 0x52d730–0x52d7c0: Miles AIL positional/velocity/cone forwarders
- 0x52dc70: AIL_open_3D_listener_4 gate at +0x38/+0x3c, -1 sentinel
- 0x5302e0, 0x531aa0, 0x534a70, 0x535900, 0x537910, 0x537930: scalar-deleting-dtor pattern (inner call, `if (flag&1) operator_delete`)
- 0x531920: vcall +0x40, conditional float read at +0x7c
- 0x533f30: FUN_00533db0(3) guard + vcall +0xe8
- 0x538370: vtable install PTR_FUN_006c0980, cleanup, delete this[2]
- 0x538410: forward to FUN_00545310
- 0x538f20: range check 4–6 → 1 else 0
- 0x538f40: +0x1c/+0x20 equality → 0 else 1
- 0x539980: refcount decrement at +0x40, virtual call(1) at zero

## Observed
Call targets, offsets (+0x04, +0x0c, +0x38, +0x3c, +0x40, +0x7c, +0x1c, +0x20), constants (0, -1, 1, 3, 4, 6, 0x006c0980, 0x40, 0xe8), and the `&1`/delete shapes above, straight from the corpus.

## Inferred
Scalar-deleting-dtor reading for the span-32 stubs; thiscall/param splits per STYLE (register-only evidence noted in manifest unknowns).

## Blockers
`cl 13.10.3077` is absent on this host — no build, no byte-match, no PASS claimed. All entries `status: unverified`.

## Next
Continue from `QUEUE.json` (933 remaining); larger spans and real-symbol types need REA dossier work.
