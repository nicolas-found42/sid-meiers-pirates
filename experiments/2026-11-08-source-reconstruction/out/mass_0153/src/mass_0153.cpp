//
// mass_0153.cpp — reconstruction batch mass_0153
// Target: Sid Meier's Pirates! (2004), PE32 i386
// Image: 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
//
// Each definition preserves the observed field offsets, constants,
// call order, return shape, and conditional structure of the Ghidra
// 12.2 pseudocode (analysis/pseudocode/functions/*.c).
//
// Register receivers (in_ECX) are modeled as an explicit `void* self`.
// Ghidra `in_ECX` typed as `int` addresses bytes, so byte offsets are
// written as (uint8_t*)self + off; `in_ECX` typed as a pointer indexes
// dwords and is kept as a uint32_t* over the same object.
//
#include <cstdint>
#include <cstddef>
#include <windows.h>

void operator_delete(void* ptr);
void operator_delete__(void* ptr);
extern int _stricmp(const char* a, const char* b);

extern void* PTR_FUN_006c309c;
extern void* PTR_FUN_006c30ac;
extern void* PTR_FUN_006c30c4;

extern uint32_t DAT_00727460[9];
extern uint32_t DAT_00727484[9];
extern uint32_t DAT_007178c8[9];
extern uint32_t DAT_007178a4[9];
extern uint32_t DAT_00717880[9];
extern uint32_t DAT_007178ec[9];
extern uint32_t DAT_0072745c;
extern uint32_t DAT_00717834;
extern uint32_t DAT_00717838;
extern uint32_t DAT_0071783c;

// Low-word temporary the decompiler models as an absolute read at 0x2.
// NEEDS_MANUAL: value is produced by the argument-elided stream call in
// FUN_0055c050; the listing gives no storage other than this symbol.
extern uint32_t uRam00000002;

extern void FUN_00546930();
extern void FUN_00546ad0();
extern void FUN_00513dc0();
extern int FUN_00533c78(int size);
extern int thunk_FUN_00533c78(int size);
extern int FUN_00539210(int32_t width, int32_t height, void* format, int flags);
extern void FUN_004127b0(int dst, int elemSize, int count, void* fill);
extern void FUN_004b10d0();
extern char FUN_0054aab0(void* format);
extern uint32_t FUN_0053a5a0(uint8_t channel, uint16_t length, int palette);
extern void FUN_004493d0(uint32_t palette);
extern uint8_t FUN_005f0ddc();

extern void LAB_0055af30(void);
extern void LAB_0055ba00(void);
extern void LAB_0055ba60(void);
extern void LAB_0055ba30(void);
extern void LAB_0055ba90(void);
extern void LAB_0055bb30(void);
extern void LAB_0055bae0(void);
extern void LAB_005cea70(void);

// Same-batch definitions used before their bodies.
void FUN_0055b050(void* self, uint8_t* param_1);
void FUN_0055b310(void* self, uint8_t* param_1);
void FUN_0055b4c0(void* self, uint8_t* param_1);
void FUN_0055b6e0(void* self, void* dst, uint32_t param_1, int param_2);
void FUN_0055bd40(void* self, int* param_1, uint32_t* param_2);
void FUN_0055be60(void* self, int* param_1);

// 0x55adf0 — observed shape: base-object init: vtable swap, zero fields at +0x1c/+0x20, critical section at +4, derived vtable, init call.
void FUN_0055adf0(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    in_ECX[0] = (uint32_t)&PTR_FUN_006c309c;
    in_ECX[7] = 0;
    in_ECX[8] = 0;
    InitializeCriticalSection((LPCRITICAL_SECTION)(in_ECX + 1));
    in_ECX[0] = (uint32_t)&PTR_FUN_006c30ac;
    FUN_00546930();
}

// 0x55ae20 — observed shape: destructor: derived/base vtable swaps, teardown call, DeleteCriticalSection at +4, conditional delete of receiver.
void FUN_0055ae20(void* self, uint8_t param_1) {
    uint32_t* in_ECX = (uint32_t*)self;
    in_ECX[0] = (uint32_t)&PTR_FUN_006c30ac;
    FUN_00546ad0();
    in_ECX[0] = (uint32_t)&PTR_FUN_006c309c;
    DeleteCriticalSection((LPCRITICAL_SECTION)(in_ECX + 1));
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
}

// 0x55b050 — observed shape: 6/5-bit palette expansion from two header bytes, then 8 nibble/bit-field palette lookups into a 0x20-stride dest, cursor at +8.
void FUN_0055b050(void* self, uint8_t* param_1) {
    uint8_t* base = (uint8_t*)self;
    uint32_t uVar1;
    uint32_t uVar2;
    uint32_t uVar4;
    uint32_t uVar5;
    uint8_t local_8[8];

    uint8_t* pbVar3 = *(uint8_t**)(base + 8);
    local_8[0] = *pbVar3;
    uVar4 = (uint32_t)local_8[0];
    *(uint8_t**)(base + 8) = pbVar3 + 1;
    local_8[1] = pbVar3[1];
    uVar5 = (uint32_t)local_8[1];
    *(uint8_t**)(base + 8) = pbVar3 + 2;
    if (uVar5 < uVar4) {
        uVar1 = uVar5 + uVar4 * 6;
        uVar2 = uVar1 / 7;
        local_8[2] = (uint8_t)((((uVar1 - uVar2) >> 1) + uVar2) >> 2);
        uVar1 = uVar4 * 5 + uVar5 * 2;
        uVar2 = uVar1 / 7;
        local_8[3] = (uint8_t)((((uVar1 - uVar2) >> 1) + uVar2) >> 2);
        uVar1 = uVar5 * 3 + uVar4 * 4;
        uVar2 = uVar1 / 7;
        local_8[4] = (uint8_t)((((uVar1 - uVar2) >> 1) + uVar2) >> 2);
        uVar1 = uVar4 * 3 + uVar5 * 4;
        uVar2 = uVar1 / 7;
        local_8[5] = (uint8_t)((((uVar1 - uVar2) >> 1) + uVar2) >> 2);
        uVar1 = uVar5 * 5 + uVar4 * 2;
        uVar2 = uVar1 / 7;
        uVar4 = uVar4 + uVar5 * 6;
        uVar5 = uVar4 / 7;
        local_8[6] = (uint8_t)((((uVar1 - uVar2) >> 1) + uVar2) >> 2);
        local_8[7] = (uint8_t)((((uVar4 - uVar5) >> 1) + uVar5) >> 2);
    }
    else {
        local_8[2] = (uint8_t)((uVar5 + uVar4 * 4) / 5);
        local_8[3] = (uint8_t)((uVar4 * 3 + uVar5 * 2) / 5);
        local_8[4] = (uint8_t)((uVar5 * 3 + uVar4 * 2) / 5);
        local_8[5] = (uint8_t)((uVar4 + uVar5 * 4) / 5);
        local_8[6] = 0;
        local_8[7] = 0xff;
    }
    *param_1 = local_8[pbVar3[2] & 7];
    param_1[4] = local_8[**(uint8_t**)(base + 8) >> 3 & 7];
    param_1[8] = local_8[((*(uint8_t**)(base + 8))[1] & 1) * 4 +
                        (uint32_t)(**(uint8_t**)(base + 8) >> 6)];
    param_1[0xc] = local_8[*(uint8_t*)(*(int*)(base + 8) + 1) >> 1 & 7];
    param_1[0x10] = local_8[*(uint8_t*)(*(int*)(base + 8) + 1) >> 4 & 7];
    param_1[0x14] = local_8[(*(uint8_t*)(*(int*)(base + 8) + 2) & 3) * 2 +
                            (uint32_t)(*(uint8_t*)(*(int*)(base + 8) + 1) >> 7)];
    param_1[0x18] = local_8[*(uint8_t*)(*(int*)(base + 8) + 2) >> 2 & 7];
    param_1[0x1c] = local_8[*(uint8_t*)(*(int*)(base + 8) + 2) >> 5];
    pbVar3 = (uint8_t*)(*(int*)(base + 8) + 3);
    *(uint8_t**)(base + 8) = pbVar3;
    param_1[0x20] = local_8[*pbVar3 & 7];
    param_1[0x24] = local_8[**(uint8_t**)(base + 8) >> 3 & 7];
    param_1[0x28] = local_8[((*(uint8_t**)(base + 8))[1] & 1) * 4 +
                            (uint32_t)(**(uint8_t**)(base + 8) >> 6)];
    param_1[0x2c] = local_8[*(uint8_t*)(*(int*)(base + 8) + 1) >> 1 & 7];
    param_1[0x30] = local_8[*(uint8_t*)(*(int*)(base + 8) + 1) >> 4 & 7];
    param_1[0x34] = local_8[(*(uint8_t*)(*(int*)(base + 8) + 2) & 3) * 2 +
                            (uint32_t)(*(uint8_t*)(*(int*)(base + 8) + 1) >> 7)];
    param_1[0x38] = local_8[*(uint8_t*)(*(int*)(base + 8) + 2) >> 2 & 7];
    param_1[0x3c] = local_8[*(uint8_t*)(*(int *)(base + 8) + 2) >> 5];
    *(int*)(base + 8) = *(int*)(base + 8) + 3;
}

