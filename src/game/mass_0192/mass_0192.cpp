#include <cstdint>
#include <cstddef>
#include <cmath>
#include <windows.h>

typedef long double float10;

extern float10 FUN_0059f2c0(uint32_t param_1, const void* param_2, const void* param_3, void* param_4);

// 0x598ac0 — observed shape
float10 FUN_00598ac0(uint32_t param_1, const uint32_t* param_2, uint32_t* param_3, uint32_t* param_4, uint32_t* param_5) {
    uint32_t local_2c;
    float local_28;
    uint32_t local_24;
    uint32_t local_20;
    uint32_t local_1c;
    uint32_t local_18;
    uint32_t local_14;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;
    uint32_t local_4;
    local_24 = param_2[0];
    local_20 = param_2[1];
    local_1c = param_2[2];
    local_18 = param_2[3];
    local_14 = param_2[4];
    local_10 = param_2[5];
    local_c = param_2[9];
    local_8 = param_2[10];
    local_4 = param_2[0xb];
    local_28 = 3.4028235e+38f;
    float10 fVar1 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_2c);
    if (fVar1 < (float10)3.4028235e+38f) {
        *param_3 = (uint32_t)(uintptr_t)param_2;
        *param_4 = 0;
        *param_5 = local_2c;
        return fVar1;
    }
    return (float10)local_28;
}

// 0x598b70 — observed shape
float10 FUN_00598b70(uint32_t param_1, float* param_2, uint32_t* param_3, uint32_t* param_4, uint32_t* param_5) {
    float* pfVar1;
    float* pfVar2;
    float* pfVar3;
    float10 fVar4;
    uint32_t local_38;
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
    float local_4;
    pfVar3 = param_2;
    local_24 = *param_2;
    local_20 = param_2[1];
    local_1c = param_2[2];
    pfVar1 = param_2 + 3;
    local_18 = *pfVar1;
    local_14 = param_2[4];
    local_10 = param_2[5];
    pfVar2 = param_2 + 9;
    local_c = *pfVar2;
    local_8 = param_2[10];
    local_4 = param_2[0xb];
    local_34 = 3.4028235e+38f;
    fVar4 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_38);
    if (fVar4 < (float10)3.4028235e+38f) {
        local_34 = (float)fVar4;
        *param_3 = (uint32_t)(uintptr_t)param_2;
        *param_4 = 0;
        *param_5 = local_38;
    }
    local_30 = *pfVar3 + *pfVar2;
    local_2c = pfVar3[10] + pfVar3[1];
    local_18 = *pfVar1;
    local_28 = pfVar3[0xb] + pfVar3[2];
    local_14 = pfVar3[4];
    local_c = pfVar3[6];
    local_8 = pfVar3[7];
    local_10 = pfVar3[5];
    local_4 = pfVar3[8];
    local_24 = local_30;
    local_20 = local_2c;
    local_1c = local_28;
    fVar4 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_38);
    if ((float10)local_34 <= fVar4) {
        return (float10)local_34;
    }
    *param_3 = (uint32_t)(uintptr_t)param_2;
    *param_4 = local_38;
    *param_5 = 0x3f800000;
    return fVar4;
}

// 0x598cd0 — observed shape
float10 FUN_00598cd0(uint32_t param_1, float* param_2, uint32_t* param_3, uint32_t* param_4, uint32_t* param_5) {
    float* pfVar1;
    float* pfVar2;
    float* pfVar3;
    float* pfVar4;
    float10 fVar5;
    uint32_t local_38;
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
    float local_4;
    pfVar4 = param_2;
    local_30 = *param_2 + param_2[3];
    pfVar1 = param_2 + 3;
    pfVar2 = param_2 + 6;
    pfVar3 = param_2 + 9;
    local_2c = param_2[4] + param_2[1];
    local_34 = 3.4028235e+38f;
    local_28 = param_2[5] + param_2[2];
    local_18 = *pfVar2;
    local_14 = param_2[7];
    local_10 = param_2[8];
    local_c = *pfVar3;
    local_8 = param_2[10];
    local_4 = param_2[0xb];
    local_24 = local_30;
    local_20 = local_2c;
    local_1c = local_28;
    fVar5 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_38);
    if (fVar5 < (float10)3.4028235e+38f) {
        local_34 = (float)fVar5;
        *param_3 = 0x3f800000;
        *param_4 = (uint32_t)(uintptr_t)param_2;
        *param_5 = local_38;
    }
    local_24 = *pfVar4;
    local_20 = pfVar4[1];
    local_1c = pfVar4[2];
    local_18 = *pfVar1;
    local_14 = pfVar4[4];
    local_10 = pfVar4[5];
    local_c = *pfVar3;
    local_8 = pfVar4[10];
    local_4 = pfVar4[0xb];
    fVar5 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_38);
    if (fVar5 < (float10)local_34) {
        local_34 = (float)fVar5;
        *param_3 = (uint32_t)(uintptr_t)param_2;
        *param_4 = 0;
        *param_5 = local_38;
    }
    local_24 = *pfVar4;
    local_20 = pfVar4[1];
    local_1c = pfVar4[2];
    local_18 = *pfVar1;
    local_14 = pfVar4[4];
    local_10 = pfVar4[5];
    local_c = *pfVar2;
    local_8 = pfVar4[7];
    local_4 = pfVar4[8];
    fVar5 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_38);
    if ((float10)local_34 <= fVar5) {
        return (float10)local_34;
    }
    *param_3 = (uint32_t)(uintptr_t)param_2;
    *param_4 = local_38;
    *param_5 = 0;
    return fVar5;
}

