# band8 wave 5

Status: **UNVERIFIED**. `cl 13.10.3077` is absent; no PASS or byte-match is claimed. Clean-room from `analysis/pseudocode/functions/*.c` and the band 8 dossiers.

## Delivered

20 unclaimed addresses selected small-span first: atexit/CloseHandle teardown group (10 in `band8_wave5_teardown.cpp`) plus scalar leaves, setters, closers, and guarded-delete wrappers (10 in `band8_wave5_leaves.cpp`), each with `// 0x00xxxxxx` comments, observed offsets/constants/call order preserved.

## Observed vs inferred

- Observed: addresses, spans, body shape, vtable/global offsets (+0x1b8, +0x98, +0xc, +8), direct-call order, rounding formula ((p1-1+p2) - (p1-1+p2)%p2), guarded-delete flag test (&1), and globals (DAT_00726x0c/1c/30/5c/64, DAT_008ed540).
- Inferred: C++ signatures (notably `void**` chains and `in_ECX` this-pointers for 0x006a3cfb/0x006b3380), class/field names, and callee arities. The manifest records these as `unknowns`.

## Blockers

1. No VC7.1 compiler, so no compile or byte comparison.
2. No original symbols or PDB types; names remain synthetic.
3. Global-slot teardown stubs expose only pointer stores; slot types and vtable bases are inferred.

## Next

Continue from `QUEUE.json` (725 remaining) with the next-smallest unclaimed addresses; merge validator should accept 20 disjoint entries.
