#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void* thunk_FUN_00533c78(int size);
extern void FUN_0056a010(void* p);
extern void CRect_ctor_zero(void* r);
extern int FUN_0056a5b0(int a, int b);
extern void* FUN_0056cce0(void);
extern void* FUN_0056cd30(void);
extern void* FUN_0056ccb0(void);
extern void* FUN_0056cbc0(void);
extern void* LAB_0056cb20;
extern void* LAB_0056b110;
extern void* LAB_0056cb70;
extern void* LAB_0056cd90;

extern unsigned char DAT_007283b3;
extern unsigned int _DAT_007288d8;
extern unsigned int _DAT_007287e8;
extern unsigned int _DAT_00728770;
extern void* _DAT_00728950;
extern void* _DAT_00728680;
extern void* _DAT_00728608;
extern void* _DAT_00728590;
extern void* _DAT_00728518;
extern void* _DAT_00728860;
extern void* _DAT_007286f8;
extern void* _DAT_00728428;
extern void* _DAT_007284a0;

// 0x56ced0 — observed shape
int* FUN_0056ced0(uint32_t param_1, int param_2) {
    int* piVar1 = (int*)thunk_FUN_00533c78(param_2 * 0x28 + 4);
    int* piVar3;
    if (piVar1 == nullptr) {
        piVar3 = nullptr;
    } else {
        *piVar1 = param_2;
        piVar3 = piVar1 + 1;
        if (param_2 - 1 >= 0) {
            piVar1 = piVar1 + 2;
            int iVar2 = param_2;
            do {
                *(uint8_t*)piVar1 = 8;
                CRect_ctor_zero((void*)(piVar1 + 1));
                *(uint8_t*)piVar1 = 0x28;
                piVar1 = piVar1 + 10;
                iVar2 = iVar2 - 1;
            } while (iVar2 != 0);
        }
    }
    for (; param_2 != 0; param_2 = param_2 - 1) {
        FUN_0056a010((void*)param_1);
    }
    return piVar3;
}

// 0x56cf50 — observed shape
uint32_t FUN_0056cf50(void) {
    if (DAT_007283b3 == 0) {
        _DAT_007288d8 = 0;
        _DAT_007287e8 = 0;
        _DAT_00728770 = 0;
        DAT_007283b3 = 1;
        _DAT_00728950 = (void*)FUN_0056ced0;
        _DAT_00728680 = (void*)FUN_0056cce0;
        _DAT_00728608 = LAB_0056cb20;
        _DAT_00728590 = (void*)FUN_0056cd30;
        _DAT_00728518 = LAB_0056b110;
        _DAT_00728860 = LAB_0056cb70;
        _DAT_007286f8 = (void*)FUN_0056ccb0;
        _DAT_00728428 = (void*)FUN_0056cbc0;
        _DAT_007284a0 = LAB_0056cd90;
        return 1;
    }
    return 0;
}

// 0x56cfe0 — observed shape
uint32_t FUN_0056cfe0(int param_1, int param_2) {
    uint32_t uVar1 = (uint32_t)FUN_0056a5b0(param_1, param_2);
    if ((char)uVar1 == 0) {
        return uVar1;
    }
    if ((*(float*)(param_1 + 0xc) == *(float*)(param_2 + 0xc)) &&
        (*(float*)(param_1 + 0x10) == *(float*)(param_2 + 0x10)) &&
        (*(float*)(param_1 + 0x14) == *(float*)(param_2 + 0x14)) &&
        (*(float*)(param_1 + 0x18) == *(float*)(param_2 + 0x18)) &&
        (*(float*)(param_1 + 0x1c) == *(float*)(param_2 + 0x1c))) {
        return 1;
    }
    return 0;
}

