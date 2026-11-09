// UNVERIFIED decompiler-derived reconstruction — cl 13.10.3077 absent; no PASS.
// Sources: analysis/pseudocode/functions/*.c.
#include <cstdint>
#include <cstddef>
#include <cmath>

// x87 extended-precision temporaries (`float10` in the provider output).
using float10 = long double;

extern void operator_delete(void* p);
extern void operator_delete__(void* p);
extern void FUN_004e6420();
extern int FUN_00533c78(uint32_t size);
extern void* thunk_FUN_00533c78(uint32_t size);
extern void FUN_00540c50();
extern void* FUN_005539e0(int a, uint32_t* matrix, int b, int c);
extern int* FUN_005446d0();
extern void FUN_004127b0(void* dst, uint32_t elem_size, uint32_t count, const void* ctor);
extern uint32_t FUN_00551810(uint16_t n1, int a, void* b, int c, int d, uint32_t e, int f,
                             uint32_t g, uint32_t* h);
extern uint32_t FUN_005473e0(uint16_t n1, int a, void* b, int c, int d, uint32_t e, int f,
                             uint16_t g, uint16_t h, uint32_t* i, uint32_t* j);
extern void* FUN_0054c210(uint32_t id);
extern int FUN_0051ffd0();
extern void FUN_005200b0(void* param);
extern void FUN_00520190(void* param);
extern void FUN_005538c0(int* param);
extern void FUN_0050d3e0(void* param_1, uint32_t param_2);
extern void FUN_00533d10();
extern void FUN_00535de0();
extern uint32_t FUN_0050b980(uint32_t in_EAX, int in_EDX, void* self_in_EBX);

extern void* PTR_FUN_007115f4;
extern void* PTR_FUN_007115bc;
extern void* PTR_FUN_007115d8;
extern void* PTR_FUN_0070bf4c;
extern void* PTR_FUN_0070bed4;
extern void* PTR_FUN_0070e93c;
extern void* PTR_FUN_00711680;
extern void* PTR_FUN_0071169c;

extern uint32_t _DAT_008ee060;
extern uint32_t _DAT_008ee058;
extern uint32_t DAT_008ee054;
extern int DAT_008ca53c;
extern int DAT_008edf30;
extern int* DAT_008ea08c;
extern int DAT_00727c30;
extern uint8_t LAB_005cea70;

namespace {

// Provider form `(**(code **)(*obj + slot))(...)`: the first dword of obj is a
// vtable pointer and slot is a byte offset into that table.
inline void* vtable_slot(const void* obj, uint32_t slot)
{
    const void* vtbl = reinterpret_cast<const void*>(
        static_cast<uintptr_t>(*static_cast<const uint32_t*>(obj)));
    return *reinterpret_cast<void* const*>(static_cast<const char*>(vtbl) + slot);
}

// Provider form `(**(code **)*obj)(1)`: vtable slot 0 is the deleting destructor.
inline void vtable_call_slot0(void* obj, int arg)
{
    reinterpret_cast<void (*)(int)>(vtable_slot(obj, 0))(arg);
}

} // namespace

