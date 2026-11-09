// Mass reconstruction batch mass_0342 — unverified decompiler-derived candidate.
// Target: Sid Meier's Pirates! (2004), PE32 i386.
// No compiler/test run. Correlated externally via observed pseudocode shapes.

#include <cstdint>
#include <cstddef>
#include <windows.h>

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int32_t  i32;
typedef uint64_t u64;

// ---- referenced helpers ----
extern intptr_t FUN_00533c78(u32 size);
extern void FUN_00661fbd(void);
extern void FUN_006a69ff(i32, i32);
extern void FUN_006a6a74(i32, i32);
extern i32  FUN_006a6b27(void);
extern void FUN_006a6b6e(void* base, u32* count);
extern void FUN_006a6bb4(u32* a, u32* b);
extern void FUN_006a6add(u32 a, u32 b);
extern void FUN_0065e1b9(i32 (*cmp)(void), u32 base, u32 count, void* ctx);
extern i32  FUN_0065cea4(void);
extern void FUN_00692470(i32, i32);
extern void operator_delete(void* p);
extern u32 FUN_006a6cd1(void* self, u32 param_1);
extern i32 FUN_006a7163(void* self);
extern void FUN_006a8960(i32 param_1, u32 param_2, u32 param_3, u32 param_4);
extern void FUN_006a89e0(i32 param_1, u32 param_2, u32* param_3, u32 param_4);
extern void FUN_006a85e0(void* self);
extern void FUN_006a8690(void* self);
extern void FUN_006a87d0(void* self);
extern void FUN_006a88b0(void* self);
extern void FUN_006a8b10(i32* param_1, i32 param_2);
extern void FUN_006a8b80(i32* param_1, i32 param_2);

// ---- globals: 4-lane float constant tables (16-byte blocks) ----
extern const float RF_00720f10[4];
extern const float RF_00720f20[4];
extern const float RF_00720f30[4];
extern const float RF_00720f40[4];
extern const float RF_00720f50[4];
extern const float RF_00720f60[4];
extern const float RF_00720f70[4];
extern const float RF_00720fb0[4];
extern const float RF_00720fc0[4];
extern const float RF_00720fd0[4];
extern const float RF_00720fe0[4];
extern const float RF_00720ff0[4];
extern const float RF_00721000[4];
extern const float RF_00721010[4];
extern const float RF_00721020[4];
extern const float RF_00721050[4];
extern const float RF_00721060[4];
extern const float RF_00721070[4];
extern const float RF_00721080[4];
extern const float RF_00721090[4];
extern const float RF_007210a0[4];
extern const float RF_007210b0[4];
extern const float RF_007210f0[4];
extern const float RF_00721100[4];
extern const float RF_00721110[4];
extern const float RF_00721120[4];
extern const float RF_00721130[4];
extern const float RF_00721140[4];
extern const float RF_00721150[4];
extern const float RF_00721160[4];
extern const u32 RU_00720f80;
extern const u32 RU_00720f90[4];
extern const u32 RU_00720fa0[4];
extern const u32 RU_00721030[8];
extern const u32 RU_00721040[4];
extern const u32 RU_007210c0[4];
extern const u32 RU_007210d0[4];
extern const u32 RU_007210e0[4];
extern const u32 RU_00721170[4];
extern const u32 RU_00721180[4];

// 0x6a6cd1 — observed shape
u32 FUN_006a6cd1(void* self_, u32 param_1)
{
    u8* self = (u8*)self_;
    i32 iVar1, iVar2, iVar6, iVar7, iVar10;
    i32* piVar3;
    u32 uVar4, uVar5, uVar8;
    u32* puVar9;
    u32* puVar11;
    u32 local_54;
    i32 local_50;
    u32* local_4c;
    i32 local_48;
    i32 local_44;
    u32 local_40, local_3c;
    i32 local_38;
    u32 local_34, local_30;
    i32 local_2c, local_28;
    u32 local_24;
    i32 local_20;
    u32 local_1c, local_18, local_14, local_10, local_c;
    i32 local_8;

    local_44 = 0;
    local_10 = param_1 + 1;
    iVar6 = *(i32*)(*(i32*)(self + 0x3c) + param_1 * 4);
    local_14 = param_1;
    iVar2 = iVar6 * 4;
    if (*(i32*)(iVar2 + *(i32*)(self + 0x34)) != 0) {
        return 1;
    }
    {
        i32 X = *(i32*)(iVar2 + *(i32*)(*(i32*)(self + 4) + 0x18));
        i32 idx = *(i32*)(*(i32*)(X + 0x10));
        iVar1 = *(i32*)(*(i32*)(*(i32*)(self + 4) + 0x14) + idx * 4);
    }
    local_28 = *(i32*)(iVar1 + 0x14);
    local_38 = *(i32*)(iVar1 + 0x18);
    local_18 = *(u32*)(iVar2 + *(i32*)(self + 8));
    puVar9 = (u32*)(*(i32*)(self + 0x10) + *(i32*)(iVar2 + *(i32*)(self + 0xc)) * 4);
    puVar11 = *(u32**)(self + 0x14);
    for (uVar4 = local_18; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar11 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar11 = puVar11 + 1;
    }
LAB_006a6d43:
    local_8 = 0;
    *(i32*)(self + 0x48) = *(i32*)(self + 0x48) + 1;
    for (uVar4 = local_14; uVar4 < local_10; uVar4 = uVar4 + 1) {
        iVar2 = *(i32*)(*(i32*)(*(i32*)(self + 4) + 0x18) +
                       *(i32*)(*(i32*)(self + 0x3c) + uVar4 * 4) * 4);
        uVar5 = 0;
        if (*(i32*)(iVar2 + 0x14) != 0) {
            do {
                iVar1 = uVar5 * 4;
                uVar5 = uVar5 + 1;
                *(u32*)(*(i32*)(*(i32*)(*(i32*)(self + 4) + 0x18) +
                                *(i32*)(*(i32*)(iVar2 + 0x18) + iVar1) * 4) + 0x24) =
                    *(u32*)(self + 0x48);
            } while (uVar5 < *(u32*)(iVar2 + 0x14));
        }
        uVar5 = 0;
        if (*(i32*)(iVar2 + 0x1c) != 0) {
            do {
                iVar1 = uVar5 * 4;
                uVar5 = uVar5 + 1;
                *(u32*)(*(i32*)(*(i32*)(*(i32*)(self + 4) + 0x18) +
                                *(i32*)(*(i32*)(iVar2 + 0x20) + iVar1) * 4) + 0x24) =
                    *(u32*)(self + 0x48);
            } while (uVar5 < *(u32*)(iVar2 + 0x1c));
        }
        local_8 = local_8 + *(i32*)(*(i32*)(self + 0x28) +
                                   *(i32*)(*(i32*)(self + 0x3c) + uVar4 * 4) * 4);
    }
    uVar4 = 0;
    if (local_18 != 0) {
        do {
            iVar2 = *(i32*)(*(i32*)(*(i32*)(self + 4) + 0x14) + uVar4 * 4);
            *(u32*)(iVar2 + 0x30) = *(u32*)(self + 0x48);
            uVar4 = uVar4 + 1;
            *(u32*)(iVar2 + 0x54) = (u32)(iVar6 == *(i32*)(iVar2 + 0x74));
        } while (uVar4 < local_18);
    }
    do {
        if (local_8 < 0) {
            local_2c = -1;
            local_c = local_14;
            local_3c = local_14;
        } else {
            if (local_8 < 1) goto LAB_006a712e;
            local_3c = local_10 - 1;
            local_c = local_10;
            local_2c = 1;
        }
        local_24 = 0;
        local_20 = 0;
        local_1c = 0;
        param_1 = local_c;
        do {
            local_3c = local_3c + local_2c;
            if (*(u32*)(self + 0x38) <= local_3c) break;
            local_48 = *(i32*)(*(i32*)(self + 0x3c) + local_3c * 4);
            iVar2 = local_48 * 4;
            if (*(i32*)(iVar2 + *(i32*)(self + 0x34)) == 0) {
                iVar1 = *(i32*)(self + 4);
                {
                    i32 Y = *(i32*)(*(i32*)(iVar1 + 0x18) + iVar2);
                    i32 idx2 = *(i32*)(*(i32*)(Y + 0x10));
                    local_50 = *(i32*)(*(i32*)(iVar1 + 0x14) + idx2 * 4);
                }
                iVar10 = *(i32*)(local_50 + 0x18);
                for (iVar7 = *(i32*)(local_50 + 0x14); iVar7 != -1;
                     iVar7 = *(i32*)(iVar7 + 0x14)) {
                    if (local_28 == iVar7) goto LAB_006a6e75;
                    iVar7 = *(i32*)(*(i32*)(iVar1 + 0x14) + iVar7 * 4);
                    iVar10 = *(i32*)(iVar7 + 0x18);
                }
                if (local_28 != -1) goto LAB_006a712e;
LAB_006a6e75:
                if (local_38 != iVar10) goto LAB_006a712e;
            }
            if (local_3c < local_c) {
                local_c = local_3c;
            }
            if (param_1 <= local_3c) {
                param_1 = local_3c + 1;
            }
            local_4c = (u32*)(*(i32*)(self + 0x10) +
                              *(i32*)(iVar2 + *(i32*)(self + 0xc)) * 4);
            local_34 = *(u32*)(iVar2 + *(i32*)(self + 8));
            puVar9 = local_4c;
            puVar11 = (u32*)(*(i32*)(self + 0x18) + local_24 * 4);
            for (uVar4 = local_34; uVar4 != 0; uVar4 = uVar4 - 1) {
                *puVar11 = *puVar9;
                puVar9 = puVar9 + 1;
                puVar11 = puVar11 + 1;
            }
            local_24 = local_24 + *(i32*)(iVar2 + *(i32*)(self + 8));
            local_20 = local_20 + *(i32*)(*(i32*)(self + 0x28) + iVar2);
            local_1c = local_1c |
                (u32)(*(i32*)(self + 0x48) ==
                      *(i32*)(*(i32*)(*(i32*)(*(i32*)(self + 4) + 0x18) + iVar2) + 0x24));
            local_30 = 0;
            if (local_34 != 0) {
                do {
                    iVar1 = *(i32*)(*(i32*)(*(i32*)(self + 4) + 0x14) +
                                    local_4c[local_30] * 4);
                    if ((*(i32*)(iVar1 + 0x30) != *(i32*)(self + 0x48)) ||
                        (local_48 == *(i32*)(iVar1 + 0x74))) {
                        *(i32*)(iVar1 + 0x30) = *(i32*)(self + 0x48);
                        *(u32*)(iVar1 + 0x54) =
                            (u32)((local_48 != *(i32*)(iVar1 + 0x74)) - 1);
                    }
                    local_30 = local_30 + 1;
                } while (local_30 < local_34);
            }
        } while ((*(i32*)(iVar2 + *(i32*)(self + 0x34)) != 0) ||
                 (local_28 != *(i32*)(local_50 + 0x14)) ||
                 (local_38 != *(i32*)(local_50 + 0x18)));
        if (param_1 <= local_c) {
LAB_006a712e:
            if (local_44 == 0) {
                return 1;
            }
            puVar9 = *(u32**)(self + 0x40);
            puVar11 = *(u32**)(self + 0x3c);
            for (uVar4 = *(u32*)(self + 0x38) & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
                *puVar11 = *puVar9;
                puVar9 = puVar9 + 1;
                puVar11 = puVar11 + 1;
            }
            for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
                *(u8*)puVar11 = *(u8*)puVar9;
                puVar9 = (u32*)((intptr_t)puVar9 + 1);
                puVar11 = (u32*)((intptr_t)puVar11 + 1);
            }
            FUN_006a6bb4(nullptr, nullptr);
            return 1;
        }
        if (local_c + 1 < param_1) {
            FUN_006a6b6e((void*)(uintptr_t)*(u32*)(self + 0x18), &local_24);
        }
        if (local_1c == 0) {
            if (local_8 < 0) {
                local_2c = local_20;
                if (local_24 != 0) {
                    piVar3 = *(i32**)(self + 0x18);
                    uVar4 = local_24;
                    do {
                        if (*(i32*)(*(i32*)(*(i32*)(*(i32*)(self + 4) + 0x14) +
                                            *piVar3 * 4) + 0x54) == 1) {
                            local_2c = local_2c + -1;
                        }
                        piVar3 = piVar3 + 1;
                        uVar4 = uVar4 - 1;
                    } while (uVar4 != 0);
                }
                if (local_2c < local_8) goto LAB_006a6fe1;
            } else {
                local_2c = local_8;
                if (local_18 != 0) {
                    piVar3 = *(i32**)(self + 0x14);
                    uVar4 = local_18;
                    do {
                        if (*(i32*)(*(i32*)(*(i32*)(*(i32*)(self + 4) + 0x14) +
                                            *piVar3 * 4) + 0x54) == -1) {
                            local_2c = local_2c + -1;
                        }
                        piVar3 = piVar3 + 1;
                        uVar4 = uVar4 - 1;
                    } while (uVar4 != 0);
                }
                if (local_2c < local_20) {
LAB_006a6fe1:
                    local_1c = 1;
                }
            }
        }
        uVar4 = local_14;
        if (local_c <= local_14) {
            uVar4 = local_c;
        }
        uVar5 = local_10;
        if (local_10 <= param_1) {
            uVar5 = param_1;
        }
        if (local_1c == 0) break;
        uVar8 = 0;
        if (local_24 != 0) {
            do {
                iVar2 = *(i32*)(*(i32*)(*(i32*)(self + 4) + 0x14) +
                                *(i32*)(*(i32*)(self + 0x18) + uVar8 * 4) * 4);
                uVar8 = uVar8 + 1;
                *(u32*)(iVar2 + 0x54) = (u32)(*(i32*)(iVar2 + 0x54) != 0);
            } while (uVar8 < local_24);
        }
        local_8 = local_8 + local_20;
        puVar9 = *(u32**)(self + 0x18);
        puVar11 = (u32*)(*(i32*)(self + 0x14) + local_18 * 4);
        for (uVar8 = local_24; uVar8 != 0; uVar8 = uVar8 - 1) {
            *puVar11 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar11 = puVar11 + 1;
        }
        local_18 = local_18 + local_24;
        local_14 = uVar4;
        local_10 = uVar5;
        FUN_006a6b6e((void*)(uintptr_t)*(u32*)(self + 0x14), &local_18);
        uVar4 = local_c;
        do {
            iVar2 = *(i32*)(*(i32*)(*(i32*)(self + 4) + 0x18) +
                            *(i32*)(*(i32*)(self + 0x3c) + uVar4 * 4) * 4);
            uVar5 = 0;
            if (*(i32*)(iVar2 + 0x14) != 0) {
                do {
                    iVar1 = uVar5 * 4;
                    uVar5 = uVar5 + 1;
                    *(u32*)(*(i32*)(*(i32*)(*(i32*)(self + 4) + 0x18) +
                                    *(i32*)(*(i32*)(iVar2 + 0x18) + iVar1) * 4) + 0x24) =
                        *(u32*)(self + 0x48);
                } while (uVar5 < *(u32*)(iVar2 + 0x14));
            }
            uVar5 = 0;
            if (*(i32*)(iVar2 + 0x1c) != 0) {
                do {
                    iVar1 = uVar5 * 4;
                    uVar5 = uVar5 + 1;
                    *(u32*)(*(i32*)(*(i32*)(*(i32*)(self + 4) + 0x18) +
                                    *(i32*)(*(i32*)(iVar2 + 0x20) + iVar1) * 4) + 0x24) =
                        *(u32*)(self + 0x48);
                } while (uVar5 < *(u32*)(iVar2 + 0x1c));
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < param_1);
    } while (true);
    FUN_006a6add(local_14, local_10);
    FUN_006a6add(local_c, param_1);
    FUN_006a6add(uVar4, uVar5);
    FUN_006a6bb4(&local_40, &local_54);
    if (((local_40 < *(u32*)(self + 0x50)) && (local_54 <= *(u32*)(self + 0x4c))) ||
        ((local_40 <= *(u32*)(self + 0x50)) && (local_54 < *(u32*)(self + 0x4c)))) {
        return 0;
    }
    if (local_8 < 0) {
        iVar2 = local_c - param_1;
    } else {
        iVar2 = param_1 - local_c;
    }
    local_14 = local_14 + iVar2;
    local_10 = local_10 + iVar2;
    local_44 = 1;
    goto LAB_006a6d43;
}

