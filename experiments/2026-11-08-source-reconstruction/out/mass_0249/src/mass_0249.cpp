#include <cstdint>
#include <cstddef>
#include <windows.h>

typedef uint32_t undefined4;
typedef uint8_t undefined1;
typedef uint8_t byte;
typedef uint8_t undefined;
using code = void (*)(int);
using code_ret = char (*)(int);
using code2 = undefined4* (*)(undefined4, undefined4);

extern void* ExceptionList;
extern void* _except_handler3;
extern char FUN_006b5090(int param_1, void* param_2);
extern void* FUN_00533c78(unsigned int size);
extern char FUN_006b5020(undefined4 param_1, void* param_2);
extern char FUN_006b5020(int param_1);
extern void operator_delete(void* ptr);
extern void* PTR_FUN_006c9fd0;
extern void FUN_006b34a0(int param_1);
extern undefined1 FUN_005ece70(void* self);
extern undefined4 FUN_005dbe30();
extern int FUN_005dbe20();
extern void* FUN_005ca610();
extern char thunk_FUN_005eeb10(void* param_1);
extern void FUN_005ca3d0();
extern int* FUN_005bf670(int* param_1);
extern char FUN_005ed740(int param_1, undefined4 param_2);
extern void FUN_005bf480();
extern undefined4 FUN_005ecae0(void* self, uint32_t param_1, int param_2);
extern undefined1 FUN_005ece80(void* self);
extern undefined4 FUN_005ece90(void* self);
extern undefined4 FUN_005ecea0(void* self);
extern undefined4 FUN_005eceb0(void* self);
extern undefined4 FUN_005ece40(void* self);
extern char FUN_006b5090(int param_1);
extern void FUN_005edba0();
extern void* FUN_006b3c00();
extern void* PTR_FUN_006c9928;
extern void* PTR_LAB_006c991c;
using code_voidp = void* (*)();
extern void FUN_005ea3c0();
extern void FUN_00497420();
extern void FUN_005ed2b0();
extern int FUN_005ed210();
extern void FUN_005606f0(uint32_t param_1, int* param_2);
extern char FUN_005ed9e0(uint32_t param_1);
extern void FUN_005d3a60(int param_1);
extern void FUN_005d3090(uint32_t param_1, uint32_t* param_2);
extern void FUN_005e90f0(undefined4 param_1);
extern uint32_t DAT_007187cc;
extern char FUN_005e8960(int param_1, void* param_2);
extern char FUN_005e8880(int param_1, undefined4* param_2);
extern int FUN_005edf90();
extern void FUN_0051ac30(undefined4 param_1);
extern int FUN_005ec480(void* self, int param_1);
extern undefined1 FUN_005ec830(void* self, uint32_t param_1);
extern undefined4 FUN_005ecec0(void* self, int param_1);
extern bool FUN_005ec520(void* self, undefined4 param_1);

// 0x5ec480 — observed shape
int FUN_005ec480(void* self, int param_1)
{
    int iVar1;
    char cVar2;
    int iVar3;
    undefined4 uVar4;
    void* local_c;
    undefined1* puStack_8;
    undefined4 local_4;

    iVar1 = param_1;
    local_4 = 0xffffffff;
    puStack_8 = (undefined1*)0x006b9d5b;
    local_c = ExceptionList;
    ExceptionList = &local_c;
    cVar2 = FUN_006b5090(param_1, &param_1);
    if (cVar2 == '\0') {
        ExceptionList = local_c;
        return 0;
    }
    if (param_1 == 1) {
        iVar3 = (int)FUN_00533c78(0x24);
        local_4 = 0;
        if (iVar3 == 0) {
            uVar4 = 0;
        }
        else {
            uVar4 = FUN_005ece40((void*)iVar3);
        }
        local_4 = 0xffffffff;
        *(undefined4*)((char*)self + 0x10) = uVar4;
        cVar2 = (char)FUN_005ecec0((void*)uVar4, iVar1);
        if (cVar2 == '\0') {
            ExceptionList = local_c;
            return 0;
        }
    }
    ExceptionList = local_c;
    return 1;
}

// 0x5ec520 — observed shape
bool FUN_005ec520(void* self, undefined4 param_1)
{
    char cVar1;

    cVar1 = FUN_006b5020(param_1, (char*)self + 0x18);
    return cVar1 != '\0';
}

