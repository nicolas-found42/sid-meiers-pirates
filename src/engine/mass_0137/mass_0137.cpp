// Reconstruction batch mass_0137 — Sid Meier's Pirates! (2004) PE32 i386
// Image: 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void* PTR_FUN_006c1998;
extern void* PTR_LAB_006fd148;
extern int DAT_00727444;
extern void FUN_00545450(void* self);
extern void operator_delete(void* p);
extern void* FUN_00533c78(std::size_t n);
extern void* thunk_FUN_00533c78(std::size_t n);
extern void* PTR_FUN_006c17d8;
extern void* PTR_FUN_006c18a8;
extern void* PTR_FUN_006c17b8;
extern int _DAT_00727820;
extern unsigned char DAT_00727720;
extern void* DAT_00727824;
extern void* DAT_00727828;
extern void* PTR_FUN_006c19b0;
extern void* PTR_FUN_006c1798;
extern void* PTR_FUN_006c18e0;
extern void* PTR_FUN_006c179c;
extern void* PTR_FUN_006c1810;
extern void* FUN_00546680(int p);
extern void* FUN_005677e0(void);
extern void FUN_00546260(void* self);
extern void FUN_005e1490(void* self);
extern void FUN_005461d0(void* self);
extern void FUN_0057a3f0(int p);
extern void FUN_00581300(unsigned int idx, void** param);

