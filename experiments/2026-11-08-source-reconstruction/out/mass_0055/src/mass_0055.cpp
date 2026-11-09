#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cstdlib>
#include <cmath>

extern void FUN_00412cb0();
typedef void (*JumpFn_004d93f0)();
extern JumpFn_004d93f0 PTR_LAB_004d948c[];
extern uint8_t DAT_004d94ab[];

extern void FUN_00500ce0(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4);
extern int FUN_00533c78(uint32_t size);
extern uint32_t* FUN_0053bb30(uint32_t param);
extern void FUN_00549540();
extern void FUN_00535670(uint32_t* ptr);
extern void FUN_004d9850(int self);
extern void FUN_00535920(uint32_t* ptr);
extern void FUN_00500ea0();
extern void FUN_00500f70(uint32_t retaddr);
extern void FUN_004cce40();
extern void FUN_00533d10(int a, int b);
extern void FUN_004ff6b0(int a);

extern void* PTR_FUN_0070efd8;

// 0x4d93f0 — observed shape
void FUN_004d93f0(uint8_t in_CL) {
    int iVar1 = 1 << (in_CL & 0x1f);
    if ((uint32_t)(iVar1 - 1U) < 0x40) {
        uint8_t idx = DAT_004d94ab[iVar1];
        PTR_LAB_004d948c[idx]();
        return;
    }
    FUN_00412cb0();
    return;
}

// 0x4d94f0 — observed shape
void FUN_004d94f0(int self, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4) {
    // in_EAX == self, in_EDX is an observed register input threaded into the first call.
    extern uint32_t in_EDX_reg;
    FUN_00500ce0(param_1, in_EDX_reg, param_2, param_4);
    *reinterpret_cast<uint32_t*>(self + 0x1c) = 0;
    *reinterpret_cast<uint32_t*>(self + 0x20) = 0;
    *reinterpret_cast<uint32_t*>(self + 0x18) = 0x47c35000;
    int iVar4 = FUN_00533c78(0xec);
    uint32_t* puVar5;
    if (iVar4 == 0) {
        puVar5 = (uint32_t*)0;
    } else {
        puVar5 = (uint32_t*)FUN_0053bb30(0);
    }
    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(self + 0x1c);
    if (puVar2 != puVar5) {
        if (puVar2 != (uint32_t*)0) {
            int* piVar3 = reinterpret_cast<int*>(puVar2 + 1);
            *piVar3 = *piVar3 - 1;
            if (*piVar3 == 0) {
                (**(void(**)(int))*)puVar2)(1);
            }
        }
        *reinterpret_cast<uint32_t**>(self + 0x1c) = puVar5;
        if (puVar5 != (uint32_t*)0) {
            puVar5[1] = puVar5[1] + 1;
        }
    }
    puVar5 = (uint32_t*)FUN_00533c78(0x11c);
    if (puVar5 != (uint32_t*)0) {
        FUN_00549540();
        *puVar5 = reinterpret_cast<uint32_t>(&PTR_FUN_0070efd8);
        puVar5[0x44] = 0;
        puVar5[0x45] = 0x3f800000;
        puVar5[0x46] = 0;
    }
    puVar2 = *reinterpret_cast<uint32_t**>(self + 0x20);
    if (puVar2 != puVar5) {
        if (puVar2 != (uint32_t*)0) {
            int* piVar3 = reinterpret_cast<int*>(puVar2 + 1);
            *piVar3 = *piVar3 - 1;
            if (*piVar3 == 0) {
                (**(void(**)(int))*)puVar2)(1);
            }
        }
        *reinterpret_cast<uint32_t**>(self + 0x20) = puVar5;
        if (puVar5 != (uint32_t*)0) {
            puVar5[1] = puVar5[1] + 1;
        }
    }
    iVar4 = *reinterpret_cast<int*>(self + 0x20);
    *reinterpret_cast<uint32_t*>(iVar4 + 0x110) = 0x3f800000;
    *reinterpret_cast<int*>(iVar4 + 0xc0) = *reinterpret_cast<int*>(iVar4 + 0xc0) + 1;
    iVar4 = *reinterpret_cast<int*>(self + 0x20);
    *reinterpret_cast<uint32_t*>(iVar4 + 0x114) = 0;
    *reinterpret_cast<int*>(iVar4 + 0xc0) = *reinterpret_cast<int*>(iVar4 + 0xc0) + 1;
    FUN_00535670(*reinterpret_cast<uint32_t**>(self + 0x1c));
    FUN_004d9850(self);
    int* piVar3 = *reinterpret_cast<int**>(*reinterpret_cast<int*>(self + 0x14) + 0x44);
    if (piVar3 != (int*)0) {
        piVar3[1] = piVar3[1] + 1;
    }
    typedef void (*Call70)(uint32_t*, int);
    (**(Call70**)(*piVar3 + 0x70))(*reinterpret_cast<uint32_t**>(self + 0x1c), 1);
    int* piVar1 = piVar3 + 1;
    *piVar1 = *piVar1 - 1;
    if (*piVar1 == 0) {
        (**(void(**)(int))*)piVar3)(1);
    }
    *reinterpret_cast<uint32_t*>(self + 0x24) = 0;
    return;
}

// 0x4d9630 — observed shape
void FUN_004d9630(int self) {
    FUN_00535920(*reinterpret_cast<uint32_t**>(self + 0x1c));
    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(self + 0x20);
    if (puVar2 != (uint32_t*)0) {
        int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) {
            (**(void(**)(int))*)puVar2)(1);
        }
        *reinterpret_cast<uint32_t*>(self + 0x20) = 0;
    }
    puVar2 = *reinterpret_cast<uint32_t**>(self + 0x1c);
    if (puVar2 != (uint32_t*)0) {
        int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) {
            (**(void(**)(int))*)puVar2)(1);
        }
        *reinterpret_cast<uint32_t*>(self + 0x1c) = 0;
    }
    puVar2 = *reinterpret_cast<uint32_t**>(self + 0x20);
    if (puVar2 != (uint32_t*)0) {
        int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) {
            (**(void(**)(int))*)puVar2)(1);
        }
    }
    puVar2 = *reinterpret_cast<uint32_t**>(self + 0x1c);
    if (puVar2 != (uint32_t*)0) {
        int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) {
            (**(void(**)(int))*)puVar2)(1);
        }
    }
    FUN_00500ea0();
    return;
}

// NEEDS_MANUAL: unaff_EDI and unaff_retaddr are unaffiliated registers in the listing; the released object and the FUN_00500f70 argument are not statically identified.
// 0x4d96a0 — observed shape
void FUN_004d96a0(int self, uint32_t* unaff_EDI, uint32_t unaff_retaddr) {
    int* piVar2 = *reinterpret_cast<int**>(*reinterpret_cast<int*>(self + 0x14) + 0x44);
    if (piVar2 != (int*)0) {
        piVar2[1] = piVar2[1] + 1;
    }
    uint8_t local_4[4] = {0};
    typedef void (*Call74)(void*, uint32_t*);
    (**(Call74**)(*piVar2 + 0x74))(local_4, *reinterpret_cast<uint32_t**>(self + 0x1c));
    if ((unaff_EDI != (uint32_t*)0)) {
        int iVar3 = static_cast<int>(unaff_EDI[1]);
        unaff_EDI[1] = static_cast<uint32_t>(iVar3 - 1);
        if (iVar3 - 1 == 0) {
            (**(void(**)(int))*)unaff_EDI)(1);
        }
    }
    int* piVar1 = piVar2 + 1;
    *piVar1 = *piVar1 - 1;
    if (*piVar1 == 0) {
        (**(void(**)(int))*)piVar2)(1);
    }
    FUN_00500f70(unaff_retaddr);
    piVar2 = *reinterpret_cast<int**>(*reinterpret_cast<int*>(self + 0x14) + 0x44);
    if (piVar2 != (int*)0) {
        piVar2[1] = piVar2[1] + 1;
    }
    typedef void (*Call70)(uint32_t*, int);
    (**(Call70**)(*piVar2 + 0x70))(*reinterpret_cast<uint32_t**>(self + 0x1c), 1);
    piVar1 = piVar2 + 1;
    *piVar1 = *piVar1 - 1;
    if (*piVar1 == 0) {
        (**(void(**)(int))*)piVar2)(1);
    }
    return;
}

