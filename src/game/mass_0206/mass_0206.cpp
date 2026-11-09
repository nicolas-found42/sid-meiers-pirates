#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cmath>

extern void FUN_005b97d0(int param_1);
extern int FUN_00557b10(int param_1);
extern void FUN_006b34a0(int param_1);
extern void FUN_005606f0(uint32_t a, int* b);
extern void FUN_005aeb40(void);
extern void FUN_005edba0(void);
extern void FUN_0053e670(void);
extern void FUN_005aed90(uint32_t a, int b, uint8_t* c);
extern void FUN_005aed10(void);
extern void FUN_00520da0(int a);
extern void* PTR_FUN_006c5a40;
extern void* PTR_LAB_006c5a18;
extern int DAT_00728cb0;

// 0x5bb7d0 — observed shape
void FUN_005bb7d0(int param_1_recon) {
    int iVar2 = param_1_recon;
    FUN_005b97d0(param_1_recon);
    int param_1 = FUN_00557b10(DAT_00728cb0);
    uint32_t uVar1 = *(uint32_t*)(iVar2 + 0xc);
    if (*(uint32_t*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
}

// 0x5bb8d0 — observed shape
void FUN_005bb8d0(void* self_recon) {
    int in_ECX = (int)(intptr_t)self_recon;
    FUN_005aeb40();
    *(void**)(in_ECX + 0xd0) = &PTR_FUN_006c5a40;
    FUN_005edba0();
    *(void**)(in_ECX + 0xd0) = &PTR_LAB_006c5a18;
    FUN_0053e670();
}

// 0x5bb990 — observed shape
void FUN_005bb990(void* self_recon, uint32_t param_1, uint32_t param_2, uint8_t* param_3) {
    (void)param_2;
    FUN_005aed90(param_1, 1, param_3);
    int in_ECX = (int)(intptr_t)self_recon;
    int iVar2 = *(int*)(in_ECX + 0xbc);
    typedef void (*Fn)(uint32_t, int, uint8_t*);
    void** obj = *(void***)(iVar2 + 0x58);
    Fn fn = *(Fn*)((char*)*obj + 0x44);
    fn(param_1, 1, param_3);
    *param_3 = 0;
    uint8_t* pbVar1 = (uint8_t*)(*(int*)(iVar2 + 0x58) + 0x20);
    *pbVar1 = *pbVar1 & 0xef;
}

// 0x5bb9d0 — observed shape
void FUN_005bb9d0(void* self_recon) {
    FUN_005aed10();
    int in_ECX = (int)(intptr_t)self_recon;
    int iVar1 = *(int*)(*(int*)(in_ECX + 0xbc) + 0x58);
    *(uint32_t*)(in_ECX + 0x28) = *(uint32_t*)(iVar1 + 0x28);
    *(uint32_t*)(in_ECX + 0x2c) = *(uint32_t*)(iVar1 + 0x2c);
    *(uint32_t*)(in_ECX + 0x30) = *(uint32_t*)(iVar1 + 0x30);
    *(uint32_t*)(in_ECX + 0x34) = *(uint32_t*)(iVar1 + 0x34);
}

// 0x5bba00 — observed shape
void FUN_005bba00(int param_1_recon) {
    uint16_t uVar3 = 0;
    if (*(int16_t*)(param_1_recon + 0x44) != 0) {
        do {
            uint32_t uVar4 = (uint32_t)uVar3;
            if ((uVar4 < *(uint32_t*)(*(int*)(param_1_recon + 0x58) + 0xc0)) &&
                (*(int*)(*(int*)(*(int*)(param_1_recon + 0x58) + 0xb8) + uVar4 * 4) != 0)) {
                int iVar2 = *(int*)(*(int*)(*(int*)(param_1_recon + 0x58) + 0xb8) + uVar4 * 4);
                uint32_t* puVar1 = (uint32_t*)(*(int*)(param_1_recon + 0x20) + uVar4 * 0xc);
                *(uint32_t*)(iVar2 + 0x5c) = *puVar1;
                *(uint32_t*)(iVar2 + 0x60) = puVar1[1];
                *(uint32_t*)(iVar2 + 100) = puVar1[2];
                if (*(int*)(param_1_recon + 0x4c) != 0) {
                    FUN_00520da0(iVar2 + 0x38);
                }
                *(float*)(iVar2 + 0x68) =
                    fabsf(*(float*)(*(int*)(param_1_recon + 0x48) + uVar4 * 4) *
                          *(float*)(*(int*)(param_1_recon + 0x40) + uVar4 * 4));
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint16_t*)(param_1_recon + 0x44));
    }
}
extern void FUN_005bb8d0(void* self);
extern void FUN_005aea80(void);
extern void FUN_00534130(void);
extern void FUN_00534350(void);
extern void FUN_005af5d0(int a);
extern void FUN_005383d0(void);
extern void FUN_00538400(void);
extern int DAT_00728cb8;
extern void* PTR_FUN_006c6c18;

// 0x5bbb30 — observed shape
void FUN_005bbb30(void* self_recon, uint8_t param_1) {
    void* in_ECX = self_recon;
    FUN_005bb8d0(self_recon);
    if ((param_1 & 1) != 0) {
        operator delete(in_ECX);
    }
}

// 0x5bbb50 — observed shape
void FUN_005bbb50(void* self_recon) {
    int in_ECX = (int)(intptr_t)self_recon;
    FUN_005aea80();
    int iVar1 = *(int*)(in_ECX + 0xbc);
    FUN_005bba00(iVar1);
    uint32_t* puVar3 = (uint32_t*)(in_ECX + 0x6c);
    uint32_t* puVar4 = (uint32_t*)(*(int*)(iVar1 + 0x58) + 0x38);
    for (int iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
    }
    int iVar2b = *(int*)(iVar1 + 0x58);
    *(uint32_t*)(iVar2b + 0x5c) = *(uint32_t*)(in_ECX + 0x90);
    *(uint32_t*)(iVar2b + 0x60) = *(uint32_t*)(in_ECX + 0x94);
    *(uint32_t*)(iVar2b + 100) = *(uint32_t*)(in_ECX + 0x98);
    *(float*)(*(int*)(iVar1 + 0x58) + 0x68) = fabsf(*(float*)(in_ECX + 0x9c));
    typedef void (*Fn)(uint32_t, int);
    void** obj = *(void***)(iVar1 + 0x58);
    Fn fn = *(Fn*)((char*)*obj + 0x48);
    fn(*(uint32_t*)(in_ECX + 0xfc), 0);
    if (*(char*)(iVar1 + 0x5c) != '\0') {
        FUN_00534130();
        FUN_00534350();
        *(uint8_t*)(iVar1 + 0x5c) = 0;
    }
}

// 0x5bbcd0 — observed shape
void FUN_005bbcd0(int param_1_recon) {
    int iVar2 = param_1_recon;
    FUN_005af5d0(param_1_recon);
    int param_1 = FUN_00557b10(DAT_00728cb8);
    uint32_t uVar1 = *(uint32_t*)(iVar2 + 0xc);
    if (*(uint32_t*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
}

// 0x5bbd20 — observed shape
void FUN_005bbd20(void* self_recon) {
    uint32_t* in_ECX = (uint32_t*)self_recon;
    FUN_005383d0();
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    *in_ECX = (uint32_t)(intptr_t)&PTR_FUN_006c6c18;
    *(uint8_t*)(in_ECX + 6) = 1;
}

// 0x5bbd50 — observed shape
void FUN_005bbd50(void* self_recon) {
    uint32_t* in_ECX = (uint32_t*)self_recon;
    *in_ECX = (uint32_t)(intptr_t)&PTR_FUN_006c6c18;
    operator delete((void*)(intptr_t)in_ECX[3]);
    FUN_00538400();
}

extern void FUN_00513ce0(uint32_t a);
extern void FUN_00545600(void);
extern uint32_t FUN_00538460(int a);
extern void* thunk_FUN_00533c78(void* a);
extern void FUN_00538410(int a, uint32_t b);
extern void FUN_005bd960(int a, void* b);
extern void FUN_005bbe20(void* self, char* a);

// 0x5bbd70 — observed shape
void FUN_005bbd70(uint32_t param_1_recon) {
    FUN_00513ce0(param_1_recon);
    FUN_00545600();
}

// 0x5bbd90 — observed shape
uint32_t FUN_005bbd90(void* self_recon, int param_1) {
    int in_ECX = (int)(intptr_t)self_recon;
    uint32_t uVar2 = FUN_00538460(param_1);
    if ((char)uVar2 == '\0') {
        return uVar2;
    }
    uint8_t* pbVar3 = *(uint8_t**)(in_ECX + 0xc);
    if ((pbVar3 != nullptr) && (*(uint8_t**)(param_1 + 0xc) != nullptr)) {
        uint8_t* pbVar4 = *(uint8_t**)(param_1 + 0xc);
        uint8_t bVar1;
        bool bVar5;
        do {
            bVar1 = *pbVar3;
            bVar5 = bVar1 < *pbVar4;
            if (bVar1 != *pbVar4) {
                pbVar3 = (uint8_t*)((int64_t)(1 - (uint32_t)bVar5) - (uint32_t)(bVar5 != 0));
                goto LAB_005bbde4;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar3[1];
            bVar5 = bVar1 < pbVar4[1];
            if (bVar1 != pbVar4[1]) {
                pbVar3 = (uint8_t*)((int64_t)(1 - (uint32_t)bVar5) - (uint32_t)(bVar5 != 0));
                goto LAB_005bbde4;
            }
            pbVar3 = pbVar3 + 2;
            pbVar4 = pbVar4 + 2;
        } while (bVar1 != 0);
        pbVar3 = nullptr;
    LAB_005bbde4:
        if ((pbVar3 == nullptr) &&
            ((pbVar3 = *(uint8_t**)(in_ECX + 0x10), pbVar3 == *(uint8_t**)(param_1 + 0x10))) &&
            (*(char*)(in_ECX + 0x18) == *(char*)(param_1 + 0x18))) {
            return (uint32_t)((((uint32_t)(intptr_t)pbVar3 >> 8) << 8) | 1);
        }
    }
    return (uint32_t)(intptr_t)pbVar3 & 0xffffff00;
}

// 0x5bbe20 — observed shape
void FUN_005bbe20(void* self_recon, char* param_1) {
    int in_ECX = (int)(intptr_t)self_recon;
    operator delete(*(void**)(in_ECX + 0xc));
    char* pcVar2 = param_1;
    char cVar1;
    do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = (char*)thunk_FUN_00533c78(pcVar2 + (1 - (int)(intptr_t)(param_1 + 1)));
    *(char**)(in_ECX + 0xc) = pcVar2;
    do {
        cVar1 = *param_1;
        param_1 = param_1 + 1;
        *pcVar2 = cVar1;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
}

// 0x5bbeb0 — observed shape
void FUN_005bbeb0(void* self_recon, int param_1, uint32_t param_2) {
    int in_ECX = (int)(intptr_t)self_recon;
    FUN_00538410(param_1, param_2);
    FUN_005bbe20(self_recon, *(char**)(in_ECX + 0xc));
    *(uint32_t*)(param_1 + 0x10) = *(uint32_t*)(in_ECX + 0x10);
    *(uint8_t*)(param_1 + 0x18) = *(uint8_t*)(in_ECX + 0x18);
}

// 0x5bbee0 — observed shape
void FUN_005bbee0(void* self_recon, int param_1) {
    int in_ECX = (int)(intptr_t)self_recon;
    FUN_00513ce0(param_1);
    FUN_005bd960(in_ECX, &param_1);
    int iVar1 = param_1;
    FUN_005bd960(*(int*)(in_ECX + 0x14), &param_1);
    *(int*)(iVar1 + 0x14) = param_1;
}

extern void FUN_00538630(int a);
extern void FUN_005460e0(int a);
extern void FUN_00545cc0(void);
extern void FUN_00538430(int* a);
extern void FUN_00545950(uint32_t a);
extern void FUN_005386f0(int a);
extern int DAT_00728cc0;
extern int FUN_00557d80(const void* a, uint32_t b);
extern int FUN_00557cb0(const char* a, uint32_t b);
extern int FUN_00557b50(const char* a, uint8_t b);
extern void* DAT_006c6c6c;
extern void* PTR_FUN_006c6c88;

// 0x5bbf20 — observed shape
void FUN_005bbf20(void* self_recon, int param_1) {
    int in_ECX = (int)(intptr_t)self_recon;
    uint8_t auStackY_98[128];
    uint8_t cVar1 = '\x04';
    FUN_00538630(param_1);
    FUN_005460e0(in_ECX + 0xc);
    typedef void (*Fn)(int);
    void** obj = *(void***)(param_1 + 0x15c);
    Fn fn1 = *(Fn*)((char*)*obj + 8);
    fn1(in_ECX + 0x10);
    FUN_00545cc0();
    Fn fn2 = *(Fn*)((char*)*obj + 8);
    fn2((int)(intptr_t)(auStackY_98 + 0x94));
    *(bool*)(in_ECX + 0x18) = cVar1 != '\0';
}

// 0x5bbf80 — observed shape
void FUN_005bbf80(void* self_recon, int* param_1) {
    int in_ECX = (int)(intptr_t)self_recon;
    uint8_t auStackY_9c[128];
    FUN_00538430(param_1);
    FUN_00545950(*(uint32_t*)(in_ECX + 0xc));
    typedef void (*Fn)(int, int);
    void** obj = *(void**)(param_1[0x58]);
    Fn fn1 = *(Fn*)((char*)*obj + 0xc);
    fn1(in_ECX + 0x10, 4);
    typedef void (*Fn2)(uint32_t);
    void** obj2 = *(void**)param_1;
    Fn2 fn2 = *(Fn2*)((char*)*obj2 + 0x2c);
    fn2(*(uint32_t*)(in_ECX + 0x14));
    Fn fn3 = *(Fn*)((char*)*obj + 0xc);
    fn3((int)(intptr_t)(auStackY_9c + 0x94), 1);
}

// 0x5bbfe0 — observed shape
void FUN_005bbfe0(void* self_recon, int param_1_recon) {
    int in_ECX = (int)(intptr_t)self_recon;
    int iVar2 = param_1_recon;
    FUN_005386f0(param_1_recon);
    int param_1 = FUN_00557b10(DAT_00728cc0);
    uint32_t uVar1 = *(uint32_t*)(iVar2 + 0xc);
    if (*(uint32_t*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
    param_1 = FUN_00557d80(&DAT_006c6c6c, *(uint32_t*)(in_ECX + 0xc));
    uVar1 = *(uint32_t*)(iVar2 + 0xc);
    if (*(uint32_t*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
    param_1 = FUN_00557cb0("Order", *(uint32_t*)(in_ECX + 0x10));
    uVar1 = *(uint32_t*)(iVar2 + 0xc);
    if (*(uint32_t*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
    param_1 = FUN_00557b50("Active", *(uint8_t*)(in_ECX + 0x18));
    uVar1 = *(uint32_t*)(iVar2 + 0xc);
    if (*(uint32_t*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
}

// 0x5bc0e0 — observed shape
void FUN_005bc0e0(void* self_recon) {
    uint32_t* in_ECX = (uint32_t*)self_recon;
    FUN_005bbd20(self_recon);
    in_ECX[7] = 0;
    in_ECX[8] = 0;
    in_ECX[9] = 0;
    *(uint8_t*)(in_ECX + 10) = 0;
    in_ECX[0xb] = 0;
    in_ECX[0xc] = 0;
    *in_ECX = (uint32_t)(intptr_t)&PTR_FUN_006c6c88;
}

// 0x5bc110 — observed shape
void FUN_005bc110(void* self_recon, int param_1, uint32_t param_2) {
    int in_ECX = (int)(intptr_t)self_recon;
    FUN_005bbeb0(self_recon, param_1, param_2);
    *(uint32_t*)(param_1 + 0x1c) = *(uint32_t*)(in_ECX + 0x1c);
    *(uint32_t*)(param_1 + 0x20) = *(uint32_t*)(in_ECX + 0x20);
    *(uint32_t*)(param_1 + 0x24) = *(uint32_t*)(in_ECX + 0x24);
    *(uint8_t*)(param_1 + 0x28) = *(uint8_t*)(in_ECX + 0x28);
    *(uint32_t*)(param_1 + 0x2c) = *(uint32_t*)(in_ECX + 0x2c);
    *(uint32_t*)(param_1 + 0x30) = *(uint32_t*)(in_ECX + 0x30);
}