// 0x546700 — observed shape
void FUN_546700(void* self, unsigned char param_1)
{
    uint32_t** p = (uint32_t**)self;
    *p = (uint32_t*)PTR_FUN_006c1998;
    FUN_00545450(self);
    *p = (uint32_t*)PTR_LAB_006fd148;
    DAT_00727444 = DAT_00727444 + -1;
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x546880 — observed shape
void FUN_546880(void)
{
    _DAT_00727820 = 0;
    DAT_00727720 = 0;
    uint32_t* puVar1 = (uint32_t*)FUN_00533c78(0x14);
    if (puVar1 == nullptr) {
        DAT_00727824 = nullptr;
    } else {
        puVar1[0] = (uint32_t)(uintptr_t)PTR_FUN_006c17d8;
        puVar1[1] = 0x3b;
        puVar1[3] = 0;
        uint32_t* puVar2 = (uint32_t*)thunk_FUN_00533c78(0xec);
        puVar1[2] = (uint32_t)(uintptr_t)puVar2;
        for (unsigned int uVar3 = puVar1[1] & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar2 = 0;
            puVar2 = puVar2 + 1;
        }
        for (int iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
            *(uint8_t*)puVar2 = 0;
            puVar2 = (uint32_t*)((intptr_t)puVar2 + 1);
        }
        *(uint8_t*)(puVar1 + 4) = 0;
        puVar1[0] = (uint32_t)(uintptr_t)PTR_FUN_006c18a8;
        DAT_00727824 = (void*)puVar1;
    }
    DAT_00727828 = FUN_00533c78(0x18);
    if (DAT_00727828 == nullptr) {
        DAT_00727828 = nullptr;
        return;
    }
    uint32_t* p = (uint32_t*)DAT_00727828;
    p[2] = 0; p[3] = 0; p[4] = 0; p[1] = 0;
    p[0] = (uint32_t)(uintptr_t)PTR_FUN_006c17b8;
    p[5] = 3;
}

// 0x546930 — observed shape
void FUN_546930(void* self)
{
    uint32_t* in_ECX = (uint32_t*)self;
    in_ECX[0] = (uint32_t)(uintptr_t)PTR_FUN_006c19b0;
    in_ECX[1] = (uint32_t)(uintptr_t)PTR_FUN_006c1798;
    in_ECX[3] = 0;
    in_ECX[6] = 1;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    in_ECX[2] = 0;
    in_ECX[0x4d] = 0;
    in_ECX[0x50] = 0x400;
    in_ECX[0x4e] = 0;
    in_ECX[0x4f] = 0;
    in_ECX[0x4c] = 0;
    in_ECX[0x4b] = (uint32_t)(uintptr_t)PTR_FUN_006c18e0;
    in_ECX[0x51] = (uint32_t)(uintptr_t)PTR_FUN_006c18e0;
    in_ECX[0x53] = 0;
    in_ECX[0x56] = 1;
    in_ECX[0x54] = 0;
    in_ECX[0x55] = 0;
    in_ECX[0x52] = 0;
    in_ECX[0x59] = 0;
    in_ECX[0x5a] = 0;
    in_ECX[0x5b] = 0;
    in_ECX[0x5d] = 0;
    in_ECX[0x5e] = 0;
    in_ECX[0x5f] = 0;
    in_ECX[0x61] = (uint32_t)(uintptr_t)PTR_FUN_006c179c;
    in_ECX[0x62] = 0x25;
    in_ECX[100] = 0;
    uint32_t* puVar3 = (uint32_t*)thunk_FUN_00533c78(0x94);
    in_ECX[99] = (uint32_t)(uintptr_t)puVar3;
    for (unsigned int uVar5 = in_ECX[0x62] & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
    }
    for (int iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
        *(uint8_t*)puVar3 = 0;
        puVar3 = (uint32_t*)((intptr_t)puVar3 + 1);
    }
    in_ECX[0x61] = (uint32_t)(uintptr_t)PTR_FUN_006c1810;
    in_ECX[0x65] = 0;
    in_ECX[0x57] = 0;
    in_ECX[0x58] = 0;
    in_ECX[7] = 0;
    in_ECX[8] = 0;
    *(uint8_t*)(in_ECX + 9) = 0;
    int iVar6b = (int)(intptr_t)FUN_00533c78(0x20);
    uint32_t* puVar3b;
    if (iVar6b == 0) {
        puVar3b = nullptr;
    } else {
        puVar3b = (uint32_t*)FUN_00546680(0);
    }
    uint32_t* puVar2 = (uint32_t*)(uintptr_t)in_ECX[0x65];
    if (puVar2 != puVar3b) {
        if (puVar2 != nullptr) {
            int* piVar1 = (int*)(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                using DelFn = void(*)(int);
                ((DelFn)(*(void**)*puVar2))(1);
            }
        }
        in_ECX[0x65] = (uint32_t)(uintptr_t)puVar3b;
        if (puVar3b != nullptr) {
            puVar3b[1] = puVar3b[1] + 1;
        }
    }
    in_ECX[0x5c] = 0;
    in_ECX[0x60] = 0;
    int iVar6c = (int)(intptr_t)FUN_00533c78(0x210);
    uint32_t uVar4;
    if (iVar6c == 0) {
        uVar4 = 0;
    } else {
        uVar4 = (uint32_t)(uintptr_t)FUN_005677e0();
    }
    in_ECX[0x4a] = uVar4;
    in_ECX[0x66] = 0;
    _DAT_00727820 = 0;
    DAT_00727720 = 0;
}

// 0x546ad0 — observed shape
void FUN_546ad0(void* self)
{
    uint32_t* in_ECX = (uint32_t*)self;
    in_ECX[0] = (uint32_t)(uintptr_t)PTR_FUN_006c19b0;
    if ((uint32_t*)in_ECX[0x57] != nullptr) {
        using DelFn = void(*)(int);
        ((DelFn)(*(void**)((uint32_t*)in_ECX[0x57])))(1);
    }
    if ((uint32_t*)in_ECX[0x58] != nullptr) {
        using DelFn = void(*)(int);
        ((DelFn)(*(void**)((uint32_t*)in_ECX[0x58])))(1);
    }
    FUN_00546260(self);
    uint32_t* puVar2 = (uint32_t*)(uintptr_t)in_ECX[0x65];
    if (puVar2 != nullptr) {
        int* piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using DelFn = void(*)(int);
            ((DelFn)(*(void**)*puVar2))(1);
        }
        in_ECX[0x65] = 0;
    }
    if ((uint32_t*)in_ECX[0x4a] != nullptr) {
        using DelFn = void(*)(int);
        ((DelFn)(*(void**)((uint32_t*)in_ECX[0x4a])))(1);
    }
    puVar2 = (uint32_t*)(uintptr_t)in_ECX[0x65];
    if (puVar2 != nullptr) {
        int* piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using DelFn = void(*)(int);
            ((DelFn)(*(void**)*puVar2))(1);
        }
    }
    in_ECX[0x61] = (uint32_t)(uintptr_t)PTR_FUN_006c1810;
    FUN_005e1490(self);
    in_ECX[0x61] = (uint32_t)(uintptr_t)PTR_FUN_006c179c;
    FUN_005e1490(self);
    operator_delete((void*)(uintptr_t)in_ECX[99]);
    operator_delete((void*)(uintptr_t)in_ECX[0x5d]);
    operator_delete((void*)(uintptr_t)in_ECX[0x59]);
    FUN_005461d0(self);
    FUN_005461d0(self);
    in_ECX[1] = (uint32_t)(uintptr_t)PTR_FUN_006c1798;
    operator_delete((void*)(uintptr_t)in_ECX[2]);
}

