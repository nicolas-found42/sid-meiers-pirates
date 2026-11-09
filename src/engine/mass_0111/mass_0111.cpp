// Reconstruction batch mass_0111 — Sid Meier's Pirates! (2004)
#include <cstdint>
#include <cstddef>
#include <windows.h>

extern char FUN_005337b0();
extern char FUN_00531940();
extern void FUN_0052b4b0(int param_1, int param_2, int param_3);

// 0x52b370 — observed shape
void FUN_0052b370_recon(uint32_t* param_1, uint32_t* param_2, uint32_t* param_3)
{
    uint32_t tmp;
    if (FUN_005337b0() != 0) {
        tmp = *param_2;
        *param_2 = *param_1;
        *param_1 = tmp;
    }
    if (FUN_005337b0() != 0) {
        tmp = *param_3;
        *param_3 = *param_2;
        *param_2 = tmp;
    }
    if (FUN_005337b0() != 0) {
        tmp = *param_2;
        *param_2 = *param_1;
        *param_1 = tmp;
    }
}

// 0x52b3d0 — observed shape
void FUN_0052b3d0_recon(int param_1, int param_2, int param_3, uint32_t param_4, uint32_t param_5)
{
    int iVar2 = param_2;
    int iVar3;
    for (;;) {
        iVar3 = iVar2 * 2 + 2;
        if (param_3 <= iVar3) break;
        if (FUN_005337b0() != 0) {
            iVar3 = iVar2 * 2 + 1;
        }
        *(uint32_t*)(param_1 + iVar2 * 4) = *(uint32_t*)(param_1 + iVar3 * 4);
        iVar2 = iVar3;
    }
    if (iVar3 == param_3) {
        *(uint32_t*)(param_1 + iVar2 * 4) = *(uint32_t*)(param_1 + -4 + param_3 * 4);
        iVar2 = param_3 + -1;
    }
    FUN_0052b4b0(param_1, iVar2, param_2, param_5);
}

// 0x52b450 — observed shape
void FUN_0052b450_recon(int param_1, int param_2, int param_3, uint32_t in_EAX)
{
    if (param_3 < param_2) {
        do {
            int iVar2 = (param_2 + -1) / 2;
            if (FUN_00531940() == 0) break;
            *(uint32_t*)(param_1 + param_2 * 4) = *(uint32_t*)(param_1 + iVar2 * 4);
            param_2 = iVar2;
        } while (param_3 < iVar2);
    }
    *(uint32_t*)(param_1 + param_2 * 4) = in_EAX;
}

// 0x52b4b0 — observed shape
void FUN_0052b4b0_recon(int param_1, int param_2, int param_3, uint32_t in_EAX)
{
    if (param_3 < param_2) {
        do {
            int iVar2 = (param_2 + -1) / 2;
            if (FUN_005337b0() == 0) break;
            *(uint32_t*)(param_1 + param_2 * 4) = *(uint32_t*)(param_1 + iVar2 * 4);
            param_2 = iVar2;
        } while (param_3 < iVar2);
    }
    *(uint32_t*)(param_1 + param_2 * 4) = in_EAX;
}