// 0x6a7163 — observed shape
i32 FUN_006a7163(void* self_)
{
    u8* self = (u8*)self_;
    u32 uVar1;
    i32 iVar2;

    FUN_006a6bb4((u32*)(self + 0x50), (u32*)(self + 0x4c));
    uVar1 = 0;
    if (*(i32*)(self + 0x38) != 0) {
        do {
            *(u32*)(*(i32*)(self + 0x30) + uVar1 * 4) = uVar1;
            *(u32*)(*(i32*)(self + 0x40) + uVar1 * 4) =
                *(u32*)(*(i32*)(self + 0x3c) + uVar1 * 4);
            uVar1 = uVar1 + 1;
        } while (uVar1 < *(u32*)(self + 0x38));
    }
    FUN_0065e1b9(FUN_006a6b27, *(u32*)(self + 0x30), *(u32*)(self + 0x38), self);
    uVar1 = 0;
    if (*(i32*)(self + 0x38) != 0) {
        do {
            iVar2 = FUN_006a6cd1(self, *(u32*)(*(i32*)(self + 0x30) + uVar1 * 4));
            if (iVar2 < 0) {
                return iVar2;
            }
            if (iVar2 == 0) {
                return 0;
            }
            uVar1 = uVar1 + 1;
        } while (uVar1 < *(u32*)(self + 0x38));
    }
    return 1;
}