// 0x546bc0 — observed shape
void FUN_546bc0(void* self, uint32_t* param_1)
{
    uint32_t* puVar3 = param_1;
    if (param_1 != nullptr) {
        param_1[1] = param_1[1] + 1;
    }
    unsigned int uVar2 = *(unsigned int*)((intptr_t)self + 0x150);
    if (*(unsigned int*)((intptr_t)self + 0x14c) <= uVar2) {
        FUN_0057a3f0(*(int*)((intptr_t)self + 0x158) + (int)uVar2);
    }
    FUN_00581300(uVar2, &param_1);
    if (puVar3 != nullptr) {
        int* piVar1 = (int*)(puVar3 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using DelFn = void(*)(int);
            ((DelFn)(*(void**)*puVar3))(1);
        }
    }
}

extern char FUN_005bd960(const char* a, const void* b);
extern void FUN_00545e30(void* self);
extern void FUN_00551680(void* self);
extern void FUN_005465c0(void* self);
extern void FUN_00545f90(void* self);
extern short FUN_005453a0(int a, void* b);
extern void FUN_00545310(int a, unsigned int b);
extern void FUN_00545ab0(void* self);
extern void FUN_00546000(void* self);
extern void FUN_00545870(void* self);
extern void FUN_0056f540(void* self);

// 0x546cb0 — observed shape
uint32_t FUN_546cb0(void* self)
{
    intptr_t selfp = (intptr_t)self;
    int* p15c = *(int**)(selfp + 0x15c);
    uint8_t local_114[4] = {0};
    void* pvVar3 = thunk_FUN_00533c78((uint32_t)0 << 2);
    return 0;
}

extern void* PTR_FUN_006c17f4;
extern void* PTR_FUN_006c197c;
extern void* PTR_FUN_006c1a00;
extern void* PTR_FUN_006c1a90;
extern void operator_delete__(void* p);
extern void FUN_00551730(uint32_t v);
extern uint32_t FUN_0054a0c0(uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5,
                             uint32_t p6, uint32_t p7, uint32_t p8, uint32_t p9, uint32_t p10,
                             uint32_t p11);
extern void FUN_005517c0(int p);
extern int FUN_00557b10(int p);
extern int DAT_00727854;
extern void FUN_006b34a0(int p);
extern void FUN_005606f0(uint32_t idx, int* param);
extern void FUN_00545950(uint32_t v);
extern void FUN_005460e0(void* p);
extern int* DAT_00727864;