// 0x52b510 — observed shape
void FUN_0052b510_recon(int param_1, int param_2, uint32_t* param_3)
{
    uint32_t* puVar4 = param_3;
    int iVar9 = ((int)param_3 - param_1) >> 2;
    int iVar11 = (param_2 - param_1) >> 2;
    int iVar7 = iVar11;
    int iVar2;
    param_2 = iVar9;
    while ((iVar2 = iVar7, iVar2 != 0)) {
        iVar7 = param_2 % iVar2;
        param_2 = iVar2;
    }
    if ((param_2 < iVar9) && (0 < param_2)) {
        uint32_t* puVar10 = (uint32_t*)(param_1 + param_2 * 4);
        do {
            uint32_t uVar1 = *puVar10;
            uint32_t** ppuVar8;
            uint32_t* local_c;
            uint32_t* local_8[2];
            uint32_t* puVar6;
            uint32_t* puVar5;
            if (puVar10 + iVar11 == puVar4) {
                puVar6 = (uint32_t*)&param_1;
            } else {
                param_3 = puVar10 + iVar11;
                puVar6 = (uint32_t*)&param_3;
            }
            puVar5 = *(uint32_t**)puVar6;
            puVar6 = puVar10;
            while (puVar5 != puVar10) {
                uint32_t* puVar3 = puVar5;
                *puVar6 = *puVar3;
                int iVar7b = ((int)puVar4 - (int)puVar3) >> 2;
                if (iVar11 < iVar7b) {
                    local_c = puVar3 + iVar11;
                    ppuVar8 = (uint32_t**)&local_c;
                } else {
                    local_8[0] = (uint32_t*)(param_1 + (iVar7b * 0x3fffffff + iVar11) * 4);
                    ppuVar8 = (uint32_t**)local_8;
                }
                puVar6 = puVar3;
                puVar5 = *ppuVar8;
            }
            puVar10 = puVar10 + -1;
            param_2 = param_2 + -1;
            *puVar6 = uVar1;
        } while (param_2 != 0);
    }
}

// ---- retry batch: remaining function reconstructions ----

extern void FUN_0052a720();
extern uint32_t FUN_00533c78(uint32_t size);
extern uint32_t FUN_00531a30();
extern void FUN_0052c690(void* self, uint32_t end, void** value);
extern void FUN_0052ccf0();
extern void operator_delete__(void* p);
extern void operator_delete(void* p);
extern void FUN_00412cb0();
extern void FUN_004129c0(void** a, int32_t* b);
extern void FUN_004b1130(void* a, void* b);
extern void* PTR_LAB_00712f28;
extern void* PTR_LAB_00713280;
extern uint8_t DAT_008cacc8;
extern uint8_t DAT_008cacd0;

uint32_t FUN_0052b640_recon(void* self, uint32_t count);
uint32_t FUN_0052b850_recon(void* self, uint32_t count);
uint32_t FUN_0052ba00_recon(void* self, uint32_t count);
void FUN_0052bc70_recon(void* self);
void FUN_0052bd90_recon(void* self);
void FUN_0052bea0_recon(void* self);

// 0x52b5d0 — observed shape
void FUN_0052b5d0_recon(void* self_ptr)
{
    uint8_t* self = (uint8_t*)self_ptr;
    int32_t iVar1;

    if ((*(int32_t*)(self + 0x14) == 0) ||
        ((*(int32_t*)(self + 0x18) - *(int32_t*)(self + 0x14)) >> 2 == 0)) {
        if (*(int32_t*)(self + 4) == 0) {
            iVar1 = 0;
        } else {
            iVar1 = (*(int32_t*)(self + 8) - *(int32_t*)(self + 4)) >> 2;
        }
        // receiver register (EDI) is not materialized in the listing; it is this object
        FUN_0052b640_recon(self, (uint32_t)(iVar1 * 2 + 1));
    }
    iVar1 = *(int32_t*)(*(int32_t*)(self + 0x18) - 4);
    if ((*(int32_t*)(self + 0x14) != 0) &&
        ((*(int32_t*)(self + 0x18) - *(int32_t*)(self + 0x14)) >> 2 != 0)) {
        *(int32_t*)(self + 0x18) = *(int32_t*)(self + 0x18) - 4;
    }
    *(int32_t*)(*(int32_t*)(*(int32_t*)(self + 4) + iVar1 * 4) + 4) = iVar1;
}

