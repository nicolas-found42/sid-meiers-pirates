// Reconstruction batch mass_0258 — Sid Meier's Pirates! (2004), PE32 i386.
// Candidates translated from Ghidra 12.2 pseudocode under
// analysis/pseudocode/functions/. Provider pseudocode is not original source.

#include <cstdint>
#include <cstddef>
#include <cmath>

extern void FUN_005f8d40(int v);
extern uint32_t FUN_005f0fa4(float a, float b);
extern void thunk_FUN_005f3fe7(float* out, const float* a, const float* b, float t);
extern void thunk_FUN_005f148d(float* a, float* b);
extern long double thunk_FUN_005f2050(float* m);
extern void thunk_FUN_005f3a2d(void* out, float* m);

extern void* g_ptr_7188b8;
extern void* g_dat_7188c0;
extern void* g_dat_718860;
extern void* g_dat_718864;
extern void* g_dat_71883c;
extern void* g_dat_718840;
extern void* g_dat_718894;
extern void* g_dat_71891c;
extern void* g_dat_718920;

extern int32_t g_index_006da658[];
extern float g_value_006dae60[];

// 0x5f40f8 — observed shape
void FUN_005f40f8(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4,
                  uint32_t param_5, uint32_t param_6) {
    FUN_005f8d40(1);
    ((void (*)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t))g_ptr_7188b8)(
        param_1, param_2, param_3, param_4, param_5, param_6);
}

// 0x5f4124 — observed shape
float* FUN_005f4124(float* param_1, float* param_2, float* param_3, float* param_4,
                    float* param_5, float param_6) {
    float local_24[16];
    float local_14[16];

    thunk_FUN_005f3fe7(local_24, param_2, param_5, param_6);
    thunk_FUN_005f3fe7(local_14, param_3, param_4, param_6);
    param_6 = (1.0f - param_6) * param_6;
    thunk_FUN_005f3fe7(param_1, local_24, local_14, param_6 + param_6);
    return param_1;
}

// 0x5f417d — observed shape
// NEEDS_MANUAL: indirect jump through table at 0x7188c0, jumptable not recovered
void FUN_005f417d() {
    FUN_005f8d40(1);
    ((void (*)())g_dat_7188c0)();
}

// 0x5f41c1 — observed shape
float* FUN_005f41c1(float* param_1, float* param_2, float* param_3, float* param_4,
                    float param_5, float param_6) {
    float local_24[16];
    float local_14[16];
    uint32_t iVar1;

    param_5 = param_5 + param_6;
    iVar1 = FUN_005f0fa4(param_5, 0.0f);
    if (iVar1 == 0) {
        thunk_FUN_005f3fe7(local_24, param_2, param_3, param_5);
        thunk_FUN_005f3fe7(local_14, param_2, param_4, param_5);
        thunk_FUN_005f3fe7(param_1, local_24, local_14, param_6 / param_5);
    }
    else if (param_1 != param_2) {
        param_1[0] = param_2[0];
        param_1[1] = param_2[1];
        param_1[2] = param_2[2];
        param_1[3] = param_2[3];
    }
    return param_1;
}

// 0x5f424b — observed shape
// NEEDS_MANUAL: indirect jump through table at 0x718860, jumptable not recovered
void FUN_005f424b() {
    FUN_005f8d40(1);
    ((void (*)())g_dat_718860)();
}

// 0x5f4307 — observed shape
// NEEDS_MANUAL: indirect jump through table at 0x718864, jumptable not recovered
void FUN_005f4307() {
    FUN_005f8d40(1);
    ((void (*)())g_dat_718864)();
}

// 0x5f43d0 — observed shape
// NEEDS_MANUAL: indirect jump through table at 0x71883c, jumptable not recovered
void FUN_005f43d0() {
    FUN_005f8d40(1);
    ((void (*)())g_dat_71883c)();
}

