// Reconstruction batch mass_0338 — Sid Meier's Pirates! (2004), PE32 i386
// Provider: Ghidra 12.2 pseudocode. Candidate source, not original.
// Receivers exposed as in_ECX are reconstructed as an explicit `void* self`.

#include <cstdint>
#include <cstddef>

// Referenced helpers (addresses as reported by the provider listings).
extern int  FUN_0065d0b4(int size);
extern int  FUN_0065cc1a();
extern int  FUN_0065d0ff(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
extern int  FUN_0065cc50(uint32_t a);
extern int  FUN_0065d8c2(int a);
extern int  FUN_0065d9d5(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
extern int  FUN_0065d501();
extern int  FUN_0065d5bd();
extern void FUN_00614343(uint32_t a);
extern void FUN_006626da(int ctx, uint32_t handle, uint64_t err);
extern int  FUN_0069da66();
extern uint64_t FUN_0069da9c();
extern int  FUN_0069dad2(uint32_t* node, int a);
extern int  FUN_0065db2e();
extern int  FUN_0069dfba(void* self, int param_1, int param_2, uint32_t* param_3,
                          int param_4, int param_5, int* param_6, uint32_t param_7,
                          int* param_8, int param_9, uint32_t param_10, uint32_t param_11);

// 0x69dfba — observed shape
int* FUN_0069dfba(void* self, int param_1, int param_2, uint32_t* param_3,
                  int param_4, int param_5, int* param_6, uint32_t param_7,
                  int* param_8, int param_9, uint32_t param_10, uint32_t param_11)
{
    uint32_t* puVar1;
    int iVar2;
    int* piVar3;
    uint32_t uVar4;
    int in_ECX = (int)(intptr_t)self;
    uint32_t uVar5;
    int extraout_ECX;
    int iVar6;
    uint32_t* puVar7;
    int* piVar8;
    uint32_t* puVar9;
    uint64_t uVar10;
    uint32_t uVar11;
    char* pcVar12;
    uint32_t local_83c[128];
    int local_63c[128];
    uint32_t local_43c[128];
    int local_23c[128];
    uint32_t local_3c;
    uint32_t local_38;
    int* local_34;
    uint32_t local_30;
    uint32_t local_2c;
    int local_28;
    int* local_24;
    uint32_t local_20;
    uint32_t local_1c;
    uint32_t local_18;
    int* local_14;
    int* local_10;
    uint32_t local_c;
    int* local_8;

    uVar4 = *param_3;
    local_28 = in_ECX;
joined_r0x0069dfd8:
    local_c = uVar4;
    if (param_7 <= local_c) {
        return (int*)0x0;
    }
    piVar3 = (int*)0x0;
    puVar1 = *(uint32_t**)(*(int*)(in_ECX + 0x18) + local_c * 4);
    local_18 = *puVar1 & 0xfff00000;
    local_14 = (int*)(*puVar1 & 0xfffff);
    if (puVar1[3] == 0) {
        uVar10 = 0x6f3600000012dfULL;
        goto LAB_0069e7ec;
    }
    local_10 = *(int**)(*(int*)(in_ECX + 0x14) + *(int*)puVar1[4] * 4);
    if (local_10[5] != param_1) {
        if (local_18 != 0x20700000) {
LAB_0069e82e:
            *param_3 = local_c;
            return (int*)0x0;
        }
        if (param_9 == 0) {
            piVar8 = (int*)puVar1[2];
            local_18 = *(uint32_t*)(*(int*)(in_ECX + 0x14) + *piVar8 * 4);
            if (*(int*)(local_18 + 0x14) !=
                *(int*)(*(int*)(*(int*)(in_ECX + 0x14) + piVar8[(int)local_14] * 4) + 0x14)) {
                pcVar12 = (char*)"internal error: if block with non matching predicates found";
                goto LAB_0069e7db;
            }
            if (((param_4 == 0) || (param_5 == 0)) || (param_6 == (int*)0x0)) {
                pcVar12 = (char*)"internal error: unexpected endif found";
LAB_0069e7b1:
                uVar10 = ((uint64_t)(uintptr_t)pcVar12 << 32) | 0x12e1;
                goto LAB_0069e7ec;
            }
            if (*(int*)(local_18 + 0x14) != param_1) goto LAB_0069e82e;
            if (param_8 == (int*)0x0) goto LAB_0069e2f1;
            local_20 = 1;
            local_24 = (int*)0x0;
            if (*(int*)(local_18 + 0x18) != param_2) {
                local_24 = local_14;
            }
            if (local_14 != (int*)0x0) {
                local_10 = (int*)puVar1[4];
                local_8 = piVar8 + (int)local_24;
                local_34 = local_14;
                do {
                    iVar2 = *(int*)(*(int*)(in_ECX + 0x14) + *local_10 * 4);
                    iVar6 = *(int*)(*(int*)(in_ECX + 0x14) + *local_8 * 4);
                    if (((*(int*)(iVar2 + 0xc) != *(int*)(iVar6 + 0xc)) ||
                         (*(int*)(iVar2 + 0x10) != *(int*)(iVar6 + 0x10))) ||
                        ((*(int*)(iVar2 + 8) != *(int*)(iVar6 + 8) ||
                          ((*(int*)(iVar2 + 4) != *(int*)(iVar6 + 4) ||
                            (*(int*)(iVar2 + 0x3c) != *(int*)(iVar6 + 0x3c))))))) {
                        local_20 = 0;
                    }
                    local_10 = local_10 + 1;
                    local_8 = local_8 + 1;
                    local_34 = (int*)((int)local_34 - 1);
                } while (local_34 != (int*)0x0);
            }
            if (0x7f < (uint32_t)(*param_6 + (int)local_14)) {
                uVar10 = 0x6f355000001194ULL;
                goto LAB_0069e7ec;
            }
            if (local_20 == 0) {
                iVar2 = FUN_0065d0b4(0);
                if (iVar2 == 0) {
                    local_8 = (int*)0x0;
                } else {
                    local_8 = (int*)FUN_0065cc1a();
                }
                if (local_8 == (int*)0x0) {
                    return (int*)0x8007000e;
                }
                piVar3 = (int*)FUN_0065d0ff((uint32_t)local_14 & 0xfffff | 0x10000000,
                                            (uint32_t)local_14, (uint32_t)local_14, 0);
                if ((((int)piVar3 < 0) || (piVar3 = (int*)FUN_0065cc50(0), (int)piVar3 < 0)) ||
                    (piVar3 = (int*)FUN_0065d8c2(0), (int)piVar3 < 0)) {
LAB_0069e808:
                    FUN_00614343(0);
                    return piVar3;
                }
                if (*(int*)(local_18 + 0x18) == param_2) {
                    puVar7 = (uint32_t*)puVar1[2];
                    puVar9 = (uint32_t*)local_8[2];
                    for (uVar4 = (uint32_t)local_14 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
                        *puVar9 = *puVar7;
                        puVar7 = puVar7 + 1;
                        puVar9 = puVar9 + 1;
                    }
                } else {
                    puVar7 = (uint32_t*)puVar1[2] + (int)local_14;
                    puVar9 = (uint32_t*)local_8[2];
                    for (uVar4 = (uint32_t)local_14 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
                        *puVar9 = *puVar7;
                        puVar7 = puVar7 + 1;
                        puVar9 = puVar9 + 1;
                    }
                }
                local_10 = (int*)0x0;
                for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 - 1) {
                    *(uint8_t*)puVar9 = *(uint8_t*)puVar7;
                    puVar7 = (uint32_t*)((int)puVar7 + 1);
                    puVar9 = (uint32_t*)((int)puVar9 + 1);
                }
                if (local_14 != (int*)0x0) {
                    local_18 = (uint32_t)local_14 << 2;
                    do {
                        uVar11 = FUN_0065d9d5(*(uint32_t*)(local_28 + 0x88), 0, 0, 0);
                        *(uint32_t*)(param_4 + (*param_6 + (int)local_10) * 4) = uVar11;
                        iVar2 = *(int*)(param_4 + (*param_6 + (int)local_10) * 4);
                        if (iVar2 == -1) {
                            piVar3 = (int*)0x8007000e;
                            goto LAB_0069e808;
                        }
                        local_34 = *(int**)(*(int*)(local_28 + 0x14) + iVar2 * 4);
                        iVar6 = (int)local_10 * 4;
                        local_20 = *(uint32_t*)(*(int*)(local_28 + 0x14) +
                                                *(int*)(iVar6 + puVar1[4]) * 4);
                        iVar2 = FUN_0065d501();
                        if ((iVar2 < 0) || (iVar2 = FUN_0065d5bd(), iVar2 < 0)) {
                            FUN_00614343(0);
                            return (int*)0x8007000e;
                        }
                        *(uint32_t*)(iVar6 + local_8[4]) =
                            *(uint32_t*)(param_4 + (*param_6 + (int)local_10) * 4);
                        *(uint32_t*)(param_5 + (*param_6 + (int)local_10) * 4) =
                            *(uint32_t*)(iVar6 + puVar1[4]);
                        iVar2 = *(int*)(puVar1[2] + iVar6);
                        if (*(int*)(*(int*)(*(int*)(local_28 + 0x14) + iVar2 * 4) + 0x18) == param_2) {
                            *(int*)(iVar6 + local_8[2]) = iVar2;
                        } else {
                            *(uint32_t*)(iVar6 + local_8[2]) = *(uint32_t*)(puVar1[2] + local_18);
                        }
                        local_10 = (int*)((int)local_10 + 1);
                        local_18 = local_18 + 4;
                    } while (local_10 < local_14);
                }
            } else if (local_14 != (int*)0x0) {
                local_24 = (int*)((int)local_24 << 2);
                do {
                    puVar7 = (uint32_t*)((int)local_24 + puVar1[2]);
                    local_24 = (int*)((int)local_24 + 1);
                    *(uint32_t*)(param_4 + (*param_6 + (int)piVar3) * 4) = *puVar7;
                    iVar2 = (int)piVar3 * 4;
                    iVar6 = *param_6 + (int)piVar3;
                    piVar3 = (int*)((int)piVar3 + 1);
                    *(uint32_t*)(param_5 + iVar6 * 4) = *(uint32_t*)(puVar1[4] + iVar2);
                } while (piVar3 < local_14);
            }
            *param_6 = *param_6 + (int)local_14;
            uVar4 = local_c + 1;
            in_ECX = local_28;
            goto joined_r0x0069dfd8;
        }
LAB_0069e2f1:
        uVar4 = local_c + 1;
        goto joined_r0x0069dfd8;
    }
    if ((param_9 != 0) && (local_18 != 0x11200000)) goto LAB_0069e2f1;
    local_8 = param_8;
    if ((param_8 != (int*)0x0) && (local_10[6] != param_2)) {
        local_8 = (int*)0x0;
    }
    iVar2 = FUN_0069da66();
    if (iVar2 != 0) {
        if (local_14 != (int*)0x1) {
            pcVar12 = (char*)"internal error: IF with size greater then 1 found";
LAB_0069e7db:
            uVar10 = ((uint64_t)(uintptr_t)pcVar12 << 32) | 0x12e0;
            goto LAB_0069e7ec;
        }
        if (local_8 != (int*)0x0) {
            iVar2 = FUN_0069dad2(puVar1, 1);
            if (iVar2 == 0) {
                return (int*)0x8007000e;
            }
            piVar3 = (int*)FUN_0065d8c2(0);
            if ((int)piVar3 < 0) {
                return piVar3;
            }
        }
        local_30 = local_c + 1;
        local_38 = 0;
        local_1c = 0;
        local_c = local_30;
        piVar3 = (int*)FUN_0069dfba((void*)(uintptr_t)*(uint32_t*)puVar1[4], 1, &local_30,
                                    local_43c, local_23c, (int*)&local_1c, param_7, local_8, 0, 0, 0);
        if ((int)piVar3 < 0) {
            return piVar3;
        }
        if (local_8 != (int*)0x0) {
            iVar2 = FUN_0069dad2(puVar1, 0);
            if (iVar2 == 0) {
                return (int*)0x8007000e;
            }
            piVar3 = (int*)FUN_0065d8c2(0);
            if ((int)piVar3 < 0) {
                return piVar3;
            }
        }
        local_30 = local_c;
        piVar3 = (int*)FUN_0069dfba((void*)(uintptr_t)*(uint32_t*)puVar1[4], 0, &local_30,
                                    local_83c, local_63c, (int*)&local_38, param_7, local_8, 0, 0, 0);
        if ((int)piVar3 < 0) {
            return piVar3;
        }
        if (local_8 != (int*)0x0) {
            local_18 = 1;
            if (local_1c != local_38) {
LAB_0069e7ac:
                pcVar12 = (char*)"internal error: endif mismatch";
                goto LAB_0069e7b1;
            }
            uVar4 = 0;
            if (local_38 != 0) {
                do {
                    if (local_63c[uVar4] != local_23c[uVar4]) {
                        local_18 = 0;
                    }
                    uVar4 = uVar4 + 1;
                } while (uVar4 < local_38);
                if (local_18 == 0) goto LAB_0069e7ac;
            }
            iVar2 = FUN_0065d0b4(0);
            if (iVar2 == 0) {
                uVar4 = 0;
            } else {
                uVar4 = (uint32_t)FUN_0065cc1a();
            }
            if (uVar4 == 0) {
                return (int*)0x8007000e;
            }
            local_18 = uVar4;
            local_8 = (int*)FUN_0065d0ff(local_38 & 0xfffff | 0x73400000, local_38 * 2, local_38, 0);
            if ((int)local_8 < 0) {
LAB_0069e7bc:
                FUN_00614343(0);
                return local_8;
            }
            piVar3 = (int*)FUN_0065cc50(0);
            if ((int)piVar3 < 0) {
LAB_0069e7cb:
                FUN_00614343(0);
                return piVar3;
            }
            piVar3 = local_63c;
            piVar8 = *(int**)(uVar4 + 0x10);
            for (uVar5 = local_1c; uVar5 != 0; uVar5 = uVar5 - 1) {
                *piVar8 = *piVar3;
                piVar3 = piVar3 + 1;
                piVar8 = piVar8 + 1;
            }
            puVar7 = local_43c;
            puVar9 = *(uint32_t**)(uVar4 + 8);
            for (uVar5 = local_1c; uVar5 != 0; uVar5 = uVar5 - 1) {
                *puVar9 = *puVar7;
                puVar7 = puVar7 + 1;
                puVar9 = puVar9 + 1;
            }
            puVar7 = local_83c;
            puVar9 = (uint32_t*)(*(int*)(uVar4 + 8) + local_1c * 4);
            for (uVar5 = local_1c & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
                *puVar9 = *puVar7;
                puVar7 = puVar7 + 1;
                puVar9 = puVar9 + 1;
            }
            for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 - 1) {
                *(uint8_t*)puVar9 = *(uint8_t*)puVar7;
                puVar7 = (uint32_t*)((int)puVar7 + 1);
                puVar9 = (uint32_t*)((int)puVar9 + 1);
            }
            piVar3 = (int*)FUN_0065d8c2(0);
            if ((int)piVar3 < 0) {
                return piVar3;
            }
            in_ECX = local_28;
        }
        local_10[1] = *(int*)(in_ECX + 0x74);
        uVar4 = local_30;
        goto joined_r0x0069dfd8;
    }
    uVar10 = FUN_0069da9c();
    if ((int)uVar10 == 0) {
        if ((extraout_ECX != 0x11100000) && (extraout_ECX != 0x74100000)) {
            if (extraout_ECX == 0x11200000) {
                if ((local_8 != (int*)0x0) && (param_9 != 0)) {
                    piVar3 = (int*)0x0;
                    if (local_14 != (int*)0x0) {
                        do {
                            iVar2 = *(int*)(*(int*)(in_ECX + 0x14) +
                                            *(int*)(puVar1[4] + (int)piVar3 * 4) * 4);
                            *(uint32_t*)(iVar2 + 0x34) = param_11;
                            piVar3 = (int*)((int)piVar3 + 1);
                            *(uint32_t*)(iVar2 + 0x30) = param_10;
                        } while (piVar3 < local_14);
                    }
                    goto LAB_0069e2e1;
                }
            } else if ((param_8 != (int*)0x0) &&
                       (*(int*)((int)((uint64_t)uVar10 >> 0x20) + 0x18) == param_2)) {
LAB_0069e2e1:
                piVar3 = (int*)FUN_0065db2e();
                if ((int)piVar3 < 0) {
                    return piVar3;
                }
            }
            goto LAB_0069e2f1;
        }
        local_2c = local_c + 1;
        local_1c = 0;
        local_c = local_2c;
        piVar3 = (int*)FUN_0069dfba((void*)(uintptr_t)*(uint32_t*)puVar1[4], 1, &local_2c,
                                    local_43c, local_23c, (int*)&local_1c, param_7, local_8, 1,
                                    param_1, param_2);
        if ((int)piVar3 < 0) {
            return piVar3;
        }
        if (local_8 != (int*)0x0) {
            if (local_18 == 0x11100000) {
                local_20 = (uint32_t)local_14 & 0xfffff;
                *puVar1 = local_20 | 0x74200000;
                piVar3 = (int*)FUN_0065db2e();
                if ((int)piVar3 < 0) {
                    return piVar3;
                }
                *puVar1 = local_20 | 0x11100000;
            } else {
                piVar3 = (int*)FUN_0065db2e();
                if ((int)piVar3 < 0) {
                    return piVar3;
                }
            }
            local_10[1] = *(int*)(in_ECX + 0x74);
        }
        local_2c = local_c;
        piVar3 = (int*)FUN_0069dfba((void*)(uintptr_t)*(uint32_t*)puVar1[4], 1, &local_2c,
                                    local_43c, local_23c, (int*)&local_1c, param_7, local_8, 0, 0, 0);
        if ((int)piVar3 < 0) {
            return piVar3;
        }
        uVar4 = local_2c;
        if (local_8 == (int*)0x0) goto joined_r0x0069dfd8;
        local_20 = FUN_0065d9d5(*(uint32_t*)(in_ECX + 0xa8), 0, 0, 0);
        if (local_20 == 0xffffffff) {
            return (int*)0x8007000e;
        }
        iVar2 = FUN_0065d0b4(0);
        if (iVar2 == 0) {
            local_10 = (int*)0x0;
        } else {
            local_10 = (int*)FUN_0065cc1a();
        }
        if (local_10 == (int*)0x0) {
            return (int*)0x8007000e;
        }
        if (local_18 == 0x11100000) {
            uVar11 = 0x74b00001;
        } else {
            uVar11 = 0x74a00001;
        }
        local_8 = (int*)FUN_0065d0ff(uVar11, 0, 1, 0);
        if ((int)local_8 < 0) goto LAB_0069e7bc;
        piVar3 = (int*)FUN_0065cc50(0);
        if ((int)piVar3 < 0) goto LAB_0069e7cb;
        *(uint32_t*)local_10[4] = local_20;
        piVar3 = (int*)FUN_0065d8c2(0);
        uVar4 = local_2c;
    } else {
        local_3c = local_c + 1;
        local_1c = 0;
        if (local_8 != (int*)0x0) {
            piVar3 = (int*)FUN_0065db2e();
            if ((int)piVar3 < 0) {
                return piVar3;
            }
            local_10[1] = *(int*)(in_ECX + 0x74);
        }
        piVar3 = (int*)FUN_0069dfba((void*)(uintptr_t)*(uint32_t*)puVar1[4], 1, &local_3c,
                                    local_43c, local_23c, (int*)&local_1c, param_7, local_8, 0, 0, 0);
        uVar4 = local_3c;
    }
    if ((int)piVar3 < 0) {
        return piVar3;
    }
    goto joined_r0x0069dfd8;
}

