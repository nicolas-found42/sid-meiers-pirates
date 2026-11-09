// Reconstruction batch mass_0191 — Sid Meier's Pirates! (2004), PE32 i386
// Corpus: Ghidra 12.2 pseudocode (analysis/pseudocode/functions/0x596xxx, 0x597xxx, 0x598xxx).
// Addresses: 0x5966c0, 0x596cb0, 0x596d60, 0x596da0, 0x596de0, 0x596eb0, 0x597010,
//            0x5970e0, 0x597470, 0x597820, 0x597980, 0x597a50, 0x597dc0, 0x597f20,
//            0x598130, 0x598270, 0x598320, 0x598480, 0x598650, 0x598790.
// Pseudocode is provider output, not original source.

#include <cstdint>
#include <cstddef>
#include <cmath>
#include <windows.h>

typedef long double float10;

extern void FUN_0053d8a0(void* param_1, float* param_2);
extern void FUN_00535110(int param_1);
extern void FUN_00535150(int param_1);
extern float10 FUN_0059f2c0(uint32_t param_1, const void* param_2, const void* param_3, void* param_4);
extern float DAT_00727568;

// 0x5966c0 — observed shape
void FUN_005966c0(void* self, uint16_t param_1, float* param_2) {
    float* in_ECX = static_cast<float*>(self);
    float fVar1;
    float fVar2;
    float fVar3;
    float fVar4;
    float* pfVar5;
    int iVar6;
    uint32_t uVar7;
    float* pfVar8;
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
    uint8_t local_30[12];
    float local_24;
    float local_20;
    float local_1c;
    float local_18;
    float local_14;
    float local_10;
    float local_c;
    float local_8;
    float local_4;

    local_74 = *param_2;
    local_6c = param_2[1];
    fVar1 = param_2[2];
    *in_ECX = *param_2;
    in_ECX[1] = param_2[1];
    in_ECX[2] = param_2[2];
    local_70 = local_74;
    local_68 = local_6c;
    local_64 = fVar1;
    if (1 < param_1) {
        pfVar5 = param_2 + 5;
        uVar7 = (uint32_t)(uint16_t)(param_1 - 1);
        do {
            *in_ECX = pfVar5[-2] + *in_ECX;
            in_ECX[1] = pfVar5[-1] + in_ECX[1];
            in_ECX[2] = in_ECX[2] + *pfVar5;
            if (local_70 <= pfVar5[-2]) {
                if (local_74 < pfVar5[-2]) {
                    local_74 = pfVar5[-2];
                }
            } else {
                local_70 = pfVar5[-2];
            }
            if (local_68 <= pfVar5[-1]) {
                if (local_6c < pfVar5[-1]) {
                    local_6c = pfVar5[-1];
                }
            } else {
                local_68 = pfVar5[-1];
            }
            if (local_64 <= *pfVar5) {
                if (fVar1 < *pfVar5) {
                    fVar1 = *pfVar5;
                }
            } else {
                local_64 = *pfVar5;
            }
            pfVar5 = pfVar5 + 3;
            uVar7 = uVar7 - 1;
        } while (uVar7 != 0);
    }
    uVar7 = (uint32_t)param_1;
    fVar2 = 1.0f / (float)uVar7;
    fVar4 = fVar2 * *in_ECX;
    *in_ECX = fVar4;
    fVar3 = fVar2 * in_ECX[1];
    fVar2 = fVar2 * in_ECX[2];
    in_ECX[1] = fVar3;
    in_ECX[2] = fVar2;
    if (((local_70 == local_74) || (local_68 == local_6c)) || (local_64 == fVar1)) {
        in_ECX[3] = 1.0f;
        local_70 = (local_74 - local_70) * 0.5f;
        in_ECX[4] = 0.0f;
        in_ECX[5] = 0.0f;
        local_68 = (local_6c - local_68) * 0.5f;
        in_ECX[6] = 0.0f;
        in_ECX[7] = 1.0f;
        in_ECX[8] = 0.0f;
        fVar1 = (fVar1 - local_64) * 0.5f;
        in_ECX[9] = 0.0f;
        in_ECX[10] = 0.0f;
        in_ECX[0xb] = 1.0f;
        if (!NAN(local_70) && local_70 < 0.0f != (local_70 == 0.0f)) {
            local_70 = 0.1f;
        }
        if (!NAN(local_68) && local_68 < 0.0f != (local_68 == 0.0f)) {
            local_68 = 0.1f;
        }
        if (!NAN(fVar1) && fVar1 < 0.0f != (fVar1 == 0.0f)) {
            fVar1 = 0.1f;
        }
        in_ECX[0xe] = fVar1;
        in_ECX[0xc] = local_70;
        in_ECX[0xd] = local_68;
        return;
    }
    pfVar5 = &DAT_00727568;
    pfVar8 = &local_24;
    for (iVar6 = 9; iVar6 != 0; iVar6 = iVar6 + -1) {
        *pfVar8 = *pfVar5;
        pfVar5 = pfVar5 + 1;
        pfVar8 = pfVar8 + 1;
    }
    if (param_1 != 0) {
        do {
            uVar7 = uVar7 - 1;
            local_24 = fVar4 * fVar4 + local_24;
            local_20 = fVar3 * fVar4 + local_20;
            local_1c = fVar2 * fVar4 + local_1c;
            local_18 = fVar3 * fVar3 + local_18;
            local_14 = fVar2 * fVar3 + local_14;
            local_10 = local_10 + fVar2 * fVar2;
        } while (uVar7 != 0);
    }
    pfVar5 = in_ECX + 3;
    local_18 = local_20;   // local_24[3] = local_24[1]
    local_c = local_1c;    // local_c     = local_24[2]
    local_8 = local_10;
    FUN_0053d8a0(local_30, pfVar5);
    local_60 = *param_2 - *in_ECX;
    local_5c = param_2[1] - in_ECX[1];
    local_58 = param_2[2] - in_ECX[2];
    local_54 = local_60;
    local_50 = local_5c;
    local_4c = local_58;
    if (1 < param_1) {
        param_2 = param_2 + 5;
        uVar7 = (uint32_t)(uint16_t)(param_1 - 1);
        do {
            fVar1 = param_2[-2] - *in_ECX;
            fVar2 = param_2[-1] - in_ECX[1];
            fVar3 = *param_2 - in_ECX[2];
            fVar4 = fVar1 * *pfVar5 + fVar3 * in_ECX[5] + fVar2 * in_ECX[4];
            if (local_60 <= fVar4) {
                if (local_54 < fVar4) {
                    local_54 = fVar4;
                }
            } else {
                local_60 = fVar4;
            }
            fVar4 = fVar3 * in_ECX[8] + fVar2 * in_ECX[7] + fVar1 * in_ECX[6];
            if (local_5c <= fVar4) {
                if (local_50 < fVar4) {
                    local_50 = fVar4;
                }
            } else {
                local_5c = fVar4;
            }
            fVar1 = fVar1 * in_ECX[9] + fVar3 * in_ECX[0xb] + fVar2 * in_ECX[10];
            if (local_58 <= fVar1) {
                if (local_4c < fVar1) {
                    local_4c = fVar1;
                }
            } else {
                local_58 = fVar1;
            }
            param_2 = param_2 + 3;
            uVar7 = uVar7 - 1;
        } while (uVar7 != 0);
    }
    fVar1 = (local_54 + local_60) * 0.5f;
    fVar2 = fVar1 * *pfVar5 + *in_ECX;
    *in_ECX = fVar2;
    fVar3 = fVar1 * in_ECX[4] + in_ECX[1];
    in_ECX[1] = fVar3;
    fVar4 = fVar1 * in_ECX[5] + in_ECX[2];
    in_ECX[2] = fVar4;
    fVar1 = (local_50 + local_5c) * 0.5f;
    fVar2 = fVar2 + fVar1 * in_ECX[6];
    *in_ECX = fVar2;
    fVar3 = fVar3 + fVar1 * in_ECX[7];
    in_ECX[1] = fVar3;
    fVar4 = fVar4 + fVar1 * in_ECX[8];
    in_ECX[2] = fVar4;
    fVar1 = (local_4c + local_58) * 0.5f;
    *in_ECX = fVar1 * in_ECX[9] + fVar2;
    in_ECX[1] = fVar1 * in_ECX[10] + fVar3;
    in_ECX[2] = fVar1 * in_ECX[0xb] + fVar4;
    in_ECX[0xc] = (local_54 - local_60) * 0.5f;
    in_ECX[0xd] = (local_50 - local_5c) * 0.5f;
    in_ECX[0xe] = (local_4c - local_58) * 0.5f;
    return;
}

