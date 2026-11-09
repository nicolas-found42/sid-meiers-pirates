#include <cstdint>
#include <cstddef>
#include <cmath>
#include <windows.h>

// ---------------------------------------------------------------------------
// External helpers and globals referenced by the translated listings.
// ---------------------------------------------------------------------------
extern int  FUN_0065d0b4(int size = 0);
extern int  FUN_0065cc1a(void);
extern int  FUN_0065d0ff(int param_1, int param_2, int param_3, int param_4);
extern int  FUN_0065cc50(void);
extern int  FUN_0065cc50(int param_1);
extern int  FUN_0065d97c(void* param_1, int param_2, int param_3, int param_4);
extern int  FUN_0065d9d5(int param_1, int param_2, int param_3, double param_4);
extern void FUN_00614343(void);
extern void FUN_00614343(int param_1);
extern int  FUN_0065d8c2(void);
extern void* FUN_0065d097(int param_1);
extern void FUN_0065d501(void);
extern int  FUN_0065d501(int param_1);
extern int  FUN_0065d35e(void);
extern int  FUN_0065d35e(int param_1);
extern int  FUN_0065d612(int param_1);
extern int  FUN_005f6015(void);
extern void FUN_006626da(void);
extern int  FUN_0065db2e(void* param_1);
extern int  FUN_0069ec6d(int* param_1, int* param_2, int param_3);
extern int  FUN_00675ec3(int param_1, int param_2, int param_3, int param_4, int param_5,
                         int* param_6);
extern int  FUN_00694b7c(uint32_t* param_1, void* param_2, void* param_3, uint32_t* param_4,
                         void* param_5, void* param_6, int param_7, int param_8);
extern uint32_t FUN_673e69(int param_1, int* param_2, uint32_t param_3);
extern uint32_t FUN_673ec4(void* self, int param_1);
extern uint32_t FUN_67576a(int param_1, uint32_t param_2);
extern int  FUN_00533c78(int size);
extern void operator_delete(void* p);

extern uint32_t DAT_006c3b94;
extern int      DAT_007203c0;
extern uint32_t DAT_00720400;
extern void*    PTR_DAT_00720340;
extern void*    PTR_DAT_00720364;
extern int      DAT_006ee918;
extern int      DAT_006ee978;

// 0x6736a9 — observed shape
int FUN_6736a9(void* self)
{
    int iVar1;
    int iVar2;
    uint32_t uVar3;
    int iVar4;
    uint32_t uVar5;
    uint32_t* puVar6;
    uint32_t* puVar7;
    bool bVar8;
    uint32_t local_10;
    int* local_c;
    int local_8;

    if ((**(uint32_t**)((char*)self + 0x100) & 0xfff00000) == 0x10100000) {
        iVar1 = *(int*)((char*)self + 0x14);
        uVar5 = **(uint32_t**)((char*)self + 0x100) & 0xfffff;
        bVar8 = (*(uint32_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                   *(int*)(*(int*)(iVar1 + *(int*)(*(uint32_t**)((char*)self + 0x100))[2] * 4) + 4) * 4) + 4) &
                 0x200) != 0;
        if (((*(uint8_t*)((char*)self + 0x6e) & 2) != 0) && (uVar5 != 0)) {
            local_c = (int*)(*(uint32_t**)((char*)self + 0x100))[2];
            local_10 = uVar5;
            do {
                iVar2 = *(int*)(iVar1 + *local_c * 4);
                if ((*(uint32_t*)(iVar2 + 0x3c) & 0x200) != 0) {
                    bVar8 = true;
                }
                if (*(int*)(iVar2 + 0x38) != -1) {
                    iVar2 = *(int*)(iVar1 + *(int*)(iVar2 + 0x38) * 4);
                }
                if ((*(uint32_t*)(iVar2 + 0x3c) & 0x200) != 0) {
                    bVar8 = true;
                }
                local_c = local_c + 1;
                local_10 = local_10 - 1;
            } while (local_10 != 0);
        }
        if (bVar8) {
            iVar1 = FUN_0065d0b4();
            if (iVar1 == 0) {
                local_8 = 0;
            }
            else {
                local_8 = FUN_0065cc1a();
            }
            if (local_8 == 0) {
                iVar1 = -0x7ff8fff2;
            }
            else {
                iVar1 = FUN_0065d0ff(uVar5 | 0x20500000, uVar5 * 2, uVar5, 0);
                if ((-1 < iVar1) && (iVar1 = FUN_0065cc50(), -1 < iVar1)) {
                    iVar1 = FUN_0065d97c(&DAT_006c3b94, 0x311, 1, 4);
                    if ((iVar1 == -1) ||
                        (iVar1 = FUN_0065d9d5(iVar1, 0, 0, 0xbff0000000000000), iVar1 == -1)) {
                        iVar1 = -0x7ff8fff2;
                    }
                    else {
                        iVar2 = uVar5 << 2;
                        puVar6 = *(uint32_t**)(*(int*)((char*)self + 0x100) + 8);
                        puVar7 = *(uint32_t**)(local_8 + 8);
                        for (uVar3 = uVar5; uVar3 != 0; uVar3 = uVar3 - 1) {
                            *puVar7 = *puVar6;
                            puVar6 = puVar6 + 1;
                            puVar7 = puVar7 + 1;
                        }
                        for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
                            *(uint8_t*)puVar7 = *(uint8_t*)puVar6;
                            puVar6 = (uint32_t*)((int)puVar6 + 1);
                            puVar7 = (uint32_t*)((int)puVar7 + 1);
                        }
                        puVar6 = *(uint32_t**)(*(int*)((char*)self + 0x100) + 0x10);
                        puVar7 = *(uint32_t**)(local_8 + 0x10);
                        for (uVar3 = uVar5; uVar3 != 0; uVar3 = uVar3 - 1) {
                            *puVar7 = *puVar6;
                            puVar6 = puVar6 + 1;
                            puVar7 = puVar7 + 1;
                        }
                        for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
                            *(uint8_t*)puVar7 = *(uint8_t*)puVar6;
                            puVar6 = (uint32_t*)((int)puVar6 + 1);
                            puVar7 = (uint32_t*)((int)puVar7 + 1);
                        }
                        for (; uVar5 != 0; uVar5 = uVar5 - 1) {
                            *(int*)(iVar2 + *(int*)(local_8 + 8)) = iVar1;
                            iVar2 = iVar2 + 4;
                        }
                        iVar1 = 0;
                        if (*(int*)(*(int*)((char*)self + 0x18) +
                                    *(int*)((char*)self + 0xfc) * 4) != 0) {
                            FUN_00614343();
                        }
                        *(int*)(*(int*)((char*)self + 0x18) +
                                *(int*)((char*)self + 0xfc) * 4) = local_8;
                        local_8 = 0;
                    }
                }
                if (local_8 != 0) {
                    FUN_00614343();
                }
            }
        }
        else {
            iVar1 = 0;
        }
    }
    else {
        iVar1 = 0;
    }
    return iVar1;
}

// 0x6738a3 — observed shape
uint32_t FUN_6738a3(void* self)
{
    int* piVar1;
    bool bVar2;
    bool bVar3;
    int* piVar4;
    int* piVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    int iVar8;
    int local_24;
    int local_20;
    int* local_1c;
    int* local_18;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;

    piVar1 = *(int**)(*(int*)((char*)self + 0x230) +
                      -4 + *(int*)((char*)self + 0x224) * 4);
    if ((piVar1 != (int*)0x0) && (*piVar1 == 0x10000004)) {
        uVar7 = 0;
        do {
            iVar8 = *(int*)(*(int*)((char*)self + 0x14) +
                            *(int*)(uVar7 + piVar1[4]) * 4);
            if (*(int*)(iVar8 + 4) != *(int*)((char*)self + 0x84)) {
                return 0;
            }
            if (*(int*)(iVar8 + 0x3c) != 0) {
                return 0;
            }
            if ((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                             *(int*)(uVar7 + piVar1[2]) * 4) + 0x3e) & 0x1f) != 0) {
                return 0;
            }
            uVar7 = uVar7 + 4;
        } while (uVar7 < 0x10);
        local_c = 0;
        local_1c = (int*)piVar1[2];
        local_8 = *(int*)((char*)self + 0x224) - 1;
        bVar3 = true;
        do {
            uVar7 = 0;
            bVar2 = false;
            if (local_8 != 0) {
                local_18 = *(int**)((char*)self + 0x230);
                do {
                    piVar4 = (int*)*local_18;
                    if ((piVar4 != (int*)0x0) && (*piVar4 != 0)) {
                        iVar8 = piVar4[3];
                        if (iVar8 != 0) {
                            piVar4 = (int*)piVar4[4];
                            do {
                                if (*piVar4 == *local_1c) {
                                    bVar2 = true;
                                }
                                piVar4 = piVar4 + 1;
                                iVar8 = iVar8 + -1;
                            } while (iVar8 != 0);
                        }
                        if (bVar2) break;
                    }
                    local_18 = local_18 + 1;
                    uVar7 = uVar7 + 1;
                } while (uVar7 < local_8);
            }
            if ((*(uint32_t*)((char*)self + 200) & 0xffff) == 0x104) {
                if ((uVar7 < *(uint32_t*)((char*)self + 0x4c)) && (uVar7 != 0)) {
                    bVar3 = false;
                }
            }
            else if (uVar7 < *(uint32_t*)((char*)self + 0x4c)) {
                bVar3 = false;
            }
            if (!bVar2) {
                return 0;
            }
            uVar7 = uVar7 + 1;
            if (uVar7 < local_8) {
                local_18 = (int*)(*(int*)((char*)self + 0x230) + uVar7 * 4);
                local_24 = local_8 - uVar7;
                do {
                    piVar4 = (int*)*local_18;
                    if ((piVar4 != (int*)0x0) && (*piVar4 != 0)) {
                        local_20 = piVar4[3];
                        if (local_20 != 0) {
                            piVar5 = (int*)piVar4[4];
                            do {
                                iVar8 = *(int*)(*(int*)((char*)self + 0x14) + *piVar5 * 4);
                                if (((*(int*)(iVar8 + 4) == *(int*)((char*)self + 0x88)) &&
                                     (*(uint32_t*)(iVar8 + 0x10) == local_c)) &&
                                    (*(int*)(iVar8 + 0xc) == 0)) {
                                    bVar3 = false;
                                }
                                piVar5 = piVar5 + 1;
                                local_20 = local_20 + -1;
                            } while (local_20 != 0);
                        }
                        local_20 = piVar4[1];
                        if (local_20 != 0) {
                            piVar4 = (int*)piVar4[2];
                            do {
                                iVar8 = *(int*)(*(int*)((char*)self + 0x14) + *piVar4 * 4);
                                if (((*(int*)(iVar8 + 4) == *(int*)((char*)self + 0x88)) &&
                                     (*(uint32_t*)(iVar8 + 0x10) == local_c)) &&
                                    (*(int*)(iVar8 + 0xc) == 0)) {
                                    bVar3 = false;
                                }
                                piVar4 = piVar4 + 1;
                                local_20 = local_20 + -1;
                            } while (local_20 != 0);
                        }
                    }
                    local_18 = local_18 + 1;
                    local_24 = local_24 + -1;
                } while (local_24 != 0);
            }
            local_c = local_c + 1;
            local_1c = local_1c + 1;
        } while (local_c < 4);
        uVar7 = 0;
        if (bVar3) {
            do {
                local_10 = 0;
                if (local_8 != 0) {
                    do {
                        uVar6 = 0;
                        piVar4 = *(int**)(*(int*)((char*)self + 0x230) + local_10 * 4);
                        if (((piVar4 != (int*)0x0) && (*piVar4 != 0)) && (piVar4[3] != 0)) {
                            do {
                                iVar8 = *(int*)(piVar4[4] + uVar6 * 4);
                                if (iVar8 == *(int*)(uVar7 + piVar1[2])) {
                                    *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                         iVar8 * 4) + 0xc) = 0;
                                }
                                uVar6 = uVar6 + 1;
                            } while (uVar6 < (uint32_t)piVar4[3]);
                        }
                        local_10 = local_10 + 1;
                        local_8 = *(int*)((char*)self + 0x224) - 1;
                    } while (local_10 < local_8);
                }
                uVar7 = uVar7 + 4;
            } while (uVar7 < 0x10);
            *piVar1 = 0;
        }
    }
    return 0;
}

// 0x673ae5 — observed shape
int FUN_673ae5(void* self)
{
    uint32_t* puVar1;
    uint32_t uVar2;
    int iVar3;
    int iVar4;
    uint32_t uVar5;
    uint32_t local_14;
    int local_10;
    uint32_t local_8;

    local_8 = 0;
    if (*(int*)((char*)self + 0x4c) != 0) {
        do {
            puVar1 = *(uint32_t**)(*(int*)((char*)self + 0x230) + local_8 * 4);
            if (puVar1 != (uint32_t*)0x0) {
                uVar2 = *puVar1 & 0xfff00000;
                if ((uVar2 != 0x72100000) && (uVar2 != 0)) {
                    uVar5 = *puVar1 & 0xfffff;
                    local_10 = (-(uint32_t)(uVar2 != 0x11000000) & uVar5) * 4;
                    if ((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                            *(int*)(*(int*)(*(int*)((char*)self + 0x14) +
                                *(int*)(local_10 + puVar1[2]) * 4) + 4) * 4) + 5) & 2) != 0) {
                        iVar3 = FUN_0065d0b4();
                        if (iVar3 == 0) {
                            iVar3 = 0;
                        }
                        else {
                            iVar3 = FUN_0065cc1a();
                        }
                        if (iVar3 == 0) {
                            return -0x7ff8fff2;
                        }
                        iVar4 = FUN_0065d0ff(uVar5 | 0x10000000, uVar5, uVar5, 0);
                        if ((iVar4 < 0) || (iVar4 = FUN_0065cc50(), iVar4 < 0)) {
LAB_00673c8b:
                            FUN_00614343();
                            return iVar4;
                        }
                        local_14 = 0;
                        if (uVar5 != 0) {
                            do {
                                iVar4 = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x88),
                                                     0, local_14, 0);
                                *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                     iVar4 * 4) + 0x3c) = 0;
                                *(int*)(*(int*)(iVar3 + 0x10) + local_14 * 4) = iVar4;
                                *(uint32_t*)(*(int*)(iVar3 + 8) + local_14 * 4) =
                                    *(uint32_t*)(local_10 +
                                        *(int*)(*(int*)(*(int*)((char*)self + 0x230) +
                                                        local_8 * 4) + 8));
                                local_14 = local_14 + 1;
                                *(int*)(local_10 +
                                    *(int*)(*(int*)(*(int*)((char*)self + 0x230) +
                                                    local_8 * 4) + 8)) = iVar4;
                                local_10 = local_10 + 4;
                            } while (local_14 < uVar5);
                        }
                        puVar1 = (uint32_t*)((char*)self + 0x220);
                        if (0x1ff < *puVar1) {
                            iVar4 = -0x7ff8fff2;
                            goto LAB_00673c8b;
                        }
                        *(int*)(*(int*)((char*)self + 0x22c) + *puVar1 * 4) = iVar3;
                        *puVar1 = *puVar1 + 1;
                        iVar4 = FUN_0065d8c2();
                        if (iVar4 < 0) goto LAB_00673c8b;
                    }
                }
            }
            local_8 = local_8 + 1;
        } while (local_8 < *(uint32_t*)((char*)self + 0x4c));
    }
    return 0;
}

