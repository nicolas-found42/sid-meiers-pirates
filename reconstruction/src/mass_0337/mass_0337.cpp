// UNVERIFIED: decompiler-derived reconstruction from Ghidra 12.2 pseudocode.
// Reconstruction batch mass_0337 — Sid Meier's Pirates! (2004), PE32 i386.
// Every definition below corresponds to one supplied corpus listing. Field offsets,
// constants, call order and conditional structure follow the listing.
#include <cstdint>
#include <cstddef>
#include <cstring>
#include <windows.h>

// ---------------------------------------------------------------------------
// Referenced helpers and globals (declared extern, not defined here).
// ---------------------------------------------------------------------------
extern int FUN_00694b7c(uint32_t* object, void* descriptor, void** out, uint32_t* count,
                        void* slots, void* scratch, uint32_t n, int flag);
extern void FUN_00614343(...);
extern int FUN_0065d0b4(...);
extern int FUN_0065cc1a(void);
extern int FUN_0065cc50(...);
extern int FUN_0065d0ff(...);
extern int FUN_0065d9d5(uint32_t a, uint32_t b, uint32_t c, uint64_t d);
extern int FUN_0065d35e(...);
extern int FUN_0065cea4(void);
extern void FUN_006951ca(void* a, void* b, uint32_t c);
extern int FUN_0066a65b(void* a, int b);
extern void FUN_0066275f(void* a, uint32_t b, uint32_t c, const char* message);
extern int FUN_00669f90(void* a, uint32_t b, int c);
extern void FUN_00661cb0(void* a);
extern void* FUN_00533c78(uint32_t size);
extern int FUN_0065e4f2(void);
extern int FUN_00662317(void);
extern int FUN_0065d97c(uint32_t a, uint32_t b, uint32_t c, int d);
extern void FUN_0065d5bd(void);
extern int FUN_0065da35(uint32_t a, uint32_t b, uint32_t c);
extern int FUN_0065ce50(void);
extern int FUN_0065ce88(void);
extern void operator_delete(void* p);

extern uint8_t DAT_006f3060;
extern uint8_t DAT_006f30c0;
extern uint8_t DAT_006f1980;
extern uint8_t DAT_006f19e0;

// ---------------------------------------------------------------------------
// Definitions
// ---------------------------------------------------------------------------

// 0x69be37 — observed shape
int FUN_0069be37(void* self)
{
    char* s = (char*)self;
    uint32_t uVar1;
    int32_t iVar2;
    int32_t iVar3;
    int32_t* piVar4;
    uint32_t uVar5;
    uint32_t* puVar6;
    uint32_t* puVar7;
    uint32_t* local_108[16];
    uint32_t local_c8;
    uint32_t local_c4;
    uint32_t local_b8;
    uint32_t local_b4;
    uint32_t local_a8;
    uint32_t local_28;
    uint32_t local_24;
    uint32_t local_20;
    uint32_t local_1c;
    uint32_t local_18;
    int32_t local_14;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;

    local_c = 0;
    local_28 = 0;
    local_10 = 0;
    uVar5 = **(uint32_t**)(s + 0x100) & 0xfffff;
    local_24 = 1;
    local_20 = 2;
    local_1c = 3;
    iVar2 = FUN_00694b7c((uint32_t*)*(uint32_t**)(s + 0x100), &DAT_006f3060,
                         (void**)local_108, &local_c, &local_c8, &local_28, uVar5, 1);
    if (iVar2 != 0) {
        iVar2 = FUN_00694b7c((uint32_t*)*(uint32_t**)(s + 0x100), &DAT_006f30c0,
                             (void**)local_108, &local_c, &local_c8, &local_28, uVar5, 1);
        if (iVar2 != 0) {
            return iVar2;
        }
        local_10 = 1;
    }
    if (*local_108[0] != 0x50000002) {
        return 1;
    }
    local_8 = 1;
    if (1 < uVar5) {
        piVar4 = (int32_t*)(*(uint32_t*)(s + 0x100) + 8);
        local_14 = *piVar4;
        iVar2 = (int32_t)(uVar5 * 4);
        do {
            piVar4 = piVar4 + 1;
            iVar2 = iVar2 + 4;
            if (*piVar4 != local_14) {
                return 1;
            }
            if (*(int32_t*)(iVar2 + *(int32_t*)(*(uint32_t*)(s + 0x100) + 8)) !=
                *(int32_t*)(*(int32_t*)(*(uint32_t*)(s + 0x100) + 8) + uVar5 * 4)) {
                return 1;
            }
            local_8 = local_8 + 1;
        } while (local_8 < uVar5);
    }
    iVar2 = FUN_0065d0b4();
    if (iVar2 == 0) {
        local_8 = 0;
    }
    else {
        local_8 = (uint32_t)FUN_0065cc1a();
    }
    iVar2 = FUN_0065d0ff(0x70800002, 6, uVar5, 0);
    if (-1 < iVar2) {
        iVar2 = FUN_0065cc50();
        uVar1 = local_8;
        if (-1 < iVar2) {
            puVar6 = *(uint32_t**)(*(uint32_t*)(s + 0x100) + 0x10);
            puVar7 = *(uint32_t**)(uVar1 + 0x10);
            for (; uVar5 != 0; uVar5 = uVar5 - 1) {
                *puVar7 = *puVar6;
                puVar6 = puVar6 + 1;
                puVar7 = puVar7 + 1;
            }
            puVar6 = *(uint32_t**)(uVar1 + 8);
            *puVar6 = local_c8;
            puVar6[1] = local_c4;
            if (local_10 == 0) {
                iVar2 = *(int32_t*)(uVar1 + 8);
                *(uint32_t*)(iVar2 + 8) = local_b8;
            }
            else {
                iVar2 = *(int32_t*)(*(uint32_t*)(s + 0x14) + local_b4 * 4);
                local_18 = local_b8;
                iVar3 = *(int32_t*)(*(uint32_t*)(s + 0x14) + local_b8 * 4);
                uVar5 = *(uint32_t*)(iVar3 + 0x38);
                local_10 = local_b4;
                if (uVar5 != 0xffffffff) {
                    iVar3 = *(int32_t*)(*(uint32_t*)(s + 0x14) + uVar5 * 4);
                    local_18 = uVar5;
                }
                uVar5 = *(uint32_t*)(iVar2 + 0x38);
                if (uVar5 != 0xffffffff) {
                    iVar2 = *(int32_t*)(*(uint32_t*)(s + 0x14) + uVar5 * 4);
                    local_10 = uVar5;
                }
                local_14 = FUN_0065d9d5(*(uint32_t*)(iVar3 + 4), *(uint32_t*)(iVar3 + 0xc),
                                        *(uint32_t*)(iVar3 + 0x10), 0);
                local_b4 = (uint32_t)FUN_0065d9d5(*(uint32_t*)(iVar2 + 4),
                                                  *(uint32_t*)(iVar2 + 0xc),
                                                  *(uint32_t*)(iVar2 + 0x10), 0);
                local_c = local_b4;
                if ((local_14 == -1) || (local_b4 == 0xffffffff)) {
                    iVar2 = -0x7ff8fff2;
                    goto LAB_0069c0e2;
                }
                *(uint32_t*)(*(int32_t*)(local_14 * 4 + *(uint32_t*)(s + 0x14)) + 0x3c) =
                    local_18 ^ 0x80000;
                *(uint32_t*)(*(int32_t*)((int32_t)local_b4 * 4 + *(uint32_t*)(s + 0x14)) + 0x3c) =
                    local_10 ^ 0x80000;
                *(uint32_t*)(*(int32_t*)(local_14 * 4 + *(uint32_t*)(s + 0x14)) + 0x38) = local_18;
                *(uint32_t*)(*(int32_t*)((int32_t)local_b4 * 4 + *(uint32_t*)(s + 0x14)) + 0x38) =
                    local_10;
                *(int32_t*)(*(int32_t*)(uVar1 + 8) + 8) = local_14;
                iVar2 = *(int32_t*)(uVar1 + 8);
            }
            *(uint32_t*)(iVar2 + 0xc) = local_b4;
            *(uint32_t*)(*(int32_t*)(uVar1 + 8) + 0x10) = local_a8;
            *(uint32_t*)(*(int32_t*)(uVar1 + 8) + 0x14) = local_a8;
            iVar2 = ((int32_t (*)(void*))*(void**)(*(uint32_t*)s + 0x30))(self);
            if (iVar2 == 0) {
                iVar2 = FUN_0065d35e();
            }
            else {
                iVar2 = 1;
            }
        }
    }
LAB_0069c0e2:
    if (local_8 != 0) {
        FUN_00614343();
    }
    return iVar2;
}

// 0x69c0f7 — observed shape
int FUN_0069c0f7(void* self)
{
    char* s = (char*)self;
    int32_t iVar1;
    uint32_t uVar2;
    int32_t iVar3;

    if (*(int32_t*)(s + 0x100) != 0x50000002) {
        return 1;
    }
    iVar1 = FUN_0065d0b4(0x74);
    if (iVar1 == 0) {
        iVar1 = 0;
    }
    else {
        iVar1 = FUN_0065cc1a();
    }
    if (iVar1 == 0) {
        iVar3 = -0x7ff8fff2;
    }
    else {
        iVar3 = FUN_0065d0ff(0x70800002, 6, 1, 0);
        if (-1 < iVar3) {
            iVar3 = FUN_0065cc50();
            if (-1 < iVar3) {
                **(uint32_t**)(iVar1 + 0x10) =
                    **(uint32_t**)(*(uint32_t*)(s + 0x100) + 0x10);
                uVar2 = 0;
                do {
                    *(uint32_t*)(uVar2 + *(int32_t*)(iVar1 + 8)) =
                        *(uint32_t*)(uVar2 + *(int32_t*)(*(uint32_t*)(s + 0x100) + 8));
                    uVar2 = uVar2 + 4;
                } while (uVar2 < 0x10);
                iVar3 = FUN_0065d9d5(*(uint32_t*)(s + 0x78), 0, 0, 0);
                if (iVar3 == -1) {
                    return -0x7ff8fff2;
                }
                *(int32_t*)(*(int32_t*)(iVar1 + 8) + 0x10) = iVar3;
                *(int32_t*)(*(int32_t*)(iVar1 + 8) + 0x14) = iVar3;
                iVar1 = ((int32_t (*)(void*))*(void**)(*(uint32_t*)s + 0x30))(self);
                if (iVar1 == 0) {
                    iVar3 = FUN_0065d35e();
                }
                else {
                    iVar3 = 1;
                }
            }
        }
        FUN_00614343();
    }
    return iVar3;
}

