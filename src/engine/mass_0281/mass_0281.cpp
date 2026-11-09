#include <cstdint>
#include <cstddef>
#include <windows.h>

// 0x625b69 — observed shape
void FUN_00625b69(int *param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5)
{
    using Fn = void (*)(int*, uint32_t, uint32_t, uint32_t);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(*reinterpret_cast<uintptr_t*>(param_1) + 0x1b4));
    fn(param_1, param_2, param_3, param_5);
}

// 0x625b87 — observed shape
void FUN_00625b87(int *param_1, uint32_t param_2, int param_3, float *param_4, int param_5)
{
    int iVar2 = param_5 << 2;
    if (iVar2 != 0) {
        int iVar1 = param_3 - reinterpret_cast<int>(param_4);
        do {
            *param_4 = (float)(*reinterpret_cast<int*>(iVar1 + reinterpret_cast<int>(param_4)) != 0);
            param_4 = param_4 + 1;
            iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
    }
    using Fn = void (*)(int*, uint32_t, int, int);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(*reinterpret_cast<uintptr_t*>(param_1) + 0x1b4));
    fn(param_1, param_2, param_3, param_5);
}

// 0x625bd1 — observed shape
void FUN_00625bd1(int *param_1, uint32_t param_2, int param_3, float *param_4, int param_5)
{
    int iVar2 = param_5 << 2;
    if (iVar2 != 0) {
        int iVar1 = param_3 - reinterpret_cast<int>(param_4);
        do {
            *param_4 = (float)*reinterpret_cast<int*>(iVar1 + reinterpret_cast<int>(param_4));
            param_4 = param_4 + 1;
            iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
    }
    using Fn = void (*)(int*, uint32_t, int, int);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(*reinterpret_cast<uintptr_t*>(param_1) + 0x1b4));
    fn(param_1, param_2, param_3, param_5);
}

// 0x625c0c — observed shape
uint32_t FUN_00625c0c(int *param_1, int param_2, uint32_t *param_3, float *param_4, uint32_t param_5)
{
    int iVar2 = param_5 << 2;
    if (iVar2 != 0) {
        int iVar1 = reinterpret_cast<int>(param_3) - reinterpret_cast<int>(param_4);
        do {
            *param_4 = (float)(*reinterpret_cast<int*>(iVar1 + reinterpret_cast<int>(param_4)) != 0);
            param_4 = param_4 + 1;
            iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
    }
    using Fn = int (*)(int*);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(*reinterpret_cast<uintptr_t*>(param_1) + 0xc));
    iVar2 = fn(param_1);
    uint32_t *puVar3 = reinterpret_cast<uint32_t*>(iVar2 + param_2 * 0x10);
    for (int iVar1 = (param_5 & 0xfffffff) << 2; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *param_3;
        param_3 = param_3 + 1;
        puVar3 = puVar3 + 1;
    }
    for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
        *reinterpret_cast<uint8_t*>(puVar3) = *reinterpret_cast<uint8_t*>(param_3);
        param_3 = reinterpret_cast<uint32_t*>(reinterpret_cast<int>(param_3) + 1);
        puVar3 = reinterpret_cast<uint32_t*>(reinterpret_cast<int>(puVar3) + 1);
    }
    return 0;
}

// 0x625c70 — observed shape
uint32_t FUN_00625c70(int *param_1, int param_2, uint32_t *param_3, float *param_4, uint32_t param_5)
{
    int iVar2 = param_5 << 2;
    if (iVar2 != 0) {
        int iVar1 = reinterpret_cast<int>(param_3) - reinterpret_cast<int>(param_4);
        do {
            *param_4 = (float)*reinterpret_cast<int*>(iVar1 + reinterpret_cast<int>(param_4));
            param_4 = param_4 + 1;
            iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
    }
    using Fn = int (*)(int*);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(*reinterpret_cast<uintptr_t*>(param_1) + 0xc));
    iVar2 = fn(param_1);
    uint32_t *puVar3 = reinterpret_cast<uint32_t*>(iVar2 + param_2 * 0x10);
    for (int iVar1 = (param_5 & 0xfffffff) << 2; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *param_3;
        param_3 = param_3 + 1;
        puVar3 = puVar3 + 1;
    }
    for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
        *reinterpret_cast<uint8_t*>(puVar3) = *reinterpret_cast<uint8_t*>(param_3);
        param_3 = reinterpret_cast<uint32_t*>(reinterpret_cast<int>(param_3) + 1);
        puVar3 = reinterpret_cast<uint32_t*>(reinterpret_cast<int>(puVar3) + 1);
    }
    return 0;
}

