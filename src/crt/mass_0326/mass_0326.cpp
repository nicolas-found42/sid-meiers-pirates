// UNVERIFIED: clean-room reconstruction from Ghidra 12.2 pseudocode for the batch mass_0326
// addresses (Sid Meier's Pirates!, 2004; PE32 i386). No compiler or test run performed.
// Provider-listed register receivers are modelled with an explicit `self` parameter.
#include <cstdint>
#include <cstddef>

// ---------------------------------------------------------------------------
// Referenced helpers (declared extern, observed call shapes only)
// ---------------------------------------------------------------------------
extern void* FUN_0067a679(uint32_t a, uint32_t b, uint32_t c, uint32_t d, int e);
extern void  FUN_006626da(void);
extern int   FUN_0065d0b4(void);
extern int   FUN_0065cc1a(int handle);
extern int   FUN_0065d0ff(uint32_t tag, uint32_t a, uint64_t b, ...);
extern int   FUN_0065d9d5(uint32_t allocator, uint32_t a, uint32_t b, uint32_t c);
extern void  FUN_0065d501(void);
extern int   FUN_0065d8c2(void);
extern void  FUN_00614343(void* p);
extern int   FUN_006a4aab(int a, void* b, int c, int d, int e, void* f, int g,
                          int h, int i, int j, int k);
extern int   FUN_006a48dd(int a);
extern int   FUN_0069fcf5(void);

// 0x67a771 — observed shape
// Validates the vertex-declaration elements of one stream against the element table at
// self+0x14 and locates the first element whose tag matches the requested regime.
int FUN_0067a771(void* self, uint32_t param_1, uint32_t param_2, uint32_t* param_3,
                 uint32_t* param_4, int* param_5, uint32_t* param_6,
                 int param_7, uint32_t param_8)
{
    uint32_t* puVar2 = param_3;
    uint32_t uVar9 = *param_3 & 0xfffff;
    uint32_t* elements;

    *param_6 = 0;
    *param_5 = 0;
    *param_4 = 0;
    if (uVar9 == 0) {
        return 0x80004005;
    }

    uint32_t uVar4 = param_3[1] / uVar9;
    if ((param_8 == 0) && (param_8 = 0, uVar4 != 0)) {
        uint32_t* offset = (uint32_t*)0x0;
        elements = (uint32_t*)0x0;
        do {
            uint32_t uVar8 = 0;
            if (uVar9 != 0) {
                int* piVar5 = (int*)(puVar2[2] + (int)(size_t)offset);
                do {
                    if (*(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) + *piVar5 * 4) + 0x10) != uVar8) {
                        return 1;
                    }
                    uVar8 = uVar8 + 1;
                    piVar5 = piVar5 + 1;
                } while (uVar8 < uVar9);
            }
            param_8 = param_8 + 1;
            offset = (uint32_t*)((int)(size_t)offset + uVar9 * 4);
        } while (param_8 < uVar4);
    }

    int iVar10 = 0;
    bool bVar1 = false;
    uint32_t* index = (uint32_t*)0x0;
    if (uVar4 != 0) {
        do {
            uint32_t* puVar6 = (uint32_t*)FUN_0067a679(param_1, param_2,
                                                      puVar2[2] + (uint32_t)(iVar10 * 4), uVar9, param_7);
            if (puVar6 != (uint32_t*)0x0) {
                uint32_t uVar8 = *puVar6 & 0xfff00000u;
                bool match = false;
                if (param_7 == 0) {
                    if (uVar8 == 0x72100000u) {
                        match = true;
                    }
                } else if (uVar8 == 0x60000000u || uVar8 == 0x60500000u ||
                           uVar8 == 0x60a00000u || uVar8 == 0x60f00000u) {
                    match = true;
                }
                if (match) {
                    if (bVar1) {
                        *param_5 = 0;
                        *param_4 = 0;
                        *param_6 = 0;
                        return 1;
                    }
                    *param_6 = puVar6;
                    bVar1 = true;
                    *param_5 = iVar10;
                    int iVar7;
                    if (param_7 == 0) {
                        iVar7 = *(int*)puVar6[2];
                    } else {
                        iVar7 = *(int*)(puVar6[2] + (*puVar6 & 0xfffff) * 4);
                    }
                    *param_4 = (uint32_t)*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x14) + iVar7 * 4) + 0x6d);
                }
            }
            index = (uint32_t*)((int)(size_t)index + 1);
            iVar10 = iVar10 + (int)uVar9;
        } while ((uint32_t)(size_t)index < uVar4);
    }
    return 0;
}

// 0x67a8d2 — observed shape
// Rewrites a declaration array (in place, entries set to null on success) after validating
// the "patch"/"blend" style declarations; allocates the replacement declaration records.
int FUN_0067a8d2(void* self, int* param_1, uint32_t param_2, int param_3)
{
    uint32_t* puVar1;
    int iVar2;
    int iVar5 = 0;
    bool bVar3;
    int* piVar4;
    int* local_c = (int*)0x0;
    uint32_t local_10 = 0;
    uint32_t local_18 = 0;
    uint32_t local_28 = 0;
    uint32_t local_1c = 0;
    uint32_t local_24 = 0;
    uint32_t uVar6 = 0;
    uint32_t uVar7 = 0;
    int local_14 = 0;
    int local_2c = 0;
    int local_20 = 0;
    int local_30 = 0;
    int local_3c = 0;
    int local_38 = 0;
    int local_34 = 0;
    int local_50[5] = { 0, 0, 0, 0, 0 };
    int local_8 = 0;

    auto cleanup = [&](int rc) -> int {
        if (local_8 != 0) {
            FUN_00614343((void*)(size_t)local_8);
        }
        return rc;
    };

    if (param_2 != 0) {
        local_c = param_1;
        do {
            puVar1 = (uint32_t*)*local_c;
            if (puVar1 != (uint32_t*)0x0) {
                local_24 = *puVar1;
                uVar7 = local_24 & 0xfffff;
                local_1c = uVar7;
                FUN_0067a771(self, (uint32_t)param_3, 4, puVar1, &local_18, &local_28, (uint32_t*)&local_14, 1, 1);

                bool takePath = false;
                if (local_14 == 0) {
                    if (uVar7 == 2) {
                        uVar7 = puVar1[2];
                        local_20 = (int)(size_t)FUN_0067a679(*(uint32_t*)((char*)self + 0x22c),
                                                             *(uint32_t*)((char*)self + 0x220),
                                                             uVar7 + 8, 1, 0);
                        local_30 = (int)(size_t)FUN_0067a679(*(uint32_t*)((char*)self + 0x22c),
                                                             *(uint32_t*)((char*)self + 0x220),
                                                             uVar7 + 0xc, 1, 0);
                        if (local_20 != 0 && local_30 != 0) {
                            FUN_0067a771(self, (uint32_t)param_3, 4, (uint32_t*)(size_t)local_20,
                                         &local_18, &local_28, (uint32_t*)&local_2c, 1, 1);
                            if (local_2c != 0) {
                                FUN_0067a771(self, (uint32_t)param_3, 4, (uint32_t*)(size_t)local_30,
                                             &local_18, &local_28, (uint32_t*)&local_14, 1, 1);
                                if (local_2c == local_14) {
                                    uVar7 = local_1c;
                                    takePath = true;
                                }
                            }
                        }
                    }
                } else if (uVar7 != 2) {
                    takePath = true;
                }

                if (takePath && local_14 != 0) {
                    uVar6 = 0;
                    local_8 = 0;
                    bool doPayload = false;

                    if (uVar7 == 3) {
                        if ((local_24 & 0xfff00000u) == 0x60f00000u ||
                            (local_24 & 0xfff00000u) == 0x60a00000u) {
                            local_28 = 1;
                            piVar4 = (int*)(puVar1[2] + 0xc);
                            do {
                                iVar5 = *(int*)(*(int*)((char*)self + 0x14) + *piVar4 * 4);
                                if (*(uint32_t*)(iVar5 + 0x10) != uVar6) {
                                    local_28 = 0;
                                }
                                iVar5 = *(int*)(iVar5 + 0x3c);
                                if (iVar5 != 0 && iVar5 != 0x60000) {
                                    // LAB_0067ad7e
                                    FUN_006626da();
                                    return -0x7fffbffb;
                                }
                                uVar6 = uVar6 + 1;
                                piVar4 = piVar4 + 1;
                            } while (uVar6 < 3);

                            if (local_28 != 0) {
                                if ((*(uint32_t*)((char*)self + 200) & 0xffff) < 0x102) {
                                    FUN_006626da();
                                    return -0x7fffbffb;
                                }
                                iVar5 = FUN_0065d0b4();
                                local_8 = (iVar5 == 0) ? 0 : FUN_0065cc1a(iVar5);
                                if (local_8 == 0) {
                                    // LAB_0067ad9f
                                    return cleanup(-0x7ff8fff2);
                                }
                                iVar5 = FUN_0065d0ff(0x72600003, 6, 4, 0);
                                if (iVar5 >= 0) {
                                    doPayload = true;   // LAB_0067ab94
                                } else {
                                    return cleanup(iVar5);
                                }
                            }
                        }
                    } else if (uVar7 == 2 && (local_24 & 0xfff00000u) == 0x60500000u) {
                        uVar7 = 0;
                        bVar3 = true;
                        local_50[2] = 3;
                        local_50[3] = 0;
                        local_50[0] = 1;
                        local_50[1] = 2;
                        local_28 = 1;
                        do {
                            iVar5 = (uVar7 != 0) ? local_30 : local_20;
                            iVar5 = *(int*)(*(int*)((char*)self + 0x14) + **(int**)(size_t)(iVar5 + 8) * 4);
                            iVar2 = *(int*)(iVar5 + 0x10);
                            if (iVar2 != local_50[uVar7 + 2]) {
                                local_28 = 0;
                            }
                            if (iVar2 != local_50[uVar7]) {
                                bVar3 = false;
                            }
                            if (*(int*)(iVar5 + 0x3c) != 0) {
                                // LAB_0067ad7e
                                FUN_006626da();
                                return -0x7fffbffb;
                            }
                            uVar7 = uVar7 + 1;
                        } while (uVar7 < 2);

                        if (local_28 != 0 || bVar3) {
                            iVar5 = FUN_0065d0b4();
                            local_8 = (iVar5 == 0) ? 0 : FUN_0065cc1a(iVar5);
                            if (local_8 == 0) {
                                return cleanup(-0x7ff8fff2);
                            }
                            iVar5 = FUN_0065d0ff((uint32_t)(bVar3 ? 0x100000 : 0) + 0x72700002u, 4, 4, 0);
                            if (iVar5 < 0) {
                                return cleanup(iVar5);
                            }
                            doPayload = true;       // LAB_0067ab94
                        }
                    }

                    if (doPayload) {
                        uVar7 = 0;
                        do {
                            *(uint32_t*)(uVar7 + *(int*)(local_8 + 0x10)) =
                                *(uint32_t*)(uVar7 + *(int*)(*local_c + 0x10));
                            uVar7 = uVar7 + 4;
                        } while (uVar7 < 0x10);

                        iVar5 = *(int*)(*(int*)((char*)self + 0x14) + **(int**)(size_t)(*local_c + 8) * 4);
                        local_34 = *(int*)(*(int*)((char*)self + 0x14) +
                                           *(int*)(*(int*)(local_14 + 8) + 0xc) * 4);

                        if ((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) + *(int*)(iVar5 + 4) * 4) + 5) & 8) == 0) {
                            for (uVar7 = local_18;
                                 (uVar7 < 4 && (*(int*)(param_3 + uVar7 * 4) != 0));
                                 uVar7 = uVar7 + 1) {
                            }
                            if (uVar7 == 4) {
                                // LAB_0067abf3
                                return cleanup(-0x7fffbffb);
                            }
                            *(uint32_t*)(iVar5 + 0xc) = uVar7;
                            local_28 = uVar7;
                        } else {
                            local_28 = *(uint32_t*)(iVar5 + 0xc);
                            if (local_28 > 3 || *(int*)(param_3 + local_28 * 4) != 0) {
                                return cleanup(-0x7fffbffb);
                            }
                        }

                        uVar7 = local_28;
                        local_3c = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x80), local_28, 0, 0);
                        if (local_3c == -1) {
                            return cleanup(-0x7ff8fff2);
                        }
                        iVar5 = *(int*)(*(int*)((char*)self + 0x14) + local_3c * 4);
                        FUN_0065d501();
                        *(uint32_t*)(iVar5 + 0x6c) = (uVar7 << 8) | 3;
                        *(uint32_t*)(iVar5 + 0xc) = uVar7;

                        uVar6 = 0;
                        if (local_1c != 0) {
                            local_24 = local_1c << 2;
                            do {
                                local_50[4] = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x80), local_18, uVar6, 0);
                                if (local_50[4] == -1) {
                                    return cleanup(-0x7ff8fff2);
                                }
                                iVar5 = *(int*)(*(int*)((char*)self + 0x14) + local_50[4] * 4);
                                local_38 = *(int*)(*(int*)((char*)self + 0x14) +
                                                   *(int*)(local_1c * 4 + *(int*)(*local_c + 8)) * 4);
                                FUN_0065d501();
                                *(uint32_t*)(iVar5 + 0xc) = local_18;
                                *(uint32_t*)(iVar5 + 0x10) = uVar6;
                                *(uint32_t*)(iVar5 + 0x3c) = *(uint32_t*)(local_38 + 0x3c);
                                *(int*)(*(int*)(local_8 + 8) + uVar6 * 4) = local_3c;
                                uVar7 = local_24 + 4;
                                uVar6 = uVar6 + 1;
                                *(int*)(local_24 + *(int*)(local_8 + 8)) = local_50[4];
                                local_24 = uVar7;
                            } while (uVar6 < local_1c);
                            uVar7 = local_28;
                        }

                        *(int*)(param_3 + uVar7 * 4) = local_8;
                        iVar5 = FUN_0065d8c2();
                        if (iVar5 < 0) {
                            return cleanup(iVar5);
                        }
                        *local_c = 0;
                        local_8 = 0;
                    }
                }
            }
            // LAB_0067b31c
            local_10 = local_10 + 1;
            local_c = local_c + 1;
        } while (local_10 < param_2);
    }
    iVar5 = 0;
    // LAB_0067ad2e
    return cleanup(iVar5);
}

