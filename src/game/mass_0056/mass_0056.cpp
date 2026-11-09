#include <cstdint>
#include <cstddef>
#include <cmath>
#include <windows.h>

extern uint32_t thunk_FUN_00533c78(uint32_t size);
extern void* FUN_0053ca60(void* out, void* src);
extern void FUN_004dafc0(float* out, float* a, float* b);
extern int FUN_004953d0();
extern int FUN_00533db0(int v);
extern void* FUN_00500850();
extern void FUN_00542700(void* a, int b, int c, int d, int e);
extern void FUN_00542cb0(int a, void* b);
extern void FUN_00547730(void* a, void* b, void* c);
extern void FUN_0053c420();
extern void FUN_004db8b0(void* self);
extern void FUN_004dcbf0();
extern void FUN_004dcd70();
extern void operator_delete__(void* p);
extern int FUN_004baaa0();
extern void FUN_004bd700(void* a, float b, float c, float d);
extern void FUN_004dba00(void* self, int idx, int base);
extern void FUN_005be280(const char* name, int sz, void* src);
extern void FUN_00547720();
extern void FUN_004dbba0(int self);
extern void FUN_004dbec0(void* self);
extern void FUN_004dc3f0();
extern void FUN_004dc5a0(void* self);
extern void FUN_0050b760(int v);
extern void FUN_004ee010();
extern void FUN_00502080(void* p);
extern int FUN_00449390(void* a, void* b);
extern void FUN_00501f40(int a, int b);
extern void FUN_005016d0(void* p);
extern void FUN_005c28d0();
extern void* FUN_00500600();
extern void* FUN_00538680();
extern void* FUN_005015e0(void* p);
extern void FUN_00534350();
extern void FUN_00534130();
extern void FUN_00533d10(int a, int b);
extern void FUN_0053c7c0(uint32_t v);
extern void FUN_0053c8d0(void* a, void* b);
extern void* FUN_0053cc20(void* p);
extern char FUN_004dc090(const char* name, void* p);
extern char FUN_004db3d0(const char* name, uint32_t v, void* p);
extern void* PTR_FUN_0070d038;
extern void* PTR_FUN_0070d048;
extern void* PTR_FUN_0070f0d0;
extern unsigned char DAT_00727598;
extern unsigned char DAT_00727560;
extern uint32_t DAT_007263bc;
extern void* DAT_008ea08c;
extern void* DAT_008e9fd8;

// 0x4dadc0 — observed shape
void FUN_004dadc0(float* self, float param_1, float param_2, float param_3)
{
    double fVar4 = (double)std::cos((double)param_1);
    double fVar5 = (double)std::sin((double)param_1);
    double fVar6 = (double)std::cos((double)param_2);
    float fVar1 = (float)fVar6;
    fVar6 = (double)std::sin((double)param_2);
    double fVar7 = (double)std::cos((double)param_3);
    float fVar2 = (float)fVar7;
    fVar7 = (double)std::sin((double)param_3);
    float fVar3 = (float)fVar7;
    self[0] = (float)((double)fVar2 * fVar4 + (double)fVar3 * fVar6 * fVar5);
    self[3] = (float)((double)(float)(fVar6 * fVar4) * (double)fVar3 - (double)fVar2 * fVar5);
    self[6] = fVar3 * fVar1;
    self[1] = (float)((double)fVar1 * fVar5);
    self[4] = (float)((double)fVar1 * fVar4);
    self[7] = (float)-fVar6;
    self[2] = (float)(fVar6 * fVar5 * (double)fVar2 - (double)fVar3 * fVar4);
    self[5] = (float)((double)fVar3 * fVar5 + (double)(float)(fVar6 * fVar4) * (double)fVar2);
    self[8] = fVar2 * fVar1;
}

