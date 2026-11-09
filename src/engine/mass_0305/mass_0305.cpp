// Mass reconstruction batch mass_0305 — unverified decompiler-derived candidate.
// Target: Sid Meier's Pirates! (2004), PE32 i386.
// No compiler/test run. Correlated externally via observed pseudocode shapes.
#include <cstdint>
#include <cstddef>
#include <windows.h>

typedef uint8_t  byte;
typedef uint32_t uint;
typedef int32_t  code(...);   // observed inline vtable dispatch type

// ---- referenced helpers (observed call targets) ----
extern int32_t  FUN_0064e847(uint32_t handle, int32_t a, int32_t b);
extern int32_t  FUN_006496c1(uint32_t handle, int32_t param_3);
extern int32_t  FUN_00649774(uint32_t handle, int32_t param_3);
extern int32_t  FUN_00649827(uint32_t handle, int32_t param_3);
extern int32_t  FUN_00648e04(uint32_t handle, int32_t param_3);
extern int32_t  FUN_00648d5c(uint32_t handle, int32_t param_3);
extern int32_t  FUN_00648e58(uint32_t handle, void* param_3, int32_t param_4);
extern int32_t  FUN_00648f01(uint32_t handle, void* param_3, int32_t param_4);
extern int32_t  FUN_00648faa(uint32_t handle, void* param_3, int32_t param_4);
extern int32_t  FUN_00648db0(uint32_t handle, float param_3);
extern int32_t  FUN_0063f926(int32_t param_3, int32_t index, int32_t table);
extern int32_t  FUN_0063f86e(int32_t param_3, int32_t index, int32_t table);
extern int32_t  FUN_006431b5(void* desc);
extern int32_t  FUN_00533c78(uint32_t size);
extern int32_t  FUN_004127b0(void* dst, int32_t stride, int32_t count, void* ctor);
extern int32_t  FUN_0063e58b();
extern int32_t  FUN_006411ea(uint32_t param_1);
extern int32_t  FUN_0064e079(int32_t rec, int32_t* stream, uint32_t* pos);
extern int32_t  FUN_0064e266(int32_t rec, int32_t* stream, uint32_t* pos);
extern int32_t  FUN_006480e4(void* a, void* b, uint32_t index);
extern int32_t  FUN_0063ec91(uint32_t base, void* a, void* b);
extern int32_t  FUN_006440fa(void* rec, void* a, void* b, void* c);
extern int32_t  FUN_0063e68a(int32_t* stream, uint32_t* pos);
extern int32_t  FUN_0064efd7(uint32_t index, void* param_4, int32_t* stream, uint32_t* pos);
extern int32_t  FUN_00644699(uint32_t index, void* param_4, int32_t* stream, uint32_t* pos);
extern int32_t  FUN_00647e66(uint32_t index, void* param_4, int32_t* stream, uint32_t* pos);
extern int32_t  FUN_0064f29e(uint32_t index, void* param_4, int32_t* stream, uint32_t* pos);
extern int32_t  FUN_0062a1a7(int32_t self, int32_t rec);
extern int32_t  FUN_0063e391();
extern int32_t  FUN_0063d772(int32_t rec);
extern int32_t  FUN_0063e327();
extern int32_t  FUN_00647b28();
extern int32_t  FUN_00646bc5();
extern int32_t  FUN_00647cf7();
extern void     FUN_0064dc3f(void* self);
extern int32_t  FUN_00644bfc(int32_t a, int32_t b, uint32_t c, uint32_t d, uint32_t e,
                             int32_t f);
extern int32_t  FUN_0063ef70(int32_t* list, void* node, int32_t* owner);
extern void     operator_delete__(void* p);
extern void     LAB_0063e3eb(void);

// ---- referenced globals ----
extern int32_t DAT_006eac9c;
extern int32_t DAT_006eacac;

// ---- observed common layouts ----
// container: +0x18 record array (stride 0x18), +0x3c mode, +0xb0 row index array,
//            +0xc4 log/status struct, +0x20 / +0x38 strides.
// descriptor: [0]=index, [1]=object*, [2]=-1 sentinel, [5]=row, [7]=byte offset.
// object:    [0]=type id, [1]=variant, [4]=flag.

// 0x650432 — observed shape
int32_t FUN_650432(int32_t param_1, uint32_t param_2, int32_t param_3)
{
    uint32_t* puVar5;
    int32_t   iVar2;
    int32_t   iVar3;
    int32_t   iVar4;

    if ((int32_t)param_2 < 0) {
        puVar5 = (uint32_t*)~param_2;
    }
    else {
        int32_t* piVar1 = (int32_t*)(uintptr_t)(param_1 + 0xc4);
        *(int32_t*)(uintptr_t)(*piVar1 + 4)    = 4;
        *(int32_t*)(uintptr_t)(*piVar1)        = 5;
        *(int32_t*)(uintptr_t)(*piVar1 + 0x10) = 0;
        puVar5 = (uint32_t*)FUN_0064e847(param_2, 1, 1);
        if (puVar5 == (uint32_t*)0) {
            return (int32_t)0x8876086c;
        }
    }
    if ((((((int32_t*)puVar5[1])[4] != 0) && (puVar5[2] == 0xffffffffu)) ||
         (iVar3 = *(int32_t*)puVar5[1], iVar3 < 5)) ||
        (9 < iVar3)) {
        return (int32_t)0x8876086c;
    }
    if (*(int32_t*)(uintptr_t)(param_1 + 0x3c) == 3) {
        iVar3 = FUN_006496c1(~(uint32_t)puVar5, param_3);
        return iVar3;
    }
    iVar3 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(param_1 + 0xb0) + puVar5[5] * 4) + 0x40);
    iVar2 = *(int32_t*)*puVar5;
    if (iVar3 == 0) {
        iVar4 = iVar2;
    }
    else {
        iVar4 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar3 + 8) + iVar2 * 4);
    }
    if (param_3 == *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(param_1 + 0x18) + 4 + iVar4 * 0x18)) {
        return 0;
    }
    iVar3 = FUN_0063f926(param_3, iVar2, iVar3);
    if (iVar3 < 0) {
        return iVar3;
    }
    iVar3 = FUN_006431b5(puVar5);
    return iVar3;
}

// 0x650506 — observed shape
uint32_t FUN_650506(int32_t param_1, uint32_t param_2, int32_t* param_3)
{
    int32_t*  piVar1;
    int32_t   iVar2;
    uint32_t* puVar3;
    int32_t   iVar4;
    uint32_t  uVar5;

    uVar5 = 0;
    if (param_3 == (int32_t*)0) {
        uVar5 = 0x8876086c;
    }
    else {
        puVar3 = (uint32_t*)FUN_0064e847(param_2, 1, 0);
        if (((puVar3 == (uint32_t*)0) ||
             (((piVar1 = (int32_t*)puVar3[1], piVar1[4] != 0 && (puVar3[2] == 0xffffffffu)) ||
              (iVar2 = *piVar1, piVar1[1] != 4)))) ||
            ((((iVar2 != 5 && (iVar2 != 6)) && (iVar2 != 7)) && ((iVar2 != 8 && (iVar2 != 9)))))) {
            uVar5 = 0x8876086c;
        }
        else {
            iVar2 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(param_1 + 0xb0) + puVar3[5] * 4) + 0x40);
            iVar4 = *(int32_t*)*puVar3;
            if (iVar2 != 0) {
                iVar4 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar2 + 8) + iVar4 * 4);
            }
            piVar1 = *(int32_t**)(uintptr_t)(*(int32_t*)(uintptr_t)(param_1 + 0x18) + 4 + iVar4 * 0x18);
            *param_3 = (int32_t)piVar1;
            if (piVar1 != (int32_t*)0) {
                (**(code**)(*piVar1 + 4))(piVar1);
            }
        }
    }
    return uVar5;
}

// 0x6505a8 — observed shape
int32_t FUN_6505a8(int32_t param_1, uint32_t param_2, int32_t param_3)
{
    int32_t*  piVar1;
    int32_t   iVar2;
    uint32_t* puVar3;
    int32_t   iVar4;
    int32_t   iVar5;
    int32_t   iVar6;

    piVar1 = (int32_t*)(uintptr_t)(param_1 + 0xc4);
    *(int32_t*)(uintptr_t)(*piVar1 + 4)    = 4;
    *(int32_t*)(uintptr_t)(*piVar1)        = 0xf;
    *(int32_t*)(uintptr_t)(*piVar1 + 0x10) = 0;
    puVar3 = (uint32_t*)FUN_0064e847(param_2, 1, 1);
    if (((puVar3 == (uint32_t*)0) ||
         (((piVar1 = (int32_t*)puVar3[1], piVar1[4] != 0 && (puVar3[2] == 0xffffffffu)) ||
           (piVar1[1] != 4)))) ||
        (*piVar1 != 0xf)) {
        iVar4 = (int32_t)0x8876086c;
    }
    else if (*(int32_t*)(uintptr_t)(param_1 + 0x3c) == 3) {
        iVar4 = FUN_00649774(~(uint32_t)puVar3, param_3);
    }
    else {
        iVar4 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(param_1 + 0xb0) + puVar3[5] * 4);
        iVar2 = *(int32_t*)(uintptr_t)(iVar4 + 0x40);
        if (iVar2 == 0) {
            iVar6 = puVar3[7];
            iVar5 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar4 + 0x30) + iVar6 + *(int32_t*)(uintptr_t)(param_1 + 0x20));
        }
        else {
            iVar5 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(param_1 + 0xb0) + puVar3[5] * 4);
            iVar6 = puVar3[7];
            iVar5 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar5 + 0x40) + 8) +
                                *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar5 + 0x30) + iVar6 +
                                            *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(param_1 + 0x38) + 0x10)) * 4);
        }
        if (param_3 == *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(param_1 + 0x18) + 4 + iVar5 * 0x18)) {
            if (iVar2 == 0) {
                iVar4 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar4 + 0x30) + iVar6 + *(int32_t*)(uintptr_t)(param_1 + 0x20));
            }
            else {
                iVar4 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(param_1 + 0xb0) + puVar3[5] * 4);
                iVar4 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar4 + 0x40) + 8) +
                                    *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar4 + 0x30) + iVar6 +
                                                *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(param_1 + 0x38) + 0x10)) * 4);
            }
            if ((*(byte*)(*(int32_t*)(uintptr_t)(param_1 + 0x18) + 0x14 + iVar4 * 0x18) & 2) != 0) {
                return 0;
            }
        }
        iVar4 = FUN_0063f86e(param_3, *(uint32_t*)*puVar3, iVar2);
        if (-1 < iVar4) {
            iVar4 = FUN_006431b5(puVar3);
        }
    }
    return iVar4;
}

// 0x6506fd — observed shape
uint32_t FUN_6506fd(int32_t param_1, uint32_t param_2, int32_t* param_3)
{
    int32_t*  piVar1;
    int32_t   iVar2;
    int32_t   iVar3;
    uint32_t  local_8;

    local_8 = 0;
    if (param_3 == (int32_t*)0) {
        local_8 = 0x8876086c;
    }
    else {
        iVar3 = FUN_0064e847(param_2, 1, 0);
        if (((iVar3 == 0) ||
             (((piVar1 = *(int32_t**)(uintptr_t)(iVar3 + 4), piVar1[4] != 0 && (*(int32_t*)(uintptr_t)(iVar3 + 8) == -1)) ||
              (piVar1[1] != 4)))) || (*piVar1 != 0xf)) {
            local_8 = 0x8876086c;
        }
        else {
            iVar2 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(param_1 + 0xb0) + *(int32_t*)(uintptr_t)(iVar3 + 0x14) * 4);
            if (*(int32_t*)(uintptr_t)(iVar2 + 0x40) == 0) {
                iVar3 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar2 + 0x30) + *(int32_t*)(uintptr_t)(iVar3 + 0x1c) +
                                    *(int32_t*)(uintptr_t)(param_1 + 0x20));
            }
            else {
                iVar2 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(param_1 + 0xb0) + *(int32_t*)(uintptr_t)(iVar3 + 0x14) * 4);
                iVar3 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar2 + 0x40) + 8) +
                                    *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar2 + 0x30) + *(int32_t*)(uintptr_t)(iVar3 + 0x1c) +
                                                *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(param_1 + 0x38) + 0x10)) * 4);
            }
            piVar1 = *(int32_t**)(uintptr_t)(*(int32_t*)(uintptr_t)(param_1 + 0x18) + 4 + iVar3 * 0x18);
            *param_3 = (int32_t)piVar1;
            if (piVar1 != (int32_t*)0) {
                (**(code**)(*piVar1 + 4))(piVar1);
            }
        }
    }
    return local_8;
}

// 0x6507b8 — observed shape
int32_t FUN_6507b8(int32_t param_1, uint32_t param_2, int32_t param_3)
{
    int32_t*  piVar1;
    int32_t   iVar2;
    uint32_t* puVar3;
    int32_t   iVar4;
    int32_t   iVar5;
    int32_t   iVar6;

    piVar1 = (int32_t*)(uintptr_t)(param_1 + 0xc4);
    *(int32_t*)(uintptr_t)(*piVar1 + 4)    = 4;
    *(int32_t*)(uintptr_t)(*piVar1)        = 0x10;
    *(int32_t*)(uintptr_t)(*piVar1 + 0x10) = 0;
    puVar3 = (uint32_t*)FUN_0064e847(param_2, 1, 1);
    if (((puVar3 == (uint32_t*)0) ||
         (((piVar1 = (int32_t*)puVar3[1], piVar1[4] != 0 && (puVar3[2] == 0xffffffffu)) ||
           (piVar1[1] != 4)))) ||
        (*piVar1 != 0x10)) {
        iVar4 = (int32_t)0x8876086c;
    }
    else if (*(int32_t*)(uintptr_t)(param_1 + 0x3c) == 3) {
        iVar4 = FUN_00649827(~(uint32_t)puVar3, param_3);
    }
    else {
        iVar4 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(param_1 + 0xb0) + puVar3[5] * 4);
        iVar2 = *(int32_t*)(uintptr_t)(iVar4 + 0x40);
        if (iVar2 == 0) {
            iVar6 = puVar3[7];
            iVar5 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar4 + 0x30) + iVar6 + *(int32_t*)(uintptr_t)(param_1 + 0x20));
        }
        else {
            iVar5 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(param_1 + 0xb0) + puVar3[5] * 4);
            iVar6 = puVar3[7];
            iVar5 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar5 + 0x40) + 8) +
                                *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar5 + 0x30) + iVar6 +
                                            *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(param_1 + 0x38) + 0x10)) * 4);
        }
        if (param_3 == *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(param_1 + 0x18) + 4 + iVar5 * 0x18)) {
            if (iVar2 == 0) {
                iVar4 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar4 + 0x30) + iVar6 + *(int32_t*)(uintptr_t)(param_1 + 0x20));
            }
            else {
                iVar4 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(param_1 + 0xb0) + puVar3[5] * 4);
                iVar4 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar4 + 0x40) + 8) +
                                    *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar4 + 0x30) + iVar6 +
                                                *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(param_1 + 0x38) + 0x10)) * 4);
            }
            if ((*(byte*)(*(int32_t*)(uintptr_t)(param_1 + 0x18) + 0x14 + iVar4 * 0x18) & 2) != 0) {
                return 0;
            }
        }
        iVar4 = FUN_0063f86e(param_3, *(uint32_t*)*puVar3, iVar2);
        if (-1 < iVar4) {
            iVar4 = FUN_006431b5(puVar3);
        }
    }
    return iVar4;
}

// 0x65090d — observed shape
uint32_t FUN_65090d(int32_t param_1, uint32_t param_2, int32_t* param_3)
{
    int32_t* piVar1;
    int32_t  iVar2;
    int32_t  iVar3;
    uint32_t local_8;

    local_8 = 0;
    if (param_3 == (int32_t*)0) {
        local_8 = 0x8876086c;
    }
    else {
        iVar3 = FUN_0064e847(param_2, 1, 0);
        if (((iVar3 == 0) ||
             (((piVar1 = *(int32_t**)(uintptr_t)(iVar3 + 4), piVar1[4] != 0 && (*(int32_t*)(uintptr_t)(iVar3 + 8) == -1)) ||
              (piVar1[1] != 4)))) || (*piVar1 != 0x10)) {
            local_8 = 0x8876086c;
        }
        else {
            iVar2 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(param_1 + 0xb0) + *(int32_t*)(uintptr_t)(iVar3 + 0x14) * 4);
            if (*(int32_t*)(uintptr_t)(iVar2 + 0x40) == 0) {
                iVar3 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar2 + 0x30) + *(int32_t*)(uintptr_t)(iVar3 + 0x1c) +
                                    *(int32_t*)(uintptr_t)(param_1 + 0x20));
            }
            else {
                iVar2 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(param_1 + 0xb0) + *(int32_t*)(uintptr_t)(iVar3 + 0x14) * 4);
                iVar3 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar2 + 0x40) + 8) +
                                    *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar2 + 0x30) + *(int32_t*)(uintptr_t)(iVar3 + 0x1c) +
                                                *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(param_1 + 0x38) + 0x10)) * 4);
            }
            piVar1 = *(int32_t**)(uintptr_t)(*(int32_t*)(uintptr_t)(param_1 + 0x18) + 4 + iVar3 * 0x18);
            *param_3 = (int32_t)piVar1;
            if (piVar1 != (int32_t*)0) {
                (**(code**)(*piVar1 + 4))(piVar1);
            }
        }
    }
    return local_8;
}

