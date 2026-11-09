# External Sources — Pirates! / Gamebryo Clean-Room Reconstruction

Date of research: 2026-11-08  
Target: `experiments/2026-11-08-target-identification/output/extracted/app/Pirates!.exe` (PE32 i386, VC7.1, Gamebryo 10.1)  
Method: web search + primary-source URL reads. No source copied into the repo.  
Status: First batch (per assignment: produce cited findings, not a full survey). Unresolved items are marked **[UNRESOLVED]**.

Legend: **Observed** = verified by quoted URL content on 2026-11-08. **Lead** = plausible but not verified or not opened. **Forbidden** = leaked/proprietary — do not use or copy.

## 1. Source table

| # | Source (URL, accessed 2026-11-08) | What it actually supports | Type | Usable in clean-room? |
|---|---|---|---|---|
| 1 | **NifTools `nif.xml` (master)** — https://raw.githubusercontent.com/niftools/nifxml/master/nif.xml ; wiki https://github.com/niftools/nifxml/wiki — read 2026-11-08 | Version map with Pirates! named: `<version id="V10_1_0_0" num="10.1.0.0">{{Sid Meier's Pirates!}}, …</version>` (line ~163 in raw). Header comment: `10.1.0.0 == 0x0A010000`. Defines all `<basic>`, `<enum>`, `<compound>`, `<niobject>` blocks for NIF/KF/KFM (8,550 lines). **This is the concrete evidence for the "Gamebryo 10.1" claim.** | Secondary (community reconstruction, BSD-style tools) | **Yes — primary format reference.** Cite, do not copy wholesale. Use field names/order for NIF/KF/KFM parsing. |
| 2 | **Adam Milazzo — Iron Man Mod post** — https://adammil.net/blog/v120_Sid_Meier_s_Pirates_Iron_Man_Mod.html — read 2026-11-08 | **Concrete addresses/offsets into the non-Steam 1.0.2.0 executable**: file offsets `0x5E699` (disable battle autosave), `0x66EB0` (arrival autosave), `0x72F3B`/`0x72F67` (quick-save/load), `0xB24A7` (load/save menu), `0xB5DD9` (abandon game), `0xB5FD6` (quit-slot copy), `0xD4B94` + `0xF617E` (Win close). States Steam build is packed/encrypted; non-Steam is plain. Quotes byte patches with surrounding bytes. Also notes `.fpk` asset archives hold `.dds` skins. | Primary (author's own RE notes) | **Yes — addresses are observed facts** (only for v1.0.2.0 English non-Steam). Verify against target before trusting. |
| 3 | **Adam Milazzo — ExePatch post** — https://adammil.net/blog/v122_Introducing_ExePatch.html ; IDA db link from #2 (`pirates.idb`) — read 2026-11-08 | Tool for assembling binary patches; confirms IDA Pro 6.1 workflow on the same binary. No new addresses beyond #2. | Primary tooling | **Yes (tool only).** The `.idb` itself not fetched — **[UNRESOLVED]** whether it is still downloadable. |
| 4 | **MWSE — Ni class hierarchy** — https://mwse.github.io/MWSE/references/general/ni-class-hierarchy — read 2026-11-08 | Full NetImmerse class tree (Morrowind/Gamebryo lineage): `niObject → niObjectNET → niAVObject → niNode`, `niGeometry → niTriBasedGeometry → niTriShape/niTriStrips`, properties (`niAlphaProperty`, `niZBufferProperty`, …), `niTimeController`, `niSequence`, particles, collision. Class names match the `Ni*` family in `nif.xml`. | Secondary (Morrowind-specific, but same engine lineage) | **Yes as naming reference only.** Do not assume Pirates! uses the same subclass set. |
| 5 | **PCGamingWiki — Sid Meier's Pirates! (2004)** — https://pcgamingwiki.com/wiki/Sid_Meier%27s_Pirates!_(2004) — fetched 2026-11-08 (full content not rendered) | Confirms 1.02 patch legacy; page content was unavailable via fetch (truncated). | Secondary | **No direct RE value.** Lead only. |
| 6 | **Nexus Mods — Sid Meier's Pirates! (game page)** — https://nexusmods.com/sidmeierspirates — read 2026-11-08 | 47 mods listed (count observed). Mod descriptions confirm asset workflow: drop files into `custom/` folder, `.dds` textures, `text.ini` / `citynames_enu.txt` / `cityloc.dta`. No addresses/classes. | Secondary | **Yes for format/workflow facts only** (custom folder, DDS). |
| 7 | **Hooked on Pirates forums** — https://hookedonpirates.com/forums/viewtopic.php?t=1540 (mod manager thread) + t=9799 (widescreen) + t=8112 — search 2026-11-08, not fully read | Indicates community tooling for mod-file management and save-game editing. | Secondary | **[UNRESOLVED]** — threads not fully read; no concrete addresses extracted yet. |
| 8 | **Microsoft — VC7.1/CRT redistribution** — https://learn.microsoft.com/en-us/previous-versions/troubleshoot/visualstudio/cpp/libraries/redistribution-shared-c-runtime-component ; StackOverflow merge-module list — search 2026-11-08 | `Msvcr71.dll` = MSVC .NET 2003 CRT; merge modules `vc_user_crt71_rtl_x86_---.msm`, `vc_user_mfc71_rtl_x86_---.msm`, `vc_user_stl71_rtl_x86_---.msm`. No symbol dumps. | Primary (Microsoft) | **Yes for CRT identification only.** No vtable/RTTI help. |
| 9 | **sigmaco/gamebryo-v2.6 — `NiObject.h`** — https://raw.githubusercontent.com/sigmaco/gamebryo-v2.6/329cd25a38d66ca8a55c7564eabd898358c95ff1/CoreLibs/NiMain/NiObject.h — read 2026-11-08 | Header shows `EMERGENT GAME TECHNOLOGIES PROPRIETARY INFORMATION … may not be copied or disclosed` and defines `NiObject : NiRefObject` with `Clone()`, `ProcessClone()`, `GetStreamableRTTIName()` etc. | **FORBIDDEN** (see §3) | **No — do not copy or quote beyond this classification note.** |
| 10 | **STBC-Reverse-Engineering (SandboxServers)** — https://github.com/SandboxServers/STBC-Reverse-Engineering — README read 2026-11-08 | Documents a Gamebryo/NetImmerse 3.1 RE (Star Trek: Bridge Commander, 2001): 670 RTTI classes, `nirtti-factory-catalog.md`, `netimmerse-vtables.md`, Ghidra annotation scripts naming ~6,031 functions. Explicitly lists `engine/gamebryo-1.2-source/` and `engine/gamebryo-2.6-source/` as reference — **i.e. the repo bundles the same proprietary sources as #9.** | **FORBIDDEN if bundling proprietary source; otherwise secondary methodology** | Current `docs/` may be cited for methodology only. **Do not fetch `engine/*-source/` or copy its code.** |