// 0x598ec0 — observed shape
float10 FUN_00598ec0(uint32_t param_1, float* param_2, uint32_t* param_3, uint32_t* param_4, uint32_t* param_5) {
    float* pfVar1;
    float* pfVar2;
    float* pfVar3;
    float10 fVar4;
    uint32_t local_38;
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
    float local_4;
    pfVar3 = param_2;
    local_30 = *param_2 + param_2[3];
    pfVar1 = param_2 + 3;
    pfVar2 = param_2 + 9;
    local_2c = param_2[4] + param_2[1];
    local_34 = 3.4028235e+38f;
    local_28 = param_2[5] + param_2[2];
    local_18 = param_2[6];
    local_14 = param_2[7];
    local_10 = param_2[8];
    local_c = *pfVar2;
    local_8 = param_2[10];
    local_4 = param_2[0xb];
    local_24 = local_30;
    local_20 = local_2c;
    local_1c = local_28;
    fVar4 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_38);
    if (fVar4 < (float10)3.4028235e+38f) {
        local_34 = (float)fVar4;
        *param_3 = 0x3f800000;
        *param_4 = (uint32_t)(uintptr_t)param_2;
        *param_5 = local_38;
    }
    local_24 = *pfVar3;
    local_20 = pfVar3[1];
    local_1c = pfVar3[2];
    local_18 = *pfVar1;
    local_14 = pfVar3[4];
    local_10 = pfVar3[5];
    local_c = *pfVar2;
    local_8 = pfVar3[10];
    local_4 = pfVar3[0xb];
    fVar4 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_38);
    if ((float10)local_34 <= fVar4) {
        return (float10)local_34;
    }
    *param_3 = (uint32_t)(uintptr_t)param_2;
    *param_4 = 0;
    *param_5 = local_38;
    return fVar4;
}

// 0x599020 — observed shape
float10 FUN_00599020(uint32_t param_1, float* param_2, uint32_t* param_3, uint32_t* param_4, uint32_t* param_5) {
    float* pfVar1;
    float* pfVar2;
    float* pfVar3;
    float* pfVar4;
    float10 fVar5;
    uint32_t local_38;
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
    float local_4;
    pfVar4 = param_2;
    local_30 = *param_2 + param_2[3];
    pfVar1 = param_2 + 3;
    pfVar2 = param_2 + 6;
    pfVar3 = param_2 + 9;
    local_2c = param_2[4] + param_2[1];
    local_34 = 3.4028235e+38f;
    local_28 = param_2[5] + param_2[2];
    local_18 = *pfVar2;
    local_14 = param_2[7];
    local_10 = param_2[8];
    local_c = *pfVar3;
    local_8 = param_2[10];
    local_4 = param_2[0xb];
    local_24 = local_30;
    local_20 = local_2c;
    local_1c = local_28;
    fVar5 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_38);
    if (fVar5 < (float10)3.4028235e+38f) {
        local_34 = (float)fVar5;
        *param_3 = 0x3f800000;
        *param_4 = (uint32_t)(uintptr_t)param_2;
        *param_5 = local_38;
    }
    local_24 = *pfVar4;
    local_20 = pfVar4[1];
    local_1c = pfVar4[2];
    local_18 = *pfVar1;
    local_14 = pfVar4[4];
    local_10 = pfVar4[5];
    local_c = *pfVar3;
    local_8 = pfVar4[10];
    local_4 = pfVar4[0xb];
    fVar5 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_38);
    if (fVar5 < (float10)local_34) {
        local_34 = (float)fVar5;
        *param_3 = (uint32_t)(uintptr_t)param_2;
        *param_4 = 0;
        *param_5 = local_38;
    }
    local_30 = *pfVar4 + *pfVar3;
    local_2c = pfVar4[10] + pfVar4[1];
    local_18 = *pfVar1;
    local_c = *pfVar2;
    local_28 = pfVar4[0xb] + pfVar4[2];
    local_14 = pfVar4[4];
    local_8 = pfVar4[7];
    local_10 = pfVar4[5];
    local_4 = pfVar4[8];
    local_24 = local_30;
    local_20 = local_2c;
    local_1c = local_28;
    fVar5 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_38);
    if ((float10)local_34 <= fVar5) {
        return (float10)local_34;
    }
    *param_3 = (uint32_t)(uintptr_t)param_2;
    *param_4 = local_38;
    *param_5 = 0x3f800000;
    return fVar5;
}

typedef float10 (*PointPlaneEvalFn)(float*, float*, float*, float*, float*);

