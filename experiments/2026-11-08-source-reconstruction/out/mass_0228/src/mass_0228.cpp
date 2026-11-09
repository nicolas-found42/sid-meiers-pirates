// Reconstruction batch mass_0228 — Sid Meier's Pirates! (2004) PE32 i386
// Image: 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
#include <cstdint>
#include <cstddef>
#include <windows.h>

extern uint8_t FUN_005f0ddc();

// 0x5d6b70 — observed shape
int FUN_005d6b70(uint param_1)
{
    uint16_t uVar1;
    int iVar2;
    uint16_t uVar3;
    uint uVar4;
    uint32_t *puVar5;
    uint32_t *puVar6;
    uint16_t uVar7;
    uint32_t *puVar8;
    uint32_t *puVar9;
    int local_10;
    iVar2 = (int)param_1;
    puVar5 = *(uint32_t **)(param_1 + 0x28);
    puVar6 = *(uint32_t **)(param_1 + 0x14);
    uVar7 = (uint16_t)(*(int16_t *)(param_1 + 8) - 0xc);
    local_10 = 0;
    uVar1 = (uint16_t)(*(int *)(param_1 + 4) != 6) * 2 + 2;
    if ((int16_t)(uVar7 - uVar1) < 1) {
        param_1 = *(uint *)(param_1 + 0x18);
    }
    else {
        param_1 = *(uint *)(param_1 + 0x20);
        uVar7 = uVar1;
    }
    uVar3 = 0;
    if (*(int16_t *)(iVar2 + 0xc) == 0) {
        return 0;
    }
    do {
        puVar8 = puVar6;
        puVar9 = puVar5;
        for (uVar4 = param_1 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar9 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar9 = puVar9 + 1;
        }
        for (uVar4 = param_1 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(uint8_t *)puVar9 = *(uint8_t *)puVar8;
            puVar8 = (uint32_t *)((int)puVar8 + 1);
            puVar9 = (uint32_t *)((int)puVar9 + 1);
        }
        if (uVar7 < uVar1) {
            puVar8 = (uint32_t *)((int)puVar5 + 2);
            for (uVar4 = (uint)((uint16_t)(uVar1 - uVar7) >> 1); uVar4 != 0; uVar4 = uVar4 - 1) {
                *puVar8 = 0;
                puVar8 = puVar8 + 1;
            }
            for (uVar4 = (uint)((uVar1 - uVar7 & 1) != 0); uVar4 != 0; uVar4 = uVar4 - 1) {
                *(uint16_t *)puVar8 = 0;
                puVar8 = (uint32_t *)((int)puVar8 + 2);
            }
        }
        puVar6 = (uint32_t *)((int)puVar6 + *(int *)(iVar2 + 0x1c));
        puVar5 = (uint32_t *)((int)puVar5 + *(int *)(iVar2 + 0x24));
        local_10 = local_10 + *(int *)(iVar2 + 0x20);
        uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint16_t *)(iVar2 + 0xc));
    return local_10;
}

// 0x5d6c50 — observed shape
int FUN_005d6c50(uint param_1)
{
    uint16_t uVar1;
    int iVar2;
    uint16_t uVar3;
    uint uVar4;
    uint32_t *puVar5;
    uint32_t *puVar6;
    uint16_t uVar7;
    uint32_t *puVar8;
    uint32_t *puVar9;
    int local_10;
    iVar2 = (int)param_1;
    puVar5 = *(uint32_t **)(param_1 + 0x28);
    puVar6 = *(uint32_t **)(param_1 + 0x14);
    uVar7 = (uint16_t)(*(int16_t *)(param_1 + 8) - 0x10);
    local_10 = 0;
    uVar1 = (uint16_t)(*(int *)(param_1 + 4) != 6) * 2 + 2;
    if ((int16_t)(uVar7 - uVar1) < 1) {
        param_1 = *(uint *)(param_1 + 0x18);
    }
    else {
        param_1 = *(uint *)(param_1 + 0x20);
        uVar7 = uVar1;
    }
    uVar3 = 0;
    if (*(int16_t *)(iVar2 + 0xc) == 0) {
        return 0;
    }
    do {
        puVar8 = puVar6;
        puVar9 = puVar5;
        for (uVar4 = param_1 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar9 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar9 = puVar9 + 1;
        }
        for (uVar4 = param_1 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(uint8_t *)puVar9 = *(uint8_t *)puVar8;
            puVar8 = (uint32_t *)((int)puVar8 + 1);
            puVar9 = (uint32_t *)((int)puVar9 + 1);
        }
        if (uVar7 < uVar1) {
            puVar8 = (uint32_t *)((int)puVar5 + 2);
            for (uVar4 = (uint)((uint16_t)(uVar1 - uVar7) >> 1); uVar4 != 0; uVar4 = uVar4 - 1) {
                *puVar8 = 0;
                puVar8 = puVar8 + 1;
            }
            for (uVar4 = (uint)((uVar1 - uVar7 & 1) != 0); uVar4 != 0; uVar4 = uVar4 - 1) {
                *(uint16_t *)puVar8 = 0;
                puVar8 = (uint32_t *)((int)puVar8 + 2);
            }
        }
        puVar6 = (uint32_t *)((int)puVar6 + *(int *)(iVar2 + 0x1c));
        puVar5 = (uint32_t *)((int)puVar5 + *(int *)(iVar2 + 0x24));
        local_10 = local_10 + *(int *)(iVar2 + 0x20);
        uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint16_t *)(iVar2 + 0xc));
    return local_10;
}

