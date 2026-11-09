# Sources

Accessed 2026-11-08. External excerpts were screened for prompt injection (`jev_screen`) and the factual claims used in the findings were checked against those excerpts (`jev_verify`). The excerpts themselves are not stored in this repository.

## Projects and method

1. Momus Digital, "This Is How We Fully Decompiled Fallout: New Vegas – Here's How I Did It", YouTube, published 2026-11-04. <https://www.youtube.com/watch?v=Ff8su9nY4os>
   - Transcript used for the workflow description, the claimed three-week effort, the community/AI-agent site, and the "over 38 billion tokens" figure.
   - The byte counts and compiler versions were cross-checked against the repository README below.
2. `momusdigital/fnv_decomp`, README. <https://github.com/momusdigital/fnv_decomp>
   - 70,611 of 70,611 functions and 11,537,067 of 11,537,067 bytes match; Visual C++ 2008 SP1 (15.00.30729.01), Visual C++ 2008 RTM (15.00.21022.08), Visual C++ 2005 SP1 (14.00.50727.762) under Wine; build output is object files, not a game.
3. `dougchansan/pkmn-colosseum`, README. <https://github.com/dougchansan/pkmn-colosseum>
   - Matching decompilation, 8,677 tracked functions / 2,504,940 tracked code bytes, dtk-template, `configure.py` + `ninja`, objdiff/decomp.dev, CodeWarrior GC 1.2.5n, AI-assisted.
4. Reddit r/decomps, "Super Mario All-Stars PC/Android coming tomorrow". <https://www.reddit.com/r/decomps/comments/1xo3yi8/super_mario_all_stars_pcandroid_coming_tomorrow/>
   - Native port, custom SNES core (65C816, SPC700, DSP, PPU), per-game widescreen/co-op/achievements, requires the user's own ROM.
   - Repository: `Darhkfox/SuperMarioAllStars` <https://github.com/Darhkfox/SuperMarioAllStars>
5. Reddit r/decomps, "Breath of the Wild running natively on a 2010 CPU". <https://www.reddit.com/r/decomps/comments/1xr1dx8/breath_of_the_wild_running_natively_on_a_2010/>
   - Static recompilation, not emulation; AMD K10 fork of SavageWindRecomp; requires the user's own 1.9.0/1.8.2 dump.
   - Repository: `Revivedx/SavageWindRecomp` <https://github.com/Revivedx/SavageWindRecomp>

## Toolchain

6. Microsoft archived blog, "Visual C++ Toolkit 2003". <https://learn.microsoft.com/en-us/archive/blogs/brianjo/visual-c-toolkit-2003>
   - A comment reports Visual Studio .NET 2003 `cl` 13.10.3077 and the Toolkit `cl` 13.10.3052; other sources below show a Toolkit reporting 13.10.3077. Toolkit builds vary by release, so verify the installed build before claiming a match. The image's dominant Rich build is 3077.
7. RootTalk message quoting `cl` 13.10.3077 and `link` 7.10.3077 for VS .NET 2003. <https://root.cern/root/roottalk/roottalk06/1212.html>
8. Mobilefish, "Microsoft Visual C++ Toolkit 2003" tutorial. <https://mobilefish.com/developer/vctoolkit2003/vctoolkit2003.html>
   - Shows Toolkit `cl` 13.10.3077 and linker 7.10.3077 output.
9. Stack Overflow, compiler version by Visual Studio release. <https://stackoverflow.com/questions/1233312/finding-version-of-microsoft-c-compiler-from-command-line-for-makefiles/69841889>
   - VS .NET 2003 SP1 reports 13.10.6030; a different build from the image's dominant 3077.

## Pirates prior art

10. Reddit r/SidMeiersPirates, "Pirates! Expanded Mod Framework – Testers Needed!", 2026-07-25. <https://reddit.com/r/SidMeiersPirates/comments/1v6gvhu/pirates_expanded_mod_framework_testers_needed>
    - Months of reverse engineering, an extension layer for internal systems, live state read/write, custom events, JSON/Lua foundation; requires the user's own copy.
11. wine-assembly.berrry.app, "Sid Meier's Pirates! (2004)", 2026-10-06. <https://wine-assembly.berrry.app/docs/re-notes/pirates-2004.html>
    - Address-level notes for graphics init/device setup and a note about `d3d9.dll`. The address notes are consistent with the local inventory; the `d3d9.dll` import claim conflicts with the local import table and is treated as unverified.

## Local evidence

- `games/raw/pirates.exe` (installer), `games/INPUTS.json`.
- `experiments/2026-11-08-target-identification/output/extracted/app/` (extracted executable and runtime DLLs).
- `analysis/rea-pirates-bundle.json` (ignored): REA/Ghidra 12.2 evidence bundle with `list_procedures`, PE imports, resources, strings, and binary overview.
- `build/functions.json`: the committed inventory derived from that bundle.