extern float10 FUN_0059ce10(float* param_1, const void* param_2, const void* param_3, void* param_4, void* param_5);
extern float10 FUN_0059f870(uint32_t param_1, const void* param_2, const void* param_3, void* param_4, void* param_5, void* param_6);
extern char FUN_00557a60(uint32_t* param_1);
extern int FUN_00533c78(uint32_t param_1);
extern uint32_t FUN_0059fce0(void* self, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5);
extern uint32_t FUN_005a3150(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5);
extern void FUN_00557990(void);
extern void FUN_00535110(int param_1);
extern void FUN_00535150(int param_1);
extern void* PTR_FUN_006c51d8;
extern void* PTR_FUN_00717bf0[];
extern uint32_t DAT_00727430;
extern uint32_t DAT_00727434;
extern uint32_t DAT_00727438;

// 0x599230 — observed shape
float10 FUN_00599230(float* param_1, float* param_2, float* param_3, float* param_4, float* param_5) {
    float* pfVar1;
    float* pfVar2;
    float* pfVar3;
    float fVar4;
    float fVar5;
    float fVar6;
    float fVar7;
    float fVar8;
    float fVar9;
    float fVar10;
    float fVar11;
    float fVar12;
    float fVar13;
    float fVar14;
    float fVar15;
    float fVar16;
    int iVar17;
    int iVar18;
    int iVar19;
    float10 fVar20;
    float local_24;
    float local_20;
    float local_1c;
    float local_18;
    float local_14;
    float local_10;
    float local_c;
    float local_8;
    float local_4;
    fVar5 = *param_1 - *param_2;
    pfVar1 = param_2 + 3;
    pfVar2 = param_2 + 6;
    fVar4 = param_1[1] - param_2[1];
    pfVar3 = param_2 + 9;
    fVar6 = param_1[2] - param_2[2];
    fVar10 = *pfVar1 * *pfVar1 + param_2[4] * param_2[4] + param_2[5] * param_2[5];
    fVar11 = *pfVar2 * *pfVar1 + param_2[7] * param_2[4] + param_2[8] * param_2[5];
    fVar12 = *pfVar3 * *pfVar1 + param_2[10] * param_2[4] + param_2[0xb] * param_2[5];
    fVar13 = *pfVar2 * *pfVar2 + param_2[7] * param_2[7] + param_2[8] * param_2[8];
    fVar7 = *pfVar2 * *pfVar3 + param_2[10] * param_2[7] + param_2[0xb] * param_2[8];
    fVar14 = *pfVar3 * *pfVar3 + param_2[10] * param_2[10] + param_2[0xb] * param_2[0xb];
    fVar9 = fVar5 * *pfVar1 + fVar4 * param_2[4] + fVar6 * param_2[5];
    fVar8 = fVar5 * *pfVar2 + fVar4 * param_2[7] + fVar6 * param_2[8];
    fVar5 = fVar5 * *pfVar3 + fVar4 * param_2[10] + fVar6 * param_2[0xb];
    fVar15 = fVar14 * fVar13 - fVar7 * fVar7;
    fVar16 = fVar7 * fVar12 - fVar14 * fVar11;
    fVar4 = fVar7 * fVar11 - fVar13 * fVar12;
    fVar6 = std::fabs(fVar15 * fVar10 + fVar16 * fVar11 + fVar12 * fVar4);
    if (fVar6 < 1e-05f) {
        local_24 = *param_2;
        local_20 = param_2[1];
        fVar15 = std::fabs(fVar15);
        local_1c = param_2[2];
        if (std::isnan(fVar15) || (fVar15 < 1e-05f) == (fVar15 == 1e-05f)) {
            local_18 = *pfVar1;
            local_14 = param_2[4];
            local_10 = param_2[5];
            local_c = *pfVar2;
            local_8 = param_2[7];
            local_4 = param_2[8];
            *param_5 = 0.0f;
            fVar20 = FUN_0059f2c0((uint32_t)(uintptr_t)param_1, &local_24, param_3, param_4);
            return fVar20;
        }
        local_14 = param_2[7];
        local_18 = *pfVar2;
        local_10 = param_2[8];
        local_c = *pfVar3;
        local_8 = param_2[10];
        local_4 = param_2[0xb];
        *param_3 = 0.0f;
        fVar20 = FUN_0059f2c0((uint32_t)(uintptr_t)param_1, &local_24, param_4, param_5);
        return fVar20;
    }
    fVar7 = fVar12 * fVar11 - fVar7 * fVar10;
    *param_3 = fVar15 * fVar9 + fVar16 * fVar8 + fVar4 * fVar5;
    *param_4 = fVar16 * fVar9 + fVar7 * fVar5 + (fVar14 * fVar10 - fVar12 * fVar12) * fVar8;
    fVar5 = fVar4 * fVar9 + fVar7 * fVar8 + (fVar13 * fVar10 - fVar11 * fVar11) * fVar5;
    *param_5 = fVar5;
    if (0.0f <= *param_3) {
        fVar4 = *param_3;
        iVar17 = 1;
        if ((std::isnan(fVar4) || std::isnan(fVar6)) || (fVar4 < fVar6) == (fVar4 == fVar6)) {
            iVar17 = 2;
        }
    } else {
        iVar17 = 0;
    }
    if (0.0f <= *param_4) {
        fVar4 = *param_4;
        iVar19 = 1;
        if ((std::isnan(fVar4) || std::isnan(fVar6)) || (fVar4 < fVar6) == (fVar4 == fVar6)) {
            iVar19 = 2;
        }
    } else {
        iVar19 = 0;
    }
    if (0.0f <= fVar5) {
        iVar18 = 1;
        if ((std::isnan(fVar5) || std::isnan(fVar6)) || (fVar5 < fVar6) == (fVar5 == fVar6)) {
            iVar18 = 2;
        }
    } else {
        iVar18 = 0;
    }
    if (((iVar17 == 1) && (iVar19 == 1)) && (iVar18 == 1)) {
        fVar6 = 1.0f / fVar6;
        *param_3 = fVar6 * *param_3;
        *param_4 = fVar6 * *param_4;
        *param_5 = fVar6 * *param_5;
        return (float10)0.0f;
    }
    fVar20 = ((PointPlaneEvalFn)(&PTR_FUN_00717bf0)[iVar18 + (iVar19 + iVar17 * 3) * 3])(param_1, param_2, param_3, param_4, param_5);
    return fVar20;
}

