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

`experiments/2026-11-08-source-reconstruction/out/verified/tiny_547610.cpp`:

```cpp
struct SetterTarget {
    void set_value(unsigned int value);
};

void SetterTarget::set_value(unsigned int value) {
    *(unsigned int*)((char*)this + 0x0c) = value;
}
```

`experiments/2026-11-08-source-reconstruction/out/verified/tiny_54a9f0.cpp`:

```cpp
struct ByteSetter {
    ByteSetter* set_byte(unsigned char value);
};

ByteSetter* ByteSetter::set_byte(unsigned char value) {
    *(unsigned char*)((char*)this + 0x18) = value;
    return this;
}
```

`experiments/2026-11-08-source-reconstruction/out/verified/tiny_5366b0.cpp`:

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

`build/units.json` now contains units `tiny_547610`, `tiny_54a9f0` and
`tiny_5366b0` with
the exact `cl` and Wine paths used for this run, `/O2`, and the corresponding
symbols `?set_value@SetterTarget@@QAEXI@Z`,
`?set_byte@ByteSetter@@QAEPAU1@E@Z` and `?copy@T@@QAEXXZ`.

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

`check` now reports `2 claimed / 8181 inventoried`, `2 claimed / 7862
matchable`, coverage `0.02%`, `config OK`.

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

Ephemeral by design, outside the repository:

- Wine: `/tmp/pirates-wine-probe/mach9/wine/bin/wine`
  (`wine-11.20-37-g2362fb0442`).
- Prefix: `/tmp/pirates-wine-probe/prefix2`.
- Compiler tree: `/tmp/compiler-research/stage/` (`cl.exe`, `link.exe`,
  `c1.dll`, `c1xx.dll`, `c2.dll`, `mspdb71.dll`, `msvcr71.dll`,
  `msvcp71.dll`).
- Headers/libs: `/tmp/compiler-research/vc71tree/{include,lib}`.

The extraction method, hashes and archive.org source are in
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