// 0x50af70 — observed shape
// Destructor: installs vtable 0x7115f4, releases owned pointer at +4, conditional free.
void FUN_0050af70(void* self_in_ECX, uint8_t param_1)
{
    uint32_t* self = (uint32_t*)self_in_ECX;
    *self = (uint32_t)(uintptr_t)&PTR_FUN_007115f4;
    operator_delete__((void*)(uintptr_t)self[1]);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x50afa0 — observed shape
// Hash-table insert: probes the bucket chain via vtable slots +4/+8, allocates a
// node (+0x14), constructs it (+0xc), links it at the bucket head and bumps count (+0xc).
void FUN_0050afa0(void* self_in_ESI)
{
    uint32_t* esi = (uint32_t*)self_in_ESI;
    uint32_t* puVar3;
    int32_t iVar2 = reinterpret_cast<int32_t (*)(void)>(vtable_slot(esi, 4))();
    puVar3 = (uint32_t*)(uintptr_t)(esi[2] + (uint32_t)iVar2 * 4);
    while (true) {
        if (puVar3 == (uint32_t*)0x0) {
            puVar3 = (uint32_t*)(uintptr_t)reinterpret_cast<void* (*)(void)>(vtable_slot(esi, 0x14))();
            reinterpret_cast<void (*)(uint32_t*)>(vtable_slot(esi, 0xc))(puVar3);
            *puVar3 = *(uint32_t*)(uintptr_t)(esi[2] + (uint32_t)iVar2 * 4);
            *(uint32_t*)(uintptr_t)(esi[2] + (uint32_t)iVar2 * 4) = (uint32_t)(uintptr_t)puVar3;
            esi[3] = esi[3] + 1;
            return;
        }
        char cVar1 = reinterpret_cast<char (*)(void)>(vtable_slot(esi, 8))();
        if (cVar1 != '\0') {
            break;
        }
        puVar3 = (uint32_t*)(uintptr_t)*puVar3;
    }
    reinterpret_cast<void (*)(uint32_t*)>(vtable_slot(esi, 0x10))(puVar3);
    reinterpret_cast<void (*)(uint32_t*)>(vtable_slot(esi, 0xc))(puVar3);
    return;
}

// 0x50b020 — observed shape
// Destructor: installs vtable 0x7115bc, calls FUN_004e6420, frees owned pointer at +8.
void FUN_0050b020(void* self_in_ECX, uint8_t param_1)
{
    uint32_t* self = (uint32_t*)self_in_ECX;
    *self = (uint32_t)(uintptr_t)&PTR_FUN_007115bc;
    FUN_004e6420();
    operator_delete__((void*)(uintptr_t)self[2]);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x50b0b0 — observed shape
// Destructor: installs vtable 0x7115d8, calls FUN_004e6420, reinstalls base vtable
// 0x7115bc, calls FUN_004e6420 again, frees owned pointer at +8.
void FUN_0050b0b0(void* self_in_ECX, uint8_t param_1)
{
    uint32_t* self = (uint32_t*)self_in_ECX;
    *self = (uint32_t)(uintptr_t)&PTR_FUN_007115d8;
    FUN_004e6420();
    *self = (uint32_t)(uintptr_t)&PTR_FUN_007115bc;
    FUN_004e6420();
    operator_delete__((void*)(uintptr_t)self[2]);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x50b0f0 — observed shape
// 4-float inequality: returns 0 when all four components match, else 1.
int32_t FUN_0050b0f0(void* self_in_ECX, float* param_1)
{
    float* in_ECX = (float*)self_in_ECX;
    if ((((*in_ECX == *param_1) && (in_ECX[1] == param_1[1])) && (in_ECX[2] == param_1[2])) &&
        (in_ECX[3] == param_1[3])) {
        return 0;
    }
    return 1;
}

// 0x50b150 — observed shape
// Hash lookup: walks the chain via vtable slots +4/+8; on a match stores node[2]
// through the caller's out pointer and returns 1, otherwise returns 0.
int32_t FUN_0050b150(void* self_in_EDI, uint32_t* out)
{
    uint32_t* edi = (uint32_t*)self_in_EDI;
    int32_t iVar3 = reinterpret_cast<int32_t (*)(void)>(vtable_slot(edi, 4))();
    uint32_t* puVar1 = (uint32_t*)(uintptr_t)(edi[2] + (uint32_t)iVar3 * 4);
    while (true) {
        if (puVar1 == (uint32_t*)0x0) {
            return 0;
        }
        char cVar2 = reinterpret_cast<char (*)(void)>(vtable_slot(edi, 8))();
        if (cVar2 != '\0') {
            break;
        }
        puVar1 = (uint32_t*)(uintptr_t)*puVar1;
    }
    *out = puVar1[2];
    return 1;
}

// 0x50b1d0 — observed shape
// Constructor: zeroes self fields, copies a 4-float value into +0x10..+0x1c, builds a
// 3x4 matrix (0x3c23d70a = 0.00999999, 0x3f800000 = 1.0), allocates a 0x28 object
// through FUN_005539e0 and stores it ref-counted at +0xc, stores the passed
// ref-counted object at +8, sets the ready byte at +1, allocates a 100-entry pool
// object, fills its fields (count +0x5c), creates three renderables (vtables
// 0x70bf4c, 0x70bed4, 0x70e93c) plus the pooled owner (0x711680, 400-byte buffer),
// registers each through vtable slot +0x34 into the table at [self+0xc]+0xc+8+i*4,
// stores the owner at +0x20 and caches cos(1deg) in self+4, then releases the four
// temporary references.
void FUN_0050b1d0(int* param_1, void* self_in_EBX, int* in_EAX)
{
    uint8_t* ebx = (uint8_t*)self_in_EBX;
    int* piVar1;
    int* piVar4;
    int* piVar7;
    int* piVar8;
    uint32_t* puVar2;
    uint32_t* puVar6;
    int iVar3;
    int iVar5;
    int iVar9;
    uint32_t uVar10;
    int* piStack_44;

    *(uint32_t*)(ebx + 8) = 0;
    *(uint32_t*)(ebx + 0xc) = 0;
    *(uint32_t*)(ebx + 0x10) = 0;
    *(uint32_t*)(ebx + 0x14) = 0;
    *(uint32_t*)(ebx + 0x18) = 0;
    *(uint32_t*)(ebx + 0x1c) = 0;
    *ebx = 0;
    *(int*)(ebx + 0x10) = in_EAX[0];
    *(int*)(ebx + 0x14) = in_EAX[1];
    *(int*)(ebx + 0x18) = in_EAX[2];
    *(int*)(ebx + 0x1c) = in_EAX[3];
    // local_30..local_4 in the provider listing; contiguous 12-dword matrix.
    uint32_t local_30[12] = {
        0x00000000u, 0x3f800000u, 0x3c23d70au, 0x00000000u,
        0x00000000u, 0x3c23d70au, 0x3f800000u, 0x00000000u,
        0x3c23d70au, 0x3f800000u, 0x3f800000u, 0x3c23d70au
    };
    iVar5 = FUN_00533c78(0x28);
    if (iVar5 == 0) {
        puVar6 = (uint32_t*)0x0;
    } else {
        puVar6 = (uint32_t*)(uintptr_t)FUN_005539e0(4, local_30, 0, 0);
    }
    puVar2 = *(uint32_t**)(ebx + 0xc);
    if (puVar2 != puVar6) {
        if (puVar2 != (uint32_t*)0x0) {
            piVar7 = (int*)(puVar2 + 1);
            *piVar7 = *piVar7 + -1;
            if (*piVar7 == 0) {
                vtable_call_slot0(puVar2, 1);
            }
        }
        *(uint32_t**)(ebx + 0xc) = puVar6;
        if (puVar6 != (uint32_t*)0x0) {
            puVar6[1] = puVar6[1] + 1;
        }
    }
    puVar6 = *(uint32_t**)(ebx + 8);
    if (puVar6 != (uint32_t*)param_1) {
        if (puVar6 != (uint32_t*)0x0) {
            piVar7 = (int*)(puVar6 + 1);
            *piVar7 = *piVar7 + -1;
            if (*piVar7 == 0) {
                vtable_call_slot0(puVar6, 1);
            }
        }
        *(int**)(ebx + 8) = param_1;
        if (param_1 != (int*)0x0) {
            param_1[1] = param_1[1] + 1;
        }
    }
    ebx[1] = 1;
    iVar5 = FUN_00533c78(100);
    if (iVar5 == 0) {
        piVar7 = (int*)0x0;
    } else {
        piVar7 = (int*)FUN_005446d0();
        if (piVar7 != (int*)0x0) {
            piVar7[1] = piVar7[1] + 1;
        }
    }
    iVar5 = in_EAX[1];
    iVar9 = in_EAX[2];
    piVar7[9] = in_EAX[0];
    piVar7[10] = iVar5;
    iVar5 = piVar7[0x17];
    piVar7[0xb] = iVar9;
    piVar7[0x17] = iVar5 + 1;
    iVar9 = in_EAX[1];
    iVar3 = in_EAX[2];
    piVar7[0xc] = in_EAX[0];
    piVar7[0xd] = iVar9;
    piVar7[0xe] = iVar3;
    piVar7[0x17] = iVar5 + 2;
    iVar9 = in_EAX[1];
    iVar3 = in_EAX[2];
    piVar7[0x12] = in_EAX[0];
    piVar7[0x13] = iVar9;
    piVar7[0x17] = iVar5 + 3;
    piVar7[0x14] = iVar3;
    piVar7[0x16] = in_EAX[3];
    piVar7[0x17] = iVar5 + 4;
    piStack_44 = (int*)(uintptr_t)FUN_00533c78(0x24);
    if (piStack_44 == (int*)0x0) {
        piStack_44 = (int*)0x0;
    } else {
        FUN_00540c50();
        *piStack_44 = (int)(uintptr_t)&PTR_FUN_0070bf4c;
        *(uint16_t*)(piStack_44 + 8) = 0xec;
        *(uint8_t*)((char*)piStack_44 + 0x22) = 0;
        piStack_44[1] = piStack_44[1] + 1;
    }
    *(uint16_t*)(piStack_44 + 8) =
        (uint16_t)((*(uint16_t*)(piStack_44 + 8) & 0xfdff) | 0x2001);
    param_1 = (int*)(uintptr_t)FUN_00533c78(0x28);
    if (param_1 == (int*)0x0) {
        param_1 = (int*)0x0;
    } else {
        FUN_00540c50();
        *(uint16_t*)(param_1 + 8) = 3;
        param_1[9] = 3;
        *param_1 = (int)(uintptr_t)&PTR_FUN_0070bed4;
        param_1[1] = param_1[1] + 1;
    }
    *(uint8_t*)(param_1 + 8) = *(uint8_t*)(param_1 + 8) & 0xfc;
    piVar8 = (int*)(uintptr_t)FUN_00533c78(0x40);
    if (piVar8 == (int*)0x0) {
        piVar8 = (int*)0x0;
    } else {
        FUN_00540c50();
        *piVar8 = (int)(uintptr_t)&PTR_FUN_0070e93c;
        *(uint8_t*)(piVar8 + 8) = 0;
        piVar8[9] = 4;
        piVar8[10] = 0;
        piVar8[0xb] = -1;
        piVar8[0xc] = 0;
        piVar8[0xd] = 0;
        piVar8[0xe] = 3;
        piVar8[0xf] = 0;
        piVar8[1] = piVar8[1] + 1;
    }
    *(uint8_t*)(piVar8 + 8) = 1;
    piVar8[9] = 3;
    piVar8[0xe] = 0;
    piVar8[0xc] = 0;
    piVar8[0xd] = 0;
    piVar8[10] = 1;
    // Register piVar8.
    iVar5 = *(int*)(*(int*)(ebx + 0xc) + 0xc);
    iVar9 = reinterpret_cast<int (*)(void)>(vtable_slot(piVar8, 0x34))();
    puVar6 = (uint32_t*)(uintptr_t)(iVar5 + 8 + iVar9 * 4);
    piVar4 = (int*)(uintptr_t)*puVar6;
    if (piVar4 != piVar8) {
        if (piVar4 != (int*)0x0) {
            piVar1 = piVar4 + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                vtable_call_slot0(piVar4, 1);
            }
        }
        *puVar6 = (uint32_t)(uintptr_t)piVar8;
        piVar8[1] = piVar8[1] + 1;
    }
    // Register piStack_44.
    iVar5 = *(int*)(*(int*)(ebx + 0xc) + 0xc);
    iVar9 = reinterpret_cast<int (*)(void)>(vtable_slot(piStack_44, 0x34))();
    puVar6 = (uint32_t*)(uintptr_t)(iVar5 + 8 + iVar9 * 4);
    piVar4 = (int*)(uintptr_t)*puVar6;
    if (piVar4 != piStack_44) {
        if (piVar4 != (int*)0x0) {
            piVar1 = piVar4 + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                vtable_call_slot0(piVar4, 1);
            }
        }
        *puVar6 = (uint32_t)(uintptr_t)piStack_44;
        piStack_44[1] = piStack_44[1] + 1;
    }
    // Register param_1.
    iVar5 = *(int*)(*(int*)(ebx + 0xc) + 0xc);
    iVar9 = reinterpret_cast<int (*)(void)>(vtable_slot(param_1, 0x34))();
    puVar6 = (uint32_t*)(uintptr_t)(iVar5 + 8 + iVar9 * 4);
    piVar4 = (int*)(uintptr_t)*puVar6;
    if (piVar4 != param_1) {
        if (piVar4 != (int*)0x0) {
            piVar1 = piVar4 + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                vtable_call_slot0(piVar4, 1);
            }
        }
        *puVar6 = (uint32_t)(uintptr_t)param_1;
        param_1[1] = param_1[1] + 1;
    }
    // Register piVar7.
    iVar5 = *(int*)(*(int*)(ebx + 0xc) + 0xc);
    iVar9 = reinterpret_cast<int (*)(void)>(vtable_slot(piVar7, 0x34))();
    puVar6 = (uint32_t*)(uintptr_t)(iVar5 + 8 + iVar9 * 4);
    piVar4 = (int*)(uintptr_t)*puVar6;
    if (piVar4 != piVar7) {
        if (piVar4 != (int*)0x0) {
            piVar1 = piVar4 + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                vtable_call_slot0(piVar4, 1);
            }
        }
        *puVar6 = (uint32_t)(uintptr_t)piVar7;
        piVar7[1] = piVar7[1] + 1;
    }
    puVar6 = (uint32_t*)(uintptr_t)FUN_00533c78(0x18);
    if (puVar6 == (uint32_t*)0x0) {
        puVar6 = (uint32_t*)0x0;
    } else {
        *puVar6 = (uint32_t)(uintptr_t)&PTR_FUN_00711680;
        puVar6[2] = 100;
        puVar6[5] = 100;
        puVar6[3] = 0;
        puVar6[4] = 0;
        uVar10 = (uint32_t)(uintptr_t)thunk_FUN_00533c78(400);
        puVar6[1] = uVar10;
        *puVar6 = (uint32_t)(uintptr_t)&PTR_FUN_00711680;
    }
    *(uint32_t**)(ebx + 0x20) = puVar6;
    float10 fVar11 = std::cos((float10)0.01745329238474369);
    *(float*)(ebx + 4) = (float)fVar11;
    piVar4 = piVar8 + 1;
    *piVar4 = *piVar4 + -1;
    if (*piVar4 == 0) {
        vtable_call_slot0(piVar8, 1);
    }
    piVar8 = param_1 + 1;
    *piVar8 = *piVar8 + -1;
    if (*piVar8 == 0) {
        vtable_call_slot0(param_1, 1);
    }
    piVar8 = piStack_44 + 1;
    *piVar8 = *piVar8 + -1;
    if (*piVar8 == 0) {
        vtable_call_slot0(piStack_44, 1);
    }
    piVar8 = piVar7 + 1;
    *piVar8 = *piVar8 + -1;
    if (*piVar8 == 0) {
        vtable_call_slot0(piVar7, 1);
    }
    return;
}

