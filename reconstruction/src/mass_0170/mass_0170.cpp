#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void* PTR_FUN_006c3e98;
extern void* PTR_FUN_007115f4;
extern void* PTR_FUN_0070d044;
extern void* PTR_FUN_0070d024;
extern uint32_t DAT_00727430;
extern uint32_t DAT_00727434;
extern uint32_t DAT_00727438;
extern uint32_t DAT_007179b0;
extern void FUN_005383d0();
extern void FUN_006b34a0(uint32_t param_1);
extern void FUN_0057a3f0(uint32_t param_1);
extern void FUN_005bbe20(uint32_t param_1);
extern void FUN_0056e700();
extern void FUN_0056f540();
extern void FUN_00538400();
extern void FUN_004c2b10();
extern void operator_delete__(void* ptr);

// 0x56f540 — observed shape
void FUN_0056f540_recon(void* self) {
    uint32_t count = *(uint32_t*)((uint8_t*)self + 0xc);
    if (count != 0) {
        uint32_t idx = 0;
        do {
            int* array = *(int**)((uint8_t*)self + 4);
            uint32_t* item = *(uint32_t**)(array + idx * 4);
            if (item != nullptr) {
                int* refcnt = (int*)(item + 1);
                *refcnt = *refcnt + -1;
                if (*refcnt == 0) {
                    void* vtable = *(void**)item;
                    void (*deleter)(uint32_t) = *(void (**)(uint32_t))*(uint8_t**)vtable;
                    deleter(1);
                }
                *(uint32_t*)(array + idx * 4) = 0;
            }
            idx = idx + 1;
        } while (idx < *(uint32_t*)((uint8_t*)self + 0xc));
    }
    *(uint32_t*)((uint8_t*)self + 0xc) = 0;
    *(uint32_t*)((uint8_t*)self + 0x10) = 0;
}

// 0x56f580 — observed shape
void FUN_0056f580_recon(void* self) {
    FUN_005383d0();
    uint32_t* o = (uint32_t*)self;
    o[0] = (uint32_t)(uintptr_t)PTR_FUN_006c3e98;
    o[3] = 0;
    o[4] = 0;
    o[5] = (uint32_t)(uintptr_t)PTR_FUN_007115f4;
    o[7] = 0;
    o[8] = 0;
    o[9] = 0;
    o[6] = 0;
    o[10] = 1;
    o[0x10] = 1;
    o[0xb] = (uint32_t)(uintptr_t)PTR_FUN_0070d044;
    o[0xd] = 0;
    o[0xe] = 0;
    o[0xf] = 0;
    o[0xc] = 0;
    o[0x16] = 1;
    o[0x11] = (uint32_t)(uintptr_t)PTR_FUN_0070d024;
    o[0x13] = 0;
    o[0x14] = 0;
    o[0x15] = 0;
    o[0x12] = 0;
    o[0x17] = 0;
    o[0x18] = 0;
    o[0x19] = 0xff7fffff;
    o[0x1a] = 0xff7fffff;
    o[0x1b] = 0xff7fffff;
    *(uint8_t*)((uint8_t*)o + 0x1d * 4) = 0;
    o[0x1c] = 0xff7fffff;
    o[0x23] = 1;
    o[0x1e] = (uint32_t)(uintptr_t)PTR_FUN_0070d044;
    o[0x20] = 0;
    o[0x21] = 0;
    o[0x22] = 0;
    o[0x1f] = 0;
    o[0x24] = 0;
    *(uint8_t*)((uint8_t*)o + 0x26 * 4) = 0;
    o[0x25] = 0xff7fffff;
    o[0x27] = 0;
    *(uint8_t*)((uint8_t*)o + 0x28 * 4) = 0;
    o[0x2a] = 0;
    o[0x29] = 0xff7fffff;
    o[0x2b] = 0;
    uint32_t* src = &DAT_007179b0;
    uint32_t* dst = o + 0x2c;
    for (int i = 9; i != 0; i = i + -1) {
        *dst = *src;
        src = src + 1;
        dst = dst + 1;
    }
    o[0x35] = DAT_00727430;
    o[0x36] = DAT_00727434;
    o[0x37] = DAT_00727438;
    src = &DAT_007179b0;
    dst = o + 0x38;
    for (int i = 9; i != 0; i = i + -1) {
        *dst = *src;
        src = src + 1;
        dst = dst + 1;
    }
    o[0x41] = DAT_00727430;
    o[0x42] = DAT_00727434;
    o[0x43] = DAT_00727438;
    FUN_006b34a0(0);
    o[10] = 0xc;
    FUN_0057a3f0(0);
    o[0x10] = 0xc;
    FUN_006b34a0(0);
    o[0x16] = 0xc;
}

// 0x56f720 — observed shape
void FUN_0056f720_recon(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3) {
    FUN_005383d0();
    uint32_t* o = (uint32_t*)self;
    o[0] = (uint32_t)(uintptr_t)PTR_FUN_006c3e98;
    o[3] = 0;
    o[4] = 0;
    o[5] = (uint32_t)(uintptr_t)PTR_FUN_007115f4;
    o[7] = 0;
    o[8] = 0;
    o[9] = 0;
    o[6] = 0;
    o[10] = 1;
    o[0x10] = 1;
    o[0xb] = (uint32_t)(uintptr_t)PTR_FUN_0070d044;
    o[0xd] = 0;
    o[0xe] = 0;
    o[0xf] = 0;
    o[0xc] = 0;
    o[0x16] = 1;
    o[0x11] = (uint32_t)(uintptr_t)PTR_FUN_0070d024;
    o[0x13] = 0;
    o[0x14] = 0;
    o[0x15] = 0;
    o[0x12] = 0;
    o[0x17] = 0;
    o[0x18] = 0;
    o[0x19] = 0xff7fffff;
    o[0x1a] = 0xff7fffff;
    o[0x1b] = 0xff7fffff;
    *(uint8_t*)((uint8_t*)o + 0x1d * 4) = 0;
    o[0x1c] = 0xff7fffff;
    o[0x23] = 1;
    o[0x1e] = (uint32_t)(uintptr_t)PTR_FUN_0070d044;
    o[0x20] = 0;
    o[0x21] = 0;
    o[0x22] = 0;
    o[0x1f] = 0;
    o[0x24] = 0;
    *(uint8_t*)((uint8_t*)o + 0x26 * 4) = 0;
    o[0x25] = 0xff7fffff;
    o[0x27] = 0;
    *(uint8_t*)((uint8_t*)o + 0x28 * 4) = 0;
    o[0x2a] = 0;
    o[0x29] = 0xff7fffff;
    o[0x2b] = 0;
    uint32_t* src = &DAT_007179b0;
    uint32_t* dst = o + 0x2c;
    for (int i = 9; i != 0; i = i + -1) {
        *dst = *src;
        src = src + 1;
        dst = dst + 1;
    }
    o[0x35] = DAT_00727430;
    o[0x36] = DAT_00727434;
    o[0x37] = DAT_00727438;
    src = &DAT_007179b0;
    dst = o + 0x38;
    for (int i = 9; i != 0; i = i + -1) {
        *dst = *src;
        src = src + 1;
        dst = dst + 1;
    }
    o[0x41] = DAT_00727430;
    o[0x42] = DAT_00727434;
    o[0x43] = DAT_00727438;
    FUN_005bbe20(param_1);
    FUN_006b34a0(param_2);
    o[10] = param_3;
    FUN_0057a3f0(param_2);
    o[0x10] = param_3;
    FUN_006b34a0(0);
    o[0x16] = param_3;
}

