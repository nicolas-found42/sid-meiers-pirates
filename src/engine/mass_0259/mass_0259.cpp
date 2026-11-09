// Mass reconstruction batch mass_0259 — unverified decompiler-derived candidate.
// Target: Sid Meier's Pirates! (2004), PE32 i386.
// Sources: analysis/pseudocode/functions/0x5f5859.c .. 0x5f74b7.c (Ghidra 12.2).
// No compiler/test run. Correlated externally via observed pseudocode shapes.
#include <cstdint>
#include <cstddef>
#include <windows.h>

typedef uint8_t  undefined1;
typedef uint16_t undefined2;
typedef uint32_t undefined4;

// ---- extern globals observed in the corpus listings ----
extern int32_t DAT_006dc6a0;       // 9-word record table terminator / default record
extern int32_t DAT_006dc6c8;       // 9-word record table base
extern int32_t DAT_006dced0[];     // byte-addressed compatibility matrix
extern int32_t* PTR_DAT_00718a58;  // end pointer of the record table

// ---- vtable dispatch helper (i386 __thiscall keeps the receiver in ECX) ----
static inline void* VSLOT(void* obj, uintptr_t off) {
    void** vtbl = *reinterpret_cast<void***>(obj);
    return *reinterpret_cast<void**>(reinterpret_cast<char*>(vtbl) + off);
}

// ---- extern helpers referenced by the listings ----
extern void thunk_FUN_005f3bfd(void* out, undefined4 a, undefined4 b, undefined4 c);
extern void thunk_FUN_005f2e51(undefined4 a, void* b);
extern void thunk_FUN_005f424b(void* out, undefined4 a);
extern void thunk_FUN_005f3dd2(void* out, void* a);
extern void thunk_FUN_005f3d0e(void* out, void* a, void* b);
extern void thunk_FUN_005f3e9e(void* out, void* a);
extern void thunk_FUN_005f3f34(void* out, void* a);
extern void thunk_FUN_005ff7c0(void);
extern void thunk_FUN_005ff879(void);
extern void FUN_005f8ea2(int a);
extern int* FUN_005f5e54(int a);
extern int  FUN_005f5ef6(int* a, uint32_t b, undefined4 c, int* d);
extern int  FUN_005f5ff4(int a);
extern void FUN_005fbd43(void);
extern void FUN_005fbd4d(void);
extern void FUN_005ff6ce(void);
extern void FUN_005ff873(void);
extern int  FUN_005ff8a2(void* a, int b, undefined4 c, undefined4 d, undefined4 e, undefined4 f);
extern int  FUN_005ffd96(void* a, int b, undefined4 c, undefined4 d, undefined4 e, undefined4 f);
extern int  FUN_005ff591(void* a, void* b, int c);
extern void FUN_005f9006(void);
extern void FUN_005f901f(void);
extern int  FUN_005fba91(uint32_t a, uint32_t b, int* c, int d);
extern void FUN_0060b97b(void);
extern int  FUN_0060b98d(undefined4 a, int b);
extern void FUN_0060bb0e(void);

// ===========================================================================
// 0x005f5859 — observed shape
// Builds a 16-byte value via thunk_FUN_005f3bfd, then applies it to param_1
// through thunk_FUN_005f2e51 and returns param_1 unchanged.
// ===========================================================================
undefined4 FUN_005f5859(undefined4 param_1, undefined4 param_2, undefined4 param_3,
                        undefined4 param_4) {
    undefined1 local_14[16];

    thunk_FUN_005f3bfd(local_14, param_2, param_3, param_4);
    thunk_FUN_005f2e51(param_1, local_14);
    return param_1;
}

// ===========================================================================
// 0x005f5894 — observed shape
// Forms a 4x4 outer-product-like matrix from a quaternion (param_3) and a
// 4-vector param_2. fVar1 is the dot term folded into four diagonal entries.
// ===========================================================================
void FUN_005f5894(float* param_1, float* param_2, undefined4 param_3) {
    float fVar1;
    float local_14;
    float local_10;
    float local_c;
    float local_8;

    thunk_FUN_005f424b(&local_14, param_3);
    fVar1 = local_c * param_2[2] + local_8 * param_2[3] + local_14 * *param_2 +
            local_10 * param_2[1];
    local_14 = -local_14;
    local_10 = -local_10;
    local_c = -local_c;
    local_8 = -local_8;
    *param_1 = local_14 * *param_2 + fVar1;
    param_1[4] = local_10 * *param_2;
    param_1[8] = local_c * *param_2;
    param_1[0xc] = local_8 * *param_2;
    param_1[1] = local_14 * param_2[1];
    param_1[5] = local_10 * param_2[1] + fVar1;
    param_1[9] = local_c * param_2[1];
    param_1[0xd] = local_8 * param_2[1];
    param_1[2] = local_14 * param_2[2];
    param_1[6] = local_10 * param_2[2];
    param_1[10] = local_c * param_2[2] + fVar1;
    param_1[0xe] = local_8 * param_2[2];
    param_1[3] = local_14 * param_2[3];
    param_1[7] = local_10 * param_2[3];
    param_1[0xb] = local_c * param_2[3];
    param_1[0xf] = local_8 * param_2[3] + fVar1;
    return;
}

// ===========================================================================
// 0x005f5992 — observed shape
// Builds a symmetric 4x4 rotation-style matrix from a quaternion (param_2):
// each diagonal is 1 - 2*q_i*q_i and off-diagonals are the paired products.
// ===========================================================================
void FUN_005f5992(float* param_1, undefined4 param_2) {
    float fVar1;
    float fVar2;
    float fVar3;
    float local_14;
    float local_10;
    float local_c;
    float local_8;

    thunk_FUN_005f424b(&local_14, param_2);
    fVar1 = local_14 * -2.0f;
    fVar3 = local_10 * -2.0f;
    fVar2 = local_c * -2.0f;
    *param_1 = local_14 * fVar1 + 1.0f;
    param_1[1] = fVar3 * local_14;
    param_1[2] = fVar2 * local_14;
    param_1[3] = 0.0f;
    param_1[4] = local_10 * fVar1;
    param_1[5] = local_10 * fVar3 + 1.0f;
    param_1[6] = fVar2 * local_10;
    param_1[7] = 0.0f;
    param_1[8] = local_c * fVar1;
    param_1[9] = local_c * fVar3;
    param_1[10] = local_c * fVar2 + 1.0f;
    param_1[0xb] = 0.0f;
    param_1[0xc] = local_8 * fVar1;
    param_1[0xd] = local_8 * fVar3;
    param_1[0xe] = local_8 * fVar2;
    param_1[0xf] = 1.0f;
    return;
}