// 0x52b640 — observed shape
uint32_t FUN_0052b640_recon(void* self_ptr, uint32_t count)
{
    uint8_t* self = (uint8_t*)self_ptr;
    int32_t iVar1;
    uint32_t* puVar1;
    uint32_t uVar2;
    uint32_t uVar4;
    uint32_t local_c = 0;
    uint32_t local_8;
    uint32_t* local_4;

    FUN_0052a720();
    FUN_0052a720();
    if (*(int32_t*)(self + 4) == 0) {
        local_8 = 0;
    } else {
        local_8 = (uint32_t)((*(int32_t*)(self + 8) - *(int32_t*)(self + 4)) >> 2);
    }
    if (count != 0) {
        do {
            local_4 = (uint32_t*)FUN_00533c78(0x124);
            if (local_4 == (uint32_t*)0) {
                return 0;
            }
            *(void**)local_4 = &PTR_LAB_00712f28;
            local_4[0x43] = 0xffffffff;
            local_4[0x44] = 0;
            *(uint8_t*)(local_4 + 0x45) = 0;
            local_4[0x46] = 0xffffffff;
            local_4[0x42] = 0;
            uVar4 = 0;
            do {
                local_4[uVar4 + 2] = 0;
                local_4[uVar4 + 0x22] = 0;
                uVar4 = uVar4 + 1;
            } while (uVar4 < 0x20);
            local_4[0x43] = 0xffffffff;
            local_4[0x44] = 0;
            *(uint8_t*)(local_4 + 0x45) = 0;
            local_4[0x46] = 0xffffffff;
            local_4[0x42] = 0;
            uVar4 = 0;
            do {
                local_4[uVar4 + 2] = 0;
                local_4[uVar4 + 0x22] = 0;
                uVar4 = uVar4 + 1;
            } while (uVar4 < 0x20);
            *(uint8_t*)(local_4 + 0x47) = 0;
            local_4[1] = 0xffffffff;
            iVar1 = *(int32_t*)(self + 4);
            if ((iVar1 == 0) ||
                ((uint32_t)((*(int32_t*)(self + 0xc) - iVar1) >> 2) <=
                 (uint32_t)((*(int32_t*)(self + 8) - iVar1) >> 2))) {
                FUN_0052c690(self, *(uint32_t*)(self + 8), (void**)&local_4);
            } else {
                puVar1 = (uint32_t*)*(uint32_t*)(self + 8);
                *puVar1 = (uint32_t)local_4;
                *(uint32_t*)(self + 8) = (uint32_t)(puVar1 + 1);
            }
            iVar1 = *(int32_t*)(self + 0x14);
            uVar2 = local_8;
            if ((iVar1 == 0) ||
                ((uint32_t)((*(int32_t*)(self + 0x1c) - iVar1) >> 2) <=
                 (uint32_t)((*(int32_t*)(self + 0x18) - iVar1) >> 2))) {
                FUN_0052c690(self + 0x10, *(uint32_t*)(self + 0x18), (void**)&uVar2);
            } else {
                puVar1 = (uint32_t*)*(uint32_t*)(self + 0x18);
                *puVar1 = uVar2;
                *(uint32_t*)(self + 0x18) = (uint32_t)(puVar1 + 1);
            }
            local_8 = local_8 + 1;
            local_c = local_c + 1;
        } while (local_c < count);
    }
    return 1;
}

// 0x52b7e0 — observed shape
void FUN_0052b7e0_recon(void* self_ptr)
{
    uint8_t* self = (uint8_t*)self_ptr;
    int32_t iVar1;

    if ((*(int32_t*)(self + 0x14) == 0) ||
        ((*(int32_t*)(self + 0x18) - *(int32_t*)(self + 0x14)) >> 2 == 0)) {
        if (*(int32_t*)(self + 4) == 0) {
            iVar1 = 0;
        } else {
            iVar1 = (*(int32_t*)(self + 8) - *(int32_t*)(self + 4)) >> 2;
        }
        FUN_0052b850_recon(self, (uint32_t)(iVar1 * 2 + 1));
    }
    iVar1 = *(int32_t*)(*(int32_t*)(self + 0x18) - 4);
    if ((*(int32_t*)(self + 0x14) != 0) &&
        ((*(int32_t*)(self + 0x18) - *(int32_t*)(self + 0x14)) >> 2 != 0)) {
        *(int32_t*)(self + 0x18) = *(int32_t*)(self + 0x18) - 4;
    }
    *(int32_t*)(*(int32_t*)(*(int32_t*)(self + 4) + iVar1 * 4) + 4) = iVar1;
}

