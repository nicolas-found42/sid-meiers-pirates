#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_005931d0();
extern void FUN_006b34a0(int);
extern char FUN_00591460(void*, void*, void*, void*, void*);

// 0x5932c0 — observed shape
void FUN_005932c0(void* self, int* param_1) {
    typedef int (*Vfunc0)(void*);
    typedef void (*Vfunc1)(void*);
    int iVar2 = (*(Vfunc0*)(*(intptr_t*)param_1 + 0xc))();
    if (iVar2 == 4) {
        FUN_005931d0();
        FUN_006b34a0(param_1[4]);
        uint32_t uVar4 = 0;
        if (param_1[4] != 0) {
            do {
                int* piVar1 = *(int**)((intptr_t)param_1[2] + uVar4 * 4);
                int* piVar3 = (int*)(*(Vfunc0*)(*(intptr_t*)piVar1 + 0x18))();
                (*(Vfunc1*)(*(intptr_t*)piVar3 + 0x20))(piVar1);
                intptr_t in_ECX = (intptr_t)self;
                if (uVar4 < *(uint32_t*)(in_ECX + 0xc)) {
                    if (uVar4 < *(uint32_t*)(in_ECX + 0x10)) {
                        if (*(int*)(*(intptr_t*)(in_ECX + 8) + uVar4 * 4) == 0) goto LAB_00593333;
                    } else {
                        *(uint32_t*)(in_ECX + 0x10) = uVar4 + 1;
LAB_00593333:
                        *(int32_t*)(in_ECX + 0x14) = *(int32_t*)(in_ECX + 0x14) + 1;
                    }
                    *(int**)(*(intptr_t*)(in_ECX + 8) + uVar4 * 4) = piVar3;
                }
                uVar4 = uVar4 + 1;
            } while (uVar4 < (uint32_t)param_1[4]);
        }
    }
}

// 0x593350 — observed shape
uint32_t FUN_00593350(void* self, int* param_1) {
    typedef uint32_t (*Vfunc0)(void*);
    uint32_t uVar1 = (*(Vfunc0*)(*(intptr_t*)param_1 + 0xc))();
    intptr_t in_ECX = (intptr_t)self;
    if ((uVar1 != 4) || (uVar1 = *(uint32_t*)(in_ECX + 0x10), uVar1 != (uint32_t)param_1[4])) {
        return uVar1 & 0xffffff00;
    }
    uint32_t uVar3 = 0;
    uint32_t uVar2 = 0;
    if (uVar1 != 0) {
        do {
            uVar1 = (*(Vfunc0*)(*(intptr_t*)(*(intptr_t*)(*(intptr_t*)(in_ECX + 8) + uVar3 * 4)) + 0x28))(*(void**)((intptr_t)param_1[2] + uVar3 * 4));
            if ((char)uVar1 != '\0') {
                return uVar1 & 0xffffff00;
            }
            uVar2 = *(uint32_t*)(in_ECX + 0x10);
            uVar3 = uVar3 + 1;
        } while (uVar3 < uVar2);
    }
    return (uint32_t)(((uVar2 >> 8) & 0x00ffffff) << 8) | 1;
}

// 0x5933b0 — observed shape
void FUN_005933b0(void* self, int param_1, void* param_2) {
    uint32_t uVar1 = 0;
    intptr_t in_ECX = (intptr_t)self;
    if (*(int32_t*)(in_ECX + 0x10) != 0) {
        do {
            typedef void (*Vfunc)(void*, void*);
            (*(Vfunc*)(*(intptr_t*)(*(intptr_t*)(*(intptr_t*)(in_ECX + 8) + uVar1 * 4)) + 0x14))(*(void**)(*(intptr_t*)(param_1 + 8) + uVar1 * 4), param_2);
            uVar1 = uVar1 + 1;
        } while (uVar1 < *(uint32_t*)(in_ECX + 0x10));
    }
}

