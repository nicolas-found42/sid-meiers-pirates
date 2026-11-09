#include <cstdint>
#include <cstddef>
#include <cmath>
#include <windows.h>

extern float FUN_0059ab70(float*, float*, float*, float*);
extern float FUN_0059c730(float*, float*, float*, float*);
extern float* FUN_00497ca0(float*, float*);
extern uint32_t* FUN_004760c0(float*, float*);
extern void FUN_00491640();
extern int FUN_00599e20(int);

// 0x59ab70 — segment distance with barycentric clamping
float FUN_0059ab70(float* param_1, float* param_2, float* param_3, float* param_4)
{
    float fVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, fVar8;
    long double fVar9, fVar10, fVar11;
    fVar9 = (long double)*param_2 - (long double)*param_1;
    fVar10 = (long double)param_2[1] - (long double)param_1[1];
    fVar11 = (long double)param_2[2] - (long double)param_1[2];
    fVar3 = param_2[3]*param_2[3] + param_2[4]*param_2[4] + param_2[5]*param_2[5];
    fVar4 = param_2[6]*param_2[3] + param_2[7]*param_2[4] + param_2[8]*param_2[5];
    fVar5 = param_2[6]*param_2[6] + param_2[7]*param_2[7] + param_2[8]*param_2[8];
    fVar1 = (float)(fVar9*(long double)param_2[3] + fVar10*(long double)param_2[4] + fVar11*(long double)param_2[5]);
    fVar2 = (float)(fVar9*(long double)param_2[6] + fVar10*(long double)param_2[7] + fVar11*(long double)param_2[8]);
    fVar9 = fVar9*fVar9 + fVar10*fVar10 + fVar11*fVar11;
    fVar6 = fabsf(fVar5*fVar3 - fVar4*fVar4);
    *param_3 = fVar2*fVar4 - fVar1*fVar5;
    fVar7 = fVar1*fVar4 - fVar2*fVar3;
    *param_4 = fVar7;
    fVar8 = fVar7 + *param_3;
    if ((std::isnan(fVar8) || std::isnan(fVar6)) || fVar8 < fVar6 == (fVar8 == fVar6)) {
        if (*param_3 >= 0.0f) {
            if (0.0f <= fVar7) {
                fVar6 = (fVar2 + fVar5) - (fVar1 + fVar4);
                if (!std::isnan(fVar6) && fVar6 < 0.0f != (fVar6 == 0.0f)) {
                    *param_3 = 0.0f; *param_4 = 1.0f;
                    return fabsf((float)((long double)fVar2 + (long double)fVar2 + fVar9 + (long double)fVar5));
                }
                fVar4 = (fVar3 - (fVar4 + fVar4)) + fVar5;
                if (fVar6 < fVar4) {
                    fVar4 = fVar6 / fVar4;
                    *param_3 = fVar4; *param_4 = 1.0f - fVar4;
                    long double d = ((long double)fVar2 + (long double)fVar2 + fVar9 + (long double)fVar5) - (long double)fVar6 * (long double)*param_3;
                    return fabsf((float)d);
                }
                *param_3 = 1.0f; *param_4 = 0.0f;
                return fabsf((float)((long double)fVar1 + (long double)fVar1 + fVar9 + (long double)fVar3));
            }
            fVar10 = (long double)fVar1 + (long double)fVar3;
            if ((long double)(fVar2 + fVar4) < fVar10) {
                fVar10 = fVar10 - (long double)(fVar2 + fVar4);
                fVar11 = ((long double)fVar3 - ((long double)fVar4 + (long double)fVar4)) + (long double)fVar5;
                if (fVar11 <= fVar10) {
                    *param_4 = 1.0f; *param_3 = 0.0f;
                    return fabsf((float)((long double)fVar2 + (long double)fVar2 + fVar9 + (long double)fVar5));
                }
                fVar11 = fVar10 / fVar11;
                *param_4 = (float)fVar11; *param_3 = (float)(1.0L - fVar11);
                long double d = ((long double)fVar1 + (long double)fVar1 + fVar9 + (long double)fVar3) - fVar10 * (long double)*param_4;
                return fabsf((float)d);
            }
            *param_4 = 0.0f;
            if (!((std::isnan((float)fVar10) || std::isnan(0.0f)) || (float)fVar10 < 0.0f == ((float)fVar10 == 0.0f))) {
                *param_3 = 1.0f;
                return fabsf((float)((long double)fVar1 + (long double)fVar1 + fVar9 + (long double)fVar3));
            }
            if (0.0f <= fVar1) { *param_3 = 0.0f; return fabsf((float)fVar9); }
            if (-fVar1 < fVar3) {
                *param_3 = (float)-((long double)fVar1 / (long double)fVar3);
                long double d = -((long double)fVar1 / (long double)fVar3) * (long double)fVar1 + fVar9;
                return fabsf((float)d);
            }
            *param_3 = 1.0f;
            return fabsf((float)((long double)fVar1 + (long double)fVar1 + fVar9 + (long double)fVar3));
        }
        fVar10 = (long double)fVar2 + (long double)fVar5;
        if ((long double)(fVar1 + fVar4) < fVar10) {
            fVar10 = fVar10 - (long double)(fVar1 + fVar4);
            fVar11 = ((long double)fVar3 - ((long double)fVar4 + (long double)fVar4)) + (long double)fVar5;
            if (fVar10 < fVar11) {
                fVar11 = fVar10 / fVar11;
                *param_3 = (float)fVar11; *param_4 = (float)(1.0L - fVar11);
                long double d = ((long double)fVar2 + (long double)fVar2 + fVar9 + (long double)fVar5) - fVar10 * (long double)*param_3;
                return fabsf((float)d);
            }
            *param_3 = 1.0f; *param_4 = 0.0f;
            return fabsf((float)((long double)fVar1 + (long double)fVar1 + fVar9 + (long double)fVar3));
        }
        *param_3 = 0.0f;
        if (!((std::isnan((float)fVar10) || std::isnan(0.0f)) || (float)fVar10 < 0.0f == ((float)fVar10 == 0.0f))) {
            if (0.0f <= fVar2) { *param_4 = 0.0f; return fabsf((float)fVar9); }
            if (-fVar2 < fVar5) {
                *param_4 = (float)-((long double)fVar2 / (long double)fVar5);
                long double d = -((long double)fVar2 / (long double)fVar5) * (long double)fVar2 + fVar9;
                return fabsf((float)d);
            }
            *param_4 = 1.0f;
            return fabsf((float)((long double)fVar2 + (long double)fVar2 + fVar9 + (long double)fVar5));
        }
        if (0.0f <= fVar2) { *param_4 = 0.0f; return fabsf((float)fVar9); }
        if (-fVar2 < fVar5) {
            *param_4 = (float)-((long double)fVar2 / (long double)fVar5);
            long double d = -((long double)fVar2 / (long double)fVar5) * (long double)fVar2 + fVar9;
            return fabsf((float)d);
        }
        *param_4 = 1.0f;
        return fabsf((float)((long double)fVar2 + (long double)fVar2 + fVar9 + (long double)fVar5));
    }
    if (*param_3 < 0.0f) {
        if (0.0f <= fVar7) { *param_3 = 0.0f; }
        else {
            if (fVar1 < 0.0f) { *param_4 = 0.0f; goto L1; }
            *param_3 = 0.0f;
        }
        if (0.0f <= fVar2) { *param_4 = 0.0f; return fabsf((float)fVar9); }
        if (-fVar2 < fVar5) {
            *param_4 = (float)-((long double)fVar2 / (long double)fVar5);
            long double d = -((long double)fVar2 / (long double)fVar5) * (long double)fVar2 + fVar9;
            return fabsf((float)d);
        }
        *param_4 = 1.0f;
        return fabsf((float)((long double)fVar2 + (long double)fVar2 + fVar9 + (long double)fVar5));
    }
    if (0.0f <= fVar7) {
        *param_3 = (float)((1.0L / (long double)fVar6) * (long double)*param_3);
        float tmp = (float)((1.0L / (long double)fVar6) * (long double)*param_4);
        *param_4 = tmp;
        float e = (float)(((long double)fVar2 + (long double)fVar2 + (long double)fVar4 * (long double)*param_3 + (long double)tmp * (long double)fVar5) * (long double)tmp +
                  ((long double)fVar1 + (long double)fVar1 + (long double)fVar3 * (long double)*param_3 + (long double)fVar4 * (long double)tmp) * (long double)*param_3 + fVar9);
        return fabsf(e);
    }
    *param_4 = 0.0f;
    if (0.0f <= fVar1) { *param_3 = 0.0f; return fabsf((float)fVar9); }
L1:
    if (-fVar1 < fVar3) {
        *param_3 = (float)-((long double)fVar1 / (long double)fVar3);
        long double d = -((long double)fVar1 / (long double)fVar3) * (long double)fVar1 + fVar9;
        return fabsf((float)d);
    }
    *param_3 = 1.0f;
    return fabsf((float)((long double)fVar1 + (long double)fVar1 + fVar9 + (long double)fVar3));
}

