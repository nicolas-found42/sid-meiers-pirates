#include <cstdint>
#include <cstddef>
#include <windows.h>

// Extern declarations for referenced helpers and globals.
extern void operator_delete__(void*);
extern void FUN_005397f0(void);
extern void FUN_00540c90(void);
extern void FUN_0054cc80(int param_1);
extern int  FUN_00557b10(int param_1);
extern void FUN_006b34a0(int param_1);
extern void FUN_005606f0(uint32_t param_1, int* param_2);
extern int  thunk_FUN_00533c78(int param_1);
extern void FUN_004127b0(int param_1, int param_2, int param_3, void* param_4);

extern void* PTR_FUN_006c0a90;
extern void* PTR_FUN_006c0a50;

extern int DAT_00727520;
extern int DAT_00727528;
extern int DAT_0072752c;
extern int _DAT_00727554;
extern DWORD DAT_00727550;
extern CRITICAL_SECTION DAT_00727538;

// 0x53a110 — observed shape
void FUN_0053a110(void* self)
{
    uint32_t** self32 = (uint32_t**)self;
    *self32 = (uint32_t*)PTR_FUN_006c0a90;
    operator_delete__((void*)self32[0xe]);
    operator_delete__((void*)self32[0xf]);
    uint32_t* puVar2 = (uint32_t*)self32[0x10];
    if (puVar2 != (uint32_t*)0x0) {
        int* piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            ((void(*)(int))(**(void***)puVar2))(1);
        }
        self32[0x10] = 0;
    }
    puVar2 = (uint32_t*)self32[0x10];
    if (puVar2 != (uint32_t*)0x0) {
        int* piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            ((void(*)(int))(**(void***)puVar2))(1);
        }
    }
    *self32 = (uint32_t*)PTR_FUN_006c0a50;
    if ((uint32_t*)self32[0xb] != (uint32_t*)0x0) {
        ((void(*)(int))(**(void***)self32[0xb]))(1);
    }
    FUN_005397f0();
    FUN_00540c90();
}

// 0x53a180 — observed shape
void FUN_0053a180(int self)
{
    uint32_t uVar1;
    FUN_0054cc80(self);
    int param_1 = FUN_00557b10(DAT_00727520);
    uVar1 = *(uint32_t*)(self + 0xc);
    if (*(uint32_t*)(self + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(self + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
}

// 0x53a240 — observed shape
void FUN_0053a240(void* self)
{
    intptr_t in_ECX = (intptr_t)self;
    DWORD DVar1 = GetCurrentThreadId();
    if (DAT_00727550 != DVar1) {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00727538);
        DAT_00727550 = GetCurrentThreadId();
    }
    _DAT_00727554 = _DAT_00727554 + 1;
    if (DAT_00727528 == 0) {
        DAT_00727528 = (int)in_ECX;
    }
    if (DAT_0072752c == 0) {
        *(uint32_t*)(in_ECX + 0x20) = 0;
    }
    else {
        *(int*)(DAT_0072752c + 0x24) = (int)in_ECX;
        *(int*)(in_ECX + 0x20) = DAT_0072752c;
    }
    DAT_0072752c = (int)in_ECX;
    *(uint32_t*)(in_ECX + 0x24) = 0;
    DVar1 = GetCurrentThreadId();
    if ((DAT_00727550 == DVar1) && (_DAT_00727554 = _DAT_00727554 + -1, _DAT_00727554 == 0)) {
        DAT_00727550 = 0;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00727538);
    }
}

// 0x53a2d0 — observed shape
void FUN_0053a2d0(void* self)
{
    intptr_t in_ECX = (intptr_t)self;
    DWORD DVar1 = GetCurrentThreadId();
    if (DAT_00727550 != DVar1) {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00727538);
        DAT_00727550 = GetCurrentThreadId();
    }
    _DAT_00727554 = _DAT_00727554 + 1;
    if (DAT_00727528 == (int)in_ECX) {
        DAT_00727528 = *(int*)(in_ECX + 0x24);
    }
    if (DAT_0072752c == (int)in_ECX) {
        DAT_0072752c = *(int*)(in_ECX + 0x20);
    }
    if (*(int*)(in_ECX + 0x20) != 0) {
        *(uint32_t*)(*(int*)(in_ECX + 0x20) + 0x24) = *(uint32_t*)(in_ECX + 0x24);
    }
    if (*(int*)(in_ECX + 0x24) != 0) {
        *(uint32_t*)(*(int*)(in_ECX + 0x24) + 0x20) = *(uint32_t*)(in_ECX + 0x20);
    }
    DVar1 = GetCurrentThreadId();
    if ((DAT_00727550 == DVar1) && (_DAT_00727554 = _DAT_00727554 + -1, _DAT_00727554 == 0)) {
        DAT_00727550 = 0;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00727538);
    }
}

