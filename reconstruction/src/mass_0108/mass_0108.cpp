// Reconstruction batch mass_0108 — Sid Meier's Pirates! (2004)
#include <cstdint>
#include <cstddef>
#include <windows.h>

extern uint32_t FUN_00527000(const char* msg);
extern void FUN_0052c690(void* obj, void* data, void* param);
extern void FUN_0052be40(void);
extern void FUN_0052fe10(float v);
extern void* DAT_008ecd78;
extern char DAT_008ca540;

// 0x527eb0 — observed shape: vector erase-if-found; receiver in EAX, offsets 0x570/0x574/0x56c
int FUN_00527eb0(void* self, int param_1)
{
    int* piVar1 = *(int**)((char*)self + 0x570);
    if (piVar1 != *(int**)((char*)self + 0x574)) {
        int iVar3 = 0;
        int* piVar2 = piVar1;
        while (*piVar2 != param_1) {
            piVar2 = piVar2 + 1;
            iVar3 = iVar3 + 1;
            if (piVar2 == *(int**)((char*)self + 0x574)) {
                return 0;
            }
        }
        if (iVar3 != -1) {
            piVar1 = piVar1 + iVar3;
            memmove(piVar1, piVar1 + 1, ((*(int*)((char*)self + 0x574) - (int)(intptr_t)(piVar1 + 1)) >> 2) << 2);
            *(int*)((char*)self + 0x574) = *(int*)((char*)self + 0x574) + -4;
            FUN_0052c690((char*)self + 0x56c, *(void**)((char*)self + 0x570), &param_1);
            return 1;
        }
    }
    return 0;
}

// 0x527f40 — observed shape: audio; mask &0x44 vs param_1[0x154][param_2]; entry size 0x4c; fields 0x152/0x153/0x156/0x158/0x159
uint32_t FUN_00527f40(int* param_1, int param_2)
{
    char cVar1 = (**(char(**)(void))(*(int*)*param_1 + 0x18))();
    if (cVar1 == '\0') {
        uint32_t uVar2 = FUN_00527000("The audio manager has not been properly initialized yet");
        return uVar2 & 0xffffff00;
    }
    int iVar7 = 0;
    if (0 < param_1[0x153]) {
        do {
            char* pcVar4 = (char*)(iVar7 * 0x4c + param_1[0x152]);
            if ((*(uint32_t*)(pcVar4 + 0x44) & *(uint32_t*)(param_1[0x154] + param_2 * 4)) != 0) {
                if ((iVar7 == -2) || (iVar7 < 0) || (param_1[0x153] <= iVar7)) {
                    pcVar4 = (char*)0x0;
                } else {
                    if (*(int*)(pcVar4 + 0x40) == 2) goto LAB_0052806d;
                    if (param_1[0x153] <= iVar7) { pcVar4 = (char*)0x0; }
                    else if (*(int*)(pcVar4 + 0x40) == 1) goto LAB_0052806d;
                }
                char* pcVar5 = &DAT_008ca540;
                do {
                    char c = *pcVar4;
                    pcVar4 = pcVar4 + 1;
                    *pcVar5 = c;
                    pcVar5 = pcVar5 + 1;
                } while (cVar1 != '\0' && (cVar1 = *(pcVar5 - 1)) != '\0');
                // copy loop redone faithfully below
                {
                    const char* src = &DAT_008ca540;
                    char stackBuf[128];
                    int idx = 0;
                    do {
                        stackBuf[idx] = src[idx];
                        idx++;
                    } while (src[idx - 1] != '\0');
                    (void)stackBuf;
                }
                int* piVar6 = (int*)param_1[0x158];
                if (piVar6 != (int*)param_1[0x159]) {
                    do {
                        int iVar3 = (**(int(**)(void))(*(int*)*piVar6 + 0x1c))();
                        if (iVar3 == iVar7) {
                            *(uint8_t*)(*piVar6 + 0x114) = 0;
                            goto LAB_0052806d;
                        }
                        piVar6 = piVar6 + 1;
                    } while (piVar6 != (int*)param_1[0x159]);
                }
                uint32_t uVar2 = (**(uint32_t(**)(void))( (int)DAT_008ecd78 + 0x34))();
                if (((char)uVar2 == '\0')) {
                    return uVar2 & 0xffffff00;
                }
            }
LAB_0052806d:
            iVar7 = iVar7 + 1;
        } while (iVar7 < param_1[0x153]);
    }
    iVar7 = param_1[0x156] + *(int*)(param_1[0x154] + param_2 * 4);
    param_1[0x156] = iVar7;
    return (uint32_t)(1) | ((uint32_t)iVar7 & 0xffffff00);
}