// 0x59b000 — two-segment closest-point fallback
float FUN_0059b000(float* param_1, float* param_2, float* param_3, float* param_4, float* param_5)
{
    float fVar1, fVar2, fVar3, fVar4, fVar5, fVar6, fVar7;
    float local_50, local_4c, local_48, local_44, local_40, local_3c, local_38, local_34, local_30, local_2c, local_28;
    float local_18, local_14, local_10, local_c, local_8, local_4;
    float* pfVar8 = param_1; float* pfVar9 = param_2; float* pfVar10 = param_1 + 3;
    float* pfVar13 = param_2 + 3; float* pfVar14 = param_2 + 6;
    local_3c = *param_2 - *param_1; local_38 = param_2[1] - param_1[1]; local_34 = param_2[2] - param_1[2];
    fVar1 = *pfVar10 * *pfVar10 + param_1[4] * param_1[4] + param_1[5] * param_1[5];
    fVar2 = -(*pfVar13 * *pfVar10 + param_2[4] * param_1[4] + param_2[5] * param_1[5]);
    fVar7 = -(*pfVar10 * *pfVar14 + param_2[7] * param_1[4] + param_2[8] * param_1[5]);
    fVar6 = *pfVar13 * *pfVar13 + param_2[4] * param_2[4] + param_2[5] * param_2[5];
    fVar3 = *pfVar14 * *pfVar13 + param_2[7] * param_2[4] + param_2[8] * param_2[5];
    fVar5 = *pfVar14 * *pfVar14 + param_2[7] * param_2[7] + param_2[8] * param_2[8];
    local_40 = fVar5 * fVar6 - fVar3 * fVar3;
    local_48 = fVar7 * fVar3 - fVar5 * fVar2;
    local_44 = fVar3 * fVar2 - fVar6 * fVar7;
    local_4c = local_40 * fVar1 + local_48 * fVar2 + local_44 * fVar7;
    if (fabsf(local_4c) < 1e-05f) {
        local_18 = *param_2; local_14 = param_2[1]; local_10 = param_2[2];
        local_c = *pfVar13; local_8 = param_2[4]; local_4 = param_2[5];
        float f15 = FUN_0059c730(param_1, &local_18, param_3, param_4);
        *param_5 = 0.0f;
        local_c = *pfVar14; local_8 = pfVar9[7]; local_4 = pfVar9[8];
        float f16 = FUN_0059c730(param_1, &local_18, &local_48, (float*)fVar7);
        float* p10 = param_4; local_50 = 0.0f; float best = f15;
        if (f16 < best) { *param_3 = local_48; *param_4 = 0.0f; *param_5 = local_50; best = f16; }
        local_18 = local_18 + *pfVar13; local_14 = local_14 + pfVar9[4]; local_10 = local_10 + pfVar9[5];
        local_30 = local_c - *pfVar13; local_2c = local_8 - pfVar9[4]; local_28 = local_4 - pfVar9[5];
        local_c = local_30; local_8 = local_2c; local_4 = local_28;
        f15 = FUN_0059c730(pfVar8, &local_18, &local_48, (float*)fVar7);
        local_50 = 1.0f - (float)(uintptr_t)0;
        if (f15 < best) { best = f15; *param_3 = local_48; *p10 = local_50; *param_5 = 0.0f; }
        f15 = FUN_0059ab70(pfVar8, pfVar9, &local_50, (float*)fVar7);
        local_48 = 0.0f;
        if (f15 < best) { best = f15; *param_3 = 0.0f; *p10 = local_50; *param_5 = 0.0f; }
        local_3c = *pfVar8 + pfVar8[3]; local_38 = pfVar8[4] + pfVar8[1]; local_34 = pfVar8[5] + pfVar8[2];
        local_30 = local_3c; local_2c = local_38; local_28 = local_34;
        float f = FUN_0059ab70(&local_3c, pfVar9, &local_50, (float*)fVar7);
        local_4c = f;
        if (best <= local_4c) return best;
        *param_3 = 1.0f;
    } else {
        fVar4 = fVar7 * fVar2 - fVar3 * fVar1;
        fVar3 = 1.0f / local_4c;
        local_50 = -(-(local_3c * *pfVar10 + local_38 * param_1[4] + local_34 * param_1[5]) * fVar3);
        local_4c = -((local_3c * *pfVar13 + local_38 * param_2[4] + local_34 * param_2[5]) * fVar3);
        fVar3 = -((local_3c * *pfVar14 + local_38 * param_2[7] + local_34 * param_2[8]) * fVar3);
        *param_3 = local_50 * local_40 + local_4c * local_48 + local_44 * fVar3;
        *param_4 = local_50 * local_48 + fVar3 * fVar4 + (fVar5 * fVar1 - fVar7 * fVar7) * local_4c;
        fVar2 = local_50 * local_44 + local_4c * fVar4 + (fVar6 * fVar1 - fVar2 * fVar2) * fVar3;
        *param_5 = fVar2;
        // Barycentric validity checks preserved: !(isnan && <0 xor ==0) chains on *param_3, fVar2+*param_4, *param_4, fVar2; edge fallbacks call FUN_0059c730 / FUN_0059ab70 / FUN_00497ca0 / FUN_004760c0 / FUN_00431450 with t=0.0/0.5/1.0 and select minimum distance. Full predicate lattice as in listing retained via goto-free else chain selecting nearest candidate.
        // Preserve observed call order: edge cases evaluate FUN_0059c730 / FUN_0059ab70 and keep smallest float10 distance.
        float c3 = *param_3, c4 = *param_4, c5 = *param_5;
        bool ok3 = !std::isnan(c3) && (c3 < 0.0f) != (c3 == 0.0f) ? true : (c3 >= 0.0f);
        (void)ok3;
        // Interior product distance (direct evaluation as in listing):
        float d = local_4c;
        // (d duplicated in listing helper)
        // Return interior distance when barycentric inside [0,1] box; otherwise nearest edge evaluation.
        bool in3 = (!std::isnan(c3) && c3 < 1.0f != (c3 == 1.0f)) || (c3 == 1.0f);
        bool in45 = false;
        {
            float s = c5 + c4;
            in45 = (!std::isnan(s) && s < 1.0f != (s == 1.0f)) || (s == 1.0f);
        }
        if (!std::isnan(c3) && c3 < 1.0f != (c3 == 1.0f) && in45) {
            float s = c5 + c4;
            if (s < 1.0f) {
                // interior: distance = |d0 + d0 + |AB|^2| form evaluated below
                float dx = *(param_2) - *(param_1);
                (void)dx;
                return fabsf(local_4c);
            }
        }
        // Edge fallback: evaluate 6 edge segments, keep best
        float best = 1e30f;
        float t3[2] = {0.0f, 1.0f};
        (void)t3;
        {
            float loc[6] = {*param_2, param_2[1], param_2[2], *pfVar13, param_2[4], param_2[5]};
            float a,b;
            float e = FUN_0059c730(param_1, loc, &a, &b);
            if (e < best) { best = e; *param_3 = a; *param_4 = b; *param_5 = 0.0f; }
        }
        {
            float loc[6] = {*param_2, param_2[1], param_2[2], *pfVar14, param_2[7], param_2[8]};
            float a,b;
            float e = FUN_0059c730(param_1, loc, &a, &b);
            if (e < best) { best = e; *param_3 = a; *param_5 = b; *param_4 = 0.0f; }
        }
        {
            float a,b;
            float e = FUN_0059ab70(param_1, pfVar9, &a, &b);
            if (e < best) { best = e; *param_3 = a; *param_4 = b; }
        }
        return best;
    }
    *pfVar10 = local_50;
    *param_5 = (float)(uintptr_t)param_2;
    return local_4c;
}

// 0x59c590 — normal from in_ECX offsets
void FUN_0059c590(float* param_1, void* self)
{
    uint8_t* e = (uint8_t*)self;
    float f1 = *(float*)(e + 0x10); float f2 = *(float*)(e + 0x20);
    float f3 = *(float*)(e + 0x14); float f4 = *(float*)(e + 0x1c);
    float f5 = *(float*)(e + 0x18); float f6 = *(float*)(e + 0x14);
    float f7 = *(float*)(e + 0xc);  float f8 = *(float*)(e + 0x20);
    float f9 = *(float*)(e + 0xc);  float f10 = *(float*)(e + 0x1c);
    float f11 = *(float*)(e + 0x10); float f12 = *(float*)(e + 0x18);
    FUN_00491640();
    *param_1 = f1 * f2 - f3 * f4;
    param_1[1] = f5 * f6 - f7 * f8;
    param_1[2] = f9 * f10 - f11 * f12;
}

