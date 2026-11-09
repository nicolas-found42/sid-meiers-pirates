#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---------------------------------------------------------------------------
// External helpers and globals referenced by the translated listings.
// ---------------------------------------------------------------------------
extern int _snprintf(char* buffer, size_t count, const char* format, ...);
extern int _vsnprintf(char* buffer, size_t count, const char* format, ...);

extern int FUN_00661fbd(void);
extern int FUN_0065d097(int param_1);
extern int FUN_0065e1b9(void (*param_1)(void*, int, int), void* param_2, int param_3,
                        void* param_4);
extern void FUN_0065de5f(void* param_1, int param_2, int param_3);
extern void FUN_0066228a(uint32_t param_1, uint32_t param_2, uint32_t param_3);

extern int FUN_0060fcd3(uint32_t param_1, int param_2, uint32_t param_3, void* param_4,
                        char* param_5);
extern int FUN_0060fd9a(uint32_t param_1, int param_2, uint32_t param_3, void* param_4,
                        char* param_5);

extern int FUN_0065cd09(void);
extern void FUN_00661ef2(void);
extern int FUN_0065da35(uint32_t param_1, uint32_t param_2, uint32_t param_3);
extern int FUN_0065cc50(void);
extern int FUN_0065ccac(void);
extern uint32_t FUN_0065d9d5(uint32_t param_1, uint32_t param_2, uint32_t param_3,
                             uint64_t param_4);
extern void* FUN_00533c78(uint32_t param_1);
extern int FUN_0065e43a(uint32_t* param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4);
extern int FUN_0065f0a1(int param_1, int param_2);
extern void FUN_0065e18b(void* param_1, int param_2, int param_3);
extern void FUN_0065ddd1(void* param_1, int param_2, int param_3);
extern int ftol();
extern int FUN_0065dc39(int param_1);
extern int FUN_0065d97c(void* param_1, int param_2, int param_3, int param_4);
extern int FUN_0065e3ad(int param_1);
extern void FUN_0065e376(void);
extern void operator_delete(void* param_1);

extern uint8_t DAT_006c7974;
extern uint32_t DAT_0070d864;
extern uint32_t DAT_006e0418;
extern uint32_t DAT_006c3b94;
extern uint32_t DAT_006e0468;
extern uint32_t DAT_006e0410;
extern uint32_t DAT_006d1994;
extern uint32_t DAT_006d198c;
extern uint32_t DAT_006e0414;
extern uint32_t DAT_006e0430;
extern uint32_t DAT_006e0440;
extern uint32_t DAT_006ee294;
extern uint32_t DAT_006ee290;
extern uint32_t DAT_006e9154;
extern uint32_t DAT_006ee28c;
extern uint32_t DAT_006ee288;

// 0x662317 — observed shape
uint32_t FUN_662317(void* self)
{
    int iVar1;
    int iVar2;
    int iVar3;
    uint32_t uVar4;
    uint32_t local_c;
    uint32_t local_8;

    FUN_00661fbd();
    uVar4 = 0;
    if (*(int32_t*)((char*)self + 0xc) != 0) {
        do {
            iVar1 = *(int32_t*)(*(int32_t*)((char*)self + 0x18) + uVar4 * 4);
            uVar4 = uVar4 + 1;
            *(uint32_t*)(iVar1 + 0x18) = 0;
            *(uint32_t*)(iVar1 + 0x20) = 0;
            *(uint32_t*)(iVar1 + 0x14) = 0;
            *(uint32_t*)(iVar1 + 0x1c) = 0;
        } while (uVar4 < *(uint32_t*)((char*)self + 0xc));
    }
    local_8 = 0;
    if (*(int32_t*)((char*)self + 0xc) != 0) {
        do {
            iVar1 = *(int32_t*)(*(int32_t*)((char*)self + 0x18) + local_8 * 4);
            if ((*(uint16_t*)(iVar1 + 2) & 0xfff0) != 0) {
                uVar4 = 0;
                if (*(int32_t*)(iVar1 + 0xc) != 0) {
                    do {
                        FUN_0066228a(*(uint32_t*)(*(int32_t*)(iVar1 + 0x10) + uVar4 * 4), local_8, 0);
                        uVar4 = uVar4 + 1;
                    } while (uVar4 < *(uint32_t*)(iVar1 + 0xc));
                }
                uVar4 = 0;
                if (*(int32_t*)(iVar1 + 4) != 0) {
                    do {
                        iVar3 = *(int32_t*)(*(int32_t*)(iVar1 + 8) + uVar4 * 4);
                        if ((iVar3 != -1) &&
                            (iVar2 = *(int32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                             iVar3 * 4) +
                                                 0x38),
                             iVar2 != -1)) {
                            iVar3 = iVar2;
                        }
                        FUN_0066228a(iVar3, local_8, 1);
                        uVar4 = uVar4 + 1;
                    } while (uVar4 < *(uint32_t*)(iVar1 + 4));
                }
            }
            local_8 = local_8 + 1;
        } while (local_8 < *(uint32_t*)((char*)self + 0xc));
    }
    uVar4 = 0;
    if (*(int32_t*)((char*)self + 0xc) != 0) {
        do {
            iVar1 = *(int32_t*)(*(int32_t*)((char*)self + 0x18) + uVar4 * 4);
            if (*(int32_t*)(iVar1 + 0x14) != 0) {
                iVar3 = FUN_0065d097(*(int32_t*)(iVar1 + 0x14));
                *(int32_t*)(iVar1 + 0x18) = iVar3;
                if (iVar3 == 0) {
                    return 0x8007000e;
                }
            }
            if (*(int32_t*)(iVar1 + 0x1c) != 0) {
                iVar3 = FUN_0065d097(*(int32_t*)(iVar1 + 0x1c));
                *(int32_t*)(iVar1 + 0x20) = iVar3;
                if (iVar3 == 0) {
                    return 0x8007000e;
                }
            }
            uVar4 = uVar4 + 1;
            *(uint32_t*)(iVar1 + 0x14) = 0;
            *(uint32_t*)(iVar1 + 0x1c) = 0;
        } while (uVar4 < *(uint32_t*)((char*)self + 0xc));
    }
    local_8 = 0;
    if (*(int32_t*)((char*)self + 0xc) != 0) {
        do {
            iVar1 = *(int32_t*)(*(int32_t*)((char*)self + 0x18) + local_8 * 4);
            if ((*(uint16_t*)(iVar1 + 2) & 0xfff0) != 0) {
                uVar4 = 0;
                if (*(int32_t*)(iVar1 + 0xc) != 0) {
                    do {
                        FUN_0066228a(*(uint32_t*)(*(int32_t*)(iVar1 + 0x10) + uVar4 * 4), local_8, 0);
                        uVar4 = uVar4 + 1;
                    } while (uVar4 < *(uint32_t*)(iVar1 + 0xc));
                }
                uVar4 = 0;
                if (*(int32_t*)(iVar1 + 4) != 0) {
                    do {
                        iVar3 = *(int32_t*)(*(int32_t*)(iVar1 + 8) + uVar4 * 4);
                        if ((iVar3 != -1) &&
                            (iVar2 = *(int32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                             iVar3 * 4) +
                                                 0x38),
                             iVar2 != -1)) {
                            iVar3 = iVar2;
                        }
                        FUN_0066228a(iVar3, local_8, 1);
                        uVar4 = uVar4 + 1;
                    } while (uVar4 < *(uint32_t*)(iVar1 + 4));
                }
            }
            local_8 = local_8 + 1;
        } while (local_8 < *(uint32_t*)((char*)self + 0xc));
    }
    local_c = 0;
    if (*(int32_t*)((char*)self + 0xc) != 0) {
        do {
            iVar1 = *(int32_t*)(*(int32_t*)((char*)self + 0x18) + local_c * 4);
            if (*(int32_t*)(iVar1 + 0x14) != 0) {
                FUN_0065e1b9(FUN_0065de5f, (void*)*(uint32_t*)(iVar1 + 0x18),
                             *(int32_t*)(iVar1 + 0x14), 0);
                local_8 = 1;
                uVar4 = 1;
                if (1 < *(uint32_t*)(iVar1 + 0x14)) {
                    do {
                        iVar3 = *(int32_t*)(iVar1 + 0x18);
                        iVar2 = *(int32_t*)(iVar3 + uVar4 * 4);
                        if (iVar2 != *(int32_t*)(iVar3 + -4 + uVar4 * 4)) {
                            *(int32_t*)(iVar3 + local_8 * 4) = iVar2;
                            local_8 = local_8 + 1;
                        }
                        uVar4 = uVar4 + 1;
                    } while (uVar4 < *(uint32_t*)(iVar1 + 0x14));
                }
                *(uint32_t*)(iVar1 + 0x14) = local_8;
            }
            if (*(int32_t*)(iVar1 + 0x1c) != 0) {
                FUN_0065e1b9(FUN_0065de5f, (void*)*(uint32_t*)(iVar1 + 0x20),
                             *(int32_t*)(iVar1 + 0x1c), 0);
                local_8 = 1;
                uVar4 = 1;
                if (1 < *(uint32_t*)(iVar1 + 0x1c)) {
                    do {
                        iVar3 = *(int32_t*)(iVar1 + 0x20);
                        iVar2 = *(int32_t*)(iVar3 + uVar4 * 4);
                        if (iVar2 != *(int32_t*)(iVar3 + -4 + uVar4 * 4)) {
                            *(int32_t*)(iVar3 + local_8 * 4) = iVar2;
                            local_8 = local_8 + 1;
                        }
                        uVar4 = uVar4 + 1;
                    } while (uVar4 < *(uint32_t*)(iVar1 + 0x1c));
                }
                *(uint32_t*)(iVar1 + 0x1c) = local_8;
            }
            local_c = local_c + 1;
        } while (local_c < *(uint32_t*)((char*)self + 0xc));
    }
    return 0;
}

// 0x66254f — observed shape
uint32_t FUN_66254f(void* self)
{
    uint32_t uVar1;

    uVar1 = 0;
    if (*(int32_t*)((char*)self + 8) != 0) {
        do {
            *(uint32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x14) + uVar1 * 4) + 0x30) = uVar1;
            uVar1 = uVar1 + 1;
        } while (uVar1 < *(uint32_t*)((char*)self + 8));
    }
    return 0;
}

// 0x662568 — observed shape
uint32_t FUN_662568(void* self)
{
    int* piVar1;
    int iVar2;
    int* piVar3;
    uint32_t uVar4;
    int iVar5;
    uint32_t uVar6;
    uint32_t local_8;

    uVar6 = 0;
    if (*(int32_t*)((char*)self + 8) != 0) {
        do {
            iVar2 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) + uVar6 * 4);
            if (*(int32_t*)(iVar2 + 8) == -1) {
                uVar4 = 0xffffffff;
            }
            else {
                uVar4 = *(uint32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                 *(int32_t*)(iVar2 + 8) * 4) +
                                     0x30);
            }
            *(uint32_t*)(iVar2 + 8) = uVar4;
            if (*(int32_t*)(iVar2 + 0x14) == -1) {
                uVar4 = 0xffffffff;
            }
            else {
                uVar4 = *(uint32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                 *(int32_t*)(iVar2 + 0x14) * 4) +
                                     0x30);
            }
            *(uint32_t*)(iVar2 + 0x14) = uVar4;
            if (*(int32_t*)(iVar2 + 0x38) == -1) {
                uVar4 = 0xffffffff;
            }
            else {
                uVar4 = *(uint32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                 *(int32_t*)(iVar2 + 0x38) * 4) +
                                     0x30);
            }
            uVar6 = uVar6 + 1;
            *(uint32_t*)(iVar2 + 0x38) = uVar4;
        } while (uVar6 < *(uint32_t*)((char*)self + 8));
    }
    local_8 = 0;
    if (*(int32_t*)((char*)self + 0xc) != 0) {
        do {
            piVar3 = *(int**)(*(int32_t*)((char*)self + 0x18) + local_8 * 4);
            uVar6 = 0;
            if (*piVar3 != 0) {
                if (piVar3[1] != 0) {
                    do {
                        iVar5 = -1;
                        piVar1 = (int*)(piVar3[2] + uVar6 * 4);
                        iVar2 = *piVar1;
                        if (iVar2 != -1) {
                            iVar5 = *(int32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                           iVar2 * 4) +
                                               0x30);
                        }
                        uVar6 = uVar6 + 1;
                        *piVar1 = iVar5;
                    } while (uVar6 < (uint32_t)piVar3[1]);
                }
                uVar6 = 0;
                if (piVar3[3] != 0) {
                    do {
                        iVar5 = -1;
                        piVar1 = (int*)(piVar3[4] + uVar6 * 4);
                        iVar2 = *piVar1;
                        if (iVar2 != -1) {
                            iVar5 = *(int32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                           iVar2 * 4) +
                                               0x30);
                        }
                        uVar6 = uVar6 + 1;
                        *piVar1 = iVar5;
                    } while (uVar6 < (uint32_t)piVar3[3]);
                }
            }
            local_8 = local_8 + 1;
        } while (local_8 < *(uint32_t*)((char*)self + 0xc));
    }
    return 0;
}

