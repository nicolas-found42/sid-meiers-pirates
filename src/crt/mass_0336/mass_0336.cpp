// Reconstruction batch mass_0336
// Sid Meier's Pirates! (2004) — PE32 i386
// Candidate definitions derived from Ghidra 12.2 pseudocode (corpus:
// analysis/pseudocode/functions/0x*.c). Pseudocode is provider output, not
// original source; shapes, offsets and call order are preserved.
// Register receivers (in_ECX) are exposed as an explicit `self` parameter.

#include <cstdint>
#include <cstddef>
#include <cmath>
#include <windows.h>

// ---------------------------------------------------------------------------
// Referenced helpers (names and signatures as observed at the call sites).
// ---------------------------------------------------------------------------
extern int32_t FUN_00694b7c(void* rec, const void* pattern, void* out1, void* out2,
                            void* out3, void* out4, uint32_t count, uint32_t flag);
extern int32_t FUN_006949cb(void* rec, void* idx, uint32_t count, void* table,
                            void* out, void* desc, int32_t flag);
extern int32_t FUN_0065d0b4(uint32_t size = 0x74);
extern int32_t FUN_0065cc1a(void);
extern int32_t FUN_0065d0ff(uint32_t magic, uint32_t a, uint32_t b, int32_t c);
extern int32_t FUN_0065cc50(void* rec);
extern int32_t FUN_0065d35e(int32_t obj);
extern int32_t FUN_0065d501(void);
extern int32_t FUN_0065d5bd(int32_t index = 0);
extern int32_t FUN_0065d9d5(uint32_t a, uint32_t b, uint32_t c, uint64_t d);
extern int32_t FUN_0065d97c(const void* str, uint32_t len, uint32_t a, uint32_t b);
extern void    FUN_006626da(void* self = nullptr, uint32_t code = 0, int32_t site = 0,
                            const char* msg = nullptr);
extern void    FUN_00614343(int32_t flag = 1);

// Batch siblings called from 0x697497.
extern uint32_t FUN_696b3c(void* self, int32_t* param_1, uint32_t* param_2, int32_t* param_3);
extern int32_t  FUN_697138(void* self, int32_t* param_1, uint32_t* param_2, int32_t* param_3);
extern int32_t  FUN_69927f(void* self);

// ---------------------------------------------------------------------------
// Referenced globals (declared as raw byte images; the listings index them
// with explicit strides, so the element types stay at the use site).
// ---------------------------------------------------------------------------
extern uint8_t DAT_006f2840[];
extern uint8_t DAT_006f284c[];
extern uint8_t DAT_006f2858[];
extern uint8_t DAT_006f1d00[];
extern uint8_t DAT_006f1d60[];
extern uint8_t DAT_006f1de0[];
extern uint8_t DAT_006f2280[];
extern uint8_t DAT_006f22e0[];
extern uint8_t DAT_006f2340[];
extern uint8_t DAT_006f1ee0[];
extern uint8_t DAT_006f34c8[];
// Additional tables referenced only by 0x697497.
extern uint8_t DAT_006f1cac[];
extern uint8_t DAT_006f1cb8[];
extern uint8_t DAT_006f1ca0[];
extern uint8_t DAT_006f1c4c[];
extern uint8_t DAT_006f1c58[];
extern uint8_t DAT_006f1c40[];
extern uint8_t DAT_006f1a4c[];
extern uint8_t DAT_006f1a58[];
extern uint8_t DAT_006f1a40[];
extern uint8_t DAT_006f1bac[];
extern uint8_t DAT_006f1bb8[];
extern uint8_t DAT_006f1ba0[];
extern uint8_t DAT_006f1aec[];
extern uint8_t DAT_006f1af8[];
extern uint8_t DAT_006f1ae0[];

// 0x696630 — observed shape
int32_t FUN_696630(void* self)
{
    uint32_t local_278[40];
    uint32_t local_1d8[40];
    int32_t  local_138[40];
    uint8_t  local_98[16];
    uint32_t* local_88[16];
    uint32_t local_48[5];
    int32_t  local_34;
    uint32_t* local_30;
    int32_t  local_2c;
    int32_t  local_28;
    uint32_t* local_24;
    int32_t  local_20;
    uint32_t local_1c;
    uint32_t local_18;
    uint32_t local_14;
    void*    local_10;
    int32_t  local_c;
    uint32_t local_8;

    uintptr_t uVar1;
    uint32_t  uVar2;
    uint32_t  uVar8;
    uint32_t  uVar9;
    uint32_t* puVar3;
    int32_t   iVar4;
    int32_t   iVar6;
    int32_t*  piVar5;
    uint32_t* puVar7;
    uint32_t* puVar10;

    local_48[0] = 0;
    local_24 = *(uint32_t**)((uint8_t*)self + 0x100);
    local_48[1] = 1;
    local_48[2] = 2;
    local_48[3] = 3;
    if (((*local_24 & 0xfffff) == 1) &&
        ((*(uint8_t*)(*(int32_t*)(*(int32_t*)((uint8_t*)self + 0x10) +
                    *(int32_t*)(*(int32_t*)(*(int32_t*)((uint8_t*)self + 0x14) +
                                            *(int32_t*)local_24[4] * 4) + 4) * 4) + 4) & 0x20) == 0)) {
        local_18 = *local_24 & 0xfffff;
        if ((local_18 < 2) && ((*local_24 & 0xfff00000) == 0x10500000)) {
            local_28 = 0;
            local_10 = self;
            do {
                local_20 = 0;
                do {
                    piVar5 = (int32_t*)local_1d8;
                    for (iVar4 = 0x28; iVar4 != 0; iVar4 = iVar4 - 1) {
                        *piVar5 = -1;
                        piVar5 = piVar5 + 1;
                    }
                    iVar6 = 0;
                    piVar5 = (int32_t*)local_278;
                    for (iVar4 = 0x28; iVar4 != 0; iVar4 = iVar4 - 1) {
                        *piVar5 = -1;
                        piVar5 = piVar5 + 1;
                    }
                    local_14 = 0;
                    local_c = 0;
                    local_8 = 0;
                    do {
                        if (local_20 == 0) {
                            uVar9 = local_8;
                        }
                        else {
                            uVar9 = 1 - local_8;
                        }
                        uVar1 = local_24[2];
                        uVar9 = *(uint32_t*)(&DAT_006f284c[0] + uVar9 * 4);
                        piVar5 = (int32_t*)(uVar1 + iVar6 * 4);
                        if (uVar9 < 0x10) {
                            iVar4 = *(int32_t*)(*(int32_t*)(*(int32_t*)((uint8_t*)local_10 + 0x14) +
                                                            *piVar5 * 4) + 0x48);
                            if (iVar4 != -1) {
                                uVar2 = *(uint32_t*)(*(int32_t*)((uint8_t*)local_10 + 0x18) +
                                                     iVar4 * 4);
                                iVar4 = FUN_006949cb((void*)(uintptr_t)uVar2, piVar5, local_18,
                                                     local_48, local_98,
                                                     &DAT_006f2858[0] + uVar9 * 0x20, 0);
                                if (iVar4 == 0) {
                                    local_c = FUN_00694b7c((void*)(uintptr_t)uVar2,
                                                           &DAT_006f2840[0] + uVar9 * 0x20,
                                                           local_88, &local_14, local_278,
                                                           local_98, 1, 0);
                                    goto LAB_006967b9;
                                }
                            }
                            local_c = 1;
                            break;
                        }
                        uVar8 = 0;
                        piVar5 = (int32_t*)(local_1d8 + (uVar9 - 0x10) * 4);
                        do {
                            if (local_48[uVar8] < local_18) {
                                *piVar5 = *(int32_t*)(uVar1 + (local_48[uVar8] + iVar6) * 4);
                            }
                            else {
                                *piVar5 = -1;
                            }
                            uVar8 = uVar8 + 1;
                            piVar5 = piVar5 + 1;
                        } while (uVar8 < 4);
LAB_006967b9:
                        if (local_c == 1) break;
                        local_8 = local_8 + 1;
                        iVar6 = iVar6 + (int32_t)local_18;
                    } while (local_8 == 0);
                    if ((0xf < *(uint32_t*)(&DAT_006f284c[0] + (uint32_t)(local_20 != 0) * 4)) &&
                        (local_8 = 0, local_14 != 0)) {
                        do {
                            uVar9 = 0;
                            if (local_18 != 0) {
                                uVar1 = *(uint32_t*)((uint8_t*)local_88[local_8] + 0xc);
                                do {
                                    local_1c = 0;
                                    if (uVar1 != 0) {
                                        piVar5 = *(int32_t**)((uint8_t*)local_88[local_8] + 0x10);
                                        do {
                                            if (*(int32_t*)(uintptr_t)(local_24[2] + uVar9 * 4) ==
                                                *piVar5) {
                                                local_c = 1;
                                                goto LAB_0069683a;
                                            }
                                            local_1c = local_1c + 1;
                                            piVar5 = piVar5 + 1;
                                        } while (local_1c < uVar1);
                                    }
                                    uVar9 = uVar9 + 1;
                                } while (uVar9 < local_18);
                            }
LAB_0069683a:
                            local_8 = local_8 + 1;
                        } while (local_8 < local_14);
                    }
                    if (local_c == 0) {
                        if (local_28 != 0) goto LAB_006969c6;
                        local_1c = 0;
                        if (local_14 != 0) {
                            do {
                                local_48[4] = *(uint32_t*)((uint8_t*)local_88[local_1c] + 0xc);
                                local_8 = 0;
                                if (local_48[4] != 0) {
                                    do {
                                        if (*(int32_t*)((uint8_t*)local_10 + 0xc) != 0) {
                                            local_30 = *(uint32_t**)((uint8_t*)local_10 + 0x18);
                                            local_34 = *(int32_t*)((uint8_t*)local_10 + 0xc);
                                            do {
                                                puVar3 = (uint32_t*)*local_30;
                                                if ((puVar3 != (uint32_t*)0x0) && (*puVar3 != 0)) {
                                                    uVar9 = puVar3[1];
                                                    local_2c = 0;
                                                    if (uVar9 != 0) {
                                                        iVar4 = *(int32_t*)(
                                                            *(int32_t*)((uint8_t*)local_88[local_1c] + 0x10) +
                                                            local_8 * 4);
                                                        piVar5 = (int32_t*)puVar3[2];
                                                        do {
                                                            if ((*piVar5 == iVar4) ||
                                                                (*(int32_t*)(*(int32_t*)(*(int32_t*)((uint8_t*)local_10 + 0x14) + *piVar5 * 4) + 0x38) == iVar4)) {
                                                                local_2c = 1;
                                                            }
                                                            piVar5 = piVar5 + 1;
                                                            uVar9 = uVar9 - 1;
                                                        } while (uVar9 != 0);
                                                    }
                                                    if (puVar3 == local_24) {
                                                        iVar4 = 0;
                                                    }
                                                    else {
                                                        iVar4 = local_2c;
                                                    }
                                                    if (iVar4 != 0) {
                                                        uVar9 = 0;
                                                        do {
                                                            if (puVar3 == (uint32_t*)local_88[uVar9]) {
                                                                iVar4 = 0;
                                                            }
                                                            uVar9 = uVar9 + 1;
                                                        } while (uVar9 < local_14);
                                                        if (iVar4 != 0) {
                                                            local_c = 1;
                                                        }
                                                    }
                                                }
                                                local_30 = local_30 + 1;
                                                local_34 = local_34 + -1;
                                            } while (local_34 != 0);
                                        }
                                        local_8 = local_8 + 1;
                                    } while (local_8 < local_48[4]);
                                }
                                local_1c = local_1c + 1;
                            } while (local_1c < local_14);
                        }
                        local_8 = 0;
                        do {
                            iVar4 = (int32_t)local_1d8[local_8];
                            if ((iVar4 != -1) && (uVar9 = 0, local_14 != 0)) {
                                do {
                                    iVar6 = *(int32_t*)((uint8_t*)local_88[uVar9] + 0xc);
                                    if (iVar6 != 0) {
                                        piVar5 = *(int32_t**)((uint8_t*)local_88[uVar9] + 0x10);
                                        do {
                                            if ((iVar4 == *piVar5) ||
                                                (*(int32_t*)(*(int32_t*)(*(int32_t*)((uint8_t*)local_10 + 0x14) + iVar4 * 4) + 0x38) == *piVar5)) {
                                                local_c = 1;
                                            }
                                            piVar5 = piVar5 + 1;
                                            iVar6 = iVar6 + -1;
                                        } while (iVar6 != 0);
                                    }
                                    uVar9 = uVar9 + 1;
                                } while (uVar9 < local_14);
                            }
                            local_8 = local_8 + 1;
                        } while (local_8 < 0x28);
                        if (local_c == 0) goto LAB_006969c6;
                    }
                    local_20 = local_20 + 1;
                } while (local_20 == 0);
                if (local_c == 0) {
LAB_006969c6:
                    local_88[local_14] = local_24;
                    uVar9 = 0;
                    do {
                        iVar4 = *(int32_t*)((uint8_t*)local_1d8 + uVar9);
                        if ((iVar4 != -1) ||
                            (iVar4 = *(int32_t*)((uint8_t*)local_278 + uVar9), iVar4 != -1)) {
                            *(int32_t*)((uint8_t*)local_138 + uVar9) = iVar4;
                        }
                        uVar9 = uVar9 + 4;
                    } while (uVar9 < 0xa0);
                    local_c = 0;
LAB_00696a02:
                    if (local_c != 0) {
                        return local_c;
                    }
                    iVar4 = FUN_0065d0b4(0x74);
                    if (iVar4 == 0) {
                        iVar4 = 0;
                    }
                    else {
                        iVar4 = FUN_0065cc1a();
                    }
                    if (iVar4 == 0) {
                        return -0x7ff8fff2;
                    }
                    iVar6 = FUN_0065d0ff(0x70d00001, 2, 1, 0);
                    if ((-1 < iVar6) &&
                        (iVar6 = FUN_0065cc50(*(void**)((uint8_t*)local_10 + 0x100)), -1 < iVar6)) {
                        puVar7 = *(uint32_t**)(*(int32_t*)((uint8_t*)local_10 + 0x100) + 0x10);
                        puVar10 = *(uint32_t**)(iVar4 + 0x10);
                        for (uVar9 = *(uint32_t*)(*(int32_t*)((uint8_t*)local_10 + 0x100) + 0xc) &
                                      0x3fffffff;
                             uVar9 != 0; uVar9 = uVar9 - 1) {
                            *puVar10 = *puVar7;
                            puVar7 = puVar7 + 1;
                            puVar10 = puVar10 + 1;
                        }
                        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
                            *(uint8_t*)puVar10 = *(uint8_t*)puVar7;
                            puVar7 = (uint32_t*)((uint8_t*)puVar7 + 1);
                            puVar10 = (uint32_t*)((uint8_t*)puVar10 + 1);
                        }
                        **(uint32_t**)(iVar4 + 8) = (uint32_t)local_138[4];
                        *(int32_t*)(*(int32_t*)(iVar4 + 8) + 4) = local_138[0];
                        iVar6 = FUN_0065d35e(iVar4);
                    }
                    FUN_00614343(1);
                    return iVar6;
                }
                local_28 = local_28 + 1;
                if (local_28 != 0) goto LAB_00696a02;
            } while (true);
        }
    }
    return 1;
}

// 0x696ab9 — observed shape
uint32_t FUN_696ab9(void* self)
{
    uint32_t uVar2;
    int32_t  iVar3;
    uint32_t local_8;

    uVar2 = **(uint32_t**)((uint8_t*)self + 0x100) & 0xfffff;
    if ((*(uint8_t*)(*(int32_t*)(*(int32_t*)((uint8_t*)self + 0x10) +
                   *(int32_t*)(*(int32_t*)(*(int32_t*)((uint8_t*)self + 0x14) +
                                          *(int32_t*)(*(int32_t*)(*(int32_t*)((uint8_t*)self + 0x14) +
                                                                *(int32_t*)(*(int32_t*)(*(int32_t*)((uint8_t*)self + 0x14) +
                                                                                      *(int32_t*)(*(uint32_t**)((uint8_t*)self + 0x100))[2] * 4) +
                                                                           0x30) * 4) + 4) * 4) +
                                          4) * 4) + 4) & 0x80) == 0) {
        return 1;
    }
    local_8 = 0;
    if (uVar2 != 0) {
        do {
            iVar3 = local_8 * 4;
            local_8 = local_8 + 1;
            *(uint32_t*)(*(int32_t*)(*(int32_t*)((uint8_t*)self + 0x14) +
                         *(int32_t*)(iVar3 + *(int32_t*)(*(int32_t*)((uint8_t*)self + 0x100) + 0x10)) * 4) +
                         0x30) =
                *(uint32_t*)(*(int32_t*)(*(int32_t*)((uint8_t*)self + 0x14) +
                             *(int32_t*)(iVar3 + *(int32_t*)(*(int32_t*)((uint8_t*)self + 0x100) + 8)) * 4) +
                             0x30);
        } while (local_8 < uVar2);
    }
    **(uint32_t**)((uint8_t*)self + 0x100) = 0;
    return 0;
}

// 0x696b3c — observed shape
uint32_t FUN_696b3c(void* self, int32_t* param_1, uint32_t* param_2, int32_t* param_3)
{
    uint32_t uVar5;
    uint32_t uVar6;
    bool     bVar2;
    int32_t  iVar1;
    int32_t  iVar3;
    int32_t  iVar4;
    int32_t* piVar7;
    uint32_t* puVar8;
    uint32_t* puVar9;
    uint32_t* puVar10;
    int32_t* piVar11;
    uint32_t* puVar12;

    uint32_t local_128[16];
    int32_t  local_e8[4];
    uint32_t local_d8[4];
    int32_t  aiStack_c8[4];
    uint32_t auStack_b8[28];
    uint32_t local_48;
    uint32_t local_44;
    uint32_t local_40;
    uint32_t local_3c;
    int32_t  local_38;
    int32_t  local_34;
    uint32_t local_30;
    int32_t  local_2c;
    uint32_t local_28;
    int32_t  local_24;
    uint32_t local_20;
    int32_t  local_1c;
    uint32_t local_18;
    uint32_t local_14;
    int32_t  local_10;
    uint32_t local_c;
    uint32_t local_8;

    uVar5 = **(uint32_t**)((uint8_t*)self + 0x100) & 0xfffff;
    local_10 = 0;
    local_38 = 0;
    local_48 = 0;
    local_44 = 1;
    local_40 = 2;
    local_3c = 3;
    if ((**(uint32_t**)((uint8_t*)self + 0x100) & 0xfff00000) != 0x30000000) {
        return 1;
    }
    local_1c = 0;
    local_28 = 0;
    local_24 = 0;
    local_2c = 0;
    local_c = 0;
    if (uVar5 == 0) {
LAB_00696dd6:
        uVar6 = FUN_00694b7c(*(void**)((uint8_t*)self + 0x100), &DAT_006f1d00[0], local_128,
                             &local_38, local_e8, &local_48, uVar5, param_1 == nullptr);
        if (uVar6 != 0) {
            return uVar6;
        }
        bVar2 = false;
        local_1c = 0;
        local_c = 0;
LAB_00696e1b:
        local_8 = 0;
LAB_00696e1f:
        local_30 = 0;
        if (uVar5 != 0) {
            iVar3 = *(int32_t*)((uint8_t*)self + 0x14);
            do {
                local_24 = local_e8[local_c * 4 + local_30];
                local_18 = local_d8[local_30 + local_c * -4];
                local_28 = auStack_b8[local_30 - local_8];
                iVar4 = aiStack_c8[local_8 + local_30];
                local_14 = *(uint32_t*)(iVar3 + local_28 * 4);
                local_20 = *(uint32_t*)(*(int32_t*)((uint8_t*)self + 0x10) +
                                        *(int32_t*)(*(int32_t*)(iVar3 + local_18 * 4) + 4) * 4);
                local_34 = *(int32_t*)(*(int32_t*)((uint8_t*)self + 0x10) +
                                       *(int32_t*)(local_14 + 4) * 4);
                local_2c = *(int32_t*)(*(int32_t*)(iVar3 + local_24 * 4) + 0x38);
                if ((((local_2c == iVar4) ||
                      (iVar1 = *(int32_t*)(*(int32_t*)(iVar3 + iVar4 * 4) + 0x38), iVar1 == local_24)) ||
                     ((local_2c != -1 && (local_2c == iVar1)))) &&
                    (((*(uint32_t*)(*(int32_t*)(iVar3 + local_24 * 4) + 0x3c) ^ 0x80000) ==
                      *(uint32_t*)(*(int32_t*)(iVar3 + iVar4 * 4) + 0x3c)) &&
                     (local_18 == local_28))) {
                    bVar2 = true;
LAB_00696f3d:
                    iVar4 = 0;
                }
                else {
                    if (local_24 != iVar4) {
LAB_00696f3b:
                        bVar2 = false;
                        goto LAB_00696f3d;
                    }
                    iVar4 = *(int32_t*)(iVar3 + local_18 * 4);
                    uVar6 = *(uint32_t*)(iVar4 + 0x38);
                    if (((((uVar6 != local_28) && (*(uint32_t*)(local_14 + 0x38) != local_18)) &&
                          ((uVar6 == 0xffffffff || (uVar6 != *(uint32_t*)(local_14 + 0x38))))) ||
                         ((*(uint32_t*)(iVar4 + 0x3c) ^ 0x80000) != *(uint32_t*)(local_14 + 0x3c))) &&
                        ((((*(uint32_t*)(local_20 + 4) & 0x100) == 0 ||
                           ((*(uint32_t*)(local_34 + 4) & 0x100) == 0)) ||
                          (*(double*)(local_14 + 0x20) != -*(double*)(iVar4 + 0x20))))) {
                        goto LAB_00696f3b;
                    }
                    iVar4 = 1;
                    bVar2 = true;
                }
                if (local_30 == 0) {
                    local_1c = iVar4;
                }
                else if (local_1c != iVar4) {
                    bVar2 = false;
                }
                if (!bVar2) goto LAB_00696f66;
                local_30 = local_30 + 1;
            } while (local_30 < uVar5);
        }
        if (!bVar2) goto LAB_00696f66;
        iVar3 = FUN_0065d0b4(0x74);
        if (iVar3 == 0) {
            local_10 = 0;
        }
        else {
            local_10 = FUN_0065cc1a();
        }
        if (local_10 == 0) {
            return 0x8007000e;
        }
        if (local_1c == 0) {
            if (local_c == 0) goto LAB_006970fb;
LAB_00697129:
            if (local_c == 1) goto LAB_00696fe2;
        }
        else {
            if (local_c == 1) {
LAB_006970fb:
                local_8 = FUN_0065d0ff(uVar5 | 0x70b00000, uVar5 * 2, uVar5, 0);
                if ((int32_t)local_8 < 0) goto LAB_00696f88;
                if (local_1c == 0) goto LAB_00697129;
            }
            if (local_c == 0) {
LAB_00696fe2:
                local_8 = FUN_0065d0ff(uVar5 | 0x70c00000, uVar5 * 2, uVar5, 0);
                if ((int32_t)local_8 < 0) goto LAB_00696f88;
            }
        }
        local_8 = FUN_0065cc50(*(void**)((uint8_t*)self + 0x100));
        if (-1 < (int32_t)local_8) {
            local_14 = uVar5 * 4;
            puVar9 = *(uint32_t**)(*(int32_t*)((uint8_t*)self + 0x100) + 0x10);
            puVar10 = *(uint32_t**)(local_10 + 0x10);
            for (uVar6 = uVar5; uVar6 != 0; uVar6 = uVar6 - 1) {
                *puVar10 = *puVar9;
                puVar9 = puVar9 + 1;
                puVar10 = puVar10 + 1;
            }
            for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
                *(uint8_t*)puVar10 = *(uint8_t*)puVar9;
                puVar9 = (uint32_t*)((uint8_t*)puVar9 + 1);
                puVar10 = (uint32_t*)((uint8_t*)puVar10 + 1);
            }
            local_20 = local_c * 0x10;
            piVar7 = local_e8 + local_c * 4;
            piVar11 = *(int32_t**)(uintptr_t)(local_10 + 8);
            for (uVar6 = uVar5; uVar6 != 0; uVar6 = uVar6 - 1) {
                *piVar11 = *piVar7;
                piVar7 = piVar7 + 1;
                piVar11 = piVar11 + 1;
            }
            for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
                *(char*)piVar11 = (char)*piVar7;
                piVar7 = (int32_t*)((uint8_t*)piVar7 + 1);
                piVar11 = (int32_t*)((uint8_t*)piVar11 + 1);
            }
            puVar8 = local_d8 + local_c * -4;
            puVar12 = (uint32_t*)(*(int32_t*)(local_10 + 8) + uVar5 * 4);
            for (uVar6 = uVar5; uVar6 != 0; uVar6 = uVar6 - 1) {
                *puVar12 = *puVar8;
                puVar8 = puVar8 + 1;
                puVar12 = puVar12 + 1;
            }
            for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
                *(char*)puVar12 = (char)*puVar8;
                puVar8 = (uint32_t*)((uint8_t*)puVar8 + 1);
                puVar12 = (uint32_t*)((uint8_t*)puVar12 + 1);
            }
            iVar3 = *(int32_t*)((uint8_t*)self + 0x14);
            local_20 = *(uint32_t*)(iVar3 + (*(int32_t**)(uintptr_t)(local_10 + 8))[uVar5] * 4);
            iVar4 = *(int32_t*)(iVar3 + **(int32_t**)(uintptr_t)(local_10 + 8) * 4);
            iVar3 = *(int32_t*)(iVar3 + **(int32_t**)(local_10 + 0x10) * 4);
            if (((*(int32_t*)(iVar3 + 4) == *(int32_t*)(iVar4 + 4)) &&
                 (*(int32_t*)(iVar3 + 0xc) == *(int32_t*)(iVar4 + 0xc))) ||
                ((*(int32_t*)(iVar3 + 4) == *(int32_t*)(local_20 + 4) &&
                  (*(int32_t*)(iVar3 + 0xc) == *(int32_t*)(local_20 + 0xc))))) {
                goto LAB_00696f81;
            }
            if (param_1 != nullptr) {
                *param_1 = local_10;
                if (local_38 != 0) {
                    puVar9 = local_128;
                    for (iVar3 = local_38; iVar3 != 0; iVar3 = iVar3 + -1) {
                        *param_2 = *puVar9;
                        puVar9 = puVar9 + 1;
                        param_2 = param_2 + 1;
                    }
                }
                *param_3 = local_38;
                return local_8;
            }
            goto LAB_00696dba;
        }
        goto LAB_00696f88;
    }
    iVar3 = *(int32_t*)(*(int32_t*)((uint8_t*)self + 0x100) + 8);
    local_14 = uVar5 << 2;
    local_20 = uVar5 << 3;
    local_18 = local_14;
    local_8 = local_20;
    do {
        iVar4 = *(int32_t*)(*(int32_t*)((uint8_t*)self + 0x14) +
                           *(int32_t*)(iVar3 + local_18) * 4);
        local_34 = *(int32_t*)(*(int32_t*)((uint8_t*)self + 0x14) +
                              *(int32_t*)(iVar3 + local_8) * 4);
        local_30 = *(uint32_t*)(*(int32_t*)((uint8_t*)self + 0x10) +
                               *(int32_t*)(local_34 + 4) * 4);
        if (((((*(uint8_t*)(*(int32_t*)(*(int32_t*)((uint8_t*)self + 0x10) +
                                        *(int32_t*)(iVar4 + 4) * 4) + 5) & 1) == 0) ||
              (*(double*)(iVar4 + 0x20) != 0.0)) || (*(int32_t*)(iVar4 + 8) != -1)) ||
            (iVar4 = *(int32_t*)(*(int32_t*)((uint8_t*)self + 0x100) + 8),
             *(int32_t*)(iVar4 + local_8) != *(int32_t*)(iVar4 + local_c * 4))) {
            local_24 = 1;
        }
        else {
            local_1c = 1;
        }
        if ((((*(uint8_t*)(local_30 + 5) & 1) == 0) || (*(double*)(local_34 + 0x20) != 0.0)) ||
            ((*(int32_t*)(local_34 + 8) != -1 ||
              (iVar4 = *(int32_t*)(*(int32_t*)((uint8_t*)self + 0x100) + 8),
               *(int32_t*)(iVar4 + local_18) != *(int32_t*)(iVar4 + local_c * 4))))) {
            local_2c = 1;
        }
        else {
            local_28 = 1;
        }
        local_c = local_c + 1;
        local_8 = local_8 + 4;
        local_18 = local_18 + 4;
    } while (local_c < uVar5);
    if ((local_1c == 0) || (local_24 != 0)) {
        if ((local_28 == 0) || (local_2c != 0)) goto LAB_00696dd6;
        if (param_1 != nullptr) {
            return 1;
        }
        iVar3 = FUN_0065d0b4(0x74);
        if (iVar3 == 0) {
            local_10 = 0;
        }
        else {
            local_10 = FUN_0065cc1a();
        }
        if (local_10 == 0) {
            return 0x8007000e;
        }
        uVar6 = uVar5 | 0x70c00000;
    }
    else {
        iVar3 = FUN_0065d0b4(0x74);
        if (iVar3 == 0) {
            local_10 = 0;
        }
        else {
            local_10 = FUN_0065cc1a();
        }
        if (local_10 == 0) {
            return 0x8007000e;
        }
        uVar6 = uVar5 | 0x70b00000;
    }
    local_8 = FUN_0065d0ff(uVar6, uVar5 * 2, uVar5, 0);
    if ((-1 < (int32_t)local_8) &&
        (local_8 = FUN_0065cc50(*(void**)((uint8_t*)self + 0x100)), -1 < (int32_t)local_8)) {
        puVar9 = *(uint32_t**)(*(int32_t*)((uint8_t*)self + 0x100) + 0x10);
        puVar10 = *(uint32_t**)(local_10 + 0x10);
        for (uVar5 = local_14 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
        }
        for (uVar5 = local_14 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(uint8_t*)puVar10 = *(uint8_t*)puVar9;
            puVar9 = (uint32_t*)((uint8_t*)puVar9 + 1);
            puVar10 = (uint32_t*)((uint8_t*)puVar10 + 1);
        }
        puVar9 = *(uint32_t**)(*(int32_t*)((uint8_t*)self + 0x100) + 8);
        puVar10 = *(uint32_t**)(local_10 + 8);
        for (uVar5 = local_14 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
        }
        for (uVar5 = local_14 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(uint8_t*)puVar10 = *(uint8_t*)puVar9;
            puVar9 = (uint32_t*)((uint8_t*)puVar9 + 1);
            puVar10 = (uint32_t*)((uint8_t*)puVar10 + 1);
        }
        uVar5 = local_14;
        if (local_1c == 0) {
            uVar5 = local_20;
        }
        puVar9 = (uint32_t*)(*(int32_t*)(*(int32_t*)((uint8_t*)self + 0x100) + 8) + uVar5);
        puVar10 = (uint32_t*)(*(int32_t*)(local_10 + 8) + local_14);
        for (uVar6 = local_14 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
        }
        for (uVar5 = local_14 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(uint8_t*)puVar10 = *(uint8_t*)puVar9;
            puVar9 = (uint32_t*)((uint8_t*)puVar9 + 1);
            puVar10 = (uint32_t*)((uint8_t*)puVar10 + 1);
        }
LAB_00696dba:
        local_8 = FUN_0065d35e(local_10);
    }
