# band3_wave2 report — unverified

20 smallest unclaimed addresses from `out/band3_batch1/QUEUE.json` (span 26–32), reconstructed clean-room in `src/small_array.cpp` and `src/small_dtors.cpp`. Every definition carries a `// 0x00xxxxxx` comment; offsets, constants, strings and call order preserved from `analysis/pseudocode/functions/*.c` and triage call lists.

- 0x533b9d: zero +0x30/+0x34/+0x38 after FUN_004aba90
- 0x533b80: ATL CSimpleArray RemoveAll (free + zero +0x00/+0x04/+0x08)
- 0x5185c0–0x5271b0 (14): scalar-deleting-dtor pattern (inner call, `if (flag&1) operator_delete`)
- 0x5289f0: refcount decrement at +0x98, virtual call(1) at zero
- 0x529420: store callee result, return 1
- 0x52a800: dword copy loop
- 0x52a870: forward to FUN_0052b030

## Observed
Call targets, offsets (0x30/0x34/0x38, 0x04/0x08, 0x98) and the `&1`/delete and copy-loop shapes above, straight from the corpus.

## Inferred
Scalar-deleting-dtor reading for the span-32 stubs; thiscall/param splits per STYLE (register-only evidence noted in manifest unknowns).

## Blockers
`cl 13.10.3077` is absent on this host — no build, no byte-match, no PASS claimed. All entries `status: unverified`.

## Next
Continue from `QUEUE.json` (953 remaining); larger spans and real-symbol types need REA dossier work.
