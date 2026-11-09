# Band2 wave2b report (UNVERIFIED)

- Toolchain: `cl 13.10.3077` is absent — no byte-match, no PASS claim. All entries unverified.
- Observed: first 20 matchable addresses of out/band2/QUEUE.json (all 20 have pseudocode; only 0x004c3790 had a deep dossier).
- Inferred: register-param conventions (EAX/ECX/ESI/EDI=this), string heap (len at -4, capacity at -8, empty-string sentinel &DAT_008cacc8), vtable slots +0xc/+0x10/+0x1c. Signatures in manifest are hypotheses.
- Blockers: no REA calls beyond corpus; field meanings (+0x24/+0x30/+0x44/+0x7c/+0x84/+0xda8/+0xdbc etc.) unproven; several callees only referenced by address.
- Next: run REA deep dives for the 19 dossier-less functions; verify against classes/vtables in out/classes before any build.