// 0x4dae80 — observed shape
uint32_t FUN_004dae80(void* self, uint32_t param_1)
{
    uint8_t* self_p = (uint8_t*)self;
    uint8_t* p1_p = (uint8_t*)(uintptr_t)param_1;
    uint32_t* puVar3 = *(uint32_t**)(p1_p + 0xb4);
    if (puVar3 != nullptr) {
        puVar3[1] = puVar3[1] + 1;
    }
    uint32_t uVar9;
    {
        uint32_t* pTmp = *(uint32_t**)((uint8_t*)(uintptr_t)puVar3[10] + 0x2c);
        if (*pTmp == 0) {
            uVar9 = 0;
        } else {
            uVar9 = *(uint32_t*)(pTmp + 1);
        }
    }
    int* piVar1 = (int*)(puVar3 + 1);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
        ((void(*)(int))*(uint32_t*)puVar3)(1);
    }
    puVar3 = *(uint32_t**)(p1_p + 0xb4);
    if (puVar3 != nullptr) {
        puVar3[1] = puVar3[1] + 1;
    }
    int iVar5 = *(int*)((uint8_t*)*(uint32_t**)((uint8_t*)(uintptr_t)puVar3[10] + 0x2c) + 0x18);
    piVar1 = (int*)(puVar3 + 1);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
        ((void(*)(int))*(uint32_t*)puVar3)(1);
    }
    if (iVar5 != 0) {
        uVar9 = uVar9 + (uint32_t)(*(int*)((uint8_t*)(uintptr_t)iVar5 + 4) * 0x38);
    }
    uint32_t uVar7 = uVar9 % *(uint32_t*)(self_p + 0x3c);
    if (*(int*)(self_p + 0x44) == 0) {
        uint32_t uVar2 = thunk_FUN_00533c78((uint32_t)(*(int*)(self_p + 0x40) << 4));
        *(uint32_t*)(self_p + 0x44) = uVar2;
        void* objAt48 = *(void**)(self_p + 0x48);
        void** vtblAt48 = *(void***)objAt48;
        uint32_t* puNew = (uint32_t*)((void*(*)())vtblAt48[1])();
        puNew[2] = *(uint32_t*)(self_p + 0x44);
        puNew[1] = 0;
        *(uint32_t*)puNew = *(uint32_t*)(self_p + 0x4c);
        if (*(int*)(self_p + 0x4c) == 0) {
            *(uint32_t**)(self_p + 0x50) = puNew;
        } else {
            *(uint32_t**)((uint8_t*)*(void**)(self_p + 0x4c) + 4) = puNew;
        }
        *(int*)(self_p + 0x54) = *(int*)(self_p + 0x54) + 1;
        *(uint32_t**)(self_p + 0x4c) = puNew;
        iVar5 = *(int*)(self_p + 0x44);
        uint32_t uVar8 = 1;
        int iVar4 = iVar5;
        if (1 < *(uint32_t*)(self_p + 0x40)) {
            do {
                iVar5 = iVar4 + 0x10;
                *(int*)((uint8_t*)(uintptr_t)iVar4 + 8) = iVar5;
                uVar8 = uVar8 + 1;
                iVar4 = iVar5;
            } while (uVar8 < *(uint32_t*)(self_p + 0x40));
        }
        *(uint32_t*)((uint8_t*)(uintptr_t)iVar5 + 8) = 0;
        *(int*)(self_p + 0x40) = *(int*)(self_p + 0x40) << 1;
    }
    uint32_t* piFree = *(uint32_t**)(self_p + 0x44);
    *(uint32_t*)(self_p + 0x58) = 0;
    *(int*)(self_p + 0x44) = (int)(piFree[2] & 0xffffffffu);
    piFree[0] = param_1;
    piFree[1] = uVar9;
    int iVar5b = *(int*)((uint8_t*)*(void**)(self_p + 0x38) + uVar7 * 4);
    uint32_t uVar6 = (uint32_t)((uintptr_t)piFree >> 8);
    int iVar4b = iVar5b;
    while (true) {
        if (iVar4b == 0) {
            piFree[2] = (uint32_t)(iVar5b & 0xffffffffu);
            *(uint32_t**)((uint8_t*)*(void**)(self_p + 0x38) + uVar7 * 4) = piFree;
            piFree[3] = 0;
            return (uint32_t)((uVar6 << 8) & 0xFFFFFF00u) | 1u;
        }
        if (*(uint32_t*)((uint8_t*)(uintptr_t)iVar4b + 4) == uVar9) break;
        iVar4b = *(int*)((uint8_t*)(uintptr_t)iVar4b + 8);
    }
    piFree[3] = (uint32_t)(*(int*)((uint8_t*)(uintptr_t)iVar4b + 0xc) & 0xffffffffu);
    *(uint32_t**)((uint8_t*)(uintptr_t)iVar4b + 0xc) = piFree;
    return (uint32_t)((uVar6 << 8) & 0xFFFFFF00u) | 1u;
}

// 0x4dafc0 — observed shape
void FUN_004dafc0(float* self, float* srcA, float* srcB)
{
    self[0] = srcA[6] * srcB[2] + srcB[0] * srcA[0] + srcB[1] * srcA[3];
    self[3] = srcB[3] * srcA[0] + srcB[5] * srcA[6] + srcB[4] * srcA[3];
    self[6] = srcA[3] * srcB[7] + srcB[6] * srcA[0] + srcB[8] * srcA[6];
    self[1] = srcA[4] * srcB[1] + srcA[7] * srcB[2] + srcA[1] * srcB[0];
    self[4] = srcB[3] * srcA[1] + srcA[4] * srcB[4] + srcA[7] * srcB[5];
    self[7] = srcB[6] * srcA[1] + srcA[4] * srcB[7] + srcB[8] * srcA[7];
    self[2] = srcA[2] * srcB[0] + srcB[1] * srcA[5] + srcA[8] * srcB[2];
    self[5] = srcB[4] * srcA[5] + srcB[3] * srcA[2] + srcA[8] * srcB[5];
    self[8] = srcB[7] * srcA[5] + srcB[8] * srcA[8] + srcB[6] * srcA[2];
}

// 0x4db0a0 — observed shape
void FUN_004db0a0(void* self)
{
    uint8_t* self_p = (uint8_t*)self;
    int iVar3 = *(int*)(self_p + 0x24);
    float local_18 = 0.0f;
    float local_14 = 0.0f;
    float local_10 = 0.0f;
    float local_8 = 0.0f;
    float local_4 = 0.0f;
    if (iVar3 == 0) {
        uint32_t* puVar4 = (uint32_t*)(self_p + 0x38);
        uint32_t* puVar5 = (uint32_t*)(self_p + 0x6c);
        for (int i = 0xd; i != 0; i = i + -1) {
            *puVar5 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar5 = puVar5 + 1;
        }
    } else {
        *(float*)(self_p + 0x9c) = *(float*)(self_p + 0x68) * *(float*)((uint8_t*)(uintptr_t)iVar3 + 0x9c);
        float* pfVar2 = (float*)FUN_0053ca60(&local_18, self_p + 0x5c);
        float fVar1 = *(float*)((uint8_t*)(uintptr_t)iVar3 + 0x9c);
        local_8 = fVar1 * pfVar2[1];
        local_4 = fVar1 * pfVar2[2];
        local_18 = fVar1 * pfVar2[0] + *(float*)((uint8_t*)(uintptr_t)iVar3 + 0x90);
        local_14 = local_8 + *(float*)((uint8_t*)(uintptr_t)iVar3 + 0x94);
        local_10 = local_4 + *(float*)((uint8_t*)(uintptr_t)iVar3 + 0x98);
        *(float*)(self_p + 0x90) = local_18;
        *(float*)(self_p + 0x94) = local_14;
        *(float*)(self_p + 0x98) = local_10;
        FUN_004dafc0((float*)(self_p + 0x6c), (float*)(self_p + 0x38), pfVar2);
    }
    if (*(int**)(self_p + 0xb0) != nullptr) {
        void** vtbl = *(void***)((uint8_t*)*(void**)(self_p + 0xb0) + 0x38);
        ((void(*)())vtbl[0])();
    }
}

