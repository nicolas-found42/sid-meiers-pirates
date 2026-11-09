# Band 2 reconstruction — batch 1 (unverified)

Scope: 10 functions from `analysis/team/band2/deep/*.md` (17 dossiers) and 4 existing candidate files in `analysis/team/band2/candidates/`. Clean-room, from shipped bytes + corpus pseudocode only. No leaked Gamebryo source used. No `src/` or `build/units.json` edits.

## Observed vs inferred

### Observed (shipped bytes / REA / corpus)
- Band 2: 0x004c3790–0x00514090, 1,023 entries in `slice.json`; 1,021 matchable; 2 thunks excluded: 0x004fca70, 0x004fcad0.
- Batch-1 addresses and their observed bodies:
  - 0x004c3a20: 34-byte leaf, `[EAX+0x88]/[EAX+0x8c]` vs `DAT_008dc30c/008dc310`, returns 0 iff both equal else 1; caller 0x4c69f0.
  - 0x004d5850: 6-byte leaf `MOV EAX,7; RET`; caller 0x50b1d0.
  - 0x004f4e50: 15-byte leaf `*(this+0x2c)==0 ? *(this+0x24) : *(*(this+0x2c)+0x18)`; caller 0x51a960.
  - 0x004f8bc0: 12-byte forwarder to `OutputDebugStringA` IAT 0x006c0134; callers 0x4f8b80, 0x4f8e40.
  - 0x0050b060: 15-byte `RET 4`, `(u16)v % *(this+4)` via MOVZX/XOR/DIV; caller 0x509970.
  - 0x00513ce0: 3-byte `RET 4` empty stdcall stub (1 arg).
  - 0x004ccc10: MSVC scalar-deleting-dtor idiom, ECX=this, RET 4, callee 0x4cd250 + `operator_delete` 0x5f08d6.
  - 0x004f7dc0: 60-byte vtable-swap deleting dtor, vtables 0x710678/0x71065c, callees 0x4e6420/0x5f08d6/0x5f08dc.
  - 0x00514060: 44-byte single-vtable deleting dtor, vtable 0x711994, `operator_delete([ESI+4])`.
  - 0x00500460: shader-lib dispatch: `strstr(name,"NiD3DXEffectShaderLib")`→0x5e0220, else `strstr(name,"NSBShaderLib")`→0x5e7c90, else 0.
- Full dossiers: `analysis/team/band2/deep/<address>.md`; pseudocode: `analysis/pseudocode/functions/<address>.c`; reuse of 4 existing candidates (`0x004d5850_return7.cpp`, `0x004f4e50_fieldgetter.cpp`, `0x004f8bc0_trace.cpp`, `0x0050b060_modulo.cpp`) as cross-checks.

### Inferred (types/names/signatures)
- All C++ types, struct/class names, and decorated symbols in `src/band2_batch1.cpp` and `manifest.json` are hypotheses only.
- Deleting-dtor functions (0x004ccc10, 0x004f7dc0, 0x00514060) are described as hand-authored dtor source; the shipped bytes are VC7.1 compiler lowering (`delete` on heap objects) and cannot be reproduced by the handwritten body alone.
- `game`/`platform` triage labels from `triage.json` are low-confidence fallback labels, not subsystem proof.

## Counts
- Manifest: 10 functions, all `status: "unverified"` (no PASS claim; `cl` 13.10.3077 absent).
- QUEUE.json: 1,011 remaining matchable addresses (1,021 matchable − 10 done), unique, in-slice, disjoint from manifest. Thunks 0x004fca70/0x004fcad0 excluded (not matchable).
- Every source function carries its shipped address in a comment and in `manifest.json`.

## Blockers
- No `cl` 13.10.3077 on this host → nothing byte-matched, per campaign README.
- Register-param conventions (EAX/ECX/EDI/ESI) and owning classes for dtors remain unresolved.
- Selected batch deliberately avoids complex multi-hundred-byte functions (e.g. 0x004f48a0 window creation, 0x005002f0 D3D9 probe, 0x004c82b0 scrollbar factory) — their sketches in dossiers are left for an accurate next wave.

## Next batch
- From QUEUE.json priority order (address order): small leaves first (span ≤ 48, leaf, no-unresolved-ref clusters), then Win32 platform cluster (0x4fxxxx `RegisterClassExA`/`CreateWindowExA` callers) and D3D adapter cluster (0x005002f0 18 callers). Resolve caller 0x4c69f0 for 0x004c3a20 and dump vtables 0x710678/0x71065c/0x711994 to pair deleting dtors with sibling ctors.