// 0x52b850 — observed shape
uint32_t FUN_0052b850_recon(void* self_ptr, uint32_t count)
{
    uint8_t* self = (uint8_t*)self_ptr;
    uint32_t* puVar1;
    uint32_t uVar2;
    int32_t iVar3;
    uint32_t local_4;
    uint32_t local_8;
    uint32_t local_c = 0;

    FUN_0052a720();
    FUN_0052a720();
    if (*(int32_t*)(self + 4) == 0) {
        uVar2 = 0;
    } else {
        uVar2 = (uint32_t)((*(int32_t*)(self + 8) - *(int32_t*)(self + 4)) >> 2);
    }
    if (count != 0) {
        local_8 = uVar2;
        do {
            iVar3 = (int32_t)FUN_00533c78(0xcc);
            if (iVar3 == 0) {
                return 0;
            }
            local_4 = FUN_00531a30();
            if (local_4 == 0) {
                return 0;
            }
            *(uint32_t*)(local_4 + 4) = 0xffffffff;
            iVar3 = *(int32_t*)(self + 4);
            if ((iVar3 == 0) ||
                ((uint32_t)((*(int32_t*)(self + 0xc) - iVar3) >> 2) <=
                 (uint32_t)((*(int32_t*)(self + 8) - iVar3) >> 2))) {
                FUN_0052c690(self, *(uint32_t*)(self + 8), (void**)&local_4);
            } else {
                puVar1 = (uint32_t*)*(uint32_t*)(self + 8);
                *puVar1 = local_4;
                *(uint32_t*)(self + 8) = (uint32_t)(puVar1 + 1);
            }
            iVar3 = *(int32_t*)(self + 0x14);
            local_4 = local_8;
            if ((iVar3 == 0) ||
                ((uint32_t)((*(int32_t*)(self + 0x1c) - iVar3) >> 2) <=
                 (uint32_t)((*(int32_t*)(self + 0x18) - iVar3) >> 2))) {
                FUN_0052c690(self + 0x10, *(uint32_t*)(self + 0x18), (void**)&local_4);
            } else {
                puVar1 = (uint32_t*)*(uint32_t*)(self + 0x18);
                *puVar1 = local_8;
                *(uint32_t*)(self + 0x18) = (uint32_t)(puVar1 + 1);
            }
            uVar2 = local_c + 1;
            local_8 = local_8 + 1;
            local_c = uVar2;
        } while (uVar2 < count);
    }
    return 1;
}

// 0x52b990 — observed shape
void FUN_0052b990_recon(void* self_ptr)
{
    uint8_t* self = (uint8_t*)self_ptr;
    int32_t iVar1;

    if ((*(int32_t*)(self + 0x14) == 0) ||
        ((*(int32_t*)(self + 0x18) - *(int32_t*)(self + 0x14)) >> 2 == 0)) {
        if (*(int32_t*)(self + 4) == 0) {
            iVar1 = 0;
        } else {
            iVar1 = (*(int32_t*)(self + 8) - *(int32_t*)(self + 4)) >> 2;
        }
        FUN_0052ba00_recon(self, (uint32_t)(iVar1 * 2 + 1));
    }
    iVar1 = *(int32_t*)(*(int32_t*)(self + 0x18) - 4);
    if ((*(int32_t*)(self + 0x14) != 0) &&
        ((*(int32_t*)(self + 0x18) - *(int32_t*)(self + 0x14)) >> 2 != 0)) {
        *(int32_t*)(self + 0x18) = *(int32_t*)(self + 0x18) - 4;
    }
    *(int32_t*)(*(int32_t*)(*(int32_t*)(self + 4) + iVar1 * 4) + 4) = iVar1;
}