// 0x56d0f0 — observed shape
int* FUN_0056d0f0(int param_1) {
    int* piVar1 = (int*)thunk_FUN_00533c78(param_1 * 0x20 + 4);
    int* piVar2;
    if (piVar1 == nullptr) {
        piVar2 = nullptr;
    } else {
        *piVar1 = param_1;
        piVar2 = piVar1 + 1;
        if (param_1 - 1 >= 0) {
            piVar1 = piVar1 + 2;
            do {
                *(uint8_t*)piVar1 = 0x20;
                piVar1 = piVar1 + 8;
                param_1 = param_1 - 1;
            } while (param_1 != 0);
            return piVar2;
        }
    }
    return piVar2;
}

// 0x56d130 — observed shape
void FUN_0056d130(int param_1, float param_2, float param_3, float param_4, float param_5) {
    param_2 = *(float*)(param_1 + 8) - param_2;
    param_3 = param_3 - *(float*)(param_1 + 8);
    float fVar2 = *(float*)(param_1 + 0x14) + 1.0f;
    float fVar1 = 1.0f - *(float*)(param_1 + 0x14);
    float fVar3 = (1.0f - *(float*)(param_1 + 0xc)) * 0.5f;
    float fVar4 = (*(float*)(param_1 + 0x10) + 1.0f) * fVar3;
    fVar3 = (1.0f - *(float*)(param_1 + 0x10)) * fVar3;
    float fVar5 = 2.0f / (param_4 + param_5);
    *(float*)(param_1 + 0x18) = (fVar3 * fVar2 * param_2 + fVar4 * fVar1 * param_3) * fVar5 * param_4;
    *(float*)(param_1 + 0x1c) = (fVar4 * fVar2 * param_2 + fVar3 * fVar1 * param_3) * fVar5 * param_5;
}

extern "C" float sqrtf(float);

extern int FUN_005762b0(int a, int* b, uint32_t c, uint32_t* d);
extern void FUN_004127b0(void* dst, int elemSize, int count, void* init);
extern void operator_delete__(void* p);
extern double FUN_0056a790(int a, int* b, int c, uint32_t d);
extern void FUN_0056a880(int a);
extern void FUN_0056a8b0(int a, int b);
extern uint32_t FUN_005695a0(int a, int b);
extern char FUN_004284c0(int a);
extern void FUN_005692e0(uint32_t a, int b);
extern void FUN_00535150(uint32_t a);
extern void FUN_005694f0(int* out, int a, int* b, int c, uint32_t d);
extern void FUN_00581f30(int a, int b, int* c, int d, int e, int* f, int g, int h, int* i, int* j);

extern void* LAB_0056d0a0;
extern void* LAB_0056d5b0;
extern void* LAB_0056d060;
extern void* LAB_0056d0b0;
extern void* LAB_0056d670;
extern void* LAB_0056db10;
extern void* LAB_0056d530;

extern unsigned char DAT_007283b4;
extern unsigned char DAT_007283b5;
extern unsigned int _DAT_007288b4;
extern unsigned int _DAT_007287c4;
extern unsigned int _DAT_0072874c;
extern void* _DAT_0072892c;
extern void* _DAT_0072865c;
extern void* _DAT_007285e4;
extern void* _DAT_0072856c;
extern void* _DAT_007284f4;
extern void* _DAT_0072883c;
extern void* _DAT_007286d4;
extern void* _DAT_00728404;
extern void* _DAT_0072847c;
extern void* _DAT_0072893c;
extern void* _DAT_0072866c;
extern void* _DAT_007285f4;
extern void* _DAT_0072857c;
extern void* _DAT_00728504;
extern int DAT_00727430;
extern int DAT_00727434;
extern int DAT_00727438;
extern int DAT_00717a9c;
extern float _DAT_00717aa0;
extern unsigned char DAT_007288a8;
extern unsigned char DAT_00728830;
extern unsigned char DAT_007287b8;
extern unsigned char DAT_00728740;
extern unsigned char DAT_007286c8;
extern unsigned char DAT_007283f8;
extern unsigned char DAT_00728470;

typedef void (*VFUN2)(void* self, int size);