// 0x5d6d30 — observed shape
int FUN_005d6d30(uint param_1)
{
    uint uVar1;
    int iVar2;
    uint16_t uVar3;
    uint8_t *pbVar4;
    uint uVar5;
    uint uVar6;
    uint8_t *pbVar7;
    uint16_t *puVar8;
    int local_10;
    uint16_t *local_c;
    iVar2 = (int)param_1;
    local_c = *(uint16_t **)(param_1 + 0x28);
    pbVar7 = *(uint8_t **)(param_1 + 0x14);
    uVar3 = (uint16_t)(*(int16_t *)(param_1 + 8) - 0x14);
    local_10 = 0;
    uVar1 = (uint)(*(int *)(param_1 + 4) != 6) * 2 + 2;
    param_1 = uVar1;
    if ((int16_t)(uVar3 - (uint16_t)uVar1) < 1) {
        param_1 = (uint)uVar3;
    }
    uVar3 = 0;
    if (*(int16_t *)(iVar2 + 0xc) != 0) {
        do {
            uVar5 = 0;
            puVar8 = local_c;
            if ((int16_t)param_1 != 0) {
                pbVar4 = pbVar7;
                uVar5 = param_1;
                do {
                    *puVar8 = (uint16_t)*pbVar4;
                    puVar8 = puVar8 + 1;
                    pbVar4 = pbVar4 + 1;
                    uVar5 = uVar5 - 1;
                } while (uVar5 != 0);
                uVar5 = param_1;
            }
            if ((uint16_t)uVar5 < (uint16_t)uVar1) {
                for (uVar6 = (uVar1 - uVar5 & 0xffff) >> 1; uVar6 != 0; uVar6 = uVar6 - 1) {
                    puVar8[0] = 0;
                    puVar8[1] = 0;
                    puVar8 = puVar8 + 2;
                }
                for (uVar5 = (uint)((uVar1 - uVar5 & 1) != 0); uVar5 != 0; uVar5 = uVar5 - 1) {
                    *puVar8 = 0;
                    puVar8 = puVar8 + 1;
                }
            }
            local_c = (uint16_t *)((int)local_c + *(int *)(iVar2 + 0x24));
            local_10 = local_10 + *(int *)(iVar2 + 0x20);
            pbVar7 = pbVar7 + *(int *)(iVar2 + 0x1c);
            uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint16_t *)(iVar2 + 0xc));
    }
    return local_10;
}

// 0x5d6e10 — observed shape
int FUN_005d6e10(uint param_1)
{
    uint uVar1;
    int iVar2;
    uint16_t uVar3;
    uint8_t *pbVar4;
    uint uVar5;
    uint uVar6;
    uint8_t *pbVar7;
    uint16_t *puVar8;
    int local_10;
    uint16_t *local_c;
    iVar2 = (int)param_1;
    local_c = *(uint16_t **)(param_1 + 0x28);
    pbVar7 = *(uint8_t **)(param_1 + 0x14);
    uVar3 = (uint16_t)(*(int16_t *)(param_1 + 8) - 0x18);
    local_10 = 0;
    uVar1 = (uint)(*(int *)(param_1 + 4) != 6) * 2 + 2;
    param_1 = uVar1;
    if ((int16_t)(uVar3 - (uint16_t)uVar1) < 1) {
        param_1 = (uint)uVar3;
    }
    uVar3 = 0;
    if (*(int16_t *)(iVar2 + 0xc) != 0) {
        do {
            uVar5 = 0;
            puVar8 = local_c;
            if ((int16_t)param_1 != 0) {
                pbVar4 = pbVar7;
                uVar5 = param_1;
                do {
                    *puVar8 = (uint16_t)*pbVar4;
                    puVar8 = puVar8 + 1;
                    pbVar4 = pbVar4 + 1;
                    uVar5 = uVar5 - 1;
                } while (uVar5 != 0);
                uVar5 = param_1;
            }
            if ((uint16_t)uVar5 < (uint16_t)uVar1) {
                for (uVar6 = (uVar1 - uVar5 & 0xffff) >> 1; uVar6 != 0; uVar6 = uVar6 - 1) {
                    puVar8[0] = 0;
                    puVar8[1] = 0;
                    puVar8 = puVar8 + 2;
                }
                for (uVar5 = (uint)((uVar1 - uVar5 & 1) != 0); uVar5 != 0; uVar5 = uVar5 - 1) {
                    *puVar8 = 0;
                    puVar8 = puVar8 + 1;
                }
            }
            local_c = (uint16_t *)((int)local_c + *(int *)(iVar2 + 0x24));
            local_10 = local_10 + *(int *)(iVar2 + 0x20);
            pbVar7 = pbVar7 + *(int *)(iVar2 + 0x1c);
            uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint16_t *)(iVar2 + 0xc));
    }
    return local_10;
}

