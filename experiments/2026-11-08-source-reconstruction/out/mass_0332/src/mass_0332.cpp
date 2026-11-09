// Reconstruction batch mass_0332.
//
// This cluster is an MMX / 3DNow! math library: 4x4 matrix compose, matrix
// inverse, point transforms, vector normalisation and half-float conversion.
// Ghidra renders the MMX opcodes as PackedFloating* builtins; the helpers
// below keep the two 32-bit float lanes of one 64-bit MMX value and preserve
// the observed instruction order.  `FastExitMediaState` is the emms
// (`_mm_empty`) media-state exit observed between the packed sequences.

#include <cstdint>
#include <cstddef>
#include <cmath>
#include <windows.h>

using u64 = uint64_t;

// ---------------------------------------------------------------------------
// MMX packed-float primitives (two 32-bit lanes per 64-bit value).
// ---------------------------------------------------------------------------
union F2 {
    u64 u;
    float f[2];
};

static inline u64 pf_pack(float lo, float hi)
{
    F2 r;
    r.f[0] = lo;
    r.f[1] = hi;
    return r.u;
}

static inline u64 pf_add(u64 a, u64 b)
{
    F2 x, y;
    x.u = a;
    y.u = b;
    return pf_pack(x.f[0] + y.f[0], x.f[1] + y.f[1]);
}

static inline u64 pf_sub(u64 a, u64 b)
{
    F2 x, y;
    x.u = a;
    y.u = b;
    return pf_pack(x.f[0] - y.f[0], x.f[1] - y.f[1]);
}

static inline u64 pf_mul(u64 a, u64 b)
{
    F2 x, y;
    x.u = a;
    y.u = b;
    return pf_pack(x.f[0] * y.f[0], x.f[1] * y.f[1]);
}

// CONCAT44(dword, dword): the same 32-bit pattern repeated into both lanes.
static inline u64 pf_dup_dword(uint32_t d)
{
    return ((u64)d << 32) | (u64)d;
}

// CONCAT44(hi, lo).
static inline u64 pf_concat44(uint32_t hi, uint32_t lo)
{
    return ((u64)hi << 32) | (u64)lo;
}

// pi2fd: two signed 32-bit integers converted to two floats.
static inline u64 pf_pi2fd(u64 v)
{
    F2 r;
    r.f[0] = (float)(int32_t)(uint32_t)v;
    r.f[1] = (float)(int32_t)(uint32_t)(v >> 32);
    return r.u;
}

// pfacc: lower lane accumulates the first operand, upper lane the second.
static inline u64 pf_acc(u64 a, u64 b)
{
    F2 x, y;
    x.u = a;
    y.u = b;
    return pf_pack(x.f[0] + x.f[1], y.f[0] + y.f[1]);
}

// pfrcp / pfrnd refinement sequence collapsed to element-wise exact math.
static inline u64 pf_rcp(u64 /*mm_residue*/, u64 v)
{
    F2 x;
    x.u = v;
    return pf_pack(1.0f / x.f[0], 1.0f / x.f[1]);
}

static inline u64 pf_rcpit1(u64 v, u64 r)
{
    F2 a, b;
    a.u = v;
    b.u = r;
    return pf_pack(b.f[0] * (2.0f - a.f[0] * b.f[0]),
                   b.f[1] * (2.0f - a.f[1] * b.f[1]));
}

static inline u64 pf_rcpit2(u64 r, u64 /*approx*/)
{
    return r;
}

// pfrsqrt / pfrsqit1 sequence.
static inline u64 pf_rsqrt(u64 /*mm_residue*/, u64 v)
{
    F2 x;
    x.u = v;
    return pf_pack(1.0f / sqrtf(x.f[0]), 1.0f / sqrtf(x.f[1]));
}

static inline u64 pf_rsqit1(u64 /*v*/, u64 r)
{
    return r;
}

// pfcmpgt: all-ones dword per lane where the first lane is greater.
static inline u64 pf_cmpgt(u64 a, u64 b)
{
    F2 x, y;
    x.u = a;
    y.u = b;
    uint32_t lo = (x.f[0] > y.f[0]) ? 0xffffffffu : 0u;
    uint32_t hi = (x.f[1] > y.f[1]) ? 0xffffffffu : 0u;
    return pf_concat44(hi, lo);
}

// First entry of the table located at `addr`: the provider's `**(code **)addr`
// and `(*(code *)**(undefined4 **)addr)` call shapes both read two dwords.
static inline uint32_t vfn0(intptr_t addr)
{
    const uint32_t* table = *(const uint32_t**)(intptr_t)addr;
    return table[0];
}

// ---------------------------------------------------------------------------
// External helpers and globals referenced by the translated listings.
// ---------------------------------------------------------------------------
extern void FastExitMediaState(void);
extern void FUN_005f10ac(float* param_1, const uint16_t* param_2, int param_3);
extern int FUN_006923b0(int param_1, int param_2);
extern u64* FUN_0068f6ce(u64* param_1, const u64* param_2, const u64* param_3);
extern void FUN_0068e936(u64* param_1, uint32_t* param_2, const u64* param_3);

extern void FUN_006ad560(void* self);
extern void FUN_006ac5f0(void* self);
extern void FUN_006ae1f0(void* self);
extern void FUN_006ab700(void* self, int param_2);
extern void FUN_006ab570(void* self);
extern void FUN_006aa5a0(void* self);
extern void FUN_006ab1a0(void* self);
extern void FUN_006a9a10(void* self, uint32_t param_2);
extern void FUN_006a8b80(void* self, int param_2);

// 16-bit to 32-bit float conversion constants at 0x00720e00..0x00720e40.
// `_DAT_00720e30` / `_DAT_00720e40` are the overlapping symbols reported by
// the provider for 0x00720e30 / 0x00720e40.
extern const u64 DAT_00720e00;
extern const u64 DAT_00720e10;
extern const u64 DAT_00720e20;
extern const u64 _DAT_00720e30;
extern const u64 _DAT_00720e40;