// 0x596cb0 — observed shape
uint16_t FUN_00596cb0(void* self, float* param_1) {
    float* in_ECX = static_cast<float*>(self);
    float fVar1;
    float fVar2;
    float* pfVar3;
    float* pfVar4;
    float* pfVar5;
    int iVar6;
    uint16_t uVar7;

    fVar1 = *param_1;
    fVar2 = *in_ECX;
    uVar7 = (uint16_t)(fVar2 < fVar1) << 8 | (uint16_t)(NAN(fVar2) || NAN(fVar1)) << 10 |
            (uint16_t)(fVar2 == fVar1) << 0xe;
    if (fVar2 == fVar1) {
        fVar1 = param_1[1];
        fVar2 = in_ECX[1];
        uVar7 = (uint16_t)(fVar2 < fVar1) << 8 | (uint16_t)(NAN(fVar2) || NAN(fVar1)) << 10 |
                (uint16_t)(fVar2 == fVar1) << 0xe;
        if (fVar2 == fVar1) {
            fVar1 = param_1[2];
            fVar2 = in_ECX[2];
            uVar7 = (uint16_t)(fVar2 < fVar1) << 8 | (uint16_t)(NAN(fVar2) || NAN(fVar1)) << 10 |
                    (uint16_t)(fVar2 == fVar1) << 0xe;
            if (fVar2 == fVar1) {
                iVar6 = 0;
                pfVar5 = param_1 + 0xc;
                pfVar4 = param_1 + 4;
                pfVar3 = in_ECX;
                while (true) {
                    fVar1 = pfVar4[-1];
                    fVar2 = pfVar3[3];
                    if (fVar2 != fVar1) {
                        return (uint16_t)(fVar2 < fVar1) << 8 | (uint16_t)(NAN(fVar2) || NAN(fVar1)) << 10 |
                               (uint16_t)(fVar2 == fVar1) << 0xe;
                    }
                    fVar1 = *pfVar4;
                    fVar2 = *(float*)(((intptr_t)in_ECX - (intptr_t)param_1) + (intptr_t)pfVar4);
                    if (fVar2 != fVar1) {
                        return (uint16_t)(fVar2 < fVar1) << 8 | (uint16_t)(NAN(fVar2) || NAN(fVar1)) << 10 |
                               (uint16_t)(fVar2 == fVar1) << 0xe;
                    }
                    fVar1 = pfVar4[1];
                    fVar2 = pfVar3[5];
                    if (fVar2 != fVar1) {
                        return (uint16_t)(fVar2 < fVar1) << 8 | (uint16_t)(NAN(fVar2) || NAN(fVar1)) << 10 |
                               (uint16_t)(fVar2 == fVar1) << 0xe;
                    }
                    fVar1 = *pfVar5;
                    fVar2 = *(float*)(((intptr_t)in_ECX - (intptr_t)param_1) + (intptr_t)pfVar5);
                    uVar7 = (uint16_t)(fVar2 < fVar1) << 8 | (uint16_t)(NAN(fVar2) || NAN(fVar1)) << 10 |
                            (uint16_t)(fVar2 == fVar1) << 0xe;
                    if (fVar2 != fVar1) {
                        break;
                    }
                    iVar6 = iVar6 + 1;
                    pfVar5 = pfVar5 + 1;
                    pfVar4 = pfVar4 + 3;
                    pfVar3 = pfVar3 + 3;
                    if (2 < iVar6) {
                        return (uint16_t)((((uint16_t)(uVar7 >> 8)) << 8) | 1);
                    }
                }
                return uVar7;
            }
        }
    }
    return uVar7;
}

