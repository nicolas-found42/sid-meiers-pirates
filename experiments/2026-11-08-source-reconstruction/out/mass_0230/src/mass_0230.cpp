#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void* DAT_00728ebc;
extern void* PTR_FUN_006c8c2c;
extern void* PTR_FUN_006c8c28;
extern uint32_t DAT_00718794;
extern uint32_t DAT_00718798;
extern uint32_t DAT_0071879c;
extern void* operator_delete__(void* p);
extern void operator_delete(void* p);
extern void* FUN_00533c78(uint32_t size);
extern void FUN_005dd7a0(uint32_t param_2);
extern void FUN_005d8610(int iVar1);
extern void FUN_005d8660(int param_1);
extern void FUN_005d8860(int iVar1);
extern void FUN_005d8760(int iVar1);
extern int FUN_00571ce0(void* p);
extern void FUN_005d8700(uint32_t param_1);
extern uint32_t FUN_005dd8e0(uint32_t param_1);
extern void FUN_005bfa50(int iVar1);
extern void FUN_005d85f0(void* puVar3);

// 0x5d88c0 — observed shape
void FUN_005d88c0(void* self) {
    uint8_t* ecx = (uint8_t*)self;
    auto get32 = [&](uint32_t off) -> uint32_t {
        uint32_t v;
        __builtin_memcpy(&v, ecx + off, 4);
        return v;
    };
    auto set32 = [&](uint32_t off, uint32_t v) {
        __builtin_memcpy(ecx + off, &v, 4);
    };
    uint32_t uVar4 = 0;
    if ((int32_t)get32(0x28) != 0) {
        if ((int32_t)get32(0x28) == 0) goto LAB_005d896e;
        do {
            uint32_t base = get32(0x20);
            uint32_t* puVar1 = *(uint32_t**)(base + uVar4 * 4);
            *(uint32_t*)(base + uVar4 * 4) = 0;
            if (puVar1 != nullptr) {
                set32(0x2c, get32(0x2c) + 0xFFFFFFFFu);
                uint32_t uVar3 = get32(0x28) - 1;
                if (uVar4 == uVar3) {
                    set32(0x28, uVar3);
                }
                int* piVar2 = (int*)puVar1[2];
                if (piVar2 != nullptr) {
                    typedef void (__cdecl* V8Fn)(int*);
                    int* vtbl = *(int**)piVar2;
                    V8Fn fn = *(V8Fn*)((uint8_t*)vtbl + 8);
                    fn(piVar2);
                    puVar1[2] = 0;
                }
                puVar1[0] = 0;
                puVar1[2] = 0;
                puVar1[3] = 0;
                puVar1[4] = 0;
                puVar1[5] = 0;
                puVar1[1] = 0;
                puVar1[6] = 0;
                puVar1[7] = 0;
                puVar1[8] = 0;
                puVar1[9] = 0;
                puVar1[10] = 0;
                uVar3 = 0;
                if (puVar1[0xe] != 0) {
                    do {
                        *(uint32_t*)(puVar1[0xc] + uVar3 * 4) = 0;
                        uVar3 = uVar3 + 1;
                    } while (uVar3 < puVar1[0xe]);
                }
                puVar1[0xe] = 0;
                puVar1[0xf] = 0;
                puVar1[0x11] = 0;
                puVar1[0x12] = 0;
                if (DAT_00728ebc != nullptr) {
                    ((uint32_t*)DAT_00728ebc)[0x12] = (uint32_t)(uintptr_t)puVar1;
                }
                puVar1[0x11] = (uint32_t)(uintptr_t)DAT_00728ebc;
                puVar1[0x12] = 0;
                DAT_00728ebc = puVar1;
            }
        LAB_005d896e:
            uVar4 = uVar4 + 1;
        } while (uVar4 < get32(0x28));
    }
    int* piVar2 = *(int**)(ecx + 0x10);
    if (piVar2 != nullptr) {
        typedef void (__cdecl* V8Fn)(int*);
        int* vtbl = *(int**)piVar2;
        V8Fn fn = *(V8Fn*)((uint8_t*)vtbl + 8);
        fn(piVar2);
    }
    set32(0x10, 0);
    *(void**)(ecx + 0x1c) = PTR_FUN_006c8c2c;
    operator_delete__(*(void**)(ecx + 0x20));
}