// 0x68f75b — observed shape
u64* FUN_0068f75b(u64* param_1, const u64* param_2, const u64* param_3)
{
    for (int r = 0; r < 4; ++r) {
        u64 v0 = param_2[2 * r];
        u64 v1 = param_2[2 * r + 1];
        u64 bx = pf_dup_dword((uint32_t)v0);
        u64 by = pf_dup_dword((uint32_t)(v0 >> 32));
        u64 bz = pf_dup_dword((uint32_t)v1);
        u64 bw = pf_dup_dword((uint32_t)(v1 >> 32));
        u64 a = pf_mul(param_3[0], bx);
        u64 b = pf_mul(bx, param_3[1]);
        u64 c = pf_mul(param_3[2], by);
        u64 d = pf_mul(by, param_3[3]);
        u64 e, f, g, h;

        a = pf_add(c, a);
        b = pf_add(d, b);
        e = pf_mul(param_3[4], bz);
        f = pf_mul(bz, param_3[5]);
        a = pf_add(e, a);
        g = pf_mul(param_3[6], bw);
        b = pf_add(b, f);
        h = pf_mul(bw, param_3[7]);
        a = pf_add(g, a);
        b = pf_add(h, b);

        param_1[2 * r] = a;
        param_1[2 * r + 1] = b;
    }
    FastExitMediaState();
    return param_1;
}

// 0x68f92f — observed shape
u64* FUN_0068f92f(u64* param_1, const u64* param_2, const u64* param_3,
                  const u64* param_4, const u64* param_5, const u64* param_6)
{
    u64 local[8] = {
        0x000000003f800000ull, 0x0000000000000000ull,
        0x3f80000000000000ull, 0x0000000000000000ull,
        0x0000000000000000ull, 0x000000003f800000ull,
        0x0000000000000000ull, 0x3f80000000000000ull
    };
    const u64* puVar1 = local;

    switch (((param_6 != (const u64*)0) << 1 | (param_5 != (const u64*)0)) << 1 |
            (param_4 != (const u64*)0)) {
    case 0:
        break;
    case 1:
        puVar1 = param_4;
        break;
    case 2:
        puVar1 = param_5;
        break;
    case 3:
        FastExitMediaState();
        FUN_0068f75b(local, param_5, param_4);
        FastExitMediaState();
        break;
    case 4:
        puVar1 = param_6;
        break;
    case 5:
        FastExitMediaState();
        FUN_0068f75b(local, param_6, param_4);
        FastExitMediaState();
        break;
    case 6:
        FastExitMediaState();
        FUN_0068f75b(local, param_6, param_5);
        FastExitMediaState();
        break;
    case 7:
        FastExitMediaState();
        FUN_0068f75b(local, param_6, param_5);
        FUN_0068f75b(local, local, param_4);
        FastExitMediaState();
        break;
    }
    FUN_0068f6ce(param_1, param_2, puVar1);
    if (param_3 != (const u64*)0) {
        FastExitMediaState();
        u64 uVar4 = param_3[2];
        u64 uVar5 = pf_pi2fd(*param_3);
        u64 uVar6 = pf_pi2fd(param_3[1]);
        u64 uVar2 = pf_add(*param_1 ^ 0x8000000000000000ull, 0x3f8000003f800000ull);
        uint32_t uVar8;
        u64 uVar7, uVar3;

        uVar6 = pf_mul(uVar6, 0x3f0000003f000000ull);
        uVar8 = (uint32_t)(uVar4 >> 32);
        uVar7 = pf_sub(pf_dup_dword(uVar8), uVar4);
        uVar2 = pf_mul(uVar2, uVar6);
        uVar6 = pf_mul((u64)(uint32_t)param_1[1], uVar7);
        uVar4 = pf_add(uVar6, uVar4);
        uVar3 = pf_add(uVar2, uVar5);
        *param_1 = uVar3;
        *(int32_t*)(param_1 + 1) = (int32_t)uVar4;
        FastExitMediaState();
    }
    return param_1;
}

// 0x68fcd8 — observed shape
u64* FUN_0068fcd8(u64* param_1, u64* param_2, const u64* param_3,
                  const u64* param_4, const u64* param_5, const u64* param_6)
{
    u64 local[8] = {
        0x000000003f800000ull, 0x0000000000000000ull,
        0x3f80000000000000ull, 0x0000000000000000ull,
        0x0000000000000000ull, 0x000000003f800000ull,
        0x0000000000000000ull, 0x3f80000000000000ull
    };
    int mode = ((param_6 != (const u64*)0) << 1 | (param_5 != (const u64*)0)) << 1 |
               (param_4 != (const u64*)0);

    if (mode != 0) {
        switch (mode) {
        case 1:
            param_6 = param_4;
            break;
        case 2:
            param_6 = param_5;
            break;
        case 3:
            param_6 = param_5;
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            param_4 = param_5;
            break;
        case 7:
            FUN_0068f75b(local, param_6, param_5);
            param_6 = local;
            break;
        }
        if (mode != 1 && mode != 2 && mode != 4) {
            FUN_0068f75b(local, param_6, param_4);
            param_6 = local;
        }
        FUN_0068e936(local, (uint32_t*)0, param_6);
    }
    if (param_3 != (const u64*)0) {
        FastExitMediaState();
        u64 uVar4 = pf_pi2fd(*param_3);
        u64 uVar1 = param_3[2];
        u64 uVar5 = pf_pi2fd(param_3[1]);
        uint32_t uVar7 = (uint32_t)(uVar5 >> 32);
        u64 uVar6 = pf_dup_dword(uVar7);
        u64 uVar8 = pf_rcp(0, uVar5);
        u64 uVar2, uVar3, uVar9;

        uVar6 = pf_rcp(uVar6, uVar6);
        uVar2 = pf_sub(*param_2, uVar4);
        uVar6 = pf_concat44((uint32_t)uVar6, (uint32_t)uVar8);
        uVar4 = pf_rcpit1(uVar5, uVar6);
        uVar4 = pf_rcpit2(uVar4, uVar6);
        uVar4 = pf_mul(uVar4, 0x4000000040000000ull);
        uVar2 = pf_mul(uVar2, uVar4);
        uVar7 = (uint32_t)(uVar1 >> 32);
        uVar3 = pf_sub(uVar2, 0x3f8000003f800000ull);
        uVar2 = pf_sub(pf_dup_dword(uVar7), uVar1);
        uVar9 = pf_rcp(0, uVar2);
        uVar2 = pf_rcpit1(uVar2, uVar9);
        uVar9 = pf_rcpit2(uVar2, uVar9);
        uVar2 = pf_sub((u64)(uint32_t)param_2[1], uVar1);
        uVar2 = pf_mul(uVar2, uVar9);
        *param_1 = uVar3 ^ 0x8000000000000000ull;
        *(int32_t*)(param_1 + 1) = (int32_t)uVar2;
        FastExitMediaState();
        param_2 = param_1;
    }
    FUN_0068f6ce(param_1, param_2, local);
    return param_1;
}

