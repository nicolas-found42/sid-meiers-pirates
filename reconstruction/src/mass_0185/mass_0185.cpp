#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_00552e30(uint32_t param_1);
extern void* FUN_00540540(uint32_t param_1);
extern void FUN_005531c0(int param_1);
extern void* FUN_00557b10(void* param_1);
extern void* FUN_00557d80(const char* param_1, uint32_t param_2);
extern void FUN_005606f0(uint32_t param_1, void* param_2);
extern void FUN_006b34a0(intptr_t param_1);
extern int FUN_00533c78(size_t param_1);
extern void FUN_004127b0(void* param_1, size_t param_2, size_t param_3, void* param_4);
extern void FUN_00582700(uint32_t param_1, void* param_2, void* param_3);
extern void FUN_005823b0(float param_1, int param_2, int param_3, uint32_t* param_4);
extern void FUN_005826a0(float param_1, int param_2, uint32_t param_3, uint32_t* param_4);
extern void FUN_005460e0(uint32_t param_1);
extern void FUN_00545950(void* param_1);
extern void FUN_00552d20(void);
extern void FUN_005383d0(void);
extern void FUN_00577d90(void* param_1, int param_2, uint32_t param_3);
extern void FUN_00552aa0(int param_1, uint32_t param_2);
extern void operator_delete__(void* param_1);
extern void operator_delete(void* param_1);
extern void* thunk_FUN_00533c78(size_t param_1);
extern const char* DAT_00728a6c;
extern const char* DAT_00728a74;
extern void* PTR_FUN_006c48d8;
extern void* PTR_FUN_006c4eb0;
extern void* PTR_FUN_006fe39c;
extern void* LAB_005cea70;

// 0x5821d0 — observed shape: release field at +0x48 (refcount decrement, call via vtable if zero, clear), call FUN_00552e30, then if field at +0x34 != 0 acquire via FUN_00540540(field +0x44) and assign to +0x48 with same refcount release/acquire.
void FUN_005821d0(void* self, uint32_t param_1) {
    char* obj = (char*)self;
    uint32_t* field48 = (uint32_t*)(obj + 0x48);
    uint32_t* puVar2 = (uint32_t*)(*(uint32_t*)(obj + 0x48));
    if (puVar2 != nullptr) {
        int* piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) {
            using Func = void(__cdecl*)(int);
            Func fn = (Func)(*(void***)puVar2)[0];
            fn(1);
        }
        *(uint32_t*)(obj + 0x48) = 0;
    }
    FUN_00552e30(param_1);
    if (*(int*)(obj + 0x34) != 0) {
        uint32_t* puVar3 = (uint32_t*)FUN_00540540(*(uint32_t*)(obj + 0x44));
        puVar2 = (uint32_t*)(*(uint32_t*)(obj + 0x48));
        if (puVar2 != puVar3) {
            if (puVar2 != nullptr) {
                int* piVar1 = (int*)(puVar2 + 1);
                *piVar1 = *piVar1 - 1;
                if (*piVar1 == 0) {
                    using Func = void(__cdecl*)(int);
                    Func fn = (Func)(*(void***)puVar2)[0];
                    fn(1);
                }
            }
            *(uint32_t**)(obj + 0x48) = puVar3;
            if (puVar3 != nullptr) {
                puVar3[1] = puVar3[1] + 1;
            }
        }
    }
}