// ===========================================================================
// 0x005f5a53 — observed shape
// Four-quaternion interpolation/spline helper: selects sign-compatible
// representatives for param_4/5/6/7 against the accumulated vector, builds
// two interpolated quaternions (param_1, param_2) and returns param_3 as the
// resulting delta quaternion. Uses the 005f3xxx quaternion thunks.
// ===========================================================================
void FUN_005f5a53(float* param_1, float* param_2, float* param_3, float* param_4,
                  float* param_5, float* param_6, float* param_7) {
    undefined1 local_a4[16];
    float local_94;
    float local_90;
    float local_8c;
    float local_88;
    float local_84;
    float local_80;
    float local_7c;
    float local_78;
    float local_74;
    float local_70;
    float local_6c;
    float local_68;
    float local_64;
    float local_60;
    float local_5c;
    float local_58;
    float local_54;
    float local_50;
    float local_4c;
    float local_48;
    float local_44;
    float local_40;
    float local_3c;
    float fStack_38;
    float local_34;
    float local_30;
    float local_2c;
    float local_28;
    float local_24;
    float local_20;
    float local_1c;
    float local_18;
    float local_14;
    float local_10;
    float local_c;
    float local_8;

    local_84 = *param_4;
    local_80 = param_4[1];
    local_7c = param_4[2];
    local_78 = param_4[3];
    local_54 = *param_5;
    local_50 = param_5[1];
    local_4c = param_5[2];
    local_48 = param_5[3];
    local_24 = *param_6;
    local_20 = param_6[1];
    local_1c = param_6[2];
    local_18 = param_6[3];
    local_74 = *param_7;
    local_70 = param_7[1];
    local_6c = param_7[2];
    local_68 = param_7[3];
    if ((local_54 + local_84) * (local_54 + local_84) +
            (local_50 + local_80) * (local_50 + local_80) +
            (local_4c + local_7c) * (local_4c + local_7c) +
            (local_48 + local_78) * (local_48 + local_78)
        < (local_84 - local_54) * (local_84 - local_54) +
              (local_80 - local_50) * (local_80 - local_50) +
              (local_7c - local_4c) * (local_7c - local_4c) +
              (local_78 - local_48) * (local_78 - local_48)) {
        local_84 = -local_84;
        local_80 = -local_80;
        local_7c = -local_7c;
        local_78 = -local_78;
        local_34 = local_84;
        local_30 = local_80;
        local_2c = local_7c;
        local_28 = local_78;
    }
    if ((local_24 + local_54) * (local_24 + local_54) +
            (local_20 + local_50) * (local_20 + local_50) +
            (local_1c + local_4c) * (local_1c + local_4c) +
            (local_18 + local_48) * (local_18 + local_48)
        < (local_54 - local_24) * (local_54 - local_24) +
              (local_50 - local_20) * (local_50 - local_20) +
              (local_4c - local_1c) * (local_4c - local_1c) +
              (local_48 - local_18) * (local_48 - local_18)) {
        local_34 = -local_24;
        local_30 = -local_20;
        local_2c = -local_1c;
        local_28 = -local_18;
        local_24 = local_34;
        local_20 = local_30;
        local_1c = local_2c;
        local_18 = local_28;
    }
    local_10 = local_20 - local_70;
    local_c = local_1c - local_6c;
    local_8 = local_18 - local_68;
    if ((local_74 + local_24) * (local_74 + local_24) +
            (local_70 + local_20) * (local_70 + local_20) +
            (local_6c + local_1c) * (local_6c + local_1c) +
            (local_68 + local_18) * (local_68 + local_18)
        < (local_24 - local_74) * (local_24 - local_74) +
              local_10 * local_10 + local_c * local_c + local_8 * local_8) {
        local_74 = -local_74;
        local_70 = -local_70;
        local_6c = -local_6c;
        local_68 = -local_68;
        local_34 = local_74;
        local_30 = local_70;
        local_2c = local_6c;
        local_28 = local_68;
    }
    thunk_FUN_005f3dd2(&local_34, &local_54);
    thunk_FUN_005f3d0e(&local_44, &local_34, &local_84);
    local_64 = local_44;
    local_60 = local_40;
    local_5c = local_3c;
    local_58 = fStack_38;
    thunk_FUN_005f3e9e(&local_94, &local_64);
    thunk_FUN_005f3d0e(&local_44, &local_34, &local_24);
    local_64 = local_44;
    local_60 = local_40;
    local_5c = local_3c;
    local_58 = fStack_38;
    thunk_FUN_005f3e9e(&local_14, &local_64);
    local_40 = local_90 + local_10;
    local_3c = local_8c + local_c;
    local_64 = (local_94 + local_14) * -0.25f;
    local_60 = local_40 * -0.25f;
    local_5c = local_3c * -0.25f;
    local_58 = (local_88 + local_8) * -0.25f;
    thunk_FUN_005f3f34(local_a4, &local_64);
    thunk_FUN_005f3d0e(&local_44, &local_54, local_a4);
    *param_1 = local_44;
    param_1[1] = local_40;
    param_1[2] = local_3c;
    param_1[3] = fStack_38;
    thunk_FUN_005f3dd2(&local_34, &local_24);
    thunk_FUN_005f3d0e(&local_44, &local_34, &local_54);
    local_64 = local_44;
    local_60 = local_40;
    local_5c = local_3c;
    local_58 = fStack_38;
    thunk_FUN_005f3e9e(&local_94, &local_64);
    thunk_FUN_005f3d0e(&local_44, &local_34, &local_74);
    local_64 = local_44;
    local_60 = local_40;
    local_5c = local_3c;
    local_58 = fStack_38;
    thunk_FUN_005f3e9e(&local_14, &local_64);
    local_40 = local_90 + local_10;
    local_3c = local_8c + local_c;
    local_64 = (local_94 + local_14) * -0.25f;
    local_60 = local_40 * -0.25f;
    local_5c = local_3c * -0.25f;
    local_58 = (local_88 + local_8) * -0.25f;
    thunk_FUN_005f3f34(local_a4, &local_64);
    thunk_FUN_005f3d0e(&local_44, &local_24, local_a4);
    *param_2 = local_44;
    param_2[1] = local_40;
    param_2[2] = local_3c;
    param_2[3] = fStack_38;
    *param_3 = local_24;
    param_3[1] = local_20;
    param_3[2] = local_1c;
    param_3[3] = local_18;
    return;
}

// ===========================================================================
// 0x005f5e54 — observed shape
// Linear scan of the 9-dword record table at DAT_006dc6c8 for a record whose
// first word equals param_1; returns the matching record or the default table
// entry at DAT_006dc6a0 when the end pointer is reached.
// ===========================================================================
int* FUN_005f5e54(int param_1) {
    int* piVar1;

    piVar1 = &DAT_006dc6c8;
    while (true) {
        if (PTR_DAT_00718a58 <= piVar1) {
            return (int*)&DAT_006dc6a0;
        }
        if (param_1 == *piVar1) break;
        piVar1 = piVar1 + 9;
    }
    return piVar1;
}

// ===========================================================================
// 0x005f5e7f — observed shape
// Compatibility score between two 9-dword records supplied in the register
// arguments (ECX = reference record, EDX = candidate record). Gates on the
// byte-compatibility matrix DAT_006dced0[ref[1]*5 + cand[1]] and accumulates
// per-field penalty bits. Returns 0xffffffff when the matrix entry is zero or
// the nonzero-field count does not match the high score byte.
// ===========================================================================
uint32_t FUN_005f5e7f(int* self_ecx, int* self_edx) {
    uint32_t uVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    int iVar4;
    uint32_t* puVar5;
    uint32_t local_8;

    uVar3 = 0;
    if (DAT_006dced0[*(int*)((char*)self_ecx + 4) * 5 +
                      *(int*)((char*)self_edx + 4)] != 0) {
        local_8 = 0;
        puVar5 = (uint32_t*)((char*)self_ecx + 0xc);
        iVar4 = 5;
        do {
            uVar1 = *puVar5;
            if (uVar1 != 0) {
                local_8 = local_8 + 1;
            }
            uVar2 = *(uint32_t*)((char*)puVar5 + ((char*)self_edx - (char*)self_ecx));
            if (uVar1 < uVar2) {
                if (uVar1 == 0) {
                    uVar3 = uVar3 + 0x100;
                } else {
                    uVar3 = uVar3 + (uVar2 - uVar1);
                }
            } else if (uVar2 < uVar1) {
                if (uVar2 == 0) {
                    uVar3 = uVar3 + 0x1000000;
                } else {
                    uVar3 = uVar3 + (uVar1 - uVar2) * 0x10000;
                }
            }
            puVar5 = puVar5 + 1;
            iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        if (local_8 != uVar3 >> 0x18) {
            return uVar3;
        }
    }
    return 0xffffffff;
}

// ===========================================================================
// 0x005f5ef6 — observed shape
// Picks the best matching adapter/record from the table for a requested
// format. Queries adapter info through vtable slots 0x18/0x1c/0x20/0x24/0x28,
// walks the 9-dword table, and keeps the record with the lowest compatibility
// score (ties broken by the record's third word).
// ===========================================================================
int FUN_005f5ef6(int* param_1, uint32_t param_2, undefined4 param_3, int* param_4) {
    int iVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    int* piVar4;
    int* piVar5;
    undefined4 local_158;
    undefined4 local_154;
    undefined1 local_28[12];
    undefined4 local_1c;
    undefined1 local_18[12];
    uint8_t local_c;
    int* local_8;

    local_8 = (int*)0x0;
    FUN_005f8ea2(1);
    if (param_1 != (int*)0x0) {
        reinterpret_cast<void (__thiscall*)(void*, int**)>(VSLOT(param_1, 0x18))(param_1, &local_8);
        reinterpret_cast<void (__thiscall*)(void*, undefined4*)>(VSLOT(param_1, 0x1c))(
            param_1, &local_158);
        reinterpret_cast<void (__thiscall*)(void*, int, undefined1*)>(VSLOT(param_1, 0x20))(
            param_1, 0, local_28);
        if (((param_2 & 0x100000) != 0) &&
            ((reinterpret_cast<void (__thiscall*)(void*, undefined1*)>(VSLOT(param_1, 0x24))(
                  param_1, local_18),
              (local_c & 0x20) != 0))) {
            param_2 = param_2 | 0x10;
        }
    }
    uVar3 = 0xffffffff;
    piVar5 = (int*)&DAT_006dc6a0;
    piVar4 = &DAT_006dc6c8;
    if (&DAT_006dc6c8 < PTR_DAT_00718a58) {
        do {
            if ((*piVar4 != 0) &&
                ((local_8 == (int*)0x0 ||
                  (iVar1 = reinterpret_cast<int (__thiscall*)(void*, undefined4, undefined4,
                                                              undefined4, uint32_t, undefined4, int)>(
                       VSLOT(local_8, 0x28))(local_8, local_154, local_158, local_1c, param_2,
                                             param_3, *piVar4),
                   -1 < iVar1)))) {
                if (*param_4 == *piVar4) {
                    piVar5 = piVar4;
                    break;
                }
                // The provider emitted a zero-argument call here; the two records
                // compared are the loop's candidate (EDX) and current best (ECX).
                if ((((piVar4[8] != 0) &&
                      (uVar2 = FUN_005f5e7f(piVar5, piVar4), uVar2 != 0xffffffff)) &&
                     (uVar2 <= uVar3)) &&
                    ((uVar2 != uVar3 || ((uint32_t)piVar4[2] < (uint32_t)piVar5[2])))) {
                    uVar3 = uVar2;
                    piVar5 = piVar4;
                }
            }
            piVar4 = piVar4 + 9;
        } while (piVar4 < PTR_DAT_00718a58);
    }
    if (local_8 != (int*)0x0) {
        reinterpret_cast<void (__thiscall*)(void*)>(VSLOT(local_8, 8))(local_8);
        local_8 = (int*)0x0;
    }
    FUN_005f8ea2(0);
    return *piVar5;
}

// ===========================================================================
// 0x005f5ff4 — observed shape
// Maps two FourCC-like format words to a canonical depth/index:
// 'AL16' (0x36314c41) -> 0x33, ' R16' (0x36315220) -> 0x24, else passthrough.
// ===========================================================================
int FUN_005f5ff4(int param_1) {
    int iStack_8;

    if (param_1 == 0x36314c41) {
        iStack_8 = 0x33;
    } else {
        if (param_1 != 0x36315220) {
            return param_1;
        }
        iStack_8 = 0x24;
    }
    return iStack_8;
}

// ===========================================================================
// 0x005f6018 — observed shape
// Type-3 path surface creation: validates arguments, decodes the format block,
// fills the 0x48-byte local descriptor, copies the 16-byte color key, and calls
// FUN_005ff591. Wrapped by the 005fbd43/005fbd4d critical-section pair.
// ===========================================================================
int FUN_005f6018(int* param_1, undefined4 param_2, undefined4 param_3, int* param_4,
                 undefined4 param_5, undefined4 param_6, undefined4 param_7, int* param_8,
                 int param_9, undefined4 param_10) {
    int iVar1;
    int iVar2;
    int* puVar3;
    int* puVar4;
    undefined1 local_cc[72];
    undefined4 local_84;
    int local_64;
    undefined4 local_60;
    undefined4 local_5c;
    undefined4 local_58;
    int local_54[4];
    undefined4 local_44;
    undefined4 local_40;
    undefined4 local_3c[8];
    undefined4 local_1c;
    undefined4 local_18;
    undefined4 local_14;

    FUN_005fbd43();
    FUN_005ff6ce();
    if (param_1 == 0) {
        iVar2 = -0x7789f794;
    } else if ((param_4 == 0) || (param_8 == (int*)0x0)) {
        iVar2 = -0x7789f794;
    } else {
        if (param_9 == -1) {
            param_9 = 0x80004;
        }
        iVar1 = FUN_005ff8a2(local_cc, (int)param_1, param_2, param_3, 0, 0);
        if (-1 < iVar1) {
            local_60 = param_5;
            local_5c = param_6;
            local_64 = (int)param_4;
            local_58 = 0;
            local_54[0] = param_8[0];
            local_54[1] = param_8[1];
            local_54[2] = param_8[2];
            local_54[3] = param_8[3];
            local_44 = 0;
            local_40 = 1;
            puVar3 = local_54;
            puVar4 = local_3c;
            for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
                *puVar4 = *puVar3;
                puVar3 = puVar3 + 1;
                puVar4 = puVar4 + 1;
            }
            local_1c = local_84;
            local_18 = param_10;
            local_14 = param_7;
            iVar1 = FUN_005ff591(local_cc, &local_64, param_9);
            iVar2 = 0;
            if (-1 < iVar1) goto LAB_005f60e9;
        }
        iVar2 = iVar1;
    }
LAB_005f60e9:
    thunk_FUN_005ff7c0();
    FUN_005fbd4d();
    return iVar2;
}