// 0x546f20 — observed shape
int FUN_546f20(void* self)
{
    int* in_ECX = (int*)self;
    using VtChar = char(*)(void*);
    using VtVoid = void(*)(void*);
    using VtNoArg = void(*)(void);
    char cVar3 = ((VtChar)(*(void**)(*in_ECX + 0x30)))(self);
    if (cVar3 == '\0') {
        return 0;
    }
    in_ECX[0x6a] = 0;
    in_ECX[0x69] = 0;
    in_ECX[0x68] = 0;
    FUN_00546260(self);
    uint32_t uVar5 = (uint32_t)in_ECX[7];
    if ((uVar5 >= 0x5000001) && (cVar3 = (char)FUN_546cb0(self), cVar3 == '\0')) {
        return 0;
    }
    if (0x5000005 < (uint32_t)in_ECX[7]) {
        FUN_00545e30(self);
    }
    uint32_t uVar4 = (uint32_t)in_ECX[0x68];
    uint32_t uVar1 = (uint32_t)in_ECX[0x4d];
    while (uVar4 < uVar1) {
        if (in_ECX[0x66] == 2) goto LAB_00547079;
        if (in_ECX[0x66] == 3) {
            FUN_00551680(self);
        }
        if (uVar5 < 0x5000001) {
            cVar3 = ((VtChar)(*(void**)(*in_ECX + 0x4c)))(self);
            if (cVar3 == '\0') goto LAB_00547079;
        } else {
            int* pObj = *(int**)((intptr_t)in_ECX[0x4c] + (intptr_t)in_ECX[0x68] * 4);
            ((VtVoid)(*(void**)(*pObj + 0xc)))(pObj);
        }
        uVar4 = (uint32_t)in_ECX[0x68] + 1;
        in_ECX[0x68] = (int)uVar4;
    }
    ((VtVoid)(*(void**)(*in_ECX + 0x44)))(self);
    uVar5 = (uint32_t)in_ECX[0x69];
    while (uVar5 < uVar1) {
        if (in_ECX[0x66] == 3) {
            FUN_00551680(self);
        }
        int* pObj = *(int**)((intptr_t)in_ECX[0x4c] + (intptr_t)in_ECX[0x69] * 4);
        ((VtVoid)(*(void**)(*pObj + 0x10)))(pObj);
        uVar5 = (uint32_t)in_ECX[0x69] + 1;
        in_ECX[0x69] = (int)uVar5;
    }
    uVar5 = (uint32_t)in_ECX[0x6a];
    while (uVar5 < uVar1) {
        if (in_ECX[0x66] == 3) {
            FUN_00551680(self);
        }
        int* pObj = *(int**)((intptr_t)in_ECX[0x4c] + (intptr_t)in_ECX[0x6a] * 4);
        ((VtVoid)(*(void**)(*pObj + 0x2c)))(pObj);
        uVar5 = (uint32_t)in_ECX[0x6a] + 1;
        in_ECX[0x6a] = (int)uVar5;
    }
    if (in_ECX[0x66] != 2) {
        if (in_ECX[0x66] == 3) {
            FUN_00551680(self);
        }
        int* iVar6 = (int*)DAT_00727828;
        uVar5 = 0;
        if ((*(int*)((intptr_t)iVar6 + 0x10) != 0) && (in_ECX[0x54] != 0)) {
            do {
                if ((*(int*)((intptr_t)in_ECX[0x52] + (intptr_t)uVar5 * 4) != 0) &&
                    (uVar4 = 0, iVar6 = (int*)DAT_00727828, *(int*)((intptr_t)iVar6 + 0xc) != 0)) {
                    do {
                        void* pcVar2 = *(void**)((intptr_t)*(int*)((intptr_t)iVar6 + 4) +
                                                 (intptr_t)uVar4 * 4);
                        if (pcVar2 != nullptr) {
                            ((VtNoArg)pcVar2)();
                            iVar6 = (int*)DAT_00727828;
                        }
                        uVar4 = uVar4 + 1;
                    } while (uVar4 < *(uint32_t*)((intptr_t)iVar6 + 0xc));
                }
                uVar5 = uVar5 + 1;
            } while (uVar5 < (uint32_t)in_ECX[0x54]);
        }
        if (in_ECX[0x66] != 2) {
            FUN_00545f90(self);
            FUN_005465c0(self);
            return 1;
        }
    }
LAB_00547079:
    FUN_005465c0(self);
    return 0;
}