// 0x56f8c0 — observed shape
void FUN_0056f8c0_recon(void* self) {
    uint32_t* o = (uint32_t*)self;
    o[0] = (uint32_t)(uintptr_t)PTR_FUN_006c3e98;
    operator_delete__((void*)(uintptr_t)o[3]);
    FUN_0056e700();
    FUN_0056f540();
    operator_delete__((void*)(uintptr_t)o[0x2a]);
    FUN_004c2b10();
    o[0x11] = (uint32_t)(uintptr_t)PTR_FUN_0070d024;
    operator_delete__((void*)(uintptr_t)o[0x12]);
    FUN_004c2b10();
    o[5] = (uint32_t)(uintptr_t)PTR_FUN_007115f4;
    operator_delete__((void*)(uintptr_t)o[6]);
    uint32_t* item = (uint32_t*)(uintptr_t)o[4];
    if (item != nullptr) {
        int* refcnt = (int*)(item + 1);
        *refcnt = *refcnt + -1;
        if (*refcnt == 0) {
            void* vtable = *(void**)item;
            void (*deleter)(uint32_t) = *(void (**)(uint32_t))*(uint8_t**)vtable;
            deleter(1);
        }
    }
    FUN_00538400();
}

extern "C" char* strchr(const char* s, int c);
extern "C" int strcmp(const char* a, const char* b);
extern "C" int sprintf(char* buffer, const char* format, ...);
extern void* FUN_00533c78(int size);
extern void* thunk_FUN_00533c78(uint32_t size);
extern void FUN_005606f0(uint32_t param_1, void* param_2);
extern void FUN_0056eb30();
extern void FUN_0056ee20(uint32_t param_1);
extern void FUN_0056e810(uint32_t param_1);
extern uint32_t FUN_0056e790();
extern void FUN_0056e940(uint32_t param_1);
extern void FUN_0056e6a0(uint32_t param_1);
extern void FUN_0056eed0(float param_1);
extern void FUN_0056e8c0(void* param_1);
extern void FUN_0056f060(float param_1, float param_2, float param_3);
extern double FUN_0056f230(void* self, float param_1);
extern int FUN_00552ec0(uint32_t param_1);
extern void FUN_00573bd0(void* param_1, void* param_2);
extern void FUN_00573d80(void* param_1, void* param_2);
extern void FUN_00573b60(void* param_1, float param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5);
extern void FUN_00574540(void* param_1, uint32_t param_2, uint32_t param_3);
extern void FUN_005741f0(void* param_1, void* param_2);
extern void FUN_005802d0(float param_1, float param_2, uint8_t param_3, void* param_4);
extern void FUN_00581300(uint32_t param_1, void* param_2);
extern void FUN_00538410(void* param_1, uint32_t param_2);
extern void* FUN_00538680();
extern void* FUN_00449390(void* param_1, uint32_t param_2);
extern void FUN_0057b9e0(void* param_1, void* param_2, void* param_3, uint32_t param_4);
extern double FUN_00506aa0();
extern double FUN_004c3100();
extern void operator_delete(void* ptr);
extern uint32_t DAT_00728a3c;
extern uint32_t DAT_007273fc;
extern uint32_t DAT_007283cc;

// 0x56f950 — observed shape
// Reads a two/three line record ("name\nPROP\n<prop name>") into a lookup, resolves the
// resulting object in the PROP list, records it in the vector at self+0x44 and finally
// asks the caller-supplied object for the name at self+0xa8. Returns the high byte of the
// uninitialized EBX register (see the corpus tail).
char FUN_0056f950_recon(void* self, int* param_1, uint32_t unaff_EBX) {
    uintptr_t selfAddr = (uintptr_t)self;
    if (param_1 == nullptr || *(int*)(selfAddr + 0x20) == 0) {
        return 0;
    }
    int base44 = (int)(selfAddr + 0x44);
    FUN_006b34a0(*(uint32_t*)(selfAddr + 0x38));
    uint32_t uVar12 = 0;
    uint32_t local_31c;
    if (*(int*)(selfAddr + 0x50) != 0) {
        local_31c = 0;
        do {
            FUN_005606f0(uVar12, &local_31c);
            uVar12 = uVar12 + 1;
        } while (uVar12 < *(uint32_t*)(selfAddr + 0x50));
    }
    local_31c = 0;
    if (*(int*)(selfAddr + 0x38) != 0) {
        do {
            char local_208[260];
            char local_30c[260];
            char local_104[260];
            char* pcVar5 = *(char**)(*(int*)(selfAddr + 0x18) + local_31c * 4);
            uVar12 = local_31c;
            if (pcVar5 != nullptr && *(int*)(*(int*)(selfAddr + 0x30) + local_31c * 4) != 0) {
                char* src = pcVar5;
                char* dst = local_208;
                char cVar1;
                do {
                    cVar1 = *src;
                    *dst = cVar1;
                    src = src + 1;
                    dst = dst + 1;
                } while (cVar1 != '\0');
                bool bVar15 = false;
                char* scan = strchr(local_208, 10);
                if (scan != nullptr) {
                    char* src2 = scan + 1;
                    char* dst2 = local_30c;
                    char cVar2;
                    do {
                        cVar2 = *src2;
                        *dst2 = cVar2;
                        src2 = src2 + 1;
                        dst2 = dst2 + 1;
                    } while (cVar2 != '\0');
                    *scan = '\0';
                    char* scan2 = strchr(local_30c, 10);
                    char* src3 = scan2 + 1;
                    char* dst3 = local_104;
                    char cVar3;
                    do {
                        cVar3 = *src3;
                        *dst3 = cVar3;
                        src3 = src3 + 1;
                        dst3 = dst3 + 1;
                    } while (cVar3 != '\0');
                    *scan2 = '\0';
                    bVar15 = true;
                }
                uint8_t* vtable = (uint8_t*)(uintptr_t)*(uint32_t*)param_1;
                void* (*lookup)(char*) = *(void* (**)(char*))(vtable + 0x40);
                int* piStack_318 = (int*)lookup(local_208);
                if (piStack_318 == nullptr) {
                    uVar12 = 0;
                    if (*(int*)(base44 + 0xc) != 0) {
                        do {
                            *(uint32_t*)(*(int*)(base44 + 4) + uVar12 * 4) = 0;
                            uVar12 = uVar12 + 1;
                        } while (uVar12 < *(uint32_t*)(base44 + 0xc));
                    }
                    *(uint32_t*)(base44 + 0xc) = 0;
                    *(uint32_t*)(base44 + 0x10) = 0;
                    if (*(int*)(base44 + 8) == 0) {
                        return 0;
                    }
                    void* pvVar4 = *(void**)(base44 + 4);
                    *(uint32_t*)(base44 + 8) = 0;
                    *(uint32_t*)(base44 + 4) = 0;
                    operator_delete__(pvVar4);
                    return 0;
                }
                if (bVar15) {
                    int iVar11 = 5;
                    bool bEq = true;
                    char* pL = local_30c;
                    const char* pR = "PROP";
                    do {
                        if (iVar11 == 0) break;
                        iVar11 = iVar11 + -1;
                        bEq = *pL == *pR;
                        pL = pL + 1;
                        pR = pR + 1;
                    } while (bEq);
                    if (bEq) {
                        int* piVar14 = (int*)piStack_318[0x29];
                        if (piVar14 != nullptr) {
                            do {
                                int* piVar3 = (int*)piVar14[2];
                                piVar14 = (int*)*piVar14;
                                uint8_t* vt3 = (uint8_t*)(uintptr_t)(uint32_t)*piVar3;
                                uint32_t* (*getName)() = *(uint32_t* (**)())(vt3 + 4);
                                uint32_t* puVar6 = getName();
                                char* name = *(char**)puVar6;
                                int cmp = strcmp(name, local_104);
                                if (cmp == 0) {
                                    piStack_318 = piVar3;
                                    break;
                                }
                            } while (piVar14 != nullptr);
                        }
                    }
                }
                uVar12 = local_31c;
                if (piStack_318 == nullptr) {
                    uVar12 = 0;
                    if (*(int*)(base44 + 0xc) != 0) {
                        do {
                            *(uint32_t*)(*(int*)(base44 + 4) + uVar12 * 4) = 0;
                            uVar12 = uVar12 + 1;
                        } while (uVar12 < *(uint32_t*)(base44 + 0xc));
                    }
                    *(uint32_t*)(base44 + 0xc) = 0;
                    *(uint32_t*)(base44 + 0x10) = 0;
                    if (*(int*)(base44 + 8) == 0) {
                        return 0;
                    }
                    void* pvVar4 = *(void**)(base44 + 4);
                    *(uint32_t*)(base44 + 8) = 0;
                    *(uint32_t*)(base44 + 4) = 0;
                    operator_delete__(pvVar4);
                    return 0;
                }
                FUN_005606f0(local_31c, &piStack_318);
            }
            local_31c = uVar12 + 1;
        } while (local_31c < *(uint32_t*)(selfAddr + 0x38));
    }
    FUN_0056e700();
    if (*(int*)(selfAddr + 0xa8) == 0) {
        return 1;
    }
    uint8_t* vtEnd = (uint8_t*)(uintptr_t)*(uint32_t*)param_1;
    uint32_t (*lookupTime)(uint32_t) = *(uint32_t (**)(uint32_t))(vtEnd + 0x40);
    uint32_t uVar9 = lookupTime(*(uint32_t*)(selfAddr + 0xa8));
    *(uint32_t*)(selfAddr + 0xac) = uVar9;
    FUN_0056eb30();
    return (char)(unaff_EBX >> 0x18);
}

