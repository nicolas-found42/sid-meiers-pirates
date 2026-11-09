#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void operator_delete(void* ptr);
extern void FUN_0062a581(void* self);
extern void FUN_0062a5eb(void* self);
extern void* FUN_0062a5d2();
extern void* FUN_00533c78(uint32_t size);
extern void FUN_0062a62d(void* self, uint8_t param_1);

// 0x62a581 — observed shape
void FUN_0062a581(void* self) {
    int32_t iVar1;
    void* pvVar2;
    uint8_t* base = static_cast<uint8_t*>(self);
    iVar1 = *reinterpret_cast<int32_t*>(base + 0x18);
    while (iVar1 != 0) {
        pvVar2 = *reinterpret_cast<void**>(base + 0x18);
        *reinterpret_cast<uint32_t*>(base + 0x18) = *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(pvVar2) + 0x18);
        *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(pvVar2) + 0x18) = 0;
        FUN_0062a581(pvVar2);
        operator_delete(pvVar2);
        iVar1 = *reinterpret_cast<int32_t*>(base + 0x18);
    }
    return;
}

// 0x62a5b1 — observed shape
void FUN_0062a5b1(void* self, uint8_t param_1) {
    FUN_0062a581(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x62a5eb — observed shape
void FUN_0062a5eb(void* self) {
    int32_t iVar1;
    void* pvVar2;
    uint8_t* base = static_cast<uint8_t*>(self);
    if (*reinterpret_cast<void**>(base + 4) != nullptr) {
        operator_delete(*reinterpret_cast<void**>(base + 4));
        *reinterpret_cast<uint32_t*>(base + 4) = 0;
    }
    iVar1 = *reinterpret_cast<int32_t*>(base + 8);
    while (iVar1 != 0) {
        pvVar2 = *reinterpret_cast<void**>(base + 8);
        *reinterpret_cast<uint32_t*>(base + 8) = *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(pvVar2) + 8);
        *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(pvVar2) + 8) = 0;
        FUN_0062a5eb(pvVar2);
        operator_delete(pvVar2);
        iVar1 = *reinterpret_cast<int32_t*>(base + 8);
    }
    return;
}

// 0x62a62d — observed shape
void FUN_0062a62d(void* self, uint8_t param_1) {
    FUN_0062a5eb(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x62a64e — observed shape
uint32_t FUN_0062a64e(void* self, uint32_t* param_1, uint32_t param_2, uint32_t* param_3) {
    int32_t iVar1;
    int32_t* piVar2;
    uint32_t* puVar3;
    uint32_t uVar4;
    uint32_t local_8;
    uint8_t* base = static_cast<uint8_t*>(self);

    local_8 = 0;
    iVar1 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_00533c78(0x1c)));
    if (iVar1 == 0) {
        piVar2 = nullptr;
    }
    else {
        piVar2 = static_cast<int32_t*>(FUN_0062a5d2());
    }
    if (piVar2 == nullptr) {
        return 0x8007000e;
    }
    if (param_2 != 0) {
        iVar1 = static_cast<int32_t>(((param_2 & 3) != 0) + (param_2 >> 2));
        *piVar2 = iVar1;
        puVar3 = static_cast<uint32_t*>(FUN_00533c78(static_cast<uint32_t>(iVar1) * 4));
        piVar2[1] = static_cast<int32_t>(reinterpret_cast<intptr_t>(puVar3));
        if (puVar3 == nullptr) {
            local_8 = 0x8007000e;
            goto LAB_0062a6ee;
        }
        for (uVar4 = param_2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar3 = *param_1;
            param_1 = param_1 + 1;
            puVar3 = puVar3 + 1;
        }
        for (param_2 = param_2 & 3; param_2 != 0; param_2 = param_2 - 1) {
            *reinterpret_cast<uint8_t*>(puVar3) = *reinterpret_cast<uint8_t*>(param_1);
            param_1 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(param_1) + 1);
            puVar3 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar3) + 1);
        }
    }
    piVar2[3] = *reinterpret_cast<int32_t*>(base + 0x10);
    *reinterpret_cast<int32_t**>(*reinterpret_cast<int32_t**>(base + 0x10) + 8) = piVar2;
    *reinterpret_cast<int32_t**>(base + 0x10) = piVar2;
    if (param_3 != nullptr) {
        *param_3 = static_cast<uint32_t>(reinterpret_cast<intptr_t>(piVar2));
    }
    piVar2 = nullptr;
LAB_0062a6ee:
    if (piVar2 != nullptr) {
        FUN_0062a62d(piVar2, 1);
    }
    return local_8;
}

extern void FUN_0060fcd3(void* p1, uint32_t p2, uint32_t p3, const char* msg, ...);
extern int32_t FUN_0062a866(void* self, int32_t param_1, uint32_t* param_2, int32_t* param_3, int32_t* param_4, int32_t* param_5, int32_t* param_6, int32_t* param_7);

// 0x62a705 — observed shape
void FUN_0062a705(void* self, char* param_1, uint32_t param_2) {
    char cVar1;
    int32_t iVar2;
    char* local_8;
    local_8 = nullptr;
    if (param_1 != nullptr) {
        local_8 = param_1;
        do {
            cVar1 = *local_8;
            local_8 = local_8 + 1;
        } while (cVar1 != '\0');
        local_8 = local_8 + (1 - static_cast<int32_t>(reinterpret_cast<intptr_t>(param_1 + 1)));
    }
    iVar2 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(&local_8), 4, reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(param_2))));
    if ((-1 < iVar2) && (param_1 != nullptr)) {
        FUN_0062a64e(self, reinterpret_cast<uint32_t*>(param_1), static_cast<uint32_t>(reinterpret_cast<intptr_t>(local_8)), nullptr);
    }
    return;
}

// 0x62a757 — observed shape
uint32_t FUN_0062a757(void* self, uint32_t param_1, uint32_t* param_2) {
    int32_t iVar1;
    uint32_t* puVar2;
    uint32_t* puVar3;
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t local_8;
    local_8 = 0;
    iVar1 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_00533c78(0x1c)));
    if (iVar1 == 0) {
        puVar2 = nullptr;
    }
    else {
        puVar2 = static_cast<uint32_t*>(FUN_0062a5d2());
    }
    if (puVar2 == nullptr) {
        local_8 = 0x8007000e;
    }
    else {
        *puVar2 = 1;
        puVar3 = static_cast<uint32_t*>(FUN_00533c78(4));
        puVar2[1] = static_cast<uint32_t>(reinterpret_cast<intptr_t>(puVar3));
        if (puVar3 == nullptr) {
            local_8 = 0x8007000e;
        }
        else {
            *puVar3 = 0xffffffff;
            puVar2[5] = param_1;
            puVar2[3] = *reinterpret_cast<uint32_t*>(base + 0x10);
            *reinterpret_cast<uint32_t**>(*reinterpret_cast<uint32_t**>(base + 0x10) + 8) = puVar2;
            *reinterpret_cast<uint32_t**>(base + 0x10) = puVar2;
            if (param_2 != nullptr) {
                *param_2 = static_cast<uint32_t>(reinterpret_cast<intptr_t>(puVar2));
            }
            puVar2 = nullptr;
        }
        if (puVar2 != nullptr) {
            FUN_0062a62d(puVar2, 1);
        }
    }
    return local_8;
}

// 0x62a7e2 — observed shape
uint32_t FUN_0062a7e2(void* self, int32_t param_1) {
    uint8_t* base = static_cast<uint8_t*>(self);
    uint8_t* node = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1));
    *reinterpret_cast<uint32_t*>(node + 0xc) = *reinterpret_cast<uint32_t*>(base + 0x10);
    *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(base + 0x10) + 8) = param_1;
    *reinterpret_cast<uint32_t*>(base + 0x10) = *reinterpret_cast<uint32_t*>(node + 0x10);
    return 0;
}

// 0x62a802 — observed shape
uint32_t FUN_0062a802(void* self, int32_t param_1, uint32_t* param_2) {
    uint32_t* node = static_cast<uint32_t*>(self);
    uint32_t uVar1;
    int32_t iVar2;
    uint32_t* puVar3;
    uint32_t* puVar4;
    for (; node != nullptr; node = reinterpret_cast<uint32_t*>(node[2])) {
        if (param_2 != nullptr) {
            node[6] = *param_2;
            *param_2 = *param_2 + *node * 4;
        }
        if (param_1 != 0) {
            if (node[5] == 0) {
                puVar3 = reinterpret_cast<uint32_t*>(node[1]);
            }
            else {
                puVar3 = reinterpret_cast<uint32_t*>(node[5] + 0x18);
            }
            puVar4 = reinterpret_cast<uint32_t*>(node[6] + param_1);
            for (uVar1 = *node & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
                *puVar4 = *puVar3;
                puVar3 = puVar3 + 1;
                puVar4 = puVar4 + 1;
            }
            for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
                *reinterpret_cast<uint8_t*>(puVar4) = *reinterpret_cast<uint8_t*>(puVar3);
                puVar3 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar3) + 1);
                puVar4 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar4) + 1);
            }
        }
    }
    return 0;
}

