# band5 wave 3

Status: **UNVERIFIED**. `cl 13.10.3077` absent; no PASS or byte-match claim.

## Delivered

Three small band-5 functions that have corpus files:

| Address | Observed shape |
|---|---|
| `0x005b4100` | calls `0x005b6ee0`, then `operator_delete(self)` if `flags & 1` |
| `0x005b4170` | forwards one stack value to `0x005bbf20`, then calls `0x00545d20` |
| `0x005b4720` | calls `0x005b46d0`, then `operator_delete(self)` if `flags & 1` |

Two queue labels (`0x005b4a00`, `0x005b4d00`) have no pseudocode file and were removed rather than guessed.

## Inferred / unknown

- `__thiscall` follows `in_ECX`; helper arities are inferred from call sites.
- No original symbols, class names, or PDB types.

## Blockers

1. No VC7.1 compiler, so no compile or byte comparison.
2. The two removed addresses need a REA decompile before reconstruction.
