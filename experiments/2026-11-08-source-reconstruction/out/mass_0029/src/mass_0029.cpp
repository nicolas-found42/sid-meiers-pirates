#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <windows.h>

extern int DAT_008e9fd8;
extern int DAT_0085a164;
extern int DAT_008ecd78;
extern int DAT_008b99e0[];
extern int DAT_008b99d4;
extern int DAT_008b99d0;
extern unsigned char DAT_008c81f4;
extern unsigned char DAT_008c81f3;
extern int DAT_008c7410[];
extern int DAT_008ba674[];
extern int DAT_008c73c4;
extern DWORD DAT_008ed618;
extern int _DAT_008ed61c;
extern int DAT_008bc490[];
extern int DAT_008c73cc[];
extern int DAT_008c73f4[];
extern int DAT_008c73a8[];
extern float DAT_008c73a0[];
extern float DAT_008c73a4;
extern float _DAT_008c84b0;
extern int DAT_008c73e0;
extern float _DAT_008c739c;
extern float DAT_008c73ac;
extern int DAT_008c73b4;
extern int DAT_008bc46c[];
extern int DAT_008bc470[];
extern int DAT_008c73ec;
extern unsigned char DAT_008c827f;
extern unsigned char DAT_008c827e;
extern unsigned char DAT_008c735e;
extern unsigned char DAT_008c735d;
extern int DAT_008c7358;
extern int DAT_008c7354;
extern int DAT_008c7388;
extern int DAT_008c7394;
extern int DAT_008c738c;
extern int DAT_008c7384;
extern int DAT_008c7380;
extern int DAT_008c737c;
extern int DAT_008c7390;
extern int DAT_008c7364;
extern int DAT_008c735c;
extern int DAT_008c736c;
extern unsigned char DAT_008e8eff;
extern unsigned char DAT_00869b21;
extern int DAT_008c7368;
extern int DAT_0072cb4c;
extern int DAT_00727080;
extern int DAT_0072ccf0;
extern int DAT_00723900;
extern int DAT_0072ccd4;
extern int DAT_008e67b0;
extern int DAT_008cacd0;
extern unsigned char DAT_008cac27;
extern unsigned char DAT_008cac26;
extern int DAT_008e8ec4;
extern int _DAT_008e8ec8;
extern int* DAT_008ed2c8;
extern int DAT_008e8eec;
extern int DAT_008e8ef0;
extern void* DAT_008e8f08;
extern int DAT_008e8f04;
extern int DAT_008c7350;
extern int DAT_008c734c;
extern int DAT_008c7348;
extern int DAT_008c7344;
extern void* DAT_008c7398;
extern int DAT_008c7370;
extern int DAT_008c7378;

extern int FUN_00488a80(...);
extern int FUN_00488b00(...);
extern int FUN_00488c30(...);
extern int FUN_00488d90(...);
extern int FUN_00488df0(...);
extern int FUN_00488ed0(...);
extern int FUN_00488b80(...);
extern int FUN_00488840(...);
extern int FUN_00489040(...);
extern int FUN_004890c0(...);
extern int FUN_00489130(...);
extern int FUN_004891a0(...);
extern int FUN_00489210(...);
extern int FUN_004985e0(...);
extern int FUN_004987a0(...);
extern int FUN_00498850(...);
extern int FUN_00498a50(...);
extern int FUN_0049f930(...);
extern int FUN_004a14b0(...);
extern int FUN_004a2080(...);
extern int FUN_004a0d90(...);
extern int FUN_0049af70(...);
extern int FUN_0049aed0(...);
extern int FUN_004a0b70(...);
extern int FUN_004a9630(...);
extern int FUN_00491640(...);
extern int FUN_004ae640(...);
extern int* FUN_004baaa0(...);
extern int FUN_0042c4b0(...);
extern int FUN_005f0ddc(...);
extern int FUN_00533d10(...);
extern int FUN_0053c7c0(...);
extern float* FUN_0053ca60(...);
extern void* thunk_FUN_00533c78(...);
extern int FUN_004dadc0(...);
extern void operator_delete__(void* p);

