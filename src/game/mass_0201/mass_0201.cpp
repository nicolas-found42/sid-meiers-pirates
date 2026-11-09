#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void* operator_delete__(void* p) noexcept;
extern void* operator_delete(void* p) noexcept;
extern int FUN_00533c78(size_t n);
extern void* FUN_005b8030(int a, int b, int c, int d, int e);
extern void FUN_005b0280();
extern void FUN_005e4780();
extern void FUN_005ae720();
extern void FUN_005ae700();
extern int FUN_00538580(void** out);
extern int FUN_00538680();
extern void FUN_00552ef0(int a, unsigned int b, unsigned int c, unsigned int d);
extern void FUN_00576320(int a, unsigned int b, unsigned int c, int d, unsigned int e, unsigned int f, unsigned int* g, unsigned int* h);
extern void FUN_005b0360(unsigned int a, unsigned int b, unsigned int c);
extern void FUN_00582420(unsigned int a, int b, unsigned int c, unsigned int d, unsigned int* e, unsigned int* f);
extern void FUN_00582080(void* a, unsigned int b);
extern char FUN_00568540(float v);
extern void* FUN_005b00e0(void* a, void* b);
extern unsigned char FUN_005823b0(float a, float* b, unsigned int c, void* d);
extern float10 FUN_0056a5f0(float a, unsigned int b, unsigned int c, unsigned int d, void* e);
extern void FUN_005b0130(float a, float b, float c, float d, float e, float f);

// 0x5b0420 — observed shape
void FUN_005b0420(void* self, int param_1, int param_2)
{
    int iVar3;
    uint32_t* puVar4;
    uint32_t* puVar2;
    int* piVar1;

    if (*(int*)((char*)self + 0x4c) == 0) {
        iVar3 = FUN_00533c78(0x20);
        if (iVar3 == 0) {
            puVar4 = nullptr;
        } else {
            puVar4 = (uint32_t*)FUN_005b8030(0, 0, 0, 0, 0);
        }
        puVar2 = *(uint32_t**)((char*)self + 0x4c);
        if (puVar2 != puVar4) {
            if (puVar2 != nullptr) {
                piVar1 = (int*)puVar2 + 1;
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    (*(void(__cdecl**)(int))puVar2)(1);
                }
            }
            *(uint32_t**)((char*)self + 0x4c) = puVar4;
            if (puVar4 != nullptr) {
                puVar4[1] = puVar4[1] + 1;
            }
        }
    }
    iVar3 = *(int*)((char*)self + 0x4c);
    operator_delete__(*(void**)(iVar3 + 0x1c));
    if (param_1 == 0 || param_2 == 0) {
        *(uint32_t*)(iVar3 + 0x18) = 0;
        *(uint32_t*)(iVar3 + 0x1c) = 0;
        *(uint32_t*)((char*)self + 0x50) = 0;
        FUN_005b0280();
        return;
    }
    *(int*)(iVar3 + 0x18) = param_2;
    *(int*)(iVar3 + 0x1c) = param_1;
    *(uint32_t*)((char*)self + 0x50) = 0;
    FUN_005b0280();
    return;
}

