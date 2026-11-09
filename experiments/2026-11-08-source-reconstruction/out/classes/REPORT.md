# Class / vtable map — whole image (UNVERIFIED)

> No `cl` 13.10.3077 on this host. Nothing here is matched; no PASS claimed. Clean room: shipped bytes + local Ghidra corpus + adjacent stream strings only. No leaked/unlicensed Gamebryo source used (per clean-room correction, no GitHub mirror consulted). Only `experiments/2026-11-08-source-reconstruction/out/classes/` written.

## Observed (bytes / corpus)

- `Pirates!.exe` SHA-256 `6e88b90e…7c9` (PE32, image base `0x400000`; `.text 0x401000–0x6c0000`, `.rdata 0x6c0000–0x717000`, `.data 0x717000+`). `build/functions.json`: 8,181 Ghidra functions.
- True vtable installs: corpus `*in_ECX = &PTR_FUN_…` — **564 distinct stored vtable addresses, 932 store sites** across the 8,181-file corpus (some funcs store twice). Every stored address points into `.rdata` (rows `0x6c…`) or `.data` (`0x71…`), and is followed by ≥1 `.text`-range dword (checked in binary).
- Vtable bytes: slots are runs of `.text`-range dwords starting at the stored address. Where the next stored address falls inside a run, the run is split there (sub-table / secondary base): **316 of 562 kept classes are length-bounded this way**; the rest (246) have run-length = run of `.text` dwords but no interior stored boundary, so lengths are less certain (concatenated tables may inflate them; flagged `length_bounded=false`).
- RTTI: **absent** for game/engine classes. Binary scan finds only four `.?AV` strings: `type_info` (`0x7187e8`), `exception` (`0x727110`), `logic_error@std` (`0x727128`), `length_error@std` (`0x727148`). Consistent with `/GR-`. Class names therefore come only from adjacent stream strings in `.rdata`.
- Adjacent-name layout: where present, the class-name string ends at a 4-byte alignment with the vtable at `align(string_end)`. E.g. `NiObject` at `0x6c0a04` → vtable `0x6c0a10` (13 slots: `0x5396b0, 0x5390a0, 0x538350, …`); `NiCamera` at `0x6c0974` → `0x6c0980` (20 bounded slots); `NiPixelData` at `0x6c0a44` → `0x6c0a50` (15 slots). Verified by byte dump.
- Deferred dispatch quads excluded (stored `*in_ECX` but ~period-4 repeated heads, shader-compiler tables): runs at `0x6dde4c` (100 dwords) and `0x6ddfe0`. Their stored addresses are not claimed as classes.
- Long (≥40-slot) unbounded runs (e.g. `0x6c8798` 87) are kept but flagged low confidence — likely concatenation with unstored tables.
- Deleting-destructor shape (`operator_delete` + `(param_1 & 1)` in corpus body): present among store funcs for **324 of 562** classes.
- Member offsets: `in_ECX[0x…]` accesses collected per storer func (163 distinct dword indices image-wide); each header lists its class's observed indices.

## Inferred

- **51 classes carry an adjacent identifier** (32 `Ni*` stream names + 19 others). `Ni*` names: treated as **high** confidence (stream class vocabulary matches the binary's own `NiMain Gamebryo Version 10.1.0.0` / `NiDX9*` strings). Non-`Ni` adjacent identifiers (`WinClass_FXS`, `MAIN`, `IniParser`, `Landscape`, `PURE`, `VOID`, …) are **low** confidence: adjacency may be coincidence (e.g. `WinClass_FXS` is a window class, not a C++ class). They are recorded in the map for completeness with tiers.
- Everything else: stable synthetic names `Class_<addr>`; confidence medium (bounded, ≥2 slots) or low (unbounded long / single-slot). Unnamed classes live in `include/vtable_6c.h`–`vtable_71.h`, `vtable_70.h`, `vtable_71.h` by address region.
- `base_candidate`: for bounded classes, another class whose slots match ≥60% of non-slot0 entries (≥3 equal) — **149 classes** have one. Pure slot-share signal, not proven inheritance (e.g. `NiCamera → 0x6c179c`); not claimed as hierarchy.
- Filler slots (`0x5f090c`, `0x513ce0`, `0x4aaef0`, `0x57eca0`, `0x5c8c10`) recur across tables; they are recorded verbatim, not decoded (likely pure-virtual / terminator stubs — unproven).

## Unknowns (explicit)

- Original class names for the ~511 unnamed classes (no RTTI).
- Full member layouts (only observed accesses; adjacent unobserved fields unknown).
- True base/derived hierarchy and multiple-inheritance secondaries (interior stored addresses are listed as separate entries; whether they are bases or independent classes is undecidable from these bytes alone).
- Whether slot 0 is the deleting destructor for each class (checked only via storer-func shape; slot-0 vs interior `RET 4` forwarder cases unresolved).
- Vtable length for the 246 unbounded classes.
- Meaning of the `0x70…–0x71…` unnamed block (likely game classes vs. engine/D3DX — no strings to decide).

## Counts

| item | n |
|---|---|
| distinct stored vtable addrs | 564 |
| classes kept (excl. 2 dispatch quads) | 562 |
| named by adjacency | 51 (32 Ni*, 19 other) |
| unnamed (synthetic) | 511 |
| length-bounded | 316 |
| with base candidate (inferred) | 149 |
| with deleting-dtor storer | 324 |
| headers | 57 (51 named + 6 regional) + this report + maps |

## Next batch

Prioritised `QUEUE.json` (265 entries, bounded ≥2 slots by slot count), e.g. `0x6c8d78` (69 slots), `0x6c48d8` (52), `0x710c40`/`0x710d08` (50), … Second wave: split the 246 unbounded runs at heap/member-evidence boundaries; resolve interior stored addresses as secondary bases vs. independent classes; validate non-`Ni` names against `xrefs` (REA read-only) before promoting them above synthetic.