// 0x662648 — observed shape
void FUN_662648(void* self, int param_1, char* param_2, size_t param_3)
{
    int* piVar1;
    char* pcVar2;
    int iVar3;
    char* _Format;

    piVar1 = (int*)(param_1 + 4);
    if (*(int32_t*)(param_1 + 0x38) != -1) {
        param_1 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) + *(int32_t*)(param_1 + 0x38) * 4);
    }
    pcVar2 = *(char**)(*(uint32_t*)(*(uint32_t*)((char*)self + 0x10) + *piVar1 * 4));
    if ((*pcVar2 == '\0') || (pcVar2[1] != '\0')) {
        _Format = (char*)"%s_";
    }
    else {
        _Format = (char*)"%s";
    }
    iVar3 = _snprintf(param_2, param_3, _Format, pcVar2);
    if (*(int32_t*)(param_1 + 0xc) == -1) {
        _snprintf(param_2 + iVar3, param_3 - iVar3, "?");
    }
    else {
        _snprintf(param_2 + iVar3, param_3 - iVar3, "%u", *(int32_t*)(param_1 + 0xc));
    }
    param_2[param_3 - 1] = '\0';
    return;
}

// 0x6626da — observed shape
uint32_t FUN_6626da(int param_1, int param_2, uint32_t param_3, char* param_4, char param_5)
{
    int iVar1;
    int iVar2;
    char local_104[255];
    uint8_t local_5;

    _vsnprintf(local_104, 0x100, param_4, &param_5);
    iVar2 = 0;
    local_5 = 0;
    if (param_2 != 0) {
        iVar1 = *(int32_t*)(param_2 + 4);
        if (iVar1 == 3) {
            iVar2 = param_2 + 0x10;
        }
        else if (iVar1 == 6) {
            iVar2 = *(int32_t*)(param_2 + 0x14) + 0x10;
        }
        else if (iVar1 == 0xd) {
            iVar2 = param_2 + 0x30;
        }
    }
    FUN_0060fcd3(*(uint32_t*)(param_1 + 0xc4), iVar2, param_3, &DAT_006c7974, local_104);
    *(uint32_t*)(param_1 + 0xd4) = 1;
    return 0;
}

// 0x66275f — observed shape
uint32_t FUN_66275f(int param_1, int param_2, uint32_t param_3, char* param_4, char param_5)
{
    int iVar1;
    int iVar2;
    char local_104[255];
    uint8_t local_5;

    _vsnprintf(local_104, 0x100, param_4, &param_5);
    iVar2 = 0;
    local_5 = 0;
    if (param_2 != 0) {
        iVar1 = *(int32_t*)(param_2 + 4);
        if (iVar1 == 3) {
            iVar2 = param_2 + 0x10;
        }
        else if (iVar1 == 6) {
            iVar2 = *(int32_t*)(param_2 + 0x14) + 0x10;
        }
        else if (iVar1 == 0xd) {
            iVar2 = param_2 + 0x30;
        }
    }
    FUN_0060fd9a(*(uint32_t*)(param_1 + 0xc4), iVar2, param_3, &DAT_006c7974, local_104);
    return 0;
}

// 0x6627d8 — observed shape
uint32_t FUN_6627d8(int32_t self, int* param_1, uint32_t param_2)
{
    uint32_t* puVar1;
    uint32_t* puVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    uint32_t uVar6;
    int iVar7;
    int* piVar8;
    uint32_t uVar9;
    uint32_t uVar10;
    uint32_t uVar11;
    uint32_t local_c;
    int* local_8;

    iVar5 = (int)param_2;
    puVar1 = *(uint32_t**)(*(int32_t*)(param_2 + 0x18) + self * 4);
    puVar2 = *(uint32_t**)(*(int32_t*)(param_2 + 0x18) + (int32_t)param_1 * 4);
    if (*puVar1 < *puVar2) {
        return 0xffffffff;
    }
    if (*puVar2 < *puVar1) {
        return 1;
    }
    local_8 = (int*)0x0;
    if (puVar1[3] != 0) {
        param_1 = (int*)puVar2[4];
        iVar7 = (int)puVar1[4] - (int)(intptr_t)param_1;
        do {
            iVar3 = *(int32_t*)(*(int32_t*)(param_2 + 0x14) + *(int32_t*)(iVar7 + (int)(intptr_t)param_1) * 4);
            iVar4 = *(int32_t*)(*(int32_t*)(param_2 + 0x14) + *param_1 * 4);
            if (*(uint32_t*)(iVar3 + 4) < *(uint32_t*)(iVar4 + 4)) {
                return 0xffffffff;
            }
            if (*(uint32_t*)(iVar4 + 4) < *(uint32_t*)(iVar3 + 4)) {
                return 1;
            }
            if (*(uint32_t*)(iVar3 + 0x14) < *(uint32_t*)(iVar4 + 0x14)) {
                return 0xffffffff;
            }
            if (*(uint32_t*)(iVar4 + 0x14) < *(uint32_t*)(iVar3 + 0x14)) {
                return 1;
            }
            if (*(int32_t*)(iVar3 + 0x18) < *(int32_t*)(iVar4 + 0x18)) {
                return 0xffffffff;
            }
            if (*(int32_t*)(iVar4 + 0x18) < *(int32_t*)(iVar3 + 0x18)) {
                return 1;
            }
            local_8 = (int*)((int)(intptr_t)local_8 + 1);
            param_1 = param_1 + 1;
        } while ((uint32_t)(intptr_t)local_8 < puVar1[3]);
    }
    iVar7 = FUN_0065cd09();
    if (iVar7 == 0) {
        param_2 = 0;
        if (puVar1[1] != 0) {
            piVar8 = (int*)puVar2[2];
            iVar7 = (int)puVar1[2] - (int)(intptr_t)piVar8;
            do {
                uVar9 = *(uint32_t*)(*(int32_t*)(*(int32_t*)(iVar5 + 0x14) +
                                                 *(int32_t*)(iVar7 + (int)(intptr_t)piVar8) * 4) +
                                     0x30);
                uVar11 = *(uint32_t*)(*(int32_t*)(*(int32_t*)(iVar5 + 0x14) + *piVar8 * 4) + 0x30);
                if (uVar9 < uVar11) {
                    return 0xffffffff;
                }
                if (uVar11 < uVar9) {
                    return 1;
                }
                param_2 = param_2 + 1;
                piVar8 = piVar8 + 1;
            } while (param_2 < puVar1[1]);
        }
    }
    else {
        uVar9 = *puVar1 & 0xfffff;
        local_c = 0;
        if (uVar9 != 0) {
            local_8 = (int*)puVar2[2];
            iVar5 = *(int32_t*)(param_2 + 0x14);
            piVar8 = local_8 + uVar9;
            iVar7 = (int)puVar1[2] - (int)(intptr_t)local_8;
            do {
                param_1 = *(int**)(*(int32_t*)(iVar5 + *(int32_t*)(iVar7 + (int)(intptr_t)local_8) * 4) +
                                   0x30);
                uVar11 = *(uint32_t*)(*(int32_t*)(iVar5 + *local_8 * 4) + 0x30);
                uVar10 = *(uint32_t*)(*(int32_t*)(iVar5 + *(int32_t*)(iVar7 + (int)(intptr_t)piVar8) * 4) +
                                      0x30);
                uVar6 = *(uint32_t*)(*(int32_t*)(iVar5 + *piVar8 * 4) + 0x30);
                param_2 = (uint32_t)(intptr_t)param_1;
                if ((intptr_t)param_1 < (intptr_t)uVar10) {
                    param_1 = (int*)(intptr_t)uVar10;
                }
                else {
                    param_2 = uVar10;
                    if ((intptr_t)param_1 <= (intptr_t)uVar10) {
                        param_1 = (int*)(intptr_t)uVar10;
                    }
                }
                uVar10 = uVar11;
                if (uVar11 < uVar6) {
                    uVar11 = uVar6;
                }
                else {
                    uVar10 = uVar6;
                    if (uVar11 <= uVar6) {
                        uVar11 = uVar6;
                    }
                }
                if (param_2 < uVar10) {
                    return 0xffffffff;
                }
                if (uVar10 < param_2) {
                    return 1;
                }
                if ((uint32_t)(intptr_t)param_1 < uVar11) {
                    return 0xffffffff;
                }
                if (uVar11 < (uint32_t)(intptr_t)param_1) {
                    return 1;
                }
                local_c = local_c + 1;
                local_8 = local_8 + 1;
                piVar8 = piVar8 + 1;
            } while (local_c < uVar9);
        }
    }
    return 0;
}

// 0x662977 — observed shape
uint32_t FUN_662977(uint32_t param_1, uint32_t param_2, uint32_t param_3)
{
    uint32_t uVar1;

    uVar1 = FUN_6627d8((int32_t)param_1, (int*)(intptr_t)param_2, param_3);
    if (uVar1 == 0) {
        if (param_1 < param_2) {
            uVar1 = 0xffffffff;
        }
        else {
            uVar1 = (uint32_t)(param_2 < param_1);
        }
    }
    return uVar1;
}

// 0x6629a3 — observed shape
void FUN_6629a3(void* self, uint8_t param_1)
{
    FUN_0065e376();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x6629c4 — observed shape
int32_t FUN_6629c4(int32_t* self, int param_1, int param_2, int param_3, int param_4)
{
    int iVar1;
    int* piVar2;

    if (param_2 == 0) {
        iVar1 = -0x7fffbffb;
    }
    else {
        self[0x31] = param_2;
        self[0x32] = param_3;
        self[0x35] = 0;
        self[0x36] = 0;
        self[0x37] = 0;
        self[0x30] = param_1;
        self[0x33] = param_4;
        iVar1 = FUN_0065d97c(&DAT_0070d864, 0, 0xffffffff, 4);
        self[0x1d] = iVar1;
        iVar1 = FUN_0065d97c(&DAT_006e0418, 0x311, 0xffffffff, 4);
        self[0x1e] = iVar1;
        iVar1 = FUN_0065d97c(&DAT_006c3b94, 0x251, 0xffffffff, 4);
        self[0x1f] = iVar1;
        iVar1 = FUN_0065d97c(&DAT_006e0468, 0x51, 0xffffffff, 4);
        self[0x20] = iVar1;
        iVar1 = FUN_0065d97c(&DAT_006e0410, 0x62, 0xffffffff, 4);
        self[0x21] = iVar1;
        iVar1 = FUN_0065d97c(&DAT_006d1994, 3, 0xffffffff, 4);
        self[0x22] = iVar1;
        iVar1 = FUN_0065d97c(&DAT_006d198c, 6, 0xffffffff, 4);
        self[0x23] = iVar1;
        iVar1 = FUN_0065d97c(&DAT_006e0414, 10, 0xffffffff, 4);
        self[0x24] = iVar1;
        iVar1 = FUN_0065d97c(&DAT_006e0430, 0x2d1, 0xffffffff, 4);
        self[0x25] = iVar1;
        iVar1 = FUN_0065d97c(&DAT_006e0440, 0x1003, 0xffffffff, 4);
        self[0x26] = iVar1;
        iVar1 = FUN_0065d97c(&DAT_006c3b94, 0x2251, 0xffffffff, 4);
        self[0x27] = iVar1;
        iVar1 = FUN_0065d97c(&DAT_006e0414, 0x400a, 0xffffffff, 4);
        self[0x28] = iVar1;
        iVar1 = FUN_0065d97c(&DAT_006ee294, 0xc00a, 0xffffffff, 4);
        self[0x29] = iVar1;
        iVar1 = FUN_0065d97c(&DAT_006ee290, 0x10042, 0, 4);
        self[0x2a] = iVar1;
        iVar1 = FUN_0065d97c(&DAT_006e9154, 0x20003, 0xffffffff, 4);
        self[0x2b] = iVar1;
        iVar1 = FUN_0065d97c(&DAT_006e0440, 0x40211, 0xffffffff, 4);
        self[0x2c] = iVar1;
        iVar1 = FUN_0065d97c(&DAT_006ee28c, 0x2062, 0xffffffff, 4);
        self[0x2d] = iVar1;
        iVar1 = FUN_0065d97c(&DAT_006ee288, 0x40062, 0xffffffff, 4);
        self[0x2e] = iVar1;
        if (self[1] == 0x12) {
            piVar2 = self + 10;
            for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
                *piVar2 = 0;
                piVar2 = piVar2 + 1;
            }
            iVar1 = (*reinterpret_cast<int (**)(void)>(self[0] + 0xc))();
            if ((-1 < iVar1) && (iVar1 = FUN_0065e3ad(0), -1 < iVar1)) {
                iVar1 = 0;
            }
        }
        else {
            iVar1 = -0x7ff8fff2;
        }
    }
    return iVar1;
}

