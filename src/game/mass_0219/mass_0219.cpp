#include <cstdint>
#include <cstddef>
#include <windows.h>

// Externs for reconstructed globals and helpers.
extern uint32_t DAT_00728e20[];
extern uint32_t DAT_00728e28;
extern uint32_t DAT_00728e2c;
extern uint32_t DAT_00728e30;
extern uint32_t DAT_00717c64;
extern uint32_t DAT_00717c6c;
extern void FUN_005ca200(uint32_t);
extern void FUN_005bf090(void*);
extern void FUN_005ca3d0(void);
extern void FUN_005cb700(void);
extern void FUN_005bd940(int);
extern int FUN_005bdd30(int);
extern void FUN_005be1e0(uint32_t);
extern uint32_t FUN_005bf990(uint32_t);
extern void FUN_005d7e40(int, uint32_t, int);
extern int FUN_005bf9b0(void*, uint32_t);
extern int FUN_005ca9e0(uint32_t, float*);
extern void FUN_005d8350(uint32_t);
extern void* thunk_FUN_00533c78(uint32_t);
extern void FUN_004127b0(void*, uint32_t, int, void*);
extern void operator_delete(void*);
extern void operator_delete__(void*);

// 0x5ca610 — observed shape
void FUN_005ca610_recon(void)
{
    uint32_t* puVar3 = DAT_00728e20;
    int* piVar1 = (int*)&DAT_00728e20[2];
    if (DAT_00728e20[2] == 0) {
        int* piVar2 = (int*)&DAT_00728e20[3];
        FUN_005ca200(DAT_00728e20[3]);
        *piVar2 = *piVar2 << 1;
    }
    puVar3 = (uint32_t*)*puVar3;
    char* pcVar4 = (char*)*puVar3;
    int iVar5 = *piVar1 - 1;
    *piVar1 = iVar5;
    *puVar3 = puVar3[iVar5];
    if (*pcVar4 == '\0') {
        *pcVar4 = '\x01';
    }
}

// 0x5ca660 — observed shape
void FUN_005ca660_recon(char* param_1)
{
    char* pcVar2 = param_1;
    if (param_1 != nullptr && *param_1 != '\0') {
        param_1 = (char*)*(int*)(param_1 + 8);
        while (param_1 != nullptr) {
            int iVar1 = *(int*)((int)param_1 + 8);
            FUN_005bf090(&param_1);
            param_1 = (char*)iVar1;
        }
        param_1 = *(char**)(pcVar2 + 0x10);
        pcVar2[8] = '\0';
        pcVar2[9] = '\0';
        pcVar2[10] = '\0';
        pcVar2[0xb] = '\0';
        pcVar2[4] = '\0';
        pcVar2[5] = '\0';
        pcVar2[6] = '\0';
        pcVar2[7] = '\0';
        while (param_1 != nullptr) {
            int iVar1 = *(int*)((int)param_1 + 8);
            FUN_005bf090(&param_1);
            param_1 = (char*)iVar1;
        }
        pcVar2[0x10] = '\0';
        pcVar2[0x11] = '\0';
        pcVar2[0x12] = '\0';
        pcVar2[0x13] = '\0';
        pcVar2[0xc] = '\0';
        pcVar2[0xd] = '\0';
        pcVar2[0xe] = '\0';
        pcVar2[0xf] = '\0';
        param_1 = pcVar2;
        FUN_005bf090(&param_1);
    }
}

// 0x5ca6f0 — observed shape
void FUN_005ca6f0_recon(void* self)
{
    int* in_ECX = (int*)self;
    int iVar1 = *in_ECX;
    if (iVar1 != 0) {
        int iVar3 = *(int*)(iVar1 - 4);
        if (-1 < iVar3 - 1) {
            do {
                FUN_005ca3d0();
                iVar3 = iVar3 - 1;
            } while (iVar3 != 0);
        }
        operator_delete__((void*)(iVar1 - 4));
    }
    void* pvVar2 = (void*)in_ECX[2];
    if (pvVar2 != nullptr) {
        FUN_005ca6f0_recon(pvVar2);
        operator_delete(pvVar2);
    }
}

