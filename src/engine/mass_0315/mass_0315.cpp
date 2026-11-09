// Reconstruction batch mass_0315 — Sid Meier's Pirates! (2004), PE32 i386
// Translated from Ghidra 12.2 pseudocode in analysis/pseudocode/functions/.
#include <cstdint>
#include <cstddef>

// ---------------------------------------------------------------------------
// Referenced helpers and globals (declared extern; not defined in this batch).
// ---------------------------------------------------------------------------
extern void FUN_0065ab96(uint32_t param_1);
extern uint32_t FUN_0065aaac(uint32_t size, uint32_t align);
extern int FUN_0060d19b(uint32_t size);
extern int FUN_0065c9e5(void);
extern uint8_t PTR_FUN_006ee218[];
extern int DAT_0072be28;

// ---------------------------------------------------------------------------
// 0x65caaa region
// ---------------------------------------------------------------------------

// 0x65caaa — observed shape
void FUN_65caaa(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3,
                uint32_t param_4, uint32_t param_5)
{
    uint32_t* const p = (uint32_t*)self;

    FUN_0065ab96(0x13);
    p[4] = param_1;
    p[5] = param_2;
    p[6] = param_3;
    p[7] = param_4;
    p[10] = param_5;
    p[0] = (uint32_t)(uintptr_t)&PTR_FUN_006ee218;
    p[8] = 0xf0000;
    p[9] = 0xe40000;
}

// 0x65caf2 — observed shape
// The provider listing calls the allocation helper with 0x60 and then calls
// FUN_0065c9e5 with no argument, so the allocated block address is not visible
// in the decompiled text; the ordering and the field offsets are preserved.
int FUN_65caf2(void* self)
{
    uint8_t* const s = (uint8_t*)self;
    uint8_t* dst;
    int iVar1;
    int local_8;
    uint32_t local_c;
    uint32_t* piVar3;

    iVar1 = FUN_0060d19b(0x60);
    if (iVar1 == 0) {
        local_8 = 0;
    } else {
        local_8 = FUN_0065c9e5();
    }
    if (local_8 == 0) {
        return 0;
    }
    dst = (uint8_t*)(intptr_t)local_8;
    {
        uint32_t* puVar2 = (uint32_t*)(s + 0x10);
        uint32_t* puVar4 = (uint32_t*)(dst + 0x10);
        for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar4 = *puVar2;
            puVar2 = puVar2 + 1;
            puVar4 = puVar4 + 1;
        }
    }
    *(uint32_t*)(dst + 0x30) = *(uint32_t*)(s + 0x30);
    *(uint32_t*)(dst + 0x34) = *(uint32_t*)(s + 0x34);
    *(uint32_t*)(dst + 0x38) = *(uint32_t*)(s + 0x38);
    *(uint32_t*)(dst + 0x54) = *(uint32_t*)(s + 0x54);
    *(uint32_t*)(dst + 0x58) = *(uint32_t*)(s + 0x58);
    if (*(int*)(s + 0x3c) == 0) {
LAB_0065cb68:
        if (*(int*)(s + 0x40) != 0) {
            iVar1 = (*(int (**)(void))(**(int**)(s + 0x40) + 4))();
            *(int*)(dst + 0x40) = iVar1;
            if (iVar1 == 0) goto LAB_0065cbaf;
        }
        local_c = 0;
        piVar3 = (uint32_t*)(s + 0x44);
        do {
            if (*piVar3 != 0) {
                iVar1 = (*(int (**)(void))(*(int*)*piVar3 + 4))();
                *(int*)(dst + ((uint8_t*)piVar3 - s)) = iVar1;
                if (iVar1 == 0) goto LAB_0065cbaf;
            }
            local_c = local_c + 1;
            piVar3 = piVar3 + 1;
        } while (local_c < 4);
    } else {
        iVar1 = (*(int (**)(void))(**(int**)(s + 0x3c) + 4))();
        *(int*)(dst + 0x3c) = iVar1;
        if (iVar1 != 0) goto LAB_0065cb68;
LAB_0065cbaf:
        local_8 = 0;
    }
    return local_8;
}

