#include <cstdint>
#include <cstddef>
#include <windows.h>

extern uint32_t *FUN_00546930();
extern char FUN_00545060(uint32_t param_2);
extern uint32_t *FUN_00571060(uint32_t *param_1, void *local_1b0, uint32_t param_3);
extern uint32_t *FUN_00546ad0();
extern void *thunk_FUN_00533c78(uint32_t size);
extern void operator_delete__(void *ptr);

// 0x571140 — observed shape
uint32_t *FUN_00571140(uint32_t *param_1, uint32_t param_2, uint32_t param_3)
{
    char cVar1;
    uint8_t local_1b0[432];

    FUN_00546930();
    cVar1 = FUN_00545060(param_2);
    if (cVar1 == '\0') {
        *param_1 = 0;
        FUN_00546ad0();
        return param_1;
    }
    FUN_00571060(param_1, local_1b0, param_3);
    FUN_00546ad0();
    return param_1;
}

// 0x5711b0 — observed shape
uint32_t *FUN_005711b0(char *param_1, char *param_2, void *self)
{
    char cVar1;
    char *pcVar2;
    uint32_t *in_ECX = reinterpret_cast<uint32_t *>(self);

    in_ECX[0] = 0;
    if (param_1 != nullptr) {
        pcVar2 = param_1;
        do {
            cVar1 = *pcVar2;
            pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        pcVar2 = reinterpret_cast<char *>(thunk_FUN_00533c78(reinterpret_cast<uint32_t>(pcVar2 + (1 - reinterpret_cast<int>(param_1 + 1))))));
        in_ECX[0] = reinterpret_cast<uint32_t>(pcVar2);
        do {
            cVar1 = *param_1;
            param_1 = param_1 + 1;
            *pcVar2 = cVar1;
            pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
    }
    in_ECX[1] = 0;
    if (param_2 != nullptr) {
        pcVar2 = param_2;
        do {
            cVar1 = *pcVar2;
            pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        pcVar2 = reinterpret_cast<char *>(thunk_FUN_00533c78(reinterpret_cast<uint32_t>(pcVar2 + (1 - reinterpret_cast<int>(param_2 + 1))))));
        in_ECX[1] = reinterpret_cast<uint32_t>(pcVar2);
        do {
            cVar1 = *param_2;
            param_2 = param_2 + 1;
            *pcVar2 = cVar1;
            pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
    }
    return in_ECX;
}

// 0x571240 — observed shape
void FUN_00571240(char *param_1, void *self)
{
    char cVar1;
    char *pcVar2;
    uint32_t in_ECX = reinterpret_cast<uint32_t>(self);

    operator_delete__(*reinterpret_cast<void **>(in_ECX + 8));
    *reinterpret_cast<uint32_t *>(in_ECX + 8) = 0;
    if (param_1 != nullptr) {
        pcVar2 = param_1;
        do {
            cVar1 = *pcVar2;
            pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        pcVar2 = reinterpret_cast<char *>(thunk_FUN_00533c78(reinterpret_cast<uint32_t>(pcVar2 + (1 - reinterpret_cast<int>(param_1 + 1))))));
        *reinterpret_cast<char **>(in_ECX + 8) = pcVar2;
        do {
            cVar1 = *param_1;
            param_1 = param_1 + 1;
            *pcVar2 = cVar1;
            pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
    }
    return;
}

// 0x571290 — observed shape
void FUN_00571290(char *param_1, void *self)
{
    char cVar1;
    char *pcVar2;
    uint32_t in_ECX = reinterpret_cast<uint32_t>(self);

    operator_delete__(*reinterpret_cast<void **>(in_ECX + 0xc));
    *reinterpret_cast<uint32_t *>(in_ECX + 0xc) = 0;
    if (param_1 != nullptr) {
        pcVar2 = param_1;
        do {
            cVar1 = *pcVar2;
            pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        pcVar2 = reinterpret_cast<char *>(thunk_FUN_00533c78(reinterpret_cast<uint32_t>(pcVar2 + (1 - reinterpret_cast<int>(param_1 + 1))))));
        *reinterpret_cast<char **>(in_ECX + 0xc) = pcVar2;
        do {
            cVar1 = *param_1;
            param_1 = param_1 + 1;
            *pcVar2 = cVar1;
            pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
    }
    return;
}

// 0x5712e0 — observed shape
void FUN_005712e0(char *param_1, void *self)
{
    char cVar1;
    char *pcVar2;
    uint32_t in_ECX = reinterpret_cast<uint32_t>(self);
    int iVar3;
    char *pcVar4;
    bool bVar5;

    operator_delete__(*reinterpret_cast<void **>(in_ECX + 0x34));
    *reinterpret_cast<uint32_t *>(in_ECX + 0x34) = 0;
    if (param_1 != nullptr) {
        iVar3 = 1;
        bVar5 = true;
        pcVar2 = param_1;
        pcVar4 = const_cast<char>("");
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
            pcVar2 = reinterpret_cast<char *>(thunk_FUN_00533c78(reinterpret_cast<uint32_t>(pcVar2 + (1 - reinterpret_cast<int>(param_1 + 1))))));
            *reinterpret_cast<char **>(in_ECX + 0x34) = pcVar2;
            do {
                cVar1 = *param_1;
                param_1 = param_1 + 1;
                *pcVar2 = cVar1;
                pcVar2 = pcVar2 + 1;
            } while (cVar1 != '\0');
        }
    }
    return;
}

extern void FUN_005e1490(void *self);
extern void operator_delete(void *ptr);
extern uint32_t PTR_FUN_006c3ee4;
extern uint32_t PTR_FUN_006c3ee8;
extern uint32_t PTR_FUN_006c3f04;
extern uint32_t PTR_FUN_006c3f3c;

// 0x571350 — observed shape
void FUN_00571350(char *param_1, void *self)
{
    char cVar1;
    char *pcVar2;
    uint32_t in_ECX = reinterpret_cast<uint32_t>(self);
    int iVar3;
    char *pcVar4;
    bool bVar5;

    operator_delete__(*reinterpret_cast<void **>(in_ECX + 0x38));
    *reinterpret_cast<uint32_t *>(in_ECX + 0x38) = 0;
    if (param_1 != nullptr) {
        iVar3 = 1;
        bVar5 = true;
        pcVar2 = param_1;
        pcVar4 = const_cast<char>("");
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
            pcVar2 = reinterpret_cast<char *>(thunk_FUN_00533c78(reinterpret_cast<uint32_t>(pcVar2 + (1 - reinterpret_cast<int>(param_1 + 1))))));
            *reinterpret_cast<char **>(in_ECX + 0x38) = pcVar2;
            do {
                cVar1 = *param_1;
                param_1 = param_1 + 1;
                *pcVar2 = cVar1;
                pcVar2 = pcVar2 + 1;
            } while (cVar1 != '\0');
        }
    }
    return;
}