// 0x5ca750 — observed shape
void FUN_005ca750_recon(uint32_t param_1)
{
    if (param_1 < DAT_00717c64) {
        do {
            (*(void(**)(uint32_t,int))(*(uint32_t*)DAT_00728e30 + 0xec))(param_1, 0);
            (*(void(**)(uint32_t,int,int,int))(*(uint32_t*)DAT_00728e30 + 0xd4))(param_1, 1, 1, 0);
            (*(void(**)(uint32_t,int,int,int))(*(uint32_t*)DAT_00728e30 + 0xd4))(param_1, 4, 1, 0);
            param_1 = param_1 + 1;
        } while (param_1 < DAT_00717c64);
    }
    if (param_1 < DAT_00717c6c) {
        do {
            (*(void(**)(uint32_t,int))(*(uint32_t*)DAT_00728e30 + 0xec))(param_1, 0);
            param_1 = param_1 + 1;
        } while (param_1 < DAT_00717c6c);
    }
}

// 0x5ca7d0 — observed shape
void FUN_005ca7d0_recon(void* self, uint8_t param_1)
{
    FUN_005cb700();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5ca7f0 — observed shape
void FUN_005ca7f0_recon(int param_1)
{
    DAT_00728e2c = param_1;
    if (param_1 == 0) {
        if (DAT_00728e28 != 0) {
            (*(void(**)(uint32_t))(*(uint32_t*)DAT_00728e28 + 8))(DAT_00728e28);
        }
        DAT_00728e28 = 0;
        DAT_00728e30 = 0;
        return;
    }
    uint32_t piVar1 = *(uint32_t*)(param_1 + 0x60);
    if (DAT_00728e28 != 0) {
        (*(void(**)(uint32_t))(*(uint32_t*)DAT_00728e28 + 8))(DAT_00728e28);
    }
    DAT_00728e28 = piVar1;
    if (piVar1 != 0) {
        (*(void(**)(uint32_t))(*(uint32_t*)piVar1 + 4))(piVar1);
    }
    DAT_00728e30 = *(uint32_t*)(DAT_00728e2c + 0x5cc);
}

// 0x5ca890 — observed shape
void FUN_005ca890_recon(void* self, uint32_t param_1, int param_2)
{
    int in_ECX = (int)self;
    if (param_1 != 0) {
        *(uint8_t*)(in_ECX + 0x60) = 1;
    }
    *(uint32_t*)(in_ECX + 0x18) = param_1;
    if (param_2 != 0 && (param_1 & 0xf0000000) == 0x10000000) {
        FUN_005bd940(param_2);
        int iVar1 = FUN_005bdd30(param_2);
        *(int*)(in_ECX + 0x1c) = iVar1;
        *(int*)(iVar1 + 4) = *(int*)(iVar1 + 4) + 1;
        return;
    }
    if (*(int*)(in_ECX + 0x1c) != 0) {
        FUN_005be1e0(*(uint32_t*)(*(int*)(in_ECX + 0x1c) + 8));
        *(uint32_t*)(in_ECX + 0x1c) = 0;
    }
}

// 0x5ca8f0 — observed shape
void FUN_005ca8f0_recon(uint32_t param_1)
{
    uint32_t uVar1 = FUN_005bf990(param_1);
    FUN_005d7e40(0, uVar1, 0);
    uint32_t extraout_EDX = FUN_005bf990(param_1);
    FUN_005d7e40(1, extraout_EDX, 0);
}

// 0x5ca940 — observed shape
void FUN_005ca940_recon(uint32_t param_1)
{
    uint8_t local_c[12];
    int iVar1 = FUN_005bf9b0(local_c, param_1);
    FUN_005d7e40(4, *(uint32_t*)(iVar1 + 4), 0);
    uint32_t* puVar2 = (uint32_t*)FUN_005bf9b0(local_c, param_1);
    FUN_005d7e40(5, *puVar2, 0);
    iVar1 = FUN_005bf9b0(local_c, param_1);
    FUN_005d7e40(6, *(uint32_t*)(iVar1 + 8), 0);
}

// 0x5ca9e0 — observed shape
int FUN_005ca9e0_recon(uint32_t param_1, float* param_2)
{
    extern float DAT_00728e38, DAT_00728e3c, _DAT_00728e40, _DAT_00728e44;
    extern float _DAT_00728e48, _DAT_00728e4c, _DAT_00728e50, _DAT_00728e54;
    extern float _DAT_00728e58, _DAT_00728e5c, _DAT_00728e60, _DAT_00728e64;
    extern float _DAT_00728e68, _DAT_00728e6c, _DAT_00728e70, _DAT_00728e74;
    float fVar1 = 0.0f;
    float fVar2 = 0.0f;
    switch (param_1) {
    case 1:
        DAT_00728e38 = *(float*)(DAT_00728e2c + 0x840) * *param_2 + param_2[4] * *(float*)(DAT_00728e2c + 0x844) + *(float*)(DAT_00728e2c + 0x848) * param_2[8];
        _DAT_00728e48 = *(float*)(DAT_00728e2c + 0x858) * param_2[8] + param_2[4] * *(float*)(DAT_00728e2c + 0x854) + *(float*)(DAT_00728e2c + 0x850) * *param_2;
        _DAT_00728e58 = *(float*)(DAT_00728e2c + 0x860) * *param_2 + *(float*)(DAT_00728e2c + 0x868) * param_2[8] + param_2[4] * *(float*)(DAT_00728e2c + 0x864);
        DAT_00728e3c = *(float*)(DAT_00728e2c + 0x840) * param_2[1] + *(float*)(DAT_00728e2c + 0x844) * param_2[5] + *(float*)(DAT_00728e2c + 0x848) * param_2[9];
        _DAT_00728e4c = *(float*)(DAT_00728e2c + 0x854) * param_2[5] + *(float*)(DAT_00728e2c + 0x858) * param_2[9] + *(float*)(DAT_00728e2c + 0x850) * param_2[1];
        _DAT_00728e5c = *(float*)(DAT_00728e2c + 0x860) * param_2[1] + *(float*)(DAT_00728e2c + 0x864) * param_2[5] + *(float*)(DAT_00728e2c + 0x868) * param_2[9];
        _DAT_00728e40 = *(float*)(DAT_00728e2c + 0x840) * param_2[2] + *(float*)(DAT_00728e2c + 0x844) * param_2[6] + *(float*)(DAT_00728e2c + 0x848) * param_2[10];
        _DAT_00728e50 = *(float*)(DAT_00728e2c + 0x854) * param_2[6] + *(float*)(DAT_00728e2c + 0x858) * param_2[10] + *(float*)(DAT_00728e2c + 0x850) * param_2[2];
        _DAT_00728e60 = *(float*)(DAT_00728e2c + 0x860) * param_2[2] + *(float*)(DAT_00728e2c + 0x864) * param_2[6] + *(float*)(DAT_00728e2c + 0x868) * param_2[10];
        _DAT_00728e68 = *(float*)(DAT_00728e2c + 0x878) * param_2[8] + param_2[4] * *(float*)(DAT_00728e2c + 0x874) + *(float*)(DAT_00728e2c + 0x870) * *param_2 + param_2[0xc];
        _DAT_00728e6c = *(float*)(DAT_00728e2c + 0x874) * param_2[5] + *(float*)(DAT_00728e2c + 0x878) * param_2[9] + *(float*)(DAT_00728e2c + 0x870) * param_2[1] + param_2[0xd];
        fVar1 = *(float*)(DAT_00728e2c + 0x878) * param_2[10] + *(float*)(DAT_00728e2c + 0x870) * param_2[2];
        fVar2 = *(float*)(DAT_00728e2c + 0x874) * param_2[6];
        break;
    case 2:
        DAT_00728e38 = *(float*)(DAT_00728e2c + 0x848) * param_2[8] + *(float*)(DAT_00728e2c + 0x840) * *param_2 + param_2[4] * *(float*)(DAT_00728e2c + 0x844);
        _DAT_00728e48 = *(float*)(DAT_00728e2c + 0x850) * *param_2 + *(float*)(DAT_00728e2c + 0x858) * param_2[8] + param_2[4] * *(float*)(DAT_00728e2c + 0x854);
        _DAT_00728e58 = *(float*)(DAT_00728e2c + 0x864) * param_2[4] + *param_2 * *(float*)(DAT_00728e2c + 0x860) + *(float*)(DAT_00728e2c + 0x868) * param_2[8];
        DAT_00728e3c = *(float*)(DAT_00728e2c + 0x848) * param_2[9] + *(float*)(DAT_00728e2c + 0x840) * param_2[1] + *(float*)(DAT_00728e2c + 0x844) * param_2[5];
        _DAT_00728e4c = *(float*)(DAT_00728e2c + 0x850) * param_2[1] + *(float*)(DAT_00728e2c + 0x854) * param_2[5] + *(float*)(DAT_00728e2c + 0x858) * param_2[9];
        _DAT_00728e5c = param_2[1] * *(float*)(DAT_00728e2c + 0x860) + *(float*)(DAT_00728e2c + 0x864) * param_2[5] + *(float*)(DAT_00728e2c + 0x868) * param_2[9];
        _DAT_00728e40 = *(float*)(DAT_00728e2c + 0x848) * param_2[10] + *(float*)(DAT_00728e2c + 0x840) * param_2[2] + *(float*)(DAT_00728e2c + 0x844) * param_2[6];
        _DAT_00728e50 = *(float*)(DAT_00728e2c + 0x850) * param_2[2] + *(float*)(DAT_00728e2c + 0x854) * param_2[6] + *(float*)(DAT_00728e2c + 0x858) * param_2[10];
        _DAT_00728e60 = param_2[2] * *(float*)(DAT_00728e2c + 0x860) + *(float*)(DAT_00728e2c + 0x864) * param_2[6] + *(float*)(DAT_00728e2c + 0x868) * param_2[10];
        _DAT_00728e68 = *(float*)(DAT_00728e2c + 0x874) * param_2[4] + *param_2 * *(float*)(DAT_00728e2c + 0x870) + *(float*)(DAT_00728e2c + 0x878) * param_2[8] + param_2[0xc];
        _DAT_00728e6c = param_2[1] * *(float*)(DAT_00728e2c + 0x870) + *(float*)(DAT_00728e2c + 0x874) * param_2[5] + *(float*)(DAT_00728e2c + 0x878) * param_2[9] + param_2[0xd];
        fVar1 = *(float*)(DAT_00728e2c + 0x874) * param_2[6] + *(float*)(DAT_00728e2c + 0x878) * param_2[10];
        fVar2 = param_2[2] * *(float*)(DAT_00728e2c + 0x870);
        break;
    case 3:
        DAT_00728e38 = *(float*)(DAT_00728e2c + 0x840) * *param_2 + *(float*)(DAT_00728e2c + 0x848) * param_2[8] + param_2[4] * *(float*)(DAT_00728e2c + 0x844);
        _DAT_00728e48 = *(float*)(DAT_00728e2c + 0x854) * param_2[4] + *param_2 * *(float*)(DAT_00728e2c + 0x850) + *(float*)(DAT_00728e2c + 0x858) * param_2[8];
        _DAT_00728e58 = *(float*)(DAT_00728e2c + 0x860) * *param_2 + *(float*)(DAT_00728e2c + 0x868) * param_2[8] + param_2[4] * *(float*)(DAT_00728e2c + 0x864);
        DAT_00728e3c = *(float*)(DAT_00728e2c + 0x844) * param_2[5] + *(float*)(DAT_00728e2c + 0x840) * param_2[1] + *(float*)(DAT_00728e2c + 0x848) * param_2[9];
        _DAT_00728e4c = param_2[1] * *(float*)(DAT_00728e2c + 0x850) + *(float*)(DAT_00728e2c + 0x854) * param_2[5] + *(float*)(DAT_00728e2c + 0x858) * param_2[9];
        _DAT_00728e5c = *(float*)(DAT_00728e2c + 0x860) * param_2[1] + *(float*)(DAT_00728e2c + 0x864) * param_2[5] + *(float*)(DAT_00728e2c + 0x868) * param_2[9];
        _DAT_00728e40 = *(float*)(DAT_00728e2c + 0x844) * param_2[6] + *(float*)(DAT_00728e2c + 0x840) * param_2[2] + *(float*)(DAT_00728e2c + 0x848) * param_2[10];
        _DAT_00728e50 = param_2[2] * *(float*)(DAT_00728e2c + 0x850) + *(float*)(DAT_00728e2c + 0x854) * param_2[6] + *(float*)(DAT_00728e2c + 0x858) * param_2[10];
        _DAT_00728e60 = *(float*)(DAT_00728e2c + 0x860) * param_2[2] + *(float*)(DAT_00728e2c + 0x864) * param_2[6] + *(float*)(DAT_00728e2c + 0x868) * param_2[10];
        _DAT_00728e68 = param_2[0xc];
        _DAT_00728e6c = param_2[0xd];
        _DAT_00728e70 = param_2[0xe];
        _DAT_00728e44 = 0; _DAT_00728e54 = 0; _DAT_00728e64 = 0; _DAT_00728e74 = 0;
        return 1;
    case 4:
        { float* puVar4 = &DAT_00728e38; for (int iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) { *puVar4 = 0; puVar4 = puVar4 + 1; } }
        _DAT_00728e4c = 0.5f; _DAT_00728e58 = 0.5f; _DAT_00728e68 = 0.5f; _DAT_00728e6c = 0.5f;
        return 1;
    case 5:
        DAT_00728e38 = *param_2 * *(float*)(DAT_00728e2c + 0x840) + *(float*)(DAT_00728e2c + 0x844) * param_2[4] + *(float*)(DAT_00728e2c + 0x848) * param_2[8];
        _DAT_00728e48 = *(float*)(DAT_00728e2c + 0x850) * *param_2 + *(float*)(DAT_00728e2c + 0x858) * param_2[8] + param_2[4] * *(float*)(DAT_00728e2c + 0x854);
        _DAT_00728e58 = *(float*)(DAT_00728e2c + 0x868) * param_2[8] + param_2[4] * *(float*)(DAT_00728e2c + 0x864) + *(float*)(DAT_00728e2c + 0x860) * *param_2;
        DAT_00728e3c = param_2[1] * *(float*)(DAT_00728e2c + 0x840) + *(float*)(DAT_00728e2c + 0x848) * param_2[9] + *(float*)(DAT_00728e2c + 0x844) * param_2[5];
        _DAT_00728e4c = *(float*)(DAT_00728e2c + 0x850) * param_2[1] + *(float*)(DAT_00728e2c + 0x854) * param_2[5] + *(float*)(DAT_00728e2c + 0x858) * param_2[9];
        _DAT_00728e5c = *(float*)(DAT_00728e2c + 0x864) * param_2[5] + *(float*)(DAT_00728e2c + 0x868) * param_2[9] + *(float*)(DAT_00728e2c + 0x860) * param_2[1];
        _DAT_00728e40 = param_2[2] * *(float*)(DAT_00728e2c + 0x840) + *(float*)(DAT_00728e2c + 0x848) * param_2[10] + *(float*)(DAT_00728e2c + 0x844) * param_2[6];
        _DAT_00728e50 = *(float*)(DAT_00728e2c + 0x850) * param_2[2] + *(float*)(DAT_00728e2c + 0x854) * param_2[6] + *(float*)(DAT_00728e2c + 0x858) * param_2[10];
        _DAT_00728e60 = *(float*)(DAT_00728e2c + 0x864) * param_2[6] + *(float*)(DAT_00728e2c + 0x868) * param_2[10] + *(float*)(DAT_00728e2c + 0x860) * param_2[2];
        _DAT_00728e68 = param_2[0xc]; _DAT_00728e6c = param_2[0xd]; _DAT_00728e70 = param_2[0xe];
        _DAT_00728e44 = 0; _DAT_00728e54 = 0; _DAT_00728e64 = 0; _DAT_00728e74 = 0;
        return 1;
    case 6:
        DAT_00728e38 = *(float*)(DAT_00728e2c + 0x848) * param_2[8] + *param_2 * *(float*)(DAT_00728e2c + 0x840) + param_2[4] * *(float*)(DAT_00728e2c + 0x844);
        _DAT_00728e48 = *(float*)(DAT_00728e2c + 0x850) * *param_2 + *(float*)(DAT_00728e2c + 0x858) * param_2[8] + param_2[4] * *(float*)(DAT_00728e2c + 0x854);
        _DAT_00728e58 = *(float*)(DAT_00728e2c + 0x864) * param_2[4] + *param_2 * *(float*)(DAT_00728e2c + 0x860) + *(float*)(DAT_00728e2c + 0x868) * param_2[8];
        DAT_00728e3c = *(float*)(DAT_00728e2c + 0x848) * param_2[9] + param_2[1] * *(float*)(DAT_00728e2c + 0x840) + *(float*)(DAT_00728e2c + 0x844) * param_2[5];
        _DAT_00728e4c = *(float*)(DAT_00728e2c + 0x850) * param_2[1] + *(float*)(DAT_00728e2c + 0x854) * param_2[5] + *(float*)(DAT_00728e2c + 0x858) * param_2[9];
        _DAT_00728e5c = param_2[1] * *(float*)(DAT_00728e2c + 0x860) + *(float*)(DAT_00728e2c + 0x864) * param_2[5] + *(float*)(DAT_00728e2c + 0x868) * param_2[9];
        _DAT_00728e40 = *(float*)(DAT_00728e2c + 0x848) * param_2[10] + param_2[2] * *(float*)(DAT_00728e2c + 0x840) + *(float*)(DAT_00728e2c + 0x844) * param_2[6];
        _DAT_00728e50 = *(float*)(DAT_00728e2c + 0x850) * param_2[2] + *(float*)(DAT_00728e2c + 0x854) * param_2[6] + *(float*)(DAT_00728e2c + 0x858) * param_2[10];
        _DAT_00728e60 = param_2[2] * *(float*)(DAT_00728e2c + 0x860) + *(float*)(DAT_00728e2c + 0x864) * param_2[6] + *(float*)(DAT_00728e2c + 0x868) * param_2[10];
        _DAT_00728e68 = param_2[0xc]; _DAT_00728e6c = param_2[0xd]; _DAT_00728e70 = param_2[0xe];
        _DAT_00728e44 = 0; _DAT_00728e54 = 0; _DAT_00728e64 = 0; _DAT_00728e74 = 0;
        return 1;
    default:
        return 0;
    }
    _DAT_00728e44 = 0; _DAT_00728e54 = 0; _DAT_00728e64 = 0;
    _DAT_00728e70 = fVar2 + fVar1 + param_2[0xe];
    _DAT_00728e74 = 0;
    return 1;
}

// 0x5cb2e0 — observed shape
void* FUN_005cb2e0_recon(void* self, uint8_t param_1)
{
    int in_ECX = (int)self;
    if ((param_1 & 2) == 0) {
        if (*(int*)(in_ECX + 0x1c) != 0) {
            FUN_005be1e0(*(uint32_t*)(*(int*)(in_ECX + 0x1c) + 8));
        }
        FUN_005d8350(*(uint32_t*)(in_ECX + 0xc));
        uint32_t* puVar2 = *(uint32_t**)(in_ECX + 4);
        if (puVar2 != nullptr) {
            int* piVar1 = (int*)puVar2 + 1;
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) {
                (*(void(**)(int))(*puVar2))(1);
            }
        }
        if ((param_1 & 1) != 0) {
            operator_delete(self);
        }
        return self;
    }
    int iVar3 = *(int*)(in_ECX - 4);
    if (-1 < iVar3 - 1) {
        int iVar4 = in_ECX + iVar3 * 0x68 + 0x1c;
        do {
            if (*(int*)(iVar4 - 0x68) != 0) {
                FUN_005be1e0(*(uint32_t*)(*(int*)(iVar4 - 0x68) + 8));
            }
            FUN_005d8350(*(uint32_t*)(iVar4 - 0x78));
            uint32_t* puVar2 = *(uint32_t**)(iVar4 - 0x80);
            if (puVar2 != nullptr) {
                int* piVar1 = (int*)puVar2 + 1;
                *piVar1 = *piVar1 - 1;
                if (*piVar1 == 0) {
                    (*(void(**)(int))(*puVar2))(1);
                }
            }
            iVar3 = iVar3 - 1;
            iVar4 = iVar4 - 0x68;
        } while (iVar3 != 0);
    }
    if ((param_1 & 1) != 0) {
        operator_delete__((void*)(in_ECX - 4));
    }
    return (void*)(in_ECX - 4);
}

