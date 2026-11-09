#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void operator_delete(void *p);
extern unsigned char *thunk_FUN_00533c78(int size);
extern int DAT_00727444;
extern void *PTR_LAB_006fd148;
extern void *PTR_FUN_006c2fc4;
extern void FUN_00547db0(int p1, uint32_t p2);

// 0x55a260 — observed shape
void FUN_0055a260(void *self_, char *param_1)
{
    uint8_t *selfBytes = (uint8_t *)self_;
    char *pcVar4;
    char *pcVar2;
    char cVar1;
    int iVar3;
    bool bVar5;

    operator_delete(*(void **)(selfBytes + 8));
    *(uint32_t *)(selfBytes + 8) = 0;
    if (param_1 != (char *)0x0) {
        iVar3 = 1;
        bVar5 = true;
        pcVar2 = param_1;
        pcVar4 = "";
        do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar5 = *pcVar2 == *pcVar4;
            pcVar2 = pcVar2 + 1;
            pcVar4 = pcVar4 + 1;
        } while (bVar5);
        if (!bVar5) {
            pcVar2 = param_1;
            do {
                cVar1 = *pcVar2;
                pcVar2 = pcVar2 + 1;
            } while (cVar1 != '\0');
            pcVar2 = (char *)thunk_FUN_00533c78((int)(pcVar2 + (1 - (int)(param_1 + 1))));
            *(char **)(selfBytes + 8) = pcVar2;
            do {
                cVar1 = *param_1;
                param_1 = param_1 + 1;
                *pcVar2 = cVar1;
                pcVar2 = pcVar2 + 1;
            } while (cVar1 != '\0');
        }
    }
}

// 0x55a2e0 — observed shape
void FUN_0055a2e0(void *self_, uint32_t param_1)
{
    uint32_t *self = (uint32_t *)self_;
    *self = (uint32_t)(uintptr_t)&PTR_LAB_006fd148;
    self[1] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    self[2] = 0;
    *self = (uint32_t)(uintptr_t)&PTR_FUN_006c2fc4;
    FUN_0055a260(self_, (char *)(uintptr_t)param_1);
}

// 0x55a310 — observed shape
void FUN_0055a310(void *self_)
{
    uint32_t *self = (uint32_t *)self_;
    *self = (uint32_t)(uintptr_t)&PTR_FUN_006c2fc4;
    operator_delete((void *)(uintptr_t)self[2]);
    self[2] = 0;
    *self = (uint32_t)(uintptr_t)&PTR_LAB_006fd148;
    DAT_00727444 = DAT_00727444 + -1;
}

// 0x55a340 — observed shape
void FUN_0055a340(void *self_, uint8_t param_1)
{
    uint32_t *self = (uint32_t *)self_;
    *self = (uint32_t)(uintptr_t)&PTR_FUN_006c2fc4;
    operator_delete((void *)(uintptr_t)self[2]);
    self[2] = 0;
    *self = (uint32_t)(uintptr_t)&PTR_LAB_006fd148;
    DAT_00727444 = DAT_00727444 + -1;
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x55a390 — observed shape
void FUN_0055a390(int param_1, uint32_t param_2)
{
    uint8_t *in_ECX;
    uint32_t *puVar1;
    uint32_t *puVar4;
    uint32_t uVar2;
    uint32_t uVar3;

    FUN_00547db0(param_1, param_2);
    if (*(int *)(in_ECX + 0x14) == 0) {
        *(uint32_t *)(param_1 + 0x14) = 0;
        *(uint32_t *)(param_1 + 0x10) = 0;
        return;
    }
    puVar1 = (uint32_t *)thunk_FUN_00533c78(*(int *)(in_ECX + 0x14));
    *(uint32_t **)(param_1 + 0x10) = puVar1;
    uVar3 = *(uint32_t *)(in_ECX + 0x14);
    puVar4 = *(uint32_t **)(in_ECX + 0x10);
    for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar1 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar1 = puVar1 + 1;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(uint8_t *)puVar1 = *(uint8_t *)puVar4;
        puVar4 = (uint32_t *)((uintptr_t)puVar4 + 1);
        puVar1 = (uint32_t *)((uintptr_t)puVar1 + 1);
    }
    *(uint32_t *)(param_1 + 0x14) = *(uint32_t *)(in_ECX + 0x14);
}

extern void FUN_00547fa0(int p1);
extern void FUN_00547e30(int p1);
extern void FUN_00541140(uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7);
extern uint32_t FUN_00541de0(int p1);
extern void FUN_00541580(void);
extern void *PTR_FUN_006c2fd8;

