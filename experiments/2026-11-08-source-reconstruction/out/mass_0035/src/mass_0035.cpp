#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cmath>
#include <windows.h>

extern int FUN_00533db0(int);
extern int FUN_004ad820();
extern int FUN_00449390(void*, uint32_t);
extern int FUN_004ad8f0(void*);
extern int FUN_004cddf0(void*, int, int, void*, void*);
extern int FUN_005f0ddc();
extern int FUN_004af080(void*, int, int, uint32_t*, int, float, float, int, int, uint32_t, uint32_t);
extern int FUN_004d0cd0(int, int, int);
extern uint32_t FUN_00533c78(int);
extern void FUN_00412840(uint32_t, uint32_t);
extern void FUN_004ae320(uint32_t*);
extern void FUN_004ff510(float, uint32_t);
extern float FUN_004ff4c0();
extern int FUN_004baaa0();
extern void FUN_004ae390(uint32_t);
extern int FUN_004ae640(int*, int*, int*);
extern void FUN_00582f50();
extern int FUN_00583070(uint32_t, uint32_t, int);
extern void FUN_005831c0();
extern uint8_t FUN_00535b40(void*, void*, void*);
extern uint8_t FUN_004ae7d0(int, int, int, uint32_t*, uint32_t*);
extern bool FUN_004ae740(uint32_t, uint32_t);
extern char FUN_00536ec0(float, float, void*, void*);
extern void FUN_004aac50(void**);
extern void FUN_00540c50();
extern void FUN_00534130();
extern void FUN_00534350();
extern void FUN_004f3350();
extern void FUN_004f2600(const char*, ...);
extern void FUN_004b1260(uint32_t);
extern int FUN_004aeb20(int, uint32_t, uint32_t, int, int);
extern int FUN_00508e20(int, float, float, float, uint32_t, int, uint32_t, uint32_t, uint32_t, uint32_t);
extern void FUN_0050a3b0(uint32_t, uint32_t, uint32_t, uint32_t);
extern void FUN_0053c6f0(void*, void*, void*);
extern void FUN_0053c7c0(float);
extern void FUN_0053c740(float);
extern void FUN_0053c780(float);
extern void* FUN_0053c8d0(void*, void*);
extern void operator_delete__(void*);
extern float FUN_00509500(int, uint32_t, int);
extern float FUN_005096b0();
extern void FUN_004aad70(int*);
extern int FUN_005428c0();
extern int FUN_005426d0();
extern void FUN_005606f0(int, void**);
extern uint32_t FUN_005473e0(int, void*, int, void*, void*, int, int, int, int, void*, void*);
extern int FUN_004baa30(uint32_t*, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern void FUN_004b0a90(int, int);
extern void FUN_004bd520();
extern void FUN_004afd20();
extern void FUN_00524e90(int*);

extern uint32_t DAT_008ea08c;
extern int DAT_008c9dec;
extern uint32_t DAT_00727520;
extern float DAT_008c84b0;
extern uint32_t DAT_0085a26c;
extern uint32_t DAT_0085a268;
extern int DAT_008c97d0;
extern uint32_t DAT_008e8f88;
extern int DAT_008cabe0;
extern uint32_t* DAT_008e9fd8;
extern uint32_t DAT_008ea08c_g;
extern uint32_t* DAT_008e9fe8;
extern uint8_t DAT_008cac36;
extern uint32_t DAT_007260d8;
extern uint32_t DAT_008cabb8;
extern uint32_t DAT_008cabbc;
extern int DAT_008cabc0;
extern uint32_t DAT_007260d4;
extern uint32_t DAT_008cabb0;
extern uint32_t DAT_008cabb4;
extern uint32_t DAT_00727448;
extern uint32_t DAT_00727560;
extern uint32_t DAT_007273fc;
extern uint32_t DAT_00726bbc;
extern uint32_t DAT_00726bb4;
extern int DAT_008cac18;
extern int DAT_008cac1c;
extern int DAT_0072637c;
extern int DAT_00726380;
extern int DAT_008c9dd8;
extern int DAT_008c9ddc;
extern int DAT_008c9de0;
extern uint8_t DAT_008ee1d0;
extern float DAT_007177c4;
extern float DAT_007177c8;
extern float DAT_007177cc;
extern uint32_t DAT_007177ac;
extern uint32_t DAT_007177b8;
extern uint32_t DAT_008ee1ac;
extern int DAT_0085a11c;
extern int DAT_008cacc8;
extern uint32_t DAT_008ea004;
extern int DAT_008cac00;
extern uint8_t DAT_008cac04;
extern uint32_t DAT_008ea00c;
extern uint32_t DAT_008ea008;
extern uint32_t PTR_FUN_0070c0a8;
extern uint32_t PTR_FUN_0070bed4;
extern uint32_t PTR_FUN_0070bf10;
extern uint32_t PTR_FUN_0070bf4c;
extern uint32_t DAT_008cacd0;
extern uint32_t DAT_006fb55c;

// 0x4ae0d0 — void (param_1, *param_2): copies 3 dwords, applies refcount dance, names Cylinder01:0/1.
void FUN_004ae0d0(uint32_t param_1, uint32_t* param_2) {
    uint32_t uVar4 = param_2[0];
    uint32_t uVar1 = param_2[1];
    uint32_t uVar2 = param_2[2];
    int iVar3 = FUN_00533db0(2);
    *(uint32_t*)(iVar3 + 0x28) = uVar4;
    *(uint32_t*)(iVar3 + 0x2c) = uVar1;
    *(uint32_t*)(iVar3 + 0x30) = uVar2;
    FUN_004ad820();
    (**(void(**)(uint32_t*))(*(uint32_t**)DAT_008ea08c + 0x74))(param_2);
    if (DAT_008c9dec != 0) {
        int* piVar5 = nullptr;
        if (*(int*)(DAT_008c9dec + 0x14) == 0) {
            piVar5 = nullptr;
        } else {
            piVar5 = *(int**)(*(int*)(DAT_008c9dec + 0x14) + 0x44);
            if (piVar5 != nullptr) {
                int iVar3b = piVar5[1];
                piVar5[1] = iVar3b + 1;
                piVar5[1] = iVar3b;
                if (iVar3b == 0) { (**(void(**)(int))piVar5[0])(1); }
            }
        }
        int iVar3c = (**(int(**)(const char*))((int)piVar5 + 0x40))("Cylinder01:0");
        if (iVar3c != 0 && (iVar3c = FUN_00533db0(8)) != 0) {
            uint32_t uVar4b = 0;
            if (**(int**)(iVar3c + 0x2c) != 0) uVar4b = *(uint32_t*)(**(int**)(iVar3c + 0x2c) + 4);
            FUN_00449390(&DAT_00727520, uVar4b);
            FUN_004ad8f0(param_2);
        }
        if (*(int*)(DAT_008c9dec + 0x14) == 0) {
            piVar5 = nullptr;
        } else {
            piVar5 = *(int**)(*(int*)(DAT_008c9dec + 0x14) + 0x44);
            if (piVar5 != nullptr) {
                int iVar3d = piVar5[1];
                piVar5[1] = iVar3d + 1;
                piVar5[1] = iVar3d;
                if (iVar3d == 0) { (**(void(**)(int))piVar5[0])(1); }
            }
        }
        int iVar3e = (**(int(**)(const char*))((int)piVar5 + 0x40))("Cylinder01:1");
        if (iVar3e != 0 && (iVar3e = FUN_00533db0(8)) != 0) {
            uint32_t uVar4c = 0;
            if (**(int**)(iVar3e + 0x2c) != 0) uVar4c = *(uint32_t*)(**(int**)(iVar3e + 0x2c) + 4);
            FUN_00449390(&DAT_00727520, uVar4c);
            FUN_004ad8f0((void*)(intptr_t)param_2);
        }
    }
}

// 0x4ae210 — void (void): loops while global float < f+1; Sleep(5).
void FUN_004ae210(void) {
    uint32_t local_8 = 0, local_4 = 0;
    uint32_t* puVar7 = (uint32_t*)FUN_004cddf0(&DAT_006fb55c, 0, 0, &local_4, &local_8);
    uint32_t uVar6 = local_4;
    uint32_t uVar5 = local_8;
    if (puVar7 != nullptr) puVar7[1] = puVar7[1] + 1;
    float fVar3 = DAT_008c84b0;
    float fVar2 = fVar3 + 1.0f;
    if ((!isnan(fVar3) && !isnan(fVar2)) && (fVar3 < fVar2 != (fVar3 == fVar2))) {
        do {
            FUN_004af080(puVar7, 0, 0, (uint32_t*)uVar6, (int)uVar5, 0, 0, (int)DAT_0085a26c, (int)DAT_0085a268, 0xffffffff, 0);
            int iVar8 = FUN_005f0ddc();
            FUN_004af080(nullptr, 0, 0, nullptr, 0, 0, 0, (int)DAT_0085a26c, (int)DAT_0085a268, iVar8 << 0x18, 0);
            FUN_004d0cd0(0, 0, 0);
            Sleep(5);
            double dVar4 = (double)fVar2;
            (void)dVar4;
        } while ((!isnan(DAT_008c84b0) && !isnan((double)fVar2)) && (DAT_008c84b0 < (double)fVar2 != (DAT_008c84b0 == (double)fVar2)));
    }
    if (puVar7 != nullptr) {
        int* piVar1 = (int*)puVar7 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) (**(void(**)(int))puVar7[0])(1);
    }
}