LAB_00696f88:
    if (local_10 != 0) {
        FUN_00614343(1);
    }
    return local_8;
LAB_00696f66:
    local_8 = local_8 + 4;
    if (7 < local_8) goto code_r0x00696f74;
    goto LAB_00696e1f;
code_r0x00696f74:
    local_c = local_c + 1;
    if (1 < local_c) goto LAB_00696f81;
    goto LAB_00696e1b;
LAB_00696f81:
    local_8 = 1;
    goto LAB_00696f88;
}

// 0x697138 — observed shape
int32_t FUN_697138(void* self, int32_t* param_1, uint32_t* param_2, int32_t* param_3)
{
    int32_t  iVar1;
    int32_t  iVar2;
    int32_t  iVar3;
    int32_t  iVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    int32_t* piVar8;
    uint32_t* puVar9;
    int32_t* piVar10;
    uint32_t* puVar11;

    uint32_t local_138[16];
    int32_t  local_f8[4];
    int32_t  local_e8[4];
    int32_t  local_d8[4];
    int32_t  local_c8[4];
    int32_t  local_b8[24];
    uint32_t local_58;
    uint32_t local_54;
    uint32_t local_50;
    uint32_t local_4c;
    int32_t  local_48;
    int32_t  local_44;
    int32_t* local_40;
    int32_t* local_3c;
    int32_t* local_38;
    int32_t* local_34;
    int32_t* local_30;
    int32_t  local_2c;
    int32_t* local_28;
    int32_t  local_24;
    int32_t* local_20;
    int32_t* local_1c;
    uint32_t local_18;
    int32_t  local_14;
    uint32_t local_10;
    uint32_t local_c;
    int32_t  local_8;

    uVar7 = **(uint32_t**)((uint8_t*)self + 0x100) & 0xfffff;
    local_2c = 0;
    local_58 = 0;
    local_8 = 0;
    local_24 = 0;
    local_54 = 1;
    local_50 = 2;
    local_4c = 3;
    local_14 = (int32_t)(intptr_t)self;
    iVar4 = FUN_00694b7c(*(void**)((uint8_t*)self + 0x100), &DAT_006f1d60[0], local_138,
                         &local_2c, local_f8, &local_58, uVar7, param_1 == nullptr);
    if (iVar4 != 0) {
        local_24 = 1;
        iVar4 = FUN_00694b7c(*(void**)((uint8_t*)self + 0x100), &DAT_006f1de0[0], local_138,
                             &local_2c, local_f8, &local_58, uVar7, param_1 == nullptr);
        if (iVar4 != 0) {
            return iVar4;
        }
    }
    local_c = 0;
    local_3c = local_e8;
    local_40 = local_d8;
LAB_006971fe:
    local_18 = 0;
    local_38 = local_c8;
    local_28 = local_b8;
LAB_00697214:
    local_10 = 0;
    if (uVar7 != 0) {
        iVar4 = *(int32_t*)((uint8_t*)self + 0x14);
        local_34 = local_40;
        local_20 = local_28;
        local_1c = local_38;
        local_30 = local_3c;
        do {
            local_48 = *(int32_t*)(iVar4 + local_f8[local_10] * 4);
            iVar1 = *(int32_t*)(iVar4 + *local_30 * 4);
            local_44 = *(int32_t*)(iVar4 + *local_1c * 4);
            if (((((*(int32_t*)(iVar1 + 8) != -1) || (*(int32_t*)(local_48 + 8) != -1)) ||
                  (*(int32_t*)(local_44 + 8) != -1)) ||
                 ((iVar2 = *(int32_t*)((uint8_t*)self + 0x10),
                  (*(uint8_t*)(*(int32_t*)(iVar2 + *(int32_t*)(iVar1 + 4) * 4) + 5) & 1) == 0 ||
                  ((*(uint8_t*)(*(int32_t*)(iVar2 + *(int32_t*)(local_44 + 4) * 4) + 5) & 1) == 0)))) ||
                (((*(uint8_t*)(*(int32_t*)(iVar2 + *(int32_t*)(local_48 + 4) * 4) + 5) & 1) == 0 ||
                  ((9.999999747378752e-06 <
                    std::fabs((*(double*)(local_44 + 0x20) - *(double*)(iVar1 + 0x20)) -
                              *(double*)(local_48 + 0x20)) ||
                    (*local_34 != *local_20)))))) {
                break;
            }
            local_10 = local_10 + 1;
            local_30 = local_30 + 1;
            local_1c = local_1c + 1;
            local_20 = local_20 + 1;
            local_34 = local_34 + 1;
        } while (local_10 < uVar7);
    }
    if (local_10 != uVar7) goto code_r0x006972e7;
    iVar4 = FUN_0065d0b4(0x74);
    if (iVar4 == 0) {
        local_8 = 0;
    }
    else {
        local_8 = FUN_0065cc1a();
    }
    if (local_8 == 0) {
        return -0x7ff8fff2;
    }
    if (local_24 == 0) {
        uVar5 = uVar7 | 0x70b00000;
    }
    else {
        if (param_1 != nullptr) goto LAB_00697310;
        uVar5 = uVar7 | 0x70c00000;
    }
    iVar4 = FUN_0065d0ff(uVar5, uVar7 * 2, uVar7, 0);
    if ((-1 < iVar4) &&
        (iVar4 = FUN_0065cc50(*(void**)((uint8_t*)self + 0x100)), iVar1 = local_8, -1 < iVar4)) {
        uVar5 = uVar7 * 4;
        local_c = uVar5;
        puVar11 = *(uint32_t**)(*(int32_t*)((uint8_t*)self + 0x100) + 0x10);
        puVar9 = *(uint32_t**)(local_8 + 0x10);
        for (uVar6 = uVar7; uVar6 != 0; uVar6 = uVar6 - 1) {
            *puVar9 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar9 = puVar9 + 1;
        }
        for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
            *(uint8_t*)puVar9 = *(uint8_t*)puVar11;
            puVar11 = (uint32_t*)((uint8_t*)puVar11 + 1);
            puVar9 = (uint32_t*)((uint8_t*)puVar9 + 1);
        }
        piVar8 = local_f8;
        piVar10 = *(int32_t**)(uintptr_t)(local_8 + 8);
        for (uVar6 = uVar7; uVar6 != 0; uVar6 = uVar6 - 1) {
            *piVar10 = *piVar8;
            piVar8 = piVar8 + 1;
            piVar10 = piVar10 + 1;
        }
        for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
            *(char*)piVar10 = (char)*piVar8;
            piVar8 = (int32_t*)((uint8_t*)piVar8 + 1);
            piVar10 = (int32_t*)((uint8_t*)piVar10 + 1);
        }
        puVar11 = (uint32_t*)(*(int32_t*)(local_8 + 8) + uVar5);
        if (local_24 == 0) {
            uVar5 = uVar7 * 8;
        }
        puVar9 = (uint32_t*)(*(int32_t*)(*(int32_t*)((uint8_t*)self + 0x100) + 8) + uVar5);
        for (uVar6 = uVar7; uVar6 != 0; uVar6 = uVar6 - 1) {
            *puVar11 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar11 = puVar11 + 1;
        }
        for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
            *(uint8_t*)puVar11 = *(uint8_t*)puVar9;
            puVar9 = (uint32_t*)((uint8_t*)puVar9 + 1);
            puVar11 = (uint32_t*)((uint8_t*)puVar11 + 1);
        }
        iVar4 = *(int32_t*)((uint8_t*)self + 0x14);
        iVar2 = *(int32_t*)(iVar4 + (*(int32_t**)(uintptr_t)(local_8 + 8))[uVar7] * 4);
        iVar3 = *(int32_t*)(iVar4 + **(int32_t**)(uintptr_t)(local_8 + 8) * 4);
        iVar4 = *(int32_t*)(iVar4 + **(int32_t**)(uintptr_t)(local_8 + 0x10) * 4);
        if (((*(int32_t*)(iVar4 + 4) != *(int32_t*)(iVar3 + 4)) ||
             (*(int32_t*)(iVar4 + 0xc) != *(int32_t*)(iVar3 + 0xc))) &&
            ((*(int32_t*)(iVar4 + 4) != *(int32_t*)(iVar2 + 4) ||
              (*(int32_t*)(iVar4 + 0xc) != *(int32_t*)(iVar2 + 0xc))))) {
            if (param_1 == nullptr) {
                FUN_0065d35e(local_8);
            }
            else {
                local_8 = 0;
                *param_1 = iVar1;
                if (local_2c != 0) {
                    puVar11 = local_138;
                    for (iVar4 = local_2c; iVar4 != 0; iVar4 = iVar4 + -1) {
                        *param_2 = *puVar11;
                        puVar11 = puVar11 + 1;
                        param_2 = param_2 + 1;
                    }
                }
                *param_3 = local_2c;
            }
            iVar4 = 0;
            goto LAB_00697313;
        }
        goto LAB_00697310;
    }
    goto LAB_00697313;
code_r0x006972e7:
    local_18 = local_18 + 1;
    local_28 = local_28 + -4;
    local_38 = local_38 + 4;
    if (1 < local_18) goto code_r0x006972fd;
    goto LAB_00697214;
code_r0x006972fd:
    local_c = local_c + 1;
    local_40 = local_40 + -4;
    local_3c = local_3c + 4;
    if (1 < local_c) {
LAB_00697310:
        iVar4 = 1;
LAB_00697313:
        if (local_8 != 0) {
            FUN_00614343(1);
        }
        return iVar4;
    }
    goto LAB_006971fe;
}

// 0x697497 — observed shape
// Five near-identical passes over the node array at self+0x14, the group array
// at self+0x18 and the instruction record at self+0x100. Each pass probes the
// record through FUN_006949cb/FUN_00694b7c against a table pair, either folds
// the produced node set into self+0x100 (0x10000000 opcode) or merges the
// folded set into self+0xfc, and on failure rebuilds self+0x100 unchanged.
int32_t FUN_697497(void* self)
{
    const uintptr_t selfBase = (uintptr_t)self;

    uint8_t   bVar4;
    bool      bVar20;
    uint32_t  uVar2;
    int32_t   iVar3;
    int32_t   iVar6;
    int32_t   iVar7;
    int32_t   iVar8;
    uint32_t* puVar5;
    uint32_t* puVar9;
    uint32_t  uVar10;
    uint32_t  uVar17;
    uint32_t  uVar18;
    int32_t*  piVar11;
    uint32_t* puVar12;
    uint32_t* puVar13;
    uint32_t* puVar14;
    uint32_t** ppuVar15;
    uint32_t* puVar16;
    uint32_t* puVar19;

    int32_t   local_2d0[40];
    uint32_t  local_230[40];
    uint32_t  auStack_190[40];
    uint32_t* local_f0[16];
    uint32_t  local_b0[16];
    uint32_t  local_70[4];
    int32_t   local_60[4];
    uint32_t* local_50;
    int32_t   local_4c;
    uint32_t  local_48;
    uint32_t* local_44;
    uint32_t  local_40;
    uint32_t* local_3c;
    uint32_t* local_38;
    uint32_t* local_34;
    uint32_t* local_30;
    uint32_t* local_2c;
    uint32_t* local_28;
    uint32_t* local_24;
    uint32_t* local_20;
    uint32_t* local_1c;
    int32_t   local_14;
    uint32_t  local_10;
    uint32_t* local_c;
    uint32_t* local_8;

    puVar14 = *(uint32_t**)(selfBase + 0x100);
    local_c = (uint32_t*)(*puVar14 & 0xfffff);
    local_30 = (uint32_t*)(*puVar14 & 0xfffff);
    local_1c = (uint32_t*)0;
    local_48 = 0;
    local_44 = (uint32_t*)0;
    local_60[0] = 0;
    local_60[1] = 1;
    local_60[2] = 2;
    local_60[3] = 3;
    local_4c = 0;
    if ((local_c <= (uint32_t*)(*puVar14 & 0xfffff)) && ((*puVar14 & 0xfff00000) == 0x20000000)) {
        local_2c = (uint32_t*)0;
LAB_00697504:
        local_10 = 0;
        do {
            puVar12 = local_230;
            for (iVar8 = 0x28; iVar8 != 0; iVar8 = iVar8 + -1) {
                *puVar12 = 0xffffffff;
                puVar12 = puVar12 + 1;
            }
            piVar11 = local_2d0;
            for (iVar8 = 0x28; iVar8 != 0; iVar8 = iVar8 + -1) {
                *piVar11 = -1;
                piVar11 = piVar11 + 1;
            }
            local_20 = (uint32_t*)0;
            local_14 = 0;
            local_40 = 0;
            local_28 = (uint32_t*)0;
            do {
                if (local_10 == 0) {
                    uVar17 = local_40;
                }
                else {
                    uVar17 = 1 - local_40;
                }
                uVar10 = puVar14[2];
                uVar17 = *(uint32_t*)(&DAT_006f1cac[0] + uVar17 * 4);
                piVar11 = (int32_t*)(uintptr_t)(uVar10 + (int32_t)(intptr_t)local_28 * 4);
                if (uVar17 < 0x10) {
                    iVar8 = *(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                                    *piVar11 * 4) + 0x48);
                    if (iVar8 != -1) {
                        uVar2 = *(uint32_t*)(*(int32_t*)(selfBase + 0x18) + iVar8 * 4);
                        iVar8 = FUN_006949cb((void*)(uintptr_t)uVar2, piVar11,
                                             (uint32_t)(uintptr_t)local_c, local_60, local_70,
                                             &DAT_006f1cb8[0] + uVar17 * 0x20, 0);
                        if (iVar8 == 0) {
                            local_14 = FUN_00694b7c((void*)(uintptr_t)uVar2,
                                                    &DAT_006f1ca0[0] + uVar17 * 0x20,
                                                    local_b0, &local_20, local_2d0, local_70,
                                                    (uint32_t)(uintptr_t)local_30, 0);
                            goto LAB_00697607;
                        }
                    }
                    local_14 = 1;
                    break;
                }
                uVar18 = 0;
                puVar12 = local_230 + (uVar17 - 0x10) * 4;
                do {
                    if ((uint32_t*)local_60[uVar18] < local_c) {
                        *puVar12 = *(uint32_t*)(uintptr_t)
                                   (uVar10 + (local_60[uVar18] + (int32_t)(intptr_t)local_28) * 4);
                    }
                    else {
                        *puVar12 = 0xffffffff;
                    }
                    uVar18 = uVar18 + 1;
                    puVar12 = puVar12 + 1;
                } while (uVar18 < 4);
LAB_00697607:
                if (local_14 == 1) break;
                local_40 = local_40 + 1;
                local_28 = (uint32_t*)((int32_t)(intptr_t)local_28 + (int32_t)(intptr_t)local_c);
            } while (local_40 < 2);
            puVar12 = local_20;
            local_40 = 0;
            local_38 = (uint32_t*)0;
            do {
                if (local_10 == 0) {
                    uVar17 = local_40;
                }
                else {
                    uVar17 = 1 - local_40;
                }
                if ((0xf < *(uint32_t*)(&DAT_006f1cac[0] + uVar17 * 4)) &&
                    (local_28 = (uint32_t*)0, local_20 != (uint32_t*)0)) {
                    do {
                        puVar13 = (uint32_t*)0;
                        if (local_c != (uint32_t*)0) {
                            uVar17 = local_b0[(int32_t)(intptr_t)local_28];
                            puVar5 = *(uint32_t**)(uintptr_t)(uVar17 + 0xc);
                            do {
                                local_8 = (uint32_t*)0;
                                if (puVar5 != (uint32_t*)0) {
                                    piVar11 = *(int32_t**)(uintptr_t)(uVar17 + 0x10);
                                    do {
                                        if (*(int32_t*)(uintptr_t)
                                            (puVar14[2] + ((int32_t)(intptr_t)local_38 +
                                                           (int32_t)(intptr_t)puVar13) * 4) ==
                                            *piVar11) {
                                            local_14 = 1;
                                            goto LAB_006976a2;
                                        }
                                        local_8 = (uint32_t*)((int32_t)(intptr_t)local_8 + 1);
                                        puVar5 = *(uint32_t**)(uintptr_t)(uVar17 + 0xc);
                                        piVar11 = piVar11 + 1;
                                    } while (local_8 < puVar5);
                                }
                                puVar13 = (uint32_t*)((int32_t)(intptr_t)puVar13 + 1);
                            } while (puVar13 < local_c);
                        }
LAB_006976a2:
                        local_28 = (uint32_t*)((int32_t)(intptr_t)local_28 + 1);
                    } while (local_28 < local_20);
                }
                local_40 = local_40 + 1;
                local_38 = (uint32_t*)((int32_t)(intptr_t)local_38 + (int32_t)(intptr_t)local_c);
            } while (local_40 < 2);
            if (local_14 == 0) {
                if (local_2c != (uint32_t*)0) goto LAB_00697855;
                local_28 = (uint32_t*)0;
                if (local_20 != (uint32_t*)0) {
                    do {
                        local_3c = *(uint32_t**)(local_b0[(int32_t)(intptr_t)local_28] + 0xc);
                        local_38 = (uint32_t*)0;
                        if (local_3c != (uint32_t*)0) {
                            do {
                                if (*(uint32_t*)(selfBase + 0xc) != 0) {
                                    local_8 = *(uint32_t**)(selfBase + 0x18);
                                    local_34 = *(uint32_t**)(selfBase + 0xc);
                                    do {
                                        puVar13 = (uint32_t*)*local_8;
                                        if ((puVar13 != (uint32_t*)0) && (*puVar13 != 0)) {
                                            local_40 = 0;
                                            if ((uint32_t*)puVar13[1] != (uint32_t*)0) {
                                                iVar8 = *(int32_t*)(
                                                    *(int32_t*)(local_b0[(int32_t)(intptr_t)local_28] + 0x10) +
                                                    (int32_t)(intptr_t)local_38 * 4);
                                                piVar11 = (int32_t*)puVar13[2];
                                                local_24 = (uint32_t*)puVar13[1];
                                                do {
                                                    if ((*piVar11 == iVar8) ||
                                                        (*(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) + *piVar11 * 4) + 0x38) == iVar8)) {
                                                        local_40 = 1;
                                                    }
                                                    piVar11 = piVar11 + 1;
                                                    local_24 = (uint32_t*)((int32_t)(intptr_t)local_24 - 1);
                                                } while (local_24 != (uint32_t*)0);
                                            }
                                            if (puVar13 == puVar14) {
                                                local_40 = 0;
                                            }
                                            if (local_40 != 0) {
                                                puVar5 = (uint32_t*)0;
                                                do {
                                                    if (puVar13 == (uint32_t*)local_b0[(int32_t)(intptr_t)puVar5]) {
                                                        local_40 = 0;
                                                    }
                                                    puVar5 = (uint32_t*)((int32_t)(intptr_t)puVar5 + 1);
                                                } while (puVar5 < local_20);
                                                if (local_40 != 0) {
                                                    local_14 = 1;
                                                }
                                            }
                                        }
                                        local_8 = local_8 + 1;
                                        local_34 = (uint32_t*)((int32_t)(intptr_t)local_34 - 1);
                                    } while (local_34 != (uint32_t*)0);
                                }
                                local_38 = (uint32_t*)((int32_t)(intptr_t)local_38 + 1);
                            } while (local_38 < local_3c);
                        }
                        local_28 = (uint32_t*)((int32_t)(intptr_t)local_28 + 1);
                    } while (local_28 < local_20);
                }
                local_38 = (uint32_t*)0;
                do {
                    uVar17 = local_230[(int32_t)(intptr_t)local_38];
                    if ((uVar17 != 0xffffffff) &&
                        (puVar13 = (uint32_t*)0, local_20 != (uint32_t*)0)) {
                        local_3c = *(uint32_t**)(*(int32_t*)(selfBase + 0x14) + uVar17 * 4);
                        do {
                            puVar5 = *(uint32_t**)(local_b0[(int32_t)(intptr_t)puVar13] + 0xc);
                            if (puVar5 != (uint32_t*)0) {
                                puVar9 = *(uint32_t**)(local_b0[(int32_t)(intptr_t)puVar13] + 0x10);
                                local_34 = puVar5;
                                do {
                                    if ((uVar17 == *puVar9) || (local_3c[0xe] == *puVar9)) {
                                        local_14 = 1;
                                    }
                                    puVar9 = puVar9 + 1;
                                    local_34 = (uint32_t*)((int32_t)(intptr_t)local_34 - 1);
                                } while (local_34 != (uint32_t*)0);
                            }
                            puVar13 = (uint32_t*)((int32_t)(intptr_t)puVar13 + 1);
                        } while (puVar13 < local_20);
                    }
                    local_38 = (uint32_t*)((int32_t)(intptr_t)local_38 + 1);
                } while (local_38 < (uint32_t*)0x28);
                if (local_14 == 0) goto LAB_00697855;
            }
            local_10 = local_10 + 1;
        } while (local_10 < 2);
        if (local_14 != 0) goto code_r0x00697846;
LAB_00697855:
        puVar13 = local_b0;
        ppuVar15 = local_f0;
        for (uVar17 = (uint32_t)(uintptr_t)local_20 & 0x3fffffff; uVar17 != 0;
             uVar17 = uVar17 - 1) {
            *ppuVar15 = (uint32_t*)*puVar13;
            puVar13 = puVar13 + 1;
            ppuVar15 = ppuVar15 + 1;
        }
        for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
            *(char*)ppuVar15 = (char)*puVar13;
            puVar13 = (uint32_t*)((uint8_t*)puVar13 + 1);
            ppuVar15 = (uint32_t**)((uint8_t*)ppuVar15 + 1);
        }
        local_f0[(int32_t)(intptr_t)puVar12] = puVar14;
        local_44 = (uint32_t*)((int32_t)(intptr_t)local_20 + 1);
        uVar17 = 0;
        do {
            iVar8 = *(int32_t*)((uint8_t*)local_230 + uVar17);
            if ((iVar8 != -1) ||
                (iVar8 = *(int32_t*)((uint8_t*)local_2d0 + uVar17), iVar8 != -1)) {
                *(int32_t*)((uint8_t*)auStack_190 + uVar17) = iVar8;
            }
            uVar17 = uVar17 + 4;
        } while (uVar17 < 0xa0);
        local_14 = 0;
LAB_006978b4:
        iVar8 = local_14;
        if (local_14 == 1) goto LAB_006978c0;
        goto LAB_00697cb1;
    }
