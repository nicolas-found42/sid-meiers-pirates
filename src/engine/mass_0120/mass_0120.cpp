#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <windows.h>

extern void FUN_00534410(int param_1);
extern void FUN_00545d20();
extern void FUN_00534660(int param_1);
extern int FUN_00545630();
extern int FUN_00545600();
extern void FUN_00534810(int* param_1);
extern int FUN_00535540(int* param_1);
extern void FUN_005349d0();
extern void FUN_0053bd50(int param);
extern void FUN_00534d60(int param_1);
extern int FUN_00557b10(int param);
extern void FUN_005606f0(uint32_t a, int* b);
extern void FUN_006b34a0(int param);
extern int FUN_00557d40(const char* fmt, uint32_t val);
extern uint32_t* FUN_005580b0(void* a, void* b);
extern void FUN_00491640();
extern char* thunk_FUN_00533c78();
extern uint32_t DAT_0072743c;
extern uint32_t DAT_007177dc;
extern void* PTR_FUN_006c07e0;
extern void* PTR_FUN_006c07d4;

// 0x5356e0 — observed shape
void FUN_005356e0(void* self, int param_1)
{
    int iVar1 = (int)(intptr_t)self;
    FUN_00534410(param_1);
    if (*(uint32_t*)(iVar1 + 0x1c) < 0x4010000) {
        int count = param_1;
        int** vt = *(int***)(iVar1 + 0x15c);
        ((void(*)(int*, int))(*((void***)vt + 1)))(&count, 4);
        int iVar2 = 0;
        if (0 < count) {
            char buf[4];
            do {
                ((void(*)(char*, int))(*((void***)vt + 1)))(buf, 4);
                iVar2 = iVar2 + 1;
            } while (iVar2 < count);
        }
    }
    if (0xa00010d < *(uint32_t*)(iVar1 + 0x1c)) {
        FUN_00545d20();
    }
}

// 0x535750 — observed shape
void FUN_00535750(void* self, int param_1)
{
    uint8_t* selfBytes = (uint8_t*)self;
    FUN_00534660(param_1);
    if ((0xa00010d < *(uint32_t*)(param_1 + 0x1c)) && ((param_1 = FUN_00545630()), param_1 != 0)) {
        do {
            int iVar1 = FUN_00545600();
            if (iVar1 != 0) {
                using AllocFn = uint32_t* (*)();
                uint32_t* puVar2 = (uint32_t*)((AllocFn)(**(void***)((*(uint32_t**)(selfBytes + 0xd4)) + 1)))();
                puVar2[2] = (uint32_t)iVar1;
                puVar2[1] = 0;
                *puVar2 = *(uint32_t*)(selfBytes + 0xd8);
                if (*(int*)(selfBytes + 0xd8) == 0) {
                    *(uint32_t**)(selfBytes + 0xdc) = puVar2;
                } else {
                    *(uint32_t**)(*(int*)(selfBytes + 0xd8) + 4) = puVar2;
                }
                *(uint32_t**)(selfBytes + 0xd8) = puVar2;
                *(int*)(selfBytes + 0xe0) = *(int*)(selfBytes + 0xe0) + 1;
            }
            param_1 = param_1 + -1;
        } while (param_1 != 0);
    }
}

// 0x5357d0 — observed shape
void FUN_005357d0(void* self, int* param_1)
{
    uint8_t* selfBytes = (uint8_t*)self;
    int* piVar2 = param_1;
    FUN_00534810(param_1);
    int count;
    int vt1 = *(int*)((char*)piVar2 + 0x58 * 4);
    ((void(*)(int*, int))(*(void**)(*(int*)vt1 + 0xc)))(&count, 4);
    if ((0 < 0) && (*(int*)(selfBytes + 0xdc) != 0)) {
    }
    int iVar3 = *(int*)(selfBytes + 0xdc);
    if (iVar3 != 0) {
        uint8_t* cur = (uint8_t*)iVar3;
        // unaff_ESI is unknown; guard loop mirrors original condition structure
        do {
            uint32_t val = *(uint32_t*)(cur + 8);
            int next = *(int*)(cur + 4);
            int vtable = *(int*)piVar2;
            ((void(*)(uint32_t))(*(void**)(vtable + 0x2c)))(val);
            cur = (uint8_t*)next;
            iVar3 = next;
        } while (iVar3 != 0);
    }
}