// 0x68fe80 — observed shape
u64* FUN_0068fe80(u64* param_1, uint32_t* param_2, int param_3)
{
    u64* puVar1 = param_1;
    u64 uVar2, uVar3, uVar4, uVar5, uVar6, uVar7, uVar8, uVar9;
    int32_t iVar10;

    if (param_3 < 4) {
        if (param_3 != 0) {
            FUN_005f10ac((float*)param_1, (const uint16_t*)param_2, param_3);
        }
    }
    else {
        while (true) {
            for (; 3 < param_3; param_3 = param_3 + -4) {
                uVar7 = (((u64)(*param_2 & 0xffffu)) |
                         ((u64)((*param_2 >> 0x10) & 0xffffu) << 32));
                uVar3 = (((u64)(param_2[1] & 0xffffu)) |
                         ((u64)((param_2[1] >> 0x10) & 0xffffu) << 32));
                uVar9 = pf_concat44(
                    ((int32_t)(uint32_t)((uVar7 & DAT_00720e00) >> 32) == 0) ? 0xffffffffu : 0u,
                    ((int32_t)(uint32_t)(uVar7 & DAT_00720e00) == 0) ? 0xffffffffu : 0u);
                uVar4 = pf_concat44(
                    ((int32_t)(uint32_t)((uVar3 & DAT_00720e00) >> 32) == 0) ? 0xffffffffu : 0u,
                    ((int32_t)(uint32_t)(uVar3 & DAT_00720e00) == 0) ? 0xffffffffu : 0u);
                uVar6 = uVar7 & DAT_00720e20;
                uVar8 = uVar3 & DAT_00720e20;
                iVar10 = (int32_t)(uint32_t)(DAT_00720e10 >> 32);
                uVar2 = uVar9 & _DAT_00720e30;
                uVar5 = uVar4 & _DAT_00720e30;
                uVar7 = pf_sub(
                    pf_concat44(
                        (uint32_t)(((int32_t)(uint32_t)((uVar7 ^ uVar6) >> 32) + iVar10 +
                                    (int32_t)(uint32_t)(uVar2 >> 32)) * 0x2000),
                        (uint32_t)(((int32_t)(uint32_t)(uVar7 ^ uVar6) +
                                    (int32_t)(uint32_t)DAT_00720e10 +
                                    (int32_t)(uint32_t)uVar2) * 0x2000)),
                    uVar9 & _DAT_00720e40);
                uVar9 = pf_sub(
                    pf_concat44(
                        (uint32_t)(((int32_t)(uint32_t)((uVar3 ^ uVar8) >> 32) + iVar10 +
                                    (int32_t)(uint32_t)(uVar5 >> 32)) * 0x2000),
                        (uint32_t)(((int32_t)(uint32_t)(uVar3 ^ uVar8) +
                                    (int32_t)(uint32_t)DAT_00720e10 +
                                    (int32_t)(uint32_t)uVar5) * 0x2000)),
                    uVar4 & _DAT_00720e40);
                *puVar1 = uVar7 | pf_concat44(
                    (uint32_t)((int32_t)(uint32_t)(uVar6 >> 32) << 0x10),
                    (uint32_t)((int32_t)(uint32_t)uVar6 << 0x10));
                puVar1[1] = uVar9 | pf_concat44(
                    (uint32_t)((int32_t)(uint32_t)(uVar8 >> 32) << 0x10),
                    (uint32_t)((int32_t)(uint32_t)uVar8 << 0x10));
                puVar1 = puVar1 + 2;
                param_2 = param_2 + 2;
            }
            if (param_3 == 0) break;
            param_2 = (uint32_t*)((char*)param_2 + (param_3 + -4) * 2);
            puVar1 = (u64*)((char*)puVar1 + (param_3 + -4) * 4);
            param_3 = 4;
        }
    }
    FastExitMediaState();
    return param_1;
}

// 0x69013b — observed shape
u64* FUN_0069013b(u64* param_1, const u64* param_2, const u64* param_3)
{
    uint32_t uVar1;
    u64 uVar2, uVar3, uVar4, uVar5, uVar6;

    FastExitMediaState();
    uVar1 = (uint32_t)*param_2;
    uVar3 = pf_dup_dword(uVar1);
    uVar1 = (uint32_t)(*param_2 >> 32);
    uVar6 = pf_dup_dword(uVar1);
    uVar2 = pf_mul(uVar3, *param_3);
    uVar4 = pf_mul(uVar6, param_3[2]);
    uVar2 = pf_add(uVar2, param_3[6]);
    uVar5 = pf_mul(uVar3, param_3[1]);
    uVar6 = pf_mul(uVar6, param_3[3]);
    uVar3 = pf_add(uVar2, uVar4);
    uVar2 = pf_add(uVar5, param_3[7]);
    uVar2 = pf_add(uVar2, uVar6);
    *param_1 = uVar3;
    param_1[1] = uVar2;
    FastExitMediaState();
    return param_1;
}

// 0x690192 — observed shape
u64* FUN_00690192(u64* param_1, const u64* param_2, const u64* param_3)
{
    uint32_t uVar1, uVar4;
    u64 uVar2, uVar3;

    FastExitMediaState();
    uVar1 = (uint32_t)*param_2;
    uVar4 = (uint32_t)(*param_2 >> 32);
    uVar2 = pf_mul(pf_dup_dword(uVar1), *param_3);
    uVar3 = pf_mul(pf_dup_dword(uVar4), param_3[2]);
    uVar2 = pf_add(uVar2, uVar3);
    *param_1 = uVar2;
    FastExitMediaState();
    return param_1;
}