LAB_006978c0:
    local_8 = *(uint32_t**)(selfBase + 0x100);
    uVar17 = **(uint32_t**)(selfBase + 0x100);
    local_20 = (uint32_t*)(uVar17 & 0xfffff);
    if ((local_20 <= local_30) && ((uVar17 & 0xfff00000) == 0x20100000)) {
        local_38 = (uint32_t*)0;
        local_40 = (uint32_t)((int32_t)(intptr_t)local_44 << 2);
LAB_006978ff:
        local_28 = (uint32_t*)0;
        do {
            uVar17 = local_40;
            ppuVar15 = local_f0;
            puVar14 = local_b0;
            for (uVar10 = local_40 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
                *puVar14 = (uint32_t)*ppuVar15;
                ppuVar15 = ppuVar15 + 1;
                puVar14 = puVar14 + 1;
            }
            for (uVar17 = uVar17 & 3; uVar17 != 0; uVar17 = uVar17 - 1) {
                *(uint8_t*)puVar14 = *(uint8_t*)ppuVar15;
                ppuVar15 = (uint32_t**)((uint8_t*)ppuVar15 + 1);
                puVar14 = (uint32_t*)((uint8_t*)puVar14 + 1);
            }
            puVar14 = local_230;
            for (iVar8 = 0x28; iVar8 != 0; iVar8 = iVar8 + -1) {
                *puVar14 = 0xffffffff;
                puVar14 = puVar14 + 1;
            }
            piVar11 = local_2d0;
            for (iVar8 = 0x28; iVar8 != 0; iVar8 = iVar8 + -1) {
                *piVar11 = -1;
                piVar11 = piVar11 + 1;
            }
            iVar8 = 0;
            local_c = local_44;
            local_14 = 0;
            local_10 = 0;
            do {
                if (local_28 == (uint32_t*)0) {
                    uVar17 = local_10;
                }
                else {
                    uVar17 = 1 - local_10;
                }
                uVar10 = local_8[2];
                uVar17 = *(uint32_t*)(&DAT_006f1c4c[0] + uVar17 * 4);
                piVar11 = (int32_t*)(uintptr_t)(uVar10 + iVar8 * 4);
                if (uVar17 < 0x10) {
                    iVar7 = *(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                                    *piVar11 * 4) + 0x48);
                    if (iVar7 != -1) {
                        uVar2 = *(uint32_t*)(*(int32_t*)(selfBase + 0x18) + iVar7 * 4);
                        iVar7 = FUN_006949cb((void*)(uintptr_t)uVar2, piVar11,
                                             (uint32_t)(uintptr_t)local_20, local_60, local_70,
                                             &DAT_006f1c58[0] + uVar17 * 0x20, 0);
                        if (iVar7 == 0) {
                            local_14 = FUN_00694b7c((void*)(uintptr_t)uVar2,
                                                    &DAT_006f1c40[0] + uVar17 * 0x20,
                                                    local_b0, &local_c, local_2d0, local_70,
                                                    (uint32_t)(uintptr_t)local_30, 0);
                            goto LAB_00697a10;
                        }
                    }
                    local_14 = 1;
                    break;
                }
                uVar18 = 0;
                puVar14 = local_230 + (uVar17 - 0x10) * 4;
                do {
                    if ((uint32_t*)local_60[uVar18] < local_20) {
                        *puVar14 = *(uint32_t*)(uintptr_t)
                                   (uVar10 + (iVar8 + local_60[uVar18]) * 4);
                    }
                    else {
                        *puVar14 = 0xffffffff;
                    }
                    uVar18 = uVar18 + 1;
                    puVar14 = puVar14 + 1;
                } while (uVar18 < 4);
LAB_00697a10:
                if (local_14 == 1) break;
                local_10 = local_10 + 1;
                iVar8 = iVar8 + (int32_t)(intptr_t)local_20;
            } while (local_10 < 2);
            local_10 = 0;
            local_1c = (uint32_t*)0;
            do {
                if (local_28 == (uint32_t*)0) {
                    uVar17 = local_10;
                }
                else {
                    uVar17 = 1 - local_10;
                }
                if ((0xf < *(uint32_t*)(&DAT_006f1c4c[0] + uVar17 * 4)) &&
                    (local_2c = (uint32_t*)0, local_c != (uint32_t*)0)) {
                    do {
                        puVar14 = (uint32_t*)0;
                        if (local_20 != (uint32_t*)0) {
                            puVar12 = *(uint32_t**)(local_b0[(int32_t)(intptr_t)local_2c] + 0xc);
                            do {
                                local_24 = (uint32_t*)0;
                                if (puVar12 != (uint32_t*)0) {
                                    piVar11 = *(int32_t**)(uintptr_t)(local_b0[(int32_t)(intptr_t)local_2c] + 0x10);
                                    do {
                                        if (*(int32_t*)(uintptr_t)
                                            (local_8[2] + ((int32_t)(intptr_t)local_1c +
                                                           (int32_t)(intptr_t)puVar14) * 4) ==
                                            *piVar11) {
                                            local_14 = 1;
                                            goto LAB_00697aa7;
                                        }
                                        local_24 = (uint32_t*)((int32_t)(intptr_t)local_24 + 1);
                                        piVar11 = piVar11 + 1;
                                    } while (local_24 < puVar12);
                                }
                                puVar14 = (uint32_t*)((int32_t)(intptr_t)puVar14 + 1);
                            } while (puVar14 < local_20);
                        }
LAB_00697aa7:
                        local_2c = (uint32_t*)((int32_t)(intptr_t)local_2c + 1);
                    } while (local_2c < local_c);
                }
                local_10 = local_10 + 1;
                local_1c = (uint32_t*)((int32_t)(intptr_t)local_1c + (int32_t)(intptr_t)local_20);
            } while (local_10 < 2);
            if (local_14 == 0) {
                if (local_38 != (uint32_t*)0) goto LAB_00697c46;
                local_1c = (uint32_t*)0;
                if (local_c != (uint32_t*)0) {
                    do {
                        local_3c = *(uint32_t**)(local_b0[(int32_t)(intptr_t)local_1c] + 0xc);
                        local_2c = (uint32_t*)0;
                        if (local_3c != (uint32_t*)0) {
                            do {
                                if (*(uint32_t*)(selfBase + 0xc) != 0) {
                                    local_24 = *(uint32_t**)(selfBase + 0x18);
                                    local_10 = *(uint32_t*)(selfBase + 0xc);
                                    do {
                                        puVar14 = (uint32_t*)*local_24;
                                        if ((puVar14 != (uint32_t*)0) && (*puVar14 != 0)) {
                                            uVar17 = puVar14[1];
                                            local_34 = (uint32_t*)0;
                                            if (uVar17 != 0) {
                                                iVar8 = *(int32_t*)(
                                                    *(int32_t*)(local_b0[(int32_t)(intptr_t)local_1c] + 0x10) +
                                                    (int32_t)(intptr_t)local_2c * 4);
                                                piVar11 = (int32_t*)puVar14[2];
                                                do {
                                                    if ((*piVar11 == iVar8) ||
                                                        (*(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) + *piVar11 * 4) + 0x38) == iVar8)) {
                                                        local_34 = (uint32_t*)1;
                                                    }
                                                    piVar11 = piVar11 + 1;
                                                    uVar17 = uVar17 - 1;
                                                } while (uVar17 != 0);
                                            }
                                            if (puVar14 == local_8) {
                                                puVar12 = (uint32_t*)0;
                                            }
                                            else {
                                                puVar12 = local_34;
                                            }
                                            if (puVar12 != (uint32_t*)0) {
                                                puVar13 = (uint32_t*)0;
                                                do {
                                                    if (puVar14 == (uint32_t*)local_b0[(int32_t)(intptr_t)puVar13]) {
                                                        puVar12 = (uint32_t*)0;
                                                    }
                                                    puVar13 = (uint32_t*)((int32_t)(intptr_t)puVar13 + 1);
                                                } while (puVar13 < local_c);
                                                if (puVar12 != (uint32_t*)0) {
                                                    local_14 = 1;
                                                }
                                            }
                                        }
                                        local_24 = local_24 + 1;
                                        local_10 = local_10 - 1;
                                    } while (local_10 != 0);
                                }
                                local_2c = (uint32_t*)((int32_t)(intptr_t)local_2c + 1);
                            } while (local_2c < local_3c);
                        }
                        local_1c = (uint32_t*)((int32_t)(intptr_t)local_1c + 1);
                    } while (local_1c < local_c);
                }
                local_2c = (uint32_t*)0;
                do {
                    uVar17 = local_230[(int32_t)(intptr_t)local_2c];
                    if ((uVar17 != 0xffffffff) &&
                        (puVar14 = (uint32_t*)0, local_c != (uint32_t*)0)) {
                        do {
                            iVar8 = *(int32_t*)(local_b0[(int32_t)(intptr_t)puVar14] + 0xc);
                            if (iVar8 != 0) {
                                puVar12 = *(uint32_t**)(local_b0[(int32_t)(intptr_t)puVar14] + 0x10);
                                do {
                                    if ((uVar17 == *puVar12) ||
                                        (*(uint32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) + uVar17 * 4) + 0x38) == *puVar12)) {
                                        local_14 = 1;
                                    }
                                    puVar12 = puVar12 + 1;
                                    iVar8 = iVar8 + -1;
                                } while (iVar8 != 0);
                            }
                            puVar14 = (uint32_t*)((int32_t)(intptr_t)puVar14 + 1);
                        } while (puVar14 < local_c);
                    }
                    local_2c = (uint32_t*)((int32_t)(intptr_t)local_2c + 1);
                } while (local_2c < (uint32_t*)0x28);
                if (local_14 == 0) goto LAB_00697c46;
            }
            local_28 = (uint32_t*)((int32_t)(intptr_t)local_28 + 1);
        } while (local_28 < (uint32_t*)0x2);
        if (local_14 != 0) goto code_r0x00697c37;
LAB_00697c46:
        puVar14 = local_b0;
        ppuVar15 = local_f0;
        for (uVar17 = (uint32_t)(uintptr_t)local_c & 0x3fffffff; uVar17 != 0;
             uVar17 = uVar17 - 1) {
            *ppuVar15 = (uint32_t*)*puVar14;
            puVar14 = puVar14 + 1;
            ppuVar15 = ppuVar15 + 1;
        }
        for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
            *(char*)ppuVar15 = (char)*puVar14;
            puVar14 = (uint32_t*)((uint8_t*)puVar14 + 1);
            ppuVar15 = (uint32_t**)((uint8_t*)ppuVar15 + 1);
        }
        local_f0[(int32_t)(intptr_t)local_c] = local_8;
        local_44 = (uint32_t*)((int32_t)(intptr_t)local_c + 1);
        uVar17 = 0;
        do {
            iVar8 = *(int32_t*)((uint8_t*)local_230 + uVar17);
            if ((iVar8 != -1) ||
                (iVar8 = *(int32_t*)((uint8_t*)local_2d0 + uVar17), iVar8 != -1)) {
                *(int32_t*)((uint8_t*)auStack_190 + uVar17) = iVar8;
            }
            uVar17 = uVar17 + 4;
        } while (uVar17 < 0xa0);
        local_14 = 0;
LAB_00697ca7:
        iVar8 = local_14;
        goto LAB_00697caa;
    }
    iVar8 = 1;
LAB_00697caa:
    local_1c = (uint32_t*)1;
LAB_00697cb1:
    if (iVar8 == 0) {
        local_8 = (uint32_t*)0;
        local_c = (uint32_t*)0;
        puVar14 = auStack_190;
        do {
            puVar14 = puVar14 + 4;
            local_24 = (uint32_t*)0;
            if (local_30 == (uint32_t*)0) {
LAB_00697d2c:
                local_8 = auStack_190 - (int32_t)(intptr_t)local_c * 4 + 8;
                break;
            }
            local_34 = local_30;
            puVar12 = puVar14;
            do {
                iVar8 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) + *puVar12 * 4);
                if ((((*(uint8_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x10) +
                                               *(int32_t*)(iVar8 + 4) * 4) + 5) & 1) == 0) ||
                     (*(int32_t*)(iVar8 + 8) != -1)) ||
                    (*(double*)(iVar8 + 0x20) != (double)(int32_t)(intptr_t)local_1c)) {
                    local_24 = (uint32_t*)1;
                }
                puVar12 = puVar12 + 1;
                local_34 = (uint32_t*)((int32_t)(intptr_t)local_34 - 1);
            } while (local_34 != (uint32_t*)0);
            if (local_24 == (uint32_t*)0) goto LAB_00697d2c;
            local_c = (uint32_t*)((int32_t)(intptr_t)local_c + 1);
        } while (local_c < (uint32_t*)0x2);
        puVar14 = (uint32_t*)0;
        local_34 = (uint32_t*)0;
        if (local_30 != (uint32_t*)0) {
            do {
                iVar8 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) + auStack_190[(int32_t)(intptr_t)puVar14] * 4);
                if ((((*(uint8_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x10) +
                                               *(int32_t*)(iVar8 + 4) * 4) + 5) & 1) != 0) &&
                     (*(int32_t*)(iVar8 + 8) == -1)) &&
                    (*(double*)(iVar8 + 0x20) == (double)(int32_t)(intptr_t)local_1c)) {
                    local_34 = (uint32_t*)1;
                }
                puVar14 = (uint32_t*)((int32_t)(intptr_t)puVar14 + 1);
            } while (puVar14 < local_30);
            if (local_34 != (uint32_t*)0) {
                local_8 = (uint32_t*)0;
            }
        }
        puVar14 = (uint32_t*)0;
        if (local_8 == (uint32_t*)0) goto LAB_006990de;
        puVar12 = local_8;
        if (local_30 != (uint32_t*)0) {
            iVar8 = *(int32_t*)(selfBase + 0x14);
            uVar17 = local_48;
            do {
                iVar7 = *(int32_t*)(iVar8 + puVar12[(int32_t)(intptr_t)puVar14] * 4);
                uVar10 = 0;
                if (uVar17 != 0) {
                    do {
                        if (*(int32_t*)(iVar7 + 0x48) == local_60[uVar10]) break;
                        uVar10 = uVar10 + 1;
                    } while (uVar10 < uVar17);
                    puVar12 = local_8;
                }
                if (uVar10 == uVar17) {
                    local_60[uVar17] = *(int32_t*)(iVar7 + 0x48);
                    uVar17 = uVar17 + 1;
                }
                puVar14 = (uint32_t*)((int32_t)(intptr_t)puVar14 + 1);
            } while (puVar14 < local_30);
            local_48 = uVar17;
        }
        local_20 = puVar12;
LAB_00698f6f:
        local_8 = (uint32_t*)0;
        if (local_48 != 0) {
            do {
                if ((local_60[(int32_t)(intptr_t)local_8] == -1) ||
                    (puVar14 = *(uint32_t**)(*(int32_t*)(selfBase + 0x18) +
                                             local_60[(int32_t)(intptr_t)local_8] * 4),
                     (*puVar14 & 0xf0000000) == 0x60000000)) {
                    goto LAB_006990c2;
                }
                puVar12 = (uint32_t*)puVar14[3];
                puVar13 = (uint32_t*)0;
                local_1c = (uint32_t*)0;
                if (local_30 != (uint32_t*)0) {
                    do {
                        if (puVar12 != (uint32_t*)0) {
                            puVar5 = (uint32_t*)puVar14[4];
                            local_3c = puVar12;
                            do {
                                if (*puVar5 == local_20[(int32_t)(intptr_t)puVar13]) {
                                    local_1c = (uint32_t*)((int32_t)(intptr_t)local_1c + 1);
                                }
                                puVar5 = puVar5 + 1;
                                local_3c = (uint32_t*)((int32_t)(intptr_t)local_3c - 1);
                            } while (local_3c != (uint32_t*)0);
                        }
                        puVar13 = (uint32_t*)((int32_t)(intptr_t)puVar13 + 1);
                    } while (puVar13 < local_30);
                }
                if (local_1c != puVar12) {
                    local_4c = 1;
                    break;
                }
                local_8 = (uint32_t*)((int32_t)(intptr_t)local_8 + 1);
            } while (local_8 < local_48);
        }
        puVar14 = (uint32_t*)0;
        if (local_4c == 0) {
            uVar10 = 0;
            uVar17 = 0xffffffff;
            if (local_30 != (uint32_t*)0) {
                do {
                    iVar8 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                        local_20[(int32_t)(intptr_t)puVar14] * 4);
                    uVar18 = *(uint32_t*)(iVar8 + 0x58);
                    if (uVar10 < uVar18) {
                        uVar10 = uVar18;
                    }
                    uVar18 = *(uint32_t*)(iVar8 + 0x54);
                    if (uVar18 < uVar17) {
                        uVar17 = uVar18;
                    }
                    puVar14 = (uint32_t*)((int32_t)(intptr_t)puVar14 + 1);
                } while (puVar14 < local_30);
            }
            if (*(uint32_t*)(selfBase + 0xc) != 0) {
                local_1c = *(uint32_t**)(selfBase + 0x18);
                local_34 = *(uint32_t**)(selfBase + 0xc);
                do {
                    puVar14 = (uint32_t*)*local_1c;
                    if (*puVar14 != 0) {
                        puVar12 = (uint32_t*)0;
                        bVar20 = local_44 == (uint32_t*)0;
                        if (local_44 != (uint32_t*)0) {
                            do {
                                if (puVar14 == local_f0[(int32_t)(intptr_t)puVar12]) break;
                                puVar12 = (uint32_t*)((int32_t)(intptr_t)puVar12 + 1);
                            } while (puVar12 < local_44);
                            bVar20 = puVar12 == local_44;
                        }
                        if ((bVar20) && ((uint32_t*)puVar14[1] != (uint32_t*)0)) {
                            puVar12 = (uint32_t*)puVar14[2];
                            local_3c = (uint32_t*)puVar14[1];
                            do {
                                puVar14 = (uint32_t*)0;
                                if (local_30 != (uint32_t*)0) {
                                    do {
                                        if ((local_20[(int32_t)(intptr_t)puVar14] == *puVar12) ||
                                            (*(uint32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) + *puVar12 * 4) + 0x38) ==
                                             local_20[(int32_t)(intptr_t)puVar14])) {
                                            local_4c = 1;
                                        }
                                        puVar14 = (uint32_t*)((int32_t)(intptr_t)puVar14 + 1);
                                    } while (puVar14 < local_30);
                                }
                                puVar12 = puVar12 + 1;
                                local_3c = (uint32_t*)((int32_t)(intptr_t)local_3c - 1);
                            } while (local_3c != (uint32_t*)0);
                        }
                    }
                    local_1c = local_1c + 1;
                    local_34 = (uint32_t*)((int32_t)(intptr_t)local_34 - 1);
                } while (local_34 != (uint32_t*)0);
                if (local_4c != 0) goto LAB_006990c2;
            }
            local_3c = (uint32_t*)0;
            if (local_48 != 0) {
                do {
                    iVar8 = *(int32_t*)(*(int32_t*)(selfBase + 0x18) +
                                        local_60[(int32_t)(intptr_t)local_3c] * 4);
                    local_50 = *(uint32_t**)(*(int32_t*)(selfBase + 0x100) + 0xc);
                    local_c = (uint32_t*)0;
                    if (local_50 != (uint32_t*)0) {
                        do {
                            local_1c = (uint32_t*)0;
                            if (*(int32_t*)(iVar8 + 0xc) != 0) {
                                do {
                                    if (*(uint32_t*)(*(int32_t*)(iVar8 + 0x10) +
                                                    (int32_t)(intptr_t)local_1c * 4) ==
                                        local_20[(int32_t)(intptr_t)local_c]) {
                                        *(uint32_t*)(*(int32_t*)(iVar8 + 0x10) +
                                                     (int32_t)(intptr_t)local_1c * 4) =
                                            *(uint32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x100) + 0x10) +
                                                         (int32_t)(intptr_t)local_c * 4);
                                        bVar4 = *(uint8_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                                                        *(int32_t*)(*(int32_t*)(iVar8 + 0x10) + (int32_t)(intptr_t)local_1c * 4) * 4) +
                                                            0x3d);
                                        *(uint8_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                                               *(int32_t*)(*(int32_t*)(iVar8 + 0x10) + (int32_t)(intptr_t)local_1c * 4) * 4) +
                                                    0x3d) = bVar4 | 2;
                                    }
                                    local_1c = (uint32_t*)((int32_t)(intptr_t)local_1c + 1);
                                } while (local_1c < *(uint32_t*)(iVar8 + 0xc));
                            }
                            local_c = (uint32_t*)((int32_t)(intptr_t)local_c + 1);
                        } while (local_c < local_50);
                    }
                    local_3c = (uint32_t*)((int32_t)(intptr_t)local_3c + 1);
                } while (local_3c < local_48);
            }
            puVar14 = (uint32_t*)0;
            if (local_44 != (uint32_t*)0) {
                do {
                    *local_f0[(int32_t)(intptr_t)puVar14] = 0;
                    puVar14 = (uint32_t*)((int32_t)(intptr_t)puVar14 + 1);
                } while (puVar14 < local_44);
            }
        }
        else {
LAB_006990c2:
            iVar8 = FUN_0065d0b4(0x74);
            if (iVar8 == 0) {
                iVar8 = 0;
            }
            else {
                iVar8 = FUN_0065cc1a();
            }
            if (iVar8 == 0) goto LAB_006990de;
            iVar7 = FUN_0065d0ff((uint32_t)(uintptr_t)local_30 & 0xfffff | 0x10000000,
                                 (uint32_t)(uintptr_t)local_30,
                                 (uint32_t)(uintptr_t)local_30, 0);
            if ((iVar7 < 0) ||
                (iVar7 = FUN_0065cc50(*(void**)(selfBase + 0x100)), iVar7 < 0)) {
                FUN_00614343(1);
                return iVar7;
            }
            puVar14 = local_20;
            puVar12 = *(uint32_t**)(iVar8 + 8);
            for (uVar17 = (uint32_t)(uintptr_t)local_30 & 0x3fffffff; uVar17 != 0;
                 uVar17 = uVar17 - 1) {
                *puVar12 = *puVar14;
                puVar14 = puVar14 + 1;
                puVar12 = puVar12 + 1;
            }
            for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                *(char*)puVar12 = (char)*puVar14;
                puVar14 = (uint32_t*)((uint8_t*)puVar14 + 1);
                puVar12 = (uint32_t*)((uint8_t*)puVar12 + 1);
            }
            puVar16 = *(uint32_t**)(*(int32_t*)(selfBase + 0x100) + 0x10);
            puVar19 = *(uint32_t**)(iVar8 + 0x10);
            for (uVar17 = (uint32_t)(uintptr_t)local_30 & 0x3fffffff; uVar17 != 0;
                 uVar17 = uVar17 - 1) {
                *puVar19 = *puVar16;
                puVar16 = puVar16 + 1;
                puVar19 = puVar19 + 1;
            }
            for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                *(uint8_t*)puVar19 = *(uint8_t*)puVar16;
                puVar16 = (uint32_t*)((uint8_t*)puVar16 + 1);
                puVar19 = (uint32_t*)((uint8_t*)puVar19 + 1);
            }
            puVar14 = (uint32_t*)0;
            if (local_30 != (uint32_t*)0) {
                do {
                    bVar4 = *(uint8_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                                    *(int32_t*)(*(int32_t*)(iVar8 + 0x10) +
                                                                (int32_t)(intptr_t)puVar14 * 4) * 4) + 0x3d);
                    *(uint8_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                            *(int32_t*)(*(int32_t*)(iVar8 + 0x10) +
                                                        (int32_t)(intptr_t)puVar14 * 4) * 4) + 0x3d) =
                        bVar4 | 2;
                    puVar14 = (uint32_t*)((int32_t)(intptr_t)puVar14 + 1);
                } while (puVar14 < local_30);
            }
            puVar14 = (uint32_t*)0;
            if (local_44 != (uint32_t*)0) {
                do {
                    ppuVar15 = local_f0 + (int32_t)(intptr_t)puVar14;
                    puVar14 = (uint32_t*)((int32_t)(intptr_t)puVar14 + 1);
                    **ppuVar15 = 0;
                } while (puVar14 < local_44);
            }
            piVar11 = (int32_t*)(selfBase + 0xfc);
            if (*(int32_t*)(*(int32_t*)(selfBase + 0x18) + *piVar11 * 4) != 0) {
                FUN_00614343(1);
            }
            *(int32_t*)(*(int32_t*)(selfBase + 0x18) + *piVar11 * 4) = iVar8;
        }
        iVar8 = 0;
    }
    else {
        local_38 = *(uint32_t**)(selfBase + 0x100);
        local_c = (uint32_t*)(*local_38 & 0xfffff);
        local_30 = (uint32_t*)(*local_38 & 0xfffff);
        local_3c = (uint32_t*)1;
        if ((local_c <= (uint32_t*)(*local_38 & 0xfffff)) && ((*local_38 & 0xfff00000) == 0x30000000)) {
            local_2c = (uint32_t*)0;
            local_40 = (uint32_t)((int32_t)(intptr_t)local_44 << 2);
LAB_00697e32:
            local_28 = (uint32_t*)0;
            do {
                uVar17 = local_40;
                ppuVar15 = local_f0;
                puVar14 = local_b0;
                for (uVar10 = local_40 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
                    *puVar14 = (uint32_t)*ppuVar15;
                    ppuVar15 = ppuVar15 + 1;
                    puVar14 = puVar14 + 1;
                }
                for (uVar17 = uVar17 & 3; uVar17 != 0; uVar17 = uVar17 - 1) {
                    *(uint8_t*)puVar14 = *(uint8_t*)ppuVar15;
                    ppuVar15 = (uint32_t**)((uint8_t*)ppuVar15 + 1);
                    puVar14 = (uint32_t*)((uint8_t*)puVar14 + 1);
                }
                puVar14 = local_230;
                for (iVar8 = 0x28; iVar8 != 0; iVar8 = iVar8 + -1) {
                    *puVar14 = 0xffffffff;
                    puVar14 = puVar14 + 1;
                }
                piVar11 = local_2d0;
                for (iVar8 = 0x28; iVar8 != 0; iVar8 = iVar8 + -1) {
                    *piVar11 = -1;
                    piVar11 = piVar11 + 1;
                }
                iVar8 = 0;
                local_20 = local_44;
                local_14 = 0;
                local_10 = 0;
                do {
                    if (local_28 == (uint32_t*)0) {
                        uVar17 = local_10;
                    }
                    else {
                        uVar17 = 1 - local_10;
                    }
                    uVar10 = local_38[2];
                    uVar17 = *(uint32_t*)(&DAT_006f1a4c[0] + uVar17 * 4);
                    piVar11 = (int32_t*)(uintptr_t)(uVar10 + iVar8 * 4);
                    if (uVar17 < 0x10) {
                        iVar7 = *(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                                        *piVar11 * 4) + 0x48);
                        if (iVar7 != -1) {
                            uVar2 = *(uint32_t*)(*(int32_t*)(selfBase + 0x18) + iVar7 * 4);
                            iVar7 = FUN_006949cb((void*)(uintptr_t)uVar2, piVar11,
                                                 (uint32_t)(uintptr_t)local_c, local_60, local_70,
                                                 &DAT_006f1a58[0] + uVar17 * 0x20, 0);
                            if (iVar7 == 0) {
                                local_14 = FUN_00694b7c((void*)(uintptr_t)uVar2,
                                                        &DAT_006f1a40[0] + uVar17 * 0x20,
                                                        local_b0, &local_20, local_2d0, local_70,
                                                        (uint32_t)(uintptr_t)local_30, 0);
                                goto LAB_00697f43;
                            }
                        }
                        local_14 = 1;
                        break;
                    }
                    uVar18 = 0;
                    puVar14 = local_230 + (uVar17 - 0x10) * 4;
                    do {
                        if ((uint32_t*)local_60[uVar18] < local_c) {
                            *puVar14 = *(uint32_t*)(uintptr_t)
                                       (uVar10 + (iVar8 + local_60[uVar18]) * 4);
                        }
                        else {
                            *puVar14 = 0xffffffff;
                        }
                        uVar18 = uVar18 + 1;
                        puVar14 = puVar14 + 1;
                    } while (uVar18 < 4);
LAB_00697f43:
                    if (local_14 == 1) break;
                    local_10 = local_10 + 1;
                    iVar8 = iVar8 + (int32_t)(intptr_t)local_c;
                } while (local_10 < 3);
                puVar14 = local_20;
                local_10 = 0;
                local_24 = (uint32_t*)0;
                do {
                    if (local_28 == (uint32_t*)0) {
                        uVar17 = local_10;
                    }
                    else {
                        uVar17 = 1 - local_10;
                    }
                    if ((0xf < *(uint32_t*)(&DAT_006f1a4c[0] + uVar17 * 4)) &&
                        (local_8 = (uint32_t*)0, local_20 != (uint32_t*)0)) {
                        do {
                            puVar12 = (uint32_t*)0;
                            if (local_c != (uint32_t*)0) {
                                puVar13 = *(uint32_t**)(local_b0[(int32_t)(intptr_t)local_8] + 0xc);
                                do {
                                    local_1c = (uint32_t*)0;
                                    if (puVar13 != (uint32_t*)0) {
                                        piVar11 = *(int32_t**)(uintptr_t)(local_b0[(int32_t)(intptr_t)local_8] + 0x10);
                                        do {
                                            if (*(int32_t*)(uintptr_t)
                                                (local_38[2] + ((int32_t)(intptr_t)local_24 +
                                                                (int32_t)(intptr_t)puVar12) * 4) ==
                                                *piVar11) {
                                                local_14 = 1;
                                                goto LAB_00697fda;
                                            }
                                            local_1c = (uint32_t*)((int32_t)(intptr_t)local_1c + 1);
                                            piVar11 = piVar11 + 1;
                                        } while (local_1c < puVar13);
                                    }
                                    puVar12 = (uint32_t*)((int32_t)(intptr_t)puVar12 + 1);
                                } while (puVar12 < local_c);
                            }
LAB_00697fda:
                            local_8 = (uint32_t*)((int32_t)(intptr_t)local_8 + 1);
                        } while (local_8 < local_20);
                    }
                    local_10 = local_10 + 1;
                    local_24 = (uint32_t*)((int32_t)(intptr_t)local_24 + (int32_t)(intptr_t)local_c);
                } while (local_10 < 3);
                if (local_14 == 0) {
                    if (local_2c != (uint32_t*)0) goto LAB_00698179;
                    local_1c = (uint32_t*)0;
                    if (local_20 != (uint32_t*)0) {
                        do {
                            local_50 = *(uint32_t**)(local_b0[(int32_t)(intptr_t)local_1c] + 0xc);
                            local_8 = (uint32_t*)0;
                            if (local_50 != (uint32_t*)0) {
                                do {
                                    if (*(uint32_t*)(selfBase + 0xc) != 0) {
                                        local_24 = *(uint32_t**)(selfBase + 0x18);
                                        local_10 = *(uint32_t*)(selfBase + 0xc);
                                        do {
                                            puVar12 = (uint32_t*)*local_24;
                                            if ((puVar12 != (uint32_t*)0) && (*puVar12 != 0)) {
                                                uVar17 = puVar12[1];
                                                local_34 = (uint32_t*)0;
                                                if (uVar17 != 0) {
                                                    iVar8 = *(int32_t*)(
                                                        *(int32_t*)(local_b0[(int32_t)(intptr_t)local_1c] + 0x10) +
                                                        (int32_t)(intptr_t)local_8 * 4);
                                                    piVar11 = (int32_t*)puVar12[2];
                                                    do {
                                                        if ((*piVar11 == iVar8) ||
                                                            (*(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) + *piVar11 * 4) + 0x38) == iVar8)) {
                                                            local_34 = (uint32_t*)1;
                                                        }
                                                        piVar11 = piVar11 + 1;
                                                        uVar17 = uVar17 - 1;
                                                    } while (uVar17 != 0);
                                                }
                                                if (puVar12 == local_38) {
                                                    puVar13 = (uint32_t*)0;
                                                }
                                                else {
                                                    puVar13 = local_34;
                                                }
                                                if (puVar13 != (uint32_t*)0) {
                                                    puVar5 = (uint32_t*)0;
                                                    do {
                                                        if (puVar12 == (uint32_t*)local_b0[(int32_t)(intptr_t)puVar5]) {
                                                            puVar13 = (uint32_t*)0;
                                                        }
                                                        puVar5 = (uint32_t*)((int32_t)(intptr_t)puVar5 + 1);
                                                    } while (puVar5 < local_20);
                                                    if (puVar13 != (uint32_t*)0) {
                                                        local_14 = 1;
                                                    }
                                                }
                                            }
                                            local_24 = local_24 + 1;
                                            local_10 = local_10 - 1;
                                        } while (local_10 != 0);
                                    }
                                    local_8 = (uint32_t*)((int32_t)(intptr_t)local_8 + 1);
                                } while (local_8 < local_50);
                            }
                            local_1c = (uint32_t*)((int32_t)(intptr_t)local_1c + 1);
                        } while (local_1c < local_20);
                    }
                    local_8 = (uint32_t*)0;
                    do {
                        uVar17 = local_230[(int32_t)(intptr_t)local_8];
                        if ((uVar17 != 0xffffffff) &&
                            (puVar12 = (uint32_t*)0, local_20 != (uint32_t*)0)) {
                            do {
                                iVar8 = *(int32_t*)(local_b0[(int32_t)(intptr_t)puVar12] + 0xc);
                                if (iVar8 != 0) {
                                    puVar13 = *(uint32_t**)(local_b0[(int32_t)(intptr_t)puVar12] + 0x10);
                                    do {
                                        if ((uVar17 == *puVar13) ||
                                            (*(uint32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) + uVar17 * 4) + 0x38) == *puVar13)) {
                                            local_14 = 1;
                                        }
                                        puVar13 = puVar13 + 1;
                                        iVar8 = iVar8 + -1;
                                    } while (iVar8 != 0);
                                }
                                puVar12 = (uint32_t*)((int32_t)(intptr_t)puVar12 + 1);
                            } while (puVar12 < local_20);
                        }
                        local_8 = (uint32_t*)((int32_t)(intptr_t)local_8 + 1);
                    } while (local_8 < (uint32_t*)0x28);
                    if (local_14 == 0) goto LAB_00698179;
                }
                local_28 = (uint32_t*)((int32_t)(intptr_t)local_28 + 1);
            } while (local_28 == (uint32_t*)0);
            if (local_14 != 0) goto code_r0x0069816a;
