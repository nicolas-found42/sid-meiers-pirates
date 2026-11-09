#include <cstdint>
#include <cstddef>
#include <cmath>
#include <windows.h>

// Extern helpers / globals referenced by the assigned listings.
extern void FUN_005692e0(uint32_t param_1, int param_2);
extern void FUN_0056a010(uint32_t param_1);
extern void FUN_0056dff0(uint32_t param_1, int param_2);
extern void FUN_0056a880(int param_1);
extern void FUN_0056a8b0(int param_1, int param_2);
extern uint32_t FUN_0056a5b0(int param_1, int param_2);
extern uint32_t FUN_005695a0(int param_1, int param_2);
extern char FUN_004284c0(int param_1);
extern void* thunk_FUN_00533c78(int param_1);
extern void FUN_0056ac20(int param_1, int param_2);
extern void FUN_0056a930(uint32_t param_1, int param_2);
extern uint32_t FUN_00497420(uint32_t param_1, int param_2);

// Globals named DAT_ in the corpus.
extern uint8_t DAT_007283ad;
extern uint8_t DAT_007283ae;
extern uint8_t DAT_007283af;
extern uint32_t _DAT_00728938;
extern uint32_t _DAT_00728668;
extern uint32_t _DAT_007285f0;
extern uint32_t _DAT_00728578;
extern uint32_t _DAT_00728500;
extern uint32_t _DAT_00728960;
extern uint32_t _DAT_00728690;
extern uint32_t _DAT_00728618;
extern uint32_t _DAT_007285a0;
extern uint32_t _DAT_00728528;
extern uint32_t _DAT_00728870;
extern uint32_t _DAT_00728708;
extern uint32_t _DAT_007284b0;
extern uint32_t _DAT_007288e8;
extern uint32_t _DAT_007287f8;
extern uint32_t _DAT_00728780;
extern uint32_t _DAT_00728438;
extern uint32_t _DAT_007288b0;
extern uint32_t _DAT_007287c0;
extern uint32_t _DAT_00728748;
extern uint32_t _DAT_00728928;
extern uint32_t _DAT_00728658;
extern uint32_t _DAT_007285e0;
extern uint32_t _DAT_00728568;
extern uint32_t _DAT_007284f0;
extern uint32_t _DAT_00728838;
extern uint32_t _DAT_007286d0;
extern uint32_t _DAT_00728400;
extern uint32_t _DAT_00728478;
extern uint32_t DAT_00717a9c;
extern float _DAT_00717aa0;
extern uint8_t DAT_007288a8[];
extern uint8_t DAT_00728830[];
extern uint8_t DAT_007287b8[];
extern uint8_t DAT_00728740[];
extern uint8_t DAT_007286c8[];
extern uint8_t DAT_007283f8[];
extern uint8_t DAT_00728470[];
extern uint8_t LAB_00569320[];
extern uint8_t LAB_0056a970[];
extern uint8_t LAB_00569300[];
extern uint8_t DAT_0056a920[];
extern uint8_t LAB_0056aaf0[];
extern uint8_t LAB_0056aa50[];
extern uint8_t LAB_0056a8e0[];
extern uint8_t LAB_0056b110[];
extern uint8_t LAB_0056ace0[];
extern uint8_t LAB_0056ad80[];
extern uint8_t DAT_0056c7f0[];
extern uint8_t LAB_0056ae90[];
extern uint8_t LAB_0056b0a0[];
extern uint8_t LAB_0056b0c0[];
extern uint8_t LAB_0056b130[];
extern uint8_t LAB_0056b5e0[];
extern uint8_t LAB_0056bd30[];

// Forward declarations of assigned entries used across functions.
void FUN_0056aa00(uint32_t param_1, int param_2, int param_3, float* param_4);
void FUN_0056aac0(uint32_t param_1, int param_2, int param_3);
int* FUN_0056ad30(int param_1);
int* FUN_0056adf0(uint32_t param_1, int param_2);
void FUN_0056ae60(uint32_t param_1, int param_2, int param_3);
uint32_t FUN_0056b050(int param_1, int param_2);
int* FUN_0056b2e0(int param_1, int param_2);
void FUN_0056b370(int param_1, int param_2, int param_3);
uint32_t FUN_0056b500(int param_1, int param_2);
int* FUN_0056b5a0(int param_1);
void FUN_0056b6a0(float param_1, int param_2, uint32_t param_3, float* param_4);
void FUN_0056b740(float param_1, int param_2, uint32_t param_3, float* param_4);
void FUN_0056b7c0(float* param_1, float* param_2, float param_3, float param_4);
void FUN_0056b980(int param_1, uint32_t param_2);
float FUN_0056bba0(int param_1, int param_2);