// 0x625cc6 — observed shape
uint32_t FUN_00625cc6(int *param_1, int param_2, uint32_t *param_3, uint32_t param_4, uint32_t param_5)
{
    using Fn = int (*)(int*);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(*reinterpret_cast<uintptr_t*>(param_1) + 0xc));
    int iVar1 = fn(param_1);
    uint32_t *puVar3 = reinterpret_cast<uint32_t*>(iVar1 + param_2 * 0x10);
    for (int iVar2 = (param_5 & 0xfffffff) << 2; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = *param_3;
        param_3 = param_3 + 1;
        puVar3 = puVar3 + 1;
    }
    for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
        *reinterpret_cast<uint8_t*>(puVar3) = *reinterpret_cast<uint8_t*>(param_3);
        param_3 = reinterpret_cast<uint32_t*>(reinterpret_cast<int>(param_3) + 1);
        puVar3 = reinterpret_cast<uint32_t*>(reinterpret_cast<int>(puVar3) + 1);
    }
    return 0;
}

// 0x625d03 — observed shape
extern void FUN_006257ba(void);
extern void operator_delete(void*);
void FUN_00625d03(void* self, uint8_t param_1)
{
    FUN_006257ba();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x625d24 — observed shape
extern void* PTR_FUN_006e18a8;
extern void FUN_00625d03(void*, uint8_t);
void FUN_00625d24(void* self)
{
    uint32_t *in_ECX = reinterpret_cast<uint32_t*>(self);
    *in_ECX = reinterpret_cast<uint32_t>(PTR_FUN_006e18a8);
    if (in_ECX[5] != 0) {
        uint32_t uVar1 = 0;
        if (in_ECX[6] != 0) {
            do {
                if (*reinterpret_cast<int*>(in_ECX[5] + uVar1 * 4) != 0) {
                    FUN_00625d03(reinterpret_cast<void*>(*reinterpret_cast<int*>(in_ECX[5] + uVar1 * 4)), 1);
                }
                uVar1 = uVar1 + 1;
            } while (uVar1 < in_ECX[6]);
        }
        operator_delete(reinterpret_cast<void*>(in_ECX[5]));
    }
    operator_delete(reinterpret_cast<void*>(in_ECX[2]));
    operator_delete(reinterpret_cast<void*>(in_ECX[7]));
}

// 0x625d72 — observed shape
void FUN_00625d72(int *param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5)
{
    using Fn = void (*)(int*, uint32_t, uint32_t, uint32_t);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(*reinterpret_cast<uintptr_t*>(param_1) + 0x188));
    fn(param_1, param_2, param_3, param_5);
}

// 0x625d90 — observed shape
void FUN_00625d90(int *param_1, uint32_t param_2, int param_3, uint32_t *param_4, int param_5)
{
    if (param_5 != 0) {
        int iVar1 = param_3 - reinterpret_cast<int>(param_4);
        int iVar2 = param_5;
        do {
            *param_4 = (uint32_t)(*reinterpret_cast<int*>(iVar1 + reinterpret_cast<int>(param_4)) != 0);
            param_4 = param_4 + 1;
            iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
    }
    using Fn = void (*)(int*, uint32_t, int, int);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(*reinterpret_cast<uintptr_t*>(param_1) + 0x188));
    fn(param_1, param_2, param_3, param_5);
}

// 0x625dd1 — observed shape
void FUN_00625dd1(int *param_1, uint32_t param_2, int param_3, uint32_t *param_4, int param_5)
{
    if (param_5 != 0) {
        int iVar1 = param_3 - reinterpret_cast<int>(param_4);
        int iVar2 = param_5;
        do {
            *param_4 = (uint32_t)(*reinterpret_cast<float*>(iVar1 + reinterpret_cast<int>(param_4)) != 0.0f);
            param_4 = param_4 + 1;
            iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
    }
    using Fn = void (*)(int*, uint32_t, int, int);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(*reinterpret_cast<uintptr_t*>(param_1) + 0x188));
    fn(param_1, param_2, param_3, param_5);
}

// 0x625e23 — observed shape
void FUN_00625e23(int *param_1, uint32_t param_2, int param_3, uint32_t *param_4, int param_5)
{
    int iVar2 = param_5 << 2;
    if (iVar2 != 0) {
        int iVar1 = param_3 - reinterpret_cast<int>(param_4);
        do {
            *param_4 = (uint32_t)(*reinterpret_cast<int*>(iVar1 + reinterpret_cast<int>(param_4)) != 0);
            param_4 = param_4 + 1;
            iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
    }
    using Fn = void (*)(int*, uint32_t, int, int);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(*reinterpret_cast<uintptr_t*>(param_1) + 0x180));
    fn(param_1, param_2, param_3, param_5);
}