// ===========================================================================
// 0x005f6100 — observed shape
// Type-4/5 path surface creation: same shape as 005f6018 with an extra format
// word (param_7) and a 0x6c-byte descriptor; copies two 6-dword blocks from the
// caller's color-key/rect array then calls FUN_005ff591.
// ===========================================================================
int FUN_005f6100(int* param_1, undefined4 param_2, undefined4 param_3, int* param_4,
                 undefined4 param_5, undefined4 param_6, undefined4 param_7, int* param_8,
                 undefined4* param_9, int param_10, undefined4 param_11) {
    int iVar1;
    undefined4* puVar2;
    undefined4* puVar3;
    int iVar4;
    undefined1 local_bc[72];
    undefined4 local_74;
    int local_68;
    undefined4 local_64;
    undefined4 local_60;
    undefined4 local_5c;
    undefined4 local_58[6];
    undefined4 local_40[8];
    undefined4 local_20;
    undefined4 local_1c;
    int* local_18;

    FUN_005fbd43();
    FUN_005ff873();
    if (((param_1 == 0) || (param_4 == 0)) || (param_9 == (undefined4*)0x0)) {
        iVar1 = -0x7789f794;
    } else {
        if (param_10 == -1) {
            param_10 = 0x80004;
        }
        iVar1 = FUN_005ffd96(local_bc, (int)param_1, param_2, param_3, 0, 0);
        if (-1 < iVar1) {
            local_64 = param_5;
            local_60 = param_6;
            local_5c = param_7;
            local_68 = (int)param_4;
            iVar4 = 6;
            puVar2 = param_9;
            puVar3 = local_58;
            for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
                *puVar3 = *puVar2;
                puVar2 = puVar2 + 1;
                puVar3 = puVar3 + 1;
            }
            puVar2 = local_40;
            for (; iVar4 != 0; iVar4 = iVar4 + -1) {
                *puVar2 = *param_9;
                param_9 = param_9 + 1;
                puVar2 = puVar2 + 1;
            }
            local_20 = local_74;
            local_1c = param_11;
            local_18 = param_8;
            iVar1 = FUN_005ff591(local_bc, &local_68, param_10);
            if (-1 < iVar1) {
                iVar1 = 0;
            }
        }
    }
    thunk_FUN_005ff879();
    FUN_005fbd4d();
    return iVar1;
}