// 0x55b310 — observed shape: two 16-bit 5/6/5 colors expanded into a 12-byte RGB palette, then 4x16-bit indirection groups per cursor byte.
void FUN_0055b310(void* self, uint8_t* param_1) {
    uint8_t* base = (uint8_t*)self;
    uint8_t bVar1;
    uint16_t* puVar2;
    int iVar3;
    uint16_t uVar4;
    uint16_t uVar5;
    int iVar6;
    // 12-byte palette; the Ghidra names local_c[0..5] then local_6..local_1
    // occupy indices 6..11 in declaration/stack order.
    uint8_t pal[12];

    puVar2 = *(uint16_t**)(base + 8);
    uVar4 = *puVar2;
    *(uint16_t**)(base + 8) = puVar2 + 1;
    uVar5 = puVar2[1];
    *(uint16_t**)(base + 8) = puVar2 + 2;
    pal[0] = (uint8_t)(uVar4 >> 8) & 0xf8;
    pal[2] = (uint8_t)(uVar4 << 3);
    pal[3] = (uint8_t)(uVar5 >> 8) & 0xf8;
    pal[5] = (uint8_t)(uVar5 << 3);
    pal[6] = (uint8_t)(((uint32_t)pal[3] + (uint32_t)pal[0] * 2) / 3);
    pal[1] = (uint8_t)(uVar4 >> 3) & 0xfe;
    pal[4] = (uint8_t)(uVar5 >> 3) & 0xfe;
    pal[7] = (uint8_t)(((uint32_t)pal[4] + (uint32_t)pal[1] * 2) / 3);
    pal[8] = (uint8_t)(((uint32_t)pal[5] + (uint32_t)pal[2] * 2) / 3);
    pal[9] = (uint8_t)(((uint32_t)pal[0] + (uint32_t)pal[3] * 2) / 3);
    pal[10] = (uint8_t)(((uint32_t)pal[1] + (uint32_t)pal[4] * 2) / 3);
    pal[11] = (uint8_t)(((uint32_t)pal[2] + (uint32_t)pal[5] * 2) / 3);
    iVar6 = 4;
    do {
        bVar1 = **(uint8_t**)(base + 8);
        iVar3 = (bVar1 & 3) * 3;
        param_1[0] = pal[iVar3];
        param_1[1] = pal[iVar3 + 1];
        param_1[2] = pal[iVar3 + 2];
        iVar3 = (bVar1 >> 2 & 3) * 3;
        param_1[4] = pal[iVar3];
        param_1[5] = pal[iVar3 + 1];
        param_1[6] = pal[iVar3 + 2];
        iVar3 = (bVar1 >> 4 & 3) * 3;
        param_1[8] = pal[iVar3];
        param_1[9] = pal[iVar3 + 1];
        param_1[10] = pal[iVar3 + 2];
        iVar3 = (uint32_t)(bVar1 >> 6) * 3;
        param_1[0xc] = pal[iVar3];
        bVar1 = pal[iVar3 + 2];
        param_1[0xd] = pal[iVar3 + 1];
        param_1[0xe] = bVar1;
        iVar6 = iVar6 + -1;
        *(int*)(base + 8) = *(int*)(base + 8) + 1;
        param_1 = param_1 + 0x10;
    } while (iVar6 != 0);
}

