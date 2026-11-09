#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_005aefa0(void);
extern void FUN_004aac50(undefined4 *param_1);
extern void FUN_005af2a0(int *param_1, undefined4 *param_2);
extern void FUN_006b37c0(undefined4 *param_1);
extern void FUN_00545310(undefined4 param_1, undefined4 *param_2);
extern void thunk_FUN_0053e500(int param_1, undefined4 param_2);
extern void FUN_005af3b0(undefined4 param_1);
extern void FUN_00545630(void);
extern void FUN_00545600(void);
extern void thunk_FUN_0053eca0(undefined4 param_1);

typedef unsigned int undefined4;
typedef unsigned char undefined1;
typedef unsigned char byte_;

// 0x5af310 — observed shape
void FUN_005af310(void* self, float param_1) {
    int* piVar1;
    int* piVar2;
    undefined4* puVar3;
    piVar2 = *(int**)((char*)self + 0xbc);
    (**(void(**)())(*piVar2 + 0x44))();
    if ((*(char*)((char*)self + 0xf8) != '\0') || (param_1 < *(float*)((char*)self + 0xf4))) {
        FUN_005aefa0();
        *(undefined1*)((char*)self + 0xf8) = 0;
    }
    if (*(float*)((char*)self + 0xf4) == -3.4028235e+38f) {
        *(float*)((char*)self + 0xf4) = param_1;
    }
    puVar3 = *(undefined4**)((char*)self + 0xd4);
    while (puVar3 != (undefined4*)0x0) {
        piVar1 = (int*)(puVar3 + 2);
        puVar3 = (undefined4*)*puVar3;
        if ((char)((int*)*piVar1)[6] != '\0') {
            (**(void(**)(float, int*))(*(int*)*piVar1 + 0x34))(param_1, piVar2);
        }
    }
    *(byte_*)((int)piVar2 + 0x32) = *(byte_*)((int)piVar2 + 0x32) | 7;
    *(float*)((char*)self + 0xf4) = param_1;
}

// 0x5af3b0 — observed shape
void FUN_005af3b0(void* self, undefined4* param_1) {
    undefined4* puVar1;
    int* piVar2;
    puVar1 = param_1;
    piVar2 = *(int**)((char*)self + 0xd4);
    if (piVar2 == (int*)0x0) {
        if (param_1 != (undefined4*)0x0) {
            param_1[1] = param_1[1] + 1;
        }
        FUN_004aac50(&param_1);
        if (puVar1 != (undefined4*)0x0) {
            piVar2 = (int*)(puVar1 + 1);
            *piVar2 = *piVar2 + -1;
            if (*piVar2 == 0) {
                (**(void(**)(int))include*puVar1)(1);
            }
        }
    } else {
        do {
            if ((uint)param_1[4] < *(uint*)(piVar2[2] + 0x10)) {
                param_1[1] = param_1[1] + 1;
                FUN_005af2a0(piVar2, &param_1);
                goto LAB_005af41d;
            }
            piVar2 = (int*)*piVar2;
        } while (piVar2 != (int*)0x0);
        param_1[1] = param_1[1] + 1;
        FUN_006b37c0(&param_1);
LAB_005af41d:
        piVar2 = (int*)(puVar1 + 1);
        *piVar2 = *piVar2 + -1;
        if (*piVar2 == 0) {
            (**(void(**)(int))include*puVar1)(1);
        }
    }
    FUN_00545310(puVar1[3], puVar1);
    puVar1[5] = (undefined4)self;
}

// 0x5af470 — observed shape
void FUN_005af470(int param_1, undefined4 param_2) {
    int* piVar1;
    undefined4* puVar2;
    undefined4* puVar3;
    undefined4* puVar4;
    int* piVar5;
    piVar5 = (int*)0;
    thunk_FUN_0053e500(param_1, param_2);
}

// 0x5af590 — observed shape
void FUN_005af590(undefined4 param_1) {
    int iVar1;
    undefined4 uVar2;
    thunk_FUN_0053eca0(param_1);
    FUN_00545630();
}

// 0x5af5d0 — observed shape
void FUN_005af5d0(int param_1) {
    FUN_0053a8f0(param_1);
}

