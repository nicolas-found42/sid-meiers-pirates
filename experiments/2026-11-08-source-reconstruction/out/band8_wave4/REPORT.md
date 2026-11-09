# band8 wave 4

Status: **UNVERIFIED**. `cl 13.10.3077` is absent; no PASS or byte-match is claimed. Clean-room from `analysis/pseudocode/functions/*.c` and the band 8 dossiers.

## Delivered

20 unclaimed band-8 addresses selected small-span first, with `// 0x00xxxxxx` comments, observed offsets/constants/strings/call order preserved. `manifest.json` carries each source path and evidence; `QUEUE.json` is the parent queue minus every claim in this tree.

## Observed vs inferred

- Observed: addresses, spans, body shape, vtable/global offsets, direct-call order, and literal strings exposed by the corpus.
- Inferred: C++ signatures, class/field names, and any non-observed callee arity. The manifest records these as `unknowns`.

## Blockers

1. No VC7.1 compiler, so no compile or byte comparison.
2. No original symbols or PDB types; class names remain synthetic except adjacent-string evidence.
3. Some bundled D3DX/zlib functions are third-party code shipped in the image, not game logic.
