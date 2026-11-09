#include <cstdint>
#include <cstddef>
#include <windows.h>

extern int FUN_00628b56(int param_1, void* param_2);
extern int FUN_00628a08(void* param_1, int param_2);
extern int FUN_00628621(void* param_1);
extern int FUN_0062603f(int param_1, void* param_2, void* param_3, uint32_t param_4, int param_5);
extern int FUN_006262de(int param_1, void* param_2, void* param_3, void* param_4, int param_5);

// 0x628e70 — observed shape
int FUN_00628e70(int param_1, int param_2, int param_3)
{
    int iVar1;

    if (param_2 == 0) {
        if (param_3 < 0) {
            param_1 = -param_3;
        } else {
            iVar1 = FUN_00628b56(param_3, &param_1);
            if (iVar1 < 0) {
                return 0;
            }
        }
    } else {
        if (param_2 < 0) {
            param_1 = -param_2;
        } else {
            iVar1 = FUN_00628b56(param_2, &param_1);
            if (iVar1 < 0) {
                return 0;
            }
        }
        param_1 = FUN_00628a08((void*)(intptr_t)param_3, 1);
        if (param_1 == 0) {
            return 0;
        }
    }
    return -param_1;
}

// 0x628ed0 — observed shape
int FUN_00628ed0(void* param_1, int param_2, void* param_3)
{
    (void)param_1;
    int iVar1;

    if (param_2 < 0) {
        param_2 = -param_2;
    } else {
        iVar1 = FUN_00628b56(param_2, &param_2);
        if (iVar1 < 0) {
            return 0;
        }
    }
    iVar1 = FUN_00628621(param_3);
    if (iVar1 == 0) {
        return 0;
    }
    return -iVar1;
}

// 0x628f0d — observed shape
int FUN_00628f0d(void* param_1, void* param_2, int param_3, void* param_4, uint32_t param_5)
{
    (void)param_1;
    int iVar1;
    int iVar2;
    uint32_t uVar3;

    if (param_3 < 0) {
        iVar1 = -param_3;
    } else {
        iVar1 = FUN_00628b56(param_3, &param_3);
        if (iVar1 < 0) {
            return iVar1;
        }
        iVar1 = param_3;
    }
    uVar3 = param_5 >> 2;
    do {
        iVar2 = FUN_0062603f(iVar1, param_2, param_4, uVar3, 0);
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar1 = *(int*)((intptr_t)iVar1 + 0x24);
    } while (iVar1 != 0);
    return 0;
}

// 0x628f5f — observed shape
int FUN_00628f5f(void* param_1, void* param_2, int param_3, uint8_t param_4)
{
    (void)param_1;
    int* piVar1;
    int iVar2;
    int iVar3;

    if (param_3 < 0) {
        iVar2 = -param_3;
    } else {
        iVar2 = FUN_00628b56(param_3, &param_3);
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar2 = param_3;
    }
    do {
        iVar3 = FUN_006262de(iVar2, param_2, &param_4, (void*)(intptr_t)1, 0);
        if (iVar3 < 0) {
            return iVar3;
        }
        piVar1 = (int*)((intptr_t)iVar2 + 0x24);
        iVar2 = *piVar1;
    } while (*piVar1 != 0);
    return 0;
}

// 0x628fab — observed shape
int FUN_00628fab(void* param_1, void* param_2, int param_3, void* param_4, void* param_5)
{
    (void)param_1;
    int* piVar1;
    int iVar2;
    int iVar3;

    if (param_3 < 0) {
        iVar2 = -param_3;
    } else {
        iVar2 = FUN_00628b56(param_3, &param_3);
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar2 = param_3;
    }
    do {
        iVar3 = FUN_006262de(iVar2, param_2, param_4, param_5, 0);
        if (iVar3 < 0) {
            return iVar3;
        }
        piVar1 = (int*)((intptr_t)iVar2 + 0x24);
        iVar2 = *piVar1;
    } while (*piVar1 != 0);
    return 0;
}

extern int FUN_006265e0(int param_1, void* param_2, void* param_3, void* param_4, int param_5);
extern int FUN_006268d6(int param_1, void* param_2, void* param_3, void* param_4, int param_5);
extern int FUN_00626c07(int param_1, void* param_2, void* param_3, int param_4, int param_5);

// 0x628ff7 — observed shape
int FUN_00628ff7(void* param_1, void* param_2, int param_3, uint8_t param_4)
{
    (void)param_1;
    int* piVar1;
    int iVar2;
    int iVar3;

    if (param_3 < 0) {
        iVar2 = -param_3;
    } else {
        iVar2 = FUN_00628b56(param_3, &param_3);
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar2 = param_3;
    }
    do {
        iVar3 = FUN_006265e0(iVar2, param_2, &param_4, (void*)(intptr_t)1, 0);
        if (iVar3 < 0) {
            return iVar3;
        }
        piVar1 = (int*)((intptr_t)iVar2 + 0x24);
        iVar2 = *piVar1;
    } while (*piVar1 != 0);
    return 0;
}

