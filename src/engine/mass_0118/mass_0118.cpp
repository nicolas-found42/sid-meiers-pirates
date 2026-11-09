#include <cstdint>
#include <cstddef>
#include <windows.h>

extern unsigned char FUN_00533df0(int param_1);
extern unsigned char FUN_00540b70(uint32_t param_1);
extern uint32_t *DAT_00727cd8;
extern void FUN_00533f70(uint32_t param_1);
extern void FUN_00533fc0(uint32_t param_1);
extern void FUN_00534040(uint32_t param_1);
extern void FUN_005340b0(uint32_t param_1);
extern uint32_t FUN_005340e0(uint32_t param_1);
extern void FUN_00534130(uint32_t param_1);
extern void FUN_00534210(uint32_t param_1);
extern void FUN_00534240(uint32_t param_1);
extern void FUN_00534270(uint32_t param_1);
extern uint32_t FUN_00534350(uint32_t param_1);
extern void FUN_00534410(uint32_t param_1);
extern void FUN_00534660(uint32_t param_1);

// 0x533e70 — observed shape
void FUN_00533e70(int param_1, void *self)
{
    int *selfPtr = (int *)self;
    int iVar1;
    char cVar2;

    if ((*(unsigned char *)((char *)self + 8 * 4) & 1) == 0) {
        iVar1 = *(int *)((char *)param_1 + 0x1ec);
        if (iVar1 == 0) {
            int *vtable = *(int **)self;
            ((void (*)(int))vtable[0x60 / 4])();
            return;
        }
        cVar2 = (char)FUN_00533df0(param_1);
        if (cVar2 == '\0') {
            int *vtable = *(int **)self;
            ((void (*)(void *))vtable[0x60 / 4])(self);
        }
        *(int *)((char *)param_1 + 0x1ec) = iVar1;
    }
}

// 0x533ec0 — observed shape
uint32_t FUN_00533ec0(unsigned char *param_1, uint32_t self)
{
    unsigned char bVar1;
    unsigned char *pbVar2;
    bool bVar3;

    if ((param_1 == nullptr) || ((pbVar2 = *(unsigned char **)(self + 0xc), pbVar2 == nullptr))) {
        return 0;
    }
    while (true) {
        bVar1 = *param_1;
        bVar3 = bVar1 < *pbVar2;
        if (bVar1 != *pbVar2) break;
        if (bVar1 == 0) {
            return self;
        }
        bVar1 = param_1[1];
        bVar3 = bVar1 < pbVar2[1];
        if (bVar1 != pbVar2[1]) break;
        param_1 = param_1 + 2;
        pbVar2 = pbVar2 + 2;
        if (bVar1 == 0) {
            return self;
        }
    }
    return ((1 - (uint32_t)bVar3 != (uint32_t)(bVar3 != 0)) - 1) & self;
}

// 0x533f50 — observed shape
unsigned char FUN_00533f50(uint32_t param_1, void *self)
{
    char cVar3;
    uint32_t *puVar2;
    int *piVar1;

    cVar3 = (char)FUN_00540b70(param_1);
    if (cVar3 == '\0') {
        return 0;
    }
    puVar2 = *(uint32_t **)((char *)self + 0xa4);
    while (puVar2 != nullptr) {
        piVar1 = (int *)(puVar2 + 2);
        uint32_t *puNext = (uint32_t *)*puVar2;
        if (*piVar1 != 0) {
            int *obj = (int *)*piVar1;
            int *vtable = *(int **)obj;
            ((void (*)(uint32_t))vtable[0x14 / 4])(param_1);
        }
        puVar2 = puNext;
    }
    if (*(int **)((char *)self + 0xb0) != nullptr) {
        int *obj2 = *(int **)((char *)self + 0xb0);
        int *vtable2 = *(int **)obj2;
        ((void (*)(uint32_t))vtable2[0x14 / 4])(param_1);
    }
    return 1;
}

