# Band 6 reconstruction report (wave 2)

Image: `Pirates!.exe` SHA-256 `6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9`, PE32 i386, base `0x400000`.
Range: `0x005db0a0-0x0061003c`.
Status: **UNVERIFIED** — no cl 13.10.3077 on this host; no PASS claims; `src/` and `build/units.json` untouched.

## Batch delivered (20 functions in 2 files)

| File | Addresses |
|---|---|
| `src/band6_wave2_hlsl.cpp` (5) | `0x0060d3ea`, `0x0060e4ea`, `0x0060e723`, `0x0060eb43`, `0x0060f155` |
| `src/band6_wave2_wrappers.cpp` (15) | `0x005db0a0`, `0x005db500`, `0x005db620`, `0x005db6c0`, `0x005db710`, `0x005db750`, `0x005db7b0`, `0x005db830`, `0x005dbaf0`, `0x005dbb20`, `0x005dbc50`, `0x005dbd00`, `0x005dbd70`, `0x005dbd80`, `0x005dbe20` |

Manifest count (20) equals source function count (20). `QUEUE.json` holds the
remaining 891 matchable addresses (parent 911 minus these 20), disjoint from
every `out/*/manifest.json`.

## Observed (grounded in corpus / triage)

- HLSL preprocessor (`0x60d3ea`, `0x60e4ea`, `0x60e723`, `0x60eb43`, `0x60f155`):
  all high confidence. `0x0060d3ea` stores macro entries in hash buckets at
  `this+0x6c` with sorted strcmp insertion; on equality it emits
  `"'%s' : macro redefinition"` (line `0x5ef`), unlinks the old entry and calls
  `FUN_0060d270(1)`.
- `0x0060e4ea` seeds predefined defines `DIRECT3D`, a `DAT_006de46c` entry,
  `DIRECT3D_VERSION`, `D3DX_VERSION` using 0x14-byte entries from
  `FUN_00533c78`, vector seed `{2,0,0x900,…}` (then `0x902`), prior-+0x26c
  save/restore, and a file-list loop calling `FUN_0060f7b4`/`FUN_0060e245`.
- `0x0060e723` is the yacc reduce dispatcher: 0x00-0x2e operator switch over
  stack cells at +0x5c/+0x60, error strings `"internal error: stack underflow"`,
  `"Stack"`, `"internal error: out of memory"`, `"division by zero in
  preprocessor expression"` (line `0x5df`).
- `0x0060eb43` (1.3 KB) is the yacc goto/shift driver with tables in
  `0x00719xxx`/`0x0072a6xx`, strings `"syntax error"`, `"yacc stack overflow"`.
- `0x0060f155` dispatches next tokens, `#`-directive handling into
  `FUN_0060eb43`, strings `"unexpected end of file"` (`0x5de`), `__FILE__` /
  `__LINE__`, `"unexpected tokens following preprocessor directive"` (`0x5dd`).
- NiD3D wrappers (`0x5db0a0`-`0x5dbe20`, medium): `0x005db0a0` initializes
  virtuals `+0x60/+0x78/+0xc4/+0xe8` then 23 `+0x70` setter calls;
  `0x005db500`/`0x005db710`/`0x005db7b0` share the dtor sequence (vtable
  `0x006c8d78`/`0x006c8e8c`, global slot `0x007275fc+0x60`, vtable
  `0x006fd148`, refcount `0x00727444`); `0x005db620` is a 36-byte field-copy
  with cache key at +0x5c; `0x005db830` builds six zeroed channel arrays;
  `0x005dbaf0` is a `FUN_00533c78(0x88)` allocator wrapper; `0x005dbb20`
  flushes six ranges via virtuals `0x178-0x1c4`; `0x005dbd00` fetches through
  virtuals `+0x18/+0x34/+0x54`; `0x005dbd70`/`0x005dbe20` return fields
  `+0xc`/`+0x10`; `0x005dbd80` is an owned-string setter at +0xc.

## Inferred (hypotheses — not proven)

- All `Band6Wave2_*` / `Hlsl_*` C++ names, class layouts, and call-target
  signatures are clean-room placeholders. `0x0060e4ea`'s `DAT_006de46c`
  entry name is observed only as an address; `FUN_0065ae50` receives a
  reconstructed `{2,*,0x900}` vector whose component semantics are unknown.
- `0x0060e723` reconstructs only the pop/switch/push skeleton: several
  operator cases (string ops, `0x2c-0x2e`) are reduced to stack bookkeeping;
  `0x0060eb43`'s goto/shift tables are data — the driver is documented, not
  a full yacc table transclusion.
- `0x005db830`'s six array allocations are stride-compressed (observed
  `count*0x10` and `count*4` pairs collapsed); paired-slot indexing for the
  second allocation in each pair is approximate.
- `0x005dbb20` device getter at +0x80 and virtual indices are inferred from
  pseudocode offsets; caller param types unknown. `0x005dbd00`'s
  `uStack00000000` out param is modelled as a single byte.

## Counts / blockers / next

- This batch: 20 functions (5 high-confidence HLSL, 15 medium wrappers).
- Remaining queue: 891 addresses in `QUEUE.json` (next after this wave:
  `0x005dbe30`, `0x005dbe40`, `0x005dbe60` … in parent order).
- Blocker: no cl 13.10.3077 — all 20 are UNVERIFIED; hand to a VC7.1 host.
  Owner-class layouts for the `0x6c8exx`/`0x6c8d78`/`0x6fd148` vtables remain
  unrecovered; yacc tables unrecovered.