// 0x69c1ed — observed shape
uint32_t FUN_0069c1ed(void* self, uint32_t param_1, int param_2, uint32_t param_3)
{
    char* s = (char*)self;
    int32_t iVar1;
    int32_t iVar2;
    int32_t iVar3;
    int32_t* piVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    int32_t local_18;
    int32_t* local_14;
    int32_t* local_10;
    uint32_t local_c;
    uint32_t local_8;

    iVar2 = (int32_t)param_1;
    iVar3 = ((int32_t (*)(void*, uint32_t, int))*(void**)(*(uint32_t*)s + 0x20))(self, param_1, 0);
    if (iVar3 == 0) {
        local_8 = 0;
        local_14 = *(int32_t**)((int32_t)param_1 + 0xc);
        param_1 = 0xffffffff;
        if (local_14 != (int32_t*)0) {
            piVar4 = *(int32_t**)(iVar2 + 0x10);
            do {
                iVar3 = *(int32_t*)(*(uint32_t*)(s + 0x14) + *piVar4 * 4);
                uVar5 = *(uint32_t*)(iVar3 + 0x4c);
                if (local_8 < uVar5) {
                    local_8 = uVar5;
                }
                uVar5 = *(uint32_t*)(iVar3 + 0x48);
                if (uVar5 < param_1) {
                    param_1 = uVar5;
                }
                piVar4 = piVar4 + 1;
                local_14 = (int32_t*)((int32_t)local_14 + -1);
            } while (local_14 != (int32_t*)0);
        }
        local_18 = *(int32_t*)(iVar2 + 4);
        if (local_18 != 0) {
            local_14 = *(int32_t**)(iVar2 + 8);
            do {
                iVar3 = *(int32_t*)(*(uint32_t*)(s + 0x14) + *local_14 * 4);
                if (((*(uint8_t*)(*(int32_t*)(*(uint32_t*)(s + 0x10) +
                                               *(int32_t*)(iVar3 + 4) * 4) + 4) & 2) != 0) &&
                    (*(int32_t*)(iVar3 + 0x48) != -1)) {
                    uVar5 = (uint32_t)(*(int32_t*)(iVar3 + 0x48) + 1);
                    if (local_8 < uVar5) {
                        local_8 = uVar5;
                    }
                    while ((uVar5 = *(uint32_t*)(iVar3 + 0x50)), uVar5 <= param_1) {
                        if ((uVar5 == 0xffffffff) || (uVar6 = 0, param_3 == 0)) {
LAB_0069c308:
                            param_1 = (uint32_t)(*(int32_t*)(iVar3 + 0x50) - 1);
                            break;
                        }
                        do {
                            if (*(int32_t*)(param_2 + uVar6 * 4) ==
                                *(int32_t*)(*(uint32_t*)(s + 0x18) + uVar5 * 4)) break;
                            uVar6 = uVar6 + 1;
                        } while (uVar6 < param_3);
                        if (param_3 <= uVar6) goto LAB_0069c308;
                        iVar1 = *(int32_t*)(param_2 + uVar6 * 4);
                        local_c = 0;
                        if (*(int32_t*)(iVar1 + 0xc) != 0) {
                            local_10 = *(int32_t**)(iVar1 + 0x10);
                            do {
                                if (*(int32_t*)(iVar3 + 0x10) ==
                                    *(int32_t*)(*(int32_t*)(*(uint32_t*)(s + 0x14) + *local_10 * 4) +
                                                0x10)) break;
                                local_c = local_c + 1;
                                local_10 = local_10 + 1;
                            } while (local_c < *(uint32_t*)(iVar1 + 0xc));
                        }
                        if (*(uint32_t*)(iVar1 + 0xc) <= local_c) goto LAB_0069c308;
                        iVar3 = *(int32_t*)(*(uint32_t*)(s + 0x14) +
                                            *(int32_t*)(*(int32_t*)(iVar1 + 0x10) + local_c * 4) * 4);
                    }
                }
                local_14 = local_14 + 1;
                local_18 = local_18 + -1;
            } while (local_18 != 0);
        }
        uVar5 = 0;
        if (param_3 == 0) {
            uVar6 = 0;
        }
        else {
            do {
                uVar6 = *(uint32_t*)(*(int32_t*)(*(uint32_t*)(s + 0x14) +
                                                 **(int32_t**)(*(int32_t*)(param_2 + uVar5 * 4) + 0x10) *
                                                     4) + 0x48);
                if ((local_8 <= uVar6) && (uVar6 <= param_1)) break;
                uVar5 = uVar5 + 1;
            } while (uVar5 < param_3);
        }
        if ((uVar5 != param_3) &&
            (iVar3 = ((int32_t (*)(void*, int32_t, uint32_t))*(void**)(*(uint32_t*)s + 0x34))(
                         self, iVar2, uVar6),
             iVar3 == 0)) {
            uVar5 = 0;
            if (param_3 != 0) {
                do {
                    **(uint32_t**)(param_2 + uVar5 * 4) = 0;
                    uVar5 = uVar5 + 1;
                } while (uVar5 < param_3);
            }
            if (*(int32_t*)(*(uint32_t*)(s + 0x18) + uVar6 * 4) != 0) {
                FUN_00614343(1);
            }
            *(int32_t*)(*(uint32_t*)(s + 0x18) + uVar6 * 4) = iVar2;
            uVar5 = 0;
            if (*(int32_t*)(iVar2 + 0xc) != 0) {
                do {
                    iVar3 = (int32_t)(uVar5 * 4);
                    uVar5 = uVar5 + 1;
                    *(uint32_t*)(*(int32_t*)(*(uint32_t*)(s + 0x14) +
                                             *(int32_t*)(*(int32_t*)(iVar2 + 0x10) +
                                                         iVar3) * 4) + 0x48) = uVar6;
                } while (uVar5 < *(uint32_t*)(iVar2 + 0xc));
            }
            return 0;
        }
    }
    if (iVar2 != 0) {
        FUN_00614343(1);
    }
    return 1;
}

// 0x69c3c2 — observed shape
uint32_t FUN_0069c3c2(void* self)
{
    char* s = (char*)self;
    int32_t iVar1;
    uint32_t uVar2;
    int32_t iVar3;
    uint32_t* puVar4;
    uint32_t* puVar5;
    uint32_t local_10;
    int32_t* local_c;
    int32_t* local_8;

    uVar2 = **(uint32_t**)(s + 0x100) & 0xfffff;
    local_10 = 0;
    if (uVar2 != 0) {
        local_8 = (int32_t*)(*(uint32_t*)(s + 0x100) + 8);
        local_c = local_8 + uVar2;
        do {
            iVar3 = *(int32_t*)(*(uint32_t*)(s + 0x14) + *local_8 * 4);
            iVar1 = *(int32_t*)(*(uint32_t*)(s + 0x14) + *local_c * 4);
            if ((((*(int32_t*)(iVar3 + 4) != *(int32_t*)(iVar1 + 4)) ||
                  (*(int32_t*)(iVar3 + 8) != *(int32_t*)(iVar1 + 8))) ||
                 (*(int32_t*)(iVar3 + 0xc) != *(int32_t*)(iVar1 + 0xc))) ||
                ((*(int32_t*)(iVar3 + 0x10) != *(int32_t*)(iVar1 + 0x10) ||
                  ((*(uint32_t*)(iVar1 + 0x3c) ^ *(uint32_t*)(iVar3 + 0x3c)) != 0x80000)))) {
                return 1;
            }
            local_10 = local_10 + 1;
            local_8 = local_8 + 1;
            local_c = local_c + 1;
        } while (local_10 < uVar2);
    }
    **(uint32_t**)(s + 0x100) = uVar2 | 0x70000000;
    *(uint32_t*)(*(uint32_t*)(s + 0x100) + 4) = uVar2;
    if ((uVar2 != 0) &&
        ((*(uint8_t*)(*(int32_t*)(*(uint32_t*)(s + 0x14) +
                                  **(int32_t**)(*(uint32_t*)(s + 0x100) + 8) * 4) + 0x3e) & 8) != 0)) {
        puVar5 = *(uint32_t**)(*(uint32_t*)(s + 0x100) + 8);
        puVar4 = puVar5 + uVar2;
        for (; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar5 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar5 = puVar5 + 1;
        }
        for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
            *(uint8_t*)puVar5 = *(uint8_t*)puVar4;
            puVar4 = (uint32_t*)((int32_t)puVar4 + 1);
            puVar5 = (uint32_t*)((int32_t)puVar5 + 1);
        }
    }
    return 0;
}

// 0x69c4b5 — observed shape
uint32_t FUN_0069c4b5(void* self)
{
    char* s = (char*)self;
    uint32_t uVar1;
    int32_t iVar2;
    int32_t iVar3;
    int32_t iVar4;
    uint32_t uVar5;
    int32_t* local_10;
    int32_t* local_c;
    uint32_t local_8;

    uVar5 = **(uint32_t**)(s + 0x100) & 0xfffff;
    local_8 = 0;
    if (uVar5 != 0) {
        uVar1 = (*(uint32_t**)(s + 0x100))[2];
        local_10 = (int32_t*)(uVar1 + uVar5 * 4);
        local_c = (int32_t*)(uVar1 + uVar5 * 8);
        do {
            iVar2 = *(int32_t*)(uVar1 + local_8 * 4);
            iVar3 = *(int32_t*)(*(uint32_t*)(s + 0x14) + iVar2 * 4);
            iVar4 = *(int32_t*)(*(uint32_t*)(s + 0x14) + *local_c * 4);
            if ((iVar2 != *local_10) ||
                (((iVar2 = *(int32_t*)(iVar4 + 0x38),
                   iVar2 != *(int32_t*)(local_8 * 4 + *(int32_t*)(*(uint32_t*)(s + 0x100) + 8)) &&
                   ((iVar2 == -1 || (iVar2 != *(int32_t*)(iVar3 + 0x38))))) ||
                  ((*(uint32_t*)(iVar4 + 0x3c) ^ 0x80000) != *(uint32_t*)(iVar3 + 0x3c))))) {
                return 1;
            }
            local_8 = local_8 + 1;
            local_c = local_c + 1;
            local_10 = local_10 + 1;
        } while (local_8 < uVar5);
    }
    **(uint32_t**)(s + 0x100) = uVar5 | 0x70000000;
    *(uint32_t*)(*(uint32_t*)(s + 0x100) + 4) = uVar5;
    return 0;
}

