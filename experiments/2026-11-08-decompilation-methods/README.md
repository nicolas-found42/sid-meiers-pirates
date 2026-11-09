# sid-meiers-pirates-2026-11-08-decompilation-methods: what are comparable projects doing?

- Status: completed
- Target/build/platform/architecture: method research for the Pirates! v1.0.2.0 Windows x86-32 image
- Canonical input: none downloaded; web sources only
- Question: which methods are behind the linked projects (Fallout: New Vegas, Pokémon Colosseum, Super Mario All-Stars, Breath of the Wild), and which method fits a 2004 x86 PC game?
- Expected observation: a consistent, source-backed description of matching decompilation, static recompilation, and emulator-plus-patch ports.
- Tool/provider/version: Firecrawl scrape/search, Keenable search, Jev (`typesafe/jev-1.14`) for screening and claim verification
- Working directory: project root
- Limits: excerpts only; no full-thread or video download beyond the transcript; no copyrighted content stored
- Output location: none; conclusions in `findings/2026-11-08-decompilation-landscape.md`

## Sources

- YouTube: <https://www.youtube.com/watch?v=Ff8su9nY4os> (Momus Digital, 2026-11-04)
- FNV decomp: <https://github.com/momusdigital/fnv_decomp>
- Pokémon Colosseum: <https://github.com/dougchansan/pkmn-colosseum>
- Reddit SMAS: <https://www.reddit.com/r/decomps/comments/1xo3yi8/super_mario_all_stars_pcandroid_coming_tomorrow/>
- Reddit BotW: <https://www.reddit.com/r/decomps/comments/1xr1dx8/breath_of_the_wild_running_natively_on_a_2010/>
- Repositories linked from the posts: `Darhkfox/SuperMarioAllStars`, `Revivedx/SavageWindRecomp`
- Compiler provenance: Microsoft archived blog, RootTalk, Mobilefish; see `references/README.md`

## Observations and evidence

- FNV: matching decompilation; 70,611/70,611 functions and 11,537,067/11,537,067 bytes match; original MSVC 2005/2008 compilers under Wine; the build produces object files, not a game; the video reports three weeks, a claim website, AI agents, and over 38 billion tokens.
- Pokémon Colosseum: matching decompilation; 8,677 functions / 2,504,940 bytes; dtk-template, splat, objdiff, decomp.dev, CodeWarrior GC 1.2.5n; AI-assisted; 100%.
- Super Mario All-Stars: native port with a custom SNES core (65C816, SPC700, DSP, PPU), game-specific patches, ROM required, no game data.
- Breath of the Wild/SavageWind: static recompilation with LAS Recomp, not emulation; user dump required; an AMD K10 fork rebuilds game code locally.
- The four sources therefore describe three distinct methods: matching decompilation, static recompilation, and emulator-plus-patch porting. They should not be conflated.

Verification: the combined excerpt bundle passed `jev_screen` (injection 0.09 and 0.04, substance ≥0.98, relevance 0.95). Seven method claims passed `jev_verify` (7/7 supported, confidence 0.92–1.0). The 38-billion-token figure is quoted from the video and not independently verified.

## Conclusion and limits

For a 2004 x86 PC game with a recovered VC7.1 toolchain, matching decompilation is the direct analogue of FNV and the only method that produces byte-identical functions. Static recompilation is the alternative if playability is the immediate goal. The emulator-plus-patch approach does not apply to native x86. See the landscape finding for the full comparison and the scale estimate.

Limits: the video transcript and Reddit posts are self-reported; the counts were cross-checked only where a README stated them. "No public Pirates decompilation found" is based on a limited search, not an exhaustive audit.

## Retention

Keep this record and the findings. No downloaded media is retained; the external excerpts are not stored. No `output/` directory is created.

## Next action

Apply the matching method to the identified image: install the exact toolchain, then certify the first unit.
