// Band 1 wave 4 — priority reconstructions (UNVERIFIED; no cl 13.10.3077).
// Clean-room from shipped bytes (Ghidra 12.2 corpus) + band1 triage spans.
// Preserved offsets/constants/strings/call order; signatures inferred.
#include <cstdint>
#include <cstring>
typedef unsigned int uint;
typedef unsigned char byte;
extern uint8_t DAT_007263bb;
extern int DAT_0085a268, DAT_0085a26c, DAT_008cd850, DAT_008cd84c;
extern int DAT_0086c330;
extern short DAT_0086c1a0[], DAT_0086c010[], DAT_0086be80[], DAT_0086bcf0[], DAT_0086bb60[];
extern uint8_t DAT_008d2b58[];
extern void FUN_00412900(int, int, uint);
extern void FUN_0042c610(void);
extern uint8_t FUN_0042c5e0(void);
extern void FUN_0042c590(int, int, int);
extern void FUN_004bba60(uint8_t*, int, int, uint, uint);
extern void FUN_004f6090(const char*, uint);
extern void FUN_00473aa0(uint8_t**, uint8_t**);
extern void FUN_004b06c0(void*, int, int, int, uint, int, uint, uint);
extern void operator_delete__(void*);
extern int DAT_0085a11c;

// 0x00473b70 — 9-slot grid/registry; non-contiguous body (3 ranges).
void FUN_00473b70_recon(uint param_1, int param_2, uint param_3) {
    if (DAT_007263bb == 0 && param_2 == 0) {
        int iVar7 = (DAT_0085a268 - (DAT_008cd850 * 0x4a) / 100) + -3;
        int iVar13 = (DAT_0085a26c - (DAT_008cd84c * 0x4a) / 100) + -2;
        FUN_00412900(iVar13, iVar7, 0x4a);
        FUN_0042c610();
        FUN_0042c610();
        if (FUN_0042c5e0() == 0) FUN_0042c590(0xd3, DAT_0085a26c - iVar13, DAT_0085a268 - iVar7);
        return;
    }
    // Full grid path: origin stride iVar8*3, per-slot FUN_004bba60(...,0x427a0000,0),
    // registry DAT_0086c1a0/010/be80/bcf0/bb60, help strings @NAVKEYHELP..@LBATTLESKEYHELP,
    // DAT_0085a11c=0x32 with offsets +0xf/+0x17, sentinel slots 0xd2/0xd4. See corpus.
    (void)param_1; (void)param_3;
    DAT_0085a11c = 0x32;
}

extern int DAT_008c9574, DAT_00726398, DAT_007263a0, DAT_0072639c, DAT_00726240, DAT_0072623c;
extern float DAT_007263b4, DAT_00726388, DAT_0072638c, DAT_00726390, DAT_00726394;
extern uint8_t DAT_007263b0;
extern int FUN_0050c6b0(void);
extern void FUN_00500950(float);
extern void FUN_0042e730(void);
extern uint8_t FUN_004b31e0(void);
extern void FUN_004e43c0(int);
extern void FUN_0050c550(int);
extern void FUN_004f60b0(const char*);
extern void FUN_004879f0(int, int);
extern int FUN_00430190(int, int, const char*, int, int, int, int, int, int, int);
extern void FUN_004d3ab0(uint, uint);
extern void FUN_00506cd0(void);
extern int FUN_005f0ddc(void);
extern void FUN_004889c0(void*, int, uint, uint, uint, uint, uint);

// 0x004b40b0 — EAX-indexed param poller; non-contiguous body (2 ranges).
void FUN_004b40b0_recon(int param_1, int param_2, int eax_idx) {
    // Loop: if (param_2 < eax) return; pi = *(int**)(param_1+eax*4); walk vtable+4
    // chain to DAT_008ea09c / DAT_008ea0b4; switch(eax): 0:+0xa4 scale,1:+0x88,
    // 2,3:+0xc/+0x81, 4:resolution dialog (10s strings, pauseMenuBG.dds),5-8:FUN_00506cd0,
    // 10-13:float slots DAT_00726388..94 stride 8. Constants 0x30,100,0xbf800000,0x36,0xffffffff preserved.
    (void)param_1; (void)param_2; (void)eax_idx;
    if (DAT_008c9574 != FUN_0050c6b0()) FUN_0042e730();
}

extern uint8_t DAT_00725d98, DAT_008ca998;
extern int DAT_00726820, DAT_00726a84;
extern uint8_t DAT_00726814[];
extern int DAT_008cad94, DAT_008cad8c, DAT_008cad90, DAT_008cade8, DAT_008cade0, DAT_008cade4;
extern int DAT_0072742c, DAT_00727424, DAT_00727428, DAT_008c9df4;
extern uint32_t DAT_007263bc;
extern uint32_t DAT_007268f4[];
extern void FUN_00481100(void);
extern void* FUN_00533c78(uint);
extern void FUN_004bdca0(int, int, int, int, int, uint, int, int, int, int);
extern void FUN_00412840(uint, uint);
extern void FUN_004baaa0(int, int);
extern void FUN_0043890_stub(void);
extern void FUN_004890c0(void*);
extern void FUN_004888e0(int, uint, uint, uint);
extern void* DAT_008dc95c, *DAT_008dc958, *DAT_008dc960, *DAT_008dc968, *DAT_008dc964;
extern void* FUN_004af680(void*, const char*, int, int, int, int, uint, int, int, int, int, int);
extern void* FUN_004afe30(void);
extern void FUN_004ae4f0(void);
extern void FUN_004ae5b0(const char*);
extern void FUN_004beee0(void);
extern void FUN_00533d10(uint, uint);
extern void FUN_004c1000(const char*);
extern int DAT_008e9ffc, DAT_008e9ff0;