// 0x662bf9 — observed shape
int32_t FUN_662bf9(int32_t* self, int param_1, int param_2, int param_3)
{
    int iVar1;
    int* piVar2;

    iVar1 = FUN_0065dc39(param_1);
    if (-1 < iVar1) {
        self[0x30] = *(int32_t*)(param_1 + 0xc0);
        iVar1 = *(int32_t*)(param_1 + 0xc4);
        self[0x35] = 0;
        self[0x36] = 0;
        self[0x37] = 0;
        self[0x31] = iVar1;
        self[0x32] = param_2;
        self[0x33] = param_3;
        self[0x1d] = *(int32_t*)(param_1 + 0x74);
        self[0x1e] = *(int32_t*)(param_1 + 0x78);
        self[0x1f] = *(int32_t*)(param_1 + 0x7c);
        self[0x20] = *(int32_t*)(param_1 + 0x80);
        self[0x21] = *(int32_t*)(param_1 + 0x84);
        self[0x22] = *(int32_t*)(param_1 + 0x88);
        self[0x23] = *(int32_t*)(param_1 + 0x8c);
        self[0x24] = *(int32_t*)(param_1 + 0x90);
        self[0x25] = *(int32_t*)(param_1 + 0x94);
        self[0x26] = *(int32_t*)(param_1 + 0x98);
        self[0x27] = *(int32_t*)(param_1 + 0x9c);
        self[0x28] = *(int32_t*)(param_1 + 0xa0);
        self[0x29] = *(int32_t*)(param_1 + 0xa4);
        self[0x2a] = *(int32_t*)(param_1 + 0xa8);
        self[0x2b] = *(int32_t*)(param_1 + 0xac);
        self[0x2c] = *(int32_t*)(param_1 + 0xb0);
        self[0x2d] = *(int32_t*)(param_1 + 0xb4);
        self[0x2e] = *(int32_t*)(param_1 + 0xb8);
        piVar2 = self + 10;
        for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
            *piVar2 = 0;
            piVar2 = piVar2 + 1;
        }
        iVar1 = (*reinterpret_cast<int (**)(void)>(self[0] + 0xc))();
        if (-1 < iVar1) {
            iVar1 = FUN_0065e3ad(0);
            if (-1 < iVar1) {
                iVar1 = 0;
            }
        }
    }
    return iVar1;
}

// 0x662d42 — observed shape
uint32_t FUN_662d42(void* self)
{
    int* piVar1;
    int iVar2;
    int iVar3;
    bool bVar4;
    int iVar5;
    int iVar7;
    uint32_t uVar6;
    uint32_t local_8;

    uVar6 = 0;
    bVar4 = false;
    if (*(int32_t*)((char*)self + 4) != 0) {
        do {
            iVar2 = *(int32_t*)(*(int32_t*)((char*)self + 0x10) + uVar6 * 4);
            uVar6 = uVar6 + 1;
            *(uint32_t*)(iVar2 + 0x28) = 0xffffffff;
            *(uint32_t*)(iVar2 + 0x24) = 0xffffffff;
        } while (uVar6 < *(uint32_t*)((char*)self + 4));
    }
    uVar6 = 0;
    if (*(int32_t*)((char*)self + 8) != 0) {
        do {
            iVar2 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) + uVar6 * 4);
            uVar6 = uVar6 + 1;
            *(uint32_t*)(iVar2 + 0x54) = 0xffffffff;
            *(uint32_t*)(iVar2 + 0x48) = 0xffffffff;
        } while (uVar6 < *(uint32_t*)((char*)self + 8));
    }
    uVar6 = 0;
    if (*(int32_t*)((char*)self + 0xc) != 0) {
        do {
            iVar2 = *(int32_t*)(*(int32_t*)((char*)self + 0x18) + uVar6 * 4);
            if ((*(uint16_t*)(iVar2 + 2) & 0xfff0) != 0) {
                local_8 = 0;
                if (*(int32_t*)(iVar2 + 4) != 0) {
                    do {
                        iVar5 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                            *(int32_t*)(*(int32_t*)(iVar2 + 8) + local_8 * 4) * 4);
                        if (uVar6 < *(uint32_t*)(iVar5 + 0x54)) {
                            *(uint32_t*)(iVar5 + 0x54) = uVar6;
                        }
                        piVar1 = (int*)(iVar5 + 8);
                        iVar7 = *piVar1;
                        iVar3 = iVar5;
                        while (iVar7 != -1) {
                            iVar7 = *(int32_t*)(*(int32_t*)((char*)self + 0x10) +
                                                *(int32_t*)(iVar3 + 4) * 4);
                            if (uVar6 < *(uint32_t*)(iVar7 + 0x28)) {
                                *(uint32_t*)(iVar7 + 0x28) = uVar6;
                            }
                            iVar3 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) + *piVar1 * 4);
                            if (uVar6 < *(uint32_t*)(iVar3 + 0x54)) {
                                *(uint32_t*)(iVar3 + 0x54) = uVar6;
                            }
                            piVar1 = (int*)(iVar3 + 8);
                            iVar7 = *piVar1;
                        }
                        while (*(int32_t*)(iVar5 + 0x14) != -1) {
                            iVar5 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                *(int32_t*)(iVar5 + 0x14) * 4);
                            if (uVar6 < *(uint32_t*)(iVar5 + 0x54)) {
                                *(uint32_t*)(iVar5 + 0x54) = uVar6;
                            }
                        }
                        local_8 = local_8 + 1;
                    } while (local_8 < *(uint32_t*)(iVar2 + 4));
                }
                local_8 = 0;
                if (*(int32_t*)(iVar2 + 0xc) != 0) {
                    do {
                        iVar5 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                            *(int32_t*)(*(int32_t*)(iVar2 + 0x10) + local_8 * 4) * 4);
                        if (uVar6 < *(uint32_t*)(iVar5 + 0x48)) {
                            *(uint32_t*)(iVar5 + 0x48) = uVar6;
                        }
                        iVar7 = iVar5;
                        if (*(int32_t*)(iVar5 + 8) != -1) {
                            iVar7 = *(int32_t*)(*(int32_t*)((char*)self + 0x10) +
                                                *(int32_t*)(iVar5 + 4) * 4);
                            if (uVar6 < *(uint32_t*)(iVar7 + 0x24)) {
                                *(uint32_t*)(iVar7 + 0x24) = uVar6;
                            }
                            iVar7 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                *(int32_t*)(iVar5 + 8) * 4);
                            if (uVar6 < *(uint32_t*)(iVar7 + 0x54)) {
                                *(uint32_t*)(iVar7 + 0x54) = uVar6;
                            }
                        }
                        if (*(int32_t*)(iVar7 + 8) != -1) {
                            do {
                                iVar3 = *(int32_t*)(*(int32_t*)((char*)self + 0x10) +
                                                    *(int32_t*)(iVar7 + 4) * 4);
                                if (uVar6 < *(uint32_t*)(iVar3 + 0x28)) {
                                    *(uint32_t*)(iVar3 + 0x28) = uVar6;
                                }
                                iVar7 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                    *(int32_t*)(iVar7 + 8) * 4);
                                if (uVar6 < *(uint32_t*)(iVar7 + 0x54)) {
                                    *(uint32_t*)(iVar7 + 0x54) = uVar6;
                                }
                            } while (*(int32_t*)(iVar7 + 8) != -1);
                        }
                        while (*(int32_t*)(iVar5 + 0x14) != -1) {
                            iVar5 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                *(int32_t*)(iVar5 + 0x14) * 4);
                            if (uVar6 < *(uint32_t*)(iVar5 + 0x54)) {
                                *(uint32_t*)(iVar5 + 0x54) = uVar6;
                            }
                        }
                        local_8 = local_8 + 1;
                    } while (local_8 < *(uint32_t*)(iVar2 + 0xc));
                }
            }
            uVar6 = uVar6 + 1;
        } while (uVar6 < *(uint32_t*)((char*)self + 0xc));
    }
    FUN_00661ef2();
    local_8 = 0;
    if (*(int32_t*)((char*)self + 8) != 0) {
        do {
            iVar2 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) + local_8 * 4);
            iVar5 = *(int32_t*)(*(int32_t*)((char*)self + 0x10) + *(int32_t*)(iVar2 + 4) * 4);
            if (*(uint32_t*)(iVar5 + 0x28) < *(uint32_t*)(iVar2 + 0x54)) {
                *(uint32_t*)(iVar2 + 0x54) = *(uint32_t*)(iVar5 + 0x28);
            }
            if (*(uint32_t*)(iVar5 + 0x24) < *(uint32_t*)(iVar2 + 0x48)) {
                *(uint32_t*)(iVar2 + 0x48) = *(uint32_t*)(iVar5 + 0x24);
            }
            uVar6 = *(uint32_t*)(iVar5 + 4);
            if ((((uVar6 & 0x10) == 0) && (*(uint32_t*)(iVar2 + 0x54) != 0xffffffff)) &&
                (*(uint32_t*)(iVar2 + 0x54) <= *(uint32_t*)(iVar2 + 0x48))) {
                iVar2 = *(int32_t*)(iVar2 + 0x60);
                if (((iVar2 == 0) || (*(int32_t*)(iVar2 + 4) != 6)) ||
                    ((*(int32_t*)(iVar2 + 0x14) == 0 ||
                      (*(int32_t*)(*(int32_t*)(iVar2 + 0x14) + 4) != 3)))) {
LAB_00662fb3:
                    // call shape as observed: stack arguments not recovered
                    (*(uint32_t (*)())(uintptr_t)0x6626da)();
                }
                else if (*(int32_t*)(iVar2 + 0x28) == 0) {
                    (*(uint32_t (*)())(uintptr_t)0x6626da)();
                    *(uint32_t*)(iVar2 + 0x28) = 1;
                }
LAB_00663044:
                bVar4 = true;
            }
            else {
                if (((uVar6 & 0x20) != 0) && (*(int32_t*)(iVar2 + 0x48) == -1)) goto LAB_00663039;
                if (((uVar6 & 2) == 0) && (*(int32_t*)(iVar2 + 0x48) != -1)) goto LAB_00662fb3;
                if (((uVar6 & 0xd) == 0) && (*(int32_t*)(iVar2 + 0x54) != -1)) {
LAB_00663039:
                    (*(uint32_t (*)())(uintptr_t)0x6626da)();
                    goto LAB_00663044;
                }
                if ((*(int32_t*)((char*)self + 0xd8) != 0) &&
                    ((((uVar6 & 0x10120) == 0 && (*(int32_t*)(iVar2 + 0x54) == -1)) &&
                      (((uVar6 & 0x10) != 0 ||
                        (((*(int32_t*)(iVar2 + 0x48) != -1 && (iVar5 = FUN_0065ccac(), iVar5 == 0)) &&
                          ((**(uint32_t**)(*(int32_t*)((char*)self + 0x18) +
                                           *(int32_t*)(iVar2 + 0x48) * 4) &
                            0xfff00000) != 0x20900000)))))))) {
                    if (*(int32_t*)(iVar2 + 0x48) != -1) goto LAB_00662fb3;
                    goto LAB_00663039;
                }
            }
            local_8 = local_8 + 1;
        } while (local_8 < *(uint32_t*)((char*)self + 8));
        if (bVar4) {
            return 0x80004005;
        }
    }
    return 0;
}