// 0x69e83f — observed shape
uint32_t* FUN_0069e83f(void* self, uint32_t param_1, int param_2, uint32_t* param_3,
                       int* param_4, uint32_t param_5)
{
    uint32_t* puVar1;
    uint32_t uVar2;
    int in_ECX = (int)(intptr_t)self;
    int* piVar3;
    uint32_t uVar4;
    uint32_t* puVar5;
    int iVar6;
    uint32_t* puVar7;
    uint32_t uVar8;
    uint32_t* puVar9;
    bool bVar10;
    uint32_t local_24[4];
    uint32_t local_14;
    int* local_10;
    uint32_t local_c;
    uint32_t* local_8;

    iVar6 = *(int*)(*(int*)(in_ECX + 0x14) + **(int**)(param_2 + 0x10) * 4);
    local_14 = *(uint32_t*)(iVar6 + 0x48);
    local_c = *(uint32_t*)(iVar6 + 0x54);
    if (local_c != 0xffffffff) {
        local_8 = (uint32_t*)0x0;
        if (*(int*)(param_2 + 4) != 0) {
            piVar3 = *(int**)(param_2 + 8);
            do {
                iVar6 = *(int*)(*(int*)(in_ECX + 0x14) + *piVar3 * 4);
                if (((*(int*)(in_ECX + 0x88) == *(int*)(iVar6 + 4)) &&
                     (uVar8 = *(uint32_t*)(iVar6 + 0x50), local_14 < uVar8)) && (uVar8 < local_c)) {
                    return (uint32_t*)0x0;
                }
                local_8 = (uint32_t*)((int)local_8 + 1);
                piVar3 = piVar3 + 1;
            } while (local_8 < *(uint32_t*)(param_2 + 4));
        }
        puVar1 = *(uint32_t**)(*(int*)(in_ECX + 0x18) + local_c * 4);
        if (param_1 == *puVar1) {
            local_8 = (uint32_t*)0x0;
            if (*(int*)(param_2 + 0xc) != 0) {
                local_10 = *(int**)(param_2 + 0x10);
                do {
                    iVar6 = *(int*)(*(int*)(in_ECX + 0x14) + *local_10 * 4);
                    if (*(uint32_t*)(iVar6 + 0x54) != local_c) {
                        return (uint32_t*)0x0;
                    }
                    if (*(uint32_t*)(iVar6 + 0x58) != local_c) {
                        return (uint32_t*)0x0;
                    }
                    if (*(int*)(param_2 + 0xc) == 1) {
                        bVar10 = *(int*)(iVar6 + 0x5c) == (param_1 & 0xfffff) * param_5;
                    } else {
                        bVar10 = *(int*)(iVar6 + 0x5c) == param_5;
                    }
                    if (!bVar10) {
                        return (uint32_t*)0x0;
                    }
                    local_8 = (uint32_t*)((int)local_8 + 1);
                    local_10 = local_10 + 1;
                } while (local_8 < *(uint32_t*)(param_2 + 0xc));
            }
            uVar8 = *puVar1 & 0xfffff;
            if ((puVar1[3] == uVar8) && (puVar1[1] <= uVar8 * (int)param_4)) {
                local_8 = (uint32_t*)0x0;
                uVar4 = 0;
                if (puVar1[1] != 0) {
                    piVar3 = (int*)puVar1[2];
                    do {
                        iVar6 = *(int*)(*(int*)(in_ECX + 0x14) + *piVar3 * 4);
                        if ((*(int*)(in_ECX + 0x88) == *(int*)(iVar6 + 4)) &&
                            (local_14 < *(uint32_t*)(iVar6 + 0x48))) {
                            return (uint32_t*)0x0;
                        }
                        local_8 = (uint32_t*)((int)local_8 + 1);
                        uVar4 = puVar1[1];
                        piVar3 = piVar3 + 1;
                    } while (local_8 < uVar4);
                }
                local_8 = (uint32_t*)0x0;
                if (uVar4 != 0) {
                    piVar3 = (int*)puVar1[2];
                    do {
                        if (*piVar3 == **(int**)(param_2 + 0x10)) break;
                        local_8 = (uint32_t*)((int)local_8 + 1);
                        piVar3 = piVar3 + 1;
                    } while (local_8 < uVar4);
                }
                if (local_8 != (uint32_t*)uVar4) {
                    if ((uVar8 <= (uint32_t)local_8) && (uVar4 = 0, uVar8 != 0)) {
                        iVar6 = uVar8 << 2;
                        do {
                            puVar5 = (uint32_t*)(puVar1[2] + uVar4 * 4);
                            uVar2 = *puVar5;
                            *puVar5 = *(uint32_t*)(iVar6 + puVar1[2]);
                            *(uint32_t*)(iVar6 + puVar1[2]) = uVar2;
                            uVar4 = uVar4 + 1;
                            iVar6 = iVar6 + 4;
                        } while (uVar4 < uVar8);
                    }
                    if (1 < *(uint32_t*)(param_2 + 0xc)) {
                        puVar5 = *(uint32_t**)(param_2 + 8);
                        local_8 = puVar5 + *(int*)(param_2 + 4);
                        if (puVar5 < puVar5 + *(int*)(param_2 + 4)) {
                            do {
                                if (uVar8 != 0) {
                                    local_10 = *(int**)(param_2 + 0x10);
                                    uVar4 = puVar1[2];
                                    puVar7 = puVar5;
                                    local_14 = uVar8;
                                    do {
                                        param_5 = 0;
                                        param_4 = local_10;
                                        do {
                                            if (*param_4 == *(int*)((uVar4 - (int)puVar5) +
                                                                    (int)puVar7)) {
                                                local_24[param_5] = *puVar7;
                                                break;
                                            }
                                            param_5 = param_5 + 1;
                                            param_4 = param_4 + 1;
                                        } while (param_5 < uVar8);
                                        puVar7 = puVar7 + 1;
                                        local_14 = local_14 - 1;
                                    } while (local_14 != 0);
                                }
                                puVar7 = local_24;
                                puVar9 = puVar5;
                                for (uVar4 = uVar8; uVar4 != 0; uVar4 = uVar4 - 1) {
                                    *puVar9 = *puVar7;
                                    puVar7 = puVar7 + 1;
                                    puVar9 = puVar9 + 1;
                                }
                                for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 - 1) {
                                    *(uint8_t*)puVar9 = *(uint8_t*)puVar7;
                                    puVar7 = (uint32_t*)((int)puVar7 + 1);
                                    puVar9 = (uint32_t*)((int)puVar9 + 1);
                                }
                                puVar5 = puVar5 + uVar8;
                            } while (puVar5 < local_8);
                        }
                    }
                    if (param_3 == (uint32_t*)0x0) {
                        return puVar1;
                    }
                    *param_3 = local_c;
                    return puVar1;
                }
            }
        }
    }
    return (uint32_t*)0x0;
}