// 0x5f441e — observed shape
// NEEDS_MANUAL: indirect jump through table at 0x718840, jumptable not recovered
void FUN_005f441e() {
    FUN_005f8d40(1);
    ((void (*)())g_dat_718840)();
}

// 0x5f44d5 — observed shape
// NEEDS_MANUAL: indirect jump through table at 0x718894, jumptable not recovered
void FUN_005f44d5() {
    FUN_005f8d40(1);
    ((void (*)())g_dat_718894)();
}

// 0x5f4589 — observed shape
// NEEDS_MANUAL: indirect jump through table at 0x71891c, jumptable not recovered
void FUN_005f4589() {
    FUN_005f8d40(1);
    ((void (*)())g_dat_71891c)();
}

// 0x5f465d — observed shape
// NEEDS_MANUAL: the listing exposes no typed parameters; three coordinates arrive on
// the x87 stack through ftol/extraout_ST0/extraout_ST1 and are reconstructed here as
// a, b, c, with fa/fb/fc their fractional parts. Table index/value globals and the
// trailing 1.5 scale are preserved exactly as printed by the provider.
long double FUN_005f465d(float a, float b, float c) {
    int32_t ia = (int32_t)std::trunc(a);
    int32_t ib = (int32_t)std::trunc(b);
    int32_t ic = (int32_t)std::trunc(c);
    uint32_t ui0 = (uint32_t)ia & 0xff;
    uint32_t uj0 = (uint32_t)ib & 0xff;
    uint32_t uk0 = (uint32_t)ic & 0xff;
    uint32_t ui1 = (ui0 + 1) & 0xff;
    uint32_t uj1 = (uj0 + 1) & 0xff;
    uint32_t uk1 = (uk0 + 1) & 0xff;
    float fa = a - (float)ia;
    float fb = b - (float)ib;
    float fc = c - (float)ic;
    float fb_m1 = fb - 1.0f;
    float fc_m1 = fc - 1.0f;
    float sA = (3.0f - 2.0f * fa) * fa * fa;
    float sB = (3.0f - 2.0f * fb) * fb * fb;
    float sC = (3.0f - 2.0f * fc) * fc * fc;
    int e0, e1, e2, e3, e4, e5, e6, e7;
    long double v, v2, v3, v4, x, g;
    float f9, f10;

    auto V = [](int off, int comp) -> float {
        return g_value_006dae60[off / 4 + comp];
    };
    auto E = [](uint32_t i, uint32_t j, uint32_t k) -> int {
        return (g_index_006da658[g_index_006da658[i] + (int)j] + (int)k) * 0xc;
    };

    e0 = E(ui0, uj0, uk0);
    v = (long double)fa * V(e0, 0) + (long double)fb * V(e0, 1) +
        (long double)fc * V(e0, 2);

    e1 = E(ui1, uj0, uk0);
    e2 = E(ui0, uj1, uk0);
    e3 = E(ui1, uj1, uk0);

    v = (((long double)fb * V(e1, 0) + (long double)fb * V(e1, 1) +
          (long double)fc * V(e1, 2)) - v) * (long double)sA + v;

    v2 = (long double)fa * V(e2, 0) + (long double)fb_m1 * V(e2, 1) +
         (long double)fc * V(e2, 2);
    f9 = (float)((((long double)fb * V(e3, 0) + (long double)fb_m1 * V(e3, 1) +
                   (long double)fc * V(e3, 2)) - v2) * (long double)sA + v2 -
                 v) * (long double)sB + v);

    e4 = E(ui0, uj0, uk1);
    v3 = (long double)fa * V(e4, 0) + (long double)fb * V(e4, 1) +
         (long double)fc_m1 * V(e4, 2);

    e5 = E(ui1, uj0, uk1);
    e6 = E(ui0, uj1, uk1);
    e7 = E(ui1, uj1, uk1);

    v4 = (long double)fa * V(e6, 0) + (long double)fb_m1 * V(e6, 1) +
         (long double)fc_m1 * V(e6, 2);
    f10 = (float)((((long double)fb * V(e5, 0) + (long double)fb * V(e5, 1) +
                    (long double)fc_m1 * V(e5, 2)) - v3) * (long double)sA + v3);

    x = (long double)(fa - 1.0f) * V(e7, 0) + (long double)fb_m1 * V(e7, 1) +
        (long double)fc_m1 * V(e7, 2);

    g = ((((x - v4) * (long double)sA + v4) - (long double)f10) *
         (long double)sB + (long double)f10) - (long double)f9;
    g = g + (long double)f9;
    return (long double)sC * g * 1.5L;
}