// 0x6a71d0 — observed shape
i32 FUN_006a71d0(void* self_, i32 param_1)
{
    u8* self = (u8*)self_;
    i32 iVar1, iVar2;
    u32 uVar4, uVar5;
    i32 iVar6;
    u32* puVar7;
    u32 local_c, local_8;

    *(u32*)(self + 8) = 0;
    *(u32*)(self + 0xc) = 0;
    *(u32*)(self + 0x10) = 0;
    *(u32*)(self + 0x1c) = 0;
    *(u32*)(self + 0x20) = 0;
    *(u32*)(self + 0x24) = 0;
    *(u32*)(self + 0x28) = 0;
    *(u32*)(self + 0x2c) = 0;
    *(u32*)(self + 0x30) = 0;
    *(u32*)(self + 0x34) = 0;
    *(u32*)(self + 0x3c) = 0;
    *(u32*)(self + 0x38) = *(u32*)(*(i32*)(self + 4) + 0xc);
    FUN_00661fbd();
    iVar1 = (i32)FUN_00533c78(*(i32*)(self + 0x38) << 2);
    *(i32*)(self + 8) = iVar1;
    if (iVar1 == 0) goto fail;
    iVar1 = (i32)FUN_00533c78(*(i32*)(self + 0x38) << 2);
    *(i32*)(self + 0x1c) = iVar1;
    if (iVar1 == 0) goto fail;
    puVar7 = *(u32**)(self + 8);
    for (uVar4 = *(u32*)(self + 0x38) & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
    }
    for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
        *(u8*)puVar7 = 0;
        puVar7 = (u32*)((intptr_t)puVar7 + 1);
    }
    puVar7 = *(u32**)(self + 0x1c);
    for (uVar4 = *(u32*)(self + 0x38) & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
    }
    for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
        *(u8*)puVar7 = 0;
        puVar7 = (u32*)((intptr_t)puVar7 + 1);
    }
    local_8 = 0;
    if (*(i32*)(self + 0x38) != 0) {
        do {
            iVar1 = *(i32*)(*(i32*)(*(i32*)(self + 4) + 0x18) + local_8 * 4);
            if ((*(u16*)(iVar1 + 2) & 0xfff0) != 0) {
                local_c = 0;
                if (*(i32*)(iVar1 + 0xc) != 0) {
                    do {
                        FUN_006a6a74((i32)local_8,
                                     *(i32*)(*(i32*)(iVar1 + 0x10) + local_c * 4));
                        local_c = local_c + 1;
                    } while (local_c < *(u32*)(iVar1 + 0xc));
                }
                local_c = 0;
                if (*(i32*)(iVar1 + 4) != 0) {
                    do {
                        FUN_006a69ff((i32)local_8,
                                     *(i32*)(*(i32*)(iVar1 + 8) + local_c * 4));
                        local_c = local_c + 1;
                    } while (local_c < *(u32*)(iVar1 + 4));
                }
            }
            local_8 = local_8 + 1;
        } while (local_8 < *(u32*)(self + 0x38));
    }
    iVar1 = (i32)FUN_00533c78(*(i32*)(self + 0x38) << 2);
    *(i32*)(self + 0xc) = iVar1;
    if (iVar1 == 0) goto fail;
    iVar1 = (i32)FUN_00533c78(*(i32*)(self + 0x38) << 2);
    *(i32*)(self + 0x20) = iVar1;
    if (iVar1 == 0) goto fail;
    iVar1 = 0;
    iVar6 = 0;
    uVar4 = 0;
    if (*(i32*)(self + 0x38) != 0) {
        do {
            iVar2 = uVar4 * 4;
            *(i32*)(iVar2 + *(i32*)(self + 0xc)) = iVar1;
            iVar1 = iVar1 + *(i32*)(iVar2 + *(i32*)(self + 8));
            *(i32*)(iVar2 + *(i32*)(self + 0x20)) = iVar6;
            iVar6 = iVar6 + *(i32*)(iVar2 + *(i32*)(self + 0x1c));
            uVar4 = uVar4 + 1;
        } while (uVar4 < *(u32*)(self + 0x38));
    }
    uVar4 = 0;
    iVar1 = iVar1 << 2;
    iVar2 = (i32)FUN_00533c78(iVar1);
    *(i32*)(self + 0x10) = iVar2;
    if (iVar2 == 0) goto fail;
    iVar2 = (i32)FUN_00533c78(iVar1);
    *(i32*)(self + 0x14) = iVar2;
    if (iVar2 == 0) goto fail;
    iVar1 = (i32)FUN_00533c78(iVar1);
    *(i32*)(self + 0x18) = iVar1;
    if (iVar1 == 0) goto fail;
    iVar1 = (i32)FUN_00533c78(iVar6 << 2);
    *(i32*)(self + 0x24) = iVar1;
    if (iVar1 == 0) goto fail;
    puVar7 = *(u32**)(self + 8);
    for (uVar5 = *(u32*)(self + 0x38) & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
    }
    for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
        *(u8*)puVar7 = 0;
        puVar7 = (u32*)((intptr_t)puVar7 + 1);
    }
    puVar7 = *(u32**)(self + 0x1c);
    for (uVar5 = *(u32*)(self + 0x38) & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
    }
    for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
        *(u8*)puVar7 = 0;
        puVar7 = (u32*)((intptr_t)puVar7 + 1);
    }
    local_8 = 0;
    if (*(i32*)(self + 0x38) != 0) {
        do {
            iVar1 = *(i32*)(*(i32*)(*(i32*)(self + 4) + 0x18) + local_8 * 4);
            if ((*(u16*)(iVar1 + 2) & 0xfff0) != 0) {
                local_c = 0;
                if (*(i32*)(iVar1 + 4) != 0) {
                    do {
                        FUN_006a69ff((i32)local_8,
                                     *(i32*)(*(i32*)(iVar1 + 8) + local_c * 4));
                        local_c = local_c + 1;
                    } while (local_c < *(u32*)(iVar1 + 4));
                }
                local_c = 0;
                if (*(i32*)(iVar1 + 0xc) != 0) {
                    do {
                        FUN_006a6a74((i32)local_8,
                                     *(i32*)(*(i32*)(iVar1 + 0x10) + local_c * 4));
                        local_c = local_c + 1;
                    } while (local_c < *(u32*)(iVar1 + 0xc));
                }
            }
            local_8 = local_8 + 1;
        } while (local_8 < *(u32*)(self + 0x38));
    }
    local_c = 0;
    if (*(i32*)(self + 0x38) != 0) {
        do {
            iVar1 = local_c * 4;
            FUN_006a6b6e((void*)(uintptr_t)(*(i32*)(self + 0x10) +
                             *(i32*)(iVar1 + *(i32*)(self + 0xc)) * 4),
                         (u32*)(uintptr_t)(*(i32*)(self + 8) + iVar1));
            FUN_006a6b6e((void*)(uintptr_t)(*(i32*)(self + 0x24) +
                             *(i32*)(iVar1 + *(i32*)(self + 0x20)) * 4),
                         (u32*)(uintptr_t)(*(i32*)(self + 0x1c) + iVar1));
            local_c = local_c + 1;
        } while (local_c < *(u32*)(self + 0x38));
    }
    iVar1 = (i32)FUN_00533c78(*(i32*)(self + 0x38) << 2);
    *(i32*)(self + 0x3c) = iVar1;
    if (iVar1 == 0) goto fail;
    iVar1 = (i32)FUN_00533c78(*(i32*)(self + 0x38) << 2);
    *(i32*)(self + 0x40) = iVar1;
    if (iVar1 == 0) goto fail;
    iVar1 = (i32)FUN_00533c78(*(i32*)(self + 0x38) << 2);
    *(i32*)(self + 0x44) = iVar1;
    if (iVar1 == 0) goto fail;
    iVar1 = (i32)FUN_00533c78(*(i32*)(self + 0x38) << 2);
    *(i32*)(self + 0x34) = iVar1;
    if (iVar1 == 0) goto fail;
    if (*(i32*)(self + 0x38) != 0) {
        do {
            iVar6 = uVar4 * 4;
            iVar1 = *(i32*)(iVar6 + *(i32*)(*(i32*)(self + 4) + 0x18));
            *(u32*)(iVar6 + *(i32*)(self + 0x3c)) = uVar4;
            *(i32*)(iVar6 + *(i32*)(self + 0x44)) = iVar1;
            *(u32*)(iVar1 + 0x24) = 0xffffffff;
            if ((*(u16*)(iVar1 + 2) & 0xfff0) == 0) {
LAB_006a7520:
                uVar5 = 1;
            } else {
                iVar1 = FUN_0065cea4();
                uVar5 = 0;
                if (iVar1 != 0) goto LAB_006a7520;
            }
            uVar4 = uVar4 + 1;
            *(u32*)(iVar6 + *(i32*)(self + 0x34)) = uVar5;
        } while (uVar4 < *(u32*)(self + 0x38));
    }
    iVar6 = 0;
    *(u32*)(self + 0x48) = 0;
    iVar1 = (i32)FUN_00533c78(*(i32*)(self + 0x38) << 2);
    *(i32*)(self + 0x28) = iVar1;
    if (iVar1 == 0) goto fail;
    iVar1 = (i32)FUN_00533c78(*(i32*)(self + 0x38) << 2);
    *(i32*)(self + 0x2c) = iVar1;
    if (iVar1 == 0) goto fail;
    iVar1 = (i32)FUN_00533c78(*(i32*)(self + 0x38) << 2);
    *(i32*)(self + 0x30) = iVar1;
    if (iVar1 == 0) goto fail;
    if (param_1 != 0) {
        do {
            iVar1 = FUN_006a7163(self);
            if (iVar1 < 0) {
                return iVar1;
            }
        } while (iVar1 != 1);
        uVar4 = 0;
        if (*(i32*)(self + 0x38) != 0) {
            do {
                *(u32*)(*(i32*)(*(i32*)(self + 4) + 0x18) + uVar4 * 4) =
                    *(u32*)(*(i32*)(self + 0x44) +
                            *(i32*)(*(i32*)(self + 0x3c) + uVar4 * 4) * 4);
                uVar4 = uVar4 + 1;
            } while (uVar4 < *(u32*)(self + 0x38));
        }
    }
    goto LAB_006a75b5;
fail:
    iVar6 = -0x7ff8fff2;
LAB_006a75b5:
    operator_delete(*(void**)(self + 8));
    operator_delete(*(void**)(self + 0xc));
    operator_delete(*(void**)(self + 0x10));
    operator_delete(*(void**)(self + 0x14));
    operator_delete(*(void**)(self + 0x18));
    operator_delete(*(void**)(self + 0x1c));
    operator_delete(*(void**)(self + 0x20));
    operator_delete(*(void**)(self + 0x24));
    operator_delete(*(void**)(self + 0x28));
    operator_delete(*(void**)(self + 0x2c));
    operator_delete(*(void**)(self + 0x30));
    operator_delete(*(void**)(self + 0x34));
    operator_delete(*(void**)(self + 0x3c));
    operator_delete(*(void**)(self + 0x40));
    operator_delete(*(void**)(self + 0x44));
    return iVar6;
}