// ===========================================================================
// 0x005f61dc — observed shape
// Shared surface-description resolver for Direct3D-style adapters. Sanitizes
// the usage mask, maps special format codes through FUN_005f5e54/FUN_005f5ef6,
// derives width/height/depth defaults, clamps to adapter caps, rounds levels
// and sizes, and writes the resolved values through the out parameters.
// The receiver is passed in EDX in the original (modelled as `self`).
// ===========================================================================
uint32_t FUN_005f61dc(int* self, uint32_t* param_1, uint32_t* param_2, uint32_t* param_3,
                      uint32_t* param_4, uint32_t param_5, int* param_6, int param_7,
                      uint32_t param_8) {
    int* uVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    uint32_t local_10c;
    uint32_t local_f0;
    uint32_t local_ec;
    uint32_t local_e8;
    int local_e0;
    uint32_t local_18;
    int local_14;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;

    if (self == (int*)0x0) {
        return 0x8876086c;
    }
    if (param_5 == 0xffffffff) {
        param_5 = 0;
    }
    if (((param_5 & 0xffe039ec) != 0) ||
        ((((param_7 != 0 && (param_7 != 1)) && (param_7 != 2)) && (param_7 != 3)))) {
        return 0x8876086c;
    }
    if (param_6 == (int*)0x0) {
        local_14 = 0;
    } else {
        local_14 = *param_6;
    }
    if (param_7 == 3) {
        if (local_14 == 0) {
            local_14 = 0x15;
        }
    } else {
        uVar1 = FUN_005f5e54(local_14);
        local_14 = FUN_005f5ef6(self, param_5, param_8, uVar1);
        if (local_14 == 0) {
            return 0x8876086a;
        }
    }
    if (param_1 == (uint32_t*)0x0) {
        local_c = 0xffffffff;
    } else {
        local_c = *param_1;
    }
    if (param_2 == (uint32_t*)0x0) {
        local_8 = 0xffffffff;
    } else {
        local_8 = *param_2;
    }
    if (param_3 == (uint32_t*)0x0) {
        local_10 = 0xffffffff;
    } else {
        local_10 = *param_3;
    }
    if (param_4 == (uint32_t*)0x0) {
        local_18 = 0xffffffff;
    } else {
        local_18 = *param_4;
    }
    if (local_c == 0xffffffff) {
        if (local_8 != 0xffffffff) {
            local_c = local_8;
            goto LAB_005f62eb;
        }
        local_8 = 0x100;
        local_c = 0x100;
    } else {
        if (local_8 == 0xffffffff) {
            local_8 = local_c;
        }
LAB_005f62eb:
        if (local_c == 0) {
            local_c = 1;
        }
        if (local_8 == 0) {
            local_8 = 1;
        }
    }
    if (param_8 == 5) {
        if (local_8 < local_c) {
            local_8 = local_c;
        }
        local_c = local_8;
    }
    if ((local_10 == 0xffffffff) || (local_10 == 0)) {
        local_10 = 1;
    }
    if (param_7 == 3) goto LAB_005f645c;
    // NEEDS_MANUAL: the provider printed this vtable call with no argument list,
    // yet the following blocks read local_10c/local_e8/local_f0/local_ec, which
    // the callee must write. Argument recovery was not possible from the corpus.
    reinterpret_cast<void (__thiscall*)(void*)>(VSLOT(self, 0x1c))(self);
    if (param_8 == 4) {
        if (local_e8 < local_10) {
            local_10 = local_e8;
        }
        if (local_e8 < local_c) {
            local_c = local_e8;
        }
LAB_005f63bb:
        if (local_e8 < local_8) {
            local_8 = local_e8;
        }
    } else {
        if (local_f0 < local_c) {
            local_c = local_f0;
        }
        if (local_ec < local_8) {
            local_8 = local_ec;
        }
        if (param_8 == 3) {
            if ((local_10c & 0x20) != 0) {
                local_e0 = 1;
            }
            if (local_e0 != 0) {
                if (local_e0 * local_8 < local_c) {
                    local_c = local_e0 * local_8;
                }
                local_e8 = local_e0 * local_c;
                goto LAB_005f63bb;
            }
        }
    }
    uVar4 = local_8;
    uVar3 = local_c;
    uVar5 = local_10;
    if (param_8 == 3) {
        uVar2 = 2;
    } else if (param_8 == 4) {
        uVar2 = 0x40000;
    } else if (param_8 == 5) {
        uVar2 = 0x20000;
    } else {
        uVar2 = param_8;
    }
    if ((((local_18 == 1) && ((local_10c & 0x100) != 0)) &&
         ((local_14 != 0x31545844 &&
           (((local_14 != 0x32545844 && (local_14 != 0x33545844)) &&
             (local_14 != 0x34545844)))))) &&
        (local_14 != 0x35545844)) {
        uVar2 = 0;
    }
    if ((local_10c & uVar2) != 0) {
        local_c = 1;
        if (1 < uVar3) {
            do {
                local_c = local_c << 1;
            } while (local_c < uVar3);
        }
        local_8 = 1;
        if (1 < uVar4) {
            do {
                local_8 = local_8 << 1;
            } while (local_8 < uVar4);
        }
        local_10 = 1;
        if (1 < uVar5) {
            do {
                local_10 = local_10 << 1;
            } while (local_10 < uVar5);
        }
    }
LAB_005f645c:
    if (((local_14 == 0x31545844) || (local_14 == 0x32545844)) ||
        ((local_14 == 0x33545844 ||
          ((local_14 == 0x34545844 || (local_14 == 0x35545844)))))) {
        local_c = local_c + 3 & 0xfffffffc;
        local_8 = local_8 + 3 & 0xfffffffc;
    }
    if (param_8 == 3) {
        uVar5 = 0x4000;
    } else if (param_8 == 4) {
        uVar5 = 0x8000;
    } else if (param_8 == 5) {
        uVar5 = 0x10000;
    } else {
        uVar5 = param_8;
    }
    if ((param_7 == 3) ||
        (((local_10c & uVar5) != 0 &&
          (((local_10c & 0x100) == 0 ||
            ((((local_c & local_c - 1) == 0 && ((local_8 & local_8 - 1) == 0)) &&
              ((local_10 & local_10 - 1) == 0)))))))) {
        uVar5 = 0;
        for (uVar3 = local_c; uVar3 != 0; uVar3 = uVar3 >> 1) {
            uVar5 = uVar5 + 1;
        }
        uVar3 = 0;
        for (uVar4 = local_8; uVar4 != 0; uVar4 = uVar4 >> 1) {
            uVar3 = uVar3 + 1;
        }
        uVar2 = 0;
        for (uVar4 = local_10; uVar4 != 0; uVar4 = uVar4 >> 1) {
            uVar2 = uVar2 + 1;
        }
        if (uVar5 <= uVar3) {
            uVar5 = uVar3;
        }
        if ((param_8 == 4) && (uVar5 < uVar2)) {
            uVar5 = uVar2;
        }
        if ((uVar5 < local_18) || (local_18 == 0)) {
            local_18 = uVar5;
        }
        if ((local_18 != 1) && ((param_5 & 0x400) != 0)) {
            local_18 = 0;
        }
    } else {
        local_18 = 1;
    }
    if (param_1 != (uint32_t*)0x0) {
        *param_1 = local_c;
    }
    if (param_2 != (uint32_t*)0x0) {
        *param_2 = local_8;
    }
    if (param_3 != (uint32_t*)0x0) {
        *param_3 = local_10;
    }
    if (param_4 != (uint32_t*)0x0) {
        *param_4 = local_18;
    }
    if (param_6 != (int*)0x0) {
        *param_6 = local_14;
    }
    return 0;
}

// ===========================================================================
// 0x005f6591 — observed shape
// Type-3 surface copy: validates the source/destination descriptions, checks
// the destination foreign-description fast path (vtable +0x30 twice), falls
// back to 005f6018 on mismatch, and uses vtable +0x78/+0x88 for same-adapter
// copies. Wrapped by FUN_005ff6ce / thunk_FUN_005ff7c0.
// ===========================================================================
int FUN_005f6591(int* param_1, int* param_2, int* param_3, int* param_4, int* param_5,
                 int* param_6, uint32_t param_7, int param_8) {
    int* piVar1;
    undefined4 uVar2;
    int iVar3;
    int* piVar4;
    int* piVar5;
    bool bVar6;
    undefined4 local_cc;
    undefined4 local_c8;
    undefined4 local_c4;
    undefined1 local_a4[64];
    undefined1 local_64[12];
    int local_58;
    int local_4c;
    int local_48;
    undefined1 local_44[12];
    int local_38;
    int local_2c;
    int local_28;
    int local_24;
    int local_20;
    int local_1c;
    int local_18;
    int local_14;
    int local_10;
    int local_c;
    int local_8;

    FUN_005ff6ce();
    piVar1 = param_4;
    if (param_1 == (int*)0x0) {
        iVar3 = -0x7789f794;
        goto LAB_005f6796;
    }
    if (param_4 == (int*)0x0) {
        iVar3 = -0x7789f794;
        goto LAB_005f6796;
    }
    reinterpret_cast<void (__thiscall*)(void*, void*)>(VSLOT(param_1, 0x30))(param_1, local_64);
    reinterpret_cast<void (__thiscall*)(void*, void*)>(VSLOT(piVar1, 0x30))(piVar1, local_44);
    if (((param_7 & 0xffff) == 5) || (param_8 != 0)) {
LAB_005f66fc:
        uVar2 = 1;
        if (param_1 == piVar1) {
            uVar2 = 0x10001;
        }
        iVar3 = FUN_005ff8a2(&local_cc, (int)piVar1, (undefined4)param_5, (undefined4)param_6, 0,
                             uVar2);
        if ((iVar3 < 0) ||
            (iVar3 = FUN_005f6018(param_1, (undefined4)param_2, (undefined4)param_3, (int*)local_cc,
                                  local_c8, local_c4, (undefined4)param_5, (int*)local_a4,
                                  (int)param_7, param_8),
             iVar3 < 0)) {
            goto LAB_005f6796;
        }
        if ((local_38 == 0) && (local_58 != 0)) {
            reinterpret_cast<void (__thiscall*)(void*, int**)>(
                VSLOT(piVar1, 0xc))(piVar1, &param_1);
            iVar3 = reinterpret_cast<int (__thiscall*)(void*)>(VSLOT(param_1, 0xc))(param_1);
            reinterpret_cast<void (__thiscall*)(void*)>(VSLOT(param_1, 8))(param_1);
            if (iVar3 != 0) {
                iVar3 = -0x7789f798;
                goto LAB_005f6796;
            }
        }
    } else {
        if (param_2 != param_5) {
            if ((param_2 != (int*)0x0) && (param_5 != (int*)0x0)) {
                iVar3 = 0x100;
                bVar6 = true;
                piVar4 = param_2;
                piVar5 = param_5;
                do {
                    if (iVar3 == 0) break;
                    iVar3 = iVar3 + -1;
                    bVar6 = *piVar4 == *piVar5;
                    piVar4 = piVar4 + 1;
                    piVar5 = piVar5 + 1;
                } while (bVar6);
                if (bVar6) goto LAB_005f6621;
            }
            goto LAB_005f66fc;
        }
LAB_005f6621:
        if (param_3 == (int*)0x0) {
            local_14 = 0;
            local_10 = 0;
            local_c = local_4c;
            local_8 = local_48;
        } else {
            local_14 = *param_3;
            local_10 = param_3[1];
            local_c = param_3[2];
            local_8 = param_3[3];
        }
        if (param_6 == (int*)0x0) {
            local_24 = 0;
            local_20 = 0;
            local_1c = local_2c;
            local_18 = local_28;
        } else {
            local_24 = *param_6;
            local_20 = param_6[1];
            local_1c = param_6[2];
            local_18 = param_6[3];
        }
        if ((local_c - local_14 != local_1c - local_24) ||
            (local_8 - local_10 != local_18 - local_20)) {
            goto LAB_005f66fc;
        }
        reinterpret_cast<void (__thiscall*)(void*, int**)>(
            VSLOT(piVar1, 0xc))(piVar1, &param_4);
        FUN_005f8ea2(1);
        iVar3 = -0x7fffbffb;
        if (local_58 == 0) {
            if (local_38 == 0) {
                iVar3 = reinterpret_cast<int (__thiscall*)(void*, int*, int*, int*, int*, int)>(
                    VSLOT(param_4, 0x88))(param_4, piVar1, &local_24, param_1, &local_14, 0);
            } else if (local_38 == 2) {
                iVar3 = reinterpret_cast<int (__thiscall*)(void*, int*, int*, int*, int*)>(
                    VSLOT(param_4, 0x78))(param_4, piVar1, &local_24, param_1, &local_14);
            }
        }
        FUN_005f8ea2(0);
        reinterpret_cast<void (__thiscall*)(void*)>(VSLOT(param_4, 8))(param_4);
        if (iVar3 < 0) goto LAB_005f66fc;
    }
    iVar3 = 0;
LAB_005f6796:
    thunk_FUN_005ff7c0();
    return iVar3;
}

