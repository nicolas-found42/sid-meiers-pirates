#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cmath>

extern void* operator_new(std::size_t);
extern void operator_delete(void*);

extern void* FUN_00533c78(std::size_t);
extern void FUN_0057d200(void* self, uint32_t param_1);
extern void FUN_00552c80();
extern void* FUN_005383d0();
extern void FUN_0057bd80(void* param_2, int param_1, uint32_t param_3);
extern void FUN_00552d20();
extern void FUN_005531c0(int param_1);
extern int FUN_00557b10(int param_1);
extern void FUN_006b34a0(int param_1);
extern void FUN_005606f0(uint32_t param_1, int* param_2);
extern void FUN_00553060(uint32_t param_1);
extern void* FUN_00545600();
extern int* FUN_00538580(void** out);
extern int FUN_00538680();
extern void FUN_00552ef0(int param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4);
extern void FUN_00576320(int param_1, uint32_t param_2, uint32_t param_3, int param_4, uint32_t param_5, uint32_t param_6, uint32_t* param_7, uint32_t* param_8);
extern void FUN_0057d460(void* self, uint32_t* param_1, uint32_t param_2, uint32_t param_3);
extern void FUN_005e1490();
extern void FUN_0053cca0();
extern void FUN_005e92a0();
extern void FUN_0057e9e0(void* self);
extern float* FUN_0053ca60(void* out, uint32_t param_2);
extern uint32_t FUN_0053c8d0(void* out, uint32_t param_1);
extern void FUN_0057eb00(void* self, float* param_1, uint32_t* param_2);
extern void FUN_0057a050();
extern char FUN_00579670(uint32_t param_1);
extern void FUN_0057ede0(void* self, uint32_t* param_1);

extern void* PTR_FUN_006c49e0;
extern void* PTR_FUN_006c49a8;
extern void* PTR_FUN_006c4a48;
extern void* PTR_FUN_006c4b20;
extern void* PTR_FUN_006c4bc0;
extern void* PTR_FUN_006c4ba4;
extern void* PTR_FUN_006c4b88;
extern void* PTR_FUN_006c3304;
extern void* PTR_FUN_007115f4;
extern void* PTR_FUN_006c4be0;
extern int DAT_00728a10;
extern int DAT_00728a18;
extern int DAT_00728a20;