// 0x52ba00 — observed shape
uint32_t FUN_0052ba00_recon(void* self_ptr, uint32_t count)
{
    uint8_t* self = (uint8_t*)self_ptr;
    int32_t iVar1;
    uint32_t* puVar1;
    uint32_t uVar2;
    uint32_t local_c = 0;
    uint32_t local_8;
    uint32_t* local_4;

    FUN_0052a720();
    FUN_0052a720();
    if (*(int32_t*)(self + 4) == 0) {
        local_8 = 0;
    } else {
        local_8 = (uint32_t)((*(int32_t*)(self + 8) - *(int32_t*)(self + 4)) >> 2);
    }
    if (count != 0) {
        do {
            local_4 = (uint32_t*)FUN_00533c78(0x80);
            if (local_4 == (uint32_t*)0) {
                return 0;
            }
            *(void**)local_4 = &PTR_LAB_00713280;
            local_4[0xe] = 0;
            local_4[0xf] = 0;
            local_4[0x10] = 0;
            local_4[0x11] = 0;
            local_4[0x12] = 0;
            local_4[0x13] = 0;
            local_4[0x14] = 0;
            local_4[0x15] = 0;
            local_4[0xb] = 0;
            local_4[0xc] = 0;
            local_4[9] = 0x3f800000;
            local_4[0xd] = 0x3f800000;
            local_4[10] = 0x3f000000;
            local_4[0xe] = 0;
            local_4[0xf] = 0;
            local_4[0x10] = 0;
            local_4[0x11] = 0;
            local_4[0x12] = 0;
            local_4[0x13] = 0;
            local_4[0x14] = 0;
            local_4[0x15] = 0;
            local_4[5] = 0xffffffff;
            *(uint8_t*)(local_4 + 6) = 0;
            local_4[7] = 0;
            local_4[8] = 0;
            local_4[9] = 0x3f800000;
            local_4[10] = 0x3f000000;
            local_4[0xb] = 0;
            local_4[0xc] = 0;
            local_4[0xd] = 0x3f800000;
            local_4[0xe] = 0;
            local_4[0xf] = 0;
            local_4[0x10] = 0;
            local_4[0x11] = 0;
            local_4[0x12] = 0;
            local_4[0x13] = 0;
            local_4[0x14] = 0;
            local_4[0x15] = 0;
            *(uint8_t*)(local_4 + 0x16) = 0;
            *(uint8_t*)((uint8_t*)local_4 + 0x59) = 0;
            local_4[0x17] = 0;
            local_4[0x18] = 0;
            local_4[0x19] = 0;
            local_4[0x1a] = 0;
            local_4[0x1b] = 0;
            local_4[0x1c] = 0xffffffff;
            *(uint8_t*)(local_4 + 0x1d) = 0;
            *(uint8_t*)(local_4 + 0x1e) = 0;
            local_4[2] = 0;
            local_4[3] = 0xffffffff;
            local_4[4] = 0xffffffff;
            local_4[5] = 0xffffffff;
            *(uint8_t*)(local_4 + 6) = 0;
            local_4[7] = 0;
            local_4[8] = 0;
            local_4[9] = 0x3f800000;
            local_4[10] = 0x3f000000;
            local_4[0xb] = 0;
            local_4[0xc] = 0;
            local_4[0xd] = 0x3f800000;
            local_4[0xe] = 0;
            local_4[0xf] = 0;
            local_4[0x10] = 0;
            local_4[0x11] = 0;
            local_4[0x12] = 0;
            local_4[0x13] = 0;
            local_4[0x14] = 0;
            local_4[0x15] = 0;
            *(uint8_t*)(local_4 + 0x16) = 0;
            *(uint8_t*)((uint8_t*)local_4 + 0x59) = 0;
            local_4[0x17] = 0;
            local_4[0x18] = 0;
            local_4[0x19] = 0;
            local_4[0x1a] = 0;
            local_4[0x1b] = 0;
            local_4[0x1c] = 0xffffffff;
            *(uint8_t*)(local_4 + 0x1d) = 0;
            *(uint8_t*)((uint8_t*)local_4 + 0x7b) = 0;
            *(uint8_t*)((uint8_t*)local_4 + 0x7a) = 0;
            local_4[0x1f] = 0;
            *(uint8_t*)((uint8_t*)local_4 + 0x79) = 0;
            local_4[1] = 0xffffffff;
            iVar1 = *(int32_t*)(self + 4);
            if ((iVar1 == 0) ||
                ((uint32_t)((*(int32_t*)(self + 0xc) - iVar1) >> 2) <=
                 (uint32_t)((*(int32_t*)(self + 8) - iVar1) >> 2))) {
                FUN_0052c690(self, *(uint32_t*)(self + 8), (void**)&local_4);
            } else {
                puVar1 = (uint32_t*)*(uint32_t*)(self + 8);
                *puVar1 = (uint32_t)local_4;
                *(uint32_t*)(self + 8) = (uint32_t)(puVar1 + 1);
            }
            iVar1 = *(int32_t*)(self + 0x14);
            uVar2 = local_8;
            if ((iVar1 == 0) ||
                ((uint32_t)((*(int32_t*)(self + 0x1c) - iVar1) >> 2) <=
                 (uint32_t)((*(int32_t*)(self + 0x18) - iVar1) >> 2))) {
                FUN_0052c690(self + 0x10, *(uint32_t*)(self + 0x18), (void**)&uVar2);
            } else {
                puVar1 = (uint32_t*)*(uint32_t*)(self + 0x18);
                *puVar1 = uVar2;
                *(uint32_t*)(self + 0x18) = (uint32_t)(puVar1 + 1);
            }
            local_8 = local_8 + 1;
            local_c = local_c + 1;
        } while (local_c < count);
    }
    return 1;
}