// 0x4db150 — observed shape
uint32_t FUN_004db150(uint32_t in_EAX, uint32_t in_ESI)
{
    uint32_t uVar1 = (uint32_t)(-(int32_t)in_EAX);
    uint32_t uVar4 = (uint32_t)((int32_t)uVar1 >> 0x1f);
    uint32_t uVar5 = (uint32_t)((int32_t)in_ESI >> 0x1f);
    uint32_t uVar6;
    if ((int32_t)in_ESI < 1) {
        if ((int32_t)uVar1 < 1) {
            int iVar3 = (int)((uVar1 ^ uVar4) - uVar4);
            int iVar2 = (int)((in_ESI ^ uVar5) - uVar5);
            uVar6 = 7;
            if (iVar3 * 2 < iVar2) {
                uVar6 = 6;
            }
            if (iVar2 * 2 < iVar3) {
                return 0;
            }
        } else {
            int iVar3 = (int)((uVar1 ^ uVar4) - uVar4);
            int iVar2 = (int)((in_ESI ^ uVar5) - uVar5);
            uVar6 = 5;
            if (iVar3 * 2 < iVar2) {
                uVar6 = 6;
            }
            if (iVar2 * 2 < iVar3) {
                return 4;
            }
        }
    } else if ((int32_t)uVar1 < 1) {
        int iVar3 = (int)((uVar1 ^ uVar4) - uVar4);
        int iVar2 = (int)((in_ESI ^ uVar5) - uVar5);
        uVar6 = 1;
        if (iVar3 * 2 < iVar2) {
            uVar6 = 2;
        }
        if (iVar2 * 2 < iVar3) {
            return 0;
        }
    } else {
        int iVar3 = (int)((uVar1 ^ uVar4) - uVar4);
        int iVar2 = (int)((in_ESI ^ uVar5) - uVar5);
        uVar6 = 3;
        if (iVar3 * 2 < iVar2) {
            uVar6 = 2;
        }
        if (iVar2 * 2 < iVar3) {
            return 4;
        }
    }
    return uVar6;
}
// 0x4db210 — observed shape
int FUN_004db210(uint32_t in_EAX, int32_t in_ECX)
{
    if (in_ECX < 0) {
        in_EAX = (uint32_t)(-(int32_t)in_EAX);
    }
    int iVar2 = 1;
    int iVar1 = (int)((in_EAX ^ (uint32_t)((int32_t)in_EAX >> 0x1f)) - (uint32_t)((int32_t)in_EAX >> 0x1f));
    while (32000 < iVar1) {
        in_EAX = (uint32_t)((int32_t)in_EAX / 2);
        iVar2 = iVar2 * 2;
        iVar1 = (int)((in_EAX ^ (uint32_t)((int32_t)in_EAX >> 0x1f)) - (uint32_t)((int32_t)in_EAX >> 0x1f));
    }
    int iVar3 = FUN_004953d0();
    return iVar3 * iVar2;
}

// 0x4db270 — observed shape
uint32_t FUN_004db270(uint32_t in_EAX, uint32_t in_ECX)
{
    if (in_ECX == 0) {
        return (uint32_t)((((int32_t)in_EAX > 0) ? 1 : 0) & 0xFFFFFFFFu) - 1u & 0x80000000u;
    }
    if (in_EAX == 0) {
        return (uint32_t)(((int32_t)in_ECX < 1 ? 1 : 0) & 0xFFFFFFFFu) - 1u & 0x80000000u + 0xc0000000u;
    }
    int iVar4 = (int)((in_ECX ^ (uint32_t)((int32_t)in_ECX >> 0x1f)) - (uint32_t)((int32_t)in_ECX >> 0x1f));
    int iVar2 = (int)((in_EAX ^ (uint32_t)((int32_t)in_EAX >> 0x1f)) - (uint32_t)((int32_t)in_EAX >> 0x1f));
    bool bVar1;
    uint32_t uVar3 = 0;
    if (iVar2 < iVar4) {
        while (true) {
            uVar3 = (uint32_t)((int32_t)in_EAX >> 0x1f);
            if (!(0x10000 < (uint32_t)iVar2)) break;
            in_EAX = (uint32_t)((int32_t)in_EAX >> 1);
            in_ECX = (uint32_t)((int32_t)in_ECX >> 1);
            iVar2 = (int)((in_EAX ^ uVar3) - uVar3);
        }
        iVar2 = (int)((in_EAX ^ uVar3) - uVar3);
        iVar4 = (int)((in_ECX ^ (uint32_t)((int32_t)in_ECX >> 0x1f)) - (uint32_t)((int32_t)in_ECX >> 0x1f));
        bVar1 = true;
    } else {
        while (true) {
            uVar3 = (uint32_t)((int32_t)in_ECX >> 0x1f);
            if (!(0x10000 < (uint32_t)iVar4)) break;
            in_ECX = (uint32_t)((int32_t)in_ECX >> 1);
            in_EAX = (uint32_t)((int32_t)in_EAX >> 1);
            iVar4 = (int)((in_ECX ^ uVar3) - uVar3);
        }
        iVar2 = (int)((in_ECX ^ uVar3) - uVar3);
        iVar4 = (int)((in_EAX ^ (uint32_t)((int32_t)in_EAX >> 0x1f)) - (uint32_t)((int32_t)in_EAX >> 0x1f));
        bVar1 = false;
    }
    iVar4 = (iVar2 * 0x4000) / iVar4;
    {
        uint32_t uVar3a = (uint32_t)(0x1333 - (uint32_t)iVar4);
        uint32_t uVar5 = (uint32_t)((int32_t)uVar3a >> 0x1f);
        uint32_t absV = (uVar3a ^ uVar5) - uVar5;
        iVar4 = (int)((0x2800u - (uint32_t)(((int32_t)absV * 0xb00) >> 0xe)) * (uint32_t)iVar4 >> 0xe);
    }
    if ((int32_t)in_ECX < 1) {
        if ((int32_t)in_EAX < 1) {
            if (bVar1) {
                return (uint32_t)((0xc000 - iVar4) * 0x10000);
            }
            return (uint32_t)((iVar4 + 0x8000) * 0x10000);
        }
        if (bVar1) {
            return (uint32_t)((iVar4 + 0xc000) * 0x10000);
        }
        iVar4 = -iVar4;
    } else {
        if ((int32_t)in_EAX < 1) {
            if (bVar1) {
                return (uint32_t)((iVar4 + 0x4000) * 0x10000);
            }
            return (uint32_t)((0x8000 - iVar4) * 0x10000);
        }
        if (bVar1) {
            return (uint32_t)((0x4000 - iVar4) * 0x10000);
        }
    }
    return (uint32_t)(iVar4 << 0x10);
}