// 0x5ec540 — observed shape
void FUN_005ec540(void* self)
{
    undefined4* in_ECX = (undefined4*)self;

    *in_ECX = (undefined4)PTR_FUN_006c9fd0;
    operator_delete((void*)in_ECX[1]);
    return;
}

// 0x5ec560 — observed shape
void FUN_005ec560(void* self, byte param_1)
{
    undefined4* in_ECX = (undefined4*)self;

    *in_ECX = (undefined4)PTR_FUN_006c9fd0;
    operator_delete((void*)in_ECX[1]);
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
    return;
}

// 0x5ec590 — observed shape
void FUN_005ec590(void* self)
{
    undefined4* in_ECX = (undefined4*)self;
    void* local_c;
    undefined1* puStack_8;
    undefined4 local_4;

    puStack_8 = (undefined1*)0x006b9d86;
    local_c = ExceptionList;
    ExceptionList = &local_c;
    *in_ECX = 0;
    in_ECX[1] = 0;
    in_ECX[2] = 0;
    in_ECX[3] = 0xffffffff;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    in_ECX[6] = 0;
    in_ECX[7] = 0;
    in_ECX[8] = 0;
    in_ECX[9] = 0;
    in_ECX[10] = (undefined4)PTR_FUN_006c9fd0;
    in_ECX[0xc] = 0;
    in_ECX[0xf] = 1;
    in_ECX[0xd] = 0;
    in_ECX[0xe] = 0;
    in_ECX[0xb] = 0;
    local_4 = 1;
    in_ECX[0xd] = 0;
    in_ECX[0xe] = 0;
    FUN_006b34a0(4);
    ExceptionList = local_c;
    return;
}

// 0x5ec630 — observed shape
void FUN_005ec630(void* self)
{
    int* piVar1;
    void* pvVar2;
    undefined4* puVar3;
    uint32_t uVar4;
    undefined4* in_ECX = (undefined4*)self;
    uint32_t uVar5;
    void* pvStack_c;
    undefined1* puStack_8;
    undefined4 local_4;

    puStack_8 = (undefined1*)0x006b9d86;
    pvStack_c = ExceptionList;
    local_4 = 1;
    ExceptionList = &pvStack_c;
    if ((undefined4*)in_ECX[9] != (undefined4*)0x0) {
        ExceptionList = &pvStack_c;
        (*(code*)**(undefined4**)in_ECX[9])(1);
    }
    if ((undefined4*)in_ECX[8] != (undefined4*)0x0) {
        (*(code*)**(undefined4**)in_ECX[8])(1);
    }
    pvVar2 = (void*)in_ECX[7];
    if (pvVar2 != (void*)0x0) {
        FUN_005ea3c0();
        operator_delete(pvVar2);
    }
    pvVar2 = (void*)in_ECX[4];
    if (pvVar2 != (void*)0x0) {
        FUN_00497420();
        operator_delete(pvVar2);
    }
    operator_delete((void*)in_ECX[6]);
    operator_delete((void*)in_ECX[2]);
    operator_delete((void*)in_ECX[1]);
    operator_delete((void*)*in_ECX);
    uVar4 = in_ECX[0xd];
    uVar5 = 0;
    if (uVar4 != 0) {
        do {
            pvVar2 = *(void**)(in_ECX[0xb] + uVar5 * 4);
            if (pvVar2 != (void*)0x0) {
                FUN_005ed2b0();
                operator_delete(pvVar2);
                if (uVar5 < (uint32_t)in_ECX[0xc]) {
                    if (uVar5 < (uint32_t)in_ECX[0xd]) {
                        if (*(int*)(in_ECX[0xb] + uVar5 * 4) != 0) {
                            in_ECX[0xe] = in_ECX[0xe] + -1;
                        }
                    }
                    else {
                        in_ECX[0xd] = uVar5 + 1;
                    }
                    *(undefined4*)(in_ECX[0xb] + uVar5 * 4) = 0;
                }
            }
            uVar5 = uVar5 + 1;
        } while (uVar5 < uVar4);
    }
    uVar4 = 0;
    if (in_ECX[0xd] != 0) {
        do {
            *(undefined4*)(in_ECX[0xb] + uVar4 * 4) = 0;
            uVar4 = uVar4 + 1;
        } while (uVar4 < (uint32_t)in_ECX[0xd]);
    }
    in_ECX[0xd] = 0;
    in_ECX[0xe] = 0;
    in_ECX[10] = (undefined4)PTR_FUN_006c9fd0;
    operator_delete((void*)in_ECX[0xb]);
    puVar3 = (undefined4*)in_ECX[5];
    local_4 = 0xffffffff;
    if (puVar3 != (undefined4*)0x0) {
        piVar1 = puVar3 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (**(code**)*puVar3)(1);
        }
    }
    ExceptionList = pvStack_c;
    return;
}