// 0x50b630 — observed shape
// Releases the +0x20 object, then the +0xc reference (twice, second time on the now
// nulled slot) and the +8 reference.
void FUN_0050b630(void* self_in_ESI)
{
    uint8_t* esi = (uint8_t*)self_in_ESI;
    int* piVar1;
    uint32_t* puVar2;

    if (*(uint32_t**)(esi + 0x20) != (uint32_t*)0x0) {
        vtable_call_slot0(*(uint32_t**)(esi + 0x20), 1);
        *(uint32_t*)(esi + 0x20) = 0;
    }
    puVar2 = *(uint32_t**)(esi + 0xc);
    if (puVar2 != (uint32_t*)0x0) {
        piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            vtable_call_slot0(puVar2, 1);
        }
        *(uint32_t*)(esi + 0xc) = 0;
    }
    puVar2 = *(uint32_t**)(esi + 0xc);
    if (puVar2 != (uint32_t*)0x0) {
        piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            vtable_call_slot0(puVar2, 1);
        }
    }
    puVar2 = *(uint32_t**)(esi + 8);
    if (puVar2 != (uint32_t*)0x0) {
        piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            vtable_call_slot0(puVar2, 1);
        }
    }
    return;
}

// 0x50b690 — observed shape
// Writes a position into the first node of the table ([self+0xc]+0xc, field +0x14):
// +0x24..+0x38 (two copies of xyz), +0x48..+0x50 (xyz), +0x58 w, bumps +0x5c by 4,
// and mirrors xyz/w into self+0x10..+0x1c.
void FUN_0050b690(void* self_in_ECX, uint32_t param_1, uint32_t param_2, uint32_t param_3,
                  uint32_t param_4)
{
    int in_ECX = (int)(uintptr_t)self_in_ECX;
    int iVar1 = *(int*)(*(int*)(*(int*)(in_ECX + 0xc) + 0xc) + 0x14);
    *(uint32_t*)(iVar1 + 0x24) = param_1;
    *(uint32_t*)(iVar1 + 0x28) = param_2;
    *(uint32_t*)(iVar1 + 0x2c) = param_3;
    *(uint32_t*)(iVar1 + 0x30) = param_1;
    *(uint32_t*)(iVar1 + 0x34) = param_2;
    *(uint32_t*)(iVar1 + 0x38) = param_3;
    *(uint32_t*)(iVar1 + 0x48) = param_1;
    *(uint32_t*)(iVar1 + 0x4c) = param_2;
    *(uint32_t*)(iVar1 + 0x50) = param_3;
    *(uint32_t*)(iVar1 + 0x58) = param_4;
    *(int*)(iVar1 + 0x5c) = *(int*)(iVar1 + 0x5c) + 4;
    *(uint32_t*)(in_ECX + 0x10) = param_1;
    *(uint32_t*)(in_ECX + 0x14) = param_2;
    *(uint32_t*)(in_ECX + 0x18) = param_3;
    *(uint32_t*)(in_ECX + 0x1c) = param_4;
    return;
}

// 0x50b760 — observed shape
// FShadowManager::Render: lazily stores the class name and initialises the render
// manager, acquires the frame lock, and when the dirty byte at self+0 is clear it
// flushes pending shadow entries (FUN_0050b980 per pool item), copies the 7-dword
// camera block from buffer+0x128 (+0x3dcccccd / 0x461c4000 appended), issues the two
// vtable +0xc4 draw calls on the 0x8ea08c device, swaps the retained device object at
// +0xc, and releases the frame lock.
void FUN_0050b760(void* self_in_EAX, char param_1)
{
    char* in_EAX = (char*)self_in_EAX;
    int* piVar1;
    uint32_t* puVar2;
    char cVar3;
    char* pcVar4;
    uint8_t* extraout_EDX = (uint8_t*)0x0; // decompiler register artifact (EDX of FUN_0050b980)
    int* piVar7;
    uint32_t uVar8;
    uint32_t* puVar9;
    uint32_t* puVar10;
    uint32_t auStack_1c[4];
    uint32_t uStack_c;
    uint32_t uStack_8;
    int iVar5;
    int iVar6;

    if ((_DAT_008ee060 & 1) == 0) {
        _DAT_008ee060 = _DAT_008ee060 | 1;
        pcVar4 = const_cast<char*>("FShadowManager::Render");
        do {
            cVar3 = *pcVar4;
            pcVar4[0x1dc8ac] = cVar3; // provider folds the destination base into this offset
            pcVar4 = pcVar4 + 1;
        } while (cVar3 != '\0');
        _DAT_008ee058 = 0xffffffff;
        DAT_008ee054 = 0;
    }
    if (DAT_008ca53c == 0) {
        iVar5 = FUN_00533c78(0x70);
        if (iVar5 == 0) {
            DAT_008ca53c = 0;
        } else {
            DAT_008ca53c = FUN_0051ffd0();
        }
    }
    FUN_005200b0(&DAT_008edf30);
    if (*in_EAX == '\0') {
        if (param_1 == '\0') {
            reinterpret_cast<void (*)(void)>(vtable_slot(DAT_008ea08c, 0xbc))();
        }
        piVar7 = DAT_008ea08c + 3;
        puVar2 = (uint32_t*)(uintptr_t)*piVar7;
        if (puVar2 != (uint32_t*)0x0) {
            piVar1 = (int*)(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                vtable_call_slot0(puVar2, 1);
            }
            *piVar7 = 0;
        }
        uVar8 = 0;
        if (*(int*)(*(int*)(in_EAX + 0x20) + 0x10) != 0) {
            do {
                // Observed zero-argument call; register inputs are not modelled.
                cVar3 = (char)((char (*)())FUN_0050b980)();
                if ((cVar3 != '\0') || (in_EAX[1] != '\0')) {
                    *extraout_EDX = 1;
                }
                FUN_0050d3e0(extraout_EDX, *(uint32_t*)(in_EAX + 8));
                uVar8 = uVar8 + 1;
            } while (uVar8 < *(uint32_t*)(*(int*)(in_EAX + 0x20) + 0x10));
        }
        iVar5 = *(int*)(in_EAX + 8);
        puVar9 = (uint32_t*)(uintptr_t)(iVar5 + 0x128);
        puVar10 = auStack_1c;
        for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
        }
        uStack_c = 0x3dcccccd;
        uStack_8 = 0x461c4000;
        reinterpret_cast<void (*)(void*, void*, void*, void*, uint32_t*, void*)>(
            vtable_slot(DAT_008ea08c, 0xc4))(
            (void*)(uintptr_t)(iVar5 + 0x90),
            (void*)(uintptr_t)(iVar5 + 0x104),
            (void*)(uintptr_t)(iVar5 + 0x110),
            (void*)(uintptr_t)(iVar5 + 0x11c),
            auStack_1c,
            (void*)(uintptr_t)(iVar5 + 0x144));
        FUN_005538c0(DAT_008ea08c);
        iVar5 = *(int*)(in_EAX + 8);
        reinterpret_cast<void (*)(void*, void*, void*, void*, void*, void*)>(
            vtable_slot(DAT_008ea08c, 0xc4))(
            (void*)(uintptr_t)(iVar5 + 0x90),
            (void*)(uintptr_t)(iVar5 + 0x104),
            (void*)(uintptr_t)(iVar5 + 0x110),
            (void*)(uintptr_t)(iVar5 + 0x11c),
            (void*)(uintptr_t)(iVar5 + 0x128),
            (void*)(uintptr_t)(iVar5 + 0x144));
        puVar9 = (uint32_t*)(uintptr_t)DAT_008ea08c[3];
        piVar7 = DAT_008ea08c + 3;
        if (puVar9 != puVar2) {
            if (puVar9 != (uint32_t*)0x0) {
                piVar1 = (int*)(puVar9 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    vtable_call_slot0(puVar9, 1);
                }
            }
            *piVar7 = (int)(uintptr_t)puVar2;
            if (puVar2 != (uint32_t*)0x0) {
                puVar2[1] = puVar2[1] + 1;
            }
        }
        if (param_1 == '\0') {
            reinterpret_cast<void (*)(void)>(vtable_slot(DAT_008ea08c, 0xc0))();
        }
        in_EAX[1] = '\0';
    }
    if (DAT_008ca53c == 0) {
        iVar5 = FUN_00533c78(0x70);
        if (iVar5 == 0) {
            DAT_008ca53c = 0;
        } else {
            DAT_008ca53c = FUN_0051ffd0();
        }
    }
    FUN_00520190(&DAT_008edf30);
    return;
}

