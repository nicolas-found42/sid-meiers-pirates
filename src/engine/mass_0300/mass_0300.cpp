#include <cstdint>
#include <cstddef>
#include <cmath>
#include <windows.h>

// ---------------------------------------------------------------------------
// External helpers and globals referenced by the translated listings.
// ---------------------------------------------------------------------------
extern "C" unsigned int _controlfp(unsigned int newValue, unsigned int mask);

static int ftol(double v) { return (int)v; }

extern void FUN_005f8ea2(int param_1);
extern int FUN_00642f7f(uint32_t param_1, uint32_t param_2);
extern int FUN_0064300d(uint32_t param_1, uint32_t param_2);
extern int FUN_00643132(uint32_t param_1, uint32_t param_2);
extern int FUN_00645ebe(int param_1, int param_2, uint16_t param_3, uint32_t param_4,
                        void* param_5, int* param_6, uint32_t param_7);
extern int FUN_00645b25(int param_1, int param_2, uint16_t param_3, uint32_t param_4,
                        void* param_5, int* param_6, uint32_t param_7);
extern int FUN_0060b067(uint32_t param_1, uint32_t param_2, int param_3, int param_4,
                        int param_5, int param_6, int param_7, int param_8,
                        int param_9, uint32_t param_10, int param_11,
                        uint32_t param_12, uint32_t param_13, uint32_t param_14);
extern void FUN_0063e306(int param_1);
extern void FUN_0064405e(int param_1);
extern void FUN_00643bae(int param_1);
extern void FUN_00644fe5(int param_1);
extern int FUN_00643e7a(void* param_1);
extern int FUN_00643f6c(void* param_1);
extern int FUN_0063da83(int param_1, int param_2, int param_3);
extern int FUN_0064369b(void* self, int param_1, int param_2);
extern int FUN_006461c7(uint32_t param_1, uint16_t* param_2);
extern void FUN_0062a186(int param_1);
extern void FUN_00412770(void* param_1, int param_2, uint32_t param_3, void (*param_4)(void*));
extern void FUN_004127b0(void* param_1, int param_2, uint32_t param_3, void* param_4);
extern uint32_t* FUN_00533c78(uint32_t param_1);
extern void operator_delete(void* param_1);

extern uint8_t DAT_006eac9c[];
extern uint8_t LAB_00646b1e[];

// 0x6462f8 — observed shape
int FUN_6462f8(void* self, uint32_t param_1, uint32_t param_2)
{
    int* local_18[3];
    int** local_c;
    uint32_t local_8;
    int iVar3;
    int* piVar1;
    int* piVar2;

    local_18[2] = (int*)((uint32_t)*(uint16_t*)((char*)self + 0x42) * 0xb4 + 0x8c +
                         *(int*)((char*)self + 0xa4));
    local_18[0] = nullptr;
    local_18[1] = nullptr;
    if ((*(uint8_t*)((char*)self + 0x119) & 2) == 0) {
        local_c = local_18;
        local_8 = 0;
        do {
            iVar3 = (*(int (**)(void*))(**(int**)((char*)self + 0xc) + 0xf0))(
                *(void**)((char*)self + 0xc));
            if (iVar3 < 0) goto LAB_00646403;
            FUN_005f8ea2(1);
            iVar3 = FUN_00642f7f(param_1, param_2);
            FUN_005f8ea2(0);
            if (iVar3 < 0) {
                (*(int (**)(void*, int**))(**(int**)((char*)self + 0xc) + 0xf4))(
                    *(void**)((char*)self + 0xc), local_18 + local_8);
                goto LAB_00646403;
            }
            iVar3 = (*(int (**)(void*, int**))(**(int**)((char*)self + 0xc) + 0xf4))(
                *(void**)((char*)self + 0xc), local_c);
            if (iVar3 < 0) goto LAB_00646403;
            local_8 = local_8 + 1;
            local_c = local_c + 1;
        } while (local_8 < 2);
    }
    iVar3 = (*(int (**)(int*))(*local_18[0] + 0x10))(local_18[0]);
    piVar2 = local_18[2];
    if (-1 < iVar3) {
        piVar1 = (int*)*local_18[2];
        if (piVar1 == nullptr) {
            iVar3 = 0;
        } else {
            iVar3 = (*(int (**)(int*))(*piVar1 + 0x14))(piVar1);
        }
        if (-1 < iVar3) {
            iVar3 = (*(int (**)(int*))(*local_18[1] + 0x10))(local_18[1]);
            if (-1 < iVar3) {
                iVar3 = (*(int (**)(int*))(*local_18[0] + 0x14))(local_18[0]);
                if (-1 < iVar3) {
                    piVar1 = (int*)*piVar2;
                    if (piVar1 != nullptr) {
                        (*(int (**)(int*))(*piVar1 + 8))(piVar1);
                        *piVar2 = 0;
                    }
                    *piVar2 = (int)(intptr_t)local_18[1];
                    local_18[1] = nullptr;
                }
            }
        }
    }
LAB_00646403:
    if (local_18[0] != nullptr) {
        (*(int (**)(int*))(*local_18[0] + 8))(local_18[0]);
        local_18[0] = nullptr;
    }
    if (local_18[1] != nullptr) {
        (*(int (**)(int*))(*local_18[1] + 8))(local_18[1]);
    }
    return iVar3;
}

// 0x646429 — observed shape
int FUN_646429(void* self, uint32_t param_1, uint32_t param_2)
{
    int* local_18[3];
    int** local_c;
    uint32_t local_8;
    int iVar3;
    int* piVar1;
    int* piVar2;

    local_18[2] = (int*)((uint32_t)*(uint16_t*)((char*)self + 0x42) * 0xb4 + 0x98 +
                         *(int*)((char*)self + 0xa4));
    local_18[0] = nullptr;
    local_18[1] = nullptr;
    if ((*(uint8_t*)((char*)self + 0x119) & 2) == 0) {
        local_c = local_18;
        local_8 = 0;
        do {
            iVar3 = (*(int (**)(void*))(**(int**)((char*)self + 0xc) + 0xf0))(
                *(void**)((char*)self + 0xc));
            if (iVar3 < 0) goto LAB_00646534;
            FUN_005f8ea2(1);
            iVar3 = FUN_0064300d(param_1, param_2);
            FUN_005f8ea2(0);
            if (iVar3 < 0) {
                (*(int (**)(void*, int**))(**(int**)((char*)self + 0xc) + 0xf4))(
                    *(void**)((char*)self + 0xc), local_18 + local_8);
                goto LAB_00646534;
            }
            iVar3 = (*(int (**)(void*, int**))(**(int**)((char*)self + 0xc) + 0xf4))(
                *(void**)((char*)self + 0xc), local_c);
            if (iVar3 < 0) goto LAB_00646534;
            local_8 = local_8 + 1;
            local_c = local_c + 1;
        } while (local_8 < 2);
    }
    iVar3 = (*(int (**)(int*))(*local_18[0] + 0x10))(local_18[0]);
    piVar2 = local_18[2];
    if (-1 < iVar3) {
        piVar1 = (int*)*local_18[2];
        if (piVar1 == nullptr) {
            iVar3 = 0;
        } else {
            iVar3 = (*(int (**)(int*))(*piVar1 + 0x14))(piVar1);
        }
        if (-1 < iVar3) {
            iVar3 = (*(int (**)(int*))(*local_18[1] + 0x10))(local_18[1]);
            if (-1 < iVar3) {
                iVar3 = (*(int (**)(int*))(*local_18[0] + 0x14))(local_18[0]);
                if (-1 < iVar3) {
                    piVar1 = (int*)*piVar2;
                    if (piVar1 != nullptr) {
                        (*(int (**)(int*))(*piVar1 + 8))(piVar1);
                        *piVar2 = 0;
                    }
                    *piVar2 = (int)(intptr_t)local_18[1];
                    local_18[1] = nullptr;
                }
            }
        }
    }
LAB_00646534:
    if (local_18[0] != nullptr) {
        (*(int (**)(int*))(*local_18[0] + 8))(local_18[0]);
        local_18[0] = nullptr;
    }
    if (local_18[1] != nullptr) {
        (*(int (**)(int*))(*local_18[1] + 8))(local_18[1]);
    }
    return iVar3;
}