// 0x6901cd — observed shape
u64* FUN_006901cd(u64* param_1, const u64* param_2, const u64* param_3)
{
    uint32_t uVar1;
    u64 uVar2, uVar3, uVar4, uVar5, uVar6;

    FastExitMediaState();
    uVar1 = (uint32_t)*param_2;
    uVar3 = pf_dup_dword(uVar1);
    uVar1 = (uint32_t)(*param_2 >> 32);
    uVar6 = pf_dup_dword(uVar1);
    uVar2 = pf_mul(uVar3, *param_3);
    uVar4 = pf_mul(uVar6, param_3[2]);
    uVar2 = pf_add(uVar2, param_3[6]);
    uVar5 = pf_mul(uVar3, param_3[1]);
    uVar6 = pf_mul(uVar6, param_3[3]);
    uVar3 = pf_add(uVar2, uVar4);
    uVar2 = pf_add(uVar5, param_3[7]);
    uVar2 = pf_add(uVar2, uVar6);
    uVar1 = (uint32_t)(uVar2 >> 32);
    uVar2 = pf_dup_dword(uVar1);
    uVar6 = pf_rcp(uVar6, uVar2);
    uVar2 = pf_rcpit1(uVar2, uVar6);
    uVar2 = pf_rcpit2(uVar2, uVar6);
    uVar3 = pf_mul(uVar3, uVar2);
    *param_1 = uVar3;
    FastExitMediaState();
    return param_1;
}

// 0x690402 — observed shape
u64* FUN_00690402(u64* param_1, const u64* param_2, const u64* param_3)
{
    uint32_t uVar1;
    u64 uVar2, uVar3, uVar4, uVar5, uVar6, uVar7, uVar8, uVar9;

    FastExitMediaState();
    uVar1 = (uint32_t)*param_2;
    uVar5 = pf_dup_dword(uVar1);
    uVar1 = (uint32_t)(*param_2 >> 32);
    uVar8 = pf_dup_dword(uVar1);
    uVar1 = (uint32_t)param_2[1];
    uVar9 = pf_dup_dword(uVar1);
    uVar1 = (uint32_t)(param_2[1] >> 32);
    uVar6 = pf_dup_dword(uVar1);
    uVar2 = pf_mul(uVar5, *param_3);
    uVar3 = pf_mul(uVar8, param_3[2]);
    uVar4 = pf_mul(uVar9, param_3[4]);
    uVar7 = pf_mul(uVar6, param_3[6]);
    uVar2 = pf_add(uVar2, uVar3);
    uVar3 = pf_mul(uVar5, param_3[1]);
    uVar5 = pf_add(uVar4, uVar7);
    uVar8 = pf_mul(uVar8, param_3[3]);
    uVar9 = pf_mul(uVar9, param_3[5]);
    uVar4 = pf_mul(uVar6, param_3[7]);
    uVar5 = pf_add(uVar2, uVar5);
    uVar2 = pf_add(uVar3, uVar8);
    uVar8 = pf_add(uVar9, uVar4);
    uVar2 = pf_add(uVar2, uVar8);
    *param_1 = uVar5;
    param_1[1] = uVar2;
    FastExitMediaState();
    return param_1;
}

// 0x690a15 — observed shape
void FUN_00690a15(u64* param_1, const u64* param_2)
{
    u64 uVar1 = *param_2;
    u64 uVar3 = (u64)(uint32_t)param_2[1];
    u64 uVar2 = pf_mul(uVar1, uVar1);
    u64 uVar4 = pf_mul(uVar3, uVar3);
    u64 uVar5, in_MM4 = 0;

    uVar2 = pf_add(uVar2, uVar4);
    uVar2 = pf_acc(uVar2, uVar2);
    uVar5 = pf_rsqrt(in_MM4, uVar2);
    uVar3 = pf_cmpgt(uVar2, 0x80000000800000ull);
    uVar4 = pf_mul(uVar5, uVar5);
    uVar2 = pf_rsqit1(uVar2, uVar4);
    uVar2 = pf_rcpit2(uVar2, uVar5);
    uVar4 = pf_mul(uVar1 & uVar3, uVar2);
    uVar2 = pf_mul(param_2[1] & uVar3, uVar2);
    *param_1 = uVar4;
    param_1[1] = uVar2;
    FastExitMediaState();
    return;
}

// 0x690b00 — observed shape
uint32_t FUN_00690b00(void* self)
{
    int32_t iVar1, iVar2;
    uint32_t uVar3;

    if (((*(int32_t*)((char*)self + 0x4c) != 0) ||
         (*(int32_t*)((char*)self + 0x130) != 0)) ||
        (*(int32_t*)((char*)self + 0x28) != 3) ||
        ((*(int32_t*)((char*)self + 0x24) != 3) ||
         (*(int32_t*)((char*)self + 0x2c) != 2)) ||
        (*(int32_t*)((char*)self + 0x78) != 3)) {
        return 0;
    }
    iVar1 = *(int32_t*)((char*)self + 0xdc);
    iVar2 = *(int32_t*)((char*)self + 0x140);
    uVar3 = 1;
    if ((*(int32_t*)(iVar1 + 8) != 2) || (*(int32_t*)(iVar1 + 0x5c) != 1) ||
        (*(int32_t*)(iVar1 + 0xb0) != 1) ||
        ((2 < *(int32_t*)(iVar1 + 0xc)) || (*(int32_t*)(iVar1 + 0x60) != 1) ||
         (*(int32_t*)(iVar1 + 0xb4) != 1)) ||
        (*(int32_t*)(iVar1 + 0x24) != iVar2) || (*(int32_t*)(iVar1 + 0x78) != iVar2) ||
        (*(int32_t*)(iVar1 + 0xcc) != iVar2)) {
        uVar3 = 0;
    }
    return uVar3;
}

