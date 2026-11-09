// UNVERIFIED decompiler-derived reconstruction — batch mass_0182.
// Target: Sid Meier's Pirates! (2004), PE32 i386.
// Sources: analysis/pseudocode/functions/0x57eef0.c .. 0x5804d0.c (Ghidra 12.2).
// No compiler/byte-match claim; shapes follow the supplied listings.
#include <cstdint>
#include <cstddef>

// ---------------------------------------------------------------------------
// Helpers and globals observed in the supplied corpus listings.
// ---------------------------------------------------------------------------
extern void operator_delete(void* memory);
extern void operator_delete__(void* memory);

extern void FUN_00520da0(void* node);
extern void FUN_00538400(void);
extern void FUN_00538430(int param);
extern void FUN_005383d0(void);
extern void FUN_00545cc0(void);
extern void FUN_00545df0(int count);
extern void FUN_00545950(int value);
extern void* FUN_00545600(void);
extern int FUN_00545630(void);
extern void FUN_005460e0(void* out);
extern void FUN_005e1a10(void* iter, void* scratch, void** out);
extern void FUN_00552aa0(int object, int* param);
extern void FUN_00552b70(void* param);
extern void FUN_00552c80(void);
extern void FUN_00552f70(void);
extern void FUN_00553060(int object);
extern void FUN_005530e0(int* param);
extern void* FUN_00555b90(void* scratch);
extern void FUN_00555f70(void* quat);
extern void FUN_0055ec90(float* out, float t, float* a, float* b);
extern void FUN_005606f0(uint32_t index, void* out);
extern void FUN_00569960(void);
extern void FUN_0056eed0(float t);
extern void FUN_00576640(int kind, uint32_t a, uint32_t* b, void* slot, uint32_t c, uint32_t d);
extern void FUN_00579100(uint32_t param);
extern void FUN_00579670(uint32_t value);
extern void FUN_0057a050(void);
extern int FUN_0057a620(void* data, int a, int b);
extern void FUN_0057a8f0(void* data, uint32_t value);
extern void FUN_0057aa50(uint32_t value);
extern void FUN_0057aa70(uint32_t value);
extern void FUN_0057ab90(uint32_t value, uint32_t extra);
extern void FUN_0057b730(uint32_t value);
extern void FUN_0057baf0(void** out, uint32_t a, uint32_t b, void* c);
extern uint8_t FUN_0057ee90(void* object, uint32_t arg);
extern void FUN_0057e9e0(void);
extern void* FUN_0057ec00(void);
extern void FUN_0057ede0(uint32_t value, void* object);
extern char FUN_00552bc0(uint32_t param);
extern void FUN_005bd960(void* self, void** out);
extern void FUN_005bbe20(void* object);
extern int FUN_00533c78(int size);
extern void* thunk_FUN_00533c78(int size);
extern void FUN_006b34a0(int address);

extern char DAT_007179b0[];
extern char DAT_00717b98;
extern uint32_t DAT_00727430;
extern uint32_t DAT_00727434;
extern uint32_t DAT_00727438;
extern uint32_t* DAT_00728a28;
extern char DAT_007284e8[];
extern char DAT_007284fc[];
extern char DAT_00728510[];
extern char DAT_00728650[];
extern char DAT_00728664[];
extern char DAT_00728678[];
extern char PTR_FUN_006c3304[];
extern char PTR_FUN_006c4b88[];
extern char PTR_FUN_006c4bc0[];
extern char PTR_FUN_006c4be0[];
extern char PTR_FUN_006c4c50[];
extern char PTR_FUN_007115f4[];

// ---------------------------------------------------------------------------
// Translations
// ---------------------------------------------------------------------------

// 0x0057eef0 — observed shape
void FUN_0057eef0(void* self, uint32_t param_1) {
    uint32_t index = 0;
    int current = 0;

    if (*(uint32_t*)((char*)self + 0x48) != 0) {
        int* entry = *(int**)((char*)self + 0x4c);
        do {
            if (*entry != 0) {
                current = (*(int**)((char*)self + 0x4c))[index];
                break;
            }
            ++index;
            ++entry;
        } while (index < *(uint32_t*)((char*)self + 0x48));
    }
    while (current != 0) {
        void* object = nullptr;
        FUN_005e1a10(&current, &param_1, &object);
        switch (*(uint32_t*)((char*)object + 0x7c)) {
        case 1:
            FUN_0057aa50(param_1);
            break;
        case 2:
        case 3:
        case 5:
            FUN_0057b730(param_1);
            break;
        case 6:
            FUN_0057aa70(param_1);
            break;
        case 8:
            FUN_0057ab90(param_1, *(uint32_t*)((char*)self + 0x8c));
            break;
        default:
            break;
        }
        int* refcount = (int*)((char*)object + 4);
        *refcount = *refcount - 1;
        if (*refcount == 0) {
            (*(void (**)(void*, int))*(void**)object)(object, 1);
        }
    }
}

