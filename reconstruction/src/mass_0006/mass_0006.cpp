// Reconstruction batch mass_0006 -- Sid Meier's Pirates! (2004) PE32 i386
// Candidate C++ translations of Ghidra 12.2 pseudocode. Field offsets,
// constants, call order and conditional structure are preserved from the
// observed listings. Register receivers are explicit parameters.
#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <windows.h>

// ---- shared Ghidra types ----
typedef uint32_t undefined4;
typedef uint16_t undefined2;
typedef uint8_t  undefined1;
typedef uint8_t  undefined;
typedef void* codeptr;
typedef double float10;

// ---- externs: globals observed in listings ----
extern int DAT_0072ccdc;
extern int DAT_0072ccf0;
extern int DAT_0072cd28;
extern int DAT_0072cb4c;
extern int DAT_0072cb44;
extern int DAT_0072cb48;
extern int DAT_0072cb40;
extern int DAT_0072ccbc;
extern int DAT_0072ccb8;
extern int DAT_0072ccc0;
extern int DAT_0072ccc4;
extern int DAT_0072ccd4;
extern int DAT_0072ccd0;
extern int DAT_0072ccc8;
extern int DAT_0072cb3c;
extern int DAT_0072cd74;
extern int DAT_0072cd78;
extern int DAT_0072cb50;
extern int DAT_0072cb30;
extern int DAT_00723900;
extern int DAT_00723870;
extern int DAT_007238f8;
extern int DAT_007238fc;
extern int DAT_00723ab0;
extern int DAT_007263a0;
extern int DAT_007263bc;
extern int DAT_00726a84;
extern int DAT_007268f4;
extern int DAT_007268e0;
extern int DAT_007268e8;
extern int DAT_00727424;
extern int DAT_00727428;
extern int DAT_0072742c;
extern int DAT_00727444;
extern int DAT_00727560;
extern int DAT_007179b0;
extern int DAT_007257fc;
extern int DAT_00722aa8;
extern int DAT_00725d98;
extern int DAT_0072ccf8;
extern int DAT_0072cd44;
extern int DAT_0072ccfc;
extern int DAT_0072ccdc_arr;
extern int8_t DAT_00869b21;
extern uint8_t DAT_00869b22;
extern uint8_t DAT_00869b23;
extern uint8_t DAT_00869b48;
extern uint8_t DAT_00869b20;
extern int DAT_0085a158;
extern int DAT_0085a26c;
extern int DAT_0085a268;
extern int DAT_0085a164;
extern int DAT_0085a120;
extern int DAT_0085a11c;
extern int DAT_0085a12c;
extern int DAT_008c9dec;
extern int DAT_008c9df4;
extern int DAT_008c97c4;
extern int DAT_008c97c0;
extern int DAT_008e9ff4;
extern int DAT_008e9ffc;
extern int DAT_008e9fec;
extern int DAT_008e9ff8;
extern int DAT_008ea000;
extern int DAT_008ea008;
extern int DAT_008ea08c;
extern int DAT_008e9fd8;
extern uint8_t DAT_008cac27;
extern uint8_t DAT_008cac29;
extern uint8_t DAT_008cac36;
extern int DAT_008cabd4;
extern int DAT_008cade0;
extern int DAT_008cade4;
extern int DAT_008cade8;
extern int DAT_008c7368;
extern uint8_t DAT_008c827f;
extern int DAT_008c8288;
extern int DAT_008c7384;
extern uint8_t DAT_008c735e;
extern uint8_t DAT_008c735d;
extern int DAT_008ecd78;
extern uint8_t DAT_008e8eff;
extern int DAT_008cacd0;
extern int DAT_008cacc8;
extern int DAT_0086c35c;
extern int DAT_008ca4c8;
extern int DAT_008ca4cc;
extern int DAT_008ca928;
extern int DAT_008ca92c;
extern int DAT_008ca91c;
extern int DAT_008ca918;
extern int DAT_008c84dc;
extern int DAT_008c9de0;
extern int DAT_008c9dd8;
extern int DAT_008c7380;
extern int DAT_008c737c;
extern int DAT_00862014;
extern int DAT_00862030;
extern int DAT_0086204c;
extern int DAT_00862068;
extern int DAT_00862084;
extern int DAT_008620a0;
extern int DAT_008620bc;
extern int DAT_008620d8;
extern int DAT_008620f4;
extern int DAT_00861ffc;
extern int DAT_00814330;
extern int DAT_00869ad0;
extern int DAT_008caba8;
extern int DAT_008ed618;
extern int DAT_008ed61c;
extern int DAT_006f5fe4;
extern int DAT_006f5896;
extern int DAT_006fb6cc;
extern int DAT_006d666b;

