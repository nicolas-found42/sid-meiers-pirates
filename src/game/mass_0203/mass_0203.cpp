#include <cstdint>
#include <cstddef>
#include <cmath>
#include <cstdlib>
#include <windows.h>

extern char FUN_005afcd0(int param_1);
extern char FUN_00428470(int param_1);
extern void FUN_005af810();
extern void* thunk_FUN_00533c78(std::size_t n);
extern void FUN_004127b0(void* dst, int a, int b, void* c);
extern void FUN_005b46d0();
extern void FUN_0051c200();
extern void FUN_005bbd50();
extern void operator_delete(void* p);
extern int FUN_005f0ddc();
extern void FUN_005b4740(int a, void* b, void* c);
extern void FUN_005af880(int a, uint32_t b);
extern void FUN_0051c040(uint32_t a);
extern void FUN_00581300(uint32_t a, int* b);
extern void FUN_0057a3f0(uint32_t a);
extern void FUN_005b4950(void* a, void* b, int* c, int d, int e, uint16_t f);
extern uint32_t FUN_004916a0();
extern void* FUN_00431450(float* a, float b, void* c);
extern void FUN_00491770(void* a, uint32_t b);
extern void FUN_0055a870(void* a);
extern uint32_t FUN_005a8990();
extern void FUN_00491610(float a);
extern void FUN_00533c78_dummy();
extern void* FUN_00533c78_wrap(std::size_t n);
extern void FUN_0051ac30(int a);
extern void FUN_005ae720();
extern void FUN_005bd490(int a);
extern void FUN_006b34a0(uint32_t a);
extern void FUN_005606f0(uint32_t a, int* b);
extern int FUN_00557b10(int a);
extern void FUN_005bbd20();
extern void FUN_005bbeb0(void* a, uint32_t b);
extern void FUN_005bbd70(uint32_t a);
extern int FUN_00545630();
extern int FUN_00545600();
extern void FUN_005b61f0(int** a);
extern void FUN_005b62a0(int** a);
extern void FUN_005b6770(uint32_t a);
extern void FUN_00545cc0();
extern void FUN_00535110();
extern void FUN_005bbf20();

extern void* PTR_FUN_006c6100;
extern void* PTR_FUN_00712780;
extern void* PTR_FUN_006c60f8;
extern void* PTR_FUN_006c60f4;
extern void* PTR_FUN_006c6398;
extern void* PTR_FUN_006c62a0;
extern void* PTR_LAB_006fd148;
extern uint32_t DAT_007177ac;
extern uint32_t DAT_007177b0;
extern uint32_t DAT_007177b4;
extern uint32_t DAT_00727444;
extern uint32_t DAT_00728c20;
extern uint8_t DAT_00727c3c;
extern uint8_t DAT_007278c0;
extern uint8_t LAB_004c2970;

// 0x5b4e60 — observed shape
char FUN_005b4e60(void* self, int param_1)
{
    char* ecx = static_cast<char*>(self);
    char cVar4 = FUN_005afcd0(param_1);
    if (cVar4 == '\0') {
        return '\0';
    }
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(ecx + 0x5c);
    if (uVar1 != *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(static_cast<uintptr_t>(param_1)) + 0x5c)) {
        return '\0';
    }
    uint32_t uVar5 = 0;
    if (uVar1 != 0) {
        do {
            int* piVar2 = *reinterpret_cast<int**>(*reinterpret_cast<int*>(ecx + 0x54) + uVar5 * 4);
            int iVar3 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(reinterpret_cast<char*>(static_cast<uintptr_t>(param_1)) + 0x54) + uVar5 * 4);
            if (piVar2 == nullptr) {
                if (iVar3 != 0) {
                    return '\0';
                }
            } else {
                if (iVar3 == 0) {
                    return '\0';
                }
                using Fn = char(*)(int);
                auto fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(reinterpret_cast<char*>(reinterpret_cast<uintptr_t>(piVar2)) + 0x1c));
                // NOTE: pseudocode calls with (iVar3); preserve single-arg shape
                cVar4 = fn(iVar3);
                if (cVar4 == '\0') {
                    return '\0';
                }
            }
            uVar5 = uVar5 + 1;
        } while (uVar5 < uVar1);
    }
    if ((*reinterpret_cast<int*>(ecx + 0x80) == *reinterpret_cast<int*>(reinterpret_cast<char*>(static_cast<uintptr_t>(param_1)) + 0x80)) &&
        (*reinterpret_cast<int*>(ecx + 0x84) == *reinterpret_cast<int*>(reinterpret_cast<char*>(static_cast<uintptr_t>(param_1)) + 0x84))) {
        cVar4 = FUN_00428470(param_1 + 0x88);
        return static_cast<char>(1 - (cVar4 != '\0'));
    }
    return '\0';
}

// 0x5b4f00 — observed shape
void FUN_005b4f00(void* self)
{
    char* base = static_cast<char*>(self);
    auto* dv = reinterpret_cast<uint32_t*>(base);
    FUN_005af810();
    *reinterpret_cast<uint32_t*>(base) = reinterpret_cast<uint32_t>(&PTR_FUN_006c6100);
    dv[0x14] = reinterpret_cast<uint32_t>(&PTR_FUN_00712780);
    dv[0x16] = 1;
    dv[0x19] = 2;
    dv[0x17] = 0;
    dv[0x18] = 0;
    uint32_t* puVar1 = static_cast<uint32_t*>(thunk_FUN_00533c78(8));
    uint32_t* puVar2 = nullptr;
    if (puVar1 == nullptr) {
        puVar2 = nullptr;
    } else {
        puVar2 = puVar1 + 1;
        *puVar1 = 1;
        FUN_004127b0(puVar2, 4, 1, &LAB_004c2970);
    }
    dv[0x15] = reinterpret_cast<uint32_t>(puVar2);
    dv[0x1c] = 0;
    dv[0x1d] = 0;
    dv[0x1e] = 0;
    dv[0x1b] = 0;
    dv[0x1a] = reinterpret_cast<uint32_t>(&PTR_FUN_006c60f8);
    dv[0x1f] = 1;
    dv[0x20] = 0;
    dv[0x21] = 0;
    dv[0x22] = DAT_007177ac;
    dv[0x23] = DAT_007177b0;
    dv[0x24] = DAT_007177b4;
}