// ===========================================================================
// 0x005f67a5 — observed shape
// Type-4 surface copy companion to 005f6591: builds the 0x48-byte descriptor
// with FUN_005ffd96 and calls FUN_005f6100.
// ===========================================================================
int FUN_005f67a5(int* param_1, undefined4 param_2, undefined4 param_3, int* param_4,
                 undefined4 param_5, undefined4 param_6, undefined4 param_7, undefined4 param_8) {
    undefined4 uVar1;
    int iVar2;
    int iVar3;
    undefined4 local_5c;
    undefined4 local_58;
    undefined4 local_54;
    undefined4 local_50;
    undefined1 local_34[48];

    FUN_005ff873();
    if ((param_1 == 0) || (param_4 == 0)) {
        iVar3 = -0x7789f794;
    } else {
        uVar1 = 1;
        if (param_1 == param_4) {
            uVar1 = 0x10001;
        }
        iVar2 = FUN_005ffd96(&local_5c, (int)param_4, param_5, param_6, 0, uVar1);
        if (-1 < iVar2) {
            iVar2 = FUN_005f6100(param_1, param_2, param_3, (int*)local_5c, local_58, local_54,
                                 local_50, (int*)param_5, (undefined4*)local_34, (int)param_7,
                                 param_8);
            iVar3 = 0;
            if (-1 < iVar2) goto LAB_005f681e;
        }
        iVar3 = iVar2;
    }
LAB_005f681e:
    thunk_FUN_005ff879();
    return iVar3;
}

// ===========================================================================
// 0x005f682d — observed shape
// Enumerates and blits a chain of surface/level objects. Reads the object type
// through vtable +0x28, resolves a usage mask from subresource caps, descends
// the level chain via the +0x48 lock getter, calls 005f6591/005f67a5 per pair,
// then 005f682d's caller-visible result via vtable +0x5c/+0x60/+0x64.
// ===========================================================================
uint32_t FUN_005f682d(int* param_1, undefined4 param_2, uint32_t param_3, uint32_t param_4) {
    int* piVar1;
    uint32_t uVar2;
    int** ppiVar3;
    uint32_t uVar4;
    undefined1 local_64[24];
    uint32_t local_4c;
    uint32_t local_48;
    undefined1 local_44[16];
    uint32_t local_34;
    uint32_t local_30;
    uint32_t local_2c;
    uint32_t local_28;
    uint32_t local_24;
    int local_20;
    int* local_1c;
    uint32_t local_18;
    int local_14;
    int* local_10;
    int* local_c;
    int* local_8;

    piVar1 = param_1;
    if ((param_1 == (int*)0x0) ||
        (((local_14 = reinterpret_cast<int (__thiscall*)(void*)>(VSLOT(param_1, 0x28))(param_1),
           local_14 != 3 && (local_14 != 4)) &&
          (local_14 != 5)))) {
        return 0x8876086c;
    }
    local_1c = piVar1;
    if (param_4 != 0xffffffff) goto LAB_005f68cd;
    if (local_14 == 3) {
        reinterpret_cast<void (__thiscall*)(void*, int, void*)>(VSLOT(piVar1, 0x44))(
            piVar1, 0, local_64);
        if (((local_4c & local_4c - 1) != 0) || ((local_48 & local_48 - 1) != 0)) {
            param_4 = 0;
LAB_005f6907:
            if (param_4 == 0) goto LAB_005f68c6;
        }
LAB_005f690c:
        param_4 = 5;
    } else {
        if (local_14 == 4) {
            reinterpret_cast<void (__thiscall*)(void*, int, void*)>(VSLOT(piVar1, 0x44))(
                piVar1, 0, local_44);
            if (((local_34 & local_34 - 1) == 0) && ((local_30 & local_30 - 1) == 0)) {
                local_48 = local_2c;
LAB_005f68bf:
                if ((local_48 & local_48 - 1) == 0) goto LAB_005f690c;
            }
        } else {
            if (local_14 != 5) goto LAB_005f6907;
            reinterpret_cast<void (__thiscall*)(void*, int, void*)>(VSLOT(piVar1, 0x44))(
                piVar1, 0, local_64);
            if ((local_4c & local_4c - 1) == 0) goto LAB_005f68bf;
        }
LAB_005f68c6:
        param_4 = 0x80004;
    }
LAB_005f68cd:
    if (local_14 == 5) {
        param_4 = param_4 | 0x70000;
    }
    if ((param_4 & 0x400000) == 0) {
        param_4 = param_4 & 0xff9fffff;
    } else {
        param_4 = param_4 | 0x600000;
    }
    local_24 = reinterpret_cast<uint32_t (__thiscall*)(void*)>(VSLOT(piVar1, 0x34))(piVar1);
    if (param_3 == 0xffffffff) {
        param_3 = 0;
    }
    if (param_3 < local_24) {
        param_1 = (int*)0x0;
        local_c = (int*)0x0;
        local_8 = (int*)0x0;
        local_10 = (int*)0x0;
        local_28 = ((local_14 != 5) - 1 & 5) + 1;
        if (((param_4 & 0xff) == 2) || (local_20 = 0, (param_4 & 0xff) == 5)) {
            local_20 = 1;
        }
        local_18 = 0;
        if (local_28 != 0) {
            uVar2 = param_4;
            do {
                if (local_14 == 3) {
                    ppiVar3 = &param_1;
LAB_005f69a6:
                    uVar2 = reinterpret_cast<uint32_t (__thiscall*)(void*, uint32_t, int**)>(
                        VSLOT(local_1c, 0x48))(local_1c, param_3, ppiVar3);
                } else {
                    if (local_14 == 4) {
                        ppiVar3 = &local_c;
                        goto LAB_005f69a6;
                    }
                    if (local_14 == 5) {
                        uVar2 = reinterpret_cast<uint32_t (__thiscall*)(void*, uint32_t, uint32_t,
                                                                        int**)>(
                            VSLOT(local_1c, 0x48))(local_1c, local_18, param_3, &param_1);
                    }
                }
                if ((int)uVar2 < 0) goto LAB_005f6ad9;
                uVar4 = param_3;
LAB_005f6a9e:
                uVar4 = uVar4 + 1;
                if (uVar4 < local_24) {
                    if (local_14 == 3) {
                        ppiVar3 = &local_8;
LAB_005f69ee:
                        uVar2 = reinterpret_cast<uint32_t (__thiscall*)(void*, uint32_t, int**)>(
                            VSLOT(local_1c, 0x48))(local_1c, uVar4, ppiVar3);
                    } else {
                        if (local_14 == 4) {
                            ppiVar3 = &local_10;
                            goto LAB_005f69ee;
                        }
                        if (local_14 == 5) {
                            uVar2 = reinterpret_cast<uint32_t (__thiscall*)(
                                void*, uint32_t, uint32_t, int**)>(VSLOT(local_1c, 0x48))(
                                local_1c, local_18, uVar4, &local_8);
                        }
                    }
                    if (-1 < (int)uVar2) {
                        if (local_14 == 3) {
LAB_005f6a11:
                            uVar2 = FUN_005f6591(
                                local_8, (int*)param_2, 0, param_1, (int*)param_2, 0, param_4, 0);
                        } else if (local_14 == 4) {
                            uVar2 = FUN_005f67a5(
                                local_10, param_2, 0, local_c, param_2, 0, param_4, 0);
                        } else if (local_14 == 5) {
                            goto LAB_005f6a11;
                        }
                        if (-1 < (int)uVar2) {
                            if (local_20 == 0) goto LAB_005f6a7e;
                            if (param_1 != (int*)0x0) {
                                reinterpret_cast<void (__thiscall*)(void*)>(
                                    VSLOT(param_1, 8))(param_1);
                                param_1 = (int*)0x0;
                            }
                            if (local_c != (int*)0x0) {
                                reinterpret_cast<void (__thiscall*)(void*)>(
                                    VSLOT(local_c, 8))(local_c);
                            }
                            param_1 = local_8;
                            local_8 = (int*)0x0;
                            local_c = local_10;
                            goto LAB_005f6a9b;
                        }
                    }
                    goto LAB_005f6ad9;
                }
                if (param_1 != (int*)0x0) {
                    reinterpret_cast<void (__thiscall*)(void*)>(VSLOT(param_1, 8))(param_1);
                    param_1 = (int*)0x0;
                }
                if (local_c != (int*)0x0) {
                    reinterpret_cast<void (__thiscall*)(void*)>(VSLOT(local_c, 8))(local_c);
                    local_c = (int*)0x0;
                }
                local_18 = local_18 + 1;
            } while (local_18 < local_28);
        }
        uVar2 = 0;
LAB_005f6ad9:
        if (param_1 != (int*)0x0) {
            reinterpret_cast<void (__thiscall*)(void*)>(VSLOT(param_1, 8))(param_1);
            param_1 = (int*)0x0;
        }
        if (local_c != (int*)0x0) {
            reinterpret_cast<void (__thiscall*)(void*)>(VSLOT(local_c, 8))(local_c);
            local_c = (int*)0x0;
        }
        if (local_8 != (int*)0x0) {
            reinterpret_cast<void (__thiscall*)(void*)>(VSLOT(local_8, 8))(local_8);
            local_8 = (int*)0x0;
        }
        if (local_10 != (int*)0x0) {
            reinterpret_cast<void (__thiscall*)(void*)>(VSLOT(local_10, 8))(local_10);
        }
    } else {
        uVar2 = 0x8876086c;
    }
    return uVar2;
LAB_005f6a7e:
    if (local_8 != (int*)0x0) {
        reinterpret_cast<void (__thiscall*)(void*)>(VSLOT(local_8, 8))(local_8);
        local_8 = (int*)0x0;
    }
    if (local_10 != (int*)0x0) {
        reinterpret_cast<void (__thiscall*)(void*)>(VSLOT(local_10, 8))(local_10);
LAB_005f6a9b:
        local_10 = (int*)0x0;
    }
    goto LAB_005f6a9e;
}

