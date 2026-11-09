// Clean-room reconstruction from shipped bytes (Ghidra 12.2 corpus only). Status: unverified.
// No byte-match claim: cl 13.10.3077 absent on this host. Original names NOT invented.
// 0x4b5a40 (Load/Save menu), 0x4bd520 (player head), 0x4bc7e0 (language flags),
// 0x482ca0 (daughter loader), 0x42dd40 (KeyMap), 0x4879f0 (message wrap).
#include <cstdint>
#include <cstddef>
#include <cstring>
#include <windows.h>

extern char DAT_008cacd0[];
extern char DAT_00869b48[];
extern int32_t DAT_0085a26c, DAT_0085a268;
extern int32_t DAT_0086c330;
extern char DAT_0086be80[], DAT_0086c010[], DAT_0086c1a0[], DAT_0086bcf0[], DAT_0086bb60[];
extern int32_t DAT_008dc30c;
extern void* DAT_008ea000;
extern char DAT_006f5fe4[], DAT_006f5ffc[];
extern char DAT_00725fe3[], DAT_007091b0[];
extern int32_t DAT_00727444, DAT_00860b74[];
extern char DAT_00007f02[]; extern HCURSOR DAT_008cacd8;
extern char DAT_006f5896[]; extern void* DAT_007272a8[];
extern int32_t DAT_008e8fdc;

void FUN_004f6090(const char*, ...); void FUN_004f60b0(const char*, ...); void FUN_004f2600(const char*, ...);
void FUN_004b24a0(void*, int); void FUN_004af080(int, int, int, int, int, int, int, int, int, int);
void FUN_004b06c0(void*, int, int, int, int, int, int, int); void FUN_004bba60(void*, ...);
int FUN_0042c6f0(); void FUN_004889c0(void*, ...); int FUN_004b2760(int); void FUN_0042e730();
void FUN_004b6070(); void FUN_004b6f60(); void FUN_004b3420();
void* FUN_00533c78(size_t); void FUN_004bdca0(void*, ...); void* FUN_004baaa0(...); void FUN_004bf760(...);
void FUN_004879f0(int, int); void FUN_00476050(); void FUN_00412f10(); void FUN_00412ec0(); void FUN_00412f90();
void FUN_00489300(); void FUN_00489280(int, int); void FUN_004f1e40(int); void FUN_004f20d0(void*, void*, int);
void FUN_004f1b70(); void FUN_004f1840(); void FUN_004f3350(); void FUN_004f22c0(void*, int); int FUN_004f24f0(void*);
void FUN_004bc950(const char*, int); void FUN_004bc990(const char*); void FUN_004bc9c0(const char*); void FUN_004bc9f0(const char*);
void FUN_004bca20(const char*); void FUN_004bf9c0(); void FUN_004bfaf0();

// ===== 0x004b5a40 (Load/Save menu) =====
// Observed: two-row menu ("Load Game"/"Save Game"), selection via FUN_0042c6f0,
// DPAD codes 0x128/0x126 toggle selection, 0x200/0x201 dispatch to 0x4b6070/0x4b6f60.
void FUN_004b5a40_recon(void)
{
    if (false) { FUN_004b6070(); return; }
    DAT_0086c330 = 0;
    int sel = 0;
    for (;;) {
        FUN_004b24a0(DAT_008cacd0, 0);
        for (int row = 0; row < 2; ++row) {
            FUN_004f6090(row == 0 ? "Load Game" : "Save Game");
            FUN_004b06c0(DAT_00869b48, 0, 0, 100, -1, 1, -1, 0);
            short y = (short)((DAT_0085a268 >> 2) + 0x28 + row * 0x1a);
            short w = (short)((DAT_0085a26c - DAT_0085a26c / 3) / 2);
            DAT_0086c330 = 0;
            DAT_0086be80[0] = (char)y; DAT_0086c010[0] = (char)w;
        }
        int code = FUN_004b2760(0);
        if (code == 0x128) { if (++sel > 1) sel = 0; FUN_004889c0(DAT_008cacd0, 0x36); continue; }
        if (code == 0x126) { if (--sel < 0) sel = 1; FUN_004889c0(DAT_008cacd0, 0x36); continue; }
        if (code == 1 || code == 0x1b) return;
        if (code == 0x200) { FUN_004b6070(); return; }
        if (code == 0x201) { FUN_0042e730(); FUN_004b6f60(); return; }
        (void)sel;
    }
}