// 0x690b80 — observed shape
void FUN_00690b80(int32_t* param_1)
{
    uint32_t* puVar1;
    uint32_t uVar2;
    int32_t* piVar3 = param_1;
    int32_t iVar4, iVar5, iVar7;
    int32_t* piVar6;

    iVar4 = param_1[5];
    if (iVar4 != 0xca) {
        puVar1 = (uint32_t*)(intptr_t)*param_1;
        puVar1[5] = 0x14;
        puVar1[6] = (uint32_t)iVar4;
        ((void (*)(int32_t*))(uintptr_t)puVar1[0])(param_1);
    }
    iVar4 = param_1[0xc];
    uVar2 = (uint32_t)param_1[0xd];
    if (uVar2 < (uint32_t)(iVar4 * 8)) {
        if (uVar2 < (uint32_t)(iVar4 * 4)) {
            if (uVar2 < (uint32_t)(iVar4 * 2)) {
                iVar4 = param_1[8];
                param_1[0x1c] = param_1[7];
                param_1[0x50] = 8;
            }
            else {
                iVar4 = FUN_006923b0(param_1[7], 2);
                param_1[0x1c] = iVar4;
                iVar4 = FUN_006923b0(param_1[8], 2);
                param_1[0x50] = 4;
            }
        }
        else {
            iVar4 = FUN_006923b0(param_1[7], 4);
            param_1[0x1c] = iVar4;
            iVar4 = FUN_006923b0(param_1[8], 4);
            param_1[0x50] = 2;
        }
    }
    else {
        iVar4 = FUN_006923b0(param_1[7], 8);
        param_1[0x1c] = iVar4;
        iVar4 = FUN_006923b0(param_1[8], 8);
        param_1[0x50] = 1;
    }
    piVar6 = param_1 + 0x37;
    param_1[0x1d] = iVar4;
    param_1 = (int32_t*)(intptr_t)param_1[9];
    if (0 < (intptr_t)param_1) {
        piVar6 = (int32_t*)((intptr_t)*piVar6 + 0xc);
        do {
            iVar4 = piVar3[0x50];
            if (iVar4 < 8) {
                iVar7 = piVar3[0x4e] * iVar4;
                do {
                    if ((iVar7 < piVar6[-1] * iVar4 * 2) ||
                        (piVar3[0x4f] * piVar3[0x50] < *piVar6 * iVar4 * 2)) {
                        break;
                    }
                    iVar4 = iVar4 * 2;
                } while (iVar4 < 8);
            }
            piVar6[6] = iVar4;
            piVar6 = piVar6 + 0x15;
            param_1 = (int32_t*)((intptr_t)param_1 - 1);
        } while (param_1 != (int32_t*)0);
    }
    iVar4 = 0;
    if (0 < piVar3[9]) {
        piVar6 = (int32_t*)((intptr_t)piVar3[0x37] + 0x24);
        do {
            iVar5 = FUN_006923b0(piVar6[-7] * *piVar6 * piVar3[7], piVar3[0x4e] << 3);
            iVar7 = piVar3[0x4f];
            piVar6[1] = iVar5;
            iVar7 = FUN_006923b0(piVar6[-6] * piVar3[8] * *piVar6, iVar7 << 3);
            piVar6[2] = iVar7;
            iVar4 = iVar4 + 1;
            piVar6 = piVar6 + 0x15;
        } while (iVar4 < piVar3[9]);
    }
    switch (piVar3[0xb]) {
    case 1:
        piVar3[0x1e] = 1;
        break;
    case 2:
    case 3:
        piVar3[0x1e] = 3;
        break;
    case 4:
    case 5:
        piVar3[0x1e] = 4;
        break;
    default:
        piVar3[0x1e] = piVar3[9];
    }
    iVar4 = 1;
    if (piVar3[0x15] == 0) {
        iVar4 = piVar3[0x1e];
    }
    piVar3[0x1f] = iVar4;
    iVar4 = (int32_t)FUN_00690b00(piVar3);
    if (iVar4 == 0) {
        piVar3[0x20] = 1;
        return;
    }
    piVar3[0x20] = piVar3[0x4f];
}

// 0x690d90 — observed shape
void FUN_00690d90(void* self)
{
    uint32_t* puVar1 = (uint32_t*)(uintptr_t)vfn0((intptr_t)((char*)self + 4));
    int32_t iVar2, iVar3;
    uint32_t* puVar4;
    uint32_t* puVar5;

    iVar2 = 0;
    *(uint32_t**)((char*)self + 0x148) = puVar1 + 0x40;
    puVar4 = puVar1;
    for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
    }
    do {
        *(char*)((char*)(puVar1 + 0x40) + iVar2) = (char)iVar2;
        iVar2 = iVar2 + 1;
    } while (iVar2 < 0x100);
    puVar4 = *(uint32_t**)((char*)self + 0x148);
    puVar5 = puVar1 + 0x80;
    for (iVar2 = 0x60; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = 0xffffffff;
        puVar5 = puVar5 + 1;
    }
    puVar5 = puVar1 + 0xe0;
    for (iVar2 = 0x60; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
    }
    puVar1 = puVar1 + 0x140;
    for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar1 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar1 = puVar1 + 1;
    }
    return;
}