// 0x69ea9a — observed shape
uint32_t FUN_0069ea9a(void* self, uint32_t param_1, uint32_t* param_2, int* param_3, int param_4)
{
    uint32_t* puVar1;
    int iVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    int in_ECX = (int)(intptr_t)self;
    int iVar5;
    int* piVar6;
    uint32_t uVar7;
    uint32_t uVar8;
    int* piVar9;
    uint32_t local_18;
    uint32_t local_14;
    int local_10;

    uVar7 = *param_2 & 0xfffff;
    if (uVar7 != 0) {
        uVar3 = param_2[1] / uVar7;
        if (uVar3 != 0) {
            local_10 = 0;
            piVar9 = param_3;
            local_18 = uVar3;
            do {
                iVar5 = *(int*)(*(int*)(in_ECX + 0x14) + *(int*)(local_10 + param_2[2]) * 4);
                uVar4 = *(uint32_t*)(iVar5 + 0x54);
                uVar8 = *(uint32_t*)(iVar5 + 0x48);
                if (uVar8 == 0xffffffff) {
LAB_0069ec2e:
                    *piVar9 = 0;
                } else {
                    puVar1 = *(uint32_t**)(*(int*)(in_ECX + 0x18) + uVar8 * 4);
                    *piVar9 = (int)puVar1;
                    if (uVar7 != 0) {
                        iVar5 = local_10;
                        local_14 = uVar7;
                        do {
                            iVar2 = *(int*)(*(int*)(in_ECX + 0x14) +
                                            *(int*)(iVar5 + param_2[2]) * 4);
                            if (*(int*)(in_ECX + 0x88) != *(int*)(iVar2 + 4)) {
                                *piVar9 = 0;
                            }
                            if (*(int*)(iVar2 + 0x3c) != 0) {
                                *piVar9 = 0;
                            }
                            if ((uVar8 < *(uint32_t*)(iVar2 + 0x50)) &&
                                (*(uint32_t*)(iVar2 + 0x50) < uVar4)) {
                                *piVar9 = 0;
                            }
                            if (*(int*)(iVar2 + 0x54) != *(int*)(iVar2 + 0x58)) {
                                *piVar9 = 0;
                            }
                            iVar5 = iVar5 + 4;
                            local_14 = local_14 - 1;
                        } while (local_14 != 0);
                    }
                    if (*piVar9 != 0) {
                        if (param_1 == *puVar1) {
                            if (uVar7 != 0) {
                                iVar5 = local_10;
                                local_14 = uVar7;
                                do {
                                    if (*(uint32_t*)(*(int*)(*(int*)(in_ECX + 0x14) +
                                                             *(int*)(iVar5 + param_2[2]) * 4) +
                                                     0x48) != uVar8) {
                                        *piVar9 = 0;
                                    }
                                    iVar5 = iVar5 + 4;
                                    local_14 = local_14 - 1;
                                } while (local_14 != 0);
                            }
                            if (*piVar9 == 0) goto LAB_0069ec31;
                            if ((puVar1[3] == (*puVar1 & 0xfffff)) &&
                                (puVar1[1] <= (*puVar1 & 0xfffff) * param_4)) {
                                uVar4 = param_2[1];
                                uVar8 = 0;
                                if (uVar4 != 0) {
                                    piVar6 = (int*)param_2[2];
                                    do {
                                        if (*piVar6 == *(int*)puVar1[4]) break;
                                        uVar8 = uVar8 + 1;
                                        piVar6 = piVar6 + 1;
                                    } while (uVar8 < uVar4);
                                }
                                if (uVar8 != uVar4) {
                                    if (1 < puVar1[3]) {
                                        if ((puVar1[3] != uVar7) || (uVar4 < uVar8 + uVar7)) {
                                            *piVar9 = 0;
                                        }
                                        uVar4 = 0;
                                        if (uVar7 != 0) {
                                            iVar5 = uVar8 << 2;
                                            do {
                                                if (*(int*)(puVar1[4] + uVar4 * 4) !=
                                                    *(int*)(iVar5 + param_2[2])) {
                                                    *piVar9 = 0;
                                                }
                                                uVar4 = uVar4 + 1;
                                                iVar5 = iVar5 + 4;
                                            } while (uVar4 < uVar7);
                                        }
                                    }
                                    goto LAB_0069ec31;
                                }
                            }
                        }
                        goto LAB_0069ec2e;
                    }
                }
LAB_0069ec31:
                local_10 = local_10 + uVar7 * 4;
                piVar9 = piVar9 + 1;
                local_18 = local_18 - 1;
            } while (local_18 != 0);
        }
        uVar7 = 0;
        if (uVar3 != 0) {
            do {
                if (param_3[uVar7] != 0) {
                    return 0;
                }
                uVar7 = uVar7 + 1;
            } while (uVar7 < uVar3);
        }
    }
    return 1;
}