// 0x66306d — observed shape
int32_t FUN_66306d(void* self)
{
    int iVar1;
    int iVar2;
    uint32_t uVar3;
    int iVar4;
    uint32_t uVar5;
    int* piVar6;
    int local_18;
    uint32_t local_14;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;

    iVar2 = *(int32_t*)((char*)self + 8);
    local_8 = 0;
    if (iVar2 != 0) {
        piVar6 = *(int**)((char*)self + 0x14);
        do {
            uVar3 = *(uint32_t*)(*piVar6 + 0xc);
            if ((local_8 < uVar3) && (uVar3 != 0xffffffff)) {
                local_8 = uVar3;
            }
            piVar6 = piVar6 + 1;
            iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
    }
    local_8 = local_8 + 1;
    local_10 = 0;
    if (*(int32_t*)((char*)self + 0xc) != 0) {
        do {
            iVar2 = *(int32_t*)(*(int32_t*)((char*)self + 0x18) + local_10 * 4);
            uVar3 = *(uint32_t*)(iVar2 + 0xc);
            if (uVar3 != 0) {
                piVar6 = *(int**)(iVar2 + 0x10);
                local_14 = uVar3;
                do {
                    iVar4 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) + *piVar6 * 4);
                    if ((*(int32_t*)(iVar4 + 0x44) == -1) &&
                        ((*(uint8_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x10) +
                                                  *(int32_t*)(iVar4 + 4) * 4) +
                                      4) &
                          0x20) != 0)) {
                        uVar3 = uVar3 - 1;
                    }
                    piVar6 = piVar6 + 1;
                    local_14 = local_14 - 1;
                } while (local_14 != 0);
            }
            if (uVar3 != *(uint32_t*)(iVar2 + 0xc)) {
                local_14 = 0;
                if (uVar3 != 0) {
                    iVar4 = FUN_0065da35(uVar3 & 0xfffff | 0x10000000, uVar3, uVar3);
                    if (iVar4 == -1) {
                        return -0x7ff8fff2;
                    }
                    local_14 = *(int32_t*)(*(int32_t*)((char*)self + 0x18) + iVar4 * 4);
                    FUN_0065cc50();
                }
                local_c = 0;
                if (*(int32_t*)(iVar2 + 0xc) != 0) {
                    local_18 = 0;
                    do {
                        iVar4 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                            *(int32_t*)(*(int32_t*)(iVar2 + 0x10) + local_c * 4) * 4);
                        iVar1 = *(int32_t*)(*(int32_t*)((char*)self + 0x10) +
                                            *(int32_t*)(iVar4 + 4) * 4);
                        uVar5 = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x88), local_8,
                                             *(uint32_t*)(iVar4 + 0x10), 0);
                        if ((*(int32_t*)(iVar4 + 0x44) != -1) ||
                            ((*(uint8_t*)(iVar1 + 4) & 0x20) == 0)) {
                            *(uint32_t*)(local_18 + *(int32_t*)(local_14 + 0x10)) =
                                *(uint32_t*)(*(int32_t*)(iVar2 + 0x10) + local_c * 4);
                            *(uint32_t*)(local_18 + *(int32_t*)(local_14 + 8)) = uVar5;
                            local_18 = local_18 + 4;
                        }
                        *(uint32_t*)(*(int32_t*)(iVar2 + 0x10) + local_c * 4) = uVar5;
                        local_c = local_c + 1;
                    } while (local_c < *(uint32_t*)(iVar2 + 0xc));
                }
                local_8 = local_8 + 1;
            }
            local_10 = local_10 + 1;
        } while (local_10 < *(uint32_t*)((char*)self + 0xc));
    }
    iVar2 = FUN_00661fbd();
    if (-1 < iVar2) {
        uVar3 = 0;
        if (*(int32_t*)((char*)self + 8) != 0) {
            do {
                iVar2 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) + uVar3 * 4);
                if ((*(int32_t*)(iVar2 + 0x48) == -1) && (*(int32_t*)(iVar2 + 0x54) == -1)) {
                    *(uint32_t*)(iVar2 + 4) = *(uint32_t*)((char*)self + 0x74);
                }
                uVar3 = uVar3 + 1;
            } while (uVar3 < *(uint32_t*)((char*)self + 8));
        }
        iVar2 = 0;
    }
    return iVar2;
}

// 0x663203 — observed shape
int32_t FUN_663203(void* self)
{
    int iVar1;
    uint32_t* puVar2;
    int iVar3;
    int iVar4;
    int* piVar5;
    int* piVar6;
    uint32_t uVar7;
    uint32_t local_24;
    int* local_20;
    int* local_1c;
    uint32_t local_18;
    uint32_t local_14;
    void* local_10;
    uint32_t local_c;
    uint32_t local_8;

    uVar7 = 0;
    local_10 = (void*)0x0;
    FUN_00661fbd();
    local_8 = 0;
    if (*(int32_t*)((char*)self + 8) != 0) {
        do {
            iVar4 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) + uVar7 * 4);
            if ((*(uint8_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x10) +
                                         *(int32_t*)(iVar4 + 4) * 4) +
                             4) &
                 0x20) == 0) {
                *(uint32_t*)(iVar4 + 0x30) = uVar7;
            }
            else {
                iVar3 = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x88), 0, 0, 0);
                *(int32_t*)(iVar4 + 0x30) = iVar3;
                if (iVar3 == -1) goto LAB_0066347f;
                local_8 = local_8 + 1;
                *(uint32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x14) + iVar3 * 4) + 0x14) =
                    *(uint32_t*)(iVar4 + 0x14);
                *(uint32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                         *(int32_t*)(iVar4 + 0x30) * 4) +
                             0x18) = *(uint32_t*)(iVar4 + 0x18);
            }
            uVar7 = uVar7 + 1;
        } while (uVar7 < *(uint32_t*)((char*)self + 8));
        if (local_8 != 0) {
            FUN_662568(self);
            // call shape as observed: argument not recovered
            local_10 = (*(void* (*)())(uintptr_t)0x533c78)();
            if (local_10 == (void*)0x0) {
LAB_0066347f:
                local_1c = (int*)0x8007000e;
                goto LAB_006632ff;
            }
            uVar7 = 0;
            local_8 = 0;
            if (*(int32_t*)((char*)self + 8) != 0) {
                do {
                    if ((*(uint8_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x10) +
                                                 *(int32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                                         uVar7 * 4) +
                                                             4) *
                                                     4) +
                                     4) &
                         0x20) != 0) {
                        *(uint32_t*)((char*)local_10 + local_8 * 4) = uVar7;
                        local_8 = local_8 + 1;
                    }
                    uVar7 = uVar7 + 1;
                } while (uVar7 < *(uint32_t*)((char*)self + 8));
            }
            FUN_0065e1b9(FUN_0065ddd1, local_10, local_8, self);
            local_18 = 0;
            if (local_8 != 0) {
                do {
                    piVar5 = (int*)((char*)local_10 + local_18 * 4);
                    iVar4 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) + *piVar5 * 4);
                    local_14 = local_18 + 1;
                    local_c = 1;
                    if (local_14 < local_8) {
                        local_1c = piVar5;
                        do {
                            local_1c = local_1c + 1;
                            iVar3 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) + *local_1c * 4);
                            if (((*(int32_t*)(iVar4 + 4) != *(int32_t*)(iVar3 + 4)) ||
                                 (*(int32_t*)(iVar4 + 8) != *(int32_t*)(iVar3 + 8))) ||
                                (*(int32_t*)(iVar4 + 0xc) != *(int32_t*)(iVar3 + 0xc))) {
                                break;
                            }
                            local_c = local_c + 1;
                            local_14 = local_14 + 1;
                        } while (local_14 < local_8);
                    }
                    iVar4 = FUN_0065da35(local_c & 0xfffff | 0x10000000, 0xffffffff, 0xffffffff);
                    if (iVar4 == -1) goto LAB_0066347f;
                    iVar4 = *(int32_t*)(*(int32_t*)((char*)self + 0x18) + iVar4 * 4);
                    local_24 = 0;
                    if (local_c != 0) {
                        local_20 = piVar5;
                        do {
                            iVar3 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) + *local_20 * 4);
                            iVar1 = *(int32_t*)(iVar3 + 0x30);
                            iVar3 = *(int32_t*)(iVar3 + 0x48);
                            while (iVar3 != -1) {
                                puVar2 = *(uint32_t**)(*(int32_t*)((char*)self + 0x18) + iVar3 * 4);
                                if ((puVar2[0xf] != 0) &&
                                    (local_1c = (int*)(intptr_t)FUN_0065cc50(),
                                     (intptr_t)local_1c < 0)) {
                                    goto LAB_006632ff;
                                }
                                if ((*puVar2 & 0xfff00000) != 0x10000000) break;
                                uVar7 = 0;
                                if (puVar2[3] != 0) {
                                    piVar6 = (int*)puVar2[4];
                                    do {
                                        if (iVar1 == *piVar6) break;
                                        uVar7 = uVar7 + 1;
                                        piVar6 = piVar6 + 1;
                                    } while (uVar7 < puVar2[3]);
                                }
                                iVar1 = *(int32_t*)(puVar2[2] + uVar7 * 4);
                                iVar3 = *(int32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                                iVar1 * 4) +
                                                    0x48);
                            }
                            if (*(int32_t*)(iVar4 + 0x3c) != 0) break;
                            local_24 = local_24 + 1;
                            local_20 = local_20 + 1;
                        } while (local_24 < local_c);
                    }
                    uVar7 = 0;
                    if (local_c != 0) {
                        do {
                            *(uint32_t*)(*(int32_t*)(iVar4 + 8) + uVar7 * 4) =
                                *(uint32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x14) + *piVar5 * 4) +
                                             0x30);
                            *(int32_t*)(*(int32_t*)(iVar4 + 0x10) + uVar7 * 4) = *piVar5;
                            uVar7 = uVar7 + 1;
                            piVar5 = piVar5 + 1;
                        } while (uVar7 < local_c);
                    }
                    local_18 = local_18 + local_c;
                } while (local_18 < local_8);
            }
        }
    }
    local_1c = (int*)0x0;
LAB_006632ff:
    operator_delete(local_10);
    return (int32_t)(intptr_t)local_1c;
}

// 0x66348b — observed shape
void FUN_66348b(void* self, int param_1, uint32_t param_2)
{
    int iVar1;

    if (param_2 != 0) {
        do {
            if (param_1 != -1) {
                iVar1 = *(int32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x14) + param_1 * 4) + 0x38);
                if (iVar1 != -1) {
                    param_1 = iVar1;
                }
            }
            iVar1 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) + param_1 * 4);
            if (*(uint32_t*)(iVar1 + 0x54) < param_2) {
                *(uint32_t*)(iVar1 + 0x54) = param_2;
            }
            if (*(int32_t*)(iVar1 + 8) != -1) {
                FUN_66348b(self, *(int32_t*)(iVar1 + 8), *(uint32_t*)(iVar1 + 0x54));
            }
            param_1 = *(int32_t*)(iVar1 + 0x14);
        } while ((param_1 != -1) && (param_2 = *(uint32_t*)(iVar1 + 0x54), param_2 != 0));
    }
    return;
}