// 0x62a866 — observed shape
int32_t FUN_0062a866(void* self, int32_t param_1, uint32_t* param_2, int32_t* param_3, int32_t* param_4, int32_t* param_5, int32_t* param_6, int32_t* param_7) {
    int32_t* piVar1;
    int32_t* piVar2;
    int32_t iVar3;
    const char* pcVar4;
    uint8_t local_20[4];
    uint8_t local_1c[4];
    uint8_t local_18[4];
    uint8_t local_14[4];
    uint8_t local_10[8];
    int32_t local_8;
    uint8_t* self_base = static_cast<uint8_t*>(self);
    piVar2 = param_7;
    piVar1 = param_6;
    local_8 = 0;
    if (param_1 == 0) {
        return -0x7fffbffb;
    }
    iVar3 = *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 4);
    if (iVar3 == 1) {
        *param_6 = 0;
        *param_7 = 0;
        while (true) {
            if (*reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 4) != 1) {
                return -0x7fffbffb;
            }
            iVar3 = *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 8);
            if (iVar3 == 0) {
                return -0x7fffbffb;
            }
            if (*reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar3)) + 4) != 6) {
                return -0x7fffbffb;
            }
            if (*reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar3)) + 0x10) != 1) {
                return -0x7fffbffb;
            }
            iVar3 = *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar3)) + 0x18);
            if (iVar3 == 0) {
                return -0x7fffbffb;
            }
            if (*reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar3)) + 4) != 0xb) {
                return -0x7fffbffb;
            }
            if (*reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar3)) + 0x20) == 0) {
                return -0x7fffbffb;
            }
            local_8 = FUN_0062a866(self, *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar3)) + 0x20), reinterpret_cast<uint32_t*>(local_20), reinterpret_cast<int32_t*>(local_1c), reinterpret_cast<int32_t*>(local_18), reinterpret_cast<int32_t*>(local_14), reinterpret_cast<int32_t*>(local_10), &param_6);
            if (local_8 < 0) break;
            *param_7 = *param_7 + static_cast<int32_t>(reinterpret_cast<intptr_t>(param_6));
            param_1 = *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0xc);
            *piVar1 = *piVar1 + 1;
            if (param_1 == 0) {
                *param_2 = 0;
                *param_3 = 0;
                *param_4 = 0;
                *param_5 = 0;
                return local_8;
            }
        }
        return local_8;
    }
    if (iVar3 == 8) {
        if (*reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x10) == 0) {
            return -0x7fffbffb;
        }
        iVar3 = FUN_0062a866(self, *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x10), param_2, param_3, param_4, param_5, param_6, param_7);
        if (iVar3 < 0) {
            return iVar3;
        }
        if (*param_5 == 0) {
            *param_5 = 1;
        }
        *param_5 = *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x14) * *param_5;
        *piVar2 = *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x14) * *piVar2;
        return iVar3;
    }
    if (iVar3 != 9) {
        pcVar4 = "ID3DXEffectCompiler: Unexpected node encountered when trying to determine type";
        goto LAB_0062a8a7;
    }
    *param_5 = 0;
    *param_6 = 0;
    iVar3 = *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x10);
    if (iVar3 == 0) {
LAB_0062a8fc:
        iVar3 = 1;
        *param_3 = 1;
    }
    else if (iVar3 == 1) {
        *param_3 = *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x1c);
        iVar3 = *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x18);
    }
    else {
        if (iVar3 != 2) {
            if (iVar3 != 3) {
                pcVar4 = "ID3DXEffectCompiler: Unexpected template type";
                goto LAB_0062a8a7;
            }
            goto LAB_0062a8fc;
        }
        *param_3 = *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x18);
        iVar3 = *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x1c);
    }
    *param_4 = iVar3;
    switch(*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x14)) {
    case 0:
        *param_2 = 1;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 0xd:
        *param_2 = 2;
        break;
    case 9:
    case 10:
    case 0xb:
    case 0xc:
        *param_2 = 3;
        break;
    case 0xe:
        *param_2 = 4;
        *param_7 = 4;
        goto LAB_0062aa12;
    case 0xf:
        *param_2 = 5;
        break;
    case 0x10:
        *param_2 = 6;
        break;
    case 0x11:
        *param_2 = 7;
        break;
    case 0x12:
        *param_2 = 8;
        break;
    case 0x13:
        *param_2 = 9;
        break;
    case 0x14:
        *param_2 = 10;
        goto LAB_0062a9d8;
    case 0x15:
        *param_2 = 0xb;
        goto LAB_0062a9d8;
    case 0x16:
        *param_2 = 0xc;
        goto LAB_0062a9d8;
    case 0x17:
        *param_2 = 0xd;
        goto LAB_0062a9d8;
    case 0x18:
        *param_2 = 0xe;
        goto LAB_0062a9d8;
    case 0x19:
        *param_2 = 0xf;
        break;
    case 0x1a:
        *param_2 = 0x10;
        break;
    case 0x1b:
        *param_2 = 0x11;
        break;
    case 0x1c:
        *param_2 = 0x12;
        break;
    case 0x1d:
        *param_2 = 0xf30000;
LAB_0062a9d8:
        *param_7 = 0;
        goto LAB_0062aa12;
    default:
        pcVar4 = "ID3DXEffectCompiler: Unexpected component type";
LAB_0062a8a7:
        FUN_0060fcd3(self_base + 0x28, 0, 0, pcVar4);
        return -0x7fffbffb;
    }
    *param_7 = 4;
LAB_0062aa12:
    *param_7 = *param_3 * *param_4 * *param_7;
    return 0;
}

extern void FUN_0062a705(void* self, char* p1, uint32_t p2);
extern uint32_t FUN_0062a757(void* self, uint32_t p1, uint32_t* p2);
extern int32_t FUN_0062aba8(int32_t param_1, int32_t* param_2, int32_t* param_3);
extern int32_t FUN_0062ace1(int32_t* param_1, uint32_t param_2, int32_t* param_3, int32_t* param_4);
extern int32_t FUN_0062aed7(void* self, int32_t param_1, int32_t* param_2);
extern int32_t FUN_0062afd1(void* self, int32_t param_1, int32_t param_2, int32_t param_3, int32_t param_4, uint32_t param_5, int32_t param_6, int32_t param_7, int32_t param_8);
extern uint32_t DAT_006dd294[4];
extern uint32_t DAT_006f5200[4];

// 0x62aba8 — observed shape
int32_t FUN_0062aba8(int32_t param_1, int32_t* param_2, int32_t* param_3) {
    int32_t iVar1;
    int32_t iVar2;
    int32_t* piVar3;
    int32_t* piVar4;
    int32_t* piVar5;
    int32_t iVar6;
    int32_t iVar7;
    int32_t iVar8;
    int32_t local_8;

    piVar4 = param_3;
    piVar3 = param_2;
    iVar6 = *param_2;
    piVar5 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(param_1 + iVar6));
    iVar8 = piVar5[4];
    iVar1 = piVar5[1];
    if (iVar8 == 0) {
        iVar8 = 1;
    }
    if (iVar1 < 0) {
LAB_0062ac80:
        iVar7 = 0;
    }
    else {
        if (iVar1 < 4) {
            iVar1 = piVar5[6];
            iVar2 = piVar5[5];
            iVar7 = *piVar5;
            if (((iVar7 == 1) || (iVar7 == 2)) || (iVar7 == 3)) {
                iVar7 = 4;
            }
            else {
                iVar7 = 0;
                iVar8 = 0;
            }
            *param_2 = iVar6 + 0x1c;
            iVar7 = iVar1 * iVar2 * iVar7;
            *param_3 = iVar1 * iVar2 * iVar8;
        }
        else if (iVar1 == 4) {
            iVar1 = *piVar5;
            if ((iVar1 < 10) || ((0xe < iVar1 && (iVar1 != 0xf30000)))) {
                iVar7 = 4;
            }
            else {
                iVar7 = 0;
            }
            *param_2 = iVar6 + 0x14;
            *param_3 = iVar8;
        }
        else {
            if (iVar1 != 5) goto LAB_0062ac80;
            iVar1 = piVar5[5];
            param_3 = nullptr;
            *param_2 = iVar6 + 0x18;
            *piVar4 = 0;
            if (iVar1 != 0) {
                param_2 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(iVar1));
                do {
                    iVar6 = FUN_0062aba8(param_1, piVar3, &local_8);
                    param_3 = reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(param_3) + iVar6);
                    *piVar4 = *piVar4 + local_8;
                    param_2 = reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(param_2) - 1);
                } while (param_2 != nullptr);
            }
            *piVar4 = *piVar4 * iVar8;
            iVar7 = static_cast<int32_t>(reinterpret_cast<intptr_t>(param_3));
        }
        iVar7 = iVar7 * iVar8;
    }
    return iVar7;
}

// 0x62ac9b — observed shape
uint32_t FUN_0062ac9b(int32_t* param_1, int32_t* param_2, uint32_t* param_3) {
    int32_t iVar1;
    int32_t* piVar2;
    int32_t* piVar3;
    bool bVar4;

    iVar1 = 4;
    bVar4 = true;
    piVar2 = param_2;
    piVar3 = reinterpret_cast<int32_t*>(DAT_006dd294);
    do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar4 = *piVar2 == *piVar3;
        piVar2 = piVar2 + 1;
        piVar3 = piVar3 + 1;
    } while (bVar4);
    if (!bVar4) {
        iVar1 = 4;
        bVar4 = true;
        piVar2 = reinterpret_cast<int32_t*>(DAT_006f5200);
        do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar4 = *param_2 == *piVar2;
            param_2 = param_2 + 1;
            piVar2 = piVar2 + 1;
        } while (bVar4);
        if (!bVar4) {
            return 0x80004002;
        }
    }
    *param_3 = static_cast<uint32_t>(reinterpret_cast<intptr_t>(param_1));
    (*reinterpret_cast<void (**)(int32_t*)>(reinterpret_cast<uint8_t*>(param_1[0]) + 4))(param_1);
    return 0;
}