// 0x673c98 — observed shape
int FUN_673c98(void* self)
{
    int* piVar1;
    uint32_t uVar2;
    int iVar3;
    int iVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    uint32_t local_10;
    uint32_t local_8;

    uVar2 = *(uint32_t*)((char*)self + 0xc);
    iVar3 = FUN_0065d0b4(0x74);
    if (iVar3 == 0) {
        iVar3 = 0;
    }
    else {
        iVar3 = FUN_0065cc1a();
    }
    if (iVar3 == 0) {
        iVar4 = -0x7ff8fff2;
    }
    else {
        iVar4 = FUN_0065d0ff(0x10000004, 4, 4, 0);
        if (-1 < iVar4) {
            local_8 = 0xffffffff;
            uVar6 = 0;
            if (*(int*)((char*)self + 8) != 0) {
                do {
                    iVar4 = uVar6 * 4;
                    if (*(int*)(*(int*)(iVar4 + *(int*)((char*)self + 0x14)) + 4) ==
                        *(int*)((char*)self + 0x84)) {
                        *(uint32_t*)(*(int*)(iVar3 + 8) +
                            *(int*)(*(int*)(iVar4 + *(int*)((char*)self + 0x14)) + 0x10) * 4) = uVar6;
                        *(uint32_t*)(*(int*)(iVar4 + *(int*)((char*)self + 0x14)) + 4) =
                            *(uint32_t*)((char*)self + 0x88);
                        *(uint32_t*)(*(int*)(iVar4 + *(int*)((char*)self + 0x14)) + 0xc) =
                            0xffffffff;
                        local_8 = *(uint32_t*)(*(int*)(iVar4 + *(int*)((char*)self + 0x14)) + 0x6c);
                    }
                    uVar6 = uVar6 + 1;
                } while (uVar6 < *(uint32_t*)((char*)self + 8));
            }
            uVar6 = 0;
            do {
                uVar5 = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x84), 0, uVar6, 0);
                *(uint32_t*)(*(int*)(iVar3 + 0x10) + uVar6 * 4) = uVar5;
                if (*(int*)(*(int*)(iVar3 + 0x10) + uVar6 * 4) == -1) {
                    iVar4 = -0x7ff8fff2;
                    goto LAB_00673d95;
                }
                iVar4 = *(int*)(*(int*)((char*)self + 0x14) +
                                *(int*)(*(int*)(iVar3 + 0x10) + uVar6 * 4) * 4);
                *(uint32_t*)(iVar4 + 0x3c) = 0;
                uVar6 = uVar6 + 1;
                *(uint32_t*)(iVar4 + 0x6c) = local_8;
            } while (uVar6 < 4);
            iVar4 = FUN_0065d8c2();
            if (-1 < iVar4) {
                local_10 = 0;
                if (uVar2 != 0) {
                    do {
                        iVar4 = *(int*)(*(int*)((char*)self + 0x18) + local_10 * 4);
                        if ((((iVar4 != 0) &&
                              (uVar6 = *(uint32_t*)(iVar4 + 0xc), uVar6 != 0)) &&
                             (*(int*)(*(int*)(*(int*)((char*)self + 0x14) +
                                             **(int**)(iVar4 + 0x10) * 4) + 4) ==
                              *(int*)((char*)self + 0x84))) && (local_8 = 0, uVar6 != 0)) {
                            do {
                                uVar7 = 0;
                                do {
                                    piVar1 = (int*)(*(int*)(iVar4 + 0x10) + local_8 * 4);
                                    if (*piVar1 ==
                                        *(int*)(uVar7 + *(int*)(iVar3 + 0x10))) {
                                        *piVar1 = *(int*)(uVar7 + *(int*)(iVar3 + 8));
                                    }
                                    uVar7 = uVar7 + 4;
                                } while (uVar7 < 0x10);
                                local_8 = local_8 + 1;
                            } while (local_8 < uVar6);
                        }
                        local_10 = local_10 + 1;
                    } while (local_10 < uVar2);
                }
                return 0;
            }
        }
LAB_00673d95:
        FUN_00614343();
    }
    return iVar4;
}

// 0x673e69 — observed shape
uint32_t FUN_673e69(int param_1, int* param_2, uint32_t param_3)
{
    bool bVar1;
    int* piVar2;
    int* piVar3;
    int iVar4;
    uint32_t local_8;

    local_8 = 0;
    if (param_3 != 0) {
        piVar3 = &DAT_007203c0;
        do {
            bVar1 = true;
            iVar4 = 4;
            piVar2 = param_2;
            do {
                if ((*(int*)((param_1 - (int)param_2) + (int)piVar2) != *piVar3) &&
                    (*piVar2 != -1)) {
                    bVar1 = false;
                }
                piVar3 = piVar3 + 1;
                piVar2 = piVar2 + 1;
                iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
            if (bVar1) {
                return 1;
            }
            local_8 = local_8 + 1;
        } while (local_8 < param_3);
    }
    return 0;
}

// 0x673ec4 — observed shape
uint32_t FUN_673ec4(void* self, int param_1)
{
    int iVar1;
    uint32_t uVar2;
    bool bVar3;
    bool bVar4;
    int* piVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    int local_18[4];
    uint32_t local_8;

    local_8 = 0;
    local_18[0] = 0;
    local_18[1] = 0;
    local_18[2] = 0;
    uVar6 = *(uint32_t*)(param_1 + 0xc);
    uVar7 = 0;
    if (uVar6 != 0) {
        iVar1 = *(int*)((char*)self + 0x14);
        piVar5 = *(int**)(param_1 + 0x10);
        do {
            uVar2 = *(uint32_t*)(*(int*)(iVar1 + *piVar5 * 4) + 0x10);
            if (3 < uVar2) {
                return 0;
            }
            uVar7 = uVar7 + 1;
            piVar5 = piVar5 + 1;
            local_18[uVar2] = 1;
        } while (uVar7 < uVar6);
    }
    bVar3 = false;
    bVar4 = true;
    uVar6 = 0;
    do {
        if (local_18[uVar6] == 0) {
            bVar3 = true;
        }
        else {
            bVar4 = false;
        }
        uVar6 = uVar6 + 1;
    } while (uVar6 < 3);
    if ((bVar3) && (!bVar4)) {
        local_8 = 1;
    }
    return local_8;
}

// 0x673f3c — observed shape
int FUN_673f3c(void* self)
{
    double uVar1;
    uint32_t uVar2;
    uint32_t* puVar3;
    uint32_t* puVar4;
    int* piVar5;
    uint32_t uVar6;
    int iVar7;
    uint32_t* puVar8;
    uint32_t uVar9;
    uint32_t* puVar10;
    int iVar11;
    bool bVar12;
    int local_ec[20];
    uint32_t local_9c[12];
    int local_6c[4];
    uint32_t local_5c[4];
    int local_4c;
    uint32_t local_3c;
    uint32_t local_38;
    uint32_t local_34;
    uint32_t local_30;
    uint32_t* local_2c;
    uint32_t local_28;
    uint32_t local_24;
    uint32_t* local_20;
    uint32_t local_1c;
    int local_18;
    uint32_t local_14;
    uint32_t local_10;
    int local_c;
    int local_8;

    local_8 = 0;
    local_c = 0;
    local_34 = *(uint32_t*)((char*)self + 0x4c);
    local_3c = *(uint32_t*)((char*)self + 0x224);
    bVar12 = local_34 < *(uint32_t*)((char*)self + 0x224);
    do {
        local_c = 0;
        if (!bVar12) {
            iVar11 = 0;
LAB_006742e7:
            if (local_8 != 0) {
                FUN_00614343();
            }
LAB_006742f5:
            if (local_c != 0) {
                FUN_00614343();
            }
            return iVar11;
        }
        puVar10 = *(uint32_t**)(*(int*)((char*)self + 0x230) + local_34 * 4);
        local_2c = puVar10;
        if ((puVar10 != (uint32_t*)0x0) && (*puVar10 != 0)) {
            local_14 = *puVar10 & 0xfffff;
            local_38 = puVar10[1] / local_14;
            local_24 = 0;
            if (local_38 != 0) {
                local_18 = 0;
                local_20 = local_9c;
                do {
                    puVar4 = local_20;
                    puVar8 = local_20 + 1;
                    *local_20 = 0xffffffff;
                    *puVar8 = 0xffffffff;
                    puVar4[2] = 0xffffffff;
                    puVar4[3] = 0xffffffff;
                    local_ec[0] = -1;
                    local_ec[1] = 0xffffffff;
                    local_ec[2] = 0xffffffff;
                    local_ec[3] = 0xffffffff;
                    local_28 = 0;
                    local_30 = 0;
                    if (local_14 == 0) {
LAB_006740ac:
                        iVar11 = FUN_00673e69((int)(intptr_t)local_20, local_ec, 2);
                        if (iVar11 == 0) {
                            local_4c = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x88), 0, 3, 0);
                            if (local_4c == -1) goto LAB_0067430a;
                            iVar11 = FUN_0065d0b4();
                            if (iVar11 == 0) {
                                local_8 = 0;
                            }
                            else {
                                local_8 = FUN_0065cc1a();
                            }
                            if (local_8 == 0) goto LAB_0067430a;
                            iVar11 = FUN_0065d0ff(0x50000003, 6, 1, 0);
                            if ((iVar11 < 0) || (iVar11 = FUN_0065cc50(), iVar11 < 0))
                                goto LAB_006742e7;
                            iVar11 = *(int*)(*(int*)((char*)self + 0x14) +
                                             *(int*)(intptr_t)(local_18 + puVar10[2]) * 4);
                            local_28 = *(uint32_t*)(iVar11 + 0x10);
                            local_10 = 0;
                            do {
                                if (local_10 == local_28) {
                                    uVar9 = *(uint32_t*)((char*)self + 0x444);
                                }
                                else {
                                    uVar9 = *(uint32_t*)((char*)self + 0x440);
                                }
                                uVar1 = *(double*)(iVar11 + 0x20);
                                uVar2 = *(uint32_t*)(iVar11 + 4);
                                local_5c[local_10] = uVar9;
                                iVar7 = FUN_0065d9d5(uVar2, 0, local_10, uVar1);
                                local_6c[local_10] = iVar7;
                                if (iVar7 == -1) goto LAB_0067430a;
                                local_1c = *(uint32_t*)(*(int*)((char*)self + 0x14) + iVar7 * 4);
                                FUN_0065d501();
                                iVar7 = *(int*)(*(int*)(*(int*)((char*)self + 0x14) +
                                         *(int*)(intptr_t)(local_18 + puVar10[2]) * 4) + 0x38);
                                if (iVar7 == -1) {
                                    *(int*)(intptr_t)(local_1c + 0x38) =
                                        *(int*)(intptr_t)(local_18 + puVar10[2]);
                                }
                                else {
                                    *(int*)(intptr_t)(local_1c + 0x38) = iVar7;
                                }
                                local_10 = local_10 + 1;
                            } while (local_10 < 3);
                            puVar3 = *(uint32_t**)(local_8 + 8);
                            *puVar3 = local_5c[0];
                            puVar3[1] = local_5c[1];
                            puVar3[2] = local_5c[2];
                            iVar11 = *(int*)(local_8 + 8);
                            *(int*)(intptr_t)(iVar11 + 0xc) = local_6c[0];
                            *(int*)(intptr_t)(iVar11 + 0x10) = local_6c[1];
                            *(int*)(intptr_t)(iVar11 + 0x14) = local_6c[2];
                            **(int**)(local_8 + 0x10) = local_4c;
                            if (local_14 != 0) {
                                iVar11 = local_18;
                                uVar6 = local_14;
                                do {
                                    *(int*)(intptr_t)(iVar11 + local_2c[2]) = local_4c;
                                    iVar11 = iVar11 + 4;
                                    uVar6 = uVar6 - 1;
                                } while (uVar6 != 0);
                            }
                            if (0x1ff < *(uint32_t*)((char*)self + 0x224)) goto LAB_0067430a;
                            *(int*)(*(int*)((char*)self + 0x230) +
                                    *(uint32_t*)((char*)self + 0x224) * 4) = local_8;
                            *(int*)((char*)self + 0x224) = *(int*)((char*)self + 0x224) + 1;
                            iVar11 = FUN_0065d8c2();
                            if (iVar11 < 0) goto LAB_0067430a;
                            local_8 = 0;
                            puVar10 = local_2c;
                        }
                    }
                    else {
                        local_1c = *puVar10 & 0xfff00000;
                        piVar5 = (int*)(intptr_t)(puVar10[2] + local_18);
                        do {
                            local_10 = *(uint32_t*)(*(int*)((char*)self + 0x14) + *piVar5 * 4);
                            uVar6 = local_30;
                            if ((local_1c != 0x50000000) && (local_14 == puVar10[3])) {
                                uVar6 = *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) +
                                          *(int*)(intptr_t)(puVar10[4] + local_30 * 4) * 4) + 0x10);
                            }
                            iVar11 = uVar6 + local_24 * 4;
                            if ((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                    *(int*)(intptr_t)(local_10 + 4) * 4) + 5) & 1) == 0) {
                                local_9c[iVar11] = *(uint32_t*)(intptr_t)(local_10 + 0x10);
                            }
                            else {
                                local_9c[iVar11] = uVar6;
                            }
                            if (uVar6 == 3) {
                                local_28 = 1;
                            }
                            local_ec[uVar6] = 0;
                            local_30 = local_30 + 1;
                            piVar5 = piVar5 + 1;
                        } while (local_30 < local_14);
                        if (((local_28 == 0) || (bVar12 = true, local_14 != 1)) ||
                            ((local_1c == 0x50000000 && (puVar10[3] == 1)))) goto LAB_006740ac;
                        uVar6 = 0;
                        puVar8 = local_20;
                        do {
                            if ((*puVar8 != *(uint32_t*)((char*)&DAT_00720400 + uVar6)) &&
                                (*(int*)((char*)local_ec + uVar6) != -1)) {
                                bVar12 = false;
                            }
                            uVar6 = uVar6 + 4;
                            puVar8 = puVar8 + 1;
                        } while (uVar6 < 0x10);
                        if (!bVar12) goto LAB_006740ac;
                    }
                    local_24 = local_24 + 1;
                    local_20 = local_20 + 4;
                    local_18 = local_18 + local_14 * 4;
                } while (local_24 < local_38);
            }
            iVar11 = FUN_0065d0b4();
            if (iVar11 == 0) {
                local_c = 0;
            }
            else {
                local_c = FUN_0065cc1a();
            }
            if ((local_c != 0) && (iVar11 = FUN_0065d8c2(), -1 < iVar11)) {
                iVar11 = FUN_0065d35e();
                iVar7 = local_c;
                if (iVar11 < 0) goto LAB_006742f5;
                if (*(uint32_t*)((char*)self + 0x224) < 0x200) {
                    local_c = 0;
                    *(int*)(*(int*)((char*)self + 0x230) +
                            *(uint32_t*)((char*)self + 0x224) * 4) = iVar7;
                    *(int*)((char*)self + 0x224) = *(int*)((char*)self + 0x224) + 1;
                    *puVar10 = 0;
                    goto LAB_006742d5;
                }
            }
LAB_0067430a:
            iVar11 = -0x7ff8fff2;
            goto LAB_006742e7;
        }
LAB_006742d5:
        local_34 = local_34 + 1;
        bVar12 = local_34 < local_3c;
    } while (true);
}