// 0x4ae320 — void (*param_1): copies 7 dwords from in_EAX+0x128, refcount swap.
void FUN_004ae320(uint32_t* param_1) {
    int in_EAX = 0; // register receiver fallback
    uint32_t local_1c[4];
    uint32_t local_c = 0, local_8 = 0;
    uint32_t* puVar3 = (uint32_t*)(in_EAX + 0x128);
    uint32_t* puVar4 = local_1c;
    for (int iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) { *puVar4++ = *puVar3++; }
    FUN_00412840(local_c, local_8);
    int iVar2b = DAT_008c97d0;
    uint32_t* puVar4b = *(uint32_t**)(DAT_008c97d0 + 8);
    uint32_t* puVar3b = (uint32_t*)(DAT_008c97d0 + 8);
    if (puVar4b != param_1) {
        if (puVar4b != nullptr) {
            int* piVar1 = (int*)puVar4b + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) (**(void(**)(int))puVar4b[0])(1);
        }
        *puVar3b = (uint32_t)param_1;
        if (param_1 != nullptr) param_1[1] = param_1[1] + 1;
    }
    *(uint8_t*)(iVar2b + 1) = 1;
}

// 0x4ae390 — void (*param_1): stack push, calls 0x4ae320, swaps slots 0x62/0x55, sets color constants.
void FUN_004ae390(uint32_t* param_1) {
    uint32_t* puVar3 = *(uint32_t**)(&DAT_008e8f88 + DAT_008cabe0 * 4);
    int iVar2 = DAT_008cabe0 * 4;
    DAT_008cabe0 = DAT_008cabe0 + 1;
    if (puVar3 != DAT_008e9fd8) {
        if (puVar3 != nullptr) {
            int* piVar1 = (int*)puVar3 + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) (**(void(**)(int))puVar3[0])(1);
        }
        puVar3 = DAT_008e9fd8;
        *(uint32_t**)(&DAT_008e8f88 + iVar2) = DAT_008e9fd8;
        if (puVar3 != nullptr) { int* piVar1 = (int*)puVar3 + 1; *piVar1 = *piVar1 + 1; }
    }
    FUN_004ae320(param_1);
    puVar3 = DAT_008e9fd8;
    if (DAT_008e9fd8 != param_1) {
        if (DAT_008e9fd8 != nullptr && ((iVar2 = DAT_008e9fd8[1], DAT_008e9fd8[1] = iVar2 + -1, iVar2 + -1 == 0))) {
            (**(void(**)(int))puVar3[0])(1);
        }
        DAT_008e9fd8 = param_1;
        if (param_1 != nullptr) param_1[1] = param_1[1] + 1;
    }
    uint32_t* puVar5 = (uint32_t*)DAT_008ea08c;
    uint32_t* puVar4 = (uint32_t*)DAT_008e9fd8[0x62];
    puVar3 = DAT_008e9fd8 + 0x62;
    if (puVar4 != (uint32_t*)DAT_008ea08c) {
        if (puVar4 != nullptr) {
            int* piVar1 = (int*)puVar4 + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) (**(void(**)(int))puVar4[0])(1);
        }
        *puVar3 = (uint32_t)puVar5;
        if (puVar5 != nullptr) puVar5[1] = puVar5[1] + 1;
    }
    puVar5 = DAT_008e9fe8;
    puVar4 = (uint32_t*)DAT_008e9fd8[0x55];
    puVar3 = DAT_008e9fd8 + 0x55;
    if (puVar4 != DAT_008e9fe8) {
        if (puVar4 != nullptr) {
            int* piVar1 = (int*)puVar4 + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) (**(void(**)(int))puVar4[0])(1);
        }
        *puVar3 = (uint32_t)puVar5;
        if (puVar5 != nullptr) puVar5[1] = puVar5[1] + 1;
    }
    if (DAT_008cac36 != 0) { float fVar6 = FUN_004ff4c0(); FUN_004ff510(fVar6, 0x3fe38e39); }
    DAT_007260d8 = 0xffff3cb0; DAT_008cabb8 = 0xffff3cb0; DAT_008cabbc = 0xffff3cb0; DAT_008cabc0 = 10000;
    DAT_007260d4 = 0xfff0bdc0; DAT_008cabb0 = 0xfff0bdc0; DAT_008cabb4 = 0xfff0bdc0;
    if (param_1 != nullptr) {
        int* piVar1 = (int*)param_1 + 1; *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) (**(void(**)(int))param_1[0])(1);
    }
}

