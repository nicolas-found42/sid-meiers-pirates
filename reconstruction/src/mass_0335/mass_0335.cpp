#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---------------------------------------------------------------------------
// External helpers and globals referenced by the translated listings.
// ---------------------------------------------------------------------------
extern void FUN_006626da(...);
extern void FUN_0066275f(...);

extern uint32_t* FUN_00533c78(uint32_t param_1);
extern void operator_delete(void* param_1);

extern int FUN_00614343(void);
extern int FUN_0065cc1a(void);
extern int FUN_0065cc50(void);
extern int FUN_0065ccac(void);
extern int FUN_0065cd3a(void);
extern int FUN_0065cea4(void);
extern int FUN_0065d0b4(void);
extern int FUN_0065d0ff(uint32_t param_1, int param_2, int param_3, int param_4);
extern int FUN_0065d35e(void);
extern int FUN_0065d501(void);
extern int FUN_0065d5bd(void);
extern int FUN_0065d8c2(void);
extern int FUN_0065d9d5(uint32_t param_1, uint32_t param_2, uint32_t param_3, int param_4);
extern uint32_t FUN_0065da35(uint32_t param_1, uint32_t param_2, uint32_t param_3);
extern int FUN_0065dadc(int param_1);
extern uint32_t FUN_0065db7d(uint32_t* param_1);
extern void FUN_0065dd0b(void* param_1, void* param_2, int param_3);
extern void FUN_0065e1b9(int (*param_1)(const void*, const void*), int* param_2,
                          uint32_t param_3, void* param_4);
extern int FUN_00661fbd(void);
extern int FUN_00694868(const void* param_1, const void* param_2);

extern "C" int isalnum(int c);
extern "C" int isalpha(int c);
extern "C" int isdigit(int c);
extern "C" int tolower(int c);
extern "C" int atoi(const char* s);
extern "C" int _stricmp(const char* a, const char* b);
extern "C" char* strncpy(char* dst, const char* src, size_t n);

extern const char DAT_006f5896;