// 0x4d9730 — observed shape
void FUN_004d9730(int* param_1) {
    int iVar6 = param_1[6];
    uint32_t* puVar7 = reinterpret_cast<uint32_t*>(param_1[1] + 0x128);
    uint32_t local_1c[5];
    uint32_t* puVar8 = local_1c;
    for (int iVar5 = 7; iVar5 != 0; iVar5 = iVar5 - 1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
    }
    int local_8 = iVar6;
    (void)local_8;
    FUN_004cce40();
    float fVar2 = *reinterpret_cast<float*>(param_1[1] + 0x13c);
    uint32_t* puVar7b = *reinterpret_cast<uint32_t**>(param_1[5] + 0x44);
    float fVar3 = static_cast<float>(param_1[2]);
    if (puVar7b != (uint32_t*)0) {
        puVar7b[1] = puVar7b[1] + 1;
    }
    puVar7b[0x1a] = static_cast<uint32_t>(std::fabs(fVar2 * fVar3));
    int* piVar1 = reinterpret_cast<int*>(puVar7b + 1);
    *piVar1 = *piVar1 - 1;
    if (*piVar1 == 0) {
        (**(void(**)(int))*)puVar7b)(1);
    }
    puVar7b = *reinterpret_cast<uint32_t**>(param_1[5] + 0x44);
    if (puVar7b != (uint32_t*)0) {
        puVar7b[1] = puVar7b[1] + 1;
    }
    FUN_00533d10(0, 1);
    if (puVar7b != (uint32_t*)0) {
        int* piVar1b = reinterpret_cast<int*>(puVar7b + 1);
        *piVar1b = *piVar1b - 1;
        if (*piVar1b == 0) {
            (**(void(**)(int))*)puVar7b)(1);
        }
    }
    uint32_t* puVar7c = reinterpret_cast<uint32_t*>(param_1[1] + 0x6c);
    uint32_t* puVar8b = reinterpret_cast<uint32_t*>(*param_1 + 0x38);
    for (int iVar6b = 9; iVar6b != 0; iVar6b = iVar6b - 1) {
        *puVar8b = *puVar7c;
        puVar7c = puVar7c + 1;
        puVar8b = puVar8b + 1;
    }
    if (static_cast<char>(param_1[4]) == '\0') {
        uint32_t uVar4 = *reinterpret_cast<uint32_t*>(param_1[1] + 100);
        int iVar6c = *param_1;
        *reinterpret_cast<uint32_t*>(iVar6c + 0x5c) = 0;
        *reinterpret_cast<uint32_t*>(iVar6c + 0x60) = 0;
        *reinterpret_cast<uint32_t*>(iVar6c + 100) = uVar4;
    } else {
        int iVar6d = param_1[3];
        int iVar5b = *param_1;
        *reinterpret_cast<uint32_t*>(iVar5b + 0x5c) = 0;
        *reinterpret_cast<uint32_t*>(iVar5b + 0x60) = 0;
        *reinterpret_cast<int*>(iVar5b + 100) = iVar6d;
    }
    FUN_004ff6b0(0);
    (**(void(**)())(*reinterpret_cast<int*>(*param_1) + 0x70))();
    return;
}

// 0x4d9850 — observed shape
extern int FUN_00500600();
extern void FUN_004f2600(void* a, int b);
extern void FUN_00540460(void* a);
extern uint32_t* FUN_00538680();
extern void FUN_00534350();
extern void FUN_00534130();
extern uint32_t* FUN_0053c8d0(void* a, void* b);
extern void FUN_0053c7c0(float a);
extern void FUN_0053c740(float a);
extern void FUN_0053c780(float a);
extern void* DAT_0070f04c;
extern void* DAT_008cacd0;
extern int unaff_ESI_004d9850;
// NEEDS_MANUAL: unaff_ESI and iStack_4 are unaffiliated registers/stack slots in the listing; the loop increment target and callback base are not statically identified.
void FUN_004d9850(int iStack_4) {
    int iVar1 = FUN_00500600();
    if (iVar1 != 0) *reinterpret_cast<int*>(iVar1 + 4) = *reinterpret_cast<int*>(iVar1 + 4) + 1;
    iVar1 = FUN_00500600();
    if (iVar1 != 0) *reinterpret_cast<int*>(iVar1 + 4) = *reinterpret_cast<int*>(iVar1 + 4) + 1;
    iVar1 = FUN_00500600();
    if (iVar1 != 0) *reinterpret_cast<int*>(iVar1 + 4) = *reinterpret_cast<int*>(iVar1 + 4) + 1;
    iVar1 = FUN_00500600();
    if (iVar1 != 0) *reinterpret_cast<int*>(iVar1 + 4) = *reinterpret_cast<int*>(iVar1 + 4) + 1;
    iVar1 = FUN_00500600();
    if (iVar1 != 0) *reinterpret_cast<int*>(iVar1 + 4) = *reinterpret_cast<int*>(iVar1 + 4) + 1;
    int local_84[22] = {0};
    int local_98 = 0;
    uint32_t auStack_2c[10] = {0};
    local_84[4] = 0x3f800000; local_84[1] = 0; local_84[2] = 0x3f800000; local_84[3] = 0;
    do {
        iVar1 = FUN_00533c78(0xec);
        int* piVar2;
        if (iVar1 == 0) piVar2 = (int*)0;
        else { piVar2 = reinterpret_cast<int*>(FUN_0053bb30(0)); if (piVar2 != (int*)0) piVar2[1] = piVar2[1] + 1; }
        iVar1 = rand();
        FUN_004f2600(&DAT_0070f04c, -(iVar1 % 0x5dc));
        FUN_00540460(&DAT_008cacd0);
        rand();
        uint32_t* puVar3 = FUN_00538680();
        if (puVar3 != (uint32_t*)0) puVar3[1] = puVar3[1] + 1;
        puVar3[0x17] = local_84[1]; puVar3[0x18] = local_84[2]; puVar3[0x1a] = local_84[4]; puVar3[0x19] = local_84[3];
        typedef void (*Call70a)(uint32_t*, int);
        (**(Call70a**)(*piVar2 + 0x70))(puVar3, 1);
        FUN_0053c7c0((float)unaff_ESI_004d9850 * 0.017453292f);
        iVar1 = rand();
        local_84[3] = -(iVar1 % 10);
        FUN_0053c740((float)local_84[3] * 0.017453292f);
        int* piVar4 = reinterpret_cast<int*>(FUN_0053c8d0(auStack_2c, local_84 + 4));
        int* piVar5 = piVar2 + 0xe;
        for (int i = 9; i != 0; i = i - 1) { *piVar5 = *piVar4; piVar4 = piVar4 + 1; piVar5 = piVar5 + 1; }
        (**(Call70a**)(*reinterpret_cast<int*>(iStack_4 + 0x1c) + 0x70))(piVar2, 1);
        iVar1 = rand();
        local_98 = local_98 + 10 + iVar1 % 5;
        int iTemp = static_cast<int>(puVar3[1]);
        puVar3[1] = static_cast<uint32_t>(iTemp - 1);
        if (iTemp - 1 == 0) (**(void(**)(int))*)puVar3)(1);
        int* piVar4b = piVar2 + 1;
        *piVar4b = *piVar4b - 1;
        if (*piVar4b == 0) (**(void(**)(int))*)piVar2)(1);
    } while (local_98 < 0x168);
    FUN_00534350(); FUN_00534130(); FUN_00533d10(0, 1);
    int* piVar2b = local_84 + 1;
    for (int iVar1b = 5; iVar1b != 0; iVar1b = iVar1b - 1) {
        uint32_t* puVar3 = reinterpret_cast<uint32_t*>(piVar2b[-1]);
        piVar2b = piVar2b - 1;
        if (puVar3 != (uint32_t*)0) { int* piVar4 = reinterpret_cast<int*>(puVar3 + 1); *piVar4 = *piVar4 - 1; if (*piVar4 == 0) (**(void(**)(int))*)puVar3)(1); }
    }
    (void)iStack_4;
    return;
}