// 0x52bc30 — observed shape
void FUN_0052bc30_recon(void* self_ptr)
{
    uint8_t* self = (uint8_t*)self_ptr;

    *(uint32_t*)(self + 0x74) = 0;
    *(uint32_t*)(self + 0x78) = 0;
    *(uint32_t*)(self + 0x7c) = 0;
    *(uint32_t*)(self + 0x80) = 0;
    *(uint32_t*)(self + 0x84) = 0;
    *(uint32_t*)(self + 0x88) = 0;
    *(uint32_t*)(self + 0x8c) = 0;
    *(uint32_t*)(self + 0x90) = 0;
    FUN_0052bc70_recon(self);
    *(uint32_t*)(self + 0x98) = 0;
    FUN_0052bd90_recon(self);
}

// 0x52bc70 — observed shape
void FUN_0052bc70_recon(void* self_ptr)
{
    uint32_t* self = (uint32_t*)self_ptr;

    self[0] = 0;
    self[1] = 0;
    self[2] = 0;
    self[3] = 0;
    self[4] = 0;
    self[5] = 0;
    self[10] = 0;
    self[0xb] = 0;
    self[0xc] = 0x3f800000;
    self[0xd] = 0;
    self[0xe] = 0x3f800000;
    self[0xf] = 0;
    self[6] = 0xbf800000;
    self[7] = 0xbf800000;
    self[8] = 0xbf800000;
    self[9] = 0;
    self[0x10] = 0x168;
    self[0x11] = 0x168;
    self[0x14] = 0x447a0000;
    self[0x16] = 0;
    self[0x17] = 0;
    self[0x12] = 0x3f800000;
    self[0x13] = 0x3f800000;
    self[0x15] = 0x3f800000;
    self[0x18] = 0x3f800000;
    self[0x19] = 0;
    self[0x1a] = 0;
    self[0x1b] = 0;
    self[0x1c] = 0;
    self[0x1d] = 0;
    self[0x1e] = 0;
    self[0x1f] = 0;
    self[0x20] = 0;
}

// 0x52bd90 — observed shape
void FUN_0052bd90_recon(void* self_ptr)
{
    uint32_t* self = (uint32_t*)self_ptr;
    uint32_t* puVar1;
    uint32_t* puVar2;

    self[0] = 0xffffffff;
    *(uint8_t*)(self + 1) = 0;
    self[2] = 0;
    self[3] = 0;
    FUN_0052bc70_recon(self);
    *(uint8_t*)(self + 0x25) = 0;
    *(uint8_t*)((uint8_t*)self + 0x95) = 0;
    puVar2 = (uint32_t*)self[0x26];
    if (puVar2 != (uint32_t*)0) {
        puVar1 = puVar2 + 1;
        *puVar1 = *puVar1 - 1;
        if (*puVar1 == 0) {
            // thiscall-style virtual dispatch: receiver of the virtual call is puVar2 (register)
            (*(void (**)(int))*puVar2)(1);
        }
        self[0x26] = 0;
    }
    self[0x27] = 0;
    self[0x28] = 0;
    self[0x29] = 0;
    self[0x2a] = 0;
    self[0x2b] = 0;
}

