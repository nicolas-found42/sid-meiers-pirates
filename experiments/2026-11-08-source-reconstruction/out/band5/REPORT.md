# Band 5 reconstruction report — 0x00591460–0x005dab60

## Scope

- Band: `band5`, 1,023 functions in slice (1,012 matchable, 11 thunks).
- This batch: **37 functions reconstructed** (3.7% of matchable). Remaining **975 matchable** in `QUEUE.json`.
- Output: `experiments/2026-11-08-source-reconstruction/out/band5/{manifest.json, QUEUE.json, REPORT.md, include/band5.h, src/band5.cpp}`.
- Status: all `unverified`. **No PASS. No byte-match.** `cl` 13.10.3077 absent. No `src/` or `build/units.json` edit.

## Triage limitation (read first)

`triage.json` labels 999/1,023 as `game` with `low` confidence — it is a **fallback default** ("no distinguishing strings; default game code per range"), not subsystem evidence. Only 13 functions carry string evidence (11 `gamebryo`, 2 `platform`) and 11 are thunks (`high`). The true D3D9/Gamebryo footprint in this band is far larger than 13: the corpus exposes at least 19 functions with `Ni*`/`D3D*`/`Creation failed` strings and 2 standalone HRESULT/D3DFMT name tables (60 + 24 cases) that triage marked `game`. Every reconstruction below was re-derived from `analysis/pseudocode/functions/*.c` (plus the three `deep/` dossiers), **not** from triage labels. Triage category/confidence is carried in `manifest.json` for audit only.

## Real clusters (observed, not triage)

Corpus scan of all 1,012 matchable bodies:

| Cluster | Size in band | Signal | Semantics |
|---|---|---|---|
| MSVC scalar-deleting dtors | 125 | `operator_delete__` + vtable store | Each is `??_G<class>@@EAEPAXH@Z`-pattern, most via `FUN_005e1490`. One representative (`0x005c00c0`) in this batch; the other 124 stay queued (mostly P1, 32-byte bodies). |
| Vtable-store ctors / dual-store | ~116+ | `*this = &PTR_FUN_006cXXXX` | Related constructors and base-class forwarding. Highest-frequency tables: `0x6c86b4` (13), `0x6c5350` (10), `0x6c7df4`/`0x6c824c` (8 each). |
| `FUN_00533c78` alloc wrapper | 201 refs | Called in this band far more than any other | Heap allocator used by D3D managers; central callee. |
| `FUN_005e1490` destroyer | 120 refs | Destructor tail for the 125-clump | Likely shared base-class/map destructor. |
| `FUN_005d7d70` + `FUN_0059c730` | 100 / 74 refs | Cross-cutting helpers | Unresolved; queue candidates. |
| D3D9 device / texture / index-buffer managers | ~19 with direct strings + `0x005cb9d0`/`0x005d8450` tables | `Creation failed: ...`, `NiDX9*`, `D3DERR_*`, `D3DFMT_*` | e.g. `0x005c5ec0` device factory, `0x005ce8a0` texture copy, `0x005d0850` index-buffer pack. Only the two name tables + loader + factory are in this batch. |
| Refcount-at-`+0x68` / `FUN_005bf480` family | 13 in-band callers of `0x5bf480` | `DEC/INC *(ptr+0x68)`, cached-pointer resync | `0x005da3a0`, `0x005da3e0`, `0x005bf480`, `0x005bf670` in this batch. |
| Dispatch tables `DAT_00728b00..0c` | 4 (+ 2 fn-pointer guards) | `vt[3]()` index, `*4` table load, 5/7/10/12-arg tails | All 6 in this batch — the clearest cluster in the band. |
| Global dword accessors | 7+ | Single `DAT_` load/store, 16–48 bytes | All tiny global getters/setters observed in-band are in this batch (`0x005be9xx`, `0x005bfa10`, `0x005bd940`, `0x005be890`, `0x005d7d60`). |
| `DAT_00728e2c` users | 3 | Same global touched 156× across band | Likely a shared manager/context; queue. |

## This batch (37)

- **Dispatch (6):** `0x00591460` (5-arg 6×6, `72 8b00`), `0x005914e0` (10-arg 6×6, `72 8b04`), `0x00591590` (7-arg, `72 8b08`), `0x005915d0` (12-arg, `72 8b0c`), `0x00591630`/`0x00591640` (null-guarded fn-ptr calls). Strongest evidence in band: pure table dispatch, no unresolved heap/global traffic.
- **Global accessors (7):** `0x005be900/10/20` setters for `0x717c64/68/6c`; `0x005bfa10`→`72 8d80`, `0x005bd940`→`72 8cf4`, `0x005be890`→`72 8cfc` getters; `0x005d7d60` setter for `72 8eb4`.
- **D3D platform (6):** `0x005c0650` lazy `D3D9.DLL`/`Direct3DCreate9` (the one function whose call is fully observed); `0x005c5ec0` 1,520-byte device factory (**semantic-only, low confidence** — see unknowns); `0x005bfe80` identity 0–16, `0x005bff40` pow2 map, `0x005d8450` HRESULT names (24 cases, `UNKNOWN!`), `0x005cb9d0` D3DFMT names (60 cases incl. FourCC, `UNKNOWN`).
- **Refcount/pool (4):** `0x005da3a0` resync→`+0x38`, `0x005da3e0` advance variant, `0x005bf480` multi-slot release, `0x005bf670` pool pop (INC-then-DEC quirk preserved).
- **Helpers (8):** `0x005bfa20` error-string setter, `0x005bf9b0`/`0x005bf9e0` 12-byte table R/W at `72 8d08`, `0x005bf990` 8-byte pair read, `0x005bfb30` checked array fetch, `0x005bff90` adapter mask, `0x00594f50` tri-state, `0x0059fcc0` emptiness.
- **CRT wrappers (3):** `0x005c9a50` `vsprintf`/`1024`, `0x005c9a80` `_splitpath`→1, `0x005bfe40` `{0x46,0x49,0x50}`.
- **Lifecycle (3):** `0x005c00c0` scalar-deleting dtor for vtable `0x6c7200`, `0x005c86f0` release `72 8de4`, `0x005c8c10` prepend onto `72 7868`.