// 0x5b4fc0 — observed shape
void FUN_005b4fc0(void* self, uint8_t param_1)
{
    FUN_005b46d0();
    FUN_0051c200();
    FUN_005bbd50();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5b4ff0 — observed shape
uint32_t FUN_005b4ff0(void* self, int param_1, uint32_t* param_2, float* param_3)
{
    char* ecx = static_cast<char*>(self);
    std::rand();
    int iVar6 = FUN_005f0ddc();
    char* base1 = reinterpret_cast<char*>(static_cast<uintptr_t>(param_1));
    int iVar1 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(base1 + 0xbc) + 0x20);
    int iVar2 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(base1 + 0xbc) + 0x24);
    if (iVar1 == 0) {
        return 0;
    }
    uint32_t* puVar8 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(iVar1 + iVar6 * 0xc));
    param_2[0] = puVar8[0];
    param_2[1] = puVar8[1];
    float* pfVar7 = reinterpret_cast<float*>(static_cast<uintptr_t>(iVar6 * 0xc + iVar2));
    param_2[2] = puVar8[2];
    float fVar3 = pfVar7[1];
    float fVar4 = pfVar7[2];
    if ((*reinterpret_cast<int*>(ecx + 0x80) == 0) && (*reinterpret_cast<int*>(*reinterpret_cast<int*>(base1 + 0xbc) + 0x24) != 0)) {
        float fVar5 = std::sqrt(param_3[2] * param_3[2] + param_3[1] * param_3[1] + param_3[0] * param_3[0]);
        param_3[0] = pfVar7[0] * fVar5;
        param_3[1] = fVar3 * fVar5;
        param_3[2] = fVar4 * fVar5;
    }
    FUN_005b4740(param_1, param_2, param_3);
    return 1;
}

// 0x5b5110 — observed shape
uint32_t FUN_005b5110(void* self, int* param_1, float* param_2, float* param_3)
{
    int* piVar4 = param_1;
    char* local_3c = static_cast<char*>(self);
    if (param_1 != nullptr) {
        for (uint32_t* puVar7 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint32_t(*)(void)>(*reinterpret_cast<void**>(*reinterpret_cast<char*>(reinterpret_cast<uintptr_t>(param_1)) + 4))()); puVar7 != nullptr;
             puVar7 = reinterpret_cast<uint32_t*>(puVar7[1])) {
            if (reinterpret_cast<uint8_t*>(puVar7) == &DAT_00727c3c) {
                uint32_t uVar8 = reinterpret_cast<uint32_t(*)(void)>(*reinterpret_cast<void**>(*reinterpret_cast<int*>(reinterpret_cast<char*>(reinterpret_cast<uintptr_t>(piVar4[0x2f])) + 0x44)))();
                std::rand();
                int iStack_34 = static_cast<int>(uVar8 & 0xffff) - 1;
                (void)iStack_34;
                int* piStack_40 = nullptr;
                int* piStack_38 = nullptr;
                int* outParam = param_1;
                uint32_t uVar9 = static_cast<uint32_t>(FUN_005f0ddc());
                reinterpret_cast<void(*)(uint32_t, void*, void*, void*)>(*reinterpret_cast<void**>(*reinterpret_cast<int*>(reinterpret_cast<char*>(reinterpret_cast<uintptr_t>(piVar4[0x2f])) + 0x48)))(uVar9, &piStack_40, &outParam, &piStack_38);
                param_1 = outParam;
                int iVar10 = std::rand();
                if (iVar10 % 3 == 1) {
                    piStack_40 = param_1;
                    param_1 = piStack_38;
                } else if (iVar10 % 3 == 2) {
                    param_1 = piStack_38;
                }
                goto LAB_005b522a;
            }
        }
        for (uint32_t* puVar7 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint32_t(*)(void)>(*reinterpret_cast<void**>(*reinterpret_cast<char*>(reinterpret_cast<uintptr_t>(piVar4)) + 4))()); puVar7 != nullptr;
             puVar7 = reinterpret_cast<uint32_t*>(puVar7[1])) {
            if (reinterpret_cast<uint8_t*>(puVar7) == &DAT_007278c0) {
                uint16_t uVar1 = *reinterpret_cast<uint16_t*>(piVar4[0x2f] + 0xc);
                std::rand();
                int* tmp = reinterpret_cast<int*>(static_cast<intptr_t>(uVar1 - 1));
                piStack_40 = reinterpret_cast<int*>(static_cast<intptr_t>(FUN_005f0ddc()));
                param_1 = reinterpret_cast<int*>(reinterpret_cast<intptr_t>(piStack_40) + 1);
                (void)tmp;
            LAB_005b522a: {
                float* pfVar6 = param_3;
                float* pfVar5 = param_2;
                int iVar10 = *reinterpret_cast<int*>(piVar4[0x2f] + 0x20);
                int iVar2 = *reinterpret_cast<int*>(piVar4[0x2f] + 0x24);
                if (iVar10 == 0) {
                    return 0;
                }
                int iVar11 = static_cast<int>((reinterpret_cast<uintptr_t>(piStack_40) & 0xffff) * 0xc);
                float* pfVar14 = reinterpret_cast<float*>(static_cast<uintptr_t>(iVar11 + iVar10));
                float fStack_30 = pfVar14[0];
                float fStack_2c = pfVar14[1];
                float fStack_28 = pfVar14[2];
                int iVar12 = static_cast<int>((reinterpret_cast<uintptr_t>(param_1) & 0xffff) * 0xc);
                pfVar14 = reinterpret_cast<float*>(static_cast<uintptr_t>(iVar10 + iVar12));
                float fStack_24 = pfVar14[0];
                float fStack_20 = pfVar14[1];
                float fStack_1c = pfVar14[2];
                float fStack_4 = fStack_1c + fStack_28;
                float fStack_18 = (fStack_24 + fStack_30) * 0.5f;
                param_2[0] = fStack_18;
                float fStack_14 = (fStack_20 + fStack_2c) * 0.5f;
                param_2[1] = fStack_14;
                float fStack_10 = fStack_4 * 0.5f;
                param_2[2] = fStack_10;
                if ((*reinterpret_cast<int*>(local_3c + 0x80) == 0) && (iVar2 != 0)) {
                    pfVar14 = reinterpret_cast<float*>(static_cast<uintptr_t>(iVar11 + iVar2));
                    float fStack_c = pfVar14[0];
                    float fStack_8 = pfVar14[1];
                    float* pfVar13 = reinterpret_cast<float*>(static_cast<uintptr_t>(iVar12 + iVar2));
                    fStack_4 = pfVar13[2] + pfVar14[2];
                    fStack_18 = (pfVar13[0] + fStack_c) * 0.5f;
                    fStack_14 = (pfVar13[1] + fStack_8) * 0.5f;
                    fStack_10 = fStack_4 * 0.5f;
                    FUN_0055a870(&fStack_18);
                    fStack_4 = std::sqrt(pfVar6[2] * pfVar6[2] + pfVar6[1] * pfVar6[1] + pfVar6[0] * pfVar6[0]);
                    fStack_c = fStack_18 * fStack_4;
                    pfVar6[0] = fStack_c;
                    fStack_8 = fStack_14 * fStack_4;
                    pfVar6[1] = fStack_8;
                    fStack_4 = fStack_10 * fStack_4;
                    pfVar6[2] = fStack_4;
                }
                if (*reinterpret_cast<int*>(local_3c + 0x84) == 4) {
                    fStack_c = fStack_24 - fStack_30;
                    fStack_8 = fStack_20 - fStack_2c;
                    fStack_4 = fStack_1c - fStack_28;
                    int r = std::rand();
                    float fVar3 = static_cast<float>(r) * 3.051851e-05f;
                    fStack_14 = fStack_8 * fVar3;
                    fStack_10 = fStack_4 * fVar3;
                    fStack_c = fStack_c * fVar3 + fStack_30;
                    pfVar5[0] = fStack_c;
                    fStack_8 = fStack_14 + fStack_2c;
                    pfVar5[1] = fStack_8;
                    fStack_4 = fStack_10 + fStack_28;
                    pfVar5[2] = fStack_4;
                }
                FUN_005b4740(reinterpret_cast<int>(piVar4), pfVar5, pfVar6);
                return 1;
            }
            }
        }
    }
    return 0;
}