// 0x4db3d0 — observed shape
unsigned char FUN_004db3d0(uint32_t param_1, uint32_t param_2, int32_t* param_3)
{
    unsigned char bVar5 = 1;
    unsigned char local_4 = 1;
    if ((param_3[3] != 0) && (((((*(unsigned char*)((uint8_t*)param_3 + 0x20) & 1) != 0 || _stricmp((const char*)(uintptr_t)param_3[3], "window") == 0) || _strnicmp((const char*)(uintptr_t)param_3[3], "glow", 4) == 0) || (_strnicmp((const char*)(uintptr_t)param_3[3], "plane", 4) == 0 || _stricmp((const char*)(uintptr_t)param_3[3], "Object02") == 0)))) {
        return 1;
    }
    int iVar2 = FUN_00533db0(8);
    if (iVar2 != 0) {
        iVar2 = FUN_00533db0(8);
        if ((*(int*)((uint8_t*)(uintptr_t)iVar2 + 0x44) == 0) || (*(uint32_t*)(*(int*)((uint8_t*)(uintptr_t)iVar2 + 0x44) + 0x10) < 2)) {
            void* uVar3 = FUN_00500850();
            uint32_t* puVar4 = (uint32_t*)FUN_00533c78(0x20);
            if (puVar4 == nullptr) {
                puVar4 = nullptr;
            } else {
                FUN_00542700(uVar3, 1, 0, 1, 0);
                puVar4[0] = (uint32_t)(uintptr_t)&PTR_FUN_0070d038;
                puVar4[7] = 0;
            }
            FUN_00542cb0(1, puVar4);
        }
    }
    uint32_t* puVar4 = (uint32_t*)((void*(*)())*(void**)((uint8_t*)(uintptr_t)param_3[0] + 4))();
    while (puVar4 != nullptr) {
        if ((void*)puVar4 == (void*)&DAT_00727598) {
            FUN_00547730(param_3, (void*)(uintptr_t)param_1, (void*)(uintptr_t)param_2);
            return 1;
        }
        puVar4 = (uint32_t*)puVar4[1];
    }
    puVar4 = (uint32_t*)((void*(*)())*(void**)((uint8_t*)(uintptr_t)param_3[0] + 4))();
    if (puVar4 != nullptr) {
        while ((void*)puVar4 != (void*)&DAT_00727560) {
            puVar4 = (uint32_t*)puVar4[1];
            if (puVar4 == nullptr) {
                return 1;
            }
        }
        uint32_t uVar6 = 0;
        if (param_3[0x30] != 0) {
            bVar5 = 1;
            if (param_3[0x30] == 0) {
                goto LAB_004db551;
            }
            do {
                iVar2 = *(int*)((uint8_t*)(uintptr_t)param_3[0x2e] + uVar6 * 4);
                if (iVar2 != 0) {
                    char cVar1 = FUN_004db3d0(param_1, param_2, (int32_t*)(uintptr_t)iVar2);
                    bVar5 = (unsigned char)(-(cVar1 != '\0') & local_4);
                    local_4 = bVar5;
                }
            LAB_004db551:
                uVar6 = uVar6 + 1;
            } while (uVar6 < (uint32_t)param_3[0x30]);
        }
    }
    return bVar5;
}

// 0x4db570 — observed shape
const char* FUN_004db570(uint32_t in_EAX)
{
    switch (in_EAX) {
    case 0:
    case 1:
        return "TownSneakOneLight";
    case 2:
        return "TownSneakTwoLight";
    case 3:
        return "TownSneakThreeLight";
    case 4:
        return "TownSneakFourLight";
    case 5:
        return "TownSneakFiveLight";
    case 6:
        return "TownSneakSixLight";
    case 7:
        return "TownSneakSevenLight";
    default:
        return "TownSneakEightLight";
    }
}

