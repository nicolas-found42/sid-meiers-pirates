#include <cstdint>
#include <cstddef>
#include <cstdio>

extern void FUN_005eddb0(void* self);
extern void operator_delete(void* ptr);
extern void FUN_005c9a80(uint32_t param_1, void* local_30c, void* local_104, void* local_208, void* local_308);

// 0x5ee000 — observed shape
void FUN_005ee000(void* self, uint8_t param_1)
{
    FUN_005eddb0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5ee090 — observed shape
uint32_t FUN_005ee090(uint32_t param_1, char* param_2)
{
    uint8_t local_30c[4];
    char local_308[256];
    uint8_t local_208[260];
    uint8_t local_104[260];

    FUN_005c9a80(param_1, local_30c, local_104, local_208, local_308);
    if (local_308[0] == '\0') {
        std::sprintf(param_2, "%s.vsh", (char*)local_208);
        return 1;
    }
    std::sprintf(param_2, "%s%s", (char*)local_208, local_308);
    return 1;
}

// 0x5ee120 — observed shape
uint32_t FUN_005ee120(uint32_t param_1, char* param_2)
{
    uint8_t local_30c[4];
    char local_308[256];
    uint8_t local_208[260];
    uint8_t local_104[260];

    FUN_005c9a80(param_1, local_30c, local_104, local_208, local_308);
    if (local_308[0] == '\0') {
        std::sprintf(param_2, "%s.psh", (char*)local_208);
        return 1;
    }
    std::sprintf(param_2, "%s%s", (char*)local_208, local_308);
    return 1;
}

// 0x5ee1b0 — observed shape
void FUN_005ee1b0(void* self, uint32_t* param_1)
{
    uint32_t* puVar2 = *(uint32_t**)((uint8_t*)self + 0x4c);
    if (puVar2 != param_1) {
        if (puVar2 != (uint32_t*)0x0) {
            int* piVar1 = (int*)(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                using ReleaseFn = void(__thiscall*)(void*, int);
                ReleaseFn fn = (ReleaseFn)(*puVar2);
                fn(puVar2, 1);
            }
        }
        *(uint32_t**)((uint8_t*)self + 0x4c) = param_1;
        if (param_1 != (uint32_t*)0x0) {
            param_1[1] = param_1[1] + 1;
        }
    }
}

// 0x5ee1e0 — observed shape
void FUN_005ee1e0(void* self, uint32_t* param_1)
{
    uint32_t* puVar2 = *(uint32_t**)((uint8_t*)self + 0x60);
    if (puVar2 != param_1) {
        if (puVar2 != (uint32_t*)0x0) {
            int* piVar1 = (int*)(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                using ReleaseFn = void(__thiscall*)(void*, int);
                ReleaseFn fn = (ReleaseFn)(*puVar2);
                fn(puVar2, 1);
            }
        }
        *(uint32_t**)((uint8_t*)self + 0x60) = param_1;
        if (param_1 != (uint32_t*)0x0) {
            param_1[1] = param_1[1] + 1;
        }
    }
}

extern void _eh_vector_destructor_iterator_(void* ptr, uint32_t elemSize, int count, void (*dtor)(void*));
extern void _eh_vector_destructor_iterator_(void* ptr, uint32_t elemSize, int count, void (*dtor)(int));
extern void operator_delete__(void* ptr);
extern void FUN_005e4780(void* ptr);
extern void* PTR_FUN_006ca168;
extern void* PTR_FUN_006ca170;
extern void* ExceptionList;
extern void FUN_005da790(void* self);
extern uint32_t FUN_005da2b0(uint32_t param_1, uint32_t param_2, int param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7, uint32_t param_8);
extern void FUN_005c2c50(uint32_t param_1, uint32_t param_2, int param_3, uint32_t param_4, int param_5);
extern void FUN_005c11d0(uint32_t param_1, int param_2);
extern int FUN_005c8ec0(char* local_104, char* pcVar1, uint32_t uVar3, uint32_t uVar2, uint32_t uVar5);

// 0x5ee210 — observed shape
void FUN_005ee210(void* self)
{
    uint32_t* in_ECX = (uint32_t*)self;
    void* pvVar1 = (void*)in_ECX[1];
    in_ECX[0] = (uint32_t)(&PTR_FUN_006ca168);
    if (pvVar1 != (void*)0x0) {
        _eh_vector_destructor_iterator_(pvVar1, 4, *(int*)((int)pvVar1 + -4), FUN_005e4780);
        operator_delete__((void*)((int)pvVar1 + -4));
    }
}

// 0x5ee240 — observed shape
void FUN_005ee240(void* self, uint8_t param_1)
{
    uint32_t* in_ECX = (uint32_t*)self;
    void* pvVar1 = (void*)in_ECX[1];
    in_ECX[0] = (uint32_t)(&PTR_FUN_006ca168);
    if (pvVar1 != (void*)0x0) {
        _eh_vector_destructor_iterator_(pvVar1, 4, *(int*)((int)pvVar1 + -4), FUN_005e4780);
        operator_delete__((void*)((int)pvVar1 + -4));
    }
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
}

// 0x5ee290 — observed shape
void FUN_005ee290(void* self)
{
    uint32_t* in_ECX = (uint32_t*)self;
    void* pvStack_c;
    uint8_t* puStack_8;
    int local_4;

    puStack_8 = (uint8_t*)0x006b9fbe;
    pvStack_c = ExceptionList;
    ExceptionList = &pvStack_c;
    in_ECX[0] = (uint32_t)(&PTR_FUN_006ca170);
    void* pvVar2 = (void*)in_ECX[0x1d];
    local_4 = 2;
    in_ECX[0x1c] = (uint32_t)(&PTR_FUN_006ca168);
    if (pvVar2 != (void*)0x0) {
        _eh_vector_destructor_iterator_(pvVar2, 4, *(int*)((int)pvVar2 + -4), FUN_005e4780);
        operator_delete__((void*)((int)pvVar2 + -4));
    }
    uint32_t* puVar3 = (uint32_t*)in_ECX[0x1b];
    local_4 = (local_4 & 0xFFFFFF00) | 1;
    if (puVar3 != (uint32_t*)0x0) {
        int* piVar1 = (int*)(puVar3 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using ReleaseFn = void(__thiscall*)(void*, int);
            ReleaseFn fn = (ReleaseFn)(*puVar3);
            fn(puVar3, 1);
        }
    }
    puVar3 = (uint32_t*)in_ECX[0x1a];
    local_4 = (local_4 & 0xFFFF00FF) | ((uint32_t)local_4 << 8 & 0xFFFFFF00);
    if (puVar3 != (uint32_t*)0x0) {
        int* piVar1 = (int*)(puVar3 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using ReleaseFn = void(__thiscall*)(void*, int);
            ReleaseFn fn = (ReleaseFn)(*puVar3);
            fn(puVar3, 1);
        }
    }
    local_4 = 0xffffffff;
    FUN_005da790(self);
    ExceptionList = pvStack_c;
}

// 0x5ee360 — observed shape
uint32_t FUN_005ee360(void* self, uint32_t param_1, uint32_t param_2, int param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7, uint32_t param_8)
{
    int iVar1;
    uint32_t uVar2;
    uint16_t uVar3;

    if ((4 < *(uint32_t*)((uint8_t*)self + 0x58)) && (param_3 != 0)) {
        if (*(int*)((uint8_t*)self + 0x34) == 0) {
            FUN_005c2c50(param_2, param_7, 1, *(uint32_t*)((uint8_t*)self + 0x5c), (*(int*)((uint8_t*)self + 0x60) == 1) ? 1 : 0);
        }
        using CallFn = void(__thiscall*)(void*, uint16_t);
        uint32_t* vtbl = *(uint32_t**)((uint8_t*)self + 0x18);
        CallFn fn = (CallFn)vtbl[0x30 / 4];
        fn(vtbl, *(uint16_t*)((uint8_t*)param_3 + 0x24));
        FUN_005c11d0(param_7, 0);
        return 0;
    }
    iVar1 = *(int*)(*(int*)((uint8_t*)self + 0x44) + *(int*)((uint8_t*)self + 0x34) * 4);
    if ((iVar1 == 0) || (iVar1 = *(int*)(iVar1 + 0x60), iVar1 == 0)) {
        uVar2 = FUN_005da2b0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
        return uVar2;
    }
    if (*(int*)((uint8_t*)self + 0x34) == 0) {
        if (param_3 != 0) {
            FUN_005c2c50(param_2, param_7, 1, *(uint32_t*)((uint8_t*)self + 0x5c),
                         ((iVar1 >> 8) & 0xFFFFFF) | ((*(int*)((uint8_t*)self + 0x60) == 1) ? 1 : 0));
            if (param_3 != 0) {
                uVar3 = *(uint16_t*)((uint8_t*)param_3 + 0x24);
                using CallFn = void(__thiscall*)(void*, uint16_t);
                uint32_t* vtbl = *(uint32_t**)((uint8_t*)self + 0x18);
                CallFn fn = (CallFn)vtbl[0x30 / 4];
                fn(vtbl, uVar3);
                FUN_005c11d0(param_7, 0);
                return 0;
            }
        }
    }
    if (param_3 != 0) {
        uVar3 = *(uint16_t*)((uint8_t*)param_3 + 0x24);
    } else {
        uVar3 = 0;
    }
    {
        using CallFn = void(__thiscall*)(void*, uint16_t);
        uint32_t* vtbl = *(uint32_t**)((uint8_t*)self + 0x18);
        CallFn fn = (CallFn)vtbl[0x30 / 4];
        fn(vtbl, uVar3);
    }
    FUN_005c11d0(param_7, 0);
    return 0;
}

// 0x5ee460 — observed shape
uint32_t FUN_005ee460(void* self, int param_1)
{
    char* pcVar1 = *(char**)(param_1 + 0x54);
    if (pcVar1 != (char*)0x0) {
        int iVar6 = 1;
        bool bVar9 = true;
        char* pcVar7 = pcVar1;
        char* pcVar8 = (char*)"";
        do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar9 = *pcVar7 == *pcVar8;
            pcVar7 = pcVar7 + 1;
            pcVar8 = pcVar8 + 1;
        } while (bVar9);
        if (!bVar9) {
            uint8_t local_104[260];
            char cVar4 = (char)FUN_005ee090((uint32_t)pcVar1, (char*)local_104);
            if (cVar4 != '\0') {
                uint32_t uVar2 = *(uint32_t*)(param_1 + 0x5c);
                uint32_t uVar3 = *(uint32_t*)(param_1 + 0x58);
                using CallFn = uint32_t(__thiscall*)(void*, uint32_t, uint8_t);
                uint32_t* vtbl = *(uint32_t**)((uint8_t*)self + 0x24);
                CallFn fn = (CallFn)vtbl[0x54 / 4];
                uint32_t uVar5 = fn(vtbl, 0, *(uint8_t*)(param_1 + 100));
                iVar6 = FUN_005c8ec0((char*)local_104, pcVar1, uVar3, uVar2, uVar5);
                if (iVar6 != 0) {
                    FUN_005ee1e0(self, (uint32_t*)iVar6);
                    return 1;
                }
            }
            return 0;
        }
    }
    return 1;
}