// 0x67ada6 — observed shape
// Declaration merge/patch path: validates every element of a multi-element declaration,
// rejects conflicting slot reuse, then allocates and (optionally) copies element records.
int FUN_0067ada6(void* self, int* param_1, uint32_t param_2, int param_3, uint32_t param_4)
{
    uint32_t* puVar1;
    int iVar2;
    int* piVar3;
    int iVar4 = 0;
    uint32_t uVar5 = 0;
    uint32_t uVar6 = 0;
    uint32_t uVar7 = 0;
    uint64_t uVar8 = 0;
    uint32_t auStack_88[8] = { 0 };
    uint32_t auStack_70[16] = { 0 };
    uint32_t local_4c[4] = { 0, 0, 0, 0 };
    uint32_t auStack_3c[4] = { 0 };
    uint32_t local_2c = 0;
    uint32_t* local_28 = (uint32_t*)0x0;
    uint32_t local_24 = 0;
    uint32_t local_20 = 0;
    uint32_t* local_1c = (uint32_t*)0x0;
    int* local_18 = (int*)0x0;
    int* local_14 = (int*)0x0;
    int* local_10 = (int*)0x0;
    uint32_t local_c = 0;
    uint32_t local_8 = 0;

    auto cleanup = [&](int rc) -> int {
        uint32_t i = 0;
        do {
            if (auStack_70[i + 9] != 0) {
                FUN_00614343((void*)(size_t)auStack_70[i + 9]);
            }
            i = i + 1;
        } while (i < 3);
        return rc;
    };

    local_2c = 0;
    local_4c[0] = 0;
    local_4c[1] = 0;
    local_4c[2] = 0;

    for (local_2c = 0, local_18 = param_1; local_2c < param_2; local_2c = local_2c + 1, local_18 = local_18 + 1) {
        puVar1 = (uint32_t*)*local_18;
        if (puVar1 == (uint32_t*)0x0) {
            continue;
        }

        uVar5 = *puVar1 & 0xfffff;
        uVar6 = uVar5;
        if ((*puVar1 & 0xfff00000u) == 0x60000000u) {
            uVar6 = 1;
        }
        if (uVar6 != param_4 || (*puVar1 & 0xfff00000u) == 0x11000000u) {
            continue;
        }

        {
            local_c = 0;
            local_8 = 0;
            bool skipItem = false;

            if (param_4 != 0) {
                local_10 = (int*)(puVar1[2] + uVar5 * 4);
                do {
                    piVar3 = (int*)(size_t)FUN_0067a679(*(uint32_t*)((char*)self + 0x22c),
                                                        *(uint32_t*)((char*)self + 0x220),
                                                        (uint32_t)(size_t)local_10, 1, 0);
                    uVar6 = local_8;
                    local_14 = piVar3;
                    auStack_70[local_8 + 6] = (uint32_t)(size_t)piVar3;
                    if (piVar3 == (int*)0x0 || *piVar3 != 0x50000003) {
                        local_c = 1;
                    } else {
                        FUN_0067a771(self,
                                     *(uint32_t*)((char*)self + 0x22c),
                                     *(uint32_t*)((char*)self + 0x220),
                                     (uint32_t*)(size_t)local_14,
                                     auStack_70 + uVar6 + 0xd,
                                     auStack_70 + uVar6,
                                     auStack_88 + uVar6, 0, 0);
                        local_1c = auStack_88 + uVar6 + 3;
                        FUN_0067a771(self, (uint32_t)param_3, 4, (uint32_t*)(size_t)local_14,
                                     local_1c, auStack_70 + uVar6 + 3, local_4c + 3, 1, 0);
                        if (auStack_88[uVar6] == 0 || *local_1c != auStack_88[3] || local_4c[3] == 0) {
                            local_c = 1;
                        }
                    }
                    local_8 = local_8 + 1;
                    local_10 = local_10 + 1;
                } while (local_8 < param_4);

                if (local_c != 0) {
                    continue;   // LAB_0067b31c
                }
            }

            // Scan the live declaration table for a conflicting usage of this slot.
            local_8 = 0;
            if (param_4 != 0) {
                do {
                    uVar6 = local_8;
                    local_20 = *(uint32_t*)((char*)self + 0x4c);
                    if (local_20 < *(uint32_t*)((char*)self + 0x224)) {
                        local_14 = (int*)(*(int*)((char*)self + 0x230) + local_20 * 4);
                        do {
                            local_10 = (int*)*local_14;
                            puVar1 = (uint32_t*)*local_18;
                            if (local_10 != (int*)0x0 && puVar1 != (uint32_t*)0x0 && *local_10 != 0) {
                                local_c = *puVar1 & 0xfffff;
                                local_24 = puVar1[1];
                                if (*puVar1 == 0x72d00003u) {
                                    local_24 = 6;
                                }
                                if (local_c < local_24) {
                                    local_1c = (uint32_t*)(size_t)local_10[1];
                                    do {
                                        local_28 = (uint32_t*)0x0;
                                        if (local_1c != (uint32_t*)0x0) {
                                            iVar4 = *(int*)(puVar1[2] + local_c * 4);
                                            piVar3 = (int*)local_10[2];
                                            do {
                                                if (*piVar3 == iVar4 ||
                                                    *(int*)(*(int*)(*(int*)((char*)self + 0x14) + *piVar3 * 4) + 0x38) == iVar4) {
                                                    // LAB_0067b35e
                                                    FUN_006626da();
                                                    return cleanup(-0x7fffbffb);
                                                }
                                                local_28 = (uint32_t*)((int)(size_t)local_28 + 1);
                                                piVar3 = piVar3 + 1;
                                                local_1c = (uint32_t*)(size_t)local_10[1];
                                            } while (local_28 < (uint32_t*)(size_t)local_10[1]);
                                        }
                                        local_c = local_c + 1;
                                    } while (local_c < local_24);
                                }
                            }
                            local_14 = local_14 + 1;
                            local_20 = local_20 + 1;
                        } while (local_20 < *(uint32_t*)((char*)self + 0x224));
                    }

                    if (local_8 != 0 &&
                        (auStack_70[local_8 + 0xc] <= auStack_88[3] ||
                         auStack_70[local_8 + 0xd] != auStack_70[local_8 + 0xc] + 1)) {
                        // LAB_0067b3c7
                        FUN_006626da();
                        return cleanup(-0x7fffbffb);
                    }

                    if (*(int*)(*(int*)(*(int*)((char*)self + 0x14) +
                                        *(int*)(*(int*)(auStack_70[local_8 + 6] + 8) +
                                                auStack_70[local_8] * 4) * 4) + 0x3c) != 0 ||
                        ((iVar4 = *(int*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                 *(int*)(*(int*)(auStack_70[local_8 + 6] + 8) +
                                                         auStack_70[local_8 + 3] * 4) * 4) + 0x3c),
                          iVar4 != 0 && iVar4 != 0x60000))) {
                        // LAB_0067b35e
                        FUN_006626da();
                        return cleanup(-0x7fffbffb);
                    }

                    iVar4 = FUN_0065d0b4();
                    uVar5 = (iVar4 == 0) ? 0 : (uint32_t)FUN_0065cc1a(iVar4);
                    auStack_70[uVar6 + 9] = uVar5;
                    if (uVar5 == 0) {
                        return cleanup(-0x7ff8fff2);
                    }

                    if (local_8 == param_4 - 1) {
                        if (*(int*)*local_18 == 0x72d00003) {
                            if (param_4 != 3) {
                                // LAB_0067b3a7
                                return cleanup(1);
                            }
                            uVar8 = 4;
                            uVar7 = 9;
                            iVar4 = 0x72a00003;
                        } else if (*(int*)*local_18 == 0x72c00003) {
                            if (param_4 != 3) {
                                return cleanup(1);
                            }
                            uVar8 = 4;
                            uVar7 = 6;
                            iVar4 = 0x72900003;
                        } else {
                            uVar8 = 4;
                            uVar7 = 6;
                            if (param_4 != 1) {
                                iVar4 = (int)(((param_4 != 3) - 1) & 0x200000) + 0x72300003;
                            } else {
                                iVar4 = 0x72b00003;
                            }
                        }
                    } else {
                        uVar8 = 0;
                        iVar4 = (int)(((param_4 != 3) - 1) & 0x200000) + 0x72200003;
                        // LAB_0067b0e4
                        uVar7 = 6;
                    }

                    iVar4 = FUN_0065d0ff((uint32_t)iVar4, uVar7, uVar8);
                    if (iVar4 < 0) {
                        return cleanup(iVar4);
                    }
                    local_8 = local_8 + 1;
                } while (local_8 < param_4);
            }

            // Fill the freshly allocated element records from the validated declaration.
            local_8 = 0;
            if (param_4 != 0) {
                do {
                    local_14 = (int*)0x0;
                    uVar6 = auStack_70[local_8 + 9];
                    local_1c = (uint32_t*)(size_t)auStack_70[local_8 + 6];
                    local_10 = (int*)(size_t)auStack_88[local_8];
                    local_24 = auStack_70[local_8 + 3] << 2;
                    local_20 = auStack_70[local_8] << 2;
                    uVar5 = 0xc;
                    do {
                        *(uint32_t*)((uVar5 - 0xc) + *(int*)(uVar6 + 8)) =
                            *(uint32_t*)(local_20 + local_1c[2]);
                        *(uint32_t*)(uVar5 + *(int*)(uVar6 + 8)) =
                            *(uint32_t*)(local_24 + local_1c[2]);
                        local_c = *(uint32_t*)(*(int*)((char*)self + 0x14) +
                                               *(int*)(*(int*)(uVar6 + 8) + -0xc + uVar5) * 4);
                        auStack_3c[3] = *(uint32_t*)(*(int*)((char*)self + 0x14) +
                                                     *(int*)(uVar5 + *(int*)(uVar6 + 8)) * 4);
                        iVar4 = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x80), 0, 0, 0);
                        local_28 = *(uint32_t**)(*(int*)((char*)self + 0x14) + iVar4 * 4);
                        *(int*)(uVar5 + *(int*)(uVar6 + 8)) = iVar4;
                        FUN_0065d501();
                        auStack_3c[3] = *(uint32_t*)(auStack_3c[3] + 0x3c);
                        FUN_0065d501();
                        local_28[4] = (uint32_t)(size_t)local_14;
                        local_28[0xf] = auStack_3c[3];
                        if (*(int*)*local_18 == 0x72d00003 && local_8 == param_4 - 1) {
                            *(uint32_t*)(uVar5 + 0xc + *(int*)(uVar6 + 8)) =
                                *(uint32_t*)(uVar5 + 0xc + ((int*)*local_18)[2]);
                        }
                        local_14 = (int*)((int)(size_t)local_14 + 1);
                        local_20 = local_20 + 4;
                        local_24 = local_24 + 4;
                        uVar5 = uVar5 + 4;
                    } while (uVar5 < 0x18);
                    local_8 = local_8 + 1;
                } while (local_8 < param_4);
            }

            uVar6 = auStack_70[param_4 + 8];
            uVar5 = 0;
            do {
                *(uint32_t*)(uVar5 + *(int*)(uVar6 + 0x10)) =
                    *(uint32_t*)(uVar5 + *(int*)(*local_18 + 0x10));
                uVar5 = uVar5 + 4;
            } while (uVar5 < 0x10);

            uVar6 = 0;
            if (param_4 != 0) {
                do {
                    if (*(int*)(param_3 + auStack_70[uVar6 + 0xd] * 4) != 0) {
                        return cleanup(-0x7fffbffb);
                    }
                    uVar6 = uVar6 + 1;
                } while (uVar6 < param_4);
            }

            iVar4 = *(int*)(*(int*)((char*)self + 0x14) + **(int**)(size_t)(*local_18 + 8) * 4);
            uVar6 = *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x10) + *(int*)(iVar4 + 4) * 4) + 4);
            if (-1 < (int8_t)uVar6) {
                // LAB_0067b35e
                FUN_006626da();
                return cleanup(-0x7fffbffb);
            }
            if ((uVar6 & 0x840) == 0) {
                *(uint32_t*)(iVar4 + 0xc) = auStack_70[param_4 + 0xc];
            } else if (auStack_70[param_4 + 0xc] != *(uint32_t*)(iVar4 + 0xc)) {
                // LAB_0067b3c7
                FUN_006626da();
                return cleanup(-0x7fffbffb);
            }

            local_8 = 0;
            if (param_4 != 0) {
                do {
                    iVar2 = local_8 + 9;
                    *(uint32_t*)(param_3 + auStack_70[local_8 + 0xd] * 4) = auStack_70[iVar2];
                    iVar4 = FUN_0065d8c2();
                    if (iVar4 < 0) {
                        return cleanup(iVar4);
                    }
                    *local_18 = 0;
                    auStack_70[iVar2] = 0;
                    local_8 = local_8 + 1;
                } while (local_8 < param_4);
            }
        }
    }
    iVar4 = 0;
    return cleanup(iVar4);
}