// 0x625e67 — observed shape
void FUN_00625e67(int *param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5)
{
    using Fn = void (*)(int*, uint32_t, uint32_t, uint32_t);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(*reinterpret_cast<uintptr_t*>(param_1) + 0x180));
    fn(param_1, param_2, param_3, param_5);
}

// 0x625e85 — observed shape
void FUN_00625e85(int *param_1, uint32_t param_2, int param_3, int *param_4, int param_5)
{
    int iVar2 = param_5 << 2;
    if (iVar2 != 0) {
        int iVar1 = param_3 - reinterpret_cast<int>(param_4);
        do {
            *param_4 = (int)(*reinterpret_cast<float*>(iVar1 + reinterpret_cast<int>(param_4)) + 0.5f);
            param_4 = param_4 + 1;
            iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
    }
    using Fn = void (*)(int*, uint32_t, int, int);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(*reinterpret_cast<uintptr_t*>(param_1) + 0x180));
    fn(param_1, param_2, param_3, param_5);
}

// 0x625eeb — observed shape
void FUN_00625eeb(int *param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5)
{
    using Fn = void (*)(int*, uint32_t, uint32_t, uint32_t);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(*reinterpret_cast<uintptr_t*>(param_1) + 0x178));
    fn(param_1, param_2, param_3, param_5);
}

// 0x625f09 — observed shape
void FUN_00625f09(int *param_1, uint32_t param_2, int param_3, float *param_4, int param_5)
{
    int iVar2 = param_5 << 2;
    if (iVar2 != 0) {
        int iVar1 = param_3 - reinterpret_cast<int>(param_4);
        do {
            *param_4 = (float)(*reinterpret_cast<int*>(iVar1 + reinterpret_cast<int>(param_4)) != 0);
            param_4 = param_4 + 1;
            iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
    }
    using Fn = void (*)(int*, uint32_t, int, int);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(*reinterpret_cast<uintptr_t*>(param_1) + 0x178));
    fn(param_1, param_2, param_3, param_5);
}

// 0x625f53 — observed shape
void FUN_00625f53(int *param_1, uint32_t param_2, int param_3, float *param_4, int param_5)
{
    int iVar2 = param_5 << 2;
    if (iVar2 != 0) {
        int iVar1 = param_3 - reinterpret_cast<int>(param_4);
        do {
            *param_4 = (float)*reinterpret_cast<int*>(iVar1 + reinterpret_cast<int>(param_4));
            param_4 = param_4 + 1;
            iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
    }
    using Fn = void (*)(int*, uint32_t, int, int);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(*reinterpret_cast<uintptr_t*>(param_1) + 0x178));
    fn(param_1, param_2, param_3, param_5);
}

// 0x625f8e — observed shape
void FUN_00625f8e(int *param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5)
{
    using Fn = void (*)(int*, uint32_t, uint32_t, uint32_t);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(*reinterpret_cast<uintptr_t*>(param_1) + 0x1c4));
    fn(param_1, param_2, param_3, param_5);
}

// 0x625fac — observed shape
void FUN_00625fac(int *param_1, uint32_t param_2, int param_3, uint32_t *param_4, int param_5)
{
    if (param_5 != 0) {
        int iVar1 = param_3 - reinterpret_cast<int>(param_4);
        int iVar2 = param_5;
        do {
            *param_4 = (uint32_t)(*reinterpret_cast<int*>(iVar1 + reinterpret_cast<int>(param_4)) != 0);
            param_4 = param_4 + 1;
            iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
    }
    using Fn = void (*)(int*, uint32_t, int, int);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(*reinterpret_cast<uintptr_t*>(param_1) + 0x1c4));
    fn(param_1, param_2, param_3, param_5);
}

// 0x625fed — observed shape
void FUN_00625fed(int *param_1, uint32_t param_2, int param_3, uint32_t *param_4, int param_5)
{
    if (param_5 != 0) {
        int iVar1 = param_3 - reinterpret_cast<int>(param_4);
        int iVar2 = param_5;
        do {
            *param_4 = (uint32_t)(*reinterpret_cast<float*>(iVar1 + reinterpret_cast<int>(param_4)) != 0.0f);
            param_4 = param_4 + 1;
            iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
    }
    using Fn = void (*)(int*, uint32_t, int, int);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(*reinterpret_cast<uintptr_t*>(param_1) + 0x1c4));
    fn(param_1, param_2, param_3, param_5);
}