// 0x62ace1 — observed shape
int32_t FUN_0062ace1(int32_t* param_1, uint32_t param_2, int32_t* param_3, int32_t* param_4) {
    int32_t* piVar1;
    int32_t iVar2;
    int32_t* piVar3;
    int32_t* piVar4;
    int32_t iVar5;
    int32_t local_8;

    piVar4 = param_4;
    piVar3 = param_3;
    iVar2 = static_cast<int32_t>(param_2);
    iVar5 = *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(param_2)) + 4);
    local_8 = 0;
    if (iVar5 == 1) {
        *param_3 = 1;
        *param_4 = 0;
        while (((((*reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(param_2)) + 4) == 1 &&
                   (iVar5 = *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(param_2)) + 8), iVar5 != 0)) &&
                  (*reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar5)) + 4) == 6)) &&
                 ((*reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar5)) + 0x10) == 1 &&
                   (iVar5 = *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar5)) + 0x18), iVar5 != 0)))) &&
                ((*reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar5)) + 4) == 0xb &&
                  (*reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar5)) + 0x20) != 0))))) {
            iVar5 = FUN_0062ace1(param_1, static_cast<uint32_t>(*reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar5)) + 0x20)), &param_3, &param_4);
            if (iVar5 < 0) {
                return iVar5;
            }
            *piVar4 = *piVar4 + static_cast<int32_t>(reinterpret_cast<intptr_t>(param_3)) * static_cast<int32_t>(reinterpret_cast<intptr_t>(param_4));
            param_2 = static_cast<uint32_t>(*reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(param_2)) + 0xc));
            if (param_2 == 0) {
                return iVar5;
            }
        }
    }
    else {
        if (iVar5 == 8) {
            piVar1 = reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(param_2)) + 0x14);
            param_2 = 0;
            if (*piVar1 != 0) {
                do {
                    local_8 = FUN_0062ace1(param_1, static_cast<uint32_t>(*reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0x10)), piVar3, piVar4);
                    if (local_8 < 0) {
                        return local_8;
                    }
                    param_2 = static_cast<uint32_t>(static_cast<int32_t>(param_2) + 1);
                } while (static_cast<int32_t>(param_2) < *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0x14));
            }
            *piVar4 = *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0x14) * *piVar3 * *piVar4;
            *piVar3 = 1;
            return local_8;
        }
        if ((iVar5 == 9) && (iVar5 = *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(param_2)) + 0x10), -1 < iVar5)) {
            if (iVar5 < 3) {
                *param_3 = *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(param_2)) + 0x18);
                iVar5 = *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(param_2)) + 0x1c);
            }
            else {
                if (iVar5 != 3) {
                    return -0x7fffbffb;
                }
                iVar5 = 1;
                *param_3 = 1;
            }
            *param_4 = iVar5;
            iVar5 = *param_3;
            param_3 = nullptr;
            if (iVar5 * *param_4 == 0) {
                return 0;
            }
            do {
                iVar5 = *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(*param_1)) + 8);
                *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar5)) + 0x10) = 0;
                *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar5)) + 0x14) = 0;
                *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar5)) + 0x18) = 0;
                *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar5)) + 0x1c) = 0;
                switch (*reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(param_2)) + 0x14)) {
                case 0:
                    *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(*reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(*param_1)) + 8))) + 0x10) = 0;
                    break;
                case 1:
                case 2:
                case 3:
                case 4:
                    *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(*reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(*param_1)) + 8))) + 0x10) = 1;
                    break;
                case 5:
                case 6:
                case 7:
                case 8:
                    *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(*reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(*param_1)) + 8))) + 0x10) = 2;
                    break;
                case 9:
                case 10:
                case 0xb:
                case 0xc:
                    *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(*reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(*param_1)) + 8))) + 0x10) = 3;
                    break;
                case 0xd:
                case 0xe:
                case 0xf:
                case 0x10:
                case 0x11:
                case 0x12:
                case 0x13:
                case 0x19:
                case 0x1a:
                case 0x1b:
                case 0x1c:
                    *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(*reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(*param_1)) + 8))) + 0x10) = 5;
                    break;
                case 0x14:
                case 0x15:
                case 0x16:
                case 0x17:
                case 0x18:
                case 0x1d:
                    *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(*reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(*param_1)) + 8))) + 0x10) = 4;
                    break;
                default:
                    goto LAB_0062ae97;
                }
                param_3 = reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(param_3) + 1);
                *param_1 = *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(*param_1)) + 0xc);
                if (static_cast<uint32_t>(*piVar3 * *param_4) <= reinterpret_cast<uintptr_t>(param_3)) {
                    return 0;
                }
            } while (true);
        }
    }
LAB_0062ae97:
    return -0x7fffbffb;
}

// 0x62aed7 — observed shape
int32_t FUN_0062aed7(void* self, int32_t param_1, int32_t* param_2) {
    int32_t* piVar1;
    int32_t iVar2;
    int32_t iVar3;
    int32_t iVar4;
    uint32_t uVar5;
    uint8_t* self_base = static_cast<uint8_t*>(self);

    iVar4 = *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 4);
    if (iVar4 == 1) {
        do {
            iVar4 = FUN_0062aed7(self, *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(*reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(*reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 8))) + 0x18))) + 0x20), param_2);
            if (iVar4 < 0) {
                return iVar4;
            }
            param_1 = *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0xc);
        } while (param_1 != 0);
        return iVar4;
    }
    if (iVar4 == 8) {
        uVar5 = 0;
        if (*reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x14) == 0) {
            return 0;
        }
        do {
            iVar4 = FUN_0062aed7(self, *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x10), param_2);
            if (iVar4 < 0) {
                return iVar4;
            }
            uVar5 = uVar5 + 1;
        } while (uVar5 < *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x14));
        return iVar4;
    }
    if ((iVar4 == 9) && (iVar4 = *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x10), -1 < iVar4)) {
        if (iVar4 < 3) {
            iVar4 = *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x1c) * *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x18);
        }
        else {
            if (iVar4 != 3) goto switchD_0062af2b_default;
            iVar4 = 1;
        }
        switch (*reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x14)) {
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x1d:
            iVar3 = 0;
            break;
        case 0x19:
        case 0x1a:
            *reinterpret_cast<int32_t*>(self_base + 0x334) = *reinterpret_cast<int32_t*>(self_base + 0x334) + 1;
            /* fall through */
        case 0xe:
        case 0xf:
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
            piVar1 = reinterpret_cast<int32_t*>(self_base + 0x330);
            *reinterpret_cast<int32_t*>(static_cast<intptr_t>(*param_2)) = *piVar1;
            *piVar1 = *piVar1 + 1;
            /* fall through */
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 0xb:
        case 0xc:
        case 0xd:
        case 0x1b:
        case 0x1c:
            iVar3 = 4;
            break;
        default:
            goto switchD_0062af2b_default;
        }
        iVar2 = 0;
        *param_2 = *param_2 + iVar3 * iVar4;
    }
    else {
switchD_0062af2b_default:
        iVar2 = -0x7fffbffb;
    }
    return iVar2;
}

// 0x62afd1 — observed shape
int32_t FUN_0062afd1(void* self, int32_t param_1, int32_t param_2, int32_t param_3, int32_t param_4, uint32_t param_5, int32_t param_6, int32_t param_7, int32_t param_8) {
    int32_t iVar1;
    int32_t iVar2;
    int32_t iVar3;
    uint32_t uVar4;
    int32_t iVar5;
    char* pcVar6;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;
    uint8_t* self_base = static_cast<uint8_t*>(self);

    iVar5 = param_1;
    iVar3 = *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 4);
    local_c = 0;
    local_8 = 5;
    local_10 = 0;
    if (iVar3 == 1) {
        iVar3 = static_cast<int32_t>(FUN_0062a64e(self, &local_c, 4, static_cast<uint32_t*>(static_cast<uintptr_t>(static_cast<int32_t>(param_7)))));
        if (iVar3 < 0) {
            return iVar3;
        }
        iVar3 = static_cast<int32_t>(FUN_0062a64e(self, &local_8, 4, nullptr));
        if (iVar3 < 0) {
            return iVar3;
        }
        param_7 = 0;
        iVar3 = iVar5;
        do {
            iVar3 = *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar3)) + 0xc);
            param_7 = param_7 + 1;
        } while (iVar3 != 0);
        param_1 = iVar5;
        if ((param_2 == 0) || (param_6 == 0)) {
            iVar3 = static_cast<int32_t>(FUN_0062a64e(self, &local_10, 4, nullptr));
        }
        else {
            iVar3 = static_cast<int32_t>(FUN_0062a705(self, *reinterpret_cast<char**>(static_cast<uint8_t*>(static_cast<intptr_t>(param_2)) + 8), &param_2));
            if (iVar3 < 0) {
                return iVar3;
            }
            iVar3 = static_cast<int32_t>(FUN_0062a757(self, static_cast<uint32_t>(param_2), nullptr));
        }
        if (iVar3 < 0) {
            return iVar3;
        }
        if ((param_3 == 0) || (param_6 == 0)) {
            iVar3 = static_cast<int32_t>(FUN_0062a64e(self, &local_10, 4, nullptr));
        }
        else {
            iVar3 = static_cast<int32_t>(FUN_0062a705(self, reinterpret_cast<char*>(static_cast<intptr_t>(param_3)), &param_2));
            if (iVar3 < 0) {
                return iVar3;
            }
            iVar3 = static_cast<int32_t>(FUN_0062a757(self, static_cast<uint32_t>(param_2), nullptr));
        }
        if (iVar3 < 0) {
            return iVar3;
        }
        iVar3 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(&param_4), 4, nullptr));
        if (iVar3 < 0) {
            return iVar3;
        }
        iVar3 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(&param_7), 4, nullptr));
        if (iVar3 < 0) {
            return iVar3;
        }
        iVar5 = param_1;
        while (true) {
            if (iVar5 == 0) {
                return iVar3;
            }
            if (*reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar5)) + 4) != 1) {
                return -0x7fffbffb;
            }
            iVar3 = *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar5)) + 8);
            if (iVar3 == 0) {
                return -0x7fffbffb;
            }
            if (*reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar3)) + 4) != 6) {
                return -0x7fffbffb;
            }
            iVar1 = *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar3)) + 0x14);
            if (iVar1 == 0) {
                return -0x7fffbffb;
            }
            if (*reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar1)) + 4) != 3) {
                return -0x7fffbffb;
            }
            if (*reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar1)) + 0x10) != 9) {
                return -0x7fffbffb;
            }
            if (*reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar1)) + 0x18) == 0) break;
            if (*reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar3)) + 0x10) != 1) {
                return -0x7fffbffb;
            }
            iVar3 = *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar3)) + 0x18);
            if (iVar3 == 0) {
                return -0x7fffbffb;
            }
            if (*reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar3)) + 4) != 0xb) {
                return -0x7fffbffb;
            }
            if (*reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar3)) + 0x20) == 0) {
                return -0x7fffbffb;
            }
            iVar2 = *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar3)) + 0x2c);
            uVar4 = 0;
            if (iVar2 != 0) {
                if (*reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 4) != 3) {
                    return -0x7fffbffb;
                }
                if (*reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0x10) != 9) {
                    return -0x7fffbffb;
                }
                uVar4 = *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) + 0x18);
            }
            iVar3 = FUN_0062afd1(self, *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar3)) + 0x20), *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar1)) + 0x10), static_cast<int32_t>(uVar4), 0, param_5, param_6, 0, 1);
            if (iVar3 < 0) {
                return iVar3;
            }
            iVar5 = *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(iVar5)) + 0xc);
        }
        return -0x7fffbffb;
    }
    if (iVar3 == 8) {
        iVar3 = param_3;
        if (param_3 == 0) {
            iVar3 = 1;
        }
        iVar3 = FUN_0062afd1(self, *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x10), param_2, param_3, *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x14) * iVar3, param_5, param_6, param_7, 0);
        return iVar3;
    }
    if (iVar3 != 9) {
        return -0x7fffbffb;
    }
    iVar3 = *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x10);
    if (iVar3 != 0) {
        if (iVar3 == 1) {
            local_8 = *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x1c);
            local_c = *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x18);
            param_8 = 1;
            goto LAB_0062b06d;
        }
        if (iVar3 == 2) {
            local_8 = *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x18);
            local_c = *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x1c);
            param_8 = 2;
            goto LAB_0062b06d;
        }
        if (iVar3 != 3) {
            return -0x7fffbffb;
        }
        if (param_8 == 0) {
            param_8 = 4;
            local_8 = 0;
            local_c = 0;
            goto LAB_0062b06d;
        }
        pcVar6 = "ID3DXEffectCompiler: Only numeric types are allowed inside structures";
        goto LAB_0062b24d;
    }
    local_c = 1;
    param_8 = 0;
    local_8 = 1;