// 0x596d60 — observed shape
void FUN_00596d60(void* self, int param_1) {
    intptr_t in_ECX = (intptr_t)self;
    int iVar1;

    FUN_00535110(param_1);
    iVar1 = 3;
    do {
        FUN_00535110(param_1);
        iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    int32_t* obj = *(int32_t**)(param_1 + 0x15c);
    int32_t vtbl = *obj;
    typedef void (*Vfunc)(void*, int);
    (*(Vfunc*)((intptr_t)vtbl + 8))((void*)(in_ECX + 0x30), 0xc);
    return;
}

// 0x596da0 — observed shape
void FUN_00596da0(void* self, int param_1) {
    intptr_t in_ECX = (intptr_t)self;
    int iVar1;

    FUN_00535150(param_1);
    iVar1 = 3;
    do {
        FUN_00535150(param_1);
        iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    int32_t* obj = *(int32_t**)(param_1 + 0x160);
    int32_t vtbl = *obj;
    typedef void (*Vfunc)(void*, int);
    (*(Vfunc*)((intptr_t)vtbl + 0xc))((void*)(in_ECX + 0x30), 0xc);
    return;
}

// 0x596de0 — observed shape
float10 FUN_00596de0(uint32_t param_1, float* param_2, uint32_t* param_3, uint32_t* param_4,
                     uint32_t* param_5) {
    float10 fVar1;
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

    local_34 = 3.4028235e+38f;
    local_30 = *param_2 + param_2[9];
    local_2c = param_2[10] + param_2[1];
    local_28 = param_2[0xb] + param_2[2];
    local_18 = param_2[3];
    local_14 = param_2[4];
    local_10 = param_2[5];
    local_c = param_2[6];
    local_8 = param_2[7];
    local_4 = param_2[8];
    local_24 = local_30;
    local_20 = local_2c;
    local_1c = local_28;
    fVar1 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_38);
    if (fVar1 < (float10)3.4028235e+38f) {
        *param_3 = (uint32_t)(uintptr_t)param_2;
        *param_4 = local_38;
        *param_5 = 0x3f800000;
        return fVar1;
    }
    return (float10)local_34;
}

// 0x596eb0 — observed shape
float10 FUN_00596eb0(uint32_t param_1, float* param_2, uint32_t* param_3, uint32_t* param_4,
                     uint32_t* param_5) {
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
    pfVar2 = param_2 + 6;
    local_2c = param_2[4] + param_2[1];
    local_34 = 3.4028235e+38f;
    local_28 = param_2[5] + param_2[2];
    local_18 = *pfVar2;
    local_14 = param_2[7];
    local_10 = param_2[8];
    local_c = param_2[9];
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
    local_8 = pfVar3[7];
    local_4 = pfVar3[8];
    fVar4 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_38);
    if ((float10)local_34 <= fVar4) {
        return (float10)local_34;
    }
    *param_3 = (uint32_t)(uintptr_t)param_2;
    *param_4 = local_38;
    *param_5 = 0;
    return fVar4;
}