// 0x57d3e0 — observed shape
void* FUN_0057d3e0(uint32_t param_1) {
    uint32_t* puVar1 = (uint32_t*)FUN_00533c78(0x74);
    if (puVar1 == nullptr) {
        FUN_0057d200(nullptr, param_1);
        return nullptr;
    }
    FUN_00552c80();
    puVar1[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c49e0;
    puVar1[0x14] = 0;
    puVar1[0x15] = 0;
    puVar1[0x12] = 0;
    puVar1[0x13] = 0;
    puVar1[0x18] = 0;
    puVar1[0x19] = 0;
    puVar1[0x1c] = 1;
    *(uint16_t*)(puVar1 + 0x1a) = 0;
    puVar1[0x1b] = 0;
    puVar1[0x16] = 0;
    puVar1[0x17] = 0xbf800000;
    *(uint16_t*)(puVar1 + 0x11) = 3;
    FUN_0057d200(puVar1, param_1);
    return puVar1;
}

// 0x57d460 — observed shape
void FUN_0057d460(void* self, int param_1, uint32_t* param_2, uint32_t param_3) {
    uint8_t* pSelf = (uint8_t*)self;
    if (*(uint32_t*)(pSelf + 0x4c) == 0) {
        uint32_t* puVar3 = (uint32_t*)FUN_00533c78(0x18);
        if (puVar3 != nullptr) {
            FUN_005383d0();
            puVar3[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c49a8;
            puVar3[3] = 0;
            puVar3[4] = 0;
            puVar3[5] = 0;
        }
        uint32_t* puVar2 = *(uint32_t**)(pSelf + 0x4c);
        if (puVar2 != puVar3) {
            if (puVar2 != nullptr) {
                int* piVar1 = (int*)(puVar2 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    using Fn = void(__cdecl *)(int);
                    Fn fn = (Fn)*(void**)puVar2;
                    fn(1);
                }
            }
            *(uint32_t**)(pSelf + 0x4c) = puVar3;
            if (puVar3 != nullptr) {
                puVar3[1] = puVar3[1] + 1;
            }
        }
    }
    FUN_0057bd80(param_2, param_1, param_3);
    *(uint32_t*)(pSelf + 0x48) = 0;
    *(uint32_t*)(pSelf + 0x18) = *param_2;
    uint32_t idx = (uint32_t)(*(uint8_t*)((uint8_t*)param_2 + 4)) * (uint32_t)(param_1 + -1);
    *(uint32_t*)(pSelf + 0x1c) = *(uint32_t*)((uint8_t*)param_2 + idx);
}

// 0x57d9e0 — observed shape
void FUN_0057d9e0(void* self, uint8_t param_1) {
    uint32_t* pSelf = (uint32_t*)self;
    pSelf[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c4a48;
    uint32_t* puVar2 = (uint32_t*)(uintptr_t)pSelf[0x13];
    if (puVar2 != nullptr) {
        int* piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using Fn = void(__cdecl *)(int);
            Fn fn = (Fn)*(void**)puVar2;
            fn(1);
        }
        pSelf[0x13] = 0;
    }
    puVar2 = (uint32_t*)(uintptr_t)pSelf[0x13];
    if (puVar2 != nullptr) {
        int* piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using Fn = void(__cdecl *)(int);
            Fn fn = (Fn)*(void**)puVar2;
            fn(1);
        }
    }
    FUN_00552d20();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x57dae0 — observed shape
void FUN_0057dae0(int param_1) {
    int iVar2 = param_1;
    FUN_005531c0(param_1);
    param_1 = FUN_00557b10(DAT_00728a10);
    uint32_t uVar1 = *(uint32_t*)((uint8_t*)(uintptr_t)iVar2 + 0xc);
    if (*(uint32_t*)((uint8_t*)(uintptr_t)iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)((uint8_t*)(uintptr_t)iVar2 + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
}

// 0x57e170 — observed shape
void FUN_0057e170(int param_1) {
    int iVar2 = param_1;
    FUN_005531c0(param_1);
    param_1 = FUN_00557b10(DAT_00728a18);
    uint32_t uVar1 = *(uint32_t*)((uint8_t*)(uintptr_t)iVar2 + 0xc);
    if (*(uint32_t*)((uint8_t*)(uintptr_t)iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)((uint8_t*)(uintptr_t)iVar2 + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
}

// 0x57e3f0 — observed shape
void FUN_0057e3f0(void* self, uint32_t param_1) {
    FUN_00553060(param_1);
    uint32_t* puVar3 = (uint32_t*)FUN_00545600();
    uint32_t* puVar2 = *(uint32_t**)((uint8_t*)self + 0x4c);
    if (puVar2 != puVar3) {
        if (puVar2 != nullptr) {
            int* piVar1 = (int*)(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                using Fn = void(__cdecl *)(int);
                Fn fn = (Fn)*(void**)puVar2;
                fn(1);
            }
        }
        *(uint32_t**)((uint8_t*)self + 0x4c) = puVar3;
        if (puVar3 != nullptr) {
            puVar3[1] = puVar3[1] + 1;
        }
    }
}

// 0x57e6a0 — observed shape
int FUN_0057e6a0(uint32_t param_1, uint32_t param_2, uint32_t param_3) {
    uint32_t* local_4 = nullptr;
    int* piVar5 = FUN_00538580((void**)&local_4);
    uint32_t* puVar1 = (uint32_t*)(uintptr_t)*piVar5;
    if (puVar1 != nullptr) {
        puVar1[1] = puVar1[1] + 1;
    }
    if (local_4 != nullptr) {
        int iVar6 = (int)local_4[1];
        local_4[1] = (uint32_t)(iVar6 + -1);
        if (iVar6 + -1 == 0) {
            using Fn = void(__cdecl *)(int);
            Fn fn = (Fn)*(void**)local_4;
            fn(1);
        }
    }
    int iVar6 = FUN_00538680();
    FUN_00552ef0(iVar6, param_1, param_2, param_3);
    uint32_t* puVar2 = *(uint32_t**)((uint8_t*)(uintptr_t)iVar6 + 0x4c);
    if (puVar2 != puVar1) {
        if (puVar2 != nullptr) {
            int* piVar5b = (int*)(puVar2 + 1);
            *piVar5b = *piVar5b + -1;
            if (*piVar5b == 0) {
                using Fn = void(__cdecl *)(int);
                Fn fn = (Fn)*(void**)puVar2;
                fn(1);
            }
        }
        *(uint32_t**)((uint8_t*)(uintptr_t)iVar6 + 0x4c) = puVar1;
        if (puVar1 != nullptr) {
            puVar1[1] = puVar1[1] + 1;
        }
    }
    uint32_t uStack_8 = 0;
    uint32_t uStack_c = 0;
    int iVar3 = *(int*)((uint8_t*)(uintptr_t)iVar6 + 0x4c);
    if (iVar3 != 0) {
        uint32_t uVar4 = *(uint32_t*)((uint8_t*)(uintptr_t)iVar3 + 0x14);
        if (*(int*)((uint8_t*)(uintptr_t)iVar3 + 0xc) != 0) {
            FUN_00576320(1, uVar4, *(uint32_t*)((uint8_t*)(uintptr_t)iVar3 + 0x10), *(int*)((uint8_t*)(uintptr_t)iVar3 + 0xc), param_1, param_2, &uStack_c, &uStack_8);
            FUN_0057d460((void*)(uintptr_t)iVar6, (uint32_t*)(uintptr_t)uStack_8, uStack_c, uVar4);
        }
    }
    if (puVar1 != nullptr) {
        int* piVar5c = (int*)(puVar1 + 1);
        *piVar5c = *piVar5c + -1;
        if (*piVar5c == 0) {
            using Fn = void(__cdecl *)(int);
            Fn fn = (Fn)*(void**)puVar1;
            fn(1);
        }
    }
    return iVar6;
}

// 0x57e880 — observed shape
void FUN_0057e880(void* self, uint8_t param_1) {
    uint32_t* pSelf = (uint32_t*)self;
    pSelf[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c4b20;
    uint32_t* puVar2 = (uint32_t*)(uintptr_t)pSelf[0x13];
    if (puVar2 != nullptr) {
        int* piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using Fn = void(__cdecl *)(int);
            Fn fn = (Fn)*(void**)puVar2;
            fn(1);
        }
    }
    FUN_00552d20();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x57e960 — observed shape
void FUN_0057e960(int param_1) {
    int iVar2 = param_1;
    FUN_005531c0(param_1);
    param_1 = FUN_00557b10(DAT_00728a20);
    uint32_t uVar1 = *(uint32_t*)((uint8_t*)(uintptr_t)iVar2 + 0xc);
    if (*(uint32_t*)((uint8_t*)(uintptr_t)iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)((uint8_t*)(uintptr_t)iVar2 + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
}

// 0x57e9b0 — observed shape
void FUN_0057e9b0(void* self, uint32_t* param_1, uint32_t* param_2) {
    uint32_t* puVar2 = (uint32_t*)((uint8_t*)self + 0x5c);
    for (int iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
        *param_1 = *puVar2;
        puVar2 = puVar2 + 1;
        param_1 = param_1 + 1;
    }
    param_2[0] = *(uint32_t*)((uint8_t*)self + 0x80);
    param_2[1] = *(uint32_t*)((uint8_t*)self + 0x84);
    param_2[2] = *(uint32_t*)((uint8_t*)self + 0x88);
}

// 0x57e9e0 — observed shape
void FUN_0057e9e0(void* self) {
    uint32_t* pSelf = (uint32_t*)self;
    pSelf[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c4bc0;
    if ((*(char*)((uint8_t*)self + 4) != '\0') && ((uint32_t)pSelf[1] != 0)) {
        uint32_t uVar3 = 0;
        do {
            uint32_t* puVar2 = *(uint32_t**)((uint32_t)(uintptr_t)pSelf[2] + uVar3 * 4);
            while (puVar2 != nullptr) {
                uint32_t* puVar1 = puVar2 + 1;
                puVar2 = (uint32_t*)(uintptr_t)*puVar2;
                operator_delete((void*)(uintptr_t)*puVar1);
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < (uint32_t)pSelf[1]);
    }
    pSelf[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c4ba4;
    FUN_005e1490();
    pSelf[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c4b88;
    FUN_005e1490();
    operator_delete((void*)(uintptr_t)pSelf[2]);
}

// 0x57ea60 — observed shape
void FUN_0057ea60(void* self, uint8_t param_1) {
    uint32_t* pSelf = (uint32_t*)self;
    pSelf[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c4b88;
    FUN_005e1490();
    operator_delete((void*)(uintptr_t)pSelf[2]);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x57eaa0 — observed shape
void FUN_0057eaa0(void* self, uint8_t param_1) {
    uint32_t* pSelf = (uint32_t*)self;
    pSelf[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c4ba4;
    FUN_005e1490();
    pSelf[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c4b88;
    FUN_005e1490();
    operator_delete((void*)(uintptr_t)pSelf[2]);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x57eb00 — observed shape
void FUN_0057eb00(void* self, float* param_1, uint32_t* param_2) {
    float* pfVar4 = (float*)((uint8_t*)self + 0x5c);
    for (int iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
        *pfVar4 = *param_1;
        param_1 = param_1 + 1;
        pfVar4 = pfVar4 + 1;
    }
    *(uint32_t*)((uint8_t*)self + 0x80) = param_2[0];
    *(uint32_t*)((uint8_t*)self + 0x84) = param_2[1];
    *(uint32_t*)((uint8_t*)self + 0x88) = param_2[2];
    float fVar1 = *(float*)((uint8_t*)self + 0x5c);
    float fVar2 = *(float*)(*(int*)((uint8_t*)self + 0x34) + 0x68);
    if (((0.01 < fabs((*(float*)((uint8_t*)self + 0x68) * *(float*)((uint8_t*)self + 0x68) +
                fVar1 * fVar1 + *(float*)((uint8_t*)self + 0x74) * *(float*)((uint8_t*)self + 0x74)) - fVar2))
        || (0.01 < fabs((*(float*)((uint8_t*)self + 0x6c) * *(float*)((uint8_t*)self + 0x6c) +
                *(float*)((uint8_t*)self + 0x60) * *(float*)((uint8_t*)self + 0x60) +
                *(float*)((uint8_t*)self + 0x78) * *(float*)((uint8_t*)self + 0x78)) - fVar2))) ||
        (0.01 < fabs((*(float*)((uint8_t*)self + 0x70) * *(float*)((uint8_t*)self + 0x70) +
                *(float*)((uint8_t*)self + 100) * *(float*)((uint8_t*)self + 100) +
                *(float*)((uint8_t*)self + 0x7c) * *(float*)((uint8_t*)self + 0x7c)) - fVar2))) {
        FUN_0053cca0();
    }
}

// 0x57ec00 — observed shape
void FUN_0057ec00(void* self) {
    uint32_t* pSelf = (uint32_t*)self;
    pSelf[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c3304;
    pSelf[2] = 0;
    pSelf[3] = 0;
    pSelf[4] = 0;
    pSelf[1] = 0;
    pSelf[5] = 1;
    pSelf[6] = (uint32_t)(uintptr_t)&PTR_FUN_007115f4;
    pSelf[8] = 0;
    pSelf[0xb] = 1;
    pSelf[9] = 0;
    pSelf[10] = 0;
    pSelf[7] = 0;
    pSelf[0xc] = (uint32_t)(uintptr_t)&PTR_FUN_006c3304;
    pSelf[0xe] = 0;
    pSelf[0x11] = 1;
    pSelf[0xf] = 0;
    pSelf[0x10] = 0;
    pSelf[0xd] = 0;
    pSelf[0x12] = (uint32_t)(uintptr_t)&PTR_FUN_007115f4;
    pSelf[0x14] = 0;
    pSelf[0x17] = 1;
    pSelf[0x15] = 0;
    pSelf[0x16] = 0;
    pSelf[0x13] = 0;
}

// 0x57eca0 — observed shape
void FUN_0057eca0() {
    FUN_005e92a0();
}

// 0x57ed40 — observed shape
void FUN_0057ed40(void* self, uint8_t param_1) {
    uint32_t* pSelf = (uint32_t*)self;
    pSelf[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c4be0;
    FUN_0057e9e0(self);
    FUN_00552d20();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x57ed70 — observed shape
void FUN_0057ed70(void* self, uint32_t param_1, uint32_t param_2) {
    uint8_t local_30[12];
    uint8_t local_24[36];
    float scale[3];
    float* pfVar1 = FUN_0053ca60(local_30, param_2);
    scale[0] = *(float*)((uint8_t*)self + 0x80) + pfVar1[0];
    scale[1] = pfVar1[1] + *(float*)((uint8_t*)self + 0x84);
    scale[2] = pfVar1[2] + *(float*)((uint8_t*)self + 0x88);
    uint32_t uVar2 = FUN_0053c8d0(local_24, param_1);
    FUN_0057eb00(self, (float*)(uintptr_t)uVar2, (uint32_t*)scale);
}

// 0x57ede0 — observed shape
void FUN_0057ede0(void* self, uint32_t* param_1) {
    uint32_t* pSelf = (uint32_t*)self;
    using FnHash = uint32_t*(__cdecl *)(uint32_t*);
    FnHash fnHash = (FnHash)*(void**)((uint32_t)(uintptr_t)pSelf[0] + 4);
    uint32_t* puVar2 = fnHash(param_1);
    int* piVar3 = *(int**)(pSelf[2] + (int)(uintptr_t)puVar2 * 4);
    if (piVar3 != nullptr) {
        do {
            using FnMatch = char(__cdecl *)(uint32_t*, int);
            FnMatch fnMatch = (FnMatch)*(void**)((uint32_t)(uintptr_t)pSelf[0] + 8);
            if (fnMatch(param_1, piVar3[1]) != '\0') {
                using FnThunk = void(__cdecl *)(int*);
                FnThunk fnThunk = (FnThunk)*(void**)((uint32_t)(uintptr_t)pSelf[0] + 0x10);
                fnThunk(piVar3);
                if (puVar2 != nullptr) {
                    puVar2[1] = puVar2[1] + 1;
                }
                using FnInsert = void(__cdecl *)(int*, uint32_t*, uint32_t*);
                FnInsert fnInsert = (FnInsert)*(void**)((uint32_t)(uintptr_t)pSelf[0] + 0xc);
                fnInsert(piVar3, param_1, puVar2);
                goto LAB_0057ee4d;
            }
            piVar3 = (int*)(uintptr_t)*piVar3;
        } while (piVar3 != nullptr);
    }
    {
        using FnNew = uint32_t*(__cdecl *)();
        FnNew fnNew = (FnNew)*(void**)((uint32_t)(uintptr_t)pSelf[0] + 0x14);
        puVar2 = fnNew();
        if (param_1 != nullptr) {
            param_1[1] = param_1[1] + 1;
        }
        using FnInsert = void(__cdecl *)(uint32_t*, uint32_t*, uint32_t*);
        FnInsert fnInsert = (FnInsert)*(void**)((uint32_t)(uintptr_t)pSelf[0] + 0xc);
        fnInsert(puVar2, param_1, param_1);
        uint32_t idx = (uint32_t)(*(int*)(param_1 + 0x8));
        *puVar2 = *(uint32_t*)(pSelf[2] + idx * 4);
        *(uint32_t**)(pSelf[2] + idx * 4) = puVar2;
        pSelf[3] = pSelf[3] + 1;
        puVar2 = param_1;
    }
LAB_0057ee4d:
    if (puVar2 != nullptr) {
        int* piRef = (int*)(puVar2 + 1);
        *piRef = *piRef + -1;
        if (*piRef == 0) {
            using Fn = void(__cdecl *)(int);
            Fn fn = (Fn)*(void**)puVar2;
            fn(1);
        }
    }
}

// 0x57ee90 — observed shape
// NEEDS_MANUAL: receiver in_ECX unread for 0x57ee90; kept as explicit self parameter
uint32_t FUN_0057ee90(void* self, int param_1, char param_2) {
    if ((self != nullptr) && (*(int*)(param_1 + 0x78) != 0)) {
        return 0;
    }
    *(void**)(param_1 + 0x78) = self;
    if (param_2 != '\0') {
        FUN_0057a050();
        uint32_t dep = *(uint32_t*)((uint8_t*)self + 0x34);
        if (FUN_00579670(dep) == '\0') {
            return 0;
        }
    }
    *(int*)(param_1 + 4) = *(int*)(param_1 + 4) + 1;
    FUN_0057ede0(self, *(uint32_t**)(param_1 + 0xc));
    return 1;
}
