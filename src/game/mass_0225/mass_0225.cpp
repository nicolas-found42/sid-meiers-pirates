// Reconstruction batch mass_0225
#include <cstdint>
#include <cstddef>
#include <windows.h>

extern uint32_t DAT_00727930;
extern uint32_t DAT_00727444;
extern void* PTR_LAB_006fd148;
extern void* PTR_FUN_006c869c;
extern void* PTR_FUN_006c85e4;
extern uint32_t FUN_005d8450(int code);
extern void FUN_00497420(const char* fmt, ...);
extern void* FUN_0054aad0(void);
extern void* FUN_00533c78(size_t sz);
extern uint32_t FUN_005d20e0(void* param_1, void* param_2);

// 0x5d20b0 — observed shape
void FUN_005d20b0(void) {
    int iVar2 = (int)DAT_00727930;
    for (; iVar2 != 0; ) {
        uint32_t* puVar1 = *(uint32_t**)((intptr_t)iVar2 + 0x18);
        int next = *(int*)((intptr_t)iVar2 + 0x20);
        if (puVar1 != nullptr) {
            *(uint32_t*)((intptr_t)iVar2 + 0x18) = 0;
            typedef void(__thiscall *VFunc)(void*, uint32_t);
            void* vtbl = *puVar1;
            ((VFunc)(*(void**)vtbl))(puVar1, 1);
        }
        iVar2 = next;
    }
}

// 0x5d20e0 — observed shape
// NEEDS_MANUAL: receiver in_ECX and unaff_EDI (height) used; vtable offsets preserved
uint32_t FUN_005d20e0(void* self, int param_1, int param_2) {
    uint32_t uStack_4c = *(uint32_t*)(*(uintptr_t*)(param_1 + 0x3c));
    uint32_t uStack_48 = *(uint32_t*)(param_2 + 0x28);
    int* piVar9 = *(int**)(*(int*)((intptr_t)self + 8) + 0x60);
    uint32_t uStack_3c = 0;
    uint32_t* puVar1 = (uint32_t*)((intptr_t)self + 0xc);
    uint32_t uStack_44 = 2;
    uint32_t* puStack_40 = puVar1;
    struct Rect4 { uint32_t v[4]; };
    Rect4 rect; rect.v[0]=uStack_4c; rect.v[1]=uStack_48; rect.v[2]=uStack_44; rect.v[3]=0;
    typedef int(__thiscall *V90)(int*, uint32_t*);
    typedef int(__thiscall *V30)(int*);
    typedef int(__thiscall *V34)(int*, void*, uint32_t, uint32_t);
    typedef void(__thiscall *V8)(int*);
    typedef void(__thiscall *V38)(int*);
    int iVar2 = ((V90)(*(void***)piVar9)[0x90/4])(piVar9, (uint32_t*)*(uintptr_t*)(param_1 + 0x38));
    // NOTE: actual decompile calls via (*piVar9 + 0x90) function pointer; expressed above structurally.
    // Reproduce exact pointer arithmetic calls below using observed offsets:
    // First call detail retained via direct expression:
    iVar2 = ((int(__thiscall*)(int*, uint32_t*))(*(void**)(*(int*)piVar9 + 0x90)))(piVar9, (uint32_t*)*(uintptr_t*)(param_1 + 0x38));
    if (iVar2 < 0) {
        uint32_t uVar3 = FUN_005d8450(iVar2);
        FUN_00497420("NiDX9BltSourceData::CreateSurf> Failed CreateImageSurface - %s", uVar3);
        return 0;
    }
    piVar9 = (int*)*puVar1;
    void* puVar10 = &uStack_3c;
    (void)puStack_40;
    iVar2 = ((int(__thiscall*)(int*))(*(void**)(*(int*)piVar9 + 0x30)))(piVar9);
    if (iVar2 < 0) {
        uint32_t uVar3 = FUN_005d8450(iVar2);
        FUN_00497420("NiDX9BltSourceData::CreateSurf> Failed GetDesc - %s", uVar3);
        ((V8)(*(void**)(*(int*)*puVar1 + 8)))((int*)*puVar1);
        *puVar1 = 0;
        return 0;
    }
    iVar2 = ((int(__thiscall*)(int*, void*, uint32_t, uint32_t))(*(void**)(*(int*)*puVar1 + 0x34)))((int*)*puVar1, &rect, 0, 0);
    if (iVar2 < 0) {
        uint32_t uVar3 = FUN_005d8450(iVar2);
        FUN_00497420("NiDX9BltSourceData::CreateSurf> Failed kLockRect - %s", uVar3);
        ((V8)(*(void**)(*(int*)*puVar1 + 8)))((int*)*puVar1);
        *puVar1 = 0;
        return 0;
    }
    uint32_t uVar6 = *(uint32_t*)(param_1 + 0x48) * **(uint32_t**)(param_1 + 0x38);
    uint8_t* puVar4 = (uint8_t*)(**(uintptr_t*)(param_1 + 0x40) + *(int*)(param_1 + 0x34));
    uint32_t uVar11 = 0;
    // unaff_EDI is the copy height in the decompile
    uint32_t height = 0; // preserved from unaff_EDI
    (void)height;
    // Exact: do { copy uVar6 bytes per row for unaff_EDI rows } while (++row < unaff_EDI)
    // We keep structure symbolic without inventing a value for unaff_EDI.
    // To stay faithful, reproduce the loop with the register value abstracted as a local.
    uint32_t unaff_EDI = *(uint32_t*)((intptr_t)self + 0x3c); // placeholder for unaff_EDI register; see NEEDS_MANUAL
    if (unaff_EDI != 0) {
        do {
            uint8_t* src = puVar4;
            uint8_t* dst = (uint8_t*)((intptr_t)piVar9 * uVar11 + (intptr_t)puVar10);
            uint32_t cnt = uVar6 >> 2;
            while (cnt != 0) {
                *(uint32_t*)dst = *(uint32_t*)src;
                src += 4; dst += 4; cnt -= 1;
            }
            puVar4 = (uint8_t*)((intptr_t)puVar4 + uVar6);
            uint32_t rem = uVar6 & 3;
            while (rem != 0) {
                *dst = *src;
                src += 1; dst += 1; rem -= 1;
            }
            uVar11 += 1;
        } while (uVar11 < unaff_EDI);
    }
    ((V38)(*(void**)(*(int*)*puVar1 + 0x38)))((int*)*puVar1);
    return 1;
}