// 0x690e10 — observed shape
void FUN_00690e10(void* self)
{
    int32_t* esi = (int32_t*)self;
    int32_t iVar1 = esi[0x6a];
    uint32_t* puVar3;
    int32_t iVar2, iVar4, iVar6;
    uint32_t uVar5;

    FUN_00690b80(esi);
    FUN_00690d90(esi);
    *(uint32_t*)((char*)(intptr_t)iVar1 + 0xc) = 0;
    uVar5 = FUN_00690b00(esi);
    *(uint32_t*)((char*)(intptr_t)iVar1 + 0x10) = uVar5;
    iVar2 = esi[0x15];
    *(uint32_t*)((char*)(intptr_t)iVar1 + 0x14) = 0;
    *(uint32_t*)((char*)(intptr_t)iVar1 + 0x18) = 0;
    if ((iVar2 == 0) || (esi[0x10] == 0)) {
        esi[0x19] = 0;
        esi[0x1a] = 0;
        esi[0x1b] = 0;
    }
    if (iVar2 != 0) {
        if (esi[0x11] != 0) {
            puVar3 = (uint32_t*)(intptr_t)*esi;
            puVar3[5] = 0x2f;
            ((void (*)(void))(uintptr_t)puVar3[0])();
        }
        {
            bool set19 = false;
            if (esi[0x1e] == 3) {
                if (esi[0x22] == 0) {
                    if (esi[0x17] == 0) {
                        set19 = true;
                    }
                    else {
                        esi[0x1b] = 1;
                    }
                }
                else {
                    esi[0x1a] = 1;
                }
            }
            else {
                esi[0x1a] = 0;
                esi[0x1b] = 0;
                esi[0x22] = 0;
                set19 = true;
            }
            if (set19) {
                esi[0x19] = 1;
            }
        }
        if (esi[0x19] != 0) {
            puVar3 = (uint32_t*)(intptr_t)*esi;
            puVar3[5] = 0x30;
            ((void (*)(void))(uintptr_t)puVar3[0])();
        }
        if ((esi[0x1b] != 0) || (esi[0x1a] != 0)) {
            puVar3 = (uint32_t*)(intptr_t)*esi;
            puVar3[5] = 0x30;
            ((void (*)(void))(uintptr_t)puVar3[0])();
        }
    }
    if (esi[0x11] == 0) {
        if (*(int32_t*)((char*)(intptr_t)iVar1 + 0x10) == 0) {
            FUN_006ad560(esi);
            FUN_006ac5f0(esi);
        }
        else {
            FUN_006ae1f0(esi);
        }
        FUN_006ab700(esi, esi[0x1b]);
    }
    FUN_006ab570(esi);
    if (esi[0x39] == 0) {
        if (esi[0x38] == 0) {
            FUN_006aa5a0(esi);
        }
        else {
            FUN_006ab1a0(esi);
        }
    }
    else {
        puVar3 = (uint32_t*)(intptr_t)*esi;
        puVar3[5] = 1;
        ((void (*)(void))(uintptr_t)puVar3[0])();
    }
    if ((*(int32_t*)((char*)(intptr_t)esi[0x6e] + 0x10) == 0) && (esi[0x10] == 0)) {
        uVar5 = 0;
    }
    else {
        uVar5 = 1;
    }
    FUN_006a9a10(esi, uVar5);
    if (esi[0x11] == 0) {
        FUN_006a8b80(esi, 0);
    }
    ((void (*)(void))(uintptr_t)vfn0((intptr_t)esi[1] + 0x18))();
    ((void (*)(void))(uintptr_t)vfn0((intptr_t)esi[0x6e] + 8))();
    iVar2 = esi[2];
    if (((iVar2 != 0) && (esi[0x10] == 0)) &&
        (*(int32_t*)((char*)(intptr_t)esi[0x6e] + 0x10) != 0)) {
        iVar6 = esi[9];
        if (esi[0x38] != 0) {
            iVar6 = iVar6 * 3 + 2;
        }
        iVar4 = esi[0x51];
        *(uint32_t*)((char*)(intptr_t)iVar2 + 4) = 0;
        *(int32_t*)((char*)(intptr_t)iVar2 + 8) = iVar4 * iVar6;
        iVar6 = esi[0x1b];
        *(uint32_t*)((char*)(intptr_t)iVar2 + 0xc) = 0;
        *(uint32_t*)((char*)(intptr_t)iVar2 + 0x10) = (uint32_t)((iVar6 != 0) + 2);
        *(int32_t*)((char*)(intptr_t)iVar1 + 0xc) =
            *(int32_t*)((char*)(intptr_t)iVar1 + 0xc) + 1;
    }
    return;
}

// 0x690fc0 — observed shape
void FUN_00690fc0(int32_t* param_1)
{
    int32_t iVar1;
    uint32_t* puVar2;
    int32_t iVar3, iVar4;

    iVar1 = param_1[0x6a];
    if (*(int32_t*)((char*)(intptr_t)iVar1 + 8) == 0) {
        if ((param_1[0x15] != 0) && (param_1[0x22] == 0)) {
            if ((param_1[0x17] == 0) || (param_1[0x1b] == 0)) {
                if (param_1[0x19] == 0) {
                    puVar2 = (uint32_t*)(intptr_t)*param_1;
                    puVar2[5] = 0x2e;
                    ((void (*)(int32_t*))(uintptr_t)puVar2[0])(param_1);
                }
                else {
                    param_1[0x74] = *(int32_t*)((char*)(intptr_t)iVar1 + 0x14);
                }
            }
            else {
                param_1[0x74] = *(int32_t*)((char*)(intptr_t)iVar1 + 0x18);
                *(uint32_t*)((char*)(intptr_t)iVar1 + 8) = 1;
            }
        }
        ((void (*)(int32_t*))(uintptr_t)vfn0(param_1[0x71]))(param_1);
        ((void (*)(int32_t*))(uintptr_t)vfn0((intptr_t)param_1[0x6c] + 8))(param_1);
        if (param_1[0x11] == 0) {
            if (*(int32_t*)((char*)(intptr_t)iVar1 + 0x10) == 0) {
                ((void (*)(int32_t*))(uintptr_t)vfn0(param_1[0x73]))(param_1);
            }
            ((void (*)(int32_t*))(uintptr_t)vfn0(param_1[0x72]))(param_1);
            if (param_1[0x15] != 0) {
                ((void (*)(int32_t*, uint32_t))(uintptr_t)vfn0(param_1[0x74]))(
                    param_1, *(uint32_t*)((char*)(intptr_t)iVar1 + 8));
            }
            ((void (*)(int32_t*, uint32_t))(uintptr_t)vfn0(param_1[0x6d]))(
                param_1, (uint32_t)(-(*(int32_t*)((char*)(intptr_t)iVar1 + 8) != 0) & 3));
            ((void (*)(int32_t*, int))(uintptr_t)vfn0(param_1[0x6b]))(param_1, 0);
        }
    }
    else {
        puVar2 = (uint32_t*)(intptr_t)*param_1;
        puVar2[5] = 0x30;
        ((void (*)(int32_t*))(uintptr_t)puVar2[0])(param_1);
    }
    iVar3 = param_1[2];
    if (iVar3 != 0) {
        *(uint32_t*)((char*)(intptr_t)iVar3 + 0xc) =
            *(uint32_t*)((char*)(intptr_t)iVar1 + 0xc);
        iVar4 = (*(int32_t*)((char*)(intptr_t)iVar1 + 8) != 0) + 1 +
                *(int32_t*)((char*)(intptr_t)iVar1 + 0xc);
        iVar1 = param_1[0x10];
        *(int32_t*)((char*)(intptr_t)iVar3 + 0x10) = iVar4;
        if ((iVar1 != 0) &&
            (*(int32_t*)((char*)(intptr_t)param_1[0x6e] + 0x14) == 0)) {
            *(uint32_t*)((char*)(intptr_t)iVar3 + 0x10) =
                (uint32_t)((param_1[0x1b] != 0) + 1 + iVar4);
        }
    }
    return;
}