// 0x69ec6d — observed shape
int FUN_0069ec6d(void* self, int param_1, uint32_t param_2, uint32_t param_3)
{
    int iVar1;
    int* piVar2;
    int in_ECX = (int)(intptr_t)self;
    uint32_t uVar3;
    int local_14;
    uint32_t local_10;
    uint32_t local_c;
    int local_8;

    iVar1 = FUN_0065d0b4(0x74);
    if (iVar1 == 0) {
        local_8 = 0;
    } else {
        local_8 = FUN_0065cc1a();
    }
    if (local_8 == 0) {
        iVar1 = -0x7ff8fff2;
    } else {
        local_c = 0;
        if (param_3 != 0) {
            piVar2 = *(int**)(*(int*)(in_ECX + 0x100) + 0x10);
            uVar3 = param_3;
            do {
                if (*(int*)(param_1 + *(int*)(*(int*)(*(int*)(in_ECX + 0x14) + *piVar2 * 4) + 0x10) * 4)
                    != -1) {
                    local_c = local_c + 1;
                }
                piVar2 = piVar2 + 1;
                uVar3 = uVar3 - 1;
            } while (uVar3 != 0);
        }
        iVar1 = FUN_0065d0ff(**(uint32_t**)(in_ECX + 0x100) & 0xfff00000 | local_c,
                             local_c * param_2, local_c, 0);
        if ((-1 < iVar1) && (iVar1 = FUN_0065cc50(*(uint32_t*)(in_ECX + 0x100)), -1 < iVar1)) {
            local_10 = 0;
            if (param_2 != 0) {
                do {
                    uVar3 = 0;
                    local_14 = 0;
                    if (param_3 != 0) {
                        do {
                            if (*(int*)(param_1 +
                                        *(int*)(*(int*)(*(int*)(in_ECX + 0x14) +
                                                        *(int*)(*(int*)(*(int*)(in_ECX + 0x100) + 0x10) +
                                                                uVar3 * 4) * 4) + 0x10) * 4) != -1) {
                                *(uint32_t*)(*(int*)(local_8 + 8) +
                                             (local_10 * local_c + local_14) * 4) =
                                    *(uint32_t*)(*(int*)(*(int*)(in_ECX + 0x100) + 8) +
                                                 (local_10 * param_3 + uVar3) * 4);
                                if (local_10 == 0) {
                                    *(uint32_t*)(*(int*)(local_8 + 0x10) + local_14 * 4) =
                                        *(uint32_t*)(*(int*)(*(int*)(in_ECX + 0x100) + 0x10) +
                                                     uVar3 * 4);
                                }
                                local_14 = local_14 + 1;
                            }
                            uVar3 = uVar3 + 1;
                        } while (uVar3 < param_3);
                    }
                    local_10 = local_10 + 1;
                } while (local_10 < param_2);
            }
            iVar1 = FUN_0065d8c2(local_8);
            if (-1 < iVar1) {
                local_8 = 0;
                iVar1 = 0;
            }
        }
        if (local_8 != 0) {
            FUN_00614343(1);
        }
    }
    return iVar1;
}

// 0x69eddc — observed shape
int FUN_0069eddc(int param_1)
{
    int iVar1;
    int iVar2;

    while (true) {
        while (true) {
            if (param_1 == 0) {
                return 0;
            }
            iVar1 = *(int*)(param_1 + 4);
            if (iVar1 == 1) {
                iVar1 = FUN_0069eddc(*(uint32_t*)(param_1 + 0xc));
                iVar2 = FUN_0069eddc(*(uint32_t*)(param_1 + 8));
                return iVar2 + iVar1;
            }
            if (iVar1 != 6) break;
            param_1 = *(int*)(param_1 + 0x18);
        }
        if (iVar1 == 8) {
            iVar1 = FUN_0069eddc(*(uint32_t*)(param_1 + 0x10));
            return iVar1 * *(int*)(param_1 + 0x14);
        }
        if (iVar1 == 9) break;
        if (iVar1 != 0xb) {
            return 0;
        }
        param_1 = *(int*)(param_1 + 0x20);
    }
    return *(int*)(param_1 + 0x1c) * *(int*)(param_1 + 0x18);
}

// Additional helpers referenced by the following definitions.
extern int  FUN_0065c17a(void* a, uint32_t b, int c, void* d);
extern void* FUN_00533c78(uint32_t size);
extern void operator_delete(void* p);

// local_14..local_8 are four adjacent stack words passed as one 0x10-byte record.
// 0x69ee3f — observed shape
int FUN_0069ee3f(uint32_t param_1, int param_2, uint32_t param_3, uint32_t param_4, int param_5)
{
    uint16_t uVar1;
    uint16_t uVar2;
    int iVar3;
    void* pvVar4;
    int iVar5;
    void* pvVar6;
    uint32_t local_14;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;

    if (param_5 == 0) {
        iVar3 = 0;
    } else {
        for (; iVar3 = *(int*)(param_2 + 4), iVar3 != 1; param_2 = *(int*)(param_2 + 0x10)) {
            if (iVar3 != 8) {
                if (iVar3 != 9) {
                    return -0x7fffbffb;
                }
                uVar1 = 0;
                local_8 = 0;
                iVar3 = *(int*)(param_2 + 0x10);
                if (iVar3 == 0) {
                    uVar1 = 0;
                } else if (iVar3 == 1) {
                    uVar1 = 1;
                } else if (iVar3 == 2) {
                    uVar1 = (uint16_t)((uint8_t)~(uint8_t)(*(uint32_t*)(param_2 + 0x20) >> 10) & 1) | 2;
                } else if (iVar3 == 3) {
                    uVar1 = 4;
                }
                switch (*(uint32_t*)(param_2 + 0x14)) {
                case 0:
                    local_14 = 1u << 16 | uVar1;
                    break;
                case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 0xd:
                    local_14 = 2u << 16 | uVar1;
                    break;
                case 9: case 10: case 0xb: case 0xc:
                    local_14 = 3u << 16 | uVar1;
                    break;
                case 0xe:
                    local_14 = 4u << 16 | uVar1;
                    break;
                case 0xf:
                    local_14 = 5u << 16 | uVar1;
                    break;
                case 0x10:
                    local_14 = 6u << 16 | uVar1;
                    break;
                case 0x11:
                    local_14 = 7u << 16 | uVar1;
                    break;
                case 0x12:
                    local_14 = 8u << 16 | uVar1;
                    break;
                case 0x13:
                    local_14 = 9u << 16 | uVar1;
                    break;
                case 0x14:
                    if ((param_4 & 0x200000) != 0) goto switchD_0069eed4_caseD_16;
                    if ((param_4 & 0x400000) != 0) goto switchD_0069eed4_caseD_17;
                    local_14 = ((uint32_t)(uint16_t)(param_4 >> 0x16) << 16 | uVar1) & 0x2ffff | 0xc0000;
                    break;
                case 0x15:
                    local_14 = 0xbu << 16 | uVar1;
                    break;
                case 0x16:
switchD_0069eed4_caseD_16:
                    local_14 = 0xcu << 16 | uVar1;
                    break;
                case 0x17:
switchD_0069eed4_caseD_17:
                    local_14 = 0xdu << 16 | uVar1;
                    break;
                case 0x18:
                    local_14 = 0xeu << 16 | uVar1;
                    break;
                case 0x19:
                    local_14 = 0xfu << 16 | uVar1;
                    break;
                case 0x1a:
                    local_14 = 0x10u << 16 | uVar1;
                    break;
                case 0x1b:
                    local_14 = 0x11u << 16 | uVar1;
                    break;
                case 0x1c:
                    local_14 = 0x12u << 16 | uVar1;
                    break;
                default:
                    local_14 = (uint32_t)uVar1;
                }
                local_10 = *(uint32_t*)(param_2 + 0x1c) << 16 | *(uint16_t*)(param_2 + 0x18);
                local_c = param_3 & 0xffff;
                iVar3 = FUN_0065c17a(&local_14, 0x10, 2, (void*)(uintptr_t)param_5);
                goto LAB_0069f0b9;
            }
            param_3 = param_3 * *(int*)(param_2 + 0x14);
        }
        local_c = 0;
        local_8 = 0;
        local_14 = 5;
        local_10 = 1;
        uVar2 = (uint16_t)FUN_0069eddc(param_2);
        local_10 = (uint32_t)uVar2 << 16 | (uint16_t)local_10;
        iVar3 = param_2;
        do {
            local_c = (local_c & 0xffff) + 0x10000;
            iVar3 = *(int*)(iVar3 + 0xc);
        } while (iVar3 != 0);
        pvVar4 = FUN_00533c78((uint32_t)(uint16_t)(local_c >> 16) << 3);
        pvVar6 = pvVar4;
        if (pvVar4 == (void*)0x0) {
            iVar3 = -0x7ff8fff2;
        } else {
            do {
                iVar3 = *(int*)(*(int*)(param_2 + 8) + 0x18);
                iVar5 = FUN_0065c17a(*(void**)(*(int*)(*(int*)(param_2 + 8) + 0x14) + 0x18),
                                     0xffffffff, 7, pvVar6);
                if (iVar5 < 0) {
                    operator_delete(pvVar4);
                    return iVar5;
                }
                iVar3 = FUN_0069ee3f(param_1, *(uint32_t*)(iVar3 + 0x20), 1, param_4,
                                     (int)pvVar6 + 4);
                if (iVar3 < 0) {
                    operator_delete(pvVar4);
                    return iVar3;
                }
                param_2 = *(int*)(param_2 + 0xc);
                pvVar6 = (void*)((int)pvVar6 + 8);
            } while (param_2 != 0);
            iVar3 = FUN_0065c17a(pvVar4, (uint32_t)(uint16_t)(local_c >> 16) << 3, 2, &local_8);
            operator_delete(pvVar4);
            if (-1 < iVar3) {
                iVar3 = FUN_0065c17a(&local_14, 0x10, 2, (void*)(uintptr_t)param_5);
LAB_0069f0b9:
                if (-1 < iVar3) {
                    iVar3 = 0;
                }
            }
        }
    }
    return iVar3;
}

