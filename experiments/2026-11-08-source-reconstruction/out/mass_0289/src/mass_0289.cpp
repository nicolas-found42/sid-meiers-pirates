// mass_0289 reconstruction — Sid Meier's Pirates! (2004) PE32 i386
// Source addresses 0x0062fa81 .. 0x006307b7 (D3DX-style texture / effect
// parameter accessors over the device's resource-object table).
#include <cstdint>
#include <cstddef>
#include <windows.h>

// Out-of-batch helpers and globals (declared; not defined here).
extern int32_t FUN_0062f194(uint32_t param_2, int32_t param_3);
extern int32_t FUN_0062d704(int32_t node, uint32_t value);
extern int32_t FUN_0062d760(int32_t node, uint32_t* cell);
extern uint32_t FUN_0062d7ba(int32_t p1, uint32_t p2, int32_t p3, uint32_t p4);
extern uint32_t FUN_0062d96b(int32_t p1, uint32_t p2, int32_t p3, uint32_t p4);
extern uint32_t FUN_0062d88b(int32_t p1, uint32_t p2, int32_t p3, uint32_t p4);
extern uint32_t FUN_0062da3c(int32_t p1, uint32_t p2, int32_t p3, uint32_t p4);
extern uint32_t FUN_0062db1c(int32_t p1, uint32_t p2, int32_t p3, uint32_t p4);
extern uint32_t FUN_0062dcfa(int32_t p1, uint32_t p2, int32_t p3, uint32_t p4);
extern uint32_t FUN_0062dc0a(int32_t p1, uint32_t p2, int32_t p3, uint32_t p4);
extern uint32_t FUN_0062dde8(int32_t p1, uint32_t p2, int32_t p3, uint32_t p4);
extern uint32_t FUN_0062deda(int32_t p1, uint32_t p2, int32_t p3, uint32_t p4);
extern uint32_t FUN_0062df4b(int32_t p1, uint32_t p2, int32_t p3, uint32_t p4);
extern void FUN_0062a46a(uint32_t param_1);
extern char* FUN_0065aaac(char* ptr, int32_t param_1);
extern void FUN_0060d2b8(void);
extern "C" long ftol();  // x87 ST0 -> long; the listing shows the implicit ST0 operand

// 0x0062fa81 — observed shape: int(base, tex, void* out); resource lookup via
// FUN_0062f194, 2D walk capped at min(4,*+0x14) x min(4,*+0x18), FUN_0062d704
// per cell; format 2 uses a 16-byte cell stride, format 3 a 4-byte one.
int32_t FUN_0062fa81(int32_t base, uint32_t param_2, uint32_t* param_3)
{
    if (param_3 == nullptr) {
        return static_cast<int32_t>(0x8876086cu);
    }
    int32_t iVar3 = FUN_0062f194(param_2, 1);
    if (iVar3 != 0) {
        int32_t iVar4 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar3 + 4) + 0x40) +
                        *reinterpret_cast<int32_t*>(base + 0x344) +
                        *reinterpret_cast<int32_t*>(iVar3 + 0x18);
        if (*reinterpret_cast<int32_t*>(iVar4 + 0x10) == 0 ||
            *reinterpret_cast<int32_t*>(iVar3 + 0x10) != -1) {
            if (*reinterpret_cast<int32_t*>(iVar4 + 4) == 2) {
                uint32_t uVar1 = *reinterpret_cast<uint32_t*>(iVar4 + 0x14);
                iVar3 = *reinterpret_cast<int32_t*>(iVar3 + 0x1c);
                uint32_t* local_c = param_3;
                uint32_t uVar2 = *reinterpret_cast<uint32_t*>(iVar4 + 0x18);
                int32_t iVar4Out = 0;
                uint32_t local_8 = 1;
                uint32_t local_10 = 4;
                if (uVar1 < 5) {
                    local_10 = uVar1;
                }
                param_2 = 4;
                if (uVar2 < 5) {
                    param_2 = uVar2;
                }
                do {
                    uint32_t local_d = 0;
                    if (local_10 != 0) {
                        uint32_t* pRow = local_c;
                        do {
                            uint32_t uVar6 = 0;
                            if (param_2 != 0) {
                                uint32_t* puVar7 = pRow;
                                do {
                                    iVar4Out = FUN_0062d704(iVar3, *puVar7);
                                    if (iVar4Out < 0) {
                                        return iVar4Out;
                                    }
                                    iVar3 = *reinterpret_cast<int32_t*>(iVar3 + 0xc);
                                    uVar6 = uVar6 + 1;
                                    puVar7 = puVar7 + 4;
                                } while (uVar6 < param_2);
                            }
                            if (uVar6 < uVar2) {
                                int32_t iVar5 = static_cast<int32_t>(uVar2 - uVar6);
                                do {
                                    iVar5 = iVar5 + -1;
                                    iVar3 = *reinterpret_cast<int32_t*>(iVar3 + 0xc);
                                } while (iVar5 != 0);
                            }
                            local_d = local_d + 1;
                            pRow = pRow + 1;
                        } while (local_d < local_10);
                    }
                    if (local_d < uVar1) {
                        int32_t iVar5 = static_cast<int32_t>(uVar1 - local_d);
                        do {
                            if (uVar2 != 0) {
                                uint32_t uVar6 = uVar2;
                                do {
                                    uVar6 = uVar6 - 1;
                                    iVar3 = *reinterpret_cast<int32_t*>(iVar3 + 0xc);
                                } while (uVar6 != 0);
                            }
                            iVar5 = iVar5 + -1;
                        } while (iVar5 != 0);
                    }
                    local_8 = local_8 - 1;
                    local_c = local_c + 0x10;
                } while (local_8 != 0);
                return iVar4Out;
            }
            if (*reinterpret_cast<int32_t*>(iVar4 + 4) == 3) {
                uint32_t uVar1 = *reinterpret_cast<uint32_t*>(iVar4 + 0x14);
                iVar3 = *reinterpret_cast<int32_t*>(iVar3 + 0x1c);
                uint32_t* local_c = param_3;
                uint32_t uVar2 = *reinterpret_cast<uint32_t*>(iVar4 + 0x18);
                int32_t iVar4Out = 0;
                uint32_t local_10 = 1;
                uint32_t local_8 = 4;
                if (uVar1 < 5) {
                    local_8 = uVar1;
                }
                param_2 = 4;
                if (uVar2 < 5) {
                    param_2 = uVar2;
                }
                do {
                    uint32_t local_d = 0;
                    if (local_8 != 0) {
                        uint32_t* pRow = local_c;
                        do {
                            uint32_t uVar6 = 0;
                            if (param_2 != 0) {
                                uint32_t* puVar7 = pRow;
                                do {
                                    iVar4Out = FUN_0062d704(iVar3, *puVar7);
                                    if (iVar4Out < 0) {
                                        return iVar4Out;
                                    }
                                    iVar3 = *reinterpret_cast<int32_t*>(iVar3 + 0xc);
                                    uVar6 = uVar6 + 1;
                                    puVar7 = puVar7 + 1;
                                } while (uVar6 < param_2);
                            }
                            if (uVar6 < uVar2) {
                                int32_t iVar5 = static_cast<int32_t>(uVar2 - uVar6);
                                do {
                                    iVar5 = iVar5 + -1;
                                    iVar3 = *reinterpret_cast<int32_t*>(iVar3 + 0xc);
                                } while (iVar5 != 0);
                            }
                            local_d = local_d + 1;
                            pRow = pRow + 4;
                        } while (local_d < local_8);
                    }
                    if (local_d < uVar1) {
                        int32_t iVar5 = static_cast<int32_t>(uVar1 - local_d);
                        do {
                            if (uVar2 != 0) {
                                uint32_t uVar6 = uVar2;
                                do {
                                    uVar6 = uVar6 - 1;
                                    iVar3 = *reinterpret_cast<int32_t*>(iVar3 + 0xc);
                                } while (uVar6 != 0);
                            }
                            iVar5 = iVar5 + -1;
                        } while (iVar5 != 0);
                    }
                    local_10 = local_10 - 1;
                    local_c = local_c + 0x10;
                } while (local_10 != 0);
                return iVar4Out;
            }
        }
    }
    return static_cast<int32_t>(0x8876086cu);
}

