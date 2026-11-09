#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void* FUN_00533c78(std::size_t size);
extern void FUN_00540c50();
extern void* thunk_FUN_00533c78(int size);
extern void thunk_FUN_00540cf0(void* self, uint32_t param_1);
extern void* PTR_FUN_0070e93c;
extern uint32_t* DAT_00727594;

// 0x53db80 — observed shape
char* FUN_0053db80(char* param_1, uint32_t param_2)
{
    char cVar1;
    char* pcVar2;
    pcVar2 = param_1;
    do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = (char*)thunk_FUN_00533c78((int)((pcVar2 - (char*)1 - param_1) + 0x16) + 1);
    // Note: listing computes pcVar2 + (0x16 - (int)(param_1 + 1)) as size argument; preserved as observed below.
    pcVar2 = (char*)thunk_FUN_00533c78(pcVar2 + (0x16 - (int)(param_1 + 1)));
    switch(param_2) {
    case 0:
        sprintf(pcVar2,"%s = ACTION_KEEP",param_1);
        return pcVar2;
    case 1:
        sprintf(pcVar2,"%s = ACTION_ZERO",param_1);
        return pcVar2;
    case 2:
        sprintf(pcVar2,"%s = ACTION_REPLACE",param_1);
        return pcVar2;
    case 3:
        sprintf(pcVar2,"%s = ACTION_INCREMENT",param_1);
        return pcVar2;
    case 4:
        sprintf(pcVar2,"%s = ACTION_DECREMENT",param_1);
        return pcVar2;
    case 5:
        sprintf(pcVar2,"%s = ACTION_INVERT",param_1);
    }
    return pcVar2;
}

// 0x53dc60 — observed shape
char* FUN_0053dc60(char* param_1, uint32_t param_2)
{
    char cVar1;
    char* pcVar2;
    pcVar2 = param_1;
    do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = (char*)thunk_FUN_00533c78(pcVar2 + (0x16 - (int)(param_1 + 1)));
    switch(param_2) {
    case 0:
        sprintf(pcVar2,"%s = DRAW_CCW_OR_BOTH",param_1);
        return pcVar2;
    case 1:
        sprintf(pcVar2,"%s = DRAW_CCW",param_1);
        return pcVar2;
    case 2:
        sprintf(pcVar2,"%s = DRAW_CW",param_1);
        return pcVar2;
    case 3:
        sprintf(pcVar2,"%s = DRAW_BOTH",param_1);
    }
    return pcVar2;
}

// 0x53dd00 — observed shape
uint32_t* FUN_0053dd00(void* self, uint32_t param_1)
{
    uint32_t* puVar1;
    puVar1 = (uint32_t*)FUN_00533c78(0x40);
    if (puVar1 == (uint32_t*)0x0) {
        puVar1 = (uint32_t*)0x0;
    }
    else {
        FUN_00540c50();
        *puVar1 = (uint32_t)(std::uintptr_t)&PTR_FUN_0070e93c;
        *(uint8_t*)(puVar1 + 8) = 0;
        puVar1[9] = 4;
        puVar1[10] = 0;
        puVar1[0xb] = 0xffffffff;
        puVar1[0xc] = 0;
        puVar1[0xd] = 0;
        puVar1[0xe] = 3;
        puVar1[0xf] = 0;
    }
    thunk_FUN_00540cf0(puVar1, param_1);
    *(uint8_t*)(puVar1 + 8) = *(uint8_t*)((char*)self + 0x20);
    puVar1[9] = *(uint32_t*)((char*)self + 0x24);
    puVar1[10] = *(uint32_t*)((char*)self + 0x28);
    puVar1[0xb] = *(uint32_t*)((char*)self + 0x2c);
    puVar1[0xc] = *(uint32_t*)((char*)self + 0x30);
    puVar1[0xd] = *(uint32_t*)((char*)self + 0x34);
    puVar1[0xe] = *(uint32_t*)((char*)self + 0x38);
    puVar1[0xf] = *(uint32_t*)((char*)self + 0x3c);
    return puVar1;
}