// 0x5b04d0 — observed shape
void FUN_005b04d0(void* self, uint8_t param_1)
{
    operator_delete__(*(void**)((intptr_t)self + 0x5c));
    FUN_005e4780();
    FUN_005ae720();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x5b0510 — observed shape
void FUN_005b0510(void* self, float param_1)
{
    float fVar1;
    int iVar2;
    char cVar3;
    uint8_t uVar4;
    float* pfVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    uint32_t uVar8;
    float* pfVar9;
    bool bVar10;
    float10 fVar11;
    float fVar12;
    float local_2c;
    float local_28;
    float local_24;
    float local_20;
    uint32_t local_1c;
    uint32_t local_18;
    uint32_t local_14;
    uint32_t local_10;
    float local_c;
    float local_8;
    int local_4;

    if (param_1 < *(float*)((char*)self + 0x24)) {
        *(uint32_t*)((char*)self + 0x54) = 0xff7fffff;
    }
    if ((*(int*)((char*)self + 0x34) != 0) && (*(int*)((char*)self + 0x48) != 0)) {
        local_4 = (int)(intptr_t)self;
        cVar3 = FUN_00568540(param_1);
        if (cVar3 == '\0') {
            fVar1 = *(float*)((char*)self + 0x2c);
            local_10 = (uint32_t)(intptr_t)FUN_005b00e0(nullptr, &local_14);
            iVar2 = *(int*)((char*)self + 0x4c);
            if (iVar2 == 0) {
                uVar7 = 0;
                pfVar9 = nullptr;
            } else {
                uVar7 = *(uint32_t*)(iVar2 + 0x18);
                pfVar9 = *(float**)(iVar2 + 0x1c);
            }
            uVar4 = FUN_005823b0(fVar1, pfVar9, uVar7, (char*)self + 0x50);
            if (*(float*)((char*)self + 0x54) == -3.4028235e+38f) {
                *(float*)((char*)self + 0x54) = fVar1;
                *(uint8_t*)((char*)self + 0x58) = uVar4;
                return;
            }
            local_2c = *(float*)((char*)self + 0x54);
            cVar3 = *(char*)((char*)self + 0x58);
            *(float*)((char*)self + 0x54) = fVar1;
            *(uint8_t*)((char*)self + 0x58) = uVar4;
            do {
                bVar10 = fVar1 < local_2c;
                if (cVar3 == '\0') {
                    uVar6 = 0;
                    if (3 < (int)uVar7) {
                        pfVar5 = pfVar9 + 5;
                        do {
                            if ((local_2c < pfVar5[-5]) && ((bVar10 || (fVar12 = pfVar5[-5], (!NAN(fVar12) && !NAN(fVar1)) && fVar12 < fVar1 != (fVar12 == fVar1))) && (*(char*)(pfVar5 + -4) != '\0'))) goto LAB_005b0750;
                            if ((local_2c < pfVar5[-3]) && ((bVar10 || (fVar12 = pfVar5[-3], (!NAN(fVar12) && !NAN(fVar1)) && fVar12 < fVar1 != (fVar12 == fVar1))) && (*(char*)(pfVar5 + -2) != '\0'))) {
                                uVar6 = uVar6 + 1;
                                goto LAB_005b0750;
                            }
                            if (((local_2c < pfVar5[-1]) && ((bVar10 || (fVar12 = pfVar5[-1], (!NAN(fVar12) && !NAN(fVar1)) && fVar12 < fVar1 != (fVar12 == fVar1))))) && (*(char*)pfVar5 != '\0')) {
                                uVar6 = uVar6 + 2;
                                goto LAB_005b0750;
                            }
                            if ((local_2c < pfVar5[1]) && ((bVar10 || (fVar12 = pfVar5[1], (!NAN(fVar12) && !NAN(fVar1)) && fVar12 < fVar1 != (fVar12 == fVar1))) && (*(char*)(pfVar5 + 2) != '\0'))) {
                                uVar6 = uVar6 + 3;
                                goto LAB_005b0750;
                            }
                            uVar6 = uVar6 + 4;
                            pfVar5 = pfVar5 + 8;
                        } while (uVar6 < uVar7 - 3);
                    }
                    while ((uVar6 < uVar7 && (((pfVar9[uVar6 * 2] <= local_2c || ((!bVar10 && (fVar12 = pfVar9[uVar6 * 2], (NAN(fVar12) || NAN(fVar1)) || fVar12 < fVar1 == (fVar12 == fVar1))))) || (*(char*)(pfVar9 + uVar6 * 2 + 1) == '\0'))))) {
                        uVar6 = uVar6 + 1;
                    }
LAB_005b0750:
                    if (uVar6 == uVar7) {
                        if (!bVar10) {
                            return;
                        }
                        uVar6 = 0;
                        if (3 < (int)uVar7) {
                            pfVar5 = pfVar9 + 5;
                            do {
                                if ((pfVar5[-5] < fVar1) && (*(char*)(pfVar5 + -4) != '\0')) goto LAB_005b07fd;
                                if ((pfVar5[-3] < fVar1) && (*(char*)(pfVar5 + -2) != '\0')) {
                                    uVar6 = uVar6 + 1;
                                    goto LAB_005b07fd;
                                }
                                if ((pfVar5[-1] < fVar1) && (*(char*)pfVar5 != '\0')) {
                                    uVar6 = uVar6 + 2;
                                    goto LAB_005b07fd;
                                }
                                if ((pfVar5[1] < fVar1) && (*(char*)(pfVar5 + 2) != '\0')) {
                                    uVar6 = uVar6 + 3;
                                    goto LAB_005b07fd;
                                }
                                uVar6 = uVar6 + 4;
                                pfVar5 = pfVar5 + 8;
                            } while (uVar6 < uVar7 - 3);
                        }
                        while ((uVar6 < uVar7 && ((fVar1 <= pfVar9[uVar6 * 2] || (*(char*)(pfVar9 + uVar6 * 2 + 1) == '\0'))))) {
                            uVar6 = uVar6 + 1;
                        }
LAB_005b07fd:
                        if (uVar6 == uVar7) {
                            return;
                        }
                    }
                } else {
                    uVar6 = uVar7;
                    if (uVar7 != 0) {
                        pfVar5 = pfVar9 + uVar7 * 2 + -2;
                        do {
                            fVar12 = *pfVar5;
                            if (((!NAN(fVar12) && !NAN(local_2c)) && fVar12 < local_2c != (fVar12 == local_2c)) && (*(char*)(pfVar5 + 1) == '\0')) break;
                            uVar6 = uVar6 - 1;
                            pfVar5 = pfVar5 + -2;
                        } while (uVar6 != 0);
                    }
                }
                uVar8 = uVar6;
                if (uVar6 < uVar7) {
                    pfVar5 = pfVar9 + uVar6 * 2 + 1;
                    do {
                        if (*(char*)pfVar5 == '\0') break;
                        uVar8 = uVar8 + 1;
                        pfVar5 = pfVar5 + 2;
                    } while (uVar8 < uVar7);
                }
                if (uVar8 == uVar7) {
                    uVar8 = uVar8 - 1;
                }
                local_1c = 0;
                local_20 = fVar1;
                if (bVar10) {
                    if (local_2c < pfVar9[uVar8 * 2]) {
                        local_20 = pfVar9[uVar7 * 2 + -2];
                        local_28 = pfVar9[uVar6 * 2];
                        goto LAB_005b08e8;
                    }
                    local_28 = pfVar9[uVar6 * 2];
                    local_8 = *pfVar9;
                    if (fVar1 <= pfVar9[uVar8 * 2]) {
                        local_24 = fVar1;
                    } else {
                        local_24 = pfVar9[uVar8 * 2];
                    }
LAB_005b08f3:
                    fVar12 = (local_24 - local_28) * 0.5f + local_28;
                } else {
                    local_8 = local_2c;
                    if (pfVar9[uVar8 * 2] < fVar1) {
                        local_20 = pfVar9[uVar8 * 2];
                        local_28 = pfVar9[uVar6 * 2];
LAB_005b08e8:
                        local_8 = local_2c;
                        local_24 = pfVar9[uVar8 * 2];
                        goto LAB_005b08f3;
                    }
                    local_28 = pfVar9[uVar6 * 2];
                    local_24 = pfVar9[uVar8 * 2];
                    fVar12 = fVar1;
                }
                fVar11 = FUN_0056a5f0(fVar12, local_10, local_14, local_18, &local_1c);
                local_c = (float)fVar11;
                fVar12 = *(float*)(*(int*)(local_4 + 0x34) + 0xf4);
                if (bVar10) {
                    fVar12 = (*(float*)(local_4 + 0x1c) - *(float*)(local_4 + 0x18)) + fVar12;
                }
                FUN_005b0130((fVar12 + fVar1) - local_2c, local_20, local_8, local_28, local_24, local_c);
                if (fVar1 <= pfVar9[uVar8 * 2]) {
                    return;
                }
                local_2c = local_20;
                cVar3 = FUN_005823b0(local_20, pfVar9, uVar7, (void*)(local_4 + 0x50));
            } while (true);
        }
    }
    return;
}

// 0x5b09d0 — observed shape
int FUN_005b09d0(uint32_t param_1, uint32_t param_2, uint32_t param_3)
{
    uint32_t* puVar1;
    uint32_t* puVar2;
    int iVar3;
    uint32_t uVar4;
    int* piVar5;
    int iVar6;
    uint32_t uStack_10 = 0;
    uint32_t uStack_c = 0;
    uint32_t uStack_8 = 0;
    uint32_t* local_4 = nullptr;

    piVar5 = (int*)FUN_00538580((void**)&local_4);
    puVar1 = (uint32_t*)*piVar5;
    if (puVar1 != nullptr) {
        puVar1[1] = puVar1[1] + 1;
    }
    if (local_4 != nullptr && (iVar6 = (int)local_4[1], local_4[1] = (uint32_t)(iVar6 - 1), iVar6 - 1 == 0)) {
        (*(void(__cdecl**)(int))local_4)(1);
    }
    iVar6 = FUN_00538680();
    FUN_00552ef0(iVar6, param_1, param_2, param_3);
    puVar2 = *(uint32_t**)(iVar6 + 0x4c);
    if (puVar2 != puVar1) {
        if (puVar2 != nullptr) {
            piVar5 = (int*)puVar2 + 1;
            *piVar5 = *piVar5 + -1;
            if (*piVar5 == 0) {
                (*(void(__cdecl**)(int))puVar2)(1);
            }
        }
        *(uint32_t**)(iVar6 + 0x4c) = puVar1;
        if (puVar1 != nullptr) {
            puVar1[1] = puVar1[1] + 1;
        }
    }
    FUN_005b0280();
    uStack_10 = 0;
    uStack_c = 0;
    iVar3 = *(int*)(iVar6 + 0x4c);
    if (iVar3 != 0) {
        uVar4 = *(uint32_t*)(iVar3 + 0x14);
        if (*(int*)(iVar3 + 0xc) != 0) {
            FUN_00576320(0, uVar4, *(uint32_t*)(iVar3 + 0x10), *(int*)(iVar3 + 0xc), param_1, param_2, &uStack_c, &uStack_10);
            FUN_005b0360(uStack_c, uStack_10, uVar4);
        }
    }
    uStack_8 = 0;
    iVar3 = *(int*)(iVar6 + 0x4c);
    if (iVar3 != 0) {
        if (*(int*)(iVar3 + 0x18) != 0) {
            FUN_00582420(*(uint32_t*)(iVar3 + 0x1c), *(int*)(iVar3 + 0x18), param_1, param_2, &uStack_8, &uStack_10);
            FUN_005b0420(nullptr, (int)uStack_8, (int)uStack_10);
        }
    }
    if (puVar1 != nullptr) {
        piVar5 = (int*)puVar1 + 1;
        *piVar5 = *piVar5 + -1;
        if (*piVar5 == 0) {
            (*(void(__cdecl**)(int))puVar1)(1);
        }
    }
    return iVar6;
}

// 0x5b0b70 — observed shape
uint32_t* FUN_005b0b70(void* self, uint32_t param_1)
{
    int* piVar1;
    uint32_t* puVar2;
    uint32_t* puVar3;
    uint32_t* puVar4;

    puVar3 = (uint32_t*)FUN_00533c78(0x68);
    if (puVar3 == nullptr) {
        puVar3 = nullptr;
    } else {
        FUN_005ae700();
        puVar3[0] = (uint32_t)(intptr_t)&PTR_FUN_006c5c18;
        puVar3[0x13] = 0;
        puVar3[0x14] = 0;
        *(uint8_t*)((char*)puVar3 + 0x16 * 4) = 0;
        puVar3[0x15] = 0xff7fffff;
        puVar3[0x17] = 0;
        puVar3[0x18] = 0;
        puVar3[0x19] = 0;
    }
    FUN_00582080(puVar3, param_1);
    if (*(int**)((char*)self + 0x4c) != nullptr) {
        puVar4 = (uint32_t*)(**(uint32_t*(__cdecl**)(uint32_t))(*(int**)((char*)self + 0x4c) + 8))(param_1);
        puVar2 = (uint32_t*)puVar3[0x13];
        if (puVar2 != puVar4) {
            if (puVar2 != nullptr) {
                piVar1 = (int*)puVar2 + 1;
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    (*(void(__cdecl**)(int))puVar2)(1);
                }
            }
            puVar3[0x13] = (uint32_t)(intptr_t)puVar4;
            if (puVar4 != nullptr) {
                puVar4[1] = puVar4[1] + 1;
            }
        }
        FUN_005b0280();
    }
    return puVar3;
}