// 0x0062fc53 — observed shape: int(base, tex, void* out); same lookup as
// 0x62fa81 but zeroes 16 output words first and stores through FUN_0062d760.
int32_t FUN_0062fc53(int32_t base, uint32_t param_2, uint32_t* param_3)
{
    if (param_3 == nullptr) {
        return static_cast<int32_t>(0x8876086cu);
    }
    int32_t iVar3 = FUN_0062f194(param_2, 1);
    if (iVar3 != 0) {
        int32_t iVar4 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar3 + 4) + 0x40) +
                        *reinterpret_cast<int32_t*>(base + 0x344) +
                        *reinterpret_cast<int32_t*>(iVar3 + 0x18);
        if (*reinterpret_cast<int32_t*>(iVar4 + 0x10) == 0 ||
            *reinterpret_cast<int32_t*>(iVar3 + 0x10) != -1) {
            if (*reinterpret_cast<int32_t*>(iVar4 + 4) == 2) {
                iVar3 = *reinterpret_cast<int32_t*>(iVar3 + 0x1c);
                uint32_t uVar1 = *reinterpret_cast<uint32_t*>(iVar4 + 0x18);
                int32_t local_14 = 0;
                uint32_t uVar2 = *reinterpret_cast<uint32_t*>(iVar4 + 0x14);
                uint32_t local_8 = 1;
                uint32_t* local_c = param_3;
                uint32_t local_10 = 4;
                if (uVar2 < 5) {
                    local_10 = uVar2;
                }
                param_2 = 4;
                if (uVar1 < 5) {
                    param_2 = uVar1;
                }
                for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
                    *param_3 = 0;
                    param_3 = param_3 + 1;
                }
                do {
                    uint32_t local_d = 0;
                    if (local_10 != 0) {
                        uint32_t* pRow = local_c;
                        do {
                            uint32_t uVar6 = 0;
                            if (param_2 != 0) {
                                uint32_t* puVar5 = pRow;
                                do {
                                    local_14 = FUN_0062d760(iVar3, puVar5);
                                    if (local_14 < 0) {
                                        return local_14;
                                    }
                                    iVar3 = *reinterpret_cast<int32_t*>(iVar3 + 0xc);
                                    uVar6 = uVar6 + 1;
                                    puVar5 = puVar5 + 4;
                                } while (uVar6 < param_2);
                            }
                            if (uVar6 < uVar1) {
                                int32_t iVar5 = static_cast<int32_t>(uVar1 - uVar6);
                                do {
                                    iVar5 = iVar5 + -1;
                                    iVar3 = *reinterpret_cast<int32_t*>(iVar3 + 0xc);
                                } while (iVar5 != 0);
                            }
                            local_d = local_d + 1;
                            pRow = pRow + 1;
                        } while (local_d < local_10);
                    }
                    if (local_d < uVar2) {
                        int32_t iVar5 = static_cast<int32_t>(uVar2 - local_d);
                        do {
                            if (uVar1 != 0) {
                                uint32_t uVar6 = uVar1;
                                do {
                                    uVar6 = uVar6 - 1;
                                    iVar3 = *reinterpret_cast<int32_t*>(iVar3 + 0xc);
                                } while (uVar6 != 0);
                            }
                            iVar5 = iVar5 + -1;
                        } while (iVar5 != 0);
                    }
                    local_8 = local_8 - 1;
                    local_c = local_c + 0x10;
                } while (local_8 != 0);
                return local_14;
            }
            if (*reinterpret_cast<int32_t*>(iVar4 + 4) == 3) {
                iVar3 = *reinterpret_cast<int32_t*>(iVar3 + 0x1c);
                uint32_t uVar1 = *reinterpret_cast<uint32_t*>(iVar4 + 0x18);
                int32_t local_14 = 0;
                uint32_t uVar2 = *reinterpret_cast<uint32_t*>(iVar4 + 0x14);
                uint32_t local_10 = 1;
                uint32_t* local_c = param_3;
                uint32_t local_8 = 4;
                if (uVar2 < 5) {
                    local_8 = uVar2;
                }
                param_2 = 4;
                if (uVar1 < 5) {
                    param_2 = uVar1;
                }
                for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
                    *param_3 = 0;
                    param_3 = param_3 + 1;
                }
                do {
                    uint32_t local_d = 0;
                    if (local_8 != 0) {
                        uint32_t* pRow = local_c;
                        do {
                            uint32_t uVar6 = 0;
                            if (param_2 != 0) {
                                uint32_t* puVar5 = pRow;
                                do {
                                    local_14 = FUN_0062d760(iVar3, puVar5);
                                    if (local_14 < 0) {
                                        return local_14;
                                    }
                                    iVar3 = *reinterpret_cast<int32_t*>(iVar3 + 0xc);
                                    uVar6 = uVar6 + 1;
                                    puVar5 = puVar5 + 1;
                                } while (uVar6 < param_2);
                            }
                            if (uVar6 < uVar1) {
                                int32_t iVar5 = static_cast<int32_t>(uVar1 - uVar6);
                                do {
                                    iVar5 = iVar5 + -1;
                                    iVar3 = *reinterpret_cast<int32_t*>(iVar3 + 0xc);
                                } while (iVar5 != 0);
                            }
                            local_d = local_d + 1;
                            pRow = pRow + 4;
                        } while (local_d < local_8);
                    }
                    if (local_d < uVar2) {
                        int32_t iVar5 = static_cast<int32_t>(uVar2 - local_d);
                        do {
                            if (uVar1 != 0) {
                                uint32_t uVar6 = uVar1;
                                do {
                                    uVar6 = uVar6 - 1;
                                    iVar3 = *reinterpret_cast<int32_t*>(iVar3 + 0xc);
                                } while (uVar6 != 0);
                            }
                            iVar5 = iVar5 + -1;
                        } while (iVar5 != 0);
                    }
                    local_10 = local_10 - 1;
                    local_c = local_c + 0x10;
                } while (local_10 != 0);
                return local_14;
            }
        }
    }
    return static_cast<int32_t>(0x8876086cu);
}