// ---------------------------------------------------------------------------
// 0x6948a1 — comparator over two node names / ids / payload words.
// The two string comparisons are the provider's inlined unsigned strcmp.
// ---------------------------------------------------------------------------
// 0x6948a1 — observed shape
uint32_t FUN_6948a1(int param_1, int param_2, uint8_t* param_3)
{
    uint8_t bVar1;
    int iVar2;
    int iVar3;
    int iVar6;
    uint32_t uVar4;
    uint8_t* pbVar5;
    uint8_t* pbVar7;
    uint8_t* pbVar8;
    bool bVar9;

    iVar2 = *(int*)(*(int*)(param_3 + 0x14) + param_1 * 4);
    iVar3 = *(int*)(*(int*)(param_3 + 0x14) + param_2 * 4);
    uVar4 = *(uint32_t*)(iVar2 + 0x60);
    pbVar5 = *(uint8_t**)(uVar4 + 0x20);
    if (pbVar5 == nullptr) {
        pbVar5 = (uint8_t*)&DAT_006f5896;
    }
    pbVar7 = *(uint8_t**)(*(int*)(iVar3 + 0x60) + 0x20);
    pbVar8 = (uint8_t*)&DAT_006f5896;
    if (pbVar7 != nullptr) {
        pbVar8 = pbVar7;
    }
    do {
        bVar1 = *pbVar5;
        bVar9 = bVar1 < *pbVar8;
        if (bVar1 != *pbVar8) {
        LAB_006948fd:
            iVar6 = (1 - (uint32_t)bVar9) - (uint32_t)(bVar9 != 0);
            goto LAB_00694902;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar5[1];
        bVar9 = bVar1 < pbVar8[1];
        if (bVar1 != pbVar8[1]) goto LAB_006948fd;
        pbVar5 = pbVar5 + 2;
        pbVar8 = pbVar8 + 2;
    } while (bVar1 != 0);
    iVar6 = 0;
LAB_00694902:
    if (iVar6 < 1) {
        if (-1 < iVar6) {
            pbVar5 = *(uint8_t**)(*(int*)(*(int*)(iVar3 + 0x60) + 0x14) + 0x18);
            pbVar7 = *(uint8_t**)(*(int*)(uVar4 + 0x14) + 0x18);
            do {
                bVar1 = *pbVar7;
                bVar9 = bVar1 < *pbVar5;
                if (bVar1 != *pbVar5) {
                LAB_00694946:
                    iVar6 = (1 - (uint32_t)bVar9) - (uint32_t)(bVar9 != 0);
                    goto LAB_0069494b;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar7[1];
                bVar9 = bVar1 < pbVar5[1];
                if (bVar1 != pbVar5[1]) goto LAB_00694946;
                pbVar7 = pbVar7 + 2;
                pbVar5 = pbVar5 + 2;
            } while (bVar1 != 0);
            iVar6 = 0;
        LAB_0069494b:
            if (0 < iVar6) goto LAB_00694906;
            if (-1 < iVar6) {
                if (*(uint32_t*)(iVar3 + 0x60) < uVar4) goto LAB_00694906;
                if (*(uint32_t*)(iVar3 + 0x60) <= uVar4) {
                    if (*(uint32_t*)(iVar3 + 0x74) <= *(uint32_t*)(iVar2 + 0x74)) {
                        if (*(uint32_t*)(iVar3 + 0x74) < *(uint32_t*)(iVar2 + 0x74))
                            goto LAB_00694906;
                        if (*(uint32_t*)(iVar3 + 0x10) <= *(uint32_t*)(iVar2 + 0x10)) {
                            return (uint32_t)(*(uint32_t*)(iVar3 + 0x10) <
                                              *(uint32_t*)(iVar2 + 0x10));
                        }
                    }
                }
            }
        }
        uVar4 = 0xffffffff;
    }
    else {
    LAB_00694906:
        uVar4 = 1;
    }
    return uVar4;
}

// ---------------------------------------------------------------------------
// 0x69497e — packed id compare key: shifted term ORed with masked word.
// ---------------------------------------------------------------------------
// 0x69497e — observed shape
uint32_t FUN_69497e(void* self, uint32_t param_1, int param_2)
{
    return (uint32_t)param_2 << ((uint8_t)*(uint32_t*)((char*)self + 0xec) & 0x1f) |
           *(uint32_t*)((char*)self + 0xe4) & param_1;
}

// ---------------------------------------------------------------------------
// 0x6949cb — operand/slot matching against a pattern word.
// ---------------------------------------------------------------------------
// 0x6949cb — observed shape
uint32_t FUN_6949cb(void* self, uint32_t* param_1, int param_2, uint32_t param_3,
                    uint32_t* param_4, uint32_t* param_5, int param_6, int param_7)
{
    uint32_t uVar1;
    int iVar2;
    int iVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    uint32_t auStack_44[4];
    int local_34[5];
    int local_20;
    int local_1c;
    int local_18;
    uint32_t local_14;
    int local_10;
    int local_c;
    uint32_t* local_8;

    uVar4 = *param_1;
    local_34[0] = 0;
    local_34[1] = 0;
    local_34[2] = 0;
    local_34[3] = 0;
    local_34[4] = (int)uVar4;
    if (((uVar4 & 0xfff00000) == 0x50000000) || ((uVar4 & 0xfff00000) == 0x70800000)) {
        uVar5 = 0;
        uVar1 = 0;
        do {
            if (uVar1 < (uVar4 & 0xfffff)) {
                param_5[uVar1] = uVar1;
            }
            else {
                param_5[uVar1] = 0xff;
            }
            uVar1 = uVar1 + 1;
        } while (uVar1 < 4);
        if (param_3 != 0) {
            do {
                iVar2 = *(int*)(param_2 + uVar5 * 4);
                iVar3 = *(int*)(*(int*)((char*)self + 0x14) + iVar2 * 4);
                if ((iVar2 != *(int*)(uintptr_t)param_1[4]) ||
                    (*(int*)(iVar3 + 0x3c) != param_6)) {
                    if (*(int*)(iVar3 + 0x38) != *(int*)(uintptr_t)param_1[4]) {
                        return 1;
                    }
                    if (*(int*)(iVar3 + 0x3c) != param_6) {
                        return 1;
                    }
                }
                uVar5 = uVar5 + 1;
            } while (uVar5 < param_3);
        }
    }
    else {
        local_14 = 0;
        if (param_3 != 0) {
            local_18 = *(int*)((char*)self + 0x14);
            iVar2 = (int)((intptr_t)param_2 - (intptr_t)param_4);
            local_8 = param_4;
            local_20 = iVar2;
            do {
                local_10 = 0;
                local_c = *(int*)(local_18 + *(int*)(iVar2 + (int)(intptr_t)local_8) * 4);
                uVar1 = local_14;
                if ((param_7 == 0) || (uVar1 = *local_8, uVar1 < 4)) {
                    uVar4 = 0;
                    if (param_1[3] == 0) {
                        return 1;
                    }
                    local_1c = (int)(uint32_t)(param_1[4] - (uint32_t)(uintptr_t)local_34);
                    do {
                        if (((*(int*)(uVar1 * 4 + (intptr_t)param_2) ==
                              *(int*)((intptr_t)local_1c +
                                      (intptr_t)(local_34 + uVar4))) &&
                             (*(int*)(local_c + 0x3c) == param_6)) ||
                            ((*(int*)(local_c + 0x38) ==
                              *(int*)((uintptr_t)param_1[4] + uVar4 * 4) &&
                              (*(int*)(local_c + 0x3c) == param_6)))) {
                            local_10 = 1;
                            auStack_44[uVar1] = uVar4;
                            local_34[uVar4] = 1;
                        }
                        uVar4 = uVar4 + 1;
                    } while (uVar4 < param_1[3]);
                    if (local_10 == 0) {
                        return 1;
                    }
                    iVar2 = local_20;
                    uVar4 = (uint32_t)local_34[4];
                }
                local_8 = local_8 + 1;
                local_14 = local_14 + 1;
            } while (local_14 < param_3);
        }
        if (param_7 == 0) {
            uVar1 = 0;
            if ((uVar4 & 0xfffff) != 0) {
                do {
                    if (local_34[uVar1] == 0) {
                        return 1;
                    }
                    uVar1 = uVar1 + 1;
                } while (uVar1 < (uVar4 & 0xfffff));
            }
        }
        iVar3 = (int)((intptr_t)param_4 - (intptr_t)param_5);
        iVar2 = 4;
        do {
            uVar4 = *(uint32_t*)((intptr_t)param_5 + iVar3);
            if (uVar4 < 4) {
                *param_5 = auStack_44[uVar4];
            }
            else {
                *param_5 = 0xff;
            }
            param_5 = param_5 + 1;
            iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x694fde — advance an index over a run of compatible nodes.
// ---------------------------------------------------------------------------
// 0x694fde — observed shape
uint32_t FUN_694fde(void* self, int* param_1)
{
    int iVar1;
    uint32_t uVar2;
    int iVar3;
    uint32_t uVar4;
    int* piVar5;

    uVar4 = (uint32_t)*param_1 + 1;
    piVar5 = (int*)(*(int*)((char*)self + 0x14) + uVar4 * 4);
    iVar1 = *piVar5;
    if (uVar4 < *(uint32_t*)((char*)self + 8)) {
        while (true) {
            uVar2 = *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                          *(int*)(*piVar5 + 4) * 4) +
                                 4);
            if ((((uVar2 & 0x10) == 0) || ((uVar2 & 0x200) != 0)) &&
                ((uVar2 & 0x20) == 0)) break;
            iVar3 = *(int*)(*piVar5 + 0x68);
            if ((*(int*)(*(int*)(iVar1 + 0x68) + 0x24) != *(int*)(iVar3 + 0x24)) ||
                (*(int*)(*(int*)(iVar1 + 0x68) + 0x20) != *(int*)(iVar3 + 0x20))) break;
            uVar4 = uVar4 + 1;
            piVar5 = piVar5 + 1;
            if (*(uint32_t*)((char*)self + 8) <= uVar4) break;
        }
    }
    *param_1 = (int)uVar4 - 1;
    return 0;
}

// ---------------------------------------------------------------------------
// 0x694b7c — recursive pattern/operand matcher over the instruction table.
// The receiver register (in_ECX) is the parser context; the recursive call
// site does not expose it, so the enclosing object is forwarded.
// ---------------------------------------------------------------------------
// 0x694b7c — observed shape
int FUN_694b7c(void* self, uint32_t* param_1, int* param_2, int* param_3, uint32_t* param_4,
               uint8_t* param_5, uint32_t* param_6, uint32_t param_7, int param_8)
{
    uint32_t uVar1;
    int iVar2;
    int iVar3;
    uint32_t* puVar4;
    int iVar5;
    uint32_t uVar6;
    int iVar11;
    uint32_t uVar8;
    uint32_t uVar9;
    int* piVar7;
    int* piVar10;
    int local_1c8[40];
    int local_128[40];
    uint8_t local_88[16];
    int local_78[16];
    uint32_t local_38;
    int local_34;
    uint32_t local_30;
    uint32_t local_2c;
    uint32_t local_28;
    uint32_t local_24;
    uint32_t local_20;
    uint32_t* local_1c;
    int local_18;
    uint32_t local_14;
    int local_10;
    uint32_t local_c;
    uint32_t local_8;

    local_20 = *param_1 & 0xfffff;
    local_10 = 0;
    local_14 = 0;
    if ((param_7 < local_20) && (param_8 == 0)) {
        local_10 = 1;
    }
    else if ((*param_1 & 0xfff00000) == (uint32_t)param_2[1]) {
        local_30 = 1;
        if ((*param_2 == 0) && (param_8 != 0)) {
            local_30 = 2;
        }
        local_2c = 0;
        local_18 = (int)(intptr_t)self;
        if (local_30 == 0) {
        LAB_00694f79:
            piVar7 = local_78;
            piVar10 = param_3;
            for (uVar9 = local_14 & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
                *piVar10 = *piVar7;
                piVar7 = piVar7 + 1;
                piVar10 = piVar10 + 1;
            }
            for (iVar11 = 0; iVar11 != 0; iVar11 = iVar11 + -1) {
                *(char*)piVar10 = (char)*piVar7;
                piVar7 = (int*)((intptr_t)piVar7 + 1);
                piVar10 = (int*)((intptr_t)piVar10 + 1);
            }
            param_3[local_14] = (int)(intptr_t)param_1;
            *param_4 = local_14 + 1;
            uVar9 = 0;
            do {
                iVar11 = *(int*)((intptr_t)local_128 + uVar9);
                if ((iVar11 != -1) ||
                    (iVar11 = *(int*)((intptr_t)local_1c8 + uVar9), iVar11 != -1)) {
                    *(int*)(param_5 + uVar9) = iVar11;
                }
                uVar9 = uVar9 + 4;
            } while (uVar9 < 0xa0);
            local_10 = 0;
        }
        else {
            do {
                local_24 = 0;
                if (param_2[7] != -1) {
                    do {
                        iVar11 = 0x28;
                        uVar9 = *param_4;
                        piVar7 = param_3;
                        piVar10 = local_78;
                        for (uVar6 = uVar9; uVar6 != 0; uVar6 = uVar6 - 1) {
                            *piVar10 = *piVar7;
                            piVar7 = piVar7 + 1;
                            piVar10 = piVar10 + 1;
                        }
                        piVar7 = local_128;
                        for (; iVar11 != 0; iVar11 = iVar11 + -1) {
                            *piVar7 = -1;
                            piVar7 = piVar7 + 1;
                        }
                        piVar7 = local_1c8;
                        for (iVar11 = 0x28; iVar11 != 0; iVar11 = iVar11 + -1) {
                            *piVar7 = -1;
                            piVar7 = piVar7 + 1;
                        }
                        local_14 = uVar9;
                        local_10 = 0;
                        local_c = 0;
                        if (param_2[2] != 0) {
                            local_8 = 0;
                            do {
                                uVar9 = local_8;
                                if (local_24 == 0) {
                                    uVar6 = local_c;
                                }
                                else {
                                    uVar6 = 1 - local_c;
                                }
                                if (3 < *param_6) {
                                    return 1;
                                }
                                uVar1 = param_1[2];
                                iVar11 = *(int*)(*(int*)(local_18 + 0x14) +
                                                 *(int*)((uintptr_t)uVar1 +
                                                         (*param_6 + local_8) * 4) *
                                                     4);
                                uVar6 = (uint32_t)param_2[uVar6 + 3];
                                if (uVar6 < 0x10) {
                                    iVar5 = *(int*)(iVar11 + 0x48);
                                    if (iVar5 != -1) {
                                        iVar2 = *param_2;
                                        iVar3 = *(int*)(local_18 + 0x18);
                                        iVar5 = FUN_6949cb(
                                            self,
                                            (uint32_t*)(uintptr_t)*(uint32_t*)(iVar3 + iVar5 * 4),
                                            (uint32_t*)(uintptr_t)(uVar1 + local_8 * 4),
                                            (int)local_20, param_6,
                                            (uint32_t*)(uintptr_t)local_88,
                                            (param_2 + (uVar6 - (uint32_t)iVar2) * 8)[6],
                                            param_8);
                                        if (iVar5 == 0) {
                                            local_10 = FUN_694b7c(
                                                self,
                                                (uint32_t*)(uintptr_t)*(uint32_t*)(
                                                    iVar3 + *(int*)(iVar11 + 0x48) * 4),
                                                param_2 + (uVar6 - (uint32_t)iVar2) * 8,
                                                local_78, &local_14, (uint8_t*)local_1c8,
                                                (uint32_t*)(uintptr_t)local_88, param_7,
                                                param_8);
                                            goto LAB_00694d1e;
                                        }
                                    }
                                    local_10 = 1;
                                    break;
                                }
                                uVar8 = 0;
                                piVar7 = local_128 + (uVar6 - 0x10) * 4;
                                do {
                                    if (param_6[uVar8] < local_20) {
                                        *piVar7 = *(int*)((uintptr_t)uVar1 +
                                                         (param_6[uVar8] + uVar9) * 4);
                                    }
                                    else {
                                        *piVar7 = -1;
                                    }
                                    uVar8 = uVar8 + 1;
                                    piVar7 = piVar7 + 1;
                                } while (uVar8 < 4);
                            LAB_00694d1e:
                                if (local_10 == 1) break;
                                local_c = local_c + 1;
                                local_8 = local_8 + local_20;
                            } while (local_c < (uint32_t)param_2[2]);
                        }
                        local_c = 0;
                        if (param_2[2] != 0) {
                            local_1c = (uint32_t*)0x0;
                            do {
                                if (local_24 == 0) {
                                    uVar9 = local_c;
                                }
                                else {
                                    uVar9 = 1 - local_c;
                                }
                                if ((0xf < (uint32_t)param_2[uVar9 + 3]) &&
                                    (local_28 = 0, local_14 != 0)) {
                                    do {
                                        uVar9 = 0;
                                        if (local_20 != 0) {
                                            uVar6 = *(uint32_t*)((intptr_t)local_78[local_28] +
                                                                0xc);
                                            do {
                                                local_8 = 0;
                                                if (uVar6 != 0) {
                                                    piVar7 = *(int**)((intptr_t)local_78[local_28] +
                                                                     0x10);
                                                    do {
                                                        if (*(int*)((uintptr_t)param_1[2] +
                                                                    ((int)(intptr_t)local_1c +
                                                                     uVar9) * 4) == *piVar7) {
                                                            local_10 = 1;
                                                            goto LAB_00694dc2;
                                                        }
                                                        local_8 = local_8 + 1;
                                                        piVar7 = piVar7 + 1;
                                                    } while (local_8 < uVar6);
                                                }
                                                uVar9 = uVar9 + 1;
                                            } while (uVar9 < local_20);
                                        }
                                    LAB_00694dc2:
                                        local_28 = local_28 + 1;
                                    } while (local_28 < local_14);
                                }
                                local_c = local_c + 1;
                                local_1c = (uint32_t*)((intptr_t)local_1c + local_20);
                            } while (local_c < (uint32_t)param_2[2]);
                        }
                        if (local_10 == 0) {
                            if ((local_2c != 0) || (*param_2 != 0)) goto LAB_00694f79;
                            local_c = 0;
                            if (local_14 != 0) {
                                do {
                                    local_38 =
                                        *(uint32_t*)((intptr_t)local_78[local_c] + 0xc);
                                    local_8 = 0;
                                    if (local_38 != 0) {
                                        do {
                                            if (*(int*)(local_18 + 0xc) != 0) {
                                                local_1c = *(uint32_t**)(local_18 + 0x18);
                                                local_34 = *(int*)(local_18 + 0xc);
                                                do {
                                                    puVar4 = (uint32_t*)(uintptr_t)*local_1c;
                                                    if ((puVar4 != nullptr) && (*puVar4 != 0)) {
                                                        uVar9 = puVar4[1];
                                                        local_28 = 0;
                                                        if (uVar9 != 0) {
                                                            iVar11 = *(int*)(*(int*)(
                                                                                (intptr_t)local_78[local_c] +
                                                                                0x10) +
                                                                            local_8 * 4);
                                                            piVar7 = (int*)(uintptr_t)puVar4[2];
                                                            do {
                                                                if ((*piVar7 == iVar11) ||
                                                                    (*(int*)(*(int*)(*(int*)(local_18 +
                                                                                              0x14) +
                                                                                     *piVar7 * 4) +
                                                                              0x38) == iVar11)) {
                                                                    local_28 = 1;
                                                                }
                                                                piVar7 = piVar7 + 1;
                                                                uVar9 = uVar9 - 1;
                                                            } while (uVar9 != 0);
                                                        }
                                                        if (puVar4 == param_1) {
                                                            uVar9 = 0;
                                                        }
                                                        else {
                                                            uVar9 = local_28;
                                                        }
                                                        if (uVar9 != 0) {
                                                            uVar6 = 0;
                                                            do {
                                                                if (puVar4 == (uint32_t*)(
                                                                                  intptr_t)
                                                                                  local_78[uVar6]) {
                                                                    uVar9 = 0;
                                                                }
                                                                uVar6 = uVar6 + 1;
                                                            } while (uVar6 < local_14);
                                                            if (uVar9 != 0) {
                                                                local_10 = 1;
                                                            }
                                                        }
                                                    }
                                                    local_1c = local_1c + 1;
                                                    local_34 = local_34 + -1;
                                                } while (local_34 != 0);
                                            }
                                            local_8 = local_8 + 1;
                                        } while (local_8 < local_38);
                                    }
                                    local_c = local_c + 1;
                                } while (local_c < local_14);
                            }
                            local_8 = 0;
                            do {
                                iVar11 = local_128[local_8];
                                if ((iVar11 != -1) && (uVar9 = 0, local_14 != 0)) {
                                    do {
                                        iVar5 = *(int*)((intptr_t)local_78[uVar9] + 0xc);
                                        if (iVar5 != 0) {
                                            piVar7 = *(int**)((intptr_t)local_78[uVar9] + 0x10);
                                            do {
                                                if ((iVar11 == *piVar7) ||
                                                    (*(int*)(*(int*)(*(int*)(local_18 + 0x14) +
                                                                     iVar11 * 4) +
                                                              0x38) == *piVar7)) {
                                                    local_10 = 1;
                                                }
                                                piVar7 = piVar7 + 1;
                                                iVar5 = iVar5 + -1;
                                            } while (iVar5 != 0);
                                        }
                                        uVar9 = uVar9 + 1;
                                    } while (uVar9 < local_14);
                                }
                                local_8 = local_8 + 1;
                            } while (local_8 < 0x28);
                            if (local_10 == 0) goto LAB_00694f79;
                        }
                        local_24 = local_24 + 1;
                    } while (local_24 < (uint32_t)param_2[7] + 1);
                }
                if (local_10 == 0) goto LAB_00694f79;
                local_2c = local_2c + 1;
            } while (local_2c < local_30);
        }
    }
    else {
        local_10 = 1;
    }
    return local_10;
}

// ---------------------------------------------------------------------------
// 0x695053 — duplicate/merge pass over the node list.
// ---------------------------------------------------------------------------
// 0x695053 — observed shape
uint32_t FUN_695053(void* self)
{
    uint32_t uVar1;
    uint32_t* puVar2;
    uint32_t* puVar3;
    bool bVar4;
    int iVar5;
    int* piVar6;
    int* ctx = (int*)self;
    char cVar7;
    uint8_t local_210[256];
    uint8_t local_110[256];
    uint32_t local_10;
    uint32_t local_c;
    char local_5;

    bVar4 = false;
    local_5 = '\0';
    local_c = 0;
    if (ctx[2] != 0) {
        do {
            iVar5 = *(int*)(ctx[5] + (int)local_c * 4);
            uVar1 = *(uint32_t*)(*(int*)(ctx[4] + *(int*)(iVar5 + 4) * 4) + 4);
            if (((((uVar1 & 0x10) != 0) && ((uVar1 & 0x200) == 0)) ||
                 ((uVar1 & 0x20) != 0)) &&
                (iVar5 = ((int (*)(int, int))(intptr_t)(*(int*)ctx + 4))(iVar5, 0),
                 iVar5 < 0)) {
                FUN_694fde(self, (int*)&local_c);
                local_5 = '\x01';
                bVar4 = true;
            }
            local_c = local_c + 1;
        } while (local_c < (uint32_t)ctx[2]);
        if (bVar4) {
            return 0x80004005;
        }
    }
    cVar7 = '\0';
    local_c = 0;
    if (ctx[2] != 0) {
        do {
            puVar2 = *(uint32_t**)(ctx[5] + (int)local_c * 4);
            uVar1 = *(uint32_t*)(*(int*)(ctx[4] + puVar2[1] * 4) + 4);
            if (((((uVar1 & 0x10) != 0) && ((uVar1 & 0x200) == 0)) ||
                 ((uVar1 & 0x20) != 0)) &&
                (local_10 = local_c + 1, local_10 < (uint32_t)ctx[2])) {
                piVar6 = (int*)(ctx[5] + (int)local_10 * 4);
                do {
                    puVar3 = (uint32_t*)(uintptr_t)*piVar6;
                    if (((puVar3[1] == puVar2[1]) && (puVar3[0x1c] == puVar2[0x1c])) &&
                        ((puVar3[0x1b] == puVar2[0x1b]) &&
                         (((*puVar2 ^ *puVar3) & 0x1000000) != 0))) {
                        FUN_0065dd0b(puVar2, local_210, 0x100);
                        FUN_0065dd0b(puVar3, local_110, 0x100);
                        FUN_006626da();
                        FUN_694fde(self, (int*)&local_c);
                        local_5 = '\x01';
                        break;
                    }
                    local_10 = local_10 + 1;
                    piVar6 = piVar6 + 1;
                } while (local_10 < (uint32_t)ctx[2]);
                cVar7 = local_5;
            }
            local_c = local_c + 1;
        } while (local_c < (uint32_t)ctx[2]);
    }
    return -(uint32_t)(cVar7 != '\0') & 0x80004005;
}

// ---------------------------------------------------------------------------
// 0x6951ca — propagate a payload word down a child/sibling tree (offset 0x24).
// ---------------------------------------------------------------------------
// 0x6951ca — observed shape
uint32_t FUN_6951ca(uint8_t* param_1, int param_2, int param_3)
{
    uint32_t uVar1;

    if (*(int*)(param_2 + 0x24) != param_3) {
        uVar1 = 0;
        *(int*)(param_2 + 0x24) = param_3;
        if (*(int*)(param_2 + 0x14) != 0) {
            do {
                FUN_6951ca(param_1,
                           *(int*)(param_1 +
                                   *(int*)(*(int*)(param_2 + 0x18) + uVar1 * 4) * 4),
                           param_3);
                uVar1 = uVar1 + 1;
            } while (uVar1 < *(uint32_t*)(param_2 + 0x14));
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x695210 — same propagation on the 0x18 child list, flag at 0x28.
// ---------------------------------------------------------------------------
// 0x695210 — observed shape
uint32_t FUN_695210(uint8_t* param_1, int param_2, int param_3)
{
    uint32_t uVar1;

    if (*(int*)(param_2 + 0x28) != param_3) {
        uVar1 = 0;
        *(int*)(param_2 + 0x28) = param_3;
        if (*(int*)(param_2 + 0x14) != 0) {
            do {
                FUN_695210(param_1,
                           *(int*)(param_1 +
                                   *(int*)(*(int*)(param_2 + 0x18) + uVar1 * 4) * 4),
                           param_3);
                uVar1 = uVar1 + 1;
            } while (uVar1 < *(uint32_t*)(param_2 + 0x14));
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x695256 — same propagation on the 0x20 child list, flag at 0x28.
// ---------------------------------------------------------------------------
// 0x695256 — observed shape
uint32_t FUN_695256(uint8_t* param_1, int param_2, int param_3)
{
    uint32_t uVar1;

    if (*(int*)(param_2 + 0x28) != param_3) {
        uVar1 = 0;
        *(int*)(param_2 + 0x28) = param_3;
        if (*(int*)(param_2 + 0x1c) != 0) {
            do {
                FUN_695256(param_1,
                           *(int*)(param_1 +
                                   *(int*)(*(int*)(param_2 + 0x20) + uVar1 * 4) * 4),
                           param_3);
                uVar1 = uVar1 + 1;
            } while (uVar1 < *(uint32_t*)(param_2 + 0x1c));
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x69529c — find the next occurrence of a leading modifier letter in a name.
// The 4th stack argument is present at the call site in 0x695343 and is not
// consumed by this body; kept for call-shape fidelity.
// ---------------------------------------------------------------------------
// 0x69529c — observed shape
uint32_t FUN_69529c(void* self, char* param_1, int* param_2, char param_3, int param_4)
{
    (void)param_4;
    char cVar1;
    int iVar2;

    *param_2 = 0;
    while (true) {
        cVar1 = *param_1;
        if (cVar1 == '\0') {
            return 0x80004005;
        }
        while (iVar2 = isalnum((int)cVar1), iVar2 == 0) {
            param_1 = param_1 + 1;
            cVar1 = *param_1;
        }
        iVar2 = tolower((int)*param_1);
        if (iVar2 == param_3) break;
        while (iVar2 = isalnum((int)*param_1), iVar2 != 0) {
            param_1 = param_1 + 1;
        }
    }
    if (*param_2 == 0) {
        *param_2 = (int)(intptr_t)param_1;
        return 0;
    }
    iVar2 = *(int*)((char*)self + 8);
    if (iVar2 != 0) {
        do {
            iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
    }
    FUN_006626da();
    return 0x80004005;
}

// ---------------------------------------------------------------------------
// 0x695343 — selection, ordering and index rewriting over the node/edge tables.
// ---------------------------------------------------------------------------
// 0x695343 — observed shape
int FUN_695343(void* self, int param_1, char* param_2, uint32_t param_3, uint32_t param_4,
               uint32_t param_5)
{
    uint32_t* puVar1;
    uint32_t uVar2;
    int iVar3;
    char* pcVar4;
    int* piVar5;
    int* ctx = (int*)self;
    uint32_t uVar6;
    int iVar7;
    uint32_t uVar8;
    uint32_t uVar9;
    char* pcVar10;
    uint32_t uVar11;
    uint32_t* puVar12;
    uint32_t* local_1c;
    char* local_18;
    int* local_14;
    int* local_10;
    uint32_t* local_c;
    char* local_8;

    uVar9 = 0;
    local_14 = (int*)0x0;
    local_1c = (uint32_t*)0x0;
    if (ctx[1] != 0) {
        do {
            iVar7 = *(int*)(ctx[4] + (int)uVar9 * 4);
            uVar2 = *(uint32_t*)(iVar7 + 4);
            *(uint32_t*)(iVar7 + 0x10) = 0;
            if ((uVar2 & 0x400) == 0) {
                uVar11 = 0;
                *(uint32_t*)(iVar7 + 8) = 0;
                if (ctx[2] != 0) {
                    do {
                        iVar3 = *(int*)(ctx[5] + (int)uVar11 * 4);
                        if ((*(uint32_t*)(iVar3 + 4) == uVar9) &&
                            (uVar6 = *(int*)(iVar3 + 0xc) + 1,
                             *(uint32_t*)(iVar7 + 8) < uVar6)) {
                            *(uint32_t*)(iVar7 + 8) = uVar6;
                        }
                        uVar11 = uVar11 + 1;
                    } while (uVar11 < (uint32_t)ctx[2]);
                }
                if (((uVar2 & 0x100) != 0) && ((uVar2 & 0x800) == 0)) {
                    *(uint32_t*)(iVar7 + 4) = uVar2 & 0xffffffbf;
                }
                uVar2 = *(uint32_t*)(iVar7 + 4);
                if (((uVar2 & 0x10) != 0) && ((uVar2 & 0xa00) == 0)) {
                    *(uint32_t*)(iVar7 + 4) = uVar2 & 0xffffffbf;
                }
                uVar2 = *(uint32_t*)(iVar7 + 4);
                if ((((int8_t)uVar2 < 0) && ((uVar2 & 0x800) == 0)) &&
                    (*(int*)(iVar7 + 8) == 1)) {
                    *(uint32_t*)(iVar7 + 4) = uVar2 & 0xffffffbf;
                }
            }
            uVar9 = uVar9 + 1;
        } while (uVar9 < (uint32_t)ctx[1]);
    }
    local_c = FUN_00533c78((uint32_t)((int)(intptr_t)param_2 << 3));
    if (local_c != nullptr) {
        local_8 = (char*)0x0;
        puVar12 = local_c;
        for (iVar7 = ((uint32_t)(intptr_t)param_2 & 0x1fffffff) << 1; iVar7 != 0;
             iVar7 = iVar7 + -1) {
            *puVar12 = 0;
            puVar12 = puVar12 + 1;
        }
        for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
            *(uint8_t*)puVar12 = 0;
            puVar12 = (uint32_t*)((intptr_t)puVar12 + 1);
        }
        if (ctx[1] != 0) {
        LAB_00695412:
            puVar12 = *(uint32_t**)(ctx[4] + (int)(intptr_t)local_8 * 4);
            uVar9 = puVar12[1];
            if ((((uVar9 & param_3) != param_3) || ((param_4 & uVar9) != 0)) ||
                (((uVar9 & 0x40) == 0) || (((uVar9 & 0x800) == 0) || (puVar12[2] == 0)))) {
                goto LAB_0069552c;
            }
            puVar12[4] = 0xffffffff;
            iVar7 = FUN_69529c(self, (char*)(uintptr_t)*puVar12, (int*)&local_18, (char)param_5,
                               (int)(intptr_t)local_8);
            pcVar10 = local_18;
            if (-1 < iVar7) {
                if ((local_18 != nullptr) &&
                    (iVar7 = tolower((int)*local_18), (char)param_5 == iVar7)) {
                    local_10 = (int*)(pcVar10 + 1);
                    iVar7 = isdigit((int)(char)*local_10);
                    if (iVar7 != 0) {
                        pcVar10 = pcVar10 + 2;
                        while (iVar7 = isdigit((int)*pcVar10), iVar7 != 0) {
                            pcVar10 = pcVar10 + 1;
                        }
                        if ((*pcVar10 == '\0') || (*pcVar10 == ';')) {
                            iVar7 = atoi((char*)local_10);
                            puVar12[4] = (uint32_t)iVar7;
                        }
                    }
                }
                if ((char*)(uintptr_t)puVar12[4] < param_2) {
                    local_10 = (int*)0x0;
                    if (puVar12[2] != 0) {
                        do {
                            if (param_2 <= (char*)(uintptr_t)(puVar12[4] +
                                                              (uint32_t)(intptr_t)local_10)) {
                                if (((((char)param_5 == 'b') || ((char)param_5 == 'c')) ||
                                     ((char)param_5 == 'i')) ||
                                    (((char)param_5 == 's' || ((char)param_5 == 'v')))) {
                                    goto LAB_0069593f;
                                }
                                goto LAB_0069594a;
                            }
                            puVar1 = local_c +
                                     (intptr_t)(puVar12[4] + (uint32_t)(intptr_t)local_10) * 2;
                            if (*puVar1 != 0) {
                                FUN_006626da();
                            }
                            *puVar1 = (uint32_t)(intptr_t)local_8;
                            puVar1[1] = (uint32_t)(intptr_t)local_10;
                            local_10 = (int*)((intptr_t)local_10 + 1);
                        } while (local_10 < (int*)(uintptr_t)puVar12[2]);
                    }
                    goto LAB_0069552c;
                }
                param_2 = (char*)(intptr_t)ctx[2];
                if (param_2 != nullptr) {
                    do {
                        param_2 = (char*)((intptr_t)param_2 - 1);
                    } while (param_2 != nullptr);
                }
                FUN_006626da();
                goto LAB_0069594a;
            }
            goto LAB_006959a1;
        }
    LAB_0069553b:
        iVar7 = ctx[1];
        local_8 = (char*)0x0;
        if (iVar7 != 0) {
            piVar5 = (int*)(intptr_t)ctx[4];
            do {
                uVar9 = *(uint32_t*)(*piVar5 + 4);
                if ((((uVar9 & param_3) == param_3) && ((param_4 & uVar9) == 0)) &&
                    (((uVar9 & 0x40) != 0 &&
                      (((uVar9 & 0x800) == 0 && (*(int*)(*piVar5 + 8) != 0)))))) {
                    local_8 = local_8 + 1;
                }
                piVar5 = piVar5 + 1;
                iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
        }
        piVar5 = (int*)FUN_00533c78((uint32_t)((int)(intptr_t)local_8 << 2));
        uVar9 = 0;
        local_14 = piVar5;
        if (piVar5 != nullptr) {
            local_8 = (char*)0x0;
            if (ctx[1] != 0) {
                do {
                    iVar7 = *(int*)(ctx[4] + (int)uVar9 * 4);
                    uVar2 = *(uint32_t*)(iVar7 + 4);
                    if (((((uVar2 & param_3) == param_3) && ((param_4 & uVar2) == 0)) &&
                         ((uVar2 & 0x40) != 0)) &&
                        (((uVar2 & 0x800) == 0 && (*(int*)(iVar7 + 8) != 0)))) {
                        piVar5[(int)(intptr_t)local_8] = (int)uVar9;
                        local_8 = local_8 + 1;
                    }
                    uVar9 = uVar9 + 1;
                } while (uVar9 < (uint32_t)ctx[1]);
            }
            FUN_0065e1b9(FUN_00694868, piVar5, (uint32_t)(intptr_t)local_8, ctx);
            local_18 = (char*)0x0;
            if (local_8 != (char*)0x0) {
                local_10 = piVar5;
                do {
                    iVar7 = *(int*)(ctx[4] + *local_10 * 4);
                    pcVar10 = (char*)0x0;
                    if (param_2 != nullptr) {
                        do {
                            for (; (pcVar4 = pcVar10,
                                    pcVar10 < param_2 &&
                                        (local_c[(int)(intptr_t)pcVar10 * 2] != 0));
                                 pcVar10 = pcVar10 + 1) {
                            }
                            for (; (pcVar4 < param_2 &&
                                    (local_c[(int)(intptr_t)pcVar4 * 2] == 0));
                                 pcVar4 = pcVar4 + 1) {
                            }
                        } while (((uint32_t)((intptr_t)pcVar4 - (intptr_t)pcVar10) <
                                  *(uint32_t*)(iVar7 + 8)) &&
                                 (pcVar10 = pcVar4, pcVar4 < param_2));
                    }
                    if (param_2 < pcVar10 + *(int*)(iVar7 + 8)) goto joined_r0x006958cb;
                    uVar9 = 0;
                    if (*(int*)(iVar7 + 8) != 0) {
                        piVar5 = (int*)(local_c + (intptr_t)pcVar10 * 2);
                        do {
                            iVar3 = *local_10;
                            piVar5[1] = (int)uVar9;
                            *piVar5 = iVar3;
                            uVar9 = uVar9 + 1;
                            piVar5 = piVar5 + 2;
                        } while (uVar9 < *(uint32_t*)(iVar7 + 8));
                    }
                    local_18 = local_18 + 1;
                    local_10 = local_10 + 1;
                    *(char**)(iVar7 + 0x10) = pcVar10;
                } while (local_18 < local_8);
            }
            uVar9 = 0;
            if (ctx[2] != 0) {
                do {
                    iVar7 = *(int*)(ctx[5] + (int)uVar9 * 4);
                    piVar5 = (int*)(iVar7 + 0xc);
                    *piVar5 = *piVar5 +
                              *(int*)(*(int*)(ctx[4] + *(int*)(iVar7 + 4) * 4) + 0x10);
                    uVar9 = uVar9 + 1;
                } while (uVar9 < (uint32_t)ctx[2]);
            }
            uVar9 = 0;
            if (ctx[1] != 0) {
                do {
                    iVar7 = *(int*)(ctx[4] + (int)uVar9 * 4);
                    *(int*)(iVar7 + 8) = *(int*)(iVar7 + 8) + *(int*)(iVar7 + 0x10);
                    uVar9 = uVar9 + 1;
                    *(uint32_t*)(iVar7 + 0x10) = 0;
                } while (uVar9 < (uint32_t)ctx[1]);
            }
            local_8 = (char*)0x0;
            if (ctx[1] != 0) {
                do {
                    iVar7 = *(int*)(ctx[4] + (int)(intptr_t)local_8 * 4);
                    uVar9 = *(uint32_t*)(iVar7 + 4);
                    if (((((uVar9 & param_3) == param_3) && ((param_4 & uVar9) == 0)) &&
                         ((uVar9 & 0x40) == 0)) &&
                        (((uVar9 & 0x800) == 0 && (*(int*)(iVar7 + 8) != 0)))) {
                        local_1c = FUN_00533c78((uint32_t)(*(int*)(iVar7 + 8) << 2));
                        if (local_1c == nullptr) goto LAB_006958e4;
                        puVar12 = local_1c;
                        for (uVar9 = *(uint32_t*)(iVar7 + 8) & 0x3fffffff; uVar9 != 0;
                             uVar9 = uVar9 - 1) {
                            *puVar12 = 0xffffffff;
                            puVar12 = puVar12 + 1;
                        }
                        for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                            *(uint8_t*)puVar12 = 0xff;
                            puVar12 = (uint32_t*)((intptr_t)puVar12 + 1);
                        }
                        local_10 = (int*)0x0;
                        if (ctx[2] != 0) {
                            do {
                                iVar7 = *(int*)(ctx[5] + (int)(intptr_t)local_10 * 4);
                                if (*(char**)(iVar7 + 4) == local_8) {
                                    if (local_1c[*(int*)(iVar7 + 0xc)] == 0xffffffff) {
                                        pcVar10 = (char*)0x0;
                                        if (param_2 == nullptr) goto joined_r0x006958cb;
                                        do {
                                            if (local_c[(int)(intptr_t)pcVar10 * 2] == 0) break;
                                            pcVar10 = pcVar10 + 1;
                                        } while (pcVar10 < param_2);
                                        if (param_2 <= pcVar10) goto joined_r0x006958cb;
                                        local_c[(int)(intptr_t)pcVar10 * 2] =
                                            (uint32_t)(intptr_t)local_8;
                                        (local_c + (intptr_t)pcVar10 * 2)[1] =
                                            *(uint32_t*)(iVar7 + 0xc);
                                        local_1c[*(int*)(iVar7 + 0xc)] =
                                            (uint32_t)(intptr_t)pcVar10;
                                    }
                                    *(uint32_t*)(iVar7 + 0xc) = local_1c[*(int*)(iVar7 + 0xc)];
                                }
                                local_10 = (int*)((intptr_t)local_10 + 1);
                            } while (local_10 < (int*)(intptr_t)ctx[2]);
                        }
                        operator_delete(local_1c);
                    }
                    local_8 = local_8 + 1;
                } while (local_8 < (char*)(intptr_t)ctx[1]);
            }
            local_1c = (uint32_t*)0x0;
            if (param_1 != -1) {
                uVar9 = 0;
                if (ctx[2] != 0) {
                    do {
                        iVar7 = *(int*)(ctx[5] + (int)uVar9 * 4);
                        uVar2 = *(uint32_t*)(*(int*)(ctx[4] + *(int*)(iVar7 + 4) * 4) + 4);
                        if (((uVar2 & param_3) == param_3) && ((param_4 & uVar2) == 0)) {
                            if ((uVar2 & 0x100) == 0) {
                                *(int*)(iVar7 + 4) = param_1;
                            }
                            else {
                                if ((uVar2 & 0x40000) == 0) {
                                    if ((uVar2 & 0x800) != 0) goto LAB_00695961;
                                    uVar8 = *(uint32_t*)((char*)ctx + 0x78);
                                }
                                else {
                                    uVar8 = *(uint32_t*)((char*)ctx + 0x184);
                                }
                                *(uint32_t*)(iVar7 + 4) = uVar8;
                            }
                        }
                    LAB_00695961:
                        uVar9 = uVar9 + 1;
                    } while (uVar9 < (uint32_t)ctx[2]);
                }
                *(uint32_t*)(*(int*)(ctx[4] + param_1 * 4) + 0x10) = 0;
                *(char**)(*(int*)(ctx[4] + param_1 * 4) + 8) = param_2;
                if (param_1 == *(int*)((char*)ctx + 0x7c)) {
                    *(uint32_t*)(*(int*)(ctx[4] + *(int*)((char*)ctx + 0x78) * 4) + 0x10) = 0;
                    *(char**)(*(int*)(ctx[4] + *(int*)((char*)ctx + 0x78) * 4) + 8) = param_2;
                }
            }
            iVar7 = 0;
            goto LAB_006959a1;
        }
    }
LAB_006958e4:
    iVar7 = -0x7ff8fff2;
    goto LAB_006959a1;
LAB_0069552c:
    local_8 = local_8 + 1;
    if ((char*)(intptr_t)ctx[1] <= local_8) goto LAB_0069553b;
    goto LAB_00695412;
joined_r0x006958cb:
    if ((((char)param_5 == 'v') || ((char)param_5 == 'c')) ||
        (((char)param_5 == 's') || (((char)param_5 == 'b') || ((char)param_5 == 'i')))) {
    LAB_0069593f:
        FUN_006626da();
    }
LAB_0069594a:
    iVar7 = -0x7fffbffb;
LAB_006959a1:
    operator_delete(local_c);
    operator_delete(local_14);
    operator_delete(local_1c);
    return iVar7;
}

// ---------------------------------------------------------------------------
// 0x6959c5 — reset the cached semantic indices, then re-run the parser hook.
// ---------------------------------------------------------------------------
// 0x6959c5 — observed shape
int FUN_6959c5(void* self)
{
    int iVar1;

    *(uint32_t*)((char*)self + 0x138) = 0xffffffff;
    *(uint32_t*)((char*)self + 0x13c) = 0xffffffff;
    *(uint32_t*)((char*)self + 0x140) = 0xffffffff;
    *(uint32_t*)((char*)self + 0x144) = 0xffffffff;
    *(uint32_t*)((char*)self + 0x148) = 0xffffffff;
    *(uint32_t*)((char*)self + 0x14c) = 0;
    *(uint32_t*)((char*)self + 0x150) = 0;
    iVar1 = FUN_00661fbd();
    if (-1 < iVar1) {
        iVar1 = 0;
    }
    return iVar1;
}

// ---------------------------------------------------------------------------
// 0x6959fc — resolve a "<type>[_centroid][<n>]" semantic name against the
// semantic descriptor table.
// ---------------------------------------------------------------------------
// 0x6959fc — observed shape
bool FUN_6959fc(uint32_t* param_1, uint32_t* param_2, uint16_t param_3, int* param_4)
{
    int* piVar1;
    char* _Source;
    uint32_t* puVar2;
    char cVar3;
    char* pcVar4;
    int iVar5;
    uint32_t* puVar6;
    uint32_t* puVar7;
    char local_50[63];
    uint8_t local_11;
    uint32_t local_10;
    int local_c;
    uint32_t local_8 = 0; // never assigned in the listing; forwarded to log helpers

    puVar2 = param_1;
    local_c = 0;
    *param_4 = 0;
    *(uint8_t*)((uint8_t*)param_1 + 3) = *(uint8_t*)((uint8_t*)param_1 + 3) & 0xbf;
    _Source = *(char**)(param_1[0x1a] + 0x18);
    strncpy(local_50, _Source, 0x3f);
    local_11 = 0;
    pcVar4 = local_50;
    cVar3 = local_50[0];
    while (cVar3 != '\0') {
        if (*pcVar4 == '_') goto LAB_00695a4d;
        pcVar4 = pcVar4 + 1;
        cVar3 = *pcVar4;
    }
    if (*pcVar4 == '_') {
    LAB_00695a4d:
        *pcVar4 = '\0';
        iVar5 = _stricmp(pcVar4 + 1, "centroid");
        if (iVar5 != 0) {
            *param_4 = 1;
            param_1[0x1b] = 0;
            FUN_006626da(local_8, param_1[0x1a], 0x1196,
                         "invalid input semantic '%s', only _centroid allowed", _Source);
            goto LAB_00695c16;
        }
        local_c = 1;
    }
    pcVar4 = local_50;
    if (local_50[0] == '\0') {
    LAB_00695abf:
        param_1 = (uint32_t*)0x0;
    }
    else {
        do {
            iVar5 = isalpha((int)*pcVar4);
            if (iVar5 == 0) break;
            pcVar4 = pcVar4 + 1;
        } while (*pcVar4 != '\0');
        if (*pcVar4 == '\0') goto LAB_00695abf;
        param_1 = (uint32_t*)(intptr_t)atoi(pcVar4);
    }
    if (*pcVar4 != '\0') {
        *pcVar4 = '\0';
        pcVar4 = pcVar4 + 1;
    }
    cVar3 = *pcVar4;
    if (cVar3 == '\0') {
    LAB_00695af2:
        param_1 = (uint32_t*)((intptr_t)param_1 + (puVar2[0x1c] >> 2));
    }
    else {
        do {
            iVar5 = isdigit((int)cVar3);
            if (iVar5 == 0) break;
            pcVar4 = pcVar4 + 1;
            cVar3 = *pcVar4;
        } while (cVar3 != '\0');
        if (*pcVar4 == '\0') goto LAB_00695af2;
        param_1 = (uint32_t*)0xffffffff;
    }
    local_10 = FUN_0065db7d(puVar2);
    puVar6 = (uint32_t*)0x0;
    if (param_2[4] != 0xffffffff) {
        do {
            iVar5 = _stricmp((char*)(uintptr_t)*param_2, local_50);
            if ((iVar5 == 0) &&
                (puVar6 = param_2, puVar7 = param_2,
                 (*(uint16_t*)(param_2 + 1) & param_3) != 0)) {
                break;
            }
            puVar7 = param_2 + 9;
            piVar1 = (int*)(param_2 + 0xd);
            param_2 = puVar7;
        } while (*piVar1 != -1);
        if ((puVar6 != (uint32_t*)0x0) && (puVar7[4] != 0xffffffff)) {
            if ((local_c != 0) && ((*(uint8_t*)(puVar6 + 2) & 1) == 0)) {
                *puVar2 = *puVar2 | 0x40000000;
            }
            if (puVar6[3] != 0) {
                FUN_0066275f(local_8, puVar2[0x1a], 0x1261,
                             "%s semantics '%s' has been deprecated; use '%s%d' instead",
                             local_10, local_50, puVar6[3], param_1);
            }
            if (((uintptr_t)param_1 < (uintptr_t)puVar7[5]) ||
                ((uintptr_t)puVar7[6] <= (uintptr_t)param_1)) {
                *puVar2 = *puVar2 | 0x40000000;
            }
            if (puVar2[4] < puVar7[8]) {
                if ((*(uint16_t*)(puVar6 + 1) & param_3) == 0) {
                    *puVar2 = *puVar2 | 0x40000000;
                }
                puVar2[0x1b] = (puVar6[7] + (uint32_t)(intptr_t)param_1) * 0x10000 |
                               puVar6[4] & 0xffff;
                if (local_c != 0) {
                    *(uint8_t*)((uint8_t*)puVar2 + 3) =
                        *(uint8_t*)((uint8_t*)puVar2 + 3) | 1;
                }
            }
            else {
                *puVar2 = *puVar2 | 0x40000000;
                *param_4 = 1;
                FUN_006626da(local_8, puVar2[0x1a], 0x11cb,
                             "invalid type used for '%s' %s semantics", local_50, local_10);
            }
            goto LAB_00695c16;
        }
    }
    *(uint8_t*)((uint8_t*)puVar2 + 3) = *(uint8_t*)((uint8_t*)puVar2 + 3) | 0x40;
    puVar2[0x1b] = 0;
LAB_00695c16:
    return *param_4 != 0;
}

// ---------------------------------------------------------------------------
// 0x695c27 — propagate the "has side effect" bit (0x1000000) transitively.
// ---------------------------------------------------------------------------
// 0x695c27 — observed shape
uint32_t FUN_695c27(void* self)
{
    int* ctx = (int*)self;
    int iVar1;
    uint32_t uVar2;
    bool bVar3;
    bool bVar4;
    uint32_t* puVar5;
    uint32_t uVar6;
    int local_14;
    int* local_c;
    uint32_t local_8;

    do {
        bVar4 = false;
        local_8 = 0;
        if (ctx[3] == 0) break;
        do {
            iVar1 = *(int*)(ctx[6] + (int)local_8 * 4);
            local_14 = *(int*)(iVar1 + 4);
            bVar3 = false;
            if (local_14 != 0) {
                local_c = *(int**)(iVar1 + 8);
                do {
                    puVar5 = *(uint32_t**)(ctx[5] + *local_c * 4);
                    if ((*puVar5 & 0x1000000) != 0) {
                        bVar3 = true;
                    }
                    if (puVar5[0xe] != 0xffffffff) {
                        puVar5 = *(uint32_t**)(ctx[5] + puVar5[0xe] * 4);
                    }
                    if ((*puVar5 & 0x1000000) != 0) {
                        bVar3 = true;
                    }
                    local_c = local_c + 1;
                    local_14 = local_14 + -1;
                } while (local_14 != 0);
                uVar6 = 0;
                if ((bVar3) && (*(int*)(iVar1 + 0xc) != 0)) {
                    do {
                        puVar5 = *(uint32_t**)(ctx[5] +
                                               *(int*)(*(int*)(iVar1 + 0x10) + uVar6 * 4) * 4);
                        uVar2 = *puVar5;
                        if ((uVar2 & 0x1000000) == 0) {
                            *puVar5 = uVar2 | 0x1000000;
                            bVar4 = true;
                        }
                        uVar6 = uVar6 + 1;
                    } while (uVar6 < *(uint32_t*)(iVar1 + 0xc));
                }
            }
            local_8 = local_8 + 1;
        } while (local_8 < (uint32_t)ctx[3]);
    } while (bVar4);
    uVar6 = 0;
    if (ctx[2] != 0) {
        do {
            puVar5 = *(uint32_t**)(ctx[5] + (int)uVar6 * 4);
            if ((puVar5[0xe] != 0xffffffff) &&
                ((**(uint32_t**)(ctx[5] + puVar5[0xe] * 4) & 0x1000000) != 0)) {
                *puVar5 = *puVar5 | 0x1000000;
            }
            uVar6 = uVar6 + 1;
        } while (uVar6 < (uint32_t)ctx[2]);
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x695d0c — clone/emit a node into the instruction stream for a 0x11400001
// single-element pattern.
// ---------------------------------------------------------------------------
// 0x695d0c — observed shape
int FUN_695d0c(void* self)
{
    int* ctx = (int*)self;
    int iVar1;
    uint32_t uVar2;
    int iVar3;
    int iVar4;
    int local_8;

    if (((**(uint32_t**)((char*)ctx + 0x100) & 0xfff00000) == 0x11400000) &&
        ((**(uint32_t**)((char*)ctx + 0x100) & 0xfffff) == 1)) {
        if ((*(uint8_t*)((char*)ctx + 0x70) & 4) == 0) {
            FUN_006626da();
            local_8 = -0x7fffbffb;
        }
        else {
            iVar3 = FUN_0065d0b4();
            if (iVar3 == 0) {
                iVar3 = 0;
            }
            else {
                iVar3 = FUN_0065cc1a();
            }
            if (iVar3 == 0) {
                local_8 = -0x7ff8fff2;
            }
            else {
                local_8 = FUN_0065d0ff(0x74500001, 2, 1, 0);
                if (((local_8 < 0) || (local_8 = FUN_0065cc50(), local_8 < 0)) ||
                    (iVar4 = FUN_0065d9d5(0, 0, 0, 0), iVar4 == -1)) {
                    FUN_00614343();
                }
                else {
                    iVar1 = *(int*)(ctx[5] + iVar4 * 4);
                    FUN_0065d501();
                    **(uint32_t**)(iVar3 + 0x10) =
                        **(uint32_t**)(*(int*)((char*)ctx + 0x100) + 0x10);
                    **(uint32_t**)(iVar3 + 8) =
                        **(uint32_t**)(*(int*)((char*)ctx + 0x100) + 8);
                    *(int*)(*(int*)(iVar3 + 8) + 4) = iVar4;
                    if (*(int*)(iVar1 + 0x38) == -1) {
                        uVar2 = **(uint32_t**)(*(int*)((char*)ctx + 0x100) + 8);
                        *(uint8_t*)(iVar1 + 0x3e) = *(uint8_t*)(iVar1 + 0x3e) | 8;
                        *(uint32_t*)(iVar1 + 0x38) = uVar2;
                    }
                    else {
                        *(uint32_t*)(iVar1 + 0x3c) = *(uint32_t*)(iVar1 + 0x3c) ^ 0x80000;
                    }
                    local_8 = FUN_0065d35e();
                    FUN_00614343();
                }
            }
        }
    }
    else {
        local_8 = 1;
    }
    return local_8;
}

// ---------------------------------------------------------------------------
// 0x695e74 — intern/merge the two operand rows of a 0x20800000 pattern.
// ---------------------------------------------------------------------------
// 0x695e74 — observed shape
uint32_t FUN_695e74(void* self)
{
    int* ctx = (int*)self;
    uint32_t* puVar1;
    int iVar2;
    int iVar8;
    bool bVar3;
    int* piVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    uint32_t local_14;
    int local_10;
    int* local_c;
    uint32_t local_8;

    uVar7 = **(uint32_t**)((char*)ctx + 0x100) & 0xfffff;
    if ((**(uint32_t**)((char*)ctx + 0x100) & 0xfff00000) == 0x20800000) {
        bVar3 = false;
        local_14 = 0;
        local_10 = 0;
        do {
            local_8 = 0;
            if (uVar7 != 0) {
                local_c = *(int**)(*(int*)((char*)ctx + 0x100) + 0x10);
                piVar4 = (int*)(*(int*)(*(int*)((char*)ctx + 0x100) + 8) + local_10);
                do {
                    iVar2 = *(int*)(ctx[5] + *local_c * 4);
                    iVar8 = *(int*)(ctx[5] + *piVar4 * 4);
                    if ((((*(int*)(iVar8 + 4) != *(int*)(iVar2 + 4)) ||
                          (*(int*)(iVar8 + 8) != *(int*)(iVar2 + 8))) ||
                         (*(int*)(iVar8 + 0xc) != *(int*)(iVar2 + 0xc))) ||
                        (*(int*)(iVar8 + 0x10) != *(int*)(iVar2 + 0x10))) {
                        break;
                    }
                    local_8 = local_8 + 1;
                    local_c = local_c + 1;
                    piVar4 = piVar4 + 1;
                } while (local_8 < uVar7);
            }
            if (local_8 != uVar7) {
                uVar5 = FUN_0065da35(uVar7 | 0x10000000, uVar7, uVar7);
                if (uVar5 == 0xffffffff) {
                    return 0x8007000e;
                }
                local_c = (int*)0x0;
                iVar2 = *(int*)(ctx[6] + (int)uVar5 * 4);
                if (uVar7 != 0) {
                    local_8 = (uint32_t)local_10;
                    do {
                        iVar8 = (int)(intptr_t)local_c * 4;
                        *(uint32_t*)(iVar8 + *(int*)(iVar2 + 8)) =
                            *(uint32_t*)(local_8 +
                                         *(int*)(*(int*)((char*)ctx + 0x100) + 8));
                        uVar6 = (uint32_t)FUN_0065dadc(
                            *(int*)(ctx[5] +
                                    *(int*)(iVar8 + *(int*)(*(int*)((char*)ctx + 0x100) + 0x10)) *
                                        4));
                        *(uint32_t*)(local_8 +
                                     *(int*)(*(int*)((char*)ctx + 0x100) + 8)) = uVar6;
                        *(uint32_t*)(iVar8 + *(int*)(iVar2 + 0x10)) =
                            *(uint32_t*)(local_8 +
                                         *(int*)(*(int*)((char*)ctx + 0x100) + 8));
                        if (*(int*)(iVar8 + *(int*)(iVar2 + 0x10)) == -1) {
                            return 0x8007000e;
                        }
                        local_c = (int*)((intptr_t)local_c + 1);
                        local_8 = local_8 + 4;
                        *(uint32_t*)(*(int*)(ctx[5] +
                                             *(int*)(iVar8 + *(int*)(iVar2 + 0x10)) * 4) +
                                     0x14) =
                            *(uint32_t*)(*(int*)(ctx[5] +
                                                 *(int*)(iVar8 + *(int*)(iVar2 + 8)) * 4) +
                                         0x14);
                        *(uint32_t*)(*(int*)(ctx[5] +
                                             *(int*)(iVar8 + *(int*)(iVar2 + 0x10)) * 4) +
                                     0x18) =
                            *(uint32_t*)(*(int*)(ctx[5] +
                                                 *(int*)(iVar8 + *(int*)(iVar2 + 8)) * 4) +
                                         0x18);
                    } while (local_c < (int*)(intptr_t)uVar7);
                }
                while ((*(uint32_t*)((char*)ctx + 0xfc) < uVar5 ||
                        ((uVar5 != 0 &&
                          ((**(uint32_t**)(ctx[6] - 4 + (int)uVar5 * 4) & 0xfff00000) ==
                           0x20800000))))) {
                    puVar1 = (uint32_t*)(ctx[6] + (int)uVar5 * 4);
                    *puVar1 = puVar1[-1];
                    uVar5 = uVar5 - 1;
                }
                *(int*)(ctx[6] + (int)uVar5 * 4) = iVar2;
                *(int*)((char*)ctx + 0xfc) = *(int*)((char*)ctx + 0xfc) + 1;
                bVar3 = true;
            }
            local_14 = local_14 + 1;
            local_10 = local_10 + (int)uVar7 * 4;
        } while (local_14 < 2);
        uVar7 = (uint32_t)!bVar3;
    }
    else {
        uVar7 = 1;
    }
    return uVar7;
}

// ---------------------------------------------------------------------------
// 0x69606d — materialize the four temporary nodes of a 0x10000004 pattern.
// ---------------------------------------------------------------------------
// 0x69606d — observed shape
int FUN_69606d(void* self)
{
    int* ctx = (int*)self;
    uint32_t* puVar1;
    int* piVar2;
    int* piVar3;
    int iVar4;
    int iVar5;
    int iVar7;
    int iVar8;
    uint32_t uVar6;
    uint32_t local_c;
    uint32_t local_8;

    piVar2 = *(int**)(*(int*)((char*)ctx + 0x100) + 0x10);
    piVar3 = *(int**)(ctx + 5);
    if ((((*(uint8_t*)(*(int*)(ctx[4] + *(int*)(piVar3[*piVar2] + 4) * 4) + 4) & 1) == 0) ||
         (*(int*)(piVar3[*piVar2] + 0x3c) != 0)) ||
        (*(int*)(piVar3[piVar2[1]] + 0x3c) != 0)) {
        local_c = 0;
        if (ctx[2] != 0) {
            iVar7 = ctx[2];
            do {
                if ((*(int*)((char*)ctx + 0x88) == *(int*)(*piVar3 + 4)) &&
                    (uVar6 = *(uint32_t*)(*piVar3 + 0xc), local_c <= uVar6)) {
                    local_c = uVar6 + 1;
                }
                piVar3 = piVar3 + 1;
                iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
        }
        iVar7 = FUN_0065da35(0x10000004, 4, 4);
        if (iVar7 == -1) {
            return -0x7ff8fff2;
        }
        iVar7 = *(int*)(ctx[6] + iVar7 * 4);
        iVar4 = FUN_0065cc50();
        if (iVar4 < 0) {
            return iVar4;
        }
        local_8 = 0;
        do {
            iVar4 = FUN_0065d9d5(*(uint32_t*)((char*)ctx + 0x88), local_c, local_8, 0);
            if (iVar4 == -1) {
                return -0x7ff8fff2;
            }
            iVar8 = (int)local_8 * 4;
            iVar5 = FUN_0065d5bd();
            if (iVar5 < 0) {
                return iVar5;
            }
            *(uint32_t*)(*(int*)(ctx[5] + iVar4 * 4) + 0x18) =
                *(uint32_t*)(*(int*)(ctx[5] +
                                     *(int*)(iVar8 +
                                             *(int*)(*(int*)((char*)ctx + 0x100) + 0x10)) *
                                         4) +
                             0x18);
            local_8 = local_8 + 1;
            *(uint32_t*)(*(int*)(ctx[5] + iVar4 * 4) + 0x14) =
                *(uint32_t*)(*(int*)(ctx[5] +
                                     *(int*)(iVar8 +
                                             *(int*)(*(int*)((char*)ctx + 0x100) + 0x10)) *
                                         4) +
                             0x14);
            *(uint32_t*)(iVar8 + *(int*)(iVar7 + 0x10)) =
                *(uint32_t*)(iVar8 + *(int*)(*(int*)((char*)ctx + 0x100) + 0x10));
            *(int*)(iVar8 + *(int*)(*(int*)((char*)ctx + 0x100) + 0x10)) = iVar4;
            *(int*)(iVar8 + *(int*)(iVar7 + 8)) = iVar4;
        } while (local_8 < 4);
        uVar6 = (uint32_t)(ctx[3] - 1);
        while (uVar6 = uVar6 - 1, *(uint32_t*)((char*)ctx + 0xfc) < uVar6) {
            puVar1 = (uint32_t*)(ctx[6] + (int)uVar6 * 4);
            puVar1[1] = *puVar1;
        }
        *(int*)(ctx[6] + 4 + *(uint32_t*)((char*)ctx + 0xfc) * 4) = iVar7;
    }
    *(uint32_t*)((char*)ctx + 0x18c) = 1;
    return 0;
}

// ---------------------------------------------------------------------------
// 0x69620d — swap column `param_2` with the next column in an operand table.
// ---------------------------------------------------------------------------
// 0x69620d — observed shape
void FUN_69620d(uint32_t* param_1, int param_2)
{
    uint32_t uVar1;
    uint32_t uVar2;
    uint32_t* puVar3;
    uint32_t* puVar4;
    int iVar5;

    puVar3 = param_1;
    uVar1 = *param_1;
    param_1 = (uint32_t*)(uintptr_t)(param_1[1] / (uVar1 & 0xfffff));
    if (param_1 != (uint32_t*)0x0) {
        iVar5 = param_2 << 2;
        do {
            puVar4 = (uint32_t*)(puVar3[2] + iVar5);
            uVar2 = *puVar4;
            *puVar4 = puVar4[1];
            *(uint32_t*)(puVar3[2] + 4 + iVar5) = uVar2;
            iVar5 = iVar5 + (int)(uVar1 & 0xfffff) * 4;
            param_1 = (uint32_t*)((intptr_t)param_1 - 1);
        } while (param_1 != (uint32_t*)0x0);
    }
    puVar4 = (uint32_t*)(puVar3[4] + param_2 * 4);
    uVar2 = *puVar4;
    *puVar4 = puVar4[1];
    *(uint32_t*)(puVar3[4] + 4 + param_2 * 4) = uVar2;
    return;
}

// ---------------------------------------------------------------------------
// 0x696278 — bubble the operand table entries by their 0x10 word.
// ---------------------------------------------------------------------------
// 0x696278 — observed shape
uint32_t FUN_696278(void* self)
{
    int* ctx = (int*)self;
    int* piVar1;
    int iVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    uint32_t local_8;

    uVar5 = **(uint32_t**)((char*)ctx + 0x100) & 0xfffff;
    if ((((uVar5 == *(uint32_t*)(*(int*)((char*)ctx + 0x100) + 0xc)) &&
         (iVar2 = FUN_0065ccac(), iVar2 == 0)) &&
        ((iVar2 = FUN_0065cea4(), iVar2 == 0 || (iVar2 = FUN_0065cd3a(), iVar2 != 0)))) &&
        ((uVar5 < 5 && (uVar5 != 0)))) {
        local_8 = 0;
        if (uVar5 != 0) {
            do {
                uVar4 = 0;
                if (uVar5 - local_8 != 1) {
                    do {
                        piVar1 = (int*)(*(int*)(*(int*)((char*)ctx + 0x100) + 0x10) +
                                        uVar4 * 4);
                        if (*(uint32_t*)(*(int*)(ctx[5] + piVar1[1] * 4) + 0x10) <
                            *(uint32_t*)(*(int*)(ctx[5] + *piVar1 * 4) + 0x10)) {
                            FUN_69620d(*(uint32_t**)((char*)ctx + 0x100), (int)uVar4);
                        }
                        uVar4 = uVar4 + 1;
                    } while (uVar4 < (uVar5 - local_8) - 1);
                }
                local_8 = local_8 + 1;
            } while (local_8 < uVar5);
        }
        uVar3 = 0;
    }
    else {
        uVar3 = 1;
    }
    return uVar3;
}

// ---------------------------------------------------------------------------
// 0x69632a — lower a 0x10000000 pattern into per-row copies and a new node.
// ---------------------------------------------------------------------------
// 0x69632a — observed shape
int FUN_69632a(void* self)
{
    int* ctx = (int*)self;
    uint32_t* puVar1;
    uint32_t uVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    int* piVar6;
    uint32_t uVar7;
    uint32_t uVar8;
    int* piVar9;
    int local_4c[4];
    int local_3c[4];
    int local_2c;
    int local_28;
    uint32_t local_24;
    uint32_t local_20;
    uint32_t local_1c;
    uint32_t local_18;
    int local_14;
    uint32_t local_10;
    int local_c;
    uint32_t local_8;

    puVar1 = *(uint32_t**)((char*)ctx + 0x100);
    uVar8 = *puVar1 & 0xfffff;
    if (((uVar8 != 0) && (puVar1[1] != 0)) && (puVar1[3] != 0)) {
        local_24 = puVar1[1] / uVar8;
        local_8 = 0;
        if (local_24 != 0) {
            iVar3 = ctx[5];
            piVar6 = (int*)(uintptr_t)puVar1[2];
            local_1c = local_24;
            local_10 = uVar8;
            do {
                iVar5 = *(int*)(*(int*)(iVar3 + *piVar6 * 4) + 8);
                if ((iVar5 != -1) &&
                    (uVar8 = local_10,
                     (*(uint8_t*)(*(int*)(ctx[4] +
                                          *(int*)(*(int*)(iVar3 + iVar5 * 4) + 4) * 4) +
                                   4) & 4) == 0)) {
                    piVar9 = local_4c + local_8;
                    local_8 = local_8 + 1;
                    *piVar9 = iVar5;
                }
                piVar6 = piVar6 + uVar8;
                local_1c = local_1c - 1;
            } while (local_1c != 0);
            uVar7 = 0;
            if (local_8 != 0) {
                local_1c = 0;
                if (local_8 != 0) {
                    do {
                        if (local_8 == 1) {
                            uVar2 = 3;
                        }
                        else {
                            uVar2 = uVar7;
                        }
                        iVar3 = FUN_0065d9d5(*(uint32_t*)((char*)ctx + 0x8c), 0, uVar2, 0);
                        local_3c[uVar7] = iVar3;
                        if (iVar3 == -1) {
                            return -0x7ff8fff2;
                        }
                        iVar3 = *(int*)(ctx[5] + iVar3 * 4);
                        *(uint32_t*)(iVar3 + 0x14) =
                            *(uint32_t*)(*(int*)(ctx[5] +
                                                 (**(int**)(
                                                     *(int*)((char*)ctx + 0x100) +
                                                     0x10)) *
                                                     4) +
                                         0x14);
                        uVar7 = uVar7 + 1;
                        *(uint32_t*)(iVar3 + 0x18) =
                            *(uint32_t*)(*(int*)(ctx[5] +
                                                 (**(int**)(
                                                     *(int*)((char*)ctx + 0x100) +
                                                     0x10)) *
                                                     4) +
                                         0x18);
                    } while (uVar7 < local_8);
                }
                local_8 = 0;
                local_1c = 0;
                local_14 = 0;
                do {
                    iVar3 = *(int*)(*(int*)(ctx[5] +
                                            *(int*)(local_14 +
                                                    *(int*)(*(int*)((char*)ctx + 0x100) + 8)) *
                                                4) +
                                    8);
                    if ((iVar3 != -1) &&
                        ((*(uint8_t*)(*(int*)(ctx[4] +
                                              *(int*)(*(int*)(ctx[5] + iVar3 * 4) + 4) * 4) +
                                       4) & 4) == 0)) {
                        local_18 = 0;
                        if (uVar8 != 0) {
                            local_c = local_14;
                            do {
                                local_20 = *(uint32_t*)(ctx[5] +
                                                        *(int*)(local_c +
                                                                *(int*)(*(int*)(
                                                                              (char*)ctx + 0x100) +
                                                                         8)) *
                                                            4);
                                iVar3 = FUN_0065d9d5(0, 0, 0, 0);
                                if (iVar3 == -1) {
                                    return -0x7ff8fff2;
                                }
                                iVar5 = *(int*)(ctx[5] + iVar3 * 4);
                                local_2c = iVar3;
                                iVar4 = FUN_0065d501();
                                if (iVar4 < 0) {
                                    return iVar4;
                                }
                                if (*(int*)(iVar5 + 0x38) != -1) {
                                    iVar3 = FUN_0065d9d5(0, 0, 0, 0);
                                    if (iVar3 == -1) {
                                        return -0x7ff8fff2;
                                    }
                                    local_28 = *(int*)(ctx[5] + iVar3 * 4);
                                    FUN_0065d501();
                                    iVar4 = local_3c[local_8];
                                    *(int*)(iVar5 + 0x38) = iVar3;
                                    *(int*)(local_28 + 8) = iVar4;
                                    iVar3 = local_2c;
                                }
                                local_18 = local_18 + 1;
                                iVar4 = local_c + 4;
                                *(int*)(iVar5 + 8) = local_3c[local_8];
                                *(int*)(local_c +
                                        *(int*)(*(int*)((char*)ctx + 0x100) + 8)) = iVar3;
                                local_c = iVar4;
                            } while (local_18 < local_10);
                            uVar8 = local_10;
                        }
                        local_8 = local_8 + 1;
                    }
                    local_1c = local_1c + 1;
                    local_14 = local_14 + (int)uVar8 * 4;
                    if (local_24 <= local_1c) {
                        iVar3 = FUN_0065d0b4();
                        if (iVar3 == 0) {
                            local_14 = 0;
                        }
                        else {
                            local_14 = FUN_0065cc1a();
                        }
                        iVar3 = local_14;
                        if (local_14 == 0) {
                            return -0x7ff8fff2;
                        }
                        iVar5 = FUN_0065d0ff(local_8 & 0xfffff | 0x10000000, (int)local_8,
                                             (int)local_8, 0);
                        if ((-1 < iVar5) && (iVar5 = FUN_0065cc50(), -1 < iVar5)) {
                            piVar6 = local_3c;
                            piVar9 = *(int**)(iVar3 + 0x10);
                            for (uVar8 = local_8 & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
                                *piVar9 = *piVar6;
                                piVar6 = piVar6 + 1;
                                piVar9 = piVar9 + 1;
                            }
                            for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
                                *(char*)piVar9 = (char)*piVar6;
                                piVar6 = (int*)((intptr_t)piVar6 + 1);
                                piVar9 = (int*)((intptr_t)piVar9 + 1);
                            }
                            piVar6 = local_4c;
                            piVar9 = *(int**)((intptr_t)local_14 + 8);
                            for (uVar8 = local_8 & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
                                *piVar9 = *piVar6;
                                piVar6 = piVar6 + 1;
                                piVar9 = piVar9 + 1;
                            }
                            for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
                                *(char*)piVar9 = (char)*piVar6;
                                piVar6 = (int*)((intptr_t)piVar6 + 1);
                                piVar9 = (int*)((intptr_t)piVar9 + 1);
                            }
                            iVar5 = FUN_0065d8c2();
                            if (-1 < iVar5) {
                                return 0;
                            }
                        }
                        FUN_00614343();
                        return iVar5;
                    }
                } while (true);
            }
        }
    }
    return 1;
}