// 0x533fa0 — observed shape
uint32_t *FUN_00533fa0(uint32_t param_1, unsigned char param_2, void *self)
{
    uint32_t *puVar3 = (uint32_t *)(uint32_t)(unsigned char)param_2;
    if (param_2 != 0) {
        uint32_t *puVar1 = *(uint32_t **)((char *)self + 0xa4);
        while (puVar1 != nullptr) {
            int *piVar2 = (int *)puVar1[2];
            uint32_t *puNext = (uint32_t *)*puVar1;
            puVar3 = puVar1 + 2;
            if (piVar2 != nullptr) {
                puVar3 = nullptr;
                if (piVar2[4] != 0) {
                    int *vtable = *(int **)piVar2;
                    puVar3 = (uint32_t *)((uint32_t * (*)(uint32_t))vtable[0x38 / 4])(param_1);
                }
            }
            puVar1 = puNext;
        }
    }
    for (int *piVar2 = *(int **)((char *)self + 0x10); piVar2 != nullptr; ) {
        int *vtable = *(int **)piVar2;
        puVar3 = (uint32_t *)((uint32_t * (*)(uint32_t))vtable[0x3c / 4])(param_1);
        piVar2 = (int *)piVar2[0xe];
    }
    return puVar3;
}

// 0x534000 — observed shape
void FUN_00534000(uint32_t *param_1)
{
    int iVar1;
    uint32_t *puVar2;

    puVar2 = DAT_00727cd8;
    if (DAT_00727cd8 != param_1) {
        if ((DAT_00727cd8 != nullptr) && ((iVar1 = (int)DAT_00727cd8[1], DAT_00727cd8[1] = (uint32_t)(iVar1 + -1), iVar1 + -1 == 0))) {
            ((void (*)(uint32_t))*(void **)puVar2)(1);
        }
        DAT_00727cd8 = param_1;
        if (param_1 != nullptr) {
            param_1[1] = param_1[1] + 1;
        }
    }
}

// ---------------------------------------------------------------------------
// Externals referenced by the retry batch (0x534040-0x534b40).
// ---------------------------------------------------------------------------
extern void FUN_005edba0(void);
extern void FUN_00540c90(void);
extern void FUN_00540c50(void);
extern void FUN_00540aa0(int param_1);
extern void FUN_00540af0(int param_1);
extern void FUN_00540bc0(void);
extern char FUN_00540f80(int param_1);
extern int FUN_00533c78(uint32_t size);
extern int thunk_FUN_00533c78(uint32_t size);
extern void *FUN_00557940(void);
extern void FUN_00557990(void);
extern int *FUN_0053b150(int **param_1);
extern int *FUN_0053bce0(int **param_1);
extern void *FUN_00557680(void *param_1);
extern void FUN_00535110(int param_1);
extern void FUN_00535150(int *param_1);
extern void FUN_0053d980(int param_1);
extern void FUN_0053d9c0(int *param_1);
extern void FUN_00545d20(void);
extern void FUN_00545cc0(void);
extern char FUN_00428470(void *param_1);
extern void *FUN_00545680(const char *param_1);
extern void *FUN_00545600(void);
extern int FUN_00545630(void);
extern char FUN_00557a60(int param_1);
extern void FUN_00428330(void **param_1, int **param_2);
extern void operator_delete__(void *param_1);

extern uint8_t PTR_FUN_006c0640[];
extern uint8_t PTR_FUN_00711808[];
extern uint8_t PTR_LAB_00711814[];

extern uint32_t DAT_0072741c;
extern uint32_t DAT_00727420;
extern uint8_t DAT_00727404[];
extern char DAT_00727720[];
extern uint16_t DAT_007273f8;
extern uint32_t DAT_00727430;
extern uint32_t DAT_00727434;
extern uint32_t DAT_00727438;

// 0x534040 — observed shape
void FUN_00534040_recon(void *self)
{
    uint32_t *p = (uint32_t *)self;
    int *piVar1;
    uint32_t *puVar2;

    p[0] = (uint32_t)(uintptr_t)PTR_FUN_006c0640;
    FUN_005edba0();
    puVar2 = (uint32_t *)p[0x2c];
    if (puVar2 != nullptr) {
        piVar1 = (int *)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (*(void (**)(int))*(void **)puVar2)(1);
        }
        p[0x2c] = 0;
    }
    puVar2 = (uint32_t *)p[0x2c];
    if (puVar2 != nullptr) {
        piVar1 = (int *)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (*(void (**)(int))*(void **)puVar2)(1);
        }
    }
    p[0x28] = (uint32_t)(uintptr_t)PTR_FUN_00711808;
    FUN_005edba0();
    p[0x28] = (uint32_t)(uintptr_t)PTR_LAB_00711814;
    FUN_00540c90();
}

// 0x5340b0 — observed shape
void FUN_005340b0_recon(uint32_t param_1, char param_2, void *self)
{
    if (param_2 != '\0') {
        FUN_00533fa0(param_1, 1, self);
    }
    (*(void (**)(void *))(*(int *)self + 0x6c))(self);
    (*(void (**)(void *))(*(int *)self + 0x68))(self);
}