// 0x5d89b0 — observed shape
void FUN_005d89b0(void* self, int param_1, uint32_t param_2) {
    uint8_t* ecx = (uint8_t*)self;
    int iVar1 = *(int*)(*(int*)(ecx + 0x20) + param_1 * 4);
    if (iVar1 != 0) {
        uint32_t iVar2 = *(uint32_t*)(iVar1 + 0x24);
        FUN_005dd7a0(param_2);
        if (iVar2 != *(uint32_t*)(iVar1 + 0x24)) {
            FUN_005d8610(iVar1);
            if (*(uint32_t*)(iVar1 + 0x28) == *(uint32_t*)(iVar1 + 0xc)) {
                FUN_005d8660(param_1);
                FUN_005d8860(iVar1);
                return;
            }
            FUN_005d8760(iVar1);
        }
    }
}

// 0x5d8a10 — observed shape
void FUN_005d8a10(void) {
    uint32_t uVar5 = 0;
    if (DAT_00718794 != 0) {
        do {
            uint32_t* puVar3 = (uint32_t*)FUN_00533c78(0x4c);
            if (puVar3 == nullptr) {
                puVar3 = nullptr;
            } else {
                puVar3[0xb] = (uint32_t)(uintptr_t)&PTR_FUN_006c8c28;
                puVar3[0xd] = 0;
                puVar3[0x10] = 1;
                puVar3[0xe] = 0;
                puVar3[0xf] = 0;
                puVar3[0xc] = 0;
                puVar3[0] = 0;
                puVar3[2] = 0;
                puVar3[3] = 0;
                puVar3[4] = 0;
                puVar3[5] = 0;
                puVar3[1] = 0;
                puVar3[6] = 0;
                puVar3[7] = 0;
                puVar3[8] = 0;
                puVar3[9] = 0;
                puVar3[10] = 0;
                uint32_t uVar4 = 0;
                if (puVar3[0xe] != 0) {
                    do {
                        *(uint32_t*)(puVar3[0xc] + uVar4 * 4) = 0;
                        uVar4 = uVar4 + 1;
                    } while (uVar4 < puVar3[0xe]);
                }
                puVar3[0xe] = 0;
                puVar3[0xf] = 0;
                puVar3[0x11] = 0;
                puVar3[0x12] = 0;
            }
            uint32_t iVar1 = puVar3[0x11];
            uint32_t iVar2 = puVar3[0x12];
            if (iVar1 != 0) {
                *(uint32_t*)(iVar1 + 0x48) = iVar2;
            }
            if (iVar2 != 0) {
                *(uint32_t*)(iVar2 + 0x44) = iVar1;
            }
            if (DAT_00728ebc != nullptr) {
                ((uint32_t*)DAT_00728ebc)[0x12] = (uint32_t)(uintptr_t)puVar3;
            }
            puVar3[0x11] = (uint32_t)(uintptr_t)DAT_00728ebc;
            puVar3[0x12] = 0;
            uVar5 = uVar5 + 1;
            DAT_00728ebc = puVar3;
        } while (uVar5 < DAT_00718794);
    }
}

