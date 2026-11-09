# Band 8 reconstruction report (wave 3)

**UNVERIFIED: cl 13.10.3077 is absent on this host. No candidate is a match; nothing was added to `build/units.json`; no PASS claims.**

## Scope

Parent queue `out/band8_wave2/QUEUE.json` (785, disjoint from the `band8` and `band8_wave2` manifests).
This wave takes the first 20 addresses — 6 D3DX9 shader-opcode forwarders, 8 terminal-call thunks,
an ATL destructor stub, a small forwarder, a vtable-installing constructor, and 3 DeleteCriticalSection
stubs — and writes only `out/band8_wave3/`.

| file | functions | coverage |
|---|---|---|
| `src/band8_shader_leaves.cpp` | 6 | `0x006a6863` (5), `0x006a686d` (0x11), `0x006a692a` (0x10), `0x006a6934` (0x58), `0x006a693e` (0x50), `0x006a6948` (0x23) — all call `FUN_006a629c(code, 0)` |
| `src/band8_thunks.cpp` | 8 | `0x006be2f0`/`0x006be380` → `FUN_004baef0`; `0x006bec20` → `FUN_004d4e00`; `0x006bed60` → `FUN_004ab7c0`; `0x006bef00`/`0x006bef10` → `FUN_0045a050`; `0x006bef80` → `FUN_004c2600`; `0x006bf3c0` → `FUN_004d4be0` |
| `src/band8_rt.cpp` | 3 | ATL dtor on `DAT_00727370` (`0x006bf9d7`), forwarder `0x0068f924` → `FUN_0068f6ce`, constructor `0x006b3910` (vtable `PTR_FUN_006f5310` then `FUN_006b50f0`) |
| `src/band8_critsect.cpp` | 3 | `DeleteCriticalSection` stubs on `DAT_00727404` (`0x006bfa00`), `DAT_00727538` (`0x006bfa10`), `DAT_00727834` (`0x006bfb00`) |
| **manifest total** | **20** | all 20 queue-head addresses, unique, disjoint from `band8` and `band8_wave2` manifests |

Remaining queue (`QUEUE.json` in this directory) = 765 addresses,
disjoint from all three manifests. EH/thunk/phantom spans were already excluded upstream.

## Third-party bundling

As in waves 1–2: `0x006axxxx` is bundled D3DX9 shader-compiler code, `0x006bxxxx`/`0x006bfxxx`
thunks are CRT/ATL teardown leaves, and the ATL destructor references `DAT_00727370` — clean-room
equivalents from shipped bytes + REA pseudocode, not Firaxis game source, and must not be attributed
to the game or Gamebryo. Target symbols `FUN_004xxxxx` are shipped-binary addresses; only the
call shape is reconstructed, not the target bodies.

## Observed vs inferred

Observed: span 10 (shader leaves), 16 (thunks/critsect), 25 (ATL stub), 11 (`0x0068f924`), 704
(`0x006b3910` triage span; decompile body is the 11-byte vtable-install prologue); literal codes
5, 0x11, 0x10, 0x58, 0x50, 0x23 each with second arg 0; terminal-call targets from Ghidra Listing
(`0x6be2f5→0x4baef0` etc., `0x6bf9dc→0x533bb7 ATL::CAtlBaseModule::~CAtlBaseModule`,
`0x68f92a→0x68f6ce`, `0x6b3916→0x6b50f0`); global refs `DAT_00727370/00727404/00727538/00727834`,
`PTR_FUN_006f5310`; each body is a single call (or store+call for `0x006b3910`). Inferred: C++
names/signatures, `this` parameter of `0x006b3910` (pseudocode `in_ECX`), and that thunk targets
are opaque in this wave.

## Blockers / next

No EH/thunk/phantom spans were reconstructed here (excluded upstream in band8_wave2's note). The
`0x006bf3c0` triage span is 80 bytes but the decompiled body is the 10-byte call — the tail bytes
belong to the next function's span and are not claimed. Next wave: the following 20 addresses in
`QUEUE.json` (`0x006bfb10` onward), which include more `0x006bxxxx` thunks/critsect stubs and
shader leaves.