// 0x65cc1a — observed shape
void FUN_65cc1a(void* self)
{
    uint32_t* const p = (uint32_t*)self;

    p[0xc] = 0xffffffff;
    p[0xd] = 0xffffffff;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[8] = 0;
    p[9] = 0;
    p[10] = 0;
    p[0xb] = 0;
    p[0xe] = 0;
    p[0xf] = 0;
}

// 0x65cc50 — observed shape
uint32_t FUN_65cc50(void* self, int param_1)
{
    if (param_1 == 0) {
        return 0x80004005;
    }
    *(uint32_t*)((uint8_t*)self + 0x3c) = *(uint32_t*)((uint8_t*)(intptr_t)param_1 + 0x3c);
    return 0;
}

// 0x65cc6f — observed shape
uint32_t FUN_65cc6f(void* self, int param_1, int* param_2)
{
    uint32_t* const p = (uint32_t*)self;
    uint32_t uVar1;

    uVar1 = *p & 0xfffff;
    if (p[1] < uVar1 * (uint32_t)param_1 + uVar1) {
        if (param_2 != nullptr) {
            *param_2 = 0;
        }
        uVar1 = 0;
    } else if (param_2 != nullptr) {
        *param_2 = (int)(p[2] + uVar1 * (uint32_t)param_1 * 4);
    }
    return uVar1;
}

// ---------------------------------------------------------------------------
// 0x65ccac region — pixel-format predicates reading the descriptor at self[0]
// ---------------------------------------------------------------------------

// 0x65ccac — observed shape
uint32_t FUN_65ccac(void* self)
{
    uint32_t uVar1;

    if ((*(uint32_t*)self & 0xf0000000) == 0x60000000) {
        return 1;
    }
    uVar1 = *(uint32_t*)self & 0xfff00000;
    if ((uVar1 == 0x50100000) || (uVar1 == 0x50200000) || (uVar1 == 0x50300000)) {
        return 1;
    }
    return 0;
}

// 0x65ccdf — observed shape
uint32_t FUN_65ccdf(void* self)
{
    uint32_t uVar1;

    uVar1 = *(uint32_t*)self & 0xfff00000;
    if ((((uVar1 == 0x10300000) || (uVar1 == 0x10500000)) || (uVar1 == 0x10600000)) ||
       (uVar1 == 0x10700000)) {
        return 1;
    }
    return 0;
}

// 0x65cd09 — observed shape
uint32_t FUN_65cd09(void* self)
{
    uint32_t uVar1;

    uVar1 = *(uint32_t*)self & 0xfff00000;
    if ((((uVar1 == 0x20000000) || (uVar1 == 0x20100000)) || (uVar1 == 0x20400000)) ||
       ((uVar1 == 0x20500000 || (uVar1 == 0x50000000)))) {
        return 1;
    }
    return 0;
}

// 0x65cd3a — observed shape
uint32_t FUN_65cd3a(void* self)
{
    uint32_t uVar1;

    uVar1 = *(uint32_t*)self & 0xfff00000;
    if ((((uVar1 == 0x10000000) || (uVar1 == 0x10100000)) || (uVar1 == 0x11200000)) ||
       (((uVar1 == 0x20700000 || (uVar1 == 0x20800000)) || (uVar1 == 0x20900000)))) {
        return 1;
    }
    return 0;
}