// 0x69c587 — observed shape
uint32_t FUN_0069c587(void* self)
{
    char* s = (char*)self;
    int32_t iVar1;
    int32_t iVar2;
    int32_t iVar3;
    int32_t iVar4;
    int32_t iVar5;
    int32_t iVar6;
    int32_t iVar7;
    uint32_t uVar8;
    uint32_t* puVar9;
    uint32_t* puVar10;
    int32_t* local_14;
    uint32_t local_c;
    int32_t local_8;

    uVar8 = **(uint32_t**)(s + 0x100) & 0xfffff;
    local_c = 0;
    if (uVar8 != 0) {
        iVar1 = *(int32_t*)(s + 0x14);
        iVar2 = *(int32_t*)(*(int32_t*)(s + 0x100) + 8);
        local_8 = (int32_t)(uVar8 << 3);
        local_14 = (int32_t*)(iVar2 + uVar8 * 4);
        do {
            iVar3 = *(int32_t*)(iVar2 + local_c * 4);
            iVar4 = *(int32_t*)(iVar1 + iVar3 * 4);
            iVar5 = *(int32_t*)(iVar1 + *local_14 * 4);
            iVar6 = *(int32_t*)(iVar1 + *(int32_t*)(local_8 + iVar2) * 4);
            if (iVar3 != *local_14) {
                return 1;
            }
            iVar3 = *(int32_t*)(local_8 + *(int32_t*)(*(int32_t*)(s + 0x100) + 8));
            iVar7 = *(int32_t*)(iVar5 + 0x38);
            if (iVar7 != iVar3) {
                if (iVar7 == -1) {
                    return 1;
                }
                if (iVar7 != *(int32_t*)(iVar6 + 0x38)) {
                    return 1;
                }
            }
            if ((*(uint32_t*)(iVar5 + 0x3c) ^ 0x80000) != *(uint32_t*)(iVar6 + 0x3c)) {
                return 1;
            }
            iVar5 = *(int32_t*)(iVar4 + 0x38);
            if (iVar5 != iVar3) {
                if (iVar5 == -1) {
                    return 1;
                }
                if (iVar5 != *(int32_t*)(iVar6 + 0x38)) {
                    return 1;
                }
            }
            if ((*(uint32_t*)(iVar4 + 0x3c) ^ 0x80000) != *(uint32_t*)(iVar6 + 0x3c)) {
                return 1;
            }
            local_c = local_c + 1;
            local_14 = local_14 + 1;
            local_8 = local_8 + 4;
        } while (local_c < uVar8);
    }
    **(uint32_t**)(s + 0x100) = uVar8 | 0x70000000;
    *(uint32_t*)(*(uint32_t*)(s + 0x100) + 4) = uVar8;
    puVar10 = *(uint32_t**)(*(uint32_t*)(s + 0x100) + 8);
    puVar9 = puVar10 + uVar8 * 2;
    for (; uVar8 != 0; uVar8 = uVar8 - 1) {
        *puVar10 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
    }
    return 0;
}