// 0x6509c8 — observed shape
// Sets a scalar or an RGBA float tuple on the descriptor payload.
uint32_t FUN_6509c8(int32_t param_1, uint32_t param_2, uint32_t param_3)
{
    int32_t*  piVar1;
    uint32_t  uVar2;
    int32_t   iVar3;
    uint32_t  uVar4;
    uint32_t  uVar5;
    int32_t*  piVar6;
    float     local_18[4];
    uint32_t  local_8;

    local_8 = 0;
    if ((int32_t)param_2 < 0) {
        piVar6 = (int32_t*)~param_2;
    }
    else {
        piVar6 = (int32_t*)(uintptr_t)(param_1 + 0xc4);
        *(uint32_t*)(uintptr_t)(*piVar6 + 4)    = 0;
        *(uint32_t*)(uintptr_t)(*piVar6)        = 2;
        *(uint32_t*)(uintptr_t)(*piVar6 + 0x10) = 0;
        *(uint32_t*)(uintptr_t)(*piVar6 + 0x14) = 1;
        *(uint32_t*)(uintptr_t)(*piVar6 + 0x18) = 1;
        piVar6 = (int32_t*)FUN_0064e847(param_2, 1, 1);
        if (piVar6 == (int32_t*)0) {
            return 0x8876086c;
        }
    }
    piVar1 = (int32_t*)piVar6[1];
    if ((piVar1[4] != 0) && (piVar6[2] == -1)) {
        return 0x8876086c;
    }
    if (*(int32_t*)(uintptr_t)(param_1 + 0x3c) == 3) {
        uVar4 = FUN_00648e04(~(uint32_t)piVar6, (int32_t)param_3);
    }
    else {
        if (piVar1[1] < 0) {
            return 0x8876086c;
        }
        if (3 < piVar1[1]) {
            return 0x8876086c;
        }
        uVar2 = (uint32_t)piVar1[5];
        iVar3 = *piVar1;
        if (((iVar3 == 3) && (piVar1[6] == 1)) && ((uVar2 == 3 || (uVar2 == 4)))) {
            local_18[0] = (float)(param_3 >> 0x10 & 0xff) * 0.003921569f;
            local_18[1] = (float)(param_3 >> 8 & 0xff)  * 0.003921569f;
            uVar5 = 0;
            local_18[2] = (float)(param_3 & 0xff)       * 0.003921569f;
            local_18[3] = (float)(param_3 >> 0x18)      * 0.003921569f;
            if (uVar2 != 0) {
                do {
                    *(float*)(*piVar6 + uVar5 * 4) = local_18[uVar5];
                    uVar5 = uVar5 + 1;
                } while (uVar5 < uVar2);
            }
        }
        else {
            if (uVar2 != 1) {
                return 0x8876086c;
            }
            if (piVar1[6] != 1) {
                return 0x8876086c;
            }
            if (iVar3 == 1) {
                if ((*(uint32_t*)*piVar6 == 0) == (param_3 == 0)) {
                    return local_8;
                }
                *(uint32_t*)*piVar6 = (uint32_t)(param_3 != 0);
            }
            else if (iVar3 == 2) {
                if (*(uint32_t*)*piVar6 == param_3) {
                    return local_8;
                }
                *(uint32_t*)*piVar6 = param_3;
            }
            else {
                if (iVar3 != 3) {
                    return 0x8876086c;
                }
                if (*(float*)*piVar6 == (float)(int32_t)param_3) {
                    return local_8;
                }
                *(float*)*piVar6 = (float)(int32_t)param_3;
            }
        }
        uVar4 = (uint32_t)FUN_006431b5(piVar6);
    }
    return uVar4;
}

// 0x650b55 — observed shape
// Reads a scalar or RGBA tuple as a packed 0xAARRGGBB color word.
// The `ftol()` spills in the listing are the x87 truncate-and-clamp idiom:
// value >= 1.0 clamps to 0xff, otherwise the 0..1 float is truncated.
// NEEDS_MANUAL: x87 long-double register spills (extraout_ST0/ST1) elided by provider.
uint32_t FUN_650b55(uint32_t param_1, uint32_t param_2, uint32_t* param_3)
{
    int32_t*  piVar1;
    int32_t   iVar2;
    uint32_t* puVar3;
    int32_t   iVar4;
    float*    pfVar5;
    uint32_t  uVar6;
    float*    pfVar7;
    uint32_t  uVar8;
    long double fVar9;
    long double fVar10;
    long double fVar11;
    float     local_18[5];
    uint32_t  out;

    (void)param_1;
    local_18[4] = 0.0f;
    if (param_3 == (uint32_t*)0) {
        return 0x8876086c;
    }
    puVar3 = (uint32_t*)FUN_0064e847(param_2, 1, 0);
    if (((puVar3 == (uint32_t*)0) ||
         (((piVar1 = (int32_t*)puVar3[1], piVar1[4] != 0 && (puVar3[2] == 0xffffffffu)) ||
           (piVar1[1] < 0)))) ||
        (3 < piVar1[1])) {
        return 0x8876086c;
    }
    iVar4 = piVar1[5];
    iVar2 = *piVar1;
    if (((iVar2 != 3) || (piVar1[6] != 1)) || ((iVar4 != 3 && (iVar4 != 4)))) {
        if (iVar4 != 1) {
            return 0x8876086c;
        }
        if (piVar1[6] != 1) {
            return 0x8876086c;
        }
        if (iVar2 == 1) {
            *param_3 = (uint32_t)(*(int32_t*)*puVar3 != 0);
            return (uint32_t)local_18[4];
        }
        if (iVar2 == 2) {
            uVar8 = *(uint32_t*)*puVar3;
        }
        else {
            if (iVar2 != 3) {
                return 0x8876086c;
            }
            uVar8 = (uint32_t)*(float*)*puVar3; // observed ftol()
        }
        *param_3 = uVar8;
        return (uint32_t)local_18[4];
    }
    local_18[0] = 0.0f;
    local_18[1] = 0.0f;
    local_18[2] = 0.0f;
    local_18[3] = 0.0f;
    fVar9  = (long double)1.0;
    fVar10 = (long double)0.0;
    if (iVar4 != 0) {
        pfVar5 = (float*)*puVar3;
        pfVar7 = local_18;
        for (; iVar4 != 0; iVar4 = iVar4 + -1) {
            *pfVar7 = *pfVar5;
            pfVar5 = pfVar5 + 1;
            pfVar7 = pfVar7 + 1;
        }
        if (fVar9 <= (long double)local_18[0]) {
            param_2 = 0xff;
            goto LAB_650c48;
        }
        fVar11 = (long double)local_18[0];
        if (fVar11 < fVar10 == (fVar11 == fVar10)) { // observed ordered-compare idiom
            param_2 = (uint32_t)fVar11;               // observed ftol()
            fVar10 = (long double)(uint32_t)param_2;
            fVar9  = (long double)param_2;            // extraout_ST1
            goto LAB_650c48;
        }
    }
    param_2 = 0;
LAB_650c48:
    if ((long double)local_18[1] < fVar9) {
        fVar11 = (long double)local_18[1];
        if (fVar11 < fVar10 == (fVar11 == fVar10)) {
            uVar8  = (uint32_t)fVar11; // observed ftol()
            fVar10 = (long double)(uint32_t)uVar8;
            fVar9  = (long double)uVar8; // extraout_ST1_00
        }
        else {
            uVar8 = 0;
        }
    }
    else {
        uVar8 = 0xff;
    }
    if ((long double)local_18[2] < fVar9) {
        fVar11 = (long double)local_18[2];
        if (fVar11 < fVar10 == (fVar11 == fVar10)) {
            uVar6 = (uint32_t)fVar11; // observed ftol()
            fVar9 = (long double)uVar6;
        }
        else {
            uVar6 = 0;
        }
    }
    else {
        uVar6 = 0xff;
    }
    if ((long double)local_18[3] < fVar9) {
        if (local_18[3] < 0.0f == (local_18[3] == 0.0f)) {
            iVar4 = (int32_t)local_18[3]; // observed ftol()
        }
        else {
            iVar4 = 0;
        }
    }
    else {
        iVar4 = 0xff;
    }
    out = ((iVar4 << 8 | (int32_t)param_2) << 8 | (int32_t)uVar8) << 8 | (int32_t)uVar6;
    *param_3 = out;
    return (uint32_t)local_18[4];
}

// 0x650d47 — observed shape
uint32_t FUN_650d47(int32_t param_1, uint32_t param_2, int32_t param_3)
{
    int32_t*  piVar1;
    int32_t   iVar2;
    uint32_t  uVar3;
    uint32_t* puVar4;
    uint32_t  uVar5;

    if ((int32_t)param_2 < 0) {
        puVar4 = (uint32_t*)~param_2;
    }
    else {
        piVar1 = (int32_t*)(uintptr_t)(param_1 + 0xc4);
        *(uint32_t*)(uintptr_t)(*piVar1 + 4)    = 0;
        *(uint32_t*)(uintptr_t)(*piVar1)        = 1;
        *(uint32_t*)(uintptr_t)(*piVar1 + 0x10) = 0;
        *(uint32_t*)(uintptr_t)(*piVar1 + 0x14) = 1;
        *(uint32_t*)(uintptr_t)(*piVar1 + 0x18) = 1;
        puVar4 = (uint32_t*)FUN_0064e847(param_2, 1, 1);
        if (puVar4 == (uint32_t*)0) {
            return 0x8876086c;
        }
    }
    piVar1 = (int32_t*)puVar4[1];
    if ((piVar1[4] == 0) || (puVar4[2] != 0xffffffffu)) {
        if (*(int32_t*)(uintptr_t)(param_1 + 0x3c) == 3) {
            uVar3 = (uint32_t)FUN_00648d5c(~(uint32_t)puVar4, param_3);
            return uVar3;
        }
        uVar5 = (uint32_t)(param_3 != 0);
        if ((((-1 < piVar1[1]) && (piVar1[1] < 4)) && (piVar1[5] == 1)) && (piVar1[6] == 1)) {
            iVar2 = *piVar1;
            if (iVar2 == 1) {
                if ((*(uint32_t*)*puVar4 == 0) == (uVar5 == 0)) {
                    return 0;
                }
                *(uint32_t*)*puVar4 = uVar5;
            }
            else if (iVar2 == 2) {
                if (*(uint32_t*)*puVar4 == uVar5) {
                    return 0;
                }
                *(uint32_t*)*puVar4 = uVar5;
            }
            else {
                if (iVar2 != 3) {
                    return 0x8876086c;
                }
                if (*(float*)*puVar4 == (float)(int32_t)uVar5) {
                    return 0;
                }
                *(float*)*puVar4 = (float)(int32_t)uVar5;
            }
            uVar3 = (uint32_t)FUN_006431b5(puVar4);
            return uVar3;
        }
    }
    return 0x8876086c;
}

// 0x650e41 — observed shape
uint32_t FUN_650e41(uint32_t param_1, uint32_t param_2, uint32_t* param_3)
{
    int32_t*  piVar1;
    int32_t   iVar2;
    uint32_t* puVar3;

    (void)param_1;
    if ((((param_3 != (uint32_t*)0) &&
          (puVar3 = (uint32_t*)FUN_0064e847(param_2, 1, 0), puVar3 != (uint32_t*)0)) &&
         ((piVar1 = (int32_t*)puVar3[1], piVar1[4] == 0 || (puVar3[2] != 0xffffffffu)))) &&
        ((((-1 < piVar1[1] && (piVar1[1] < 4)) && (piVar1[5] == 1)) && (piVar1[6] == 1)))) {
        iVar2 = *piVar1;
        if ((iVar2 == 1) || (iVar2 == 2)) {
            *param_3 = (uint32_t)(*(int32_t*)*puVar3 != 0);
            return 0;
        }
        if (iVar2 == 3) {
            *param_3 = (uint32_t)(*(float*)*puVar3 != 0.0f);
            return 0;
        }
    }
    return 0x8876086c;
}

// 0x650ed3 — observed shape
// Bulk upload of a float/bool/int plane into a pitch-0x40 subresource, flattened row-major.
uint32_t FUN_650ed3(int32_t param_1, uint32_t param_2, float* param_3, int32_t param_4)
{
    float    fVar1;
    int32_t* piVar2;
    int32_t  iVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    float*   pfVar7;
    float*   pfVar8;
    int32_t  iVar9;
    uint32_t uVar10;
    uint32_t local_14;
    int32_t* local_10;
    uint32_t local_8;

    if ((int32_t)param_2 < 0) {
        local_10 = (int32_t*)~param_2;
    }
    else {
        piVar2 = (int32_t*)(uintptr_t)(param_1 + 0xc4);
        *(uint32_t*)(uintptr_t)(*piVar2 + 4)    = 0;
        *(uint32_t*)(uintptr_t)(*piVar2)        = 1;
        *(int32_t*)(uintptr_t)(*piVar2 + 0x10)  = param_4;
        *(uint32_t*)(uintptr_t)(*piVar2 + 0x14) = 1;
        *(uint32_t*)(uintptr_t)(*piVar2 + 0x18) = 1;
        local_10 = (int32_t*)FUN_0064e847(param_2, 1, 1);
        if (local_10 == (int32_t*)0) {
            return 0x8876086c;
        }
    }
    if (*(int32_t*)(uintptr_t)(param_1 + 0x3c) == 3) {
        uVar5 = FUN_00648e58(~(uint32_t)local_10, param_3, param_4);
        return uVar5;
    }
    piVar2 = (int32_t*)local_10[1];
    iVar3 = piVar2[1];
    if (iVar3 < 0) {
        return 0x8876086c;
    }
    if (1 < iVar3) {
        if (iVar3 == 2) {
            param_2 = (uint32_t)piVar2[4];
            uVar4 = (uint32_t)piVar2[5];
            uVar10 = (uint32_t)piVar2[6];
            if ((param_2 == 0) || (local_10[2] != -1)) {
                param_2 = 1;
            }
            iVar3 = *piVar2;
            iVar9 = *local_10;
            if (iVar3 == 1) {
                local_14 = 0;
                if (param_2 != 0) {
                    pfVar8 = param_3;
                    do {
                        if (param_4 == 0) break;
                        param_3 = (float*)0;
                        if (uVar10 != 0) {
                            do {
                                local_8 = 0;
                                if (uVar4 != 0) {
                                    pfVar7 = pfVar8 + (int32_t)param_3;
                                    do {
                                        if (param_4 == 0) break;
                                        param_4 = param_4 + -1;
                                        uVar6 = local_8 + 1;
                                        *(float*)(iVar9 + (local_8 + (int32_t)param_3 * 4) * 4) = *pfVar7;
                                        pfVar7 = pfVar7 + uVar10;
                                        local_8 = uVar6;
                                    } while (uVar6 < uVar4);
                                }
                                param_3 = (float*)((int32_t)param_3 + 1);
                            } while (param_3 < uVar10);
                        }
                        iVar9 = iVar9 + 0x40;
                        local_14 = local_14 + 1;
                        pfVar8 = pfVar8 + uVar10 * uVar4;
                    } while (local_14 < param_2);
                }
            }
            else if (iVar3 == 2) {
                local_14 = 0;
                if (param_2 != 0) {
                    pfVar8 = param_3;
                    do {
                        if (param_4 == 0) break;
                        param_3 = (float*)0;
                        if (uVar10 != 0) {
                            do {
                                local_8 = 0;
                                if (uVar4 != 0) {
                                    pfVar7 = pfVar8 + (int32_t)param_3;
                                    do {
                                        if (param_4 == 0) break;
                                        param_4 = param_4 + -1;
                                        uVar6 = local_8 + 1;
                                        *(float*)(iVar9 + (local_8 + (int32_t)param_3 * 4) * 4) = *pfVar7;
                                        pfVar7 = pfVar7 + uVar10;
                                        local_8 = uVar6;
                                    } while (uVar6 < uVar4);
                                }
                                param_3 = (float*)((int32_t)param_3 + 1);
                            } while (param_3 < uVar10);
                        }
                        iVar9 = iVar9 + 0x40;
                        local_14 = local_14 + 1;
                        pfVar8 = pfVar8 + uVar10 * uVar4;
                    } while (local_14 < param_2);
                }
            }
            else {
                if (iVar3 != 3) {
                    return 0x80004005;
                }
                local_8 = 0;
                if (param_2 != 0) {
                    pfVar8 = param_3;
                    do {
                        if (param_4 == 0) break;
                        param_3 = (float*)0;
                        if (uVar10 != 0) {
                            do {
                                uVar6 = 0;
                                if (uVar4 != 0) {
                                    pfVar7 = pfVar8 + (int32_t)param_3;
                                    do {
                                        if (param_4 == 0) break;
                                        param_4 = param_4 + -1;
                                        *(float*)(iVar9 + (uVar6 + (int32_t)param_3 * 4) * 4) =
                                            (float)(int32_t)*pfVar7;
                                        pfVar7 = pfVar7 + uVar10;
                                        uVar6 = uVar6 + 1;
                                    } while (uVar6 < uVar4);
                                }
                                param_3 = (float*)((int32_t)param_3 + 1);
                            } while (param_3 < uVar10);
                        }
                        iVar9 = iVar9 + 0x40;
                        local_8 = local_8 + 1;
                        pfVar8 = pfVar8 + uVar10 * uVar4;
                    } while (local_8 < param_2);
                }
            }
            goto LAB_651203;
        }
        if (iVar3 != 3) {
            return 0x8876086c;
        }
    }
    param_2 = (uint32_t)piVar2[4];
    if ((param_2 == 0) || (local_10[2] != -1)) {
        param_2 = 1;
    }
    uVar4 = (uint32_t)piVar2[5];
    iVar3 = *piVar2;
    pfVar8 = (float*)*local_10;
    if (iVar3 == 1) {
        uVar10 = 0;
        if (param_2 != 0) {
            do {
                uVar6 = 0;
                if (param_4 == 0) break;
                if (uVar4 != 0) {
                    do {
                        if (param_4 == 0) break;
                        fVar1 = *param_3;
                        param_3 = param_3 + 1;
                        param_4 = param_4 + -1;
                        *pfVar8 = fVar1;
                        pfVar8 = pfVar8 + 1;
                        uVar6 = uVar6 + 1;
                    } while (uVar6 < uVar4);
                }
                uVar10 = uVar10 + 1;
                pfVar8 = pfVar8 + (4 - uVar4);
            } while (uVar10 < param_2);
        }
    }
    else if (iVar3 == 2) {
        uVar10 = 0;
        if (param_2 != 0) {
            do {
                uVar6 = 0;
                if (param_4 == 0) break;
                if (uVar4 != 0) {
                    do {
                        if (param_4 == 0) break;
                        fVar1 = *param_3;
                        param_3 = param_3 + 1;
                        param_4 = param_4 + -1;
                        *pfVar8 = fVar1;
                        pfVar8 = pfVar8 + 1;
                        uVar6 = uVar6 + 1;
                    } while (uVar6 < uVar4);
                }
                uVar10 = uVar10 + 1;
                pfVar8 = pfVar8 + (4 - uVar4);
            } while (uVar10 < param_2);
        }
    }
    else {
        if (iVar3 != 3) {
            return 0x8876086c;
        }
        uVar10 = 0;
        if (param_2 != 0) {
            do {
                uVar6 = 0;
                if (param_4 == 0) break;
                if (uVar4 != 0) {
                    do {
                        if (param_4 == 0) break;
                        fVar1 = *param_3;
                        param_3 = param_3 + 1;
                        param_4 = param_4 + -1;
                        *pfVar8 = (float)(int32_t)fVar1;
                        pfVar8 = pfVar8 + 1;
                        uVar6 = uVar6 + 1;
                    } while (uVar6 < uVar4);
                }
                uVar10 = uVar10 + 1;
                pfVar8 = pfVar8 + (4 - uVar4);
            } while (uVar10 < param_2);
        }
    }
LAB_651203:
    uVar5 = (uint32_t)FUN_006431b5(local_10);
    return uVar5;
}