// 0x629043 — observed shape
int FUN_00629043(void* param_1, void* param_2, int param_3, void* param_4, void* param_5)
{
    (void)param_1;
    int* piVar1;
    int iVar2;
    int iVar3;

    if (param_3 < 0) {
        iVar2 = -param_3;
    } else {
        iVar2 = FUN_00628b56(param_3, &param_3);
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar2 = param_3;
    }
    do {
        iVar3 = FUN_006265e0(iVar2, param_2, param_4, param_5, 0);
        if (iVar3 < 0) {
            return iVar3;
        }
        piVar1 = (int*)((intptr_t)iVar2 + 0x24);
        iVar2 = *piVar1;
    } while (*piVar1 != 0);
    return 0;
}

// 0x62908f — observed shape
int FUN_0062908f(void* param_1, void* param_2, int param_3, uint8_t param_4)
{
    (void)param_1;
    int* piVar1;
    int iVar2;
    int iVar3;

    if (param_3 < 0) {
        iVar2 = -param_3;
    } else {
        iVar2 = FUN_00628b56(param_3, &param_3);
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar2 = param_3;
    }
    do {
        iVar3 = FUN_006268d6(iVar2, param_2, &param_4, (void*)(intptr_t)1, 0);
        if (iVar3 < 0) {
            return iVar3;
        }
        piVar1 = (int*)((intptr_t)iVar2 + 0x24);
        iVar2 = *piVar1;
    } while (*piVar1 != 0);
    return 0;
}

// 0x6290db — observed shape
int FUN_006290db(void* param_1, void* param_2, int param_3, void* param_4, void* param_5)
{
    (void)param_1;
    int* piVar1;
    int iVar2;
    int iVar3;

    if (param_3 < 0) {
        iVar2 = -param_3;
    } else {
        iVar2 = FUN_00628b56(param_3, &param_3);
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar2 = param_3;
    }
    do {
        iVar3 = FUN_006268d6(iVar2, param_2, param_4, param_5, 0);
        if (iVar3 < 0) {
            return iVar3;
        }
        piVar1 = (int*)((intptr_t)iVar2 + 0x24);
        iVar2 = *piVar1;
    } while (*piVar1 != 0);
    return 0;
}

// 0x629127 — observed shape
int FUN_00629127(void* param_1, void* param_2, int param_3, void* param_4)
{
    (void)param_1;
    int* piVar1;
    int iVar2;
    int iVar3;

    if (param_3 < 0) {
        iVar2 = -param_3;
    } else {
        iVar2 = FUN_00628b56(param_3, &param_3);
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar2 = param_3;
    }
    do {
        iVar3 = FUN_00626c07(iVar2, param_2, param_4, 1, 0);
        if (iVar3 < 0) {
            return iVar3;
        }
        piVar1 = (int*)((intptr_t)iVar2 + 0x24);
        iVar2 = *piVar1;
    } while (*piVar1 != 0);
    return 0;
}

extern int FUN_00626ff4(int param_1, void* param_2, void* param_3, int param_4, int param_5);
extern int FUN_00627489(int param_1, void* param_2, void* param_3, void* param_4, int param_5);
extern int FUN_006278c3(int param_1, void* param_2, void* param_3, int param_4, int param_5);

// 0x629172 — observed shape
int FUN_00629172(void* param_1, void* param_2, int param_3, void* param_4, void* param_5)
{
    (void)param_1;
    int* piVar1;
    int iVar2;
    int iVar3;

    if (param_3 < 0) {
        iVar2 = -param_3;
    } else {
        iVar2 = FUN_00628b56(param_3, &param_3);
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar2 = param_3;
    }
    do {
        iVar3 = FUN_00626c07(iVar2, param_2, param_4, (void*)(intptr_t)param_5, 0);
        if (iVar3 < 0) {
            return iVar3;
        }
        piVar1 = (int*)((intptr_t)iVar2 + 0x24);
        iVar2 = *piVar1;
    } while (*piVar1 != 0);
    return 0;
}

// 0x6291be — observed shape
int FUN_006291be(void* param_1, void* param_2, int param_3, void* param_4)
{
    (void)param_1;
    int* piVar1;
    int iVar2;
    int iVar3;

    if (param_3 < 0) {
        iVar2 = -param_3;
    } else {
        iVar2 = FUN_00628b56(param_3, &param_3);
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar2 = param_3;
    }
    do {
        iVar3 = FUN_00626ff4(iVar2, param_2, param_4, 1, 0);
        if (iVar3 < 0) {
            return iVar3;
        }
        piVar1 = (int*)((intptr_t)iVar2 + 0x24);
        iVar2 = *piVar1;
    } while (*piVar1 != 0);
    return 0;
}