// 0x5b5490 — observed shape
uint32_t FUN_005b5490(void* self, int param_1, int* param_2, uint32_t* param_3, uint32_t* param_4)
{
    char* ecx = static_cast<char*>(self);
    if (param_2 != nullptr) {
        for (uint32_t* puVar3 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint32_t(*)(void)>(*reinterpret_cast<void**>(*reinterpret_cast<char*>(reinterpret_cast<uintptr_t>(param_2)) + 4))()); puVar3 != nullptr;
             puVar3 = reinterpret_cast<uint32_t*>(puVar3[1])) {
            if (reinterpret_cast<uint8_t*>(puVar3) == &DAT_00727c3c) {
                int p1 = param_1;
                if (*reinterpret_cast<int*>(reinterpret_cast<char*>(static_cast<uintptr_t>(p1)) + 8) == 0) {
                    return 0;
                }
                uint16_t uVar2 = *reinterpret_cast<uint16_t*>(*reinterpret_cast<int*>(reinterpret_cast<char*>(static_cast<uintptr_t>(p1)) + 8) + 0xc);
                std::rand();
                int iVar4 = FUN_005f0ddc();
                int iVar1 = static_cast<int>(uVar2) - 1;
                if (iVar1 <= iVar4) {
                    iVar4 = iVar1;
                }
                iVar1 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(reinterpret_cast<char*>(static_cast<uintptr_t>(p1)) + 8) + 0x10);
                std::rand();
                uint32_t uVar5 = static_cast<uint32_t>(FUN_005f0ddc());
                if (param_2[0x30] == 0) {
                    return 0;
                }
                uint32_t uStack_18 = 0;
                uint32_t uStack_14 = 0;
                uint32_t uStack_10 = 0;
                uint8_t auStack_c[12] = {};
                FUN_005b4950(&uStack_18, auStack_c, param_2, param_2[0x30], iVar4 * 0x2c + iVar1, static_cast<uint16_t>(uVar5));
                param_3[0] = uStack_18;
                param_3[1] = uStack_14;
                param_3[2] = uStack_10;
                if ((*reinterpret_cast<int*>(ecx + 0x80) == 0) && (*reinterpret_cast<int*>(param_2[0x2f] + 0x24) != 0)) {
                    float fVar6 = static_cast<float>(FUN_004916a0());
                    uint32_t* scaled = static_cast<uint32_t*>(FUN_00431450(reinterpret_cast<float*>(&uStack_18), fVar6, auStack_c));
                    param_4[0] = scaled[0];
                    param_4[1] = scaled[1];
                    param_4[2] = scaled[2];
                }
                FUN_005b4740(reinterpret_cast<int>(param_2), param_3, param_4);
                return 1;
            }
        }
    }
    return 0;
}

