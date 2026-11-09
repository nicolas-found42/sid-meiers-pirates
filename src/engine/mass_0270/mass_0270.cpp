#include <cstdint>
#include <cstddef>
#include <cmath>
#include <windows.h>

extern void FUN_006015d0(void* param_1);
extern void FUN_0060183d(void* param_1);
extern void FUN_005f1093(void* dst, uint32_t src, uint32_t count);

// 0x608d7d — observed shape
void FUN_608d7d(void* self, int param_1, int param_2, float* param_3)
{
    uint8_t* pbVar2 = (uint8_t*)(*(intptr_t*)((char*)self + 0x60) * param_1 + *(intptr_t*)((char*)self + 100) * param_2 + *(intptr_t*)((char*)self + 0x20));
    uint8_t* pbVar1 = pbVar2 + *(intptr_t*)((char*)self + 0x68) * 2;
    for (; pbVar2 < pbVar1; pbVar2 = pbVar2 + 2) {
        param_3[0] = (float)(pbVar2[1] & 0xf) * 0.06666667f;
        param_3[1] = (float)(*pbVar2 >> 4) * 0.06666667f;
        param_3[2] = (float)(*pbVar2 & 0xf) * 0.06666667f;
        param_3[3] = 1.0f;
        param_3 = param_3 + 4;
    }
    if (*(intptr_t*)((char*)self + 0x18) != 0) {
        FUN_006015d0(param_3 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
    if (*(intptr_t*)((char*)self + 0x10) != 0) {
        FUN_0060183d(param_3 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
}

// 0x608e24 — observed shape
void FUN_608e24(void* self, int param_1, int param_2, uint32_t* param_3)
{
    uint8_t* pbVar2 = (uint8_t*)(*(intptr_t*)((char*)self + 0x60) * param_1 + *(intptr_t*)((char*)self + 100) * param_2 + *(intptr_t*)((char*)self + 0x20));
    uint8_t* pbVar1 = pbVar2 + *(intptr_t*)((char*)self + 0x68) * 2;
    for (; pbVar2 < pbVar1; pbVar2 = pbVar2 + 2) {
        uint32_t* puVar3 = (uint32_t*)((uint32_t)*pbVar2 * 0x10 + (uint32_t)*(intptr_t*)((char*)self + 0x38));
        param_3[0] = puVar3[0];
        param_3[1] = puVar3[1];
        param_3[2] = puVar3[2];
        param_3[3] = puVar3[3];
        param_3[3] = (uint32_t)((float)pbVar2[1] * 0.003921569f);
        param_3 = param_3 + 4;
    }
    if (*(intptr_t*)((char*)self + 0x18) != 0) {
        FUN_006015d0(param_3 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
    if (*(intptr_t*)((char*)self + 0x10) != 0) {
        FUN_0060183d(param_3 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
}

// 0x608eb4 — observed shape
void FUN_608eb4(void* self, int param_1, int param_2, uint32_t* param_3)
{
    uint8_t* pbVar2 = (uint8_t*)(*(intptr_t*)((char*)self + 0x60) * param_1 + *(intptr_t*)((char*)self + 100) * param_2 + *(intptr_t*)((char*)self + 0x20));
    uint8_t* pbVar3 = pbVar2 + *(intptr_t*)((char*)self + 0x68);
    for (; pbVar2 < pbVar3; pbVar2 = pbVar2 + 1) {
        uint32_t* puVar4 = (uint32_t*)((uint32_t)*pbVar2 * 0x10 + (uint32_t)*(intptr_t*)((char*)self + 0x38));
        param_3[0] = puVar4[0];
        param_3[1] = puVar4[1];
        uint32_t* puVar1 = param_3 + 3;
        param_3[2] = puVar4[2];
        param_3 = param_3 + 4;
        *puVar1 = puVar4[3];
    }
    if (*(intptr_t*)((char*)self + 0x18) != 0) {
        FUN_006015d0(param_3 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
    if (*(intptr_t*)((char*)self + 0x10) != 0) {
        FUN_0060183d(param_3 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
}

// 0x608f23 — observed shape
void FUN_608f23(void* self, int param_1, int param_2, float* param_3)
{
    uint8_t* pbVar3 = (uint8_t*)(*(intptr_t*)((char*)self + 0x60) * param_1 + *(intptr_t*)((char*)self + 100) * param_2 + *(intptr_t*)((char*)self + 0x20));
    uint8_t* pbVar4 = pbVar3 + *(intptr_t*)((char*)self + 0x68);
    float* pfVar5 = param_3;
    if (pbVar3 < pbVar4) {
        do {
            uint8_t bVar1 = *pbVar3;
            pbVar3 = pbVar3 + 1;
            float fVar2 = (float)bVar1 * 0.003921569f;
            param_3[2] = fVar2;
            param_3[1] = fVar2;
            param_3[0] = fVar2;
            pfVar5 = param_3 + 4;
            param_3[3] = 1.0f;
            param_3 = pfVar5;
        } while (pbVar3 < pbVar4);
    }
    if (*(intptr_t*)((char*)self + 0x18) != 0) {
        FUN_006015d0(pfVar5 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
    if (*(intptr_t*)((char*)self + 0x10) != 0) {
        FUN_0060183d(pfVar5 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
}

// 0x608f9d — observed shape
void FUN_608f9d(void* self, int param_1, int param_2, float* param_3)
{
    uint8_t* pbVar3 = (uint8_t*)(*(intptr_t*)((char*)self + 0x60) * param_1 + *(intptr_t*)((char*)self + 100) * param_2 + *(intptr_t*)((char*)self + 0x20));
    uint8_t* pbVar1 = pbVar3 + *(intptr_t*)((char*)self + 0x68) * 2;
    for (; pbVar3 < pbVar1; pbVar3 = pbVar3 + 2) {
        float fVar2 = (float)*pbVar3 * 0.003921569f;
        param_3[2] = fVar2;
        param_3[1] = fVar2;
        param_3[0] = fVar2;
        param_3[3] = (float)pbVar3[1] * 0.003921569f;
        param_3 = param_3 + 4;
    }
    if (*(intptr_t*)((char*)self + 0x18) != 0) {
        FUN_006015d0(param_3 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
    if (*(intptr_t*)((char*)self + 0x10) != 0) {
        FUN_0060183d(param_3 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
}
// 0x60902e — observed shape
void FUN_60902e(void* self, int param_1, int param_2, float* param_3)
{
    uint8_t* pbVar2 = (uint8_t*)(*(intptr_t*)((char*)self + 0x60) * param_1 + *(intptr_t*)((char*)self + 100) * param_2 + *(intptr_t*)((char*)self + 0x20));
    uint8_t* pbVar3 = pbVar2 + *(intptr_t*)((char*)self + 0x68);
    for (; pbVar2 < pbVar3; pbVar2 = pbVar2 + 1) {
        float fVar1 = (float)(*pbVar2 & 0xf) * 0.06666667f;
        param_3[2] = fVar1;
        param_3[1] = fVar1;
        param_3[0] = fVar1;
        param_3[3] = (float)(*pbVar2 >> 4) * 0.06666667f;
        param_3 = param_3 + 4;
    }
    if (*(intptr_t*)((char*)self + 0x18) != 0) {
        FUN_006015d0(param_3 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
    if (*(intptr_t*)((char*)self + 0x10) != 0) {
        FUN_0060183d(param_3 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
}

// 0x6090bf — observed shape
void FUN_6090bf(void* self, int param_1, int param_2, float* param_3)
{
    int8_t* pcVar3 = (int8_t*)(*(intptr_t*)((char*)self + 0x60) * param_1 + *(intptr_t*)((char*)self + 100) * param_2 + *(intptr_t*)((char*)self + 0x20));
    int8_t* pcVar1 = pcVar3 + *(intptr_t*)((char*)self + 0x68) * 2;
    float* pfVar4 = param_3;
    if (pcVar3 < pcVar1) {
        do {
            int8_t cVar2 = pcVar3[1];
            param_3[0] = (float)(int8_t)((*pcVar3 == -0x80) + *pcVar3) * 0.007874016f;
            pcVar3 = pcVar3 + 2;
            pfVar4 = param_3 + 4;
            param_3[1] = (float)(int8_t)((cVar2 == -0x80) + cVar2) * 0.007874016f;
            param_3[2] = 1.0f;
            param_3[3] = 1.0f;
            param_3 = pfVar4;
        } while (pcVar3 < pcVar1);
    }
    if (*(intptr_t*)((char*)self + 0x18) != 0) {
        FUN_006015d0(pfVar4 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
    if (*(intptr_t*)((char*)self + 0x10) != 0) {
        FUN_0060183d(pfVar4 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
}

// 0x60916d — observed shape
void FUN_60916d(void* self, int param_1, int param_2, float* param_3)
{
    uint16_t* puVar3 = (uint16_t*)(*(intptr_t*)((char*)self + 0x60) * param_1 + *(intptr_t*)((char*)self + 100) * param_2 + *(intptr_t*)((char*)self + 0x20));
    uint16_t* puVar1 = puVar3 + *(intptr_t*)((char*)self + 0x68);
    float* pfVar6 = param_3;
    if (puVar3 < puVar1) {
        do {
            int8_t cVar5 = (int8_t)((int8_t)*puVar3 << 3) >> 3;
            int8_t cVar4 = (int8_t)((int8_t)(*puVar3 >> 5) << 3) >> 3;
            param_3[0] = (float)(int8_t)((cVar5 == -0x10) + cVar5) * 0.06666667f;
            pfVar6 = param_3 + 4;
            param_3[1] = (float)(int8_t)((cVar4 == -0x10) + cVar4) * 0.06666667f;
            param_3[2] = 1.0f;
            uint16_t uVar2 = *puVar3;
            puVar3 = puVar3 + 1;
            param_3[3] = (float)(uVar2 >> 10) * 0.015873017f;
            param_3 = pfVar6;
        } while (puVar3 < puVar1);
    }
    if (*(intptr_t*)((char*)self + 0x18) != 0) {
        FUN_006015d0(pfVar6 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
    if (*(intptr_t*)((char*)self + 0x10) != 0) {
        FUN_0060183d(pfVar6 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
}

// 0x609240 — observed shape
void FUN_609240(void* self, int param_1, int param_2, float* param_3)
{
    int8_t* pcVar2 = (int8_t*)(*(intptr_t*)((char*)self + 0x60) * param_1 + *(intptr_t*)((char*)self + 100) * param_2 + *(intptr_t*)((char*)self + 0x20));
    int8_t* pcVar1 = pcVar2 + *(intptr_t*)((char*)self + 0x68) * 4;
    float* pfVar5 = param_3;
    if (pcVar2 < pcVar1) {
        do {
            int8_t cVar4 = (int8_t)(((uint32_t)*(uint32_t*)pcVar2) >> 8);
            int8_t* pcVar3 = pcVar2 + 4;
            param_3[0] = (float)(int8_t)((*pcVar2 == -0x80) + *pcVar2) * 0.007874016f;
            pfVar5 = param_3 + 4;
            param_3[1] = (float)(int8_t)((cVar4 == -0x80) + cVar4) * 0.007874016f;
            param_3[2] = 1.0f;
            param_3[3] = (float)(uint8_t)pcVar2[2] * 0.003921569f;
            pcVar2 = pcVar3;
            param_3 = pfVar5;
        } while (pcVar3 < pcVar1);
    }
    if (*(intptr_t*)((char*)self + 0x18) != 0) {
        FUN_006015d0(pfVar5 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
    if (*(intptr_t*)((char*)self + 0x10) != 0) {
        FUN_0060183d(pfVar5 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
}

// 0x6092ff — observed shape
void FUN_6092ff(void* self, int param_1, int param_2, float* param_3)
{
    uint32_t* puVar4 = (uint32_t*)(*(intptr_t*)((char*)self + 0x60) * param_1 + *(intptr_t*)((char*)self + 100) * param_2 + *(intptr_t*)((char*)self + 0x20));
    uint32_t* puVar1 = puVar4 + *(intptr_t*)((char*)self + 0x68);
    float* pfVar7 = param_3;
    if (puVar4 < puVar1) {
        do {
            uint32_t uVar2 = *puVar4;
            int8_t cVar3 = (int8_t)((uint32_t)uVar2 >> 0x10);
            int8_t cVar6 = (int8_t)((uint32_t)uVar2 >> 0x18);
            int8_t cVar5 = (int8_t)((uint32_t)uVar2 >> 8);
            param_3[0] = (float)(int8_t)(((int8_t)uVar2 == -0x80) + (int8_t)uVar2) * 0.007874016f;
            param_3[1] = (float)(int8_t)((cVar5 == -0x80) + cVar5) * 0.007874016f;
            puVar4 = puVar4 + 1;
            pfVar7 = param_3 + 4;
            param_3[2] = (float)(int8_t)((cVar3 == -0x80) + cVar3) * 0.007874016f;
            param_3[3] = (float)(int8_t)((cVar6 == -0x80) + cVar6) * 0.007874016f;
            param_3 = pfVar7;
        } while (puVar4 < puVar1);
    }
    if (*(intptr_t*)((char*)self + 0x18) != 0) {
        FUN_006015d0(pfVar7 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
    if (*(intptr_t*)((char*)self + 0x10) != 0) {
        FUN_0060183d(pfVar7 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
}
// 0x6093ed — observed shape
void FUN_6093ed(void* self, int param_1, int param_2, float* param_3)
{
    int16_t* psVar3 = (int16_t*)(*(intptr_t*)((char*)self + 0x60) * param_1 + *(intptr_t*)((char*)self + 100) * param_2 + *(intptr_t*)((char*)self + 0x20));
    int16_t* psVar1 = psVar3 + *(intptr_t*)((char*)self + 0x68) * 2;
    for (; psVar3 < psVar1; psVar3 = psVar3 + 2) {
        int16_t sVar2 = psVar3[1];
        param_3[0] = (float)(int16_t)((uint16_t)(*psVar3 == -0x8000) + *psVar3) * 3.051851e-05f;
        param_3[1] = (float)(int16_t)((uint16_t)(sVar2 == -0x8000) + sVar2) * 3.051851e-05f;
        param_3[2] = 1.0f;
        param_3[3] = 1.0f;
        param_3 = param_3 + 4;
    }
    if (*(intptr_t*)((char*)self + 0x18) != 0) {
        FUN_006015d0(param_3 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
    if (*(intptr_t*)((char*)self + 0x10) != 0) {
        FUN_0060183d(param_3 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
}

// 0x6094a2 — observed shape
void FUN_6094a2(void* self, int param_1, int param_2, float* param_3)
{
    uint32_t* puVar2 = (uint32_t*)(*(intptr_t*)((char*)self + 0x60) * param_1 + *(intptr_t*)((char*)self + 100) * param_2 + *(intptr_t*)((char*)self + 0x20));
    uint32_t* puVar1 = puVar2 + *(intptr_t*)((char*)self + 0x68);
    for (; puVar2 < puVar1; puVar2 = puVar2 + 1) {
        int16_t sVar3 = (int16_t)((uint16_t)(*puVar2 >> 0x14) << 6) >> 6;
        int16_t sVar5 = (int16_t)((int16_t)*puVar2 << 6) >> 6;
        int16_t sVar4 = (int16_t)((int16_t)(*puVar2 >> 10) << 6) >> 6;
        param_3[0] = (float)(int16_t)((uint16_t)(sVar5 == -0x200) + sVar5) * 0.0019569471f;
        param_3[1] = (float)(int16_t)((uint16_t)(sVar4 == -0x200) + sVar4) * 0.0019569471f;
        param_3[2] = (float)(int16_t)((uint16_t)(sVar3 == -0x200) + sVar3) * 0.0019569471f;
        param_3[3] = (float)(*puVar2 >> 0x1e) * 0.33333334f;
        param_3 = param_3 + 4;
    }
    if (*(intptr_t*)((char*)self + 0x18) != 0) {
        FUN_006015d0(param_3 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
    if (*(intptr_t*)((char*)self + 0x10) != 0) {
        FUN_0060183d(param_3 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
}

// 0x6095ae — observed shape
void FUN_6095ae(void* self, int param_1, int param_2, float* param_3)
{
    int16_t* psVar3 = (int16_t*)(*(intptr_t*)((char*)self + 0x60) * param_1 + *(intptr_t*)((char*)self + 100) * param_2 + *(intptr_t*)((char*)self + 0x20));
    int16_t* psVar1 = psVar3 + *(intptr_t*)((char*)self + 0x68) * 4;
    float* pfVar5 = param_3;
    if (psVar3 < psVar1) {
        do {
            uint32_t uVar2 = *(uint32_t*)(psVar3 + 2);
            int16_t sVar4 = (int16_t)uVar2;
            int16_t sVarLow = (int16_t)(((uint32_t)*(uint32_t*)psVar3) >> 0x10);
            pfVar5[0] = (float)(int16_t)((uint16_t)(*psVar3 == -0x8000) + *psVar3) * 3.051851e-05f;
            pfVar5[1] = (float)(int16_t)((uint16_t)(sVarLow == -0x8000) + sVarLow) * 3.051851e-05f;
            int16_t sVarHigh = (int16_t)((uint32_t)uVar2 >> 0x10);
            psVar3 = psVar3 + 4;
            param_3 = pfVar5 + 4;
            pfVar5[2] = (float)(int16_t)((uint16_t)(sVar4 == -0x8000) + sVar4) * 3.051851e-05f;
            pfVar5[3] = (float)(int16_t)((uint16_t)(sVarHigh == -0x8000) + sVarHigh) * 3.051851e-05f;
            pfVar5 = param_3;
        } while (psVar3 < psVar1);
    }
    if (*(intptr_t*)((char*)self + 0x18) != 0) {
        FUN_006015d0(param_3 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
    if (*(intptr_t*)((char*)self + 0x10) != 0) {
        FUN_0060183d(param_3 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
}

// 0x6096b8 — observed shape
void FUN_6096b8(void* self, int param_1, int param_2, float* param_3)
{
    int8_t* pcVar5 = (int8_t*)(*(intptr_t*)((char*)self + 0x60) * param_1 + *(intptr_t*)((char*)self + 100) * param_2 + *(intptr_t*)((char*)self + 0x20));
    int8_t* pcVar1 = pcVar5 + *(intptr_t*)((char*)self + 0x68) * 2;
    if (pcVar5 < pcVar1) {
        do {
            int8_t cVar2 = pcVar5[1];
            float fVar3 = (float)(int8_t)((*pcVar5 == -0x80) + *pcVar5) * 0.007874016f;
            param_3[0] = fVar3;
            float fVar4 = (float)(int8_t)((cVar2 == -0x80) + cVar2) * 0.007874016f;
            param_3[1] = fVar4;
            fVar3 = (1.0f - fVar3 * fVar3) - fVar4 * fVar4;
            if (isnan(fVar3) || ((fVar3 < 0.0f) == (fVar3 == 0.0f))) {
                fVar3 = sqrtf(fVar3);
            } else {
                fVar3 = 0.0f;
            }
            param_3[2] = fVar3;
            pcVar5 = pcVar5 + 2;
            param_3[3] = 1.0f;
            param_3 = param_3 + 4;
        } while (pcVar5 < pcVar1);
    }
    if (*(intptr_t*)((char*)self + 0x18) != 0) {
        FUN_006015d0(param_3 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
    if (*(intptr_t*)((char*)self + 0x10) != 0) {
        FUN_0060183d(param_3 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
}

// 0x60978c — observed shape
void FUN_60978c(void* self, int param_1, int param_2, float* param_3)
{
    uint16_t* puVar4 = (uint16_t*)(*(intptr_t*)((char*)self + 0x60) * param_1 + *(intptr_t*)((char*)self + 100) * param_2 + *(intptr_t*)((char*)self + 0x20));
    uint16_t* puVar1 = puVar4 + *(intptr_t*)((char*)self + 0x68);
    float* pfVar5 = param_3;
    if (puVar4 < puVar1) {
        do {
            uint16_t uVar2 = *puVar4;
            puVar4 = puVar4 + 1;
            float fVar3 = (float)uVar2 * 1.5259022e-05f;
            param_3[2] = fVar3;
            param_3[1] = fVar3;
            param_3[0] = fVar3;
            pfVar5 = param_3 + 4;
            param_3[3] = 1.0f;
            param_3 = pfVar5;
        } while (puVar4 < puVar1);
    }
    if (*(intptr_t*)((char*)self + 0x18) != 0) {
        FUN_006015d0(pfVar5 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
    if (*(intptr_t*)((char*)self + 0x10) != 0) {
        FUN_0060183d(pfVar5 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
}
// 0x609808 — observed shape
void FUN_609808(void* self, int param_1, int param_2, intptr_t param_3)
{
    uint32_t uVar2 = (uint32_t)(*(intptr_t*)((char*)self + 0x60) * param_1 + *(intptr_t*)((char*)self + 100) * param_2 + *(intptr_t*)((char*)self + 0x20));
    uint32_t uVar1 = uVar2 + *(intptr_t*)((char*)self + 0x68) * 2;
    for (; uVar2 < uVar1; uVar2 = uVar2 + 2) {
        FUN_005f1093((void*)param_3, uVar2, 1);
        *(uint32_t*)(param_3 + 0xc) = 0x3f800000;
        *(uint32_t*)(param_3 + 8) = 0x3f800000;
        *(uint32_t*)(param_3 + 4) = 0x3f800000;
        param_3 = param_3 + 0x10;
    }
    if (*(intptr_t*)((char*)self + 0x18) != 0) {
        FUN_006015d0((void*)(param_3 + *(intptr_t*)((char*)self + 0x68) * -0x10));
    }
    if (*(intptr_t*)((char*)self + 0x10) != 0) {
        FUN_0060183d((void*)(param_3 + *(intptr_t*)((char*)self + 0x68) * -0x10));
    }
}

// 0x60988c — observed shape
void FUN_60988c(void* self, int param_1, int param_2, intptr_t param_3)
{
    uint32_t uVar2 = (uint32_t)(*(intptr_t*)((char*)self + 0x60) * param_1 + *(intptr_t*)((char*)self + 100) * param_2 + *(intptr_t*)((char*)self + 0x20));
    uint32_t uVar1 = uVar2 + *(intptr_t*)((char*)self + 0x68) * 4;
    for (; uVar2 < uVar1; uVar2 = uVar2 + 4) {
        FUN_005f1093((void*)param_3, uVar2, 2);
        *(uint32_t*)(param_3 + 0xc) = 0x3f800000;
        *(uint32_t*)(param_3 + 8) = 0x3f800000;
        param_3 = param_3 + 0x10;
    }
    if (*(intptr_t*)((char*)self + 0x18) != 0) {
        FUN_006015d0((void*)(param_3 + *(intptr_t*)((char*)self + 0x68) * -0x10));
    }
    if (*(intptr_t*)((char*)self + 0x10) != 0) {
        FUN_0060183d((void*)(param_3 + *(intptr_t*)((char*)self + 0x68) * -0x10));
    }
}

// 0x60990c — observed shape
void FUN_60990c(void* self, int param_1, int param_2, void* param_3)
{
    FUN_005f1093(param_3, *(intptr_t*)((char*)self + 0x60) * param_1 + *(intptr_t*)((char*)self + 100) * param_2 + *(intptr_t*)((char*)self + 0x20), *(intptr_t*)((char*)self + 0x68) << 2);
    if (*(intptr_t*)((char*)self + 0x18) != 0) {
        FUN_006015d0(param_3);
    }
    if (*(intptr_t*)((char*)self + 0x10) != 0) {
        FUN_0060183d(param_3);
    }
}

// 0x60995c — observed shape
void FUN_60995c(void* self, int param_1, int param_2, uint32_t* param_3)
{
    uint32_t* puVar3 = (uint32_t*)(*(intptr_t*)((char*)self + 0x60) * param_1 + *(intptr_t*)((char*)self + 100) * param_2 + *(intptr_t*)((char*)self + 0x20));
    uint32_t* puVar1 = puVar3 + *(intptr_t*)((char*)self + 0x68);
    uint32_t* puVar4 = param_3;
    if (puVar3 < puVar1) {
        do {
            uint32_t uVar2 = *puVar3;
            param_3[3] = 0x3f800000;
            param_3[0] = uVar2;
            puVar3 = puVar3 + 1;
            param_3[2] = 0x3f800000;
            puVar4 = param_3 + 4;
            param_3[1] = 0x3f800000;
            param_3 = puVar4;
        } while (puVar3 < puVar1);
    }
    if (*(intptr_t*)((char*)self + 0x18) != 0) {
        FUN_006015d0(puVar4 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
    if (*(intptr_t*)((char*)self + 0x10) != 0) {
        FUN_0060183d(puVar4 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
}

// 0x6099d0 — observed shape
void FUN_6099d0(void* self, int param_1, int param_2, uint32_t* param_3)
{
    uint32_t* puVar3 = (uint32_t*)(*(intptr_t*)((char*)self + 0x60) * param_1 + *(intptr_t*)((char*)self + 100) * param_2 + *(intptr_t*)((char*)self + 0x20));
    uint32_t* puVar1 = puVar3 + *(intptr_t*)((char*)self + 0x68) * 2;
    if (puVar3 < puVar1) {
        do {
            param_3[0] = *puVar3;
            uint32_t uVar2 = puVar3[1];
            param_3[3] = 0x3f800000;
            param_3[1] = uVar2;
            param_3[2] = 0x3f800000;
            puVar3 = puVar3 + 2;
            param_3 = param_3 + 4;
        } while (puVar3 < puVar1);
    }
    if (*(intptr_t*)((char*)self + 0x18) != 0) {
        FUN_006015d0(param_3 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
    if (*(intptr_t*)((char*)self + 0x10) != 0) {
        FUN_0060183d(param_3 + *(intptr_t*)((char*)self + 0x68) * -4);
    }
}