LAB_0062b06d:
    switch (*reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(static_cast<intptr_t>(param_1)) + 0x14)) {
    case 0:
        param_1 = 1;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 0xd:
        param_1 = 2;
        break;
    case 9:
    case 10:
    case 0xb:
    case 0xc:
        param_1 = 3;
        break;
    case 0xe:
        param_1 = 4;
        break;
    case 0xf:
        param_1 = 5;
        goto LAB_0062b23f;
    case 0x10:
        param_1 = 6;
        goto LAB_0062b23f;
    case 0x11:
        param_1 = 7;
        goto LAB_0062b23f;
    case 0x12:
        param_1 = 8;
        goto LAB_0062b23f;
    case 0x13:
        param_1 = 9;
        goto LAB_0062b23f;
    case 0x14:
        param_1 = 10;
        break;
    case 0x15:
        param_1 = 0xb;
        break;
    case 0x16:
        param_1 = 0xc;
        break;
    case 0x17:
        param_1 = 0xd;
        break;
    case 0x18:
        param_1 = 0xe;
        break;
    case 0x19:
        param_1 = 0xf;
        break;
    case 0x1a:
        param_1 = 0x10;
        break;
    case 0x1b:
        param_1 = 0x11;
        goto LAB_0062b23f;
    case 0x1c:
        param_1 = 0x12;
        goto LAB_0062b23f;
    case 0x1d:
        param_1 = 0xf30000;
LAB_0062b23f:
        if (param_4 != 0) {
            pcVar6 = "ID3DXEffectCompiler: Arrays must be either numeric, structure, string or shader";
LAB_0062b24d:
            FUN_0060fcd3(self_base + 0x28, static_cast<uint32_t>(param_2), 0, pcVar6);
LAB_0062b262:
            return -0x7fffbffb;
        }
        break;
    default:
        goto LAB_0062b262;
    }
    iVar3 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(&param_1), 4, reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(static_cast<int32_t>(param_7)))));
    if (-1 < iVar3) {
        iVar3 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(&param_8), 4, nullptr));
        iVar5 = param_6;
        if (-1 < iVar3) {
            if ((param_2 == 0) || (param_6 == 0)) {
                iVar3 = static_cast<int32_t>(FUN_0062a64e(self, &local_10, 4, nullptr));
            }
            else {
                iVar3 = static_cast<int32_t>(FUN_0062a705(self, *reinterpret_cast<char**>(static_cast<uint8_t*>(static_cast<intptr_t>(param_2)) + 8), &param_2));
                if (iVar3 < 0) {
                    return iVar3;
                }
                iVar3 = static_cast<int32_t>(FUN_0062a757(self, static_cast<uint32_t>(param_2), nullptr));
            }
            if (-1 < iVar3) {
                if ((param_3 == 0) || (iVar5 == 0)) {
                    iVar3 = static_cast<int32_t>(FUN_0062a64e(self, &local_10, 4, nullptr));
                }
                else {
                    iVar3 = static_cast<int32_t>(FUN_0062a705(self, reinterpret_cast<char*>(static_cast<intptr_t>(param_3)), &param_2));
                    if (iVar3 < 0) {
                        return iVar3;
                    }
                    iVar3 = static_cast<int32_t>(FUN_0062a757(self, static_cast<uint32_t>(param_2), nullptr));
                }
                if ((((-1 < iVar3) && (iVar3 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(&param_4), 4, nullptr)), -1 < iVar3)) && (0 < param_1)) &&
                   ((param_1 < 4 && (iVar3 = static_cast<int32_t>(FUN_0062a64e(self, &local_8, 4, nullptr)), -1 < iVar3)))) {
                    iVar3 = static_cast<int32_t>(FUN_0062a64e(self, &local_c, 4, nullptr));
                }
            }
        }
    }
    return iVar3;
}

#include <cmath>

extern int32_t ftol_ld(long double v);
extern int32_t _stricmp(const char* a, const char* b);
extern int32_t FUN_0062afd1(void* self, int32_t param_1, int32_t param_2, int32_t param_3, int32_t param_4, uint32_t param_5, int32_t param_6, int32_t param_7, int32_t param_8);
extern int32_t FUN_0062b4f8(void* self, int32_t* param_1, uint32_t param_2, int32_t param_3, void** param_4, int32_t* param_5, uint32_t param_6, uint32_t param_7, float param_8);

static inline int32_t& rd_i32(uint32_t addr) {
    return *reinterpret_cast<int32_t*>(static_cast<intptr_t>(addr));
}
static inline uint32_t& rd_u32(uint32_t addr) {
    return *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(addr));
}

extern void* PTR_s_ZENABLE_006e2128[];
extern void* PTR_PTR_006e2140[];
extern int32_t DAT_006e212c[];
extern uint32_t DAT_006e213c[];