// 0x56fbf0 — observed shape
uint32_t FUN_0056fbf0_recon(void* self, uint32_t param_1, char param_2) {
    uintptr_t selfAddr = (uintptr_t)self;
    if (*(uint32_t*)(selfAddr + 0x60) != 0) {
        return *(uint32_t*)(selfAddr + 0x60) & 0xffffff00u;
    }
    FUN_0056ee20(param_1);
    *(uint8_t*)(selfAddr + 0x98) = 0;
    *(uint32_t*)(selfAddr + 0x9c) = 0;
    uint32_t* puVar3 = nullptr;
    if (*(int*)(selfAddr + 0xac) != 0) {
        char cVar1 = *(char*)(*(int*)(selfAddr + 0x5c) + 0x70);
        puVar3 = (uint32_t*)(uintptr_t)(((uint32_t)*(int*)(selfAddr + 0xac) & 0xffffff00u) |
                                        (uint32_t)(uint8_t)cVar1);
        if (cVar1 != '\0') {
            uint32_t* puVar5 = nullptr;
            puVar3 = nullptr;
            if (*(int*)(selfAddr + 0x38) != 0) {
                do {
                    int* piVar2 = *(int**)(*(int*)(selfAddr + 0x30) + (int)(uintptr_t)puVar5 * 4);
                    if (piVar2 != nullptr && piVar2[0xd] == *(int*)(selfAddr + 0xac)) {
                        for (puVar3 = (uint32_t*)(**(uint32_t* (**)())((uint8_t*)(uintptr_t)(uint32_t)*piVar2 + 4))();
                             puVar3 != nullptr; puVar3 = (uint32_t*)puVar3[1]) {
                            if (puVar3 == &DAT_00728a3c) {
                                *(uint8_t*)(selfAddr + 0x98) = 1;
                                *(uint32_t**)(selfAddr + 0x9c) = puVar5;
                                puVar3 = &DAT_00728a3c;
                                goto lab_56fc86;
                            }
                        }
                    }
                    puVar3 = *(uint32_t**)(selfAddr + 0x38);
                    puVar5 = (uint32_t*)((int)(uintptr_t)puVar5 + 1);
                } while (puVar5 < puVar3);
            }
        }
    }
lab_56fc86:
    if (*(char*)(selfAddr + 0x98) != '\0') {
        *(uint8_t*)(selfAddr + 0xa0) = 1;
        *(uint32_t*)(selfAddr + 0xa4) = 0xff7fffff;
        FUN_00573bd0((void*)(selfAddr + 0xe0), (void*)(selfAddr + 0x104));
    }
    *(uint32_t*)(selfAddr + 0x60) = 1;
    if (param_2 != '\0') {
        *(uint32_t*)(selfAddr + 100) = 0xff7fffff;
    }
    return ((uint32_t)(uintptr_t)puVar3 & 0xffffff00u) | 1;
}

// 0x56fce0 — observed shape
uint8_t FUN_0056fce0_recon(void* self) {
    uintptr_t selfAddr = (uintptr_t)self;
    if (*(int*)(selfAddr + 0x60) == 2) {
        FUN_0056e810(1);
        *(uint32_t*)(selfAddr + 0x68) = 0xff7fffff;
        *(uint32_t*)(selfAddr + 0x6c) = 0xff7fffff;
        *(uint8_t*)(selfAddr + 0x74) = 0;
        *(uint32_t*)(selfAddr + 0x70) = 0xff7fffff;
        FUN_0056f540();
        FUN_0057a3f0(0);
        return 1;
    }
    return 0;
}