// 0x5d6ef0 — observed shape
int FUN_005d6ef0(uint param_1)
{
    uint16_t *puVar1;
    int iVar2;
    uint8_t uVar3;
    uint16_t uVar4;
    uint uVar5;
    uint uVar6;
    uint32_t *puVar7;
    uint32_t *local_c;
    int local_8;
    iVar2 = (int)param_1;
    puVar1 = (uint16_t *)(param_1 + 8);
    local_c = *(uint32_t **)(param_1 + 0x28);
    local_8 = 0;
    param_1 = 4;
    if ((int16_t)(*puVar1 - 4) < 1) {
        param_1 = (uint)*puVar1;
    }
    uVar4 = 0;
    if (*(int16_t *)(iVar2 + 0xc) == 0) {
        return 0;
    }
    do {
        uVar6 = 0;
        puVar7 = local_c;
        if ((uint16_t)param_1 == 0) {
            for (uVar5 = (4 - uVar6 & 0xffff) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                *puVar7 = 0;
                puVar7 = puVar7 + 1;
            }
            for (uVar6 = 4 - uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
                *(uint8_t *)puVar7 = 0;
                puVar7 = (uint32_t *)((int)puVar7 + 1);
            }
        }
        else {
            uVar6 = param_1;
            do {
                uVar3 = FUN_005f0ddc();
                *(uint8_t *)puVar7 = uVar3;
                puVar7 = (uint32_t *)((int)puVar7 + 1);
                uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
            if ((uint16_t)param_1 < 4) {
                uVar6 = param_1;
                for (uVar5 = (4 - uVar6 & 0xffff) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                    *puVar7 = 0;
                    puVar7 = puVar7 + 1;
                }
                for (uVar6 = 4 - uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
                    *(uint8_t *)puVar7 = 0;
                    puVar7 = (uint32_t *)((int)puVar7 + 1);
                }
            }
        }
        local_8 = local_8 + *(int *)(iVar2 + 0x20);
        local_c = (uint32_t *)((int)local_c + *(int *)(iVar2 + 0x24));
        uVar4 = uVar4 + 1;
        if (*(uint16_t *)(iVar2 + 0xc) <= uVar4) {
            return local_8;
        }
    } while( true );
}

// 0x5d6fe0 — observed shape
int FUN_005d6fe0(int param_1)
{
    uint16_t uVar1;
    uint16_t uVar2;
    uint8_t *puVar3;
    uint8_t *puVar4;
    uint uVar5;
    uint uVar6;
    uint32_t *puVar7;
    uint32_t *local_c;
    int local_8;
    local_c = *(uint32_t **)(param_1 + 0x28);
    uVar1 = (uint16_t)(*(int16_t *)(param_1 + 8) - 4);
    puVar4 = *(uint8_t **)(param_1 + 0x14);
    local_8 = 0;
    if (0 < (int16_t)(*(int16_t *)(param_1 + 8) + -8)) {
        uVar1 = 4;
    }
    uVar2 = 0;
    if (*(int16_t *)(param_1 + 0xc) == 0) {
        return 0;
    }
    do {
        uVar5 = 0;
        puVar7 = local_c;
        if (uVar1 == 0) {
            for (uVar6 = (4 - uVar5 & 0xffff) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
                *puVar7 = 0;
                puVar7 = puVar7 + 1;
            }
            for (uVar5 = 4 - uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
                *(uint8_t *)puVar7 = 0;
                puVar7 = (uint32_t *)((int)puVar7 + 1);
            }
        }
        else {
            uVar5 = (uint)uVar1;
            puVar3 = puVar4;
            uVar6 = uVar5;
            do {
                *(uint8_t *)puVar7 = *puVar3;
                puVar7 = (uint32_t *)((int)puVar7 + 1);
                puVar3 = puVar3 + 4;
                uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
            if (uVar1 < 4) {
                for (uVar6 = (4 - uVar5 & 0xffff) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
                    *puVar7 = 0;
                    puVar7 = puVar7 + 1;
                }
                for (uVar5 = 4 - uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
                    *(uint8_t *)puVar7 = 0;
                    puVar7 = (uint32_t *)((int)puVar7 + 1);
                }
            }
        }
        puVar4 = puVar4 + *(int *)(param_1 + 0x1c);
        local_8 = local_8 + *(int *)(param_1 + 0x20);
        local_c = (uint32_t *)((int)local_c + *(int *)(param_1 + 0x24));
        uVar2 = uVar2 + 1;
        if (*(uint16_t *)(param_1 + 0xc) <= uVar2) {
            return local_8;
        }
    } while( true );
}

// 0x5d70b0 — observed shape
int FUN_005d70b0(int param_1)
{
    uint16_t uVar1;
    uint16_t uVar2;
    uint8_t *puVar3;
    uint8_t *puVar4;
    uint uVar5;
    uint uVar6;
    uint32_t *puVar7;
    uint32_t *local_c;
    int local_8;
    local_c = *(uint32_t **)(param_1 + 0x28);
    uVar1 = (uint16_t)(*(int16_t *)(param_1 + 8) - 8);
    puVar4 = *(uint8_t **)(param_1 + 0x14);
    local_8 = 0;
    if (0 < (int16_t)(*(int16_t *)(param_1 + 8) + -0xc)) {
        uVar1 = 4;
    }
    uVar2 = 0;
    if (*(int16_t *)(param_1 + 0xc) == 0) {
        return 0;
    }
    do {
        uVar5 = 0;
        puVar7 = local_c;
        if (uVar1 == 0) {
            for (uVar6 = (4 - uVar5 & 0xffff) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
                *puVar7 = 0;
                puVar7 = puVar7 + 1;
            }
            for (uVar5 = 4 - uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
                *(uint8_t *)puVar7 = 0;
                puVar7 = (uint32_t *)((int)puVar7 + 1);
            }
        }
        else {
            uVar5 = (uint)uVar1;
            puVar3 = puVar4;
            uVar6 = uVar5;
            do {
                *(uint8_t *)puVar7 = *puVar3;
                puVar7 = (uint32_t *)((int)puVar7 + 1);
                puVar3 = puVar3 + 4;
                uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
            if (uVar1 < 4) {
                for (uVar6 = (4 - uVar5 & 0xffff) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
                    *puVar7 = 0;
                    puVar7 = puVar7 + 1;
                }
                for (uVar5 = 4 - uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
                    *(uint8_t *)puVar7 = 0;
                    puVar7 = (uint32_t *)((int)puVar7 + 1);
                }
            }
        }
        puVar4 = puVar4 + *(int *)(param_1 + 0x1c);
        local_8 = local_8 + *(int *)(param_1 + 0x20);
        local_c = (uint32_t *)((int)local_c + *(int *)(param_1 + 0x24));
        uVar2 = uVar2 + 1;
        if (*(uint16_t *)(param_1 + 0xc) <= uVar2) {
            return local_8;
        }
    } while( true );
}

// 0x5d7180 — observed shape
int FUN_005d7180(int param_1)
{
    uint16_t uVar1;
    uint16_t uVar2;
    uint8_t *puVar3;
    uint8_t *puVar4;
    uint uVar5;
    uint uVar6;
    uint32_t *puVar7;
    uint32_t *local_c;
    int local_8;
    local_c = *(uint32_t **)(param_1 + 0x28);
    uVar1 = (uint16_t)(*(int16_t *)(param_1 + 8) - 0xc);
    puVar4 = *(uint8_t **)(param_1 + 0x14);
    local_8 = 0;
    if (0 < (int16_t)(*(int16_t *)(param_1 + 8) + -0x10)) {
        uVar1 = 4;
    }
    uVar2 = 0;
    if (*(int16_t *)(param_1 + 0xc) == 0) {
        return 0;
    }
    do {
        uVar5 = 0;
        puVar7 = local_c;
        if (uVar1 == 0) {
            for (uVar6 = (4 - uVar5 & 0xffff) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
                *puVar7 = 0;
                puVar7 = puVar7 + 1;
            }
            for (uVar5 = 4 - uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
                *(uint8_t *)puVar7 = 0;
                puVar7 = (uint32_t *)((int)puVar7 + 1);
            }
        }
        else {
            uVar5 = (uint)uVar1;
            puVar3 = puVar4;
            uVar6 = uVar5;
            do {
                *(uint8_t *)puVar7 = *puVar3;
                puVar7 = (uint32_t *)((int)puVar7 + 1);
                puVar3 = puVar3 + 2;
                uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
            if (uVar1 < 4) {
                for (uVar6 = (4 - uVar5 & 0xffff) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
                    *puVar7 = 0;
                    puVar7 = puVar7 + 1;
                }
                for (uVar5 = 4 - uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
                    *(uint8_t *)puVar7 = 0;
                    puVar7 = (uint32_t *)((int)puVar7 + 1);
                }
            }
        }
        puVar4 = puVar4 + *(int *)(param_1 + 0x1c);
        local_8 = local_8 + *(int *)(param_1 + 0x20);
        local_c = (uint32_t *)((int)local_c + *(int *)(param_1 + 0x24));
        uVar2 = uVar2 + 1;
        if (*(uint16_t *)(param_1 + 0xc) <= uVar2) {
            return local_8;
        }
    } while( true );
}

// 0x5d7250 — observed shape
int FUN_005d7250(int param_1)
{
    uint16_t uVar1;
    uint16_t uVar2;
    uint8_t *puVar3;
    uint8_t *puVar4;
    uint uVar5;
    uint uVar6;
    uint32_t *puVar7;
    uint32_t *local_c;
    int local_8;
    local_c = *(uint32_t **)(param_1 + 0x28);
    uVar1 = (uint16_t)(*(int16_t *)(param_1 + 8) - 0x10);
    puVar4 = *(uint8_t **)(param_1 + 0x14);
    local_8 = 0;
    if (0 < (int16_t)(*(int16_t *)(param_1 + 8) + -0x14)) {
        uVar1 = 4;
    }
    uVar2 = 0;
    if (*(int16_t *)(param_1 + 0xc) == 0) {
        return 0;
    }
    do {
        uVar5 = 0;
        puVar7 = local_c;
        if (uVar1 == 0) {
            for (uVar6 = (4 - uVar5 & 0xffff) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
                *puVar7 = 0;
                puVar7 = puVar7 + 1;
            }
            for (uVar5 = 4 - uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
                *(uint8_t *)puVar7 = 0;
                puVar7 = (uint32_t *)((int)puVar7 + 1);
            }
        }
        else {
            uVar5 = (uint)uVar1;
            puVar3 = puVar4;
            uVar6 = uVar5;
            do {
                *(uint8_t *)puVar7 = *puVar3;
                puVar7 = (uint32_t *)((int)puVar7 + 1);
                puVar3 = puVar3 + 2;
                uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
            if (uVar1 < 4) {
                for (uVar6 = (4 - uVar5 & 0xffff) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
                    *puVar7 = 0;
                    puVar7 = puVar7 + 1;
                }
                for (uVar5 = 4 - uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
                    *(uint8_t *)puVar7 = 0;
                    puVar7 = (uint32_t *)((int)puVar7 + 1);
                }
            }
        }
        puVar4 = puVar4 + *(int *)(param_1 + 0x1c);
        local_8 = local_8 + *(int *)(param_1 + 0x20);
        local_c = (uint32_t *)((int)local_c + *(int *)(param_1 + 0x24));
        uVar2 = uVar2 + 1;
        if (*(uint16_t *)(param_1 + 0xc) <= uVar2) {
            return local_8;
        }
    } while( true );
}

// 0x5d7320 — observed shape
int FUN_005d7320(int param_1)
{
    uint16_t uVar1;
    uint uVar2;
    uint uVar3;
    uint32_t *puVar4;
    uint32_t *puVar5;
    uint32_t *puVar6;
    uint32_t *puVar7;
    int local_c;
    uint local_8;
    local_8 = (uint)(uint16_t)(*(int16_t *)(param_1 + 8) - 0x14);
    puVar4 = *(uint32_t **)(param_1 + 0x28);
    puVar5 = *(uint32_t **)(param_1 + 0x14);
    local_c = 0;
    if ((int16_t)(*(int16_t *)(param_1 + 8) + -0x18) < 1) {
        uVar2 = *(uint *)(param_1 + 0x18);
    }
    else {
        uVar2 = *(uint *)(param_1 + 0x20);
        local_8 = 4;
    }
    uVar1 = 0;
    if (*(int16_t *)(param_1 + 0xc) == 0) {
        return 0;
    }
    do {
        puVar6 = puVar5;
        puVar7 = puVar4;
        for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar7 = puVar7 + 1;
        }
        for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(uint8_t *)puVar7 = *(uint8_t *)puVar6;
            puVar6 = (uint32_t *)((int)puVar6 + 1);
            puVar7 = (uint32_t *)((int)puVar7 + 1);
        }
        if ((uint16_t)local_8 < 4) {
            puVar6 = (uint32_t *)((int)puVar4 + 1);
            for (uVar3 = (4 - local_8 & 0xffff) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
                *puVar6 = 0;
                puVar6 = puVar6 + 1;
            }
            for (uVar3 = 4 - local_8 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
                *(uint8_t *)puVar6 = 0;
                puVar6 = (uint32_t *)((int)puVar6 + 1);
            }
        }
        puVar4 = (uint32_t *)((int)puVar4 + *(int *)(param_1 + 0x24));
        local_c = local_c + *(int *)(param_1 + 0x20);
        puVar5 = (uint32_t *)((int)puVar5 + *(int *)(param_1 + 0x1c));
        uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint16_t *)(param_1 + 0xc));
    return local_c;
}

// 0x5d73f0 — observed shape
int FUN_005d73f0(int param_1)
{
    uint16_t uVar1;
    uint uVar2;
    uint uVar3;
    uint32_t *puVar4;
    uint32_t *puVar5;
    uint32_t *puVar6;
    uint32_t *puVar7;
    int local_c;
    uint local_8;
    local_8 = (uint)(uint16_t)(*(int16_t *)(param_1 + 8) - 0x18);
    puVar4 = *(uint32_t **)(param_1 + 0x28);
    puVar5 = *(uint32_t **)(param_1 + 0x14);
    local_c = 0;
    if ((int16_t)(*(int16_t *)(param_1 + 8) + -0x1c) < 1) {
        uVar2 = *(uint *)(param_1 + 0x18);
    }
    else {
        uVar2 = *(uint *)(param_1 + 0x20);
        local_8 = 4;
    }
    uVar1 = 0;
    if (*(int16_t *)(param_1 + 0xc) == 0) {
        return 0;
    }
    do {
        puVar6 = puVar5;
        puVar7 = puVar4;
        for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar7 = puVar7 + 1;
        }
        for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(uint8_t *)puVar7 = *(uint8_t *)puVar6;
            puVar6 = (uint32_t *)((int)puVar6 + 1);
            puVar7 = (uint32_t *)((int)puVar7 + 1);
        }
        if ((uint16_t)local_8 < 4) {
            puVar6 = (uint32_t *)(uVar2 + (int)puVar4);
            for (uVar3 = (4 - local_8 & 0xffff) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
                *puVar6 = 0;
                puVar6 = puVar6 + 1;
            }
            for (uVar3 = 4 - local_8 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
                *(uint8_t *)puVar6 = 0;
                puVar6 = (uint32_t *)((int)puVar6 + 1);
            }
        }
        puVar4 = (uint32_t *)((int)puVar4 + *(int *)(param_1 + 0x24));
        local_c = local_c + *(int *)(param_1 + 0x20);
        puVar5 = (uint32_t *)((int)puVar5 + *(int *)(param_1 + 0x1c));
        uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint16_t *)(param_1 + 0xc));
    return local_c;
}