// 0x0062fe3b — observed shape: uint(base, tex, buf, bytes); format 2 -> 0x62d7ba,
// format 3 -> 0x62d96b, size bounded by *(+0x10) and lock state -1.
uint32_t FUN_0062fe3b(int32_t base, uint32_t param_2, int32_t param_3, uint32_t param_4)
{
    if (param_4 != 0 && param_3 == 0) {
        return 0x8876086cu;
    }
    int32_t iVar1 = FUN_0062f194(param_2, 1);
    if (iVar1 != 0) {
        int32_t iVar3 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar1 + 4) + 0x40) +
                        *reinterpret_cast<int32_t*>(base + 0x344) +
                        *reinterpret_cast<int32_t*>(iVar1 + 0x18);
        if (param_4 <= *reinterpret_cast<uint32_t*>(iVar3 + 0x10) &&
            *reinterpret_cast<uint32_t*>(iVar3 + 0x10) != 0 &&
            *reinterpret_cast<int32_t*>(iVar1 + 0x10) == -1) {
            if (*reinterpret_cast<int32_t*>(iVar3 + 4) == 2) {
                return FUN_0062d7ba(iVar3, *reinterpret_cast<uint32_t*>(iVar1 + 0x1c), param_3, param_4);
            }
            if (*reinterpret_cast<int32_t*>(iVar3 + 4) == 3) {
                return FUN_0062d96b(iVar3, *reinterpret_cast<uint32_t*>(iVar1 + 0x1c), param_3, param_4);
            }
        }
    }
    return 0x8876086cu;
}

// 0x0062febc — observed shape: uint(base, tex, buf, bytes); mirror of 0x62fe3b
// with the format->helper mapping swapped (2 -> 0x62d96b, 3 -> 0x62d7ba).
uint32_t FUN_0062febc(int32_t base, uint32_t param_2, int32_t param_3, uint32_t param_4)
{
    if (param_4 != 0 && param_3 == 0) {
        return 0x8876086cu;
    }
    int32_t iVar1 = FUN_0062f194(param_2, 1);
    if (iVar1 != 0) {
        int32_t iVar3 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar1 + 4) + 0x40) +
                        *reinterpret_cast<int32_t*>(base + 0x344) +
                        *reinterpret_cast<int32_t*>(iVar1 + 0x18);
        if (param_4 <= *reinterpret_cast<uint32_t*>(iVar3 + 0x10) &&
            *reinterpret_cast<uint32_t*>(iVar3 + 0x10) != 0 &&
            *reinterpret_cast<int32_t*>(iVar1 + 0x10) == -1) {
            if (*reinterpret_cast<int32_t*>(iVar3 + 4) == 2) {
                return FUN_0062d96b(iVar3, *reinterpret_cast<uint32_t*>(iVar1 + 0x1c), param_3, param_4);
            }
            if (*reinterpret_cast<int32_t*>(iVar3 + 4) == 3) {
                return FUN_0062d7ba(iVar3, *reinterpret_cast<uint32_t*>(iVar1 + 0x1c), param_3, param_4);
            }
        }
    }
    return 0x8876086cu;
}