// 0x69c6b9 — observed shape
uint32_t FUN_0069c6b9(void* self, int param_1, int32_t* param_2, int32_t* param_3)
{
    char* s = (char*)self;
    int32_t* piVar1;
    int32_t iVar2;
    uint32_t* puVar3;
    uint32_t uVar4;
    int32_t* piVar5;
    int32_t* piVar6;
    uint32_t local_8;

    iVar2 = *(int32_t*)(*(uint32_t*)(s + 0x14) + param_1 * 4);
    if ((*(int32_t*)(iVar2 + 0x58) == *(int32_t*)(iVar2 + 0x54)) &&
        (uVar4 = 0xffffffff, *(int32_t*)(iVar2 + 0x48) != -1)) {
        puVar3 = *(uint32_t**)(*(uint32_t*)(s + 0x18) + *(int32_t*)(iVar2 + 0x48) * 4);
        if ((*puVar3 & 0xfff00000) == 0x20400000) {
            local_8 = 0;
            if (puVar3[3] != 0) {
                piVar6 = (int32_t*)puVar3[4];
                do {
                    if (*piVar6 == param_1) {
                        uVar4 = local_8;
                    }
                    local_8 = local_8 + 1;
                    piVar6 = piVar6 + 1;
                } while (local_8 < puVar3[3]);
                if (uVar4 != 0xffffffff) {
                    piVar6 = (int32_t*)(puVar3[2] + uVar4 * 4);
                    piVar1 = (int32_t*)(puVar3[2] + (uVar4 + (*puVar3 & 0xfffff)) * 4);
                    if ((*(uint8_t*)(*(int32_t*)(*(uint32_t*)(s + 0x10) +
                                                 *(int32_t*)(*(int32_t*)(*(uint32_t*)(s + 0x14) +
                                                                      *piVar1 * 4) + 4) * 4) + 5) &
                         1) == 0) {
                        if ((*(uint8_t*)(*(int32_t*)(*(uint32_t*)(s + 0x10) +
                                                     *(int32_t*)(*(int32_t*)(*(uint32_t*)(s + 0x14) +
                                                                          *piVar6 * 4) + 4) * 4) + 5) &
                             1) == 0) {
                            return 1;
                        }
                        piVar5 = piVar1;
                    }
                    else {
                        piVar5 = piVar6;
                        piVar6 = piVar1;
                    }
                    if ((*(double*)(*(int32_t*)(*(uint32_t*)(s + 0x14) + *piVar6 * 4) + 0x20) == 1.0) &&
                        ((*(uint32_t*)(*(int32_t*)(*(uint32_t*)(s + 0x14) + *piVar5 * 4) + 0x3c) &
                          0x1f0000) == 0x80000)) {
                        *param_3 = *piVar5;
                        *param_2 = (int32_t)(intptr_t)puVar3;
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

// 0x69c7d0 — observed shape
int FUN_0069c7d0(void* self, int param_1, uint32_t* param_2, int32_t* param_3,
                 uint32_t* param_4, uint32_t* param_5, int param_6)
{
    char* s = (char*)self;
    uint32_t* puVar1;
    int32_t iVar2;
    int32_t iVar3;
    int32_t iVar4;
    bool bVar5;
    int32_t iVar6;
    int32_t* piVar7;
    int32_t iVar8;
    uint32_t uVar9;
    uint32_t uVar10;
    uint32_t* puVar11;
    uint32_t uVar12;
    uint32_t* puVar13;
    int32_t local_34[4];
    uint32_t* local_24[4];
    uint32_t local_14;
    int32_t local_10;
    int32_t* local_c;
    uint32_t local_8;

    local_24[0] = nullptr;
    local_24[1] = nullptr;
    local_24[2] = nullptr;
    uVar10 = *param_5 & 0xfffff;
    local_14 = uVar10;
    local_24[3] = nullptr;
    local_c = (int32_t*)self;
    if ((*(uint8_t*)((intptr_t)self + 0x6f) & 2) == 0) {
        uVar12 = 0;
        if (uVar10 != 0) {
            do {
                iVar6 = FUN_0069c6b9(self, *(uint32_t*)(param_1 + uVar12 * 4),
                                     (int32_t*)(local_24 + uVar12), local_34 + uVar12);
                if (iVar6 != 0) {
                    return iVar6;
                }
                uVar12 = uVar12 + 1;
            } while (uVar12 < uVar10);
        }
        local_8 = 0;
        if (uVar10 != 0) {
            local_10 = (int32_t)((intptr_t)local_24 - (intptr_t)param_3);
            piVar7 = param_3;
            do {
                if (((*(int32_t*)(*(int32_t*)(*(uint32_t*)(s + 0x14) +
                                              *(int32_t*)((intptr_t)local_34 - (intptr_t)param_3 +
                                                          (intptr_t)piVar7) * 4) + 0x38) !=
                      *piVar7) ||
                     ((*(uint8_t*)(*(int32_t*)(*(uint32_t*)(s + 0x14) + *piVar7 * 4) + 0x3e) &
                       0x1f) != 0)) ||
                    (*(uint32_t**)((intptr_t)local_24 - (intptr_t)param_3 + (intptr_t)piVar7) !=
                     local_24[0])) {
                    goto LAB_0069cab6;
                }
                local_8 = local_8 + 1;
                piVar7 = piVar7 + 1;
            } while (local_8 < uVar10);
        }
        uVar12 = 0;
        if (local_24[0][3] != 0) {
            do {
                uVar9 = 0;
                local_8 = 1;
                if (uVar10 == 0) goto LAB_0069cab6;
                do {
                    if (*(int32_t*)(local_24[0][4] + uVar12 * 4) ==
                        *(int32_t*)(param_1 + uVar9 * 4)) {
                        local_8 = 0;
                    }
                    uVar9 = uVar9 + 1;
                } while (uVar9 < uVar10);
                if (local_8 != 0) goto LAB_0069cab6;
                uVar12 = uVar12 + 1;
            } while (uVar12 < (uint32_t)local_24[0][3]);
        }
    }
    else {
        local_8 = 0;
        if (uVar10 != 0) {
            piVar7 = param_3;
            do {
                iVar6 = *(int32_t*)(*(uint32_t*)(s + 0x14) +
                                    *(int32_t*)((intptr_t)piVar7 +
                                                (param_1 - (intptr_t)param_3)) * 4);
                if ((*(int32_t*)(iVar6 + 0x38) != *piVar7) ||
                    ((*(uint32_t*)(iVar6 + 0x3c) & 0x1f0000) != 0x10000)) {
                    goto LAB_0069cab6;
                }
                puVar1 = *(uint32_t**)(*(uint32_t*)(s + 0x14) + *piVar7 * 4);
                uVar12 = puVar1[0xf];
                if (((uVar12 & 0x1f0000) != 0) ||
                    (((uVar12 & 0x200) == 0 &&
                      ((uVar12 = *puVar1, (uVar12 & 4) == 0 || ((uVar12 & 0x10) == 0)))))) {
                    goto LAB_0069cab6;
                }
                local_8 = local_8 + 1;
                piVar7 = piVar7 + 1;
            } while (local_8 < uVar10);
        }
    }
    iVar6 = FUN_0065d0b4(0x74);
    if (iVar6 == 0) {
        iVar6 = 0;
    }
    else {
        iVar6 = FUN_0065cc1a();
    }
    if (iVar6 == 0) {
        iVar8 = -0x7ff8fff2;
    }
    else {
        iVar8 = FUN_0065d0ff(uVar10 | 0x70100000, uVar10 * 3, uVar10, 0);
        if (-1 < iVar8) {
            iVar8 = FUN_0065cc50(param_5);
            if (-1 < iVar8) {
                puVar11 = *(uint32_t**)(param_6 + 0x10);
                puVar13 = *(uint32_t**)(iVar6 + 0x10);
                for (uVar12 = uVar10; uVar12 != 0; uVar12 = uVar12 - 1) {
                    *puVar13 = *puVar11;
                    puVar11 = puVar11 + 1;
                    puVar13 = puVar13 + 1;
                }
                for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
                    *(uint8_t*)puVar13 = *(uint8_t*)puVar11;
                    puVar11 = (uint32_t*)((intptr_t)puVar11 + 1);
                    puVar13 = (uint32_t*)((intptr_t)puVar13 + 1);
                }
                piVar7 = *(int32_t**)(iVar6 + 8);
                for (uVar12 = uVar10; uVar12 != 0; uVar12 = uVar12 - 1) {
                    *piVar7 = *param_3;
                    param_3 = param_3 + 1;
                    piVar7 = piVar7 + 1;
                }
                for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
                    *(char*)piVar7 = (char)*param_3;
                    param_3 = (int32_t*)((intptr_t)param_3 + 1);
                    piVar7 = (int32_t*)((intptr_t)piVar7 + 1);
                }
                puVar11 = (uint32_t*)(*(int32_t*)(iVar6 + 8) + local_14 * 8);
                for (uVar12 = uVar10; uVar12 != 0; uVar12 = uVar12 - 1) {
                    *puVar11 = *param_2;
                    param_2 = param_2 + 1;
                    puVar11 = puVar11 + 1;
                }
                for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
                    *(uint8_t*)puVar11 = *(uint8_t*)param_2;
                    param_2 = (uint32_t*)((intptr_t)param_2 + 1);
                    puVar11 = (uint32_t*)((intptr_t)puVar11 + 1);
                }
                puVar11 = (uint32_t*)(*(int32_t*)(iVar6 + 8) + uVar10 * 4);
                for (; uVar10 != 0; uVar10 = uVar10 - 1) {
                    *puVar11 = *param_4;
                    param_4 = param_4 + 1;
                    puVar11 = puVar11 + 1;
                }
                for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
                    *(uint8_t*)puVar11 = *(uint8_t*)param_4;
                    param_4 = (uint32_t*)((intptr_t)param_4 + 1);
                    puVar11 = (uint32_t*)((intptr_t)puVar11 + 1);
                }
                iVar8 = local_c[5];
                iVar2 = *(int32_t*)(iVar8 + **(int32_t**)(iVar6 + 0x10) * 4);
                iVar3 = *(int32_t*)(iVar8 + **(int32_t**)(iVar6 + 8) * 4);
                iVar8 = *(int32_t*)(iVar8 + (*(int32_t**)(iVar6 + 8))[local_14 * 2] * 4);
                iVar4 = *(int32_t*)(iVar2 + 4);
                bVar5 = false;
                if (((((iVar4 == *(int32_t*)(iVar3 + 4)) &&
                       (*(int32_t*)(iVar2 + 0xc) == *(int32_t*)(iVar3 + 0xc))) ||
                      ((iVar4 == *(int32_t*)(iVar8 + 4) &&
                        (*(int32_t*)(iVar2 + 0xc) == *(int32_t*)(iVar8 + 0xc))))) ||
                     (iVar4 != local_c[0x22])) &&
                    ((*(uint8_t*)((intptr_t)local_c + 0x6f) & 2) == 0)) {
                    bVar5 = true;
                }
                iVar8 = ((int32_t (*)(void*, int32_t, int))*(void**)(*(uint32_t*)local_c + 0x20))(
                    self, iVar6, 0);
                if ((iVar8 != 0) ||
                    ((((*(uint8_t*)(*(int32_t*)(local_c[4] + *(int32_t*)(iVar2 + 4) * 4) + 4) &
                        0x20) != 0 ||
                       (bVar5)) &&
                      ((*(uint8_t*)((intptr_t)local_c + 0x6f) & 2) == 0)))) {
                    FUN_00614343(1);
LAB_0069cab6:
                    iVar8 = 1;
                }
                else {
                    iVar8 = FUN_0065d35e(iVar6);
                    if (-1 < iVar8) {
                        FUN_00614343(1);
                        *param_5 = 0;
                        if (local_24[0] != nullptr) {
                            *local_24[0] = 0;
                        }
                        iVar8 = 0;
                    }
                }
            }
        }
    }
    return iVar8;
}

// 0x69cac0 — observed shape
int FUN_0069cac0(void* self, int param_1)
{
    char* s = (char*)self;
    int32_t iVar1;
    uint32_t uVar2;
    uint32_t* puVar3;
    int32_t* piVar4;
    int32_t* piVar5;
    uint32_t uVar6;
    uint32_t uVar7;

    iVar1 = *(int32_t*)(*(uint32_t*)(s + 0x14) + param_1 * 4);
    uVar6 = *(uint32_t*)(iVar1 + 0x54);
    if (((uVar6 != 0xffffffff) && ((*(uint8_t*)(s + 0x6f) & 0x20) == 0)) &&
        (uVar2 = *(uint32_t*)(iVar1 + 0x58), uVar6 <= uVar2)) {
        piVar4 = (int32_t*)(*(uint32_t*)(s + 0x18) + uVar6 * 4);
        do {
            puVar3 = (uint32_t*)*piVar4;
            if ((*puVar3 & 0xf0000000) == 0x60000000) {
                uVar7 = 0;
                if (puVar3[1] != 0) {
                    piVar5 = (int32_t*)puVar3[2];
                    do {
                        if (*piVar5 == param_1) {
                            return 1;
                        }
                        uVar7 = uVar7 + 1;
                        piVar5 = piVar5 + 1;
                    } while (uVar7 < puVar3[1]);
                }
            }
            uVar6 = uVar6 + 1;
            piVar4 = piVar4 + 1;
        } while (uVar6 <= uVar2);
    }
    return 0;
}

// 0x69cb30 — observed shape
int FUN_0069cb30(void* self, int param_1)
{
    char* s = (char*)self;
    int32_t** ppiVar1;
    uint32_t* puVar2;
    int32_t* piVar3;
    int32_t iVar4;
    uint32_t uVar5;
    int32_t iVar6;
    uint32_t uVar7;
    uint32_t* puVar8;
    int32_t* piVar9;
    uint32_t* puVar10;
    int32_t* piVar11;
    bool bVar12;
    int32_t local_118[4];
    uint32_t local_108[4];
    uint32_t local_f8[4];
    int32_t local_e8[28];
    int32_t* local_78[16];
    uint32_t local_38;
    uint32_t local_34;
    uint32_t local_30;
    uint32_t local_2c;
    uint32_t local_28;
    int32_t* local_24;
    uint32_t* local_20;
    int32_t local_1c;
    int32_t* local_18;
    uint32_t local_14;
    uint32_t local_10;
    uint32_t local_c;
    int32_t* local_8;

    local_10 = 0;
    local_38 = 0;
    uVar7 = **(uint32_t**)(s + 0x100) & 0xfffff;
    local_34 = 1;
    local_30 = 2;
    local_2c = 3;
    local_28 = uVar7;
    local_24 = (int32_t*)self;
    iVar4 = FUN_00694b7c((uint32_t*)*(uint32_t**)(s + 0x100), &DAT_006f1980,
                         (void**)local_78, &local_10, local_118, &local_38, uVar7, param_1);
    if ((iVar4 == 0) ||
        ((iVar4 = FUN_00694b7c((uint32_t*)*(uint32_t**)(s + 0x100), &DAT_006f19e0,
                               (void**)local_78, &local_10, local_118, &local_38, uVar7, param_1)),
         iVar4 == 0)) {
        local_14 = 0;
        local_18 = local_118;
        local_20 = local_108;
        do {
            local_c = 0;
            if (uVar7 != 0) {
                local_1c = (*(int32_t*)(s + 0x6c) << 6) >> 0x1f;
                local_8 = local_18;
                do {
                    iVar4 = *(int32_t*)(*(uint32_t*)(s + 0x14) + *local_8 * 4);
                    iVar6 = *(int32_t*)(*(uint32_t*)(s + 0x14) + local_e8[local_c] * 4);
                    if (*(int32_t*)(s + 0x6c) << 6 < 0) {
                        if ((*(uint32_t*)(iVar6 + 0x3c) ^ *(uint32_t*)(iVar4 + 0x3c)) != 0x80000) {
                            break;
                        }
                        bVar12 = *(int32_t*)(iVar6 + 0x38) == *local_8;
                    }
                    else {
                        if ((((*(int32_t*)(iVar4 + 4) != *(int32_t*)(iVar6 + 4)) ||
                              (*(int32_t*)(iVar4 + 8) != *(int32_t*)(iVar6 + 8))) ||
                             (*(int32_t*)(iVar4 + 0xc) != *(int32_t*)(iVar6 + 0xc))) ||
                            (*(int32_t*)(iVar4 + 0x10) != *(int32_t*)(iVar6 + 0x10))) {
                            break;
                        }
                        bVar12 = (*(uint32_t*)(iVar6 + 0x3c) ^ *(uint32_t*)(iVar4 + 0x3c)) == 0x80000;
                    }
                    if (!bVar12) {
                        break;
                    }
                    local_c = local_c + 1;
                    local_8 = local_8 + 1;
                } while (local_c < uVar7);
            }
            if (local_c == uVar7) {
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
                local_8 = (int32_t*)FUN_0065d0ff(uVar7 & 0xfffff | 0x70100000, uVar7 * 3, uVar7, 0);
                if ((int32_t)(intptr_t)local_8 < 0) {
LAB_0069cdf9:
                    FUN_00614343(1);
                    return (int32_t)(intptr_t)local_8;
                }
                local_8 = (int32_t*)FUN_0065cc50(*(uint32_t*)(s + 0x100));
                piVar3 = local_24;
                if ((int32_t)(intptr_t)local_8 < 0) {
                    goto LAB_0069cdf9;
                }
                puVar8 = *(uint32_t**)(*(uint32_t*)(s + 0x100) + 0x10);
                puVar10 = *(uint32_t**)(iVar4 + 0x10);
                for (uVar5 = uVar7 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
                    *puVar10 = *puVar8;
                    puVar8 = puVar8 + 1;
                    puVar10 = puVar10 + 1;
                }
                for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
                    *(uint8_t*)puVar10 = *(uint8_t*)puVar8;
                    puVar8 = (uint32_t*)((intptr_t)puVar8 + 1);
                    puVar10 = (uint32_t*)((intptr_t)puVar10 + 1);
                }
                puVar8 = local_f8;
                puVar10 = *(uint32_t**)(iVar4 + 8);
                for (uVar5 = uVar7 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
                    *puVar10 = *puVar8;
                    puVar8 = puVar8 + 1;
                    puVar10 = puVar10 + 1;
                }
                for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
                    *(uint8_t*)puVar10 = *(uint8_t*)puVar8;
                    puVar8 = (uint32_t*)((intptr_t)puVar8 + 1);
                    puVar10 = (uint32_t*)((intptr_t)puVar10 + 1);
                }
                puVar8 = local_20;
                puVar10 = (uint32_t*)(*(int32_t*)(iVar4 + 8) + uVar7 * 4);
                for (uVar5 = uVar7 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
                    *puVar10 = *puVar8;
                    puVar8 = puVar8 + 1;
                    puVar10 = puVar10 + 1;
                }
                for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
                    *(uint8_t*)puVar10 = *(uint8_t*)puVar8;
                    puVar8 = (uint32_t*)((intptr_t)puVar8 + 1);
                    puVar10 = (uint32_t*)((intptr_t)puVar10 + 1);
                }
                local_c = 0;
                piVar9 = local_e8;
                piVar11 = (int32_t*)(*(int32_t*)(iVar4 + 8) + local_28 * 8);
                for (uVar7 = uVar7 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
                    *piVar11 = *piVar9;
                    piVar9 = piVar9 + 1;
                    piVar11 = piVar11 + 1;
                }
                for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
                    *(char*)piVar11 = (char)*piVar9;
                    piVar9 = (int32_t*)((intptr_t)piVar9 + 1);
                    piVar11 = (int32_t*)((intptr_t)piVar11 + 1);
                }
                iVar6 = local_24[5];
                local_8 = *(int32_t**)(iVar6 + **(int32_t**)(iVar4 + 0x10) * 4);
                puVar2 = *(uint32_t**)(iVar6 + **(int32_t**)(iVar4 + 8) * 4);
                iVar6 = *(int32_t*)(iVar6 + (*(int32_t**)(iVar4 + 8))[local_28 * 2] * 4);
                uVar7 = (uint32_t)local_8[1];
                if (((((uVar7 == puVar2[1]) && (local_8[3] == (int32_t)puVar2[3])) ||
                      ((uVar7 == *(uint32_t*)(iVar6 + 4) &&
                        (local_8[3] == *(int32_t*)(iVar6 + 0xc))))) ||
                     (uVar7 != (uint32_t)local_24[0x22])) &&
                    ((*(uint8_t*)((intptr_t)local_24 + 0x6f) & 2) == 0)) {
                    local_c = 1;
                }
                iVar6 = ((int32_t (*)(void*, int32_t, int))*(void**)(*(uint32_t*)local_24 + 0x20))(
                    self, iVar4, 0);
                if ((iVar6 == 0) &&
                    ((((*(uint8_t*)(*(int32_t*)(piVar3[4] + local_8[1] * 4) + 4) & 0x20) == 0) &&
                      (local_c == 0)) ||
                     ((*(uint8_t*)((intptr_t)piVar3 + 0x6f) & 2) != 0))) {
                    if (param_1 == 0) {
                        local_1c = *local_78[0];
                        *local_78[0] = 0;
                    }
                    if ((((*(uint8_t*)((intptr_t)piVar3 + 0x6f) & 2) != 0) &&
                         ((*(uint8_t*)((intptr_t)puVar2 + 0x3d) & 2) == 0)) &&
                        (((*puVar2 & 4) == 0 || ((*puVar2 & 0x10) == 0)))) {
                        FUN_00614343(1);
                        FUN_0066275f(piVar3, *(uint32_t*)((uintptr_t)piVar3[0x40] + 0x3c), 0x125f,
                                     "cannot match lerp because lerp factor is not _sat'd");
                        *local_78[0] = local_1c;
                        return 1;
                    }
                    if (param_1 == 0) {
                        uVar7 = 0;
                        if (local_10 != 0) {
                            do {
                                ppiVar1 = local_78 + uVar7;
                                uVar7 = uVar7 + 1;
                                **ppiVar1 = 0;
                            } while (uVar7 < local_10);
                        }
                        if (*(int32_t*)(piVar3[6] + piVar3[0x3f] * 4) != 0) {
                            FUN_00614343(1);
                        }
                        *(int32_t*)(piVar3[6] + piVar3[0x3f] * 4) = iVar4;
                    }
                    else {
                        iVar4 = FUN_0065d35e(iVar4);
                        FUN_00614343(1);
                        if (iVar4 < 0) {
                            return iVar4;
                        }
                        iVar4 = FUN_0065cc50(piVar3[0x40]);
                        if (iVar4 < 0) {
                            return iVar4;
                        }
                    }
                    return 0;
                }
                FUN_00614343(1);
                uVar7 = local_28;
                local_24 = (int32_t*)self;
            }
            local_14 = local_14 + 1;
            local_18 = local_18 + 4;
            local_20 = local_20 + -4;
        } while (local_14 < 2);
    }
    return 1;
}