// 0x5d74c0 — observed shape
extern uint32_t *FUN_00533c78(uint p1);
extern void FUN_005c7170(void);
extern char FUN_005c84f0(int p1, uint32_t p2, uint p3);
extern uint32_t *PTR_FUN_006c8980;
uint32_t *FUN_005d74c0(int param_1, uint32_t param_2, uint param_3)
{
    char cVar1;
    uint32_t *puVar2;
    if (*(uint *)(param_1 + 0x454) < param_3) {
        return (uint32_t *)0x0;
    }
    puVar2 = (uint32_t *)FUN_00533c78(0x38);
    if (puVar2 != (uint32_t *)0x0) {
        FUN_005c7170();
        *puVar2 = (uint32_t)PTR_FUN_006c8980;
        puVar2[0xc] = 0;
        puVar2[0xd] = 0;
        cVar1 = FUN_005c84f0(param_1,param_2,param_3);
        if (cVar1 != '\0') {
            return puVar2;
        }
        (*(void (**)(int))*puVar2)(1);
    }
    return (uint32_t *)0x0;
}

// 0x5d7580 — observed shape
extern int FUN_005cd450(int p1, uint p2);
extern int FUN_005cd310(uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4);
extern char FUN_005cd3a0(uint32_t p1);
extern int FUN_005bfb30(uint p1);
extern void FUN_005c7e30(uint p1, int p2, int p3, int *p4, uint32_t p5, int p6, uint32_t p7, int p8);
extern void FUN_005542d0(uint32_t p1, uint32_t p2, uint16_t p3, int p4, int p5, int p6, int p7, uint32_t p8);
int FUN_005d7580(void *self, int *param_1, uint32_t param_2, uint param_3, int param_4, uint param_5, int param_6)
{
    int *piVar1;
    uint8_t bVar2;
    bool bVar3;
    bool bVar4;
    char cVar5;
    int iVar6;
    int iVar7;
    int iVar8;
    int iVar9;
    int unaff_retaddr;
    uint32_t uStack_3c;
    uint local_38;
    int local_34;
    int iStack_30;
    int iStack_2c;
    int iStack_28;
    int aiStack_20[4];
    uint uStack_10;
    int iStack_4;
    (void)self;
    if (param_3 == 0) {
        local_38 = (uint)(*(uint16_t (**)(int *))(**(int ***)param_1 + 0x38))() & 0xffff;
    }
    else {
        local_38 = *(uint16_t *)(param_3 + 0x1c);
    }
    if ((int16_t)local_38 != 0) {
        local_34 = 0;
        aiStack_20[1] = 0;
        cVar5 = (char)(**(char (**)(int *, int *))(**(int ***)0 + 0x50))(&local_34,aiStack_20 + 1);
        if (cVar5 != '\0') {
            if (param_3 == 0) {
                iVar8 = param_1[0xe];
            }
            else {
                iVar8 = *(int *)(param_3 + 0x28);
            }
            *(uint32_t *)(iVar8 + 0xc) = uStack_3c;
            *(uint32_t *)(iVar8 + 8) = 0;
            if (param_5 < *(uint *)(iVar8 + 0x14)) {
                *(uint32_t *)(*(int *)(iVar8 + 0x18) + param_5 * 4) =
                     *(uint32_t *)(param_5 * 0x10 + 0xc + (int)0);
            }
            bVar4 = true;
            if (param_6 == 0) {
                if ((((param_4 == 0) || (piVar1 = *(int **)(param_4 + 8), piVar1 == (int *)0x0)) ||
                    ((*(uint16_t *)(iStack_4 + 0x32) & 0xf000) == 0x8000)) ||
                    (((**(int (**)(int *, int *))(*piVar1 + 0x34))(piVar1,aiStack_20), aiStack_20[0] != 100 ||
                    (iVar9 = 0,
                    uStack_10 < (uint)(iVar9 * 0))))) {
                    cVar5 = (char)FUN_005cd450(iVar8,param_5);
                    if (cVar5 == '\0') {
                        return 0;
                    }
                    param_4 = FUN_005bfb30(param_5);
                    param_3 = 0xfff;
                }
                param_6 = FUN_005cd310(*(uint32_t *)(param_4 + 8),*(uint32_t *)(param_4 + 0xc),
                                       *(uint32_t *)(param_4 + 0x14),*(uint32_t *)(param_4 + 0x10));
            }
            else {
                bVar4 = false;
            }
            iVar8 = 0;
            if ((unaff_retaddr == 0) || (bVar3 = true, param_1 != (int *)0x0)) {
                bVar3 = false;
            }
            iVar9 = 0;
            iStack_28 = 0;
            iStack_2c = 0;
            iStack_30 = 0;
            local_34 = 0;
            if ((iVar9 != 0) && (local_38 = 0, *(int *)0 != 0)) {
                do {
                    iVar6 = *(int *)(iVar9 + 8) + iVar8;
                    iVar7 = *(int *)(*(int *)(iVar9 + 8) + 4 + iVar8) + param_6;
                    switch(*(uint32_t *)(iVar6 + 8)) {
                    case 0:
                        if ((param_3 & 1) != 0) {
                            if (!bVar3) goto LAB_005d7797;
                            iStack_28 = iVar7;
                        }
                        break;
                    default:
                        goto LAB_005d7797;
                    case 3:
                        if ((param_3 & 2) != 0) {
                            if (!bVar3) goto LAB_005d7797;
                            iStack_2c = iVar7;
                        }
                        break;
                    case 4:
                        bVar2 = (uint8_t)param_3 & 4;
                        goto LAB_005d7795;
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                    case 9:
                    case 10:
                    case 0xb:
                    case 0xc:
                        bVar2 = (uint8_t)param_3 & 8;
LAB_005d7795:
                        if (bVar2 != 0) {
LAB_005d7797:
                            FUN_005c7e30(0,iStack_4,unaff_retaddr,param_1,param_2,iVar6,
                                         *(uint32_t *)(iVar9 + 0xc),iVar7);
                        }
                        break;
                    case 0xd:
                        if ((param_3 & 2) != 0) {
                            if (!bVar3) goto LAB_005d7797;
                            local_34 = iVar7;
                        }
                        break;
                    case 0xe:
                        if ((param_3 & 2) != 0) {
                            if (!bVar3) goto LAB_005d7797;
                            iStack_30 = iVar7;
                        }
                    }
                    local_38 = local_38 + 1;
                    iVar8 = iVar8 + 0x1c;
                } while (local_38 < 0);
            }
            if (bVar3) {
                FUN_005542d0(*(uint32_t *)(iStack_4 + 0x20),*(uint32_t *)(iStack_4 + 0x24),
                             *(uint16_t *)(iStack_4 + 0xc),iStack_28,iStack_2c,iStack_30,local_34,
                             *(uint32_t *)(iVar9 + 0xc));
            }
            if ((!bVar4) || (cVar5 = (char)FUN_005cd3a0(*(uint32_t *)(param_4 + 8)), cVar5 != '\0')) {
                return param_4;
            }
        }
    }
    return 0;
}