// 0x5340e0 — observed shape
void FUN_005340e0_recon(uint32_t param_1, void *self)
{
    char *base = (char *)self;

    FUN_00533fa0(param_1, (unsigned char)((*(uint8_t *)(base + 0x20) >> 3) & 1), self);
    if (((*(uint8_t *)(base + 0x20) >> 2) & 1) != 0) {
        (*(void (**)(void *))(*(int *)self + 0x6c))(self);
        (*(void (**)(void *))(*(int *)self + 0x68))(self);
    }
}

// 0x534130 — observed shape
void FUN_00534130_recon(void *self)
{
    char *base = (char *)self;
    int *piVar2;
    int iVar3;
    uint32_t *puVar4;
    uint32_t *puVar5 = nullptr;
    int *local_4 = (int *)self;
    DWORD DVar1;

    DVar1 = GetCurrentThreadId();
    if (DAT_0072741c != DVar1) {
        EnterCriticalSection((LPCRITICAL_SECTION)DAT_00727404);
        DAT_0072741c = GetCurrentThreadId();
    }
    DAT_00727420 = DAT_00727420 + 1;
    if (*(int *)(base + 0x24) == 0) {
        iVar3 = FUN_00533c78(0x38);
        if (iVar3 != 0) {
            puVar4 = (uint32_t *)FUN_00557940();
            if (puVar4 != nullptr) {
                puVar4[1] = puVar4[1] + 1;
                puVar5 = puVar4;
            }
        }
    }
    else {
        piVar2 = (int *)FUN_0053b150(&local_4);
        puVar4 = (uint32_t *)*piVar2;
        if (puVar4 != nullptr) {
            puVar4[1] = puVar4[1] + 1;
            puVar5 = puVar4;
        }
        if ((local_4 != nullptr) && (iVar3 = local_4[1], local_4[1] = iVar3 + -1, iVar3 + -1 == 0)) {
            (*(void (**)(int))*(void **)local_4)(1);
        }
    }
    (*(void (**)(uint32_t *))(*(int *)self + 0x58))(puVar5);
    DVar1 = GetCurrentThreadId();
    if ((DAT_0072741c == DVar1) && (DAT_00727420 = DAT_00727420 + -1, DAT_00727420 == 0)) {
        DAT_0072741c = 0;
        LeaveCriticalSection((LPCRITICAL_SECTION)DAT_00727404);
    }
    if (puVar5 != nullptr) {
        piVar2 = (int *)(puVar5 + 1);
        *piVar2 = *piVar2 + -1;
        if (*piVar2 == 0) {
            (*(void (**)(int))*(void **)puVar5)(1);
        }
    }
}

// 0x534210 — observed shape
uint32_t FUN_00534210_recon(void *self)
{
    int *piVar1;
    char cVar2;

    piVar1 = *(int **)((char *)self + 0x10);
    while (true) {
        if (piVar1 == nullptr) {
            return 0;
        }
        cVar2 = (*(char (**)(void))(*piVar1 + 0x44))();
        if (cVar2 != '\0') break;
        piVar1 = (int *)piVar1[0xe];
    }
    return 1;
}

// 0x534240 — observed shape
uint32_t FUN_00534240_recon(void *self)
{
    int *piVar1;
    uint32_t *puVar2;

    puVar2 = *(uint32_t **)((char *)self + 0xa4);
    do {
        if (puVar2 == nullptr) {
            return 0;
        }
        piVar1 = (int *)(puVar2 + 2);
        puVar2 = (uint32_t *)*puVar2;
    } while ((*piVar1 == 0) || (*(int *)(*piVar1 + 0x10) == 0));
    return 1;
}