// 0x50b980 — observed shape
// Shadow visibility test: with the two 9-float matrices copied from node+0x38 and
// object+0x6c, compares the three diagonal products against self+4; returns the
// packed x87 comparison flags (bit 0 set on the final accept path).
// The provider models the register inputs in_EAX (a byte to merge), in_EDX (node
// pointer) and EBX (self); they are explicit parameters here.
uint32_t FUN_0050b980(uint32_t in_EAX, int in_EDX, void* self_in_EBX)
{
    uint8_t* ebx = (uint8_t*)self_in_EBX;
    float fVar1;
    float fVar3;
    uint32_t uVar4;
    uint16_t uVar5;
    int iVar2;
    int iVar6;
    float* pfVar7;
    float* pfVar8;
    float local_48[9];
    float local_24[9];

    uVar4 = (in_EAX & 0xffffff00u) | (uint32_t)*(uint8_t*)(in_EDX + 2);
    if (*(char*)(in_EDX + 2) == '\0') {
        uVar4 = 0;
        iVar2 = *(int*)(in_EDX + 0x58);
        if (iVar2 != 0) {
            pfVar7 = (float*)(uintptr_t)(iVar2 + 0x38);
            pfVar8 = local_24;
            for (iVar6 = 9; iVar6 != 0; iVar6 = iVar6 + -1) {
                *pfVar8 = *pfVar7;
                pfVar7 = pfVar7 + 1;
                pfVar8 = pfVar8 + 1;
            }
            pfVar7 = (float*)(uintptr_t)(*(int*)(in_EDX + 8) + 0x6c);
            pfVar8 = local_48;
            for (iVar6 = 9; iVar6 != 0; iVar6 = iVar6 + -1) {
                *pfVar8 = *pfVar7;
                pfVar7 = pfVar7 + 1;
                pfVar8 = pfVar8 + 1;
            }
            fVar3 = local_48[0] * local_24[0] + local_48[3] * local_24[3] + local_48[6] * local_24[6];
            fVar1 = *(float*)(ebx + 4);
            uVar5 = (uint16_t)((uint32_t)iVar2 >> 0x10);
            uVar4 = ((uint32_t)uVar5 << 16) |
                    (uint16_t)(((uint16_t)(fVar3 < fVar1) << 8) |
                               ((uint16_t)(std::isnan(fVar3) || std::isnan(fVar1)) << 10) |
                               ((uint16_t)(fVar3 == fVar1) << 14));
            if ((std::isnan(fVar3) || std::isnan(fVar1)) ||
                (fVar3 < fVar1) == (fVar3 == fVar1)) {
                fVar3 = local_48[1] * local_24[1] + local_48[4] * local_24[4] + local_48[7] * local_24[7];
                fVar1 = *(float*)(ebx + 4);
                uVar4 = ((uint32_t)uVar5 << 16) |
                        (uint16_t)(((uint16_t)(fVar3 < fVar1) << 8) |
                                   ((uint16_t)(std::isnan(fVar3) || std::isnan(fVar1)) << 10) |
                                   ((uint16_t)(fVar3 == fVar1) << 14));
                if ((std::isnan(fVar3) || std::isnan(fVar1)) ||
                    (fVar3 < fVar1) == (fVar3 == fVar1)) {
                    fVar3 = local_48[2] * local_24[2] + local_48[5] * local_24[5] +
                            local_48[8] * local_24[8];
                    fVar1 = *(float*)(ebx + 4);
                    uVar4 = ((uint32_t)uVar5 << 16) |
                            (uint16_t)(((uint16_t)(fVar3 < fVar1) << 8) |
                                       ((uint16_t)(std::isnan(fVar3) || std::isnan(fVar1)) << 10) |
                                       ((uint16_t)(fVar3 == fVar1) << 14));
                    if ((std::isnan(fVar3) || std::isnan(fVar1)) ||
                        (fVar3 < fVar1) == (fVar3 == fVar1)) {
                        return uVar4;
                    }
                }
            }
        }
    }
    return (uVar4 & 0xffffff00u) | 1u;
}

// 0x50ba40 — observed shape
// Table store keyed by vtable slot +0x34: releases any previous occupant of
// self+8+key*4 and stores param_1 with an incremented reference count.
void FUN_0050ba40(void* self_in_ECX, int* param_1)
{
    int in_ECX = (int)(uintptr_t)self_in_ECX;
    int* piVar1;
    int* piVar2;
    int iVar3;

    if (param_1 != (int*)0x0) {
        iVar3 = reinterpret_cast<int (*)(void)>(vtable_slot(param_1, 0x34))();
        piVar2 = *(int**)((char*)(uintptr_t)(in_ECX + 8) + iVar3 * 4);
        if (piVar2 != param_1) {
            if (piVar2 != (int*)0x0) {
                piVar1 = piVar2 + 1;
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    vtable_call_slot0(piVar2, 1);
                }
            }
            *(int**)((char*)(uintptr_t)(in_ECX + 8) + iVar3 * 4) = param_1;
            param_1[1] = param_1[1] + 1;
        }
    }
    return;
}

// 0x50ba80 — observed shape
// Clears two references at +0 and +4 (nulling each slot), zeroes +8/+0xc, then
// releases the +4 and +0 references again (observed redundant second pass).
void FUN_0050ba80(void* self_in_ESI)
{
    int* unaff_ESI = (int*)self_in_ESI;
    int* piVar1;
    uint32_t* puVar2;

    puVar2 = (uint32_t*)(uintptr_t)*unaff_ESI;
    if (puVar2 != (uint32_t*)0x0) {
        piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            vtable_call_slot0(puVar2, 1);
        }
        *unaff_ESI = 0;
    }
    puVar2 = (uint32_t*)(uintptr_t)unaff_ESI[1];
    if (puVar2 != (uint32_t*)0x0) {
        piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            vtable_call_slot0(puVar2, 1);
        }
        unaff_ESI[1] = 0;
    }
    unaff_ESI[2] = 0;
    unaff_ESI[3] = 0;
    puVar2 = (uint32_t*)(uintptr_t)unaff_ESI[1];
    if (puVar2 != (uint32_t*)0x0) {
        piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            vtable_call_slot0(puVar2, 1);
        }
    }
    puVar2 = (uint32_t*)(uintptr_t)*unaff_ESI;
    if (puVar2 != (uint32_t*)0x0) {
        piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            vtable_call_slot0(puVar2, 1);
        }
    }
    return;
}