// 0x5d7870 — observed shape
extern void *FUN_00533c78(uint p1);
extern int FUN_005d6690(int p1, uint p2);
extern void operator_delete__(void *p1);
int *FUN_005d7870(int in_ECX)
{
    int *piVar1;
    uint32_t uVar2;
    int iVar3;
    int iVar4;
    uint8_t *puVar5;
    uint uVar6;
    int iVar7;
    uint uVar8;
    int iVar9;
    uint uVar10;
    int iVar11;
    int iStack_c;
    uint uStack_8;
    uint uStack_4;
    iVar7 = 0;
    uVar8 = 0;
    piVar1 = *(int **)(in_ECX + 0x34);
    if (*(char *)(in_ECX + 0x2c) == '\0') {
        return piVar1;
    }
    if (piVar1 != (int *)0x0) {
        (**(void (**)(int *))(*piVar1 + 8))(piVar1);
        *(uint32_t *)(in_ECX + 0x34) = 0;
    }
    uVar10 = 0;
    if (*(int *)(in_ECX + 0x24) != 0) {
        do {
            puVar5 = (uint8_t *)(*(int *)(in_ECX + 0x28) + iVar7);
            if (puVar5 != (uint8_t *)0x0) {
                *puVar5 = 0;
                uVar6 = 0;
                if (*(int *)(in_ECX + 0x20) != 0) {
                    piVar1 = (int *)(*(int *)(puVar5 + 8) + 0xc);
                    do {
                        if ((piVar1[-1] != -1) && (*piVar1 != 0x11)) {
                            uVar8 = uVar8 + 1;
                            *puVar5 = 1;
                        }
                        uVar6 = uVar6 + 1;
                        piVar1 = piVar1 + 7;
                    } while (uVar6 < *(uint *)(in_ECX + 0x20));
                }
            }
            uVar10 = uVar10 + 1;
            iVar7 = iVar7 + 0x10;
        } while (uVar10 < *(uint *)(in_ECX + 0x24));
        if (uVar8 != 0) {
            uVar8 = uVar8 + 1;
        }
    }
    if (*(uint *)(in_ECX + 0x18) < uVar8) {
        operator_delete__(*(void **)(in_ECX + 0x30));
        *(uint32_t *)(in_ECX + 0x30) = 0;
    }
    if (uVar8 == 0) {
        *(uint32_t *)(in_ECX + 0x18) = 0;
    }
    else {
        if (*(int *)(in_ECX + 0x30) == 0) {
            *(uint *)(in_ECX + 0x18) = uVar8;
            uVar2 = (uint32_t)FUN_00533c78(uVar8 * 8);
            *(uint32_t *)(in_ECX + 0x30) = uVar2;
        }
        *(uint32_t *)(in_ECX + 0x1c) = 0;
        uStack_4 = 0;
        if (*(int *)(in_ECX + 0x24) != 0) {
            iStack_c = 0;
            do {
                iVar7 = 0;
                iVar11 = *(int *)(in_ECX + 0x28) + iStack_c;
                if (*(char *)(*(int *)(in_ECX + 0x28) + iStack_c) != '\0') {
                    iVar9 = 0;
                    uStack_8 = 0;
                    if (*(int *)(in_ECX + 0x20) != 0) {
                        do {
                            iVar4 = *(int *)(iVar11 + 8);
                            iVar3 = iVar4 + iVar9;
                            if ((*(int *)(iVar4 + 8 + iVar9) != -1) && (*(int *)(iVar3 + 0xc) != 0x11)) {
                                *(int *)(iVar3 + 4) = iVar7;
                                iVar4 = FUN_005d6690(iVar3,uStack_4);
                                iVar7 = iVar7 + iVar4;
                            }
                            uStack_8 = uStack_8 + 1;
                            iVar9 = iVar9 + 0x1c;
                        } while (uStack_8 < *(uint *)(in_ECX + 0x20));
                    }
                    *(int *)(iVar11 + 0xc) = iVar7;
                }
                uStack_4 = uStack_4 + 1;
                iStack_c = iStack_c + 0x10;
            } while (uStack_4 < *(uint *)(in_ECX + 0x24));
        }
        *(uint16_t *)(*(int *)(in_ECX + 0x30) + *(int *)(in_ECX + 0x1c) * 8) = 0xff;
        *(uint16_t *)(*(int *)(in_ECX + 0x30) + 2 + *(int *)(in_ECX + 0x1c) * 8) = 0;
        *(uint8_t *)(*(int *)(in_ECX + 0x30) + 4 + *(int *)(in_ECX + 0x1c) * 8) = 0x11;
        *(uint8_t *)(*(int *)(in_ECX + 0x30) + 5 + *(int *)(in_ECX + 0x1c) * 8) = 0;
        *(uint8_t *)(*(int *)(in_ECX + 0x30) + 6 + *(int *)(in_ECX + 0x1c) * 8) = 0;
        *(uint8_t *)(*(int *)(in_ECX + 0x30) + 7 + *(int *)(in_ECX + 0x1c) * 8) = 0;
        iVar7 = (**(int (**)(int *, uint32_t, int **))(**(int **)(in_ECX + 0x14) + 0x158))
                          (*(int **)(in_ECX + 0x14),*(uint32_t *)(in_ECX + 0x30),
                           (uint32_t *)(in_ECX + 0x34));
        if (-1 < iVar7) {
            *(uint8_t *)(in_ECX + 0x2c) = 0;
            return *(int **)(in_ECX + 0x34);
        }
    }
    return (int *)0x0;
}