// 0x6910f0 — observed shape
void FUN_006910f0(int param_1)
{
    int32_t iVar2 = *(int32_t*)((char*)(intptr_t)param_1 + 0x1a8);
    int32_t* piVar1;

    if (*(int32_t*)((char*)(intptr_t)param_1 + 0x54) != 0) {
        ((void (*)(int))(uintptr_t)vfn0(
            *(int32_t*)((char*)(intptr_t)param_1 + 0x1d0) + 8))(param_1);
    }
    piVar1 = (int32_t*)((char*)(intptr_t)iVar2 + 0xc);
    *piVar1 = *piVar1 + 1;
    return;
}

// 0x691120 — observed shape
void FUN_00691120(int param_1)
{
    uint32_t* puVar1;

    puVar1 = (uint32_t*)(uintptr_t)
        ((void* (*)(int, int, unsigned int))(uintptr_t)
            vfn0((intptr_t)((char*)(intptr_t)param_1 + 4)))(param_1, 1, 0x1c);
    *(uint32_t**)((char*)(intptr_t)param_1 + 0x1a8) = puVar1;
    puVar1[0] = (uint32_t)reinterpret_cast<uintptr_t>(&FUN_00690fc0);
    puVar1[1] = (uint32_t)reinterpret_cast<uintptr_t>(&FUN_006910f0);
    puVar1[2] = 0;
    FUN_00690e10((void*)(intptr_t)param_1);
    return;
}

// 0x691160 — observed shape
void FUN_00691160(void* self)
{
    int32_t* esi = (int32_t*)self;
    int32_t iVar1, iVar2, iVar4;
    int32_t uVar3;
    uint32_t* puVar6;
    int32_t* piVar5;

    if ((0xffdc < (uint32_t)esi[8]) || (0xffdc < (uint32_t)esi[7])) {
        puVar6 = (uint32_t*)(intptr_t)*esi;
        puVar6[5] = 0x29;
        puVar6[6] = 0xffdc;
        ((void (*)(void))(uintptr_t)puVar6[0])();
    }
    iVar4 = esi[0x36];
    if (iVar4 != 8) {
        puVar6 = (uint32_t*)(intptr_t)*esi;
        puVar6[5] = 0xf;
        puVar6[6] = (uint32_t)iVar4;
        ((void (*)(void))(uintptr_t)puVar6[0])();
    }
    iVar4 = esi[9];
    if (10 < iVar4) {
        puVar6 = (uint32_t*)(intptr_t)*esi;
        puVar6[5] = 0x1a;
        puVar6[6] = (uint32_t)iVar4;
        puVar6[7] = 10;
        ((void (*)(void))(uintptr_t)puVar6[0])();
    }
    iVar4 = 0;
    esi[0x4e] = 1;
    esi[0x4f] = 1;
    if (0 < esi[9]) {
        piVar5 = (int32_t*)((char*)(intptr_t)esi[0x37] + 0xc);
        do {
            if ((((piVar5[-1] < 1) || (4 < piVar5[-1])) || (*piVar5 < 1)) ||
                (4 < *piVar5)) {
                puVar6 = (uint32_t*)(intptr_t)*esi;
                puVar6[5] = 0x12;
                ((void (*)(void))(uintptr_t)puVar6[0])();
            }
            iVar2 = esi[0x4e];
            if (esi[0x4e] <= piVar5[-1]) {
                iVar2 = piVar5[-1];
            }
            iVar1 = *piVar5;
            esi[0x4e] = iVar2;
            iVar2 = esi[0x4f];
            if (esi[0x4f] <= iVar1) {
                iVar2 = iVar1;
            }
            esi[0x4f] = iVar2;
            iVar4 = iVar4 + 1;
            piVar5 = piVar5 + 0x15;
        } while (iVar4 < esi[9]);
    }
    iVar4 = 0;
    esi[0x50] = 8;
    if (0 < esi[9]) {
        puVar6 = (uint32_t*)((char*)(intptr_t)esi[0x37] + 0x1c);
        do {
            iVar2 = esi[7];
            iVar1 = esi[0x4e];
            puVar6[2] = 8;
            uVar3 = FUN_006923b0((int32_t)puVar6[-5] * iVar2, iVar1 << 3);
            iVar2 = esi[0x4f];
            *puVar6 = (uint32_t)uVar3;
            uVar3 = FUN_006923b0((int32_t)puVar6[-4] * esi[8], iVar2 << 3);
            iVar2 = esi[7];
            iVar1 = esi[0x4e];
            puVar6[1] = (uint32_t)uVar3;
            uVar3 = FUN_006923b0((int32_t)puVar6[-5] * iVar2, iVar1);
            iVar2 = esi[8];
            puVar6[3] = (uint32_t)uVar3;
            uVar3 = FUN_006923b0((int32_t)puVar6[-4] * iVar2, esi[0x4f]);
            puVar6[4] = (uint32_t)uVar3;
            iVar2 = esi[9];
            puVar6[5] = 1;
            puVar6[0xc] = 0;
            iVar4 = iVar4 + 1;
            puVar6 = puVar6 + 0x15;
        } while (iVar4 < iVar2);
    }
    iVar4 = FUN_006923b0(esi[8], esi[0x4f] << 3);
    esi[0x51] = iVar4;
    if ((esi[0x53] < esi[9]) || (esi[0x38] != 0)) {
        *(uint32_t*)((char*)(intptr_t)esi[0x6e] + 0x10) = 1;
        return;
    }
    *(uint32_t*)((char*)(intptr_t)esi[0x6e] + 0x10) = 0;
    return;
}