// 0x62b4f8 — observed shape
int32_t FUN_0062b4f8(void* self, int32_t* param_1, uint32_t param_2, int32_t param_3, void** param_4, int32_t* param_5, uint32_t param_6, uint32_t param_7, float param_8) {
    float fVar1;
    float fVar4;
    int32_t* piVar2;
    float* pfVar3;
    int32_t* piVar5;
    void** ppuVar6;
    int32_t iVar7;
    uint32_t uVar8;
    uint32_t uVar9;
    int32_t iVar10;
    float* pfVar11;
    bool bVar12;
    long double fVar13;
    long double fVar14;
    long double fVar15;
    long double fVar16;
    const char* pcVar17;
    void* puVar18;
    uint32_t local_34;
    uint32_t local_30;
    int32_t local_2c;
    uint32_t local_28;
    uint32_t local_24;
    int32_t local_1c;
    uint32_t local_18;
    uint32_t local_14;
    int32_t local_10;
    uint8_t* local_8;
    int32_t* local_20;
    float* local_c;
    int32_t stateIdx;

    piVar2 = param_1;
    piVar5 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(param_1[10]));
    iVar10 = 0;
    local_c = nullptr;
    local_20 = nullptr;
    local_10 = 0;
    local_2c = 0;
    if (piVar5 != nullptr) {
        do {
            if (*param_1 == *piVar5) {
                if (param_8 != -NAN) {
                    return 0;
                }
                if (param_1[1] == piVar5[1]) {
                    return 0;
                }
            }
            piVar5 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(piVar5[10]));
        } while (piVar5 != nullptr);
    }
    iVar7 = *param_1;
    uVar9 = static_cast<uint32_t>(param_1[2]);
    local_18 = static_cast<uint32_t>(param_1[3]);
    local_34 = static_cast<uint32_t>(param_1[1]);
    local_24 = static_cast<uint32_t>(param_1[4]);
    local_28 = static_cast<uint32_t>(param_1[5]);
    local_30 = static_cast<uint32_t>(param_1[6]);
    param_8 = static_cast<float>(param_1[8]);
    stateIdx = iVar7;
    local_8 = static_cast<uint8_t*>(self);
    if (rd_i32(uVar9 + 4) == 1) {
        iVar7 = rd_i32(uVar9 + 8);
        if (iVar7 == 0) {
            return -0x7fffbffb;
        }
        if (rd_i32(static_cast<uint32_t>(iVar7) + 4) == 3) {
            if ((rd_i32(static_cast<uint32_t>(iVar7) + 0x10) < 5) || (8 < rd_i32(static_cast<uint32_t>(iVar7) + 0x10))) {
                param_8 = 0.0f;
                for (param_2 = uVar9; param_2 != 0; param_2 = rd_u32(param_2 + 0xc)) {
                    if (rd_i32(param_2 + 4) != 1) {
                        return -0x7fffbffb;
                    }
                    iVar10 = rd_i32(param_2 + 8);
                    if (iVar10 == 0) {
                        return -0x7fffbffb;
                    }
                    if (rd_i32(static_cast<uint32_t>(iVar10) + 4) != 3) {
                        return -0x7fffbffb;
                    }
                    iVar7 = rd_i32(static_cast<uint32_t>(iVar10) + 0x10);
                    if (iVar7 < 2) {
LAB_0062be5a:
                        puVar18 = PTR_s_ZENABLE_006e2128[stateIdx * 7];
                        pcVar17 = "ID3DXEffectCompiler: State '%s' accepts only dwords and ids";
                        goto LAB_0062b58d;
                    }
                    if (iVar7 < 5) {
                        uVar9 = rd_u32(static_cast<uint32_t>(iVar10) + 0x18);
                    }
                    else {
                        if (iVar7 != 9) goto LAB_0062be5a;
                        if (rd_i32(static_cast<uint32_t>(iVar10) + 0x18) == 0) {
                            return -0x7fffbffb;
                        }
                        param_4 = PTR_PTR_006e2140 + stateIdx * 7;
                        piVar5 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(*reinterpret_cast<uint32_t*>(param_4)));
                        if (piVar5 == nullptr) {
LAB_0062be2d:
                            FUN_0060fcd3(reinterpret_cast<uint8_t*>(local_8) + 0x28, static_cast<uint32_t>(piVar2[9]), 0,
                                         "ID3DXEffectCompiler: State '%s' does not accept '%s' as a value",
                                         PTR_s_ZENABLE_006e2128[stateIdx * 7],
                                         reinterpret_cast<void*>(static_cast<intptr_t>(rd_i32(static_cast<uint32_t>(iVar10) + 0x18))));
                            return -0x7fffbffb;
                        }
                        param_3 = 0;
                        iVar7 = *piVar5;
                        while ((iVar7 != 0 &&
                                (iVar7 = _stricmp(reinterpret_cast<char*>(static_cast<intptr_t>(piVar5[param_3 * 2])), reinterpret_cast<char*>(static_cast<intptr_t>(rd_i32(static_cast<uint32_t>(iVar10) + 0x18)))),
                                 iVar7 != 0))) {
                            param_3 = param_3 + 1;
                            piVar5 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(*reinterpret_cast<uint32_t*>(param_4)));
                            iVar7 = piVar5[param_3 * 2];
                        }
                        if (rd_i32(*reinterpret_cast<uint32_t*>(param_4) + static_cast<uint32_t>(param_3) * 8) == 0) goto LAB_0062be2d;
                        uVar9 = rd_u32(*reinterpret_cast<uint32_t*>(param_4) + static_cast<uint32_t>(param_3) * 8 + 4);
                    }
                    param_8 = static_cast<float>(static_cast<uint32_t>(param_8) | uVar9);
                }
                iVar10 = DAT_006e213c[stateIdx * 7];
                if (iVar10 == 0x5000000) {
                    if (param_8 == 0.0f) {
                        FUN_0060fcd3(local_8 + 0x28, static_cast<uint32_t>(piVar2[9]), 0,
                                     "ID3DXEffectCompiler: FVFs must not evaluate to NULL");
                        return -0x7fffbffb;
                    }
                }
                else if (iVar10 == 0x9000000) {
LAB_0062bea4:
                    if (param_8 != 0.0f) {
                        puVar18 = PTR_s_ZENABLE_006e2128[stateIdx * 7];
                        pcVar17 = "ID3DXEffectCompiler: Dword expressions for state '%s' must be evaluate to NULL";
LAB_0062b58d:
                        FUN_0060fcd3(local_8 + 0x28, static_cast<uint32_t>(piVar2[9]), 0, pcVar17, puVar18);
                        return -0x7fffbffb;
                    }
                }
                else if (iVar10 == 0xa000000) {
                    if (param_8 != 0.0f) {
                        stateIdx = 0;
                        ppuVar6 = PTR_s_ZENABLE_006e2128;
                        do {
                            if (reinterpret_cast<uint32_t>(ppuVar6[5]) == 0x5000000) break;
                            stateIdx = stateIdx + 1;
                            ppuVar6 = ppuVar6 + 7;
                        } while (ppuVar6[0] != nullptr);
                        local_2c = 1;
                    }
                }
                else {
                    if (iVar10 == 0xb000000) goto LAB_0062bea4;
                    if (iVar10 == 0xe000000) {
                        return 0;
                    }
                    if (iVar10 == 0xf000000) {
                        return 0;
                    }
                }
                param_2 = 0;
            }
            else {
                param_8 = static_cast<float>(*reinterpret_cast<double*>(static_cast<intptr_t>(rd_i32(static_cast<uint32_t>(iVar7) + 0x18))));
            }
            iVar10 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(&param_8), 4, reinterpret_cast<uint32_t*>(&local_14)));
            if (iVar10 < 0) {
                return iVar10;
            }
        }
        else if (rd_i32(static_cast<uint32_t>(iVar7) + 4) == 0xd) {
            pfVar3 = static_cast<float*>(FUN_00533c78(static_cast<uint32_t>(param_8)));
            local_c = pfVar3;
            if (pfVar3 == nullptr) goto LAB_0062b6d8;
            pfVar11 = pfVar3;
            for (uVar9 = static_cast<uint32_t>(param_8) >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
                *pfVar11 = 0.0f;
                pfVar11 = pfVar11 + 1;
            }
            for (uVar9 = static_cast<uint32_t>(param_8) & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
                *reinterpret_cast<uint8_t*>(pfVar11) = 0;
                pfVar11 = reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(pfVar11) + 1);
            }
            param_2 = static_cast<uint32_t>(piVar2[2]);
            if (param_2 != 0) {
                do {
                    if (((rd_i32(param_2 + 4) != 1) || (iVar10 = rd_i32(param_2 + 8), iVar10 == 0)) ||
                        (rd_i32(static_cast<uint32_t>(iVar10) + 4) != 0xd)) goto LAB_0062b91c;
                    param_3 = 0;
                    if (((rd_i32(static_cast<uint32_t>(iVar10) + 0x1c) == 5) && (iVar7 = rd_i32(static_cast<uint32_t>(iVar10) + 0x20), iVar7 != 0)) &&
                        (rd_i32(static_cast<uint32_t>(iVar7) + 4) == 0xd)) {
                        param_3 = 1;
                        while ((iVar10 = iVar7, rd_i32(static_cast<uint32_t>(iVar10) + 0x1c) == 0 &&
                                (iVar7 = rd_i32(static_cast<uint32_t>(iVar10) + 0x20), iVar7 != 0))) {
                            if ((rd_i32(static_cast<uint32_t>(iVar7) + 4) != 1) ||
                                ((iVar7 = rd_i32(static_cast<uint32_t>(iVar7) + 8), iVar7 == 0 || (rd_i32(static_cast<uint32_t>(iVar7) + 4) != 0xd)))) break;
                        }
                    }
                    if ((rd_i32(static_cast<uint32_t>(iVar10) + 0x1c) != 0) ||
                        ((((iVar10 = rd_i32(static_cast<uint32_t>(iVar10) + 0x20), iVar10 == 0 || (rd_i32(static_cast<uint32_t>(iVar10) + 4) != 1)) ||
                           (iVar10 = rd_i32(static_cast<uint32_t>(iVar10) + 8), iVar10 == 0)) ||
                          ((rd_i32(static_cast<uint32_t>(iVar10) + 4) != 0xe || (rd_i32(static_cast<uint32_t>(iVar10) + 0x10) == 6)))))) {
                        pcVar17 = "ID3DXEffectCompiler: Initializer list elements cannot be complex expressions or variables";
LAB_0062b909:
                        FUN_0060fcd3(local_8 + 0x28, static_cast<uint32_t>(piVar2[9]), 0, pcVar17);
                        goto LAB_0062b91c;
                    }
                    iVar7 = DAT_006e212c[stateIdx * 7];
                    if (iVar7 == 1) {
                        iVar7 = rd_i32(static_cast<uint32_t>(iVar10) + 0x10);
                        if (((iVar7 == 0) || (iVar7 == 1)) || (iVar7 == 2)) {
                            *pfVar3 = static_cast<float>(static_cast<uint32_t>(rd_i32(static_cast<uint32_t>(iVar10) + 0x18) != 0));
                        }
                        else {
                            if (iVar7 != 3) {
LAB_0062b8fd:
                                pcVar17 = "ID3DXEffectCompiler: Unexpected error";
                                goto LAB_0062b909;
                            }
                            *pfVar3 = static_cast<float>(static_cast<uint32_t>(*reinterpret_cast<double*>(static_cast<intptr_t>(rd_i32(static_cast<uint32_t>(iVar10) + 0x18))) != 0.0));
                        }
                    }
                    else if (iVar7 == 2) {
                        iVar7 = rd_i32(static_cast<uint32_t>(iVar10) + 0x10);
                        if (iVar7 == 0) {
                            *pfVar3 = static_cast<float>(static_cast<uint32_t>(rd_i32(static_cast<uint32_t>(iVar10) + 0x18) != 0));
                        }
                        else if ((iVar7 == 1) || (iVar7 == 2)) {
                            *pfVar3 = *reinterpret_cast<float*>(static_cast<intptr_t>(rd_i32(static_cast<uint32_t>(iVar10) + 0x18)));
                        }
                        else {
                            if (iVar7 != 3) goto LAB_0062b8fd;
                            fVar4 = static_cast<float>(ftol_ld(*reinterpret_cast<double*>(static_cast<intptr_t>(rd_i32(static_cast<uint32_t>(iVar10) + 0x18)))));
                            *pfVar3 = fVar4;
                        }
                        if (param_3 != 0) {
                            *pfVar3 = static_cast<float>(-static_cast<int32_t>(*pfVar3));
                        }
                    }
                    else {
                        if ((iVar7 != 3) && (iVar7 != 0xf20000)) {
                            pcVar17 = "ID3DXEffectCompiler: Error in type checking";
                            goto LAB_0062b909;
                        }
                        iVar7 = rd_i32(static_cast<uint32_t>(iVar10) + 0x10);
                        if (iVar7 == 0) {
                            fVar4 = static_cast<float>(rd_i32(static_cast<uint32_t>(iVar10) + 0x18) != 0);
                        }
                        else if (iVar7 == 1) {
                            fVar4 = static_cast<float>(rd_i32(static_cast<uint32_t>(iVar10) + 0x18));
                        }
                        else if (iVar7 == 2) {
                            fVar4 = static_cast<float>(rd_i32(static_cast<uint32_t>(iVar10) + 0x18));
                            if (rd_i32(static_cast<uint32_t>(iVar10) + 0x18) < 0) {
                                fVar4 = fVar4 + 4.2949673e+09f;
                            }
                        }
                        else {
                            if (iVar7 != 3) goto LAB_0062b8fd;
                            fVar4 = static_cast<float>(*reinterpret_cast<double*>(static_cast<intptr_t>(rd_i32(static_cast<uint32_t>(iVar10) + 0x18))));
                        }
                        *pfVar3 = fVar4;
                        if (param_3 != 0) {
                            *pfVar3 = -*pfVar3;
                        }
                    }
                    param_2 = rd_u32(param_2 + 0xc);
                    pfVar3 = pfVar3 + 1;
                } while (param_2 != 0);
            }
            if (DAT_006e212c[stateIdx * 7] == 0xf20000) {
                fVar13 = static_cast<long double>(local_c[3]);
                fVar14 = 1.0L;
                fVar4 = local_c[1];
                fVar1 = local_c[2];
                fVar15 = 0.0L;
                if (static_cast<long double>(*local_c) < fVar14) {
                    fVar16 = static_cast<long double>(*local_c);
                    if ((std::isnan(static_cast<double>(fVar16)) || std::isnan(static_cast<double>(fVar15))) || (fVar16 < fVar15) == (fVar16 == fVar15)) {
                        fVar13 = fVar14;
                        param_8 = static_cast<float>(ftol_ld(fVar16));
                        fVar15 = 0.0L;
                        fVar14 = 1.0L;
                    }
                    else {
                        param_8 = 0.0f;
                    }
                }
                else {
                    param_8 = 3.57331e-43f;
                }
                if (static_cast<long double>(fVar4) < fVar14) {
                    fVar16 = static_cast<long double>(fVar4);
                    if ((std::isnan(static_cast<double>(fVar16)) || std::isnan(static_cast<double>(fVar15))) || (fVar16 < fVar15) == (fVar16 == fVar15)) {
                        fVar13 = fVar14;
                        param_2 = static_cast<uint32_t>(ftol_ld(fVar16));
                        fVar15 = 0.0L;
                        fVar14 = 1.0L;
                    }
                    else {
                        param_2 = 0;
                    }
                }
                else {
                    param_2 = 0xff;
                }
                if (static_cast<long double>(fVar1) < fVar14) {
                    fVar16 = static_cast<long double>(fVar1);
                    if ((std::isnan(static_cast<double>(fVar16)) || std::isnan(static_cast<double>(fVar15))) || (fVar16 < fVar15) == (fVar16 == fVar15)) {
                        uVar9 = static_cast<uint32_t>(ftol_ld(fVar16));
                        fVar14 = 0.0L;
                        fVar13 = 1.0L;
                    }
                    else {
                        uVar9 = 0;
                    }
                }
                else {
                    uVar9 = 0xff;
                }
                if (fVar13 < fVar14) {
                    fVar14 = 0.0L;
                    if ((std::isnan(static_cast<double>(fVar13)) || std::isnan(static_cast<double>(fVar14))) || (fVar13 < fVar14) == (fVar13 == fVar14)) {
                        iVar10 = static_cast<int32_t>(ftol_ld(fVar13));
                    }
                    else {
                        iVar10 = 0;
                    }
                }
                else {
                    iVar10 = 0xff;
                }
                local_18 = 2;
                param_8 = static_cast<float>((((static_cast<uint32_t>(iVar10) << 8 | static_cast<uint32_t>(param_8)) << 8 | param_2) << 8 | uVar9));
                local_24 = 1;
                local_28 = 1;
                iVar10 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(&param_8), 4, reinterpret_cast<uint32_t*>(&local_14)));
            }
            else {
                iVar10 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(local_c), static_cast<uint32_t>(param_8), reinterpret_cast<uint32_t*>(&local_14)));
            }
            if (iVar10 < 0) goto LAB_0062be15;
            operator_delete(local_c);
            local_c = nullptr;
        }
    }
    else {
        if (rd_i32(uVar9 + 4) != 0xd) {
            puVar18 = PTR_s_ZENABLE_006e2128[stateIdx * 7];
            pcVar17 = "ID3DXEffectCompiler: State '%s' was assigned an unsupported value";
            goto LAB_0062b58d;
        }
        if (local_18 < 5) {
LAB_0062b5c6:
            local_c = static_cast<float*>(FUN_00533c78(static_cast<uint32_t>(param_8)));
            if (local_c == nullptr) {
LAB_0062b6d8:
                iVar10 = -0x7ff8fff2;
                goto LAB_0062be15;
            }
            pfVar3 = local_c;
            for (uVar8 = static_cast<uint32_t>(param_8) >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                *pfVar3 = 0.0f;
                pfVar3 = pfVar3 + 1;
            }
            for (uVar8 = static_cast<uint32_t>(param_8) & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
                *reinterpret_cast<uint8_t*>(pfVar3) = 0;
                pfVar3 = reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(pfVar3) + 1);
            }
            iVar10 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(local_c), static_cast<uint32_t>(param_8), reinterpret_cast<uint32_t*>(&local_14)));
            if (iVar10 < 0) goto LAB_0062be15;
        }
        else if (local_18 < 10) {
LAB_0062b625:
            iVar10 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(local_8 + 0x330), 4, reinterpret_cast<uint32_t*>(&local_14)));
            if (iVar10 < 0) {
                return iVar10;
            }
            *reinterpret_cast<int32_t*>(local_8 + 0x330) = *reinterpret_cast<int32_t*>(local_8 + 0x330) + 1;
        }
        else if (local_18 < 0xf) {
            iVar10 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(&local_10), 4, reinterpret_cast<uint32_t*>(&local_14)));
            if (iVar10 < 0) {
                return iVar10;
            }
        }
        else {
            if (local_18 < 0x11) {
                *reinterpret_cast<int32_t*>(local_8 + 0x334) = *reinterpret_cast<int32_t*>(local_8 + 0x334) + 1;
                goto LAB_0062b625;
            }
            if (local_18 != 0xf30000) goto LAB_0062b5c6;
        }
        local_20 = static_cast<int32_t*>(FUN_00533c78(0x24));
        if (local_20 == nullptr) {
            local_20 = nullptr;
        }
        else {
            local_20[6] = 0;
        }
        if (local_20 == nullptr) {
LAB_0062b91c:
            iVar10 = -0x7fffbffb;
            goto LAB_0062be15;
        }
        *local_20 = static_cast<int32_t>(reinterpret_cast<intptr_t>(param_1));
        local_20[1] = static_cast<int32_t>(param_2);
        local_20[2] = param_3;
        local_20[3] = static_cast<int32_t>(reinterpret_cast<intptr_t>(param_4));
        local_20[4] = *param_5;
        local_20[5] = static_cast<int32_t>(uVar9);
    }
    if (local_18 == 0) {
        iVar7 = FUN_0062afd1(self, rd_i32(static_cast<uint32_t>(piVar2[2]) + 0x10), 0, 0, 0, param_7, 0, &local_1c, 0);
        if (iVar7 < 0) {
            FUN_0060fcd3(local_8 + 0x28, static_cast<uint32_t>(piVar2[9]), 0,
                         "ID3DXEffectCompiler: Error initializing assignment type");
            goto LAB_0062be07;
        }
LAB_0062bc6c:
        iVar10 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(&param_1), 4, nullptr));
        if (((-1 < iVar10) && (iVar10 = static_cast<int32_t>(FUN_0062a64e(self, &local_34, 4, nullptr)), -1 < iVar10)) &&
            (iVar10 = static_cast<int32_t>(FUN_0062a757(self, static_cast<uint32_t>(local_1c), nullptr)), -1 < iVar10)) {
            iVar10 = static_cast<int32_t>(FUN_0062a757(self, local_14, nullptr));
            piVar5 = local_20;
            if (-1 < iVar10) {
                if (local_20 != nullptr) {
                    local_20[8] = local_1c;
                    local_20 = nullptr;
                    piVar5[7] = static_cast<int32_t>(local_14);
                    piVar5[6] = *reinterpret_cast<int32_t*>(local_8 + 0x354);
                    *reinterpret_cast<int32_t*>(local_8 + 0x354) = static_cast<int32_t>(reinterpret_cast<intptr_t>(piVar5));
                }
                *param_5 = *param_5 + 1;
                if (local_2c != 0) {
                    param_1 = reinterpret_cast<int32_t*>(0x4);
                    local_18 = 0x10;
                    iVar10 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(&local_18), 4, reinterpret_cast<uint32_t*>(&local_1c)));
                    if (((-1 < iVar10) && (iVar10 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(&param_1), 4, nullptr)), -1 < iVar10)) &&
                        ((iVar10 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(&local_10), 4, nullptr)), -1 < iVar10 &&
                          ((iVar10 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(&local_10), 4, nullptr)), -1 < iVar10 &&
                           (iVar10 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(&local_10), 4, nullptr)), -1 < iVar10))))) {
                        param_1 = nullptr;
                        ppuVar6 = PTR_s_ZENABLE_006e2128;
                        do {
                            if (reinterpret_cast<uint32_t>(ppuVar6[5]) == 0xa000000) break;
                            param_1 = reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(param_1) + 1);
                            ppuVar6 = ppuVar6 + 7;
                        } while (ppuVar6[0] != nullptr);
                        iVar10 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(&param_1), 4, nullptr));
                        if ((((-1 < iVar10) && (iVar10 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(&local_10), 4, nullptr)), -1 < iVar10)) &&
                             (iVar10 = static_cast<int32_t>(FUN_0062a757(self, static_cast<uint32_t>(local_1c), nullptr)), -1 < iVar10)) &&
                            (iVar10 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(&local_10), 4, nullptr)), -1 < iVar10)) {
                            *param_5 = *param_5 + 1;
                        }
                    }
                }
            }
        }
    }
    else if (local_18 < 1) {
LAB_0062bfdf:
        FUN_0060fcd3(local_8 + 0x28, static_cast<uint32_t>(piVar2[9]), 0,
                     "ID3DXEffectCompiler: Internal error initializing assignment - missing type case");
        iVar10 = -0x7fffbffb;
    }
    else {
        if (local_18 < 4) {
            uVar9 = DAT_006e213c[stateIdx * 7];
            if (uVar9 < 0xd000005) {
                if (uVar9 < 0xd000000) {
                    if (uVar9 < 0xc000000) goto LAB_0062bf2d;
                    if ((0xc000004 < uVar9) && (uVar9 != 0xc010000)) {
                        bVar12 = uVar9 == 0xc020000;
                        goto LAB_0062bf2b;
                    }
                }
LAB_0062bf36:
                param_8 = 4.2039e-45f;
            }
            else {
                if (uVar9 == 0xd010000) goto LAB_0062bf36;
                bVar12 = uVar9 == 0xd020000;
LAB_0062bf2b:
                if (bVar12) goto LAB_0062bf36;
LAB_0062bf2d:
                param_8 = 2.8026e-45f;
            }
            iVar10 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(&local_18), 4, reinterpret_cast<uint32_t*>(&local_1c)));
            if (((((iVar10 < 0) || (iVar10 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(&param_8), 4, nullptr)), iVar10 < 0)) ||
                  (iVar10 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(&local_10), 4, nullptr)), iVar10 < 0)) ||
                 ((iVar10 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(&local_10), 4, nullptr)), iVar10 < 0 ||
                  (iVar10 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(&local_30), 4, nullptr)), iVar10 < 0)))) ||
                (iVar10 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(&local_24), 4, nullptr)), iVar10 < 0)) goto LAB_0062be07;
            piVar5 = reinterpret_cast<int32_t*>(&local_28);
        }
        else {
            if ((local_18 < 5) || (0x10 < local_18)) goto LAB_0062bfdf;
            param_8 = 5.60519e-45f;
            iVar10 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(&local_18), 4, reinterpret_cast<uint32_t*>(&local_1c)));
            if ((((iVar10 < 0) || (iVar10 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(&param_8), 4, nullptr)), iVar10 < 0)) ||
                 (iVar10 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(&local_10), 4, nullptr)), iVar10 < 0)) ||
                (iVar10 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(&local_10), 4, nullptr)), iVar10 < 0)) goto LAB_0062be07;
            piVar5 = reinterpret_cast<int32_t*>(&local_10);
        }
        iVar10 = static_cast<int32_t>(FUN_0062a64e(self, reinterpret_cast<uint32_t*>(piVar5), 4, nullptr));
        if (-1 < iVar10) goto LAB_0062bc6c;
    }