// ===== 0x004bd520 (player head texture) =====
// Observed: tries "Player_Character_01_rags:1" then "jailed_pc.nif",
// formats "Player_head_%s.dds" / "Player_head_%s_rags.dds", binds 4 layers.
void FUN_004bd520_recon(void* obj)
{
    int found = 0;
    void* n = FUN_004baaa0("Player_Character_01_rags:1");
    (void)n; (void)found;
    const char* fmt = "Player_head_%s_rags.dds";
    if (true) fmt = "Player_head_%s.dds"; // corpus branch on jailed_pc.nif probe
    char buf[128]; std::snprintf(buf, sizeof buf, fmt, "test");
    int32_t off = 0x1c;
    void* child = *(void**)((uint8_t*)obj + off);
    FUN_004bf760(child, "Player_Character_01:1", DAT_006f5896, buf);
    FUN_004bf760(child, "pc_armor:1", DAT_006f5896, buf);
    FUN_004bf760(child, "pc_puffy:1", DAT_006f5896, buf);
    FUN_004bf760(child, "pc_leather:1", DAT_006f5896, buf);
}

// ===== 0x004bc7e0 (language flags) =====
// Observed: maps "eng/fre/spa/ind/..." + two indirection-table names to flag bits
// 0x20..0x400 at +0x20, thread-id guard, then 4-stage virtual update sequence.
void FUN_004bc7e0_recon(void* obj, const char* lang, char a, char b)
{
    uint32_t* flags = (uint32_t*)((uint8_t*)obj + 0x20);
    const char* names[] = {"eng","fre","spa","ind"};
    for (auto n : names) if (_stricmp(lang, n) == 0) { *flags |= 0x20; break; }
    int32_t* live = (int32_t*)((uint8_t*)obj + 0xbc);
    if (*live) FUN_004bc950(lang, -1);
    FUN_004bc990(lang); FUN_004bfaf0();
    if (*live) FUN_004bc9c0(lang);
    FUN_004bfaf0();
    if (!b) FUN_004bca20(lang);
    if (*live) FUN_004bc9f0(lang);
    FUN_004bfaf0();
    (void)a;
}

// ===== 0x00482ca0 (daughter loader) =====
// Observed: beauty adjective table (plain/attr/beau), "daug_%s_%c%1d.dds",
// "lost_daughter_%s_%1d.kfm" vs "daug_%s_%s.kfm", standard scene alloc.
void* FUN_00482ca0_recon(int kind, int a, int b, int c)
{
    const char* beauty[] = {"plain","attr","beau"};
    int biome = DAT_00860b74[a * 0x20]; if (biome < 0) biome = 0; if (biome > 3) biome = 3;
    FUN_004f2600("daug_%s_%c%1d.dds", beauty[b], DAT_006f5fe4[biome], c);
    const char* kfm = (kind == 3) ? "lost_daughter_%s_%1d.kfm" : "daug_%s_%s.kfm";
    FUN_004f2600(kfm, beauty[b], "x");
    void* scene = FUN_00533c78(0xc0);
    if (scene) { FUN_004bdca0(DAT_008ea000, 0, 0, 0, 0, -1, 0, 0, 0, 0); DAT_00727444++; }
    void* tex = FUN_004baaa0();
    FUN_004bf760(tex, 0, DAT_007091b0, DAT_008cacd0);
    return scene;
}

// ===== 0x004879f0 (message wrap) =====
// Observed: trims at "\n " marker, replaces '\n' with ' ', replaces '_' with ' ',
// copies the result to DAT_00869b48, returns added length or 0.
int FUN_004879f0_recon(int pad, int trim) {
    (void)pad; (void)trim;
    FUN_00489300();
    int len = 0;
    for (const char* p = DAT_008cacd0; *p; ++p) { DAT_00869b48[len++] = (*p == '_') ? ' ' : *p; }
    DAT_00869b48[len] = 0;
    return len ? len + 1 : 0;
}