// 0x0062ff3d — observed shape: uint(base, tex, buf, bytes); returns 0 when
// bytes == 0; format 2 -> 0x62d88b, format 3 -> 0x62da3c.
uint32_t FUN_0062ff3d(int32_t base, uint32_t param_2, int32_t param_3, uint32_t param_4)
{
    uint32_t uVar1 = 0;
    if (param_4 != 0) {
        if (param_3 == 0) {
            uVar1 = 0x8876086cu;
        } else {
            int32_t iVar2 = FUN_0062f194(param_2, 1);
            if (iVar2 != 0) {
                int32_t iVar3 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar2 + 4) + 0x40) +
                                *reinterpret_cast<int32_t*>(base + 0x344) +
                                *reinterpret_cast<int32_t*>(iVar2 + 0x18);
                if (param_4 <= *reinterpret_cast<uint32_t*>(iVar3 + 0x10) &&
                    *reinterpret_cast<uint32_t*>(iVar3 + 0x10) != 0 &&
                    *reinterpret_cast<int32_t*>(iVar2 + 0x10) == -1) {
                    if (*reinterpret_cast<int32_t*>(iVar3 + 4) == 2) {
                        return FUN_0062d88b(iVar3, *reinterpret_cast<uint32_t*>(iVar2 + 0x1c), param_3, param_4);
                    }
                    if (*reinterpret_cast<int32_t*>(iVar3 + 4) == 3) {
                        return FUN_0062da3c(iVar3, *reinterpret_cast<uint32_t*>(iVar2 + 0x1c), param_3, param_4);
                    }
                }
            }
            uVar1 = 0x8876086cu;
        }
    }
    return uVar1;
}

// 0x0062ffbf — observed shape: uint(base, tex, buf, bytes); returns 0 when
// bytes == 0; format 2 -> 0x62da3c, format 3 -> 0x62d88b.
uint32_t FUN_0062ffbf(int32_t base, uint32_t param_2, int32_t param_3, uint32_t param_4)
{
    uint32_t uVar1 = 0;
    if (param_4 != 0) {
        if (param_3 == 0) {
            uVar1 = 0x8876086cu;
        } else {
            int32_t iVar2 = FUN_0062f194(param_2, 1);
            if (iVar2 != 0) {
                int32_t iVar3 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar2 + 4) + 0x40) +
                                *reinterpret_cast<int32_t*>(base + 0x344) +
                                *reinterpret_cast<int32_t*>(iVar2 + 0x18);
                if (param_4 <= *reinterpret_cast<uint32_t*>(iVar3 + 0x10) &&
                    *reinterpret_cast<uint32_t*>(iVar3 + 0x10) != 0 &&
                    *reinterpret_cast<int32_t*>(iVar2 + 0x10) == -1) {
                    if (*reinterpret_cast<int32_t*>(iVar3 + 4) == 2) {
                        return FUN_0062da3c(iVar3, *reinterpret_cast<uint32_t*>(iVar2 + 0x1c), param_3, param_4);
                    }
                    if (*reinterpret_cast<int32_t*>(iVar3 + 4) == 3) {
                        return FUN_0062d88b(iVar3, *reinterpret_cast<uint32_t*>(iVar2 + 0x1c), param_3, param_4);
                    }
                }
            }
            uVar1 = 0x8876086cu;
        }
    }
    return uVar1;
}

// 0x00630041 — observed shape: uint(base, tex, buf, bytes); format 2 -> 0x62db1c,
// format 3 -> 0x62dcfa.
uint32_t FUN_00630041(int32_t base, uint32_t param_2, int32_t param_3, uint32_t param_4)
{
    if (param_4 != 0 && param_3 == 0) {
        return 0x8876086cu;
    }
    int32_t iVar1 = FUN_0062f194(param_2, 1);
    if (iVar1 != 0) {
        int32_t iVar3 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar1 + 4) + 0x40) +
                        *reinterpret_cast<int32_t*>(base + 0x344) +
                        *reinterpret_cast<int32_t*>(iVar1 + 0x18);
        if (param_4 <= *reinterpret_cast<uint32_t*>(iVar3 + 0x10) &&
            *reinterpret_cast<uint32_t*>(iVar3 + 0x10) != 0 &&
            *reinterpret_cast<int32_t*>(iVar1 + 0x10) == -1) {
            if (*reinterpret_cast<int32_t*>(iVar3 + 4) == 2) {
                return FUN_0062db1c(iVar3, *reinterpret_cast<uint32_t*>(iVar1 + 0x1c), param_3, param_4);
            }
            if (*reinterpret_cast<int32_t*>(iVar3 + 4) == 3) {
                return FUN_0062dcfa(iVar3, *reinterpret_cast<uint32_t*>(iVar1 + 0x1c), param_3, param_4);
            }
        }
    }
    return 0x8876086cu;
}