// 0x4d9af0 — observed shape
extern double atof_c(const char* s);
extern void FUN_0053c7c0_2(float a);
void FUN_004d9af0(int param_1, float param_2) {
    float fVar4 = param_2 + *reinterpret_cast<float*>(param_1 + 0x24);
    *reinterpret_cast<float*>(param_1 + 0x24) = fVar4;
    if (fVar4 <= 0.033333335f) return;
    uint32_t uVar7 = 0;
    *reinterpret_cast<float*>(param_1 + 0x24) = fVar4 - 0.033333335f;
    uint32_t uVar2 = *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(param_1 + 0x1c) + 0xc0);
    if (uVar2 != 0) {
        do {
            if ((uVar7 < *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(param_1 + 0x1c) + 0xc0)) &&
                ((puVar3 = *reinterpret_cast<uint32_t**>(*reinterpret_cast<int*>(*reinterpret_cast<int*>(param_1 + 0x1c) + 0xb8) + uVar7 * 4), puVar3 != (uint32_t*)0) {
                puVar3[1] = puVar3[1] + 1;
                double dVar9 = atof_c(reinterpret_cast<char*>(puVar3[3]));
                FUN_0053c7c0_2((float)(dVar9 * 0.001 * param_2 * 0.017453292));
                uint8_t local_24[36] = {0};
                uint32_t* puVar5 = reinterpret_cast<uint32_t*>(FUN_0053c8d0(local_24, puVar3 + 0xe));
                uint32_t* puVar8 = puVar3 + 0xe;
                for (int i = 9; i != 0; i = i - 1) { *puVar8 = *puVar5; puVar5 = puVar5 + 1; puVar8 = puVar8 + 1; }
                int* piVar1 = reinterpret_cast<int*>(puVar3 + 1);
                *piVar1 = *piVar1 - 1;
                if (*piVar1 == 0) (**(void(**)(int))*)puVar3)(1);
            }
            uVar7 = uVar7 + 1;
        } while (uVar7 < uVar2);
    }
    return;
}

// 0x4d9bc0 — observed shape
extern void FUN_00549470();
extern void operator_delete(void* p) noexcept;
void FUN_004d9bc0(void* self, uint8_t param_1) {
    FUN_00549470();
    if ((param_1 & 1) != 0) operator_delete(self);
    return;
}

// 0x4d9bf0 — observed shape
extern void FUN_004da1e0(int self);
extern void FUN_004da940(uint32_t* param_1);
extern void FUN_004da6a0(int self);
// NEEDS_MANUAL: unaff_ESI is the unaffiliated receiver in the listing; mapped to an explicit self parameter.
void FUN_004d9bf0(int self, uint32_t* param_1) {
    uint32_t* unaff_ESI = reinterpret_cast<uint32_t*>(self);
    unaff_ESI[0] = 0; unaff_ESI[1] = 0; unaff_ESI[2] = 0; unaff_ESI[0x11] = 0;
    *reinterpret_cast<uint8_t*>(unaff_ESI + 4) = 0;
    unaff_ESI[7] = 0; unaff_ESI[6] = 0; unaff_ESI[5] = 0; unaff_ESI[0xb] = 0; unaff_ESI[10] = 0;
    unaff_ESI[9] = 0; unaff_ESI[0xe] = 0; unaff_ESI[0xd] = 0; unaff_ESI[0xc] = 0; unaff_ESI[0xf] = 0x2d; unaff_ESI[3] = 0;
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(unaff_ESI[0x11]);
    if (puVar2 != (uint32_t*)0) { int* piVar1 = reinterpret_cast<int*>(puVar2 + 1); *piVar1 = *piVar1 - 1; if (*piVar1 == 0) (**(void(**)(int))*)puVar2)(1); unaff_ESI[0x11] = 0; }
    unaff_ESI[0x12] = 0; *reinterpret_cast<uint8_t*>(unaff_ESI + 0x10) = 0;
    FUN_004da1e0(self);
    if (param_1 != (uint32_t*)0) param_1[1] = param_1[1] + 1;
    FUN_004da940(param_1);
    FUN_004da6a0(self);
    if (param_1 != (uint32_t*)0) { int* piVar1 = reinterpret_cast<int*>(param_1 + 1); *piVar1 = *piVar1 - 1; if (*piVar1 == 0) (**(void(**)(int))*)param_1)(1); }
    return;
}

// 0x4d9c80 — observed shape
extern void FUN_004bb980();
// NEEDS_MANUAL: unaff_ESI is the unaffiliated receiver in the listing; mapped to an explicit self parameter.
void FUN_004d9c80(int self) {
    int* unaff_ESI = reinterpret_cast<int*>(self);
    FUN_004bb980();
    if (reinterpret_cast<uint32_t*>(unaff_ESI[3]) != (uint32_t*)0) { (**(void(**)(int))**)unaff_ESI[3])(1); }
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(unaff_ESI[1]);
    if (puVar2 != (uint32_t*)0) { int* piVar1 = reinterpret_cast<int*>(puVar2 + 1); *piVar1 = *piVar1 - 1; if (*piVar1 == 0) (**(void(**)(int))*)puVar2)(1); unaff_ESI[1] = 0; }
    puVar2 = reinterpret_cast<uint32_t*>(*unaff_ESI);
    if (puVar2 != (uint32_t*)0) { int* piVar1 = reinterpret_cast<int*>(puVar2 + 1); *piVar1 = *piVar1 - 1; if (*piVar1 == 0) (**(void(**)(int))*)puVar2)(1); *unaff_ESI = 0; }
    puVar2 = reinterpret_cast<uint32_t*>(unaff_ESI[2]);
    if (puVar2 != (uint32_t*)0) { int* piVar1 = reinterpret_cast<int*>(puVar2 + 1); *piVar1 = *piVar1 - 1; if (*piVar1 == 0) (**(void(**)(int))*)puVar2)(1); unaff_ESI[2] = 0; }
    puVar2 = reinterpret_cast<uint32_t*>(unaff_ESI[0x11]);
    if (puVar2 != (uint32_t*)0) { int* piVar1 = reinterpret_cast<int*>(puVar2 + 1); *piVar1 = *piVar1 - 1; if (*piVar1 == 0) (**(void(**)(int))*)puVar2)(1); unaff_ESI[0x11] = 0; }
    unaff_ESI[0x12] = 0;
    puVar2 = reinterpret_cast<uint32_t*>(unaff_ESI[0x11]);
    if (puVar2 != (uint32_t*)0) { int* piVar1 = reinterpret_cast<int*>(puVar2 + 1); *piVar1 = *piVar1 - 1; if (*piVar1 == 0) (**(void(**)(int))*)puVar2)(1); }
    puVar2 = reinterpret_cast<uint32_t*>(unaff_ESI[2]);
    if (puVar2 != (uint32_t*)0) { int* piVar1 = reinterpret_cast<int*>(puVar2 + 1); *piVar1 = *piVar1 - 1; if (*piVar1 == 0) (**(void(**)(int))*)puVar2)(1); }
    puVar2 = reinterpret_cast<uint32_t*>(unaff_ESI[1]);
    if (puVar2 != (uint32_t*)0) { int* piVar1 = reinterpret_cast<int*>(puVar2 + 1); *piVar1 = *piVar1 - 1; if (*piVar1 == 0) (**(void(**)(int))*)puVar2)(1); }
    puVar2 = reinterpret_cast<uint32_t*>(*unaff_ESI);
    if (puVar2 != (uint32_t*)0) { int* piVar1 = reinterpret_cast<int*>(puVar2 + 1); *piVar1 = *piVar1 - 1; if (*piVar1 == 0) (**(void(**)(int))*)puVar2)(1); }
    return;
}

