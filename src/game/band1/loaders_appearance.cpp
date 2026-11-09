// Clean-room reconstruction from shipped bytes (Ghidra 12.2 corpus only). Status: unverified.
// No byte-match claim: cl 13.10.3077 absent on this host. Original names NOT invented.
#include <cstdint>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <windows.h>

extern char DAT_008cacd0[];
extern void* DAT_008ea000;
extern char DAT_006f5ffc[], DAT_006f5fe4[];
extern char DAT_007091b0[]; extern char DAT_00725fe3[];
extern int32_t DAT_00727444;
extern int32_t DAT_00860b74[];
extern int32_t DAT_008e8fb0, DAT_008e8fb4, DAT_008e8fb8, DAT_008e8fbc;
extern void* DAT_00727520;
extern int32_t DAT_008c9df4;
extern int32_t DAT_008ed618; extern uint32_t DAT_008ed61c;

void FUN_004f2600(const char*, ...);
void* FUN_00533c78(size_t); void FUN_004bdca0(void*, ...); void* FUN_004baaa0(...); void FUN_004bf760(...);
void FUN_004baa30(void*, ...); void FUN_004afd20(); void FUN_00482200(void*);
void FUN_00449390(void*, int); void FUN_004aad70(int); int FUN_004bf530(void*); int FUN_004bf5e0(void*); void FUN_004aade0(int);
void FUN_004c1000(const char*); void FUN_00535670(void*); void FUN_00535920(void*);

// Helper observed in many loaders: 0xc0 scene alloc + vtable + counter + bind.
static void* allocScene(void) {
    void* p = FUN_00533c78(0xc0);
    if (p) { FUN_004bdca0(DAT_008ea000, 0, 0, 0, 0, -1, 0, 0, 0, 0); DAT_00727444++; }
    return p;
}

// ===== 0x00482830 (bartender loader) =====
// Observed: seed/state branches on param_2; strings "bartender_%c.dds", "bartender_e.dds",
// "bart_p_var1.dds"; timeGetTime/srand interplay; same scene alloc idiom.
void* FUN_00482830_recon(int seed, int kind)
{
    void* scene = allocScene();
    if (kind == 4) {
        srand(seed);
        int r = rand();
        if (r % 100 > 0x32) {
            void* tex = FUN_004baaa0(0, "bartender_e.dds", "bart_p_var1.dds");
            FUN_004bf760(tex);
        }
        if (!(DAT_008ed61c & 1)) { DAT_008ed61c |= 1; DAT_008ed618 = (int)timeGetTime(); }
        srand((int)timeGetTime() - DAT_008ed618);
    } else {
        FUN_004f2600("bartender_%c.dds", DAT_006f5ffc[kind]);
        void* tex = FUN_004baaa0();
        FUN_004bf760(tex, 0, "bartender_e.dds", DAT_008cacd0);
    }
    return scene;
}

// ===== 0x00482560 (shipwright loader) =====
// Observed: same alloc idiom; "shipw_%c.dds"/"shipw_e.dds"/"shipw_p_512.dds"/"shipw_p_var1.dds".
void* FUN_00482560_recon(int flag, int kind)
{
    void* scene = allocScene();
    if (kind == 4) {
        if (flag & 1) {
            void* tex = FUN_004baaa0(0, "shipw_p_512.dds", "shipw_p_var1.dds");
            FUN_004bf760(tex);
        }
    } else {
        FUN_004f2600("shipw_%c.dds", DAT_006f5ffc[kind]);
        void* tex = FUN_004baaa0();
        FUN_004bf760(tex, 0, "shipw_e.dds", DAT_008cacd0);
    }
    return scene;
}

// ===== 0x004af760 (ship appearance applier) =====
// Observed: four optional panels "ship_playercolor_*", "flag*", "ship_sail_emblem_lrg*",
// "ship_sail_emblem_sml*" gated on DAT_008e8fb0/b4/b8/bc.
void FUN_004af760_recon(void)
{
    if (DAT_008e8fb0) {
        void* n = FUN_004baaa0("ship_playercolor_*");
        int found = FUN_004bf530(n);
        if (found) { FUN_00449390(DAT_00727520, 0); FUN_004aad70(DAT_008e8fb0); }
    }
    if (DAT_008e8fb4) {
        void* n = FUN_004baaa0("flag*");
        int found = FUN_004bf530(n);
        if (found) { FUN_00449390(DAT_00727520, 0); FUN_004aad70(DAT_008e8fb4); }
    }
    if (DAT_008e8fb8) {
        void* n = FUN_004baaa0("ship_sail_emblem_lrg*");
        if (FUN_004bf5e0(n)) { FUN_00449390(DAT_00727520, 0); FUN_004aade0(DAT_008e8fb8); }
    }
    if (DAT_008e8fbc) {
        void* n = FUN_004baaa0("ship_sail_emblem_sml*");
        if (FUN_004bf5e0(n)) { FUN_00449390(DAT_00727520, 0); FUN_004aade0(DAT_008e8fbc); }
    }
}

// ===== 0x004813f0 (clothing selector) =====
// Observed: switch -> "cl_interface02/05/04/03/01", "cl_crewmen01", "shadow_01" fallback.
void FUN_004813f0_recon(void* out, int kind)
{
    char* node = nullptr;
    switch (kind) {
    case 3: case 0xf: node = "cl_interface02"; break;
    case 4: case 5: case 0xb: case 0xc: node = "cl_interface05"; break;
    case 6: case 0xd: node = "cl_interface03"; break;
    case 7: node = "cl_interface01"; break;
    case 2: node = "cl_interface04"; break;
    default: FUN_004c1000("shadow_01"); DAT_008c9df4 = 1; return;
    }
    (void)out; (void)node;
    void* n = FUN_004baaa0();
    (void)n;
    FUN_00535670(n); FUN_00535920(DAT_008ea000);
}

// ===== 0x004823f0 (mayor loader) =====
// Observed: "mayo_%c%1d.dds", "mayor_s%1d.kfm"/"mayor_e.kfm", "mayo_e1.dds".
void* FUN_004823f0_recon(int kind, int variant)
{
    int v = variant % 3 + 1;
    FUN_004f2600("mayo_%c%1d.dds", DAT_006f5fe4[kind], v);
    void* scene = nullptr;
    if (kind == 0) {
        FUN_004f2600("mayor_s%1d.kfm", v);
        scene = FUN_00533c78(0xc0);
        if (scene) FUN_004baa30(DAT_008ea000, DAT_008cacd0, 0, 0, 0, 0, -1, 0, 0, 0, 0);
    } else if (kind == 1) {
        FUN_004f2600("mayor_e.kfm");
        scene = FUN_00533c78(0xc0);
        if (scene) FUN_004baa30(DAT_008ea000, DAT_008cacd0, 0, 0, 0, 0, -1, 0, 0, 0, 0);
        void* tex = FUN_004baaa0();
        FUN_004bf760(tex, 0, "mayo_e1.dds", DAT_008cacd0);
    } else {
        FUN_00482200(DAT_008cacd0);
    }
    FUN_004baaa0(); FUN_004afd20();
    return scene;
}