extern char FUN_005c8f40(uint8_t* local_104, char* pcVar1, uint32_t uVar3, uint32_t uVar2);
extern void FUN_005d3e10(void);
extern void FUN_005d3090(uint32_t param_1, void* local_14);
extern uint8_t LAB_006ba001;
extern char FUN_005da280(uint32_t param_1);
extern void* FUN_005ea390(void);
extern void* FUN_005ea3b0(void);
extern char FUN_005ef190(uint32_t param_1, int* param_2);
extern char FUN_005efdd0(uint32_t param_1, uint32_t param_2, int* local_4);
extern void FUN_005ca4e0(uint32_t param_1, int local_4, uint8_t flag);
extern char FUN_005f0020(uint32_t param_1, int* param_2);
extern char FUN_005f05b0(uint32_t param_1, uint32_t param_2, int* local_4);
extern void FUN_005d7d70(uint32_t param_1, int local_4, uint8_t flag);
extern char FUN_005f06c0(uint32_t param_1, uint32_t param_2, uint32_t* param_3);
extern void FUN_005d7e40(uint32_t param_1, uint32_t param_2, uint8_t flag);
extern void FUN_005ec150(void* local_c, void* local_8);
extern int* FUN_005d74c0(int param_1, uint32_t local_8, uint32_t local_c);
extern int* FUN_005ec110(void);
extern int* FUN_005ec130(void);
extern uint32_t thunk_FUN_005eecd0(uint32_t param_1);