// 0x69f138 — observed shape
uint32_t FUN_0069f138(void* self, int param_1)
{
    uint32_t* puVar1;
    int in_ECX = (int)(intptr_t)self;
    uint32_t uVar2;
    int iVar3;
    uint32_t* puVar4;
    uint32_t* puVar5;
    uint32_t local_8;

    uVar2 = *(uint32_t*)(in_ECX + 0x114);
    local_8 = uVar2;
    if (uVar2 == 0) {
        local_8 = 0x400;
    }
    if (local_8 < (uint32_t)(*(int*)(in_ECX + 0x110) + param_1)) {
        do {
            local_8 = local_8 * 2;
        } while (local_8 < (uint32_t)(param_1 + *(int*)(in_ECX + 0x110)));
    }
    if (local_8 != uVar2) {
        puVar1 = (uint32_t*)FUN_00533c78(local_8 << 2);
        if (puVar1 == (uint32_t*)0x0) {
            return 0x8007000e;
        }
        puVar4 = *(uint32_t**)(in_ECX + 0x10c);
        puVar5 = puVar1;
        for (uVar2 = *(uint32_t*)(in_ECX + 0x110) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar5 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar5 = puVar5 + 1;
        }
        for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 - 1) {
            *(uint8_t*)puVar5 = *(uint8_t*)puVar4;
            puVar4 = (uint32_t*)((int)puVar4 + 1);
            puVar5 = (uint32_t*)((int)puVar5 + 1);
        }
        operator_delete(*(void**)(in_ECX + 0x10c));
        *(uint32_t**)(in_ECX + 0x10c) = puVar1;
        *(uint32_t*)(in_ECX + 0x114) = local_8;
    }
    return 0;
}

// 0x69f1e0 — observed shape
int FUN_0069f1e0(void* self, int param_1, uint32_t* param_2, uint32_t param_3, uint32_t* param_4)
{
    uint32_t uVar1;
    int iVar2;
    int* in_ECX = (int*)(intptr_t)self;
    uint32_t local_c;
    uint32_t local_8;

    local_c = 0;
    local_8 = 0;
    if (param_4 != (uint32_t*)0x0) {
        *param_4 = 0;
    }
    iVar2 = *(int*)(param_1 + 4);
    if (in_ECX[0x22] == iVar2) {
        local_8 = *(uint32_t*)(param_1 + 0xc);
        local_c = 0;
        if ((uint32_t)in_ECX[0xb] <= local_8) {
LAB_0069f2c0:
            FUN_006626da();
            return -0x7789f4a7;
        }
        uVar1 = (uint32_t)in_ECX[0x14];
        if ((uVar1 != 0) && (uVar1 <= local_8)) {
            local_8 = local_8 - uVar1;
            local_c = 3;
        }
    } else if (in_ECX[0x23] == iVar2) {
        local_8 = *(uint32_t*)(param_1 + 0xc);
        local_c = 3;
        if (local_8 != 0) goto LAB_0069f2c0;
    } else if (in_ECX[0x21] == iVar2) {
        iVar2 = (*(int(**)(int, uint32_t*, uint32_t*, uint32_t*))((char*)*(void**)in_ECX + 0x84))
                    (param_1, &local_8, &local_c, param_4);
        if (iVar2 < 0) {
            return -0x7fffbffb;
        }
    } else {
        if (in_ECX[0x24] != iVar2) {
            FUN_006626da();
            return -0x7fffbffb;
        }
        local_8 = *(uint32_t*)(param_1 + 0xc);
        local_c = 0x13;
        if ((uint32_t)in_ECX[0xd] <= local_8) goto LAB_0069f2c0;
    }
    if (param_2 != (uint32_t*)0x0) {
        *param_2 = (((local_c | 0xfffffff8) << 0x14 | local_c & 0x18) << 8) | local_8 & 0x7ff;
    }
    iVar2 = (*(int(**)(int, uint32_t))((char*)*(void**)in_ECX + 0x7c))(param_1, param_3);
    if (-1 < iVar2) {
        iVar2 = 0;
    }
    return iVar2;
}

// 0x69f32d — observed shape
uint32_t FUN_0069f32d(void* self, int* param_1, uint32_t param_2, uint32_t* param_3, int param_4)
{
    int* piVar1;
    int iVar2;
    int in_ECX = (int)(intptr_t)self;
    uint32_t uVar3;
    uint32_t uVar4;
    uint32_t local_c;
    uint32_t local_8;

    uVar3 = *(uint32_t*)(*(int*)(*(int*)(in_ECX + 0x14) + *param_1 * 4) + 0x3c);
    local_c = 0;
    local_8 = 0;
    if ((uVar3 & 0x400) == 0) {
        if ((uVar3 & 0x800) == 0) {
            if ((uVar3 & 0x1000) == 0) {
                if ((uVar3 & 0x2000) == 0) {
                    if ((uVar3 & 0x4000) == 0) {
                        if ((char)(uVar3 >> 8) < '\0') {
                            local_8 = 0xd000000;
                        }
                    } else {
                        local_8 = 0xe000000;
                    }
                } else {
                    local_8 = 0xf000000;
                }
            } else {
                local_8 = 0x3000000;
            }
        } else {
            local_8 = 0x2000000;
        }
    } else {
        local_8 = 0x1000000;
    }
    if ((uVar3 & 0x200) != 0) {
        local_8 = (local_8 & 0xff000000) | 0x100000;
    }
    if (param_4 == 0) {
        uVar3 = 0;
        if (param_2 != 0) {
            do {
                iVar2 = *(int*)(*(int*)(*(int*)(in_ECX + 0x14) + param_1[uVar3] * 4) + 0x10);
                uVar4 = 0;
                if (iVar2 == 0) {
                    uVar4 = 0x10000;
                } else if (iVar2 == 1) {
                    uVar4 = 0x20000;
                } else if (iVar2 == 2) {
                    uVar4 = 0x40000;
                } else if (iVar2 == 3) {
                    uVar4 = 0x80000;
                }
                if ((local_c & uVar4) != 0) {
                    FUN_006626da();
                }
                local_c = local_c | uVar4;
                uVar3 = uVar3 + 1;
            } while (uVar3 < param_2);
        }
    } else {
        local_c = 0xf0000;
    }
    uVar3 = 0;
    if ((*(uint8_t*)(in_ECX + 0x6e) & 0x80) != 0) {
        if ((local_c & 0x80000) == 0) {
            local_c = 0x70000;
        } else if ((local_c & 0x70000) != 0) {
            local_c = 0xf0000;
        }
    }
    if ((((*(uint8_t*)(in_ECX + 0xcc) & 1) != 0) && (*(int*)(in_ECX + 0x124) != 0)) &&
        (param_2 != 0)) {
        do {
            piVar1 = param_1 + uVar3;
            iVar2 = uVar3 + *(int*)(in_ECX + 0x128) * 6;
            uVar3 = uVar3 + 1;
            *(int*)(*(int*)(in_ECX + 0x124) + -0x10 + iVar2 * 4) = *piVar1;
        } while (uVar3 < param_2);
    }
    *param_3 = local_8 | local_c;
    return 0;
}

// 0x69f48f — observed shape
uint32_t FUN_0069f48f(void* self, int param_1, uint32_t* param_2, uint32_t* param_3)
{
    uint32_t uVar1;
    uint32_t uVar2;
    int in_ECX = (int)(intptr_t)self;

    *param_3 = 1;
    uVar1 = *(uint32_t*)(param_1 + 0xc);
    *param_2 = uVar1;
    if (uVar1 < *(uint32_t*)(in_ECX + 0x28)) {
        uVar2 = 0;
    } else {
        FUN_006626da();
        uVar2 = 0x80004005;
    }
    return uVar2;
}