// 0x5713e0 — observed shape
void FUN_005713e0(uint8_t param_1, void *self)
{
    uint32_t *in_ECX = reinterpret_cast<uint32_t *>(self);

    *in_ECX = PTR_FUN_006c3ee4;
    operator_delete__(reinterpret_cast<void *>(in_ECX[1]));
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
    return;
}

// 0x571410 — observed shape
void FUN_00571410(uint8_t param_1, void *self)
{
    uint32_t *in_ECX = reinterpret_cast<uint32_t *>(self);

    *in_ECX = PTR_FUN_006c3ee8;
    FUN_005e1490(in_ECX);
    operator_delete__(reinterpret_cast<void *>(in_ECX[2]));
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
    return;
}

// 0x571450 — observed shape
void FUN_00571450(uint8_t param_1, void *self)
{
    uint32_t *in_ECX = reinterpret_cast<uint32_t *>(self);

    *in_ECX = PTR_FUN_006c3f3c;
    FUN_005e1490(in_ECX);
    *in_ECX = PTR_FUN_006c3ee8;
    FUN_005e1490(in_ECX);
    operator_delete__(reinterpret_cast<void *>(in_ECX[2]));
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
    return;
}

// 0x571490 — observed shape
void FUN_00571490(uint8_t param_1, void *self)
{
    uint32_t *in_ECX = reinterpret_cast<uint32_t *>(self);

    *in_ECX = PTR_FUN_006c3f04;
    FUN_005e1490(in_ECX);
    operator_delete__(reinterpret_cast<void *>(in_ECX[2]));
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
    return;
}