// 0x50baf0 — observed shape
// Re-binds a reference-counted resource: resets +0x10, releases +4 and +0, stores
// param_1 at +0xc, resolves param_2 through FUN_0054c210 into +0; on failure calls
// the device vtable slot +0x14 and retries the lookup.
void FUN_0050baf0(void* self_in_ESI, int param_1, uint32_t param_2)
{
    int* unaff_ESI = (int*)self_in_ESI;
    uint32_t* puVar1;
    uint32_t* puVar2;
    int* piVar3;

    unaff_ESI[4] = 0;
    puVar1 = (uint32_t*)(uintptr_t)unaff_ESI[1];
    if (puVar1 != (uint32_t*)0x0) {
        piVar3 = (int*)(puVar1 + 1);
        *piVar3 = *piVar3 + -1;
        if (*piVar3 == 0) {
            vtable_call_slot0(puVar1, 1);
        }
        unaff_ESI[1] = 0;
    }
    puVar1 = (uint32_t*)(uintptr_t)*unaff_ESI;
    unaff_ESI[2] = 0;
    if (puVar1 != (uint32_t*)0x0) {
        piVar3 = (int*)(puVar1 + 1);
        *piVar3 = *piVar3 + -1;
        if (*piVar3 == 0) {
            vtable_call_slot0(puVar1, 1);
        }
        *unaff_ESI = 0;
    }
    unaff_ESI[3] = param_1;
    puVar2 = (uint32_t*)FUN_0054c210(param_2);
    puVar1 = (uint32_t*)(uintptr_t)*unaff_ESI;
    if (puVar1 != puVar2) {
        if (puVar1 != (uint32_t*)0x0) {
            piVar3 = (int*)(puVar1 + 1);
            *piVar3 = *piVar3 + -1;
            if (*piVar3 == 0) {
                vtable_call_slot0(puVar1, 1);
            }
        }
        *unaff_ESI = (int)(uintptr_t)puVar2;
        if (puVar2 == (uint32_t*)0x0) {
            goto LAB_0050bb68;
        }
        puVar2[1] = puVar2[1] + 1;
    }
    if (*unaff_ESI != 0) {
        return;
    }
LAB_0050bb68:
    if (DAT_008ea08c == 0) {
        piVar3 = (int*)0x0;
    } else {
        piVar3 = *(int**)(uintptr_t)(DAT_00727c30 + 0x60);
    }
    reinterpret_cast<void (*)(int*)>(vtable_slot(piVar3, 0x14))(piVar3);
    puVar2 = (uint32_t*)FUN_0054c210(param_2);
    puVar1 = (uint32_t*)(uintptr_t)*unaff_ESI;
    if (puVar1 != puVar2) {
        if (puVar1 != (uint32_t*)0x0) {
            piVar3 = (int*)(puVar1 + 1);
            *piVar3 = *piVar3 + -1;
            if (*piVar3 == 0) {
                vtable_call_slot0(puVar1, 1);
            }
        }
        *unaff_ESI = (int)(uintptr_t)puVar2;
        if (puVar2 != (uint32_t*)0x0) {
            puVar2[1] = puVar2[1] + 1;
        }
    }
    return;
}

// 0x50bbc0 — observed shape
// Accumulates param_1 into self+0x10 while no callback is installed at +0xc; when
// one is installed it runs the device vtable +0x40/+0x74 sequences around the
// callback at +0xc. The pushed return-address immediates (0x50bbeb..) are stack
// artifacts the provider keeps as locals.
void FUN_0050bbc0(void* self_in_ESI, float param_1)
{
    uint32_t* unaff_ESI = (uint32_t*)self_in_ESI;
    uint32_t uStack_18;
    uint8_t* puStack_14;
    uint32_t uStack_10;
    uint32_t uStack_c;
    uint32_t uStack_8;

    if (unaff_ESI[3] == 0) {
        puStack_14 = (uint8_t*)(uintptr_t)(param_1 + (float)unaff_ESI[4]);
        uStack_10 = 1;
        unaff_ESI[4] = (uint32_t)(uintptr_t)puStack_14;
        uStack_18 = 0x50bbeb;
        FUN_00533d10();
        uStack_10 = *unaff_ESI;
        puStack_14 = (uint8_t*)0x50bbf9;
        reinterpret_cast<void (*)(void)>(vtable_slot(DAT_008ea08c, 0x40))();
        uStack_10 = 0;
        uStack_c = 0;
        uStack_8 = 0;
        uStack_18 = 0x50bc1f;
        puStack_14 = (uint8_t*)&uStack_10;
        reinterpret_cast<void (*)(void)>(vtable_slot(DAT_008ea08c, 0x74))();
        uStack_18 = 5;
        FUN_00535de0();
        uStack_18 = 0x50bc31;
        reinterpret_cast<void (*)(void)>(vtable_slot((void*)(uintptr_t)unaff_ESI[2], 0x70))();
        uStack_18 = 0;
        reinterpret_cast<void (*)(void)>(vtable_slot(DAT_008ea08c, 0x40))();
        uStack_18 = 0;
        puStack_14 = (uint8_t*)0x0;
        uStack_10 = 0;
        reinterpret_cast<void (*)(uint32_t*)>(vtable_slot(DAT_008ea08c, 0x74))(&uStack_18);
        return;
    }
    uStack_10 = *unaff_ESI;
    puStack_14 = (uint8_t*)0x50bc78;
    reinterpret_cast<void (*)(void)>(vtable_slot(DAT_008ea08c, 0x40))();
    puStack_14 = (uint8_t*)0x50bc7b;
    reinterpret_cast<void (*)(void)>(static_cast<uintptr_t>(unaff_ESI[3]))();
    puStack_14 = (uint8_t*)0x0;
    uStack_18 = 0x50bc88;
    reinterpret_cast<void (*)(void)>(vtable_slot(DAT_008ea08c, 0x40))();
    return;
}

// 0x50bc90 — observed shape
// Looks up two primitives by id (vtable +0x38 gathers 3 dwords, +0x34 returns the
// stride), fills local_2c (2,2,3, y, x, y2) from both objects' +0x28 descriptors and
// issues two device vtable +0x88 blits. AL is a decompiler register artifact used
// as the shift count.
void FUN_0050bc90(void* self_in_ECX)
{
    uint32_t uVar1;
    uint32_t uVar2;
    uint8_t in_AL; // decompiler register artifact
    uint32_t uVar3;
    int* piVar4;
    int iVar5;
    int* in_ECX = (int*)self_in_ECX;
    int* piVar6;
    int* piVar7;
    int* piStack_30;
    int local_2c[6];
    int iStack_14;
    uint32_t uStack_10;
    uint32_t uStack_c;
    int iStack_8;
    int iStack_4;

    local_2c[1] = 2;
    local_2c[0] = 2;
    local_2c[2] = 3;
    uVar3 = reinterpret_cast<uint32_t (*)(void*, int*)>(vtable_slot(in_ECX, 0x38))(DAT_008ea08c, local_2c);
    uVar3 = reinterpret_cast<uint32_t (*)(uint32_t)>(vtable_slot(in_ECX, 0x34))(uVar3 >> (in_AL & 0x1f));
    piVar4 = (int*)FUN_0054c210(uVar3 >> (in_AL & 0x1f));
    if (piVar4 == (int*)0x0) {
        if (DAT_008ea08c == 0) {
            piVar4 = (int*)0x0;
        } else {
            piVar4 = *(int**)(uintptr_t)(DAT_00727c30 + 0x60);
        }
        reinterpret_cast<void (*)(int*)>(vtable_slot(piVar4, 0x14))(piVar4);
        uVar3 = reinterpret_cast<uint32_t (*)(void*, int**)>(vtable_slot(in_ECX, 0x38))(DAT_008ea08c, &piStack_30);
        uVar3 = reinterpret_cast<uint32_t (*)(uint32_t)>(vtable_slot(in_ECX, 0x34))(uVar3 >> (in_AL & 0x1f));
        piVar4 = (int*)FUN_0054c210(uVar3 >> (in_AL & 0x1f));
        if (piVar4 == (int*)0x0) {
            return;
        }
    }
    piStack_30 = piVar4 + 1;
    *piStack_30 = *piStack_30 + 1;
    local_2c[4] = 0;
    local_2c[3] = 0;
    iStack_14 = reinterpret_cast<int (*)(void)>(vtable_slot(in_ECX, 0x38))();
    iStack_14 = iStack_14 + -1;
    local_2c[5] = reinterpret_cast<int (*)(void)>(vtable_slot(in_ECX, 0x34))();
    local_2c[5] = local_2c[5] + -1;
    uStack_c = 0;
    uStack_10 = 0;
    iStack_4 = reinterpret_cast<int (*)(void)>(vtable_slot(piVar4, 0x38))();
    iStack_4 = iStack_4 + -1;
    iStack_8 = reinterpret_cast<int (*)(void)>(vtable_slot(piVar4, 0x34))();
    iStack_8 = iStack_8 + -1;
    iVar5 = reinterpret_cast<int (*)(void)>(
        vtable_slot((void*)(uintptr_t)in_ECX[0xb], 0x28))();
    uVar1 = *(uint32_t*)(uintptr_t)(iVar5 + 0xc);
    iVar5 = reinterpret_cast<int (*)(void)>(
        vtable_slot((void*)(uintptr_t)piVar4[0xb], 0x28))();
    uVar2 = *(uint32_t*)(uintptr_t)(iVar5 + 0xc);
    if (DAT_008ea08c == 0) {
        piVar6 = (int*)0x0;
    } else {
        piVar6 = *(int**)(uintptr_t)(DAT_00727c30 + 0x60);
    }
    reinterpret_cast<void (*)(int*, uint32_t, int*, uint32_t, uint32_t*, int)>(
        vtable_slot(piVar6, 0x88))(piVar6, uVar1, local_2c + 3, uVar2, &uStack_10, 2);
    // local_2c - 3 aliases the piStack_30 slot on the observed stack frame.
    piVar7 = local_2c + -3;
    reinterpret_cast<void (*)(int*, uint32_t, int*, uint32_t, int*, int)>(
        vtable_slot(piVar6, 0x88))(piVar6, uVar2, local_2c + 1, uVar1, piVar7, 2);
    *piVar7 = *piVar7 + -1;
    if (*piVar7 == 0) {
        vtable_call_slot0(piVar4, 1);
    }
    return;
}