// 0x6a7639 — observed shape
void FUN_006a7639(u32* param_1, u32* param_2, u32* param_3)
{
    float fVar6, fVar7, fVar8, fVar10, fVar11, fVar12, fVar14, fVar15, fVar16, fVar18, fVar19, fVar20;
    u32 uVar1, uVar2, uVar3, uVar4, uVar5, uVar9, uVar13, uVar17, uVar21;
    u32 uVar22, uVar23, uVar24, uVar25, uVar26, uVar27, uVar28;

    fVar6 = (float)(*param_1 & RU_00721040[0]);
    fVar10 = (float)(param_1[1] & RU_00721040[1]);
    fVar14 = (float)(param_1[2] & RU_00721040[2]);
    fVar18 = (float)(param_1[3] & RU_00721040[3]);
    uVar22 = param_1[1] & RU_00721030[1];
    uVar23 = param_1[2] & RU_00721030[2];
    uVar24 = param_1[3] & RU_00721030[3];
    fVar7 = fVar6 * RF_00721020[0] + RF_00720fd0[0];
    fVar11 = fVar10 * RF_00721020[1] + RF_00720fd0[1];
    fVar15 = fVar14 * RF_00721020[2] + RF_00720fd0[2];
    fVar19 = fVar18 * RF_00721020[3] + RF_00720fd0[3];
    fVar8 = fVar7 - RF_00720fd0[0];
    fVar12 = fVar11 - RF_00720fd0[1];
    fVar16 = fVar15 - RF_00720fd0[2];
    fVar20 = fVar19 - RF_00720fd0[3];
    fVar6 = (((fVar6 - RF_00721010[0] * fVar8) - RF_00721000[0] * fVar8) -
             RF_00720ff0[0] * fVar8) - RF_00720fe0[0] * fVar8;
    fVar8 = (((fVar10 - RF_00721010[1] * fVar12) - RF_00721000[1] * fVar12) -
             RF_00720ff0[1] * fVar12) - RF_00720fe0[1] * fVar12;
    fVar10 = (((fVar14 - RF_00721010[2] * fVar16) - RF_00721000[2] * fVar16) -
              RF_00720ff0[2] * fVar16) - RF_00720fe0[2] * fVar16;
    fVar12 = (((fVar18 - RF_00721010[3] * fVar20) - RF_00721000[3] * fVar20) -
              RF_00720ff0[3] * fVar20) - RF_00720fe0[3] * fVar20;
    fVar14 = fVar6 * fVar6;
    fVar16 = fVar8 * fVar8;
    fVar18 = fVar10 * fVar10;
    fVar20 = fVar12 * fVar12;
    uVar25 = (u32)fVar7 & RU_00720fa0[0];
    uVar26 = (u32)fVar11 & RU_00720fa0[1];
    uVar27 = (u32)fVar15 & RU_00720fa0[2];
    uVar28 = (u32)fVar19 & RU_00720fa0[3];
    uVar9 = uVar25 & RU_00720f90[0];
    uVar13 = uVar26 & RU_00720f90[1];
    uVar17 = uVar27 & RU_00720f90[2];
    uVar21 = uVar28 & RU_00720f90[3];
    uVar1 = uVar26 - uVar13 & RU_00720f80;
    uVar2 = uVar27 - uVar17 & RU_00720f80;
    uVar3 = uVar28 - uVar21 & RU_00720f80;
    uVar4 = uVar25 + uVar9 & RU_00720f80;
    uVar26 = uVar26 + uVar13 & RU_00720f80;
    uVar27 = uVar27 + uVar17 & RU_00720f80;
    uVar28 = uVar28 + uVar21 & RU_00720f80;
    uVar5 = 0u - (u32)((float)(uVar9 << 0x1e) != 0.0f);
    uVar13 = 0u - (u32)((float)(uVar13 << 0x1e) != 0.0f);
    uVar17 = 0u - (u32)((float)(uVar17 << 0x1e) != 0.0f);
    uVar21 = 0u - (u32)((float)(uVar21 << 0x1e) != 0.0f);
    fVar6 = (((RF_00720fc0[0] * fVar14 + RF_00720f70[0]) * fVar14 + RF_00720f50[0]) *
             fVar14 + RF_00720f30[0]) * fVar6;
    fVar8 = (((RF_00720fc0[1] * fVar16 + RF_00720f70[1]) * fVar16 + RF_00720f50[1]) *
             fVar16 + RF_00720f30[1]) * fVar8;
    fVar10 = (((RF_00720fc0[2] * fVar18 + RF_00720f70[2]) * fVar18 + RF_00720f50[2]) *
              fVar18 + RF_00720f30[2]) * fVar10;
    fVar12 = (((RF_00720fc0[3] * fVar20 + RF_00720f70[3]) * fVar20 + RF_00720f50[3]) *
              fVar20 + RF_00720f30[3]) * fVar12;
    fVar7 = (((RF_00720fb0[0] * fVar14 + RF_00720f60[0]) * fVar14 + RF_00720f40[0]) *
             fVar14 + RF_00720f20[0]) * fVar14 + RF_00720f10[0];
    fVar11 = (((RF_00720fb0[1] * fVar16 + RF_00720f60[1]) * fVar16 + RF_00720f40[1]) *
              fVar16 + RF_00720f20[1]) * fVar16 + RF_00720f10[1];
    fVar14 = (((RF_00720fb0[2] * fVar18 + RF_00720f60[2]) * fVar18 + RF_00720f40[2]) *
              fVar18 + RF_00720f20[2]) * fVar18 + RF_00720f10[2];
    fVar15 = (((RF_00720fb0[3] * fVar20 + RF_00720f60[3]) * fVar20 + RF_00720f40[3]) *
              fVar20 + RF_00720f20[3]) * fVar20 + RF_00720f10[3];
    *param_2 = (~uVar5 & (u32)fVar6 | uVar5 & (u32)fVar7) ^
               (uVar25 - uVar9 & RU_00720f80) << 0x1e ^ *param_1 & RU_00721030[0];
    param_2[1] = (~uVar13 & (u32)fVar8 | uVar13 & (u32)fVar11) ^ uVar1 << 0x1e ^ uVar22;
    param_2[2] = (~uVar17 & (u32)fVar10 | uVar17 & (u32)fVar14) ^ uVar2 << 0x1e ^ uVar23;
    param_2[3] = (~uVar21 & (u32)fVar12 | uVar21 & (u32)fVar15) ^ uVar3 << 0x1e ^ uVar24;
    *param_3 = (uVar5 & (u32)fVar6 | ~uVar5 & (u32)fVar7) ^ uVar4 << 0x1e;
    param_3[1] = (uVar13 & (u32)fVar8 | ~uVar13 & (u32)fVar11) ^ uVar26 << 0x1e;
    param_3[2] = (uVar17 & (u32)fVar10 | ~uVar17 & (u32)fVar14) ^ uVar27 << 0x1e;
    param_3[3] = (uVar21 & (u32)fVar12 | ~uVar21 & (u32)fVar15) ^ uVar28 << 0x1e;
    return;
}

// 0x6a7825 — observed shape
void FUN_006a7825(u32* param_1, u32* param_2, u32* param_3)
{
    float fVar1, fVar2, fVar4, fVar5, fVar7, fVar8, fVar10, fVar11, fVar16, fVar17, fVar25, fVar26;
    u32 uVar3, uVar6, uVar9, uVar12, uVar13, uVar14, uVar15, uVar18, uVar19, uVar20;
    u32 uVar21, uVar22, uVar23, uVar24, uVar27, uVar28;

    fVar16 = (float)(*param_1 & RU_00721180[0]);
    fVar17 = (float)(param_1[1] & RU_00721180[1]);
    fVar25 = (float)(param_1[2] & RU_00721180[2]);
    fVar26 = (float)(param_1[3] & RU_00721180[3]);
    uVar13 = param_1[1] & RU_00721170[1];
    uVar14 = param_1[2] & RU_00721170[2];
    uVar15 = param_1[3] & RU_00721170[3];
    fVar1 = fVar16 * RF_00721160[0] + RF_00721110[0];
    fVar4 = fVar17 * RF_00721160[1] + RF_00721110[1];
    fVar7 = fVar25 * RF_00721160[2] + RF_00721110[2];
    fVar10 = fVar26 * RF_00721160[3] + RF_00721110[3];
    fVar2 = fVar1 - RF_00721110[0];
    fVar5 = fVar4 - RF_00721110[1];
    fVar8 = fVar7 - RF_00721110[2];
    fVar11 = fVar10 - RF_00721110[3];
    fVar16 = (((fVar16 - RF_00721150[0] * fVar2) - RF_00721140[0] * fVar2) -
              RF_00721130[0] * fVar2) - RF_00721120[0] * fVar2;
    fVar2 = (((fVar17 - RF_00721150[1] * fVar5) - RF_00721140[1] * fVar5) -
             RF_00721130[1] * fVar5) - RF_00721120[1] * fVar5;
    fVar17 = (((fVar25 - RF_00721150[2] * fVar8) - RF_00721140[2] * fVar8) -
              RF_00721130[2] * fVar8) - RF_00721120[2] * fVar8;
    fVar5 = (((fVar26 - RF_00721150[3] * fVar11) - RF_00721140[3] * fVar11) -
             RF_00721130[3] * fVar11) - RF_00721120[3] * fVar11;
    fVar25 = fVar16 * fVar16;
    fVar8 = fVar2 * fVar2;
    fVar26 = fVar17 * fVar17;
    fVar11 = fVar5 * fVar5;
    uVar18 = (u32)fVar1 & RU_007210e0[0];
    uVar19 = (u32)fVar4 & RU_007210e0[1];
    uVar21 = (u32)fVar7 & RU_007210e0[2];
    uVar23 = (u32)fVar10 & RU_007210e0[3];
    uVar3 = uVar18 & RU_007210d0[0];
    uVar6 = uVar19 & RU_007210d0[1];
    uVar9 = uVar21 & RU_007210d0[2];
    uVar12 = uVar23 & RU_007210d0[3];
    uVar20 = uVar19 - uVar6 & RU_007210c0[1];
    uVar22 = uVar21 - uVar9 & RU_007210c0[2];
    uVar24 = uVar23 - uVar12 & RU_007210c0[3];
    uVar27 = uVar18 + uVar3 & RU_007210c0[0];
    uVar28 = uVar19 + uVar6 & RU_007210c0[1];
    uVar21 = uVar21 + uVar9 & RU_007210c0[2];
    uVar23 = uVar23 + uVar12 & RU_007210c0[3];
    uVar19 = 0u - (u32)((float)(uVar3 << 0x1e) != 0.0f);
    uVar6 = 0u - (u32)((float)(uVar6 << 0x1e) != 0.0f);
    uVar9 = 0u - (u32)((float)(uVar9 << 0x1e) != 0.0f);
    uVar12 = 0u - (u32)((float)(uVar12 << 0x1e) != 0.0f);
    fVar16 = (((RF_00721100[0] * fVar25 + RF_007210b0[0]) * fVar25 + RF_00721090[0]) *
              fVar25 + RF_00721070[0]) * fVar16;
    fVar2 = (((RF_00721100[1] * fVar8 + RF_007210b0[1]) * fVar8 + RF_00721090[1]) *
             fVar8 + RF_00721070[1]) * fVar2;
    fVar17 = (((RF_00721100[2] * fVar26 + RF_007210b0[2]) * fVar26 + RF_00721090[2]) *
              fVar26 + RF_00721070[2]) * fVar17;
    fVar5 = (((RF_00721100[3] * fVar11 + RF_007210b0[3]) * fVar11 + RF_00721090[3]) *
             fVar11 + RF_00721070[3]) * fVar5;
    fVar1 = (((RF_007210f0[0] * fVar25 + RF_007210a0[0]) * fVar25 + RF_00721080[0]) *
             fVar25 + RF_00721060[0]) * fVar25 + RF_00721050[0];
    fVar4 = (((RF_007210f0[1] * fVar8 + RF_007210a0[1]) * fVar8 + RF_00721080[1]) *
             fVar8 + RF_00721060[1]) * fVar8 + RF_00721050[1];
    fVar25 = (((RF_007210f0[2] * fVar26 + RF_007210a0[2]) * fVar26 + RF_00721080[2]) *
              fVar26 + RF_00721060[2]) * fVar26 + RF_00721050[2];
    fVar7 = (((RF_007210f0[3] * fVar11 + RF_007210a0[3]) * fVar11 + RF_00721080[3]) *
             fVar11 + RF_00721060[3]) * fVar11 + RF_00721050[3];
    *param_2 = (~uVar19 & (u32)fVar16 | uVar19 & (u32)fVar1) ^
               (uVar18 - uVar3 & RU_007210c0[0]) << 0x1e ^ *param_1 & RU_00721170[0];
    param_2[1] = (~uVar6 & (u32)fVar2 | uVar6 & (u32)fVar4) ^ uVar20 << 0x1e ^ uVar13;
    param_2[2] = (~uVar9 & (u32)fVar17 | uVar9 & (u32)fVar25) ^ uVar22 << 0x1e ^ uVar14;
    param_2[3] = (~uVar12 & (u32)fVar5 | uVar12 & (u32)fVar7) ^ uVar24 << 0x1e ^ uVar15;
    *param_3 = (uVar19 & (u32)fVar16 | ~uVar19 & (u32)fVar1) ^ uVar27 << 0x1e;
    param_3[1] = (uVar6 & (u32)fVar2 | ~uVar6 & (u32)fVar4) ^ uVar28 << 0x1e;
    param_3[2] = (uVar9 & (u32)fVar17 | ~uVar9 & (u32)fVar25) ^ uVar21 << 0x1e;
    param_3[3] = (uVar12 & (u32)fVar5 | ~uVar12 & (u32)fVar7) ^ uVar23 << 0x1e;
    return;
}