// 0x53a380 — observed shape
void FUN_0053a380(void* self, int param_1)
{
    intptr_t in_ECX = (intptr_t)self;
    if (in_ECX != param_1) {
        if (*(void***)(in_ECX + 0x1c) != (void***)0x0) {
            ((void(*)(int))(**(void***)**(void****)(in_ECX + 0x1c)))(1);
            *(uint32_t*)(in_ECX + 0x1c) = 0;
        }
        *(uint8_t*)(in_ECX + 0xc) = *(uint8_t*)(param_1 + 0xc);
        *(uint32_t*)(in_ECX + 0x14) = 1;
        if (*(int*)(in_ECX + 0x10) != *(int*)(param_1 + 0x10)) {
            operator_delete__(*(void**)(in_ECX + 0x18));
            int iVar3 = *(int*)(param_1 + 0x10);
            *(int*)(in_ECX + 0x10) = iVar3;
            int iVar1 = thunk_FUN_00533c78(iVar3 * 4);
            if (iVar1 == 0) {
                iVar1 = 0;
            }
            else {
                // LAB_005cea70: static initializer object for array copy
                extern uint8_t LAB_005cea70[];
                FUN_004127b0(iVar1, 4, iVar3, (void*)LAB_005cea70);
            }
            *(int*)(in_ECX + 0x18) = iVar1;
        }
        uint32_t* puVar4 = *(uint32_t**)(param_1 + 0x18);
        uint32_t* puVar5 = *(uint32_t**)(in_ECX + 0x18);
        for (uint32_t uVar2 = *(uint32_t*)(param_1 + 0x10) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar5 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar5 = puVar5 + 1;
        }
        for (int iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
            *(uint8_t*)puVar5 = *(uint8_t*)puVar4;
            puVar4 = (uint32_t*)((intptr_t)puVar4 + 1);
            puVar5 = (uint32_t*)((intptr_t)puVar5 + 1);
        }
    }
}

// 0x53a470 — observed shape
void FUN_0053a470(void* self, uint8_t param_1)
{
    uint32_t** in_ECX = (uint32_t**)self;
    extern void* PTR_FUN_006c0ae8;
    extern void operator_delete(void*);
    extern void FUN_00538400(void);
    *in_ECX = (uint32_t*)PTR_FUN_006c0ae8;
    operator_delete__((void*)in_ECX[6]);
    if ((uint32_t*)in_ECX[7] != (uint32_t*)0x0) {
        ((void(*)(int))(**(void***)in_ECX[7]))(1);
    }
    FUN_0053a2d0(self);
    FUN_00538400();
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
}

// 0x53a4c0 — observed shape
void FUN_0053a4c0(void* self, int param_1)
{
    uint32_t** in_ECX = (uint32_t**)self;
    extern void* PTR_FUN_006c0ae8;
    extern void FUN_005383d0(void);
    extern int* DAT_00727c30;
    FUN_005383d0();
    *in_ECX = (uint32_t*)PTR_FUN_006c0ae8;
    *(uint8_t*)(in_ECX + 3) = *(uint8_t*)(param_1 + 0xc);
    int iVar3 = *(int*)(param_1 + 0x10);
    in_ECX[4] = (uint32_t*)iVar3;
    in_ECX[5] = (uint32_t*)1;
    uint32_t* puVar1 = (uint32_t*)thunk_FUN_00533c78(iVar3 * 4);
    in_ECX[6] = puVar1;
    uint32_t* puVar4 = *(uint32_t**)(param_1 + 0x18);
    for (uint32_t uVar2 = *(uint32_t*)(param_1 + 0x10) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar1 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar1 = puVar1 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(uint8_t*)puVar1 = *(uint8_t*)puVar4;
        puVar4 = (uint32_t*)((intptr_t)puVar4 + 1);
        puVar1 = (uint32_t*)((intptr_t)puVar1 + 1);
    }
    in_ECX[7] = 0;
    if (DAT_00727c30 != (int*)0x0) {
        ((void(*)())(**(void***)(*(int**)(DAT_00727c30) + 0x110)))(0);
    }
    FUN_0053a240(self);
}