// NEEDS_MANUAL: 0x5d7a30 — intricate nested switch table mapping param_2 (1..0x20) to conversion functions; preserve dispatcher and groups including 0x4, 0x6/0x7, 0x5 cases and FUN_004aaef0 default, but exact label/goto correspondences for switchD_005d7afe_caseD_1, caseD_1d, and LAB targets are not fully decidable from the listing alone.
extern void *FUN_004aaef0;
extern void FUN_005606f0(int p1, void **p2);
extern void *FUN_005c7bd0;
extern void *FUN_005c7ca0;
extern void *FUN_005d68d0;
extern void *FUN_005d69c0;
extern void *FUN_005d6a90;
extern void *FUN_005d6b70;
extern void *FUN_005d6c50;
extern void *FUN_005d6d30;
extern void *FUN_005d6e10;
extern void *FUN_005d6ef0;
extern void *FUN_005d6fe0;
extern void *FUN_005d70b0;
extern void *FUN_005d7180;
extern void *FUN_005d7250;
extern void *FUN_005d7320;
extern void *FUN_005d73f0;
extern void *FUN_005c73d0;
extern void *FUN_005c7220;
extern void *FUN_005c7500;
extern void *FUN_005c75d0;
extern void *FUN_005c76a0;
extern void *FUN_005c7870;
extern void *FUN_005c7960;
extern void *FUN_005c7290;
// 0x005d7a30 — observed shape: void(code* param_1, int param_2) — engine event/callback
// dispatcher: 0 selects FUN_004aaef0 via FUN_005606f0; codes >3 (0x4) run the large
// switch over engine events, small codes 0..3 fall through to the tail handlers.
void FUN_005d7a30(void *param_1, int param_2)
{
    code *p = (code *)param_1;
    if (param_2 == 0) {
        param_1 = FUN_004aaef0;
        FUN_005606f0(0,&param_1);
        return;
    }
    if (((int)(intptr_t)param_1 < 0) || (3 < (int)(intptr_t)param_1)) {
        if (param_1 == (void *)0x4) {
            switch(param_2) {
            case 1:
            case 2:
            case 6:
            case 7:
            case 8:
            case 10:
            case 0xb:
            case 0xc:
            case 0xd:
            case 0xe:
            case 0xf:
            case 0x11:
            case 0x12:
            case 0x13:
                param_1 = FUN_004aaef0;
                break;
            case 3:
            case 4:
            case 0x1d:
            case 0x1e:
            case 0x1f:
            case 0x20:
                param_1 = (void *)&LAB_005c81a0;
                break;
            case 5:
                param_1 = (void *)&LAB_005c7a40;
                break;
            case 9:
                param_1 = (void *)&LAB_005c7a40;
                break;
            case 0x10:
                param_1 = (void *)&LAB_005c7a70;
                break;
            case 0x14:
                param_1 = (void *)&LAB_005c7b20;
                break;
            case 0x15:
            case 0x16:
            case 0x17:
            case 0x18:
                param_1 = FUN_005c7bd0;
                break;
            case 0x19:
            case 0x1a:
            case 0x1b:
            case 0x1c:
                param_1 = FUN_005c7ca0;
                break;
            default:
                return;
            }
        }
        else if ((param_1 == (void *)0x6) || (param_1 == (void *)0x7)) {
            switch(param_2) {
            case 1:
            case 2:
            case 3:
            case 4:
                param_1 = FUN_005d68d0;
                break;
            case 5:
            case 6:
            case 7:
            case 8:
                param_1 = FUN_005d69c0;
                break;
            case 9:
            case 10:
            case 0xb:
            case 0xc:
                param_1 = FUN_005d6a90;
                break;
            case 0xd:
            case 0xe:
            case 0xf:
            case 0x10:
                param_1 = FUN_005d6b70;
                break;
            case 0x11:
            case 0x12:
            case 0x13:
            case 0x14:
                param_1 = FUN_005d6c50;
                break;
            case 0x15:
            case 0x16:
            case 0x17:
            case 0x18:
                param_1 = FUN_005d6d30;
                break;
            case 0x19:
            case 0x1a:
            case 0x1b:
            case 0x1c:
                param_1 = FUN_005d6e10;
                break;
            case 0x1d:
            case 0x1e:
            case 0x1f:
            case 0x20:
                param_1 = FUN_004aaef0;
                break;
            default:
                return;
            }
        }
        else {
            if (param_1 != (void *)0x5) {
                return;
            }
            switch(param_2) {
            case 1:
            case 2:
            case 3:
            case 4:
                param_1 = FUN_005d6ef0;
                break;
            case 5:
            case 6:
            case 7:
            case 8:
                param_1 = FUN_005d6fe0;
                break;
            case 9:
            case 10:
            case 0xb:
            case 0xc:
                param_1 = FUN_005d70b0;
                break;
            case 0xd:
            case 0xe:
            case 0xf:
            case 0x10:
                param_1 = FUN_005d7180;
                break;
            case 0x11:
            case 0x12:
            case 0x13:
            case 0x14:
                param_1 = FUN_005d7250;
                break;
            case 0x15:
            case 0x16:
            case 0x17:
            case 0x18:
                param_1 = FUN_005d7320;
                break;
            case 0x19:
            case 0x1a:
            case 0x1b:
            case 0x1c:
                param_1 = FUN_005d73f0;
                break;
            case 0x1d:
            case 0x1e:
            case 0x1f:
            case 0x20:
                param_1 = FUN_004aaef0;
                break;
            default:
                return;
            }
        }
    }
    else {
        switch(param_2) {
        case 1:
        case 2:
        case 3:
        case 4:
            if ((code *)(param_2 - 1U) == p) {
                param_1 = FUN_005c73d0;
            }
            else {
                if ((uint)(param_2 - 1U) < (uint)(intptr_t)param_1) {
                    param_1 = FUN_005c7290;
                }
                else {
                    param_1 = FUN_005c7220;
                }
            }
            break;
        case 5:
        case 6:
        case 7:
        case 8:
            param_1 = FUN_005c7500;
            break;
        case 9:
        case 10:
        case 0xb:
        case 0xc:
            param_1 = FUN_005c75d0;
            break;
        case 0xd:
        case 0xe:
        case 0xf:
        case 0x10:
            param_1 = FUN_005c76a0;
            break;
        case 0x11:
        case 0x12:
        case 0x13:
        case 0x14:
            param_1 = (void *)&LAB_005c7790;
            break;
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
            param_1 = FUN_005c7870;
            break;
        case 0x19:
        case 0x1a:
        case 0x1b:
        case 0x1c:
            param_1 = FUN_005c7960;
            break;
        case 0x1d:
        case 0x1e:
        case 0x1f:
        case 0x20:
            param_1 = FUN_005c7290;
            break;
        default:
            return;
        }
    }
    if (param_1 != (void *)0x0) {
        FUN_005606f0(param_2,&param_1);
    }
    return;
}