LAB_0062be07:
    if (local_20 != nullptr) {
        FUN_0062a5b1(static_cast<void*>(local_20), 1);
    }
LAB_0062be15:
    if (local_c != nullptr) {
        operator_delete(local_c);
    }
    return iVar10;
}

extern uint32_t FUN_0062c50d(void* self, uint8_t* param_1);
extern int32_t FUN_0062c5a3(void* self, uint8_t* param_1);

// 0x62c043 — observed shape
int32_t FUN_0062c043(void* self, int32_t param_1, uint32_t* param_2, int32_t* param_3, int32_t* param_4, int32_t* param_5, int32_t* param_6, int32_t* param_7, int32_t* param_8, uint32_t param_9) {
    int32_t iVar1;
    int32_t iVar2;
    const char* pcVar3;
    int32_t iVar4;
    uint8_t* self_base = static_cast<uint8_t*>(self);

    iVar2 = 0;
    if (rd_i32(static_cast<uint32_t>(param_1) + 4) == 1) {
        iVar1 = rd_i32(static_cast<uint32_t>(param_1) + 8);
        if (iVar1 == 0) {
            return -0x7fffbffb;
        }
        if (rd_i32(static_cast<uint32_t>(iVar1) + 4) == 3) {
            if ((rd_i32(static_cast<uint32_t>(iVar1) + 0x10) < 5) || (8 < rd_i32(static_cast<uint32_t>(iVar1) + 0x10))) {
                *param_3 = 2;
            }
            else {
                *param_3 = 3;
            }
            *param_4 = 1;
            *param_5 = 1;
            *param_6 = 0;
            *param_7 = 0;
            *param_8 = 4;
            return 0;
        }
        if (rd_i32(static_cast<uint32_t>(iVar1) + 4) == 0xd) {
            while (true) {
                if (rd_i32(static_cast<uint32_t>(param_1) + 4) != 1) {
                    return -0x7fffbffb;
                }
                iVar1 = rd_i32(static_cast<uint32_t>(param_1) + 8);
                if (iVar1 == 0) {
                    return -0x7fffbffb;
                }
                if (rd_i32(static_cast<uint32_t>(iVar1) + 4) != 0xd) {
                    return -0x7fffbffb;
                }
                if (rd_i32(static_cast<uint32_t>(iVar1) + 0x10) == 0) {
                    return -0x7fffbffb;
                }
                iVar1 = FUN_0062a866(self, rd_i32(static_cast<uint32_t>(iVar1) + 0x10), param_3, param_4, param_5, param_6, param_7, param_8);
                if (iVar1 < 0) {
                    return iVar1;
                }
                iVar4 = *param_3;
                if (((((iVar4 != 3) && (iVar4 != 2)) && (iVar4 != 1)) ||
                     ((*param_5 != 1 || (*param_4 != 1)))) || ((*param_6 != 0 || (*param_7 != 0)))) break;
                param_1 = rd_i32(static_cast<uint32_t>(param_1) + 0xc);
                iVar2 = iVar2 + 1;
                if (param_1 == 0) {
                    if ((param_2[1] == 3) || (param_2[1] == 0xf20000)) {
                        iVar4 = 3;
                    }
                    else {
                        iVar4 = 2;
                    }
                    *param_3 = iVar4;
                    *param_4 = iVar2;
                    *param_5 = 1;
                    *param_6 = 0;
                    *param_7 = 0;
                    *param_8 = iVar2 * 4;
                    return iVar1;
                }
            }
            pcVar3 = "ID3DXEffectCompiler: Initializers must be numeric scalars";
            goto LAB_0062c0be;
        }
    }
    else if (rd_i32(static_cast<uint32_t>(param_1) + 4) == 0xd) {
        iVar2 = FUN_0062a866(self, rd_i32(static_cast<uint32_t>(param_1) + 0x10), param_3, param_4, param_5, param_6, param_7, param_8);
        if (iVar2 < 0) {
            return iVar2;
        }
        if (*param_3 != 0) {
            return iVar2;
        }
        pcVar3 = "ID3DXEffectCompiler: Assignment cannot be a structure";
LAB_0062c0be:
        FUN_0060fcd3(self_base + 0x28, param_9, 0, pcVar3);
        return -0x7fffbffb;
    }
    FUN_0060fcd3(self_base + 0x28, param_9, 0,
                 "ID3DXEffectCompiler: State '%s' was assigned an unsupported value", *param_2);
    return -0x7fffbffb;
}