// 0x5995d0 — observed shape
float10 FUN_005995d0(uint32_t param_1, uint32_t* param_2, uint32_t* param_3, uint32_t* param_4, uint32_t* param_5) {
    float10 fVar1;
    uint32_t local_2c;
    float local_28;
    uint32_t local_24;
    uint32_t local_20;
    uint32_t local_1c;
    uint32_t local_18;
    uint32_t local_14;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;
    uint32_t local_4;
    local_24 = *param_2;
    local_20 = param_2[1];
    local_1c = param_2[2];
    local_18 = param_2[3];
    local_14 = param_2[4];
    local_10 = param_2[5];
    local_c = param_2[6];
    local_8 = param_2[7];
    local_4 = param_2[8];
    local_28 = 3.4028235e+38f;
    fVar1 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_2c);
    if (fVar1 < (float10)3.4028235e+38f) {
        *param_3 = (uint32_t)(uintptr_t)param_2;
        *param_4 = local_2c;
        *param_5 = 0;
        return fVar1;
    }
    return (float10)local_28;
}

// 0x599680 — observed shape
float10 FUN_00599680(float* param_1, float* param_2, float* param_3, float* param_4, float* param_5, float* param_6) {
    float* pfVar1;
    float* pfVar2;
    float fVar3;
    float fVar4;
    float fVar5;
    float fVar6;
    float fVar7;
    float fVar8;
    float fVar9;
    float fVar10;
    float fVar11;
    float fVar12;
    float fVar13;
    float fVar14;
    float fVar15;
    float* pfVar16;
    float10 fVar17;
    float local_68;
    float local_64;
    float local_60;
    float local_5c;
    float local_3c;
    float local_38;
    float local_34;
    float local_30;
    float local_24;
    float local_20;
    float local_1c;
    float local_18;
    float local_14;
    float local_10;
    float local_c;
    float local_8;
    float local_4;
    local_24 = *param_2;
    local_20 = param_2[1];
    local_1c = param_2[2];
    pfVar1 = param_2 + 3;
    local_18 = *pfVar1;
    local_14 = param_2[4];
    local_10 = param_2[5];
    pfVar2 = param_2 + 6;
    local_c = *pfVar2;
    local_8 = param_2[7];
    local_4 = param_2[8];
    local_5c = 3.4028235e+38f;
    fVar17 = FUN_0059ce10(param_1, &local_24, &local_68, &local_64, &local_60);
    if (fVar17 < (float10)3.4028235e+38f) {
        local_5c = (float)fVar17;
        *param_3 = local_68;
        *param_4 = local_64;
        *param_5 = local_60;
        *param_6 = 0.0f;
        if (fVar17 == (float10)0.0f) {
            return (float10)0.0f;
        }
    }
    pfVar16 = param_2 + 9;
    local_c = *pfVar16;
    local_8 = param_2[10];
    local_4 = param_2[0xb];
    fVar17 = FUN_0059ce10(param_1, &local_24, &local_68, &local_64, &local_60);
    if (fVar17 < (float10)local_5c) {
        local_5c = (float)fVar17;
        *param_3 = local_68;
        *param_4 = local_64;
        *param_5 = 0.0f;
        *param_6 = local_60;
        if (fVar17 == (float10)0.0f) {
            return (float10)0.0f;
        }
    }
    local_18 = *pfVar2;
    local_14 = param_2[7];
    local_10 = param_2[8];
    fVar17 = FUN_0059ce10(param_1, &local_24, &local_68, &local_64, &local_60);
    if (fVar17 < (float10)local_5c) {
        local_5c = (float)fVar17;
        *param_3 = local_68;
        *param_4 = 0.0f;
        *param_5 = local_64;
        *param_6 = local_60;
        if (fVar17 == (float10)0.0f) {
            return (float10)0.0f;
        }
    }
    local_30 = *pfVar2 + *pfVar1 + *pfVar16;
    local_24 = local_30 + local_24;
    local_20 = local_20 + param_2[7] + param_2[4] + param_2[10];
    local_1c = local_1c + param_2[8] + param_2[5] + param_2[0xb];
    local_18 = -*pfVar1;
    local_14 = -param_2[4];
    local_10 = -param_2[5];
    local_3c = -*pfVar2;
    local_38 = -param_2[7];
    local_34 = -param_2[8];
    local_c = local_3c;
    local_8 = local_38;
    local_4 = local_34;
    fVar17 = FUN_0059ce10(param_1, &local_24, &local_68, &local_64, &local_60);
    if (fVar17 < (float10)local_5c) {
        local_5c = (float)fVar17;
        *param_3 = local_68;
        *param_4 = 1.0f - local_64;
        *param_5 = 1.0f - local_60;
        *param_6 = 1.0f;
        if (fVar17 == (float10)0.0f) {
            return (float10)0.0f;
        }
    }
    local_3c = -*pfVar16;
    local_38 = -param_2[10];
    local_34 = -param_2[0xb];
    local_c = local_3c;
    local_8 = local_38;
    local_4 = local_34;
    fVar17 = FUN_0059ce10(param_1, &local_24, &local_68, &local_64, &local_60);
    if (fVar17 < (float10)local_5c) {
        local_5c = (float)fVar17;
        *param_3 = local_68;
        *param_4 = 1.0f - local_64;
        *param_5 = 1.0f;
        *param_6 = 1.0f - local_60;
        if (fVar17 == (float10)0.0f) {
            return (float10)0.0f;
        }
    }
    local_3c = -*pfVar2;
    local_38 = -param_2[7];
    local_34 = -param_2[8];
    local_18 = local_3c;
    local_14 = local_38;
    local_10 = local_34;
    fVar17 = FUN_0059ce10(param_1, &local_24, &local_68, &local_64, &local_60);
    fVar3 = (float)fVar17;
    fVar17 = (float10)local_5c;
    if ((float10)fVar3 < fVar17) {
        fVar17 = (float10)fVar3;
        *param_3 = local_68;
        *param_4 = 1.0f;
        *param_5 = 1.0f - local_64;
        *param_6 = 1.0f - local_60;
        if (fVar3 == 0.0f) goto LAB_00599db7;
    }
    fVar3 = *param_3;
    fVar4 = (fVar3 * param_1[3] + *param_1) - *param_2;
    fVar5 = (fVar3 * param_1[4] + param_1[1]) - param_2[1];
    fVar3 = (fVar3 * param_1[5] + param_1[2]) - param_2[2];
    fVar8 = *pfVar1 * *pfVar1 + param_2[4] * param_2[4] + param_2[5] * param_2[5];
    fVar9 = *pfVar2 * *pfVar1 + param_2[7] * param_2[4] + param_2[8] * param_2[5];
    fVar10 = *pfVar1 * *pfVar16 + param_2[10] * param_2[4] + param_2[0xb] * param_2[5];
    fVar11 = *pfVar2 * *pfVar2 + param_2[7] * param_2[7] + param_2[8] * param_2[8];
    fVar12 = *pfVar16 * *pfVar2 + param_2[10] * param_2[7] + param_2[0xb] * param_2[8];
    fVar13 = *pfVar16 * *pfVar16 + param_2[10] * param_2[10] + param_2[0xb] * param_2[0xb];
    fVar7 = fVar4 * *pfVar1 + fVar5 * param_2[4] + fVar3 * param_2[5];
    fVar6 = fVar4 * *pfVar2 + fVar5 * param_2[7] + fVar3 * param_2[8];
    fVar3 = fVar4 * *pfVar16 + fVar5 * param_2[10] + fVar3 * param_2[0xb];
    fVar4 = fVar13 * fVar11 - fVar12 * fVar12;
    fVar14 = fVar12 * fVar10 - fVar13 * fVar9;
    fVar15 = fVar12 * fVar9 - fVar11 * fVar10;
    fVar12 = fVar10 * fVar9 - fVar12 * fVar8;
    fVar5 = fVar4 * fVar8 + fVar14 * fVar9 + fVar15 * fVar10;
    fVar4 = fVar4 * fVar7 + fVar14 * fVar6 + fVar15 * fVar3;
    if ((((fVar4 < 0.0f) || (fVar5 < fVar4)) ||
         (fVar4 = fVar14 * fVar7 + fVar12 * fVar3 + (fVar13 * fVar8 - fVar10 * fVar10) * fVar6, fVar4 < 0.0f)) ||
        (((fVar5 < fVar4 ||
           (fVar3 = fVar15 * fVar7 + fVar12 * fVar6 + (fVar11 * fVar8 - fVar9 * fVar9) * fVar3, fVar3 < 0.0f)) ||
          (fVar5 < fVar3)))) {
        return fVar17;
    }
LAB_00599db7:
    return (float10)0.0f;
}