// 0x56d1d0 — observed shape
void FUN_0056d1d0(int param_1, uint32_t param_2) {
    if (1 < param_2) {
        float* base = (float*)param_1;
        FUN_0056d130(param_1, (base[2] + base[2]) - base[10], base[10], 1.0f, 1.0f);
        uint32_t uVar1 = param_2 - 1;
        if (1 < uVar1) {
            int iVar4 = (int)(param_2 - 2);
            float* pfVar2 = base;
            do {
                FUN_0056d130((int)(pfVar2 + 8), pfVar2[2], pfVar2[0x12],
                             pfVar2[8] - *pfVar2, pfVar2[0x10] - pfVar2[8]);
                iVar4 = iVar4 - 1;
                pfVar2 = pfVar2 + 8;
            } while (iVar4 != 0);
        }
        FUN_0056d130((int)(base + uVar1 * 8), base[(param_2 - 2) * 8 + 2],
                     (base[uVar1 * 8 + 2] + base[uVar1 * 8 + 2]) - base[(param_2 - 2) * 8 + 2],
                     1.0f, 1.0f);
    }
}

// 0x56d280 — observed shape
uint32_t FUN_0056d280(int param_1, int** param_2, uint32_t* param_3) {
    int* piVar4 = *param_2;
    int* local_4 = piVar4;
    uint32_t local_8;
    char cVar1 = FUN_005762b0(param_1, piVar4, *param_3, &local_8);
    if (cVar1 == '\0') {
        return 0;
    }
    int iVar5 = (int)(*param_3 + 1);
    int* piVar2 = (int*)thunk_FUN_00533c78(iVar5 * 0x20 + 4);
    int* piVar3;
    if (piVar2 == nullptr) {
        piVar3 = nullptr;
    } else {
        piVar3 = piVar2 + 1;
        *piVar2 = iVar5;
        FUN_004127b0(piVar3, 0x20, iVar5, (void*)&LAB_0056d0a0);
    }
    piVar2 = piVar3;
    for (iVar5 = (int)((local_8 & 0x7ffffff) << 3); iVar5 != 0; iVar5 = iVar5 - 1) {
        *piVar2 = *piVar4;
        piVar4 = piVar4 + 1;
        piVar2 = piVar2 + 1;
    }
    if (local_8 < *param_3) {
        piVar4 = local_4 + local_8 * 8;
        piVar2 = piVar3 + local_8 * 8 + 8;
        for (iVar5 = (int)(((*param_3 - local_8) & 0x7ffffff) << 3); iVar5 != 0; iVar5 = iVar5 - 1) {
            *piVar2 = *piVar4;
            piVar4 = piVar4 + 1;
            piVar2 = piVar2 + 1;
        }
    }
    double fVar6 = FUN_0056a790(param_1, local_4, 3, *param_3);
    piVar4 = piVar3 + local_8 * 8;
    *piVar4 = param_1;
    piVar4[2] = (int)(float)fVar6;
    piVar4[3] = 0;
    piVar4[4] = 0;
    piVar4[5] = 0;
    *param_3 = *param_3 + 1;
    if (local_4 != nullptr) {
        operator_delete__(local_4 + -1);
    }
    *param_2 = piVar3;
    FUN_0056d1d0((int)piVar3, *param_3);
    return 1;
}

// 0x56d3a0 — observed shape
int* FUN_0056d3a0(int param_1, int param_2) {
    int* piVar1 = (int*)thunk_FUN_00533c78(param_2 * 0x20 + 4);
    int* piVar3;
    if (piVar1 == nullptr) {
        piVar3 = nullptr;
    } else {
        *piVar1 = param_2;
        piVar3 = piVar1 + 1;
        if (-1 < param_2 - 1) {
            piVar1 = piVar1 + 2;
            int iVar2 = param_2;
            do {
                *(uint8_t*)piVar1 = 0x20;
                piVar1 = piVar1 + 8;
                iVar2 = iVar2 - 1;
            } while (iVar2 != 0);
        }
    }
    if (param_2 != 0) {
        piVar1 = piVar3 + 4;
        do {
            FUN_0056a880(param_1);
            int* pObj = *(int**)(param_1 + 0x15c);
            int* vtable = (int*)*pObj;
            ((VFUN2)vtable[2])(piVar1 - 1, 4);
            ((VFUN2)vtable[2])(piVar1, 4);
            ((VFUN2)vtable[2])(piVar1 + 1, 4);
            piVar1 = piVar1 + 8;
            param_2 = param_2 - 1;
        } while (param_2 != 0);
    }
    return piVar3;
}

