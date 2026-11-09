#include <cstdint>
#include <cstddef>
#include <windows.h>

// Extern helpers referenced by mass_0184 corpus
extern void FUN_00552c80();
extern void FUN_00581390();
extern void FUN_00552d20();
extern void operator_delete(void* ptr);
extern void* thunk_FUN_00533c78(uint32_t size);
extern void FUN_004127b0(void* dst, uint32_t a, uint32_t b, void* c);
extern void FUN_0057a3f0(uint32_t n);
extern void FUN_00581300(uint32_t a, void** b);
extern void FUN_00552aa0(void* a, uint32_t b);
extern void FUN_00538400();

// Globals / tables referenced
extern void* PTR_FUN_006c4d98;
extern void* PTR_FUN_006c4d90;
extern void* PTR_FUN_006c4428;
extern void* LAB_004c2970;
extern void* DAT_00728524;

// 0x581590 — observed shape
void FUN_00581590(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    FUN_00552c80();
    in_ECX[0] = (uint32_t)&PTR_FUN_006c4d98;
    in_ECX[0x11] = (uint32_t)&PTR_FUN_006c4d90;
    in_ECX[0x13] = 1;
    in_ECX[0x16] = 1;
    in_ECX[0x14] = 0;
    in_ECX[0x15] = 0;
    uint32_t* puVar1 = (uint32_t*)thunk_FUN_00533c78(8);
    uint32_t* puVar2;
    if (puVar1 == (uint32_t*)0x0) {
        puVar2 = (uint32_t*)0x0;
    } else {
        puVar2 = puVar1 + 1;
        *puVar1 = 1;
        FUN_004127b0(puVar2, 4, 1, &LAB_004c2970);
    }
    in_ECX[0x12] = (uint32_t)puVar2;
    in_ECX[0x17] = 0;
    in_ECX[0x18] = 0;
    in_ECX[0x1a] = 0;
    in_ECX[0x19] = 0x7f7fffff;
    in_ECX[0x1b] = 0x3d088889;
}