// 0x56fd40 — observed shape
uint32_t FUN_0056fd40_recon(void* self, void* param_1, uint32_t param_2, uint32_t param_3) {
    uintptr_t selfAddr = (uintptr_t)self;
    uintptr_t p1 = (uintptr_t)param_1;
    uint32_t uVar3 = FUN_0056fbf0_recon(self, param_3, 0);
    if ((char)uVar3 == '\0' ||
        (uVar3 = FUN_0056fbf0_recon(self, param_3, 0), (char)uVar3 == '\0')) {
        return uVar3 & 0xffffff00u;
    }
    uint32_t idx = 0;
    if (*(int*)(selfAddr + 0x38) == *(int*)(p1 + 0x38)) {
        while (true) {
            while (true) {
                if (*(uint32_t*)(selfAddr + 0x38) <= idx) {
                    *(uint32_t*)(selfAddr + 0x6c) = param_2;
                    *(uint32_t*)(selfAddr + 0x68) = 0xff7fffff;
                    *(uint32_t*)(selfAddr + 0x60) = 3;
                    *(uint32_t*)(p1 + 0x60) = 4;
                    *(uint32_t*)(p1 + 100) = 0xff7fffff;
                    *(void**)(selfAddr + 0x90) = param_1;
                    *(void**)(p1 + 0x90) = self;
                    return (idx & 0xffffff00u) | 1;
                }
                int* piVar1 = *(int**)(*(int*)(selfAddr + 0x30) + idx * 4);
                int* piVar2 = *(int**)(*(int*)(p1 + 0x30) + idx * 4);
                if (piVar1 != nullptr) break;
                if (piVar2 != nullptr) goto lab_56fde8;
                idx = idx + 1;
            }
            if (piVar2 == nullptr) break;
            int (*f1)() = *(int (**)())((uint8_t*)(uintptr_t)(uint32_t)*piVar1 + 4);
            int (*f2)() = *(int (**)())((uint8_t*)(uintptr_t)(uint32_t)*piVar2 + 4);
            int iVar4 = f1();
            int iVar5 = f2();
            if (iVar4 != iVar5 || piVar1[0xd] != piVar2[0xd]) break;
            idx = idx + 1;
        }
    }
lab_56fde8:
    uVar3 = 0;
    if (*(int*)(selfAddr + 0x60) != 0) {
        int iVar4 = *(int*)(*(int*)(selfAddr + 0x30) + *(int*)(selfAddr + 0x9c) * 4);
        if (*(float*)(iVar4 + 0x24) != -3.4028235e+38f) {
            *(float*)(selfAddr + 100) =
                (*(float*)(iVar4 + 0x28) / *(float*)(iVar4 + 0x10) - *(float*)(iVar4 + 0x24)) +
                *(float*)(selfAddr + 100);
        }
        *(uint32_t*)(selfAddr + 0x60) = 0;
        uVar3 = FUN_0056e790();
    }
    if (*(int*)(p1 + 0x60) != 0) {
        int iVar4 = *(int*)(*(int*)(p1 + 0x30) + *(int*)(p1 + 0x9c) * 4);
        if (*(float*)(iVar4 + 0x24) != -3.4028235e+38f) {
            *(float*)(p1 + 100) =
                (*(float*)(iVar4 + 0x28) / *(float*)(iVar4 + 0x10) - *(float*)(iVar4 + 0x24)) +
                *(float*)(p1 + 100);
        }
        *(uint32_t*)(p1 + 0x60) = 0;
        uVar3 = FUN_0056e790();
    }
    return uVar3 & 0xffffff00u;
}

// 0x56fed0 — observed shape
void FUN_0056fed0_recon(void* self) {
    uintptr_t selfAddr = (uintptr_t)self;
    if (*(int*)(selfAddr + 0x5c) != 0) {
        FUN_006b34a0(*(uint32_t*)(selfAddr + 0x50));
        *(uint32_t*)(selfAddr + 0x28) = *(uint32_t*)(selfAddr + 0x58);
        FUN_0056e940(*(uint32_t*)(*(int*)(selfAddr + 0x5c) + 0x34));
    }
}

// 0x56ff00 — observed shape
void FUN_0056ff00_recon(void* self, float param_1) {
    uintptr_t selfAddr = (uintptr_t)self;
    if (*(float*)(selfAddr + 100) == -3.4028235e+38f) {
        *(float*)(selfAddr + 100) = -param_1;
    }
    param_1 = param_1 + *(float*)(selfAddr + 100);
    uint32_t uVar6 = 0;
    if (*(int*)(selfAddr + 0x38) != 0) {
        do {
            int* piVar1 = *(int**)(*(int*)(selfAddr + 0x30) + uVar6 * 4);
            if (piVar1 != nullptr && ((*(uint8_t*)((uint8_t*)piVar1 + 0xc) >> 5 & 1) != 0)) {
                int* piVar2 = (int*)piVar1[0xd];
                if (piVar2 != nullptr) {
                    uint32_t* puVar4;
                    bool bFound = false;
                    for (puVar4 = (uint32_t*)(**(uint32_t* (**)())((uint8_t*)(uintptr_t)(uint32_t)*piVar2 + 4))();
                         puVar4 != nullptr; puVar4 = (uint32_t*)puVar4[1]) {
                        if (puVar4 == &DAT_007273fc) {
                            bFound = true;
                            break;
                        }
                    }
                    uint32_t* masked = bFound ? piVar2 : nullptr;
                    if (masked != nullptr &&
                        ((*(uint8_t*)((uint8_t*)masked + 0x20) >> 1 & 1) == 0)) {
                        goto lab_56ffc0;
                    }
                }
                int iVar5 = FUN_00552ec0((uint32_t)piVar1[0xd]);
                if (piVar1[0xf] == iVar5) {
                    *(uint8_t*)((uint8_t*)piVar1 + 0xc) = *(uint8_t*)((uint8_t*)piVar1 + 0xc) | 8;
                    *(uint8_t*)((uint8_t*)piVar1 + 0x40) = 1;
                    void (*fn)(float) = *(void (**)(float))((uint8_t*)(uintptr_t)(uint32_t)*piVar1 + 0x3c);
                    fn(param_1);
                    *(uint8_t*)((uint8_t*)piVar1 + 0xc) = *(uint8_t*)((uint8_t*)piVar1 + 0xc) & 0xf7;
                }
            }
        lab_56ffc0:
            uVar6 = uVar6 + 1;
        } while (uVar6 < *(uint32_t*)(selfAddr + 0x38));
    }
    if (*(char*)(selfAddr + 0x98) != '\0') {
        FUN_0056eed0(param_1);
        FUN_00573bd0((void*)(selfAddr + 0xe0), (void*)(selfAddr + 0x104));
    }
}

