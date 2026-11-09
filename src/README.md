# Source layout

No source unit is committed yet. The toolchain is not installed, so no function has been matched.

Planned organization:

- `engine/`: statically linked Gamebryo 10.1.0.0 code (`NiMain`, `NiAnimation`, `NiCollision`, `NiDX9`, `NiInput`, `NiParticle`, `NiMesh`, NIF/KFM loading).
- `game/`: Firaxis game logic (`world`, `sailing`, `combat`, `colonies`, `characters`, `ui`).
- `platform/`: Win32 initialization, Miles audio (`mss32`), Bink video, dynamic Direct3D 9 loading, file system.
- `crt/`: runtime/glue code that is inside the image rather than imported.

Rules:

- Every file must own at least one declared unit in `build/units.json`; a file without a claim is not part of the build.
- File and symbol names describe recovered behavior. The shipped address remains the identity.
- A file is added only with the flags and evidence that produce a PASS.
- Do not copy leaked or unlicensed engine source. Gamebryo 10.1 is proprietary; reconstruct from the shipped binary and public documentation.
