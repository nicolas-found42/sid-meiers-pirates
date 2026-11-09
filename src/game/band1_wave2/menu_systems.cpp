// Clean-room reconstruction from shipped bytes (Ghidra 12.2 corpus only).
// No byte-match claim: cl 13.10.3077 absent on this host. Status: unverified.
// Menu / systems subsystem.
#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <windows.h>

extern int32_t DAT_0086c360, DAT_0086c35c;
extern void* DAT_008cac3c;
extern int32_t DAT_0085a270, DAT_0085a380, DAT_0085a3b8, DAT_0085a4c8;
extern int32_t DAT_0085a500, DAT_0085a610, DAT_0085a648, DAT_0085a758;
extern int32_t DAT_00869b1c;
extern int32_t DAT_007263bc, DAT_00726a84, DAT_007268f4[], DAT_00726a84_dummy;
extern char DAT_00726a84_str[];
extern char DAT_006f588c[], DAT_007060e4[];
extern char DAT_00869b48[];
extern int32_t DAT_0085a26c, DAT_0085a268, DAT_0085a11c;
extern int32_t DAT_008cac18;
extern void* DAT_008c9dd8;
extern int32_t DAT_008c9de0;
extern int32_t DAT_008ed618;
extern int32_t DAT_008ed61c;
extern int32_t DAT_007238fc, DAT_007238f8, DAT_0072ccbc;
extern short DAT_007238bc[];
extern int32_t DAT_007238bc_i;
extern int32_t DAT_0072cb4c, DAT_0072cb40, DAT_0072cb41, DAT_0072ccc4;
extern uint8_t DAT_008cac15;
extern int32_t DAT_008ca91d;
extern uint8_t DAT_008cac27;
extern int32_t DAT_008c827f;
extern void* DAT_0086bb5c;
extern int32_t DAT_00869b48_s;
extern int32_t DAT_00869ab0, DAT_00869acc, DAT_0081431e_dummy;
extern uint8_t DAT_0081431e_b, DAT_00814320_b;
extern int32_t DAT_00814304, DAT_00814308, DAT_0081433c, DAT_00814314, DAT_00814310;
extern int32_t DAT_0085b170[], DAT_0085b174[];
extern int32_t DAT_00725684, DAT_008ca934, DAT_008ca930;
extern int32_t DAT_0085a164;
extern int32_t DAT_00869aac;
extern int32_t DAT_0085a0fc;
extern uint8_t DAT_008c827d, DAT_008e8eff;
extern void* DAT_008ecd78;
extern void* DAT_008e9fd8;

void FUN_004b17f0(const char*,const char*,int,int,int);
int FUN_0042e1d0(int);
void FUN_00506040(int,int,int,int,int);
void FUN_005044d0(int);
void FUN_004888e0(int,int,int,int);
void FUN_004985e0();
void FUN_004a14b0();
void FUN_00488840(const char*,int);
void FUN_004db210();
void FUN_004e7510(float,float,int);
void FUN_004af990();
int FUN_00404910(int);
void FUN_00405420();
void FUN_0045bbf0(int);
void FUN_004cce40();
void FUN_004ad820();
int FUN_005f0ddc();
void FUN_004881b0(int,int);
void FUN_004b06c0(const void*,int,int,int,int,int,int,int);
void FUN_004f6090(const char*,...);
void FUN_004f60b0(const char*,...);
void FUN_004f2600(const char*,...);
void FUN_004f3350();
void FUN_00476050();
void FUN_004d0cd0(int,int,int);
void FUN_00509500(void*,void*,int);
void FUN_00412ec0();
void FUN_00412f10();
void FUN_00412df0();
void FUN_0042c4e0(int);
void FUN_004af080(void*,int,int,int,int,int,int,int,int,int,int);
int FUN_004afd20();
void FUN_004bae60();
void FUN_004bf760(void*,int,const char*,const void*);
void* FUN_004baaa0(...);