## 2. Findings by investigation question

### (1) Public Pirates! PDB / debug symbols / map file / official SDK
- **Observed:** No public Pirates! PDB, `.map`, or official SDK found in any search. The only concrete binary-internal evidence is Adam Milazzo's offset list (#2 above) — for v1.0.2.0 non-Steam, not for the analyzed target image.
- **Lead:** Hooked on Pirates modding tools (#7) may document `.fpk` layout; not verified.
- **[UNRESOLVED]** Whether a Pirates! `.pdb` or `.map` ever shipped with the 1.02 patch, GOG release, or SteamDepot. Not confirmed.

### (2) Existing Pirates! decompilation / mod frameworks / RE notes
- **Observed:** Adam Milazzo's Iron Man Mod (#2) is the strongest primary source — named offsets, patch bytes, version scope (v1.0.2.0 English non-Steam). ExePatch (#3) is tooling only.
- **Lead:** Reddit "Pirates! Expanded Mod Framework / PEMF" (2026-08) claims reverse engineering of the 2004 game — **search returned no concrete addresses, classes, or repo URL**; the PEMF search results were dominated by unrelated "Pulsed EMF" projects. Treat as unverified claim.
- **[UNRESOLVED]** PEMF repo location, hook addresses, class names. Needs direct follow-up (see §5).
- **Dead end:** `SMSG-decomp` (SimGolf) and other "Sid Meier's" decomp projects are different games — not Pirates!.

### (3) Gamebryo 10.1 / 2.6 documentation, headers, NIF/KFM specs
- **Observed (strongest result):** `nif.xml` (#1) **explicitly names Sid Meier's Pirates! as a primary `{{…}}` user of NIF version 10.1.0.0** (`0x0A010000`). The file is the canonical community reconstruction of the NIF/KF/KFM binary layout (basic types, enums, compounds, NiObject blocks) and is used by NifSkope, PyFFI, Niflib. This is usable directly for parsing Pirates! `.nif`/`.kf`/`.kfm` assets.
- **Observed:** MWSE hierarchy (#4) gives the `Ni*` class names and inheritance shape for the same engine family (Morrowind lineage, NetImmerse prefix).
- **Observed:** sigmaco/gamebryo-v2.6 exists on GitHub and shows the `NiMain` header layout (e.g. `NiObject.h` content above) — but the file header marks it **proprietary Emergent/NDA material**.
- **[UNRESOLVED]** Official Emergent Game Technologies 10.1/2.6 SDK documentation, API reference PDFs, or class-reference HTML. None located via public search; the vendor (Emergent → Gamebryo, now Gamebryo/Emerson) documentation was licensed, not free.
- **[UNRESOLVED]** Whether any public `NiMain` header set or API docs exist outside the proprietary repos above. Not found.

### (4) VC7.1 runtime / CRT symbol clues
- **Observed:** `Msvcr71.dll` / `Msvcp71.dll` are the VC7.1 CRT; merge modules named in #8. This identifies the CRT family but yields **no function symbols, vtable layouts, or STL internals** for the target.
- **[UNRESOLVED]** No `.def`, import-library, or symbol-map resource specific to the target's VC7.1 build was found. `msvcr71d.dll` (debug) import-library patch exists in mingw-w64 sources — not verified as useful for RE here.

## 3. Legal / clean-room classification

| Category | Sources | Rule |
|---|---|---|
| **Safe to cite (public, non-proprietary)** | #1 nif.xml (community), #2/#3 Milazzo notes, #4 MWSE docs, #5 PCGW, #6 Nexus, #8 Microsoft docs | Cite URL + access date; paraphrase field/class names; do not bulk-copy `nif.xml` into the repo. |
| **Secondary — cite with attribution, verify against binary** | #7 Hooked on Pirates threads | Treat forum claims as leads until confirmed in the target image. |
| **FORBIDDEN — leaked/proprietary, do not copy or use as source** | #9 sigmaco/gamebryo-v2.6 (Emergent proprietary header, NDA text in file), #10's `engine/gamebryo-*-source/` bundles | **Do not fetch, quote, or paraphrase code from these.** Gamebryo 2.6 may be referenced *semantically only* (class names already public via #1/#4), never copied. |
| **Unverified claims** | PEMF "reverse engineered" posts | Do not cite as fact until a repo/commit with addresses or classes is produced. |

Clean-room note: the only Gamebryo-10.1-specific evidence obtained so far is the **format-level** record in `nif.xml` (version number ↔ Pirates!) plus Milazzo's binary offsets. No proprietary headers, `.lib`, or engine source have been used.

## 4. Concrete data extracted (observed)

**From `nif.xml` (#1):**
- Pirates! NIF version: **10.1.0.0 = `0x0A010000`** (primary `{{Sid Meier's Pirates!}}`).
- Header string rule (PyFFI docs, consistent): `versions >= 10.1.0.0` use `'Gamebryo File Format x.x.x.x'`; `<= 10.0.1.2` use `'NetImmerse File Format x.x.x.x'`.
- Sibling 10.1-era titles for cross-check: Freedom Force vs. the 3rd Reich, Axis and Allies, Empire Earth II, Kohan 2.

**From Milazzo (#2) — v1.0.2.0 English non-Steam file offsets (verify against target; Steam build is packed/encrypted):**
- `0x5E699` disable 'battle' autosave (`E8 …` → `EB 03 90 90 90`)
- `0x66EB0` disable 'arrival' autosave
- `0x72F3B` disable quick-save, `0x72F67` disable quick-load
- `0xB24A7` disable load/save menu in-game
- `0xB5DD9` disable abandon-game, `0xB5FD6` quit-slot copy guard
- `0xD4B94`, `0xF617E` disable Win close (Alt-F4)
- Asset archive: `.fpk` (contains `.dds` skins); custom content goes in `custom/` folder; text files `text.ini`, `citynames_enu.txt`, `cityloc.dta`.

**From MWSE (#4) — class names (engine-family reference, not Pirates!-confirmed):**
`niObject, niObjectNET, niAVObject, niNode, niGeometry, niTriBasedGeometry, niTriShape, niTriStrips, niTimeController, niKeyframeData, niKeyframeController, niSequence, niAlphaProperty, niZBufferProperty, niTexturingProperty, niSkinInstance, Ni…` (see hierarchy page for full tree).

## 5. Dead ends

- **SimGolf decomp (`SMSG-decomp`)** — different game, no overlap.
- **"Pirates Expanded" (RimWorld / EK2)** — unrelated mods with the same name; not the 2004 game.
- **PEMF name collision** — "Pulsed Electromagnetic Field" projects and unrelated forks dominate GitHub topic search; the Pirates! PEMF repo was not located.
- **PCGamingWiki fetch** — page skeleton only; no RE tables extracted.
- **Open-source Gamebryo lookalikes** (`ByroRedux`, Nifly, PyNifly, `decomp.dev` FNV entries) — useful format knowledge but **not Pirates!-specific**; FNV/decomp.dev entries are Bethesda-era (Gamebryo 20.x), not 10.1.
- **Steam version of the executable is packed/encrypted** (per Milazzo) — offsets do not apply to it.

## 6. Next research steps (3–5)

1. **Verify Milazzo offsets against the analyzed target image** with REA (read-only): check the byte patterns at `0x5E699`, `0x66EB0`, `0x72F3B`, `0xB5DD9` in `Pirates!.exe` to confirm whether the target is the same v1.0.2.0 build. If they match, these become anchored entry points for the decomp queue.
2. **Locate the PEMF repo directly** (Reddit r/SidMeiersPirates 2026-08 posts). If it publishes hook addresses or a class map, that would be the first true Pirates!-specific symbol source. If no repo exists, record it as a dead end.
3. **Parse a Pirates! `.nif`/`.kf` asset with `nif.xml` 10.1.0.0 rules** (PyFFI or NifSkope CLI) to confirm the block list against shipped bytes, and record which NiObject block types actually appear — this grounds the class-name list in observed data rather than Morrowind-era MWSE names.
4. **Search Firaxis/Atari official mod-support pages and the Hooked on Pirates "Customizations & Modding" forum** for `.fpk` layout notes and any officially released format docs (`.dat`/`.dta` field lists). Mark anything unconfirmed as a lead.
5. **Interrogate the target's imports for VC7.1 CRT + Gamebryo markers** (REA `inspect_pe_imports`, RTTI strings) to move from family-level class names (#4) to Pirates!-observed RTTI names — this is the clean-room path to real class/vtable evidence without touching proprietary sources.

## 7. Unresolved items checklist

- [ ] Pirates! PDB / `.map` / official SDK — **not found; no claim made.**
- [ ] PEMF repo, hook addresses, class map — **unresolved; claim unverified.**
- [ ] Official Emergent Gamebryo 10.1/2.6 docs — **not publicly located.**
- [ ] Milazzo `pirates.idb` (IDA 6.1 database) — **link noted, not fetched.**
- [ ] Hooked on Pirates forum threads — **listed, not fully read.**