// 0x4ae4f0 — void (void): pop stack, call 0x4ae320, reset color constants.
void FUN_004ae4f0(void) {
    DAT_008cabe0 = DAT_008cabe0 + -1;
    uint32_t* puVar3 = *(uint32_t**)(&DAT_008e8f88 + DAT_008cabe0 * 4);
    int iVar2 = DAT_008cabe0 * 4;
    if (puVar3 != nullptr) puVar3[1] = puVar3[1] + 1;
    uint32_t* puVar4 = *(uint32_t**)(&DAT_008e8f88 + iVar2);
    if (puVar4 != nullptr) {
        int* piVar1 = (int*)puVar4 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) (**(void(**)(int))puVar4[0])(1);
        *(int*)(&DAT_008e8f88 + iVar2) = 0;
    }
    FUN_004ae320(puVar3);
    puVar4 = DAT_008e9fd8;
    if (DAT_008e9fd8 != puVar3) {
        if (DAT_008e9fd8 != nullptr && ((iVar2 = DAT_008e9fd8[1], DAT_008e9fd8[1] = iVar2 + -1, iVar2 + -1 == 0))) {
            (**(void(**)(int))puVar4[0])(1);
        }
        DAT_008e9fd8 = puVar3;
        if (puVar3 != nullptr) puVar3[1] = puVar3[1] + 1;
    }
    DAT_007260d8 = 0xffff3cb0; DAT_008cabb8 = 0xffff3cb0; DAT_008cabbc = 0xffff3cb0; DAT_008cabc0 = 10000;
    DAT_007260d4 = 0xfff0bdc0; DAT_008cabb0 = 0xfff0bdc0; DAT_008cabb4 = 0xfff0bdc0;
    if (puVar3 != nullptr) {
        int* piVar1 = (int*)puVar3 + 1; *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) (**(void(**)(int))puVar3[0])(1);
    }
}

// 0x4ae5b0 — void (param_1): walks list; if DAT_00727448 found, calls 0x4ae390.
void FUN_004ae5b0(uint32_t param_1) {
    int* piVar2 = (int*)FUN_004baaa0();
    piVar2 = (int*)(**(int(**)(uint32_t))(*(int*)piVar2 + 0x40))(param_1);
    while (true) {
        if (piVar2 == nullptr) return;
        uint32_t* puVar3 = (uint32_t*)(**(uint32_t*(**)(void))(*(int*)piVar2 + 4))();
        while (true) {
            if (puVar3 == nullptr) { puVar3 = (uint32_t*)(**(uint32_t*(**)(void))(*(int*)piVar2 + 4))(); goto joined; }
            if (puVar3 == (uint32_t*)&DAT_00727560) break;
            puVar3 = (uint32_t*)puVar3[1];
        }
        if (piVar2[0x30] == 0) piVar2 = nullptr;
        else piVar2 = *(int**)piVar2[0x2e];
    }
joined:
    if (puVar3 == nullptr) goto LAB;
    if (puVar3 == (uint32_t*)&DAT_00727448) {
        {
            uint32_t bVar1 = 1;
            uint32_t uVar4 = -(uint32_t)bVar1 & (uint32_t)(intptr_t)piVar2;
            if (uVar4 != 0) { *(int*)(uVar4 + 4) = *(int*)(uVar4 + 4) + 1; FUN_004ae390(uVar4); }
        }
        return;
    }
    puVar3 = (uint32_t*)puVar3[1];
    goto joined;
LAB:
    {
        uint32_t bVar1 = 0;
        uint32_t uVar4 = -(uint32_t)bVar1 & (uint32_t)(intptr_t)piVar2;
        if (uVar4 != 0) { *(int*)(uVar4 + 4) = *(int*)(uVar4 + 4) + 1; FUN_004ae390(uVar4); }
    }
}