// 0x5d8ae0 — observed shape
uint32_t* FUN_005d8ae0(void* self, uint32_t param_1) {
    uint8_t* ecx = (uint8_t*)self;
    uint32_t uVar2 = param_1;
    if (((*(uint32_t*)(ecx + 8) & 0x10000000) == 0) && (param_1 <= *(uint32_t*)(ecx + 0xc))) {
        uVar2 = *(uint32_t*)(ecx + 0xc);
    }
    uint32_t uStack_10 = 0;
    uint32_t* puStack_14 = &param_1;
    uint32_t iStack_18 = *(uint32_t*)(ecx + 0x18);
    uint32_t uStack_1c = *(uint32_t*)(ecx + 4);
    uint32_t* piStack_20 = *(uint32_t**)(ecx + 0x14);
    uint32_t param1_saved = 0;
    (void)puStack_14; (void)uStack_10; (void)uStack_1c;
    param_1 = param1_saved;
    typedef int (__cdecl* V68Fn)(void*, uint32_t);
    void* obj = *(void**)(ecx + 0x10);
    int** vtbl = *(int***)obj;
    V68Fn fn68 = *(V68Fn*)((uint8_t*)vtbl + 0x68);
    int iVar1 = fn68(obj, uVar2);
    if (iVar1 < 0) {
        return nullptr;
    }
    uint32_t* piVar3 = (uint32_t*)DAT_00728ebc;
    if (DAT_00728ebc == nullptr) {
        FUN_005d8a10();
        piVar3 = (uint32_t*)DAT_00728ebc;
    }
    DAT_00728ebc = (void*)(uintptr_t)piVar3[0x11];
    if (DAT_00728ebc != nullptr) {
        *(uint32_t*)((uint32_t)(uintptr_t)DAT_00728ebc + 0x48) = 0;
    }
    piVar3[0x11] = 0;
    piVar3[0x12] = 0;
    piVar3[0] = (uint32_t)(uintptr_t)self;
    piVar3[2] = iStack_18;
    piVar3[3] = uVar2;
    piVar3[9] = uVar2;
    piVar3[10] = uVar2;
    piVar3[4] = *(uint32_t*)(ecx + 4);
    piVar3[5] = *(uint32_t*)(ecx + 8);
    piVar3[7] = *(uint32_t*)(ecx + 0x18);
    piVar3[6] = *(uint32_t*)(ecx + 0x14);
    piStack_20 = piVar3;
    iVar1 = FUN_00571ce0(&piStack_20);
    piVar3[1] = (uint32_t)iVar1;
    return piVar3;
}

// 0x5d8bb0 — observed shape
uint32_t FUN_005d8bb0(void* self, uint32_t param_1, char param_2) {
    uint8_t* ecx = (uint8_t*)self;
    if (param_2 == '\0') {
        FUN_005d8700(param_1);
    }
    uint32_t iVar1 = (uint32_t)(uintptr_t)FUN_005d8ae0(self, param_1);
    if (iVar1 == 0) {
        return 0;
    }
    uint32_t uVar2 = FUN_005dd8e0(param_1);
    if (*(uint32_t*)(ecx + 0x38) < *(uint32_t*)(iVar1 + 0x24)) {
        FUN_005d8760((int)iVar1);
    }
    return uVar2;
}

// 0x5d8c10 — observed shape
void FUN_005d8c10(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    in_ECX[0] = 0;
    in_ECX[1] = 0;
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    in_ECX[6] = 0;
    in_ECX[7] = 0;
    in_ECX[8] = 0;
    in_ECX[9] = 0;
    in_ECX[10] = 0;
    in_ECX[0xb] = 0;
    in_ECX[0xc] = 0;
    in_ECX[0xd] = 4;
    in_ECX[0xe] = 0;
    in_ECX[0xf] = 0;
    in_ECX[0x10] = 0;
    in_ECX[0x11] = 0;
}

// 0x5d8cd0 — observed shape
void FUN_005d8cd0(void* self) {
    uint8_t* ecx = (uint8_t*)self;
    uint32_t uVar3 = 0;
    int32_t* piVar4 = nullptr;
    if (*(uint32_t*)(ecx + 0x14) != 0) {
        piVar4 = *(int32_t**)(ecx + 0x18);
        do {
            if (*piVar4 != 0) {
                piVar4 = *(int32_t**)((*(int32_t**)(ecx + 0x18))[uVar3]);
                goto joined_r0x005d8cf7;
            }
            uVar3 = uVar3 + 1;
            piVar4 = piVar4 + 1;
        } while (uVar3 < *(uint32_t*)(ecx + 0x14));
    }
    piVar4 = nullptr;
joined_r0x005d8cf7:
    do {
        if (piVar4 == nullptr) {
            return;
        }
        int32_t iVar1 = piVar4[1];
        void* pvVar2 = (void*)(uintptr_t)piVar4[2];
        piVar4 = (int32_t*)(uintptr_t)*piVar4;
        if (piVar4 == nullptr) {
            typedef int (__cdecl* V4Fn)(int32_t);
            void* obj = *(void**)(ecx + 0x10);
            int32_t** vtbl = *(int32_t***)obj;
            V4Fn fn = *(V4Fn*)((uint8_t*)vtbl + 4);
            int32_t iVar5 = fn(iVar1);
            uVar3 = (uint32_t)iVar5 + 1;
            if (uVar3 < *(uint32_t*)(ecx + 0x14)) {
                uint32_t* puVar6 = (uint32_t*)(*(uint32_t*)(ecx + 0x18) + uVar3 * 4);
                do {
                    piVar4 = (int32_t*)(uintptr_t)*puVar6;
                    if (piVar4 != nullptr) goto LAB_005d8d32;
                    uVar3 = uVar3 + 1;
                    puVar6 = puVar6 + 1;
                } while (uVar3 < *(uint32_t*)(ecx + 0x14));
            }
            piVar4 = nullptr;
        }
    LAB_005d8d32:
        FUN_005bfa50(iVar1);
        if (pvVar2 != nullptr) {
            FUN_005d88c0(pvVar2);
            operator_delete(pvVar2);
        }
    } while (true);
}