// 0x5933f0 — observed shape
int FUN_005933f0(void* param_1, int param_2, void* param_3, void* param_4, void* param_5) {
    uint32_t uVar2 = 0;
    if (*(int32_t*)(param_2 + 0x10) != 0) {
        do {
            char cVar1 = FUN_00591460(param_1, *(void**)(*(intptr_t*)(param_2 + 8) + uVar2 * 4), param_3, param_4, param_5);
            if (cVar1 != '\0') {
                *(uint32_t*)(param_2 + 0x1c) = uVar2;
                return 1;
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint32_t*)(param_2 + 0x10));
    }
    return 0;
}

// 0x593450 — observed shape
uint32_t FUN_00593450(void* param_1, int param_2, void* param_3, int param_4, void* param_5) {
    uint32_t uVar3 = 0;
    uint32_t local_4 = 0;
    if (*(int32_t*)(param_2 + 0x10) != 0) {
        do {
            void* uVar1 = *(void**)(*(intptr_t*)(param_2 + 8) + local_4 * 4);
            uVar3 = 0;
            if (*(int32_t*)(param_4 + 0x10) != 0) {
                do {
                    char cVar2 = FUN_00591460(param_1, uVar1, param_3, *(void**)(*(intptr_t*)(param_4 + 8) + uVar3 * 4), param_5);
                    if (cVar2 != '\0') {
                        *(uint32_t*)(param_2 + 0x1c) = local_4;
                        *(uint32_t*)(param_4 + 0x1c) = uVar3;
                        return (uint32_t)(((local_4 >> 8) & 0x00ffffff) << 8) | 1;
                    }
                    uVar3 = uVar3 + 1;
                } while (uVar3 < *(uint32_t*)(param_4 + 0x10));
            }
            uVar3 = local_4 + 1;
            local_4 = uVar3;
        } while (uVar3 < *(uint32_t*)(param_2 + 0x10));
    }
    return uVar3 & 0xffffff00;
}

extern char FUN_00591590(void*, void*, void*, void*, void*, void*, void*);
extern char FUN_005914e0(void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);
extern char FUN_005915d0(void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);
extern void FUN_005916b0(int);

// 0x5934e0 — observed shape
int FUN_005934e0(void* param_1, int param_2, void* param_3, void* param_4, void* param_5, void* param_6, void* param_7) {
    uint32_t uVar2 = 0;
    if (*(int32_t*)(param_2 + 0x10) != 0) {
        do {
            char cVar1 = FUN_00591590(param_1, *(void**)(*(intptr_t*)(param_2 + 8) + uVar2 * 4), param_3, param_4, param_5, param_6, param_7);
            if (cVar1 != '\0') {
                *(uint32_t*)(param_2 + 0x1c) = uVar2;
                return 1;
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint32_t*)(param_2 + 0x10));
    }
    return 0;
}

// 0x593550 — observed shape
int FUN_00593550(void* param_1, int param_2, void* param_3, void* param_4, void* param_5, void* param_6, void* param_7, void* param_8, void* param_9, void* param_10) {
    uint32_t uVar2 = 0;
    if (*(int32_t*)(param_2 + 0x10) != 0) {
        do {
            char cVar1 = FUN_005914e0(param_1, *(void**)(*(intptr_t*)(param_2 + 8) + uVar2 * 4), param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10);
            if (cVar1 != '\0') {
                *(uint32_t*)(param_2 + 0x1c) = uVar2;
                return 1;
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint32_t*)(param_2 + 0x10));
    }
    return 0;
}

// 0x5935d0 — observed shape
int FUN_005935d0(void* param_1, int param_2, void* param_3, int param_4, void* param_5, void* param_6, void* param_7, void* param_8, void* param_9, void* param_10) {
    uint32_t local_4 = 0;
    if (*(int32_t*)(param_2 + 0x10) != 0) {
        do {
            void* uVar1 = *(void**)(*(intptr_t*)(param_2 + 8) + local_4 * 4);
            uint32_t uVar3 = 0;
            if (*(int32_t*)(param_4 + 0x10) != 0) {
                do {
                    char cVar2 = FUN_005914e0(param_1, uVar1, param_3, *(void**)(*(intptr_t*)(param_4 + 8) + uVar3 * 4), param_5, param_6, param_7, param_8, param_9, param_10);
                    if (cVar2 != '\0') {
                        *(uint32_t*)(param_2 + 0x1c) = local_4;
                        *(uint32_t*)(param_4 + 0x1c) = uVar3;
                        return 1;
                    }
                    uVar3 = uVar3 + 1;
                } while (uVar3 < *(uint32_t*)(param_4 + 0x10));
            }
            local_4 = local_4 + 1;
        } while (local_4 < *(uint32_t*)(param_2 + 0x10));
    }
    return 0;
}