// 0x53df60 — observed shape
void FUN_0053df60()
{
    int iVar1;
    uint32_t* puVar2;
    uint32_t* puVar3;
    puVar3 = (uint32_t*)FUN_00533c78(0x40);
    if (puVar3 == (uint32_t*)0x0) {
        puVar3 = (uint32_t*)0x0;
    }
    else {
        FUN_00540c50();
        *puVar3 = (uint32_t)(std::uintptr_t)&PTR_FUN_0070e93c;
        *(uint8_t*)(puVar3 + 8) = 0;
        puVar3[9] = 4;
        puVar3[10] = 0;
        puVar3[0xb] = 0xffffffff;
        puVar3[0xc] = 0;
        puVar3[0xd] = 0;
        puVar3[0xe] = 3;
        puVar3[0xf] = 0;
    }
    puVar2 = DAT_00727594;
    if (DAT_00727594 != puVar3) {
        if ((DAT_00727594 != (uint32_t*)0x0) &&
           (iVar1 = DAT_00727594[1], DAT_00727594[1] = iVar1 + -1, iVar1 + -1 == 0)) {
            (*(void(**)(int))(*puVar2))(1);
        }
        DAT_00727594 = puVar3;
        if (puVar3 != (uint32_t*)0x0) {
            puVar3[1] = puVar3[1] + 1;
        }
    }
    return;
}

// 0x53dfe0 — observed shape
void FUN_0053dfe0()
{
    int iVar1;
    uint32_t* puVar2;
    puVar2 = DAT_00727594;
    if (DAT_00727594 != (uint32_t*)0x0) {
        iVar1 = DAT_00727594[1];
        DAT_00727594[1] = iVar1 + -1;
        if (iVar1 + -1 == 0) {
            (*(void(**)(int))(*puVar2))(1);
        }
        DAT_00727594 = (uint32_t*)0x0;
    }
    return;
}

extern void FUN_00559c30(int x);
extern void FUN_00548720(int a, int b);
extern void FUN_00534cf0(void* a, void* b);
extern char FUN_00533f50(uint32_t param_1);
extern int FUN_005348e0(int param_1);
extern void FUN_005349d0();
extern void* PTR_FUN_006c0e78;

// 0x53e240 — observed shape
void FUN_0053e240(void* self)
{
    int iVar1;
    iVar1 = *(int*)((char*)self + 0xbc) + 0x10;
    if (*(int*)((char*)self + 0xc0) != 0) {
        FUN_00559c30(iVar1);
    }
    FUN_00548720(iVar1, (int)(std::uintptr_t)((char*)self + 0x6c));
    return;
}

// 0x53e500 — observed shape
void FUN_0053e500(void* self, int* param_1)
{
    (**(void(**)(uint32_t))(*param_1 + 0x74))(*(uint32_t*)((char*)self + 0xbc));
    FUN_00534cf0(param_1, param_1);
    return;
}

// 0x53e530 — observed shape
uint8_t FUN_0053e530(void* self, uint32_t param_1)
{
    char cVar1;
    cVar1 = FUN_00533f50(param_1);
    if (cVar1 == '\0') {
        return 0;
    }
    (**(void(**)(uint32_t))(**(int**)((char*)self + 0xbc) + 0x14))(param_1);
    if (*(int**)((char*)self + 0xc0) != (int*)0x0) {
        (**(void(**)(uint32_t))(**(int**)((char*)self + 0xc0) + 0x14))(param_1);
    }
    return 1;
}

// 0x53e570 — observed shape
int FUN_0053e570(void* self, int param_1)
{
    int* piVar1;
    int iVar2;
    iVar2 = FUN_005348e0(param_1);
    if ((char)iVar2 == '\0') {
        return iVar2;
    }
    piVar1 = *(int**)((char*)self + 0xc0);
    uint32_t uVar3 = (uint32_t)((uint32_t)iVar2 >> 8);
    if ((piVar1 == (int*)0x0) != (*(int*)(param_1 + 0xc0) == 0)) {
        return (int)(uVar3 << 8);
    }
    if (piVar1 != (int*)0x0) {
        (**(int(**)(uint32_t))(*piVar1 + 0x1c))(*(int*)(param_1 + 0xc0));
        // extraout_AL / extraout_var observed; preserved structure: if zero, return shifted value.
        // Listing shows register residue; model as no-op check is unrecoverable — use goto-style return.
        // To preserve observed control flow without inventing semantics, keep return.
        // NEEDS_MANUAL: extraout_AL check depends on unlisted call residue.
        return (int)(uVar3 << 8);
    }
    iVar2 = (**(int(**)(uint32_t))(**(int**)((char*)self + 0xbc) + 0x1c))(*(uint32_t*)(param_1 + 0xbc));
    return iVar2;
}