// 0x4d9d40 — observed shape
extern int DAT_008ed8c0;
extern int DAT_007177b8, DAT_007177c4, DAT_007177ac;
extern int DAT_008cac36;
extern void FUN_0053c6f0(void* a, void* b, void* c);
extern void FUN_0053c780(float a);
extern void FUN_0053c740_2(float a);
extern void FUN_004ff510(float a, uint32_t b);
void FUN_004d9d40(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8) {
    if ((DAT_008ed8c0 & 1) == 0) { DAT_008ed8c0 = DAT_008ed8c0 | 1; FUN_0053c6f0(&DAT_007177b8, &DAT_007177c4, &DAT_007177ac); }
    if ((param_5 != *reinterpret_cast<int*>(param_1 + 0x30)) || (param_6 != *reinterpret_cast<int*>(param_1 + 0x34)) || (param_7 != *reinterpret_cast<int*>(param_1 + 0x38))) {
        FUN_0053c780((float)param_5 * 1.4629181e-09f); FUN_0053c7c0((float)param_6 * 1.4629181e-09f); FUN_0053c740_2((float)param_7 * 1.4629181e-09f);
        int iVar1 = *reinterpret_cast<int*>(param_1 + 4);
        uint8_t local_b4[36] = {0}, local_6c[36] = {0}, local_d8[36] = {0}, local_48[36] = {0}, local_24[36] = {0}, local_90[36] = {0};
        FUN_0053c8d0(local_24, local_90);
        FUN_0053c8d0(local_48, local_d8);
        uint32_t* puVar2 = reinterpret_cast<uint32_t*>(FUN_0053c8d0(local_6c, local_b4));
        uint32_t* puVar4 = reinterpret_cast<uint32_t*>(iVar1 + 0x38);
        for (int i = 9; i != 0; i = i - 1) { *puVar4 = *puVar2; puVar2 = puVar2 + 1; puVar4 = puVar4 + 1; }
        FUN_004ff6b0(0);
        *reinterpret_cast<int*>(param_1 + 0x30) = param_5; *reinterpret_cast<int*>(param_1 + 0x34) = param_6; *reinterpret_cast<int*>(param_1 + 0x38) = param_7;
    }
    if (param_8 != *reinterpret_cast<int*>(param_1 + 0x3c)) {
        uint32_t uVar9 = (DAT_008cac36 == '\0') ? 0x3faaaaab : 0x3fe38e39;
        FUN_004ff510((float)param_8 * 8.381903e-08f, uVar9);
        *reinterpret_cast<int*>(param_1 + 0x3c) = param_8;
    }
    if ((param_2 != *reinterpret_cast<int*>(param_1 + 0x24)) || (param_3 != *reinterpret_cast<int*>(param_1 + 0x28)) || (param_4 != *reinterpret_cast<int*>(param_1 + 0x2c))) {
        int iVar1 = *reinterpret_cast<int*>(param_1 + 4);
        *reinterpret_cast<float*>(iVar1 + 0x5c) = (float)param_2; *reinterpret_cast<float*>(iVar1 + 0x60) = (float)param_3; *reinterpret_cast<float*>(iVar1 + 100) = (float)param_4;
        *reinterpret_cast<int*>(param_1 + 0x24) = param_2; *reinterpret_cast<int*>(param_1 + 0x28) = param_3; *reinterpret_cast<int*>(param_1 + 0x2c) = param_4;
    }
    FUN_004ff6b0(0);
    return;
}

// 0x4d9f50 — observed shape
extern int DAT_0085a26c;
extern int DAT_0085a268;
// NEEDS_MANUAL: in_EAX and in_ECX are register receivers in the listing; in_EAX maps to the added first parameter and in_ECX maps to self. param_1 is a stack param.
void FUN_004d9f50(int in_EAX, int self, int param_1, uint32_t param_2, uint32_t param_3) {
    *reinterpret_cast<int*>(self + 0x14) = in_EAX - DAT_0085a26c / 2;
    int iVar1 = DAT_0085a268;
    *reinterpret_cast<uint32_t*>(self + 0x18) = param_3;
    *reinterpret_cast<int*>(self + 0x1c) = (iVar1 - iVar1 / 2) - param_1;
    *reinterpret_cast<uint8_t*>(self + 0x10) = 1;
    *reinterpret_cast<uint32_t*>(self + 0x20) = param_2;
    return;
}

// 0x4d9f90 — observed shape
extern void FUN_004da810_2(int* param_1);
extern void FUN_004da6a0_2(int* param_1);
extern void FUN_004daa70_2(int* param_1);
extern void FUN_004bbc10(int a, int b, int c, int d, int e, int f, int g, int h, int i);
extern void FUN_004ad820();
extern void FUN_004d1240();
extern void FUN_00535e10();
extern uint32_t* DAT_008e9fd8;
extern uint32_t* DAT_008ea08c;
extern uint32_t DAT_007263bc;
extern int DAT_00726a84;
extern uint32_t DAT_007268f4[];
void FUN_004d9f90(int* param_1) {
    FUN_004bb980();
    if (static_cast<char>(param_1[4]) == '\0') { FUN_004da810_2(param_1); return; }
    if (*param_1 == 0) FUN_004da6a0_2(param_1);
    (**(void(**)(int))(*DAT_008ea08c + 0x40))(*param_1);
    if (static_cast<char>(param_1[0x10]) == '\0') {
        uint32_t* puVar3 = reinterpret_cast<uint32_t*>(param_1[0x11]);
        if (puVar3 != (uint32_t*)0) {
            int* piVar1 = reinterpret_cast<int*>(puVar3 + 1); *piVar1 = *piVar1 - 1; if (*piVar1 == 0) (**(void(**)(int))*)puVar3)(1);
            param_1[0x11] = 0; param_1[0x12] = 0;
        }
        uint32_t* puVar2 = DAT_008e9fd8;
        if (DAT_008e9fd8 != (uint32_t*)0) DAT_008e9fd8[1] = DAT_008e9fd8[1] + 1;
        puVar2 = DAT_008e9fd8;
        uint32_t auStack_20[7] = {0};
        uint32_t* puVar5 = DAT_008e9fd8 + 0x4a; uint32_t* puVar7 = auStack_20;
        for (int i = 7; i != 0; i = i - 1) { *puVar7 = *puVar5; puVar5 = puVar5 + 1; puVar7 = puVar7 + 1; }
        float afStack_34[7] = {0};
        float* pfVar6 = reinterpret_cast<float*>(param_1[1] + 0x128);
        float* pfVar8 = afStack_34 - 2;
        for (int i = 7; i != 0; i = i - 1) { *pfVar8 = *pfVar6; pfVar6 = pfVar6 + 1; pfVar8 = pfVar8 + 1; }
        float fStack_10 = afStack_34[2]; float fStack_c = afStack_34[3];
        if (DAT_008e9fd8 != reinterpret_cast<uint32_t*>(param_1[1])) {
            int iVar4 = static_cast<int>(DAT_008e9fd8[1]); DAT_008e9fd8[1] = static_cast<uint32_t>(iVar4 - 1);
            if (iVar4 - 1 == 0) (**(void(**)(int))*)puVar2)(1);
            DAT_008e9fd8 = reinterpret_cast<uint32_t*>(param_1[1]);
            if (DAT_008e9fd8 != (uint32_t*)0) DAT_008e9fd8[1] = DAT_008e9fd8[1] + 1;
        }
        if ((fStack_10 != afStack_34[2]) || (fStack_c != afStack_34[3])) FUN_004ad820();
        int iVar4 = param_1[1];
        uint32_t* puVar2b = reinterpret_cast<uint32_t*>(puVar3[0x55]);
        uint32_t* puVar5b = *reinterpret_cast<uint32_t**>(iVar4 + 0x154);
        if (puVar5b != puVar2b) {
            if (puVar5b != (uint32_t*)0) { int* piVar1 = reinterpret_cast<int*>(puVar5b + 1); *piVar1 = *piVar1 - 1; if (*piVar1 == 0) (**(void(**)(int))*)puVar5b)(1); }
            *reinterpret_cast<uint32_t**>(iVar4 + 0x154) = puVar2b;
            if (puVar2b != (uint32_t*)0) puVar2b[1] = puVar2b[1] + 1;
        }
        *reinterpret_cast<uint32_t*>(&DAT_007268f4[DAT_00726a84]) = DAT_007263bc;
        DAT_007263bc = DAT_007263bc & 0xfffff05f;
        DAT_00726a84 = DAT_00726a84 + 1;
        FUN_004d1240();
        DAT_00726a84 = DAT_00726a84 - 1;
        DAT_007263bc = DAT_007268f4[DAT_00726a84];
        FUN_00535e10();
        puVar2 = DAT_008e9fd8;
        if (DAT_008e9fd8 != puVar3) {
            if (DAT_008e9fd8 != (uint32_t*)0) { int iVar4b = static_cast<int>(DAT_008e9fd8[1]); DAT_008e9fd8[1] = static_cast<uint32_t>(iVar4b - 1); if (iVar4b - 1 == 0) (**(void(**)(int))*)puVar2)(1); }
            DAT_008e9fd8 = puVar3; puVar3[1] = puVar3[1] + 1;
        }
        if ((fStack_10 != afStack_34[2]) || (fStack_c != afStack_34[3])) FUN_004ad820();
        int* piVar1 = reinterpret_cast<int*>(puVar3 + 1); *piVar1 = *piVar1 - 1; if (*piVar1 == 0) (**(void(**)(int))*)puVar3)(1);
    } else {
        FUN_004daa70_2(param_1);
    }
    (**(void(**)(int))(*DAT_008ea08c + 0x40))(0);
    FUN_004bbc10(param_1[3], param_1[5], param_1[6], param_1[7], 0, 0, 0, static_cast<int>(0xffffffff), 0);
    int iVar4 = param_1[1];
    uint32_t* puVar3 = *reinterpret_cast<uint32_t**>(iVar4 + 0x154);
    if (puVar3 != (uint32_t*)0) { int* piVar1 = reinterpret_cast<int*>(puVar3 + 1); *piVar1 = *piVar1 - 1; if (*piVar1 == 0) (**(void(**)(int))*)puVar3)(1); *reinterpret_cast<uint32_t*>(iVar4 + 0x154) = 0; }
    *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(param_1) + 4) = 0;
    return;
}