// 0x593680 — observed shape
int FUN_00593680(void* param_1, int param_2, void* param_3, void* param_4, void* param_5, void* param_6, void* param_7, void* param_8, void* param_9, void* param_10, void* param_11, void* param_12) {
    uint32_t uVar2 = 0;
    if (*(int32_t*)(param_2 + 0x10) != 0) {
        do {
            char cVar1 = FUN_005915d0(param_1, *(void**)(*(intptr_t*)(param_2 + 8) + uVar2 * 4), param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12);
            if (cVar1 != '\0') {
                *(uint32_t*)(param_2 + 0x1c) = uVar2;
                return 1;
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint32_t*)(param_2 + 0x10));
    }
    return 0;
}

// 0x593760 — observed shape
void FUN_00593760(void* self, int param_1) {
    int iVar2 = param_1;
    FUN_005916b0(param_1);
    intptr_t in_ECX = (intptr_t)self;
    int tmpParam = *(int32_t*)(in_ECX + 0x10);
    typedef void (*Vfunc)(void*, int);
    (*(Vfunc*)(*(intptr_t*)(*(intptr_t*)(iVar2 + 0x160)) + 0xc))(&tmpParam, 4);
    uint32_t uVar3 = 0;
    if (*(int32_t*)(in_ECX + 0x10) != 0) {
        do {
            int* piVar1 = *(int**)(*(intptr_t*)(in_ECX + 8) + uVar3 * 4);
            if (piVar1 != 0) {
                typedef void (*Vfunc2)(void*);
                (*(Vfunc2*)(*(intptr_t*)piVar1 + 4))( (void*)(intptr_t)iVar2);
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint32_t*)(in_ECX + 0x10));
    }
}

#include <cstdio>

extern void* thunk_FUN_00533c78(int);
extern void FUN_005606f0(uint32_t, char**);
extern char FUN_0059c600(void*);
extern float* FUN_0053ca60(void*, int);
extern void FUN_00593960(void*);
extern long double FUN_0059b000(void*, void*, void*, void*, void*);