// 0x56aa00 — observed shape: 3-float vector difference
void FUN_0056aa00(uint32_t param_1, int param_2, int param_3, float* param_4)
{
    (void)param_1;
    float fVar1 = *reinterpret_cast<float*>(param_2 + 0x0c);
    float fVar2 = *reinterpret_cast<float*>(param_3 + 0x0c);
    float fVar3 = *reinterpret_cast<float*>(param_2 + 0x10);
    float fVar4 = *reinterpret_cast<float*>(param_3 + 0x10);
    param_4[0] = *reinterpret_cast<float*>(param_2 + 8) - *reinterpret_cast<float*>(param_3 + 8);
    param_4[1] = fVar1 - fVar2;
    param_4[2] = fVar3 - fVar4;
}

// 0x56aac0 — observed shape: stride 0x14 loop over FUN_005692e0
void FUN_0056aac0(uint32_t param_1, int param_2, int param_3)
{
    if (param_3 != 0) {
        do {
            FUN_005692e0(param_1, param_2);
            param_2 += 0x14;
            param_3 -= 1;
        } while (param_3 != 0);
    }
}

// 0x56ac20 — observed shape: vtable install with index (param2 + param1*5)*4
void FUN_0056ac20(int param_1, int param_2)
{
    int iVar1 = (param_2 + param_1 * 5) * 4;
    *reinterpret_cast<uint8_t**>(DAT_007288a8 + iVar1) = LAB_00569320;
    *reinterpret_cast<uint8_t**>(DAT_00728830 + iVar1) = LAB_0056a970;
    *reinterpret_cast<void**>(DAT_007287b8 + iVar1) = reinterpret_cast<void*>(&FUN_0056aa00);
    *reinterpret_cast<uint8_t**>(DAT_00728740 + iVar1) = LAB_00569300;
    *reinterpret_cast<uint8_t**>(DAT_007286c8 + iVar1) = DAT_0056a920;
    *reinterpret_cast<void**>(DAT_007283f8 + iVar1) = reinterpret_cast<void*>(&FUN_00497420);
    *reinterpret_cast<uint8_t**>(DAT_00728470 + iVar1) = LAB_0056aaf0;
}

// 0x56ac80 — observed shape: one-shot init guarded by DAT_007283ad
uint32_t FUN_0056ac80(void)
{
    if (DAT_007283ad == '\0') {
        DAT_007283ad = 1;
        _DAT_00728938 = reinterpret_cast<uint32_t>(LAB_0056aa50);
        _DAT_00728668 = reinterpret_cast<uint32_t>(&FUN_0056aac0);
        _DAT_007285f0 = reinterpret_cast<uint32_t>(LAB_0056a8e0);
        _DAT_00728578 = reinterpret_cast<uint32_t>(&FUN_0056a930);
        _DAT_00728500 = reinterpret_cast<uint32_t>(LAB_0056b110);
        FUN_0056ac20(1, 1);
        return 1;
    }
    return 0;
}

// 0x56ad30 — observed shape: alloc array of param1 records size 0x18, zeroed
int* FUN_0056ad30(int param_1)
{
    int* piVar1 = static_cast<int*>(thunk_FUN_00533c78(param_1 * 0x18 + 4));
    if (piVar1 == nullptr) {
        return nullptr;
    }
    *piVar1 = param_1;
    int* piVar2 = piVar1 + 1;
    if (param_1 - 1 >= 0) {
        piVar1 = piVar1 + 5;
        int remaining = param_1;
        do {
            piVar1[-2] = 0;
            piVar1[-1] = 0;
            *piVar1 = 0;
            piVar1[1] = 0;
            *reinterpret_cast<uint8_t*>(piVar1 - 3) = 0x18;
            piVar1 += 6;
            remaining -= 1;
        } while (remaining != 0);
    }
    return piVar2;
}