// 0x62c211 — observed shape
uint32_t FUN_0062c211(void* self, int32_t* param_1, int32_t param_2, int32_t param_3, int32_t param_4, int32_t param_5, int32_t param_6, uint32_t param_7) {
    int32_t iVar1;
    uint32_t uVar2;
    bool bVar3;
    const char* pcVar4;
    uint32_t uVar5;
    uint8_t* self_base = static_cast<uint8_t*>(self);

    iVar1 = param_1[1];
    if (10 < iVar1) {
        if (iVar1 < 0xf) goto LAB_0062c4e5;
        if (iVar1 < 0x11) {
            if ((param_5 == 0) && (param_6 == 0)) {
                if ((iVar1 == param_2) && ((param_3 == 1 && (param_4 == 1)))) {
                    return 0;
                }
                if (((param_2 == 2) && (param_3 == 1)) && (param_4 == 1)) {
                    return 0;
                }
                uVar5 = static_cast<uint32_t>(*param_1);
                pcVar4 = "ID3DXEffectCompiler: State '%s' was assigned an incompatible type";
                goto LAB_0062c4ed;
            }
        }
        else {
            if (iVar1 == 0xf20000) {
                if (param_2 == 3) {
                    if (param_3 != 4) {
LAB_0062c490:
                        if (param_3 != 1) goto LAB_0062c49a;
                    }
                    if (param_4 == 1) {
                        return 0;
                    }
                }
                else if ((param_2 == 2) || (param_2 == 1)) goto LAB_0062c490;
LAB_0062c49a:
                uVar5 = static_cast<uint32_t>(*param_1);
                pcVar4 = "ID3DXEffectCompiler: State '%s' must be assigned a numeric scalar or a 4-float vector";
                goto LAB_0062c4ed;
            }
            if (iVar1 != 0xf30000) goto LAB_0062c4e5;
            if ((param_5 == 0) && (param_6 == 0)) {
                if ((param_3 == 1) && (param_4 == 1)) {
                    if (param_2 == 0xf30000) {
                        return 0;
                    }
                    if (param_2 == 2) {
                        return 0;
                    }
                }
                uVar5 = static_cast<uint32_t>(*param_1);
                pcVar4 = "ID3DXEffectCompiler: State '%s' was not assigned a stateblock type";
                goto LAB_0062c4ed;
            }
        }
LAB_0062c4da:
        uVar5 = static_cast<uint32_t>(*param_1);
        pcVar4 = "ID3DXEffectCompiler: State '%s' cannot be assigned an array or structure";
        goto LAB_0062c4ed;
    }
    if (iVar1 == 10) {
        if ((param_5 == 0) && (param_6 == 0)) {
            if ((param_3 == 1) && (param_4 == 1)) {
                if (param_2 == 10) {
                    return 0;
                }
                if (param_2 == 0xb) {
                    return 0;
                }
                if (param_2 == 0xc) {
                    return 0;
                }
                if (param_2 == 0xd) {
                    return 0;
                }
                if (param_2 == 0xe) {
                    return 0;
                }
                if (param_2 == 2) {
                    return 0;
                }
            }
            uVar5 = static_cast<uint32_t>(*param_1);
            pcVar4 = "ID3DXEffectCompiler: State '%s' was not assigned a sampler type";
            goto LAB_0062c4ed;
        }
        goto LAB_0062c4da;
    }
    if (iVar1 < 1) {
LAB_0062c4e5:
        uVar5 = static_cast<uint32_t>(*param_1);
        pcVar4 = "ID3DXEffectCompiler: Unexpected value type of state '%s' (internal error)";
        goto LAB_0062c4ed;
    }
    if (iVar1 < 3) goto LAB_0062c37c;
    if (iVar1 != 3) {
        if (iVar1 == 5) {
            if ((param_5 == 0) && (param_6 == 0)) {
                if ((param_3 == 1) && (param_4 == 1)) {
                    if (param_2 == 5) {
                        return 0;
                    }
                    if (param_2 == 6) {
                        return 0;
                    }
                    if (param_2 == 7) {
                        return 0;
                    }
                    if (param_2 == 8) {
                        return 0;
                    }
                    if (param_2 == 9) {
                        return 0;
                    }
                    if (param_2 == 2) {
                        return 0;
                    }
                }
                uVar5 = static_cast<uint32_t>(*param_1);
                pcVar4 = "ID3DXEffectCompiler: State '%s' was not assigned a texture type";
            }
            else {
                uVar5 = static_cast<uint32_t>(*param_1);
                pcVar4 = "ID3DXEffectCompiler: State '%s' cannot be assigned an array or structure";
            }
            goto LAB_0062c4ed;
        }
        goto LAB_0062c4e5;
    }
    uVar2 = static_cast<uint32_t>(param_1[5]);
    if (uVar2 < 0xd000005) {
        if (uVar2 < 0xd000000) {
            if (uVar2 < 0xc000000) goto LAB_0062c30e;
            if ((0xc000004 < uVar2) && (uVar2 != 0xc010000)) {
                bVar3 = uVar2 == 0xc020000;
                goto LAB_0062c30c;
            }
        }
LAB_0062c37c:
        if (param_6 != 0) {
            return 0;
        }
    }
    else {
        if (uVar2 == 0xd010000) goto LAB_0062c37c;
        bVar3 = uVar2 == 0xd020000;
LAB_0062c30c:
        if (bVar3) goto LAB_0062c37c;
LAB_0062c30e:
        if (param_1[2] != 1) goto LAB_0062c37c;
        uVar2 = static_cast<uint32_t>(param_1[3]);
        if (uVar2 != 1) {
            if ((2 < uVar2) && (uVar2 < 5)) {
                if ((param_4 == 1) &&
                    ((((param_3 == 3 || (param_3 == 4)) && (param_5 == 0)) && (param_6 == 0))))
                    goto LAB_0062c386;
                if (((param_2 != 2) || (param_3 != 1)) || (param_4 != 1)) {
                    uVar5 = static_cast<uint32_t>(*param_1);
                    pcVar4 = "ID3DXEffectCompiler: State '%s' must be assigned a 3-vector or a 4-vector or a uint scalar";
                    goto LAB_0062c4ed;
                }
            }
            goto LAB_0062c37c;
        }
        if (((param_3 != 1) || (param_4 != 1)) || ((param_5 != 0 || (param_6 != 0)))) {
            uVar5 = static_cast<uint32_t>(*param_1);
            pcVar4 = "ID3DXEffectCompiler: State '%s' must be assigned a scalar";
            goto LAB_0062c4ed;
        }
    }
LAB_0062c386:
    if (param_2 == 3) {
        return 0;
    }
    if (param_2 == 2) {
        return 0;
    }
    if (param_2 == 1) {
        return 0;
    }
    uVar5 = static_cast<uint32_t>(*param_1);
    pcVar4 = "ID3DXEffectCompiler: State '%s' must be assigned a numeric value";
LAB_0062c4ed:
    FUN_0060fcd3(self_base + 0x28, param_7, 0, pcVar4, uVar5);
    return 0x80004005;
}