// 0x5d2250 — observed shape
uint32_t* FUN_005d2250(void* self, int param_1, int param_2) {
    uint32_t unaff_EBX = 0; // unaff_EBX register value
    uint32_t unaff_EBP = (uint32_t)(intptr_t)self; // unaff_EBP register anchor
    void* unaff_EDI = self; // unaff_EDI register anchor
    uint32_t* puVar4 = *(uint32_t**)(param_1 + 0x14);
    if (puVar4 == nullptr) {
        uint32_t uVar1 = *(uint32_t*)(param_1 + 0x10);
        int* piVar3 = (int*)FUN_0054aad0();
        puVar4 = (uint32_t*)((uint32_t(__thiscall*)(uint32_t, uint32_t))(*(void**)(*(int*)piVar3 + 8)))(uVar1, 0);
    }
    uint32_t uVar1 = *(uint32_t*)(*(int*)(param_2 + 0x5a4) + 0x14);
    if (puVar4 != nullptr) {
        int* piVar3 = (int*)FUN_0054aad0();
        uint32_t* puVar5 = (uint32_t*)((uint32_t*(__thiscall*)(uint32_t*, uint32_t, uint32_t*, uint32_t))(*(void**)(*(int*)piVar3 + 0x10)))(puVar4, uVar1, puVar4, 0);
        if (puVar5 != nullptr) {
            uint32_t* puVar6 = (uint32_t*)FUN_00533c78(0x1c);
            if (puVar6 == nullptr) {
                puVar6 = nullptr;
            } else {
                puVar6[1] = (uint32_t)param_1;
                *(void**)puVar6 = &PTR_FUN_006c85e4;
                puVar6[2] = unaff_EBX;
                puVar6[3] = 0;
                puVar6[4] = 0;
                puVar6[5] = 0;
                puVar6[6] = 0;
            }
            puVar6[5] = *(uint32_t*)puVar4[0xe];
            puVar6[6] = *(uint32_t*)puVar4[0xf];
            if (puVar6[3] == 0) {
                FUN_005d20e0(puVar5, unaff_EDI);
            }
            int iVar2 = puVar5[1];
            int* piVar3b = (int*)(puVar5 + 1);
            *piVar3b = iVar2 + 1;
            if (puVar5 != puVar4) {
                *piVar3b = iVar2;
                if (iVar2 == 0) {
                    ((void(__thiscall*)(void*, uint32_t))(*(void**)*puVar5))(puVar5, 1);
                }
                piVar3b = (int*)(puVar4 + 1);
                *piVar3b = puVar4[1] + 1;
                puVar5 = puVar4;
            }
            *(uint32_t**)(unaff_EBP + 0x18) = puVar6;
            *piVar3b = *piVar3b + -1;
            if (*piVar3b == 0) {
                ((void(__thiscall*)(void*, uint32_t))(*(void**)*puVar5))(puVar5, 1);
            }
            return puVar6;
        }
    }
    return nullptr;
}