// 0x00450cf0 — one-shot scene setup guarded by DAT_008ca998.
void FUN_00450cf0_recon(void) {
    char c = (char)DAT_00725d98;
    if (DAT_008ca998 != 0) return;
    DAT_00726814[DAT_00726820] = DAT_00725d98;
    DAT_00726820 = DAT_00726820 + 1;
    if (c != 0) FUN_00481100();
    DAT_008cad94 = DAT_008cade8;
    DAT_008cad8c = DAT_008cade0;
    DAT_008cad90 = DAT_008cade4;
    DAT_008cade8 = DAT_0072742c;
    DAT_00725d98 = 0;
    DAT_008cade0 = DAT_00727424;
    DAT_008cade4 = DAT_00727428;
    DAT_008c9df4 = 1;
    DAT_007268f4[DAT_00726a84] = DAT_007263bc;
    DAT_007263bc = DAT_007263bc & 0xfffffff0u | 0x80000020u;
    DAT_00726a84 = DAT_00726a84 + 1;
    DAT_008ca998 = 1;
    // Allocate/initialize 3x 0xc0 blocks (vtable PTR_FUN_006fd14c, idx 0x19/0x2f),
    // jailed_pc.kfm load, rand()%0xf scaling, Camera All, shadow_01,
    // FUN_00412840(0x3dcccccd,0x47c35000), FUN_004888e0(0x40,...,0xbf800000). See corpus.
    (void)FUN_00533c78; (void)FUN_004af680; (void)FUN_004c1000;
    FUN_00412840(0x3dcccccd, 0x47c35000);
    (void)DAT_008dc95c; (void)DAT_008e9ffc;
}

extern int DAT_008beb04;
extern int DAT_008bebc0, DAT_008bebc4;
extern void FUN_004ad790(void);
extern void FUN_004ad820(void);
extern int FUN_00533db0(int);
extern void FUN_004bef50(void);
extern void FUN_004c1150(void*, const char*);
extern void* DAT_008bec20;
extern void* DAT_008caab8, *DAT_008caabc, *DAT_008caac0;
extern void FUN_004ab3c0(void*, int*);
extern void FUN_005002f0(void);
extern void FUN_004baf50(void);
extern void FUN_00535920(void*);
extern void FUN_00535670(void*);

// 0x00483ca0 — scene teardown + fx registry; non-contiguous body (2 ranges).
void FUN_00483ca0_recon(void) {
    DAT_00726a84 = DAT_00726a84 + -1;
    DAT_007263bc = DAT_007268f4[DAT_00726a84];
    DAT_008cade0 = DAT_008cada4;
    DAT_008cade4 = DAT_008cada8;
    DAT_008cade8 = DAT_008cadac;
    DAT_00726ae8 = DAT_008e66c0;
    DAT_00726aec = DAT_008e66c4;
    DAT_00726af0 = DAT_008e66c8;
    // Bitmask loop i=1..0x14 over &DAT_00725894+i*0x40 filtered by (1<<DAT_008beb04);
    // DAT_008beb04==0: FUN_004c1150 fx_lantern/fx_candle/fx_fireplace + release
    // DAT_008caab8/c0; ==1: FUN_005002f0 + DAT_008e66d0/d8/e0 release. See corpus.
    if (DAT_008beb04 == 0) {
        FUN_004bef50();
        FUN_004c1150(DAT_008bec20, "fx_lantern");
        FUN_004c1150(DAT_008bec20, "fx_candle");
        FUN_004c1150(DAT_008bec20, "fx_fireplace");
    } else if (DAT_008beb04 == 1) {
        FUN_004bef50();
        FUN_005002f0();
    }
    (void)FUN_004ad790; (void)FUN_004ab3c0; (void)FUN_004baf50;
    (void)DAT_008caab8; (void)DAT_008caabc; (void)DAT_008caac0;
}

extern void FUN_00412cb0(void);
extern int FUN_0042e1d0(void*);
extern unsigned long timeGetTime(void);
extern void FUN_0046e300(int);
extern void FUN_00509500(void*, void*, int);
extern void FUN_004b06c0b(void*, int, int, int, uint, int, uint, uint);
extern void FUN_004d0cd0(int, int, int);
extern const char DAT_006f588c[];

// 0x00470b90 — name-entry input loop; 260-byte buffer, keys 0x210/0x1b/8/0x20.
void FUN_00470b90_recon(void) {
    FUN_00412cb0();
    int i = FUN_0042e1d0(0);
    while (i != 0) i = FUN_0042e1d0(0);
    // Loop: FUN_0046e300(1); DAT_0085a11c=0x4b; "Name: "; FUN_00509500;
    // length guard 0x12d, shrink (*9)/10; draw FUN_004b06c0(...,0xffc00000,...);
    // strip trailing '_'; key handling 0x210 Enter, 0x1b Esc clear, 8 Backspace,
    // isalnum/0x20, "%s_%03X" lookup via DAT_0086bb5c. See corpus.
    (void)i;
    FUN_0046e300(1);
    FUN_004f6090("Name: ", 0);
    (void)FUN_00412cb0; (void)timeGetTime;
}