// ---- MMX packed-float primitives (two 32-bit float lanes per 64-bit value) ----
#include <cmath>

union F2 {
    u64 u;
    float f[2];
};

static inline u64 pf_pack(float lo, float hi)
{
    F2 r;
    r.f[0] = lo;
    r.f[1] = hi;
    return r.u;
}

static inline u64 pf_add(u64 a, u64 b)
{
    F2 x, y;
    x.u = a; y.u = b;
    return pf_pack(x.f[0] + y.f[0], x.f[1] + y.f[1]);
}

static inline u64 pf_sub(u64 a, u64 b)
{
    F2 x, y;
    x.u = a; y.u = b;
    return pf_pack(x.f[0] - y.f[0], x.f[1] - y.f[1]);
}

static inline u64 pf_subr(u64 a, u64 b)
{
    F2 x, y;
    x.u = a; y.u = b;
    return pf_pack(y.f[0] - x.f[0], y.f[1] - x.f[1]);
}

static inline u64 pf_mul(u64 a, u64 b)
{
    F2 x, y;
    x.u = a; y.u = b;
    return pf_pack(x.f[0] * y.f[0], x.f[1] * y.f[1]);
}

static inline u64 pf_max(u64 a, u64 b)
{
    F2 x, y;
    x.u = a; y.u = b;
    return pf_pack(x.f[0] > y.f[0] ? x.f[0] : y.f[0],
                   x.f[1] > y.f[1] ? x.f[1] : y.f[1]);
}

static inline u64 pf_min(u64 a, u64 b)
{
    F2 x, y;
    x.u = a; y.u = b;
    return pf_pack(x.f[0] < y.f[0] ? x.f[0] : y.f[0],
                   x.f[1] < y.f[1] ? x.f[1] : y.f[1]);
}

static inline u64 pf_rcp(u64 /*residue*/, u64 v)
{
    F2 x;
    x.u = v;
    return pf_pack(1.0f / x.f[0], 1.0f / x.f[1]);
}

static inline u64 pf_rcpit1(u64 v, u64 r)
{
    F2 a, b;
    a.u = v; b.u = r;
    return pf_pack(b.f[0] * (2.0f - a.f[0] * b.f[0]),
                   b.f[1] * (2.0f - a.f[1] * b.f[1]));
}

static inline u64 pf_rcpit2(u64 r, u64 /*approx*/)
{
    return r;
}

static inline u64 pf_rsqrt(u64 /*residue*/, u64 v)
{
    F2 x;
    x.u = v;
    return pf_pack(1.0f / sqrtf(x.f[0]), 1.0f / sqrtf(x.f[1]));
}

static inline u64 pf_rsqit1(u64 /*v*/, u64 r)
{
    return r;
}

static inline u64 pf_todword(u64 v)
{
    F2 x;
    x.u = v;
    return ((u64)(u32)(i32)x.f[1] << 32) | (u32)(i32)x.f[0];
}

static inline u64 pf_pi2fd(u64 v)
{
    F2 r;
    r.f[0] = (float)(i32)(u32)v;
    r.f[1] = (float)(i32)(u32)(v >> 32);
    return r.u;
}

static inline u64 pf_dup32(u32 d)
{
    return ((u64)d << 32) | (u64)d;
}

static inline u64 pf_concat44(u32 hi, u32 lo)
{
    return ((u64)hi << 32) | (u64)lo;
}

// ---- packed-math constant words ----
extern const u64 DAT_00721258;
extern const u64 DAT_0072125c;
extern const u64 DAT_00721288;
extern const u64 DAT_0072128c;
extern const u64 DAT_00721290;
extern const u64 DAT_00721294;
extern const u64 DAT_00721298;
extern const u64 DAT_0072129c;
extern const u64 DAT_007212a4;
extern const u64 DAT_007212a8;
extern const u64 DAT_007212ac;
extern const u64 DAT_007212b0;
extern const u64 DAT_007212b4;
extern const u64 DAT_007212b8;
extern const u64 DAT_0072126c;
extern const u64 DAT_00721274;
extern const u64 DAT_007211d8;
extern const u64 DAT_00721220;
extern const u64 DAT_00721228;
extern const u64 DAT_00721230;
extern const u64 DAT_00721238;
extern const u64 DAT_00721240;
extern const u64 DAT_00721248;
extern const u64 DAT_00721310;
extern const i32 DAT_00721268;
extern const i32 DAT_007212a0;

// 0x6a7a40 — observed shape
u64 FUN_006a7a40(u64 in_MM0, u64 in_MM1)
{
    u64 uVar1, uVar2, uVar3, uVar4, uVar5, uVar6, uVar9;
    u32 uVar7, uVar8;

    uVar9 = ((DAT_00721258 & in_MM0) >> 1) | (DAT_00721258 & in_MM1);
    uVar3 = in_MM1 & DAT_0072125c;
    uVar1 = in_MM0 & DAT_0072125c;
    uVar2 = pf_max(uVar1, uVar3);
    uVar7 = (u32)(((i32)uVar1 < (i32)uVar3) ? 0x80000000u : 0u);
    uVar4 = pf_min(uVar3, uVar1);
    uVar5 = pf_rcp(uVar1, uVar2);
    uVar2 = pf_rcpit1(uVar2, uVar5);
    uVar2 = pf_rcpit2(uVar2, uVar5);
    uVar2 = pf_mul(uVar2, uVar4);
    uVar4 = pf_mul(uVar2, uVar2);
    uVar5 = pf_add(DAT_00721290, uVar4);
    uVar6 = pf_mul(DAT_0072129c, uVar4);
    uVar5 = pf_mul(uVar5, uVar4);
    uVar6 = pf_add(uVar6, DAT_00721298);
    uVar5 = pf_add(uVar5, DAT_0072128c);
    uVar6 = pf_mul(uVar6, uVar4);
    uVar5 = pf_mul(uVar5, uVar4);
    uVar6 = pf_add(uVar6, DAT_00721294);
    uVar5 = pf_add(uVar5, DAT_00721288);
    uVar4 = pf_mul(uVar4, uVar6);
    uVar4 = pf_mul(uVar4, uVar2);
    uVar6 = pf_rcp(DAT_00721294, uVar5);
    uVar8 = (u32)((i32)uVar9 << 1);
    uVar5 = pf_rcpit1(uVar5, uVar6);
    uVar5 = pf_rcpit2(uVar5, uVar6);
    uVar4 = pf_mul(uVar4, uVar5);
    uVar1 = pf_add(uVar4, uVar2);
    uVar2 = pf_sub((~(u64)(u32)((i32)uVar7 >> 0x1f)) & ((u64)uVar8 ^ DAT_007212b8),
                   DAT_007212b8);
    uVar1 = pf_add(uVar1 | ((u64)uVar8 ^ (u64)uVar7), uVar2);
    return uVar1 | (DAT_00721258 & uVar9);
}

// 0x6a7b40 — observed shape
u64 FUN_006a7b40(u64 in_MM0)
{
    u32 uVar1, uVar4, uVar6;
    u64 uVar2, uVar3, uVar5, uVar7, uVar8, uVar9;

    uVar2 = in_MM0 & DAT_0072125c;
    uVar6 = 0u - (u32)(DAT_00721268 < (i32)uVar2);
    uVar3 = pf_mul(uVar2, DAT_0072126c);
    uVar3 = pf_subr(uVar3, DAT_0072126c);
    uVar7 = pf_rsqrt(DAT_0072125c, uVar3);
    uVar8 = pf_mul(uVar7, uVar7);
    uVar1 = (u32)((i32)uVar2 < DAT_007212a0);
    uVar4 = 0u - uVar1;
    uVar5 = (u64)uVar4;
    uVar8 = pf_rsqit1(uVar8, uVar3);
    uVar7 = pf_rcpit2(uVar8, uVar7);
    uVar9 = pf_mul(uVar7, uVar3);
    uVar2 = ((~uVar5) & uVar9) | (uVar2 & (u64)uVar4);
    uVar3 = pf_mul(uVar2, uVar2);
    uVar8 = pf_mul(DAT_007212a8, uVar3);
    uVar7 = pf_add(DAT_007212b0, uVar3);
    uVar8 = pf_add(uVar8, DAT_007212a4);
    uVar8 = pf_mul(uVar8, uVar3);
    uVar3 = pf_mul(uVar3, uVar7);
    uVar3 = pf_add(uVar3, DAT_007212ac);
    uVar8 = pf_mul(uVar8, uVar2);
    uVar7 = pf_rcp(uVar7, uVar3);
    uVar3 = pf_rcpit1(uVar3, uVar7);
    uVar3 = pf_rcpit2(uVar3, uVar7);
    uVar3 = pf_mul(uVar3, uVar8);
    uVar2 = pf_add(uVar2, uVar3);
    uVar3 = pf_add(((~uVar5) & DAT_007212b8) ^ (DAT_00721258 & in_MM0), DAT_007212b4);
    uVar2 = pf_add(uVar2, (~uVar5) & uVar2);
    uVar2 = pf_add(uVar3, (uVar2 | (u64)(u32)(uVar1 * 0x80000000u)) ^
                           (DAT_00721258 & in_MM0));
    return (u64)(DAT_00721274 & (u64)uVar6) | ((~(u64)uVar6) & uVar2);
}