// 0x674311 — observed shape
int FUN_674311(int* self)
{
    uint32_t uVar1;
    uint32_t* puVar2;
    uint32_t uVar3;
    uint32_t* puVar4;
    uint32_t uVar5;
    int* piVar6;
    uint32_t* puVar7;
    uint32_t uVar8;
    int iVar9;
    uint32_t uVar10;
    int iVar11;
    int local_1c;
    int local_14;
    uint32_t local_c;
    uint32_t local_8;

    local_c = 0;
    if (self[2] != 0) {
        piVar6 = (int*)self[5];
        iVar9 = self[2];
        do {
            if ((self[0x22] == *(int*)(intptr_t)(*piVar6 + 4)) &&
                (uVar5 = *(uint32_t*)(intptr_t)(*piVar6 + 0xc), local_c <= uVar5)) {
                local_c = uVar5 + 1;
            }
            piVar6 = piVar6 + 1;
            iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
    }
    uVar1 = self[0x89];
    uVar5 = self[0x13];
    do {
        if (uVar1 <= uVar5) {
            for (uVar5 = self[0x13]; uVar5 < uVar1; uVar5 = uVar5 + 1) {
                **(uint32_t**)(intptr_t)(self[0x8c] + uVar5 * 4) = 0;
            }
            return 0;
        }
        puVar2 = *(uint32_t**)(intptr_t)(self[0x8c] + uVar5 * 4);
        if ((puVar2 != (uint32_t*)0x0) && (uVar8 = *puVar2, uVar8 != 0)) {
            uVar10 = uVar8 & 0xfffff;
            if ((uVar8 & 0xfff00000) == 0x70100000) {
                piVar6 = (int*)puVar2[2];
                iVar9 = self[5];
                iVar11 = self[4];
                if ((((*(uint8_t*)(*(int*)(iVar11 + *(int*)(*(int*)(iVar9 + *piVar6 * 4) + 4) * 4) + 5) & 2) != 0) &&
                     ((*(uint8_t*)(*(int*)(iVar11 + *(int*)(*(int*)(iVar9 + piVar6[uVar10] * 4) + 4) * 4) + 5) & 2) != 0)) &&
                    ((*(uint8_t*)(*(int*)(iVar11 + *(int*)(*(int*)(iVar9 + piVar6[uVar10 * 2] * 4) + 4) * 4) + 5) & 2) != 0)) {
                    iVar9 = FUN_0065d0b4();
                    if (iVar9 == 0) {
                        local_14 = 0;
                    }
                    else {
                        local_14 = FUN_0065cc1a();
                    }
                    if (local_14 == 0) {
                        return -0x7ff8fff2;
                    }
                    iVar9 = FUN_0065d0ff(uVar10 | 0x10000000, uVar10, uVar10, 0);
                    if (iVar9 < 0) {
                        return iVar9;
                    }
                    iVar9 = FUN_0065cc50();
                    if (iVar9 < 0) {
                        return iVar9;
                    }
                    local_8 = 0;
                    if (uVar10 != 0) {
                        do {
                            iVar11 = local_8 * 4;
                            iVar9 = *(int*)(self[5] + *(int*)(iVar11 + puVar2[4]) * 4);
                            *(uint32_t*)(intptr_t)(iVar11 + *(int*)(local_14 + 8)) =
                                *(uint32_t*)(intptr_t)(iVar11 + puVar2[2]);
                            uVar3 = FUN_0065d9d5(self[0x22], local_c,
                                                 *(uint32_t*)(intptr_t)(iVar9 + 0x10), 0);
                            *(uint32_t*)(intptr_t)(iVar11 + *(int*)(local_14 + 0x10)) = uVar3;
                            *(uint32_t*)(intptr_t)(iVar11 + puVar2[2]) =
                                *(uint32_t*)(intptr_t)(iVar11 + *(int*)(local_14 + 0x10));
                            if (*(int*)(intptr_t)(iVar11 + *(int*)(local_14 + 0x10)) == -1) {
                                return -0x7ff8fff2;
                            }
                            local_8 = local_8 + 1;
                        } while (local_8 < uVar10);
                    }
                    local_c = local_c + 1;
                    if (0x1ff < (uint32_t)self[0x89]) {
                        return -0x7ff8fff2;
                    }
                    iVar9 = FUN_0065d8c2();
                    if (iVar9 < 0) {
                        return iVar9;
                    }
                    *(int*)(intptr_t)(self[0x8c] + self[0x89] * 4) = local_14;
                    self[0x89] = self[0x89] + 1;
                }
            }
            if (((*puVar2 & 0xfff00000) == 0x30000000) && ((self[0x32] & 0xffffu) != 0x104)) {
                uVar8 = 1;
                if (1 < uVar10) {
                    piVar6 = (int*)puVar2[2];
                    iVar9 = *piVar6;
                    do {
                        piVar6 = piVar6 + 1;
                        if (iVar9 != *piVar6) {
                            FUN_006626da();
                            return -0x7fffbffb;
                        }
                        uVar8 = uVar8 + 1;
                    } while (uVar8 < uVar10);
                }
                iVar9 = FUN_0065d0b4();
                if (iVar9 == 0) {
                    puVar4 = (uint32_t*)0x0;
                }
                else {
                    puVar4 = (uint32_t*)FUN_0065cc1a();
                }
                if (puVar4 == (uint32_t*)0x0) {
                    return -0x7ff8fff2;
                }
                local_8 = FUN_0065d8c2();
                if ((int)local_8 < 0) {
LAB_0067485a:
                    FUN_00614343();
                    return local_8;
                }
                iVar9 = FUN_0065d0ff(0x70300001, 3, 1, 0);
                if (iVar9 < 0) {
                    return iVar9;
                }
                iVar9 = FUN_0065cc50();
                if (iVar9 < 0) {
                    return iVar9;
                }
                *(uint32_t*)(intptr_t)puVar4[2] = *(uint32_t*)(intptr_t)puVar2[2];
                uVar3 = FUN_0065d9d5(self[0x1e], 0, 0, 0xbff0000000000000);
                *(uint32_t*)(intptr_t)(puVar4[2] + 4) = uVar3;
                uVar3 = FUN_0065d9d5(self[0x1e], 0, 0, 0x3fe0000000000000);
                *(uint32_t*)(intptr_t)(puVar4[2] + 8) = uVar3;
                if (*(int*)(intptr_t)(puVar4[2] + 4) == -1) {
                    return -0x7ff8fff2;
                }
                if (*(int*)(intptr_t)(puVar4[2] + 8) == -1) {
                    return -0x7ff8fff2;
                }
                uVar3 = FUN_0065d9d5(self[0x22], local_c, 3, 0);
                *(uint32_t*)(intptr_t)puVar4[4] = uVar3;
                if (*(int*)(intptr_t)puVar4[4] == -1) {
                    return -0x7ff8fff2;
                }
                local_8 = 0;
                if (uVar10 != 0) {
                    local_1c = uVar10 << 3;
                    local_14 = uVar10 << 2;
                    do {
                        *(uint32_t*)(intptr_t)(puVar2[2] + local_8 * 4) =
                            *(uint32_t*)(intptr_t)puVar4[4];
                        puVar7 = (uint32_t*)(intptr_t)(local_14 + puVar2[2]);
                        uVar3 = *puVar7;
                        *puVar7 = *(uint32_t*)(intptr_t)(puVar2[2] + local_1c);
                        *(uint32_t*)(intptr_t)(local_1c + puVar2[2]) = uVar3;
                        local_8 = local_8 + 1;
                        local_1c = local_1c + 4;
                        local_14 = local_14 + 4;
                    } while (local_8 < uVar10);
                }
                local_c = local_c + 1;
                if (0x1ff < (uint32_t)self[0x89]) {
                    return -0x7ff8fff2;
                }
                *(uint32_t**)(intptr_t)(self[0x8c] + self[0x89] * 4) = puVar4;
                self[0x89] = self[0x89] + 1;
                iVar9 = ((int (*)(void*))(*(void**)((char*)(intptr_t)(*self) + 0x20)))(puVar4);
                if (iVar9 != 0) {
                    iVar9 = FUN_0065d0b4();
                    if (iVar9 == 0) {
                        local_14 = 0;
                    }
                    else {
                        local_14 = FUN_0065cc1a();
                    }
                    local_8 = FUN_0065d8c2();
                    if ((int)local_8 < 0) {
                        if (local_14 == 0) {
                            return local_8;
                        }
                        goto LAB_0067485a;
                    }
                    if (local_14 == 0) {
                        return -0x7ff8fff2;
                    }
                    iVar9 = FUN_0065d0ff(0x20400001, 2, 1, 0);
                    if (iVar9 < 0) {
                        return iVar9;
                    }
                    iVar9 = FUN_0065cc50();
                    if (iVar9 < 0) {
                        return iVar9;
                    }
                    **(uint32_t**)(local_14 + 0x10) = *(uint32_t*)(intptr_t)puVar4[4];
                    **(uint32_t**)(local_14 + 8) = *(uint32_t*)(intptr_t)(puVar4[2] + 8);
                    uVar3 = FUN_0065d9d5(self[0x22], 0, 3, 0);
                    *(uint32_t*)(intptr_t)puVar4[4] = uVar3;
                    *(uint32_t*)(intptr_t)(*(int*)(local_14 + 8) + 4) =
                        *(uint32_t*)(intptr_t)puVar4[4];
                    puVar4[1] = 2;
                    *puVar4 = 0x20500001;
                    if (0x1ff < (uint32_t)self[0x89]) {
                        return -0x7ff8fff2;
                    }
                    *(int*)(intptr_t)(self[0x8c] + self[0x89] * 4) = local_14;
                    self[0x89] = self[0x89] + 1;
                }
                self[0x113] = 1;
                *puVar2 = uVar10 | 0x70f00000;
            }
            iVar9 = FUN_0065d0b4();
            if (iVar9 == 0) {
                iVar9 = 0;
            }
            else {
                iVar9 = FUN_0065cc1a();
            }
            if (iVar9 == 0) {
                return -0x7ff8fff2;
            }
            iVar11 = FUN_0065d35e();
            if (iVar11 < 0) {
                return iVar11;
            }
            if (0x1ff < (uint32_t)self[0x89]) {
                return -0x7ff8fff2;
            }
            iVar11 = FUN_0065d8c2();
            if (iVar11 < 0) {
                return iVar11;
            }
            *(int*)(intptr_t)(self[0x8c] + self[0x89] * 4) = iVar9;
            self[0x89] = self[0x89] + 1;
        }
        uVar5 = uVar5 + 1;
    } while (true);
}

// 0x674889 — observed shape
int FUN_674889(int* self)
{
    uint32_t* puVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    int* piVar5;
    int iVar6;
    int iVar7;
    uint32_t uVar8;
    int* piVar9;
    int* piVar10;
    bool bVar11;
    int uVar12;
    int local_ac[12];
    int local_7c[9];
    int iStack_58;
    int iStack_54;
    int iStack_50;
    int local_4c[9];
    int* local_28;
    int* local_24;
    int* local_20;
    int* local_1c;
    int* local_18;
    int* local_14;
    int* local_10;
    int* local_c;
    int* local_8;

    puVar1 = *(uint32_t**)((char*)self + 0x100);
    uVar8 = *puVar1;
    local_1c = (int*)(intptr_t)(uVar8 & 0xfffff);
    if ((puVar1 == (uint32_t*)0x0) || (uVar8 == 0)) {
        return 0;
    }
    local_c = (int*)(intptr_t)(puVar1[1] / (uint32_t)(uintptr_t)local_1c);
    local_18 = (int*)0x0;
    if (((uVar8 & 0xfff00000) == 0x50000000) ||
        ((int*)(intptr_t)puVar1[3] != local_1c)) {
        iVar6 = FUN_0065db2e(puVar1);
        if (iVar6 < 0) {
            return iVar6;
        }
        **(uint32_t**)((char*)self + 0x100) = 0;
        return 0;
    }
    local_4c[8] = 0;
    local_20 = self;
    if ((((*(uint32_t*)((char*)self + 200) & 0xffff) != 0x104) &&
         (iVar6 = (int)FUN_00673ec4(self, (int)(intptr_t)puVar1), iVar6 != 0)) &&
        (uVar8 = puVar1[3], uVar8 != 0)) {
        piVar9 = (int*)(intptr_t)puVar1[4];
        do {
            if (*(int*)(*(int*)(*(int*)((char*)self + 0x14) + *piVar9 * 4) + 0x10) == 3) {
                local_18 = (int*)0x1;
                local_4c[8] = 1;
            }
            piVar9 = piVar9 + 1;
            uVar8 = uVar8 - 1;
        } while (uVar8 != 0);
    }
    local_14 = (int*)0x0;
    if (local_c != (int*)0x0) {
        local_24 = (int*)0x0;
        local_8 = local_ac;
        do {
            piVar10 = local_8;
            piVar9 = local_8 + 1;
            *local_8 = -1;
            local_10 = (int*)0x0;
            *piVar9 = -1;
            piVar10[2] = -1;
            piVar10[3] = -1;
            local_7c[0] = -1;
            local_7c[1] = -1;
            local_7c[2] = -1;
            local_7c[3] = -1;
            if (local_1c != (int*)0x0) {
                iVar6 = *(int*)((char*)self + 0x100);
                iVar7 = *(int*)((char*)self + 0x14);
                iVar2 = *(int*)((char*)self + 0x10);
                local_28 = local_24;
                do {
                    iVar3 = *(int*)(iVar7 +
                             *(int*)(intptr_t)((int)(intptr_t)local_28 + *(int*)(intptr_t)(iVar6 + 8)) * 4);
                    iVar4 = *(int*)(*(int*)(iVar7 +
                             *(int*)(intptr_t)(*(int*)(intptr_t)(iVar6 + 0x10) +
                                               (int)(intptr_t)local_10 * 4) * 4) + 0x10);
                    if ((*(uint8_t*)(*(int*)(iVar2 + *(int*)(iVar3 + 4) * 4) + 5) & 1) == 0) {
                        local_ac[iVar4 + (int)(intptr_t)local_14 * 4] = *(int*)(iVar3 + 0x10);
                    }
                    else {
                        local_ac[iVar4 + (int)(intptr_t)local_14 * 4] = iVar4;
                    }
                    local_7c[iVar4] = 0;
                    local_10 = (int*)(intptr_t)((int)(intptr_t)local_10 + 1);
                    local_28 = local_28 + 1;
                } while (local_10 < local_1c);
                self = local_20;
            }
            iVar6 = FUN_00673e69((int)(intptr_t)local_8, local_7c, 5);
            if (iVar6 == 0) {
                local_18 = (int*)0x1;
            }
            local_14 = (int*)(intptr_t)((int)(intptr_t)local_14 + 1);
            local_8 = local_8 + 4;
            local_24 = local_24 + (int)(intptr_t)local_1c;
        } while (local_14 < local_c);
    }
    uVar8 = 0;
    if (local_18 == (int*)0x0) {
        iVar6 = FUN_0065db2e((void*)(uintptr_t)*(uint32_t*)((char*)self + 0x100));
LAB_00674e18:
        if (iVar6 < 0) {
            return iVar6;
        }
        goto LAB_00674e1c;
    }
    local_14 = (int*)0x0;
    local_20 = (int*)0x0;
    if (local_1c == (int*)4) {
        local_8 = (int*)0x1;
        do {
            if (local_8 == (int*)0x0) break;
            local_7c[0] = 0;
            local_7c[1] = 0;
            local_7c[2] = 0;
            local_7c[3] = 0;
            local_7c[4] = 0xffffffff;
            local_7c[5] = 0xffffffff;
            local_7c[6] = 0xffffffff;
            local_7c[7] = 0xffffffff;
            local_7c[uVar8] = -1;
            local_7c[uVar8 + 4] = 0;
            local_8 = (int*)0x0;
            if (local_c != (int*)0x0) {
                piVar9 = local_ac;
                local_18 = local_c;
                do {
                    iVar6 = FUN_00673e69((int)(intptr_t)piVar9, local_7c, 5);
                    if ((iVar6 == 0) ||
                        (iVar6 = FUN_00673e69((int)(intptr_t)piVar9, local_7c, 5), iVar6 == 0)) {
                        local_8 = (int*)0x1;
                    }
                    piVar9 = piVar9 + 4;
                    local_18 = (int*)(intptr_t)((int)(intptr_t)local_18 + -1);
                } while (local_18 != (int*)0x0);
            }
            if ((local_4c[8] != 0) && (uVar8 != 3)) {
                local_8 = (int*)0x1;
            }
            if (local_8 == (int*)0x0) {
                iVar6 = FUN_0069ec6d(local_7c, local_c, 4);
                if (iVar6 < 0) {
                    return iVar6;
                }
                iVar6 = FUN_0069ec6d(local_7c + 4, local_c, 4);
                goto LAB_00674e18;
            }
            uVar8 = uVar8 + 1;
        } while (uVar8 < 4);
        local_8 = (int*)0x1;
        local_10 = (int*)0x0;
        do {
            if (local_8 == (int*)0x0) break;
            local_18 = (int*)0x0;
            do {
                piVar10 = local_10;
                piVar9 = local_18;
                if (local_18 != local_10) {
                    local_7c[0] = 0;
                    local_7c[1] = 0;
                    local_7c[2] = 0;
                    local_7c[3] = 0;
                    local_7c[4] = 0xffffffff;
                    local_7c[5] = 0xffffffff;
                    local_7c[6] = 0xffffffff;
                    local_7c[7] = 0xffffffff;
                    local_7c[(int)(intptr_t)local_10] = -1;
                    local_7c[(int)(intptr_t)piVar9] = -1;
                    bVar11 = local_c != (int*)0x0;
                    local_7c[(int)(intptr_t)(piVar10 + 1)] = 0;
                    local_7c[(int)(intptr_t)(piVar9 + 1)] = 0;
                    local_8 = (int*)0x0;
                    local_28 = (int*)0x0;
                    if (bVar11) {
                        piVar9 = local_ac;
                        local_24 = local_c;
                        do {
                            iVar6 = FUN_00673e69((int)(intptr_t)piVar9, local_7c, 5);
                            iVar7 = FUN_00673e69((int)(intptr_t)piVar9, local_7c + 4, 5);
                            if (iVar6 == 0) {
                                local_28 = (int*)0x1;
LAB_00674b7d:
                                local_8 = (int*)0x1;
                            }
                            else if (iVar7 == 0) goto LAB_00674b7d;
                            piVar9 = piVar9 + 4;
                            local_24 = (int*)(intptr_t)((int)(intptr_t)local_24 + -1);
                        } while (local_24 != (int*)0x0);
                    }
                    if (local_4c[8] != 0) {
                        local_8 = (int*)0x1;
                    }
                    if (local_8 == (int*)0x0) {
                        local_14 = (int*)0x1;
                        break;
                    }
                    if ((local_28 == (int*)0x0) &&
                        ((local_4c[8] == 0 || (local_7c[3] != 0)))) {
                        local_7c[8] = local_7c[0];
                        iStack_58 = local_7c[1];
                        iStack_54 = local_7c[2];
                        iStack_50 = local_7c[3];
                        local_4c[0] = -1;
                        local_4c[1] = 0xffffffff;
                        local_4c[2] = 0xffffffff;
                        local_4c[3] = 0xffffffff;
                        local_4c[4] = 0xffffffff;
                        local_4c[5] = 0xffffffff;
                        local_4c[6] = 0xffffffff;
                        local_4c[7] = 0xffffffff;
                        local_4c[(int)(intptr_t)local_10] = 0;
                        local_4c[(int)(intptr_t)(local_18 + 1)] = 0;
                        local_20 = (int*)0x1;
                    }
                }
                local_18 = (int*)(intptr_t)((int)(intptr_t)local_18 + 1);
            } while (local_18 < (int*)4);
            local_10 = (int*)(intptr_t)((int)(intptr_t)local_10 + 1);
        } while (local_10 < (int*)4);
        if (local_14 == (int*)0x0) {
            if (local_20 == (int*)0x0) goto LAB_00674dc3;
            local_14 = (int*)0x1;
            iVar6 = FUN_0069ec6d(local_7c + 8, local_c, 4);
            if (iVar6 < 0) {
                return iVar6;
            }
            iVar6 = FUN_0069ec6d(local_4c, local_c, 4);
            if (iVar6 < 0) {
                return iVar6;
            }
            uVar12 = 4;
            piVar9 = local_4c;
        }
        else {
            iVar6 = FUN_0069ec6d(local_7c, local_c, 4);
            if (iVar6 < 0) {
                return iVar6;
            }
            uVar12 = 4;
LAB_00674da7:
            piVar9 = local_7c;
        }
        iVar6 = FUN_0069ec6d(piVar9 + 4, local_c, uVar12);
        if (iVar6 < 0) {
            return iVar6;
        }
        if (local_14 != (int*)0x0) goto LAB_00674e1c;
    }
    else if (local_1c == (int*)0x3) {
        local_20 = (int*)0xffffffff;
        piVar9 = (int*)0x0;
        do {
            if (local_ac[(int)(intptr_t)piVar9] == -1) {
                local_20 = piVar9;
            }
            piVar9 = (int*)(intptr_t)((int)(intptr_t)piVar9 + 1);
        } while (piVar9 < (int*)4);
        local_10 = (int*)0x0;
        do {
            if (local_14 != (int*)0x0) goto LAB_00674d8d;
            piVar9 = (int*)0x0;
            do {
                piVar5 = local_10;
                piVar10 = local_20;
                if (local_14 != (int*)0x0) break;
                if (((piVar9 != local_10) && (piVar9 != local_20)) && (local_10 != local_20)) {
                    local_7c[0] = -1;
                    local_7c[1] = -1;
                    local_7c[2] = -1;
                    local_7c[3] = -1;
                    local_7c[4] = 0;
                    local_7c[5] = 0;
                    local_7c[6] = 0;
                    local_7c[7] = 0;
                    local_7c[(int)(intptr_t)local_10] = 0;
                    local_7c[(int)(intptr_t)piVar9] = 0;
                    local_7c[(int)(intptr_t)(piVar5 + 1)] = -1;
                    local_7c[(int)(intptr_t)(piVar9 + 1)] = -1;
                    local_7c[(int)(intptr_t)(piVar10 + 1)] = -1;
                    piVar10 = (int*)0x0;
                    local_8 = (int*)0x0;
                    if (local_c != (int*)0x0) {
                        local_18 = local_ac;
                        do {
                            if (local_8 != (int*)0x0) break;
                            iVar6 = FUN_00673e69((int)(intptr_t)local_18, local_7c, 5);
                            if (iVar6 == 0) {
                                local_8 = (int*)0x1;
                            }
                            local_18 = local_18 + 4;
                            piVar10 = (int*)(intptr_t)((int)(intptr_t)piVar10 + 1);
                        } while (piVar10 < local_c);
                    }
                    if ((local_7c[3] == 0) &&
                        ((((local_7c[0] == 0 || (local_7c[1] == 0)) || (local_7c[2] == 0)) &&
                          (local_4c[8] != 0)))) {
                        local_8 = (int*)0x1;
                    }
                    if (local_8 == (int*)0x0) {
                        local_14 = (int*)0x1;
                    }
                }
                piVar9 = (int*)(intptr_t)((int)(intptr_t)piVar9 + 1);
            } while (piVar9 < (int*)4);
            local_10 = (int*)(intptr_t)((int)(intptr_t)local_10 + 1);
        } while (local_10 < (int*)4);
        if (local_14 != (int*)0x0) {
LAB_00674d8d:
            iVar6 = FUN_0069ec6d(local_7c, local_c, 3);
            if (iVar6 < 0) {
                return iVar6;
            }
            uVar12 = 3;
            goto LAB_00674da7;
        }
    }
LAB_00674dc3:
    piVar9 = (int*)0x0;
    if (local_1c != (int*)0x0) {
        do {
            piVar5 = local_c;
            piVar10 = local_1c;
            local_7c[0] = -1;
            local_7c[1] = 0xffffffff;
            local_7c[2] = 0xffffffff;
            local_7c[3] = 0xffffffff;
            local_7c[*(int*)(*(int*)(*(int*)((char*)self + 0x14) +
                      *(int*)(*(int*)(intptr_t)(*(int*)((char*)self + 0x100) + 0x10) +
                              (int)(intptr_t)piVar9 * 4) * 4) + 0x10)] = 0;
            iVar6 = FUN_0069ec6d(local_7c, piVar5, (int)(intptr_t)piVar10);
            if (iVar6 < 0) {
                return iVar6;
            }
            piVar9 = (int*)(intptr_t)((int)(intptr_t)piVar9 + 1);
        } while (piVar9 < local_1c);
    }
LAB_00674e1c:
    **(uint32_t**)((char*)self + 0x100) = 0;
    return 0;
}

// 0x674e44 — observed shape
int FUN_674e44(void* self, int param_1)
{
    int iVar1;
    int iVar2;
    int iVar3;
    int* piVar4;
    int* piVar5;
    uint32_t uVar6;
    uint32_t* puVar7;
    uint32_t* puVar8;
    bool bVar9;
    uint32_t uVar10;
    uint32_t uVar11;
    uint32_t local_128[16];
    uint8_t local_e8[16];
    int aiStack_d8[4];
    int aiStack_c8[4];
    int aiStack_b8[4];
    int aiStack_a8[4];
    int aiStack_98[4];
    int aiStack_88[4];
    int aiStack_78[12];
    uint32_t local_48;
    int local_44[9];
    int local_20;
    uint32_t local_1c;
    uint32_t local_18;
    int local_14;
    uint32_t local_10;
    int* local_c;
    int local_8;

    if (0x103 < (*(uint32_t*)((char*)self + 200) & 0xffff)) {
        return 1;
    }
    uVar6 = 0;
    local_1c = 0;
    local_48 = 0;
    local_44[0] = 1;
    local_44[1] = 2;
    local_44[2] = 3;
    local_8 = (int)(intptr_t)self;
    if ((**(uint32_t**)((char*)self + 0x100) & 0xfffff) == 3) {
        do {
            iVar1 = FUN_00694b7c(*(uint32_t*)((char*)self + 0x100),
                                 (&PTR_DAT_00720340)[uVar6], local_128, &local_1c,
                                 local_e8, &local_48, 3, 0);
            if (iVar1 == 0) break;
            uVar6 = uVar6 + 1;
        } while (uVar6 < 9);
        local_14 = 0;
        local_18 = 0;
        if (4 < uVar6) {
            local_18 = 1;
        }
        local_18 = (uint32_t)(4 < uVar6);
        if (iVar1 != 0) {
            uVar6 = 0;
            do {
                iVar1 = FUN_00694b7c(*(uint32_t*)((char*)self + 0x100),
                                     (&PTR_DAT_00720364)[uVar6], local_128, &local_1c,
                                     local_e8, &local_48, 3, 0);
                if (iVar1 == 0) break;
                uVar6 = uVar6 + 1;
            } while (uVar6 < 3);
            local_18 = 0;
            if (1 < uVar6) {
                local_18 = 1;
            }
            local_18 = (uint32_t)(1 < uVar6);
            local_14 = 1;
            if (iVar1 != 0) goto LAB_00674f3d;
        }
        local_10 = 0;
        iVar1 = *(int*)((char*)self + 0x14);
        local_20 = 0xc - (int)(intptr_t)(local_44 + 3);
        do {
            iVar3 = aiStack_d8[local_10];
            iVar2 = *(int*)(intptr_t)(iVar1 + iVar3 * 4);
            if (*(uint32_t*)(iVar2 + 0x10) != local_10) {
                return 1;
            }
            if (param_1 == 0) {
                if (local_18 == 0) {
                    if (*(int*)(iVar2 + 0x48) == -1) {
                        return 1;
                    }
                    piVar5 = *(int**)(intptr_t)(*(int*)(intptr_t)(local_8 + 0x18) +
                                                *(int*)(iVar2 + 0x48) * 4);
                    if (*piVar5 != 0x20500003) {
                        return 1;
                    }
                    iVar3 = piVar5[2];
                    local_c = *(int**)(intptr_t)(local_10 * 4 + iVar3);
                    iVar2 = *(int*)(intptr_t)(iVar1 + (int)(intptr_t)local_c * 4);
                    if ((*(uint8_t*)(*(int*)(intptr_t)(*(int*)(intptr_t)(local_8 + 0x10) +
                            *(int*)(iVar2 + 4) * 4) + 5) & 2) == 0) {
                        return 1;
                    }
                    if (*(uint32_t*)(iVar2 + 0x10) != local_10) {
                        return 1;
                    }
                    piVar4 = local_44 + local_10 + 3;
                    iVar1 = *(int*)(intptr_t)(iVar1 +
                             *(int*)(intptr_t)(local_20 + iVar3 + (int)(intptr_t)piVar4) * 4);
                    if ((*(uint8_t*)(*(int*)(intptr_t)(*(int*)(intptr_t)(local_8 + 0x10) +
                            *(int*)(iVar1 + 4) * 4) + 5) & 1) == 0) {
                        return 1;
                    }
                    if (*(double*)(iVar1 + 0x20) != -1.0) {
                        return 1;
                    }
                    *piVar4 = (int)(intptr_t)local_c;
                }
                else {
                    if ((*(uint8_t*)(*(int*)(intptr_t)(*(int*)(intptr_t)(local_8 + 0x10) +
                            *(int*)(iVar2 + 4) * 4) + 5) & 2) == 0) {
                        return 1;
                    }
                    piVar4 = local_44 + local_10 + 3;
                    *piVar4 = iVar3;
                }
                piVar5 = aiStack_b8 + local_10;
                local_c = (int*)(intptr_t)*piVar4;
                if ((*piVar5 != *piVar4) ||
                    (iVar3 = aiStack_c8[local_10], aiStack_a8[local_10] != iVar3)) {
LAB_00675144:
                    bVar9 = (int*)(intptr_t)aiStack_a8[local_10] == local_c;
                    goto LAB_0067514b;
                }
                piVar4 = aiStack_98 + local_10;
                iVar1 = *piVar4;
                if ((iVar1 != aiStack_88[local_10]) || (aiStack_a8[local_10] != iVar1))
                    goto LAB_00675144;
            }
            else {
                if (*(int*)(iVar2 + 0x48) != -1) {
                    return 1;
                }
                if (*(int*)(iVar2 + 4) != *(int*)(intptr_t)(local_8 + 0x80)) {
                    return 1;
                }
                if ((uint32_t)*(uint8_t*)(iVar2 + 0x6d) != local_10 + 1) {
                    return 1;
                }
                if (*(int8_t*)(iVar2 + 0x6c) != '\x05') {
                    return 1;
                }
                local_44[local_10 + 3] = iVar3;
                if (local_18 == 0) {
                    if (*(int*)(iVar2 + 0x3c) != 0x80000) {
                        return 1;
                    }
                    piVar5 = aiStack_b8 + local_10;
                    local_c = (int*)(intptr_t)*(int*)(iVar2 + 0x38);
                    if ((*piVar5 == *(int*)(iVar2 + 0x38)) &&
                        (iVar3 = aiStack_c8[local_10], aiStack_a8[local_10] == iVar3)) {
                        piVar4 = aiStack_98 + local_10;
                        iVar1 = *piVar4;
                        if ((iVar1 == aiStack_88[local_10]) &&
                            (aiStack_a8[local_10] == iVar1))
                            goto LAB_00675168;
                    }
                    goto LAB_00675144;
                }
                if (*(int*)(iVar2 + 0x3c) != 0) {
                    return 1;
                }
                piVar5 = aiStack_b8 + local_10;
                if (*piVar5 == iVar3) {
                    iVar3 = aiStack_c8[local_10];
                    if (aiStack_a8[local_10] == iVar3) {
                        piVar4 = aiStack_98 + local_10;
                        iVar1 = *piVar4;
                        if ((iVar1 == aiStack_88[local_10]) &&
                            (aiStack_a8[local_10] == iVar1))
                            goto LAB_00675168;
                    }
                }
                bVar9 = aiStack_a8[local_10] == aiStack_d8[local_10];
LAB_0067514b:
                if (!bVar9) {
                    return 1;
                }
                iVar3 = piVar5[-4];
                if (*piVar5 != iVar3) {
                    return 1;
                }
                piVar4 = aiStack_98 + local_10;
                iVar1 = *piVar4;
                if (iVar1 != piVar5[0xc]) {
                    return 1;
                }
                if (*piVar5 != iVar1) {
                    return 1;
                }
            }
LAB_00675168:
            local_44[local_10 + 6] = iVar3;
            if (((local_14 != 0) && (iVar1 != piVar4[8])) ||
                (iVar1 = *(int*)((char*)self + 0x14),
                 *(uint32_t*)(*(int*)(intptr_t)(iVar1 + iVar3 * 4) + 0x10) != local_10)) {
                return 1;
            }
            local_10 = local_10 + 1;
        } while (local_10 < 3);
        uVar6 = 0;
        if (local_1c != 0) {
            do {
                puVar7 = local_128 + uVar6;
                uVar6 = uVar6 + 1;
                *(uint32_t*)(intptr_t)*puVar7 = 0;
            } while (uVar6 < local_1c);
        }
        iVar1 = FUN_0065d0b4(0x74);
        if (iVar1 == 0) {
            iVar1 = 0;
        }
        else {
            iVar1 = FUN_0065cc1a();
        }
        iVar3 = local_8;
        if (iVar1 == 0) {
            local_14 = -0x7ff8fff2;
        }
        else {
            if (param_1 == 0) {
                uVar11 = 9;
                uVar10 = 0x72d00003;
            }
            else {
                uVar11 = 6;
                uVar10 = 0x72c00003;
            }
            iVar2 = FUN_0065d0ff(uVar10, uVar11,
                                 *(uint32_t*)(intptr_t)(*(int*)(intptr_t)(local_8 + 0x100) + 0xc), 0);
            if (iVar2 < 0) {
                FUN_00614343(1);
                local_14 = iVar2;
            }
            else {
                local_14 = FUN_0065cc50(*(uint32_t*)(intptr_t)(iVar3 + 0x100));
                if (local_14 < 0) {
                    FUN_00614343(1);
                }
                else {
                    puVar7 = *(uint32_t**)(intptr_t)(*(int*)(intptr_t)(local_8 + 0x100) + 0x10);
                    puVar8 = *(uint32_t**)(iVar1 + 0x10);
                    for (uVar6 = *(uint32_t*)(intptr_t)(*(int*)(intptr_t)(local_8 + 0x100) + 0xc) &
                                 0x3fffffff;
                         uVar6 != 0; uVar6 = uVar6 - 1) {
                        *puVar8 = *puVar7;
                        puVar7 = puVar7 + 1;
                        puVar8 = puVar8 + 1;
                    }
                    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
                        *(uint8_t*)puVar8 = *(uint8_t*)puVar7;
                        puVar7 = (uint32_t*)((int)(intptr_t)puVar7 + 1);
                        puVar8 = (uint32_t*)((int)(intptr_t)puVar8 + 1);
                    }
                    uVar6 = 0xc;
                    local_c = local_44;
                    do {
                        *(uint32_t*)(intptr_t)((uVar6 - 0xc) + *(int*)(iVar1 + 8)) =
                            **(uint32_t**)(intptr_t)(*(int*)(intptr_t)(local_8 + 0x100) + 8);
                        *(uint32_t*)(intptr_t)(uVar6 + *(int*)(iVar1 + 8)) =
                            *(uint32_t*)(intptr_t)((int)(intptr_t)local_44 + uVar6 + 0xc);
                        if (param_1 == 0) {
                            *(uint32_t*)(intptr_t)(uVar6 + 0xc + *(int*)(iVar1 + 8)) =
                                *(uint32_t*)(intptr_t)((int)(intptr_t)local_44 + uVar6);
                        }
                        uVar6 = uVar6 + 4;
                    } while (uVar6 < 0x18);
                    piVar5 = (int*)(intptr_t)(local_8 + 0xfc);
                    if (*(int*)(intptr_t)(*(int*)(intptr_t)(local_8 + 0x18) + *piVar5 * 4) != 0) {
                        FUN_00614343(1);
                    }
                    *(int*)(intptr_t)(*(int*)(intptr_t)(local_8 + 0x18) + *piVar5 * 4) = iVar1;
                }
            }
        }
    }
    else {
LAB_00674f3d:
        local_14 = 1;
    }
    return local_14;
}