// 0x67b3d2 — observed shape
// Walks the live declaration table, records the per-usage stream maxima into self+0x218 and
// self+0x1f8, and reports DXERROR_INVALIDCALL when required declaration classes are missing.
uint32_t FUN_0067b3d2(void* self)
{
    uint8_t bVar1;
    uint8_t bVar3;
    int iVar2;
    int iVar6;
    uint32_t uVar4;
    uint32_t uVar7;
    uint32_t* puVar5;
    uint32_t* puVar8;
    int local_24[8];

    local_24[0] = 0;
    local_24[1] = 0;
    local_24[2] = 0;
    local_24[3] = 0;
    *(uint32_t*)((char*)self + 0x218) = 0;
    *(uint32_t*)((char*)self + 0x21c) = 0;
    bVar3 = 0;
    puVar8 = (uint32_t*)((char*)self + 0x1f8);
    for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar8 = 0;
        puVar8 = puVar8 + 1;
    }
    local_24[6] = 0;
    local_24[5] = 0;
    local_24[4] = 0;
    local_24[7] = 0;

    if (*(int*)((char*)self + 8) != 0) {
        do {
            iVar6 = *(int*)(*(int*)((char*)self + 0x14) + local_24[7] * 4);
            iVar2 = *(int*)(*(int*)((char*)self + 0x10) + *(int*)(iVar6 + 4) * 4);
            if (*(int*)(iVar6 + 8) != -1 && local_24[6] == 0) {
                FUN_006626da();
                local_24[6] = 1;
                bVar3 = 1;
            }
            uVar4 = *(uint32_t*)(iVar2 + 4);
            if ((uVar4 & 0x20) == 0) {
                if ((uVar4 & 0x10) != 0 && (uVar4 & 0x200) == 0) {
                    uVar4 = (uint32_t)*(uint8_t*)(iVar6 + 0x6d);
                    uVar7 = *(uint32_t*)(iVar6 + 0x6c) & 0xff;
                    if (uVar7 == 1) {
                        if (uVar4 < 2) {
                            puVar5 = (uint32_t*)((char*)self + 0x218 + uVar4 * 4);
                            uint32_t uTmp = *(uint32_t*)(iVar6 + 0x10) + 1;
                            if (*puVar5 < uTmp) {
                                *puVar5 = uTmp;
                            }
                        }
                    } else if (uVar7 == 3 && uVar4 < 8) {
                        puVar5 = (uint32_t*)((char*)self + 0x1f8 + uVar4 * 4);
                        uint32_t uTmp = *(uint32_t*)(iVar6 + 0x10) + 1;
                        if (*puVar5 < uTmp) {
                            *puVar5 = uTmp;
                        }
                    }
                }
            } else {
                bVar1 = *(uint8_t*)(iVar6 + 0x6d);
                if (3 < bVar1) {
                    break;
                }
                uVar4 = *(uint32_t*)(iVar6 + 0x6c) & 0xff;
                if (uVar4 == 1) {
                    if (bVar1 == 0) {
                        local_24[*(int*)(iVar6 + 0x10)] = 1;
                        local_24[4] = *(int*)(iVar6 + 0x60);
                    }
                } else if (uVar4 == 2 && bVar1 == 0 && *(int*)(iVar6 + 0x10) != 0 &&
                           local_24[5] == 0) {
                    FUN_006626da();
                    local_24[5] = 1;
                    bVar3 = 1;
                }
            }
            local_24[7] = local_24[7] + 1;
        } while ((uint32_t)local_24[7] < *(uint32_t*)((char*)self + 8));
    }

    iVar6 = 0;
    uVar4 = 0;
    do {
        iVar6 = iVar6 + (uint32_t)(local_24[uVar4] != 0);
        uVar4 = uVar4 + 1;
    } while (uVar4 < 4);
    if (iVar6 != 4) {
        FUN_006626da();
        bVar3 = 1;
    }
    return (uint32_t)(-(int)bVar3) & 0x80004005u;
}

// 0x67b559 — observed shape
// Rebuilds the declaration objects referenced by self+0x100: remaps the usage stream, clones
// each element record, then rewrites the declaration through FUN_006a4aab.
int FUN_0067b559(void* self)
{
    uint32_t* puVar1;
    int iVar2;
    int* piVar3;
    uint32_t uVar4;
    int iVar5;
    uint32_t* puVar6;
    uint32_t* puVar7;
    uint32_t local_48[4];
    uint32_t local_38[4];
    uint8_t local_28[16];
    int* local_18;
    ptrdiff_t local_14;
    int local_10;
    int* local_c;
    int local_8;

    iVar5 = *(int*)((char*)self + 0x100);
    local_18 = *(int**)(*(int*)((char*)self + 0x100) + 0x10);
    local_8 = *(int*)(*(int*)((char*)self + 0x100) + 0xc);
    uVar4 = 0;
    do {
        *(uint32_t*)((char*)local_48 + uVar4) = *(uint32_t*)(*(int*)(iVar5 + 8) + 0xc);
        *(uint32_t*)((char*)local_38 + uVar4) = *(uint32_t*)(*(int*)(iVar5 + 8) + 0x1c);
        uVar4 = uVar4 + 4;
    } while (uVar4 < 0x10);

    iVar5 = *(int*)(*(int*)((char*)self + 0x14) + *local_18 * 4);
    if (*(int*)(iVar5 + 4) == *(int*)((char*)self + 0x84)) {
        iVar2 = local_8;
        if (*(int*)(iVar5 + 0x6c) != 1) {
            FUN_006626da();
            return -0x7fffbffb;
        }
        for (; iVar2 != 0; iVar2 = iVar2 + -1) {
            *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) + *local_18 * 4) + 0xc) = 0;
            *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) + *local_18 * 4) + 4) =
                *(uint32_t*)((char*)self + 0x88);
        }
    }

    if (local_8 != 0) {
        local_14 = (ptrdiff_t)local_28 - (ptrdiff_t)local_18;
        local_10 = local_8;
        local_c = local_18;
        do {
            piVar3 = local_c;
            iVar5 = FUN_0065d9d5(0, 0, 0, 0);
            local_c = local_c + 1;
            *(int*)(local_14 + (ptrdiff_t)piVar3) = iVar5;
            puVar1 = *(uint32_t**)(*(int*)((char*)self + 0x14) + iVar5 * 4);
            puVar6 = *(uint32_t**)(*(int*)((char*)self + 0x14) + *piVar3 * 4);
            puVar7 = puVar1;
            for (iVar5 = 0x20; iVar5 != 0; iVar5 = iVar5 + -1) {
                *puVar7 = *puVar6;
                puVar6 = puVar6 + 1;
                puVar7 = puVar7 + 1;
            }
            puVar1[0xf] = 0;
            local_10 = local_10 + -1;
        } while (local_10 != 0);
        local_10 = 0;
    }

    piVar3 = local_18;
    iVar5 = *(int*)(*(int*)((char*)self + 0x100) + 8);
    iVar5 = FUN_006a4aab(8, local_28, local_8, iVar5, iVar5 + 0x10, 0, 2, 0, 0, 0, 0);
    if (-1 < iVar5) {
        iVar5 = FUN_006a4aab(4, piVar3, local_8, (void*)local_48, (void*)local_38, local_28, local_8, 0, 0, 0, 0);
    }
    return iVar5;
}

// ---------------------------------------------------------------------------
// Declarations for the declaration-state / device-interface group below.
// ---------------------------------------------------------------------------
// Virtual interface dispatch: the listing calls through the vtable rooted at *self.
// Each call site below names the observed argument shape explicitly.
static inline void* omp_vtbl_entry(void* self, size_t byte_off)
{
    return (*(void***)self)[byte_off / sizeof(void*)];
}

// 0x67b6a6 — observed shape
// Applies one declaration (param_1 selects the update code) to the two usage-stream element
// records of the current declaration, then commits the stream update.
int FUN_0067b6a6(void* self, uint32_t param_1)
{
    uint32_t* puVar1 = *(uint32_t**)((char*)self + 0x100);
    int* piVar2 = (int*)puVar1[2];
    uint32_t uVar5 = *puVar1 & 0xfffff;
    int* piVar6 = (uVar5 != puVar1[1]) ? (int*)0x0 : (piVar2 + uVar5);
    int* piVar3 = (uVar5 * 2 < *(uint32_t*)((char*)puVar1 + 4)) ? (piVar2 + uVar5 * 2) : (int*)0x0;
    uint32_t local_8 = 0;
    uint32_t local_c = 0;
    int iVar4 = FUN_006a48dd(param_1);

    if (-1 < iVar4) {
        param_1 = (uint32_t)*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x14) + *piVar2 * 4) + 0x6d);
        local_8 = param_1 | 0xb0000000u;
        iVar4 = reinterpret_cast<int (*)(uint32_t, uint32_t, uint32_t)>(omp_vtbl_entry(self, 100))(local_8, 0xf0000, 0);
        if (-1 < iVar4) {
            if (piVar6 != (int*)0x0) {
                iVar4 = reinterpret_cast<int (*)(uint32_t, uint32_t*, uint32_t*)>(omp_vtbl_entry(self, 0x74))(
                    *(uint32_t*)(*(int*)((char*)self + 0x14) + *piVar6 * 4), &local_8, &param_1);
                if (iVar4 < 0) {
                    return iVar4;
                }
                iVar4 = reinterpret_cast<int (*)(int*, uint32_t, uint32_t, uint32_t*)>(omp_vtbl_entry(self, 0x78))(
                    piVar6, uVar5, 0xf0000, &local_c);
                if (iVar4 < 0) {
                    return iVar4;
                }
                iVar4 = reinterpret_cast<int (*)(uint32_t, uint32_t, uint32_t)>(omp_vtbl_entry(self, 0x68))(
                    local_8, local_c, param_1);
                if (iVar4 < 0) {
                    return iVar4;
                }
            }
            if (piVar3 != (int*)0x0) {
                iVar4 = reinterpret_cast<int (*)(uint32_t, uint32_t*, uint32_t*)>(omp_vtbl_entry(self, 0x74))(
                    *(uint32_t*)(*(int*)((char*)self + 0x14) + *piVar3 * 4), &local_8, &param_1);
                if (iVar4 < 0) {
                    return iVar4;
                }
                iVar4 = reinterpret_cast<int (*)(int*, uint32_t, uint32_t, uint32_t*)>(omp_vtbl_entry(self, 0x78))(
                    piVar3, uVar5, 0xf0000, &local_c);
                if (iVar4 < 0) {
                    return iVar4;
                }
                iVar4 = reinterpret_cast<int (*)(uint32_t, uint32_t, uint32_t)>(omp_vtbl_entry(self, 0x68))(
                    local_8, local_c, param_1);
                if (iVar4 < 0) {
                    return iVar4;
                }
            }
            iVar4 = reinterpret_cast<int (*)()>(omp_vtbl_entry(self, 0x60))();
            if (-1 < iVar4) {
                iVar4 = FUN_0069fcf5();
                if (-1 < iVar4) {
                    iVar4 = 0;
                }
            }
        }
    }
    return iVar4;
}