// 0x6a8120 — observed shape
u32 FUN_006a8120(u64 in_MM0)
{
    u64 uVar1, uVar2, uVar4, uVar5, uVar6, uVar7;
    u32 uVar3;

    uVar1 = pf_mul(in_MM0 & DAT_0072125c, DAT_00721310);
    uVar2 = pf_todword(uVar1);
    uVar1 = pf_pi2fd(uVar2);
    uVar1 = pf_mul(pf_dup32((u32)uVar1), DAT_00721220);
    uVar4 = pf_add(in_MM0 & DAT_0072125c, uVar1);
    uVar3 = (u32)(uVar1 >> 0x20);
    uVar1 = pf_add(uVar4, pf_dup32(uVar3));
    uVar1 = pf_dup32((u32)uVar1);
    if ((uVar2 & 1) != 0) {
        uVar1 = pf_subr(uVar1, DAT_00721230);
    }
    uVar4 = pf_mul(uVar1, uVar1);
    uVar6 = pf_mul(DAT_00721228, uVar4);
    uVar5 = pf_mul(DAT_00721238, uVar4);
    uVar7 = pf_add(uVar6, DAT_007211d8);
    uVar6 = pf_mul(DAT_00721240, uVar4);
    uVar5 = pf_mul(uVar7, uVar5);
    uVar7 = pf_add(uVar5, DAT_007211d8);
    uVar5 = pf_mul(DAT_00721248, uVar4);
    uVar4 = pf_mul(uVar6, uVar7);
    uVar4 = pf_add(uVar4, DAT_007211d8);
    uVar4 = pf_mul(uVar4, pf_concat44((u32)DAT_007211d8, (u32)uVar5));
    uVar4 = pf_add(uVar4, DAT_007211d8 >> 0x20);
    pf_mul(uVar4, pf_concat44((u32)uVar1, (u32)DAT_007211d8));
    return (u32)in_MM0 ^ ((u32)in_MM0 & 0x80000000u);
}

// 0x6a8220 — observed shape
u32 FUN_006a8220(u64 in_MM0)
{
    u64 uVar1, uVar2, uVar4, uVar5, uVar6, uVar7;
    u32 uVar3;

    uVar1 = pf_mul(in_MM0 & DAT_0072125c, DAT_00721310);
    uVar2 = pf_todword(uVar1);
    uVar1 = pf_pi2fd(uVar2);
    uVar1 = pf_mul(pf_dup32((u32)uVar1), DAT_00721220);
    uVar4 = pf_add(in_MM0 & DAT_0072125c, uVar1);
    uVar3 = (u32)(uVar1 >> 0x20);
    uVar1 = pf_add(uVar4, pf_dup32(uVar3));
    uVar1 = pf_dup32((u32)uVar1);
    if ((uVar2 & 1) != 0) {
        uVar1 = pf_subr(uVar1, DAT_00721230);
    }
    uVar4 = pf_mul(uVar1, uVar1);
    uVar6 = pf_mul(DAT_00721228, uVar4);
    uVar5 = pf_mul(DAT_00721238, uVar4);
    uVar7 = pf_add(uVar6, DAT_007211d8);
    uVar6 = pf_mul(DAT_00721240, uVar4);
    uVar5 = pf_mul(uVar7, uVar5);
    uVar7 = pf_add(uVar5, DAT_007211d8);
    uVar5 = pf_mul(DAT_00721248, uVar4);
    uVar4 = pf_mul(uVar6, uVar7);
    uVar4 = pf_add(uVar4, DAT_007211d8);
    uVar4 = pf_mul(uVar4, pf_concat44((u32)DAT_007211d8, (u32)uVar5));
    uVar4 = pf_add(uVar4, DAT_007211d8 >> 0x20);
    pf_mul(uVar4, pf_concat44((u32)uVar1, (u32)DAT_007211d8));
    return (u32)in_MM0 ^ ((u32)in_MM0 & 0x80000000u);
}

// 0x6a85e0 — observed shape
void FUN_006a85e0(void* self_)
{
    u8* self = (u8*)self_;
    i32 iVar1, iVar2, iVar3, iVar4, iVar5, iVar6;
    i32* local_8;

    iVar1 = *(i32*)(self + 0x1ac);
    iVar2 = *(i32*)(self + 0x140);
    iVar4 = ((i32 (*)(void))(*(void***)(self + 4))[0])();
    iVar6 = *(i32*)(self + 0x24);
    *(i32*)(iVar1 + 0x38) = iVar4;
    iVar3 = *(i32*)(self + 0xdc);
    *(i32*)(iVar1 + 0x3c) = iVar4 + iVar6 * 4;
    iVar4 = 0;
    if (0 < iVar6) {
        local_8 = (i32*)(iVar3 + 0xc);
        do {
            iVar5 = (local_8[6] * *local_8) / *(i32*)(self + 0x140);
            iVar6 = ((i32 (*)(void))(*(void***)(self + 4))[0])();
            iVar6 = iVar6 + iVar5 * 4;
            iVar3 = *(i32*)(iVar1 + 0x3c);
            *(i32*)(*(i32*)(iVar1 + 0x38) + iVar4 * 4) = iVar6;
            *(i32*)(iVar3 + iVar4 * 4) = iVar6 + (iVar2 + 4) * iVar5 * 4;
            iVar4 = iVar4 + 1;
            local_8 = local_8 + 0x15;
        } while (iVar4 < *(i32*)(self + 0x24));
    }
    return;
}

// 0x6a8690 — observed shape
void FUN_006a8690(void* self_)
{
    u8* self = (u8*)self_;
    i32 iVar1, iVar3, iVar5, iVar9;
    u32 uVar4;
    u32* puVar2;
    u32* puVar6;
    u32* puVar7;
    u32* puVar8;
    i32 local_20, local_18;
    i32* local_14;
    i32* local_10;
    i32* local_c;

    iVar9 = *(i32*)(self + 0x1ac);
    iVar1 = *(i32*)(self + 0x140);
    local_20 = *(i32*)(self + 0x24);
    if (0 < local_20) {
        local_c = *(i32**)(iVar9 + 0x3c);
        local_10 = (i32*)(iVar9 + 8);
        local_14 = (i32*)(*(i32*)(self + 0xdc) + 0xc);
        iVar9 = *(i32*)(iVar9 + 0x38) - (i32)(intptr_t)local_c;
        do {
            iVar5 = (local_14[6] * *local_14) / iVar1;
            puVar2 = *(u32**)((intptr_t)local_c + iVar9);
            iVar3 = *local_10;
            puVar6 = (u32*)(intptr_t)*local_c;
            local_18 = (iVar1 + 2) * iVar5;
            if (0 < local_18) {
                puVar7 = puVar6;
                do {
                    uVar4 = *(u32*)((intptr_t)puVar7 + ((intptr_t)iVar3 - (intptr_t)puVar6));
                    *puVar7 = uVar4;
                    *(u32*)(((intptr_t)puVar2 - (intptr_t)puVar6) + (intptr_t)puVar7) = uVar4;
                    puVar7 = puVar7 + 1;
                    local_18 = local_18 + -1;
                } while (local_18 != 0);
            }
            if (0 < iVar5 * 2) {
                puVar7 = puVar6 + iVar5 * iVar1;
                puVar8 = (u32*)(iVar3 + (iVar1 + -2) * iVar5 * 4);
                local_18 = iVar5 * 2;
                do {
                    *(u32*)(((intptr_t)puVar6 - iVar3) + (intptr_t)puVar8) =
                        *(u32*)((intptr_t)puVar7 + ((intptr_t)iVar3 - (intptr_t)puVar6));
                    *puVar7 = *puVar8;
                    puVar8 = puVar8 + 1;
                    puVar7 = puVar7 + 1;
                    local_18 = local_18 + -1;
                } while (local_18 != 0);
            }
            if (0 < iVar5) {
                puVar6 = puVar2 + -iVar5;
                do {
                    *puVar6 = *puVar2;
                    puVar6 = puVar6 + 1;
                    iVar5 = iVar5 + -1;
                } while (iVar5 != 0);
            }
            local_c = local_c + 1;
            local_10 = local_10 + 1;
            local_14 = local_14 + 0x15;
            local_20 = local_20 + -1;
        } while (local_20 != 0);
    }
    return;
}

// 0x6a87d0 — observed shape
void FUN_006a87d0(void* self_)
{
    u8* self = (u8*)self_;
    i32 iVar1, iVar3, iVar5;
    u32* puVar2;
    u32* puVar4;
    u32* puVar6;
    u32* puVar7;
    i32 local_14, local_8;
    i32* local_10;
    i32* local_c;

    iVar1 = *(i32*)(self + 0x140);
    local_14 = *(i32*)(self + 0x24);
    if (0 < local_14) {
        local_c = *(i32**)(*(i32*)(self + 0x1ac) + 0x3c);
        local_10 = (i32*)(*(i32*)(self + 0xdc) + 0xc);
        iVar5 = *(i32*)(*(i32*)(self + 0x1ac) + 0x38) - (i32)(intptr_t)local_c;
        do {
            local_8 = (local_10[6] * *local_10) / iVar1;
            puVar6 = (u32*)(intptr_t)*local_c;
            if (0 < local_8) {
                puVar2 = puVar6 + (iVar1 + 2) * local_8;
                puVar4 = puVar6 + -local_8;
                puVar7 = puVar6 + (iVar1 + 1) * local_8;
                iVar3 = *(i32*)((intptr_t)local_c + iVar5) - (i32)(intptr_t)puVar6;
                do {
                    *(u32*)(iVar3 + (intptr_t)puVar4) = *(u32*)(iVar3 + (intptr_t)puVar7);
                    *puVar4 = *puVar7;
                    *(u32*)(iVar3 + (intptr_t)puVar2) = *(u32*)(iVar3 + (intptr_t)puVar6);
                    *puVar2 = *puVar6;
                    puVar7 = puVar7 + 1;
                    puVar4 = puVar4 + 1;
                    puVar6 = puVar6 + 1;
                    puVar2 = puVar2 + 1;
                    local_8 = local_8 + -1;
                } while (local_8 != 0);
            }
            local_c = local_c + 1;
            local_10 = local_10 + 0x15;
            local_14 = local_14 + -1;
        } while (local_14 != 0);
    }
    return;
}

