# band7_batch1 REPORT (UNVERIFIED)

Observed (shipped bytes + `analysis/pseudocode/functions/*.c` + `analysis/team/band7/deep/*.md` + REA evidence already in `analysis/team/`):
- 18 functions reconstructed from the 1,023-entry band7 slice; 15 smallest-span (11–18) plus the 3 deep-dive addresses 0x00610ba0, 0x00647b28, 0x00672e90. Sources in `src/functions_1.cpp` with `// 0x00xxxxxx` above each definition.
- Ordered by (span asc, address). Matchable = not thunk, not eh-funclet (none marked in triage), pseudocode present, not claimed in any other `out/*/manifest.json`.
- 0x0061288b: shader register-name resolver (shorts v_/r_/c_/b_/i_/s_/o_, counters at this+0x8c..0xac, err 0x7d5 / 0x80040405); 0x00610ba0: 7-bucket case-insensitive lookup via FUN_00610b5f + lstrcmpiA, node next at +0x20; 0x00647b28: frameless field initializer ([2] |= -1, [4]=3, +0x46 word zero); 0x00672e90: 6-constant membership predicate; four refcount increments at +4/+8/+0x24; four terminal tail calls; three arg getters/flag sets.

Inferred: owning-class names (thiscall treated as plain helpers), register allocator / error-helper roles, RegInfo struct shape, HashNode layout beyond +0x00/+0x20, Reset/Init naming for 0x00647b28, switch vs || chain for 0x00672e90.

Blockers: `cl 13.10.3077` is absent — no compile, no PASS, no byte-match claim. Ghidra limitations boilerplate in corpus files not reconstructed.

Next: QUEUE.json holds the remaining 1,005 matchable unclaimed addresses (band7_batch1, count 1005); no address is claimed twice across bands.