// 0x4ae640 — bool (param_1, param_2, param_3): recursive search; copies 0x24..0x26 and 0x1b..0x23.
uint32_t FUN_004ae640(int* param_1, int* param_2, int* param_3) {
    if (param_1 != nullptr) {
        uint32_t* puVar2 = (uint32_t*)(**(uint32_t*(**)(void))(*(int*)param_1 + 4))();
        if (puVar2 == (uint32_t*)&DAT_00727448 && ((*(uint8_t*)((int)param_1 + 8) & 1) == 0)) {
            param_2[0] = param_1[0x24]; param_2[1] = param_1[0x25]; param_2[2] = param_1[0x26];
            int* piVar4 = param_1 + 0x1b;
            int* p3 = param_3;
            for (int iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) { *p3++ = *piVar4++; }
            return 1;
        }
        puVar2 = (uint32_t*)(**(uint32_t*(**)(void))(*(int*)param_1 + 4))();
        if (puVar2 != nullptr) {
            while (puVar2 != (uint32_t*)&DAT_00727560) {
                puVar2 = (uint32_t*)puVar2[1];
                if (puVar2 == nullptr) return 0;
            }
            uint32_t uVar5 = 0;
            if (param_1[0x30] != 0) {
                do {
                    int iVar3 = *(int*)(param_1[0x2e] + uVar5 * 4);
                    if (iVar3 != 0 && FUN_004ae640((int*)iVar3, param_2, param_3) != 0) return 1;
                    uVar5 = uVar5 + 1;
                } while (uVar5 < (uint32_t)param_1[0x30]);
            }
        }
    }
    return 0;
}

// 0x4ae740 — bool (param_1, param_2): lock, call 0x583070, copy 3 dwords from *stack_1c+8.
bool FUN_004ae740(uint32_t param_1, uint32_t param_2) {
    uint32_t* unaff_EBX = nullptr;
    uint32_t* unaff_ESI = nullptr;
    uint32_t* in_stack_ffffffdc = nullptr;
    int* piStack_1c = nullptr;
    FUN_00582f50();
    int iVar3 = 0;
    if (in_stack_ffffffdc != unaff_ESI) {
        if (in_stack_ffffffdc != nullptr && ((int iVar1 = in_stack_ffffffdc[1], in_stack_ffffffdc[1] = iVar1 + -1, iVar1 + -1 == 0))) {
            (**(void(**)(int))in_stack_ffffffdc[0])(1);
        }
        if (unaff_ESI != nullptr) unaff_ESI[1] = unaff_ESI[1] + 1;
    }
    char cVar2 = FUN_00583070(param_1, param_2, 0);
    if (cVar2 != 0 && (iVar3 = *piStack_1c) != 0) {
        unaff_EBX[0] = *(uint32_t*)(iVar3 + 8);
        unaff_EBX[1] = *(uint32_t*)(iVar3 + 0xc);
        unaff_EBX[2] = *(uint32_t*)(iVar3 + 0x10);
    }
    FUN_005831c0();
    return iVar3 != 0;
}

// 0x4ae7d0 — uint8_t (param_1, param_2, param_3, param_4, param_5): float vec + call 0x535b40 + 2x 0x5f0ddc.
uint8_t FUN_004ae7d0(int param_1, int param_2, int param_3, uint32_t* param_4, uint32_t* param_5) {
    float local_c = (float)param_1;
    float local_8 = (float)param_2;
    float local_4 = (float)param_3;
    uint8_t uVar1 = FUN_00535b40(&local_c, &param_2, &param_1);
    *param_4 = FUN_005f0ddc();
    *param_5 = FUN_005f0ddc();
    (void)local_8; (void)local_4;
    return uVar1;
}

// 0x4ae850 — bool (param_1, param_2, param_3): 5x corner test via 0x4ae7d0.
bool FUN_004ae850(int param_1, int param_2, int param_3) {
    // NOTE: pseudocode omits 3 trailing args; preserved as observed call shape.
    char cVar1 = 0;
    cVar1 = FUN_004ae7d0(param_1, param_2, 0, nullptr, nullptr);
    if (cVar1 == 0) {
        cVar1 = FUN_004ae7d0(param_1 + param_3, param_2 + param_3, 0, nullptr, nullptr);
        if (cVar1 == 0) {
            cVar1 = FUN_004ae7d0(param_1 + param_3, param_2 - param_3, 0, nullptr, nullptr);
            if (cVar1 == 0) {
                cVar1 = FUN_004ae7d0(param_1 - param_3, param_2 + param_3, 0, nullptr, nullptr);
                if (cVar1 == 0) {
                    cVar1 = FUN_004ae7d0(param_1 - param_3, param_2 - param_3, 0, nullptr, nullptr);
                    return cVar1 != 0;
                }
            }
        }
    }
    return true;
}

// 0x4ae900 — char (param_1, param_2, param_3, param_4): scaled 0x536ec0, fallback normalize, 2x out.
char FUN_004ae900(int param_1, int param_2, uint32_t* param_3, uint32_t* param_4) {
    float local_30 = 0, local_2c = 0, local_28 = 0, local_24 = 0, local_20 = 0, local_1c = 0, local_18 = 0, local_14 = 0, local_10 = 0, local_c = 0, local_8 = 0, local_4 = 0;
    uint32_t* unaff_EDI = nullptr;
    char cVar2 = FUN_00536ec0((DAT_008cac18 * param_1) / (float)DAT_0072637c, (DAT_008cac1c * param_2) / (float)DAT_00726380, &local_18, &local_30);
    if (cVar2 == 0) return 0;
    if (unaff_EDI == nullptr || FUN_004ae740((uint32_t)(intptr_t)&local_18, (uint32_t)(intptr_t)&local_30) == 0) {
        if (local_28 == 0.0f) local_28 = 0.005f;
        float fVar1 = local_10 / local_28; if (fVar1 < 0) fVar1 = -fVar1;
        local_2c = local_2c * fVar1;
        local_28 = fVar1 * local_28;
        local_24 = local_18 + local_30 * fVar1;
        local_20 = local_14 + local_2c;
        local_1c = local_10 + local_28;
        local_c = local_24; local_8 = local_20; local_4 = local_1c;
    }
    *param_3 = FUN_005f0ddc();
    *param_4 = FUN_005f0ddc();
    if (unaff_EDI != nullptr) *unaff_EDI = FUN_005f0ddc();
    return cVar2;
}