// 0x5b55f0 — observed shape
uint32_t FUN_005b55f0(void* self, int param_1, int* param_2, float* param_3, uint32_t* param_4)
{
    char* ecx = static_cast<char*>(self);
    if (param_2 != nullptr) {
        for (uint32_t* puVar7 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint32_t(*)(void)>(*reinterpret_cast<void**>(*reinterpret_cast<char*>(reinterpret_cast<uintptr_t>(param_2)) + 4))()); puVar7 != nullptr;
             puVar7 = reinterpret_cast<uint32_t*>(puVar7[1])) {
            if (reinterpret_cast<uint8_t*>(puVar7) == &DAT_00727c3c) {
                if (*reinterpret_cast<int*>(reinterpret_cast<char*>(static_cast<uintptr_t>(param_1)) + 8) == 0) {
                    return 0;
                }
                uint16_t uVar2 = *reinterpret_cast<uint16_t*>(*reinterpret_cast<int*>(reinterpret_cast<char*>(static_cast<uintptr_t>(param_1)) + 8) + 0xc);
                std::rand();
                int iVar8 = FUN_005f0ddc();
                int iVar9 = static_cast<int>(uVar2) - 1;
                if (iVar9 <= iVar8) {
                    iVar8 = iVar9;
                }
                iVar9 = iVar8 * 0x2c + *reinterpret_cast<int*>(*reinterpret_cast<int*>(reinterpret_cast<char*>(static_cast<uintptr_t>(param_1)) + 8) + 0x10);
                if (*reinterpret_cast<short*>(static_cast<uintptr_t>(iVar9) + 0x1e) == 0) {
                    return FUN_005b5490(self, param_1, param_2, reinterpret_cast<uint32_t*>(param_3), param_4);
                }
                uVar2 = *reinterpret_cast<uint16_t*>(static_cast<uintptr_t>(iVar9) + 0x1e);
                std::rand();
                int iVar11 = FUN_005f0ddc();
                iVar8 = static_cast<int>(uVar2) - 1;
                if (iVar8 <= iVar11) {
                    iVar11 = iVar8;
                }
                int iVar8b = param_2[0x30];
                if (iVar8b == 0) {
                    return 0;
                }
                uint16_t uVar3 = 0;
                uint16_t uVar4 = 0;
                uint16_t uVar5 = 0;
                if (*reinterpret_cast<short*>(static_cast<uintptr_t>(iVar9) + 0x22) == 0) {
                    uint16_t* puVar1 = reinterpret_cast<uint16_t*>(static_cast<uintptr_t>(*reinterpret_cast<int*>(static_cast<uintptr_t>(iVar9) + 0x14) + iVar11 * 6));
                    uVar3 = puVar1[0];
                    uVar4 = puVar1[1];
                    uVar5 = puVar1[2];
                } else {
                    int iVar6 = *reinterpret_cast<int*>(static_cast<uintptr_t>(iVar9) + 0x14);
                    uVar3 = *reinterpret_cast<uint16_t*>(static_cast<uintptr_t>(iVar6 + iVar11 * 2));
                    uVar4 = *reinterpret_cast<uint16_t*>(static_cast<uintptr_t>(iVar6 + 2 + iVar11 * 2));
                    uVar5 = *reinterpret_cast<uint16_t*>(static_cast<uintptr_t>(iVar6 + 4 + iVar11 * 2));
                }
                float fStack_60 = 0, fStack_5c = 0, fStack_58 = 0, fStack_54 = 0, fStack_50 = 0, fStack_4c = 0, fStack_48 = 0, fStack_44 = 0, fStack_40 = 0, fStack_3c = 0, fStack_38 = 0, fStack_34 = 0, fStack_30 = 0, fStack_2c = 0, fStack_28 = 0, fStack_24 = 0, fStack_20 = 0, fStack_1c = 0, fStack_18 = 0, fStack_14 = 0, fStack_10 = 0;
                FUN_005b4950(&fStack_60, &fStack_24, param_2, iVar8b, iVar9, uVar3);
                FUN_005b4950(&fStack_54, &fStack_30, param_2, iVar8b, iVar9, uVar4);
                FUN_005b4950(&fStack_48, &fStack_18, param_2, iVar8b, iVar9, uVar5);
                (void)fStack_58; (void)fStack_50; (void)fStack_4c; (void)fStack_44; (void)fStack_40; (void)fStack_34; (void)fStack_34;
                float afStack_c[2] = {0, 0};
                afStack_c[0] = fStack_54 + fStack_60 + fStack_48;
                fStack_3c = afStack_c[0] * 0.33333334f;
                param_3[0] = fStack_3c;
                fStack_38 = (fStack_50 + fStack_5c + fStack_44) * 0.33333334f;
                param_3[1] = fStack_38;
                fStack_34 = (fStack_40 + fStack_4c + fStack_58) * 0.33333334f;
                param_3[2] = fStack_34;
                if (*reinterpret_cast<int*>(ecx + 0x80) == 0) {
                    float fStack_4 = fStack_28 + fStack_1c;
                    fStack_24 = fStack_30 + fStack_24 + fStack_18;
                    fStack_20 = fStack_14 + fStack_2c + fStack_20;
                    fStack_1c = fStack_10 + fStack_4;
                    FUN_00491770(&fStack_18, 0x40400000);
                    FUN_0055a870(&fStack_18);
                    float fVar12 = static_cast<float>(FUN_004916a0());
                    uint32_t* scaled = static_cast<uint32_t*>(FUN_00431450(afStack_c, fVar12, &fStack_18));
                    param_4[0] = scaled[0];
                    param_4[1] = scaled[1];
                    param_4[2] = scaled[2];
                }
                if (*reinterpret_cast<int*>(ecx + 0x84) == 3) {
                    fStack_3c = fStack_54 - fStack_60;
                    fStack_38 = fStack_50 - fStack_5c;
                    fStack_34 = fStack_4c - fStack_58;
                    float t54 = fStack_48 - fStack_60;
                    float t50 = fStack_44 - fStack_5c;
                    float t4c = fStack_40 - fStack_58;
                    float fVar12 = static_cast<float>(FUN_005a8990());
                    FUN_00491610(fVar12);
                    float fVar13 = static_cast<float>(FUN_005a8990());
                    FUN_00491610((1.0f - fVar12) * fVar13);
                    (void)fVar13;
                    float fStack_4 = fStack_34 + fStack_58;
                    fStack_3c = fStack_3c + fStack_60 + t54;
                    param_3[0] = fStack_3c;
                    fStack_38 = fStack_38 + fStack_5c + t50;
                    param_3[1] = fStack_38;
                    fStack_34 = fStack_4 + t4c;
                    param_3[2] = fStack_34;
                }
                FUN_005b4740(reinterpret_cast<int>(param_2), param_3, param_4);
                return 1;
            }
        }
    }
    return 0;
}