// 0x55b4c0 — observed shape: two 16-bit colors expanded into a 16-byte RGBA palette (alpha 0xff), gradient fill of the middle colors, then 4x packed nibbles per cursor byte.
void FUN_0055b4c0(void* self, uint8_t* param_1) {
    uint8_t* base = (uint8_t*)self;
    int iVar1;
    uint8_t bVar2;
    uint8_t bVar3;
    uint8_t bVar4;
    uint16_t* puVar5;
    uint16_t uVar6;
    uint16_t uVar7;
    uint32_t uVar8;
    int iVar9;
    // 16-byte RGBA palette; Ghidra names local_10[0..6] then local_9..local_1
    // for indices 7..15.
    uint8_t pal[16];

    puVar5 = *(uint16_t**)(base + 8);
    uVar6 = *puVar5;
    pal[3] = 0xff;
    pal[7] = 0xff;
    pal[11] = 0xff;
    *(uint16_t**)(base + 8) = puVar5 + 1;
    uVar7 = puVar5[1];
    *(uint16_t**)(base + 8) = puVar5 + 2;
    pal[0] = (uint8_t)(uVar6 >> 8) & 0xf8;
    pal[2] = (uint8_t)(uVar6 << 3);
    pal[4] = (uint8_t)(uVar7 >> 8) & 0xf8;
    pal[5] = (uint8_t)(uVar7 >> 3) & 0xfe;
    pal[1] = (uint8_t)(uVar6 >> 3) & 0xfe;
    pal[6] = (uint8_t)(uVar7 << 3);
    uVar8 = (uint32_t)pal[0];
    if (uVar7 < uVar6) {
        pal[8] = (uint8_t)(((uint32_t)pal[4] + uVar8 * 2) / 3);
        pal[9] = (uint8_t)(((uint32_t)pal[5] + (uint32_t)pal[1] * 2) / 3);
        pal[10] = (uint8_t)(((uint32_t)pal[6] + (uint32_t)pal[2] * 2) / 3);
        pal[12] = (uint8_t)((uVar8 + (uint32_t)pal[4] * 2) / 3);
        pal[13] = (uint8_t)(((uint32_t)pal[1] + (uint32_t)pal[5] * 2) / 3);
        // Listing writes the same byte twice; the second write is retained.
        pal[10] = (uint8_t)(((uint32_t)pal[2] + (uint32_t)pal[6] * 2) / 3);
        pal[15] = 0xff;
    }
    else {
        pal[8] = (uint8_t)((pal[4] + uVar8) >> 1);
        pal[9] = (uint8_t)(((uint32_t)pal[5] + (uint32_t)pal[1]) >> 1);
        pal[10] = (uint8_t)(((uint32_t)pal[6] + (uint32_t)pal[2]) >> 1);
        pal[12] = pal[8];
        pal[13] = pal[9];
        pal[15] = 0;
    }
    pal[14] = pal[10];
    iVar9 = 4;
    do {
        bVar2 = **(uint8_t**)(base + 8);
        iVar1 = (bVar2 & 3) * 4;
        param_1[0] = pal[(bVar2 & 3) * 4];
        param_1[1] = pal[iVar1 + 1];
        bVar3 = pal[iVar1 + 2];
        param_1[3] = pal[iVar1 + 3];
        param_1[2] = bVar3;
        uVar8 = bVar2 >> 2 & 3;
        iVar1 = uVar8 * 4;
        param_1[4] = pal[uVar8 * 4];
        param_1[5] = pal[iVar1 + 1];
        bVar3 = pal[iVar1 + 2];
        param_1[7] = pal[iVar1 + 3];
        iVar1 = (bVar2 >> 4 & 3) * 4;
        bVar4 = pal[iVar1];
        param_1[6] = bVar3;
        param_1[8] = bVar4;
        param_1[9] = pal[iVar1 + 1];
        bVar3 = pal[iVar1 + 2];
        param_1[0xb] = pal[iVar1 + 3];
        param_1[10] = bVar3;
        iVar1 = (uint32_t)(bVar2 >> 6) * 4;
        param_1[0xc] = pal[(uint32_t)(bVar2 >> 6) * 4];
        param_1[0xd] = pal[iVar1 + 1];
        bVar2 = pal[iVar1 + 2];
        param_1[0xf] = pal[iVar1 + 3];
        param_1[0xe] = bVar2;
        iVar9 = iVar9 + -1;
        *(int*)(base + 8) = *(int*)(base + 8) + 1;
        param_1 = param_1 + 0x10;
    } while (iVar9 != 0);
}

// 0x55b6e0 — observed shape: regenerate one 64-byte pattern via vtable[0]/vtable[1], then copy `param_1` dwords per row for `param_2` rows into dst, advancing dst by stride self[3].
// `dst` is the decompiler's unaff_retaddr (the first stack argument).
void FUN_0055b6e0(void* self, void* dst, uint32_t param_1, int param_2) {
    uint32_t* in_ECX = (uint32_t*)self;
    uint32_t uVar1;
    uint32_t* puVar4;
    uint32_t local_40[16];

    uVar1 = param_1;
    puVar4 = local_40;
    if ((void*)*in_ECX != (void*)0) {
        ((void(*)(void*))(*in_ECX))((uint8_t*)local_40 + 3);
    }
    ((void(*)(void*))in_ECX[1])(local_40);
    if (param_2 != 0) {
        param_1 = param_2;
        do {
            uint32_t* puVar5 = puVar4;
            uint32_t* puVar6 = (uint32_t*)dst;
            for (uint32_t uVar2 = uVar1 & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
                *puVar6 = *puVar5;
                puVar5 = puVar5 + 1;
                puVar6 = puVar6 + 1;
            }
            for (int iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
                *(uint8_t*)puVar6 = *(uint8_t*)puVar5;
                puVar5 = (uint32_t*)((int)puVar5 + 1);
                puVar6 = (uint32_t*)((int)puVar6 + 1);
            }
            dst = (uint32_t*)((int)dst + in_ECX[3]);
            puVar4 = puVar4 + 4;
            param_1 = param_1 + -1;
        } while (param_1 != 0);
    }
}

// 0x55b760 — observed shape: init of a 512-byte two-way dither table: vtable=0, pattern fn at +4, zeros at +8/+0xc, then 0x100 pairs of bytes at +0x10/+0x11 from FUN_005f0ddc.
void FUN_0055b760(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    uint8_t uVar1;
    uint32_t uVar2;
    uint8_t* puVar3;

    uVar2 = 0;
    in_ECX[0] = 0;
    in_ECX[1] = (uint32_t)&FUN_0055b310;
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    puVar3 = (uint8_t*)((int)in_ECX + 0x11);
    do {
        uVar1 = FUN_005f0ddc();
        puVar3[-1] = uVar1;
        uVar1 = FUN_005f0ddc();
        *puVar3 = uVar1;
        uVar2 = uVar2 + 1;
        puVar3 = puVar3 + 2;
    } while (uVar2 < 0x100);
}

