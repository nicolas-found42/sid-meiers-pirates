#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_005f8d40(int param_1);
extern void* PTR_FUN_00718808;
extern void* _DAT_0071882c;
extern void* _DAT_0071881c;
extern void* _DAT_00718900;
extern void* _DAT_00718824;
extern void* PTR_FUN_007188d4;
extern void* PTR_FUN_007188d8;
extern void* PTR_FUN_0071880c;
extern void* _DAT_00718904;
extern void* _DAT_00718830;
extern void* _DAT_00718908;
extern void* _DAT_00718820;
extern void* _DAT_0071890c;
extern void* PTR_FUN_00718844;
extern void* _DAT_00718828;
extern void* PTR_FUN_007188e0;

// 0x5f1375 — observed shape
void FUN_005f1375(void) {
    FUN_005f8d40(1);
    ((void (*)())PTR_FUN_00718808)();
}

// 0x5f13a1 — observed shape
void FUN_005f13a1(void) {
    FUN_005f8d40(1);
    ((void (*)())_DAT_0071882c)();
}

// 0x5f13cd — observed shape
void FUN_005f13cd(void) {
    FUN_005f8d40(1);
    ((void (*)())_DAT_0071881c)();
}

// 0x5f1424 — observed shape
void FUN_005f1424(void) {
    FUN_005f8d40(1);
    ((void (*)())_DAT_00718900)();
}

// 0x5f148d — observed shape
void FUN_005f148d(void) {
    FUN_005f8d40(1);
    ((void (*)())_DAT_00718824)();
}
// 0x5f14d2 — observed shape
void FUN_005f14d2(float* param_1, float* param_2, float* param_3, float* param_4, float* param_5, float param_6) {
    float fVar1;
    float fVar2;
    float fVar3;
    float fVar4;
    fVar1 = param_6 * param_6;
    fVar2 = param_6 * fVar1;
    fVar4 = ((fVar2 + fVar2) - fVar1 * 3.0f) + 1.0f;
    param_6 = (fVar2 - (fVar1 + fVar1)) + param_6;
    fVar3 = fVar1 * 3.0f - (fVar2 + fVar2);
    fVar2 = fVar2 - fVar1;
    *param_1 = fVar2 * *param_5 + fVar3 * *param_4 + param_6 * *param_3 + fVar4 * *param_2;
    param_1[1] = fVar4 * param_2[1] + param_6 * param_3[1] + fVar3 * param_4[1] + fVar2 * param_5[1];
    param_1[2] = fVar4 * param_2[2] + param_6 * param_3[2] + fVar3 * param_4[2] + fVar2 * param_5[2];
}

// 0x5f1582 — observed shape
void FUN_005f1582(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6) {
    FUN_005f8d40(1);
    ((void (*)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t))PTR_FUN_007188d4)(param_1, param_2, param_3, param_4, param_5, param_6);
}

// 0x5f15ae — observed shape
void FUN_005f15ae(float* param_1, float* param_2, float* param_3, float* param_4, float* param_5, float param_6) {
    float fVar1;
    float fVar2;
    float fVar3;
    float fVar4;
    fVar1 = param_6 * param_6;
    fVar2 = param_6 * fVar1;
    fVar4 = (fVar1 * 2.0f - fVar2) - param_6;
    fVar3 = (fVar2 * 3.0f - fVar1 * 5.0f) + 2.0f;
    param_6 = (fVar1 * 4.0f - fVar2 * 3.0f) + param_6;
    fVar2 = fVar2 - fVar1;
    *param_1 = (fVar2 * *param_5 + param_6 * *param_4 + fVar3 * *param_3 + fVar4 * *param_2) * 0.5f;
    param_1[1] = (fVar4 * param_2[1] + fVar3 * param_3[1] + param_6 * param_4[1] + fVar2 * param_5[1]) * 0.5f;
    param_1[2] = (fVar4 * param_2[2] + fVar3 * param_3[2] + param_6 * param_4[2] + fVar2 * param_5[2]) * 0.5f;
}

// 0x5f1681 — observed shape
void FUN_005f1681(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6) {
    FUN_005f8d40(1);
    ((void (*)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t))PTR_FUN_007188d8)(param_1, param_2, param_3, param_4, param_5, param_6);
}

// 0x5f16b2 — observed shape
void FUN_005f16b2(float* param_1, float* param_2, float* param_3, float* param_4, float param_5, float param_6) {
    *param_1 = (*param_4 - *param_2) * param_6 + (*param_3 - *param_2) * param_5 + *param_2;
    param_1[1] = (param_4[1] - param_2[1]) * param_6 + (param_3[1] - param_2[1]) * param_5 + param_2[1];
    param_1[2] = (param_4[2] - param_2[2]) * param_6 + (param_3[2] - param_2[2]) * param_5 + param_2[2];
}
// 0x5f1711 — observed shape
void FUN_005f1711(void) {
    FUN_005f8d40(1);
    ((void (*)())PTR_FUN_0071880c)();
}

// 0x5f17b1 — observed shape
void FUN_005f17b1(void) {
    FUN_005f8d40(1);
    ((void (*)())_DAT_00718904)();
}

// 0x5f186d — observed shape
void FUN_005f186d(void) {
    FUN_005f8d40(1);
    ((void (*)())_DAT_00718830)();
}

// 0x5f1886 — observed shape
void FUN_005f1886(void) {
    FUN_005f8d40(1);
    ((void (*)())_DAT_00718908)();
}

// 0x5f1980 — observed shape
void FUN_005f1980(void) {
    FUN_005f8d40(1);
    ((void (*)())_DAT_00718820)();
}
// 0x5f1a01 — observed shape
void FUN_005f1a01(void) {
    FUN_005f8d40(1);
    ((void (*)())_DAT_0071890c)();
}

// 0x5f1a94 — observed shape
void FUN_005f1a94(void) {
    FUN_005f8d40(1);
    ((void (*)())PTR_FUN_00718844)();
}

// 0x5f1be5 — observed shape
void FUN_005f1be5(void) {
    FUN_005f8d40(1);
    ((void (*)())_DAT_00718828)();
}

// 0x5f1c24 — observed shape
void FUN_005f1c24(float* param_1, float* param_2, float* param_3, float* param_4, float* param_5, float param_6) {
    float fVar1;
    float fVar2;
    float fVar3;
    float fVar4;
    fVar1 = param_6 * param_6;
    fVar2 = param_6 * fVar1;
    fVar4 = ((fVar2 + fVar2) - fVar1 * 3.0f) + 1.0f;
    param_6 = (fVar2 - (fVar1 + fVar1)) + param_6;
    fVar3 = fVar1 * 3.0f - (fVar2 + fVar2);
    fVar2 = fVar2 - fVar1;
    *param_1 = fVar2 * *param_5 + fVar3 * *param_4 + param_6 * *param_3 + fVar4 * *param_2;
    param_1[1] = fVar4 * param_2[1] + param_6 * param_3[1] + fVar3 * param_4[1] + fVar2 * param_5[1];
    param_1[2] = fVar4 * param_2[2] + param_6 * param_3[2] + fVar3 * param_4[2] + fVar2 * param_5[2];
    param_1[3] = fVar4 * param_2[3] + param_6 * param_3[3] + fVar3 * param_4[3] + fVar2 * param_5[3];
}

// 0x5f1cf7 — observed shape
void FUN_005f1cf7(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6) {
    FUN_005f8d40(1);
    ((void (*)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t))PTR_FUN_007188e0)(param_1, param_2, param_3, param_4, param_5, param_6);
}