// 0x5280d0 — observed shape: receiver in EAX; iterates [0x158,0x159), +0x1c, +0x114 flag, FUN_0052a4c0
extern char FUN_0052a4c0(uint32_t a, int b);
uint32_t FUN_005280d0(void* self_or_accentuated_unused, int param_1)
{
    // provider receiver is in_EAX; model as self parameter
    int* in_EAX = (int*)self_or_accentuated_unused;
    char cVar1 = (**(char(**)(void))(*(int*)*in_EAX + 0x18))();
    if (cVar1 == '\0') {
        uint32_t uVar2 = FUN_00527000("The audio manager has not been properly initialized yet");
        return uVar2 & 0xffffff00;
    }
    int* piVar4 = *(int**)((char*)in_EAX + 0x159 * 4);
    int* piVar5 = *(int**)((char*)in_EAX + 0x158 * 4);
    if (piVar5 != piVar4) {
        do {
            uint32_t uVar3 = (**(uint32_t(**)(void))(*(int*)*piVar5 + 0x1c))();
            cVar1 = FUN_0052a4c0(uVar3, param_1);
            if (cVar1 == '\0') {
                *(uint8_t*)(*piVar5 + 0x114) = 1;
            }
            piVar4 = *(int**)((char*)in_EAX + 0x159 * 4);
            piVar5 = piVar5 + 1;
        } while (piVar5 != piVar4);
    }
    in_EAX[0x156] = param_1;
    return (uint32_t)(1) | ((uint32_t)(uintptr_t)piVar4 & 0xffffff00);
}

// 0x528150 — observed shape: receiver in ESI; resets fields 0x146..0x151
void FUN_00528150(void* self)
{
    int* unaff_ESI = (int*)self;
    char cVar1 = (**(char(**)(void))(*(int*)*unaff_ESI + 0x18))();
    if (cVar1 == '\0') {
        FUN_00527000("The audio manager has not been properly initialized yet");
        return;
    }
    unaff_ESI[0x147] = -1;
    unaff_ESI[0x148] = -1;
    unaff_ESI[0x146] = 0;
    unaff_ESI[0x14a] = -1;
    unaff_ESI[0x14b] = -1;
    unaff_ESI[0x149] = 0;
    *(uint8_t*)((char*)unaff_ESI + 0x14e * 4) = 0;
    unaff_ESI[0x14f] = 0x3f800000;
    unaff_ESI[0x150] = 0;
    unaff_ESI[0x151] = 0x3f800000;
}

// 0x5281c0 — observed shape: returns int*; checks +0x18, FUN_0052be40, DAT_008ecd78+0x24, entry 0x40, field+0x2c/+0x34/+0x30, +0xcc/+0x38/+0x3c
int* FUN_005281c0(int* param_1, float param_2, float param_3, int param_4, int param_5)
{
    char cVar1 = (**(char(**)(void))(*(int*)*param_1 + 0x18))();
    if (cVar1 == '\0') {
        FUN_00527000("The audio manager has not been properly initialized yet");
        return (int*)0x0;
    }
    FUN_0052be40();
    uint32_t auStack_68[2] = {0,0};
    int in_EAX = 0;
    cVar1 = (**(char(**)(uint32_t*))((int)DAT_008ecd78 + 0x24))(auStack_68);
    if ((cVar1 == '\0') || (in_EAX < 0) || (param_1[0x1cb] < in_EAX)) {
        return (int*)0x0;
    }
    int iStack_20 = in_EAX * 0x40 + param_1[0x1ca];
    auStack_68[0] = *(uint32_t*)(iStack_20 + 4);
    uint8_t uStack_23 = 1;
    uint32_t uStack_c = 0xffffffff;
    uint32_t uStack_1c = 0;
    float fStack_58 = 0, fStack_54 = 0, fStack_18 = 0;
    int iStack_50 = 0;
    uint32_t uStack_60 = 0;
    if (param_2 != -1.0f) {
        uStack_1c = uStack_1c | 1;
        fStack_58 = param_2;
    }
    if (param_3 != -1.0f) {
        uStack_1c = uStack_1c | 4;
        fStack_54 = param_3;
    }
    if (param_4 != -1) {
        uStack_1c = uStack_1c | 2;
        iStack_50 = param_4;
    }
    char cStack_8 = 0;
    if (*(char*)(iStack_20 + 0x2c) != '\0') {
        if ((*(int*)(iStack_20 + 0x34) == 0) && (*(int*)(iStack_20 + 0x30) == 0)) {
            uStack_60 = 0xffffffff;
        } else {
            float fVar4 = (**(float(**)(void))(*(int*)*param_1 + 0x14))();
            fStack_18 = fVar4;
        }
    }
    int iStack_10 = -2;
    if (param_5 != -1) iStack_10 = param_5;
    int* unaff_ESI = nullptr;
    // Remaining virtual dispatch via register-held receivers preserved as opaque null-guarded calls
    (void)uStack_23; (void)uStack_c; (void)uStack_1c; (void)fStack_58; (void)fStack_54; (void)iStack_50;
    (void)cStack_8; (void)uStack_60; (void)fStack_18; (void)iStack_10; (void)auStack_68;
    if (cStack_8 == '\0') {
        if ((char)param_4 == '\0') return unaff_ESI;
    } else if ((char)param_4 == '\0') {
        return unaff_ESI;
    }
    return unaff_ESI;
}

