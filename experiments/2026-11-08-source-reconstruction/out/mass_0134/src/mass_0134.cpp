#include <cstdint>
#include <cstddef>

// --- extern helpers/globals for mass_0134 ---
extern void FUN_00549730(int param_1);
extern int FUN_00557b10(void* param_1);
extern void FUN_006b34a0(int param_1);
extern void FUN_005606f0(uint32_t param_1, void* param_2);
extern void* DAT_00727600;
extern void* DAT_00727608;
extern void FUN_00549540(void);
extern char PTR_FUN_006c16b8;
extern void* FUN_00533c78(uint32_t size);
extern void FUN_00540c50(void);
extern char PTR_FUN_0070c0a8;
extern void* DAT_00727618;
extern void* DAT_00727824;
extern void* DAT_00727828;
extern int _DAT_00727820;
extern char DAT_00727720[0x100];
extern void FUN_00497420(void* param_1);
extern void FUN_00567880(void* param_1);
extern void* thunk_FUN_004fcaa0(void* param_1, int param_2, int param_3);
extern void FUN_00567d20(void* param_1, void* param_2);
extern void FUN_00567be0(void);
extern void FUN_005515a0(void);
extern void operator_delete(void* ptr);
extern void operator_delete__(void* ptr);
extern void FUN_005e1490(void);
extern char PTR_FUN_006c17b8;
extern char PTR_FUN_006c17bc;
extern char PTR_FUN_006c1798;
extern char PTR_FUN_006c179c;
extern char PTR_FUN_006c1810;
extern char PTR_FUN_006c182c;
extern char PTR_FUN_006c1848;
#include <cstring>
#include <cstdlib>