// 0x6a88b0 — observed shape
void FUN_006a88b0(void* self_)
{
    u8* self = (u8*)self_;
    u32* puVar1;
    u32* puVar7;
    i32 iVar2, iVar3, iVar4, iVar5, iVar6;
    u32 uVar8, uVar10;
    i32* piVar9;
    i32 local_8;

    iVar2 = *(i32*)(self + 0x24);
    iVar3 = *(i32*)(self + 0x1ac);
    local_8 = 0;
    if (0 < iVar2) {
        iVar4 = *(i32*)(self + 0x140);
        iVar5 = *(i32*)(iVar3 + 0x40);
        piVar9 = (i32*)(*(i32*)(self + 0xdc) + 0xc);
        do {
            uVar8 = (u32)(piVar9[6] * *piVar9);
            iVar6 = (i32)uVar8 / iVar4;
            uVar10 = (u32)piVar9[8] % uVar8;
            if ((u32)piVar9[8] % uVar8 == 0) {
                uVar10 = uVar8;
            }
            if (local_8 == 0) {
                *(i32*)(iVar3 + 0x48) = (i32)(uVar10 - 1) / iVar6 + 1;
            }
            iVar6 = iVar6 * 2;
            if (0 < iVar6) {
                puVar1 = (u32*)(*(i32*)(*(i32*)(iVar3 + 0x38 + iVar5 * 4) +
                                        local_8 * 4) + uVar10 * 4);
                puVar7 = puVar1;
                do {
                    *puVar7 = puVar1[-1];
                    puVar7 = puVar7 + 1;
                    iVar6 = iVar6 + -1;
                } while (iVar6 != 0);
            }
            local_8 = local_8 + 1;
            piVar9 = piVar9 + 0x15;
        } while (local_8 < iVar2);
    }
    return;
}

// 0x6a8960 — observed shape
void FUN_006a8960(i32 param_1, u32 param_2, u32 param_3, u32 param_4)
{
    u32* puVar1;
    i32 iVar2, iVar4;
    u32 uVar3;

    iVar2 = *(i32*)(param_1 + 0x1ac);
    if (*(i32*)(iVar2 + 0x30) == 0) {
        iVar4 = ((i32 (*)(i32, i32))*(i32*)(*(i32*)(param_1 + 0x1b0) + 0xc))
                    (param_1, iVar2 + 8);
        if (iVar4 == 0) {
            return;
        }
        *(u32*)(iVar2 + 0x30) = 1;
    }
    uVar3 = *(u32*)(param_1 + 0x140);
    puVar1 = (u32*)(iVar2 + 0x34);
    ((void (*)(i32, i32, u32*, u32, u32, u32, u32))
        *(i32*)(*(i32*)(param_1 + 0x1b4) + 4))
            (param_1, iVar2 + 8, puVar1, uVar3, param_2, param_3, param_4);
    if (uVar3 <= *puVar1) {
        *(u32*)(iVar2 + 0x30) = 0;
        *puVar1 = 0;
    }
    return;
}

// 0x6a89e0 — observed shape
void FUN_006a89e0(i32 param_1, u32 param_2, u32* param_3, u32 param_4)
{
    u32* puVar1;
    i32 iVar2, iVar4;
    u32 uVar3;

    iVar2 = *(i32*)(param_1 + 0x1ac);
    if (*(i32*)(iVar2 + 0x30) == 0) {
        iVar4 = ((i32 (*)(i32, u32))*(i32*)(*(i32*)(param_1 + 0x1b0) + 0xc))
                    (param_1, *(u32*)(iVar2 + 0x38 + *(i32*)(iVar2 + 0x40) * 4));
        if (iVar4 == 0) {
            return;
        }
        *(u32*)(iVar2 + 0x30) = 1;
        *(i32*)(iVar2 + 0x4c) = *(i32*)(iVar2 + 0x4c) + 1;
    }
    iVar4 = *(i32*)(iVar2 + 0x44);
    if (iVar4 != 0) {
        if (iVar4 == 1) goto LAB_006a8aa2;
        if (iVar4 != 2) {
            return;
        }
        ((void (*)(i32, u32, u32*, u32, u32, u32*, u32))
            *(i32*)(*(i32*)(param_1 + 0x1b4) + 4))
                (param_1, *(u32*)(iVar2 + 0x38 + *(i32*)(iVar2 + 0x40) * 4),
                 (u32*)(iVar2 + 0x34), *(u32*)(iVar2 + 0x48), param_2, param_3, param_4);
        if (*(u32*)(iVar2 + 0x34) < *(u32*)(iVar2 + 0x48)) {
            return;
        }
        uVar3 = *param_3;
        *(u32*)(iVar2 + 0x44) = 0;
        if (param_4 <= uVar3) {
            return;
        }
    }
    *(i32*)(iVar2 + 0x48) = *(i32*)(param_1 + 0x140) + -1;
    iVar4 = *(i32*)(param_1 + 0x144);
    *(u32*)(iVar2 + 0x34) = 0;
    if (*(i32*)(iVar2 + 0x4c) == iVar4) {
        FUN_006a88b0((void*)param_1);
    }
    *(u32*)(iVar2 + 0x44) = 1;
LAB_006a8aa2:
    puVar1 = (u32*)(iVar2 + 0x34);
    ((void (*)(i32, u32, u32*, u32, u32, u32*, u32))
        *(i32*)(*(i32*)(param_1 + 0x1b4) + 4))
            (param_1, *(u32*)(iVar2 + 0x38 + *(i32*)(iVar2 + 0x40) * 4), puVar1,
             *(u32*)(iVar2 + 0x48), param_2, param_3, param_4);
    if (*(u32*)(iVar2 + 0x48) <= *puVar1) {
        if (*(i32*)(iVar2 + 0x4c) == 1) {
            FUN_006a87d0((void*)param_1);
        }
        iVar4 = *(i32*)(param_1 + 0x140);
        *(u32*)(iVar2 + 0x40) = *(u32*)(iVar2 + 0x40) ^ 1;
        *(u32*)(iVar2 + 0x30) = 0;
        *puVar1 = iVar4 + 1;
        *(i32*)(iVar2 + 0x48) = iVar4 + 2;
        *(u32*)(iVar2 + 0x44) = 2;
    }
    return;
}

// 0x6a8b10 — observed shape
void FUN_006a8b10(i32* param_1, i32 param_2)
{
    i32 iVar1;
    u32* puVar2;

    iVar1 = param_1[0x6b];
    if (param_2 != 0) {
        puVar2 = (u32*)*param_1;
        puVar2[5] = 4;
        ((void (*)(i32*))(intptr_t)puVar2[0])(param_1);
        return;
    }
    if (*(i32*)(param_1[0x72] + 8) == 0) {
        *(u32*)(iVar1 + 0x30) = 0;
        *(u32*)(iVar1 + 0x34) = 0;
        *(void**)(iVar1 + 4) = (void*)(intptr_t)&FUN_006a8960;
        return;
    }
    *(void**)(iVar1 + 4) = (void*)(intptr_t)&FUN_006a89e0;
    FUN_006a8690((void*)param_1);
    *(u32*)(iVar1 + 0x40) = 0;
    *(u32*)(iVar1 + 0x44) = 0;
    *(u32*)(iVar1 + 0x4c) = 0;
    *(u32*)(iVar1 + 0x30) = 0;
    *(u32*)(iVar1 + 0x34) = 0;
    return;
}

// 0x6a8b80 — observed shape
void FUN_006a8b80(i32* param_1, i32 param_2)
{
    u32* puVar1;
    i32 iVar2;
    i32* piVar3;
    u32* puVar4;
    u32 uVar5;
    i32* piVar6;

    piVar3 = param_1;
    {
        i32 iVarAlloc = ((i32 (*)(i32*, i32, i32))*(i32*)(intptr_t)param_1[1])
                            (param_1, 1, 0x50);
        puVar4 = (u32*)(intptr_t)iVarAlloc;
    }
    param_1[0x6b] = (i32)(intptr_t)puVar4;
    *puVar4 = (u32)(intptr_t)&FUN_006a8b10;
    if (param_2 != 0) {
        puVar1 = (u32*)*param_1;
        puVar1[5] = 4;
        ((void (*)(i32*))(intptr_t)puVar1[0])(param_1);
    }
    if (*(i32*)(param_1[0x72] + 8) == 0) {
        param_1 = (i32*)(intptr_t)param_1[0x50];
    } else {
        if (param_1[0x50] < 2) {
            puVar1 = (u32*)*param_1;
            puVar1[5] = 0x2f;
            ((void (*)(i32*))(intptr_t)puVar1[0])(param_1);
        }
        FUN_006a85e0((void*)param_1);
        param_1 = (i32*)(intptr_t)(param_1[0x50] + 2);
    }
    param_2 = 0;
    if (0 < piVar3[9]) {
        piVar6 = (i32*)(piVar3[0x37] + 0x24);
        puVar4 = puVar4 + 2;
        do {
            uVar5 = ((u32 (*)(i32*, i32, i32, i32))*(i32*)(piVar3[1] + 8))
                        (piVar3, 1, piVar6[-2] * *piVar6,
                         ((piVar6[-6] * *piVar6) / piVar3[0x50]) * (i32)(intptr_t)param_1);
            iVar2 = piVar3[9];
            *puVar4 = uVar5;
            param_2 = param_2 + 1;
            puVar4 = puVar4 + 1;
            piVar6 = piVar6 + 0x15;
        } while (param_2 < iVar2);
    }
    return;
}

// 0x6a8c60 — observed shape
void FUN_006a8c60(void* self_)
{
    u8* self = (u8*)self_;
    i32 iVar1;
    u32 uVar2;

    iVar1 = *(i32*)(self + 0x1b0);
    uVar2 = 1;
    if (*(i32*)(self + 0x14c) < 2) {
        if (*(u32*)(self + 0x98) < (u32)(*(i32*)(self + 0x144) - 1)) {
            *(u32*)(iVar1 + 0x1c) = *(u32*)(*(i32*)(self + 0x150) + 0xc);
            *(u32*)(iVar1 + 0x14) = 0;
            *(u32*)(iVar1 + 0x18) = 0;
            return;
        }
        uVar2 = *(u32*)(*(i32*)(self + 0x150) + 0x48);
    }
    *(u32*)(iVar1 + 0x1c) = uVar2;
    *(u32*)(iVar1 + 0x14) = 0;
    *(u32*)(iVar1 + 0x18) = 0;
    return;
}