// 0x67b7eb — observed shape
// Commits the first usage-stream element of the current declaration (tag 0x42 / 0x9000000).
int FUN_0067b7eb(void* self)
{
    int* piVar1;
    uint32_t uVar2;
    int iVar3;
    uint32_t local_10 = 0;
    uint32_t local_c = 0;
    uint32_t local_8 = 0;

    uVar2 = 0;
    {
        uint32_t* desc = *(uint32_t**)((char*)self + 0x100);
        uVar2 = *desc;
        iVar3 = FUN_006a48dd(0x42);
        if (-1 < iVar3) {
            iVar3 = reinterpret_cast<int (*)(uint32_t, uint32_t*, uint32_t, uint32_t)>(omp_vtbl_entry(self, 0x6c))(
                *(uint32_t*)(*(int*)((char*)self + 0x14) +
                             *reinterpret_cast<int*>(reinterpret_cast<char*>(desc) + 0x10) * 4),
                &local_8, 0, 0);
            if (-1 < iVar3) {
                iVar3 = reinterpret_cast<int (*)(uint32_t, uint32_t, uint32_t)>(omp_vtbl_entry(self, 100))(local_8, 0xf0000, 0);
                if (-1 < iVar3) {
                    piVar1 = (int*)(*(int*)(reinterpret_cast<char*>(desc) + 8) + (uVar2 & 0xfffff) * 4);
                    iVar3 = reinterpret_cast<int (*)(uint32_t, uint32_t*, uint32_t*)>(omp_vtbl_entry(self, 0x74))(
                        *(uint32_t*)(*(int*)((char*)self + 0x14) + *piVar1 * 4), &local_8, &local_c);
                    if (-1 < iVar3) {
                        iVar3 = reinterpret_cast<int (*)(int*, uint32_t, uint32_t, uint32_t*)>(omp_vtbl_entry(self, 0x78))(
                            piVar1, uVar2 & 0xfffff, 0xf0000, &local_10);
                        if (-1 < iVar3) {
                            iVar3 = reinterpret_cast<int (*)(uint32_t, uint32_t, uint32_t)>(omp_vtbl_entry(self, 0x68))(
                                local_8, local_10 | 0x9000000u, local_c);
                            if (-1 < iVar3) {
                                iVar3 = reinterpret_cast<int (*)()>(omp_vtbl_entry(self, 0x60))();
                                if (-1 < iVar3) {
                                    iVar3 = FUN_0069fcf5();
                                    if (-1 < iVar3) {
                                        iVar3 = 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return iVar3;
}

// 0x67b8c6 — observed shape
// Same commit path as 0x67b7eb but with the 0xaf40000 constant in the final blend call.
int FUN_0067b8c6(void* self)
{
    int* piVar1;
    uint32_t uVar2;
    int iVar3;
    uint8_t local_10[4] = { 0 };
    uint32_t local_c = 0;
    uint32_t local_8 = 0;

    {
        uint32_t* desc = *(uint32_t**)((char*)self + 0x100);
        uVar2 = *desc;
        iVar3 = FUN_006a48dd(0x42);
        if (-1 < iVar3) {
            iVar3 = reinterpret_cast<int (*)(uint32_t, uint32_t*, uint32_t, uint32_t)>(omp_vtbl_entry(self, 0x6c))(
                *(uint32_t*)(*(int*)((char*)self + 0x14) +
                             *reinterpret_cast<int*>(reinterpret_cast<char*>(desc) + 0x10) * 4),
                &local_8, 0, 0);
            if (-1 < iVar3) {
                iVar3 = reinterpret_cast<int (*)(uint32_t, uint32_t, uint32_t)>(omp_vtbl_entry(self, 100))(local_8, 0xf0000, 0);
                if (-1 < iVar3) {
                    piVar1 = (int*)(*(int*)(reinterpret_cast<char*>(desc) + 8) + (uVar2 & 0xfffff) * 4);
                    iVar3 = reinterpret_cast<int (*)(uint32_t, uint32_t*, uint32_t*)>(omp_vtbl_entry(self, 0x74))(
                        *(uint32_t*)(*(int*)((char*)self + 0x14) + *piVar1 * 4), &local_8, &local_c);
                    if (-1 < iVar3) {
                        iVar3 = reinterpret_cast<int (*)(int*, uint32_t, uint32_t, void*)>(omp_vtbl_entry(self, 0x78))(
                            piVar1, uVar2 & 0xfffff, 0xf0000, local_10);
                        if (-1 < iVar3) {
                            iVar3 = reinterpret_cast<int (*)(uint32_t, uint32_t, uint32_t)>(omp_vtbl_entry(self, 0x68))(
                                local_8, 0xaf40000u, local_c);
                            if (-1 < iVar3) {
                                iVar3 = reinterpret_cast<int (*)()>(omp_vtbl_entry(self, 0x60))();
                                if (-1 < iVar3) {
                                    iVar3 = FUN_0069fcf5();
                                    if (-1 < iVar3) {
                                        iVar3 = 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return iVar3;
}

// 0x67b998 — observed shape
// Version-gated commit: on D3D 10.4 (self+0xc8 low word == 0x104) also rewrites the element
// range, otherwise only re-binds the stream.
int FUN_0067b998(void* self)
{
    int* piVar1;
    int iVar2;
    uint32_t uVar3;
    uint32_t local_14 = 0;
    uint32_t local_10 = 0;
    uint32_t local_c = 0;
    uint32_t local_8 = 0;

    {
        uint32_t* desc = *(uint32_t**)((char*)self + 0x100);
        uVar3 = *desc & 0xfffff;
        local_c = uVar3;
        if ((*(uint32_t*)((char*)self + 0xc8) & 0xffff) == 0x104) {
            iVar2 = FUN_006a48dd(0x42);
            if (iVar2 < 0) {
                return iVar2;
            }
            iVar2 = reinterpret_cast<int (*)(uint32_t, uint32_t*, uint32_t, uint32_t)>(omp_vtbl_entry(self, 0x6c))(
                *(uint32_t*)(*(int*)((char*)self + 0x14) +
                             *reinterpret_cast<int*>(reinterpret_cast<char*>(desc) + 0x10) * 4),
                &local_8, 0, 0);
            if (iVar2 < 0) {
                return iVar2;
            }
            iVar2 = reinterpret_cast<int (*)(uint32_t, uint32_t, uint32_t)>(omp_vtbl_entry(self, 100))(local_8, 0xf0000, 0);
            if (iVar2 < 0) {
                return iVar2;
            }
            piVar1 = (int*)(*(int*)(reinterpret_cast<char*>(desc) + 8) + uVar3 * 4);
            iVar2 = reinterpret_cast<int (*)(uint32_t, uint32_t*, uint32_t*)>(omp_vtbl_entry(self, 0x74))(
                *(uint32_t*)(*(int*)((char*)self + 0x14) + *piVar1 * 4), &local_8, &local_10);
            if (iVar2 < 0) {
                return iVar2;
            }
            iVar2 = reinterpret_cast<int (*)(int*, uint32_t, uint32_t, uint32_t*)>(omp_vtbl_entry(self, 0x78))(
                piVar1, local_c, 0xf0000, &local_14);
            if (iVar2 < 0) {
                return iVar2;
            }
            iVar2 = reinterpret_cast<int (*)(uint32_t, uint32_t, uint32_t)>(omp_vtbl_entry(self, 0x68))(
                local_8, local_14, local_10);
            if (iVar2 < 0) {
                return iVar2;
            }
            iVar2 = reinterpret_cast<int (*)()>(omp_vtbl_entry(self, 0x60))();
        } else {
            iVar2 = FUN_006a48dd(0x42);
            if (iVar2 < 0) {
                return iVar2;
            }
            iVar2 = reinterpret_cast<int (*)(uint32_t, uint32_t*, uint32_t, uint32_t)>(omp_vtbl_entry(self, 0x6c))(
                *(uint32_t*)(*(int*)((char*)self + 0x14) +
                             *reinterpret_cast<int*>(reinterpret_cast<char*>(desc) + 0x10) * 4),
                &local_8, 0, 0);
            if (iVar2 < 0) {
                return iVar2;
            }
            iVar2 = reinterpret_cast<int (*)(uint32_t, uint32_t, uint32_t)>(omp_vtbl_entry(self, 100))(local_8, 0xf0000, 0);
            if (iVar2 < 0) {
                return iVar2;
            }
            iVar2 = reinterpret_cast<int (*)()>(omp_vtbl_entry(self, 0x60))();
        }
    }
    if (-1 < iVar2) {
        iVar2 = 0;
    }
    return iVar2;
}

// 0x67bae9 — observed shape
// Stream/declaration re-bind path (tag 0x40); on D3D 10.4 also resolves the element block and
// patches the usage record, then commits with 0xe40000.
int FUN_0067bae9(void* self)
{
    int* piVar2;
    int iVar3;
    uint32_t uVar4;
    uint8_t local_18[4] = { 0 };
    uint32_t local_14 = 0;
    uint32_t local_10 = 0;
    uint32_t local_c = 0;
    uint32_t local_8 = 0;

    {
        uint32_t* desc = *(uint32_t**)((char*)self + 0x100);
        uint32_t uVar1 = *(uint32_t*)(*(int*)((char*)self + 0x14) +
                                      *reinterpret_cast<int*>(reinterpret_cast<char*>(desc) + 0x10) * 4);
        uVar4 = *desc & 0xfffff;
        if ((*(uint32_t*)((char*)self + 0xc8) & 0xffff) == 0x104) {
            iVar3 = FUN_006a48dd(0x40);
            if (iVar3 < 0) {
                return iVar3;
            }
            iVar3 = reinterpret_cast<int (*)(uint32_t, uint32_t*, uint32_t, uint32_t*)>(omp_vtbl_entry(self, 0x6c))(
                uVar1, &local_8, 0, &local_c);
            if (iVar3 < 0) {
                return iVar3;
            }
            iVar3 = reinterpret_cast<int (*)(uint32_t, uint32_t, uint32_t*, uint32_t)>(omp_vtbl_entry(self, 0x70))(
                *(uint32_t*)(reinterpret_cast<char*>(desc) + 0x10), uVar4, &local_10, local_c);
            if (iVar3 < 0) {
                return iVar3;
            }
            iVar3 = reinterpret_cast<int (*)(uint32_t, uint32_t, uint32_t)>(omp_vtbl_entry(self, 100))(local_8, 0x70000, 0);
            if (iVar3 < 0) {
                return iVar3;
            }
            piVar2 = *(int**)(reinterpret_cast<char*>(desc) + 8);
            iVar3 = reinterpret_cast<int (*)(uint32_t, uint32_t*, uint32_t*)>(omp_vtbl_entry(self, 0x74))(
                *(uint32_t*)(*(int*)((char*)self + 0x14) + *piVar2 * 4), &local_8, &local_14);
            if (iVar3 < 0) {
                return iVar3;
            }
            iVar3 = reinterpret_cast<int (*)(int*, uint32_t, uint32_t, void*)>(omp_vtbl_entry(self, 0x78))(
                piVar2, uVar4, local_10, local_18);
            if (iVar3 < 0) {
                return iVar3;
            }
            iVar3 = reinterpret_cast<int (*)(uint32_t, uint32_t, uint32_t)>(omp_vtbl_entry(self, 0x68))(
                local_8, 0xe40000u, local_14);
        } else {
            iVar3 = FUN_006a48dd(0x40);
            if (iVar3 < 0) {
                return iVar3;
            }
            iVar3 = reinterpret_cast<int (*)(uint32_t, uint32_t*, uint32_t, uint32_t*)>(omp_vtbl_entry(self, 0x6c))(
                uVar1, &local_8, 0, &local_c);
            if (iVar3 < 0) {
                return iVar3;
            }
            iVar3 = reinterpret_cast<int (*)(uint32_t, uint32_t, uint32_t*, uint32_t)>(omp_vtbl_entry(self, 0x70))(
                *(uint32_t*)(reinterpret_cast<char*>(desc) + 0x10), uVar4, &local_10, local_c);
            if (iVar3 < 0) {
                return iVar3;
            }
            iVar3 = reinterpret_cast<int (*)(uint32_t, uint32_t, uint32_t)>(omp_vtbl_entry(self, 100))(local_8, 0xf0000, 0);
        }
    }
    if (-1 < iVar3 && (iVar3 = reinterpret_cast<int (*)()>(omp_vtbl_entry(self, 0x60))(), -1 < iVar3) &&
        (iVar3 = FUN_0069fcf5(), -1 < iVar3)) {
        iVar3 = 0;
    }
    return iVar3;
}

// 0x67bc3a — observed shape
// ORs the 0x40000000 ("SRGB"/flag) bit into the usage value when the declaration state
// at self+0x100 has its +0x24 field equal to 1.
uint32_t FUN_0067bc3a(void* self, uint32_t param_1)
{
    if (*(int*)(*(int*)((char*)self + 0x100) + 0x24) == 1) {
        param_1 = param_1 | 0x40000000u;
    }
    return param_1;
}

// 0x67bc7a — observed shape
// Resolves the stream slot index for one element record: usage class 1 indexes the
// self+0x28 limit, usage class 3 the self+0x3c limit (offset by 2), class 5 maps to slot 0xc.
uint32_t FUN_0067bc7a(void* self, int param_1, uint32_t* param_2)
{
    uint32_t uVar2 = (uint32_t)*(uint8_t*)(param_1 + 0x6d);
    uint32_t uVar1 = *(uint32_t*)(param_1 + 0x6c) & 0xff;

    if (uVar1 == 1) {
        if (*(uint32_t*)((char*)self + 0x28) <= uVar2) {
            return 0x80004005;
        }
    } else {
        if (uVar1 != 3) {
            if (uVar1 == 5) {
                *param_2 = 0xc;
                return 0;
            }
            return 0x80004005;
        }
        if (*(uint32_t*)((char*)self + 0x3c) <= uVar2) {
            return 0x80004005;
        }
        uVar2 = uVar2 + 2;
    }
    *param_2 = uVar2;
    return 0;
}

// 0x67bcc9 — observed shape
// Returns the stream slot and the packing width for one element record.
uint32_t FUN_0067bcc9(void* self, int param_1, uint32_t* param_2, uint32_t* param_3)
{
    uint8_t bVar1;
    uint32_t uVar2;
    uint32_t uVar3;

    uVar2 = *(uint32_t*)(param_1 + 0x6c);
    bVar1 = *(uint8_t*)(param_1 + 0x6d);
    *param_2 = (uint32_t)bVar1;
    uVar2 = uVar2 & 0xff;
    uVar3 = 1;
    if (uVar2 == 1) {
        uVar2 = *(uint32_t*)((char*)self + 0x28);
    } else {
        uVar3 = 3;
        if (uVar2 != 3) {
            return 0x80004005;
        }
        uVar2 = *(uint32_t*)((char*)self + 0x3c);
    }
    if (bVar1 < uVar2) {
        *param_3 = uVar3;
        return 0;
    }
    return 0x80004005;
}

// 0x67c181 — observed shape
// Specialised (attribute-less) element query: only usage classes 1 and 2 with a zero index
// are accepted, returning the fixed (slot,width) pair 0/0 or 9/1.
uint32_t FUN_0067c181(int param_1, uint32_t* param_2, uint32_t* param_3, uint32_t* param_4)
{
    uint32_t uVar1;
    uint32_t uVar2;

    uVar1 = *(uint32_t*)(param_1 + 0x6c);
    uVar2 = (uint32_t)*(uint8_t*)(param_1 + 0x6d);
    *param_2 = uVar2;
    uVar1 = uVar1 & 0xff;
    if (uVar1 == 1) {
        if (uVar2 != 0) {
            return 0x80004005;
        }
        *param_3 = 0;
        if (param_4 != (uint32_t*)0x0) {
            *param_4 = 0;
        }
    } else {
        if (uVar1 != 2) {
            return 0x80004005;
        }
        if (uVar2 != 0) {
            return 0x80004005;
        }
        *param_3 = 9;
        if (param_4 != (uint32_t*)0x0) {
            *param_4 = 1;
        }
    }
    return 0;
}

// 0x67c1df — observed shape
// Counts the declaration elements into per-slot buckets (limits 2/3/2/1 for slots
// self+0x80/0x88/0x7c/0x94), rejecting declarations that exceed a bucket or repeat the
// special 0x60f00000/0x60500000/0x60a00000/0x60000000 pattern more than twice.
uint32_t FUN_0067c1df(void* self, uint32_t* param_1, uint32_t* param_2)
{
    int iVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    int* piVar5;
    uint32_t* puVar6;
    char cVar7;
    int* piVar9;
    uint32_t uVar10;
    uint32_t uVar11;
    bool bVar12;
    uint32_t auStack_b0[19];
    uint32_t auStack_68[19];
    uint32_t local_1c;
    int* local_14;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;

    (void)bVar12;
    if (param_1 == (uint32_t*)0x0) {
        return 1;
    }

    uVar11 = *param_1 & 0xfff00000u;
    if (uVar11 == 0 || uVar11 == 0x20700000u) {
        return 0;
    }

    local_c = *param_1 & 0xfffff;
    local_1c = param_1[1] / local_c;
    if (1 < local_1c) {
        iVar1 = *(int*)((char*)self + 0x80);
        iVar2 = *(int*)((char*)self + 0x88);
        iVar3 = *(int*)((char*)self + 0x7c);
        iVar4 = *(int*)((char*)self + 0x94);
        local_8 = 0;
        auStack_68[iVar1] = 0;
        auStack_68[iVar2] = 0;
        auStack_68[iVar3] = 0;
        auStack_68[iVar4] = 0;
        auStack_b0[iVar1] = 2;
        auStack_b0[iVar2] = 3;
        auStack_b0[iVar3] = 2;
        auStack_b0[iVar4] = 1;
        local_10 = 0;
        if (local_1c != 0) {
            piVar5 = (int*)param_1[2];
            local_14 = piVar5;
            do {
                iVar1 = *(int*)(*(int*)((char*)self + 0x14) + *local_14 * 4);
                param_1 = (uint32_t*)0x0;
                uVar11 = *(uint32_t*)(iVar1 + 4);
                if (local_10 != 0) {
                    piVar9 = piVar5;
                    do {
                        iVar2 = *(int*)(*(int*)((char*)self + 0x14) + *piVar9 * 4);
                        if (uVar11 == *(uint32_t*)(iVar2 + 4) &&
                            *(int*)(iVar1 + 8) == *(int*)(iVar2 + 8) &&
                            *(int*)(iVar1 + 0xc) == *(int*)(iVar2 + 0xc) &&
                            ((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) + uVar11 * 4) + 5) & 1) == 0 ||
                             (*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) + *(int*)(iVar2 + 4) * 4) + 5) & 1) == 0 ||
                             *(double*)(iVar1 + 0x20) == *(double*)(iVar2 + 0x20))) {
                            break;
                        }
                        param_1 = (uint32_t*)((int)(size_t)param_1 + 1);
                        piVar9 = piVar9 + local_c;
                    } while ((uint32_t)(size_t)param_1 < local_10);
                }
                if ((uint32_t)(size_t)param_1 == local_10) {
                    if (uVar11 == *(uint32_t*)((char*)self + 0x80)) {
                        uVar10 = *(uint32_t*)((char*)self + 0x80);
                        if (*(char*)(iVar1 + 0x6c) == 3) {
                            if ((*(uint32_t*)((char*)self + 200) & 0xffff) == 0x101) {
                                local_8 = local_8 + 1;
                                if (local_8 > 2 && param_2 == (uint32_t*)0x0) {
                                    return 1;
                                }
                            }
                            uVar10 = *(uint32_t*)((char*)self + 0x88);
                        }
                    } else {
                        uVar10 = *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x10) + uVar11 * 4) + 4);
                        cVar7 = (char)uVar10;
                        if ((uVar10 & 0x200) == 0) {
                            if (cVar7 < 0) {
                                uVar10 = *(uint32_t*)((char*)self + 0x94);
                            } else {
                                uVar10 = uVar11;
                            }
                        } else if (cVar7 < 0) {
                            uVar10 = *(uint32_t*)((char*)self + 0x94);
                        } else {
                            uVar10 = *(uint32_t*)((char*)self + 0x7c);
                        }
                    }
                    if (*(int*)(iVar1 + 0x48) != -1 && uVar11 == *(uint32_t*)((char*)self + 0x88) &&
                        (*(uint32_t*)((char*)self + 200) & 0xffff) == 0x101) {
                        puVar6 = *(uint32_t**)(*(int*)((char*)self + 0x18) + *(int*)(iVar1 + 0x48) * 4);
                        if (puVar6 != (uint32_t*)0x0) {
                            uVar11 = *puVar6 & 0xfff00000u;
                            if (uVar11 == 0x60f00000u || uVar11 == 0x60500000u ||
                                uVar11 == 0x60a00000u || uVar11 == 0x60000000u) {
                                local_8 = local_8 + 1;
                                if (local_8 > 2 && param_2 == (uint32_t*)0x0) {
                                    return 1;
                                }
                            }
                        }
                        uVar10 = *(uint32_t*)((char*)self + 0x88);
                    }
                    if (uVar10 < 0x12) {
                        puVar6 = auStack_68 + uVar10;
                        *puVar6 = *puVar6 + 1;
                        if (auStack_b0[uVar10] < *puVar6) {
                            if (param_2 != (uint32_t*)0x0) {
                                *param_2 = local_10;
                            }
                            return 1;
                        }
                    }
                }
                local_14 = local_14 + local_c;
                local_10 = local_10 + 1;
            } while (local_10 < local_1c);
        }
    }
    return 0;
}

// 0x67c441 — observed shape
// Sorts/absorbs declaration entries: resets each entry's +0x24 marker, then for each non-null
// entry finds the next non-null entry and merges it when the two declarations overlap.
uint32_t FUN_0067c441(void* self, int param_1, int* param_2, uint32_t param_3, int* param_4)
{
    bool bVar1;
    bool bVar2;
    bool bVar3;
    int iVar4;
    uint32_t uVar5;
    int* piVar6;
    uint32_t uVar7;
    uint32_t uVar8;
    uint32_t* puVar9 = (uint32_t*)0x0;
    uint32_t* puVar10 = (uint32_t*)0x0;
    uint32_t* puVar11;
    uint32_t local_18 = 0;
    uint32_t local_14 = 0;
    int* local_c = (int*)0x0;
    bool doBody = false;

    if (param_4 != (int*)0x0) {
        *param_4 = 0;
    }
    if (param_3 != 0) {
        if (param_4 == (int*)0x0) {
            for (uVar7 = (uint32_t)(size_t)param_2; uVar7 < param_3; uVar7 = uVar7 + 1) {
                iVar4 = *(int*)(param_1 + uVar7 * 4);
                if (iVar4 != 0) {
                    *(uint32_t*)(iVar4 + 0x24) = 0;
                }
            }
        }
        uVar7 = (uint32_t)(size_t)param_2;
        if ((uint32_t)(size_t)param_2 < param_3 - 1) {
            do {
                puVar11 = *(uint32_t**)(param_1 + uVar7 * 4);
                uVar8 = uVar7;
                if (puVar11 != (uint32_t*)0x0) {
                    puVar9 = (uint32_t*)0x0;
                    if (param_4 != (int*)0x0) {
                        *param_4 = *param_4 + 1;
                    }
                    do {
                        if (param_3 - 1 <= uVar7) {
                            break;
                        }
                        uVar7 = uVar7 + 1;
                        puVar9 = *(uint32_t**)(param_1 + uVar7 * 4);
                    } while (puVar9 == (uint32_t*)0x0);

                    bVar3 = false;
                    uVar8 = uVar7 - 1;
                    doBody = false;
                    if (puVar9 != (uint32_t*)0x0) {
                        bVar1 = false;
                        if (param_4 == (int*)0x0) {
                            puVar11[9] = 0;
                            puVar9[9] = 0;
                        }
                        if ((*puVar11 & 0xfffff) == 1 && (*puVar9 & 0xfffff) < 4) {
                            bVar1 = true;
                            puVar10 = puVar11;
                            puVar11 = puVar9;
                            doBody = true;
                        } else if ((*puVar11 & 0xfffff) != 4) {
                            puVar10 = puVar9;
                            if ((*puVar9 & 0xfffff) == 1) {
                                doBody = true;
                            }
                        }

                        if (doBody) {
                            if ((*(uint32_t*)((char*)self + 0xc8) & 0xffff) != 0x104) {
                                iVar4 = reinterpret_cast<int (*)(uint32_t*, uint32_t*)>(
                                            omp_vtbl_entry(self, 0xa4))(puVar11, puVar10);
                                if (iVar4 != 0) {
                                    goto next_entry;
                                }
                            }
                            uVar5 = *puVar11 & 0xfff00000u;
                            if (!(uVar5 == 0x72100000u || uVar5 == 0x72000000u ||
                                  uVar5 == 0x60500000u || uVar5 == 0x60a00000u ||
                                  uVar5 == 0x60000000u || uVar5 == 0x60f00000u ||
                                  uVar5 == 0x11000000u || uVar5 == 0)) {
                                bVar2 = false;
                                if (puVar11[3] != 0) {
                                    local_c = (int*)(size_t)puVar11[4];
                                    local_18 = puVar11[3];
                                    do {
                                        iVar4 = *local_c;
                                        if (*(int*)(*(int*)(*(int*)((char*)self + 0x14) + iVar4 * 4) + 0x10) == 3) {
                                            bVar3 = true;
                                        }
                                        if (puVar10[1] != 0) {
                                            param_2 = (int*)(size_t)puVar10[2];
                                            local_14 = puVar10[1];
                                            do {
                                                if (*(int*)(*(int*)(*(int*)((char*)self + 0x14) + *param_2 * 4) + 0x38) == iVar4 ||
                                                    *param_2 == iVar4) {
                                                    bVar2 = true;
                                                }
                                                param_2 = param_2 + 1;
                                                local_14 = local_14 - 1;
                                            } while (local_14 != 0);
                                        }
                                        local_c = local_c + 1;
                                        local_18 = local_18 - 1;
                                    } while (local_18 != 0);
                                }
                                param_2 = (int*)0x0;
                                if (puVar10[3] != 0) {
                                    do {
                                        if (puVar11[1] != 0) {
                                            local_18 = puVar11[1];
                                            iVar4 = *(int*)(puVar10[4] + (int)(size_t)param_2 * 4);
                                            piVar6 = (int*)(size_t)puVar11[2];
                                            do {
                                                if (*(int*)(*(int*)(*(int*)((char*)self + 0x14) + *piVar6 * 4) + 0x38) == iVar4 ||
                                                    *piVar6 == iVar4) {
                                                    bVar2 = true;
                                                }
                                                piVar6 = piVar6 + 1;
                                                local_18 = local_18 - 1;
                                            } while (local_18 != 0);
                                        }
                                        param_2 = (int*)((int)(size_t)param_2 + 1);
                                    } while ((uint32_t)(size_t)param_2 < puVar10[3]);
                                }
                                if (!bVar2 && !bVar3 &&
                                    *(int*)(*(int*)(*(int*)((char*)self + 0x14) + *(int*)(size_t)puVar10[4] * 4) + 0x10) == 3) {
                                    uVar8 = uVar7;
                                    if (param_4 == (int*)0x0) {
                                        if (bVar1) {
                                            puVar11[9] = 1;
                                        } else {
                                            puVar10[9] = 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            next_entry:
                uVar7 = uVar8 + 1;
            } while (uVar7 < param_3 - 1);
        }
        if (uVar7 != param_3 && param_4 != (int*)0x0) {
            *param_4 = *param_4 + 1;
        }
    }
    return 0;
}

// 0x67c6bd — observed shape
// Counts the merged declaration elements of two declarations into per-slot buckets
// (limits 2/5/3 for slots self+0x80/0x88/0x7c) and rejects overflow / unsupported vertex
// element flags.
uint32_t FUN_0067c6bd(void* self, uint32_t* param_1, uint32_t* param_2)
{
    int iVar1;
    uint32_t uVar2;
    int iVar4;
    int iVar5;
    uint32_t* puVar6;
    uint32_t uVar7;
    uint32_t uVar8;
    bool bVar9;
    bool bVar10;
    uint32_t auStack_cc[19];
    uint32_t auStack_84[19];
    int local_3c;
    uint32_t local_38;
    int local_34;
    int local_30;
    int local_2c;
    int local_28;
    int local_24;
    uint32_t local_20;
    uint32_t local_1c;
    int local_18;
    uint32_t local_14;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;

    if (param_1 == (uint32_t*)0x0) {
        return 1;
    }
    if ((*param_1 & 0xfff00000u) == 0) {
        return 0;
    }

    local_10 = *param_1 & 0xfffff;
    local_8 = 0;
    local_c = 0;
    local_1c = 0;
    local_20 = param_1[1] / local_10;
    uVar8 = param_2[1];
    uVar7 = *param_2 & 0xfffff;
    iVar4 = *(int*)((char*)self + 0x80);
    iVar1 = *(int*)((char*)self + 0x88);
    auStack_84[iVar4] = 0;
    auStack_84[iVar1] = 0;
    iVar5 = *(int*)((char*)self + 0x7c);
    auStack_84[iVar5] = 0;
    auStack_cc[iVar4] = 2;
    uVar2 = local_20;
    auStack_cc[iVar1] = 5;
    auStack_cc[iVar5] = 3;
    local_38 = uVar8 / uVar7 + uVar2;
    if (local_38 != 0) {
        local_18 = 0;
        local_28 = local_10 << 2;
        local_2c = uVar7 * uVar2 * -4;
        local_30 = uVar7 << 2;
        local_3c = local_2c;
        do {
            if (local_8 < local_20) {
                iVar4 = *(int*)(local_18 + param_1[2]);
            } else {
                iVar4 = *(int*)(local_2c + param_2[2]);
            }
            iVar4 = *(int*)(*(int*)((char*)self + 0x14) + iVar4 * 4);
            iVar1 = *(int*)(iVar4 + 4);
            local_34 = *(int*)(*(int*)((char*)self + 0x10) + iVar1 * 4);
            local_14 = 0;
            if (local_8 != 0) {
                local_10 = 0;
                local_24 = local_3c;
                do {
                    if (local_14 < local_20) {
                        puVar6 = param_1;
                        uVar8 = local_10;
                    } else {
                        puVar6 = param_2;
                        uVar8 = local_24;
                    }
                    iVar5 = *(int*)(*(int*)((char*)self + 0x14) + *(int*)(uVar8 + puVar6[2]) * 4);
                    if (iVar1 == *(int*)(iVar5 + 4) &&
                        *(int*)(iVar4 + 8) == *(int*)(iVar5 + 8) &&
                        *(int*)(iVar4 + 0xc) == *(int*)(iVar5 + 0xc)) {
                        break;
                    }
                    local_24 = local_24 + local_30;
                    local_14 = local_14 + 1;
                    local_10 = local_10 + local_28;
                } while (local_14 < local_8);
            }
            if (local_14 == local_8) {
                if (iVar1 == *(int*)((char*)self + 0x88) && 1 < *(uint32_t*)(iVar4 + 0xc)) {
                    local_c = local_c + 1;
                    if (local_c > 3) {
                        return 1;
                    }
                }
                iVar5 = *(int*)((char*)self + 0x80);
                if (iVar1 == iVar5) {
                    if (*(char*)(iVar4 + 0x6c) == 3) {
                        if ((*(uint32_t*)((char*)self + 200) & 0xffff) == 0x101) {
                            local_c = local_c + 1;
                            if (local_c > 3) {
                                return 1;
                            }
                        }
                        iVar5 = *(int*)((char*)self + 0x88);
                    }
                    puVar6 = auStack_84 + iVar5;
                    *puVar6 = *puVar6 + 1;
                    bVar9 = *puVar6 < auStack_cc[iVar5];
                    bVar10 = *puVar6 == auStack_cc[iVar5];
                } else {
                    uVar8 = *(uint32_t*)(local_34 + 4);
                    if ((char)uVar8 < 0) {
                        break;
                    }
                    if ((uVar8 & 0x200) == 0) {
                        iVar4 = *(int*)(iVar4 + 4);
                        puVar6 = auStack_84 + iVar4;
                        *puVar6 = *puVar6 + 1;
                        bVar9 = *puVar6 < auStack_cc[iVar4];
                        bVar10 = *puVar6 == auStack_cc[iVar4];
                    } else {
                        local_1c = local_1c + 1;
                        bVar9 = local_1c < 3;
                        bVar10 = local_1c == 3;
                    }
                }
                if (!bVar9 && !bVar10) {
                    return 1;
                }
            }
            local_8 = local_8 + 1;
            local_18 = local_18 + local_28;
            local_2c = local_2c + local_30;
        } while (local_8 < local_38);
    }
    return 0;
}

// 0x67ca57 — observed shape
// Destructor: reinstates the vtable, releases the two name tables, frees the 16 cached
// pointers at self+0x2c4, then the two ownership arrays and the base object state.
extern void FUN_00615a4f(int a);
extern void FUN_006a0238(void);
extern void operator_delete(void* p);
extern void* PTR_FUN_006ef628;

void FUN_0067ca57(void* self)
{
    uint32_t* in_ECX = (uint32_t*)self;
    int iVar1;
    uint32_t uVar2;
    uint32_t* piVar3;

    *(void**)in_ECX = (void*)&PTR_FUN_006ef628;
    operator_delete((void*)(size_t)in_ECX[0x8b]);
    operator_delete((void*)(size_t)in_ECX[0x8c]);

    uVar2 = 0;
    if (in_ECX[0xad] != 0 && in_ECX[0xb0] != 0) {
        do {
            if (*(int*)(in_ECX[0xad] + uVar2 * 4) != 0) {
                FUN_00614343((void*)1);
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < in_ECX[0xb0]);
    }

    uVar2 = 0;
    if (in_ECX[0xae] != 0 && in_ECX[0xaf] != 0) {
        do {
            if (*(int*)(in_ECX[0xae] + uVar2 * 4) != 0) {
                FUN_00615a4f(1);
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < in_ECX[0xaf]);
    }

    piVar3 = in_ECX + 0xb1;
    iVar1 = 0x10;
    do {
        if (*piVar3 != 0) {
            FUN_00614343((void*)1);
        }
        *piVar3 = 0;
        piVar3 = piVar3 + 1;
        iVar1 = iVar1 + -1;
    } while (iVar1 != 0);

    operator_delete((void*)(size_t)in_ECX[0xad]);
    operator_delete((void*)(size_t)in_ECX[0xae]);
    FUN_006a0238();
}

extern void     FUN_00678a8e(uint32_t a, uint32_t b, uint32_t c, int* d, int e,
                             int* f, int* g, int* h);
extern void     FUN_006788f0(uint32_t a, uint32_t b, uint32_t c, uint32_t d,
                             uint32_t e, int* f, uint32_t* g);
extern int      FUN_00673ec4(void);
extern uint32_t FUN_0065d35e(void);
extern int      FUN_0065cc50(void);

// 0x67cbd8 — observed shape
// Rebuilds the declaration list: clears per-element markers, stamps usage indices, then for
// each unprocessed declaration allocates the replacement declaration/usage records, resolves
// overlapping declarations and appends them to the table at self+0x230.
int FUN_0067cbd8(void* self)
{
    uint32_t uVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    int iVar8;
    int* piVar5;
    uint32_t uVar6;
    uint32_t* puVar7;
    uint32_t uVar9;
    int local_108[32];
    int aiStack_88[4];
    int aiStack_78[4];
    int local_68[9];
    int local_44 = 0;
    int local_40 = 0;
    int local_3c = 0;
    int local_38 = 0;
    int local_34 = 0;
    uint32_t local_30 = 0;
    int local_2c = 0;
    uint32_t local_28 = 0;
    int* local_24 = (int*)0x0;
    uint32_t* local_20 = (uint32_t*)0x0;
    int local_1c = 0;
    uint32_t local_18 = 0;
    uint32_t* local_14 = (uint32_t*)0x0;
    uint32_t local_10 = 0;
    int local_c = 0;
    int local_8 = 0;
    bool shared;

    uVar9 = 0;
    uVar6 = 0;
    local_24 = (int*)0x0;
    local_1c = 0;

    if (*(int*)((char*)self + 8) != 0) {
        do {
            iVar3 = *(int*)(*(int*)((char*)self + 0x14) + uVar6 * 4);
            *(uint32_t*)(iVar3 + 0x30) = 0;
            if (*(int*)(iVar3 + 4) == *(int*)((char*)self + 0x88)) {
                *(uint32_t*)(iVar3 + 0xc) = 0xffffffff;
            }
            uVar6 = uVar6 + 1;
        } while (uVar6 < *(uint32_t*)((char*)self + 8));
    }

    for (uVar6 = *(uint32_t*)((char*)self + 0x4c), uVar9 = 0;
         uVar6 < *(uint32_t*)((char*)self + 0x224); uVar6 = uVar6 + 1) {
        piVar5 = *(int**)(*(int*)((char*)self + 0x230) + uVar6 * 4);
        if (piVar5 != (int*)0x0 && *piVar5 != 0 && piVar5[3] != 0) {
            do {
                iVar3 = (int)uVar9 * 4;
                uVar9 = uVar9 + 1;
                *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) + *(int*)(piVar5[4] + iVar3) * 4) + 0x48) = uVar6;
            } while (uVar9 < (uint32_t)piVar5[3]);
        }
    }

    local_30 = *(uint32_t*)((char*)self + 0x224);
    local_28 = *(uint32_t*)((char*)self + 0x4c);
    if (local_28 < local_30) {
        do {
            local_14 = *(uint32_t**)(*(int*)((char*)self + 0x230) + local_28 * 4);
            if (local_14 != (uint32_t*)0x0 && *local_14 != 0) {
                iVar3 = FUN_0065d0b4();
                local_1c = (iVar3 == 0) ? 0 : FUN_0065cc1a(iVar3);
                if (local_1c != 0) {
                    local_18 = FUN_0065d35e();
                    puVar7 = local_14;
                    if ((int)local_18 < 0) {
                        goto LAB_0067d4d0;
                    }
                    if (*(uint32_t*)((char*)self + 0x224) < 0x200) {
                        local_34 = 0;
                        local_40 = 0;
                        shared = false;

                        if ((*local_14 & 0xfff00000u) == 0x50000000u && local_14[3] == 1) {
                            local_20 = *(uint32_t**)(*(int*)((char*)self + 0x14) + *(int*)(size_t)local_14[4] * 4);
                            if (local_20[4] == 3) {
                                FUN_00678a8e(*(uint32_t*)((char*)self + 0x230), local_28, local_30,
                                             (int*)(size_t)local_14[4], 1, &local_2c, &local_3c,
                                             local_68 + 8);
                                if (local_68[8] != 0) {
                                    iVar3 = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x88), 0, 3, 0);
                                    if (iVar3 == -1) {
                                        goto LAB_0067d4a5;
                                    }
                                    iVar4 = *(int*)(*(int*)((char*)self + 0x14) + iVar3 * 4);
                                    FUN_0065d501();
                                    uVar1 = *(uint32_t*)((char*)self + 0x88);
                                    *(uint32_t*)(iVar4 + 0x3c) = 0;
                                    *(uint32_t*)(iVar4 + 4) = uVar1;
                                    *(uint32_t*)(iVar4 + 0x10) = 3;
                                    iVar4 = FUN_0065d0b4();
                                    iVar4 = (iVar4 == 0) ? 0 : FUN_0065cc1a(iVar4);
                                    if (iVar4 == 0) {
                                        goto LAB_0067d4a5;
                                    }
                                    local_18 = FUN_0065d0ff(0x10000001u, 1, 1, 0);
                                    if ((int)local_18 < 0) {
                                        goto LAB_0067d4c9;
                                    }
                                    local_18 = FUN_0065cc50();
                                    if ((int)local_18 < 0) {
                                        goto LAB_0067d4c9;
                                    }
                                    **(uint32_t**)(size_t)(iVar4 + 0x10) = *(uint32_t*)(size_t)local_14[4];
                                    **(int**)(size_t)(iVar4 + 8) = iVar3;
                                    **(int**)(size_t)(local_1c + 0x10) = iVar3;
                                    *(int*)(*(int*)((char*)self + 0x230) + *(int*)((char*)self + 0x224) * 4) = local_1c;
                                    *(int*)((char*)self + 0x224) = *(int*)((char*)self + 0x224) + 1;
                                    local_2c = local_1c;
                                    iVar3 = FUN_0065d8c2();
                                    if (iVar3 < 0 || 0x1ff < *(uint32_t*)((char*)self + 0x224)) {
                                        goto LAB_0067d4a5;
                                    }
                                    *(int*)(*(int*)((char*)self + 0x230) + *(uint32_t*)((char*)self + 0x224) * 4) = iVar4;
                                    *(int*)((char*)self + 0x224) = *(int*)((char*)self + 0x224) + 1;
                                    iVar3 = FUN_0065d8c2();
                                    if (iVar3 < 0) {
                                        goto LAB_0067d4a5;
                                    }
                                    puVar7 = local_14;
                                    shared = true;
                                }
                            }
                        }

                        if (!shared) {
                            bool pushExisting = false;
                            if ((*local_14 & 0xfff00000u) != 0x10000000u || FUN_00673ec4() == 0) {
                                pushExisting = true;
                            } else {
                                uVar6 = puVar7[3];
                                local_34 = 1;
                                if (uVar6 != 0) {
                                    piVar5 = (int*)(size_t)puVar7[4];
                                    do {
                                        if (*(int*)(*(int*)(*(int*)((char*)self + 0x14) + *piVar5 * 4) + 0x3c) != 0) {
                                            local_34 = 0;
                                        }
                                        piVar5 = piVar5 + 1;
                                        uVar6 = uVar6 - 1;
                                    } while (uVar6 != 0);
                                    if (local_34 == 0) {
                                        pushExisting = true;
                                    }
                                }
                                if (!pushExisting) {
                                    FUN_00614343((void*)0);   // listing forwards no argument here
                                    local_2c = 0;
                                }
                            }
                            if (pushExisting) {
LAB_0067ce95:
                                iVar3 = FUN_0065d8c2();
                                if (iVar3 < 0) {
                                    goto LAB_0067d4a5;
                                }
                                *(int*)(*(int*)((char*)self + 0x230) + *(int*)((char*)self + 0x224) * 4) = local_1c;
                                *(int*)((char*)self + 0x224) = *(int*)((char*)self + 0x224) + 1;
                                local_2c = local_1c;
                            }
                            puVar7 = local_14;   // LAB_0067ce4a

                        }

                        local_1c = 0;
                        iVar3 = FUN_00673ec4();
                        if (iVar3 != 0) {
                            local_20 = (uint32_t*)0x0;
                            local_10 = 0;
                            local_68[4] = -1;
                            local_68[5] = -1;
                            local_68[6] = -1;
                            local_68[7] = -1;
                            uVar6 = 0;
                            if (puVar7[3] != 0) {
                                iVar3 = *(int*)((char*)self + 0x14);
                                do {
                                    iVar8 = (int)local_10 * 4;
                                    iVar4 = *(int*)(iVar8 + puVar7[4]);
                                    iVar2 = *(int*)(iVar3 + iVar4 * 4);
                                    if (*(int*)(iVar2 + 0x30) != 0) {
                                        iVar2 = *(int*)(iVar2 + 0x10);
                                        local_68[iVar2 + 4] = iVar4;
                                        aiStack_88[iVar2] = *(int*)(iVar8 + puVar7[2]);
                                        local_20 = (uint32_t*)0x1;
                                    }
                                    uVar6 = puVar7[3];
                                    local_10 = local_10 + 1;
                                } while (local_10 < uVar6);
                            }

                            uVar9 = 0;
                            local_10 = 0;
                            FUN_006788f0(*(uint32_t*)((char*)self + 0x230), local_28, local_30,
                                         puVar7[4], uVar6, local_108, &local_10);

                            if (local_20 != (uint32_t*)0x0) {
                                local_68[0] = -1;
                                local_68[1] = -1;
                                local_68[2] = -1;
                                local_68[3] = -1;
                                local_18 = 0;
                                if (local_10 != 0) {
                                    do {
                                        iVar3 = *(int*)(*(int*)((char*)self + 0x14) + local_108[local_18] * 4);
                                        local_c = local_108[local_18];
                                        if (*(int*)(iVar3 + 0x38) != -1) {
                                            local_c = *(int*)(iVar3 + 0x38);
                                            iVar3 = *(int*)(*(int*)((char*)self + 0x14) + *(int*)(iVar3 + 0x38) * 4);
                                        }
                                        uVar6 = *(uint32_t*)(iVar3 + 0x48);
                                        if ((local_30 <= uVar6 || uVar6 < local_28) && uVar6 != 0xffffffffu) {
                                            local_8 = (int)(uVar6 * 4);
                                            local_20 = *(uint32_t**)(local_8 + *(int*)((char*)self + 0x230));
                                            iVar4 = FUN_00673ec4();
                                            if (iVar4 != 0) {
                                                if ((*local_20 & 0xfff00000u) == 0x10000000u &&
                                                    *(int*)(iVar3 + 0x38) == -1) {
                                                    uVar6 = 0;
                                                    if (local_20[3] != 0) {
                                                        piVar5 = (int*)(size_t)local_20[4];
                                                        while (local_c != *piVar5) {
                                                            local_24 = piVar5 + 1;
                                                            uVar6 = uVar6 + 1;
                                                            if (*(uint32_t*)(*(int*)(local_8 + *(int*)((char*)self + 0x230)) + 0xc) <= uVar6) {
                                                                goto LAB_0067d03d;
                                                            }
                                                            piVar5 = local_24;
                                                        }
                                                        aiStack_78[*(int*)(iVar3 + 0x10)] = *(int*)(local_20[2] + uVar6 * 4);
                                                        local_40 = 1;
                                                    }
                                                }
LAB_0067d03d:
                                                iVar4 = local_68[*(int*)(iVar3 + 0x10)];
                                                if (iVar4 == -1) {
                                                    local_68[*(int*)(iVar3 + 0x10)] = local_c;
                                                } else if (iVar4 != local_c) {
                                                    goto LAB_0067d456;
                                                }
                                            }
                                        }
                                        local_18 = local_18 + 1;
                                    } while (local_18 < local_10);
                                }

                                uVar9 = 0;
                                uVar6 = 0;
                                local_10 = 0;
                                do {
                                    if (*(int*)((char*)local_68 + uVar6) == -1) {
                                        if (*(int*)((char*)local_68 + uVar6 + 0x10) != -1) {
                                            uVar9 = uVar9 + 1;
                                            local_10 = uVar9;
                                        }
                                    } else {
                                        if (*(int*)((char*)local_68 + uVar6 + 0x10) != -1) {
                                            goto LAB_0067d456;
                                        }
                                        uVar9 = uVar9 + 1;
                                        local_10 = uVar9;
                                    }
                                    uVar6 = uVar6 + 4;
                                } while (uVar6 < 0x10);

                                iVar3 = FUN_0065d0b4();
                                local_24 = (iVar3 == 0) ? (int*)0x0 : (int*)FUN_0065cc1a(iVar3);
                                if (local_24 == (int*)0x0) {
                                    return -0x7ff8fff2;
                                }
                                local_18 = FUN_0065d0ff((uVar9 & 0xfffff) | 0x70100000u, uVar9 * 3, uVar9, 0);
                                if ((int)local_18 < 0) {
                                    goto LAB_0067d4c2;
                                }
                                local_18 = FUN_0065cc50();
                                if ((int)local_18 < 0) {
                                    goto LAB_0067d4c2;
                                }

                                local_8 = 0;
                                local_20 = (uint32_t*)0x0;
                                local_c = (int)(local_10 << 2);
                                do {
                                    iVar3 = *(int*)((char*)local_68 + 0x10 + (int)(size_t)local_20);
                                    if (iVar3 == -1) {
                                        iVar3 = *(int*)((char*)local_68 + (int)(size_t)local_20);
                                        if (iVar3 != -1) {
                                            local_38 = local_8 * 4;
                                            *(int*)(local_38 + local_24[4]) = iVar3;
                                            if (local_40 == 0) {
                                                iVar2 = *(int*)(*(int*)((char*)self + 0x14) + iVar3 * 4);
                                                iVar4 = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x88), 0,
                                                                     *(uint32_t*)(iVar2 + 0x10), 0);
                                                if (iVar4 == -1) {
                                                    goto LAB_0067d4a5;
                                                }
                                                *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) + iVar4 * 4) + 0x3c) =
                                                    *(uint32_t*)(iVar2 + 0x3c);
                                                iVar8 = *(int*)(iVar2 + 0x48);
                                                *(uint32_t*)(iVar2 + 0x3c) = 0;
                                                if (iVar8 == -1 || iVar8 == *(int*)((char*)self + 0x224)) {
                                                    FUN_006626da();
                                                    goto LAB_0067d4c2;
                                                }
                                                local_3c = *(int*)(*(int*)((char*)self + 0x230) + iVar8 * 4);
                                                uVar6 = 0;
                                                if (*(int*)(local_3c + 0xc) != 0) {
                                                    do {
                                                        piVar5 = (int*)(*(int*)(local_3c + 0x10) + uVar6 * 4);
                                                        if (*piVar5 == iVar3) {
                                                            *piVar5 = iVar4;
                                                        }
                                                        uVar6 = uVar6 + 1;
                                                    } while (uVar6 < *(uint32_t*)(local_3c + 0xc));
                                                }
                                                *(uint32_t*)(iVar2 + 0x48) = *(uint32_t*)((char*)self + 0x224);
                                            } else {
                                                iVar4 = *(int*)((char*)aiStack_78 + (int)(size_t)local_20);
                                                *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) + iVar3 * 4) + 0x48) =
                                                    *(uint32_t*)((char*)self + 0x224);
                                            }
                                            *(uint32_t*)(local_38 + local_24[2]) = *(uint32_t*)((char*)self + 0x440);
                                            local_38 = iVar4;
                                            *(int*)(local_24[2] + (local_8 + (int)local_10 * 2) * 4) = iVar4;
                                            local_8 = local_8 + 1;
                                            local_c = local_c + 4;
                                        }
                                    } else {
                                        *(int*)(local_24[4] + local_8 * 4) = iVar3;
                                        if (local_34 == 0) {
                                            iVar2 = *(int*)(*(int*)((char*)self + 0x14) + iVar3 * 4);
                                            iVar4 = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x88), 0,
                                                                 *(uint32_t*)(iVar2 + 0x10), 0);
                                            if (iVar4 == -1) {
                                                goto LAB_0067d4a5;
                                            }
                                            *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) + iVar4 * 4) + 0x3c) =
                                                *(uint32_t*)(iVar2 + 0x3c);
                                            *(uint32_t*)(iVar2 + 0x3c) = 0;
                                            *(uint32_t*)(iVar2 + 0x48) = *(uint32_t*)((char*)self + 0x224);
                                            uVar6 = 0;
                                            if (*(int*)(local_2c + 0xc) != 0) {
                                                do {
                                                    piVar5 = (int*)(*(int*)(local_2c + 0x10) + uVar6 * 4);
                                                    if (*piVar5 == iVar3) {
                                                        *piVar5 = iVar4;
                                                    }
                                                    uVar6 = uVar6 + 1;
                                                } while (uVar6 < *(uint32_t*)(local_2c + 0xc));
                                            }
                                        } else {
                                            iVar4 = *(int*)((char*)aiStack_88 + (int)(size_t)local_20);
                                            *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) + iVar3 * 4) + 0x48) =
                                                *(uint32_t*)((char*)self + 0x224);
                                        }
                                        *(int*)(local_c + local_24[2]) = iVar4;
                                        local_44 = iVar4;
                                        *(uint32_t*)(local_24[2] + local_8 * 4) = *(uint32_t*)((char*)self + 0x444);
                                        local_8 = local_8 + 1;
                                        local_c = local_c + 4;
                                    }
                                    piVar5 = local_24;
                                    local_20 = (uint32_t*)((int)(size_t)local_20 + 4);
                                } while ((uint32_t)(size_t)local_20 < 0x10);

                                local_8 = 0;
                                local_14 = (uint32_t*)0x0;
                                local_c = (int)(local_10 << 2);
                                do {
                                    if (*(int*)((char*)local_68 + 0x10 + (int)(size_t)local_14) == -1) {
                                        if (*(int*)((char*)local_68 + (int)(size_t)local_14) != -1) {
                                            iVar3 = *(int*)(*(int*)((char*)self + 0x14) +
                                                           *(int*)((char*)local_68 + (int)(size_t)local_14) * 4);
                                            iVar4 = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x88), 0,
                                                                 *(uint32_t*)(iVar3 + 0x10), 0);
                                            if (iVar4 != -1) {
                                                iVar2 = *(int*)(*(int*)((char*)self + 0x14) + iVar4 * 4);
                                                *(int*)(iVar2 + 0x38) = local_44;
                                                *(uint32_t*)(iVar2 + 0x3c) = *(uint32_t*)(iVar3 + 0x3c);
                                                if (local_44 != -1) {
                                                    *(uint32_t*)(iVar2 + 4) =
                                                        *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) + local_44 * 4) + 4);
                                                }
                                                *(int*)(local_c + piVar5[2]) = iVar4;
                                                local_8 = local_8 + 1;
                                                local_c = local_c + 4;
                                            } else {
                                                goto LAB_0067d4a5;
                                            }
                                        }
                                    } else {
                                        iVar3 = *(int*)(*(int*)((char*)self + 0x14) +
                                                       *(int*)((char*)local_68 + 0x10 + (int)(size_t)local_14) * 4);
                                        iVar4 = FUN_0065d9d5(*(uint32_t*)((char*)self + 0x88), 0,
                                                             *(uint32_t*)(iVar3 + 0x10), 0);
                                        if (iVar4 == -1) {
                                            goto LAB_0067d4a5;
                                        }
                                        iVar2 = *(int*)(*(int*)((char*)self + 0x14) + iVar4 * 4);
                                        *(int*)(iVar2 + 0x38) = local_38;
                                        *(uint32_t*)(iVar2 + 0x3c) = *(uint32_t*)(iVar3 + 0x3c);
                                        if (local_38 != -1) {
                                            *(uint32_t*)(iVar2 + 4) =
                                                *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x14) + local_38 * 4) + 4);
                                        }
                                        *(int*)(piVar5[2] + (local_8 + (int)local_10 * 2) * 4) = iVar4;
                                        local_8 = local_8 + 1;
                                        local_c = local_c + 4;
                                    }
                                    local_14 = (uint32_t*)((int)(size_t)local_14 + 4);
                                } while ((uint32_t)(size_t)local_14 < 0x10);

                                if (*(uint32_t*)((char*)self + 0x224) < 0x200) {
                                    *(int**)(*(int*)((char*)self + 0x230) + *(uint32_t*)((char*)self + 0x224) * 4) = piVar5;
                                    *(int*)((char*)self + 0x224) = *(int*)((char*)self + 0x224) + 1;
                                    iVar3 = FUN_0065d8c2();
                                    if (-1 < iVar3) {
                                        local_24 = (int*)0x0;
                                        goto LAB_0067d412;
                                    }
                                }
                                goto LAB_0067d4a5;
                            }

                            if (local_10 != 0) {
                                do {
                                    iVar3 = *(int*)(*(int*)((char*)self + 0x14) + local_108[uVar9] * 4);
                                    if (*(int*)(iVar3 + 0x38) != -1) {
                                        iVar3 = *(int*)(*(int*)((char*)self + 0x14) + *(int*)(iVar3 + 0x38) * 4);
                                    }
                                    uVar9 = uVar9 + 1;
                                    *(uint32_t*)(iVar3 + 0x30) = 1;
                                } while (uVar9 < local_10);
                            }
                        }