// 0x69ced3 — observed shape
uint32_t FUN_0069ced3(void* self, int param_1, int32_t* param_2, uint32_t param_3, int param_4)
{
    char* s = (char*)self;
    uint32_t* puVar1;
    bool bVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    int32_t* piVar5;
    uint32_t local_c;
    int32_t local_8;

    if (param_3 < 0x1f) {
        if (*(uint32_t*)(s + 0xfc) < *(uint32_t*)(s + 0xc)) {
            do {
                puVar1 = *(uint32_t**)(*(uint32_t*)(s + 0x18) + *(int32_t*)(s + 0xfc) * 4);
                uVar4 = *puVar1 & 0xfff00000;
                if ((uVar4 == 0x73400000) ||
                    ((param_4 != 0 && ((uVar4 == 0x73100000 || (uVar4 == 0x73300000)))))) {
                    break;
                }
                if ((uVar4 == 0x73000000) ||
                    (((uVar4 == 0x73300000 || (uVar4 == 0x73100000)) || (uVar4 == 0x73200000)))) {
                    local_8 = 1;
                    if ((uVar4 == 0x73100000) || (uVar4 == 0x73200000)) {
                        local_8 = 0;
                    }
                    bVar2 = false;
                    if (param_3 != 0) {
                        local_c = param_3;
                        piVar5 = param_2;
                        do {
                            piVar5 = piVar5 + 1;
                            if ((*(int32_t*)puVar1[4] ==
                                 *(int32_t*)((param_1 - (intptr_t)param_2) + (intptr_t)piVar5)) &&
                                (*piVar5 == local_8)) {
                                bVar2 = true;
                            }
                            local_c = local_c - 1;
                        } while (local_c != 0);
                        if (bVar2) {
                            if ((uVar4 == 0x73000000) || (uVar4 == 0x73200000)) {
                                *puVar1 = 0;
                            }
                            else {
                                *puVar1 = 0x73400000;
                            }
                            *(int32_t*)(s + 0xfc) = *(int32_t*)(s + 0xfc) + 1;
                            *(uint32_t*)(param_1 + 4 + param_3 * 4) =
                                *(uint32_t*)(param_1 + param_3 * 4);
                            param_2[param_3 + 1] = param_2[param_3];
                            FUN_0069ced3(self, param_1, param_2, param_3 + 1, 1);
                            puVar1 = *(uint32_t**)(*(uint32_t*)(s + 0x18) +
                                                   *(int32_t*)(s + 0xfc) * 4);
                            uVar4 = *puVar1 & 0xfff00000;
                            if (uVar4 == 0x73400000) {
                                *puVar1 = 0;
                            }
                            else if (uVar4 == 0x73100000) {
                                *puVar1 = 0x73200001;
                            }
                            else if (uVar4 == 0x73300000) {
                                *puVar1 = 0x73000001;
                            }
                            goto LAB_0069d08b;
                        }
                    }
                    if ((uVar4 == 0x73000000) || (uVar4 == 0x73200000)) {
                        *(int32_t*)(s + 0xfc) = *(int32_t*)(s + 0xfc) + 1;
                        *(uint32_t*)(param_1 + 4 + param_3 * 4) = *(uint32_t*)puVar1[4];
                        param_2[param_3 + 1] = local_8;
                        FUN_0069ced3(self, param_1, param_2, param_3 + 1, 0);
                    }
                }
LAB_0069d08b:
                if (*(uint32_t*)(s + 0xc) <= *(uint32_t*)(s + 0xfc)) {
                    return 0x80004005;
                }
                uVar4 = **(uint32_t**)(*(uint32_t*)(s + 0x18) + *(uint32_t*)(s + 0xfc) * 4) &
                        0xfff00000;
                if ((uVar4 == 0x73100000) || (uVar4 == 0x73300000)) {
                    param_2[param_3] = (uint32_t)(param_2[param_3] == 0);
                }
                *(int32_t*)(s + 0xfc) = *(int32_t*)(s + 0xfc) + 1;
            } while (*(uint32_t*)(s + 0xfc) < *(uint32_t*)(s + 0xc));
        }
        uVar3 = 0;
    }
    else {
        uVar3 = 0x80004005;
    }
    return uVar3;
}

// 0x69d0e1 — observed shape
uint32_t FUN_0069d0e1(void* self, uint32_t param_1, uint32_t param_2, int param_3,
                      int32_t* param_4)
{
    char* s = (char*)self;
    uint32_t* puVar1;
    uint32_t uVar2;
    int32_t iVar3;
    uint32_t* puVar4;
    uint32_t uVar5;
    bool bVar6;
    int32_t iVar7;
    int32_t iVar8;
    int32_t iVar9;
    int32_t* piVar10;
    uint32_t local_c;

    if (*(int32_t*)(param_3 + 0x30) == -1) {
        puVar1 = *(uint32_t**)(*(uint32_t*)(s + 0x10) + *(int32_t*)(param_3 + 4) * 4);
        if ((puVar1[1] & 0x800) != 0) {
            param_1 = *puVar1;
        }
        iVar7 = FUN_0065d97c(param_1, puVar1[1] | param_2 | 0x40, 0xffffffff, 4);
        if (iVar7 == -1) {
            return 0x8007000e;
        }
        if ((*(uint8_t*)((intptr_t)puVar1 + 5) & 1) != 0) {
            iVar7 = FUN_0065d9d5((uint32_t)iVar7, *(uint32_t*)(param_3 + 100), 0,
                                 *(uint64_t*)(param_3 + 0x20));
            *(int32_t*)(param_3 + 0x30) = iVar7;
            if (iVar7 == -1) {
                return 0x8007000e;
            }
            *param_4 = iVar7;
            FUN_0065d5bd();
            return 0;
        }
        uVar2 = *(uint32_t*)(s + 8);
        bVar6 = false;
        param_1 = 0;
        if (uVar2 != 0) {
            do {
                iVar3 = *(int32_t*)(*(uint32_t*)(s + 0x14) + param_1 * 4);
                if (((((*(int32_t*)(iVar3 + 4) == *(int32_t*)(param_3 + 4)) &&
                       (*(int32_t*)(iVar3 + 0x60) == *(int32_t*)(param_3 + 0x60))) &&
                      (*(int32_t*)(iVar3 + 0x60) != 0)) &&
                     (*(int32_t*)(iVar3 + 8) == -1)) ||
                    (param_3 == iVar3)) {
                    iVar8 = FUN_0065d9d5((uint32_t)iVar7, *(uint32_t*)(iVar3 + 100), 0,
                                         *(uint64_t*)(iVar3 + 0x20));
                    *(int32_t*)(iVar3 + 0x30) = iVar8;
                    if (iVar8 == -1) {
                        return 0x8007000e;
                    }
                    iVar8 = *(int32_t*)(*(uint32_t*)(s + 0x14) + iVar8 * 4);
                    FUN_0065d5bd();
                    *(int32_t*)(iVar8 + 0x70) = *(int32_t*)(iVar8 + 100) << 2;
                    if (*(int32_t*)(iVar3 + 0x44) != -1) {
                        bVar6 = true;
                    }
                }
                param_1 = param_1 + 1;
            } while (param_1 < uVar2);
        }
        iVar7 = *(int32_t*)(s + 0xe0);
        if ((iVar7 != 0) && (bVar6)) {
            if ((param_2 & 0x2000) == 0) {
                iVar7 = *(int32_t*)(iVar7 + 0xb8);
            }
            else {
                iVar7 = *(int32_t*)(iVar7 + 0xb4);
            }
            if (iVar7 == -1) {
                return 0x8007000e;
            }
            local_c = 0;
            if (uVar2 != 0) {
                do {
                    iVar3 = *(int32_t*)(*(uint32_t*)(s + 0x14) + local_c * 4);
                    if ((((*(int32_t*)(iVar3 + 4) == *(int32_t*)(param_3 + 4)) &&
                          (*(int32_t*)(iVar3 + 0x60) == *(int32_t*)(param_3 + 0x60))) &&
                         ((*(int32_t*)(iVar3 + 0x60) != 0 && (*(int32_t*)(iVar3 + 8) == -1)))) ||
                        (param_3 == iVar3)) {
                        iVar8 = FUN_0065d9d5((uint32_t)iVar7, *(uint32_t*)(iVar3 + 100), 0,
                                             *(uint64_t*)(iVar3 + 0x20));
                        if (iVar8 == -1) {
                            return 0x8007000e;
                        }
                        if (*(int32_t*)(iVar3 + 0x44) != -1) {
                            iVar9 = *(int32_t*)(*(int32_t*)(*(int32_t*)(*(uint32_t*)(s + 0xe0) +
                                                                      0x14) +
                                                           *(int32_t*)(iVar3 + 0x44) * 4) + 0x48);
                            if ((iVar9 != -1) &&
                                (puVar4 = *(uint32_t**)(*(int32_t*)(*(uint32_t*)(s + 0xe0) + 0x18) +
                                                        iVar9 * 4),
                                 (*puVar4 & 0xfff00000) == 0x10000000)) {
                                param_2 = 0;
                                if (puVar4[3] != 0) {
                                    piVar10 = (int32_t*)puVar4[4];
                                    do {
                                        if (*piVar10 == *(int32_t*)(iVar3 + 0x44)) break;
                                        param_2 = param_2 + 1;
                                        piVar10 = piVar10 + 1;
                                    } while (param_2 < puVar4[3]);
                                }
                                uVar5 = *(uint32_t*)(puVar4[2] + param_2 * 4);
                                iVar9 = FUN_0065da35(0x10000001, 1, 1);
                                if (iVar9 == -1) {
                                    return 0x8007000e;
                                }
                                iVar9 = *(int32_t*)(*(int32_t*)(*(uint32_t*)(s + 0xe0) + 0x18) +
                                                    iVar9 * 4);
                                FUN_0065cc50();
                                **(int32_t**)(iVar9 + 0x10) = iVar8;
                                **(uint32_t**)(iVar9 + 8) = uVar5;
                                *(int32_t*)(*(int32_t*)(*(uint32_t*)(s + 0x14) +
                                                        *(int32_t*)(iVar3 + 0x30) * 4) +
                                            0x44) = iVar8;
                            }
                        }
                    }
                    local_c = local_c + 1;
                } while (local_c < uVar2);
            }
        }
    }
    *param_4 = *(int32_t*)(param_3 + 0x30);
    return 0;
}

