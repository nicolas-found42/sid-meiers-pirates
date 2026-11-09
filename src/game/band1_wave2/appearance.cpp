// Clean-room reconstruction from shipped bytes (Ghidra 12.2 corpus only).
// No byte-match claim: cl 13.10.3077 absent on this host. Status: unverified.
// Appearance / texture loader subsystem.
#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <windows.h>

extern uint8_t DAT_00869a88[];
extern int32_t DAT_00869aa8;
extern uint8_t DAT_00860b74[];
extern uint8_t DAT_006f5ffc[];
extern uint8_t DAT_00725fd8[];
extern int32_t DAT_008c827f_dummy;
extern void* DAT_008dc974, *DAT_008dc97c, *DAT_008dc96c, *DAT_008dc970;
extern int32_t DAT_00727444;
extern int32_t DAT_00725560;
extern int32_t DAT_008cb100[];
extern int32_t DAT_008cb104[];
extern char DAT_008cacd0[];
extern uint8_t DAT_008cac27;
extern int32_t DAT_0085a26c, DAT_0085a268;
extern void* DAT_008e9ff0, *DAT_008e9ffc;

void FUN_004f6090(const char*, ...);
void FUN_004f60b0(const char*, ...);
void FUN_004f2600(const char*, ...);
void FUN_004baaa0(...);
void FUN_004bf760(void*,int,const char*,const void*);
void FUN_004bc1b0(const char*,int);
void FUN_004bc210(const char*,int);
void FUN_004bdb30();
void FUN_00449390(const void*,const void*);
int FUN_004bf440();
void* FUN_00500850();
void FUN_00542cb0(int,int);
void* FUN_00533c78(size_t);
void FUN_004bdca0(void*,...);
void* FUN_004af680(void*,const char*,int,int,int,int,int,int,int,int,int,int);
void FUN_004c1000(const char*);
void FUN_004c1080(void*,const char*,int,int);
void FUN_004c12a0(void*,void*,int);
void FUN_00412840(int,int);
void FUN_004beee0();
void FUN_00481100();
void FUN_004bcd90(int,int,int);
void FUN_004af080(void*,int,int,int,int,int,int,int,int,int,int);
void* FUN_004cddf0(const char*,int,int,int*,int*);
void FUN_004d0cd0(int,int,int);
int FUN_0042c4e0(int);
int FUN_0042e1d0(int);
void FUN_004afd20();
struct RefObj { void** vtbl; int refs; };
void releaseRef(RefObj* o){ if(o && --o->refs==0) ((void(*)(int))o->vtbl[0])(1); }

// ===== 0x004bcd90 =====
// Observed: player-appearance texture builder. Calls FUN_004baaa0 first; formats
// "Player_head_%s.dds" (table DAT_007272dc[param_3]), "PC_%s_%c.dds", "%s_Gloss.dds";
// binds via FUN_004bf760; refcount release idiom (puVar+1 / vtbl call(1));
// switch on rank selector 0..7 choosing "PC_hat duke[:0]", "PC hat admiral:0",
// "PC Blue Feather admrl", "PC red feather admirl 1/2", "PC_hair", shadow nodes;
// FUN_004bc1b0(name,1/0) / FUN_004bc210 gated on *(EBX+0xbc)!=0.
void FUN_004bcd90_recon(int mesh, int slot, int head)
{
    char buf1[256], buf2[256], buf3[256];
    FUN_004baaa0();
    sprintf(buf1, "Player_head_%s.dds", "");
    sprintf(buf2, "PC_%s_%c.dds", "", (char)slot);
    sprintf(buf3, "%s_Gloss.dds", "");
    (void)buf1; (void)buf2; (void)buf3;
    FUN_004bc1b0("PC_hair", 1);
    FUN_004bc1b0("PC hat duke:0", 0);
    FUN_004bc1b0("PC hat admiral:0", 0);
    FUN_004bc1b0("PC Blue Feather admrl", 0);
    FUN_004bc1b0("PC red feather admirl 1", 0);
    FUN_004bc1b0("PC red feather admirl 2", 0);
    (void)mesh; (void)head;
}