LAB_0067d412:
                        uVar6 = 0;
                        if (local_2c != 0 && *(int*)(local_2c + 0xc) != 0) {
                            do {
                                iVar3 = (int)uVar6 * 4;
                                uVar6 = uVar6 + 1;
                                *(int*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                *(int*)(*(int*)(local_2c + 0x10) + iVar3) * 4) + 0x48) =
                                    *(int*)((char*)self + 0x224) - 1;
                            } while (uVar6 < *(uint32_t*)(local_2c + 0xc));
                        }
                    }
                }
            }
            // LAB_0067d43c
            local_28 = local_28 + 1;
        } while (local_28 < local_30);
    }

    for (uVar6 = *(uint32_t*)((char*)self + 0x4c); uVar6 < local_30; uVar6 = uVar6 + 1) {
        **(uint32_t**)(*(int*)((char*)self + 0x230) + uVar6 * 4) = 0;
    }
    local_18 = 0;
    goto LAB_0067d4c2;

LAB_0067d456:
    FUN_006626da();
    return -0x7fffbffb;

LAB_0067d4a5:
    local_18 = (uint32_t)-0x7ff8fff2;
LAB_0067d4c2:
    if (local_24 != (int*)0x0) {
LAB_0067d4c9:
        FUN_00614343((void*)(size_t)local_24);
    }