// 0x5f48c8 — observed shape
// NEEDS_MANUAL: indirect jump through table at 0x718920, jumptable not recovered
void FUN_005f48c8() {
    FUN_005f8d40(1);
    ((void (*)())g_dat_718920)();
}

// 0x5f497a — observed shape
void FUN_005f497a(float* param_1, float* param_2, float* param_3) {
    float fVar1 = param_3[1];
    float fVar2 = param_2[0];
    float fVar3 = param_3[5];
    float fVar4 = param_2[1];
    float fVar5 = param_3[0xd];
    float fVar6 = param_3[2];
    float fVar7 = param_2[0];
    float fVar8 = param_3[6];
    float fVar9 = param_2[1];
    float fVar10 = param_3[0xe];
    float fVar11 = param_3[3];
    float fVar12 = param_2[0];
    float fVar13 = param_3[7];
    float fVar14 = param_2[1];
    float fVar15 = param_3[0xf];

    param_1[0] = param_2[0] * param_3[0] + param_3[4] * param_2[1] + param_3[0xc];
    param_1[1] = fVar3 * fVar4 + fVar1 * fVar2 + fVar5;
    param_1[2] = fVar8 * fVar9 + fVar6 * fVar7 + fVar10;
    param_1[3] = fVar13 * fVar14 + fVar11 * fVar12 + fVar15;
}

// 0x5f49e7 — observed shape
float* FUN_005f49e7(float* param_1, int param_2, float* param_3, int param_4,
                    float* param_5, int param_6) {
    if (param_6 != 0) {
        float* pfVar18 = param_1;
        do {
            float fVar2 = param_3[0];
            float fVar3 = param_5[1];
            float fVar4 = param_3[0];
            float fVar5 = param_5[5];
            float fVar6 = param_3[1];
            float fVar7 = param_5[0xd];
            float fVar8 = param_5[2];
            float fVar9 = param_3[0];
            float fVar10 = param_5[6];
            float fVar11 = param_3[1];
            float fVar12 = param_5[0xe];
            float fVar13 = param_3[0];
            float fVar14 = param_5[3];
            float fVar15 = param_3[1];
            float fVar16;
            float fVar17;

            param_3 = (float*)((uint8_t*)param_3 + param_4);
            param_6 = param_6 - 1;
            fVar16 = param_5[7];
            fVar17 = param_5[0xf];
            pfVar18[0] = fVar2 * param_5[0] + param_5[4] * fVar6 + param_5[0xc];
            pfVar18[1] = fVar5 * fVar6 + fVar3 * fVar4 + fVar7;
            pfVar18[2] = fVar10 * fVar11 + fVar8 * fVar9 + fVar12;
            pfVar18[3] = fVar15 * fVar16 + fVar13 * fVar14 + fVar17;
            pfVar18 = (float*)((uint8_t*)pfVar18 + param_2);
        } while (param_6 != 0);
    }
    return param_1;
}

