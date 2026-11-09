#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cmath>

extern void operator_delete(void* p);
extern uint32_t FUN_00491640();
extern char FUN_0059aac0(void* p);
extern char FUN_00596690(uint32_t param_1, int v1, int v2);
extern void FUN_0053ca60(void* out, int src);

extern void* PTR_FUN_006c50fc;
extern void* DAT_00728ae8;

// 0x5910a0 — observed shape
void FUN_005910a0(void* self_param) {
    uint32_t* in_ECX = (uint32_t*)self_param;
    uint32_t uVar1 = 0;
    if (in_ECX[3] != 0) {
        do {
            operator_delete(*(void**)((char*)in_ECX[1] + uVar1 * 4));
            uVar1 = uVar1 + 1;
        } while (uVar1 < in_ECX[3]);
    }
    uVar1 = 0;
    if (in_ECX[9] != 0) {
        do {
            operator_delete(*(void**)((char*)in_ECX[7] + uVar1 * 4));
            uVar1 = uVar1 + 1;
        } while (uVar1 < in_ECX[9]);
    }
    uVar1 = 0;
    if (in_ECX[3] != 0) {
        do {
            *(uint32_t*)((char*)in_ECX[1] + uVar1 * 4) = 0;
            uVar1 = uVar1 + 1;
        } while (uVar1 < in_ECX[3]);
    }
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    uVar1 = 0;
    if (in_ECX[9] != 0) {
        do {
            *(uint32_t*)((char*)in_ECX[7] + uVar1 * 4) = 0;
            uVar1 = uVar1 + 1;
        } while (uVar1 < in_ECX[9]);
    }
    in_ECX[9] = 0;
    in_ECX[10] = 0;
    in_ECX[6] = (uint32_t)PTR_FUN_006c50fc;
    operator_delete((void*)in_ECX[7]);
    in_ECX[0] = (uint32_t)PTR_FUN_006c50fc;
    operator_delete((void*)in_ECX[1]);
}