// 0x56d440 — observed shape
void FUN_0056d440(int param_1, int param_2, int param_3) {
    if (param_3 != 0) {
        param_2 = param_2 + 0x10;
        do {
            FUN_0056a8b0(param_1, param_2 - 0x10);
            int* pObj = *(int**)(param_1 + 0x160);
            int* vtable = (int*)*pObj;
            ((VFUN2)vtable[3])(param_2 - 4, 4);
            ((VFUN2)vtable[3])(param_2, 4);
            ((VFUN2)vtable[3])(param_2 + 4, 4);
            param_2 = param_2 + 0x20;
            param_3 = param_3 - 1;
        } while (param_3 != 0);
    }
}

// 0x56d4a0 — observed shape
uint32_t FUN_0056d4a0(void) {
    if (DAT_007283b4 == 0) {
        _DAT_007288b4 = 0;
        _DAT_007287c4 = 0;
        _DAT_0072874c = 0;
        DAT_007283b4 = 1;
        _DAT_0072892c = (void*)FUN_0056d3a0;
        _DAT_0072865c = (void*)FUN_0056d440;
        _DAT_007285e4 = (void*)&LAB_0056d060;
        _DAT_0072856c = (void*)FUN_0056d0f0;
        _DAT_007284f4 = (void*)&LAB_0056b110;
        _DAT_0072883c = (void*)&LAB_0056d0b0;
        _DAT_007286d4 = (void*)FUN_0056cfe0;
        _DAT_00728404 = (void*)FUN_0056d1d0;
        _DAT_0072847c = (void*)FUN_0056d280;
        return 1;
    }
    return 0;
}

// 0x56d5c0 — observed shape
uint32_t FUN_0056d5c0(int param_1, int param_2) {
    uint32_t uVar2 = FUN_005695a0(param_1, param_2);
    if ((char)uVar2 == '\0') {
        return uVar2;
    }
    if ((*(float*)(param_1 + 0x14) == *(float*)(param_2 + 0x14)) &&
        (*(float*)(param_1 + 0x18) == *(float*)(param_2 + 0x18)) &&
        (*(float*)(param_1 + 0x1c) == *(float*)(param_2 + 0x1c))) {
        char cVar1 = FUN_004284c0(param_2 + 0x20);
        if (cVar1 != '\0') {
            return 1;
        }
    }
    return 0;
}

// 0x56d630 — observed shape
int* FUN_0056d630(int param_1) {
    int* piVar1 = (int*)thunk_FUN_00533c78(param_1 * 0x44 + 4);
    int* piVar2;
    if (piVar1 == nullptr) {
        piVar2 = nullptr;
    } else {
        *piVar1 = param_1;
        piVar2 = piVar1 + 1;
        if (-1 < param_1 - 1) {
            piVar1 = piVar1 + 2;
            do {
                *(uint8_t*)piVar1 = 0x44;
                piVar1 = piVar1 + 0x11;
                param_1 = param_1 - 1;
            } while (param_1 != 0);
            return piVar2;
        }
    }
    return piVar2;
}

// 0x56d730 — observed shape
void FUN_0056d730(float param_1, int param_2, uint32_t param_3, float* param_4) {
    float fVar7 = param_1 * 3.0f;
    float fVar1 = *(float*)(param_2 + 0x3c);
    float fVar2 = *(float*)(param_2 + 0x40);
    float fVar3 = *(float*)(param_2 + 0x30);
    float fVar4 = *(float*)(param_2 + 0x34);
    float fVar5 = *(float*)(param_2 + 0x24);
    float fVar6 = *(float*)(param_2 + 0x28);
    *param_4 = (*(float*)(param_2 + 0x2c) + *(float*)(param_2 + 0x2c) +
                fVar7 * *(float*)(param_2 + 0x38)) * param_1 + *(float*)(param_2 + 0x20);
    param_4[1] = (fVar3 + fVar3 + fVar7 * fVar1) * param_1 + fVar5;
    param_4[2] = (fVar4 + fVar4 + fVar7 * fVar2) * param_1 + fVar6;
}

