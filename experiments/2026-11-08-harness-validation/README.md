# sid-meiers-pirates-2026-11-08-harness-validation: does the matcher compare correctly?

- Status: completed
- Target/build/platform/architecture: harness fixture, i386 COFF, host macOS arm64
- Canonical input: `tests/fixture/a.c` (tracked)
- Question: does `tools/match.py` parse COFF, derive section bases, apply a `REL32` relocation, compare function bytes, and reject a changed image?
- Expected observation: both fixture functions PASS against the linked image; one flipped image byte makes the same comparison FAIL.
- Tool/provider/version: `i686-w64-mingw32-gcc` (Homebrew), Python 3.15, `tools/match.py`
- Working directory: project root
- Limits: fixture compiler is GCC, not MSVC 7.1; the fixture validates the harness mechanics, not MSVC compatibility
- Output location: temporary directory only (`mktemp`), removed automatically

## Command

```sh
python3 tests/run_fixture.py
```

The fixture compiles `a.c` twice:

1. to a COFF object (the input the harness relocates);
2. linked into a PE at `.text = 0x401000` (the "shipped image" stand-in).

It derives the two symbol addresses from the linker map, writes a fixture `functions.json` and `units.json`, runs `match.py check`, then `compare`, then flips one byte of the linked image and runs `compare` again.

## Observations and evidence

Positive run:

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

`_call_add` contains a call to `_add`; its PASS requires the `REL32` relocation to be applied with the declared address.

Negative control (one byte flipped inside `_add`):

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

The changed byte appears exactly where expected; the other function still passes. The harness is not a tautology.

## Conclusion and limits

The COFF parser, symbol-base derivation, `REL32` application, padding trim, and FAIL reporting work on a real i386 PE/COFF pair. This does not validate MSVC-specific sections, decorated symbols, exception funclets, jump tables, or data references. Those require a real VC7.1 unit and are the reason the first game unit is gated on the toolchain.

The fixture's image hash changes between runs because the linked PE carries build metadata; the addresses and byte comparisons are stable.

## Retention

No artifacts are retained: the fixture build lives in a temporary directory and is removed by the script. The tracked inputs are `tests/fixture/a.c` and `tests/run_fixture.py`; the harness is `tools/match.py`.

## Next action

Install the VC7.1 toolchain, then repeat the same positive/negative discipline on the first real function.