// 0x64655a — observed shape
int FUN_64655a(void* self, uint32_t param_1, uint32_t param_2)
{
    int* local_18[3];
    int** local_c;
    uint32_t local_8;
    int iVar3;
    int* piVar1;
    int* piVar2;

    local_18[2] = (int*)((uint32_t)*(uint16_t*)((char*)self + 0x42) * 0xb4 + 0x90 +
                         *(int*)((char*)self + 0xa4));
    local_18[0] = nullptr;
    local_18[1] = nullptr;
    if ((*(uint8_t*)((char*)self + 0x119) & 2) == 0) {
        local_c = local_18;
        local_8 = 0;
        do {
            iVar3 = (*(int (**)(void*))(**(int**)((char*)self + 0xc) + 0xf0))(
                *(void**)((char*)self + 0xc));
            if (iVar3 < 0) goto LAB_00646665;
            FUN_005f8ea2(1);
            iVar3 = FUN_00643132(param_1, param_2);
            FUN_005f8ea2(0);
            if (iVar3 < 0) {
                (*(int (**)(void*, int**))(**(int**)((char*)self + 0xc) + 0xf4))(
                    *(void**)((char*)self + 0xc), local_18 + local_8);
                goto LAB_00646665;
            }
            iVar3 = (*(int (**)(void*, int**))(**(int**)((char*)self + 0xc) + 0xf4))(
                *(void**)((char*)self + 0xc), local_c);
            if (iVar3 < 0) goto LAB_00646665;
            local_8 = local_8 + 1;
            local_c = local_c + 1;
        } while (local_8 < 2);
    }
    iVar3 = (*(int (**)(int*))(*local_18[0] + 0x10))(local_18[0]);
    piVar2 = local_18[2];
    if (-1 < iVar3) {
        piVar1 = (int*)*local_18[2];
        if (piVar1 == nullptr) {
            iVar3 = 0;
        } else {
            iVar3 = (*(int (**)(int*))(*piVar1 + 0x14))(piVar1);
        }
        if (-1 < iVar3) {
            iVar3 = (*(int (**)(int*))(*local_18[1] + 0x10))(local_18[1]);
            if (-1 < iVar3) {
                iVar3 = (*(int (**)(int*))(*local_18[0] + 0x14))(local_18[0]);
                if (-1 < iVar3) {
                    piVar1 = (int*)*piVar2;
                    if (piVar1 != nullptr) {
                        (*(int (**)(int*))(*piVar1 + 8))(piVar1);
                        *piVar2 = 0;
                    }
                    *piVar2 = (int)(intptr_t)local_18[1];
                    local_18[1] = nullptr;
                }
            }
        }
    }
LAB_00646665:
    if (local_18[0] != nullptr) {
        (*(int (**)(int*))(*local_18[0] + 8))(local_18[0]);
        local_18[0] = nullptr;
    }
    if (local_18[1] != nullptr) {
        (*(int (**)(int*))(*local_18[1] + 8))(local_18[1]);
    }
    return iVar3;
}

// 0x64668b — observed shape
void FUN_64668b(void* self, int param_1, int param_2)
{
    int* piVar15 = (int*)((intptr_t)param_1 * 100 + *(int*)((char*)self + 0x2c));
    int iVar14 = (intptr_t)param_2 * 100 + piVar15[1];
    int local_8 = (int)(intptr_t)self;
    int iVar10 = (*(int (**)(void*))(**(int**)(iVar14 + 0x38) + 0xc))(
        *(void**)(iVar14 + 0x38));
    int local_c = *(int*)(iVar10 + 0xc) + *piVar15;
    uint32_t uVar4 = *(uint32_t*)(iVar10 + 4);
    int local_10 = 0;
    int iVar5 = 0;
    int iVar6 = 0;
    int iVar7 = 0;
    int iVar8 = 0;
    int iVar9 = 0;
    int iVar12 = 0;
    uint32_t uVar11;
    uint16_t uVar1;
    int16_t sVar2;
    uint16_t uVar3;
    int* piVar13;

    (void)local_8;
    if ((*(uint8_t*)((char*)self + 0x118) & 1) == 0) {
        uVar11 = _controlfp(0, 0);
        *(uint32_t*)((char*)self + 0x114) = uVar11;
        _controlfp(0, 0x30000);
        *(uint32_t*)((char*)self + 0x118) = *(uint32_t*)((char*)self + 0x118) | 1;
    }
    if (*(int*)(iVar14 + 0x3c) != 0) {
        iVar5 = *piVar15;
        iVar6 = *(int*)(iVar10 + 0x10);
        iVar7 = *(int*)(iVar10 + 0x14);
        iVar8 = *(int*)(iVar10 + 0x18);
        uVar1 = 0;
        if (*(int16_t*)(iVar14 + 0x4e) != 0) {
            do {
                piVar13 = (int*)((uint32_t)uVar1 * 0x20 + *(int*)(iVar14 + 0x34));
                if (*piVar13 != 0) {
                    *piVar13 = piVar13[1];
                    iVar9 = piVar13[4];
                    sVar2 = *(int16_t*)(iVar9 + 4);
                    if (sVar2 == 0) {
                        FUN_00645ebe(piVar13[3],
                                     iVar7 + iVar5 + (uint32_t)*(uint16_t*)(iVar9 + 6) * 8,
                                     *(uint16_t*)(iVar9 + 8), *(uint32_t*)(iVar14 + 0x3c),
                                     (void*)(intptr_t)iVar9, &local_10, 0xffffffff);
                    } else {
                        if (sVar2 == 1) {
                            uVar3 = *(uint16_t*)(iVar9 + 8);
                            iVar12 = (uint32_t)*(uint16_t*)(iVar9 + 6) * 0x20 + iVar8 + iVar5;
                        } else {
                            if (sVar2 != 2) goto LAB_006467bb;
                            uVar3 = *(uint16_t*)(iVar9 + 8);
                            iVar12 = (uint32_t)*(uint16_t*)(iVar9 + 6) * 0x20 + iVar6 + iVar5;
                        }
                        FUN_00645b25(piVar13[3], iVar12, uVar3, *(uint32_t*)(iVar14 + 0x3c),
                                     (void*)(intptr_t)iVar9, &local_10, 0xffffffff);
                    }
                }
            LAB_006467bb:
                uVar1 = uVar1 + 1;
            } while (uVar1 < *(uint16_t*)(iVar14 + 0x4e));
        }
        local_10 = *piVar15 + *(int*)(iVar10 + 0x10);
        param_1 = *(uint32_t*)(iVar10 + 8);
    }
    FUN_0060b067(*(uint32_t*)(iVar14 + 0x40), *(uint32_t*)(iVar14 + 0x44), 0, local_10, 0,
                 local_c, local_c, local_c, 0, (uint32_t)param_1, 0, uVar4, uVar4, uVar4);
}