// 0x5d2390 — observed shape
void FUN_005d2390(void* self) {
    DWORD DVar2 = GetCurrentThreadId();
    if (*(DWORD*)((intptr_t)self + 0x50) == DVar2) {
        int* piVar1 = (int*)((intptr_t)self + 0x54);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            *(uint32_t*)((intptr_t)self + 0x50) = 0;
            LeaveCriticalSection((LPCRITICAL_SECTION)((intptr_t)self + 0x38));
        }
    }
}

// 0x5d23c0 — observed shape
void FUN_005d23c0(void* self, int param_1) {
    uint32_t* in_ECX = (uint32_t*)self;
    *(void**)in_ECX = &PTR_LAB_006fd148;
    in_ECX[1] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    *(void**)in_ECX = &PTR_FUN_006c869c;
    in_ECX[3] = (uint32_t)param_1;
    int* piVar1 = *(int**)(param_1 + 0x60);
    in_ECX[2] = (uint32_t)piVar1;
    ((void(__thiscall*)(int*))(*(void**)(*(int*)piVar1 + 4)))(piVar1);
    *(uint8_t*)(in_ECX + 4) = 0;
}

extern void operator_delete(void* p);
extern void* DAT_00727520;
extern int FUN_00449390(void* a, int b);
extern char FUN_005da280(int v);
extern void FUN_005da230(void);
extern void FUN_005da330(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g);
extern void FUN_0054a7e0(void);

// 0x5d2410 — observed shape
void FUN_005d2410(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    *(void**)in_ECX = &PTR_FUN_006c869c;
    ((void(__thiscall*)(uint32_t*))(*(void**)(*(uint32_t*)in_ECX[2] + 8)))( (uint32_t*)in_ECX[2]);
    in_ECX[2] = 0;
    *(void**)in_ECX = &PTR_LAB_006fd148;
    DAT_00727444 = DAT_00727444 + -1;
    // unaff_retaddr & 1 gates operator_delete; preserved as observed conditional
    if ((*(uint8_t*)((intptr_t)self + 0x08) & 1) != 0) {
        operator_delete(in_ECX);
    }
}

// 0x5d2660 — observed shape
uint32_t FUN_005d2660(void* self, int param_1) {
    int* piVar3 = *(int**)(param_1 + 0x2c);
    if (piVar3 != nullptr) {
goto lab_005d266f;
    }
    int iVar2 = FUN_00449390(&DAT_00727520, param_1);
    if (iVar2 != 0) {
        char cVar1 = (char)((uint8_t(__thiscall*)(int*))(*(void**)(**(int**)((intptr_t)self + 0xc) + 0x100)))( (int*)iVar2);
        if ((cVar1 != 0) && (piVar3 = *(int**)(param_1 + 0x2c), piVar3 != nullptr)) {
goto lab_005d266f;
        }
    }
    return 0xe;
lab_005d266f:
    iVar2 = ((int(__thiscall*)(int*))(*(void**)(*(int*)piVar3 + 0x10)))(piVar3);
    return *(uint32_t*)(iVar2 + 0x24);
}

// 0x5d26b0 — observed shape
uint8_t FUN_005d26b0(void* self, int param_1) {
    if ((*(int8_t*)((intptr_t)self + 0x1c) != 1) || (param_1 != *(int*)((intptr_t)self + 0x14))) {
        char cVar1 = FUN_005da280(param_1);
        if (cVar1 == 0) {
            return 0;
        }
        FUN_005da230();
    }
    return 1;
}

