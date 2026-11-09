# What decompilation projects are doing (2026-11)

Research date: 2026-11-08. Sources were fetched and screened; the claims below were checked against the fetched excerpts (7/7 supported by `jev_verify`; the excerpt bundle passed `jev_screen` with injection probabilities 0.09 and 0.04). The 38-billion-token figure is a direct quote from the video and was not independently verified.

## Three different things called "decompilation"

| Project | Target | Method | Result | Ships game data? |
|---|---|---|---|---|
| [FNV decomp] | Fallout: New Vegas, PC x86 | Matching decompilation with the original MSVC compilers | 70,611 functions / 11,537,067 bytes compile to identical bytes; produces object files, not a game | No; user supplies the game |
| [pkmn-colosseum] | Pokémon Colosseum, GameCube PowerPC | Matching decompilation via dtk-template | 8,677 functions / 2,504,940 bytes match and link (100%) | No; user supplies the ROM |
| [Super Mario All-Stars port] | SNES game on Windows/Android | Native port with a custom SNES core plus game-specific patches | Playable port with widescreen, co-op, achievements, save states | No; user supplies the ROM |
| [SavageWindRecomp] | Breath of the Wild, Switch | Static recompilation (LAS Recomp), not an emulator | Native PC build; a fork targets AMD K10 | No; user supplies a 1.9.0/1.8.2 dump |

These are not interchangeable:

- **Matching decompilation** recovers source that compiles to the same bytes as the shipped functions. The build output is object files for comparison. It is the strongest form of source recovery and the most expensive per byte.
- **Static recompilation** lifts the binary into generated C at build time. It targets playability, not source equivalence, and does not need the original compiler.
- **Native port with an emulator core** keeps a console emulator and adds game-specific patches. It is a portability project, not a decompilation.
- **Engine reimplementation** (not in the reviewed sources) rewrites the game around new code. It cannot claim function-level equivalence.

## The matching workflow

The FNV project's account is the clearest public description of the loop:

1. Split the executable into functions (about 70,000 for New Vegas).
2. For each function, write C++ that compiles with the original compiler.
3. Compile and compare the produced bytes with the shipped function.
4. Claim a function on a website, solve it, submit it, and check every submission against the original before counting it complete.
5. Use the community and AI agents for volume; the automatic byte check is the authority.

Reported scale: 70,611 of 70,611 functions and 11,537,067 of 11,537,067 bytes matched; the video reports three weeks, a website, AI agents, and over 38 billion processed tokens. The README requires Visual C++ 2008 SP1 (15.00.30729.01), Visual C++ 2008 RTM (15.00.21022.08) and Visual C++ 2005 SP1 (14.00.50727.762) under Wine. It explicitly says the project is not a port or a replacement executable: building it gives object files to compare.

Pokémon Colosseum applies the same idea to a console binary with a different toolchain: 8,677 tracked functions and 2,504,940 code bytes, the standard dtk-template workflow (`configure.py`, `ninja`), splat splits/symbols, `objdiff`, `decomp.dev`, and the MetroWerks CodeWarrior GC 1.2.5n compiler. Its README also describes the project as AI-assisted. The method is independent of CPU: function boundaries, original compiler, byte comparison.

## The static-recompilation workflow

SavageWindRecomp is a Work-in-Progress static recompilation of Breath of the Wild (Switch v1.9.0), built on LAS Recomp. `make gen` recompiles game code into `generated/`; the repository contains no game files and not even the generated C. The Reddit fork targets AMD K10: the original build needs SSE4.2, so the fork detects the CPU and builds game code for it locally. Users must supply their own dump.

This workflow is the right choice when the goal is a native, playable build and source-level fidelity is not required. It does not produce functions that compile back to the original bytes, so it cannot share the matching harness.

## The emulator-plus-patches workflow

The Super Mario All-Stars port is a native Windows/Android port with a custom SNES core: 65C816, SPC700 and DSP, PPU (including widescreen and high-frame-rate changes), plus per-game widescreen, achievements, cheats, level select and co-op. `build/Release/smastool.exe` is a headless runner/debugger used to reverse-engineer the games. It contains no game data and requires a USA ROM.

This is not applicable to a native x86 PC game: there is no console to emulate, and a compatibility wrapper would not recover source.

## What this means for Pirates!

The shipped executable is a 32-bit x86 PE built with Visual C++ .NET 2003 (linker 7.10, Rich build 3077). That is the same family as the FNV target, so the matching-decompilation workflow is the direct analogue:

- fixed image identity and function inventory (done);
- exact original compiler and flags (identified, not installed);
- compile-and-compare harness (done and fixture-tested);
- function claims, then byte comparison (the actual decompilation work).

Scale comparison (inference from the two inventories, not an effort estimate):

| Metric | FNV | Pirates! | Ratio |
|---|---|---|---|
| Functions | 70,611 | 8,181 | 11.6% |
| Code bytes | 11,537,067 | 2,879,488 | 25.0% |

Pirates is smaller in function count but proportionally denser in bytes (median span 128 bytes). A large part of the image is statically linked Gamebryo 10.1 engine code, which is C++-heavy and template-heavy. A community effort is plausible; a single agent session is not. The exact toolchain remains the gate: without `cl` 13.10.3077, a byte-identical claim cannot be made.

A static recompilation is the alternative if the immediate goal is a playable native build. It would not produce the matching source, and it would still require a clean split of code and data from a 3.3 MB image plus 900 MB of assets. For this project the chosen path is the matching decompilation, because it gives a deterministic, verifiable target and preserves the option of a port later.

## Requested sources

- YouTube, "How I Recompiled Fallout: New Vegas" — https://www.youtube.com/watch?v=Ff8su9nY4os — the matching-decomp account; the 70,611/11,537,067-byte and three-week/38-billion-token figures are the video's claims.
- `dougchansan/pkmn-colosseum` — https://github.com/dougchansan/pkmn-colosseum — GameCube matching decomp; 8,677 functions / 2,504,940 bytes.
- r/decomps, Super Mario All-Stars PC/Android — https://www.reddit.com/r/decomps/comments/1xo3yi8/super_mario_all_stars_pcandroid_coming_tomorrow/ — native port with a custom SNES core, not matching source.
- r/decomps, Breath of the Wild native on a 2010 PC — https://www.reddit.com/r/decomps/comments/1xr1dx8/breath_of_the_wild_running_natively_on_a_2010/ — static recompilation (LAS Recomp), with an AMD K10 fork.

## Legal and distribution boundaries

Every reviewed project requires the user's own copy of the game and ships no game data. The FNV README is explicit that building the decomp produces object files, not a game. This project follows the same rule: the repository contains addresses, names, source, and tools; the image and assets stay outside the repository, and no built game is distributed.

[FNV decomp]: https://github.com/momusdigital/fnv_decomp
[pkmn-colosseum]: https://github.com/dougchansan/pkmn-colosseum
[Super Mario All-Stars port]: https://github.com/Darhkfox/SuperMarioAllStars
[SavageWindRecomp]: https://github.com/Revivedx/SavageWindRecomp