Confidence split: `high` 26, `medium` 7, `low` 4. `manifest.json` carries per-function `confidence`, `evidence`, `unknowns`, `span`, and the triage label it disagrees with where relevant.

## Observed vs inferred

**Observed (corpus/assembly):**

- Dispatch indices, strides (`*4`, `*6`), table bases, arg counts, null-fallback arg swaps; `DAT_00728e2c`/`FUN_005e1490`/`FUN_00533c78` frequencies above are counts over the 1,012 corpus bodies.
- Scalar-deleting destructor shape (`*this = vt; call destroyer; free +offset; if (flag&1) delete this`) in 125 bodies; `0x005c00c0` additionally observed via deep dossier (`RET 0x4`, vtable `0x6c7200`).
- D3D loader call sequence and all string literals (`D3D9.DLL`, `Direct3DCreate9`, four `Creation failed: ...`, all `D3DERR_*`/`D3DFMT_*` names) — quoted verbatim in `src/band5.cpp`.
- Refcount offset `+0x68` and destroyer `0x5bf480` in the 13-function family; pool header shape at `DAT_00728d04`.

**Inferred (not verified):**

- C/C++ signatures (thiscall/cdecl, `void*` vs `int` return, `Ref80.count` type). The `FUN_005d8450`/`0x5cb9d0` maps are byte-exact as value→string tables but the original switch spelling (which the decompiler normalised to `if` cascades) is not recovered.
- `0x005c5ec0` is a deliberate **semantic-only** placeholder: the 13-parameter factory body is large with unresolved thiscall/vtable traffic. It is the only `low`-confidence dispatch in the batch and should be treated as a queue-grade skeleton, not a match candidate.

## Blockers

1. **No toolchain:** `cl` 13.10.3077 / `link` 7.10.3077 absent — nothing compiles byte-identical; no PASS.
2. **No types:** every `FUN_*` name, class, vtable owner, and `DAT_` global is inferred from offsets. `0x005c5ec0` unknowns (13 params, adapter/device validation) are the largest single gap.
3. **Indirect callees:** `FUN_005e1490`, `FUN_005bf560`, `FUN_005ca660`, `FUN_0055f300` and the `vt[3]` slot-`0x0c` implementations are outside this batch.
4. **Triage depth:** string evidence covers 13/1,023; the 999 `game` labels cannot drive subsystem assignment. A string+xref re-triage is needed before claiming cluster membership for queued items.

## Next batch (QUEUE.json, 975 remaining)

- **P1 (small ≤48, ~127 remaining after this batch):** the 124 unclaimed scalar-deleting dtors (32 bytes each — mechanical), `0x005c9270` lazy-init guard, `0x005c86f0`-style global releases, and the remaining 16-byte global accessors (`0x005ae050` jumptable, `0x005cce50`, `0x005cd3c0`, `0x005d01f0`). These need only the vtable/friend vtable names to be useful.
- **P2 (medium 49–192):** `0x005c9fe0`/`0x005ca020` doubly-linked removal pair, `0x005c8780`/`0x005c87c0` `FUN_005bd960` adapters, `0x005c9050`/`0x005c9080` `72 8de4` dispatchers, `0x005bf090` unique-insert-with-grow, `0x005cc1b0`/`0x005cc240` format finders called from the device factory.
- **P3 (heavy 193–512):** the remaining `NiDX9*` managers (`0x005cead0`, `0x005cf2c0`, `0x005cf3d0`, `0x005d09a0`, `0x005d0b50`, `0x005d1280`, `0x005d1640`, `0x005d18e0`, `0x005d20e0`) — each is a self-contained D3D copy/create/pack variant.
- **P4 (large >512):** `0x005a57f0` (11,632), `0x0059ce10` (6,384), `0x0059b000` (5,520), `0x005d4520` (3,712), `0x005a4c20`, `0x005b2100`, `0x005c2c50` — decompose callees first; do not attempt whole-function reconstruction.

QUEUE guarantees: unique, in-slice, disjoint from this manifest, union == 1,012 matchable. Priority order is small-first, then address.