// 0x5f4a6c — observed shape
void FUN_005f4a6c(float* param_1, float* param_2, float* param_3) {
    float fVar1 = param_2[0];
    float fVar2 = param_3[1];
    float fVar3 = param_2[1];
    float fVar4 = param_3[5];
    float fVar5 = param_3[0xd];
    float fVar6 = param_3[0xf] + param_2[1] * param_3[7] + param_2[0] * param_3[3];
    uint32_t iVar7;

    param_1[0] = param_3[0xc] + param_2[1] * param_3[4] + param_2[0] * param_3[0];
    param_1[1] = fVar5 + fVar3 * fVar4 + fVar1 * fVar2;
    iVar7 = FUN_005f0fa4(fVar6, 1.0f);
    if (iVar7 == 0) {
        fVar6 = 1.0f / fVar6;
        param_1[0] = fVar6 * param_1[0];
        param_1[1] = fVar6 * param_1[1];
    }
}

// 0x5f4aeb — observed shape
// NEEDS_MANUAL: the provider left the pointer advance as the high dword of the
// FUN_005f0fa4 result (extraout_ECX / undefined8); translated as param_3 advances by
// param_4, with param_5 invariant across iterations.
float* FUN_005f4aeb(float* param_1, int param_2, float* param_3, int param_4,
                    float* param_5, int param_6) {
    if (param_6 != 0) {
        float* pfVar7 = param_1;
        do {
            float fVar1 = param_5[1];
            float fVar2 = param_3[0];
            float fVar3 = param_5[5];
            float fVar4 = param_3[1];
            float fVar5 = param_5[0xd];
            float fVar6 = param_5[7] * param_3[1] + param_5[3] * param_3[0] + param_5[0xf];
            uint32_t uVar8;

            pfVar7[0] = param_3[0] * param_5[0] + param_5[4] * param_3[1] + param_5[0xc];
            pfVar7[1] = fVar3 * fVar4 + fVar1 * fVar2 + fVar5;
            uVar8 = FUN_005f0fa4(fVar6, 1.0f);
            if ((int)uVar8 == 0) {
                fVar6 = 1.0f / fVar6;
                pfVar7[0] = fVar6 * pfVar7[0];
                pfVar7[1] = fVar6 * pfVar7[1];
            }
            param_3 = (float*)((uint8_t*)param_3 + param_4);
            pfVar7 = (float*)((uint8_t*)pfVar7 + param_2);
            param_6 = param_6 - 1;
        } while (param_6 != 0);
    }
    return param_1;
}

// 0x5f4b85 — observed shape
void FUN_005f4b85(float* param_1, float* param_2) {
    float local_10, local_c, local_8;
    float fVar2 = param_2[2] * param_2[2] + param_2[1] * param_2[1] +
                  param_2[0] * param_2[0];
    uint32_t iVar3 = FUN_005f0fa4(fVar2, 1.0f);

    if (iVar3 == 0) {
        if (fVar2 <= 1.1754944e-38f) {
            param_1[0] = 0.0f;
            param_1[1] = 0.0f;
            param_1[2] = 0.0f;
            return;
        }
        fVar2 = 1.0f / std::sqrt(fVar2);
        local_10 = fVar2 * param_2[0];
        local_c = fVar2 * param_2[1];
        float* pfVar1 = param_2 + 2;
        param_2 = &local_10;
        local_8 = fVar2 * *pfVar1;
    }
    else if (param_1 == param_2) {
        return;
    }
    param_1[0] = param_2[0];
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
}

// 0x5f4c24 — observed shape
void FUN_005f4c24(float* param_1, float* param_2, float* param_3) {
    float fVar1 = param_2[0];
    float fVar2 = param_3[2];
    float fVar3 = param_2[0];
    float fVar4 = param_3[1];
    float fVar5 = param_2[1];
    float fVar6 = param_3[6];
    float fVar7 = param_2[1];
    float fVar8 = param_3[5];
    float fVar9 = param_2[2];
    float fVar10 = param_3[10];
    float fVar11 = param_2[2];
    float fVar12 = param_3[9];
    float fVar13 = param_3[0xd];
    float fVar14 = param_3[0xe];
    float fVar15 = param_3[0xf] + param_2[2] * param_3[0xb] +
                   param_2[1] * param_3[7] + param_2[0] * param_3[3];
    uint32_t iVar16;

    param_1[0] = param_3[0xc] + param_2[2] * param_3[8] +
                 param_2[1] * param_3[4] + param_2[0] * param_3[0];
    param_1[1] = fVar13 + fVar11 * fVar12 + fVar7 * fVar8 + fVar3 * fVar4;
    param_1[2] = fVar14 + fVar9 * fVar10 + fVar5 * fVar6 + fVar1 * fVar2;
    iVar16 = FUN_005f0fa4(fVar15, 1.0f);
    if (iVar16 == 0) {
        fVar15 = 1.0f / fVar15;
        param_1[0] = fVar15 * param_1[0];
        param_1[1] = fVar15 * param_1[1];
        param_1[2] = fVar15 * param_1[2];
    }
}