// 0x5cb3a0 — observed shape
void FUN_005cb3a0_recon(void* self, int param_1)
{
    int* in_ECX = (int*)self;
    int* piVar2 = nullptr;
    in_ECX[1] = param_1;
    in_ECX[2] = 0;
    if (param_1 != 0) {
        int* piVar1 = (int*)thunk_FUN_00533c78(param_1 * 0x68 + 4);
        if (piVar1 != nullptr) {
            piVar2 = piVar1 + 1;
            *piVar1 = param_1;
            extern void* LAB_005ca860;
            FUN_004127b0(piVar2, 0x68, param_1, &LAB_005ca860);
        }
    }
    *in_ECX = (int)piVar2;
}

// 0x5cb3f0 — observed shape
void FUN_005cb3f0_recon(void)
{
    extern uint32_t* DAT_00728e34;
    DAT_00728e34 = (uint32_t*)FUN_00533c78(0x18);
    if (DAT_00728e34 == nullptr) {
        DAT_00728e34 = nullptr;
        return;
    }
    DAT_00728e34[0] = 0;
    DAT_00728e34[1] = 0;
    DAT_00728e34[2] = 0;
    DAT_00728e34[3] = 8;
    DAT_00728e34[4] = 8;
    DAT_00728e34[5] = 0;
}