extern void FUN_005aeb40(void);
extern void operator_delete(void* ptr);
extern void FUN_005aec90(void);
extern void FUN_0053e670(void);
extern void FUN_0053a790(void);
extern void* thunk_FUN_00533c78(uint32_t size);
extern int FUN_00533c78(uint32_t size);
extern void FUN_005bbd20(void);
extern void FUN_005bbeb0(int param_1, undefined4 param_2);
extern void FUN_005bbf20(int param_1);
extern void FUN_005bbf80(int param_1);
extern uint FUN_005bbd90(int param_1);
extern void FUN_005bbfe0(int param_1);
extern uint FUN_0050b0f0(int param_1);
extern void FUN_005aecb0(uint param_1);
extern void FUN_00535190(int param_1);
extern void FUN_005351e0(int param_1);
extern void FUN_005606f0(uint index, undefined4* value);
extern int FUN_00557b10(undefined4 param_1);
extern int FUN_00557cf0(const char* name, undefined4 value);
extern int FUN_005350b0(const char* name);
extern void FUN_006b34a0(int param_1);
extern void thunk_FUN_00553060(undefined4 param_1);
extern uint16_t FUN_005f0ddc(void);
extern void FUN_0055f300(int param_1);
extern int FUN_005b8030(undefined4 a, undefined4 b, undefined4 c, undefined4 d, undefined4 e);
extern const char DAT_00728b98[];
extern undefined4 DAT_0071779c;
extern undefined4 DAT_007177a0;
extern undefined4 DAT_007177a4;
extern undefined4 DAT_007177a8;
extern float DAT_007177ac;
extern float DAT_007177b0;
extern float DAT_007177b4;
extern undefined1 DAT_007284e8;
extern undefined4 PTR_FUN_006c5a90;
extern undefined4 PTR_FUN_006c5a40;
extern undefined4 PTR_FUN_006c5a24;
extern undefined4 PTR_FUN_006c5a68;
extern undefined4 PTR_FUN_006c5b18;

typedef long double float10;
extern "C" int rand(void);
extern "C" float10 fsin(float10 value);
extern "C" float10 fcos(float10 value);