// 0x4da1e0 — observed shape
extern void FUN_004bdca0(void* a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
extern void FUN_00540c50();
extern void FUN_004aac50(int* a);
extern void FUN_004282e0(int a);
extern int FUN_004baaa0_2();
extern void* PTR_FUN_006fd14c;
extern void* PTR_FUN_0070e93c;
extern void* PTR_FUN_0070bf4c;
extern void* PTR_FUN_0070bed4;
extern int DAT_00727444;
extern void* DAT_008ea008;
extern void* DAT_00727560;
// NEEDS_MANUAL: unaff_EBP is unaffiliated in the listing; the stored result is also used after the label. Preserved as an explicit parameter.
void FUN_004da1e0(int param_1, uint32_t* unaff_EBP) {
    uint32_t* puVar3 = reinterpret_cast<uint32_t*>(FUN_00533c78(0xc0));
    if (puVar3 != (uint32_t*)0) { puVar3[1] = 0; *puVar3 = reinterpret_cast<uint32_t>(&PTR_FUN_006fd14c); DAT_00727444 = DAT_00727444 + 1; puVar3[7] = 0; puVar3[0x19] = 0; puVar3[0x2f] = 0; }
    *reinterpret_cast<uint32_t**>(param_1 + 0xc) = puVar3;
    FUN_004bdca0(DAT_008ea008, 0, 0, 0, 0, static_cast<int>(0xffffffff), 0, 0, 0, 0);
    int* local_c[3] = {0, 0, 0};
    int* piVar4 = reinterpret_cast<int*>(FUN_00533c78(0x40));
    if (piVar4 != (int*)0) {
        FUN_00540c50(); *piVar4 = reinterpret_cast<int>(&PTR_FUN_0070e93c);
        *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(piVar4) + 32) = 0;
        piVar4[9] = 4; piVar4[10] = 0; piVar4[0xb] = -1; piVar4[0xc] = 0; piVar4[0xd] = 0; piVar4[0xe] = 3; piVar4[0xf] = 0;
    }
    if (piVar4 != (int*)0) piVar4[1] = piVar4[1] + 1;
    *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(piVar4) + 32) = 1;
    piVar4[9] = 2; piVar4[0xe] = 0; piVar4[0xc] = 0; piVar4[0xd] = 0; piVar4[10] = 1;
    int* local_14 = piVar4;
    int* piVar5 = reinterpret_cast<int*>(FUN_004baaa0_2());
    piVar5 = reinterpret_cast<int*>(reinterpret_cast<void(**)(const char*)>(*piVar5 + 0x40)("Rendered"));
    puVar3 = (uint32_t*)0; local_c[0] = piVar5;
    if (piVar5 != (int*)0) {
        piVar5[1] = piVar5[1] + 1;
        uint8_t bVar2 = 0;
        for (uint32_t* puVar6 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint32_t*(*)()>(*piVar5 + 4)()); puVar6 != (uint32_t*)0; puVar6 = reinterpret_cast<uint32_t*>(puVar6[1])) { if (puVar6 == reinterpret_cast<uint32_t*>(&DAT_00727560)) { bVar2 = 1; break; } }
        uint32_t* puVar6b = reinterpret_cast<uint32_t*>(-(int)bVar2 & reinterpret_cast<int>(piVar5));
        if (puVar6b != (uint32_t*)0) { puVar6b[1] = puVar6b[1] + 1; puVar3 = puVar6b; }
    }
    int* piVar8 = (puVar3[0x30] == 0) ? (int*)0 : *reinterpret_cast<int**>(puVar3[0x2e]);
    if (piVar5 != piVar8) {
        if (piVar5 != (int*)0) { int* piVar7 = piVar5 + 1; *piVar7 = *piVar7 - 1; if (*piVar7 == 0) (**(void(**)(int))*)piVar5)(1); }
        piVar5 = piVar8; local_c[0] = piVar8; if (piVar8 != (int*)0) piVar8[1] = piVar8[1] + 1;
    }
    piVar4[1] = piVar4[1] + 1; local_14 = piVar4; FUN_004aac50(&local_14);
    int* piVar8b = piVar4 + 1; *piVar8b = *piVar8b - 1; if (*piVar8b == 0) (**(void(**)(int))*)piVar4)(1);
    piVar8 = reinterpret_cast<int*>(FUN_00533db0(0));
    if (piVar8 != (int*)0) { piVar8[1] = piVar8[1] + 1; FUN_004282e0(reinterpret_cast<int>(piVar5)); }
    piVar5 = reinterpret_cast<int*>(FUN_00533c78(0x40));
    if (piVar5 != (int*)0) {
        FUN_00540c50(); *piVar5 = reinterpret_cast<int>(&PTR_FUN_0070e93c);
        *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(piVar5) + 32) = 0;
        piVar5[9] = 4; piVar5[10] = 0; piVar5[0xb] = -1; piVar5[0xc] = 0; piVar5[0xd] = 0; piVar5[0xe] = 3; piVar5[0xf] = 0;
    }
    int* piStack_18 = piVar5;
    if (piVar4 != piVar5) {
        int* piVar7 = piVar4 + 1; *piVar7 = *piVar7 - 1; if (*piVar7 == 0) (**(void(**)(int))*)piVar4)(1);
        piStack_18 = piVar5; if (piVar5 != (int*)0) piVar5[1] = piVar5[1] + 1;
    }
    *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(piStack_18) + 32) = 1;
    piStack_18[9] = 7; piStack_18[0xc] = 0; piStack_18[0xe] = 2; piStack_18[0xd] = 0; piStack_18[10] = 1;
    piVar4 = reinterpret_cast<int*>(FUN_00533c78(0x24));
    if (piVar4 == (int*)0) local_14 = (int*)0;
    else { FUN_00540c50(); *piVar4 = reinterpret_cast<int>(&PTR_FUN_0070bf4c); *reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(piVar4) + 32) = 0xec; *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(piVar4) + 34) = 0; piVar4[1] = piVar4[1] + 1; local_14 = piVar4; }
    *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(local_14) + 34) = 0x80;
    *reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(local_14) + 32) = static_cast<uint16_t>(*reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(local_14) + 32) & 0xfa03 | 0x3a03);
    piVar4 = reinterpret_cast<int*>(FUN_00533c78(0x28));
    if (piVar4 != (int*)0) { FUN_00540c50(); *reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(piVar4) + 32) = 3; piVar4[9] = 3; *piVar4 = reinterpret_cast<int>(&PTR_FUN_0070bed4); piVar4[1] = piVar4[1] + 1; }
    *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(piVar4) + 32) = static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(piVar4) + 32) & 0xfc);
    piVar5 = reinterpret_cast<int*>(FUN_004baaa0_2());
    piVar5 = reinterpret_cast<int*>(reinterpret_cast<void(**)(const char*)>(*piVar5 + 0x40)("Stencil"));
    int* piVar7c = (int*)0;
    if (piVar5 != (int*)0) {
        piVar5[1] = piVar5[1] + 1;
        uint8_t bVar2 = 0;
        for (uint32_t* puVarX = reinterpret_cast<uint32_t*>(reinterpret_cast<uint32_t*(*)()>(*piVar5 + 4)()); puVarX != (uint32_t*)0; puVarX = reinterpret_cast<uint32_t*>(puVarX[1])) { if (puVarX == reinterpret_cast<uint32_t*>(&DAT_00727560)) { bVar2 = 1; break; } }
        piVar7c = reinterpret_cast<int*>(-(int)bVar2 & reinterpret_cast<int>(piVar5));
    }
    if (local_14 != piVar7c) { int* piVar1 = local_14 + 1; *piVar1 = *piVar1 - 1; if (*piVar1 == 0) (**(void(**)(int))*)local_14)(1); local_14 = piVar7c; if (piVar7c != (int*)0) piVar7c[1] = piVar7c[1] + 1; }
    int* piVar7d = (local_14[0x30] == 0) ? (int*)0 : *reinterpret_cast<int**>(local_14[0x2e]);
    if (piVar5 != piVar7d) {
        if (piVar5 != (int*)0) { int* piVar1 = piVar5 + 1; *piVar1 = *piVar1 - 1; if (*piVar1 == 0) (**(void(**)(int))*)piVar5)(1); }
        piVar5 = piVar7d; if (piVar7d != (int*)0) piVar7d[1] = piVar7d[1] + 1;
    }
    puVar3 = reinterpret_cast<uint32_t*>(FUN_00533db0(0));
    if (unaff_EBP != puVar3) {
        if (unaff_EBP != (uint32_t*)0) { int* piVar7 = reinterpret_cast<int*>(unaff_EBP + 1); *piVar7 = *piVar7 - 1; if (*piVar7 == 0) (**(void(**)(int))*)unaff_EBP)(1); }
        if (puVar3 != (uint32_t*)0) { puVar3[1] = puVar3[1] + 1; unaff_EBP = puVar3; }
    }
    puVar3 = unaff_EBP;
    if (puVar3 != (uint32_t*)0) FUN_004282e0(reinterpret_cast<int>(piVar5));
    piVar8[1] = piVar8[1] + 1; local_c[0] = piVar8; FUN_004aac50(local_c);
    int* piVar7e = piVar8 + 1; *piVar7e = *piVar7e - 1; if (*piVar7e == 0) (**(void(**)(int))*)piVar8)(1);
    piStack_18[1] = piStack_18[1] + 1; local_c[0] = piStack_18; FUN_004aac50(local_c);
    int* piVar7f = piStack_18 + 1; *piVar7f = *piVar7f - 1; if (*piVar7f == 0) (**(void(**)(int))*)piStack_18)(1);
    piVar4[1] = piVar4[1] + 1; local_c[0] = piVar4; FUN_004aac50(local_c);
    int* piVar7g = piVar4 + 1; *piVar7g = *piVar7g - 1; if (*piVar7g == 0) (**(void(**)(int))*)piVar4)(1);
    FUN_004baaa0_2(); FUN_00534130();
    if (piVar5 != (int*)0) { int* piVar7 = piVar5 + 1; *piVar7 = *piVar7 - 1; if (*piVar7 == 0) (**(void(**)(int))*)piVar5)(1); }
    int* piVar5b = piVar4 + 1; *piVar5b = *piVar5b - 1; if (*piVar5b == 0) (**(void(**)(int))*)piVar4)(1);
    piVar4 = piStack_18 + 1; *piVar4 = *piVar4 - 1; if (*piVar4 == 0) (**(void(**)(int))*)piStack_18)(1);
    if (puVar3 != (uint32_t*)0) { piVar4 = reinterpret_cast<int*>(puVar3 + 1); *piVar4 = *piVar4 - 1; if (*piVar4 == 0) (**(void(**)(int))*)puVar3)(1); }
    if (puVar3 != (uint32_t*)0) { /* puStack_10 aliases puVar3 in this listing */ int* piVar4b = reinterpret_cast<int*>(puVar3 + 1); *piVar4b = *piVar4b - 1; if (*piVar4b == 0) (**(void(**)(int))*)puVar3)(1); }
    piVar4 = piVar8 + 1; *piVar4 = *piVar4 - 1; if (*piVar4 == 0) (**(void(**)(int))*)piVar8)(1);
    piVar4 = local_14 + 1; *piVar4 = *piVar4 - 1; if (*piVar4 == 0) (**(void(**)(int))*)local_14)(1);
    return;
}

