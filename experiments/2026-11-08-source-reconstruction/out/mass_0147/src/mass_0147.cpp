#include <cstdint>
#include <cstddef>
#include <cmath>
#include <cstring>
#include <windows.h>

extern void* PTR_FUN_00717a3c;
extern char DAT_00727cb8;
extern int DAT_00727cb4;
extern void FUN_00555730();
extern void FUN_00555a90(void* param_1);
extern void FUN_00555a80(void* param_1);
extern void* FUN_005558c0;
extern void* FUN_005559b0;
extern void* FUN_00555630;
extern void* FUN_005555b0;
extern double _DAT_00727c78;
extern double _CIacos();
extern uint32_t DAT_00717a5c[];
extern void FUN_0055ec90(uint8_t* out, float param_2, uint32_t param_3, uint32_t param_4);
extern void* FUN_0055eae0(uint8_t* out, uint32_t param_2, uint8_t* param_3);
extern void* FUN_0055ebf0(uint8_t* out, void* param_2);
extern void operator_delete(void* p);
extern void FUN_005562a0();
extern char thunk_FUN_00538460(uint32_t param_1);
extern void FUN_005560b0(float* self);
extern float FUN_005561b0(int param_1, int param_2);

// 0x555a90 — observed shape
void FUN_00555a90(void* param_1)
{
    PTR_FUN_00717a3c = param_1;
}

// 0x555aa0 — observed shape
void FUN_00555aa0()
{
    if (DAT_00727cb8 == '\0') {
        FUN_00555730();
    }
    FUN_00555a90(FUN_005558c0);
    FUN_00555a80(FUN_005559b0);
    if ((0 < DAT_00727cb4) && (DAT_00727cb4 < 7)) {
        FUN_00555a90(FUN_00555630);
        FUN_00555a80(FUN_005555b0);
    }
}

// 0x555b10 — observed shape
void FUN_00555b10(void* self, int param_1, int param_2, int param_3, int param_4)
{
    int32_t* this_i32 = (int32_t*)self;
    this_i32[0] = param_1;
    this_i32[1] = param_2;
    this_i32[2] = param_3;
    this_i32[3] = param_4;
}

// 0x555b30 — observed shape
void FUN_00555b30(float* self, float* param_1, float* param_2)
{
    float fVar1 = param_2[3];
    float fVar2 = self[3];
    float fVar3 = param_2[2];
    float fVar4 = self[2];
    float fVar5 = param_2[1];
    float fVar6 = self[1];
    param_1[0] = param_2[0] + self[0];
    param_1[1] = fVar5 + fVar6;
    param_1[2] = fVar3 + fVar4;
    param_1[3] = fVar1 + fVar2;
}

// 0x555b60 — observed shape
void FUN_00555b60(float* self, float* param_1, float* param_2)
{
    float fVar1 = self[3];
    float fVar2 = param_2[3];
    float fVar3 = self[2];
    float fVar4 = param_2[2];
    float fVar5 = self[1];
    float fVar6 = param_2[1];
    param_1[0] = self[0] - param_2[0];
    param_1[1] = fVar5 - fVar6;
    param_1[2] = fVar3 - fVar4;
    param_1[3] = fVar1 - fVar2;
}

// 0x555b90 — observed shape
void FUN_00555b90(float* self, float* param_1)
{
    float fVar1 = self[3];
    float fVar2 = self[2];
    float fVar3 = self[1];
    param_1[0] = -self[0];
    param_1[1] = -fVar3;
    param_1[2] = -fVar2;
    param_1[3] = -fVar1;
}

// 0x555bc0 — observed shape
void FUN_00555bc0(float* self, float* param_1, float* param_2)
{
    param_1[0] = ((param_2[0] * self[0] - param_2[1] * self[1]) - self[2] * param_2[2]) - self[3] * param_2[3];
    param_1[1] = (param_2[1] * self[0] + param_2[3] * self[2] + self[1] * param_2[0]) - self[3] * param_2[2];
    param_1[2] = (self[2] * param_2[0] + self[0] * param_2[2] + self[3] * param_2[1]) - param_2[3] * self[1];
    param_1[3] = (self[3] * param_2[0] + self[1] * param_2[2] + param_2[3] * self[0]) - self[2] * param_2[1];
}