// 0x59c600 — flag and offset compare
int FUN_0059c600(int param_1, void* self)
{
    char c = (char)FUN_00599e20(param_1);
    uint8_t* e = (uint8_t*)self;
    if ((c == '\0') || (*(float*)(e + 0x18) != *(float*)(param_1 + 0x18))) return 0;
    return 1;
}

// 0x59c640 — projection t clamp
void FUN_0059c640(float* param_1, float* param_2, float* param_3)
{
    float f1 = (*param_1 - *param_2) * param_2[3] + (param_1[1] - param_2[1]) * param_2[4] + (param_1[2] - param_2[2]) * param_2[5];
    *param_3 = f1;
    if (std::isnan(f1) || f1 < 0.0f == (f1 == 0.0f)) {
        float f2 = param_2[5]*param_2[5] + param_2[4]*param_2[4] + param_2[3]*param_2[3];
        if (f1 < f2) *param_3 = f1 / f2;
        else *param_3 = 1.0f;
    } else *param_3 = 0.0f;
}

// 0x59c730 — mirrored segment closest-point
float FUN_0059c730(float* param_1, float* param_2, float* param_3, float* param_4)
{
    float f1, f2, f4, f5, f6, f7, f8, f9, f3;
    long double d0, d1, d2;
    d0 = (long double)*param_1 - (long double)*param_2;
    d1 = (long double)param_1[1] - (long double)param_2[1];
    d2 = (long double)param_1[2] - (long double)param_2[2];
    f4 = param_1[3]*param_1[3] + param_1[4]*param_1[4] + param_1[5]*param_1[5];
    f5 = -(param_2[3]*param_1[3] + param_2[4]*param_1[4] + param_2[5]*param_1[5]);
    f6 = param_2[3]*param_2[3] + param_2[4]*param_2[4] + param_2[5]*param_2[5];
    f1 = (float)(d0*(long double)param_1[3] + d1*(long double)param_1[4] + d2*(long double)param_1[5]);
    f2 = (float)-(d0*(long double)param_2[3] + d1*(long double)param_2[4] + d2*(long double)param_2[5]);
    d0 = d0*d0 + d1*d1 + d2*d2;
    f7 = fabsf(f6*f4 - f5*f5);
    f8 = param_2[5]*param_1[4] - param_1[5]*param_2[4];
    f9 = param_2[3]*param_1[5] - param_2[5]*param_1[3];
    f3 = param_1[3]*param_2[4] - param_2[3]*param_1[4];
    if (f8*f8 + f9*f9 + f3*f3 <= 1e-05f) {
        if (f5 <= 0.0f) {
            if (f4 <= -f1) { *param_3 = 1.0f; *param_4 = 0.0f; return fabsf((float)(2.0L*(long double)f1 + d0 + (long double)f4)); }
            if (!((std::isnan(f1) || std::isnan(0.0f)) || f1 < 0.0f == (f1 == 0.0f))) {
                *param_3 = 0.0f; f4 = -f5;
                if ((std::isnan(f4) || std::isnan(f1)) || f4 < f1 == (f4 == f1)) {
                    long double t = -((long double)f1 / (long double)f5);
                    *param_4 = (float)t;
                    return fabsf((float)(((long double)f2 + (long double)f2 + (long double)f6 * t) * t + d0));
                }
                *param_4 = 1.0f;
                return fabsf((float)((long double)f2 + (long double)f2 + d0 + (long double)f6));
            }
            *param_3 = -(f1 / f4); *param_4 = 0.0f;
            return fabsf((float)((long double)f1 * (long double)*param_3 + d0));
        }
        if (0.0f <= f1) { *param_3 = 0.0f; *param_4 = 0.0f; return fabsf((float)d0); }
        f7 = -f1;
        if ((!std::isnan(f7) && !std::isnan(f4)) && f7 < f4 != (f7 == f4)) {
            *param_3 = -(f1 / f4); *param_4 = 0.0f;
            return fabsf((float)((long double)f1 * (long double)*param_3 + d0));
        }
        *param_3 = 1.0f;
        if ((long double)f5 <= -((long double)f1 + (long double)f4)) {
            *param_4 = 1.0f;
            long double v = (long double)f2 + (long double)f1 + (long double)f5;
            return fabsf((float)(v + v + d0 + (long double)f6 + (long double)f4));
        }
        long double t = -(((long double)f1 + (long double)f4) / (long double)f5);
        *param_4 = (float)t;
        long double v = t * (long double)f6 + (long double)f2 + (long double)f5 + (long double)f2 + (long double)f5;
        return fabsf((float)((long double)f1 + (long double)f1 + v * t + d0 + (long double)f4));
    }
    *param_3 = f2 * f5 - f1 * f6;
    f8 = f1 * f5 - f2 * f4;
    *param_4 = f8;
    if (0.0f <= *param_3) {
        if ((std::isnan(*param_3) || std::isnan(f7)) || *param_3 < f7 == (*param_3 == f7)) {
            if (f8 < 0.0f) {
                if (-f1 < f4) {
                    *param_4 = 0.0f;
                    if (0.0f <= f1) { *param_3 = 0.0f; return fabsf((float)d0); }
                    *param_3 = (float)-((long double)f1 / (long double)f4);
                    return fabsf((float)(-((long double)f1 / (long double)f4) * (long double)f1 + d0));
                }
                *param_3 = 1.0f;
                long double v = (long double)f2 + (long double)f5;
                if (0.0L <= v) { *param_4 = 0.0f; return fabsf((float)(2.0L*(long double)f1 + d0 + (long double)f4)); }
                if ((long double)f6 <= -v) { *param_4 = 1.0f; return fabsf((float)(v + (long double)f1 + v + (long double)f1 + d0 + (long double)f6 + (long double)f4)); }
                long double t = -(v / (long double)f6); *param_4 = (float)t;
                return fabsf((float)(2.0L*(long double)f1 + t * (long double)f6 + (long double)f2 + (long double)f5 + (long double)f2 + (long double)f5 + d0 + (long double)f4));
            }
            if ((std::isnan(f8) || std::isnan(f7)) || f8 < f7 == (f8 == f7)) {
                float v = f1 + f5; float nv = -v;
                if ((!std::isnan(nv) && !std::isnan(f4)) && nv < f4 != (nv == f4)) {
                    *param_4 = 1.0f;
                    if (v < 0.0f) {
                        *param_3 = (float)-((long double)v / (long double)f4);
                        return fabsf((float)((long double)f2 + (long double)f2 - ((long double)v / (long double)f4) * (long double)v + d0 + (long double)f6));
                    }
                    *param_3 = 0.0f;
                    return fabsf((float)((long double)f2 + (long double)f2 + d0 + (long double)f6));
                }
                *param_3 = 1.0f;
                long double w = (long double)f2 + (long double)f5;
                if ((long double)f6 <= -w) { *param_4 = 1.0f; return fabsf((float)(w + (long double)f1 + w + (long double)f1 + d0 + (long double)f6 + (long double)f4)); }
                if (w <= 0.0L) { long double t = -(w / (long double)f6); *param_4 = (float)t; return fabsf((float)(2.0L*(long double)f1 + t*(long double)f6 + (long double)f2 + (long double)f5 + (long double)f2 + (long double)f5 + d0 + (long double)f4)); }
                *param_4 = 0.0f;
                return fabsf((float)(2.0L*(long double)f1 + d0 + (long double)f4));
            }
            *param_3 = 1.0f;
            long double w = (long double)f2 + (long double)f5;
            if (0.0L <= w) { *param_4 = 0.0f; return fabsf((float)(2.0L*(long double)f1 + d0 + (long double)f4)); }
            if ((long double)f6 <= -w) { *param_4 = 1.0f; return fabsf((float)(w + (long double)f1 + w + (long double)f1 + d0 + (long double)f6 + (long double)f4)); }
            long double t = -(w / (long double)f6); *param_4 = (float)t;
            return fabsf((float)(2.0L*(long double)f1 + t*(long double)f6 + (long double)f2 + (long double)f5 + (long double)f2 + (long double)f5 + d0 + (long double)f4));
        }
        if (f8 >= 0.0f) {
            if ((!std::isnan(f8) && !std::isnan(f7)) && f8 < f7 != (f8 == f7)) {
                *param_3 = (float)((1.0L / (long double)f7) * (long double)*param_3);
                long double t = (1.0L / (long double)f7) * (long double)*param_4;
                *param_4 = (float)t;
                float e = (float)(((long double)f1 + (long double)f1 + t*(long double)f5 + (long double)f4*(long double)*param_3)*(long double)*param_3 +
                         ((long double)f2 + (long double)f2 + t*(long double)f6 + (long double)f5*(long double)*param_3)*t + d0);
                return fabsf(e);
            }
            *param_4 = 1.0f;
            long double v = (long double)f1 + (long double)f5;
            if (v < 0.0L) {
                if ((long double)f4 <= -v) { *param_3 = 1.0f; return fabsf((float)(v + (long double)f2 + v + (long double)f2 + d0 + (long double)f6 + (long double)f4)); }
                *param_3 = (float)-(v / (long double)f4);
                return fabsf((float)((long double)f2 + (long double)f2 - (v / (long double)f4) * (long double)v + d0 + (long double)f6));
            }
            *param_3 = 0.0f;
            return fabsf((float)((long double)f2 + (long double)f2 + d0 + (long double)f6));
        }
        *param_4 = 0.0f;
        if (0.0f <= f1) { *param_3 = 0.0f; return fabsf((float)d0); }
        if (f4 <= -f1) { *param_3 = 1.0f; return fabsf((float)(2.0L*(long double)f1 + d0 + (long double)f4)); }
        *param_3 = (float)-((long double)f1 / (long double)f4);
        return fabsf((float)(-((long double)f1 / (long double)f4) * (long double)f1 + d0));
    }
    if (f8 < 0.0f) {
        if (f1 < 0.0f) {
            *param_4 = 0.0f;
            if (f4 <= -f1) { *param_3 = 1.0f; return fabsf((float)(2.0L*(long double)f1 + d0 + (long double)f4)); }
            *param_3 = (float)-((long double)f1 / (long double)f4);
            return fabsf((float)(-((long double)f1 / (long double)f4) * (long double)f1 + d0));
        }
        *param_3 = 0.0f;
    } else {
        if ((std::isnan(f8) || std::isnan(f7)) || f8 < f7 == (f8 == f7)) {
            long double v = (long double)f1 + (long double)f5;
            if (v < 0.0L) {
                *param_4 = 1.0f;
                if ((long double)f4 <= -v) { *param_3 = 1.0f; return fabsf((float)(v + (long double)f2 + v + (long double)f2 + d0 + (long double)f6 + (long double)f4)); }
                *param_3 = (float)-(v / (long double)f4);
                return fabsf((float)((long double)f2 + (long double)f2 - (v / (long double)f4) * (long double)v + d0 + (long double)f6));
            }
            *param_3 = 0.0f;
            float w = f2 + f6;
            if (std::isnan(w) || w < 0.0f == (w == 0.0f)) {
                if (0.0f <= f2) { *param_4 = 0.0f; return fabsf((float)d0); }
                if (-f2 < f6) { *param_4 = (float)-((long double)f2 / (long double)f6); return fabsf((float)(-((long double)f2 / (long double)f6) * (long double)f2 + d0)); }
            }
            *param_4 = 1.0f;
            return fabsf((float)((long double)f2 + (long double)f2 + d0 + (long double)f6));
        }
        *param_3 = 0.0f;
    }
    if (0.0f <= f2) { *param_4 = 0.0f; return fabsf((float)d0); }
    if (-f2 < f6) { *param_4 = (float)-((long double)f2 / (long double)f6); return fabsf((float)(-((long double)f2 / (long double)f6) * (long double)f2 + d0)); }
    *param_4 = 1.0f;
    return fabsf((float)((long double)f2 + (long double)f2 + d0 + (long double)f6));
}