// 0x5d8e80 — observed shape
void FUN_005d8e80(int param_1, uint32_t param_2) {
    uint8_t* p1 = (uint8_t*)(uintptr_t)param_1;
    uint32_t* puVar1 = nullptr;
    if ((param_2 < *(uint32_t*)(p1 + 0x14)) &&
        (puVar1 = *(uint32_t**)(*(uint32_t*)(p1 + 0x1c) + param_2 * 4), puVar1 != nullptr)) {
        if (puVar1[2] != 0) {
            FUN_005d89b0((void*)(uintptr_t)*(uint32_t*)(puVar1[1] + 4), (int)*(int32_t*)puVar1, *puVar1);
        }
        if (param_2 < *(uint32_t*)(p1 + 0x14)) {
            *(uint32_t*)(*(uint32_t*)(p1 + 0x1c) + param_2 * 4) = 0;
        }
    }
}

// 0x5d8ed0 — observed shape
void FUN_005d8ed0(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    in_ECX[7] = (uint32_t)(uintptr_t)PTR_FUN_006c8c2c;
    in_ECX[9] = 0;
    in_ECX[0xc] = 1;
    in_ECX[10] = 0;
    in_ECX[0xb] = 0;
    in_ECX[8] = 0;
    in_ECX[3] = DAT_00718798;
    in_ECX[1] = 0;
    in_ECX[2] = 0;
    in_ECX[0] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    in_ECX[6] = 0;
    uint32_t uVar1 = 0;
    if (in_ECX[10] != 0) {
        do {
            *(uint32_t*)(in_ECX[8] + uVar1 * 4) = 0;
            uVar1 = uVar1 + 1;
        } while (uVar1 < in_ECX[10]);
    }
    in_ECX[10] = 0;
    in_ECX[0xb] = 0;
    in_ECX[0xd] = 0;
    in_ECX[0xe] = DAT_0071879c;
}

// 0x5d8f40 — observed shape
uint32_t* FUN_005d8f40(uint32_t param_1, int32_t* param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5) {
    uint32_t iVar2 = (uint32_t)(uintptr_t)FUN_00533c78(0x3c);
    if (iVar2 == 0) {
        return nullptr;
    }
    uint32_t* puVar3 = (uint32_t*)FUN_005d8ed0();
    if (puVar3 != nullptr) {
        puVar3[3] = param_1;
        if (param_2 == nullptr) {
            int32_t* piVar1 = (int32_t*)(uintptr_t)puVar3[4];
            if (piVar1 != nullptr) {
                typedef void (__cdecl* V8Fn)(int32_t*);
                int32_t* vtbl = *(int32_t**)piVar1;
                V8Fn fn = *(V8Fn*)((uint8_t*)vtbl + 8);
                fn(piVar1);
            }
            puVar3[4] = 0;
        } else {
            puVar3[4] = (uint32_t)(uintptr_t)param_2;
            typedef void (__cdecl* V4Fn)(int32_t*);
            int32_t* vtbl = *(int32_t**)param_2;
            V4Fn fn = *(V4Fn*)((uint8_t*)vtbl + 4);
            fn(param_2);
        }
        puVar3[1] = param_3;
        puVar3[2] = param_4;
        puVar3[0] = param_5;
        FUN_005d85f0(puVar3);
    }
    return puVar3;
}