// 0x55a4d0 — observed shape
void FUN_0055a4d0(int param_1)
{
    int *piVar1;
    uint32_t uVar2;
    int in_ECX;
    typedef void (*code_t)(int *, int);
    typedef void (*code2_t)(uint32_t, int);

    FUN_00547fa0(param_1);
    piVar1 = (int *)(in_ECX + 0x14);
    (*(code_t *)((**(int **)(param_1 + 0x15c) + 8)))(piVar1, 4);
    if (*piVar1 != 0) {
        uVar2 = (uint32_t)(uintptr_t)thunk_FUN_00533c78(*piVar1);
        *(uint32_t *)(in_ECX + 0x10) = uVar2;
        (*(code2_t *)((**(int **)(param_1 + 0x15c) + 8)))(uVar2, *piVar1);
    }
}

// 0x55a520 — observed shape
void FUN_0055a520(int param_1)
{
    int iVar1;
    int in_ECX;
    typedef void (*code_t)(int *, int);
    typedef void (*code2_t)(uint32_t, int);

    FUN_00547e30(param_1);
    (*(code_t *)((**(int **)(param_1 + 0x160) + 0xc)) )((int *)(in_ECX + 0x14), 4);
    iVar1 = *(int *)(in_ECX + 0x14);
    if (iVar1 != 0) {
        (*(code2_t *)((**(int **)(param_1 + 0x160) + 0xc)))(*(uint32_t *)(in_ECX + 0x10), iVar1);
    }
}

// 0x55a5f0 — observed shape
void FUN_0055a5f0(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6, int param_7)
{
    uint8_t bVar1;
    uint16_t uVar2;
    uint32_t uVar3;
    uint32_t *in_ECX;
    int iVar4;

    FUN_00541140(param_1, param_2, 0, param_3, param_4, param_5, param_6);
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c2fd8;
    if (param_7 != 0) {
        in_ECX[0xf] = (uint32_t)param_7;
        return;
    }
    uVar3 = (uint32_t)(uintptr_t)thunk_FUN_00533c78(param_1 & 0xffff);
    in_ECX[0xf] = uVar3;
    uVar2 = 0;
    if ((uint16_t)param_1 != 0) {
        iVar4 = 0;
        do {
            bVar1 = (uint8_t)uVar2;
            uVar2 = uVar2 + 1;
            *(uint8_t *)(iVar4 + in_ECX[0xf]) = (uint8_t)(~bVar1 & 1);
            iVar4 = iVar4 + 1;
        } while (uVar2 < (uint16_t)param_1);
    }
}

// 0x55a6a0 — observed shape
uint32_t FUN_0055a6a0(int param_1)
{
    int iVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    uint16_t uVar4;
    int in_ECX;

    uVar2 = FUN_00541de0(param_1);
    if ((char)uVar2 == '\0') {
        return uVar2;
    }
    iVar1 = *(int *)(in_ECX + 0x3c);
    if (iVar1 != 0) {
        uVar2 = *(uint32_t *)(param_1 + 0x3c);
        uVar3 = 0;
        if (uVar2 == 0) goto LAB_0055a6d1;
        if (iVar1 != 0) goto LAB_0055a6d9;
    }
    uVar3 = *(uint32_t *)(param_1 + 0x3c);
    uVar2 = 0;
    if (uVar3 == 0) {
    LAB_0055a6d9:
        if (iVar1 != 0) {
            uVar4 = 0;
            if (*(uint16_t *)(in_ECX + 0xc) != 0) {
                do {
                    uVar2 = (uint32_t)uVar4;
                    if (*(char *)(uVar2 + iVar1) != *(char *)(*(int *)(param_1 + 0x3c) + uVar2)) {
                        return (uint32_t)(uint8_t)(uVar4 >> 8) << 8;
                    }
                    uVar4 = uVar4 + 1;
                } while (uVar4 < *(uint16_t *)(in_ECX + 0xc));
            }
        }
        return ((uVar2 >> 8) & 0xffffff00) | 1;
    }
LAB_0055a6d1:
    return uVar3 & 0xffffff00;
}

// 0x55a730 — observed shape
void FUN_0055a730(void *self_, uint8_t param_1)
{
    uint32_t *in_ECX = (uint32_t *)self_;
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c2fd8;
    operator_delete((void *)(uintptr_t)in_ECX[0xf]);
    FUN_00541580();
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
}

extern uint8_t DAT_007275a0[];
extern void *PTR_FUN_006c3028;
extern void FUN_005411f0(void);