// ===== 0x004b19e0 =====
// Observed: pause menu. Body split 0x4b19e0-0x4b19fc / 0x4b1a00-0x4b1aac / 0x4b1ab0-0x4b1ea0.
// DAT_008cac3c pairwise copy; drains FUN_0042e1d0(0) until 0; zeros DAT_0086c360/35c;
// builds rows via FUN_004b17f0("MenuStatus","button_GeneralStatus.kfm",...),
// "MenuFleet"/"button_FleetStatus.kfm", "MenuTreasure"/"button_TreasureMap.kfm" 0x1a4/0x2c3,
// "MenuNav"/"button_Maps.kfm" 0x1fe/0x2c3, "MenuTop10" 600, "MenuPedia" 0x2b2, "MenuOptions" 0x30c,
// "MenuFiles" 0x366, conditional "MenuMapTop10"/button_tmap_top10 400/0x2b3 when DAT_0085a270&&!0x80000000,
// relative buttons by DAT_00869b1c 0..3 (sister/uncle/aunt/gfather), "MenuLostCity" 400/0x2d3,
// "MenuUbervill" 0x1b8/0x2d3, "ReturnToGame"/"button_continueExit.kfm" 0x3c0/0x2c3;
// FUN_00506040(9,0x3f800000,...) reset when param_2/param_3==0 and slots nonzero; sets +3 byte=1, +0xef=1, [0x3c]=0; pushes DAT_007263bc.
void FUN_004b19e0_recon(int* menu, uint8_t param_2, uint8_t param_3)
{
    if (DAT_008cac3c) DAT_008cac3c = DAT_008cac3c;
    int code;
    do { code = FUN_0042e1d0(0); } while (code != 0);
    DAT_0086c360 = 0; DAT_0086c35c = 0;
    FUN_004b17f0("MenuStatus", "button_GeneralStatus.kfm", 0, 0, 0xfffffff6);
    FUN_004b17f0("MenuFleet", "button_FleetStatus.kfm", 0, 0, 0xfffffff6);
    FUN_004b17f0("MenuTreasure", "button_TreasureMap.kfm", 0x1a4, 0x2c3, 0xfffffff6);
    FUN_004b17f0("MenuNav", "button_Maps.kfm", 0x1fe, 0x2c3, 0xfffffff6);
    FUN_004b17f0("MenuTop10", "button_top10.kfm", 600, 0x2c3, 0xfffffff6);
    FUN_004b17f0("MenuPedia", "button_pirateopedia.kfm", 0x2b2, 0x2c3, 0xfffffff6);
    FUN_004b17f0("MenuOptions", "button_systemOptions.kfm", 0x30c, 0x2c3, 0xfffffff6);
    FUN_004b17f0("MenuFiles", "button_loadSave.kfm", 0x366, 0x2c3, 0xfffffff6);
    if (DAT_0085a270 != 0 && (DAT_0085a380 & 0x80000000) == 0)
        FUN_004b17f0("MenuMapTop10", "button_tmap_top10.kfm", 400, 0x2b3, 0xffffffec);
    if (DAT_0085a3b8 != 0 && (DAT_0085a4c8 & 0x80000000) == 0) {
        const char *n=nullptr,*f=nullptr;
        switch (DAT_00869b1c) {
        case 0: n="MenuMapRelative1"; f="button_tmap_sister.kfm"; break;
        case 1: n="MenuMapRelative2"; f="button_tmap_uncle.kfm"; break;
        case 2: n="MenuMapRelative3"; f="button_tmap_aunt.kfm"; break;
        case 3: n="MenuMapRelative4"; f="button_tmap_gfather.kfm"; break;
        default: break;
        }
        if (n) FUN_004b17f0(n, f, 0x1b8, 0x2b3, 0xffffffec);
    }
    if (DAT_0085a500 != 0 && (DAT_0085a610 & 0x80000000) == 0)
        FUN_004b17f0("MenuLostCity", "button_tmap_lostcity.kfm", 400, 0x2d3, 0xffffffec);
    if (DAT_0085a648 != 0 && (DAT_0085a758 & 0x80000000) == 0)
        FUN_004b17f0("MenuUbervill", "button_tmap_ubervill.kfm", 0x1b8, 0x2d3, 0xffffffec);
    if (param_2 == 0 && menu && menu[0x10] != 0) FUN_00506040(9, 0x3f800000,0,0,0x3f800000);
    if (param_3 == 0 && menu && menu[9] != 0) FUN_00506040(9, 0x3f800000,0,0,0x3f800000);
    FUN_004b17f0("ReturnToGame", "button_continueExit.kfm", 0x3c0, 0x2c3, 0xfffffff6);
}