// 0x6634e9 — observed shape
bool FUN_6634e9(void* self)
{
    uint32_t* puVar1;
    int iVar2;
    bool bVar3;
    uint32_t uVar4;
    int* piVar5;
    uint32_t uVar6;
    int iVar7;
    int iVar8;
    int iVar9;
    uint32_t uVar10;
    bool bVar11;
    uint32_t local_1c;
    int local_18;
    uint32_t local_14;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;

    bVar3 = false;
    FUN_00661fbd();
    uVar6 = 0;
    if (*(int32_t*)((char*)self + 8) != 0) {
        do {
            iVar8 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) + uVar6 * 4);
            uVar6 = uVar6 + 1;
            *(uint32_t*)(iVar8 + 0x54) =
                -(uint32_t)((*(uint32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x10) +
                                                      *(int32_t*)(iVar8 + 4) * 4) +
                                          4) &
                             0x10020) != 0) &
                2;
        } while (uVar6 < *(uint32_t*)((char*)self + 8));
    }
    iVar8 = *(int32_t*)((char*)self + 0xc);
    while (uVar6 = 0, iVar8 != 0) {
        iVar8 = iVar8 + -1;
        puVar1 = *(uint32_t**)(*(int32_t*)((char*)self + 0x18) + iVar8 * 4);
        if (((*puVar1 & 0xfff00000) == 0x20900000) && (puVar1[3] != 0)) {
            do {
                iVar9 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                    *(int32_t*)(puVar1[4] + uVar6 * 4) * 4);
                if (*(int32_t*)(iVar9 + 0x54) != 2) {
                    *(uint32_t*)(iVar9 + 0x54) = 1;
                }
                uVar6 = uVar6 + 1;
            } while (uVar6 < puVar1[3]);
        }
    }
    do {
        local_10 = *(uint32_t*)((char*)self + 0xc);
        bVar11 = false;
        if (local_10 == 0) break;
        do {
            local_10 = local_10 - 1;
            puVar1 = *(uint32_t**)(*(int32_t*)((char*)self + 0x18) + local_10 * 4);
            uVar6 = *puVar1;
            if ((uVar6 & 0xfff00000) != 0) {
                if (((uVar6 & 0xf0000000) < 0x10000000) || (0x40000000 < (uVar6 & 0xf0000000))) {
                    uVar6 = puVar1[3];
                    local_8 = 0;
                    if (uVar6 != 0) {
                        piVar5 = (int*)puVar1[4];
                        local_1c = uVar6;
                        do {
                            uVar10 = *(uint32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                              *piVar5 * 4) +
                                                  0x54);
                            if (local_8 < uVar10) {
                                local_8 = uVar10;
                            }
                            piVar5 = piVar5 + 1;
                            local_1c = local_1c - 1;
                        } while (local_1c != 0);
                        if (local_8 == 1) {
                            bVar11 = true;
                        }
                    }
                    uVar10 = 0;
                    if (uVar6 != 0) {
                        do {
                            FUN_66348b(self, *(int32_t*)(puVar1[4] + uVar10 * 4), local_8);
                            uVar10 = uVar10 + 1;
                        } while (uVar10 < puVar1[3]);
                    }
                    uVar6 = 0;
                    if (puVar1[1] != 0) {
                        do {
                            FUN_66348b(self, *(int32_t*)(puVar1[2] + uVar6 * 4), local_8);
                            uVar6 = uVar6 + 1;
                        } while (uVar6 < puVar1[1]);
                    }
                }
                else {
                    uVar6 = puVar1[1] / (uVar6 & 0xfffff);
                    local_8 = 0;
                    if (puVar1[3] != 0) {
                        do {
                            iVar8 = *(int32_t*)(puVar1[4] + local_8 * 4);
                            iVar9 = *(int32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                            iVar8 * 4) +
                                                0x54);
                            if (iVar9 == 1) {
                                bVar11 = true;
                            }
                            FUN_66348b(self, iVar8, (uint32_t)iVar9);
                            local_c = 0;
                            if (uVar6 != 0) {
                                do {
                                    FUN_66348b(self,
                                               *(int32_t*)(puVar1[2] +
                                                           (puVar1[3] * local_c + local_8) * 4),
                                               (uint32_t)iVar9);
                                    local_c = local_c + 1;
                                } while (local_c < uVar6);
                            }
                            local_8 = local_8 + 1;
                        } while (local_8 < puVar1[3]);
                    }
                }
            }
        } while (local_10 != 0);
        if (!bVar11) break;
        bVar11 = false;
        local_c = 0;
        if (*(int32_t*)((char*)self + 0xc) == 0) break;
        do {
            puVar1 = *(uint32_t**)(*(int32_t*)((char*)self + 0x18) + local_c * 4);
            if ((*puVar1 & 0xfff00000) == 0x20900000) {
                uVar6 = puVar1[3];
                local_8 = 0;
                if (uVar6 != 0) {
                    do {
                        iVar8 = *(int32_t*)((char*)self + 0x14);
                        iVar9 = *(int32_t*)(iVar8 + *(int32_t*)(puVar1[4] + local_8 * 4) * 4);
                        if (*(int32_t*)(iVar9 + 0x54) == 1) {
                            iVar7 = *(int32_t*)(puVar1[2] + (uVar6 + local_8) * 4);
                            if (iVar7 != -1) {
                                iVar2 = *(int32_t*)(*(int32_t*)(iVar8 + iVar7 * 4) + 0x38);
                                if (iVar2 != -1) {
                                    iVar7 = iVar2;
                                }
                            }
                            local_10 = 0;
                            iVar2 = *(int32_t*)(*(int32_t*)((char*)self + 0x18) +
                                                *(int32_t*)(*(int32_t*)(iVar8 + iVar7 * 4) + 0x48) * 4);
                            if (*(int32_t*)(iVar2 + 0xc) != 0) {
                                piVar5 = *(int**)(iVar2 + 0x10);
                                do {
                                    if (*piVar5 == iVar7) break;
                                    local_10 = local_10 + 1;
                                    piVar5 = piVar5 + 1;
                                } while (local_10 < *(uint32_t*)(iVar2 + 0xc));
                            }
                            iVar7 = *(int32_t*)(*(int32_t*)(iVar2 + 8) + local_10 * 4);
                            if (iVar7 != -1) {
                                iVar2 = *(int32_t*)(*(int32_t*)(iVar8 + iVar7 * 4) + 0x38);
                                if (iVar2 != -1) {
                                    iVar7 = iVar2;
                                }
                            }
                            iVar8 = *(int32_t*)(*(int32_t*)(iVar8 + iVar7 * 4) + 0x54);
                            if (iVar8 != 1) {
                                *(int32_t*)(iVar9 + 0x54) = iVar8;
                                bVar11 = true;
                            }
                        }
                        local_8 = local_8 + 1;
                        uVar6 = puVar1[3];
                    } while (local_8 < uVar6);
                }
            }
            local_c = local_c + 1;
        } while (local_c < *(uint32_t*)((char*)self + 0xc));
    } while (bVar11);
    local_14 = 0;
    if (*(int32_t*)((char*)self + 0xc) != 0) {
        do {
            puVar1 = *(uint32_t**)(*(int32_t*)((char*)self + 0x18) + local_14 * 4);
            uVar6 = *puVar1;
            if ((uVar6 & 0xfff00000) != 0) {
                if (((uVar6 & 0xf0000000) < 0x10000000) || (0x40000000 < (uVar6 & 0xf0000000))) {
                    uVar6 = 0;
                    bVar11 = puVar1[3] == 0;
                    if (puVar1[3] != 0) {
                        piVar5 = (int*)puVar1[4];
                        do {
                            if (*(int32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                        *piVar5 * 4) +
                                            0x54) == 2) {
                                break;
                            }
                            uVar6 = uVar6 + 1;
                            piVar5 = piVar5 + 1;
                        } while (uVar6 < puVar1[3]);
                        bVar11 = uVar6 == puVar1[3];
                    }
                    if (bVar11) {
                        uVar6 = 0;
                        *puVar1 = 0;
                        puVar1[3] = 0;
                        goto LAB_00663911;
                    }
                }
                else {
                    uVar6 = puVar1[1] / (uVar6 & 0xfffff);
                    uVar10 = 0;
                    bVar11 = puVar1[3] == 0;
                    local_8 = 0;
                    if (puVar1[3] != 0) {
                        do {
                            iVar8 = *(int32_t*)(puVar1[4] + local_8 * 4);
                            if (*(int32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                        iVar8 * 4) +
                                            0x54) == 2) {
                                local_10 = 0;
                                *(int32_t*)(puVar1[4] + uVar10 * 4) = iVar8;
                                if (uVar6 != 0) {
                                    do {
                                        iVar8 = puVar1[3] * local_10;
                                        local_10 = local_10 + 1;
                                        *(uint32_t*)(puVar1[2] + (iVar8 + uVar10) * 4) =
                                            *(uint32_t*)(puVar1[2] + (local_8 + iVar8) * 4);
                                    } while (local_10 < uVar6);
                                }
                                uVar10 = uVar10 + 1;
                            }
                            local_8 = local_8 + 1;
                        } while (local_8 < puVar1[3]);
                        bVar11 = uVar10 == puVar1[3];
                    }
                    if (!bVar11) {
                        if (uVar10 == 0) {
                            uVar4 = 0;
                        }
                        else {
                            uVar4 = (*puVar1 ^ uVar10) & 0xfffff ^ *puVar1;
                        }
                        *puVar1 = uVar4;
                        local_8 = 1;
                        if (1 < uVar6) {
                            local_18 = uVar10 << 2;
                            do {
                                local_10 = 0;
                                if (uVar10 != 0) {
                                    iVar8 = local_18;
                                    do {
                                        iVar9 = puVar1[3] * local_8 + local_10;
                                        local_10 = local_10 + 1;
                                        *(uint32_t*)(iVar8 + puVar1[2]) =
                                            *(uint32_t*)(puVar1[2] + iVar9 * 4);
                                        iVar8 = iVar8 + 4;
                                    } while (local_10 < uVar10);
                                }
                                local_8 = local_8 + 1;
                                local_18 = local_18 + uVar10 * 4;
                            } while (local_8 < uVar6);
                        }
                        uVar6 = uVar10 * uVar6;
                        puVar1[3] = uVar10;
LAB_00663911:
                        puVar1[1] = uVar6;
                        bVar3 = true;
                    }
                }
            }
            local_14 = local_14 + 1;
        } while (local_14 < *(uint32_t*)((char*)self + 0xc));
    }
    uVar6 = 0;
    if (*(int32_t*)((char*)self + 8) != 0) {
        do {
            iVar8 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) + uVar6 * 4);
            if ((uVar6 == 0xffffffff) ||
                (uVar10 = *(uint32_t*)(iVar8 + 0x38), *(uint32_t*)(iVar8 + 0x38) == 0xffffffff)) {
                uVar10 = uVar6;
            }
            if (*(int32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x14) + uVar10 * 4) + 0x54) != 2) {
                iVar9 = *(int32_t*)(iVar8 + 4);
                if (((*(int32_t*)((char*)self + 0x74) != iVar9) &&
                     ((*(int32_t*)(iVar8 + 8) != -1 ||
                       ((*(uint8_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x10) + iVar9 * 4) + 5) &
                         4) == 0)))) &&
                    ((uVar10 = *(uint32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x10) + iVar9 * 4) +
                                            4),
                      (uVar10 & 0x100) == 0 || ((uVar10 & 0x800) == 0)))) {
                    *(int32_t*)(iVar8 + 4) = *(int32_t*)((char*)self + 0x74);
                    bVar3 = true;
                }
            }
            uVar6 = uVar6 + 1;
        } while (uVar6 < *(uint32_t*)((char*)self + 8));
    }
    return !bVar3;
}