// 0x534270 — observed shape
void **FUN_00534270_recon(void **param_1, uint32_t *param_2, char param_3, void *self)
{
    char *base = (char *)self;
    int *piVar1;
    uint32_t *puVar2;
    int *piVar3;
    int *piVar4;
    int iVar5;
    uint32_t *puVar6;

    if (*(int *)(base + 0xac) == 0) {
        *param_1 = param_2;
        if (param_2 == nullptr) {
            return param_1;
        }
        param_2[1] = param_2[1] + 1;
        return param_1;
    }
    puVar6 = nullptr;
    if (param_3 != '\0') {
        iVar5 = FUN_00533c78(0x38);
        if (iVar5 == 0) goto LAB_005342ce;
        param_2 = (uint32_t *)FUN_00557680(param_2);
    }
    if (param_2 != nullptr) {
        param_2[1] = param_2[1] + 1;
        puVar6 = param_2;
    }
LAB_005342ce:
    puVar2 = *(uint32_t **)(base + 0xa4);
    while (puVar2 != nullptr) {
        piVar3 = (int *)puVar2[2];
        puVar2 = (uint32_t *)*puVar2;
        if (piVar3 != nullptr) {
            iVar5 = (*(int (**)(void))(*piVar3 + 0x34))();
            piVar4 = (int *)puVar6[iVar5 + 2];
            if (piVar4 != piVar3) {
                if (piVar4 != nullptr) {
                    piVar1 = piVar4 + 1;
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) {
                        (*(void (**)(int))*(void **)piVar4)(1);
                    }
                }
                puVar6[iVar5 + 2] = (uint32_t)(uintptr_t)piVar3;
                piVar3[1] = piVar3[1] + 1;
            }
        }
    }
    *param_1 = puVar6;
    if (puVar6 != nullptr) {
        iVar5 = puVar6[1];
        puVar6[1] = iVar5 + 1;
        puVar6[1] = iVar5;
        if (iVar5 == 0) {
            (*(void (**)(int))*(void **)puVar6)(1);
        }
    }
    return param_1;
}

// 0x534350 — observed shape
void FUN_00534350_recon(void *self)
{
    char *base = (char *)self;
    int iVar1;
    uint32_t *puVar2;
    int *piVar3;
    uint32_t *puVar4;
    int *local_4 = (int *)self;

    puVar4 = DAT_00727cd8;
    if (DAT_00727cd8 != nullptr) {
        iVar1 = (int)DAT_00727cd8[1];
        DAT_00727cd8[1] = (uint32_t)(iVar1 + -1);
        if (iVar1 + -1 == 0) {
            (*(void (**)(int))*(void **)puVar4)(1);
        }
        DAT_00727cd8 = nullptr;
    }
    puVar4 = nullptr;
    if (*(int *)(base + 0x24) != 0) {
        piVar3 = (int *)FUN_0053bce0(&local_4);
        puVar2 = (uint32_t *)*piVar3;
        if (puVar2 != nullptr) {
            puVar2[1] = puVar2[1] + 1;
            puVar4 = puVar2;
        }
        if ((local_4 != nullptr) && (iVar1 = local_4[1], local_4[1] = iVar1 + -1, iVar1 + -1 == 0)) {
            (*(void (**)(int))*(void **)local_4)(1);
        }
    }
    (*(void (**)(uint32_t *))(*(int *)self + 0x5c))(puVar4);
    puVar2 = DAT_00727cd8;
    if (DAT_00727cd8 != nullptr) {
        iVar1 = (int)DAT_00727cd8[1];
        DAT_00727cd8[1] = (uint32_t)(iVar1 + -1);
        if (iVar1 + -1 == 0) {
            (*(void (**)(int))*(void **)puVar2)(1);
        }
        DAT_00727cd8 = nullptr;
    }
    if (puVar4 != nullptr) {
        piVar3 = (int *)(puVar4 + 1);
        *piVar3 = *piVar3 + -1;
        if (*piVar3 == 0) {
            (*(void (**)(int))*(void **)puVar4)(1);
        }
    }
}