// ===== 0x0041a300 =====
// Observed: captain appearance. Initializes DAT_007238fc=-1, DAT_008ca91d=0,
// DAT_0072cb41/40=0. Branches on DAT_0072cb4c 4/5/6 and param_2<3/<5, param_3 0x28/0x29/0x2a;
// mail: "merch_cap_e%1d_"/"merch_cap_f%1d_"/"merch_cap_d%1d_"/"merch_cap_s%1d_" for param_2<3,
// "milit_cpt_e0%1d_" etc. for 3<=param_2<5; random DAT_007238f8=rand()%5(+5), DAT_0072ccbc=DAT_007238bc[idx];
// DAT_0072ccc4=300, DAT_0072ccbc=2, DAT_008ca91d=1, FUN_00412f10/FUN_00412df0/FUN_004f2600; deck postfix deck01/02/03.
int FUN_0041a300_recon(int seed, int kind, int variant, uint8_t flag)
{
    DAT_007238fc = 0xffffffff; DAT_008ca91d = 0; DAT_0072cb41 = 0; DAT_0072cb40 = 0;
    const char* fmt = "merch_cap_e%1d_";
    if (kind == 1) fmt="merch_cap_e%1d_"; else if (kind==2) fmt="merch_cap_f%1d_"; else if (kind==3) fmt="merch_cap_d%1d_"; else if (kind==0) fmt="merch_cap_s%1d_";
    int roll = rand();
    if (3 <= kind && kind < 5) {
        if (kind==1) fmt="milit_cpt_e0%1d_"; else if (kind==2) fmt="milit_cpt_f0%1d_"; else if (kind==3) fmt="milit_cpt_d0%1d_";
    }
    DAT_007238f8 = roll % 5 + 5;
    DAT_0072ccbc = DAT_007238bc[DAT_007238f8];
    FUN_004f2600(fmt, (seed & 3) + 1);
    FUN_00412f10();
    (void)variant; (void)flag;
    return DAT_007238f8;
}

// ===== 0x00471120 =====
// Observed: ship-name entry. "pauseMenuBG.dds", "Name your @SHIPTYPE:  ", "%s_%03X";
// timed FUN_005f0ddc layout: local_12c = DAT_0085a11c*DAT_008cac18>>10; iVar7=((DAT_0085a26c>>2)-f())/2-ish;
// FUN_004881b0/FUN_004b06c0(&DAT_00869b48,...) two-phase buffer with FUN_00509500, strip suffix after '_' backward scan;
// key loop FUN_0042e1d0(&DAT_006f588c) with sprintf "%s_%03X", timeout 0xf9 via timeGetTime, Sleep(10);
// codes 0x1b (clear 4 tail bytes) / 8 (FUN_00476050 buffer ops).
void FUN_00471120_recon(void)
{
    FUN_004f6090("Name your @SHIPTYPE:  ");
    FUN_004881b0(0, 0x8a);
    FUN_004b06c0(DAT_00869b48, 0, 0x96, 100, 0xffffff80, 1, 0xffffffff, 0);
    char local[256];
    int code;
    do {
        code = FUN_0042e1d0(0);
        sprintf(local, "%s_%03X", DAT_006f588c, code);
        if (DAT_0086bb5c) { /* dispatch */ }
    } while (code == 0 && DAT_008cac27 == 0);
    FUN_004d0cd0(0,0,0);
}

// ===== 0x00466f00 =====
// Observed: sailing / arrival update. param_1 city index. Clamps speed DAT_00869ab0/DAT_00869acc
// against DAT_00723b14/18 stride 0x44 by DAT_008142f8 into DAT_0081431e/20 (uint16);
// when !(DAT_0085a164&0x80) integrates DAT_00814304/08 via FUN_004db210, Manhattan check /0x28<0x3c loop with FUN_004e7510/FUN_005f0ddc;
// DAT_00725684<0x96 -> 0x96; zeros 0x120 words at DAT_00877060; scans 0x22e-stride table psVar7 from DAT_008165da i=8.. until psVar7[-1]==-1||*psVar7!=1||psVar7[0x10]>99;
// audio gate DAT_008c827d: "The audio manager has not been properly initialized yet" via FUN_00488840 else FUN_004985e0/FUN_004a14b0; copies 7 words DAT_008e9fd8+0x128; fStack 100000.0/1000.0 defaults; FUN_0045bbf0(1), FUN_004af990, FUN_00404910/FUN_00405420.
void FUN_00466f00_recon(int cityId)
{
    (void)cityId;
    FUN_004af990();
    if (FUN_00404910(1) < 0) FUN_00405420();
    int spd = DAT_00869ab0 < 0 ? 0 : DAT_00869ab0;
    DAT_0081431e_b = (uint16_t)spd;
    if ((DAT_0085a164 & 0x80) == 0) {
        DAT_00814304 += FUN_004db210();
        DAT_00814308 += FUN_004db210();
    }
    if (DAT_00725684 < 0x96) DAT_00725684 = 0x96;
    DAT_008ca934 = 0; DAT_008ca930 = 0;
    FUN_0045bbf0(1);
    if (DAT_008c827d != 0) {
        // arrival/audio branch observed
        FUN_00488840("The audio manager has not been properly initialized yet", 0);
    }
}