// 0x50be00 — observed shape
// Constructor for the 0x71169c table: stores mode (+0x2c), capacity (+4, 16-bit),
// element count (+8), zeroes the 16-bit counters at +0x18..+0x1e, allocates the
// key->index table (capacity*4, filled with 0xffffffff), the reverse table
// (capacity*2) and per-mode storage (mode 0: count*6; mode 1: count*4 + count even;
// mode 2: count*0x40 + count even).
void FUN_0050be00(void* self_in_ESI, int param_1, uint16_t in_AX, uint32_t in_ECX)
{
    uint32_t* unaff_ESI = (uint32_t*)self_in_ESI;
    uint32_t* puVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    int iVar4;

    *unaff_ESI = (uint32_t)(uintptr_t)&PTR_FUN_0071169c;
    unaff_ESI[0xb] = (uint32_t)param_1;
    *(uint16_t*)(unaff_ESI + 1) = in_AX;
    unaff_ESI[2] = in_ECX;
    *(uint16_t*)(unaff_ESI + 6) = 0;
    *(uint16_t*)((char*)unaff_ESI + 0x1a) = 0;
    *(uint16_t*)((char*)unaff_ESI + 0x1e) = 0;
    *(uint16_t*)(unaff_ESI + 7) = 0;
    unaff_ESI[0xc] = 0;
    puVar1 = (uint32_t*)(uintptr_t)thunk_FUN_00533c78((uint32_t)in_AX << 2);
    unaff_ESI[3] = (uint32_t)(uintptr_t)puVar1;
    for (uVar3 = (uint32_t)*(uint16_t*)(unaff_ESI + 1); uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar1 = 0xffffffff;
        puVar1 = puVar1 + 1;
    }
    // Observed zero-trip loop: the provider initialises the counter to 0.
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
        *(uint8_t*)puVar1 = 0xff;
        puVar1 = (uint32_t*)((char*)puVar1 + 1);
    }
    uVar2 = (uint32_t)(uintptr_t)thunk_FUN_00533c78((uint32_t)*(uint16_t*)(unaff_ESI + 1) << 1);
    unaff_ESI[4] = uVar2;
    if (param_1 == 0) {
        uVar2 = (uint32_t)(uintptr_t)thunk_FUN_00533c78(unaff_ESI[2] * 6);
        unaff_ESI[5] = uVar2;
        unaff_ESI[8] = 0;
    } else {
        if (param_1 == 1) {
            uVar2 = (uint32_t)(uintptr_t)thunk_FUN_00533c78(unaff_ESI[2] << 2);
            unaff_ESI[5] = uVar2;
            uVar2 = (uint32_t)(uintptr_t)thunk_FUN_00533c78(unaff_ESI[2] & 0xfffffffe);
            unaff_ESI[8] = uVar2;
            return;
        }
        if (param_1 == 2) {
            uVar2 = (uint32_t)(uintptr_t)thunk_FUN_00533c78(unaff_ESI[2] << 6);
            unaff_ESI[5] = uVar2;
            uVar2 = (uint32_t)(uintptr_t)thunk_FUN_00533c78(unaff_ESI[2] & 0xfffffffe);
            unaff_ESI[8] = uVar2;
            return;
        }
    }
    return;
}

// 0x50bef0 — observed shape
// Destructor: reinstalls vtable 0x71169c and frees the four owned buffers at
// +0x10, +0xc, +0x14 and +0x20 (nulling each).
void FUN_0050bef0(void* self_in_ESI)
{
    uint32_t* unaff_ESI = (uint32_t*)self_in_ESI;

    *unaff_ESI = (uint32_t)(uintptr_t)&PTR_FUN_0071169c;
    if ((void*)(uintptr_t)unaff_ESI[4] != (void*)0x0) {
        operator_delete__((void*)(uintptr_t)unaff_ESI[4]);
        unaff_ESI[4] = 0;
    }
    if ((void*)(uintptr_t)unaff_ESI[3] != (void*)0x0) {
        operator_delete__((void*)(uintptr_t)unaff_ESI[3]);
        unaff_ESI[3] = 0;
    }
    if ((void*)(uintptr_t)unaff_ESI[5] != (void*)0x0) {
        operator_delete__((void*)(uintptr_t)unaff_ESI[5]);
        unaff_ESI[5] = 0;
    }
    if ((void*)(uintptr_t)unaff_ESI[8] != (void*)0x0) {
        operator_delete__((void*)(uintptr_t)unaff_ESI[8]);
        unaff_ESI[8] = 0;
    }
    return;
}

