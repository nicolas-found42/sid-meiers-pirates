// Clean-room reconstruction from shipped bytes (Ghidra 12.2 corpus only).
// No byte-match claim: cl 13.10.3077 absent on this host. Status: unverified.
// Scene / cinematic subsystem.
#include <cstdint>
#include <cstddef>
#include <windows.h>

extern uint8_t DAT_008cac27, DAT_008c827f;
extern int32_t DAT_0086c35c, DAT_007263bc, DAT_00726a84, DAT_00725d98, DAT_008c9df4;
extern int32_t DAT_00726820, DAT_007268f4[], DAT_00726814[];
extern int32_t DAT_00727444;
extern int32_t DAT_00726398, DAT_0072639c, DAT_0072cd78_dummy;
extern void* DAT_008e9fe8, *DAT_008e9fec, *DAT_008e9fd8, *DAT_008e9ff4, *DAT_008e9ffc;
extern void* DAT_008ea000;
extern int32_t DAT_0085a164;
extern uint8_t DAT_00869b48;
extern void* DAT_008c97c0;
extern int32_t DAT_008c97c4;
extern char DAT_00007f02[];
extern HCURSOR DAT_008cacd8;

void FUN_00488ed0(int);
void FUN_004a2080(int,int,int);
void FUN_00481100();
void* FUN_004afe30();
void* FUN_004af680(void*,const char*,int,int,int,int,int,int,int,int,int,int);
void FUN_004bdca0(void*,...);
void* FUN_00533c78(size_t);
void FUN_004ae4f0();
void FUN_004ae5b0(const char*);
void FUN_00412840(int,int);
void FUN_004beee0();
void FUN_004a21c0();
int FUN_0042e1d0(int);
void FUN_00489130(const void*);
int FUN_00481560(int,int,int,int,int,int);
void FUN_004d94f0(const char*,float,int,int);
void FUN_004e65a0(float,float,float,float,float,float,float);
void FUN_004e24b0();
void FUN_004e2970(void*,void*,void*);
void FUN_004e43c0(int);
void FUN_00412cb0(int);
void FUN_004e4660();
void FUN_004d0340();
void FUN_004ff810();
void FUN_004ff6b0(int);
void FUN_004ae0d0(const void*,const void*);
void FUN_004add70(int);
void FUN_004ad790();
void FUN_004d9bf0(void*);
void FUN_004d5860();
void FUN_004f6090(const char*,...);
void FUN_00412f10();
void FUN_00412df0();
void FUN_00470a80(const void*);
void FUN_004d2170(const char*);
int FUN_004f4ed0();
void FUN_004c3690();
void FUN_0042dd40();
void FUN_004c31e0();
int FUN_004b1740();
void FUN_004bc0d0();
int FUN_005f0ddc();
int FUN_004dadc0(int,int,int);
void FUN_004bbc80(int,int,int,int,int,int,int);
void FUN_004bbe10(int,int);
void FUN_004bbf50();
void FUN_004afee0();
void FUN_004aff70(const void*);
void FUN_004d0cd0(int,int,int);
void FUN_004bef50();
void FUN_00535920(void*);
void FUN_00535670(void*);
void FUN_004bed70(void*,int);
void FUN_004baaa0(...);
void FUN_00533d10(int,int);
void FUN_004c1000(const char*);
struct RefObj { void** vtbl; int refs; };
void releaseRef(RefObj* o){ if(o && --o->refs==0) ((void(*)(int))o->vtbl[0])(1); }

// ===== 0x00428fd0 =====
// Observed: engine/graphic init. Returns 1. Cursor idiom with DAT_00007f02 fallback;
// allocs 0xcc (FUN_004e65a0(0x46fa0000,0x41c80000,0x447a0000,0x447a0000,0x41200000,0x3f800000,0x3f800000)),
// 0x108 (FUN_004e24b0), 0x28 skydome "assets\\terrain\\skydome006.nif" 0x3f266666,
// 0x5c (FUN_004d9bf0), 0x10 (FUN_004d5860); FUN_00412840(0x447a0000,0x46ea6000);
// "Incognito" when DAT_00726640 empty; Config.ini load via FUN_004d2170 guarded by FUN_004f4ed0;
// tail FUN_004c3690/FUN_0042dd40/FUN_004c31e0, FUN_004b1740 into DAT_008cabe8; restores cursor.
int FUN_00428fd0_recon(void)
{
    HCURSOR saved = GetCursor();
    SetCursor(DAT_008cacd8 ? DAT_008cacd8 : LoadCursorA(nullptr, DAT_00007f02));
    FUN_004d94f0("assets\\terrain\\skydome006.nif", 0.625f, 0, 0);
    FUN_00412840(0x447a0000, 0x46ea6000);
    FUN_004add70(0x4b0);
    FUN_004ad790();
    FUN_004f6090("Incognito");
    FUN_004d2170("Config.ini");
    FUN_004c3690(); FUN_0042dd40(); FUN_004c31e0();
    SetCursor(saved);
    return 1;
}