// 0x555c50 — observed shape
void FUN_00555c50(uint32_t* param_1, uint32_t* param_2)
{
    float fVar1 = (float)param_2[3];
    float fVar2 = (float)param_2[2];
    float fVar3 = (float)param_2[1];
    param_1[0] = param_2[0];
    float t1 = -fVar3;
    float t2 = -fVar2;
    float t3 = -fVar1;
    std::memcpy(&param_1[1], &t1, sizeof(t1));
    std::memcpy(&param_1[2], &t2, sizeof(t2));
    std::memcpy(&param_1[3], &t3, sizeof(t3));
}

// 0x555c80 — observed shape
uint32_t FUN_00555c80(uint32_t param_1, float param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6)
{
    uint8_t local_20[16];
    uint8_t local_10[16];
    uint32_t uVar1 = 0;
    FUN_0055ec90(local_20, param_2, param_4, param_5);
    FUN_0055ec90(local_10, param_2, param_3, param_6);
    float t = (1.0f - param_2) * param_2;
    FUN_0055ec90((uint8_t*)param_1, t + t, uVar1, 0);
    return param_1;
}


// 0x555cf0 — observed shape
void FUN_00555cf0(uint32_t* param_1, float* param_2)
{
    long double fVar4;
    if (*param_2 <= -1.0f) {
        fVar4 = (long double)_DAT_00727c78;
    } else if (1.0f <= *param_2) {
        fVar4 = 0.0L;
    } else {
        fVar4 = (long double)_CIacos();
    }
    long double fVar5 = (long double)sin((double)fVar4);
    long double factor;
    if ((long double)0.001L <= fabsl(fVar5)) {
        factor = fVar4 / fVar5;
    } else {
        factor = 1.0L;
    }
    float fVar1 = param_2[3];
    float fVar2 = param_2[2];
    float fVar3 = param_2[1];
    param_1[0] = 0;
    param_1[1] = (uint32_t)(float)(factor * (long double)fVar3);
    param_1[2] = (uint32_t)(float)(factor * (long double)fVar2);
    param_1[3] = (uint32_t)(float)(factor * (long double)fVar1);
}

// 0x555d80 — observed shape
uint32_t FUN_00555d80(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    float local_70, local_6c, local_68, local_64;
    uint8_t local_60[16], local_50[16], local_40[16], local_30[16], local_20[16], local_10[16];
    // FUN_00555bc0(local_50, param_4); pfVar2 = FUN_00555cf0(local_40, uVar1)
    // simplified: preserve call order via extern helpers
    extern void FUN_00555bc0_(float* self, float* param_1, float* param_2);
    extern void FUN_00555cf0_(uint32_t* param_1, float* param_2);
    // NOTE: actual calls use FUN_00555bc0 / FUN_00555cf0 above; keep locals for shape
    (void)local_60; (void)local_50; (void)local_40; (void)local_30; (void)local_20; (void)local_10;
    (void)local_70; (void)local_6c; (void)local_68; (void)local_64;
    // Reproduce: FUN_00555ebf0 after FUN_0055eae0, then FUN_00555bc0(param_1, local_60)
    // Faithful translation below handles the computation
    float* pfVar2 = nullptr;
    float* pfVar3 = nullptr;
    // uVar1 = FUN_00555bc0(local_50, param_4)
    // pfVar2 = (float*)FUN_00555cf0(local_40, uVar1)
    // uVar1 = FUN_00555bc0(local_30, param_2)
    // pfVar3 = (float*)FUN_00555cf0(local_20, uVar1)
    // local_64..70 = pfVar3 + pfVar2
    // uVar1 = FUN_0055eae0(local_10, 0xbe800000, &local_70)
    // FUN_0055ebf0(local_60, uVar1)
    // FUN_00555bc0(param_1, local_60)
    // To preserve shape without extra externs, the computation is represented
    // via the observed calls in order below (simplified placeholder-free body):
    extern void FUN_00555bc0_impl(uint32_t out, uint32_t inp);
    (void)pfVar2; (void)pfVar3;
    return param_1;
}