// ---- appended: mass_0230 retry ----

extern void FUN_005dd980(void* self);
extern void FUN_005dd9f0(void* self, uint32_t param_1);
extern void FUN_005dda00(void* param_1);
extern void FUN_005d0610(void);
extern char FUN_004879c0(void* a, int* b);
extern void* PTR_FUN_006c8c68;
extern void* PTR_FUN_006c8c30;
extern void* PTR_FUN_006c8c4c;
extern void* PTR_FUN_006c8c98;
extern void* DAT_00728ec0;
extern uint8_t DAT_00727cc8;
extern uint8_t DAT_007278d4;
extern uint32_t uRam00000008;

// 0x5d9010 — observed shape
void FUN_005d9010(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    FUN_005dd980(self);
    in_ECX[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c8c68;
    in_ECX[4] = (uint32_t)(uintptr_t)&PTR_FUN_006c8c30;
    in_ECX[5] = 0x25;
    in_ECX[7] = 0;
    uint32_t* puVar1 = (uint32_t*)FUN_00533c78(0x94);
    in_ECX[6] = (uint32_t)(uintptr_t)puVar1;
    for (uint32_t uVar2 = in_ECX[5] & 0x3fffffffu; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar1 = 0;
        puVar1 = puVar1 + 1;
    }
    // remainder byte loop present in the listing with a zero trip count
    for (int iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(uint8_t*)puVar1 = 0;
        puVar1 = (uint32_t*)((uint8_t*)puVar1 + 1);
    }
    in_ECX[4] = (uint32_t)(uintptr_t)&PTR_FUN_006c8c4c;
}

// 0x5d9130 — observed shape
void FUN_005d9130(uint32_t param_1) {
    int iVar1 = (int)(uintptr_t)FUN_00533c78(0x20);
    if (iVar1 == 0) {
        uRam00000008 = param_1;
        return;
    }
    FUN_005d9010((void*)(uintptr_t)iVar1);
    *(uint32_t*)(iVar1 + 8) = param_1;
}

// 0x5d91d0 — observed shape
uint32_t* FUN_005d91d0(uint32_t param_1) {
    uint32_t* puVar1;
    if (DAT_00728ec0 == nullptr) {
        puVar1 = (uint32_t*)FUN_00533c78(0x10);
        if (puVar1 != nullptr) {
            FUN_005dd980(puVar1);
            *puVar1 = (uint32_t)(uintptr_t)&PTR_FUN_006c8c98;
            DAT_00728ec0 = puVar1;
            puVar1[2] = param_1;
            return (uint32_t*)DAT_00728ec0;
        }
        uRam00000008 = param_1;
        DAT_00728ec0 = nullptr;
    }
    return (uint32_t*)DAT_00728ec0;
}

// 0x5d9230 — observed shape
void FUN_005d9230(void* self, int param_1, uint32_t param_2) {
    uint8_t* ecx = (uint8_t*)self;
    uint32_t* puVar1;
    uint32_t uVar2;
    if (*(int32_t*)(param_1 + 0x24) == 0) {
        puVar1 = (uint32_t*)FUN_00533c78(0x48);
        if (puVar1 == nullptr) {
            puVar1 = nullptr;
        } else {
            puVar1[0] = 0;
            puVar1[1] = 0;
            puVar1[2] = 0;
            puVar1[3] = 0;
            puVar1[4] = 0;
            puVar1[5] = 0;
            puVar1[6] = 0;
            puVar1[7] = 0;
            puVar1[8] = 0;
            puVar1[9] = 0;
            puVar1[10] = 0;
            puVar1[0xb] = 0;
            puVar1[0xc] = 0;
            puVar1[0xd] = 4;
            puVar1[0xe] = 0;
            puVar1[0xf] = 0;
            puVar1[0x10] = 0;
            puVar1[0x11] = 0;
        }
        puVar1[0xd] = 6;
        *(uint32_t**)(param_1 + 0x24) = puVar1;
        uVar2 = (param_2 & 0x7fffffu) | (uint32_t)(*(int32_t*)(param_1 + 0x18) != 0) << 0x18 |
                *(uint32_t*)(ecx + 8);
        *puVar1 = uVar2;
        FUN_005dd9f0(puVar1, uVar2);
    }
}

// 0x5d92d0 — observed shape
void FUN_005d92d0(void* self, int param_1, uint32_t param_2) {
    uint8_t* ecx = (uint8_t*)self;
    uint32_t* puVar1;
    uint32_t uVar2;
    if (*(int32_t*)(param_1 + 0x20) == 0) {
        puVar1 = (uint32_t*)FUN_00533c78(0x48);
        if (puVar1 == nullptr) {
            puVar1 = nullptr;
        } else {
            puVar1[0] = 0;
            puVar1[1] = 0;
            puVar1[2] = 0;
            puVar1[3] = 0;
            puVar1[4] = 0;
            puVar1[5] = 0;
            puVar1[6] = 0;
            puVar1[7] = 0;
            puVar1[8] = 0;
            puVar1[9] = 0;
            puVar1[10] = 0;
            puVar1[0xb] = 0;
            puVar1[0xc] = 0;
            puVar1[0xd] = 4;
            puVar1[0xe] = 0;
            puVar1[0xf] = 0;
            puVar1[0x10] = 0;
            puVar1[0x11] = 0;
        }
        puVar1[0xd] = 4;
        *(uint32_t**)(param_1 + 0x20) = puVar1;
        uVar2 = (param_2 & 0x7fffffu) | *(uint32_t*)(ecx + 8) | 0x1000000u;
        *puVar1 = uVar2;
        FUN_005dd9f0(puVar1, uVar2);
    }
}

// 0x5d9360 — observed shape
uint32_t* FUN_005d9360(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4,
                      uint32_t param_5) {
    uint32_t* puVar1 = (uint32_t*)FUN_00533c78(0x20);
    if (puVar1 == nullptr) {
        return nullptr;
    }
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[5] = 0;
    puVar1[4] = 0;
    puVar1[6] = 0;
    puVar1[7] = 0;
    *puVar1 = param_5;
    puVar1[1] = param_1;
    puVar1[2] = param_2;
    puVar1[3] = param_3;
    puVar1[5] = param_4;
    puVar1[4] = 0;
    return puVar1;
}

// 0x5d93b0 — observed shape
void FUN_005d93b0(void* self, int32_t* param_1, uint32_t param_2, int param_3, uint32_t param_4) {
    uint8_t* ecx = (uint8_t*)self;
    uint32_t* puVar3 = nullptr;
    (void)param_2;
    if (param_3 == 0) {
        if (param_1[0xe] != 0) {
            return;
        }
        int32_t iVar2 = (int32_t)(uintptr_t)FUN_00533c78(0x48);
        if (iVar2 == 0) {
            puVar3 = nullptr;
        } else {
            FUN_005d8c10((void*)(uintptr_t)iVar2);
            puVar3 = (uint32_t*)(uintptr_t)iVar2;
        }
        typedef void* (__cdecl* V4GetFn)(void);
        V4GetFn* slot = (V4GetFn*)((uint8_t*)(uintptr_t)(*(uint32_t*)param_1) + 4);
        uint32_t* puVar4 = (uint32_t*)(uintptr_t)(*slot)();
        for (; puVar4 != nullptr; puVar4 = (uint32_t*)(uintptr_t)puVar4[1]) {
            if (puVar4 == (uint32_t*)(uintptr_t)&DAT_00727cc8) {
                puVar3[0xd] = 4;
                goto LAB_005d9457;
            }
        }
        {
            char cVar1 = FUN_004879c0((void*)&DAT_007278d4, param_1);
            if (cVar1 != '\0') {
                puVar3[0xd] = 5;
            }
        }
    LAB_005d9457:
        param_1[0xe] = (int32_t)(uintptr_t)puVar3;
    } else {
        if (*(int32_t*)(param_3 + 0x28) != 0) {
            return;
        }
        int32_t iVar2 = (int32_t)(uintptr_t)FUN_00533c78(0x48);
        if (iVar2 == 0) {
            puVar3 = nullptr;
        } else {
            FUN_005d8c10((void*)(uintptr_t)iVar2);
            puVar3 = (uint32_t*)(uintptr_t)iVar2;
        }
        puVar3[0xd] = (uint32_t)(*(int16_t*)(param_3 + 0x22) != 0) + 4;
        *(uint32_t**)(param_3 + 0x28) = puVar3;
    }
    if (param_1[9] == 0) {
        param_4 = param_4 & 0xff7fffffu;
    } else {
        param_4 = param_4 | 0x800000u;
    }
    uint32_t uVar5 = (param_4 & 0xffffffu) |
                     (uint32_t)(*(uint8_t*)((uint8_t*)param_1 + 0x30) & 0x3f) << 0x18 |
                     *(uint32_t*)(ecx + 8);
    *puVar3 = uVar5;
    FUN_005dd9f0(puVar3, uVar5);
}

// 0x5d9540 — observed shape
void FUN_005d9540(int param_1, uint32_t param_2) {
    void* pvVar1 = nullptr;
    if (param_2 < *(uint32_t*)(param_1 + 0x14)) {
        pvVar1 = *(void**)(*(int32_t*)(param_1 + 0x1c) + param_2 * 4);
        if (pvVar1 != nullptr) {
            int32_t* piVar2 = *(int32_t**)((uint8_t*)pvVar1 + 8);
            if (piVar2 != nullptr) {
                typedef void (__cdecl* V8Fn)(int32_t*);
                int32_t* vtbl = *(int32_t**)piVar2;
                V8Fn fn = *(V8Fn*)((uint8_t*)vtbl + 8);
                fn(piVar2);
            }
            if (param_2 < *(uint32_t*)(param_1 + 0x14)) {
                *(uint32_t*)(*(int32_t*)(param_1 + 0x1c) + param_2 * 4) = 0;
            }
            *(uint32_t*)((uint8_t*)pvVar1 + 8) = 0;
            operator_delete(pvVar1);
        }
    }
}

// 0x5d9860 — observed shape
void FUN_005d9860(int param_1) {
    void* pvVar1 = *(void**)(param_1 + 0x38);
    if (pvVar1 != nullptr) {
        FUN_005dda00(pvVar1);
        if (*(uint32_t**)((uint8_t*)pvVar1 + 0x1c) != nullptr) {
            uint32_t* puVar4 = *(uint32_t**)((uint8_t*)pvVar1 + 0x1c);
            for (uint32_t uVar2 = *(uint32_t*)((uint8_t*)pvVar1 + 0x14) & 0x3fffffffu; uVar2 != 0;
                 uVar2 = uVar2 - 1) {
                *puVar4 = 0;
                puVar4 = puVar4 + 1;
            }
            // remainder byte loop present in the listing with a zero trip count
            for (int32_t iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
                *(uint8_t*)puVar4 = 0;
                puVar4 = (uint32_t*)((uint8_t*)puVar4 + 1);
            }
        }
        FUN_005d0610();
        operator_delete(pvVar1);
        *(uint32_t*)(param_1 + 0x38) = 0;
    }
}

// 0x5d98b0 — observed shape
void FUN_005d98b0(int param_1) {
    void* pvVar1 = *(void**)(param_1 + 0x28);
    if (pvVar1 != nullptr) {
        FUN_005dda00(pvVar1);
        if (*(uint32_t**)((uint8_t*)pvVar1 + 0x1c) != nullptr) {
            uint32_t* puVar4 = *(uint32_t**)((uint8_t*)pvVar1 + 0x1c);
            for (uint32_t uVar2 = *(uint32_t*)((uint8_t*)pvVar1 + 0x14) & 0x3fffffffu; uVar2 != 0;
                 uVar2 = uVar2 - 1) {
                *puVar4 = 0;
                puVar4 = puVar4 + 1;
            }
            // remainder byte loop present in the listing with a zero trip count
            for (int32_t iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
                *(uint8_t*)puVar4 = 0;
                puVar4 = (uint32_t*)((uint8_t*)puVar4 + 1);
            }
        }
        FUN_005d0610();
        operator_delete(pvVar1);
        *(uint32_t*)(param_1 + 0x28) = 0;
    }
}