// 0x4aea30 — void (void): checks DAT_008e9fe8 list for DAT_007273fc; creates 0x24 node.
void FUN_004aea30(void) {
    int* piVar1 = (int*)DAT_008e9fe8;
    if (DAT_008e9fe8 != nullptr) {
        uint8_t bVar2 = 0;
        for (uint32_t* puVar3 = (uint32_t*)(**(uint32_t*(**)(void))(*(int*)DAT_008e9fe8 + 4))(); puVar3 != nullptr; puVar3 = (uint32_t*)puVar3[1]) {
            if (puVar3 == (uint32_t*)&DAT_007273fc) { bVar2 = 1; break; }
        }
        uint32_t* puVar3b = (uint32_t*)(-(uint32_t)bVar2 & (uint32_t)(intptr_t)piVar1);
        if (puVar3b != nullptr) {
            puVar3b[1] = puVar3b[1] + 1;
            int iVar4 = FUN_00533db0(10);
            if (iVar4 == 0) {
                uint32_t* puVar5 = (uint32_t*)FUN_00533c78(0x24);
                if (puVar5 == nullptr) puVar5 = nullptr;
                else { FUN_00540c50(); *puVar5 = PTR_FUN_0070c0a8; *(uint16_t*)(puVar5 + 8) = 0; }
                if (puVar5 != nullptr) puVar5[1] = puVar5[1] + 1;
                uint32_t* puStack_4 = puVar5;
                FUN_004aac50(&puStack_4);
                if (puVar5 != nullptr) {
                    int* pi = (int*)puVar5 + 1; *pi = *pi + -1;
                    if (*pi == 0) (**(void(**)(int))puVar5[0])(1);
                }
                *(uint8_t*)(puVar5 + 8) |= 1;
            } else if ((*(uint8_t*)(iVar4 + 0x20) & 1) == 0) {
                *(uint8_t*)(iVar4 + 0x20) &= 0xfe;
            } else {
                *(uint8_t*)(iVar4 + 0x20) |= 1;
            }
            FUN_00534130(); FUN_00534350();
            int* pi2 = (int*)puVar3b + 1; *pi2 = *pi2 + -1;
            if (*pi2 == 0) (**(void(**)(int))puVar3b[0])(1);
        }
    }
}

// 0x4aeb20 — uint32_t (param_1, param_2, param_3, param_4, param_5): string list scan, offset-table lookup.
uint32_t FUN_004aeb20(int param_1, uint32_t param_2, uint32_t param_3, int param_4, int param_5) {
    int* in_EAX = nullptr;
    char* unaff_EBX = nullptr;
    uint32_t local_4 = 0;
    while (true) {
        if (local_4 == 0) {
            if (unaff_EBX != nullptr) {
                char* pcVar4 = unaff_EBX;
                do { char cVar3 = *pcVar4; pcVar4 = pcVar4 + 1; } while (cVar3 != 0);
                size_t _Size = (int)(pcVar4 - unaff_EBX - 1);
                if ((int)_Size >= -1 && (pcVar4 = (char*)(intptr_t)*in_EAX, unaff_EBX != pcVar4)) {
                    if (_Size == 0) {
                        if (*(int*)(pcVar4 - 4) != 0) { *pcVar4 = 0; *(uint32_t*)(*in_EAX - 4) = 0; }
                    } else {
                        FUN_004f3350();
                        memmove((void*)(intptr_t)*in_EAX, unaff_EBX, _Size);
                        *(uint8_t*)(*in_EAX + *(int*)(*in_EAX - 4)) = 0;
                    }
                }
            }
        } else {
            FUN_004f2600("%s,%08x,%d,%d,%d");
        }
        int iVar1 = *in_EAX;
        int iVar5 = (**(int(**)(int))(DAT_00726bb4 + 4))(iVar1);
        uint32_t* puVar2 = *(uint32_t**)(DAT_00726bbc + iVar5 * 4);
        while (true) {
            if (puVar2 == nullptr) return 0;
            char cVar3 = (**(char(**)(int, uint32_t))(DAT_00726bb4 + 8))(iVar1, puVar2[1]);
            if (cVar3 != 0) break;
            puVar2 = (uint32_t*)puVar2[0];
        }
        puVar2 = (uint32_t*)puVar2[2];
        if (puVar2 == nullptr) break;
        if ((*(char*)(puVar2 + 2) == 0) && puVar2[1] == (uint32_t)param_1 && puVar2[3] == (uint32_t)param_4 && *(short*)(puVar2 + 4) == param_5) {
            *(uint8_t*)(puVar2 + 2) = 1;
            return puVar2[0];
        }
        local_4 = local_4 + 1;
    }
    return 0;
}