// 0x4db5d0 — observed shape
void FUN_004db5d0(void* self)
{
    uint32_t* unaff_ESI = (uint32_t*)self;
    int local_10;
    unaff_ESI[0x79] = 1;
    unaff_ESI[0x76] = 0;
    unaff_ESI[0x77] = 0;
    unaff_ESI[0x78] = 0;
    unaff_ESI[0x75] = 0;
    unaff_ESI[0x74] = (uint32_t)(uintptr_t)&PTR_FUN_0070d048;
    unaff_ESI[0x7f] = 1;
    unaff_ESI[0x7a] = (uint32_t)(uintptr_t)&PTR_FUN_0070d048;
    unaff_ESI[0x7c] = 0;
    unaff_ESI[0x7d] = 0;
    unaff_ESI[0x7e] = 0;
    unaff_ESI[0x7b] = 0;
    unaff_ESI[0x85] = 1;
    unaff_ESI[0x80] = (uint32_t)(uintptr_t)&PTR_FUN_0070d048;
    unaff_ESI[0x82] = 0;
    unaff_ESI[0x83] = 0;
    unaff_ESI[0x84] = 0;
    unaff_ESI[0x81] = 0;
    unaff_ESI[0x8b] = 1;
    unaff_ESI[0x86] = (uint32_t)(uintptr_t)&PTR_FUN_0070d048;
    unaff_ESI[0x88] = 0;
    unaff_ESI[0x89] = 0;
    unaff_ESI[0x8a] = 0;
    unaff_ESI[0x87] = 0;
    unaff_ESI[0x92] = 0;
    unaff_ESI[0x90] = 0;
    unaff_ESI[0x91] = 0;
    unaff_ESI[0x8f] = (uint32_t)(uintptr_t)&PTR_FUN_0070f0d0;
    unaff_ESI[0xa9] = 0;
    unaff_ESI[0xaa] = 0;
    unaff_ESI[0xab] = 0;
    unaff_ESI[0xac] = 0;
    unaff_ESI[0xad] = 0;
    unaff_ESI[0xae] = 0;
    unaff_ESI[0xaf] = 0;
    unaff_ESI[0xb0] = 0;
    unaff_ESI[0xb1] = 0;
    unaff_ESI[0xb2] = 0;
    unaff_ESI[0xb3] = 0;
    unaff_ESI[0xb4] = 0;
    unaff_ESI[0xb5] = 0;
    unaff_ESI[0xb6] = 0;
    unaff_ESI[0xb7] = 0;
    unaff_ESI[0xb8] = 0;
    unaff_ESI[0xb9] = 0;
    unaff_ESI[0xba] = 0;
    unaff_ESI[0xbb] = 0;
    unaff_ESI[0xbc] = 0;
    unaff_ESI[0] = 0x39aec33e;
    unaff_ESI[1] = 0x4b095440;
    uint32_t* puVar1 = unaff_ESI + 2;
    local_10 = 8;
    do {
        puVar1[0] = 0;
        puVar1[1] = 0;
        puVar1[2] = 0x42c80000;
        FUN_0053c420();
        puVar1 = puVar1 + 3;
        local_10 = local_10 + -1;
    } while (local_10 != 0);
    unaff_ESI[0x62] = 0x4b189680;
    unaff_ESI[99] = 0xca989680;
    unaff_ESI[100] = 0xcb189680;
    unaff_ESI[0x65] = 0;
    unaff_ESI[0x66] = 0;
    unaff_ESI[0x67] = 0x3f800000;
    *(unsigned char*)((uint8_t*)unaff_ESI + 0x93 * 4) = 0;
    *(unsigned char*)((uint8_t*)unaff_ESI + 0x8e * 4) = 0;
    FUN_004db8b0(self);
}
// 0x4db7e0 — observed shape
void FUN_004db7e0(void* self)
{
    uint8_t* self_p = (uint8_t*)self;
    uint32_t* puVar3 = *(uint32_t**)(self_p + 0x240);
    while (puVar3 != nullptr) {
        uint32_t* puVar2 = (uint32_t*)puVar3[0];
        void* vtblBase = *(void**)(self_p + 0x23c);
        void** vtbl = *(void***)vtblBase;
        ((void(*)(uint32_t*))vtbl[2])(puVar3);
        puVar3 = puVar2;
    }
    *(uint32_t*)(self_p + 0x248) = 0;
    *(uint32_t*)(self_p + 0x240) = 0;
    *(uint32_t*)(self_p + 0x244) = 0;
    FUN_004dcbf0();
    int iVar4 = (int)(uintptr_t)(self_p + 0x2f4);
    int iStack_4 = 0x14;
    do {
        puVar3 = *(uint32_t**)((uint8_t*)(uintptr_t)(iVar4 - 4));
        iVar4 = iVar4 + -4;
        if (puVar3 != nullptr) {
            int* piVar1 = (int*)(puVar3 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                ((void(*)(int))*(uint32_t*)puVar3)(1);
            }
        }
        iStack_4 = iStack_4 + -1;
    } while (iStack_4 != 0);
    FUN_004dcd70();
    *(void**)(self_p + 0x218) = &PTR_FUN_0070d048;
    operator_delete__(*(void**)(self_p + 0x21c));
    *(void**)(self_p + 0x200) = &PTR_FUN_0070d048;
    operator_delete__(*(void**)(self_p + 0x204));
    *(void**)(self_p + 0x1e8) = &PTR_FUN_0070d048;
    operator_delete__(*(void**)(self_p + 0x1ec));
    *(void**)(self_p + 0x1d0) = &PTR_FUN_0070d048;
    operator_delete__(*(void**)(self_p + 0x1d4));
}

// 0x4db8b0 — observed shape
void FUN_004db8b0(void* self)
{
    uint8_t* self_p = (uint8_t*)self;
    int iVar4 = (int)(uintptr_t)self_p;
    uint32_t* puVar5 = (uint32_t*)FUN_00500600();
    uint32_t* puVar2 = *(uint32_t**)(self_p + 0x2a4);
    uint32_t* puVar7 = (uint32_t*)(self_p + 0x2a4);
    if (puVar2 != puVar5) {
        if (puVar2 != nullptr) {
            int* piVar6 = (int*)(puVar2 + 1);
            *piVar6 = *piVar6 + -1;
            if (*piVar6 == 0) {
                ((void(*)(int))*(uint32_t*)puVar2)(1);
            }
        }
        puVar7[0] = (uint32_t)(uintptr_t)puVar5;
        if (puVar5 != nullptr) {
            puVar5[1] = puVar5[1] + 1;
        }
    }
    int* piVar6 = (int*)(self_p + 0x2a8);
    int param_1 = 0x13;
    do {
        puVar5 = (uint32_t*)FUN_00538680();
        puVar2 = (uint32_t*)*piVar6;
        if (puVar2 != puVar5) {
            if (puVar2 != nullptr) {
                int* piVar1 = (int*)(puVar2 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    ((void(*)(int))*(uint32_t*)puVar2)(1);
                }
            }
            *(uint32_t*)piVar6 = (uint32_t)(uintptr_t)puVar5;
            if (puVar5 != nullptr) {
                puVar5[1] = puVar5[1] + 1;
            }
        }
        piVar6 = piVar6 + 1;
        param_1 = param_1 + -1;
    } while (param_1 != 0);
    double fVar9 = (double)(float)FUN_005015e0((void*)puVar7[0]);
    *(float*)(self_p + 0x250) = (float)fVar9;
    uint32_t uVar8 = 0;
    do {
        FUN_00534350();
        FUN_00534130();
        FUN_00533d10(0, 1);
        float fVar3 = (float)(int)uVar8;
        if ((int)uVar8 < 0) {
            fVar3 = fVar3 + 4.2949673e+09f;
        }
        uVar8 = uVar8 + 1;
        puVar7[-0x14] = fVar3 * *(float*)(self_p + 0x250) * 0.05f;
        puVar7 = puVar7 + 1;
    } while (uVar8 < 0x14);
}