// 0x691340 — observed shape
uint32_t FUN_00691340(void* self)
{
    int32_t* esi = (int32_t*)self;
    int32_t iVar3, iVar7;
    uint32_t uVar1, uVar4, uVar5, uVar6;
    uint32_t* puVar2;
    int32_t* local_c;
    uint32_t local_8;

    iVar3 = esi[0x53];
    if (iVar3 == 1) {
        iVar3 = esi[0x54];
        uVar1 = *(uint32_t*)((char*)(intptr_t)iVar3 + 0x24);
        uVar4 = *(uint32_t*)((char*)(intptr_t)iVar3 + 0xc);
        esi[0x58] = *(int32_t*)((char*)(intptr_t)iVar3 + 0x1c);
        uVar6 = *(uint32_t*)((char*)(intptr_t)iVar3 + 0x20);
        *(uint32_t*)((char*)(intptr_t)iVar3 + 0x40) = uVar1;
        esi[0x59] = (int32_t)uVar6;
        *(uint32_t*)((char*)(intptr_t)iVar3 + 0x34) = 1;
        *(uint32_t*)((char*)(intptr_t)iVar3 + 0x38) = 1;
        *(uint32_t*)((char*)(intptr_t)iVar3 + 0x3c) = 1;
        *(uint32_t*)((char*)(intptr_t)iVar3 + 0x44) = 1;
        uVar5 = uVar6 % uVar4;
        if (uVar6 % uVar4 == 0) {
            uVar5 = uVar4;
        }
        esi[0x5a] = 1;
        *(uint32_t*)((char*)(intptr_t)iVar3 + 0x48) = uVar5;
        esi[0x5b] = 0;
        return uVar6 / uVar4;
    }
    if ((iVar3 < 1) || (4 < iVar3)) {
        puVar2 = (uint32_t*)(intptr_t)*esi;
        puVar2[5] = 0x1a;
        puVar2[6] = (uint32_t)iVar3;
        puVar2[7] = 4;
        ((void (*)(void))(uintptr_t)puVar2[0])();
    }
    iVar3 = FUN_006923b0(esi[7], esi[0x4e] << 3);
    esi[0x58] = iVar3;
    uVar4 = (uint32_t)FUN_006923b0(esi[8], esi[0x4f] << 3);
    esi[0x59] = (int32_t)uVar4;
    esi[0x5a] = 0;
    local_8 = 0;
    if (0 < esi[0x53]) {
        local_c = esi + 0x54;
        do {
            iVar3 = *local_c;
            uVar4 = *(uint32_t*)((char*)(intptr_t)iVar3 + 8);
            *(uint32_t*)((char*)(intptr_t)iVar3 + 0x40) =
                (uint32_t)(*(int32_t*)((char*)(intptr_t)iVar3 + 0x24) * (int32_t)uVar4);
            uVar6 = *(uint32_t*)((char*)(intptr_t)iVar3 + 0x1c) % uVar4;
            *(int32_t*)((char*)(intptr_t)iVar3 + 0x38) =
                *(int32_t*)((char*)(intptr_t)iVar3 + 0xc);
            iVar7 = *(int32_t*)((char*)(intptr_t)iVar3 + 0xc) * (int32_t)uVar4;
            *(uint32_t*)((char*)(intptr_t)iVar3 + 0x34) = uVar4;
            *(int32_t*)((char*)(intptr_t)iVar3 + 0x3c) = iVar7;
            if (uVar6 == 0) {
                uVar6 = uVar4;
            }
            *(uint32_t*)((char*)(intptr_t)iVar3 + 0x44) = uVar6;
            uVar4 = *(uint32_t*)((char*)(intptr_t)iVar3 + 0x20) %
                    *(uint32_t*)((char*)(intptr_t)iVar3 + 0xc);
            if (uVar4 == 0) {
                uVar4 = *(uint32_t*)((char*)(intptr_t)iVar3 + 0xc);
            }
            *(uint32_t*)((char*)(intptr_t)iVar3 + 0x48) = uVar4;
            if (10 < esi[0x5a] + iVar7) {
                puVar2 = (uint32_t*)(intptr_t)*esi;
                puVar2[5] = 0xd;
                ((void (*)(void))(uintptr_t)puVar2[0])();
            }
            if (0 < iVar7) {
                do {
                    esi[esi[0x5a] + 0x5b] = (int32_t)local_8;
                    iVar7 = iVar7 + -1;
                    esi[0x5a] = esi[0x5a] + 1;
                } while (iVar7 != 0);
            }
            uVar4 = local_8 + 1;
            local_c = local_c + 1;
            local_8 = uVar4;
        } while ((int32_t)uVar4 < esi[0x53]);
    }
    return uVar4;
}

// 0x6914d0 — observed shape
void FUN_006914d0(void* self)
{
    int32_t* ebx = (int32_t*)self;
    int32_t iVar1, iVar2, iVar4;
    uint32_t* puVar3;
    uint32_t* puVar5;
    uint32_t* puVar6;
    int32_t local_c;
    int32_t* local_8;

    local_c = 0;
    if (0 < ebx[0x53]) {
        local_8 = ebx + 0x54;
        do {
            iVar1 = *local_8;
            if (*(int32_t*)((char*)(intptr_t)iVar1 + 0x4c) == 0) {
                iVar2 = *(int32_t*)((char*)(intptr_t)iVar1 + 0x10);
                if (((iVar2 < 0) || (3 < iVar2)) || (ebx[iVar2 + 0x2a] == 0)) {
                    puVar5 = (uint32_t*)(intptr_t)*ebx;
                    puVar5[5] = 0x34;
                    puVar5[6] = (uint32_t)iVar2;
                    ((void (*)(void))(uintptr_t)puVar5[0])();
                }
                puVar3 = (uint32_t*)(uintptr_t)
                    ((void* (*)(void))(uintptr_t)vfn0(ebx[1]))();
                puVar5 = (uint32_t*)(intptr_t)ebx[iVar2 + 0x2a];
                puVar6 = puVar3;
                for (iVar4 = 0x21; iVar4 != 0; iVar4 = iVar4 + -1) {
                    *puVar6 = *puVar5;
                    puVar5 = puVar5 + 1;
                    puVar6 = puVar6 + 1;
                }
                *(uint32_t**)((char*)(intptr_t)iVar1 + 0x4c) = puVar3;
            }
            local_c = local_c + 1;
            local_8 = local_8 + 1;
        } while (local_c < ebx[0x53]);
    }
    return;
}

// 0x691570 — observed shape
void FUN_00691570(int param_1)
{
    FUN_00691340((void*)(intptr_t)param_1);
    FUN_006914d0((void*)(intptr_t)param_1);
    ((void (*)(int))(uintptr_t)vfn0((intptr_t)param_1 + 0x1c0))(param_1);
    ((void (*)(int))(uintptr_t)vfn0((intptr_t)param_1 + 0x1b0))(param_1);
    *(uint32_t*)(intptr_t)(*(uint32_t**)((char*)(intptr_t)param_1 + 0x1b8)) =
        *(uint32_t*)((char*)(intptr_t)(*(int32_t*)((char*)(intptr_t)param_1 + 0x1b0)) + 4);
    return;
}