// ---- retry batch: 0x5b0c60..0x5b31a0 ----

extern int rand();
extern "C" double fsin(double value);
extern "C" double fcos(double value);
extern "C" double _CIfmod(void);
extern void FUN_00552d20();
extern void FUN_005531c0(int param_1);
extern int FUN_00557b10(uint32_t param_1);
extern void FUN_006b34a0(int param_1);
extern void FUN_005606f0(uint32_t param_1, int* param_2);
extern uint32_t DAT_00728ba8;
extern void FUN_005579c0(void* param_1);
extern void FUN_00548b20(void* param_1, void* param_2);
extern void FUN_005bc490(uint32_t param_1, int param_2, uint32_t param_3);
extern void FUN_005bc560(int param_1);
extern char FUN_005bd960(intptr_t param_1, int* param_2);
extern void FUN_00538400();
extern void FUN_005bc7b0(int param_1);
extern void FUN_00545cc0();
extern void FUN_005bc740(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4);
extern uint32_t PTR_FUN_006c5d44;
extern uint32_t DAT_00727430;
extern uint32_t DAT_00727434;
extern uint32_t DAT_00727438;
extern uint32_t DAT_00727568;
extern float* FUN_00502260(void* param_1, float* param_2);
extern uint32_t* FUN_0053ca60(void* param_1, void* param_2);
extern float _DAT_00727c78;
extern float _DAT_00727c80;
extern void FUN_005bbd20();
extern uint32_t PTR_FUN_006c5de8;
extern void FUN_005bbeb0(void* param_1, uint32_t param_2);
extern int16_t FUN_005f0ddc();
extern void FUN_00555ea0(void* param_1, void* param_2);
extern void FUN_00555e70(float param_1, int param_2);
extern float _DAT_00728bd0;
extern int DAT_00728bd4;