// 0x4a5740 — observed shape
void FUN_004a5740(int param_1) {
    int iVar1;
    char cVar2;
    DWORD DVar3;
    int iVar4;
    uint32_t* puVar5;
    int* piVar6;
    int iStack_90;
    int local_8c;

    if (DAT_008e9fd8 != 0) {
        if ((DAT_0085a164 & 0x40) == 0) {
            FUN_004a9630();
            FUN_004a9630();
            FUN_004a9630();
            FUN_004985e0();
            FUN_004a14b0();
            FUN_004987a0();
        } else {
            FUN_00491640();
            FUN_004985e0();
            FUN_004a14b0();
            FUN_004987a0();
        }
    }
    FUN_004a6210();
    puVar5 = (uint32_t*)&DAT_008b99e0;
    do {
        if ((puVar5[0xd] != 0) && (cVar2 = (char)(((char(*)(void))(*(void**)((char*)&DAT_008ecd78 + 0x18)))()), cVar2 != '\0')) {
            FUN_004985e0();
            FUN_004a14b0();
        }
        puVar5 = puVar5 + 0x10;
    } while ((int)(intptr_t)puVar5 < 0x8ba3e0);
    if (param_1 != -1) {
        FUN_005f0ddc();
        cVar2 = (char)(((char(*)(void))(*(void**)((char*)&DAT_008ecd78 + 0x18)))());
        if (cVar2 != '\0') {
            FUN_004985e0();
            FUN_004a14b0();
        }
        cVar2 = (char)(((char(*)(void))(*(void**)((char*)&DAT_008ecd78 + 0x18)))());
        if (cVar2 != '\0') {
            FUN_004985e0();
            FUN_004a14b0();
        }
    }
    if (DAT_008c81f4 == '\0') {
        if (DAT_008c81f3 != '\0') {
            FUN_00489040();
        }
    } else if (DAT_008c81f3 == '\0') {
        FUN_00488a80();
    } else {
        cVar2 = (char)(((char(*)(void))(*(void**)((char*)&DAT_008ecd78 + 0x18)))());
        if (cVar2 != '\0') {
            FUN_004985e0();
            FUN_004a14b0();
        }
    }
    DAT_008c81f3 = DAT_008c81f4;
    iStack_90 = 0;
    piVar6 = &DAT_008c7410;
    do {
        local_8c = 0;
        do {
            iVar4 = 0;
            do {
                if ((piVar6[-1] != -1) &&
                    (iVar1 = *(int*)((char*)&DAT_008ba674 + (iVar4 + (iStack_90 + local_8c) * 0x18) * 0x28), 0 < iVar1) && (iVar1 != 1000)) {
                    if (iVar1 < *piVar6) {
                        cVar2 = (char)(((char(*)(void))(*(void**)((char*)&DAT_008ecd78 + 0x18)))());
                        if (cVar2 != '\0') {
                            FUN_004985e0();
                            FUN_004a14b0();
                        }
                        *piVar6 = -2;
                    } else if (*piVar6 != -2) {
                        *piVar6 = iVar1;
                    }
                }
                iVar4 = iVar4 + 1;
                piVar6 = piVar6 + 3;
            } while (iVar4 < 0x18);
            local_8c = local_8c + 1;
        } while (local_8c < 2);
        iStack_90 = iStack_90 + 4;
    } while ((int)(intptr_t)piVar6 < 0x8c7890);
    if (DAT_008c73c4 != -1) {
        if ((_DAT_008ed61c & 1) == 0) {
            _DAT_008ed61c = _DAT_008ed61c | 1;
            DAT_008ed618 = timeGetTime();
        }
        DVar3 = timeGetTime();
        if (DAT_008c73c4 + 500 < (int)(DVar3 - DAT_008ed618)) {
            DAT_008c73c4 = -1;
            FUN_004baaa0();
            cVar2 = (char)(((char(*)(void))(*(void**)((char*)&DAT_008ecd78 + 0x18)))());
            if (cVar2 == '\0') {
                FUN_00488840();
                return;
            }
            FUN_0049f930();
        }
    }
}

// 0x4a60e0 — observed shape
void FUN_004a60e0(void* self, int in_EAX) {
    float fVar1;
    float fVar2;
    int iVar3;
    char cVar4;
    int in_ECX;

    in_ECX = (int)(intptr_t)self;
    if ((0x18 < DAT_008bc490[(in_EAX + in_ECX * 4) * 0x12a]) &&
        (iVar3 = in_EAX + in_ECX * 2, DAT_008c73cc[iVar3] < 0x19)) {
        DAT_008c73cc[iVar3] = 0x1a;
        FUN_00488c30(&DAT_008c73f4[iVar3], 0x2e, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0x3f800000, 0xffffffff);
    }
    if (DAT_008c73a8[in_ECX * 3] == 0) {
        DAT_008c73a0[in_ECX * 3] = (float)_DAT_008c84b0;
    }
    iVar3 = DAT_008c73a8[in_ECX * 3] + 1;
    DAT_008c73a8[in_ECX * 3] = iVar3;
    if (DAT_008c73a4 == -1.0f) {
        fVar1 = (float)DAT_008c73a0[in_ECX * 3] + 3.0f;
        fVar2 = (float)_DAT_008c84b0;
        if (((fVar2 == fVar2 && fVar1 == fVar1) && (fVar2 < fVar1 != (fVar2 == fVar1))) && (2 < iVar3)) {
            cVar4 = (char)((in_ECX != 0) + 'D');
            if (cVar4 == 'E') {
                DAT_008c73c4 = FUN_0042c4b0();
                DAT_008c73a4 = 5.0f;
                return;
            }
            iVar3 = (int)(intptr_t)FUN_004baaa0();
            FUN_00488a80(cVar4, *(uint32_t*)((char*)(intptr_t)iVar3 + 0x90), *(uint32_t*)((char*)(intptr_t)iVar3 + 0x94),
                         *(uint32_t*)((char*)(intptr_t)iVar3 + 0x98), 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                         &DAT_008c73e0, 0xbf800000, 0xffffffff);
            DAT_008c73a4 = 5.0f;
        }
    }
}

