# Pirates! decompilation tree

Decompiler-derived source reconstruction of the shipped `Pirates!.exe` (PE32
i386, SHA-256 `6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9`).
This is not the original source, and no function here is byte-matched.

## Complete decompilation

The Ghidra 12.2 pass covers **every analyzed function**:

| Corpus | Count | Evidence |
|---|---:|---|
| internal functions | 8,181 | one `.c` file per function under `analysis/pseudocode/functions/` |
| external imports | 341 | `analysis/pseudocode/decompile-index.json` |
| inventory functions lacking pseudocode | 0 | `tools/build_decompile_index.py` |

The corpus lives under the ignored analysis root because it is large and
regenerable. A tracked address/name/hash index is at
[`decompilation-index.json`](decompilation-index.json); it is built by:

```sh
python3 tools/build_decompile_index.py
```

That command re-hashes all 8,181 files, checks them against the inventory, and
prints `status: complete`.

## Readable C++ candidates

`src/<wave>/` holds reconstruction attempts on top of the corpus:

| Item | Count |
|---|---:|
| matchable functions | 7,862 |
| claimed candidates | 683 |
| full-body candidates | 607 |
| partial skeletons | 76 |
| remaining queue | 7,179 |
| class/vtable records | 562 |
| class headers | 57, 562 structs |

Every candidate is `status: "unverified"`. The target compiler
(`cl 13.10.3077` / `link 7.10.3077`) is absent on this host, so there is no
compile, byte comparison, or `PASS`.

| Path | Contents |
|---|---|
| `src/<wave>/` | C++ approximations, one shipped address per function |
| `manifest.json` | per-function address, source, signature, evidence, confidence, unknowns |
| `QUEUE.json` | matchable functions not yet claimed |
| `include/classes/` | 57 class headers with explicit 32-bit padding |
| `include/vtable-map.json` | 562 vtable/class records |
| `DECOMPILATION.md` | complete 8,181-function index with links and byte spans |
| `decompilation-index.json` | complete inventory index with pseudocode hashes |
| `INDEX.md` | generated coverage table and per-wave counts |

## Rebuild and validation

```sh
python3 tools/recon_status.py          # manifests, duplicates, address-in-source audit
python3 tools/check_class_layout.py    # 57 headers, 1,188 field offsets
python3 tools/build_decompile_index.py # complete corpus verification
python3 tools/merge_reconstruction.py  # regenerate src/, manifests, INDEX.md
```

`recon_status.py` now rejects an entry whose declared source does not contain
its shipped address. Partial bodies are counted separately and not silently
promoted to full candidates.

## Legal and evidence boundary

The repository contains addresses, names, reconstructed source, and tools. It
does not contain the game image, assets, extracted DLLs, object files, or PDB
files. No unlicensed Gamebryo source was used. The pseudocode is
decompiler-derived evidence about the shipped bytes, not original source.