// 0x5d7d10 — observed shape
extern int DAT_00728eb0;
extern int *DAT_00728eac;
void FUN_005d7d10(int param_1)
{
    int *piVar1;
    DAT_00728eb0 = param_1;
    if (param_1 == 0) {
        if (DAT_00728eac != (int *)0x0) {
            (**(void (**)(int *))(*DAT_00728eac + 8))(DAT_00728eac);
        }
        DAT_00728eac = (int *)0x0;
        return;
    }
    piVar1 = *(int **)(param_1 + 0x60);
    if (DAT_00728eac != (int *)0x0) {
        (**(void (**)(int *))(*DAT_00728eac + 8))(DAT_00728eac);
    }
    DAT_00728eac = piVar1;
    if (piVar1 != (int *)0x0) {
        (**(void (**)(int *))(*piVar1 + 4))(piVar1);
    }
    return;
}

// 0x5d7d70 — observed shape
void FUN_005d7d70(void *self, uint param_1, uint32_t param_2, char param_3)
{
    int in_ECX = (int)self;
    if (param_1 < 0x21) {
        if (param_3 != '\0') {
            if (*(char *)(param_1 + 0x90 + in_ECX) != '\0') {
                *(uint32_t *)(in_ECX + 0xc + param_1 * 4) = param_2;
                return;
            }
            if (*(char *)(param_1 + 0x140 + in_ECX) != '\0') {
                *(uint8_t *)(param_1 + 0x140 + in_ECX) = 0;
                *(uint8_t *)(param_1 + 0x90 + in_ECX) = 1;
                *(uint32_t *)(in_ECX + 0xc + param_1 * 4) = param_2;
                *(int *)(in_ECX + 0xb4) = *(int *)(in_ECX + 0xb4) + -1;
                *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + 1;
            }
            *(uint8_t *)(param_1 + 0x90 + in_ECX) = 1;
            *(uint32_t *)(in_ECX + 0xc + param_1 * 4) = param_2;
            *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + 1;
            return;
        }
        if (*(char *)(param_1 + 0x140 + in_ECX) != '\0') {
            *(uint32_t *)(in_ECX + 0xbc + param_1 * 4) = param_2;
            return;
        }
        if (*(char *)(param_1 + 0x90 + in_ECX) != '\0') {
            *(uint8_t *)(param_1 + 0x90 + in_ECX) = 0;
            *(uint8_t *)(param_1 + 0x140 + in_ECX) = 1;
            *(uint32_t *)(in_ECX + 0xbc + param_1 * 4) = param_2;
            *(int *)(in_ECX + 0xb4) = *(int *)(in_ECX + 0xb4) + 1;
            *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + -1;
        }
        *(uint8_t *)(param_1 + 0x140 + in_ECX) = 1;
        *(uint32_t *)(in_ECX + 0xbc + param_1 * 4) = param_2;
        *(int *)(in_ECX + 0xb4) = *(int *)(in_ECX + 0xb4) + 1;
    }
    return;
}

