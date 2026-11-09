# Band 6 wave 4 — report

## Observed
- 20 small-span unclaimed functions reconstructed from REA pseudocode in the `0x5dbxxx` NiD3D shader-wrapper cluster: 5 scalar stores (`0x5dbe40` two-slot `+0x10/+0x14`; `0x5dbe90` `+0x24`; `0x5dbec0` `+0x28`; `0x5dbed0` `+0x2c`; `0x5dbee0` `+0x30`), 1 byte store (`0x5dbf00` `+0x24`), 5 slot getters (`0x5dbfa0` `+0x2c`; `0x5dc010` `+0x30`; `0x5dc070` `+0x34`; `0x5dc0e0` `+0x38`; `0x5dc150` `+0x3c`), 4 owned-string setters (`0x5dbf40` `+0x28`; `0x5dbfb0` `+0x2c`; `0x5dc080` `+0x34`; `0x5dc0f0` `+0x38`) freeing via `operator_delete__` and copying via `FUN_00533c78` with self-assign guard, 2 refcounted iface slots (`0x5dc020` `+0x30`; `0x5dc160` `+0x3c`, Release via vtable `+8`, AddRef via `+4`), 1 hub query (`0x5dce00`, virtuals `+0x18/+0x34` + `FUN_005de050`), and 2 dtors (`0x5dd4e0` core, `0x5dd520` deleting-dtor with `operator_delete` declared only).
- Offsets, constants (0/1, vtable `0x006c9270`, refcount `+0x44`), string copy loops, and call order preserved verbatim from pseudocode.

## Inferred
- Owner-class layouts and field names not recovered; reconstructions use `base + 0xNN` with no invented members.
- `FUN_00533c78` is allocator-like (owned-string duplication); `FUN_005de050`, `FUN_005ce760`, `FUN_005ce790` targets unverified; `operator_delete`/`operator_delete__` declared, never defined.

## Blockers
- `cl 13.10.3077` is absent on this host; this wave is unverified, no PASS, no byte-match claimed.
- Owner-class layouts, vtable slot numbers, and exact calling conventions unverified.

## Next
- Continue smallest-span-first from QUEUE.json (866 remaining); next `0x005dbe60` deleting-dtor wrapper.