// 0x675520 — observed shape
int* FUN_675520(int* self)
{
    int iVar1;
    int iVar2;
    uint32_t uVar3;
    int iVar4;
    int iVar5;
    uint32_t uVar6;
    int local_10c[4];
    int local_fc[4];
    uint32_t auStack_ec[32];
    uint32_t local_6c[16];
    uint32_t local_2c;
    uint32_t local_28;
    uint32_t local_24;
    uint32_t local_20;
    uint32_t local_1c;
    int local_18;
    uint32_t local_14;
    int local_10;
    uint32_t local_c;
    intptr_t local_8;

    local_14 = 0;
    local_2c = 0;
    local_28 = 1;
    local_24 = 2;
    local_20 = 3;
    uVar6 = *(uint32_t*)(intptr_t)self[0x40] & 0xfffff;
    local_c = 0;
    iVar2 = FUN_00694b7c((uint32_t*)(intptr_t)self[0x40], (void*)&DAT_006ee918, local_6c,
                         &local_14, local_10c, &local_2c, uVar6, 0);
    if (iVar2 == 0) {
LAB_006755ba:
        local_1c = 0;
        if (local_c != 0) {
            uVar3 = *(uint32_t*)(intptr_t)(*(int*)(intptr_t)(self[4] +
                        *(int*)(intptr_t)(*(int*)(intptr_t)(self[5] + local_fc[0] * 4) + 4) * 4) + 4);
            local_1c = (uint32_t)((uVar3 & 0x200) != 0);
            if (((*(uint32_t*)(intptr_t)(*(int*)(intptr_t)(self[4] +
                     *(int*)(intptr_t)(*(int*)(intptr_t)(self[5] + local_10c[0] * 4) + 4) * 4) + 4) &
                  0x300) != 0) && ((uVar3 & 0x300) != 0)) {
                return (int*)0x1;
            }
        }
        iVar2 = FUN_0065d0b4(0x74);
        if (iVar2 == 0) {
            iVar2 = 0;
        }
        else {
            iVar2 = FUN_0065cc1a();
        }
        if (iVar2 == 0) {
            return (int*)0x8007000e;
        }
        if (local_c == 0) {
            uVar3 = uVar6 | 0x70300000;
        }
        else {
            uVar3 = uVar6 | 0x70400000;
        }
        local_8 = (intptr_t)FUN_0065d0ff(uVar3, uVar6 * 3, uVar6, 0);
        if (((int)local_8 < 0) ||
            (local_8 = (intptr_t)FUN_0065cc50(self[0x40]), (int)local_8 < 0))
            goto LAB_00675755;
        local_c = 0;
        if (uVar6 != 0) {
            local_18 = uVar6 << 3;
            local_10 = uVar6 << 2;
            do {
                uVar3 = local_c;
                iVar1 = local_10;
                iVar5 = local_18;
                iVar4 = local_c * 4;
                *(uint32_t*)(intptr_t)(iVar4 + *(int*)(iVar2 + 0x10)) =
                    *(uint32_t*)(intptr_t)(iVar4 + *(int*)(intptr_t)(self[0x40] + 0x10));
                local_8 = (intptr_t)(local_fc + local_c);
                if (local_1c == 0) {
                    *(int*)(intptr_t)(iVar4 + *(int*)(iVar2 + 8)) = local_10c[local_c];
                    iVar4 = *(int*)(intptr_t)local_8;
                }
                else {
                    *(int*)(intptr_t)(iVar4 + *(int*)(iVar2 + 8)) = *(int*)(intptr_t)local_8;
                    iVar4 = local_10c[local_c];
                }
                local_c = local_c + 1;
                local_10 = local_10 + 4;
                *(int*)(intptr_t)(iVar1 + *(int*)(iVar2 + 8)) = iVar4;
                local_18 = local_18 + 4;
                *(uint32_t*)(intptr_t)(iVar5 + *(int*)(iVar2 + 8)) = auStack_ec[uVar3];
            } while (local_c < uVar6);
        }
        iVar5 = ((int (*)(int, int))(*(void**)((char*)(intptr_t)(*self) + 0x20)))(iVar2, 0);
        if (iVar5 != 0) {
            local_8 = 1;
            goto LAB_00675755;
        }
        uVar6 = 0;
        if (local_14 != 0) {
            do {
                *(uint32_t*)(intptr_t)local_6c[uVar6] = 0;
                uVar6 = uVar6 + 1;
            } while (uVar6 < local_14);
        }
        if (self[0x40] != 0) {
            FUN_00614343(1);
        }
        *(int*)(intptr_t)(self[6] + self[0x3f] * 4) = iVar2;
    }
    else {
        iVar2 = FUN_00694b7c((uint32_t*)(intptr_t)self[0x40], (void*)&DAT_006ee978, local_6c,
                             &local_14, local_10c, &local_2c, uVar6, 0);
        local_c = 1;
        if (iVar2 == 0) goto LAB_006755ba;
    }
    iVar2 = 0;
    local_8 = 0;
LAB_00675755:
    if (iVar2 != 0) {
        FUN_00614343(1);
    }
    return (int*)local_8;
}