// 0x5ee500 — observed shape
uint32_t FUN_005ee500(void* self)
{
    char* pcVar1 = *(char**)((uint8_t*)self + 0x40);
    uint8_t local_104[260];

    if (pcVar1 != (char*)0x0) {
        int iVar3 = 1;
        bool bVar6 = true;
        char* pcVar4 = pcVar1;
        char* pcVar5 = (char*)"";
        do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar6 = *pcVar4 == *pcVar5;
            pcVar4 = pcVar4 + 1;
            pcVar5 = pcVar5 + 1;
        } while (bVar6);
        if (!bVar6) {
            char cVar2 = (char)FUN_005ee120((uint32_t)pcVar1, (char*)local_104);
            if (cVar2 == '\0') {
                return 0;
            }
            iVar3 = FUN_005c8f40(local_104, pcVar1, *(uint32_t*)((uint8_t*)self + 0x44),
                                 *(uint32_t*)((uint8_t*)self + 0x48));
            if (iVar3 == 0) {
                return 0;
            }
            FUN_005ee1b0(self, (uint32_t*)iVar3);
            return 1;
        }
    }
    return 1;
}

// 0x5ee580 — observed shape
void FUN_005ee580(void* self)
{
    uint32_t* in_ECX = (uint32_t*)self;
    uint32_t local_14[2];
    void* local_c;
    uint8_t* puStack_8;
    uint32_t local_4;

    local_4 = 0xffffffff;
    puStack_8 = &LAB_006ba001;
    local_c = ExceptionList;
    ExceptionList = &local_c;
    FUN_005d3e10();
    uint32_t uVar1 = 0;
    in_ECX[0] = (uint32_t)(&PTR_FUN_006ca170);
    in_ECX[0x16] = 0;
    in_ECX[0x17] = 0;
    in_ECX[0x18] = 0;
    in_ECX[0x19] = 0;
    in_ECX[0x1a] = 0;
    in_ECX[0x1b] = 0;
    in_ECX[0x1c] = (uint32_t)(&PTR_FUN_006ca168);
    in_ECX[0x1e] = 0;
    in_ECX[0x21] = 1;
    in_ECX[0x1f] = 0;
    in_ECX[0x20] = 0;
    in_ECX[0x1d] = 0;
    local_4 = (local_4 & 0x000000FFu);
    if (in_ECX[0x12] != 0) {
        local_14[0] = 0;
        do {
            local_4 = (local_4 & 0xFFFFFF00u) | 5u;
            FUN_005d3090(uVar1, local_14);
            uVar1 = uVar1 + 1;
        } while (uVar1 < in_ECX[0x12]);
    }
    ExceptionList = local_c;
}