// 0x5b5990 — observed shape
uint32_t FUN_005b5990(void* self, int param_1, int* param_2, float* param_3, uint32_t* param_4)
{
    char* ecx = static_cast<char*>(self);
    if (param_2 != nullptr) {
        for (uint32_t* puVar5 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint32_t(*)(void)>(*reinterpret_cast<void**>(*reinterpret_cast<char*>(reinterpret_cast<uintptr_t>(param_2)) + 4))()); puVar5 != nullptr;
             puVar5 = reinterpret_cast<uint32_t*>(puVar5[1])) {
            if (reinterpret_cast<uint8_t*>(puVar5) == &DAT_00727c3c) {
                if (*reinterpret_cast<int*>(reinterpret_cast<char*>(static_cast<uintptr_t>(param_1)) + 8) == 0) {
                    return 0;
                }
                uint16_t uVar1 = *reinterpret_cast<uint16_t*>(*reinterpret_cast<int*>(reinterpret_cast<char*>(static_cast<uintptr_t>(param_1)) + 8) + 0xc);
                std::rand();
                int iVar6 = FUN_005f0ddc();
                int iVar7 = static_cast<int>(uVar1) - 1;
                if (iVar7 <= iVar6) {
                    iVar6 = iVar7;
                }
                iVar7 = iVar6 * 0x2c + *reinterpret_cast<int*>(*reinterpret_cast<int*>(reinterpret_cast<char*>(static_cast<uintptr_t>(param_1)) + 8) + 0x10);
                if (*reinterpret_cast<short*>(static_cast<uintptr_t>(iVar7) + 0x1e) == 0) {
                    return FUN_005b5490(self, param_1, param_2, reinterpret_cast<uint32_t*>(param_3), param_4);
                }
                uVar1 = *reinterpret_cast<uint16_t*>(static_cast<uintptr_t>(iVar7) + 0x1e);
                std::rand();
                int iVar9 = FUN_005f0ddc();
                iVar6 = static_cast<int>(uVar1) - 1;
                if (iVar6 <= iVar9) {
                    iVar9 = iVar6;
                }
                int iVar6b = param_2[0x30];
                if (iVar6b == 0) {
                    return 0;
                }
                uint16_t uVar10 = 0;
                uint16_t uVar11 = 0;
                uint16_t uVar2 = 0;
                if (*reinterpret_cast<short*>(static_cast<uintptr_t>(iVar7) + 0x22) == 0) {
                    int iVar3 = *reinterpret_cast<int*>(static_cast<uintptr_t>(iVar7) + 0x14);
                    uVar10 = *reinterpret_cast<uint16_t*>(static_cast<uintptr_t>(iVar3 + iVar9 * 6));
                    uVar11 = *reinterpret_cast<uint16_t*>(static_cast<uintptr_t>(iVar3 + 2 + iVar9 * 6));
                    uVar2 = *reinterpret_cast<uint16_t*>(static_cast<uintptr_t>(iVar3 + 4 + iVar9 * 6));
                } else {
                    int iVar3 = *reinterpret_cast<int*>(static_cast<uintptr_t>(iVar7) + 0x14);
                    uVar10 = *reinterpret_cast<uint16_t*>(static_cast<uintptr_t>(iVar3 + iVar9 * 2));
                    uVar11 = *reinterpret_cast<uint16_t*>(static_cast<uintptr_t>(iVar3 + 2 + iVar9 * 2));
                    uVar2 = *reinterpret_cast<uint16_t*>(static_cast<uintptr_t>(iVar3 + 4 + iVar9 * 2));
                }
                iVar9 = std::rand();
                uint16_t uVar4 = uVar11;
                if ((iVar9 % 3 == 1) || (uVar4 = uVar10, iVar9 % 3 == 2)) {
                    uVar10 = uVar4;
                    uVar11 = uVar2;
                }
                float fStack_48 = 0, fStack_44 = 0, fStack_40 = 0, fStack_3c = 0, fStack_38 = 0, fStack_34 = 0, fStack_30 = 0, fStack_2c = 0, fStack_28 = 0, fStack_24 = 0, fStack_20 = 0, fStack_1c = 0, fStack_18 = 0, fStack_14 = 0, fStack_10 = 0;
                uint8_t auStack_c[8] = {};
                FUN_005b4950(&fStack_48, &fStack_18, param_2, iVar6b, iVar7, uVar10);
                FUN_005b4950(&fStack_3c, &fStack_24, param_2, iVar6b, iVar7, uVar11);
                float fStack_4 = fStack_34 + fStack_40;
                fStack_30 = (fStack_3c + fStack_48) * 0.5f;
                param_3[0] = fStack_30;
                fStack_2c = (fStack_38 + fStack_44) * 0.5f;
                param_3[1] = fStack_2c;
                fStack_28 = fStack_4 * 0.5f;
                param_3[2] = fStack_28;
                if (*reinterpret_cast<int*>(ecx + 0x80) == 0) {
                    fStack_30 = fStack_24 + fStack_18;
                    fStack_2c = fStack_20 + fStack_14;
                    fStack_28 = fStack_1c + fStack_10;
                    FUN_00491770(&fStack_18, 0x40000000);
                    FUN_0055a870(&fStack_18);
                    float fVar12 = static_cast<float>(FUN_004916a0());
                    uint32_t* scaled = static_cast<uint32_t*>(FUN_00431450(reinterpret_cast<float*>(auStack_c), fVar12, &fStack_18));
                    param_4[0] = scaled[0];
                    param_4[1] = scaled[1];
                    param_4[2] = scaled[2];
                }
                if (*reinterpret_cast<int*>(ecx + 0x84) == 4) {
                    fStack_30 = fStack_3c - fStack_48;
                    fStack_2c = fStack_38 - fStack_44;
                    fStack_28 = fStack_34 - fStack_40;
                    float fVar12 = static_cast<float>(FUN_005a8990());
                    float t14 = fStack_2c * fVar12;
                    float t10 = fStack_28 * fVar12;
                    fStack_30 = fStack_30 * fVar12 + fStack_48;
                    param_3[0] = fStack_30;
                    fStack_2c = t14 + fStack_44;
                    param_3[1] = fStack_2c;
                    fStack_28 = t10 + fStack_40;
                    param_3[2] = fStack_28;
                }
                FUN_005b4740(reinterpret_cast<int>(param_2), param_3, param_4);
                return 1;
            }
        }
    }
    return 0;
}

// 0x5b5c90 — observed shape
void FUN_005b5c90(void* self, int param_1, uint32_t param_2)
{
    char* ecx = static_cast<char*>(self);
    FUN_005af880(param_1, param_2);
    FUN_0051c040(*reinterpret_cast<uint32_t*>(ecx + 0x5c));
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(static_cast<uintptr_t>(param_1)) + 0x80) = *reinterpret_cast<uint32_t*>(ecx + 0x80);
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(static_cast<uintptr_t>(param_1)) + 0x84) = *reinterpret_cast<uint32_t*>(ecx + 0x84);
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(static_cast<uintptr_t>(param_1)) + 0x88) = *reinterpret_cast<uint32_t*>(ecx + 0x88);
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(static_cast<uintptr_t>(param_1)) + 0x8c) = *reinterpret_cast<uint32_t*>(ecx + 0x8c);
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(static_cast<uintptr_t>(param_1)) + 0x90) = *reinterpret_cast<uint32_t*>(ecx + 0x90);
}

