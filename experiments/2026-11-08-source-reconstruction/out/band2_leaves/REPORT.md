# band2 small leaves

Status: **UNVERIFIED**. `cl 13.10.3077` is absent; no PASS or byte-match is claimed. Clean-room from `analysis/pseudocode/functions/*.c`.

## Delivered

| Address | Observed shape |
|---|---|
| `0x004cd150` | resets a pointer/count pair through EAX; `p[1] = -1` |
| `0x004d0880` | destructor body `0x004d4580`, conditional `operator_delete` |
| `0x004d4600` | clears `+8`, calls `0x004b0650` |
| `0x004d4bc0` | single `RET` |

`0x004cd150` cannot be written portably without the register entry (the provider exposes EAX, not a stack argument); its body is recorded as a comment rather than invented as a callable signature.

## Inferred / unknown

- All class names and the EAX/ECX entry of `0x004cd150` are unknown.
- The two deleting destructors assume `__thiscall` and a one-byte flags argument.

## Blockers

1. No VC7.1 compiler, so no compile or byte comparison.
2. No PDB types or original symbols.
3. `0x004cd150` needs its register entry modeled before it can be a match candidate.

`QUEUE.json` is the band2 parent queue minus every claimed address in this tree.