// 0x534410 — observed shape
// NOTE: `unaff_EBP` is a register read the listing never writes (its value is
// only compared against zero); kept as an explicit parameter, not fabricated.
void FUN_00534410_recon(int param_1, int unaff_EBP, void *self)
{
    char *base = (char *)self;
    uint16_t *puVar1;
    int *piVar2;
    uint32_t *puVar3;
    uint8_t bVar4;
    char cVar5;
    uint32_t *puVar6;
    char *pcVar7;
    char *pcVar8;
    bool bVar9;
    int iVar10;
    uint16_t uVar11;
    uint8_t auStack_26[6];
    uint8_t abStack_c[12];
    struct {
        uint32_t owner;
        uint32_t uStack_1c;
        uint32_t uStack_18;
        uint32_t iStack_14;
    } args;
    int *reader;

    FUN_00540aa0(param_1);
    iVar10 = 2;
    puVar1 = (uint16_t *)(base + 0x20);
    reader = *(int **)(param_1 + 0x15c);
    (*(void (**)(uint16_t *))(*reader + 8))(puVar1);
    if (*(uint32_t *)(param_1 + 0x1c) < 0x401000b) {
        *puVar1 = (uint16_t)(((*puVar1 & 0xfff8) << 1) | (*puVar1 & 7));
    }
    if (*(uint32_t *)(param_1 + 0x1c) < 0x401000c) {
        *puVar1 = (uint16_t)((((*puVar1 & 0xfff7) | 7) << 4) | (*puVar1 & 0xf));
    }
    if (*(uint32_t *)(param_1 + 0x1c) < 0x5000001) {
        *puVar1 = (uint16_t)(((*puVar1 & 0xff00) << 1) | (*puVar1 & 0xff));
    }
    FUN_00535110(param_1);
    FUN_0053d980(param_1);
    (*(void (**)(void *, uint32_t))(*reader + 8))(base + 0x68, 4);
    if (*(uint32_t *)(param_1 + 0x1c) < 0x5000013) {
        bVar4 = (uint8_t)*puVar1;
        uVar11 = (uint16_t)((bVar4 >> 1) & 7);
        *puVar1 = (uint16_t)(((uint8_t)((bVar4 >> 3) ^ bVar4) & 1) ^ (*puVar1 >> 3));
        FUN_00535110(param_1);
        FUN_00545d20();
        if (*(uint32_t *)(param_1 + 0x1c) < 0x4010000) {
            (*(void (**)(void *, uint32_t))(*reader + 8))(auStack_26 - 10, 4);
            abStack_c[0] = (uint8_t)(unaff_EBP != 0);
        }
        else {
            (*(void (**)(void *, uint32_t))(*reader + 8))(abStack_c, 1);
        }
        iVar10 = 0x12;
        bVar9 = true;
        pcVar7 = DAT_00727720;
        pcVar8 = (char *)"NiCollisionSwitch";
        do {
            if (iVar10 == 0) break;
            iVar10 = iVar10 + -1;
            bVar9 = *pcVar7 == *pcVar8;
            pcVar7 = pcVar7 + 1;
            pcVar8 = pcVar8 + 1;
        } while (bVar9);
        if ((bVar9) && (((*puVar1 >> 3) & 1) == 0)) {
            uVar11 = 4;
        }
        if ((((abStack_c[0] != 0) || (cVar5 = FUN_00428470(&DAT_00727430), cVar5 != '\0')) ||
             (uVar11 != 2)) &&
            (puVar6 = (uint32_t *)FUN_00545680("NiCollisionData"), puVar6 != nullptr)) {
            puVar3 = *(uint32_t **)(base + 0xb0);
            if (puVar3 != puVar6) {
                if (puVar3 != nullptr) {
                    piVar2 = (int *)(puVar3 + 1);
                    *piVar2 = *piVar2 + -1;
                    if (*piVar2 == 0) {
                        (*(void (**)(int))*(void **)puVar3)(1);
                    }
                }
                *(uint32_t **)(base + 0xb0) = puVar6;
                puVar6[1] = puVar6[1] + 1;
            }
            args.owner = (uint32_t)(uintptr_t)self;
            args.uStack_1c = (uint32_t)uVar11;
            args.uStack_18 = (uint32_t)abStack_c[0];
            args.iStack_14 = (uint32_t)param_1;
            (*(void (**)(void *))(**(int **)(base + 0xb0) + 0x40))(&args);
        }
    }
    else {
        FUN_00545d20();
        FUN_00545cc0();
    }
    if (*(uint32_t *)(param_1 + 0x1c) < 0xa000102) {
        DAT_007273f8 = *puVar1;
        *puVar1 = (uint16_t)(*puVar1 & 0x3f);
    }
    if ((*(uint32_t *)(param_1 + 0x1c) < 0xa000106) && (*(int **)(base + 0xb0) != nullptr)) {
        (*(void (**)(uint32_t, int))(**(int **)(base + 0xb0) + 0x44))(*(uint32_t *)(param_1 + 0x1c), 0);
    }
}