// 0x69f4d6 — observed shape
int FUN_0069f4d6(void* self, uint32_t param_1, uint32_t* param_2, uint32_t* param_3)
{
    int* piVar1;
    uint32_t uVar2;
    int iVar3;
    int* in_ECX = (int*)(intptr_t)self;
    uint32_t uVar4;
    int* local_c;
    int* local_8;

    uVar2 = param_1;
    if (in_ECX[0x22] == *(int*)(param_1 + 4)) {
        local_c = *(int**)(param_1 + 0xc);
        param_1 = 0;
        if ((int*)in_ECX[0xb] <= local_c) goto LAB_0069f6a4;
        piVar1 = (int*)in_ECX[0x14];
        if ((piVar1 != (int*)0x0) && (piVar1 <= local_c)) {
            local_c = (int*)((int)local_c - (int)piVar1);
            param_1 = 3;
        }
LAB_0069f57a:
        local_8 = (int*)0x0;
        uVar4 = *(uint32_t*)(uVar2 + 0x3c) & 0x1f0000;
        if (uVar4 == 0x100000) {
            local_8 = (int*)0xb000000;
        } else if (uVar4 == 0x180000) {
            local_8 = (int*)0xc000000;
        } else if (uVar4 == 0x80000) {
            local_8 = (int*)0x1000000;
        } else if (uVar4 == 0x20000) {
            local_8 = (int*)0x2000000;
        } else if (uVar4 == 0xa0000) {
            local_8 = (int*)0x3000000;
        } else if (uVar4 == 0x60000) {
            local_8 = (int*)0x4000000;
        } else if (uVar4 == 0xe0000) {
            local_8 = (int*)0x5000000;
        } else if (uVar4 == 0x10000) {
            local_8 = (int*)0x6000000;
        } else if (uVar4 == 0x40000) {
            local_8 = (int*)0x7000000;
        } else if (uVar4 == 0xc0000) {
            local_8 = (int*)0x8000000;
        }
        if (param_2 != (uint32_t*)0x0) {
            *param_2 = (((param_1 | 0xfffffff8) << 0x14 | param_1 & 0x18) << 8) |
                       ((uint32_t)local_c & 0x7ff) | (uint32_t)local_8;
        }
        if (param_3 != (uint32_t*)0x0) {
            *param_3 = *(uint32_t*)(uVar2 + 8);
        }
        if (*(int*)(uVar2 + 8) != -1) {
            if (in_ECX[0x55] == 0) goto LAB_0069f7ba;
            ((uint8_t*)param_2)[1] = ((uint8_t*)param_2)[1] | 0x20;
        }
        iVar3 = 0;
    } else {
        uVar4 = *(uint32_t*)(*(int*)(in_ECX[4] + *(int*)(param_1 + 4) * 4) + 4);
        if (((uVar4 & 0x10) != 0) && ((uVar4 & 4) != 0)) {
            param_1 = 0xf;
            local_c = (int*)0x0;
            goto LAB_0069f57a;
        }
        local_c = in_ECX;
        if (((uVar4 & 0x10) != 0) && ((uVar4 & 0x200) == 0)) {
            iVar3 = (*(int(**)(uint32_t, int**, uint32_t*))((char*)*(void**)in_ECX + 0x88))
                        (param_1, &local_c, &param_1);
            if (iVar3 < 0) {
                return iVar3;
            }
            goto LAB_0069f57a;
        }
        if (((uVar4 & 0x200) != 0) && ((uVar4 & 0x42080) == 0)) {
            local_c = *(int**)(param_1 + 0xc);
            if ((int*)in_ECX[0xe] <= local_c) goto LAB_0069f6a4;
            if (local_c < (int*)0x800) {
                param_1 = 2;
            } else if (local_c < (int*)0x1000) {
                param_1 = 0xb;
            } else {
                param_1 = 0xd - (local_c < (int*)0x1800);
            }
            local_c = (int*)((uint32_t)local_c & 0x7ff);
            goto LAB_0069f57a;
        }
        if ((uVar4 & 0x200) != 0) {
            if (-1 < (char)uVar4) {
                if ((uVar4 & 0x2000) != 0) {
                    local_c = *(int**)(param_1 + 0xc);
                    param_1 = 0xe;
                    if ((int*)in_ECX[0x18] <= local_c) goto LAB_0069f6a4;
                    goto LAB_0069f57a;
                }
                goto LAB_0069f62d;
            }
LAB_0069f631:
            local_c = *(int**)(param_1 + 0xc);
            param_1 = 10;
            if ((int*)in_ECX[0x13] <= local_c) {
LAB_0069f6a4:
                FUN_006626da();
                return -0x7789f4a7;
            }
            goto LAB_0069f57a;
        }
LAB_0069f62d:
        if ((char)uVar4 < '\0') goto LAB_0069f631;
        if ((uVar4 & 0x40000) != 0) {
            local_c = *(int**)(param_1 + 0xc);
            param_1 = 7;
            if ((int*)in_ECX[0x10] <= local_c) goto LAB_0069f6a4;
            goto LAB_0069f57a;
        }
        local_8 = in_ECX;
        if (in_ECX[0x24] == *(int*)(param_1 + 4)) {
            local_c = *(int**)(param_1 + 0xc);
            param_1 = 0x13;
            if ((int*)in_ECX[0xd] <= local_c) goto LAB_0069f6a4;
            goto LAB_0069f57a;
        }
LAB_0069f7ba:
        FUN_006626da();
        iVar3 = -0x7fffbffb;
    }
    return iVar3;
}

// Additional helpers referenced by the following definitions.
extern int  FUN_0060fcd3(uint32_t a, void* b, int c, char* d, uint32_t e);
extern int  FUN_0061273f(char* name, uint32_t a, int b);
extern void FUN_00610bd6(void* p);
extern int  FUN_00612061(const void* a, const void* b);
extern char DAT_006c7974[];
extern int  sprintf(char* dst, const char* fmt, ...);
extern void qsort(void* base, size_t n, size_t size, int (*cmp)(const void*, const void*));

// 0x69f930 — observed shape
uint32_t FUN_0069f930(void* self, int* param_1, uint32_t param_2, uint32_t param_3,
                      uint32_t* param_4)
{
    int* piVar1;
    int* piVar2;
    int iVar3;
    int iVar4;
    uint32_t uVar5;
    uint32_t* puVar6;
    int in_ECX = (int)(intptr_t)self;
    uint32_t uVar7;
    uint32_t uVar8;
    bool bVar9;
    uint32_t local_28[4];
    int local_18[4];
    int local_8;

    iVar3 = *param_1;
    iVar4 = *(int*)(in_ECX + 0x14);
    local_8 = *(int*)(iVar4 + iVar3 * 4);
    if ((*(uint8_t*)(*(int*)(*(int*)(in_ECX + 0x10) + *(int*)(local_8 + 4) * 4) + 4) & 0x80) != 0) {
        *param_4 = 0xe40000;
        return 0;
    }
    bVar9 = (param_3 & 0x10000) != 0;
    if (bVar9) {
        local_18[0] = 0;
    }
    uVar7 = (uint32_t)bVar9;
    if ((param_3 & 0x20000) != 0) {
        local_18[uVar7] = 1;
        uVar7 = uVar7 + 1;
    }
    if ((param_3 & 0x40000) != 0) {
        local_18[uVar7] = 2;
        uVar7 = uVar7 + 1;
    }
    if ((param_3 & 0x80000) != 0) {
        local_18[uVar7] = 3;
        uVar7 = uVar7 + 1;
    }
    if (uVar7 < param_2) {
        param_2 = uVar7;
    }
    uVar7 = 0;
    if (param_2 != 0) {
        do {
            if (*(int*)(*(int*)(*(int*)(in_ECX + 0x14) + iVar3 * 4) + 0x10) !=
                *(int*)(*(int*)(*(int*)(in_ECX + 0x14) + param_1[uVar7] * 4) + 0x10)) break;
            uVar7 = uVar7 + 1;
        } while (uVar7 < param_2);
        if (uVar7 < param_2) {
            uVar7 = 0;
            do {
                local_28[uVar7] = uVar7;
                uVar7 = uVar7 + 1;
            } while (uVar7 < 4);
            goto LAB_0069f9f8;
        }
    }
    local_28[0] = *(uint32_t*)(local_8 + 0x10);
    local_28[1] = local_28[0];
    local_28[2] = local_28[0];
    local_28[3] = local_28[0];
LAB_0069f9f8:
    uVar7 = 0;
    if (param_2 != 0) {
        do {
            piVar2 = local_18 + uVar7;
            piVar1 = param_1 + uVar7;
            uVar7 = uVar7 + 1;
            local_28[*piVar2] = *(uint32_t*)(*(int*)(iVar4 + *piVar1 * 4) + 0x10);
        } while (uVar7 < param_2);
    }
    uVar8 = 0;
    uVar7 = 0x10;
    puVar6 = local_28;
    do {
        uVar5 = *puVar6;
        puVar6 = puVar6 + 1;
        uVar8 = uVar8 | uVar5 << (uVar7 & 0x1f);
        uVar7 = uVar7 + 2;
    } while (uVar7 < 0x18);
    *param_4 = uVar8;
    return 0;
}

// 0x69fa46 — observed shape
uint32_t FUN_0069fa46(void* self, int param_1, uint32_t* param_2)
{
    int iVar1;
    int iVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    int in_ECX = (int)(intptr_t)self;

    uVar3 = 0;
    if (*(int*)(param_1 + 0x14) != -1) {
        iVar1 = *(int*)(*(int*)(in_ECX + 0x14) + *(int*)(param_1 + 0x14) * 4);
        if ((*(uint8_t*)(*(int*)(*(int*)(in_ECX + 0x10) + *(int*)(iVar1 + 4) * 4) + 4) & 8) != 0) {
            iVar2 = *(int*)(iVar1 + 0x10);
            uVar4 = *(uint32_t*)(iVar1 + 0xc) & 0x7ff;
            uVar3 = uVar4 | 0xb0001000;
            if (iVar2 != 0) {
                if (iVar2 == 1) {
                    uVar3 = uVar4 | 0xb0551000;
                } else if (iVar2 == 2) {
                    uVar3 = uVar4 | 0xb0aa1000;
                } else if (iVar2 == 3) {
                    uVar3 = uVar4 | 0xb0ff1000;
                }
            }
            if (*(int*)(param_1 + 0x18) == 0) {
                uVar3 = uVar3 | 0xd000000;
            }
        }
    }
    if (param_2 != (uint32_t*)0x0) {
        *param_2 = uVar3;
    }
    return 0;
}

