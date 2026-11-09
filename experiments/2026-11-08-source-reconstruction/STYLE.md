# Reconstruction style (unverified candidates)

All output is clean-room and `unverified`; no compiler is available.

## Source shape

- One file per subsystem or 5–20 related functions.
- `// 0x00xxxxxx — observed purpose` immediately above every definition.
- Use `extern "C"` for shipped functions; declarations do not define them.
- Preserve observed offsets as `reinterpret_cast<unsigned*>(base + 0xNN)`;
  prefer byte offsets over invented field names.
- Never define `operator_delete`, CRT symbols, or Win32 imports; declare them.
- Do not add a second definition for an address already in another wave; the
  merge validator rejects duplicate claims.
- If the provider exposes only a register (`in_EAX`, `in_ECX`) and no stack
  entry, record the observed body as a comment instead of inventing a signature.

## Class headers

`reconstruction/include/classes/` uses explicit 32-bit padding. Fields are
placed with `pad_0xNNNN` arrays; do not remove or reorder them. The target is
i386, so `void*` is 4 bytes.

## Manifest

Every entry:
`{address, name, source, signature, confidence, evidence, status:"unverified", unknowns}`.
`evidence` names the pseudocode path or dossier; `unknowns` names the
unresolved type, calling convention, or layout.

## Report

Short observed / inferred / blockers / next sections. State that
`cl 13.10.3077` is absent and no PASS is claimed.