extern uint32_t PTR_FUN_006c3f20;
extern uint32_t PTR_FUN_006c3f58;
extern uint32_t PTR_FUN_006c3f74;
extern int *FUN_005aead0(int **param_1, int **param_2, void *local_4);

// 0x5714d0 — observed shape
void FUN_005714d0(uint8_t param_1, void *self)
{
    uint32_t *in_ECX = reinterpret_cast<uint32_t *>(self);

    *in_ECX = PTR_FUN_006c3f58;
    FUN_005e1490(in_ECX);
    *in_ECX = PTR_FUN_006c3f04;
    FUN_005e1490(in_ECX);
    operator_delete__(reinterpret_cast<void *>(in_ECX[2]));
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
    return;
}

// 0x571510 — observed shape
void FUN_00571510(uint8_t param_1, void *self)
{
    uint32_t *in_ECX = reinterpret_cast<uint32_t *>(self);

    *in_ECX = PTR_FUN_006c3f20;
    FUN_005e1490(in_ECX);
    operator_delete__(reinterpret_cast<void *>(in_ECX[2]));
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
    return;
}

// 0x571550 — observed shape
void FUN_00571550(uint8_t param_1, void *self)
{
    uint32_t *in_ECX = reinterpret_cast<uint32_t *>(self);

    *in_ECX = PTR_FUN_006c3f74;
    FUN_005e1490(in_ECX);
    *in_ECX = PTR_FUN_006c3f20;
    FUN_005e1490(in_ECX);
    operator_delete__(reinterpret_cast<void *>(in_ECX[2]));
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
    return;
}