// 0x56adf0 — observed shape: alloc 0x18 records, zero, then FUN_0056a010 per index
int* FUN_0056adf0(uint32_t param_1, int param_2)
{
    int* piVar1 = static_cast<int*>(thunk_FUN_00533c78(param_2 * 0x18 + 4));
    int* piVar3 = nullptr;
    if (piVar1 == nullptr) {
        piVar3 = nullptr;
    } else {
        *piVar1 = param_2;
        piVar3 = piVar1 + 1;
        if (param_2 - 1 >= 0) {
            piVar1 = piVar1 + 5;
            int iVar2 = param_2;
            do {
                piVar1[-2] = 0;
                piVar1[-1] = 0;
                *piVar1 = 0;
                piVar1[1] = 0;
                *reinterpret_cast<uint8_t*>(piVar1 - 3) = 0x18;
                piVar1 += 6;
                iVar2 -= 1;
            } while (iVar2 != 0);
        }
    }
    for (; param_2 != 0; param_2 -= 1) {
        FUN_0056a010(param_1);
    }
    return piVar3;
}

// 0x56ae60 — observed shape: stride 0x18 loop over FUN_0056dff0
void FUN_0056ae60(uint32_t param_1, int param_2, int param_3)
{
    if (param_3 != 0) {
        do {
            FUN_0056dff0(param_1, param_2);
            param_2 += 0x18;
            param_3 -= 1;
        } while (param_3 != 0);
    }
}

// 0x56afd0 — observed shape: one-shot init guarded by DAT_007283ae
uint32_t FUN_0056afd0(void)
{
    if (DAT_007283ae == '\0') {
        _DAT_007288e8 = 0;
        _DAT_007287f8 = 0;
        _DAT_00728780 = 0;
        _DAT_00728438 = 0;
        DAT_007283ae = 1;
        _DAT_00728960 = reinterpret_cast<uint32_t>(&FUN_0056adf0);
        _DAT_00728690 = reinterpret_cast<uint32_t>(&FUN_0056ae60);
        _DAT_00728618 = reinterpret_cast<uint32_t>(LAB_0056ace0);
        _DAT_007285a0 = reinterpret_cast<uint32_t>(&FUN_0056ad30);
        _DAT_00728528 = reinterpret_cast<uint32_t>(LAB_0056b110);
        _DAT_00728870 = reinterpret_cast<uint32_t>(LAB_0056ad80);
        _DAT_00728708 = reinterpret_cast<uint32_t>(DAT_0056c7f0);
        _DAT_007284b0 = reinterpret_cast<uint32_t>(LAB_0056ae90);
        return 1;
    }
    return 0;
}

// 0x56b050 — observed shape: FUN_0056a5b0 gate then float eq at +0xc/+0x10
uint32_t FUN_0056b050(int param_1, int param_2)
{
    uint32_t uVar1 = FUN_0056a5b0(param_1, param_2);
    if (static_cast<char>(uVar1) == '\0') {
        return uVar1;
    }
    if ((*reinterpret_cast<float*>(param_1 + 0x0c) == *reinterpret_cast<float*>(param_2 + 0x0c)) &&
        (*reinterpret_cast<float*>(param_1 + 0x10) == *reinterpret_cast<float*>(param_2 + 0x10))) {
        return 1;
    }
    return 0;
}

// 0x56b2e0 — observed shape: alloc 0x14 records, vtable callback at +0x15c, FUN_0056a880 loop
int* FUN_0056b2e0(int param_1, int param_2)
{
    int* piVar1 = static_cast<int*>(thunk_FUN_00533c78(param_2 * 0x14 + 4));
    int* piVar3 = nullptr;
    if (piVar1 == nullptr) {
        piVar3 = nullptr;
    } else {
        *piVar1 = param_2;
        piVar3 = piVar1 + 1;
        if (param_2 - 1 >= 0) {
            piVar1 = piVar1 + 2;
            int iVar2 = param_2;
            do {
                *reinterpret_cast<uint8_t*>(piVar1) = 0x14;
                piVar1 += 5;
                iVar2 -= 1;
            } while (iVar2 != 0);
        }
    }
    if (param_2 != 0) {
        piVar1 = piVar3 + 4;
        do {
            FUN_0056a880(param_1);
            void* vtbl = *reinterpret_cast<void**>(*reinterpret_cast<int*>(param_1 + 0x15c) + 8);
            using Cb = void(*)(int*, int);
            reinterpret_cast<Cb>(vtbl)(piVar1 - 1, 4);
            reinterpret_cast<Cb>(vtbl)(piVar1, 4);
            piVar1 += 5;
            param_2 -= 1;
        } while (param_2 != 0);
    }
    return piVar3;
}