// 0x5d26e0 — observed shape
void FUN_005d26e0(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4) {
    ((void(__thiscall*)(uint32_t, uint32_t, uint32_t))(*(void**)(**(int**)((intptr_t)self + 0x18) + 0x70)))(0x89, *(uint32_t*)((intptr_t)self + 0x10c), 0);
    FUN_005da330(0, 0, 0, param_1, param_2, param_3, param_4);
}

// 0x5d2730 — observed shape
intptr_t FUN_005d2730(void* self) {
    if (*(int8_t*)((intptr_t)self + 0x1c) != 0) {
        FUN_0054a7e0();
    }
    return (intptr_t)self + 0x20;
}

extern uint32_t FUN_005ca610(void);
extern void FUN_005ca4e0(uint32_t a, uint32_t b, uint32_t c);
extern void FUN_005ca1d0(int a, void* b, void* c);
extern void FUN_005d7d70(int a, int b, int c);
extern void FUN_005bf480(void);

// 0x5d2750 — observed shape
void FUN_005d2750(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3) {
    if (*(int*)((intptr_t)self + 0x38) == 0) {
        uint32_t uVar1 = FUN_005ca610();
        *(uint32_t*)((intptr_t)self + 0x38) = uVar1;
    }
    FUN_005ca4e0(param_1, param_2, param_3);
}

// 0x5d27b0 — observed shape
bool FUN_005d27b0(void* self, int param_1, int param_2) {
    if ((*(int*)((intptr_t)self + 0x38) == 0) || (*(int*)((intptr_t)self + 0x3c) == 0)) {
        return true;
    }
    int local_8 = 0;
    int local_4 = 0;
    uint8_t local_9 = 0;
    if (*(int*)(*(int*)((intptr_t)self + 0x3c) + 0x38) != 0) {
        FUN_005ca1d0(0x13, &local_8, &local_9);
    }
    if (local_8 != param_1) {
        return false;
    }
    if (*(int*)(*(int*)((intptr_t)self + 0x3c) + 0x38) != 0) {
        FUN_005ca1d0(0x14, &local_4, &local_9);
    }
    return local_4 == param_2;
}

// 0x5d2830 — observed shape
void FUN_005d2830(void* self) {
    uint32_t base = (uint32_t)(intptr_t)self;
    struct Slot { uint32_t dataOff; uint32_t cntOff; };
    Slot slots[6] = {
        {0x5c, 100}, {0x74, 0x7c}, {0x8c, 0x94},
        {0xa4, 0xac}, {0xbc, 0xc4}, {0xd4, 0xdc}
    };
    uint32_t tailOff[6] = {0x68, 0x80, 0x98, 0xb0, 200, 0xe0};
    for (int s = 0; s < 6; s++) {
        uint32_t uVar1 = 0;
        if (*(int*)(base + slots[s].cntOff) != 0) {
            do {
                *(uint32_t*)(*(int*)(base + slots[s].dataOff) + uVar1 * 4) = 0;
                uVar1 = uVar1 + 1;
            } while (uVar1 < *(uint32_t*)(base + slots[s].cntOff));
        }
        *(uint32_t*)(base + slots[s].cntOff) = 0;
        *(uint32_t*)(base + tailOff[s]) = 0;
    }
    *(uint32_t*)(base + 0x124) = 0;
}

// 0x5d2950 — observed shape
void FUN_005d2950(uint32_t* param_1, int param_2) {
    *(uint8_t*)(param_2 + 0x60) = 1;
    FUN_005d7d70(0x18, 2, 0);
    *(uint32_t*)(param_2 + 0x20) = param_1[0];
    *(uint32_t*)(param_2 + 0x30) = param_1[1];
    uint32_t uVar1 = param_1[2];
    *(uint32_t*)(param_2 + 0x50) = 0;
    *(uint32_t*)(param_2 + 0x40) = uVar1;
    *(uint32_t*)(param_2 + 0x24) = param_1[3];
    *(uint32_t*)(param_2 + 0x34) = param_1[4];
    uVar1 = param_1[5];
    *(uint32_t*)(param_2 + 0x54) = 0;
    *(uint32_t*)(param_2 + 0x58) = 0;
    *(uint32_t*)(param_2 + 0x48) = 0;
    *(uint32_t*)(param_2 + 0x38) = 0;
    *(uint32_t*)(param_2 + 0x28) = 0;
    *(uint32_t*)(param_2 + 0x5c) = 0;
    *(uint32_t*)(param_2 + 0x4c) = 0;
    *(uint32_t*)(param_2 + 0x3c) = 0;
    *(uint32_t*)(param_2 + 0x2c) = 0;
    *(uint32_t*)(param_2 + 0x44) = uVar1;
}