// 0x581620 — observed shape
void FUN_00581620(void* self, uint8_t param_1) {
    FUN_00581390();
    FUN_00552d20();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x581650 — observed shape
void FUN_00581650(void* self, uint32_t* param_1, uint32_t param_2) {
    uint8_t* base = (uint8_t*)self;
    if (*(uint32_t*)(base + 0x50) <= param_2) {
        FUN_0057a3f0(param_2 + 1);
    }
    uint32_t* p2 = param_1;
    if (param_1 != (uint32_t*)0x0) {
        param_1[1] = param_1[1] + 1;
    }
    if (*(uint32_t*)(base + 0x4c) <= param_2) {
        FUN_0057a3f0(*(uint32_t*)(base + 0x58) + param_2);
    }
    FUN_00581300(param_2, (void**)&p2);
    if (param_1 != (uint32_t*)0x0) {
        uint32_t* piVar1 = param_1 + 1;
        *piVar1 = *piVar1 + (uint32_t)-1;
        if (*piVar1 == 0) {
            ((void(__cdecl*)(uint32_t))(*param_1))(1);
        }
    }
    float fVar2 = (float)*(int32_t*)(base + 0x50);
    if ((int32_t)*(uint32_t*)(base + 0x50) < 0) {
        fVar2 = fVar2 + 4.2949673e+09f;
    }
    fVar2 = fVar2 * *(float*)(base + 0x6c);
    *(float*)(base + 0x68) = fVar2;
    *(float*)(base + 0x1c) = fVar2 + *(float*)(base + 100);
    if (*(uint32_t*)(base + 0x50) <= *(uint32_t*)(base + 0x5c)) {
        *(uint32_t*)(base + 0x5c) = 0;
    }
}

// 0x5816e0 — observed shape
void FUN_005816e0(void* self, uint8_t* param_1, uint32_t param_2) {
    uint8_t* sbase = (uint8_t*)self;
    FUN_00552aa0(param_1, param_2);
    *(uint32_t*)(param_1 + 0x60) = *(uint32_t*)(sbase + 0x60);
    float fVar1 = *(float*)(sbase + 100);
    *(float*)(param_1 + 100) = fVar1;
    *(float*)(param_1 + 0x18) = fVar1;
    *(float*)(param_1 + 0x1c) = fVar1 + *(float*)(param_1 + 0x68);
    float fVar2 = *(float*)(sbase + 0x6c);
    *(float*)(param_1 + 0x6c) = fVar2;
    float fVar3 = (float)*(int32_t*)(param_1 + 0x50);
    if ((int32_t)*(uint32_t*)(param_1 + 0x50) < 0) {
        fVar3 = fVar3 + 4.2949673e+09f;
    }
    fVar3 = fVar3 * fVar2;
    *(float*)(param_1 + 0x68) = fVar3;
    *(float*)(param_1 + 0x1c) = fVar3 + fVar1;
    if (*(uint32_t*)(param_1 + 0x50) <= *(uint32_t*)(param_1 + 0x5c)) {
        *(uint32_t*)(param_1 + 0x5c) = 0;
    }
    uint32_t uVar5 = 0;
    if (*(int32_t*)(sbase + 0x50) != 0) {
        if (*(int32_t*)(sbase + 0x50) == 0) {
            uint32_t uVar4 = 0;
            FUN_00581650(self, (uint32_t*)uVar4, uVar5);
            uVar5 = uVar5 + 1;
        } else {
            do {
                uint32_t uVar4 = *(uint32_t*)(*(int32_t*)(sbase + 0x48) + uVar5 * 4);
                FUN_00581650(self, (uint32_t*)uVar4, uVar5);
                uVar5 = uVar5 + 1;
            } while (uVar5 < *(uint32_t*)(sbase + 0x50));
        }
    }
    fVar1 = (float)*(int32_t*)(param_1 + 0x50);
    if ((int32_t)*(uint32_t*)(param_1 + 0x50) < 0) {
        fVar1 = fVar1 + 4.2949673e+09f;
    }
    fVar1 = fVar1 * *(float*)(param_1 + 0x6c);
    *(float*)(param_1 + 0x68) = fVar1;
    *(float*)(param_1 + 0x1c) = fVar1 + *(float*)(param_1 + 100);
    if (*(uint32_t*)(param_1 + 0x50) <= *(uint32_t*)(param_1 + 0x5c)) {
        *(uint32_t*)(param_1 + 0x5c) = 0;
    }
}

// 0x5818f0 — observed shape
void FUN_005818f0(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    in_ECX[0] = (uint32_t)&PTR_FUN_006c4428;
    if (in_ECX[4] != 0) {
        ((void(__cdecl*)(uint32_t))(*(uint32_t*)((uint8_t*)&DAT_00728524 + in_ECX[5] * 4)))(in_ECX[4]);
    }
    FUN_00538400();
}

extern uint32_t FUN_00538460(int param_1);
extern void FUN_005829b0();
extern void FUN_00538430(int param_1);
extern void* DAT_00728704;
extern void* DAT_0072868c;
extern int* FUN_00538580(void** out);
extern int FUN_00538680();
extern void FUN_00552ef0(int a, uint32_t b, uint32_t c, uint32_t d);
extern uint32_t FUN_005829f0(int* a, uint32_t* b);
extern void FUN_00576320(uint32_t a, uint32_t b, uint32_t c, int d, uint32_t e, uint32_t f, uint32_t* g, uint32_t* h);
extern void FUN_00582a30(uint32_t a, uint32_t b, uint32_t c);

// 0x581920 — observed shape
void FUN_00581920(void* self, int param_1, int param_2, uint32_t param_3) {
    uint8_t* base = (uint8_t*)self;
    if (*(int32_t*)(base + 0x10) != 0) {
        ((void(__cdecl*)(int32_t))(*(uint32_t*)((uint8_t*)&DAT_00728524 + *(int32_t*)(base + 0x14) * 4)))(*(int32_t*)(base + 0x10));
    }
    if ((param_1 == 0) || (param_2 == 0)) {
        *(uint32_t*)(base + 0xc) = 0;
        *(uint32_t*)(base + 0x10) = 0;
        *(uint32_t*)(base + 0x14) = 0;
        return;
    }
    *(int32_t*)(base + 0xc) = param_2;
    *(int32_t*)(base + 0x10) = param_1;
    *(uint32_t*)(base + 0x14) = param_3;
}

// 0x5819c0 — observed shape
uint32_t FUN_005819c0(void* self, int param_1) {
    uint8_t* base = (uint8_t*)self;
    uint8_t* pbase = (uint8_t*)param_1;
    uint32_t uVar2 = FUN_00538460(param_1);
    if ((((char)uVar2 == '\0') || (*(int32_t*)(base + 0xc) != *(int32_t*)(pbase + 0xc))) ||
        (uVar2 = *(uint32_t*)(base + 0x14), uVar2 != *(uint32_t*)(pbase + 0x14))) {
        return uVar2 & 0xffffff00u;
    }
    uint32_t (*pcVar1)(uint8_t*, uint8_t*) = (uint32_t(*)(uint8_t*,uint8_t*))*(uint32_t*)((uint8_t*)&DAT_00728704 + uVar2 * 4);
    uint32_t uVar3 = 0;
    if (*(int32_t*)(base + 0xc) != 0) {
        do {
            uVar2 = pcVar1((uint8_t*)(*(int32_t*)(base + 0x10) + *(uint8_t*)(*(int32_t*)(base + 0x10) + 4) * uVar3),
                           (uint8_t*)(*(int32_t*)(pbase + 0x10) + *(uint8_t*)(*(int32_t*)(pbase + 0x10) + 4) * uVar3));
            if ((char)uVar2 == '\0') {
                return uVar2 & 0xffffff00u;
            }
            uVar2 = *(uint32_t*)(base + 0xc);
            uVar3 = uVar3 + 1;
        } while (uVar3 < uVar2);
    }
    return (uint32_t)(uVar2 & 0xffffff00u) + 1;
}

// 0x581ab0 — observed shape
void FUN_00581ab0(void* self, int param_1) {
    uint8_t* base = (uint8_t*)self;
    FUN_00538430(param_1);
    int32_t* piVar1 = (int32_t*)(base + 0xc);
    ((void(__cdecl*)(int32_t*, uint32_t))(*(uint32_t*)(*(int32_t*)(param_1 + 0x160) + 0xc)))(piVar1, 4);
    if (*piVar1 != 0) {
        ((void(__cdecl*)(int32_t*, uint32_t))(*(uint32_t*)(*(int32_t*)(param_1 + 0x160) + 0xc)))((int32_t*)(base + 0x14), 4);
        ((void(__cdecl*)(int, uint32_t, int32_t))(*(uint32_t*)((uint8_t*)&DAT_0072868c + *(int32_t*)(base + 0x14) * 4)))(param_1, *(uint32_t*)(base + 0x10), *piVar1);
    }
}

// 0x581c00 — observed shape
void FUN_00581c00(void* self, uint8_t param_1) {
    FUN_005829b0();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x581cd0 — observed shape
int FUN_00581cd0(uint32_t param_1, uint32_t param_2, uint32_t param_3) {
    uint32_t* local_8 = nullptr;
    int* piVar3 = (int*)FUN_00538580((void**)&local_8);
    uint32_t* puVar1 = (uint32_t*)*piVar3;
    if (puVar1 != (uint32_t*)0x0) {
        puVar1[1] = puVar1[1] + 1;
    }
    if ((local_8 != (uint32_t*)0x0) &&
        ((int)local_8[1] - 1 == 0)) {
        int iTemp = (int)local_8[1];
        local_8[1] = (uint32_t)(iTemp - 1);
        if (iTemp - 1 == 0) {
            ((void(__cdecl*)(uint32_t))(*local_8))(1);
        }
    } else if (local_8 != (uint32_t*)0x0) {
        int iVar4 = (int)local_8[1];
        local_8[1] = (uint32_t)(iVar4 - 1);
        if (iVar4 - 1 == 0) {
            ((void(__cdecl*)(uint32_t))(*local_8))(1);
        }
    }
    int iVar4 = FUN_00538680();
    FUN_00552ef0(iVar4, param_1, param_2, param_3);
    uint32_t* puVar2 = *(uint32_t**)(iVar4 + 0x48);
    if (puVar2 != puVar1) {
        if (puVar2 != (uint32_t*)0x0) {
            piVar3 = (int*)(puVar2 + 1);
            *piVar3 = *piVar3 - 1;
            if (*piVar3 == 0) {
                ((void(__cdecl*)(uint32_t))(*puVar2))(1);
            }
        }
        *(uint32_t**)(iVar4 + 0x48) = puVar1;
        if (puVar1 != (uint32_t*)0x0) {
            puVar1[1] = puVar1[1] + 1;
        }
    }
    uint32_t uStack_c = 0;
    uint32_t uStack_10 = 0;
    uint32_t uStack_14 = 0;
    int iStack_4 = 0;
    uint32_t uVar5 = FUN_005829f0(&iStack_4, &uStack_14);
    if (iStack_4 != 0) {
        FUN_00576320(0, uStack_14, uVar5, iStack_4, param_1, param_2, &uStack_10, &uStack_c);
        FUN_00582a30(uStack_c, uStack_10, uStack_14);
    }
    if (puVar1 != (uint32_t*)0x0) {
        piVar3 = (int*)(puVar1 + 1);
        *piVar3 = *piVar3 - 1;
        if (*piVar3 == 0) {
            ((void(__cdecl*)(uint32_t))(*puVar1))(1);
        }
    }
    return iVar4;
}

extern void FUN_005531c0(int param_1);
extern int FUN_00557b10(uint32_t param_1);
extern void FUN_006b34a0(int param_1);
extern void FUN_005606f0(uint32_t a, int* b);
extern void* DAT_00728a5c;
extern void FUN_00552f70(uint32_t param_1);
extern void FUN_005460e0(void* param_1);

// 0x581e70 — observed shape
void FUN_00581e70(int param_1) {
    int iVar2 = param_1;
    FUN_005531c0(param_1);
    param_1 = FUN_00557b10((uint32_t)&DAT_00728a5c);
    uint32_t uVar1 = *(uint32_t*)(iVar2 + 0xc);
    if (*(uint32_t*)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int32_t*)(iVar2 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
}

// 0x581ec0 — observed shape
long double FUN_00581ec0(float param_1, float param_2, float param_3) {
    return (long double)param_1 * (long double)param_3 + ((long double)1.0 - (long double)param_1) * (long double)param_2;
}

// 0x581ee0 — observed shape
long double FUN_00581ee0(float param_1, float param_2, float param_3, float param_4, float param_5) {
    long double fVar1 = (long double)param_4 - (long double)param_2;
    return (((fVar1 * (long double)3.0 - ((long double)param_3 + (long double)param_3 + (long double)param_5)) +
             (((long double)param_3 + (long double)param_5) - (fVar1 + fVar1)) * (long double)param_1) *
             (long double)param_1 + (long double)param_3) * (long double)param_1 + (long double)param_2;
}

// 0x581f30 — observed shape
void FUN_00581f30(float param_1, float param_2, float* param_3, float param_4, float param_5,
                  float* param_6, float param_7, uint32_t param_8, float* param_9, float* param_10) {
    param_4 = param_4 - param_1;
    float fVar3 = 1.0f / (param_5 - param_2);
    float fVar2 = (param_7 - param_2) * fVar3;
    float fVar1 = (param_4 * 3.0f - (*param_3 + *param_3)) - *param_6;
    fVar1 = ((fVar1 + fVar1 + ((*param_6 - (param_4 + param_4)) + *param_3) * fVar2 * 3.0f) * fVar2 +
             *param_3) * fVar3;
    *param_9 = fVar1;
    *param_10 = fVar1 * (param_5 - param_7);
    *param_9 = (param_7 - param_2) * *param_9;
    *param_3 = fVar2 * *param_3;
    *param_6 = fVar3 * *param_6 * (param_5 - param_7);
}

// 0x581fd0 — observed shape
void FUN_00581fd0(void* self, uint32_t param_1) {
    FUN_00552f70(param_1);
    FUN_005460e0((uint8_t*)self + 0x44);
}

extern char FUN_00552b90(uint32_t param_1);
extern void FUN_005530e0(uint32_t param_1);
extern void FUN_00545950(uint32_t param_1);
extern void* PTR_FUN_006c44c8;
extern void operator_delete__(void* ptr);
extern void FUN_005ae800(uint32_t param_1);
extern uint8_t* FUN_00552bc0(int param_1);

// 0x581ff0 — observed shape
bool FUN_00581ff0(uint32_t param_1) {
    char cVar1 = FUN_00552b90(param_1);
    return cVar1 != '\0';
}

// 0x582010 — observed shape
void FUN_00582010(void* self, uint32_t param_1) {
    FUN_005530e0(param_1);
    FUN_00545950(*(uint32_t*)((uint8_t*)self + 0x44));
}

// 0x582030 — observed shape
void FUN_00582030(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    in_ECX[0] = (uint32_t)&PTR_FUN_006c44c8;
    uint32_t* puVar2 = (uint32_t*)in_ECX[0x12];
    if (puVar2 != (uint32_t*)0x0) {
        int32_t* piVar1 = (int32_t*)(puVar2 + 1);
        *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) {
            ((void(__cdecl*)(uint32_t))(*puVar2))(1);
        }
        in_ECX[0x12] = 0;
    }
    operator_delete__((void*)in_ECX[0x11]);
    puVar2 = (uint32_t*)in_ECX[0x12];
    if (puVar2 != (uint32_t*)0x0) {
        int32_t* piVar1 = (int32_t*)(puVar2 + 1);
        *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) {
            ((void(__cdecl*)(uint32_t))(*puVar2))(1);
        }
    }
    FUN_00552d20();
}

// 0x582080 — observed shape
void FUN_00582080(void* self, uint32_t param_1, uint32_t param_2) {
    FUN_00552aa0((void*)param_1, param_2);
    FUN_005ae800(*(uint32_t*)((uint8_t*)self + 0x44));
}

// 0x582120 — observed shape
uint32_t FUN_00582120(void* self, int param_1) {
    uint8_t* sbase = (uint8_t*)self;
    uint8_t* pbase = (uint8_t*)param_1;
    uint8_t* pbVar3 = FUN_00552bc0(param_1);
    if ((char)(uint32_t)pbVar3 == '\0') {
        return (uint32_t)pbVar3 & 0xffffff00u;
    }
    int32_t* piVar2 = *(int32_t**)(sbase + 0x48);
    uint8_t* pbVar4;
    if (piVar2 == (int32_t*)0x0) {
        pbVar3 = *(uint8_t**)(pbase + 0x48);
        if (pbVar3 != (uint8_t*)0x0) {
            return (uint32_t)pbVar3 & 0xffffff00u;
        }
        if (piVar2 != (int32_t*)0x0) {
            goto LAB_00582153;
        }
    } else {
        pbVar3 = (uint8_t*)0x0;
        if (*(int32_t*)(pbase + 0x48) == 0) {
            return (uint32_t)pbVar3 & 0xffffff00u;
        }
        if (piVar2 == (int32_t*)0x0) {
            pbVar3 = *(uint8_t**)(pbase + 0x48);
            if (pbVar3 != (uint8_t*)0x0) {
                return (uint32_t)pbVar3 & 0xffffff00u;
            }
            if (piVar2 != (int32_t*)0x0) {
                goto LAB_00582153;
            }
        } else {
LAB_00582153:
            if ((*(int32_t*)(pbase + 0x48) != 0) &&
                (pbVar3 = (uint8_t*)((*(uint32_t(*)(int32_t))(*(uint32_t*)(*piVar2 + 0x1c)))(*(int32_t*)(pbase + 0x48))),
                (char)(uint32_t)pbVar3 == '\0')) {
                return (uint32_t)pbVar3 & 0xffffff00u;
            }
        }
    }
    pbVar3 = *(uint8_t**)(sbase + 0x44);
    pbVar4 = pbVar3;
    if (pbVar3 == (uint8_t*)0x0) {
        if (*(int32_t*)(pbase + 0x44) != 0) {
            return (uint32_t)pbVar3 & 0xffffff00u;
        }
        if (pbVar3 == (uint8_t*)0x0) {
            goto LAB_005821c9;
        }
    } else {
        if (*(int32_t*)(pbase + 0x44) == 0) {
            return (uint32_t)pbVar3 & 0xffffff00u;
        }
        if (pbVar3 == (uint8_t*)0x0) {
            if (*(int32_t*)(pbase + 0x44) != 0) {
                return (uint32_t)pbVar3 & 0xffffff00u;
            }
            if (pbVar3 == (uint8_t*)0x0) {
                goto LAB_005821c9;
            }
        }
    }
    {
        uint8_t* pbVar5 = *(uint8_t**)(pbase + 0x44);
        if (pbVar5 != (uint8_t*)0x0) {
            uint8_t bVar1;
            bool bVar6;
            do {
                bVar1 = *pbVar3;
                bVar6 = bVar1 < *pbVar5;
                if (bVar1 != *pbVar5) {
                    pbVar3 = (uint8_t*)((1 - (uint32_t)bVar6) - (uint32_t)(bVar6 != 0));
                    goto LAB_005821bd;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar3[1];
                bVar6 = bVar1 < pbVar5[1];
                if (bVar1 != pbVar5[1]) {
                    pbVar3 = (uint8_t*)((1 - (uint32_t)bVar6) - (uint32_t)(bVar6 != 0));
                    goto LAB_005821bd;
                }
                pbVar3 = pbVar3 + 2;
                pbVar5 = pbVar5 + 2;
            } while (bVar1 != 0);
            pbVar3 = (uint8_t*)0x0;
LAB_005821bd:
            pbVar4 = (uint8_t*)0x0;
            if (pbVar3 != (uint8_t*)0x0) {
                return (uint32_t)pbVar3 & 0xffffff00u;
            }
        }
    }
LAB_005821c9:
    return (uint32_t)((uint32_t)pbVar4 & 0xffffff00u) + 1;
}
