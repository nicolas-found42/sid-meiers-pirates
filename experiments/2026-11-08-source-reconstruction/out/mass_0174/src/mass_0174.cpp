#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void* FUN_0053ca60(void* out, uint32_t param);
extern void* FUN_0053c8d0(void* out, uint32_t param);
extern void FUN_00573d80(void* a, void* b);
extern void operator_delete(void* ptr);
extern void* FUN_0053ba20(void** p1, void* p2);
extern void FUN_005bfa50(int v);
extern void FUN_005709b0(void);
extern void FUN_0056f540(void);
extern void FUN_005e1490(void);
extern void* thunk_FUN_00533c78(size_t n);
extern void FUN_00552c80(void);
extern void FUN_00552d20(void);
extern void FUN_00552aa0(uint32_t a, uint32_t b);
extern void FUN_00552e30(uint32_t p);
extern uint32_t FUN_0056f950(uint32_t p);
extern void FUN_005bbe20(int p);
extern uint32_t FUN_005b62a0(void** p);
extern void FUN_00545310(uint32_t a, uint32_t b);
extern void FUN_0053ba20();
extern void* FUN_00553060(uint32_t p);
extern uint32_t FUN_00545600(void);
extern uint32_t FUN_00552bc0(int p);
extern void FUN_0055f300(int n);
extern void FUN_00545cc0(void);
extern void FUN_00552f70(void);
extern void FUN_00552b70(int* p);
extern void FUN_005bd960(void* ec, void** out);
extern int FUN_006b34a0(void* p);
extern void operator_delete__(void* p);

// 0x574040 — observed shape
void FUN_00574040(void* self, uint32_t param_1, uint32_t param_2)
{
    uint8_t local_30[12];
    uint8_t local_24[36];
    float* pfVar1 = (float*)FUN_0053ca60(local_30, param_2);
    float local_3c = *(float*)((uint8_t*)self + 0x98) + pfVar1[0];
    float local_38 = pfVar1[1] + *(float*)((uint8_t*)self + 0x9c);
    float local_34 = pfVar1[2] + *(float*)((uint8_t*)self + 0xa0);
    void* uVar2 = FUN_0053c8d0(local_24, param_1);
    FUN_00573d80(uVar2, &local_3c);
}

// 0x574170 — observed shape
void FUN_00574170(void* self)
{
    uint32_t* vec = (uint32_t*)self;
    vec[0] = 0x006c42d0; // &PTR_FUN_006c42d0
    int iVar2 = (int)vec[1];
    if (iVar2 != 0) {
        int iVar4 = *(int*)((uint8_t*)iVar2 - 4);
        int* iVar5 = (int*)(iVar2 + iVar4 * 4);
        if (-1 < iVar4 - 1) {
            do {
                uint32_t* puVar3 = *(uint32_t**)((uint8_t*)iVar5 - 4);
                iVar5 = (int*)((uint8_t*)iVar5 - 4);
                if (puVar3 != nullptr) {
                    int* piVar1 = (int*)(puVar3 + 1);
                    *piVar1 += -1;
                    if (*piVar1 == 0) {
                        ((void(*)(int))(puVar3[0]))(1);
                    }
                }
                iVar4 -= 1;
            } while (iVar4 != 0);
        }
        operator_delete__((void*)(iVar2 - 4));
    }
}