// 0x006300c2 — observed shape: uint(base, tex, buf, bytes); mirror of 0x630041
// with the format->helper mapping swapped (2 -> 0x62dcfa, 3 -> 0x62db1c).
uint32_t FUN_006300c2(int32_t base, uint32_t param_2, int32_t param_3, uint32_t param_4)
{
    if (param_4 != 0 && param_3 == 0) {
        return 0x8876086cu;
    }
    int32_t iVar1 = FUN_0062f194(param_2, 1);
    if (iVar1 != 0) {
        int32_t iVar3 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar1 + 4) + 0x40) +
                        *reinterpret_cast<int32_t*>(base + 0x344) +
                        *reinterpret_cast<int32_t*>(iVar1 + 0x18);
        if (param_4 <= *reinterpret_cast<uint32_t*>(iVar3 + 0x10) &&
            *reinterpret_cast<uint32_t*>(iVar3 + 0x10) != 0 &&
            *reinterpret_cast<int32_t*>(iVar1 + 0x10) == -1) {
            if (*reinterpret_cast<int32_t*>(iVar3 + 4) == 2) {
                return FUN_0062dcfa(iVar3, *reinterpret_cast<uint32_t*>(iVar1 + 0x1c), param_3, param_4);
            }
            if (*reinterpret_cast<int32_t*>(iVar3 + 4) == 3) {
                return FUN_0062db1c(iVar3, *reinterpret_cast<uint32_t*>(iVar1 + 0x1c), param_3, param_4);
            }
        }
    }
    return 0x8876086cu;
}

// 0x00630143 — observed shape: uint(base, tex, buf, bytes); returns 0 when
// bytes == 0; format 2 -> 0x62dc0a, format 3 -> 0x62dde8.
uint32_t FUN_00630143(int32_t base, uint32_t param_2, int32_t param_3, uint32_t param_4)
{
    uint32_t uVar1 = 0;
    if (param_4 != 0) {
        if (param_3 == 0) {
            uVar1 = 0x8876086cu;
        } else {
            int32_t iVar2 = FUN_0062f194(param_2, 1);
            if (iVar2 != 0) {
                int32_t iVar3 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar2 + 4) + 0x40) +
                                *reinterpret_cast<int32_t*>(base + 0x344) +
                                *reinterpret_cast<int32_t*>(iVar2 + 0x18);
                if (param_4 <= *reinterpret_cast<uint32_t*>(iVar3 + 0x10) &&
                    *reinterpret_cast<uint32_t*>(iVar3 + 0x10) != 0 &&
                    *reinterpret_cast<int32_t*>(iVar2 + 0x10) == -1) {
                    if (*reinterpret_cast<int32_t*>(iVar3 + 4) == 2) {
                        return FUN_0062dc0a(iVar3, *reinterpret_cast<uint32_t*>(iVar2 + 0x1c), param_3, param_4);
                    }
                    if (*reinterpret_cast<int32_t*>(iVar3 + 4) == 3) {
                        return FUN_0062dde8(iVar3, *reinterpret_cast<uint32_t*>(iVar2 + 0x1c), param_3, param_4);
                    }
                }
            }
            uVar1 = 0x8876086cu;
        }
    }
    return uVar1;
}

// 0x006301c5 — observed shape: uint(base, tex, buf, bytes); mirror of 0x630143
// with the format->helper mapping swapped (2 -> 0x62dde8, 3 -> 0x62dc0a).
uint32_t FUN_006301c5(int32_t base, uint32_t param_2, int32_t param_3, uint32_t param_4)
{
    uint32_t uVar1 = 0;
    if (param_4 != 0) {
        if (param_3 == 0) {
            uVar1 = 0x8876086cu;
        } else {
            int32_t iVar2 = FUN_0062f194(param_2, 1);
            if (iVar2 != 0) {
                int32_t iVar3 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar2 + 4) + 0x40) +
                                *reinterpret_cast<int32_t*>(base + 0x344) +
                                *reinterpret_cast<int32_t*>(iVar2 + 0x18);
                if (param_4 <= *reinterpret_cast<uint32_t*>(iVar3 + 0x10) &&
                    *reinterpret_cast<uint32_t*>(iVar3 + 0x10) != 0 &&
                    *reinterpret_cast<int32_t*>(iVar2 + 0x10) == -1) {
                    if (*reinterpret_cast<int32_t*>(iVar3 + 4) == 2) {
                        return FUN_0062dde8(iVar3, *reinterpret_cast<uint32_t*>(iVar2 + 0x1c), param_3, param_4);
                    }
                    if (*reinterpret_cast<int32_t*>(iVar3 + 4) == 3) {
                        return FUN_0062dc0a(iVar3, *reinterpret_cast<uint32_t*>(iVar2 + 0x1c), param_3, param_4);
                    }
                }
            }
            uVar1 = 0x8876086cu;
        }
    }
    return uVar1;
}

// 0x00630247 — observed shape: uint(base, tex, buf, bytes); format must be 1;
// dispatches to FUN_0062deda.
uint32_t FUN_00630247(int32_t base, uint32_t param_2, int32_t param_3, uint32_t param_4)
{
    if ((param_4 == 0 || param_3 != 0)) {
        int32_t iVar1 = FUN_0062f194(param_2, 1);
        if (iVar1 != 0) {
            int32_t iVar3 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar1 + 4) + 0x40) +
                            *reinterpret_cast<int32_t*>(base + 0x344) +
                            *reinterpret_cast<int32_t*>(iVar1 + 0x18);
            if (param_4 <= *reinterpret_cast<uint32_t*>(iVar3 + 0x10) &&
                *reinterpret_cast<uint32_t*>(iVar3 + 0x10) != 0 &&
                *reinterpret_cast<int32_t*>(iVar1 + 0x10) == -1 &&
                *reinterpret_cast<int32_t*>(iVar3 + 4) == 1) {
                return FUN_0062deda(iVar3, *reinterpret_cast<uint32_t*>(iVar1 + 0x1c), param_3, param_4);
            }
        }
    }
    return 0x8876086cu;
}