// 0x5b0c60 — observed shape
void FUN_005b0c60(void* self, uint8_t param_1)
{
    FUN_00552d20();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x5b0df0 — observed shape
void FUN_005b0df0(int param_1)
{
    int iVar2;
    uint32_t uVar1;
    int local_1;

    iVar2 = param_1;
    FUN_005531c0(param_1);
    local_1 = FUN_00557b10(DAT_00728ba8);
    uVar1 = *(uint32_t*)(iVar2 + 0xc);
    if (*(uint32_t*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0((int)(*(int*)(iVar2 + 0x14) + uVar1));
    }
    FUN_005606f0(uVar1, &local_1);
    return;
}

// 0x5b0ef0 — observed shape
void FUN_005b0ef0(void* self, uint32_t param_1, int param_2)
{
    float* pfVar1;
    float fVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    uint16_t uVar6;

    uVar6 = 0;
    if (*(int16_t*)(param_2 + 0x44) != 0) {
        do {
            pfVar1 = (float*)(*(int*)(param_2 + 0x50) + (uint32_t)uVar6 * 0x28);
            iVar3 = rand();
            iVar4 = rand();
            iVar5 = rand();
            uVar6 = (uint16_t)(uVar6 + 1);
            fVar2 = *(float*)((char*)self + 0x20);
            *pfVar1 = ((float)iVar3 * 6.103702e-05f - 1.0f) * fVar2 + *pfVar1;
            pfVar1[1] = ((float)iVar4 * 6.103702e-05f - 1.0f) * fVar2 + pfVar1[1];
            pfVar1[2] = fVar2 * ((float)iVar5 * 6.103702e-05f - 1.0f) + pfVar1[2];
        } while (uVar6 < *(uint16_t*)(param_2 + 0x44));
    }
    return;
}

// 0x5b1020 — observed shape
// NEEDS_MANUAL: local_ac/local_a8/local_a4 are read by the range test but never assigned
// anywhere in the listing (Ghidra lost the writer of those three floats).
void FUN_005b1020(void* self, uint32_t param_1, int param_2)
{
    float* pfVar1;
    float* pfVar2;
    float fVar3;
    float fVar4;
    int iVar5;
    int iVar6;
    int iVar7;
    uint16_t uVar8;
    uint32_t* puVar9;
    uint32_t* puVar10;
    uint8_t local_d0[36];
    float local_ac;
    float local_a8;
    float local_a4;
    uint32_t local_9c[13];
    uint32_t local_68[13];
    uint8_t local_34[52];

    puVar9 = (uint32_t*)(*(int*)((char*)self + 0x1c) + 0x6c);
    puVar10 = local_68;
    for (iVar7 = 0xd; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar10 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
    }
    puVar9 = (uint32_t*)(*(int*)((char*)self + 0x14) + 0x6c);
    puVar10 = local_9c;
    for (iVar7 = 0xd; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar10 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
    }
    FUN_005579c0(local_34);
    FUN_00548b20(local_d0, local_68);
    uVar8 = 0;
    if (*(int16_t*)(param_2 + 0x44) != 0) {
        do {
            pfVar1 = (float*)(*(int*)(param_2 + 0x50) + (uint32_t)uVar8 * 0x28);
            pfVar2 = (float*)(*(int*)(param_2 + 0x20) + (uint32_t)uVar8 * 0xc);
            fVar4 = (*pfVar2 - local_ac) * (*pfVar2 - local_ac) +
                    (pfVar2[1] - local_a8) * (pfVar2[1] - local_a8) +
                    (pfVar2[2] - local_a4) * (pfVar2[2] - local_a4);
            fVar3 = *(float*)((char*)self + 0x30);
            if ((!NAN(fVar4) && !NAN(fVar3)) && fVar4 < fVar3 != (fVar4 == fVar3)) {
                iVar7 = rand();
                iVar5 = rand();
                iVar6 = rand();
                fVar3 = *(float*)((char*)self + 0x20);
                *pfVar1 = ((float)iVar7 * 6.103702e-05f - 1.0f) * fVar3 + *pfVar1;
                pfVar1[1] = ((float)iVar5 * 6.103702e-05f - 1.0f) * fVar3 + pfVar1[1];
                pfVar1[2] = fVar3 * ((float)iVar6 * 6.103702e-05f - 1.0f) + pfVar1[2];
            }
            uVar8 = (uint16_t)(uVar8 + 1);
        } while (uVar8 < *(uint16_t*)(param_2 + 0x44));
    }
    return;
}

// 0x5b15a0 — observed shape
void FUN_005b15a0(void* self, uint32_t param_1, int param_2, uint32_t param_3)
{
    float* pfVar1;
    float fVar2;
    float fVar3;
    float fVar4;
    float fVar5;

    pfVar1 = (float*)(*(int*)(param_2 + 0x50) + (param_3 & 0xffff) * 0x28);
    fVar3 = 1.0f / *(float*)((char*)self + 0x38);
    fVar2 = fVar3 * (*(float*)((char*)self + 0x18) - *(float*)((char*)self + 0x40));
    fVar4 = fVar3 * (*(float*)((char*)self + 0x1c) - *(float*)((char*)self + 0x44));
    fVar3 = (*(float*)((char*)self + 0x20) - *(float*)((char*)self + 0x48)) * fVar3;
    fVar5 = fVar2 * *pfVar1 + fVar4 * pfVar1[1] + fVar3 * pfVar1[2];
    fVar2 = fVar2 * fVar5;
    fVar4 = fVar4 * fVar5;
    fVar3 = fVar3 * fVar5;
    fVar5 = *pfVar1 - (fVar2 + fVar2);
    *pfVar1 = fVar5;
    fVar4 = pfVar1[1] - (fVar4 + fVar4);
    pfVar1[1] = fVar4;
    fVar3 = pfVar1[2] - (fVar3 + fVar3);
    pfVar1[2] = fVar3;
    fVar2 = *(float*)((char*)self + 0xc);
    *pfVar1 = fVar5 * fVar2;
    pfVar1[1] = fVar4 * fVar2;
    pfVar1[2] = fVar3 * fVar2;
    FUN_005bc490(param_1, param_2, param_3);
    return;
}

// 0x5b1690 — observed shape
void FUN_005b1690(void* self, int param_1)
{
    int iVar1;
    char cVar2;

    FUN_005bc560(param_1);
    FUN_005bd960((intptr_t)self, &param_1);
    iVar1 = param_1;
    if (*(int*)((char*)self + 0x30) != 0) {
        cVar2 = FUN_005bd960(*(int*)((char*)self + 0x30), &param_1);
        if (cVar2 != '\0') {
            *(int*)(iVar1 + 0x30) = param_1;
            return;
        }
        *(uint32_t*)(iVar1 + 0x30) = *(uint32_t*)((char*)self + 0x30);
    }
    return;
}

// 0x5b16f0 — observed shape
void FUN_005b16f0(void* self)
{
    int* piVar1;
    uint32_t* puVar2;

    puVar2 = *(uint32_t**)((char*)self + 0x2c);
    if (puVar2 != nullptr) {
        piVar1 = (int*)puVar2 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (*(void(__cdecl**)(uint32_t))(*puVar2))(1);
        }
    }
    FUN_00538400();
    return;
}

// 0x5b1a00 — observed shape
void FUN_005b1a00(void* self, int param_1)
{
    FUN_005bc7b0(param_1);
    FUN_00545cc0();
    if (0xa000112 < *(uint32_t*)(param_1 + 0x1c)) {
        (*(void(__cdecl**)(void*, int))(**(int**)(param_1 + 0x15c) + 8))((char*)self + 0x34, 4);
    }
    return;
}

// 0x5b1a70 — observed shape
void FUN_005b1a70(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3,
                 uint32_t param_4, uint32_t param_5, float param_6)
{
    uint32_t* s;
    int iVar1;
    uint32_t* puVar2;
    uint32_t* puVar3;

    s = (uint32_t*)self;
    FUN_005bc740(param_1, param_2, param_3, param_4);
    s[0xd] = 0x3f800000;
    s[0xf] = 0x3f800000;
    *s = (uint32_t)(intptr_t)&PTR_FUN_006c5d44;
    s[0xc] = param_5;
    s[0x10] = DAT_00727430;
    s[0x11] = DAT_00727434;
    s[0x12] = DAT_00727438;
    if (0.0f <= param_6) {
        *(float*)(s + 0xd) = param_6;
    }
    s[0x29] = 0xff7fffff;
    s[0x2a] = 0xff7fffff;
    s[0x2b] = 0xff7fffff;
    s[0x1c] = 0xff7fffff;
    s[0x1d] = 0xff7fffff;
    s[0x1e] = 0xff7fffff;
    puVar2 = &DAT_00727568;
    puVar3 = s + 0x20;
    for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
    }
    puVar2 = s + 0x20;
    puVar3 = s + 0x13;
    for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
    }
    s[0x2c] = 0xff7fffff;
    s[0x1f] = 0xff7fffff;
    return;
}