// 0x53a540 — observed shape
void FUN_0053a540(void* self, uint8_t param_1, int param_2)
{
    uint32_t** in_ECX = (uint32_t**)self;
    extern void* PTR_FUN_006c0ae8;
    extern void FUN_005383d0(void);
    extern int* DAT_00727c30;
    FUN_005383d0();
    *(uint8_t*)(in_ECX + 3) = param_1;
    *in_ECX = (uint32_t*)PTR_FUN_006c0ae8;
    in_ECX[4] = (uint32_t*)param_2;
    uint32_t uVar1 = (uint32_t)thunk_FUN_00533c78(param_2 * 4);
    in_ECX[6] = (uint32_t*)uVar1;
    in_ECX[5] = (uint32_t*)1;
    in_ECX[7] = 0;
    if (DAT_00727c30 != (int*)0x0) {
        ((void(*)())(**(void***)(*(int**)(DAT_00727c30) + 0x110)))(0);
    }
    FUN_0053a240(self);
}

// 0x53a5a0 — observed shape
void FUN_0053a5a0(void* self, uint8_t param_1, int param_2, uint32_t* param_3)
{
    uint32_t** in_ECX = (uint32_t**)self;
    extern void* PTR_FUN_006c0ae8;
    extern void FUN_005383d0(void);
    extern int* DAT_00727c30;
    FUN_005383d0();
    *(uint8_t*)(in_ECX + 3) = param_1;
    *in_ECX = (uint32_t*)PTR_FUN_006c0ae8;
    in_ECX[5] = (uint32_t*)1;
    in_ECX[4] = (uint32_t*)param_2;
    uint32_t* puVar1 = (uint32_t*)thunk_FUN_00533c78(param_2 * 4);
    in_ECX[6] = puVar1;
    for (uint32_t uVar2 = in_ECX[4] & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar1 = *param_3;
        param_3 = param_3 + 1;
        puVar1 = puVar1 + 1;
    }
    for (int iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(uint8_t*)puVar1 = *(uint8_t*)param_3;
        param_3 = (uint32_t*)((intptr_t)param_3 + 1);
        puVar1 = (uint32_t*)((intptr_t)puVar1 + 1);
    }
    in_ECX[7] = 0;
    if (DAT_00727c30 != (int*)0x0) {
        ((void(*)())(**(void***)(*(int**)(DAT_00727c30) + 0x110)))(0);
    }
    FUN_0053a240(self);
}

// 0x53a6e0 — observed shape
void FUN_0053a6e0(void* self, int param_1)
{
    intptr_t in_ECX = (intptr_t)self;
    extern void FUN_00538430(int);
    int iVar1 = param_1;
    FUN_00538430(param_1);
    int param_1b = (param_1 & 0xffffff00) | (int)*(uint8_t*)(in_ECX + 0xc);
    ((void(*)(int*, int))(**(void***)(**(int**)(iVar1 + 0x160) + 0xc)))(&param_1b, 1);
    ((void(*)(int*, int))(**(void***)(**(int**)(iVar1 + 0x160) + 0xc)))((int*)(in_ECX + 0x10), 4);
    ((void(*)(uint32_t*, int))(**(void***)(**(int**)(iVar1 + 0x160) + 0xc)))(*(uint32_t**)(in_ECX + 0x18), *(int*)(in_ECX + 0x10) << 2);
}