// 0x5ec780 — observed shape
int FUN_005ec780(void* self, uint32_t param_1, int param_2)
{
    int iVar1;
    void* local_c;
    undefined1* puStack_8;
    undefined4 local_4;

    local_4 = 0xffffffff;
    puStack_8 = (undefined1*)0x006b9d9b;
    local_c = ExceptionList;
    iVar1 = 0;
    if (((*(uint32_t*)((char*)self + 0x34) <= param_1) ||
         (iVar1 = *(int*)(*(int*)((char*)self + 0x2c) + param_1 * 4), iVar1 == 0)) &&
        ((char)param_2 != '\0')) {
        ExceptionList = &local_c;
        param_2 = (int)FUN_00533c78(0x58);
        local_4 = 0;
        if (param_2 == 0) {
            iVar1 = 0;
        }
        else {
            iVar1 = FUN_005ed210();
        }
        local_4 = 0xffffffff;
        param_2 = iVar1;
        if (*(uint32_t*)((char*)self + 0x30) <= param_1) {
            FUN_006b34a0(*(int*)((char*)self + 0x3c) + param_1);
        }
        FUN_005606f0(param_1, &param_2);
    }
    ExceptionList = local_c;
    return iVar1;
}

// 0x5ec830 — observed shape
undefined1 FUN_005ec830(void* self, uint32_t param_1)
{
    uint32_t uVar1;
    char cVar2;
    uint32_t uVar3;
    int local_10;
    void* local_c;
    undefined1* puStack_8;
    undefined4 local_4;

    uVar1 = param_1;
    local_4 = 0xffffffff;
    puStack_8 = (undefined1*)0x006b9d5b;
    local_c = ExceptionList;
    ExceptionList = &local_c;
    cVar2 = FUN_006b5090(param_1, &param_1);
    if (cVar2 == '\0') {
        ExceptionList = local_c;
        return 0;
    }
    FUN_006b34a0(param_1);
    uVar3 = 0;
    if (param_1 != 0) {
        do {
            local_10 = (int)FUN_00533c78(0x58);
            local_4 = 0;
            if (local_10 == 0) {
                local_10 = 0;
            }
            else {
                local_10 = FUN_005ed210();
            }
            local_4 = 0xffffffff;
            cVar2 = FUN_005ed9e0(uVar1);
            if (cVar2 == '\0') {
                ExceptionList = local_c;
                return 0;
            }
            FUN_005606f0(uVar3, &local_10);
            uVar3 = uVar3 + 1;
        } while (uVar3 < param_1);
    }
    ExceptionList = local_c;
    return 1;
}