// 0x570010 — observed shape
void FUN_00570010_recon(void* self, float param_1) {
    uintptr_t selfAddr = (uintptr_t)self;
    bool bVar3 = *(float*)(selfAddr + 0x68) == -3.4028235e+38f;
    if (bVar3) {
        *(float*)(selfAddr + 0x68) = param_1;
        *(float*)(selfAddr + 0x6c) = param_1 + *(float*)(selfAddr + 0x6c);
    }
    float fVar4 = *(float*)(selfAddr + 0x70) /
                      *(float*)(*(int*)(*(int*)(selfAddr + 0x30) + *(int*)(selfAddr + 0x9c) * 4) + 0x10) -
                  *(float*)(selfAddr + 0x6c);
    *(float*)(selfAddr + 100) = fVar4;
    if (param_1 < *(float*)(selfAddr + 0x6c)) {
        int local_c = (int)(selfAddr + 0x2c);
        if (*(char*)(selfAddr + 0x74) != '\0' && *(int*)(selfAddr + 0x88) != 0) {
            local_c = (int)(selfAddr + 0x78);
        }
        fVar4 = fVar4 + *(float*)(selfAddr + 0x6c);
        uint32_t local_4 = 0;
        float ratio = (param_1 - *(float*)(selfAddr + 0x68)) /
                      (*(float*)(selfAddr + 0x6c) - *(float*)(selfAddr + 0x68));
        if (*(int*)(local_c + 0xc) != 0) {
            do {
                int* piVar2 = *(int**)(*(int*)(local_c + 4) + local_4 * 4);
                int iVar5 = 0;
                if (piVar2 != nullptr &&
                    (bVar3 ||
                     (((*(uint8_t*)((uint8_t*)piVar2 + 0xc) >> 5 & 1) != 0) &&
                      ((iVar5 = (int)(uintptr_t)FUN_00449390(&DAT_007273fc, (uint32_t)piVar2[0xd]),
                        iVar5 == 0 || ((*(uint8_t*)(iVar5 + 0x20) >> 1 & 1) != 0))))) &&
                    (iVar5 = FUN_00552ec0((uint32_t)piVar2[0xd]), piVar2[0xf] == iVar5)) {
                    *(uint8_t*)((uint8_t*)piVar2 + 0xc) = *(uint8_t*)((uint8_t*)piVar2 + 0xc) | 8;
                    if (*(char*)(selfAddr + 0x98) == '\0' ||
                        local_4 != *(uint32_t*)(selfAddr + 0x9c)) {
                        void (*fn)(float, float, bool) =
                            *(void (**)(float, float, bool))((uint8_t*)(uintptr_t)(uint32_t)*piVar2 + 0x60);
                        fn(fVar4, ratio, bVar3);
                    } else {
                        FUN_00573d80((void*)(selfAddr + 0xe0), (void*)(selfAddr + 0x104));
                        FUN_005802d0(fVar4, ratio, bVar3 ? 1 : 0, self);
                        FUN_00573bd0((void*)(selfAddr + 0xe0), (void*)(selfAddr + 0x104));
                    }
                    *(uint8_t*)((uint8_t*)piVar2 + 0xc) = *(uint8_t*)((uint8_t*)piVar2 + 0xc) & 0xf7;
                }
                local_4 = local_4 + 1;
            } while (local_4 < *(uint32_t*)(local_c + 0xc));
        }
    } else {
        uint32_t uVar1 = *(uint32_t*)(*(int*)(*(int*)(selfAddr + 0x30) + *(int*)(selfAddr + 0x9c) * 4) + 0x3c);
        bool flag;
        if (*(char*)(selfAddr + 0x74) == '\0' || *(int*)(selfAddr + 0x88) != 0) {
            flag = true;
        } else {
            flag = false;
        }
        FUN_0056fce0_recon(self);
        if (flag) {
            FUN_0056fbf0_recon(self, uVar1, 0);
            FUN_0056ff00_recon(self, param_1);
            return;
        }
        void* tempObj = nullptr;
        FUN_005741f0(&tempObj, self);
        if (tempObj != nullptr) {
            int iVar5 = ((int*)tempObj)[1];
            ((int*)tempObj)[1] = iVar5 + -1;
            if (iVar5 + -1 == 0) {
                void (*release)(uint32_t) = *(void (**)(uint32_t))*(uint8_t**)tempObj;
                release(1);
            }
        }
    }
}