// 0x50bf50 — observed shape
// Maps four vertex indices of the quad to slot ids (allocating new ids and appending
// them to the index map when the slot holds 0xffffffff), then appends the two
// triangles according to the primitive mode at +0x2c (0/2: fan with 7 indices;
// 1: strip with winding chosen by param_1, plus the degenerate-skip bookkeeping at
// +0x1c/+0x1e/+0x20). Caches the two id pairs in +0x24/+0x28.
void FUN_0050bf50(void* self_in_EAX, void* self2_in_ECX, char param_1)
{
    int* eax = (int*)self_in_EAX;
    uint16_t* ecx = (uint16_t*)self2_in_ECX;
    uint32_t* puVar1;
    int16_t* psVar2;
    uint16_t uVar3;
    int iVar4;
    int16_t sVar5;
    int16_t sVar6;
    int16_t sVar7;
    int16_t sVar8;
    uint32_t local_8;
    uint32_t local_4;

    uVar3 = ecx[0];
    puVar1 = (uint32_t*)(uintptr_t)(*(int*)((char*)eax + 0xc) + (uint32_t)uVar3 * 4);
    if (*puVar1 == 0xffffffff) {
        *puVar1 = (uint32_t)*(uint16_t*)((char*)eax + 0x18);
        *(uint16_t*)(uintptr_t)(*(int*)((char*)eax + 0x10) +
                                (uint32_t)*(uint16_t*)((char*)eax + 0x18) * 2) = uVar3;
        *(int16_t*)((char*)eax + 0x18) = *(int16_t*)((char*)eax + 0x18) + 1;
        sVar5 = *(int16_t*)((char*)eax + 0x18) + -1;
    } else {
        sVar5 = (int16_t)*puVar1;
    }
    uVar3 = ecx[1];
    puVar1 = (uint32_t*)(uintptr_t)(*(int*)((char*)eax + 0xc) + (uint32_t)uVar3 * 4);
    if (*puVar1 == 0xffffffff) {
        *puVar1 = (uint32_t)*(uint16_t*)((char*)eax + 0x18);
        *(uint16_t*)(uintptr_t)(*(int*)((char*)eax + 0x10) +
                                (uint32_t)*(uint16_t*)((char*)eax + 0x18) * 2) = uVar3;
        *(int16_t*)((char*)eax + 0x18) = *(int16_t*)((char*)eax + 0x18) + 1;
        sVar6 = *(int16_t*)((char*)eax + 0x18) + -1;
    } else {
        sVar6 = (int16_t)*puVar1;
    }
    uVar3 = ecx[2];
    puVar1 = (uint32_t*)(uintptr_t)(*(int*)((char*)eax + 0xc) + (uint32_t)uVar3 * 4);
    local_8 = ((uint32_t)(uint16_t)sVar6 << 16) | (uint32_t)(uint16_t)sVar5;
    if (*puVar1 == 0xffffffff) {
        *puVar1 = (uint32_t)*(uint16_t*)((char*)eax + 0x18);
        *(uint16_t*)(uintptr_t)(*(int*)((char*)eax + 0x10) +
                                (uint32_t)*(uint16_t*)((char*)eax + 0x18) * 2) = uVar3;
        *(int16_t*)((char*)eax + 0x18) = *(int16_t*)((char*)eax + 0x18) + 1;
        sVar7 = *(int16_t*)((char*)eax + 0x18) + -1;
    } else {
        sVar7 = (int16_t)*puVar1;
    }
    uVar3 = ecx[3];
    puVar1 = (uint32_t*)(uintptr_t)(*(int*)((char*)eax + 0xc) + (uint32_t)uVar3 * 4);
    if (*puVar1 == 0xffffffff) {
        *puVar1 = (uint32_t)*(uint16_t*)((char*)eax + 0x18);
        *(uint16_t*)(uintptr_t)(*(int*)((char*)eax + 0x10) +
                                (uint32_t)*(uint16_t*)((char*)eax + 0x18) * 2) = uVar3;
        *(int16_t*)((char*)eax + 0x18) = *(int16_t*)((char*)eax + 0x18) + 1;
        sVar8 = *(int16_t*)((char*)eax + 0x18) + -1;
    } else {
        sVar8 = (int16_t)*puVar1;
    }
    iVar4 = *(int*)((char*)eax + 0x2c);
    local_4 = ((uint32_t)(uint16_t)sVar8 << 16) | (uint32_t)(uint16_t)sVar7;
    if (iVar4 == 0) {
LAB_0050c057:
        *(int16_t*)(uintptr_t)(*(int*)((char*)eax + 0x14) +
                              (uint32_t)*(uint16_t*)((char*)eax + 0x1a) * 2) = sVar5;
        *(int16_t*)((char*)eax + 0x1a) = *(int16_t*)((char*)eax + 0x1a) + 1;
        if (param_1 == '\0') {
            *(int16_t*)(uintptr_t)(*(int*)((char*)eax + 0x14) +
                                  (uint32_t)*(uint16_t*)((char*)eax + 0x1a) * 2) = sVar6;
            *(int16_t*)((char*)eax + 0x1a) = *(int16_t*)((char*)eax + 0x1a) + 1;
            *(int16_t*)(uintptr_t)(*(int*)((char*)eax + 0x14) +
                                  (uint32_t)*(uint16_t*)((char*)eax + 0x1a) * 2) = sVar7;
            *(int16_t*)((char*)eax + 0x1a) = *(int16_t*)((char*)eax + 0x1a) + 1;
            *(int16_t*)(uintptr_t)(*(int*)((char*)eax + 0x14) +
                                  (uint32_t)*(uint16_t*)((char*)eax + 0x1a) * 2) = sVar6;
        } else {
            *(int16_t*)(uintptr_t)(*(int*)((char*)eax + 0x14) +
                                  (uint32_t)*(uint16_t*)((char*)eax + 0x1a) * 2) = sVar6;
            *(int16_t*)((char*)eax + 0x1a) = *(int16_t*)((char*)eax + 0x1a) + 1;
            *(int16_t*)(uintptr_t)(*(int*)((char*)eax + 0x14) +
                                  (uint32_t)*(uint16_t*)((char*)eax + 0x1a) * 2) = sVar8;
            *(int16_t*)((char*)eax + 0x1a) = *(int16_t*)((char*)eax + 0x1a) + 1;
            *(int16_t*)(uintptr_t)(*(int*)((char*)eax + 0x14) +
                                  (uint32_t)*(uint16_t*)((char*)eax + 0x1a) * 2) = sVar5;
        }
        *(int16_t*)((char*)eax + 0x1a) = *(int16_t*)((char*)eax + 0x1a) + 1;
        *(int16_t*)(uintptr_t)(*(int*)((char*)eax + 0x14) +
                              (uint32_t)*(uint16_t*)((char*)eax + 0x1a) * 2) = sVar8;
        *(int16_t*)((char*)eax + 0x1a) = *(int16_t*)((char*)eax + 0x1a) + 1;
        *(int16_t*)(uintptr_t)(*(int*)((char*)eax + 0x14) +
                              (uint32_t)*(uint16_t*)((char*)eax + 0x1a) * 2) = sVar7;
    } else {
        if (iVar4 != 1) {
            if (iVar4 != 2) {
                goto LAB_0050c1b3;
            }
            goto LAB_0050c057;
        }
        if ((sVar5 == *(int16_t*)((char*)eax + 0x26)) &&
            (sVar7 == *(int16_t*)((char*)eax + 0x2a))) {
            *(int16_t*)((char*)eax + 0x1c) = *(int16_t*)((char*)eax + 0x1c) + 2;
            psVar2 = (int16_t*)(uintptr_t)(*(int*)((char*)eax + 0x20) + -2 +
                                           (uint32_t)*(uint16_t*)((char*)eax + 0x1e) * 2);
            *psVar2 = *psVar2 + 2;
        } else {
            if (*(int16_t*)((char*)eax + 0x1c) == 0) {
                *(uint16_t*)((char*)eax + 0x1c) = 2;
                *(uint16_t*)((char*)eax + 0x1e) = 1;
                **(uint16_t**)((char*)eax + 0x20) = 4;
                *(int16_t*)(uintptr_t)(*(int*)((char*)eax + 0x14) +
                                      (uint32_t)*(uint16_t*)((char*)eax + 0x1a) * 2) = sVar7;
            } else {
                *(int16_t*)((char*)eax + 0x1c) = *(int16_t*)((char*)eax + 0x1c) + 6;
                psVar2 = (int16_t*)(uintptr_t)(*(int*)((char*)eax + 0x20) + -2 +
                                               (uint32_t)*(uint16_t*)((char*)eax + 0x1e) * 2);
                *psVar2 = *psVar2 + 6;
                *(uint16_t*)(uintptr_t)(*(int*)((char*)eax + 0x14) +
                                       (uint32_t)*(uint16_t*)((char*)eax + 0x1a) * 2) =
                    *(uint16_t*)((char*)eax + 0x26);
                *(int16_t*)((char*)eax + 0x1a) = *(int16_t*)((char*)eax + 0x1a) + 1;
                *(int16_t*)(uintptr_t)(*(int*)((char*)eax + 0x14) +
                                      (uint32_t)*(uint16_t*)((char*)eax + 0x1a) * 2) = sVar7;
                *(int16_t*)((char*)eax + 0x1a) = *(int16_t*)((char*)eax + 0x1a) + 1;
                *(int16_t*)(uintptr_t)(*(int*)((char*)eax + 0x14) +
                                      (uint32_t)*(uint16_t*)((char*)eax + 0x1a) * 2) = sVar7;
            }
            *(int16_t*)((char*)eax + 0x1a) = *(int16_t*)((char*)eax + 0x1a) + 1;
            *(int16_t*)(uintptr_t)(*(int*)((char*)eax + 0x14) +
                                  (uint32_t)*(uint16_t*)((char*)eax + 0x1a) * 2) = sVar5;
            *(int16_t*)((char*)eax + 0x1a) = *(int16_t*)((char*)eax + 0x1a) + 1;
        }
        *(int16_t*)(uintptr_t)(*(int*)((char*)eax + 0x14) +
                              (uint32_t)*(uint16_t*)((char*)eax + 0x1a) * 2) = sVar8;
        *(int16_t*)((char*)eax + 0x1a) = *(int16_t*)((char*)eax + 0x1a) + 1;
        *(int16_t*)(uintptr_t)(*(int*)((char*)eax + 0x14) +
                              (uint32_t)*(uint16_t*)((char*)eax + 0x1a) * 2) = sVar6;
    }
    *(int16_t*)((char*)eax + 0x1a) = *(int16_t*)((char*)eax + 0x1a) + 1;
LAB_0050c1b3:
    *(uint32_t*)((char*)eax + 0x24) = local_8;
    *(uint32_t*)((char*)eax + 0x28) = local_4;
    return;
}