// 0x52be00 — observed shape
void FUN_0052be00_recon(void* self_ptr)
{
    uint8_t* self = (uint8_t*)self_ptr;
    uint32_t uVar1;

    *(uint32_t*)(self + 0x104) = 0xffffffff;
    *(uint32_t*)(self + 0x110) = 0xffffffff;
    *(uint32_t*)(self + 0x108) = 0;
    *(uint8_t*)(self + 0x10c) = 0;
    *(uint32_t*)(self + 0x100) = 0;
    uVar1 = 0;
    do {
        *(uint32_t*)(self + uVar1 * 4) = 0;
        *(uint32_t*)(self + 0x80 + uVar1 * 4) = 0;
        uVar1 = uVar1 + 1;
    } while (uVar1 < 0x20);
}

// 0x52be40 — observed shape
void FUN_0052be40_recon(void* self_ptr)
{
    uint8_t* self = (uint8_t*)self_ptr;

    *(uint32_t*)(self + 0x24) = 0;
    *(uint32_t*)(self + 0x28) = 0;
    *(uint32_t*)(self + 0x2c) = 0;
    *(uint32_t*)(self + 0x30) = 0;
    *(uint32_t*)(self + 0x34) = 0;
    *(uint32_t*)(self + 0x38) = 0;
    *(uint32_t*)(self + 0x3c) = 0;
    *(uint32_t*)(self + 0x40) = 0;
    *(uint32_t*)(self + 0x18) = 0;
    *(uint32_t*)(self + 0x1c) = 0;
    *(uint32_t*)(self + 0x14) = 0x3f000000;
    *(uint32_t*)(self + 0x10) = 0x3f800000;
    *(uint32_t*)(self + 0x20) = 0x3f800000;
    *(uint32_t*)(self + 0x24) = 0;
    *(uint32_t*)(self + 0x28) = 0;
    *(uint32_t*)(self + 0x2c) = 0;
    *(uint32_t*)(self + 0x30) = 0;
    *(uint32_t*)(self + 0x34) = 0;
    *(uint32_t*)(self + 0x38) = 0;
    *(uint32_t*)(self + 0x3c) = 0;
    *(uint32_t*)(self + 0x40) = 0;
    // callee receiver arrives in EAX; listing does not materialize the pass-through argument
    FUN_0052bea0_recon(self);
}

// 0x52bea0 — observed shape
void FUN_0052bea0_recon(void* self_ptr)
{
    uint32_t* self = (uint32_t*)self_ptr;

    self[0] = 0xffffffff;
    *(uint8_t*)(self + 1) = 0;
    self[2] = 0;
    self[3] = 0;
    self[5] = 0x3f000000;
    self[6] = 0;
    self[7] = 0;
    self[4] = 0x3f800000;
    self[8] = 0x3f800000;
    self[9] = 0;
    self[10] = 0;
    self[0xb] = 0;
    self[0xc] = 0;
    self[0xd] = 0;
    self[0xe] = 0;
    self[0xf] = 0;
    self[0x10] = 0;
    *(uint8_t*)(self + 0x11) = 0;
    *(uint8_t*)((uint8_t*)self + 0x45) = 0;
    self[0x12] = 0;
    self[0x13] = 0;
    self[0x14] = 0;
    self[0x15] = 0;
    self[0x16] = 0;
    self[0x17] = 0xffffffff;
    *(uint8_t*)(self + 0x18) = 0;
}