// 0x56b370 — observed shape: stride 0x14 loop, FUN_0056a8b0 plus vtable at +0x160
void FUN_0056b370(int param_1, int param_2, int param_3)
{
    if (param_3 != 0) {
        param_2 += 0x10;
        do {
            FUN_0056a8b0(param_1, param_2 - 0x10);
            void* vtbl = *reinterpret_cast<void**>(*reinterpret_cast<int*>(param_1 + 0x160) + 0x0c);
            using Cb = void(*)(int, int);
            reinterpret_cast<Cb>(vtbl)(param_2 - 4, 4);
            reinterpret_cast<Cb>(vtbl)(param_2, 4);
            param_2 += 0x14;
            param_3 -= 1;
        } while (param_3 != 0);
    }
}

// 0x56b3c0 — observed shape: one-shot init guarded by DAT_007283af
uint32_t FUN_0056b3c0(void)
{
    if (DAT_007283af == '\0') {
        _DAT_007288b0 = 0;
        _DAT_007287c0 = 0;
        _DAT_00728748 = 0;
        DAT_007283af = 1;
        _DAT_00728928 = reinterpret_cast<uint32_t>(&FUN_0056b2e0);
        _DAT_00728658 = reinterpret_cast<uint32_t>(&FUN_0056b370);
        _DAT_007285e0 = reinterpret_cast<uint32_t>(LAB_0056b0a0);
        _DAT_00728568 = reinterpret_cast<uint32_t>(&FUN_0056a930);
        _DAT_007284f0 = reinterpret_cast<uint32_t>(LAB_0056b110);
        _DAT_00728838 = reinterpret_cast<uint32_t>(LAB_0056b0c0);
        _DAT_007286d0 = reinterpret_cast<uint32_t>(&FUN_0056b050);
        _DAT_00728400 = reinterpret_cast<uint32_t>(&FUN_00497420);
        _DAT_00728478 = reinterpret_cast<uint32_t>(LAB_0056b130);
        return 1;
    }
    return 0;
}