// 0x4aec30 — void (9 ints): resolve/create node, matrix setup, DAT_0085a11c=100.
void FUN_004aec30(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9) {
    uint32_t in_EAX = 0, in_ECX = 0;
    float local_fc = (float)param_1, local_f8 = (float)param_2, local_f4 = (float)param_3;
    uint8_t* local_f0 = (uint8_t*)&DAT_008cacd0;
    uint32_t local_ec = 0, local_e8 = 0, local_e4 = 0, local_e0 = 0;
    uint32_t* local_dc = nullptr;
    uint8_t local_d8[36] = {0}, local_b4[72] = {0}, local_6c[36] = {0}, local_48[36] = {0}, local_24[36] = {0};
    FUN_004b1260(in_EAX);
    if (param_9 == 0) param_9 = DAT_008c9dd8;
    DAT_008c9ddc = param_9;
    int iVar2 = FUN_004aeb20(param_9, param_1, param_2, param_8, 0);
    if (iVar2 == 0) {
        iVar2 = FUN_00508e20(DAT_008c9ddc, local_fc, local_f8, local_f4, in_ECX, param_8, local_ec, local_e8, local_e4, local_e0);
        int* piVar3 = (int*)FUN_00533c78(0x14);
        *piVar3 = iVar2; piVar3[1] = DAT_008c9ddc; *(uint8_t*)(piVar3 + 2) = 1; piVar3[3] = param_8; *(uint16_t*)(piVar3 + 4) = 0;
        int iVar5 = FUN_00533db0(0xb);
        if (iVar5 == 0) {
            uint32_t* puVar4 = (uint32_t*)FUN_00533c78(0x28);
            if (puVar4 != nullptr) { FUN_00540c50(); *puVar4 = PTR_FUN_0070bed4; *(uint16_t*)(puVar4 + 8) = 3; puVar4[9] = 3; }
            if (puVar4 != nullptr) puVar4[1] = puVar4[1] + 1;
            local_dc = puVar4;
            FUN_004aac50(&local_dc);
            if (puVar4 != nullptr) { int* pi = (int*)puVar4 + 1; *pi = *pi + -1; if (*pi == 0) (**(void(**)(int))puVar4[0])(1); }
            FUN_00534130();
        }
        FUN_00524e90(piVar3);
    } else {
        FUN_0050a3b0(local_ec, local_e8, local_e4, local_e0);
        int iVar5 = *(int*)(iVar2 + 0x34);
        *(float*)(iVar5 + 0x5c) = local_fc; *(float*)(iVar5 + 0x60) = local_f8; *(float*)(iVar5 + 100) = local_f4;
    }
    iVar2 = *(int*)(iVar2 + 0x34);
    if ((DAT_008ee1d0 & 1) == 0) {
        local_fc = -DAT_007177c4; local_f8 = -DAT_007177c8; DAT_008ee1d0 |= 1; local_f4 = -DAT_007177cc;
        FUN_0053c6f0(&DAT_007177ac, &local_fc, &DAT_007177b8);
    }
    FUN_0053c7c0(param_4 * 1.4629181e-09f);
    FUN_0053c740(param_5 * 1.4629181e-09f);
    FUN_0053c780(param_6 * 1.4629181e-09f);
    uint8_t* puVar9 = local_6c; uint8_t* puVar8 = local_d8; uint8_t* puVar7 = local_48;
    *(float*)(iVar2 + 0x68) = ((param_7 * 0x50) / 100) * 0.01f; if (*(float*)(iVar2 + 0x68) < 0) *(float*)(iVar2 + 0x68) = -(*(float*)(iVar2 + 0x68));
    FUN_0053c8d0(local_24, local_b4);
    FUN_0053c8d0(puVar7, puVar8);
    uint32_t* puVar4b = (uint32_t*)FUN_0053c8d0(puVar9, &DAT_008ee1ac);
    uint32_t* puVar6 = (uint32_t*)(iVar2 + 0x38);
    for (int iVar5b = 9; iVar5b != 0; iVar5b = iVar5b + -1) { *puVar6++ = *puVar4b++; }
    int iVar5c = FUN_00533db0(0xb);
    if (iVar5c != 0) *(uint8_t*)(iVar5c + 0x20) |= 3;
    (**(void(**)(int, int))(*(uint32_t**)DAT_008ea004 + 0x70))(iVar2, 1);
    uint32_t* puVar4c = (uint32_t*)(int)((int)local_f8 - 8);
    DAT_0085a11c = 100;
    if (puVar4c != nullptr && puVar4c != (uint32_t*)&DAT_008cacc8) operator_delete__(puVar4c);
    (void)local_f0;
}

// 0x4aef70 — float (param_1): (0x509500 result scaled by DAT_0072637c/DAT_008cac18) * int-scaled 0.01.
float FUN_004aef70(uint32_t param_1) {
    int in_EAX = 0;
    int iVar1 = DAT_008cac18 * DAT_0085a11c;
    if (in_EAX == 0) in_EAX = DAT_008c9dd8;
    DAT_008c9de0 = in_EAX;
    float fVar2 = FUN_00509500(in_EAX, param_1, 0);
    return ((fVar2 * (float)DAT_0072637c) / (float)DAT_008cac18) * (float)((int)(iVar1 + (iVar1 >> 0x1f & 0x3ff)) >> 10) * 0.01f;
}

// 0x4aefd0 — float (void): (0x5096b0 result scaled by DAT_00726380/DAT_008cac1c + 2.0) * scaled 0.01.
float FUN_004aefd0(void) {
    int in_EAX = 0;
    int iVar1 = DAT_008cac18 * DAT_0085a11c;
    if (in_EAX == 0) in_EAX = DAT_008c9dd8;
    DAT_008c9de0 = in_EAX;
    float fVar2 = FUN_005096b0();
    return ((fVar2 * (float)DAT_00726380) / (float)DAT_008cac1c + 2.0f) * (float)((int)(iVar1 + (iVar1 >> 0x1f & 0x3ff)) >> 10) * 0.01f;
}

// 0x4af030 — void (void): uVar1 = 0x4cddf0(); 0x4af080(uVar1).
void FUN_004af030(void) {
    uint32_t uVar1 = FUN_004cddf0(nullptr, 0, 0, nullptr, nullptr);
    FUN_004af080((void*)(intptr_t)uVar1, 0, 0, nullptr, 0, 0, 0, 0, 0, 0, 0);
}

