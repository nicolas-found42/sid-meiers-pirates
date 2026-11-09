# Band 1 wave 3 — 20 reconstructions (unverified)

Status: **unverified**. No PASS claim. `cl 13.10.3077` is absent on this host, so nothing here compiles to a byte-comparable image and nothing was added to `src/` or `build/units.json`. All reconstructions are clean-room from shipped bytes (Ghidra 12.2 corpus `analysis/pseudocode/functions/<addr>.c`) plus `analysis/team/band1/triage.json`; no external sources were consulted.

## Observed vs inferred

- **Observed:** spans 16–32, body ranges, call order, literal constants (`0`, `3`, `0xec`, `+0x20`/`+0x22`, `+0x68`, `+0xef=1`, `+0x2c`/`+0x0c`, `0x4abb3b` terminal call), vtable pointers (`PTR_FUN_0070bf4c`, `PTR_FUN_0070c4d0`), save-stack idiom (`DAT_007268f4`/`DAT_00726a84`/`DAT_007263bc`), `SetCursor(*EAX)`, deleting-destructor `flags & 1` tail.
- **Inferred:** every signature, parameter name, global type/layout, callee arity, `*_recon` wrapper names. `DAT_*`/`FUN_*` are corpus labels. Register-only inputs (`EAX`/`ECX`/`EDX`/`EDI`) are taken as explicit arguments and flagged in `unknowns`.

## Counts

- Parent queue `out/band1/QUEUE.json`: 985 entries (bare list of `{address,priority,reason}`).
- This wave: **20 functions** in 4 files under `src/` (`deleting_dtors.cpp` 8, `small_leaves.cpp` 7, `mem_init.cpp` 3, `stack_ops.cpp` 2). `manifest.json` has 20 entries.
- `QUEUE.json`: parent minus all `out/*/manifest.json` claims (including this wave); remaining length in file.

## By subsystem

- Deleting destructors: 0x0042c110, 0x004313a0, 0x0045a100, 0x004ab0b0, 0x004b1030, 0x004ba8c0, 0x004c2930, 0x004c2af0.
- Small leaves: 0x004b2160, 0x00412da0, 0x004aaef0, 0x004a1050, 0x004abb30, 0x004c2d70, 0x004c2df0.
- Object init: 0x004aaea0, 0x004b9780, 0x004b97a0.
- Save-stack: 0x004ae700, 0x004ae720.

## Blockers

- No VC7.1 toolchain (`cl 13.10.3077` absent); no compile or byte-compare; all entries remain `unverified`.
- Register conventions, helper arities, and object layouts beyond observed offsets are ambiguous in the corpus; flagged in `unknowns`.

## Next

Take the next unclaimed head of `QUEUE.json` (parent minus wave claims), preferring small span + high string count first. No address is claimed twice.