// 0x5b1d30 — observed shape
void FUN_005b1d30(void* self, uint32_t param_1, float* param_2, uint32_t* param_3)
{
    float fVar1;
    float fVar2;
    int iVar3;
    float* pfVar4;
    uint32_t* puVar5;
    float10 fVar6;
    float10 fVar7;
    float10 fVar8;
    uint8_t local_c[12];

    iVar3 = rand();
    fVar1 = (float)iVar3 * *(float*)((char*)self + 0x54) * 3.051851e-05f;
    iVar3 = rand();
    fVar2 = (float)iVar3 * _DAT_00727c80 * 3.051851e-05f;
    iVar3 = rand();
    fVar6 = (float10)iVar3 * (float10)_DAT_00727c80 * (float10)3.051851e-05f;
    fVar7 = (float10)fsin((double)fVar6);
    fVar8 = (float10)fcos((double)fVar2);
    *param_2 = (float)(fVar8 * fVar7 * (float10)fVar1);
    fVar8 = (float10)fsin((double)fVar2);
    param_2[1] = (float)(fVar8 * fVar7 * (float10)fVar1);
    fVar6 = (float10)fcos((double)fVar6);
    param_2[2] = (float)(fVar6 * (float10)fVar1);
    pfVar4 = FUN_00502260(local_c, param_2);
    *param_2 = *pfVar4;
    param_2[1] = pfVar4[1];
    param_2[2] = pfVar4[2];
    puVar5 = FUN_0053ca60(local_c, param_3);
    *param_3 = *puVar5;
    param_3[1] = puVar5[1];
    param_3[2] = puVar5[2];
    return;
}