// 0x5b61f0 — observed shape
uint32_t FUN_005b61f0(void* self, int* param_1)
{
    char* ecx = static_cast<char*>(self);
    if (*param_1 == 0) {
        return 0xffffffffu;
    }
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(ecx + 0xc);
    uint32_t uVar6 = 0;
    if (uVar1 != 0) {
        int* piVar2 = *reinterpret_cast<int**>(ecx + 4);
        int* piVar5 = piVar2;
        do {
            if (*piVar5 == 0) {
                uint32_t* puVar3 = reinterpret_cast<uint32_t*>(piVar2[uVar6]);
                if (reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(*param_1)) != puVar3) {
                    if (puVar3 != nullptr) {
                        int* slot = reinterpret_cast<int*>(puVar3 + 1);
                        *slot = *slot - 1;
                        if (*slot == 0) {
                            reinterpret_cast<void(*)(int)>(*reinterpret_cast<void**>(puVar3))(1);
                        }
                    }
                    int iVar4 = *param_1;
                    piVar2[uVar6] = iVar4;
                    if (iVar4 != 0) {
                        *reinterpret_cast<int*>(static_cast<uintptr_t>(iVar4) + 4) = *reinterpret_cast<int*>(static_cast<uintptr_t>(iVar4) + 4) + 1;
                    }
                }
                *reinterpret_cast<int*>(ecx + 0x10) = *reinterpret_cast<int*>(ecx + 0x10) + 1;
                return uVar6;
            }
            uVar6 = uVar6 + 1;
            piVar5 = piVar5 + 1;
        } while (uVar6 < *reinterpret_cast<uint32_t*>(ecx + 0xc));
    }
    if (*reinterpret_cast<uint32_t*>(ecx + 8) <= uVar1) {
        FUN_0051c040(*reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(*reinterpret_cast<int*>(ecx + 0x14)) + uVar1));
    }
    FUN_00581300(uVar1, param_1);
    return uVar1;
}

// 0x5b62a0 — observed shape
uint32_t FUN_005b62a0(void* self, int* param_1)
{
    char* ecx = static_cast<char*>(self);
    if (*param_1 == 0) {
        return 0xffffffffu;
    }
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(ecx + 0xc);
    uint32_t uVar6 = 0;
    if (uVar1 != 0) {
        int* piVar2 = *reinterpret_cast<int**>(ecx + 4);
        int* piVar5 = piVar2;
        do {
            if (*piVar5 == 0) {
                uint32_t* puVar3 = reinterpret_cast<uint32_t*>(piVar2[uVar6]);
                if (reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(*param_1)) != puVar3) {
                    if (puVar3 != nullptr) {
                        int* slot = reinterpret_cast<int*>(puVar3 + 1);
                        *slot = *slot - 1;
                        if (*slot == 0) {
                            reinterpret_cast<void(*)(int)>(*reinterpret_cast<void**>(puVar3))(1);
                        }
                    }
                    int iVar4 = *param_1;
                    piVar2[uVar6] = iVar4;
                    if (iVar4 != 0) {
                        *reinterpret_cast<int*>(static_cast<uintptr_t>(iVar4) + 4) = *reinterpret_cast<int*>(static_cast<uintptr_t>(iVar4) + 4) + 1;
                    }
                }
                *reinterpret_cast<int*>(ecx + 0x10) = *reinterpret_cast<int*>(ecx + 0x10) + 1;
                return uVar6;
            }
            uVar6 = uVar6 + 1;
            piVar5 = piVar5 + 1;
        } while (uVar6 < *reinterpret_cast<uint32_t*>(ecx + 0xc));
    }
    if (*reinterpret_cast<uint32_t*>(ecx + 8) <= uVar1) {
        FUN_0057a3f0(*reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(*reinterpret_cast<int*>(ecx + 0x14)) + uVar1));
    }
    FUN_00581300(uVar1, param_1);
    return uVar1;
}