LAB_00698179:
            puVar12 = local_b0;
            ppuVar15 = local_f0;
            for (uVar17 = (uint32_t)(uintptr_t)local_20 & 0x3fffffff; uVar17 != 0;
                 uVar17 = uVar17 - 1) {
                *ppuVar15 = (uint32_t*)*puVar12;
                puVar12 = puVar12 + 1;
                ppuVar15 = ppuVar15 + 1;
            }
            for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
                *(char*)ppuVar15 = (char)*puVar12;
                puVar12 = (uint32_t*)((uint8_t*)puVar12 + 1);
                ppuVar15 = (uint32_t**)((uint8_t*)ppuVar15 + 1);
            }
            local_f0[(int32_t)(intptr_t)puVar14] = local_38;
            local_44 = (uint32_t*)((int32_t)(intptr_t)puVar14 + 1);
            uVar17 = 0;
            do {
                iVar8 = *(int32_t*)((uint8_t*)local_230 + uVar17);
                if ((iVar8 != -1) ||
                    (iVar8 = *(int32_t*)((uint8_t*)local_2d0 + uVar17), iVar8 != -1)) {
                    *(int32_t*)((uint8_t*)auStack_190 + uVar17) = iVar8;
                }
                uVar17 = uVar17 + 4;
            } while (uVar17 < 0xa0);
            local_14 = 0;
LAB_006981da:
            iVar8 = local_14;
            if (local_14 == 1) goto LAB_006981e6;
            goto LAB_006985d3;
        }
LAB_006981e6:
        local_38 = *(uint32_t**)(selfBase + 0x100);
        uVar17 = **(uint32_t**)(selfBase + 0x100);
        local_20 = (uint32_t*)(uVar17 & 0xfffff);
        if ((local_20 <= local_30) && ((uVar17 & 0xfff00000) == 0x30000000)) {
            local_2c = (uint32_t*)0;
            local_40 = (uint32_t)((int32_t)(intptr_t)local_44 << 2);
LAB_00698225:
            local_28 = (uint32_t*)0;
            do {
                uVar17 = local_40;
                ppuVar15 = local_f0;
                puVar14 = local_b0;
                for (uVar10 = local_40 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
                    *puVar14 = (uint32_t)*ppuVar15;
                    ppuVar15 = ppuVar15 + 1;
                    puVar14 = puVar14 + 1;
                }
                for (uVar17 = uVar17 & 3; uVar17 != 0; uVar17 = uVar17 - 1) {
                    *(uint8_t*)puVar14 = *(uint8_t*)ppuVar15;
                    ppuVar15 = (uint32_t**)((uint8_t*)ppuVar15 + 1);
                    puVar14 = (uint32_t*)((uint8_t*)puVar14 + 1);
                }
                puVar14 = local_230;
                for (iVar8 = 0x28; iVar8 != 0; iVar8 = iVar8 + -1) {
                    *puVar14 = 0xffffffff;
                    puVar14 = puVar14 + 1;
                }
                piVar11 = local_2d0;
                for (iVar8 = 0x28; iVar8 != 0; iVar8 = iVar8 + -1) {
                    *piVar11 = -1;
                    piVar11 = piVar11 + 1;
                }
                iVar8 = 0;
                local_c = local_44;
                local_14 = 0;
                local_10 = 0;
                do {
                    if (local_28 == (uint32_t*)0) {
                        uVar17 = local_10;
                    }
                    else {
                        uVar17 = 1 - local_10;
                    }
                    uVar10 = local_38[2];
                    uVar17 = *(uint32_t*)(&DAT_006f1bac[0] + uVar17 * 4);
                    piVar11 = (int32_t*)(uintptr_t)(uVar10 + iVar8 * 4);
                    if (uVar17 < 0x10) {
                        iVar7 = *(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                                        *piVar11 * 4) + 0x48);
                        if (iVar7 != -1) {
                            uVar2 = *(uint32_t*)(*(int32_t*)(selfBase + 0x18) + iVar7 * 4);
                            iVar7 = FUN_006949cb((void*)(uintptr_t)uVar2, piVar11,
                                                 (uint32_t)(uintptr_t)local_20, local_60, local_70,
                                                 &DAT_006f1bb8[0] + uVar17 * 0x20, 0);
                            if (iVar7 == 0) {
                                local_14 = FUN_00694b7c((void*)(uintptr_t)uVar2,
                                                        &DAT_006f1ba0[0] + uVar17 * 0x20,
                                                        local_b0, &local_c, local_2d0, local_70,
                                                        (uint32_t)(uintptr_t)local_30, 0);
                                goto LAB_00698335;
                            }
                        }
                        local_14 = 1;
                        break;
                    }
                    uVar18 = 0;
                    puVar14 = local_230 + (uVar17 - 0x10) * 4;
                    do {
                        if ((uint32_t*)local_60[uVar18] < local_20) {
                            *puVar14 = *(uint32_t*)(uintptr_t)
                                       (uVar10 + (local_60[uVar18] + iVar8) * 4);
                        }
                        else {
                            *puVar14 = 0xffffffff;
                        }
                        uVar18 = uVar18 + 1;
                        puVar14 = puVar14 + 1;
                    } while (uVar18 < 4);
LAB_00698335:
                    if (local_14 == 1) break;
                    local_10 = local_10 + 1;
                    iVar8 = iVar8 + (int32_t)(intptr_t)local_20;
                } while (local_10 < 3);
                puVar14 = local_c;
                local_10 = 0;
                local_24 = (uint32_t*)0;
                do {
                    if (local_28 == (uint32_t*)0) {
                        uVar17 = local_10;
                    }
                    else {
                        uVar17 = 1 - local_10;
                    }
                    if ((0xf < *(uint32_t*)(&DAT_006f1bac[0] + uVar17 * 4)) &&
                        (local_8 = (uint32_t*)0, local_c != (uint32_t*)0)) {
                        do {
                            puVar12 = (uint32_t*)0;
                            if (local_20 != (uint32_t*)0) {
                                puVar13 = *(uint32_t**)(local_b0[(int32_t)(intptr_t)local_8] + 0xc);
                                do {
                                    local_1c = (uint32_t*)0;
                                    if (puVar13 != (uint32_t*)0) {
                                        piVar11 = *(int32_t**)(uintptr_t)(local_b0[(int32_t)(intptr_t)local_8] + 0x10);
                                        do {
                                            if (*(int32_t*)(uintptr_t)
                                                (local_38[2] + ((int32_t)(intptr_t)local_24 +
                                                                (int32_t)(intptr_t)puVar12) * 4) ==
                                                *piVar11) {
                                                local_14 = 1;
                                                goto LAB_006983cc;
                                            }
                                            local_1c = (uint32_t*)((int32_t)(intptr_t)local_1c + 1);
                                            piVar11 = piVar11 + 1;
                                        } while (local_1c < puVar13);
                                    }
                                    puVar12 = (uint32_t*)((int32_t)(intptr_t)puVar12 + 1);
                                } while (puVar12 < local_20);
                            }
LAB_006983cc:
                            local_8 = (uint32_t*)((int32_t)(intptr_t)local_8 + 1);
                        } while (local_8 < local_c);
                    }
                    local_10 = local_10 + 1;
                    local_24 = (uint32_t*)((int32_t)(intptr_t)local_24 + (int32_t)(intptr_t)local_20);
                } while (local_10 < 3);
                if (local_14 == 0) {
                    if (local_2c != (uint32_t*)0) goto LAB_0069856b;
                    local_1c = (uint32_t*)0;
                    if (local_c != (uint32_t*)0) {
                        do {
                            local_50 = *(uint32_t**)(local_b0[(int32_t)(intptr_t)local_1c] + 0xc);
                            local_8 = (uint32_t*)0;
                            if (local_50 != (uint32_t*)0) {
                                do {
                                    if (*(uint32_t*)(selfBase + 0xc) != 0) {
                                        local_24 = *(uint32_t**)(selfBase + 0x18);
                                        local_10 = *(uint32_t*)(selfBase + 0xc);
                                        do {
                                            puVar12 = (uint32_t*)*local_24;
                                            if ((puVar12 != (uint32_t*)0) && (*puVar12 != 0)) {
                                                uVar17 = puVar12[1];
                                                local_34 = (uint32_t*)0;
                                                if (uVar17 != 0) {
                                                    iVar8 = *(int32_t*)(
                                                        *(int32_t*)(local_b0[(int32_t)(intptr_t)local_1c] + 0x10) +
                                                        (int32_t)(intptr_t)local_8 * 4);
                                                    piVar11 = (int32_t*)puVar12[2];
                                                    do {
                                                        if ((*piVar11 == iVar8) ||
                                                            (*(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) + *piVar11 * 4) + 0x38) == iVar8)) {
                                                            local_34 = (uint32_t*)1;
                                                        }
                                                        piVar11 = piVar11 + 1;
                                                        uVar17 = uVar17 - 1;
                                                    } while (uVar17 != 0);
                                                }
                                                if (puVar12 == local_38) {
                                                    puVar13 = (uint32_t*)0;
                                                }
                                                else {
                                                    puVar13 = local_34;
                                                }
                                                if (puVar13 != (uint32_t*)0) {
                                                    puVar5 = (uint32_t*)0;
                                                    do {
                                                        if (puVar12 == (uint32_t*)local_b0[(int32_t)(intptr_t)puVar5]) {
                                                            puVar13 = (uint32_t*)0;
                                                        }
                                                        puVar5 = (uint32_t*)((int32_t)(intptr_t)puVar5 + 1);
                                                    } while (puVar5 < local_c);
                                                    if (puVar13 != (uint32_t*)0) {
                                                        local_14 = 1;
                                                    }
                                                }
                                            }
                                            local_24 = local_24 + 1;
                                            local_10 = local_10 - 1;
                                        } while (local_10 != 0);
                                    }
                                    local_8 = (uint32_t*)((int32_t)(intptr_t)local_8 + 1);
                                } while (local_8 < local_50);
                            }
                            local_1c = (uint32_t*)((int32_t)(intptr_t)local_1c + 1);
                        } while (local_1c < local_c);
                    }
                    local_8 = (uint32_t*)0;
                    do {
                        uVar17 = local_230[(int32_t)(intptr_t)local_8];
                        if ((uVar17 != 0xffffffff) &&
                            (puVar12 = (uint32_t*)0, local_c != (uint32_t*)0)) {
                            do {
                                iVar8 = *(int32_t*)(local_b0[(int32_t)(intptr_t)puVar12] + 0xc);
                                if (iVar8 != 0) {
                                    puVar13 = *(uint32_t**)(local_b0[(int32_t)(intptr_t)puVar12] + 0x10);
                                    do {
                                        if ((uVar17 == *puVar13) ||
                                            (*(uint32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) + uVar17 * 4) + 0x38) == *puVar13)) {
                                            local_14 = 1;
                                        }
                                        puVar13 = puVar13 + 1;
                                        iVar8 = iVar8 + -1;
                                    } while (iVar8 != 0);
                                }
                                puVar12 = (uint32_t*)((int32_t)(intptr_t)puVar12 + 1);
                            } while (puVar12 < local_c);
                        }
                        local_8 = (uint32_t*)((int32_t)(intptr_t)local_8 + 1);
                    } while (local_8 < (uint32_t*)0x28);
                    if (local_14 == 0) goto LAB_0069856b;
                }
                local_28 = (uint32_t*)((int32_t)(intptr_t)local_28 + 1);
            } while (local_28 == (uint32_t*)0);
            if (local_14 != 0) goto code_r0x0069855c;
LAB_0069856b:
            puVar12 = local_b0;
            ppuVar15 = local_f0;
            for (uVar17 = (uint32_t)(uintptr_t)local_c & 0x3fffffff; uVar17 != 0;
                 uVar17 = uVar17 - 1) {
                *ppuVar15 = (uint32_t*)*puVar12;
                puVar12 = puVar12 + 1;
                ppuVar15 = ppuVar15 + 1;
            }
            for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
                *(char*)ppuVar15 = (char)*puVar12;
                puVar12 = (uint32_t*)((uint8_t*)puVar12 + 1);
                ppuVar15 = (uint32_t**)((uint8_t*)ppuVar15 + 1);
            }
            local_f0[(int32_t)(intptr_t)puVar14] = local_38;
            local_44 = (uint32_t*)((int32_t)(intptr_t)puVar14 + 1);
            uVar17 = 0;
            do {
                iVar8 = *(int32_t*)((uint8_t*)local_230 + uVar17);
                if ((iVar8 != -1) ||
                    (iVar8 = *(int32_t*)((uint8_t*)local_2d0 + uVar17), iVar8 != -1)) {
                    *(int32_t*)((uint8_t*)auStack_190 + uVar17) = iVar8;
                }
                uVar17 = uVar17 + 4;
            } while (uVar17 < 0xa0);
            local_14 = 0;
LAB_006985cc:
            iVar8 = local_14;
            goto LAB_006985cf;
        }
        iVar8 = 1;
LAB_006985cf:
        local_3c = (uint32_t*)0;
LAB_006985d3:
        if (iVar8 == 0) {
            local_8 = (uint32_t*)0;
            if (local_30 != (uint32_t*)0) {
                do {
                    iVar8 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                        auStack_190[(int32_t)(intptr_t)local_8] * 4);
                    uVar17 = auStack_190[(int32_t)(intptr_t)(local_8 + 2)];
                    local_34 = *(uint32_t**)(*(int32_t*)(selfBase + 0x14) +
                                             auStack_190[(int32_t)(intptr_t)(local_8 + 1)] * 4);
                    if ((((uVar17 != auStack_190[(int32_t)(intptr_t)(local_8 + 5)]) ||
                          (auStack_190[(int32_t)(intptr_t)(local_8 + 3)] !=
                           auStack_190[(int32_t)(intptr_t)(local_8 + 6)])) ||
                         (auStack_190[(int32_t)(intptr_t)(local_8 + 4)] !=
                          auStack_190[(int32_t)(intptr_t)(local_8 + 7)])) ||
                        (uVar17 != auStack_190[(int32_t)(intptr_t)(local_8 + 3)])) {
                        goto LAB_006990de;
                    }
                    iVar7 = *(int32_t*)(selfBase + 0x10);
                    iVar6 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                        auStack_190[(int32_t)(intptr_t)(local_8 + 4)] * 4);
                    if (((((*(uint8_t*)(*(int32_t*)(iVar7 + *(int32_t*)(iVar8 + 4) * 4) + 5) & 1) == 0) ||
                          ((*(uint8_t*)(*(int32_t*)(iVar7 + local_34[1] * 4) + 5) & 1) == 0)) ||
                         (((*(uint8_t*)(*(int32_t*)(iVar7 + *(int32_t*)(iVar6 + 4) * 4) + 5) & 1) == 0 ||
                           ((*(double*)(iVar8 + 0x20) != 1.0 ||
                             (local_50 = (uint32_t*)((uint32_t)(local_3c == (uint32_t*)0) * 2 - 1),
                              *(double*)((uint8_t*)local_34 + 8) != (double)(int32_t)(intptr_t)local_50)))))) ||
                        (*(double*)(iVar6 + 0x20) != 0.0)) {
                        goto LAB_006990de;
                    }
                    iVar8 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) + uVar17 * 4);
                    if (*(int32_t*)(iVar8 + 4) != *(int32_t*)(selfBase + 0x88)) {
                        local_4c = 1;
                    }
                    uVar17 = 0;
                    if (local_48 != 0) {
                        do {
                            if (*(int32_t*)(iVar8 + 0x48) == local_60[uVar17]) break;
                            uVar17 = uVar17 + 1;
                        } while (uVar17 < local_48);
                    }
                    if ((uVar17 == local_48) && (local_4c == 0)) {
                        local_60[local_48] = *(int32_t*)(iVar8 + 0x48);
                        local_48 = local_48 + 1;
                    }
                    local_8 = (uint32_t*)((int32_t)(intptr_t)local_8 + 1);
                } while (local_8 < local_30);
            }
            local_20 = auStack_190 + 8;
            goto LAB_00698f6f;
        }
        if (iVar8 != 1) {
LAB_00698f67:
            if (iVar8 != 0) {
                return iVar8;
            }
            goto LAB_00698f6f;
        }
        local_38 = *(uint32_t**)(selfBase + 0x100);
        uVar17 = **(uint32_t**)(selfBase + 0x100);
        local_20 = (uint32_t*)(uVar17 & 0xfffff);
        if ((local_30 < local_20) || ((uVar17 & 0xfff00000) != 0x30000000)) {
            iVar8 = 1;
LAB_00698774:
            local_c = (uint32_t*)0;
            local_34 = (uint32_t*)0;
            if (((*(uint8_t*)(selfBase + 0x6e) & 0x40) == 0) ||
                ((iVar6 = (int32_t)FUN_696b3c(self, (int32_t*)&local_c, (int32_t*)local_f0,
                                              (int32_t*)&local_44), iVar6 != 0 &&
                  (iVar6 = FUN_697138(self, (int32_t*)&local_c, (int32_t*)local_f0,
                                      (int32_t*)&local_44), iVar6 != 0)))) {
                local_44 = (uint32_t*)1;
                local_f0[0] = *(uint32_t**)(selfBase + 0x100);
                local_c = *(uint32_t**)(selfBase + 0x100);
            }
            else {
                local_34 = local_c;
            }
            if ((local_c != (uint32_t*)0) && ((*local_c & 0xfff00000) == 0x70b00000)) {
                local_30 = (uint32_t*)(*local_c & 0xfffff);
                local_3c = (uint32_t*)((int32_t)(intptr_t)local_30 << 2);
                local_10 = 0;
                local_8 = (uint32_t*)0;
                local_2c = (uint32_t*)((int32_t)(intptr_t)local_30 * -4);
                do {
                    local_24 = (uint32_t*)0;
                    if (local_30 != (uint32_t*)0) {
                        uVar17 = local_c[2];
                        iVar8 = *(int32_t*)(selfBase + 0x14);
                        local_1c = (uint32_t*)((int32_t)(intptr_t)local_3c + uVar17);
                        puVar14 = local_8;
                        do {
                            bVar4 = *(uint8_t*)(iVar8 + *(int32_t*)((int32_t)(intptr_t)puVar14 + uVar17) * 4);
                            local_50 = *(uint32_t**)(iVar8 + *local_1c * 4);
                            if ((bVar4 & 0x3e) != 0) {
                                if ((*(uint8_t*)(*(int32_t*)(iVar8 + *(int32_t*)((int32_t)(intptr_t)puVar14 + uVar17) * 4) + 0x3e) & 8) == 0) {
                                    bVar4 = *(uint8_t*)(iVar8 + *(int32_t*)((int32_t)(intptr_t)puVar14 + uVar17) * 4) & 4;
                                }
                                else {
                                    bVar4 = *(uint8_t*)(iVar8 + *(int32_t*)((int32_t)(intptr_t)puVar14 + uVar17) * 4) & 8;
                                }
                            }
                            else {
                                bVar4 = 0;
                            }
                            if ((((bVar4 == 0) ||
                                  ((*(uint8_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x10) +
                                                           *(int32_t*)((uint8_t*)local_50 + 4) * 4) + 5) & 1) == 0)) ||
                                 (*(double*)((uint8_t*)local_50 + 0x20) != 1.0)) ||
                                (*(int32_t*)((uint8_t*)local_50 + 8) != -1)) {
                                break;
                            }
                            iVar7 = *(int32_t*)((uint8_t*)local_50 + 4);
                            local_70[(int32_t)(intptr_t)local_24] =
                                *(uint32_t*)((int32_t)(intptr_t)puVar14 + local_c[2]);
                            if (iVar7 != *(int32_t*)(selfBase + 0x88)) {
                                local_4c = 1;
                            }
                            local_1c = local_1c + 1;
                            local_24 = (uint32_t*)((int32_t)(intptr_t)local_24 + 1);
                            puVar14 = puVar14 + 1;
                        } while (local_24 < local_30);
                    }
                    if (local_24 == local_30) {
                        if (local_30 != (uint32_t*)0) {
                            iVar8 = *(int32_t*)(selfBase + 0x14);
                            piVar11 = (int32_t*)(uintptr_t)
                                      (local_c[2] + local_10 * (int32_t)(intptr_t)local_30 * 4);
                            puVar14 = local_30;
                            do {
                                uVar17 = local_48;
                                iVar7 = *(int32_t*)(iVar8 + *piVar11 * 4);
                                if (*(int32_t*)(iVar7 + 0x38) == -1) {
                                    uVar10 = 0;
                                    if (local_48 != 0) {
                                        do {
                                            if (*(int32_t*)(iVar7 + 0x48) == local_60[uVar10]) break;
                                            uVar10 = uVar10 + 1;
                                        } while (uVar10 < local_48);
                                    }
                                    if ((uVar10 == local_48) && (local_4c == 0)) {
                                        local_48 = local_48 + 1;
                                        local_60[uVar17] = *(int32_t*)(iVar7 + 0x48);
                                    }
                                }
                                else {
                                    local_4c = 1;
                                }
                                piVar11 = piVar11 + 1;
                                puVar14 = (uint32_t*)((int32_t)(intptr_t)puVar14 - 1);
                            } while (puVar14 != (uint32_t*)0);
                        }
                        break;
                    }
                    local_10 = local_10 + 1;
                    local_8 = (uint32_t*)((int32_t)(intptr_t)local_8 + (int32_t)(intptr_t)local_30);
                    local_3c = (uint32_t*)((int32_t)(intptr_t)local_3c + (int32_t)(intptr_t)local_2c);
                } while (local_10 < 2);
                if (local_10 == 2) goto LAB_006990de;
                local_20 = local_70;
                iVar8 = 0;
            }
            if (local_34 != (uint32_t*)0) {
                FUN_00614343(1);
            }
            goto LAB_00698f67;
        }
        local_2c = (uint32_t*)0;
LAB_006987cf:
        local_28 = (uint32_t*)0;
        do {
            puVar14 = local_44;
            ppuVar15 = local_f0;
            puVar12 = local_b0;
            for (uVar17 = (uint32_t)(uintptr_t)local_44 & 0x3fffffff; uVar17 != 0;
                 uVar17 = uVar17 - 1) {
                *puVar12 = (uint32_t)*ppuVar15;
                ppuVar15 = ppuVar15 + 1;
                puVar12 = puVar12 + 1;
            }
            for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
                *(uint8_t*)puVar12 = *(uint8_t*)ppuVar15;
                ppuVar15 = (uint32_t**)((uint8_t*)ppuVar15 + 1);
                puVar12 = (uint32_t*)((uint8_t*)puVar12 + 1);
            }
            puVar12 = local_230;
            for (iVar8 = 0x28; iVar8 != 0; iVar8 = iVar8 + -1) {
                *puVar12 = 0xffffffff;
                puVar12 = puVar12 + 1;
            }
            iVar7 = 0;
            piVar11 = local_2d0;
            for (iVar8 = 0x28; iVar8 != 0; iVar8 = iVar8 + -1) {
                *piVar11 = -1;
                piVar11 = piVar11 + 1;
            }
            local_c = puVar14;
            local_14 = 0;
            local_10 = 0;
            do {
                if (local_28 == (uint32_t*)0) {
                    uVar17 = local_10;
                }
                else {
                    uVar17 = 1 - local_10;
                }
                uVar10 = local_38[2];
                uVar17 = *(uint32_t*)(&DAT_006f1aec[0] + uVar17 * 4);
                piVar11 = (int32_t*)(uintptr_t)(uVar10 + iVar7 * 4);
                if (uVar17 < 0x10) {
                    iVar8 = *(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                                    *piVar11 * 4) + 0x48);
                    if (iVar8 != -1) {
                        uVar2 = *(uint32_t*)(*(int32_t*)(selfBase + 0x18) + iVar8 * 4);
                        iVar8 = FUN_006949cb((void*)(uintptr_t)uVar2, piVar11,
                                             (uint32_t)(uintptr_t)local_20, local_60, local_70,
                                             &DAT_006f1af8[0] + uVar17 * 0x20, 0);
                        if (iVar8 == 0) {
                            local_14 = FUN_00694b7c((void*)(uintptr_t)uVar2,
                                                    &DAT_006f1ae0[0] + uVar17 * 0x20,
                                                    local_b0, &local_c, local_2d0, local_70,
                                                    (uint32_t)(uintptr_t)local_30, 0);
                            goto LAB_006988e1;
                        }
                    }
                    local_14 = 1;
                    break;
                }
                uVar18 = 0;
                puVar14 = local_230 + (uVar17 - 0x10) * 4;
                do {
                    if ((uint32_t*)local_60[uVar18] < local_20) {
                        *puVar14 = *(uint32_t*)(uintptr_t)
                                   (uVar10 + (local_60[uVar18] + iVar7) * 4);
                    }
                    else {
                        *puVar14 = 0xffffffff;
                    }
                    uVar18 = uVar18 + 1;
                    puVar14 = puVar14 + 1;
                } while (uVar18 < 4);