// 0x66399b — observed shape
uint32_t FUN_66399b(void* self)
{
    uint32_t* puVar1;
    uint32_t* puVar2;
    bool bVar3;
    int* piVar4;
    uint32_t uVar5;
    int iVar6;
    int iVar7;
    int iVar8;
    int iVar9;
    int iVar10;
    uint32_t* puVar11;
    uint32_t uVar12;
    uint32_t uVar13;
    bool bVar14;
    uint32_t local_50;
    int local_40;
    uint32_t local_3c;
    int* local_38;
    int* local_34;
    uint32_t local_2c;
    uint32_t local_20;
    uint32_t local_1c;
    uint32_t local_18;
    uint32_t local_14;
    uint32_t local_8;

    piVar4 = (int*)FUN_00533c78(*(int32_t*)((char*)self + 8) << 2);
    if (piVar4 != (int*)0x0) {
        local_40 = 0;
        do {
            bVar3 = false;
            local_14 = 0;
            FUN_00661fbd();
            FUN_66254f(self);
            local_8 = 0;
            if (*(int32_t*)((char*)self + 8) != 0) {
                do {
                    iVar10 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) + local_8 * 4);
                    if ((((*(int32_t*)(iVar10 + 8) == -1) &&
                          (*(int32_t*)(iVar10 + 0x48) != -1)) &&
                         (uVar13 = *(uint32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x10) +
                                                           *(int32_t*)(iVar10 + 4) * 4) +
                                                4),
                          (uVar13 & 2) != 0)) &&
                        ((uVar13 & 0x20) == 0)) {
                        puVar1 = *(uint32_t**)(*(int32_t*)((char*)self + 0x18) +
                                               *(int32_t*)(iVar10 + 0x48) * 4);
                        uVar13 = *puVar1;
                        if ((0xfffffff < (uVar13 & 0xf0000000)) &&
                            ((uVar13 & 0xf0000000) < 0x40000001)) {
                            uVar12 = uVar13 & 0xfff00000;
                            if (uVar12 < 0x11400001) {
                                if ((((uVar12 != 0x11400000) && (uVar12 != 0x10f00000)) &&
                                     (uVar12 != 0x11100000)) &&
                                    (uVar12 != 0x11200000)) {
                                    bVar14 = uVar12 == 0x11300000;
LAB_00663abb:
                                    if (!bVar14) {
                                        local_20 = 0;
                                        if (puVar1[3] != 0) {
                                            puVar11 = (uint32_t*)puVar1[4];
                                            do {
                                                if (local_8 == *puVar11) break;
                                                local_20 = local_20 + 1;
                                                puVar11 = puVar11 + 1;
                                            } while (local_20 < puVar1[3]);
                                        }
                                        uVar13 = puVar1[1] / (uVar13 & 0xfffff);
                                        uVar5 = FUN_0065cd09();
                                        local_1c = 0;
                                        if (uVar13 != 0) {
                                            do {
                                                iVar6 = FUN_0065e43a(puVar1, local_1c, local_20,
                                                                     uVar5);
                                                uVar12 = uVar12 * 0x83f + iVar6;
                                                local_1c = local_1c + 1;
                                            } while (local_1c < uVar13);
                                        }
                                        *(uint32_t*)(iVar10 + 0x40) = uVar12;
                                        piVar4[local_14] = local_8;
                                        local_14 = local_14 + 1;
                                    }
                                }
                            }
                            else if (((uVar12 != 0x11500000) && (uVar12 != 0x20700000)) &&
                                     (uVar12 != 0x20800000)) {
                                bVar14 = uVar12 == 0x20900000;
                                goto LAB_00663abb;
                            }
                        }
                    }
                    local_8 = local_8 + 1;
                } while (local_8 < *(uint32_t*)((char*)self + 8));
            }
            FUN_0065e1b9(FUN_0065e18b, piVar4, local_14, self);
            if (local_14 == 0) goto LAB_00663e30;
            local_3c = 1;
            local_50 = local_14;
            local_38 = piVar4;
            do {
                iVar10 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) + *local_38 * 4);
                puVar1 = *(uint32_t**)(*(int32_t*)((char*)self + 0x18) +
                                       *(int32_t*)(iVar10 + 0x48) * 4);
                if (*(int32_t*)(iVar10 + 0x30) == *local_38) {
                    for (local_2c = local_3c; local_2c < local_14; local_2c = local_2c + 1) {
                        iVar6 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                            piVar4[local_2c] * 4);
                        if (*(int32_t*)(iVar10 + 0x40) != *(int32_t*)(iVar6 + 0x40)) break;
                        if ((((*(int32_t*)(iVar6 + 0x30) == piVar4[local_2c]) &&
                              (*(int32_t*)(iVar10 + 0x48) != *(int32_t*)(iVar6 + 0x48))) &&
                             ((*(int32_t*)(iVar10 + 4) == *(int32_t*)(iVar6 + 4) &&
                               ((*(int32_t*)(iVar10 + 0x14) == *(int32_t*)(iVar6 + 0x14) &&
                                 (*(int32_t*)(iVar10 + 0x18) == *(int32_t*)(iVar6 + 0x18))))))) &&
                            (uVar13 = *puVar1,
                             ((**(uint32_t**)(*(int32_t*)((char*)self + 0x18) +
                                              *(int32_t*)(iVar6 + 0x48) * 4) ^
                               uVar13) &
                              0xfff00000) == 0)) {
                            uVar13 = puVar1[1] / (uVar13 & 0xfffff);
                            uVar5 = FUN_0065cd09();
                            local_20 = 0;
LAB_00663c2e:
                            iVar7 = iVar6;
                            if (local_20 == 0) {
                                iVar7 = iVar10;
                            }
                            uVar12 = *(uint32_t*)(iVar7 + 0x48);
                            iVar7 = iVar10;
                            if (local_20 == 0) {
                                iVar7 = iVar6;
                            }
                            puVar2 = *(uint32_t**)(*(int32_t*)((char*)self + 0x18) +
                                                   *(int32_t*)(iVar7 + 0x48) * 4);
                            iVar7 = *(int32_t*)(*(int32_t*)((char*)self + 0x18) + uVar12 * 4);
                            local_1c = 0;
                            if (puVar2[3] != 0) {
                                local_34 = (int*)puVar2[4];
                                do {
                                    if (*(uint32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                                 *local_34 * 4) +
                                                     0x54) <= uVar12) {
                                        break;
                                    }
                                    local_18 = 0;
                                    if (*(int32_t*)(iVar7 + 0xc) != 0) {
                                        do {
                                            local_8 = 0;
                                            if (uVar13 != 0) {
                                                do {
                                                    iVar8 = FUN_0065e43a(puVar2, local_8,
                                                                         local_1c, uVar5);
                                                    iVar9 = FUN_0065e43a((uint32_t*)iVar7,
                                                                         local_8, local_18, uVar5);
                                                    if (iVar9 != iVar8) break;
                                                    local_8 = local_8 + 1;
                                                } while (local_8 < uVar13);
                                            }
                                        } while ((local_8 != uVar13) &&
                                                 (local_18 = local_18 + 1,
                                                  local_18 < *(uint32_t*)(iVar7 + 0xc)));
                                    }
                                    if (local_18 == *(uint32_t*)(iVar7 + 0xc)) break;
                                    local_1c = local_1c + 1;
                                    local_34 = local_34 + 1;
                                } while (local_1c < (uint32_t)puVar2[3]);
                            }
                            if (local_1c < (uint32_t)puVar2[3]) goto code_r0x00663d0f;
                            local_1c = 0;
                            if (puVar2[3] != 0) {
                                do {
                                    local_20 = 0;
                                    if (*(int32_t*)(iVar7 + 0xc) != 0) {
                                        do {
                                            local_8 = 0;
                                            if (uVar13 != 0) {
                                                do {
                                                    iVar6 = FUN_0065e43a((uint32_t*)iVar7,
                                                                         local_8, local_20, uVar5);
                                                    iVar8 = FUN_0065e43a(puVar2, local_8,
                                                                         local_1c, uVar5);
                                                    if (iVar6 != iVar8) break;
                                                    local_8 = local_8 + 1;
                                                } while (local_8 < uVar13);
                                            }
                                        } while ((local_8 != uVar13) &&
                                                 (local_20 = local_20 + 1,
                                                  local_20 < *(uint32_t*)(iVar7 + 0xc)));
                                    }
                                    iVar6 = local_1c * 4;
                                    local_1c = local_1c + 1;
                                    *(uint32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                             *(int32_t*)(puVar2[4] + iVar6) * 4) +
                                                 0x30) =
                                        *(uint32_t*)(*(int32_t*)(iVar7 + 0x10) + local_20 * 4);
                                } while (local_1c < (uint32_t)puVar2[3]);
                            }
                            *puVar2 = 0;
                            bVar3 = true;
                        }
LAB_00663dcb:
                    }
                }
                local_38 = local_38 + 1;
                local_3c = local_3c + 1;
                local_50 = local_50 - 1;
            } while (local_50 != 0);
            if (!bVar3) goto LAB_00663e30;
            uVar13 = 0;
            if (*(int32_t*)((char*)self + 8) != 0) {
                iVar10 = *(int32_t*)((char*)self + 0x14);
                do {
                    iVar6 = *(int32_t*)(iVar10 + uVar13 * 4);
                    while (*(int32_t*)(iVar6 + 0x30) !=
                           *(int32_t*)(*(int32_t*)(iVar10 + *(int32_t*)(iVar6 + 0x30) * 4) +
                                       0x30)) {
                        *(uint32_t*)(iVar6 + 0x30) =
                            *(uint32_t*)(*(int32_t*)(iVar10 + *(int32_t*)(iVar6 + 0x30) * 4) +
                                         0x30);
                        iVar10 = *(int32_t*)((char*)self + 0x14);
                    }
                    uVar13 = uVar13 + 1;
                } while (uVar13 < *(uint32_t*)((char*)self + 8));
            }
            FUN_662568(self);
            local_40 = local_40 + 1;
        } while (true);
    }
    uVar13 = 0x8007000e;
LAB_00663e3b:
    operator_delete(piVar4);
    return uVar13;
code_r0x00663d0f:
    local_20 = local_20 + 1;
    if (1 < local_20) goto LAB_00663dcb;
    goto LAB_00663c2e;
LAB_00663e30:
    uVar13 = (uint32_t)(local_40 == 0);
    goto LAB_00663e3b;
}

// 0x663e4a — observed shape
uint32_t FUN_663e4a(void* self)
{
    int iVar1;
    uint32_t* puVar2;
    uint32_t* puVar3;
    bool bVar4;
    bool bVar5;
    bool bVar6;
    int iVar7;
    int iVar8;
    int* piVar9;
    int* piVar10;
    uint32_t uVar11;
    uint32_t uVar12;
    int* local_10;
    uint32_t local_c;
    uint32_t local_8;

    bVar6 = false;
    bVar5 = false;
    bVar4 = false;
    local_c = 0;
    if (*(int32_t*)((char*)self + 8) != 0) {
        do {
            iVar8 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) + local_c * 4);
            if ((*(int32_t*)((char*)self + 0x74) != *(int32_t*)(iVar8 + 4)) &&
                (piVar10 = (int*)(iVar8 + 8), *piVar10 != -1)) {
                if (!bVar4) {
                    FUN_00661fbd();
                    bVar4 = true;
                }
                iVar7 = *piVar10;
                iVar1 = *(int32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x14) + iVar7 * 4) + 0x48);
                if ((iVar1 != -1) &&
                    (puVar2 = *(uint32_t**)(*(int32_t*)((char*)self + 0x18) + iVar1 * 4),
                     (*puVar2 & 0xfff00000) == 0x10000000)) {
                    local_8 = 0;
                    if (puVar2[3] != 0) {
                        piVar10 = (int*)puVar2[4];
                        do {
                            if (*piVar10 == iVar7) break;
                            local_8 = local_8 + 1;
                            piVar10 = piVar10 + 1;
                        } while (local_8 < puVar2[3]);
                    }
                    piVar10 = (int*)(puVar2[2] + local_8 * 4);
                }
                iVar1 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) + *piVar10 * 4);
                uVar11 = *(uint32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x10) +
                                                  *(int32_t*)(iVar1 + 4) * 4) +
                                      4);
                if (((uVar11 & 0x100) == 0) || (*(int32_t*)(iVar1 + 8) != -1)) {
                    if (((uVar11 & 2) == 0) ||
                        ((*(int32_t*)(iVar1 + 0x48) == -1 ||
                          (puVar2 = *(uint32_t**)(*(int32_t*)((char*)self + 0x18) +
                                                  *(int32_t*)(iVar1 + 0x48) * 4),
                           (*puVar2 & 0xfff00000) != 0x20400000)))) {
                        goto LAB_00664120;
                    }
                    uVar11 = puVar2[3];
                    uVar12 = 0;
                    if (uVar11 != 0) {
                        piVar9 = (int*)puVar2[4];
                        do {
                            if (*piVar9 == *piVar10) break;
                            uVar12 = uVar12 + 1;
                            piVar9 = piVar9 + 1;
                        } while (uVar12 < uVar11);
                    }
                    iVar8 = *(int32_t*)(puVar2[2] + uVar12 * 4);
                    iVar1 = *(int32_t*)(puVar2[2] + (uVar11 + uVar12) * 4);
                    puVar2 = *(uint32_t**)(*(int32_t*)((char*)self + 0x14) + iVar8 * 4);
                    puVar3 = *(uint32_t**)(*(int32_t*)((char*)self + 0x14) + iVar1 * 4);
                    if (((((*(uint8_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x10) +
                                                     puVar2[1] * 4) +
                                         5) &
                            1) == 0) ||
                          (puVar2[2] != 0xffffffff)) ||
                         ((*puVar2 & 4) == 0)) ||
                        (((*puVar2 & 2) == 0 && ((*puVar3 & 2) == 0)))) {
                        if ((((*(uint8_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x10) +
                                                        puVar3[1] * 4) +
                                            5) &
                               1) == 0) ||
                             ((puVar3[2] != 0xffffffff || ((*puVar3 & 4) == 0)))) ||
                           (((*puVar2 & 2) == 0 && ((*puVar3 & 2) == 0)))) {
                            goto LAB_00664120;
                        }
                        local_10 = (int*)(intptr_t)ftol();
                    }
                    else {
                        local_10 = (int*)(intptr_t)ftol();
                        iVar8 = iVar1;
                    }
                    uVar11 = 0;
                    if (*piVar10 == iVar7) {
                        if (*(int32_t*)((char*)self + 8) != 0) {
                            do {
                                iVar1 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) + uVar11 * 4);
                                if (iVar7 == *(int32_t*)(iVar1 + 8)) {
                                    *(int32_t*)(iVar1 + 0xc) =
                                        *(int32_t*)(iVar1 + 0xc) + (int)(intptr_t)local_10;
                                    *(int32_t*)(iVar1 + 8) = iVar8;
                                }
                                uVar11 = uVar11 + 1;
                            } while (uVar11 < *(uint32_t*)((char*)self + 8));
                        }
                    }
                    else {
                        if (*(int32_t*)((char*)self + 8) != 0) {
                            do {
                                iVar1 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) + uVar11 * 4);
                                if (iVar7 == *(int32_t*)(iVar1 + 8)) {
                                    piVar9 = (int*)(iVar1 + 0xc);
                                    *piVar9 = *piVar9 + (int)(intptr_t)local_10;
                                }
                                uVar11 = uVar11 + 1;
                            } while (uVar11 < *(uint32_t*)((char*)self + 8));
                        }
                        *piVar10 = iVar8;
                    }
                }
                else {
                    iVar7 = ftol();
                    local_8 = 0;
                    uVar11 = iVar7 + *(int32_t*)(iVar8 + 0xc);
                    if (*(uint32_t*)((char*)self + 8) != 0) {
                        local_10 = *(int**)((char*)self + 0x14);
                        do {
                            if (((((local_8 != local_c) &&
                                   (iVar7 = *local_10,
                                    *(int32_t*)(iVar7 + 4) == *(int32_t*)(iVar8 + 4))) &&
                                  (*(int32_t*)(iVar7 + 8) == -1)) &&
                                 ((*(uint32_t*)(iVar7 + 0xc) == uVar11 &&
                                   (*(int32_t*)(iVar7 + 0x10) == *(int32_t*)(iVar8 + 0x10))))) &&
                                ((*(int32_t*)(iVar7 + 0x14) == *(int32_t*)(iVar8 + 0x14) &&
                                  (*(int32_t*)(iVar7 + 0x18) == *(int32_t*)(iVar8 + 0x18))))) {
                                if (!bVar5) {
                                    FUN_66254f(self);
                                    bVar5 = true;
                                }
                                *(uint32_t*)(iVar8 + 0x30) = local_8;
                                break;
                            }
                            local_8 = local_8 + 1;
                            local_10 = local_10 + 1;
                        } while (local_8 < *(uint32_t*)((char*)self + 8));
                    }
                    if (local_8 == *(uint32_t*)((char*)self + 8)) {
                        *(uint32_t*)(iVar8 + 8) = 0xffffffff;
                        *(uint32_t*)(iVar8 + 0xc) = uVar11;
                        if (*(uint32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x10) +
                                                     *(int32_t*)(iVar8 + 4) * 4) +
                                         8) <= uVar11) {
                            // call shape as observed: stack arguments not recovered
                            (*(uint32_t (*)())(uintptr_t)0x6626da)();
                            return 0x80004005;
                        }
                    }
                }
                bVar6 = true;
            }