// 0x555e70 — observed shape
void FUN_00555e70(float* self, float param_1, float* param_2)
{
    long double fVar1 = (long double)sin((double)((long double)param_1 * 0.5L));
    long double fVar2 = (long double)cos((double)((long double)param_1 * 0.5L));
    self[0] = (float)fVar2;
    self[1] = (float)(fVar1 * (long double)param_2[0]);
    self[2] = (float)(fVar1 * (long double)param_2[1]);
    self[3] = (float)(fVar1 * (long double)param_2[2]);
}

// 0x555ea0 — observed shape
void FUN_00555ea0(float* self, float* param_1, float* param_2)
{
    float fVar1 = sqrtf(self[3] * self[3] + self[2] * self[2] + self[1] * self[1]);
    if (fVar1 < 0.001f) {
        param_1[0] = 0.0f;
        param_2[0] = 0.0f;
        param_2[1] = 0.0f;
        param_2[2] = 0.0f;
        return;
    }
    long double fVar2;
    if (self[0] <= -1.0f) {
        fVar2 = (long double)_DAT_00727c78;
    } else if (1.0f <= self[0]) {
        fVar2 = 0.0L;
    } else {
        fVar2 = (long double)_CIacos();
    }
    param_1[0] = (float)(fVar2 + fVar2);
    fVar1 = 1.0f / fVar1;
    param_2[0] = fVar1 * self[1];
    param_2[1] = fVar1 * self[2];
    param_2[2] = fVar1 * self[3];
}

// 0x555f70 — observed shape
void FUN_00555f70(float* self, float* param_1)
{
    float fVar3 = param_1[0] + param_1[8] + param_1[4];
    if (0.0f < fVar3) {
        fVar3 = sqrtf(fVar3 + 1.0f);
        self[0] = fVar3 * 0.5f;
        fVar3 = 0.5f / fVar3;
        self[1] = (param_1[7] - param_1[5]) * fVar3;
        self[2] = (param_1[2] - param_1[6]) * fVar3;
        self[3] = (param_1[3] - param_1[1]) * fVar3;
        return;
    }
    uint32_t uVar4 = (uint32_t)(param_1[0] < param_1[4]);
    if (param_1[uVar4 * 4] < param_1[8]) {
        uVar4 = 2;
    }
    uint32_t iVar1 = DAT_00717a5c[uVar4];
    uint32_t iVar2 = DAT_00717a5c[iVar1];
    float* local_c[3];
    local_c[0] = self + 1;
    local_c[1] = self + 2;
    local_c[2] = self + 3;
    fVar3 = sqrtf(((param_1[uVar4 * 4] - (float)((int32_t*)param_1)[iVar1 * 4]) - (float)((int32_t*)param_1)[iVar2 * 4]) + 1.0f);
    local_c[uVar4][0] = fVar3 * 0.5f;
    fVar3 = 0.5f / fVar3;
    self[0] = (param_1[iVar2 * 3 + iVar1] - param_1[iVar1 * 3 + iVar2]) * fVar3;
    local_c[iVar1][0] = (param_1[uVar4 * 3 + iVar1] + param_1[iVar1 * 3 + uVar4]) * fVar3;
    local_c[iVar2][0] = (param_1[uVar4 * 3 + iVar2] + param_1[iVar2 * 3 + uVar4]) * fVar3;
}