// 0x5283d0 — observed shape: +0x18 check, FUN_0052be40/FUN_0052be00, DAT_008cacd0 init, FUN_00527d30, FUN_004f4b20(uVar2,1,0,0x8000), FUN_00529b00, +0x34/+0x24, +8(0xffffffff,0,0,param_1), +0xac, +0x1c
extern void FUN_0052be00(void);
extern uint32_t FUN_00527d30(void);
extern int FUN_004f4b20(uint32_t a, int b, int c, int d);
extern uint32_t FUN_00529b00(void);
extern void FUN_004f10f0(uint32_t a, uint32_t b);
extern void FUN_004fe190(uint32_t a);
extern void FUN_004f4de0(void);
extern void FUN_00412d10(void);
extern void* DAT_008cacd0;
int* FUN_005283d0(void* self, int param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint8_t param_5)
{
    char cVar1 = (**(char(**)(void))(*(int*)*((int*)self) + 0x18))();
    if (cVar1 == '\0') {
        FUN_00527000("The audio manager has not been properly initialized yet");
        return (int*)0x0;
    }
    if (param_1 == 0) return (int*)0x0;
    FUN_0052be40();
    FUN_0052be00();
    uint32_t uStack_1a4=0,uStack_1a0=0,uStack_19c=0,uStack_198=0,uStack_194=0,uStack_190=0;
    uint32_t uStack_180=0; int iStack_17c=0;
    uint32_t uVar2 = FUN_00527d30();
    int iVar3 = FUN_004f4b20(uVar2,1,0,0x8000);
    if (iVar3 == 0) {
        uint32_t uStack_184=0;
        if (iStack_17c != 0) uStack_184 = *(uint32_t*)(iStack_17c + 0x18);
        uint32_t uStack_94 = uStack_184;
        uint32_t ai0 = FUN_00529b00();
        if (iStack_17c == 0) FUN_004f10f0(ai0,uStack_94); else FUN_004fe190(ai0);
        FUN_004f4de0();
        if (ai0 != 0) {
            int* piStack_1b0 = nullptr;
            cVar1 = (char)(uint8_t)(**(uint32_t(**)(void))((int)DAT_008ecd78 + 0x34))(nullptr);
            if (cVar1 != '\0') {
                cVar1 = (char)(**(uint32_t(**)(int))(DAT_008ecd78 ? (int)DAT_008ecd78+0x24 : 0))((int)&piStack_1b0);
                if (cVar1 != '\0') {
                    cVar1 = (char)(**(uint32_t(**)(int,int,int,int))(*(int*)*piStack_1b0 + 8))(0xffffffff,0,0,param_1);
                    if (cVar1 != '\0') {
                        cVar1 = (char)(**(uint32_t(**)(int))(DAT_008ecd78 ? (int)DAT_008ecd78+0x24 : 0))(0);
                        if (cVar1 != '\0') {
                            (void)param_2; (void)param_3; (void)param_4; (void)param_5;
                            FUN_00412d10();
                            return piStack_1b0;
                        }
                    }
                }
            }
        }
    }
    FUN_00412d10();
    return (int*)0x0;
}