// 0x52bf10 — observed shape
void FUN_0052bf10_recon(void* self_ptr, void* object_edi)
{
    uint8_t* self = (uint8_t*)self_ptr;
    uint8_t* local_8;
    int32_t local_4;
    void* puVar1;

    FUN_00412cb0();
    FUN_004129c0((void**)&local_8, &local_4);
    FUN_004b1130(object_edi, self + 8);
    puVar1 = (void*)(local_8 - 8);
    if ((puVar1 != (void*)0) && (puVar1 != (void*)&DAT_008cacc8)) {
        operator_delete__(puVar1);
    }
    puVar1 = (void*)(uintptr_t)(local_4 - 8);
    local_8 = &DAT_008cacd0;
    if ((puVar1 != (void*)0) && (puVar1 != (void*)&DAT_008cacc8)) {
        operator_delete__(puVar1);
    }
}

// 0x52bfb0 — observed shape
void FUN_0052bfb0_recon(void* self_ptr)
{
    uint8_t* self = (uint8_t*)self_ptr;
    int32_t iVar1;
    uint32_t* puVar2;
    uint32_t* arr;
    uint32_t uVar3;
    uint32_t uVar4 = 0;

    while (1) {
        iVar1 = *(int32_t*)(self + 4);
        arr = (uint32_t*)(uintptr_t)iVar1;
        if ((arr == (uint32_t*)0) ||
            ((uint32_t)((*(int32_t*)(self + 8) - iVar1) >> 2) <= uVar4)) {
            break;
        }
        puVar2 = (uint32_t*)(uintptr_t)arr[uVar4];
        if (puVar2 != (uint32_t*)0) {
            *(void**)puVar2 = &PTR_LAB_00712f28;
            FUN_0052ccf0();
            puVar2[0x43] = 0xffffffff;
            puVar2[0x46] = 0xffffffff;
            puVar2[0x44] = 0;
            *(uint8_t*)(puVar2 + 0x45) = 0;
            puVar2[0x42] = 0;
            uVar3 = 0;
            do {
                puVar2[uVar3 + 2] = 0;
                puVar2[uVar3 + 0x22] = 0;
                uVar3 = uVar3 + 1;
            } while (uVar3 < 0x20);
            *(uint8_t*)(puVar2 + 0x47) = 0;
            operator_delete(puVar2);
        }
        uVar4 = uVar4 + 1;
    }
    if (*(void**)(self + 4) != (void*)0) {
        operator_delete(*(void**)(self + 4));
    }
    *(uint32_t*)(self + 4) = 0;
    *(uint32_t*)(self + 8) = 0;
    *(uint32_t*)(self + 0xc) = 0;
    if (*(void**)(self + 0x14) != (void*)0) {
        operator_delete(*(void**)(self + 0x14));
    }
    *(uint32_t*)(self + 0x14) = 0;
    *(uint32_t*)(self + 0x18) = 0;
    *(uint32_t*)(self + 0x1c) = 0;
}

// 0x52c060 — observed shape
void FUN_0052c060_recon(void* self_ptr)
{
    uint8_t* self = (uint8_t*)self_ptr;
    int32_t iVar1;
    uint32_t* piVar2;
    uint32_t uVar3;

    for (uVar3 = 0;
         (iVar1 = *(int32_t*)(self + 4), iVar1 != 0 &&
          (uVar3 < (uint32_t)((*(int32_t*)(self + 8) - iVar1) >> 2)));
         uVar3 = uVar3 + 1) {
        piVar2 = (uint32_t*)(uintptr_t)(*(uint32_t*)(iVar1 + uVar3 * 4));
        if (piVar2 != (uint32_t*)0) {
            // virtual call through slot +0x14; receiver of the dispatch is piVar2
            (*(void (**)(int))(*piVar2 + 0x14))(1);
        }
    }
    if (*(void**)(self + 4) != (void*)0) {
        operator_delete(*(void**)(self + 4));
    }
    *(uint32_t*)(self + 4) = 0;
    *(uint32_t*)(self + 8) = 0;
    *(uint32_t*)(self + 0xc) = 0;
    if (*(void**)(self + 0x14) != (void*)0) {
        operator_delete(*(void**)(self + 0x14));
    }
    *(uint32_t*)(self + 0x14) = 0;
    *(uint32_t*)(self + 0x18) = 0;
    *(uint32_t*)(self + 0x1c) = 0;
}