// 0x64680a — observed shape
int FUN_64680a(void* self, int param_1, uint32_t* param_2)
{
    int* piVar24 = (int*)((intptr_t)param_1 * 100 + *(int*)((char*)self + 0x2c));
    int iVar25 = (int)(intptr_t)param_2 * 100 + piVar24[1];
    int iVar14 = (*(int (**)(void*))(**(int**)(iVar25 + 0x38) + 0xc))(
        *(void**)(iVar25 + 0x38));
    int iVar17 = *piVar24;
    int iVar21 = *(int*)(iVar14 + 0x1c) + iVar17;
    int iVar5 = *(int*)(iVar14 + 0x20);
    int iVar6 = *(int*)(iVar14 + 0x24);
    uint32_t uVar20 = *(uint32_t*)(iVar14 + 0xc);
    uint32_t uVar7 = *(uint32_t*)(iVar14 + 0x10);
    uint32_t uVar8 = *(uint32_t*)(iVar14 + 0x14);
    uint32_t uVar15;
    uint16_t uVar2;
    int16_t sVar3;
    uint16_t uVar4;
    int iVar9 = 0;
    int iVar10 = 0;
    int iVar11 = 0;
    int iVar12 = 0;
    int iVar13 = 0;
    int iVar16 = 0;
    int* piVar22;
    uint32_t* puVar19;
    uint32_t* puVar1;
    int local_c = 0;
    float* pfVar18;
    double* pdVar23;
    float* pfVar26;

    param_2 = nullptr;
    param_1 = 0;
    if ((*(uint8_t*)((char*)self + 0x118) & 1) == 0) {
        uVar15 = _controlfp(0, 0);
        *(uint32_t*)((char*)self + 0x114) = uVar15;
        _controlfp(0, 0x30000);
        *(uint32_t*)((char*)self + 0x118) = *(uint32_t*)((char*)self + 0x118) | 1;
    }
    if (*(int*)(iVar25 + 0x3c) != 0) {
        iVar9 = *piVar24;
        iVar10 = *(int*)(iVar14 + 0x34);
        iVar11 = *(int*)(iVar14 + 0x38);
        iVar12 = *(int*)(iVar14 + 0x3c);
        uVar2 = 0;
        if (*(int16_t*)(iVar25 + 0x4e) != 0) {
            do {
                piVar22 = (int*)((uint32_t)uVar2 * 0x20 + *(int*)(iVar25 + 0x34));
                if (*piVar22 != 0) {
                    *piVar22 = piVar22[1];
                    iVar13 = piVar22[4];
                    sVar3 = *(int16_t*)(iVar13 + 4);
                    if (sVar3 == 0) {
                        FUN_00645ebe(piVar22[3],
                                     iVar11 + iVar9 + (uint32_t)*(uint16_t*)(iVar13 + 6) * 8,
                                     *(uint16_t*)(iVar13 + 8), *(uint32_t*)(iVar25 + 0x3c),
                                     (void*)(intptr_t)iVar13, (int*)&param_2, 0xffffffff);
                    } else {
                        if (sVar3 == 1) {
                            uVar4 = *(uint16_t*)(iVar13 + 8);
                            iVar16 = (uint32_t)*(uint16_t*)(iVar13 + 6) * 0x20 + iVar12 + iVar9;
                        } else {
                            if (sVar3 != 2) goto LAB_00646958;
                            uVar4 = *(uint16_t*)(iVar13 + 8);
                            iVar16 = (uint32_t)*(uint16_t*)(iVar13 + 6) * 0x20 + iVar10 + iVar9;
                        }
                        FUN_00645b25(piVar22[3], iVar16, uVar4, *(uint32_t*)(iVar25 + 0x3c),
                                     (void*)(intptr_t)iVar13, (int*)&param_2, 0xffffffff);
                    }
                }
            LAB_00646958:
                uVar2 = uVar2 + 1;
            } while (uVar2 < *(uint16_t*)(iVar25 + 0x4e));
        }
        param_2 = (uint32_t*)(*piVar24 + *(int*)(iVar14 + 0x34));
        param_1 = *(uint32_t*)(iVar14 + 0x18);
    }
    iVar17 = FUN_0060b067(*(uint32_t*)(iVar25 + 0x40), *(uint32_t*)(iVar25 + 0x44), 0,
                          (int)(intptr_t)param_2, 0, iVar21, iVar6 + iVar17, iVar5 + iVar17, 0,
                          (uint32_t)param_1, 0, uVar20, uVar8, uVar7);
    if (-1 < iVar17) {
        if (*(int*)(iVar14 + 0x4c) != 0) {
            iVar5 = *(int*)(iVar14 + 0x28);
            iVar6 = *piVar24;
            piVar22 = (int*)(*(int*)(iVar14 + 0x5c) + iVar14);
            param_1 = *piVar22;
            piVar22 = piVar22 + 1;
            if (param_1 != 0) {
                do {
                    pfVar18 = (float*)(*piVar22 * 0x10 + iVar5 + iVar6);
                    pdVar23 = (double*)(*piVar22 * 0x20 + iVar21);
                    pfVar26 = pfVar18 + piVar22[1] * 4;
                    for (; pfVar18 < pfVar26; pfVar18 = pfVar18 + 4) {
                        *pfVar18 = (float)*pdVar23;
                        pfVar18[1] = (float)pdVar23[1];
                        pfVar18[2] = (float)pdVar23[2];
                        pfVar18[3] = (float)pdVar23[3];
                        pdVar23 = pdVar23 + 4;
                    }
                    piVar22 = piVar22 + 2;
                    param_1 = param_1 + -1;
                } while (param_1 != 0);
            }
        }
        if (*(int*)(iVar14 + 0x54) != 0) {
            iVar5 = *(int*)(iVar14 + 0x30);
            iVar6 = *piVar24;
            piVar22 = (int*)(*(int*)(iVar14 + 100) + iVar14);
            local_c = *piVar22;
            piVar22 = piVar22 + 1;
            if (local_c != 0) {
                do {
                    uint32_t* puVar19b = (uint32_t*)(*piVar22 * 0x10 + iVar5 + iVar6);
                    puVar19 = puVar19b + piVar22[1] * 4;
                    for (; puVar19b < puVar19; puVar19b = puVar19b + 1) {
                        uVar20 = (uint32_t)ftol((double)*(float*)puVar19b);
                        *puVar19b = uVar20;
                    }
                    piVar22 = piVar22 + 2;
                    local_c = local_c + -1;
                } while (local_c != 0);
            }
        }
        if (*(int*)(iVar14 + 0x50) != 0) {
            iVar5 = *(int*)(iVar14 + 0x2c);
            iVar6 = *piVar24;
            piVar24 = (int*)(*(int*)(iVar14 + 0x60) + iVar14);
            param_2 = (uint32_t*)*piVar24;
            piVar24 = piVar24 + 1;
            if (param_2 != nullptr) {
                do {
                    puVar19 = (uint32_t*)(iVar5 + iVar6 + *piVar24 * 4);
                    puVar1 = puVar19 + piVar24[1];
                    for (; puVar19 < puVar1; puVar19 = puVar19 + 1) {
                        uVar20 = (uint32_t)ftol((double)*(float*)puVar19);
                        *puVar19 = uVar20;
                    }
                    piVar24 = piVar24 + 2;
                    param_2 = (uint32_t*)((intptr_t)param_2 - 1);
                } while (param_2 != nullptr);
            }
        }
    }
    return iVar17;
}

// 0x646ae9 — observed shape
void FUN_646ae9(void* self)
{
    int iVar1;

    if (*(int*)((char*)self + 0x20) != 0) {
        FUN_0064405e(3);
        *(uint32_t*)((char*)self + 0x20) = 0;
    }
    while (*(int*)((char*)self + 0x24) != 0) {
        iVar1 = *(int*)((char*)self + 0x24);
        *(uint32_t*)((char*)self + 0x24) = *(uint32_t*)(iVar1 + 0x24);
        *(uint32_t*)(iVar1 + 0x24) = 0;
        FUN_0063e306(1);
    }
}

// 0x646b6e — observed shape
void FUN_646b6e(void* self)
{
    int* piVar1 = *(int**)((char*)self + 0x38);

    *(uint32_t*)((char*)self + 0x28) = 0;
    *(uint32_t*)((char*)self + 0x2c) = 0;
    if (piVar1 != nullptr) {
        (*(int (**)(int*))(*piVar1 + 8))(piVar1);
        *(uint32_t*)((char*)self + 0x38) = 0;
    }
    if (*(int*)((char*)self + 0x34) != 0) {
        FUN_00643bae(3);
        *(uint32_t*)((char*)self + 0x34) = 0;
    }
    FUN_646ae9(self);
}

