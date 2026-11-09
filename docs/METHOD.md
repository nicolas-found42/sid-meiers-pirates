# Matching method

## Goal

Reconstruct C++ translation units that compile — with the original toolchain — to the exact bytes of the shipped `Pirates!.exe`. Success is a function-level byte match against the image, not a plausible decompiler listing and not a playable port. Building the project produces object files to compare; it does not produce a game.

The image is fixed by SHA-256 `6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9`. Any other image is a different state.

## Unit model

`build/units.json` owns the claim set. Each unit is one translation unit:

```json
{
  "id": "area-name-address",
  "source": "src/area/Name.cpp",
  "flags": ["/O2", "/MD", "/DNDEBUG", "/DWIN32"],
  "functions": [
    {"symbol": "?DecoratedSymbol@@...", "address": "0x00401000"}
  ],
  "data": {"?some_symbol@@3HA": "0x006c1234"},
  "externals": {"__imp__CloseHandle@4": "0x006c0f00"}
}
```

- `functions[].symbol` is the exact symbol name the compiler emits into the COFF object (decorated for C++). `address` is the shipped image address of its entry.
- `data` maps object symbols referenced by the function to declared image addresses. A function that references data cannot be relocated without these addresses.
- `externals` maps undefined symbols (usually `__imp__` IAT slots) to image addresses. Imports can be derived from the PE import table.
- One unit must not claim the same address twice, and two units must not claim the same address. `tools/match.py check` enforces both.
- Prefer one COMDAT section per function (`/Gy`) while exploring. The matcher derives one base address per object section; two functions from the same section must agree on that base.

## Loop

1. Pick an unclaimed address from `build/functions.json`. Small leaf functions and address-taken functions are easiest; heavily inlined template code is hardest.
2. Inspect it in Ghidra (REA is retained in `analysis/`): pseudocode, assembly, callers/callees, string references, RTTI, and the surrounding functions.
3. Write the smallest C++ definition that explains the observed operations, not the decompiler's variable names.
4. Declare the unit with the exact symbol, address, and candidate flags.
5. Compile with `cl` 13.10.3077 under Wine and compare:

   ```sh
   python3 tools/match.py compare --image "<image>" --unit <id>
   ```

6. On mismatch, read the first differing offset. Typical causes, in order:
   - calling convention or argument count;
   - signed/unsigned or width of a local;
   - an inline vs out-of-line call;
   - loop shape, switch lowering, or string instruction;
   - optimization or runtime flags;
   - a missing data address (the relocation applies, but the address is wrong).
7. A unit is committed only when every function reports PASS. Keep the flags that produced the match.

## Flags

The compiler version is fixed; the flags are hypotheses that must be proven per unit. Start from the Release plausibility set and vary one axis at a time:

- optimization: `/O2`, `/O1`, `/Ox`, `/Ot`, `/Os`, `/Ob0`–`/Ob2`, `/Oi`, `/Oy`;
- runtime: `/MD` (default: the image imports `msvcr71.dll`/`msvcp71.dll`, so it links the CRT dynamically), `/MT` (variant worth testing; static CRT changes calls and startup);
- C++: `/GR-` (no class RTTI is visible), `/EHsc` or `/EHa` (the image has C++ exception funclets), `/GX-`;
- processor: `/G6` (P6) or `/G7` (Pentium 4), `/arch:SSE`;
- stack: `/GS-` or `/GS`;
- inlining: `/Ob1`, `/Ob2`, `/Ob0`, `/Zc:inline` does not exist in VC7.1;
- floating point: `/fp:precise` vs `/fp:fast`;
- special: `/GL` (whole-program optimization) cannot be reproduced object-by-object and would invalidate the unit model.

Do not assume the retail build used a single global flag set. A unit's flags are part of its claim and belong in its record.

## What the harness checks

`tools/match.py`:

1. Parses the COFF object (sections, symbols, relocations) without external tools.
2. Derives each object section's base VA from the declared function and data addresses.
3. Applies these relocation types: `ABSOLUTE`, `DIR32`, `DIR32NB`, `REL32`, `REL32_1`–`REL32_5`, `SECREL`, `SECTION`.
4. Extracts each function's bytes, trims trailing `0xCC`/`0x90`/`0x00` padding on both sides, and compares with the image span.
5. Reports PASS/FAIL per function, the first differing byte, and the trimmed lengths.

The compile template is an argv list, not a shell string. A `{flags}` element expands to one argument per flag; `{src}` and `{obj}` convert to Wine-visible paths when `path_style` is `wine` (auto-detected for a `wine` wrapper) or `windows`. `check` reports coverage twice: all inventory entries, and the subset categorized as matchable source functions (thunks and EH funclets excluded).

`check` verifies the image hash, the inventory hash, address existence, duplicate claims, and coverage. The fixture in `tests/run_fixture.py` proves the relocation path and verifies that a changed image byte fails.

## Limits

- **Code only.** Function bytes and relocation targets are compared; referenced data bytes are not. A PASS means the code and the declared target addresses match, not that the data at those addresses is semantically correct.
- **Spans are approximate.** Ghidra does not report body lengths in the retained inventory; a span runs to the next entry and can include alignment padding. The matcher strips trailing padding, but a function with a large embedded table can hide a span error.
- **COMDAT layout.** MSVC may place each function in its own `.text$...` section. The matcher supports that; one unit with several functions from one COMDAT section must agree on a base.
- **Compiler output, not linker output.** Only compiled bytes are compared. Linker layout, IAT thunks, and import stubs are outside the unit.
- **No `/GL`.** Whole-program optimization rewrites functions after compilation; it cannot be matched unit-by-unit.
- **Data matching is future work.** Strings, jump tables, vtables, and global initializers need their own declarative format and comparison pass.
- **Attribution.** A byte match does not prove the original source text or semantics; it proves the compiler produced the same code for the reconstructed unit.

## Layout conventions

- `src/engine/`: Gamebryo/Ni* code (NiMain, NiAnimation, NiCollision, NiDX9, NiInput, NiParticle, NiMesh, file formats).
- `src/game/`: Firaxis game logic (world, sailing, combat, colonies, characters, UI).
- `src/platform/`: Win32, Miles, Bink, DirectX initialization, file system.
- `src/crt/`: compiler/runtime glue that is inside the image and not imported.
- File names describe the recovered class or subsystem, not the Ghidra placeholder. The shipped address remains the identity in `units.json`.
- Do not add a source file without a unit declaration; an undeclared file is dead weight.

## Definition of done

All 8,181 internal addresses report PASS, the units reproduce deterministically from a clean checkout plus the user's image, and the project builds object files without a game binary. Playability is a separate project; the decompilation repository must not ship game data.