// 0x4af080 — void* (11 args): builds 12-vertex quad buffers, index table, creates geometry node.
void* FUN_004af080(void* param_1, int param_2, int param_3, uint32_t* param_4, int param_5, float param_6, float param_7, int param_8, int param_9, uint32_t param_10, uint32_t param_11) {
    uint32_t local_10 = 0, uStack_c = 0, uStack_8 = 0, local_4 = 0;
    float fVar2 = (float)(int)param_6 - (float)(DAT_0072637c / 2);
    param_6 = (float)(int)param_7 - (float)(DAT_00726380 / 2);
    float fVar3 = (DAT_008cac04 == 0) ? 100.0f : -100.0f;
    param_7 = (float)DAT_008cac00;
    if (DAT_008cac00 < 0) param_7 = param_7 + 4.2949673e+09f;
    param_7 = param_7 / fVar3;
    DAT_008cac00 = DAT_008cac00 + 1;
    FUN_004b1260(param_10);
    float* pfVar5 = (float*)FUN_00533c78(0x30);
    uint32_t* puVar6 = (uint32_t*)FUN_00533c78(0x40);
    if (puVar6 != nullptr) {
        uint32_t* puVar10 = puVar6 + 2;
        int iVar11 = 4;
        do { puVar10[-2] = 0; puVar10[-1] = 0; *puVar10 = 0; puVar10[1] = 0; puVar10 += 4; iVar11--; } while (iVar11 != 0);
    }
    float* pfVar7 = (float*)FUN_00533c78(0x20);
    float fVar3b = -param_7;
    float fVar4 = -param_6;
    pfVar5[0] = fVar2; pfVar5[1] = fVar3b; pfVar5[2] = fVar4 - (float)param_9; pfVar5[3] = (float)param_8 + fVar2;
    pfVar5[4] = fVar3b; pfVar5[5] = fVar4 - (float)param_9; pfVar5[6] = fVar2; pfVar5[7] = fVar3b;
    pfVar5[8] = fVar4; pfVar5[9] = (float)param_8 + fVar2; pfVar5[10] = fVar3b; pfVar5[0xb] = fVar4;
    float fVar2b;
    if (param_1 == nullptr) {
        int iVar11 = 1; param_6 = 1.4013e-45f;
        if ((int)(intptr_t)param_4 > 1) { do { iVar11 *= 2; } while (iVar11 < (int)(intptr_t)param_4); param_6 = (float)iVar11; }
        param_7 = (float)(int)param_6;
        iVar11 = 1; param_6 = 1.4013e-45f;
        if (param_5 > 1) { do { iVar11 *= 2; } while (iVar11 < param_5); param_6 = (float)iVar11; }
        fVar2b = (float)(int)param_6;
    } else {
        param_6 = (float)(**(int(**)(void))(*(int*)param_1 + 0x34))();
        param_7 = (float)(int)param_6; if ((int)param_6 < 0) param_7 += 4.2949673e+09f;
        int iVar11b = (**(int(**)(void))(*(int*)param_1 + 0x38))();
        fVar2b = (float)iVar11b; if (iVar11b < 0) fVar2b += 4.2949673e+09f;
    }
    param_7 = 1.0f / param_7;
    float fVar3c = (float)param_2 * param_7;
    param_6 = (float)param_3 * (1.0f / fVar2b);
    param_4 = (uint32_t*)((float)(int)(intptr_t)param_4 * param_7 + fVar3c);
    fVar2b = (1.0f / fVar2b) * (float)param_5 + param_6;
    pfVar7[0] = fVar3c; pfVar7[1] = fVar2b; pfVar7[3] = fVar2b; pfVar7[2] = (float)(intptr_t)param_4;
    pfVar7[4] = fVar3c; pfVar7[5] = param_6; pfVar7[6] = (float)(intptr_t)param_4; pfVar7[7] = param_6;
    puVar6[0] = local_10; puVar6[1] = uStack_c; puVar6[2] = uStack_8; puVar6[3] = local_4;
    puVar6[4] = local_10; puVar6[5] = uStack_c; puVar6[6] = uStack_8; puVar6[7] = local_4;
    puVar6[8] = local_10; puVar6[9] = uStack_c; puVar6[10] = uStack_8; puVar6[0xb] = local_4;
    puVar6[0xc] = local_10; puVar6[0xd] = uStack_c; puVar6[0xe] = uStack_8; puVar6[0xf] = local_4;
    if ((param_11 & 1) != 0) puVar6[3] = (uint32_t)((float)puVar6[3] * 0.5f);
    if ((param_11 & 2) != 0) puVar6[7] = (uint32_t)((float)puVar6[7] * 0.5f);
    if ((param_11 & 4) != 0) puVar6[0xb] = (uint32_t)((float)puVar6[0xb] * 0.5f);
    if ((param_11 & 8) != 0) puVar6[0xf] = (uint32_t)((float)puVar6[0xf] * 0.5f);
    if ((param_11 & 0x10) != 0) puVar6[3] = 0;
    if ((param_11 & 0x20) != 0) puVar6[7] = 0;
    if ((param_11 & 0x40) != 0) puVar6[0xb] = 0;
    if ((char)param_11 < 0) puVar6[0xf] = 0;
    uint16_t* puVar8 = (uint16_t*)FUN_00533c78(2);
    uint16_t* puVar12 = nullptr;
    if (puVar8 != nullptr) { *puVar8 = 4; puVar12 = puVar8; }
    puVar8 = (uint16_t*)FUN_00533c78(8);
    puVar8[0] = 0; puVar8[1] = 1; puVar8[2] = 2; puVar8[3] = 3;
    int iVar11c = FUN_00533c78(0xcc);
    uint32_t uVar9 = 0;
    if (iVar11c != 0) uVar9 = FUN_005473e0(4, pfVar5, 0, puVar6, pfVar7, 1, 0, 2, 1, puVar12, puVar8);
    if (param_1 != nullptr) {
        int iVar11d = FUN_00533c78(0x48);
        uint32_t* puVar6b = nullptr;
        if (iVar11d != 0) puVar6b = (uint32_t*)FUN_005428c0();
        FUN_004aad70((int*)param_1);
        int iVar11e = *(int*)puVar6b[0xb];
        if (iVar11e == 0) {
            iVar11e = FUN_00533c78(0x1c);
            if (iVar11e != 0) iVar11e = FUN_005426d0();
            param_4 = (uint32_t*)(intptr_t)iVar11e;
            FUN_005606f0(0, &param_4);
        }
        *(uint32_t*)(iVar11e + 0xc) = 1;
        puVar6b[1] = puVar6b[1] + 1;
        param_4 = puVar6b;
        FUN_004aac50(&param_4);
        int* pi = (int*)puVar6b + 1; *pi = *pi + -1;
        if (*pi == 0) (**(void(**)(int))puVar6b[0])(1);
    }
    puVar6 = (uint32_t*)FUN_00533c78(0x2c);
    if (puVar6 != nullptr) { FUN_00540c50(); *puVar6 = PTR_FUN_0070bf10; *(uint16_t*)(puVar6 + 8) = 0; puVar6[9] = 0; puVar6[10] = 1; }
    puVar6[10] = 0; puVar6[9] = 1;
    puVar6[1] = puVar6[1] + 1;
    param_4 = puVar6;
    FUN_004aac50(&param_4);
    { int* pi = (int*)puVar6 + 1; *pi = *pi + -1; if (*pi == 0) (**(void(**)(int))puVar6[0])(1); }
    puVar6 = (uint32_t*)FUN_00533c78(0x24);
    if (puVar6 != nullptr) { FUN_00540c50(); *puVar6 = PTR_FUN_0070bf4c; *(uint16_t*)(puVar6 + 8) = 0xec; *(uint8_t*)((int)puVar6 + 0x22) = 0; }
    *(uint8_t*)((int)puVar6 + 0x22) = 0;
    *(uint16_t*)(puVar6 + 8) = (*(uint16_t*)(puVar6 + 8) & 0xd6ed) | 0x16ed;
    puVar6[1] = puVar6[1] + 1;
    param_4 = puVar6;
    FUN_004aac50(&param_4);
    { int* pi = (int*)puVar6 + 1; *pi = *pi + -1; if (*pi == 0) (**(void(**)(int))puVar6[0])(1); }
    if ((param_11 & 0x200) != 0) { (**(void(**)(uint32_t, int))(*(uint32_t**)DAT_008ea00c + 0x70))(uVar9, 1); return (void*)(intptr_t)uVar9; }
    if (*(int*)(DAT_008ea008 + 0xc0) == 0) { (**(void(**)(uint32_t, int))0x70)(uVar9, 1); return (void*)(intptr_t)uVar9; }
    (**(void(**)(uint32_t, int))(*(int*)**(uint32_t**)(DAT_008ea008 + 0xb8) + 0x70))(uVar9, 1);
    return (void*)(intptr_t)uVar9;
}