// 0x65cd72 — observed shape
uint32_t FUN_65cd72(void* self)
{
    uint32_t uVar1;
    bool bVar2;

    uVar1 = *(uint32_t*)self & 0xfff00000;
    if (uVar1 < 0x70700001) {
        if (uVar1 == 0x70700000) {
            return 1;
        }
        if (uVar1 == 0x50300000) {
            return 1;
        }
        if (uVar1 == 0x70100000) {
            return 1;
        }
        if (uVar1 == 0x70200000) {
            return 1;
        }
        if (uVar1 == 0x70500000) {
            return 1;
        }
        bVar2 = uVar1 == 0x70600000;
    } else {
        if (uVar1 == 0x70b00000) {
            return 1;
        }
        if (uVar1 == 0x70c00000) {
            return 1;
        }
        if (uVar1 == 0x70d00000) {
            return 1;
        }
        bVar2 = uVar1 == 0x71000000;
    }
    if (bVar2) {
        return 1;
    }
    return 0;
}

// 0x65cdca — observed shape
uint32_t FUN_65cdca(void* self)
{
    uint32_t uVar1;
    bool bVar2;

    uVar1 = *(uint32_t*)self & 0xfff00000;
    if (uVar1 < 0x74200001) {
        if (uVar1 == 0x74200000) {
            return 1;
        }
        if (uVar1 < 0x11500001) {
            if (uVar1 == 0x11500000) {
                return 1;
            }
            if (uVar1 == 0x11100000) {
                return 1;
            }
            if (uVar1 == 0x11200000) {
                return 1;
            }
            if (uVar1 == 0x11300000) {
                return 1;
            }
            bVar2 = uVar1 == 0x11400000;
        } else {
            if (uVar1 == 0x20800000) {
                return 1;
            }
            if (uVar1 == 0x20900000) {
                return 1;
            }
            bVar2 = uVar1 == 0x74100000;
        }
    } else {
        if (uVar1 == 0x74300000) {
            return 1;
        }
        if (uVar1 == 0x74400000) {
            return 1;
        }
        if (uVar1 == 0x74500000) {
            return 1;
        }
        if (uVar1 == 0x74600000) {
            return 1;
        }
        if (uVar1 == 0x74700000) {
            return 1;
        }
        if (uVar1 == 0x74a00000) {
            return 1;
        }
        bVar2 = uVar1 == 0x74b00000;
    }
    if (bVar2) {
        return 1;
    }
    return 0;
}

// 0x65ce50 — observed shape
uint32_t FUN_65ce50(void* self)
{
    uint32_t uVar1;

    uVar1 = *(uint32_t*)self & 0xfff00000;
    if ((((uVar1 == 0x73100000) || (uVar1 == 0x73300000)) || (uVar1 == 0x73d00000)) ||
       (((uVar1 == 0x73e00000 || (uVar1 == 0x73f00000)) || (uVar1 == 0x74000000)))) {
        return 1;
    }
    return 0;
}

// 0x65ce88 — observed shape
uint32_t FUN_65ce88(void* self)
{
    if (((*(uint32_t*)self & 0xfff00000) == 0x20700000) ||
       ((*(uint32_t*)self & 0xfff00000) == 0x73400000)) {
        return 1;
    }
    return 0;
}

