# Source layout

The toolchain is installed (`analysis/toolchain/`, driven by `tools/wine-cl.sh`)
and three shipped functions are reproduced byte-for-byte; each source file
below owns a declared unit in `build/units.json` and carries the `PASS`
evidence for its addresses:

| File | Units | Addresses |
|---|---|---|
| `engine/setter_u32_00547610.cpp` | `tiny_547610` | `0x00547610` |
| `engine/setter_u8_0054a9f0.cpp` | `tiny_54a9f0` | `0x0054a9f0` |
| `engine/triple_copy_005366b0.cpp` | `tiny_5366b0` | `0x005366b0` |

Verify with:

```sh
python3 tools/match.py check \
  --image "experiments/2026-11-08-target-identification/output/extracted/app/Pirates!.exe"
python3 tools/match.py compare --all \
  --image "experiments/2026-11-08-target-identification/output/extracted/app/Pirates!.exe"
```

Planned organization (grows only with units that PASS):

- `engine/`: statically linked Gamebryo 10.1.0.0 code (`NiMain`, `NiAnimation`, `NiCollision`, `NiDX9`, `NiInput`, `NiParticle`, `NiMesh`, NIF/KFM loading). The three matched addresses (`0x5366b0`, `0x547610`, `0x54a9f0`) sit in the Gamebryo band and are the first entries.
- `game/`: Firaxis game logic (`world`, `sailing`, `combat`, `colonies`, `characters`, `ui`).
- `platform/`: Win32 initialization, Miles audio (`mss32`), Bink video, dynamic Direct3D 9 loading, file system.
- `crt/`: runtime/glue code that is inside the image rather than imported.

Rules:

- Every file must own at least one declared unit in `build/units.json`; a file without a claim is not part of the build.
- File and symbol names describe recovered behavior. The shipped address remains the identity.
- A file is added only with the flags and evidence that produce a PASS.
- Do not copy leaked or unlicensed engine source. Gamebryo 10.1 is proprietary; reconstruct from the shipped binary and public documentation.