// 0x006302b5 — observed shape: uint(base, tex, buf, bytes); returns 0 when
// bytes == 0; format must be 1; dispatches to FUN_0062df4b.
uint32_t FUN_006302b5(int32_t base, uint32_t param_2, int32_t param_3, uint32_t param_4)
{
    uint32_t uVar1 = 0;
    if (param_4 != 0) {
        if (param_3 == 0) {
            uVar1 = 0x8876086cu;
        } else {
            int32_t iVar2 = FUN_0062f194(param_2, 1);
            if (iVar2 != 0) {
                int32_t iVar3 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar2 + 4) + 0x40) +
                                *reinterpret_cast<int32_t*>(base + 0x344) +
                                *reinterpret_cast<int32_t*>(iVar2 + 0x18);
                if (param_4 <= *reinterpret_cast<uint32_t*>(iVar3 + 0x10) &&
                    *reinterpret_cast<uint32_t*>(iVar3 + 0x10) != 0 &&
                    *reinterpret_cast<int32_t*>(iVar2 + 0x10) == -1 &&
                    *reinterpret_cast<int32_t*>(iVar3 + 4) == 1) {
                    return FUN_0062df4b(iVar3, *reinterpret_cast<uint32_t*>(iVar2 + 0x1c), param_3, param_4);
                }
            }
            uVar1 = 0x8876086cu;
        }
    }
    return uVar1;
}

// 0x00630323 — observed shape: int(base, tex, void* src); single-row copy of at
// most four dwords through FUN_0062d704; format must be 1.
int32_t FUN_00630323(int32_t base, uint32_t param_2, uint32_t param_3)
{
    if (param_3 == 0) {
        return static_cast<int32_t>(0x8876086cu);
    }
    int32_t iVar2 = FUN_0062f194(param_2, 1);
    if (iVar2 == 0) {
        return static_cast<int32_t>(0x8876086cu);
    }
    int32_t iVar3 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar2 + 4) + 0x40) +
                    *reinterpret_cast<int32_t*>(base + 0x344) +
                    *reinterpret_cast<int32_t*>(iVar2 + 0x18);
    if ((*reinterpret_cast<int32_t*>(iVar3 + 0x10) != 0 &&
         *reinterpret_cast<int32_t*>(iVar2 + 0x10) == -1) ||
        *reinterpret_cast<int32_t*>(iVar3 + 4) != 1) {
        return static_cast<int32_t>(0x8876086cu);
    }
    int32_t iVar5 = *reinterpret_cast<int32_t*>(iVar2 + 0x1c);
    uint32_t src = param_3;
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(iVar3 + 0x14);
    int32_t iVar2Out = 0;
    int32_t rows = 1;
    uint32_t count = 4;
    if (uVar1 < 5) {
        count = uVar1;
    }
    do {
        uint32_t uVar4 = 0;
        if (count != 0) {
            do {
                iVar2Out = FUN_0062d704(iVar5, *reinterpret_cast<uint32_t*>(src + uVar4 * 4));
                if (iVar2Out < 0) {
                    return iVar2Out;
                }
                iVar5 = *reinterpret_cast<int32_t*>(iVar5 + 0xc);
                uVar4 = uVar4 + 1;
            } while (uVar4 < count);
        }
        if (uVar4 < uVar1) {
            int32_t iVar3b = static_cast<int32_t>(uVar1 - uVar4);
            do {
                iVar3b = iVar3b + -1;
                iVar5 = *reinterpret_cast<int32_t*>(iVar5 + 0xc);
            } while (iVar3b != 0);
        }
        rows = rows + -1;
        src = src + 0x10;
    } while (rows != 0);
    return iVar2Out;
}

// 0x006303d9 — observed shape: int(base, tex, void* out16); zeroes four dwords,
// then a single row of at most four FUN_0062d760 stores; format must be 1.
int32_t FUN_006303d9(int32_t base, uint32_t param_2, uint32_t* param_3)
{
    if (param_3 == nullptr) {
        return static_cast<int32_t>(0x8876086cu);
    }
    int32_t iVar3 = FUN_0062f194(param_2, 1);
    int32_t iVar2 = 0;
    if (iVar3 == 0) {
        return static_cast<int32_t>(0x8876086cu);
    }
    int32_t iVar4 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar3 + 4) + 0x40) +
                    *reinterpret_cast<int32_t*>(base + 0x344) +
                    *reinterpret_cast<int32_t*>(iVar3 + 0x18);
    if ((*reinterpret_cast<int32_t*>(iVar4 + 0x10) != 0 &&
         *reinterpret_cast<int32_t*>(iVar3 + 0x10) == -1) ||
        *reinterpret_cast<int32_t*>(iVar4 + 4) != 1) {
        return static_cast<int32_t>(0x8876086cu);
    }
    iVar3 = *reinterpret_cast<int32_t*>(iVar3 + 0x1c);
    int32_t local_8 = 1;
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(iVar4 + 0x14);
    uint32_t* pRow = param_3;
    uint32_t count = 4;
    if (uVar1 < 5) {
        count = uVar1;
    }
    param_3[0] = 0;
    param_3[1] = 0;
    param_3[2] = 0;
    param_3[3] = 0;
    do {
        uint32_t uVar5 = 0;
        if (count != 0) {
            uint32_t* pCell = pRow;
            do {
                iVar2 = FUN_0062d760(iVar3, pCell);
                if (iVar2 < 0) {
                    return iVar2;
                }
                pCell = pCell + 1;
                iVar3 = *reinterpret_cast<int32_t*>(iVar3 + 0xc);
                uVar5 = uVar5 + 1;
            } while (uVar5 < count);
        }
        if (uVar5 < uVar1) {
            int32_t iVar4b = static_cast<int32_t>(uVar1 - uVar5);
            do {
                iVar4b = iVar4b + -1;
                iVar3 = *reinterpret_cast<int32_t*>(iVar3 + 0xc);
            } while (iVar4b != 0);
        }
        local_8 = local_8 + -1;
        pRow = pRow + 4;
    } while (local_8 != 0);
    return iVar2;
}