// 0x67576a — observed shape
uint32_t FUN_67576a(int param_1, uint32_t param_2)
{
    uint32_t* puVar1;
    uint32_t uVar2;
    int iVar3;
    uint32_t* puVar4;
    uint32_t* puVar5;

    if ((*(uint32_t*)(param_1 + 0x1c) & 7) == 0) {
        puVar1 = (uint32_t*)(intptr_t)FUN_0065d097(*(uint32_t*)(param_1 + 0x1c) + 8);
        if (puVar1 == (uint32_t*)0x0) {
            return 0x8007000e;
        }
        puVar4 = *(uint32_t**)(param_1 + 0x20);
        puVar5 = puVar1;
        for (uVar2 = *(uint32_t*)(param_1 + 0x1c) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar5 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar5 = puVar5 + 1;
        }
        for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
            *(uint8_t*)puVar5 = *(uint8_t*)puVar4;
            puVar4 = (uint32_t*)((int)(intptr_t)puVar4 + 1);
            puVar5 = (uint32_t*)((int)(intptr_t)puVar5 + 1);
        }
        *(uint32_t**)(param_1 + 0x20) = puVar1;
    }
    *(uint32_t*)(intptr_t)(*(int*)(param_1 + 0x20) + *(int*)(param_1 + 0x1c) * 4) = param_2;
    *(int*)(param_1 + 0x1c) = *(int*)(param_1 + 0x1c) + 1;
    return 0;
}

// 0x6757c4 — observed shape
int FUN_6757c4(void* self, int param_1, uint32_t param_2)
{
    int iVar1;
    int iVar2;
    int* piVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    int* piVar6;
    int local_414[256];
    int local_14;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;

    uVar5 = 0;
    if (param_2 != 0) {
        do {
            iVar1 = *(int*)(param_1 + uVar5 * 4);
            if (iVar1 != 0) {
                uVar4 = 0;
                if (*(int*)(iVar1 + 0xc) != 0) {
                    do {
                        iVar2 = uVar4 * 4;
                        uVar4 = uVar4 + 1;
                        *(uint32_t*)(intptr_t)(*(int*)(intptr_t)(*(int*)((char*)self + 0x14) +
                            *(int*)(intptr_t)(*(int*)(iVar1 + 0x10) + iVar2) * 4) + 0x48) = uVar5;
                    } while (uVar4 < *(uint32_t*)(iVar1 + 0xc));
                }
                *(uint32_t*)(iVar1 + 0x1c) = 0;
                *(uint32_t*)(iVar1 + 0x14) = 0;
            }
            uVar5 = uVar5 + 1;
        } while (uVar5 < param_2);
    }
    uVar5 = 0;
    if (*(int*)((char*)self + 8) != 0) {
        do {
            iVar1 = *(int*)(intptr_t)(*(int*)((char*)self + 0x14) + uVar5 * 4);
            iVar2 = *(int*)(iVar1 + 0x38);
            if (iVar2 != -1) {
                *(uint32_t*)(iVar1 + 0x48) =
                    *(uint32_t*)(intptr_t)(*(int*)(intptr_t)(*(int*)((char*)self + 0x14) +
                                           iVar2 * 4) + 0x48);
            }
            uVar5 = uVar5 + 1;
        } while (uVar5 < *(uint32_t*)((char*)self + 8));
    }
    local_8 = 0;
    local_14 = (int)(intptr_t)self;
    if (param_2 != 0) {
        do {
            iVar1 = *(int*)(param_1 + local_8 * 4);
            uVar5 = 0;
            if (iVar1 != 0) {
                local_10 = 0;
                local_c = 0;
                if (*(int*)(iVar1 + 4) != 0) {
                    do {
                        iVar2 = *(int*)(intptr_t)(*(int*)(intptr_t)(*(int*)((char*)self + 0x14) +
                                 *(int*)(intptr_t)(*(int*)(iVar1 + 8) + local_c * 4) * 4) + 0x48);
                        if (iVar2 != -1) {
                            uVar4 = 0;
                            if (uVar5 != 0) {
                                do {
                                    if (local_414[uVar4] == iVar2) break;
                                    uVar4 = uVar4 + 1;
                                } while (uVar4 < uVar5);
                            }
                            if (uVar4 == uVar5) {
                                local_414[uVar5] = iVar2;
                                uVar5 = uVar5 + 1;
                                local_10 = uVar5;
                            }
                            iVar2 = (int)FUN_0067576a(*(uint32_t*)(param_1 + iVar2 * 4), local_8);
                            if (iVar2 < 0) {
                                return iVar2;
                            }
                        }
                        local_c = local_c + 1;
                    } while (local_c < *(uint32_t*)(iVar1 + 4));
                }
                piVar3 = (int*)(intptr_t)FUN_0065d097(uVar5);
                *(int**)(iVar1 + 0x18) = piVar3;
                if (piVar3 == (int*)0x0) {
                    return -0x7ff8fff2;
                }
                piVar6 = local_414;
                for (; uVar5 != 0; uVar5 = uVar5 - 1) {
                    *piVar3 = *piVar6;
                    piVar6 = piVar6 + 1;
                    piVar3 = piVar3 + 1;
                }
                *(uint32_t*)(iVar1 + 0x14) = local_10;
                self = (void*)(intptr_t)local_14;
            }
            local_8 = local_8 + 1;
        } while (local_8 < param_2);
    }
    return 0;
}