// 0x547120 — observed shape
void FUN_547120(void* self)
{
    intptr_t in_ECX = (intptr_t)self;
    uint32_t local_10;
    uint32_t local_8;
    void** local_14;
    uint32_t* local_c;
    uint8_t local_4;
    uint32_t local_18;
    void* uStack_1c;
    int* piVar7;
    void* pvVar6;
    uint8_t local_24[4];
    uint8_t local_28[2];
    uint32_t uVar10;
    uint32_t unaff_EBX; // incoming EBX: callback table pointer, value not established by the listing

    local_14 = (void**)&PTR_FUN_006c17f4;
    local_10 = 0x25;
    local_8 = 0;
    local_c = (uint32_t*)thunk_FUN_00533c78(0x94);
    uint32_t* puVar5 = local_c;
    for (uVar10 = local_10; uVar10 != 0; uVar10 = uVar10 - 1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
    }
    local_4 = 0;
    uVar10 = 0;
    local_14 = (void**)&PTR_FUN_006c197c;
    if (*(int*)(in_ECX + 0x138) != 0) {
        do {
            int* pObj = *(int**)(*(int*)(in_ECX + 0x130) + (intptr_t)uVar10 * 4);
            uint32_t* puVar = (uint32_t*)((void*(*)(void*))(*(void**)(*pObj + 4)))(pObj);
            uint32_t uVar2 = *puVar;
            char cVar4 = FUN_005453a0((int)uVar2, &uStack_1c);
            if (cVar4 == '\0') {
                FUN_00545310((int)uVar2, local_8);
            }
            uVar10 = uVar10 + 1;
        } while (uVar10 < *(uint32_t*)(in_ECX + 0x138));
    }
    local_18 = local_8;
    pvVar6 = (void*)thunk_FUN_00533c78((local_8 & 0xffff) << 2);
    uVar10 = 0;
    uStack_1c = pvVar6;
    if (local_10 != 0) {
        do {
            if (local_c[uVar10] != 0) {
                piVar7 = (int*)local_c[uVar10];
                goto joined_r0x005471f3;
            }
            uVar10 = uVar10 + 1;
        } while (uVar10 < local_10);
    }
    int* pObj160 = *(int**)(in_ECX + 0x160);
    using VtWrite = void(*)(void*, void*, int);
    piVar7 = nullptr;
joined_r0x005471f3:
    do {
        if (piVar7 == nullptr) {
            ((VtWrite)(*(void**)(*pObj160 + 0xc)))(pObj160, &local_18, 2);
            uVar10 = 0;
            if ((short)unaff_EBX != 0) {
                do {
                    char* pcVar3 = *(char**)((intptr_t)pvVar6 + (intptr_t)uVar10 * 4);
                    int iLen;
                    if (pcVar3 == nullptr) {
                        iLen = 0;
                    } else {
                        char* pcVar8 = pcVar3;
                        char cVar4;
                        do {
                            cVar4 = *pcVar8;
                            pcVar8 = pcVar8 + 1;
                        } while (cVar4 != '\0');
                        iLen = (int)((intptr_t)pcVar8 - (intptr_t)(pcVar3 + 1));
                    }
                    ((VtWrite)(*(void**)(*pObj160 + 0xc)))(pObj160, local_24, 4);
                    if (iLen != 0) {
                        ((VtWrite)(*(void**)(*pObj160 + 0xc)))(pObj160, pcVar3, iLen);
                    }
                    uVar10 = uVar10 + 1;
                } while (uVar10 < (unaff_EBX & 0xffff));
            }
            operator_delete__(pvVar6);
            uVar10 = 0;
            if (*(int*)(in_ECX + 0x138) != 0) {
                do {
                    int* pObj = *(int**)(*(int*)(in_ECX + 0x130) + (intptr_t)uVar10 * 4);
                    uint32_t* puVar = (uint32_t*)((void*(*)(void*))(*(void**)(*pObj + 4)))(pObj);
                    uint32_t uVar2 = *puVar;
                    int iSlot = ((int(*)(uint32_t))(*(void**)((intptr_t)uStack_1c + 4)))(uVar2);
                    uint32_t* puVar5b = *(uint32_t**)((intptr_t)local_18 + (intptr_t)iSlot * 4);
                    char cVar4;
                    while ((puVar5b != nullptr) &&
                           (cVar4 = ((char(*)(uint32_t, uint32_t))
                                     (*(void**)(unaff_EBX + 8)))(uVar2, puVar5b[1]),
                            cVar4 == '\0')) {
                        puVar5b = (uint32_t*)*puVar5b;
                    }
                    ((VtWrite)(*(void**)(*pObj160 + 0xc)))(pObj160, local_28, 2);
                    uVar10 = uVar10 + 1;
                } while (uVar10 < *(uint32_t*)(in_ECX + 0x138));
            }
            FUN_00545ab0(self);
            return;
        }
        int iKey = piVar7[1];
        uint16_t uVar1 = *(uint16_t*)(piVar7 + 2);
        piVar7 = (int*)*piVar7;
        if (piVar7 == nullptr) {
            uVar10 = ((uint32_t(*)(int))(local_14[1]))(iKey);
            do {
                uVar10 = uVar10 + 1;
                if (local_10 <= uVar10) {
                    piVar7 = nullptr;
                    break;
                }
                piVar7 = (int*)local_c[uVar10];
            } while (piVar7 == nullptr);
            pvVar6 = uStack_1c;
        }
        *(int*)((intptr_t)pvVar6 + (intptr_t)uVar1 * 4) = iKey;
    } while (true);
}