// 0x651213 — observed shape
// Download variant: float payload -> nonzero (bool) words, both flat and 2D-tiled shapes.
uint32_t FUN_651213(uint32_t param_1, float* param_2, uint32_t* param_3, float* param_4)
{
    int32_t* piVar1;
    int32_t  iVar2;
    int32_t  iVar3;
    float    fVar4;
    uint32_t* puVar5;
    float*   pfVar6;
    uint32_t* puVar7;
    int32_t  iVar8;
    int32_t  local_18;
    int32_t  local_14;
    int32_t  local_10;
    uint32_t* local_c;

    if (param_4 == (float*)0) {
        return 0;
    }
    if (param_3 == (uint32_t*)0) {
        return 0x8876086c;
    }
    puVar5 = (uint32_t*)FUN_0064e847((uint32_t)param_2, 1, 0);
    if (puVar5 == (uint32_t*)0) {
        return 0x8876086c;
    }
    piVar1 = (int32_t*)puVar5[1];
    iVar8 = piVar1[1];
    if (-1 < iVar8) {
        if (1 < iVar8) {
            if (iVar8 == 2) {
                local_18 = piVar1[4];
                if ((local_18 == 0) || (puVar5[2] != 0xffffffffu)) {
                    local_18 = 1;
                }
                iVar8 = piVar1[5];
                iVar2 = piVar1[6];
                iVar3 = *piVar1;
                param_4 = (float*)*puVar5;
                local_10 = local_18;
                if (iVar3 == 1) {
                    if (local_18 == 0) {
                        return 0;
                    }
                    do {
                        if (iVar2 != 0) {
                            param_1 = (uint32_t)param_3;
                            param_2 = param_4;
                            local_14 = iVar2;
                            do {
                                if (iVar8 != 0) {
                                    pfVar6 = param_2;
                                    puVar7 = (uint32_t*)param_1;
                                    local_18 = iVar8;
                                    do {
                                        fVar4 = *pfVar6;
                                        pfVar6 = pfVar6 + 1;
                                        *puVar7 = (uint32_t)(fVar4 != 0.0f);
                                        puVar7 = puVar7 + iVar2;
                                        local_18 = local_18 + -1;
                                    } while (local_18 != 0);
                                }
                                param_2 = param_2 + 4;
                                param_1 = param_1 + 1;
                                local_14 = local_14 + -1;
                            } while (local_14 != 0);
                        }
                        param_4 = param_4 + 0x10;
                        param_3 = param_3 + iVar2 * iVar8;
                        local_10 = local_10 + -1;
                    } while (local_10 != 0);
                    return 0;
                }
                if (iVar3 == 2) {
                    if (local_18 == 0) {
                        return 0;
                    }
                    do {
                        if (iVar2 != 0) {
                            param_1 = (uint32_t)param_3;
                            param_2 = param_4;
                            local_14 = iVar2;
                            do {
                                if (iVar8 != 0) {
                                    pfVar6 = param_2;
                                    puVar7 = (uint32_t*)param_1;
                                    local_18 = iVar8;
                                    do {
                                        fVar4 = *pfVar6;
                                        pfVar6 = pfVar6 + 1;
                                        *puVar7 = (uint32_t)(fVar4 != 0.0f);
                                        puVar7 = puVar7 + iVar2;
                                        local_18 = local_18 + -1;
                                    } while (local_18 != 0);
                                }
                                param_2 = param_2 + 4;
                                param_1 = param_1 + 1;
                                local_14 = local_14 + -1;
                            } while (local_14 != 0);
                        }
                        param_4 = param_4 + 0x10;
                        param_3 = param_3 + iVar2 * iVar8;
                        local_10 = local_10 + -1;
                    } while (local_10 != 0);
                    return 0;
                }
                if (iVar3 != 3) {
                    return 0x80004005;
                }
                if (local_18 == 0) {
                    return 0;
                }
                do {
                    if (iVar2 != 0) {
                        local_c = param_3;
                        param_1 = (uint32_t)param_4;
                        local_14 = iVar2;
                        do {
                            if (iVar8 != 0) {
                                param_2 = (float*)param_1;
                                puVar7 = local_c;
                                local_10 = iVar8;
                                do {
                                    fVar4 = *param_2;
                                    param_2 = param_2 + 1;
                                    *puVar7 = (uint32_t)(fVar4 != 0.0f);
                                    puVar7 = puVar7 + iVar2;
                                    local_10 = local_10 + -1;
                                } while (local_10 != 0);
                            }
                            param_1 = param_1 + 4;
                            local_c = local_c + 1;
                            local_14 = local_14 + -1;
                        } while (local_14 != 0);
                    }
                    param_4 = param_4 + 0x10;
                    param_3 = param_3 + iVar2 * iVar8;
                    local_18 = local_18 + -1;
                } while (local_18 != 0);
                return 0;
            }
            if (iVar8 != 3) {
                return 0x8876086c;
            }
        }
        iVar8 = piVar1[4];
        if ((iVar8 == 0) || (puVar5[2] != 0xffffffffu)) {
            iVar8 = 1;
        }
        iVar2 = piVar1[5];
        iVar3 = *piVar1;
        pfVar6 = (float*)*puVar5;
        if (iVar3 == 1) {
            if (iVar8 == 0) {
                return 0;
            }
            puVar7 = param_3;
            param_3 = (uint32_t*)iVar8;
            do {
                if (iVar2 != 0) {
                    iVar8 = iVar2;
                    do {
                        fVar4 = *pfVar6;
                        pfVar6 = pfVar6 + 1;
                        *puVar7 = (uint32_t)(fVar4 != 0.0f);
                        puVar7 = puVar7 + 1;
                        iVar8 = iVar8 + -1;
                    } while (iVar8 != 0);
                }
                pfVar6 = pfVar6 + (4 - iVar2);
                param_3 = (uint32_t*)(uintptr_t)((int32_t)param_3 + -1);
            } while (param_3 != (uint32_t*)0);
            return 0;
        }
        if (iVar3 == 2) {
            if (iVar8 == 0) {
                return 0;
            }
            puVar7 = param_3;
            param_3 = (uint32_t*)iVar8;
            do {
                if (iVar2 != 0) {
                    iVar8 = iVar2;
                    do {
                        fVar4 = *pfVar6;
                        pfVar6 = pfVar6 + 1;
                        *puVar7 = (uint32_t)(fVar4 != 0.0f);
                        puVar7 = puVar7 + 1;
                        iVar8 = iVar8 + -1;
                    } while (iVar8 != 0);
                }
                pfVar6 = pfVar6 + (4 - iVar2);
                param_3 = (uint32_t*)(uintptr_t)((int32_t)param_3 + -1);
            } while (param_3 != (uint32_t*)0);
            return 0;
        }
        if (iVar3 == 3) {
            if (iVar8 == 0) {
                return 0;
            }
            puVar7 = param_3;
            param_3 = (uint32_t*)iVar8;
            do {
                if (iVar2 != 0) {
                    iVar8 = iVar2;
                    do {
                        *puVar7 = (uint32_t)(*pfVar6 != 0.0f);
                        puVar7 = puVar7 + 1;
                        pfVar6 = pfVar6 + 1;
                        iVar8 = iVar8 + -1;
                    } while (iVar8 != 0);
                }
                pfVar6 = pfVar6 + (4 - iVar2);
                param_3 = (uint32_t*)(uintptr_t)((int32_t)param_3 + -1);
            } while (param_3 != (uint32_t*)0);
            return 0;
        }
    }
    return 0x8876086c;
}

// 0x6514f2 — observed shape
// Bulk upload variant that normalizes floats to boolean 0/1 values.
uint32_t FUN_6514f2(int32_t param_1, uint32_t param_2, float* param_3, int32_t param_4)
{
    float    fVar1;
    int32_t  iVar2;
    uint32_t uVar3;
    int32_t* piVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    float*   pfVar7;
    float*   pfVar8;
    uint32_t uVar9;
    int32_t  local_18;
    uint32_t local_14;
    int32_t* local_10;
    uint32_t local_8;

    if ((int32_t)param_2 < 0) {
        local_10 = (int32_t*)~param_2;
    }
    else {
        piVar4 = (int32_t*)(uintptr_t)(param_1 + 0xc4);
        *(uint32_t*)(uintptr_t)(*piVar4 + 4)    = 0;
        *(uint32_t*)(uintptr_t)(*piVar4)        = 2;
        *(int32_t*)(uintptr_t)(*piVar4 + 0x10)  = param_4;
        *(uint32_t*)(uintptr_t)(*piVar4 + 0x14) = 1;
        *(uint32_t*)(uintptr_t)(*piVar4 + 0x18) = 1;
        local_10 = (int32_t*)FUN_0064e847(param_2, 1, 1);
        if (local_10 == (int32_t*)0) {
            return 0x8876086c;
        }
    }
    if (*(int32_t*)(uintptr_t)(param_1 + 0x3c) == 3) {
        uVar5 = FUN_00648f01(~(uint32_t)local_10, param_3, param_4);
        return uVar5;
    }
    piVar4 = (int32_t*)local_10[1];
    iVar2 = piVar4[1];
    if (iVar2 < 0) {
        return 0x8876086c;
    }
    if (1 < iVar2) {
        if (iVar2 == 2) {
            param_2 = (uint32_t)piVar4[4];
            uVar3 = (uint32_t)piVar4[5];
            uVar6 = (uint32_t)piVar4[6];
            if ((param_2 == 0) || (local_10[2] != -1)) {
                param_2 = 1;
            }
            iVar2 = *piVar4;
            local_18 = *local_10;
            if (iVar2 == 1) {
                local_14 = 0;
                if (param_2 != 0) {
                    pfVar8 = param_3;
                    do {
                        if (param_4 == 0) break;
                        param_3 = (float*)0;
                        if (uVar6 != 0) {
                            do {
                                local_8 = 0;
                                if (uVar3 != 0) {
                                    pfVar7 = pfVar8 + (int32_t)param_3;
                                    do {
                                        if (param_4 == 0) break;
                                        iVar2 = local_8 + (int32_t)param_3 * 4;
                                        param_4 = param_4 + -1;
                                        local_8 = local_8 + 1;
                                        *(uint32_t*)(uintptr_t)(local_18 + iVar2 * 4) = (uint32_t)(*pfVar7 != 0.0f);
                                        pfVar7 = pfVar7 + uVar6;
                                    } while (local_8 < uVar3);
                                }
                                param_3 = (float*)((int32_t)param_3 + 1);
                            } while (param_3 < uVar6);
                        }
                        local_18 = local_18 + 0x40;
                        local_14 = local_14 + 1;
                        pfVar8 = pfVar8 + uVar6 * uVar3;
                    } while (local_14 < param_2);
                }
            }
            else if (iVar2 == 2) {
                local_14 = 0;
                if (param_2 != 0) {
                    pfVar8 = param_3;
                    do {
                        if (param_4 == 0) break;
                        param_3 = (float*)0;
                        if (uVar6 != 0) {
                            do {
                                local_8 = 0;
                                if (uVar3 != 0) {
                                    pfVar7 = pfVar8 + (int32_t)param_3;
                                    do {
                                        if (param_4 == 0) break;
                                        param_4 = param_4 + -1;
                                        uVar9 = local_8 + 1;
                                        *(float*)(local_18 + (local_8 + (int32_t)param_3 * 4) * 4) = *pfVar7;
                                        pfVar7 = pfVar7 + uVar6;
                                        local_8 = uVar9;
                                    } while (uVar9 < uVar3);
                                }
                                param_3 = (float*)((int32_t)param_3 + 1);
                            } while (param_3 < uVar6);
                        }
                        local_18 = local_18 + 0x40;
                        local_14 = local_14 + 1;
                        pfVar8 = pfVar8 + uVar6 * uVar3;
                    } while (local_14 < param_2);
                }
            }
            else {
                if (iVar2 != 3) {
                    return 0x80004005;
                }
                local_8 = 0;
                if (param_2 != 0) {
                    pfVar8 = param_3;
                    do {
                        if (param_4 == 0) break;
                        param_3 = (float*)0;
                        if (uVar6 != 0) {
                            do {
                                uVar9 = 0;
                                if (uVar3 != 0) {
                                    pfVar7 = pfVar8 + (int32_t)param_3;
                                    do {
                                        if (param_4 == 0) break;
                                        param_4 = param_4 + -1;
                                        *(float*)(local_18 + (uVar9 + (int32_t)param_3 * 4) * 4) =
                                            (float)(int32_t)*pfVar7;
                                        pfVar7 = pfVar7 + uVar6;
                                        uVar9 = uVar9 + 1;
                                    } while (uVar9 < uVar3);
                                }
                                param_3 = (float*)((int32_t)param_3 + 1);
                            } while (param_3 < uVar6);
                        }
                        local_18 = local_18 + 0x40;
                        local_8 = local_8 + 1;
                        pfVar8 = pfVar8 + uVar6 * uVar3;
                    } while (local_8 < param_2);
                }
            }
            goto LAB_651837;
        }
        if (iVar2 != 3) {
            return 0x8876086c;
        }
    }
    param_2 = (uint32_t)piVar4[4];
    if ((param_2 == 0) || (local_10[2] != -1)) {
        param_2 = 1;
    }
    uVar3 = (uint32_t)piVar4[5];
    iVar2 = *piVar4;
    pfVar8 = (float*)*local_10;
    if (iVar2 == 1) {
        uVar6 = 0;
        if (param_2 != 0) {
            do {
                uVar9 = 0;
                if (param_4 == 0) break;
                if (uVar3 != 0) {
                    do {
                        if (param_4 == 0) break;
                        fVar1 = *param_3;
                        param_3 = param_3 + 1;
                        param_4 = param_4 + -1;
                        *pfVar8 = (float)(uint32_t)(fVar1 != 0.0f);
                        pfVar8 = pfVar8 + 1;
                        uVar9 = uVar9 + 1;
                    } while (uVar9 < uVar3);
                }
                uVar6 = uVar6 + 1;
                pfVar8 = pfVar8 + (4 - uVar3);
            } while (uVar6 < param_2);
        }
    }
    else if (iVar2 == 2) {
        uVar6 = 0;
        if (param_2 != 0) {
            do {
                uVar9 = 0;
                if (param_4 == 0) break;
                if (uVar3 != 0) {
                    do {
                        if (param_4 == 0) break;
                        fVar1 = *param_3;
                        param_3 = param_3 + 1;
                        param_4 = param_4 + -1;
                        *pfVar8 = fVar1;
                        pfVar8 = pfVar8 + 1;
                        uVar9 = uVar9 + 1;
                    } while (uVar9 < uVar3);
                }
                uVar6 = uVar6 + 1;
                pfVar8 = pfVar8 + (4 - uVar3);
            } while (uVar6 < param_2);
        }
    }
    else {
        if (iVar2 != 3) {
            return 0x8876086c;
        }
        uVar6 = 0;
        if (param_2 != 0) {
            do {
                uVar9 = 0;
                if (param_4 == 0) break;
                if (uVar3 != 0) {
                    do {
                        if (param_4 == 0) break;
                        fVar1 = *param_3;
                        param_3 = param_3 + 1;
                        param_4 = param_4 + -1;
                        *pfVar8 = (float)(int32_t)fVar1;
                        pfVar8 = pfVar8 + 1;
                        uVar9 = uVar9 + 1;
                    } while (uVar9 < uVar3);
                }
                uVar6 = uVar6 + 1;
                pfVar8 = pfVar8 + (4 - uVar3);
            } while (uVar6 < param_2);
        }
    }
LAB_651837:
    uVar5 = (uint32_t)FUN_006431b5(local_10);
    return uVar5;
}

