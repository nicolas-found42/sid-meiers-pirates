#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cstdio>
#include <cmath>

extern void FUN_00540cf0(int param_1, uint32_t param_2);
extern void FUN_004c2d90(uint32_t param_1);
extern void FUN_00541080(int param_1);
extern int FUN_00557b10(uint32_t addr);
extern void FUN_006b34a0(int param_1);
extern void FUN_005606f0(uint32_t a, void* b);
extern int FUN_00557b50(const char* name, int value);
extern int FUN_00535230(const char* name);
extern int FUN_0053c630(const char* name);
extern int FUN_00557cf0(const char* name, uint32_t value);
extern int FUN_00557e10(const char* name);
extern int FUN_00557d40(const char* name, int value);
extern int thunk_FUN_00533c78(int size);
extern uint32_t FUN_005348e0(int param_1);
extern void FUN_005edba0(void);
extern void operator_delete(void* ptr);
extern void FUN_0053bd50(int param_1);
extern void FUN_0053b680(int param_1);
extern void FUN_00534040(void);

// 0x534c00 — observed shape
void FUN_00534c00(int param_1, int param_2, int* param_3)
{
    uint32_t* puVar6;
    uint32_t* puVar7;
    uint32_t* puVar3;
    int iVar8;
    iVar8 = *(int*)(param_2 + 8);
    if (iVar8 == 0) {
        return;
    }
    do {
        int* piVar1 = *(int**)(iVar8 + 8);
        int* piVar2 = (int*)*param_3;
        iVar8 = *(int*)(iVar8 + 4);
        int iVar5 = (**((int (**)(int*))piVar2 + 4))(piVar1);
        for (puVar6 = *(uint32_t**)(piVar2[2] + iVar5 * 4); puVar6 != (uint32_t*)0x0;
            puVar6 = (uint32_t*)*puVar6) {
            char cVar4 = (**((char (**)(int*, int))piVar2 + 8))(piVar1, (int)puVar6[1]);
            if (cVar4 != '\0') {
                puVar6 = (uint32_t*)puVar6[2];
                goto LAB_00534c6c;
            }
        }
        puVar6 = (uint32_t*)(**(uint32_t* (**)(int))piVar1 + 8)(iVar8);
LAB_00534c6c:
        if (puVar6 != (uint32_t*)0x0) {
            puVar6[1] = puVar6[1] + 1;
        }
        puVar7 = (uint32_t*)(**(uint32_t* (**)())(*(int*)(param_1 + 0xa0) + 4))();
        puVar3 = (uint32_t*)puVar7[2];
        if (puVar3 != puVar6) {
            if (puVar3 != (uint32_t*)0x0) {
                int* piVar1b = (int*)(puVar3 + 1);
                *piVar1b = *piVar1b + -1;
                if (*piVar1b == 0) {
                    (**((void (**)(int))puVar3))(1);
                }
            }
            puVar7[2] = puVar6;
            if (puVar6 != (uint32_t*)0x0) {
                puVar6[1] = puVar6[1] + 1;
            }
        }
        puVar7[1] = 0;
        *puVar7 = *(uint32_t*)(param_1 + 0xa4);
        if (*(int*)(param_1 + 0xa4) == 0) {
            *(uint32_t**)(param_1 + 0xa8) = puVar7;
        }
        else {
            *(uint32_t**)(*(int*)(param_1 + 0xa4) + 4) = puVar7;
        }
        *(uint32_t**)(param_1 + 0xa4) = puVar7;
        *(int*)(param_1 + 0xac) = *(int*)(param_1 + 0xac) + 1;
        if (puVar6 != (uint32_t*)0x0) {
            int* piVar1b = (int*)(puVar6 + 1);
            *piVar1b = *piVar1b + -1;
            if (*piVar1b == 0) {
                (**((void (**)(int))puVar6))(1);
            }
        }
        if (iVar8 == 0) {
            return;
        }
    } while( true );
}

// 0x534cf0 — observed shape
void FUN_00534cf0_recon(void* self, int param_1, uint32_t param_2)
{
    uint32_t* puVar3;
    uint32_t* puVar4;
    FUN_00540cf0(param_1, param_2);
    *(uint16_t*)((char*)param_1 + 0x20) = *(uint16_t*)((char*)self + 0x20);
    puVar3 = (uint32_t*)((char*)self + 0x38);
    puVar4 = (uint32_t*)((char*)param_1 + 0x38);
    for (int iVar2 = 0xd; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
    }
    if (*(int*)((char*)self + 0xac) != 0) {
        FUN_00534c00(param_1, (int)((char*)self + 0xa0), (int*)&param_2);
    }
    if (*(int**)((char*)self + 0xb0) != (int*)0x0) {
        uint32_t uVar1 = (**(uint32_t* (**)(uint32_t))(*(int**)((char*)self + 0xb0) + 8))(param_2);
        FUN_004c2d90(uVar1);
    }
    return;
}