// 0x597010 — observed shape
float10 FUN_00597010(uint32_t param_1, float* param_2, uint32_t* param_3, uint32_t* param_4,
                     uint32_t* param_5) {
    float10 fVar1;
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

    local_34 = 3.4028235e+38f;
    local_30 = *param_2 + param_2[3];
    local_2c = param_2[4] + param_2[1];
    local_28 = param_2[5] + param_2[2];
    local_18 = param_2[6];
    local_14 = param_2[7];
    local_10 = param_2[8];
    local_c = param_2[9];
    local_8 = param_2[10];
    local_4 = param_2[0xb];
    local_24 = local_30;
    local_20 = local_2c;
    local_1c = local_28;
    fVar1 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_38);
    if (fVar1 < (float10)3.4028235e+38f) {
        *param_3 = 0x3f800000;
        *param_4 = (uint32_t)(uintptr_t)param_2;
        *param_5 = local_38;
        return fVar1;
    }
    return (float10)local_34;
}

// 0x5970e0 — observed shape
float10 FUN_005970e0(uint32_t param_1, float* param_2, uint32_t* param_3, uint32_t* param_4,
                     uint32_t* param_5) {
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

// 0x597470 — observed shape
float10 FUN_00597470(uint32_t param_1, float* param_2, uint32_t* param_3, uint32_t* param_4,
                     uint32_t* param_5) {
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
    local_30 = *pfVar4 + *pfVar2;
    local_2c = pfVar4[7] + pfVar4[1];
    local_18 = *pfVar1;
    local_c = *pfVar3;
    local_28 = pfVar4[8] + pfVar4[2];
    local_14 = pfVar4[4];
    local_8 = pfVar4[10];
    local_10 = pfVar4[5];
    local_4 = pfVar4[0xb];
    local_24 = local_30;
    local_20 = local_2c;
    local_1c = local_28;
    fVar5 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_38);
    if ((float10)local_34 <= fVar5) {
        return (float10)local_34;
    }
    *param_3 = (uint32_t)(uintptr_t)param_2;
    *param_4 = 0x3f800000;
    *param_5 = local_38;
    return fVar5;
}