// 0x651847 — observed shape
// Download variant: integer payload -> nonzero bool words / as-is / float(ftol()) words.
// NEEDS_MANUAL: the integer->float ftol() source operands are elided from the listing
// (x87 pending value only); reconstructed from the sibling float-source traversal.
uint32_t FUN_651847(uint32_t param_1, int32_t param_2, uint32_t* param_3, uint32_t* param_4)
{
    int32_t*  piVar1;
    int32_t   iVar2;
    int32_t   iVar3;
    uint32_t* puVar4;
    uint32_t  uVar5;
    uint32_t* puVar6;
    uint32_t* puVar7;
    int32_t   iVar8;
    int32_t   local_20;
    int32_t   local_1c;
    int32_t   local_18;
    uint32_t* local_14;
    uint32_t* local_c;

    if (param_4 == (uint32_t*)0) {
        return 0;
    }
    if (param_3 == (uint32_t*)0) {
        return 0x8876086c;
    }
    puVar4 = (uint32_t*)FUN_0064e847((uint32_t)param_2, 1, 0);
    if (puVar4 == (uint32_t*)0) {
        return 0x8876086c;
    }
    piVar1 = (int32_t*)puVar4[1];
    iVar2 = piVar1[1];
    if (-1 < iVar2) {
        if (1 < iVar2) {
            if (iVar2 == 2) {
                local_20 = piVar1[4];
                if ((local_20 == 0) || (puVar4[2] != 0xffffffffu)) {
                    local_20 = 1;
                }
                iVar2 = piVar1[5];
                iVar8 = piVar1[6];
                iVar3 = *piVar1;
                param_4 = (uint32_t*)*puVar4;
                local_18 = local_20;
                if (iVar3 == 1) {
                    if (local_20 == 0) {
                        return 0;
                    }
                    do {
                        if (iVar8 != 0) {
                            local_14 = param_3;
                            param_1 = (uint32_t)param_4;
                            local_1c = iVar8;
                            do {
                                if (iVar2 != 0) {
                                    puVar6 = (uint32_t*)param_1;
                                    puVar7 = local_14;
                                    local_20 = iVar2;
                                    do {
                                        uVar5 = *puVar6;
                                        puVar6 = puVar6 + 1;
                                        *puVar7 = (uint32_t)(uVar5 != 0);
                                        puVar7 = puVar7 + iVar8;
                                        local_20 = local_20 + -1;
                                    } while (local_20 != 0);
                                }
                                param_1 = param_1 + 4;
                                local_14 = local_14 + 1;
                                local_1c = local_1c + -1;
                            } while (local_1c != 0);
                        }
                        param_4 = param_4 + 0x10;
                        param_3 = param_3 + iVar8 * iVar2;
                        local_18 = local_18 + -1;
                    } while (local_18 != 0);
                    return 0;
                }
                if (iVar3 == 2) {
                    if (local_20 == 0) {
                        return 0;
                    }
                    do {
                        if (iVar8 != 0) {
                            local_14 = param_3;
                            param_1 = (uint32_t)param_4;
                            local_1c = iVar8;
                            do {
                                if (iVar2 != 0) {
                                    puVar6 = (uint32_t*)param_1;
                                    puVar7 = local_14;
                                    local_20 = iVar2;
                                    do {
                                        *puVar7 = *puVar6;
                                        puVar6 = puVar6 + 1;
                                        puVar7 = puVar7 + iVar8;
                                        local_20 = local_20 + -1;
                                    } while (local_20 != 0);
                                }
                                param_1 = param_1 + 4;
                                local_14 = local_14 + 1;
                                local_1c = local_1c + -1;
                            } while (local_1c != 0);
                        }
                        param_4 = param_4 + 0x10;
                        param_3 = param_3 + iVar8 * iVar2;
                        local_18 = local_18 + -1;
                    } while (local_18 != 0);
                    return 0;
                }
                if (iVar3 != 3) {
                    return 0x80004005;
                }
                if (local_20 == 0) {
                    return 0;
                }
                do {
                    if (iVar8 != 0) {
                        local_14 = param_3;
                        local_1c = iVar8;
                        do {
                            if (iVar2 != 0) {
                                local_c = local_14;
                                local_18 = iVar2;
                                do {
                                    uVar5 = (uint32_t)*(float*)(uintptr_t)param_1; // observed ftol()
                                    local_18 = local_18 + -1;
                                    *local_c = uVar5;
                                    local_c = local_c + iVar8;
                                } while (local_18 != 0);
                            }
                            local_14 = local_14 + 1;
                            local_1c = local_1c + -1;
                        } while (local_1c != 0);
                    }
                    param_3 = param_3 + iVar8 * iVar2;
                    local_20 = local_20 + -1;
                } while (local_20 != 0);
                return 0;
            }
            if (iVar2 != 3) {
                return 0x8876086c;
            }
        }
        param_2 = piVar1[4];
        if ((param_2 == 0) || (puVar4[2] != 0xffffffffu)) {
            param_2 = 1;
        }
        iVar2 = piVar1[5];
        iVar8 = *piVar1;
        puVar6 = (uint32_t*)*puVar4;
        param_4 = (uint32_t*)param_2;
        if (iVar8 == 1) {
            if (param_2 == 0) {
                return 0;
            }
            do {
                if (iVar2 != 0) {
                    iVar8 = iVar2;
                    do {
                        uVar5 = *puVar6;
                        puVar7 = param_3 + 1;
                        puVar6 = puVar6 + 1;
                        iVar8 = iVar8 + -1;
                        *param_3 = (uint32_t)(uVar5 != 0);
                        param_3 = puVar7;
                    } while (iVar8 != 0);
                }
                puVar6 = puVar6 + (4 - iVar2);
                param_4 = (uint32_t*)(uintptr_t)((int32_t)param_4 + -1);
            } while (param_4 != (uint32_t*)0);
            return 0;
        }
        if (iVar8 == 2) {
            if (param_2 == 0) {
                return 0;
            }
            do {
                if (iVar2 != 0) {
                    iVar8 = iVar2;
                    do {
                        *param_3 = *puVar6;
                        param_3 = param_3 + 1;
                        puVar6 = puVar6 + 1;
                        iVar8 = iVar8 + -1;
                    } while (iVar8 != 0);
                }
                puVar6 = puVar6 + (4 - iVar2);
                param_4 = (uint32_t*)(uintptr_t)((int32_t)param_4 + -1);
            } while (param_4 != (uint32_t*)0);
            return 0;
        }
        if (iVar8 == 3) {
            if (param_2 == 0) {
                return 0;
            }
            do {
                if (iVar2 != 0) {
                    param_4 = (uint32_t*)iVar2;
                    do {
                        uVar5 = (uint32_t)*(float*)puVar6; // observed ftol()
                        puVar6 = param_3 + 1;
                        param_4 = (uint32_t*)(uintptr_t)((int32_t)param_4 + -1);
                        *param_3 = uVar5;
                        param_3 = puVar6;
                    } while (param_4 != (uint32_t*)0);
                }
                param_2 = param_2 + -1;
            } while (param_2 != 0);
            return 0;
        }
    }
    return 0x8876086c;
}

// 0x651b11 — observed shape
// Upload of a float plane into a 0x40-pitch subresource with three element encodings.
// NEEDS_MANUAL: the int<->float ftol() source operands in the type-2 paths are elided
// from the listing; reconstructed from the sibling typed traversals.
uint32_t FUN_651b11(int32_t param_1, uint32_t param_2, float* param_3, int32_t param_4)
{
    int32_t* piVar1;
    int32_t  iVar2;
    uint32_t uVar3;
    uint32_t uVar4;
    float*   pfVar5;
    uint32_t uVar6;
    float    fVar7;
    float*   pfVar8;
    uint32_t uVar9;
    int32_t* local_18;
    float*   local_14;
    uint32_t local_10;
    uint32_t local_c;

    if ((int32_t)param_2 < 0) {
        local_18 = (int32_t*)~param_2;
    }
    else {
        piVar1 = (int32_t*)(uintptr_t)(param_1 + 0xc4);
        *(uint32_t*)(uintptr_t)(*piVar1 + 4)    = 0;
        *(uint32_t*)(uintptr_t)(*piVar1)        = 3;
        *(int32_t*)(uintptr_t)(*piVar1 + 0x10)  = param_4;
        *(uint32_t*)(uintptr_t)(*piVar1 + 0x14) = 1;
        *(uint32_t*)(uintptr_t)(*piVar1 + 0x18) = 1;
        local_18 = (int32_t*)FUN_0064e847(param_2, 1, 1);
        if (local_18 == (int32_t*)0) {
            return 0x8876086c;
        }
    }
    if (*(int32_t*)(uintptr_t)(param_1 + 0x3c) == 3) {
        uVar4 = (uint32_t)FUN_00648faa(~(uint32_t)local_18, param_3, param_4);
        return uVar4;
    }
    piVar1 = (int32_t*)local_18[1];
    iVar2 = piVar1[1];
    if (iVar2 < 0) {
        return 0x8876086c;
    }
    if (1 < iVar2) {
        if (iVar2 == 2) {
            uVar3 = (uint32_t)piVar1[5];
            local_10 = (uint32_t)piVar1[4];
            uVar9 = (uint32_t)piVar1[6];
            if ((local_10 == 0) || (local_18[2] != -1)) {
                local_10 = 1;
            }
            iVar2 = *piVar1;
            param_2 = (uint32_t)*local_18;
            if (iVar2 == 1) {
                local_c = 0;
                if (local_10 != 0) {
                    pfVar8 = param_3;
                    do {
                        if (param_4 == 0) break;
                        param_3 = (float*)0;
                        if (uVar9 != 0) {
                            do {
                                uVar6 = 0;
                                if (uVar3 != 0) {
                                    local_14 = pfVar8 + (int32_t)param_3;
                                    do {
                                        if (param_4 == 0) break;
                                        param_4 = param_4 + -1;
                                        *(uint32_t*)(uintptr_t)(param_2 + (uVar6 + (int32_t)param_3 * 4) * 4) =
                                            (uint32_t)(*local_14 != 0.0f);
                                        local_14 = local_14 + uVar9;
                                        uVar6 = uVar6 + 1;
                                    } while (uVar6 < uVar3);
                                }
                                param_3 = (float*)((int32_t)param_3 + 1);
                            } while (param_3 < uVar9);
                        }
                        param_2 = param_2 + 0x40;
                        local_c = local_c + 1;
                        pfVar8 = pfVar8 + uVar9 * uVar3;
                    } while (local_c < local_10);
                }
            }
            else if (iVar2 == 2) {
                local_14 = (float*)0;
                if (local_10 != 0) {
                    do {
                        if (param_4 == 0) break;
                        param_3 = (float*)0;
                        if (uVar9 != 0) {
                            do {
                                local_c = 0;
                                if (uVar3 != 0) {
                                    pfVar5 = pfVar8 + (int32_t)param_3;
                                    do {
                                        if (param_4 == 0) break;
                                        uVar4 = (uint32_t)*pfVar5; // observed ftol()
                                        param_4 = param_4 + -1;
                                        uVar6 = local_c + 1;
                                        *(uint32_t*)(uintptr_t)(param_2 + (local_c + (int32_t)param_3 * 4) * 4) =
                                            uVar4;
                                        pfVar5 = pfVar5 + uVar9;
                                        local_c = uVar6;
                                    } while (uVar6 < uVar3);
                                }
                                param_3 = (float*)((int32_t)param_3 + 1);
                            } while (param_3 < uVar9);
                        }
                        param_2 = param_2 + 0x40;
                        local_14 = (float*)((int32_t)local_14 + 1);
                    } while (local_14 < local_10);
                }
            }
            else {
                if (iVar2 != 3) {
                    return 0x80004005;
                }
                local_c = 0;
                if (local_10 != 0) {
                    pfVar8 = param_3;
                    do {
                        if (param_4 == 0) break;
                        param_3 = (float*)0;
                        if (uVar9 != 0) {
                            do {
                                uVar6 = 0;
                                if (uVar3 != 0) {
                                    pfVar5 = pfVar8 + (int32_t)param_3;
                                    do {
                                        if (param_4 == 0) break;
                                        param_4 = param_4 + -1;
                                        *(float*)(param_2 + (uVar6 + (int32_t)param_3 * 4) * 4) = *pfVar5;
                                        uVar6 = uVar6 + 1;
                                        pfVar5 = pfVar5 + uVar9;
                                    } while (uVar6 < uVar3);
                                }
                                param_3 = (float*)((int32_t)param_3 + 1);
                            } while (param_3 < uVar9);
                        }
                        param_2 = param_2 + 0x40;
                        local_c = local_c + 1;
                        pfVar8 = pfVar8 + uVar9 * uVar3;
                    } while (local_c < local_10);
                }
            }
            goto LAB_651e97;
        }
        if (iVar2 != 3) {
            return 0x8876086c;
        }
    }
    param_2 = (uint32_t)piVar1[4];
    if ((param_2 == 0) || (local_18[2] != -1)) {
        param_2 = 1;
    }
    uVar3 = (uint32_t)piVar1[5];
    iVar2 = *piVar1;
    pfVar8 = (float*)*local_18;
    if (iVar2 == 1) {
        uVar9 = 0;
        if (param_2 != 0) {
            do {
                uVar6 = 0;
                if (param_4 == 0) break;
                if (uVar3 != 0) {
                    do {
                        if (param_4 == 0) break;
                        fVar7 = *param_3;
                        param_3 = param_3 + 1;
                        param_4 = param_4 + -1;
                        *pfVar8 = (float)(uint32_t)(fVar7 != 0.0f);
                        pfVar8 = pfVar8 + 1;
                        uVar6 = uVar6 + 1;
                    } while (uVar6 < uVar3);
                }
                uVar9 = uVar9 + 1;
                pfVar8 = pfVar8 + (4 - uVar3);
            } while (uVar9 < param_2);
        }
    }
    else if (iVar2 == 2) {
        local_14 = (float*)0;
        if (param_2 != 0) {
            do {
                uVar9 = 0;
                if (param_4 == 0) break;
                if (uVar3 != 0) {
                    do {
                        if (param_4 == 0) break;
                        fVar7 = (float)(int32_t)*param_3; // observed float(ftol())
                        param_3 = param_3 + 1;
                        param_4 = param_4 + -1;
                        *pfVar8 = fVar7;
                        pfVar8 = pfVar8 + 1;
                        uVar9 = uVar9 + 1;
                    } while (uVar9 < uVar3);
                }
                local_14 = (float*)((int32_t)local_14 + 1);
                pfVar8 = pfVar8 + (4 - uVar3);
            } while (local_14 < param_2);
        }
    }
    else {
        if (iVar2 != 3) {
            return 0x8876086c;
        }
        uVar9 = 0;
        if (param_2 != 0) {
            do {
                uVar6 = 0;
                if (param_4 == 0) break;
                if (uVar3 != 0) {
                    do {
                        if (param_4 == 0) break;
                        fVar7 = *param_3;
                        param_3 = param_3 + 1;
                        param_4 = param_4 + -1;
                        *pfVar8 = fVar7;
                        pfVar8 = pfVar8 + 1;
                        uVar6 = uVar6 + 1;
                    } while (uVar6 < uVar3);
                }
                uVar9 = uVar9 + 1;
                pfVar8 = pfVar8 + (4 - uVar3);
            } while (uVar9 < param_2);
        }
    }
LAB_651e97:
    uVar4 = (uint32_t)FUN_006431b5(local_18);
    return uVar4;
}

// 0x651ea7 — observed shape
// Download of a float plane: nonzero -> bool, value -> int-truncated float, value as-is.
uint32_t FUN_651ea7(uint32_t param_1, float* param_2, float* param_3, float* param_4)
{
    float    fVar1;
    int32_t* piVar2;
    int32_t  iVar3;
    uint32_t* puVar4;
    float*   pfVar5;
    int32_t  iVar6;
    int32_t  iVar7;
    float*   pfVar8;
    int32_t  local_18;
    int32_t  local_14;
    int32_t  local_10;

    if (param_4 == (float*)0) {
        return 0;
    }
    if (param_3 == (float*)0) {
        return 0x8876086c;
    }
    puVar4 = (uint32_t*)FUN_0064e847((uint32_t)param_2, 1, 0);
    if (puVar4 == (uint32_t*)0) {
        return 0x8876086c;
    }
    piVar2 = (int32_t*)puVar4[1];
    iVar3 = piVar2[1];
    if (-1 < iVar3) {
        if (1 < iVar3) {
            if (iVar3 == 2) {
                local_18 = piVar2[4];
                if ((local_18 == 0) || (puVar4[2] != 0xffffffffu)) {
                    local_18 = 1;
                }
                iVar3 = piVar2[5];
                iVar7 = piVar2[6];
                iVar6 = *piVar2;
                param_4 = (float*)*puVar4;
                if (iVar6 == 1) {
                    if (local_18 == 0) {
                        return 0;
                    }
                    local_10 = local_18;
                    do {
                        if (iVar7 != 0) {
                            param_1 = (uint32_t)param_3;
                            param_2 = param_4;
                            local_14 = iVar7;
                            do {
                                if (iVar3 != 0) {
                                    pfVar5 = param_2;
                                    pfVar8 = (float*)(uintptr_t)param_1;
                                    local_18 = iVar3;
                                    do {
                                        fVar1 = *pfVar5;
                                        pfVar5 = pfVar5 + 1;
                                        *pfVar8 = (float)(fVar1 != 0.0f);
                                        pfVar8 = pfVar8 + iVar7;
                                        local_18 = local_18 + -1;
                                    } while (local_18 != 0);
                                }
                                param_2 = param_2 + 4;
                                param_1 = param_1 + 1;
                                local_14 = local_14 + -1;
                            } while (local_14 != 0);
                        }
                        param_4 = param_4 + 0x10;
                        param_3 = param_3 + iVar7 * iVar3;
                        local_10 = local_10 + -1;
                    } while (local_10 != 0);
                    return 0;
                }
                if (iVar6 == 2) {
                    if (local_18 == 0) {
                        return 0;
                    }
                    local_14 = local_18;
                    do {
                        if (iVar7 != 0) {
                            param_1 = (uint32_t)param_3;
                            param_2 = param_4;
                            local_18 = iVar7;
                            do {
                                if (iVar3 != 0) {
                                    iVar6 = iVar3;
                                    pfVar5 = param_2;
                                    pfVar8 = (float*)(uintptr_t)param_1;
                                    do {
                                        fVar1 = *pfVar5;
                                        pfVar5 = pfVar5 + 1;
                                        *pfVar8 = (float)(int32_t)fVar1;
                                        pfVar8 = pfVar8 + iVar7;
                                        iVar6 = iVar6 + -1;
                                    } while (iVar6 != 0);
                                }
                                param_2 = param_2 + 4;
                                param_1 = param_1 + 1;
                                local_18 = local_18 + -1;
                            } while (local_18 != 0);
                        }
                        param_4 = param_4 + 0x10;
                        param_3 = param_3 + iVar7 * iVar3;
                        local_14 = local_14 + -1;
                    } while (local_14 != 0);
                    return 0;
                }
                if (iVar6 != 3) {
                    return 0x80004005;
                }
                if (local_18 == 0) {
                    return 0;
                }
                do {
                    if (iVar7 != 0) {
                        param_1 = (uint32_t)param_3;
                        param_2 = param_4;
                        local_14 = iVar7;
                        do {
                            if (iVar3 != 0) {
                                pfVar5 = param_2;
                                pfVar8 = (float*)(uintptr_t)param_1;
                                local_10 = iVar3;
                                do {
                                    *pfVar8 = *pfVar5;
                                    pfVar5 = pfVar5 + 1;
                                    pfVar8 = pfVar8 + iVar7;
                                    local_10 = local_10 + -1;
                                } while (local_10 != 0);
                            }
                            param_2 = param_2 + 4;
                            param_1 = param_1 + 1;
                            local_14 = local_14 + -1;
                        } while (local_14 != 0);
                    }
                    param_4 = param_4 + 0x10;
                    param_3 = param_3 + iVar7 * iVar3;
                    local_18 = local_18 + -1;
                } while (local_18 != 0);
                return 0;
            }
            if (iVar3 != 3) {
                return 0x8876086c;
            }
        }
        param_4 = (float*)(uintptr_t)piVar2[4];
        if ((param_4 == (float*)0) || (puVar4[2] != 0xffffffffu)) {
            param_4 = (float*)(uintptr_t)1;
        }
        iVar3 = piVar2[5];
        iVar7 = *piVar2;
        pfVar5 = (float*)*puVar4;
        if (iVar7 == 1) {
            if (param_4 == (float*)0) {
                return 0;
            }
            do {
                if (iVar3 != 0) {
                    iVar7 = iVar3;
                    do {
                        fVar1 = *pfVar5;
                        pfVar5 = pfVar5 + 1;
                        pfVar8 = param_3 + 1;
                        iVar7 = iVar7 + -1;
                        *param_3 = (float)(fVar1 != 0.0f);
                        param_3 = pfVar8;
                    } while (iVar7 != 0);
                }
                pfVar5 = pfVar5 + (4 - iVar3);
                param_4 = (float*)((int32_t)param_4 + -1);
            } while (param_4 != (float*)0);
            return 0;
        }
        if (iVar7 == 2) {
            if (param_4 == (float*)0) {
                return 0;
            }
            do {
                if (iVar3 != 0) {
                    iVar7 = iVar3;
                    do {
                        fVar1 = *pfVar5;
                        pfVar5 = pfVar5 + 1;
                        *param_3 = (float)(int32_t)fVar1;
                        param_3 = param_3 + 1;
                        iVar7 = iVar7 + -1;
                    } while (iVar7 != 0);
                }
                pfVar5 = pfVar5 + (4 - iVar3);
                param_4 = (float*)((int32_t)param_4 + -1);
            } while (param_4 != (float*)0);
            return 0;
        }
        if (iVar7 == 3) {
            if (param_4 == (float*)0) {
                return 0;
            }
            do {
                if (iVar3 != 0) {
                    iVar7 = iVar3;
                    do {
                        *param_3 = *pfVar5;
                        param_3 = param_3 + 1;
                        pfVar5 = pfVar5 + 1;
                        iVar7 = iVar7 + -1;
                    } while (iVar7 != 0);
                }
                pfVar5 = pfVar5 + (4 - iVar3);
                param_4 = (float*)((int32_t)param_4 + -1);
            } while (param_4 != (float*)0);
            return 0;
        }
    }
    return 0x8876086c;
}