// 0x55b7f0 — observed shape: pick row decoder by width (4/5/6 -> 55b4c0 / 55af30+55b310 / 55b050+55b310), allocate target via FUN_00539210, then per-plane 4-pixel pattern copies with FUN_0055b6e0 for clipped remainders.
int FUN_0055b7f0(void* self, int param_1) {
    uint32_t* in_ECX = (uint32_t*)self;
    uint32_t uVar1;
    uint32_t uVar2;
    int iVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    uint32_t uVar8;
    uint32_t* puVar6;
    uint32_t* puVar7;
    uint32_t* puVar9;
    int local_68;
    uint32_t local_60;
    int local_5c;
    uint32_t local_58;
    uint32_t local_54;
    uint32_t local_40[16];

    iVar3 = *(int*)(param_1 + 0xc);
    if (iVar3 == 4) {
        in_ECX[0] = 0;
        in_ECX[1] = (uint32_t)&FUN_0055b4c0;
    }
    else if (iVar3 == 5) {
        in_ECX[0] = (uint32_t)&LAB_0055af30;
        in_ECX[1] = (uint32_t)&FUN_0055b310;
    }
    else {
        if (iVar3 != 6) {
            return 0;
        }
        in_ECX[0] = (uint32_t)&FUN_0055b050;
        in_ECX[1] = (uint32_t)&FUN_0055b310;
    }
    iVar3 = FUN_00533c78(0x50);
    if (iVar3 == 0) {
        local_68 = 0;
    }
    else {
        local_68 = FUN_00539210(**(uint32_t**)(param_1 + 0x38),
                                **(uint32_t**)(param_1 + 0x3c),
                                &DAT_00727484,
                                *(uint32_t*)(param_1 + 0x44));
    }
    uVar1 = *(uint32_t*)(param_1 + 0x44);
    local_60 = 0;
    if (uVar1 != 0) {
        do {
            in_ECX[2] = *(int*)(*(int*)(param_1 + 0x40) + local_60 * 4) +
                        *(int*)(param_1 + 0x34);
            uVar2 = *(uint32_t*)(*(int*)(param_1 + 0x38) + local_60 * 4);
            local_54 = *(uint32_t*)(*(int*)(param_1 + 0x3c) + local_60 * 4);
            puVar7 = (uint32_t*)(*(int*)(*(int*)(local_68 + 0x40) + local_60 * 4) +
                                 *(int*)(local_68 + 0x34));
            uVar4 = local_54 & 3;
            uVar5 = uVar2 >> 2;
            local_54 = local_54 >> 2;
            uVar8 = uVar2 & 3;
            in_ECX[3] = uVar2 * 4;
            if (local_54 != 0) {
                do {
                    if (uVar5 != 0) {
                        local_58 = uVar5;
                        do {
                            puVar6 = local_40;
                            if ((void*)*in_ECX != (void*)0) {
                                ((void(*)(void*))(*in_ECX))((uint8_t*)local_40 + 3);
                            }
                            ((void(*)(void*))in_ECX[1])(local_40);
                            local_5c = 4;
                            puVar9 = puVar7;
                            do {
                                puVar9[0] = puVar6[0];
                                puVar9[1] = puVar6[1];
                                puVar9[2] = puVar6[2];
                                puVar9[3] = puVar6[3];
                                puVar9 = (uint32_t*)((int)puVar9 + in_ECX[3]);
                                puVar6 = puVar6 + 4;
                                local_5c = local_5c + -1;
                            } while (local_5c != 0);
                            puVar7 = puVar7 + 4;
                            local_58 = local_58 - 1;
                        } while (local_58 != 0);
                    }
                    if (uVar8 != 0) {
                        FUN_0055b6e0(in_ECX, puVar7, uVar8, 4);
                        puVar7 = puVar7 + uVar8;
                    }
                    puVar7 = puVar7 + uVar2 * 3;
                    local_54 = local_54 - 1;
                } while (local_54 != 0);
            }
            if (uVar4 != 0) {
                for (; uVar5 != 0; uVar5 = uVar5 - 1) {
                    FUN_0055b6e0(in_ECX, puVar7, 4, uVar4);
                    puVar7 = puVar7 + 4;
                }
                if (uVar8 != 0) {
                    FUN_0055b6e0(in_ECX, puVar7, uVar8, uVar4);
                }
            }
            local_60 = local_60 + 1;
        } while (local_60 < uVar1);
    }
    return local_68;
}

// 0x55bb90 — observed shape: RGB->BGR swap of `count at +0x32` 3-byte pixels.
void FUN_0055bb90(void* self, uint8_t* param_1, uint8_t* param_2) {
    uint8_t* base = (uint8_t*)self;
    uint32_t uVar1;

    uVar1 = 0;
    if (*(uint16_t*)(base + 0x32) != 0) {
        do {
            *param_2 = param_1[2];
            param_2[1] = param_1[1];
            param_2[2] = *param_1;
            param_2 = param_2 + 3;
            param_1 = param_1 + 3;
            uVar1 = uVar1 + 1;
        } while (uVar1 < *(uint16_t*)(base + 0x32));
    }
}

// 0x55bbd0 — observed shape: BGRx reorder (swap R/B, keep 4th byte) of `count at +0x32` 4-byte pixels.
void FUN_0055bbd0(void* self, uint8_t* param_1, uint8_t* param_2) {
    uint8_t* base = (uint8_t*)self;
    uint32_t uVar1;

    uVar1 = 0;
    if (*(uint16_t*)(base + 0x32) != 0) {
        do {
            *param_2 = param_1[2];
            param_2[1] = param_1[1];
            param_2[2] = *param_1;
            param_2[3] = param_1[3];
            param_2 = param_2 + 4;
            param_1 = param_1 + 4;
            uVar1 = uVar1 + 1;
        } while (uVar1 < *(uint16_t*)(base + 0x32));
    }
}

// 0x55bc10 — observed shape: extension test ".tga" / ".targa" (case-insensitive).
uint32_t FUN_0055bc10(char* param_1) {
    int iVar1;

    iVar1 = _stricmp(param_1, ".tga");
    if (iVar1 != 0) {
        iVar1 = _stricmp(param_1, ".targa");
        if (iVar1 != 0) {
            return 0;
        }
    }
    return 1;
}

// 0x55bc50 — observed shape: derived-object init: vtable swaps, critical section at +4, byte/word field zeroing through +0x80, 9-dword copy from DAT_00727460 at +0x40.
void FUN_0055bc50(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    int iVar1;
    uint32_t* puVar2;
    uint32_t* puVar3;

    *in_ECX = (uint32_t)&PTR_FUN_006c309c;
    in_ECX[7] = 0;
    in_ECX[8] = 0;
    InitializeCriticalSection((LPCRITICAL_SECTION)(in_ECX + 1));
    *in_ECX = (uint32_t)&PTR_FUN_006c30c4;
    FUN_00513dc0();
    *(uint8_t*)(in_ECX + 9) = 0;
    *(uint8_t*)((int)in_ECX + 0x25) = 0;
    *(uint8_t*)((int)in_ECX + 0x26) = 0;
    *(uint16_t*)(in_ECX + 10) = 0;
    *(uint16_t*)((int)in_ECX + 0x2a) = 0;
    *(uint8_t*)(in_ECX + 0xb) = 0;
    *(uint16_t*)((int)in_ECX + 0x2e) = 0;
    *(uint16_t*)(in_ECX + 0xc) = 0;
    *(uint16_t*)((int)in_ECX + 0x32) = 0;
    *(uint16_t*)(in_ECX + 0xd) = 0;
    *(uint8_t*)((int)in_ECX + 0x36) = 0;
    *(uint8_t*)((int)in_ECX + 0x37) = 0;
    *(uint8_t*)(in_ECX + 0xe) = 0;
    *(uint8_t*)((int)in_ECX + 0x39) = 0;
    *(uint8_t*)((int)in_ECX + 0x3a) = 0;
    *(uint8_t*)((int)in_ECX + 0x3b) = 0;
    *(uint8_t*)(in_ECX + 0xf) = 0;
    puVar2 = &DAT_00727460[0];
    puVar3 = in_ECX + 0x10;
    for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
    }
    in_ECX[0x19] = 0;
    in_ECX[0x1a] = 0;
    in_ECX[0x1b] = 0;
    in_ECX[0x1c] = 0;
    in_ECX[0x1d] = 0;
    in_ECX[0x1e] = 0;
    *(uint8_t*)(in_ECX + 0x1f) = 0;
    *(uint8_t*)((int)in_ECX + 0x7d) = 0;
    *(uint8_t*)((int)in_ECX + 0x7e) = 0;
    *(uint8_t*)((int)in_ECX + 0x7f) = 0;
    *(uint8_t*)(in_ECX + 0x20) = 0;
}