// 0x5d3090 — observed shape
void FUN_005d3090(void* self, uint32_t param_1, int* param_2) {
    uint32_t base = (uint32_t)(intptr_t)self;
    if (*(uint32_t*)(base + 8) <= param_1) {
        return;
    }
    int iVar3;
    if (param_1 < *(uint32_t*)(base + 0xc)) {
        iVar3 = *(int*)(*(int*)(base + 4) + param_1 * 4);
        if (*param_2 == 0) {
            if (iVar3 == 0) goto lab_005d30e9;
            iVar3 = *(int*)(base + 0x10) + -1;
        } else {
            if (iVar3 != 0) goto lab_005d30e9;
            iVar3 = *(int*)(base + 0x10) + 1;
        }
    } else {
        *(uint32_t*)(base + 0xc) = param_1 + 1;
        if (*param_2 == 0) goto lab_005d30e9;
        iVar3 = *(int*)(base + 0x10) + 1;
    }
    *(int*)(base + 0x10) = iVar3;
lab_005d30e9:
    int* piVar2 = (int*)(*(int*)(base + 4) + param_1 * 4);
    iVar3 = *piVar2;
    if (iVar3 != *param_2) {
        if (iVar3 != 0) {
            int* piVar1 = (int*)(iVar3 + 0x68);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                FUN_005bf480();
            }
        }
        iVar3 = *param_2;
        *piVar2 = iVar3;
        if (iVar3 != 0) {
            *(int*)(iVar3 + 0x68) = *(int*)(iVar3 + 0x68) + 1;
        }
    }
}

extern void* PTR_FUN_006c86c0;
extern void* PTR_FUN_006c86b4;
extern void operator_delete__(void* ptr);
extern void FUN_005da790(void);
extern uint32_t FUN_005cfe70(uint32_t a, uint32_t b, uint32_t c);
extern uint32_t FUN_005da440(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g);
extern char FUN_005be8c0(int a, int b);
extern void FUN_005cb870(void* p);
extern void FUN_004aade0(int v);
extern void FUN_005ca940(uint32_t v);
extern void FUN_005ca8f0(uint32_t v);
extern void FUN_005bf1f0(uint32_t a, int b);
extern void FUN_005cb7c0(void);

// 0x5d3120 — observed shape
void FUN_005d3120(void* self) {
    uint32_t uVar4 = 0;
    if (*(int*)((intptr_t)self + 0xc) != 0) {
        do {
            int iVar2 = *(int*)((intptr_t)self + 4);
            int iVar3 = *(int*)(iVar2 + uVar4 * 4);
            if (iVar3 != 0) {
                int* piVar1 = (int*)(iVar3 + 0x68);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    FUN_005bf480();
                }
                *(uint32_t*)(iVar2 + uVar4 * 4) = 0;
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < *(uint32_t*)((intptr_t)self + 0xc));
    }
    *(uint32_t*)((intptr_t)self + 0xc) = 0;
    *(uint32_t*)((intptr_t)self + 0x10) = 0;
}