// 0x65214a — observed shape
uint32_t FUN_65214a(int32_t param_1, uint32_t param_2, float param_3)
{
    int32_t*  piVar1;
    uint32_t  uVar2;
    int32_t   iVar3;
    uint32_t* puVar4;

    if ((int32_t)param_2 < 0) {
        puVar4 = (uint32_t*)~param_2;
    }
    else {
        piVar1 = (int32_t*)(uintptr_t)(param_1 + 0xc4);
        *(uint32_t*)(uintptr_t)(*piVar1 + 4)    = 0;
        *(uint32_t*)(uintptr_t)(*piVar1)        = 3;
        *(uint32_t*)(uintptr_t)(*piVar1 + 0x10) = 0;
        *(uint32_t*)(uintptr_t)(*piVar1 + 0x14) = 1;
        *(uint32_t*)(uintptr_t)(*piVar1 + 0x18) = 1;
        puVar4 = (uint32_t*)FUN_0064e847(param_2, 1, 1);
        if (puVar4 == (uint32_t*)0) {
            return 0x8876086c;
        }
    }
    piVar1 = (int32_t*)puVar4[1];
    if ((piVar1[4] != 0) && (puVar4[2] == 0xffffffffu)) {
        return 0x8876086c;
    }
    if (*(int32_t*)(uintptr_t)(param_1 + 0x3c) == 3) {
        uVar2 = (uint32_t)FUN_00648db0(~(uint32_t)puVar4, param_3);
    }
    else {
        if (piVar1[1] < 0) {
            return 0x8876086c;
        }
        if (3 < piVar1[1]) {
            return 0x8876086c;
        }
        if (piVar1[5] != 1) {
            return 0x8876086c;
        }
        if (piVar1[6] != 1) {
            return 0x8876086c;
        }
        iVar3 = *piVar1;
        if (iVar3 == 1) {
            if (*(uint32_t*)*puVar4 == (uint32_t)(param_3 != 0.0f)) {
                return 0;
            }
            *(uint32_t*)*puVar4 = (uint32_t)(param_3 != 0.0f);
        }
        else if (iVar3 == 2) {
            piVar1 = (int32_t*)*puVar4;
            iVar3 = (int32_t)param_3; // observed ftol()
            if (*piVar1 == iVar3) {
                return 0;
            }
            *piVar1 = iVar3;
        }
        else {
            if (iVar3 != 3) {
                return 0x8876086c;
            }
            if (*(float*)*puVar4 == param_3) {
                return 0;
            }
            *(float*)*puVar4 = param_3;
        }
        uVar2 = (uint32_t)FUN_006431b5(puVar4);
    }
    return uVar2;
}

// 0x652274 — observed shape
uint32_t FUN_652274(uint32_t param_1, uint32_t param_2, float* param_3)
{
    int32_t*  piVar1;
    int32_t   iVar2;
    uint32_t* puVar3;
    uint32_t  uVar4;

    (void)param_1;
    if (((((param_3 == (float*)0) ||
           (puVar3 = (uint32_t*)FUN_0064e847(param_2, 1, 0), puVar3 == (uint32_t*)0)) ||
          ((piVar1 = (int32_t*)puVar3[1], piVar1[4] != 0 && (puVar3[2] == 0xffffffffu)))) ||
         (((piVar1[1] < 0 || (3 < piVar1[1])) || (piVar1[5] != 1)))) || (piVar1[6] != 1)) {
        return 0x8876086c;
    }
    iVar2 = *piVar1;
    if (iVar2 == 1) {
        uVar4 = (uint32_t)(*(int32_t*)*puVar3 != 0);
    }
    else {
        if (iVar2 != 2) {
            if (iVar2 == 3) {
                *param_3 = *(float*)*puVar3;
                return 0;
            }
            return 0x8876086c;
        }
        uVar4 = *(uint32_t*)*puVar3;
    }
    *param_3 = (float)(int32_t)uVar4;
    return 0;
}