// 0x597820 — observed shape
float10 FUN_00597820(uint32_t param_1, float* param_2, uint32_t* param_3, uint32_t* param_4,
                     uint32_t* param_5) {
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
    local_30 = *param_2 + param_2[6];
    pfVar1 = param_2 + 6;
    pfVar2 = param_2 + 3;
    local_2c = param_2[7] + param_2[1];
    local_34 = 3.4028235e+38f;
    local_28 = param_2[8] + param_2[2];
    local_18 = *pfVar2;
    local_14 = param_2[4];
    local_10 = param_2[5];
    local_c = param_2[9];
    local_8 = param_2[10];
    local_4 = param_2[0xb];
    local_24 = local_30;
    local_20 = local_2c;
    local_1c = local_28;
    fVar4 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_38);
    if (fVar4 < (float10)3.4028235e+38f) {
        local_34 = (float)fVar4;
        *param_3 = (uint32_t)(uintptr_t)param_2;
        *param_4 = 0x3f800000;
        *param_5 = local_38;
    }
    local_24 = *pfVar3;
    local_20 = pfVar3[1];
    local_1c = pfVar3[2];
    local_18 = *pfVar2;
    local_14 = pfVar3[4];
    local_10 = pfVar3[5];
    local_c = *pfVar1;
    local_8 = pfVar3[7];
    local_4 = pfVar3[8];
    fVar4 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_38);
    if ((float10)local_34 <= fVar4) {
        return (float10)local_34;
    }
    *param_3 = (uint32_t)(uintptr_t)param_2;
    *param_4 = local_38;
    *param_5 = 0;
    return fVar4;
}

// 0x597980 — observed shape
float10 FUN_00597980(uint32_t param_1, float* param_2, uint32_t* param_3, uint32_t* param_4,
                     uint32_t* param_5) {
    float10 fVar1;
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

    local_34 = 3.4028235e+38f;
    local_30 = *param_2 + param_2[6];
    local_2c = param_2[7] + param_2[1];
    local_28 = param_2[8] + param_2[2];
    local_18 = param_2[3];
    local_14 = param_2[4];
    local_10 = param_2[5];
    local_c = param_2[9];
    local_8 = param_2[10];
    local_4 = param_2[0xb];
    local_24 = local_30;
    local_20 = local_2c;
    local_1c = local_28;
    fVar1 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_38);
    if (fVar1 < (float10)3.4028235e+38f) {
        *param_3 = (uint32_t)(uintptr_t)param_2;
        *param_4 = 0x3f800000;
        *param_5 = local_38;
        return fVar1;
    }
    return (float10)local_34;
}

// 0x597a50 — observed shape
float10 FUN_00597a50(uint32_t param_1, float* param_2, uint32_t* param_3, uint32_t* param_4,
                     uint32_t* param_5) {
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
    local_30 = *param_2 + param_2[6];
    pfVar1 = param_2 + 6;
    pfVar2 = param_2 + 3;
    pfVar3 = param_2 + 9;
    local_2c = param_2[7] + param_2[1];
    local_34 = 3.4028235e+38f;
    local_28 = param_2[8] + param_2[2];
    local_18 = *pfVar2;
    local_14 = param_2[4];
    local_10 = param_2[5];
    local_c = *pfVar3;
    local_8 = param_2[10];
    local_4 = param_2[0xb];
    local_24 = local_30;
    local_20 = local_2c;
    local_1c = local_28;
    fVar5 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_38);
    if (fVar5 < (float10)3.4028235e+38f) {
        local_34 = (float)fVar5;
        *param_3 = (uint32_t)(uintptr_t)param_2;
        *param_4 = 0x3f800000;
        *param_5 = local_38;
    }
    local_30 = *pfVar4 + *pfVar3;
    local_2c = pfVar4[10] + pfVar4[1];
    local_18 = *pfVar2;
    local_c = *pfVar1;
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