// 0x599de0 — observed shape
void FUN_00599de0(const float* self, float* param_1, float param_2) {
    float fVar1;
    float fVar2;
    float fVar3;
    float fVar4;
    fVar1 = self[4];
    fVar2 = self[5];
    fVar3 = self[2];
    fVar4 = self[1];
    *param_1 = param_2 * self[3] + *self;
    param_1[1] = param_2 * fVar1 + fVar4;
    param_1[2] = param_2 * fVar2 + fVar3;
}

// 0x599e20 — observed shape
uint32_t FUN_00599e20(const float* self, const float* param_1) {
    if ((((self[0] == param_1[0]) && (self[1] == param_1[1])) && (self[2] == param_1[2])) &&
        (((self[3] == param_1[3] && (self[4] == param_1[4])) && (self[5] == param_1[5])))) {
        return 1;
    }
    return 0;
}

// 0x599e90 — observed shape
void FUN_00599e90(uint32_t* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4) {
    self[0] = param_1;
    self[1] = param_2;
    self[2] = param_3;
    self[6] = param_4;
    self[5] = 0x3727c5ac;
}

// 0x599ec0 — observed shape
uint32_t FUN_00599ec0(const uint32_t* self, int param_1, float param_2, float param_3, float param_4, float param_5) {
    float fVar1;
    char cVar2;
    float10 fVar3;
    if (param_1 == 0) {
        return 0;
    }
    fVar1 = param_3 * param_5;
    if (fVar1 < 0.0f) {
        // The listing's CONCAT31 packs the comparison flags; the returned low byte is 1.
        return 1;
    }
    fVar1 = (param_2 + param_4) * 0.5f;
    fVar3 = (float10)((float (*)(float, uint32_t))(uintptr_t)self[0])(fVar1, self[6]);
    cVar2 = (char)FUN_00599ec0(self, param_1 + -1, param_2, param_3, fVar1, (float)fVar3);
    if (cVar2 == '\0') {
        cVar2 = (char)FUN_00599ec0(self, param_1 + -1, fVar1, (float)fVar3, param_4, param_5);
        if (cVar2 == '\0') {
            return 0;
        }
    }
    return 1;
}