// 0x534660 — observed shape
void FUN_00534660_recon(int param_1, void *self)
{
    char *base = (char *)self;
    int *piVar1;
    uint32_t *puVar2;
    uint32_t *puVar3;
    uint32_t *puVar4;
    int local_4;

    FUN_00540af0(param_1);
    local_4 = FUN_00545630();
    if (*(uint32_t *)(param_1 + 0x1c) < 0x4010008) {
        if (local_4 != 0) {
            do {
                puVar2 = (uint32_t *)FUN_00545600();
                if (puVar2 != nullptr) {
                    puVar2[1] = puVar2[1] + 1;
                }
                puVar3 = (uint32_t *)(*(void *(**)(void))((char *)(uintptr_t)*(int *)(base + 0xa0) + 4))();
                puVar4 = (uint32_t *)puVar3[2];
                if (puVar4 != puVar2) {
                    if (puVar4 != nullptr) {
                        piVar1 = (int *)(puVar4 + 1);
                        *piVar1 = *piVar1 + -1;
                        if (*piVar1 == 0) {
                            (*(void (**)(int))*(void **)puVar4)(1);
                        }
                    }
                    puVar3[2] = (uint32_t)(uintptr_t)puVar2;
                    if (puVar2 != nullptr) {
                        puVar2[1] = puVar2[1] + 1;
                    }
                }
                *puVar3 = 0;
                puVar3[1] = *(uint32_t *)(base + 0xa8);
                if (*(uint32_t **)(base + 0xa8) == nullptr) {
                    *(uint32_t **)(base + 0xa4) = puVar3;
                }
                else {
                    **(uint32_t **)(base + 0xa8) = (uint32_t)(uintptr_t)puVar3;
                }
                *(uint32_t **)(base + 0xa8) = puVar3;
                *(int *)(base + 0xac) = *(int *)(base + 0xac) + 1;
                if (puVar2 != nullptr) {
                    piVar1 = (int *)(puVar2 + 1);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) {
                        (*(void (**)(int))*(void **)puVar2)(1);
                    }
                }
                local_4 = local_4 + -1;
            } while (local_4 != 0);
            return;
        }
    }
    else {
        if (local_4 != 0) {
            do {
                puVar2 = (uint32_t *)FUN_00545600();
                if (puVar2 != nullptr) {
                    puVar2[1] = puVar2[1] + 1;
                }
                puVar3 = (uint32_t *)(*(void *(**)(void))((char *)(uintptr_t)*(int *)(base + 0xa0) + 4))();
                puVar4 = (uint32_t *)puVar3[2];
                if (puVar4 != puVar2) {
                    if (puVar4 != nullptr) {
                        piVar1 = (int *)(puVar4 + 1);
                        *piVar1 = *piVar1 + -1;
                        if (*piVar1 == 0) {
                            (*(void (**)(int))*(void **)puVar4)(1);
                        }
                    }
                    puVar3[2] = (uint32_t)(uintptr_t)puVar2;
                    if (puVar2 != nullptr) {
                        puVar2[1] = puVar2[1] + 1;
                    }
                }
                puVar3[1] = 0;
                *puVar3 = *(uint32_t *)(base + 0xa4);
                if (*(int *)(base + 0xa4) == 0) {
                    *(uint32_t **)(base + 0xa8) = puVar3;
                }
                else {
                    *(uint32_t **)(*(int *)(base + 0xa4) + 4) = puVar3;
                }
                *(uint32_t **)(base + 0xa4) = puVar3;
                *(int *)(base + 0xac) = *(int *)(base + 0xac) + 1;
                if (puVar2 != nullptr) {
                    piVar1 = (int *)(puVar2 + 1);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) {
                        (*(void (**)(int))*(void **)puVar2)(1);
                    }
                }
                local_4 = local_4 + -1;
            } while (local_4 != 0);
        }
        if (0x5000012 < *(uint32_t *)(param_1 + 0x1c)) {
            puVar4 = (uint32_t *)FUN_00545600();
            puVar2 = *(uint32_t **)(base + 0xb0);
            if (puVar2 != puVar4) {
                if (puVar2 != nullptr) {
                    piVar1 = (int *)(puVar2 + 1);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) {
                        (*(void (**)(int))*(void **)puVar2)(1);
                    }
                }
                *(uint32_t **)(base + 0xb0) = puVar4;
                if (puVar4 != nullptr) {
                    puVar4[1] = puVar4[1] + 1;
                }
            }
            if (*(int **)(base + 0xb0) != nullptr) {
                (*(void (**)(uint32_t, int))(**(int **)(base + 0xb0) + 0x44))(*(uint32_t *)(param_1 + 0x1c), 0);
            }
        }
    }
}