// 0x5cb430 — observed shape
void FUN_005cb430_recon(void* self)
{
    int* in_ECX = (int*)self;
    if ((char)in_ECX[0x18] == '\0') {
        return;
    }
    uint32_t uVar1 = in_ECX[6];
    uint32_t uVar3 = uVar1 & 0xf0000000;
    int* piVar4 = nullptr;
    bool skipCall = false;
    if (uVar3 == 0) {
        piVar4 = in_ECX + 8;
    } else if (uVar3 == 0x10000000) {
        piVar4 = *(int**)(in_ECX[7] + 0x14);
        if ((uVar1 & 0xfffffff) != 0) {
            skipCall = false;
        }
    } else if (uVar3 == 0x20000000) {
        if ((uVar1 & 0xfffffff) == 0) {
            piVar4 = in_ECX + 8;
        } else {
            piVar4 = in_ECX + 8;
            char cVar2 = (char)FUN_005ca9e0(uVar1 & 0xfffffff, (float*)piVar4);
            if (cVar2 == '\0') {
                return;
            }
            extern float DAT_00728e38;
            piVar4 = (int*)&DAT_00728e38;
        }
    } else {
        return;
    }
    if (uVar3 == 0x10000000 && (uVar1 & 0xfffffff) != 0) {
        char cVar2 = (char)FUN_005ca9e0(uVar1 & 0xfffffff, (float*)piVar4);
        if (cVar2 == '\0') {
            return;
        }
        extern float DAT_00728e38;
        piVar4 = (int*)&DAT_00728e38;
    }
    if (!skipCall) {
        (*(void(**)(uint32_t, uint32_t, int*))(*(uint32_t*)DAT_00728e28 + 0xb0))(DAT_00728e28, *in_ECX + 0x10, piVar4);
    }
}