// 0x6758fc — observed shape
int FUN_6758fc(void* self)
{
    int* piVar1;
    uint32_t* puVar2;
    int* piVar3;
    int iVar4;
    int iVar5;
    float fVar6;
    uint32_t uVar7;
    int iVar8;
    uint32_t* puVar9;
    int* piVar10;
    uint32_t* puVar11;
    uint32_t uVar12;
    uint32_t* puVar13;
    uint32_t uVar14;
    uint32_t* puVar15;
    uint32_t local_94[16];
    uint32_t local_54[8];
    int* local_34;
    uint32_t local_30;
    int* local_2c;
    float local_28;
    uint32_t local_24;
    uint32_t local_20;
    uint32_t* local_1c;
    int* local_18;
    uint32_t local_14;
    uint32_t* local_10;
    int* local_c;
    uint32_t* local_8;

    local_20 = 0;
    local_14 = 0;
    piVar3 = (int*)(*(uint32_t**)((char*)self + 0x100))[2];
    uVar12 = **(uint32_t**)((char*)self + 0x100) & 0xfffff;
    iVar8 = *(int*)(intptr_t)(*(int*)((char*)self + 0x14) + *piVar3 * 4);
    piVar1 = piVar3 + uVar12;
    iVar4 = *(int*)(intptr_t)(*(int*)((char*)self + 0x14) + *piVar1 * 4);
    local_10 = *(uint32_t**)(intptr_t)(*(int*)((char*)self + 0x10) + *(int*)(iVar8 + 4) * 4);
    iVar5 = *(int*)((char*)self + 0x88);
    if (((*(int*)(iVar8 + 4) == iVar5) &&
         ((*(uint8_t*)(intptr_t)(*(int*)(intptr_t)(*(int*)((char*)self + 0x10) +
               *(int*)(iVar4 + 4) * 4) + 5) & 1) != 0)) &&
        ((**(uint32_t**)((char*)self + 0x100) & 0xfff00000) == 0x20500000)) {
        local_18 = piVar3;
        local_2c = piVar1;
    }
    else {
        if (((*(int*)(iVar4 + 4) != iVar5) ||
             ((*(uint8_t*)((int)(intptr_t)local_10 + 5) & 1) == 0)) ||
            ((**(uint32_t**)((char*)self + 0x100) & 0xfff00000) != 0x20500000)) {
            if (*(int*)(iVar8 + 4) != iVar5) {
                return 1;
            }
            if (*(int*)(iVar4 + 4) != iVar5) {
                return 1;
            }
            if ((**(uint32_t**)((char*)self + 0x100) & 0xfff00000) != 0x20400000) {
                return 1;
            }
            local_14 = 1;
            if (uVar12 != 0) {
                piVar10 = piVar3;
                local_10 = (uint32_t*)(uintptr_t)uVar12;
                do {
                    if (*piVar10 != *(int*)(intptr_t)(((int)(intptr_t)piVar1 -
                                                       (int)(intptr_t)piVar3) +
                                                      (int)(intptr_t)piVar10)) {
                        local_14 = 0;
                    }
                    piVar10 = piVar10 + 1;
                    local_10 = (uint32_t*)(intptr_t)((int)(intptr_t)local_10 - 1);
                } while (local_10 != (uint32_t*)0x0);
            }
            uVar7 = *(uint32_t*)(iVar8 + 0x3c);
            if (uVar7 != *(uint32_t*)(iVar4 + 0x3c)) {
                return 1;
            }
            if (uVar7 == 0x80000) {
                local_28 = -1.0f;
            }
            else {
                if ((uVar7 & 0x80000) != 0) {
                    return 1;
                }
                local_28 = 1.0f;
            }
            local_18 = piVar3;
            if (local_14 == 0) {
                return 1;
            }
            local_28 = local_28 + local_28;
            goto LAB_0067598a;
        }
        local_18 = piVar1;
        local_2c = piVar3;
    }
    local_28 = (float)*(double*)(intptr_t)(*(int*)(intptr_t)(*(int*)((char*)self + 0x14) +
                                          *local_2c * 4) + 0x20);
LAB_0067598a:
    local_8 = (uint32_t*)0x0;
    if (uVar12 != 0) {
        iVar8 = *(int*)((char*)self + 0x14);
        local_c = local_2c;
        local_1c = (uint32_t*)(uintptr_t)((int)(intptr_t)local_18 - (int)(intptr_t)local_2c);
        do {
            uVar7 = local_20;
            iVar4 = *(int*)(intptr_t)(iVar8 + *(int*)(intptr_t)((int)(intptr_t)local_1c +
                                                               (int)(intptr_t)local_c) * 4);
            uVar14 = 0;
            if (local_14 == 0) {
                local_10 = (uint32_t*)(intptr_t)*(int*)(intptr_t)(iVar8 + *local_c * 4);
            }
            else {
                local_10 = (uint32_t*)0x0;
            }
            if (*(int*)(iVar4 + 0x58) != *(int*)((char*)self + 0xfc)) {
                return 1;
            }
            if (*(int*)(iVar4 + 0x54) != *(int*)((char*)self + 0xfc)) {
                return 1;
            }
            if ((*(uint32_t*)(iVar4 + 0x3c) & 0x1ffe00) != 0) {
                return 1;
            }
            if (local_20 != 0) {
                do {
                    if (*(uint32_t*)(iVar4 + 0x48) == local_54[uVar14 + 4]) break;
                    uVar14 = uVar14 + 1;
                } while (uVar14 < local_20);
            }
            if (uVar14 == local_20) {
                local_20 = local_20 + 1;
                local_54[uVar7 + 4] = *(uint32_t*)(iVar4 + 0x48);
            }
            if ((local_14 == 0) &&
                ((double)local_28 != *(double*)(intptr_t)((int)(intptr_t)local_10 + 0x20))) {
                return 1;
            }
            local_8 = (uint32_t*)(intptr_t)((int)(intptr_t)local_8 + 1);
            local_c = local_c + 1;
        } while ((int)(intptr_t)local_8 < (int)uVar12);
    }
    fVar6 = fabsf(local_28);
    if ((((fabsf(fVar6) != 2.0f) || (uVar7 = 0x400, (*(uint32_t*)((char*)self + 0x6c) & 0x400) == 0)) &&
         (((fVar6 != 4.0f || (uVar7 = 0x800, (*(uint32_t*)((char*)self + 0x6c) & 0x800) == 0)) &&
           ((fVar6 != 8.0f || (uVar7 = 0x1000, (*(uint32_t*)((char*)self + 0x6c) & 0x1000) == 0)))))) &&
        (((fVar6 != 0.5f || (uVar7 = 0x2000, (*(uint32_t*)((char*)self + 0x6c) & 0x2000) == 0)) &&
          (((fVar6 != 0.25f || (uVar7 = 0x4000, (*(uint32_t*)((char*)self + 0x6c) & 0x4000) == 0)) &&
            ((fVar6 != 0.125f || (uVar7 = 0x8000, (*(uint32_t*)((char*)self + 0x6c) & 0x8000) == 0)))))))) {
        return 1;
    }
    local_14 = uVar7;
    if (local_28 < 0.0f) {
        local_14 = (uint32_t)((8u << 16) | ((uint32_t)uVar7 & 0xffffu));
    }
    local_54[0] = 0;
    local_54[1] = 0;
    local_54[2] = 0;
    local_54[3] = 0;
    local_c = (int*)0x0;
    if (local_20 != 0) {
        local_1c = local_94;
        local_10 = (uint32_t*)0x0;
        do {
            puVar15 = local_1c;
            puVar11 = *(uint32_t**)(intptr_t)(*(int*)((char*)self + 0x18) +
                                            local_54[(int)(intptr_t)local_c + 4] * 4);
            if ((*puVar11 & 0xf0000000) == 0x60000000) {
                return 1;
            }
            if ((*puVar11 & 0xff000000) == 0x72000000) {
                return 1;
            }
            local_24 = 0;
            local_8 = (uint32_t*)0x0;
            uVar7 = puVar11[3];
            puVar2 = local_1c + 1;
            *local_1c = 0xffffffff;
            *puVar2 = 0xffffffff;
            puVar15[2] = 0xffffffff;
            puVar15[3] = 0xffffffff;
            if (uVar12 != 0) {
                do {
                    local_30 = 0;
                    if (uVar7 != 0) {
                        local_2c = (int*)(intptr_t)local_18[(int)(intptr_t)local_8];
                        local_34 = (int*)(intptr_t)puVar11[4];
                        puVar15 = (uint32_t*)(intptr_t)((int)(intptr_t)local_94 +
                                                       (int)(intptr_t)local_10);
                        do {
                            puVar13 = local_8;
                            if ((int*)(intptr_t)*local_34 == local_2c) {
                                local_54[(int)(intptr_t)local_c] =
                                    local_54[(int)(intptr_t)local_c] + 1;
                                iVar8 = *(int*)(intptr_t)(*(int*)((char*)self + 0x100) + 0x10);
                                *puVar15 = (uint32_t)(uintptr_t)puVar13;
                                if (((*(uint8_t*)(intptr_t)(*(int*)(intptr_t)(*(int*)((char*)self + 0x14) +
                                        *(int*)(intptr_t)(iVar8 + (int)(intptr_t)puVar13 * 4) * 4) +
                                        0x3d) & 2) != 0) && (local_28 < 0.0f)) {
                                    return 1;
                                }
                                local_24 = local_24 + 1;
                            }
                            local_30 = local_30 + 1;
                            uVar7 = puVar11[3];
                            local_34 = local_34 + 1;
                            puVar15 = puVar15 + 1;
                        } while (local_30 < uVar7);
                    }
                    local_8 = (uint32_t*)(intptr_t)((int)(intptr_t)local_8 + 1);
                } while ((int)(intptr_t)local_8 < (int)uVar12);
            }
            if (local_24 != uVar7) {
                return 1;
            }
            local_c = (int*)(intptr_t)((int)(intptr_t)local_c + 1);
            local_1c = local_1c + 4;
            local_10 = (uint32_t*)(intptr_t)((int)(intptr_t)local_10 + 0x10);
        } while ((int)(intptr_t)local_c < (int)local_20);
    }
    local_c = (int*)0x0;
    if (local_20 != 0) {
        local_1c = local_94;
        do {
            uVar12 = local_54[(int)(intptr_t)local_c];
            puVar13 = *(uint32_t**)(intptr_t)(local_54[(int)(intptr_t)local_c + 4] * 4 +
                                              *(int*)((char*)self + 0x18));
            local_2c = (int*)(uintptr_t)(local_54[(int)(intptr_t)local_c + 4] * 4);
            local_10 = puVar13;
            local_24 = uVar12;
            if (uVar12 != puVar13[3]) {
                iVar8 = FUN_0065d0b4(0x74);
                if (iVar8 == 0) {
                    local_8 = (uint32_t*)0x0;
                }
                else {
                    local_8 = (uint32_t*)(intptr_t)FUN_0065cc1a();
                }
                if (local_8 == (uint32_t*)0x0) {
                    return -0x7ff8fff2;
                }
                iVar8 = FUN_0065d0ff((int)*puVar13, (int)puVar13[1], (int)uVar12, 0);
                if ((iVar8 < 0) ||
                    (iVar8 = FUN_0065cc50((int)(intptr_t)puVar13), iVar8 < 0)) {
                    FUN_00614343(1);
                    return iVar8;
                }
                puVar13 = (uint32_t*)(intptr_t)local_10[2];
                puVar9 = (uint32_t*)(intptr_t)local_8[2];
                for (uVar12 = local_10[1] & 0x3fffffff; uVar12 != 0; uVar12 = uVar12 - 1) {
                    *puVar9 = *puVar13;
                    puVar13 = puVar13 + 1;
                    puVar9 = puVar9 + 1;
                }
                for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
                    *(uint8_t*)puVar9 = *(uint8_t*)puVar13;
                    puVar13 = (uint32_t*)((int)(intptr_t)puVar13 + 1);
                    puVar9 = (uint32_t*)((int)(intptr_t)puVar9 + 1);
                }
                FUN_00614343(1);
                *(uint32_t**)(intptr_t)((int)(intptr_t)local_2c +
                                        *(int*)((char*)self + 0x18)) = local_8;
                local_10 = local_8;
                puVar13 = local_8;
            }
            local_8 = (uint32_t*)0x0;
            if (local_24 != 0) {
                local_10 = local_1c;
                do {
                    puVar9 = local_8;
                    if ((int)(intptr_t)local_8 < 4) {
                        puVar11 = local_10;
                        do {
                            if (*puVar11 != 0xffffffff) break;
                            puVar9 = (uint32_t*)(intptr_t)((int)(intptr_t)puVar9 + 1);
                            puVar11 = puVar11 + 1;
                        } while ((int)(intptr_t)puVar9 < 4);
                    }
                    local_18 = (int*)0x0;
                    iVar8 = (int)(intptr_t)puVar9 * 4;
                    *(uint32_t*)(intptr_t)(puVar13[4] + (int)(intptr_t)local_8 * 4) =
                        *(uint32_t*)(intptr_t)(iVar8 +
                            *(int*)(intptr_t)(*(int*)((char*)self + 0x100) + 0x10));
                    puVar11 = (uint32_t*)(intptr_t)(*(int*)(intptr_t)(*(int*)((char*)self + 0x14) +
                        *(int*)(intptr_t)(iVar8 + *(int*)(intptr_t)(*(int*)((char*)self + 0x100) +
                                                                   0x10)) * 4) + 0x3c);
                    *puVar11 = *puVar11 | local_14;
                    if (*(int*)((char*)self + 8) != 0) {
                        do {
                            iVar4 = *(int*)(intptr_t)(*(int*)((char*)self + 0x14) +
                                                     (int)(intptr_t)local_18 * 4);
                            if (*(int*)(iVar4 + 0x38) ==
                                *(int*)(intptr_t)(iVar8 +
                                    *(int*)(intptr_t)(*(int*)((char*)self + 0x100) + 0x10))) {
                                *(uint32_t*)(iVar4 + 0x3c) =
                                    *(uint32_t*)(iVar4 + 0x3c) | (local_14 & 0xfff7ffff);
                                uVar12 = *(uint32_t*)(iVar4 + 0x3c);
                                if (local_28 < 0.0f) {
                                    if ((uVar12 & 0x80000) == 0) {
                                        uVar12 = uVar12 | 0x80000;
                                    }
                                    else {
                                        uVar12 = uVar12 & 0xfff7ffff;
                                    }
                                    *(uint32_t*)(iVar4 + 0x3c) = uVar12;
                                }
                            }
                            local_18 = (int*)(intptr_t)((int)(intptr_t)local_18 + 1);
                        } while ((int)(intptr_t)local_18 < *(int*)((char*)self + 8));
                    }
                    local_8 = (uint32_t*)(intptr_t)((int)(intptr_t)local_8 + 1);
                    local_10 = local_10 + 1;
                } while ((int)(intptr_t)local_8 < (int)local_24);
            }
            local_c = (int*)(intptr_t)((int)(intptr_t)local_c + 1);
            local_1c = local_1c + 4;
        } while ((int)(intptr_t)local_c < (int)local_20);
    }
    **(uint32_t**)((char*)self + 0x100) = 0;
    return 0;
}

// 0x67601a — observed shape
uint32_t FUN_67601a(void* self, int param_1, uint32_t param_2, uint32_t param_3,
                    uint32_t param_4, uint32_t param_5, int param_6)
{
    int iVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;

    local_10 = 0;
    if (param_2 != 0) {
        do {
            iVar1 = *(int*)(param_1 + local_10 * 4);
            if ((iVar1 != 0) && (local_c = 0, *(int*)(iVar1 + 4) != 0)) {
                do {
                    iVar2 = *(int*)(intptr_t)(*(int*)((char*)self + 0x14) +
                             *(int*)(intptr_t)(*(int*)(iVar1 + 8) + local_c * 4) * 4);
                    if ((*(int*)(iVar2 + 4) == *(int*)((char*)self + 0x80)) &&
                        (((*(int*)(iVar2 + 0x3c) != 0 &&
                           ((*(uint32_t*)(iVar2 + 0x6c) & 0xff) == param_3)) &&
                          (param_4 == *(uint8_t*)(iVar2 + 0x6d))))) {
                        local_8 = 0;
                        if (param_5 != 0) {
                            do {
                                if (*(int*)(iVar2 + 0x10) ==
                                    *(int*)(intptr_t)(*(int*)(intptr_t)(*(int*)((char*)self + 0x14) +
                                        *(int*)(param_6 + local_8 * 4) * 4) + 0x10)) {
                                    iVar4 = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x88), 0,
                                                         *(int*)(iVar2 + 0x10), 0);
                                    if (iVar4 == -1) {
                                        return 0x8007000e;
                                    }
                                    iVar3 = *(int*)(intptr_t)(*(int*)((char*)self + 0x14) +
                                                              iVar4 * 4);
                                    *(uint32_t*)(iVar3 + 0x3c) = *(uint32_t*)(iVar2 + 0x3c);
                                    *(uint32_t*)(iVar3 + 0x38) = *(uint32_t*)(param_6 + local_8 * 4);
                                    *(int*)(intptr_t)(*(int*)(iVar1 + 8) + local_c * 4) = iVar4;
                                    break;
                                }
                                local_8 = local_8 + 1;
                            } while (local_8 < param_5);
                        }
                        if (local_8 == param_5) {
                            FUN_006626da();
                            return 0x80004005;
                        }
                    }
                    local_c = local_c + 1;
                } while (local_c < *(uint32_t*)(iVar1 + 4));
            }
            local_10 = local_10 + 1;
        } while (local_10 < param_2);
    }
    return 0;
}

// 0x676149 — observed shape
int FUN_676149(void* self, int param_1, uint32_t param_2, int param_3, int* param_4)
{
    uint32_t* puVar1;
    int iVar2;
    int iVar3;
    bool bVar4;
    int iVar5;
    uint32_t uVar6;
    int* piVar7;
    uint32_t uVar8;
    uint32_t local_18;
    int local_14;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;

    local_8 = 0;
    if (*(int*)((char*)self + 0xc) != 0) {
        do {
            puVar1 = *(uint32_t**)(intptr_t)(*(int*)((char*)self + 0x18) + local_8 * 4);
            if (((puVar1 != (uint32_t*)0x0) && (puVar1[9] != 1)) && (*puVar1 != 0)) {
                bVar4 = false;
                local_10 = 0;
                if (puVar1[3] != 0) {
                    do {
                        local_c = 0;
                        if (param_2 != 0) {
                            do {
                                iVar5 = *(int*)(param_1 + local_c * 4);
                                iVar2 = *(int*)(intptr_t)(*(int*)((char*)self + 0x14) + iVar5 * 4);
                                if ((*(int*)(iVar2 + 4) == *(int*)((char*)self + 0x80)) &&
                                    (*(int8_t*)(iVar2 + 0x6c) != '\x03')) goto LAB_00676316;
                                iVar3 = *(int*)(intptr_t)(puVar1[4] + local_10 * 4);
                                if ((iVar3 == iVar5) || (iVar3 == *(int*)(iVar2 + 0x38))) {
                                    uVar6 = puVar1[1];
                                    uVar8 = *puVar1 & 0xfffff;
                                    local_18 = 0;
                                    if (uVar6 / uVar8 != 0) {
                                        local_14 = 0;
                                        do {
                                            iVar5 = FUN_676149(self,
                                                              (int)(intptr_t)(puVar1[2] + local_14),
                                                              uVar8, param_3, param_4);
                                            if (iVar5 < 0) {
                                                return iVar5;
                                            }
                                            local_18 = local_18 + 1;
                                            local_14 = local_14 + uVar8 * 4;
                                            bVar4 = true;
                                        } while (local_18 < uVar6 / uVar8);
                                    }
                                }
                                local_c = local_c + 1;
                            } while (local_c < param_2);
                        }
                        local_10 = local_10 + 1;
                    } while (local_10 < puVar1[3]);
                    if (bVar4) {
                        uVar6 = *puVar1 & 0xfff00000;
                        if ((((uVar6 == 0x60000000) || (uVar6 == 0x60500000)) ||
                            ((uVar6 == 0x60a00000 ||
                              (((uVar6 == 0x60f00000 || (uVar6 == 0x72c00000)) ||
                                (uVar6 == 0x72d00000)))))) ||
                            (uVar6 == 0x11000000)) {
                            uVar8 = *puVar1 & 0xfffff;
                            uVar6 = uVar8 * 2;
                            if (uVar8 < uVar6) {
                                piVar7 = (int*)(intptr_t)(puVar1[2] + uVar8 * 4);
                                do {
                                    if (*(int*)(intptr_t)(*(int*)(intptr_t)(*(int*)((char*)self + 0x14) +
                                            *piVar7 * 4) + 4) == *(int*)((char*)self + 0x88)) {
LAB_00676316:
                                        FUN_006626da();
                                        return -0x7fffbffb;
                                    }
                                    uVar8 = uVar8 + 1;
                                    piVar7 = piVar7 + 1;
                                } while (uVar8 < uVar6);
                            }
                        }
                        *(uint32_t**)(intptr_t)(param_3 + *param_4 * 4) = puVar1;
                        *(int*)(intptr_t)(*(int*)(intptr_t)(*(int*)((char*)self + 0x18) +
                                            local_8 * 4) + 0x24) = 1;
                        *param_4 = *param_4 + 1;
                    }
                }
            }
            local_8 = local_8 + 1;
        } while (local_8 < *(uint32_t*)((char*)self + 0xc));
    }
    return 0;
}