// 0x5ee630 — observed shape
void FUN_005ee630(void* self, uint8_t param_1)
{
    FUN_005ee290(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5ee650 — observed shape
uint8_t FUN_005ee650(void* self, uint32_t param_1)
{
    if (*(uint8_t*)((uint8_t*)self + 0x1c) == '\0') {
        char cVar3 = FUN_005da280(param_1);
        if (cVar3 == '\0') {
            return 0;
        }
        uint32_t uVar1 = *(uint32_t*)((uint8_t*)self + 0x4c);
        uint32_t uVar4 = 0;
        if (uVar1 != 0) {
            do {
                int iVar2 = *(int*)(*(int*)((uint8_t*)self + 0x44) + uVar4 * 4);
                if (iVar2 != 0) {
                    FUN_005ee460(self, iVar2);
                    FUN_005ee500((void*)iVar2);
                }
                uVar4 = uVar4 + 1;
            } while (uVar4 < uVar1);
        }
        *(uint8_t*)((uint8_t*)self + 0x1c) = 1;
    }
    return *(uint8_t*)((uint8_t*)self + 0x1c);
}

// 0x5eeb10 — observed shape
uint32_t FUN_005eeb10(void* self, int param_1)
{
    int local_4;

    if (*(uint32_t*)((uint8_t*)self + 0x10) == 0) {
        return 0;
    }
    local_4 = (int)(intptr_t)self;
    uint32_t* puVar2 = (uint32_t*)FUN_005ea390();
    while (puVar2 != (uint32_t*)0x0) {
        if (((((*puVar2 >> 1 & 1) == 0) &&
              (FUN_005ef190(puVar2[1], &param_1) != '\0')) &&
             (FUN_005efdd0(puVar2[1], puVar2[2], &local_4) != '\0')) &&
            (param_1 != 0x7fffffff)) {
            FUN_005ca4e0((uint32_t)param_1, local_4, (uint8_t)*puVar2 & 1);
        }
        puVar2 = (uint32_t*)FUN_005ea3b0();
    }
    return 1;
}

// 0x5eebb0 — observed shape
uint32_t FUN_005eebb0(void* self, int param_1)
{
    int local_4;

    if (*(uint32_t*)((uint8_t*)self + 0x10) == 0) {
        return 0;
    }
    local_4 = (int)(intptr_t)self;
    uint32_t* puVar2 = (uint32_t*)FUN_005ea390();
    while (puVar2 != (uint32_t*)0x0) {
        if (((((*puVar2 >> 1 & 1) == 0) &&
              (FUN_005f0020(puVar2[1], &param_1) != '\0')) &&
             (FUN_005f05b0(puVar2[1], puVar2[2], &local_4) != '\0')) &&
            (param_1 != 0x7fffffff)) {
            FUN_005d7d70((uint32_t)param_1, local_4, (uint8_t)*puVar2 & 1);
        }
        puVar2 = (uint32_t*)FUN_005ea3b0();
    }
    return 1;
}

// 0x5eec50 — observed shape
uint32_t FUN_005eec50(void* self, uint32_t param_1)
{
    if (*(uint32_t*)((uint8_t*)self + 0x10) == 0) {
        return 0;
    }
    uint32_t* puVar2 = (uint32_t*)FUN_005ea390();
    while (puVar2 != (uint32_t*)0x0) {
        if ((((*puVar2 >> 1 & 1) == 0) &&
             (FUN_005f06c0(puVar2[1], puVar2[2], &param_1) != '\0')) &&
            (puVar2[1] != 0x7fffffff)) {
            FUN_005d7e40(puVar2[1], param_1, (uint8_t)*puVar2 & 1);
        }
        puVar2 = (uint32_t*)FUN_005ea3b0();
    }
    return 1;
}

// 0x5eecd0 — observed shape
uint32_t FUN_005eecd0(uint32_t param_1)
{
    switch (param_1) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 5;
    default:
        return 0xffffffff;
    case 7:
        return 6;
    case 9:
        return 7;
    case 0xb:
        return 9;
    case 0xd:
        return 10;
    case 0x14:
        return 8;
    case 0x15:
        return 0xb;
    case 0x16:
        return 0xc;
    case 0x17:
        return 0xd;
    case 0x18:
        return 0xe;
    case 0x19:
        return 0xf;
    case 0x1a:
        return 0x10;
    }
}

// 0x5eede0 — observed shape
int* FUN_005eede0(int param_1)
{
    uint32_t local_c = 0;
    uint32_t local_8[2] = { 0, 0 };

    FUN_005ec150(&local_c, local_8);
    int* piVar2 = FUN_005d74c0(param_1, local_8[0], local_c);
    if (piVar2 == (int*)0x0) {
        return (int*)0x0;
    }
    param_1 = -1;
    int* piVar3 = FUN_005ec110();
    if (piVar3 != (int*)0x0) {
        int iVar5 = 0;
        do {
            uint32_t uVar4 = thunk_FUN_005eecd0((uint32_t)piVar3[3]);
            int iVar1 = *piVar3;
            if (param_1 != iVar1) {
                iVar5 = 0;
                param_1 = iVar1;
            }
            if (piVar3[5] == 0xe) {
                using CallFn38 = void(__thiscall*)(void*, int, int, int, uint32_t, int);
                uint32_t* vtbl = (uint32_t*)*piVar2;
                CallFn38 fn = (CallFn38)vtbl[0x38 / 4];
                fn(piVar2, iVar5, piVar3[1], piVar3[2], uVar4, iVar1);
            } else {
                using CallFn34 = void(__thiscall*)(void*, int, int, int, int, uint32_t, int, int, int);
                uint32_t* vtbl = (uint32_t*)*piVar2;
                CallFn34 fn = (CallFn34)vtbl[0x34 / 4];
                fn(piVar2, iVar1, iVar5, piVar3[1], piVar3[2], uVar4, piVar3[5], piVar3[6], piVar3[4]);
            }
            iVar5 = iVar5 + 1;
            piVar3 = FUN_005ec130();
        } while (piVar3 != (int*)0x0);
    }
    return piVar2;
}

// 0x5eeec0 — observed shape
void FUN_005eeec0(void* self)
{
    uint32_t* in_ECX = (uint32_t*)self;

    in_ECX[0] = 0;
    in_ECX[1] = 0;
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    *(uint8_t*)((uint8_t*)self + 20) = 0;
    in_ECX[0x16] = 0;
    in_ECX[0x17] = 0;
    in_ECX[6] = 0x3f800000;
    in_ECX[7] = 0;
    in_ECX[8] = 0;
    in_ECX[9] = 0;
    in_ECX[10] = 0;
    in_ECX[0xb] = 0x3f800000;
    in_ECX[0xc] = 0;
    in_ECX[0xd] = 0;
    in_ECX[0xe] = 0;
    in_ECX[0xf] = 0;
    in_ECX[0x10] = 0x3f800000;
    in_ECX[0x11] = 0;
    in_ECX[0x12] = 0;
    in_ECX[0x13] = 0;
    in_ECX[0x14] = 0;
    in_ECX[0x15] = 0x3f800000;
}