LAB_006988e1:
                if (local_14 == 1) break;
                local_10 = local_10 + 1;
                iVar7 = iVar7 + (int32_t)(intptr_t)local_20;
            } while (local_10 < 3);
            puVar14 = local_c;
            local_10 = 0;
            local_24 = (uint32_t*)0;
            do {
                if (local_28 == (uint32_t*)0) {
                    uVar17 = local_10;
                }
                else {
                    uVar17 = 1 - local_10;
                }
                if ((0xf < *(uint32_t*)(&DAT_006f1aec[0] + uVar17 * 4)) &&
                    (local_8 = (uint32_t*)0, local_c != (uint32_t*)0)) {
                    do {
                        puVar12 = (uint32_t*)0;
                        if (local_20 != (uint32_t*)0) {
                            puVar13 = *(uint32_t**)(local_b0[(int32_t)(intptr_t)local_8] + 0xc);
                            do {
                                local_1c = (uint32_t*)0;
                                if (puVar13 != (uint32_t*)0) {
                                    piVar11 = *(int32_t**)(uintptr_t)(local_b0[(int32_t)(intptr_t)local_8] + 0x10);
                                    do {
                                        if (*(int32_t*)(uintptr_t)
                                            (local_38[2] + ((int32_t)(intptr_t)local_24 +
                                                            (int32_t)(intptr_t)puVar12) * 4) ==
                                            *piVar11) {
                                            local_14 = 1;
                                            goto LAB_00698978;
                                        }
                                        local_1c = (uint32_t*)((int32_t)(intptr_t)local_1c + 1);
                                        piVar11 = piVar11 + 1;
                                    } while (local_1c < puVar13);
                                }
                                puVar12 = (uint32_t*)((int32_t)(intptr_t)puVar12 + 1);
                            } while (puVar12 < local_20);
                        }
LAB_00698978:
                        local_8 = (uint32_t*)((int32_t)(intptr_t)local_8 + 1);
                    } while (local_8 < local_c);
                }
                local_10 = local_10 + 1;
                local_24 = (uint32_t*)((int32_t)(intptr_t)local_24 + (int32_t)(intptr_t)local_20);
            } while (local_10 < 3);
            if (local_14 == 0) {
                if (local_2c != (uint32_t*)0) goto LAB_00698b17;
                local_1c = (uint32_t*)0;
                if (local_c != (uint32_t*)0) {
                    do {
                        local_50 = *(uint32_t**)(local_b0[(int32_t)(intptr_t)local_1c] + 0xc);
                        local_8 = (uint32_t*)0;
                        if (local_50 != (uint32_t*)0) {
                            do {
                                if (*(uint32_t*)(selfBase + 0xc) != 0) {
                                    local_34 = *(uint32_t**)(selfBase + 0x18);
                                    local_24 = *(uint32_t**)(selfBase + 0xc);
                                    do {
                                        puVar12 = (uint32_t*)*local_34;
                                        if ((puVar12 != (uint32_t*)0) && (*puVar12 != 0)) {
                                            uVar17 = puVar12[1];
                                            local_3c = (uint32_t*)0;
                                            if (uVar17 != 0) {
                                                iVar8 = *(int32_t*)(
                                                    *(int32_t*)(local_b0[(int32_t)(intptr_t)local_1c] + 0x10) +
                                                    (int32_t)(intptr_t)local_8 * 4);
                                                piVar11 = (int32_t*)puVar12[2];
                                                do {
                                                    if ((*piVar11 == iVar8) ||
                                                        (*(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) + *piVar11 * 4) + 0x38) == iVar8)) {
                                                        local_3c = (uint32_t*)1;
                                                    }
                                                    piVar11 = piVar11 + 1;
                                                    uVar17 = uVar17 - 1;
                                                } while (uVar17 != 0);
                                            }
                                            if (puVar12 == local_38) {
                                                puVar13 = (uint32_t*)0;
                                            }
                                            else {
                                                puVar13 = local_3c;
                                            }
                                            if (puVar13 != (uint32_t*)0) {
                                                puVar5 = (uint32_t*)0;
                                                do {
                                                    if (puVar12 == (uint32_t*)local_b0[(int32_t)(intptr_t)puVar5]) {
                                                        puVar13 = (uint32_t*)0;
                                                    }
                                                    puVar5 = (uint32_t*)((int32_t)(intptr_t)puVar5 + 1);
                                                } while (puVar5 < local_c);
                                                if (puVar13 != (uint32_t*)0) {
                                                    local_14 = 1;
                                                }
                                            }
                                        }
                                        local_34 = local_34 + 1;
                                        local_24 = (uint32_t*)((int32_t)(intptr_t)local_24 - 1);
                                    } while (local_24 != (uint32_t*)0);
                                }
                                local_8 = (uint32_t*)((int32_t)(intptr_t)local_8 + 1);
                            } while (local_8 < local_50);
                        }
                        local_1c = (uint32_t*)((int32_t)(intptr_t)local_1c + 1);
                    } while (local_1c < local_c);
                }
                local_8 = (uint32_t*)0;
                do {
                    uVar17 = local_230[(int32_t)(intptr_t)local_8];
                    if ((uVar17 != 0xffffffff) &&
                        (puVar12 = (uint32_t*)0, local_c != (uint32_t*)0)) {
                        do {
                            iVar8 = *(int32_t*)(local_b0[(int32_t)(intptr_t)puVar12] + 0xc);
                            if (iVar8 != 0) {
                                puVar13 = *(uint32_t**)(local_b0[(int32_t)(intptr_t)puVar12] + 0x10);
                                do {
                                    if ((uVar17 == *puVar13) ||
                                        (*(uint32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) + uVar17 * 4) + 0x38) == *puVar13)) {
                                        local_14 = 1;
                                    }
                                    puVar13 = puVar13 + 1;
                                    iVar8 = iVar8 + -1;
                                } while (iVar8 != 0);
                            }
                            puVar12 = (uint32_t*)((int32_t)(intptr_t)puVar12 + 1);
                        } while (puVar12 < local_c);
                    }
                    local_8 = (uint32_t*)((int32_t)(intptr_t)local_8 + 1);
                } while (local_8 < (uint32_t*)0x28);
                if (local_14 == 0) goto LAB_00698b17;
            }
            local_28 = (uint32_t*)((int32_t)(intptr_t)local_28 + 1);
        } while (local_28 == (uint32_t*)0);
        if (local_14 != 0) goto code_r0x00698b08;
LAB_00698b17:
        puVar12 = local_b0;
        ppuVar15 = local_f0;
        for (uVar17 = (uint32_t)(uintptr_t)local_c & 0x3fffffff; uVar17 != 0;
             uVar17 = uVar17 - 1) {
            *ppuVar15 = (uint32_t*)*puVar12;
            puVar12 = puVar12 + 1;
            ppuVar15 = ppuVar15 + 1;
        }
        for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
            *(char*)ppuVar15 = (char)*puVar12;
            puVar12 = (uint32_t*)((uint8_t*)puVar12 + 1);
            ppuVar15 = (uint32_t**)((uint8_t*)ppuVar15 + 1);
        }
        local_f0[(int32_t)(intptr_t)puVar14] = local_38;
        local_44 = (uint32_t*)((int32_t)(intptr_t)puVar14 + 1);
        uVar17 = 0;
        do {
            iVar8 = *(int32_t*)((uint8_t*)local_230 + uVar17);
            if ((iVar8 != -1) ||
                (iVar8 = *(int32_t*)((uint8_t*)local_2d0 + uVar17), iVar8 != -1)) {
                *(int32_t*)((uint8_t*)auStack_190 + uVar17) = iVar8;
            }
            uVar17 = uVar17 + 4;
        } while (uVar17 < 0xa0);
        local_14 = 0;
LAB_00698b78:
        iVar8 = local_14;
        if (local_14 != 0) goto LAB_00698774;
        local_24 = (uint32_t*)0;
        if (local_30 == (uint32_t*)0) goto LAB_00698f6f;
        while (true) {
            local_8 = (uint32_t*)0;
            local_34 = (uint32_t*)auStack_190[(int32_t)(intptr_t)(local_24 + 1)];
            if (local_34 != (uint32_t*)auStack_190[(int32_t)(intptr_t)(local_24 + 3)]) break;
            local_1c = (uint32_t*)auStack_190[(int32_t)(intptr_t)(local_24 + 2)];
            if (((local_1c != (uint32_t*)auStack_190[(int32_t)(intptr_t)(local_24 + 4)]) ||
                 (puVar14 = (uint32_t*)auStack_190[(int32_t)(intptr_t)(local_24 + 5)],
                  puVar14 != (uint32_t*)auStack_190[(int32_t)(intptr_t)(local_24 + 7)])) ||
                (puVar12 = (uint32_t*)auStack_190[(int32_t)(intptr_t)(local_24 + 6)],
                 puVar12 != (uint32_t*)auStack_190[(int32_t)(intptr_t)(local_24 + 8)])) {
                break;
            }
            iVar8 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) + (int32_t)(intptr_t)puVar14 * 4);
            iVar7 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) + (int32_t)(intptr_t)puVar12 * 4);
            local_3c = *(uint32_t**)(*(int32_t*)(selfBase + 0x10) + *(int32_t*)(iVar8 + 4) * 4);
            local_c = (uint32_t*)0;
            iVar6 = *(int32_t*)(*(int32_t*)(selfBase + 0x10) + *(int32_t*)(iVar7 + 4) * 4);
            if ((((puVar14 == local_1c) && ((*(uint8_t*)(iVar6 + 5) & 1) != 0)) &&
                 (*(double*)(iVar7 + 0x20) == -1.0)) ||
                (((puVar12 == local_1c && ((*(uint8_t*)((uint8_t*)local_3c + 5) & 1) != 0)) &&
                  (*(double*)(iVar8 + 0x20) == -1.0)))) {
                local_c = (uint32_t*)1;
            }
            local_20 = auStack_190 + 8;
            if (local_c == (uint32_t*)0) {
                iVar3 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) + (int32_t)(intptr_t)local_34 * 4);
                puVar14 = *(uint32_t**)((uint8_t*)iVar8 + 0x38);
                if ((((puVar14 == local_34) ||
                      ((puVar14 != (uint32_t*)0xffffffff &&
                        (*(uint32_t**)((uint8_t*)iVar3 + 0x38) == puVar14)))) &&
                     (*(uint32_t*)((uint8_t*)iVar8 + 0x3c) ==
                      (*(uint32_t*)((uint8_t*)iVar3 + 0x3c) ^ 0x80000))) &&
                    (((*(uint8_t*)(iVar6 + 5) & 1) != 0 && (*(double*)(iVar7 + 0x20) == 1.0)))) {
                    local_c = (uint32_t*)1;
                }
                puVar14 = *(uint32_t**)((uint8_t*)iVar7 + 0x38);
                if (((puVar14 == local_34) ||
                     ((puVar14 != (uint32_t*)0xffffffff &&
                       (*(uint32_t**)((uint8_t*)iVar3 + 0x38) == puVar14)))) &&
                    ((*(uint32_t*)((uint8_t*)iVar7 + 0x3c) ==
                      (*(uint32_t*)((uint8_t*)iVar3 + 0x3c) ^ 0x80000) &&
                     (((*(uint8_t*)((uint8_t*)local_3c + 5) & 1) != 0) &&
                      (*(double*)(iVar8 + 0x20) == 1.0))))) {
                    local_c = (uint32_t*)1;
                }
                local_8 = (uint32_t*)1;
                if (local_c == (uint32_t*)0) {
                    return 1;
                }
                local_20 = auStack_190 + 4;
            }
            iVar8 = *(int32_t*)(selfBase + 0x14);
            iVar7 = *(int32_t*)(iVar8 + auStack_190[(int32_t)(intptr_t)local_24] * 4);
            if (local_8 == (uint32_t*)0) {
                iVar6 = *(int32_t*)(iVar8 + (int32_t)(intptr_t)local_34 * 4);
            }
            else {
                iVar6 = *(int32_t*)(iVar8 + (int32_t)(intptr_t)local_1c * 4);
            }
            if (((((*(uint8_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x10) +
                                        *(int32_t*)(iVar7 + 4) * 4) + 5) & 1) == 0) ||
                  (*(double*)(iVar7 + 0x20) != 0.0)) ||
                 ((*(uint8_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x10) +
                                          *(int32_t*)(iVar6 + 4) * 4) + 5) & 1) == 0)) ||
                (*(double*)(iVar6 + 0x20) != 1.0)) {
                break;
            }
            iVar8 = *(int32_t*)(iVar8 + local_20[(int32_t)(intptr_t)local_24] * 4);
            if (*(int32_t*)(iVar8 + 4) != *(int32_t*)(selfBase + 0x88)) {
                local_4c = 1;
            }
            uVar17 = 0;
            if (local_48 != 0) {
                do {
                    if (*(int32_t*)(iVar8 + 0x48) == local_60[uVar17]) break;
                    uVar17 = uVar17 + 1;
                } while (uVar17 < local_48);
            }
            if ((uVar17 == local_48) && (local_4c == 0)) {
                local_60[local_48] = *(int32_t*)(iVar8 + 0x48);
                local_48 = local_48 + 1;
            }
            local_24 = (uint32_t*)((int32_t)(intptr_t)local_24 + 1);
            if (local_30 <= local_24) goto LAB_00698f6f;
        }
LAB_006990de:
        iVar8 = 1;
    }
    return iVar8;
code_r0x00697846:
    local_2c = (uint32_t*)((int32_t)(intptr_t)local_2c + 1);
    if (local_2c != (uint32_t*)0) goto LAB_006978b4;
    goto LAB_00697504;
code_r0x00697c37:
    local_38 = (uint32_t*)((int32_t)(intptr_t)local_38 + 1);
    if (local_38 != (uint32_t*)0) goto LAB_00697ca7;
    goto LAB_006978ff;
code_r0x0069816a:
    local_2c = (uint32_t*)((int32_t)(intptr_t)local_2c + 1);
    if (local_2c != (uint32_t*)0) goto LAB_006981da;
    goto LAB_00697e32;
code_r0x0069855c:
    local_2c = (uint32_t*)((int32_t)(intptr_t)local_2c + 1);
    if (local_2c != (uint32_t*)0) goto LAB_006985cc;
    goto LAB_00698225;
code_r0x00698b08:
    local_2c = (uint32_t*)((int32_t)(intptr_t)local_2c + 1);
    if (local_2c != (uint32_t*)0) goto LAB_00698b78;
    goto LAB_006987cf;
}

// ---------------------------------------------------------------------------
// Additional tables referenced by the 0x699xxx - 0x69bxxx group.
// ---------------------------------------------------------------------------
extern uint8_t DAT_006f2280[];
extern uint8_t DAT_006f22e0[];
extern uint8_t DAT_006f2340[];
extern uint8_t DAT_006f23c0[];
extern uint8_t DAT_006f2420[];
extern uint8_t DAT_006f2480[];
extern uint8_t DAT_006f24e0[];
extern uint8_t DAT_006f2540[];
extern uint8_t DAT_006f25a0[];
extern uint8_t DAT_006f2600[];
extern uint8_t DAT_006f2680[];
extern uint8_t DAT_006f2700[];
extern uint8_t DAT_006f2760[];
extern uint8_t DAT_006f27c0[];
extern uint8_t DAT_006f28c0[];
extern uint8_t DAT_006f2a20[];
extern uint8_t DAT_006f2bc0[];
extern uint8_t DAT_006f2d60[];
extern uint8_t DAT_006f29a0[];
extern uint8_t DAT_006f2b20[];
extern uint8_t DAT_006f2cc0[];
extern uint8_t DAT_006f2e80[];
extern uint8_t DAT_006f2f40[];
extern uint8_t DAT_006f3000[];
extern uint8_t DAT_006f34c8[];
extern uint8_t DAT_006f1ee0[];
extern uint8_t DAT_006f1f40[];
extern uint8_t DAT_006f1fa0[];
extern uint8_t DAT_006f2000[];
extern uint8_t DAT_006f2060[];
extern uint8_t DAT_006f20c0[];
extern uint8_t DAT_006f2120[];
extern uint8_t DAT_006f2180[];
extern uint8_t DAT_006f2200[];
extern uint8_t DAT_006f1e6c[];

// 0x69927f — observed shape
// Walk the node array, collapse every union-find chain in place while OR-ing
// the chain's flags (node+0x3c) into the head, and release the replaced links.
int32_t FUN_69927f(void* self)
{
    const uintptr_t selfBase = (uintptr_t)self;

    int32_t  iVar1;
    int32_t  iVar2;
    int32_t  iVar3;
    int32_t  iVar4;
    uint32_t uVar5;

    uVar5 = 0;
    if (*(int32_t*)(selfBase + 8) != 0) {
        do {
            iVar1 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) + uVar5 * 4);
            iVar2 = *(int32_t*)(iVar1 + 0x38);
            if (iVar2 != -1) {
                iVar3 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) + iVar2 * 4);
                iVar4 = iVar2;
                while (*(int32_t*)(iVar3 + 0x38) != -1) {
                    *(uint32_t*)(iVar1 + 0x3c) = *(uint32_t*)(iVar1 + 0x3c) | *(uint32_t*)(iVar3 + 0x3c);
                    iVar4 = *(int32_t*)(iVar3 + 0x38);
                    iVar3 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) + iVar4 * 4);
                }
                if (iVar2 != iVar4) {
                    *(int32_t*)(iVar1 + 0x38) = iVar4;
                    FUN_0065d5bd(iVar3);
                }
            }
            uVar5 = uVar5 + 1;
        } while (uVar5 < *(uint32_t*)(selfBase + 8));
    }
    return 0;
}

// 0x6992d0 — observed shape
// A single-output node operation: verify the record's operand group is an
// ordered producer chain for the folded instruction, else rebuild the node and
// fold it into slot self->fc.
int32_t FUN_6992d0(void* self)
{
    const uintptr_t selfBase = (uintptr_t)self;

    uint32_t* puVar1;
    uint32_t* puVar2;
    int32_t   iVar3;
    uint32_t  uVar4;
    bool      bVar5;
    int32_t*  piVar6;
    int32_t   iVar7;
    uint32_t  uVar8;
    int32_t   iVar9;
    uint32_t* puVar10;
    uint32_t* puVar11;
    uint32_t  local_10;
    uint32_t  local_c;
    uint32_t  local_8;

    puVar1 = *(uint32_t**)(selfBase + 0x100);
    uVar8 = *puVar1 & 0xfff00000;
    if (((((uVar8 == 0x50000000) || (uVar8 == 0x10500000)) || (uVar8 == 0x10600000)) ||
         ((uVar8 == 0x10300000 || (uVar8 == 0x10700000)))) && (puVar1[3] == 1)) {
        iVar7 = *(int32_t*)(selfBase + 0x14);
        bVar5 = false;
        iVar9 = *(int32_t*)(iVar7 + *(int32_t*)puVar1[4] * 4);
        if (*(int32_t*)(iVar9 + 0x54) != -1) {
            local_c = 0;
            puVar2 = *(uint32_t**)(*(int32_t*)(selfBase + 0x18) + *(int32_t*)(iVar9 + 0x54) * 4);
            local_10 = puVar2[3];
            if (local_10 != 0) {
                piVar6 = (int32_t*)puVar2[4];
                do {
                    uVar8 = *(uint32_t*)(*(int32_t*)(iVar7 + *piVar6 * 4) + 0x4c);
                    if (local_c < uVar8) {
                        local_c = uVar8;
                    }
                    piVar6 = piVar6 + 1;
                    local_10 = local_10 - 1;
                } while (local_10 != 0);
            }
            iVar3 = *(int32_t*)(iVar7 + *(int32_t*)puVar2[4] * 4);
            if (((*(int32_t*)(iVar3 + 4) == *(int32_t*)(iVar9 + 4)) &&
                 (*(int32_t*)(iVar3 + 0xc) == *(int32_t*)(iVar9 + 0xc))) &&
                ((*(int32_t*)(iVar3 + 8) == *(int32_t*)(iVar9 + 8) &&
                  (*(int32_t*)(iVar9 + 0x54) != *(int32_t*)(iVar9 + 0x58))))) {
                bVar5 = true;
            }
            if ((((local_c <= *(uint32_t*)(selfBase + 0xfc)) &&
                  ((bVar5 || (*(int32_t*)(iVar9 + 0x54) == *(int32_t*)(iVar9 + 0x58))))) &&
                 (((*(uint8_t*)(selfBase + 0x6c) & 1) == 0 ||
                   ((puVar2[3] != 0 &&
                     (*(int32_t*)(*(int32_t*)(iVar7 + *(int32_t*)puVar2[4] * 4) + 4) !=
                      *(int32_t*)(selfBase + 0x84))))))
                && (((*puVar2 & 0xfff00000) == 0x10000000 &&
                     ((*(uint8_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x10) +
                                              *(int32_t*)(iVar3 + 4) * 4) + 4) & 4) == 0)))) {
                uVar8 = 0;
                if (puVar2[1] != 0) {
                    piVar6 = (int32_t*)puVar2[2];
                    do {
                        if (*piVar6 != *(int32_t*)puVar1[4]) {
                            return 1;
                        }
                        uVar8 = uVar8 + 1;
                        piVar6 = piVar6 + 1;
                    } while (uVar8 < puVar2[1]);
                }
                iVar9 = 0;
                if (*(int32_t*)(*(int32_t*)(iVar7 + *(int32_t*)puVar2[2] * 4) + 0x3c) == 0) {
                    iVar7 = FUN_0065d0b4(0x74);
                    if (iVar7 != 0) {
                        iVar9 = FUN_0065cc1a();
                    }
                    if (iVar9 == 0) {
                        return -0x7ff8fff2;
                    }
                    iVar7 = FUN_0065d0ff(**(uint32_t**)(selfBase + 0x100),
                                         (*(uint32_t**)(selfBase + 0x100))[1],
                                         (uint32_t)bVar5 + puVar2[3], 1);
                    if (iVar7 < 0) {
                        FUN_00614343(1);
                        return iVar7;
                    }
                    puVar10 = (uint32_t*)puVar2[4];
                    puVar11 = *(uint32_t**)(iVar9 + 0x10);
                    for (uVar8 = puVar2[3] & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
                        *puVar11 = *puVar10;
                        puVar10 = puVar10 + 1;
                        puVar11 = puVar11 + 1;
                    }
                    for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                        *(uint8_t*)puVar11 = *(uint8_t*)puVar10;
                        puVar10 = (uint32_t*)((uint8_t*)puVar10 + 1);
                        puVar11 = (uint32_t*)((uint8_t*)puVar11 + 1);
                    }
                    if (bVar5) {
                        *(uint32_t*)(*(int32_t*)(iVar9 + 0x10) + puVar2[3] * 4) =
                            **(uint32_t**)(*(int32_t*)(selfBase + 0x100) + 0x10);
                    }
                    uVar8 = *(uint32_t*)(iVar9 + 0xc);
                    local_8 = 0;
                    if (uVar8 != 0) {
                        local_10 = 1;
                        do {
                            local_c = local_10;
                            if (local_10 < uVar8) {
                                do {
                                    iVar7 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                                       *(int32_t*)(*(int32_t*)(iVar9 + 0x10) +
                                                                   local_8 * 4) * 4);
                                    iVar3 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                                       *(int32_t*)(local_c * 4 +
                                                                   *(int32_t*)(iVar9 + 0x10)) * 4);
                                    if (*(uint32_t*)(iVar3 + 0x10) < *(uint32_t*)(iVar7 + 0x10)) {
                                        puVar10 = (uint32_t*)(local_c * 4 + *(int32_t*)(iVar9 + 0x10));
                                        uVar4 = *puVar10;
                                        *puVar10 = *(uint32_t*)(*(int32_t*)(iVar9 + 0x10) + local_8 * 4);
                                        *(uint32_t*)(*(int32_t*)(iVar9 + 0x10) + local_8 * 4) = uVar4;
                                    }
                                    if (*(int32_t*)(iVar7 + 0x10) == *(int32_t*)(iVar3 + 0x10)) {
                                        FUN_006626da(self, *(uint32_t*)(*(int32_t*)(selfBase + 0x100) + 0x3c),
                                                     0x12d6,
                                                     "internal error: multiple write to same output");
                                        FUN_00614343(1);
                                        return -0x7fffbffb;
                                    }
                                    local_c = local_c + 1;
                                } while (local_c < *(uint32_t*)(iVar9 + 0xc));
                            }
                            local_8 = local_8 + 1;
                            uVar8 = *(uint32_t*)(iVar9 + 0xc);
                            local_10 = local_10 + 1;
                        } while (local_8 < uVar8);
                    }
                    puVar10 = *(uint32_t**)(*(int32_t*)(selfBase + 0x100) + 8);
                    puVar11 = *(uint32_t**)(iVar9 + 8);
                    for (uVar8 = *(uint32_t*)(*(int32_t*)(selfBase + 0x100) + 4) & 0x3fffffff;
                         uVar8 != 0; uVar8 = uVar8 - 1) {
                        *puVar11 = *puVar10;
                        puVar10 = puVar10 + 1;
                        puVar11 = puVar11 + 1;
                    }
                    for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                        *(uint8_t*)puVar11 = *(uint8_t*)puVar10;
                        puVar10 = (uint32_t*)((uint8_t*)puVar10 + 1);
                        puVar11 = (uint32_t*)((uint8_t*)puVar11 + 1);
                    }
                    if (*(int32_t*)(*(int32_t*)(selfBase + 0x18) + *(int32_t*)(selfBase + 0xfc) * 4) != 0) {
                        FUN_00614343(1);
                    }
                    *(int32_t*)(*(int32_t*)(selfBase + 0x18) + *(int32_t*)(selfBase + 0xfc) * 4) = iVar9;
                    *puVar2 = 0;
                    return 0;
                }
            }
            return 1;
        }
    }
    return 1;
}

// 0x6995be — observed shape
// Compare node: dispatch over the operand table, then either build a fresh
// 0x736xxxxx compare node from the matched operand pair (both operands
// constant/one-sided) or copy the singleton operand forward.
int32_t FUN_6995be(void* self)
{
    uintptr_t selfBase = (uintptr_t)self;

    int32_t   iVar1;
    int32_t   iVar2;
    uint32_t  uVar3;
    uint32_t  uVar4;
    uint32_t  uVar5;
    uint32_t* puVar6;
    int32_t*  piVar7;
    uint32_t* puVar8;
    int32_t*  piVar9;
    uint8_t   local_114[64];
    int32_t   local_d4[4];
    int32_t   local_c4[4];
    int32_t   local_b4[4];
    int32_t   local_a4[28];
    int32_t   local_34[4];
    int32_t   local_24[5];
    int32_t   local_10;
    int32_t   local_c;
    int32_t   local_8;

    local_10 = 0;
    local_24[0] = 0;
    uVar5 = **(uint32_t**)(selfBase + 0x100) & 0xfffff;
    local_24[1] = 1;
    local_24[2] = 2;
    local_24[3] = 3;
    local_24[4] = (int32_t)(intptr_t)self;
    iVar2 = FUN_00694b7c(*(void**)(selfBase + 0x100), &DAT_006f2280[0], local_114, &local_10,
                         local_d4, local_24, uVar5, 1);
    if (iVar2 == 0) {
        iVar2 = FUN_0065d0b4(0x74);
        if (iVar2 == 0) {
            local_c = 0;
        }
        else {
            local_c = FUN_0065cc1a();
        }
        if (local_c == 0) {
            return -0x7ff8fff2;
        }
        uVar3 = uVar5 | 0x73600000;
    }
    else {
        iVar2 = FUN_00694b7c(*(void**)(selfBase + 0x100), &DAT_006f22e0[0], local_114, &local_10,
                             local_d4, local_24, uVar5, 1);
        if (iVar2 != 0) {
            iVar2 = FUN_00694b7c(*(void**)(selfBase + 0x100), &DAT_006f2340[0], local_114,
                                 &local_10, local_d4, local_24, uVar5, 1);
            if (iVar2 != 0) {
                return iVar2;
            }
            iVar2 = *(int32_t*)(selfBase + 0x14);
            if (*(int32_t*)(*(int32_t*)(iVar2 + local_b4[0] * 4) + 0x3c) == 0x80000) {
                uVar3 = 0;
                if (uVar5 != 0) {
                    piVar7 = local_a4;
                    piVar9 = local_24;
                    for (uVar4 = uVar5; uVar4 != 0; uVar4 = uVar4 - 1) {
                        *piVar9 = *piVar7;
                        piVar7 = piVar7 + 1;
                        piVar9 = piVar9 + 1;
                    }
                    do {
                        local_34[uVar3] = *(int32_t*)(*(int32_t*)(iVar2 + local_b4[uVar3] * 4) + 0x38);
                        uVar3 = uVar3 + 1;
                    } while (uVar3 < uVar5);
LAB_006997ed:
                    selfBase = (uintptr_t)local_24[4];
                }
            }
            else {
                if (*(int32_t*)(*(int32_t*)(iVar2 + local_a4[0] * 4) + 0x3c) != 0x80000) {
                    return 1;
                }
                uVar3 = 0;
                if (uVar5 != 0) {
                    piVar7 = local_b4;
                    piVar9 = local_24;
                    for (uVar4 = uVar5; uVar4 != 0; uVar4 = uVar4 - 1) {
                        *piVar9 = *piVar7;
                        piVar7 = piVar7 + 1;
                        piVar9 = piVar9 + 1;
                    }
                    do {
                        local_34[uVar3] = *(int32_t*)(*(int32_t*)(iVar2 + local_a4[uVar3] * 4) + 0x38);
                        uVar3 = uVar3 + 1;
                    } while (uVar3 < uVar5);
                    goto LAB_006997ed;
                }
            }
            local_c = 0;
            local_10 = 1;
            local_8 = 1;
            if (uVar5 != 0) {
                do {
                    iVar1 = *(int32_t*)(iVar2 + local_d4[local_c] * 4);
                    if ((*(uint8_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x10) +
                                               *(int32_t*)(iVar1 + 4) * 4) + 5) & 1) == 0) {
                        local_8 = 0;
                        local_10 = 0;
                    }
                    if (*(double*)(iVar1 + 0x20) != 0.0) {
                        local_8 = 0;
                    }
                    if (*(double*)(iVar1 + 0x20) != 1.0) {
                        local_10 = 0;
                    }
                    iVar1 = *(int32_t*)(iVar2 + local_c4[local_c] * 4);
                    if ((*(uint8_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x10) +
                                               *(int32_t*)(iVar1 + 4) * 4) + 5) & 1) == 0) {
                        local_8 = 0;
                        local_10 = 0;
                    }
                    if (*(double*)(iVar1 + 0x20) != 1.0) {
                        local_8 = 0;
                    }
                    if (*(double*)(iVar1 + 0x20) != 0.0) {
                        local_10 = 0;
                    }
                    local_c = local_c + 1;
                } while (local_c < (int32_t)uVar5);
                if ((local_8 == 0) && (local_10 == 0)) {
                    return 1;
                }
            }
            iVar2 = FUN_0065d0b4(0x74);
            if (iVar2 == 0) {
                local_c = 0;
            }
            else {
                local_c = FUN_0065cc1a();
            }
            uVar3 = local_c;
            if (local_c == 0) {
                return -0x7ff8fff2;
            }
            if (local_8 == 0) {
                uVar4 = uVar5 | 0x73500000;
            }
            else {
                uVar4 = uVar5 | 0x73600000;
            }
            local_8 = FUN_0065d0ff(uVar4, uVar5 * 2, uVar5, 0);
            if (-1 < local_8) {
                local_8 = FUN_0065cc50(*(void**)(selfBase + 0x100));
                if (local_8 < 0) goto LAB_00699935;
                puVar6 = *(uint32_t**)(*(int32_t*)(selfBase + 0x100) + 0x10);
                puVar8 = *(uint32_t**)(uVar3 + 0x10);
                for (uVar4 = uVar5; uVar4 != 0; uVar4 = uVar4 - 1) {
                    *puVar8 = *puVar6;
                    puVar6 = puVar6 + 1;
                    puVar8 = puVar8 + 1;
                }
                for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
                    *(uint8_t*)puVar8 = *(uint8_t*)puVar6;
                    puVar6 = (uint32_t*)((uint8_t*)puVar6 + 1);
                    puVar8 = (uint32_t*)((uint8_t*)puVar8 + 1);
                }
                piVar7 = local_24;
                piVar9 = *(int32_t**)(uintptr_t)(local_c + 8);
                for (uVar3 = uVar5; uVar3 != 0; uVar3 = uVar3 - 1) {
                    *piVar9 = *piVar7;
                    piVar7 = piVar7 + 1;
                    piVar9 = piVar9 + 1;
                }
                for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
                    *(char*)piVar9 = (char)*piVar7;
                    piVar7 = (int32_t*)((uint8_t*)piVar7 + 1);
                    piVar9 = (int32_t*)((uint8_t*)piVar9 + 1);
                }
                piVar7 = local_34;
                goto LAB_0069997c;
            }
            goto LAB_00699935;
        }
        iVar2 = FUN_0065d0b4(0x74);
        if (iVar2 == 0) {
            local_c = 0;
        }
        else {
            local_c = FUN_0065cc1a();
        }
        if (local_c == 0) {
            return -0x7ff8fff2;
        }
        uVar3 = uVar5 | 0x73500000;
    }
    uVar4 = local_c;
    local_8 = FUN_0065d0ff(uVar3, uVar5 * 2, uVar5, 0);
    if (-1 < local_8) {
        local_8 = FUN_0065cc50(*(void**)(selfBase + 0x100));
        if (-1 < local_8) {
            puVar6 = *(uint32_t**)(*(int32_t*)(selfBase + 0x100) + 0x10);
            puVar8 = *(uint32_t**)(uVar4 + 0x10);
            for (uVar3 = uVar5; uVar3 != 0; uVar3 = uVar3 - 1) {
                *puVar8 = *puVar6;
                puVar6 = puVar6 + 1;
                puVar8 = puVar8 + 1;
            }
            for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
                *(uint8_t*)puVar8 = *(uint8_t*)puVar6;
                puVar6 = (uint32_t*)((uint8_t*)puVar6 + 1);
                puVar8 = (uint32_t*)((uint8_t*)puVar8 + 1);
            }
            piVar7 = local_d4;
            piVar9 = *(int32_t**)(uintptr_t)(local_c + 8);
            for (uVar3 = uVar5; uVar3 != 0; uVar3 = uVar3 - 1) {
                *piVar9 = *piVar7;
                piVar7 = piVar7 + 1;
                piVar9 = piVar9 + 1;
            }
            for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
                *(char*)piVar9 = (char)*piVar7;
                piVar7 = (int32_t*)((uint8_t*)piVar7 + 1);
                piVar9 = (int32_t*)((uint8_t*)piVar9 + 1);
            }
            piVar7 = local_c4;