// 0x69d37b — observed shape
uint32_t FUN_0069d37b(void* self, uint32_t param_1, uint32_t param_2)
{
    char* s = (char*)self;
    uint32_t* puVar1;
    uint32_t uVar2;

    uVar2 = *(uint32_t*)(*(int32_t*)(s + 0x18) + param_2 * 4);
    if (param_2 < param_1) {
        do {
            puVar1 = (uint32_t*)(*(int32_t*)(s + 0x18) + param_2 * 4);
            param_2 = param_2 + 1;
            *puVar1 = puVar1[1];
        } while (param_2 < param_1);
    }
    else {
        for (; param_1 < param_2; param_2 = param_2 - 1) {
            puVar1 = (uint32_t*)(*(int32_t*)(s + 0x18) + param_2 * 4);
            *puVar1 = puVar1[-1];
        }
    }
    *(uint32_t*)(*(int32_t*)(s + 0x18) + param_1 * 4) = uVar2;
    return 0;
}

// NEEDS_MANUAL: 0x69d3c8 masks with a decompiler register artifact (extraout_EDX) whose
// concrete value is not derivable from the listing; all other operations are observed.
// 0x69d3c8 — observed shape
int32_t FUN_0069d3c8(void* self, int32_t param_1, uint32_t* param_2, uint32_t param_3,
                     uint32_t param_4, uint32_t param_5, int32_t param_6)
{
    char* s = (char*)self;
    uint32_t* puVar1;
    uint32_t uVar2;
    int32_t iVar3;
    int32_t iVar4;
    uint32_t uVar5;
    uint32_t extraout_EDX; // decompiler register artifact, not a data operand
    int32_t* piVar6;
    uint32_t* puVar7;
    uint32_t* puVar8;
    uint32_t local_18;
    int32_t local_14;
    int32_t local_c;
    uint32_t local_8;

    iVar3 = 1;
    local_14 = 1;
    if (param_4 != 0) {
        puVar1 = *(uint32_t**)(*(int32_t*)(s + 0x18) + -4 + (int32_t)param_4 * 4);
        iVar3 = FUN_0065cea4();
        if (((iVar3 == 0) && (uVar5 = *puVar1, (uVar5 & 0xf0000000) != 0x60000000)) &&
            (iVar3 = local_14, uVar2 = param_4, (uVar5 & 0xfff00000) != 0x11000000)) {
            while ((uVar2 = uVar2 - 1, -1 < (int32_t)uVar2)) {
                puVar1 = *(uint32_t**)(*(int32_t*)(s + 0x18) + (int32_t)uVar2 * 4);
                if (puVar1[9] != param_4) {
                    uVar5 = *puVar1 & 0xfff00000;
                    if (uVar5 != 0) {
                        if ((*puVar1 & 0xf0000000) == 0x60000000) {
                            return iVar3;
                        }
                        if (uVar5 == 0x11000000) {
                            return iVar3;
                        }
                        FUN_006951ca((void*)(uintptr_t)param_3, puVar1, param_4);
                        local_c = 0;
                        local_8 = (uint32_t)((*puVar1 & extraout_EDX) == 0x50000000);
                        local_18 = puVar1[3];
                        if (local_18 != 0) {
                            piVar6 = (int32_t*)puVar1[4];
                            do {
                                iVar4 = *(int32_t*)(*(int32_t*)(s + 0x14) + *piVar6 * 4);
                                if (*(int32_t*)(s + 0x6c) << 3 < 0) {
                                    iVar4 = *(int32_t*)(iVar4 + 0x10);
                                }
                                else {
                                    iVar4 = *(int32_t*)(*(int32_t*)(param_1 + 0x14) +
                                                        (*(int32_t*)(iVar4 + 0x10) +
                                                         *(int32_t*)(iVar4 + 0xc) * 4) * 4);
                                }
                                if (iVar4 == 3) {
                                    local_c = 1;
                                }
                                else {
                                    local_8 = 1;
                                }
                                piVar6 = piVar6 + 1;
                                local_18 = local_18 - 1;
                            } while (local_18 != 0);
                        }
                        if ((local_8 != param_5) && (local_c != param_6)) {
                            iVar3 = FUN_0069d37b(self, param_4 - 1, uVar2);
                            if (iVar3 < 0) {
                                return iVar3;
                            }
                            if ((*(uint8_t*)(s + 0x6f) & 0x10) != 0) {
                                return 0;
                            }
                            iVar4 = FUN_0066a65b((void*)(uintptr_t)param_1, 0);
                            if (-1 < iVar4) {
                                local_18 = puVar1[3];
                                if (local_18 != 0) {
                                    piVar6 = (int32_t*)puVar1[4];
                                    do {
                                        iVar4 = *(int32_t*)(*(int32_t*)(s + 0x14) + *piVar6 * 4);
                                        if (*(int32_t*)(*(int32_t*)(param_1 + 0x14) +
                                                        (*(int32_t*)(iVar4 + 0x10) +
                                                         *(int32_t*)(iVar4 + 0xc) * 4) * 4) == 3) {
                                            local_c = 1;
                                        }
                                        else {
                                            local_8 = 1;
                                        }
                                        piVar6 = piVar6 + 1;
                                        local_18 = local_18 - 1;
                                    } while (local_18 != 0);
                                }
                                if ((local_8 != param_5) && (local_c != param_6)) {
                                    return 0;
                                }
                            }
                            puVar7 = param_2;
                            puVar8 = *(uint32_t**)(s + 0x18);
                            for (uVar5 = *(uint32_t*)(s + 0xc) & 0x3fffffff; uVar5 != 0;
                                 uVar5 = uVar5 - 1) {
                                *puVar8 = *puVar7;
                                puVar7 = puVar7 + 1;
                                puVar8 = puVar8 + 1;
                            }
                            for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
                                *(uint8_t*)puVar8 = *(uint8_t*)puVar7;
                                puVar7 = (uint32_t*)((intptr_t)puVar7 + 1);
                                puVar8 = (uint32_t*)((intptr_t)puVar8 + 1);
                            }
                        }
                    }
                }
            }
        }
        else {
            iVar3 = 1;
        }
    }
    return iVar3;
}

// 0x69d5c4 — observed shape
int32_t FUN_0069d5c4(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3,
                     uint32_t param_4, uint32_t param_5, int32_t param_6)
{
    char* s = (char*)self;
    uint32_t uVar1;
    uint32_t* puVar2;
    int32_t iVar3;
    int32_t iVar4;

    if (param_5 != 0) {
        puVar2 = *(uint32_t**)(*(int32_t*)(s + 0x18) + -4 + (int32_t)param_5 * 4);
        iVar4 = FUN_0065cea4();
        if ((iVar4 == 0) && (uVar1 = param_5, (*puVar2 & 0xf0000000) != 0x60000000)) {
            while (uVar1 != 0) {
                uVar1 = uVar1 - 1;
                puVar2 = *(uint32_t**)(*(int32_t*)(s + 0x18) + (int32_t)uVar1 * 4);
                if ((puVar2[9] != param_5) && ((*puVar2 & 0xfff00000) != 0)) {
                    if ((*puVar2 & 0xf0000000) == 0x60000000) {
                        return 1;
                    }
                    iVar4 = FUN_0065cea4();
                    if (iVar4 != 0) {
                        return 1;
                    }
                    FUN_006951ca((void*)(uintptr_t)param_4, puVar2, param_5);
                    iVar4 = *(int32_t*)(*(int32_t*)(s + 0x18) + -4 + (int32_t)param_5 * 4);
                    iVar3 = *(int32_t*)(*(int32_t*)(s + 0x18) + (int32_t)uVar1 * 4);
                    if ((*(int32_t*)(iVar4 + 0xc) != 0) && (*(int32_t*)(iVar3 + 0xc) != 0)) {
                        iVar4 = *(int32_t*)(*(int32_t*)(s + 0x14) +
                                            **(int32_t**)(iVar4 + 0x10) * 4);
                        iVar3 = *(int32_t*)(*(int32_t*)(s + 0x14) +
                                            **(int32_t**)(iVar3 + 0x10) * 4);
                        if (*(int32_t*)(iVar4 + 0x14) != *(int32_t*)(iVar3 + 0x14)) {
                            return 1;
                        }
                        if (*(int32_t*)(iVar4 + 0x18) != *(int32_t*)(iVar3 + 0x18)) {
                            return 1;
                        }
                        FUN_0069d37b(self, param_5 - 1, uVar1);
                        if ((((*(uint8_t*)(s + 0x6f) & 0x10) != 0) ||
                             (iVar4 = FUN_0066a65b((void*)(uintptr_t)param_1, 0), -1 < iVar4)) &&
                            ((param_6 == 0 ||
                              (iVar4 = FUN_0066a65b((void*)(uintptr_t)param_2, 0), -1 < iVar4)))) {
                            return 0;
                        }
                        FUN_0069d37b(self, uVar1, param_5 - 1);
                        FUN_006951ca((void*)(uintptr_t)param_4, puVar2, param_5);
                    }
                }
            }
        }
    }
    return 1;
}