// 0x5b6350 — observed shape
uint32_t FUN_005b6350(void* self, int* param_1, uint32_t param_2, uint32_t param_3)
{
    int* piVar2 = param_1;
    char* unaff_EDI = static_cast<char*>(self);
    if (param_1 != nullptr) {
        for (uint32_t* puVar4 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint32_t(*)(void)>(*reinterpret_cast<void**>(*reinterpret_cast<char*>(reinterpret_cast<uintptr_t>(param_1)) + 4))()); puVar4 != nullptr;
             puVar4 = reinterpret_cast<uint32_t*>(puVar4[1])) {
            if (reinterpret_cast<uint8_t*>(puVar4) == &DAT_00727c3c) {
                uint32_t uVar5 = reinterpret_cast<uint32_t(*)(void)>(*reinterpret_cast<void**>(*reinterpret_cast<int*>(reinterpret_cast<char*>(reinterpret_cast<uintptr_t>(piVar2[0x2f])) + 0x44)))();
                float fVar13 = static_cast<float>(uVar5 & 0xffffu);
                std::rand();
                float fStack_4c = fVar13;
                float fVar6 = static_cast<float>(FUN_005f0ddc());
                if (fVar6 == fVar13) {
                    fVar6 = static_cast<float>(static_cast<int>(fVar13) - 1);
                }
                float* pfStack_4 = nullptr;
                float fStack_58 = 0, fStack_54 = 0, fStack_48 = 0, fStack_44 = 0, fStack_40 = 0, fStack_3c = 0, fStack_38 = 0, fStack_34 = 0, fStack_30 = 0, fStack_2c = 0, fStack_28 = 0, fStack_24 = 0, fStack_20 = 0, fStack_1c = 0, fStack_18 = 0, fStack_14 = 0;
                float outPos[3] = {0, 0, 0};
                float outNrm[3] = {0, 0, 0};
                float* pfStack_8 = outPos;
                pfVar3_dummy:;
                float* pfVar3 = outNrm;
                (void)pfVar3_dummy;
                (void)param_2; (void)param_3;
                uint16_t uStack_c = 0;
                reinterpret_cast<void(*)(float, void*, void*)>(*reinterpret_cast<void**>(*reinterpret_cast<int*>(reinterpret_cast<char*>(reinterpret_cast<uintptr_t>(piVar2[0x2f])) + 0x48)))(fVar6, &param_1, &fStack_58);
                int iVar7 = *reinterpret_cast<int*>(piVar2[0x2f] + 0x20);
                int iVar1 = *reinterpret_cast<int*>(piVar2[0x2f] + 0x24);
                if (iVar7 == 0) {
                    return 0;
                }
                float* pfVar10 = reinterpret_cast<float*>(static_cast<uintptr_t>(static_cast<uint32_t>(uStack_c) * 0xc + static_cast<uint32_t>(iVar7)));
                fStack_58 = pfVar10[0];
                fStack_54 = pfVar10[1];
                float local_50 = pfVar10[2];
                int iVar9 = static_cast<int>((reinterpret_cast<uintptr_t>(&fStack_54) & 0xffffu) * 0xc);
                float* pfVar14 = reinterpret_cast<float*>(static_cast<uintptr_t>(iVar9 + static_cast<uint32_t>(iVar7)));
                fStack_40 = pfVar14[0];
                fStack_3c = pfVar14[1];
                fStack_38 = pfVar14[2];
                fStack_14 = fStack_38 + local_50;
                int iVar11 = static_cast<int>((reinterpret_cast<uintptr_t>(pfVar3) & 0xffffu) * 0xc);
                pfVar14 = reinterpret_cast<float*>(static_cast<uintptr_t>(static_cast<uint32_t>(iVar7) + static_cast<uint32_t>(iVar11)));
                fStack_34 = pfVar14[0];
                fStack_30 = pfVar14[1];
                fStack_28 = fStack_40 + fStack_58 + fStack_34;
                fStack_2c = pfVar14[2];
                fStack_4c = fStack_28 * 0.33333334f;
                pfStack_8[0] = fStack_4c;
                fStack_48 = (fStack_3c + fStack_54 + fStack_30) * 0.33333334f;
                pfStack_8[1] = fStack_48;
                fStack_44 = (fStack_2c + fStack_14) * 0.33333334f;
                pfStack_8[2] = fStack_44;
                if ((*reinterpret_cast<int*>(unaff_EDI + 0x80) == 0) && (iVar1 != 0)) {
                    pfVar14 = reinterpret_cast<float*>(static_cast<uintptr_t>(static_cast<uint32_t>(uStack_c) * 0xc + static_cast<uint32_t>(iVar1)));
                    fStack_28 = pfVar14[0];
                    fStack_24 = pfVar14[1];
                    pfVar10 = reinterpret_cast<float*>(static_cast<uintptr_t>(iVar9 + static_cast<uint32_t>(iVar1)));
                    float* pfVar12 = reinterpret_cast<float*>(static_cast<uintptr_t>(iVar11 + static_cast<uint32_t>(iVar1)));
                    fStack_20 = pfVar10[2] + pfVar14[2];
                    fStack_1c = pfVar12[0];
                    fStack_18 = pfVar12[1];
                    fStack_14 = pfVar12[2];
                    fStack_4c = (pfVar10[0] + fStack_28 + fStack_1c) * 0.33333334f;
                    fStack_48 = (pfVar10[1] + fStack_24 + fStack_18) * 0.33333334f;
                    fStack_44 = (fStack_14 + fStack_20) * 0.33333334f;
                    FUN_0055a870(&fStack_4c);
                    fStack_14 = std::sqrt(pfVar3[2] * pfVar3[2] + pfVar3[1] * pfVar3[1] + pfVar3[0] * pfVar3[0]);
                    fStack_1c = fStack_4c * fStack_14;
                    pfVar3[0] = fStack_1c;
                    fStack_18 = fStack_48 * fStack_14;
                    pfVar3[1] = fStack_18;
                    fStack_14 = fStack_44 * fStack_14;
                    pfVar3[2] = fStack_14;
                }
                if (*reinterpret_cast<int*>(unaff_EDI + 0x84) == 3) {
                    fStack_4c = fStack_40 - fStack_58;
                    fStack_48 = fStack_3c - fStack_54;
                    fStack_44 = fStack_38 - local_50;
                    fStack_40 = fStack_34 - fStack_58;
                    fStack_3c = fStack_30 - fStack_54;
                    fStack_38 = fStack_2c - local_50;
                    int r = std::rand();
                    float t = static_cast<float>(r) * 3.051851e-05f;
                    fStack_4c = fStack_4c * t;
                    fStack_48 = fStack_48 * t;
                    fStack_44 = fStack_44 * t;
                    int r2 = std::rand();
                    float fVar6b = (1.0f - t) * static_cast<float>(r2) * 3.051851e-05f;
                    fStack_3c = fStack_3c * fVar6b;
                    fStack_38 = fStack_38 * fVar6b;
                    fStack_24 = fStack_48 + fStack_54;
                    fStack_20 = fStack_44 + local_50;
                    fStack_1c = fStack_4c + fStack_58 + fStack_40 * fVar6b;
                    pfStack_8[0] = fStack_1c;
                    fStack_18 = fStack_24 + fStack_3c;
                    pfStack_8[1] = fStack_18;
                    fStack_14 = fStack_20 + fStack_38;
                    pfStack_8[2] = fStack_14;
                }
                FUN_005b4740(reinterpret_cast<int>(piVar2), pfStack_8, pfVar3);
                return 1;
            }
        }
        for (uint32_t* puVar4 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint32_t(*)(void)>(*reinterpret_cast<void**>(*reinterpret_cast<char*>(reinterpret_cast<uintptr_t>(piVar2)) + 4))()); puVar4 != nullptr;
             puVar4 = reinterpret_cast<uint32_t*>(puVar4[1])) {
            if (reinterpret_cast<uint8_t*>(puVar4) == &DAT_007278c0) {
                return FUN_005b5110(self, piVar2, reinterpret_cast<float*>(param_2), reinterpret_cast<float*>(param_3));
            }
        }
    }
    return 0;
}

// 0x5b6770 — observed shape
void FUN_005b6770(uint32_t* param_1)
{
    uint32_t* puVar4 = param_1;
    if (param_1 != nullptr) {
        param_1[1] = param_1[1] + 1;
        FUN_005b61f0(reinterpret_cast<int**>(&param_1));
        uint32_t* piVar1 = puVar4 + 1;
        *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) {
            reinterpret_cast<void(*)(int)>(*reinterpret_cast<void**>(puVar4))(1);
        }
        int iVar3 = 0;
        if ((puVar4[0x30] == 0) || (iVar3 = *reinterpret_cast<int*>(puVar4[0x30] + 0xc), iVar3 == 0) ||
            (iVar3 = *reinterpret_cast<int*>(static_cast<uintptr_t>(iVar3) + 0xc), iVar3 == 0)) {
            uint32_t* puVar5 = static_cast<uint32_t*>(thunk_FUN_00533c78(0xc));
            if (puVar5 != nullptr) {
                puVar5[1] = 0;
                *puVar5 = reinterpret_cast<uint32_t>(&PTR_LAB_006fd148);
                DAT_00727444 = DAT_00727444 + 1;
                *puVar5 = reinterpret_cast<uint32_t>(&PTR_FUN_006c60f4);
                puVar5[2] = 0;
            }
            param_1 = puVar5;
            if (puVar5 != nullptr) {
                puVar5[1] = puVar5[1] + 1;
            }
            FUN_005b62a0(reinterpret_cast<int**>(&param_1));
            if (puVar5 != nullptr) {
                uint32_t* q = puVar5 + 1;
                *q = *q - 1;
                if (*q == 0) {
                    reinterpret_cast<void(*)(int)>(*reinterpret_cast<void**>(puVar5))(1);
                }
            }
        } else {
            uint32_t* puVar5 = static_cast<uint32_t*>(thunk_FUN_00533c78(0xc));
            if (puVar5 == nullptr) {
                FUN_0051ac30(iVar3);
            } else {
                *puVar5 = reinterpret_cast<uint32_t>(&PTR_LAB_006fd148);
                puVar5[1] = 0;
                DAT_00727444 = DAT_00727444 + 1;
                *puVar5 = reinterpret_cast<uint32_t>(&PTR_FUN_006c60f4);
                puVar5[2] = 0;
                FUN_0051ac30(iVar3);
            }
            if (puVar5 != nullptr) {
                puVar5[1] = puVar5[1] + 1;
            }
            param_1 = puVar5;
            FUN_005b62a0(reinterpret_cast<int**>(&param_1));
            if (puVar5 != nullptr) {
                uint32_t* q = puVar5 + 1;
                *q = *q - 1;
                if (*q == 0) {
                    reinterpret_cast<void(*)(int)>(*reinterpret_cast<void**>(puVar5))(1);
                }
            }
        }
        if (puVar4[0x2f] != 0) {
            uint8_t* pbVar2 = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(puVar4[0x2f]) + 0x34);
            *pbVar2 = static_cast<uint8_t>(*pbVar2 | 0x33);
        }
    }
}