// 0x599f70 — observed shape
uint32_t FUN_00599f70(const uint32_t* self, int param_1, float param_2, float param_3, float param_4, float param_5, float* param_6, float* param_7) {
    float fVar1;
    char cVar2;
    float10 fVar3;
    if (param_1 == 0) {
        return 0;
    }
    fVar1 = param_3 * param_5;
    if (fVar1 < 0.0f) {
        *param_6 = param_2;
        *param_7 = param_4;
        // The listing's CONCAT31 packs the comparison flags; the returned low byte is 1.
        return 1;
    }
    fVar1 = (param_2 + param_4) * 0.5f;
    fVar3 = (float10)((float (*)(float, uint32_t))(uintptr_t)self[0])(fVar1, self[6]);
    cVar2 = (char)FUN_00599f70(self, param_1 + -1, param_2, param_3, fVar1, (float)fVar3, param_6, param_7);
    if (cVar2 == '\0') {
        cVar2 = (char)FUN_00599f70(self, param_1 + -1, fVar1, (float)fVar3, param_4, param_5, param_6, param_7);
        if (cVar2 == '\0') {
            return 0;
        }
    }
    return 1;
}

// 0x59a040 — observed shape
uint32_t FUN_0059a040(const uint32_t* self, float param_1, float param_2, float param_3, float param_4, float* param_5) {
    float10 fVar1;
    float* pfVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    float10 fVar5;
    float10 fVar6;
    if (param_4 < 0.0f) {
        param_4 = param_3;
    } else {
        uVar3 = FUN_00599f70(self, (int)self[1], param_1, param_2, param_3, param_4, &param_1, &param_4);
        if ((char)uVar3 == '\0') {
            return uVar3;
        }
    }
    pfVar2 = param_5;
    uVar4 = 0;
    if (self[2] != 0) {
        while (true) {
            param_3 = (param_1 + param_4) * 0.5f;
            *pfVar2 = param_3;
            fVar5 = (float10)((float (*)(float, uint32_t))(uintptr_t)self[0])(param_3, self[6]);
            fVar6 = (float10)std::fabs(fVar5);
            fVar1 = (float10)*(const float*)&self[5];
            if ((!std::isnan(fVar6) && !std::isnan(fVar1)) && (fVar6 < fVar1) != (fVar6 == fVar1)) break;
            if ((float10)0.0f <= (float10)param_2 * fVar5) {
                param_1 = *pfVar2;
                param_2 = (float)fVar5;
            } else {
                param_4 = *pfVar2;
            }
            uVar4 = uVar4 + 1;
            if (self[2] <= uVar4) {
                return 1;
            }
        }
    }
    return 1;
}