// 0x646bc5 — observed shape
void FUN_646bc5(void* self)
{
    uint32_t* puVar1;
    uint32_t* puVar2;
    int local_8;

    *(uint32_t*)((char*)self + 8) = 0xffffffff;
    *(uint32_t*)((char*)self + 0x24) = 0;
    *(uint32_t*)((char*)self + 0x20) = 0;
    *(uint32_t*)((char*)self + 0) = 0;
    *(uint32_t*)((char*)self + 4) = 0;
    *(uint32_t*)((char*)self + 0x10) = 0;
    *(uint32_t*)((char*)self + 0x30) = 0;
    *(uint32_t*)((char*)self + 0x38) = 0;
    *(uint32_t*)((char*)self + 0x40) = 0;
    *(uint32_t*)((char*)self + 0x88) = 0;
    puVar1 = (uint32_t*)((char*)self + 0x94);
    puVar2 = (uint32_t*)((char*)self + 0xa4);
    local_8 = 2;
    do {
        puVar1[2] = 0xffff;
        *puVar2 = 0;
        puVar2[1] = 0;
        *puVar1 = 0;
        puVar1[-2] = 0;
        puVar1 = puVar1 + 1;
        puVar2 = puVar2 + 2;
        local_8 = local_8 + -1;
    } while (local_8 != 0);
}

// 0x646c28 — observed shape
void FUN_646c28(void* self)
{
    int* p = (int*)self;
    int iVar1;
    void* pvVar2;

    if (p[5] != 0) {
        FUN_00644fe5(3);
        p[5] = 0;
    }
    iVar1 = *p;
    if (((((iVar1 == 0) || (iVar1 == 2)) || (iVar1 == 4)) ||
         ((5 < iVar1) && (iVar1 < 0xb))) &&
        (p[3] != 0)) {
        operator_delete((void*)(intptr_t)p[3]);
        p[3] = 0;
    }
    iVar1 = p[6];
    while (iVar1 != 0) {
        pvVar2 = (void*)(intptr_t)p[6];
        p[6] = *(int*)((char*)pvVar2 + 0x18);
        *(uint32_t*)((char*)pvVar2 + 0x18) = 0;
        FUN_646c28(self);
        operator_delete(pvVar2);
        iVar1 = p[6];
    }
}

// 0x646c95 — observed shape
int FUN_646c95(void* self, int param_1, uint16_t* param_2)
{
    int iVar1 = 0;
    int iVar3;
    uint32_t uVar2 = 0;
    uint16_t uVar4;
    uint16_t local_10;
    uint16_t local_e;
    uint16_t local_c;
    uint16_t local_a;

    iVar3 = (uint32_t)*(uint16_t*)((char*)self + 0x42) * 0xb4 + *(int*)((char*)self + 0xa4);
    if ((*(uint32_t*)((char*)self + 0x118) & 8) == 0) {
        return 0;
    }
    if ((*(uint32_t*)((char*)self + 0x118) & 0x10) == 0) goto LAB_00646da6;
    if (*(int*)(iVar3 + 0x94) == 0) {
LAB_00646d13:
        if (*(int*)(iVar3 + 0x9c) == 0) goto LAB_00646d1b;
LAB_00646d20:
        uVar2 = 1;
    } else {
        if ((param_1 == 0) || (*(int*)(iVar3 + 0x9c) != 0)) {
            if ((*param_2 <= *(uint16_t*)(iVar3 + 0xa4)) &&
                ((param_2[1] <= *(uint16_t*)(iVar3 + 0xa6)) &&
                 (param_2[2] <= *(uint16_t*)(iVar3 + 0xa8))))
                goto LAB_00646da6;
            goto LAB_00646d13;
        }
LAB_00646d1b:
        if (param_1 != 0) goto LAB_00646d20;
    }
    local_10 = *(uint16_t*)(iVar3 + 0xa4);
    if (*(uint16_t*)(iVar3 + 0xa4) <= *param_2) {
        local_10 = *param_2;
    }
    local_e = *(uint16_t*)(iVar3 + 0xa6);
    if (*(uint16_t*)(iVar3 + 0xa6) <= param_2[1]) {
        local_e = param_2[1];
    }
    local_c = *(uint16_t*)(iVar3 + 0xa8);
    if (*(uint16_t*)(iVar3 + 0xa8) <= param_2[2]) {
        local_c = param_2[2];
    }
    iVar1 = FUN_006461c7(uVar2, &local_10);
    if (iVar1 < 0) {
        return iVar1;
    }
    *(uint16_t*)(iVar3 + 0xa4) = local_10;
    *(uint16_t*)(iVar3 + 0xa6) = local_e;
    *(uint32_t*)(iVar3 + 0x9c) = uVar2;
    *(uint16_t*)(iVar3 + 0xa8) = local_c;
LAB_00646da6:
    if ((*(int*)(iVar3 + 0x8c) == 0) || (*(uint16_t*)(iVar3 + 0xaa) < param_2[3])) {
        uVar4 = param_2[3];
        if (param_2[3] < *(uint16_t*)(iVar3 + 0xaa)) {
            uVar4 = *(uint16_t*)(iVar3 + 0xaa);
        }
        local_a = uVar4;
        iVar1 = FUN_6462f8(self, 0, (uint32_t)(uintptr_t)&local_10);
        if (-1 < iVar1) {
            *(uint16_t*)(iVar3 + 0xaa) = uVar4;
        }
    }
    return iVar1;
}

// 0x646df0 — observed shape
int FUN_646df0(void* self, int param_1, uint16_t* param_2)
{
    int iVar1 = 0;
    int iVar3;
    uint32_t uVar2 = 0;
    uint16_t uVar4;
    uint16_t local_10;
    uint16_t local_e;
    uint16_t local_c;
    uint16_t local_a;

    iVar3 = (uint32_t)*(uint16_t*)((char*)self + 0x42) * 0xb4 + *(int*)((char*)self + 0xa4);
    if ((*(uint32_t*)((char*)self + 0x118) & 8) == 0) {
        return 0;
    }
    if ((*(uint32_t*)((char*)self + 0x118) & 0x10) == 0) goto LAB_00646f01;
    if (*(int*)(iVar3 + 0x98) == 0) {
LAB_00646e6e:
        if (*(int*)(iVar3 + 0xa0) == 0) goto LAB_00646e76;
LAB_00646e7b:
        uVar2 = 1;
    } else {
        if ((param_1 == 0) || (*(int*)(iVar3 + 0xa0) != 0)) {
            if ((*param_2 <= *(uint16_t*)(iVar3 + 0xac)) &&
                ((param_2[1] <= *(uint16_t*)(iVar3 + 0xae)) &&
                 (param_2[2] <= *(uint16_t*)(iVar3 + 0xb0))))
                goto LAB_00646f01;
            goto LAB_00646e6e;
        }
LAB_00646e76:
        if (param_1 != 0) goto LAB_00646e7b;
    }
    local_10 = *(uint16_t*)(iVar3 + 0xac);
    if (*(uint16_t*)(iVar3 + 0xac) <= *param_2) {
        local_10 = *param_2;
    }
    local_e = *(uint16_t*)(iVar3 + 0xae);
    if (*(uint16_t*)(iVar3 + 0xae) <= param_2[1]) {
        local_e = param_2[1];
    }
    local_c = *(uint16_t*)(iVar3 + 0xb0);
    if (*(uint16_t*)(iVar3 + 0xb0) <= param_2[2]) {
        local_c = param_2[2];
    }
    iVar1 = FUN_646429(self, uVar2, (uint32_t)(uintptr_t)&local_10);
    if (iVar1 < 0) {
        return iVar1;
    }
    *(uint16_t*)(iVar3 + 0xac) = local_10;
    *(uint16_t*)(iVar3 + 0xae) = local_e;
    *(uint32_t*)(iVar3 + 0xa0) = uVar2;
    *(uint16_t*)(iVar3 + 0xb0) = local_c;
LAB_00646f01:
    if ((*(int*)(iVar3 + 0x90) == 0) || (*(uint16_t*)(iVar3 + 0xb2) < param_2[3])) {
        uVar4 = param_2[3];
        if (param_2[3] < *(uint16_t*)(iVar3 + 0xb2)) {
            uVar4 = *(uint16_t*)(iVar3 + 0xb2);
        }
        local_a = uVar4;
        iVar1 = FUN_64655a(self, 0, (uint32_t)(uintptr_t)&local_10);
        if (-1 < iVar1) {
            *(uint16_t*)(iVar3 + 0xb2) = uVar4;
        }
    }
    return iVar1;
}