LAB_0069997c:
            piVar9 = (int32_t*)(*(int32_t*)(local_c + 8) + uVar5 * 4);
            for (; uVar5 != 0; uVar5 = uVar5 - 1) {
                *piVar9 = *piVar7;
                piVar7 = piVar7 + 1;
                piVar9 = piVar9 + 1;
            }
            for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
                *(char*)piVar9 = (char)*piVar7;
                piVar7 = (int32_t*)((uint8_t*)piVar7 + 1);
                piVar9 = (int32_t*)((uint8_t*)piVar9 + 1);
            }
            iVar2 = FUN_0065d35e(local_c);
            FUN_00614343(1);
            return iVar2;
        }
    }
LAB_00699935:
    FUN_00614343(1);
    return local_8;
}

// 0x6999b4 — observed shape
// Two-operand comparison node: classify both operand records (integer and
// float-one/float-zero), reject mixed shapes, then emit a 0x735/0x736 node.
int32_t FUN_6999b4(void* self)
{
    const uintptr_t selfBase = (uintptr_t)self;

    int32_t   iVar1;
    uint32_t  uVar2;
    int32_t   iVar3;
    uint32_t  uVar4;
    uint32_t* puVar5;
    uint32_t* puVar6;
    uint8_t   local_10c[64];
    uint32_t  local_cc[4];
    int32_t   local_bc;
    int32_t   local_ac;
    uint32_t  local_2c;
    uint32_t  local_28;
    uint32_t  local_24;
    uint32_t  local_20;
    int32_t   local_1c;
    uint32_t  local_18;
    uint32_t  local_14;
    int32_t   local_10;
    int32_t   local_c;
    int32_t   local_8;

    local_28 = 1;
    uVar4 = **(uint32_t**)(selfBase + 0x100) & 0xfffff;
    local_c = 0;
    local_2c = 0;
    local_24 = 2;
    local_20 = 3;
    local_1c = (int32_t)(intptr_t)self;
    iVar1 = FUN_00694b7c(*(void**)(selfBase + 0x100), &DAT_006f1ee0[0], local_10c, &local_c,
                         local_cc, &local_2c, uVar4, 1);
    if (iVar1 != 0) {
        return iVar1;
    }
    local_c = 0;
    local_10 = 0;
    local_14 = 0;
    local_8 = 0;
    if (uVar4 != 0) {
        iVar1 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) + local_bc * 4);
        iVar3 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) + local_ac * 4);
        local_18 = *(uint32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x10) +
                                            *(int32_t*)(iVar1 + 4) * 4) + 4) & 0x100;
        do {
            if (local_18 == 0) {
                return 1;
            }
            if ((*(uint8_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x10) +
                                         *(int32_t*)(iVar3 + 4) * 4) + 5) & 1) == 0) {
                return 1;
            }
            if (*(int32_t*)(iVar1 + 8) != -1) {
                return 1;
            }
            if (*(int32_t*)(iVar3 + 8) != -1) {
                return 1;
            }
            if ((*(double*)(iVar1 + 0x20) == 1.0) && (*(double*)(iVar3 + 0x20) == 0.0)) {
                local_c = 1;
            }
            else {
                if (*(double*)(iVar3 + 0x20) != 1.0) {
                    return 1;
                }
                if (*(double*)(iVar1 + 0x20) != 0.0) {
                    return 1;
                }
                local_10 = 1;
            }
            local_8 = local_8 + 1;
        } while (local_8 < (int32_t)uVar4);
        if (local_c != 0) {
            if (local_10 != 0) {
                return 1;
            }
            local_14 = uVar4 | 0x73500000;
        }
        if (local_10 != 0) {
            local_14 = uVar4 | 0x73600000;
        }
    }
    iVar1 = FUN_0065d0b4(0x74);
    if (iVar1 == 0) {
        local_8 = 0;
    }
    else {
        local_8 = FUN_0065cc1a();
    }
    if (local_8 == 0) {
        return -0x7ff8fff2;
    }
    iVar1 = FUN_0065d0ff(local_14, uVar4 * 2, uVar4, 0);
    if ((-1 < iVar1) && (iVar1 = FUN_0065cc50(nullptr), -1 < iVar1)) {
        puVar5 = *(uint32_t**)(*(int32_t*)(selfBase + 0x100) + 0x10);
        puVar6 = *(uint32_t**)(local_8 + 0x10);
        for (uVar2 = uVar4; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar6 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar6 = puVar6 + 1;
        }
        for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
            *(uint8_t*)puVar6 = *(uint8_t*)puVar5;
            puVar5 = (uint32_t*)((uint8_t*)puVar5 + 1);
            puVar6 = (uint32_t*)((uint8_t*)puVar6 + 1);
        }
        puVar5 = local_cc;
        puVar6 = *(uint32_t**)(local_8 + 8);
        for (uVar2 = uVar4; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar6 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar6 = puVar6 + 1;
        }
        for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
            *(uint8_t*)puVar6 = *(uint8_t*)puVar5;
            puVar5 = (uint32_t*)((uint8_t*)puVar5 + 1);
            puVar6 = (uint32_t*)((uint8_t*)puVar6 + 1);
        }
        iVar1 = FUN_0065d9d5(*(uint32_t*)((uint8_t*)(uintptr_t)local_1c + 0x78), 0, 0, 0);
        if (iVar1 == -1) {
            iVar1 = -0x7ff8fff2;
        }
        else {
            if (uVar4 != 0) {
                iVar3 = uVar4 << 2;
                do {
                    *(int32_t*)(iVar3 + *(int32_t*)(local_8 + 8)) = iVar1;
                    iVar3 = iVar3 + 4;
                    uVar4 = uVar4 - 1;
                } while (uVar4 != 0);
            }
            iVar1 = FUN_0065d35e(local_8);
        }
    }
    FUN_00614343(1);
    return iVar1;
}

// 0x699c0e — observed shape
// Emit a new join node for the single operand and link it under the folded
// instruction's index chain.
int32_t FUN_699c0e(void* self)
{
    const uintptr_t selfBase = (uintptr_t)self;

    int32_t  iVar1;
    int32_t  iVar2;
    int32_t  iVar3;

    if ((**(uint32_t**)(selfBase + 0x100) & 0xfffff) == 1) {
        iVar2 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                            *(int32_t*)((*(uint32_t**)(selfBase + 0x100))[2] + 4) * 4);
        if ((((*(uint8_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x10) +
                                       *(int32_t*)(iVar2 + 4) * 4) + 5) & 1) == 0) ||
             (*(int32_t*)(iVar2 + 8) != -1)) || (*(double*)(iVar2 + 0x20) != 0.0)) {
            iVar2 = 1;
        }
        else {
            iVar3 = FUN_0065d9d5(0, 0, 0, 0);
            if (iVar3 == -1) {
                iVar2 = -0x7ff8fff2;
            }
            else {
                iVar1 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) + iVar3 * 4);
                iVar2 = FUN_0065d501();
                if ((-1 < iVar2) && (iVar2 = FUN_0065d5bd(0), -1 < iVar2)) {
                    *(uint32_t*)(iVar1 + 0x3c) = *(uint32_t*)(iVar1 + 0x3c) ^ 0x80000;
                    if (*(int32_t*)(iVar1 + 0x38) == -1) {
                        *(uint32_t*)(iVar1 + 0x38) =
                            **(uint32_t**)(*(int32_t*)(selfBase + 0x100) + 8);
                    }
                    *(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x100) + 8) + 4) = iVar3;
                    iVar2 = 0;
                }
            }
        }
    }
    else {
        iVar2 = 1;
    }
    return iVar2;
}

// 0x699cf5 — observed shape
// Join node: match one of two tables, verify both operands are still plain
// virtual registers, and rewrite the folded instruction's result list.
int32_t FUN_699cf5(void* self)
{
    const uintptr_t selfBase = (uintptr_t)self;

    int32_t  iVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    uint8_t  local_100[16];
    int32_t  aiStack_f0[4];
    int32_t  aiStack_e0[32];
    uint8_t  local_60[64];
    uint32_t local_20;
    uint32_t local_1c;
    uint32_t local_18;
    uint32_t local_14;
    int32_t  local_10;
    uint32_t local_c;
    int32_t  local_8;

    local_8 = 0;
    local_20 = 0;
    local_10 = 0;
    uVar4 = **(uint32_t**)(selfBase + 0x100) & 0xfffff;
    local_1c = 1;
    local_18 = 2;
    local_14 = 3;
    iVar1 = FUN_00694b7c(*(void**)(selfBase + 0x100), &DAT_006f20c0[0], local_60, &local_8,
                         local_100, &local_20, uVar4, 1);
    if (iVar1 == 1) {
        local_10 = 1;
        iVar1 = FUN_00694b7c(*(void**)(selfBase + 0x100), &DAT_006f2120[0], local_60, &local_8,
                             local_100, &local_20, uVar4, 1);
    }
    if (iVar1 == 0) {
        local_c = 0;
        if (uVar4 != 0) {
            local_8 = uVar4 << 2;
            do {
                if ((((aiStack_f0[local_c] != aiStack_e0[local_c]) ||
                      (iVar1 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                           *(int32_t*)(local_8 +
                                                       *(int32_t*)(*(int32_t*)(selfBase + 0x100) + 8)) * 4),
                       (*(uint8_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x10) +
                                               *(int32_t*)(iVar1 + 4) * 4) + 5) & 1) == 0))
                     || (*(double*)(iVar1 + 0x20) != 0.0)) ||
                    (*(int32_t*)(iVar1 + 8) != -1)) {
                    return 1;
                }
                local_c = local_c + 1;
                local_8 = local_8 + 4;
            } while (local_c < uVar4);
        }
        uVar2 = 0;
        if (local_10 == 0) {
            uVar3 = uVar4 | 0x73800000;
        }
        else {
            uVar3 = uVar4 | 0x73700000;
        }
        **(uint32_t**)(selfBase + 0x100) = uVar3;
        if (uVar4 != 0) {
            do {
                *(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x100) + 8) + uVar2 * 4) =
                    aiStack_f0[uVar2];
                uVar2 = uVar2 + 1;
            } while (uVar2 < uVar4);
        }
        iVar1 = 0;
    }
    return iVar1;
}

// 0x699e43 — observed shape
// Merge node: require all four operand ids to be equal, then emit a constant
// node carrying the merged value.
int32_t FUN_699e43(void* self)
{
    const uintptr_t selfBase = (uintptr_t)self;

    uint32_t uVar1;
    int32_t  iVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    uint8_t  local_fc[64];
    int32_t  local_bc[4];
    int32_t  aiStack_ac[4];
    int32_t  aiStack_9c[4];
    int32_t  aiStack_8c[28];
    uint32_t local_1c;
    uint32_t local_18;
    uint32_t local_14;
    uint32_t local_10;
    int32_t  local_c;
    uint32_t local_8;

    local_8 = 0;
    local_1c = 0;
    local_c = 0;
    uVar4 = **(uint32_t**)(selfBase + 0x100) & 0xfffff;
    local_18 = 1;
    local_14 = 2;
    local_10 = 3;
    iVar2 = FUN_00694b7c(*(void**)(selfBase + 0x100), &DAT_006f2180[0], local_fc, &local_8,
                         local_bc, &local_1c, uVar4, 1);
    if (iVar2 == 1) {
        local_c = 1;
        iVar2 = FUN_00694b7c(*(void**)(selfBase + 0x100), &DAT_006f2200[0], local_fc, &local_8,
                             local_bc, &local_1c, uVar4, 1);
    }
    if (iVar2 == 0) {
        local_8 = 0;
        if (uVar4 != 0) {
            do {
                if (((local_bc[local_8] != aiStack_ac[local_8]) ||
                     (aiStack_ac[local_8] != aiStack_9c[local_8])) ||
                    (local_bc[local_8] != aiStack_8c[local_8])) {
                    return 1;
                }
                local_8 = local_8 + 1;
            } while (local_8 < uVar4);
        }
        if (local_c == 0) {
            uVar3 = uVar4 | 0x73800000;
        }
        else {
            uVar3 = uVar4 | 0x73700000;
        }
        **(uint32_t**)(selfBase + 0x100) = uVar3;
        local_c = FUN_0065d9d5(*(uint32_t*)(selfBase + 0x78), 0, 0, 0);
        if (local_c == -1) {
            iVar2 = -0x7ff8fff2;
        }
        else {
            uVar3 = 0;
            if (uVar4 != 0) {
                local_8 = uVar4 << 2;
                do {
                    uVar1 = local_8;
                    local_8 = local_8 + 4;
                    *(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x100) + 8) + uVar3 * 4) =
                        local_bc[uVar3];
                    uVar3 = uVar3 + 1;
                    *(int32_t*)(uVar1 + *(int32_t*)(*(int32_t*)(selfBase + 0x100) + 8)) = local_c;
                } while (uVar3 < uVar4);
            }
            iVar2 = 0;
        }
    }
    return iVar2;
}

// 0x699fa5 — observed shape
// Signed constant node: probe one of four tables, re-emit the operand and
// either negate the value (single operand) or link a sign-flip node.
int32_t FUN_699fa5(void* self)
{
    const uintptr_t selfBase = (uintptr_t)self;

    int32_t   iVar1;
    int32_t*  piVar2;
    uint32_t  uVar3;
    uint8_t   local_100[16];
    uint32_t  auStack_f0[4];
    int32_t   local_e0[32];
    uint8_t   local_60[64];
    uint32_t  local_20;
    uint32_t  local_1c;
    uint32_t  local_18;
    uint32_t  local_14;
    int32_t   local_10;
    int32_t   local_c;
    int32_t   local_8;

    local_8 = 0;
    local_20 = 0;
    local_1c = 1;
    local_18 = 2;
    local_14 = 3;
    if ((**(uint32_t**)(selfBase + 0x100) & 0xfffff) == 1) {
        iVar1 = FUN_00694b7c(*(void**)(selfBase + 0x100), &DAT_006f1f40[0], local_60, &local_8,
                             local_100, &local_20, 1, 1);
        if (((iVar1 == 1) &&
             (iVar1 = FUN_00694b7c(*(void**)(selfBase + 0x100), &DAT_006f1fa0[0], local_60,
                                   &local_8, local_100, &local_20, 1, 1), iVar1 == 1)) &&
            (iVar1 = FUN_00694b7c(*(void**)(selfBase + 0x100), &DAT_006f2000[0], local_60,
                                  &local_8, local_100, &local_20, 1, 1), iVar1 == 1)) {
            iVar1 = FUN_00694b7c(*(void**)(selfBase + 0x100), &DAT_006f2060[0], local_60,
                                 &local_8, local_100, &local_20, 1, 1);
        }
        if (iVar1 == 0) {
            piVar2 = *(int32_t**)(*(int32_t*)(selfBase + 0x100) + 8);
            local_8 = 0;
            do {
                piVar2 = piVar2 + 1;
                iVar1 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) + *piVar2 * 4);
                if ((((*(uint8_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x10) +
                                               *(int32_t*)(iVar1 + 4) * 4) + 5) & 1) == 0) ||
                     (*(double*)(iVar1 + 0x20) != 0.0)) || (*(int32_t*)(iVar1 + 8) != -1)) {
                    return 1;
                }
                local_8 = local_8 + 1;
            } while (local_8 == 0);
            iVar1 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) + local_e0[0] * 4);
            local_8 = 0;
            if ((*(int32_t*)(iVar1 + 8) == -1) &&
                ((*(uint8_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x10) +
                                          *(int32_t*)(iVar1 + 4) * 4) + 5) & 1) != 0)) {
                local_8 = 1;
            }
            uVar3 = 0;
            do {
                *(uint32_t*)(uVar3 + *(int32_t*)(*(int32_t*)(selfBase + 0x100) + 8)) =
                    *(uint32_t*)((uint8_t*)auStack_f0 + uVar3);
                iVar1 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                    *(int32_t*)((uint8_t*)local_e0 + uVar3) * 4);
                local_10 = FUN_0065d9d5(*(uint32_t*)(iVar1 + 4), *(uint32_t*)(iVar1 + 0xc),
                                        *(uint32_t*)(iVar1 + 0x10),
                                        *(uint64_t*)(iVar1 + 0x20));
                if (local_10 == -1) {
                    return -0x7ff8fff2;
                }
                local_c = *(int32_t*)(*(int32_t*)(selfBase + 0x14) + local_10 * 4);
                FUN_0065d501();
                if (local_8 == 0) {
                    if (*(int32_t*)(local_c + 0x38) == -1) {
                        *(uint32_t*)(local_c + 0x38) = *(uint32_t*)((uint8_t*)local_e0 + uVar3);
                    }
                    *(uint32_t*)(local_c + 0x3c) = *(uint32_t*)(local_c + 0x3c) ^ 0x80000;
                }
                else {
                    *(double*)(local_c + 0x20) = *(double*)(local_c + 0x20) * -1.0;
                }
                *(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x100) + 8) + 4 + uVar3) = local_10;
                uVar3 = uVar3 + 4;
            } while (uVar3 < 4);
            iVar1 = 0;
        }
    }
    else {
        iVar1 = 1;
    }
    return iVar1;
}

// 0x69a1bd — observed shape
// Sub-select node: reduce the operand group to one index, resolve through the
// 0x10100000 producer, then emit a 0x746/0x747 node over its own operands.
int32_t FUN_69a1bd(void* self)
{
    uintptr_t selfBase = (uintptr_t)self;

    int32_t   iVar1;
    uint32_t* puVar2;
    int32_t   iVar3;
    uint32_t  uVar4;
    uint32_t  uVar5;
    uint32_t* puVar6;
    int32_t*  piVar7;
    uint32_t* puVar8;
    int32_t*  piVar9;
    uint8_t   local_114[64];
    int32_t   local_d4[4];
    int32_t   local_c4[4];
    int32_t   local_b4[4];
    int32_t   local_a4[28];
    int32_t   local_34[4];
    int32_t   local_24;
    int32_t   local_20[7];

    local_20[5] = 0;
    local_20[0] = 0;
    uVar5 = **(uint32_t**)(selfBase + 0x100) & 0xfffff;
    local_20[1] = 1;
    local_20[2] = 2;
    local_20[3] = 3;
    local_20[4] = (int32_t)uVar5;
    iVar3 = FUN_00694b7c(*(void**)(selfBase + 0x100), &DAT_006f2760[0], local_114, local_20 + 5,
                         local_d4, local_20, uVar5, 1);
    if (iVar3 == 0) {
        iVar3 = FUN_0065d0b4(0x74);
        if (iVar3 == 0) {
            local_20[6] = 0;
        }
        else {
            local_20[6] = FUN_0065cc1a();
        }
        if (local_20[6] == 0) {
            return -0x7ff8fff2;
        }
        uVar4 = uVar5 | 0x74600000;
    }
    else {
        iVar3 = FUN_00694b7c(*(void**)(selfBase + 0x100), &DAT_006f2700[0], local_114,
                             local_20 + 5, local_d4, local_20, uVar5, 1);
        if (iVar3 != 0) {
            iVar3 = FUN_00694b7c(*(void**)(selfBase + 0x100), &DAT_006f27c0[0], local_114,
                                 local_20 + 5, local_d4, local_20, uVar5, 1);
            if (iVar3 != 0) {
                return iVar3;
            }
            iVar3 = *(int32_t*)(selfBase + 0x14);
            iVar1 = *(int32_t*)(iVar3 + local_b4[0] * 4);
            local_20[5] = *(int32_t*)(iVar1 + 0x3c);
            if (local_20[5] == 0x80000) {
                uVar4 = 0;
                if (uVar5 != 0) {
                    piVar7 = local_a4;
                    piVar9 = local_20;
                    for (; uVar5 != 0; uVar5 = uVar5 - 1) {
                        *piVar9 = *piVar7;
                        piVar7 = piVar7 + 1;
                        piVar9 = piVar9 + 1;
                    }
                    do {
                        local_34[uVar4] = *(int32_t*)(*(int32_t*)(iVar3 + local_b4[uVar4] * 4) + 0x38);
                        uVar4 = uVar4 + 1;
                    } while (uVar4 < (uint32_t)local_20[4]);
LAB_0069a401:
                    uVar5 = local_20[4];
                }
            }
            else {
                local_20[6] = *(int32_t*)(iVar3 + local_a4[0] * 4);
                local_24 = *(int32_t*)(local_20[6] + 0x3c);
                if (local_24 == 0x80000) {
                    uVar4 = 0;
                    if (uVar5 != 0) {
                        piVar7 = local_b4;
                        piVar9 = local_20;
                        for (; uVar5 != 0; uVar5 = uVar5 - 1) {
                            *piVar9 = *piVar7;
                            piVar7 = piVar7 + 1;
                            piVar9 = piVar9 + 1;
                        }
                        do {
                            local_34[uVar4] =
                                *(int32_t*)(*(int32_t*)(iVar3 + local_a4[uVar4] * 4) + 0x38);
                            uVar4 = uVar4 + 1;
                        } while (uVar4 < (uint32_t)local_20[4]);
                        goto LAB_0069a401;
                    }
                }
                else {
                    if (uVar5 != 1) {
                        return 1;
                    }
                    iVar3 = *(int32_t*)(iVar1 + 0x48);
                    if (iVar3 == -1) {
LAB_0069a459:
                        if (*(int32_t*)(local_20[6] + 0x48) == -1) {
                            return 1;
                        }
                        puVar2 = *(uint32_t**)(*(int32_t*)(selfBase + 0x18) +
                                              *(int32_t*)(local_20[6] + 0x48) * 4);
                        uVar4 = *puVar2;
                        if ((uVar4 & 0xfff00000) != 0x10100000) {
                            return 1;
                        }
                        if ((uVar4 & 0xfffff) != 1) {
                            return 1;
                        }
                        if (local_24 != 0) {
                            return 1;
                        }
                        local_34[0] = *(int32_t*)puVar2[2];
                        local_a4[0] = local_b4[0];
                    }
                    else {
                        puVar2 = *(uint32_t**)(*(int32_t*)(selfBase + 0x18) + iVar3 * 4);
                        uVar4 = *puVar2;
                        if ((((uVar4 & 0xfff00000) != 0x10100000) || ((uVar4 & 0xfffff) != 1)) ||
                            (local_20[5] != 0)) goto LAB_0069a459;
                        local_34[0] = *(int32_t*)puVar2[2];
                    }
                    local_20[0] = local_a4[0];
                }
            }
            local_20[6] = 0;
            local_20[4] = 1;
            local_20[5] = 1;
            if (uVar5 != 0) {
                do {
                    iVar3 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) + local_d4[local_20[6]] * 4);
                    if ((*(uint32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x10) +
                                                  *(int32_t*)(iVar3 + 4) * 4) + 4) & 0x100) == 0) {
                        local_20[5] = 0;
                        local_20[4] = 0;
                    }
                    if (*(double*)(iVar3 + 0x20) != 1.0) {
                        local_20[5] = 0;
                    }
                    if (*(double*)(iVar3 + 0x20) != 0.0) {
                        local_20[4] = 0;
                    }
                    iVar3 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) + local_c4[local_20[6]] * 4);
                    if ((*(uint32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x10) +
                                                  *(int32_t*)(iVar3 + 4) * 4) + 4) & 0x100) == 0) {
                        local_20[5] = 0;
                        local_20[4] = 0;
                    }
                    if (*(double*)(iVar3 + 0x20) != 0.0) {
                        local_20[5] = 0;
                    }
                    if (*(double*)(iVar3 + 0x20) != 1.0) {
                        local_20[4] = 0;
                    }
                    local_20[6] = local_20[6] + 1;
                } while ((uint32_t)local_20[6] < uVar5);
                if ((local_20[5] == 0) && (local_20[4] == 0)) {
                    return 1;
                }
            }
            iVar3 = FUN_0065d0b4(0x74);
            if (iVar3 == 0) {
                local_20[6] = 0;
            }
            else {
                local_20[6] = FUN_0065cc1a();
            }
            iVar3 = local_20[6];
            if (local_20[6] == 0) {
                return -0x7ff8fff2;
            }
            if (local_20[5] == 0) {
                uVar4 = uVar5 & 0xfffff | 0x74700000;
            }
            else {
                uVar4 = uVar5 & 0xfffff | 0x74600000;
            }
            local_20[5] = FUN_0065d0ff(uVar4, uVar5 * 2, uVar5, 0);
            if (-1 < local_20[5]) {
                local_20[5] = FUN_0065cc50(*(void**)(selfBase + 0x100));
                if (local_20[5] < 0) goto LAB_0069a5f1;
                puVar6 = *(uint32_t**)(*(int32_t*)(selfBase + 0x100) + 0x10);
                puVar8 = *(uint32_t**)(iVar3 + 0x10);
                for (uVar4 = uVar5 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
                    *puVar8 = *puVar6;
                    puVar6 = puVar6 + 1;
                    puVar8 = puVar8 + 1;
                }
                for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
                    *(uint8_t*)puVar8 = *(uint8_t*)puVar6;
                    puVar6 = (uint32_t*)((uint8_t*)puVar6 + 1);
                    puVar8 = (uint32_t*)((uint8_t*)puVar8 + 1);
                }
                piVar7 = local_20;
                piVar9 = *(int32_t**)(uintptr_t)(local_20[6] + 8);
                for (uVar4 = uVar5 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
                    *piVar9 = *piVar7;
                    piVar7 = piVar7 + 1;
                    piVar9 = piVar9 + 1;
                }
                for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
                    *(char*)piVar9 = (char)*piVar7;
                    piVar7 = (int32_t*)((uint8_t*)piVar7 + 1);
                    piVar9 = (int32_t*)((uint8_t*)piVar9 + 1);
                }
                piVar7 = local_34;
                goto LAB_0069a63a;
            }
            goto LAB_0069a5f1;
        }
        iVar3 = FUN_0065d0b4(0x74);
        if (iVar3 == 0) {
            local_20[6] = 0;
        }
        else {
            local_20[6] = FUN_0065cc1a();
        }
        if (local_20[6] == 0) {
            return -0x7ff8fff2;
        }
        uVar4 = uVar5 | 0x74700000;
    }
    iVar3 = local_20[6];
    local_20[5] = FUN_0065d0ff(uVar4, uVar5 * 2, uVar5, 0);
    if (-1 < local_20[5]) {
        local_20[5] = FUN_0065cc50(*(void**)(selfBase + 0x100));
        if (-1 < local_20[5]) {
            puVar6 = *(uint32_t**)(*(int32_t*)(selfBase + 0x100) + 0x10);
            puVar8 = *(uint32_t**)(iVar3 + 0x10);
            for (uVar4 = uVar5; uVar4 != 0; uVar4 = uVar4 - 1) {
                *puVar8 = *puVar6;
                puVar6 = puVar6 + 1;
                puVar8 = puVar8 + 1;
            }
            for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
                *(uint8_t*)puVar8 = *(uint8_t*)puVar6;
                puVar6 = (uint32_t*)((uint8_t*)puVar6 + 1);
                puVar8 = (uint32_t*)((uint8_t*)puVar8 + 1);
            }
            piVar7 = local_d4;
            piVar9 = *(int32_t**)(uintptr_t)(local_20[6] + 8);
            for (uVar4 = uVar5; uVar4 != 0; uVar4 = uVar4 - 1) {
                *piVar9 = *piVar7;
                piVar7 = piVar7 + 1;
                piVar9 = piVar9 + 1;
            }
            for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
                *(char*)piVar9 = (char)*piVar7;
                piVar7 = (int32_t*)((uint8_t*)piVar7 + 1);
                piVar9 = (int32_t*)((uint8_t*)piVar9 + 1);
            }
            piVar7 = local_c4;