// 0x535830 — observed shape
int FUN_00535830(void* self, int* param_1)
{
    uint8_t* selfBytes = (uint8_t*)self;
    int* piVar3 = nullptr;
    if (*(int**)(selfBytes + 4) != nullptr) {
        piVar3 = *(int**)(selfBytes + 4);
        do {
            int* piVar1 = (int*)*piVar3;
            if (*param_1 == piVar3[2]) goto found;
            piVar3 = piVar1;
        } while (piVar3 != nullptr);
    }
    piVar3 = nullptr;
found:
    if (piVar3 == nullptr) {
        return *param_1;
    }
    param_1 = piVar3;
    return FUN_00535540(reinterpret_cast<int*>(&param_1));
}

// 0x535880 — observed shape
void FUN_00535880(void* self)
{
    uint32_t* in_ECX = (uint32_t*)self;
    FUN_005349d0();
    *in_ECX = (uint32_t)(intptr_t)PTR_FUN_006c07e0;
    in_ECX[0x34] = 0;
    in_ECX[0x32] = 0;
    in_ECX[0x33] = 0;
    in_ECX[0x31] = (uint32_t)(intptr_t)PTR_FUN_006c07d4;
    in_ECX[0x35] = (uint32_t)(intptr_t)PTR_FUN_006c07d4;
    in_ECX[0x38] = 0;
    in_ECX[0x36] = 0;
    in_ECX[0x37] = 0;
    *(uint8_t*)((uint8_t*)in_ECX + 0x2d * 4) = 1;
    in_ECX[0x2e] = DAT_007177dc;
    DAT_007177dc = DAT_007177dc + 1;
    in_ECX[0x2f] = 0;
    in_ECX[0x30] = 1;
}
// 0x535920 — observed shape
void FUN_00535920(void* self, int param_1)
{
    uint8_t* selfBytes = (uint8_t*)self;
    int* piVar2 = *(int**)(selfBytes + 200);
    if (piVar2 != nullptr) {
        int* piVar1 = nullptr;
        while ((piVar1 = (int*)*piVar2), param_1 != piVar2[2]) {
            piVar2 = piVar1;
            if (piVar1 == nullptr) {
                return;
            }
        }
        if (piVar2 != nullptr) {
            FUN_00535830(self, &param_1);
            FUN_0053bd50((int)(intptr_t)self);
        }
    }
}