// 0x55bcf0 — observed shape: destructor: derived/base vtable swaps, free +0x68/+0x70 payloads, DeleteCriticalSection at +4, conditional delete of receiver.
void FUN_0055bcf0(void* self, uint8_t param_1) {
    uint32_t* in_ECX = (uint32_t*)self;

    *in_ECX = (uint32_t)&PTR_FUN_006c30c4;
    operator_delete__((void*)in_ECX[0x1a]);
    operator_delete__((void*)in_ECX[0x1c]);
    *in_ECX = (uint32_t)&PTR_FUN_006c309c;
    DeleteCriticalSection((LPCRITICAL_SECTION)(in_ECX + 1));
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
}

// 0x55bd40 — observed shape: RLE plane decoder: refill run state at +0x78 from packed count byte, copy or replicate pixel bytes from +0x7d, advance by width at +0x38.
void FUN_0055bd40(void* self, int* param_1, uint32_t* param_2) {
    uint8_t* base = (uint8_t*)self;
    uint32_t uVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    uint32_t* puVar4;
    uint32_t* puVar5;
    uint8_t local_9;
    uint32_t uStack_8;
    uint32_t local_4;

    local_4 = 0;
    if (*(uint16_t*)(base + 0x32) != 0) {
        do {
            uVar3 = local_4;
            if (*(uint32_t*)(base + 0x78) == 0) {
                local_9 = 0;
                ((void(*)(void*, int))*(void**)(*param_1 + 8))(&local_9, 1);
                *(uint8_t*)(base + 0x7c) = local_9 >> 7;
                if ((int8_t)local_9 < 0) {
                    *(uint32_t*)(base + 0x78) = local_9 - 0x7f;
                    *(uint8_t*)(base + 0x7c) = 1;
                    ((void(*)(void*, int))*(void**)(*param_1 + 8))(
                        base + 0x7d, *(uint8_t*)(base + 0x38));
                }
                else {
                    *(uint8_t*)(base + 0x7c) = 0;
                    *(uint32_t*)(base + 0x78) = local_9 + 1;
                }
            }
            uVar3 = *(uint16_t*)(base + 0x32) - uVar3;
            if (*(uint32_t*)(base + 0x78) < uVar3) {
                uVar3 = *(uint32_t*)(base + 0x78);
            }
            if (*(uint8_t*)(base + 0x7c) == 0) {
                ((void(*)(void*, int))*(void**)(*param_1 + 8))(
                    param_2, *(uint8_t*)(base + 0x38) * uVar3);
                param_2 = (uint32_t*)((uint8_t*)param_2 +
                                      *(uint8_t*)(base + 0x38) * uVar3);
            }
            else if (uVar3 != 0) {
                uVar1 = (uint32_t)*(uint8_t*)(base + 0x38);
                uStack_8 = uVar3;
                do {
                    puVar4 = (uint32_t*)(base + 0x7d);
                    puVar5 = param_2;
                    for (uVar2 = uVar1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
                        *puVar5 = *puVar4;
                        puVar4 = puVar4 + 1;
                        puVar5 = puVar5 + 1;
                    }
                    for (uVar1 = uVar1 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
                        *(uint8_t*)puVar5 = *(uint8_t*)puVar4;
                        puVar4 = (uint32_t*)((int)puVar4 + 1);
                        puVar5 = (uint32_t*)((int)puVar5 + 1);
                    }
                    uVar1 = (uint32_t)*(uint8_t*)(base + 0x38);
                    param_2 = (uint32_t*)((int)param_2 + uVar1);
                    uStack_8 = uStack_8 - 1;
                } while (uStack_8 != 0);
                uStack_8 = 0;
            }
            *(uint32_t*)(base + 0x78) = *(int*)(base + 0x78) - uVar3;
            local_4 = local_4 + uVar3;
        } while (local_4 < *(uint16_t*)(base + 0x32));
    }
}

// 0x55be60 — observed shape: grow the dword palette buffer at +0x70 (capacity +0x6c) and scratch buffer at +0x68 (capacity +0x64), then de-interleave one row by pixel depth at +0x2c into RGBA dwords.
void FUN_0055be60(void* self, int* param_1) {
    uint8_t* base = (uint8_t*)self;
    char cVar1;
    int iVar2;
    int iVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    uint8_t* pbVar6;
    uint8_t* pcVar7;
    uint8_t* pcVar8;

    if (*(uint32_t*)(base + 0x6c) < (uint32_t)*(uint16_t*)(base + 0x2a)) {
        *(uint32_t*)(base + 0x6c) = (uint32_t)*(uint16_t*)(base + 0x2a);
        operator_delete__(*(void**)(base + 0x70));
        iVar2 = *(int*)(base + 0x6c);
        iVar3 = thunk_FUN_00533c78(iVar2 * 4);
        if (iVar3 == 0) {
            iVar3 = 0;
        }
        else {
            FUN_004127b0(iVar3, 4, iVar2, (void*)&LAB_005cea70);
        }
        *(int*)(base + 0x70) = iVar3;
    }
    uVar4 = (uint32_t)*(uint16_t*)(base + 0x2a) << 2;
    if (*(uint32_t*)(base + 100) < uVar4) {
        *(uint32_t*)(base + 100) = uVar4;
        operator_delete__(*(void**)(base + 0x68));
        uVar5 = (uint32_t)thunk_FUN_00533c78(*(uint32_t*)(base + 100));
        *(uint32_t*)(base + 0x68) = uVar5;
    }
    pcVar8 = *(uint8_t**)(base + 0x70);
    switch (*(uint8_t*)(base + 0x2c)) {
    case 8:
        pcVar7 = *(uint8_t**)(base + 0x68);
        ((void(*)(void*, int))*(void**)(*param_1 + 8))(pcVar7,
                                                       *(uint16_t*)(base + 0x2a));
        uVar4 = 0;
        if (*(int16_t*)(base + 0x2a) != 0) {
            do {
                cVar1 = (char)*pcVar7;
                pcVar8[2] = (uint8_t)cVar1;
                pcVar8[1] = (uint8_t)cVar1;
                *pcVar8 = (uint8_t)cVar1;
                pcVar8[3] = 0xff;
                pcVar8 = pcVar8 + 4;
                pcVar7 = pcVar7 + 1;
                uVar4 = uVar4 + 1;
            } while (uVar4 < *(uint16_t*)(base + 0x2a));
            return;
        }
        break;
    case 0xf:
    case 0x10:
        pbVar6 = *(uint8_t**)(base + 0x68);
        ((void(*)(void*, int))*(void**)(*param_1 + 8))(
            pbVar6, (uint32_t)*(uint16_t*)(base + 0x2a) << 1);
        uVar4 = 0;
        if (*(int16_t*)(base + 0x2a) != 0) {
            do {
                *pcVar8 = (uint8_t)((pbVar6[1] & 0xfc) << 1);
                pcVar8[1] = (uint8_t)((*pbVar6 >> 2 & 0x38) + pbVar6[1] * '@');
                pcVar8[2] = (uint8_t)(*pbVar6 << 3);
                pcVar8[3] = 0xff;
                pcVar8 = pcVar8 + 4;
                pbVar6 = pbVar6 + 2;
                uVar4 = uVar4 + 1;
            } while (uVar4 < *(uint16_t*)(base + 0x2a));
            return;
        }
        break;
    case 0x18:
        pcVar7 = *(uint8_t**)(base + 0x68);
        ((void(*)(void*, int))*(void**)(*param_1 + 8))(
            pcVar7, (uint32_t)*(uint16_t*)(base + 0x2a) * 3);
        uVar4 = 0;
        if (*(int16_t*)(base + 0x2a) != 0) {
            do {
                pcVar8[2] = *pcVar7;
                pcVar8[1] = pcVar7[1];
                *pcVar8 = pcVar7[2];
                pcVar8[3] = 0xff;
                pcVar7 = pcVar7 + 3;
                pcVar8 = pcVar8 + 4;
                uVar4 = uVar4 + 1;
            } while (uVar4 < *(uint16_t*)(base + 0x2a));
            return;
        }
        break;
    case 0x20:
        pcVar7 = *(uint8_t**)(base + 0x68);
        ((void(*)(void*, int))*(void**)(*param_1 + 8))(
            pcVar7, (uint32_t)*(uint16_t*)(base + 0x2a) << 2);
        uVar4 = 0;
        if (*(int16_t*)(base + 0x2a) != 0) {
            do {
                pcVar8[2] = *pcVar7;
                pcVar8[1] = pcVar7[1];
                *pcVar8 = pcVar7[2];
                pcVar8[3] = pcVar7[3];
                pcVar7 = pcVar7 + 4;
                pcVar8 = pcVar8 + 4;
                uVar4 = uVar4 + 1;
            } while (uVar4 < *(uint16_t*)(base + 0x2a));
        }
        break;
    }
}