LAB_0069a63a:
            piVar9 = (int32_t*)(*(int32_t*)(local_20[6] + 8) + uVar5 * 4);
            for (uVar4 = uVar5 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
                *piVar9 = *piVar7;
                piVar7 = piVar7 + 1;
                piVar9 = piVar9 + 1;
            }
            for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
                *(char*)piVar9 = (char)*piVar7;
                piVar7 = (int32_t*)((uint8_t*)piVar7 + 1);
                piVar9 = (int32_t*)((uint8_t*)piVar9 + 1);
            }
            iVar3 = FUN_0065d35e(local_20[6]);
            FUN_00614343(1);
            return iVar3;
        }
    }
LAB_0069a5f1:
    FUN_00614343(1);
    return local_20[5];
}

// 0x69a674 — observed shape
// Rebuild every 0x20900000 record: for each operand emit a compare node and
// thread the result through the record's index chain, creating shared
// temporaries where several operands feed the same value.
int32_t FUN_69a674(void* self)
{
    uintptr_t selfBase = (uintptr_t)self;

    int32_t   iVar1;
    int32_t   iVar2;
    uint32_t* puVar3;
    int32_t   iVar4;
    int32_t   iVar5;
    uint32_t  uVar6;
    int32_t   iVar7;
    uint32_t* puVar8;
    int32_t*  piVar9;
    uint8_t   local_21c[64];
    uint8_t   local_1dc[64];
    int32_t   local_19c[4];
    int32_t   local_18c;
    int32_t   local_fc[4];
    int32_t   local_ec;
    int32_t   local_dc;
    uint32_t  local_5c;
    uint32_t  local_58;
    uint32_t  local_54;
    uint32_t  local_50;
    uint32_t  local_4c;
    uint32_t  local_48;
    uint32_t  local_44;
    uint32_t  local_40;
    uint32_t  local_3c;
    uint32_t  local_38;
    uint32_t  local_34;
    int32_t   local_30;
    int32_t   local_2c;
    int32_t   local_28;
    uint32_t* local_24;
    int32_t   local_20;
    int32_t   local_1c;
    int32_t*  local_18;
    int32_t   local_14;
    uint32_t  local_10;
    uint32_t  local_c;
    uint32_t  local_8;

    local_58 = 0xffffffff;
    local_54 = 0xffffffff;
    local_50 = 0xffffffff;
    local_48 = 0xffffffff;
    local_44 = 0xffffffff;
    local_40 = 0xffffffff;
    local_3c = **(uint32_t**)(selfBase + 0x100) & 0xfffff;
    local_5c = 0;
    local_4c = 0;
    if ((**(uint32_t**)(selfBase + 0x100) & 0xfff00000) == 0x20900000) {
        iVar4 = FUN_0065d0b4(0x74);
        if (iVar4 == 0) {
            local_24 = (uint32_t*)0;
        }
        else {
            local_24 = (uint32_t*)(uintptr_t)FUN_0065cc1a();
        }
        puVar8 = local_24;
        if (local_24 == (uint32_t*)0) {
LAB_0069a6e9:
            iVar4 = -0x7ff8fff2;
        }
        else {
            iVar4 = FUN_0065d35e((int32_t)(intptr_t)local_24);
            if (iVar4 < 0) {
                FUN_00614343(1);
            }
            else {
                puVar8[3] = 1;
                puVar8[1] = 2;
                *puVar8 = 0x20900001;
                local_38 = 0;
                if (local_3c != 0) {
                    local_2c = local_3c << 2;
                    do {
                        *(uint32_t*)(uintptr_t)puVar8[4] =
                            *(uint32_t*)(local_38 * 4 +
                                         *(int32_t*)(*(int32_t*)(selfBase + 0x100) + 0x10));
                        *(uint32_t*)(uintptr_t)puVar8[2] =
                            *(uint32_t*)(local_38 * 4 +
                                         *(int32_t*)(*(int32_t*)(selfBase + 0x100) + 8));
                        local_10 = 0;
                        *(uint32_t*)((uint8_t*)(uintptr_t)puVar8[2] + 4) =
                            *(uint32_t*)(local_2c +
                                         *(int32_t*)(*(int32_t*)(selfBase + 0x100) + 8));
                        piVar9 = local_fc;
                        for (iVar4 = 0x28; iVar4 != 0; iVar4 = iVar4 + -1) {
                            *piVar9 = -1;
                            piVar9 = piVar9 + 1;
                        }
                        iVar5 = FUN_00694b7c(puVar8, &DAT_006f2f40[0], local_1dc, &local_10,
                                             local_fc, &local_5c, 0x100000001);
                        iVar4 = local_ec;
                        if ((iVar5 == 0) && (local_ec == local_dc)) {
                            local_10 = 0;
                            FUN_00694b7c(puVar8, &DAT_006f3000[0], local_21c, &local_10, local_19c,
                                         &local_4c, 1, 1);
                            if (local_19c[0] == local_fc[0]) {
                                local_14 = local_18c;
                            }
                            else {
                                local_14 = local_fc[0];
                            }
                            if ((((local_14 != -1) &&
                                  (*(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                                           *(int32_t*)puVar8[4] * 4) + 0x14) != -1)) &&
                                 (iVar5 = *(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                                                  *(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) + *(int32_t*)puVar8[4] * 4) + 0x14) * 4) + 0x48),
                                  iVar5 != -1)) &&
                                (local_18 = *(int32_t**)(*(int32_t*)(selfBase + 0x18) + iVar5 * 4),
                                 *local_18 == 0x11100001)) {
                                local_1c = *(int32_t*)(*(int32_t*)(selfBase + 0x14) + local_fc[0] * 4);
                                iVar5 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) + iVar4 * 4);
                                while ((*(int32_t*)(iVar5 + 0x48) != -1 &&
                                        (*(int32_t*)(iVar5 + 8) == -1))) {
                                    puVar3 = *(uint32_t**)(*(int32_t*)(selfBase + 0x18) +
                                                           *(int32_t*)(iVar5 + 0x48) * 4);
                                    if ((*puVar3 & 0xfff00000) != 0x10000000) break;
                                    local_8 = 0;
                                    local_c = *puVar3 & 0xfffff;
                                    if (local_c == 0) break;
                                    piVar9 = (int32_t*)puVar3[4];
                                    while (*piVar9 != iVar4) {
                                        local_8 = local_8 + 1;
                                        piVar9 = piVar9 + 1;
                                        if (local_c <= local_8) goto LAB_0069a8d3;
                                    }
                                    iVar4 = *(int32_t*)(uintptr_t)(puVar3[2] + local_8 * 4);
                                    iVar5 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) + iVar4 * 4);
                                }
LAB_0069a8d3:
                                if ((((*(uint32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x10) +
                                                               *(int32_t*)(local_1c + 4) * 4) + 4) & 0x100) != 0) &&
                                     ((*(uint32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x10) +
                                                               *(int32_t*)(iVar5 + 4) * 4) + 4) & 0x100) != 0)) &&
                                    ((*(double*)(local_1c + 0x20) == 1.0 &&
                                      (*(double*)(iVar5 + 0x20) == 0.0)))) {
                                    iVar4 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) + local_14 * 4);
                                    local_10 = *(uint32_t*)(iVar4 + 0x54);
                                    iVar5 = -1;
                                    local_30 = -1;
                                    local_1c = iVar4;
                                    if (local_10 <= *(uint32_t*)(iVar4 + 0x58)) {
                                        do {
                                            iVar7 = *(int32_t*)(*(int32_t*)(selfBase + 0x18) + local_10 * 4);
                                            local_28 = iVar7;
                                            if ((*(int32_t*)(iVar7 + 0xc) != 0) &&
                                                (local_c = 0, *(int32_t*)(iVar7 + 4) != 0)) {
                                                do {
                                                    iVar4 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                                                       *(int32_t*)(*(int32_t*)(iVar7 + 8) + local_c * 4) * 4);
                                                    iVar1 = *(int32_t*)(iVar4 + 8);
                                                    local_20 = -1;
                                                    if (iVar1 == -1) {
LAB_0069a9e4:
                                                        if (local_20 == local_14) {
                                                            if (local_30 == -1) {
                                                                uVar6 = FUN_0065d97c(&DAT_006f34c8[0], 0x15,
                                                                                     0xffffffff, 4);
                                                                local_30 = FUN_0065d9d5(uVar6, 0, 0, 0);
                                                                *(int32_t*)(iVar4 + 8) = local_30;
                                                            }
                                                            *(int32_t*)(iVar4 + 8) = local_30;
                                                            if (*(int32_t*)(iVar4 + 0x38) != -1) {
                                                                *(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                                                                        *(int32_t*)(iVar4 + 0x38) * 4) + 8) = local_30;
                                                            }
                                                        }
                                                        iVar7 = local_28;
                                                        iVar5 = local_30;
                                                    }
                                                    else {
                                                        iVar2 = *(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) + iVar1 * 4) + 0x48);
                                                        if (iVar2 != -1) {
                                                            puVar3 = *(uint32_t**)(*(int32_t*)(selfBase + 0x18) + iVar2 * 4);
                                                            if ((*puVar3 & 0xfff00000) == 0x10000000) {
                                                                local_8 = 0;
                                                                local_34 = *puVar3 & 0xfffff;
                                                                if (local_34 != 0) {
                                                                    piVar9 = (int32_t*)puVar3[4];
                                                                    do {
                                                                        if (*piVar9 == iVar1) {
                                                                            local_20 = *(int32_t*)(uintptr_t)(puVar3[2] + local_8 * 4);
                                                                            break;
                                                                        }
                                                                        local_8 = local_8 + 1;
                                                                        piVar9 = piVar9 + 1;
                                                                    } while (local_8 < local_34);
                                                                }
                                                            }
                                                            else {
                                                                local_20 = iVar1;
                                                            }
                                                            goto LAB_0069a9e4;
                                                        }
                                                    }
                                                    local_c = local_c + 1;
                                                } while (local_c < *(uint32_t*)(iVar7 + 4));
                                                iVar4 = local_1c;
                                            }
                                            local_10 = local_10 + 1;
                                        } while (local_10 <= *(uint32_t*)(iVar4 + 0x58));
                                        if (iVar5 != -1) {
                                            iVar4 = FUN_0065d0b4(0x74);
                                            if (iVar4 == 0) {
                                                iVar4 = 0;
                                            }
                                            else {
                                                iVar4 = FUN_0065cc1a();
                                            }
                                            if (iVar4 == 0) goto LAB_0069a6e9;
                                            iVar5 = FUN_0065d0ff(0x74100001, 3, 1, 0);
                                            if ((iVar5 < 0) || (iVar5 = FUN_0065cc50(nullptr), iVar5 < 0)) {
                                                FUN_00614343(1);
                                                return iVar5;
                                            }
                                            **(uint32_t**)(iVar4 + 0x10) = *(uint32_t*)local_18[4];
                                            **(uint32_t**)(iVar4 + 8) = *(uint32_t*)local_18[2];
                                            iVar5 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                                               *(int32_t*)local_18[2] * 4);
                                            uVar6 = FUN_0065d9d5(*(uint32_t*)(iVar5 + 4),
                                                                 *(uint32_t*)(iVar5 + 0xc), 2, 0);
                                            *(uint32_t*)(*(int32_t*)(iVar4 + 8) + 4) = uVar6;
                                            uVar6 = FUN_0065d9d5(*(uint32_t*)(iVar5 + 4),
                                                                 *(uint32_t*)(iVar5 + 0xc), 2,
                                                                 0x3ff0000000000000ULL);
                                            *(uint32_t*)(*(int32_t*)(iVar4 + 8) + 8) = uVar6;
                                            iVar4 = FUN_0065d35e(iVar4);
                                            FUN_00614343(1);
                                            if (iVar4 < 0) {
                                                return iVar4;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        local_2c = local_2c + 4;
                        local_38 = local_38 + 1;
                        if (local_3c <= local_38) break;
                        puVar8 = local_24;
                    } while (true);
                }
                iVar4 = 0;
            }
        }
    }
    else {
        iVar4 = 1;
    }
    return iVar4;
}

// 0x69ab4e — observed shape
// Fold one 0x20900000 record: detect the producer chain pattern where a
// 0x74700001 consumer's quantised float input matches self->68, then rewrite
// the operand group in place and rebuild the dependants.
int32_t FUN_69ab4e(void* self)
{
    uintptr_t selfBase = (uintptr_t)self;

    int32_t  iVar1;
    int32_t* piVar2;
    uint32_t uVar3;
    float    fVar4;
    int32_t  iVar5;
    uint32_t uVar6;
    int32_t  iVar7;
    uint32_t uVar8;
    uint32_t* puVar9;
    uint8_t* pbVar10;
    uint32_t* puVar11;
    uint32_t* puVar12;
    int32_t* piVar13;
    uint8_t* puVar14;
    int32_t  local_218[4];
    int32_t  local_208;
    int32_t  local_178[4];
    uint32_t local_168;
    uint32_t local_158;
    uint8_t  local_d8[64];
    int32_t  local_98[16];
    uint32_t local_58;
    uint32_t local_54;
    uint32_t local_50;
    uint32_t local_4c;
    uint32_t local_48;
    uint32_t local_44;
    uint32_t local_40;
    uint32_t local_3c;
    uint32_t* local_38;
    int32_t* local_34;
    uint32_t* local_30;
    uint32_t local_2c;
    uint32_t* local_28;
    uint32_t* local_24;
    uint32_t local_20;
    uint8_t* local_1c;
    uint32_t local_18;
    int32_t  local_14;
    uint32_t local_10;
    int32_t  local_c;
    int32_t* local_8;

    local_44 = 0xffffffff;
    local_40 = 0xffffffff;
    local_3c = 0xffffffff;
    local_54 = 0xffffffff;
    local_50 = 0xffffffff;
    local_4c = 0xffffffff;
    puVar12 = (uint32_t*)0;
    puVar9 = (uint32_t*)(**(uint32_t**)(selfBase + 0x100) & 0xfffff);
    local_48 = 0;
    local_58 = 0;
    if ((**(uint32_t**)(selfBase + 0x100) & 0xfff00000) != 0x20900000) {
        return 1;
    }
    local_38 = puVar9;
    iVar5 = FUN_0065d0b4(0x74);
    if (iVar5 != 0) {
        puVar12 = (uint32_t*)(uintptr_t)FUN_0065cc1a();
    }
    if (puVar12 == (uint32_t*)0) {
        return -0x7ff8fff2;
    }
    local_30 = puVar12;
    local_c = FUN_0065d35e((int32_t)(intptr_t)puVar12);
    if (-1 < local_c) {
        local_24 = (uint32_t*)0;
        puVar12[3] = 1;
        puVar12[1] = 2;
        *puVar12 = 0x20900001;
        if (puVar9 != (uint32_t*)0) {
            local_2c = (int32_t)(intptr_t)local_38 << 2;
LAB_0069ac02:
            puVar12 = local_30;
            *(uint32_t*)(uintptr_t)local_30[4] =
                *(uint32_t*)((int32_t)(intptr_t)local_24 * 4 +
                             *(int32_t*)(*(int32_t*)(selfBase + 0x100) + 0x10));
            *(uint32_t*)(uintptr_t)local_30[2] =
                *(uint32_t*)((int32_t)(intptr_t)local_24 * 4 +
                             *(int32_t*)(*(int32_t*)(selfBase + 0x100) + 8));
            *(uint32_t*)((uint8_t*)(uintptr_t)local_30[2] + 4) =
                *(uint32_t*)(local_2c + *(int32_t*)(*(int32_t*)(selfBase + 0x100) + 8));
            piVar13 = local_178;
            for (iVar5 = 0x28; iVar5 != 0; iVar5 = iVar5 + -1) {
                *piVar13 = -1;
                piVar13 = piVar13 + 1;
            }
            local_8 = (int32_t*)0;
            local_18 = 0;
            local_28 = (uint32_t*)0;
            local_10 = 0;
            local_c = FUN_00694b7c(puVar12, &DAT_006f28c0[0], local_98, &local_8, local_178,
                                   &local_48, 1, 1);
            if (local_c != 0) {
                local_8 = (int32_t*)0;
                local_c = FUN_00694b7c(puVar12, &DAT_006f2a20[0], local_98, &local_8, local_178,
                                       &local_48, 1, 1);
                if (local_c == 0) {
                    local_18 = 1;
                    local_c = 0;
                }
                else {
                    local_8 = (int32_t*)0;
                    local_c = FUN_00694b7c(puVar12, &DAT_006f2bc0[0], local_98, &local_8, local_178,
                                           &local_48, 1, 1);
                    if (local_c == 0) {
                        local_28 = (uint32_t*)1;
                        local_c = 0;
                    }
                    else {
                        local_8 = (int32_t*)0;
                        local_c = FUN_00694b7c(puVar12, &DAT_006f2d60[0], local_98, &local_8,
                                               local_178, &local_48, 1, 1);
                        if (local_c == 0) {
                            local_10 = 1;
                        }
                    }
                }
            }
            if ((local_168 == local_158) && (local_c == 0)) {
                iVar5 = *(int32_t*)(selfBase + 0x14);
                iVar7 = *(int32_t*)(*(int32_t*)(iVar5 + **(int32_t**)(uintptr_t)(local_98[0] + 0x10) * 4) + 0x14);
                if (iVar7 != -1) {
                    piVar13 = *(int32_t**)(*(int32_t*)(selfBase + 0x18) +
                                           *(int32_t*)(*(int32_t*)(iVar5 + iVar7 * 4) + 0x48) * 4);
                    local_8 = (int32_t*)0;
                    if (*piVar13 == 0x11100001) {
                        iVar7 = *(int32_t*)piVar13[4];
                        iVar1 = *(int32_t*)(iVar5 + iVar7 * 4);
                        pbVar10 = *(uint8_t**)(iVar1 + 0x54);
                        local_1c = *(uint8_t**)(iVar1 + 0x58);
                        if (pbVar10 <= local_1c) {
                            local_34 = (int32_t*)(*(int32_t*)(selfBase + 0x18) +
                                                  (int32_t)(intptr_t)pbVar10 * 4);
                            do {
                                piVar13 = (int32_t*)*local_34;
                                if ((*(int32_t*)(*(int32_t*)(iVar5 + *(int32_t*)piVar13[4] * 4) +
                                                 0x14) == iVar7) &&
                                    (*piVar13 == 0x74700001)) {
                                    if (local_8 != (int32_t*)0) {
                                        FUN_006626da();
                                        return -0x7fffbffb;
                                    }
                                    local_8 = piVar13;
                                }
                                piVar13 = local_8;
                                pbVar10 = pbVar10 + 1;
                                local_34 = local_34 + 1;
                            } while (pbVar10 <= local_1c);
                            if (local_8 != (int32_t*)0) {
                                local_14 = 0;
                                if (local_10 == 0) {
                                    if (local_28 == (uint32_t*)0) {
                                        if (local_18 == 0) {
                                            puVar12 = &local_58;
                                            puVar14 = &DAT_006f29a0[0];
                                        }
                                        else {
                                            puVar12 = &local_48;
                                            puVar14 = &DAT_006f2b20[0];
                                        }
                                    }
                                    else {
                                        puVar12 = &local_48;
                                        puVar14 = &DAT_006f2cc0[0];
                                    }
                                }
                                else {
                                    puVar12 = &local_48;
                                    puVar14 = &DAT_006f2e80[0];
                                }
                                local_c = FUN_00694b7c(local_30, puVar14, local_d8, &local_14,
                                                       local_218, puVar12, 1, 1);
                                iVar5 = local_178[0];
                                if (local_218[0] == local_178[0]) {
                                    iVar5 = local_208;
                                }
                                if (((iVar5 != -1) && (piVar2 = (int32_t*)piVar13[2],
                                                       *piVar2 == iVar5)) &&
                                    (iVar5 = *(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                                                     *(int32_t*)piVar13[4] * 4) + 0x14),
                                     iVar5 != -1)) {
                                    local_34 = *(int32_t**)(*(int32_t*)(selfBase + 0x18) +
                                                            *(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) + iVar5 * 4) + 0x48) * 4);
                                    iVar5 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                                        *(int32_t*)local_34[2] * 4);
                                    if ((*local_34 == 0x11100001) &&
                                        ((*(uint8_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x10) +
                                                                  *(int32_t*)(iVar5 + 4) * 4) + 5) & 1) != 0)) {
                                        fVar4 = (float)*(int32_t*)(selfBase + 0x68);
                                        if (*(int32_t*)(selfBase + 0x68) < 0) {
                                            fVar4 = fVar4 + 4.2949673e+09f;
                                        }
                                        if ((float)*(double*)(iVar5 + 0x20) == fVar4) {
                                            iVar5 = *(int32_t*)(selfBase + 0x14);
                                            local_1c = *(uint8_t**)(iVar5 + piVar2[1] * 4);
                                            local_14 = *(int32_t*)(iVar5 + local_178[0] * 4);
                                            iVar7 = *(int32_t*)(iVar5 + local_168 * 4);
                                            iVar5 = *(int32_t*)(iVar7 + 0x48);
                                            local_10 = local_168;
                                            if (iVar5 != -1) {
                                                while ((*(int32_t*)(iVar7 + 8) == -1 &&
                                                        (puVar9 = *(uint32_t**)(*(int32_t*)(selfBase + 0x18) + iVar5 * 4),
                                                         (*puVar9 & 0xfff00000) == 0x10000000))) {
                                                    local_20 = 0;
                                                    local_18 = *puVar9 & 0xfffff;
                                                    if (local_18 == 0) break;
                                                    puVar11 = (uint32_t*)puVar9[4];
                                                    while (*puVar11 != local_10) {
                                                        local_20 = local_20 + 1;
                                                        puVar11 = puVar11 + 1;
                                                        local_28 = puVar11;
                                                        if (local_18 <= local_20) goto LAB_0069afae;
                                                    }
                                                    local_10 = *(uint32_t*)(uintptr_t)(puVar9[2] + local_20 * 4);
                                                    iVar7 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) + local_10 * 4);
                                                    iVar5 = *(int32_t*)(iVar7 + 0x48);
                                                    if (iVar5 == -1) break;
                                                }
                                            }
LAB_0069afae:
                                            iVar5 = *(int32_t*)(selfBase + 0x10);
                                            if ((((((*(uint8_t*)(*(int32_t*)(iVar5 + *(int32_t*)(local_14 + 4) * 4) + 5) & 1) != 0) &&
                                                   ((*(uint8_t*)(*(int32_t*)(iVar5 + *(int32_t*)(iVar7 + 4) * 4) + 5) & 1) != 0)) &&
                                                  (*(double*)(local_14 + 0x20) == 1.0)) &&
                                                 ((*(double*)(iVar7 + 0x20) == 0.0 &&
                                                   ((*(uint8_t*)(*(int32_t*)(iVar5 + *(int32_t*)(local_1c + 4) * 4) + 5) & 2) != 0)))) &&
                                                (((*local_1c & 2) != 0 &&
                                                  ((*(int32_t*)(local_1c + 0x10) == 0 &&
                                                    (*(int32_t*)(local_1c + 8) == -1)))))) {
                                                local_18 = 0xffffffff;
                                                *(uint32_t*)(uintptr_t)local_34[2] =
                                                    *(uint32_t*)(local_8[2] + 4);
                                                *local_8 = 0;
                                                local_14 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                                                      *(int32_t*)local_34[4] * 4);
                                                local_1c = *(uint8_t**)(local_14 + 0x54);
                                                if (*(uint8_t**)(local_14 + 0x58) < local_1c) goto LAB_0069b2c9;
                                                do {
                                                    uVar8 = *(uint32_t*)(*(int32_t*)(selfBase + 0x18) +
                                                                         (int32_t)(intptr_t)local_1c * 4);
                                                    local_20 = uVar8;
                                                    if (((*(int32_t*)(uVar8 + 0xc) != 0) &&
                                                         (*(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                                                                 **(int32_t**)(uVar8 + 0x10) * 4) + 0x14) ==
                                                          *(int32_t*)local_8[4])) &&
                                                        (local_2c = 0, *(int32_t*)(uVar8 + 4) != 0)) {
                                                        do {
                                                            iVar5 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                                                                *(int32_t*)(*(int32_t*)(uVar8 + 8) + local_2c * 4) * 4);
                                                            uVar3 = *(uint32_t*)(iVar5 + 8);
                                                            local_10 = 0xffffffff;
                                                            if (uVar3 == 0xffffffff) {
LAB_0069b137:
                                                                if (local_10 == *(uint32_t*)local_8[2]) {
                                                                    if (local_18 == 0xffffffff) {
                                                                        uVar6 = FUN_0065d97c(&DAT_006f34c8[0], 0x15,
                                                                                             0xffffffff, 4);
                                                                        local_18 = FUN_0065d9d5(uVar6, 0, 0, 0);
                                                                        *(uint32_t*)(iVar5 + 8) = local_18;
                                                                    }
                                                                    *(uint32_t*)(iVar5 + 8) = local_18;
                                                                    if (*(int32_t*)(iVar5 + 0x38) != -1) {
                                                                        *(uint32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                                                                                *(int32_t*)(iVar5 + 0x38) * 4) + 8) = local_18;
                                                                    }
                                                                }
                                                            }
                                                            else {
                                                                iVar7 = *(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) + uVar3 * 4) + 0x48);
                                                                if (iVar7 != -1) {
                                                                    puVar9 = *(uint32_t**)(*(int32_t*)(selfBase + 0x18) + iVar7 * 4);
                                                                    if ((*puVar9 & 0xfff00000) == 0x10000000) {
                                                                        local_24 = (uint32_t*)0;
                                                                        local_28 = (uint32_t*)(*puVar9 & 0xfffff);
                                                                        if (local_28 != (uint32_t*)0) {
                                                                            puVar11 = (uint32_t*)puVar9[4];
                                                                            do {
                                                                                if (*puVar11 == uVar3) {
                                                                                    local_10 = *(uint32_t*)(uintptr_t)(puVar9[2] + (int32_t)(intptr_t)local_24 * 4);
                                                                                    break;
                                                                                }
                                                                                local_24 = (uint32_t*)((int32_t)(intptr_t)local_24 + 1);
                                                                                puVar11 = puVar11 + 1;
                                                                            } while (local_24 < local_28);
                                                                        }
                                                                    }
                                                                    else {
                                                                        local_10 = uVar3;
                                                                    }
                                                                    uVar8 = local_20;
                                                                    goto LAB_0069b137;
                                                                }
                                                            }
                                                            local_2c = local_2c + 1;
                                                        } while (local_2c < *(uint32_t*)(uVar8 + 4));
                                                    }
                                                    local_1c = local_1c + 1;
                                                } while (local_1c <= *(uint8_t**)(local_14 + 0x58));
                                                if (local_18 != 0xffffffff) {
                                                    iVar5 = FUN_0065d9d5(0, 0, 0, 0);
                                                    iVar7 = FUN_0065d9d5(0, 0, 0, 0);
                                                    if ((iVar5 == -1) || (iVar7 == -1)) {
                                                        return -0x7ff8fff2;
                                                    }
                                                    iVar1 = *(int32_t*)(selfBase + 0x14);
                                                    local_38 = *(uint32_t**)(iVar1 + *(int32_t*)local_34[2] * 4);
                                                    iVar5 = *(int32_t*)(iVar1 + iVar5 * 4);
                                                    iVar7 = *(int32_t*)(iVar1 + iVar7 * 4);
                                                    FUN_0065d501();
                                                    FUN_0065d501();
                                                    *(uint32_t*)(iVar5 + 0x10) = 1;
                                                    *(uint32_t*)(iVar7 + 0x10) = 2;
                                                    iVar5 = FUN_0065d0b4(0x74);
                                                    if (iVar5 == 0) {
                                                        iVar5 = 0;
                                                    }
                                                    else {
                                                        iVar5 = FUN_0065cc1a();
                                                    }
                                                    if (iVar5 == 0) {
                                                        return -0x7ff8fff2;
                                                    }
                                                    iVar7 = FUN_0065d0ff(0x74100001, 3, 1, 0);
                                                    piVar13 = local_34;
                                                    if (iVar7 < 0) {
                                                        FUN_00614343(1);
                                                        return iVar7;
                                                    }
                                                    local_c = FUN_0065cc50(*(void**)(uintptr_t)(iVar5 + 0x10));
                                                    if (local_c < 0) goto LAB_0069b35d;
                                                    **(uint32_t**)(iVar5 + 0x10) = *(uint32_t*)piVar13[4];
                                                    **(uint32_t**)(iVar5 + 8) = *(uint32_t*)piVar13[2];
                                                    *(uint32_t*)(*(int32_t*)(iVar5 + 8) + 4) = *(uint32_t*)piVar13[2];
                                                    *(uint32_t*)(*(int32_t*)(iVar5 + 8) + 8) = *(uint32_t*)piVar13[2];
                                                    local_c = FUN_0065d35e(iVar5);
                                                    FUN_00614343(1);
                                                    if (local_c < 0) {
                                                        return local_c;
                                                    }
                                                }