// 0x5f5411 — observed shape
void FUN_005f5411(float* param_1, float* param_2) {
    float local_14, local_10, local_c, local_8;
    float fVar2 = param_2[3] * param_2[3] + param_2[2] * param_2[2] +
                  param_2[1] * param_2[1] + param_2[0] * param_2[0];
    uint32_t iVar3 = FUN_005f0fa4(fVar2, 1.0f);

    if (iVar3 == 0) {
        if (fVar2 <= 1.1754944e-38f) {
            param_1[0] = 0.0f;
            param_1[1] = 0.0f;
            param_1[2] = 0.0f;
            param_1[3] = 0.0f;
            return;
        }
        fVar2 = 1.0f / std::sqrt(fVar2);
        local_14 = fVar2 * param_2[0];
        local_10 = fVar2 * param_2[1];
        local_c = fVar2 * param_2[2];
        float* pfVar1 = param_2 + 3;
        param_2 = &local_14;
        local_8 = fVar2 * *pfVar1;
    }
    else if (param_1 == param_2) {
        return;
    }
    param_1[0] = param_2[0];
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
}

// 0x5f54c9 — observed shape
uint32_t FUN_005f54c9(float* param_1, uint8_t* param_2, float* param_3,
                      float* param_4) {
    float local_88[10];
    float local_5c, local_58, local_54;
    float local_4c, local_48, local_44;
    float local_3c, local_38, local_34;
    float local_1c, local_18, local_14;
    float* local_10[3];
    float* local_60;
    float fVar5, fVar6, fVar7;
    int iVar8, ia, ib;
    long double fVar10;
    uint32_t uVar9;

    local_88[0] = 1.0f;
    local_88[1] = 0.0f;
    local_88[2] = 0.0f;
    local_88[3] = 0.0f;
    local_88[4] = 1.0f;
    local_88[5] = 0.0f;
    local_88[6] = 0.0f;
    local_88[7] = 0.0f;
    local_88[8] = 1.0f;

    param_3[0] = param_4[0xc];
    param_3[1] = param_4[0xd];
    param_3[2] = param_4[0xe];

    local_10[0] = &local_5c;
    local_10[1] = &local_4c;
    local_10[2] = &local_3c;

    local_5c = param_4[0];
    local_58 = param_4[1];
    local_54 = param_4[2];
    local_4c = param_4[4];
    local_48 = param_4[5];
    local_44 = param_4[6];
    local_3c = param_4[8];
    local_38 = param_4[9];
    local_34 = param_4[10];

    fVar5 = std::sqrt(local_5c * local_5c + local_58 * local_58 +
                      local_54 * local_54);
    param_1[0] = fVar5;
    fVar6 = std::sqrt(local_4c * local_4c + local_48 * local_48 +
                      local_44 * local_44);
    param_1[1] = fVar6;
    fVar7 = std::sqrt(local_3c * local_3c + local_38 * local_38 +
                      local_34 * local_34);
    param_1[2] = fVar7;

    if (fVar6 <= fVar5) {
        if (fVar7 <= fVar5) {
            iVar8 = 0;
            if (fVar7 <= fVar6) {
                ia = 2;
                ib = 1;
            }
            else {
                ia = 1;
                ib = 2;
            }
        }
        else {
            ia = 1;
            ib = 0;
            iVar8 = 2;
        }
    }
    else if (fVar7 <= fVar6) {
        iVar8 = 1;
        if (fVar7 <= fVar5) {
            ib = 0;
            ia = 2;
        }
        else {
            ia = 0;
            ib = 2;
        }
    }
    else {
        ia = 0;
        iVar8 = 2;
        ib = 1;
    }

    local_60 = param_1 + iVar8;
    if (*local_60 < 0.0001f) {
        float* pfVar2 = local_10[iVar8];
        pfVar2[0] = local_88[iVar8 * 3];
        pfVar2[1] = local_88[iVar8 * 3 + 1];
        pfVar2[2] = local_88[iVar8 * 3 + 2];
    }
    float** ppfVar1 = local_10 + iVar8;
    thunk_FUN_005f148d(*ppfVar1, *ppfVar1);
    if (0.0001f <= param_1[ib]) {
        // straight to the shared normalization below
    }
    else {
        float* pfVar2 = *ppfVar1;
        float fa = std::fabs(pfVar2[0]);
        local_88[9] = std::fabs(pfVar2[1]);
        float fc = std::fabs(pfVar2[2]);
        int kVar;

        if (local_88[9] <= fa) {
            if (fc <= fa && fc <= local_88[9]) {
                kVar = 2;
            }
            else {
                kVar = 1;
            }
        }
        else if (local_88[9] < fc || fa < fc) {
            kVar = 0;
        }
        else {
            kVar = 2;
        }

        float* pfVar3 = local_10[ib];
        local_1c = local_88[kVar * 3 + 2] * pfVar2[1] -
                   pfVar2[2] * local_88[kVar * 3 + 1];
        local_18 = pfVar2[2] * local_88[kVar * 3] -
                   pfVar2[0] * local_88[kVar * 3 + 2];
        local_14 = pfVar2[0] * local_88[kVar * 3 + 1] -
                   local_88[kVar * 3] * pfVar2[1];
        pfVar3[0] = local_1c;
        pfVar3[1] = local_18;
        pfVar3[2] = local_14;
    }

    {
        float* pfVar2 = local_10[ib];
        thunk_FUN_005f148d(pfVar2, pfVar2);
    }
    if (param_1[ia] < 0.0001f) {
        float* pfVar2 = local_10[ib];
        float* pfVar3 = *ppfVar1;
        float* pfVar4 = local_10[ia];

        local_1c = pfVar2[2] * pfVar3[1] - pfVar3[2] * pfVar2[1];
        local_18 = pfVar2[0] * pfVar3[2] - pfVar2[2] * pfVar3[0];
        local_14 = pfVar2[1] * pfVar3[0] - pfVar2[0] * pfVar3[1];
        pfVar4[0] = local_1c;
        pfVar4[1] = local_18;
        pfVar4[2] = local_14;
    }
    thunk_FUN_005f148d(local_10[ia], local_10[ia]);

    fVar10 = thunk_FUN_005f2050(&local_5c);
    if (fVar10 < 0.0L) {
        float* pfVar2 = *ppfVar1;
        *local_60 = -*local_60;
        local_1c = -pfVar2[0];
        local_18 = -pfVar2[1];
        local_14 = -pfVar2[2];
        pfVar2[0] = local_1c;
        pfVar2[1] = local_18;
        pfVar2[2] = local_14;
        fVar10 = -fVar10;
    }

    if ((fVar10 - 1.0L) * (fVar10 - 1.0L) <= 0.0001L) {
        thunk_FUN_005f3a2d(param_2, &local_5c);
        uVar9 = 0;
        *(float*)(param_2 + 0xc) = -*(float*)(param_2 + 0xc);
    }
    else {
        uVar9 = 0x8876086c;
    }
    return uVar9;
}