// 0x0057efe0 — observed shape
void FUN_0057efe0(void* self, int param_1, int* param_2) {
    uint32_t index = 0;
    int current = 0;
    int* source = param_2;
    uint8_t local_4[4] = {0, 0, 0, 0};
    int* object = nullptr;
    char* target = (char*)(uintptr_t)param_1;

    FUN_00552aa0(param_1, param_2);
    target[0x58] = *(uint8_t*)((char*)self + 0x58);
    *(uint32_t*)(target + 0x8c) = *(uint32_t*)((char*)self + 0x8c);
    if (*(uint32_t*)((char*)self + 0x48) != 0) {
        int* entry = *(int**)((char*)self + 0x4c);
        do {
            if (*entry != 0) {
                current = (*entry);
                break;
            }
            ++index;
            ++entry;
        } while (index < *(uint32_t*)((char*)self + 0x48));
    }
    if (current != 0) {
        do {
            FUN_005e1a10(&current, local_4, (void**)&object);
            int* object_ptr = object;
            intptr_t iVar5 = (*(intptr_t (**)(int*))(*(char**)object_ptr + 8))(source);
            if (*(int*)((char*)iVar5 + 0x78) == 0) {
                *(int*)((char*)iVar5 + 0x78) = param_1;
                *(int*)((char*)iVar5 + 4) = *(int*)((char*)iVar5 + 4) + 1;
                FUN_0057ede0(*(uint32_t*)((char*)iVar5 + 0xc), (void*)iVar5);
            }
        } while (current != 0);
        if (object != nullptr) {
            int* refcount = (int*)((char*)object + 4);
            *refcount = *refcount - 1;
            if (*refcount == 0) {
                (*(void (**)(int))*(void**)object)(1);
            }
        }
    }
}

// 0x0057f0b0 — observed shape
void FUN_0057f0b0(void* self, void* param_1) {
    uint32_t index = 0;
    int current = 0;
    uint8_t local_4[4] = {0, 0, 0, 0};
    void* object = nullptr;
    char* target;
    uint32_t uVar2;
    uint32_t count;

    FUN_00552b70(param_1);
    FUN_005bd960(self, &param_1);
    target = (char*)param_1;
    uVar2 = *(uint32_t*)(target + 0x34);
    count = *(uint32_t*)(target + 0x48);
    if (count != 0) {
        int* entry = *(int**)(target + 0x4c);
        do {
            if (*entry != 0) {
                current = (*(int**)(target + 0x4c))[index];
                break;
            }
            ++index;
            ++entry;
        } while (index < count);
    }
    if (current != 0) {
        do {
            FUN_005e1a10(&current, local_4, &object);
            FUN_0057a050();
            FUN_00579670(uVar2);
        } while (current != 0);
        if (object != nullptr) {
            int* refcount = (int*)((char*)object + 4);
            *refcount = *refcount - 1;
            if (*refcount == 0) {
                (*(void (**)(int))*(void**)object)(1);
            }
        }
    }
}