// 0x53e5d0 — observed shape
void FUN_0053e5d0(void* self, int param_1)
{
    uint32_t* in_ECX = (uint32_t*)self;
    FUN_005349d0();
    *in_ECX = (uint32_t)(std::uintptr_t)&PTR_FUN_006c0e78;
    in_ECX[0x2d] = 0;
    in_ECX[0x2e] = 0;
    in_ECX[0x2f] = param_1;
    if (param_1 != 0) {
        *(int*)(param_1 + 4) = *(int*)(param_1 + 4) + 1;
    }
    in_ECX[0x30] = 0;
    in_ECX[0x32] = 0;
    in_ECX[0x31] = 0x3f;
    return;
}

extern void FUN_00547760();
extern void FUN_00534040();
extern int* FUN_00534270(void** a, void* b, int c);

// 0x53e630 — observed shape
void FUN_0053e630(void* self)
{
    uint32_t* in_ECX = (uint32_t*)self;
    FUN_005349d0();
    *in_ECX = (uint32_t)(std::uintptr_t)&PTR_FUN_006c0e78;
    in_ECX[0x2d] = 0;
    in_ECX[0x2e] = 0;
    in_ECX[0x2f] = 0;
    in_ECX[0x30] = 0;
    in_ECX[0x32] = 0;
    return;
}

// 0x53e670 — observed shape
void FUN_0053e670(void* self)
{
    uint32_t* in_ECX = (uint32_t*)self;
    *in_ECX = (uint32_t)(std::uintptr_t)&PTR_FUN_006c0e78;
    FUN_00547760();
    uint32_t* puVar2;
    int* piVar1;
    puVar2 = (uint32_t*)in_ECX[0x2f];
    if (puVar2 != (uint32_t*)0x0) {
        piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (*(void(**)(int))(*puVar2))(1);
        }
        in_ECX[0x2f] = 0;
    }
    puVar2 = (uint32_t*)in_ECX[0x32];
    if (puVar2 != (uint32_t*)0x0) {
        piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (*(void(**)(int))(*puVar2))(1);
        }
    }
    puVar2 = (uint32_t*)in_ECX[0x30];
    if (puVar2 != (uint32_t*)0x0) {
        piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (*(void(**)(int))(*puVar2))(1);
        }
    }
    puVar2 = (uint32_t*)in_ECX[0x2f];
    if (puVar2 != (uint32_t*)0x0) {
        piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (*(void(**)(int))(*puVar2))(1);
        }
    }
    puVar2 = (uint32_t*)in_ECX[0x2e];
    if (puVar2 != (uint32_t*)0x0) {
        piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (*(void(**)(int))(*puVar2))(1);
        }
    }
    puVar2 = (uint32_t*)in_ECX[0x2d];
    if (puVar2 != (uint32_t*)0x0) {
        piVar1 = (int*)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (*(void(**)(int))(*puVar2))(1);
        }
    }
    FUN_00534040();
    return;
}

// 0x53e760 — observed shape
void FUN_0053e760(void* self, int param_1)
{
    *(uint32_t*)(param_1 + 0x10) = *(uint32_t*)((char*)self + 0xb4);
    *(uint32_t*)(param_1 + 0x14) = *(uint32_t*)((char*)self + 0xb8);
    int* piVar1 = *(int**)((char*)self + 0x10);
    if (piVar1 == (int*)0x0) {
        *(uint32_t*)(param_1 + 0x5c) = *(uint32_t*)((char*)self + 0xc4);
        return;
    }
    do {
        (**(void(**)())(*piVar1 + 0x50))();
        piVar1 = (int*)piVar1[0xe];
    } while (piVar1 != (int*)0x0);
    *(uint32_t*)(param_1 + 0x5c) = *(uint32_t*)((char*)self + 0xc4);
    return;
}

// 0x53e7b0 — observed shape
void FUN_0053e7b0(void* self, uint32_t* param_1)
{
    int* piVar1;
    uint32_t* puVar2;
    if (param_1 != (uint32_t*)0x0) {
        if (*(int**)((char*)self + 0xb0) != (int*)0x0) {
            (**(void(**)())(**(int**)((char*)self + 0xb0) + 0x3c))();
            (**(void(**)())(**(int**)((char*)self + 0xb0) + 0x38))();
        }
        puVar2 = *(uint32_t**)((char*)self + 0xbc);
        if (puVar2 != param_1) {
            if (puVar2 != (uint32_t*)0x0) {
                piVar1 = (int*)(puVar2 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    (*(void(**)(int))(*puVar2))(1);
                }
            }
            *(uint32_t**)((char*)self + 0xbc) = param_1;
            param_1[1] = param_1[1] + 1;
        }
    }
    return;
}