// 0x5b2060 — observed shape
uint32_t* FUN_005b2060(void* self, uint32_t param_1)
{
    uint32_t* puVar1;

    puVar1 = (uint32_t*)FUN_00533c78(0x38);
    if (puVar1 == nullptr) {
        puVar1 = nullptr;
    } else {
        FUN_005bbd20();
        *puVar1 = (uint32_t)(intptr_t)&PTR_FUN_006c5de8;
        *(uint16_t*)(puVar1 + 7) = 1;
        puVar1[8] = 0x3f800000;
        *(uint16_t*)(puVar1 + 9) = 1;
        *(uint16_t*)((char*)puVar1 + 0x26) = 1;
        puVar1[10] = 0;
        puVar1[0xb] = 0;
        puVar1[0xc] = 0;
        puVar1[0xd] = 0;
    }
    FUN_005bbeb0(puVar1, param_1);
    *(uint16_t*)(puVar1 + 7) = *(uint16_t*)((char*)self + 0x1c);
    puVar1[8] = *(uint32_t*)((char*)self + 0x20);
    *(uint16_t*)(puVar1 + 9) = *(uint16_t*)((char*)self + 0x24);
    *(uint16_t*)((char*)puVar1 + 0x26) = *(uint16_t*)((char*)self + 0x26);
    puVar1[10] = *(uint32_t*)((char*)self + 0x28);
    puVar1[0xb] = *(uint32_t*)((char*)self + 0x2c);
    puVar1[0xc] = *(uint32_t*)((char*)self + 0x30);
    puVar1[0xd] = *(uint32_t*)((char*)self + 0x34);
    return puVar1;
}