// 0x0057f160 — observed shape
void FUN_0057f160(void* self, int param_1) {
    char* base = (char*)(uintptr_t)param_1;
    uint32_t uVar2;
    uint32_t local_c;
    int iVar9;
    int iVar8;
    int iVar5;
    void* pvVar3;
    void* puVar6;
    uint32_t* puVar4;

    FUN_00553060(param_1);
    if (0x4010002 < *(uint32_t*)(base + 0x1c)) {
        iVar9 = FUN_00545630();
        if (iVar9 != 0) {
            do {
                iVar5 = (int)(intptr_t)FUN_00545600();
                if ((self == nullptr) || (*(int*)((char*)iVar5 + 0x78) == 0)) {
                    *(int*)((char*)iVar5 + 0x78) = (int)(intptr_t)self;
                    *(int*)((char*)iVar5 + 4) = *(int*)((char*)iVar5 + 4) + 1;
                    FUN_0057ede0(*(uint32_t*)((char*)iVar5 + 0xc), (void*)iVar5);
                }
                iVar9 = iVar9 - 1;
            } while (iVar9 != 0);
        }
        return;
    }
    uVar2 = DAT_00728a28[0xf];
    iVar9 = 0;
    local_c = 0;
    if (uVar2 != 0) {
        do {
            pvVar3 = *(void**)(uintptr_t)(DAT_00728a28[7] + local_c * 4);
            iVar5 = FUN_00533c78(0xf8);
            if (iVar5 == 0) {
                iVar5 = 0;
            } else {
                iVar5 = FUN_0057a620(pvVar3, 0xc, 0xc);
            }
            operator_delete__(pvVar3);
            *(uint32_t*)((char*)iVar5 + 0x74) =
                *(uint32_t*)(uintptr_t)(DAT_00728a28[1] + local_c * 4);
            puVar6 = FUN_00545600();
            puVar4 = *(uint32_t**)((char*)iVar5 + 0x70);
            if (puVar4 != puVar6) {
                if (puVar4 != nullptr) {
                    int* refcount = (int*)puVar4 + 1;
                    *refcount = *refcount - 1;
                    if (*refcount == 0) {
                        (*(void (**)(int))*(void**)puVar4)(1);
                    }
                }
                *(void**)((char*)iVar5 + 0x70) = puVar6;
                if (puVar6 != nullptr) {
                    ((uint32_t*)puVar6)[1] = ((uint32_t*)puVar6)[1] + 1;
                }
            }
            for (iVar8 = *(int*)(uintptr_t)(DAT_00728a28[0xd] + local_c * 4);
                 iVar8 != 0; iVar8 = iVar8 - 1) {
                pvVar3 = *(void**)(uintptr_t)(DAT_00728a28[0x13] + iVar9 * 4);
                iVar9 = iVar9 + 1;
                uint32_t uVar7 = (uint32_t)(uintptr_t)FUN_00545600();
                FUN_0057a8f0(pvVar3, uVar7);
                operator_delete__(pvVar3);
            }
            if ((self == nullptr) || (*(int*)((char*)iVar5 + 0x78) == 0)) {
                *(int*)((char*)iVar5 + 0x78) = (int)(intptr_t)self;
                *(int*)((char*)iVar5 + 4) = *(int*)((char*)iVar5 + 4) + 1;
                FUN_0057ede0(*(uint32_t*)((char*)iVar5 + 0xc), (void*)iVar5);
            }
            local_c = local_c + 1;
        } while (local_c < uVar2);
    }
    puVar4 = DAT_00728a28;
    if (DAT_00728a28 != nullptr) {
        DAT_00728a28[0x12] = (uint32_t)(uintptr_t)&PTR_FUN_007115f4[0];
        operator_delete__((void*)(uintptr_t)puVar4[0x13]);
        puVar4[0xc] = (uint32_t)(uintptr_t)&PTR_FUN_006c3304[0];
        operator_delete__((void*)(uintptr_t)puVar4[0xd]);
        puVar4[6] = (uint32_t)(uintptr_t)&PTR_FUN_007115f4[0];
        operator_delete__((void*)(uintptr_t)puVar4[7]);
        *puVar4 = (uint32_t)(uintptr_t)&PTR_FUN_006c3304[0];
        operator_delete__((void*)(uintptr_t)puVar4[1]);
        operator_delete(puVar4);
    }
    DAT_00728a28 = nullptr;
}

// 0x0057f350 — observed shape
void FUN_0057f350(void* self) {
    uint32_t uVar1 = *(uint32_t*)((char*)self + 0x34);
    uint32_t index = 0;
    int current = 0;
    uint8_t local_4[4] = {0, 0, 0, 0};
    void* object = nullptr;

    if (*(uint32_t*)((char*)self + 0x48) != 0) {
        int* entry = *(int**)((char*)self + 0x4c);
        do {
            if (*entry != 0) {
                current = (*(int**)((char*)self + 0x4c))[index];
                break;
            }
            ++index;
            ++entry;
        } while (index < *(uint32_t*)((char*)self + 0x48));
    }
    if (current != 0) {
        do {
            FUN_005e1a10(&current, local_4, &object);
            FUN_0057a050();
            FUN_00579670(uVar1);
        } while (current != 0);
        if (object != nullptr) {
            int* refcount = (int*)((char*)object + 4);
            *refcount = *refcount - 1;
            if (*refcount == 0) {
                (*(void (**)(int))*(void**)object)(1);
            }
        }
    }
}