// 0x5741c0 — observed shape
void FUN_005741c0(void* self, uint8_t param_1)
{
    FUN_00574170(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5741f0 — observed shape
int* FUN_005741f0(void* self, int* param_1, uint32_t* param_2)
{
    uint8_t* s = (uint8_t*)self;
    uint32_t* puVar6 = param_2;
    uint32_t* puVar7 = nullptr;
    if (*(int*)(s + 0x50) != 0) {
        do {
            uint32_t* puVar1 = *(uint32_t**)(*(int*)(s + 0x48) + (int)(intptr_t)puVar7 * 4);
            if (puVar1 != nullptr) {
                puVar1[1] += 1;
            }
            if (puVar1 == puVar6) {
                uint32_t* tmp = param_2;
                FUN_0053ba20((void**)&param_2, puVar7);
                if (param_2 != nullptr) {
                    int* piVar4 = (int*)(param_2 + 1);
                    *piVar4 += -1;
                    if (*piVar4 == 0) {
                        ((void(*)(int))(param_2[0]))(1);
                    }
                }
                uint32_t uVar3 = 0;
                int* piVar4 = nullptr;
                if (*(uint32_t*)(s + 0x60) != 0) {
                    piVar4 = *(int**)(s + 100);
                    // advance loop
                    while (true) {
                        while (uVar3 + 1 < *(uint32_t*)(s + 0x60)) {
                            uVar3 += 1;
                            piVar4 += 1;
                            if (*piVar4 != 0) {
                                piVar4 = (int*)(*(int**)(s + 100))[uVar3];
                                goto joined_r0x00574291;
                            }
                        }
                        piVar4 = nullptr;
                        goto LAB_0057428d;
                    }
                }
LAB_0057428d:
                piVar4 = nullptr;
joined_r0x00574291:
                {
                    int iVar2 = 0;
                    while (true) {
                        if (piVar4 == nullptr) goto LAB_005742f1;
                        param_2 = (uint32_t*)piVar4[2];
                        iVar2 = piVar4[1];
                        piVar4 = (int*)*piVar4;
                        if (piVar4 == nullptr) {
                            int iVar5 = ((int(*)(int))(*(int*)(s + 0x5c) + 4))(iVar2);
                            uint32_t uVar3b = (uint32_t)(iVar5 + 1);
                            if (uVar3b < *(uint32_t*)(s + 0x60)) {
                                uint32_t* puVar6b = (uint32_t*)(*(int*)(s + 100) + uVar3b * 4);
                                do {
                                    piVar4 = (int*)*puVar6b;
                                    if (piVar4 != nullptr) goto LAB_005742d0;
                                    uVar3b += 1;
                                    puVar6b += 1;
                                } while (uVar3b < *(uint32_t*)(s + 0x60));
                            }
                            piVar4 = nullptr;
                        }
LAB_005742d0:
                        if (param_2 == puVar7) break;
                    }
                    FUN_005bfa50(iVar2);
                }
LAB_005742f1:
                FUN_005709b0();
                {
                    uint32_t* puVar1b = puVar1;
                    puVar1b[0x17] = 0;
                    *param_1 = (int)(intptr_t)puVar1b;
                    int iVar2b = puVar1b[1];
                    puVar1b[1] = iVar2b + 1;
                    puVar1b[1] = iVar2b;
                    if (iVar2b == 0) {
                        ((void(*)(int))(puVar1b[0]))(1);
                    }
                }
                return param_1;
            }
            if (puVar1 != nullptr) {
                int* piVar4 = (int*)(puVar1 + 1);
                *piVar4 += -1;
                if (*piVar4 == 0) {
                    ((void(*)(int))(puVar1[0]))(1);
                }
            }
            puVar7 = (uint32_t*)((int)(intptr_t)puVar7 + 1);
        } while (puVar7 < *(uint32_t**)(s + 0x50));
    }
    *param_1 = 0;
    return param_1;
}

// 0x574330 — observed shape
void FUN_00574330(void* self)
{
    uint8_t* s = (uint8_t*)self;
    uint32_t uVar2 = 0;
    if (*(int*)(s + 0x50) != 0) {
        do {
            int iVar1 = *(int*)(*(int*)(s + 0x48) + uVar2 * 4);
            if (iVar1 != 0) {
                FUN_005709b0();
                *(uint32_t*)(iVar1 + 0x5c) = 0;
            }
            uVar2 += 1;
        } while (uVar2 < *(uint32_t*)(s + 0x50));
    }
    FUN_0056f540();
    FUN_005e1490();
}

// 0x574380 — observed shape
void FUN_00574380(void* self)
{
    uint32_t* in_ECX = (uint32_t*)self;
    FUN_00552c80();
    in_ECX[0] = 0x006c42d8; // &PTR_FUN_006c42d8
    in_ECX[0x11] = 0x006c42d0; // &PTR_FUN_006c42d0
    in_ECX[0x13] = 0;
    in_ECX[0x16] = 1;
    in_ECX[0x14] = 0;
    in_ECX[0x15] = 0;
    in_ECX[0x12] = 0;
    in_ECX[0x17] = 0x006c427c; // &PTR_FUN_006c427c
    in_ECX[0x18] = 0x25;
    in_ECX[0x1a] = 0;
    uint32_t* puVar1 = (uint32_t*)thunk_FUN_00533c78(0x94);
    in_ECX[0x19] = (uint32_t)(intptr_t)puVar1;
    for (uint32_t uVar2 = in_ECX[0x18] & 0x3fffffff; uVar2 != 0; uVar2 -= 1) {
        *puVar1 = 0;
        puVar1 += 1;
    }
    for (int iVar3 = 0; iVar3 != 0; iVar3 -= 1) {
        *(uint8_t*)puVar1 = 0;
        puVar1 = (uint32_t*)((int)(intptr_t)puVar1 + 1);
    }
    *(uint8_t*)((uint8_t*)in_ECX + 0x1b * 4) = 1;
    in_ECX[0x17] = 0x006c42b4; // &PTR_FUN_006c42b4
    *(uint8_t*)((uint8_t*)in_ECX + 0x1c * 4) = 0;
    extern uint32_t DAT_007179b0[];
    uint32_t* puVar4 = in_ECX + 0x1d;
    uint32_t* src = DAT_007179b0;
    for (int iVar3 = 9; iVar3 != 0; iVar3 -= 1) {
        *puVar4 = *src;
        src += 1;
        puVar4 += 1;
    }
    extern uint32_t DAT_00727430;
    extern uint32_t DAT_00727434;
    extern uint32_t DAT_00727438;
    in_ECX[0x26] = DAT_00727430;
    in_ECX[0x27] = DAT_00727434;
    in_ECX[0x28] = DAT_00727438;
}

// 0x574430 — observed shape
void FUN_00574430(void* self, uint8_t param_1)
{
    uint32_t* in_ECX = (uint32_t*)self;
    *in_ECX = 0x006c42d8; // &PTR_FUN_006c42d8
    FUN_0056f540();
    FUN_00573c00();
    FUN_00574170(self);
    FUN_00552d20();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x574480 — observed shape
void FUN_00574480(void* self, uint32_t param_1)
{
    uint32_t* in_ECX = (uint32_t*)self;
    FUN_00552c80();
    in_ECX[0] = 0x006c42d8; // &PTR_FUN_006c42d8
    in_ECX[0x11] = 0x006c42d0; // &PTR_FUN_006c42d0
    in_ECX[0x13] = 0;
    in_ECX[0x16] = 1;
    in_ECX[0x14] = 0;
    in_ECX[0x15] = 0;
    in_ECX[0x12] = 0;
    in_ECX[0x17] = 0x006c427c; // &PTR_FUN_006c427c
    in_ECX[0x18] = 0x25;
    in_ECX[0x1a] = 0;
    uint32_t* puVar1 = (uint32_t*)thunk_FUN_00533c78(0x94);
    in_ECX[0x19] = (uint32_t)(intptr_t)puVar1;
    for (uint32_t uVar2 = in_ECX[0x18] & 0x3fffffff; uVar2 != 0; uVar2 -= 1) {
        *puVar1 = 0;
        puVar1 += 1;
    }
    for (int iVar3 = 0; iVar3 != 0; iVar3 -= 1) {
        *(uint8_t*)puVar1 = 0;
        puVar1 = (uint32_t*)((int)(intptr_t)puVar1 + 1);
    }
    *(uint8_t*)((uint8_t*)in_ECX + 0x1b * 4) = 1;
    in_ECX[0x17] = 0x006c42b4; // &PTR_FUN_006c42b4
    *(uint8_t*)((uint8_t*)in_ECX + 0x1c * 4) = 0;
    extern uint32_t DAT_007179b0[];
    uint32_t* puVar4 = in_ECX + 0x1d;
    uint32_t* src = DAT_007179b0;
    for (int iVar3 = 9; iVar3 != 0; iVar3 -= 1) {
        *puVar4 = *src;
        src += 1;
        puVar4 += 1;
    }
    extern uint32_t DAT_00727430;
    extern uint32_t DAT_00727434;
    extern uint32_t DAT_00727438;
    in_ECX[0x26] = DAT_00727430;
    in_ECX[0x27] = DAT_00727434;
    in_ECX[0x28] = DAT_00727438;
    FUN_00552e30(param_1);
}

// 0x574540 — observed shape
uint32_t FUN_00574540(void* self, uint32_t* param_1, int param_2, uint32_t* param_3)
{
    int in_ECX = (int)(intptr_t)self;
    if ((in_ECX != 0) && (param_1[0x17] != 0)) {
        return 0;
    }
    param_1[0x17] = in_ECX;
    if (((char)(intptr_t)param_3 != '\0') &&
        (FUN_0056f950(*(uint32_t*)(in_ECX + 0x34)) == 0)) {
        param_1[0x17] = 0;
        return 0;
    }
    if (param_2 != 0) {
        FUN_005bbe20(param_2);
    }
    param_1[1] += 1;
    uint32_t uVar2 = param_1[3];
    void* p = param_1;
    uint32_t uVar4 = FUN_005b62a0(&p);
    FUN_00545310(uVar2, uVar4);
    int* piVar1 = (int*)(param_1 + 1);
    *piVar1 += -1;
    if (*piVar1 == 0) {
        ((void(*)(int))(param_1[0]))(1);
    }
    return 1;
}

// 0x5745d0 — observed shape
void FUN_005745d0(void* self, uint32_t param_1, uint32_t param_2)
{
    uint32_t* in_ECX = (uint32_t*)self;
    int iVar3 = (int)param_1;
    uint32_t* puStack_4 = in_ECX;
    FUN_00552aa0(param_1, param_2);
    *(uint8_t*)(param_1 + 0x70) = *(uint8_t*)((uint8_t*)in_ECX + 0x1c * 4);
    {
        uint32_t* puVar4 = in_ECX + 0x1d;
        uint32_t* puVar7 = (uint32_t*)(param_1 + 0x74);
        for (int iVar6 = 9; iVar6 != 0; iVar6 -= 1) {
            *puVar7 = *puVar4;
            puVar4 += 1;
            puVar7 += 1;
        }
    }
    *(uint32_t*)(param_1 + 0x98) = in_ECX[0x26];
    *(uint32_t*)(param_1 + 0x9c) = in_ECX[0x27];
    *(uint32_t*)(param_1 + 0xa0) = in_ECX[0x28];
    uint32_t idx = 0;
    if (in_ECX[0x14] != 0) {
        do {
            int* piVar1 = *(int**)(in_ECX[0x12] + idx * 4);
            if (piVar1 != nullptr) {
                uint32_t* puVar4 = (uint32_t*)((void(*)(uint32_t))(*(uint32_t*)*piVar1 + 8))(param_2);
                if (puVar4[0x17] == 0) {
                    puVar4[0x17] = iVar3;
                    puVar4[1] += 1;
                    uint32_t uVar2 = puVar4[3];
                    puStack_4 = puVar4;
                    uint32_t uVar5 = FUN_005b62a0((void**)&puStack_4);
                    FUN_00545310(uVar2, uVar5);
                    int* piVar1b = (int*)(puVar4 + 1);
                    *piVar1b += -1;
                    if (*piVar1b == 0) {
                        ((void(*)(int))(puVar4[0]))(1);
                    }
                }
            }
            idx += 1;
        } while (idx < in_ECX[0x14]);
    }
}

// 0x574790 — observed shape
void FUN_00574790(void* self, uint8_t param_1)
{
    uint32_t* in_ECX = (uint32_t*)self;
    *in_ECX = 0x006c4344; // &PTR_FUN_006c4344
    operator_delete__((void*)(uint32_t)in_ECX[1]);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5747c0 — observed shape
void FUN_005747c0(void* self, uint8_t param_1)
{
    uint32_t* in_ECX = (uint32_t*)self;
    *in_ECX = 0x006c4348; // &PTR_FUN_006c4348
    operator_delete__((void*)(uint32_t)in_ECX[1]);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x574860 — observed shape
void FUN_00574860(void* self, uint32_t param_1)
{
    uint8_t* s = (uint8_t*)self;
    FUN_00553060(param_1);
    uint32_t uVar7 = 0;
    if (*(int*)(s + 0x58) != 0) {
        do {
            int* piVar2 = *(int**)(*(int*)(s + 0x50) + uVar7 * 4);
            if (piVar2 != nullptr && piVar2[2] != 0) {
                uint32_t uVar8 = 0;
                do {
                    uint32_t uVar5 = FUN_00545600();
                    if (uVar8 < (uint32_t)piVar2[2]) {
                        *(uint32_t*)(*piVar2 + uVar8 * 4) = uVar5;
                    }
                    uVar8 += 1;
                } while (uVar8 < (uint32_t)piVar2[2]);
            }
            uVar7 += 1;
        } while (uVar7 < *(uint32_t*)(s + 0x58));
    }
    uint32_t local_4 = 0;
    if (*(int*)(s + 0x70) != 0) {
        do {
            int* piVar2 = *(int**)(*(int*)(s + 0x68) + local_4 * 4);
            if (piVar2 != nullptr && piVar2[2] != 0) {
                uint32_t uVar7b = 0;
                do {
                    uint32_t* puVar3 = *(uint32_t**)(*piVar2 + uVar7b * 4);
                    uint32_t uVar5 = FUN_00545600();
                    *puVar3 = uVar5;
                    uint32_t* puVar6 = (uint32_t*)FUN_00545600();
                    uint32_t* puVar4 = (uint32_t*)puVar3[1];
                    if (puVar4 != puVar6) {
                        if (puVar4 != nullptr) {
                            int* piVar1 = (int*)(puVar4 + 1);
                            *piVar1 += -1;
                            if (*piVar1 == 0) {
                                ((void(*)(int))(puVar4[0]))(1);
                            }
                        }
                        puVar3[1] = (uint32_t)(intptr_t)puVar6;
                        if (puVar6 != nullptr) {
                            puVar6[1] += 1;
                        }
                    }
                    uVar7b += 1;
                } while (uVar7b < (uint32_t)piVar2[2]);
            }
            local_4 += 1;
        } while (local_4 < *(uint32_t*)(s + 0x70));
    }
    uVar7 = 0;
    if (*(int*)(s + 0x84) != 0) {
        do {
            uint32_t uVar5 = FUN_00545600();
            if (uVar7 < *(uint32_t*)(s + 0x84)) {
                *(uint32_t*)(*(int*)(s + 0x7c) + uVar7 * 4) = uVar5;
            }
            uVar7 += 1;
        } while (uVar7 < *(uint32_t*)(s + 0x84));
    }
}

// 0x574970 — observed shape
// NEEDS_MANUAL: non_contiguous body; elided Ghidra ranges preserved at high level, receiver and compare loops translated from visible ranges
uint32_t FUN_00574970(void* self, int param_1)
{
    uint8_t* s = (uint8_t*)self;
    uint8_t* p = (uint8_t*)param_1;
    uint32_t uVar5 = FUN_00552bc0(param_1);
    if ((((((char)uVar5 == '\0') ||
        (uVar5 = *(uint32_t*)(s + 0x44), uVar5 != *(uint32_t*)(p + 0x44))) ||
       (*(int*)(s + 0x48) != *(int*)(p + 0x48))) ||
      ((*(int*)(s + 0x58) != *(int*)(p + 0x58) ||
       (*(int*)(s + 0x70) != *(int*)(p + 0x70))))) ||
     (uVar5 = *(uint32_t*)(s + 0x84), uVar5 != *(uint32_t*)(p + 0x84))) {
        return uVar5 & 0xffffff00;
    }
    int* local_c = nullptr;
    int* piVar6 = nullptr;
    if (*(int*)(s + 0x58) != 0) {
        do {
            int* piVar1 = *(int**)(*(int*)(s + 0x50) + (int)(intptr_t)local_c * 4);
            int* piVar2 = *(int**)(*(int*)(p + 0x50) + (int)(intptr_t)local_c * 4);
            piVar6 = local_c;
            if (piVar1 == nullptr) {
                if (piVar2 != nullptr) goto LAB_00574a70;
            } else {
                if (piVar2 == nullptr || piVar1[2] != piVar2[2]) goto LAB_00574a70;
                uint32_t u = 0;
                if (piVar1[2] != 0) {
                    do {
                        piVar6 = (int*)((int(*)(uint32_t))(*(uint32_t**)(**(uint32_t**)(*piVar1 + u * 4) + 0x1c))(*(uint32_t*)(*piVar2 + u * 4)));
                        if ((char)(int)(intptr_t)piVar6 == '\0') goto LAB_00574a70;
                        u += 1;
                    } while (u < (uint32_t)piVar1[2]);
                }
            }
            local_c = (int*)((int)(intptr_t)local_c + 1);
        } while (local_c < *(int**)(s + 0x58));
    }
    local_c = nullptr;
    if (*(int*)(s + 0x70) != 0) {
        do {
            int* piVar1 = *(int**)(*(int*)(s + 0x68) + (int)(intptr_t)local_c * 4);
            int* piVar2 = *(int**)(*(int*)(p + 0x68) + (int)(intptr_t)local_c * 4);
            piVar6 = piVar2;
            if (piVar1 == nullptr) {
                if (piVar2 != nullptr) goto LAB_00574a70;
            } else {
                if (piVar2 == nullptr || piVar1[2] != piVar2[2]) goto LAB_00574a70;
                uint32_t u = 0;
                if (piVar1[2] != 0) {
                    do {
                        uint32_t* puVar3 = *(uint32_t**)(*piVar1 + u * 4);
                        uint32_t* puVar4 = *(uint32_t**)(*piVar2 + u * 4);
                        piVar6 = (int*)((int(*)(uint32_t))(*(uint32_t**)(*(uint32_t*)*puVar3 + 0x1c))(*puVar4));
                        if (((char)(int)(intptr_t)piVar6 == '\0') ||
                            (piVar6 = (int*)((int(*)(uint32_t))(*(uint32_t**)(*(uint32_t*)puVar3[1] + 0x1c))(puVar4[1])), (char)(int)(intptr_t)piVar6 == '\0')) goto LAB_00574a70;
                        u += 1;
                    } while (u < (uint32_t)piVar1[2]);
                }
            }
            local_c = (int*)((int)(intptr_t)local_c + 1);
        } while (local_c < *(uint32_t*)(s + 0x70));
    }
    {
        uint32_t uVar7 = 0;
        uint32_t uVar5b = 0;
        if (*(int*)(s + 0x84) != 0) {
            do {
                piVar6 = (int*)((int(*)(uint32_t))(*(uint32_t**)(**(uint32_t**)(*(int*)(s + 0x7c) + uVar7 * 4) + 0x1c))(*(uint32_t*)(*(int*)(p + 0x7c) + uVar7 * 4)));
                if ((char)(int)(intptr_t)piVar6 == '\0') {
LAB_00574a70:
                    return (uint32_t)(int)(intptr_t)piVar6 & 0xffffff00;
                }
                uVar5b = *(uint32_t*)(s + 0x84);
                uVar7 += 1;
            } while (uVar7 < uVar5b);
        }
        return (uVar5b & 0xffffff00) | 1;
    }
}

// 0x574b20 — observed shape
void FUN_00574b20(void* self)
{
    uint32_t* in_ECX = (uint32_t*)self;
    FUN_00552c80();
    in_ECX[0] = 0x006c4350; // &PTR_FUN_006c4350
    in_ECX[0x11] = 0xffffffff;
    in_ECX[0x12] = 0;
    in_ECX[0x15] = 0;
    in_ECX[0x16] = 0;
    in_ECX[0x17] = 0;
    in_ECX[0x14] = 0;
    in_ECX[0x13] = 0x006c4344; // &PTR_FUN_006c4344
    in_ECX[0x18] = 1;
    in_ECX[0x1b] = 0;
    in_ECX[0x1c] = 0;
    in_ECX[0x1d] = 0;
    in_ECX[0x1a] = 0;
    in_ECX[0x19] = 0x006c4348; // &PTR_FUN_006c4348
    in_ECX[0x1e] = 1;
    in_ECX[0x1f] = 0;
    in_ECX[0x20] = 0;
    in_ECX[0x21] = 0;
}

// 0x574bc0 — observed shape
uint32_t FUN_00574bc0(void* self, uint32_t param_1)
{
    uint8_t* s = (uint8_t*)self;
    uint32_t uVar8 = *(uint32_t*)(s + 0x48);
    if ((uVar8 == 0) || (*(uint32_t*)(s + 0x44) == param_1) ||
        (param_1 != 0xffffffff && (((int)param_1 < 0 || (uVar8 <= param_1))))) {
        return uVar8 & 0xffffff00;
    }
    bool bVar7 = false;
    uVar8 = 0;
    if (*(int*)(s + 0x58) != 0) {
        do {
            int* piVar3 = *(int**)(*(int*)(s + 0x50) + uVar8 * 4);
            if (piVar3 != nullptr) {
                if (uVar8 == param_1) bVar7 = true;
                uint32_t uVar9 = 0;
                if (piVar3[2] != 0) {
                    do {
                        int iVar4 = *(int*)(*piVar3 + uVar9 * 4);
                        uint8_t* pbVar1 = (uint8_t*)(iVar4 + 0x20);
                        if (bVar7) *pbVar1 = *pbVar1 | 2;
                        else *pbVar1 = *pbVar1 & 0xfd;
                        uVar9 += 1;
                    } while (uVar9 < (uint32_t)piVar3[2]);
                }
            }
            uVar8 += 1;
        } while (uVar8 < *(uint32_t*)(s + 0x58));
    }
    uVar8 = 0;
    if (*(int*)(s + 0x84) != 0) {
        do {
            int iVar4 = *(int*)(*(int*)(s + 0x7c) + uVar8 * 4);
            *(uint16_t*)(iVar4 + 0x20) = *(uint16_t*)(iVar4 + 0x20) & 0xfffd | 1;
            uVar8 += 1;
        } while (uVar8 < *(uint32_t*)(s + 0x84));
    }
    if (param_1 != 0xffffffff) {
        uVar8 = *(uint32_t*)(s + 0x68);
        int* piVar3 = *(int**)(uVar8 + param_1 * 4);
        if (piVar3 != nullptr) {
            uint32_t uVar9 = 0;
            if (piVar3[2] != 0) {
                do {
                    int iVar4 = **(int**)(*piVar3 + uVar9 * 4);
                    *(uint16_t*)(iVar4 + 0x20) = *(uint16_t*)(iVar4 + 0x20) & 0xfffe | 2;
                    uint32_t* puVar5 = *(uint32_t**)(*(int*)(*piVar3 + uVar9 * 4) + 4);
                    uint32_t* puVar6 = *(uint32_t**)(iVar4 + 0xc0);
                    if (puVar6 != puVar5) {
                        if (puVar6 != nullptr) {
                            int* piVar2 = (int*)(puVar6 + 1);
                            *piVar2 += -1;
                            if (*piVar2 == 0) {
                                ((void(*)(int))(puVar6[0]))(1);
                            }
                        }
                        *(uint32_t**)(iVar4 + 0xc0) = puVar5;
                        if (puVar5 != nullptr) puVar5[1] += 1;
                    }
                    uVar8 = piVar3[2];
                    uVar9 += 1;
                } while (uVar9 < uVar8);
            }
        }
    }
    *(uint32_t*)(s + 0x44) = param_1;
    return (uVar8 & 0xffffff00) | 1;
}

// 0x574d50 — observed shape
// NEEDS_MANUAL: very large non_contiguous body (344 lines); vector-grow/ensure and lookup loops for three vectors preserved structurally from visible ranges; exact growth helper FUN_0055f300 and lookup vtables kept
void FUN_00574d50(void* self, int* param_1)
{
    uint32_t* in_ECX = (uint32_t*)self;
    FUN_00552b70(param_1);
    void* local_4 = nullptr;
    FUN_005bd960(self, &local_4);
    int iVar7 = (int)(intptr_t)local_4;
    uint32_t local_1c = 0;
    if (in_ECX[0x16] != 0) {
        do {
            int* piVar1 = *(int**)(in_ECX[0x14] + local_1c * 4);
            if (piVar1 == nullptr) {
                if ((local_1c < *(uint32_t*)(iVar7 + 0x54)) ||
                    (FUN_006b34a0((void*)(*(int*)(iVar7 + 0x60) + local_1c)), local_1c < *(uint32_t*)(iVar7 + 0x54))) {
                    if (local_1c < *(uint32_t*)(iVar7 + 0x58)) {
                        if (*(int*)(*(int*)(iVar7 + 0x50) + local_1c * 4) != 0) {
                            *(int*)(iVar7 + 0x5c) -= 1;
                        }
                    } else {
                        *(uint32_t*)(iVar7 + 0x58) = local_1c + 1;
                    }
                    *(uint32_t*)(*(int*)(iVar7 + 0x50) + local_1c * 4) = 0;
                }
            } else {
                int* piVar10 = nullptr;
                void* alloc = FUN_00533c78(0xc);
                if (alloc != nullptr) {
                    *(int*)alloc = 0;
                    *((int*)alloc + 1) = 0;
                    *((int*)alloc + 2) = 0;
                    piVar10 = (int*)alloc;
                }
                if ((local_1c < *(uint32_t*)(iVar7 + 0x54)) ||
                    (FUN_006b34a0((void*)(*(int*)(iVar7 + 0x60) + local_1c)), local_1c < *(uint32_t*)(iVar7 + 0x54))) {
                    if (local_1c < *(uint32_t*)(iVar7 + 0x58)) {
                        if (piVar10 == nullptr) {
                            if (*(int*)(*(int*)(iVar7 + 0x50) + local_1c * 4) != 0) {
                                int iVar6 = *(int*)(iVar7 + 0x5c) - 1;
                                *(int*)(iVar7 + 0x5c) = iVar6;
                            }
                        } else if (*(int*)(*(int*)(iVar7 + 0x50) + local_1c * 4) == 0) {
                            *(int*)(iVar7 + 0x5c) += 1;
                        }
                    } else {
                        *(uint32_t*)(iVar7 + 0x58) = local_1c + 1;
                        if (piVar10 != nullptr) *(int*)(iVar7 + 0x5c) += 1;
                    }
                    *(int**)(*(int*)(iVar7 + 0x50) + local_1c * 4) = piVar10;
                }
                uint32_t* local_14 = nullptr;
                if (piVar1[2] != 0) {
                    do {
                        uint32_t uVar2 = *(uint32_t*)(*piVar1 + (int)(intptr_t)local_14 * 4);
                        int* piVar5 = (int*)*param_1;
                        int iVar7b = ((int(*)(uint32_t))(*(uint32_t*)*piVar5 + 4))(uVar2);
                        for (uint32_t* puVar3 = *(uint32_t**)(piVar5[2] + iVar7b * 4); puVar3 != nullptr; puVar3 = (uint32_t*)*puVar3) {
                            char cVar4 = (char)((int(*)(uint32_t, uint32_t))(*(uint32_t*)*piVar5 + 8))(uVar2, puVar3[1]);
                            if (cVar4 != '\0') {
                                int iVar7c = piVar10[1];
                                uint32_t uVar2b = puVar3[2];
                                if (piVar10[2] == iVar7c) {
                                    iVar7c = iVar7c == 0 ? 1 : iVar7c * 2;
                                    FUN_0055f300(iVar7c);
                                }
                                *(uint32_t*)(*piVar10 + piVar10[2] * 4) = uVar2b;
                                goto LAB_00574ebb;
                            }
                        }
                        {
                            int iVar7c = piVar10[1];
                            if (piVar10[2] == iVar7c) {
                                iVar7c = iVar7c == 0 ? 1 : iVar7c * 2;
                                FUN_0055f300(iVar7c);
                            }
                            *(uint32_t*)(*piVar10 + piVar10[2] * 4) = uVar2;
                        }
LAB_00574ebb:
                        piVar10[2] += 1;
                        local_14 = (uint32_t*)((int)(intptr_t)local_14 + 1);
                    } while (local_14 < (uint32_t*)piVar1[2]);
                    iVar7 = (int)(intptr_t)local_4;
                }
            }
            local_1c += 1;
        } while (local_1c < in_ECX[0x16]);
    }
    local_1c = 0;
    if (in_ECX[0x1c] != 0) {
        do {
            int* piVar1 = *(int**)(in_ECX[0x1a] + local_1c * 4);
            if (piVar1 == nullptr) {
                if ((local_1c < *(uint32_t*)(iVar7 + 0x6c)) ||
                    (FUN_006b34a0((void*)(*(int*)(iVar7 + 0x78) + local_1c)), local_1c < *(uint32_t*)(iVar7 + 0x6c))) {
                    if (local_1c < *(uint32_t*)(iVar7 + 0x70)) {
                        if (*(int*)(*(int*)(iVar7 + 0x68) + local_1c * 4) != 0) {
                            *(int*)(iVar7 + 0x74) -= 1;
                        }
                    } else {
                        *(uint32_t*)(iVar7 + 0x70) = local_1c + 1;
                    }
                    *(uint32_t*)(*(int*)(iVar7 + 0x68) + local_1c * 4) = 0;
                }
            } else {
                int* piVar10 = nullptr;
                void* alloc = FUN_00533c78(0xc);
                if (alloc != nullptr) {
                    *(int*)alloc = 0;
                    *((int*)alloc + 1) = 0;
                    *((int*)alloc + 2) = 0;
                    piVar10 = (int*)alloc;
                }
                if ((local_1c < *(uint32_t*)(iVar7 + 0x6c)) ||
                    (FUN_006b34a0((void*)(*(int*)(iVar7 + 0x78) + local_1c)), local_1c < *(uint32_t*)(iVar7 + 0x6c))) {
                    if (local_1c < *(uint32_t*)(iVar7 + 0x70)) {
                        if (piVar10 == nullptr) {
                            if (*(int*)(*(int*)(iVar7 + 0x68) + local_1c * 4) != 0) {
                                *(int*)(iVar7 + 0x74) -= 1;
                            }
                        } else if (*(int*)(*(int*)(iVar7 + 0x68) + local_1c * 4) == 0) {
                            *(int*)(iVar7 + 0x74) += 1;
                        }
                    } else {
                        *(uint32_t*)(iVar7 + 0x70) = local_1c + 1;
                        if (piVar10 != nullptr) *(int*)(iVar7 + 0x74) += 1;
                    }
                    *(int**)(*(int*)(iVar7 + 0x68) + local_1c * 4) = piVar10;
                }
                uint32_t uStack_c = 0;
                if (piVar1[2] != 0) {
                    do {
                        uint32_t* puVar3 = *(uint32_t**)(*piVar1 + uStack_c * 4);
                        uint32_t* local_14 = (uint32_t*)FUN_00533c78(8);
                        if (local_14 != nullptr) local_14[1] = 0;
                        {
                            int iVar7b = piVar10[1];
                            if (piVar10[2] == iVar7b) {
                                int iVar6 = iVar7b * 2;
                                if (iVar7b == 0) iVar6 = 1;
                                if (iVar6 != iVar7b) {
                                    int iVar7c = 0;
                                    if (iVar6 != 0) {
                                        iVar7c = (int)(intptr_t)thunk_FUN_00533c78(iVar6 * 4);
                                        uint32_t uVar8 = 0;
                                        if (piVar10[2] != 0) {
                                            do {
                                                *(uint32_t*)(iVar7c + uVar8 * 4) = *(uint32_t*)(*piVar10 + uVar8 * 4);
                                                uVar8 += 1;
                                            } while (uVar8 < (uint32_t)piVar10[2]);
                                        }
                                    }
                                    operator_delete__((void*)*piVar10);
                                    *piVar10 = iVar7c;
                                    piVar10[1] = iVar6;
                                }
                            }
                            *(uint32_t**)(*piVar10 + piVar10[2] * 4) = local_14;
                            piVar10[2] += 1;
                        }
                        uint32_t uVar2 = *puVar3;
                        int* piVar5 = (int*)*param_1;
                        int iVar7d = ((int(*)(uint32_t))(*(uint32_t*)*piVar5 + 4))(uVar2);
                        uint32_t* found = nullptr;
                        for (uint32_t* node = *(uint32_t**)(piVar5[2] + iVar7d * 4); node != nullptr; node = (uint32_t*)*node) {
                            char cVar4 = (char)((int(*)(uint32_t, uint32_t))(*(uint32_t*)*piVar5 + 8))(uVar2, node[1]);
                            if (cVar4 != '\0') { found = node; break; }
                        }
                        uint32_t* chosen = found ? found + 2 : local_14;
                        in_ECX[0] = (uint32_t)(intptr_t)chosen;
                        {
                            uint32_t* puVar9 = (uint32_t*)((void*(*)(uint32_t))(*(uint32_t*)local_14[1] + 8))(0);
                            uint32_t* puVar3b = (uint32_t*)in_ECX[1];
                            if (puVar3b != puVar9) {
                                if (puVar3b != nullptr) {
                                    int* piVar5b = (int*)(puVar3b + 1);
                                    *piVar5b += -1;
                                    if (*piVar5b == 0) ((void(*)(int))(puVar3b[0]))(1);
                                }
                                in_ECX[1] = (uint32_t)(intptr_t)puVar9;
                                if (puVar9 != nullptr) puVar9[1] += 1;
                            }
                        }
                        uStack_c += 1;
                    } while (uStack_c < (uint32_t)piVar1[2]);
                    iVar7 = (int)(intptr_t)local_4;
                }
            }
            local_1c += 1;
        } while (local_1c < in_ECX[0x1c]);
    }
    local_1c = 0;
    if (in_ECX[0x21] != 0) {
        do {
            uint32_t uVar2 = *(uint32_t*)(in_ECX[0x1f] + local_1c * 4);
            int* piVar1 = (int*)*param_1;
            int iVar6 = ((int(*)(uint32_t))(*(uint32_t*)*piVar1 + 4))(uVar2);
            int* piVar10 = *(int**)(piVar1[2] + iVar6 * 4);
            while (true) {
                if (piVar10 == nullptr) break;
                {
                    char cVar4 = (char)((int(*)(uint32_t, int))(*(uint32_t*)*piVar1 + 8))(uVar2, piVar10[1]);
                    if (cVar4 == '\0') { piVar10 = (int*)*piVar10; continue; }
                }
                int iVar7b = *(int*)(iVar7 + 0x80);
                int iVar11 = piVar10[2];
                if (*(int*)(iVar7 + 0x84) == iVar7b) {
                    int iVar12 = iVar7b * 2;
                    if (iVar7b == 0) iVar12 = 1;
                    if (iVar12 != iVar7b) {
                        int iVar6b = 0;
                        if (iVar12 != 0) {
                            iVar6b = (int)(intptr_t)thunk_FUN_00533c78(iVar12 * 4);
                            uint32_t uVar8 = 0;
                            if (*(int*)(iVar7 + 0x84) != 0) {
                                do {
                                    *(uint32_t*)(iVar6b + uVar8 * 4) = *(uint32_t*)(*(int*)(iVar7 + 0x7c) + uVar8 * 4);
                                    uVar8 += 1;
                                } while (uVar8 < *(uint32_t*)(iVar7 + 0x84));
                            }
                        }
                        operator_delete__(*(void**)(iVar7 + 0x7c));
                        *(int*)(iVar7 + 0x7c) = iVar6b;
                        *(int*)(iVar7 + 0x80) = iVar12;
                    }
                }
                *(int*)(*(int*)(iVar7 + 0x7c) + *(int*)(iVar7 + 0x84) * 4) = iVar11;
                goto LAB_005752ee;
            }
            {
                int iVar6b = *(int*)(iVar7 + 0x80);
                if (*(int*)(iVar7 + 0x84) == iVar6b) {
                    int iVar11 = iVar6b * 2;
                    if (iVar6b == 0) iVar11 = 1;
                    if (iVar11 != iVar6b) {
                        int iVar6c = 0;
                        if (iVar11 != 0) {
                            iVar6c = (int)(intptr_t)thunk_FUN_00533c78(iVar11 * 4);
                            uint32_t uVar8 = 0;
                            if (*(int*)(iVar7 + 0x84) != 0) {
                                do {
                                    *(uint32_t*)(iVar6c + uVar8 * 4) = *(uint32_t*)(*(int*)(iVar7 + 0x7c) + uVar8 * 4);
                                    uVar8 += 1;
                                } while (uVar8 < *(uint32_t*)(iVar7 + 0x84));
                            }
                        }
                        operator_delete__(*(void**)(iVar7 + 0x7c));
                        *(int*)(iVar7 + 0x7c) = iVar6c;
                        *(int*)(iVar7 + 0x80) = iVar11;
                    }
                }
                *(uint32_t*)(*(int*)(iVar7 + 0x7c) + *(int*)(iVar7 + 0x84) * 4) = uVar2;
            }
LAB_005752ee:
            *(int*)(iVar7 + 0x84) += 1;
            local_1c += 1;
        } while (local_1c < in_ECX[0x21]);
    }
    {
        uint32_t uVar2 = *(uint32_t*)(iVar7 + 0x44);
        *(uint32_t*)(iVar7 + 0x44) = 0xffffffff;
        FUN_00574bc0((void*)iVar7, uVar2);
    }
}

// 0x575520 — observed shape
// NEEDS_MANUAL: large deserialization-style body with indirect vtable reads at param_1+0x15c; stack locals auStack_1e offsets preserved structurally; vector-grow inline code translated
void FUN_00575520(void* self, int param_1)
{
    uint8_t* in_ECX = (uint8_t*)self;
    uint32_t uStack_34 = (uint32_t)param_1;
    uint8_t* puStack_38 = (uint8_t*)(intptr_t)0x575537;
    FUN_00552f70();
    uStack_34 = 4;
    puStack_38 = in_ECX + 0x44;
    uint32_t uStack_3c = 0x575548;
    ((void(*)())(*(uint32_t**)(**(int**)(param_1 + 0x15c) + 8)))();
    uStack_3c = 4;
    uint8_t* puVar7 = in_ECX + 0x48;
    ((void(*)())(*(uint32_t**)(**(int**)(param_1 + 0x15c) + 8)))();
    uint32_t uVar6 = 0;
    uint8_t* auStack_1e = (uint8_t*)(intptr_t)0;
    ((void(*)(uint8_t*, uint32_t))(*(uint32_t**)(**(int**)(param_1 + 0x15c) + 8)))(auStack_1e, 4);
    uint32_t unaff_EDI = uStack_34;
    if (unaff_EDI != 0) {
        do {
            int* piVar8 = nullptr;
            void* al = FUN_00533c78(0xc);
            if (al != nullptr) {
                *(int*)al = 0;
                *((int*)al + 1) = 0;
                *((int*)al + 2) = 0;
                piVar8 = (int*)al;
            }
            if ((uVar6 < *(uint32_t*)(in_ECX + 0x54)) ||
                (FUN_006b34a0((void*)(*(int*)(in_ECX + 0x60) + uVar6)), uVar6 < *(uint32_t*)(in_ECX + 0x54))) {
                if (uVar6 < *(uint32_t*)(in_ECX + 0x58)) {
                    if (piVar8 == nullptr) {
                        if (*(int*)(*(int*)(in_ECX + 0x50) + uVar6 * 4) != 0) {
                            *(int*)(in_ECX + 0x5c) -= 1;
                        }
                    } else if (*(int*)(*(int*)(in_ECX + 0x50) + uVar6 * 4) == 0) {
                        *(int*)(in_ECX + 0x5c) += 1;
                    }
                } else {
                    *(uint32_t*)(in_ECX + 0x58) = uVar6 + 1;
                    if (piVar8 != nullptr) *(int*)(in_ECX + 0x5c) += 1;
                }
                *(int**)(*(int*)(in_ECX + 0x50) + uVar6 * 4) = piVar8;
            }
            uStack_34 = 0;
            ((void(*)(uint32_t*, uint32_t))(*(uint32_t**)(**(int**)(param_1 + 0x15c) + 8)))(&uStack_34, 4);
            uint32_t uVar9 = 0;
            if (uStack_34 != 0) {
                do {
                    int iVar2 = piVar8[1];
                    if (piVar8[2] == iVar2) {
                        iVar2 = iVar2 == 0 ? 1 : iVar2 * 2;
                        FUN_0055f300(iVar2);
                    }
                    *(uint8_t**)(*piVar8 + piVar8[2] * 4) = puStack_38;
                    piVar8[2] += 1;
                    FUN_00545cc0();
                    uVar9 += 1;
                } while (uVar9 < uStack_34);
            }
            uVar6 += 1;
        } while (uVar6 < unaff_EDI);
        in_ECX = puStack_38;
    }
    ((void(*)(uint8_t*, uint32_t))(*(uint32_t**)(**(int**)(param_1 + 0x15c) + 8)))(auStack_1e, 4);
    uVar6 = 0;
    if (uStack_34 != 0) {
        do {
            int* piVar8 = nullptr;
            void* al = FUN_00533c78(0xc);
            if (al != nullptr) {
                *(int*)al = 0;
                *((int*)al + 1) = 0;
                *((int*)al + 2) = 0;
                piVar8 = (int*)al;
            }
            if ((uVar6 < *(uint32_t*)(in_ECX + 0x6c)) ||
                (FUN_006b34a0((void*)(*(int*)(in_ECX + 0x78) + uVar6)), uVar6 < *(uint32_t*)(in_ECX + 0x6c))) {
                if (uVar6 < *(uint32_t*)(in_ECX + 0x70)) {
                    if (piVar8 == nullptr) {
                        if (*(int*)(*(int*)(in_ECX + 0x68) + uVar6 * 4) != 0) {
                            *(int*)(in_ECX + 0x74) -= 1;
                        }
                    } else if (*(int*)(*(int*)(in_ECX + 0x68) + uVar6 * 4) == 0) {
                        *(int*)(in_ECX + 0x74) += 1;
                    }
                } else {
                    *(uint32_t*)(in_ECX + 0x70) = uVar6 + 1;
                    if (piVar8 != nullptr) *(int*)(in_ECX + 0x74) += 1;
                }
                *(int**)(*(int*)(in_ECX + 0x68) + uVar6 * 4) = piVar8;
            }
            uStack_3c = 0;
            ((void(*)(uint32_t*, uint32_t))(*(uint32_t**)(**(int**)(param_1 + 0x15c) + 8)))(&uStack_3c, 4);
            uint32_t uVar9 = 0;
            if (uStack_3c != 0) {
                do {
                    int iVar2 = (int)(intptr_t)FUN_00533c78(8);
                    if (iVar2 == 0) iVar2 = 0;
                    else *(uint32_t*)(iVar2 + 4) = 0;
                    int iVar3 = piVar8[1];
                    if (piVar8[2] == iVar3) {
                        int iVar5 = iVar3 * 2;
                        if (iVar3 == 0) iVar5 = 1;
                        if (iVar5 != iVar3) {
                            int iVar3b = 0;
                            if (iVar5 != 0) {
                                iVar3b = (int)(intptr_t)thunk_FUN_00533c78(iVar5 * 4);
                                uint32_t uVar4 = 0;
                                if (piVar8[2] != 0) {
                                    do {
                                        *(uint32_t*)(iVar3b + uVar4 * 4) = *(uint32_t*)(*piVar8 + uVar4 * 4);
                                        uVar4 += 1;
                                    } while (uVar4 < (uint32_t)piVar8[2]);
                                }
                            }
                            operator_delete__((void*)*piVar8);
                            *piVar8 = iVar3b;
                            piVar8[1] = iVar5;
                        }
                    }
                    *(int*)(*piVar8 + piVar8[2] * 4) = iVar2;
                    piVar8[2] += 1;
                    FUN_00545cc0();
                    FUN_00545cc0();
                    uVar9 += 1;
                } while (uVar9 < uStack_3c);
            }
            uVar6 += 1;
        } while (uVar6 < uStack_34);
        in_ECX = puVar7;
    }
    puVar7 = nullptr;
    ((void(*)(uint8_t*, uint32_t))(*(uint32_t**)(**(int**)(param_1 + 0x15c) + 8)))(auStack_1e, 4);
    if (puStack_38 != nullptr) {
        do {
            int iVar2 = *(int*)(in_ECX + 0x80);
            if (*(int*)(in_ECX + 0x84) == iVar2) {
                int iVar3 = iVar2 * 2;
                if (iVar2 == 0) iVar3 = 1;
                uint8_t* saved = in_ECX;
                if (iVar3 != iVar2) {
                    int iVar2b = 0;
                    if (iVar3 != 0) {
                        iVar2b = (int)(intptr_t)thunk_FUN_00533c78(iVar3 * 4);
                        uint32_t uVar6b = 0;
                        if (*(int*)(saved + 0x84) != 0) {
                            do {
                                *(uint32_t*)(iVar2b + uVar6b * 4) = *(uint32_t*)(*(int*)(saved + 0x7c) + uVar6b * 4);
                                uVar6b += 1;
                            } while (uVar6b < *(uint32_t*)(saved + 0x84));
                        }
                    }
                    operator_delete__(*(void**)(saved + 0x7c));
                    *(int*)(saved + 0x7c) = iVar2b;
                    *(int*)(saved + 0x80) = iVar3;
                }
            }
            *(uint8_t**)(*(int*)(in_ECX + 0x7c) + *(int*)(in_ECX + 0x84) * 4) = in_ECX;
            *(int*)(in_ECX + 0x84) += 1;
            FUN_00545cc0();
            puVar7 += 1;
        } while (puVar7 < puStack_38);
    }
}

// 0x575a00 — observed shape
void FUN_00575a00(void* self)
{
    uint8_t* s = (uint8_t*)self;
    uint32_t uVar5 = 0;
    if (*(int*)(s + 0x58) != 0) {
        do {
            uint32_t* puVar2 = *(uint32_t**)(*(int*)(s + 0x50) + uVar5 * 4);
            if (puVar2 != nullptr) {
                operator_delete__((void*)*puVar2);
                operator_delete(puVar2);
            }
            uVar5 += 1;
        } while (uVar5 < *(uint32_t*)(s + 0x58));
    }
    uVar5 = 0;
    if (*(int*)(s + 0x58) != 0) {
        do {
            *(uint32_t*)(*(int*)(s + 0x50) + uVar5 * 4) = 0;
            uVar5 += 1;
        } while (uVar5 < *(uint32_t*)(s + 0x58));
    }
    *(uint32_t*)(s + 0x58) = 0;
    *(uint32_t*)(s + 0x5c) = 0;
    uint32_t local_4 = 0;
    if (*(int*)(s + 0x70) != 0) {
        do {
            uint32_t uVar5b = 0;
            int* piVar3 = *(int**)(*(int*)(s + 0x68) + local_4 * 4);
            if (piVar3 != nullptr) {
                if (piVar3[2] != 0) {
                    do {
                        void* pvVar4 = *(void**)(*piVar3 + uVar5b * 4);
                        if (pvVar4 != nullptr) {
                            uint32_t* puVar2 = *(uint32_t**)((int)(intptr_t)pvVar4 + 4);
                            if (puVar2 != nullptr) {
                                int* piVar1 = (int*)(puVar2 + 1);
                                *piVar1 += -1;
                                if (*piVar1 == 0) {
                                    ((void(*)(int))(puVar2[0]))(1);
                                }
                            }
                            operator_delete(pvVar4);
                        }
                        uVar5b += 1;
                    } while (uVar5b < (uint32_t)piVar3[2]);
                }
                operator_delete__((void*)*piVar3);
                operator_delete(piVar3);
            }
            local_4 += 1;
        } while (local_4 < *(uint32_t*)(s + 0x70));
    }
    uVar5 = 0;
    if (*(int*)(s + 0x70) != 0) {
        do {
            *(uint32_t*)(*(int*)(s + 0x68) + uVar5 * 4) = 0;
            uVar5 += 1;
        } while (uVar5 < *(uint32_t*)(s + 0x70));
    }
    *(uint32_t*)(s + 0x70) = 0;
    *(uint32_t*)(s + 0x74) = 0;
    *(uint32_t*)(s + 0x84) = 0;
}

// 0x575af0 — observed shape
void FUN_00575af0(void* self, uint8_t param_1)
{
    FUN_00575b10();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}