// 0x676329 — observed shape
int FUN_676329(void* self, int param_1, int* param_2, int param_3, uint32_t param_4,
               uint32_t param_5, int* param_6)
{
    uint32_t* puVar1;
    int* piVar2;
    uint32_t* puVar3;
    uint32_t uVar4;
    int iVar5;
    uint32_t uVar6;
    int iVar7;
    int* piVar8;
    bool bVar9;
    uint32_t local_4c[6];
    int aiStack_34[4];
    int local_24[4];
    uint32_t* local_14;
    int* local_10;
    uint32_t* local_c;
    uint32_t local_8;

    local_8 = 0;
    puVar3 = local_4c;
    for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
    }
    if (param_4 + (int)(intptr_t)param_6 != 0) {
        local_10 = (int*)(intptr_t)(param_5 + param_4 * -4);
        do {
            if (local_8 < param_4) {
                puVar3 = *(uint32_t**)(param_3 + local_8 * 4);
            }
            else {
                puVar3 = (uint32_t*)(intptr_t)*local_10;
            }
            if ((((puVar3 != (uint32_t*)0x0) && (uVar6 = *puVar3 & 0xfff00000, uVar6 != 0)) &&
                 (puVar3[9] != 1)) &&
                ((((((uVar6 != 0x60000000 && (uVar6 != 0x60500000)) &&
                     ((uVar6 != 0x60a00000 &&
                       ((uVar6 != 0x60f00000 && (uVar6 != 0x11000000)))))) &&
                    (uVar6 != 0x72c00000)) && (uVar6 != 0x72d00000)) || (param_4 <= local_8)))) {
                local_14 = (uint32_t*)(intptr_t)puVar3[1];
                local_c = (uint32_t*)0x0;
                if (local_14 != (uint32_t*)0x0) {
                    piVar8 = (int*)(intptr_t)puVar3[2];
                    do {
                        iVar5 = *(int*)(intptr_t)(*(int*)((char*)self + 0x14) + *piVar8 * 4);
                        if (*(int*)(iVar5 + 4) == *(int*)((char*)self + 0x80)) {
                            if (5 < *(uint8_t*)(iVar5 + 0x6d)) break;
                            if (*(int8_t*)(iVar5 + 0x6c) == '\x03') {
                                puVar3 = local_4c + *(uint8_t*)(iVar5 + 0x6d);
                                if (local_8 < param_4) {
                                    uVar6 = *(int*)(iVar5 + 0x10) + 1;
                                    if (*puVar3 < uVar6) {
                                        *puVar3 = uVar6;
                                    }
                                }
                                else {
                                    uVar6 = *(int*)(iVar5 + 0x10) + 1;
                                    if ((*puVar3 < uVar6) && (*(int*)(iVar5 + 0x3c) != 0)) {
                                        *puVar3 = uVar6;
                                    }
                                }
                            }
                        }
                        local_c = (uint32_t*)(intptr_t)((int)(intptr_t)local_c + 1);
                        piVar8 = piVar8 + 1;
                    } while (local_c < local_14);
                }
            }
            local_8 = local_8 + 1;
            local_10 = local_10 + 1;
        } while (local_8 < param_4 + (int)(intptr_t)param_6);
    }
    local_8 = 0;
    if (*(int*)((char*)self + 0x3c) != 0) {
        puVar3 = local_4c;
        local_14 = (uint32_t*)(intptr_t)(param_1 - (int)(intptr_t)puVar3);
        do {
            uVar6 = *puVar3;
            if (uVar6 != 0) {
                iVar5 = FUN_0065d0b4();
                if (iVar5 == 0) {
                    local_c = (uint32_t*)0x0;
                }
                else {
                    local_c = (uint32_t*)(intptr_t)FUN_0065cc1a();
                }
                if (local_c == (uint32_t*)0x0) {
                    return -0x7ff8fff2;
                }
                iVar5 = FUN_0065d0ff((int)(uVar6 & 0xfffff | 0x72100000), (int)uVar6, (int)uVar6, 0);
                if (iVar5 < 0) goto LAB_00676624;
                uVar6 = 0;
                if (*puVar3 != 0) {
                    do {
                        iVar5 = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x88), local_8, uVar6, 0);
                        local_24[uVar6] = iVar5;
                        if (iVar5 == -1) goto LAB_006765f7;
                        *(int*)(intptr_t)(local_c[4] + uVar6 * 4) = iVar5;
                        iVar5 = *(int*)(intptr_t)(*(int*)((char*)self + 0x14) + iVar5 * 4);
                        *(uint32_t*)(iVar5 + 0x3c) = 0;
                        *(uint32_t*)(iVar5 + 0x38) = 0xffffffff;
                        uVar6 = uVar6 + 1;
                        uVar4 = *puVar3;
                        *(uint32_t*)(iVar5 + 0x6c) = (local_8 << 8) | 3;
                    } while (uVar6 < uVar4);
                }
                uVar6 = *puVar3;
                iVar5 = FUN_00675ec3(param_3, (int)param_4, 3, (int)local_8, (int)uVar6, local_24);
                if ((iVar5 < 0) ||
                    (iVar5 = (int)FUN_67601a(self, (int)(intptr_t)param_5, param_6, 3,
                                             local_8, uVar6, local_24), iVar5 < 0))
                    goto LAB_00676624;
                uVar6 = 0;
                if (*puVar3 != 0) {
                    do {
                        iVar5 = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x80), local_8, uVar6, 0);
                        aiStack_34[uVar6] = iVar5;
                        if (iVar5 == -1) goto LAB_006765f7;
                        iVar7 = *(int*)(intptr_t)(*(int*)((char*)self + 0x14) + iVar5 * 4);
                        *(uint32_t*)(iVar7 + 0x3c) = 0;
                        *(uint32_t*)(iVar7 + 0x6c) = (local_8 << 8) | 3;
                        *(int*)(intptr_t)(local_c[2] + uVar6 * 4) = iVar5;
                        uVar6 = uVar6 + 1;
                    } while (uVar6 < *puVar3);
                }
                puVar1 = (uint32_t*)(intptr_t)((int)(intptr_t)local_14 + (int)(intptr_t)puVar3);
                if (*puVar1 != 0) {
                    FUN_006626da();
                    iVar5 = -0x7fffbffb;
                    goto LAB_00676624;
                }
                iVar5 = FUN_0065d8c2();
                if (iVar5 < 0) {
                    return iVar5;
                }
                *puVar1 = (uint32_t)(uintptr_t)local_c;
            }
            local_8 = local_8 + 1;
            puVar3 = puVar3 + 1;
        } while (local_8 < *(uint32_t*)((char*)self + 0x3c));
    }
    param_5 = 1;
    do {
        local_8 = 0;
        if (param_4 != 0) {
            local_c = (uint32_t*)(intptr_t)(param_3 + param_4 * -4);
            do {
                if (0x1ff < local_8) goto LAB_00676a39;
                if (local_8 < param_4) {
                    puVar3 = *(uint32_t**)(param_3 + local_8 * 4);
                }
                else {
                    puVar3 = (uint32_t*)(intptr_t)*local_c;
                }
                if ((puVar3 != (uint32_t*)0x0) && (puVar3[9] != 1)) {
                    uVar6 = *puVar3 & 0xfff00000;
                    if (((uVar6 == 0x60000000) ||
                         (((uVar6 == 0x60500000 || (uVar6 == 0x60a00000)) ||
                           (uVar6 == 0x60f00000)))) ||
                        (((uVar6 == 0x11000000 || (uVar6 == 0x72c00000)) ||
                          (uVar6 == 0x72d00000)))) {
                        uVar4 = *puVar3 & 0xfffff;
                        if (uVar6 == 0x11000000) {
                            uVar4 = 0;
                        }
                        iVar5 = *(int*)(intptr_t)(*(int*)((char*)self + 0x14) +
                                     ((int*)(intptr_t)puVar3[2])[uVar4] * 4);
                        iVar7 = 0;
                        if (uVar4 != 0) {
                            iVar7 = *(int*)(intptr_t)(*(int*)((char*)self + 0x14) +
                                          *(int*)(intptr_t)puVar3[2] * 4);
                        }
                        local_14 = *(uint32_t**)(iVar5 + 4);
                        if (((local_14 == *(uint32_t**)((char*)self + 0x80)) &&
                             ((*(uint32_t*)((char*)self + 200) & 0xffff) != 0x104)) &&
                            (param_5 == 1)) {
                            uVar6 = (uint32_t)*(uint8_t*)(iVar5 + 0x6d);
                            if (5 < uVar6) break;
                            if (iVar7 != 0) {
                                if ((*(uint16_t*)(intptr_t)(*(int*)(intptr_t)(*(int*)((char*)self + 0x10) +
                                        *(int*)(iVar7 + 4) * 4) + 4) & 0x840) == 0) {
                                    *(uint32_t*)(iVar7 + 0xc) = uVar6;
                                }
                                else if (uVar6 != *(uint32_t*)(iVar7 + 0xc)) goto LAB_006769f0;
                            }
                            piVar8 = (int*)((char*)self + 0x424 + uVar6 * 4);
                            if ((*piVar8 != -1) ||
                                (local_10 = (int*)(intptr_t)(param_1 + uVar6 * 4), *local_10 != 0)) {
LAB_006769f0:
                                FUN_006626da();
                                return -0x7fffbffb;
                            }
                            if (iVar7 != 0) {
                                *(uint32_t*)((char*)self + 0x40c + uVar6 * 4) =
                                    *(uint32_t*)(iVar7 + 4);
                                *piVar8 = *(int*)(intptr_t)puVar3[2];
                                iVar5 = FUN_0065d9d5(*(uint32_t*)(iVar7 + 4),
                                                     *(uint32_t*)(iVar7 + 0xc),
                                                     *(uint32_t*)(iVar7 + 0x10),
                                                     *(double*)(iVar7 + 0x20));
                                uVar4 = 0;
                                if ((*puVar3 & 0xfffff) != 0) {
                                    do {
                                        *(int*)(intptr_t)(puVar3[2] + uVar4 * 4) = iVar5;
                                        uVar4 = uVar4 + 1;
                                    } while (uVar4 < (*puVar3 & 0xfffff));
                                }
                                local_14 = *(uint32_t**)(intptr_t)(*(int*)((char*)self + 0x14) +
                                                                  iVar5 * 4);
                                FUN_0065d501();
                                local_14[3] = uVar6;
                                *(uint32_t*)(iVar7 + 0x40) = 1;
                                local_14[0x10] = 0;
                            }
                            *local_10 = (int)(intptr_t)puVar3;
                        }
                        else {
                            if (param_5 != 2) goto LAB_00676977;
                            if (iVar7 == 0) {
LAB_00676888:
                                uVar6 = 0;
                                bVar9 = *(int*)((char*)self + 0x4c) == 0;
                                if (*(int*)((char*)self + 0x4c) != 0) {
                                    param_6 = (int*)((char*)self + 0x424);
                                    do {
                                        if ((*(int*)(param_1 + uVar6 * 4) == 0) &&
                                            ((*param_6 == *(int*)(intptr_t)puVar3[2] ||
                                              (*param_6 == -1)))) break;
                                        param_6 = param_6 + 1;
                                        uVar6 = uVar6 + 1;
                                    } while (uVar6 < *(uint32_t*)((char*)self + 0x4c));
                                    bVar9 = uVar6 == *(uint32_t*)((char*)self + 0x4c);
                                }
                                if (bVar9) {
LAB_00676a39:
                                    FUN_006626da();
                                    return -0x7fffbffb;
                                }
                                if (iVar7 != 0) {
                                    if (((*(uint32_t*)((char*)self + 200) & 0xffff) == 0x104) ||
                                        (local_14 == *(uint32_t**)((char*)self + 0x80))) {
                                        *(uint32_t*)((char*)self + 0x40c + uVar6 * 4) =
                                            *(uint32_t*)(iVar7 + 4);
                                        *(uint32_t*)((char*)self + 0x424 + uVar6 * 4) =
                                            *(uint32_t*)(intptr_t)puVar3[2];
                                    }
                                    iVar5 = FUN_0065d9d5(*(uint32_t*)(iVar7 + 4),
                                                         *(uint32_t*)(iVar7 + 0xc),
                                                         *(uint32_t*)(iVar7 + 0x10),
                                                         *(double*)(iVar7 + 0x20));
                                    uVar4 = 0;
                                    if ((*puVar3 & 0xfffff) != 0) {
                                        do {
                                            *(int*)(intptr_t)(puVar3[2] + uVar4 * 4) = iVar5;
                                            uVar4 = uVar4 + 1;
                                        } while (uVar4 < (*puVar3 & 0xfffff));
                                    }
                                    local_14 = *(uint32_t**)(intptr_t)(*(int*)((char*)self + 0x14) +
                                                                      iVar5 * 4);
                                    FUN_0065d501();
                                    local_14[3] = uVar6;
                                    *(uint32_t*)(iVar7 + 0x40) = 1;
                                    local_14[0x10] = 0;
                                }
                            }
                            else {
                                local_10 = *(int**)(intptr_t)(*(int*)((char*)self + 0x10) +
                                                             *(int*)(iVar7 + 4) * 4);
                                uVar6 = *(uint32_t*)(iVar7 + 0xc);
                                if (5 < uVar6) break;
                                if ((*(uint16_t*)((char*)local_10 + 4) & 0x840) == 0)
                                    goto LAB_00676888;
                                piVar8 = (int*)((char*)self + 0x424 + uVar6 * 4);
                                iVar5 = *piVar8;
                                if ((iVar5 == -1) && (*(int*)(param_1 + uVar6 * 4) == 0)) {
                                    *(int*)((char*)self + 0x40c + uVar6 * 4) =
                                        *(int*)(iVar7 + 4);
                                    *piVar8 = *(int*)(intptr_t)puVar3[2];
                                }
                                else {
                                    if (iVar5 != *(int*)(intptr_t)puVar3[2]) goto LAB_00676a39;
                                    if (*(int*)(param_1 + uVar6 * 4) != 0) goto LAB_006769f0;
                                }
                            }
                            *(uint32_t**)(intptr_t)(param_1 + uVar6 * 4) = puVar3;
                        }
                        *(uint32_t*)(intptr_t)(*(int*)(param_3 + local_8 * 4) + 0x24) = 1;
                    }
                }
LAB_00676977:
                local_8 = local_8 + 1;
                local_c = local_c + 1;
            } while (local_8 < param_4);
        }
        param_5 = param_5 + 1;
        if (2 < param_5) {
            local_8 = 0;
            if (*(int*)((char*)self + 0x3c) != 0) {
                do {
                    piVar8 = (int*)(intptr_t)(param_1 + local_8 * 4);
                    if (*piVar8 == 0) {
                        iVar5 = FUN_0065d0b4();
                        if (iVar5 == 0) {
                            iVar5 = 0;
                        }
                        else {
                            iVar5 = FUN_0065cc1a();
                        }
                        *piVar8 = iVar5;
                        if (iVar5 == 0) {
                            return -0x7ff8fff2;
                        }
                        FUN_0065d0ff(0, 0, 0, 0);
                        FUN_0065d8c2();
                    }
                    local_8 = local_8 + 1;
                } while (local_8 < *(uint32_t*)((char*)self + 0x3c));
            }
            uVar6 = 0;
            *param_2 = *(int*)((char*)self + 0x3c);
            if (param_4 != 0) {
                do {
                    piVar8 = (int*)(intptr_t)(param_3 + uVar6 * 4);
                    piVar2 = (int*)(intptr_t)*piVar8;
                    if (((piVar2 != (int*)0x0) && (piVar2[9] != 1)) && (*piVar2 != 0)) {
                        *(int*)(intptr_t)(param_1 + *param_2 * 4) = *piVar8;
                        *param_2 = *param_2 + 1;
                        *(uint32_t*)(intptr_t)(*piVar8 + 0x24) = 1;
                    }
                    uVar6 = uVar6 + 1;
                } while (uVar6 < param_4);
            }
            return 0;
        }
    } while (true);
LAB_006765f7:
    iVar5 = -0x7ff8fff2;
LAB_00676624:
    FUN_00614343();
    return iVar5;
}