// 0x534d60 — observed shape
void FUN_00534d60_recon(void* self, int param_1)
{
    uint32_t* puVar2;
    int* piVar3;
    int iVar4;
    uint32_t* puVar5;
    int iVar6;
    int iVar7;
    iVar4 = param_1;
    FUN_00541080(param_1);
    param_1 = FUN_00557b10(0x7273fc);
    uint32_t uVar1 = *(uint32_t*)(iVar4 + 0xc);
    if (*(uint32_t*)(iVar4 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar4 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
    param_1 = FUN_00557b50("m_bAppCulled", *(uint8_t*)((char*)self + 0x20) & 1);
    uVar1 = *(uint32_t*)(iVar4 + 0xc);
    if (*(uint32_t*)(iVar4 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar4 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
    param_1 = FUN_00535230("m_localTranslate");
    uVar1 = *(uint32_t*)(iVar4 + 0xc);
    if (*(uint32_t*)(iVar4 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar4 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
    param_1 = FUN_0053c630("m_localRotate");
    uVar1 = *(uint32_t*)(iVar4 + 0xc);
    if (*(uint32_t*)(iVar4 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar4 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
    param_1 = FUN_00557cf0("m_fLocalScale", *(uint32_t*)((char*)self + 0x68));
    uVar1 = *(uint32_t*)(iVar4 + 0xc);
    if (*(uint32_t*)(iVar4 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar4 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
    param_1 = FUN_00535230("m_worldTranslate");
    uVar1 = *(uint32_t*)(iVar4 + 0xc);
    if (*(uint32_t*)(iVar4 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar4 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
    param_1 = FUN_0053c630("m_worldRotate");
    uVar1 = *(uint32_t*)(iVar4 + 0xc);
    if (*(uint32_t*)(iVar4 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar4 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
    param_1 = FUN_00557cf0("m_worldScale", *(uint32_t*)((char*)self + 0x9c));
    uVar1 = *(uint32_t*)(iVar4 + 0xc);
    if (*(uint32_t*)(iVar4 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar4 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
    param_1 = FUN_00557e10("m_kWorldBound");
    uVar1 = *(uint32_t*)(iVar4 + 0xc);
    if (*(uint32_t*)(iVar4 + 8) <= uVar1) {
        FUN_006b34a0(*(int*)(iVar4 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
    if (*(int*)((char*)self + 0xac) != 0) {
        puVar2 = *(uint32_t**)((char*)self + 0xa4);
        while (puVar2 != (uint32_t*)0x0) {
            piVar3 = (int*)puVar2[2];
            puVar2 = (uint32_t*)*puVar2;
            puVar5 = (uint32_t*)(**(uint32_t* (**)())(*piVar3 + 4))();
            iVar6 = FUN_00557d40((const char*)*puVar5, piVar3);
            uVar1 = *(uint32_t*)(iVar4 + 0xc);
            if ((uVar1 < *(uint32_t*)(iVar4 + 8)) ||
                (FUN_006b34a0(*(int*)(iVar4 + 0x14) + uVar1), uVar1 < *(uint32_t*)(iVar4 + 8))) {
                if (uVar1 < *(uint32_t*)(iVar4 + 0xc)) {
                    if (iVar6 == 0) {
                        if (*(int*)(*(int*)(iVar4 + 4) + uVar1 * 4) != 0) {
                            iVar7 = *(int*)(iVar4 + 0x10) + -1;
                            goto LAB_00534fee;
                        }
                    }
                    else if (*(int*)(*(int*)(iVar4 + 4) + uVar1 * 4) == 0) {
                        iVar7 = *(int*)(iVar4 + 0x10) + 1;
LAB_00534fee:
                        *(int*)(iVar4 + 0x10) = iVar7;
                    }
                }
                else {
                    *(uint32_t*)(iVar4 + 0xc) = uVar1 + 1;
                    if (iVar6 != 0) {
                        iVar7 = *(int*)(iVar4 + 0x10) + 1;
                        goto LAB_00534fee;
                    }
                }
                *(int*)(*(int*)(iVar4 + 4) + uVar1 * 4) = iVar6;
            }
        }
    }
    if (*(int*)((char*)self + 0xb0) != 0) {
        param_1 = FUN_00557d40("m_spCollisionObject", *(int*)((char*)self + 0xb0));
        uVar1 = *(uint32_t*)(iVar4 + 0xc);
        if (*(uint32_t*)(iVar4 + 8) <= uVar1) {
            FUN_006b34a0(*(int*)(iVar4 + 0x14) + uVar1);
        }
        FUN_005606f0(uVar1, &param_1);
    }
    return;
}

// 0x535050 — observed shape
char* FUN_00535050_recon(float* self, char* param_1)
{
    char cVar1;
    char* pcVar2;
    pcVar2 = param_1;
    do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = (char*)thunk_FUN_00533c78(0);
    sprintf(pcVar2, "%s = (%5.3f,%5.3f,%5.3f)", param_1, (double)*self, (double)self[1], (double)self[2]);
    return pcVar2;
}

// 0x5350b0 — observed shape
char* FUN_005350b0_recon(float* self, char* param_1)
{
    char cVar1;
    char* pcVar2;
    pcVar2 = param_1;
    do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = (char*)thunk_FUN_00533c78(0);
    sprintf(pcVar2, "%s = (%5.3f,%5.3f,%5.3f,%5.3f)", param_1, (double)*self, (double)self[1], (double)self[2], (double)self[3]);
    return pcVar2;
}
// 0x535110 — observed shape
void FUN_00535110_recon(void* self, int param_1)
{
    (**(void (**)(void))(*(int**)((char*)param_1 + 0x15c) + 8))();
    (**(void (**)(void*, int))(*(int**)((char*)param_1 + 0x15c) + 8))((char*)self + 4, 4);
    (**(void (**)(void*, int))(*(int**)((char*)param_1 + 0x15c) + 8))((char*)self + 8, 4);
    return;
}

// 0x535150 — observed shape
void FUN_00535150_recon(void* self, int param_1)
{
    (**(void (**)(void))(*(int**)((char*)param_1 + 0x160) + 0xc))();
    (**(void (**)(void*, int))(*(int**)((char*)param_1 + 0x160) + 0xc))((char*)self + 4, 4);
    (**(void (**)(void*, int))(*(int**)((char*)param_1 + 0x160) + 0xc))((char*)self + 8, 4);
    return;
}

// 0x535190 — observed shape
void FUN_00535190_recon(void* self, int param_1)
{
    (**(void (**)(void))(*(int**)((char*)param_1 + 0x15c) + 8))();
    (**(void (**)(void*, int))(*(int**)((char*)param_1 + 0x15c) + 8))((char*)self + 4, 4);
    (**(void (**)(void*, int))(*(int**)((char*)param_1 + 0x15c) + 8))((char*)self + 8, 4);
    (**(void (**)(void*, int))(*(int**)((char*)param_1 + 0x15c) + 8))((char*)self + 0xc, 4);
    return;
}

// 0x5351e0 — observed shape
void FUN_005351e0_recon(void* self, int param_1)
{
    (**(void (**)(void))(*(int**)((char*)param_1 + 0x160) + 0xc))();
    (**(void (**)(void*, int))(*(int**)((char*)param_1 + 0x160) + 0xc))((char*)self + 4, 4);
    (**(void (**)(void*, int))(*(int**)((char*)param_1 + 0x160) + 0xc))((char*)self + 8, 4);
    (**(void (**)(void*, int))(*(int**)((char*)param_1 + 0x160) + 0xc))((char*)self + 0xc, 4);
    return;
}

// 0x535230 — observed shape
char* FUN_00535230_recon(float* self, char* param_1)
{
    char cVar1;
    char* pcVar2;
    pcVar2 = param_1;
    do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = (char*)thunk_FUN_00533c78(0);
    sprintf(pcVar2, "%s = (%g,%g,%g)", param_1, (double)*self, (double)self[1], (double)self[2]);
    return pcVar2;
}
// 0x535290 — observed shape
void FUN_00535290(void)
{
    int iVar1;
    uint32_t uVar2;
    iVar1 = thunk_FUN_00533c78(0x400);
    uVar2 = 0;
    do {
        *(uint32_t*)(iVar1 + uVar2 * 4) = (uint32_t)sqrtf((float)((uVar2 | 0x3f80) << 0x10)) & 0x7fffff;
        *(uint32_t*)(iVar1 + 0x200 + uVar2 * 4) = (uint32_t)sqrtf((float)((uVar2 | 0x4000) << 0x10)) & 0x7fffff;
        uVar2 = uVar2 + 1;
    } while (uVar2 < 0x80);
    return;
}

// 0x535300 — observed shape
void FUN_00535300_recon(void* self, int param_1, uint32_t param_2)
{
    FUN_00534cf0(param_1, param_2);
    *(uint32_t*)((char*)param_1 + 0xbc) = *(uint32_t*)((char*)self + 0xbc);
    *(uint32_t*)((char*)param_1 + 0xc0) = *(uint32_t*)((char*)self + 0xc0);
    *(uint8_t*)((char*)param_1 + 0xb4) = *(uint8_t*)((char*)self + 0xb4);
    return;
}

// 0x535370 — observed shape
void FUN_00535370_recon(void* self, uint8_t param_1)
{
    *(void**)self = (void*)0x6c07d4;
    FUN_005edba0();
    *(void**)self = (void*)0x6c07c8;
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x5353a0 — observed shape
void FUN_005353a0_recon(void* self)
{
    int* piVar1;
    int iVar2;
    if (*(int*)((char*)self + 0xd0) != 0) {
        do {
            piVar1 = *(int**)((char*)self + 200);
            iVar2 = *piVar1;
            *(int*)((char*)self + 200) = iVar2;
            if (iVar2 == 0) {
                *(uint32_t*)((char*)self + 0xcc) = 0;
            }
            else {
                *(uint32_t*)(iVar2 + 4) = 0;
            }
            (**(void (**)(int*))(*(int*)((char*)self + 0xc4) + 8))(piVar1);
            *(int*)((char*)self + 0xd0) = *(int*)((char*)self + 0xd0) + -1;
            FUN_0053bd50((int)self);
        } while (*(int*)((char*)self + 0xd0) != 0);
    }
    return;
}

// 0x535410 — observed shape
void FUN_00535410_recon(void* self)
{
    int* piVar1;
    int iVar2;
    if (*(int*)((char*)self + 0xe0) != 0) {
        do {
            piVar1 = *(int**)((char*)self + 0xd8);
            iVar2 = *piVar1;
            *(int*)((char*)self + 0xd8) = iVar2;
            if (iVar2 == 0) {
                *(uint32_t*)((char*)self + 0xdc) = 0;
            }
            else {
                *(uint32_t*)(iVar2 + 4) = 0;
            }
            (**(void (**)(int*))(*(int*)((char*)self + 0xd4) + 8))(piVar1);
            *(int*)((char*)self + 0xe0) = *(int*)((char*)self + 0xe0) + -1;
        } while (*(int*)((char*)self + 0xe0) != 0);
    }
    return;
}
// 0x535460 — observed shape
uint32_t FUN_00535460_recon(void* self, int param_1)
{
    uint32_t* puVar5;
    uint32_t* puVar3;
    uint32_t uVar4;
    uVar4 = FUN_005348e0(param_1);
    if (((char)uVar4 == '\0') ||
        (uVar4 = *(uint32_t*)((char*)self + 0xd0), uVar4 != *(uint32_t*)((char*)param_1 + 0xd0))) {
        return uVar4 & 0xffffff00;
    }
    if (uVar4 == 0) {
LAB_005354c6:
        puVar5 = *(uint32_t**)((char*)self + 0xe0);
        if (puVar5 == (uint32_t*)*(uint32_t*)((char*)param_1 + 0xe0)) {
            if (puVar5 == (uint32_t*)0x0) {
                return 1;
            }
            puVar5 = *(uint32_t**)((char*)self + 0xd8);
            puVar3 = *(uint32_t**)((char*)param_1 + 0xd8);
            do {
                while( true ) {
                    if (puVar5 == (uint32_t*)0x0) {
                        return 1;
                    }
                    int* piVar1 = (int*)(puVar5 + 2);
                    puVar5 = (uint32_t*)*puVar5;
                    int* piVar2 = (int*)(puVar3 + 2);
                    puVar3 = (uint32_t*)*puVar3;
                    if (*piVar1 == 0) break;
                    if (*piVar2 == 0) goto LAB_005354b6;
                }
            } while (*((int*)(puVar3 + 2)) == 0);
        }
    }
    else {
        puVar5 = *(uint32_t**)((char*)self + 200);
        puVar3 = *(uint32_t**)((char*)param_1 + 200);
        do {
            while( true ) {
                if (puVar5 == (uint32_t*)0x0) goto LAB_005354c6;
                int* piVar1 = (int*)(puVar5 + 2);
                puVar5 = (uint32_t*)*puVar5;
                int* piVar2 = (int*)(puVar3 + 2);
                puVar3 = (uint32_t*)*puVar3;
                if (*piVar1 == 0) break;
                if (*piVar2 == 0) goto LAB_005354b6;
            }
        } while (*((int*)(puVar3 + 2)) == 0);
    }
LAB_005354b6:
    return (uint32_t)puVar5 & 0xffffff00;
}

// 0x535510 — observed shape
uint32_t FUN_00535510_recon(void* self, int param_1)
{
    uint32_t* puVar2;
    puVar2 = *(uint32_t**)((char*)self + 0xd8);
    do {
        if (puVar2 == (uint32_t*)0x0) {
            return 0;
        }
        int* piVar1 = (int*)(puVar2 + 2);
        puVar2 = (uint32_t*)*puVar2;
    } while (*piVar1 != param_1);
    return ((uint32_t)puVar2 & 0xffffff00) | 1;
}

// 0x535540 — observed shape
int FUN_00535540_recon(void* self, int* param_1)
{
    uint32_t* puVar1;
    int iVar2;
    int* piVar3;
    int iVar4;
    int* piVar5 = (int*)*param_1;
    int* in_ECX = (int*)self;
    if (piVar5 == (int*)in_ECX[1]) {
        *param_1 = *piVar5;
        piVar5 = (int*)in_ECX[1];
        iVar4 = *piVar5;
        in_ECX[1] = iVar4;
        if (iVar4 == 0) {
            in_ECX[2] = 0;
            iVar4 = piVar5[2];
        }
        else {
            *(uint32_t*)(iVar4 + 4) = 0;
            iVar4 = piVar5[2];
        }
    }
    else {
        if (piVar5 == (int*)in_ECX[2]) {
            *param_1 = 0;
            iVar4 = in_ECX[2];
            puVar1 = *(uint32_t**)(iVar4 + 4);
            in_ECX[2] = (int)puVar1;
            if (puVar1 == (uint32_t*)0x0) {
                in_ECX[1] = 0;
                iVar2 = *(int*)(iVar4 + 8);
                (**(void (**)(int))(*in_ECX + 8))(iVar4);
                in_ECX[3] = in_ECX[3] + -1;
                return iVar2;
            }
            *puVar1 = 0;
            iVar2 = *(int*)(iVar4 + 8);
            (**(void (**)(int))(*in_ECX + 8))(iVar4);
            in_ECX[3] = in_ECX[3] + -1;
            return iVar2;
        }
        piVar3 = (int*)piVar5[1];
        iVar4 = *piVar5;
        *param_1 = iVar4;
        if (piVar3 != (int*)0x0) {
            *piVar3 = iVar4;
        }
        if (iVar4 != 0) {
            *(int**)(iVar4 + 4) = piVar3;
        }
        iVar4 = piVar5[2];
    }
    (**(void (**)(int*))(*in_ECX + 8))(piVar5);
    in_ECX[3] = in_ECX[3] + -1;
    return iVar4;
}

// 0x535600 — observed shape
void FUN_00535600_recon(void* self)
{
    uint32_t* in_ECX = (uint32_t*)self;
    *in_ECX = (uint32_t)0x6c07e0;
    FUN_005353a0_recon(self);
    FUN_00535410_recon(self);
    in_ECX[0x35] = (uint32_t)0x6c07d4;
    FUN_005edba0();
    in_ECX[0x35] = (uint32_t)0x6c07c8;
    in_ECX[0x31] = (uint32_t)0x6c07d4;
    FUN_005edba0();
    in_ECX[0x31] = (uint32_t)0x6c07c8;
    FUN_00534040();
    return;
}

// 0x535670 — observed shape
void FUN_00535670_recon(void* self, int param_1)
{
    uint32_t* puVar2;
    puVar2 = *(uint32_t**)((char*)self + 200);
    do {
        uint32_t* puVar1 = puVar2;
        if (puVar1 == (uint32_t*)0x0) goto LAB_0053569b;
        puVar2 = (uint32_t*)*puVar1;
        if (param_1 == (int)puVar1[2]) {
            return;
        }
    } while (true);
LAB_0053569b:
    puVar2 = (uint32_t*)(**(uint32_t* (**)())(*(int*)((char*)self + 0xc4) + 4))();
    puVar2[2] = (uint32_t)param_1;
    puVar2[1] = 0;
    *puVar2 = *(uint32_t*)((char*)self + 200);
    if (*(int*)((char*)self + 200) == 0) {
        *(uint32_t**)((char*)self + 0xcc) = puVar2;
    }
    else {
        *(uint32_t**)(*(int*)((char*)self + 200) + 4) = puVar2;
    }
    *(int*)((char*)self + 0xd0) = *(int*)((char*)self + 0xd0) + 1;
    *(uint32_t**)((char*)self + 200) = puVar2;
    FUN_0053b680((int)self);
    return;
}