// 0x597dc0 — observed shape
float10 FUN_00597dc0(uint32_t param_1, float* param_2, uint32_t* param_3, uint32_t* param_4,
                     uint32_t* param_5) {
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
    pfVar1 = param_2 + 6;
    local_18 = *pfVar1;
    local_14 = param_2[7];
    local_10 = param_2[8];
    pfVar2 = param_2 + 9;
    local_c = *pfVar2;
    local_8 = param_2[10];
    local_4 = param_2[0xb];
    local_34 = 3.4028235e+38f;
    fVar4 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_38);
    if (fVar4 < (float10)3.4028235e+38f) {
        local_34 = (float)fVar4;
        *param_3 = 0;
        *param_4 = (uint32_t)(uintptr_t)param_2;
        *param_5 = local_38;
    }
    local_30 = *pfVar3 + *pfVar1;
    local_2c = pfVar3[7] + pfVar3[1];
    local_28 = pfVar3[8] + pfVar3[2];
    local_18 = pfVar3[3];
    local_14 = pfVar3[4];
    local_c = *pfVar2;
    local_10 = pfVar3[5];
    local_8 = pfVar3[10];
    local_4 = pfVar3[0xb];
    local_24 = local_30;
    local_20 = local_2c;
    local_1c = local_28;
    fVar4 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_38);
    if ((float10)local_34 <= fVar4) {
        return (float10)local_34;
    }
    *param_3 = (uint32_t)(uintptr_t)param_2;
    *param_4 = 0x3f800000;
    *param_5 = local_38;
    return fVar4;
}

// 0x597f20 — observed shape
float10 FUN_00597f20(uint32_t param_1, float* param_2, uint32_t* param_3, uint32_t* param_4,
                     uint32_t* param_5) {
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
    pfVar1 = param_2 + 6;
    local_18 = *pfVar1;
    local_14 = param_2[7];
    local_10 = param_2[8];
    pfVar2 = param_2 + 9;
    local_c = *pfVar2;
    local_8 = param_2[10];
    local_4 = param_2[0xb];
    local_34 = 3.4028235e+38f;
    fVar4 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_38);
    if (fVar4 < (float10)3.4028235e+38f) {
        local_34 = (float)fVar4;
        *param_3 = 0;
        *param_4 = (uint32_t)(uintptr_t)param_2;
        *param_5 = local_38;
    }
    local_30 = *pfVar3 + *pfVar1;
    local_2c = pfVar3[7] + pfVar3[1];
    local_28 = pfVar3[8] + pfVar3[2];
    local_18 = pfVar3[3];
    local_14 = pfVar3[4];
    local_10 = pfVar3[5];
    local_c = *pfVar2;
    local_8 = pfVar3[10];
    local_4 = pfVar3[0xb];
    local_24 = local_30;
    local_20 = local_2c;
    local_1c = local_28;
    fVar4 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_38);
    if (fVar4 < (float10)local_34) {
        local_34 = (float)fVar4;
        *param_3 = (uint32_t)(uintptr_t)param_2;
        *param_4 = 0x3f800000;
        *param_5 = local_38;
    }
    local_30 = *pfVar3 + *pfVar2;
    local_2c = pfVar3[10] + pfVar3[1];
    local_18 = pfVar3[3];
    local_c = *pfVar1;
    local_28 = pfVar3[0xb] + pfVar3[2];
    local_14 = pfVar3[4];
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