// 0x646f4b — observed shape
int FUN_646f4b(void* self, int param_1, int param_2, int param_3, uint32_t* param_4)
{
    uint16_t uVar1;
    uint16_t uVar2;
    uint16_t* puVar7;
    int iVar3;
    uint32_t uVar4;
    int* piVar5;
    int* piVar6;
    int local_8 = 0;

    *param_4 = 0;
    piVar5 = (int*)((intptr_t)param_1 * 100 + *(int*)((char*)self + 0x2c));
    if (*(uint16_t*)((char*)piVar5 + 0x18) != 0xffff) {
        piVar6 = (int*)((uint32_t)*(uint16_t*)((char*)piVar5 + 0x18) * 100 + piVar5[1]);
        iVar3 = piVar6[0x16];
        if ((iVar3 == 0xa000000) || (iVar3 == 0xb000000)) {
            iVar3 = *(int*)(piVar6[7] * 4 + *(int*)((char*)self + 0xb0));
            if (*(int*)(iVar3 + 0x40) == 0) {
                iVar3 = *(int*)(*(int*)(iVar3 + 0x30) + piVar6[9] + *(int*)((char*)self + 0x20));
            } else {
                iVar3 = *(int*)(piVar6[7] * 4 + *(int*)((char*)self + 0xb0));
                iVar3 = *(int*)(*(int*)(*(int*)(iVar3 + 0x40) + 8) +
                               *(int*)(*(int*)(iVar3 + 0x30) + piVar6[9] +
                                       *(int*)(*(int*)((char*)self + 0x38) + 0x10)) * 4);
            }
            iVar3 = *(int*)((char*)self + 0x18) + iVar3 * 0x18;
            if ((*(uint32_t*)(iVar3 + 0x14) & 1) != 0) {
                if (*(int*)(iVar3 + 4) == 0) {
                    *(uint32_t*)(iVar3 + 0x14) = *(uint32_t*)(iVar3 + 0x14) | 2;
                    *(uint32_t*)(iVar3 + 0xc) = 0;
                } else {
                    local_8 = FUN_00643e7a((void*)(intptr_t)iVar3);
                    if (local_8 < 0) {
                        return local_8;
                    }
                }
                *(uint32_t*)(iVar3 + 0x14) = *(uint32_t*)(iVar3 + 0x14) & 0xfffffffe;
            }
            if ((*(int*)(iVar3 + 4) != 0) || ((*(uint8_t*)(iVar3 + 0x14) & 2) == 0)) {
                uVar4 = (*(uint32_t (**)(void*))(*(int*)(iVar3 + 8) + 0xc))(
                    *(void**)(iVar3 + 8));
                *param_4 = uVar4;
            }
        } else if (iVar3 == 0xe000000) {
            if (*piVar6 != 0) {
                *piVar6 = piVar6[1];
                local_8 = FUN_64668b(self, param_1,
                                     (int16_t)*(uint16_t*)((char*)piVar5 + 0x18));
                if (local_8 < 0) {
                    return local_8;
                }
                iVar3 = *piVar5;
                {
                    float f = (*(float (**)(void*))(*(int*)(intptr_t)piVar6[0xe] + 0xc))(
                        (void*)(intptr_t)piVar6[0xe]);
                    uVar2 = (uint16_t)ftol((double)f);
                }
                puVar7 = (uint16_t*)(piVar6[0x12] + iVar3);
                if (puVar7[1] != uVar2) {
                    if (*(uint32_t*)(piVar6[3] + 0x10) <= (uint32_t)uVar2) {
                        return -0x7fffbffb;
                    }
                    uVar1 = 0;
                    if (*(int16_t*)((char*)piVar6 + 0x56) != 0) {
                        do {
                            local_8 = FUN_0063da83(
                                (int)((uint32_t)(puVar7[1] - 1) + (uint32_t)*puVar7),
                                -(int)(uint32_t)(param_2 != 0),
                                -(int)(uint32_t)(param_3 != 0));
                            if (local_8 < 0) {
                                return local_8;
                            }
                            uVar1 = uVar1 + 1;
                        } while (uVar1 < *(uint16_t*)((char*)piVar6 + 0x56));
                    }
                    uVar1 = 0;
                    puVar7[1] = uVar2;
                    if (*(int16_t*)((char*)piVar6 + 0x56) != 0) {
                        do {
                            local_8 = FUN_0063da83(
                                (int)((uint32_t)(puVar7[1] - 1) + (uint32_t)*puVar7),
                                (int)(uint32_t)(param_2 != 0),
                                (int)(uint32_t)(param_3 != 0));
                            if (local_8 < 0) {
                                return local_8;
                            }
                            uVar1 = uVar1 + 1;
                        } while (uVar1 < *(uint16_t*)((char*)piVar6 + 0x56));
                    }
                }
            }
            uVar2 = *(uint16_t*)(piVar6[0x12] + *piVar5);
            if (uVar2 != 0) {
                local_8 = FUN_646f4b(self,
                                     (int)(((uint16_t*)(piVar6[0x12] + *piVar5))[1] - 1) +
                                         (uint32_t)uVar2,
                                     param_2, param_3, param_4);
            }
        }
    }
    return local_8;
}