// 0x0057f490 — observed shape
void FUN_0057f490(void* self, int* param_1) {
    int iVar3 = 0;
    uint32_t uVar2 = 0;
    uint32_t local_10 = 0;
    uint32_t local_14 = 0;
    void* object = nullptr;
    int* stream;

    FUN_005530e0(param_1);
    stream = (int*)(uintptr_t)param_1[0x58];
    uint32_t header = *(uint32_t*)((char*)self + 0x50);
    (*(void (**)(void*, int))(*(char**)stream + 0xc))(&header, 4);
    if (*(uint32_t*)((char*)self + 0x48) != 0) {
        int* entry = *(int**)((char*)self + 0x4c);
        do {
            if (*entry != 0) {
                iVar3 = (*entry);
                break;
            }
            ++uVar2;
            ++entry;
        } while (uVar2 < *(uint32_t*)((char*)self + 0x48));
    }
    if (iVar3 != 0) {
        do {
            FUN_005e1a10(&iVar3, &local_10, &object);
            int iVar1 = (int)local_10;
            if ((DAT_00717b98 == 0) || (local_10 == 0)) {
                uint8_t flag = 0;
                (*(void (**)(void*, int))(*(char**)stream + 0xc))(&flag, 1);
                (*(void (**)(int))(*(char**)param_1 + 0x2c))(0);
            } else {
                uint8_t flag = 1;
                (*(void (**)(void*, int))(*(char**)stream + 0xc))(&flag, 1);
                FUN_00545950(iVar3);
                FUN_00545950(iVar1);
                uint32_t uStack_14 = local_14;
                (*(void (**)(void*, int))(*(char**)stream + 0xc))(&uStack_14, 4);
            }
        } while (iVar3 != 0);
        if (object != nullptr) {
            int* refcount = (int*)((char*)object + 4);
            *refcount = *refcount - 1;
            if (*refcount == 0) {
                (*(void (**)(int))*(void**)object)(1);
            }
        }
    }
}

// 0x0057f5c0 — observed shape
int FUN_0057f5c0(void* self, uint32_t param_1) {
    char* other = (char*)(uintptr_t)param_1;
    uint32_t index = 0;
    int current_a = 0;
    uint32_t current_b = 0;
    uint8_t local_8[4] = {0, 0, 0, 0};
    uint8_t local_4[4] = {0, 0, 0, 0};
    int* object_a = nullptr;
    int* object_b = nullptr;
    int* puVar5 = nullptr;
    int* piVar6 = nullptr;
    char cVar3;

    cVar3 = FUN_00552bc0(param_1);
    if ((cVar3 == 0) || (*(int*)((char*)self + 0x50) != *(int*)(other + 0x50))) {
        return 0;
    }
    if (*(uint32_t*)((char*)self + 0x48) != 0) {
        int* entry = *(int**)((char*)self + 0x4c);
        do {
            if (*entry != 0) {
                current_a = (*entry);
                break;
            }
            ++index;
            ++entry;
        } while (index < *(uint32_t*)((char*)self + 0x48));
    }
    index = 0;
    if (*(uint32_t*)(other + 0x48) != 0) {
        int* entry = *(int**)(other + 0x4c);
        do {
            if (*entry != 0) {
                current_b = (uint32_t)(*entry);
                break;
            }
            ++index;
            ++entry;
        } while (index < *(uint32_t*)(other + 0x48));
    }
    for (;;) {
        if (current_a == 0) {
            if (current_b == 0) {
                if (puVar5 != nullptr) {
                    int* rc = puVar5 + 1;
                    *rc = *rc - 1;
                    if (*rc == 0) {
                        (*(void (**)(int))(uintptr_t)puVar5[0])(1);
                    }
                }
                if (piVar6 != nullptr) {
                    int* rc = piVar6 + 1;
                    *rc = *rc - 1;
                    if (*rc == 0) {
                        (*(void (**)(int))(uintptr_t)piVar6[0])(1);
                    }
                }
                return 1;
            }
            break;
        }
        if (current_b == 0) {
            break;
        }
        FUN_005e1a10(&current_a, local_8, (void**)&object_a);
        FUN_005e1a10(&current_b, local_4, (void**)&object_b);
        puVar5 = object_b;
        piVar6 = object_a;
        cVar3 = (*(char (**)(int*))(*(char**)object_a + 0x1c))(object_b);
        if (cVar3 == 0) {
            break;
        }
    }
    if (puVar5 != nullptr) {
        int* rc = puVar5 + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            (*(void (**)(int))(uintptr_t)puVar5[0])(1);
        }
    }
    if (piVar6 != nullptr) {
        int* rc = piVar6 + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
            (*(void (**)(int))(uintptr_t)piVar6[0])(1);
        }
    }
    return 0;
}