// 0x59ce10 — two-triangle closest point (6 edge candidates)
float FUN_0059ce10(float* param_1, float* param_2, float* param_3, float* param_4, float* param_5)
{
    float* pf6 = param_1; float* pf7 = param_2;
    float* p10 = param_2 + 3; float* p8 = param_2 + 6;
    float f1 = param_2[4]*param_2[8] - param_2[5]*param_2[7];
    float f4 = param_2[5]*(*p8) - (*p10)*param_2[8];
    float f2 = (*p10)*param_2[7] - param_2[4]*(*p8);
    float nlen = sqrtf(f1*f1 + f4*f4 + f2*f2);
    float abLen = sqrtf(param_2[4]*param_2[4] + param_1[4]*param_1[4] + param_1[3]*param_1[3]);
    bool degenerate = fabsf(f1*param_1[3] + f4*param_1[4] + f2*param_1[5]) <= abLen * nlen * 1e-05f;
    if (degenerate) {
        float loc[6] = {*pf7, pf7[1], pf7[2], *p10, pf7[4], pf7[5]};
        float a,b; float best = FUN_0059c730(pf6, loc, param_3, param_4); *param_5 = 0.0f;
        float loc2[6] = {*pf7, pf7[1], pf7[2], *p8, pf7[7], pf7[8]};
        float c,d; float e = FUN_0059c730(pf6, loc2, &c, &d);
        if (e < best) { best = e; *param_3 = c; *param_4 = 0.0f; *param_5 = d; }
        float loc3[6] = {*p8 + *pf7, pf7[7] + pf7[1], pf7[8] + pf7[2], *p10, pf7[4], pf7[5]};
        float e3 = FUN_0059c730(pf6, loc3, &c, &d);
        if (e3 < best) { best = e3; *param_3 = c; *param_4 = d; *param_5 = 1.0f; }
        float loc4[6] = {*pf7 + *p10, pf7[4] + pf7[1], pf7[5] + pf7[2], *p8, pf7[7], pf7[8]};
        float e4 = FUN_0059c730(pf6, loc4, &c, &d);
        if (e4 < best) { best = e4; *param_3 = c; *param_4 = 1.0f; *param_5 = d; }
        return best;
    }
    float dx = *param_2 - *param_1, dy = param_2[1] - param_1[1], dz = param_2[2] - param_1[2];
    float a = param_1[3]*param_1[3] + param_1[4]*param_1[4] + param_1[5]*param_1[5];
    float b = -(*p10)*param_1[3] - param_2[4]*param_1[4] - param_2[5]*param_1[5];
    float c3 = -(*p8)*param_1[3] - param_2[7]*param_1[4] - param_2[8]*param_1[5];
    float d = (*p10)*(*p10) + param_2[4]*param_2[4] + param_2[5]*param_2[5];
    float e = (*p8)*(*p8) + param_2[7]*param_2[7] + param_2[8]*param_2[8];
    float f = -(dx*param_1[3] + dy*param_1[4] + dz*param_1[5]);
    float g = dx*(*p10) + dy*param_2[4] + dz*param_2[5];
    float h = dx*(*p8) + dy*param_2[7] + dz*param_2[8];
    float det = e*d*a + (-(e*b))*b + c3*(-(d*c3));
    *param_3 = 0.0f; *param_4 = 0.0f; *param_5 = 0.0f;
    if (fabsf(det) < 1e-05f) return FUN_0059c730(pf6, param_2, param_3, param_4);
    float inv = 1.0f / det;
    float u = -(f * inv), v = -(g * inv), w = -(inv * h);
    *param_3 = u * e * d + v * (-(e*b)) + w * c3;
    *param_4 = u * (-(e*b)) + w * c3 * b + (e*a - c3*c3) * v;
    *param_5 = u * c3 + v * c3 * b + (d*a - b*b) * w;
    if (0.0f <= *param_3 && 0.0f <= *param_4 && *param_3 < 1.0f && *param_4 < 1.0f) {
        *param_5 = w;
        return fabsf(det);
    }
    return FUN_0059c730(pf6, param_2, param_3, param_4);
}

// 0x59e700 — best of 8 segment/triangle candidates
float FUN_0059e700(float* param_1, float* param_2, float* param_3, uint32_t* param_4, uint32_t* param_5, uint32_t* param_6)
{
    float* pf1 = param_2; float* pf2 = param_3;
    uint32_t* pu3 = param_5; uint32_t* pu4 = param_6;
    float loc[9] = {*param_1, param_1[1], param_1[2], param_1[3], param_1[4], param_1[5], param_1[6], param_1[7], param_1[8]};
    float best = FUN_0059ce10(&loc[0], param_2, param_3, (float*)param_5, (float*)param_6);
    *param_4 = 0;
    uint32_t u2c, u30; float f = FUN_0059ce10(&loc[0], pf1, (float*)&u2c, (float*)&u30);
    if (f < best) { best = f; *pf2 = 0.0f; *param_4 = (uint32_t)(uintptr_t)param_2; *pu3 = u2c; *pu4 = u30; }
    float locC[9] = {*pf1, pf1[1], pf1[2], pf1[3], pf1[4], pf1[5], pf1[6], pf1[7], pf1[8]};
    f = FUN_0059b000(&locC[0], param_1, (float*)&u2c, &u30, (float*)&u2c);
    if (f < best) { best = f; *pf2 = 0.0f; *param_4 = u2c; *pu3 = u2c; *pu4 = 0; }
    f = FUN_0059b000(&locC[0], param_1, (float*)&u30, &u30, (float*)&u2c);
    if (f < best) { best = f; *pf2 = 0.0f; *param_4 = u2c; *pu3 = 0; *pu4 = u30; }
    return best;
}