// 0x6a8cd0 — observed shape
u32 FUN_006a8cd0(i32 param_1, i32 param_2)
{
    i32 iVar1, iVar2, iVar3, iVar5, iVar6, iVar7, iVar10;
    u32 uVar8, uVar9;
    void (*pcVar4)(i32, i32, u32, i32, i32);
    u32* puVar11;
    i32* local_1c;
    i32 local_30, local_2c, local_28, local_18, local_14, local_8;
    u32 local_c;

    iVar1 = *(i32*)(param_1 + 0x144);
    uVar8 = (u32)(*(i32*)(param_1 + 0x160) - 1);
    iVar2 = *(i32*)(param_1 + 0x1b0);
    local_8 = *(i32*)(iVar2 + 0x18);
    if (local_8 < *(i32*)(iVar2 + 0x1c)) {
        do {
            local_c = *(u32*)(iVar2 + 0x14);
            if (local_c <= uVar8) {
                do {
                    FUN_00692470(*(i32*)(iVar2 + 0x20), *(i32*)(param_1 + 0x168) << 7);
                    iVar6 = ((i32 (*)(i32, i32))*(i32*)(*(i32*)(param_1 + 0x1c0) + 4))
                                (param_1, iVar2 + 0x20);
                    if (iVar6 == 0) {
                        *(u32*)(iVar2 + 0x14) = local_c;
                        *(i32*)(iVar2 + 0x18) = local_8;
                        return 0;
                    }
                    iVar6 = 0;
                    local_14 = 0;
                    local_30 = 0;
                    if (0 < *(i32*)(param_1 + 0x14c)) {
                        local_1c = (i32*)(param_1 + 0x150);
                        do {
                            iVar3 = *local_1c;
                            if (*(i32*)(iVar3 + 0x30) == 0) {
                                iVar6 = iVar6 + *(i32*)(iVar3 + 0x3c);
                                local_14 = iVar6;
                            } else {
                                iVar7 = *(i32*)(iVar3 + 4) * 4;
                                pcVar4 = (void (*)(i32, i32, u32, i32, i32))
                                    *(i32*)(*(i32*)(param_1 + 0x1c4) + 4 + iVar7);
                                if (local_c < uVar8) {
                                    iVar10 = *(i32*)(iVar3 + 0x34);
                                } else {
                                    iVar10 = *(i32*)(iVar3 + 0x44);
                                }
                                iVar5 = *(i32*)(iVar3 + 0x40);
                                local_18 = *(i32*)(iVar7 + param_2) +
                                           *(i32*)(iVar3 + 0x24) * local_8 * 4;
                                local_2c = 0;
                                if (0 < *(i32*)(iVar3 + 0x38)) {
                                    do {
                                        if (((*(u32*)(param_1 + 0x98) <
                                              (u32)(iVar1 - 1)) ||
                                             (local_8 + local_2c < *(i32*)(iVar3 + 0x48))) &&
                                            (0 < iVar10)) {
                                            puVar11 = (u32*)(iVar2 + 0x20 + iVar6 * 4);
                                            iVar6 = (i32)((u32)iVar5 * local_c);
                                            local_28 = iVar10;
                                            do {
                                                (*pcVar4)(param_1, iVar3, *puVar11,
                                                          local_18, iVar6);
                                                iVar6 = iVar6 + *(i32*)(iVar3 + 0x24);
                                                puVar11 = puVar11 + 1;
                                                local_28 = local_28 + -1;
                                            } while (local_28 != 0);
                                            iVar6 = local_14;
                                        }
                                        iVar6 = iVar6 + *(i32*)(iVar3 + 0x34);
                                        local_18 = local_18 + *(i32*)(iVar3 + 0x24) * 4;
                                        local_2c = local_2c + 1;
                                        local_14 = iVar6;
                                    } while (local_2c < *(i32*)(iVar3 + 0x38));
                                }
                            }
                            local_30 = local_30 + 1;
                            local_1c = local_1c + 1;
                        } while (local_30 < *(i32*)(param_1 + 0x14c));
                    }
                    local_c = local_c + 1;
                } while (local_c <= uVar8);
            }
            *(u32*)(iVar2 + 0x14) = 0;
            local_8 = local_8 + 1;
        } while (local_8 < *(i32*)(iVar2 + 0x1c));
    }
    *(i32*)(param_1 + 0xa0) = *(i32*)(param_1 + 0xa0) + 1;
    uVar8 = *(u32*)(param_1 + 0x98) + 1;
    *(u32*)(param_1 + 0x98) = uVar8;
    if (*(u32*)(param_1 + 0x144) <= uVar8) {
        ((void (*)(i32))*(i32*)(*(i32*)(param_1 + 0x1b8) + 0xc))(param_1);
        return 4;
    }
    iVar1 = *(i32*)(param_1 + 0x1b0);
    if (1 < *(i32*)(param_1 + 0x14c)) {
        *(u32*)(iVar1 + 0x1c) = 1;
        *(u32*)(iVar1 + 0x14) = 0;
        *(u32*)(iVar1 + 0x18) = 0;
        return 3;
    }
    if (uVar8 < (u32)(*(i32*)(param_1 + 0x144) - 1)) {
        uVar9 = *(u32*)(*(i32*)(param_1 + 0x150) + 0xc);
    } else {
        uVar9 = *(u32*)(*(i32*)(param_1 + 0x150) + 0x48);
    }
    *(u32*)(iVar1 + 0x1c) = uVar9;
    *(u32*)(iVar1 + 0x14) = 0;
    *(u32*)(iVar1 + 0x18) = 0;
    return 3;
}

// 0x6a8f40 — observed shape
u32 FUN_006a8f40(i32 param_1)
{
    i32 iVar1, iVar2, iVar4, iVar6;
    u32 uVar5, uVar8;
    i32* piVar3;
    i32* piVar7;
    i32 aiStack_38[4];
    i32 local_28, local_24, local_1c, local_18, local_10, local_8;
    u32 local_20;
    i32* local_14;
    i32* local_c;

    local_8 = *(i32*)(param_1 + 0x1b0);
    iVar6 = 0;
    if (0 < *(i32*)(param_1 + 0x14c)) {
        local_c = (i32*)(param_1 + 0x150);
        do {
            iVar1 = *(i32*)(*local_c + 0xc);
            iVar1 = ((i32 (*)(i32, u32, i32, i32, i32))
                        *(i32*)(*(i32*)(param_1 + 4) + 0x20))
                        (param_1,
                         *(u32*)(local_8 + 0x48 + *(i32*)(*local_c + 4) * 4),
                         *(i32*)(param_1 + 0x98) * iVar1, iVar1, 1);
            aiStack_38[iVar6] = iVar1;
            iVar6 = iVar6 + 1;
            local_c = local_c + 1;
        } while (iVar6 < *(i32*)(param_1 + 0x14c));
    }
    local_c = *(i32**)(local_8 + 0x18);
    if ((i32)(intptr_t)local_c < *(i32*)(local_8 + 0x1c)) {
        do {
            uVar8 = *(u32*)(local_8 + 0x14);
            local_20 = uVar8;
            if (uVar8 < *(u32*)(param_1 + 0x160)) {
                do {
                    iVar6 = *(i32*)(param_1 + 0x14c);
                    local_10 = 0;
                    local_1c = 0;
                    if (0 < iVar6) {
                        local_28 = iVar6;
                        local_14 = (i32*)(param_1 + 0x150);
                        do {
                            iVar1 = *(i32*)(*local_14 + 0x34);
                            iVar2 = *(i32*)(*local_14 + 0x38);
                            if (0 < iVar2) {
                                local_24 = (i32)((u32)iVar1 * uVar8 * 0x80u);
                                piVar7 = (i32*)(aiStack_38[local_1c] +
                                                (i32)(intptr_t)local_c * 4);
                                local_18 = iVar2;
                                do {
                                    iVar2 = *piVar7 + local_24;
                                    if (0 < iVar1) {
                                        piVar3 = (i32*)(local_8 + 0x20 + local_10 * 4);
                                        local_10 = local_10 + iVar1;
                                        iVar4 = iVar1;
                                        do {
                                            *piVar3 = iVar2;
                                            piVar3 = piVar3 + 1;
                                            iVar2 = iVar2 + 0x80;
                                            iVar4 = iVar4 + -1;
                                        } while (iVar4 != 0);
                                    }
                                    piVar7 = piVar7 + 1;
                                    local_18 = local_18 + -1;
                                } while (local_18 != 0);
                            }
                            local_1c = local_1c + 1;
                            local_14 = local_14 + 1;
                        } while (local_1c < iVar6);
                    }
                    local_20 = uVar8;
                    iVar6 = ((i32 (*)(i32, i32))
                                *(i32*)(*(i32*)(param_1 + 0x1c0) + 4))
                                (param_1, local_8 + 0x20);
                    if (iVar6 == 0) {
                        *(u32*)(local_8 + 0x14) = uVar8;
                        *(i32**)(local_8 + 0x18) = local_c;
                        return 0;
                    }
                    uVar8 = uVar8 + 1;
                    local_20 = uVar8;
                } while (uVar8 < *(u32*)(param_1 + 0x160));
            }
            *(u32*)(local_8 + 0x14) = 0;
            local_c = (i32*)((intptr_t)local_c + 1);
        } while ((i32)(intptr_t)local_c < *(i32*)(local_8 + 0x1c));
    }
    uVar8 = *(u32*)(param_1 + 0x98) + 1;
    *(u32*)(param_1 + 0x98) = uVar8;
    if (*(u32*)(param_1 + 0x144) <= uVar8) {
        ((void (*)(i32))*(i32*)(*(i32*)(param_1 + 0x1b8) + 0xc))(param_1);
        return 4;
    }
    iVar6 = *(i32*)(param_1 + 0x1b0);
    if (1 < *(i32*)(param_1 + 0x14c)) {
        *(u32*)(iVar6 + 0x1c) = 1;
        *(u32*)(iVar6 + 0x14) = 0;
        *(u32*)(iVar6 + 0x18) = 0;
        return 3;
    }
    if (uVar8 < (u32)(*(i32*)(param_1 + 0x144) - 1)) {
        uVar5 = *(u32*)(*(i32*)(param_1 + 0x150) + 0xc);
    } else {
        uVar5 = *(u32*)(*(i32*)(param_1 + 0x150) + 0x48);
    }
    *(u32*)(iVar6 + 0x1c) = uVar5;
    *(u32*)(iVar6 + 0x14) = 0;
    *(u32*)(iVar6 + 0x18) = 0;
    return 3;
}