// 0x69fabc — observed shape
uint32_t FUN_0069fabc(void* self, uint32_t param_1, int param_2, uint32_t param_3, uint32_t param_4,
                      int* param_5)
{
    int iVar1;
    bool bVar2;
    uint32_t uVar3;
    int iVar4;
    int in_ECX = (int)(intptr_t)self;
    int iVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    uint32_t* puVar8;
    uint32_t* local_8;

    local_8 = (uint32_t*)0x0;
    uVar3 = 0;
    bVar2 = false;
    if (param_5 != (int*)0x0) {
        do {
            if (*(int*)(in_ECX + 0x150) == *(int*)(param_4 + uVar3 * 4)) {
                bVar2 = true;
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < (uint32_t)(uintptr_t)param_5);
    }
    if ((*(uint32_t*)(in_ECX + 0x14c) <= param_1) || (bVar2)) {
        *(uint32_t*)(in_ECX + 0x13c) = 0xffffffff;
        *(uint32_t*)(in_ECX + 0x140) = 0xffffffff;
        *(uint32_t*)(in_ECX + 0x144) = 0xffffffff;
        *(uint32_t*)(in_ECX + 0x148) = 0xffffffff;
        local_8 = (uint32_t*)FUN_00533c78(0);
        if (local_8 == (uint32_t*)0x0) {
LAB_0069fcee:
            uVar7 = 0x8007000e;
            goto LAB_0069fcdc;
        }
        puVar8 = local_8;
        for (uVar3 = *(uint32_t*)(in_ECX + 0x2c) & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar8 = 0xffffffff;
            puVar8 = puVar8 + 1;
        }
        uVar3 = 0;
        for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 - 1) {
            *(uint8_t*)puVar8 = 0xff;
            puVar8 = (uint32_t*)((int)puVar8 + 1);
        }
        if (*(int*)(in_ECX + 8) != 0) {
            do {
                iVar5 = *(int*)(*(int*)(in_ECX + 0x14) + uVar3 * 4);
                if (((*(int*)(in_ECX + 0x88) == *(int*)(iVar5 + 4)) && (*(int*)(iVar5 + 8) == -1)) &&
                    (*(uint32_t*)(iVar5 + 0xc) < *(uint32_t*)(in_ECX + 0x2c))) {
                    if ((*(uint32_t*)(iVar5 + 0x48) < param_1) &&
                        (param_1 <= *(uint32_t*)(iVar5 + 0x58))) {
                        local_8[*(uint32_t*)(iVar5 + 0xc)] = 0;
                    }
                    uVar6 = *(uint32_t*)(iVar5 + 0x48);
                    if ((param_1 <= uVar6) && (uVar6 < local_8[*(int*)(iVar5 + 0xc)])) {
                        local_8[*(int*)(iVar5 + 0xc)] = uVar6;
                    }
                }
                uVar3 = uVar3 + 1;
            } while (uVar3 < *(uint32_t*)(in_ECX + 8));
        }
        uVar3 = 0;
        *(uint32_t*)(in_ECX + 0x150) = 0;
        *(uint32_t*)(in_ECX + 0x14c) = 0;
        if (*(int*)(in_ECX + 0x2c) != 0) {
            do {
                uVar6 = 0;
                if (param_5 == (int*)0x0) {
LAB_0069fbbe:
                    if (*(uint32_t*)(in_ECX + 0x14c) < local_8[uVar3]) {
                        *(uint32_t*)(in_ECX + 0x150) = uVar3;
                        *(uint32_t*)(in_ECX + 0x14c) = local_8[uVar3];
                    }
                } else {
                    do {
                        if (uVar3 == *(uint32_t*)(param_4 + uVar6 * 4)) break;
                        uVar6 = uVar6 + 1;
                    } while (uVar6 < (uint32_t)(uintptr_t)param_5);
                    if ((uint32_t)(uintptr_t)param_5 <= uVar6) goto LAB_0069fbbe;
                }
                uVar3 = uVar3 + 1;
            } while (uVar3 < *(uint32_t*)(in_ECX + 0x2c));
        }
        if (*(uint32_t*)(in_ECX + 0x14c) <= param_1) {
            *(uint32_t*)(in_ECX + 0x14c) = 0xffffffff;
            *(int*)(in_ECX + 0x150) = *(int*)(in_ECX + 0x2c);
        }
    }
    param_4 = 0;
    iVar5 = (-(uint32_t)(param_3 != 1) & 0xfffffffd) + 3;
    if (param_3 != 0) {
        param_5 = (int*)(in_ECX + 0x13c + iVar5 * 4);
        do {
            if (*param_5 != -1) {
                *(uint32_t*)(*(int*)(*(int*)(in_ECX + 0x14) + *param_5 * 4) + 0x50) = param_1;
            }
            iVar4 = FUN_0065d9d5(*(uint32_t*)(in_ECX + 0x88), *(uint32_t*)(in_ECX + 0x150), iVar5, 0);
            *param_5 = iVar4;
            if (iVar4 == -1) goto LAB_0069fcee;
            iVar4 = *(int*)(*(int*)(in_ECX + 0x14) + iVar4 * 4);
            *(uint32_t*)(iVar4 + 0x3c) = 0;
            *(uint32_t*)(iVar4 + 0x30) = 0;
            *(uint32_t*)(iVar4 + 0x48) = param_1;
            *(uint32_t*)(iVar4 + 0x50) = *(uint32_t*)(in_ECX + 0x14c);
            *(uint32_t*)(iVar4 + 0x54) = param_1;
            *(uint32_t*)(iVar4 + 0x58) = param_1;
            *(uint32_t*)(iVar4 + 0x5c) = 1;
            iVar1 = *(int*)(*(int*)(in_ECX + 0x18) + param_1 * 4);
            if (*(int*)(iVar1 + 0xc) != 0) {
                *(uint32_t*)(iVar4 + 0x18) =
                    *(uint32_t*)(*(int*)(*(int*)(in_ECX + 0x14) +
                                         **(int**)(iVar1 + 0x10) * 4) + 0x18);
                *(uint32_t*)(iVar4 + 0x14) =
                    *(uint32_t*)(*(int*)(*(int*)(in_ECX + 0x14) +
                                         **(int**)(*(int*)(*(int*)(in_ECX + 0x18) + param_1 * 4) + 0x10) * 4) +
                                 0x14);
            }
            if (param_2 != 0) {
                *(int*)(param_2 + param_4 * 4) = *param_5;
            }
            param_5 = param_5 + 1;
            iVar5 = iVar5 + 1;
            param_4 = param_4 + 1;
        } while (param_4 < param_3);
    }
    uVar7 = 0;
LAB_0069fcdc:
    operator_delete(local_8);
    return uVar7;
}

// 0x69fcf5 — observed shape
uint32_t FUN_0069fcf5(void* self)
{
    int* piVar1;
    uint32_t uVar2;
    int iVar3;
    uint32_t uVar4;
    int in_ECX = (int)(intptr_t)self;
    uint32_t local_c;
    uint32_t local_8;

    piVar1 = *(int**)(in_ECX + 0x1b0);
    if (piVar1 != (int*)0x0) {
        uVar2 = *(uint32_t*)(in_ECX + 0x11c);
        if ((uVar2 < *(uint32_t*)(in_ECX + 0x110)) && (*(int*)(in_ECX + 0xd4) == 0)) {
            local_c = 0;
            local_8 = 0;
            if ((*(int*)(in_ECX + 0x100) != 0) &&
                ((iVar3 = *(int*)(*(int*)(in_ECX + 0x100) + 0x3c), iVar3 != 0 &&
                  (*(int*)(iVar3 + 4) == 0xd)))) {
                local_c = *(uint32_t*)(iVar3 + 0x40);
                local_8 = *(uint32_t*)(iVar3 + 0x44);
            }
            uVar4 = (*(uint32_t(**)(int*, uint32_t, uint32_t, int, uint32_t))((char*)*(void**)piVar1 + 0x10))
                        (piVar1, local_c, local_8,
                         *(int*)(in_ECX + 0x10c) + uVar2 * 4,
                         *(uint32_t*)(in_ECX + 0x110) - uVar2);
            *(uint32_t*)(in_ECX + 0x11c) = *(uint32_t*)(in_ECX + 0x110);
            return uVar4;
        }
    }
    return 0;
}

// 0x69fd7e — observed shape
uint32_t FUN_0069fd7e(uint32_t param_1, int param_2, short param_3, int param_4, uint32_t param_5,
                      int param_6)
{
    int iVar1;
    uint8_t local_24[16];
    uint32_t local_14;
    int local_10;

    if (param_2 == -1) {
        if (((*(int*)(param_6 + 0x100) != 0) &&
             (iVar1 = *(int*)(*(int*)(param_6 + 0x100) + 0x3c), iVar1 != 0)) &&
            (*(int*)(iVar1 + 4) == 0xd)) {
            param_1 = *(uint32_t*)(iVar1 + 0x40);
            param_2 = *(int*)(iVar1 + 0x44);
            if (param_2 != -1) goto LAB_0069fdbb;
        }
        param_2 = 0;
    }
LAB_0069fdbb:
    local_14 = param_1;
    if ((param_3 == 2) || (param_3 == 6)) {
        local_10 = param_2;
        FUN_0060fcd3(*(uint32_t*)(param_6 + 0xc4), local_24, param_4 + 5000, DAT_006c7974, param_5);
        *(uint32_t*)(param_6 + 0xd4) = 1;
    }
    return 0;
}