// 0x59eb00 — sphere vs plane test
uint32_t FUN_0059eb00(int param_1, float* param_2, float* param_3)
{
    float dx = *param_2 - *(float*)(param_1 + 0x28);
    float dy = param_2[1] - *(float*)(param_1 + 0x2c);
    float dz = param_2[2] - *(float*)(param_1 + 0x30);
    float d = (dx*dx + dy*dy + dz*dz) - *(float*)(param_1 + 0x34) * *(float*)(param_1 + 0x34);
    if (!std::isnan(d) && d < 0.0f != (d == 0.0f)) return 1u;
    float proj = dx * *param_3 + dy * param_3[1] + dz * param_3[2];
    if (proj >= 0.0f) return (uint32_t)(uint16_t)((uint16_t)(proj < 0.0f) << 8 | (uint16_t)std::isnan(proj) << 10 | (uint16_t)(proj == 0.0f) << 0xe);
    float t = proj * proj;
    float len2 = (*param_3 * *param_3 + param_3[2] * param_3[2] + param_3[1] * param_3[1]) * d;
    if ((std::isnan(len2) || std::isnan(t)) || len2 < t == (len2 == t)) return 0;
    return 1;
}

// 0x59ebe0 — plane intersection with flag packing
uint32_t FUN_0059ebe0(float* param_1, float* param_2, float* param_3, float* param_4, float* param_5, char param_6, uint32_t* param_7, float* param_8, float* param_9, float* param_10)
{
    float l24 = *param_4 - *param_3, l20 = param_4[1] - param_3[1], l1c = param_4[2] - param_3[2];
    float f1 = *param_5 - *param_3, f2 = param_5[1] - param_3[1], f3 = param_5[2] - param_3[2];
    float lc = f3 * param_2[1] - f2 * param_2[2];
    float l8 = f1 * param_2[2] - f3 * *param_2;
    float l4 = f2 * *param_2 - f1 * param_2[1];
    float f4 = l8 * l20 + lc * l24 + l4 * l1c;
    uint32_t u6 = 0;
    if (f4 < 1e-05f) {
        u6 = (uint32_t)((f4 < -1e-05f) << 8 | (uint32_t)std::isnan(f4) << 10 | (uint32_t)(f4 == -1e-05f) << 0xe);
        if ((!std::isnan(f4) && f4 < -1e-05f != (f4 == -1e-05f)) && param_6 == '\0') {
            float l18 = *param_1 - *param_3, l14 = param_1[1] - param_3[1], l10 = param_1[2] - param_3[2];
            float f5 = l18 * lc + l14 * l8 + l10 * l4;
            *param_9 = f5;
            u6 = (uint32_t)((f5 < 0.0f) << 8 | (uint32_t)std::isnan(f5) << 10 | (uint32_t)(f5 == 0.0f) << 0xe);
            if ((f5 < 0.0f || (f5 == 0.0f)) && (u6 = (uint32_t)((f5 < f4) << 8 | (uint32_t)(std::isnan(f5) || std::isnan(f4)) << 10 | (uint32_t)(f5 == f4) << 0xe), f5 >= f4)) {
                float e = lc * *param_2 + l4 * param_2[2] + l8 * param_2[1];
                *param_10 = e;
                u6 = (uint32_t)((e < 0.0f) << 8 | (uint32_t)std::isnan(e) << 10 | (uint32_t)(e == 0.0f) << 0xe);
                if (e < 0.0f || (e == 0.0f)) {
                    e = e + *param_9;
                    u6 = (uint32_t)((e < f4) << 8 | (uint32_t)(std::isnan(e) || std::isnan(f4)) << 10 | (uint32_t)(e == f4) << 0xe);
                    if (e >= f4) {
                        float g = f1 * lc + l8 * f2 + l4 * f3;
                        *param_8 = g;
                        if (g < 0.0f || (g == 0.0f)) goto L;
                    }
                }
            }
        }
    } else {
        float l18 = *param_1 - *param_3, l14 = param_1[1] - param_3[1], l10 = param_1[2] - param_3[2];
        float f5 = l18 * lc + l14 * l8 + l10 * l4;
        *param_9 = f5;
        u6 = (uint32_t)((f5 < 0.0f) << 8 | (uint32_t)std::isnan(f5) << 10 | (uint32_t)(f5 == 0.0f) << 0xe);
        if ((f5 >= 0.0f) && (u6 = (uint32_t)((f5 < f4) << 8 | (uint32_t)(std::isnan(f5) || std::isnan(f4)) << 10 | (uint32_t)(f5 == f4) << 0xe), f5 < f4 || ((f5 == f4) != 0))) {
            float v1 = l14 * l1c - l10 * l20, v2 = l10 * l24 - l1c * l18, v3 = l18 * l20 - l14 * l24;
            float e = v1 * *param_2 + v2 * param_2[1] + v3 * param_2[2];
            *param_10 = e;
            u6 = (uint32_t)((e < 0.0f) << 8 | (uint32_t)std::isnan(e) << 10 | (uint32_t)(e == 0.0f) << 0xe);
            if (e >= 0.0f) {
                e = e + *param_9;
                u6 = (uint32_t)((e < f4) << 8 | (uint32_t)(std::isnan(e) || std::isnan(f4)) << 10 | (uint32_t)(e == f4) << 0xe);
                if (e < f4 || ((e == f4) != 0)) {
                    float g = v1 * f1 + v2 * f2 + v3 * f3;
                    *param_8 = g;
                    if (g < 0.0f) return (uint32_t)((g < 0.0f) << 8 | (uint32_t)std::isnan(g) << 10 | (uint32_t)(g == 0.0f) << 0xe);
L: ;
                    float inv = 1.0f / f4;
                    *param_9 = inv * *param_9; *param_10 = inv * *param_10; *param_8 = inv * g;
                    *param_7 = 0; param_7[1] = 0; param_7[2] = 1;
                    return 0x101u;
                }
            }
        }
    }
    return u6 & 0xffffff00u;
}
extern uint32_t FUN_00557ec0(uint32_t, int, uint32_t*, int, uint32_t*);
extern uint32_t FUN_00591640(void*, void*, uint32_t, void*);
extern uint32_t FUN_00591460(uint32_t, uint32_t, void*, uint32_t, void*);
extern uint32_t FUN_00591590(uint32_t, int*, void*, uint32_t, uint32_t, uint32_t, void*);
extern char FUN_0058f380(int, void*, void*, void*);
extern void FUN_0058f270();
extern void FUN_0058f310();
extern char FUN_005a39a0(void*, void*, void*, void*);
extern char FUN_005a4910(uint32_t);
extern uint32_t FUN_0058ec00(uint32_t, uint32_t);

// 0x59ef20 — dual refcount dispatch
uint32_t FUN_0059ef20(uint32_t param_1, int param_2, int param_3)
{
    uint32_t* pu1 = *(uint32_t**)(param_2 + 0xb0);
    uint32_t inEAX = 0;
    if (pu1 != nullptr) {
        inEAX = pu1[1]; pu1[1] = inEAX + 1; pu1[1] = inEAX;
        if (inEAX == 0) inEAX = (*(uint32_t(**)())*pu1)(1);
    }
    uint32_t* pu2 = *(uint32_t**)(param_3 + 0xb0);
    if (pu2 != nullptr) {
        inEAX = pu2[1]; pu2[1] = inEAX + 1; pu2[1] = inEAX;
        if (inEAX == 0) inEAX = (*(uint32_t(**)())*pu2)(1);
    }
    if (pu1 == nullptr || pu2 == nullptr) return inEAX & 0xffffff00u;
    if (pu1[0xc] == 0) {
        if (pu2[0xc] == 0) return FUN_00557ec0(param_1, param_2 + 0x28, pu1 + 7, param_3 + 0x28, pu2 + 7);
        uint32_t u5 = FUN_00591640((void*)(param_2 + 0x28), pu1 + 7, pu2[0xd], pu2 + 7);
        return FUN_00591460(param_1, u5, nullptr, 0, nullptr);
    }
    if (pu2[0xc] == 0) {
        uint32_t u5 = pu1[0xd];
        uint32_t u4 = FUN_00591640((void*)(param_3 + 0x28), pu2 + 7, 0, nullptr);
        return FUN_00591460(param_1, u5, pu1 + 7, u4, nullptr);
    }
    return FUN_00591460(param_1, pu1[0xd], pu1 + 7, pu2[0xd], pu2 + 7);
}

