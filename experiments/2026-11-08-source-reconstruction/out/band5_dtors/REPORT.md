# band5 scalar-deleting destructors

Status: **UNVERIFIED**. `cl 13.10.3077` absent; no PASS or byte-match claim. Clean-room from the local Ghidra corpus and the class/vtable map.

## Delivered

72 scalar-deleting destructors from the unclaimed band-5 queue (71 high, 1 medium confidence), in `src/band5_dtors_[1-5].cpp`.

Each candidate follows the observed shape:

- vtable store(s) into `*self`,
- class-specific body/member release,
- `test flags & 1` then `operator_delete(self)`,
- plain `RET 0x4`; no return value (`void` `__thiscall`).

`manifest.json` records each address, the vtable entry from `out/classes/vtable-map.json` (e.g. `0x6c5148 -> Class_6c5148`), observed store list, and unknowns. `QUEUE.json` is the parent queue minus every tree claim.

## Observed

- `operator_delete` use, `flags & 1` test, vtable store addresses, and member release order from `analysis/pseudocode/functions/<addr>.c`.
- Multiple/dual vtable stores are retained where the corpus shows them.

## Inferred / unknown

- `__thiscall` is inferred from `in_ECX`; the original symbol and class names are unresolved unless the vtable map has adjacent-string evidence.
- Layout beyond vtable slot 0 and free offsets is unknown; intermediate refcount-held member churn is simplified to an observation comment where the corpus is ambiguous.

## Blockers

1. No VC7.1 compiler, so no compile or byte comparison.
2. No PDB/symbols; most class names are synthetic.
3. The destructor set is a subset of the band-5 cluster; `QUEUE.json` carries the rest.