// 0x56b500 — observed shape: FUN_005695a0 gate, float eq at +0x14/0x18/0x1c, FUN_004284c0 checks
uint32_t FUN_0056b500(int param_1, int param_2)
{
    uint32_t uVar2 = FUN_005695a0(param_1, param_2);
    if (static_cast<char>(uVar2) == '\0') {
        return uVar2;
    }
    if ((*reinterpret_cast<float*>(param_1 + 0x14) == *reinterpret_cast<float*>(param_2 + 0x14)) &&
        (*reinterpret_cast<float*>(param_1 + 0x18) == *reinterpret_cast<float*>(param_2 + 0x18)) &&
        (*reinterpret_cast<float*>(param_1 + 0x1c) == *reinterpret_cast<float*>(param_2 + 0x1c))) {
        if (FUN_004284c0(param_2 + 0x20) != '\0') {
            if (FUN_004284c0(param_2 + 0x2c) != '\0') {
                if (FUN_004284c0(param_2 + 0x38) != '\0') {
                    if (FUN_004284c0(param_2 + 0x44) != '\0') {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

// 0x56b5a0 — observed shape: alloc records size 0x50, first byte 0x50
int* FUN_0056b5a0(int param_1)
{
    int* piVar1 = static_cast<int*>(thunk_FUN_00533c78(param_1 * 0x50 + 4));
    if (piVar1 == nullptr) {
        return nullptr;
    }
    *piVar1 = param_1;
    int* piVar2 = piVar1 + 1;
    if (param_1 - 1 >= 0) {
        piVar1 = piVar1 + 2;
        do {
            *reinterpret_cast<uint8_t*>(piVar1) = 0x50;
            piVar1 += 0x14;
            param_1 -= 1;
        } while (param_1 != 0);
    }
    return piVar2;
}

// 0x56b6a0 — observed shape: cubic Hermite evaluation over offsets 0x2c..0x4c
void FUN_0056b6a0(float param_1, int param_2, uint32_t param_3, float* param_4)
{
    (void)param_3;
    float t3 = param_1 * 3.0f;
    float f1 = *reinterpret_cast<float*>(param_2 + 0x48);
    float f2 = *reinterpret_cast<float*>(param_2 + 0x4c);
    float f3 = *reinterpret_cast<float*>(param_2 + 0x3c);
    float f4 = *reinterpret_cast<float*>(param_2 + 0x40);
    float f5 = *reinterpret_cast<float*>(param_2 + 0x30);
    float f6 = *reinterpret_cast<float*>(param_2 + 0x34);
    param_4[0] = (*reinterpret_cast<float*>(param_2 + 0x38) + *reinterpret_cast<float*>(param_2 + 0x38) + t3 * *reinterpret_cast<float*>(param_2 + 0x44)) * param_1 + *reinterpret_cast<float*>(param_2 + 0x2c);
    param_4[1] = (f3 + f3 + t3 * f1) * param_1 + f5;
    param_4[2] = (f4 + f4 + t3 * f2) * param_1 + f6;
}

// 0x56b740 — observed shape: quadratic Hermite over offsets 0x2c..0x4c, x6.0
void FUN_0056b740(float param_1, int param_2, uint32_t param_3, float* param_4)
{
    (void)param_3;
    param_1 = param_1 * 6.0f;
    float f1 = *reinterpret_cast<float*>(param_2 + 0x48);
    float f2 = *reinterpret_cast<float*>(param_2 + 0x4c);
    float f3 = *reinterpret_cast<float*>(param_2 + 0x3c);
    float f4 = *reinterpret_cast<float*>(param_2 + 0x40);
    param_4[0] = *reinterpret_cast<float*>(param_2 + 0x38) + *reinterpret_cast<float*>(param_2 + 0x38) + param_1 * *reinterpret_cast<float*>(param_2 + 0x44);
    param_4[1] = f3 + f3 + param_1 * f1;
    param_4[2] = f4 + f4 + param_1 * f2;
}

// 0x56b7c0 — observed shape: receiver in_ECX, 0x14/0x18/0x1c basis split, weighted blend
void FUN_0056b7c0(void* self, float* param_1, float* param_2, float param_3, float param_4)
{
    int in_ECX = reinterpret_cast<int>(self);
    float fA = *reinterpret_cast<float*>(in_ECX + 8) - *param_1;
    float fB = *reinterpret_cast<float*>(in_ECX + 0x0c) - param_1[1];
    float fC = *reinterpret_cast<float*>(in_ECX + 0x10) - param_1[2];
    float fD = *param_2 - *reinterpret_cast<float*>(in_ECX + 8);
    float fE = param_2[1] - *reinterpret_cast<float*>(in_ECX + 0x0c);
    float fF = param_2[2] - *reinterpret_cast<float*>(in_ECX + 0x10);
    float fG = *reinterpret_cast<float*>(in_ECX + 0x1c) + 1.0f;
    float fH = 1.0f - *reinterpret_cast<float*>(in_ECX + 0x1c);
    float fI = (1.0f - *reinterpret_cast<float*>(in_ECX + 0x14)) * 0.5f;
    float fJ = (*reinterpret_cast<float*>(in_ECX + 0x18) + 1.0f) * fI;
    fI = (1.0f - *reinterpret_cast<float*>(in_ECX + 0x18)) * fI;
    float fK = fJ * fH;
    float fL = fG * fI;
    *reinterpret_cast<float*>(in_ECX + 0x20) = fA * fL + fD * fK;
    *reinterpret_cast<float*>(in_ECX + 0x24) = fB * fL + fE * fK;
    *reinterpret_cast<float*>(in_ECX + 0x28) = fC * fL + fF * fK;
    fI = fI * fH;
    float fM = fJ * fG;
    *reinterpret_cast<float*>(in_ECX + 0x2c) = fM * fA + fI * fD;
    *reinterpret_cast<float*>(in_ECX + 0x30) = fB * fM + fE * fI;
    *reinterpret_cast<float*>(in_ECX + 0x34) = fC * fM + fF * fI;
    float w = 2.0f / (param_3 + param_4);
    param_3 = param_3 * w;
    *reinterpret_cast<float*>(in_ECX + 0x20) = param_3 * *reinterpret_cast<float*>(in_ECX + 0x20);
    *reinterpret_cast<float*>(in_ECX + 0x24) = param_3 * *reinterpret_cast<float*>(in_ECX + 0x24);
    *reinterpret_cast<float*>(in_ECX + 0x28) = param_3 * *reinterpret_cast<float*>(in_ECX + 0x28);
    w = w * param_4;
    *reinterpret_cast<float*>(in_ECX + 0x2c) = w * *reinterpret_cast<float*>(in_ECX + 0x2c);
    *reinterpret_cast<float*>(in_ECX + 0x30) = w * *reinterpret_cast<float*>(in_ECX + 0x30);
    *reinterpret_cast<float*>(in_ECX + 0x34) = w * *reinterpret_cast<float*>(in_ECX + 0x34);
}

// 0x56b980 — observed shape: Chaikin-like subdivision + 3-tap filter on 0x50 stride
void FUN_0056b980(int param_1, uint32_t param_2)
{
    uint32_t uVar6 = param_2 - 1;
    if (param_2 > 1) {
        int iVar5 = param_1 + 8;
        float local_4c = *reinterpret_cast<float*>(param_1 + 0x10) + *reinterpret_cast<float*>(param_1 + 0x10);
        float local_60 = (*reinterpret_cast<float*>(param_1 + 8) + *reinterpret_cast<float*>(param_1 + 8)) - *reinterpret_cast<float*>(param_1 + 0x58);
        float local_5c = (*reinterpret_cast<float*>(param_1 + 0x0c) + *reinterpret_cast<float*>(param_1 + 0x0c)) - *reinterpret_cast<float*>(param_1 + 0x5c);
        float local_58 = local_4c - *reinterpret_cast<float*>(param_1 + 0x60);
        float buf1[3] = {local_60, local_5c, local_58};
        FUN_0056b7c0(reinterpret_cast<void*>(param_1), buf1, reinterpret_cast<float*>(param_1 + 0x58), 1.0f, 1.0f);
        if (uVar6 > 1) {
            int iVar4 = static_cast<int>(param_2 - 2);
            do {
                FUN_0056b7c0(reinterpret_cast<void*>(param_1), reinterpret_cast<float*>(iVar5), reinterpret_cast<float*>(iVar5 + 0xa0),
                             *reinterpret_cast<float*>(iVar5 + 0x48) - *reinterpret_cast<float*>(iVar5 + -8),
                             *reinterpret_cast<float*>(iVar5 + 0x98) - *reinterpret_cast<float*>(iVar5 + 0x48));
                iVar5 += 0x50;
                iVar4 -= 1;
            } while (iVar4 != 0);
        }
        float f1 = *reinterpret_cast<float*>(uVar6 * 0x50 + 8 + param_1);
        int iEnd = static_cast<int>(uVar6 * 0x50 + param_1);
        float f2 = *reinterpret_cast<float*>(iEnd + 0x0c);
        float* pfEnd = reinterpret_cast<float*>((param_2 * 5 + -10) * 0x10 + 8 + param_1);
        float z = *reinterpret_cast<float*>(iEnd + 0x10);
        z = z + z;
        float e1 = (f1 + f1) - *pfEnd;
        float e2 = (f2 + f2) - pfEnd[1];
        float e3 = z - pfEnd[2];
        float buf2[3] = {e1, e2, e3};
        FUN_0056b7c0(reinterpret_cast<void*>(param_1), pfEnd, buf2, 1.0f, 1.0f);
    }
    if (uVar6 != 0) {
        float* pf = reinterpret_cast<float*>(param_1 + 0x60);
        do {
            pf[-10] = (pf[-2] - pf[-0x16]) * 3.0f - (pf[-0x0d] + pf[-0x0d] + pf[4]);
            pf[-9] = (pf[-1] - pf[-0x15]) * 3.0f - (pf[-0x0c] + pf[-0x0c] + pf[5]);
            pf[-8] = (*pf - pf[-0x14]) * 3.0f - (pf[-0x0b] + pf[-0x0b] + pf[6]);
            float d1 = (pf[-2] - pf[-0x16]) + (pf[-2] - pf[-0x16]);
            float d2 = (pf[-1] - pf[-0x15]) + (pf[-1] - pf[-0x15]);
            float d3 = (*pf - pf[-0x14]) + (*pf - pf[-0x14]);
            pf[-7] = (pf[4] + pf[-0x0d]) - d1;
            pf[-6] = (pf[-0x0c] + pf[5]) - d2;
            pf[-5] = (pf[-0x0b] + pf[6]) - d3;
            pf += 0x14;
            uVar6 -= 1;
        } while (uVar6 != 0);
    }
}

// 0x56bba0 — observed shape: max curvature search, returns float10
float FUN_0056bba0(int param_1, int param_2)
{
    float local_40 = 0.0f;
    float local_3c = 0.0f, local_38 = 0.0f, local_34 = 0.0f;
    float local_30 = 0.0f, local_2c = 0.0f, local_28 = 0.0f;
    if (param_2 - 1 != 0) {
        float* pfVar5 = reinterpret_cast<float*>(param_1 + 0x4c);
        int iVar4 = static_cast<int>(DAT_00717a9c);
        int outer = param_2 - 1;
        do {
            param_2 = 0;
            if (iVar4 >= 0) {
                do {
                    float f = static_cast<float>(param_2) * _DAT_00717aa0;
                    float out3[3];
                    FUN_0056b6a0(f, reinterpret_cast<int>(pfVar5 - 0x13), reinterpret_cast<uint32_t>(pfVar5 + 1), out3);
                    local_3c = out3[0]; local_38 = out3[1]; local_34 = out3[2];
                    f = f * 6.0f;
                    float local_8 = f * pfVar5[-1];
                    float local_4 = f * *pfVar5;
                    float local_14 = pfVar5[-4] + pfVar5[-4];
                    float local_10 = pfVar5[-3] + pfVar5[-3];
                    local_30 = pfVar5[-5] + pfVar5[-5] + f * pfVar5[-2];
                    local_2c = local_14 + local_8;
                    local_28 = local_10 + local_4;
                    float cr1 = local_28 * local_38 - local_34 * local_2c;
                    float cr3 = local_34 * local_30 - local_28 * local_3c;
                    float cr2 = local_2c * local_3c - local_38 * local_30;
                    float curv = sqrtf(cr1 * cr1 + cr3 * cr3 + cr2 * cr2) / (local_3c * local_3c + local_38 * local_38 + local_34 * local_34);
                    if (local_40 < curv) local_40 = curv;
                    param_2 += 1;
                    iVar4 = static_cast<int>(DAT_00717a9c);
                } while (param_2 <= static_cast<int>(DAT_00717a9c));
            }
            pfVar5 += 0x14;
            outer -= 1;
        } while (outer != 0);
    }
    return local_40;
}

// 0x56be80 — observed shape: vtable install with index (param2 + param1*5)*4
void FUN_0056be80(int param_1, int param_2)
{
    int iVar1 = (param_2 + param_1 * 5) * 4;
    *reinterpret_cast<void**>(DAT_007288a8 + iVar1) = reinterpret_cast<void*>(&FUN_0056bba0);
    *reinterpret_cast<uint8_t**>(DAT_00728830 + iVar1) = LAB_0056b5e0;
    *reinterpret_cast<void**>(DAT_007287b8 + iVar1) = reinterpret_cast<void*>(&FUN_0056b6a0);
    *reinterpret_cast<void**>(DAT_00728740 + iVar1) = reinterpret_cast<void*>(&FUN_0056b740);
    *reinterpret_cast<void**>(DAT_007286c8 + iVar1) = reinterpret_cast<void*>(&FUN_0056b500);
    *reinterpret_cast<void**>(DAT_007283f8 + iVar1) = reinterpret_cast<void*>(&FUN_0056b980);
    *reinterpret_cast<uint8_t**>(DAT_00728470 + iVar1) = LAB_0056bd30;
}