// 0x59a130 — observed shape
float10 FUN_0059a130(int param_1, float* param_2, float* param_3, float* param_4, float* param_5, float* param_6, float* param_7) {
    float* pfVar1;
    float* pfVar2;
    float fVar3;
    float fVar4;
    float fVar5;
    float fVar6;
    float fVar7;
    float fVar8;
    float fVar9;
    float fVar10;
    float fVar11;
    float fVar12;
    float fVar13;
    float fVar14;
    float* pfVar15;
    float* pfVar16;
    float10 fVar17;
    float local_68;
    float local_64;
    float local_60;
    float local_5c;
    float local_3c;
    float local_38;
    float local_34;
    float local_28;
    float local_24;
    float local_20;
    float local_1c;
    float local_18;
    float local_14;
    float local_10;
    float local_c;
    float local_8;
    float local_4;
    pfVar15 = param_2;
    local_24 = *param_2;
    local_20 = param_2[1];
    local_1c = param_2[2];
    pfVar1 = param_2 + 3;
    local_18 = *pfVar1;
    local_14 = param_2[4];
    local_10 = param_2[5];
    pfVar2 = param_2 + 6;
    local_c = *pfVar2;
    local_8 = param_2[7];
    local_4 = param_2[8];
    local_5c = 3.4028235e+38f;
    fVar17 = FUN_0059f870((uint32_t)param_1, &local_24, &param_2, &local_68, &local_64, &local_60);
    if (fVar17 < (float10)3.4028235e+38f) {
        local_5c = (float)fVar17;
        *param_3 = (float)(uintptr_t)param_2;
        *param_4 = local_68;
        *param_5 = local_64;
        *param_6 = local_60;
        *param_7 = 0.0f;
        if (fVar17 == (float10)0.0f) {
            return (float10)0.0f;
        }
    }
    pfVar16 = pfVar15 + 9;
    local_c = *pfVar16;
    local_8 = pfVar15[10];
    local_4 = pfVar15[0xb];
    fVar17 = FUN_0059f870((uint32_t)param_1, &local_24, &param_2, &local_68, &local_64, &local_60);
    if (fVar17 < (float10)local_5c) {
        local_5c = (float)fVar17;
        *param_3 = (float)(uintptr_t)param_2;
        *param_4 = local_68;
        *param_5 = local_64;
        *param_6 = 0.0f;
        *param_7 = local_60;
        if (fVar17 == (float10)0.0f) {
            return (float10)0.0f;
        }
    }
    local_18 = *pfVar2;
    local_14 = pfVar15[7];
    local_10 = pfVar15[8];
    fVar17 = FUN_0059f870((uint32_t)param_1, &local_24, &param_2, &local_68, &local_64, &local_60);
    if (fVar17 < (float10)local_5c) {
        local_5c = (float)fVar17;
        *param_3 = (float)(uintptr_t)param_2;
        *param_4 = local_68;
        *param_5 = 0.0f;
        *param_6 = local_64;
        *param_7 = local_60;
        if (fVar17 == (float10)0.0f) {
            return (float10)0.0f;
        }
    }
    local_28 = pfVar15[8] + pfVar15[5];
    local_24 = *pfVar2 + *pfVar1 + *pfVar16 + local_24;
    local_20 = local_20 + pfVar15[7] + pfVar15[4] + pfVar15[10];
    local_1c = local_1c + local_28 + pfVar15[0xb];
    local_18 = -*pfVar1;
    local_14 = -pfVar15[4];
    local_10 = -pfVar15[5];
    local_3c = -*pfVar2;
    local_38 = -pfVar15[7];
    local_34 = -pfVar15[8];
    local_c = local_3c;
    local_8 = local_38;
    local_4 = local_34;
    fVar17 = FUN_0059f870((uint32_t)param_1, &local_24, &param_2, &local_68, &local_64, &local_60);
    if (fVar17 < (float10)local_5c) {
        local_5c = (float)fVar17;
        *param_3 = (float)(uintptr_t)param_2;
        *param_4 = local_68;
        *param_5 = 1.0f - local_64;
        *param_6 = 1.0f - local_60;
        *param_7 = 1.0f;
        if (fVar17 == (float10)0.0f) {
            return (float10)0.0f;
        }
    }
    local_3c = -*pfVar16;
    local_38 = -pfVar15[10];
    local_34 = -pfVar15[0xb];
    local_c = local_3c;
    local_8 = local_38;
    local_4 = local_34;
    fVar17 = FUN_0059f870((uint32_t)param_1, &local_24, &param_2, &local_68, &local_64, &local_60);
    if (fVar17 < (float10)local_5c) {
        local_5c = (float)fVar17;
        *param_3 = (float)(uintptr_t)param_2;
        *param_4 = local_68;
        *param_5 = 1.0f - local_64;
        *param_6 = 1.0f;
        *param_7 = 1.0f - local_60;
        if (fVar17 == (float10)0.0f) {
            return (float10)0.0f;
        }
    }
    local_3c = -*pfVar2;
    local_38 = -pfVar15[7];
    local_34 = -pfVar15[8];
    local_18 = local_3c;
    local_14 = local_38;
    local_10 = local_34;
    fVar17 = FUN_0059f870((uint32_t)param_1, &local_24, &param_2, &local_68, &local_64, &local_60);
    fVar3 = (float)fVar17;
    fVar17 = (float10)local_5c;
    if ((float10)fVar3 < fVar17) {
        fVar17 = (float10)fVar3;
        *param_3 = (float)(uintptr_t)param_2;
        *param_4 = local_68;
        *param_5 = 1.0f;
        *param_6 = 1.0f - local_64;
        *param_7 = 1.0f - local_60;
        if (fVar3 == 0.0f) goto LAB_0059a8dc;
    }
    fVar3 = *param_4;
    fVar4 = *param_3;
    fVar5 = fVar3 * *(const float*)((uintptr_t)param_1 + 0x18) + fVar4 * *(const float*)((uintptr_t)param_1 + 0xc);
    fVar7 = fVar4 * *(const float*)((uintptr_t)param_1 + 0x10) + fVar3 * *(const float*)((uintptr_t)param_1 + 0x1c);
    fVar3 = fVar4 * *(const float*)((uintptr_t)param_1 + 0x14) + fVar3 * *(const float*)((uintptr_t)param_1 + 0x20);
    fVar8 = *pfVar1 * *pfVar1 + pfVar15[4] * pfVar15[4] + pfVar15[5] * pfVar15[5];
    fVar9 = *pfVar1 * *pfVar2 + pfVar15[7] * pfVar15[4] + pfVar15[8] * pfVar15[5];
    fVar10 = *pfVar16 * *pfVar1 + pfVar15[10] * pfVar15[4] + pfVar15[0xb] * pfVar15[5];
    fVar11 = *pfVar2 * *pfVar2 + pfVar15[7] * pfVar15[7] + pfVar15[8] * pfVar15[8];
    fVar12 = *pfVar16 * *pfVar2 + pfVar15[10] * pfVar15[7] + pfVar15[0xb] * pfVar15[8];
    fVar13 = *pfVar16 * *pfVar16 + pfVar15[10] * pfVar15[10] + pfVar15[0xb] * pfVar15[0xb];
    fVar6 = fVar5 * *pfVar1 + fVar7 * pfVar15[4] + fVar3 * pfVar15[5];
    fVar4 = fVar5 * *pfVar2 + fVar7 * pfVar15[7] + fVar3 * pfVar15[8];
    fVar3 = fVar5 * *pfVar16 + fVar7 * pfVar15[10] + fVar3 * pfVar15[0xb];
    fVar5 = fVar12 * fVar10 - fVar13 * fVar9;
    fVar7 = fVar12 * fVar9 - fVar11 * fVar10;
    fVar14 = fVar10 * fVar9 - fVar12 * fVar8;
    fVar12 = fVar5 * fVar4 + fVar7 * fVar3 + (fVar13 * fVar11 - fVar12 * fVar12) * fVar6;
    if ((((fVar12 < 0.0f) || (1.0f < fVar12)) ||
         (fVar5 = fVar5 * fVar6 + fVar14 * fVar3 + (fVar13 * fVar8 - fVar10 * fVar10) * fVar4, fVar5 < 0.0f)) ||
        (((1.0f < fVar5 ||
           (fVar3 = fVar7 * fVar6 + fVar14 * fVar4 + (fVar11 * fVar8 - fVar9 * fVar9) * fVar3, fVar3 < 0.0f)) ||
          (1.0f < fVar3)))) {
        return fVar17;
    }
LAB_0059a8dc:
    return (float10)0.0f;
}