// 0x582320 — observed shape: self=param_1 wrapped in struct with count at +8, index at +0xc, base at +0x14; calls FUN_005531c0, formats two fields via FUN_00557b10/FUN_00557d80 + bounds check FUN_006b34a0 + FUN_005606f0; receiver in_ECX used for +0x44.
void FUN_00582320(void* self, int param_1) {
    int iVar2 = param_1;
    FUN_005531c0(param_1);
    void* param1 = FUN_00557b10((void*)DAT_00728a6c);
    char* obj = (char*)self;
    (void)obj;
    uint32_t uVar1 = *(uint32_t*)(iVar2 + 0xc);
    if (*(uint32_t*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &param1);
    void* in_ECX_self = self;
    param1 = FUN_00557d80("Extra Data Name", *(uint32_t*)((char*)in_ECX_self + 0x44));
    uVar1 = *(uint32_t*)(iVar2 + 0xc);
    if (*(uint32_t*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &param1);
}

// 0x5823b0 — observed shape: binary-search-like lower_bound over stride-8 table at param_2 (key float at offset 0, tag byte at offset 4) with hint *param_4; single-element fast path; returns tag byte.
uint8_t FUN_005823b0(float param_1, int param_2, int param_3, uint32_t* param_4) {
    uint32_t uVar1;
    if (param_3 == 1) {
        return *(uint8_t*)(param_2 + 4);
    }
    if (param_1 < *(float*)(param_2 + (int)(*param_4) * 8)) {
        *param_4 = 0;
    }
    uVar1 = *param_4;
    while (true) {
        uVar1 = uVar1 + 1;
        if ((uint32_t)(param_3 - 1) < uVar1) {
            return *(uint8_t*)(param_2 + 4 + (param_3 - 1) * 8);
        }
        if (param_1 < *(float*)(param_2 + (int)uVar1 * 8)) break;
        *param_4 = *param_4 + 1;
    }
    return *(uint8_t*)(param_2 + 4 + (int)(*param_4) * 8);
}

// 0x582420 — observed shape: range filter over stride-8 table (float key at 0, byte tag at 4) counting entries with param_3 <= key and param_4 >= key; allocates output via thunk and fills (key-param_3, tag) pairs; unrolled by 4 with early-exit goto on param_4 < key.
void FUN_00582420(int param_1, uint32_t param_2, float param_3, float param_4, int* param_5, int* param_6) {
    uint32_t uVar2 = 0;
    *param_6 = 0;
    if (3 < (int)param_2) {
        float* pfVar4 = (float*)(param_1 + 0x10);
        do {
            if (param_3 <= pfVar4[-4]) {
                if (param_4 < pfVar4[-4]) goto LAB_005824f5;
                *param_6 = *param_6 + 1;
            }
            if (param_3 <= pfVar4[-2]) {
                if (param_4 < pfVar4[-2]) goto LAB_005824f5;
                *param_6 = *param_6 + 1;
            }
            if (param_3 <= *pfVar4) {
                if (param_4 < *pfVar4) goto LAB_005824f5;
                *param_6 = *param_6 + 1;
            }
            if (param_3 <= pfVar4[2]) {
                if (param_4 < pfVar4[2]) goto LAB_005824f5;
                *param_6 = *param_6 + 1;
            }
            uVar2 = uVar2 + 4;
            pfVar4 = pfVar4 + 8;
        } while (uVar2 < param_2 - 3);
    }
    for (; uVar2 < param_2; uVar2 = uVar2 + 1) {
        if (param_3 <= *(float*)(param_1 + (int)uVar2 * 8)) {
            if (param_4 < *(float*)(param_1 + (int)uVar2 * 8)) break;
            *param_6 = *param_6 + 1;
        }
    }
LAB_005824f5:
    if (*param_6 == 0) {
        *param_5 = 0;
        return;
    }
    int iVar1 = thunk_FUN_00533c78((size_t)(*param_6) * 8);
    uVar2 = 0;
    *param_5 = iVar1;
    *param_6 = 0;
    if (3 < (int)param_2) {
        uint8_t* puVar3 = (uint8_t*)(param_1 + 0x14);
        do {
            if (param_3 <= *(float*)(puVar3 - 0x14)) {
                if (param_4 < *(float*)(puVar3 - 0x14)) {
                    return;
                }
                float* pfVar4 = (float*)(*param_5 + *param_6 * 8);
                *pfVar4 = *(float*)(puVar3 - 0x14);
                *(uint8_t*)(pfVar4 + 1) = puVar3[-0x10];
                *pfVar4 = *pfVar4 - param_3;
                *param_6 = *param_6 + 1;
            }
            if (param_3 <= *(float*)(puVar3 - 0xc)) {
                if (param_4 < *(float*)(puVar3 - 0xc)) {
                    return;
                }
                float* pfVar4 = (float*)(*param_5 + *param_6 * 8);
                *pfVar4 = *(float*)(puVar3 - 0xc);
                *(uint8_t*)(pfVar4 + 1) = puVar3[-8];
                *pfVar4 = *pfVar4 - param_3;
                *param_6 = *param_6 + 1;
            }
            if (param_3 <= *(float*)(puVar3 - 4)) {
                if (param_4 < *(float*)(puVar3 - 4)) {
                    return;
                }
                float* pfVar4 = (float*)(*param_5 + *param_6 * 8);
                *pfVar4 = *(float*)(puVar3 - 4);
                *(uint8_t*)(pfVar4 + 1) = *puVar3;
                *pfVar4 = *pfVar4 - param_3;
                *param_6 = *param_6 + 1;
            }
            if (param_3 <= *(float*)(puVar3 + 4)) {
                if (param_4 < *(float*)(puVar3 + 4)) {
                    return;
                }
                float* pfVar4 = (float*)(*param_5 + *param_6 * 8);
                *pfVar4 = *(float*)(puVar3 + 4);
                *(uint8_t*)(pfVar4 + 1) = puVar3[8];
                *pfVar4 = *pfVar4 - param_3;
                *param_6 = *param_6 + 1;
            }
            uVar2 = uVar2 + 4;
            puVar3 = puVar3 + 0x20;
        } while (uVar2 < param_2 - 3);
    }
    do {
        if (param_2 <= uVar2) {
            return;
        }
        if (param_3 <= *(float*)(param_1 + (int)uVar2 * 8)) {
            if (param_4 < *(float*)(param_1 + (int)uVar2 * 8)) {
                return;
            }
            float* pfVar4 = (float*)(*param_5 + *param_6 * 8);
            *pfVar4 = *(float*)(param_1 + (int)uVar2 * 8);
            *(uint8_t*)(pfVar4 + 1) = *(uint8_t*)(param_1 + 4 + (int)uVar2 * 8);
            *pfVar4 = *pfVar4 - param_3;
            *param_6 = *param_6 + 1;
        }
        uVar2 = uVar2 + 1;
    } while (true);
}

// 0x5826a0 — observed shape: linear scan with hint reset; returns 1 if param_1 < entry (strict), 0 if == entry, 1 if past end / empty.
uint16_t FUN_005826a0(float param_1, int param_2, uint32_t param_3, uint32_t* param_4) {
    uint32_t uVar1;
    *param_4 = 0;
    if (param_3 == 0) {
        return 1;
    }
    do {
        uVar1 = *param_4;
        if (param_1 <= *(float*)(param_2 + (int)uVar1 * 8)) {
            if (param_1 < *(float*)(param_2 + (int)uVar1 * 8)) {
                return 1;
            }
            return 0;
        }
        *param_4 = uVar1 + 1;
    } while (uVar1 + 1 < param_3);
    return 1;
}

// 0x582700 — observed shape: sorted-insert into stride-8 table via FUN_005826a0 lower_bound; allocate (n+1)*8, memcpy head/tail (16-byte blocks for aligned part), append (param_1, tag from FUN_005823b0) at old count, increment count, free old table; returns 0/1.
int FUN_00582700(uint32_t param_1, void* self, void* param_2) {
    (void)self;
    int* pCount = (int*)param_2;
    uint32_t local_4 = 0;
    char cVar2 = (char)FUN_005826a0(*(float*)&param_1, *(int*)pCount, *(uint32_t*)((char*)param_2 + 4), &local_4);
    if (cVar2 == '\0') {
        return 0;
    }
    uint32_t uVar1 = *(uint32_t*)((char*)param_2 + 4);
    uint32_t* puVar4 = (uint32_t*)thunk_FUN_00533c78((uVar1 + 1) * 8);
    if (puVar4 == nullptr) {
        puVar4 = nullptr;
    } else {
        FUN_004127b0(puVar4, 8, uVar1 + 1, &LAB_005cea70);
    }
    uint32_t insertPos = local_4;
    uint32_t* puVar6 = (uint32_t*)(*(int*)pCount);
    uint32_t* puVar7 = puVar4;
    int iVar5 = (int)((local_4 & 0x1fffffff) << 1);
    for (; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(uint8_t*)puVar7 = *(uint8_t*)puVar6;
        puVar6 = (uint32_t*)((intptr_t)puVar6 + 1);
        puVar7 = (uint32_t*)((intptr_t)puVar7 + 1);
    }
    if (local_4 < *(uint32_t*)((char*)param_2 + 4)) {
        puVar6 = (uint32_t*)(*(int*)pCount + (int)local_4 * 8);
        puVar7 = puVar4 + (int)local_4 * 2 + 2;
        for (iVar5 = (int)((*(uint32_t*)((char*)param_2 + 4) - local_4 & 0x1fffffff) << 1); iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar7 = puVar7 + 1;
        }
    }
    local_4 = 0;
    uint8_t uVar3 = (uint8_t)FUN_005823b0(*(float*)&param_1, *(int*)pCount, *(int*)((char*)param_2 + 4), &local_4);
    puVar4[uVar1 * 2] = param_1;
    *(uint8_t*)(puVar4 + uVar1 * 2 + 1) = uVar3;
    *(uint32_t*)((char*)param_2 + 4) = *(uint32_t*)((char*)param_2 + 4) + 1;
    operator_delete__((void*)(*(int*)pCount));
    *(int*)pCount = (int)(intptr_t)puVar4;
    (void)insertPos;
    return 1;
}

// 0x582800 — observed shape: vtable dispatch at *(int**)(param_1+0x15c)+8 twice, second with stack buffer +0xc,1; sets byte at self+4 to 1; receiver self.
void FUN_00582800(int param_1) {
    void* self = nullptr;
    uint8_t auStack_10[8];
    using Func0 = void(__thiscall*)(void*);
    using Func1 = void(__thiscall*)(void*, void*, int);
    void** vtbl = *(void***)(*(int*)(param_1 + 0x15c));
    Func0 fn0 = (Func0)vtbl[1];
    fn0(*(void**)(param_1 + 0x15c));
    void** vtbl2 = *(void***)(*(int*)(param_1 + 0x15c));
    Func1 fn1 = (Func1)vtbl2[1];
    fn1(*(void**)(param_1 + 0x15c), auStack_10 + 0xc, 1);
    *(uint8_t*)((char*)self + 4) = 1;
}

// 0x582840 — observed shape: vtable dispatch at *(int**)(param_1+0x160)+0xc twice, second with stack buffer +0xc,1.
void FUN_00582840(int param_1) {
    uint8_t auStack_10[8];
    using Func0 = void(__thiscall*)(void*);
    using Func1 = void(__thiscall*)(void*, void*, int);
    void** vtbl = *(void***)(*(int*)(param_1 + 0x160));
    Func0 fn0 = (Func0)vtbl[1];
    fn0(*(void**)(param_1 + 0x160));
    void** vtbl2 = *(void***)(*(int*)(param_1 + 0x160));
    Func1 fn1 = (Func1)vtbl2[1];
    fn1(*(void**)(param_1 + 0x160), auStack_10 + 0xc, 1);
}

// 0x582880 — observed shape: if size != 1 or first key != param_3, insert both param_3 and param_4 via FUN_00582700.
void FUN_00582880(uint32_t* param_1, int* param_2, float param_3, uint32_t param_4) {
    if ((*param_2 != 1) || (*(float*)*param_1 != param_3)) {
        FUN_00582700(*(uint32_t*)&param_3, param_1, param_2);
        FUN_00582700(param_4, param_1, param_2);
    }
}

// 0x5828c0 — observed shape: free pointer at self+4 if non-null; receiver self.
void FUN_005828c0(void* self) {
    void** field4 = (void**)((char*)self + 4);
    if (*field4 != nullptr) {
        operator_delete__(*field4);
    }
}

// 0x5828d0 — observed shape: free old string at self+4 (clear), then if param_1 non-null allocate via thunk, copy including NUL; receiver self.
void FUN_005828d0(void* self, char* param_1) {
    char** field4 = (char**)((char*)self + 4);
    if (*field4 != nullptr) {
        operator_delete__(*field4);
        *(uint32_t*)((char*)self + 4) = 0;
    }
    if (param_1 != nullptr) {
        char* pcVar2 = param_1;
        char cVar1;
        do {
            cVar1 = *pcVar2;
            pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        pcVar2 = (char*)thunk_FUN_00533c78((size_t)(pcVar2 + (1 - (int)(intptr_t)(param_1 + 1))));
        *(char**)((char*)self + 4) = pcVar2;
        do {
            cVar1 = *param_1;
            param_1 = param_1 + 1;
            *pcVar2 = cVar1;
            pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
    }
}

// 0x582930 — observed shape: vtable call at *(int**)(param_1+0x15c)+8, then FUN_005460e0(self+4); receiver self.
void FUN_00582930(int param_1) {
    void* self = nullptr;
    using Func0 = void(__thiscall*)(void*);
    void** vtbl = *(void***)(*(int*)(param_1 + 0x15c));
    Func0 fn0 = (Func0)vtbl[1];
    fn0(*(void**)(param_1 + 0x15c));
    FUN_005460e0((uint32_t)(intptr_t)((char*)self + 4));
}

// 0x582960 — observed shape: vtable call at *(int**)(param_1+0x160)+0xc, then FUN_00545950(field self+4); receiver self.
void FUN_00582960(int param_1) {
    void* self = nullptr;
    using Func0 = void(__thiscall*)(void*);
    void** vtbl = *(void***)(*(int*)(param_1 + 0x160));
    Func0 fn0 = (Func0)vtbl[1];
    fn0(*(void**)(param_1 + 0x160));
    FUN_00545950((void*)(*(uint32_t*)((char*)self + 4)));
}

// 0x5829b0 — observed shape: set vtable at self to PTR_FUN_006c48d8, release refcount object at index 0x12 twice (second without clear), call FUN_00552d20; receiver self as uint32_t array.
void FUN_005829b0(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    *in_ECX = (uint32_t)(intptr_t)PTR_FUN_006c48d8;
    uint32_t* puVar2 = (uint32_t*)(in_ECX[0x12]);
    if (puVar2 != nullptr) {
        int* piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) {
            using Func = void(__cdecl*)(int);
            Func fn = (Func)(*(void***)puVar2)[0];
            fn(1);
        }
        in_ECX[0x12] = 0;
    }
    puVar2 = (uint32_t*)(in_ECX[0x12]);
    if (puVar2 != nullptr) {
        int* piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) {
            using Func = void(__cdecl*)(int);
            Func fn = (Func)(*(void***)puVar2)[0];
            fn(1);
        }
    }
    FUN_00552d20();
}

// 0x5829f0 — observed shape: read object at self+0x48; if null zero outputs and return 0; else outputs = fields at +0xc/+0x14 and return field at +0x10; receiver self.
uint32_t FUN_005829f0(void* self, uint32_t* param_1, uint32_t* param_2) {
    int iVar1 = *(int*)((char*)self + 0x48);
    if (iVar1 == 0) {
        *param_1 = 0;
        *param_2 = 0;
        return 0;
    }
    *param_1 = *(uint32_t*)(iVar1 + 0xc);
    *param_2 = *(uint32_t*)(iVar1 + 0x14);
    return *(uint32_t*)(iVar1 + 0x10);
}

// 0x582a30 — observed shape: if self+0x48 null, allocate 0x18 object with vtable PTR_FUN_006fe39c and zero fields, refcount-assign to +0x48; call FUN_00577d90, clear +0x44, copy *param_2 to +0x18 and indexed byte to +0x1c; receiver self.
void FUN_00582a30(void* self, int param_1, uint32_t* param_2, uint32_t param_3) {
    if (*(int*)((char*)self + 0x48) == 0) {
        uint32_t* puVar3 = (uint32_t*)FUN_00533c78(0x18);
        if (puVar3 == nullptr) {
            puVar3 = nullptr;
        } else {
            FUN_005383d0();
            *puVar3 = (uint32_t)(intptr_t)PTR_FUN_006fe39c;
            puVar3[3] = 0;
            puVar3[4] = 0;
            puVar3[5] = 0;
        }
        uint32_t* puVar2 = *(uint32_t**)((char*)self + 0x48);
        if (puVar2 != puVar3) {
            if (puVar2 != nullptr) {
                int* piVar1 = (int*)(puVar2 + 1);
                *piVar1 = *piVar1 - 1;
                if (*piVar1 == 0) {
                    using Func = void(__cdecl*)(int);
                    Func fn = (Func)(*(void***)puVar2)[0];
                    fn(1);
                }
            }
            *(uint32_t**)((char*)self + 0x48) = puVar3;
            if (puVar3 != nullptr) {
                puVar3[1] = puVar3[1] + 1;
            }
        }
    }
    FUN_00577d90(param_2, param_1, param_3);
    *(uint32_t*)((char*)self + 0x44) = 0;
    *(uint32_t*)((char*)self + 0x18) = *param_2;
    *(uint32_t*)((char*)self + 0x1c) =
         *(uint32_t*)((uint32_t)(*(uint8_t*)(param_2 + 1)) * (uint32_t)(param_1 - 1) + (int)(intptr_t)param_2);
}

// 0x582b50 — observed shape: FUN_00552aa0 then refcount-assign result of vtable call at self+0x48+8 to param_1+0x48; receiver self.
void FUN_00582b50(void* self, int param_1, uint32_t param_2) {
    FUN_00552aa0(param_1, param_2);
    using Func = uint32_t*(__thiscall*)(void*, uint32_t);
    void** vtbl = *(void***)((char*)self + 0x48);
    Func fn = (Func)vtbl[1];
    uint32_t* puVar3 = fn((void*)(*(uint32_t*)((char*)self + 0x48)), param_2);
    uint32_t* puVar2 = *(uint32_t**)(param_1 + 0x48);
    if (puVar2 != puVar3) {
        if (puVar2 != nullptr) {
            int* piVar1 = (int*)(puVar2 + 1);
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) {
                using Func2 = void(__cdecl*)(int);
                Func2 fn2 = (Func2)(*(void***)puVar2)[0];
                fn2(1);
            }
        }
        *(uint32_t**)(param_1 + 0x48) = puVar3;
        if (puVar3 != nullptr) {
            puVar3[1] = puVar3[1] + 1;
        }
    }
}

// 0x582ba0 — observed shape: FUN_005531c0, format via FUN_00557b10(DAT_00728a74), bounds check FUN_006b34a0, emit via FUN_005606f0.
void FUN_00582ba0(int param_1) {
    FUN_005531c0(param_1);
    void* param_1_v = FUN_00557b10((void*)DAT_00728a74);
    uint32_t uVar1 = *(uint32_t*)(param_1 + 0xc);
    if (*(uint32_t*)(param_1 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(param_1 + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &param_1_v);
}

// 0x582f20 — observed shape: set vtable to PTR_FUN_006c4eb0, delete word at self+4, if param_1 & 1 delete self; receiver self.
void FUN_00582f20(void* self, uint8_t param_1) {
    *(void**)self = PTR_FUN_006c4eb0;
    operator_delete__((void*)(((uint32_t*)self)[1]));
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x582f50 — observed shape: zero/init 12-word struct at self with vtable PTR_FUN_006c4eb0 at index 6, flags at bytes +0x35..0x37, then release refcount object at index 5; receiver self as uint32_t array.
void FUN_00582f50(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    in_ECX[5] = 0;
    in_ECX[6] = (uint32_t)(intptr_t)PTR_FUN_006c4eb0;
    in_ECX[8] = 0;
    in_ECX[0xb] = 1;
    in_ECX[9] = 0;
    in_ECX[10] = 0;
    in_ECX[7] = 0;
    *in_ECX = 0;
    in_ECX[1] = 0;
    in_ECX[2] = 1;
    in_ECX[3] = 1;
    *(uint8_t*)(in_ECX + 4) = 1;
    *(uint8_t*)((intptr_t)in_ECX + 0x11) = 0;
    uint32_t* puVar2 = (uint32_t*)(in_ECX[5]);
    if (puVar2 != nullptr) {
        int* piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) {
            using Func = void(__cdecl*)(int);
            Func fn = (Func)(*(void***)puVar2)[0];
            fn(1);
        }
        in_ECX[5] = 0;
    }
    *(uint8_t*)(in_ECX + 0xd) = 0;
    *(uint8_t*)((intptr_t)in_ECX + 0x35) = 0;
    *(uint8_t*)((intptr_t)in_ECX + 0x36) = 0;
    *(uint8_t*)((intptr_t)in_ECX + 0x37) = 0;
    in_ECX[0xc] = 0;
}