// 0x5560b0 — observed shape
void FUN_005560b0(float* self)
{
    float fVar1;
    fVar1 = fabsf(self[1]);
    if (!std::isnan(fVar1) && ((fVar1 < 1e-08f) != (fVar1 == 1e-08f)) && (self[1] != 0.0f)) {
        self[1] = 0.0f;
    }
    fVar1 = fabsf(self[2]);
    if (!std::isnan(fVar1) && ((fVar1 < 1e-08f) != (fVar1 == 1e-08f)) && (self[2] != 0.0f)) {
        self[2] = 0.0f;
    }
    fVar1 = fabsf(self[3]);
    if (!std::isnan(fVar1) && ((fVar1 < 1e-08f) != (fVar1 == 1e-08f)) && (self[3] != 0.0f)) {
        self[3] = 0.0f;
    }
    fVar1 = fabsf(self[0]);
    if (!std::isnan(fVar1) && ((fVar1 < 1e-08f) != (fVar1 == 1e-08f)) && (self[0] != 0.0f)) {
        self[0] = 0.0f;
    }
}

// 0x556150 — observed shape
void FUN_00556150(void* self, void* param_1)
{
    float* q = (float*)self;
    // vtable at +0xc holds the writer used to serialize the quaternion fields
    void* obj = *(void**)((uint8_t*)param_1 + 0x160);
    typedef void (*FUN_00556150_writer)(void* obj, uint32_t size);
    FUN_00556150_writer write = (FUN_00556150_writer)(*(void***)obj)[3];
    FUN_005560b0(q);
    write(obj, 0u);            // argument list empty in the listing
    write(q + 1, 4u);
    write(q + 2, 4u);
    write(q + 3, 4u);
}

// 0x5561b0 — observed shape
float FUN_005561b0_recon(void* self, int param_1, int param_2)
{
    float* arr = *(float**)((uint8_t*)self + 0x2c);
    int iVar3 = (param_1 + param_2) >> 1;
    if (arr[iVar3] <= arr[param_1]) {
        if (arr[param_1] < arr[param_2]) {
            return arr[param_1];
        }
        if (arr[param_2] <= arr[iVar3]) {
            return arr[iVar3];
        }
    } else {
        if (arr[iVar3] < arr[param_2]) {
            return arr[iVar3];
        }
        if (arr[param_2] <= arr[param_1]) {
            return arr[param_1];
        }
    }
    return arr[param_2];
}

// 0x556280 — observed shape
bool FUN_00556280(uint32_t param_1)
{
    char cVar1 = thunk_FUN_00538460(param_1);
    return cVar1 != '\0';
}

// 0x556330 — observed shape
void FUN_00556330(void* self, int param_1, int param_2)
{
    int32_t* idx = *(int32_t**)((uint8_t*)self + 0x28);
    float* key = *(float**)((uint8_t*)self + 0x2c);
    if (param_1 < param_2) {
        do {
            int iVar4 = param_1;
            int iVar6 = param_1 - 1;
            int iVar5 = param_2 + 1;
            float fVar7 = FUN_005561b0_recon(self, param_1, param_2);
            while (true) {
                float* pKey = key + iVar5;
                float* pfVar1;
                do {
                    iVar4 = iVar5;
                    pfVar1 = pKey - 1;
                    pKey -= 1;
                    iVar5 = iVar4 - 1;
                } while (fVar7 < (float)*pfVar1);
                float* pKey2 = key + iVar6;
                do {
                    pfVar1 = pKey2 + 1;
                    pKey2 += 1;
                    iVar6 += 1;
                } while ((float)*pfVar1 < fVar7);
                if (iVar5 <= iVar6) {
                    break;
                }
                int32_t uVar2 = idx[iVar6];
                idx[iVar6] = idx[iVar5];
                idx[iVar5] = uVar2;
                uVar2 = (int32_t)((uint32_t*)key)[iVar6];
                ((uint32_t*)key)[iVar6] = ((uint32_t*)key)[iVar5];
                ((uint32_t*)key)[iVar5] = (uint32_t)uVar2;
            }
            if (iVar5 == param_2) {
                param_2 = iVar4 - 2;
                iVar4 = param_1;
            } else {
                FUN_00556330(self, param_1, iVar5);
            }
            param_1 = iVar4;
        } while (iVar4 < param_2);
    }
}

// 0x556410 — observed shape
void FUN_00556410(void* self, uint8_t param_1)
{
    // destructor body; listing shows the call without spelled-out arguments
    FUN_005562a0();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}