// 0x676ac7 — observed shape
int FUN_676ac7(void* self)
{
    uint8_t bVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    uint32_t* puVar4;
    int iVar5;
    int iVar6;
    uint32_t uVar7;
    int* piVar8;
    uint32_t* puVar9;
    bool bVar10;
    int local_74[6];
    int local_5c[6];
    uint32_t local_44[6];
    uint32_t local_2c;
    uint32_t local_28;
    uint32_t local_24;
    uint32_t local_20;
    int* local_1c;
    int local_18;
    uint32_t* local_14;
    uint32_t local_10;
    uint32_t* local_c;
    uint32_t local_8;

    local_14 = (uint32_t*)0x0;
    local_c = (uint32_t*)0x0;
    iVar6 = 6;
    piVar8 = local_5c;
    for (iVar5 = iVar6; iVar5 != 0; iVar5 = iVar5 + -1) {
        *piVar8 = 0;
        piVar8 = piVar8 + 1;
    }
    piVar8 = local_74;
    for (iVar5 = iVar6; iVar5 != 0; iVar5 = iVar5 + -1) {
        *piVar8 = 0;
        piVar8 = piVar8 + 1;
    }
    puVar9 = local_44;
    for (iVar5 = iVar6; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar9 = 0;
        puVar9 = puVar9 + 1;
    }
    puVar4 = (uint32_t*)((char*)self + 0x40c);
    for (iVar5 = iVar6; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar4 = 0xffffffff;
        puVar4 = puVar4 + 1;
    }
    puVar4 = (uint32_t*)((char*)self + 0x424);
    for (; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar4 = 0xffffffff;
        puVar4 = puVar4 + 1;
    }
    local_18 = 1;
    local_20 = 0;
    local_8 = 0;
    if (*(int*)((char*)self + 0xc) != 0) {
        do {
            puVar9 = *(uint32_t**)(intptr_t)(*(int*)((char*)self + 0x18) + local_8 * 4);
            uVar3 = *puVar9;
            uVar7 = uVar3 & 0xfff00000;
            puVar9[9] = 0;
            if ((((uVar7 == 0x60000000) || (uVar7 == 0x60500000)) || (uVar7 == 0x60a00000)) ||
                (uVar7 == 0x60f00000)) {
LAB_00676cfd:
                if (uVar7 == 0x11000000) {
LAB_00676d05:
                    iVar6 = *(int*)(intptr_t)puVar9[2];
                }
                else {
                    iVar6 = *(int*)(intptr_t)(puVar9[2] + (uVar3 & 0xfffff) * 4);
                }
                iVar6 = *(int*)(intptr_t)(*(int*)((char*)self + 0x14) + iVar6 * 4);
                if ((*(int*)(iVar6 + 4) == *(int*)((char*)self + 0x80)) &&
                    (*(int*)(iVar6 + 0x3c) == 0)) {
                    if (*(int8_t*)(iVar6 + 0x6c) != '\x03') goto LAB_00676fd4;
                    if ((local_5c[*(uint8_t*)(iVar6 + 0x6d)] != 0) &&
                        ((*(uint32_t*)((char*)self + 200) & 0xffff) != 0x104)) {
                        local_18 = 0;
                    }
                    local_5c[*(uint8_t*)(iVar6 + 0x6d)] = 1;
                }
                else {
                    local_18 = 0;
                }
            }
            else {
                if (uVar7 == 0x11000000) goto LAB_00676d05;
                if ((uVar7 == 0x72c00000) || (uVar7 == 0x72d00000)) goto LAB_00676cfd;
                uVar7 = uVar3 & 0xfffff;
                local_28 = uVar7;
                if ((uVar7 != 0) && (uVar3 != 0)) {
                    local_10 = 0;
                    if (puVar9[1] != 0) {
                        local_2c = puVar9[1];
                        local_1c = (int*)(intptr_t)puVar9[2];
                        do {
                            iVar6 = *(int*)(intptr_t)(*(int*)((char*)self + 0x14) +
                                                      *local_1c * 4);
                            if ((*(int*)(iVar6 + 4) == *(int*)((char*)self + 0x80)) &&
                                (bVar1 = *(uint8_t*)(iVar6 + 0x6d),
                                 *(int8_t*)(iVar6 + 0x6c) == '\x03')) {
                                if ((local_5c[bVar1] != 0) &&
                                    (((*(uint32_t*)((char*)self + 200) & 0xffff) != 0x104 &&
                                      (local_44[bVar1] == 0)))) {
                                    local_18 = 0;
                                }
                                local_5c[bVar1] = 1;
                                uVar3 = local_10 + uVar7;
                                bVar10 = local_10 < uVar3;
                                local_74[bVar1] = 1;
                                uVar2 = local_28;
                                if (bVar10) {
                                    local_24 = uVar3 - local_10;
                                    uVar3 = local_44[bVar1];
                                    piVar8 = local_1c;
                                    do {
                                        uVar7 = *(int*)(intptr_t)(*(int*)(intptr_t)
                                                     (*(int*)((char*)self + 0x14) +
                                                      *piVar8 * 4) + 0x10) + 1;
                                        if (uVar3 < uVar7) {
                                            uVar3 = uVar7;
                                        }
                                        piVar8 = piVar8 + 1;
                                        local_24 = local_24 - 1;
                                    } while (local_24 != 0);
                                    local_44[bVar1] = uVar3;
                                    uVar7 = uVar2;
                                }
                            }
                            local_10 = local_10 + uVar7;
                            local_1c = local_1c + uVar7;
                        } while (local_10 < local_2c);
                    }
                    local_20 = local_20 + 1;
                }
            }
            local_8 = local_8 + 1;
        } while (local_8 < *(uint32_t*)((char*)self + 0xc));
        if (0x10 < local_20) {
            local_18 = 0;
        }
    }
    uVar3 = 0;
    if (*(int*)((char*)self + 8) != 0) {
        do {
            iVar6 = uVar3 * 4;
            uVar3 = uVar3 + 1;
            *(uint32_t*)(intptr_t)(*(int*)(intptr_t)(*(int*)((char*)self + 0x14) + iVar6) +
                                   0x40) = 0;
        } while (uVar3 < *(uint32_t*)((char*)self + 8));
    }
    uVar3 = *(uint32_t*)((char*)self + 0xc);
    local_2c = uVar3;
    if (local_18 == 0) {
        iVar6 = FUN_00533c78(0x800);
        *(int*)((char*)self + 0x22c) = iVar6;
        if (iVar6 == 0) {
            return -0x7ff8fff2;
        }
        iVar6 = FUN_00533c78(0x800);
        *(int*)((char*)self + 0x230) = iVar6;
        if (iVar6 == 0) {
            return -0x7ff8fff2;
        }
        local_14 = (uint32_t*)(intptr_t)FUN_00533c78(0x800);
        if (local_14 == (uint32_t*)0x0) {
            return -0x7ff8fff2;
        }
        local_c = (uint32_t*)(intptr_t)FUN_00533c78(0x800);
        puVar4 = *(uint32_t**)((char*)self + 0x22c);
        for (iVar6 = 0x200; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar4 = 0;
            puVar4 = puVar4 + 1;
        }
        puVar4 = *(uint32_t**)((char*)self + 0x230);
        for (iVar6 = 0x200; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar4 = 0;
            puVar4 = puVar4 + 1;
        }
        puVar4 = local_14;
        for (iVar6 = 0x200; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar4 = 0;
            puVar4 = puVar4 + 1;
        }
        puVar4 = local_c;
        for (iVar6 = 0x200; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar4 = 0;
            puVar4 = puVar4 + 1;
        }
        *(uint32_t*)((char*)self + 0x220) = 0;
        *(uint32_t*)((char*)self + 0x224) = 0;
        local_10 = 0;
        local_8 = 0;
        if (*(int*)((char*)self + 0xc) != 0) {
            do {
                if (0x1ff < local_8) {
LAB_00676fd4:
                    FUN_006626da();
                    return -0x7fffbffb;
                }
                puVar9 = *(uint32_t**)(intptr_t)(*(int*)((char*)self + 0x18) + local_8 * 4);
                uVar3 = *puVar9 & 0xfff00000;
                if ((((uVar3 == 0x60000000) || (uVar3 == 0x60500000)) ||
                     (uVar3 == 0x60a00000)) ||
                    (((uVar3 == 0x60f00000 || (uVar3 == 0x11000000)) ||
                      ((uVar3 == 0x72d00000 || (uVar3 == 0x72c00000)))))) {
                    local_24 = *puVar9 & 0xfffff;
                    if (uVar3 == 0x11000000) {
                        local_24 = 0;
                    }
                    piVar8 = (int*)(intptr_t)(puVar9[2] + local_24 * 4);
                    iVar6 = *(int*)(intptr_t)(*(int*)((char*)self + 0x14) + *piVar8 * 4);
                    if ((*(int*)(iVar6 + 4) == *(int*)((char*)self + 0x88)) ||
                        (*(int*)(iVar6 + 0x3c) != 0)) {
                        iVar6 = FUN_676149(self, (int)(intptr_t)piVar8,
                                           puVar9[1] - local_24,
                                           (int)(intptr_t)local_14, (int*)&local_10);
                        if (iVar6 < 0) goto LAB_00676fa3;
                    }
                    else if ((*(int*)(iVar6 + 4) == *(int*)((char*)self + 0x80)) &&
                             ((*(int8_t*)(iVar6 + 0x6c) != '\x03' ||
                               ((local_74[*(uint8_t*)(iVar6 + 0x6d)] != 0 &&
                                 ((*(uint32_t*)((char*)self + 200) & 0xffff) != 0x104)))))) {
                        FUN_006626da();
                        iVar6 = -0x7fffbffb;
                        goto LAB_00676fa3;
                    }
                }
                local_8 = local_8 + 1;
            } while (local_8 < *(uint32_t*)((char*)self + 0xc));
        }
        uVar3 = 0;
        if (local_10 != 0) {
            puVar4 = local_14;
            do {
                *(uint32_t*)(intptr_t)(((int)(intptr_t)local_c -
                                        (int)(intptr_t)local_14) +
                                       (int)(intptr_t)puVar4) = *puVar4;
                *puVar4 = 0;
                uVar3 = uVar3 + 1;
                puVar4 = puVar4 + 1;
            } while (uVar3 < local_10);
        }
        iVar6 = FUN_676329(self, *(int*)((char*)self + 0x230),
                           (int*)((char*)self + 0x224), *(int*)((char*)self + 0x18),
                           local_2c, 0, (int*)0x0);
        if (iVar6 < 0) goto LAB_00676fa3;
        uVar3 = 0;
        if (local_10 != 0) {
            do {
                *(uint32_t*)(intptr_t)(local_c[uVar3] + 0x24) = 0;
                uVar3 = uVar3 + 1;
            } while (uVar3 < local_10);
        }
        iVar6 = FUN_676329(self, *(int*)((char*)self + 0x22c),
                           (int*)((char*)self + 0x220), (int)(intptr_t)local_c,
                           local_10, *(uint32_t*)((char*)self + 0x230),
                           (int*)(intptr_t)*(uint32_t*)((char*)self + 0x4c));
        if (iVar6 < 0) goto LAB_00676fa3;
    }
    else {
        *(uint32_t*)((char*)self + 0x22c) = 0;
        puVar4 = (uint32_t*)(intptr_t)FUN_00533c78(0x800);
        *(uint32_t**)((char*)self + 0x230) = puVar4;
        if (puVar4 == (uint32_t*)0x0) {
            return -0x7ff8fff2;
        }
        for (iVar6 = 0x200; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar4 = 0;
            puVar4 = puVar4 + 1;
        }
        iVar6 = FUN_676329(self, *(int*)((char*)self + 0x230),
                           (int*)((char*)self + 0x224), *(int*)((char*)self + 0x18),
                           uVar3, 0, (int*)0x0);
        if (iVar6 < 0) {
            return iVar6;
        }
    }
    iVar6 = 0;
    uVar3 = 0;
    if (*(int*)((char*)self + 8) != 0) {
        do {
            iVar5 = *(int*)(intptr_t)(*(int*)((char*)self + 0x14) + uVar3 * 4);
            if (*(int*)(iVar5 + 0x40) == 1) {
                *(uint32_t*)(iVar5 + 4) = *(uint32_t*)((char*)self + 0x74);
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint32_t*)((char*)self + 8));
    }
LAB_00676fa3:
    if (local_14 != (uint32_t*)0x0) {
        operator_delete(local_14);
    }
    if (local_c != (uint32_t*)0x0) {
        operator_delete(local_c);
    }
    return iVar6;
}

// 0x677000 — observed shape
uint32_t FUN_677000(void* self, int param_1, uint32_t param_2, uint32_t param_3,
                    int param_4, int param_5, uint32_t* param_6)
{
    int iVar1;
    int iVar2;
    int iVar3;
    uint32_t uVar4;
    uint32_t local_8;

    local_8 = 0;
    *param_6 = 0;
    for (; param_2 < param_3; param_2 = param_2 + 1) {
        iVar1 = *(int*)(param_1 + param_2 * 4);
        uVar4 = 0;
        if ((iVar1 != 0) && (*(int*)(iVar1 + 4) != 0)) {
            do {
                iVar2 = *(int*)(intptr_t)(*(int*)(iVar1 + 8) + uVar4 * 4);
                iVar3 = *(int*)(intptr_t)(*(int*)((char*)self + 0x14) + iVar2 * 4);
                if ((iVar2 == param_4) || (*(int*)(iVar3 + 0x38) == param_4)) {
                    *(uint32_t*)(iVar3 + 0xc) = *(uint32_t*)(param_5 + 0xc);
                    *(uint32_t*)(iVar3 + 0x10) = *(uint32_t*)(param_5 + 0x10);
                    *param_6 = 1;
                    local_8 = param_2;
                }
                uVar4 = uVar4 + 1;
            } while (uVar4 < *(uint32_t*)(iVar1 + 4));
        }
    }
    return local_8;
}

// 0x67707d — observed shape
int FUN_67707d(void* self)
{
    uint32_t uVar1;
    int iVar2;
    int iVar3;
    uint32_t uVar4;

    uVar4 = 0;
    iVar3 = 0;
    uVar1 = (uint32_t)(uintptr_t)FUN_00533c78(*(int*)((char*)self + 0xc) << 2);
    *(uint32_t*)((char*)self + 0x2b4) = uVar1;
    iVar2 = FUN_00533c78(*(int*)((char*)self + 8) << 2);
    *(int*)((char*)self + 0x2b8) = iVar2;
    if ((*(int*)((char*)self + 0x2b4) == 0) || (iVar2 == 0)) {
LAB_0067716b:
        iVar3 = -0x7ff8fff2;
    }
    else {
        if (*(int*)((char*)self + 0xc) != 0) {
            do {
                iVar2 = FUN_0065d0b4(0x74);
                if (iVar2 == 0) {
                    uVar1 = 0;
                }
                else {
                    uVar1 = (uint32_t)FUN_0065cc1a();
                }
                *(uint32_t*)(intptr_t)(*(int*)((char*)self + 0x2b4) + uVar4 * 4) = uVar1;
                if (*(int*)(intptr_t)(*(int*)((char*)self + 0x2b4) + uVar4 * 4) == 0)
                    goto LAB_0067716b;
                iVar3 = FUN_0065d35e(*(uint32_t*)(intptr_t)(*(int*)((char*)self + 0x18) +
                                                           uVar4 * 4));
                if (iVar3 < 0) {
                    return iVar3;
                }
                uVar4 = uVar4 + 1;
            } while (uVar4 < *(uint32_t*)((char*)self + 0xc));
        }
        uVar4 = 0;
        if (*(int*)((char*)self + 8) != 0) {
            do {
                iVar2 = FUN_0065d612(0x80);
                if (iVar2 == 0) {
                    uVar1 = 0;
                }
                else {
                    uVar1 = (uint32_t)FUN_005f6015();
                }
                *(uint32_t*)(intptr_t)(*(int*)((char*)self + 0x2b8) + uVar4 * 4) = uVar1;
                if (*(int*)(intptr_t)(*(int*)((char*)self + 0x2b8) + uVar4 * 4) == 0)
                    goto LAB_0067716b;
                iVar3 = FUN_0065d501(*(uint32_t*)(intptr_t)(*(int*)((char*)self + 0x14) +
                                                           uVar4 * 4));
                if (iVar3 < 0) {
                    return iVar3;
                }
                uVar4 = uVar4 + 1;
            } while (uVar4 < *(uint32_t*)((char*)self + 8));
        }
        *(uint32_t*)((char*)self + 0x2c0) = *(uint32_t*)((char*)self + 0xc);
        *(uint32_t*)((char*)self + 700) = *(uint32_t*)((char*)self + 8);
    }
    return iVar3;
}