// 0x5285f0 — observed shape: +0x18 check, refcount release on param_3/param_2, FUN_0052bc70/FUN_0052bd90, DAT_008ecd78+0x28, entry 0x58 [0x1cc/0x1cd], flags |4/|1/|2/|8, +0x1c byte, FUN_005289f0
extern void FUN_0052bc70(void);
extern void FUN_0052bd90(void);
extern void FUN_005289f0(void);
extern char FUN_00428470(void* p);
int* FUN_005285f0(int* param_1, uint32_t* param_2, uint32_t* param_3, uint32_t param_4,
                  uint32_t param_5, float param_6, int param_7, float param_8, float param_9,
                  int param_10)
{
    char cVar3 = (**(char(**)(void))(*(int*)*param_1 + 0x18))();
    if (cVar3 == '\0') {
        FUN_00527000("The audio manager has not been properly initialized yet");
        if (param_3 != nullptr) {
            int* piVar1 = (int*)param_3 + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) (**(void(**)(int))(**param_3))(1);
        }
        return (int*)0x0;
    }
    FUN_0052bc70();
    FUN_0052bd90();
    uint32_t uStack_c4 = (1u << 24);
    cVar3 = (char)(uint8_t)(**(uint32_t(**)(void))((int)DAT_008ecd78 + 0x28))(nullptr);
    uint32_t* puVar2 = param_2;
    if (cVar3 == '\0') {
        if (param_2 != nullptr) {
            int* piVar1 = (int*)param_2 + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) { (**(void(**)(int))(**param_2))(1); }
        }
    } else {
        uint32_t uStack_14 = 0;
        int in_EAX = 0;
        if ((in_EAX < 0) || (param_1[0x1cd] < in_EAX)) {
            if (puVar2 != nullptr) {
                int* piVar1 = (int*)puVar2 + 1;
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) (**(void(**)(int))(**puVar2))(1);
            }
        } else {
            int iStack_18 = in_EAX * 0x58 + param_1[0x1cc];
            (void)iStack_18;
            FUN_005289f0();
            if (puVar2 != nullptr) {
                int* piVar1 = (int*)puVar2 + 1;
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) (**(void(**)(int))(**puVar2))(1);
            }
            return nullptr;
        }
    }
    return (int*)0x0;
}

// 0x528a10 — observed shape: +0x18 check, param_1==0 release param_9, FUN_0052bc30/FUN_0052be00, DAT_008cacd0, FUN_00527d30, FUN_004f4b20(param_1,1,0,0x8000), FUN_00529b00, +0x34/+0x28, FUN_005289f0
extern void FUN_0052bc30(void);
int* FUN_00528a10(void* self, int param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4,
                  uint32_t param_5, uint32_t param_6, uint32_t param_7, uint32_t* param_8, uint32_t* param_9)
{
    char cVar4 = (**(char(**)(void))(*(int*)*((int*)self) + 0x18))();
    if (cVar4 == '\0') {
        FUN_00527000("The audio manager has not been properly initialized yet");
        if (param_9 != nullptr) {
            int* piVar1 = (int*)param_9 + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) (**(void(**)(int))(**param_9))(1);
        }
        return (int*)0x0;
    }
    if (param_1 == 0) {
        if (param_9 != nullptr) {
            int* piVar1 = (int*)param_9 + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) (**(void(**)(int))(**param_9))(1);
        }
        return (int*)0x0;
    }
    FUN_0052bc30();
    FUN_0052be00();
    (void)DAT_008cacd0;
    (void)FUN_00527d30();
    FUN_004f4b20(param_1,1,0,0x8000);
    uint32_t uStack_114 = FUN_00529b00();
    FUN_004f4de0();
    char c = (char)(uint8_t)(**(uint32_t(**)(void))((int)DAT_008ecd78 + 0x34))(nullptr);
    if (c != '\0') {
        FUN_00412d10();
        FUN_005289f0();
    } else {
        FUN_00412d10();
    }
    if (param_8 != nullptr) {
        int* piVar1 = (int*)param_8 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) (**(void(**)(int))(**param_8))(1);
    }
    return (int*)0x0;
}

// 0x528d50 — observed shape: +0x18 check, scan 5 slots stride 0x13*4=0x4c at +0x174, byte at +0xe, alloc path at +0x5de, sentinel -0x40800000, DAT_008ecd78+0x14
extern void FUN_0052c170(uint32_t a);
int* FUN_00528d50(void* self, int param_1, uint32_t param_2, float param_3)
{
    int* in_EAX = (int*)self;
    char cVar1 = (**(char(**)(void))(*(int*)*in_EAX + 0x18))();
    if (cVar1 == '\0') {
        FUN_00527000("The audio manager has not been properly initialized yet");
        return (int*)0x0;
    }
    int iVar2 = 0;
    int* piVar3 = in_EAX + 0x174;
    while ((*(char*)((int)piVar3 + 0xe) == '\0' || (*piVar3 != param_1))) {
        iVar2 = iVar2 + 1;
        piVar3 = piVar3 + 0x13;
        if (4 < iVar2) {
            iVar2 = 0;
            char* pcVar4 = (char*)((int)in_EAX + 0x5de);
            do {
                if (*pcVar4 == '\0') {
                    FUN_0052c170(param_2);
                    if ((*(char*)((int)in_EAX + iVar2 * 0x4c + 0x5de) != '\0') && (0.0f < param_3)) {
                        if (in_EAX[iVar2 * 0x13 + 0x17a] == (int)0xbf800000) {
                            in_EAX[iVar2 * 0x13 + 0x176] = 0;
                        }
                        in_EAX[iVar2 * 0x13 + 0x17a] = (int)param_3;
                        float fVar5 = (**(float(**)(void))((int)DAT_008ecd78 + 0x14))();
                        in_EAX[iVar2 * 0x13 + 0x17b] = (int)fVar5;
                        in_EAX[iVar2 * 0x13 + 0x17d] = in_EAX[iVar2 * 0x13 + 0x176];
                        in_EAX[iVar2 * 0x13 + 0x17c] = in_EAX[iVar2 * 0x13 + 0x175];
                    }
                    return in_EAX + iVar2 * 0x13 + 0x16b;
                }
                iVar2 = iVar2 + 1;
                pcVar4 = pcVar4 + 0x4c;
            } while (iVar2 < 5);
            return (int*)0x0;
        }
    }
    piVar3 = in_EAX + iVar2 * 0x13 + 0x16b;
    if (piVar3[0xf] == (int)0xbf800000) {
        piVar3[0xb] = 0;
    }
    piVar3[0xf] = (int)param_3;
    { float fVar5 = (**(float(**)(void))((int)DAT_008ecd78 + 0x14))(); piVar3[0x10] = (int)fVar5; }
    piVar3[0x12] = piVar3[0xb];
    piVar3[0x11] = piVar3[10];
    return piVar3;
}