// 0x4da6a0 — observed shape
extern void* FUN_0054c210(int a, int b, void* c, void* d);
extern void* DAT_008ea08c_2;
extern void* DAT_007179f4;
extern void* DAT_00727c30;
extern void FUN_004aad70(int a);
extern void FUN_00533db0_2(int a);
void FUN_004da6a0(int* param_1) {
    uint32_t* puVar3 = reinterpret_cast<uint32_t*>(FUN_0054c210(0x100, 0x100, DAT_008ea08c_2, &DAT_007179f4));
    uint32_t* puVar5 = reinterpret_cast<uint32_t*>(*param_1);
    bool skipFirst = false;
    if (puVar5 == puVar3) skipFirst = true;
    else {
        if (puVar5 != (uint32_t*)0) { int* piVar4 = reinterpret_cast<int*>(puVar5 + 1); *piVar4 = *piVar4 - 1; if (*piVar4 == 0) (**(void(**)(int))*)puVar5)(1); }
        *param_1 = reinterpret_cast<int>(puVar3);
        if (puVar3 != (uint32_t*)0) { puVar3[1] = puVar3[1] + 1; skipFirst = true; }
    }
    if (!skipFirst) {
        int* piVar4 = (DAT_008ea08c_2 == 0) ? (int*)0 : *reinterpret_cast<int**>(reinterpret_cast<char*>(&DAT_00727c30) + 0x60);
        (**(void(**)(int))(*piVar4 + 0x14))(reinterpret_cast<int>(piVar4));
        puVar3 = reinterpret_cast<uint32_t*>(FUN_0054c210(0x100, 0x100, DAT_008ea08c_2, &DAT_007179f4));
        puVar5 = reinterpret_cast<uint32_t*>(*param_1);
        if (puVar5 != puVar3) {
            if (puVar5 != (uint32_t*)0) { int* piVar4b = reinterpret_cast<int*>(puVar5 + 1); *piVar4b = *piVar4b - 1; if (*piVar4b == 0) (**(void(**)(int))*)puVar5)(1); }
            *param_1 = reinterpret_cast<int>(puVar3);
            if (puVar3 != (uint32_t*)0) puVar3[1] = puVar3[1] + 1;
        }
    }
    int* piVar4 = reinterpret_cast<int*>(FUN_004baaa0());
    piVar4 = reinterpret_cast<int*>(reinterpret_cast<void(**)(const char*)>(*piVar4 + 0x40)("Rendered"));
    puVar5 = (uint32_t*)0;
    if (piVar4 == (int*)0) puVar5 = (uint32_t*)0;
    else {
        piVar4[1] = piVar4[1] + 1;
        uint8_t bVar2 = 0;
        for (uint32_t* p = reinterpret_cast<uint32_t*>(reinterpret_cast<uint32_t*(*)()>(*piVar4 + 4)()); p != (uint32_t*)0; p = reinterpret_cast<uint32_t*>(p[1])) { if (p == reinterpret_cast<uint32_t*>(&DAT_00727560)) { bVar2 = 1; break; } }
        puVar5 = reinterpret_cast<uint32_t*>(-(int)bVar2 & reinterpret_cast<int>(piVar4));
        if (puVar5 != (uint32_t*)0) puVar5[1] = puVar5[1] + 1;
    }
    int* piVar6 = (puVar5[0x30] == 0) ? (int*)0 : *reinterpret_cast<int**>(puVar5[0x2e]);
    if (piVar4 != piVar6) {
        if (piVar4 != (int*)0) { int* piVar1 = piVar4 + 1; *piVar1 = *piVar1 - 1; if (*piVar1 == 0) (**(void(**)(int))*)piVar4)(1); }
        piVar4 = piVar6; if (piVar6 != (int*)0) piVar6[1] = piVar6[1] + 1;
    }
    FUN_00533db0_2(8); FUN_004aad70(*param_1);
    int* piVar6b = reinterpret_cast<int*>(puVar5 + 1); *piVar6b = *piVar6b - 1; if (*piVar6b == 0) (**(void(**)(int))*)puVar5)(1);
    if (piVar4 != (int*)0) { piVar6 = piVar4 + 1; *piVar6 = *piVar6 - 1; if (*piVar6 == 0) (**(void(**)(int))*)piVar4)(1); }
    return;
}