// 0x56d7d0 — observed shape
void FUN_0056d7d0(float param_1, int param_2, uint32_t param_3, float* param_4) {
    param_1 = param_1 * 6.0f;
    float fVar1 = *(float*)(param_2 + 0x3c);
    float fVar2 = *(float*)(param_2 + 0x40);
    float fVar3 = *(float*)(param_2 + 0x30);
    float fVar4 = *(float*)(param_2 + 0x34);
    *param_4 = *(float*)(param_2 + 0x2c) + *(float*)(param_2 + 0x2c) +
               param_1 * *(float*)(param_2 + 0x38);
    param_4[1] = fVar3 + fVar3 + param_1 * fVar1;
    param_4[2] = fVar4 + fVar4 + param_1 * fVar2;
}

// 0x56d850 — observed shape
void FUN_0056d850(int param_1, int param_2) {
    param_2 = param_2 - 1;
    if (param_2 != 0) {
        float* pfVar1 = (float*)(param_1 + 0x54);
        do {
            pfVar1[-10] = (pfVar1[-2] - pfVar1[-0x13]) * 3.0f -
                          (pfVar1[-0xd] + pfVar1[-0xd] + pfVar1[1]);
            pfVar1[-9] = (pfVar1[-1] - pfVar1[-0x12]) * 3.0f -
                         (pfVar1[-0xc] + pfVar1[-0xc] + pfVar1[2]);
            pfVar1[-8] = (*pfVar1 - pfVar1[-0x11]) * 3.0f -
                         (pfVar1[-0xb] + pfVar1[-0xb] + pfVar1[3]);
            pfVar1[-7] = (pfVar1[1] + pfVar1[-0xd]) -
                         ((pfVar1[-2] - pfVar1[-0x13]) + (pfVar1[-2] - pfVar1[-0x13]));
            pfVar1[-6] = (pfVar1[-0xc] + pfVar1[2]) -
                         ((pfVar1[-1] - pfVar1[-0x12]) + (pfVar1[-1] - pfVar1[-0x12]));
            pfVar1[-5] = (pfVar1[-0xb] + pfVar1[3]) -
                         ((*pfVar1 - pfVar1[-0x11]) + (*pfVar1 - pfVar1[-0x11]));
            pfVar1 = pfVar1 + 0x11;
            param_2 = param_2 - 1;
        } while (param_2 != 0);
    }
}

// 0x56d980 — observed shape
double FUN_0056d980(int param_1, int param_2) {
    float local_40 = 0.0f;
    float local_3c;
    float local_38;
    float local_34;
    float local_30;
    float local_2c;
    float local_28;
    float local_24;
    float local_20;
    float local_1c;
    if (param_2 - 1 != 0) {
        float* pfVar5 = (float*)(param_1 + 0x40);
        int iVar4 = DAT_00717a9c;
        param_1 = param_2 - 1;
        do {
            param_2 = 0;
            if (-1 < iVar4) {
                do {
                    float fVar1 = (float)param_2 * _DAT_00717aa0;
                    FUN_0056d730(fVar1, (int)(pfVar5 - 0x10), (uint32_t)(int)(pfVar5 + 1), &local_3c);
                    fVar1 = fVar1 * 6.0f;
                    float local_8 = fVar1 * pfVar5[-1];
                    float local_4 = fVar1 * *pfVar5;
                    float local_14 = pfVar5[-4] + pfVar5[-4];
                    float local_10 = pfVar5[-3] + pfVar5[-3];
                    local_30 = pfVar5[-5] + pfVar5[-5] + fVar1 * pfVar5[-2];
                    local_2c = local_14 + local_8;
                    local_28 = local_10 + local_4;
                    fVar1 = local_28 * local_38 - local_34 * local_2c;
                    float fVar3 = local_34 * local_30 - local_28 * local_3c;
                    float fVar2 = local_2c * local_3c - local_38 * local_30;
                    fVar1 = sqrtf(fVar1 * fVar1 + fVar3 * fVar3 + fVar2 * fVar2) /
                            (local_3c * local_3c + local_38 * local_38 + local_34 * local_34);
                    if (local_40 < fVar1) {
                        local_40 = fVar1;
                    }
                    param_2 = param_2 + 1;
                    iVar4 = DAT_00717a9c;
                    local_24 = local_30;
                    local_20 = local_2c;
                    local_1c = local_28;
                } while (param_2 <= DAT_00717a9c);
            }
            pfVar5 = pfVar5 + 0x11;
            param_1 = param_1 - 1;
        } while (param_1 != 0);
    }
    return (double)local_40;
}