// 0x534810 — observed shape
void FUN_00534810_recon(int *param_1, void *self)
{
    char *base = (char *)self;
    int *piVar1;
    int *piVar2;
    int *piVar3;
    int *piVar4;
    int iVar5;
    int *piStack_c;
    int *stream;

    FUN_00540bc0();
    stream = (int *)param_1[0x58];
    (*(void (**)(void *))(*stream + 0xc))(base + 0x20);
    FUN_00535150(param_1);
    FUN_0053d9c0(param_1);
    iVar5 = 4;
    (*(void (**)(void *))(*stream + 0xc))(base + 0x68);
    piStack_c = *(int **)(base + 0xac);
    (*(void (**)(int **, uint32_t))(*stream + 0xc))(&piStack_c, 4);
    if (0 < iVar5) {
        piVar2 = (int *)thunk_FUN_00533c78(iVar5 * 4);
        piVar3 = *(int **)(base + 0xa4);
        if (piVar3 != nullptr) {
            piVar4 = piVar2;
            do {
                piVar1 = piVar3 + 2;
                piVar3 = (int *)*piVar3;
                *piVar4 = *piVar1;
                piVar4 = piVar4 + 1;
            } while (piVar3 != nullptr);
        }
        while (iVar5 = iVar5 + -1, -1 < iVar5) {
            (*(void (**)(int))(*param_1 + 0x2c))(piVar2[iVar5]);
        }
        operator_delete__(piVar2);
    }
    (*(void (**)(void *))(*param_1 + 0x2c))(*(void **)(base + 0xb0));
}

// 0x5348e0 — observed shape
uint32_t FUN_005348e0_recon(int param_1, void *self)
{
    char *base = (char *)self;
    uint32_t *puVar1;
    uint32_t *puVar2;
    int iVar3;
    int *piVar4;
    int *piVar5;
    char cVar6;

    cVar6 = FUN_00540f80(param_1);
    if (((cVar6 == '\0') || (((*(uint8_t *)(param_1 + 0x20) ^ *(uint8_t *)(base + 0x20)) & 1) != 0)) ||
        (cVar6 = FUN_00557a60(param_1 + 0x38), cVar6 != '\0') ||
        (*(int *)(base + 0xac) != *(int *)(param_1 + 0xac))) {
        return 0;
    }
    if (*(int *)(base + 0xac) == 0) {
LAB_0053495c:
        piVar4 = *(int **)(base + 0xb0);
        if (piVar4 != nullptr) {
            iVar3 = piVar4[1];
            piVar4[1] = iVar3 + 1;
            piVar4[1] = iVar3;
            if (iVar3 == 0) {
                (*(void (**)(int))*(void **)piVar4)(1);
            }
        }
        piVar5 = *(int **)(param_1 + 0xb0);
        if (piVar5 != nullptr) {
            iVar3 = piVar5[1];
            piVar5[1] = iVar3 + 1;
            piVar5[1] = iVar3;
            if (iVar3 == 0) {
                (*(void (**)(int))*(void **)piVar5)(1);
            }
        }
        if ((piVar4 == nullptr) || (piVar5 == nullptr)) {
            if (piVar4 == piVar5) {
                return 1;
            }
        }
        else {
            cVar6 = (*(char (**)(int *))(*piVar4 + 0x1c))(piVar5);
            if (cVar6 != '\0') {
                return 1;
            }
        }
    }
    else {
        puVar1 = *(uint32_t **)(base + 0xa4);
        puVar2 = *(uint32_t **)(param_1 + 0xa4);
        do {
            while (true) {
                if (puVar1 == nullptr) goto LAB_0053495c;
                piVar4 = (int *)(puVar1 + 2);
                puVar1 = (uint32_t *)*puVar1;
                piVar5 = (int *)(puVar2 + 2);
                puVar2 = (uint32_t *)*puVar2;
                iVar3 = *piVar5;
                if (*piVar4 == 0) break;
                if (iVar3 == 0) {
                    return 0;
                }
                cVar6 = (*(char (**)(int))(*(int *)(uintptr_t)*piVar4 + 0x1c))(iVar3);
                if (cVar6 == '\0') {
                    return 0;
                }
            }
        } while (iVar3 == 0);
    }
    return 0;
}

// 0x5349d0 — observed shape
void FUN_005349d0_recon(void *self)
{
    uint32_t *p = (uint32_t *)self;
    int *piVar1;
    uint32_t *puVar2;
    uint32_t uVar3;

    FUN_00540c50();
    p[0] = (uint32_t)(uintptr_t)PTR_FUN_006c0640;
    p[0x2b] = 0;
    p[0x29] = 0;
    p[0x2a] = 0;
    p[0x28] = (uint32_t)(uintptr_t)PTR_FUN_00711808;
    p[0x2c] = 0;
    p[9] = 0;
    *(uint16_t *)((char *)p + 0x20) = 0;
    FUN_00557990();
    FUN_00557990();
    p[10] = DAT_00727430;
    p[0xb] = DAT_00727434;
    uVar3 = DAT_00727438;
    p[0xd] = 0;
    p[0xc] = uVar3;
    *(uint16_t *)((char *)p + 0x20) = (uint16_t)((*(uint16_t *)((char *)p + 0x20) & 0xfff1) | 0x10);
    puVar2 = (uint32_t *)p[0x2c];
    if (puVar2 != nullptr) {
        piVar1 = (int *)(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (*(void (**)(int))*(void **)puVar2)(1);
        }
        p[0x2c] = 0;
    }
}