// 0x6522f5 — observed shape
// Large stream loader/constructor: reads a tagged header, copies the embedded blob,
// allocates the animation (0x50), character (0xb4) and 0x18-stride tables, links the
// per-subobject chains through the 0xb0 index, then walks the sprite lists.
// Receivers: in_ECX = self.
// NEEDS_MANUAL: 0x8007000e / 0x80004005 label targets folded into the shared epilogue;
// inline COM-style vtable dispatches use the observed `code` calling convention.
int32_t FUN_6522f5(void* self, uint32_t param_1, uint32_t* param_2, int32_t* param_3,
                   uint32_t* param_4)
{
    uint16_t  uVar1;
    uint16_t  uVar2;
    int16_t   sVar3;
    uint16_t  uVar4;
    uint32_t* puVar5;
    int32_t   iVar6;
    uint32_t  uVar7;
    uint32_t  uVar8;
    int32_t*  piVar9;
    uint32_t* puVar10;
    uint32_t  uVar11;
    int32_t   iVar12;
    int32_t   iVar13;
    int32_t   in_ECX = (int32_t)(intptr_t)self;
    int32_t   iVar14;
    int32_t   iVar15;
    int16_t*  psVar16;
    int32_t   iVar17;
    uint32_t* puVar18;
    uint32_t* puVar19;
    int32_t   iVar20;
    uint32_t  local_30;
    uint32_t  local_2c;
    uint32_t  local_28;
    uint32_t  local_24;
    uint32_t  local_20;
    int32_t   local_1c;
    int32_t   local_18;
    int32_t   local_14;
    int32_t   local_10;
    int32_t   local_c;
    int32_t   local_8;

    puVar5 = param_4;
    if ((param_1 == 0) || (param_3 == (int32_t*)0)) {
        iVar6 = (int32_t)0x8876086c;
        goto LAB_653291;
    }
    iVar6 = FUN_00533c78(0x1c);
    *(int32_t*)(uintptr_t)(in_ECX + 0xc4) = iVar6;
    if (iVar6 == 0) goto LAB_652329;
    iVar6 = FUN_0063e58b();
    if (iVar6 < 0) goto LAB_653291;
    puVar10 = *(uint32_t**)(uintptr_t)(in_ECX + 0xc4);
    for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar10 = 0;
        puVar10 = puVar10 + 1;
    }
    *(uint32_t**)(uintptr_t)(in_ECX + 0x38) = param_2;
    if (param_2 != (uint32_t*)0) {
        (**(code**)(*param_2 + 4))(param_2);
    }
    FUN_006411ea(param_1);
    *(int32_t**)(uintptr_t)(in_ECX + 0x28) = param_3;
    (**(code**)(*param_3 + 4))(param_3);
    param_1 = *param_4;
    uVar7 = (**(code**)(*param_3 + 0x10))(param_3);
    if (param_1 + 1 <= uVar7) {
        param_1 = *param_4;
        iVar6 = (**(code**)(*param_3 + 0xc))(param_3);
        param_2 = *(uint32_t**)(uintptr_t)(iVar6 + param_1 * 4);
    }
    *param_4 = param_1 + 1;
    uVar7 = (**(code**)(*param_3 + 0x10))(param_3);
    if (*param_4 + 1 <= uVar7) {
        iVar6 = (**(code**)(*param_3 + 0xc))(param_3);
        *(uint32_t*)(uintptr_t)(in_ECX + 0x1c) = *(uint32_t*)(uintptr_t)(iVar6 + *param_4 * 4);
    }
    *param_4 = *param_4 + 1;
    if ((param_2 == (uint32_t*)0xfeff0901) &&
        (uVar7 = (**(code**)(*param_3 + 0x10))(param_3), *param_4 <= uVar7)) {
        if (*(void**)(uintptr_t)(in_ECX + 0x20) != (void*)0) {
            operator_delete__(*(void**)(uintptr_t)(in_ECX + 0x20));
            *(uint32_t*)(uintptr_t)(in_ECX + 0x20) = 0;
        }
        iVar6 = FUN_00533c78(*(uint32_t*)(uintptr_t)(in_ECX + 0x1c));
        *(int32_t*)(uintptr_t)(in_ECX + 0x20) = iVar6;
        if (iVar6 == 0) goto LAB_652329;
        if (*(int32_t*)(uintptr_t)(in_ECX + 0x1c) != 0) {
            uVar7 = *(uint32_t*)(uintptr_t)(in_ECX + 0x1c);
            uVar8 = (**(code**)(*param_3 + 0x10))(param_3);
            if ((uint32_t)((uVar7 & 3) != 0) + (uVar7 >> 2) + *param_4 <= uVar8) {
                iVar6 = (**(code**)(*param_3 + 0xc))(param_3);
                puVar10 = (uint32_t*)(uintptr_t)(iVar6 + *param_4 * 4);
                puVar18 = *(uint32_t**)(uintptr_t)(in_ECX + 0x20);
                for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                    *puVar18 = *puVar10;
                    puVar10 = puVar10 + 1;
                    puVar18 = puVar18 + 1;
                }
                for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
                    *(uint8_t*)puVar18 = *(uint8_t*)puVar10;
                    puVar10 = (uint32_t*)(uintptr_t)((int32_t)puVar10 + 1);
                    puVar18 = (uint32_t*)(uintptr_t)((int32_t)puVar18 + 1);
                }
            }
            *param_4 = *param_4 +
                       (uint32_t)((*(uint32_t*)(uintptr_t)(in_ECX + 0x1c) & 3) != 0) +
                       (*(uint32_t*)(uintptr_t)(in_ECX + 0x1c) >> 2);
        }
        uVar7 = (**(code**)(*param_3 + 0x10))(param_3);
        if (*param_4 + 1 <= uVar7) {
            iVar6 = (**(code**)(*param_3 + 0xc))(param_3);
            *(uint32_t*)(uintptr_t)(in_ECX + 0x98) = *(uint32_t*)(uintptr_t)(iVar6 + *param_4 * 4);
        }
        *param_4 = *param_4 + 1;
        uVar7 = (**(code**)(*param_3 + 0x10))(param_3);
        if (*param_4 + 1 <= uVar7) {
            iVar6 = (**(code**)(*param_3 + 0xc))(param_3);
            *(uint32_t*)(uintptr_t)(in_ECX + 0xa0) = *(uint32_t*)(uintptr_t)(iVar6 + *param_4 * 4);
        }
        *param_4 = *param_4 + 1;
        uVar7 = (**(code**)(*param_3 + 0x10))(param_3);
        if (*param_4 + 1 <= uVar7) {
            iVar6 = (**(code**)(*param_3 + 0xc))(param_3);
            *(uint32_t*)(uintptr_t)(in_ECX + 0x34) = *(uint32_t*)(uintptr_t)(iVar6 + *param_4 * 4);
        }
        *param_4 = *param_4 + 1;
        uVar7 = (**(code**)(*param_3 + 0x10))(param_3);
        if (*param_4 + 1 <= uVar7) {
            iVar6 = (**(code**)(*param_3 + 0xc))(param_3);
            *(uint32_t*)(uintptr_t)(in_ECX + 0x14) = *(uint32_t*)(uintptr_t)(iVar6 + *param_4 * 4);
        }
        *param_4 = *param_4 + 1;
        uVar7 = (**(code**)(*param_3 + 0x10))(param_3);
        if (((*param_4 <= uVar7) && (3 < *(uint32_t*)(uintptr_t)(in_ECX + 0x1c))) &&
            (**(int32_t**)(uintptr_t)(in_ECX + 0x20) == 0)) {
            iVar6 = *(int32_t*)(uintptr_t)(in_ECX + 0x34);
            if (iVar6 != 0) {
                piVar9 = (int32_t*)FUN_00533c78(iVar6 * 100 + 4);
                if (piVar9 == (int32_t*)0) {
                    piVar9 = (int32_t*)0;
                }
                else {
                    *piVar9 = iVar6;
                    piVar9 = piVar9 + 1;
                    FUN_004127b0(piVar9, 100, iVar6, FUN_0063e327);
                }
                *(int32_t**)(uintptr_t)(in_ECX + 0x2c) = piVar9;
                if (piVar9 == (int32_t*)0) goto LAB_652329;
            }
            iVar6 = *(int32_t*)(uintptr_t)(in_ECX + 0x98);
            *(uint16_t*)(uintptr_t)(in_ECX + 0x30) = 0;
            if (iVar6 != 0) {
                piVar9 = (int32_t*)FUN_00533c78(iVar6 * 0x50 + 4);
                if (piVar9 == (int32_t*)0) {
                    piVar9 = (int32_t*)0;
                }
                else {
                    *piVar9 = iVar6;
                    piVar9 = piVar9 + 1;
                    FUN_004127b0(piVar9, 0x50, iVar6, FUN_00647b28);
                }
                *(int32_t**)(uintptr_t)(in_ECX + 0x9c) = piVar9;
                if (piVar9 == (int32_t*)0) goto LAB_652329;
            }
            iVar6 = *(int32_t*)(uintptr_t)(in_ECX + 0xa0);
            if (iVar6 != 0) {
                piVar9 = (int32_t*)FUN_00533c78(iVar6 * 0xb4 + 4);
                if (piVar9 == (int32_t*)0) {
                    piVar9 = (int32_t*)0;
                }
                else {
                    *piVar9 = iVar6;
                    piVar9 = piVar9 + 1;
                    FUN_004127b0(piVar9, 0xb4, iVar6, FUN_00646bc5);
                }
                *(int32_t**)(uintptr_t)(in_ECX + 0xa4) = piVar9;
                if (piVar9 != (int32_t*)0) {
                    iVar6 = *(int32_t*)(uintptr_t)(in_ECX + 0x14);
                    if (iVar6 != 0) {
                        piVar9 = (int32_t*)FUN_00533c78(iVar6 * 0x18 + 4);
                        if (piVar9 == (int32_t*)0) {
                            piVar9 = (int32_t*)0;
                        }
                        else {
                            *piVar9 = iVar6;
                            piVar9 = piVar9 + 1;
                            FUN_004127b0(piVar9, 0x18, iVar6, &LAB_0063e3eb);
                        }
                        *(int32_t**)(uintptr_t)(in_ECX + 0x18) = piVar9;
                        if (piVar9 == (int32_t*)0) goto LAB_652329;
                    }
                    uVar7 = (**(code**)(*param_3 + 0x10))(param_3);
                    if (uVar7 < *param_4) goto LAB_653039;
                    uVar7 = 0;
                    *(uint32_t*)(uintptr_t)(in_ECX + 0xa8) = 1;
                    param_2 = (uint32_t*)0;
                    if (*(int32_t*)(uintptr_t)(in_ECX + 0x98) != 0) {
                        do {
                            iVar6 = FUN_0064e079(uVar7 * 0x50 + *(int32_t*)(uintptr_t)(in_ECX + 0x9c),
                                                 param_3, param_4);
                            if (iVar6 < 0) goto LAB_653291;
                            param_2 = (uint32_t*)(uintptr_t)((int32_t)param_2 + 1);
                            uVar7 = (uint32_t)param_2 & 0xffff;
                        } while (uVar7 < *(uint32_t*)(uintptr_t)(in_ECX + 0x98));
                    }
                    uVar7 = 0;
                    uVar1 = 0;
                    if (*(int32_t*)(uintptr_t)(in_ECX + 0xa0) != 0) {
                        do {
                            *(uint16_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0xa4) + 0x14 + uVar7 * 0xb4) = uVar1;
                            iVar6 = FUN_0064e266(*(int32_t*)(uintptr_t)(in_ECX + 0xa4) + uVar7 * 0xb4,
                                                 param_3, param_4);
                            if (iVar6 < 0) goto LAB_653291;
                            uVar1 = uVar1 + 1;
                            uVar7 = (uint32_t)uVar1;
                        } while (uVar7 < *(uint32_t*)(uintptr_t)(in_ECX + 0xa0));
                    }
                    iVar6 = *(int32_t*)(uintptr_t)(in_ECX + 300) + *(int32_t*)(uintptr_t)(in_ECX + 0x1c) +
                            *(int32_t*)(uintptr_t)(in_ECX + 0x128) + 0x20 + *(int32_t*)(uintptr_t)(in_ECX + 0x124);
                    puVar10 = (uint32_t*)FUN_00533c78(iVar6);
                    if (puVar10 != (uint32_t*)0) {
                        uVar7 = *(uint32_t*)(uintptr_t)(in_ECX + 0x1c);
                        puVar18 = *(uint32_t**)(uintptr_t)(in_ECX + 0x20);
                        puVar19 = puVar10;
                        for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                            *puVar19 = *puVar18;
                            puVar18 = puVar18 + 1;
                            puVar19 = puVar19 + 1;
                        }
                        for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
                            *(uint8_t*)puVar19 = *(uint8_t*)puVar18;
                            puVar18 = (uint32_t*)(uintptr_t)((int32_t)puVar18 + 1);
                            puVar19 = (uint32_t*)(uintptr_t)((int32_t)puVar19 + 1);
                        }
                        uVar8 = iVar6 - *(int32_t*)(uintptr_t)(in_ECX + 0x1c);
                        puVar18 = (uint32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0x1c) + (int32_t)puVar10);
                        for (uVar7 = uVar8 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
                            *puVar18 = 0;
                            puVar18 = puVar18 + 1;
                        }
                        for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
                            *(uint8_t*)puVar18 = 0;
                            puVar18 = (uint32_t*)(uintptr_t)((int32_t)puVar18 + 1);
                        }
                        local_10 = (((uint32_t)(*(int32_t*)(uintptr_t)(in_ECX + 0x1c) + (int32_t)puVar10) &
                                     0xffffffe0) - (int32_t)puVar10) + 0x20;
                        local_14 = *(int32_t*)(uintptr_t)(in_ECX + 0x124) + local_10;
                        local_c  = *(int32_t*)(uintptr_t)(in_ECX + 0x128) + local_14;
                        if (*(void**)(uintptr_t)(in_ECX + 0x20) != (void*)0) {
                            operator_delete__(*(void**)(uintptr_t)(in_ECX + 0x20));
                            *(uint32_t*)(uintptr_t)(in_ECX + 0x20) = 0;
                        }
                        *(uint32_t**)(uintptr_t)(in_ECX + 0x20) = puVar10;
                        piVar9 = (int32_t*)FUN_00533c78(*(int32_t*)(uintptr_t)(in_ECX + 0xa8) << 2);
                        *(int32_t**)(uintptr_t)(in_ECX + 0xb0) = piVar9;
                        if (piVar9 != (int32_t*)0) {
                            param_2 = (uint32_t*)0;
                            *piVar9 = in_ECX + 0x48;
                            param_1 = 1;
                            if (*(int32_t*)(uintptr_t)(in_ECX + 0x98) != 0) {
                                do {
                                    uVar7 = param_1 & 0xffff;
                                    if (*(uint32_t*)(uintptr_t)(in_ECX + 0xa8) <= uVar7) break;
                                    local_30 = ((uint32_t)param_2 & 0xffff) * 0x50;
                                    piVar9 = (int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0x9c) + local_30);
                                    *(int32_t**)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0xb0) + uVar7 * 4) = piVar9;
                                    piVar9[5] = (int32_t)uVar7;
                                    iVar6 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0xb0) + uVar7 * 4);
                                    if (*(int32_t*)(uintptr_t)(iVar6 + 0x40) == 0) {
                                        iVar14 = *(int32_t*)(uintptr_t)(in_ECX + 0x20);
                                    }
                                    else {
                                        iVar14 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0x38) + 0x10);
                                    }
                                    local_8 = *(int32_t*)(uintptr_t)(iVar6 + 0x2c) + iVar14 + piVar9[6];
                                    iVar6 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0xb0) + piVar9[5] * 4);
                                    if (*(int32_t*)(uintptr_t)(iVar6 + 0x40) == 0) {
                                        local_18 = *(int32_t*)(uintptr_t)(in_ECX + 0x20);
                                    }
                                    else {
                                        local_18 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0x38) + 0x10);
                                    }
                                    local_18 = piVar9[7] + *(int32_t*)(uintptr_t)(iVar6 + 0x30) + local_18;
                                    local_20 = (uint32_t)piVar9[0xb];
                                    local_1c = piVar9[0xc];
                                    *(uint16_t*)(uintptr_t)(piVar9 + 0x11) = *(uint16_t*)(uintptr_t)(in_ECX + 0x30);
                                    *(uint16_t*)(uintptr_t)((int32_t)piVar9 + 0x46) = 0;
                                    iVar6 = FUN_006480e4(&local_8, &local_18, uVar7);
                                    if (iVar6 < 0) goto LAB_653291;
                                    if (*(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0xb0) +
                                                               piVar9[5] * 4) + 0x40) == 0) {
                                        uVar11 = *(uint32_t*)(uintptr_t)(in_ECX + 0x20);
                                    }
                                    else {
                                        uVar11 = *(uint32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0x38) + 0x10);
                                    }
                                    iVar6 = FUN_0063ec91(uVar11, &local_20, &local_1c);
                                    piVar9[3] = iVar6;
                                    piVar9[0x12] = 0;
                                    iVar6 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0xb0) +
                                                       piVar9[5] * 4);
                                    if (*(int32_t*)(uintptr_t)(iVar6 + 0x40) == 0) {
                                        iVar14 = *(int32_t*)(uintptr_t)(in_ECX + 0x20);
                                    }
                                    else {
                                        iVar14 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0x38) + 0x10);
                                    }
                                    local_8 = *(int32_t*)(uintptr_t)(iVar6 + 0x2c) + iVar14 + piVar9[6];
                                    iVar6 = *(int32_t*)(uintptr_t)(local_8 + 0x10);
                                    piVar9[0x13] = iVar6;
                                    if (iVar6 == 0) {
                                        piVar9[0x13] = 1;
                                    }
                                    iVar6 = FUN_006440fa(piVar9, &local_14, &local_10, &local_c);
                                    if (iVar6 < 0) goto LAB_653291;
                                    *piVar9 = *(int32_t*)(uintptr_t)(in_ECX + 0x20) + piVar9[0xc];
                                    piVar9[1] = piVar9[0xb] + *(int32_t*)(uintptr_t)(in_ECX + 0x20);
                                    piVar9 = *(int32_t**)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0x9c) + 0x3c +
                                                          local_30);
                                    while ((param_1 = param_1 + 1, piVar9 != (int32_t*)0 &&
                                            (uVar7 = param_1 & 0xffff,
                                             uVar7 < *(uint32_t*)(uintptr_t)(in_ECX + 0xa8)))) {
                                        *(int32_t**)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0xb0) + uVar7 * 4) = piVar9;
                                        piVar9[5] = (int32_t)uVar7;
                                        iVar6 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0xb0) + uVar7 * 4);
                                        if (*(int32_t*)(uintptr_t)(iVar6 + 0x40) == 0) {
                                            local_2c = *(uint32_t*)(uintptr_t)(in_ECX + 0x20);
                                        }
                                        else {
                                            local_2c = *(uint32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0x38) +
                                                                    0x10);
                                        }
                                        local_8 = piVar9[6] + *(int32_t*)(uintptr_t)(iVar6 + 0x2c) + local_2c;
                                        iVar6 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0xb0) +
                                                           piVar9[5] * 4);
                                        if (*(int32_t*)(uintptr_t)(iVar6 + 0x40) == 0) {
                                            local_18 = *(int32_t*)(uintptr_t)(in_ECX + 0x20);
                                        }
                                        else {
                                            local_18 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0x38) +
                                                                   0x10);
                                        }
                                        local_18 = piVar9[7] + *(int32_t*)(uintptr_t)(iVar6 + 0x30) + local_18;
                                        local_20 = (uint32_t)piVar9[0xb];
                                        local_1c = piVar9[0xc];
                                        iVar6 = FUN_006440fa(piVar9, &local_14, &local_10, &local_c);
                                        if (iVar6 < 0) goto LAB_653291;
                                        *piVar9 = *(int32_t*)(uintptr_t)(in_ECX + 0x20) + piVar9[0xc];
                                        piVar9[1] = piVar9[0xb] + *(int32_t*)(uintptr_t)(in_ECX + 0x20);
                                        uVar2 = *(uint16_t*)(uintptr_t)(in_ECX + 0x30);
                                        *(uint16_t*)(uintptr_t)((int32_t)piVar9 + 0x46) = 0;
                                        *(uint16_t*)(uintptr_t)(piVar9 + 0x11) = uVar2;
                                        iVar6 = FUN_006480e4(&local_8, &local_18, uVar7);
                                        if (iVar6 < 0) goto LAB_653291;
                                        if (*(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0xb0) +
                                                                   piVar9[5] * 4) + 0x40) == 0) {
                                            uVar11 = *(uint32_t*)(uintptr_t)(in_ECX + 0x20);
                                        }
                                        else {
                                            uVar11 = *(uint32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0x38) + 0x10);
                                        }
                                        iVar6 = FUN_0063ec91(uVar11, &local_20, &local_1c);
                                        piVar9[3] = iVar6;
                                        piVar9 = (int32_t*)piVar9[0xf];
                                    }
                                    param_2 = (uint32_t*)(uintptr_t)((int32_t)param_2 + 1);
                                } while (((uint32_t)param_2 & 0xffff) <
                                         *(uint32_t*)(uintptr_t)(in_ECX + 0x98));
                            }
                            uVar7 = 0;
                            param_2 = (uint32_t*)0;
                            if (*(int32_t*)(uintptr_t)(in_ECX + 0xa0) != 0) {
                                do {
                                    local_28 = uVar7 * 0xb4 + *(int32_t*)(uintptr_t)(in_ECX + 0xa4);
                                    piVar9 = *(int32_t**)(uintptr_t)(local_28 + 0x30);
                                    while ((piVar9 != (int32_t*)0 &&
                                            (uVar7 = param_1 & 0xffff,
                                             uVar7 < *(uint32_t*)(uintptr_t)(in_ECX + 0xa8)))) {
                                        *(int32_t**)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0xb0) + uVar7 * 4) = piVar9;
                                        piVar9[5] = (int32_t)uVar7;
                                        iVar6 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0xb0) + uVar7 * 4);
                                        if (*(int32_t*)(uintptr_t)(iVar6 + 0x40) == 0) {
                                            local_1c = *(int32_t*)(uintptr_t)(in_ECX + 0x20);
                                        }
                                        else {
                                            local_1c = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0x38) + 0x10);
                                        }
                                        local_1c = piVar9[6] + *(int32_t*)(uintptr_t)(iVar6 + 0x2c) + local_1c;
                                        iVar6 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0xb0) +
                                                           piVar9[5] * 4);
                                        if (*(int32_t*)(uintptr_t)(iVar6 + 0x40) == 0) {
                                            iVar14 = *(int32_t*)(uintptr_t)(in_ECX + 0x20);
                                        }
                                        else {
                                            iVar14 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0x38) + 0x10);
                                        }
                                        local_20 = (uint32_t)(piVar9[7] + *(int32_t*)(uintptr_t)(iVar6 + 0x30) +
                                                              iVar14);
                                        local_8 = (int32_t)piVar9[0xb];
                                        local_18 = piVar9[0xc];
                                        iVar6 = FUN_006440fa(piVar9, &local_14, &local_10, &local_c);
                                        if (iVar6 < 0) goto LAB_653291;
                                        *piVar9 = piVar9[0xc] + *(int32_t*)(uintptr_t)(in_ECX + 0x20);
                                        piVar9[1] = *(int32_t*)(uintptr_t)(in_ECX + 0x20) + piVar9[0xb];
                                        uVar2 = *(uint16_t*)(uintptr_t)(in_ECX + 0x30);
                                        *(uint16_t*)(uintptr_t)((int32_t)piVar9 + 0x46) = 0;
                                        *(uint16_t*)(uintptr_t)(piVar9 + 0x11) = uVar2;
                                        iVar6 = FUN_006480e4(&local_1c, &local_20, uVar7);
                                        if (iVar6 < 0) goto LAB_653291;
                                        if (*(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0xb0) +
                                                                   piVar9[5] * 4) + 0x40) == 0) {
                                            uVar11 = *(uint32_t*)(uintptr_t)(in_ECX + 0x20);
                                        }
                                        else {
                                            uVar11 = *(uint32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0x38) + 0x10);
                                        }
                                        iVar6 = FUN_0063ec91(uVar11, &local_8, &local_18);
                                        param_1 = param_1 + 1;
                                        piVar9[3] = iVar6;
                                        piVar9 = (int32_t*)piVar9[0xf];
                                    }
                                    local_2c = 0;
                                    if (*(int32_t*)(uintptr_t)(local_28 + 0x34) != 0) {
                                        local_24 = 0;
                                        do {
                                            piVar9 = *(int32_t**)(uintptr_t)(local_24 + 0x30 +
                                                                  *(int32_t*)(uintptr_t)(local_28 + 0x38));
                                            while ((piVar9 != (int32_t*)0 &&
                                                    (uVar7 = param_1 & 0xffff,
                                                     uVar7 < *(uint32_t*)(uintptr_t)(in_ECX + 0xa8)))) {
                                                *(int32_t**)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0xb0) + uVar7 * 4) =
                                                    piVar9;
                                                piVar9[5] = (int32_t)uVar7;
                                                iVar6 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0xb0) +
                                                                   uVar7 * 4);
                                                if (*(int32_t*)(uintptr_t)(iVar6 + 0x40) == 0) {
                                                    local_30 = *(uint32_t*)(uintptr_t)(in_ECX + 0x20);
                                                }
                                                else {
                                                    local_30 = *(uint32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0x38) +
                                                                           0x10);
                                                }
                                                local_1c = piVar9[6] + *(int32_t*)(uintptr_t)(iVar6 + 0x2c) +
                                                           (int32_t)local_30;
                                                iVar6 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0xb0) +
                                                                   piVar9[5] * 4);
                                                if (*(int32_t*)(uintptr_t)(iVar6 + 0x40) == 0) {
                                                    iVar14 = *(int32_t*)(uintptr_t)(in_ECX + 0x20);
                                                }
                                                else {
                                                    iVar14 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(in_ECX + 0x38) +
                                                                         0x10);
                                                }
                                                local_20 = (uint32_t)(*(int32_t*)(uintptr_t)(iVar6 + 0x30) +
                                                                      piVar9[7] + iVar14);
                                                local_8 = (int32_t)piVar9[0xb];
                                                local_18 = piVar9[0xc];
                                                iVar6 = FUN_006440fa(piVar9, &local_14, &local_10,
                                                                     &local_c);
                                                if (iVar6 < 0) goto LAB_653291;
                                                *piVar9 = piVar9[0xc] + *(int32_t*)(uintptr_t)(in_ECX + 0x20);
                                                piVar9[1] = *(int32_t*)(uintptr_t)(in_ECX + 0x20) + piVar9[0xb];
                                                uVar2 = *(uint16_t*)(uintptr_t)(in_ECX + 0x30);
                                                *(uint16_t*)(uintptr_t)((int32_t)piVar9 + 0x46) = 0;
                                                *(uint16_t*)(uintptr_t)(piVar9 + 0x11) = uVar2;
                                                iVar6 = FUN_006480e4(&local_1c, &local_20, uVar7);
                                                if (iVar6 < 0) goto LAB_653291;
                                                if (*(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(*(int32_t*)
                                                                           (in_ECX + 0xb0) +
                                                                           piVar9[5] * 4) + 0x40) ==
                                                    0) {
                                                    uVar11 = *(uint32_t*)(uintptr_t)(in_ECX + 0x20);
                                                }
                                                else {
                                                    uVar11 = *(uint32_t*)(uintptr_t)(*(int32_t*)
                                                                          (in_ECX + 0x38) + 0x10);
                                                }
                                                iVar6 = FUN_0063ec91(uVar11, &local_8, &local_18);
                                                param_1 = param_1 + 1;
                                                piVar9[3] = iVar6;
                                                piVar9 = (int32_t*)piVar9[0xf];
                                            }
                                            local_2c = local_2c + 1;
                                            local_24 = local_24 + 0x38;
                                        } while (local_2c < *(uint32_t*)(uintptr_t)(local_28 + 0x34));
                                    }
                                    param_2 = (uint32_t*)(uintptr_t)((int32_t)param_2 + 1);
                                    uVar7 = (uint32_t)param_2 & 0xffff;
                                } while (uVar7 < *(uint32_t*)(uintptr_t)(in_ECX + 0xa0));
                            }
                            if ((param_1 & 0xffff) == *(uint32_t*)(uintptr_t)(in_ECX + 0xa8)) {
                                param_1 = *param_4;
                                uVar7 = (**(code**)(*param_3 + 0x10))(param_3);
                                if (param_1 + 1 <= uVar7) {
                                    param_1 = *param_4;
                                    iVar6 = (**(code**)(*param_3 + 0xc))(param_3);
                                    param_4 = *(uint32_t**)(uintptr_t)(iVar6 + param_1 * 4);
                                }
                                *puVar5 = param_1 + 1;
                                uVar7 = (**(code**)(*param_3 + 0x10))(param_3);
                                uVar8 = param_1 + 2;
                                param_1 = param_1 + 1;
                                if (uVar8 <= uVar7) {
                                    param_1 = *puVar5;
                                    iVar6 = (**(code**)(*param_3 + 0xc))(param_3);
                                    local_24 = *(uint32_t*)(uintptr_t)(iVar6 + param_1 * 4);
                                }
                                *puVar5 = param_1 + 1;
                                uVar7 = (**(code**)(*param_3 + 0x10))(param_3);
                                if (*puVar5 <= uVar7) {
                                    iVar6 = 0;
                                    param_2 = (uint32_t*)0;
                                    if (param_4 != (uint32_t*)0) {
                                        do {
                                            iVar6 = FUN_0063e68a(param_3, puVar5);
                                            if (iVar6 < 0) goto LAB_653291;
                                            param_2 = (uint32_t*)(uintptr_t)((int32_t)param_2 + 1);
                                        } while (param_2 < param_4);
                                    }
                                    param_2 = (uint32_t*)0;
                                    if (local_24 != 0) {
                                        do {
                                            param_1 = *puVar5;
                                            uVar7 = (**(code**)(*param_3 + 0x10))(param_3);
                                            if (param_1 + 1 <= uVar7) {
                                                param_1 = *puVar5;
                                                iVar6 = (**(code**)(*param_3 + 0xc))(param_3);
                                                local_20 = *(uint32_t*)(uintptr_t)(iVar6 + param_1 * 4);
                                            }
                                            *puVar5 = param_1 + 1;
                                            uVar7 = (**(code**)(*param_3 + 0x10))(param_3);
                                            uVar8 = param_1 + 2;
                                            param_1 = param_1 + 1;
                                            if (uVar8 <= uVar7) {
                                                param_1 = *puVar5;
                                                iVar6 = (**(code**)(*param_3 + 0xc))(param_3);
                                                local_30 = *(uint32_t*)(uintptr_t)(iVar6 + param_1 * 4);
                                            }
                                            *puVar5 = param_1 + 1;
                                            uVar7 = (**(code**)(*param_3 + 0x10))(param_3);
                                            uVar8 = param_1 + 2;
                                            param_1 = param_1 + 1;
                                            if (uVar8 <= uVar7) {
                                                param_1 = *puVar5;
                                                iVar6 = (**(code**)(*param_3 + 0xc))(param_3);
                                                local_28 = *(uint32_t*)(uintptr_t)(iVar6 + param_1 * 4);
                                            }
                                            *puVar5 = param_1 + 1;
                                            uVar7 = (**(code**)(*param_3 + 0x10))(param_3);
                                            uVar8 = param_1 + 2;
                                            param_1 = param_1 + 1;
                                            if (uVar8 <= uVar7) {
                                                param_1 = *puVar5;
                                                iVar6 = (**(code**)(*param_3 + 0xc))(param_3);
                                                param_4 = *(uint32_t**)(uintptr_t)(iVar6 + param_1 * 4);
                                            }
                                            *puVar5 = param_1 + 1;
                                            uVar7 = (**(code**)(*param_3 + 0x10))(param_3);
                                            uVar8 = param_1 + 2;
                                            param_1 = param_1 + 1;
                                            if (uVar8 <= uVar7) {
                                                param_1 = *puVar5;
                                                iVar6 = (**(code**)(*param_3 + 0xc))(param_3);
                                                local_2c = *(uint32_t*)(uintptr_t)(iVar6 + param_1 * 4);
                                            }
                                            *puVar5 = param_1 + 1;
                                            uVar7 = (**(code**)(*param_3 + 0x10))(param_3);
                                            if (uVar7 < *puVar5) goto LAB_653039;
                                            if (local_20 == 0xffffffff) {
                                                if ((*(uint32_t*)(uintptr_t)(in_ECX + 0x98) <= local_30) ||
                                                    (iVar6 = (int32_t)local_30 * 0x50 +
                                                             *(int32_t*)(uintptr_t)(in_ECX + 0x9c),
                                                     *(uint16_t*)(uintptr_t)(iVar6 + 0x46) <= local_28))
                                                    goto LAB_653039;
                                                uVar7 = local_28 + *(uint16_t*)(uintptr_t)(iVar6 + 0x44);
                                            }
                                            else {
                                                if (((*(uint32_t*)(uintptr_t)(in_ECX + 0xa0) <= local_20) ||
                                                     (iVar6 = (int32_t)local_20 * 0xb4 +
                                                              *(int32_t*)(uintptr_t)(in_ECX + 0xa4),
                                                      *(uint32_t*)(uintptr_t)(iVar6 + 0x34) <= local_30)) ||
                                                    (local_28 != 0xffffffff))
                                                    goto LAB_653039;
                                                uVar7 = (uint32_t)*(uint16_t*)
                                                        (*(int32_t*)(uintptr_t)(iVar6 + 0x38) + 0x34 +
                                                         local_30 * 0x38);
                                            }
                                            if ((uint32_t)*(uint16_t*)
                                                (uVar7 * 100 + 0x36 +
                                                 *(int32_t*)(uintptr_t)(in_ECX + 0x2c)) <=
                                                (uint32_t)(uintptr_t)param_4)
                                                goto LAB_653039;
                                            iVar6 = *(int32_t*)(uintptr_t)(&DAT_006eac9c +
                                                     (uint32_t)*(uint16_t*)
                                                     (*(int32_t*)(uintptr_t)(uVar7 * 100 + 4 +
                                                                  *(int32_t*)(uintptr_t)(in_ECX + 0x2c)) +
                                                      0x52 + (int32_t)param_4 * 100) * 0x1c);
                                            if ((iVar6 == 5) || (iVar6 == 10)) {
                                                if (local_2c == 1) {
LAB_652f1c:
                                                    iVar6 = FUN_0064efd7(uVar7, param_4, param_3,
                                                                         puVar5);
                                                }
                                                else {
                                                    iVar6 = (int32_t)0x80004005;
                                                }
                                            }
                                            else if ((iVar6 < 0xf) || (0x10 < iVar6)) {
                                                iVar6 = FUN_00644699(uVar7, param_4, param_3,
                                                                     puVar5);
                                            }
                                            else if (local_2c == 0) {
                                                iVar6 = FUN_00647e66(uVar7, param_4, param_3,
                                                                     puVar5);
                                            }
                                            else {
                                                if (local_2c == 1) goto LAB_652f1c;
                                                iVar6 = FUN_0064f29e(uVar7, param_4, param_3,
                                                                     puVar5);
                                            }
                                            if (iVar6 < 0) goto LAB_653291;
                                            param_2 = (uint32_t*)(uintptr_t)((int32_t)param_2 + 1);
                                        } while ((uint32_t)(uintptr_t)param_2 < local_24);
                                    }
                                    uVar7 = 0;
                                    if ((*(int32_t*)(uintptr_t)(in_ECX + 0x38) != 0) &&
                                        (uVar8 = 0, *(int32_t*)(uintptr_t)(in_ECX + 0x98) != 0)) {
                                        do {
                                            iVar14 = uVar7 * 0x50 + *(int32_t*)(uintptr_t)(in_ECX + 0x9c);
                                            if (((*(uint32_t*)(uintptr_t)(*(int32_t*)
                                                               (*(int32_t*)(uintptr_t)(in_ECX + 0xb0) +
                                                                *(int32_t*)(uintptr_t)(iVar14 + 0x14) * 4) +
                                                               0x28) & 1) != 0) &&
                                                (iVar6 = FUN_0062a1a7(in_ECX, iVar14), iVar6 < 0))
                                                goto LAB_653291;
                                            uVar8 = uVar8 + 1;
                                            uVar7 = uVar8 & 0xffff;
                                        } while (uVar7 < *(uint32_t*)(uintptr_t)(in_ECX + 0x98));
                                    }
                                    uVar1 = 0;
                                    if (*(int16_t*)(uintptr_t)(in_ECX + 0x30) != 0) {
                                        do {
                                            piVar9 = (int32_t*)(uintptr_t)((uint32_t)uVar1 * 100 +
                                                                *(int32_t*)(uintptr_t)(in_ECX + 0x2c));
                                            iVar6 = FUN_0063e391();
                                            if (iVar6 < 0) goto LAB_653291;
                                            uVar7 = (uint32_t)piVar9[3];
                                            puVar10 = (uint32_t*)*piVar9;
                                            for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                                                *puVar10 = 0;
                                                puVar10 = puVar10 + 1;
                                            }
                                            for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
                                                *(uint8_t*)puVar10 = 0;
                                                puVar10 = (uint32_t*)(uintptr_t)((int32_t)puVar10 + 1);
                                            }
                                            iVar14 = piVar9[5];
                                            iVar17 = *piVar9;
                                            param_1 = 0;
                                            uVar4 = 0;
                                            if (*(int16_t*)(uintptr_t)((int32_t)piVar9 + 0x36) != 0) {
                                                do {
                                                    iVar12 = (uint32_t)uVar4 * 100 + piVar9[1];
                                                    iVar15 = *(int32_t*)(uintptr_t)(iVar12 + 0x1c) * 4;
                                                    iVar13 = *(int32_t*)(uintptr_t)(iVar15 +
                                                                         *(int32_t*)(uintptr_t)(in_ECX + 0xb0));
                                                    if (*(int32_t*)(uintptr_t)(iVar13 + 0x40) == 0) {
                                                        iVar20 = *(int32_t*)(uintptr_t)(in_ECX + 0x20);
                                                    }
                                                    else {
                                                        iVar20 = *(int32_t*)
                                                                 (*(int32_t*)(uintptr_t)(in_ECX + 0x38) + 0x10);
                                                    }
                                                    *(int32_t*)(uintptr_t)(iVar12 + 8) =
                                                        *(int32_t*)(uintptr_t)(iVar13 + 0x30) +
                                                        *(int32_t*)(uintptr_t)(iVar12 + 0x24) + iVar20;
                                                    iVar13 = *(int32_t*)(uintptr_t)(iVar15 +
                                                                         *(int32_t*)(uintptr_t)(in_ECX + 0xb0));
                                                    if (*(int32_t*)(uintptr_t)(iVar13 + 0x40) == 0) {
                                                        iVar15 = *(int32_t*)(uintptr_t)(in_ECX + 0x20);
                                                    }
                                                    else {
                                                        iVar15 = *(int32_t*)
                                                                 (*(int32_t*)(uintptr_t)(in_ECX + 0x38) + 0x10);
                                                    }
                                                    *(int32_t*)(uintptr_t)(iVar12 + 0xc) =
                                                        *(int32_t*)(uintptr_t)(iVar13 + 0x2c) +
                                                        *(int32_t*)(uintptr_t)(iVar12 + 0x20) + iVar15;
                                                    if ((*(int32_t*)(uintptr_t)(&DAT_006eacac +
                                                          (uint32_t)*(uint16_t*)(uintptr_t)(iVar12 + 0x52) *
                                                          0x1c) == 0xe000000) ||
                                                        (*(int32_t*)(uintptr_t)(&DAT_006eacac +
                                                          (uint32_t)*(uint16_t*)(uintptr_t)(iVar12 + 0x52) *
                                                          0x1c) == 0xf000000)) {
                                                        uVar7 = param_1 & 0xffff;
                                                        param_1 = param_1 + 1;
                                                        *(uint16_t*)(uintptr_t)(iVar14 + iVar17 + uVar7 * 2) =
                                                            uVar4;
                                                        psVar16 = (int16_t*)
                                                                  (*(int32_t*)(uintptr_t)(iVar12 + 0x48) +
                                                                   *piVar9);
                                                        if (*(int32_t*)(uintptr_t)(iVar12 + 0x1c) == 0) {
                                                            iVar13 = **(int32_t**)
                                                                      (in_ECX + 0xb0);
                                                            if (*(int32_t*)(uintptr_t)(iVar13 + 0x40) == 0) {
                                                                iVar13 = *(int32_t*)
                                                                         (*(int32_t*)(uintptr_t)(iVar13 + 0x30) +
                                                                          *(int32_t*)(uintptr_t)(iVar12 + 0x24) +
                                                                          *(int32_t*)(uintptr_t)(in_ECX + 0x20));
                                                            }
                                                            else {
                                                                iVar13 = **(int32_t**)
                                                                          (in_ECX + 0xb0);
                                                                iVar13 = *(int32_t*)
                                                                         (*(int32_t*)
                                                                          (*(int32_t*)(uintptr_t)(iVar13 + 0x40) +
                                                                           8) +
                                                                          *(int32_t*)
                                                                          (*(int32_t*)(uintptr_t)(iVar13 + 0x30) +
                                                                           *(int32_t*)(uintptr_t)(iVar12 + 0x24) +
                                                                           *(int32_t*)
                                                                           (*(int32_t*)(uintptr_t)(in_ECX + 0x38) +
                                                                            0x10)) * 4);
                                                            }
                                                            sVar3 = *(int16_t*)
                                                                    (*(int32_t*)(uintptr_t)(in_ECX + 0x18) +
                                                                     0x10 + iVar13 * 0x18);
                                                            psVar16[1] = 0;
                                                            *psVar16 = sVar3 + 1;
                                                        }
                                                        else {
                                                            *psVar16 = *(int16_t*)
                                                                       (*(int32_t*)
                                                                        (*(int32_t*)(uintptr_t)(in_ECX + 0xb0) +
                                                                         *(int32_t*)(uintptr_t)(iVar12 + 0x1c) * 4) +
                                                                        0x44) + 1;
                                                            psVar16[1] = (int16_t)
                                                                         (*(uint32_t*)
                                                                          (iVar12 + 0x24) >> 2);
                                                        }
                                                    }
                                                    uVar4 = uVar4 + 1;
                                                } while (uVar4 < *(uint16_t*)
                                                                   ((int32_t)piVar9 + 0x36));
                                            }
                                            uVar1 = uVar1 + 1;
                                        } while (uVar1 < *(uint16_t*)(uintptr_t)(in_ECX + 0x30));
                                    }
                                    *(uint16_t*)(uintptr_t)(in_ECX + 0x44) = 0xffff;
                                    *(uint16_t*)(uintptr_t)(in_ECX + 0x40) = 0xffff;
                                    *(uint32_t*)(uintptr_t)(in_ECX + 0x118) =
                                        *(uint32_t*)(uintptr_t)(in_ECX + 0x118) | 0x40;
                                    uVar7 = 0;
                                    *(uint32_t*)(uintptr_t)(in_ECX + 0x3c) = 0;
                                    *(uint16_t*)(uintptr_t)(in_ECX + 0x42) = 0;
                                    if (*(int32_t*)(uintptr_t)(in_ECX + 0x98) != 0) {
                                        uVar8 = 0;
                                        do {
                                            iVar17 = uVar8 * 0x50 + *(int32_t*)(uintptr_t)(in_ECX + 0x9c);
                                            iVar14 = **(int32_t**)(uintptr_t)(iVar17 + 4);
                                            if (((iVar14 < 10) || (0xe < iVar14)) &&
                                                (iVar6 = FUN_0063d772(iVar17), iVar6 < 0))
                                                goto LAB_653291;
                                            uVar7 = uVar7 + 1;
                                            uVar8 = uVar7 & 0xffff;
                                        } while (uVar8 < *(uint32_t*)(uintptr_t)(in_ECX + 0x98));
                                    }
                                    uVar1 = 0;
                                    if (*(int32_t*)(uintptr_t)(in_ECX + 0xa8) != 0) {
                                        uVar7 = 0;
                                        do {
                                            piVar9 = *(int32_t**)
                                                     (*(int32_t*)(uintptr_t)(in_ECX + 0xb0) + uVar7 * 4);
                                            iVar14 = *(int32_t*)
                                                     (piVar9[5] * 4 + *(int32_t*)(uintptr_t)(in_ECX + 0xb0));
                                            if (*(int32_t*)(uintptr_t)(iVar14 + 0x40) == 0) {
                                                iVar17 = *(int32_t*)(uintptr_t)(in_ECX + 0x20);
                                            }
                                            else {
                                                iVar17 = *(int32_t*)
                                                         (*(int32_t*)(uintptr_t)(in_ECX + 0x38) + 0x10);
                                            }
                                            *piVar9 = piVar9[7] + *(int32_t*)(uintptr_t)(iVar14 + 0x30) + iVar17;
                                            iVar14 = *(int32_t*)
                                                     (piVar9[5] * 4 + *(int32_t*)(uintptr_t)(in_ECX + 0xb0));
                                            if (*(int32_t*)(uintptr_t)(iVar14 + 0x40) == 0) {
                                                iVar17 = *(int32_t*)(uintptr_t)(in_ECX + 0x20);
                                            }
                                            else {
                                                iVar17 = *(int32_t*)
                                                         (*(int32_t*)(uintptr_t)(in_ECX + 0x38) + 0x10);
                                            }
                                            iVar17 = piVar9[6] + *(int32_t*)(uintptr_t)(iVar14 + 0x2c) + iVar17;
                                            while (true) {
                                                piVar9[1] = iVar17;
                                                piVar9 = (int32_t*)piVar9[9];
                                                if (piVar9 == (int32_t*)0) break;
                                                iVar14 = *(int32_t*)
                                                         (piVar9[5] * 4 +
                                                          *(int32_t*)(uintptr_t)(in_ECX + 0xb0));
                                                if (*(int32_t*)(uintptr_t)(iVar14 + 0x40) == 0) {
                                                    iVar17 = *(int32_t*)(uintptr_t)(in_ECX + 0x20);
                                                }
                                                else {
                                                    iVar17 = *(int32_t*)
                                                             (*(int32_t*)(uintptr_t)(in_ECX + 0x38) + 0x10);
                                                }
                                                *piVar9 = piVar9[7] + *(int32_t*)(uintptr_t)(iVar14 + 0x30) +
                                                          iVar17;
                                                iVar14 = *(int32_t*)
                                                         (piVar9[5] * 4 +
                                                          *(int32_t*)(uintptr_t)(in_ECX + 0xb0));
                                                if (*(int32_t*)(uintptr_t)(iVar14 + 0x40) == 0) {
                                                    iVar17 = *(int32_t*)(uintptr_t)(in_ECX + 0x20);
                                                }
                                                else {
                                                    iVar17 = *(int32_t*)
                                                             (*(int32_t*)(uintptr_t)(in_ECX + 0x38) + 0x10);
                                                }
                                                iVar17 = piVar9[6] + *(int32_t*)(uintptr_t)(iVar14 + 0x2c) +
                                                          iVar17;
                                            }
                                            uVar1 = uVar1 + 1;
                                            uVar7 = (uint32_t)uVar1;
                                        } while (uVar7 < *(uint32_t*)(uintptr_t)(in_ECX + 0xa8));
                                    }
                                    goto LAB_653291;
                                }
                            }
                            goto LAB_653039;
                        }
                    }
                }
            }
        }
    }