// 0x65cea4 — observed shape
uint32_t FUN_65cea4(void* self)
{
    uint32_t uVar1;
    bool bVar2;

    uVar1 = *(uint32_t*)self & 0xfff00000;
    if (uVar1 < 0x73800001) {
        if (uVar1 == 0x73800000) {
            return 1;
        }
        if (uVar1 < 0x20900001) {
            if (uVar1 == 0x20900000) {
                return 1;
            }
            if (uVar1 < 0x11400001) {
                if (uVar1 == 0x11400000) {
                    return 1;
                }
                if (uVar1 == 0x10f00000) {
                    return 1;
                }
                if (uVar1 == 0x11100000) {
                    return 1;
                }
                if (uVar1 == 0x11200000) {
                    return 1;
                }
                bVar2 = uVar1 == 0x11300000;
            } else {
                if (uVar1 == 0x11500000) {
                    return 1;
                }
                if (uVar1 == 0x20700000) {
                    return 1;
                }
                bVar2 = uVar1 == 0x20800000;
            }
        } else if (uVar1 < 0x73400001) {
            if (uVar1 == 0x73400000) {
                return 1;
            }
            if (uVar1 == 0x73000000) {
                return 1;
            }
            if (uVar1 == 0x73100000) {
                return 1;
            }
            if (uVar1 == 0x73200000) {
                return 1;
            }
            bVar2 = uVar1 == 0x73300000;
        } else {
            if (uVar1 == 0x73500000) {
                return 1;
            }
            if (uVar1 == 0x73600000) {
                return 1;
            }
            bVar2 = uVar1 == 0x73700000;
        }
    } else if (uVar1 < 0x74100001) {
        if (uVar1 == 0x74100000) {
            return 1;
        }
        if (uVar1 < 0x73d00001) {
            if (uVar1 == 0x73d00000) {
                return 1;
            }
            if (uVar1 == 0x73900000) {
                return 1;
            }
            if (uVar1 == 0x73a00000) {
                return 1;
            }
            if (uVar1 == 0x73b00000) {
                return 1;
            }
            bVar2 = uVar1 == 0x73c00000;
        } else {
            if (uVar1 == 0x73e00000) {
                return 1;
            }
            if (uVar1 == 0x73f00000) {
                return 1;
            }
            bVar2 = uVar1 == 0x74000000;
        }
    } else if (uVar1 < 0x74600001) {
        if (uVar1 == 0x74600000) {
            return 1;
        }
        if (uVar1 == 0x74200000) {
            return 1;
        }
        if (uVar1 == 0x74300000) {
            return 1;
        }
        if (uVar1 == 0x74400000) {
            return 1;
        }
        bVar2 = uVar1 == 0x74500000;
    } else {
        if (uVar1 == 0x74700000) {
            return 1;
        }
        if (uVar1 == 0x74a00000) {
            return 1;
        }
        bVar2 = uVar1 == 0x74b00000;
    }
    if (bVar2) {
        return 1;
    }
    return 0;
}