// 0x56db90 — observed shape
void FUN_0056db90(uint32_t param_1, int param_2, int param_3) {
    if (param_3 != 0) {
        param_2 = param_2 + 0x20;
        do {
            FUN_005692e0(param_1, param_2 - 0x20);
            FUN_00535150(param_1);
            FUN_00535150(param_1);
            param_2 = param_2 + 0x44;
            param_3 = param_3 - 1;
        } while (param_3 != 0);
    }
}

// 0x56dbd0 — observed shape
uint32_t FUN_0056dbd0(int param_1, int** param_2, uint32_t* param_3) {
    int* piVar1 = *param_2;
    int* local_64 = piVar1;
    uint32_t local_74;
    char cVar2 = FUN_005762b0(param_1, piVar1, *param_3, &local_74);
    if (cVar2 == '\0') {
        return 0;
    }
    int iVar5 = (int)(*param_3 + 1);
    int* piVar3 = (int*)thunk_FUN_00533c78(iVar5 * 0x44 + 4);
    int* local_70;
    if (piVar3 == nullptr) {
        local_70 = nullptr;
    } else {
        *piVar3 = iVar5;
        FUN_004127b0(piVar3 + 1, 0x44, iVar5, (void*)&LAB_0056d5b0);
        local_70 = piVar3 + 1;
    }
    piVar3 = local_70;
    int* piVar6 = piVar1;
    int* piVar7 = local_70;
    uint32_t uVar4;
    for (uVar4 = local_74 * 0x44 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *piVar7 = *piVar6;
        piVar6 = piVar6 + 1;
        piVar7 = piVar7 + 1;
    }
    if (local_74 < *param_3) {
        piVar6 = piVar1 + local_74 * 0x11;
        piVar7 = local_70 + local_74 * 0x11 + 0x11;
        for (uVar4 = (*param_3 - local_74) * 0x44 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *piVar7 = *piVar6;
            piVar6 = piVar6 + 1;
            piVar7 = piVar7 + 1;
        }
    }
    int local_18;
    int local_14;
    int local_10;
    FUN_005694f0(&local_18, param_1, piVar1, 2, *param_3);
    piVar1 = local_70;
    piVar3[local_74 * 0x11] = param_1;
    piVar3[local_74 * 0x11 + 2] = local_18;
    piVar3[local_74 * 0x11 + 3] = local_14;
    piVar3[local_74 * 0x11 + 4] = local_10;
    piVar3[local_74 * 0x11 + 5] = DAT_00727430;
    piVar3[local_74 * 0x11 + 6] = DAT_00727434;
    piVar3[local_74 * 0x11 + 7] = DAT_00727438;
    piVar3[local_74 * 0x11 + 8] = DAT_00727430;
    piVar3[local_74 * 0x11 + 9] = DAT_00727434;
    piVar3[local_74 * 0x11 + 10] = DAT_00727438;
    if ((local_74 != 0) && (local_74 != *param_3)) {
        int local_3c = local_70[local_74 * 0x11 - 0xf];
        int local_38 = local_70[local_74 * 0x11 - 0xe];
        int local_34 = local_70[local_74 * 0x11 - 0xd];
        int local_68 = local_70[local_74 * 0x11 - 0x11];
        piVar6 = local_70 + local_74 * 0x11 - 9;
        int local_60 = *piVar6;
        int local_5c = local_70[local_74 * 0x11 - 8];
        int local_8 = piVar3[local_74 * 0x11 + 3];
        int local_58 = local_70[local_74 * 0x11 - 7];
        int local_4 = piVar3[local_74 * 0x11 + 4];
        int local_48 = local_70[local_74 * 0x11 + 0x13];
        int local_44 = local_70[local_74 * 0x11 + 0x14];
        int local_40 = local_70[local_74 * 0x11 + 0x15];
        int local_6c = local_70[local_74 * 0x11 + 0x11];
        piVar7 = local_70 + local_74 * 0x11 + 0x16;
        int local_54 = *piVar7;
        int local_50 = local_70[local_74 * 0x11 + 0x17];
        int local_4c = local_70[local_74 * 0x11 + 0x18];
        int local_30;
        int local_2c;
        int local_28;
        int local_24;
        int local_20;
        int local_1c;
        FUN_00581f30(local_3c, local_68, &local_60, local_48, local_6c, &local_54, param_1,
                     piVar3[local_74 * 0x11 + 2], &local_30, &local_24);
        FUN_00581f30(local_38, local_68, &local_5c, local_44, local_6c, &local_50, param_1,
                     local_8, &local_2c, &local_20);
        FUN_00581f30(local_34, local_68, &local_58, local_40, local_6c, &local_4c, param_1,
                     local_4, &local_28, &local_1c);
        *piVar6 = local_60;
        piVar1[local_74 * 0x11 - 8] = local_5c;
        piVar1[local_74 * 0x11 - 7] = local_58;
        piVar3[local_74 * 0x11 + 5] = local_30;
        piVar3[local_74 * 0x11 + 6] = local_2c;
        piVar3[local_74 * 0x11 + 7] = local_28;
        piVar3[local_74 * 0x11 + 8] = local_24;
        piVar3[local_74 * 0x11 + 9] = local_20;
        piVar3[local_74 * 0x11 + 10] = local_1c;
        *piVar7 = local_54;
        piVar1[local_74 * 0x11 + 0x17] = local_50;
        piVar1[local_74 * 0x11 + 0x18] = local_4c;
    }
    *param_3 = *param_3 + 1;
    if (local_64 != nullptr) {
        operator_delete__(local_64 + -1);
    }
    *param_2 = local_70;
    FUN_0056d850((int)local_70, *param_3);
    return 1;
}