// 0x591150 — observed shape
void FUN_00591150(void* self_param) {
    char* in_ECX = (char*)self_param;
    if (*(int*)(in_ECX + 0xc) != 0) {
        uint32_t uVar3 = 0;
        do {
            int* piVar1 = *(int**)(*(int*)(*(int*)(*(int*)(*(int*)(in_ECX + 4) + uVar3 * 4) + 0xc) + 0xb0);
            if (piVar1 != nullptr) {
                int iVar2 = piVar1[1];
                piVar1[1] = iVar2 + 1;
                piVar1[1] = iVar2;
                if (iVar2 == 0) {
                    (*(void(__cdecl**)(int)))piVar1[0](1);
                }
                (*(void(__cdecl**)())(piVar1[0] + 0x38))();
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint32_t*)(in_ECX + 0xc));
    }
}

// 0x5911a0 — observed shape
uint32_t FUN_005911a0(void* self_param, uint32_t param_1) {
    char* in_ECX = (char*)self_param;
    uint32_t local_8 = 0;
    if (*(int*)(in_ECX + 0xc) != 0) {
        uint32_t local_4 = 1;
        do {
            int iVar1 = *(int*)(*(int*)(in_ECX + 4) + local_8 * 4);
            uint32_t* puVar2 = *(uint32_t**)(*(int*)(iVar1 + 0xc) + 0xb0);
            if (puVar2 == nullptr) {
LAB_00591201:
                uint32_t uVar6 = local_4;
                if (local_4 < *(uint32_t*)(in_ECX + 0xc)) {
                    do {
                        int iVar3 = *(int*)(*(int*)(in_ECX + 4) + uVar6 * 4);
                        puVar2 = *(uint32_t**)(*(int*)(iVar3 + 0xc) + 0xb0);
                        if (puVar2 == nullptr) {
LAB_0059123c:
                            char cVar5 = FUN_00596690(param_1, iVar1, iVar3);
                            if (cVar5 != '\0') return 1;
                        } else {
                            int iVar4 = (int)puVar2[1];
                            puVar2[1] = (uint32_t)(iVar4 + 1);
                            puVar2[1] = (uint32_t)iVar4;
                            if (iVar4 == 0) {
                                (*(void(__cdecl**)(int)))puVar2[0](1);
                            }
                            if ((puVar2[0xb] != 3) || (puVar2[10] == 2)) goto LAB_0059123c;
                        }
                        uVar6 = uVar6 + 1;
                    } while (uVar6 < *(uint32_t*)(in_ECX + 0xc));
                }
                uVar6 = 0;
                if (*(int*)(in_ECX + 0x24) != 0) {
                    do {
                        int iVar3 = *(int*)(*(int*)(in_ECX + 0x1c) + uVar6 * 4);
                        puVar2 = *(uint32_t**)(*(int*)(iVar3 + 0xc) + 0xb0);
                        if (puVar2 == nullptr) {
LAB_005912a6:
                            char cVar5 = FUN_00596690(param_1, iVar1, iVar3);
                            if (cVar5 != '\0') return 1;
                        } else {
                            int iVar4 = (int)puVar2[1];
                            puVar2[1] = (uint32_t)(iVar4 + 1);
                            puVar2[1] = (uint32_t)iVar4;
                            if (iVar4 == 0) {
                                (*(void(__cdecl**)(int)))puVar2[0](1);
                            }
                            if ((puVar2[0xb] != 3) || (puVar2[10] == 2)) goto LAB_005912a6;
                        }
                        uVar6 = uVar6 + 1;
                    } while (uVar6 < *(uint32_t*)(in_ECX + 0x24));
                }
            } else {
                int iVar3 = (int)puVar2[1];
                puVar2[1] = (uint32_t)(iVar3 + 1);
                puVar2[1] = (uint32_t)iVar3;
                if (iVar3 == 0) {
                    (*(void(__cdecl**)(int)))puVar2[0](1);
                }
                if ((puVar2[0xb] != 3) || (puVar2[10] == 2)) goto LAB_00591201;
            }
            local_8 = local_8 + 1;
            local_4 = local_4 + 1;
        } while (local_8 < *(uint32_t*)(in_ECX + 0xc));
    }
    return 0;
}

// 0x591670 — observed shape
uint32_t FUN_00591670(int param_1) {
    int iVar1 = param_1;
    (*(void(__cdecl**)(int*, int)))((*(int**)(param_1 + 0x15c)))[2];
// NOTE: pseudocode passes &param_1; model unaff_ESI as the second-stage index register.
    int unaff_ESI = 0;
// Original checks unaff_ESI bounds; preserve dispatch via DAT_00728ae8 table.
    void** table = (void**)DAT_00728ae8;
    if (unaff_ESI < 0 || 5 < unaff_ESI) return 0;
    uint32_t uVar2 = (*(uint32_t(__cdecl**)(int)))table[unaff_ESI](iVar1);
    return uVar2;
}

// 0x5916b0 — observed shape
void FUN_005916b0(void* self_param, int param_1) {
    int* in_ECX = (int*)self_param;
    uint32_t uStack_4 = (*(uint32_t(__cdecl**)())(in_ECX[0] + 0xc))();
    (*(void(__cdecl**)(uint32_t*, int)))((*(int**)(param_1 + 0x160))[3])(&uStack_4, 4);
}

// 0x591740 — observed shape
void FUN_00591740(void* self_param, uint32_t* param_1) {
    char* in_ECX = (char*)self_param;
    uint32_t uVar2 = param_1[0];
    uint32_t uVar3 = param_1[1];
    uint32_t uVar4 = param_1[2];
    float fVar5 = (float)FUN_00491640();
    float fVar1 = *(float*)&param_1[3];
    *(uint32_t*)(in_ECX + 4) = uVar2;
    *(uint32_t*)(in_ECX + 8) = uVar3;
    *(uint32_t*)(in_ECX + 0xc) = uVar4;
    *(float*)(in_ECX + 0x10) = fVar1 / fVar5;
}

// 0x5917a0 — observed shape
uint32_t FUN_005917a0(void* self_param, int* param_1) {
    char* in_ECX = (char*)self_param;
    int iVar2 = (*(int(__cdecl**)())(param_1[0] + 0xc))();
    if (iVar2 == 5) {
        char cVar1 = FUN_0059aac0(in_ECX + 4);
        if (cVar1 != '\0') return 1;
    }
    return 0;
}

// 0x5917e0 — observed shape
void FUN_005917e0(void* self_param, int param_1, int param_2) {
    char* in_ECX = (char*)self_param;
    float local_c, local_8, local_4;
    FUN_0053ca60(&local_c, param_1 + 4);
    float fVar1 = *(float*)(param_2 + 0x30);
    float fVar2 = *(float*)(param_1 + 0x10);
    float fVar3 = *(float*)(param_2 + 0x28);
    float fVar4 = *(float*)(param_2 + 0x2c);
    float fVar5 = *(float*)(param_2 + 0x24);
    *(float*)(in_ECX + 4) = local_c;
    *(float*)(in_ECX + 8) = local_8;
    *(float*)(in_ECX + 0xc) = local_4;
    *(float*)(in_ECX + 0x10) = local_c * fVar5 + local_4 * fVar4 + local_8 * fVar3 + fVar1 * fVar2;
}

// 0x5918f0 — observed shape
uint32_t FUN_005918f0(float param_1, int param_2, float* param_3, int param_4, float* param_5) {
    float fVar2 = (*(float*)(param_4 + 4) * *(float*)(param_2 + 4) +
                   *(float*)(param_4 + 0xc) * *(float*)(param_2 + 0xc) +
                   *(float*)(param_4 + 8) * *(float*)(param_2 + 8)) - *(float*)(param_2 + 0x10);
    float fVar1 = -(fabsf((*(float*)(param_4 + 0x10) * *(float*)(param_2 + 4) +
                          *(float*)(param_4 + 0x18) * *(float*)(param_2 + 0xc) +
                          *(float*)(param_4 + 0x14) * *(float*)(param_2 + 8)) * *(float*)(param_4 + 0x34))
                    + fabsf((*(float*)(param_4 + 0x1c) * *(float*)(param_2 + 4) +
                             *(float*)(param_4 + 0x24) * *(float*)(param_2 + 0xc) +
                             *(float*)(param_4 + 0x20) * *(float*)(param_2 + 8)) * *(float*)(param_4 + 0x38))
                    + fabsf((*(float*)(param_4 + 0x28) * *(float*)(param_2 + 4) +
                             *(float*)(param_4 + 0x30) * *(float*)(param_2 + 0xc) +
                             *(float*)(param_4 + 0x2c) * *(float*)(param_2 + 8)) *
                            *(float*)(param_4 + 0x3c)));
    if (fVar2 >= fVar1) {
        return (uint32_t)((fVar2 < fVar1) ? 1 : 1);
    }
    float fVar3 = (param_5[2] - param_3[2]) * *(float*)(param_2 + 0xc) +
                  (param_5[0] - param_3[0]) * *(float*)(param_2 + 4) +
                  (param_5[1] - param_3[1]) * *(float*)(param_2 + 8);
    if (!std::isnan(fVar3) && ((fVar3 < 0.0f) != (fVar3 == 0.0f))) {
        return (uint32_t)(uint16_t)((uint16_t)(fVar3 < 0.0f) << 8 | (uint16_t)std::isnan(fVar3) << 10 | (uint16_t)(fVar3 == 0.0f) << 0xe);
    }
    if (fVar1 <= param_1 * fVar3 + fVar2) return 1;
    return 0;
}

// 0x591b80 — observed shape
uint32_t FUN_00591b80(float param_1, int param_2, float* param_3, float* param_4, float* param_5,
                      float* param_6, float* param_7) {
    float fVar1 = (param_4[0] * *(float*)(param_2 + 4) +
                   param_4[1] * *(float*)(param_2 + 8) + param_4[2] * *(float*)(param_2 + 0xc)) -
                  *(float*)(param_2 + 0x10);
    uint32_t uVar5 = (uint32_t)(uint16_t)((uint16_t)(fVar1 < 0.0f) << 8 | (uint16_t)std::isnan(fVar1) << 10 | (uint16_t)(fVar1 == 0.0f) << 0xe);
    if (fVar1 < 0.0f) {
        float fVar2 = (param_5[0] * *(float*)(param_2 + 4) +
                       param_5[1] * *(float*)(param_2 + 8) + param_5[2] * *(float*)(param_2 + 0xc)) -
                      *(float*)(param_2 + 0x10);
        uVar5 = (uint32_t)(uint16_t)((uint16_t)(fVar2 < 0.0f) << 8 | (uint16_t)std::isnan(fVar2) << 10 | (uint16_t)(fVar2 == 0.0f) << 0xe);
        if (fVar2 < 0.0f) {
            float fVar3 = (param_6[0] * *(float*)(param_2 + 4) +
                           param_6[1] * *(float*)(param_2 + 8) + param_6[2] * *(float*)(param_2 + 0xc)) -
                          *(float*)(param_2 + 0x10);
            uVar5 = (uint32_t)(uint16_t)((uint16_t)(fVar3 < 0.0f) << 8 | (uint16_t)std::isnan(fVar3) << 10 | (uint16_t)(fVar3 == 0.0f) << 0xe);
            if (fVar3 < 0.0f) {
                float fVar4 = (param_7[1] - param_3[1]) * *(float*)(param_2 + 8) +
                              (param_7[0] - param_3[0]) * *(float*)(param_2 + 4) +
                              (param_7[2] - param_3[2]) * *(float*)(param_2 + 0xc);
                if (!std::isnan(fVar4) && ((fVar4 < 0.0f) != (fVar4 == 0.0f))) {
                    return (uint32_t)(uint16_t)((uint16_t)(fVar4 < 0.0f) << 8 | (uint16_t)std::isnan(fVar4) << 10 | (uint16_t)(fVar4 == 0.0f) << 0xe);
                }
                fVar4 = -(fVar4 * param_1);
                if ((fVar1 < fVar4) && (fVar2 < fVar4) && (fVar3 < fVar4)) return 0;
                return 1;
            }
        }
    }
    return (uint32_t)((uVar5 >> 8) | 1);
}

// ---- helpers referenced by the 0x591xxx/0x593xxx cluster ----
extern void FUN_0058fca0(uint32_t param_1, void* param_2);
extern uint32_t DAT_00727430;
extern void* FUN_00431450(void* out, float t, float* in, ...);
extern void* FUN_00431480(void* out, uint32_t param_1);
extern void* FUN_00497ca0(void* a, void* b);
extern void FUN_00558050(void);
extern void* thunk_FUN_00533c78(int size);
extern void* FUN_00533c78(uint32_t size);
extern void FUN_006b34a0(uint32_t p);
extern void FUN_005606f0(uint32_t index, char** out);
extern void* PTR_LAB_006c5104;
extern void* PTR_LAB_006c514c;
extern void* PTR_FUN_006c5148;
extern "C" int sprintf(char* buffer, const char* format, ...);

// 0x591ca0 — observed shape
uint32_t FUN_00591ca0(float param_1, int param_2, float* param_3, int param_4, float* param_5,
                      float* param_6, float* param_7, char param_8, float* param_9, float* param_10) {
    float* pfVar9 = (float*)(param_2 + 4);
    float fVar8 = (*pfVar9 * *(float*)(param_4 + 4) +
                   *(float*)(param_4 + 8) * *(float*)(param_2 + 8) +
                   *(float*)(param_4 + 0xc) * *(float*)(param_2 + 0xc)) - *(float*)(param_2 + 0x10);
    float fVar1 = -*(float*)(param_4 + 0x10);
    if (fVar1 <= fVar8) {
        *param_6 = 0.0f;
        float fVar2 = *(float*)(param_2 + 8);
        float fVar3 = *(float*)(param_4 + 8);
        float fVar4 = *(float*)(param_4 + 0xc) - fVar8 * *(float*)(param_2 + 0xc);
        *param_7 = *(float*)(param_4 + 4) - fVar8 * *pfVar9;
        param_7[1] = fVar3 - fVar8 * fVar2;
        param_7[2] = fVar4;
        if (param_8 != '\0') {
            *param_10 = *pfVar9;
            param_10[1] = *(float*)(param_2 + 8);
            param_10[2] = *(float*)(param_2 + 0xc);
            float fVar5 = param_10[1];
            float fVar6 = param_10[2];
            *param_9 = -*param_10;
            fVar6 = -fVar6;
            param_9[1] = -fVar5;
            param_9[2] = fVar6;
        }
        return 1;
    }
    float fVar2 = (param_5[2] - param_3[2]) * *(float*)(param_2 + 0xc) +
                  (param_5[1] - param_3[1]) * *(float*)(param_2 + 8) +
                  (*param_5 - *param_3) * *pfVar9;
    uint16_t uVar10 = (uint16_t)((uint16_t)(fVar2 < 0.0f) << 8 |
                                 (uint16_t)std::isnan(fVar2) << 10 |
                                 (uint16_t)(fVar2 == 0.0f) << 0xe);
    if (std::isnan(fVar2) || ((fVar2 < 0.0f) == (fVar2 == 0.0f))) {
        float fVar3 = fVar2 * param_1 + fVar8;
        if (fVar3 >= fVar1) {
            *param_6 = (-1.0f / fVar2) * (fVar8 + *(float*)(param_4 + 0x10));
            if (param_8 != '\0') {
                *param_10 = *pfVar9;
                param_10[1] = *(float*)(param_2 + 8);
                param_10[2] = *(float*)(param_2 + 0xc);
                float fVar4 = param_10[1];
                float fVar5 = param_10[2];
                *param_9 = -*param_10;
                param_9[1] = -fVar4;
                param_9[2] = -fVar5;
            }
            float fVar6 = *(float*)(param_4 + 0x10);
            float f1 = param_10[1];
            float f2 = param_10[2];
            float f3 = *param_6;
            float f4 = param_5[1];
            float f5 = param_5[2];
            float f7 = *(float*)(param_4 + 8);
            float f8 = *(float*)(param_4 + 0xc);
            *param_7 = f3 * *param_5 + *(float*)(param_4 + 4) + fVar6 * *param_10;
            param_7[1] = f3 * f4 + f7 + fVar6 * f1;
            f8 = f3 * f5 + f8 + fVar6 * f2;
            param_7[2] = f8;
            return 1;
        }
    }
    return (uint32_t)uVar10;
}

// 0x591f00 — observed shape
uint32_t FUN_00591f00(float param_1, int param_2, float* param_3, int param_4, float* param_5,
                      float* param_6, float* param_7, char param_8, float* param_9, float* param_10) {
    float* pfVar12 = (float*)(param_2 + 4);
    float fVar1 = (*pfVar12 * *(float*)(param_4 + 0x10) +
                   *(float*)(param_4 + 0x18) * *(float*)(param_2 + 0xc) +
                   *(float*)(param_4 + 0x14) * *(float*)(param_2 + 8)) * *(float*)(param_4 + 0x34);
    float fVar2 = (*pfVar12 * *(float*)(param_4 + 0x1c) +
                   *(float*)(param_4 + 0x24) * *(float*)(param_2 + 0xc) +
                   *(float*)(param_4 + 0x20) * *(float*)(param_2 + 8)) * *(float*)(param_4 + 0x38);
    float fVar3 = (*(float*)(param_4 + 0x28) * *pfVar12 +
                   *(float*)(param_4 + 0x30) * *(float*)(param_2 + 0xc) +
                   *(float*)(param_4 + 0x2c) * *(float*)(param_2 + 8)) * *(float*)(param_4 + 0x3c);
    float fVar4 = fabsf(fVar3);
    float fVar10 = fabsf(fVar2);
    float fVar9 = fabsf(fVar1);
    float fVar5 = fVar9 + fVar10 + fVar4;
    float fVar6 = (*pfVar12 * *(float*)(param_4 + 4) +
                   *(float*)(param_4 + 0xc) * *(float*)(param_2 + 0xc) +
                   *(float*)(param_4 + 8) * *(float*)(param_2 + 8)) - *(float*)(param_2 + 0x10);
    float fVar7 = -fVar5;
    if (fVar7 <= fVar6) {
        *param_6 = 0.0f;
        fVar1 = *(float*)(param_2 + 8);
        fVar2 = *(float*)(param_2 + 0xc);
        fVar3 = *(float*)(param_4 + 8);
        fVar4 = *(float*)(param_4 + 0xc);
        *param_7 = *(float*)(param_4 + 4) - fVar6 * *pfVar12;
        param_7[1] = fVar3 - fVar6 * fVar1;
        param_7[2] = fVar4 - fVar6 * fVar2;
        if (param_8 != '\0') {
            *param_10 = *pfVar12;
            param_10[1] = *(float*)(param_2 + 8);
            param_10[2] = *(float*)(param_2 + 0xc);
            float t1 = param_10[1];
            float t2 = param_10[2];
            *param_9 = -*param_10;
            param_9[1] = -t1;
            param_9[2] = -t2;
        }
        return 1;
    }
    float fVar8 = (param_5[1] - param_3[1]) * *(float*)(param_2 + 8) +
                  (*param_5 - *param_3) * *pfVar12 +
                  (param_5[2] - param_3[2]) * *(float*)(param_2 + 0xc);
    if (std::isnan(fVar8) || ((fVar8 < 0.0f) == (fVar8 == 0.0f))) {
        if (fVar7 <= fVar8 * param_1 + fVar6) {
            float fVar11 = (-1.0f / fVar8) * (fVar6 + fVar5);
            *param_6 = fVar11;
            fVar5 = param_5[1];
            fVar6 = param_5[2];
            fVar7 = *(float*)(param_4 + 8);
            fVar8 = *(float*)(param_4 + 0xc);
            *param_7 = fVar11 * *param_5 + *(float*)(param_4 + 4);
            param_7[1] = fVar11 * fVar5 + fVar7;
            param_7[2] = fVar11 * fVar6 + fVar8;
            if (0.001f < fVar9) {
                fVar9 = *(float*)(param_4 + 0x34);
                fVar6 = fVar9 * *(float*)(param_4 + 0x10);
                fVar5 = fVar9 * *(float*)(param_4 + 0x14);
                if (fVar1 <= 0.0f) {
                    fVar1 = *(float*)(param_4 + 0x18);
                    *param_7 = *param_7 - fVar6;
                    param_7[1] = param_7[1] - fVar5;
                    fVar1 = param_7[2] - fVar9 * fVar1;
                } else {
                    fVar1 = *(float*)(param_4 + 0x18);
                    *param_7 = fVar6 + *param_7;
                    param_7[1] = fVar5 + param_7[1];
                    fVar1 = fVar9 * fVar1 + param_7[2];
                }
                param_7[2] = fVar1;
            }
            if (0.001f < fVar10) {
                fVar1 = *(float*)(param_4 + 0x38);
                fVar9 = fVar1 * *(float*)(param_4 + 0x1c);
                fVar10 = fVar1 * *(float*)(param_4 + 0x20);
                if (fVar2 <= 0.0f) {
                    fVar2 = *(float*)(param_4 + 0x24);
                    *param_7 = *param_7 - fVar9;
                    param_7[1] = param_7[1] - fVar10;
                    fVar1 = param_7[2] - fVar1 * fVar2;
                } else {
                    fVar2 = *(float*)(param_4 + 0x24);
                    *param_7 = fVar9 + *param_7;
                    param_7[1] = fVar10 + param_7[1];
                    fVar1 = fVar1 * fVar2 + param_7[2];
                }
                param_7[2] = fVar1;
            }
            if (0.001f < fVar4) {
                fVar1 = *(float*)(param_4 + 0x3c);
                fVar4 = fVar1 * *(float*)(param_4 + 0x28);
                fVar2 = fVar1 * *(float*)(param_4 + 0x2c);
                if (fVar3 <= 0.0f) {
                    fVar3 = *(float*)(param_4 + 0x30);
                    *param_7 = *param_7 - fVar4;
                    param_7[1] = param_7[1] - fVar2;
                    fVar1 = param_7[2] - fVar1 * fVar3;
                } else {
                    fVar3 = *(float*)(param_4 + 0x30);
                    *param_7 = fVar4 + *param_7;
                    param_7[1] = fVar2 + param_7[1];
                    fVar1 = fVar1 * fVar3 + param_7[2];
                }
                param_7[2] = fVar1;
            }
            if (param_8 != '\0') {
                fVar1 = *(float*)(param_2 + 8);
                fVar2 = *(float*)(param_2 + 0xc);
                *param_9 = -*pfVar12;
                param_9[1] = -fVar1;
                param_9[2] = -fVar2;
                fVar1 = param_7[1];
                fVar2 = *(float*)(param_4 + 8);
                fVar3 = param_7[2];
                fVar4 = *(float*)(param_4 + 0xc);
                *param_10 = *param_7 - *(float*)(param_4 + 4);
                param_10[1] = fVar1 - fVar2;
                param_10[2] = fVar3 - fVar4;
            }
            return 1;
        }
    }
    return 0;
}

// 0x592330 — observed shape
uint32_t FUN_00592330(float param_1, int param_2, float* param_3, int param_4, float* param_5,
                      float* param_6, float* param_7, uint32_t param_8, float* param_9,
                      float* param_10) {
    float* pfVar10 = (float*)(param_2 + 4);
    float* pfVar9 = (float*)(param_4 + 0x20);
    float* pfVar1 = (float*)(param_4 + 0x2c);
    float fVar6 = (*pfVar9 * *pfVar10 +
                   *(float*)(param_2 + 8) * *(float*)(param_4 + 0x24) +
                   *(float*)(param_2 + 0xc) * *(float*)(param_4 + 0x28)) - *(float*)(param_2 + 0x10);
    float fVar2 = ((*(float*)(param_4 + 0x34) + *(float*)(param_4 + 0x28)) * *(float*)(param_2 + 0xc) +
                   (*pfVar9 + *pfVar1) * *pfVar10 +
                   (*(float*)(param_4 + 0x30) + *(float*)(param_4 + 0x24)) *
                       *(float*)(param_2 + 8)) -
                  *(float*)(param_2 + 0x10);
    float local_44[6];
    uint8_t local_2c[12];
    uint8_t local_20[12];
    float local_14[5];
    if (((fVar6 < 0.0f) && (0.0f < fVar2)) || ((0.0f < fVar6) && (fVar2 < 0.0f))) {
        *param_6 = 0.0f;
        fVar6 = fVar6 / (fVar6 - fVar2);
        float fVar3 = *(float*)(param_4 + 0x30);
        float fVar4 = *(float*)(param_4 + 0x34);
        float fVar5 = *(float*)(param_4 + 0x24);
        float fVar2b = *(float*)(param_4 + 0x28);
        *param_7 = fVar6 * *pfVar1 + *pfVar9;
        param_7[1] = fVar6 * fVar3 + fVar5;
        param_7[2] = fVar6 * fVar4 + fVar2b;
        if ((char)param_8 != '\0') {
            *param_10 = *pfVar10;
            param_10[1] = *(float*)(param_2 + 8);
            param_10[2] = *(float*)(param_2 + 0xc);
            float t1 = param_10[1];
            float t2 = param_10[2];
            *param_9 = -*param_10;
            param_9[1] = -t1;
            param_9[2] = -t2;
            return 1;
        }
    } else {
        if (-*(float*)(param_4 + 0x38) <= fVar6) {
            *param_6 = 0.0f;
            FUN_0058fca0(0x3f800000, &DAT_00727430);
            local_14[4] = *(float*)(param_4 + 0x38);
            float fVar6b = -*(float*)(param_4 + 0x38);
            if (std::isnan(fVar6b) || std::isnan(fVar2) ||
                ((fVar6b < fVar2) == (fVar6b == fVar2))) {
                local_14[1] = *pfVar9;
                local_14[2] = *(float*)(param_4 + 0x24);
                local_14[3] = *(float*)(param_4 + 0x28);
                return FUN_00591ca0(param_1, param_2, param_3, (int)(intptr_t)local_14, param_5,
                                    param_6, param_7, (char)param_8, param_9, param_10);
            }
            local_14[1] = *(float*)(param_4 + 4);
            local_14[2] = *(float*)(param_4 + 8);
            local_14[3] = *(float*)(param_4 + 0xc);
            return FUN_00591ca0(param_1, param_2, param_3, (int)(intptr_t)local_14, param_5,
                                param_6, param_7, (char)param_8, param_9, param_10);
        }
        if (-*(float*)(param_4 + 0x38) <= fVar2) {
            *param_6 = 0.0f;
            FUN_0058fca0(0x3f800000, &DAT_00727430);
            local_44[0] = *(float*)(param_4 + 0x2c) + *pfVar9;
            local_14[4] = *(float*)(param_4 + 0x38);
            local_44[1] = *(float*)(param_4 + 0x30) + *(float*)(param_4 + 0x24);
            local_44[2] = *(float*)(param_4 + 0x34) + *(float*)(param_4 + 0x28);
            local_14[1] = local_44[0];
            local_14[2] = local_44[1];
            local_14[3] = local_44[2];
            return FUN_00591ca0(param_1, param_2, param_3, (int)(intptr_t)local_14, param_5,
                                param_6, param_7, (char)param_8, param_9, param_10);
        }
        float fVar3 = (param_5[1] - param_3[1]) * *(float*)(param_2 + 8) +
                      (*param_5 - *param_3) * *pfVar10 +
                      (param_5[2] - param_3[2]) * *(float*)(param_2 + 0xc);
        float fVar4 = 0.0f;
        if ((!std::isnan(fVar3) && ((fVar3 < 0.0f) != (fVar3 == 0.0f))) ||
            ((fVar4 = -(fVar3 * param_1 + *(float*)(param_4 + 0x38)),
              fVar6 < fVar4 && (fVar2 < fVar4)))) {
            return 0;
        }
        if (fVar6 <= fVar2 + 1e-06f) {
            fVar3 = -((fVar2 + *(float*)(param_4 + 0x38)) / fVar3);
            if (fVar2 <= fVar6 + 1e-06f) {
                *param_6 = fVar3;
                local_44[5] = *(float*)(param_4 + 0x34) * 0.5f;
                local_44[0] = *pfVar1 * 0.5f + *pfVar9;
                local_44[1] = *(float*)(param_4 + 0x30) * 0.5f + *(float*)(param_4 + 0x24);
                local_44[2] = local_44[5] + *(float*)(param_4 + 0x28);
                pfVar9 = (float*)FUN_00431450(local_14, fVar3, param_5);
                local_44[3] = local_44[0] + *pfVar9;
                local_44[4] = local_44[1] + pfVar9[1];
                local_44[5] = local_44[2] + pfVar9[2];
                pfVar9 = (float*)FUN_00431480(local_20, *(uint32_t*)(param_4 + 0x38));
                float t1 = pfVar9[1];
                float t2 = pfVar9[2];
                *param_7 = local_44[3] + *pfVar9;
                param_7[1] = local_44[4] + t1;
                param_7[2] = local_44[5] + t2;
            } else {
                *param_6 = fVar3;
                void* uVar7 = FUN_00431480(local_20, *(uint32_t*)(param_4 + 0x38));
                void* uVar8 = FUN_00431450(&local_44[3], fVar3, param_5, local_2c, uVar7);
                pfVar9 = local_44;
                FUN_00497ca0(local_14, pfVar1);
                FUN_00497ca0(pfVar9, uVar8);
                pfVar9 = (float*)FUN_00497ca0(local_2c, uVar7);
                *param_7 = *pfVar9;
                param_7[1] = pfVar9[1];
                param_7[2] = pfVar9[2];
            }
        } else {
            fVar6 = -((fVar6 + *(float*)(param_4 + 0x38)) / fVar3);
            *param_6 = fVar6;
            void* uVar7 = FUN_00431480(&local_44[3], *(uint32_t*)(param_4 + 0x38));
            pfVar9 = local_44;
            void* uVar8 = FUN_00431450(local_2c, fVar6, param_5, pfVar9, uVar7);
            FUN_00497ca0(local_20, uVar8);
            pfVar9 = (float*)FUN_00497ca0(pfVar9, uVar7);
            *param_7 = *pfVar9;
            param_7[1] = pfVar9[1];
            param_7[2] = pfVar9[2];
        }
        if ((char)param_8 != '\0') {
            *param_10 = *pfVar10;
            param_10[1] = *(float*)(param_2 + 8);
            param_10[2] = *(float*)(param_2 + 0xc);
            float t1 = param_10[1];
            float t2 = param_10[2];
            *param_9 = -*param_10;
            param_9[1] = -t1;
            param_9[2] = -t2;
        }
    }
    return 1;
}

// 0x5928e0 — observed shape
uint16_t FUN_005928e0(float param_1, int param_2, float* param_3, int param_4, float* param_5,
                      float* param_6, float* param_7, char param_8, float* param_9,
                      float* param_10) {
    float* pfVar7 = (float*)(param_4 + 4);
    float* pfVar6 = (float*)(param_2 + 4);
    float fVar8 = *(float*)(param_2 + 8) * *(float*)(param_4 + 8) +
                  *(float*)(param_2 + 0xc) * *(float*)(param_4 + 0xc) +
                  *(float*)(param_4 + 4) * *(float*)(param_2 + 4);
    float fVar1 = 0.0f, fVar2 = 0.0f, fVar3 = 0.0f, fVar4 = 0.0f, fVar5 = 0.0f;
    if (-0.999999f < fVar8) {
        fVar4 = 1.0f / (1.0f - fVar8 * fVar8);
        fVar5 = (*(float*)(param_2 + 0x10) - fVar8 * *(float*)(param_4 + 0x10)) * fVar4;
        fVar1 = *(float*)(param_2 + 0x10);
        fVar2 = *(float*)(param_4 + 0x10);
        *param_6 = 0.0f;
        fVar4 = (fVar2 - fVar8 * fVar1) * fVar4;
        float f8a = *(float*)(param_4 + 8);
        float f1a = *(float*)(param_4 + 0xc);
        float f2a = *(float*)(param_2 + 8);
        float f3a = *(float*)(param_2 + 0xc);
        *param_7 = fVar5 * *pfVar6 + fVar4 * *pfVar7;
        param_7[1] = fVar5 * f2a + fVar4 * f8a;
        param_7[2] = fVar5 * f3a + fVar4 * f1a;
        if (param_8 != '\0') {
            f8a = *(float*)(param_2 + 8);
            f1a = *(float*)(param_2 + 0xc);
            *param_9 = -*pfVar6;
            param_9[1] = -f8a;
            param_9[2] = -f1a;
            f8a = *(float*)(param_4 + 8);
            f1a = *(float*)(param_4 + 0xc);
            *param_10 = -*pfVar7;
            param_10[1] = -f8a;
            param_10[2] = -f1a;
        }
        return 1;
    }
    if (*(float*)(param_2 + 0x10) <= -*(float*)(param_4 + 0x10)) {
        *param_6 = 0.0f;
        fVar2 = *(float*)(param_2 + 0x10) - *(float*)(param_4 + 0x10);
        fVar1 = *(float*)(param_2 + 8);
        fVar8 = fVar2 * *(float*)(param_2 + 0xc);
        *param_7 = fVar2 * *pfVar6;
        param_7[1] = fVar2 * fVar1;
LAB_00592a78:
        param_7[2] = fVar8;
        if (param_8 != '\0') {
            *param_10 = *pfVar6;
            param_10[1] = *(float*)(param_2 + 8);
            param_10[2] = *(float*)(param_2 + 0xc);
            *param_9 = *pfVar7;
            param_9[1] = *(float*)(param_4 + 8);
            param_9[2] = *(float*)(param_4 + 0xc);
        }
        return 1;
    }
    fVar8 = (param_5[2] - param_3[2]) * *(float*)(param_2 + 0xc) +
            (*param_5 - *param_3) * *pfVar6 +
            (param_5[1] - param_3[1]) * *(float*)(param_2 + 8);
    if (std::isnan(fVar8) || ((fVar8 < 0.0f) == (fVar8 == 0.0f))) {
        if (*(float*)(param_2 + 0x10) <= fVar8 * param_1 - *(float*)(param_4 + 0x10)) {
            fVar8 = (*(float*)(param_4 + 0x10) + *(float*)(param_2 + 0x10)) / fVar8;
            *param_6 = fVar8;
            fVar1 = param_3[1];
            fVar2 = param_3[2];
            fVar3 = *(float*)(param_2 + 0x10);
            fVar4 = *(float*)(param_2 + 8);
            fVar5 = *(float*)(param_2 + 0xc);
            *param_7 = fVar3 * *pfVar6 + fVar8 * *param_3;
            param_7[1] = fVar3 * fVar4 + fVar8 * fVar1;
            fVar8 = fVar3 * fVar5 + fVar8 * fVar2;
            goto LAB_00592a78;
        }
    }
    return 0;
}

// 0x592ec0 — observed shape
void FUN_00592ec0(void* self_param, float* param_1, float* param_2) {
    uint32_t* in_ECX = (uint32_t*)self_param;
    float* fSelf = (float*)self_param;
    in_ECX[0] = (uint32_t)(uintptr_t)&PTR_LAB_006c5104;
    FUN_00558050();
    fSelf[5] = *param_1;
    fSelf[6] = param_1[1];
    fSelf[7] = param_1[2];
    FUN_00558050();
    float fVar1 = param_1[2];
    float fVar2 = param_2[2];
    float fVar7 = *param_2;
    float fVar3 = param_1[1];
    float fVar8 = param_2[1];
    float fVar4 = param_2[1];
    float fVar9 = param_2[2];
    float fVar5 = *param_1;
    float fVar6 = *param_2;
    float fVar10 = (float)FUN_00491640();
    fSelf[1] = fVar7;
    fSelf[2] = fVar8;
    fSelf[3] = fVar9;
    fSelf[4] = (fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2) / fVar10;
}

// 0x593030 — observed shape
void FUN_00593030(char* param_1, int param_2) {
    char* pcVar3 = param_1;
    char* pcVar4 = param_1;
    char cVar1;
    do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    param_1 = (char*)thunk_FUN_00533c78(
        (int)(intptr_t)(pcVar4 + (0x10 - (int)(intptr_t)(param_1 + 1))));
    sprintf(param_1, "%s = HALFSPACE_BV", pcVar3);
    uint32_t uVar2 = *(uint32_t*)(param_2 + 0xc);
    if (*(uint32_t*)(param_2 + 8) <= uVar2) {
        FUN_006b34a0(*(uint32_t*)(param_2 + 0x14) + uVar2);
    }
    FUN_005606f0(uVar2, &param_1);
}

// 0x5930d0 — observed shape
// Returns the constructed object: the caller at 0x593220 consumes EAX after the
// register-based construction call.
void* FUN_005930d0(void* self_param) {
    uint32_t* in_ECX = (uint32_t*)self_param;
    in_ECX[0] = (uint32_t)(uintptr_t)&PTR_LAB_006c514c;
    in_ECX[1] = (uint32_t)(uintptr_t)&PTR_FUN_006c5148;
    in_ECX[3] = 2;
    in_ECX[6] = 1;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    uint32_t uVar1 = (uint32_t)(uintptr_t)thunk_FUN_00533c78(8);
    in_ECX[2] = uVar1;
    in_ECX[7] = 0;
    return self_param;
}

// 0x593120 — observed shape
void FUN_00593120(void* self_param, int param_1) {
    int* in_ECX = (int*)self_param;
    int iVar3 = 0;
    in_ECX[0] = (int)(intptr_t)&PTR_LAB_006c514c;
    in_ECX[1] = (int)(intptr_t)&PTR_FUN_006c5148;
    in_ECX[3] = 0;
    in_ECX[6] = 1;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    in_ECX[2] = 0;
    FUN_006b34a0(*(uint32_t*)(param_1 + 0x10));
    uint32_t uVar4 = 0;
    if (in_ECX[4] != 0) {
        do {
            int* piVar1 = *(int**)(*(int*)(param_1 + 8) + uVar4 * 4);
            if (piVar1 != nullptr) {
                int iVar2 = ((int(__cdecl*)(void*))(*(uint32_t*)(intptr_t)(*piVar1 + 0x1c)))(
                    piVar1);
                if (uVar4 < (uint32_t)in_ECX[3]) {
                    if (uVar4 < (uint32_t)in_ECX[4]) {
                        if (iVar2 == 0) {
                            if (*(int*)(in_ECX[2] + uVar4 * 4) != 0) {
                                iVar3 = in_ECX[5] + -1;
                                goto LAB_005931ad;
                            }
                        } else if (*(int*)(in_ECX[2] + uVar4 * 4) == 0) {
                            iVar3 = in_ECX[5] + 1;
LAB_005931ad:
                            in_ECX[5] = iVar3;
                        }
                    } else {
                        in_ECX[4] = (int)(uVar4 + 1);
                        if (iVar2 != 0) {
                            iVar3 = in_ECX[5] + 1;
                            goto LAB_005931ad;
                        }
                    }
                    *(int*)(in_ECX[2] + uVar4 * 4) = iVar2;
                }
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < (uint32_t)in_ECX[4]);
    }
}

// 0x5931d0 — observed shape
void FUN_005931d0(void* self_param) {
    char* in_ECX = (char*)self_param;
    uint32_t uVar2 = 0;
    if (*(int*)(in_ECX + 0x10) != 0) {
        do {
            int* piVar1 = *(int**)(*(int*)(in_ECX + 8) + uVar2 * 4);
            if (piVar1 != nullptr) {
                ((void(__cdecl*)(int))(*(uint32_t*)(intptr_t)(*piVar1 + 8)))(1);
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint32_t*)(in_ECX + 0x10));
    }
    uVar2 = 0;
    if (*(int*)(in_ECX + 0x10) != 0) {
        do {
            *(uint32_t*)(*(int*)(in_ECX + 8) + uVar2 * 4) = 0;
            uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint32_t*)(in_ECX + 0x10));
    }
    *(uint32_t*)(in_ECX + 0x10) = 0;
    *(uint32_t*)(in_ECX + 0x14) = 0;
}

// 0x593220 — observed shape
int FUN_00593220(void* self_param) {
    char* in_ECX = (char*)self_param;
    int iVar1;
    int iVar3 = 0;
    void* pAlloc = FUN_00533c78(0x20);
    if (pAlloc == nullptr) {
        iVar1 = 0;
    } else {
        iVar1 = (int)(intptr_t)FUN_005930d0(pAlloc);
    }
    FUN_006b34a0(*(uint32_t*)(in_ECX + 0x10));
    uint32_t uVar4 = 0;
    if (*(int*)(in_ECX + 0x10) != 0) {
        do {
            int* pObj = *(int**)(*(int*)(in_ECX + 8) + uVar4 * 4);
            int iVar2 =
                ((int(__cdecl*)(void*))(*(uint32_t*)(intptr_t)(*pObj + 0x18)))(pObj);
            if (uVar4 < *(uint32_t*)(iVar1 + 0xc)) {
                if (uVar4 < *(uint32_t*)(iVar1 + 0x10)) {
                    if (iVar2 == 0) {
                        if (*(int*)(*(int*)(iVar1 + 8) + uVar4 * 4) != 0) {
                            iVar3 = *(int*)(iVar1 + 0x14) + -1;
                            goto LAB_0059329d;
                        }
                    } else if (*(int*)(*(int*)(iVar1 + 8) + uVar4 * 4) == 0) {
                        iVar3 = *(int*)(iVar1 + 0x14) + 1;
LAB_0059329d:
                        *(int*)(iVar1 + 0x14) = iVar3;
                    }
                } else {
                    *(uint32_t*)(iVar1 + 0x10) = uVar4 + 1;
                    if (iVar2 != 0) {
                        iVar3 = *(int*)(iVar1 + 0x14) + 1;
                        goto LAB_0059329d;
                    }
                }
                *(int*)(*(int*)(iVar1 + 8) + uVar4 * 4) = iVar2;
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < *(uint32_t*)(in_ECX + 0x10));
    }
    return iVar1;
}