// ===========================================================================
// 0x005f6b1f — observed shape
// Full surface/level chain creator. Resolves the target format (005fba91),
// validates the format word (param_16 3/4/5) against the level chain length,
// expands usage masks, builds the 256-entry color-key table, chooses the format
// via 005f5ff4, resolves dimensions via 005f61dc, then walks every level/mip of
// the chain calling 005f6018/005f6100 and finally 005f682d's sibling logic
// through vtable +0x7c. Returns 0 on success or a D3D-style HRESULT.
// ===========================================================================
int FUN_005f6b1f(int* param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4,
                 int* param_5, uint32_t param_6, uint32_t param_7, uint32_t param_8,
                 uint32_t param_9, int param_10, uint32_t param_11, uint32_t param_12,
                 uint32_t param_13, int* param_14, undefined4* param_15, int param_16,
                 undefined4* param_17) {
    uint32_t* puVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    int** ppiVar4;
    int* piVar5;
    undefined4* puVar6;
    int* piVar7;
    int iVar8;
    uint32_t* puVar9;
    undefined4* puVar10;
    undefined4 local_4dc[256];
    int local_dc[7];
    int local_c0[2];
    int local_b8;
    uint32_t local_b4;
    int* local_b0;
    uint32_t local_ac;
    int local_74;
    int local_70;
    uint32_t local_6c[14];
    uint32_t local_34;
    uint32_t local_30;
    uint32_t local_2c;
    uint32_t local_28;
    uint32_t local_24;
    uint32_t local_20;
    uint32_t local_1c;
    int local_18;
    int local_14;
    int* local_10;
    int* local_c;
    int* local_8;

    piVar5 = param_14;
    uVar3 = param_4;
    FUN_005f9006();
    local_8 = (int*)0x0;
    param_14 = (int*)0x0;
    local_c = (int*)0x0;
    local_10 = (int*)0x0;
    if ((((param_1 == (int*)0x0) || (param_2 == 0)) || (param_3 == 0)) ||
        (param_17 == (undefined4*)0x0)) {
        iVar8 = -0x7789f794;
        goto LAB_005f7353;
    }
    local_6c[0xd] = (uint32_t)(uVar3 == 0xfffffffd);
    local_28 = (uint32_t)(param_5 == (int*)0xfffffffd);
    local_20 = (uint32_t)(param_6 == 0xfffffffd);
    local_30 = (uint32_t)(param_7 == 0xfffffffd);
    local_1c = (uint32_t)(param_9 == 0xfffffffd);
    if ((piVar5 == (int*)0x0) && (param_16 == -1)) {
        piVar5 = local_dc;
    }
    iVar8 = FUN_005fba91(param_2, param_3, piVar5, 1);
    if (iVar8 < 0) goto LAB_005f7353;
    if (param_16 == -1) {
        param_16 = piVar5[5];
    }
    param_3 = 1;
    // local_74 is the level-chain head seeded by FUN_005fba91's descriptor; the
    // provider did not expose the store textually.
    for (; local_74 != 0; local_74 = *(int*)(local_74 + 0x4c)) {
        param_3 = param_3 + 1;
    }
    param_2 = 1;
    if (param_16 == 5) {
        if (local_70 != 0) {
            do {
                local_70 = *(int*)(local_70 + 0x50);
                param_2 = param_2 + 1;
            } while (local_70 != 0);
            if (param_2 == 6) goto LAB_005f6c1f;
        }
        iVar8 = -0x7fffbffb;
        goto LAB_005f7353;
    }
LAB_005f6c1f:
    if (param_7 == 0xfffffffd) {
        param_7 = param_3;
    }
    if (((uVar3 == 0xfffffffe) || (uVar3 == 0xfffffffd)) || ((int)local_b4 < 0)) {
        param_4 = local_b4;
    } else if (((uVar3 == 0) || (uVar3 == 0xffffffff)) && (param_4 = 1, 1 < local_b4)) {
        do {
            param_4 = param_4 << 1;
        } while (param_4 < local_b4);
    }
    if (((param_5 == (int*)0xfffffffe) || (param_5 == (int*)0xfffffffd)) ||
        ((int)local_b0 < 0)) {
        param_5 = local_b0;
    } else if (((param_5 == (int*)0x0) || (param_5 == (int*)0xffffffff)) &&
               (param_5 = (int*)0x1, (int*)0x1 < local_b0)) {
        do {
            param_5 = (int*)((int)param_5 << 1);
        } while (param_5 < local_b0);
    }
    if (((param_6 == 0xfffffffe) || (param_6 == 0xfffffffd)) || ((int)local_ac < 0)) {
        param_6 = local_ac;
    } else if (((param_6 == 0) || (param_6 == 0xffffffff)) && (param_6 = 1, 1 < local_ac)) {
        do {
            param_6 = param_6 << 1;
        } while (param_6 < local_ac);
    }
    if (param_11 == 0xffffffff) {
        param_11 = 0x80004;
    }
    if (param_12 == 0xffffffff) {
        param_12 = 5;
    }
    if (param_16 == 5) {
        param_11 = param_11 | 0x70000;
        param_12 = param_12 | 0x70000;
    }
    if ((((char)param_11 == '\x01') || ((param_12 & 0xff) == 2)) || ((param_12 & 0xff) == 5)) {
        local_18 = 1;
    } else {
        local_18 = 0;
    }
    if (local_b8 == 0) {
        puVar6 = local_4dc;
        for (iVar8 = 0x100; iVar8 != 0; iVar8 = iVar8 + -1) {
            *puVar6 = 0xffffffff;
            puVar6 = puVar6 + 1;
        }
    } else {
        uVar3 = 0;
        do {
            uVar2 = *(uint32_t*)(local_b8 + uVar3 * 4);
            local_4dc[uVar3] =
                (uint32_t)(-(int32_t)(uVar2 != (param_13 >> 0x10 & 0xff | (param_13 & 0xff) << 0x10 |
                                                    param_13 & 0xff00ff00))) &
                uVar2;
            uVar3 = uVar3 + 1;
        } while (uVar3 < 0x100);
        param_13 = 0;
        if ((param_9 != 0x29) && (local_c0[0] == 0x29)) {
            uVar3 = 0;
            do {
                if (local_4dc[uVar3] != (((uVar3 | 0xffffff00) << 8 | uVar3) << 8 | uVar3)) break;
                uVar3 = uVar3 + 1;
            } while (uVar3 < 0x100);
            if (uVar3 == 0x100) {
                local_c0[0] = 0x32;
            } else {
                local_6c[3] = 0xff;
                local_6c[0xc] = 0xff;
                local_6c[0] = 0;
                local_6c[1] = 0x55;
                local_6c[2] = 0xaa;
                local_6c[5] = 0;
                local_6c[6] = 0x24;
                local_6c[7] = 0x49;
                local_6c[8] = 0x6d;
                local_6c[9] = 0x92;
                local_6c[10] = 0xb6;
                local_6c[0xb] = 0xdb;
                uVar3 = 0;
                do {
                    if (local_4dc[uVar3] !=
                        (((local_6c[uVar3 & 3] | 0xffffff00) << 8 |
                          local_6c[(uVar3 >> 2 & 7) + 5]) << 8 | local_6c[(uVar3 >> 5) + 5])) {
                        break;
                    }
                    uVar3 = uVar3 + 1;
                } while (uVar3 < 0x100);
                if (uVar3 == 0x100) {
                    local_c0[0] = 0x1b;
                }
            }
        }
    }
    iVar8 = local_c0[0];
    if ((param_9 == 0) || (param_9 == 0xfffffffd)) {
        if (param_13 != 0) {
            puVar1 = (uint32_t*)FUN_005f5e54(local_c0[0]);
            uVar3 = puVar1[1];
            if ((((uVar3 == 0) || (uVar3 == 1)) || (uVar3 == 2)) && (puVar1[4] == 0)) {
                puVar9 = local_6c + 4;
                for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
                    *puVar9 = *puVar1;
                    puVar1 = puVar1 + 1;
                    puVar9 = puVar9 + 1;
                }
                local_6c[4] = 0;
                local_6c[8] = 1;
                iVar8 = FUN_005f5ef6(0, param_8, param_16, (int*)(local_6c + 4));
                if (iVar8 == 0) {
                    iVar8 = local_c0[0];
                }
            }
        }
        param_9 = FUN_005f5ff4(iVar8);
        if ((param_10 != 3) && (param_9 == 0x14)) {
            param_9 = 0x16;
        }
    }
    piVar5 = param_5;
    uVar3 = param_4;
    if (param_15 == (undefined4*)0x0) {
LAB_005f6ee9:
        if ((local_1c == 0) || ((param_9 != 0x28 && (param_9 != 0x29)))) {
            if (param_9 == 0x28) {
LAB_005f6f2a:
                param_9 = 0x15;
            } else if (param_9 == 0x29) {
                param_9 = 0x16;
                uVar2 = 0;
                do {
                    if (*(char*)((int)local_4dc + uVar2 * 4 + 3) != -1) goto LAB_005f6f2a;
                    uVar2 = uVar2 + 1;
                } while (uVar2 < 0x100);
            }
            goto LAB_005f6f31;
        }
        iVar8 = -0x7789f794;
    } else {
        puVar6 = local_4dc;
        puVar10 = param_15;
        for (iVar8 = 0x100; iVar8 != 0; iVar8 = iVar8 + -1) {
            *puVar10 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar10 = puVar10 + 1;
        }
        if (local_b8 == 0) goto LAB_005f6ee9;
LAB_005f6f31:
        if ((param_10 != 0) || (local_14 = 1, (param_8 & 0x200) != 0)) {
            local_14 = 0;
        }
        local_34 = param_6;
        local_2c = param_7;
        local_24 = param_9;
        iVar8 = FUN_005f61dc(param_1, &param_4, &param_5, &param_6, &param_7, param_8,
                             (int*)&param_9, param_10, param_16);
        uVar2 = param_9;
        if (-1 < iVar8) {
            if ((((((local_6c[0xd] == 0) || (uVar3 == param_4)) &&
                   ((local_28 == 0 || (piVar5 == param_5)))) &&
                  ((local_20 == 0 || (local_34 == param_6)))) &&
                 ((local_30 == 0 || (local_2c == param_7)))) &&
                ((local_1c == 0 || (local_24 == param_9)))) {
                if (param_16 == 3) {
                    iVar8 = reinterpret_cast<int (__thiscall*)(
                        void*, uint32_t, int*, uint32_t, uint32_t, uint32_t, int, int**, int)>(
                        VSLOT(param_1, 0x5c))(param_1, param_4, param_5, param_7,
                                              param_8 & 0xffe07fff, param_9, param_10, &local_c, 0);
                } else if (param_16 == 4) {
                    iVar8 = reinterpret_cast<int (__thiscall*)(
                        void*, uint32_t, int*, uint32_t, uint32_t, uint32_t, uint32_t, int,
                        int**, int)>(VSLOT(param_1, 0x60))(
                        param_1, param_4, param_5, param_6, param_7, param_8 & 0xffe07fff, param_9,
                        param_10, &local_c, 0);
                } else if (param_16 == 5) {
                    iVar8 = reinterpret_cast<int (__thiscall*)(
                        void*, uint32_t, uint32_t, uint32_t, uint32_t, int, int**, int)>(
                        VSLOT(param_1, 100))(param_1, param_4, param_7, param_8 & 0xffe07fff,
                                             param_9, param_10, &local_c, 0);
                }
                if (-1 < iVar8) {
                    if (local_14 == 0) {
                        piVar5 = local_c;
                    } else {
                        if (param_16 == 3) {
                            iVar8 = reinterpret_cast<int (__thiscall*)(
                                void*, uint32_t, int*, uint32_t, uint32_t, uint32_t, int, int**,
                                int)>(VSLOT(param_1, 0x5c))(
                                param_1, param_4, param_5, param_7, 0, uVar2, 2, &local_10, 0);
                        } else if (param_16 == 4) {
                            iVar8 = reinterpret_cast<int (__thiscall*)(
                                void*, uint32_t, int*, uint32_t, uint32_t, uint32_t, uint32_t, int,
                                int**, int)>(VSLOT(param_1, 0x60))(
                                param_1, param_4, param_5, param_6, param_7, 0, uVar2, 2,
                                &local_10, 0);
                        } else if (param_16 == 5) {
                            iVar8 = reinterpret_cast<int (__thiscall*)(
                                void*, uint32_t, uint32_t, uint32_t, uint32_t, int, int**, int)>(
                                VSLOT(param_1, 100))(param_1, param_4, param_7, 0, uVar2, 2,
                                                     &local_10, 0);
                        }
                        if (iVar8 < 0) goto LAB_005f7310;
                        piVar5 = local_10;
                    }
                    param_4 = 0;
                    param_5 = local_c0;
                    if (param_2 != 0) {
                        do {
                            param_9 = 0;
                            piVar7 = param_5;
                            if (param_3 != 0) {
                                while (param_9 < param_7) {
                                    if (param_16 == 3) {
                                        ppiVar4 = &param_14;
LAB_005f712f:
                                        iVar8 = reinterpret_cast<int (__thiscall*)(
                                            void*, uint32_t, int**)>(VSLOT(piVar5, 0x48))(
                                            piVar5, param_9, ppiVar4);
                                    } else {
                                        if (param_16 == 4) {
                                            ppiVar4 = &local_8;
                                            goto LAB_005f712f;
                                        }
                                        if (param_16 == 5) {
                                            iVar8 = reinterpret_cast<int (__thiscall*)(
                                                void*, uint32_t, uint32_t, int**)>(
                                                VSLOT(piVar5, 0x48))(piVar5, param_4, param_9,
                                                                     &param_14);
                                        }
                                    }
                                    if (iVar8 < 0) goto LAB_005f7310;
                                    if (param_16 == 3) {
LAB_005f7151:
                                        iVar8 = FUN_005f6018(param_14, (undefined4)param_15, 0,
                                                             (int*)piVar7[1], (undefined4)*piVar7,
                                                             piVar7[0xc], local_4dc, piVar7 + 6,
                                                             (int)param_11, param_13);
                                    } else if (param_16 == 4) {
                                        iVar8 = FUN_005f6100(
                                            (int*)local_8, (undefined4)param_15, 0,
                                            (int*)piVar7[1], (undefined4)*piVar7, piVar7[0xc],
                                            piVar7[0xd], local_4dc, (undefined4*)(piVar7 + 6),
                                            (int)param_11, param_13);
                                    } else if (param_16 == 5) {
                                        goto LAB_005f7151;
                                    }
                                    if (iVar8 < 0) goto LAB_005f7310;
                                    if (local_8 != (int*)0x0) {
                                        reinterpret_cast<void (__thiscall*)(void*)>(
                                            VSLOT(local_8, 8))(local_8);
                                        local_8 = (int*)0x0;
                                    }
                                    if (param_14 != (int*)0x0) {
                                        reinterpret_cast<void (__thiscall*)(void*)>(
                                            VSLOT(param_14, 8))(param_14);
                                        param_14 = (int*)0x0;
                                    }
                                    param_9 = param_9 + 1;
                                    if (param_3 <= param_9) break;
                                    piVar7 = (int*)piVar7[0x13];
                                }
                            }
                            if ((local_18 == 0) && (param_9 < param_7)) {
                                do {
                                    if (param_16 == 3) {
                                        ppiVar4 = &param_14;
LAB_005f721f:
                                        iVar8 = reinterpret_cast<int (__thiscall*)(
                                            void*, uint32_t, int**)>(VSLOT(piVar5, 0x48))(
                                            piVar5, param_9, ppiVar4);
                                    } else {
                                        if (param_16 == 4) {
                                            ppiVar4 = &local_8;
                                            goto LAB_005f721f;
                                        }
                                        if (param_16 == 5) {
                                            iVar8 = reinterpret_cast<int (__thiscall*)(
                                                void*, uint32_t, uint32_t, int**)>(
                                                VSLOT(piVar5, 0x48))(piVar5, param_4, param_9,
                                                                     &param_14);
                                        }
                                    }
                                    if (iVar8 < 0) goto LAB_005f7310;
                                    if (param_16 == 3) {
LAB_005f7245:
                                        iVar8 = FUN_005f6018(param_14, (undefined4)param_15, 0,
                                                             (int*)piVar7[1], (undefined4)*piVar7,
                                                             piVar7[0xc], local_4dc, piVar7 + 6,
                                                             (int)param_11, param_13);
                                    } else if (param_16 == 4) {
                                        iVar8 = FUN_005f6100(
                                            (int*)local_8, (undefined4)param_15, 0,
                                            (int*)piVar7[1], (undefined4)*piVar7, piVar7[0xc],
                                            piVar7[0xd], local_4dc, (undefined4*)(piVar7 + 6),
                                            (int)param_11, param_13);
                                    } else if (param_16 == 5) {
                                        goto LAB_005f7245;
                                    }
                                    if (iVar8 < 0) goto LAB_005f7310;
                                    if (local_8 != (int*)0x0) {
                                        reinterpret_cast<void (__thiscall*)(void*)>(
                                            VSLOT(local_8, 8))(local_8);
                                        local_8 = (int*)0x0;
                                    }
                                    if (param_14 != (int*)0x0) {
                                        reinterpret_cast<void (__thiscall*)(void*)>(
                                            VSLOT(param_14, 8))(param_14);
                                        param_14 = (int*)0x0;
                                    }
                                    param_9 = param_9 + 1;
                                } while (param_9 < param_7);
                            }
                            param_5 = (int*)param_5[0x14];
                            param_4 = param_4 + 1;
                        } while (param_4 < param_2);
                    }
                    if ((((local_18 == 0) || (param_7 <= param_3)) ||
                         (iVar8 = FUN_005f682d(piVar5, (undefined4)(uintptr_t)local_4dc,
                                               param_3 - 1, param_12),
                          -1 < iVar8)) &&
                        ((local_14 == 0 ||
                          (iVar8 = reinterpret_cast<int (__thiscall*)(void*, int*, int*)>(
                               VSLOT(param_1, 0x7c))(param_1, local_10, local_c),
                           -1 < iVar8)))) {
                        piVar5 = local_c;
                        local_c = (int*)0x0;
                        *param_17 = piVar5;
                        iVar8 = 0;
                    }
                }
            } else {
                iVar8 = -0x7789f796;
            }
        }
    }