// 0x5ec910 — observed shape
bool FUN_005ec910(void* self, int param_1)
{
    int* piVar1;
    undefined4* puVar2;
    void* pvVar3;
    int iVar4;
    char cVar5;
    int iVar6;
    undefined4 uVar7;
    void* local_c;
    undefined1* puStack_8;
    undefined4 local_4;

    iVar4 = param_1;
    local_4 = 0xffffffff;
    puStack_8 = (undefined1*)0x006b9d5b;
    local_c = ExceptionList;
    ExceptionList = &local_c;
    cVar5 = FUN_006b5020(param_1);
    if (cVar5 == '\0') {
        ExceptionList = local_c;
        return false;
    }
    cVar5 = FUN_006b5020(iVar4, (char*)self + 4);
    if (cVar5 == '\0') {
        ExceptionList = local_c;
        return false;
    }
    if ((0x10004 < DAT_007187cc) && (cVar5 = FUN_006b5020(iVar4, (char*)self + 8), cVar5 == '\0')) {
        ExceptionList = local_c;
        return false;
    }
    cVar5 = FUN_006b5090(iVar4, (char*)self + 0xc);
    if (cVar5 == '\0') {
        ExceptionList = local_c;
        return false;
    }
    cVar5 = FUN_005ec480(self, iVar4);
    if (cVar5 == '\0') {
        ExceptionList = local_c;
        return false;
    }
    if (0x10005 < DAT_007187cc) {
        cVar5 = FUN_006b5090(iVar4, &param_1);
        if (cVar5 == '\0') {
            ExceptionList = local_c;
            return false;
        }
        if (param_1 == 0) {
            puVar2 = *(undefined4**)((char*)self + 0x14);
            if (puVar2 != (undefined4*)0x0) {
                piVar1 = puVar2 + 1;
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    (**(code**)*puVar2)(1);
                }
                *(undefined4*)((char*)self + 0x14) = 0;
            }
        }
        else {
            iVar6 = (int)FUN_00533c78(0x1c);
            local_4 = 0;
            if (iVar6 == 0) {
                uVar7 = 0;
            }
            else {
                uVar7 = FUN_005edf90();
            }
            local_4 = 0xffffffff;
            FUN_0051ac30(uVar7);
            cVar5 = (*(code_ret**)(**(int**)((char*)self + 0x14) + 8))(iVar4);
            if (cVar5 == '\0') {
                ExceptionList = local_c;
                return false;
            }
        }
    }
    cVar5 = FUN_005ec520(self, iVar4);
    if (cVar5 != '\0') {
        puVar2 = (undefined4*)((char*)self + 0x1c);
        pvVar3 = (void*)*puVar2;
        if (pvVar3 != (void*)0x0) {
            FUN_005ea3c0();
            operator_delete(pvVar3);
        }
        *puVar2 = 0;
        cVar5 = FUN_005e8960(iVar4, puVar2);
        if (cVar5 != '\0') {
            if (*(undefined4**)((char*)self + 0x20) != (undefined4*)0x0) {
                (**(code**)**(undefined4**)((char*)self + 0x20))(1);
            }
            *(undefined4*)((char*)self + 0x20) = 0;
            cVar5 = FUN_005e8880(iVar4, (undefined4*)((char*)self + 0x20));
            if (cVar5 != '\0') {
                if (*(undefined4**)((char*)self + 0x24) != (undefined4*)0x0) {
                    (**(code**)**(undefined4**)((char*)self + 0x24))(1);
                }
                *(undefined4*)((char*)self + 0x24) = 0;
                cVar5 = FUN_005e8880(iVar4, (undefined4*)((char*)self + 0x24));
                if (cVar5 != '\0') {
                    cVar5 = (char)FUN_005ec830(self, iVar4);
                    ExceptionList = local_c;
                    return cVar5 != '\0';
                }
            }
        }
    }
    ExceptionList = local_c;
    return false;
}

// 0x5ecae0 — observed shape
undefined4 FUN_005ecae0(void* self, uint32_t param_1, int param_2)
{
    int* piVar1;
    uint32_t uVar2;
    int iVar3;
    void* local_c;
    undefined* puStack_8;
    undefined4 local_4;

    iVar3 = param_2;
    uVar2 = param_1;
    puStack_8 = (undefined*)0x006b9db8;
    local_c = ExceptionList;
    if ((*(uint32_t*)((char*)self + 0x48) <= param_1) ||
        (ExceptionList = &local_c, *(int*)(*(int*)((char*)self + 0x44) + param_1 * 4) == 0)) {
        ExceptionList = &local_c;
        *(int*)((char*)self + 0x38) = *(int*)((char*)self + 0x38) + 1;
    }
    param_1 = param_2;
    if (param_2 != 0) {
        *(int*)(param_2 + 0x68) = *(int*)(param_2 + 0x68) + 1;
    }
    local_4 = 0;
    if (*(uint32_t*)((char*)self + 0x48) <= uVar2) {
        FUN_005d3a60(*(int*)((char*)self + 0x54) + uVar2);
    }
    FUN_005d3090(uVar2, &param_1);
    local_4 = 0xffffffff;
    if (iVar3 != 0) {
        piVar1 = (int*)(iVar3 + 0x68);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            FUN_005bf480();
        }
    }
    FUN_005e90f0(*(undefined4*)((char*)self + 0x38));
    ExceptionList = local_c;
    return 1;
}