// 0x50c1d0 — observed shape
// Bakes a quad mesh: allocates two per-vertex transform arrays (count*0xc), an
// optional per-frame array (count*param_5*8), copies the index list (count2 words)
// and every vertex from param_2 (object space) and param_3 (shadow space), fills the
// per-frame UV/position table indexed by slot stride param_1, then dispatches on the
// primitive mode at +0x2c — 0: FUN_00551810(count, ...), 1: FUN_005473e0 with the
// copied index block, other: stores param_5 unchanged. The resulting handle is kept
// at +0x30 (0 on allocation failure).
uint32_t FUN_0050c1d0(void* self_in_ECX, int param_1, int param_2, int param_3, int param_4,
                      uint32_t param_5)
{
    int in_ECX = (int)(uintptr_t)self_in_ECX;
    uint16_t uVar1;
    uint16_t uVar1b;
    int iVar2;
    uint32_t* puVar3;
    uint32_t uVar4;
    uint32_t* puVar5;
    int iVar6;
    uint32_t iVar7;
    uint32_t* puVar8;
    int iVar9;
    uint32_t* puVar10;
    uint32_t* local_18;
    int local_14;
    int local_10;

    uVar1 = *(uint16_t*)(uintptr_t)(in_ECX + 0x18);
    if (uVar1 == 0) {
        return 0;
    }
    local_14 = FUN_00533c78((uint32_t)uVar1 * 0xc);
    if (local_14 == 0) {
        local_14 = 0;
    } else {
        FUN_004127b0((void*)(uintptr_t)local_14, 0xc, (uint32_t)uVar1, &LAB_005cea70);
    }
    uVar1 = *(uint16_t*)(uintptr_t)(in_ECX + 0x18);
    local_18 = (uint32_t*)(uintptr_t)thunk_FUN_00533c78((uint32_t)uVar1 * 0xc);
    if (local_18 == (uint32_t*)0x0) {
        local_18 = (uint32_t*)0x0;
    } else {
        FUN_004127b0(local_18, 0xc, (uint32_t)uVar1, &LAB_005cea70);
    }
    iVar6 = 0;
    if (param_5 != 0) {
        iVar7 = (uint32_t)*(uint16_t*)(uintptr_t)(in_ECX + 0x18) * param_5;
        iVar2 = FUN_00533c78(iVar7 * 8);
        if (iVar2 != 0) {
            FUN_004127b0((void*)(uintptr_t)iVar2, 8, iVar7, &LAB_005cea70);
            iVar6 = iVar2;
        }
    }
    puVar3 = (uint32_t*)(uintptr_t)thunk_FUN_00533c78((uint32_t)*(uint16_t*)(uintptr_t)(in_ECX + 0x1a) << 1);
    uVar1b = *(uint16_t*)(uintptr_t)(in_ECX + 0x1a);
    puVar5 = *(uint32_t**)(uintptr_t)(in_ECX + 0x14);
    puVar10 = puVar3;
    for (uVar4 = (uint32_t)(uVar1b >> 1); uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar10 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar10 = puVar10 + 1;
    }
    for (iVar7 = (uint32_t)(uVar1b & 1) << 1; iVar7 != 0; iVar7 = iVar7 - 1) {
        *(uint8_t*)puVar10 = *(uint8_t*)puVar5;
        puVar5 = (uint32_t*)((char*)puVar5 + 1);
        puVar10 = (uint32_t*)((char*)puVar10 + 1);
    }
    iVar2 = 0;
    if (*(int16_t*)(uintptr_t)(in_ECX + 0x18) != 0) {
        puVar5 = local_18;
        do {
            puVar10 = (uint32_t*)(uintptr_t)(
                param_2 + (uint32_t)*(uint16_t*)(uintptr_t)(*(int*)(uintptr_t)(in_ECX + 0x10) + iVar2 * 2) * 0xc);
            puVar8 = (uint32_t*)(uintptr_t)((local_14 - (int)(uintptr_t)local_18) + (int)(uintptr_t)puVar5);
            *puVar8 = *puVar10;
            puVar8[1] = puVar10[1];
            puVar8[2] = puVar10[2];
            puVar10 = (uint32_t*)(uintptr_t)(
                param_3 + (uint32_t)*(uint16_t*)(uintptr_t)(*(int*)(uintptr_t)(in_ECX + 0x10) + iVar2 * 2) * 0xc);
            *puVar5 = *puVar10;
            puVar5[1] = puVar10[1];
            puVar5[2] = puVar10[2];
            uVar4 = 0;
            if (param_5 != 0) {
                local_10 = 0;
                do {
                    iVar9 = (uint32_t)*(uint16_t*)(uintptr_t)(*(int*)(uintptr_t)(in_ECX + 0x10) + iVar2 * 2) +
                            local_10;
                    iVar7 = (uint32_t)*(uint16_t*)(uintptr_t)(in_ECX + 0x18) * uVar4 + (uint32_t)iVar2;
                    *(uint32_t*)(uintptr_t)(iVar6 + (int)iVar7 * 8) =
                        *(uint32_t*)(uintptr_t)(param_4 + iVar9 * 8);
                    *(uint32_t*)(uintptr_t)(iVar6 + 4 + (int)iVar7 * 8) =
                        *(uint32_t*)(uintptr_t)(param_4 + 4 + iVar9 * 8);
                    local_10 = local_10 + param_1;
                    uVar4 = uVar4 + 1;
                } while (uVar4 < param_5);
            }
            iVar2 = iVar2 + 1;
            puVar5 = puVar5 + 3;
        } while (iVar2 < (int)(uint32_t)*(uint16_t*)(uintptr_t)(in_ECX + 0x18));
    }
    if (*(int*)(uintptr_t)(in_ECX + 0x2c) == 0) {
        iVar2 = FUN_00533c78(0xcc);
        if (iVar2 != 0) {
            uVar4 = FUN_00551810(*(uint16_t*)(uintptr_t)(in_ECX + 0x18), local_14, local_18, 0,
                                 iVar6, param_5, 0,
                                 (uint32_t)*(uint16_t*)(uintptr_t)(in_ECX + 0x1a) / 3, puVar3);
            *(uint32_t*)(uintptr_t)(in_ECX + 0x30) = uVar4;
            return uVar4;
        }
    } else {
        if (*(int*)(uintptr_t)(in_ECX + 0x2c) != 1) {
            *(uint32_t*)(uintptr_t)(in_ECX + 0x30) = param_5;
            return param_5;
        }
        puVar8 = (uint32_t*)(uintptr_t)thunk_FUN_00533c78(
            (uint32_t)*(uint16_t*)(uintptr_t)(in_ECX + 0x1e) << 1);
        uVar1 = *(uint16_t*)(uintptr_t)(in_ECX + 0x1e);
        puVar5 = *(uint32_t**)(uintptr_t)(in_ECX + 0x20);
        puVar10 = puVar8;
        for (uVar4 = (uint32_t)(uVar1 >> 1); uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar10 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar10 = puVar10 + 1;
        }
        for (iVar2 = (int)(((uint32_t)(uVar1 & 1)) << 1); iVar2 != 0; iVar2 = iVar2 + -1) {
            *(uint8_t*)puVar10 = *(uint8_t*)puVar5;
            puVar5 = (uint32_t*)((char*)puVar5 + 1);
            puVar10 = (uint32_t*)((char*)puVar10 + 1);
        }
        iVar2 = FUN_00533c78(0xcc);
        if (iVar2 != 0) {
            uVar4 = FUN_005473e0(*(uint16_t*)(uintptr_t)(in_ECX + 0x18), local_14, local_18, 0,
                                 iVar6, param_5, 0,
                                 *(uint16_t*)(uintptr_t)(in_ECX + 0x1c),
                                 *(uint16_t*)(uintptr_t)(in_ECX + 0x1e), puVar8, puVar3);
            *(uint32_t*)(uintptr_t)(in_ECX + 0x30) = uVar4;
            return uVar4;
        }
    }
    *(uint32_t*)(uintptr_t)(in_ECX + 0x30) = 0;
    return 0;
}