// 0x59a900 — observed shape
void FUN_0059a900(void* self, uint32_t* param_1) {
    int iVar1;
    char cVar2;
    int iVar3;
    uint32_t* puVar4;
    uintptr_t base = (uintptr_t)self;
    cVar2 = FUN_00557a60(param_1);
    if (cVar2 != '\0') {
        iVar1 = *(int*)(base + 0x50);
        puVar4 = (uint32_t*)(base + 0x1c);
        for (iVar3 = 0xd; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar4 = *param_1;
            param_1 = param_1 + 1;
            puVar4 = puVar4 + 1;
        }
        *(uint8_t*)(base + 0xc) = 1;
        *(int*)(base + 0x50) = iVar1 + 1;
    }
}

// 0x59a940 — observed shape
void FUN_0059a940(uint32_t* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5) {
    int iVar1;
    uint32_t uVar2;
    self[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c51d8;
    if ((uint16_t)param_1 < 2) {
        iVar1 = FUN_00533c78(0x98);
        if (iVar1 != 0) {
            uVar2 = FUN_0059fce0(self, param_2, param_3, param_4, 0);
            goto LAB_0059a9b2;
        }
    } else {
        iVar1 = FUN_00533c78(0x8c);
        if (iVar1 != 0) {
            uVar2 = FUN_005a3150(self, param_1, param_2, param_3, param_4, param_5);
            goto LAB_0059a9b2;
        }
    }
    uVar2 = 0;
LAB_0059a9b2:
    self[2] = uVar2;
    self[1] = 0;
    self[4] = DAT_00727430;
    self[5] = DAT_00727434;
    self[6] = DAT_00727438;
    FUN_00557990();
    *(uint8_t*)(self + 3) = 0;
    self[0x14] = 0;
}

// 0x59aac0 — observed shape
uint32_t FUN_0059aac0(const float* self, const float* param_1) {
    if ((((self[0] == param_1[0]) && (self[1] == param_1[1])) && (self[2] == param_1[2])) &&
        (self[3] == param_1[3])) {
        return 1;
    }
    return 0;
}

// 0x59ab10 — observed shape
void FUN_0059ab10(void* self, int param_1) {
    uintptr_t vftable;
    void (*fn)(void*, uint32_t);
    FUN_00535110(param_1);
    vftable = (uintptr_t)(uint32_t)(**(int**)((uintptr_t)param_1 + 0x15c));
    fn = *(void (**)(void*, uint32_t))(vftable + 8);
    fn((uint8_t*)self + 0xc, 4);
}

// 0x59ab40 — observed shape
void FUN_0059ab40(void* self, int param_1) {
    uintptr_t vftable;
    void (*fn)(void*, uint32_t);
    FUN_00535150(param_1);
    vftable = (uintptr_t)(uint32_t)(**(int**)((uintptr_t)param_1 + 0x160));
    fn = *(void (**)(void*, uint32_t))(vftable + 0xc);
    fn((uint8_t*)self + 0xc, 4);
}