// 0x5ecb90 — observed shape
undefined4 FUN_005ecb90(void* self, int param_1, undefined4 param_2)
{
    int* piVar1;
    undefined4* puVar2;
    undefined1 uVar3;
    char cVar4;
    undefined4 uVar5;
    undefined4* puVar6;
    int iVar7;
    int* piVar8;
    uint32_t uVar9;
    int iVar10;
    void* pvVar11;
    uint32_t uStack_20;
    int iStack_18;
    int iStack_14;
    uint32_t uStack_10;
    void* pvStack_c;
    undefined* puStack_8;
    uint32_t iStack_4;

    iStack_4 = 0xffffffff;
    puStack_8 = (undefined*)0x006b9de0;
    pvStack_c = ExceptionList;
    if (*(int*)((char*)self + 0x10) == 0) {
        ExceptionList = &pvStack_c;
        *(undefined1*)(param_1 + 0x20) = 0;
        *(undefined1*)(param_1 + 0x21) = 0;
        *(undefined4*)(param_1 + 0x58) = 0;
        *(undefined4*)(param_1 + 100) = 0;
        *(undefined4*)(param_1 + 0x5c) = 0;
        *(undefined4*)(param_1 + 0x60) = 0;
    }
    else {
        ExceptionList = &pvStack_c;
        uVar3 = FUN_005ece70(self);
        *(undefined1*)(param_1 + 0x20) = uVar3;
        uVar3 = FUN_005ece80(self);
        *(undefined1*)(param_1 + 0x21) = uVar3;
        uVar5 = FUN_005dbe30();
        *(undefined4*)(param_1 + 0x58) = uVar5;
        uVar5 = FUN_005eceb0(self);
        *(undefined4*)(param_1 + 100) = uVar5;
        uVar5 = FUN_005ece90(self);
        *(undefined4*)(param_1 + 0x5c) = uVar5;
        uVar5 = FUN_005ecea0(self);
        *(undefined4*)(param_1 + 0x60) = uVar5;
    }
    if (*(int*)((char*)self + 0x20) == 0) {
        puVar2 = *(undefined4**)(param_1 + 0x2c);
        if (puVar2 != (undefined4*)0x0) {
            piVar8 = puVar2 + 1;
            *piVar8 = *piVar8 + -1;
            if (*piVar8 == 0) {
                (**(code**)*puVar2)(1);
            }
            *(undefined4*)(param_1 + 0x2c) = 0;
        }
    }
    else {
        puVar6 = (undefined4*)(**(code2**)(**(int**)((char*)self + 0x20) + 0xc))(*(undefined4*)(param_1 + 0x14), param_2);
        puVar2 = *(undefined4**)(param_1 + 0x2c);
        if (puVar2 != puVar6) {
            if (puVar2 != (undefined4*)0x0) {
                piVar8 = puVar2 + 1;
                *piVar8 = *piVar8 + -1;
                if (*piVar8 == 0) {
                    (**(code**)*puVar2)(1);
                }
            }
            *(undefined4**)(param_1 + 0x2c) = puVar6;
            if (puVar6 != (undefined4*)0x0) {
                puVar6[1] = puVar6[1] + 1;
            }
        }
    }
    if (*(int*)((char*)self + 0x24) == 0) {
        puVar2 = *(undefined4**)(param_1 + 0x30);
        if (puVar2 != (undefined4*)0x0) {
            piVar8 = puVar2 + 1;
            *piVar8 = *piVar8 + -1;
            if (*piVar8 == 0) {
                (**(code**)*puVar2)(1);
            }
            *(undefined4*)(param_1 + 0x30) = 0;
        }
    }
    else {
        puVar6 = (undefined4*)(**(code2**)(**(int**)((char*)self + 0x24) + 0x10))(*(undefined4*)(param_1 + 0x14), param_2);
        puVar2 = *(undefined4**)(param_1 + 0x30);
        if (puVar2 != puVar6) {
            if (puVar2 != (undefined4*)0x0) {
                piVar8 = puVar2 + 1;
                *piVar8 = *piVar8 + -1;
                if (*piVar8 == 0) {
                    (**(code**)*puVar2)(1);
                }
            }
            *(undefined4**)(param_1 + 0x30) = puVar6;
            if (puVar6 != (undefined4*)0x0) {
                puVar6[1] = puVar6[1] + 1;
            }
        }
    }
    pvVar11 = (void*)0x0;
    if ((*(int*)((char*)self + 0x1c) != 0) && (iVar7 = FUN_005dbe20(), iVar7 != 0)) {
        pvVar11 = (void*)FUN_005ca610();
        cVar4 = thunk_FUN_005eeb10(pvVar11);
        if (cVar4 == '\0') {
            if (pvVar11 != (void*)0x0) {
                FUN_005ca3d0();
                operator_delete(pvVar11);
            }
            ExceptionList = pvStack_c;
            return 0;
        }
    }
    *(void**)(param_1 + 0x28) = pvVar11;
    iVar7 = 0;
    uVar9 = *(uint32_t*)((char*)self + 0x34);
    iStack_4 = 0;
    param_1 = 0;
    uStack_20 = 0;
    uStack_10 = uVar9;
    if (uVar9 != 0) {
        do {
            iStack_14 = *(int*)(*(int*)((char*)self + 0x2c) + uStack_20 * 4);
            if (iStack_14 != 0) {
                piVar8 = (int*)FUN_005bf670(&iStack_18);
                iStack_4 = (iStack_4 & 0xff00) | 1;
                if (iVar7 != *piVar8) {
                    if (iVar7 != 0) {
                        piVar1 = (int*)(iVar7 + 0x68);
                        *piVar1 = *piVar1 + -1;
                        if (*piVar1 == 0) {
                            FUN_005bf480();
                        }
                    }
                    iVar7 = *piVar8;
                    if (iVar7 != 0) {
                        *(int*)(iVar7 + 0x68) = *(int*)(iVar7 + 0x68) + 1;
                    }
                }
                iStack_4 = (uint32_t)((iStack_4 << 8) & 0xffffff00);
                if ((iStack_18 != 0) &&
                    (iVar10 = *(int*)(iStack_18 + 0x68) + -1, *(int*)(iStack_18 + 0x68) = iVar10,
                     iVar10 == 0)) {
                    FUN_005bf480();
                }
                cVar4 = FUN_005ed740(iVar7, param_2);
                if (cVar4 == '\0') {
                    iStack_4 = 0xffffffff;
                    if (iVar7 != 0) {
                        piVar8 = (int*)(iVar7 + 0x68);
                        *piVar8 = *piVar8 + -1;
                        if (*piVar8 == 0) {
                            FUN_005bf480();
                        }
                    }
                    ExceptionList = pvStack_c;
                    return 0;
                }
                FUN_005ecae0(self, param_1, iVar7);
                param_1 = param_1 + 1;
                uVar9 = uStack_10;
            }
            uStack_20 = uStack_20 + 1;
        } while (uStack_20 < uVar9);
    }
    iStack_4 = 0xffffffff;
    if (iVar7 != 0) {
        piVar8 = (int*)(iVar7 + 0x68);
        *piVar8 = *piVar8 + -1;
        if (*piVar8 == 0) {
            FUN_005bf480();
        }
    }
    ExceptionList = pvStack_c;
    return 1;
}