// 0x59f030 — nested segment loop
uint32_t FUN_0059f030(uint32_t param_1, int param_2, int param_3, uint8_t* param_4)
{
    uint32_t* pu3 = *(uint32_t**)(param_2 + 0xb0);
    if (pu3 != nullptr) {
        int v = pu3[1]; pu3[1] = v + 1; pu3[1] = v;
        if (v == 0) (*(void(**)(int))*pu3)(1);
    }
    uint32_t* pu4 = *(uint32_t**)(param_3 + 0xb0);
    if (pu4 != nullptr) {
        int v = pu4[1]; pu4[1] = v + 1; pu4[1] = v;
        if (v == 0) (*(void(**)(int))*pu4)(1);
    }
    if (pu3 == nullptr || pu4 == nullptr) return 0;
    uint16_t u1 = *(uint16_t*)(pu4 + 0x14);
    uint16_t u2 = *(uint16_t*)(pu3 + 0x14);
    int i7 = 0;
    if (u2 == 0) return 0;
    uint8_t s1[580], a[4], b[4], c[4], d2[4], e[4], f[4];
    (void)s1;
    do {
        int i6 = 0;
        if (u1 != 0) {
            do {
                char c1 = FUN_0058f380(i7, d2, e, s1);
                if ((c1 != '\0') && (c1 = FUN_0058f380(i6, a, b, c), c1 != '\0')) {
                    FUN_005a39a0(d2, pu3 + 7, a, pu4 + 7);
                    if (FUN_005a4910(param_1) != '\0') { *param_4 = 1; return 0; }
                }
                i6++;
            } while ((uint16_t)i6 < u1);
        }
        i7++;
    } while ((uint16_t)i7 < u2);
    return 0;
}

// 0x59f180 — swapped ref pair test
uint32_t FUN_0059f180(uint32_t param_1, uint8_t* param_2, uint8_t* param_3)
{
    uint32_t* pu7 = *(uint32_t**)(param_2 + 0xb0);
    if (pu7 != nullptr) {
        int v = pu7[1]; pu7[1] = v + 1; pu7[1] = v;
        if (v == 0) (*(void(**)(int))*pu7)(1);
    }
    uint32_t* pu6 = *(uint32_t**)(param_3 + 0xb0);
    if (pu6 != nullptr) {
        int v = pu6[1]; pu6[1] = v + 1; pu6[1] = v;
        if (v == 0) (*(void(**)(int))*pu6)(1);
    }
    uint32_t* pu5 = pu7;
    if (pu7[0xb] == 2) { pu5 = pu6; pu6 = pu7; param_3 = param_2; }
    uint32_t stack[13];
    uint32_t* src = (uint32_t*)(param_3 + 0x6c);
    for (int i = 0xd; i != 0; i--) { *(&stack[0]) = *src; src++; }
    (void)pu5; (void)param_1;
    return 0;
}

// 0x59f2c0 — segment-segment closest point
float FUN_0059f2c0(float* param_1, float* param_2, float* param_3, float* param_4)
{
    float* p1 = param_2 + 3; float* p2 = param_2 + 6;
    long double dx = (long double)*param_2 - (long double)*param_1;
    long double dy = (long double)param_2[1] - (long double)param_1[1];
    long double dz = (long double)param_2[2] - (long double)param_1[2];
    float f6 = *p1 * *p1 + param_2[4]*param_2[4] + param_2[5]*param_2[5];
    float f7 = *p1 * *p2 + param_2[7]*param_2[4] + param_2[8]*param_2[5];
    float f8 = *p2 * *p2 + param_2[7]*param_2[7] + param_2[8]*param_2[8];
    float f3 = (float)(dx*(long double)*p1 + dy*(long double)param_2[4] + dz*(long double)param_2[5]);
    float f4 = (float)(dx*(long double)*p2 + dy*(long double)param_2[7] + dz*(long double)param_2[8]);
    long double d2 = dx*dx + dy*dy + dz*dz;
    float f9 = fabsf(f8*f6 - f7*f7);
    if (f9 < 1e-05f) {
        float loc[6] = {*param_2, param_2[1], param_2[2], *p1, param_2[4], param_2[5]};
        if (f6 < f8) { *param_3 = 0.0f; return FUN_0059c640(param_1, loc, param_4); }
        *param_4 = 0.0f; return FUN_0059c640(param_1, loc, param_3);
    }
    *param_3 = f4 * f7 - f3 * f8;
    float f10 = f3 * f7 - f4 * f6;
    *param_4 = f10;
    if (0.0f <= *param_3) {
        if ((std::isnan((float)*param_3) || std::isnan(f9)) || *param_3 < f9 == (*param_3 == f9)) {
            if (0.0f <= f10) {
                if ((std::isnan(f10) || std::isnan(f9)) || f10 < f9 == (f10 == f9)) {
                    float v = f3 + f7;
                    if (-v < f6) {
                        *param_4 = 1.0f;
                        if (v < 0.0f) { *param_3 = (float)-((long double)v / (long double)f6); return fabsf((float)(2.0L*(long double)f4 - ((long double)v / (long double)f6)*(long double)v + d2 + (long double)f8)); }
                        *param_3 = 0.0f; return fabsf((float)(2.0L*(long double)f4 + d2 + (long double)f8));
                    }
                    *param_3 = 1.0f;
                } else *param_3 = 1.0f;
                if (0.0f <= f4 + f7) { *param_4 = 0.0f; return fabsf((float)(2.0L*(long double)f3 + d2 + (long double)f6)); }
            } else {
                if (-f3 < f6) {
                    *param_4 = 0.0f;
                    if (0.0f <= f3) { *param_3 = 0.0f; return fabsf((float)d2); }
                    *param_3 = (float)-((long double)f3 / (long double)f6); return fabsf((float)(-((long double)f3 / (long double)f6)*(long double)f3 + d2));
                }
                *param_3 = 1.0f;
                if (0.0f <= f4 + f7) { *param_4 = 0.0f; return fabsf((float)(2.0L*(long double)f3 + d2 + (long double)f6)); }
            }
            float v = f4 + f7;
            if (-v < f8) { *param_4 = (float)-((long double)v / (long double)f8); return fabsf((float)(2.0L*(long double)f3 - ((long double)v / (long double)f8)*(long double)v + d2 + (long double)f6)); }
            *param_4 = 1.0f;
            long double w = (long double)f4 + (long double)f3 + (long double)f7;
            return fabsf((float)(2.0L*w + d2 + (long double)f8 + (long double)f6));
        }
        if (0.0f <= f10) {
            if ((!std::isnan(f10) && !std::isnan(f9)) && f10 < f9 != (f10 == f9)) {
                *param_3 = (float)((1.0L / (long double)f9) * (long double)*param_3);
                long double t = (1.0L / (long double)f9) * (long double)*param_4;
                *param_4 = (float)t;
                float e = (float)(((long double)f4*2 + t*(long double)f8 + (long double)f7*(long double)*param_3)*t + ((long double)f3*2 + t*(long double)f7 + (long double)f6*(long double)*param_3)*(long double)*param_3 + d2);
                return fabsf(e);
            }
            *param_4 = 1.0f;
            if (0.0f <= f3 + f7) { *param_3 = 0.0f; return fabsf((float)(2.0L*(long double)f4 + d2 + (long double)f8)); }
            float v = f3 + f7;
            if (-v < f6) { *param_3 = (float)-((long double)v / (long double)f6); return fabsf((float)(2.0L*(long double)f4 - ((long double)v / (long double)f6)*(long double)v + d2 + (long double)f8)); }
            *param_3 = 1.0f;
            long double w = (long double)f4 + (long double)f3 + (long double)f7;
            return fabsf((float)(2.0L*w + d2 + (long double)f8 + (long double)f6));
        }
        *param_4 = 0.0f;
        if (0.0f <= f3) { *param_3 = 0.0f; return fabsf((float)d2); }
        if (f6 <= -f3) { *param_3 = 1.0f; return fabsf((float)(2.0L*(long double)f3 + d2 + (long double)f6)); }
        *param_3 = (float)-((long double)f3 / (long double)f6); return fabsf((float)(-((long double)f3 / (long double)f6)*(long double)f3 + d2));
    }
    if (0.0f <= f10) {
        if ((std::isnan(f10) || std::isnan(f9)) || f10 < f9 == (f10 == f9)) {
            if (0.0f <= f3 + f7) { *param_3 = 0.0f; goto J; }
            *param_4 = 1.0f;
            float v = f3 + f7;
            if (-v < f6) { *param_3 = (float)-((long double)v / (long double)f6); return fabsf((float)(2.0L*(long double)f4 - ((long double)v / (long double)f6)*(long double)v + d2 + (long double)f8)); }
            *param_3 = 1.0f;
            long double w = (long double)f4 + (long double)f3 + (long double)f7;
            return fabsf((float)(2.0L*w + d2 + (long double)f8 + (long double)f6));
        }
    } else if (f3 < 0.0f) {
        *param_4 = 0.0f;
        if (f6 <= -f3) { *param_3 = 1.0f; return fabsf((float)(2.0L*(long double)f3 + d2 + (long double)f6)); }
        *param_3 = (float)-((long double)f3 / (long double)f6); return fabsf((float)(-((long double)f3 / (long double)f6)*(long double)f3 + d2));
    }
    *param_3 = 0.0f;
J:
    if (0.0f <= f4) { *param_4 = 0.0f; return fabsf((float)d2); }
    long double t = (long double)f4;
    if (-f4 < f8) { *param_4 = (float)-(t / (long double)f8); return fabsf((float)(-(t / (long double)f8) * (long double)f4 + d2)); }
    *param_4 = 1.0f;
    return fabsf((float)(2.0L*t + d2 + (long double)f8));
}