// 0x647193 — observed shape
int FUN_647193(void* self, int param_1, int param_2, int param_3, uint32_t* param_4)
{
    uint16_t uVar1;
    uint16_t uVar2;
    uint16_t* puVar7;
    int iVar3;
    uint32_t uVar4;
    int* piVar5;
    int* piVar6;
    int local_8 = 0;

    *param_4 = 0;
    piVar5 = (int*)((intptr_t)param_1 * 100 + *(int*)((char*)self + 0x2c));
    if (*(uint16_t*)((char*)piVar5 + 0x1a) != 0xffff) {
        piVar6 = (int*)((uint32_t)*(uint16_t*)((char*)piVar5 + 0x1a) * 100 + piVar5[1]);
        iVar3 = piVar6[0x16];
        if ((iVar3 == 0xa000000) || (iVar3 == 0xb000000)) {
            iVar3 = *(int*)(piVar6[7] * 4 + *(int*)((char*)self + 0xb0));
            if (*(int*)(iVar3 + 0x40) == 0) {
                iVar3 = *(int*)(*(int*)(iVar3 + 0x30) + piVar6[9] + *(int*)((char*)self + 0x20));
            } else {
                iVar3 = *(int*)(piVar6[7] * 4 + *(int*)((char*)self + 0xb0));
                iVar3 = *(int*)(*(int*)(*(int*)(iVar3 + 0x40) + 8) +
                               *(int*)(*(int*)(iVar3 + 0x30) + piVar6[9] +
                                       *(int*)(*(int*)((char*)self + 0x38) + 0x10)) * 4);
            }
            iVar3 = *(int*)((char*)self + 0x18) + iVar3 * 0x18;
            if ((*(uint32_t*)(iVar3 + 0x14) & 1) != 0) {
                if (*(int*)(iVar3 + 4) == 0) {
                    *(uint32_t*)(iVar3 + 0x14) = *(uint32_t*)(iVar3 + 0x14) | 2;
                    *(uint32_t*)(iVar3 + 0xc) = 0;
                } else {
                    local_8 = FUN_00643f6c((void*)(intptr_t)iVar3);
                    if (local_8 < 0) {
                        return local_8;
                    }
                }
                *(uint32_t*)(iVar3 + 0x14) = *(uint32_t*)(iVar3 + 0x14) & 0xfffffffe;
            }
            if ((*(int*)(iVar3 + 4) != 0) || ((*(uint8_t*)(iVar3 + 0x14) & 2) == 0)) {
                uVar4 = (*(uint32_t (**)(void*))(*(int*)(iVar3 + 8) + 0xc))(
                    *(void**)(iVar3 + 8));
                *param_4 = uVar4;
            }
        } else if (iVar3 == 0xe000000) {
            if (*piVar6 != 0) {
                *piVar6 = piVar6[1];
                local_8 = FUN_64668b(self, param_1, *(uint16_t*)((char*)piVar5 + 0x1a));
                if (local_8 < 0) {
                    return local_8;
                }
                iVar3 = *piVar5;
                {
                    float f = (*(float (**)(void*))(*(int*)(intptr_t)piVar6[0xe] + 0xc))(
                        (void*)(intptr_t)piVar6[0xe]);
                    uVar2 = (uint16_t)ftol((double)f);
                }
                puVar7 = (uint16_t*)(piVar6[0x12] + iVar3);
                if (puVar7[1] != uVar2) {
                    if (*(uint32_t*)(piVar6[3] + 0x10) <= (uint32_t)uVar2) {
                        return -0x7fffbffb;
                    }
                    uVar1 = 0;
                    if (*(int16_t*)((char*)piVar6 + 0x56) != 0) {
                        do {
                            local_8 = FUN_0063da83(
                                (int)((uint32_t)(puVar7[1] - 1) + (uint32_t)*puVar7),
                                -(int)(uint32_t)(param_2 != 0),
                                -(int)(uint32_t)(param_3 != 0));
                            if (local_8 < 0) {
                                return local_8;
                            }
                            uVar1 = uVar1 + 1;
                        } while (uVar1 < *(uint16_t*)((char*)piVar6 + 0x56));
                    }
                    uVar1 = 0;
                    puVar7[1] = uVar2;
                    if (*(int16_t*)((char*)piVar6 + 0x56) != 0) {
                        do {
                            local_8 = FUN_0063da83(
                                (int)((uint32_t)(puVar7[1] - 1) + (uint32_t)*puVar7),
                                (int)(uint32_t)(param_2 != 0),
                                (int)(uint32_t)(param_3 != 0));
                            if (local_8 < 0) {
                                return local_8;
                            }
                            uVar1 = uVar1 + 1;
                        } while (uVar1 < *(uint16_t*)((char*)piVar6 + 0x56));
                    }
                }
            }
            uVar2 = *(uint16_t*)(piVar6[0x12] + *piVar5);
            if (uVar2 != 0) {
                local_8 = FUN_647193(self,
                                     (int)(((uint16_t*)(piVar6[0x12] + *piVar5))[1] - 1) +
                                         (uint32_t)uVar2,
                                     param_2, param_3, param_4);
            }
        }
    }
    return local_8;
}

// 0x6473db — observed shape
int FUN_6473db(int* param_1, uint32_t* param_2, uint32_t param_3)
{
    int* piVar1;
    int iVar2;
    int iVar5;
    int iVar6;
    int* piVar3;
    uint32_t uVar4;
    uint32_t* puVar7;
    int local_8 = 0;

    iVar2 = param_1[2];
    param_1[2] = param_1[3];
    if (param_1[0xf] == 4) {
        local_8 = -0x7789f794;
    } else if ((param_3 & 7) == param_3) {
        iVar6 = (uint32_t)*(uint16_t*)((char*)param_1 + 0x42) * 0xb4 + param_1[0x29];
        uVar4 = ~(param_3 << 3) & 8;
        param_1[0x46] = ((uint32_t)((param_3 & 5) == 0) << 1 |
                         (uint32_t)((param_3 & 3) == 0)) << 4 |
                        uVar4 | param_1[0x46] & 0xffffffc7U;
        if (uVar4 != 0) {
            local_8 = FUN_646c95(param_1, *(uint32_t*)(iVar6 + 0x9c),
                                 (uint16_t*)(iVar6 + 0xa4));
            if ((((local_8 < 0) ||
                  (local_8 = FUN_646df0(param_1, *(uint32_t*)(iVar6 + 0xa0),
                                        (uint16_t*)(iVar6 + 0xac)),
                   local_8 < 0)) ||
                 (((*(uint8_t*)((char*)param_1 + 0x118) & 0x10) != 0 &&
                   ((local_8 = (*(int (**)(void*))(**(int**)(iVar6 + 0x94) + 0x10))(
                         *(void**)(iVar6 + 0x94)),
                     local_8 < 0 ||
                         (local_8 = (*(int (**)(void*))(**(int**)(iVar6 + 0x98) + 0x10))(
                              *(void**)(iVar6 + 0x98)),
                          local_8 < 0)))))) ||
                (((*(uint8_t*)((char*)param_1 + 0x118) & 0x20) != 0 &&
                  ((local_8 = (*(int (**)(void*))(**(int**)(iVar6 + 0x8c) + 0x10))(
                        *(void**)(iVar6 + 0x8c)),
                    local_8 < 0 ||
                        (local_8 = (*(int (**)(void*))(**(int**)(iVar6 + 0x90) + 0x10))(
                             *(void**)(iVar6 + 0x90)),
                         local_8 < 0)))))) {
                goto LAB_0064766a;
            }
            if (*(int*)(iVar6 + 0x88) == 0) {
                puVar7 = (uint32_t*)(iVar6 + 0x44);
                for (iVar5 = 0x11; iVar5 != 0; iVar5 = iVar5 + -1) {
                    *puVar7 = 0;
                    puVar7 = puVar7 + 1;
                }
                puVar7 = *(uint32_t**)(iVar6 + 0x40);
                for (uVar4 = (uint32_t)*(uint16_t*)(iVar6 + 0x3c) * 0x68 >> 2; uVar4 != 0;
                     uVar4 = uVar4 - 1) {
                    *puVar7 = 0;
                    puVar7 = puVar7 + 1;
                }
                for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
                    *(uint8_t*)puVar7 = 0;
                    puVar7 = (uint32_t*)((intptr_t)puVar7 + 1);
                }
                local_8 = (*(int (**)(void*))(*(int*)param_1[3] + 0xf0))(
                    (void*)param_1[3]);
                if (local_8 < 0) goto LAB_0064766a;
                param_1[0xf] = 1;
                FUN_005f8ea2(1);
                uVar4 = 0;
                if (*(int*)(iVar6 + 0x34) != 0) {
                    do {
                        (*(void (**)(int*, uint32_t))(*param_1 + 0x108))(param_1, uVar4);
                        (*(void (**)(int*))(*param_1 + 0x110))(param_1);
                        uVar4 = uVar4 + 1;
                    } while (uVar4 < *(uint32_t*)(iVar6 + 0x34));
                }
                FUN_005f8ea2(0);
                piVar1 = (int*)(iVar6 + 0x88);
                local_8 = (*(int (**)(void*, int*))(*(int*)param_1[3] + 0xf4))(
                    (void*)param_1[3], piVar1);
                if (local_8 < 0) {
                    piVar3 = (int*)*piVar1;
                    if (piVar3 != nullptr) {
                        (*(int (**)(int*))(*piVar3 + 8))(piVar3);
                        *piVar1 = 0;
                    }
                    goto LAB_0064766a;
                }
                param_1[0xf] = 0;
                if ((*(uint16_t*)((char*)param_1 + 0x44) != 0xffff) &&
                    (local_8 = FUN_0063da83(
                         (int)*(uint16_t*)((uint32_t)*(uint16_t*)((char*)param_1 + 0x44) * 0x38 +
                                           0x34 + *(int*)(iVar6 + 0x38)),
                         0xffffffff,
                         ((int16_t)param_1[0x10] != *(int16_t*)((char*)param_1 + 0x42)) - 1),
                     local_8 < 0)) {
                    goto LAB_0064766a;
                }
                *(uint16_t*)((char*)param_1 + 0x44) = 0xffff;
            }
            local_8 = (*(int (**)(void*))(**(int**)(iVar6 + 0x88) + 0x10))(
                *(void**)(iVar6 + 0x88));
            if (local_8 < 0) goto LAB_0064766a;
        }
        puVar7 = (uint32_t*)(iVar6 + 0x44);
        for (iVar5 = 0x11; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar7 = 0;
            puVar7 = puVar7 + 1;
        }
        puVar7 = *(uint32_t**)(iVar6 + 0x40);
        for (uVar4 = (uint32_t)*(uint16_t*)(iVar6 + 0x3c) * 0x68 >> 2; uVar4 != 0;
             uVar4 = uVar4 - 1) {
            *puVar7 = 0;
            puVar7 = puVar7 + 1;
        }
        for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
            *(uint8_t*)puVar7 = 0;
            puVar7 = (uint32_t*)((intptr_t)puVar7 + 1);
        }
        if (param_2 != nullptr) {
            *param_2 = *(uint32_t*)(iVar6 + 0x34);
        }
        if (param_1[0xe] != 0) {
            piVar1 = (int*)(param_1[0xe] + 8);
            *piVar1 = *piVar1 + 1;
            *(int**)(param_1[0xe] + 0xc) = param_1;
        }
        param_1[0xf] = 4;
    } else {
        local_8 = -0x7789f794;
    }