// 0x547350 — observed shape
uint32_t FUN_547350(void* self)
{
    int* in_ECX = (int*)self;
    using VtVoid = void(*)(void*);
    ((VtVoid)(*(void**)(*in_ECX + 0x40)))(self);
    ((VtVoid)(*(void**)(*in_ECX + 0x34)))(self);
    FUN_547120(self);
    FUN_00546000(self);
    FUN_00545870(self);
    uint32_t uVar1 = 0;
    if (in_ECX[0x4e] != 0) {
        do {
            int* pObj = *(int**)((intptr_t)in_ECX[0x4c] + (intptr_t)uVar1 * 4);
            ((VtVoid)(*(void**)(*pObj + 0x18)))(pObj);
            uVar1 = uVar1 + 1;
        } while (uVar1 < (uint32_t)in_ECX[0x4e]);
    }
    ((VtVoid)(*(void**)(*in_ECX + 0x48)))(self);
    FUN_0056f540(self);
    FUN_005e1490(self);
    return 1;
}

// 0x5473c0 — observed shape
void FUN_5473c0(void* self, uint8_t param_1)
{
    FUN_546ad0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5473e0 — observed shape
void FUN_5473e0(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4,
               uint32_t param_5, uint32_t param_6, uint32_t param_7, uint32_t param_8,
               uint32_t param_9, uint32_t param_10, uint32_t param_11)
{
    uint32_t* in_ECX = (uint32_t*)self;
    intptr_t iVar1 = (intptr_t)FUN_00533c78(0x4c);
    if (iVar1 == 0) {
        FUN_00551730(0);
        in_ECX[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c1a00;
        return;
    }
    uint32_t uVar2 = FUN_0054a0c0(param_1, param_2, param_3, param_4, param_5, param_6, param_7,
                                  param_8, param_9, param_10, param_11);
    FUN_00551730(uVar2);
    in_ECX[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c1a00;
}

// 0x5475c0 — observed shape
void FUN_5475c0(int param_1)
{
    int iVar2 = param_1;
    FUN_005517c0(param_1);
    param_1 = FUN_00557b10(DAT_00727854);
    uint32_t uVar1 = *(uint32_t*)(iVar2 + 0xc);
    if (*(uint32_t*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
}

// 0x547620 — observed shape
void FUN_547620(void* self)
{
    uint32_t* in_ECX = (uint32_t*)self;
    in_ECX[0] = (uint32_t)(uintptr_t)&PTR_LAB_006fd148;
    in_ECX[1] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    in_ECX[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c1a90;
    in_ECX[2] = 0;
    in_ECX[3] = 0;
}

// 0x547650 — observed shape
void FUN_547650(void* self)
{
    uint32_t* in_ECX = (uint32_t*)self;
    in_ECX[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c1a90;
    operator_delete__((void*)(uintptr_t)in_ECX[2]);
    in_ECX[0] = (uint32_t)(uintptr_t)&PTR_LAB_006fd148;
    DAT_00727444 = DAT_00727444 + -1;
}

// 0x547680 — observed shape
void FUN_547680(int param_1, void* self)
{
    intptr_t in_ECX = (intptr_t)self;
    FUN_00545950(*(uint32_t*)(in_ECX + 8));
    int* pObj = *(int**)(param_1 + 0x160);
    using VtWrite = void(*)(void*, void*, int);
    ((VtWrite)(*(void**)(*pObj + 0xc)))(pObj, (void*)(in_ECX + 0xc), 4);
}

// 0x5476b0 — observed shape
void FUN_5476b0(void* self, uint8_t param_1)
{
    uint32_t* in_ECX = (uint32_t*)self;
    in_ECX[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c1a90;
    operator_delete__((void*)(uintptr_t)in_ECX[2]);
    in_ECX[0] = (uint32_t)(uintptr_t)&PTR_LAB_006fd148;
    DAT_00727444 = DAT_00727444 + -1;
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5476f0 — observed shape
void FUN_5476f0(int param_1, void* self)
{
    intptr_t in_ECX = (intptr_t)self;
    FUN_005460e0((void*)(in_ECX + 8));
    int* pObj = *(int**)(param_1 + 0x15c);
    using VtWrite = void(*)(void*, void*, int);
    ((VtWrite)(*(void**)(*pObj + 8)))(pObj, (void*)(in_ECX + 0xc), 4);
}

// 0x547730 — observed shape
uint32_t FUN_547730(uint32_t param_1, uint32_t param_2, uint32_t param_3)
{
    if ((param_1 == 0) || (DAT_00727864 == nullptr)) {
        return param_1 & 0xffffff00;
    }
    uint32_t (*fn)(uint32_t, uint32_t, uint32_t) =
        (uint32_t(*)(uint32_t, uint32_t, uint32_t))(*(void**)((intptr_t)*DAT_00727864 + 8));
    uint32_t uVar1 = fn(param_1, param_2, param_3);
    return uVar1;
}

// 0x547760 — observed shape
uint32_t FUN_547760(uint32_t param_1)
{
    if ((param_1 == 0) || (DAT_00727864 == nullptr)) {
        return param_1 & 0xffffff00;
    }
    uint32_t (*fn)(uint32_t) =
        (uint32_t(*)(uint32_t))(*(void**)((intptr_t)*DAT_00727864 + 0xc));
    uint32_t uVar1 = fn(param_1);
    return uVar1;
}

// 0x5477a0 — observed shape
uint32_t FUN_5477a0(uint32_t param_1)
{
    uint32_t uVar1 = (uint32_t)(intptr_t)DAT_00727864 >> 8;
    if (DAT_00727864 == nullptr) {
        return 0;
    }
    *(uint32_t*)((intptr_t)DAT_00727864 + 8) = param_1;
    return (uVar1 & 0xffffff00) | 1u;
}