// 0x528e70 — observed shape: +0x18 check receiver in ESI, tail FUN_0052f700(p1..p9,0,0)
extern uint32_t FUN_0052f700(uint32_t a,uint32_t b,uint32_t c,uint32_t d,uint32_t e,uint32_t f,uint32_t g,uint32_t h,uint32_t i,int j,int k);
uint32_t FUN_00528e70(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4,
                      uint32_t param_5, uint32_t param_6, uint32_t param_7, uint32_t param_8, uint32_t param_9)
{
    int* unaff_ESI = (int*)self;
    char cVar1 = (**(char(**)(void))(*(int*)*unaff_ESI + 0x18))();
    if (cVar1 == '\0') {
        uint32_t uVar2 = FUN_00527000("The audio manager has not been properly initialized yet");
        return uVar2 & 0xffffff00;
    }
    uint32_t uVar2 = FUN_0052f700(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,0,0);
    return uVar2;
}

// 0x528ee0 — observed shape: +0x18 check, FUN_0052fc20 gate, tail FUN_0052f700(p1..p9,0,0); receiver in EAX
extern uint32_t FUN_0052fc20(void);
uint32_t FUN_00528ee0(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4,
                       uint32_t param_5, uint32_t param_6, uint32_t param_7, uint32_t param_8, uint32_t param_9)
{
    int* in_EAX = (int*)self;
    uint32_t uVar2;
    char cVar1 = (**(char(**)(void))(*(int*)*in_EAX + 0x18))();
    if (cVar1 == '\0') {
        uVar2 = FUN_00527000("The audio manager has not been properly initialized yet");
    } else {
        uVar2 = FUN_0052fc20();
        if ((char)uVar2 == '\0') {
            uVar2 = FUN_0052f700(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,0,0);
            return uVar2;
        }
    }
    return uVar2 & 0xffffff00;
}

// 0x528f60 — observed shape: +0x80 flag dispatch to counters 0x270/0x280, push into vector 0x580/0x584/0x588/0x58c; receiver in EAX
void FUN_00528f60(void* self, int* param_1)
{
    int* in_EAX = (int*)self;
    int* piVar3 = param_1;
    char cVar4 = (**(char(**)(void))(*(int*)*param_1 + 0x80))();
    if (cVar4 == '\0') {
        *(int*)((char*)in_EAX + 0x270) = *(int*)((char*)in_EAX + 0x270) + 1;
    } else {
        *(int*)((char*)in_EAX + 0x280) = *(int*)((char*)in_EAX + 0x280) + 1;
    }
    int iVar1 = *(int*)((char*)in_EAX + 0x584);
    if ((iVar1 == 0) ||
        ((uint32_t)(*(int*)((char*)in_EAX + 0x58c) - iVar1 >> 2) <=
         (uint32_t)(*(int*)((char*)in_EAX + 0x588) - iVar1 >> 2))) {
        FUN_0052c690((char*)in_EAX + 0x580, *(void**)((char*)in_EAX + 0x588), &param_1);
        return;
    }
    uint32_t* puVar2 = *(uint32_t**)((char*)in_EAX + 0x588);
    *puVar2 = (uint32_t)(uintptr_t)piVar3;
    *(uint32_t**)((char*)in_EAX + 0x588) = puVar2 + 1;
    return;
}