// 0x5b6950 — observed shape
void FUN_005b6950(uint32_t param_1)
{
    thunk_FUN_005bbd70(param_1);
    int iVar1 = FUN_00545630();
    if (iVar1 != 0) {
        FUN_0051c040(static_cast<uint32_t>(iVar1));
        for (; iVar1 != 0; iVar1 = iVar1 - 1) {
            uint32_t uVar2 = static_cast<uint32_t>(FUN_00545600());
            FUN_005b6770(reinterpret_cast<uint32_t*>(uVar2));
        }
    }
}

// 0x5b6c70 — observed shape
uint32_t* FUN_005b6c70(void* self, uint32_t param_1)
{
    char* ecx = static_cast<char*>(self);
    uint32_t* puVar1 = static_cast<uint32_t*>(thunk_FUN_00533c78(0x2c));
    if (puVar1 != nullptr) {
        FUN_005bbd20();
        *puVar1 = reinterpret_cast<uint32_t>(&PTR_FUN_006c62a0);
        puVar1[7] = 0;
        *reinterpret_cast<uint16_t*>(puVar1 + 8) = 0;
        puVar1[9] = 0;
        *reinterpret_cast<uint16_t*>(puVar1 + 10) = 0;
    }
    FUN_005bbeb0(puVar1, param_1);
    puVar1[7] = *reinterpret_cast<uint32_t*>(ecx + 0x1c);
    *reinterpret_cast<uint16_t*>(puVar1 + 8) = *reinterpret_cast<uint16_t*>(ecx + 0x20);
    puVar1[9] = *reinterpret_cast<uint32_t*>(ecx + 0x24);
    *reinterpret_cast<uint16_t*>(puVar1 + 10) = *reinterpret_cast<uint16_t*>(ecx + 0x28);
    return puVar1;
}

// 0x5b6ee0 — observed shape
void FUN_005b6ee0(void* self)
{
    char* ecx = static_cast<char*>(self);
    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(ecx + 0x4c);
    if (puVar2 != nullptr) {
        uint32_t* piVar1 = puVar2 + 1;
        *piVar1 = *piVar1 + static_cast<uint32_t>(-1);
        if (*piVar1 == 0) {
            reinterpret_cast<void(*)(uint32_t)>(*reinterpret_cast<void**>(puVar2))(1);
        }
    }
    FUN_005ae720();
}

// 0x5b7010 — observed shape
void FUN_005b7010(int param_1)
{
    int iVar2 = param_1;
    FUN_005bd490(param_1);
    int param_local = FUN_00557b10(static_cast<int>(DAT_00728c20));
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(iVar2) + 0xc);
    if (*reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(iVar2) + 8) <= uVar1) {
        FUN_006b34a0(static_cast<uint32_t>(*reinterpret_cast<int*>(static_cast<uintptr_t>(iVar2) + 0x14)) + uVar1);
    }
    FUN_005606f0(uVar1, &param_local);
}

// 0x5b7060 — observed shape
void FUN_005b7060(void* self)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    FUN_005bbd20();
    in_ECX[7] = 0;
    *in_ECX = reinterpret_cast<uint32_t>(&PTR_FUN_006c6398);
    in_ECX[8] = DAT_007177ac;
    in_ECX[9] = DAT_007177b0;
    in_ECX[10] = DAT_007177b4;
    in_ECX[0xb] = 0;
    in_ECX[0xd] = 0;
    in_ECX[0xe] = 0;
    in_ECX[0xc] = 0x3f800000;
    in_ECX[0xf] = 0x3f800000;
}

// 0x5b70d0 — observed shape
void FUN_005b70d0(void* self, uint32_t param_1)
{
    char* ecx = static_cast<char*>(self);
    FUN_005bbd70(param_1);
    uint32_t uVar1 = static_cast<uint32_t>(FUN_00545600());
    *reinterpret_cast<uint32_t*>(ecx + 0x1c) = uVar1;
}

// 0x5b7700 — observed shape
void FUN_005b7700(void* self, int param_1)
{
    char* ecx = static_cast<char*>(self);
    // NOTE: iStack_c also holds the observed stack-argument placeholders at the call sites below.
    int iStack_c = param_1;
    FUN_005bbf20();
    iStack_c = 0x5b7715;
    FUN_00545cc0();
    iStack_c = param_1;
    FUN_00535110();
    iStack_c = 4;
    uint32_t* vtbl = *reinterpret_cast<uint32_t**>(
        *reinterpret_cast<uint32_t**>(reinterpret_cast<char*>(static_cast<uintptr_t>(param_1)) + 0x15c));
    reinterpret_cast<void(*)(void*)>(vtbl[2])(ecx + 0x2c);
    reinterpret_cast<void(*)(void*)>(vtbl[2])(ecx + 0x30);
    reinterpret_cast<void(*)(void*, uint32_t)>(vtbl[2])(&iStack_c, 4);
    *reinterpret_cast<uint32_t*>(ecx + 0x34) = 4;
    if (0xa00010d < *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(static_cast<uintptr_t>(param_1)) + 0x1c)) {
        reinterpret_cast<void(*)(void*, uint32_t)>(vtbl[2])(ecx + 0x38, 4);
        reinterpret_cast<void(*)(void*, uint32_t)>(vtbl[2])(ecx + 0x3c, 4);
    }
}