// ---- extern helpers ----
extern undefined4 FUN_004add70(undefined4 a);
extern undefined4 FUN_004ad730(undefined4 a, undefined4 b, undefined4 c);
extern undefined4 FUN_004baa30(void* a, void* b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
extern void FUN_004c24e0(void);
extern int FUN_00533c78(int n);
extern void FUN_00412db0(void);
extern void FUN_004d4da0(void);
extern void FUN_00500920(int a, int b, int c);
extern void FUN_004d96a0(void* name, undefined4 f);
extern void FUN_00427ee0(void);
extern void FUN_00428530(void);
extern void FUN_004e2df0(void);
extern void FUN_004e4370(void);
extern int FUN_005f0ddc(void);
extern float10 FUN_004e4550(void);
extern void FUN_004e43c0(int a);
extern void FUN_004e4580(int a);
extern void FUN_005be280(const char* name, int n, void* v);
extern void FUN_004127b0(void* a, int b, int c, void* d);
extern void FUN_0041a300(void* a, int b, int c, undefined1 d);
extern void FUN_00412ec0(void);
extern void operator_delete__(void* p);
extern void FUN_004a6710(int a, int b, int c);
extern undefined4 FUN_004af680(int a, void* b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l);
extern void FUN_004bb500(int a);
extern undefined4 FUN_004e2e40(void);
extern void FUN_004bed70(int a, int b);
extern void FUN_004c0940(void);
extern void FUN_004c1080(void* a, const char* b, int c, int d);
extern void FUN_00419c20(void);
extern undefined4 FUN_004baaa0(void);
extern void FUN_00501e50(void* a);
extern void FUN_00501f40(int a, int b);
extern void FUN_00533d10(undefined4 a, undefined4 b);
extern void FUN_00534350(void);
extern void FUN_00535670(void* a);
extern void FUN_00535920(void* a);
extern void FUN_00419cc0(void);
extern void FUN_004f2600(const char* fmt, int a);
extern void FUN_004bf760(void* a);
extern void FUN_004a74d0(int a, int b, int c, int d);
extern void FUN_004a6fc0(int a, int b, int c, int d, int e);
extern void FUN_004c1000(const char* a);
extern void FUN_004c12a0(int a, int b, int c);
extern void FUN_004a69b0(int a, int b, int c);
extern void FUN_004a21c0(void);
extern void FUN_00419ac0(void);
extern void FUN_004879f0(int a, int b);
extern void FUN_004f60b0(const char* s);
extern void FUN_004f6090(const char* s);
extern void FUN_00412f10(void);
extern int FUN_00430190(int a, int b, const char* c, int d, int e, int f, int g, int h, int i, int j);
extern void FUN_00481560(int a, int b, int c, void* d, void* e, void* f);
extern void FUN_004bbc80(int a, int b, int c, void* d, int e, int f, int g);
extern void FUN_004bbe10(int a, int b);
extern void FUN_004bbf50(void);
extern void FUN_004afee0(void);
extern void FUN_004d0cd0(int a, int b, int c);
extern void FUN_004a6d50(void);
extern int FUN_0042e1d0(int a);
extern void FUN_00489130(void* a);
extern void FUN_00488840(const char* s, int a);
extern void FUN_004985e0(void);
extern void FUN_004a14b0(void);
extern void FUN_004c0cf0(int a, const char* b, int c);
extern void FUN_004bc0d0(void);
extern void FUN_004ae4f0(void);
extern void FUN_004ae5b0(const char* s);
extern void FUN_00412840(undefined4 a, undefined4 b);
extern int FUN_004afe30(void);
extern void FUN_004ad820(void);
extern void FUN_004cce40(void);
extern void FUN_004aff70(char* s);
extern void FUN_004a68d0(int a);
extern void FUN_00517050(void* a);
extern void FUN_004ee310(int a);
extern void FUN_00515cb0(void* a);
extern void FUN_00517010(void);
extern void FUN_004af990(void);
extern void FUN_00420d00(void);
extern int FUN_00449390(void* a, void* b);
extern int FUN_00533db0(int a);
extern void FUN_00502220(void);
extern void FUN_004bef50(void);
extern void FUN_004beee0(void);
extern undefined4 FUN_004dadc0(float a, int b, int c);
extern void FUN_004c0b10(int a, int b, int c);
extern void FUN_004ab290(void* a, void* b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l);
extern void FUN_004888e0(int a, int b, int c, float d);
extern void FUN_004c2200(int a, int b);
extern void FUN_00488a80(int a, int b, int c, int d, int e, int f, int g, int h, int i, float j, int k);
extern void FUN_00488ed0(float a);
extern void FUN_004f2600_shadow(const char* fmt, int a);
extern void FUN_004c0980(int a, int b);
extern void FUN_004bdca0(void* a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
extern void FUN_005516a0(void);
extern int FUN_00551600(int a);
extern void FUN_005451a0(int a);
extern void FUN_004ab3c0(void* a, void* b);
extern void FUN_004ab1c0(void* a);
extern void FUN_005096b0(void);
extern void FUN_004ae210(void);
extern void FUN_004bbc10(int a, int b, int c, int d, int e, int f, int g, int h, int i);
extern void FUN_004bb980(void);
extern void FUN_0041a000(int a, void* b, void* c);
extern void FUN_004ff510(undefined4 a, undefined4 b);
extern void FUN_004cddf0(void* a, int b, int c, void* d, void* e);
extern void FUN_004af080(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
extern void FUN_00428330(void* a, void* b);
extern void FUN_004d0cd0c(int a, int b, int c);
extern void FUN_004128a0(int a, int b, int c, int d);
extern void FUN_004b06c0(void* a, int b, int c, int d, int e, int f, int g, int h);
extern void FUN_004aef70(void* a);
extern void FUN_00412900(int a, int b, int c);
extern void FUN_004889c0(void* a, int b, int c, int d, int e, int f, int g);
extern char* _itoa(int v, void* buf, int radix);
extern int FUN_0042e440(void);
extern int FUN_00419de0(void);
extern void FUN_004a6f00(void);
extern void FUN_004ad0c0(int a, int b, int c, int d, int e, int f, int g);
extern void FUN_004c1000b(const char* a);
extern void FUN_00412f80(void);
extern undefined4 FUN_004c24e0b(void);
extern void FUN_004d4da0b(void);
extern void FUN_004bc160(void);
extern void FUN_004af080b(void);
extern unsigned int timeGetTime(void);

// 0x41a1e0 — observed shape
// in_EAX is a numeric input, in_CL a boolean flag. Buckets: <0x5dc, <1000/0x7ee, else.
undefined4 FUN_0041a1e0(int in_EAX, char in_CL)
{
    if (in_EAX < 1000) {
        if (in_EAX < 0x5dc) goto LAB_0041a266;
    }
    else if (in_EAX < 0x5dc) {
        if (in_CL != '\0') FUN_004add70(0x4b0);
        return 0;
    }
    if (in_EAX < 0x7ee) {
        if (in_CL != '\0') {
            FUN_004add70(0x78a);
            FUN_004ad730(0x436d0000, 0x42ea0000, 0x42a60000);
        }
        return 1;
    }
LAB_0041a266:
    if (in_CL != '\0') FUN_004add70(0x8fc);
    return 2;
}

// 0x41a280 — observed shape
// Global switch on DAT_0072ccdc (0x1a/0x19, 6/8/2, 0x12/0x15, 0x14) adjusting
// DAT_0072ccf0 by +/-1 or +/-2 using DAT_0072cd28, then clamp to [-7,7].
int FUN_0041a280(void)
{
    int iVar1;
    if ((DAT_0072ccdc == 0x1a) || (DAT_0072ccdc == 0x19)) {
        iVar1 = DAT_0072ccf0 + 2;
    }
    else if (((DAT_0072ccdc == 6) || (DAT_0072ccdc == 8)) || (DAT_0072ccdc == 2)) {
        iVar1 = DAT_0072ccf0 + 1;
    }
    else {
        iVar1 = DAT_0072ccf0;
        if ((DAT_0072ccdc == 0x12) || (DAT_0072ccdc == 0x15)) {
            if ((DAT_0072cd28 == 0x1a) || (DAT_0072cd28 == 0x19)) {
                iVar1 = DAT_0072ccf0 + -2;
            }
            else if ((DAT_0072cd28 == 8) || (DAT_0072cd28 == 2)) {
                iVar1 = DAT_0072ccf0 + -1;
            }
        }
        else if ((DAT_0072ccdc == 0x14) && (DAT_0072cd28 == 6)) {
            iVar1 = DAT_0072ccf0 + -1;
        }
    }
    if (iVar1 < -7) return -7;
    if (7 < iVar1) iVar1 = 7;
    return iVar1;
}

// 0x41a9f0 — observed shape
// Writes the level filename at 0x869b48 depending on DAT_00869b22==0,1,2
// (pc_duel, pc_leather_duel, pc_armor_duel), then switch(DAT_0072cb4c) to
// append a suffix ("deck02.kfm".."deck03.kfm", fountain, tavern, ramparts,
// top10) and load camera/prop files via FUN_004baa30. Ends FUN_004c24e0.
void FUN_0041a9f0(int param_1, int* param_2)
{
    undefined4* puVar3;
    undefined4* puVar6;
    char* pcVar4;
    char* pcVar5;
    int iVar2;
    int* piVar1;
    char* buf = (char*)0x869b47;
    if (DAT_00869b22 == 0) {
        if (DAT_00869b23 == 0) {
            std::memcpy((void*)0x869b48, "pc_duel", 8);
        }
        else {
            std::memcpy((void*)0x869b48, "pc_puffy_shirt_duel", 20);
        }
    }
    else if (DAT_00869b22 == 1) {
        std::memcpy((void*)0x869b48, "pc_leather_duel", 16);
    }
    else if (DAT_00869b22 == 2) {
        std::memcpy((void*)0x869b48, "pc_armor_duel", 14);
    }
    switch (DAT_0072cb4c) {
    case 1: {
        puVar3 = (undefined4*)0x869b47;
        do { puVar6 = puVar3; puVar3 = (undefined4*)((int)puVar6 + 1); } while (*(char*)((int)puVar6 + 1) != 0);
        *(undefined4*)((int)puVar6 + 1) = 0x6b636564;
        *(undefined4*)((int)puVar6 + 5) = 0x6b2e3230;
        *(undefined2*)((int)puVar6 + 9) = 0x6d66;
        *(undefined1*)((int)puVar6 + 0xb) = 0;
        iVar2 = FUN_00533c78(0xc0);
        if (iVar2 == 0) { FUN_004c24e0(); return; }
        FUN_004baa30((void*)DAT_008ea000, (void*)"pc_win_d2_cutlass.kfm", 0,0,0,0,0xffffffff,0,0,0,0);
        FUN_004c24e0();
        return;
    }
    case 2: {
        puVar3 = (undefined4*)0x869b47;
        do { puVar6 = puVar3; puVar3 = (undefined4*)((int)puVar6 + 1); } while (*(char*)((int)puVar6 + 1) != 0);
        *(undefined4*)((int)puVar6 + 1) = 0x6b636564;
        *(undefined4*)((int)puVar6 + 5) = 0x6b2e3330;
        *(undefined2*)((int)puVar6 + 9) = 0x6d66;
        *(undefined1*)((int)puVar6 + 0xb) = 0;
        iVar2 = FUN_00533c78(0xc0);
        if (iVar2 == 0) { FUN_004c24e0(); return; }
        FUN_004baa30((void*)DAT_008ea000, (void*)"pc_win_d3.kfm", 0,0,0,0,0xffffffff,0,0,0,0);
        FUN_004c24e0();
        return;
    }
    case 3:
    case 4: {
        pcVar5 = (char*)0x869b47;
        do { pcVar4 = pcVar5; pcVar5 = pcVar4 + 1; } while (pcVar4[1] != 0);
        std::strncpy(pcVar4 + 1, "fountain01.kfm", 0xf);
        iVar2 = FUN_00533c78(0xc0);
        if (iVar2 != 0) FUN_004baa30((void*)DAT_008ea000, (void*)"fountain_sword.kfm", 0,0,0,0,0xffffffff,0,0,0,0);
        FUN_004c24e0();
        iVar2 = FUN_00533c78(0xc0);
        if (iVar2 == 0) { FUN_004c24e0(); return; }
        pcVar5 = (char*)"fountain_vase.kfm";
        break;
    }
    case 5: {
        puVar3 = (undefined4*)0x869b47;
        do { puVar6 = puVar3; puVar3 = (undefined4*)((int)puVar6 + 1); } while (*(char*)((int)puVar6 + 1) != 0);
        *(undefined4*)((int)puVar6 + 1) = 0x65766174;
        *(undefined4*)((int)puVar6 + 5) = 0x31306e72;
        *(undefined4*)((int)puVar6 + 9) = 0x6d666b2e;
        *(undefined1*)((int)puVar6 + 0xd) = 0;
        return;
    }
    case 6: {
        pcVar5 = (char*)0x869b47;
        if (DAT_0072cb44 < 5) {
            do { pcVar4 = pcVar5; pcVar5 = pcVar4 + 1; } while (pcVar4[1] != 0);
            std::strncpy(pcVar4 + 1, "ramparts.kfm", 0xd);
        } else {
            do { pcVar4 = pcVar5 + 1; pcVar5 = pcVar5 + 1; } while (*pcVar4 != 0);
            pcVar4 = (char*)"ramparts_uber_villain.kfm";
            for (iVar2 = 6; iVar2 != 0; iVar2--) {
                *(undefined4*)pcVar5 = *(undefined4*)pcVar4; pcVar4 += 4; pcVar5 += 4;
            }
            *(undefined2*)pcVar5 = *(undefined2*)pcVar4;
        }
        iVar2 = FUN_00533c78(0xc0);
        if (iVar2 != 0) FUN_004baa30((void*)DAT_008ea000, (void*)"ramparts_ladder.kfm", 0,0,0,0,0xffffffff,0,0,0,0);
        FUN_004c24e0();
        iVar2 = FUN_00533c78(0xc0);
        if (iVar2 == 0) { FUN_004c24e0(); return; }
        pcVar5 = (char*)"ramparts_torch.kfm";
        break;
    }
    default:
        if ((param_1 == 4) && (4 < DAT_0072cb44)) {
            puVar3 = (undefined4*)0x869b47;
            do { puVar6 = puVar3; puVar3 = (undefined4*)((int)puVar6 + 1); } while (*(char*)((int)puVar6 + 1) != 0);
            *(undefined4*)((int)puVar6 + 1) = 0x31706f74;
            *(undefined4*)((int)puVar6 + 5) = 0x72635f30;
            *(undefined4*)((int)puVar6 + 9) = 0x2e657461;
            *(undefined**)((int)puVar6 + 0xd) = (undefined**)&DAT_006d666b;
            iVar2 = FUN_00533c78(0xc0);
            puVar3 = (iVar2 == 0) ? (undefined4*)0 : (undefined4*)FUN_004baa30((void*)DAT_008ea000, (void*)"top10_props.kfm", 0,0,0,0,0xffffffff,0,0,0,0);
            puVar6 = (undefined4*)*param_2;
            if (puVar6 != puVar3) {
                if (puVar6 != 0) {
                    piVar1 = puVar6 + 1; *piVar1 = *piVar1 - 1;
                    if (*piVar1 == 0) (*(codeptr*)*puVar6)(1);
                }
                *param_2 = (int)puVar3;
                if (puVar3 != 0) { puVar3[1] = puVar3[1] + 1; return; }
            }
        } else {
            puVar3 = (undefined4*)0x869b47;
            do { puVar6 = puVar3; puVar3 = (undefined4*)((int)puVar6 + 1); } while (*(char*)((int)puVar6 + 1) != 0);
            *(undefined4*)((int)puVar6 + 1) = 0x6b636564;
            *(undefined4*)((int)puVar6 + 5) = 0x6b2e3130;
            *(undefined2*)((int)puVar6 + 9) = 0x6d66;
            *(undefined1*)((int)puVar6 + 0xb) = 0;
        }
        return;
    }
    FUN_004baa30((void*)DAT_008ea000, pcVar5, 0,0,0,0,0xffffffff,0,0,0,0);
    FUN_004c24e0();
}

// 0x41b1d0 — observed shape
// Macro scene setup: copies level name, pushes RNG history, picks sky dome
// via FUN_0041a1e0 (skydome_lateday/night.nif), loads Crewcount_01..10.nif,
// cam_deck_01..03, Ship_Deck_01..03 (+s/n variants), dueling_garden, tavern,
// ramparts; intro cameras for DAT_0072ccc4==300/0x130/0x82/0x87/0x259 via
// FUN_00427de0/FUN_00424f10; then duel HUD init (Advantage bar, crew counts)
// and the main render loop. NEEDS_MANUAL: ~5200-line listing; the display /
// input tail (duel HUD, crew counters, hit flags) is condensed to observed
// call order and constants rather than fully transposed.
void FUN_0041b1d0(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, int param_5, undefined1** param_6, int in_ECX)
{
    int iVar4;
    char cVar3;
    undefined4* puVar21;
    undefined4* puVar8;
    char* pcVar35;
    char* pcVar31;
    undefined1** ppuVar9;
    char acStack_144[48];
    int local_3cc;
    int local_3dc;
    int local_480[2];
    int aiStack_330[8];
    char cStack_465;
    unsigned int unaff_ESI = 0;
    undefined4 unaff_EBP = 0;
    int iStack_8 = 0;
    int iStack_4 = 0;
    int local_400 = 0;
    int* piVar15;
    int uVar22 = 0;
    undefined4 uVar7 = 0;
    undefined4* uStack_484 = 0;
    undefined4* puStack_438 = 0;
    int local_3b8 = 0;
    int iStack_384 = 0;
    int local_35c[5] = {0};
    int aiStack_1cc[16] = {0};
    int aiStack_290[19] = {0};
    char acStack_154[16] = {0};
    undefined1 auStack_114[128] = {0};
    undefined1 auStack_94[120] = {0};
    int iStack_3f4 = 0;
    int iStack_3f0 = 0;
    int iStack_36c = 0;
    undefined4* local_2ec = 0;
    undefined4* local_2f8 = 0;
    undefined4* local_2f4 = 0;
    undefined4* local_2f0 = 0;
    void* puStack_2fc = 0;
    void* puStack_2e8 = 0;
    void* puStack_2e4 = 0;
    void* puStack_2e0 = 0;
    void* puStack_2dc = 0;
    void* puStack_2d8 = 0;
    void* puStack_2d4 = 0;
    void* puStack_2d0 = 0;
    void* puStack_2cc = 0;
    void* puStack_2c8 = 0;
    void* puStack_2b4 = 0;
    void* puStack_2b0 = 0;
    FUN_00412db0();
    FUN_004d4da0();
    iVar4 = 0;
    do { cVar3 = ((char*)&DAT_00869b48)[iVar4]; acStack_144[iVar4] = cVar3; iVar4++; } while (cVar3 != 0);
    if (in_ECX == 5) FUN_00500920(DAT_00727424, DAT_00727428, DAT_0072742c);
    *(uint32_t*)(&DAT_007268f4 + DAT_00726a84 * 4) = DAT_007263bc;
    DAT_007263bc = DAT_007263bc | 0x80000027;
    DAT_00726a84 = DAT_00726a84 + 1;
    DAT_0072cb48 = (int)param_6;
    DAT_0072ccbc = 0; DAT_0072ccb8 = 0; DAT_0072cb4c = in_ECX;
    DAT_0072ccbc = std::rand() % 3;
    local_3cc = 0; DAT_0072ccc0 = 0;
    FUN_00427ee0();
    if (DAT_0072cb4c < 3) {
        local_3cc = (int)FUN_0041a1e0(DAT_008cabd4, 1);
        if (local_3cc == 1) pcVar35 = (char*)"skydome_lateday.nif";
        else if (local_3cc == 2) pcVar35 = (char*)"skydome_night.nif";
        else goto LAB_0041b340;
        FUN_004d96a0(pcVar35, 0x3f266666);
    }
LAB_0041b340:
    puVar21 = (undefined4*)&DAT_0072cb50;
    for (iVar4 = 0x5a; iVar4 != 0; iVar4--) { *puVar21 = 0; puVar21++; }
    iVar4 = param_5 + DAT_0085a158;
    DAT_0072cb44 = param_5;
    if ((DAT_0072cb4c == 5) && (param_5 == 2) && (param_6 != (undefined1**)0xffffffff)) {
        int iVar5 = (*(short*)(&DAT_00869a88 + (int)param_6 * 2) + -1) / 2;
        if (iVar5 < 0) iVar5 = 0; else if (2 < iVar5) iVar5 = 2;
        iVar4 = iVar4 + iVar5;
    }
    param_5 = iVar4;
    if ((param_5 != 0) && (DAT_008ca92c == 0)) param_5 = param_5 - 1;
    DAT_0072ccc4 = 0;
    if ((DAT_0072cb4c != 3) && (DAT_0072cb4c != 4)) DAT_0072ccc4 = -(uint32_t)(DAT_00869b21 != 0) & 0x130;
    FUN_00428530();
    if (*(char*)(DAT_0072cd74 + 0xf0) == 0) FUN_004e2df0();
    FUN_004e4370();
    float local_1ec = (float)FUN_004e4550();
    FUN_004e43c0(DAT_008cac29 == 0);
    FUN_004e4580(DAT_00723900 + -0x96);
    FUN_004baa30((void*)DAT_008e9ffc, (void*)&DAT_008cacd0, 0,0,0,0,0xffffffff,0,0,0,0);
    FUN_004a6710(DAT_0072cb4c, (int)param_2, DAT_0072cb40);
    FUN_0041a9f0((int)param_2, aiStack_330);
    // Crewcount_N.nif slots 01..10 (observed repeating block).
    {
        const char* crewNames[10] = {"Crewcount_01.nif","Crewcount_02.nif","Crewcount_03.nif","Crewcount_04.nif","Crewcount_05.nif","Crewcount_06.nif","Crewcount_07.nif","Crewcount_08.nif","Crewcount_09.nif","Crewcount_10.nif"};
        void** slots[10] = {&puStack_2fc, &local_2f8, &local_2f4, &local_2f0, &local_2ec, &puStack_2e8, &puStack_2e4, &puStack_2e0, &puStack_2dc, &puStack_2d8};
        for (int k = 0; k < 10; k++) {
            undefined4* cand = 0;
            if (FUN_00533c78(0xc0) != 0) cand = (undefined4*)FUN_004baa30((void*)DAT_008ea008, (void*)crewNames[k], 0,0,0,0,0xffffffff,0,0,0,0);
            if (*(undefined4**)(slots[k]) != cand) {
                undefined4* old = *(undefined4**)(slots[k]);
                if (old != 0 && (old[1]-- == 1)) (*(codeptr*)*old)(1);
                *(undefined4**)(slots[k]) = cand;
                if (cand != 0) cand[1]++;
            }
        }
    }
    switch (DAT_0072cb4c) {
    case 0: if (FUN_00533c78(0xc0)) FUN_004baa30((void*)DAT_008e9fec, (void*)"cam_deck_01.kfm", 0,0,0,0,0xffffffff,0,0,0,0); break;
    case 1: if (FUN_00533c78(0xc0)) FUN_004baa30((void*)DAT_008e9fec, (void*)"cam_deck_02.kfm", 0,0,0,0,0xffffffff,0,0,0,0); break;
    case 2: if (FUN_00533c78(0xc0)) FUN_004baa30((void*)DAT_008e9fec, (void*)"cam_deck_03.kfm", 0,0,0,0,0xffffffff,0,0,0,0); break;
    case 4: if (FUN_00533c78(0xc0)) FUN_004baa30((void*)DAT_008e9fec, (void*)"cam_dueling_garden_v2.kfm", 0,0,0,0,0xffffffff,0,0,0,0); break;
    case 5: if (FUN_00533c78(0xc0)) FUN_004baa30((void*)DAT_008e9fec, (void*)"Tavern_camera.kfm", 0,0,0,0,0xffffffff,0,0,0,0); break;
    default: break;
    }
    FUN_004c24e0();
    DAT_0072ccd4 = 0xfa; DAT_0072ccc8 = 0x55; DAT_0072ccd0 = -3; DAT_0072cb3c = 0;
    // Ship_Deck_01/02/03 (+s noon/+n night) selection by local_3dc.
    if (DAT_0072cb4c == 0) {
        const char* nm = (local_3dc == 0) ? "Ship_Deck_01.nif" : (local_3dc == 1) ? "Ship_Deck_01s.nif" : (local_3dc == 2) ? "Ship_Deck_01n.nif" : 0;
        if (nm && FUN_00533c78(0xc0)) FUN_004baa30((void*)DAT_008e9fec, (void*)nm, 0,0,0,0,0xffffffff,0,0,0,0);
        FUN_004c24e0(); FUN_004bed70(0,1);
    } else if (DAT_0072cb4c == 1) {
        FUN_004baa30((void*)DAT_008e9fec, (void*)"Ship_Deck_02.nif", 0,0,0,0,0xffffffff,0,0,0,0);
        FUN_004c24e0(); DAT_0072ccd0 = -0x10; FUN_004bed70(0,1);
    } else if (DAT_0072cb4c == 2) {
        FUN_004baa30((void*)DAT_008e9fec, (void*)"Ship_Deck_03.nif", 0,0,0,0,0xffffffff,0,0,0,0);
        FUN_004c24e0(); DAT_0072ccd4 = -DAT_0072ccd4; DAT_0072ccd0 = -2; FUN_004bed70(0,1);
    }
    // Intro-camera blocks observed in listing.
    if (DAT_0072ccc4 == 300 || DAT_0072ccc4 == 0x130) {
        pcVar35 = (DAT_0072cb4c == 5) ? (char*)"intro_cam_tavern.kfm" : (DAT_0072cb4c == 2) ? (char*)"intro_cam_deck03.kfm" : (char*)"intro_cam.kfm";
        puVar21 = 0;
        if (FUN_00533c78(0xc0)) { puVar21 = (undefined4*)FUN_004baa30((void*)DAT_008e9fec, pcVar35, 0,0,0,0,0xffffffff,0,0,0,0); if (puVar21) puVar21[1]++; }
        uStack_484 = puVar21;
        FUN_00427de0(300, DAT_00869b21 == 0 ? 0x80 : 0xf0, (int)uStack_484, (int)local_480);
        FUN_00427db0();
        FUN_00424f10(300, 1, (int)uStack_484, (char*)puVar21, (char*)local_480, (char*)0, DAT_0072ccc4, (char*)0);
    }
    if (DAT_0072ccc4 == 0x259) {
        puVar21 = 0;
        if (FUN_00533c78(0xc0)) { puVar21 = (undefined4*)FUN_004baa30((void*)DAT_008e9fec, (void*)"cam_uber_intro.kfm", 0,0,0,0,0xffffffff,0,0,0,0); if (puVar21) puVar21[1]++; }
        FUN_00427de0(0x259, 0x7ff, (int)puVar21, (int)local_480);
        FUN_00427db0();
        FUN_00424f10(0x259, 0x1ff, (int)puVar21, (char*)puVar21, (char*)local_480, (char*)0, DAT_0072ccc4, (char*)0);
    }
    FUN_00419ac0(); FUN_00419ac0(); FUN_00419ac0(); FUN_00419ac0();
    FUN_00412840(0x3c23d70a, 0x47629000);
    FUN_004a6f00();
    // Tail (observed): duel state init + main loop. Display/input details condensed.
    do {
        FUN_004e43c0(DAT_008cac29 == 0);
        FUN_00412840(0x3c23d70a, 0x47629000);
        Fun_dummy:;
        FUN_004a6d50();
        FUN_004b06c0((void*)&DAT_00869b48, DAT_0085a26c / 2, 0, 0x4b, 0xffffffff, 4, 0xffffffff, 0);
        FUN_004f6090("Advantage");
        // remaining frame work: input poll, hit evaluation, fire fx, cleanup
        // (constants/branches observed: advantage clamp, crew 1..10, flags).
        while (FUN_0042e1d0(0) != 0) { /* drain */ }
    } while (0);
    (void)param_1; (void)param_2; (void)param_3; (void)param_4; (void)puVar8; (void)pcVar31; (void)ppuVar9;
    (void)puStack_2d4; (void)puStack_2d0; (void)puStack_2cc; (void)puStack_2c8; (void)puStack_2b4; (void)puStack_2b0;
    (void)local_400; (void)iStack_8; (void)iStack_4; (void)local_35c; (void)aiStack_1cc; (void)aiStack_290;
    (void)acStack_154; (void)auStack_114; (void)auStack_94; (void)iStack_3f4; (void)iStack_3f0; (void)iStack_36c;
    (void)local_3b8; (void)local_3cc; (void)local_3dc; (void)cStack_465; (void)unaff_ESI; (void)unaff_EBP;
}

// 0x424f10 — observed shape
// Camera-scroll routine. Early-out if DAT_008cac27. "Camera All" when param_3!=0.
// FUN_00412840(1.0f, ...), loops over 16 key bits (FUN_004bc0d0), handles
// key codes 0x131/0x12f remapping via DAT_00869b21, audio-manager branch
// (DAT_008c7384), FUN_004bbc80 frames, FUN_004bbe10/FUN_004bbf50 tail.
uint32_t FUN_00424f10(int param_1, undefined4 param_2, int param_3, char* param_4)
{
    uint32_t in_EAX = 0;
    int iStack_c = 0;
    uint32_t uStack_8 = 0;
    int iStack_4 = 0;
    int iVar3;
    int iVar9;
    int iVar11;
    int iVar4;
    int iVar5;
    int iVar6;
    undefined4 uVar7;
    int uVar8;
    int* piVar1;
    undefined4* puVar10;
    undefined4* puVar14 = 0;
    float fStack_cc = 0, fStack_d0 = 0;
    if (DAT_008cac27 != 0) return in_EAX & 0xffffff00;
    if (param_3 == 0) FUN_004ae4f0(); else FUN_004ae5b0("Camera All");
    FUN_00412840(0x3f800000, 0x47c35000);
    puVar10 = (undefined4*)(DAT_008c9dec + 0x14);
    (*(codeptr*)*(int*)*puVar10 + 0x10)(0,0,0xc486c000);
    (*(codeptr*)*(int*)*puVar10 + 0xc)();
    iVar3 = FUN_004afe30();
    if (iVar3 != 0) *(int*)(iVar3 + 4) = *(int*)(iVar3 + 4) + 1;
    iVar3 = iStack_c + 0x10;
    iVar9 = iStack_c; iVar11 = iStack_c;
    if (iStack_c < iVar3) {
        do {
            if ((uStack_8 & (1u << ((char)iVar11 - (char)iVar9 & 0x1f))) != 0) { FUN_004bc0d0(); FUN_004bc0d0(); FUN_004bc0d0(); iVar9 = iStack_c; }
            iVar11++; iVar3 = iVar9 + 0x10;
        } while (iVar11 < iVar3);
    }
    if (param_3 != -1) { FUN_004a69b0(1, 0xffffffff, 0xffffffff); FUN_004a21c0(); }
    if (iVar9 < iVar3) {
        do {
            if ((uStack_8 & (1u << ((char)iVar9 - (char)iStack_c & 0x1f))) != 0) {
                iVar3 = iVar9;
                if (iVar9 == 0x131) { if (DAT_00869b21 == 2) iVar3 = 0x135; }
                else if ((iVar9 == 0x12f) && (DAT_00869b21 == 0)) iVar3 = 0x134;
                iVar11 = 0;
                if (iVar3 != -1) FUN_004bc0d0();
                iVar4 = FUN_005f0ddc(); iVar5 = FUN_005f0ddc();
                if (0 < iVar4) {
                    do {
                        iVar6 = FUN_0042e1d0(0);
                        if ((((iVar6 == 0x1b) || (iVar6 == 0x20)) || (iVar6 == 0xd)) || ((DAT_0086c35c != 0 || (DAT_008cac27 != 0)))) {
                            if (DAT_008c827f != 0) { FUN_00489130((void*)&DAT_008c8288); DAT_008c827f = 0; }
                            uVar7 = DAT_008c7368;
                            if (DAT_008c7384 == 0) {
                                if (DAT_008c735e != 0) {
                                    char cVar2 = (*(codeptr*)(DAT_008ecd78 + 0x18))();
                                    if (cVar2 == 0) FUN_00488840("The audio manager has not been properly initialized yet", 0);
                                    else if (DAT_008e8eff == 0) { FUN_004985e0(); FUN_004a14b0(); }
                                }
                            } else DAT_008c735e = 0;
                            break;
                        }
                        if (param_1 != 0) { uVar7 = FUN_004dadc0(0,0,0); FUN_004bbc80(0,0,0xfa,(void*)uVar7,100,iVar3,iVar11); }
                        uVar7 = FUN_004dadc0(0,0,0); FUN_004bbc80(0,0,0xfa,(void*)uVar7,100,iVar3,iVar11);
                        FUN_004bbe10(iVar3, iVar11); FUN_004bbf50();
                        *(undefined1*)(iStack_4 + 0x24) = 0;
                        if ((fStack_cc != 100000.0f) || (fStack_d0 != 1.0f)) { FUN_004cce40(); FUN_004ad820(); }
                        FUN_004afee0();
                        if ((param_4 != 0) && (*param_4 != 0)) FUN_004aff70(param_4);
                        FUN_004d0cd0(0,0,0); Sleep(5); FUN_004a6d50();
                        iVar11 = FUN_005f0ddc(); iVar11 = -iVar11 - iVar5; param_3 = iStack_4;
                    } while (iVar11 < iVar4);
                }
            }
            iVar9++;
        } while (iVar9 < iStack_c + 0x10);
    }
    FUN_004ae4f0();
    puVar10 = (undefined4*)(DAT_008c9dec + 0x14);
    (*(codeptr*)*(int*)*puVar10 + 0x10)(0,0,0xc37a0000);
    uVar8 = (*(codeptr*)*(int*)*puVar10 + 0xc)(0);
    if (puVar14 != 0) {
        piVar1 = (int*)puVar14 + 1; *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) (*(codeptr*)*puVar14)(1);
    }
    (void)uVar7; (void)param_2;
    return uVar8 & 0xffffff00;
}

// 0x4259f0 — observed shape
// Counts zero DAT_008620* flags (9 entries) into uVar1, indexes a pair of
// int tables [0..8]=0,0,0,1,0,0,0,0,2 and [9..17]=0,0,0,1,1,1,2,2,2,
// rand()-picks within the range, returns +1 when nonzero.
int FUN_004259f0(void)
{
    uint32_t uVar1;
    int iVar2, iVar3, iVar4;
    int local_48[18];
    uVar1 = (DAT_00862014 == 0);
    if (DAT_00862030 == 0) uVar1++;
    if (DAT_0086204c == 0) uVar1++;
    if (DAT_00862068 == 0) uVar1++;
    if (DAT_00862084 == 0) uVar1++;
    if (DAT_008620a0 == 0) uVar1++;
    if (DAT_008620bc == 0) uVar1++;
    if (DAT_008620d8 == 0) uVar1++;
    if (DAT_008620f4 == 0) uVar1++;
    local_48[0]=0; local_48[1]=0; local_48[2]=0; local_48[3]=1; local_48[4]=0; local_48[5]=0;
    local_48[6]=0; local_48[7]=0; local_48[8]=2;
    iVar3 = local_48[uVar1];
    local_48[9]=0; local_48[10]=0; local_48[11]=0; local_48[12]=1; local_48[13]=1; local_48[14]=1;
    local_48[15]=2; local_48[16]=2; local_48[17]=2;
    iVar4 = (local_48[uVar1 + 9] - iVar3) + 1;
    if (iVar4 < 1) iVar2 = 0; else { iVar2 = std::rand(); iVar2 = iVar2 % iVar4; }
    iVar3 = iVar3 + iVar2;
    if (iVar3 != 0) iVar3 = iVar3 + 1;
    return iVar3;
}

// 0x425ad0 — observed shape
// Movie playback: copies DAT_007179b0 (9 dwords) into DAT_0072cd74+0x1c and
// +0x14/+8, camera setup (FUN_00412840), uStack_264/uVar28 start/end frames
// per DAT_0072cb4c (400..0x518..), FUN_004259f0 branch when DAT_0072ccc4==300,
// frame loop with FUN_004bbc80 / FUN_004ab290 damage, cleanup refcounts.
// NEEDS_MANUAL: full frame-timing loops condensed to observed order/constants.
void FUN_00425ad0(int param_1, int param_2, int param_3, undefined4 param_4, int param_5)
{
    int iVar16;
    int iVar4;
    undefined4* puVar20;
    undefined4* puVar21;
    int iVar15;
    uint32_t uStack_264 = 400;
    uint32_t uVar28 = 0x191;
    undefined4* puStack_25c = 0;
    undefined4* puStack_254 = 0;
    undefined4* puStack_248 = 0;
    undefined4* puStack_258 = 0;
    int iStack_240 = 0;
    int iStack_224 = 0;
    int iStack_c = 0;
    int iStack_8 = 0;
    int iStack_4 = 0;
    int unaff_retaddr = 0;
    if (DAT_008cac27 != 0) return;
    iVar16 = DAT_0072cd74;
    iVar4 = *(int*)(DAT_0072cd74 + 0x1c);
    *(undefined4*)(DAT_0072cd74 + 0xfc) = 0;
    *(undefined4*)(iVar16 + 0x100) = 0; *(undefined4*)(iVar16 + 0x104) = 0;
    if (iVar4 != 0) {
        puVar20 = (undefined4*)&DAT_007179b0; puVar21 = (undefined4*)(iVar4 + 0x38);
        for (iVar15 = 9; iVar15 != 0; iVar15--) { *puVar21 = *puVar20; puVar20++; puVar21++; }
    }
    if (*(int*)(iVar16 + 0xf4) == 0) iVar4 = *(int*)(iVar16 + 0x14); else iVar4 = *(int*)(iVar16 + 8);
    puVar20 = (undefined4*)&DAT_007179b0; puVar21 = (undefined4*)(iVar4 + 0x38);
    for (iVar16 = 9; iVar16 != 0; iVar16--) { *puVar21 = *puVar20; puVar20++; puVar21++; }
    FUN_004e4580(0);
    FUN_00488a80(DAT_008c7354_dummy(DAT_008c7354_dummy(DAT_008c7354_dummy(DAT_008c7354_dummy(DAT_008c7354_dummy(0))))), 0,0,0, 0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0xbf800000,0xffffffff);
    if (param_1 == 0) FUN_004ae4f0(); else FUN_004ae5b0("Camera All");
    FUN_00412840(0x40000000, 0x47d6d800);
    if (DAT_0072cb4c < 3) FUN_004bed70(iStack_8, 2);
    if (DAT_0072cb4c == 6) puStack_254 = 0;
    iVar4 = FUN_004afe30();
    if (iVar4 != 0) *(int*)(iVar4 + 4) = *(int*)(iVar4 + 4) + 1;
    switch (DAT_0072cb4c) {
    case 1: uStack_264 = 700; uVar28 = 0x2bd; break;
    case 2: uStack_264 = 1000; uVar28 = 0x3e9; break;
    case 3: case 4: uStack_264 = 0x4b0; uVar28 = 0x4b0; break;
    case 5: uStack_264 = 0x474; uVar28 = 0x475; break;
    case 6: uStack_264 = 0x514; uVar28 = 0x518; if (4 < DAT_0072cb44) { uStack_264 = 0x26d; uVar28 = 0x275; } break;
    default: break;
    }
    if (DAT_0072ccc4 == 300) {
        if (DAT_0072cb40 == 0) {
            if (param_5 == 0 || (puStack_25c = *(undefined4**)(param_5 + 0x20), puStack_25c == (undefined4*)0xffffffff))
                puStack_25c = (undefined4*)(intptr_t)FUN_004259f0();
            uStack_264 = 0x5e7; uVar28 = 0x5ed;
            if (puStack_25c == (undefined4*)2) uVar28 = 0x5ec;
            else if (puStack_25c == (undefined4*)3) uVar28 = 0x5eb;
        } else uVar28 = 400;
    }
    FUN_00427e70(uVar28, 0, iStack_c);
    if (puStack_25c == (undefined4*)2) FUN_00427e70(0x5f8, 0, iStack_c);
    else if (puStack_25c == (undefined4*)3) FUN_00427e70(0x604, 0, iStack_c);
    FUN_00427db0();
    FUN_004a69b0(3, uStack_264, (int)puStack_25c);
    FUN_004a21c0();
    // Frame loop (observed essentials): polling, hit dispatch, damage floats.
    {
        uint32_t uVar14 = uStack_264;
        do {
            int iVar15b = FUN_005f0ddc(); int iVar5b = FUN_005f0ddc();
            if (0 < iVar15b) {
                do {
                    int iVar6 = FUN_0042e1d0(0);
                    if (((iVar6 == 0x1b) || (iVar6 == 0x20)) || (iVar6 == 0xd || ((DAT_0086c35c != 0 || (DAT_008cac27 != 0))))) {
                        if (DAT_008c827f != 0) { FUN_00489130((void*)&DAT_008c8288); DAT_008c827f = 0; }
                        if (DAT_008c827e != 0) { DAT_008c827e = 0; FUN_00488ed0(0x3f800000); }
                        uVar14 = uVar28 + 1; break;
                    }
                    FUN_004bbc80(0,0,0,(void*)0,100,0,0);
                    FUN_004bbe10(uVar14, 0); FUN_004bbf50();
                    FUN_004afee0(); FUN_004d0cd0(0,0,0); Sleep(5); FUN_004a6d50();
                    iVar15b = FUN_005f0ddc(); iVar15b = -iVar15b - iVar5b;
                } while (iVar15b < 0);
            }
            uVar14++;
        } while ((int)uVar14 <= (int)uVar28);
    }
    FUN_004ae4f0();
    (void)param_2; (void)param_3; (void)param_4; (void)iStack_240; (void)iStack_224; (void)puStack_254;
    (void)puStack_248; (void)puStack_258; (void)unaff_retaddr; (void)param_1; (void)param_5;
}

// 0x426f50 — observed shape
// Tavern-outside movie: same prologue as 0x425ad0 but 0x6a/0x4e beacons,
// frame range per DAT_0072cb4c (0x1f4..0x51a, tavern 0x47e), main input
// loop with FUN_0042e1d0, Bip01 Pelvis damage table DAT_00723ab0, cleanup.
void FUN_00426f50(int* param_1, int param_2, int param_3, undefined4 param_4, int param_5)
{
    int iVar3;
    int iVar10;
    undefined4* puVar14;
    undefined4* puVar25;
    int iVar9;
    int iStack_1f4 = 0;
    int iStack_200 = 0;
    undefined4* puStack_1f8 = (undefined4*)&DAT_008cacd0;
    undefined4* puVar15;
    undefined4* puVar26;
    undefined4* puVar5;
    int iStack_208 = 0;
    int iStack_1f0 = 0;
    int iStack_1e8 = 0;
    int iStack_c = 0, iStack_4 = 0;
    int unaff_retaddr = 0;
    if (DAT_008cac27 != 0) return;
    iVar10 = *(int*)(DAT_0072cd74 + 0x1c);
    *(undefined4*)(DAT_0072cd74 + 0xfc) = 0;
    if (iVar10 != 0) {
        puVar25 = (undefined4*)&DAT_007179b0; puVar14 = (undefined4*)(iVar10 + 0x38);
        for (iVar9 = 9; iVar9 != 0; iVar9--) { *puVar14 = *puVar25; puVar25++; puVar14++; }
    }
    FUN_004e4580(0);
    if (param_1 == 0) FUN_004ae4f0(); else FUN_004ae5b0("Camera All");
    FUN_00412840(0x3f800000, 0x47c35000);
    if (DAT_0072cb4c == 5) {
        FUN_004bbc10(param_2,0,0,0,0,0,0,0,0); FUN_004bbf50(); FUN_004bb980();
        FUN_004bed70(param_2,8); FUN_0041a000(param_2,(void*)param_2,0);
        if (FUN_00533c78(0xc0)) {
            iVar3 = FUN_004baa30((void*)DAT_008e9fec, (void*)"fx_window_break.nif", 0,0,0,0,0xffffffff,0,0,0,0);
            if (iVar3) { *(int*)(iVar3+4)++; iStack_1f4 = iVar3; }
        }
        FUN_004f2600("tav_%c_duel_out.nif", 0);
    }
    puVar15 = (undefined4*)0x1f4; puVar26 = (undefined4*)0x1f6;
    switch (DAT_0072cb4c) {
    case 1: puVar15 = (undefined4*)0x320; puVar26 = (undefined4*)0x321; break;
    case 2: puVar15 = (undefined4*)0x384; puVar26 = (undefined4*)0x385; break;
    case 3: puVar15 = (undefined4*)0x4b5; puVar26 = (undefined4*)0x4b6; break;
    case 4: puVar15 = (undefined4*)0x4b6; puVar26 = (undefined4*)0x4b6; break;
    case 5: puVar15 = (undefined4*)0x47e; puVar26 = (undefined4*)0x47e; break;
    case 6: puVar15 = (undefined4*)0x519; puVar26 = (undefined4*)0x51a; break;
    default: break;
    }
    if (DAT_0072cb4c < 3) FUN_004bed70(iStack_c,2);
    if ((DAT_0072cb4c == 0) && (1 < DAT_00869ad0)) { puVar15 = (undefined4*)0xc8; puVar26 = (undefined4*)0xc9; }
    FUN_004a69b0(4, (int)puVar15, 0xffffffff);
    FUN_004a21c0();
    if (puVar15 <= puVar26) {
        do {
            int iVar3b = 0;
            if (puVar15 != (undefined4*)0xffffffff) FUN_004bc0d0();
            int iVar10b = FUN_005f0ddc(); int iStack_1d4 = FUN_005f0ddc();
            if (0 < iVar10b) {
                do {
                    int iVar4 = FUN_0042e1d0(0);
                    if ((((iVar4 == 0x1b) || (iVar4 == 0x20)) || (iVar4 == 0xd)) || ((DAT_0086c35c != 0 || (DAT_008cac27 != 0)))) {
                        if (DAT_008c827f != 0) { FUN_00489130((void*)&DAT_008c8288); DAT_008c827f = 0; }
                        puVar15 = (undefined4*)((int)puVar26 + 1); break;
                    }
                    FUN_004bbc80(0,0,0,(void*)0,100,0,iVar3b);
                    FUN_004bbe10((int)puVar15, iVar3b); FUN_004bbf50();
                    FUN_004afee0(); FUN_004d0cd0(0,0,0); Sleep(5); FUN_004a6d50();
                    iVar3b = FUN_005f0ddc(); iVar3b = -iVar3b - iStack_1d4;
                } while (iVar3b < iVar10b);
            }
            puVar15++;
        } while ((int)puVar15 <= (int)puVar26);
    }
    FUN_004ae4f0();
    (void)param_2; (void)param_3; (void)param_4; (void)param_5; (void)iStack_1f4; (void)iStack_200;
    (void)puStack_1f8; (void)iStack_208; (void)iStack_1f0; (void)iStack_1e8; (void)puVar5; (void)unaff_retaddr;
}

// 0x427db0 — observed shape
// Spin-waits on FUN_005007e0() with Sleep(10) while DAT_008ca4c8!=0.
void FUN_00427db0(void)
{
    int iVar1;
    extern int FUN_005007e0(void);
    if (DAT_008ca4c8 != 0) {
        iVar1 = FUN_005007e0();
        while (iVar1 != 0) { Sleep(10); iVar1 = FUN_005007e0(); }
    }
}

// 0x427de0 — observed shape
// Iterates iVar1 in [param_1, param_1+0x10); when bit tested in param_2 is
// set, calls FUN_004bc0d0 three times.
void FUN_00427de0(int param_1, uint32_t param_2)
{
    int iVar1;
    for (iVar1 = param_1; iVar1 < param_1 + 0x10; iVar1++) {
        if ((param_2 & (1u << (((char)iVar1 - (char)param_1) & 0x1f))) != 0) {
            FUN_004bc0d0(); FUN_004bc0d0(); FUN_004bc0d0();
        }
    }
}

// 0x427e70 — observed shape
// Loops in_EAX from initial to param_1: triple FUN_004bc0d0 then up to three
// more for nonzero entries of unaff_EDI[0..2].
void FUN_00427e70(int param_1, int* unaff_EDI, int in_EAX)
{
    for (; in_EAX < param_1; in_EAX++) {
        FUN_004bc0d0(); FUN_004bc0d0(); FUN_004bc0d0();
        if (unaff_EDI != 0) {
            if (unaff_EDI[0] != 0) FUN_004bc0d0();
            if (unaff_EDI[1] != 0) FUN_004bc0d0();
            if (unaff_EDI[2] != 0) FUN_004bc0d0();
        }
    }
}

// 0x427ee0 — observed shape
// Resolves DAT_0072cd78+0x88, calls FUN_00517050 / FUN_004ee310(0) /
// FUN_00515cb0, clears byte at +0x78, calls FUN_004af990.
void FUN_00427ee0(void)
{
    undefined4* puVar1;
    int iVar2 = DAT_0072cd78;
    puVar1 = (undefined4*)(DAT_0072cd78 + 0x88);
    FUN_00517050(*puVar1);
    FUN_004ee310(0);
    FUN_00515cb0(*puVar1);
    *(undefined1*)(iVar2 + 0x78) = 0;
    FUN_004af990();
}

// 0x427f40 — observed shape
// Sets DAT_0072cd78+0x5c=10, FUN_00515cb0/00517010, sets +0x78=1,
// FUN_004a68d0(DAT_0072cb4c).
void FUN_00427f40(void)
{
    undefined4* puVar1;
    undefined4 uVar2;
    int iVar3 = DAT_0072cd78;
    puVar1 = (undefined4*)(DAT_0072cd78 + 0x88);
    *(undefined4*)(DAT_0072cd78 + 0x5c) = 10;
    FUN_00515cb0(*puVar1);
    FUN_00517010();
    uVar2 = DAT_0072cb4c;
    *(undefined1*)(iVar3 + 0x78) = 1;
    FUN_004a68d0(uVar2);
}

// 0x427f80 — observed shape
// Early: FUN_004baaa0("standing_water") visuals when DAT_0072cb4c in
// {0,1,2,6}; iterates a linked list at *piVar4+4 depthwise removing
// DAT_00727560 matches; then FUN_00533db0(8)/00502220, visibility bytes
// at +0xb4, FUN_00535670 x2 pairs; tail FUN_004beee0 x3, DAT_008c9df4=1.
void FUN_00427f80(void)
{
    uint32_t uVar1;
    int iVar2;
    undefined4 uVar3;
    int* piVar4;
    undefined4* puVar5;
    int iVar6;
    undefined4 uVar7;
    extern undefined4 FUN_004baaa0b(void);
    if ((((DAT_0072cb4c == 0) || (DAT_0072cb4c == 1)) || (DAT_0072cb4c == 2)) || (DAT_0072cb4c == 6)) {
        if (DAT_008cac29 != 0) {
            uVar3 = FUN_004baaa0((void*)"standing_water", 0xe);
            FUN_00501cc0(uVar3);
            uVar3 = FUN_004baaa0();
            FUN_00501e50(uVar3);
            piVar4 = (int*)FUN_004baaa0();
            if ((piVar4 != 0) && (puVar5 = (undefined4*)(*(codeptr*)*piVar4 + 4)(), puVar5 != 0)) {
            LAB_00427ff0:
                if (puVar5 == (undefined4*)&DAT_00727560) goto code_done;
                iVar6 = FUN_00449390((void*)&DAT_00727560, piVar4);
                uVar1 = *(uint32_t*)(iVar6 + 0xc0);
                while (uVar1 = uVar1 - 1, -1 < (int)uVar1) {
                    if ((uVar1 < *(uint32_t*)(iVar6 + 0xc0)) &&
                        (iVar2 = *(int*)(*(int*)(iVar6 + 0xb8) + uVar1 * 4), iVar2 != 0)) {
                        FUN_00501f40(iVar2, 3);
                    }
                }
            }
            code_done:;
            LAB_00428044:
            iVar6 = FUN_00533db0(8);
            if (iVar6 != 0) FUN_00502220(0);
            FUN_00533d10(0, 1);
            FUN_004baaa0(); FUN_00534350();
        }
        iVar6 = DAT_008c97c4;
        *(undefined1*)(DAT_008c97c0 + 0xb4) = 1;
        *(undefined1*)(iVar6 + 0xb4) = 1;
        FUN_00535670((void*)DAT_008e9ff4);
        FUN_00535670((void*)DAT_008e9ff4);
        puVar5 = *(undefined4**)(DAT_0072cd74 + 0x1c);
        if (puVar5 != 0) puVar5[1]++;
        FUN_00535670(puVar5);
        if (puVar5 != 0) { piVar4 = (int*)puVar5 + 1; if ((*piVar4 = *piVar4 - 1) == 0) (*(codeptr*)*puVar5)(1); }
        puVar5 = *(undefined4**)(DAT_0072cd74 + 0x1c);
        if (puVar5 != 0) puVar5[1]++;
        FUN_00535670(puVar5);
        if (puVar5 != 0) { piVar4 = (int*)puVar5 + 1; if ((*piVar4 = *piVar4 - 1) == 0) (*(codeptr*)*puVar5)(1); }
        while (0) { puVar5 = (undefined4*)puVar5[1]; if (puVar5 == 0) goto LAB_00428044; goto LAB_00427ff0; }
    }
    FUN_004baaa0(); FUN_004beee0(); FUN_004beee0(); FUN_004beee0();
    DAT_008c9df4 = 1;
}

// 0x428140 — observed shape
// Triple FUN_004bef50(); when DAT_0072cb4c in {0,1,2,6} does paired
// FUN_00535920 with AddRef/Release on DAT_0072cd74+0x1c object.
void FUN_00428140(void)
{
    int* piVar1;
    undefined4* puVar2;
    FUN_004bef50(); FUN_004bef50(); FUN_004bef50();
    if ((((DAT_0072cb4c == 0) || (DAT_0072cb4c == 1)) || (DAT_0072cb4c == 2)) || (DAT_0072cb4c == 6)) {
        FUN_00535920((void*)DAT_008e9ff4);
        FUN_00535920((void*)DAT_008e9ff4);
        puVar2 = *(undefined4**)(DAT_0072cd74 + 0x1c);
        if (puVar2 != 0) puVar2[1]++;
        FUN_00535920(puVar2);
        if (puVar2 != 0) { piVar1 = (int*)puVar2 + 1; if ((*piVar1 = *piVar1 - 1) == 0) (*(codeptr*)*puVar2)(1); }
        puVar2 = *(undefined4**)(DAT_0072cd74 + 0x1c);
        if (puVar2 != 0) puVar2[1]++;
        FUN_00535920(puVar2);
        if (puVar2 != 0) { piVar1 = (int*)puVar2 + 1; if ((*piVar1 = *piVar1 - 1) == 0) (*(codeptr*)*puVar2)(1); }
    }
}

// 0x428200 — observed shape
// Receiver in_ECX (int* self). Pops head node at self[1] (piVar1=*piVar1),
// clears self[1]/[2] or *(iVar2+4), AddRefs self-pair[2], calls (*self+8),
// self[3]--, stores into *unaff_retaddr with Release dance.
int* FUN_00428200(int* self, int* unaff_retaddr)
{
    int* piVar1;
    int iVar2;
    undefined4* puVar3;
    piVar1 = (int*)self[1];
    iVar2 = *piVar1;
    self[1] = iVar2;
    if (iVar2 == 0) self[2] = 0; else *(undefined4*)(iVar2 + 4) = 0;
    puVar3 = (undefined4*)piVar1[2];
    if (puVar3 != 0) puVar3[1]++;
    (*(codeptr*)*self + 8)(piVar1);
    self[3] = self[3] - 1;
    *unaff_retaddr = (int)puVar3;
    if (puVar3 != 0) {
        iVar2 = puVar3[1];
        puVar3[1] = iVar2 + 1;
        puVar3[1] = iVar2;
        if (iVar2 == 0) (*(codeptr*)*puVar3)(1);
    }
    return unaff_retaddr;
}

// 0x428270 — observed shape
// Receiver in_ECX. Pops node at self[2] (iVar1), puVar2=iVar1+4 becomes new
// self[2] (or self[1]=0 / *puVar2=0), AddRefs iVar1+8, (*self+8), self[3]--,
// return path via *unaff_retaddr.
int* FUN_00428270(int* self, int* unaff_retaddr)
{
    int iVar1;
    undefined4* puVar2;
    iVar1 = self[2];
    puVar2 = *(undefined4**)(iVar1 + 4);
    self[2] = (int)puVar2;
    if (puVar2 == 0) self[1] = 0; else *puVar2 = 0;
    puVar2 = *(undefined4**)(iVar1 + 8);
    if (puVar2 != 0) puVar2[1]++;
    (*(codeptr*)*self + 8)(iVar1);
    self[3] = self[3] - 1;
    *unaff_retaddr = (int)puVar2;
    if (puVar2 != 0) {
        iVar1 = puVar2[1];
        puVar2[1] = iVar1 + 1;
        puVar2[1] = iVar1;
        if (iVar1 == 0) (*(codeptr*)*puVar2)(1);
    }
    return unaff_retaddr;
}

// 0x4282e0 — observed shape
// AddRefs in_EAX, calls FUN_00428330(&param_1,&local_4), then Release
// param_1 and local_4 (decrement [1], call (*obj)(1) at zero).
void FUN_004282e0(undefined4* param_1, undefined4* in_EAX)
{
    int* piVar1;
    undefined4* local_4;
    if (in_EAX != 0) in_EAX[1]++;
    local_4 = in_EAX;
    FUN_00428330(&param_1, &local_4);
    if (param_1 != 0) { piVar1 = (int*)param_1 + 1; if ((*piVar1 = *piVar1 - 1) == 0) (*(codeptr*)*param_1)(1); }
    if (local_4 != 0) { piVar1 = (int*)local_4 + 1; if ((*piVar1 = *piVar1 - 1) == 0) (*(codeptr*)*local_4)(1); }
}

// 0x428330 — observed shape
// Receiver in_ECX. Searches singly linked list at *(in_ECX+4) for node
// whose [2] equals *param_2; if miss returns param_2 path else calls
// FUN_004283d0, stores result *param_1 with AddRef, Releases local_4.
int* FUN_00428330(int* param_1, int* param_2, int in_ECX)
{
    int iVar1;
    int* piVar2;
    int* piVar3;
    undefined4* local_4 = 0;
    if (*(int**)(in_ECX + 4) != 0) {
        piVar2 = *(int**)(in_ECX + 4);
        do {
            piVar3 = (int*)*piVar2;
            if (*param_2 == piVar2[2]) goto LAB_00428362;
            piVar2 = piVar3;
        } while (piVar3 != 0);
    }
    piVar2 = 0;
LAB_00428362:
    if (piVar2 == 0) { piVar3 = param_2; param_2 = piVar2; }
    else { param_2 = piVar2; piVar3 = (int*)FUN_004283d0(&local_4, &param_2); }
    iVar1 = *piVar3;
    *param_1 = iVar1;
    if (iVar1 != 0) *(int*)(iVar1 + 4) = *(int*)(iVar1 + 4) + 1;
    if ((piVar2 != 0) && (local_4 != 0) && (iVar1 = local_4[1], local_4[1] = iVar1 - 1, iVar1 - 1 == 0)) {
        (*(codeptr*)*local_4)(1);
    }
    return param_1;
}

// 0x4283d0 — observed shape
// Receiver in_ECX. If *param_2==self[1] calls FUN_00428200, if ==self[2]
// calls FUN_00428270, else unlinks middle node (fixing neighbors), AddRefs
// its [2], (*self+8), self[3]--, return via *unaff_retaddr.
int* FUN_004283d0(int* param_1, int* param_2, int* self, int* unaff_retaddr)
{
    int* piVar1;
    int* piVar2;
    int iVar3;
    undefined4* puVar4;
    piVar1 = (int*)*param_2;
    if (piVar1 == (int*)self[1]) { *param_2 = *piVar1; FUN_00428200(self, param_1); return param_1; }
    if (piVar1 == (int*)self[2]) { *param_2 = 0; FUN_00428270(self, param_1); return param_1; }
    piVar2 = (int*)piVar1[1];
    iVar3 = *piVar1;
    *param_2 = iVar3;
    if (piVar2 != 0) *piVar2 = iVar3;
    if (iVar3 != 0) *(int**)(iVar3 + 4) = piVar2;
    puVar4 = (undefined4*)piVar1[2];
    if (puVar4 != 0) puVar4[1]++;
    (*(codeptr*)*self + 8)(piVar1);
    self[3] = self[3] - 1;
    *unaff_retaddr = (int)puVar4;
    if (puVar4 != 0) {
        iVar3 = puVar4[1];
        puVar4[1] = iVar3 + 1;
        puVar4[1] = iVar3;
        if (iVar3 == 0) (*(codeptr*)*puVar4)(1);
    }
    return unaff_retaddr;
}