// 0x5708a0 — observed shape
void FUN_005708a0_recon(void* self, uint8_t param_1) {
    FUN_0056f8c0_recon(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5708c0 — observed shape
uint32_t FUN_005708c0_recon(void* self, char* param_1, void* param_2) {
    uintptr_t selfAddr = (uintptr_t)self;
    char* pcVar6 = param_1;
    char* pcVar5 = param_1;
    char cVar2;
    do {
        cVar2 = *pcVar5;
        pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    char* newStr = (char*)thunk_FUN_00533c78((uint32_t)(pcVar5 - param_1));
    {
        char* src = pcVar6;
        char* dst = newStr;
        char cVar1;
        do {
            cVar1 = *src;
            *dst = cVar1;
            src = src + 1;
            dst = dst + 1;
        } while (cVar1 != '\0');
    }
    uint32_t idx0 = *(uint32_t*)(selfAddr + 0x20);
    if (*(uint32_t*)(selfAddr + 0x1c) <= idx0) {
        FUN_006b34a0(*(int*)(selfAddr + 0x28) + idx0);
    }
    FUN_005606f0(idx0, &newStr);
    void* held = param_2;
    if (param_2 != nullptr) {
        ((uint32_t*)param_2)[1] = ((uint32_t*)param_2)[1] + 1;
    }
    uint32_t idx1 = *(uint32_t*)(selfAddr + 0x38);
    if (*(uint32_t*)(selfAddr + 0x34) <= idx1) {
        FUN_0057a3f0(*(int*)(selfAddr + 0x40) + idx1);
    }
    FUN_00581300(idx1, &held);
    if (held != nullptr) {
        int* refcnt = (int*)((uint32_t*)held + 1);
        *refcnt = *refcnt + -1;
        if (*refcnt == 0) {
            void (*release)(uint32_t) = *(void (**)(uint32_t))*(uint8_t**)held;
            release(1);
        }
    }
    return idx1;
}

// 0x570970 — observed shape
// Per-state frame update. Cases 1/2 forward the frame time: the corpus shows those calls
// without an explicit argument, so the only float input (param_1) is passed through.
void FUN_00570970_recon(void* self, float param_1) {
    uintptr_t selfAddr = (uintptr_t)self;
    switch (*(uint32_t*)(selfAddr + 0x60)) {
    case 1:
        FUN_0056ff00_recon(self, param_1);
        return;
    case 2:
        FUN_00570010_recon(self, param_1);
        return;
    case 3:
        break;
    default:
        return;
    case 5: {
        if (*(float*)(selfAddr + 100) == -3.4028235e+38f) {
            *(float*)(selfAddr + 100) = -param_1;
        }
        int other = *(int*)(selfAddr + 0x90);
        if (*(float*)(other + 100) == -3.4028235e+38f) {
            double fVar4 = FUN_0056f230(self, param_1 + *(float*)(selfAddr + 100));
            int iVar2 = other;
            *(float*)(iVar2 + 100) =
                (float)((fVar4 -
                         (double)*(float*)(*(int*)(*(int*)(iVar2 + 0x30) + *(int*)(iVar2 + 0x9c) * 4) + 0x14)) /
                            (double)*(float*)(*(int*)(*(int*)(iVar2 + 0x30) + *(int*)(iVar2 + 0x9c) * 4) + 0x10) -
                        (double)param_1);
        }
        float t = param_1 + *(float*)(*(int*)(selfAddr + 0x90) + 100);
        double f4 = FUN_0056f230((void*)(uintptr_t)*(uint32_t*)(selfAddr + 0x90), t);
        int iVar2b = *(int*)(*(int*)(selfAddr + 0x30) + *(int*)(selfAddr + 0x9c) * 4);
        FUN_0056f060((float)((f4 - (double)*(float*)(iVar2b + 0x14)) /
                             (double)*(float*)(iVar2b + 0x10)),
                     t, *(float*)(selfAddr + 0x94));
        return;
    }
    }
    if (*(float*)(selfAddr + 0x68) == -3.4028235e+38f) {
        *(float*)(selfAddr + 0x68) = param_1;
        *(float*)(selfAddr + 0x6c) = param_1 + *(float*)(selfAddr + 0x6c);
    }
    if (*(float*)(selfAddr + 100) == -3.4028235e+38f) {
        *(float*)(selfAddr + 100) = -param_1;
    }
    int partner = *(int*)(selfAddr + 0x90);
    if (*(float*)(partner + 100) == -3.4028235e+38f) {
        double fVar4 = FUN_0056f230(self, param_1 + *(float*)(selfAddr + 100));
        int iVar2 = partner;
        *(float*)(iVar2 + 100) =
            (float)((fVar4 -
                     (double)*(float*)(*(int*)(*(int*)(iVar2 + 0x30) + *(int*)(iVar2 + 0x9c) * 4) + 0x14)) /
                        (double)*(float*)(*(int*)(*(int*)(iVar2 + 0x30) + *(int*)(iVar2 + 0x9c) * 4) + 0x10) -
                    (double)param_1);
    }
    if (*(float*)(selfAddr + 0x6c) <= param_1) {
        int iVar2 = *(int*)(selfAddr + 0x90);
        uint32_t uVar1 = *(uint32_t*)(*(int*)(*(int*)(iVar2 + 0x30) + *(int*)(iVar2 + 0x9c) * 4) + 0x3c);
        FUN_0056e8c0((void*)(uintptr_t)iVar2);
        FUN_0056fbf0_recon(self, uVar1, 0);
        return;
    }
    float fVar3 = param_1 + *(float*)(*(int*)(selfAddr + 0x90) + 100);
    double fVar4b = FUN_0056f230((void*)(uintptr_t)*(uint32_t*)(selfAddr + 0x90), fVar3);
    int iVar2c = *(int*)(*(int*)(selfAddr + 0x30) + *(int*)(selfAddr + 0x9c) * 4);
    FUN_0056f060((float)((fVar4b - (double)*(float*)(iVar2c + 0x14)) /
                         (double)*(float*)(iVar2c + 0x10)),
                 fVar3,
                 (param_1 - *(float*)(selfAddr + 0x68)) /
                     (*(float*)(selfAddr + 0x6c) - *(float*)(selfAddr + 0x68)));
}

// 0x5709b0 — observed shape
void FUN_005709b0_recon(void* self) {
    uintptr_t selfAddr = (uintptr_t)self;
    if (*(int*)(selfAddr + 0x20) == 0 && *(int*)(selfAddr + 0x5c) != 0) {
        FUN_006b34a0(*(uint32_t*)(selfAddr + 0x50));
        *(uint32_t*)(selfAddr + 0x28) = *(uint32_t*)(selfAddr + 0x58);
        FUN_0056e940(*(uint32_t*)(*(int*)(selfAddr + 0x5c) + 0x34));
    }
    uint32_t uVar1 = 0;
    if (*(int*)(selfAddr + 0x50) != 0) {
        do {
            *(uint32_t*)(*(int*)(selfAddr + 0x48) + uVar1 * 4) = 0;
            uVar1 = uVar1 + 1;
        } while (uVar1 < *(uint32_t*)(selfAddr + 0x50));
    }
    *(uint32_t*)(selfAddr + 0x50) = 0;
    *(uint32_t*)(selfAddr + 0x54) = 0;
    FUN_006b34a0(0);
    *(uint32_t*)(selfAddr + 0xac) = 0;
}

// 0x570a30 — observed shape
uint32_t FUN_00570a30_recon(void* self, float param_1, uint32_t param_2, uint32_t param_3, void* param_4) {
    uintptr_t selfAddr = (uintptr_t)self;
    uintptr_t p4 = (uintptr_t)param_4;
    if (param_4 == nullptr || *(int*)(selfAddr + 0x60) == 0) {
        char cVar1 = (char)FUN_0056fbf0_recon(self, param_3, 0);
        if (cVar1 != '\0') {
            double fVar7 = FUN_00506aa0();
            if (fVar7 <= (double)param_1) {
                fVar7 = FUN_004c3100();
                if ((double)param_1 <= fVar7) {
                    *(float*)(selfAddr + 0x70) = param_1;
                    if (param_4 != nullptr) {
                        *(uint8_t*)(selfAddr + 0x74) = 1;
                        FUN_0057a3f0(*(uint32_t*)(selfAddr + 0x38));
                        uint32_t local_110 = 0;
                        if (*(int*)(selfAddr + 0x38) != 0) {
                            do {
                                uint32_t* puVar4 =
                                    *(uint32_t**)(*(int*)(selfAddr + 0x30) + local_110 * 4);
                                int iVar2 = *(int*)(*(int*)(selfAddr + 0x48) + local_110 * 4);
                                if (puVar4 != nullptr && iVar2 != 0) {
                                    uint32_t uVar3 = 0;
                                    if (*(uint32_t*)(p4 + 0x50) != 0) {
                                        int* piVar5 = *(int**)(p4 + 0x48);
                                        do {
                                            if (*piVar5 == iVar2) {
                                                puVar4[1] = puVar4[1] + 1;
                                                uVar3 = *(uint32_t*)(selfAddr + 0x84);
                                                uint32_t* local_108 = puVar4;
                                                if (*(uint32_t*)(selfAddr + 0x80) <= uVar3) {
                                                    FUN_0057a3f0(*(int*)(selfAddr + 0x8c) + uVar3);
                                                }
                                                FUN_00581300(uVar3, &local_108);
                                                int* refcnt = (int*)(puVar4 + 1);
                                                *refcnt = *refcnt + -1;
                                                if (*refcnt == 0) {
                                                    void (*release)(uint32_t) =
                                                        *(void (**)(uint32_t))*(uint8_t**)puVar4;
                                                    release(1);
                                                }
                                                break;
                                            }
                                            uVar3 = uVar3 + 1;
                                            piVar5 = piVar5 + 1;
                                        } while (uVar3 < *(uint32_t*)(p4 + 0x50));
                                    }
                                }
                                local_110 = local_110 + 1;
                            } while (local_110 < *(uint32_t*)(selfAddr + 0x38));
                        }
                    }
                    *(uint32_t*)(selfAddr + 0x68) = 0xff7fffff;
                    *(uint32_t*)(selfAddr + 0x6c) = param_2;
                    *(uint32_t*)(selfAddr + 0x60) = 2;
                    return 1;
                }
            }
        }
    } else {
        char local_100[256];
        sprintf(local_100, "%s::SyncSequence", *(char**)(selfAddr + 0xc));
        int iVar2 = (int)(uintptr_t)FUN_00533c78(0x110);
        int local_10c;
        if (iVar2 == 0) {
            local_10c = 0;
        } else {
            FUN_0056f720_recon((void*)(uintptr_t)iVar2, (uint32_t)(uintptr_t)local_100,
                               *(uint32_t*)(selfAddr + 0x38), 1);
            local_10c = iVar2;
        }
        *(uint32_t*)((uintptr_t)local_10c + 0xac) = *(uint32_t*)(selfAddr + 0xac);
        {
            uint32_t* puVar4 = (uint32_t*)(selfAddr + 0xb0);
            uint32_t* puVar6 = (uint32_t*)((uintptr_t)local_10c + 0xb0);
            for (int i = 9; i != 0; i = i + -1) {
                *puVar6 = *puVar4;
                puVar4 = puVar4 + 1;
                puVar6 = puVar6 + 1;
            }
        }
        *(uint32_t*)((uintptr_t)local_10c + 0xd4) = *(uint32_t*)(selfAddr + 0xd4);
        *(uint32_t*)((uintptr_t)local_10c + 0xd8) = *(uint32_t*)(selfAddr + 0xd8);
        *(uint32_t*)((uintptr_t)local_10c + 0xdc) = *(uint32_t*)(selfAddr + 0xdc);
        *(uint32_t*)((uintptr_t)local_10c + 0x58) = *(uint32_t*)(selfAddr + 0x38);
        uint32_t local_110 = 0;
        if (*(int*)(selfAddr + 0x38) != 0) {
            do {
                uint32_t* local_108 = *(uint32_t**)(*(int*)(selfAddr + 0x48) + local_110 * 4);
                if (*(int*)(*(int*)(selfAddr + 0x30) + local_110 * 4) != 0 &&
                    local_108 != nullptr) {
                    uint32_t uVar3 = 0;
                    if (*(uint32_t*)(p4 + 0x50) != 0) {
                        int* piVar5 = *(int**)(p4 + 0x48);
                        do {
                            if ((uint32_t*)*piVar5 == local_108) {
                                uint32_t* puVar4b = (uint32_t*)FUN_00538680();
                                if (puVar4b != nullptr) {
                                    puVar4b[1] = puVar4b[1] + 1;
                                }
                                uVar3 = *(uint32_t*)((uintptr_t)local_10c + 0x38);
                                uint32_t* local_104 = puVar4b;
                                if (*(uint32_t*)((uintptr_t)local_10c + 0x34) <= uVar3) {
                                    FUN_0057a3f0(*(int*)((uintptr_t)local_10c + 0x40) + uVar3);
                                }
                                FUN_00581300(uVar3, &local_104);
                                if (puVar4b != nullptr) {
                                    int* refcnt = (int*)(puVar4b + 1);
                                    *refcnt = *refcnt + -1;
                                    if (*refcnt == 0) {
                                        void (*release)(uint32_t) =
                                            *(void (**)(uint32_t))*(uint8_t**)puVar4b;
                                        release(1);
                                    }
                                }
                                uVar3 = *(uint32_t*)((uintptr_t)local_10c + 0x50);
                                if (*(uint32_t*)((uintptr_t)local_10c + 0x4c) <= uVar3) {
                                    FUN_006b34a0(*(int*)((uintptr_t)local_10c + 0x58) + uVar3);
                                }
                                FUN_005606f0(uVar3, &local_108);
                                break;
                            }
                            uVar3 = uVar3 + 1;
                            piVar5 = piVar5 + 1;
                        } while (uVar3 < *(uint32_t*)(p4 + 0x50));
                    }
                }
                local_110 = local_110 + 1;
            } while (local_110 < *(uint32_t*)(selfAddr + 0x38));
        }
        *(uint8_t*)((uintptr_t)local_10c + 0x74) = 1;
        FUN_00574540((void*)(uintptr_t)local_10c, 0, 0);
        FUN_00573b60((void*)(uintptr_t)local_10c, param_1, param_2, param_3, 0);
    }
    return 0;
}

// 0x570d30 — observed shape
void FUN_00570d30_recon(void* self, void* param_1, uint32_t param_2) {
    uintptr_t selfAddr = (uintptr_t)self;
    uintptr_t p1 = (uintptr_t)param_1;
    FUN_00538410(param_1, param_2);
    uint32_t* puVar4 = *(uint32_t**)(p1 + 0x10);
    if (puVar4 != *(uint32_t**)(selfAddr + 0x10)) {
        if (puVar4 != nullptr) {
            int* refcnt = (int*)(puVar4 + 1);
            *refcnt = *refcnt + -1;
            if (*refcnt == 0) {
                void (*release)(uint32_t) = *(void (**)(uint32_t))*(uint8_t**)puVar4;
                release(1);
            }
        }
        int iVar2 = *(int*)(selfAddr + 0x10);
        *(uint32_t*)(p1 + 0x10) = iVar2;
        if (iVar2 != 0) {
            *(int*)(iVar2 + 4) = *(int*)(iVar2 + 4) + 1;
        }
    }
    {
        uint32_t* puVar4b = (uint32_t*)(selfAddr + 0xb0);
        uint32_t* puVar5 = (uint32_t*)(p1 + 0xb0);
        for (int i = 9; i != 0; i = i + -1) {
            *puVar5 = *puVar4b;
            puVar4b = puVar4b + 1;
            puVar5 = puVar5 + 1;
        }
    }
    *(uint32_t*)(p1 + 0xd4) = *(uint32_t*)(selfAddr + 0xd4);
    *(uint32_t*)(p1 + 0xd8) = *(uint32_t*)(selfAddr + 0xd8);
    *(uint32_t*)(p1 + 0xdc) = *(uint32_t*)(selfAddr + 0xdc);
    if (*(int*)(*(int*)(*(int*)(selfAddr + 0x30) + *(int*)(selfAddr + 0x9c) * 4) + 0x34) == 0) {
        if (*(int*)(selfAddr + 0x5c) != 0) {
            FUN_006b34a0(*(uint32_t*)(selfAddr + 0x50));
            *(uint32_t*)(selfAddr + 0x28) = *(uint32_t*)(selfAddr + 0x58);
            FUN_0056e940(*(uint32_t*)(*(int*)(selfAddr + 0x5c) + 0x34));
        }
        uint32_t uVar3 = 0;
        if (*(int*)(selfAddr + 0x38) != 0) {
            do {
                int iVar2 = *(int*)(*(int*)(selfAddr + 0x18) + uVar3 * 4);
                int* piVar1 = *(int**)(*(int*)(selfAddr + 0x30) + uVar3 * 4);
                if (iVar2 != 0 && piVar1 != nullptr) {
                    uint8_t* vt = (uint8_t*)(uintptr_t)(uint32_t)*piVar1;
                    void (*fn8)(uint32_t) = *(void (**)(uint32_t))(vt + 8);
                    fn8(param_2);
                    void (*fn28)(void*) = *(void (**)(void*))(vt + 0x28);
                    fn28(param_1);
                    FUN_005708c0_recon(self, (char*)(uintptr_t)iVar2, self);
                }
                uVar3 = uVar3 + 1;
            } while (uVar3 < *(uint32_t*)(selfAddr + 0x38));
        }
        if (*(int*)(selfAddr + 0x5c) != 0) {
            FUN_0056e700();
            FUN_0056e700();
        }
    }
    FUN_0056e6a0(*(uint32_t*)(selfAddr + 0xa8));
}

// 0x570e60 — observed shape
// Allocates and constructs the 0x110 byte object, copies the vector contents of param_2,
// releases the old +0x2a buffer and returns the new object through param_1.
uint32_t* FUN_00570e60_recon(uint32_t* param_1, void* param_2) {
    uintptr_t p2 = (uintptr_t)param_2;
    int iVar5 = (int)(uintptr_t)FUN_00533c78(0x110);
    uint32_t* puVar6;
    if (iVar5 == 0) {
        puVar6 = nullptr;
    } else {
        FUN_0056f720_recon((void*)(uintptr_t)iVar5, *(uint32_t*)(p2 + 0xc),
                           *(uint32_t*)(p2 + 0x24), *(uint32_t*)(p2 + 0x24));
        puVar6 = (uint32_t*)(uintptr_t)iVar5;
        puVar6[1] = puVar6[1] + 1;
    }
    uint32_t uVar7 = 0;
    if (*(int*)(p2 + 0x24) != 0) {
        do {
            int iVar5b = *(int*)(*(int*)(p2 + 0x1c) + uVar7 * 4);
            int iVar2 = *(int*)(*(int*)(p2 + 0x34) + uVar7 * 4);
            if (iVar5b != 0 && iVar2 != 0) {
                FUN_005708c0_recon((void*)puVar6, (char*)(uintptr_t)iVar5b, (void*)(uintptr_t)iVar2);
            }
            uVar7 = uVar7 + 1;
        } while (uVar7 < *(uint32_t*)(p2 + 0x24));
    }
    uint32_t* puVar3 = *(uint32_t**)(p2 + 0x70);
    uint32_t* puVar4 = (uint32_t*)puVar6[4];
    if (puVar4 != puVar3) {
        if (puVar4 != nullptr) {
            int* refcnt = (int*)(puVar4 + 1);
            *refcnt = *refcnt + -1;
            if (*refcnt == 0) {
                void (*release)(uint32_t) = *(void (**)(uint32_t))*(uint8_t**)puVar4;
                release(1);
            }
        }
        puVar6[4] = (uint32_t)(uintptr_t)puVar3;
        if (puVar3 != nullptr) {
            puVar3[1] = puVar3[1] + 1;
        }
    }
    operator_delete__((void*)(uintptr_t)puVar6[0x2a]);
    puVar6[0x2a] = 0;
    *param_1 = (uint32_t)(uintptr_t)puVar6;
    iVar5 = (int)puVar6[1];
    puVar6[1] = (uint32_t)(iVar5 + 1);
    puVar6[1] = (uint32_t)iVar5;
    if (iVar5 == 0) {
        void (*release)(uint32_t) = *(void (**)(uint32_t))*(uint8_t**)puVar6;
        release(1);
    }
    return param_1;
}

// 0x570f30 — observed shape
// Looks the supplied key up in the table at self[4] (name at entry+4, time at entry+0)
// and forwards the normalized time to the SyncSequence trigger.
void FUN_00570f30_recon(void* self, uint8_t* param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4) {
    uintptr_t selfAddr = (uintptr_t)self;
    float local_8 = 0.0f;
    if (param_1 != nullptr) {
        int iVar2 = *(int*)(selfAddr + 0x10);
        if (iVar2 != 0) {
            uint32_t uVar7 = 0;
            if (*(uint32_t*)(iVar2 + 0x10) != 0) {
                uint32_t* puVar5 = (uint32_t*)(*(int*)(iVar2 + 0x14) + 4);
                do {
                    uint8_t* pbVar3 = (uint8_t*)(uintptr_t)*puVar5;
                    if (strcmp((char*)pbVar3, (char*)param_1) == 0) {
                        int iVar4 = *(int*)(*(int*)(selfAddr + 0x30) + *(int*)(selfAddr + 0x9c) * 4);
                        local_8 = (*(float*)(*(int*)(iVar2 + 0x14) + uVar7 * 8) -
                                   *(float*)(iVar4 + 0x14)) /
                                  *(float*)(iVar4 + 0x10);
                        break;
                    }
                    uVar7 = uVar7 + 1;
                    puVar5 = puVar5 + 2;
                } while (uVar7 < *(uint32_t*)(iVar2 + 0x10));
            }
        }
    }
    FUN_00570a30_recon(self, local_8, param_2, param_3, (void*)(uintptr_t)param_4);
}

// 0x571060 — observed shape
uint32_t* FUN_00571060_recon(uint32_t* param_1, uint32_t* param_2, uint32_t* param_3) {
    if ((uintptr_t)param_2[0x54] <= (uintptr_t)param_3) {
        *param_1 = 0;
        return param_1;
    }
    uint32_t* puVar4 = nullptr;
    if (param_2[7] < 0x5000000u) {
        FUN_0057b9e0(&param_3, param_2, param_3, 0);
        int* piVar2 = (int*)FUN_00570e60_recon((uint32_t*)&param_2, param_3);
        uint32_t* puVar3 = (uint32_t*)(uintptr_t)*piVar2;
        if (puVar3 != nullptr) {
            puVar3[1] = puVar3[1] + 1;
            puVar4 = puVar3;
        }
        if (param_2 != nullptr) {
            int iVar1 = (int)param_2[1];
            param_2[1] = (uint32_t)(iVar1 + -1);
            if (iVar1 + -1 == 0) {
                void (*release)(uint32_t) = *(void (**)(uint32_t))*(uint8_t**)param_2;
                release(1);
            }
        }
        if (param_3 != nullptr) {
            int iVar1 = (int)param_3[1];
            param_3[1] = (uint32_t)(iVar1 + -1);
            if (iVar1 + -1 == 0) {
                void (*release)(uint32_t) = *(void (**)(uint32_t))*(uint8_t**)param_3;
                release(1);
            }
        }
    } else {
        uint32_t* puVar3 = (uint32_t*)FUN_00449390(
            &DAT_007283cc, *(uint32_t*)(param_2[0x52] + (int)(uintptr_t)param_3 * 4));
        if (puVar3 != nullptr) {
            puVar3[1] = puVar3[1] + 1;
            puVar4 = puVar3;
        }
    }
    *param_1 = (uint32_t)(uintptr_t)puVar4;
    if (puVar4 != nullptr) {
        int iVar1 = (int)puVar4[1];
        puVar4[1] = (uint32_t)(iVar1 + 1);
        puVar4[1] = (uint32_t)iVar1;
        if (iVar1 == 0) {
            void (*release)(uint32_t) = *(void (**)(uint32_t))*(uint8_t**)puVar4;
            release(1);
        }
    }
    return param_1;
}