// 0x4db9a0 — observed shape
void FUN_004db9a0(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3)
{
    uint8_t* self_p = (uint8_t*)self;
    *(uint32_t*)(self_p + 0x1a4) = param_1;
    *(uint32_t*)(self_p + 0x1b0) = param_2;
    *(uint32_t*)(self_p + 0x1b4) = param_2;
    *(uint32_t*)(self_p + 0x1a0) = 0;
    *(uint32_t*)(self_p + 0x1a8) = 0;
    *(uint32_t*)(self_p + 0x1ac) = 0;
    *(uint32_t*)(self_p + 0x1b8) = 0;
    *(uint32_t*)(self_p + 0x1bc) = 0;
    *(uint32_t*)(self_p + 0x1c0) = 0;
    *(uint32_t*)(self_p + 0x1c4) = param_3;
    *(uint32_t*)(self_p + 0x1c8) = 0;
    *(uint32_t*)(self_p + 0x1cc) = 0;
}

// 0x4dba00 — observed shape
void FUN_004dba00(int32_t unaff_EBX, int32_t unaff_ESI, int32_t unaff_EDI)
{
    FUN_00547720();
    switch (unaff_EBX) {
    case 0:
        FUN_005be280("f3LightPos1", 0xc, (void*)(uintptr_t)(unaff_EDI + 8 + unaff_ESI * 0xc));
        FUN_005be280("mtxLightRot1", 0x24, (void*)(uintptr_t)(unaff_EDI + 0x68 + unaff_ESI * 0x24));
        return;
    case 1:
        FUN_005be280("f3LightPos2", 0xc, (void*)(uintptr_t)(unaff_EDI + 8 + unaff_ESI * 0xc));
        FUN_005be280("mtxLightRot2", 0x24, (void*)(uintptr_t)(unaff_EDI + 0x68 + unaff_ESI * 0x24));
        return;
    case 2:
        FUN_005be280("f3LightPos3", 0xc, (void*)(uintptr_t)(unaff_EDI + 8 + unaff_ESI * 0xc));
        FUN_005be280("mtxLightRot3", 0x24, (void*)(uintptr_t)(unaff_EDI + 0x68 + unaff_ESI * 0x24));
        return;
    case 3:
        FUN_005be280("f3LightPos4", 0xc, (void*)(uintptr_t)(unaff_EDI + 8 + unaff_ESI * 0xc));
        FUN_005be280("mtxLightRot4", 0x24, (void*)(uintptr_t)(unaff_EDI + 0x68 + unaff_ESI * 0x24));
        return;
    case 4:
        FUN_005be280("f3LightPos5", 0xc, (void*)(uintptr_t)(unaff_EDI + 8 + unaff_ESI * 0xc));
        FUN_005be280("mtxLightRot5", 0x24, (void*)(uintptr_t)(unaff_EDI + 0x68 + unaff_ESI * 0x24));
        return;
    case 5:
        FUN_005be280("f3LightPos6", 0xc, (void*)(uintptr_t)(unaff_EDI + 8 + unaff_ESI * 0xc));
        FUN_005be280("mtxLightRot6", 0x24, (void*)(uintptr_t)(unaff_EDI + 0x68 + unaff_ESI * 0x24));
        return;
    case 6:
        FUN_005be280("f3LightPos7", 0xc, (void*)(uintptr_t)(unaff_EDI + 8 + unaff_ESI * 0xc));
        FUN_005be280("mtxLightRot7", 0x24, (void*)(uintptr_t)(unaff_EDI + 0x68 + unaff_ESI * 0x24));
        return;
    case 7:
        FUN_005be280("f3LightPos8", 0xc, (void*)(uintptr_t)(unaff_EDI + 8 + unaff_ESI * 0xc));
        FUN_005be280("mtxLightRot8", 0x24, (void*)(uintptr_t)(unaff_EDI + 0x68 + unaff_ESI * 0x24));
    }
}

// 0x4dbba0 — observed shape
void FUN_004dbba0(void* self)
{
    uint8_t* self_p = (uint8_t*)self;
    uint32_t local_88 = 0;
    if (*(int*)(self_p + 0x1e0) != 0) {
        float* pfVar8 = (float*)(self_p + 8);
        float* pfVar7 = (float*)(self_p + 0x80);
        do {
            uint32_t uVar1 = *(uint32_t*)(*(uint32_t*)(self_p + 0x1d4) + local_88 * 4);
            if (local_88 < 8) {
                int* piVar4 = (int*)(uintptr_t)FUN_004baaa0();
                int iVar5 = (int)((void*(*)())*(void**)(*(void**)((uint8_t*)(uintptr_t)piVar4 + 0x0) + 8))("object0");
                pfVar8[0] = *(float*)((uint8_t*)(uintptr_t)iVar5 + 0x90);
                pfVar8[1] = *(float*)((uint8_t*)(uintptr_t)iVar5 + 0x94);
                pfVar8[2] = *(float*)((uint8_t*)(uintptr_t)iVar5 + 0x98);
                iVar5 = FUN_004baaa0();
                float fVar2 = pfVar8[0] - *(float*)((uint8_t*)(uintptr_t)iVar5 + 0x90);
                float fVar3 = pfVar8[1] - *(float*)((uint8_t*)(uintptr_t)iVar5 + 0x94);
                FUN_004bd700((void*)(uintptr_t)uVar1, -fVar2, -fVar3, -(pfVar8[2] - *(float*)((uint8_t*)(uintptr_t)iVar5 + 0x98)));
                float fStack_8c = (float)std::sqrt((double)(fVar2 * fVar2 + fVar3 * fVar3));
                if (fStack_8c <= 1e-06f) {
                    fStack_8c = 0.0f;
                    fVar2 = 0.0f;
                    fVar3 = 0.0f;
                } else {
                    fStack_8c = 1.0f / fStack_8c;
                    fVar2 = fStack_8c * fVar2;
                    fVar3 = fVar3 * fStack_8c;
                    fStack_8c = fStack_8c * 0.0f;
                }
                float* pfVar9 = pfVar7 + -6;
                pfVar7[0] = fVar2 * 0.0f - fVar3 * 0.0f;
                pfVar9[0] = fVar3 - fStack_8c * 0.0f;
                pfVar7[-3] = fStack_8c * 0.0f - fVar2;
                pfVar7[1] = fStack_8c;
                pfVar7[-5] = fVar2;
                pfVar7[-2] = fVar3;
                pfVar7[-4] = 0.0f;
                pfVar7[-1] = 0.0f;
                pfVar7[2] = 1.0f;
                FUN_0053c7c0(0xbe860a92);
                uint8_t auStack_24[36];
                uint8_t auStack_48[36];
                FUN_0053c8d0(auStack_24, pfVar9);
                float* pfVar6 = (float*)FUN_0053cc20(auStack_48);
                for (int i = 9; i != 0; i = i + -1) {
                    *pfVar9 = *pfVar6;
                    pfVar6 = pfVar6 + 1;
                    pfVar9 = pfVar9 + 1;
                }
            }
            local_88 = local_88 + 1;
            pfVar8 = pfVar8 + 3;
            pfVar7 = pfVar7 + 9;
        } while (local_88 < *(uint32_t*)(self_p + 0x1e0));
    }
}