// 0x629209 — observed shape
int FUN_00629209(void* param_1, void* param_2, int param_3, void* param_4, void* param_5)
{
    (void)param_1;
    int* piVar1;
    int iVar2;
    int iVar3;

    if (param_3 < 0) {
        iVar2 = -param_3;
    } else {
        iVar2 = FUN_00628b56(param_3, &param_3);
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar2 = param_3;
    }
    do {
        iVar3 = FUN_00626ff4(iVar2, param_2, param_4, (int)(intptr_t)param_5, 0);
        if (iVar3 < 0) {
            return iVar3;
        }
        piVar1 = (int*)((intptr_t)iVar2 + 0x24);
        iVar2 = *piVar1;
    } while (*piVar1 != 0);
    return 0;
}

// 0x629255 — observed shape
int FUN_00629255(void* param_1, void* param_2, int param_3, void* param_4, void* param_5)
{
    (void)param_1;
    int* piVar1;
    int iVar2;
    int iVar3;

    if (param_3 < 0) {
        iVar2 = -param_3;
    } else {
        iVar2 = FUN_00628b56(param_3, &param_3);
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar2 = param_3;
    }
    do {
        iVar3 = FUN_00627489(iVar2, param_2, param_4, param_5, 0);
        if (iVar3 < 0) {
            return iVar3;
        }
        piVar1 = (int*)((intptr_t)iVar2 + 0x24);
        iVar2 = *piVar1;
    } while (*piVar1 != 0);
    return 0;
}

// 0x6292a1 — observed shape
int FUN_006292a1(void* param_1, void* param_2, int param_3, void* param_4)
{
    (void)param_1;
    int* piVar1;
    int iVar2;
    int iVar3;

    if (param_3 < 0) {
        iVar2 = -param_3;
    } else {
        iVar2 = FUN_00628b56(param_3, &param_3);
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar2 = param_3;
    }
    do {
        iVar3 = FUN_006278c3(iVar2, param_2, param_4, 1, 0);
        if (iVar3 < 0) {
            return iVar3;
        }
        piVar1 = (int*)((intptr_t)iVar2 + 0x24);
        iVar2 = *piVar1;
    } while (*piVar1 != 0);
    return 0;
}

extern int FUN_00627dcb(int param_1, void* param_2, void* param_3, void* param_4, int param_5);
extern int FUN_00533c78(void* param_1);
extern void FUN_00629384(void* self);
extern void operator_delete(void* self);

// 0x6292ec — observed shape
int FUN_006292ec(void* param_1, void* param_2, int param_3, void* param_4, void* param_5)
{
    (void)param_1;
    int* piVar1;
    int iVar2;
    int iVar3;

    if (param_3 < 0) {
        iVar2 = -param_3;
    } else {
        iVar2 = FUN_00628b56(param_3, &param_3);
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar2 = param_3;
    }
    do {
        iVar3 = FUN_006278c3(iVar2, param_2, param_4, (int)(intptr_t)param_5, 0);
        if (iVar3 < 0) {
            return iVar3;
        }
        piVar1 = (int*)((intptr_t)iVar2 + 0x24);
        iVar2 = *piVar1;
    } while (*piVar1 != 0);
    return 0;
}

// 0x629338 — observed shape
int FUN_00629338(void* param_1, void* param_2, int param_3, void* param_4, void* param_5)
{
    (void)param_1;
    int* piVar1;
    int iVar2;
    int iVar3;

    if (param_3 < 0) {
        iVar2 = -param_3;
    } else {
        iVar2 = FUN_00628b56(param_3, &param_3);
        if (iVar2 < 0) {
            return iVar2;
        }
        iVar2 = param_3;
    }
    do {
        iVar3 = FUN_00627dcb(iVar2, param_2, param_4, param_5, 0);
        if (iVar3 < 0) {
            return iVar3;
        }
        piVar1 = (int*)((intptr_t)iVar2 + 0x24);
        iVar2 = *piVar1;
    } while (*piVar1 != 0);
    return 0;
}

// 0x629394 — observed shape
uint32_t FUN_00629394(void* self, void* param_1)
{
    int iVar1;
    uint32_t uVar2;

    iVar1 = FUN_00533c78(param_1);
    *(int*)((intptr_t)self + 0xc) = iVar1;
    if (iVar1 == 0) {
        uVar2 = 0x8007000e;
    } else {
        *(void**)((intptr_t)self + 8) = param_1;
        uVar2 = 0;
    }
    return uVar2;
}

// 0x6293d2 — observed shape
int FUN_006293d2(int* param_1)
{
    int iVar1;
    int iVar2;

    iVar2 = param_1[1];
    iVar1 = iVar2 + -1;
    param_1[1] = iVar1;
    if (iVar2 == 1) {
        typedef void (__cdecl* Callback)(int);
        Callback cb = *(Callback*)(*(int*)param_1 + 0x14);
        cb(1);
    }
    return iVar1;
}

// 0x629415 — observed shape
void FUN_00629415(void* self, uint8_t param_1)
{
    FUN_00629384(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}