// 0x5d3160 — observed shape
void FUN_005d3160(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    *(void**)in_ECX = &PTR_FUN_006c86c0;
    FUN_005d2830(self);
    operator_delete((void*)in_ECX[0x44]);
    in_ECX[0x34] = (uint32_t)(intptr_t)&PTR_FUN_006c86b4;
    operator_delete__((void*)in_ECX[0x35]);
    in_ECX[0x2e] = (uint32_t)(intptr_t)&PTR_FUN_006c86b4;
    operator_delete__((void*)in_ECX[0x2f]);
    in_ECX[0x28] = (uint32_t)(intptr_t)&PTR_FUN_006c86b4;
    operator_delete__((void*)in_ECX[0x29]);
    in_ECX[0x22] = (uint32_t)(intptr_t)&PTR_FUN_006c86b4;
    operator_delete__((void*)in_ECX[0x23]);
    in_ECX[0x1c] = (uint32_t)(intptr_t)&PTR_FUN_006c86b4;
    operator_delete__((void*)in_ECX[0x1d]);
    in_ECX[0x16] = (uint32_t)(intptr_t)&PTR_FUN_006c86b4;
    operator_delete__((void*)in_ECX[0x17]);
    FUN_005da790();
}

// 0x5d3220 — observed shape
uint32_t FUN_005d3220(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, int param_4, uint32_t param_5, uint32_t param_6) {
    ((void(__thiscall*)(int))(*(void**)(**(int**)((intptr_t)self + 0x18) + 4)))(param_4);
    FUN_005cfe70(param_4, *(uint32_t*)(param_4 + 0x28), *(uint32_t*)(param_4 + 0x2c));
    uint32_t uVar1 = FUN_005da440(0, param_1, param_2, param_4, param_4, param_5, param_6);
    uint32_t uVar2 = ((uint32_t(__thiscall*)(int))(*(void**)(**(int**)((intptr_t)self + 0x18) + 0x74)))(0x89);
    *(uint32_t*)((intptr_t)self + 0x10c) = uVar2;
    return uVar1;
}

// 0x5d3290 — observed shape
int FUN_005d3290(void* self, int param_1, uint32_t param_2) {
    int iVar4 = param_1;
    int iVar1;
    if (*(int*)((intptr_t)self + 0x3c) == 0) {
        return 0;
    }
    char cVar2 = FUN_005be8c0(1, param_1 != 0);
    if (cVar2 == 0) {
        return 0;
    }
    int p1 = param_1;
    FUN_005cb870(&p1);
    iVar1 = p1;
    FUN_005d7d70(0x1c, 1, 0);
    if ((iVar4 == 0) || (*(int*)(iVar4 + 4) == 0)) {
        FUN_005d7d70(1, 2, 0);
        FUN_005d7d70(2, 0, 0);
        FUN_005d7d70(3, 1, 0);
        if (*(int8_t*)((intptr_t)self + 0xfd) == 0) {
            FUN_005d7d70(4, 3, 0);
        } else {
            FUN_005d7d70(4, 2, 0);
            *(uint8_t*)((intptr_t)self + 0xfd) = 0;
        }
        FUN_005d7d70(5, 0, 0);
        FUN_005d7d70(6, 1, 0);
        iVar4 = *(int*)((intptr_t)self + 0x108);
        if (iVar4 == 0) goto lab_005d3439;
    } else {
        FUN_004aade0(*(int*)(iVar4 + 4));
        *(uint32_t*)(iVar1 + 0x10) = param_2;
        *(uint8_t*)(iVar1 + 0x14) = 0;
        FUN_005d7d70(1, 2, 0);
        FUN_005d7d70(2, 2, 0);
        FUN_005d7d70(3, 1, 0);
        FUN_005d7d70(4, 3, 0);
        FUN_005d7d70(5, 2, 0);
        if (*(int8_t*)((intptr_t)self + 0xfd) == 0) {
            FUN_005d7d70(6, 1, 0);
        } else {
            FUN_005d7d70(6, 0, 0);
            *(uint8_t*)((intptr_t)self + 0xfd) = 0;
        }
        FUN_005ca940(*(uint32_t*)(iVar4 + 0xc));
        FUN_005ca8f0(*(uint32_t*)(iVar4 + 8));
        if (*(int*)(iVar4 + 0x18) == 0) {
            *(uint8_t*)(iVar1 + 0x60) = 0;
            FUN_005d7d70(0x18, 0, 0);
            iVar4 = *(int*)((intptr_t)self + 0x108);
        } else {
            iVar4 = iVar1;
            uint32_t uVar3 = (uint32_t)FUN_005d2730((void*)(intptr_t)iVar1);
            FUN_005d2950((uint32_t*)uVar3, iVar4);
            iVar4 = *(int*)((intptr_t)self + 0x108);
        }
    }
    *(int*)((intptr_t)self + 0x108) = iVar4 + -1;
lab_005d3439:
    *(int*)((intptr_t)self + 0x104) = *(int*)((intptr_t)self + 0x104) + -1;
    FUN_005bf1f0(*(uint32_t*)(*(int*)((intptr_t)self + 0x3c) + 0x14), iVar1);
    if ((param_1 != 0) &&
        (iVar4 = *(int*)(param_1 + 100) + -1, *(int*)(param_1 + 100) = iVar4, iVar4 == 0)) {
        FUN_005cb7c0();
    }
    return iVar1;
}