// 0x4dbda0 — observed shape
int FUN_004dbda0(float* self)
{
    int iVar8 = FUN_004baaa0();
    float fVar1 = *(float*)((uint8_t*)(uintptr_t)iVar8 + 0x28);
    float fVar2 = *(float*)((uint8_t*)(uintptr_t)iVar8 + 0x2c);
    float fVar3 = self[0x78];
    float fVar4 = *(float*)((uint8_t*)(uintptr_t)iVar8 + 0x34);
    int iVar9 = 0;
    float fVar10 = 0.0f;
    if (fVar3 != 0.0f) {
        do {
            if (7 < (uint32_t)fVar10) {
                return iVar9;
            }
            uint32_t uVar9 = 2;
            float fVar5 = fVar1 - self[2];
            float fVar6 = 1.0f;
            while (true) {
                if ((uVar9 & 1) != 0) {
                    fVar6 = fVar6 * fVar5;
                }
                uVar9 = uVar9 >> 1;
                if (uVar9 == 0) break;
                fVar5 = fVar5 * fVar5;
            }
            uVar9 = 2;
            float fVar7 = fVar2 - self[3];
            fVar5 = 1.0f;
            while (true) {
                if ((uVar9 & 1) != 0) {
                    fVar5 = fVar5 * fVar7;
                }
                uVar9 = uVar9 >> 1;
                if (uVar9 == 0) break;
                fVar7 = fVar7 * fVar7;
            }
            uVar9 = 2;
            fVar5 = fVar5 + fVar6;
            fVar7 = fVar4 + 3000.0f;
            fVar6 = 1.0f;
            while (true) {
                if ((uVar9 & 1) != 0) {
                    fVar6 = fVar6 * fVar7;
                }
                uVar9 = uVar9 >> 1;
                if (uVar9 == 0) break;
                fVar7 = fVar7 * fVar7;
            }
            if (!std::isnan(fVar5) && !std::isnan(fVar6) && ((fVar5 < fVar6) != (fVar5 == fVar6))) {
                FUN_004dba00((int32_t)fVar10, (int32_t)(uintptr_t)self, 24);
                iVar9 = iVar9 + 1;
            }
            fVar10 = (float)((int)fVar10 + 1);
            self = self + 3;
        } while ((uint32_t)fVar10 < (uint32_t)fVar3);
    }
    return iVar9;
}

// 0x4dbec0 — observed shape
void FUN_004dbec0(void* self)
{
    uint8_t* self_p = (uint8_t*)self;
    if (*(char*)(self_p + 0x24c) != '\0') {
        FUN_004dbba0(self);
        FUN_00547720();
        FUN_005be280("fIntensityMod", 0x10, self_p + 0x1a0);
        FUN_005be280("fRedGreenMod", 0x10, self_p + 0x1b0);
        FUN_005be280("fAmbient", 0x10, self_p + 0x1c0);
        FUN_005be280("f3DirLight", 0xc, self_p + 0x188);
        FUN_005be280("f3BackgroundColor", 0xc, self_p + 0x194);
        FUN_005be280("f3ViewPos", 0xc, (uint8_t*)DAT_008e9fd8 + 0x5c);
        FUN_005be280("fLightRange", 4, nullptr);
        FUN_005be280("f3LightPos1", 0xc, self_p + 8);
        FUN_005be280("f3LightPos2", 0xc, self_p + 0x14);
        FUN_005be280("f3LightPos3", 0xc, self_p + 0x20);
        FUN_005be280("f3LightPos4", 0xc, self_p + 0x2c);
        FUN_005be280("f3LightPos5", 0xc, self_p + 0x38);
        FUN_005be280("f3LightPos6", 0xc, self_p + 0x44);
        FUN_005be280("f3LightPos7", 0xc, self_p + 0x50);
        FUN_005be280("f3LightPos8", 0xc, self_p + 0x5c);
        FUN_005be280("mtxLightRot1", 0x24, self_p + 0x68);
        FUN_005be280("mtxLightRot2", 0x24, self_p + 0x8c);
        FUN_005be280("mtxLightRot3", 0x24, self_p + 0xb0);
        FUN_005be280("mtxLightRot4", 0x24, self_p + 0xd4);
        FUN_005be280("mtxLightRot5", 0x24, self_p + 0xf8);
        FUN_005be280("mtxLightRot6", 0x24, self_p + 0x11c);
        FUN_005be280("mtxLightRot7", 0x24, self_p + 0x140);
        FUN_005be280("mtxLightRot8", 0x24, self_p + 0x164);
    }
}