LAB_0064766a:
    param_1[2] = iVar2;
    return local_8;
}

// 0x647678 — observed shape
int FUN_647678(void* self, uint32_t param_1, uint32_t param_2)
{
    int* piVar1;
    int iVar2;
    float fVar3;
    float* pfVar4;
    uint32_t uVar5 = 0;
    uint32_t uVar6 = 0;
    uint32_t uVar13;
    float* pfVar7;
    float* pfVar8;
    int iVar9;
    float* pfVar10;
    uint32_t* puVar11;
    uint32_t* puVar12;
    double fVar14;
    double fVar15;
    double fVar16;
    float local_1c[4];
    int* local_c;
    int local_8 = 0;

    local_c = (int*)((intptr_t)param_1 * 100 + *(int*)((char*)self + 0x2c));
    iVar9 = (int)(intptr_t)param_2 * 100 + local_c[1];
    if ((*(uint8_t*)(iVar9 + 0x30) & 4) == 0) {
        if (*(int*)(iVar9 + 0x38) != 0) {
            local_8 = FUN_64668b(self, (int)param_1, (int)param_2);
            if (local_8 < 0) {
                return local_8;
            }
            local_8 = FUN_0064369b(self, (int)param_1, (int)param_2);
            if (local_8 < 0) {
                return local_8;
            }
        }
    } else {
        uVar6 = *(uint32_t*)(iVar9 + 0x60);
        puVar11 = *(uint32_t**)(iVar9 + 0x5c);
        puVar12 = *(uint32_t**)(iVar9 + 8);
        for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar12 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar12 = puVar12 + 1;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
            *(uint8_t*)puVar12 = *(uint8_t*)puVar11;
            puVar11 = (uint32_t*)((intptr_t)puVar11 + 1);
            puVar12 = (uint32_t*)((intptr_t)puVar12 + 1);
        }
    }
    pfVar7 = (float*)(*(int*)(iVar9 + 0x48) + *local_c);
    pfVar10 = *(float**)(iVar9 + 8);
    iVar2 = (uint32_t)*(uint16_t*)(iVar9 + 0x52) * 0x1c;
    piVar1 = *(int**)(iVar9 + 0xc);
    iVar9 = *piVar1;
    if (*(int*)(DAT_006eac9c + iVar2) == 3) {
        if (iVar9 == 1) {
            param_2 = (uint32_t)piVar1[5];
            uVar6 = (uint32_t)piVar1[6];
            if (uVar6 == 1) {
                uVar6 = 0x10;
                if (param_2 < 0x11) {
                    uVar6 = param_2;
                }
                if (uVar6 == 0) {
                    return local_8;
                }
                iVar9 = (int)(intptr_t)pfVar10 - (int)(intptr_t)pfVar7;
                do {
                    *pfVar7 = (float)*(int*)((intptr_t)pfVar7 + iVar9);
                    pfVar7 = pfVar7 + 1;
                    uVar6 = uVar6 - 1;
                } while (uVar6 != 0);
                return local_8;
            }
            if (4 < param_2) {
                param_2 = 4;
            }
            param_1 = 4;
            if (uVar6 < 5) {
                param_1 = uVar6;
            }
            if (param_2 == 0) {
                return local_8;
            }
            do {
                if (param_1 != 0) {
                    pfVar4 = pfVar10;
                    pfVar8 = pfVar7;
                    uVar5 = param_1;
                    do {
                        fVar3 = *pfVar4;
                        pfVar4 = pfVar4 + 1;
                        *pfVar8 = (float)(int)fVar3;
                        pfVar8 = pfVar8 + 1;
                        uVar5 = uVar5 - 1;
                    } while (uVar5 != 0);
                }
                pfVar7 = pfVar7 + 4;
                pfVar10 = pfVar10 + uVar6;
                param_2 = param_2 - 1;
            } while (param_2 != 0);
            return local_8;
        }
        if (iVar9 != 2) {
            if (iVar9 != 3) {
                return -0x7fffbffb;
            }
            local_c = (int*)piVar1[5];
            uVar6 = (uint32_t)piVar1[6];
            if (uVar6 == 1) {
                uVar6 = 0x10;
                if ((intptr_t)local_c < 0x11) {
                    uVar6 = (uint32_t)(intptr_t)local_c;
                }
                if (uVar6 == 0) {
                    return local_8;
                }
                iVar9 = (int)(intptr_t)pfVar10 - (int)(intptr_t)pfVar7;
                do {
                    *pfVar7 = *(float*)(iVar9 + (int)(intptr_t)pfVar7);
                    pfVar7 = pfVar7 + 1;
                    uVar6 = uVar6 - 1;
                } while (uVar6 != 0);
                return local_8;
            }
            if ((intptr_t)local_c > 4) {
                local_c = (int*)4;
            }
            param_1 = 4;
            if (uVar6 < 5) {
                param_1 = uVar6;
            }
            if (local_c == (int*)0x0) {
                return local_8;
            }
            do {
                if (param_1 != 0) {
                    param_2 = param_1;
                    pfVar4 = pfVar10;
                    pfVar8 = pfVar7;
                    do {
                        *pfVar8 = *pfVar4;
                        pfVar4 = pfVar4 + 1;
                        pfVar8 = pfVar8 + 1;
                        param_2 = param_2 - 1;
                    } while (param_2 != 0);
                }
                pfVar7 = pfVar7 + 4;
                pfVar10 = pfVar10 + uVar6;
                local_c = (int*)((intptr_t)local_c - 1);
            } while (local_c != (int*)0x0);
            return local_8;
        }
        uVar6 = (uint32_t)piVar1[5];
        uVar5 = (uint32_t)piVar1[6];
        if (uVar5 == 1) {
            if (uVar6 == 1) {
                if ((*(int*)(DAT_006eac9c + iVar2 + 4) == 1) &&
                    (*(int*)(DAT_006eac9c + iVar2 + 8) == 4)) {
                    uint32_t bits = *(uint32_t*)pfVar10;
                    pfVar7[0] = (float)((bits >> 0x10) & 0xff) * 0.003921569;
                    pfVar7[1] = (float)((bits >> 8) & 0xff) * 0.003921569;
                    pfVar7[2] = (float)(bits & 0xff) * 0.003921569;
                    pfVar7[3] = (float)(bits >> 0x18) * 0.003921569;
                    return local_8;
                }
            } else if (0x10 < uVar6) {
                uVar6 = 0x10;
            }
            if (uVar6 == 0) {
                return local_8;
            }
            iVar9 = (int)(intptr_t)pfVar10 - (int)(intptr_t)pfVar7;
            do {
                *pfVar7 = (float)*(int*)((intptr_t)pfVar7 + iVar9);
                pfVar7 = pfVar7 + 1;
                uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
            return local_8;
        }
        param_2 = 4;
        if (uVar6 < 5) {
            param_2 = uVar6;
        }
        param_1 = 4;
        if (uVar5 < 5) {
            param_1 = uVar5;
        }
        if (param_2 == 0) {
            return local_8;
        }
        do {
            if (param_1 != 0) {
                pfVar4 = pfVar10;
                pfVar8 = pfVar7;
                uVar6 = param_1;
                do {
                    fVar3 = *pfVar4;
                    pfVar4 = pfVar4 + 1;
                    *pfVar8 = (float)(int)fVar3;
                    pfVar8 = pfVar8 + 1;
                    uVar6 = uVar6 - 1;
                } while (uVar6 != 0);
            }
            pfVar7 = pfVar7 + 4;
            pfVar10 = pfVar10 + uVar5;
            param_2 = param_2 - 1;
        } while (param_2 != 0);
        return local_8;
    }
    if (*(int*)(DAT_006eac9c + iVar2) != 0xf20000) {
        return -0x7fffbffb;
    }
    local_1c[0] = 0.0f;
    local_1c[1] = 0.0f;
    local_1c[2] = 0.0f;
    local_1c[3] = 0.0f;
    if (iVar9 == 1) {
        uVar6 = (uint32_t)piVar1[5];
        if (uVar6 == 1) goto LAB_00647833;
        uVar5 = 4;
        if (uVar6 < 5) {
            uVar5 = uVar6;
        }
        uVar6 = 0;
        if (uVar5 != 0) {
            do {
                uVar13 = uVar6 + 1;
                local_1c[uVar6] = (float)(int)pfVar10[uVar6];
                uVar6 = uVar13;
            } while (uVar13 < uVar5);
        }
    } else if (iVar9 == 2) {
        uVar6 = (uint32_t)piVar1[5];
        if (uVar6 == 1) goto LAB_00647833;
        uVar5 = 4;
        if (uVar6 < 5) {
            uVar5 = uVar6;
        }
        uVar6 = 0;
        if (uVar5 != 0) {
            do {
                uVar13 = uVar6 + 1;
                local_1c[uVar6] = (float)(int)pfVar10[uVar6];
                uVar6 = uVar13;
            } while (uVar13 < uVar5);
        }
    } else {
        if (iVar9 != 3) {
            return -0x7fffbffb;
        }
        uVar6 = (uint32_t)piVar1[5];
        if (uVar6 == 1) {
            fVar3 = (float)ftol((double)*pfVar10);
            goto LAB_00647835;
        }
        if (4 < uVar6) {
            uVar6 = 4;
        }
        if (uVar6 != 0) {
            pfVar4 = local_1c;
            for (; uVar6 != 0; uVar6 = uVar6 - 1) {
                *pfVar4 = *pfVar10;
                pfVar10 = pfVar10 + 1;
                pfVar4 = pfVar4 + 1;
            }
        }
    }
    fVar14 = 1.0;
    uVar6 = 0xff;
    fVar15 = 0.0;
    if ((double)local_1c[0] < fVar14) {
        fVar16 = (double)local_1c[0];
        if (std::isnan(fVar16) || std::isnan(fVar15) ||
            (fVar16 < fVar15) == (fVar16 == fVar15)) {
            param_1 = (uint32_t)ftol(fVar16);
        } else {
            param_1 = 0;
        }
    } else {
        param_1 = 0xff;
    }
    if ((double)local_1c[1] < fVar14) {
        fVar16 = (double)local_1c[1];
        if (std::isnan(fVar16) || std::isnan(fVar15) ||
            (fVar16 < fVar15) == (fVar16 == fVar15)) {
            uVar5 = (uint32_t)ftol(fVar16);
        } else {
            uVar5 = 0;
        }
    } else {
        uVar5 = uVar6;
    }
    if ((double)local_1c[2] < fVar14) {
        fVar16 = (double)local_1c[2];
        if (std::isnan(fVar16) || std::isnan(fVar15) ||
            (fVar16 < fVar15) == (fVar16 == fVar15)) {
            uVar13 = (uint32_t)ftol(fVar16);
        } else {
            uVar13 = 0;
        }
    } else {
        uVar13 = 0xff;
    }
    if ((double)local_1c[3] < fVar14) {
        if (std::isnan(local_1c[3]) ||
            (local_1c[3] < 0.0f) == (local_1c[3] == 0.0f)) {
            uVar6 = (uint32_t)ftol((double)local_1c[3]);
        } else {
            uVar6 = 0;
        }
    }
    fVar3 = (float)(((uVar6 << 8 | param_1) << 8 | uVar5) << 8 | uVar13);
    goto LAB_00647835;
LAB_00647833:
    fVar3 = *pfVar10;
LAB_00647835:
    *pfVar7 = fVar3;
    return local_8;
}