// NEEDS_MANUAL: unaff_retaddr is unaffiliated in the listing; the second released object is not statically identified. Mapped to an explicit self-like parameter.
// 0x4da810 — observed shape
extern int FUN_00533db0_3(int a);
extern int FUN_00533c78_2(uint32_t a);
extern int FUN_005426d0();
extern void FUN_005606f0(int a, void* b);
void FUN_004da810(int* unaff_retaddr) {
    int* piVar4 = reinterpret_cast<int*>(FUN_004baaa0());
    piVar4 = reinterpret_cast<int*>(reinterpret_cast<void(**)(const char*)>(*piVar4 + 0x40)("Rendered"));
    uint32_t* puVar5 = (uint32_t*)0;
    if (piVar4 != (int*)0) {
        piVar4[1] = piVar4[1] + 1;
        uint8_t bVar3 = 0;
        for (uint32_t* p = reinterpret_cast<uint32_t*>(reinterpret_cast<uint32_t*(*)()>(*piVar4 + 4)()); p != (uint32_t*)0; p = reinterpret_cast<uint32_t*>(p[1])) { if (p == reinterpret_cast<uint32_t*>(&DAT_00727560)) { bVar3 = 1; break; } }
        puVar5 = reinterpret_cast<uint32_t*>(-(int)bVar3 & reinterpret_cast<int>(piVar4));
        if (puVar5 != (uint32_t*)0) puVar5[1] = puVar5[1] + 1;
    }
    int* piVar7 = (puVar5[0x30] == 0) ? (int*)0 : *reinterpret_cast<int**>(puVar5[0x2e]);
    if (piVar4 != piVar7) {
        if (piVar4 != (int*)0) { int* piVar1 = piVar4 + 1; *piVar1 = *piVar1 - 1; if (*piVar1 == 0) (**(void(**)(int))*)piVar4)(1); }
        piVar4 = piVar7; if (piVar7 != (int*)0) piVar7[1] = piVar7[1] + 1;
    }
    int iVar6 = FUN_00533db0_3(8);
    iVar6 = **reinterpret_cast<int**>(iVar6 + 0x2c);
    if (iVar6 == 0) {
        iVar6 = FUN_00533c78_2(0x1c);
        if (iVar6 != 0) iVar6 = FUN_005426d0();
        uint8_t auStack_2[2] = {0};
        FUN_005606f0(0, auStack_2 - 6);
    }
    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(iVar6 + 4);
    if (puVar2 != (uint32_t*)0) { int* piVar7b = reinterpret_cast<int*>(puVar2 + 1); *piVar7b = *piVar7b - 1; if (*piVar7b == 0) (**(void(**)(int))*)puVar2)(1); *reinterpret_cast<uint32_t*>(iVar6 + 4) = 0; }
    puVar2 = reinterpret_cast<uint32_t*>(*unaff_retaddr);
    if (puVar2 != (uint32_t*)0) { int* piVar7c = reinterpret_cast<int*>(puVar2 + 1); *piVar7c = *piVar7c - 1; if (*piVar7c == 0) (**(void(**)(int))*)puVar2)(1); *unaff_retaddr = 0; }
    int* piVar7d = reinterpret_cast<int*>(puVar5 + 1); *piVar7d = *piVar7d - 1; if (*piVar7d == 0) (**(void(**)(int))*)puVar5)(1);
    if (piVar4 != (int*)0) { piVar7 = piVar4 + 1; *piVar7 = *piVar7 - 1; if (*piVar7 == 0) (**(void(**)(int))*)piVar4)(1); }
    return;
}

// 0x4da940 — observed shape
extern void FUN_004ff360(uint32_t a);
extern void* PTR_FUN_0070d868;
// NEEDS_MANUAL: unaff_EBX is unaffiliated in the listing; mapped to explicit self parameter.
void FUN_004da940(int self, uint32_t* param_1) {
    int unaff_EBX = self;
    uint32_t* puVar4 = *reinterpret_cast<uint32_t**>(unaff_EBX + 8);
    if (puVar4 != param_1) {
        if (puVar4 != (uint32_t*)0) { int* piVar1 = reinterpret_cast<int*>(puVar4 + 1); *piVar1 = *piVar1 - 1; if (*piVar1 == 0) (**(void(**)(int))*)puVar4)(1); }
        *reinterpret_cast<uint32_t**>(unaff_EBX + 8) = param_1;
        if (param_1 != (uint32_t*)0) param_1[1] = param_1[1] + 1;
    }
    puVar4 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x238));
    if (puVar4 != (uint32_t*)0) { FUN_004ff360(0x42340000); *puVar4 = reinterpret_cast<uint32_t>(&PTR_FUN_0070d868); }
    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(unaff_EBX + 4);
    if (puVar2 != puVar4) {
        if (puVar2 != (uint32_t*)0) { int* piVar1 = reinterpret_cast<int*>(puVar2 + 1); *piVar1 = *piVar1 - 1; if (*piVar1 == 0) (**(void(**)(int))*)puVar2)(1); }
        *reinterpret_cast<uint32_t**>(unaff_EBX + 4) = puVar4;
        if (puVar4 != (uint32_t*)0) puVar4[1] = puVar4[1] + 1;
    }
    uint32_t* puVar2b = DAT_008ea08c;
    int iVar3 = *reinterpret_cast<int*>(unaff_EBX + 4);
    puVar4 = *reinterpret_cast<uint32_t**>(iVar3 + 0x188);
    if (puVar4 != DAT_008ea08c) {
        if (puVar4 != (uint32_t*)0) { int* piVar1 = reinterpret_cast<int*>(puVar4 + 1); *piVar1 = *piVar1 - 1; if (*piVar1 == 0) (**(void(**)(int))*)puVar4)(1); }
        *reinterpret_cast<uint32_t**>(iVar3 + 0x188) = puVar2b;
        if (puVar2b != (uint32_t*)0) puVar2b[1] = puVar2b[1] + 1;
    }
    FUN_004cce40();
    if (param_1 != (uint32_t*)0) { int* piVar1 = reinterpret_cast<int*>(param_1 + 1); *piVar1 = *piVar1 - 1; if (*piVar1 == 0) (**(void(**)(int))*)param_1)(1); }
    return;
}