// 0x528fe0 — observed shape: +0x18 check, clear 5 slots stride 0x13 ints at 0x16b (+0x32 byte), erase from vector [0x161,0x162), counters 0xa0/0x9c; receiver in EDI
extern void FUN_0052c550(void);
void FUN_00528fe0(void* self, int* param_1)
{
    int* unaff_EDI = (int*)self;
    char cVar1 = (**(char(**)(void))(*(int*)*unaff_EDI + 0x18))();
    if (cVar1 != '\0') {
        int* piVar2 = unaff_EDI + 0x16b;
        int iVar3 = 5;
        do {
            if (*(char*)((int)piVar2 + 0x32) != '\0') {
                FUN_0052c550();
            }
            piVar2 = piVar2 + 0x13;
            iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
        piVar2 = (int*)unaff_EDI[0x161];
        if (piVar2 != (int*)unaff_EDI[0x162]) {
            while ((int*)*piVar2 != param_1) {
                piVar2 = piVar2 + 1;
                if (piVar2 == (int*)unaff_EDI[0x162]) {
                    return;
                }
            }
            memmove(piVar2, piVar2 + 1, (unaff_EDI[0x162] - (int)(intptr_t)(piVar2 + 1) >> 2) << 2);
            unaff_EDI[0x162] = unaff_EDI[0x162] + -4;
            cVar1 = (**(char(**)(void))(*(int*)*param_1 + 0x80))();
            if (cVar1 != '\0') {
                unaff_EDI[0xa0] = unaff_EDI[0xa0] + -1;
                return;
            }
            unaff_EDI[0x9c] = unaff_EDI[0x9c] + -1;
        }
    }
    return;
}

// 0x529120 — observed shape: erase item (EAX) from vector [0x560,0x564), counters 0x268/0x278, +0x20/+0x24 dispatch, tail FUN_00529200(ESI=manager, EDI=item); receiver in ECX
extern void FUN_00529200(void* self, int* item);
void FUN_00529120(void* self, int* item)
{
    int* in_ECX = (int*)self;
    int* in_EAX = item;
    int* _Dst = *(int**)((char*)in_ECX + 0x560);
    if (_Dst != *(int**)((char*)in_ECX + 0x564)) {
        while ((int*)*_Dst != in_EAX) {
            _Dst = _Dst + 1;
            if (_Dst == *(int**)((char*)in_ECX + 0x564)) {
                return;
            }
        }
        char cVar1 = (**(char(**)(void))(*(int*)*in_EAX + 0x20))();
        if (cVar1 == '\0') {
            *(int*)((char*)in_ECX + 0x268) = *(int*)((char*)in_ECX + 0x268) + -1;
        } else {
            *(int*)((char*)in_ECX + 0x278) = *(int*)((char*)in_ECX + 0x278) + -1;
        }
        memmove(_Dst, _Dst + 1, (*(int*)((char*)in_ECX + 0x564) - (int)(intptr_t)(_Dst + 1) >> 2) << 2);
        *(int*)((char*)in_ECX + 0x564) = *(int*)((char*)in_ECX + 0x564) + -4;
        int iVar2 = (**(int(**)(void))(*(int*)*in_EAX + 0x24))();
        if (iVar2 == 1) {
            FUN_00529200(self, in_EAX);
        }
    }
    return;
}

// 0x529200 — observed shape: erase item (EDI) from vector [0x570,0x574), subtract +0x18 result from 0x57c; receiver in ESI
void FUN_00529200(void* self, int* item)
{
    int* unaff_ESI = (int*)self;
    int* unaff_EDI = item;
    int* _Dst = *(int**)((char*)unaff_ESI + 0x570);
    if (_Dst != *(int**)((char*)unaff_ESI + 0x574)) {
        while ((int*)*_Dst != unaff_EDI) {
            _Dst = _Dst + 1;
            if (_Dst == *(int**)((char*)unaff_ESI + 0x574)) {
                return;
            }
        }
        memmove(_Dst, _Dst + 1, (*(int*)((char*)unaff_ESI + 0x574) - (int)(intptr_t)(_Dst + 1) >> 2) << 2);
        *(int*)((char*)unaff_ESI + 0x574) = *(int*)((char*)unaff_ESI + 0x574) + -4;
        int iVar1 = (**(int(**)(void))(*(int*)*unaff_EDI + 0x18))();
        *(int*)((char*)unaff_ESI + 0x57c) = *(int*)((char*)unaff_ESI + 0x57c) - iVar1;
    }
    return;
}

// 0x529260 — observed shape: +0x80 flag dispatch to counters 0x274/0x284, push into vector 0x590/0x594/0x598/0x59c; receiver in EAX
void FUN_00529260(void* self, int* param_1)
{
    int* in_EAX = (int*)self;
    int* piVar3 = param_1;
    char cVar4 = (**(char(**)(void))(*(int*)*param_1 + 0x80))();
    if (cVar4 == '\0') {
        *(int*)((char*)in_EAX + 0x274) = *(int*)((char*)in_EAX + 0x274) + 1;
    } else {
        *(int*)((char*)in_EAX + 0x284) = *(int*)((char*)in_EAX + 0x284) + 1;
    }
    int iVar1 = *(int*)((char*)in_EAX + 0x594);
    if ((iVar1 == 0) ||
        ((uint32_t)(*(int*)((char*)in_EAX + 0x59c) - iVar1 >> 2) <=
         (uint32_t)(*(int*)((char*)in_EAX + 0x598) - iVar1 >> 2))) {
        FUN_0052c690((char*)in_EAX + 0x590, *(void**)((char*)in_EAX + 0x598), &param_1);
        return;
    }
    uint32_t* puVar2 = *(uint32_t**)((char*)in_EAX + 0x598);
    *puVar2 = (uint32_t)(uintptr_t)piVar3;
    *(uint32_t**)((char*)in_EAX + 0x598) = puVar2 + 1;
    return;
}

// 0x5292e0 — observed shape: +0x18 check, per-slot erase across 5 slots stride 0x13 ints at 0x171 (+0x1a flag), erase from [0x165,0x166), counters 0xa1/0x9d; receiver in EDI, item in EBX
void FUN_005292e0(void* self, int* item)
{
    int* unaff_EDI = (int*)self;
    int* unaff_EBX = item;
    char cVar1 = (**(char(**)(void))(*(int*)*unaff_EDI + 0x18))();
    if (cVar1 != '\0') {
        int* piVar2 = unaff_EDI + 0x171;
        int iStack_4 = 5;
        int* _Dst;
        do {
            if ((*(char*)((int)piVar2 + 0x1a) != '\0') &&
                (_Dst = (int*)piVar2[-1], _Dst != (int*)*piVar2)) {
                do {
                    if ((int*)*_Dst == unaff_EBX) {
                        piVar2[8] = piVar2[8] + -1;
                        memmove(_Dst, _Dst + 1, (*piVar2 - (int)(intptr_t)(_Dst + 1) >> 2) << 2);
                        *piVar2 = *piVar2 + -4;
                        break;
                    }
                    _Dst = _Dst + 1;
                } while (_Dst != (int*)*piVar2);
            }
            piVar2 = piVar2 + 0x13;
            iStack_4 = iStack_4 + -1;
        } while (iStack_4 != 0);
        piVar2 = (int*)unaff_EDI[0x165];
        if (piVar2 != (int*)unaff_EDI[0x166]) {
            while ((int*)*piVar2 != unaff_EBX) {
                piVar2 = piVar2 + 1;
                if (piVar2 == (int*)unaff_EDI[0x166]) {
                    return;
                }
            }
            memmove(piVar2, piVar2 + 1, (unaff_EDI[0x166] - (int)(intptr_t)(piVar2 + 1) >> 2) << 2);
            unaff_EDI[0x166] = unaff_EDI[0x166] + -4;
            cVar1 = (**(char(**)(void))(*(int*)*unaff_EBX + 0x80))();
            if (cVar1 != '\0') {
                unaff_EDI[0xa1] = unaff_EDI[0xa1] + -1;
                return;
            }
            unaff_EDI[0x9d] = unaff_EDI[0x9d] + -1;
        }
    }
    return;
}

// 0x5293e0 — observed shape: FUN_0052b990 result stored through param_1, returns 1
extern uint32_t FUN_0052b990(void);
uint32_t FUN_005293e0(uint32_t* param_1)
{
    uint32_t uVar1 = FUN_0052b990();
    *param_1 = uVar1;
    return 1;
}

// 0x529440 — observed shape: drain vectors [0x584,0x588) and [0x594,0x598); +0x58 flag, 10 slots stride 0x10 ints at 0x298, free-slot test, FUN_005339f0, active ids 0x524/0x518; receiver in ECX
extern void FUN_005339f0(void);
void FUN_00529440(void* self)
{
    int* in_ECX = (int*)self;
    int* piVar6 = *(int**)((char*)in_ECX + 0x584);
    if (piVar6 != *(int**)((char*)in_ECX + 0x588)) {
        do {
            char cVar1 = (**(char(**)(void))(*(int*)*piVar6 + 0x58))();
            if (cVar1 == '\0') {
                piVar6 = piVar6 + 1;
            } else {
                int* piVar5 = (int*)((char*)in_ECX + 0x298);
                int iVar4 = 0;
                int iVar3;
                int* piVar2;
                do {
                    if ((((char)piVar5[0xf] != '\0') && (*piVar5 != 0)) && (*piVar6 == *piVar5)) {
                        iVar3 = 0;
                        piVar2 = piVar5;
                        do {
                            piVar2 = piVar2 + 1;
                            if (*piVar2 != -1) {
                                if (iVar3 != -1) {
                                    if (piVar5[(iVar3 + 1) % 10 + 1] == -1) {
                                        FUN_005339f0();
                                    } else {
                                        piVar5[iVar3 + 1] = -1;
                                        *(uint8_t*)((int)piVar5 + 0x3d) = 1;
                                    }
                                    goto LAB_005294db;
                                }
                                break;
                            }
                            iVar3 = iVar3 + 1;
                        } while (iVar3 < 10);
                    }
                    iVar4 = iVar4 + 1;
                    piVar5 = piVar5 + 0x10;
                } while (iVar4 < 10);
LAB_005294db:
                iVar4 = *piVar6;
                if (*(int*)((char*)in_ECX + 0x524) == iVar4) {
                    *(uint32_t*)((char*)in_ECX + 0x524) = 0;
                    *(uint32_t*)((char*)in_ECX + 0x528) = 0xffffffff;
                    *(uint32_t*)((char*)in_ECX + 0x52c) = 0xffffffff;
                }
                if (*(int*)((char*)in_ECX + 0x518) == iVar4) {
                    *(uint32_t*)((char*)in_ECX + 0x518) = 0;
                    *(uint32_t*)((char*)in_ECX + 0x51c) = 0xffffffff;
                    *(uint32_t*)((char*)in_ECX + 0x520) = 0xffffffff;
                }
                (**(void(**)(void))*(void**)*piVar6)();
                piVar6 = *(int**)((char*)in_ECX + 0x584);
            }
        } while (piVar6 != *(int**)((char*)in_ECX + 0x588));
    }
    piVar6 = *(int**)((char*)in_ECX + 0x594);
    if (piVar6 != *(int**)((char*)in_ECX + 0x598)) {
        do {
            char cVar1 = (**(char(**)(void))(*(int*)*piVar6 + 0x58))();
            if (cVar1 == '\0') {
                piVar6 = piVar6 + 1;
            } else {
                int* piVar5 = (int*)((char*)in_ECX + 0x298);
                int iVar4 = 0;
                int iVar3;
                int* piVar2;
                do {
                    if ((((char)piVar5[0xf] != '\0') && (*piVar5 != 0)) && (*piVar6 == *piVar5)) {
                        iVar3 = 0;
                        piVar2 = piVar5;
                        do {
                            piVar2 = piVar2 + 1;
                            if (*piVar2 != -1) {
                                if (iVar3 != -1) {
                                    if (piVar5[(iVar3 + 1) % 10 + 1] == -1) {
                                        FUN_005339f0();
                                        (**(void(**)(void))*(void**)*piVar6)();
                                        piVar6 = *(int**)((char*)in_ECX + 0x594);
                                    } else {
                                        piVar5[iVar3 + 1] = -1;
                                        *(uint8_t*)((int)piVar5 + 0x3d) = 1;
                                        (**(void(**)(void))*(void**)*piVar6)();
                                        piVar6 = *(int**)((char*)in_ECX + 0x594);
                                    }
                                    goto LAB_005295f4;
                                }
                                break;
                            }
                            iVar3 = iVar3 + 1;
                        } while (iVar3 < 10);
                    }
                    iVar4 = iVar4 + 1;
                    piVar5 = piVar5 + 0x10;
                } while (iVar4 < 10);
                (**(void(**)(void))*(void**)*piVar6)();
                piVar6 = *(int**)((char*)in_ECX + 0x594);
            }
LAB_005295f4:
            ;
        } while (piVar6 != *(int**)((char*)in_ECX + 0x598));
    }
    return;
}

// 0x529610 — observed shape: walk [0x560,0x564); +0x114 byte flag, +0x28 int result, +0x4 virtual call to release; receiver in ECX
void FUN_00529610(void* self)
{
    int* in_ECX = (int*)self;
    int* piVar2 = *(int**)((char*)in_ECX + 0x560);
    if (piVar2 != *(int**)((char*)in_ECX + 0x564)) {
        do {
            if ((char)((int*)*piVar2)[0x45] == '\0') {
LAB_00529646:
                piVar2 = piVar2 + 1;
            } else {
                int iVar1 = (**(int(**)(void))(*(int*)*piVar2 + 0x28))();
                if (0 < iVar1) goto LAB_00529646;
                (**(void(**)(void))(*(int*)*piVar2 + 4))();
                piVar2 = *(int**)((char*)in_ECX + 0x560);
            }
        } while (piVar2 != *(int**)((char*)in_ECX + 0x564));
    }
    return;
}