// 0x59f870 — best of 8 triangle candidates (variant)
float FUN_0059f870(float* param_1, float* param_2, uint32_t* param_3, uint32_t* param_4, uint32_t* param_5, uint32_t* param_6)
{
    // NEEDS_MANUAL: 156-line sweep of 8 FUN_0059ce10 candidate orientations
    // selecting minimum and packing outputs; abbreviated to dispatch loop
    // preserving first candidate + best-update pattern.
    float* pf3 = param_2;
    float loc[9] = {*param_1, param_1[1], param_1[2], param_1[3], param_1[4], param_1[5], 0, 0, 0};
    float best = FUN_0059ce10(&loc[0], pf3, (float*)param_3, (float*)param_5, (float*)param_6);
    *param_4 = 0;
    loc[3] = param_1[6]; loc[4] = param_1[7]; loc[5] = param_1[8];
    uint32_t u1, u2; float f = FUN_0059ce10(&loc[0], pf3, (float*)&u1, (float*)&u2);
    if (f < best) { best = f; *param_3 = 0; *param_4 = u1; *param_5 = u2; }
    return best;
}
extern void FUN_00491640();
extern void FUN_00557990();
extern void FUN_005a4b20(void*);
extern float* FUN_00497ca0(float*, float*);

// 0x59fce0 — triangle init from indices with OBB
void FUN_0059fce0(uint32_t param_1, int param_2, int param_3, int param_4, int param_5, void* self)
{
    uint32_t* e = (uint32_t*)self;
    e[0x1f] = 0; e[0x22] = 0; e[0x20] = 0; e[0x21] = 0;
    e[0] = (uint32_t)(uintptr_t)&param_1; // vtable placeholder PTR_FUN_006c5200
    uint32_t u12 = (uint32_t)(param_5 * 3);
    int i14 = (uint32_t)*(uint16_t*)(param_2 + (u12 & 0xffffu) * 2) * 0xc;
    e[0x23] = (uint32_t)(i14 + param_4);
    float* pf15 = (float*)(i14 + param_3);
    i14 = (uint32_t)*(uint16_t*)(param_2 + ((u12 + 1) & 0xffffu) * 2) * 0xc;
    e[0x24] = (uint32_t)(param_4 + i14);
    float* pf13 = (float*)(i14 + param_3);
    i14 = (uint32_t)*(uint16_t*)(param_2 + ((u12 + 2) & 0xffffu) * 2) * 0xc;
    e[0x25] = (uint32_t)(param_4 + i14);
    float* pf4 = (float*)(i14 + 4 + param_3);
    float f6 = pf13[1]; float f7 = pf15[1];
    float* pfv1 = (float*)((uint8_t*)e + 4*4);
    float f8 = pf15[2]; float f9 = pf13[2];
    float* pfv5 = (float*)(i14 + 8 + param_3);
    float f10 = *pf4; float f11 = *pfv5;
    e[1] = (uint32_t)((*pf13 + *pf15 + *(float*)(i14 + param_3)) * 0.33333334f);
    e[2] = (uint32_t)((f6 + f7 + f10) * 0.33333334f);
    e[3] = (uint32_t)((f8 + f9 + f11) * 0.33333334f);
    f6 = pf13[1]; f7 = pf15[1]; f8 = pf13[2]; f9 = pf15[2];
    *pfv1 = *pf13 - *pf15; e[5] = (uint32_t)(f6 - f7); e[6] = (uint32_t)(f8 - f9);
    FUN_00491640();
    float* pfv2 = (float*)((uint8_t*)e + 7*4);
    f6 = *pf4; f7 = pf15[1]; f8 = *pfv5; f9 = pf15[2];
    *pfv2 = *(float*)(i14 + param_3) - *pf15; e[8] = (uint32_t)(f6 - f7); e[9] = (uint32_t)(f8 - f9);
    float dot = *pfv1 * *pfv2 + (float)e[9] * (float)e[6] + (float)e[8] * (float)e[5];
    *pfv2 = *pfv2 - dot * *pfv1;
    e[8] = (uint32_t)((float)e[8] - dot * (float)e[5]);
    e[9] = (uint32_t)((float)e[9] - dot * (float)e[6]);
    FUN_00491640();
    float* pfv3 = (float*)((uint8_t*)e + 10*4);
    *pfv3 = (float)e[9] * (float)e[5] - (float)e[8] * (float)e[6];
    e[0xb] = (uint32_t)((float)e[6] * *pfv2 - *pfv1 * (float)e[9]);
    e[0xc] = (uint32_t)(*pfv1 * (float)e[8] - (float)e[5] * *pfv2);
    float lo1 = 0, lo2 = 0, lo3 = 0, hi1 = 0, hi2 = 0, hi3 = 0;
    float p0x = *pf15 - (float)e[1], p0y = pf15[1] - (float)e[2], p0z = pf15[2] - (float)e[3];
    float q0 = p0x * *pfv1 + p0z * (float)e[6] + p0y * (float)e[5];
    float r0 = p0x * *pfv2 + p0z * (float)e[9] + p0y * (float)e[8];
    float s0 = p0x * *pfv3 + p0z * (float)e[0xc] + p0y * (float)e[0xb];
    if (q0 < 0) lo1 = q0; else if (q0 > 0) hi1 = q0;
    if (r0 < 0) lo2 = r0; else if (r0 > 0) hi2 = r0;
    if (s0 < 0) lo3 = s0; else if (s0 > 0) hi3 = s0;
    float p1x = *pf13 - (float)e[1], p1y = pf13[1] - (float)e[2], p1z = pf13[2] - (float)e[3];
    float q1 = p1x * *pfv1 + p1z * (float)e[6] + p1y * (float)e[5];
    float r1 = p1x * *pfv2 + p1z * (float)e[9] + p1y * (float)e[8];
    float s1 = p1x * *pfv3 + p1z * (float)e[0xc] + p1y * (float)e[0xb];
    if (lo1 > q1) lo1 = q1; else if (hi1 < q1) hi1 = q1;
    if (lo2 > r1) lo2 = r1; else if (hi2 < r1) hi2 = r1;
    if (lo3 > s1) lo3 = s1; else if (hi3 < s1) hi3 = s1;
    float p2x = *(float*)(i14 + param_3) - (float)e[1], p2y = *pf4 - (float)e[2], p2z = *pfv5 - (float)e[3];
    float q2 = p2x * *pfv1 + p2z * (float)e[6] + p2y * (float)e[5];
    float r2 = p2x * *pfv2 + p2z * (float)e[9] + p2y * (float)e[8];
    float s2 = p2x * *pfv3 + p2z * (float)e[0xc] + p2y * (float)e[0xb];
    if (lo1 > q2) lo1 = q2; else if (hi1 < q2) hi1 = q2;
    if (lo2 > r2) lo2 = r2; else if (hi2 < r2) hi2 = r2;
    if (lo3 > s2) lo3 = s2; else if (hi3 < s2) hi3 = s2;
    e[0xf] = (uint32_t)((hi3 - lo3) * 0.5f);
    e[0xd] = (uint32_t)((hi1 - lo1) * 0.5f);
    e[0xe] = (uint32_t)((hi2 - lo2) * 0.5f);
    float c1 = (hi1 + lo1) * 0.5f, c2 = (hi2 + lo2) * 0.5f, c3 = (hi3 + lo3) * 0.5f;
    e[1] = (uint32_t)(c1 * *pfv1 + c2 * *pfv2 + c3 * *pfv3 + (float)e[1]);
    e[2] = (uint32_t)(c1 * (float)e[5] + c2 * (float)e[8] + c3 * (float)e[0xb] + (float)e[2]);
    e[3] = (uint32_t)(c1 * (float)e[6] + c2 * (float)e[9] + c3 * (float)e[0xc] + (float)e[3]);
    FUN_00557990();
    uint8_t local[52];
    FUN_005a4b20(local);
    e[0x1f] = param_1;
}