// ===== 0x0044fa40 =====
// Observed: lost-city cinematic. Guard DAT_008cac27==0. FUN_00488ed0(0x3f800000);
// FUN_004a2080(-1,-1,-1); cursor + palette push/pop on DAT_007268f4/DAT_00726814 with
// DAT_00726a84/DAT_00726820 and DAT_007263bc=0xff7ffff; param_1 defaults to
// FUN_004af680(DAT_008ea000,"pc_lost_city.kfm",0,0,0,0,0xffffffff,...); two 0xc0 scene
// nodes + FUN_00481560(8,0/1,...); "Camera All", FUN_00412840(0x3dcccccd,0x47c35000);
// "shadow_01", frame loop 0x65..0x67 with FUN_004bbc80/FUN_004bbe10/FUN_004bbf50,
// Sleep(5), escape on 0x1b/0x20/0xd; teardown restores palette, DAT_008c9df4=1, FUN_004bef50.
void FUN_0044fa40_recon(void* param_1)
{
    if (DAT_008cac27 != 0) return;
    FUN_00488ed0(0x3f800000);
    FUN_004a2080(0xffffffff,0xffffffff,0xffffffff);
    if (!param_1) param_1 = FUN_004af680(DAT_008ea000, "pc_lost_city.kfm",0,0,0,0,0xffffffff,0,0,0,0,0);
    FUN_004ae5b0("Camera All");
    FUN_00412840(0x3dcccccd, 0x47c35000);
    FUN_004beee0();
    FUN_004c1000("shadow_01");
    FUN_004a21c0();
    FUN_004bef50();
    FUN_004ae4f0();
}

// ===== 0x00452890 =====
// Observed: hidden-treasure cinematic. Same prologue as 0x0044fa40 (DAT_007263bc=0xff7ffff,
// DAT_00725d98 cleared); loads "pc_hid_treas.kfm" via FUN_004af680; FUN_00481560(7,0..4,...)
// five adds; FUN_00412840(0x3f800000,0x47435000); loop iVar5=0xc9..0xcb with FUN_004bed70(node,iVar5-200),
// triple FUN_004bc0d0/FUN_004dadc0+FUN_004bbc80, 5x repeat, FUN_004bbe10/FUN_004bbf50,
// *(puVar3+9)=0, FUN_004afee0, Sleep(5); same palette restore + FUN_004bef50 + releaseRef chain.
void FUN_00452890_recon(void)
{
    if (DAT_008cac27 != 0) return;
    FUN_00488ed0(0x3f800000);
    FUN_004a2080(0xffffffff,0xffffffff,0xffffffff);
    FUN_004af680(DAT_008e9ffc, "pc_hid_treas.kfm",0,0,0,0,0xffffffff,0,0,0,0,0);
    FUN_00481560(7,0,0xffffffff,0,0,0); FUN_00481560(7,1,0xffffffff,0,0,0);
    FUN_00481560(7,2,0xffffffff,0,0,0); FUN_00481560(7,3,0xffffffff,0,0,0);
    FUN_00481560(7,4,0xffffffff,0,0,0);
    FUN_004ae5b0("Camera All");
    FUN_00412840(0x3f800000, 0x47435000);
    FUN_004beee0();
    FUN_004a21c0();
    FUN_004bef50();
    FUN_004ae4f0();
}

// ===== 0x00418dd0 =====
// Observed: floor camera pan. Returns uint8 flag local_b9 (0/1). Guard param_1<0x46;
// 0xc0 node via FUN_00533c78; frame loop calls FUN_004bc0d0, timed FUN_005f0ddc pair,
// render via FUN_004dadc0(0,0,0)+FUN_004bbc80(...,100,param_1,iVar6) 3x + 0xffffffff flush,
// FUN_004bbe10/FUN_004bbf50, *(local_b8+9)=0, FUN_004afee0, FUN_005002f0, Sleep(5);
// every >10 frames toggles "f_br_floor_shader" bit 0x20 via FUN_004baaa0/FUN_004d4fe0;
// batch cameras "Camera01"; escape 0x1b/0x20/0xd sets local_b9=0; releases puVar3/local_b8.
uint8_t FUN_00418dd0_recon(int count)
{
    uint8_t done = 1;
    if (count < 0x46) {
        FUN_004ae5b0("Camera01");
        FUN_004ae4f0();
    }
    return done;
}