// 0x62c50d — observed shape
uint32_t FUN_0062c50d(void* self, uint8_t* param_1) {
    uint8_t bVar1;
    uint32_t uVar2;
    uint8_t* pbVar3;
    int32_t iVar4;
    int32_t* piVar5;
    uint8_t* pbVar6;
    bool bVar7;
    uint8_t* self_base = static_cast<uint8_t*>(self);

    if (reinterpret_cast<uint8_t*>(reinterpret_cast<uintptr_t>(param_1) & 0x7fffffff) == param_1) {
        for (uVar2 = *reinterpret_cast<uint32_t*>(self_base + 0x34c); uVar2 != 0; uVar2 = *reinterpret_cast<uint32_t*>(static_cast<intptr_t>(uVar2) + 0x34)) {
            if (param_1 == nullptr) {
                iVar4 = *reinterpret_cast<int32_t*>(static_cast<intptr_t>(uVar2) + 0x20);
LAB_0062c58d:
                if (iVar4 == 0) {
                    return uVar2;
                }
            }
            else {
                pbVar6 = *reinterpret_cast<uint8_t**>(static_cast<intptr_t>(uVar2) + 0x20);
                if (pbVar6 != nullptr) {
                    pbVar3 = param_1;
                    do {
                        bVar1 = *pbVar3;
                        bVar7 = bVar1 < *pbVar6;
                        if (bVar1 != *pbVar6) {
LAB_0062c586:
                            iVar4 = (1 - static_cast<int32_t>(bVar7)) - static_cast<int32_t>(bVar7 != 0);
                            goto LAB_0062c58d;
                        }
                        if (bVar1 == 0) break;
                        bVar1 = pbVar3[1];
                        bVar7 = bVar1 < pbVar6[1];
                        if (bVar1 != pbVar6[1]) goto LAB_0062c586;
                        pbVar3 = pbVar3 + 2;
                        pbVar6 = pbVar6 + 2;
                    } while (bVar1 != 0);
                    iVar4 = 0;
                    goto LAB_0062c58d;
                }
            }
        }
        uVar2 = 0;
    }
    else {
        piVar5 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(~reinterpret_cast<uintptr_t>(param_1)));
        if (((*piVar5 == 3) && (piVar5[6] == 0)) && (piVar5[4] == -1)) {
            uVar2 = static_cast<uint32_t>(-static_cast<uint32_t>(*reinterpret_cast<int32_t*>(static_cast<intptr_t>(piVar5[1]) + 0x44) != 0) & static_cast<uint32_t>(reinterpret_cast<uintptr_t>(piVar5)));
        }
        else {
            uVar2 = 0;
        }
    }
    return uVar2;
}

// 0x62c5a3 — observed shape
int32_t FUN_0062c5a3(void* self, uint8_t* param_1) {
    uint8_t bVar1;
    int32_t iVar2;
    int32_t iVar3;
    uint8_t* pbVar4;
    uint8_t* pbVar5;
    bool bVar6;
    uint8_t* self_base = static_cast<uint8_t*>(self);

    if (reinterpret_cast<uint8_t*>(reinterpret_cast<uintptr_t>(param_1) & 0x7fffffff) == param_1) {
        for (iVar2 = *reinterpret_cast<int32_t*>(self_base + 0x350); iVar2 != 0; iVar2 = *reinterpret_cast<int32_t*>(static_cast<intptr_t>(iVar2) + 0x28)) {
            if (param_1 == nullptr) {
                iVar3 = *reinterpret_cast<int32_t*>(static_cast<intptr_t>(iVar2) + 0x20);
LAB_0062c60e:
                if (iVar3 == 0) {
                    return iVar2;
                }
            }
            else {
                pbVar5 = *reinterpret_cast<uint8_t**>(static_cast<intptr_t>(iVar2) + 0x20);
                if (pbVar5 != nullptr) {
                    pbVar4 = param_1;
                    do {
                        bVar1 = *pbVar4;
                        bVar6 = bVar1 < *pbVar5;
                        if (bVar1 != *pbVar5) {
LAB_0062c607:
                            iVar3 = (1 - static_cast<int32_t>(bVar6)) - static_cast<int32_t>(bVar6 != 0);
                            goto LAB_0062c60e;
                        }
                        if (bVar1 == 0) break;
                        bVar1 = pbVar4[1];
                        bVar6 = bVar1 < pbVar5[1];
                        if (bVar1 != pbVar5[1]) goto LAB_0062c607;
                        pbVar4 = pbVar4 + 2;
                        pbVar5 = pbVar5 + 2;
                    } while (bVar1 != 0);
                    iVar3 = 0;
                    goto LAB_0062c60e;
                }
            }
        }
        iVar2 = 0;
    }
    else if (*reinterpret_cast<int32_t*>(static_cast<intptr_t>(~reinterpret_cast<uintptr_t>(param_1))) == 2) {
        iVar2 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(~reinterpret_cast<uintptr_t>(param_1)))[1];
    }
    else {
        iVar2 = 0;
    }
    return iVar2;
}