// 0x0063049c — observed shape: uint(base, tex, const char* name); copies the
// string into a fresh allocation (FUN_0065aaac) and stores its length/pointer
// in the resource node at +0x18/+0x1c.
uint32_t FUN_0063049c(int32_t base, uint32_t param_2, char* param_3)
{
    char* pcVar6 = nullptr;
    uint32_t local_8 = 0;
    int32_t iVar2 = FUN_0062f194(param_2, 1);
    int32_t* piVar3 = nullptr;
    if (iVar2 != 0) {
        piVar3 = reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar2 + 4) + 0x40) +
                                            *reinterpret_cast<int32_t*>(base + 0x344) +
                                            *reinterpret_cast<int32_t*>(iVar2 + 0x18));
    }
    if (iVar2 == 0 ||
        ((piVar3[4] != 0 && *reinterpret_cast<int32_t*>(iVar2 + 0x10) == -1) || piVar3[1] != 4) ||
        *piVar3 != 4) {
        local_8 = 0x8876086cu;
    } else {
        iVar2 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar2 + 0x1c) + 8);
        char* pcVar4 = nullptr;
        if (param_3 != nullptr) {
            FUN_0062a46a(static_cast<uint32_t>(base + 0x10));
            pcVar6 = param_3;
            char cVar1;
            do {
                cVar1 = *pcVar6;
                pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            pcVar6 = pcVar6 + (1 - static_cast<intptr_t>(param_3 + 1));
            pcVar4 = FUN_0065aaac(pcVar6, 1);
            if (pcVar4 == nullptr) {
                FUN_0060d2b8();
                return 0x8007000eu;
            }
            char* pcVar7 = pcVar4;
            for (uint32_t uVar5 = static_cast<uint32_t>(reinterpret_cast<intptr_t>(pcVar6)) >> 2; uVar5 != 0;
                 uVar5 = uVar5 - 1) {
                *reinterpret_cast<uint32_t*>(pcVar7) = *reinterpret_cast<uint32_t*>(param_3);
                param_3 = param_3 + 4;
                pcVar7 = pcVar7 + 4;
            }
            for (uint32_t uVar5 = static_cast<uint32_t>(reinterpret_cast<intptr_t>(pcVar6)) & 3; uVar5 != 0;
                 uVar5 = uVar5 - 1) {
                *pcVar7 = *param_3;
                param_3 = param_3 + 1;
                pcVar7 = pcVar7 + 1;
            }
            FUN_0060d2b8();
        }
        *reinterpret_cast<char**>(iVar2 + 0x18) = pcVar4;
        *reinterpret_cast<char**>(iVar2 + 0x1c) = pcVar6;
    }
    return local_8;
}

// 0x0063057f — observed shape: uint(base, tex, void* out); yields the node's
// stored length/pointer field *(+0x18) when the object is a 4/4 resource.
uint32_t FUN_0063057f(int32_t base, uint32_t param_2, uint32_t* param_3)
{
    uint32_t uVar3 = 0;
    if (param_3 == nullptr) {
        uVar3 = 0x8876086cu;
    } else {
        int32_t iVar1 = FUN_0062f194(param_2, 1);
        int32_t* piVar2 = nullptr;
        if (iVar1 != 0) {
            piVar2 = reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar1 + 4) + 0x40) +
                                                *reinterpret_cast<int32_t*>(base + 0x344) +
                                                *reinterpret_cast<int32_t*>(iVar1 + 0x18));
        }
        if (iVar1 == 0 ||
            ((piVar2[4] != 0 && *reinterpret_cast<int32_t*>(iVar1 + 0x10) == -1) || piVar2[1] != 4) ||
            *piVar2 != 4) {
            uVar3 = 0x8876086cu;
        } else {
            *param_3 = *reinterpret_cast<uint32_t*>(
                *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar1 + 0x1c) + 8) + 0x18);
        }
    }
    return uVar3;
}

// 0x006305eb — observed shape: uint(base, tex, int value); writes a BOOL (or
// f64 when the parameter type is 3) into the node's 0x18 slot.
uint32_t FUN_006305eb(int32_t base, uint32_t param_2, int32_t param_3)
{
    int32_t iVar1 = FUN_0062f194(param_2, 1);
    if (iVar1 != 0) {
        int32_t iVar2 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar1 + 4) + 0x40) +
                        *reinterpret_cast<int32_t*>(base + 0x344) +
                        *reinterpret_cast<int32_t*>(iVar1 + 0x18);
        if (*reinterpret_cast<int32_t*>(iVar2 + 0x10) == 0 ||
            *reinterpret_cast<int32_t*>(iVar1 + 0x10) != -1) {
            if (-1 < *reinterpret_cast<int32_t*>(iVar2 + 4) &&
                *reinterpret_cast<int32_t*>(iVar2 + 4) < 4 &&
                *reinterpret_cast<int32_t*>(iVar2 + 0x14) == 1 &&
                *reinterpret_cast<int32_t*>(iVar2 + 0x18) == 1) {
                iVar1 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar1 + 0x1c) + 8);
                iVar2 = *reinterpret_cast<int32_t*>(iVar1 + 0x10);
                if (iVar2 == 0 || iVar2 == 1 || iVar2 == 2) {
                    *reinterpret_cast<uint32_t*>(iVar1 + 0x18) = static_cast<uint32_t>(param_3 != 0);
                    return 0;
                }
                if (iVar2 == 3) {
                    *reinterpret_cast<double*>(iVar1 + 0x18) = static_cast<double>(param_3 != 0);
                    return 0;
                }
            }
        }
    }
    return 0x8876086cu;
}