// 0x4dc090 — observed shape
char FUN_004dc090(uint32_t param_1, int32_t* param_2)
{
    char local_1 = '\0';
    char cVar3 = local_1;
    local_1 = '\0';
    if (param_2 != nullptr) {
        uint32_t* puVar4 = (uint32_t*)((void*(*)())*(void**)((uint8_t*)(uintptr_t)param_2[0] + 4))();
        while (puVar4 != nullptr) {
            if ((void*)puVar4 == (void*)&DAT_00727598) {
                local_1 = '\x01';
                FUN_00547730(param_2, (void*)(uintptr_t)param_1, (void*)(uintptr_t)0xffffffffu);
                puVar4 = (uint32_t*)(uintptr_t)param_2[0x32];
                if (puVar4 != nullptr) {
                    puVar4[1] = puVar4[1] + 1;
                }
                FUN_004ee010();
                if (puVar4 != nullptr) {
                    int* piVar1 = (int*)(puVar4 + 1);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) {
                        ((void(*)(int))*(uint32_t*)puVar4)(1);
                        return (char)(0);
                    }
                }
                goto LAB_004dc183;
            }
            puVar4 = (uint32_t*)puVar4[1];
        }
        puVar4 = (uint32_t*)((void*(*)())*(void**)((uint8_t*)(uintptr_t)param_2[0] + 4))();
        local_1 = cVar3;
        if (puVar4 != nullptr) {
            while ((void*)puVar4 != (void*)&DAT_00727560) {
                puVar4 = (uint32_t*)puVar4[1];
                if (puVar4 == nullptr) {
                    return '\0';
                }
            }
            uint32_t uVar5 = (uint32_t)param_2[0x30];
            uint32_t uVar6 = 0;
            if (uVar5 != 0) {
                local_1 = '\0';
                do {
                    if (local_1 != '\0') break;
                    if ((uVar6 < uVar5) && (((int)(*(int*)((uint8_t*)(uintptr_t)param_2[0x2e] + uVar6 * 4)) != 0))) {
                        int iVar2 = *(int*)((uint8_t*)(uintptr_t)param_2[0x2e] + uVar6 * 4);
                        local_1 = FUN_004dc090(param_1, (int32_t*)(uintptr_t)iVar2);
                    }
                    uVar5 = (uint32_t)param_2[0x30];
                    uVar6 = uVar6 + 1;
                } while (uVar6 < uVar5);
            }
        }
    }
LAB_004dc183:
    return local_1;
}

// 0x4dc190 — observed shape
void FUN_004dc190(void* self)
{
    uint8_t* self_p = (uint8_t*)self;
    void* in_EAX = self;
    if (*(char*)(self_p + 0x24c) == '\0') {
        int uVar3 = FUN_004baaa0();
        FUN_00502080((void*)(uintptr_t)uVar3);
        int piVar4_addr = FUN_004baaa0();
        int32_t* piVar4 = (int32_t*)(uintptr_t)piVar4_addr;
        if (piVar4 != nullptr) {
            uint32_t* puVar5 = (uint32_t*)((void*(*)())*(void**)((uint8_t*)(uintptr_t)piVar4[0] + 4))();
        joined_r0x004dc1ce:
            if (puVar5 != nullptr) {
                if ((void*)puVar5 != (void*)&DAT_00727560) {
                    puVar5 = (uint32_t*)puVar5[1];
                    goto joined_r0x004dc1ce;
                }
                int iVar6 = FUN_00449390(&DAT_00727560, piVar4);
                uint32_t uVar1 = *(uint32_t*)((uint8_t*)(uintptr_t)iVar6 + 0xc0);
                while (true) {
                    uVar1 = uVar1 - 1;
                    if (!(-1 < (int)uVar1)) break;
                    if ((uVar1 < *(uint32_t*)((uint8_t*)(uintptr_t)iVar6 + 0xc0)) && (*(int*)(*(int*)((uint8_t*)(uintptr_t)iVar6 + 0xb8) + uVar1 * 4) != 0)) {
                        int iVar2 = *(int*)(*(int*)((uint8_t*)(uintptr_t)iVar6 + 0xb8) + uVar1 * 4);
                        FUN_00501f40(iVar2, 6);
                    }
                }
            }
        }
        int iVar6b = FUN_00533db0(8);
        if (iVar6b != 0) {
            FUN_00542cb0(0, 0);
            return;
        }
    } else {
        if (*(char*)(self_p + 0x238) == '\0') {
            int uVar3a = FUN_004baaa0();
            FUN_004dc090(0x4000, nullptr);
            (void)uVar3a;
            FUN_004dc090((uint32_t)(uintptr_t)"TownSneakZPass", (int32_t*)(uintptr_t)FUN_004baaa0());
            FUN_004dc090((uint32_t)(uintptr_t)"TownSneakOneLight", (int32_t*)(uintptr_t)FUN_004baaa0());
            FUN_004dc090((uint32_t)(uintptr_t)"TownSneakTwoLight", (int32_t*)(uintptr_t)FUN_004baaa0());
            FUN_004dc090((uint32_t)(uintptr_t)"TownSneakThreeLight", (int32_t*)(uintptr_t)FUN_004baaa0());
            FUN_004dc090((uint32_t)(uintptr_t)"TownSneakFourLight", (int32_t*)(uintptr_t)FUN_004baaa0());
            FUN_004dc090((uint32_t)(uintptr_t)"TownSneakFiveLight", (int32_t*)(uintptr_t)FUN_004baaa0());
            FUN_004dc090((uint32_t)(uintptr_t)"TownSneakSixLight", (int32_t*)(uintptr_t)FUN_004baaa0());
            FUN_004dc090((uint32_t)(uintptr_t)"TownSneakSevenLight", (int32_t*)(uintptr_t)FUN_004baaa0());
            FUN_004dc090((uint32_t)(uintptr_t)"TownSneakEightLight", (int32_t*)(uintptr_t)FUN_004baaa0());
            *(unsigned char*)(self_p + 0x238) = 1;
        }
        FUN_004db3d0("TownSneakZPass", 0xffffffffu, (int32_t*)(uintptr_t)FUN_004baaa0());
        int uVar3b = FUN_004baaa0();
        (void)uVar3b;
        FUN_005016d0((void*)(uintptr_t)FUN_004baaa0());
        FUN_005c28d0();
        FUN_004bd700(in_EAX, 0x3f800000, 0x3f800000, 0xbf800000);
    }
}

// 0x4dc390 — observed shape
void FUN_004dc390(void* self)
{
    uint8_t* self_p = (uint8_t*)self;
    if (*(char*)(self_p + 0x24c) != '\0') {
        FUN_004dbec0(self);
        FUN_004dc3f0();
        if (((unsigned char)DAT_007263bc & 0x20) != 0) {
            int* piVar1 = *(int**)((uint8_t*)DAT_008ea08c + 0xc);
            void** vtbl = *(void***)piVar1;
            ((void(*)(void*))vtbl[0x34 / 4])(DAT_008e9fd8);
            FUN_0050b760(1);
            void** vtbl2 = *(void***)piVar1;
            ((void(*)())vtbl2[0x38 / 4])();
        }
        FUN_004dc5a0(self);
    }
}