// 0x4a6210 — observed shape
void FUN_004a6210(void) {
    float fVar1;

    fVar1 = (float)_DAT_008c84b0;
    if (DAT_008c73a4 != -1.0f) {
        if (DAT_008c73a4 <= 0.0f) {
            DAT_008c73a4 = -1.0f;
        } else {
            DAT_008c73a4 = DAT_008c73a4 - (fVar1 - _DAT_008c739c);
        }
    }
    if ((DAT_008c73a0[0] != -1.0f) && (DAT_008c73a0[0] + 3.0f < fVar1)) {
        DAT_008c73a8[0] = 0;
        DAT_008c73a0[0] = -1.0f;
    }
    if ((DAT_008c73ac != -1.0f) && (_DAT_008c739c = fVar1, DAT_008c73ac + 3.0f < fVar1)) {
        DAT_008c73b4 = 0;
        DAT_008c73ac = -1.0f;
        return;
    }
    _DAT_008c739c = fVar1;
}

// 0x4a62f0 — observed shape
void FUN_004a62f0(void* self, int in_EAX, int unaff_ESI, int unaff_EDI) {
    float fVar1;
    int iVar2;
    int in_ECX;
    float fVar3;
    float fVar4;

    in_ECX = (int)(intptr_t)self;
    iVar2 = in_EAX + in_ECX * 4;
    fVar3 = (float)(((int)((int)(DAT_008bc46c[iVar2 * 0x12a] / 100 +
                       ((int)(DAT_008bc46c[iVar2 * 0x12a] / 100) >> 0x1f & 3U)) >> 2) + DAT_008b99d4);
    iVar2 = ((int)((int)(DAT_008bc470[iVar2 * 0x12a] / 100 +
                  ((int)(DAT_008bc470[iVar2 * 0x12a] / 100) >> 0x1f & 3U)) >> 2) + DAT_008b99d0;
    fVar4 = (float)iVar2;
    iVar2 = FUN_005f0ddc(iVar2, fVar3, fVar4);
    fVar1 = (float)iVar2;
    if (unaff_ESI < 1) {
        if (unaff_ESI < 0) {
            if (0 < unaff_EDI) {
                FUN_00488a80(0x32, fVar3, fVar4, fVar1, 0x14, 0xffffff38, 0xffffffff, 0xffffffff, &DAT_008c73ec, 0xbf800000, 0xffffffff);
                return;
            }
            if (unaff_EDI == 0) {
                FUN_00488b00(&DAT_008c73ec, 0x32, fVar3, fVar4, fVar1, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
            }
        }
    } else {
        if (unaff_EDI < 0) {
            FUN_00488a80(0x32, fVar3, fVar4, fVar1, 0x14, 0xffffff38, 0xffffffff, 0xffffffff, &DAT_008c73ec, 0xbf800000, 0xffffffff);
            return;
        }
        if (unaff_EDI == 0) {
            FUN_00488b00(&DAT_008c73ec, 0x32, fVar3, fVar4, fVar1, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
            return;
        }
    }
}

// 0x4a6490 — observed shape
void FUN_004a6490(uint32_t* param_1, int in_EAX, void* self) {
    int* piVar1;
    uint32_t uVar2;

    if (in_EAX == 0) {
        uVar2 = 0x26;
    } else if (in_EAX == 1) {
        uVar2 = 0x33;
    } else {
        if (in_EAX != 2) {
            if (param_1 == (uint32_t*)0x0) {
                return;
            }
            piVar1 = (int*)param_1 + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                ((void(**)(int))(*param_1))(1);
                return;
            }
            return;
        }
        uVar2 = 0x34;
    }
    FUN_00488c30();
    *(uint32_t*)((char*)self + 4) = uVar2;
    *(uint32_t*)((char*)self + 8) = 0xffffffff;
    if (param_1 != (uint32_t*)0x0) {
        piVar1 = (int*)param_1 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            ((void(**)(int))(*param_1))(1);
        }
    }
}

// 0x4a6500 — observed shape
void FUN_004a6500(void* self) {
    uint32_t uVar1;
    float fVar2;
    float fVar3;
    int iVar4;
    int iVar5;
    uint32_t uVar6;
    int iVar7;

    iVar4 = *(int*)((char*)self + 4) / 100;
    fVar2 = (float)(((int)(iVar4 + (iVar4 >> 0x1f & 3U)) >> 2) + DAT_008b99d4);
    iVar4 = *(int*)((char*)self + 8) / 100;
    fVar3 = (float)(((int)(iVar4 + (iVar4 >> 0x1f & 3U)) >> 2) + DAT_008b99d0);
    iVar4 = FUN_005f0ddc();
    uVar1 = *(uint32_t*)((char*)self + 0x68);
    uVar6 = uVar1 >> 7;
    iVar5 = *(int*)((char*)self + 0x44) / 2;
    iVar7 = -1;
    if (iVar5 < 10) {
        if (iVar5 < 6) {
            if (iVar5 < 3) {
                if (*(int*)((char*)self + 0x44) == 0) goto LAB_004a6631;
                iVar7 = 0x3e;
                iVar5 = (int)(-(uint32_t)((uVar6 & 1) != 0) & 0x15) + 0x25;
            } else {
                iVar7 = 0x3f;
                iVar5 = (int)(-(uint32_t)((uVar6 & 1) != 0) & 3) + 0x38;
            }
        } else {
            iVar7 = 0x3f;
            iVar5 = (int)(-(uint32_t)((uVar6 & 1) != 0) & 3) + 0x39;
        }
    } else {
        iVar7 = 0x40;
        iVar5 = (int)(-(uint32_t)((uVar6 & 1) != 0) & 0x16) + 0x27;
    }
    if (iVar5 != -1) {
        FUN_00488a80(iVar5, fVar2, fVar3, (float)iVar4, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0, 0xbf800000, 0xffffffff);
    }
LAB_004a6631:
    if (((uVar1 >> 6 & 1) != 0) && (iVar7 != -1)) {
        FUN_00488a80(iVar7, fVar2, fVar3, (float)iVar4, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0, 0xbf800000, 0xffffffff);
    }
}

// 0x4a6680 — observed shape
uint32_t FUN_004a6680(int in_EAX) {
    switch (in_EAX) {
    case 0:
    case 9:
    case 0x12:
        return 7;
    case 1:
    case 10:
    case 0x13:
        return 6;
    case 2:
    case 0xb:
    case 0x14:
        return 1;
    default:
        return 0;
    case 4:
    case 0xd:
    case 0x16:
        return 3;
    case 5:
    case 0xe:
    case 0x17:
        return 5;
    case 6:
    case 0xf:
    case 0x18:
        return 4;
    case 7:
    case 0x10:
    case 0x19:
        return 2;
    case 8:
    case 0x11:
    case 0x1a:
        return 8;
    }
}

// 0x4a6710 — observed shape
void FUN_004a6710(int param_1, int param_2, char param_3, int in_EAX) {
    uint32_t uVar1;

    DAT_008c827f = 0;
    DAT_008c827e = 0;
    DAT_008c735e = 1;
    if ((in_EAX == 300) || (in_EAX == 0x259)) {
        DAT_008c735d = '\x01';
    } else {
        DAT_008c735d = '\0';
    }
    DAT_008c7358 = (int)(-(uint32_t)(DAT_008c735d != '\0') & 0xd) + 0x73;
    FUN_004a72c0();
    if (param_3 == '\0') {
        if (param_2 == 4) {
            uVar1 = (uint32_t)rand();
            uVar1 = uVar1 & 0x80000001;
            if ((int)uVar1 < 0) {
                uVar1 = (uVar1 - 1 | 0xfffffffe) + 1;
            }
            DAT_008c7354 = (int)(uVar1 + 4);
        } else {
            uVar1 = (uint32_t)rand();
            DAT_008c7354 = (int)(uVar1 & 0x80000003);
            if ((int)DAT_008c7354 < 0) {
                DAT_008c7354 = (int)((DAT_008c7354 - 1 | 0xfffffffc) + 1);
            }
        }
    } else {
        DAT_008c7354 = 6;
    }
    FUN_004890c0(&DAT_008c7388);
    FUN_004891a0(&DAT_008c7394);
    FUN_004891a0(&DAT_008c738c);
    FUN_004890c0(&DAT_008c7384);
    FUN_004890c0(&DAT_008c7380);
    FUN_004890c0(&DAT_008c737c);
    FUN_004891a0(&DAT_008c7390);
    DAT_008c7364 = 0xffffffff;
    FUN_00488ed0(0);
    FUN_004985e0();
    FUN_004a14b0();
    FUN_004985e0();
    FUN_004a14b0();
    FUN_00498850(param_1 + 3);
    FUN_004985e0();
    FUN_004a14b0();
    DAT_008c735c = 0;
}

// 0x4a68d0 — observed shape
void FUN_004a68d0(void) {
    FUN_00489130(&DAT_008c7388);
    FUN_00489210(&DAT_008c7394);
    FUN_00489210(&DAT_008c738c);
    FUN_00489130(&DAT_008c7380);
    FUN_00489130(&DAT_008c737c);
    if (DAT_008c735c == '\0') {
        FUN_00488ed0(0x3f800000);
    }
    DAT_008c7354 = 0xffffffff;
    FUN_004985e0();
    FUN_004a14b0();
    FUN_004985e0();
    FUN_004a14b0();
    FUN_00498a50();
}

// 0x4a69b0 — observed shape
void FUN_004a69b0(int param_1, int param_2, int param_3, int in_EAX) {
    uint32_t uVar1;
    int iVar2;
    int iVar3;
    uint32_t uVar4;

    iVar2 = DAT_008c736c;
    if (param_1 != 1) {
        if (param_1 == 3) {
            if (DAT_008c736c < 3) {
                FUN_004985e0();
                FUN_004a14b0();
            }
            if (param_2 == 0x26d) {
                iVar2 = 9;
                iVar3 = 10;
            } else {
                iVar3 = iVar2;
                if (param_2 == 0x5e7) {
                    if (param_3 == 0) {
                        iVar3 = 7;
                        iVar2 = 7;
                    } else {
                        iVar2 = 8;
                        iVar3 = 8;
                        if (param_3 != 2) {
                            iVar3 = 9;
                        }
                    }
                }
            }
            FUN_004a2080(0x6f, iVar3, iVar2);
            DAT_008c735c = 1;
            DAT_008c7378 = param_1;
            return;
        }
        if (param_1 != 4) {
            return;
        }
        if (DAT_008c736c < 3) {
            FUN_004985e0();
            FUN_004a14b0();
        }
        if (param_2 == 200) {
            iVar2 = 7;
        }
        FUN_004a2080(0x71, iVar2, iVar2);
        DAT_008c735c = 1;
        DAT_008c7378 = param_1;
        return;
    }
    if ((DAT_008c736c == 6) && (DAT_008e8eff == '\0')) {
        FUN_004985e0();
        FUN_004a14b0();
    }
    if (in_EAX == 300) {
        if (DAT_00869b21 == '\x02') {
            FUN_004a2080(0x83, 2, 1);
            DAT_008c7378 = param_1;
            return;
        }
        if (DAT_00869b21 == '\x01') {
            FUN_004a2080(0x83, 1, 1);
            DAT_008c7378 = param_1;
            return;
        }
        FUN_004a2080(0x83, 0, 0);
        DAT_008c7378 = param_1;
        return;
    }
    if (in_EAX == 0x130) {
        if (DAT_00869b21 == '\x02') {
            FUN_004a2080(0x6d, 1, DAT_008c7368);
            DAT_008c7378 = param_1;
            return;
        }
        FUN_004a2080(0x6d, 0, DAT_008c7368);
        DAT_008c7378 = param_1;
        return;
    }
    if (in_EAX == 0x82) {
        FUN_004a2080(0x6d, 2, DAT_008c7368);
        DAT_008c7378 = param_1;
        return;
    }
    if (in_EAX == 0x87) {
        uVar4 = 0x6d;
        uVar1 = (uint32_t)DAT_008c7368;
    } else {
        if (in_EAX != 0x259) {
            FUN_00488d90(0x6d, 0, 0, 0, 0xffffffff, 0xffffffff, 0xffffffff, 0, DAT_008c7368);
            DAT_008c7378 = param_1;
            return;
        }
        uVar4 = 0x83;
        uVar1 = 2;
    }
    FUN_004a2080((int)uVar4, 3, (int)uVar1);
    DAT_008c7378 = param_1;
}

// 0x4a6d50 — observed shape
void FUN_004a6d50(void) {
    uint32_t local_94;
    uint32_t local_90;
    uint32_t local_8c;
    uint32_t local_88;
    float local_84;
    uint32_t local_7c;
    float local_78;
    uint32_t local_70;
    float local_6c;
    uint32_t local_64;
    uint32_t local_1c;
    uint32_t local_18;
    uint32_t local_14;
    uint8_t* local_4;

    if (DAT_008c7384 == 0) {
        if (DAT_008c735e != '\0') {
            FUN_00488df0((uint32_t)(-(uint32_t)(DAT_008c735d != '\0') & 0xdU) + 0x73, 1, 0, 0, 0xffffffff, 0xffffffff, 0xffffffff, &DAT_008c7384, DAT_008c7368);
        }
    } else {
        DAT_008c735e = '\0';
    }
    FUN_004a73c0();
    if (DAT_008e9fd8 != 0) {
        FUN_004ae640(DAT_008e9fd8, &local_94, &local_88);
        local_1c = local_94;
        local_4 = (uint8_t*)&DAT_008cacd0;
        local_64 = 1;
        local_18 = local_90;
        local_14 = local_8c;
        FUN_004985e0();
        FUN_004a14b0();
        FUN_004987a0(&DAT_008e67b0, local_88, local_7c, local_70, -local_84, -local_78, -local_6c);
    }
}

// 0x4a6ec0 — observed shape
void FUN_004a6ec0(uint32_t* param_1) {
    int iVar1;

    if (param_1 != (uint32_t*)0x0) {
        FUN_00488b80();
        iVar1 = (int)param_1[1];
        param_1[1] = (uint32_t)(iVar1 + -1);
        if (iVar1 + -1 == 0) {
            ((void(**)(int))(*param_1))(1);
        }
    }
}

// 0x4a6f00 — observed shape
void FUN_004a6f00(void) {
    switch (DAT_0072cb4c) {
    case 0:
    case 1:
    case 2:
        if (DAT_008e8eff != '\0') {
            return;
        }
        goto LAB_004a6f51;
    case 3:
    case 4:
        break;
    case 5:
        break;
    default:
        goto switchD_004a6f13_default;
    }
    if (DAT_008e8eff == '\0') {
LAB_004a6f51:
        FUN_004985e0();
        FUN_004a14b0();
    }
switchD_004a6f13_default:
    return;
}

// 0x4a6fc0 — observed shape
void FUN_004a6fc0(int param_1, int param_2, uint32_t param_3, int param_4) {
    float fVar1;
    float fVar2;
    float fVar3;
    float fVar4;
    char cVar5;
    int* piVar6;
    int iVar7;
    float* pfVar8;
    int iVar9;
    int iVar10;
    float fVar11;
    uint8_t auStack_ca[22];
    int local_b4[13];
    char local_80[128];

    (void)param_3;
    local_b4[0] = 0x59 - (uint32_t)(DAT_0072cb4c != 1);
    DAT_008c7370 = 0;
    if (param_1 != 0) {
        iVar10 = 1;
        do {
            std::sprintf(local_80, "dummy_%s_%02d", "fx_fire_floor", iVar10);
            piVar6 = (int*)FUN_004baaa0();
            iVar7 = ((int(*)(char*))(*(void**)((char*)(void*)(intptr_t)(*piVar6) + 0x40)))(local_80);
            if (iVar7 == 0) break;
            iVar10 = iVar10 + 1;
        } while (iVar10 < 100);
        DAT_008c7370 = iVar10 + -1;
        DAT_008c7398 = thunk_FUN_00533c78(DAT_008c7370 * 4);
        iVar10 = FUN_005f0ddc();
        fVar11 = (float)iVar10;
        if (iVar10 < 0) {
            fVar11 = fVar11 + 4.2949673e+09f;
        }
        FUN_0053c7c0(fVar11 * 1.4629181e-09f);
        fVar11 = 0.0f;
        if (0 < DAT_008c7370) {
            do {
                fVar1 = (float)((int)fVar11 + 1);
                std::sprintf(local_80, "dummy_%s_%02d", "fx_fire_floor", fVar1);
                piVar6 = (int*)FUN_004baaa0();
                ((int(*)(char*))(*(void**)((char*)(void*)(intptr_t)(*piVar6) + 0x40)))(local_80);
                pfVar8 = FUN_0053ca60(local_b4, auStack_ca + -6);
                fVar2 = *pfVar8;
                fVar3 = pfVar8[1];
                fVar4 = pfVar8[2];
                if (DAT_0072cb4c == 2) {
                    iVar10 = -DAT_0072ccd4;
                } else {
                    iVar10 = 0;
                }
                iVar9 = DAT_00723900 + param_4;
                FUN_004891a0((void*)((intptr_t)DAT_008c7398 + (int)fVar11 * 4));
                iVar7 = (int)((intptr_t)DAT_008c7398 + (int)fVar11 * 4);
                cVar5 = (char)(((char(*)(void))(*(void**)((char*)&DAT_008ecd78 + 0x18)))());
                if (cVar5 == '\0') {
                    FUN_00488840("The audio manager has not been properly initialized yet", 0);
                } else {
                    FUN_0049f930(&DAT_008e67b0, local_b4[0], 0, (float)(iVar10 + param_2) + fVar2, fVar1 + fVar3,
                                 (float)iVar9 + fVar4, 0xffffffff, 0xffffffff, 0xffffffff, iVar7, 0x40000000, 0xffffffff, 1);
                }
                fVar11 = fVar1;
            } while ((int)fVar1 < DAT_008c7370);
        }
    }
}

// 0x4a7220 — observed shape
void FUN_004a7220(void) {
    int iVar1;
    bool bVar2;

    bVar2 = DAT_0072cb4c != 1;
    iVar1 = 0;
    if (0 < DAT_008c7370) {
        do {
            FUN_00489040((void*)((intptr_t)DAT_008c7398 + iVar1 * 4), 0x59 - (uint32_t)bVar2, 0xbf800000);
            FUN_00489210((void*)((intptr_t)DAT_008c7398 + iVar1 * 4));
            iVar1 = iVar1 + 1;
        } while (iVar1 < DAT_008c7370);
    }
    while (true) {
        iVar1 = DAT_008e8ec4 - _DAT_008e8ec8;
        if (iVar1 < 0) {
            iVar1 = iVar1 + 100;
        }
        if (iVar1 == 0) break;
        Sleep(0x28);
    }
    if (DAT_008c7398 != (void*)0x0) {
        operator_delete__(DAT_008c7398);
        DAT_008c7398 = (void*)0x0;
    }
}

// 0x4a72c0 — observed shape
void FUN_004a72c0(void) {
    switch (DAT_0072cb4c) {
    case 0:
        DAT_008c736c = 0;
        break;
    case 1:
        DAT_008c736c = 1;
        break;
    case 2:
        DAT_008c736c = 2;
        break;
    case 3:
        DAT_008c736c = 3;
        break;
    case 4:
        DAT_008c736c = 4;
        break;
    case 5:
        DAT_008c736c = 5;
        break;
    case 6:
        DAT_008c736c = 6;
    }
    if (DAT_008c735d == '\0') {
        DAT_00727080 = DAT_00727080 * 0x343fd + 0x269ec3;
        DAT_008c7368 = FUN_005f0ddc(DAT_00727080);
        return;
    }
    DAT_00727080 = DAT_00727080 * 0x343fd + 0x269ec3;
    DAT_008c7368 = FUN_005f0ddc(DAT_00727080);
}

// 0x4a73c0 — observed shape
void FUN_004a73c0(void) {
    int iVar1;
    int iVar2;
    int iVar3;

    if (((DAT_008c735e == '\0') && (DAT_008c7378 != 4)) && (DAT_008c7378 != 3)) {
        if (DAT_008c735d == '\0') {
            iVar1 = 0x73;
            iVar2 = 0x78;
            iVar3 = 0x79;
        } else {
            iVar1 = 0x80;
            iVar2 = 0x7e;
            iVar3 = 0x7f;
        }
        if ((3 < DAT_0072ccf0) && (DAT_008c7358 != iVar2)) {
            FUN_00488d90(iVar3, 1, 0x40000000, 1, 0xffffffff, 0xffffffff, 0xffffffff, &DAT_008c7384, DAT_008c7368);
            DAT_008c7358 = iVar3;
            return;
        }
        if ((DAT_0072ccf0 < -3) && (DAT_008c7358 != iVar3)) {
            FUN_00488d90(iVar2, 1, 0x40000000, 1, 0xffffffff, 0xffffffff, 0xffffffff, &DAT_008c7384, DAT_008c7368);
            DAT_008c7358 = iVar2;
            return;
        }
        if (((DAT_008c7358 != iVar1) && (DAT_0072ccf0 < 4)) && (-4 < DAT_0072ccf0)) {
            FUN_00488d90(iVar1, 1, 0x40000000, 1, 0xffffffff, 0xffffffff, 0xffffffff, &DAT_008c7384, DAT_008c7368);
            DAT_008c7358 = iVar1;
        }
    }
}

// 0x4a74d0 — observed shape
void FUN_004a74d0(uint32_t param_1, int param_2, int param_3) {
    float fVar1;
    int iVar2;
    int* piVar3;
    int iVar4;
    float* pfVar5;
    uint32_t uVar6;
    char* pcStack_40;
    float fStack_3c;
    float fStack_38;
    uint8_t auStack_34[52];

    (void)param_1;
    pcStack_40 = (char*)0x0;
    iVar2 = FUN_005f0ddc(0);
    fVar1 = (float)iVar2;
    if (iVar2 < 0) {
        fVar1 = fVar1 + 4.2949673e+09f;
    }
    FUN_004dadc0(fVar1 * 1.4629181e-09f);
    pcStack_40 = (char*)(intptr_t)0x1;
    uVar6 = 0;
    FUN_004baaa0(0);
    FUN_00533d10(uVar6);
    pcStack_40 = (char*)(intptr_t)0x4a7527;
    piVar3 = (int*)FUN_004baaa0();
    pcStack_40 = "dummy_audio_01";
    iVar4 = ((int(*)())(*(void**)((char*)(void*)(intptr_t)(*piVar3) + 0x40)))();
    if (iVar4 != 0) {
        pcStack_40 = (char*)(intptr_t)(*(uint32_t*)((char*)(intptr_t)iVar4 + 0x90));
        fStack_3c = *(float*)((char*)(intptr_t)iVar4 + 0x94);
        fStack_38 = *(float*)((char*)(intptr_t)iVar4 + 0x98);
        pfVar5 = FUN_0053ca60(auStack_34, &pcStack_40);
        if (DAT_0072cb4c == 2) {
            iVar4 = -DAT_0072ccd4;
        } else {
            iVar4 = 0;
        }
        pcStack_40 = (char*)(intptr_t)(int32_t)((float)(iVar4 + iVar2) + *pfVar5);
        fStack_3c = (float)param_2 + pfVar5[1];
        fStack_38 = (float)(DAT_00723900 + param_3) + pfVar5[2];
        FUN_00488a80(100, (int)(intptr_t)pcStack_40, fStack_3c, fStack_38, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, &DAT_008c7390, 0x40000000, 0xffffffff);
    }
}

// 0x4a7610 — observed shape
void FUN_004a7610(void) {
    char cVar1;
    int iVar2;

    FUN_004890c0(&DAT_008c7350);
    FUN_004890c0(&DAT_008c734c);
    FUN_004890c0(&DAT_008c7348);
    FUN_004890c0(&DAT_008c7344);
    cVar1 = (char)(((char(*)(int))(*(void**)((char*)&DAT_008ecd78 + 0x18)))(10));
    if ((cVar1 != '\0') && ((DAT_008cac27 == '\0' || (DAT_008cac26 != '\0')))) {
        while (true) {
            iVar2 = DAT_008e8ec4 - _DAT_008e8ec8;
            if (iVar2 < 0) {
                iVar2 = iVar2 + 100;
            }
            if (iVar2 == 0) break;
            Sleep(0x28);
        }
        FUN_004a0d90();
        FUN_0049af70(*DAT_008ed2c8, 0);
        FUN_0049aed0(0xb, 0xfffffffe);
    }
}

// 0x4a76c0 — observed shape
void FUN_004a76c0(void) {
    char cVar1;
    int iVar2;
    uint32_t uVar3;
    uint32_t uVar4;

    FUN_00489130(&DAT_008c7350);
    FUN_00489130(&DAT_008c734c);
    FUN_00489130(&DAT_008c7348);
    FUN_00489130(&DAT_008c7344);
    FUN_004985e0();
    FUN_004a14b0();
    cVar1 = (char)(((char(*)(void))(*(void**)((char*)&DAT_008ecd78 + 0x18)))());
    if ((cVar1 != '\0') && ((DAT_008cac27 == '\0' || (DAT_008cac26 != '\0')))) {
        while (true) {
            iVar2 = DAT_008e8ec4 - _DAT_008e8ec8;
            if (iVar2 < 0) {
                iVar2 = iVar2 + 100;
            }
            if (iVar2 == 0) break;
            Sleep(0x28);
        }
        if ((DAT_008e8eec != 0) && ((DAT_008e8ef0 - DAT_008e8eec >> 2) != 0)) {
            DAT_008e8ef0 = DAT_008e8ef0 + -4;
        }
        FUN_0049af70(*DAT_008ed2c8, 0);
        uVar4 = 0xfffffffe;
        uVar3 = (uint32_t)FUN_004a0b70(0xfffffffe);
        FUN_0049aed0((int)uVar3, (int)uVar4);
    }
    if (DAT_008e8f08 != (void*)0x0) {
        operator_delete__(DAT_008e8f08);
        DAT_008e8f08 = (void*)0x0;
    }
    DAT_008e8f04 = 0;
}