// 0x5cb4b0 — observed shape
void FUN_005cb4b0_recon(void* self, int param_1)
{
    uint32_t* in_ECX = (uint32_t*)self;
    uint32_t uVar1 = in_ECX[2];
    int iVar3 = 0;
    uint32_t uStack_4 = (uint32_t)in_ECX;
    if (uVar1 == 0) {
        iVar3 = in_ECX[1];
        (*(void(**)(uint32_t, int, uint32_t, uint8_t))(*(uint32_t*)DAT_00728e30 + 0xd4))(*in_ECX, 0xb, in_ECX[4], *(uint8_t*)((uint8_t*)in_ECX + 0x14));
    } else {
        uint32_t uVar2 = uVar1 & 0xf000000;
        int iVar4 = 0;
        bool hasVar4 = false;
        if (uVar2 == 0) {
            uVar2 = uVar1 & 0xf00000;
            if (uVar2 < 0x500001) {
                if (uVar2 == 0x500000) { iVar4 = *(int*)(*(int*)(param_1 + 0x2c) + 0xc); hasVar4 = true; }
                else if (uVar2 == 0x200000) { iVar4 = **(int**)(param_1 + 0x2c); hasVar4 = true; }
                else if (uVar2 == 0x300000) { iVar4 = *(int*)(*(int*)(param_1 + 0x2c) + 4); hasVar4 = true; }
                else if (uVar2 == 0x400000) { iVar4 = *(int*)(*(int*)(param_1 + 0x2c) + 8); hasVar4 = true; }
            } else if (uVar2 == 0x600000) { iVar4 = *(int*)(*(int*)(param_1 + 0x2c) + 0x10); hasVar4 = true; }
            else if (uVar2 == 0x700000) { iVar4 = *(int*)(*(int*)(param_1 + 0x2c) + 0x14); hasVar4 = true; }
        } else if (uVar2 == 0x1000000) {
            if ((uVar1 & 0xffff) < (uint32_t)(*(int*)(param_1 + 0x34) - 6)) {
                iVar4 = *(int*)(*(int*)(param_1 + 0x2c) + 0x18 + (uVar1 & 0xffff) * 4);
                hasVar4 = true;
            }
        } else if (uVar2 == 0x2000000) {
            if (*(int*)(param_1 + 0x44) != 0 && (uVar1 & 0xffff) < *(uint32_t*)(*(int*)(param_1 + 0x44) + 0xc)) {
                extern int FUN_004b1230(uint32_t);
                iVar4 = FUN_004b1230(uVar1 & 0xffff);
                hasVar4 = true;
            }
        }
        if (hasVar4 && iVar4 != 0) {
            iVar3 = *(int*)(iVar4 + 4);
            if ((uVar1 & 0xf0000000) == 0x10000000) {
                (*(void(**)(uint32_t, int, uint32_t, uint8_t))(*(uint32_t*)DAT_00728e30 + 0xd4))(*in_ECX, 0xb, (in_ECX[4] & 0xffff0000) | *(uint32_t*)(iVar4 + 0x10), *(uint8_t*)((uint8_t*)in_ECX + 0x14));
            }
        }
    }
    int iVar4 = 0;
    if (iVar3 != 0) {
        extern int* DAT_00728e2c;
        iVar4 = (*(int(**)(int, void*, int*))(*(int*)(*(int**)(DAT_00728e2c + 0x5d8) + 8))(iVar3, (void*)((int)&uStack_4 + 3), &param_1);
    }
    (*(void(**)(uint32_t, int))(*(uint32_t*)DAT_00728e30 + 0xec))(*in_ECX, iVar4);
    if (iVar4 != 0) {
        if ((char)uStack_4 == '\0') {
            FUN_005d7e40(6, 0, 0);
        }
        FUN_005cb430_recon(self);
    }
}

// 0x5cb660 — observed shape
void FUN_005cb660_recon(void* self, uint32_t param_1)
{
    int* in_ECX = (int*)self;
    int iVar1 = (int)thunk_FUN_00533c78(0xc);
    int iVar4 = 0;
    int* local_4 = nullptr;
    if (iVar1 != 0) {
        local_4 = (int*)FUN_005cb3a0_recon(nullptr, param_1);
    }
    uint32_t uVar3 = 0;
    if (param_1 != 0) {
        do {
            if (uVar3 < (uint32_t)local_4[1]) {
                iVar1 = *local_4 + iVar4;
            } else {
                iVar1 = 0;
            }
            int iVar2 = in_ECX[1];
            if (in_ECX[2] == (uint32_t)iVar2) {
                if (iVar2 == 0) { iVar2 = 1; } else { iVar2 = iVar2 * 2; }
                extern void FUN_0055f300(int);
                FUN_0055f300(iVar2);
            }
            *(int*)(*in_ECX + in_ECX[2] * 4) = iVar1;
            in_ECX[2] = in_ECX[2] + 1;
            uVar3 = uVar3 + 1;
            iVar4 = iVar4 + 0x68;
        } while (uVar3 < param_1);
    }
    local_4[2] = in_ECX[5];
    in_ECX[5] = (int)local_4;
}

// 0x5cb700 — observed shape
void FUN_005cb700_recon(void* self)
{
    int* in_ECX = (int*)self;
    if (*in_ECX != 0) {
        FUN_005cb2e0_recon(self, 3);
    }
    void* pvVar1 = (void*)in_ECX[2];
    if (pvVar1 != nullptr) {
        FUN_005cb700_recon(pvVar1);
        operator_delete(pvVar1);
    }
}

// 0x5cb730 — observed shape
void FUN_005cb730_recon(void)
{
    extern uint32_t* DAT_00728e34;
    uint32_t* puVar2 = DAT_00728e34;
    if (DAT_00728e34 != nullptr) {
        int* piVar1 = (int*)DAT_00728e34[5];
        DAT_00728e34[2] = 0;
        if (piVar1 != nullptr) {
            if (*piVar1 != 0) {
                FUN_005cb2e0_recon(piVar1, 3);
            }
            if (piVar1[2] != 0) {
                FUN_005ca7d0_recon(piVar1, 1);
            }
            operator_delete(piVar1);
        }
        operator_delete__((void*)*puVar2);
        operator_delete(puVar2);
    }
    DAT_00728e34 = nullptr;
}

// 0x5cb790 — observed shape
uint32_t FUN_005cb790_recon(void* self, uint32_t param_1, uint32_t param_2)
{
    int iVar1 = FUN_005cb4b0_recon(self, param_1) ? 0 : 0;
    extern int FUN_005d8110(uint32_t);
    iVar1 = FUN_005d8110(*(uint32_t*)self);
    if (iVar1 == 0) {
        FUN_005cb4b0_recon(self, param_2);
        return 1;
    }
    return 0;
}

// 0x5cb7c0 — observed shape
void FUN_005cb7c0_recon(void* self)
{
    uint32_t* in_ECX = (uint32_t*)self;
    if (*(char*)((int)in_ECX + 0x61) == '\0') {
        if (in_ECX[7] != 0) {
            FUN_005be1e0(*(uint32_t*)(in_ECX[7] + 8));
        }
        FUN_005d8350(in_ECX[3]);
        uint32_t* puVar2 = (uint32_t*)in_ECX[1];
        if (puVar2 != nullptr) {
            int* piVar1 = (int*)puVar2 + 1;
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) {
                (*(void(**)(int))(*puVar2))(1);
            }
        }
        operator_delete(in_ECX);
        return;
    }
    uint32_t* puVar2 = (uint32_t*)in_ECX[1];
    if (puVar2 != nullptr) {
        int* piVar1 = (int*)puVar2 + 1;
        *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) {
            (*(void(**)(int))(*puVar2))(1);
        }
        in_ECX[1] = 0;
    }
    extern void FUN_005d7f00(void);
    extern void FUN_005d7f30(void);
    FUN_005d7f00();
    FUN_005d7f30();
    if (in_ECX[7] != 0) {
        FUN_005be1e0(*(uint32_t*)(in_ECX[7] + 8));
    }
    in_ECX[7] = 0;
    *in_ECX = 0;
    in_ECX[2] = 0;
    in_ECX[6] = 0;
    in_ECX[4] = 0;
    *(uint8_t*)((uint8_t*)in_ECX + 0x14) = 0;
    *(uint8_t*)((uint8_t*)in_ECX + 0x60) = 0;
    uint8_t auStack_4[4];
    FUN_005bf090(auStack_4);
}