// 0x55a870 — observed shape
void FUN_0055a870(float *param_1)
{
    float fVar1;
    uint32_t uVar2;
    uint32_t uVar3;

    fVar1 = param_1[2] * param_1[2] + param_1[1] * param_1[1] + *param_1 * *param_1;
    if (fVar1 == 0.0f) {
        fVar1 = 0.0f;
    }
    else {
        uVar2 = ((uint32_t)*(uint32_t *)&fVar1 >> 0x17) - 0x7f;
        uVar3 = (uint32_t)*(uint32_t *)&fVar1 & 0x7fffff;
        if ((uVar2 & 1) != 0) {
            uVar3 = uVar3 | 0x800000;
        }
        uint32_t bits = (uint32_t)(((int16_t)uVar2 >> 1) + 0x7f) * 0x800000 | *(uint32_t *)(DAT_007275a0 + (uVar3 >> 0x10) * 4);
        fVar1 = 1.0f / (float)*(float *)&bits;
    }
    *param_1 = fVar1 * *param_1;
    param_1[1] = fVar1 * param_1[1];
    param_1[2] = fVar1 * param_1[2];
}

// 0x55ab40 — observed shape
void FUN_0055ab40(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7, uint16_t param_8)
{
    uint32_t *in_ECX;
    FUN_00541140(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c3028;
    *(uint16_t *)(in_ECX + 0xf) = param_8;
}

// 0x55ab90 — observed shape
void FUN_0055ab90(void *self_)
{
    uint32_t *in_ECX = (uint32_t *)self_;
    FUN_005411f0();
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c3028;
    *(uint16_t *)(in_ECX + 0xf) = 0;
}

// 0x55abb0 — observed shape
void FUN_0055abb0(void *self_)
{
    uint32_t *in_ECX = (uint32_t *)self_;
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c3028;
    FUN_00541580();
}

// 0x55abd0 — observed shape
uint16_t FUN_0055abd0(int param_1)
{
    uint16_t uVar1;
    int in_ECX;
    uVar1 = (uint16_t)FUN_00541de0(param_1);
    if ((char)uVar1 == '\0') {
        return uVar1;
    }
    return (uint16_t)(((uint8_t)((int16_t)*(int16_t *)(in_ECX + 0x3c) >> 8) << 8) | (uint8_t)(*(int16_t *)(in_ECX + 0x3c) == *(int16_t *)(param_1 + 0x3c)));
}

extern void FUN_005418d0(int p1);
extern void FUN_00541c20(int p1);
extern void FUN_005420e0(int p1);
extern int FUN_00557b10(int p1);
extern int FUN_00557c30(const char *a, uint16_t b);
extern void FUN_005606f0(uint32_t a, void *b);
extern void FUN_006b34a0(int p1);
extern int DAT_00727d14;
extern void FUN_00546ad0(void);
extern void *PTR_FUN_006c30ac;
extern void *PTR_FUN_006c309c;

// 0x55ac10 — observed shape
void FUN_0055ac10(void *self_, uint8_t param_1)
{
    uint32_t *in_ECX = (uint32_t *)self_;
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c3028;
    FUN_00541580();
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
}

// 0x55ac40 — observed shape
void FUN_0055ac40(int param_1)
{
    int in_ECX;
    typedef void (*code_t)(int, int);
    FUN_005418d0(param_1);
    (*(code_t *)((**(int **)(param_1 + 0x15c) + 8)))(in_ECX + 0x3c, 2);
}

// 0x55ac70 — observed shape
void FUN_0055ac70(int param_1)
{
    int in_ECX;
    typedef void (*code_t)(int, int);
    FUN_00541c20(param_1);
    (*(code_t *)((**(int **)(param_1 + 0x160) + 0xc)))(in_ECX + 0x3c, 2);
}

// 0x55aca0 — observed shape
void FUN_0055aca0(int param_1)
{
    uint32_t uVar1;
    int iVar2;
    int in_ECX;

    iVar2 = param_1;
    FUN_005420e0(param_1);
    param_1 = FUN_00557b10(DAT_00727d14);
    uVar1 = *(uint32_t *)(iVar2 + 0xc);
    if (*(uint32_t *)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int *)(iVar2 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
    param_1 = FUN_00557c30("m_usTriangles", *(uint16_t *)(in_ECX + 0x3c));
    uVar1 = *(uint32_t *)(iVar2 + 0xc);
    if (*(uint32_t *)(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*(int *)(iVar2 + 0x14) + uVar1);
    }
    FUN_005606f0(uVar1, &param_1);
}

// 0x55ad50 — observed shape
void FUN_0055ad50(void *self_)
{
    uint32_t *in_ECX = (uint32_t *)self_;
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c30ac;
    FUN_00546ad0();
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c309c;
    DeleteCriticalSection((LPCRITICAL_SECTION)(in_ECX + 1));
}