// 0x53e800 — observed shape
void FUN_0053e800(void* self, uint32_t* param_1)
{
    int* piVar1;
    uint32_t* puVar2;
    int iVar3;
    int* piVar4;
    piVar4 = (int*)FUN_00534270((void**)&param_1, param_1, 1);
    puVar2 = *(uint32_t**)((char*)self + 0xb4);
    if (puVar2 != (uint32_t*)*piVar4) {
        if (puVar2 != (uint32_t*)0x0) {
            piVar1 = (int*)(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                (*(void(**)(int))(*puVar2))(1);
            }
        }
        iVar3 = *piVar4;
        *(int*)((char*)self + 0xb4) = iVar3;
        if (iVar3 != 0) {
            *(int*)(iVar3 + 4) = *(int*)(iVar3 + 4) + 1;
        }
    }
    if ((param_1 != (uint32_t*)0x0) &&
       (iVar3 = param_1[1], param_1[1] = iVar3 + -1, iVar3 + -1 == 0)) {
        (*(void(**)(int))(*param_1))(1);
    }
    return;
}

extern void FUN_00534b40(uint8_t* a, uint32_t b, uint8_t* c);
extern void FUN_00533f30(int* param_1);
extern void thunk_FUN_005405e0(void* param_1);
extern char FUN_005bd960(int a, void** b);
extern void* FUN_00547620();
extern uint32_t FUN_005dbd60();
extern uint32_t FUN_005dbd70();
extern void FUN_0055a260(uint32_t x);
extern void FUN_00547610(uint32_t x);
extern void FUN_00547730(void* a, uint32_t b);
extern void FUN_00534410(uint32_t param_1);
extern void FUN_00545cc0();
extern void FUN_005476f0(uint32_t x);
extern void FUN_00534660(uint32_t param_1);
extern void* FUN_00545600();
extern void* DAT_0072785c;

// 0x53e940 — observed shape
void FUN_0053e940(void* self, uint8_t* param_1, uint32_t param_2, uint8_t* param_3)
{
    FUN_00534b40(param_1, param_2, param_3);
    if (*(int*)((char*)self + 0xc0) != 0) {
        *(uint8_t*)((char*)self + 0x20) = *(uint8_t*)((char*)self + 0x20) | 4;
        *param_1 = 1;
        *(uint8_t*)((char*)self + 0x20) = *(uint8_t*)((char*)self + 0x20) | 2;
        *param_3 = 0;
    }
    return;
}

// 0x53ea10 — observed shape
void FUN_0053ea10(void* self, int* param_1)
{
    int iVar1;
    FUN_00533f30(param_1);
    (**(void(**)(uint32_t))(*param_1 + 0xe4))(*(uint32_t*)((char*)self + 0xbc));
    if (*(int*)((char*)self + 0xc0) != 0) {
        (**(void(**)(int))(*param_1 + 0xf8))(*(int*)((char*)self + 0xc0));
        iVar1 = *(int*)(*(int*)((char*)self + 0xc0) + 0xc);
        if (iVar1 != 0) {
            (**(void(**)(uint32_t))(*param_1 + 0xf4))(*(uint32_t*)(iVar1 + 0xc));
            return;
        }
        (**(void(**)(int))(*param_1 + 0xf4))(0);
    }
    return;
}