LAB_00664120:
            local_c = local_c + 1;
        } while (local_c < *(uint32_t*)((char*)self + 8));
        if (bVar6) {
            if (bVar5) {
                FUN_662568(self);
            }
            return 0;
        }
    }
    return 1;
}

// 0x66414e — observed shape
// NEEDS_MANUAL: the decompiler mixes node pointers and node indices in the
// list-walk loops; the literal observed expressions are preserved below.
bool FUN_66414e(void* self)
{
    uint32_t* puVar1;
    int iVar2;
    int iVar3;
    uint8_t* pbVar4;
    uint32_t* puVar5;
    bool bVar6;
    uint64_t uVar7;
    bool bVar8;
    uint32_t uVar9;
    int iVar10;
    uint32_t uVar11;
    int iVar12;
    int iVar13;
    int iVar14;
    int* piVar15;
    uint32_t* puVar16;
    uint32_t uVar17;
    uint32_t* puVar18;
    bool bVar19;
    int local_34;
    uint32_t local_30;
    int local_28;
    uint32_t local_20;
    int* local_1c;
    uint32_t local_18;
    uint32_t local_14;
    uint32_t local_10;
    uint32_t local_c;

    FUN_00661fbd();
    local_30 = 0xffffffff;
    local_34 = -1;
    bVar6 = false;
    local_18 = 0;
    if (*(int32_t*)((char*)self + 0xc) != 0) {
        do {
            puVar1 = *(uint32_t**)(*(int32_t*)((char*)self + 0x18) + local_18 * 4);
            uVar9 = *puVar1;
            if ((((uVar9 & 0xfff00000) != 0) && (0xfffffff < (uVar9 & 0xf0000000))) &&
                ((uVar9 & 0xf0000000) < 0x40000001)) {
                uVar9 = puVar1[1] / (uVar9 & 0xfffff);
                local_c = 0;
                if (uVar9 != 0) {
                    do {
                        uVar11 = puVar1[3];
                        local_20 = 0;
                        local_14 = 0;
                        if (uVar11 != 0) {
                            do {
                                iVar14 = *(int32_t*)(puVar1[2] + (uVar11 * local_c + local_14) * 4);
                                iVar12 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                     *(int32_t*)(puVar1[4] + local_14 * 4) * 4);
                                if ((**(uint8_t**)(*(int32_t*)((char*)self + 0x14) + iVar14 * 4) & 1) !=
                                    0) {
                                    local_28 = *(int32_t*)(iVar12 + 0x18);
                                    for (iVar13 = *(int32_t*)(iVar12 + 0x14); iVar13 != -1;
                                         iVar13 = *(int32_t*)(iVar13 + 0x14)) {
                                        local_10 = 0;
                                        iVar10 = *(int32_t*)(*(int32_t*)((char*)self + 0x18) +
                                                             *(int32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                                                     iVar13 * 4) +
                                                                         0x48) *
                                                                 4);
                                        if (*(int32_t*)(iVar10 + 0xc) != 0) {
                                            local_1c = *(int**)(iVar10 + 0x10);
                                            do {
                                                if (*local_1c == iVar13) break;
                                                local_10 = local_10 + 1;
                                                local_1c = local_1c + 1;
                                            } while (local_10 < *(uint32_t*)(iVar10 + 0xc));
                                        }
                                        if (local_28 == 0) {
                                            iVar10 = FUN_0065f0a1(
                                                *(uint32_t*)(*(int32_t*)(iVar10 + 8) +
                                                             local_10 * 4),
                                                iVar14);
                                            if (iVar10 != 0) {
                                                *(uint32_t*)(iVar12 + 0x40) = 0;
                                                goto LAB_006642ac;
                                            }
                                        }
                                        else {
                                            iVar10 = FUN_0065f0a1(
                                                iVar14,
                                                *(uint32_t*)(*(int32_t*)(iVar10 + 8) +
                                                             local_10 * 4));
                                            if (iVar10 != 0) {
                                                *(uint32_t*)(iVar12 + 0x40) = 1;
LAB_006642ac:
                                                local_20 = local_20 + 1;
                                                break;
                                            }
                                        }
                                        iVar13 = *(int32_t*)(iVar13 * 4 +
                                                             *(int32_t*)((char*)self + 0x14));
                                        local_28 = *(int32_t*)(iVar13 + 0x18);
                                    }
                                }
                                local_14 = local_14 + 1;
                                uVar11 = puVar1[3];
                            } while (local_14 < uVar11);
                        }
                        uVar17 = 0;
                        uVar11 = puVar1[3];
                        if ((local_20 == uVar11) && (uVar11 != 0)) {
                            do {
                                iVar14 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                     *(int32_t*)(puVar1[2] +
                                                                 (uVar11 * local_c + uVar17) * 4) *
                                                         4);
                                iVar12 = *(int32_t*)(*(int32_t*)((char*)self + 0x10) +
                                                     *(int32_t*)(iVar14 + 4) * 4);
                                if (*(int32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                            *(int32_t*)(puVar1[4] + uVar17 * 4) * 4) +
                                                0x40) == 0) {
                                    if (((*(uint8_t*)(iVar12 + 5) & 1) == 0) ||
                                        (*(double*)(iVar14 + 0x20) != 0.0)) {
                                        uVar11 = local_34;
                                        if (local_34 == -1) {
                                            uVar11 = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x78),
                                                                 0, 0, 0);
                                            local_34 = (int)uVar11;
                                        }
                                        goto LAB_00664370;
                                    }
                                }
                                else if (((*(uint8_t*)(iVar12 + 5) & 1) == 0) ||
                                         (*(double*)(iVar14 + 0x20) != 1.0)) {
                                    uVar11 = local_30;
                                    if (local_30 == 0xffffffff) {
                                        uVar11 = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x78),
                                                             0, 0, 0x3ff0000000000000);
                                        local_30 = uVar11;
                                    }
LAB_00664370:
                                    *(uint32_t*)(puVar1[2] + (puVar1[3] * local_c + uVar17) * 4) =
                                        uVar11;
                                    bVar6 = true;
                                }
                                uVar11 = puVar1[3];
                                uVar17 = uVar17 + 1;
                            } while (uVar17 < uVar11);
                        }
                        local_c = local_c + 1;
                    } while (local_c < uVar9);
                }
            }
            local_18 = local_18 + 1;
        } while (local_18 < *(uint32_t*)((char*)self + 0xc));
    }
    bVar8 = false;
    FUN_66254f(self);
    local_1c = (int*)0x0;
    if (*(int32_t*)((char*)self + 0xc) != 0) {
        do {
            puVar1 = *(uint32_t**)(*(int32_t*)((char*)self + 0x18) +
                                   (int)(intptr_t)local_1c * 4);
            if ((*puVar1 & 0xfff00000) != 0) {
                local_14 = 0;
                if (puVar1[3] != 0) {
                    do {
                        iVar14 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                             *(int32_t*)(puVar1[4] + local_14 * 4) * 4);
                        local_18 = *(int32_t*)(iVar14 + 0x18);
                        iVar12 = *(int32_t*)(iVar14 + 0x14);
                        while (iVar12 != -1) {
                            pbVar4 = *(uint8_t**)(*(int32_t*)((char*)self + 0x14) + iVar12 * 4);
                            if ((*pbVar4 & 0x80) == 0) break;
                            bVar6 = *(double*)(pbVar4 + 0x20) == 0.0;
                            if (local_18 == 0) {
                                if (bVar6) goto LAB_0066458d;
LAB_00664431:
                                local_18 = 0;
                                iVar12 = -1;
                            }
                            else {
                                if (bVar6) goto LAB_00664431;
LAB_0066458d:
                                iVar12 = *(int32_t*)(iVar12 * 4 +
                                                     *(int32_t*)((char*)self + 0x14));
                                local_18 = *(int32_t*)(iVar12 + 0x18);
                                iVar12 = *(int32_t*)(iVar12 + 0x14);
                            }
                            bVar6 = true;
                        }
                        local_14 = local_14 + 1;
                        *(int32_t*)(iVar14 + 0x14) = iVar12;
                        *(uint32_t*)(iVar14 + 0x18) = local_18;
                    } while (local_14 < puVar1[3]);
                }
                uVar9 = *puVar1;
                uVar11 = uVar9 & 0xfff00000;
                if ((uVar11 == 0x10f00000) || (uVar11 == 0x11400000)) {
                    uVar9 = 0;
                    bVar19 = puVar1[3] == 0;
                    local_30 = 0;
                    local_18 = 0;
                    if (puVar1[3] != 0) {
                        do {
                            iVar14 = local_18 * 4;
                            pbVar4 = *(uint8_t**)(*(int32_t*)((char*)self + 0x14) +
                                                  *(int32_t*)(iVar14 + puVar1[4]) * 4);
                            puVar5 = *(uint32_t**)(*(int32_t*)((char*)self + 0x14) +
                                                   *(int32_t*)(iVar14 + puVar1[2]) * 4);
                            if (((*(uint8_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x10) +
                                                           puVar5[1] * 4) +
                                              5) &
                                  1) == 0) ||
                                (puVar5[2] != 0xffffffff)) {
                                if (((*puVar5 & 4) != 0) && ((*puVar5 & 8) != 0)) {
                                    *pbVar4 = *pbVar4 | 0x80;
                                    goto LAB_006647ce;
                                }
                                *pbVar4 = *pbVar4 & 0x7f;
                            }
                            else {
                                *pbVar4 = *pbVar4 | 0x80;
                                if (*(double*)(puVar5 + 8) == 0.0) {
LAB_006647ce:
                                    uVar7 = 0;
                                }
                                else {
                                    uVar7 = 0x3ff0000000000000;
                                }
                                *(uint64_t*)(pbVar4 + 0x20) = uVar7;
                            }
                            if ((*pbVar4 & 0x80) == 0) {
                                *(uint32_t*)(uVar9 * 4 + puVar1[4]) =
                                    *(uint32_t*)(iVar14 + puVar1[4]);
                                *(uint32_t*)(uVar9 * 4 + puVar1[2]) =
                                    *(uint32_t*)(iVar14 + puVar1[2]);
                                uVar9 = local_30 + 1;
                                local_30 = uVar9;
                            }
                            local_18 = local_18 + 1;
                        } while (local_18 < puVar1[3]);
                        bVar19 = uVar9 == puVar1[3];
                    }
                    if (!bVar19) {
                        uVar11 = -(uint32_t)(uVar9 != 0) & (uVar9 & 0xfffff | 0x10f00000);
                        puVar1[1] = uVar9;
                        puVar1[3] = uVar9;
LAB_0066483e:
                        *puVar1 = uVar11;
LAB_00664840:
                        bVar6 = true;
                    }
                }
                else if ((uVar11 == 0x20700000) || (uVar11 == 0x20800000)) {
                    uVar9 = puVar1[1] / (uVar9 & 0xfffff);
                    local_10 = 0;
                    local_c = 0;
                    if (puVar1[3] != 0) {
                        do {
                            iVar14 = *(int32_t*)((char*)self + 0x14);
                            iVar12 = *(int32_t*)(local_c * 4 + puVar1[4]);
                            iVar13 = *(int32_t*)(iVar14 + iVar12 * 4);
                            if ((*(int32_t*)(iVar13 + 0x14) != -1) ||
                                (*(int32_t*)(iVar13 + 0x18) != 0)) {
                                iVar10 = *(int32_t*)(local_c * 4 + puVar1[2]);
                                iVar2 = *(int32_t*)(puVar1[2] + (puVar1[3] + local_c) * 4);
                                iVar3 = *(int32_t*)(iVar14 + iVar10 * 4);
                                if ((*(int32_t*)(iVar3 + 0x14) == -1) &&
                                    (*(int32_t*)(iVar3 + 0x18) == 0)) {
                                    *(uint32_t*)(*(int32_t*)(iVar14 + iVar2 * 4) + 4) =
                                        *(uint32_t*)((char*)self + 0x88);
                                    *(int32_t*)(iVar13 + 0x30) = iVar2;
                                }
                                else {
                                    iVar14 = *(int32_t*)(iVar14 + iVar2 * 4);
                                    if ((*(int32_t*)(iVar14 + 0x14) != -1) ||
                                        (*(int32_t*)(iVar14 + 0x18) != 0)) {
                                        local_18 = 0;
                                        *(int32_t*)(puVar1[4] + local_10 * 4) = iVar12;
                                        if (uVar9 != 0) {
                                            do {
                                                iVar14 = puVar1[3] * local_18;
                                                local_18 = local_18 + 1;
                                                *(uint32_t*)(puVar1[2] +
                                                             (iVar14 + local_10) * 4) =
                                                    *(uint32_t*)(puVar1[2] +
                                                                 (local_c + iVar14) * 4);
                                            } while (local_18 < uVar9);
                                        }
                                        local_10 = local_10 + 1;
                                        goto LAB_006646e3;
                                    }
                                    *(uint32_t*)(iVar3 + 4) = *(uint32_t*)((char*)self + 0x88);
                                    *(int32_t*)(iVar13 + 0x30) = iVar10;
                                }
                                bVar8 = true;
                            }
LAB_006646e3:
                            local_c = local_c + 1;
                        } while (local_c < puVar1[3]);
                    }
                    if (local_10 != puVar1[3]) {
                        local_18 = 0;
                        if (uVar9 != 0) {
                            local_20 = 0;
                            do {
                                puVar18 = (uint32_t*)(local_20 + puVar1[2]);
                                local_20 = local_20 + local_10 * 4;
                                puVar16 = (uint32_t*)(puVar1[2] + puVar1[3] * local_18 * 4);
                                for (uVar11 = local_10 & 0x3fffffff; uVar11 != 0;
                                     uVar11 = uVar11 - 1) {
                                    *puVar18 = *puVar16;
                                    puVar16 = puVar16 + 1;
                                    puVar18 = puVar18 + 1;
                                }
                                local_18 = local_18 + 1;
                                for (iVar14 = 0; iVar14 != 0; iVar14 = iVar14 + -1) {
                                    *(uint8_t*)puVar18 = *(uint8_t*)puVar16;
                                    puVar16 = (uint32_t*)((int)(intptr_t)puVar16 + 1);
                                    puVar18 = (uint32_t*)((int)(intptr_t)puVar18 + 1);
                                }
                            } while (local_18 < uVar9);
                        }
                        if (local_10 == 0) {
                            uVar11 = 0;
                        }
                        else {
                            uVar11 = (*puVar1 ^ local_10) & 0xfffff ^ *puVar1;
                        }
                        puVar1[3] = local_10;
                        puVar1[1] = uVar9 * local_10;
                        goto LAB_0066483e;
                    }
                }
                else if (((uVar9 & 0xf0000000) < 0x10000000) ||
                         (0x40000000 < (uVar9 & 0xf0000000))) {
                    uVar9 = puVar1[3];
                    if (uVar9 != 0) {
                        local_20 = 0;
                        if (uVar9 != 0) {
                            piVar15 = (int*)puVar1[4];
                            do {
                                iVar14 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                     *piVar15 * 4);
                                if ((*(int32_t*)(iVar14 + 0x14) != -1) ||
                                    (*(int32_t*)(iVar14 + 0x18) != 0)) {
                                    local_20 = local_20 + 1;
                                }
                                piVar15 = piVar15 + 1;
                                uVar9 = uVar9 - 1;
                            } while (uVar9 != 0);
                            if (local_20 != 0) goto LAB_00664847;
                        }
                        uVar11 = 0;
                        puVar1[1] = 0;
                        puVar1[3] = 0;
                        goto LAB_0066483e;
                    }
                }
                else {
                    uVar9 = puVar1[1] / (uVar9 & 0xfffff);
                    local_c = 0;
                    local_10 = 0;
                    if (puVar1[3] != 0) {
                        do {
                            iVar14 = *(int32_t*)(puVar1[4] + local_10 * 4);
                            iVar12 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) + iVar14 * 4);
                            if ((*(int32_t*)(iVar12 + 0x14) != -1) ||
                                (*(int32_t*)(iVar12 + 0x18) != 0)) {
                                local_18 = 0;
                                *(int32_t*)(puVar1[4] + local_c * 4) = iVar14;
                                if (uVar9 != 0) {
                                    do {
                                        iVar14 = puVar1[3] * local_18;
                                        local_18 = local_18 + 1;
                                        *(uint32_t*)(puVar1[2] + (iVar14 + local_c) * 4) =
                                            *(uint32_t*)(puVar1[2] + (local_10 + iVar14) * 4);
                                    } while (local_18 < uVar9);
                                }
                                local_c = local_c + 1;
                            }
                            local_10 = local_10 + 1;
                        } while (local_10 < puVar1[3]);
                    }
                    if (local_c != puVar1[3]) {
                        local_18 = 0;
                        if (uVar9 != 0) {
                            local_20 = 0;
                            do {
                                puVar16 = (uint32_t*)(puVar1[2] + puVar1[3] * local_18 * 4);
                                puVar18 = (uint32_t*)(local_20 + puVar1[2]);
                                for (uVar11 = local_c & 0x3fffffff; uVar11 != 0;
                                     uVar11 = uVar11 - 1) {
                                    *puVar18 = *puVar16;
                                    puVar16 = puVar16 + 1;
                                    puVar18 = puVar18 + 1;
                                }
                                local_18 = local_18 + 1;
                                for (iVar14 = 0; iVar14 != 0; iVar14 = iVar14 + -1) {
                                    *(uint8_t*)puVar18 = *(uint8_t*)puVar16;
                                    puVar16 = (uint32_t*)((int)(intptr_t)puVar16 + 1);
                                    puVar18 = (uint32_t*)((int)(intptr_t)puVar18 + 1);
                                }
                                local_20 = local_20 + local_c * 4;
                            } while (local_18 < uVar9);
                        }
                        if (local_c == 0) {
                            uVar11 = 0;
                        }
                        else {
                            uVar11 = (*puVar1 ^ local_c) & 0xfffff ^ *puVar1;
                        }
                        *puVar1 = uVar11;
                        puVar1[3] = local_c;
                        puVar1[1] = uVar9 * local_c;
                        goto LAB_00664840;
                    }
                }
            }