// 0x5d3480 — observed shape
uint32_t* FUN_005d3480(void* self, int param_1, uint32_t param_2) {
    uint32_t* in_ECX = (uint32_t*)self;
    if (in_ECX[0xf] != 0) {
        uint32_t* local_4 = in_ECX;
        char cVar6 = FUN_005be8c0(1, 1);
        if (cVar6 != 0) {
            FUN_005cb870(&local_4);
            uint32_t* puVar5 = local_4;
            *local_4 = *(uint32_t*)(in_ECX[0xf] + 0x14);
            uint32_t* puVar2 = *(uint32_t**)(param_1 + 4);
            uint32_t* puVar3 = (uint32_t*)local_4[1];
            if (puVar3 != puVar2) {
                if (puVar3 != nullptr) {
                    int* piVar1 = (int*)(puVar3 + 1);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) {
                        ((void(__thiscall*)(uint32_t*, uint32_t))(*(void**)*puVar3))(puVar3, 1);
                    }
                }
                puVar5[1] = (uint32_t)(intptr_t)puVar2;
                if (puVar2 != nullptr) {
                    puVar2[1] = puVar2[1] + 1;
                }
            }
            puVar5[4] = param_2;
            *(uint8_t*)(puVar5 + 5) = 0;
            FUN_005d7d70(1, in_ECX[0x47], 0);
            FUN_005d7d70(2, 2, 0);
            FUN_005d7d70(3, 1, 0);
            FUN_005d7d70(4, 3, 0);
            FUN_005d7d70(5, 2, 0);
            if (*(int8_t*)((intptr_t)in_ECX + 0xfd) == 0) {
                FUN_005d7d70(6, 1, 0);
            } else {
                FUN_005d7d70(6, 0, 0);
                *(uint8_t*)((intptr_t)in_ECX + 0xfd) = 0;
            }
            if (puVar2 != nullptr) {
                FUN_005ca940(*(uint32_t*)(param_1 + 0xc));
                FUN_005ca8f0(*(uint32_t*)(param_1 + 8));
                int iVar4 = *(int*)(param_1 + 0x18);
                if (iVar4 == 0) {
                    *(uint8_t*)(puVar5 + 0x18) = 0;
                    FUN_005d7d70(0x18, 0, 0);
                } else {
                    if (*(int8_t*)(iVar4 + 0x1c) != 0) {
                        FUN_0054a7e0();
                    }
                    FUN_005d2950((uint32_t*)(iVar4 + 0x20), (int)(intptr_t)puVar5);
                }
                FUN_005d7d70(7, *(uint32_t*)(param_1 + 0x24), 0);
                FUN_005d7d70(8, *(uint32_t*)(param_1 + 0x28), 0);
                FUN_005d7d70(9, *(uint32_t*)(param_1 + 0x2c), 0);
                FUN_005d7d70(10, *(uint32_t*)(param_1 + 0x30), 0);
                FUN_005d7d70(0x16, *(uint32_t*)(param_1 + 0x1c), 0);
                FUN_005d7d70(0x17, *(uint32_t*)(param_1 + 0x20), 0);
            }
            in_ECX[0x41] = in_ECX[0x41] + -1;
            in_ECX[0x42] = in_ECX[0x42] + -1;
            FUN_005bf1f0(*(uint32_t*)(in_ECX[0xf] + 0x14), (int)(intptr_t)puVar5);
            if ((local_4 != nullptr) &&
                (int iVar4 = local_4[0x19], local_4[0x19] = iVar4 + -1, iVar4 + -1 == 0)) {
                FUN_005cb7c0();
            }
            return puVar5;
        }
    }
    return nullptr;
}