// 0x69fe28 — observed shape
int FUN_0069fe28(void* self, uint32_t param_1, int param_2, uint32_t param_3)
{
    int* piVar1;
    int iVar2;
    int in_ECX = (int)(intptr_t)self;
    void* _Base;
    uint32_t uVar3;
    char local_3c[32];
    uint16_t local_1c;
    uint16_t local_1a;
    uint16_t local_18;
    uint16_t local_16;
    uint16_t local_14;
    uint16_t local_12;
    uint32_t local_10;
    void* local_c;
    int local_8;

    uVar3 = 0;
    local_8 = 0;
    local_c = (void*)0x0;
    if (*(int*)(in_ECX + 0x158) == 0) {
        local_8 = 0;
    } else {
        iVar2 = *(int*)(in_ECX + 0x1d0) + *(int*)(in_ECX + 0x1f0) + *(int*)(in_ECX + 500);
        if (iVar2 != 0) {
            local_c = (void*)FUN_00533c78(iVar2 * 4);
            if (local_c == (void*)0x0) {
                local_8 = -0x7ff8fff2;
            } else {
                if (*(int*)(in_ECX + 0x2c) != 0) {
                    do {
                        sprintf(local_3c, "r_$Int%d", uVar3);
                        local_8 = FUN_0061273f(local_3c, uVar3, 1);
                        if (local_8 < 0) goto LAB_0069ffd0;
                        uVar3 = uVar3 + 1;
                    } while (uVar3 < *(uint32_t*)(in_ECX + 0x2c));
                }
                _Base = local_c;
                FUN_00610bd6(local_c);
                iVar2 = *(int*)(in_ECX + 0x1d0) + *(int*)(in_ECX + 500);
                FUN_00610bd6((void*)((int)_Base + iVar2 * 4));
                uVar3 = iVar2 + *(int*)(in_ECX + 0x1f0);
                qsort(_Base, uVar3, 4, FUN_00612061);
                local_1c = 1;
                local_1a = 3;
                local_18 = 1;
                local_16 = 4;
                local_14 = 1;
                local_12 = 0;
                local_10 = 0;
                param_2 = param_2 + param_3 * 0x14;
                param_3 = 0;
                if (uVar3 == 0) {
LAB_0069ffcb:
                    local_8 = 0;
                } else {
                    while (true) {
                        piVar1 = (int*)((int)_Base + param_3 * 4);
                        local_8 = FUN_0065c17a((void*)(uintptr_t)*piVar1, 0xffffffff, 7,
                                               (void*)(uintptr_t)param_2);
                        if ((local_8 < 0) ||
                            (local_8 = FUN_0065c17a(&local_1c, 0x10, 6,
                                                    (void*)(uintptr_t)(param_2 + 0xc)),
                             local_8 < 0)) break;
                        if (*(int*)(*piVar1 + 0xc) != 0) {
                            *(uint8_t*)(param_2 + 10) = *(uint8_t*)(param_2 + 10) | 1;
                            local_8 = FUN_0065c17a((void*)(*piVar1 + 0x10), 0x10, 7,
                                                   (void*)(uintptr_t)(param_2 + 0x10));
                            if (local_8 < 0) break;
                        }
                        param_3 = param_3 + 1;
                        *(uint16_t*)(param_2 + 4) = 2;
                        *(uint16_t*)(param_2 + 6) = *(uint16_t*)(*piVar1 + 4);
                        *(uint16_t*)(param_2 + 8) = 1;
                        param_2 = param_2 + 0x14;
                        if (uVar3 <= param_3) goto LAB_0069ffcb;
                        _Base = local_c;
                    }
                }
            }
        }
LAB_0069ffd0:
        operator_delete(local_c);
    }
    return local_8;
}

// Additional helpers referenced by the following definitions.
extern int  FUN_005f7fa4(int a, int b, uint8_t* out);
extern int  tolower(int c);
extern int  isdigit(int c);
extern int  atoi(const char* s);
extern void FUN_0065e2d0();
extern void FUN_0065e376();
extern void FUN_006126c7();
extern uint32_t PTR_FUN_006f37c0;

// 0x69ffe2 — observed shape
uint32_t FUN_0069ffe2(void* self, int param_1, int param_2)
{
    int iVar1;
    int iVar2;
    uint32_t uVar3;
    int in_ECX = (int)(intptr_t)self;
    int iVar4;
    char* pcVar5;
    char* pcVar6;
    uint8_t local_1c[4];
    uint32_t local_18;
    int local_10;
    char* local_c;
    char* local_8;

    // local_1c and local_18 are adjacent stack slots filled together by FUN_005f7fa4.
    pcVar6 = (char*)0x0;
    local_8 = (char*)0x0;
    local_c = (char*)0x0;
    if (*(int*)(in_ECX + 0x158) == 0) {
        return 0;
    }
    iVar2 = *(int*)(param_1 + 0x30);
    local_10 = in_ECX;
    if (iVar2 != 0) {
        do {
            iVar1 = *(int*)(iVar2 + 8);
            if (*(int*)(iVar1 + 4) == 0x11) {
                iVar4 = 0;
                if (*(int*)(iVar1 + 0x10) != 0) {
                    iVar4 = *(int*)(*(int*)(iVar1 + 0x10) + 0x18);
                }
                if (*(int*)(iVar1 + 0x14) == 0) {
                    pcVar5 = (char*)0x0;
                } else {
                    pcVar5 = *(char**)(*(int*)(iVar1 + 0x14) + 0x18);
                }
                if (iVar4 == 0) {
                    if ((pcVar5 != (char*)0x0) && (iVar1 = tolower((int)*pcVar5), iVar1 == 99)) {
                        local_c = pcVar5;
                    }
                } else if (((pcVar5 != (char*)0x0) && (iVar1 = FUN_005f7fa4(iVar4, 0, local_1c), -1 < iVar1)) &&
                           (iVar1 = tolower((int)*pcVar5), iVar1 == 99)) {
                    if (*(uint32_t*)(local_10 + 200) == local_18) {
                        pcVar6 = pcVar5;
                    } else if ((((*(uint32_t*)(local_10 + 200) ^ local_18) & 0xffff0000) == 0) &&
                               ((short)local_18 == 0)) {
                        local_8 = pcVar5;
                    }
                }
            }
            iVar2 = *(int*)(iVar2 + 0xc);
        } while (iVar2 != 0);
        if (pcVar6 != (char*)0x0) goto LAB_006a00b9;
    }
    pcVar6 = local_8;
    if ((local_8 == (char*)0x0) && (pcVar6 = local_c, local_c == (char*)0x0)) {
        return 0;
    }
LAB_006a00b9:
    iVar2 = tolower((int)*pcVar6);
    if (iVar2 == 99) {
        iVar2 = isdigit((int)pcVar6[1]);
        if (iVar2 != 0) {
            pcVar5 = pcVar6 + 2;
            while (iVar2 = isdigit((int)*pcVar5), iVar2 != 0) {
                pcVar5 = pcVar5 + 1;
            }
            if (*pcVar5 == '\0') {
                uVar3 = (uint32_t)atoi(pcVar6 + 1);
                if (0x1fff < uVar3) {
                    FUN_006626da(local_10, 0, 0,
                                 "Constant variable '%s' bound to register greater than 8191 (%d requested)",
                                 pcVar6 + 2, uVar3);
                    return 0x80004005;
                }
                *(uint16_t*)(param_2 + 10) =
                    *(uint16_t*)(param_2 + 10) | (uint16_t)(uVar3 << 2) | 2;
            }
        }
    }
    return 0;
}

// 0x6a0152 — observed shape
void FUN_006a0152(void* self)
{
    uint32_t* in_ECX = (uint32_t*)(intptr_t)self;
    int iVar1;
    uint32_t* puVar2;

    FUN_0065e2d0();
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006f37c0;
    puVar2 = in_ECX + 0x6d;
    for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 - 1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
    }
    puVar2 = in_ECX + 0x75;
    for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 - 1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
    }
    in_ECX[0x58] = 0xffffffff;
    in_ECX[0x3f] = 0;
    in_ECX[0x40] = 0;
    in_ECX[0x41] = 0;
    in_ECX[0x59] = 0xffffffff;
    in_ECX[0x5a] = 0xffffffff;
    in_ECX[0x5b] = 0xffffffff;
    in_ECX[0x62] = 0xffffffff;
    in_ECX[0x43] = 0;
    in_ECX[0x44] = 0;
    in_ECX[0x45] = 0;
    in_ECX[0x49] = 0;
    in_ECX[0x4a] = 0;
    in_ECX[0x4b] = 0;
    in_ECX[0x4c] = 0;
    in_ECX[0x4d] = 0;
    in_ECX[0x42] = 0;
    in_ECX[0x6c] = 0;
    in_ECX[0x56] = 0;
    in_ECX[0x7c] = 0;
    in_ECX[0x74] = 0;
    in_ECX[0x7d] = 0;
    in_ECX[0x3a] = 0xffff0000;
    in_ECX[0x3b] = 0x10;
    in_ECX[0x39] = 0xffff;
    in_ECX[0x3e] = 0;
    in_ECX[0x3c] = 0;
    in_ECX[0x3d] = 0;
    in_ECX[99] = 0;
    return;
}

// 0x6a0238 — observed shape
void FUN_006a0238(void* self)
{
    int* piVar1;
    uint32_t* in_ECX = (uint32_t*)(intptr_t)self;

    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006f37c0;
    operator_delete((void*)(uintptr_t)in_ECX[0x43]);
    operator_delete((void*)(uintptr_t)in_ECX[0x49]);
    piVar1 = (int*)(uintptr_t)in_ECX[0x6c];
    if (piVar1 != (int*)0x0) {
        (*(void(**)(int*))((char*)*(void**)piVar1 + 8))(piVar1);
        in_ECX[0x6c] = 0;
    }
    FUN_006126c7();
    FUN_006126c7();
    FUN_0065e376();
    return;
}