// 0x5ece40 — observed shape
void FUN_005ece40(void* self)
{
    undefined4* in_ECX = (undefined4*)self;

    *in_ECX = 0;
    in_ECX[1] = 0;
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    *(undefined1*)(in_ECX + 4) = 0;
    *(undefined1*)((int)in_ECX + 0x11) = 0;
    in_ECX[5] = 0;
    in_ECX[8] = 0;
    return;
}

// 0x5ece80 — observed shape
undefined1 FUN_005ece80(void* self)
{
    return *(undefined1*)((char*)self + 0x11);
}

// 0x5ece90 — observed shape
undefined4 FUN_005ece90(void* self)
{
    return *(undefined4*)((char*)self + 0x18);
}

// 0x5ecea0 — observed shape
undefined4 FUN_005ecea0(void* self)
{
    return *(undefined4*)((char*)self + 0x1c);
}

// 0x5eceb0 — observed shape
undefined4 FUN_005eceb0(void* self)
{
    return *(undefined4*)((char*)self + 0x20);
}

// 0x5ecec0 — observed shape
undefined4 FUN_005ecec0(void* self, int param_1)
{
    int iVar1;
    char cVar2;

    iVar1 = param_1;
    cVar2 = FUN_006b5090(param_1);
    if (cVar2 != '\0') {
        cVar2 = FUN_006b5090(iVar1, (char*)self + 4);
        if (cVar2 != '\0') {
            cVar2 = FUN_006b5090(iVar1, (char*)self + 8);
            if (cVar2 != '\0') {
                cVar2 = FUN_006b5090(iVar1, (char*)self + 0xc);
                if (cVar2 != '\0') {
                    cVar2 = FUN_006b5090(iVar1, &param_1);
                    if (cVar2 != '\0') {
                        *(bool*)((char*)self + 0x10) = param_1 != 0;
                        cVar2 = FUN_006b5090(iVar1, &param_1);
                        if (cVar2 != '\0') {
                            *(bool*)((char*)self + 0x11) = param_1 != 0;
                            cVar2 = FUN_006b5090(iVar1, (char*)self + 0x14);
                            if (cVar2 != '\0') {
                                cVar2 = FUN_006b5090(iVar1, (char*)self + 0x18);
                                if (cVar2 != '\0') {
                                    cVar2 = FUN_006b5090(iVar1, &param_1);
                                    if (cVar2 != '\0') {
                                        *(int*)((char*)self + 0x1c) = param_1;
                                        cVar2 = FUN_006b5090(iVar1, &param_1);
                                        if (cVar2 != '\0') {
                                            *(int*)((char*)self + 0x20) = param_1;
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

// 0x5ecfc0 — observed shape
void FUN_005ecfc0(void* self)
{
    int iVar1;
    int* piVar2;
    undefined4* puVar3;
    int* in_ECX = (int*)self;
    void* pvStack_c;
    undefined1* puStack_8;
    undefined4 local_4;

    pvStack_c = ExceptionList;
    puStack_8 = (undefined1*)0x006b9e03;
    ExceptionList = &pvStack_c;
    iVar1 = in_ECX[2];
    local_4 = 0;
    *in_ECX = iVar1;
    while (iVar1 != 0) {
        piVar2 = (int*)*in_ECX;
        *in_ECX = *piVar2;
        puVar3 = (undefined4*)piVar2[2];
        if (puVar3 != (undefined4*)0x0) {
            (**(code**)*puVar3)(1);
        }
        iVar1 = *in_ECX;
    }
    FUN_005edba0();
    in_ECX[1] = (int)&PTR_FUN_006c9928;
    local_4 = 1;
    FUN_005edba0();
    in_ECX[1] = (int)&PTR_LAB_006c991c;
    ExceptionList = pvStack_c;
    return;
}

// 0x5ed050 — observed shape
int FUN_005ed050(void* self)
{
    int* piVar1;
    int* in_ECX = (int*)self;

    piVar1 = (int*)in_ECX[2];
    *in_ECX = (int)piVar1;
    if (piVar1 == (int*)0x0) {
        return 0;
    }
    *in_ECX = *piVar1;
    return piVar1[2];
}

// 0x5ed070 — observed shape
bool FUN_005ed070(void* self, undefined4 param_1)
{
    char cVar1;
    int* piVar2;
    undefined4* puVar3;
    int* in_ECX = (int*)self;
    uint32_t uVar4;
    uint32_t local_14;
    int local_10;
    void* local_c;
    undefined1* puStack_8;
    undefined4 local_4;

    local_4 = 0xffffffff;
    puStack_8 = (undefined1*)0x006b9e1b;
    local_c = ExceptionList;
    ExceptionList = &local_c;
    cVar1 = FUN_006b5090(param_1, &local_14);
    if (cVar1 == '\0') {
        ExceptionList = local_c;
        return false;
    }
    uVar4 = 0;
    if (local_14 != 0) {
        do {
            local_10 = (int)FUN_00533c78(0xdc);
            local_4 = 0;
            if (local_10 == 0) {
                piVar2 = (int*)0x0;
            }
            else {
                piVar2 = (int*)FUN_006b3c00();
            }
            local_4 = 0xffffffff;
            (**(code**)(*piVar2 + 0x18))(param_1);
            puVar3 = (undefined4*)(**(code_voidp**)(*(int*)((char*)self + 4) + 4))();
            puVar3[2] = (undefined4)piVar2;
            *puVar3 = 0;
            puVar3[1] = *(undefined4*)((char*)self + 0xc);
            if (*(undefined4**)((char*)self + 0xc) == (undefined4*)0x0) {
                *(undefined4**)((char*)self + 8) = puVar3;
            }
            else {
                **(undefined4**)((char*)self + 0xc) = puVar3;
            }
            *(undefined4**)((char*)self + 0xc) = puVar3;
            uVar4 = uVar4 + 1;
            *(int*)((char*)self + 0x10) = *(int*)((char*)self + 0x10) + 1;
        } while (uVar4 < local_14);
    }
    ExceptionList = local_c;
    return local_14 == 0;
}