// 0x5b2100 — observed shape
// NEEDS_MANUAL: Ghidra emitted _CIfmod() with no recovered operands; the divisor applied
// to the rand()/FUN_005f0ddc() pair is not present in the listing.
void FUN_005b2100(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, int param_4)
{
    int16_t sVar1;
    uint16_t uVar2;
    int iVar3;
    int* s;
    uint32_t uVar4;
    float10 fVar5;

    s = (int*)self;
    if ((*(uint16_t*)(*(int*)(*(int*)(param_4 + 0xbc) + 0x50) + 0x24 + (param_3 & 0xffff) * 0x28) <
         *(uint16_t*)((char*)s + 0x1c)) &&
        (iVar3 = rand(), (float)iVar3 * 3.051851e-05f <= (float)s[8])) {
        iVar3 = s[9];
        rand();
        sVar1 = FUN_005f0ddc();
        fVar5 = (float10)_CIfmod();
        if ((float10)0.5 < fVar5) {
            sVar1 = (int16_t)(sVar1 + 1);
        }
        uVar2 = (uint16_t)((int16_t)iVar3 + sVar1);
        if (uVar2 == 0) {
            uVar2 = 1;
        }
        uVar4 = (uint32_t)uVar2;
        do {
            (*(void(__cdecl**)(uint32_t, uint32_t, uint32_t, int))(*s + 0x48))
                (param_1, param_2, param_3, param_4);
            uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
    }
    return;
}

// 0x5b2c60 — observed shape
// NEEDS_MANUAL: Ghidra aliased the float accumulator and the object pointer in param_2
// (dereferenced as a pointer and also accumulated as a float); both uses preserved verbatim.
void FUN_005b2c60(void* self, float param_1, float param_2)
{
    int iVar1;
    float fVar2;
    uint16_t uVar3;
    uint8_t local_c[12];

    fVar2 = param_2;
    uVar3 = 0;
    if ((*(int*)((int)param_2 + 0x4c) != 0) && (*(int16_t*)((int)param_2 + 0x44) != 0)) {
        do {
            iVar1 = *(int*)((int)fVar2 + 0x50) + (uint32_t)uVar3 * 0x28;
            FUN_00555ea0(&param_2, local_c);
            param_2 = (param_1 - *(float*)(iVar1 + 0x20)) * *(float*)((char*)self + 0x1c) + param_2;
            if ((DAT_00728bd4 & 1) == 0) {
                _DAT_00728bd0 = _DAT_00727c78 * 10.0f;
                DAT_00728bd4 = DAT_00728bd4 | 1;
            }
            if (param_2 <= _DAT_00728bd0) {
                if (_DAT_00727c80 < param_2) {
                    do {
                        param_2 = param_2 - _DAT_00727c80;
                    } while (_DAT_00727c80 < param_2);
                }
            } else {
                param_2 = 0.0f;
            }
            FUN_00555e70(param_2, iVar1 + 0xc);
            uVar3 = (uint16_t)(uVar3 + 1);
        } while (uVar3 < *(uint16_t*)((int)fVar2 + 0x44));
    }
    return;
}

// 0x5b2d60 — observed shape
void FUN_005b2d60(void* self, int param_1, uint32_t param_2)
{
    int iVar1;
    float fVar2;
    int iVar3;
    float10 fVar4;
    float10 fVar5;

    if (*(int*)(param_1 + 0x4c) != 0) {
        iVar1 = *(int*)(param_1 + 0x50) + (param_2 & 0xffff) * 0x28;
        if (*(char*)((char*)self + 0x20) == '\0') {
            *(uint32_t*)(iVar1 + 0xc) = *(uint32_t*)((char*)self + 0x24);
            *(uint32_t*)(iVar1 + 0x10) = *(uint32_t*)((char*)self + 0x28);
            *(uint32_t*)(iVar1 + 0x14) = *(uint32_t*)((char*)self + 0x2c);
        } else {
            iVar3 = rand();
            fVar4 = (float10)fcos((double)((float10)iVar3 * (float10)_DAT_00727c78 *
                                           (float10)3.051851e-05f));
            fVar2 = (float)SQRT((float10)1.0 - fVar4 * (float10)(float)fVar4);
            iVar3 = rand();
            fVar5 = (float10)_DAT_00727c80;
            *(float*)(iVar1 + 0x14) = (float)fVar4;
            fVar5 = (float10)iVar3 * fVar5 * (float10)3.051851e-05f;
            fVar4 = (float10)fcos((double)fVar5);
            *(float*)(iVar1 + 0xc) = (float)(fVar4 * (float10)fVar2);
            fVar5 = (float10)fsin((double)fVar5);
            *(float*)(iVar1 + 0x10) = (float)(fVar5 * (float10)fVar2);
        }
        FUN_00555e70(0.0f, iVar1 + 0xc);
    }
    return;
}

// 0x5b31a0 — observed shape
void FUN_005b31a0(void* self, float param_1)
{
    char cVar1;

    *(uint8_t*)((char*)self + 0xc) = *(uint8_t*)((char*)self + 0xc) & 0xf9;
    if (*(int*)((char*)self + 0x34) != 0) {
        cVar1 = FUN_00568540(param_1);
        if (cVar1 == '\0') {
            if (*(float*)((char*)self + 0x44) == -3.4028235e+38f) {
                *(uint32_t*)((char*)self + 0x44) = *(uint32_t*)((char*)self + 0x2c);
            }
            if (*(float*)((char*)self + 0x2c) < *(float*)((char*)self + 0x44)) {
                *(uint8_t*)(*(int*)((char*)self + 0x34) + 0xf8) = 1;
            }
            *(uint32_t*)((char*)self + 0x44) = *(uint32_t*)((char*)self + 0x2c);
        }
    }
    return;
}