// 0x65d00b — observed shape
uint32_t FUN_65d00b(void* self)
{
    uint32_t uVar1;
    bool bVar2;

    uVar1 = *(uint32_t*)self & 0xfff00000;
    if (uVar1 < 0x60800001) {
        if (uVar1 == 0x60800000) {
            return 1;
        }
        if (uVar1 == 0x10d00000) {
            return 1;
        }
        if (uVar1 == 0x10e00000) {
            return 1;
        }
        if (uVar1 == 0x60000000) {
            return 1;
        }
        if (uVar1 == 0x60200000) {
            return 1;
        }
        if (uVar1 == 0x60300000) {
            return 1;
        }
        if (uVar1 == 0x60500000) {
            return 1;
        }
        bVar2 = uVar1 == 0x60700000;
    } else {
        if (uVar1 == 0x60a00000) {
            return 1;
        }
        if (uVar1 == 0x60c00000) {
            return 1;
        }
        if (uVar1 == 0x60d00000) {
            return 1;
        }
        if (uVar1 == 0x60f00000) {
            return 1;
        }
        if (uVar1 == 0x61100000) {
            return 1;
        }
        bVar2 = uVar1 == 0x61200000;
    }
    if (bVar2) {
        return 1;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x65d097 region — allocation helper, free-list, descriptor init/copy
// ---------------------------------------------------------------------------

// 0x65d097 — observed shape
// The provider types this procedure void, but every caller consumes the value
// produced by FUN_0065aaac; the allocation result is forwarded so the callers
// below keep the observed data flow (element count scaled by 4, align 0x10).
uint32_t FUN_65d097(uint32_t param_1)
{
    return FUN_0065aaac(param_1 << 2, 0x10);
}

// 0x65d0b4 — observed shape
void FUN_65d0b4(uint32_t param_1)
{
    if (DAT_0072be28 == 0) {
        FUN_0065aaac(param_1, 0x10);
    } else {
        DAT_0072be28 = *(int*)(DAT_0072be28 + 0x70);
    }
}

// 0x65d0e1 — observed shape
void FUN_65d0e1(int param_1)
{
    if (param_1 != 0) {
        *(int*)((uint8_t*)(intptr_t)param_1 + 0x70) = DAT_0072be28;
        DAT_0072be28 = param_1;
    }
}

// 0x65d0ff — observed shape
uint32_t FUN_65d0ff(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3,
                    int param_4)
{
    uint32_t* const p = (uint32_t*)self;
    uint32_t uVar1;
    uint32_t uVar2;
    uint32_t iVar3;
    uint32_t uVar4;
    uint32_t* puVar5;
    bool bVar6;

    uVar1 = param_1 & 0xfffff;
    p[0] = param_1;
    p[1] = param_2;
    p[3] = param_3;
    if (param_4 == 0) {
        uVar4 = param_1 & 0xf0000000;
        if (uVar4 == 0) {
            param_2 = 0;
            param_3 = 0;
            goto LAB_0065d2a1;
        }
        if (uVar4 == 0x10000000) {
            param_2 = uVar1;
            param_3 = uVar1;
        } else if (uVar4 == 0x20000000) {
            param_2 = uVar1 * 2;
            param_3 = uVar1;
        } else if (uVar4 == 0x30000000) {
            param_2 = uVar1 * 3;
            param_3 = uVar1;
        } else if (uVar4 == 0x40000000) {
            param_2 = uVar1 << 2;
            param_3 = uVar1;
        } else if (uVar4 == 0x50000000) {
            param_1 = param_1 & 0xfff00000;
            if (param_1 == 0x50000000) {
                param_2 = uVar1 * 2;
                if (param_3 == 0xffffffff) {
                    param_3 = 1;
                }
            } else if (param_1 == 0x50100000) {
                param_2 = uVar1;
                param_3 = uVar1;
            } else if (param_1 == 0x50200000) {
                param_2 = uVar1;
                param_3 = 1;
            } else if (param_1 == 0x50300000) {
                param_2 = uVar1;
                param_3 = uVar1;
            }
        } else if (uVar4 == 0x60000000) {
            param_1 = param_1 & 0xfff00000;
            if (param_1 < 0x60a00001) {
                if (param_1 != 0x60a00000) {
                    if (param_1 < 0x60500001) {
                        if ((param_1 == 0x60500000) || (param_1 == 0x60000000)) {
                            param_2 = 4;
                            param_3 = param_2;
                            goto LAB_0065d2a1;
                        }
                        if (((param_1 != 0x60100000) && (param_1 != 0x60200000)) &&
                            (param_1 != 0x60300000)) {
                            bVar6 = param_1 == 0x60400000;
                            goto LAB_0065d1c1;
                        }
                    } else if (((param_1 != 0x60600000) && (param_1 != 0x60700000)) &&
                               (param_1 != 0x60800000)) {
                        bVar6 = param_1 == 0x60900000;
LAB_0065d1c1:
                        if (!bVar6) goto LAB_0065d2a1;
                    }
                    goto LAB_0065d1c7;
                }
LAB_0065d1f5:
                param_2 = 6;
            } else {
                if (param_1 < 0x60f00001) {
                    if (param_1 == 0x60f00000) goto LAB_0065d1f5;
                    if (param_1 == 0x60b00000) goto LAB_0065d247;
                    if ((param_1 != 0x60c00000) && (param_1 != 0x60d00000)) {
                        bVar6 = param_1 == 0x60e00000;
                        goto LAB_0065d1c1;
                    }
                } else {
                    if (param_1 == 0x61000000) {
LAB_0065d247:
                        param_2 = 0xc;
                        goto LAB_0065d249;
                    }
                    if ((param_1 != 0x61100000) && (param_1 != 0x61200000)) {
                        bVar6 = param_1 == 0x61300000;
                        goto LAB_0065d1c1;
                    }
                }
LAB_0065d1c7:
                param_2 = 8;
            }
LAB_0065d249:
            param_3 = 4;
        }
LAB_0065d2a1:
        if (p[1] == 0xffffffff) {
            p[1] = param_2;
        }
        if (p[3] == 0xffffffff) {
            p[3] = param_3;
        }
        if ((((p[1] != param_2) || (p[3] != param_3)) || (p[1] == 0xffffffff)) ||
           (p[3] == 0xffffffff)) {
            return 0x80004005;
        }
    }
    if (p[1] < 9) {
        p[2] = (uint32_t)(uintptr_t)(p + 0x10);
LAB_0065d2f0:
        if (p[3] < 5) {
            p[4] = (uint32_t)(uintptr_t)(p + 0x18);
        } else {
            uVar1 = FUN_65d097(p[3]);
            p[4] = uVar1;
            if (uVar1 == 0) goto LAB_0065d357;
        }
        puVar5 = (uint32_t*)(uintptr_t)p[2];
        for (uVar1 = p[1] & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar5 = 0xffffffff;
            puVar5 = puVar5 + 1;
        }
        for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
            *(uint8_t*)puVar5 = 0xff;
            puVar5 = (uint32_t*)((intptr_t)puVar5 + 1);
        }
        puVar5 = (uint32_t*)(uintptr_t)p[4];
        for (uVar1 = p[3] & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar5 = 0xffffffff;
            puVar5 = puVar5 + 1;
        }
        for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
            *(uint8_t*)puVar5 = 0xff;
            puVar5 = (uint32_t*)((intptr_t)puVar5 + 1);
        }
        p[9] = 0;
        p[10] = 0;
        p[0xb] = 0;
        p[0xe] = 0;
        p[0xf] = 0;
        uVar2 = 0;
    } else {
        uVar1 = FUN_65d097(p[1]);
        p[2] = uVar1;
        if (uVar1 != 0) goto LAB_0065d2f0;
LAB_0065d357:
        uVar2 = 0x8007000e;
    }
    return uVar2;
}