// 0x4daa10 — observed shape
extern uint32_t* FUN_004bb500(int a);
// NEEDS_MANUAL: unaff_EBX and unaff_ESI are unaffiliated registers in the listing; mapped to explicit parameters (unaff_EBX first, unaff_ESI second).
void FUN_004daa10(int unaff_EBX, int unaff_ESI, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4) {
    if (unaff_EBX != *reinterpret_cast<int*>(unaff_ESI + 0x48)) {
        uint32_t* puVar3 = FUN_004bb500(0);
        uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(unaff_ESI + 0x44);
        if (puVar2 != puVar3) {
            if (puVar2 != (uint32_t*)0) { int* piVar1 = reinterpret_cast<int*>(puVar2 + 1); *piVar1 = *piVar1 - 1; if (*piVar1 == 0) (**(void(**)(int))*)puVar2)(1); }
            *reinterpret_cast<uint32_t**>(unaff_ESI + 0x44) = puVar3;
            if (puVar3 != (uint32_t*)0) puVar3[1] = puVar3[1] + 1;
        }
        *reinterpret_cast<int*>(unaff_ESI + 0x48) = unaff_EBX;
    }
    if (*reinterpret_cast<int*>(unaff_ESI + 0x44) != 0) {
        *reinterpret_cast<uint32_t*>(unaff_ESI + 0x4c) = param_1; *reinterpret_cast<uint32_t*>(unaff_ESI + 0x50) = param_2;
        *reinterpret_cast<uint32_t*>(unaff_ESI + 0x54) = param_3; *reinterpret_cast<uint32_t*>(unaff_ESI + 0x58) = param_4;
        *reinterpret_cast<uint8_t*>(unaff_ESI + 0x40) = 1;
    }
    return;
}

// 0x4daa70 — observed shape
extern uint32_t DAT_00717780, DAT_00717784, DAT_00717788;
extern void FUN_00535670_2(uint32_t a);
extern void FUN_00533d10_2(uint32_t a, uint32_t b);
extern void FUN_00534130_2();
extern void FUN_00534350_2();
extern void FUN_00535de0(int a);
extern void FUN_00535e10_2();
void FUN_004daa70(int param_1) {
    uint32_t* puVar1 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x11c));
    if (puVar1 != (uint32_t*)0) { FUN_00549540(); *puVar1 = reinterpret_cast<uint32_t>(&PTR_FUN_0070efd8); puVar1[0x44] = 0; puVar1[0x45] = 0x3f800000; puVar1[0x46] = 0; }
    puVar1[0x3a] = DAT_00717780; puVar1[0x3b] = DAT_00717784;
    uint32_t uVar2 = DAT_00717788;
    int iVar5 = static_cast<int>(puVar1[0x30]); puVar1[0x30] = static_cast<uint32_t>(iVar5 + 1);
    puVar1[0x3c] = uVar2; puVar1[0x3d] = DAT_00717780; puVar1[0x3e] = DAT_00717784; puVar1[0x3f] = DAT_00717788;
    puVar1[0x30] = static_cast<uint32_t>(iVar5 + 2);
    uint32_t uVar2b = FUN_004baaa0();
    FUN_00535670_2(uVar2b);
    puVar1[0x30] = puVar1[0x30] + 2;
    puVar1[0x44] = 0x3f800000; puVar1[0x45] = 0;
    iVar5 = *reinterpret_cast<int*>(param_1 + 4);
    puVar1[0x17] = *reinterpret_cast<uint32_t*>(iVar5 + 0x90); puVar1[0x18] = *reinterpret_cast<uint32_t*>(iVar5 + 0x94); puVar1[0x19] = *reinterpret_cast<uint32_t*>(iVar5 + 0x98);
    int* piVar3 = reinterpret_cast<int*>(FUN_004baaa0());
    typedef void (*Call70c)(uint32_t*, int);
    (**(Call70c**)(*piVar3 + 0x70))(puVar1, 1);
    FUN_0053c7c0((float)*reinterpret_cast<int*>(param_1 + 0x4c) * 1.4629181e-09f);
    FUN_0053c740((float)*reinterpret_cast<int*>(param_1 + 0x50) * 1.4629181e-09f);
    FUN_0053c780((float)*reinterpret_cast<int*>(param_1 + 0x54) * 1.4629181e-09f);
    iVar5 = *reinterpret_cast<int*>(param_1 + 0x58);
    int iVar4 = FUN_004baaa0();
    *reinterpret_cast<float*>(iVar4 + 0x68) = static_cast<float>(std::fabs(iVar5 * 0.01f));
    uint8_t auStack_bc[72] = {0}, auStack_74[36] = {0}, auStack_50[36] = {0}, auStack_2c[44] = {0};
    FUN_0053c8d0(auStack_2c, auStack_bc);
    puVar1 = reinterpret_cast<uint32_t*>(FUN_0053c8d0(auStack_50, auStack_74));
    iVar5 = FUN_004baaa0();
    uint32_t* puVar6 = reinterpret_cast<uint32_t*>(iVar5 + 0x38);
    for (int i = 9; i != 0; i = i - 1) { *puVar6 = *puVar1; puVar1 = puVar1 + 1; puVar6 = puVar6 + 1; }
    iVar5 = FUN_004baaa0();
    *reinterpret_cast<uint32_t*>(iVar5 + 0x5c) = 0; *reinterpret_cast<uint32_t*>(iVar5 + 0x60) = 0; *reinterpret_cast<uint32_t*>(iVar5 + 100) = 0;
    FUN_004baaa0(); FUN_00534130_2();
    FUN_004baaa0(); FUN_00534350_2();
    FUN_004baaa0(0, 1); FUN_00533d10_2(0, 1);
    uint32_t* puVar6b = DAT_008ea08c;
    iVar5 = *reinterpret_cast<int*>(param_1 + 4);
    puVar1 = *reinterpret_cast<uint32_t**>(iVar5 + 0x188);
    if (puVar1 != DAT_008ea08c) {
        if (puVar1 != (uint32_t*)0) { int* piVar3b = reinterpret_cast<int*>(puVar1 + 1); *piVar3b = *piVar3b - 1; if (*piVar3b == 0) (**(void(**)(int))*)puVar1)(1); }
        *reinterpret_cast<uint32_t**>(iVar5 + 0x188) = puVar6b;
        if (puVar6b != (uint32_t*)0) puVar6b[1] = puVar6b[1] + 1;
    }
    iVar5 = *reinterpret_cast<int*>(param_1 + 4);
    uint32_t* puVar6c = reinterpret_cast<uint32_t*>(FUN_004baaa0());
    puVar1 = *reinterpret_cast<uint32_t**>(iVar5 + 0x154);
    if (puVar1 != puVar6c) {
        if (puVar1 != (uint32_t*)0) { int* piVar3c = reinterpret_cast<int*>(puVar1 + 1); *piVar3c = *piVar3c - 1; if (*piVar3c == 0) (**(void(**)(int))*)puVar1)(1); }
        *reinterpret_cast<uint32_t**>(iVar5 + 0x154) = puVar6c;
        if (puVar6c != (uint32_t*)0) puVar6c[1] = puVar6c[1] + 1;
    }
    FUN_004ff6b0(0);
    FUN_00535de0(7);
    (**(void(**)())(**reinterpret_cast<int**>(param_1 + 4) + 0x70))();
    FUN_00535e10_2();
    *reinterpret_cast<uint8_t*>(param_1 + 0x40) = 0;
    return;
}

// 0x4dad10 — observed shape
extern int strncmp_c(const char* a, const char* b, size_t n);
extern int atoi_c(const char* s);
void FUN_004dad10(int* param_1, char* param_2, size_t param_3, int param_4, int param_5) {
    int iVar1 = strncmp_c(reinterpret_cast<char*>(param_1[3]), param_2, param_3);
    if (iVar1 == 0) {
        iVar1 = atoi_c(reinterpret_cast<char*>(param_1[3] + param_3));
        if ((iVar1 < param_4) || (param_5 < iVar1)) *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(param_1) + 8) = static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(param_1) + 8) | 1);
        else *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(param_1) + 8) = static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(param_1) + 8) & 0xfe);
    }
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint32_t*(*)()>(*param_1 + 4)());
    if (puVar2 != (uint32_t*)0) {
        while (puVar2 != reinterpret_cast<uint32_t*>(&DAT_00727560)) {
            puVar2 = reinterpret_cast<uint32_t*>(puVar2[1]);
            if (puVar2 == (uint32_t*)0) return;
        }
        uint32_t uVar3 = 0;
        if (param_1[0x30] != 0) {
            do {
                int iVar1b = *reinterpret_cast<int*>(param_1[0x2e] + uVar3 * 4);
                if (iVar1b != 0) FUN_004dad10(reinterpret_cast<int*>(iVar1b), param_2, param_3, param_4, param_5);
                uVar3 = uVar3 + 1;
            } while (uVar3 < static_cast<uint32_t>(param_1[0x30]));
        }
    }
    return;
}