// 0x00630676 — observed shape: uint(base, tex, uint* out); reads back the BOOL
// stored at +0x18 (or f64 -> BOOL when the parameter type is 3).
uint32_t FUN_00630676(int32_t base, uint32_t param_2, uint32_t* param_3)
{
    if (param_3 == nullptr) {
        return 0x8876086cu;
    }
    int32_t iVar1 = FUN_0062f194(param_2, 1);
    if (iVar1 != 0) {
        int32_t iVar2 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar1 + 4) + 0x40) +
                        *reinterpret_cast<int32_t*>(base + 0x344) +
                        *reinterpret_cast<int32_t*>(iVar1 + 0x18);
        if ((*reinterpret_cast<int32_t*>(iVar2 + 0x10) == 0 ||
             *reinterpret_cast<int32_t*>(iVar1 + 0x10) != -1) &&
            -1 < *reinterpret_cast<int32_t*>(iVar2 + 4) &&
            *reinterpret_cast<int32_t*>(iVar2 + 4) < 4 &&
            *reinterpret_cast<int32_t*>(iVar2 + 0x14) == 1 &&
            *reinterpret_cast<int32_t*>(iVar2 + 0x18) == 1) {
            iVar1 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar1 + 0x1c) + 8);
            iVar2 = *reinterpret_cast<int32_t*>(iVar1 + 0x10);
            if (iVar2 == 0 || iVar2 == 1 || iVar2 == 2) {
                *param_3 = static_cast<uint32_t>(*reinterpret_cast<int32_t*>(iVar1 + 0x18) != 0);
                return 0;
            }
            if (iVar2 == 3) {
                *param_3 = static_cast<uint32_t>(*reinterpret_cast<double*>(iVar1 + 0x18) != 0.0);
                return 0;
            }
        }
    }
    return 0x8876086cu;
}

// 0x0063072c — observed shape: uint(base, tex, uint value); type 0 stores a BOOL,
// types 1/2 store raw, type 3 stores as f64; other types fail.
uint32_t FUN_0063072c(int32_t base, uint32_t param_2, uint32_t param_3)
{
    uint32_t uVar3 = 0;
    int32_t iVar1 = FUN_0062f194(param_2, 1);
    if (iVar1 == 0) {
        uVar3 = 0x8876086cu;
    } else {
        int32_t iVar2 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar1 + 4) + 0x40) +
                        *reinterpret_cast<int32_t*>(base + 0x344) +
                        *reinterpret_cast<int32_t*>(iVar1 + 0x18);
        if ((*reinterpret_cast<int32_t*>(iVar2 + 0x10) != 0 &&
             *reinterpret_cast<int32_t*>(iVar1 + 0x10) == -1) ||
            *reinterpret_cast<int32_t*>(iVar2 + 4) < 0 ||
            3 < *reinterpret_cast<int32_t*>(iVar2 + 4) ||
            *reinterpret_cast<int32_t*>(iVar2 + 0x14) != 1 ||
            *reinterpret_cast<int32_t*>(iVar2 + 0x18) != 1) {
            uVar3 = 0x8876086cu;
        } else {
            iVar1 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar1 + 0x1c) + 8);
            iVar2 = *reinterpret_cast<int32_t*>(iVar1 + 0x10);
            if (iVar2 == 0) {
                *reinterpret_cast<uint32_t*>(iVar1 + 0x18) = static_cast<uint32_t>(param_3 != 0);
            } else if (iVar2 == 1 || iVar2 == 2) {
                *reinterpret_cast<uint32_t*>(iVar1 + 0x18) = param_3;
            } else if (iVar2 == 3) {
                *reinterpret_cast<double*>(iVar1 + 0x18) = static_cast<double>(static_cast<int32_t>(param_3));
                return 0;
            } else {
                uVar3 = 0x8876086cu;
            }
        }
    }
    return uVar3;
}

// 0x006307b7 — observed shape: uint(base, tex, uint* out); type 0 -> BOOL,
// types 1/2 -> raw dword, type 3 -> x87 ftol of the stored f64.
uint32_t FUN_006307b7(int32_t base, uint32_t param_2, uint32_t* param_3)
{
    uint32_t local_8 = 0;
    if (param_3 == nullptr) {
        return 0x8876086cu;
    }
    int32_t iVar1 = FUN_0062f194(param_2, 1);
    if (iVar1 == 0) {
        local_8 = 0x8876086cu;
    } else {
        int32_t iVar3 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar1 + 4) + 0x40) +
                        *reinterpret_cast<int32_t*>(base + 0x344) +
                        *reinterpret_cast<int32_t*>(iVar1 + 0x18);
        if ((*reinterpret_cast<int32_t*>(iVar3 + 0x10) != 0 &&
             *reinterpret_cast<int32_t*>(iVar1 + 0x10) == -1) ||
            *reinterpret_cast<int32_t*>(iVar3 + 4) < 0 ||
            3 < *reinterpret_cast<int32_t*>(iVar3 + 4) ||
            *reinterpret_cast<int32_t*>(iVar3 + 0x14) != 1 ||
            *reinterpret_cast<int32_t*>(iVar3 + 0x18) != 1) {
            local_8 = 0x8876086cu;
        } else {
            iVar1 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar1 + 0x1c) + 8);
            iVar3 = *reinterpret_cast<int32_t*>(iVar1 + 0x10);
            if (iVar3 == 0) {
                *param_3 = static_cast<uint32_t>(*reinterpret_cast<int32_t*>(iVar1 + 0x18) != 0);
                return 0;
            }
            if (iVar3 == 1 || iVar3 == 2) {
                *param_3 = *reinterpret_cast<uint32_t*>(iVar1 + 0x18);
            } else if (iVar3 == 3) {
                *param_3 = static_cast<uint32_t>(ftol());
            } else {
                local_8 = 0x8876086cu;
            }
        }
    }
    return local_8;
}