LAB_0069b2c9:
                                                local_10 = *(uint32_t*)(local_14 + 0x54);
                                                if (local_10 <= *(uint32_t*)(local_14 + 0x58)) {
                                                    do {
                                                        puVar9 = *(uint32_t**)(*(int32_t*)(selfBase + 0x18) + local_10 * 4);
                                                        if (((*puVar9 & 0xfff00000) == 0x20800000) &&
                                                            (*(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                                                                     *(int32_t*)puVar9[2] * 4) + 0x14) ==
                                                             *(int32_t*)local_8[4])) {
                                                            uVar8 = *puVar9 & 0xfffff;
                                                            *puVar9 = uVar8 | 0x10000000;
                                                            puVar9[3] = uVar8;
                                                            puVar9[1] = uVar8;
                                                        }
                                                        local_10 = local_10 + 1;
                                                    } while (local_10 <= *(uint32_t*)(local_14 + 0x58));
                                                }
                                                uVar8 = 0;
                                                if (*(int32_t*)(selfBase + 8) != 0) {
                                                    do {
                                                        iVar5 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) + uVar8 * 4);
                                                        if (*(int32_t*)(iVar5 + 0x14) == *(int32_t*)local_8[4]) {
                                                            *(uint32_t*)(iVar5 + 0x14) = *(uint32_t*)local_34[4];
                                                        }
                                                        uVar8 = uVar8 + 1;
                                                    } while (uVar8 < *(uint32_t*)(selfBase + 8));
                                                }
                                                goto LAB_0069b35d;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            local_24 = (uint32_t*)((int32_t)(intptr_t)local_24 + 1);
            local_2c = local_2c + 4;
            if (local_38 <= local_24) goto LAB_0069b35d;
            goto LAB_0069ac02;
        }
    }
LAB_0069b35d:
    FUN_00614343(1);
    return local_c;
}

// 0x69b36c — observed shape
// Select-conversion node: match one of two tables, require both operand
// records to be plain virtual zero registers, and rewrite the record type.
int32_t FUN_69b36c(void* self)
{
    const uintptr_t selfBase = (uintptr_t)self;

    int32_t  iVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    uint8_t  local_100[16];
    int32_t  aiStack_f0[4];
    int32_t  aiStack_e0[32];
    uint8_t  local_60[64];
    uint32_t local_20;
    uint32_t local_1c;
    uint32_t local_18;
    uint32_t local_14;
    int32_t  local_10;
    uint32_t local_c;
    int32_t  local_8;

    local_8 = 0;
    local_20 = 0;
    local_10 = 0;
    uVar4 = **(uint32_t**)(selfBase + 0x100) & 0xfffff;
    local_1c = 1;
    local_18 = 2;
    local_14 = 3;
    iVar1 = FUN_00694b7c(*(void**)(selfBase + 0x100), &DAT_006f2540[0], local_60, &local_8,
                         local_100, &local_20, uVar4, 1);
    if (iVar1 == 1) {
        local_10 = 1;
        iVar1 = FUN_00694b7c(*(void**)(selfBase + 0x100), &DAT_006f25a0[0], local_60, &local_8,
                             local_100, &local_20, uVar4, 1);
    }
    if (iVar1 == 0) {
        local_c = 0;
        if (uVar4 != 0) {
            local_8 = uVar4 << 2;
            do {
                if ((((aiStack_f0[local_c] != aiStack_e0[local_c]) ||
                      (iVar1 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                           *(int32_t*)(local_8 +
                                                       *(int32_t*)(*(int32_t*)(selfBase + 0x100) + 8)) * 4),
                       (*(uint8_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x10) +
                                               *(int32_t*)(iVar1 + 4) * 4) + 5) & 1) == 0))
                     || (*(double*)(iVar1 + 0x20) != 0.0)) ||
                    (*(int32_t*)(iVar1 + 8) != -1)) {
                    return 1;
                }
                local_c = local_c + 1;
                local_8 = local_8 + 4;
            } while (local_c < uVar4);
        }
        uVar2 = 0;
        if (local_10 == 0) {
            uVar3 = uVar4 | 0x74500000;
        }
        else {
            uVar3 = uVar4 | 0x74400000;
        }
        **(uint32_t**)(selfBase + 0x100) = uVar3;
        if (uVar4 != 0) {
            do {
                *(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x100) + 8) + uVar2 * 4) =
                    aiStack_f0[uVar2];
                uVar2 = uVar2 + 1;
            } while (uVar2 < uVar4);
        }
        iVar1 = 0;
    }
    return iVar1;
}

// 0x69b4ba — observed shape
// Merge/constant node: require all four operand ids to agree, then emit the
// merged constant register.
int32_t FUN_69b4ba(void* self)
{
    const uintptr_t selfBase = (uintptr_t)self;

    uint32_t uVar1;
    int32_t  iVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    uint8_t  local_fc[64];
    int32_t  local_bc[4];
    int32_t  aiStack_ac[4];
    int32_t  aiStack_9c[4];
    int32_t  aiStack_8c[28];
    uint32_t local_1c;
    uint32_t local_18;
    uint32_t local_14;
    uint32_t local_10;
    int32_t  local_c;
    uint32_t local_8;

    local_8 = 0;
    local_1c = 0;
    local_c = 0;
    uVar4 = **(uint32_t**)(selfBase + 0x100) & 0xfffff;
    local_18 = 1;
    local_14 = 2;
    local_10 = 3;
    iVar2 = FUN_00694b7c(*(void**)(selfBase + 0x100), &DAT_006f2600[0], local_fc, &local_8,
                         local_bc, &local_1c, uVar4, 1);
    if (iVar2 == 1) {
        local_c = 1;
        iVar2 = FUN_00694b7c(*(void**)(selfBase + 0x100), &DAT_006f2680[0], local_fc, &local_8,
                             local_bc, &local_1c, uVar4, 1);
    }
    if (iVar2 == 0) {
        local_8 = 0;
        if (uVar4 != 0) {
            do {
                if (((local_bc[local_8] != aiStack_ac[local_8]) ||
                     (aiStack_ac[local_8] != aiStack_9c[local_8])) ||
                    (local_bc[local_8] != aiStack_8c[local_8])) {
                    return 1;
                }
                local_8 = local_8 + 1;
            } while (local_8 < uVar4);
        }
        if (local_c == 0) {
            uVar3 = uVar4 | 0x74500000;
        }
        else {
            uVar3 = uVar4 | 0x74400000;
        }
        **(uint32_t**)(selfBase + 0x100) = uVar3;
        local_c = FUN_0065d9d5(*(uint32_t*)(selfBase + 0x78), 0, 0, 0);
        if (local_c == -1) {
            iVar2 = -0x7ff8fff2;
        }
        else {
            uVar3 = 0;
            if (uVar4 != 0) {
                local_8 = uVar4 << 2;
                do {
                    uVar1 = local_8;
                    local_8 = local_8 + 4;
                    *(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x100) + 8) + uVar3 * 4) =
                        local_bc[uVar3];
                    uVar3 = uVar3 + 1;
                    *(int32_t*)(uVar1 + *(int32_t*)(*(int32_t*)(selfBase + 0x100) + 8)) = local_c;
                } while (uVar3 < uVar4);
            }
            iVar2 = 0;
        }
    }
    return iVar2;
}

// 0x69b61c — observed shape
// Sign flip: for the single-operand case probe one of four tables and either
// allocate a copy with the negated value or link a 0x80000-flagged node.
int32_t FUN_69b61c(void* self)
{
    const uintptr_t selfBase = (uintptr_t)self;

    int32_t   iVar1;
    int32_t*  piVar2;
    uint32_t  uVar3;
    uint8_t   local_100[16];
    uint32_t  auStack_f0[4];
    int32_t   local_e0[32];
    uint8_t   local_60[64];
    uint32_t  local_20;
    uint32_t  local_1c;
    uint32_t  local_18;
    uint32_t  local_14;
    int32_t   local_10;
    int32_t   local_c;
    int32_t   local_8;

    local_8 = 0;
    local_20 = 0;
    local_1c = 1;
    local_18 = 2;
    local_14 = 3;
    if ((**(uint32_t**)(selfBase + 0x100) & 0xfffff) == 1) {
        iVar1 = FUN_00694b7c(*(void**)(selfBase + 0x100), &DAT_006f23c0[0], local_60, &local_8,
                             local_100, &local_20, 1, 1);
        if (((iVar1 == 1) &&
             (iVar1 = FUN_00694b7c(*(void**)(selfBase + 0x100), &DAT_006f2420[0], local_60,
                                   &local_8, local_100, &local_20, 1, 1), iVar1 == 1)) &&
            (iVar1 = FUN_00694b7c(*(void**)(selfBase + 0x100), &DAT_006f2480[0], local_60,
                                  &local_8, local_100, &local_20, 1, 1), iVar1 == 1)) {
            iVar1 = FUN_00694b7c(*(void**)(selfBase + 0x100), &DAT_006f24e0[0], local_60,
                                 &local_8, local_100, &local_20, 1, 1);
        }
        if (iVar1 == 0) {
            piVar2 = *(int32_t**)(*(int32_t*)(selfBase + 0x100) + 8);
            local_8 = 0;
            do {
                piVar2 = piVar2 + 1;
                iVar1 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) + *piVar2 * 4);
                if ((((*(uint8_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x10) +
                                               *(int32_t*)(iVar1 + 4) * 4) + 5) & 1) == 0) ||
                     (*(double*)(iVar1 + 0x20) != 0.0)) || (*(int32_t*)(iVar1 + 8) != -1)) {
                    return 1;
                }
                local_8 = local_8 + 1;
            } while (local_8 == 0);
            iVar1 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) + local_e0[0] * 4);
            local_8 = 0;
            if ((*(int32_t*)(iVar1 + 8) == -1) &&
                ((*(uint8_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x10) +
                                          *(int32_t*)(iVar1 + 4) * 4) + 5) & 1) != 0)) {
                local_8 = 1;
            }
            uVar3 = 0;
            do {
                *(uint32_t*)(uVar3 + *(int32_t*)(*(int32_t*)(selfBase + 0x100) + 8)) =
                    *(uint32_t*)((uint8_t*)auStack_f0 + uVar3);
                iVar1 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                    *(int32_t*)((uint8_t*)local_e0 + uVar3) * 4);
                local_10 = FUN_0065d9d5(*(uint32_t*)(iVar1 + 4), *(uint32_t*)(iVar1 + 0xc),
                                        *(uint32_t*)(iVar1 + 0x10),
                                        *(uint64_t*)(iVar1 + 0x20));
                if (local_10 == -1) {
                    return -0x7ff8fff2;
                }
                local_c = *(int32_t*)(*(int32_t*)(selfBase + 0x14) + local_10 * 4);
                FUN_0065d501();
                if (local_8 == 0) {
                    if (*(int32_t*)(local_c + 0x38) == -1) {
                        *(uint32_t*)(local_c + 0x38) = *(uint32_t*)((uint8_t*)local_e0 + uVar3);
                    }
                    *(uint32_t*)(local_c + 0x3c) = *(uint32_t*)(local_c + 0x3c) ^ 0x80000;
                }
                else {
                    *(double*)(local_c + 0x20) = *(double*)(local_c + 0x20) * -1.0;
                }
                *(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x100) + 8) + 4 + uVar3) = local_10;
                uVar3 = uVar3 + 4;
            } while (uVar3 < 4);
            iVar1 = 0;
        }
    }
    else {
        iVar1 = 1;
    }
    return iVar1;
}

// 0x69b834 — observed shape
// Three-output selection: first probe the operand group to build a fresh
// 0x20500000 record, then fold the producers and mark the consumers as
// absorbed; on the retry path merge the produced operand set instead.
int32_t FUN_69b834(void* self)
{
    const uintptr_t selfBase = (uintptr_t)self;

    uint32_t* puVar1;
    int32_t*  piVar2;
    int32_t   iVar3;
    uint32_t  uVar4;
    uint32_t  uVar5;
    uint32_t* puVar6;
    uint32_t  uVar7;
    uint32_t* puVar8;
    int32_t*  piVar9;
    int32_t   local_27c[40];
    int32_t   local_1dc[40];
    int32_t   local_13c[40];
    uint8_t   local_9c[16];
    int32_t   local_8c[16];
    uint32_t  local_4c[5];
    uint32_t  local_38;
    int32_t   local_34;
    uint32_t* local_30;
    uint32_t  local_2c;
    uint32_t  local_28;
    uint32_t* local_24;
    int32_t   local_20;
    uint32_t  local_1c;
    uint32_t  local_18;
    uint32_t  local_14;
    uint32_t  local_10;
    uint32_t  local_c;
    uint32_t  local_8;

    local_4c[0] = 0;
    piVar2 = local_13c;
    for (iVar3 = 0x28; iVar3 != 0; iVar3 = iVar3 + -1) {
        *piVar2 = -1;
        piVar2 = piVar2 + 1;
    }
    local_24 = *(uint32_t**)(selfBase + 0x100);
    local_28 = *local_24 & 0xfffff;
    local_4c[1] = 1;
    local_4c[2] = 2;
    local_4c[3] = 3;
    local_1c = *local_24 & 0xfffff;
    if (((*local_24 & 0xfffff) < local_28) || ((*local_24 & 0xfff00000) != 0x20500000)) {
        local_10 = 1;
LAB_0069bc37:
        if (local_1c < 3) {
            return 1;
        }
        local_18 = 0;
        if (local_1c != 0) {
            piVar2 = *(int32_t**)(*(int32_t*)(selfBase + 0x100) + 0x10);
            do {
                iVar3 = *(int32_t*)(*(int32_t*)(selfBase + 0x14) + *piVar2 * 4);
                if ((*(uint8_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x10) +
                                            *(int32_t*)(iVar3 + 4) * 4) + 4) & 0x20) != 0) {
                    return 1;
                }
                if (*(uint32_t*)(iVar3 + 0x10) != local_18) {
                    return 1;
                }
                local_18 = local_18 + 1;
                piVar2 = piVar2 + 1;
            } while (local_18 < local_1c);
        }
        if (local_10 == 0) {
            uVar5 = 0;
            do {
                iVar3 = local_13c[uVar5];
                if (iVar3 != local_13c[uVar5 + 4]) {
                    return 1;
                }
                if (iVar3 != local_13c[uVar5 + 8]) {
                    return 1;
                }
                if ((*(uint32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) + iVar3 * 4) + 0x10) != uVar5) &&
                    ((*(uint8_t*)(selfBase + 0x6c) & 2) != 0)) {
                    return 1;
                }
                uVar5 = uVar5 + 1;
            } while (uVar5 < 3);
            if ((local_13c[7] != -1) || (local_13c[0xb] != -1)) {
                return 1;
            }
            iVar3 = FUN_0065d0b4(0x74);
            if (iVar3 == 0) {
                local_24 = (uint32_t*)0;
            }
            else {
                local_24 = (uint32_t*)(uintptr_t)FUN_0065cc1a();
            }
            if (local_24 == (uint32_t*)0) {
                return -0x7ff8fff2;
            }
            iVar3 = FUN_0065d0ff(local_1c & 0xfffff | 0x70200000, local_1c, local_1c, 0);
            if ((iVar3 < 0) || (iVar3 = FUN_0065cc50(*(void**)(selfBase + 0x100)), iVar3 < 0)) {
                FUN_00614343(1);
                return iVar3;
            }
            puVar6 = *(uint32_t**)(*(int32_t*)(selfBase + 0x100) + 0x10);
            puVar8 = *(uint32_t**)((uintptr_t)local_24 + 0x10);
            for (uVar5 = local_1c & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
                *puVar8 = *puVar6;
                puVar6 = puVar6 + 1;
                puVar8 = puVar8 + 1;
            }
            for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
                *(uint8_t*)puVar8 = *(uint8_t*)puVar6;
                puVar6 = (uint32_t*)((uint8_t*)puVar6 + 1);
                puVar8 = (uint32_t*)((uint8_t*)puVar8 + 1);
            }
            piVar2 = local_13c;
            piVar9 = *(int32_t**)((uintptr_t)local_24 + 8);
            for (uVar5 = local_1c & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
                *piVar9 = *piVar2;
                piVar2 = piVar2 + 1;
                piVar9 = piVar9 + 1;
            }
            for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
                *(char*)piVar9 = (char)*piVar2;
                piVar2 = (int32_t*)((uint8_t*)piVar2 + 1);
                piVar9 = (int32_t*)((uint8_t*)piVar9 + 1);
            }
            uVar5 = 0;
            if (local_1c != 0) {
                do {
                    if ((*(uint8_t*)(selfBase + 0x6c) & 2) != 0) {
                        puVar1 = *(uint32_t**)(*(int32_t*)(selfBase + 0x14) +
                                               *(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x100) + 8) + uVar5 * 4) * 4);
                        *puVar1 = *puVar1 | 0x80000000;
                        iVar3 = *(int32_t*)(selfBase + 0x14);
                        if (*(int32_t*)(*(int32_t*)(iVar3 + *(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x100) + 8) +
                                                                      uVar5 * 4) * 4) + 0x38) != -1) {
                            puVar1 = *(uint32_t**)(iVar3 + *(int32_t*)(*(int32_t*)(iVar3 +
                                                                                    *(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x100) + 8) + uVar5 * 4) * 4) + 0x38) * 4);
                            *puVar1 = *puVar1 | 0x80000000;
                        }
                    }
                    puVar1 = *(uint32_t**)(*(int32_t*)(selfBase + 0x14) +
                                           *(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x100) + 0x10) + uVar5 * 4) * 4);
                    *puVar1 = *puVar1 | 0x80000000;
                    uVar5 = uVar5 + 1;
                } while (uVar5 < local_1c);
            }
            local_10 = FUN_0065d35e((int32_t)(intptr_t)local_24);
            FUN_00614343(1);
        }
        return local_10;
    }
    local_34 = 0;
    do {
        local_10 = 0;
        do {
            piVar2 = local_1dc;
            for (iVar3 = 0x28; iVar3 != 0; iVar3 = iVar3 + -1) {
                *piVar2 = -1;
                piVar2 = piVar2 + 1;
            }
            piVar2 = local_27c;
            for (iVar3 = 0x28; iVar3 != 0; iVar3 = iVar3 + -1) {
                *piVar2 = -1;
                piVar2 = piVar2 + 1;
            }
            local_2c = 0;
            local_20 = 0;
            local_8 = 0;
            local_c = 0;
            do {
                if (local_10 == 0) {
                    uVar5 = local_8;
                }
                else {
                    uVar5 = 1 - local_8;
                }
                uVar7 = local_24[2];
                uVar5 = *(uint32_t*)(&DAT_006f1e6c[0] + uVar5 * 4);
                piVar2 = (int32_t*)(uVar7 + local_c * 4);
                if (uVar5 < 0x10) {
                    iVar3 = *(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) + *piVar2 * 4) + 0x48);
                    if (iVar3 != -1) {
                        local_18 = *(uint32_t*)(*(int32_t*)(selfBase + 0x18) + iVar3 * 4);
                        iVar3 = FUN_006949cb((void*)(uintptr_t)local_18, piVar2, local_28, local_4c,
                                             local_9c,
                                             *(void**)(&DAT_006f1e78[0] + uVar5 * 0x20), 0);
                        if (iVar3 == 0) {
                            local_20 = FUN_00694b7c((void*)(uintptr_t)local_18,
                                                    &DAT_006f1e60[0] + uVar5 * 0x20, local_8c,
                                                    &local_2c, local_27c, local_9c, local_1c, 0);
                            goto LAB_0069b9b1;
                        }
                    }
                    local_20 = 1;
                    break;
                }
                uVar4 = 0;
                piVar2 = local_1dc + (uVar5 - 0x10) * 4;
                do {
                    if (local_4c[uVar4] < local_28) {
                        *piVar2 = *(int32_t*)(uVar7 + (local_4c[uVar4] + local_c) * 4);
                    }
                    else {
                        *piVar2 = -1;
                    }
                    uVar4 = uVar4 + 1;
                    piVar2 = piVar2 + 1;
                } while (uVar4 < 4);
LAB_0069b9b1:
                if (local_20 == 1) break;
                local_8 = local_8 + 1;
                local_c = local_c + local_28;
            } while (local_8 < 2);
            local_8 = 0;
            local_30 = (uint32_t*)0;
            do {
                if (local_10 == 0) {
                    uVar5 = local_8;
                }
                else {
                    uVar5 = 1 - local_8;
                }
                if ((0xf < *(uint32_t*)(&DAT_006f1e6c[0] + uVar5 * 4)) && (local_14 = 0, local_2c != 0)) {
                    do {
                        uVar5 = 0;
                        if (local_28 != 0) {
                            iVar3 = local_8c[local_14];
                            uVar7 = *(uint32_t*)(iVar3 + 0xc);
                            do {
                                local_c = 0;
                                if (uVar7 != 0) {
                                    piVar2 = *(int32_t**)(iVar3 + 0x10);
                                    do {
                                        if (*(int32_t*)(local_24[2] + ((int32_t)(intptr_t)local_30 + uVar5) * 4) == *piVar2) {
                                            local_20 = 1;
                                            goto LAB_0069ba4c;
                                        }
                                        local_c = local_c + 1;
                                        uVar7 = *(uint32_t*)(iVar3 + 0xc);
                                        piVar2 = piVar2 + 1;
                                    } while (local_c < uVar7);
                                }
                                uVar5 = uVar5 + 1;
                            } while (uVar5 < local_28);
                        }
LAB_0069ba4c:
                        local_14 = local_14 + 1;
                    } while (local_14 < local_2c);
                }
                local_8 = local_8 + 1;
                local_30 = (uint32_t*)((int32_t)(intptr_t)local_30 + local_28);
            } while (local_8 < 2);
            if (local_20 == 0) {
                if (local_34 != 0) goto LAB_0069bbf7;
                local_14 = 0;
                if (local_2c != 0) {
                    do {
                        local_38 = *(uint32_t*)(local_8c[local_14] + 0xc);
                        local_c = 0;
                        if (local_38 != 0) {
                            do {
                                if (*(int32_t*)(selfBase + 0xc) != 0) {
                                    local_30 = *(uint32_t**)(selfBase + 0x18);
                                    local_18 = *(uint32_t*)(selfBase + 0xc);
                                    do {
                                        puVar1 = (uint32_t*)*local_30;
                                        if ((puVar1 != (uint32_t*)0) && (*puVar1 != 0)) {
                                            local_8 = 0;
                                            if (puVar1[1] != 0) {
                                                iVar3 = *(int32_t*)(*(int32_t*)(local_8c[local_14] + 0x10) + local_c * 4);
                                                piVar2 = (int32_t*)puVar1[2];
                                                local_4c[4] = puVar1[1];
                                                do {
                                                    if ((*piVar2 == iVar3) ||
                                                        (*(int32_t*)(*(int32_t*)(*(int32_t*)(selfBase + 0x14) +
                                                                                 *piVar2 * 4) + 0x38) == iVar3)) {
                                                        local_8 = 1;
                                                    }
                                                    piVar2 = piVar2 + 1;
                                                    local_4c[4] = local_4c[4] - 1;
                                                } while (local_4c[4] != 0);
                                            }
                                            if (puVar1 == local_24) {
                                                local_8 = 0;
                                            }
                                            if (local_8 != 0) {
                                                uVar5 = 0;
                                                do {
                                                    if (puVar1 == (uint32_t*)local_8c[uVar5]) {
                                                        local_8 = 0;
                                                    }
                                                    uVar5 = uVar5 + 1;
                                                } while (uVar5 < local_2c);
                                                if (local_8 != 0) {
                                                    local_20 = 1;
                                                }
                                            }
                                        }
                                        local_30 = local_30 + 1;
                                        local_18 = local_18 - 1;
                                    } while (local_18 != 0);
                                }
                                local_c = local_c + 1;
                            } while (local_c < local_38);
                        }
                        local_14 = local_14 + 1;
                    } while (local_14 < local_2c);
                }
                local_c = 0;
                do {
                    iVar3 = local_1dc[local_c];
                    if ((iVar3 != -1) && (uVar5 = 0, local_2c != 0)) {
                        local_38 = *(uint32_t*)(*(int32_t*)(selfBase + 0x14) + iVar3 * 4);
                        do {
                            local_18 = *(uint32_t*)(local_8c[uVar5] + 0xc);
                            if (local_18 != 0) {
                                piVar2 = *(int32_t**)(uintptr_t)(local_8c[uVar5] + 0x10);
                                do {
                                    if ((iVar3 == *piVar2) ||
                                        (*(int32_t*)(local_38 + 0x38) == *piVar2)) {
                                        local_20 = 1;
                                    }
                                    piVar2 = piVar2 + 1;
                                    local_18 = local_18 - 1;
                                } while (local_18 != 0);
                            }
                            uVar5 = uVar5 + 1;
                        } while (uVar5 < local_2c);
                    }
                    local_c = local_c + 1;
                } while (local_c < 0x28);
                if (local_20 == 0) goto LAB_0069bbf7;
            }
            local_10 = local_10 + 1;
        } while (local_10 < 2);
        if (local_20 == 0) {
LAB_0069bbf7:
            local_8c[local_2c] = (int32_t)(intptr_t)local_24;
            uVar5 = 0;
            do {
                iVar3 = *(int32_t*)((uint8_t*)local_1dc + uVar5);
                if ((iVar3 != -1) ||
                    (iVar3 = *(int32_t*)((uint8_t*)local_27c + uVar5), iVar3 != -1)) {
                    *(int32_t*)((uint8_t*)local_13c + uVar5) = iVar3;
                }
                uVar5 = uVar5 + 4;
            } while (uVar5 < 0xa0);
            local_10 = 0;
LAB_0069bc31:
            goto LAB_0069bc37;
        }
        local_34 = local_34 + 1;
        local_10 = local_20;
        if (local_34 != 0) goto LAB_0069bc31;
    } while (true);
}