LAB_00664847:
            local_1c = (int*)((int)(intptr_t)local_1c + 1);
        } while ((uint32_t)(intptr_t)local_1c < *(uint32_t*)((char*)self + 0xc));
        if (bVar8) {
            FUN_662568(self);
        }
    }
    return !bVar6;
}

// 0x664870 — observed shape
uint32_t FUN_664870(void* self)
{
    uint32_t* puVar1;
    int iVar2;
    uint32_t uVar3;
    uint32_t* puVar4;
    uint32_t* puVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    bool bVar8;
    int iVar9;
    int* piVar10;
    uint32_t uVar11;
    int iVar12;
    uint32_t uVar13;
    uint32_t uVar14;
    int* local_24;
    int local_1c;
    uint32_t local_18;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;

    if ((*(uint8_t*)((char*)self + 0x6c) & 1) == 0) {
        bVar8 = false;
        FUN_00661fbd();
        iVar9 = *(int32_t*)((char*)self + 0xc);
        if (iVar9 != 0) {
            do {
                iVar9 = iVar9 + -1;
                puVar1 = *(uint32_t**)(*(int32_t*)((char*)self + 0x18) + iVar9 * 4);
                if (((*puVar1 & 0xfff00000) == 0x10000000) ||
                    ((*puVar1 & 0xfff00000) == 0x20700000)) {
                    local_c = 0;
                    if (puVar1[3] != 0) {
                        piVar10 = (int*)puVar1[4];
                        do {
                            if ((*(uint8_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x10) +
                                                         *(int32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                                                 *piVar10 * 4) +
                                                                     4) *
                                                         4) +
                                             4) &
                                 0x20) == 0) {
                                break;
                            }
                            local_c = local_c + 1;
                            piVar10 = piVar10 + 1;
                        } while (local_c < puVar1[3]);
                    }
                    if (puVar1[3] <= local_c) {
                        local_c = 0;
                        if (puVar1[1] != 0) {
                            piVar10 = (int*)puVar1[2];
                            do {
                                if ((*(uint8_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x10) +
                                                             *(int32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                                                     *piVar10 * 4) +
                                                                         4) *
                                                             4) +
                                                 4) &
                                     2) == 0) {
                                    break;
                                }
                                local_c = local_c + 1;
                                piVar10 = piVar10 + 1;
                            } while (local_c < puVar1[1]);
                        }
                        if (puVar1[1] <= local_c) {
                            uVar13 = *puVar1 & 0xfffff;
                            uVar11 = puVar1[1] / uVar13;
                            local_10 = 0;
                            if (uVar11 != 0) {
                                local_1c = 0;
                                do {
                                    local_c = 0;
                                    if (uVar13 != 0) {
                                        local_18 = local_1c;
                                        do {
                                            iVar2 = *(int32_t*)(*(int32_t*)((char*)self + 0x18) +
                                                               *(int32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                                                       *(int32_t*)(local_18 + puVar1[2]) *
                                                                                           4) +
                                                                           0x48) *
                                                               4);
                                            iVar12 = FUN_0065ccac();
                                            local_8 = 0;
                                            uVar3 = *(uint32_t*)(iVar2 + 0xc);
                                            if (uVar3 != 0) {
                                                local_24 = *(int**)(iVar2 + 0x10);
                                                do {
                                                    iVar2 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                                        *local_24 * 4);
                                                    if (((1 < *(uint32_t*)(iVar2 + 0x5c)) ||
                                                         (*(int32_t*)(iVar2 + 0x54) !=
                                                          iVar9)) ||
                                                        ((iVar12 != 0 &&
                                                          (local_8 !=
                                                           *(uint32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x14) +
                                                                                    *(int32_t*)(puVar1[4] +
                                                                                                local_c * 4) *
                                                                                        4) +
                                                                        0x10))))) {
                                                        break;
                                                    }
                                                    local_8 = local_8 + 1;
                                                    local_24 = local_24 + 1;
                                                } while (local_8 < uVar3);
                                            }
                                            if (local_8 < uVar3) break;
                                            local_c = local_c + 1;
                                            local_18 = local_18 + 4;
                                        } while (local_c < uVar13);
                                        if (local_c < uVar13) break;
                                    }
                                    local_10 = local_10 + 1;
                                    local_1c = local_1c + uVar13 * 4;
                                } while (local_10 < uVar11);
                                if (local_10 < uVar11) goto LAB_00664b0b;
                            }
                            local_10 = 0;
                            if (puVar1[3] != 0) {
                                do {
                                    local_1c = local_10 * 4;
                                    puVar4 = *(uint32_t**)(*(int32_t*)((char*)self + 0x14) +
                                                           *(int32_t*)(local_1c + puVar1[4]) * 4);
                                    if (uVar11 != 0) {
                                        local_18 = uVar11;
                                        do {
                                            puVar5 = *(uint32_t**)(*(int32_t*)((char*)self + 0x14) +
                                                                   *(int32_t*)(local_1c + puVar1[2]) * 4);
                                            uVar3 = *puVar5;
                                            uVar6 = *puVar4;
                                            uVar7 = *puVar5;
                                            *puVar5 = uVar7 & 0xf1ffffff;
                                            uVar14 = uVar6 & 0xe000000;
                                            if ((uVar6 & 0xe000000) <= (uVar3 & 0xe000000)) {
                                                uVar14 = uVar3 & 0xe000000;
                                            }
                                            *puVar5 = uVar7 & 0xf1ffffff | uVar14;
                                            puVar5[1] = puVar4[1];
                                            puVar5[2] = puVar4[2];
                                            puVar5[3] = puVar4[3];
                                            puVar5[4] = puVar4[4];
                                            if (puVar5[0x18] == 0) {
                                                puVar5[0x18] = puVar4[0x18];
                                                puVar5[0x19] = puVar4[0x19];
                                            }
                                            puVar5[0x1a] = puVar4[0x1a];
                                            puVar5[0x1b] = puVar4[0x1b];
                                            puVar5[0x1c] = puVar4[0x1c];
                                            local_1c = local_1c + uVar13 * 4;
                                            local_18 = local_18 - 1;
                                        } while (local_18 != 0);
                                    }
                                    local_10 = local_10 + 1;
                                    puVar4[1] = *(uint32_t*)((char*)self + 0x74);
                                } while (local_10 < puVar1[3]);
                            }
                            bVar8 = true;
                            *puVar1 = 0;
                            puVar1[1] = 0;
                            puVar1[3] = 0;
                        }
                    }
                }
LAB_00664b0b:
            } while (iVar9 != 0);
            if (bVar8) {
                return 0;
            }
        }
    }
    return 1;
}