// 0x5d7e40 — observed shape
void FUN_005d7e40(void *self, uint param_1, uint32_t param_2, char param_3)
{
    int in_ECX = (int)self;
    if (param_1 < 0xe) {
        if (param_3 != '\0') {
            if (*(char *)(param_1 + 0x1a4 + in_ECX) != '\0') {
                *(uint32_t *)(in_ECX + 0x16c + param_1 * 4) = param_2;
                return;
            }
            if (*(char *)(param_1 + 500 + in_ECX) != '\0') {
                *(uint8_t *)(param_1 + 500 + in_ECX) = 0;
                *(int *)(in_ECX + 0x1b4) = *(int *)(in_ECX + 0x1b4) + -1;
            }
            *(uint8_t *)(param_1 + 0x1a4 + in_ECX) = 1;
            *(uint32_t *)(in_ECX + 0x16c + param_1 * 4) = param_2;
            *(int *)(in_ECX + 0x164) = *(int *)(in_ECX + 0x164) + 1;
            return;
        }
        if (*(char *)(param_1 + 500 + in_ECX) != '\0') {
            *(uint32_t *)(in_ECX + 0x1bc + param_1 * 4) = param_2;
            return;
        }
        if (*(char *)(param_1 + 0x1a4 + in_ECX) != '\0') {
            *(uint8_t *)(param_1 + 0x1a4 + in_ECX) = 0;
            *(int *)(in_ECX + 0x164) = *(int *)(in_ECX + 0x164) + -1;
        }
        *(uint8_t *)(param_1 + 500 + in_ECX) = 1;
        *(uint32_t *)(in_ECX + 0x1bc + param_1 * 4) = param_2;
        *(int *)(in_ECX + 0x1b4) = *(int *)(in_ECX + 0x1b4) + 1;
    }
    return;
}

// 0x5d7f00 — observed shape
void FUN_005d7f00(void *self)
{
    uint8_t *puVar1;
    int in_ECX = (int)self;
    int iVar2;
    puVar1 = (uint8_t *)(in_ECX + 0x140);
    iVar2 = 0x21;
    do {
        puVar1[-0xb0] = 0;
        *puVar1 = 0;
        puVar1 = puVar1 + 1;
        iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    *(uint32_t *)(in_ECX + 0xb4) = 0;
    *(uint32_t *)(in_ECX + 4) = 0;
    return;
}

// 0x5d7f30 — observed shape
void FUN_005d7f30(void *self)
{
    uint8_t *puVar1;
    int in_ECX = (int)self;
    int iVar2;
    puVar1 = (uint8_t *)(in_ECX + 500);
    iVar2 = 0xe;
    do {
        puVar1[-0x50] = 0;
        *puVar1 = 0;
        puVar1 = puVar1 + 1;
        iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    *(uint32_t *)(in_ECX + 0x1b4) = 0;
    *(uint32_t *)(in_ECX + 0x164) = 0;
    return;
}