// 0x647b53 — observed shape
void FUN_647b53(void* self)
{
    int iVar1 = *(int*)((char*)self + 0x3c);
    void* pvVar2;

    while (iVar1 != 0) {
        pvVar2 = *(void**)((char*)self + 0x3c);
        *(uint32_t*)((char*)self + 0x3c) = *(uint32_t*)((char*)pvVar2 + 0x3c);
        *(uint32_t*)((char*)pvVar2 + 0x3c) = 0;
        FUN_647b53(self);
        operator_delete(pvVar2);
        iVar1 = *(int*)((char*)self + 0x3c);
    }
    if (*(int*)((char*)self + 0x40) != 0) {
        FUN_0062a186(1);
        *(uint32_t*)((char*)self + 0x40) = 0;
    }
    FUN_646ae9(self);
}

// 0x647b9b — observed shape
void FUN_647b9b(void* self, uint8_t param_1)
{
    FUN_647b53(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x647bbc — observed shape
void FUN_647bbc(void* self, uint8_t param_1)
{
    if ((param_1 & 2) == 0) {
        FUN_646b6e(self);
        if ((param_1 & 1) != 0) {
            operator_delete(self);
        }
    } else {
        FUN_00412770(self, 100, *(uint32_t*)((char*)self - 4), FUN_646b6e);
        if ((param_1 & 1) != 0) {
            operator_delete((void*)((intptr_t)self - 4));
        }
    }
}

// 0x647c0a — observed shape
uint32_t FUN_647c0a(void* self, uint16_t param_1)
{
    uint32_t* puVar1;
    uint32_t uVar2;
    uint32_t* puVar3;

    if (*(uint16_t*)((char*)self + 0x38) < param_1) {
        uVar2 = (uint32_t)param_1;
        puVar1 = (uint32_t*)FUN_00533c78(uVar2 * 100 + 4);
        if (puVar1 == nullptr) {
            puVar3 = nullptr;
        } else {
            puVar3 = puVar1 + 1;
            *puVar1 = uVar2;
            FUN_004127b0(puVar3, 100, uVar2, (void*)LAB_00646b1e);
        }
        if (puVar3 == nullptr) {
            return 0x8007000e;
        }
        if (*(int*)((char*)self + 4) != 0) {
            FUN_647bbc(self, 3);
            *(uint32_t*)((char*)self + 4) = 0;
        }
        *(uint32_t**)((char*)self + 4) = puVar3;
        *(uint16_t*)((char*)self + 0x38) = param_1;
    }
    *(uint16_t*)((char*)self + 0x36) = param_1;
    return 0;
}

// 0x647c8a — observed shape
void FUN_647c8a(void* self)
{
    if (*(int*)((char*)self + 0x30) != 0) {
        FUN_647b9b(self, 1);
        *(uint32_t*)((char*)self + 0x30) = 0;
    }
    FUN_646ae9(self);
}
