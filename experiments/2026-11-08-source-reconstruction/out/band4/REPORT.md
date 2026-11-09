# Band 4 reconstruction report — batch 1

Status: **UNVERIFIED**. No `cl 13.10.3077` on this host, so nothing is byte-matched and no PASS is claimed. `src/` and `build/units.json` were not edited. Clean-room from shipped bytes, local Ghidra corpus, and band 4 dossiers.

## Delivered

- 43 matchable functions in `src/` across collision kernels, collision enum stringifiers, deleting destructors, fog enum formatting, factories/forwarders, keyed insert, KFM helpers, property formatting, refcount helpers, slot access, and vtable init.
- `manifest.json` is generated from the `// 0x00xxxxxx` shipped-address comments in `src/*.cpp`; each entry names the source file and remains `unverified`.
- `QUEUE.json` holds the remaining 969 matchable band-4 addresses (1,012 matchable minus 43 claimed), disjoint from this batch and other reconstructed waves.

## Observed

- Address, source span, and function body ranges from `analysis/team/band4/triage.json` and `analysis/pseudocode/functions/<addr>.c`.
- Vtable stores, argument counts, constants, string literals, and direct-call order are preserved where the corpus exposes them.

## Inferred / unknown

- All C++ signatures, class/field names, helper arities, and `DAT_*` meanings are placeholders. This batch carries no original symbols and no PDB types.
- Large collision/KFM builders were deferred; only bodies with defensible local shape are included.

## Blockers

1. No VC7.1 compiler: no compile, no byte compare, no PASS.
2. No original class/field types; several helper calls are typed as `void*` wrappers.
3. Indirect callees outside band 4 remain unresolved.

## Next

Take `QUEUE.json` head, preferring small collision/KFM leaves and deleting destructors; wave 2 is owned by `out/band4_wave2/`.