LAB_005f7310:
    if (local_8 != (int*)0x0) {
        reinterpret_cast<void (__thiscall*)(void*)>(VSLOT(local_8, 8))(local_8);
        local_8 = (int*)0x0;
    }
    if (param_14 != (int*)0x0) {
        reinterpret_cast<void (__thiscall*)(void*)>(VSLOT(param_14, 8))(param_14);
        param_14 = (int*)0x0;
    }
    if (local_c != (int*)0x0) {
        reinterpret_cast<void (__thiscall*)(void*)>(VSLOT(local_c, 8))(local_c);
        local_c = (int*)0x0;
    }
    if (local_10 != (int*)0x0) {
        reinterpret_cast<void (__thiscall*)(void*)>(VSLOT(local_10, 8))(local_10);
        local_10 = (int*)0x0;
    }
LAB_005f7353:
    FUN_005f901f();
    return iVar8;
}

// ===========================================================================
// 0x005f7394 — observed shape
// Thin wrapper: funnels a 15-argument call into FUN_005f6b1f with the
// type selector fixed to 3 and the level/usage argument fixed to 1.
// ===========================================================================
void FUN_005f7394(undefined4 param_1, undefined4 param_2, undefined4 param_3,
                  undefined4 param_4, undefined4 param_5, undefined4 param_6,
                  undefined4 param_7, undefined4 param_8, undefined4 param_9,
                  undefined4 param_10, undefined4 param_11, undefined4 param_12,
                  undefined4 param_13, undefined4 param_14, undefined4 param_15) {
    FUN_005f6b1f((int*)param_1, param_2, param_3, param_4, (int*)param_5, 1, param_6, param_7,
                 param_8, param_9, param_10, param_11, param_12, param_13, param_14, 3, param_15);
    return;
}

