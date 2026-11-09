# First byte-identical function — VC7.1 on the host

Date: 2026-11-09. Target: `Pirates!.exe`, PE32 i386, image base `0x00400000`,
SHA-256 `6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9`.

## Result

Three functions now **PASS** against the shipped image using the original
toolchain: `FUN_00547610` at `0x00547610`, `FUN_0054a9f0` at `0x0054a9f0`,
and `FUN_005366b0` at `0x005366b0`. The first two are 16-byte inventory
entries with 9- and 11-byte bodies; the third is a 26-byte body followed
by 6 `0xCC` bytes.

Shipped bytes (`tools/pe.py`, `read_va(0x00547610, 16)`):

```
8b 44 24 04 89 41 0c c2 04 00 cc cc cc cc cc cc
```

`cl 13.10.3077` `/O2` emitted exactly:

```
8b 44 24 04 89 41 0c c2 04 00
```

For `0x0054a9f0` the shipped bytes are:

```
8b c1 8a 4c 24 04 88 48 18 c2 04 00 cc cc cc cc cc
```

and `/O2` emitted:

```
8b c1 8a 4c 24 04 88 48 18 c2 04 00
```

Harness output:

```
unit tiny_547610
  PASS ?set_value@SetterTarget@@QAEXI@Z @ 0x00547610 (9 bytes, trimmed 1/7)
  1 passed, 0 failed
unit tiny_54a9f0
  PASS ?set_byte@ByteSetter@@QAEPAU1@E@Z @ 0x0054a9f0 (11 bytes, trimmed 1/5)
  1 passed, 0 failed
```

The third match is a 12-byte struct assignment from `+0x90` to `+0x28`,
which VC7.1 formats as the shipped `lea`/`add` sequence:

```
unit tiny_5366b0
  PASS ?copy@T@@QAEXXZ @ 0x005366b0 (26 bytes, trimmed 1/6)
  1 passed, 0 failed
```

This establishes three things at once: the image is runnable under the
Mach9 Wine/FEX runtime, the harness resolves and relocates a real VC7.1 COFF
object correctly, and shipped functions can be reproduced byte-for-byte on
this host.

## Source

`src/engine/setter_u32_00547610.cpp` (unit `tiny_547610`):

```cpp
struct SetterTarget {
    void set_value(unsigned int value);
};

void SetterTarget::set_value(unsigned int value) {
    *(unsigned int*)((char*)this + 0x0c) = value;
}
```

`src/engine/setter_u8_0054a9f0.cpp` (unit `tiny_54a9f0`):

```cpp
struct ByteSetter {
    ByteSetter* set_byte(unsigned char value);
};

ByteSetter* ByteSetter::set_byte(unsigned char value) {
    *(unsigned char*)((char*)this + 0x18) = value;
    return this;
}
```

`src/engine/triple_copy_005366b0.cpp` (unit `tiny_5366b0`):

```cpp
struct T { void copy(); };
struct Triple { unsigned int a, b, c; };

void T::copy() {
    *(Triple*)((char*)this + 0x28) = *(Triple*)((char*)this + 0x90);
}
```

The explicit `__thiscall` keyword is rejected by this compiler
(`error C4234`), so the packed thiscall ABI comes from a real C++ member
function instead. The second function returns `this`, which is why the
shipped code starts `mov eax,ecx`; returning `void` changes the register
allocation and fails.

## Unit and command

`build/units.json` contains units `tiny_547610`, `tiny_54a9f0` and
`tiny_5366b0` — sources now under `src/engine/`, `/O2`, and the corresponding
symbols `?set_value@SetterTarget@@QAEXI@Z`,
`?set_byte@ByteSetter@@QAEPAU1@E@Z` and `?copy@T@@QAEXXZ`. The toolchain was
relocated from the `/tmp` staging paths to the durable, gitignored
`analysis/toolchain/` root and is driven by `tools/wine-cl.sh`; the final
`match.py compare --all` run re-verified all three PASS from the repo config
(see [docs/TOOLCHAIN.md](docs/TOOLCHAIN.md) "Installation").

```sh
cd games/sid-meiers-pirates
python3 tools/match.py check \
  --image "experiments/2026-11-08-target-identification/output/extracted/app/Pirates!.exe"
python3 tools/match.py compare \
  --image "experiments/2026-11-08-target-identification/output/extracted/app/Pirates!.exe" \
  --unit tiny_547610
python3 tools/match.py compare \
  --image "experiments/2026-11-08-target-identification/output/extracted/app/Pirates!.exe" \
  --unit tiny_54a9f0
```

`check` reports `3 claimed / 8181 inventoried`, `3 claimed / 7862
matchable`, coverage `0.04%`, `config OK` after the third unit landed.

## Two nearby negatives

Two other hand-written candidates in the same set do **not** match with the
current source and `/O2`:

| Address | Shipped first bytes | Candidate first bytes |
|---|---|---|
| `0x0054a9f0` | `8b c1 8a 4c 24 04 …` | `8a 44 24 04 88 41 18 …` |
| `0x005366b0` | `8d 81 90 00 00 00 8b 10 …` | `8b 81 90 00 00 00 89 41 28 …` |

The source-level operation is the same; the compiler chose a different
addressing/register plan. Those two remain unverified candidates. The
negative results show the PASS is not a tautology.

## Toolchain paths

Originally staged under `/tmp` (`/tmp/pirates-wine-probe/`,
`/tmp/compiler-research/stage/`, `/tmp/compiler-research/vc71tree/`) for the
first matches, then relocated on 2026-11-09 to the durable, gitignored
`analysis/toolchain/` root (`vc71/`, `wine/mach9/`, `prefix2`) and wired into
`build/units.json` through `tools/wine-cl.sh`. See
[docs/TOOLCHAIN.md](docs/TOOLCHAIN.md) "Installation". The extraction method,
hashes and archive.org source are in
`findings/2026-11-08-compiler-availability.md`. No compiler payload is
copied into the repository.

## Limits

- Two functions are matched; 7,860 matchable functions remain unclaimed.
- `/O2` is proven for this unit only. Other functions may need different
  flags; every unit must justify its own.
- The repository's bulk reconstruction candidates are decompiler-derived
  and mostly do **not** compile as-is. They are not moved to `PASS` by this
  result.
- The `check` coverage percentage counts claimed addresses; it is not a
  reconstruction-coverage measure.