// 0x55c050 — observed shape: locked surface load: header field reads via stream vtable+8, BGR(A) and mask dispatch, palette-block copy from DAT_007178xx/DAT_007274xx, decoder install at +0x74, then lock release.
// Ghidra elided the arguments of two stream calls (vtable+8 with no operands shown) and one with a single operand; they are kept as observed.
int FUN_0055c050(void* self, int* param_1) {
    uint8_t* base = (uint8_t*)self;
    LPCRITICAL_SECTION lpCriticalSection;
    int* piVar1;
    char cVar2;
    char cVar3;
    DWORD DVar4;
    int iVar5;
    uint32_t uVar6;
    uint32_t* puVar7;
    uint32_t* puVar8;
    uint32_t* puVar9;
    bool bVar10;
    LPCRITICAL_SECTION p_Var11;

    DVar4 = GetCurrentThreadId();
    if (*(DWORD*)(base + 0x1c) != DVar4) {
        EnterCriticalSection((LPCRITICAL_SECTION)(base + 4));
        DVar4 = GetCurrentThreadId();
        *(DWORD*)(base + 0x1c) = DVar4;
    }
    *(int*)(base + 0x20) = *(int*)(base + 0x20) + 1;
    ((void(*)(void*, int))*(void**)(*param_1 + 8))((char*)(base + 0x24), 1);
    ((void(*)(void*, int))*(void**)(*param_1 + 8))(base + 0x25, 1);
    ((void(*)(void*, int))*(void**)(*param_1 + 8))((void*)(base + 0x26), 1);
    ((void(*)(void*, int))*(void**)(*param_1 + 8))(base + 0x28, 2);
    ((void(*)(void*, int))*(void**)(*param_1 + 8))(base + 0x2a, 2);
    ((void(*)(void*, int))*(void**)(*param_1 + 8))(base + 0x2c, 1);
    puVar9 = (uint32_t*)(base + 0x2e);
    ((void(*)(void*, int))*(void**)(*param_1 + 8))(puVar9, 2);
    ((void(*)(void))*(void**)(*param_1 + 8))();
    ((void(*)(void*))*(void**)(*param_1 + 8))(base + 0x32);
    lpCriticalSection = (LPCRITICAL_SECTION)(base + 0x34);
    p_Var11 = lpCriticalSection;
    ((void(*)(void))*(void**)(*param_1 + 8))();
    ((void(*)(void*, int))*(void**)(*param_1 + 8))(base + 0x36, 1);
    ((void(*)(void*, int))*(void**)(*param_1 + 8))(base + 0x37, 1);
    cVar2 = *(char*)(base + 0x24);
    if (cVar2 != '\0') {
        ((void(*)(int, int))*(void**)(*param_1 + 0x10))(cVar2, 1);
    }
    *(uint8_t*)(base + 0x3b) = (uint8_t)(~(*(uint8_t*)(base + 0x37) >> 5) & 1);
    switch (*(uint8_t*)(base + 0x26)) {
    case 1:
        *(uint8_t*)(base + 0x3a) = 1;
        *(uint8_t*)(base + 0x3c) = 0;
        goto LAB_0055c180;
    case 2:
    case 3:
        *(uint8_t*)(base + 0x3c) = 0;
        break;
    default:
        DVar4 = GetCurrentThreadId();
        if (*(DWORD*)(base + 0x4c) == DVar4) {
            piVar1 = (int*)(base + 0x50);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                *(uint32_t*)(base + 0x4c) = 0;
                LeaveCriticalSection(lpCriticalSection);
            }
        }
        return 0;
    case 9:
        *(uint8_t*)(base + 0x3a) = 1;
        *(uint8_t*)(base + 0x3c) = 1;
        goto LAB_0055c180;
    case 10:
    case 0xb:
        *(uint8_t*)(base + 0x3c) = 1;
    }
    *(uint8_t*)(base + 0x3a) = 0;