// 0x598130 — observed shape
float10 FUN_00598130(uint32_t param_1, uint32_t* param_2, uint32_t* param_3, uint32_t* param_4,
                     uint32_t* param_5) {
    uint32_t* puVar1;
    uint32_t* puVar2;
    uint32_t* puVar3;
    float10 fVar4;
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

    puVar2 = param_2;
    local_24 = *param_2;
    local_20 = param_2[1];
    local_1c = param_2[2];
    puVar1 = param_2 + 6;
    local_18 = *puVar1;
    local_14 = param_2[7];
    local_10 = param_2[8];
    local_c = param_2[9];
    local_8 = param_2[10];
    local_4 = param_2[0xb];
    local_28 = 3.4028235e+38f;
    fVar4 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_2c);
    puVar3 = param_5;
    if (fVar4 < (float10)3.4028235e+38f) {
        local_28 = (float)fVar4;
        *param_3 = 0;
        *param_4 = (uint32_t)(uintptr_t)param_2;
        *param_5 = local_2c;
    }
    local_24 = *puVar2;
    local_20 = puVar2[1];
    local_1c = puVar2[2];
    local_18 = puVar2[3];
    local_14 = puVar2[4];
    local_10 = puVar2[5];
    local_c = *puVar1;
    local_8 = puVar2[7];
    local_4 = puVar2[8];
    fVar4 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_2c);
    if ((float10)local_28 <= fVar4) {
        return (float10)local_28;
    }
    *param_3 = (uint32_t)(uintptr_t)param_2;
    *param_4 = local_2c;
    *puVar3 = 0;
    return fVar4;
}

// 0x598270 — observed shape
float10 FUN_00598270(uint32_t param_1, uint32_t* param_2, uint32_t* param_3, uint32_t* param_4,
                     uint32_t* param_5) {
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
    local_18 = param_2[6];
    local_14 = param_2[7];
    local_10 = param_2[8];
    local_c = param_2[9];
    local_8 = param_2[10];
    local_4 = param_2[0xb];
    local_28 = 3.4028235e+38f;
    fVar1 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_2c);
    if (fVar1 < (float10)3.4028235e+38f) {
        *param_3 = 0;
        *param_4 = (uint32_t)(uintptr_t)param_2;
        *param_5 = local_2c;
        return fVar1;
    }
    return (float10)local_28;
}

// 0x598320 — observed shape
float10 FUN_00598320(uint32_t param_1, float* param_2, uint32_t* param_3, uint32_t* param_4,
                     uint32_t* param_5) {
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
    pfVar1 = param_2 + 6;
    local_18 = *pfVar1;
    local_14 = param_2[7];
    local_10 = param_2[8];
    pfVar2 = param_2 + 9;
    local_c = *pfVar2;
    local_8 = param_2[10];
    local_4 = param_2[0xb];
    local_34 = 3.4028235e+38f;
    fVar4 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_38);
    if (fVar4 < (float10)3.4028235e+38f) {
        local_34 = (float)fVar4;
        *param_3 = 0;
        *param_4 = (uint32_t)(uintptr_t)param_2;
        *param_5 = local_38;
    }
    local_30 = *pfVar3 + *pfVar2;
    local_2c = pfVar3[10] + pfVar3[1];
    local_28 = pfVar3[0xb] + pfVar3[2];
    local_18 = pfVar3[3];
    local_14 = pfVar3[4];
    local_c = *pfVar1;
    local_10 = pfVar3[5];
    local_8 = pfVar3[7];
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

// 0x598480 — observed shape
float10 FUN_00598480(uint32_t param_1, uint32_t* param_2, uint32_t* param_3, uint32_t* param_4,
                     uint32_t* param_5) {
    uint32_t* puVar1;
    uint32_t* puVar2;
    uint32_t* puVar3;
    float10 fVar4;
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

    puVar3 = param_2;
    local_24 = *param_2;
    local_20 = param_2[1];
    local_1c = param_2[2];
    puVar1 = param_2 + 6;
    local_18 = *puVar1;
    local_14 = param_2[7];
    local_10 = param_2[8];
    puVar2 = param_2 + 9;
    local_c = *puVar2;
    local_8 = param_2[10];
    local_4 = param_2[0xb];
    local_28 = 3.4028235e+38f;
    fVar4 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_2c);
    if (fVar4 < (float10)3.4028235e+38f) {
        local_28 = (float)fVar4;
        *param_3 = 0;
        *param_4 = (uint32_t)(uintptr_t)param_2;
        *param_5 = local_2c;
    }
    local_24 = *puVar3;
    local_20 = puVar3[1];
    local_1c = puVar3[2];
    local_18 = puVar3[3];
    local_14 = puVar3[4];
    local_10 = puVar3[5];
    local_c = *puVar2;
    local_8 = puVar3[10];
    local_4 = puVar3[0xb];
    fVar4 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_2c);
    if (fVar4 < (float10)local_28) {
        local_28 = (float)fVar4;
        *param_3 = (uint32_t)(uintptr_t)param_2;
        *param_4 = 0;
        *param_5 = local_2c;
    }
    local_24 = *puVar3;
    local_20 = puVar3[1];
    local_1c = puVar3[2];
    local_18 = puVar3[3];
    local_14 = puVar3[4];
    local_10 = puVar3[5];
    local_c = *puVar1;
    local_8 = puVar3[7];
    local_4 = puVar3[8];
    fVar4 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_2c);
    if ((float10)local_28 <= fVar4) {
        return (float10)local_28;
    }
    *param_3 = (uint32_t)(uintptr_t)param_2;
    *param_4 = local_2c;
    *param_5 = 0;
    return fVar4;
}

