// Reconstruction batch mass_0348 — Sid Meier's Pirates! (2004), PE32 i386.
// Decompiler-derived candidates (Ghidra 12.2 pseudocode corpus). Unverified.
#include <cstdint>
#include <cstddef>
#include <windows.h>

// --- data labels observed in the listings --------------------------------
extern uint8_t PTR_FUN_006f5218;
extern uint8_t PTR_FUN_006f5210;
extern uint8_t PTR_FUN_006f5284;
extern uint8_t PTR_LAB_006f5288;
extern uint8_t PTR_FUN_006f5294;
extern uint8_t PTR_FUN_006f52a0;
extern uint8_t PTR_FUN_006f5310;
extern uint8_t PTR_FUN_006f5380;

// --- referenced helpers --------------------------------------------------
void FUN_0056f540();
void FUN_00581300(uint32_t index, void** slot);
void FUN_006b3330();
void FUN_006b3910();
void FUN_005b62a0(void** slot);
uint32_t thunk_FUN_00533c78(uint32_t bytes);
void FUN_005606f0(uint32_t index, void* value);
void FUN_006b50d0();
void FUN_006b50f0();
void FUN_005edba0();
void FUN_006b38d0(void* self);
void FUN_006b34a0(void* self, uint32_t param_1);
void FUN_006b37c0(void* self, int* param_1);
void FUN_006b33e0(void* self);
void FUN_006b35b0(void* self);
void operator_delete(void* p);
void operator_delete__(void* p);

// Deleting destructor (vtable slot 0 with flag 1), rendered by the provider
// as `(**(code **)*p)(1)`; the ECX receiver is the object itself.
typedef void (__thiscall* VtDeletingDtor)(void* self, uint32_t flags);
static inline void VtDelete(void* obj)
{
    ((VtDeletingDtor)(*(void***)obj)[0])(obj, 1u);
}

// Virtual slot 1 with no stack arguments, returning a pointer.
typedef void* (__thiscall* VtSlot1Fn)(void* self);
static inline void* VtCallSlot1(void* obj)
{
    return ((VtSlot1Fn)(*(void***)obj)[1])(obj);
}

// Virtual slot 2 with one stack argument.
typedef void (__thiscall* VtSlot2Fn)(void* self, void* arg);
static inline void VtCallSlot2(void* obj, void* arg)
{
    ((VtSlot2Fn)(*(void***)obj)[2])(obj, arg);
}

// 0x6b33a0 — observed shape
void FUN_006b33a0(void* self)
{
    uint32_t* o = (uint32_t*)self;

    FUN_006b38d0(self);
    o[0] = (uint32_t)(uintptr_t)&PTR_FUN_006f5218;
    o[0xd] = (uint32_t)(uintptr_t)&PTR_FUN_006f5210;
    o[0xf] = 0;
    o[0x12] = 1;
    o[0x10] = 0;
    o[0x11] = 0;
    o[0xe] = 0;
    FUN_0056f540();
}

// 0x6b33e0 — observed shape
void FUN_006b33e0(void* self)
{
    uint32_t* o = (uint32_t*)self;
    uint32_t uVar1 = 0;
    void* local_4;

    o[0] = (uint32_t)(uintptr_t)&PTR_FUN_006f5218;
    local_4 = self;
    if (o[0x10] != 0) {
        local_4 = (void*)0;
        do {
            FUN_00581300(uVar1, &local_4);
            uVar1 = uVar1 + 1;
        } while (uVar1 < o[0x10]);
    }
    FUN_0056f540();
    FUN_006b3330();
    FUN_006b3910();
}