// 0x69d701 — observed shape
int FUN_0069d701(void* self)
{
    char* s = (char*)self;
    uint8_t bVar1;
    uint32_t* puVar2;
    int32_t iVar3;
    int32_t* piVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    uint32_t* puVar7;
    uint32_t* puVar8;
    uint32_t uVar9;
    uint32_t uVar10;
    uint32_t local_ec[25];
    int32_t local_88[25]; // stack slot local_74 is local_88[5]; the 25-word clear covers it
    uint32_t local_24;
    uint32_t local_20;
    uint32_t local_1c;
    uint32_t local_18;
    uint32_t local_14;
    uint32_t* local_10;
    uint32_t* local_c;
    uint32_t local_8;

    if ((*(uint8_t*)(s + 0xcc) & 4) != 0) {
        return 1;
    }
    iVar3 = FUN_0065e4f2();
    if (iVar3 < 0) {
        return iVar3;
    }
    iVar3 = FUN_00662317();
    if (iVar3 < 0) {
        return iVar3;
    }
    uVar5 = *(uint32_t*)(s + 0xc);
    local_c = (uint32_t*)0;
    local_10 = (uint32_t*)0;
    local_20 = 0;
    bVar1 = *(uint8_t*)(s + 0x6f);
    piVar4 = local_88;
    for (iVar3 = 0x19; iVar3 != 0; iVar3 = iVar3 + -1) {
        *piVar4 = 0;
        piVar4 = piVar4 + 1;
    }
    puVar7 = local_ec;
    local_18 = uVar5;
    for (iVar3 = 0x19; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
    }
    if ((bVar1 & 0x10) == 0) {
        if (*(int32_t*)(s + 0x30) != 0) {
            iVar3 = FUN_00669f90(local_ec, *(uint32_t*)(s + 0x8c), *(int32_t*)(s + 0x30));
            if (iVar3 < 0) goto LAB_0069da25;
            iVar3 = FUN_0066a65b(local_ec, 0);
            local_20 = (uint32_t)(-1 < iVar3);
        }
        iVar3 = FUN_00669f90(local_88, *(uint32_t*)(s + 0x88), *(int32_t*)(s + 0x2c) + -1);
        if ((iVar3 < 0) || (iVar3 = FUN_0066a65b(local_88, 0), iVar3 < 0)) {
            FUN_00661cb0(local_88);
            iVar3 = FUN_00669f90(local_88, *(uint32_t*)(s + 0x88), *(uint32_t*)(s + 0x2c));
            if ((iVar3 < 0) || (iVar3 = FUN_0066a65b(local_88, 0), iVar3 < 0)) {
                if (iVar3 != -0x7ff8fff2) {
                    iVar3 = 1;
                }
                goto LAB_0069da25;
            }
        }
    }
    uVar6 = uVar5 << 2;
    local_14 = uVar6;
    local_c = (uint32_t*)FUN_00533c78(uVar6);
    if ((local_c == (uint32_t*)0) ||
        (local_10 = (uint32_t*)FUN_00533c78(uVar6), local_10 == (uint32_t*)0)) {
        iVar3 = -0x7ff8fff2;
    }
    else {
        puVar7 = *(uint32_t**)(s + 0x18);
        puVar8 = local_10;
        for (uVar5 = uVar5 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
        }
        for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
            *(uint8_t*)puVar8 = *(uint8_t*)puVar7;
            puVar7 = (uint32_t*)((intptr_t)puVar7 + 1);
            puVar8 = (uint32_t*)((intptr_t)puVar8 + 1);
        }
        puVar7 = *(uint32_t**)(s + 0x18);
        puVar8 = local_c;
        for (uVar5 = local_14 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
        }
        for (uVar5 = local_14 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(uint8_t*)puVar8 = *(uint8_t*)puVar7;
            puVar7 = (uint32_t*)((intptr_t)puVar7 + 1);
            puVar8 = (uint32_t*)((intptr_t)puVar8 + 1);
        }
        uVar5 = 0;
        local_8 = local_18;
        if (local_18 != 0) {
            do {
                iVar3 = *(int32_t*)(*(int32_t*)(s + 0x18) + uVar5 * 4);
                *(int32_t*)(s + 0x100) = iVar3;
                *(uint32_t*)(iVar3 + 0x24) = 0xffffffff;
                uVar5 = uVar5 + 1;
            } while (uVar5 < local_18);
        }
joined_r0x0069d8b7:
        uVar5 = local_8 - 1;
        local_8 = uVar5;
        if (-1 < (int32_t)uVar5) {
            puVar2 = *(uint32_t**)(*(int32_t*)(s + 0x18) + uVar5 * 4);
            *(uint32_t**)(s + 0x100) = puVar2;
            uVar6 = *puVar2;
            if (((((uVar6 & 0xfff00000) != 0) && ((uVar6 & 0xf0000000) != 0x60000000)) &&
                 (iVar3 = FUN_0065cea4(), iVar3 == 0)) &&
                ((**(uint32_t**)(s + 0x100) & 0xfff00000) != 0x11000000)) {
                FUN_006951ca(local_10, *(uint32_t**)(s + 0x100), uVar5);
                if ((*(uint8_t*)(s + 0x70) & 8) == 0) {
                    iVar3 = FUN_0069d5c4(self, (uint32_t)(uintptr_t)local_88,
                                         (uint32_t)(uintptr_t)local_ec, (uint32_t)(uintptr_t)local_c,
                                         (uint32_t)(uintptr_t)local_10, uVar5, (int32_t)local_20);
                }
                else {
                    puVar2 = *(uint32_t**)(s + 0x100);
                    local_18 = 0;
                    local_1c = (uint32_t)((*puVar2 & 0xfff00000) == 0x50000000);
                    if (puVar2[3] != 0) {
                        local_24 = *(uint32_t*)(*(int32_t*)(s + 0x100) + 0xc);
                        piVar4 = (int32_t*)puVar2[4];
                        do {
                            iVar3 = *(int32_t*)(*(int32_t*)(s + 0x14) + *piVar4 * 4);
                            if ((*(int32_t*)(s + 0x6c) << 3 < 0) ||
                                (local_88[0] != *(int32_t*)(iVar3 + 4))) {
                                iVar3 = *(int32_t*)(iVar3 + 0x10);
                            }
                            else {
                                iVar3 = *(int32_t*)(local_88[5] +
                                                    (*(int32_t*)(iVar3 + 0x10) +
                                                     *(int32_t*)(iVar3 + 0xc) * 4) * 4);
                            }
                            if (iVar3 == 3) {
                                local_18 = 1;
                            }
                            else {
                                local_1c = 1;
                            }
                            piVar4 = piVar4 + 1;
                            local_24 = local_24 + -1;
                        } while (local_24 != 0);
                    }
                    if (local_1c == 0) {
                        uVar10 = 1;
                        uVar9 = 0;
                    }
                    else {
                        if (local_18 != 0) goto joined_r0x0069d8b7;
                        uVar10 = 0;
                        uVar9 = 1;
                    }
                    iVar3 = FUN_0069d3c8(self, (int32_t)(intptr_t)local_88,
                                         (uint32_t*)(uintptr_t)local_c,
                                         (uint32_t)(uintptr_t)local_10, local_8, uVar9, uVar10);
                }
                if (iVar3 < 0) goto LAB_0069da25;
                if (iVar3 == 0) {
                    local_8 = local_8 - 1;
                    puVar7 = *(uint32_t**)(s + 0x18);
                    puVar8 = local_c;
                    for (uVar5 = local_14 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                        *puVar8 = *puVar7;
                        puVar7 = puVar7 + 1;
                        puVar8 = puVar8 + 1;
                    }
                    for (uVar5 = local_14 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
                        *(uint8_t*)puVar8 = *(uint8_t*)puVar7;
                        puVar7 = (uint32_t*)((intptr_t)puVar7 + 1);
                        puVar8 = (uint32_t*)((intptr_t)puVar8 + 1);
                    }
                }
            }
            goto joined_r0x0069d8b7;
        }
        iVar3 = 0;
    }
LAB_0069da25:
    if (((*(uint8_t*)(s + 0x6f) & 0x10) == 0) &&
        (FUN_00661cb0(local_88), *(int32_t*)(s + 0x30) != 0)) {
        FUN_00661cb0(local_ec);
    }
    operator_delete(local_10);
    operator_delete(local_c);
    return iVar3;
}

// 0x69da66 — observed shape
uint32_t FUN_0069da66(int32_t param_1)
{
    uint32_t uVar1;

    if ((((param_1 == 0x73500000) || (param_1 == 0x73600000)) || (param_1 == 0x73700000)) ||
        ((param_1 == 0x73800000 || (param_1 == 0x10f00000)))) {
        uVar1 = 1;
    }
    else {
        uVar1 = 0;
    }
    return uVar1;
}

// 0x69da9c — observed shape
uint32_t FUN_0069da9c(int32_t param_1)
{
    uint32_t uVar1;

    if ((((param_1 == 0x74700000) || (param_1 == 0x74600000)) || (param_1 == 0x74400000)) ||
        ((param_1 == 0x74500000 || (param_1 == 0x74300000)))) {
        uVar1 = 1;
    }
    else {
        uVar1 = 0;
    }
    return uVar1;
}