// 0x534a90 — observed shape
void **FUN_00534a90_recon(void **param_1, int *param_2, void *self)
{
    uint32_t *p = (uint32_t *)self;
    int *piVar1;
    uint32_t *puVar2;
    int *piVar3;
    int iVar4;
    int iVar5;
    void *puStack_4;

    iVar4 = (int)param_2;
    puVar2 = (uint32_t *)p[0x29];
    puStack_4 = self;
    while (true) {
        do {
            if (puVar2 == nullptr) {
                *param_1 = nullptr;
                return param_1;
            }
            piVar3 = (int *)puVar2[2];
            puVar2 = (uint32_t *)*puVar2;
        } while (piVar3 == nullptr);
        piVar3[1] = piVar3[1] + 1;
        param_2 = piVar3;
        iVar5 = (*(int (**)(void))(*piVar3 + 0x34))();
        if (iVar5 == iVar4) break;
        piVar1 = piVar3 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            (*(void (**)(int))*(void **)piVar3)(1);
        }
    }
    FUN_00428330(&puStack_4, &param_2);
    if (puStack_4 != nullptr) {
        piVar3 = (int *)((uint32_t *)puStack_4 + 1);
        *piVar3 = *piVar3 + -1;
        if (*piVar3 == 0) {
            (*(void (**)(int))*(void **)puStack_4)(1);
        }
    }
    *param_1 = param_2;
    if (param_2 != nullptr) {
        iVar4 = param_2[1];
        param_2[1] = iVar4 + 1;
        param_2[1] = iVar4;
        if (iVar4 == 0) {
            (*(void (**)(int))*(void **)param_2)(1);
        }
    }
    return param_1;
}

// 0x534b40 — observed shape
void FUN_00534b40_recon(uint8_t *param_1, char param_2, void *param_3, void *self)
{
    char *base = (char *)self;
    int *piVar1;
    uint32_t *puVar2;
    bool bVar3;
    char cVar4;

    for (piVar1 = *(int **)(base + 0x10); piVar1 != nullptr; piVar1 = (int *)piVar1[0xe]) {
        cVar4 = (*(char (**)(void))(*piVar1 + 0x44))();
        if (cVar4 != '\0') {
            bVar3 = true;
            goto LAB_00534b64;
        }
    }
    bVar3 = false;
LAB_00534b64:
    *(bool *)param_3 = !bVar3;
    if (param_2 == '\0') {
        param_2 = (char)bVar3;
    }
    puVar2 = *(uint32_t **)(base + 0xa4);
    do {
        if (puVar2 == nullptr) {
            bVar3 = false;
            if ((param_2 != '\0') || (*(int *)(base + 0x10) != 0)) goto LAB_00534bca;
            *param_1 = 0;
            *(uint8_t *)(base + 0x20) = *(uint8_t *)(base + 0x20) & 0xfd;
            goto LAB_00534bb3;
        }
        piVar1 = (int *)(puVar2 + 2);
        puVar2 = (uint32_t *)*puVar2;
    } while ((*piVar1 == 0) || (*(int *)(*piVar1 + 0x10) == 0));
    bVar3 = true;
LAB_00534bca:
    *param_1 = 1;
    *(uint8_t *)(base + 0x20) = *(uint8_t *)(base + 0x20) | 2;
    if (param_2 == '\0') {
LAB_00534bb3:
        *(uint8_t *)(base + 0x20) = *(uint8_t *)(base + 0x20) & 0xfb;
    }
    else {
        *(uint16_t *)(base + 0x20) = *(uint16_t *)(base + 0x20) | 4;
    }
    if (bVar3) {
        *(uint8_t *)(base + 0x20) = *(uint8_t *)(base + 0x20) | 0x18;
        return;
    }
    *(uint8_t *)(base + 0x20) = *(uint8_t *)(base + 0x20) & 0xf7;
    *(uint8_t *)(base + 0x20) = *(uint8_t *)(base + 0x20) | 0x10;
    return;
}