LAB_0055c180:
    cVar2 = *(char*)(base + 0x3a);
    if (cVar2 == '\0') {
        cVar3 = *(char*)(base + 0x36);
    }
    else {
        cVar3 = *(char*)(base + 0x2c);
    }
    bVar10 = cVar3 == ' ';
    *(bool*)(base + 0x39) = bVar10;
    if (cVar2 == '\0') {
        puVar7 = &DAT_00727484[0];
        if (!bVar10) {
            puVar7 = &DAT_00727460[0];
        }
    }
    else if (*(int16_t*)(base + 0x2a) == 0x10) {
        puVar7 = &DAT_007178a4[0];
        if (!bVar10) {
            puVar7 = &DAT_00717880[0];
        }
    }
    else {
        puVar7 = &DAT_007178ec[0];
        if (!bVar10) {
            puVar7 = &DAT_007178c8[0];
        }
    }
    puVar8 = (uint32_t*)(base + 0x40);
    for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
    }
    switch (*(uint8_t*)(base + 0x36)) {
    case 4:
        *(uint8_t*)(base + 0x38) = 0;
        if (cVar2 == '\0') {
            FUN_004b10d0();
            return 0;
        }
        *(void**)(base + 0x74) = (void*)&LAB_0055ba00;
        break;
    case 8:
        *(uint8_t*)(base + 0x38) = 1;
        if (cVar2 == '\0') {
            *(void**)(base + 0x74) = (void*)&LAB_0055ba60;
        }
        else {
            *(void**)(base + 0x74) = (void*)&LAB_0055ba30;
        }
        break;
    case 0xf:
    case 0x10:
        *(uint8_t*)(base + 0x38) = 2;
        if (cVar2 == '\0') {
            *(void**)(base + 0x74) = (void*)&LAB_0055ba90;
        }
        else if (bVar10) {
            *(void**)(base + 0x74) = (void*)&LAB_0055bb30;
        }
        else {
            *(void**)(base + 0x74) = (void*)&LAB_0055bae0;
        }
        break;
    case 0x18:
        *(uint8_t*)(base + 0x38) = 3;
        *(void**)(base + 0x74) = (void*)&FUN_0055bb90;
        break;
    case 0x20:
        *(uint8_t*)(base + 0x38) = 4;
        *(void**)(base + 0x74) = (void*)&FUN_0055bbd0;
        break;
    }
    uVar6 = uRam00000002 & 0xffff;
    *(uint8_t*)(base + 0x7c) = 0;
    *(uint32_t*)(base + 0x78) = 0;
    *(uint32_t*)(base + 0x30) = uVar6;
    uRam00000002 = uRam00000002 & 0xffff;
    puVar7 = (uint32_t*)(base + 0x40);
    for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar9 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar9 = puVar9 + 1;
    }
    *(uint8_t*)&p_Var11->DebugInfo = 0;
    DVar4 = GetCurrentThreadId();
    if (*(DWORD*)(base + 0x4c) == DVar4) {
        piVar1 = (int*)(base + 0x50);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            *(uint32_t*)(base + 0x4c) = 0;
            LeaveCriticalSection(lpCriticalSection);
        }
    }
    return 1;
}

// 0x55c370 — observed shape: locked page load: vtable+0xc header read, size selection incl. 4bpp halving, optional FUN_0055be60 palette row, target create/reuse via FUN_00539210 + FUN_0054aab0 match, decode rows into +0x68 buffer through +0x74 decoder, flip when +0x3b, then critical-section release.
// `unaff_ESI` is the critical section the decompiler tracked in ESI for the release path.
int FUN_0055c370(void* self, uint32_t param_1, LPCRITICAL_SECTION unaff_ESI) {
    int* in_ECX = (int*)self;
    LPCRITICAL_SECTION lpCriticalSection;
    int* piVar1;
    LONG* pLVar2;
    char cVar3;
    DWORD DVar4;
    int iVar5;
    int iVar6;
    uint32_t uVar7;
    PRTL_CRITICAL_SECTION_DEBUG p_Var8;
    uint32_t uVar9;
    uint32_t uVar10;
    uint32_t uVar11;
    uint8_t local_35[5];
    LPCRITICAL_SECTION local_30;
    uint8_t local_2c[4];
    uint8_t local_28[4];
    uint32_t local_24;
    uint32_t local_20;
    uint32_t local_1c;
    uint32_t local_18;
    uint32_t local_14;
    int* local_10;
    int local_c;
    uint32_t local_8;
    uint32_t local_4;

    local_8 = (2u << ((uint8_t)DAT_0072745c & 0x1f) & DAT_00717834) |
              (1u << ((uint8_t)DAT_0071783c & 0x1f) & DAT_00717838);
    lpCriticalSection = (LPCRITICAL_SECTION)(in_ECX + 1);
    local_c = 8;
    local_10 = (int*)0;
    local_14 = 0;
    local_18 = 0;
    local_1c = 0;
    local_24 = 2;
    local_20 = 0;
    local_4 = 0;
    local_30 = lpCriticalSection;
    DVar4 = GetCurrentThreadId();
    if (in_ECX[7] != DVar4) {
        EnterCriticalSection(lpCriticalSection);
        DVar4 = GetCurrentThreadId();
        in_ECX[7] = DVar4;
    }
    in_ECX[8] = in_ECX[8] + 1;
    cVar3 = ((char(*)(uint32_t, void*, void*, void*, void*))*(void**)(*in_ECX + 0xc))(
        param_1, local_28, local_2c, &local_24, local_35);
    if (cVar3 == '\0') {
        DVar4 = GetCurrentThreadId();
        if (in_ECX[7] == DVar4) {
            piVar1 = in_ECX + 8;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                in_ECX[7] = 0;
                LeaveCriticalSection(lpCriticalSection);
            }
        }
        return 0;
    }
    uVar9 = (uint32_t)*(uint8_t*)(in_ECX + 0xe) *
            (uint32_t)*(uint16_t*)((int)in_ECX + 0x32);
    if (*(uint8_t*)(in_ECX + 0xe) == 0) {
        if (*(char*)((int)in_ECX + 0x36) != '\x04') {
            DVar4 = GetCurrentThreadId();
            if (in_ECX[7] == DVar4) {
                piVar1 = in_ECX + 8;
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    in_ECX[7] = 0;
                    LeaveCriticalSection(lpCriticalSection);
                }
            }
            return 0;
        }
        uVar9 = (uint32_t)(*(uint16_t*)((int)in_ECX + 0x32) >> 1);
    }
    if (*(char*)((int)in_ECX + 0x25) == '\0') {
        if (*(char*)((int)in_ECX + 0x3a) != '\0') goto LAB_0055c4eb;
    }
    else {
        if (0x3fff < *(uint16_t*)((int)in_ECX + 0x2a) + 1 +
                        (uint32_t)*(uint16_t*)(in_ECX + 10)) {
LAB_0055c4eb:
            FUN_004b10d0();
            return 0;
        }
        FUN_0055be60(in_ECX, local_10);
    }
    iVar5 = local_c;
    if ((((local_c == 0) ||
          (**(uint32_t**)(local_c + 0x38) !=
           (uint32_t)*(uint16_t*)((int)in_ECX + 0x32))) ||
         (**(uint32_t**)(local_c + 0x3c) !=
          (uint32_t)*(uint16_t*)(in_ECX + 0xd))) ||
        ((cVar3 = FUN_0054aab0(in_ECX + 0x10)), cVar3 == '\0')) {
        iVar5 = FUN_00533c78(0x50);
        if (iVar5 == 0) {
            local_c = 0;
        }
        else {
            local_c = FUN_00539210(*(uint16_t*)((int)in_ECX + 0x32),
                                   (int16_t)in_ECX[0xd], in_ECX + 0x10, 1);
        }
    }
    else {
        local_c = iVar5;
    }
    iVar5 = local_c;
    if (*(char*)((int)in_ECX + 0x3a) != '\0') {
        iVar6 = FUN_00533c78(0x28);
        if (iVar6 == 0) {
            uVar7 = 0;
        }
        else {
            uVar7 = FUN_0053a5a0(*(uint8_t*)((int)in_ECX + 0x39),
                                 *(uint16_t*)((int)in_ECX + 0x2a), in_ECX[0x1c]);
        }
        FUN_004493d0(uVar7);
    }
    if ((uint32_t)in_ECX[0x19] < uVar9) {
        in_ECX[0x19] = uVar9;
        operator_delete__((void*)in_ECX[0x1a]);
        iVar6 = thunk_FUN_00533c78(in_ECX[0x19]);
        in_ECX[0x1a] = iVar6;
    }
    iVar6 = **(int**)(iVar5 + 0x40) + *(int*)(iVar5 + 0x34);
    uVar11 = *(int*)(iVar5 + 0x48) * **(uint32_t**)(iVar5 + 0x38);
    if (uVar11 == 0) {
        uVar11 = **(uint32_t**)(iVar5 + 0x38) >> 1;
    }
    if (*(char*)((int)in_ECX + 0x3b) != '\0') {
        iVar6 = iVar6 + (*(uint16_t*)(in_ECX + 0xd) - 1) * uVar11;
        uVar11 = -uVar11;
    }
    uVar10 = 0;
    if ((char)in_ECX[0xf] == '\0') {
        if ((int16_t)in_ECX[0xd] != 0) {
            do {
                ((void(*)(void*, uint32_t))*(void**)(*local_10 + 8))(
                    (void*)in_ECX[0x1a], uVar9);
                ((void(*)(void*, int))in_ECX[0x1d])((void*)in_ECX[0x1a], iVar6);
                iVar6 = iVar6 + uVar11;
                uVar10 = uVar10 + 1;
            } while (uVar10 < *(uint16_t*)(in_ECX + 0xd));
        }
    }
    else if ((int16_t)in_ECX[0xd] != 0) {
        do {
            FUN_0055bd40(in_ECX, local_10, (uint32_t*)in_ECX[0x1a]);
            ((void(*)(void*, int))in_ECX[0x1d])((void*)in_ECX[0x1a], iVar6);
            iVar6 = iVar6 + uVar11;
            uVar10 = uVar10 + 1;
        } while (uVar10 < *(uint16_t*)(in_ECX + 0xd));
    }
    p_Var8 = (PRTL_CRITICAL_SECTION_DEBUG)GetCurrentThreadId();
    if (unaff_ESI[1].DebugInfo == p_Var8) {
        pLVar2 = &unaff_ESI[1].LockCount;
        *pLVar2 = *pLVar2 + -1;
        if (*pLVar2 == 0) {
            unaff_ESI[1].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0;
            LeaveCriticalSection(unaff_ESI);
        }
    }
    return local_c;
}