// ===== 0x00482a00 =====
// Observed: NPC appearance selector. Returns RefObj* (puVar3). Reads faction
// byte DAT_00860b74[param_2*0x20] clamped to [0,3]; gate DAT_00725fd8[param_1]==0;
// cases: 1/2 -> "barmaid_%c.dds"/"barmaid_e.dds"; 5 -> "mayo_%c%1d.dds"/"governor_french512.dds";
// 6 -> "merch_p_var1.dds"/"merch_p_512.dds"; then FUN_004bf760(...,pcVar6,...),
// FUN_004baaa0(), FUN_004afd20(). Calls FUN_004823f0/0x00482560/0x00482830/0x00482200 etc.
void* FUN_00482a00_recon(int kind, char* handle)
{
    int faction = 0;
    if (handle != (char*)0xffffffff) faction = (signed char)DAT_00860b74[(int)(size_t)handle * 0x20];
    if (faction < 0) faction = 0; else if (faction > 3) faction = 3;
    if (DAT_00725fd8[kind] == 0) {
        switch (kind) {
        case 1: case 2:
            FUN_004f2600("barmaid_%c.dds", (int)(char)DAT_006f5ffc[faction]);
            FUN_004bf760(FUN_004baaa0(), 0, "barmaid_e.dds", DAT_008cacd0);
            break;
        case 5:
            FUN_004f2600("mayo_%c%1d.dds", (int)(char)DAT_006f5ffc[faction], 1);
            FUN_004bf760(FUN_004baaa0(), 0, "governor_french512.dds", DAT_008cacd0);
            break;
        case 6:
            FUN_004bf760(FUN_004baaa0(0,"merch_p_512.dds","merch_p_var1.dds"), 0, "merch_p_512.dds", DAT_008cacd0);
            break;
        default: break;
        }
    }
    FUN_004baaa0();
    FUN_004afd20();
    return nullptr;
}

// ===== 0x00453030 =====
// Observed: governor scene spawn. Cursor save/restore; loads "pce_back.dds",
// allocs 0xc0-byte scene nodes via FUN_00533c78 with vtbl &PTR_FUN_006fd14c,
// DAT_00727444 live counter, FUN_004bdca0 init, "pc_govm.kfm" via FUN_004af680,
// "fx_candle" via FUN_004c1080, FUN_004bcd90(suit,slot,head) appearance pass,
// FUN_004c1000("shadow_01"), "cam_myster" camera via FUN_004ae5b0 else FUN_004ae4f0,
// FUN_00412840(0x3f800000,0x49742400), FUN_004beee0 camera update; flag DAT_007263bc reset.
void FUN_00453030_recon(int cityId, void* renderCtx)
{
    (void)cityId; (void)renderCtx;
    FUN_004c1080(DAT_008dc974, "fx_candle", 100, 0xffffffff);
    FUN_004bcd90(0, 0, 0);
    FUN_004c1000("shadow_01");
    FUN_00412840(0x3f800000, 0x49742400);
    FUN_004beee0();
}

// ===== 0x0044b8a0 =====
// Observed: top-10 death parchment. Texts "The sordid career of the @ORDINAL most notorious pirate: @TOP10...", triple DAT_008cb100[param_1*3];
// renders "bigParchment.dds" twice, "x_1.dds"/"x_2.dds" via FUN_004cddf0/FUN_004af080 at 0x7e/0x88,
// DAT_0085a11c=0x4b, FUN_004b06c0(...,0xf2,...,0x4b,0xff8f661e,...); polls FUN_0042e1d0(&DAT_006fbe38)
// until nonzero or DAT_008cac27!=0; timeout path FUN_0042c4e0(500); teardown releases puVar5 and local_110-8 string.
void FUN_0044b8a0_recon(int rank)
{
    FUN_004f6090("The sordid career of the @ORDINAL most notorious pirate: @TOP10, has come to an end!\n",
                 DAT_00725560, DAT_008cb100[rank*3], DAT_008cb104[rank*3]);
    FUN_004f60b0("bigParchment.dds");
    FUN_004f60b0("x_1.dds");
    FUN_004d0cd0(0,0,0);
    (void)rank;
}