// 0x53a740 — observed shape
void FUN_0053a740(int self)
{
    uint32_t uVar1;
    extern void FUN_005386f0(int);
    extern int DAT_00727530;
    int iVar2 = self;
    FUN_005386f0(self);
    int param_1 = FUN_00557b10(DAT_00727530);
    uVar1 = *(uint32_t*)(iVar2 + 0xc);
    if (*(uint32_t*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
}

// 0x53a790 — observed shape
void FUN_0053a790(void* self)
{
    uint32_t** in_ECX = (uint32_t**)self;
    extern void FUN_0053e630(void);
    extern void* PTR_FUN_006c0b28;
    FUN_0053e630();
    *in_ECX = (uint32_t*)PTR_FUN_006c0b28;
}

// 0x53a850 — observed shape
void FUN_0053a850(void* self, uint8_t param_1)
{
    void* in_ECX = self;
    extern void FUN_005572c0(void);
    extern void operator_delete(void*);
    FUN_005572c0();
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
}

// 0x53a8f0 — observed shape
void FUN_0053a8f0(int self)
{
    uint32_t uVar1;
    extern void FUN_0053edc0(int);
    extern int DAT_00727558;
    int iVar2 = self;
    FUN_0053edc0(self);
    int param_1 = FUN_00557b10(DAT_00727558);
    uVar1 = *(uint32_t*)(iVar2 + 0xc);
    if (*(uint32_t*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
}

// 0x53a940 — observed shape
void FUN_0053a940(uint32_t param_1)
{
    extern void FUN_00534410(uint32_t);
    extern void FUN_00545d20(void);
    FUN_00534410(param_1);
    FUN_00545d20();
    FUN_00545d20();
}

// 0x53a980 — observed shape
void FUN_0053a980(void* self, uint8_t param_1)
{
    uint32_t** in_ECX = (uint32_t**)self;
    extern void* PTR_FUN_006c0bc4;
    extern void FUN_005edba0(void);
    extern void* PTR_LAB_006c0bb8;
    extern void operator_delete(void*);
    *in_ECX = (uint32_t*)PTR_FUN_006c0bc4;
    FUN_005edba0();
    *in_ECX = (uint32_t*)PTR_LAB_006c0bb8;
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
}

// 0x53ab20 — observed shape
void FUN_0053ab20(void* self)
{
    intptr_t in_ECX = (intptr_t)self;
    extern void FUN_00548600(uint32_t*);
    uint32_t uVar2 = 0;
    *(uint32_t*)(in_ECX + 0x34) = 0;
    if (*(int*)(in_ECX + 0xc0) != 0) {
        do {
            int iVar1 = *(int*)(*(int*)(in_ECX + 0xb8) + uVar2 * 4);
            if ((iVar1 != 0) && (*(float*)(iVar1 + 0x34) != 0.0f)) {
                if (*(float*)(in_ECX + 0x34) == 0.0f) {
                    *(uint32_t*)(in_ECX + 0x28) = *(uint32_t*)(iVar1 + 0x28);
                    *(uint32_t*)(in_ECX + 0x2c) = *(uint32_t*)(iVar1 + 0x2c);
                    *(uint32_t*)(in_ECX + 0x30) = *(uint32_t*)(iVar1 + 0x30);
                    *(uint32_t*)(in_ECX + 0x34) = *(uint32_t*)(iVar1 + 0x34);
                }
                else {
                    FUN_00548600((uint32_t*)(iVar1 + 0x28));
                }
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint32_t*)(in_ECX + 0xc0));
    }
}

// 0x53ac20 — observed shape
void FUN_0053ac20(void* self)
{
    intptr_t in_ECX = (intptr_t)self;
    extern void FUN_005579c0(void*);
    extern void FUN_00548720(void*, void*);
    uint32_t uVar2 = 0;
    if (*(int*)(in_ECX + 0xc0) != 0) {
        do {
            int* piVar1 = *(int**)(*(int*)(in_ECX + 0xb8) + uVar2 * 4);
            if (piVar1 != (int*)0x0) {
                ((void(*)())(**(void***)piVar1 + 0x38))(0);
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint32_t*)(in_ECX + 0xc0));
    }
    uint8_t local_34[52];
    FUN_005579c0(local_34);
    FUN_00548720((void*)(in_ECX + 0x28), local_34);
}

// 0x53ac80 — observed shape
void FUN_0053ac80(void* self, uint32_t param_1)
{
    intptr_t in_ECX = (intptr_t)self;
    extern void FUN_00533e70(uint32_t);
    uint32_t uVar1 = 0;
    if ((*(float*)(in_ECX + 0x34) != 0.0f) && (*(int*)(in_ECX + 0xc0) != 0)) {
        do {
            if (*(int*)(*(int*)(in_ECX + 0xb8) + uVar1 * 4) != 0) {
                FUN_00533e70(param_1);
            }
            uVar1 = uVar1 + 1;
        } while (uVar1 < *(uint32_t*)(in_ECX + 0xc0));
    }
}

// 0x53ace0 — observed shape
void FUN_0053ace0(void* self, int* param_1)
{
    intptr_t in_ECX = (intptr_t)self;
    extern void FUN_00533f30(int*);
    FUN_00533f30(param_1);
    int* piVar2 = *(int**)(in_ECX + 0xd0);
    if (piVar2 != (int*)0x0) {
        do {
            int* piVar1 = piVar2 + 2;
            piVar2 = (int*)*piVar2;
            ((void(*)(int*))(**(void***)param_1 + 0xec))(*piVar1);
        } while (piVar2 != (int*)0x0);
    }
    uint32_t uVar3 = 0;
    if (*(int*)(in_ECX + 0xc0) != 0) {
        do {
            piVar2 = *(int**)(*(int*)(in_ECX + 0xb8) + uVar3 * 4);
            if (piVar2 != (int*)0x0) {
                ((void(*)(int*))(**(void***)piVar2 + 100))(param_1);
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint32_t*)(in_ECX + 0xc0));
    }
}