// 0x593870 — observed shape
void FUN_00593870(void* self, char* param_1, int param_2) {
    char* pcVar4 = param_1;
    char* pcVar3 = param_1;
    do {
        char cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    char* tmp = (char*)thunk_FUN_00533c78((int)(pcVar3 + (0xc - (int)(param_1 + 1))));
    param_1 = tmp;
    sprintf(param_1, "%s = UNION_BV", pcVar4);
    int iVar2 = param_2;
    uint32_t uVar6 = *(uint32_t*)(param_2 + 0xc);
    if (*(uint32_t*)(param_2 + 8) <= uVar6) {
        FUN_006b34a0(*(int32_t*)(param_2 + 0x14) + (int)uVar6);
    }
    FUN_005606f0(uVar6, &param_1);
    uVar6 = 0;
    intptr_t in_ECX = (intptr_t)self;
    if (*(int32_t*)(in_ECX + 0x10) != 0) {
        do {
            char* pcVar4b = (char*)thunk_FUN_00533c78(0xd);
            sprintf(pcVar4b, "   child %i", uVar6);
            int* piVar5;
            if (uVar6 < *(uint32_t*)(in_ECX + 0x10)) {
                piVar5 = *(int**)(*(intptr_t*)(in_ECX + 8) + uVar6 * 4);
            } else {
                piVar5 = 0;
            }
            typedef void (*Vfunc)(void*, int);
            (*(Vfunc*)(*(intptr_t*)piVar5 + 0x2c))(pcVar4b, iVar2);
            uVar6 = uVar6 + 1;
        } while (uVar6 < *(uint32_t*)(in_ECX + 0x10));
    }
}

// 0x593920 — observed shape
int FUN_00593920(void* self, int* param_1) {
    typedef int (*Vfunc)(void*);
    int iVar2 = (*(Vfunc*)(*(intptr_t*)param_1 + 0xc))();
    if (iVar2 == 2) {
        intptr_t in_ECX = (intptr_t)self;
        char cVar1 = FUN_0059c600((void*)(in_ECX + 0x20));
        if (cVar1 != '\0') {
            return 1;
        }
    }
    return 0;
}

// 0x593960 — observed shape
void FUN_00593960(void* self) {
    intptr_t in_ECX = (intptr_t)self;
    float fVar1 = *(float*)(in_ECX + 0x1c) - *(float*)(in_ECX + 0x38);
    *(float*)(in_ECX + 0x20) = *(float*)(in_ECX + 4) - fVar1 * *(float*)(in_ECX + 0x10);
    *(float*)(in_ECX + 0x24) = *(float*)(in_ECX + 8) - fVar1 * *(float*)(in_ECX + 0x14);
    *(float*)(in_ECX + 0x28) = *(float*)(in_ECX + 0xc) - fVar1 * *(float*)(in_ECX + 0x18);
    float fVar3 = fVar1 * *(float*)(in_ECX + 0x10);
    float fVar2 = fVar1 * *(float*)(in_ECX + 0x14);
    fVar1 = fVar1 * *(float*)(in_ECX + 0x18);
    *(float*)(in_ECX + 0x2c) = fVar3 + fVar3;
    *(float*)(in_ECX + 0x30) = fVar2 + fVar2;
    *(float*)(in_ECX + 0x34) = fVar1 + fVar1;
}

// 0x593a60 — observed shape
void FUN_00593a60(void* self, int param_1, int param_2) {
    intptr_t in_ECX = (intptr_t)self;
    float local_18;
    float local_14;
    float local_10;
    unsigned char local_c[4];
    float local_8;
    float local_4;
    float* pfVar2 = (float*)FUN_0053ca60(&local_18, param_1 + 4);
    float fVar1 = *(float*)(param_2 + 0x30);
    local_8 = fVar1 * pfVar2[1];
    local_4 = fVar1 * pfVar2[2];
    local_18 = fVar1 * *pfVar2 + *(float*)(param_2 + 0x24);
    local_14 = local_8 + *(float*)(param_2 + 0x28);
    local_10 = local_4 + *(float*)(param_2 + 0x2c);
    *(float*)(in_ECX + 4) = local_18;
    *(float*)(in_ECX + 8) = local_14;
    *(float*)(in_ECX + 0xc) = local_10;
    unsigned int* puVar3 = (unsigned int*)FUN_0053ca60(local_c, param_1 + 0x10);
    *(unsigned int*)(in_ECX + 0x10) = *puVar3;
    *(unsigned int*)(in_ECX + 0x14) = puVar3[1];
    *(unsigned int*)(in_ECX + 0x18) = puVar3[2];
    *(float*)(in_ECX + 0x1c) = *(float*)(param_1 + 0x1c) * *(float*)(param_2 + 0x30);
    *(float*)(in_ECX + 0x38) = *(float*)(param_1 + 0x38) * *(float*)(param_2 + 0x30);
    FUN_00593960((void*)(intptr_t)in_ECX);
}

// 0x593b20 — observed shape
long double FUN_00593b20(float param_1, float* param_2) {
    float local_18;
    float local_14;
    float local_10;
    float local_c;
    float local_8;
    float local_4;
    local_18 = param_1 * param_2[6] + *param_2;
    local_14 = param_1 * param_2[7] + param_2[1];
    local_10 = param_1 * param_2[8] + param_2[2];
    local_c = param_2[3];
    local_8 = param_2[4];
    local_4 = param_2[5];
    long double fVar1 = FUN_0059b000(&local_18, param_2 + 9, param_2 + 0x13, param_2 + 0x14, param_2 + 0x15);
    return fVar1 - (long double)param_2[0x12];
}

#include <cmath>

struct VtablePtr { void* vtable; };
extern void* PTR_LAB_006c5198;
extern float DAT_00727430, DAT_00727434, DAT_00727438;
extern float DAT_007177c4, DAT_007177c8, DAT_007177cc;
extern long double FUN_0059c730(void*, void*, void*, void*);
extern long double FUN_0059ce10(void*, void*, void*, void*, void*);
extern long double FUN_0059b000(void*, void*, void*, void*, void*);
extern long double FUN_0059e700(void*, void*, void*, void*, void*, void*);
extern long double FUN_0059c640(void*, void*, void*);
extern char FUN_00428470(void*);
extern void FUN_0058fca0(unsigned int, void*);
extern unsigned int* FUN_00599de0(void*, void*);
extern void FUN_00491640();
extern unsigned int FUN_00594060(float, int, float*, int, float*, float*, unsigned int*, unsigned int, float*, float*);

// 0x593bb0 — observed shape
void FUN_00593bb0(void* self, unsigned int param_1, unsigned int param_2, unsigned int param_3, unsigned int param_4, unsigned int param_5, unsigned int param_6, unsigned int param_7, unsigned int param_8) {
    unsigned int* in_ECX = (unsigned int*)self;
    in_ECX[1] = param_3;
    in_ECX[2] = param_4;
    in_ECX[3] = param_5;
    in_ECX[4] = param_6;
    in_ECX[5] = param_7;
    in_ECX[6] = param_8;
    in_ECX[7] = param_2;
    *in_ECX = (unsigned int)(intptr_t)&PTR_LAB_006c5198;
    in_ECX[0xe] = param_1;
    FUN_00593960((void*)(intptr_t)in_ECX);
}

// 0x593d50 — observed shape
int FUN_00593d50(float param_1, int param_2, float* param_3, int param_4, float* param_5) {
    int iVar2 = param_4;
    int iVar1 = param_2;
    long double fVar3;
    if (((*param_5 - *param_3 == DAT_00727430) && (param_5[1] - param_3[1] == DAT_00727434)) &&
        (param_5[2] - param_3[2] == DAT_00727438)) {
        fVar3 = FUN_0059c730((void*)(param_2 + 0x20), (void*)(param_4 + 0x20), &param_4, &param_2);
    } else {
        float local_c = (*param_5 - *param_3) * param_1;
        unsigned int local_24 = *(unsigned int*)(param_4 + 0x20);
        unsigned int local_20 = *(unsigned int*)(param_4 + 0x24);
        float local_8 = (param_5[1] - param_3[1]) * param_1;
        unsigned int local_1c = *(unsigned int*)(param_4 + 0x28);
        unsigned int local_18 = *(unsigned int*)(param_4 + 0x2c);
        float local_4 = (param_5[2] - param_3[2]) * param_1;
        unsigned int local_14 = *(unsigned int*)(param_4 + 0x30);
        unsigned int local_10 = *(unsigned int*)(param_4 + 0x34);
        (void)local_c; (void)local_8; (void)local_4;
        fVar3 = FUN_0059ce10((void*)(param_2 + 0x20), &local_24, &param_4, &param_5, &param_2);
    }
    long double fVar4 = (long double)*(float*)(iVar1 + 0x38) + (long double)*(float*)(iVar2 + 0x38);
    fVar4 = fVar4 * fVar4;
    if ((std::isnan((double)fVar3) || std::isnan((double)fVar4)) || (fVar3 < fVar4) == (fVar3 == fVar4)) {
        return 0;
    }
    return 1;
}

// 0x593e90 — observed shape
int FUN_00593e90(float param_1, int param_2, float* param_3, float* param_4, float* param_5, float* param_6, float* param_7) {
    int iVar1 = param_2;
    float local_48 = *param_4;
    float local_44 = param_4[1];
    float local_40 = param_4[2];
    float local_3c = *param_5 - *param_4;
    float local_38 = param_5[1] - param_4[1];
    float local_34 = param_5[2] - param_4[2];
    float local_30 = *param_6 - *param_4;
    float local_2c = param_6[1] - param_4[1];
    float local_28 = param_6[2] - param_4[2];
    long double fVar2;
    if (((*param_3 - *param_7 == DAT_00727430) && (param_3[1] - param_7[1] == DAT_00727434)) &&
        (param_3[2] - param_7[2] == DAT_00727438)) {
        fVar2 = FUN_0059b000((void*)(param_2 + 0x20), &local_48, &param_7, &param_3, &param_2);
    } else {
        float local_c = (*param_3 - *param_7) * param_1;
        unsigned int local_24 = *(unsigned int*)(param_2 + 0x20);
        unsigned int local_20 = *(unsigned int*)(param_2 + 0x24);
        unsigned int local_1c = *(unsigned int*)(param_2 + 0x28);
        float local_8 = (param_3[1] - param_7[1]) * param_1;
        unsigned int local_18 = *(unsigned int*)(param_2 + 0x2c);
        unsigned int local_14 = *(unsigned int*)(param_2 + 0x30);
        float local_4 = (param_3[2] - param_7[2]) * param_1;
        unsigned int local_10 = *(unsigned int*)(param_2 + 0x34);
        (void)local_c; (void)local_8; (void)local_4;
        fVar2 = FUN_0059e700(&local_48, &local_24, &param_3, &param_2, &param_4, &param_7);
    }
    long double fVar3 = (long double)*(float*)(iVar1 + 0x38) * (long double)*(float*)(iVar1 + 0x38);
    if ((std::isnan((double)fVar2) || std::isnan((double)fVar3)) || (fVar2 < fVar3) == (fVar2 == fVar3)) {
        return 0;
    }
    return 1;
}

// 0x594060 — observed shape
unsigned int FUN_00594060(float param_1, int param_2, float* param_3, int param_4, float* param_5, float* param_6, unsigned int* param_7, unsigned int param_8, float* param_9, float* param_10) {
    float* pfVar5 = param_5;
    float* pfVar4 = param_3;
    int iVar3 = param_2;
    float local_44 = *param_5 - *param_3;
    float local_40 = param_5[1] - param_3[1];
    float* pfVar1 = (float*)(param_2 + 0x20);
    float local_3c = param_5[2] - param_3[2];
    float fVar2 = *(float*)(param_4 + 0x10) + *(float*)(param_2 + 0x38);
    float* param_5b = (float*)(fVar2 * fVar2);
    long double fVar9 = FUN_0059c640((void*)(param_4 + 4), pfVar1, &param_2);
    if (fVar9 < (long double)(float)(intptr_t)param_5b) {
        FUN_0058fca0(0x3f800000, &DAT_00727430);
        unsigned int local_1c = *(unsigned int*)(iVar3 + 0x38);
        float local_38[8] = {};
        unsigned int* puVar7 = FUN_00599de0(local_38, (void*)(intptr_t)param_2);
        float local_28 = (float)*puVar7;
        float local_24 = (float)puVar7[1];
        float local_20 = (float)puVar7[2];
        unsigned char local_2c[4] = {};
        unsigned int uVar8 = FUN_005914e0(param_1, local_2c, pfVar4, param_4, pfVar5, param_6, param_7, param_8, param_9, param_10);
        return uVar8;
    }
    char cVar6 = FUN_00428470(&DAT_00727430);
    if (cVar6 != '\0') {
        float local_50 = local_44 * param_1;
        unsigned int local_18 = *(unsigned int*)(param_4 + 4);
        unsigned int local_14 = *(unsigned int*)(param_4 + 8);
        unsigned int local_10 = *(unsigned int*)(param_4 + 0xc);
        float local_4c = local_40 * param_1;
        float local_48 = local_3c * param_1;
        float local_c = local_50;
        float local_8 = local_4c;
        float local_4 = local_48;
        long double fVar10 = FUN_0059c730(&local_18, pfVar1, &param_2, &param_3);
        if ((!std::isnan((double)fVar10) && !std::isnan((double)(float)(intptr_t)param_5b)) && (fVar10 < (long double)(float)(intptr_t)param_5b) != (fVar10 == (long double)(float)(intptr_t)param_5b)) {
            FUN_0058fca0(0x3f800000, &DAT_00727430);
            unsigned int local_1c = *(unsigned int*)(iVar3 + 0x38);
            float local_28 = *pfVar1;
            float local_24 = *(float*)(iVar3 + 0x24);
            float local_20 = *(float*)(iVar3 + 0x28);
            unsigned char local_2c[4] = {};
            unsigned int local_5c = 0, local_58 = 0, local_54 = 0;
            float local_38[8] = {};
            cVar6 = FUN_005914e0(param_1, local_2c, pfVar4, param_4, pfVar5, param_6, param_7, param_8, param_9, param_10);
            if (cVar6 == '\0') {
                *param_6 = param_1 + param_1;
            }
            float local_38b = *(float*)(iVar3 + 0x2c) + *pfVar1;
            float local_34 = *(float*)(iVar3 + 0x24) + *(float*)(iVar3 + 0x30);
            float local_30 = *(float*)(iVar3 + 0x28) + *(float*)(iVar3 + 0x34);
            local_28 = local_38b;
            local_24 = local_34;
            local_20 = local_30;
            cVar6 = FUN_005914e0(param_1, local_2c, pfVar4, param_4, pfVar5, &param_5, &local_5c, param_8, &local_50, &local_44);
            pfVar1 = param_10;
            if (cVar6 != '\0') {
                if ((float)(intptr_t)param_5 < *param_6) {
                    *param_6 = (float)(intptr_t)param_5;
                    *param_7 = local_5c;
                    param_7[1] = local_58;
                    param_7[2] = local_54;
                    *param_9 = local_50;
                    param_9[1] = local_4c;
                    param_9[2] = local_48;
                    *param_10 = local_44;
                    param_10[1] = local_40;
                    param_10[2] = local_3c;
                }
            }
            if ((float)(intptr_t)param_3 != 0.0f) {
                if ((float)(intptr_t)param_3 != 1.0f) {
                    unsigned int* puVar7 = FUN_00599de0(local_38, (void*)(intptr_t)param_3);
                    local_28 = (float)*puVar7;
                    local_24 = (float)puVar7[1];
                    local_20 = (float)puVar7[2];
                    cVar6 = FUN_005914e0(param_1, local_2c, pfVar4, param_4, pfVar5, &param_5, &local_5c, param_8, &local_50, &local_44);
                    if (cVar6 != '\0') {
                        if ((float)(intptr_t)param_5 < *param_6) {
                            *param_6 = (float)(intptr_t)param_5;
                            *param_7 = local_5c;
                            param_7[1] = local_58;
                            param_7[2] = local_54;
                            *param_9 = local_50;
                            param_9[1] = local_4c;
                            param_9[2] = local_48;
                            *pfVar1 = local_44;
                            pfVar1[1] = local_40;
                            pfVar1[2] = local_3c;
                        }
                    }
                }
            }
            return 1;
        }
    }
    return 0;
}

// 0x594480 — observed shape
unsigned int FUN_00594480(float param_1, int param_2, float* param_3, int param_4, float* param_5, float* param_6, float* param_7, unsigned int param_8, float* param_9, float* param_10) {
    float* pfVar7 = param_5;
    int iVar6 = param_4;
    float* pfVar12 = param_3;
    int iVar5 = param_2;
    float fVar1 = *param_3;
    float local_4c = param_5[1] - param_3[1];
    float local_48 = param_5[2] - param_3[2];
    float fVar2 = *(float*)(param_4 + 0x38) + *(float*)(param_2 + 0x38);
    float* param_3b = (float*)(fVar2 * fVar2);
    unsigned int uVar11 = 0;
    if (((*param_5 - fVar1 == DAT_00727430) && (local_4c == DAT_00727434)) &&
        (local_48 == DAT_00727438)) {
        param_2 = param_2 + 0x20;
        long double fVar14 = FUN_0059c730((void*)(intptr_t)param_2, (void*)(param_4 + 0x20), &param_5, &param_4);
        float* pfVar8 = param_6;
        long double fVar4 = (long double)(float)(intptr_t)param_3b;
        uVar11 = (unsigned int)(((fVar14 < fVar4) ? 1 : 0) << 8) | (((std::isnan((double)fVar14) || std::isnan((double)fVar4)) ? 1 : 0) << 10) | (((fVar14 == fVar4) ? 1 : 0) << 14);
        if ((!std::isnan((double)fVar14) && !std::isnan((double)fVar4)) && (fVar14 < fVar4) != (fVar14 == fVar4)) {
            *param_6 = 0.0f;
            float local_50 = *pfVar12 * 0.0f;
            local_4c = pfVar12[1] * 0.0f;
            local_48 = pfVar12[2] * 0.0f;
            unsigned char local_30[8] = {};
            pfVar12 = (float*)FUN_00599de0(local_30, param_5);
            local_50 = local_50 + *pfVar12;
            local_4c = local_4c + pfVar12[1];
            local_48 = local_48 + pfVar12[2];
            fVar1 = *pfVar8;
            fVar2 = *pfVar7;
            float fVar3 = pfVar7[1];
            float fVar13 = pfVar7[2];
            pfVar12 = (float*)FUN_00599de0(local_30, (void*)(intptr_t)param_4);
            fVar2 = fVar1 * fVar2 + *pfVar12;
            fVar3 = fVar1 * fVar3 + pfVar12[1];
            fVar1 = fVar1 * fVar13 + pfVar12[2];
            float local_28 = fVar1 + local_48;
            float local_44 = (fVar2 + local_50) * 0.5f;
            *param_7 = local_44;
            float local_40 = (fVar3 + local_4c) * 0.5f;
            float local_3c = local_28 * 0.5f;
            param_7[1] = local_40;
            param_7[2] = local_3c;
            fVar13 = (float)(unsigned int)(((unsigned int)(intptr_t)param_7 >> 8) & 0x00ffffff) | (unsigned char)param_8;
            if ((unsigned char)param_8 != '\0') {
                char cVar9 = FUN_00428470(&local_50);
                float* pfVar12b = param_9;
                if (cVar9 == '\0') {
                    *param_9 = DAT_007177c4;
                    param_9[1] = DAT_007177c8;
                    param_9[2] = DAT_007177cc;
                } else {
                    local_44 = fVar2 - local_50;
                    *param_9 = local_44;
                    local_40 = fVar3 - local_4c;
                    param_9[1] = local_40;
                    local_3c = fVar1 - local_48;
                    param_9[2] = local_3c;
                    FUN_00491640();
                }
                fVar13 = -pfVar12b[1];
                fVar1 = pfVar12b[2];
                *param_10 = -*pfVar12b;
                param_10[1] = fVar13;
                param_10[2] = -fVar1;
            }
            return (unsigned int)(((unsigned int)(intptr_t)fVar13 >> 8) & 0x00ffffff) | 1;
        }
    } else {
        float local_c = (*param_5 - fVar1) * param_1;
        unsigned int local_24 = *(unsigned int*)(param_4 + 0x20);
        unsigned int local_20 = *(unsigned int*)(param_4 + 0x24);
        unsigned int local_1c = *(unsigned int*)(param_4 + 0x28);
        float local_8 = local_4c * param_1;
        unsigned int local_18 = *(unsigned int*)(param_4 + 0x2c);
        unsigned int local_14 = *(unsigned int*)(param_4 + 0x30);
        unsigned int local_10 = *(unsigned int*)(param_4 + 0x34);
        float local_4 = local_48 * param_1;
        long double fVar14 = FUN_0059ce10((void*)(param_2 + 0x20), &local_24, &param_5, &param_4, &param_2);
        long double fVar4 = (long double)(float)(intptr_t)param_3b;
        uVar11 = (unsigned int)(((fVar14 < fVar4) ? 1 : 0) << 8) | (((std::isnan((double)fVar14) || std::isnan((double)fVar4)) ? 1 : 0) << 10) | (((fVar14 == fVar4) ? 1 : 0) << 14);
        if ((!std::isnan((double)fVar14) && !std::isnan((double)fVar4)) && (fVar14 < fVar4) != (fVar14 == fVar4)) {
            FUN_0058fca0(0x3f800000, &DAT_00727430);
            unsigned char local_30[8] = {};
            unsigned int* puVar10 = FUN_00599de0(local_30, param_5);
            float local_40 = (float)*puVar10;
            float local_3c = (float)puVar10[1];
            unsigned int local_34 = *(unsigned int*)(iVar5 + 0x38);
            float local_38 = puVar10[2];
            float local_44 = 0;
            uVar11 = FUN_00594060(param_1, iVar6, pfVar7, (int)(intptr_t)&local_44, pfVar12, param_6, param_7, param_8, param_10, param_9);
            return uVar11;
        }
    }
    return uVar11;
}
