#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <windows.h>

// Extern helpers observed in listings
uint32_t FUN_004baaa0();
uint32_t FUN_004ab200();
void FUN_004ab0d0(uint32_t a, int32_t b);
int32_t FUN_00533c78(size_t sz);
uint32_t FUN_00589b60(void* a, void* b, void* c, void* d, void* e);
uint32_t FUN_0058edf0(uint32_t a);
void FUN_0058f000(int32_t a);
void FUN_0058f6e0(uint32_t a, int b);
void FUN_004c1480(int32_t* param_1);
void FUN_004c2d90(int32_t a);
int32_t FUN_00533db0(int a);
uint32_t FUN_00449390(void* a, void* b);
void FUN_004127b0(void* a, size_t b, int c, void* d);
void FUN_00540460(const char* s);
uint32_t FUN_00549e00(int a, float* b, float c, int d, int e, int f, uint8_t* g);
void FUN_00534350();
void FUN_00534130();
void FUN_00591050();
void FUN_00591380(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
void FUN_005913a0(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
void FUN_00591150();
uint32_t FUN_005911a0(int a);
void FUN_005910a0();
uint32_t FUN_004c2470(int* a);
void FUN_004282e0(uint32_t a);
int32_t FUN_004aaea0();
void FUN_004aac10(int32_t a);
void FUN_004c2cd0();
void FUN_004c2c80(void* a);
void FUN_004c2c40(float a);
void FUN_004c2ba0(void* a);
void FUN_004c2d20();
void FUN_004e6420();
void FUN_004e6150(void* a);
void FUN_004c27a0(int* a, uint32_t b);
void FUN_004c2810(int* a, uint32_t b);
void FUN_004c2120(int* a, uint32_t b, uint32_t c);
int32_t FUN_004cddf0(int a, int b, int c, int* d, float* e);
int32_t FUN_004c2d70(int a, int b);
int32_t FUN_005f0ddc();
double FUN_00512f70(int a);
void FUN_0054a8f0(void* a, int b, void* c, void* d, int e);
void FUN_004aad70(void* a);
uint32_t FUN_004bb4b0(int a);
void FUN_004bb840(int a, int b);
uint32_t FUN_006b34a0(int a);
void FUN_005606f0(uint32_t a, int* b);
void* operator_new(size_t sz);
void operator_delete(void* p);
void operator_delete_sized(void* p, size_t sz);

// Globals observed
extern uint32_t DAT_00727560;
extern uint32_t DAT_00727598;
extern uint32_t DAT_00727430;
extern uint32_t DAT_00727434;
extern uint32_t DAT_00727438;
extern uint32_t DAT_007177ac;
extern uint32_t DAT_007177b8;
extern uint32_t DAT_007177c4;
extern uint32_t DAT_00728acc;
extern uint32_t DAT_0071779c;
extern uint32_t DAT_007177a0;
extern uint32_t DAT_007177a4;
extern uint32_t DAT_007177a8;
extern void* PTR_FUN_0070d0ac;
extern void* PTR_FUN_0070d11c;
extern void* PTR_FUN_0070d044;
extern void* PTR_FUN_0070d100;
extern void* PTR_FUN_0070d0e4;
extern void* PTR_FUN_0070d0c8;
extern void* PTR_FUN_0070d138;
extern uint32_t DAT_00727854;
extern uint32_t DAT_007278d4;
extern uint32_t DAT_0072cd78;
extern uint32_t DAT_00726249;

// 0x4c1210 — observed shape
uint32_t FUN_004c1210(int32_t in_EAX, int32_t in_EDX) {
    char local_80[128];
    int32_t* piVar1;
    uint32_t* puVar2;
    if (in_EDX != 0 && in_EAX != 0) {
        sprintf(local_80, "dummy_%s_%02d");
        piVar1 = (int32_t*)FUN_004baaa0();
        piVar1 = (int32_t*)(**(int32_t*(**)(int32_t*, char*))((*(void***)piVar1)[0x40 / 4]))(piVar1, local_80);
        if (piVar1 != nullptr) {
            for (puVar2 = (uint32_t*)(**(uint32_t*(**)(int32_t*))((*(void***)piVar1)[1]))(piVar1); puVar2 != nullptr; puVar2 = (uint32_t*)puVar2[1]) {
                if (puVar2 == &DAT_00727560) {
                    return FUN_004ab200();
                }
            }
        }
    }
    return 0;
}

// 0x4c12a0 — observed shape
void FUN_004c12a0(uint32_t param_1, int32_t param_2, uint32_t param_3, int32_t unaff_EBX) {
    char local_80[128];
    int32_t* piVar2;
    uint32_t* puVar3;
    if (param_2 != 0 && unaff_EBX != 0) {
        bool bVar1 = true;
        int32_t iVar5 = 1;
        do {
            if (!bVar1) return;
            sprintf(local_80, "dummy_%s_%02d");
            piVar2 = (int32_t*)FUN_004baaa0();
            piVar2 = (int32_t*)(**(int32_t*(**)(int32_t*, char*))((*(void***)piVar2)[0x40 / 4]))(piVar2, local_80);
            if (piVar2 != nullptr) {
                for (puVar3 = (uint32_t*)(**(uint32_t*(**)(int32_t*))((*(void***)piVar2)[1]))(piVar2); puVar3 != nullptr; puVar3 = (uint32_t*)puVar3[1]) {
                    if (puVar3 == &DAT_00727560) {
                        int32_t iVar4 = (int32_t)FUN_004ab200();
                        if (iVar4 != 0) {
                            FUN_004ab0d0(param_3, 0xffffffff);
                        }
                        goto LAB_004c131a;
                    }
                }
            }
            bVar1 = false;
        LAB_004c131a:
            iVar5 = iVar5 + 1;
        } while (iVar5 < 100);
    }
}

// 0x4c1360 — observed shape
void FUN_004c1360(uint32_t param_1, char param_2, char param_3, float* in_EAX, float* unaff_EBX) {
    int32_t iVar1;
    int32_t iVar2;
    in_EAX[0] = in_EAX[0] * 0.5f;
    in_EAX[1] = in_EAX[1] * 0.5f;
    in_EAX[2] = in_EAX[2] * 0.5f;
    iVar1 = FUN_00533c78(0x40);
    if (iVar1 == 0) {
        iVar1 = 0;
    } else {
        iVar1 = (int32_t)FUN_00589b60(in_EAX, &DAT_00727430, &DAT_007177ac, &DAT_007177b8, &DAT_007177c4);
    }
    if ((*unaff_EBX != DAT_00727430) || (unaff_EBX[1] != DAT_00727434) || (unaff_EBX[2] != DAT_00727438)) {
        *(float*)(iVar1 + 4) = *unaff_EBX;
        *(float*)(iVar1 + 8) = unaff_EBX[1];
        *(float*)(iVar1 + 0xc) = unaff_EBX[2];
    }
    iVar2 = FUN_00533c78(0x54);
    if (iVar2 == 0) {
        iVar2 = 0;
    } else {
        uint32_t uVar3 = FUN_004baaa0();
        iVar2 = (int32_t)FUN_0058edf0(uVar3);
    }
    FUN_0058f000(iVar1);
    *(uint32_t*)(iVar2 + 0x2c) = 2;
    *(uint32_t*)(iVar2 + 0x28) = (uint32_t)(param_3 != '\0') + 2;
    FUN_0058f6e0(*(uint32_t*)(iVar2 + 0xc), 2);
    FUN_004baaa0();
    FUN_004c2d90(iVar2);
    if (param_2 != '\0') {
        FUN_004c1480((int32_t*)param_1);
    }
}

// 0x4c1480 — observed shape
void FUN_004c1480(int32_t* param_1) {
    int32_t* piVar6 = (int32_t*)FUN_004baaa0();
    if (piVar6 != nullptr) {
        piVar6[1] = piVar6[1] + 1;
    }
    uint32_t* puVar10 = (uint32_t*)piVar6[0x2c];
    uint32_t* local_10 = puVar10;
    int32_t* piVar15 = param_1;
    if (puVar10 != nullptr) {
        puVar10[1] = puVar10[1] + 1;
        int32_t iVar7 = (int32_t)FUN_00449390(&DAT_00728acc, puVar10);
        if (iVar7 != 0) {
            piVar15 = *(int32_t**)(iVar7 + 0x30);
            if (piVar15 != nullptr) {
                iVar7 = (int32_t)(**(int32_t*(**)(int32_t*))((*(void***)piVar15)[3]))(piVar15);
                if (iVar7 == 1) goto LAB_004c14db;
            }
        }
    }
    piVar15 = param_1;
LAB_004c14db:
    if (piVar15 != nullptr) {
        float* pfVar8 = (float*)FUN_00533c78(0xd8);
        if (pfVar8 != nullptr) {
            FUN_004127b0(pfVar8, 0xc, 0x12, (void*)0x005cea70);
        }
        uint8_t* puVar9 = (uint8_t*)FUN_00533c78(0x12);
        uint32_t* puStack_18 = (uint32_t*)FUN_00533c78(0x120);
        if (puStack_18 != nullptr) {
            FUN_004127b0(puStack_18, 0x10, 0x12, (void*)0x004b1250);
        }
        uint32_t* puVar10b = puStack_18;
        for (int iVar7 = 0x12; iVar7 != 0; --iVar7) {
            *puVar10b = DAT_0071779c;
            puVar10b[1] = DAT_007177a0;
            puVar10b[2] = DAT_007177a4;
            puVar10b[3] = DAT_007177a8;
            puVar10b += 4;
        }
        float fStack_c = (float)piVar15[1] - (float)piVar15[0xd];
        float fVar2 = (float)piVar15[0xe] + (float)piVar15[2];
        float fVar3 = (float)piVar15[3] - (float)piVar15[0xf];
        float fVar4 = (float)piVar15[1] + (float)piVar15[0xd];
        float fVar5 = (float)piVar15[2] - (float)piVar15[0xe];
        float fStack_8 = (float)piVar15[3] + (float)piVar15[0xf];
        uint32_t puStack_14 = (uint32_t)fStack_8;
        pfVar8[0] = fStack_c; pfVar8[1] = fVar2; pfVar8[2] = fVar3;
        pfVar8[3] = fVar4; pfVar8[4] = fVar2; pfVar8[5] = fVar3;
        pfVar8[6] = fVar4; pfVar8[7] = fVar5; pfVar8[8] = fVar3;
        pfVar8[9] = fStack_c; pfVar8[10] = fVar5; pfVar8[11] = fVar3;
        pfVar8[12] = fStack_c; pfVar8[13] = fVar2; pfVar8[14] = fVar3;
        pfVar8[15] = fStack_c; pfVar8[16] = fVar2; pfVar8[17] = fStack_8;
        pfVar8[18] = fVar4; pfVar8[19] = fVar2; pfVar8[20] = fStack_8;
        pfVar8[21] = fVar4; pfVar8[22] = fVar5; pfVar8[23] = fStack_8;
        pfVar8[24] = fStack_c; pfVar8[25] = fVar5; pfVar8[26] = fStack_8;
        pfVar8[27] = fStack_c; pfVar8[28] = fVar2; pfVar8[29] = fStack_8;
        pfVar8[30] = fStack_c; pfVar8[31] = fVar2; pfVar8[32] = fVar3;
        pfVar8[33] = fStack_c; pfVar8[34] = fVar2; pfVar8[35] = fStack_8;
        pfVar8[36] = fVar4; pfVar8[37] = fVar2; pfVar8[38] = fVar3;
        pfVar8[39] = fVar4; pfVar8[40] = fVar2; pfVar8[41] = fStack_8;
        pfVar8[42] = fVar4; pfVar8[43] = fVar5; pfVar8[44] = fVar3;
        pfVar8[45] = fVar4; pfVar8[46] = fVar5; pfVar8[47] = fStack_8;
        pfVar8[48] = fStack_c; pfVar8[49] = fVar5; pfVar8[50] = fVar3;
        pfVar8[51] = fStack_c; pfVar8[52] = fVar5; pfVar8[53] = fStack_8;
        // BoundingBox lookup, create 0xcc object, insert
        puVar10 = (uint32_t*)(**(uint32_t*(**)(int32_t*, const char*))((*(void***)piVar6)[0x40 / 4]))(piVar6, "BoundingBox");
        piVar15 = piVar6;
        int32_t iVar7 = FUN_00533c78(0xcc);
        uint32_t* puVar12 = (iVar7 == 0) ? nullptr : (uint32_t*)FUN_00549e00(0x12, pfVar8, fVar5, 0, 0, 0, puVar9);
        if (puVar12 != nullptr) puVar12[1] = puVar12[1] + 1;
        FUN_00540460("BoundingBox");
        (**(void(**)(int32_t*, uint32_t*, int))((*(void***)piVar15)[0x70 / 4]))(piVar15, puVar12, 1);
        FUN_00534350();
        FUN_00534130();
        uint32_t lo = (uint32_t)(uintptr_t)puVar12;
        FUN_004c2470((int32_t*)&lo);
        if (puVar12 != nullptr) {
            int32_t* p = (int32_t*)puVar12 + 1;
            *p = *p - 1;
            if (*p == 0) (**(void(**)(uint32_t*, int))(*(void***)puVar12))(puVar12, 1);
        }
        if (puVar10 != nullptr) {
            int32_t* p = (int32_t*)puVar10 + 1;
            *p = *p - 1;
            if (*p == 0) (**(void(**)(uint32_t*, int))(*(void***)puVar10))(puVar10, 1);
        }
    }
    if (puVar10 != nullptr) {
        int32_t* p = (int32_t*)puVar10 + 1;
        int32_t v = *p - 1;
        *p = v;
        if (v == 0) (**(void(**)(uint32_t*, int))(*(void***)puVar10))(puVar10, 1);
    }
    int32_t v = piVar6[1] - 1;
    piVar6[1] = v;
    if (v == 0) (**(void(**)(int32_t*, int))(*(void***)piVar6))(piVar6, 1);
}

// 0x4c1a50 — observed shape
uint32_t FUN_004c1a50() {
    uint32_t uVar2;
    FUN_00591050();
    uVar2 = FUN_004baaa0();
    FUN_00591380(uVar2, 1, 0xffffffff, 1);
    uVar2 = FUN_004baaa0();
    FUN_005913a0(uVar2, 1, 0xffffffff, 1);
    FUN_00591150();
    uint32_t r = FUN_005911a0(0);
    FUN_005910a0();
    return r;
}
// 0x4c1ac0 — observed shape
int32_t FUN_004c1ac0(int32_t param_1, int32_t param_2, int32_t param_3, int32_t param_4, float param_5) {
    char in_AL = 0;
    uint32_t* unaff_EBX = nullptr;
    uint32_t* unaff_retaddr = nullptr;
    if (param_1 != 0) {
        int32_t iVar5 = 1;
        while (iVar5 != 0) {
            iVar5 = (int32_t)FUN_004bb4b0(1);
            if (iVar5 == param_1) {
                FUN_004bb840(param_1, 100);
                if ((in_AL == '\0') && (*(char*)((char*)param_1 + 0xac) != '\0') && (param_2 == *(int32_t*)((char*)param_1 + 0xb0)) && (param_3 == *(int32_t*)((char*)param_1 + 0xb4))) {
                    *(uint8_t*)((char*)param_1 + 0x24) = 1;
                    return param_1;
                }
                *(int32_t*)((char*)param_1 + 0xb4) = param_3;
                *(uint8_t*)((char*)param_1 + 0xac) = 1;
                *(int32_t*)((char*)param_1 + 0xb0) = param_2;
                int32_t local_64 = 0;
                int32_t* piVar6 = (int32_t*)FUN_004baaa0();
                uint32_t* puVar7 = (uint32_t*)(**(uint32_t*(**)(int32_t*, const char*))((*(void***)piVar6)[0x40 / 4]))(piVar6, "ProjectedPlane");
                if (puVar7 == nullptr) return 0;
                puVar7[1] += 1;
                int32_t iVar8 = (int32_t)param_5;
                if (unaff_EBX != nullptr) {
                    local_64 = 0x200;
                    if (param_5 != 0.0f) {
                        param_5 = 0.0f;
                        local_64 = 0;
                        puVar7 = (uint32_t*)(uintptr_t)FUN_004cddf0(iVar8, 0, 0, &local_64, &param_5);
                        if (puVar7 != nullptr) puVar7[1] += 1;
                        if (FUN_00533db0(8) != 0) FUN_004aad70(puVar7);
                        if (puVar7 != nullptr) {
                            int32_t* p = (int32_t*)puVar7 + 1; *p -= 1;
                            if (*p == 0) (**(void(**)(uint32_t*, int))(*(void***)puVar7))(puVar7, 1);
                        }
                    }
                    int32_t iVar5b = (int32_t)DAT_0072cd78;
                    int32_t iVar8b = FUN_004c2d70(0, param_2);
                    float fStack_3c = 0.0f;
                    int32_t iVar9 = iVar8b * 0x2cc + *(int32_t*)((char*)iVar5b + 8);
                    int32_t iVar11 = iVar8b * 0x124 + *(int32_t*)((char*)iVar5b + 4);
                    int32_t f = FUN_005f0ddc();
                    float fStack_60 = (float)f * *(float*)((char*)iVar11 + 0x84) + *(float*)((char*)iVar9 + 0x2a4);
                    uint32_t puStack_30v = (uint32_t)(int32_t)param_2;
                    f = FUN_005f0ddc();
                    float fVar3 = *(float*)((char*)iVar11 + 0x88);
                    float fStack_38 = *(float*)((char*)iVar11 + 0x84);
                    float fStack_5c = (float)f * fVar3 + *(float*)((char*)iVar9 + 0x2a8);
                    float fVar4 = fStack_60 * *(float*)((char*)iVar5b + 0x30);
                    param_5 = fStack_5c * *(float*)((char*)iVar5b + 0x34);
                    int32_t iv = (int32_t)FUN_004baaa0();
                    float fStack_24 = *(float*)((char*)iv + 0x5c);
                    float fStack_20 = *(float*)((char*)iv + 0x60);
                    float fStack_1c = *(float*)((char*)iv + 100);
                    if (fStack_24 != fVar4 || fStack_20 != param_5) {
                        float* pfStack_44 = (float*)unaff_EBX[8];
                        const char* pcVar12 = (const char*)(uintptr_t)DAT_00726249;
                        float afStack_54[4];
                        do {
                            afStack_54[0] = (float)((int8_t)pcVar12[-1] - 1) * fStack_38;
                            afStack_54[2] = (float)(int)(uint8_t)pcVar12[0] * fVar3;
                            float fStack_18 = afStack_54[0] + fStack_60;
                            float fStack_14 = afStack_54[2] + fStack_5c;
                            double fVar13 = FUN_00512f70(0);
                            float fVar1x = *(float*)((char*)DAT_0072cd78 + 0x44);
                            float fVar2x = *(float*)((char*)iVar9 + 0x290);
                            fStack_24 = afStack_54[0];
                            fStack_20 = afStack_54[2];
                            *pfStack_44 = afStack_54[0];
                            fStack_1c = (float)(fVar13 - (double)fVar1x * (double)fVar2x);
                            pfStack_44[1] = afStack_54[2];
                            pcVar12 += 2;
                            float* next = pfStack_44 + 3;
                            pfStack_44[2] = fStack_1c;
                            pfStack_44 = next;
                        } while ((uintptr_t)pcVar12 < 0x7262eb);
                        *(uint8_t*)((char*)unaff_EBX + 0x32) |= 1;
                        float fStack_c = fVar3 * 6.0f;
                        fStack_24 = 0.0f; unaff_EBX[4] = 0;
                        fStack_20 = 0.0f; fStack_1c = 0.0f;
                        unaff_EBX[5] = 0; unaff_EBX[6] = 0;
                        unaff_EBX[7] = (uint32_t)fStack_c;
                    }
                    if (FUN_00533db0(8) != 0) {
                        float vals[4] = {0.0f, 0.0f, 1.0f, 1.0f};
                        float pfStack_44v = 0.5f; // 0x3f000000
                        FUN_0054a8f0(vals, 0, vals + 2, &pfStack_44v, 1);
                        FUN_004c2d20();
                        float fStack_58 = ((float)local_64 * 0.125f * 0.5f) / (float)local_64;
                        float fStack_5cc = fStack_58 + 0.5f;
                        fStack_58 = 0.5f - fStack_58;
                        FUN_004c2cd0();
                        float fStack_38b = ((fStack_3c - fVar4) / fStack_38) * 0.2f;
                        float fStack_34 = ((((float)(int32_t)puStack_30v - param_5) / fVar3) * 0.2f);
                        FUN_004c2c80(&fStack_38b);
                        FUN_004c2c40((float)param_3 * 1.4629181e-09f);
                        float z = 2.35f - (float)param_4 * 0.01f * 1.35f;
                        if (z <= 2.35f) { if (z < 1.0f) z = 1.0f; }
                        else { z = 2.35f; }
                        uint32_t zbits = *(uint32_t*)&z;
                        FUN_004c2ba0(&zbits);
                        FUN_00534130();
                        (void)fStack_5cc;
                    }
                    int32_t iv2 = (int32_t)FUN_004baaa0();
                    *(float*)((char*)iv2 + 0x5c) = fVar4;
                    *(float*)((char*)iv2 + 0x60) = param_5;
                    *(float*)((char*)iv2 + 100) = 30.0f;
                    *(uint32_t*)((char*)param_1 + 0x20) |= 0x2000;
                    *(uint8_t*)((char*)param_1 + 0x24) = 1;
                    return param_1;
                }
                return 0;
            }
            in_AL = 0;
            param_1 = iVar5;
            if (iVar5 == 0) return 0;
        }
    }
    return 0;
}

// 0x4c2120 — observed shape
void FUN_004c2120(int32_t* param_1, uint32_t param_2, uint32_t param_3) {
    uint32_t* puVar1;
    int32_t iVar2;
    if (param_1 != nullptr) {
        for (puVar1 = (uint32_t*)(**(uint32_t*(**)(int32_t*))((*(void***)param_1)[1]))(param_1); puVar1 != nullptr; puVar1 = (uint32_t*)puVar1[1]) {
            if (puVar1 == &DAT_00727598) {
                iVar2 = FUN_00533db0(3);
                if (iVar2 != 0) {
                    *(uint32_t*)(iVar2 + 0x58) = param_2;
                    *(int32_t*)(iVar2 + 0x5c) += 1;
                }
                if ((char)param_3 != '\0' && (iVar2 = FUN_00533db0(0), iVar2 != 0)) {
                    *(uint16_t*)(iVar2 + 0x20) = (uint16_t)(*(uint16_t*)(iVar2 + 0x20) & 0xfeed | 0xed);
                }
                break;
            }
        }
        puVar1 = (uint32_t*)(**(uint32_t*(**)(int32_t*))((*(void***)param_1)[1]))(param_1);
        if (puVar1 != nullptr) {
            while (puVar1 != &DAT_00727560) {
                puVar1 = (uint32_t*)puVar1[1];
                if (puVar1 == nullptr) return;
            }
            uint32_t uVar3 = 0;
            if (param_1[0x30] != 0) {
                do {
                    iVar2 = *(int32_t*)((char*)param_1[0x2e] + uVar3 * 4);
                    if (iVar2 != 0) FUN_004c2120((int32_t*)iVar2, param_2, param_3);
                    uVar3++;
                } while (uVar3 < (uint32_t)param_1[0x30]);
            }
        }
    }
}

// 0x4c2200 — observed shape
void FUN_004c2200(float param_1, uint32_t param_2, int32_t in_ECX) {
    if (*(int32_t*)(in_ECX + 0xbc) != 0) {
        FUN_004c2200(param_1, 0, in_ECX);
    }
    param_1 = (float)(int32_t)param_1 * 0.01f;
    if (0.0f <= param_1) {
        if (100.0f < param_1) {
            param_1 = 100.0f;
            goto LAB_004c226c;
        }
        if (0.0f <= param_1) goto LAB_004c226c;
    }
    param_1 = 0.0f;
LAB_004c226c:
    if (param_1 != *(float*)(in_ECX + 0xa8)) {
        *(float*)(in_ECX + 0xa8) = param_1;
        float fVar3 = param_1;
        uint32_t uVar1 = FUN_004baaa0();
        FUN_004c2120((int32_t*)uVar1, *(uint32_t*)&fVar3, param_2);
        uVar1 = 0;
        if (param_1 == 1.0f) {
            FUN_004baaa0();
            int32_t iVar2 = FUN_00533db0((int)uVar1);
            if (iVar2 != 0) {
                uVar1 = FUN_004baaa0();
                FUN_004282e0(uVar1);
                FUN_004baaa0();
                FUN_00534130();
                return;
            }
        } else {
            FUN_004baaa0();
            int32_t iVar2 = FUN_00533db0((int)uVar1);
            if (iVar2 == 0) {
                iVar2 = FUN_00533c78(0x24);
                if (iVar2 == 0) {
                    iVar2 = 0;
                } else {
                    iVar2 = FUN_004aaea0();
                }
                *(uint16_t*)(iVar2 + 0x20) = (uint16_t)(*(uint16_t*)(iVar2 + 0x20) & 0xe2ed | 0x2ed);
                FUN_004baaa0();
                FUN_004aac10(iVar2);
                FUN_004baaa0();
                FUN_00534130();
                return;
            }
            *(uint16_t*)(iVar2 + 0x20) = (uint16_t)(*(uint16_t*)(iVar2 + 0x20) & 0xfeed | 0xed);
        }
        FUN_004baaa0();
        FUN_00534130();
    }
}

// 0x4c2380 — observed shape
void FUN_004c2380(int32_t in_EAX, uint32_t* unaff_ESI) {
    unaff_ESI[1] = (uint32_t)in_EAX;
    *unaff_ESI = (uint32_t)(uintptr_t)&PTR_FUN_0070d0ac;
    unaff_ESI[3] = 0;
    uint32_t* puVar1 = (uint32_t*)(uintptr_t)FUN_00533c78((size_t)(in_EAX << 2));
    unaff_ESI[2] = (uint32_t)(uintptr_t)puVar1;
    for (uint32_t uVar2 = unaff_ESI[1] & 0x3fffffff; uVar2 != 0; uVar2--) {
        *puVar1 = 0;
        puVar1++;
    }
    for (int32_t iVar3 = 0; iVar3 != 0; iVar3--) {
        *(uint8_t*)puVar1 = 0;
        puVar1 = (uint32_t*)((char*)puVar1 + 1);
    }
    *unaff_ESI = (uint32_t)(uintptr_t)&PTR_FUN_0070d11c;
}

// 0x4c23d0 — observed shape
void FUN_004c23d0(byte param_1, uint32_t* in_ECX) {
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_0070d11c;
    FUN_004e6420();
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_0070d0ac;
    FUN_004e6420();
    operator_delete((void*)(uintptr_t)in_ECX[2]);
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
}

// 0x4c2410 — observed shape
void FUN_004c2410(int32_t param_1, uint32_t param_2, uint32_t* in_ECX) {
    int32_t* piVar2 = nullptr;
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_0070d044;
    in_ECX[2] = (uint32_t)param_1;
    in_ECX[5] = param_2;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    if (param_1 != 0) {
        int32_t* piVar1 = (int32_t*)(uintptr_t)FUN_00533c78((size_t)(param_1 * 4 + 4));
        if (piVar1 != nullptr) {
            piVar2 = piVar1 + 1;
            *piVar1 = param_1;
            FUN_004127b0(piVar2, 4, param_1, (void*)(uintptr_t)0x004c2970);
        }
    }
    in_ECX[1] = (uint32_t)(uintptr_t)piVar2;
}

// 0x4c2470 — observed shape
uint32_t FUN_004c2470(int32_t* param_1, int32_t unaff_ESI) {
    if (*param_1 == 0) {
        return 0xffffffff;
    }
    uint32_t uVar1 = *(uint32_t*)(unaff_ESI + 0xc);
    uint32_t uVar2 = 0;
    if (uVar1 != 0) {
        int32_t* piVar3 = *(int32_t**)(unaff_ESI + 4);
        do {
            if (*piVar3 == 0) {
                (*(int32_t**)(unaff_ESI + 4))[uVar2] = *param_1;
                *(int32_t*)(unaff_ESI + 0x10) = *(int32_t*)(unaff_ESI + 0x10) + 1;
                return uVar2;
            }
            uVar2++;
            piVar3++;
        } while (uVar2 < *(uint32_t*)(unaff_ESI + 0xc));
    }
    if (*(uint32_t*)(unaff_ESI + 8) <= uVar1) {
        FUN_006b34a0(*(int32_t*)(unaff_ESI + 0x14) + (int32_t)uVar1);
    }
    FUN_005606f0(uVar1, param_1);
    return uVar1;
}

// 0x4c24e0 — observed shape
void FUN_004c24e0(void* self_param, uint32_t* unaff_ESI, int32_t** unaff_EDI) {
    uint32_t* puVar2 = (uint32_t*)(uintptr_t)(*unaff_EDI);
    if (puVar2 != unaff_ESI) {
        if (puVar2 != nullptr) {
            int32_t* piVar1 = (int32_t*)puVar2 + 1;
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) {
                (**(void(**)(uint32_t*, int))(*(void***)puVar2))(puVar2, 1);
            }
        }
        *unaff_EDI = (int32_t)(uintptr_t)unaff_ESI;
        if (unaff_ESI != nullptr) {
            unaff_ESI[1] = unaff_ESI[1] + 1;
        }
    }
}

// 0x4c2510 — observed shape
void FUN_004c2510(uint32_t* param_1, uint32_t* unaff_ESI, int32_t unaff_EDI) {
    uint32_t* puVar3 = (uint32_t*)(**(uint32_t*(**)(uint32_t*, uint32_t*))((*(void***)unaff_ESI)[1]))(param_1, nullptr);
    uint32_t* puVar4 = *(uint32_t**)(unaff_ESI[2] + (uintptr_t)puVar3 * 4);
    for (;;) {
        if (puVar4 == nullptr) {
            puVar4 = (uint32_t*)(**(uint32_t*(**)(uint32_t*))((*(void***)unaff_ESI)[1]))(nullptr);
            if (param_1 != nullptr) param_1[1] += 1;
            (**(void(**)(uint32_t*, uint32_t*, uint32_t*))((*(void***)unaff_ESI)[3]))(пуVar4 = puVar4, param_1, param_1);
            *puVar4 = *(uint32_t*)(unaff_ESI[2] + (uintptr_t)unaff_EDI * 4);
            *(uint32_t**)(unaff_ESI[2] + (uintptr_t)unaff_EDI * 4) = puVar4;
            unaff_ESI[3] += 1;
            puVar3 = param_1;
            if (puVar3 != nullptr) {
                int32_t* piVar1 = (int32_t*)puVar3 + 1;
                *piVar1 -= 1;
                if (*piVar1 == 0) (**(void(**)(uint32_t*, int))(*(void***)puVar3))(puVar3, 1);
            }
            return;
        }
        uint8_t cVar2 = (uint8_t)(**(uint32_t*(**)(uint32_t*, uint32_t*))((*(void***)unaff_ESI)[2]))(param_1, puVar4[1]);
        if (cVar2 != 0) {
            (**(void(**)(uint32_t*))((*(void***)unaff_ESI)[4]))(puVar4);
            if (puVar3 != nullptr) puVar3[1] += 1;
            (**(void(**)(uint32_t*, uint32_t*, uint32_t*))((*(void***)unaff_ESI)[3]))(puVar4, param_1, puVar3);
            if (puVar3 != nullptr) {
                int32_t* piVar1 = (int32_t*)puVar3 + 1;
                *piVar1 -= 1;
                if (*piVar1 == 0) (**(void(**)(uint32_t*, int))(*(void***)puVar3))(puVar3, 1);
            }
            return;
        }
        puVar4 = (uint32_t*)(uintptr_t)puVar4[0];
    }
}

// 0x4c2600 — observed shape
void FUN_004c2600(uint32_t* in_ECX) {
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_0070d100;
    if ((*(char*)(in_ECX + 4) != '\0') && (in_ECX[1] != 0)) {
        uint32_t uVar3 = 0;
        do {
            uint32_t* puVar2 = *(uint32_t**)(in_ECX[2] + uVar3 * 4);
            while (puVar2 != nullptr) {
                uint32_t* puVar1 = puVar2 + 1;
                puVar2 = (uint32_t*)(uintptr_t)puVar2[0];
                operator_delete_sized((void*)(uintptr_t)puVar1[0], 0);
                (void)puVar1;
            }
            uVar3++;
        } while (uVar3 < in_ECX[1]);
    }
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_0070d0e4;
    FUN_004e6420();
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_0070d0c8;
    FUN_004e6420();
    operator_delete((void*)(uintptr_t)in_ECX[2]);
}

// 0x4c26a0 — observed shape
void FUN_004c26a0(uint32_t* in_ECX) {
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_0070d138;
    int32_t iVar2 = (int32_t)in_ECX[1];
    if (iVar2 != 0) {
        int32_t iVar4 = *(int32_t*)(iVar2 - 4);
        int32_t iVar5 = iVar2 + iVar4 * 4;
        if (iVar4 - 1 >= -1) {
            do {
                uint32_t* puVar3 = *(uint32_t**)(iVar5 - 4);
                iVar5 -= 4;
                if (puVar3 != nullptr) {
                    int32_t* piVar1 = (int32_t*)puVar3 + 1;
                    *piVar1 -= 1;
                    if (*piVar1 == 0) (**(void(**)(uint32_t*, int))(*(void***)puVar3))(puVar3, 1);
                }
                iVar4 -= 1;
            } while (iVar4 != 0);
        }
        operator_delete((void*)(iVar2 - 4));
    }
}

// 0x4c26f0 — observed shape
void FUN_004c26f0(int32_t in_EAX, uint32_t in_ECX, uint32_t* unaff_EDI) {
    if (*(uint32_t*)(in_EAX + 8) <= in_ECX) return;
    int32_t iVar4 = 0;
    if (in_ECX < *(uint32_t*)(in_EAX + 0xc)) {
        iVar4 = *(int32_t*)(*(int32_t*)(in_EAX + 4) + in_ECX * 4);
        if (*unaff_EDI == 0) {
            if (iVar4 == 0) goto LAB_004c2740;
            iVar4 = *(int32_t*)(in_EAX + 0x10) - 1;
        } else {
            if (iVar4 != 0) goto LAB_004c2740;
            iVar4 = *(int32_t*)(in_EAX + 0x10) + 1;
        }
    } else {
        *(uint32_t*)(in_EAX + 0xc) = in_ECX + 1;
        if (*unaff_EDI == 0) goto LAB_004c2740;
        iVar4 = *(int32_t*)(in_EAX + 0x10) + 1;
    }
    *(int32_t*)(in_EAX + 0x10) = iVar4;
LAB_004c2740:;
    int32_t* piVar2 = (int32_t*)(*(int32_t*)(in_EAX + 4) + in_ECX * 4);
    uint32_t* puVar3 = (uint32_t*)(uintptr_t)(*piVar2);
    if (puVar3 != unaff_EDI) {
        if (puVar3 != nullptr) {
            int32_t* piVar1 = (int32_t*)puVar3 + 1;
            *piVar1 -= 1;
            if (*piVar1 == 0) (**(void(**)(uint32_t*, int))(*(void***)puVar3))(puVar3, 1);
        }
        int32_t v = (int32_t)(uintptr_t)unaff_EDI;
        *piVar2 = v;
        if (v != 0) *(int32_t*)(v + 4) += 1;
    }
}

// 0x4c2770 — observed shape
int32_t FUN_004c2770(uint32_t* unaff_ESI) {
    int32_t* piVar1 = (int32_t*)(uintptr_t)unaff_ESI[1];
    int32_t iVar2 = *piVar1;
    unaff_ESI[1] = (uint32_t)iVar2;
    if (iVar2 == 0) {
        unaff_ESI[2] = 0;
    } else {
        *(uint32_t*)(iVar2 + 4) = 0;
    }
    iVar2 = piVar1[2];
    (**(void(**)(int32_t*))((*(void***)unaff_ESI)[2]))(piVar1);
    unaff_ESI[3] -= 1;
    return iVar2;
}

// 0x4c27a0 — observed shape
void FUN_004c27a0(int32_t* param_1, uint32_t param_2) {
    if (param_1 != nullptr) {
        FUN_004e6150(&param_2);
        uint32_t* puVar2 = (uint32_t*)(**(uint32_t*(**)(int32_t*))((*(void***)param_1)[1]))(param_1);
        uint32_t uVar1 = param_2;
        if (puVar2 != nullptr) {
            while (puVar2 != &DAT_00727560) {
                puVar2 = (uint32_t*)(uintptr_t)puVar2[1];
                if (puVar2 == nullptr) return;
            }
            uint32_t uVar4 = 0;
            if (param_1[0x30] != 0) {
                uint32_t uVar3 = 0;
                for (;;) {
                    if (uVar4 >= (uint32_t)param_1[0x30]) break;
                    uVar3 = *(uint32_t*)((char*)param_1[0x2e] + uVar4 * 4);
                    FUN_004c27a0((int32_t*)(uintptr_t)uVar3, uVar1);
                    uVar4++;
                }
            }
        }
    }
}

// 0x4c2810 — observed shape
void FUN_004c2810(int32_t* param_1, uint32_t param_2) {
    if (param_1 != nullptr) {
        int32_t iVar1 = FUN_00533db0(0);
        if (iVar1 != 0 && ((*(uint16_t*)(iVar1 + 0x20) >> 0xd & 1) != 0)) {
            *(char*)(iVar1 + 0x22) = (char)param_2;
            *(uint16_t*)(iVar1 + 0x20) = (uint16_t)(*(uint16_t*)(iVar1 + 0x20) & 0xf3ff | 0x1200);
        }
        uint32_t* puVar2 = (uint32_t*)(**(uint32_t*(**)(int32_t*))((*(void***)param_1)[1]))(param_1);
        if (puVar2 != nullptr) {
            while (puVar2 != &DAT_00727560) {
                puVar2 = (uint32_t*)(uintptr_t)puVar2[1];
                if (puVar2 == nullptr) return;
            }
            uint32_t uVar4 = 0;
            if (param_1[0x30] != 0) {
                uint32_t uVar3 = 0;
                for (;;) {
                    if (uVar4 >= (uint32_t)param_1[0x30]) break;
                    uVar3 = *(uint32_t*)((char*)param_1[0x2e] + uVar4 * 4);
                    FUN_004c2810((int32_t*)(uintptr_t)uVar3, param_2);
                    uVar4++;
                }
            }
        }
    }
}