// 0x69dad2 — observed shape
int FUN_0069dad2(void* self, uint32_t* param_1, int param_2)
{
    char* s = (char*)self;
    int32_t iVar1;
    bool bVar2;
    char* pcVar3;
    int32_t iVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    int32_t* piVar7;
    uint32_t uVar8;
    uint32_t uVar9;
    uint32_t* puVar10;
    uint32_t* puVar11;
    int32_t local_8;

    bVar2 = false;
    uVar6 = *param_1 & 0xfffff;
    uVar8 = *param_1 & 0xfff00000;
    if (param_2 == 0) {
        if (uVar8 != 0x10f00000) {
            if (uVar8 == 0x73500000) {
                uVar9 = uVar6 | 0x73d00000;
            }
            else if (uVar8 == 0x73600000) {
                uVar9 = uVar6 | 0x73e00000;
            }
            else if (uVar8 == 0x73700000) {
                uVar9 = uVar6 | 0x73f00000;
            }
            else {
                if (uVar8 != 0x73800000) {
                    return 0;
                }
                uVar9 = uVar6 | 0x74000000;
            }
            goto LAB_0069dd03;
        }
        puVar10 = *(uint32_t**)(*(int32_t*)(s + 0x10) +
                                *(int32_t*)(*(int32_t*)(*(int32_t*)(s + 0x14) +
                                                        *(int32_t*)(uintptr_t)param_1[2] * 4) + 4) *
                                    4);
        uVar9 = uVar6 | 0x73100000;
        if ((((*(uint16_t*)(puVar10 + 1) & 0x208) != 0) &&
             ((((char*)(uintptr_t)*puVar10 == nullptr) ||
               (pcVar3 = strchr((char*)(uintptr_t)*puVar10, 0x69), pcVar3 != nullptr)) ||
              (pcVar3 = strchr((char*)(uintptr_t)*puVar10, 0x49), pcVar3 != nullptr) ||
              ((pcVar3 = strchr((char*)(uintptr_t)*puVar10, 0x62), pcVar3 != nullptr) ||
               (pcVar3 = strchr((char*)(uintptr_t)*puVar10, 0x42), pcVar3 != nullptr)) ||
              ((*(uint8_t*)((intptr_t)puVar10 + 5) & 8) == 0))) &&
            (*(int32_t*)(*(int32_t*)(*(int32_t*)(s + 0x14) +
                                     *(int32_t*)(uintptr_t)param_1[2] * 4) + 8) == -1)) {
            goto LAB_0069dd03;
        }
        uVar9 = uVar6 | 0x73f00000;
    }
    else {
        if (uVar8 != 0x10f00000) {
            if (uVar8 == 0x73500000) {
                uVar9 = uVar6 | 0x73900000;
            }
            else if (uVar8 == 0x73600000) {
                uVar9 = uVar6 | 0x73a00000;
            }
            else if (uVar8 == 0x73700000) {
                uVar9 = uVar6 | 0x73b00000;
            }
            else {
                if (uVar8 != 0x73800000) {
                    return 0;
                }
                uVar9 = uVar6 | 0x73c00000;
            }
            goto LAB_0069dd03;
        }
        puVar10 = *(uint32_t**)(*(int32_t*)(s + 0x10) +
                                *(int32_t*)(*(int32_t*)(*(int32_t*)(s + 0x14) +
                                                        *(int32_t*)(uintptr_t)param_1[2] * 4) + 4) *
                                    4);
        uVar9 = uVar6 | 0x73000000;
        if ((((*(uint16_t*)(puVar10 + 1) & 0x208) != 0) &&
             ((((char*)(uintptr_t)*puVar10 == nullptr) ||
               (pcVar3 = strchr((char*)(uintptr_t)*puVar10, 0x69), pcVar3 != nullptr)) ||
              ((pcVar3 = strchr((char*)(uintptr_t)*puVar10, 0x49), pcVar3 != nullptr) ||
               (((pcVar3 = strchr((char*)(uintptr_t)*puVar10, 0x62), pcVar3 != nullptr) ||
                 (pcVar3 = strchr((char*)(uintptr_t)*puVar10, 0x42), pcVar3 != nullptr)) ||
                ((*(uint8_t*)((intptr_t)puVar10 + 5) & 8) == 0))))) &&
            (*(int32_t*)(*(int32_t*)(*(int32_t*)(s + 0x14) +
                                     *(int32_t*)(uintptr_t)param_1[2] * 4) + 8) == -1)) {
            goto LAB_0069dd03;
        }
        uVar9 = uVar6 | 0x73b00000;
    }
    bVar2 = true;
LAB_0069dd03:
    iVar4 = FUN_0065d0b4();
    if (iVar4 == 0) {
        local_8 = 0;
    }
    else {
        local_8 = FUN_0065cc1a();
    }
    if (local_8 != 0) {
        if ((uVar8 != 0x10f00000) || (bVar2)) {
            uVar8 = uVar6 * 2;
        }
        else {
            uVar8 = uVar6;
        }
        iVar4 = FUN_0065d0ff(uVar9, uVar8, uVar6);
        if (-1 < iVar4) {
            iVar4 = FUN_0065cc50();
            if (-1 < iVar4) {
                if (param_2 == 0) {
                    uVar5 = (uint32_t)FUN_0065d9d5(*(uint32_t*)(s + 0xa8), 0, 0, 0);
                    **(uint32_t**)(local_8 + 0x10) = uVar5;
                    if (**(int32_t**)(local_8 + 0x10) == -1) {
                        return 0;
                    }
                    iVar4 = *(int32_t*)(*(int32_t*)(s + 0x14) +
                                        **(int32_t**)(local_8 + 0x10) * 4);
                    iVar1 = *(int32_t*)(*(int32_t*)(s + 0x14) +
                                        *(int32_t*)(uintptr_t)param_1[4] * 4);
                    *(uint32_t*)(iVar4 + 0x18) = *(uint32_t*)(iVar1 + 0x18);
                    *(uint32_t*)(iVar4 + 0x14) = *(uint32_t*)(iVar1 + 0x14);
                }
                else {
                    puVar10 = (uint32_t*)(uintptr_t)param_1[4];
                    puVar11 = *(uint32_t**)(local_8 + 0x10);
                    for (uVar6 = param_1[3] & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {
                        *puVar11 = *puVar10;
                        puVar10 = puVar10 + 1;
                        puVar11 = puVar11 + 1;
                    }
                    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
                        *(uint8_t*)puVar11 = *(uint8_t*)puVar10;
                        puVar10 = (uint32_t*)((intptr_t)puVar10 + 1);
                        puVar11 = (uint32_t*)((intptr_t)puVar11 + 1);
                    }
                }
                puVar10 = (uint32_t*)(uintptr_t)param_1[2];
                puVar11 = *(uint32_t**)(local_8 + 8);
                for (uVar6 = param_1[1] & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {
                    *puVar11 = *puVar10;
                    puVar10 = puVar10 + 1;
                    puVar11 = puVar11 + 1;
                }
                for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
                    *(uint8_t*)puVar11 = *(uint8_t*)puVar10;
                    puVar10 = (uint32_t*)((intptr_t)puVar10 + 1);
                    puVar11 = (uint32_t*)((intptr_t)puVar11 + 1);
                }
                if (!bVar2) {
                    return local_8;
                }
                param_1 = (uint32_t*)0;
                if (*(int32_t*)(s + 8) != 0) {
                    piVar7 = *(int32_t**)(s + 0x14);
                    iVar4 = *(int32_t*)(s + 8);
                    do {
                        if (((*(uint8_t*)(*(int32_t*)(*(int32_t*)(s + 0x10) +
                                                     *(int32_t*)(*piVar7 + 4) * 4) + 5) & 1) != 0) &&
                            (uVar6 = *(uint32_t*)(*piVar7 + 0xc),
                             (uint32_t)(uintptr_t)param_1 <= uVar6)) {
                            param_1 = (uint32_t*)(uintptr_t)(uVar6 + 1);
                        }
                        piVar7 = piVar7 + 1;
                        iVar4 = iVar4 + -1;
                    } while (iVar4 != 0);
                }
                if (*(int32_t*)(s + 0x188) == -1) {
                    uVar5 = (uint32_t)FUN_0065d9d5(*(uint32_t*)(s + 0x78),
                                                   (uint32_t)(uintptr_t)param_1, 0, 0);
                    *(uint32_t*)(s + 0x188) = uVar5;
                }
                if (*(int32_t*)(s + 0x188) != -1) {
                    *(int32_t*)(*(int32_t*)(local_8 + 8) + 4) = *(int32_t*)(s + 0x188);
                    return local_8;
                }
            }
        }
        FUN_00614343();
    }
    return 0;
}

// 0x69de84 — observed shape
uint32_t FUN_0069de84(void* self)
{
    char* s = (char*)self;
    uint32_t* puVar1;
    int32_t iVar2;
    int32_t iVar3;
    bool bVar4;
    bool bVar5;
    int32_t iVar6;
    uint32_t uVar7;
    uint32_t local_18;
    uint32_t local_14;
    uint32_t local_10;
    int32_t* local_8;

    do {
        bVar5 = false;
        local_10 = 0;
        if (*(int32_t*)(s + 0xc) == 0) {
            return 0;
        }
        do {
            iVar6 = FUN_0065ce50();
            if (iVar6 != 0) {
                local_18 = local_10 + 1;
                bVar4 = true;
                if (local_18 < *(uint32_t*)(s + 0xc)) {
                    do {
                        puVar1 = *(uint32_t**)(*(int32_t*)(s + 0x18) + local_18 * 4);
                        iVar6 = FUN_0065ce88();
                        if (iVar6 != 0) break;
                        if ((*puVar1 & 0xfff00000) != 0x10000000) {
                            bVar4 = false;
                            break;
                        }
                        local_14 = puVar1[3];
                        if (local_14 != 0) {
                            local_8 = (int32_t*)puVar1[2];
                            iVar6 = (int32_t)(puVar1[4] - (uintptr_t)local_8);
                            do {
                                iVar2 = *(int32_t*)(*(int32_t*)(s + 0x14) +
                                                    *(int32_t*)(iVar6 +
                                                                (intptr_t)local_8) * 4);
                                iVar3 = *(int32_t*)(*(int32_t*)(s + 0x14) + *local_8 * 4);
                                if ((((*(int32_t*)(iVar2 + 0x38) != *(int32_t*)(iVar3 + 0x38)) ||
                                      (*(int32_t*)(iVar2 + 0x3c) != *(int32_t*)(iVar3 + 0x3c))) ||
                                     (*(int32_t*)(iVar2 + 4) != *(int32_t*)(iVar3 + 4))) ||
                                    (((*(int32_t*)(iVar2 + 0xc) != *(int32_t*)(iVar3 + 0xc) ||
                                       (*(int32_t*)(iVar2 + 8) != *(int32_t*)(iVar3 + 8))) ||
                                      (*(int32_t*)(iVar2 + 0x10) != *(int32_t*)(iVar3 + 0x10))))) {
                                    bVar4 = false;
                                }
                                local_8 = local_8 + 1;
                                local_14 = local_14 - 1;
                            } while (local_14 != 0);
                        }
                        local_18 = local_18 + 1;
                    } while (local_18 < *(uint32_t*)(s + 0xc));
                    if (!bVar4) goto LAB_0069df9c;
                }
                bVar5 = true;
                uVar7 = local_10;
                if (local_10 < *(uint32_t*)(s + 0xc)) {
                    do {
                        iVar6 = FUN_0065ce88();
                        if (iVar6 != 0) break;
                        **(uint32_t**)(*(int32_t*)(s + 0x18) + uVar7 * 4) = 0;
                        uVar7 = uVar7 + 1;
                    } while (uVar7 < *(uint32_t*)(s + 0xc));
                }
            }
LAB_0069df9c:
            local_10 = local_10 + 1;
        } while (local_10 < *(uint32_t*)(s + 0xc));
        if (!bVar5) {
            return 0;
        }
    } while (true);
}