// 0x55c660 — observed shape: 8-bit RLE row expand into param_1 with param_3 stride; run byte high bit selects literal run (byte stride 1) vs repeated literal (byte stride 1), biased run count, stops at count +0x24.
void FUN_0055c660(void* self, uint8_t* param_1, uint8_t* param_2, int param_3) {
    uint8_t* base = (uint8_t*)self;
    uint8_t bVar1;
    int16_t sVar2;
    uint8_t bVar3;
    uint8_t* pbVar4;
    uint32_t uVar5;

    bVar3 = *param_2;
    if (bVar3 != 0) {
        sVar2 = 0;
        do {
            if (sVar2 == *(int16_t*)(base + 0x24)) {
                return;
            }
            pbVar4 = param_2 + 1;
            bVar1 = bVar3 & 0x7f;
            if ((char)bVar3 < '\0') {
                if (bVar1 != 0) {
                    uVar5 = (uint32_t)bVar1;
                    do {
                        bVar1 = (uint8_t)(bVar1 - 1);
                        *param_1 = *pbVar4;
                        pbVar4 = pbVar4 + 1;
                        param_1 = param_1 + param_3;
                        uVar5 = uVar5 - 1;
                    } while (uVar5 != 0);
                }
            }
            else {
                bVar3 = *pbVar4;
                pbVar4 = param_2 + 2;
                if (bVar1 != 0) {
                    uVar5 = (uint32_t)bVar1;
                    do {
                        *param_1 = bVar3;
                        bVar1 = (uint8_t)(bVar1 - 1);
                        param_1 = param_1 + param_3;
                        uVar5 = uVar5 - 1;
                    } while (uVar5 != 0);
                }
            }
            bVar3 = *pbVar4;
            sVar2 = (int16_t)(sVar2 + (uint16_t)(uint8_t)(bVar1 - 1));
            param_2 = pbVar4;
        } while (bVar3 != 0);
    }
}

// 0x55c6e0 — observed shape: 16-bit RLE row expand into param_1 with param_3 stride; literal runs step 2 bytes, repeat runs step 3, biased run count, stops at count +0x24.
void FUN_0055c6e0(void* self, uint8_t* param_1, uint8_t* param_2, int param_3) {
    uint8_t* base = (uint8_t*)self;
    uint8_t bVar1;
    int16_t sVar2;
    uint8_t* pbVar3;
    uint8_t bVar4;
    uint32_t uVar5;

    bVar4 = *param_2;
    if (bVar4 != 0) {
        sVar2 = 0;
        do {
            if (sVar2 == *(int16_t*)(base + 0x24)) {
                return;
            }
            pbVar3 = param_2 + 1;
            bVar1 = bVar4 & 0x7f;
            if ((char)bVar4 < '\0') {
                if (bVar1 != 0) {
                    uVar5 = (uint32_t)bVar1;
                    do {
                        *param_1 = *pbVar3;
                        bVar1 = (uint8_t)(bVar1 - 1);
                        pbVar3 = pbVar3 + 2;
                        param_1 = param_1 + param_3;
                        uVar5 = uVar5 - 1;
                    } while (uVar5 != 0);
                }
            }
            else {
                bVar4 = *pbVar3;
                pbVar3 = param_2 + 3;
                if (bVar1 != 0) {
                    uVar5 = (uint32_t)bVar1;
                    do {
                        *param_1 = bVar4;
                        bVar1 = (uint8_t)(bVar1 - 1);
                        param_1 = param_1 + param_3;
                        uVar5 = uVar5 - 1;
                    } while (uVar5 != 0);
                }
            }
            bVar4 = *pbVar3;
            sVar2 = (int16_t)(sVar2 + (uint16_t)(uint8_t)(bVar1 - 1));
            param_2 = pbVar3;
        } while (bVar4 != 0);
    }
}

// 0x55c760 — observed shape: extension test ".sgi" / ".rgb" / ".rgba" / ".int" / ".inta" (case-insensitive).
uint32_t FUN_0055c760(char* param_1) {
    int iVar1;

    iVar1 = _stricmp(param_1, ".sgi");
    if (iVar1 != 0) {
        iVar1 = _stricmp(param_1, ".rgb");
        if (iVar1 != 0) {
            iVar1 = _stricmp(param_1, ".rgba");
            if (iVar1 != 0) {
                iVar1 = _stricmp(param_1, ".int");
                if (iVar1 != 0) {
                    iVar1 = _stricmp(param_1, ".inta");
                    if (iVar1 != 0) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}