// 0x0057f720 — observed shape
void FUN_0057f720(void* self, uint8_t param_1) {
    FUN_0057e9e0();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x0057f740 — observed shape
void FUN_0057f740(void* self) {
    uint32_t* words = (uint32_t*)self;
    uint32_t* cursor;
    const uint32_t* source;
    uint32_t* dest;
    uint32_t remaining;
    int tail;
    int i;

    FUN_00552c80();
    words[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c4be0[0];
    words[0x11] = (uint32_t)(uintptr_t)&PTR_FUN_006c4b88[0];
    words[0x12] = 0x25;
    words[0x14] = 0;
    cursor = (uint32_t*)thunk_FUN_00533c78(0x94);
    words[0x13] = (uint32_t)(uintptr_t)cursor;
    for (remaining = words[0x12] & 0x3fffffff; remaining != 0; remaining = remaining - 1) {
        *cursor = 0;
        cursor = cursor + 1;
    }
    // The listing emits a second zero-fill loop whose counter is zero, so it never runs.
    for (tail = 0; tail != 0; tail = tail - 1) {
        *(uint8_t*)cursor = 0;
        cursor = (uint32_t*)((uint8_t*)cursor + 1);
    }
    ((uint8_t*)self)[0x54] = 0;
    words[0x11] = (uint32_t)(uintptr_t)&PTR_FUN_006c4bc0[0];
    ((uint8_t*)self)[0x58] = 0;
    ((uint8_t*)self)[0x90] = 0;
    words[0x25] = 0;
    words[0x26] = 0;
    words[0x23] = 0;
    source = (const uint32_t*)&DAT_007179b0[0];
    dest = words + 0x17;
    for (i = 9; i != 0; i = i - 1) {
        *dest = *source;
        source = source + 1;
        dest = dest + 1;
    }
    words[0x20] = DAT_00727430;
    words[0x21] = DAT_00727434;
    words[0x22] = DAT_00727438;
}

// 0x0057f7f0 — observed shape
uint8_t FUN_0057f7f0(uint32_t param_1, void* param_2, uint32_t param_3, uint32_t param_4) {
    uint32_t uVar3 = param_3;
    void* puVar2 = param_2;
    uint8_t uVar4;

    FUN_0057baf0(&param_2, param_1, param_3, param_2);
    if (param_2 == nullptr) {
        return 0;
    }
    if (puVar2 != nullptr) {
        FUN_005bbe20(puVar2);
    }
    FUN_00579100(param_1);
    ((uint32_t*)param_2)[5] = uVar3;
    uVar4 = FUN_0057ee90(param_2, param_4);
    if (param_2 != nullptr) {
        int* refcount = (int*)((char*)param_2 + 4);
        int previous = *refcount;
        *refcount = previous - 1;
        if (previous - 1 == 0) {
            (*(void (**)(int))*(void**)param_2)(1);
        }
    }
    return uVar4;
}

// 0x0057f8f0 — observed shape
void FUN_0057f8f0(void* self, int in_EBX) {
    char* base = (char*)self;
    int* stream = *(int**)(base + 0x15c);
    void* local_10 = nullptr;
    void* local_1c = nullptr;
    void* pvStack_20 = nullptr;
    void* pvStack_18 = nullptr;
    uint32_t uStack_14 = 0;
    uint32_t local_4 = 0;
    uint32_t auStack_c[2] = {0, 0};
    int iVar2;
    uint32_t uVar1;

    FUN_00552f70();
    if (*(uint32_t*)(base + 0x1c) < 0x4010003) {
        void** ppvStack_38 = &local_10;
        (*(void (**)(void))(*(char**)stream + 8))();
        if (pvStack_18 != nullptr) {
            do {
                pvStack_18 = (void*)((intptr_t)pvStack_18 - 1);
                (*(void (**)(void*, int))(*(char**)stream + 8))(&local_4, 1);
                FUN_005460e0((uint8_t*)auStack_c - 28);
                if ((char)auStack_c[0] == '\0') {
                    iVar2 = FUN_00533c78(0x60);
                    if (iVar2 == 0) {
                        DAT_00728a28 = nullptr;
                    } else {
                        DAT_00728a28 = (uint32_t*)FUN_0057ec00();
                    }
                    uVar1 = DAT_00728a28[9];
                    if (DAT_00728a28[8] <= uVar1) {
                        FUN_006b34a0((int)(DAT_00728a28[0xb] + uVar1));
                    }
                    FUN_005606f0(uVar1, (uint8_t*)auStack_c - 28);
                    (*(void (**)(void*, int))(*(char**)stream + 8))(&pvStack_18, 4);
                    uVar1 = DAT_00728a28[3];
                    if (DAT_00728a28[2] <= uVar1) {
                        FUN_006b34a0((int)(DAT_00728a28[5] + uVar1));
                    }
                    FUN_005606f0(uVar1, &pvStack_20);
                    FUN_00545cc0();
                    (*(void (**)(void*, int))(*(char**)stream + 8))(&ppvStack_38, 4);
                    uVar1 = DAT_00728a28[0xf];
                    if (DAT_00728a28[0xe] <= uVar1) {
                        FUN_006b34a0((int)(DAT_00728a28[0x11] + uVar1));
                    }
                    FUN_005606f0(uVar1, (uint8_t*)auStack_c - 28);
                } else {
                    FUN_005460e0((uint8_t*)auStack_c - 24);
                    (*(void (**)(void*, int))(*(char**)stream + 8))(&local_1c, 4);
                    FUN_0057f7f0((uint32_t)(uintptr_t)local_1c, pvStack_20, uStack_14, 0);
                    operator_delete__(local_1c);
                    operator_delete__(pvStack_20);
                }
            } while (pvStack_18 != nullptr);
            return;
        }
    } else {
        void** ppvStack_38 = &local_1c;
        iVar2 = 0;
        (*(void (**)(void))(*(char**)stream + 8))();
        while (in_EBX != 0) {
            in_EBX = in_EBX - 1;
            (*(void (**)(void*, int))(*(char**)stream + 8))(&local_4, 1);
            if ((char)local_4 == '\0') {
                FUN_00545cc0();
                iVar2 = iVar2 + 1;
            } else {
                pvStack_18 = nullptr;
                FUN_005460e0(&pvStack_18);
                local_1c = nullptr;
                FUN_005460e0(&local_1c);
                (*(void (**)(void*, int))(*(char**)stream + 8))(auStack_c, 4);
                FUN_0057f7f0((uint32_t)(uintptr_t)local_1c, pvStack_18, auStack_c[0], 0);
                operator_delete__(pvStack_18);
                operator_delete__(local_1c);
            }
        }
        FUN_00545df0(iVar2);
    }

}

// 0x0057fc00 — observed shape
void FUN_0057fc00(void* self) {
    uint32_t* words = (uint32_t*)self;
    int i;

    FUN_005383d0();
    for (i = 3; i <= 0xb; i = i + 1) {
        words[i] = 0;
    }
    words[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c4c50[0];
}

// 0x0057fc30 — observed shape
void FUN_0057fc30(void* self, uint32_t param_1, uint32_t param_2) {
    char* base = (char*)self;
    uint32_t uVar1 = param_2;

    if (*(int*)(base + 0xc) != 0) {
        param_2 = *(uint32_t*)(base + 0x10);
        FUN_00576640(2, *(uint32_t*)(base + 0x14), &param_2, base + 0xc, param_1, uVar1);
        *(uint32_t*)(base + 0x10) = param_2;
    }
    if (*(int*)(base + 0x18) != 0) {
        param_2 = *(uint32_t*)(base + 0x1c);
        FUN_00576640(1, *(uint32_t*)(base + 0x20), &param_2, base + 0x18, param_1, uVar1);
        *(uint32_t*)(base + 0x1c) = param_2;
    }
    if (*(int*)(base + 0x24) != 0) {
        param_2 = *(uint32_t*)(base + 0x28);
        FUN_00576640(0, *(uint32_t*)(base + 0x2c), &param_2, base + 0x24, param_1, uVar1);
        *(uint32_t*)(base + 0x28) = param_2;
    }
}

// 0x0057fd30 — observed shape
void FUN_0057fd30(void* self, int param_1, int param_2, uint32_t param_3) {
    char* base = (char*)self;

    if (*(int*)(base + 0x1c) != 0) {
        (*(void (**)(int))(&DAT_007284fc[*(int*)(base + 0x20) * 4]))(*(int*)(base + 0x1c));
    }
    if ((param_1 == 0) || (param_2 == 0)) {
        *(uint32_t*)(base + 0x18) = 0;
        *(uint32_t*)(base + 0x1c) = 0;
        *(uint32_t*)(base + 0x20) = 0;
        return;
    }
    *(int*)(base + 0x18) = param_2;
    *(int*)(base + 0x1c) = param_1;
    *(uint32_t*)(base + 0x20) = param_3;
}

// 0x0057fed0 — observed shape
void FUN_0057fed0(void* self) {
    uint32_t* words = (uint32_t*)self;
    uint32_t iVar1 = words[4];

    words[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c4c50[0];
    if (iVar1 != 0) {
        if (words[5] == 4) {
            FUN_00569960();
        }
        (*(void (**)(uint32_t))(&DAT_00728510[words[5] * 4]))(iVar1);
    }
    if (words[7] != 0) {
        (*(void (**)(uint32_t))(&DAT_007284fc[words[8] * 4]))(words[7]);
    }
    if (words[10] != 0) {
        (*(void (**)(uint32_t))(&DAT_007284e8[words[0xb] * 4]))(words[10]);
    }
    FUN_00538400();
}

// 0x0057ff30 — observed shape
void FUN_0057ff30(void* self, int param_1, int param_2, uint32_t param_3) {
    char* base = (char*)self;
    int iVar1 = *(int*)(base + 0x10);

    if (iVar1 != 0) {
        if (*(int*)(base + 0x14) == 4) {
            FUN_00569960();
        }
        (*(void (**)(int))(&DAT_00728510[*(int*)(base + 0x14) * 4]))(iVar1);
    }
    if ((param_1 == 0) || (param_2 == 0)) {
        *(uint32_t*)(base + 0xc) = 0;
        *(uint32_t*)(base + 0x10) = 0;
        *(uint32_t*)(base + 0x14) = 0;
        return;
    }
    *(int*)(base + 0x10) = param_1;
    *(int*)(base + 0xc) = param_2;
    *(uint32_t*)(base + 0x14) = param_3;
}

// 0x005800e0 — observed shape
void FUN_005800e0(void* self, int param_1) {
    char* base = (char*)self;
    void* stream = *(void**)((char*)(uintptr_t)param_1 + 0x160);
    int* p;

    FUN_00538430(param_1);
    p = (int*)(base + 0xc);
    (*(void (**)(int*, int))(*(char**)stream + 0xc))(p, 4);
    if (*p != 0) {
        (*(void (**)(int*, int))(*(char**)stream + 0xc))((int*)(base + 0x14), 4);
        (*(void (**)(int, uint32_t, int))(&DAT_00728678[*(int*)(base + 0x14) * 4]))(
            param_1, *(uint32_t*)(base + 0x10), *p);
    }
    p = (int*)(base + 0x18);
    (*(void (**)(int*, int))(*(char**)stream + 0xc))(p, 4);
    if (*p != 0) {
        (*(void (**)(int*, int))(*(char**)stream + 0xc))((int*)(base + 0x20), 4);
        (*(void (**)(int, uint32_t, int))(&DAT_00728664[*(int*)(base + 0x20) * 4]))(
            param_1, *(uint32_t*)(base + 0x1c), *p);
    }
    p = (int*)(base + 0x24);
    (*(void (**)(int*, int))(*(char**)stream + 0xc))(p, 4);
    if (*p != 0) {
        (*(void (**)(int*, int))(*(char**)stream + 0xc))((int*)(base + 0x2c), 4);
        (*(void (**)(int, uint32_t, int))(&DAT_00728650[*(int*)(base + 0x2c) * 4]))(
            param_1, *(uint32_t*)(base + 0x28), *p);
    }
}

// 0x005801b0 — observed shape
void FUN_005801b0(void* self, uint8_t param_1) {
    FUN_0057fed0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x005802d0 — observed shape
void FUN_005802d0(void* self, float param_1, uint32_t param_2, int param_3) {
    int* words = (int*)self;
    char* node = (char*)(uintptr_t)words[0xd];
    int* renderer = (int*)(uintptr_t)words[0x14];
    float fVar2;
    float fVar3;
    float fVar4;
    float fVar5;
    float fVar6;
    // Locals carried across the FUN_00555f70 calls; the listing does not show
    // their initialization, so they start at zero here.
    float fStack_14 = 0.0f;
    float fStack_10 = 0.0f;
    float fStack_c = 0.0f;
    float fStack_8 = 0.0f;

    if ((uint8_t)param_3 != 0) {
        words[0x15] = *(int*)(node + 0x5c);
        words[0x16] = *(int*)(node + 0x60);
        words[0x17] = *(int*)(node + 100);
        FUN_00555f70(node + 0x38);
        words[0x1c] = *(int*)(node + 0x68);
    }
    ((uint8_t*)self)[0x40] = 1;
    (*(void (**)(float))(*words + 0x3c))(param_1);
    if (param_3 != 0) {
        FUN_0056eed0(param_1);
    }
    fVar2 = *(float*)(node + 0x5c);
    fVar3 = *(float*)(node + 0x60);
    fVar4 = *(float*)(node + 100);
    FUN_00555f70(node + 0x38);
    fVar6 = 1.0f - param_1;
    fVar5 = *(float*)(node + 0x68);
    if (*(int*)((char*)renderer + 0x18) != 0) {
        float fStack_30 = fVar6 * (float)words[0x16];
        float fStack_2c = fVar6 * (float)words[0x17];
        *(float*)(node + 0x5c) = fVar6 * (float)words[0x15] + fVar2 * param_1;
        *(float*)(node + 0x60) = fStack_30 + fVar3 * param_1;
        *(float*)(node + 100) = fStack_2c + fVar4 * param_1;
    }
    if (*(int*)((char*)renderer + 0xc) != 0) {
        float fStack_24 = (float)words[0x18];
        float fStack_20 = (float)words[0x19];
        float fStack_1c = (float)words[0x1a];
        float fStack_18 = (float)words[0x1b];
        if (fStack_14 * fStack_24 + fStack_10 * fStack_20
            + fStack_c * fStack_1c + fStack_8 * fStack_18 < 0.0f) {
            float scratch[4] = {0.0f, 0.0f, 0.0f, 0.0f};
            float* pfVar7 = (float*)FUN_00555b90(scratch);
            fStack_24 = pfVar7[0];
            fStack_20 = pfVar7[1];
            fStack_1c = pfVar7[2];
            fStack_18 = pfVar7[3];
        }
        float outQuat[4] = {0.0f, 0.0f, 0.0f, 0.0f};
        FUN_0055ec90(outQuat, param_1, &fStack_24, &fStack_14);
        FUN_00520da0(node + 0x38);
    }
    if (*(int*)((char*)renderer + 0x24) != 0) {
        float value = fVar5 * param_1 + fVar6 * (float)words[0x1c];
        *(float*)(node + 0x68) = (value < 0.0f) ? -value : value;
    }
}

// 0x005804d0 — observed shape
void FUN_005804d0(void* self, int param_1) {
    int* words = (int*)self;
    uint32_t* fresh;
    uint32_t* puVar2;

    FUN_00553060(param_1);
    fresh = (uint32_t*)FUN_00545600();
    puVar2 = (uint32_t*)(uintptr_t)words[0x14];
    if (puVar2 != fresh) {
        if (puVar2 != nullptr) {
            int* refcount = (int*)puVar2 + 1;
            *refcount = *refcount - 1;
            if (*refcount == 0) {
                (*(void (**)(int))*(void**)puVar2)(1);
            }
        }
        words[0x14] = (int)(intptr_t)fresh;
        if (fresh != nullptr) {
            ((int*)fresh)[1] = ((int*)fresh)[1] + 1;
        }
    }
    if ((words[0x14] != 0) && (*(uint32_t*)((char*)(uintptr_t)param_1 + 0x1c) < 0x401000d)) {
        (*(void (**)(int, int))(*words + 0x54))(words[6], words[7]);
    }
}
