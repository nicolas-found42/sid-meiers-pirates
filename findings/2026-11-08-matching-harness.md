# Matching harness

Date: 2026-11-08. The harness and its fixture are in the repository; the fixture output below is copied from the actual run.

## Tools

| File | Purpose |
|---|---|
| `tools/pe.py` | Parse PE headers, sections, imports, CodeView/PDB, Rich header, VS_VERSIONINFO. |
| `tools/build_inventory.py` | Convert a retained Ghidra procedure inventory into `build/functions.json`. |
| `tools/match.py` | Validate unit claims, compile a unit, relocate its COFF object, compare functions. |
| `tests/run_fixture.py` | End-to-end fixture with a positive comparison and a negative control. |

## Unit claims

`tools/match.py check` verifies:

- the image SHA-256 and size match `build/units.json`;
- `build/functions.json` was generated from that image;
- every declared address exists in the inventory;
- no address is claimed twice;
- coverage is reported as claimed / inventoried.

The real image currently reports:

```text
image            6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
functions        0 claimed / 8181 inventoried
coverage         0.00%
config OK
```

The zero is deliberate: the compiler is not installed, so no unit is certified yet.

## Comparison pipeline

1. Compile `unit.source` with `unit.compile_argv` (the unit's flags are inserted at `{flags}`) into a COFF object.
2. Parse the COFF file header, section table, symbol table, string table, and section relocations.
3. For every declared function or data symbol, derive the object section's base VA from the declared image address and the symbol's section offset. All claims that share an object section must agree on that base.
4. Copy each touched section and apply its relocations:
   - `DIR32`, `DIR32NB`, `REL32`, `REL32_1`–`REL32_5`, `SECREL`, `SECTION`, `ABSOLUTE`;
   - defined symbols resolve through the declared function/data maps;
   - undefined symbols resolve through the unit's `externals` map.
5. Extract each function up to the next declared function in the same object section, trim trailing `0xCC`/`0x90`/`0x00` padding on both sides, and compare with the image span.
6. Report PASS/FAIL, the first differing byte, and the trimmed lengths.

This is enough to compare ordinary VC7.1 functions that call other functions, reference imported APIs, or reference declared globals.

## Fixture evidence

The fixture builds two C functions (`add`, `call_add`) into a PE linked at `.text = 0x401000`, then builds the same source into a COFF object and compares. `call_add` exercises a `REL32` call relocation.

```text
image            3144c2f7e53ac77a5be61b931508ea683104e82d16ff832cc1ce9699a01ba942
functions        2 claimed / 2 inventoried
coverage         100.00%
config OK
unit fixture
  compile: i686-w64-mingw32-gcc -O2 -fno-inline -c .../a.c -o .../fixture.obj
  PASS _add @ 0x00401000 (12 bytes, trimmed 4/4)
  PASS _call_add @ 0x00401010 (35 bytes, trimmed 13/461)
  2 passed, 0 failed
total 2 passed, 0 failed
```

The negative control flips one byte of the linked image inside `_add` and reruns the comparison:

```text
  FAIL _add @ 0x00401000: first difference at +0x1
    expected 8b 45 24 08 03 44 24 04 c3
    actual   8b 44 24 08 03 44 24 04 c3
  PASS _call_add @ 0x00401010 (35 bytes, trimmed 13/461)
  1 passed, 1 failed
total 1 passed, 1 failed
negative control correctly failed
fixture OK
```

The positive result proves COFF parsing, symbol-base derivation, and `REL32` application. The negative result proves the comparison is not a tautology. It does not prove MSVC compatibility; that requires the actual VC7.1 toolchain and a real game function.

## Limits

- Code bytes and relocation targets only; referenced data bytes are not compared.
- Spans are next-entry deltas and may include padding; trailing padding is trimmed, interior padding is not.
- One base per object section; functions in one COMDAT section must share a consistent base.
- Unsupported relocation types fail the unit instead of being guessed (`TOKEN`, `SECREL7`, and unknown values).
- No `/GL` whole-program optimization, no PGO, no linker-level layout.
- Source paths and timestamps must not influence code bytes; `__FILE__`/`__DATE__`/`__TIME__` are banned in matched code.

## Next harness milestone

Add a data-section comparator for `.rdata` and `.data` claims, then a jump-table/vtable check. Until then, a PASS establishes the function's instruction bytes and the declared target addresses, not the content at those addresses.