// 0x65d35e — observed shape
uint32_t FUN_65d35e(void* self, uint32_t* param_1)
{
    uint32_t* const p = (uint32_t*)self;
    uint32_t uVar1;
    uint32_t iVar3;
    uint32_t* puVar4;
    uint32_t* puVar5;

    if (param_1 == nullptr) {
        return 0x80004005;
    }
    p[0] = param_1[0];
    uVar1 = param_1[1];
    if (p[1] < uVar1) {
        if (uVar1 < 9) {
            p[2] = (uint32_t)(uintptr_t)(p + 0x10);
        } else {
            iVar3 = FUN_65d097(uVar1);
            p[2] = iVar3;
            if (iVar3 == 0) {
                return 0x8007000e;
            }
        }
    }
    iVar3 = param_1[1];
    p[1] = iVar3;
    puVar4 = (uint32_t*)(uintptr_t)param_1[2];
    puVar5 = (uint32_t*)(uintptr_t)p[2];
    for (; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
    }
    uVar1 = param_1[3];
    if (p[3] < uVar1) {
        if (uVar1 < 5) {
            p[4] = (uint32_t)(uintptr_t)(p + 0x18);
        } else {
            iVar3 = FUN_65d097(uVar1);
            p[4] = iVar3;
            if (iVar3 == 0) {
                return 0x8007000e;
            }
        }
    }
    iVar3 = param_1[3];
    p[3] = iVar3;
    puVar4 = (uint32_t*)(uintptr_t)param_1[4];
    puVar5 = (uint32_t*)(uintptr_t)p[4];
    for (; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
    }
    p[9] = param_1[9];
    p[10] = param_1[10];
    p[0xc] = param_1[0xc];
    p[0xf] = param_1[0xf];
    return 0;
}