// 0x571590 — observed shape
void FUN_00571590(uint32_t param_1, char *param_2, void *self)
{
    char cVar1;
    char *pcVar2;
    uint32_t *in_ECX = reinterpret_cast<uint32_t *>(self);

    *in_ECX = param_1;
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    in_ECX[6] = 0;
    in_ECX[7] = 0;
    in_ECX[1] = 0;
    if (param_2 != nullptr) {
        pcVar2 = param_2;
        do {
            cVar1 = *pcVar2;
            pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        pcVar2 = reinterpret_cast<char *>(thunk_FUN_00533c78(reinterpret_cast<uint32_t>(pcVar2 + (1 - reinterpret_cast<int>(param_2 + 1))))));
        in_ECX[1] = reinterpret_cast<uint32_t>(pcVar2);
        do {
            cVar1 = *param_2;
            param_2 = param_2 + 1;
            *pcVar2 = cVar1;
            pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
    }
    return;
}

// 0x571600 — observed shape
void FUN_00571600(int *param_1, int *param_2, void *self)
{
    int *piVar1;
    int iVar2;
    uint32_t uVar3;
    uint32_t in_ECX = reinterpret_cast<uint32_t>(self);
    int *piVar4;
    uint8_t local_4[4];

    iVar2 = *reinterpret_cast<int *>(in_ECX + 0x1c);
    *param_2 = iVar2;
    if (iVar2 == 0) {
        *param_1 = 0;
        return;
    }
    iVar2 = reinterpret_cast<int>(thunk_FUN_00533c78(static_cast<uint32_t>(iVar2 << 2)));
    piVar1 = param_1;
    *param_1 = iVar2;
    uVar3 = 0;
    if (*reinterpret_cast<uint32_t *>(in_ECX + 0x14) != 0) {
        piVar4 = *reinterpret_cast<int **>(in_ECX + 0x18);
        do {
            if (*piVar4 != 0) {
                param_1 = (*reinterpret_cast<int **>(in_ECX + 0x18))[uVar3];
                goto LAB_00571650;
            }
            uVar3 = uVar3 + 1;
            piVar4 = piVar4 + 1;
        } while (uVar3 < *reinterpret_cast<uint32_t *>(in_ECX + 0x14));
    }
    param_1 = nullptr;
LAB_00571650:
    if (param_1 != nullptr) {
        iVar2 = 0;
        do {
            FUN_005aead0(&param_1, &param_2, local_4);
            *reinterpret_cast<int **>(iVar2 + *piVar1) = param_2;
            iVar2 = iVar2 + 4;
        } while (param_1 != nullptr);
    }
    return;
}

extern uint32_t PTR_LAB_006fd148;
extern uint32_t PTR_FUN_006c3f90;
extern int DAT_00727444;
extern char FUN_005bd960(int param_1, int *param_out);
extern int FUN_0055f300(int iVar4);
extern uint32_t FUN_00545310(void *pvVar1, uint32_t uVar5);

// 0x5716a0 — observed shape
void FUN_005716a0(uint8_t param_1, void *self)
{
    uint32_t *puVar1;
    uint32_t *in_ECX = reinterpret_cast<uint32_t *>(self);
    uint32_t uVar2;
    int iVar3;

    *in_ECX = PTR_LAB_006fd148;
    in_ECX[1] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    *in_ECX = PTR_FUN_006c3f90;
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = PTR_FUN_006c3f04;
    in_ECX[5] = 0x25;
    in_ECX[7] = 0;
    puVar1 = reinterpret_cast<uint32_t *>(thunk_FUN_00533c78(0x94));
    in_ECX[6] = reinterpret_cast<uint32_t>(puVar1);
    for (uVar2 = in_ECX[5] & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar1 = 0;
        puVar1 = puVar1 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *reinterpret_cast<uint8_t *>(puVar1) = 0;
        puVar1 = reinterpret_cast<uint32_t *>(reinterpret_cast<uint32_t>(puVar1) + 1);
    }
    in_ECX[4] = PTR_FUN_006c3f58;
    in_ECX[8] = PTR_FUN_006c3f20;
    in_ECX[9] = 0x25;
    in_ECX[0xb] = 0;
    puVar1 = reinterpret_cast<uint32_t *>(thunk_FUN_00533c78(0x94));
    in_ECX[10] = reinterpret_cast<uint32_t>(puVar1);
    for (uVar2 = in_ECX[9] & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar1 = 0;
        puVar1 = puVar1 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *reinterpret_cast<uint8_t *>(puVar1) = 0;
        puVar1 = reinterpret_cast<uint32_t *>(reinterpret_cast<uint32_t>(puVar1) + 1);
    }
    in_ECX[8] = PTR_FUN_006c3f74;
    *reinterpret_cast<uint8_t *>(reinterpret_cast<uint32_t>(in_ECX) + 0xc) = param_1;
    in_ECX[0xd] = 0;
    in_ECX[0xe] = 0;
    return;
}

// 0x571760 — observed shape
void FUN_00571760(uint32_t param_1, char *param_2, char *param_3, uint32_t param_4, void *self)
{
    char cVar1;
    uint32_t *puVar2;
    char *pcVar3;
    uint32_t *in_ECX = reinterpret_cast<uint32_t *>(self);
    uint32_t uVar4;
    int iVar5;

    *in_ECX = param_1;
    in_ECX[3] = param_4;
    in_ECX[4] = PTR_FUN_006c3ee8;
    in_ECX[5] = 0x25;
    in_ECX[7] = 0;
    puVar2 = reinterpret_cast<uint32_t *>(thunk_FUN_00533c78(0x94));
    in_ECX[6] = reinterpret_cast<uint32_t>(puVar2);
    for (uVar4 = in_ECX[5] & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *reinterpret_cast<uint8_t *>(puVar2) = 0;
        puVar2 = reinterpret_cast<uint32_t *>(reinterpret_cast<uint32_t>(puVar2) + 1);
    }
    in_ECX[4] = PTR_FUN_006c3f3c;
    in_ECX[1] = 0;
    if (param_2 != nullptr) {
        pcVar3 = param_2;
        do {
            cVar1 = *pcVar3;
            pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
        pcVar3 = reinterpret_cast<char *>(thunk_FUN_00533c78(reinterpret_cast<uint32_t>(pcVar3 + (1 - reinterpret_cast<int>(param_2 + 1))))));
        in_ECX[1] = reinterpret_cast<uint32_t>(pcVar3);
        do {
            cVar1 = *param_2;
            param_2 = param_2 + 1;
            *pcVar3 = cVar1;
            pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
    }
    in_ECX[2] = 0;
    if (param_3 != nullptr) {
        pcVar3 = param_3;
        do {
            cVar1 = *pcVar3;
            pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
        pcVar3 = reinterpret_cast<char *>(thunk_FUN_00533c78(reinterpret_cast<uint32_t>(pcVar3 + (1 - reinterpret_cast<int>(param_3 + 1))))));
        in_ECX[2] = reinterpret_cast<uint32_t>(pcVar3);
        do {
            cVar1 = *param_3;
            param_3 = param_3 + 1;
            *pcVar3 = cVar1;
            pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
    }
    return;
}

// 0x571850 — observed shape
void FUN_00571850(void *self)
{
    uint32_t *puVar1;
    uint32_t in_ECX = reinterpret_cast<uint32_t>(self);
    uint32_t uVar2;

    uVar2 = 0;
    if (*reinterpret_cast<int *>(in_ECX + 0x1c) != 0) {
        do {
            puVar1 = *reinterpret_cast<uint32_t **>(*reinterpret_cast<int *>(in_ECX + 0x14) + uVar2 * 4);
            if (puVar1 != nullptr) {
                operator_delete__(reinterpret_cast<void *>(*puVar1));
                operator_delete__(reinterpret_cast<void *>(puVar1[1]));
                operator_delete(puVar1);
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < *reinterpret_cast<uint32_t *>(in_ECX + 0x1c));
    }
    operator_delete__(*reinterpret_cast<void **>(in_ECX + 0x28));
    *reinterpret_cast<uint32_t *>(in_ECX + 0x10) = PTR_FUN_006c3ee4;
    operator_delete__(*reinterpret_cast<void **>(in_ECX + 0x14));
    return;
}

// 0x5718b0 — observed shape
uint32_t FUN_005718b0(int param_1, uint32_t param_2, uint32_t param_3)
{
    int *piVar1;
    int iVar2;
    char cVar3;
    int iVar4;

    cVar3 = FUN_005bd960(param_1, &param_1);
    if ((cVar3 == '\0') || (param_1 == 0)) {
        return 2;
    }
    cVar3 = FUN_005bd960(static_cast<int>(param_2), &param_1);
    iVar2 = param_1;
    if ((cVar3 == '\0') || (param_1 == 0)) {
        return 3;
    }
    piVar1 = reinterpret_cast<int *>(param_1 + 0x28);
    iVar4 = *reinterpret_cast<int *>(param_1 + 0x2c);
    if (*reinterpret_cast<int *>(param_1 + 0x30) == iVar4) {
        if (iVar4 == 0) {
            iVar4 = 1;
        }
        else {
            iVar4 = iVar4 * 2;
        }
        FUN_0055f300(iVar4);
    }
    *reinterpret_cast<uint32_t *>(*piVar1 + *reinterpret_cast<int *>(iVar2 + 0x30) * 4) = param_3;
    piVar1 = reinterpret_cast<int *>(iVar2 + 0x30);
    *piVar1 = *piVar1 + 1;
    return 0;
}

// 0x571940 — observed shape
uint32_t FUN_00571940(void *param_1, uint32_t param_2)
{
    void *pvVar1;
    void *pvVar2;
    char cVar3;
    int iVar4;
    uint32_t uVar5;

    iVar4 = reinterpret_cast<int>(thunk_FUN_00533c78(0x20));
    pvVar1 = param_1;
    if (iVar4 == 0) {
        uVar5 = 0;
    }
    else {
        uVar5 = FUN_00571590(reinterpret_cast<uint32_t>(param_1), reinterpret_cast<char *>(param_2), reinterpret_cast<void *>(iVar4));
    }
    cVar3 = FUN_005bd960(reinterpret_cast<int>(pvVar1), reinterpret_cast<int *>(&param_1));
    pvVar2 = param_1;
    if ((cVar3 != '\0') && (param_1 != nullptr)) {
        operator_delete__(*reinterpret_cast<void **>(reinterpret_cast<int>(param_1) + 4));
        operator_delete__(*reinterpret_cast<void **>(reinterpret_cast<int>(pvVar2) + 0x14));
        operator_delete__(*reinterpret_cast<void **>(reinterpret_cast<int>(pvVar2) + 8));
        operator_delete(pvVar2);
    }
    FUN_00545310(pvVar1, uVar5);
    return 0;
}