// 0x598650 — observed shape
float10 FUN_00598650(uint32_t param_1, uint32_t* param_2, uint32_t* param_3, uint32_t* param_4,
                     uint32_t* param_5) {
    uint32_t* puVar1;
    uint32_t* puVar2;
    uint32_t* puVar3;
    float10 fVar4;
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

    puVar2 = param_2;
    local_24 = *param_2;
    local_20 = param_2[1];
    local_1c = param_2[2];
    local_18 = param_2[6];
    local_14 = param_2[7];
    local_10 = param_2[8];
    puVar1 = param_2 + 9;
    local_c = *puVar1;
    local_8 = param_2[10];
    local_4 = param_2[0xb];
    local_28 = 3.4028235e+38f;
    fVar4 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_2c);
    puVar3 = param_5;
    if (fVar4 < (float10)3.4028235e+38f) {
        local_28 = (float)fVar4;
        *param_3 = 0;
        *param_4 = (uint32_t)(uintptr_t)param_2;
        *param_5 = local_2c;
    }
    local_24 = *puVar2;
    local_20 = puVar2[1];
    local_1c = puVar2[2];
    local_18 = puVar2[3];
    local_14 = puVar2[4];
    local_10 = puVar2[5];
    local_c = *puVar1;
    local_8 = puVar2[10];
    local_4 = puVar2[0xb];
    fVar4 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_2c);
    if ((float10)local_28 <= fVar4) {
        return (float10)local_28;
    }
    *param_3 = (uint32_t)(uintptr_t)param_2;
    *param_4 = 0;
    *puVar3 = local_2c;
    return fVar4;
}

// 0x598790 — observed shape
float10 FUN_00598790(uint32_t param_1, float* param_2, uint32_t* param_3, uint32_t* param_4,
                     uint32_t* param_5) {
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
    pfVar1 = param_2 + 6;
    local_18 = *pfVar1;
    local_14 = param_2[7];
    local_10 = param_2[8];
    pfVar2 = param_2 + 9;
    local_c = *pfVar2;
    local_8 = param_2[10];
    local_4 = param_2[0xb];
    local_34 = 3.4028235e+38f;
    fVar4 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_38);
    if (fVar4 < (float10)3.4028235e+38f) {
        local_34 = (float)fVar4;
        *param_3 = 0;
        *param_4 = (uint32_t)(uintptr_t)param_2;
        *param_5 = local_38;
    }
    local_24 = *pfVar3;
    local_20 = pfVar3[1];
    local_1c = pfVar3[2];
    local_18 = pfVar3[3];
    local_14 = pfVar3[4];
    local_10 = pfVar3[5];
    local_c = *pfVar2;
    local_8 = pfVar3[10];
    local_4 = pfVar3[0xb];
    fVar4 = FUN_0059f2c0(param_1, &local_24, &param_2, &local_38);
    if (fVar4 < (float10)local_34) {
        local_34 = (float)fVar4;
        *param_3 = (uint32_t)(uintptr_t)param_2;
        *param_4 = 0;
        *param_5 = local_38;
    }
    local_30 = *pfVar3 + *pfVar2;
    local_2c = pfVar3[10] + pfVar3[1];
    local_18 = pfVar3[3];
    local_c = *pfVar1;
    local_28 = pfVar3[0xb] + pfVar3[2];
    local_14 = pfVar3[4];
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