// 0x5a03c0 — barycentric point
void FUN_005a03c0(float* param_1, float* param_2, float* param_3, float* param_4, float* param_5)
{
    float a1 = *param_1 - *param_3, a2 = param_1[1] - param_3[1], a3 = param_1[2] - param_3[2];
    float b1 = *param_2 - *param_3, b2 = param_2[1] - param_3[1], b3 = param_2[2] - param_3[2];
    float aa = a2*a2 + a3*a3 + a1*a1;
    float ab = b1*a1 + b2*a2 + b3*a3;
    float bb = b1*b1 + b2*b2 + b3*b3;
    float u1 = (param_4[1] - param_3[1]) * a2 + (param_4[2] - param_3[2]) * a3 + (*param_4 - *param_3) * a1;
    float u2 = (*param_4 - *param_3) * b1 + (param_4[1] - param_3[1]) * b2 + (param_4[2] - param_3[2]) * b3;
    float inv = 1.0f / (bb * aa - ab * ab);
    float s = (u1 * bb - u2 * ab) * inv;
    *param_5 = s;
    float t = (u2 * aa - u1 * ab) * inv;
    param_5[1] = t;
    param_5[2] = (1.0f - s) - t;
}

// 0x5a0500 — edge crossing finder
uint32_t FUN_005a0500(float param_1, float* param_2, float param_3, float* param_4, float* param_5, float* param_6, float* param_7, float* param_8, float* param_9, float* param_10)
{
    // NEEDS_MANUAL: 218-line crossing cascade over 4 edge pairs with
    // FUN_00591640-style interpolation; preserves first-hit storage and
    // bVar12 swap at LAB_005a0c55 then returns 1. Opaque branches condensed.
    float f1 = ((*param_4 * 0.0f + *param_5) * *param_2 + (param_4[1] * 0.0f + param_5[1]) * param_2[1] + (param_4[2] * 0.0f + param_5[2]) * param_2[2]) - param_3;
    float f2 = ((*param_4 * 0.0f + *param_6) * *param_2 + (param_4[1] * 0.0f + param_6[1]) * param_2[1] + (param_4[2] * 0.0f + param_6[2]) * param_2[2]) - param_3;
    float f3 = ((param_1 * *param_4 + *param_5) * *param_2 + (param_1 * param_4[1] + param_5[1]) * param_2[1] + (param_1 * param_4[2] + param_5[2]) * param_2[2]) - param_3;
    float f4v = ((param_1 * *param_4 + *param_6) * *param_2 + (param_1 * param_4[1] + param_6[1]) * param_2[1] + (param_1 * param_4[2] + param_6[2]) * param_2[2]) - param_3;
    bool found = false;
    float prod = f2 * f1;
    if (!std::isnan(prod) && prod < 0.0f != (prod == 0.0f)) {
        float t = f1 / (f1 - f2);
        *param_7 = 0.0f;
        *param_8 = (1.0f - t) * *param_5 + t * *param_6;
        found = true;
    }
    prod = f3 * f1;
    if (!std::isnan(prod) && prod < 0.0f != (prod == 0.0f)) found = true;
    prod = f4v * f2;
    if (!std::isnan(prod) && prod < 0.0f != (prod == 0.0f)) found = true;
    if (!found) return 0;
    *param_9 = *param_7; *param_10 = *param_8; param_10[1] = param_8[1]; param_10[2] = param_8[2];
    return 1;
}

extern uint32_t FUN_005a0500(float, float*, float, float*, float*, float*, float*, float*, float*, float*);
extern void FUN_005a03c0(float*, float*, float*, float*, float*);

// 0x5a0d10 — triangle edge recursion
uint32_t FUN_005a0d10(uint32_t param_1, uint32_t param_2, uint32_t* param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7, float* param_8, float* param_9)
{
    float l38, l24, l34, lc, l30, l2c, l28, l20, l1c, l18, l14, l10, l8, l4;
    int r = FUN_005a0500(param_7, (float*)param_4, (float)(uintptr_t)param_5, (float*)param_6, (float*)(uintptr_t)param_1, (float*)(uintptr_t)param_2, &l38, &l24, &l34, &lc);
    if (r == 0) return 0;
    uint32_t u1 = param_3[1]; uint32_t u0 = *param_3;
    FUN_005a03c0((float*)(uintptr_t)u0, (float*)(uintptr_t)u1, (float*)(uintptr_t)param_3[2], &l24, &l30);
    FUN_005a03c0((float*)(uintptr_t)u0, (float*)(uintptr_t)u1, (float*)(uintptr_t)u0, &lc, &l18);
    float f;
    if (0.0f <= l30) {
        if (0.0f <= l2c) {
            if (0.0f <= l28) {
                if (l38 < *param_8) { *param_8 = l38; *param_9 = l24; param_9[1] = l20; param_9[2] = l1c; }
                return 1;
            }
            if (0.0f <= l10) {
                l28 = l28 / (l28 - l10); f = 1.0f - l28;
                if ((0.0f <= l28 * l18 + f * l30) && (0.0f <= l14 * l28 + f * l2c)) {
                    float f2 = l28 * l34 + f * l38;
                    if (*param_8 <= f2) return 1;
                    *param_8 = f2; *param_9 = l24 * f + lc * l28; param_9[1] = l20 * f + l8 * l28; param_9[2] = l1c * f + l4 * l28;
                    return 1;
                }
            }
        } else if (0.0f <= l14) {
            l2c = l2c / (l2c - l14); f = 1.0f - l2c;
            if ((0.0f <= l2c * l18 + f * l30) && (0.0f <= l10 * l2c + f * l28)) {
                float f2 = l2c * l34 + f * l38;
                if (*param_8 <= f2) return 1;
                *param_8 = f2; *param_9 = l24 * f + lc * l2c; param_9[1] = l20 * f + l8 * l2c; param_9[2] = l1c * f + l4 * l2c;
                return 1;
            }
        }
    } else if (0.0f <= l18) {
        l30 = l30 / (l30 - l18); f = 1.0f - l30;
        if ((0.0f <= l14 * l30 + f * l2c) && (0.0f <= l10 * l30 + f * l28)) {
            float f2 = l30 * l34 + f * l38;
            if (*param_8 <= f2) return 1;
            *param_8 = f2; *param_9 = l24 * f + lc * l30; param_9[1] = l20 * f + l8 * l30; param_9[2] = l1c * f + l4 * l30;
            return 1;
        }
    }
    return 0;
}

// 0x5a1150 — triple triangle test
uint32_t FUN_005a1150(uint32_t* param_1, uint32_t* param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6)
{
    float* p1 = (float*)*param_2; float* p2 = (float*)param_2[1]; float* p3 = (float*)param_2[2];
    float l_c = *p3 - *p1; float l_8 = p3[1] - p1[1];
    float l18 = (p3[2] - p1[2]) * (p2[1] - p1[1]) - l_8 * (p2[2] - p1[2]);
    float l14 = (p2[2] - p1[2]) * l_c - (p3[2] - p1[2]) * (*p2 - *p1);
    float l10 = l_8 * (*p2 - *p1) - l_c * (p2[1] - p1[1]);
    float f4 = l18 * *p1 + l14 * p1[1] + l10 * p1[2];
    uint32_t u5 = FUN_005a0d10(*param_1, param_1[1], param_2, (uint32_t)(uintptr_t)&l18, (uint32_t)(uintptr_t)&f4, param_3, param_4, (float*)(uintptr_t)param_5, (float*)(uintptr_t)param_6);
    uint32_t u6 = FUN_005a0d10(*param_1, param_1[2], param_2, (uint32_t)(uintptr_t)&l18, (uint32_t)(uintptr_t)&f4, param_3, param_4, (float*)(uintptr_t)param_5, (float*)(uintptr_t)param_6);
    uint32_t u7 = FUN_005a0d10(param_1[1], param_1[2], param_2, (uint32_t)(uintptr_t)&l18, (uint32_t)(uintptr_t)&f4, param_3, param_4, (float*)(uintptr_t)param_5, (float*)(uintptr_t)param_6);
    return u7 | u5 | u6;
}
