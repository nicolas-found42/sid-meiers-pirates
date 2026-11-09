// UNVERIFIED decompiler-derived reconstruction — batch mass_0328.
// Sources: analysis/pseudocode/functions/*.c (Ghidra 12.2 pseudocode).
// Receivers exposed as in_ECX are translated to an explicit `self` parameter.
#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <windows.h>

// ---------------------------------------------------------------------------
// Referenced helpers (declared only; no definitions in this batch).
// ---------------------------------------------------------------------------
extern void __cdecl operator_delete(void* p);

extern void FUN_006a0238(void);
extern void FUN_006a0152(void);
extern void FUN_006a3d1c(void);
extern void FUN_00696278(void);
extern void FUN_006959c5(void);
extern void FUN_006626da(...); // error reporter, called with 0 or 4 arguments
extern void FUN_00614343(int32_t flag);
extern int32_t FUN_00673e38(uint32_t* a, const uint32_t* b);
extern int32_t FUN_0065d0b4(uint32_t size);
extern int32_t FUN_0065cc1a(void);
extern int32_t FUN_0065d0ff(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
extern int32_t FUN_0065cc50(uint32_t obj);
extern int32_t FUN_0065d8c2(int32_t obj);
extern int32_t FUN_0065db2e(uint32_t* obj);
extern uint32_t* FUN_0069e83f(uint32_t id, uint32_t* blob, int32_t* out, int32_t a, int32_t b);
extern uint32_t* FUN_006a3cac(int32_t idx);
extern int32_t FUN_0061273f(const char* name, uint32_t flags, int32_t count);
extern void* FUN_00533c78(int32_t nbytes);
extern int32_t FUN_006a48dd(int32_t a);
extern int32_t FUN_006a2b66(uint32_t a);
extern int32_t FUN_0069fcf5(void);
extern int32_t FUN_006a4aab(...);
extern int32_t FUN_006a6375(int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
extern int32_t FUN_00695e74(void);
extern int32_t FUN_006992d0(void);
extern int32_t FUN_0069632a(void);
extern int32_t FUN_0065e4f2(void);
extern int32_t FUN_006a2842(void);
extern int32_t FUN_00664b28(void);

// Per-type validation helpers used by the FUN_680dcd dispatch table.
extern int32_t FUN_006a507d(void);
extern int32_t FUN_0067f558(void);
extern int32_t FUN_0067f68e(void);
extern int32_t FUN_0067f47c(void);
extern int32_t FUN_0067f3a0(void);
extern int32_t FUN_006a67f5(void);
extern int32_t FUN_006a6662(void);
extern int32_t FUN_006a5c6c(void);
extern int32_t FUN_006a67af(void);
extern int32_t FUN_006a67cd(void);
extern int32_t FUN_006a67d7(void);
extern int32_t FUN_006a6813(void);
extern int32_t FUN_006a679b(void);
extern int32_t FUN_006a67a5(void);
extern int32_t FUN_006a566b(void);
extern int32_t FUN_006a5478(void);
extern int32_t FUN_006a6877(void);
extern int32_t FUN_006a6859(void);
extern int32_t FUN_006a6863(void);
extern int32_t FUN_006a5874(void);
extern int32_t FUN_006a6934(void);
extern int32_t FUN_006a55cd(void);
extern int32_t FUN_006a50e1(void);
extern int32_t FUN_006a5310(void);
extern int32_t FUN_006a5377(void);
extern int32_t FUN_006a53de(void);
extern int32_t FUN_006a5d79(void);
extern int32_t FUN_006a6948(void);
extern int32_t FUN_006a5deb(void);
extern int32_t FUN_006a5f06(void);
extern int32_t FUN_006a5fac(void);
extern int32_t FUN_006a5442(void);

// ---------------------------------------------------------------------------
// Referenced globals (addresses taken from the supplied listings only).
// ---------------------------------------------------------------------------
extern uint8_t PTR_FUN_006f0668;      // vtable blob
extern uint8_t PTR_FUN_006f07e0;      // vtable blob
extern uint8_t PTR_s_Position_00720638; // string blob
extern uint8_t PTR_s_Position_00720878; // string blob
extern uint32_t DAT_007205b8[];       // 8-entry table, 16-byte stride

// 0x680c65 — observed shape: scalar-deleting destructor; reinstalls the vtable
// PTR_FUN_006f0668, calls 0x6a0238, frees only when bit 0 of the flag is set.
void FUN_680c65(uint32_t* self, uint8_t param_1) {
    self[0] = (uint32_t)(uintptr_t)&PTR_FUN_006f0668;
    FUN_006a0238();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x680d04 — observed shape: per-block operand type check; walks
// (param_1[1] / (param_1[0] & 0xfffff)) blocks, gathers up to four element type
// ids into local_28 and, when bit 1 of *(int*)(self+0x6c) is set, requires one of
// the eight DAT_007205b8 entries to match (1000_... comparisons).
uint32_t FUN_680d04(uint8_t* self, uint32_t* param_1) {
    uint32_t uVar6 = *param_1 & 0xfffffu;
    if (uVar6 == 0) {
        return 1;
    }
    uint32_t local_28[5];
    local_28[4] = param_1[1] / uVar6;
    uint32_t local_10 = 0;
    if (local_28[4] != 0) {
        int32_t iVar1 = *(int32_t*)(self + 0x6c);
        uint32_t local_c = 0;
        uint8_t* local_14 = self;
        do {
            local_28[0] = 0xffffffffu;
            local_28[1] = 0xffffffffu;
            local_28[2] = 0xffffffffu;
            local_28[3] = 0xffffffffu;
            uint32_t uVar5 = 0;
            if (uVar6 != 0) {
                int32_t iVar4 = *(int32_t*)(local_14 + 0x14);
                int32_t* piVar3 = (int32_t*)(param_1[2] + local_c);
                do {
                    local_28[uVar5] = *(uint32_t*)(*(int32_t*)(iVar4 + *piVar3 * 4) + 0x10);
                    uVar5 = uVar5 + 1;
                    piVar3 = piVar3 + 1;
                } while (uVar5 < uVar6);
            }
            if ((iVar1 & 2) != 0) {
                uint32_t uVar5b = 0;
                uint32_t* local_8 = DAT_007205b8;
                do {
                    if (FUN_00673e38(local_28, local_8) != 0) break;
                    local_8 = local_8 + 4;
                    uVar5b = uVar5b + 1;
                } while (uVar5b < 8);
                if (uVar5b == 8) {
                    return 1;
                }
            }
            local_10 = local_10 + 1;
            local_c = local_c + uVar6 * 4;
        } while (local_10 < local_28[4]);
    }
    return 0;
}

// 0x680dcd — observed shape: three-phase materialisation pass.
//   phase 1: reset each object (self[3f]/self[40] cursor) and rebuild the
//            constant blob for the 0x60000000 / 0x11000000 class of type ids;
//   phase 2: 0x6959c5 latch, then per-object type dispatch through the
//            0x6a4xxx/0x6a5xxx/0x6a6xxx validators;
//   any validator returning 0x80004001 (-0x7fffbfff) aborts with 0x6626da.
uint32_t FUN_680dcd(uint32_t* self) {
    uint32_t local_38[8];
    uint32_t local_18 = self[3];
    uint32_t uVar3 = 0;
    int32_t local_8 = 0;
    int32_t iVar5 = 0;

    if (local_18 != 0) {
        do {
            self[0x3f] = uVar3;
            self[0x40] = *(uint32_t*)(self[6] + uVar3 * 4);
            FUN_00696278();
            uVar3 = uVar3 + 1;
        } while (uVar3 < self[3]);
    }

    uint32_t local_14 = 0;
    if (local_18 != 0) {
        do {
            self[0x3f] = local_14;
            uint32_t* puVar8 = *(uint32_t**)(self[6] + local_14 * 4);
            self[0x40] = (uint32_t)(uintptr_t)puVar8;
            uint32_t type = *puVar8 & 0xfff00000u;
            if (type == 0x60500000u || type == 0x60f00000u || type == 0x60a00000u ||
                type == 0x60200000u || type == 0x60700000u || type == 0x60c00000u ||
                type == 0x61100000u || type == 0x60300000u || type == 0x60800000u ||
                type == 0x60d00000u || type == 0x61200000u || type == 0x60000000u ||
                type == 0x11000000u) {
                uint32_t uVar3b = *puVar8 & 0xfffffu;
                uint32_t local_10 = uVar3b;
                if ((*puVar8 & 0xfff00000u) == 0x11000000u) {
                    local_10 = 0;
                }
                uint32_t local_c = 0;
                if (uVar3b != 0) {
                    int32_t iVar5b = (int32_t)(local_10 << 2);
                    do {
                        int32_t iVar1 = *(int32_t*)(self[5] +
                            *(int32_t*)(iVar5b + *(int32_t*)(self[0x40] + 8)) * 4);
                        if (*(uint32_t*)(iVar1 + 0x10) != local_c ||
                            (*(uint8_t*)(iVar1 + 0x3e) & 0x1f) != 0) {
                            break;
                        }
                        bool bVar7;
                        if (*(int32_t*)(iVar1 + 4) == (int32_t)self[0x20]) {
                            // vtable +0x54: component id of the element
                            iVar1 = reinterpret_cast<int32_t(__thiscall*)(void*, uint32_t)>(
                                *reinterpret_cast<uint32_t*>(self[0] + 0x54))(
                                self, *(uint32_t*)(iVar1 + 0x6c));
                            bVar7 = (iVar1 == 6);
                        } else {
                            bVar7 = (*(int32_t*)(iVar1 + 4) == (int32_t)self[0x22]);
                        }
                        if (!bVar7) break;
                        local_c = local_c + 1;
                        iVar5b = iVar5b + 4;
                    } while (local_c < uVar3b);
                }
                if ((*(uint32_t*)self[0x40] & 0xfff00000u) == 0x60000000u && uVar3b == 1) {
                    // vtable +0x80: read 4 bytes of the object payload
                    iVar5 = reinterpret_cast<int32_t(__thiscall*)(void*, uint32_t, void*, uint32_t,
                                                                 uint32_t, uint32_t)>(
                        *reinterpret_cast<uint32_t*>(self[0] + 0x80))(
                        self, self[0x3f], &local_38[1], 4, 0, 0);
                    if (iVar5 < 0) {
                        return 0;
                    }
                    iVar5 = FUN_0065d0b4(0x74);
                    if (iVar5 == 0) {
                        iVar5 = 0;
                    } else {
                        iVar5 = FUN_0065cc1a();
                    }
                    if (iVar5 == 0) {
                        return 0x8007000eu;
                    }
                    local_8 = iVar5;
                    int32_t iVar1 = FUN_0065d0ff(0x10000002u, 2, 2, 0);
                    if (iVar1 < 0 || (iVar1 = FUN_0065cc50(self[0x40]), iVar1 < 0)) {
                        if (local_8 == 0) {
                            return 0;
                        }
                        FUN_00614343(1);
                        return 0;
                    }
                    **(uint32_t**)(iVar5 + 8) =
                        *(uint32_t*)(*(int32_t*)(self[0x40] + 8) + 4);
                    *(uint32_t*)(*(int32_t*)(iVar5 + 8) + 4) =
                        *(uint32_t*)(*(int32_t*)(self[0x40] + 8) + 4);
                    **(uint32_t**)(iVar5 + 0x10) = local_38[4];
                    *(uint32_t*)(*(int32_t*)(iVar5 + 0x10) + 4) = local_38[5];
                    iVar5 = FUN_0065d8c2(iVar5);
                    if (iVar5 < 0) {
                        if (local_8 == 0) {
                            return 0;
                        }
                        FUN_00614343(1);
                        return 0;
                    }
                    iVar5 = FUN_0065d0b4(0x74);
                    if (iVar5 == 0) {
                        uVar3b = 0;
                    } else {
                        uVar3b = (uint32_t)FUN_0065cc1a();
                    }
                    if (uVar3b == 0) {
                        return 0;
                    }
                    local_c = uVar3b;
                    iVar5 = FUN_0065d0ff(0x60500002u, 4,
                                         *(uint32_t*)(self[0x40] + 0xc), 0);
                    if (iVar5 < 0 || (iVar5 = FUN_0065cc50(self[0x40]), iVar5 < 0)) {
                        FUN_00614343(1);
                        return 0;
                    }
                    uint32_t uVar2 = 8;
                    do {
                        *(uint32_t*)((uVar2 - 8) + *(int32_t*)(uVar3b + 8)) =
                            **(uint32_t**)(self[0x40] + 8);
                        *(uint32_t*)(uVar2 + *(int32_t*)(uVar3b + 8)) =
                            *(uint32_t*)((uint8_t*)local_38 + uVar2 + 8);
                        uVar2 = uVar2 + 4;
                    } while (uVar2 < 0x10);
                    uint32_t* puVar4 = *(uint32_t**)(self[0x40] + 0x10);
                    uint32_t* puVar6 = *(uint32_t**)(local_c + 0x10);
                    for (uint32_t n = *(uint32_t*)(self[0x40] + 0xc) & 0x3fffffffu;
                         n != 0; n = n - 1) {
                        *puVar6 = *puVar4;
                        puVar4 = puVar4 + 1;
                        puVar6 = puVar6 + 1;
                    }
                    // observed trailing byte loop with a zero trip count
                    for (int32_t n = 0; n != 0; n = n - 1) {
                        *(uint8_t*)puVar6 = *(uint8_t*)puVar4;
                        puVar4 = (uint32_t*)((uintptr_t)puVar4 + 1);
                        puVar6 = (uint32_t*)((uintptr_t)puVar6 + 1);
                    }
                    if (self[0x40] != 0) {
                        FUN_00614343(1);
                    }
                    *(uint32_t*)(self[6] + local_14 * 4) = local_c;
                    self[0x40] = local_c;
                    local_8 = 0;
                } else if (local_c != uVar3b) {
                    // vtable +0x80: read 4 bytes of the block header
                    iVar5 = reinterpret_cast<int32_t(__thiscall*)(void*, uint32_t, void*, uint32_t,
                                                                 uint32_t, uint32_t)>(
                        *reinterpret_cast<uint32_t*>(self[0] + 0x80))(
                        self, self[0x3f], local_38, 4, 0, 0);
                    if (iVar5 < 0) {
                        return 0;
                    }
                    iVar5 = FUN_0065d0b4(0x74);
                    if (iVar5 == 0) {
                        local_8 = 0;
                    } else {
                        local_8 = FUN_0065cc1a();
                    }
                    if (local_8 == 0) {
                        return 0x8007000eu;
                    }
                    iVar5 = FUN_0065d0ff(uVar3b | 0x10000000u, uVar3b, uVar3b, 0);
                    if (iVar5 < 0 || (iVar5 = FUN_0065cc50(self[0x40]), iVar5 < 0)) {
                        if (local_8 == 0) {
                            return 0;
                        }
                        FUN_00614343(1);
                        return 0;
                    }
                    local_c = 0;
                    if (uVar3b != 0) {
                        int32_t iVar5b = (int32_t)(local_10 << 2);
                        do {
                            uint32_t uVar2 = local_c;
                            int32_t iVar1b = (int32_t)(local_c * 4);
                            local_c = local_c + 1;
                            *(uint32_t*)(iVar1b + *(int32_t*)(local_8 + 8)) =
                                *(uint32_t*)(iVar5b + *(int32_t*)(self[0x40] + 8));
                            *(uint32_t*)(iVar1b + *(int32_t*)(local_8 + 0x10)) =
                                local_38[uVar2];
                            *(uint32_t*)(iVar5b + *(int32_t*)(self[0x40] + 8)) =
                                *(uint32_t*)(iVar1b + *(int32_t*)(local_8 + 0x10));
                            iVar5b = iVar5b + 4;
                        } while (local_c < uVar3b);
                    }
                    iVar5 = FUN_0065d8c2(local_8);
                    if (iVar5 < 0) {
                        if (local_8 == 0) {
                            return 0;
                        }
                        FUN_00614343(1);
                        return 0;
                    }
                    local_8 = 0;
                }
                puVar8 = (uint32_t*)(uintptr_t)self[0x40];
            }
            iVar5 = FUN_0065db2e(puVar8);
            if (iVar5 < 0) {
                return 0;
            }
            *puVar8 = 0;
            local_14 = local_14 + 1;
        } while (local_14 < local_18);
    }

    FUN_006959c5();
    local_18 = self[3];
    uVar3 = 0;
    if (local_18 != 0) {
        do {
            self[0x3f] = uVar3;
            int32_t iVar1 = *(int32_t*)(self[6] + uVar3 * 4);
            self[0x40] = (uint32_t)iVar1;
            iVar1 = *(int32_t*)(iVar1 + 0x3c);
            if (iVar1 != 0 && *(int32_t*)(iVar1 + 4) == 0xd) {
                self[0x41] = (uint32_t)(iVar1 + 0x30);
            }
            uint32_t* puVar8 = (uint32_t*)(uintptr_t)self[0x40];
            uint32_t uVar2 = *puVar8 & 0xfff00000u;
            if (uVar2 != 0 && puVar8[1] != 0 &&
                *(int32_t*)(*(int32_t*)(self[5] + *(int32_t*)puVar8[2] * 4) + 8) != -1) {
                FUN_006626da();
                return 0;
            }
            iVar5 = 0;
            switch (uVar2) {
            case 0x00000000u:
                // observed: type 0 leaves the previous status word untouched
                break;
            case 0x10000000u: iVar5 = FUN_006a6662(); break;
            case 0x10100000u: iVar5 = FUN_006a5c6c(); break;
            case 0x10300000u: iVar5 = FUN_006a67af(); break;
            case 0x10400000u: iVar5 = FUN_006a67cd(); break;
            case 0x10500000u: iVar5 = FUN_006a67d7(); break;
            case 0x10600000u: iVar5 = FUN_006a67f5(); break;
            case 0x10700000u: iVar5 = FUN_006a6813(); break;
            case 0x10d00000u:
                if ((*(uint8_t*)(self + 0x1c) & 0x10) == 0) {
                    iVar5 = -0x7fffbfff;
                } else {
                    iVar5 = FUN_006a679b();
                }
                break;
            case 0x10e00000u:
                if ((*(uint8_t*)(self + 0x1c) & 0x10) == 0) {
                    iVar5 = -0x7fffbfff;
                } else {
                    iVar5 = FUN_006a67a5();
                }
                break;
            case 0x10f00000u: iVar5 = FUN_006a566b(); break;
            case 0x11000000u: iVar5 = FUN_006a5478(); break;
            case 0x20000000u: iVar5 = FUN_0067f68e(); break;
            case 0x20100000u: iVar5 = FUN_0067f558(); break;
            case 0x20200000u: iVar5 = FUN_0067f47c(); break;
            case 0x20300000u: iVar5 = FUN_0067f3a0(); break;
            case 0x20400000u: iVar5 = FUN_006a6859(); break;
            case 0x20500000u: iVar5 = FUN_006a6863(); break;
            case 0x20700000u: iVar5 = FUN_006a5874(); break;
            case 0x30000000u: iVar5 = FUN_006a6934(); break;
            case 0x50000000u: iVar5 = FUN_006a6877(); break;
            case 0x50300000u: iVar5 = FUN_006a55cd(); break;
            case 0x60000000u:
            case 0x60500000u:
            case 0x60a00000u:
            case 0x60f00000u: iVar5 = FUN_006a507d(); break;
            case 0x60100000u:
            case 0x60600000u:
            case 0x60b00000u:
            case 0x61000000u: iVar5 = FUN_006a50e1(); break;
            case 0x60200000u:
            case 0x60700000u:
            case 0x60c00000u:
            case 0x61100000u: iVar5 = FUN_006a5310(); break;
            case 0x60300000u:
            case 0x60800000u:
            case 0x61200000u: iVar5 = FUN_006a5377(); break;
            case 0x60400000u:
            case 0x60900000u:
            case 0x60e00000u:
            case 0x61300000u:
                if ((*(uint8_t*)(self + 0x1c) & 0x20) == 0) {
                    FUN_006626da();
                    return 0;
                }
                iVar5 = FUN_006a53de();
                break;
            case 0x60d00000u: iVar5 = FUN_006a5377(); break;
            case 0x70000000u: iVar5 = FUN_006a6948(); break;
            case 0x70100000u: iVar5 = FUN_006a5deb(); break;
            case 0x70200000u: iVar5 = FUN_006a5f06(); break;
            case 0x70300000u:
            case 0x70400000u: iVar5 = FUN_006a5fac(); break;
            case 0x70800000u: iVar5 = FUN_006a5442(); break;
            case 0x70b00000u: iVar5 = FUN_0067f68e(); break;
            case 0x70c00000u: iVar5 = FUN_0067f558(); break;
            case 0x70d00000u: iVar5 = FUN_006a5d79(); break;
            case 0x73500000u:
            case 0x73600000u:
            case 0x73700000u:
            case 0x73800000u: iVar5 = FUN_006a566b(); break;
            default: iVar5 = -0x7fffbfff; break;
            }
            if (iVar5 == -0x7fffbfff) {
                FUN_006626da();
                return 0;
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < local_18);
    }
    return 0;
}

// 0x68163f — observed shape: validate the element bookkeeping of one operand
// blob. Counts elements per stream bucket (self[0x1f], self[0x20], self[0x22],
// self[0x25]) using the bucket table auStack_6c / auStack_b4, aborts when a
// bucket overflows or when more than two elements carry the 0x10 stream bit.
uint32_t FUN_68163f(uint32_t* self, uint32_t* param_1, uint32_t* param_2) {
    if (param_1 == nullptr) {
        return 1;
    }
    uint32_t uVar8 = *param_1 & 0xfff00000u;
    if (uVar8 == 0 || uVar8 == 0x20700000u) {
        return 0;
    }
    uint32_t local_8 = *param_1 & 0xfffffu;
    uint32_t local_20 = param_1[1] / local_8;
    if (local_20 <= 1) {
        return 0;
    }
    uint32_t auStack_b4[18];
    uint32_t auStack_6c[18];
    int32_t iVar2 = (int32_t)self[0x20];
    int32_t iVar6 = (int32_t)self[0x22];
    int32_t iVar3 = (int32_t)self[0x1f];
    auStack_6c[iVar2] = 0;
    auStack_6c[iVar6] = 0;
    auStack_6c[iVar3] = 0;
    int32_t iVar4 = (int32_t)self[0x25];
    auStack_b4[iVar2] = 1;
    auStack_6c[iVar4] = 0;
    auStack_b4[iVar6] = 3;
    auStack_b4[iVar3] = 1;
    auStack_b4[iVar4] = 1;
    uint32_t local_14 = 0;
    uint32_t local_10 = 0;
    int32_t local_18 = 0;
    int32_t local_1c = 0;
    if (local_20 != 0) {
        local_18 = (int32_t)(local_8 << 2);
        do {
            int32_t iVar2b = *(int32_t*)(self[5] +
                *(int32_t*)(local_1c + param_1[2]) * 4);
            int32_t local_24 = *(int32_t*)(self[4] + *(int32_t*)(iVar2b + 4) * 4);
            uint32_t u = *(uint32_t*)(local_24 + 4);
            uint32_t local_c;
            if ((u & 0x200) == 0) {
                if ((int8_t)u < 0) {
                    local_c = self[0x25];
                } else if ((u & 0x10) == 0 ||
                           (iVar6 = reinterpret_cast<int32_t(__thiscall*)(void*, uint32_t)>(
                                *reinterpret_cast<uint32_t*>(self[0] + 0x54))(
                                self, *(uint32_t*)(iVar2b + 0x6c)),
                            iVar6 == 0xffff)) {
                    local_c = self[0x22];
                } else {
                    local_c = self[0x20];
                }
            } else if ((int8_t)u < 0) {
                local_c = self[0x25];
            } else {
                local_c = self[0x1f];
            }
            local_8 = 0;
            if (local_10 != 0) {
                int32_t* piVar7 = (int32_t*)param_1[2];
                do {
                    iVar6 = *(int32_t*)(self[5] + *piVar7 * 4);
                    if (*(int32_t*)(iVar2b + 4) == *(int32_t*)(iVar6 + 4) &&
                        *(int32_t*)(iVar2b + 8) == *(int32_t*)(iVar6 + 8) &&
                        *(int32_t*)(iVar2b + 0xc) == *(int32_t*)(iVar6 + 0xc)) {
                        break;
                    }
                    local_8 = local_8 + 1;
                    piVar7 = (int32_t*)((intptr_t)piVar7 + local_18);
                } while (local_8 < local_10);
            }
            if (local_8 == local_10 && local_c < 0x12) {
                uint32_t* puVar1 = auStack_6c + local_c;
                *puVar1 = *puVar1 + 1;
                if (auStack_b4[local_c] < *puVar1) {
                    if (param_2 != nullptr) {
                        *param_2 = local_10;
                    }
                    return 1;
                }
            }
            if ((*(uint8_t*)(local_24 + 5) & 2) != 0) {
                local_14 = local_14 + 1;
                if (2 < local_14) {
                    if (param_2 != nullptr) {
                        *param_2 = local_10;
                    }
                    return 1;
                }
            }
            local_1c = local_1c + local_18;
            local_10 = local_10 + 1;
        } while (local_10 < local_20);
    }
    return 0;
}

// 0x681814 — observed shape: constructor tail; forwards to 0x6a0152, stores the
// argument at self[0x56], then installs the vtable and the two string blobs.
void FUN_681814(uint32_t* self, uint32_t param_1) {
    FUN_006a0152();
    self[0x56] = param_1;
    self[0] = (uint32_t)(uintptr_t)&PTR_FUN_006f07e0;
    self[0x3c] = (uint32_t)(uintptr_t)&PTR_s_Position_00720638;
    self[0x3d] = (uint32_t)(uintptr_t)&PTR_s_Position_00720878;
}

// 0x68199d — observed shape: stream-completeness check. Scans every object of
// self[2], buckets the 0x20-flagged ones by the stream index stored at +0x10,
// reports duplicates through 0x6626da, then requires all four buckets filled.
uint32_t FUN_68199d(uint32_t* self) {
    uint32_t uVar1 = 0;
    if (self[0x56] != 0) {
        return 0;
    }
    int32_t local_2c[5];
    uint32_t local_18 = 0;
    int32_t local_14 = 0;
    int32_t local_10 = 0;
    int32_t local_c = 0;
    uint32_t local_8 = 0;
    local_2c[0] = 0;
    local_2c[1] = 0;
    local_2c[2] = 0;
    local_2c[3] = 0;
    if (self[2] != 0) {
        do {
            int32_t iVar3 = *(int32_t*)(self[5] + local_8 * 4);
            if ((*(uint8_t*)(*(int32_t*)(self[4] + *(int32_t*)(iVar3 + 4) * 4) + 4) & 0x20) != 0) {
                local_2c[4] = reinterpret_cast<int32_t(__thiscall*)(void*, uint32_t)>(
                    *reinterpret_cast<uint32_t*>(self[0] + 0x54))(
                    self, *(uint32_t*)(iVar3 + 0x6c));
                int32_t iVar2 = reinterpret_cast<int32_t(__thiscall*)(void*, uint32_t)>(
                    *reinterpret_cast<uint32_t*>(self[0] + 0x58))(
                    self, *(uint32_t*)(iVar3 + 0x6c));
                if (local_2c[4] == 1) {
                    if (iVar2 == 0) {
                        local_2c[*(int32_t*)(iVar3 + 0x10)] = 1;
                        local_18 = *(uint32_t*)(iVar3 + 0x60);
                    }
                } else if (local_2c[4] == 5) {
                    if (iVar2 == 0 && *(int32_t*)(iVar3 + 0x10) != 0 && local_14 == 0) {
                        FUN_006626da();
                        local_14 = 1;
                        local_c = 1;
                    }
                } else if (local_2c[4] == 0xc && iVar2 == 0 &&
                           *(int32_t*)(iVar3 + 0x10) != 0 && local_10 == 0) {
                    FUN_006626da();
                    local_10 = 1;
                    local_c = 1;
                }
            }
            local_8 = local_8 + 1;
        } while (local_8 < self[2]);
    }
    int32_t iVar3 = 0;
    uVar1 = 0;
    do {
        if (local_2c[uVar1] != 0) {
            iVar3 = iVar3 + 1;
        }
        uVar1 = uVar1 + 1;
    } while (uVar1 < 4);
    if (iVar3 != 4) {
        FUN_006626da();
        local_c = 1;
    }
    return (uint32_t)(-(int32_t)(local_c != 0)) & 0x80004005u;
}

// 0x681ade — observed shape: classify one effect object into a (stream, index)
// pair. vtable +0x54 gives the class, +0x58 the index; only class 1/5/0xc fill
// param_4 with 1, classes 0xb/6/0xffff report wide indices, others are E_FAIL.
uint32_t FUN_681ade(uint32_t* self, int32_t param_1, uint32_t* param_2,
                    uint32_t* param_3, uint32_t* param_4) {
    int32_t iVar1 = reinterpret_cast<int32_t(__thiscall*)(void*, uint32_t)>(
        *reinterpret_cast<uint32_t*>(self[0] + 0x54))(self, *(uint32_t*)(param_1 + 0x6c));
    uint32_t uVar2 = (uint32_t)reinterpret_cast<int32_t(__thiscall*)(void*, uint32_t)>(
        *reinterpret_cast<uint32_t*>(self[0] + 0x58))(self, *(uint32_t*)(param_1 + 0x6c));
    *param_2 = uVar2;
    if (param_4 != nullptr) {
        *param_4 = 0;
    }
    if (iVar1 == 1) {
        if (*param_2 == 0) {
            *param_3 = 4;
            *param_2 = 0;
            return 0;
        }
        return 0x80004005u;
    }
    if (iVar1 == 5) {
        if (*param_2 != 0) {
            return 0x80004005u;
        }
        *param_3 = 4;
        *param_2 = 2;
    } else {
        if (iVar1 != 0xc) {
            if (iVar1 == 0xb) {
                if (*param_2 < 2) {
                    *param_3 = 5;
                    return 0;
                }
                return 0x80004005u;
            }
            if (iVar1 == 6) {
                if (*param_2 < 8) {
                    *param_3 = 6;
                    return 0;
                }
                return 0x80004005u;
            }
            if (iVar1 == 0xffff) {
                *param_3 = 0;
                return 0;
            }
            return 0x80004005u;
        }
        if (*param_2 != 0) {
            return 0x80004005u;
        }
        *param_3 = 4;
        *param_2 = 1;
    }
    if (param_4 != nullptr) {
        *param_4 = 1;
    }
    return 0;
}

// 0x681ba0 — observed shape: read the (class, index) pair of one object; class
// 0xffff means "unnamed", reported through vtable +0x58 with kind 0, otherwise
// the declared slot at +0xc with kind 1.
uint32_t FUN_681ba0(uint32_t* self, int32_t param_1, uint32_t* param_2, uint32_t* param_3) {
    int32_t iVar1 = reinterpret_cast<int32_t(__thiscall*)(void*, uint32_t)>(
        *reinterpret_cast<uint32_t*>(self[0] + 0x54))(self, *(uint32_t*)(param_1 + 0x6c));
    uint32_t uVar2;
    if (iVar1 == 0xffff) {
        *param_3 = 0;
        uVar2 = (uint32_t)reinterpret_cast<int32_t(__thiscall*)(void*, uint32_t)>(
            *reinterpret_cast<uint32_t*>(self[0] + 0x58))(self, *(uint32_t*)(param_1 + 0x6c));
    } else {
        *param_3 = 1;
        uVar2 = *(uint32_t*)(param_1 + 0xc);
    }
    *param_2 = uVar2;
    return 0;
}

// 0x681be3 — observed shape: latches "more than 0x100 elements" into self+0x154
// from the low 16 bits at self+200, then forwards to 0x6a3d1c.
void FUN_681be3(uint8_t* self) {
    *(uint32_t*)(self + 0x154) =
        (uint32_t)(0x100u < (*(uint32_t*)(self + 200) & 0xffffu));
    FUN_006a3d1c();
}

// 0x682188 — observed shape: collapse redundant 0x50xxxxxx chain nodes. Looks up
// the 0x1000000{2,3,4} template, checks the operator against self[0x21], then
// either rebuilds the node through 0x9e83f and the vtable (+0x20/+0x34), or
// collapses a 3-element pass-through chain into one new 0x70200000 node.
int32_t FUN_682188(uint32_t* self) {
    uint32_t* puVar5 = (uint32_t*)(uintptr_t)self[0x40];
    uint32_t uVar8 = *puVar5 & 0xfffffu;
    if (uVar8 < 3) {
        return 0;
    }
    uint32_t* local_10 = puVar5;
    uint32_t* local_8 = self;
    int32_t local_c = 0;
    uint32_t local_14 = 0;

    // Template lookup: the first non-null of 0x1000000{2,3,4}.
    uint32_t* puVar1 = FUN_0069e83f(0x10000002u, puVar5, nullptr, 2, 1);
    if (puVar1 == nullptr) {
        puVar1 = FUN_0069e83f(0x10000003u, puVar5, nullptr, 2, 1);
    }
    if (puVar1 == nullptr) {
        puVar1 = FUN_0069e83f(0x10000004u, puVar5, nullptr, 2, 1);
    }
    bool fallback = false;
    if (puVar1 == nullptr) {
        fallback = true;
    } else {
        local_c = (int32_t)local_8[5];
        if (*(int32_t*)(*(int32_t*)(local_c + *(int32_t*)puVar1[4] * 4) + 4) !=
            (int32_t)local_8[0x21]) {
            fallback = true;
        }
    }

    if (!fallback) {
        uint32_t local_1c = *puVar1 & 0xfffffu;
        bool bVar12 = true;
        if (local_1c != 0) {
            local_14 = (uint32_t)puVar5[4];
            int32_t* piVar6 = (int32_t*)puVar1[2];
            do {
                if (*piVar6 != (int32_t)local_14 ||
                    (*(uint32_t*)(*(int32_t*)(local_c + *piVar6 * 4) + 0x34) & 0x1ffe00) != 0) {
                    bVar12 = false;
                }
                piVar6 = piVar6 + 1;
                local_1c = local_1c - 1;
            } while (local_1c != 0);
        }
        if (bVar12) {
            int32_t iVar2 = FUN_0065d0b4(0x74);
            if (iVar2 == 0) {
                local_c = 0;
            } else {
                local_c = FUN_0065cc1a();
            }
            if (local_c == 0) {
                return -0x7ff8fff2;
            }
            int32_t iVar3 = FUN_0065d0ff(uVar8 | 0x50000000u, puVar5[1], puVar1[3], 0);
            int32_t iVar2b = local_c;
            if (iVar3 < 0 || (iVar3 = FUN_0065cc50((uint32_t)(uintptr_t)puVar5), iVar3 < 0)) {
                FUN_00614343(1);
                return iVar3;
            }
            uint32_t* puVar4 = (uint32_t*)puVar1[4];
            uint32_t* puVar9 = *(uint32_t**)(iVar2b + 0x10);
            for (uVar8 = *(uint32_t*)(iVar2b + 0xc) & 0x3fffffffu; uVar8 != 0; uVar8 = uVar8 - 1) {
                *puVar9 = *puVar4;
                puVar4 = puVar4 + 1;
                puVar9 = puVar9 + 1;
            }
            // observed trailing byte loop with a zero trip count
            for (int32_t n = 0; n != 0; n = n - 1) {
                *(uint8_t*)puVar9 = *(uint8_t*)puVar4;
                puVar4 = (uint32_t*)((uintptr_t)puVar4 + 1);
                puVar9 = (uint32_t*)((uintptr_t)puVar9 + 1);
            }
            puVar4 = (uint32_t*)local_10[2];
            puVar9 = *(uint32_t**)(local_c + 8);
            for (uVar8 = *(uint32_t*)(local_c + 4) & 0x3fffffffu; uVar8 != 0; uVar8 = uVar8 - 1) {
                *puVar9 = *puVar4;
                puVar4 = puVar4 + 1;
                puVar9 = puVar9 + 1;
            }
            // observed trailing byte loop with a zero trip count
            for (int32_t n = 0; n != 0; n = n - 1) {
                *(uint8_t*)puVar9 = *(uint8_t*)puVar4;
                puVar4 = (uint32_t*)((uintptr_t)puVar4 + 1);
                puVar9 = (uint32_t*)((uintptr_t)puVar9 + 1);
            }
            *puVar1 = 0;
            if (local_8[0x40] != 0) {
                FUN_00614343(1);
            }
            *(int32_t*)(local_8[6] + local_8[0x3f] * 4) = local_c;
            local_8[0x40] = (uint32_t)local_c;
        }
        return 0;
    }

    // Fallback: collapse a 3-element pass-through chain.
    if (uVar8 == 3 && 0x1ffu < (local_8[0x32] & 0xffffu)) {
        local_10 = (uint32_t*)(uintptr_t)local_8[0x40];
        int32_t iVar2 = 3;
        bool bVar12 = true;
        int32_t* piVar6 = (int32_t*)local_10[2];
        int32_t* piVar10 = (int32_t*)local_10[2] + 3;
        do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 - 1;
            bVar12 = (*piVar6 == *piVar10);
            piVar6 = piVar6 + 1;
            piVar10 = piVar10 + 1;
        } while (bVar12);
        if (bVar12) {
            uint32_t* puVar4 = FUN_0069e83f(0x10700001u, local_10, nullptr, 2, 1);
            uint32_t* puVar5b = nullptr;
            if (puVar4 != nullptr) {
                puVar5b = FUN_0069e83f(0x20500003u, puVar4, (int32_t*)&local_14, 2, 1);
                if (puVar5b == nullptr) {
                    puVar5b = FUN_0069e83f(0x20500004u, puVar4, (int32_t*)&local_14, 2, 1);
                }
            }
            if (puVar4 != nullptr && puVar5b != nullptr) {
                int32_t iVar2b = *(int32_t*)(local_8[5] + *(int32_t*)local_10[2] * 4);
                local_c = *(int32_t*)(local_8[5] + *(int32_t*)puVar5b[4] * 4);
                uVar8 = *puVar5b & 0xfffffu;
                int32_t iVar3 = 3;
                bool bVar12b = true;
                int32_t* piVar6b = (int32_t*)(puVar5b[2] + uVar8 * 4);
                int32_t* piVar10b = (int32_t*)local_10[2];
                do {
                    if (iVar3 == 0) break;
                    iVar3 = iVar3 - 1;
                    bVar12b = (*piVar6b == *piVar10b);
                    piVar6b = piVar6b + 1;
                    piVar10b = piVar10b + 1;
                } while (bVar12b);
                if (bVar12b &&
                    (*(int32_t*)(iVar2b + 4) != *(int32_t*)(local_c + 4) ||
                     *(int32_t*)(iVar2b + 0xc) != *(int32_t*)(local_c + 0xc))) {
                    iVar2b = FUN_0065d0b4(0x74);
                    if (iVar2b == 0) {
                        local_c = 0;
                    } else {
                        local_c = FUN_0065cc1a();
                    }
                    if (local_c == 0) {
                        return -0x7ff8fff2;
                    }
                    int32_t iVar3b = FUN_0065d0ff(uVar8 | 0x70200000u, uVar8, uVar8, 0);
                    if (iVar3b < 0) {
                        return iVar3b;
                    }
                    iVar3b = FUN_0065cc50((uint32_t)(uintptr_t)puVar5b);
                    if (iVar3b < 0) {
                        return iVar3b;
                    }
                    uint32_t* puVar9 = (uint32_t*)puVar5b[4];
                    uint32_t* puVar11 = *(uint32_t**)(local_c + 0x10);
                    for (uint32_t uVar7 = uVar8; uVar7 != 0; uVar7 = uVar7 - 1) {
                        *puVar11 = *puVar9;
                        puVar9 = puVar9 + 1;
                        puVar11 = puVar11 + 1;
                    }
                    // observed trailing byte loop with a zero trip count
                    for (int32_t n = 0; n != 0; n = n - 1) {
                        *(uint8_t*)puVar11 = *(uint8_t*)puVar9;
                        puVar9 = (uint32_t*)((uintptr_t)puVar9 + 1);
                        puVar11 = (uint32_t*)((uintptr_t)puVar11 + 1);
                    }
                    puVar9 = (uint32_t*)(puVar5b[2] + uVar8 * 4);
                    puVar11 = *(uint32_t**)(local_c + 8);
                    for (uint32_t uVar7 = uVar8; uVar7 != 0; uVar7 = uVar7 - 1) {
                        *puVar11 = *puVar9;
                        puVar9 = puVar9 + 1;
                        puVar11 = puVar11 + 1;
                    }
                    // observed trailing byte loop with a zero trip count
                    for (int32_t n = 0; n != 0; n = n - 1) {
                        *(uint8_t*)puVar11 = *(uint8_t*)puVar9;
                        puVar9 = (uint32_t*)((uintptr_t)puVar9 + 1);
                        puVar11 = (uint32_t*)((uintptr_t)puVar11 + 1);
                    }
                    // vtable +0x20: register the new node
                    iVar3b = reinterpret_cast<int32_t(__thiscall*)(void*, uint32_t, uint32_t)>(
                        *reinterpret_cast<uint32_t*>(local_8[0] + 0x20))(
                        local_8, (uint32_t)local_c, 0);
                    if (iVar3b == 0) {
                        *local_10 = 0;
                        *puVar4 = 0;
                        *puVar5b = 0;
                        // vtable +0x34: bind the node to the slot index
                        iVar3b = reinterpret_cast<int32_t(__thiscall*)(void*, uint32_t, uint32_t)>(
                            *reinterpret_cast<uint32_t*>(local_8[0] + 0x34))(
                            local_8, (uint32_t)local_c, local_14);
                        if (iVar3b == 0) {
                            if (*(int32_t*)(local_8[6] + local_14 * 4) != 0) {
                                FUN_00614343(1);
                            }
                            *(int32_t*)(local_8[6] + local_14 * 4) = local_c;
                            return 0;
                        }
                        *local_10 = 0x50000003u;
                        *puVar4 = 0x10700001u;
                        *puVar5b = uVar8 | 0x20500000u;
                    }
                    FUN_00614343(1);
                }
            }
        }
    }
    return 0;
}

// 0x682543 — observed shape: bind one effect object. In "named" mode
// (self[0x56] != 0) it derives "v_<class><index>" (plus "n_<name>" for the
// 0x60/+0x14/+0x18 sub-object) and registers both strings through 0x61273f;
// otherwise it encodes the (class,index) pair and drives the vtable pipeline
// (+0x54/+0x58/+0x70/+0x88/+0x64/+0x60) before 0x69fcf5.
int32_t FUN_682543(uint32_t* self, uint32_t param_1, uint32_t* param_2) {
    int32_t iVar6 = (int32_t)param_1;
    int32_t iVar3 = reinterpret_cast<int32_t(__thiscall*)(void*, uint32_t)>(
        *reinterpret_cast<uint32_t*>(self[0] + 0x54))(self, *(uint32_t*)(param_1 + 0x6c));
    uint32_t uVar4 = (uint32_t)reinterpret_cast<int32_t(__thiscall*)(void*, uint32_t)>(
        *reinterpret_cast<uint32_t*>(self[0] + 0x58))(self, *(uint32_t*)(param_1 + 0x6c));
    // listing declares a 16-byte local but passes a 0x20-byte limit
    char local_34[0x20];
    uint32_t auStack_24[5];
    uint32_t uStack_10;
    int32_t iStack_c;
    uint32_t uStack_8;

    if (self[0x56] != 0) {
        if (*(int32_t*)(param_1 + 0x6c) == -1) {
            return 0;
        }
        if (iVar3 != 0xffff) {
            uint32_t* puVar5 = FUN_006a3cac(iVar3);
            _snprintf(local_34, 0x20, "v_%s%d", (const char*)(uintptr_t)*puVar5, uVar4);
            auStack_24[3] = auStack_24[3] & 0xffffffu; // listing masks an uninitialised slot
            iVar6 = FUN_0061273f(local_34, *(uint32_t*)(param_1 + 0xc), 1);
            if (iVar6 < 0) {
                return iVar6;
            }
            self[0x7c] = self[0x7c] + 1;
            if ((*(uint8_t*)(self + 0x33) & 1) != 0) {
                iVar6 = *(int32_t*)(param_1 + 0x60);
                if (iVar6 != 0 && *(int32_t*)(iVar6 + 4) == 6) {
                    iVar6 = *(int32_t*)(iVar6 + 0x14);
                    if (*(int32_t*)(iVar6 + 4) == 3) {
                        char* pcVar7 = *(char**)(iVar6 + 0x18);
                        char* pcVar8 = pcVar7 + 1;
                        char cVar1;
                        do {
                            cVar1 = *pcVar7;
                            pcVar7 = pcVar7 + 1;
                        } while (cVar1 != '\0');
                        int32_t nbytes = (int32_t)((intptr_t)pcVar7 + 3 - (intptr_t)pcVar8);
                        pcVar8 = (char*)FUN_00533c78(nbytes);
                        if (pcVar8 == nullptr) {
                            return -0x7ff8fff2;
                        }
                        sprintf(pcVar8, "n_%s", *(char**)(iVar6 + 0x18));
                        iVar6 = FUN_0061273f(pcVar8, *(uint32_t*)(param_1 + 0xc), 1);
                        operator_delete(pcVar8);
                        if (iVar6 < 0) {
                            return iVar6;
                        }
                        self[0x7c] = self[0x7c] + 1;
                    }
                }
            }
        }
        if (param_2 == nullptr) {
            return 0;
        }
        *param_2 = *(uint32_t*)(param_1 + 0x6c);
        return 0;
    }

    // Anonymous mode: map the vtable class to a slot index.
    int32_t slot = 0;
    bool checkRange = true;
    switch (iVar3) {
    case 0:
        return 1;
    case 1: slot = 0; break;
    case 2: slot = 1; break;
    case 3: slot = 2; break;
    case 4: slot = 3; break;
    case 5: slot = 4; break;
    case 6: slot = 5; break;
    case 7: slot = 6; break;
    case 8: slot = 7; break;
    case 9:
        slot = 8;
        if (uVar4 != 0) {
            return -0x7fffbffb;
        }
        checkRange = false; // listing jumps straight to the encoding
        break;
    case 10: slot = 9; break;
    case 0xb: slot = 10; break;
    case 0xc: slot = 0xb; break;
    case 0xd: slot = 0xc; break;
    case 0xe: slot = 0xd; break;
    default:
        return -0x7fffbffb;
    }
    if (checkRange && 0xfu < uVar4) {
        return -0x7fffbffb;
    }
    uint32_t encoded = (uint32_t)slot | ((uVar4 | 0xffff8000u) << 0x10);

    iVar3 = FUN_006a48dd(0x1f);
    if (iVar3 < 0) {
        return iVar3;
    }
    iVar3 = FUN_006a2b66(encoded);
    if (iVar3 < 0) {
        return iVar3;
    }
    if ((*(uint8_t*)(self + 0x33) & 1) != 0) {
        iStack_c = 0;
        uStack_8 = 0;
        auStack_24[0] = 0xffffffffu;
        auStack_24[1] = 0xffffffffu;
        auStack_24[2] = 0xffffffffu;
        auStack_24[3] = 0xffffffffu;
        if (self[2] != 0) {
            iVar3 = *(int32_t*)(iVar6 + 4);
            int32_t* piVar9 = (int32_t*)self[5];
            do {
                int32_t iVar2 = *piVar9;
                if (iVar3 == *(int32_t*)(iVar2 + 4) &&
                    *(int32_t*)(iVar6 + 8) == *(int32_t*)(iVar2 + 8) &&
                    *(int32_t*)(iVar6 + 0xc) == *(int32_t*)(iVar2 + 0xc)) {
                    auStack_24[*(int32_t*)(iVar2 + 0x10)] = uStack_8;
                }
                uStack_8 = uStack_8 + 1;
                piVar9 = piVar9 + 1;
            } while (uStack_8 < self[2]);
        }
        uVar4 = 0;
        iVar3 = iStack_c;
        do {
            if (auStack_24[uVar4] != 0xffffffffu) {
                auStack_24[iVar3] = auStack_24[uVar4];
                iVar3 = iVar3 + 1;
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < 4);
        // vtable +0x70: remap the gathered stream list
        iVar3 = reinterpret_cast<int32_t(__thiscall*)(void*, uint32_t*, int32_t, int32_t*, uint32_t)>(
            *reinterpret_cast<uint32_t*>(self[0] + 0x70))(
            self, auStack_24, iVar3, &iStack_c, 1);
        if (iVar3 < 0) {
            return iVar3;
        }
    }
    // vtable +0x88: resolve the object's stream index
    iVar6 = reinterpret_cast<int32_t(__thiscall*)(void*, uint32_t*, uint32_t*)>(
        *reinterpret_cast<uint32_t*>(self[0] + 0x88))(self, (uint32_t*)iVar6, &uStack_10);
    if (iVar6 < 0) {
        return iVar6;
    }
    // vtable +0x64: declare the encoded destination
    iVar6 = reinterpret_cast<int32_t(__thiscall*)(void*, uint32_t, uint32_t, uint32_t)>(
        *reinterpret_cast<uint32_t*>(self[0] + 0x64))(
        self,
        (((uStack_10 | 0xfffffff8u) << 0x14 | (uStack_10 & 0x18)) << 8) |
            (auStack_24[4] & 0x7ff),
        0xf0000, 0);
    if (iVar6 < 0) {
        return iVar6;
    }
    // vtable +0x60: flush
    iVar6 = reinterpret_cast<int32_t(__thiscall*)(void*)>(
        *reinterpret_cast<uint32_t*>(self[0] + 0x60))(self);
    if (iVar6 < 0) {
        return iVar6;
    }
    iVar6 = FUN_0069fcf5();
    if (iVar6 < 0) {
        return iVar6;
    }
    if (param_2 == nullptr) {
        return 0;
    }
    *param_2 = encoded;
    return 0;
}

// 0x6828b5 — observed shape: pair up the operand slots of the current node.
// When the declared slot count is short it emits one 0x4e pair; otherwise it
// walks the slot array twice (local_14 = 0/1) and emits 0x4e/0x13 instruction
// pairs through 0x6a4aab, mirroring the second half onto local_30.
int32_t FUN_6828b5(uint32_t* self) {
    int32_t local_18 = 0;
    uint32_t local_30[4];

    if (*(uint32_t*)(self[0x40] + 4) < *(uint32_t*)(self[0x40] + 0xc)) {
        int32_t iVar1 = reinterpret_cast<int32_t(__thiscall*)(void*, uint32_t, void*, uint32_t,
                                                              uint32_t, uint32_t)>(
            *reinterpret_cast<uint32_t*>(self[0] + 0x80))(
            self, self[0x3f], local_30, 4, 0, 0);
        if (iVar1 < 0) {
            return iVar1;
        }
        iVar1 = FUN_006a4aab(0x4e, local_30 + 1, 1, *(uint32_t*)(self[0x40] + 8),
                             0, 0, 1, 0, 0, 0, 0);
        if (iVar1 < 0) {
            return iVar1;
        }
        int32_t iVar1b = (int32_t)self[0x40];
        uint32_t uVar3 = 0;
        if (*(int32_t*)(iVar1b + 0xc) != 0) {
            do {
                local_30[uVar3] = local_30[1];
                uVar3 = uVar3 + 1;
            } while (uVar3 < *(uint32_t*)(iVar1b + 0xc));
        }
        uint32_t uVar6 = *(uint32_t*)(self[0x40] + 0xc);
        iVar1 = FUN_006a4aab(1, *(uint32_t*)(self[0x40] + 0x10), uVar6, local_30,
                             0, 0, uVar6, 0, 0, 0, 0);
        if (iVar1 < 0) {
            return iVar1;
        }
    } else {
        uint32_t local_14 = 0;
        do {
            int32_t iVar1 = (int32_t)self[0x40];
            uint32_t local_1c = *(uint32_t*)(iVar1 + 0xc);
            uint32_t local_8 = 0;
            if (local_1c != 0) {
                uint32_t local_10 = 1;
                uint32_t local_c = 2;
                do {
                    int32_t iVar5 = (int32_t)(local_8 * 4);
                    int32_t* piVar2 = (int32_t*)(*(int32_t*)(iVar1 + 0x10) + iVar5);
                    int32_t local_20 = *(int32_t*)(*(int32_t*)(self[5] + *piVar2 * 4) + 0x10);
                    if (local_20 == 1 && local_c < local_1c) {
                        if (local_14 == 1) {
                            int32_t base10 = *(int32_t*)(self[0x40] + 0x10);
                            uint32_t* puVar4 =
                                (uint32_t*)(*(int32_t*)(self[0x40] + 8) + iVar5);
                            iVar1 = FUN_006a4aab(0x4e, base10 + iVar5, 1, puVar4,
                                                 0, 0, 1, 0, 0, 0, 0);
                            if (iVar1 < 0) {
                                return iVar1;
                            }
                        }
                        local_8 = local_8 + 1;
                        local_c = local_c + 1;
                        local_10 = local_10 + 1;
                    } else {
                        if (local_1c <= local_10) {
                            if (local_14 == 0) {
                                if (local_18 == 0) {
                                    iVar1 = reinterpret_cast<int32_t(__thiscall*)(
                                        void*, uint32_t, void*, uint32_t, uint32_t,
                                        uint32_t)>(*reinterpret_cast<uint32_t*>(
                                        self[0] + 0x80))(self, self[0x3f], local_30, 4, 0, 0);
                                    if (iVar1 < 0) {
                                        return iVar1;
                                    }
                                    local_18 = 1;
                                }
                                iVar1 = FUN_006a4aab(
                                    0x4e, local_30 + 1, 1,
                                    *(int32_t*)(self[0x40] + 8) + iVar5, 0, 0, 1, 0, 0, 0, 0);
                                if (iVar1 < 0) {
                                    return iVar1;
                                }
                                int32_t base10 = *(int32_t*)(self[0x40] + 0x10);
                                iVar1 = FUN_006a4aab(1, base10 + iVar5, 1, local_30 + 1,
                                                     0, 0, 1, 0, 0, 0, 0);
                                if (iVar1 < 0) {
                                    return iVar1;
                                }
                            }
                        } else if (local_20 == 0 &&
                                   *(int32_t*)(*(int32_t*)(self[5] + piVar2[1] * 4) + 0x10) == 1) {
                            if (local_14 == 1) {
                                int32_t base10 = *(int32_t*)(self[0x40] + 0x10);
                                uint32_t* puVar4 =
                                    (uint32_t*)(*(int32_t*)(self[0x40] + 8) + iVar5);
                                iVar1 = FUN_006a4aab(0x13, base10 + iVar5, 2, puVar4,
                                                     0, 0, 2, 0, 0, 0, 0);
                                if (iVar1 < 0) {
                                    return iVar1;
                                }
                            }
                        } else if (local_14 == 0) {
                            if (local_18 == 0) {
                                iVar1 = reinterpret_cast<int32_t(__thiscall*)(
                                    void*, uint32_t, void*, uint32_t, uint32_t,
                                    uint32_t)>(*reinterpret_cast<uint32_t*>(
                                    self[0] + 0x80))(self, self[0x3f], local_30, 4, 0, 0);
                                if (iVar1 < 0) {
                                    return iVar1;
                                }
                                local_18 = 1;
                            }
                            iVar1 = FUN_006a4aab(
                                0x13, local_30, 2,
                                *(int32_t*)(self[0x40] + 8) + iVar5, 0, 0, 2, 0, 0, 0, 0);
                            if (iVar1 < 0) {
                                return iVar1;
                            }
                            int32_t base10 = *(int32_t*)(self[0x40] + 0x10);
                            iVar1 = FUN_006a4aab(1, base10 + iVar5, 2, local_30,
                                                 0, 0, 2, 0, 0, 0, 0);
                            if (iVar1 < 0) {
                                return iVar1;
                            }
                        }
                        local_c = local_c + 2;
                        local_8 = local_8 + 2;
                        local_10 = local_10 + 2;
                    }
                    iVar1 = (int32_t)self[0x40];
                    local_1c = *(uint32_t*)(iVar1 + 0xc);
                } while (local_8 < local_1c);
            }
            local_14 = local_14 + 1;
        } while (local_14 < 2);
    }
    return 0;
}

// 0x682b7b — observed shape: emit the node's sampler/stream declarations.
// Skips when every slot carries the 0x02 flag (resolved through 0x6a6375 with
// opcode 0xe); otherwise, above revision 0x200 it uses 0x6a6375/0x4e, below it
// walks the slot pairs and emits 0x4e / mirrored 0x01 records via 0x6a4aab.
int32_t FUN_682b7b(uint32_t* self) {
    uint32_t uVar4 = *(uint32_t*)(self[0x40] + 0xc);
    uint32_t local_8 = 0;
    if (uVar4 != 0) {
        int32_t* piVar2 = *(int32_t**)(self[0x40] + 0x10);
        do {
            if ((*(uint8_t*)(*(int32_t*)(self[5] + *piVar2 * 4) + 3) & 2) == 0) break;
            local_8 = local_8 + 1;
            piVar2 = piVar2 + 1;
        } while (local_8 < uVar4);
    }
    if (local_8 < uVar4) {
        int32_t iVar3 = (int32_t)self[0x40];
        uint32_t uVar7 = *(uint32_t*)(iVar3 + 4);
        uint32_t uVar11 = *(uint32_t*)(iVar3 + 0xc);
        uint32_t uVar10 = *(uint32_t*)(iVar3 + 8);
        uint32_t uVar9 = *(uint32_t*)(iVar3 + 0x10);
        uint32_t uVar8 = 0xe;
        return FUN_006a6375((int32_t)uVar8, (int32_t)uVar9, (int32_t)uVar10,
                            (int32_t)uVar11, (int32_t)uVar7, 0, 0);
    }

    int32_t iVar3 = (int32_t)self[0x40];
    if ((self[0x32] & 0xffffu) < 0x200) {
        int32_t local_c = 0;
        uint32_t local_1c[4];
        if (*(uint32_t*)(iVar3 + 4) < *(uint32_t*)(iVar3 + 0xc)) {
            iVar3 = reinterpret_cast<int32_t(__thiscall*)(void*, uint32_t, void*, uint32_t,
                                                          uint32_t, uint32_t)>(
                *reinterpret_cast<uint32_t*>(self[0] + 0x80))(
                self, self[0x3f], local_1c, 4, 0, 0);
            if (iVar3 < 0) {
                return iVar3;
            }
            iVar3 = FUN_006a4aab(0x4e, local_1c + 2, 1, *(uint32_t*)(self[0x40] + 8),
                                 0, 0, 1, 0, 0, 0, 0);
            if (iVar3 < 0) {
                return iVar3;
            }
            iVar3 = (int32_t)self[0x40];
            uVar4 = 0;
            if (*(int32_t*)(iVar3 + 0xc) != 0) {
                do {
                    local_1c[uVar4] = local_1c[2];
                    uVar4 = uVar4 + 1;
                } while (uVar4 < *(uint32_t*)(iVar3 + 0xc));
            }
            uint32_t uVar7 = *(uint32_t*)(self[0x40] + 0xc);
            iVar3 = FUN_006a4aab(1, *(uint32_t*)(self[0x40] + 0x10), uVar7, local_1c,
                                 0, 0, uVar7, 0, 0, 0, 0);
            if (iVar3 < 0) {
                return iVar3;
            }
        } else {
            local_8 = 0;
            if (uVar4 != 0) {
                do {
                    int32_t iVar6 = (int32_t)(local_8 * 4);
                    int32_t iVar3b = *(int32_t*)(*(int32_t*)(self[5] +
                        *(int32_t*)(iVar6 + *(int32_t*)(self[0x40] + 0x10)) * 4) + 0x10);
                    uint32_t* puVar1 = *(uint32_t**)(self[5] +
                        *(int32_t*)(iVar6 + *(int32_t*)(self[0x40] + 8)) * 4);
                    uint32_t uVar7;
                    int32_t iVar3c;
                    uint32_t* puVar5;
                    if ((iVar3b == 0 && (*puVar1 & 2) != 0) || iVar3b == 2 ||
                        (iVar3b == 3 && (uVar4 = *puVar1, (uVar4 & 4) != 0) &&
                         (uVar4 & 8) != 0)) {
                        iVar3c = *(int32_t*)(self[0x40] + 0x10);
                        puVar5 = (uint32_t*)(*(int32_t*)(self[0x40] + 8) + iVar6);
                        uVar7 = 0x4e;
                    } else {
                        if (local_c == 0) {
                            iVar3 = reinterpret_cast<int32_t(__thiscall*)(
                                void*, uint32_t, void*, uint32_t, uint32_t,
                                uint32_t)>(*reinterpret_cast<uint32_t*>(self[0] + 0x80))(
                                self, self[0x3f], local_1c, 4, 0, 0);
                            if (iVar3 < 0) {
                                return iVar3;
                            }
                            local_c = 1;
                        }
                        iVar3 = FUN_006a4aab(0x4e, local_1c + 2, 1,
                                             *(int32_t*)(self[0x40] + 8) + iVar6,
                                             0, 0, 1, 0, 0, 0, 0);
                        if (iVar3 < 0) {
                            return iVar3;
                        }
                        puVar5 = local_1c + 2;
                        iVar3c = *(int32_t*)(self[0x40] + 0x10);
                        uVar7 = 1;
                    }
                    iVar3 = FUN_006a4aab(uVar7, iVar3c + iVar6, 1, puVar5,
                                         0, 0, 1, 0, 0, 0, 0);
                    if (iVar3 < 0) {
                        return iVar3;
                    }
                    local_8 = local_8 + 1;
                } while (local_8 < *(uint32_t*)(self[0x40] + 0xc));
            }
        }
        return 0;
    }

    uint32_t uVar7 = *(uint32_t*)(iVar3 + 4);
    uint32_t uVar11 = *(uint32_t*)(iVar3 + 0xc);
    uint32_t uVar10 = *(uint32_t*)(iVar3 + 8);
    uint32_t uVar9 = *(uint32_t*)(iVar3 + 0x10);
    uint32_t uVar8 = 0x4e;
    return FUN_006a6375((int32_t)uVar8, (int32_t)uVar9, (int32_t)uVar10,
                        (int32_t)uVar11, (int32_t)uVar7, 0, 0);
}

// 0x682db2 — observed shape: sibling of 0x682b7b using opcode 0x4f/0xf.
// Skips when every slot carries the 0x02 flag; otherwise 0x6a6375/0x4f above
// revision 0x200, and the 0x4f record walk with mirrored 0x01 records below it,
// where a slot whose element type is 2 uses itself as the mirror operand.
int32_t FUN_682db2(uint32_t* self) {
    uint32_t uVar3 = *(uint32_t*)(self[0x40] + 0xc);
    uint32_t local_8 = 0;
    if (uVar3 != 0) {
        int32_t* piVar1 = *(int32_t**)(self[0x40] + 0x10);
        do {
            if ((*(uint8_t*)(*(int32_t*)(self[5] + *piVar1 * 4) + 3) & 2) == 0) break;
            local_8 = local_8 + 1;
            piVar1 = piVar1 + 1;
        } while (local_8 < uVar3);
    }
    if (local_8 < uVar3) {
        int32_t iVar2 = (int32_t)self[0x40];
        uint32_t uVar5 = *(uint32_t*)(iVar2 + 4);
        uint32_t uVar9 = *(uint32_t*)(iVar2 + 0xc);
        uint32_t uVar8 = *(uint32_t*)(iVar2 + 8);
        uint32_t uVar7 = *(uint32_t*)(iVar2 + 0x10);
        uint32_t uVar6 = 0xf;
        return FUN_006a6375((int32_t)uVar6, (int32_t)uVar7, (int32_t)uVar8,
                            (int32_t)uVar9, (int32_t)uVar5, 0, 0);
    }

    int32_t iVar2 = (int32_t)self[0x40];
    if ((self[0x32] & 0xffffu) < 0x200) {
        int32_t local_c = 0;
        uint32_t local_1c[4];
        if (*(uint32_t*)(iVar2 + 4) < *(uint32_t*)(iVar2 + 0xc)) {
            iVar2 = reinterpret_cast<int32_t(__thiscall*)(void*, uint32_t, void*, uint32_t,
                                                          uint32_t, uint32_t)>(
                *reinterpret_cast<uint32_t*>(self[0] + 0x80))(
                self, self[0x3f], local_1c, 4, 0, 0);
            if (iVar2 < 0) {
                return iVar2;
            }
            iVar2 = FUN_006a4aab(0x4f, local_1c + 2, 1, *(uint32_t*)(self[0x40] + 8),
                                 0, 0, 1, 0, 0, 0, 0);
            if (iVar2 < 0) {
                return iVar2;
            }
            iVar2 = (int32_t)self[0x40];
            uVar3 = 0;
            if (*(int32_t*)(iVar2 + 0xc) != 0) {
                do {
                    local_1c[uVar3] = local_1c[2];
                    uVar3 = uVar3 + 1;
                } while (uVar3 < *(uint32_t*)(iVar2 + 0xc));
            }
            uint32_t uVar5b = *(uint32_t*)(self[0x40] + 0xc);
            iVar2 = FUN_006a4aab(1, *(uint32_t*)(self[0x40] + 0x10), uVar5b, local_1c,
                                 0, 0, uVar5b, 0, 0, 0, 0);
            if (iVar2 < 0) {
                return iVar2;
            }
        } else {
            local_8 = 0;
            if (uVar3 != 0) {
                do {
                    int32_t iVar2b = (int32_t)(local_8 * 4);
                    uint32_t uVar5b;
                    int32_t iVar2c;
                    uint32_t* puVar4;
                    if (*(int32_t*)(*(int32_t*)(self[5] +
                        *(int32_t*)(iVar2b + *(int32_t*)(self[0x40] + 0x10)) * 4) + 0x10) == 2) {
                        puVar4 = (uint32_t*)(*(int32_t*)(self[0x40] + 8) + iVar2b);
                        iVar2c = *(int32_t*)(self[0x40] + 0x10) + iVar2b;
                        uVar5b = 0x4f;
                    } else {
                        if (local_c == 0) {
                            iVar2 = reinterpret_cast<int32_t(__thiscall*)(
                                void*, uint32_t, void*, uint32_t, uint32_t,
                                uint32_t)>(*reinterpret_cast<uint32_t*>(self[0] + 0x80))(
                                self, self[0x3f], local_1c, 4, 0, 0);
                            if (iVar2 < 0) {
                                return iVar2;
                            }
                            local_c = 1;
                        }
                        iVar2 = FUN_006a4aab(0x4f, local_1c + 2, 1,
                                             *(int32_t*)(self[0x40] + 8) + local_8 * 4,
                                             0, 0, 1, 0, 0, 0, 0);
                        if (iVar2 < 0) {
                            return iVar2;
                        }
                        puVar4 = local_1c + 2;
                        iVar2c = *(int32_t*)(self[0x40] + 0x10) + local_8 * 4;
                        uVar5b = 1;
                    }
                    iVar2 = FUN_006a4aab(uVar5b, iVar2c, 1, puVar4, 0, 0, 1, 0, 0, 0, 0);
                    if (iVar2 < 0) {
                        return iVar2;
                    }
                    local_8 = local_8 + 1;
                } while (local_8 < *(uint32_t*)(self[0x40] + 0xc));
            }
        }
        return 0;
    }

    uint32_t uVar5 = *(uint32_t*)(iVar2 + 4);
    uint32_t uVar9 = *(uint32_t*)(iVar2 + 0xc);
    uint32_t uVar8 = *(uint32_t*)(iVar2 + 8);
    uint32_t uVar7 = *(uint32_t*)(iVar2 + 0x10);
    uint32_t uVar6 = 0x4f;
    return FUN_006a6375((int32_t)uVar6, (int32_t)uVar7, (int32_t)uVar8,
                        (int32_t)uVar9, (int32_t)uVar5, 0, 0);
}

// 0x682fbc — observed shape: recursive slot resolution. Refuses revision below
// 0x101; walks self[1][8] (previous slot) depth-first, then, unless the slot is
// already current (self[0x4e]), drives +0x64/+0x74/+0x78/+0x68/+0x60 and
// 0x69fcf5 to declare and commit the slot.
int32_t FUN_682fbc(uint32_t* self, int32_t param_1) {
    int32_t iVar1 = *(int32_t*)(self[5] + param_1 * 4);
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;
    int32_t iVar2;
    if ((self[0x32] & 0xffffu) < 0x101) {
        FUN_006626da();
        iVar2 = -0x7fffbfff;
    } else {
        iVar2 = *(int32_t*)(iVar1 + 8);
        bool recurseOk = true;
        if (iVar2 != -1) {
            iVar2 = FUN_682fbc(self, iVar2);
            recurseOk = (iVar2 > -1);
        }
        if (recurseOk) {
            if (self[0x4e] == (uint32_t)param_1) {
                iVar2 = 0;
            } else {
                iVar2 = FUN_006a48dd(1);
                if (-1 < iVar2 &&
                    (iVar2 = reinterpret_cast<int32_t(__thiscall*)(void*, uint32_t, uint32_t,
                                                                   uint32_t)>(
                         *reinterpret_cast<uint32_t*>(self[0] + 0x64))(
                         self, 0xb0000000u, 0x10000, 0), -1 < iVar2) &&
                    (iVar2 = reinterpret_cast<int32_t(__thiscall*)(void*, uint32_t, void*,
                                                                   void*)>(
                         *reinterpret_cast<uint32_t*>(self[0] + 0x74))(
                         self, (uint32_t)iVar1, &local_10, &local_8), -1 < iVar2) &&
                    (iVar2 = reinterpret_cast<int32_t(__thiscall*)(void*, void*, uint32_t,
                                                                   uint32_t, void*)>(
                         *reinterpret_cast<uint32_t*>(self[0] + 0x78))(
                         self, &param_1, 1, 0x10000, &local_c), -1 < iVar2) &&
                    (iVar2 = reinterpret_cast<int32_t(__thiscall*)(void*, uint32_t, uint32_t,
                                                                   uint32_t)>(
                         *reinterpret_cast<uint32_t*>(self[0] + 0x68))(
                         self, local_10, local_c, local_8), -1 < iVar2) &&
                    (iVar2 = reinterpret_cast<int32_t(__thiscall*)(void*)>(
                         *reinterpret_cast<uint32_t*>(self[0] + 0x60))(self), -1 < iVar2) &&
                    (iVar2 = FUN_0069fcf5(), -1 < iVar2)) {
                    self[0x4e] = (uint32_t)param_1;
                    iVar2 = 0;
                }
            }
        }
    }
    return iVar2;
}

// 0x6830e6 — observed shape: rebuild the destination list of one program node.
// For every (blob[0] & 0xfffff)-sized group it locates the source operands of
// element type 0/1/2/3 (self+0x14 objects, 0x1000000x index bloBs at self+0x18),
// checks that destinations do not alias, sorts the destination list by element
// type and stamps the new object into self[0x18][local_3c]. Stores the error
// text "internal error: DST test failure" via 0x6626da on mismatch.
int32_t FUN_6830e6(uint8_t* self) {
    int32_t aiStack_64[4];
    uint32_t local_54[5];
    uint32_t local_40;
    uint32_t local_3c;
    uint32_t local_38;
    uint32_t local_34;
    int32_t* local_30;
    uint32_t* local_2c;
    uint32_t* local_28;
    uint8_t* local_24;
    int32_t* local_20;
    int32_t* local_1c;
    int32_t local_18 = 0;
    uint32_t local_14;
    int32_t local_10;
    int32_t local_c;
    uint32_t local_8;

    uint32_t* local_blk = *(uint32_t**)(self + 0x100);
    local_14 = *local_blk & 0xfffffu;
    if (local_14 == 0) {
        return 1;
    }
    local_54[4] = local_blk[1] / local_14;
    local_40 = 0;
    if (local_54[4] != 0) {
        local_34 = 0;
        local_24 = self;
        do {
            int32_t iVar9 = -1;
            local_54[0] = 0xffffffffu;
            local_54[1] = 0xffffffffu;
            local_54[2] = 0xffffffffu;
            local_8 = 0;
            local_20 = nullptr;
            local_1c = nullptr;
            local_28 = nullptr;
            local_2c = nullptr;
            local_54[3] = 0xffffffffu;
            local_10 = -1;
            local_c = -1;
            if (local_14 != 0) {
                local_30 = (int32_t*)(*(int32_t*)(*(int32_t*)(self + 0x100) + 8) + local_34);
                local_3c = local_14;
                do {
                    uint32_t uVar3 = local_8;
                    int32_t iVar10 = *local_30;
                    int32_t iVar7 = *(int32_t*)(*(int32_t*)(self + 0x14) + iVar10 * 4);
                    int32_t iVar1 = *(int32_t*)(iVar7 + 0x10);
                    bool handled = false;
                    if (iVar1 == 0) {
                        if (*(int32_t*)(iVar7 + 0x48) != -1 && local_20 == nullptr) {
                            uint32_t uVar6 = *(uint32_t*)(iVar7 + 0x48);
                            local_20 = *(int32_t**)(*(int32_t*)(self + 0x18) + uVar6 * 4);
                            local_54[local_8] = uVar6;
                            aiStack_64[uVar3] = iVar10;
                            iVar10 = iVar9;
                            handled = true;
                        }
                    } else if (iVar1 == 1) {
                        if (*(int32_t*)(iVar7 + 0x48) != -1 && local_1c == nullptr) {
                            uint32_t uVar6 = *(uint32_t*)(iVar7 + 0x48);
                            local_1c = *(int32_t**)(*(int32_t*)(self + 0x18) + uVar6 * 4);
                            local_54[local_8] = uVar6;
                            aiStack_64[uVar3] = iVar10;
                            iVar10 = iVar9;
                            handled = true;
                        }
                    } else if (iVar1 == 2) {
                        if (iVar9 == -1) {
                            iVar9 = *(int32_t*)(iVar7 + 0x48);
                            local_54[local_8] = 0xffffffffu;
                            local_10 = iVar10;
                            aiStack_64[uVar3] = iVar10;
                            if (iVar9 != -1) {
                                local_28 = *(uint32_t**)(*(int32_t*)(self + 0x18) + iVar9 * 4);
                                if ((*local_28 & 0xfff00000u) == 0x10000000u) {
                                    uint32_t uVar6 = 0;
                                    uint32_t uVar3b = *local_28 & 0xfffffu;
                                    if (uVar3b != 0) {
                                        int32_t* piVar4 = (int32_t*)local_28[4];
                                        do {
                                            if (*piVar4 == iVar10) {
                                                local_10 = *(int32_t*)(local_28[2] + uVar6 * 4);
                                                iVar10 = local_10;
                                                break;
                                            }
                                            uVar6 = uVar6 + 1;
                                            piVar4 = piVar4 + 1;
                                        } while (uVar6 < uVar3b);
                                    }
                                } else {
                                    local_28 = nullptr;
                                }
                            }
                            handled = true;
                        }
                    } else if (iVar1 == 3 && local_c == -1) {
                        iVar7 = *(int32_t*)(iVar7 + 0x48);
                        local_54[local_8] = 0xffffffffu;
                        local_c = iVar10;
                        aiStack_64[uVar3] = iVar10;
                        iVar10 = iVar9;
                        if (iVar7 != -1) {
                            local_2c = *(uint32_t**)(*(int32_t*)(self + 0x18) + iVar7 * 4);
                            if ((*local_2c & 0xfff00000u) == 0x10000000u) {
                                uint32_t uVar6 = 0;
                                uint32_t uVar3b = *local_2c & 0xfffffu;
                                if (uVar3b != 0) {
                                    int32_t* piVar4 = (int32_t*)local_2c[4];
                                    do {
                                        if (*piVar4 == local_c) {
                                            local_c = *(int32_t*)(local_2c[2] + uVar6 * 4);
                                            break;
                                        }
                                        uVar6 = uVar6 + 1;
                                        piVar4 = piVar4 + 1;
                                    } while (uVar6 < uVar3b);
                                    iVar10 = local_10;
                                }
                            } else {
                                local_2c = nullptr;
                            }
                        }
                        handled = true;
                    }
                    if (handled) {
                        local_8 = local_8 + 1;
                        iVar9 = iVar10;
                    }
                    local_30 = local_30 + 1;
                    local_3c = local_3c - 1;
                } while (local_3c != 0);
            }
            if (local_8 == local_14 && 1 < local_8) {
                bool bVar2 = false;
                if (local_1c != nullptr) {
                    if (*local_1c != 0x20500001) {
                        bVar2 = true;
                    } else {
                        if (iVar9 != -1 && iVar9 != *(int32_t*)local_1c[2] &&
                            iVar9 != ((int32_t*)local_1c[2])[1]) {
                            bVar2 = true;
                        }
                        if (local_c != -1) {
                            if (local_c != *(int32_t*)local_1c[2] &&
                                local_c != ((int32_t*)local_1c[2])[1]) {
                                bVar2 = true;
                            }
                            if (iVar9 != -1) {
                                int32_t* piVar4 = (int32_t*)local_1c[2];
                                if (local_c == iVar9) {
                                    if (*piVar4 != piVar4[1]) {
                                        bVar2 = true;
                                    }
                                } else if (*piVar4 == piVar4[1]) {
                                    bVar2 = true;
                                }
                            }
                        }
                    }
                }
                bool skipGroup = false;
                if (local_20 != nullptr) {
                    if (*local_20 != 0x10000001) {
                        skipGroup = true;
                    } else {
                        int32_t iVar9b = *(int32_t*)(*(int32_t*)(self + 0x14) +
                                                     *(int32_t*)local_20[2] * 4);
                        if ((*(uint8_t*)(*(int32_t*)(*(int32_t*)(self + 0x10) +
                                                     *(int32_t*)(iVar9b + 4) * 4) + 5) & 1) == 0 ||
                            *(double*)(iVar9b + 0x20) != 1.0) {
                            bVar2 = true;
                        }
                    }
                }
                if (!skipGroup && !bVar2) {
                    local_3c = 0;
                    if (local_8 != 0) {
                        do {
                            local_38 = local_54[local_3c];
                            if (local_38 != 0xffffffffu) {
                                local_18 = 1;
                                local_20 = (int32_t*)(uintptr_t)local_14;
                                if (local_14 != 0) {
                                    int32_t* piVar4 = (int32_t*)(*(int32_t*)(*(int32_t*)(self + 0x100) + 8) +
                                                                 local_34);
                                    local_30 = (int32_t*)(uintptr_t)local_14;
                                    do {
                                        int32_t iVar9c = *(int32_t*)(*(int32_t*)(self + 0x14) +
                                                                     *piVar4 * 4);
                                        if (*(uint32_t*)(iVar9c + 0x50) <
                                            *(uint32_t*)(self + 0xfc)) {
                                            local_18 = 0;
                                        }
                                        if (local_38 < *(uint32_t*)(iVar9c + 0x4c)) {
                                            local_18 = 0;
                                        }
                                        if ((local_28 == nullptr &&
                                             *(int32_t*)(iVar9c + 0x10) == 2) ||
                                            (local_2c == nullptr &&
                                             *(int32_t*)(iVar9c + 0x10) == 3)) {
                                            local_20 = (int32_t*)((uintptr_t)local_20 - 1);
                                        } else if (*(uint32_t*)(iVar9c + 0x54) < local_38) {
                                            local_18 = 0;
                                        }
                                        piVar4 = piVar4 + 1;
                                        local_30 = (int32_t*)((uintptr_t)local_30 - 1);
                                    } while (local_30 != nullptr);
                                }
                                int32_t* piVar4b = local_20;
                                local_30 = nullptr;
                                do {
                                    if (local_54[(intptr_t)local_30] != 0xffffffffu) {
                                        int32_t iVar9d = *(int32_t*)(*(int32_t*)(self + 0x18) +
                                            local_54[(intptr_t)local_30] * 4);
                                        int32_t iVar10b = *(int32_t*)(iVar9d + 4);
                                        if (iVar10b != 0) {
                                            int32_t* piVar5 = *(int32_t**)(iVar9d + 8);
                                            do {
                                                iVar9d = *(int32_t*)(*(int32_t*)(self + 0x14) +
                                                                     *piVar5 * 4);
                                                uint32_t uVar3c = *(uint32_t*)(iVar9d + 0x48);
                                                if ((local_38 < uVar3c &&
                                                     uVar3c != 0xffffffffu) ||
                                                    *(uint32_t*)(iVar9d + 0x50) < local_38) {
                                                    local_18 = 0;
                                                }
                                                piVar5 = piVar5 + 1;
                                                iVar10b = iVar10b - 1;
                                            } while (iVar10b != 0);
                                            self = local_24;
                                        }
                                    }
                                    local_30 = (int32_t*)((uintptr_t)local_30 + 1);
                                } while ((intptr_t)local_30 < (intptr_t)local_8);
                                if (local_18 != 0) {
                                    local_3c = local_54[local_3c];
                                    if (local_3c != 0xffffffffu &&
                                        (uintptr_t)piVar4b > 1) {
                                        int32_t iVar9e = FUN_0065d0b4(0x74);
                                        if (iVar9e == 0) {
                                            iVar9e = 0;
                                        } else {
                                            iVar9e = FUN_0065cc1a();
                                        }
                                        if (iVar9e == 0) {
                                            return -0x7ff8fff2;
                                        }
                                        int32_t iVar10c = FUN_0065d0ff(
                                            ((uint32_t)(uintptr_t)piVar4b & 0xfffffu) | 0x70900000u,
                                            (int32_t)((intptr_t)piVar4b * 2),
                                            (int32_t)(intptr_t)piVar4b, 0);
                                        if (iVar10c < 0 ||
                                            (iVar10c = FUN_0065cc50(
                                                 *(uint32_t*)(self + 0x100)), iVar10c < 0)) {
                                            FUN_00614343(1);
                                            return iVar10c;
                                        }
                                        uint32_t uVar3d = 0;
                                        uint32_t count = (uint32_t)(uintptr_t)piVar4b;
                                        int32_t iVar10d = (int32_t)((intptr_t)piVar4b << 2);
                                        do {
                                            int32_t slot = -1;
                                            bool have = false;
                                            if (local_1c == nullptr) {
                                                bool ok;
                                                if (local_c == -1) {
                                                    slot = local_10;
                                                    ok = (local_10 != -1);
                                                } else {
                                                    slot = local_c;
                                                    ok = (local_10 == -1);
                                                }
                                                have = ok;
                                            } else {
                                                *(int32_t*)(*(int32_t*)(iVar9e + 8) + uVar3d * 4) =
                                                    *(int32_t*)local_1c[2];
                                                slot = *(int32_t*)(local_1c[2] + 4);
                                                have = true;
                                            }
                                            if (!have) {
                                                FUN_006626da(
                                                    local_24,
                                                    *(uint32_t*)(*(int32_t*)(self + 0x100) + 0x3c),
                                                    0x12d9u,
                                                    "internal error: DST test failure");
                                                FUN_00614343(1);
                                                return 1;
                                            }
                                            *(int32_t*)(iVar10d +
                                                *(int32_t*)(iVar9e + 8)) = slot;
                                            uVar3d = uVar3d + 1;
                                            iVar10d = iVar10d + 4;
                                        } while (uVar3d < count);

                                        uint32_t uVar3e = 0;
                                        uint32_t uVar6 = 0;
                                        if (local_8 != 0) {
                                            do {
                                                int32_t iVar10f = *(int32_t*)(*(int32_t*)(self + 0x14) +
                                                                              aiStack_64[uVar3e] * 4);
                                                if ((local_28 != nullptr ||
                                                     *(int32_t*)(iVar10f + 0x10) != 2) &&
                                                    (local_2c != nullptr ||
                                                     *(int32_t*)(iVar10f + 0x10) != 3)) {
                                                    *(int32_t*)(*(int32_t*)(iVar9e + 0x10) + uVar6 * 4) =
                                                        aiStack_64[uVar3e];
                                                    uVar6 = uVar6 + 1;
                                                }
                                                if ((uint32_t)(uintptr_t)piVar4b < uVar6) {
                                                    FUN_006626da(
                                                        local_24,
                                                        *(uint32_t*)(*(int32_t*)(local_24 + 0x100) + 0x3c),
                                                        0x12dau,
                                                        "internal error: DST test failure");
                                                    FUN_00614343(1);
                                                    return 1;
                                                }
                                                uVar3e = uVar3e + 1;
                                                self = local_24;
                                            } while (uVar3e < local_8);
                                        }

                                        uVar3e = *(uint32_t*)(iVar9e + 0xc);
                                        local_14 = 0;
                                        if (uVar3e != 0) {
                                            local_40 = 1;
                                            do {
                                                uint32_t local_34b = local_40;
                                                if (local_40 < uVar3e) {
                                                    do {
                                                        int32_t iVar10g = *(int32_t*)(
                                                            *(int32_t*)(self + 0x14) +
                                                            *(int32_t*)(*(int32_t*)(iVar9e + 0x10) +
                                                                        local_14 * 4) * 4);
                                                        int32_t iVar7g = *(int32_t*)(
                                                            *(int32_t*)(self + 0x14) +
                                                            *(int32_t*)(local_34b * 4 +
                                                                *(int32_t*)(iVar9e + 0x10)) * 4);
                                                        if (*(uint32_t*)(iVar7g + 0x10) <
                                                            *(uint32_t*)(iVar10g + 0x10)) {
                                                            uint32_t* puVar8 = (uint32_t*)(
                                                                local_34b * 4 +
                                                                *(int32_t*)(iVar9e + 0x10));
                                                            uint32_t tmp = *puVar8;
                                                            *puVar8 = *(uint32_t*)(
                                                                *(int32_t*)(iVar9e + 0x10) +
                                                                local_14 * 4);
                                                            *(uint32_t*)(
                                                                *(int32_t*)(iVar9e + 0x10) +
                                                                local_14 * 4) = tmp;
                                                            self = local_24;
                                                        }
                                                        if (*(int32_t*)(iVar10g + 0x10) ==
                                                            *(int32_t*)(iVar7g + 0x10)) {
                                                            FUN_006626da(
                                                                self,
                                                                *(uint32_t*)(*(int32_t*)(self + 0x100) + 0x3c),
                                                                0x12dbu,
                                                                "internal error: multiple write to same output");
                                                            FUN_00614343(1);
                                                            return -0x7fffbffb;
                                                        }
                                                        local_34b = local_34b + 1;
                                                    } while (local_34b <
                                                             *(uint32_t*)(iVar9e + 0xc));
                                                }
                                                local_14 = local_14 + 1;
                                                uVar3e = *(uint32_t*)(iVar9e + 0xc);
                                                local_40 = local_40 + 1;
                                            } while (local_14 < uVar3e);
                                        }

                                        uVar3e = 0;
                                        if (local_8 != 0) {
                                            do {
                                                if (local_54[uVar3e] != 0xffffffffu) {
                                                    **(uint32_t**)(*(int32_t*)(self + 0x18) +
                                                        local_54[uVar3e] * 4) = 0;
                                                }
                                                uVar3e = uVar3e + 1;
                                            } while (uVar3e < local_8);
                                        }
                                        if (local_28 != nullptr) {
                                            if (*local_28 == 0x10000001u) {
                                                *local_28 = 0;
                                            } else if (*local_28 == 0x10000002u) {
                                                int32_t* piVar4 = (int32_t*)local_28[2];
                                                if (*piVar4 == local_10 &&
                                                    piVar4[1] == local_c) {
                                                    *local_28 = 0;
                                                }
                                                if (piVar4[1] == local_10 &&
                                                    *piVar4 == local_c) {
                                                    *local_28 = 0;
                                                }
                                            }
                                        }
                                        if (local_2c != nullptr) {
                                            if (*local_2c == 0x10000001u) {
                                                *local_2c = 0;
                                            } else if (*local_2c == 0x10000002u) {
                                                int32_t* piVar4 = (int32_t*)local_2c[2];
                                                bool m1 = (*piVar4 == local_10 &&
                                                           piVar4[1] == local_c);
                                                bool m2 = (piVar4[1] == local_10 &&
                                                           *piVar4 == local_c);
                                                if (m1 || m2) {
                                                    *local_2c = 0;
                                                }
                                            }
                                        }
                                        int32_t iVar10h = (int32_t)(local_3c * 4);
                                        if (*(int32_t*)(iVar10h +
                                            *(int32_t*)(self + 0x18)) != 0) {
                                            FUN_00614343(1);
                                        }
                                        *(int32_t*)(iVar10h + *(int32_t*)(self + 0x18)) = iVar9e;
                                        return 0;
                                    }
                                    break;
                                }
                            }
                            local_3c = local_3c + 1;
                        } while (local_3c < local_8);
                    }
                }
            }
            local_40 = local_40 + 1;
            local_34 = local_34 + local_14 * 4;
        } while (local_40 < local_54[4]);
    }
    return 1;
}

// 0x683768 — observed shape: program rebuild driver. Passes a 0x20800000 scan,
// then (unless bit 2 of self+0xcc is set) the 0x6830e6 rebuild, the 0x682188
// collapse for 0x50000000 nodes, 0x6959c5, and 0x6992d0 for the
// 0x103/0x105/0x106/0x107/0x500 families; finally a bounded retry loop over
// 0x69632a/0x65db2e/0x65e4f2, then 0x6a2842/0x6959c5/0x664b28.
int32_t FUN_683768(uint8_t* self) {
    bool bVar2 = false;
    if (*(int32_t*)(self + 0x5c) != 0) {
        *(uint32_t*)(self + 0xfc) = 0;
        if (*(int32_t*)(self + 0xc) != 0) {
            do {
                uint32_t* puVar1 = *(uint32_t**)(*(int32_t*)(self + 0x18) +
                                                 *(int32_t*)(self + 0xfc) * 4);
                *(uint32_t**)(self + 0x100) = puVar1;
                if ((*puVar1 & 0xfff00000u) == 0x20800000u) {
                    int32_t iVar3 = FUN_00695e74();
                    if (iVar3 < 0) {
                        return iVar3;
                    }
                    bVar2 = (bool)(bVar2 | (iVar3 == 0));
                }
                *(int32_t*)(self + 0xfc) = *(int32_t*)(self + 0xfc) + 1;
            } while (*(uint32_t*)(self + 0xfc) < *(uint32_t*)(self + 0xc));
            if (bVar2) {
                FUN_006959c5();
            }
        }
    }

    if ((*(uint8_t*)(self + 0xcc) & 4) == 0) {
        uint32_t uVar5 = 0;
        if (*(int32_t*)(self + 0xc) != 0) {
            do {
                *(uint32_t*)(self + 0xfc) = uVar5;
                *(uint32_t*)(self + 0x100) =
                    *(uint32_t*)(*(int32_t*)(self + 0x18) + uVar5 * 4);
                int32_t iVar3 = FUN_6830e6(self);
                if (iVar3 == 0) {
                    FUN_006959c5();
                }
                uVar5 = uVar5 + 1;
            } while (uVar5 < *(uint32_t*)(self + 0xc));
        }
        uVar5 = 0;
        if (*(int32_t*)(self + 0xc) != 0) {
            do {
                *(uint32_t*)(self + 0xfc) = uVar5;
                uint32_t* puVar1 = *(uint32_t**)(*(int32_t*)(self + 0x18) + uVar5 * 4);
                *(uint32_t**)(self + 0x100) = puVar1;
                if ((*puVar1 & 0xfff00000u) == 0x50000000u) {
                    int32_t iVar3 = FUN_682188((uint32_t*)self);
                    if (iVar3 < 0) {
                        return iVar3;
                    }
                }
                uVar5 = uVar5 + 1;
            } while (uVar5 < *(uint32_t*)(self + 0xc));
        }
        FUN_006959c5();
        uVar5 = 0;
        if (*(int32_t*)(self + 0xc) != 0) {
            do {
                *(uint32_t*)(self + 0xfc) = uVar5;
                uint32_t* puVar1 = *(uint32_t**)(*(int32_t*)(self + 0x18) + uVar5 * 4);
                *(uint32_t**)(self + 0x100) = puVar1;
                uint32_t uVar4 = *puVar1 & 0xfff00000u;
                if (uVar4 == 0x10300000u || uVar4 == 0x10500000u ||
                    uVar4 == 0x10600000u || uVar4 == 0x10700000u ||
                    uVar4 == 0x50000000u) {
                    int32_t iVar3 = FUN_006992d0();
                    if (iVar3 < 0) {
                        return iVar3;
                    }
                }
                uVar5 = uVar5 + 1;
            } while (uVar5 < *(uint32_t*)(self + 0xc));
        }
    }

    if (*(int32_t*)(self + 0x30) != 0) {
        uint32_t local_c = 0;
        do {
            if (0xf < local_c) {
                break; // listing jumps into the error pass
            }
            uint32_t uVar5 = *(uint32_t*)(self + 0xc);
            uint32_t uVar4 = 0;
            bVar2 = true;
            if (uVar5 != 0) {
                do {
                    *(uint32_t*)(self + 0x100) =
                        *(uint32_t*)(*(int32_t*)(self + 0x18) + uVar4 * 4);
                    int32_t iVar3 = FUN_0069632a();
                    if (iVar3 < 0) {
                        return iVar3;
                    }
                    if (iVar3 == 0) {
                        bVar2 = false;
                    }
                    iVar3 = FUN_0065db2e(*(uint32_t*)(self + 0x100));
                    if (iVar3 < 0) {
                        return iVar3;
                    }
                    **(uint32_t**)(self + 0x100) = 0;
                    uVar4 = uVar4 + 1;
                } while (uVar4 < uVar5);
            }
            int32_t iVar3 = FUN_0065e4f2();
            if (iVar3 < 0) {
                return iVar3;
            }
            local_c = local_c + 1;
        } while (!bVar2);
        if (0xf < local_c) {
            // error pass: report each unresolvable node and tear it down
            uint32_t uVar5 = *(uint32_t*)(self + 0xc);
            uint32_t uVar4 = 0;
            bVar2 = true;
            if (uVar5 != 0) {
                do {
                    *(uint32_t*)(self + 0x100) =
                        *(uint32_t*)(*(int32_t*)(self + 0x18) + uVar4 * 4);
                    int32_t iVar3 = FUN_0069632a();
                    if (iVar3 < 0) {
                        return iVar3;
                    }
                    if (iVar3 == 0) {
                        FUN_006626da();
                        bVar2 = false;
                    }
                    iVar3 = FUN_0065db2e(*(uint32_t*)(self + 0x100));
                    if (iVar3 < 0) {
                        return iVar3;
                    }
                    **(uint32_t**)(self + 0x100) = 0;
                    uVar4 = uVar4 + 1;
                } while (uVar4 < uVar5);
            }
            int32_t iVar3 = FUN_0065e4f2();
            if (iVar3 < 0) {
                return iVar3;
            }
            if (!bVar2) {
                return -0x7fffbffb;
            }
        }
    }

    if (*(int32_t*)(self + 0x60) != 0) {
        int32_t iVar3 = FUN_006a2842();
        if (iVar3 < 0) {
            return iVar3;
        }
        FUN_006959c5();
        iVar3 = FUN_00664b28();
        if (iVar3 < 0) {
            return iVar3;
        }
    }
    return 0;
}

// 0x6839e3 — observed shape: stream bucket validation, sibling of 0x68163f.
// 0x705/0x706/0x707 blobs are forced to two elements; buckets are self[0x1f],
// self[0x20], self[0x22] with the 3/1/1 limits, and above revision 0x1ff more
// than two self[0x1f] hits abort with the offending index.
uint32_t FUN_6839e3(uint32_t* self, uint32_t* param_1, uint32_t* param_2) {
    if (param_1 == nullptr) {
        return 1;
    }
    uint32_t uVar7 = *param_1 & 0xfff00000u;
    if (uVar7 == 0 || uVar7 == 0x20700000u) {
        return 0;
    }
    uint32_t uVar5 = *param_1 & 0xfffffu;
    uint32_t local_14 = param_1[1] / uVar5;
    if (uVar7 == 0x70500000u || uVar7 == 0x70600000u || uVar7 == 0x70700000u) {
        local_14 = 2;
    }
    if (local_14 <= 1) {
        return 0;
    }
    uint32_t auStack_b0[18];
    uint32_t auStack_68[18];
    int32_t iVar2 = (int32_t)self[0x20];
    int32_t iVar6 = (int32_t)self[0x22];
    int32_t iVar3 = (int32_t)self[0x1f];
    auStack_68[iVar2] = 0;
    auStack_68[iVar6] = 0;
    auStack_68[iVar3] = 0;
    auStack_b0[iVar2] = 1;
    auStack_b0[iVar6] = 3;
    auStack_b0[iVar3] = 1;
    uint32_t local_18 = 0;
    uint32_t local_10 = 0;
    if (local_14 != 0) {
        int32_t local_1c = 0;
        int32_t local_20 = (int32_t)(uVar5 << 2);
        do {
            int32_t iVar2b = *(int32_t*)(self[5] +
                *(int32_t*)(local_1c + param_1[2]) * 4);
            uint32_t u = *(uint32_t*)(*(int32_t*)(self[4] +
                *(int32_t*)(iVar2b + 4) * 4) + 4);
            uint32_t bucket;
            if ((u & 0x200) == 0) {
                if ((int8_t)u < 0) {
                    bucket = self[0x25];
                } else if ((u & 0x10) == 0 ||
                           (iVar6 = reinterpret_cast<int32_t(__thiscall*)(void*, uint32_t)>(
                                *reinterpret_cast<uint32_t*>(self[0] + 0x54))(
                                self, *(uint32_t*)(iVar2b + 0x6c)),
                            iVar6 == 0xffff)) {
                    bucket = self[0x22];
                } else {
                    bucket = self[0x20];
                }
            } else if ((int8_t)u < 0) {
                bucket = self[0x25];
            } else {
                bucket = self[0x1f];
            }
            uint32_t local_c = 0;
            uint32_t local_8 = bucket;
            if (local_10 != 0) {
                int32_t* piVar8 = (int32_t*)param_1[2];
                do {
                    iVar3 = *(int32_t*)(self[5] + *piVar8 * 4);
                    if (*(int32_t*)(iVar2b + 4) == *(int32_t*)(iVar3 + 4) &&
                        *(int32_t*)(iVar2b + 8) == *(int32_t*)(iVar3 + 8) &&
                        *(int32_t*)(iVar2b + 0xc) == *(int32_t*)(iVar3 + 0xc)) {
                        break;
                    }
                    local_c = local_c + 1;
                    piVar8 = (int32_t*)((intptr_t)piVar8 + local_20);
                } while (local_c < local_10);
            }
            bool hit = false;
            if (local_c == local_10) {
                uint32_t* puVar1 = auStack_68 + bucket;
                *puVar1 = *puVar1 + 1;
                if (auStack_b0[bucket] < *puVar1) {
                    hit = true;
                }
            }
            if (!hit && 0x1ffu < (self[0x32] & 0xffffu) && self[0x1f] == local_8) {
                local_18 = local_18 + 1;
                if (2 < local_18) {
                    hit = true;
                }
            }
            if (hit) {
                if (param_2 != nullptr) {
                    *param_2 = local_10;
                }
                return 1;
            }
            local_10 = local_10 + 1;
            local_1c = local_1c + local_20;
        } while (local_10 < local_14);
    }
    return 0;
}

// 0x683bc9 — observed shape: destination-conflict probe. Scans the elements of
// the 0x10000000 blob at param_1's +8 list; returns 1 when an element bound to
// self+0x88 has a destination slot below param_2 whose 0xfff0 flags are set.
uint32_t FUN_683bc9(uint8_t* self, uint8_t* param_1, uint32_t param_2) {
    uint32_t local_8 = 0;
    if (*(uint32_t*)(param_1 + 4) != 0) {
        int32_t* piVar3 = *(int32_t**)(param_1 + 8);
        do {
            int32_t iVar1 = *(int32_t*)(*(int32_t*)(self + 0x14) + *piVar3 * 4);
            uint32_t uVar2;
            if (*(int32_t*)(self + 0x88) == *(int32_t*)(iVar1 + 4) &&
                (uVar2 = *(uint32_t*)(iVar1 + 0x50), uVar2 < param_2) &&
                (*(uint16_t*)(*(int32_t*)(*(int32_t*)(self + 0x18) + uVar2 * 4) + 2) &
                 0xfff0) != 0) {
                return 1;
            }
            local_8 = local_8 + 1;
            piVar3 = piVar3 + 1;
        } while (local_8 < *(uint32_t*)(param_1 + 4));
    }
    return 0;
}

// 0x683c2b — observed shape: first-slot resolver. Above revision 0x1ff, or when
// the flags at self[0x100]+2 carry no 0xfff0 bits, it is a no-op; otherwise it
// resolves the first element whose +8 slot index is not -1 through 0x682fbc
// and stops.
int32_t FUN_683c2b(uint8_t* self) {
    if (0x1ffu < (*(uint32_t*)(self + 200) & 0xffffu)) {
        return 0;
    }
    int32_t iVar3 = *(int32_t*)(self + 0x100);
    if ((*(uint16_t*)(iVar3 + 2) & 0xfff0) == 0) {
        return 0;
    }
    uint32_t uVar4 = 0;
    if (*(uint32_t*)(iVar3 + 4) != 0) {
        int32_t* piVar2 = *(int32_t**)(iVar3 + 8);
        do {
            int32_t iVar1 = *(int32_t*)(*(int32_t*)(self + 0x14) + *piVar2 * 4);
            if (*(int32_t*)(iVar1 + 8) != -1) {
                int32_t iVar3b = FUN_682fbc((uint32_t*)self, *(int32_t*)(iVar1 + 8));
                if (iVar3b < 0) {
                    return iVar3b;
                }
                return 0;
            }
            uVar4 = uVar4 + 1;
            piVar2 = piVar2 + 1;
        } while (uVar4 < *(uint32_t*)(iVar3 + 4));
    }
    return 0;
}