// ===========================================================================
// 0x005f73d3 — observed shape
// Thin wrapper into FUN_005f6b1f with type selector 5; param_4 is duplicated as
// both the width argument and the level-chain argument (param_5 slot).
// ===========================================================================
void FUN_005f73d3(undefined4 param_1, undefined4 param_2, undefined4 param_3,
                  undefined4 param_4, undefined4 param_5, undefined4 param_6,
                  undefined4 param_7, undefined4 param_8, undefined4 param_9,
                  undefined4 param_10, undefined4 param_11, undefined4 param_12,
                  undefined4 param_13, undefined4 param_14) {
    FUN_005f6b1f((int*)param_1, param_2, param_3, param_4, (int*)param_4, 1, param_5, param_6,
                 param_7, param_8, param_9, param_10, param_11, param_12, param_13, 5, param_14);
    return;
}

// ===========================================================================
// 0x005f7412 — observed shape
// Thin wrapper into FUN_005f6b1f with type selector 4; every argument is
// forwarded one-to-one before the selector.
// ===========================================================================
void FUN_005f7412(undefined4 param_1, undefined4 param_2, undefined4 param_3,
                  undefined4 param_4, undefined4 param_5, undefined4 param_6,
                  undefined4 param_7, undefined4 param_8, undefined4 param_9,
                  undefined4 param_10, undefined4 param_11, undefined4 param_12,
                  undefined4 param_13, undefined4 param_14, undefined4 param_15,
                  undefined4 param_16) {
    FUN_005f6b1f((int*)param_1, param_2, param_3, param_4, (int*)param_5, param_6, param_7,
                 param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15, 4,
                 param_16);
    return;
}

// ===========================================================================
// 0x005f7452 — observed shape
// Type-3 entry point: brackets FUN_0060b98d(param_2,0) with the 0060b97b/
// 0060bb0e pair and forwards the 0x48-byte descriptor fields (local_c/local_8)
// plus the remaining arguments to FUN_005f7394.
// ===========================================================================
int FUN_005f7452(undefined4 param_1, undefined4 param_2, undefined4 param_3,
                 undefined4 param_4, undefined4 param_5, undefined4 param_6,
                 undefined4 param_7, undefined4 param_8, undefined4 param_9,
                 undefined4 param_10, undefined4 param_11, undefined4 param_12,
                 undefined4 param_13, undefined4 param_14) {
    int iVar1;
    undefined4 local_c;
    undefined4 local_8;

    FUN_0060b97b();
    iVar1 = FUN_0060b98d(param_2, 0);
    if (-1 < iVar1) {
        iVar1 = FUN_005f7394(param_1, local_c, local_8, param_3, param_4, param_5, param_6,
                             param_7, param_8, param_9, param_10, param_11, param_12, param_13,
                             param_14);
    }
    FUN_0060bb0e();
    return iVar1;
}

// ===========================================================================
// 0x005f74b7 — observed shape
// Type-5 entry point: same 0060b97b/0060b98d/0060bb0e bracketing as 005f7452,
// forwarding to FUN_005f73d3.
// ===========================================================================
int FUN_005f74b7(undefined4 param_1, undefined4 param_2, undefined4 param_3,
                 undefined4 param_4, undefined4 param_5, undefined4 param_6,
                 undefined4 param_7, undefined4 param_8, undefined4 param_9,
                 undefined4 param_10, undefined4 param_11, undefined4 param_12,
                 undefined4 param_13) {
    int iVar1;
    undefined4 local_c;
    undefined4 local_8;

    FUN_0060b97b();
    iVar1 = FUN_0060b98d(param_2, 0);
    if (-1 < iVar1) {
        iVar1 = FUN_005f73d3(param_1, local_c, local_8, param_3, param_4, param_5, param_6,
                             param_7, param_8, param_9, param_10, param_11, param_12, param_13);
    }
    FUN_0060bb0e();
    return iVar1;
}