// 0x5af680 — observed shape
void FUN_005af680(void* self, byte param_1) {
    FUN_005aeb40();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x5af6b0 — observed shape
void FUN_005af6b0(void* self, byte param_1) {
    FUN_005aeb40();
    FUN_005aec90();
    FUN_0053e670();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x5af6f0 — observed shape
void FUN_005af6f0(void* self) {
    undefined4* puVar1;
    undefined4 uVar2;
    int iVar3;

    FUN_0053a790();
    *(undefined4*)((char*)self + 0x0) = (undefined4)&PTR_FUN_006c5a90;
    *(undefined1*)((char*)self + 0xcc) = 1;
    *(undefined4*)((char*)self + 0xdc) = 0;
    *(undefined4*)((char*)self + 0xd4) = 0;
    *(undefined4*)((char*)self + 0xd8) = 0;
    *(undefined4*)((char*)self + 0xd0) = (undefined4)&PTR_FUN_006c5a40;
    *(undefined4*)((char*)self + 0xe0) = (undefined4)&PTR_FUN_006c5a24;
    *(undefined4*)((char*)self + 0xe4) = 0x25;
    *(undefined4*)((char*)self + 0xec) = 0;
    puVar1 = (undefined4*)thunk_FUN_00533c78(0x94);
    *(undefined4*)((char*)self + 0xe8) = (undefined4)puVar1;
    for (uVar2 = *(undefined4*)((char*)self + 0xe4) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar1 = 0;
        puVar1 = puVar1 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined1*)puVar1 = 0;
        puVar1 = (undefined4*)((int)puVar1 + 1);
    }
    *(undefined1*)((char*)self + 0xf0) = 1;
    *(undefined4*)((char*)self + 0xe0) = (undefined4)&PTR_FUN_006c5a68;
    *(undefined1*)((char*)self + 0xf8) = 0;
    *(undefined4*)((char*)self + 0xf4) = 0xff7fffff;
    return;
}

// 0x5af810 — observed shape
void FUN_005af810(void* self) {
    undefined4 uVar1;

    FUN_005bbd20();
    *(undefined4*)((char*)self + 0x1c) = 0;
    *(undefined4*)((char*)self + 0x20) = 0;
    *(undefined4*)((char*)self + 0x24) = 0;
    *(undefined4*)((char*)self + 0x28) = 0;
    *(undefined4*)((char*)self + 0x2c) = 0;
    *(undefined4*)((char*)self + 0x30) = 0;
    *(undefined4*)((char*)self + 0x0) = (undefined4)&PTR_FUN_006c5b18;
    *(undefined4*)((char*)self + 0x34) = DAT_0071779c;
    *(undefined4*)((char*)self + 0x38) = DAT_007177a0;
    *(undefined4*)((char*)self + 0x3c) = DAT_007177a4;
    uVar1 = DAT_007177a8;
    *(undefined4*)((char*)self + 0x48) = 0;
    *(undefined4*)((char*)self + 0x4c) = 0;
    *(undefined4*)((char*)self + 0x44) = 0x3f800000;
    *(undefined4*)((char*)self + 0x40) = uVar1;
    return;
}

// 0x5af880 — observed shape
void FUN_005af880(void* self, int param_1, undefined4 param_2) {
    FUN_005bbeb0(param_1, param_2);
    *(undefined4*)(param_1 + 0x1c) = *(undefined4*)((char*)self + 0x1c);
    *(undefined4*)(param_1 + 0x20) = *(undefined4*)((char*)self + 0x20);
    *(undefined4*)(param_1 + 0x24) = *(undefined4*)((char*)self + 0x24);
    *(undefined4*)(param_1 + 0x28) = *(undefined4*)((char*)self + 0x28);
    *(undefined4*)(param_1 + 0x2c) = *(undefined4*)((char*)self + 0x2c);
    *(undefined4*)(param_1 + 0x30) = *(undefined4*)((char*)self + 0x30);
    *(undefined4*)(param_1 + 0x34) = *(undefined4*)((char*)self + 0x34);
    *(undefined4*)(param_1 + 0x38) = *(undefined4*)((char*)self + 0x38);
    *(undefined4*)(param_1 + 0x3c) = *(undefined4*)((char*)self + 0x3c);
    *(undefined4*)(param_1 + 0x40) = *(undefined4*)((char*)self + 0x40);
    *(undefined4*)(param_1 + 0x44) = *(undefined4*)((char*)self + 0x44);
    *(undefined4*)(param_1 + 0x48) = *(undefined4*)((char*)self + 0x48);
    *(undefined4*)(param_1 + 0x4c) = *(undefined4*)((char*)self + 0x4c);
    return;
}

// 0x5af900 — observed shape
void FUN_005af900(void* self, float param_1, ushort param_2, int param_3) {
    float* pfVar1;
    float fVar2;
    float fVar3;
    ushort uVar4;
    int iVar5;
    int iVar6;
    int iVar7;
    int iVar8;
    int iVar9;
    int iVar10;
    int* piVar11;
    uint uVar12;
    float10 fVar13;
    float10 fVar14;
    float10 fVar15;
    float10 fVar16;
    uint local_38;
    uint local_34;

    uVar12 = *(uint*)((char*)self + 0x14);
    iVar5 = *(int*)(uVar12 + 0xbc);
    local_34 = 0;
    if (param_2 != 0) {
        do {
            uVar4 = *(ushort*)(iVar5 + 0x54);
            if (uVar4 == 0) {
                uVar4 = *(ushort*)(iVar5 + 0x44);
                local_38 = (uint)uVar4;
                *(uint16_t*)(iVar5 + 0x56) = uVar4;
                if (*(ushort*)(iVar5 + 0xc) <= uVar4) {
                    return;
                }
                *(uint16_t*)(iVar5 + 0x54) = 1;
            } else {
                if ((uint)*(ushort*)(iVar5 + 0xc) <= (uint)*(ushort*)(iVar5 + 0x56) + (uint)uVar4) {
                    return;
                }
                local_38 = (uint)*(ushort*)(iVar5 + 0x56) +
                           (((uint)(uint16_t)(uVar12 >> 0x10) << 16) | (uint)uVar4);
                *(uint16_t*)(iVar5 + 0x54) = uVar4 + 1;
            }
            if ((short)local_38 == -1) {
                return;
            }
            iVar6 = *(int*)(iVar5 + 0x20);
            uVar12 = local_38 & 0xffff;
            pfVar1 = (float*)(*(int*)(iVar5 + 0x50) + uVar12 * 0x28);
            iVar7 = *(int*)(iVar5 + 0x28);
            iVar8 = *(int*)(iVar5 + 0x40);
            iVar9 = *(int*)(iVar5 + 0x48);
            iVar10 = rand();
            fVar2 = ((float)iVar10 * 3.051851e-05f - 0.5f) * (float)*(int*)((char*)self + 0x20) +
                    (float)*(int*)((char*)self + 0x1c);
            iVar10 = rand();
            fVar3 = ((float)iVar10 * 6.103702e-05f - 1.0f) * (float)*(int*)((char*)self + 0x28) +
                    (float)*(int*)((char*)self + 0x24);
            iVar10 = rand();
            fVar13 = ((float10)iVar10 * (float10)6.103702e-05 - (float10)1.0) *
                         (float10)(float)*(int*)((char*)self + 0x30) +
                     (float10)(float)*(int*)((char*)self + 0x2c);
            fVar14 = fsin((float10)fVar3);
            fVar15 = fcos(fVar13);
            fVar13 = fsin(fVar13);
            fVar16 = fcos((float10)fVar3);
            *pfVar1 = (float)(fVar15 * fVar14) * fVar2;
            pfVar1[1] = (float)(fVar13 * fVar14 * (float10)fVar2);
            pfVar1[2] = (float)(fVar16 * (float10)fVar2);
            pfVar1[6] = *(float*)(param_3 + (local_34 & 0xffff) * 4);
            iVar10 = rand();
            fVar2 = (float)*(int*)((char*)self + 0x4c);
            fVar3 = (float)*(int*)((char*)self + 0x48);
            *(uint16_t*)(pfVar1 + 9) = 0;
            pfVar1[7] = ((float)iVar10 * 3.051851e-05f - 0.5f) * fVar2 + fVar3;
            pfVar1[3] = DAT_007177ac;
            pfVar1[4] = DAT_007177b0;
            pfVar1[5] = DAT_007177b4;
            (*(void (**)(void*, float*))(*(int*)self + 0x48))((void*)(iVar6 + uVar12 * 0xc), pfVar1);
            if (iVar7 != 0) {
                piVar11 = (int*)(uVar12 * 0x10 + iVar7);
                piVar11[0] = *(int*)((char*)self + 0x34);
                piVar11[1] = *(int*)((char*)self + 0x38);
                piVar11[2] = *(int*)((char*)self + 0x3c);
                piVar11[3] = *(int*)((char*)self + 0x40);
            }
            if (iVar8 != 0) {
                *(int*)(iVar8 + uVar12 * 4) = *(int*)((char*)self + 0x44);
            }
            if (iVar9 != 0) {
                *(undefined4*)(iVar9 + uVar12 * 4) = 0x3f800000;
            }
            pfVar1[8] = param_1 - pfVar1[6];
            FUN_005aecb0(local_38);
            uVar12 = local_34 + 1;
            local_34 = uVar12;
        } while ((ushort)uVar12 < param_2);
    }
    return;
}

// 0x5afb50 — observed shape
void FUN_005afb50(void* self, int param_1) {
    FUN_005bbf20(param_1);
    (*(void (**)(void*, int))(*(int*)(param_1 + 0x15c) + 8))((char*)self + 0x1c, 4);
    (*(void (**)(void*, int))(*(int*)(param_1 + 0x15c) + 8))((char*)self + 0x20, 4);
    (*(void (**)(void*, int))(*(int*)(param_1 + 0x15c) + 8))((char*)self + 0x24, 4);
    (*(void (**)(void*, int))(*(int*)(param_1 + 0x15c) + 8))((char*)self + 0x28, 4);
    (*(void (**)(void*, int))(*(int*)(param_1 + 0x15c) + 8))((char*)self + 0x2c, 4);
    (*(void (**)(void*, int))(*(int*)(param_1 + 0x15c) + 8))((char*)self + 0x30, 4);
    FUN_00535190(param_1);
    (*(void (**)(void*, int))(*(int*)(param_1 + 0x15c) + 8))((char*)self + 0x44, 4);
    (*(void (**)(void*, int))(*(int*)(param_1 + 0x15c) + 8))((char*)self + 0x48, 4);
    (*(void (**)(void*, int))(*(int*)(param_1 + 0x15c) + 8))((char*)self + 0x4c, 4);
    return;
}

// 0x5afc10 — observed shape
void FUN_005afc10(void* self, int param_1) {
    FUN_005bbf80(param_1);
    (*(void (**)(void*, int))(*(int*)(param_1 + 0x160) + 0xc))((char*)self + 0x1c, 4);
    (*(void (**)(void*, int))(*(int*)(param_1 + 0x160) + 0xc))((char*)self + 0x20, 4);
    (*(void (**)(void*, int))(*(int*)(param_1 + 0x160) + 0xc))((char*)self + 0x24, 4);
    (*(void (**)(void*, int))(*(int*)(param_1 + 0x160) + 0xc))((char*)self + 0x28, 4);
    (*(void (**)(void*, int))(*(int*)(param_1 + 0x160) + 0xc))((char*)self + 0x2c, 4);
    (*(void (**)(void*, int))(*(int*)(param_1 + 0x160) + 0xc))((char*)self + 0x30, 4);
    FUN_005351e0(param_1);
    (*(void (**)(void*, int))(*(int*)(param_1 + 0x160) + 0xc))((char*)self + 0x44, 4);
    (*(void (**)(void*, int))(*(int*)(param_1 + 0x160) + 0xc))((char*)self + 0x48, 4);
    (*(void (**)(void*, int))(*(int*)(param_1 + 0x160) + 0xc))((char*)self + 0x4c, 4);
    return;
}

// 0x5afcd0 — observed shape
uint FUN_005afcd0(void* self, int param_1) {
    float fVar1;
    float fVar2;
    uint uVar3;
    uint16_t uVar4;

    uVar3 = FUN_005bbd90(param_1);
    if ((char)uVar3 != '\0') {
        fVar1 = *(float*)((char*)self + 0x1c);
        fVar2 = *(float*)(param_1 + 0x1c);
        uVar4 = (uint16_t)(uVar3 >> 0x10);
        uVar3 = ((uint)uVar4 << 16) |
                (uint)(uint16_t)((uint)(fVar2 < fVar1) << 8 |
                                 (uint)(fVar2 != fVar2 || fVar1 != fVar1) << 10 |
                                 (uint)(fVar2 == fVar1) << 0xe);
        if (fVar2 == fVar1) {
            fVar1 = *(float*)((char*)self + 0x20);
            fVar2 = *(float*)(param_1 + 0x20);
            uVar3 = ((uint)uVar4 << 16) |
                    (uint)(uint16_t)((uint)(fVar2 < fVar1) << 8 |
                                     (uint)(fVar2 != fVar2 || fVar1 != fVar1) << 10 |
                                     (uint)(fVar2 == fVar1) << 0xe);
            if (fVar2 == fVar1) {
                fVar1 = *(float*)((char*)self + 0x24);
                fVar2 = *(float*)(param_1 + 0x24);
                uVar3 = ((uint)uVar4 << 16) |
                        (uint)(uint16_t)((uint)(fVar2 < fVar1) << 8 |
                                         (uint)(fVar2 != fVar2 || fVar1 != fVar1) << 10 |
                                         (uint)(fVar2 == fVar1) << 0xe);
                if (fVar2 == fVar1) {
                    fVar1 = *(float*)((char*)self + 0x28);
                    fVar2 = *(float*)(param_1 + 0x28);
                    uVar3 = ((uint)uVar4 << 16) |
                            (uint)(uint16_t)((uint)(fVar2 < fVar1) << 8 |
                                             (uint)(fVar2 != fVar2 || fVar1 != fVar1) << 10 |
                                             (uint)(fVar2 == fVar1) << 0xe);
                    if (fVar2 == fVar1) {
                        fVar1 = *(float*)((char*)self + 0x2c);
                        fVar2 = *(float*)(param_1 + 0x2c);
                        uVar3 = ((uint)uVar4 << 16) |
                                (uint)(uint16_t)((uint)(fVar2 < fVar1) << 8 |
                                                 (uint)(fVar2 != fVar2 || fVar1 != fVar1) << 10 |
                                                 (uint)(fVar2 == fVar1) << 0xe);
                        if (fVar2 == fVar1) {
                            fVar1 = *(float*)((char*)self + 0x30);
                            fVar2 = *(float*)(param_1 + 0x30);
                            uVar3 = ((uint)uVar4 << 16) |
                                    (uint)(uint16_t)((uint)(fVar2 < fVar1) << 8 |
                                                     (uint)(fVar2 != fVar2 || fVar1 != fVar1) << 10 |
                                                     (uint)(fVar2 == fVar1) << 0xe);
                            if (fVar2 == fVar1) {
                                uVar3 = FUN_0050b0f0((int)((char*)self + 0x34));
                                if ((char)uVar3 == '\0') {
                                    fVar1 = *(float*)((char*)self + 0x44);
                                    fVar2 = *(float*)(param_1 + 0x44);
                                    uVar4 = (uint16_t)(uVar3 >> 0x10);
                                    uVar3 = ((uint)uVar4 << 16) |
                                            (uint)(uint16_t)((uint)(fVar2 < fVar1) << 8 |
                                                             (uint)(fVar2 != fVar2 || fVar1 != fVar1) << 10 |
                                                             (uint)(fVar2 == fVar1) << 0xe);
                                    if (fVar2 == fVar1) {
                                        fVar1 = *(float*)((char*)self + 0x48);
                                        fVar2 = *(float*)(param_1 + 0x48);
                                        uVar3 = ((uint)uVar4 << 16) |
                                                (uint)(uint16_t)((uint)(fVar2 < fVar1) << 8 |
                                                                 (uint)(fVar2 != fVar2 || fVar1 != fVar1) << 10 |
                                                                 (uint)(fVar2 == fVar1) << 0xe);
                                        if (fVar2 == fVar1) {
                                            fVar1 = *(float*)((char*)self + 0x4c);
                                            fVar2 = *(float*)(param_1 + 0x4c);
                                            uVar3 = ((uint)uVar4 << 16) |
                                                    (uint)(uint16_t)((uint)(fVar2 < fVar1) << 8 |
                                                                     (uint)(fVar2 != fVar2 || fVar1 != fVar1) << 10 |
                                                                     (uint)(fVar2 == fVar1) << 0xe);
                                            if (fVar2 == fVar1) {
                                                return (uVar3 & 0xffffff00) | 1;
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
    }
    return uVar3 & 0xffffff00;
}

// 0x5afda0 — observed shape
void FUN_005afda0(void* self, int param_1) {
    uint uVar1;
    int iVar2;

    iVar2 = param_1;
    FUN_005bbfe0(param_1);
    param_1 = FUN_00557b10(DAT_00728b98);
    uVar1 = *(uint*)(iVar2 + 0xc);
    if (*(uint*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, (undefined4*)&param_1);
    param_1 = FUN_00557cf0("Speed", *(undefined4*)((char*)self + 0x1c));
    uVar1 = *(uint*)(iVar2 + 0xc);
    if (*(uint*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, (undefined4*)&param_1);
    param_1 = FUN_00557cf0("Speed Variation", *(undefined4*)((char*)self + 0x20));
    uVar1 = *(uint*)(iVar2 + 0xc);
    if (*(uint*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, (undefined4*)&param_1);
    param_1 = FUN_00557cf0("Declination", *(undefined4*)((char*)self + 0x24));
    uVar1 = *(uint*)(iVar2 + 0xc);
    if (*(uint*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, (undefined4*)&param_1);
    param_1 = FUN_00557cf0("Declination Variation", *(undefined4*)((char*)self + 0x28));
    uVar1 = *(uint*)(iVar2 + 0xc);
    if (*(uint*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, (undefined4*)&param_1);
    param_1 = FUN_00557cf0("Planar Angle", *(undefined4*)((char*)self + 0x2c));
    uVar1 = *(uint*)(iVar2 + 0xc);
    if (*(uint*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, (undefined4*)&param_1);
    param_1 = FUN_00557cf0("Planar Angle Variation", *(undefined4*)((char*)self + 0x30));
    uVar1 = *(uint*)(iVar2 + 0xc);
    if (*(uint*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, (undefined4*)&param_1);
    param_1 = FUN_005350b0("Initial Color");
    uVar1 = *(uint*)(iVar2 + 0xc);
    if (*(uint*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, (undefined4*)&param_1);
    param_1 = FUN_00557cf0("Initial Radius", *(undefined4*)((char*)self + 0x44));
    uVar1 = *(uint*)(iVar2 + 0xc);
    if (*(uint*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, (undefined4*)&param_1);
    param_1 = FUN_00557cf0("Life Span", *(undefined4*)((char*)self + 0x48));
    uVar1 = *(uint*)(iVar2 + 0xc);
    if (*(uint*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, (undefined4*)&param_1);
    param_1 = FUN_00557cf0("Life Span Variation", *(undefined4*)((char*)self + 0x4c));
    uVar1 = *(uint*)(iVar2 + 0xc);
    if (*(uint*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar2 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, (undefined4*)&param_1);
    return;
}

// 0x5b0050 — observed shape
void FUN_005b0050(void* self, undefined4 param_1) {
    int* piVar1;
    undefined4* puVar2;
    undefined4* puVar3;

    thunk_FUN_00553060(param_1);
    // The existing declaration of FUN_00545600 in this file is void-returning;
    // the listing consumes its returned singleton pointer.
    puVar3 = (undefined4*)((void* (*)(void))FUN_00545600)();
    puVar2 = *(undefined4**)((char*)self + 0x4c);
    if (puVar2 != puVar3) {
        if (puVar2 != (undefined4*)0x0) {
            piVar1 = (int*)(puVar2 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                (*(void (**)(int))(*puVar2))(1);
            }
        }
        *(undefined4**)((char*)self + 0x4c) = puVar3;
        if (puVar3 != (undefined4*)0x0) {
            puVar3[1] = puVar3[1] + 1;
        }
    }
    return;
}

// 0x5b00e0 — observed shape
undefined4 FUN_005b00e0(void* self, undefined4* param_1, undefined4* param_2) {
    int iVar1;

    iVar1 = *(int*)((char*)self + 0x4c);
    if (iVar1 == 0) {
        *param_1 = 0;
        *param_2 = 0;
        return 0;
    }
    *param_1 = *(undefined4*)(iVar1 + 0xc);
    *param_2 = *(undefined4*)(iVar1 + 0x14);
    return *(undefined4*)(iVar1 + 0x10);
}

// 0x5b0130 — observed shape
void FUN_005b0130(void* self, undefined4 param_1, float param_2, float param_3, float param_4,
                 float param_5, float param_6) {
    ushort uVar1;
    uint uVar2;
    int iVar3;
    uint uVar4;

    if ((((0.0 < param_6) && (param_4 < param_5)) && (param_4 < param_2)) && (param_3 < param_5)) {
        if ((param_2 != param_2 || param_5 != param_5) ||
            ((param_2 < param_5) == (param_2 == param_5))) {
            param_2 = param_5;
        }
        param_2 = param_2 - param_4;
        uVar2 = FUN_005f0ddc();
        uVar1 = FUN_005f0ddc();
        *(undefined4*)((char*)self + 100) = 0;
        uVar4 = uVar1 - uVar2;
        if ((short)uVar4 != 0) {
            param_4 = (float)(uVar4 & 0xffff);
            do {
                iVar3 = *(int*)((char*)self + 0x60);
                uVar2 = uVar2 + 1;
                if (*(int*)((char*)self + 100) == iVar3) {
                    if (iVar3 == 0) {
                        iVar3 = 1;
                    } else {
                        iVar3 = iVar3 * 2;
                    }
                    FUN_0055f300(iVar3);
                }
                *(float*)(*(int*)((char*)self + 0x5c) + *(int*)((char*)self + 100) * 4) =
                    param_2 - (float)(uVar2 & 0xffff) * (1.0 / param_6);
                param_4 = (float)((int)param_4 - 1);
                *(int*)((char*)self + 100) = *(int*)((char*)self + 100) + 1;
            } while (param_4 != 0.0);
        }
        (*(void (**)(undefined4, uint, undefined4))(*(int*)((char*)self + 0x48) + 0x44))(
            param_1, uVar4, *(undefined4*)((char*)self + 0x5c));
    }
    return;
}

// 0x5b0280 — observed shape
void FUN_005b0280(void* self) {
    int iVar1;
    float* pfVar2;
    int iVar3;

    iVar1 = *(int*)((char*)self + 0x4c);
    *(undefined4*)((char*)self + 0x18) = 0x7f7fffff;
    *(undefined4*)((char*)self + 0x1c) = 0xff7fffff;
    if (iVar1 != 0) {
        pfVar2 = *(float**)(iVar1 + 0x10);
        iVar3 = *(int*)(iVar1 + 0xc);
        if (pfVar2 != (float*)0x0) {
            if (*pfVar2 < 3.4028235e+38f) {
                *(float*)((char*)self + 0x18) = *pfVar2;
            }
            iVar3 = (uint)*(byte*)(pfVar2 + 1) * (iVar3 + -1);
            if (-3.4028235e+38f < *(float*)((int)pfVar2 + iVar3)) {
                *(float*)((char*)self + 0x1c) = *(float*)((int)pfVar2 + iVar3);
            }
        }
        if (iVar1 != 0) {
            iVar3 = *(int*)(iVar1 + 0x18);
            pfVar2 = *(float**)(iVar1 + 0x1c);
            if (pfVar2 != (float*)0x0) {
                if (*pfVar2 < *(float*)((char*)self + 0x18)) {
                    *(float*)((char*)self + 0x18) = *pfVar2;
                }
                if (*(float*)((char*)self + 0x1c) < pfVar2[iVar3 * 2 + -2]) {
                    *(float*)((char*)self + 0x1c) = pfVar2[iVar3 * 2 + -2];
                }
            }
        }
    }
    return;
}

// 0x5b0360 — observed shape
void FUN_005b0360(void* self, int param_1, int param_2, undefined4 param_3) {
    int* piVar1;
    undefined4* puVar2;
    int iVar3;
    undefined4* puVar4;

    if (*(int*)((char*)self + 0x4c) == 0) {
        iVar3 = FUN_00533c78(0x20);
        if (iVar3 == 0) {
            puVar4 = (undefined4*)0x0;
        } else {
            puVar4 = (undefined4*)FUN_005b8030(0, 0, 0, 0, 0);
        }
        puVar2 = *(undefined4**)((char*)self + 0x4c);
        if (puVar2 != puVar4) {
            if (puVar2 != (undefined4*)0x0) {
                piVar1 = (int*)(puVar2 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    (*(void (**)(int))(*puVar2))(1);
                }
            }
            *(undefined4**)((char*)self + 0x4c) = puVar4;
            if (puVar4 != (undefined4*)0x0) {
                puVar4[1] = puVar4[1] + 1;
            }
        }
    }
    iVar3 = *(int*)((char*)self + 0x4c);
    if (*(int*)(iVar3 + 0x10) != 0) {
        (*(void (**)(int))(&DAT_007284e8 + *(int*)(iVar3 + 0x14) * 4))(*(int*)(iVar3 + 0x10));
    }
    if ((param_1 == 0) || (param_2 == 0)) {
        *(undefined4*)(iVar3 + 0xc) = 0;
        *(undefined4*)(iVar3 + 0x10) = 0;
        *(undefined4*)(iVar3 + 0x14) = 0;
        FUN_005b0280(self);
        return;
    }
    *(int*)(iVar3 + 0x10) = param_1;
    *(int*)(iVar3 + 0xc) = param_2;
    *(undefined4*)(iVar3 + 0x14) = param_3;
    FUN_005b0280(self);
    return;
}