// 0x535970 — observed shape
void FUN_00535970(void* self, int param_1)
{
    (void)self;
    uint8_t* selfBytes = (uint8_t*)self;
    int iVar4 = param_1;
    FUN_00534d60(param_1);
    param_1 = FUN_00557b10((int)DAT_0072743c);
    uint32_t uVar1 = *(uint32_t*)(iVar4 + 0xc);
    if (*(uint32_t*)(iVar4 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar4 + 0x14) + (int)uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
    if (*(int*)(selfBytes + 0xd0) != 0) {
        char local_40[64];
        uint32_t* puVar2 = *(uint32_t**)(selfBytes + 200);
        param_1 = 0;
        while (puVar2 != nullptr) {
            uint32_t uVar3 = puVar2[2];
            puVar2 = (uint32_t*)*puVar2;
            sprintf(local_40, "affected node[%d]", param_1);
            int iVar5 = FUN_00557d40(local_40, uVar3);
            uVar1 = *(uint32_t*)(iVar4 + 0xc);
            if ((uVar1 < *(uint32_t*)(iVar4 + 8)) ||
                (FUN_006b34a0(*(int*)(iVar4 + 0x14) + (int)uVar1), uVar1 < *(uint32_t*)(iVar4 + 8))) {
                if (uVar1 < *(uint32_t*)(iVar4 + 0xc)) {
                    if (iVar5 == 0) {
                        if (*(int*)(*(int*)(iVar4 + 4) + uVar1 * 4) != 0) {
                            int iVar6 = *(int*)(iVar4 + 0x10) + -1;
                            goto LAB_00535a5f;
                        }
                    } else if (*(int*)(*(int*)(iVar4 + 4) + uVar1 * 4) == 0) {
                        int iVar6 = *(int*)(iVar4 + 0x10) + 1;
LAB_00535a5f:
                        *(int*)(iVar4 + 0x10) = iVar6;
                    }
                } else {
                    *(uint32_t*)(iVar4 + 0xc) = uVar1 + 1;
                    if (iVar5 != 0) {
                        int iVar6 = *(int*)(iVar4 + 0x10) + 1;
                        goto LAB_00535a5f;
                    }
                }
                *(int*)(*(int*)(iVar4 + 4) + uVar1 * 4) = iVar5;
            }
            param_1 = param_1 + 1;
        }
        puVar2 = *(uint32_t**)(selfBytes + 0xd8);
        while (puVar2 != nullptr) {
            uint32_t uVar3 = puVar2[2];
            puVar2 = (uint32_t*)*puVar2;
            sprintf(local_40, "unaffected node[%d]", param_1);
            int iVar5 = FUN_00557d40(local_40, uVar3);
            uVar1 = *(uint32_t*)(iVar4 + 0xc);
            if ((uVar1 < *(uint32_t*)(iVar4 + 8)) ||
                (FUN_006b34a0(*(int*)(iVar4 + 0x14) + (int)uVar1), uVar1 < *(uint32_t*)(iVar4 + 8))) {
                if (uVar1 < *(uint32_t*)(iVar4 + 0xc)) {
                    if (iVar5 == 0) {
                        if (*(int*)(*(int*)(iVar4 + 4) + uVar1 * 4) != 0) {
                            int iVar6 = *(int*)(iVar4 + 0x10) + -1;
                            goto LAB_00535b0e;
                        }
                    } else if (*(int*)(*(int*)(iVar4 + 4) + uVar1 * 4) == 0) {
                        int iVar6 = *(int*)(iVar4 + 0x10) + 1;
LAB_00535b0e:
                        *(int*)(iVar4 + 0x10) = iVar6;
                    }
                } else {
                    *(uint32_t*)(iVar4 + 0xc) = uVar1 + 1;
                    if (iVar5 != 0) {
                        int iVar6 = *(int*)(iVar4 + 0x10) + 1;
                        goto LAB_00535b0e;
                    }
                }
                *(int*)(*(int*)(iVar4 + 4) + uVar1 * 4) = iVar5;
            }
            param_1 = param_1 + 1;
        }
    }
}

// 0x535b40 — observed shape
uint32_t FUN_00535b40(void* self, float* param_1, float* param_2, float* param_3)
{
    uint8_t* selfBytes = (uint8_t*)self;
    float fVar1 = param_1[0];
    float fVar2 = param_1[1];
    float fVar3 = param_1[2];
    float fVar4 = fVar1 * *(float*)(selfBytes + 0xe8) +
                  fVar2 * *(float*)(selfBytes + 0xec) + fVar3 * *(float*)(selfBytes + 0xf0) +
                  *(float*)(selfBytes + 0xf4);
    if (fVar4 < 1e-05f || fVar4 == 1e-05f) {
        uint32_t flags = (uint32_t)((fVar4 < 1e-05f) ? 1 : 0) << 8;
    }
    *param_2 = fVar1 * *(float*)(selfBytes + 0xb8) +
               fVar2 * *(float*)(selfBytes + 0xbc) + fVar3 * *(float*)(selfBytes + 0xc0) +
               *(float*)(selfBytes + 0xc4);
    *param_3 = fVar1 * *(float*)(selfBytes + 200) +
               fVar2 * *(float*)(selfBytes + 0xcc) + fVar3 * *(float*)(selfBytes + 0xd0) +
               *(float*)(selfBytes + 0xd4);
    *param_2 = (1.0f / fVar4) * *param_2;
    fVar2 = (1.0f / fVar4) * *param_3;
    *param_3 = fVar2;
    fVar1 = *param_2;
    if (fVar1 >= -1.0f) {
        fVar1 = *param_2;
        if (fVar1 < 1.0f) {
            if (fVar2 >= -1.0f) {
                if (fVar2 < 1.0f) {
                    *param_2 = (*(float*)(selfBytes + 0x148) - *(float*)(selfBytes + 0x144)) * *param_2 * 0.5f;
                    *param_3 = (*(float*)(selfBytes + 0x14c) - *(float*)(selfBytes + 0x150)) * *param_3 * 0.5f;
                    *param_2 = (*(float*)(selfBytes + 0x144) + *(float*)(selfBytes + 0x148)) * 0.5f + *param_2;
                    *param_3 = (*(float*)(selfBytes + 0x150) + *(float*)(selfBytes + 0x14c)) * 0.5f + *param_3;
                    return 1;
                }
            }
        }
    }
    return 0;
}

// 0x535cc0 — observed shape
uint32_t FUN_00535cc0(void* self, float param_1, float param_2, float* param_3, float* param_4)
{
    uint8_t* selfBytes = (uint8_t*)self;
    float fVar1 = *(float*)(selfBytes + 0x150);
    float fVar2 = *(float*)(selfBytes + 0x14c);
    float fVar3 = *(float*)(selfBytes + 0x150);
    *param_3 = (*(float*)(selfBytes + 300) - *(float*)(selfBytes + 0x128)) *
               ((param_1 - *(float*)(selfBytes + 0x144)) /
               (*(float*)(selfBytes + 0x148) - *(float*)(selfBytes + 0x144))) + *(float*)(selfBytes + 0x128);
    *param_4 = (*(float*)(selfBytes + 0x130) - *(float*)(selfBytes + 0x134)) *
               ((param_2 - fVar1) / (fVar2 - fVar3)) + *(float*)(selfBytes + 0x134);
    fVar1 = *(float*)(selfBytes + 0x148);
    if (param_1 < fVar1 || param_1 == fVar1) {
        fVar1 = *(float*)(selfBytes + 0x144);
        if (param_1 >= fVar1) {
            fVar1 = *(float*)(selfBytes + 0x14c);
            if (param_2 < fVar1 || param_2 == fVar1) {
                fVar1 = *(float*)(selfBytes + 0x150);
                if (param_2 >= fVar1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// 0x535d80 — observed shape
char* FUN_00535d80(void* self, char* param_1)
{
    float* in_ECX = (float*)self;
    char* pcVar2 = param_1;
    char cVar1;
    do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = thunk_FUN_00533c78();
    sprintf(pcVar2, "%s = (L=%g,R=%g,T=%g,B=%g)", param_1, (double)in_ECX[0], (double)in_ECX[1],
            (double)in_ECX[2], (double)in_ECX[3]);
    return pcVar2;
}
// 0x535de0 — observed shape
void FUN_00535de0(void* self, uint32_t param_1)
{
    uint8_t* selfBytes = (uint8_t*)self;
    if (*(int**)(selfBytes + 0x188) != nullptr) {
        void** vtable = *(void***)(selfBytes + 0x188);
        ((void(*)(void*, uint32_t))vtable[0x48 / 4])(selfBytes + 0x144, param_1);
    }
}

// 0x535e20 — observed shape
void FUN_00535e20(void* self, float param_1)
{
    uint8_t* selfBytes = (uint8_t*)self;
    float local_28 = *(float*)(selfBytes + 0x104);
    float local_24 = *(float*)(selfBytes + 0x108);
    float local_20 = *(float*)(selfBytes + 0x10c);
    float local_1c = local_24 * *(float*)(selfBytes + 0x118) - local_20 * *(float*)(selfBytes + 0x114);
    float local_18 = local_20 * *(float*)(selfBytes + 0x110) - local_28 * *(float*)(selfBytes + 0x118);
    float local_14 = local_28 * *(float*)(selfBytes + 0x114) - local_24 * *(float*)(selfBytes + 0x110);
    FUN_00491640();
    float local_8 = param_1 * *(float*)(selfBytes + 0x124);
    local_28 = param_1 * *(float*)(selfBytes + 0x11c) + *(float*)(selfBytes + 0x90);
    local_24 = param_1 * *(float*)(selfBytes + 0x120) + *(float*)(selfBytes + 0x94);
    local_20 = local_8 + *(float*)(selfBytes + 0x98);
    uint32_t* puVar1 = FUN_005580b0(&local_1c, &local_28);
    *(uint32_t*)(selfBytes + 0x1ac) = puVar1[0];
    *(uint32_t*)(selfBytes + 0x1b0) = puVar1[1];
    *(uint32_t*)(selfBytes + 0x1b4) = puVar1[2];
    *(uint32_t*)(selfBytes + 0x1b8) = puVar1[3];
}

// 0x535f20 — observed shape
void FUN_00535f20(void* self, float param_1)
{
    uint8_t* selfBytes = (uint8_t*)self;
    float local_28 = *(float*)(selfBytes + 0x104);
    float local_24 = *(float*)(selfBytes + 0x108);
    float local_20 = *(float*)(selfBytes + 0x10c);
    local_28 = local_28;
    // negated cross product components
    float v118 = *(float*)(selfBytes + 0x118);
    float v114 = *(float*)(selfBytes + 0x114);
    float v110 = *(float*)(selfBytes + 0x110);
    float local_1c = local_24 * -v118 - local_20 * -v114;
    float local_18 = local_20 * -v110 - -v118 * local_28;
    float local_14 = local_28 * -v114 - local_24 * -v110;
    FUN_00491640();
    float local_8 = param_1 * *(float*)(selfBytes + 0x124);
    local_28 = param_1 * *(float*)(selfBytes + 0x11c) + *(float*)(selfBytes + 0x90);
    local_24 = param_1 * *(float*)(selfBytes + 0x120) + *(float*)(selfBytes + 0x94);
    local_20 = local_8 + *(float*)(selfBytes + 0x98);
    uint32_t* puVar1 = FUN_005580b0(&local_1c, &local_28);
    *(uint32_t*)(selfBytes + 0x1bc) = puVar1[0];
    *(uint32_t*)(selfBytes + 0x1c0) = puVar1[1];
    *(uint32_t*)(selfBytes + 0x1c4) = puVar1[2];
    *(uint32_t*)(selfBytes + 0x1c8) = puVar1[3];
}

// 0x536020 — observed shape
void FUN_00536020(void* self, float param_1)
{
    uint8_t* selfBytes = (uint8_t*)self;
    float local_28 = *(float*)(selfBytes + 0x104);
    float local_24 = *(float*)(selfBytes + 0x108);
    float local_20 = *(float*)(selfBytes + 0x10c);
    float local_1c = local_24 * *(float*)(selfBytes + 0x124) - local_20 * *(float*)(selfBytes + 0x120);
    float local_18 = local_20 * *(float*)(selfBytes + 0x11c) - local_28 * *(float*)(selfBytes + 0x124);
    float local_14 = local_28 * *(float*)(selfBytes + 0x120) - local_24 * *(float*)(selfBytes + 0x11c);
    FUN_00491640();
    float local_8 = param_1 * *(float*)(selfBytes + 0x118);
    local_28 = param_1 * *(float*)(selfBytes + 0x110) + *(float*)(selfBytes + 0x90);
    local_24 = param_1 * *(float*)(selfBytes + 0x114) + *(float*)(selfBytes + 0x94);
    local_20 = local_8 + *(float*)(selfBytes + 0x98);
    uint32_t* puVar1 = FUN_005580b0(&local_1c, &local_28);
    *(uint32_t*)(selfBytes + 0x1cc) = puVar1[0];
    *(uint32_t*)(selfBytes + 0x1d0) = puVar1[1];
    *(uint32_t*)(selfBytes + 0x1d4) = puVar1[2];
    *(uint32_t*)(selfBytes + 0x1d8) = puVar1[3];
}

// 0x536120 — observed shape
void FUN_00536120(void* self, float param_1)
{
    uint8_t* selfBytes = (uint8_t*)self;
    float local_28 = *(float*)(selfBytes + 0x104);
    float local_24 = *(float*)(selfBytes + 0x108);
    float local_20 = *(float*)(selfBytes + 0x10c);
    float v124 = *(float*)(selfBytes + 0x124);
    float v120 = *(float*)(selfBytes + 0x120);
    float v11c = *(float*)(selfBytes + 0x11c);
    float local_1c = local_24 * -v124 - local_20 * -v120;
    float local_18 = local_20 * -v11c - -v124 * local_28;
    float local_14 = local_28 * -v120 - local_24 * -v11c;
    FUN_00491640();
    float local_8 = param_1 * *(float*)(selfBytes + 0x118);
    local_28 = param_1 * *(float*)(selfBytes + 0x110) + *(float*)(selfBytes + 0x90);
    local_24 = param_1 * *(float*)(selfBytes + 0x114) + *(float*)(selfBytes + 0x94);
    local_20 = local_8 + *(float*)(selfBytes + 0x98);
    uint32_t* puVar1 = FUN_005580b0(&local_1c, &local_28);
    *(uint32_t*)(selfBytes + 0x1dc) = puVar1[0];
    *(uint32_t*)(selfBytes + 0x1e0) = puVar1[1];
    *(uint32_t*)(selfBytes + 0x1e4) = puVar1[2];
    *(uint32_t*)(selfBytes + 0x1e8) = puVar1[3];
}
// 0x536220 — observed shape
void FUN_00536220(void* self, float param_1)
{
    uint8_t* selfBytes = (uint8_t*)self;
    float local_8 = param_1 * *(float*)(selfBytes + 0x10c);
    float local_1c = param_1 * *(float*)(selfBytes + 0x104) + *(float*)(selfBytes + 0x90);
    float local_18 = param_1 * *(float*)(selfBytes + 0x108) + *(float*)(selfBytes + 0x94);
    float local_14 = local_8 + *(float*)(selfBytes + 0x98);
    uint32_t* puVar1 = FUN_005580b0(selfBytes + 0x104, &local_1c);
    *(uint32_t*)(selfBytes + 0x18c) = puVar1[0];
    *(uint32_t*)(selfBytes + 400) = puVar1[1];
    *(uint32_t*)(selfBytes + 0x194) = puVar1[2];
    *(uint32_t*)(selfBytes + 0x198) = puVar1[3];
}

// 0x5362a0 — observed shape
void FUN_005362a0(void* self, float param_1)
{
    uint8_t* selfBytes = (uint8_t*)self;
    float local_28 = param_1 * *(float*)(selfBytes + 0x104) + *(float*)(selfBytes + 0x90);
    float local_24 = param_1 * *(float*)(selfBytes + 0x108) + *(float*)(selfBytes + 0x94);
    float local_20 = param_1 * *(float*)(selfBytes + 0x10c) + *(float*)(selfBytes + 0x98);
    float local_1c = -*(float*)(selfBytes + 0x104);
    float local_18 = -*(float*)(selfBytes + 0x108);
    float local_14 = -*(float*)(selfBytes + 0x10c);
    uint32_t* puVar1 = FUN_005580b0(&local_1c, &local_28);
    *(uint32_t*)(selfBytes + 0x19c) = puVar1[0];
    *(uint32_t*)(selfBytes + 0x1a0) = puVar1[1];
    *(uint32_t*)(selfBytes + 0x1a4) = puVar1[2];
    *(uint32_t*)(selfBytes + 0x1a8) = puVar1[3];
}

// 0x536350 — observed shape
void FUN_00536350(void* self, float param_1)
{
    uint8_t* selfBytes = (uint8_t*)self;
    float local_10 = param_1 * *(float*)(selfBytes + 0x11c) + *(float*)(selfBytes + 0x104);
    float fVar1 = param_1 * *(float*)(selfBytes + 0x120) + *(float*)(selfBytes + 0x108);
    float fVar2 = param_1 * *(float*)(selfBytes + 0x124) + *(float*)(selfBytes + 0x10c);
    float local_1c = fVar1 * *(float*)(selfBytes + 0x118) - fVar2 * *(float*)(selfBytes + 0x114);
    float local_18 = fVar2 * *(float*)(selfBytes + 0x110) - local_10 * *(float*)(selfBytes + 0x118);
    float local_14 = local_10 * *(float*)(selfBytes + 0x114) - fVar1 * *(float*)(selfBytes + 0x110);
    FUN_00491640();
    uint32_t* puVar3 = FUN_005580b0(&local_1c, selfBytes + 0x90);
    *(uint32_t*)(selfBytes + 0x1ac) = puVar3[0];
    *(uint32_t*)(selfBytes + 0x1b0) = puVar3[1];
    *(uint32_t*)(selfBytes + 0x1b4) = puVar3[2];
    *(uint32_t*)(selfBytes + 0x1b8) = puVar3[3];
}

// 0x536420 — observed shape
void FUN_00536420(void* self, float param_1)
{
    uint8_t* selfBytes = (uint8_t*)self;
    float local_10 = param_1 * *(float*)(selfBytes + 0x11c) + *(float*)(selfBytes + 0x104);
    float fVar1 = param_1 * *(float*)(selfBytes + 0x120) + *(float*)(selfBytes + 0x108);
    float fVar2 = param_1 * *(float*)(selfBytes + 0x124) + *(float*)(selfBytes + 0x10c);
    float v118 = *(float*)(selfBytes + 0x118);
    float v114 = *(float*)(selfBytes + 0x114);
    float v110 = *(float*)(selfBytes + 0x110);
    float local_1c = -v118 * fVar1 - -v114 * fVar2;
    float local_18 = fVar2 * -v110 - -v118 * local_10;
    float local_14 = -v114 * local_10 - fVar1 * -v110;
    FUN_00491640();
    uint32_t* puVar3 = FUN_005580b0(&local_1c, selfBytes + 0x90);
    *(uint32_t*)(selfBytes + 0x1bc) = puVar3[0];
    *(uint32_t*)(selfBytes + 0x1c0) = puVar3[1];
    *(uint32_t*)(selfBytes + 0x1c4) = puVar3[2];
    *(uint32_t*)(selfBytes + 0x1c8) = puVar3[3];
}

// 0x536500 — observed shape
void FUN_00536500(void* self, float param_1)
{
    uint8_t* selfBytes = (uint8_t*)self;
    float local_10 = param_1 * *(float*)(selfBytes + 0x110) + *(float*)(selfBytes + 0x104);
    float fVar1 = param_1 * *(float*)(selfBytes + 0x114) + *(float*)(selfBytes + 0x108);
    float fVar2 = param_1 * *(float*)(selfBytes + 0x118) + *(float*)(selfBytes + 0x10c);
    float local_1c = fVar1 * *(float*)(selfBytes + 0x124) - fVar2 * *(float*)(selfBytes + 0x120);
    float local_18 = fVar2 * *(float*)(selfBytes + 0x11c) - local_10 * *(float*)(selfBytes + 0x124);
    float local_14 = local_10 * *(float*)(selfBytes + 0x120) - fVar1 * *(float*)(selfBytes + 0x11c);
    FUN_00491640();
    uint32_t* puVar3 = FUN_005580b0(&local_1c, selfBytes + 0x90);
    *(uint32_t*)(selfBytes + 0x1cc) = puVar3[0];
    *(uint32_t*)(selfBytes + 0x1d0) = puVar3[1];
    *(uint32_t*)(selfBytes + 0x1d4) = puVar3[2];
    *(uint32_t*)(selfBytes + 0x1d8) = puVar3[3];
}