// 0x6b3440 — observed shape
void FUN_006b3440(void* self, uint8_t param_1)
{
    FUN_006b33e0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x6b3460 — observed shape
uint32_t FUN_006b3460(uint32_t* param_1)
{
    uint32_t* puVar2;

    if (param_1 == 0) {
        return 0;
    }
    puVar2 = param_1;
    param_1[1] = param_1[1] + 1;
    FUN_005b62a0((void**)&param_1);
    puVar2[1] = puVar2[1] - 1;
    if (puVar2[1] == 0) {
        VtDelete(puVar2);
    }
    return 1;
}

// 0x6b34a0 — observed shape
void FUN_006b34a0(void* self, uint32_t param_1)
{
    uint8_t* p = (uint8_t*)self;
    void* pvVar1;
    uint32_t uVar2;
    uint32_t uVar3;

    if (param_1 != *(uint32_t*)(p + 8)) {
        if (param_1 < *(uint32_t*)(p + 0xc)) {
            uVar3 = param_1;
            do {
                if (*(int*)(*(int*)(p + 4) + uVar3 * 4) != 0) {
                    *(uint32_t*)(*(int*)(p + 4) + uVar3 * 4) = 0;
                    *(int*)(p + 0x10) = *(int*)(p + 0x10) - 1;
                }
                uVar3 = uVar3 + 1;
            } while (uVar3 < *(uint32_t*)(p + 0xc));
            *(uint32_t*)(p + 0xc) = param_1;
        }
        pvVar1 = *(void**)(p + 4);
        *(uint32_t*)(p + 8) = param_1;
        if (param_1 == 0) {
            *(uint32_t*)(p + 4) = 0;
        }
        else {
            uVar2 = thunk_FUN_00533c78(param_1 * 4);
            *(uint32_t*)(p + 4) = uVar2;
            uVar3 = 0;
            if (*(int*)(p + 0xc) != 0) {
                do {
                    *(uint32_t*)(*(int*)(p + 4) + uVar3 * 4) =
                        *(uint32_t*)((int)(intptr_t)pvVar1 + uVar3 * 4);
                    uVar3 = uVar3 + 1;
                } while (uVar3 < *(uint32_t*)(p + 0xc));
            }
            uVar3 = *(uint32_t*)(p + 0xc);
            if (uVar3 < *(uint32_t*)(p + 8)) {
                do {
                    *(uint32_t*)(*(int*)(p + 4) + uVar3 * 4) = 0;
                    uVar3 = uVar3 + 1;
                } while (uVar3 < *(uint32_t*)(p + 8));
                operator_delete__(pvVar1);
                return;
            }
        }
        operator_delete__(pvVar1);
    }
}

// 0x6b3560 — observed shape
void FUN_006b3560(void* self, uint8_t param_1)
{
    uint32_t* o = (uint32_t*)self;

    o[0] = (uint32_t)(uintptr_t)&PTR_FUN_006f5284;
    operator_delete__((void*)o[1]);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x6b35b0 — observed shape
void FUN_006b35b0(void* self)
{
    uint32_t* o = (uint32_t*)self;
    uint32_t uVar4 = 0;
    void* puVar2;
    void* puVar3;
    uint32_t* piVar1;

    o[0] = (uint32_t)(uintptr_t)&PTR_FUN_006f52a0;
    if (o[0x11] != 0) {
        do {
            puVar2 = *(void**)(o[0xf] + uVar4 * 4);
            if (puVar2 != 0) {
                if (uVar4 < o[0x10]) {
                    if (uVar4 < o[0x11]) {
                        if (*(int*)(o[0xf] + uVar4 * 4) != 0) {
                            o[0x12] = o[0x12] - 1;
                        }
                    }
                    else {
                        o[0x11] = uVar4 + 1;
                    }
                    *(uint32_t*)(o[0xf] + uVar4 * 4) = 0;
                }
                VtDelete(puVar2);
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < o[0x11]);
    }
    uVar4 = 0;
    if (o[0x11] != 0) {
        do {
            *(uint32_t*)(o[0xf] + uVar4 * 4) = 0;
            uVar4 = uVar4 + 1;
        } while (uVar4 < o[0x11]);
    }
    piVar1 = o + 0x15;
    o[0x11] = 0;
    o[0x12] = 0;
    puVar2 = (void*)o[0x16];
    while (puVar2 != 0) {
        puVar3 = *(void**)puVar2;
        VtCallSlot2((void*)piVar1, puVar2);
        puVar2 = puVar3;
    }
    o[0x18] = 0;
    o[0x16] = 0;
    o[0x17] = 0;
    *piVar1 = (uint32_t)(uintptr_t)&PTR_FUN_006f5294;
    puVar2 = (void*)o[0x16];
    while (puVar2 != 0) {
        puVar3 = *(void**)puVar2;
        VtCallSlot2((void*)piVar1, puVar2);
        puVar2 = puVar3;
    }
    o[0x18] = 0;
    o[0x16] = 0;
    o[0x17] = 0;
    *piVar1 = (uint32_t)(uintptr_t)&PTR_LAB_006f5288;
    o[0xe] = (uint32_t)(uintptr_t)&PTR_FUN_006f5284;
    operator_delete__((void*)o[0xf]);
    FUN_006b3910();
}

// Byte-wise comparison exactly as emitted by the provider (two bytes per
// iteration, early exit, sign of the result from the observed expression).
static int CompareBytes2(const uint8_t* pbVar4, const uint8_t* pbVar6)
{
    uint8_t bVar1;
    bool bVar7;
    int iVar5;

    do {
        bVar1 = *pbVar4;
        bVar7 = bVar1 < *pbVar6;
        if (bVar1 != *pbVar6) {
            iVar5 = (1 - (uint32_t)bVar7) - (uint32_t)(bVar7 != 0);
            return iVar5;
        }
        if (bVar1 == 0) {
            break;
        }
        bVar1 = pbVar4[1];
        bVar7 = bVar1 < pbVar6[1];
        if (bVar1 != pbVar6[1]) {
            iVar5 = (1 - (uint32_t)bVar7) - (uint32_t)(bVar7 != 0);
            return iVar5;
        }
        pbVar4 = pbVar4 + 2;
        pbVar6 = pbVar6 + 2;
    } while (bVar1 != 0);
    return 0;
}

// 0x6b36a0 — observed shape
int* FUN_006b36a0(void* self, uint8_t* param_1)
{
    uint32_t* puVar2;
    int* piVar3;
    uint8_t* pbVar4;
    uint8_t* pbVar6;
    int iVar5;

    if (param_1 == 0) {
        return (int*)0x0;
    }
    puVar2 = *(uint32_t**)((uint8_t*)self + 0x58);
    *(uint32_t**)((uint8_t*)self + 0x50) = puVar2;
    if (puVar2 != 0) {
        *(uint32_t*)((uint8_t*)self + 0x50) = *puVar2;
        piVar3 = (int*)puVar2[2];
        while (piVar3 != 0) {
            pbVar4 = (uint8_t*)VtCallSlot1(piVar3);
            pbVar6 = param_1;
            iVar5 = CompareBytes2(pbVar4, pbVar6);
            if (iVar5 == 0) {
                return piVar3;
            }
            puVar2 = *(uint32_t**)((uint8_t*)self + 0x50);
            if (puVar2 == 0) {
                return (int*)0x0;
            }
            *(uint32_t*)((uint8_t*)self + 0x50) = *puVar2;
            piVar3 = (int*)puVar2[2];
        }
    }
    return (int*)0x0;
}

// 0x6b3740 — observed shape
void FUN_006b3740(void* self, uint8_t param_1)
{
    FUN_006b35b0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x6b3760 — observed shape
void FUN_006b3760(void* self, uint8_t param_1)
{
    *(uint32_t*)self = (uint32_t)(uintptr_t)&PTR_FUN_006f5294;
    FUN_005edba0();
    *(uint32_t*)self = (uint32_t)(uintptr_t)&PTR_LAB_006f5288;
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x6b3790 — observed shape
// NEEDS_MANUAL: the provider renders the FUN_006b34a0 call with one stack
// argument (*(int*)(self + 0x4c) + param_1) and an implicit ECX receiver that
// it does not expose; the receiver identity is not recoverable from this
// listing, so the call is reproduced through the observed one-argument shape.
void FUN_006b3790(void* self, uint32_t param_1, uint8_t param_2)
{
    uint8_t* p = (uint8_t*)self;

    if (*(uint32_t*)(p + 0x40) <= param_1) {
        reinterpret_cast<void (*)(uint32_t)>(&FUN_006b34a0)(
            (uint32_t)(*(int*)(p + 0x4c) + (int)param_1));
    }
    FUN_005606f0(param_1, &param_2);
}

// 0x6b37c0 — observed shape
void FUN_006b37c0(void* self, int* param_1)
{
    uint32_t* o = (uint32_t*)self;
    uint32_t* node = (uint32_t*)VtCallSlot1(self);
    uint32_t* puVar2 = (uint32_t*)node[2];
    int iVar3;

    if (puVar2 != (uint32_t*)*param_1) {
        if (puVar2 != 0) {
            puVar2[1] = puVar2[1] - 1;
            if (puVar2[1] == 0) {
                VtDelete(puVar2);
            }
        }
        iVar3 = *param_1;
        node[2] = (uint32_t)iVar3;
        if (iVar3 != 0) {
            *(int*)(iVar3 + 4) = *(int*)(iVar3 + 4) + 1;
        }
    }
    node[0] = 0;
    node[1] = o[2];
    if (o[2] == 0) {
        o[1] = (uint32_t)(uintptr_t)node;
        o[2] = (uint32_t)(uintptr_t)node;
        o[3] = o[3] + 1;
        return;
    }
    *(uint32_t*)o[2] = (uint32_t)(uintptr_t)node;
    o[2] = (uint32_t)(uintptr_t)node;
    o[3] = o[3] + 1;
}

// 0x6b3830 — observed shape
void FUN_006b3830(void* self)
{
    uint32_t* o = (uint32_t*)self;
    uint32_t uVar1;

    FUN_006b38d0(self);
    o[0] = (uint32_t)(uintptr_t)&PTR_FUN_006f52a0;
    o[0xd] = 0;
    o[0xe] = (uint32_t)(uintptr_t)&PTR_FUN_006f5284;
    o[0x10] = 0;
    o[0x13] = 1;
    o[0x11] = 0;
    o[0x12] = 0;
    o[0xf] = 0;
    o[0x18] = 0;
    o[0x16] = 0;
    o[0x17] = 0;
    o[0x15] = (uint32_t)(uintptr_t)&PTR_FUN_006f5294;
    uVar1 = 0;
    if (o[0x11] != 0) {
        do {
            *(uint32_t*)(o[0xf] + uVar1 * 4) = 0;
            uVar1 = uVar1 + 1;
        } while (uVar1 < o[0x11]);
    }
    o[0x11] = 0;
    o[0x12] = 0;
    FUN_005edba0();
}

// 0x6b38a0 — observed shape
void FUN_006b38a0(void* self, uint32_t* param_1)
{
    uint32_t* puVar2;

    if (param_1 != 0) {
        puVar2 = param_1;
        param_1[1] = param_1[1] + 1;
        FUN_006b37c0(self, (int*)&param_1);
        puVar2[1] = puVar2[1] - 1;
        if (puVar2[1] == 0) {
            VtDelete(puVar2);
        }
    }
}

// 0x6b38d0 — observed shape
void FUN_006b38d0(void* self)
{
    uint32_t* o = (uint32_t*)self;

    FUN_006b50d0();
    o[5] = 0;
    o[7] = 0;
    o[9] = 0;
    o[10] = 0;
    o[0xb] = 0;
    o[0xc] = 0;
    o[0] = (uint32_t)(uintptr_t)&PTR_FUN_006f5310;
    o[4] = 0xffffffff;
    o[6] = 0xffffffff;
    o[8] = 0xffffffff;
}

// 0x6b3bd0 — observed shape
void FUN_006b3bd0(void* self, uint8_t param_1)
{
    *(uint32_t*)self = (uint32_t)(uintptr_t)&PTR_FUN_006f5310;
    FUN_006b50f0();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x6b3c00 — observed shape
void FUN_006b3c00(void* self)
{
    uint32_t* o = (uint32_t*)self;

    FUN_006b50d0();
    o[4] = 0;
    o[5] = 0;
    o[6] = 0;
    o[0x16] = 0;
    o[0x26] = 0;
    o[0x36] = 0;
    o[0] = (uint32_t)(uintptr_t)&PTR_FUN_006f5380;
}

// 0x6b3c30 — observed shape
uint32_t FUN_006b3c30(void* self, uint8_t* param_1)
{
    uint8_t* p = (uint8_t*)self;

    if (*(int*)(p + 0x10) == 1) {
        *param_1 = *(uint8_t*)(p + 0x18);
        return 1;
    }
    return 0;
}

// 0x6b3c50 — observed shape
uint32_t FUN_006b3c50(void* self, uint32_t* param_1, uint32_t in_EAX)
{
    uint8_t* p = (uint8_t*)self;
    uint32_t uVar1;

    if (*(int*)(p + 0x10) == 2) {
        uVar1 = *(uint32_t*)(p + 0x18);
        *param_1 = uVar1;
        return (uVar1 & 0xffffff00u) | 1u;
    }
    return in_EAX & 0xffffff00u;
}

// 0x6b3c70 — observed shape
uint32_t FUN_006b3c70(void* self, uint32_t* param_1, uint32_t in_EAX)
{
    uint8_t* p = (uint8_t*)self;
    uint32_t uVar1;

    if (*(int*)(p + 0x10) == 3) {
        uVar1 = *(uint32_t*)(p + 0x18);
        *param_1 = uVar1;
        return (uVar1 & 0xffffff00u) | 1u;
    }
    return in_EAX & 0xffffff00u;
}