// 0x56df30 — observed shape
void FUN_0056df30(int param_1, int param_2) {
    int iVar1 = (param_2 + param_1 * 5) * 4;
    *(void**)((uint8_t*)&DAT_007288a8 + iVar1) = (void*)FUN_0056d980;
    *(void**)((uint8_t*)&DAT_00728830 + iVar1) = (void*)&LAB_0056d670;
    *(void**)((uint8_t*)&DAT_007287b8 + iVar1) = (void*)FUN_0056d730;
    *(void**)((uint8_t*)&DAT_00728740 + iVar1) = (void*)FUN_0056d7d0;
    *(void**)((uint8_t*)&DAT_007286c8 + iVar1) = (void*)FUN_0056d5c0;
    *(void**)((uint8_t*)&DAT_007283f8 + iVar1) = (void*)FUN_0056d850;
    *(void**)((uint8_t*)&DAT_00728470 + iVar1) = (void*)FUN_0056dbd0;
}

// 0x56df90 — observed shape
uint32_t FUN_0056df90(void) {
    if (DAT_007283b5 == 0) {
        DAT_007283b5 = 1;
        _DAT_0072893c = (void*)&LAB_0056db10;
        _DAT_0072866c = (void*)FUN_0056db90;
        _DAT_007285f4 = (void*)&LAB_0056d530;
        _DAT_0072857c = (void*)FUN_0056d630;
        _DAT_00728504 = (void*)&LAB_0056b110;
        FUN_0056df30(1, 2);
        return 1;
    }
    return 0;
}