// 0x544cb0 — observed shape
void FUN_00544cb0(int param_1) {
    uint32_t uVar1;
    int iVar2;
    iVar2 = param_1;
    FUN_00549730(param_1);
    int temp = FUN_00557b10(DAT_00727600);
    param_1 = temp;
    uVar1 = *(uint32_t*)(iVar2 + 0xc);
    if (*(uint32_t*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
    return;
}

// 0x544d00 — observed shape
void FUN_00544d00(void* self) {
    FUN_00549540();
    *(void**)self = (void*)&PTR_FUN_006c16b8;
    return;
}

// 0x544dd0 — observed shape
void FUN_00544dd0(int param_1) {
    uint32_t uVar1;
    int iVar2;
    iVar2 = param_1;
    FUN_00549730(param_1);
    int temp = FUN_00557b10(DAT_00727608);
    param_1 = temp;
    uVar1 = *(uint32_t*)(iVar2 + 0xc);
    if (*(uint32_t*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
    return;
}

// 0x544ec0 — observed shape
void FUN_00544ec0(void) {
    void* puVar3 = FUN_00533c78(0x24);
    if (puVar3 == nullptr) {
        puVar3 = nullptr;
    } else {
        FUN_00540c50();
        *(void**)puVar3 = (void*)&PTR_FUN_0070c0a8;
        *(uint16_t*)((uint8_t*)puVar3 + 0x20) = 0;
    }
    void* puVar2 = DAT_00727618;
    if (DAT_00727618 != puVar3) {
        if (DAT_00727618 != nullptr) {
            int* ref = (int*)DAT_00727618;
            int refcount = *(int*)((uint8_t*)ref + 4);
            *(int*)((uint8_t*)ref + 4) = refcount - 1;
            if (refcount - 1 == 0) {
                void* vtable = *(void**)puVar2;
                void (*dtor)(int) = (void (*)(int))*(void**)((uint8_t*)vtable + 0);
                dtor(1);
            }
        }
        DAT_00727618 = puVar3;
        if (puVar3 != nullptr) {
            int* ref = (int*)puVar3;
            *(int*)((uint8_t*)ref + 4) = *(int*)((uint8_t*)ref + 4) + 1;
        }
    }
    return;
}

// 0x544f20 — observed shape
void FUN_00544f20(void) {
    void* puVar2 = DAT_00727618;
    if (DAT_00727618 != nullptr) {
        int refcount = *(int*)((uint8_t*)DAT_00727618 + 4);
        *(int*)((uint8_t*)DAT_00727618 + 4) = refcount - 1;
        if (refcount - 1 == 0) {
            void* vtable = *(void**)puVar2;
            void (*dtor)(int) = (void (*)(int))*(void**)((uint8_t*)vtable + 0);
            dtor(1);
        }
        DAT_00727618 = nullptr;
    }
    return;
}

// 0x544fe0 — observed shape
void FUN_00544fe0(void) {
    if (DAT_00727824 != nullptr) {
        void* vtable = *(void**)DAT_00727824;
        void (*dtor)(int) = (void (*)(int))*(void**)((uint8_t*)vtable + 0);
        dtor(1);
    }
    if (DAT_00727828 != nullptr) {
        void* vtable = *(void**)DAT_00727828;
        void (*dtor)(int) = (void (*)(int))*(void**)((uint8_t*)vtable + 0);
        dtor(1);
    }
    return;
}

// 0x545010 — observed shape
void FUN_00545010(char* param_1) {
    _DAT_00727820 = 5;
    int offset = (int)(intptr_t)DAT_00727720 - (int)(intptr_t)param_1;
    char cVar1;
    do {
        cVar1 = *param_1;
        *(param_1 + offset) = cVar1;
        param_1 = param_1 + 1;
    } while (cVar1 != '\0');
    uint8_t* puVar4 = (uint8_t*)0x72771f;
    while (*puVar4 != '\0') {
        puVar4++;
    }
    const char* pcVar3 = ": cannot find create function.";
    for (int iVar2 = 7; iVar2 != 0; iVar2--) {
        *(uint32_t*)puVar4 = *(uint32_t*)pcVar3;
        pcVar3 += 4;
        puVar4 += 4;
    }
    *(uint16_t*)puVar4 = *(uint16_t*)pcVar3;
    *(char*)(puVar4 + 2) = pcVar3[2];
    return;
}

// 0x545060 — observed shape
uint8_t FUN_00545060(void* self, char* param_1) {
    int* piVar3 = (int*)((uint8_t*)self + 0x24);
    int offset = (int)(intptr_t)piVar3 - (int)(intptr_t)param_1;
    char cVar1;
    do {
        cVar1 = *param_1;
        *(param_1 + offset) = cVar1;
        param_1++;
    } while (cVar1 != '\0');
    FUN_00497420(piVar3);
    FUN_00567880(piVar3);
    piVar3 = (int*)thunk_FUN_004fcaa0(piVar3, 0, 0x8000);
    if (piVar3 != nullptr) {
        void* vtable = *(void**)piVar3;
        uint8_t (*check)(void) = (uint8_t (*)(void))*(void**)((uint8_t*)vtable + 4);
        cVar1 = (char)check();
        if (cVar1 != '\0') {
            void (*call)(void*) = (void (*)(void*))*(void**)((uint8_t*)*(void**)self + 4);
            uint8_t result = ((uint8_t (*)(void*))call)(piVar3);
            void (*release)(int) = (void (*)(int))*(void**)(*(void**)piVar3);
            release(1);
            return result;
        }
        void (*release)(int) = (void (*)(int))*(void**)(*(void**)piVar3);
        release(1);
    }
    DAT_00727720[0] = 'C';
    DAT_00727720[1] = 'a';
    DAT_00727720[2] = 'n';
    DAT_00727720[3] = 'n';
    DAT_00727720[4] = 'o';
    DAT_00727720[5] = 't';
    DAT_00727720[6] = ' ';
    DAT_00727720[7] = 'o';
    DAT_00727720[12] = 'f';
    DAT_00727720[13] = 'i';
    DAT_00727720[14] = 'l';
    DAT_00727720[15] = 'e';
    _DAT_00727820 = 1;
    DAT_00727720[8] = 'p';
    DAT_00727720[9] = 'e';
    DAT_00727720[10] = 'n';
    DAT_00727720[11] = ' ';
    DAT_00727720[16] = 0x2e;
    return 0;
}

// 0x545120 — observed shape
uint8_t FUN_00545120(void* self, uint32_t param_1, uint32_t param_2) {
    FUN_00567d20((void*)(intptr_t)param_1, (void*)(intptr_t)param_2);
    uint8_t local_18[24];
    void* vtable = *(void**)self;
    uint8_t result = ((uint8_t (*)(uint8_t*))*(void**)((uint8_t*)vtable + 4))(local_18);
    FUN_00567be0();
    return result;
}

// 0x5451a0 — observed shape
void FUN_005451a0(void* self, char* param_1) {
    *(uint32_t*)((uint8_t*)self + 0x15c) = 0;
    int offset = (int)((intptr_t)self + 0x24) - (int)(intptr_t)param_1;
    char cVar1;
    do {
        cVar1 = *param_1;
        *(param_1 + offset) = cVar1;
        param_1++;
    } while (cVar1 != '\0');
    FUN_005515a0();
    return;
}

// 0x5451d0 — observed shape
uint8_t FUN_005451d0(void* self, char* param_1) {
    int* piVar4 = (int*)((uint8_t*)self + 0x24);
    char* pcVar3 = param_1;
    char cVar1;
    do {
        cVar1 = *pcVar3;
        *(pcVar3 + ((int)(intptr_t)piVar4 - (int)(intptr_t)param_1)) = cVar1;
        pcVar3++;
    } while (cVar1 != '\0');
    FUN_00497420(piVar4);
    FUN_00567880(piVar4);
    piVar4 = (int*)thunk_FUN_004fcaa0(param_1, 1, 0x8000);
    if (piVar4 != nullptr) {
        void* vtable = *(void**)piVar4;
        uint8_t (*check)(void) = (uint8_t (*)(void))*(void**)((uint8_t*)vtable + 4);
        cVar1 = (char)check();
        if (cVar1 != '\0') {
            uint8_t result = ((uint8_t (*)(void*))*(void**)((uint8_t*)*(void**)self + 0x10))(piVar4);
            void (*release)(int) = (void (*)(int))*(void**)(*(void**)piVar4);
            release(1);
            return result;
        }
        void (*release)(int) = (void (*)(int))*(void**)(*(void**)piVar4);
        release(1);
    }
    return 0;
}

// 0x545270 — observed shape
uint32_t FUN_00545270(char* param_1) {
    char local_10[16];
    int offset = -(int)(intptr_t)param_1;
    char cVar1;
    do {
        cVar1 = *param_1;
        *(param_1 + offset + (int)(intptr_t)local_10) = cVar1;
        param_1++;
    } while (cVar1 != '\0');
    uint8_t bVar4 = 0x18;
    uint32_t uVar5 = 0;
    char* _Str = strtok(local_10, ".");
    while (_Str != nullptr) {
        int part = atoi(_Str);
        uint8_t bVar2 = bVar4 & 0x1f;
        bVar4 = bVar4 - 8;
        uVar5 = uVar5 | ((uint32_t)part << bVar2);
        _Str = strtok(nullptr, ".");
    }
    return uVar5;
}

// 0x5452e0 — observed shape
void FUN_005452e0(void* self, int param_1) {
    if (param_1 != 0) {
        void* old = *(void**)((uint8_t*)self + 0x128);
        if (old != nullptr) {
            void* vtable = *(void**)old;
            void (*release)(int) = (void (*)(int))*(void**)(vtable);
            release(1);
        }
        *(int*)((uint8_t*)self + 0x128) = param_1;
    }
    return;
}

// 0x545310 — observed shape
void FUN_00545310(void* self, uint32_t param_1) {
    void* vtable = *(void**)self;
    int hash = ((int (*)(uint32_t))*(void**)((uint8_t*)vtable + 4))(param_1);
    int* bucketBase = *(int**)((uint8_t*)self + 8);
    int* piVar4 = *(int**)(bucketBase + hash * 4);
    if (piVar4 != nullptr) {
        do {
            char match = ((char (*)(uint32_t, int))*(void**)((uint8_t*)vtable + 8))(param_1, piVar4[1]);
            if (match != '\0') {
                ((void (*)(int*))*(void**)((uint8_t*)vtable + 0x10))(piVar4);
                ((void (*)(int*, uint32_t, void*))*(void**)((uint8_t*)vtable + 0xc))(piVar4, param_1, nullptr);
                return;
            }
            piVar4 = (int*)*piVar4;
        } while (piVar4 != nullptr);
    }
    int* newNode = ((int* (*)(void))*(void**)((uint8_t*)vtable + 0x14))();
    ((void (*)(int*, uint32_t, uint32_t))*(void**)((uint8_t*)vtable + 0xc))(newNode, param_1, param_1);
    *newNode = *(int*)(bucketBase + hash * 4);
    *(int**)(bucketBase + hash * 4) = newNode;
    *(int*)((uint8_t*)self + 12) = *(int*)((uint8_t*)self + 12) + 1;
    return;
}

// 0x5453a0 — observed shape
uint32_t FUN_005453a0(void* self, uint16_t* param_1) {
    void* vtable = *(void**)self;
    int hash = ((int (*)(uint16_t*))*(void**)((uint8_t*)vtable + 4))(param_1);
    int* bucketBase = *(int**)((uint8_t*)self + 8);
    int* piVar3 = *(int**)(bucketBase + hash * 4);
    if (piVar3 != nullptr) {
        do {
            char match = ((char (*)(uint16_t*, int))*(void**)((uint8_t*)vtable + 8))(param_1, piVar3[1]);
            if (match != '\0') {
                *param_1 = (int16_t)piVar3[2];
                return 1;
            }
            piVar3 = (int*)*piVar3;
        } while (piVar3 != nullptr);
    }
    return 0;
}

// 0x545400 — observed shape
void FUN_00545400(void* self, uint8_t param_1) {
    *(void**)self = (void*)&PTR_FUN_006c17b8;
    operator_delete__(*(void**)((uint8_t*)self + 4));
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x545450 — observed shape
void FUN_00545450(void* self) {
    *(void**)self = (void*)&PTR_FUN_006c1848;
    if (*(char*)((uint8_t*)self + 16) != '\0' && *(uint32_t*)((uint8_t*)self + 4) != 0) {
        uint32_t uVar3 = 0;
        do {
            void* puVar2 = *(void**)(*(uint8_t**)((uint8_t*)self + 8) + uVar3 * 4);
            while (puVar2 != nullptr) {
                void* toFree = *(void**)((uint8_t*)puVar2 + 4);
                puVar2 = *(void**)puVar2;
                operator_delete__(toFree);
            }
            uVar3++;
        } while (uVar3 < *(uint32_t*)((uint8_t*)self + 4));
    }
    *(void**)self = (void*)&PTR_FUN_006c182c;
    FUN_005e1490();
    *(void**)self = (void*)&PTR_FUN_006c17bc;
    FUN_005e1490();
    operator_delete__(*(void**)((uint8_t*)self + 8));
    return;
}

// 0x5454d0 — observed shape
void FUN_005454d0(void* self, uint8_t param_1) {
    *(void**)self = (void*)&PTR_FUN_006c1798;
    operator_delete__(*(void**)((uint8_t*)self + 4));
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x545500 — observed shape
void FUN_00545500(void* self, uint8_t param_1) {
    *(void**)self = (void*)&PTR_FUN_006c179c;
    FUN_005e1490();
    operator_delete__(*(void**)((uint8_t*)self + 8));
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x545540 — observed shape
void FUN_00545540(void* self, uint8_t param_1) {
    *(void**)self = (void*)&PTR_FUN_006c1810;
    FUN_005e1490();
    *(void**)self = (void*)&PTR_FUN_006c179c;
    FUN_005e1490();
    operator_delete__(*(void**)((uint8_t*)self + 8));
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}
