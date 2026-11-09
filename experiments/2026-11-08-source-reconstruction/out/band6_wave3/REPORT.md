# Band 6 wave 3 — report

## Observed
- 5 small-span unclaimed functions reconstructed from REA pseudocode: three ECX-as-self slot getters (self+0x14, self+0x00, byte at self+0x10) and two constant/void stubs.
- Offsets, constants (0), and return order preserved verbatim from pseudocode.

## Inferred
- Getter owners are Gamebryo/NiD3D wrapper classes per triage basis; field names not recovered, so reconstructions use `base + 0xNN` with no invented members.
- Stubs likely placeholder/virtual slots; no stores observed.

## Blockers
- `cl 13.10.3077` is absent on this host; this wave is unverified, no PASS, no byte-match claimed.
- Owner-class layouts, vtable slot numbers, and exact calling conventions unverified.

## Next
- Continue smallest-span-first from QUEUE.json; tackle dtor wrappers (SEH/vtable/operator_delete tails) and the cpuid helper (0x5f8ce5) with full pseudocode review.