LAB_652329:
    iVar6 = (int32_t)0x8007000e;
    goto LAB_653291;
LAB_653039:
    iVar6 = (int32_t)0x80004005;
LAB_653291:
    *(uint32_t*)(uintptr_t)(in_ECX + 0xac) = *(uint32_t*)(uintptr_t)(in_ECX + 0xa8);
    return iVar6;
}

// 0x6532a4 — observed shape
// Factory: allocates a 0x130 object, either deep-loads it through FUN_6522f5 and
// clones the 0xb4/0x18 sub-tables, or only reloads the blob, then rebuilds the
// sprite/dispatch lists with FUN_00644bfc / FUN_0063ef70.
// Receiver of the nested FUN_6522f5 call is the new 0x130 object (in_ECX).
int32_t FUN_6532a4(uint32_t param_1, int32_t param_2, uint32_t* param_3)
{
    uint32_t* puVar1;
    int32_t   iVar2;
    int32_t   iVar3;
    int32_t*  piVar4;
    int32_t*  piVar5;
    int32_t   iVar6;
    int32_t   iVar7;
    int32_t   iVar8;
    uint32_t  uVar9;
    uint32_t* puVar10;
    int32_t*  local_1c;
    uint32_t  local_18;
    int32_t*  local_14;
    int32_t   local_10;
    uint32_t  local_c;
    int32_t   local_8;

    iVar2 = (int32_t)param_1;
    if (param_3 == (uint32_t*)0) {
        return (int32_t)0x8876086c;
    }
    iVar3 = FUN_00533c78(0x130);
    if (iVar3 == 0) {
        piVar4 = (int32_t*)0;
    }
    else {
        piVar4 = (int32_t*)FUN_00647cf7();
    }
    if (piVar4 == (int32_t*)0) {
        return (int32_t)0x8007000e;
    }
    local_18 = 0;
    if (param_2 == *(int32_t*)(uintptr_t)(param_1 + 0xc)) {
        *(uint8_t*)(uintptr_t)((int32_t)piVar4 + 0x119) = *(uint8_t*)(uintptr_t)((int32_t)piVar4 + 0x119) | 2;
        param_2 = FUN_6522f5(piVar4, (uint32_t)param_2, *(uint32_t**)(uintptr_t)(param_1 + 0x38),
                             *(int32_t**)(uintptr_t)(param_1 + 0x28), &local_18);
        if (param_2 < 0) goto LAB_6539e7;
        *(uint8_t*)(uintptr_t)((int32_t)piVar4 + 0x119) = *(uint8_t*)(uintptr_t)((int32_t)piVar4 + 0x119) & 0xfd;
        param_2 = FUN_0063e58b();
        if (param_2 < 0) goto LAB_6539e7;
        *param_3 = 0;
        local_c = 0;
        if (*(int32_t*)(uintptr_t)(param_1 + 0xa0) != 0) {
            param_1 = 0;
            uVar9 = local_18;
            do {
                local_18 = uVar9;
                if (*(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar2 + 0xa4) + 0x88 + param_1) != 0) {
                    *(uint32_t*)(uintptr_t)(piVar4[0x29] + 0x88 + (int32_t)param_1) =
                        *(uint32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar2 + 0xa4) + 0x88 + param_1);
                    piVar5 = *(int32_t**)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar2 + 0xa4) + 0x88 + param_1);
                    (**(code**)(*piVar5 + 4))(piVar5);
                }
                iVar3 = (int32_t)param_1 + 0x8c;
                local_18 = 2;
                do {
                    if (*(int32_t*)(uintptr_t)(iVar3 + *(int32_t*)(uintptr_t)(iVar2 + 0xa4)) != 0) {
                        *(uint32_t*)(uintptr_t)(iVar3 + piVar4[0x29]) =
                            *(uint32_t*)(uintptr_t)(iVar3 + *(int32_t*)(uintptr_t)(iVar2 + 0xa4));
                        piVar5 = *(int32_t**)(uintptr_t)(iVar3 + *(int32_t*)(uintptr_t)(iVar2 + 0xa4));
                        (**(code**)(*piVar5 + 4))(piVar5);
                    }
                    iVar3 = iVar3 + 4;
                    local_18 = local_18 - 1;
                } while (local_18 != 0);
                iVar3 = (int32_t)param_1 + 0x94;
                local_18 = 2;
                do {
                    if (*(int32_t*)(uintptr_t)(iVar3 + *(int32_t*)(uintptr_t)(iVar2 + 0xa4)) != 0) {
                        *(uint32_t*)(uintptr_t)(iVar3 + piVar4[0x29]) =
                            *(uint32_t*)(uintptr_t)(iVar3 + *(int32_t*)(uintptr_t)(iVar2 + 0xa4));
                        piVar5 = *(int32_t**)(uintptr_t)(iVar3 + *(int32_t*)(uintptr_t)(iVar2 + 0xa4));
                        (**(code**)(*piVar5 + 4))(piVar5);
                    }
                    iVar3 = iVar3 + 4;
                    local_18 = local_18 - 1;
                } while (local_18 != 0);
                local_c = local_c + 1;
                param_1 = (uint32_t)((int32_t)param_1 + 0xb4);
                local_18 = 0;
                uVar9 = 0;
            } while (local_c < *(uint32_t*)(uintptr_t)(iVar2 + 0xa0));
        }
        param_1 = 0;
        if (*(int32_t*)(uintptr_t)(iVar2 + 0x14) != 0) {
            iVar3 = 0;
            do {
                piVar5 = (int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar2 + 0x18) + iVar3);
                if (*piVar5 == 0xf) {
                    if (piVar5[1] != 0) {
                        piVar5 = *(int32_t**)(uintptr_t)(iVar3 + 4 + *(int32_t*)(uintptr_t)(iVar2 + 0x18));
                        (**(code**)(*piVar5 + 4))(piVar5);
                    }
                    piVar5 = (int32_t*)(uintptr_t)(piVar4[6] + 4 + iVar3);
                    if (*piVar5 != 0) {
                        piVar5 = (int32_t*)*piVar5;
                        (**(code**)(*piVar5 + 8))(piVar5);
                        *(uint32_t*)(uintptr_t)(piVar4[6] + 4 + iVar3) = 0;
                    }
                    *(uint32_t*)(uintptr_t)(piVar4[6] + 4 + iVar3) =
                        *(uint32_t*)(uintptr_t)(iVar3 + 4 + *(int32_t*)(uintptr_t)(iVar2 + 0x18));
                    puVar1 = (uint32_t*)(uintptr_t)(piVar4[6] + 0x14 + iVar3);
                    *puVar1 = *puVar1 ^
                              ((*(int32_t*)(uintptr_t)(iVar3 + 0x14 + *(int32_t*)(uintptr_t)(iVar2 + 0x18)) << 0x1e) >>
                               0x1e ^ *puVar1) & 2;
                    puVar1 = (uint32_t*)(uintptr_t)(piVar4[6] + 0x14 + iVar3);
                    *puVar1 = *puVar1 | 1;
                }
                piVar5 = (int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar2 + 0x18) + iVar3);
                if (*piVar5 == 0x10) {
                    if (piVar5[1] != 0) {
                        piVar5 = *(int32_t**)(uintptr_t)(iVar3 + 4 + *(int32_t*)(uintptr_t)(iVar2 + 0x18));
                        (**(code**)(*piVar5 + 4))(piVar5);
                    }
                    piVar5 = (int32_t*)(uintptr_t)(piVar4[6] + 4 + iVar3);
                    if (*piVar5 != 0) {
                        piVar5 = (int32_t*)*piVar5;
                        (**(code**)(*piVar5 + 8))(piVar5);
                        *(uint32_t*)(uintptr_t)(piVar4[6] + 4 + iVar3) = 0;
                    }
                    *(uint32_t*)(uintptr_t)(piVar4[6] + 4 + iVar3) =
                        *(uint32_t*)(uintptr_t)(iVar3 + 4 + *(int32_t*)(uintptr_t)(iVar2 + 0x18));
                    puVar1 = (uint32_t*)(uintptr_t)(piVar4[6] + 0x14 + iVar3);
                    *puVar1 = *puVar1 ^
                              ((*(int32_t*)(uintptr_t)(iVar3 + 0x14 + *(int32_t*)(uintptr_t)(iVar2 + 0x18)) << 0x1e) >>
                               0x1e ^ *puVar1) & 2;
                    puVar1 = (uint32_t*)(uintptr_t)(piVar4[6] + 0x14 + iVar3);
                    *puVar1 = *puVar1 | 1;
                }
                param_1 = param_1 + 1;
                iVar3 = iVar3 + 0x18;
            } while (param_1 < *(uint32_t*)(uintptr_t)(iVar2 + 0x14));
        }
        piVar5 = (int32_t*)(uintptr_t)(iVar2 + 0x104);
        piVar4[0x41] = *piVar5;
        if (*piVar5 != 0) {
            (**(code**)(*(int32_t*)*piVar5 + 4))((int32_t*)*piVar5);
        }
        FUN_0064dc3f(piVar4);
        iVar3 = 0;
        uVar9 = 0;
        if (*(int32_t*)(uintptr_t)(iVar2 + 0x14) != 0) {
            do {
                piVar5 = (int32_t*)(uintptr_t)(iVar3 + *(int32_t*)(uintptr_t)(iVar2 + 0x18));
                if (*piVar5 == 0xf) {
                    puVar1 = (uint32_t*)(uintptr_t)(piVar4[6] + 0x14 + iVar3);
                    *puVar1 = *puVar1 ^ ((piVar5[5] << 0x1e) >> 0x1e ^ *puVar1) & 2;
                }
                piVar5 = (int32_t*)(uintptr_t)(iVar3 + *(int32_t*)(uintptr_t)(iVar2 + 0x18));
                if (*piVar5 == 0x10) {
                    puVar1 = (uint32_t*)(uintptr_t)(piVar4[6] + 0x14 + iVar3);
                    *puVar1 = *puVar1 ^ ((piVar5[5] << 0x1e) >> 0x1e ^ *puVar1) & 2;
                }
                uVar9 = uVar9 + 1;
                iVar3 = iVar3 + 0x18;
            } while (uVar9 < *(uint32_t*)(uintptr_t)(iVar2 + 0x14));
        }
    }
    else {
        param_2 = FUN_6522f5(piVar4, (uint32_t)param_2, *(uint32_t**)(uintptr_t)(param_1 + 0x38),
                             *(int32_t**)(uintptr_t)(param_1 + 0x28), &local_18);
        if ((param_2 < 0) || (param_2 = FUN_0063e58b(), param_2 < 0)) goto LAB_6539e7;
        FUN_0064dc3f(piVar4);
    }
    local_c = 0;
    if (*(int32_t*)(uintptr_t)(iVar2 + 0x98) != 0) {
        local_8 = 0;
        do {
            puVar10 = (uint32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar2 + 0x9c) + local_8);
            param_1 = (uint32_t)(piVar4[0x27] + local_8);
            local_18 = *(uint32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar2 + 0xb0) + puVar10[5] * 4);
            if (*(int32_t*)(uintptr_t)(local_18 + 0x40) == 0) {
                iVar3 = *(int32_t*)(uintptr_t)(iVar2 + 0x20);
            }
            else {
                iVar3 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar2 + 0x38) + 0x10);
            }
            if (*(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(puVar10[1] + 8) + iVar3) == 0) {
                local_14 = (int32_t*)0;
            }
            else {
                if (*(int32_t*)(uintptr_t)(local_18 + 0x40) == 0) {
                    iVar3 = *(int32_t*)(uintptr_t)(iVar2 + 0x20);
                }
                else {
                    iVar3 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar2 + 0x38) + 0x10);
                }
                local_14 = (int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(puVar10[1] + 8) + 4 + iVar3);
            }
            if ((*(uint32_t*)(uintptr_t)(local_18 + 0x28) & 2) != 0) goto LAB_6536e8;
            iVar3 = *(int32_t*)(uintptr_t)(piVar4[0x2c] + *(int32_t*)(uintptr_t)(param_1 + 0x14) * 4);
            if (*(int32_t*)(uintptr_t)(iVar3 + 0x40) == 0) {
                iVar6 = piVar4[8];
            }
            else {
                iVar6 = *(int32_t*)(uintptr_t)(piVar4[0xe] + 0x10);
            }
            param_2 = FUN_00644bfc(puVar10[1], *(int32_t*)(uintptr_t)(iVar3 + 0x30) +
                                   *(int32_t*)(uintptr_t)(param_1 + 0x1c) + iVar6, *puVar10,
                                   *(uint32_t*)(uintptr_t)(param_1 + 0x40), puVar10[0x10], iVar2);
            if (param_2 < 0) goto LAB_6539e7;
            param_2 = FUN_006431b5((uint32_t*)param_1);
            while (true) {
                if (param_2 < 0) goto LAB_6539e7;
LAB_6536e8:
                puVar10 = (uint32_t*)puVar10[0xf];
                iVar3 = *(int32_t*)(uintptr_t)(param_1 + 0x3c);
                if (iVar3 == 0) break;
                iVar6 = *(int32_t*)(uintptr_t)(piVar4[0x2c] + *(int32_t*)(uintptr_t)(iVar3 + 0x14) * 4);
                if (*(int32_t*)(uintptr_t)(iVar6 + 0x40) == 0) {
                    iVar8 = piVar4[8];
                }
                else {
                    iVar8 = *(int32_t*)(uintptr_t)(piVar4[0xe] + 0x10);
                }
                param_2 = FUN_00644bfc(puVar10[1], *(int32_t*)(uintptr_t)(iVar6 + 0x30) +
                                       *(int32_t*)(uintptr_t)(iVar3 + 0x1c) + iVar8, *puVar10,
                                       *(uint32_t*)(uintptr_t)(iVar3 + 0x40), puVar10[0x10], iVar2);
                param_1 = (uint32_t)iVar3;
            }
            for (; puVar10 != (uint32_t*)0; puVar10 = (uint32_t*)puVar10[0xf]) {
                param_2 = FUN_0063ef70(local_14, puVar10, piVar4);
                if (param_2 < 0) goto LAB_6539e7;
                param_1 = (uint32_t)*(int32_t*)(uintptr_t)(param_1 + 0x3c);
                iVar3 = *(int32_t*)(uintptr_t)(piVar4[0x2c] + *(int32_t*)(uintptr_t)(param_1 + 0x14) * 4);
                if (*(int32_t*)(uintptr_t)(iVar3 + 0x40) == 0) {
                    iVar6 = piVar4[8];
                }
                else {
                    iVar6 = *(int32_t*)(uintptr_t)(piVar4[0xe] + 0x10);
                }
                param_2 = FUN_00644bfc(puVar10[1], *(int32_t*)(uintptr_t)(iVar3 + 0x30) +
                                       *(int32_t*)(uintptr_t)(param_1 + 0x1c) + iVar6, *puVar10,
                                       *(uint32_t*)(uintptr_t)(param_1 + 0x40), puVar10[0x10], iVar2);
                if (param_2 < 0) goto LAB_6539e7;
            }
            local_c = local_c + 1;
            local_8 = local_8 + 0x50;
        } while (local_c < *(uint32_t*)(uintptr_t)(iVar2 + 0x98));
    }
    local_18 = 0;
    if (*(int32_t*)(uintptr_t)(iVar2 + 0xa0) != 0) {
        local_c = 0;
        do {
            iVar3 = *(int32_t*)(uintptr_t)(iVar2 + 0xa4) + (int32_t)local_c;
            local_10 = piVar4[0x29] + (int32_t)local_c;
            local_14 = (int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar3 + 0x28) + *(int32_t*)(uintptr_t)(iVar2 + 0x20));
            if (*local_14 == 0) {
                local_14 = (int32_t*)0;
            }
            else {
                local_14 = local_14 + 1;
            }
            piVar5 = (int32_t*)(uintptr_t)(iVar3 + 0x30);
            puVar10 = (uint32_t*)*piVar5;
            iVar6 = *(int32_t*)(uintptr_t)(local_10 + 0x30);
            while (iVar6 != 0) {
                iVar8 = *(int32_t*)(uintptr_t)(piVar4[0x2c] + *(int32_t*)(uintptr_t)(iVar6 + 0x14) * 4);
                if (*(int32_t*)(uintptr_t)(iVar8 + 0x40) == 0) {
                    iVar7 = piVar4[8];
                }
                else {
                    iVar7 = *(int32_t*)(uintptr_t)(piVar4[0xe] + 0x10);
                }
                param_2 = FUN_00644bfc(puVar10[1], *(int32_t*)(uintptr_t)(iVar8 + 0x30) +
                                       *(int32_t*)(uintptr_t)(iVar6 + 0x1c) + iVar7, *puVar10,
                                       *(uint32_t*)(uintptr_t)(iVar6 + 0x40), puVar10[0x10], iVar2);
                if (param_2 < 0) goto LAB_6539e7;
                puVar10 = (uint32_t*)puVar10[0xf];
                piVar5 = (int32_t*)(uintptr_t)(iVar6 + 0x3c);
                iVar6 = *piVar5;
            }
            param_1 = (uint32_t)*piVar5;
            for (; puVar10 != (uint32_t*)0; puVar10 = (uint32_t*)puVar10[0xf]) {
                param_2 = FUN_0063ef70(local_14, puVar10, piVar4);
                if (param_2 < 0) goto LAB_6539e7;
                param_1 = (uint32_t)*(int32_t*)(uintptr_t)(param_1 + 0x3c);
                iVar6 = *(int32_t*)(uintptr_t)(piVar4[0x2c] + *(int32_t*)(uintptr_t)(param_1 + 0x14) * 4);
                if (*(int32_t*)(uintptr_t)(iVar6 + 0x40) == 0) {
                    iVar8 = piVar4[8];
                }
                else {
                    iVar8 = *(int32_t*)(uintptr_t)(piVar4[0xe] + 0x10);
                }
                param_2 = FUN_00644bfc(puVar10[1], *(int32_t*)(uintptr_t)(iVar6 + 0x30) +
                                       *(int32_t*)(uintptr_t)(param_1 + 0x1c) + iVar8, *puVar10,
                                       *(uint32_t*)(uintptr_t)(param_1 + 0x40), puVar10[0x10], iVar2);
                if (param_2 < 0) goto LAB_6539e7;
            }
            local_14 = (int32_t*)0;
            if (*(int32_t*)(uintptr_t)(local_10 + 0x34) != 0) {
                local_8 = 0;
                do {
                    iVar6 = *(int32_t*)(uintptr_t)(iVar3 + 0x38) + local_8;
                    local_1c = (int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar6 + 0x28) +
                                          *(int32_t*)(uintptr_t)(iVar2 + 0x20));
                    if (*local_1c == 0) {
                        local_1c = (int32_t*)0;
                    }
                    else {
                        local_1c = local_1c + 1;
                    }
                    piVar5 = (int32_t*)(uintptr_t)(iVar6 + 0x30);
                    puVar10 = (uint32_t*)*piVar5;
                    iVar6 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(local_10 + 0x38) + local_8 + 0x30);
                    while (iVar6 != 0) {
                        iVar8 = *(int32_t*)(uintptr_t)(piVar4[0x2c] + *(int32_t*)(uintptr_t)(iVar6 + 0x14) * 4);
                        if (*(int32_t*)(uintptr_t)(iVar8 + 0x40) == 0) {
                            iVar7 = piVar4[8];
                        }
                        else {
                            iVar7 = *(int32_t*)(uintptr_t)(piVar4[0xe] + 0x10);
                        }
                        param_2 = FUN_00644bfc(puVar10[1], *(int32_t*)(uintptr_t)(iVar8 + 0x30) +
                                               *(int32_t*)(uintptr_t)(iVar6 + 0x1c) + iVar7, *puVar10,
                                               *(uint32_t*)(uintptr_t)(iVar6 + 0x40), puVar10[0x10], iVar2);
                        if (param_2 < 0) goto LAB_6539e7;
                        puVar10 = (uint32_t*)puVar10[0xf];
                        piVar5 = (int32_t*)(uintptr_t)(iVar6 + 0x3c);
                        iVar6 = *piVar5;
                    }
                    param_1 = (uint32_t)*piVar5;
                    for (; puVar10 != (uint32_t*)0; puVar10 = (uint32_t*)puVar10[0xf]) {
                        param_2 = FUN_0063ef70(local_1c, puVar10, piVar4);
                        if (param_2 < 0) goto LAB_6539e7;
                        param_1 = (uint32_t)*(int32_t*)(uintptr_t)(param_1 + 0x3c);
                        iVar6 = *(int32_t*)(uintptr_t)(piVar4[0x2c] + *(int32_t*)(uintptr_t)(param_1 + 0x14) * 4);
                        if (*(int32_t*)(uintptr_t)(iVar6 + 0x40) == 0) {
                            iVar8 = piVar4[8];
                        }
                        else {
                            iVar8 = *(int32_t*)(uintptr_t)(piVar4[0xe] + 0x10);
                        }
                        param_2 = FUN_00644bfc(puVar10[1], *(int32_t*)(uintptr_t)(iVar6 + 0x30) +
                                               *(int32_t*)(uintptr_t)(param_1 + 0x1c) + iVar8, *puVar10,
                                               *(uint32_t*)(uintptr_t)(param_1 + 0x40), puVar10[0x10], iVar2);
                        if (param_2 < 0) goto LAB_6539e7;
                    }
                    local_14 = (int32_t*)(uintptr_t)((int32_t)local_14 + 1);
                    local_8 = local_8 + 0x38;
                } while (local_14 < *(int32_t**)(uintptr_t)(local_10 + 0x34));
            }
            local_18 = local_18 + 1;
            local_c = local_c + 0xb4;
        } while (local_18 < *(uint32_t*)(uintptr_t)(iVar2 + 0xa0));
    }
    *param_3 = (uint32_t)(uintptr_t)piVar4;
    piVar4 = (int32_t*)0;
LAB_6539e7:
    if (piVar4 != (int32_t*)0) {
        (**(code**)(*piVar4 + 8))(piVar4);
    }
    return param_2;
}