// 0x4af5f0 — void (void): sets bit 0x20 at +0x21 based on *unaff_EDI.
void FUN_004af5f0(void) {
    char* unaff_EDI = nullptr;
    int iVar2 = FUN_00533db0(0);
    if (iVar2 == 0) {
        if (*unaff_EDI != 0) {
            uint32_t* puVar3 = (uint32_t*)FUN_00533c78(0x24);
            if (puVar3 != nullptr) { FUN_00540c50(); *puVar3 = PTR_FUN_0070bf4c; *(uint16_t*)(puVar3 + 8) = 0xec; *(uint8_t*)((int)puVar3 + 0x22) = 0; }
            if (*unaff_EDI == 0) *(uint8_t*)((int)puVar3 + 0x21) &= 0xdf;
            else *(uint8_t*)((int)puVar3 + 0x21) |= 0x20;
            puVar3[1] = puVar3[1] + 1;
            uint32_t* local_4 = puVar3;
            FUN_004aac50(&local_4);
            int* pi = (int*)puVar3 + 1; *pi = *pi + -1;
            if (*pi == 0) (**(void(**)(int))puVar3[0])(1);
        }
        return;
    }
    if (*unaff_EDI == 0) { *(uint8_t*)(iVar2 + 0x21) &= 0xdf; return; }
    *(uint8_t*)(iVar2 + 0x21) |= 0x20;
}

// 0x4af680 — int (12 args): alloc 0xc0, init via 0x4baa30, flag 0x40000, PC_rank:0 check.
int FUN_004af680(uint32_t* param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7, uint32_t param_8, uint32_t param_9, uint32_t param_10, uint32_t param_11, uint32_t param_12) {
    int iVar1 = FUN_00533c78(0xc0);
    if (iVar1 != 0) iVar1 = FUN_004baa30(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_9, param_10, param_11, param_12);
    else iVar1 = 0;
    if ((*(uint32_t*)(iVar1 + 0x20) & 1) == 0) {
        if (*(int*)(iVar1 + 0x1c) != 0) FUN_004b0a90(*(int*)(iVar1 + 0x1c), 1);
    } else {
        *(uint32_t*)(iVar1 + 0x20) |= 0x40000;
    }
    int* piVar2 = (int*)FUN_004baaa0();
    int iVar3 = (**(int(**)(const char*))(*(int*)piVar2 + 0x40))("PC_rank:0");
    if (iVar3 == 0) FUN_004bd520();
    FUN_004baaa0();
    FUN_004afd20();
    if (param_1 != nullptr) {
        int* pi = (int*)param_1 + 1; *pi = *pi + -1;
        if (*pi == 0) (**(void(**)(int))param_1[0])(1);
    }
    return iVar1;
}