// 0x53ea80 — observed shape
void FUN_0053ea80(void* self, uint32_t* param_1)
{
    int* piVar1;
    uint32_t* puVar2;
    uint32_t* puVar3;
    char cVar4;
    void* puVar5;
    int iVar6;
    uint32_t* puVar7;
    uint32_t uVar8;
    puVar7 = param_1;
    thunk_FUN_005405e0(param_1);
    FUN_005bd960((int)(std::uintptr_t)self, (void**)&param_1);
    puVar3 = param_1;
    if (*(int*)((char*)self + 0xc0) != 0) {
        cVar4 = FUN_005bd960(*(int*)((char*)self + 0xc0), (void**)&param_1);
        if (cVar4 == '\0') {
            puVar7 = (uint32_t*)(**(void* (**)(uint32_t*))(**(int**)((char*)self + 0xc0) + 8))(puVar7);
        }
        else {
            puVar7 = param_1;
        }
        puVar2 = (uint32_t*)puVar3[0x30];
        if (puVar2 != puVar7) {
            if (puVar2 != (uint32_t*)0x0) {
                piVar1 = (int*)(puVar2 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    (*(void(**)(int))(*puVar2))(1);
                }
            }
            puVar3[0x30] = puVar7;
            if (puVar7 != (uint32_t*)0x0) {
                puVar7[1] = puVar7[1] + 1;
            }
        }
    }
    if (*(int**)((char*)self + 200) != (int*)0x0) {
        puVar5 = (void*)(**(void* (** )())(**(int**)((char*)self + 200) + 4))();
        if (puVar5 == DAT_0072785c) {
            iVar6 = (int)(std::uintptr_t)FUN_00533c78(0x10);
            if (iVar6 == 0) {
                puVar7 = (uint32_t*)0x0;
            }
            else {
                puVar7 = (uint32_t*)FUN_00547620();
            }
            uVar8 = FUN_005dbd60();
            FUN_0055a260(uVar8);
            uVar8 = FUN_005dbd70();
            FUN_00547610(uVar8);
            puVar2 = (uint32_t*)puVar3[0x32];
            if (puVar2 != puVar7) {
                if (puVar2 != (uint32_t*)0x0) {
                    piVar1 = (int*)(puVar2 + 1);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) {
                        (*(void(**)(int))(*puVar2))(1);
                    }
                }
                puVar3[0x32] = puVar7;
                if (puVar7 != (uint32_t*)0x0) {
                    puVar7[1] = puVar7[1] + 1;
                    return;
                }
            }
        }
        else {
            uVar8 = FUN_005dbd70();
            uVar8 = FUN_005dbd60();
            FUN_00547730(puVar3, uVar8);
        }
    }
    return;
}

// 0x53ec00 — observed shape
// NEEDS_MANUAL: unaff_BL is uninitialized register residue in listing; if-condition on its value is preserved as opaque.
void FUN_0053ec00(void* self, uint32_t param_1)
{
    int* piVar1;
    uint32_t* puVar2;
    uint32_t uVar3;
    int iVar4;
    uint32_t* puVar5;
    char unaff_BL = 0;
    uVar3 = param_1;
    FUN_00534410(param_1);
    FUN_00545cc0();
    FUN_00545cc0();
    if (0x5000014 < *(uint32_t*)(uVar3 + 0x1c)) {
        param_1 = param_1 & 0xffffff00;
        (**(void(**)(void*, int))(**(int**)(uVar3 + 0x15c) + 8))(&param_1, 1);
        if (unaff_BL != '\0') {
            iVar4 = (int)(std::uintptr_t)FUN_00533c78(0x10);
            if (iVar4 == 0) {
                puVar5 = (uint32_t*)0x0;
            }
            else {
                puVar5 = (uint32_t*)FUN_00547620();
            }
            puVar2 = *(uint32_t**)((char*)self + 200);
            if (puVar2 != puVar5) {
                if (puVar2 != (uint32_t*)0x0) {
                    piVar1 = (int*)(puVar2 + 1);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) {
                        (*(void(**)(int))(*puVar2))(1);
                    }
                }
                *(uint32_t**)((char*)self + 200) = puVar5;
                if (puVar5 != (uint32_t*)0x0) {
                    puVar5[1] = puVar5[1] + 1;
                }
            }
            FUN_005476f0(uVar3);
        }
    }
    return;
}

// 0x53eca0 — observed shape
void FUN_0053eca0(void* self, uint32_t param_1)
{
    int* piVar1;
    uint32_t* puVar2;
    uint32_t* puVar3;
    FUN_00534660(param_1);
    puVar3 = (uint32_t*)FUN_00545600();
    puVar2 = *(uint32_t**)((char*)self + 0xbc);
    if (puVar2 != puVar3) {
        if (puVar2 != (uint32_t*)0x0) {
            piVar1 = (int*)(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                (*(void(**)(int))(*puVar2))(1);
            }
        }
        *(uint32_t**)((char*)self + 0xbc) = puVar3;
        if (puVar3 != (uint32_t*)0x0) {
            puVar3[1] = puVar3[1] + 1;
        }
    }
    puVar3 = (uint32_t*)FUN_00545600();
    puVar2 = *(uint32_t**)((char*)self + 0xc0);
    if (puVar2 != puVar3) {
        if (puVar2 != (uint32_t*)0x0) {
            piVar1 = (int*)(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                (*(void(**)(int))(*puVar2))(1);
            }
        }
        *(uint32_t**)((char*)self + 0xc0) = puVar3;
        if (puVar3 != (uint32_t*)0x0) {
            puVar3[1] = puVar3[1] + 1;
        }
    }
    return;
}