LAB_0067d4d0:
    if (local_1c != 0) {
        FUN_00614343((void*)(size_t)local_1c);
    }
    return (int)local_18;
}

// ---------------------------------------------------------------------------
// Result type used by 0x67d4e6 (register-out modelling).
// NEEDS_MANUAL: FUN_00672e90 additionally leaves a value in ECX (Ghidra names it
// "extraout_ECX"); the decompiler never settles the result type. The three observed
// output words are modelled as a record so each call site keeps its observed uses.
// ---------------------------------------------------------------------------
struct FUN_00672e90_result {
    uint32_t lo;       // EAX
    uint32_t hi;       // EDX
    uint32_t ecx_out;  // ECX
};
extern FUN_00672e90_result FUN_00672e90(uint32_t tag);
extern void FUN_00695210(uint32_t a, int b, int c);
extern void FUN_00695256(uint32_t a, uint32_t b, int c);
extern int  FUN_00677f73(int* out);
extern int  FUN_00678775(void);
extern int  FUN_006788a9(uint32_t* decl);
extern int  DAT_0072be38[];

// 0x67d4e6 — observed shape
// Declaration-list fix-up loop: clears/rebuilds the per-element state, appends lookup results
// to the lists at self+0x22c/self+0x230, then repeatedly resolves and rebuilds conflicting
// declarations until the list stabilises.
// NEEDS_MANUAL: FUN_00672e90 leaves a second value in ECX; each site keeps its observed use.
int FUN_0067d4e6(void* self)
{
    uint32_t* puVar1;
    uint32_t uVar2;
    int iVar3;
    int* piVar4;
    uint32_t uVar5;
    bool bVar6;
    FUN_00672e90_result uVar7;
    int local_18;
    int local_14;
    int local_10;
    uint32_t local_c;
    int local_8;

    uVar2 = 0;
    if (*(int*)((char*)self + 0xc) != 0) {
        do {
            *(uint32_t*)(*(int*)(*(int*)((char*)self + 0x18) + uVar2 * 4) + 0x28) = 0;
            uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint32_t*)((char*)self + 0xc));
    }

    uVar2 = 0;
    do {
        iVar3 = *(int*)(uVar2 + *(int*)((char*)self + 0x230));
        if (iVar3 != 0) {
            FUN_00695210(*(uint32_t*)((char*)self + 0x18), iVar3, 1);
            FUN_00695256(*(uint32_t*)((char*)self + 0x18),
                         *(uint32_t*)(uVar2 + *(int*)((char*)self + 0x230)), 2);
        }
        iVar3 = *(int*)(uVar2 + *(int*)((char*)self + 0x22c));
        if (iVar3 != 0) {
            *(uint32_t*)(iVar3 + 0x28) = 1;
        }
        uVar2 = uVar2 + 4;
    } while (uVar2 < 0x18);

    uVar2 = 0;
    if (*(int*)((char*)self + 0xc) != 0) {
        do {
            uVar7 = FUN_00672e90(**(uint32_t**)(*(int*)((char*)self + 0x18) + uVar2 * 4) & 0xfff00000u);
            iVar3 = (int)uVar7.hi;
            if (uVar7.lo == 0 && uVar7.ecx_out != 0x72100000u && uVar7.ecx_out != 0x11000000u) {
                puVar1 = (uint32_t*)((char*)self + 0x220);
                if (0x1ff < *puVar1) {
                    return -0x7fffbffb;
                }
                if (*(int*)(iVar3 + 0x28) == 1) {
                    *(int*)(*(int*)((char*)self + 0x22c) + *puVar1 * 4) = iVar3;
                    *puVar1 = *puVar1 + 1;
                }
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint32_t*)((char*)self + 0xc));
    }

    piVar4 = *(int**)((char*)self + 0x22c);
    local_10 = 1;
    if (piVar4 != (int*)0x0 && *(int*)((char*)self + 0x220) != 0) {
        iVar3 = *(int*)((char*)self + 0x220);
        do {
            if (*piVar4 != 0) {
                local_10 = 0;
            }
            piVar4 = piVar4 + 1;
            iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
    }

    local_c = 0;
    do {
        local_8 = 0;
        iVar3 = FUN_00677f73(&local_8);
        if (iVar3 < 0) {
            return iVar3;
        }
        FUN_0067c441(self, *(int*)((char*)self + 0x22c), (int*)6,
                     *(uint32_t*)((char*)self + 0x220), &local_14);

        uVar5 = 0;
        uVar2 = 0;
        if (*(int*)((char*)self + 0xc) != 0) {
            do {
                puVar1 = *(uint32_t**)(*(int*)((char*)self + 0x18) + uVar5 * 4);
                if (puVar1 != (uint32_t*)0x0) {
                    if (puVar1[10] == 2 || puVar1[10] == 0) {
                        uVar7 = FUN_00672e90(*puVar1 & 0xfff00000u);
                        if (uVar7.lo == 0 && uVar7.ecx_out != 0x11000000u && uVar7.ecx_out != 0x72100000u) {
                            (&DAT_0072be38)[uVar2] = (int)uVar7.hi;
                            uVar2 = uVar2 + 1;
                        }
                    }
                    if (0x1ff < uVar2) {
                        return -0x7ff8fff2;
                    }
                }
                uVar5 = uVar5 + 1;
            } while (uVar5 < *(uint32_t*)((char*)self + 0xc));
        }

        while ((FUN_0067c441(self, (int)(size_t)DAT_0072be38, (int*)0, uVar2, &local_18),
                7 < local_8 + local_18 ||
                    ((local_14 < local_18 && local_c == 0) && local_10 == 0))) {
            local_8 = 0;
            if (*(int*)((char*)self + 0xc) != 0) {
                do {
                    puVar1 = *(uint32_t**)(*(int*)((char*)self + 0x18) + local_8 * 4);
                    if (puVar1[10] == 0) {
                        uVar7 = FUN_00672e90(*puVar1 & 0xfff00000u);
                        uVar2 = uVar7.hi;
                        if (uVar7.lo == 0 && uVar7.ecx_out != 0x72100000u) {
                            bVar6 = (uVar2 == puVar1[1]);
                            if (uVar2 < puVar1[1]) {
                                piVar4 = (int*)(size_t)puVar1[2];
                                do {
                                    if (*(char*)(*(int*)(*(int*)((char*)self + 0x14) + *piVar4 * 4) + 0x6c) == 1) {
                                        break;
                                    }
                                    uVar2 = uVar2 + 1;
                                    piVar4 = piVar4 + 1;
                                } while (uVar2 < puVar1[1]);
                                bVar6 = (uVar2 == puVar1[1]);
                            }
                            if (bVar6) {
                                uVar2 = 0;
                                if (local_c == 0) {
                                    bVar6 = (puVar1[3] == 0);
                                    if (puVar1[3] != 0) {
                                        piVar4 = (int*)(size_t)puVar1[4];
                                        do {
                                            if (*(int*)(*(int*)(*(int*)((char*)self + 0x14) + *piVar4 * 4) + 0x10) == 3) {
                                                break;
                                            }
                                            uVar2 = uVar2 + 1;
                                            piVar4 = piVar4 + 1;
                                        } while (uVar2 < puVar1[3]);
                                        bVar6 = (uVar2 == puVar1[3]);
                                    }
                                    if (!bVar6) {
                                        goto LAB_0067d771;
                                    }
                                }
                                if ((*(uint8_t*)(*(int*)(*(int*)((char*)self + 0x10) +
                                                       *(int*)(*(int*)(*(int*)((char*)self + 0x14) +
                                                                       *(int*)(size_t)puVar1[4] * 4) + 4) * 4) + 4) & 0x20) == 0) {
                                    puVar1[10] = 1;
                                    iVar3 = FUN_00678775();
                                    if (iVar3 == 0 && (iVar3 = FUN_006788a9(puVar1), iVar3 == 0)) {
                                        if (0x1ff < *(uint32_t*)((char*)self + 0x220)) {
                                            return -0x7ff8fff2;
                                        }
                                        *(uint32_t**)(*(int*)((char*)self + 0x22c) +
                                                      *(uint32_t*)((char*)self + 0x220) * 4) = puVar1;
                                        *(int*)((char*)self + 0x220) = *(int*)((char*)self + 0x220) + 1;
                                        break;
                                    }
                                    puVar1[10] = 0;
                                }
                            }
                        }
                    }
                LAB_0067d771:
                    local_8 = local_8 + 1;
                } while (local_8 < *(uint32_t*)((char*)self + 0xc));
            }
            if (local_8 == *(uint32_t*)((char*)self + 0xc)) {
                break;
            }

            local_8 = 0;
            iVar3 = FUN_00677f73(&local_8);
            if (iVar3 < 0) {
                return iVar3;
            }
            FUN_0067c441(self, *(int*)((char*)self + 0x22c), (int*)6,
                         *(uint32_t*)((char*)self + 0x220), &local_14);

            uVar5 = 0;
            uVar2 = 0;
            if (*(int*)((char*)self + 0xc) != 0) {
                do {
                    puVar1 = *(uint32_t**)(*(int*)((char*)self + 0x18) + uVar5 * 4);
                    if (puVar1 != (uint32_t*)0x0) {
                        if (puVar1[10] == 2 || puVar1[10] == 0) {
                            uVar7 = FUN_00672e90(*puVar1 & 0xfff00000u);
                            if (uVar7.lo == 0 && uVar7.ecx_out != 0x11000000u && uVar7.ecx_out != 0x72100000u) {
                                (&DAT_0072be38)[uVar2] = (int)uVar7.hi;
                                uVar2 = uVar2 + 1;
                            }
                        }
                        if (0x1ff < uVar2) {
                            return -0x7ff8fff2;
                        }
                    }
                    uVar5 = uVar5 + 1;
                } while (uVar5 < *(uint32_t*)((char*)self + 0xc));
            }
        }

        local_c = local_c + 1;
        if (1 < local_c) {
            uVar2 = 0;
            if (*(int*)((char*)self + 0xc) != 0) {
                do {
                    puVar1 = *(uint32_t**)(*(int*)((char*)self + 0x18) + uVar2 * 4);
                    if (puVar1[10] == 0) {
                        puVar1[10] = 2;
                    }
                    uVar5 = *(uint32_t*)((char*)self + 0x224);
                    if (0x1ff < uVar5) {
                        return -0x7fffbffb;
                    }
                    if (puVar1[10] == 2) {
                        uVar7 = FUN_00672e90(*puVar1 & 0xfff00000u);
                        iVar3 = (int)uVar7.hi;
                        if (uVar7.lo == 0 && iVar3 != 0x11000000 && iVar3 != 0x72100000) {
                            *(uint32_t*)(*(int*)((char*)self + 0x230) + uVar5 * 4) = uVar7.ecx_out;
                            *(int*)((char*)self + 0x224) = *(int*)((char*)self + 0x224) + 1;
                        }
                    }
                    uVar2 = uVar2 + 1;
                } while (uVar2 < *(uint32_t*)((char*)self + 0xc));
            }
            return 0;
        }
    } while (true);
}
