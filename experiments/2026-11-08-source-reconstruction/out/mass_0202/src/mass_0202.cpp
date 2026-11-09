// Reconstruction batch mass_0202
// Sid Meier's Pirates! (2004), PE32 i386
#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void* g_ptr_006a6020;
extern void* g_ptr_006a6028;
extern void* g_ptr_006a6030;
extern void* g_ptr_006a6044;
extern void* g_ptr_006a6050;
extern void* g_ptr_006a6054;
extern void* g_ptr_006a605c;
extern void* g_ptr_006a6060;
extern void* g_ptr_006a6064;
extern void* g_ptr_006a606c;
extern void* g_ptr_006a6070;
extern void* g_ptr_006a6074;
extern void* g_ptr_006a6078;
extern void* g_ptr_006a607c;
extern void* g_ptr_006a6080;
extern void* g_ptr_006a6084;
extern void* g_ptr_006a6088;
extern void* g_ptr_006a608c;
extern void* g_ptr_006a6090;
extern void* g_ptr_006a6094;
// 0x5b3200 — observed shape
void FUN_005b3200(int param_1)
{
    int iVar2 = param_1;
    extern void FUN_005531c0(int);
    extern int DAT_00728be0;
    extern int FUN_00557b10(int);
    extern void FUN_006b34a0(int);
    extern void FUN_005606f0(unsigned int, int*);
    FUN_005531c0(param_1);
    param_1 = FUN_00557b10(DAT_00728be0);
    unsigned int uVar1 = *reinterpret_cast<unsigned int*>(iVar2 + 0xc);
    if (*reinterpret_cast<unsigned int*>(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(iVar2 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
}

// 0x5b32e0 — observed shape
void FUN_005b32e0(float param_1, int* param_2)
{
    (**(void (**)(void))(*param_2 + 0x44))();
    int iVar5 = param_2[0x14];
    unsigned short uVar7 = 0;
    if ((short)param_2[0x11] != 0) {
        do {
            float* pfVar1 = reinterpret_cast<float*>(iVar5 + (unsigned int)uVar7 * 0x28);
            float* pfVar2 = reinterpret_cast<float*>(param_2[8] + (unsigned int)uVar7 * 0xc);
            float fVar6 = param_1 - pfVar1[8];
            uVar7 = uVar7 + 1;
            float fVar3 = pfVar1[1];
            float fVar4 = pfVar1[2];
            *pfVar2 = fVar6 * *pfVar1 + *pfVar2;
            pfVar2[1] = fVar6 * fVar3 + pfVar2[1];
            pfVar2[2] = fVar6 * fVar4 + pfVar2[2];
            pfVar1[8] = param_1;
        } while (uVar7 < *reinterpret_cast<unsigned short*>(param_2 + 0x11));
    }
}

// 0x5b33b0 — observed shape
void FUN_005b33b0(int param_1)
{
    int iVar2 = param_1;
    extern void FUN_005bbfe0(int);
    extern int DAT_00728be8;
    extern int FUN_00557b10(int);
    extern void FUN_006b34a0(int);
    extern void FUN_005606f0(unsigned int, int*);
    FUN_005bbfe0(param_1);
    param_1 = FUN_00557b10(DAT_00728be8);
    unsigned int uVar1 = *reinterpret_cast<unsigned int*>(iVar2 + 0xc);
    if (*reinterpret_cast<unsigned int*>(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(iVar2 + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
}

// 0x5b3410 — observed shape
void FUN_005b3410(void* self, float param_1, int param_2, unsigned int param_3)
{
    extern void FUN_005bc490(float, int, unsigned int);
    int in_ECX = reinterpret_cast<int>(self);
    float* pfVar1 = reinterpret_cast<float*>(*reinterpret_cast<int*>(param_2 + 0x50) + (param_3 & 0xffff) * 0x28);
    float fVar2 = *pfVar1 * *reinterpret_cast<float*>(in_ECX + 0x5c) + *reinterpret_cast<float*>(in_ECX + 100) * pfVar1[2] + *reinterpret_cast<float*>(in_ECX + 0x60) * pfVar1[1];
    float fVar5 = fVar2 * *reinterpret_cast<float*>(in_ECX + 0x5c);
    float fVar4 = fVar2 * *reinterpret_cast<float*>(in_ECX + 0x60);
    float fVar3 = fVar2 * *reinterpret_cast<float*>(in_ECX + 100);
    if ((*reinterpret_cast<float*>(in_ECX + 0x24) == param_1) && (fVar2 < 0.001f)) {
        *pfVar1 = *pfVar1 - fVar5;
        pfVar1[1] = pfVar1[1] - fVar4;
        pfVar1[2] = pfVar1[2] - fVar3;
        FUN_005bc490(param_1, param_2, param_3);
        return;
    }
    fVar5 = *pfVar1 - (fVar5 + fVar5);
    *pfVar1 = fVar5;
    fVar4 = pfVar1[1] - (fVar4 + fVar4);
    pfVar1[1] = fVar4;
    fVar3 = pfVar1[2] - (fVar3 + fVar3);
    pfVar1[2] = fVar3;
    fVar2 = *reinterpret_cast<float*>(in_ECX + 0xc);
    *pfVar1 = fVar5 * fVar2;
    pfVar1[1] = fVar4 * fVar2;
    pfVar1[2] = fVar3 * fVar2;
    FUN_005bc490(param_1, param_2, param_3);
}

// 0x5b3c50 — observed shape
void FUN_005b3c50(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7, uint32_t param_8, uint32_t param_9, uint32_t param_10, uint32_t param_11, uint32_t param_12, uint32_t param_13)
{
    extern void FUN_005bc740(uint32_t, uint32_t, uint32_t, uint32_t);
    extern void FUN_00558080(void*, int);
    extern void FUN_00557990();
    extern uint32_t DAT_00727430;
    extern uint32_t DAT_00727434;
    extern uint32_t DAT_00727438;
    extern uint32_t DAT_007179b0;
    extern uint32_t PTR_FUN_006c5fe0;
    uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
    FUN_005bc740(param_1, param_2, param_3, param_4);
    in_ECX[0xc] = param_5;
    in_ECX[0xd] = param_6;
    in_ECX[0xe] = param_7;
    in_ECX[0xf] = param_8;
    in_ECX[0x10] = param_9;
    in_ECX[0x11] = param_10;
    in_ECX[0x12] = param_11;
    in_ECX[0x13] = param_12;
    in_ECX[0x14] = param_13;
    *in_ECX = PTR_FUN_006c5fe0;
    in_ECX[0x15] = 0x3f000000;
    in_ECX[0x16] = 0x3f000000;
    FUN_00558080(&DAT_00727430, 0);
    in_ECX[0x1b] = DAT_00727430;
    in_ECX[0x1c] = DAT_00727434;
    in_ECX[0x1d] = DAT_00727438;
    uint32_t* puVar2 = &DAT_007179b0;
    uint32_t* puVar3 = in_ECX + 0x1e;
    for (int iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
    }
    FUN_00557990();
    FUN_00557990();
}
// 0x5b3d30 — observed shape
void FUN_005b3d30(void* self, unsigned char param_1)
{
    extern void FUN_005b16f0();
    FUN_005b16f0();
    if ((param_1 & 1) != 0) {
        operator delete(self);
    }
}

// 0x5b4120 — observed shape
void FUN_005b4120(int param_1)
{
    int iVar2 = param_1;
    extern void FUN_005bd0f0(int);
    extern int DAT_00728c00;
    extern int FUN_00557b10(int);
    extern void FUN_006b34a0(int);
    extern void FUN_005606f0(unsigned int, int*);
    FUN_005bd0f0(param_1);
    param_1 = FUN_00557b10(DAT_00728c00);
    unsigned int uVar1 = *reinterpret_cast<unsigned int*>(iVar2 + 0xc);
    if (*reinterpret_cast<unsigned int*>(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(iVar2 + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
}

// 0x5b4190 — observed shape
void FUN_005b4190(void* self, uint32_t param_1)
{
    extern void FUN_005bbee0(uint32_t);
    int in_ECX = reinterpret_cast<int>(self);
    FUN_005bbee0(param_1);
    unsigned int uVar2 = 0;
    if (*reinterpret_cast<int*>(in_ECX + 0x28) != 0) {
        do {
            int* piVar1 = *reinterpret_cast<int**>(*reinterpret_cast<int*>(in_ECX + 0x20) + uVar2 * 4);
            if (piVar1 != nullptr) {
                (**(void (**)(uint32_t))(*piVar1 + 0x28))(param_1);
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < *reinterpret_cast<unsigned int*>(in_ECX + 0x28));
    }
}

// 0x5b41d0 — observed shape
uint32_t FUN_005b41d0(void* self, uint32_t param_1)
{
    extern uint32_t thunk_FUN_00538360(uint32_t);
    int in_ECX = reinterpret_cast<int>(self);
    uint32_t uVar2 = thunk_FUN_00538360(param_1);
    if ((char)uVar2 == '\0') {
        return uVar2;
    }
    unsigned int uVar4 = 0;
    unsigned int uVar3 = 0;
    if (*reinterpret_cast<int*>(in_ECX + 0x28) != 0) {
        do {
            int* piVar1 = *reinterpret_cast<int**>(*reinterpret_cast<int*>(in_ECX + 0x20) + uVar4 * 4);
            if (piVar1 != nullptr) {
                (**(void (**)(uint32_t))(*piVar1 + 0x14))(param_1);
            }
            uVar3 = *reinterpret_cast<unsigned int*>(in_ECX + 0x28);
            uVar4 = uVar4 + 1;
        } while (uVar4 < uVar3);
    }
    return (uint32_t)((uVar3 >> 8) << 8) | 1u;
}

// 0x5b4220 — observed shape
void FUN_005b4220(void* self, int* param_1, unsigned int unaff_EBX)
{
    extern void FUN_005bbf80(int*);
    int in_ECX = reinterpret_cast<int>(self);
    int* piVar1 = param_1;
    FUN_005bbf80(param_1);
    int* param_1_ptr = *reinterpret_cast<int**>(in_ECX + 0x28);
    (**(void (**)(int**, int))(*reinterpret_cast<int*>(piVar1[0x58]) + 0xc))(&param_1_ptr, 4);
    unsigned int uVar2 = 0;
    if (unaff_EBX != 0) {
        do {
            (**(void (**)(uint32_t))(*piVar1 + 0x2c))(*reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(in_ECX + 0x20) + uVar2 * 4));
            uVar2 = uVar2 + 1;
        } while (uVar2 < unaff_EBX);
    }
}
// 0x5b44a0 — observed shape
int* FUN_005b44a0(void* self, int* param_1, unsigned int param_2, uint32_t* param_3)
{
    extern void FUN_0057a3f0(int);
    extern void FUN_00581300(unsigned int, uint32_t**);
    int in_ECX = reinterpret_cast<int>(self);
    uint32_t* puVar4 = param_3;
    if (*reinterpret_cast<unsigned int*>(in_ECX + 0x28) <= param_2) {
        if (param_3 != nullptr) {
            param_3[1] = param_3[1] + 1;
        }
        if (*reinterpret_cast<unsigned int*>(in_ECX + 0x24) <= param_2) {
            FUN_0057a3f0(*reinterpret_cast<int*>(in_ECX + 0x30) + param_2);
        }
        FUN_00581300(param_2, &param_3);
        if (puVar4 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar4 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                (**(void (**)(int))(*puVar4))(1);
            }
        }
        *param_1 = 0;
        return param_1;
    }
    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(*reinterpret_cast<int*>(in_ECX + 0x20) + param_2 * 4);
    if (puVar2 != nullptr) {
        puVar2[1] = puVar2[1] + 1;
    }
    if (param_3 != nullptr) {
        param_3[1] = param_3[1] + 1;
    }
    FUN_00581300(param_2, &param_3);
    if (puVar4 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar4 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (**(void (**)(int))(*puVar4))(1);
        }
    }
    *param_1 = reinterpret_cast<int>(puVar2);
    if (puVar2 != nullptr) {
        int iVar3 = puVar2[1];
        puVar2[1] = iVar3 + 1;
        puVar2[1] = iVar3;
        if (iVar3 == 0) {
            (**(void (**)(int))(*puVar2))(1);
        }
    }
    return param_1;
}

// 0x5b4570 — observed shape
void FUN_005b4570(void* self, unsigned char param_1)
{
    extern void FUN_0053bac0();
    extern void FUN_005bbd50();
    FUN_0053bac0();
    FUN_005bbd50();
    if ((param_1 & 1) != 0) {
        operator delete(self);
    }
}

// 0x5b45a0 — observed shape
void FUN_005b45a0(void* self, uint32_t param_1, uint32_t* param_2)
{
    extern void FUN_005bbeb0(uint32_t, uint32_t*);
    extern int* FUN_005b44a0(void*, int*, unsigned int, uint32_t*);
    int in_ECX = reinterpret_cast<int>(self);
    uint32_t* puVar2 = param_2;
    FUN_005bbeb0(param_1, param_2);
    unsigned int uVar4 = 0;
    if (*reinterpret_cast<int*>(in_ECX + 0x28) != 0) {
        do {
            int* piVar1 = *reinterpret_cast<int**>(*reinterpret_cast<int*>(in_ECX + 0x20) + uVar4 * 4);
            if (piVar1 != nullptr) {
                uint32_t uVar3 = (**(uint32_t (**)(uint32_t*))(*piVar1 + 8))(puVar2);
                FUN_005b44a0(self, reinterpret_cast<int*>(&param_2), uVar4, reinterpret_cast<uint32_t*>(uVar3));
                if (param_2 != nullptr) {
                    int* piVar1b = reinterpret_cast<int*>(param_2 + 1);
                    *piVar1b = *piVar1b + -1;
                    if (*piVar1b == 0) {
                        (**(void (**)(int))(*param_2))(1);
                    }
                }
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < *reinterpret_cast<unsigned int*>(in_ECX + 0x28));
    }
}

// 0x5b4600 — observed shape
void FUN_005b4600(int param_1)
{
    int iVar2 = param_1;
    extern void FUN_005bbfe0(int);
    extern int DAT_00728c08;
    extern int FUN_00557b10(int);
    extern void FUN_006b34a0(int);
    extern void FUN_005606f0(unsigned int, int*);
    FUN_005bbfe0(param_1);
    param_1 = FUN_00557b10(DAT_00728c08);
    unsigned int uVar1 = *reinterpret_cast<unsigned int*>(iVar2 + 0xc);
    if (*reinterpret_cast<unsigned int*>(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(iVar2 + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
}

// 0x5b4650 — observed shape
uint32_t* FUN_005b4650(uint32_t param_1)
{
    extern uint32_t* FUN_00533c78(unsigned int);
    extern void FUN_005bbd20();
    extern void FUN_005b45a0(void*, uint32_t, uint32_t*);
    extern uint32_t PTR_FUN_006c60b0;
    extern uint32_t PTR_FUN_006c0bd0;
    uint32_t* puVar1 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x34));
    if (puVar1 == nullptr) {
        FUN_005b45a0(nullptr, 0, reinterpret_cast<uint32_t*>(param_1));
        return nullptr;
    }
    FUN_005bbd20();
    *puVar1 = PTR_FUN_006c60b0;
    puVar1[7] = PTR_FUN_006c0bd0;
    puVar1[9] = 0;
    puVar1[0xc] = 1;
    puVar1[10] = 0;
    puVar1[0xb] = 0;
    puVar1[8] = 0;
    FUN_005b45a0(puVar1, reinterpret_cast<uint32_t>(puVar1), reinterpret_cast<uint32_t*>(param_1));
    return puVar1;
}

// 0x5b46d0 — observed shape
void FUN_005b46d0(void* self)
{
    extern uint32_t PTR_FUN_006c60f8;
    uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
    *in_ECX = PTR_FUN_006c60f8;
    int iVar2 = in_ECX[1];
    if (iVar2 != 0) {
        int iVar4 = *reinterpret_cast<int*>(iVar2 + -4);
        int iVar5 = iVar2 + iVar4 * 4;
        if (-1 < iVar4 + -1) {
            do {
                uint32_t* puVar3 = *reinterpret_cast<uint32_t**>(iVar5 + -4);
                iVar5 = iVar5 + -4;
                if (puVar3 != nullptr) {
                    int* piVar1 = reinterpret_cast<int*>(puVar3 + 1);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) {
                        (**(void (**)(int))(*puVar3))(1);
                    }
                }
                iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
        }
        operator delete(reinterpret_cast<void*>(iVar2 + -4));
    }
}

// 0x5b4740 — observed shape
void FUN_005b4740(void* self, int param_1, uint32_t* param_2, float* param_3)
{
    extern void FUN_005579c0(void*);
    extern void* FUN_00548b20(void*, void*);
    extern uint32_t* FUN_00502260(float*, uint32_t*);
    extern float* FUN_0053ca60(float*, void*);
    extern void FUN_00491640();
    int in_ECX = reinterpret_cast<int>(self);
    if (param_1 != 0) {
        uint32_t local_9c[13];
        uint32_t local_68[13];
        unsigned char local_d0[52];
        unsigned char local_34[52];
        float local_e8, local_e4, local_e0;
        uint32_t* puVar2 = reinterpret_cast<uint32_t*>(param_1 + 0x6c);
        uint32_t* puVar5 = local_9c;
        for (int iVar4 = 0xd; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar5 = *puVar2;
            puVar2 = puVar2 + 1;
            puVar5 = puVar5 + 1;
        }
        puVar2 = reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(in_ECX + 0x14) + 0x6c);
        puVar5 = local_68;
        for (int iVar4 = 0xd; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar5 = *puVar2;
            puVar2 = puVar2 + 1;
            puVar5 = puVar5 + 1;
        }
        FUN_005579c0(local_34);
        FUN_00548b20(local_d0, local_9c);
        puVar2 = FUN_00502260(&local_e8, param_2);
        *param_2 = *puVar2;
        param_2[1] = puVar2[1];
        param_2[2] = puVar2[2];
        if (*reinterpret_cast<int*>(in_ECX + 0x80) != 2) {
            float* pfVar3 = FUN_0053ca60(&local_e8, param_3);
            *param_3 = *pfVar3;
            param_3[1] = pfVar3[1];
            param_3[2] = pfVar3[2];
            return;
        }
        FUN_0053ca60(&local_e8, reinterpret_cast<void*>(in_ECX + 0x88));
        int iVar4b = rand();
        float fVar1 = ((float)iVar4b * 3.051851e-05f - 0.5f) * *reinterpret_cast<float*>(in_ECX + 0x20) + *reinterpret_cast<float*>(in_ECX + 0x1c);
        FUN_00491640();
        *param_3 = local_e8 * fVar1;
        param_3[1] = local_e4 * fVar1;
        param_3[2] = local_e0 * fVar1;
    }
}

// 0x5b4890 — observed shape
uint32_t FUN_005b4890(int* param_1)
{
    extern void FUN_0051ac30(int);
    extern int FUN_00533c78(unsigned int);
    extern int FUN_00562300();
    extern char FUN_00563f50(int, int, unsigned int, int, int);
    extern uint32_t DAT_00727c3c;
    if (param_1 != nullptr) {
        for (uint32_t* puVar3 = (**(uint32_t* (**)(void))(*param_1 + 4))(); puVar3 != nullptr; puVar3 = reinterpret_cast<uint32_t*>(puVar3[1])) {
            if (puVar3 == &DAT_00727c3c) {
                int iVar1 = param_1[0x30];
                if (iVar1 == 0) {
                    return 0;
                }
                int iVar4 = *reinterpret_cast<int*>(iVar1 + 0xc);
                if (iVar4 != 0) {
                    int iVar5 = *reinterpret_cast<int*>(iVar4 + 0xc);
                    if (iVar5 != 0) {
                        FUN_0051ac30(iVar5);
                        return 1;
                    }
                    if (iVar4 != 0) {
                        unsigned int uVar6 = *reinterpret_cast<unsigned int*>(iVar4 + 0x44);
                        if (uVar6 < 4) {
                            uVar6 = 4;
                        }
                        int iVar4b = FUN_00533c78(0x14);
                        int iVar5b = 0;
                        if (iVar4b != 0) {
                            iVar5b = FUN_00562300();
                        }
                        (void)iVar5b;
                        char cVar2 = FUN_00563f50(param_1[0x2f], *reinterpret_cast<int*>(iVar1 + 0xc), uVar6, 4, 0);
                        if (cVar2 != '\0') {
                            FUN_0051ac30(iVar5);
                            return 1;
                        }
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}

// 0x5b4950 — observed shape
void FUN_005b4950(float* param_1, float* param_2, int param_3, int param_4, int param_5, int param_6)
{
    extern void FUN_005579c0(void*);
    extern float* FUN_00548b20(void*, void*);
    extern void FUN_0053c9e0(float*, float);
    extern float DAT_00727438;
    extern float DAT_00727430;
    extern float DAT_00727434;
    int iVar2 = *reinterpret_cast<int*>(param_4 + 0xc);
    unsigned char local_d0[52];
    float local_140[4];
    FUN_005579c0(local_d0);
    float* puVar7 = FUN_00548b20(local_140, local_d0);
    float local_164 = DAT_00727438;
    float local_188 = DAT_00727438;
    uint32_t local_9c[13];
    uint32_t* puVar16 = local_9c;
    for (int iVar11 = 0xd; iVar11 != 0; iVar11 = iVar11 + -1) {
        *puVar16 = reinterpret_cast<uint32_t*>(puVar7)[0];
        puVar7 = puVar7 + 1;
        puVar16 = puVar16 + 1;
    }
    iVar2 = *reinterpret_cast<int*>(iVar2 + 0x48);
    float local_16c = DAT_00727430;
    float local_190 = DAT_00727430;
    float local_168 = DAT_00727434;
    float local_18c = DAT_00727434;
    int iVar11b = *reinterpret_cast<int*>(*reinterpret_cast<int*>(param_3 + 0xbc) + 0x24);
    unsigned int iVar8 = (unsigned int)*reinterpret_cast<unsigned short*>(*reinterpret_cast<int*>(param_5 + 0xc) + param_6 * 2) * 0xc;
    float* pfVar13 = reinterpret_cast<float*>(*reinterpret_cast<int*>(*reinterpret_cast<int*>(param_3 + 0xbc) + 0x20) + iVar8);
    float fVar3 = *pfVar13;
    float fVar4 = pfVar13[1];
    float fVar5 = pfVar13[2];
    float fVar12, fVar14, fVar9;
    if (iVar11b == 0) {
        fVar12 = 1.0f;
        fVar14 = 0.0f;
        fVar9 = 0.0f;
    } else {
        pfVar13 = reinterpret_cast<float*>(iVar8 + iVar11b);
        fVar12 = *pfVar13;
        fVar14 = pfVar13[1];
        fVar9 = pfVar13[2];
    }
    unsigned int uVar10 = (unsigned int)*reinterpret_cast<unsigned short*>(param_5 + 0x24);
    unsigned int uVar15 = 0;
    if (uVar10 != 0) {
        int local_154 = param_6 << 4;
        float local_140_copy[13];
        float local_10c = 0, local_108 = 0, local_104 = 0, local_100 = 0, local_fc = 0, local_f8 = 0, local_f4 = 0, local_f0 = 0, local_ec = 0, local_e8 = 0, local_d4 = 0, local_11c = 0, local_118 = 0, local_114 = 0, local_130 = 0, local_12c = 0, local_128 = 0, local_124 = 0, local_120 = 0;
        float local_110 = 0;
        do {
            unsigned short uVar6;
            if (*reinterpret_cast<int*>(param_5 + 0x10) == 0) {
                uVar6 = *reinterpret_cast<unsigned short*>(*reinterpret_cast<int*>(param_5 + 4) + uVar15 * 2);
            } else {
                uVar6 = *reinterpret_cast<unsigned short*>(*reinterpret_cast<int*>(param_5 + 4) + (unsigned int)*reinterpret_cast<unsigned char*>(uVar10 * param_6 + *reinterpret_cast<int*>(param_5 + 0x10) + uVar15) * 2);
            }
            int iVar11c = (unsigned int)uVar6 * 0x4c + iVar2;
            unsigned char local_68[52];
            unsigned char local_34[52];
            FUN_00548b20(local_34, reinterpret_cast<void*>(*reinterpret_cast<int*>(*reinterpret_cast<int*>(param_4 + 0x14) + (unsigned int)uVar6 * 4) + 0x6c));
            float* pfVar13b = FUN_00548b20(local_68, reinterpret_cast<void*>(iVar11c));
            float* pfVar17 = local_140_copy;
            for (int iVar11d = 0xd; iVar11d != 0; iVar11d = iVar11d + -1) {
                *pfVar17 = *pfVar13b;
                pfVar13b = pfVar13b + 1;
                pfVar17 = pfVar17 + 1;
            }
            FUN_0053c9e0(&local_10c, local_110);
            float fVar1 = *reinterpret_cast<float*>(local_154 + *reinterpret_cast<int*>(param_5 + 8));
            local_d4 = local_f4 * fVar3 + local_f0 * fVar4 + local_ec * fVar5 + local_114;
            local_154 = local_154 + 4;
            uVar10 = (unsigned int)*reinterpret_cast<unsigned short*>(param_5 + 0x24);
            uVar15 = uVar15 + 1;
            local_e8 = (local_10c * fVar3 + local_108 * fVar4 + local_104 * fVar5 + local_11c) * fVar1;
            local_16c = local_e8 + local_16c;
            local_168 = local_168 + (local_100 * fVar3 + local_fc * fVar4 + local_f8 * fVar5 + local_118) * fVar1;
            local_164 = local_164 + local_d4 * fVar1;
            local_190 = (local_140_copy[0] * fVar12 + local_140_copy[1] * fVar14 + local_140_copy[2] * fVar9) * fVar1 + local_190;
            local_18c = local_18c + (local_140_copy[3] * fVar12 + local_130 * fVar14 + local_12c * fVar9) * fVar1;
            local_188 = local_188 + (local_128 * fVar12 + local_124 * fVar14 + local_120 * fVar9) * fVar1;
        } while (uVar15 < uVar10);
        for (int i = 0; i < 13; i++) local_140[i] = local_140_copy[i];
    }
    float fVar3b = sqrtf(local_190 * local_190 + local_18c * local_18c + local_188 * local_188);
    if (fVar3b <= 1e-06f) {
        local_190 = 0.0f;
        local_18c = 0.0f;
        local_188 = 0.0f;
    } else {
        fVar3b = 1.0f / fVar3b;
        local_190 = local_190 * fVar3b;
        local_18c = local_18c * fVar3b;
        local_188 = local_188 * fVar3b;
    }
    *param_1 = local_16c;
    param_1[1] = local_168;
    param_1[2] = local_164;
    *param_2 = local_190;
    param_2[1] = local_18c;
    param_2[2] = local_188;
}

// 0x5b4dd0 — observed shape
void FUN_005b4dd0(void* self, int* param_1, unsigned int unaff_EBX)
{
    extern void FUN_005afc10(int*);
    extern void FUN_00535150(int*);
    int in_ECX = reinterpret_cast<int>(self);
    int* piVar1 = param_1;
    FUN_005afc10(param_1);
    int* param_1_ptr = *reinterpret_cast<int**>(in_ECX + 0x5c);
    (**(void (**)(int**, int))(*reinterpret_cast<int*>(piVar1[0x58]) + 0xc))(&param_1_ptr, 4);
    unsigned int uVar2 = 0;
    if (unaff_EBX != 0) {
        do {
            (**(void (**)(uint32_t))(*piVar1 + 0x2c))(*reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(in_ECX + 0x54) + uVar2 * 4));
            uVar2 = uVar2 + 1;
        } while (uVar2 < unaff_EBX);
    }
    (**(void (**)(int, int))(*reinterpret_cast<int*>(piVar1[0x58]) + 0xc))(in_ECX + 0x80, 4);
    (**(void (**)(int, int))(*reinterpret_cast<int*>(piVar1[0x58]) + 0xc))(in_ECX + 0x84, 4);
    FUN_00535150(piVar1);
}
