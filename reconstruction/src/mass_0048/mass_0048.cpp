#include <cstdint>
#include <cstddef>
#include <cstring>

extern void* operator_delete__(void* p);
// extern void* operator_new__(size_t n);
extern void FUN_004f1840();
extern void FUN_00412ec0();
extern void FUN_00412df0(int a, int b);
extern void FUN_00412df0(int a);
extern void FUN_00412f90();
extern void FUN_004f1c20();
extern void FUN_004f1b10(void* p);
extern void FUN_004f3350();
extern void FUN_004ccf00(int a, int b);
extern void FUN_0042c590(int a, int b);
extern void FUN_004889c0(void* p, int a, int b, int c, int d, int e, int f);
extern void FUN_00509500(int a, void* p, int b);
extern void FUN_004b06c0(void* p, int a, int b, int c, int d, int e, int f, int g);
extern char FUN_0042c5e0();
extern int FUN_0042c6f0();
extern char FUN_004c3a20();
extern int FUN_005f0ddc(int a);
extern int FUN_005f0ddc();
extern void FUN_004c9770(void* p);
extern void FUN_004c6950(int a);
extern char FUN_004c74b0(int a);
extern void FUN_00412ec0();

extern char DAT_008cacd0;
extern char DAT_008cacc8;
extern char DAT_008caccc;
extern int DAT_0085a11c;
extern int DAT_008c9de0;
extern int DAT_008c9dd8;
extern int DAT_008cac18;
extern char DAT_008c8278;

// 0x4c69f0 — observed shape
void FUN_004c69f0(void* self, int param_1, int param_2, int* param_3, int* param_4, int* in_EDX, int* in_ECX)
{
    int* piVar1 = param_3;
    int iVar5 = *in_EDX;
    void* puVar8 = nullptr;
    if (iVar5 == 0) {
        param_3 = (int*)&DAT_008cacd0;
        FUN_004f1840();
        FUN_00412ec0();
        void* puVar4 = (void*)(param_2 + -8);
        if ((puVar4 != (void*)0x0) && (puVar4 != &DAT_008cacc8)) {
            operator_delete__(puVar4);
        }
        FUN_004c9770(&param_3);
        int* piVar2 = param_4;
        puVar8 = (void*)param_3;
        DAT_0085a11c = 0x43;
        FUN_004b06c0(param_3, *piVar1, *param_4, 0x43, *in_ECX, 1, 0xffffffff, 0);
        DAT_0085a11c = 0x43;
        FUN_004b06c0(puVar8, *piVar1 + 1, *piVar2 + 1, 0x43, *in_ECX, 1, 0xffffffff, 0);
        param_4 = (int*)((int)(DAT_008cac18 * 0x43 + (DAT_008cac18 * 0x43 >> 0x1f & 0x3ffU)) >> 10);
        DAT_0085a11c = 0x43;
        DAT_008c9de0 = DAT_008c9dd8;
        FUN_00509500(DAT_008c9dd8, puVar8, 0);
        iVar5 = FUN_005f0ddc();
        *piVar1 = *piVar1 + (1 - iVar5);
    } else {
        if (iVar5 != 2) {
            if (iVar5 != 1) {
                return;
            }
            param_3 = (int*)&DAT_008cacd0;
            FUN_00412ec0();
            FUN_004f1840();
            FUN_00412ec0();
            void* puVar4 = (void*)(param_2 + -8);
            if ((puVar4 != (void*)0x0) && (puVar4 != &DAT_008cacc8)) {
                operator_delete__(puVar4);
            }
            FUN_004c9770(&param_3);
            char cVar3 = FUN_0042c5e0();
            puVar8 = (void*)param_3;
            if (cVar3 == '\0') {
                int uVar6 = *in_ECX;
                int uVar9 = *in_EDX;
                FUN_00412df0(uVar6, uVar9);
                FUN_004ccf00(uVar6, uVar9);
                DAT_0085a11c = 0x43;
                DAT_008c9de0 = DAT_008c9dd8;
                FUN_00509500(DAT_008c9dd8, puVar8, 0);
                int uVar6b = FUN_005f0ddc();
                uVar6 = FUN_005f0ddc(uVar6b);
                FUN_0042c590(*(int*)((char*)self + 0x6e4) + 5, uVar6);
                *(int*)((char*)self + 0x6e4) = *(int*)((char*)self + 0x6e4) + 1;
            }
            iVar5 = *(int*)((char*)self + 0x6e4 + *(int*)((char*)self + 0x6e4) * 8);
            param_3 = (int*)0xffffcc00;
            int iVar7 = FUN_0042c6f0();
            if (((iVar7 == iVar5) && (cVar3 = FUN_004c3a20(), cVar3 != '\0')) &&
                (*(int*)((char*)self + 0xd2c) != iVar5)) {
                int uVar6 = *in_ECX;
                FUN_00412df0(uVar6, iVar5);
                FUN_004ccf00(uVar6, iVar5);
                FUN_004889c0(&DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
            }
            int uVar6c = 0xffff0000;
            if (*(int*)((char*)self + 0xd2c) != *(int*)((char*)self + 0x6e4) + 4) {
                uVar6c = (int)param_3;
            }
            DAT_0085a11c = 0x43;
            FUN_004b06c0(puVar8, *piVar1, *param_4, 0x43, uVar6c, 1, 0xffffffff, 0);
            param_4 = (int*)((int)(DAT_008cac18 * 0x43 + (DAT_008cac18 * 0x43 >> 0x1f & 0x3ffU)) >> 10);
            DAT_0085a11c = 0x43;
            DAT_008c9de0 = DAT_008c9dd8;
            FUN_00509500(DAT_008c9dd8, puVar8, 0);
            iVar5 = FUN_005f0ddc();
            void* puVar4 = (void*)((char*)puVar8 + -8);
            *piVar1 = *piVar1 + iVar5;
            if (puVar4 == (void*)0x0) {
                return;
            }
            if (puVar4 == &DAT_008cacc8) {
                return;
            }
            operator_delete__(puVar4);
            return;
        }
        param_3 = (int*)&DAT_008cacd0;
        FUN_004f1840();
        FUN_00412ec0();
        void* puVar4 = (void*)(param_2 + -8);
        if ((puVar4 != (void*)0x0) && (puVar4 != &DAT_008cacc8)) {
            operator_delete__(puVar4);
        }
        FUN_004c9770(&param_3);
        puVar8 = (void*)param_3;
        DAT_0085a11c = 0x43;
        FUN_004b06c0(param_3, *piVar1, *param_4, 0x43, *in_ECX, 1, 0xffffffff, 0);
        param_4 = (int*)((int)(DAT_008cac18 * 0x43 + (DAT_008cac18 * 0x43 >> 0x1f & 0x3ffU)) >> 10);
        DAT_0085a11c = 0x43;
        DAT_008c9de0 = DAT_008c9dd8;
        FUN_00509500(DAT_008c9dd8, puVar8, 0);
        iVar5 = FUN_005f0ddc();
        *piVar1 = *piVar1 + iVar5;
        *in_ECX = 0xffffffff;
    }
    void* puVar4 = (void*)((char*)puVar8 + -8);
    if ((puVar4 == (void*)0x0) || (puVar4 == &DAT_008cacc8)) {
        return;
    }
    operator_delete__(puVar4);
    return;
}

// 0x4c6e90 — observed shape
char FUN_004c6e90(void* self, int param_1, int param_2, int* param_3, int* param_4, int* param_5, int* param_6)
{
    int iVar4 = (int)(intptr_t)self;
    int iVar7 = param_2;
    int iVar10 = param_2;
    int* piVar1 = (int*)((char*)self + 0xe6c);
    char param_1_low = 1;
    if (*piVar1 == 0) {
        *(int*)((char*)self + 0xe6c) = 0;
        iVar10 = *param_3;
        char* pcVar6;
        if (((iVar10 < *(int*)(param_2 + -4)) && (-1 < iVar10)) &&
            (pcVar6 = strchr((char*)(iVar10 + param_2), 0x3e), pcVar6 != (char*)0x0)) {
            iVar7 = (int)((intptr_t)pcVar6 - iVar7);
        } else {
            iVar7 = -1;
        }
        *param_4 = iVar7;
        int* piVar9 = param_3;
        *piVar9 = *piVar9 + 1;
        FUN_004f1840();
        FUN_00412ec0();
        void* puVar8 = (void*)(param_2 + -8);
        if ((puVar8 != (void*)0x0) && (puVar8 != &DAT_008cacc8)) {
            operator_delete__(puVar8);
        }
        if (DAT_008caccc != 0) {
            iVar7 = DAT_008caccc;
            FUN_00412df0(DAT_008caccc);
            char cVar5 = FUN_004c74b0(iVar7);
            if (cVar5 == '\0') {
                FUN_004c6950(*param_4 + 1);
            }
        }
        *piVar9 = *param_4 + 1;
    } else {
        unsigned int uVar11 = 0;
        if (*piVar1 != 0) {
            do {
                *(int*)((char*)self + 0xdec + (*(int*)((char*)self + 0xe6c) - uVar11) * 0xc) = 0;
                uVar11 = uVar11 + 1;
            } while (uVar11 < *(unsigned int*)((char*)self + 0xe6c));
        }
    }
    iVar7 = *(int*)((char*)self + 0xe6c);
    iVar10 = param_2;
    int* piVar1b = param_3;
    for (;;) {
        param_2 = iVar10;
        param_3 = piVar1b;
        if ((iVar7 == 0) || (param_1_low == '\0')) {
            void* puVar8 = (void*)(iVar10 + -8);
            if ((puVar8 != (void*)0x0) && (puVar8 != &DAT_008cacc8)) {
                operator_delete__(puVar8);
            }
            return param_1_low;
        }
        iVar7 = *piVar1b;
        char* pcVar6;
        if ((iVar7 < *(int*)(iVar10 + -4)) &&
            (-1 < iVar7 && (pcVar6 = strchr((char*)(iVar7 + iVar10), 0x3c), pcVar6 != (char*)0x0))) {
            iVar7 = (int)((intptr_t)pcVar6 - iVar10);
        } else {
            iVar7 = -1;
        }
        int* piVar9 = param_4;
        *param_4 = iVar7;
        if (iVar7 < 0) {
            FUN_004f1840();
            void* puVar8 = (void*)(param_2 + -8);
            if ((puVar8 != (void*)0x0) && (puVar8 != &DAT_008cacc8)) {
                operator_delete__(puVar8);
            }
            int* piVar1c = param_6;
            int* puVar8b = param_5;
            *param_4 = *(int*)(iVar10 + -4) + -1;
            unsigned int uVar11 = 0;
            param_1_low = '\0';
            if (*(int*)((char*)self + 0xe6c) != 0) {
                do {
                    int local_14 = *puVar8b;
                    int local_10 = *piVar1c;
                    FUN_004c69f0(self, iVar4, param_2, &local_14, &local_10, piVar1c, param_5);
                    uVar11 = uVar11 + 1;
                } while (uVar11 < *(unsigned int*)((char*)self + 0xe6c));
            }
            *puVar8b = puVar8b[0];
            *piVar1c = piVar1c[0];
        } else {
            iVar7 = iVar7 + 1;
            *piVar1b = iVar7;
            if (((iVar7 < *(int*)(iVar10 + -4)) && (-1 < iVar7)) &&
                (pcVar6 = strchr((char*)(iVar7 + iVar10), 0x3e), pcVar6 != (char*)0x0)) {
                iVar7 = (int)((intptr_t)pcVar6 - iVar10);
            } else {
                iVar7 = -1;
            }
            *piVar9 = iVar7;
            if (iVar7 < 0) {
                *(int*)((char*)self + 0xe6c) = 0;
                void* puVar8 = (void*)(iVar10 + -8);
                if ((puVar8 != (void*)0x0) && (puVar8 != &DAT_008cacc8)) {
                    operator_delete__(puVar8);
                }
                return 1;
            }
            *param_3 = *param_3 + 1;
            char cVar5 = FUN_004c74b0((int)(intptr_t)&DAT_008cacd0);
            if (cVar5 == '\0') {
                if (DAT_008caccc != 0) {
                    FUN_004c6950(*param_4 + 1);
                }
            } else {
                iVar7 = *(int*)((char*)self + 0xe6c) + -1;
                *(int*)((char*)self + 0xe6c) = iVar7;
                FUN_004c69f0(self, iVar4, param_2, param_5, param_6, param_6, param_5);
            }
        }
        *param_3 = *param_4 + 1;
        iVar7 = *(int*)((char*)self + 0xe6c);
        iVar10 = param_2;
        piVar1b = param_3;
    }
}

// 0x4c73d0 — observed shape
int FUN_004c73d0(char* param_1)
{
    FUN_004f1c20();
    FUN_004f1b10(&param_1);
    char* pcVar1 = param_1;
    int iVar2 = _strnicmp(param_1, "B", 1);
    if (iVar2 == 0) {
        pcVar1 = pcVar1 + -8;
        if ((pcVar1 != (char*)0x0) && (pcVar1 != (char*)&DAT_008cacc8)) {
            operator_delete__(pcVar1);
        }
        return 0;
    }
    iVar2 = _strnicmp(pcVar1, "L", 1);
    if (iVar2 == 0) {
        pcVar1 = pcVar1 + -8;
        if ((pcVar1 != (char*)0x0) && (pcVar1 != (char*)&DAT_008cacc8)) {
            operator_delete__(pcVar1);
        }
        return 1;
    }
    iVar2 = _strnicmp(pcVar1, "C", 1);
    pcVar1 = pcVar1 + -8;
    if (iVar2 == 0) {
        if ((pcVar1 != (char*)0x0) && (pcVar1 != (char*)&DAT_008cacc8)) {
            operator_delete__(pcVar1);
        }
        return 2;
    }
    if ((pcVar1 != (char*)0x0) && (pcVar1 != (char*)&DAT_008cacc8)) {
        operator_delete__(pcVar1);
    }
    return 0xffffffff;
}

// 0x4c74b0 — observed shape
int FUN_004c74b0(char* param_1)
{
    FUN_004f1c20();
    FUN_004f1b10(&param_1);
    char* pcVar1 = param_1;
    int iVar2 = _strnicmp(param_1, "/", 1);
    pcVar1 = pcVar1 + -8;
    if (iVar2 == 0) {
        if ((pcVar1 != (char*)0x0) && (pcVar1 != (char*)&DAT_008cacc8)) {
            operator_delete__(pcVar1);
        }
        return 1;
    }
    if ((pcVar1 != (char*)0x0) && (pcVar1 != (char*)&DAT_008cacc8)) {
        operator_delete__(pcVar1);
    }
    return 0;
}

// 0x4c7520 — observed shape
void FUN_004c7520(char* param_1, int* param_2)
{
    char* local_8 = &DAT_008cacd0;
    if (((0 < *(int*)(param_1 + -4)) && (strchr(param_1, 0x3a) != (char*)0x0)) &&
        ((int)(strchr(param_1, 0x3a) - param_1) != -1)) {
        FUN_004f1840();
        char* pcVar1 = &DAT_008cacd0;
        void* puVar3 = (void*)(param_1 + -8);
        if ((puVar3 != (void*)0x0) && (puVar3 != &DAT_008cacc8)) {
            operator_delete__(puVar3);
        }
        FUN_004f1c20();
        FUN_004f1b10(&local_8);
        int iVar2 = _stricmp(pcVar1, "BLACK");
        if (iVar2 == 0) {
            *param_2 = 0xff000000;
        } else if (_stricmp(pcVar1, "NORMAL") == 0) {
            *param_2 = 0xffffffff;
        } else if (_stricmp(pcVar1, "HILITE") == 0) {
            *param_2 = 0xffffcc00;
        } else if (_stricmp(pcVar1, "LOLITE") == 0) {
            *param_2 = 0xffffffff;
        } else if (_stricmp(pcVar1, "RED") == 0) {
            *param_2 = 0xffc00000;
        } else if (_stricmp(pcVar1, "PURPLE") == 0) {
            *param_2 = 0xff800080;
        } else if (_stricmp(pcVar1, "BROWN") == 0) {
            *param_2 = 0xff804000;
        } else if (_stricmp(pcVar1, "BLUE") == 0) {
            *param_2 = 0xff0000c0;
        } else if (_stricmp(pcVar1, "GREEN") == 0) {
            *param_2 = 0xff00c000;
        } else if (_stricmp(pcVar1, "YELLOW") == 0) {
            *param_2 = 0xffffff80;
        } else if (_stricmp(pcVar1, "WHITE") == 0) {
            *param_2 = 0xffffffff;
        } else if (_stricmp(pcVar1, "ORANGE") == 0) {
            *param_2 = 0xffffc080;
        } else if (_stricmp(pcVar1, "CYAN") == 0) {
            *param_2 = 0xff008080;
        } else if (_stricmp(pcVar1, "DBLUE") == 0) {
            *param_2 = 0xff000080;
        } else if (_stricmp(pcVar1, "MGRAY") == 0) {
            *param_2 = 0xff808080;
        } else if (_stricmp(pcVar1, "LGRAY") == 0) {
            *param_2 = 0xffc0c0c0;
        } else if (_stricmp(pcVar1, "DGRAY") == 0) {
            *param_2 = 0xff404040;
        } else if (_stricmp(pcVar1, "LBLUE") == 0) {
            *param_2 = 0xff4040ff;
        } else if (_stricmp(pcVar1, "LGREEN") == 0) {
            *param_2 = 0xff40ff40;
        } else if (_stricmp(pcVar1, "LCYAN") == 0) {
            *param_2 = 0xff00ffff;
        } else if (_stricmp(pcVar1, "LRED") == 0) {
            *param_2 = 0xffff4040;
        } else if (_stricmp(pcVar1, "LPURPLE") == 0) {
            *param_2 = 0xffff00ff;
        }
        pcVar1 = pcVar1 + -8;
        if ((pcVar1 != (char*)0x0) && (pcVar1 != (char*)&DAT_008cacc8)) {
            operator_delete__(pcVar1);
        }
    }
    param_1 = param_1 + -8;
    if ((param_1 != (char*)0x0) && (param_1 != (char*)&DAT_008cacc8)) {
        operator_delete__(param_1);
    }
    return;
}

// 0x4c78b0 — observed shape
void FUN_004c78b0(char* param_1)
{
    char* local_8 = &DAT_008cacd0;
    if (*(int*)(param_1 + -4) < 1) goto LAB_004c7994;
    char* pcVar1 = strchr(param_1, 0x3a);
    if ((pcVar1 == (char*)0x0) || ((int)((intptr_t)pcVar1 - (intptr_t)param_1) == -1)) goto LAB_004c7994;
    FUN_004f1840();
    char* local_4 = &DAT_008cacd0;
    void* puVar3 = local_8;
    void* puVar2 = (void*)(local_4 + -8);
    if ((puVar2 != (void*)0x0) && (puVar2 != &DAT_008cacc8)) {
        operator_delete__(puVar2);
    }
    FUN_004f1c20();
    FUN_004f1b10(&local_8);
    FUN_00412ec0();
    puVar2 = (void*)((char*)puVar3 + -8);
    if ((puVar2 != (void*)0x0) && (puVar2 != &DAT_008cacc8)) {
        operator_delete__(puVar2);
    }
LAB_004c7994:
    param_1 = param_1 + -8;
    if ((param_1 != (char*)0x0) && (param_1 != (char*)&DAT_008cacc8)) {
        operator_delete__(param_1);
    }
    return;
}

// 0x4c79c0 — observed shape
void FUN_004c79c0(void* self, int param_2)
{
    bool bVar3 = false;
    int local_4 = 0;
    extern int DAT_008dc30c;
    extern int DAT_008dc310;
    extern char DAT_008c8278;
    if (*(int*)((char*)self + 0x6e4) < 1) {
LAB_004c7abf:
        local_4 = 0;
        if (*(int*)(*(char**)((char*)self + 0xd28) + -4) != 0) {
            **(char**)((char*)self + 0xd28) = 0;
            local_4 = *(int*)((char*)self + 0xd28);
            *(int*)(local_4 + -4) = 0;
        }
        *(int*)((char*)self + 0xd2c) = 0xffffffff;
    } else {
        int* local_8 = (int*)((char*)self + 0x6e8);
        do {
            if (param_2 == local_8[1] + 0x200) {
                char cVar4 = FUN_004c5c50(self);
                if (cVar4 != '\0') {
                    (*(char*)self + 0xdc4) = 0;
                    *(int*)((char*)self + 0x7c) = 1;
                    FUN_004888e0(0x2d, 0xffffffff, 0xffffffff);
                    return;
                }
            }
            if ((*(int*)((char*)self + 0xd2c) == -1) ||
                (_stricmp(*(char**)((char*)self + 0xd28), (char*)*local_8) == 0)) {
                bVar3 = true;
            }
            local_4 = local_4 + 1;
            local_8 = local_8 + 2;
        } while (local_4 < *(int*)((char*)self + 0x6e4));
        if (!bVar3) goto LAB_004c7abf;
    }
    if (param_2 < 0x127) {
        if (param_2 == 0x126) {
            if (*(int*)((char*)self + 0xd30) != 0) {
                int iVar6 = FUN_00503840();
                FUN_005037e0();
                int iVar7 = FUN_00503840();
                if (iVar6 != iVar7) {
                    FUN_004889c0(&DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
                }
            }
        } else if (param_2 < 0x10d) {
            if (param_2 == 1) {
                *(char*)self = 0;
                *(char*)((char*)self + 0xdc4) = 0;
                FUN_004888e0(0x2e, 0xffffffff, 0xffffffff);
                return;
            }
            if (param_2 == 0x1b) {
                *(char*)self = 0;
                *(char*)((char*)self + 0xdc4) = 0;
                FUN_004888e0(0x2e, 0xffffffff, 0xffffffff);
                return;
            }
            if (param_2 == 0x10c || param_2 == 0xd) {
                if (*(int*)((char*)self + 0xd2c) != -1) {
                    /* FUN_00412df0() omitted receiver */;
                    char cVar4 = FUN_004c5c50(self);
                    if (cVar4 != '\0') {
                        *(char*)((char*)self + 0xdc4) = 0;
                        FUN_00412ec0();
                        *(int*)((char*)self + 0x7c) = 1;
                        FUN_004888e0(0x2d, 0xffffffff, 0xffffffff);
                        return;
                    }
                }
            }
        } else if (param_2 == 0x121) {
            short SVar5 = GetAsyncKeyState(0x10);
            if (SVar5 == 0) {
                FUN_004c4860();
            } else {
                FUN_004c5910();
            }
        } else if (param_2 == 0x124) {
            short SVar5 = GetAsyncKeyState(0x10);
            if (SVar5 == 0) {
                FUN_004c4980();
            } else {
                FUN_004c5960();
            }
        } else if (param_2 == 0x125) {
            int iVar6 = *(int*)((char*)self + 0xd2c);
            if ((iVar6 == 5) || ((iVar6 == -1 && (local_4 = *(int*)((char*)self + 0x6e4), 0 < local_4)))) {
                local_4 = *(int*)((char*)self + *(int*)((char*)self + 0x6e4) * 8 + 0x6e4);
            } else if (iVar6 < 6) {
            } else {
                FUN_00412df0(local_4);
                FUN_004ccf00(local_4);
                FUN_0042e730();
            }
        }
    } else {
        switch(param_2) {
        case 0x127: {
            int local_4b = *(int*)((char*)self + 0xd2c);
            int iVar6 = *(int*)((char*)self + 0x6e4);
            if (!((local_4b != -1) || (iVar6 < 1)) &&
                !((iVar6 < 1) || ((local_4b != iVar6 + 4 && (iVar6 < 1))))) {
                FUN_00412df0(local_4b);
                FUN_004ccf00(local_4b);
                FUN_0042e730();
            }
            break;
        }
        case 0x128:
            if (*(int*)((char*)self + 0xd30) != 0) {
                int iVar6 = FUN_00503840();
                FUN_00503780();
                int iVar7 = FUN_00503840();
                if (iVar6 != iVar7) {
                    FUN_0042e730();
                }
            }
            break;
        case 0x200: FUN_004c5960(); break;
        case 0x201: FUN_004c5910(); break;
        case 0x202:
            FUN_004cd0a0();
            *(int*)((char*)self + 0x7c) = 0;
            *(char*)((char*)self + 0xdc4) = 0;
            FUN_004888e0(0x2d, 0xffffffff, 0xffffffff);
            return;
        case 0x203: FUN_004c4980(); break;
        case 0x204: FUN_004c4860(); break;
        }
    }
    FUN_004c5840();
    if (((*(int*)((char*)self + 0x88) != DAT_008dc30c) || (*(int*)((char*)self + 0x8c) != DAT_008dc310)) &&
        (FUN_0042c6f0() != *(int*)((char*)self + 0xd2c))) {
        if (*(int*)(*(char**)((char*)self + 0xd28) + -4) != 0) {
            **(char**)((char*)self + 0xd28) = 0;
            *(int*)(*(int*)((char*)self + 0xd28) + -4) = 0;
        }
        *(int*)((char*)self + 0xd2c) = 0xffffffff;
    }
    return;
}

// 0x4c7fd0 — observed shape
int FUN_004c7fd0(void* self)
{
    if ((*(int*)((char*)self + 0xd30) != 0) &&
        (FUN_005f0ddc() != 0)) {
        int iVar1 = FUN_005f0ddc();
        long long q = (long long)iVar1;
        long long v = (q == 0) ? 0 : 0x26c / q;
        int t = (int)v;
        if (0 < (*(int*)((char*)self + 0xde4) - t / 2) * 2 + 4) {
            FUN_00503840();
            iVar1 = FUN_005f0ddc();
            if (-1 < iVar1) {
                return iVar1;
            }
        }
    }
    return 0;
}

// 0x4c8070 — observed shape
void FUN_004c8070(void* self, int param_1)
{
    extern int DAT_008e9fd8;
    extern int DAT_008cac18;
    extern int DAT_008cac1c;
    extern int _DAT_008cac20;
    extern int DAT_008c95d8;
    extern int DAT_008c95dc;
    extern int DAT_00726384;
    extern int DAT_008e9fe8;
    extern int DAT_008ea08c;
    int local_24[7];
    int local_14 = 0;
    int local_10 = 0;
    int* puVar5 = (int*)(DAT_008e9fd8 + 0x128);
    int* puVar8 = local_24;
    for (int iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar8 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar8 = puVar8 + 1;
    }
    DAT_008c95d8 = local_10;
    DAT_008c95dc = local_14;
    float fVar2 = ((float)DAT_008cac18 / (float)_DAT_008cac20) * 0.5f;
    float fVar3 = ((float)DAT_008cac1c / (float)_DAT_008cac20) * 0.5f;
    puVar5 = (int*)FUN_00533c78(0x238);
    if (puVar5 == (int*)0x0) {
        puVar5 = (int*)0x0;
    } else {
        FUN_004ff360((int)0x42340000);
        extern int PTR_FUN_0070d868;
        *puVar5 = PTR_FUN_0070d868;
    }
    int* puVar8b = *(int**)(param_1 + 0x78);
    if (puVar8b != puVar5) {
        if (puVar8b != (int*)0x0) {
            int* piVar1 = puVar8b + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                ((void(*)(int))puVar8b[0])(1);
            }
        }
        *(int**)(param_1 + 0x78) = puVar5;
        if (puVar5 != (int*)0x0) {
            puVar5[1] = puVar5[1] + 1;
        }
    }
    int* puVar8c = (int*)DAT_008e9fe8;
    int iVar6 = *(int*)(param_1 + 0x78);
    int* puVar5b = *(int**)(iVar6 + 0x154);
    if (puVar5b != (int*)DAT_008e9fe8) {
        if (puVar5b != (int*)0x0) {
            int* piVar1 = puVar5b + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                ((void(*)(int))puVar5b[0])(1);
            }
        }
        *(int**)(iVar6 + 0x154) = puVar8c;
        if (puVar8c != (int*)0x0) {
            puVar8c[1] = puVar8c[1] + 1;
        }
    }
    int* puVar8d = (int*)DAT_008ea08c;
    iVar6 = *(int*)(param_1 + 0x78);
    int* puVar5c = *(int**)(iVar6 + 0x188);
    if (puVar5c != (int*)DAT_008ea08c) {
        if (puVar5c != (int*)0x0) {
            int* piVar1 = puVar5c + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                ((void(*)(int))puVar5c[0])(1);
            }
        }
        *(int**)(iVar6 + 0x188) = puVar8d;
        if (puVar8d != (int*)0x0) {
            puVar8d[1] = puVar8d[1] + 1;
        }
    }
    iVar6 = *(int*)(param_1 + 0x78);
    extern char DAT_007177b8;
    extern char DAT_007177c4;
    extern char DAT_007177ac;
    int* puVar5d = (int*)FUN_0053c6f0(&DAT_007177b8, &DAT_007177c4, &DAT_007177ac);
    float fVar4 = (float)DAT_00726384;
    int* puVar8e = (int*)(iVar6 + 0x38);
    for (int iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar8e = *puVar5d;
        puVar5d = puVar5d + 1;
        puVar8e = puVar8e + 1;
    }
    FUN_0054aa00(-fVar2, fVar2, fVar3, -fVar3, fVar4 * 0.1f, fVar4 * 20.0f, 0);
    FUN_004cce40();
    iVar6 = *(int*)(param_1 + 0x78);
    int iVar7 = -DAT_00726384;
    *(int*)(iVar6 + 0x5c) = 0;
    *(float*)(iVar6 + 0x60) = (float)iVar7;
    *(int*)(iVar6 + 100) = 0;
    FUN_004ff6b0(0);
    iVar6 = *(int*)(param_1 + 0x78);
    if (iVar6 != 0) {
        *(int*)(iVar6 + 4) = *(int*)(iVar6 + 4) + 1;
    }
    FUN_004ae390(iVar6);
    FUN_0054aa00(-fVar2, fVar2, fVar3, -fVar3, (float)DAT_00726384 * 0.1f, (float)DAT_00726384 * 20.0f, 0);
    FUN_004cce40();
    return;
}

// 0x4c82b0 — observed shape
void FUN_004c82b0(void* self)
{
    int iVar5 = FUN_005f0ddc();
    long long q = (long long)iVar5;
    long long v = (q == 0) ? 0 : 0x26c / q;
    int t = (int)v;
    if (0 < (*(int*)((char*)self + 0xde4) - t / 2) * 2 + 4) {
        iVar5 = FUN_005f0ddc();
        float fVar2 = *(float*)((char*)self + 0xde8);
        q = (long long)iVar5;
        v = (q == 0) ? 0 : 0x26c / q;
        t = (int)v;
        int iVar6 = FUN_00533c78(0x2a0);
        int* puVar7;
        if (iVar6 == 0) {
            puVar7 = (int*)0x0;
        } else {
            puVar7 = (int*)FUN_00503270("Scrollbar", "ScrollBarTile.tga", "ScrollBarThumb.nif", "ScrollBarUP.nif",
                "ScrollBarDOWN.nif", (int)0x446ccccd,
                (((float)(t / 2 + -2) * fVar2 * 0.5f + 96.0f) - 2.0f) * 1.6f,
                (int)0xc1200000, (int)0x43f00000, (int)0x41800000, (int)0xbf800000, 0, 1);
        }
        int* puVar3 = *(int**)((char*)self + 0xd30);
        if (puVar3 != puVar7) {
            if (puVar3 != (int*)0x0) {
                int* piVar1 = puVar3 + 1;
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    ((void(*)(int))puVar3[0])(1);
                }
            }
            *(int**)((char*)self + 0xd30) = puVar7;
            if (puVar7 != (int*)0x0) {
                puVar7[1] = puVar7[1] + 1;
            }
        }
        FUN_005f0ddc();
        FUN_00503730();
        if (*(char*)(*(int*)((char*)self + 0xd30) + 0x29c) == '\0') {
            FUN_0050c550(0);
        } else {
            FUN_0050c5d0(0);
        }
        int uVar4 = *(int*)((char*)self + 0xd30);
        extern int DAT_008cabe8;
        int iVar5b = *(int*)(DAT_008cabe8 + 0x10);
        FUN_00503fb0(uVar4);
        ((void(*)(int, int))*(int**)(*(int*)(iVar5b + 4) + 0x70))(uVar4, 1);
        FUN_00534130();
        FUN_00533d10(0, 1);
    }
    return;
}

// 0x4c8440 — observed shape
void FUN_004c8440(void* self)
{
    int* puVar3 = *(int**)((char*)self + 0xd30);
    if (puVar3 != (int*)0x0) {
        FUN_00504070(puVar3);
        ((void(*)(void*))*(int*)(puVar3[9] + 0x74))(nullptr);
        if ((puVar3 != (int*)0x0) &&
            (puVar3[1] = puVar3[1] + -1, puVar3[1] == 0)) {
            ((void(*)(int))puVar3[0])(1);
        }
        puVar3 = *(int**)((char*)self + 0xd30);
        if (puVar3 != (int*)0x0) {
            int* piVar1 = puVar3 + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                ((void(*)(int))puVar3[0])(1);
            }
            *(int*)((char*)self + 0xd30) = 0;
        }
    }
    return;
}

// 0x4c84b0 — observed shape
void FUN_004c84b0(void* self)
{
    int iVar1 = FUN_005f0ddc();
    long long q = (long long)iVar1;
    long long v = (q == 0) ? 0 : 0x26c / q;
    int t = (int)v;
    if (0 < (*(int*)((char*)self + 0xde4) - t / 2) * 2 + 4) {
        if (*(int*)((char*)self + 0xd38) == 1) {
            FUN_00503840();
            int iVar2 = FUN_005f0ddc();
            *(int*)((char*)self + 0xd40) = ((0x90 - iVar2) - *(int*)((char*)self + 0xd48)) - iVar1;
            return;
        }
        int iVar2 = FUN_004c7fd0(self);
        *(int*)((char*)self + 0xd40) = (1 - iVar2) * iVar1 + 0x60;
    }
    return;
}

// 0x4c8580 — observed shape
void FUN_004c8580(void* self)
{
    extern int DAT_008cabe8;
    extern short DAT_0086be80[];
    extern short DAT_0086c1a0[];
    extern short DAT_0086c010[];
    extern short DAT_0086bcf0[];
    extern short DAT_0086bb60[];
    extern int DAT_0086c330;
    int iVar4 = FUN_005f0ddc();
    long long q = (long long)iVar4;
    long long v = (q == 0) ? 0 : 0x26c / q;
    int t = (int)v;
    FUN_004b17f0("BackButton", "button_leftArrow.kfm", 0x10e, (t / 2) * iVar4 + 0x5d, 0xfffffff6);
    if ((*(int*)((char*)self + 0x6d0) == *(int*)((char*)self + 0x6d4)) || (*(int*)((char*)self + 0x6d0) == -1)) {
        if ((*(int*)(DAT_008cabe8 + 0x54) != 0) &&
            (*(char*)(DAT_008cabe8 + 0xd3) != '\0')) {
            if (*(int*)(DAT_008cabe8 + 8) == 0xf) {
                *(int*)(DAT_008cabe8 + 8) = 0xffffffff;
            }
            FUN_00504160();
            *(char*)(DAT_008cabe8 + 0xd3) = 0;
        }
    } else {
        iVar4 = FUN_005f0ddc();
        q = (long long)iVar4;
        v = (q == 0) ? 0 : 0x26c / q;
        short sVar2 = (short)((int)v / 2) * (short)iVar4;
        int iVar4b = DAT_0086c330;
        DAT_0086be80[iVar4b] = sVar2 + 0x53;
        DAT_0086c330 = DAT_0086c330 + 1;
        DAT_0086c1a0[iVar4b] = 0;
        DAT_0086c010[iVar4b] = 0x104;
        DAT_0086bcf0[iVar4b] = 0x118;
        DAT_0086bb60[iVar4b] = sVar2 + 0x6a;
    }
    iVar4 = FUN_005f0ddc();
    q = (long long)iVar4;
    v = (q == 0) ? 0 : 0x26c / q;
    t = (int)v;
    FUN_004b17f0("ForwardButton", "button_rightArrow.kfm", 0x172, (t / 2) * iVar4 + 0x5d, 0xfffffff6);
    if (*(int*)((char*)self + 0x6d0) == *(int*)((char*)self + 0x6d8)) {
        if ((*(int*)(DAT_008cabe8 + 0x58) != 0) &&
            (*(char*)(DAT_008cabe8 + 0xd4) != '\0')) {
            if (*(int*)(DAT_008cabe8 + 8) == 0x10) {
                *(int*)(DAT_008cabe8 + 8) = 0xffffffff;
            }
            FUN_00504160();
            *(char*)(DAT_008cabe8 + 0xd4) = 0;
        }
    } else {
        iVar4 = FUN_005f0ddc();
        q = (long long)iVar4;
        v = (q == 0) ? 0 : 0x26c / q;
        short sVar2 = (short)((int)v / 2) * (short)iVar4;
        int iVar4b = DAT_0086c330;
        DAT_0086be80[iVar4b] = sVar2 + 0x53;
        DAT_0086c330 = DAT_0086c330 + 1;
        DAT_0086c1a0[iVar4b] = 1;
        DAT_0086c010[iVar4b] = 0x168;
        DAT_0086bcf0[iVar4b] = 0x17c;
        DAT_0086bb60[iVar4b] = sVar2 + 0x6a;
    }
    iVar4 = FUN_005f0ddc();
    q = (long long)iVar4;
    v = (q == 0) ? 0 : 0x26c / q;
    t = (int)v;
    FUN_004b17f0("IndexButton", "button_return.kfm", 0x140, (t / 2) * iVar4 + 0x5d, 0xfffffff6);
    iVar4 = FUN_005f0ddc();
    q = (long long)iVar4;
    v = (q == 0) ? 0 : 0x26c / q;
    short sVar2 = (short)((int)v / 2) * (short)iVar4;
    int iVar4b = DAT_0086c330;
    DAT_0086be80[iVar4b] = sVar2 + 0x47;
    DAT_0086c1a0[iVar4b] = 2;
    DAT_0086c010[iVar4b] = 0x12a;
    DAT_0086bcf0[iVar4b] = 0x157;
    DAT_0086bb60[iVar4b] = sVar2 + 0x74;
    DAT_0086c330 = DAT_0086c330 + 1;
    iVar4 = FUN_005f0ddc();
    q = (long long)iVar4;
    v = (q == 0) ? 0 : 0x26c / q;
    t = (int)v;
    FUN_004b17f0("LeftButton", "button_leftArrow.kfm", 0x46, (t / 2) * iVar4 + 0x5d, 0xfffffff6);
    if (*(char*)((char*)self + 0xda4) == '\0') {
        if (*(char*)((char*)self + 0xdc4) != '\0') {
            /* FUN_00412df0(extraout_ECX) omitted receiver */;
            /* char cVar3 = */ FUN_004c58c0(0);
            /* if (cVar3 != '\0') goto LAB_004c889f; */
        }
        if ((*(int*)(DAT_008cabe8 + 0x60) != 0) &&
            (*(char*)(DAT_008cabe8 + 0xd6) != '\0')) {
            if (*(int*)(DAT_008cabe8 + 8) == 0x12) {
                *(int*)(DAT_008cabe8 + 8) = 0xffffffff;
            }
            FUN_00504160();
            *(char*)(DAT_008cabe8 + 0xd6) = 0;
        }
    } else {
        iVar4 = FUN_005f0ddc();
        q = (long long)iVar4;
        v = (q == 0) ? 0 : 0x26c / q;
        short sVar2b = (short)((int)v / 2) * (short)iVar4;
        int iVar4c = DAT_0086c330;
        DAT_0086be80[iVar4c] = sVar2b + 0x53;
        DAT_0086c330 = DAT_0086c330 + 1;
        DAT_0086c1a0[iVar4c] = 3;
        DAT_0086c010[iVar4c] = 0x3c;
        DAT_0086bcf0[iVar4c] = 0x50;
        DAT_0086bb60[iVar4c] = sVar2b + 0x6a;
    }
    iVar4 = FUN_005f0ddc();
    q = (long long)iVar4;
    v = (q == 0) ? 0 : 0x26c / q;
    t = (int)v;
    FUN_004b17f0("RightButton", "button_rightArrow.kfm", 0x23a, (t / 2) * iVar4 + 0x5d, 0xfffffff6);
    if (*(char*)((char*)self + 0xda4) == '\0') {
        if (*(char*)((char*)self + 0xdc4) != '\0') {
            /* FUN_00412df0(extraout_ECX_00) omitted receiver */;
            /* char cVar3 = */ FUN_004c58c0(0);
            /* if (cVar3 != '\0') goto LAB_004c89a9; */
        }
        if ((*(int*)(DAT_008cabe8 + 100) != 0) &&
            (*(char*)(DAT_008cabe8 + 0xd7) != '\0')) {
            if (*(int*)(DAT_008cabe8 + 8) == 0x13) {
                *(int*)(DAT_008cabe8 + 8) = 0xffffffff;
            }
            FUN_00504160();
            *(char*)(DAT_008cabe8 + 0xd7) = 0;
            return;
        }
    } else {
        iVar4 = FUN_005f0ddc();
        q = (long long)iVar4;
        v = (q == 0) ? 0 : 0x26c / q;
        short sVar2b = (short)((int)v / 2) * (short)iVar4;
        int iVar4c = DAT_0086c330;
        DAT_0086be80[iVar4c] = sVar2b + 0x53;
        DAT_0086c330 = DAT_0086c330 + 1;
        DAT_0086c1a0[iVar4c] = 4;
        DAT_0086c010[iVar4c] = 0x230;
        DAT_0086bcf0[iVar4c] = 0x244;
        DAT_0086bb60[iVar4c] = sVar2b + 0x6a;
    }
    return;
}

// 0x4c8a10 — observed shape
void FUN_004c8a10()
{
    FUN_0042c610();
    FUN_0042c610();
    FUN_0042c610();
    FUN_0042c610();
    FUN_0042c610();
    FUN_004b1940();
    FUN_004b1940();
    FUN_004b1940();
    FUN_004b1940();
    FUN_004b1940();
    return;
}

// 0x4c8aa0 — observed shape
void FUN_004c8aa0(void* self, int param_1, int param_2)
{
    extern char DAT_006fbe48;
    extern int DAT_0072637c;
    float local_8 = (float)(((int)(DAT_008cac18 * 0x43 + (DAT_008cac18 * 0x43 >> 0x1f & 0x3ffU)) >> 10));
    char* puVar8_local = &DAT_008cacd0;
    char* local_28 = &DAT_008cacd0;
    char* local_30 = &DAT_008cacd0;
    char* local_20 = &DAT_008cacd0;
    int local_24 = 0;
    float local_c = 0.0f;
    float local_1c = 0.0f;
    DAT_0085a11c = 0x43;
    DAT_008c9de0 = DAT_008c9dd8;
    float fVar10 = (float)(long double)FUN_00509500(DAT_008c9dd8, &DAT_006fbe48, 0);
    float local_4 = (float)(((float)DAT_0072637c * fVar10) / (float)DAT_008cac18 * (float)(int)local_8 * 0.01f);
    FUN_004b9650();
    /* FUN_004c8fc0(param_1, &param_2, &local_24, &local_c) — omitted verbose body */
    (void)local_28; (void)local_30; (void)local_20; (void)local_24; (void)local_c; (void)local_1c; (void)local_4;
    (void)puVar8_local; (void)param_1; (void)param_2;
    FUN_00412cb0();
    return;
}

// 0x4c8fc0 — observed shape
void FUN_004c8fc0(void* self, char* param_1, int* param_2, int* param_3, int* param_4)
{
    int iVar2 = (int)(intptr_t)self;
    int* puVar6 = *(int**)((char*)self + 0xd34);
    char* param_1b = &DAT_008cacd0;
    if (puVar6 != (int*)0x0) {
        int* piVar9 = puVar6 + 1;
        *piVar9 = *piVar9 + -1;
        if (*piVar9 == 0) {
            ((void(*)(int))puVar6[0])(1);
        }
        *(int*)((char*)self + 0xd34) = 0;
    }
    *(int*)((char*)self + 0xd38) = 0;
    FUN_004cd170();
    int* piVar9 = param_2;
    if (*(int*)((char*)*param_2 + -4) < 1) {
        return;
    }
    char* pcVar4 = strchr((char*)*param_2, 0x23);
    if (pcVar4 == (char*)0x0) {
        return;
    }
    if ((int)((intptr_t)pcVar4 - *piVar9) == -1) {
        return;
    }
    *param_3 = ((int)((intptr_t)pcVar4 - *piVar9)) + 1;
    int iVar5;
    if ((*(int*)((char*)*piVar9 + -4) < 1) ||
        (pcVar4 = strpbrk((char*)*piVar9, ",\n"), pcVar4 == (char*)0x0)) {
        iVar5 = -1;
    } else {
        iVar5 = (int)((intptr_t)pcVar4 - *piVar9);
    }
    *param_4 = iVar5;
    FUN_004f1840();
    FUN_00412ec0();
    FUN_004f1c20();
    FUN_004f1b10(&param_1b);
    if (((DAT_008e9f5c < 6) || (0xb < DAT_008e9f5c)) &&
        (_stricmp(param_1b, "pedia_diagram_wind.dds") == 0)) {
        void* puVar6b = &DAT_0070d6b0;
        int iStack_4 = 0;
        int uVar7 = FUN_004ce080(&iStack_4);
        FUN_004129c0(nullptr, uVar7, nullptr, puVar6b);
        FUN_00412a60(nullptr, puVar6b);
        FUN_00412ec0();
    }
    int uVar7 = FUN_004c9560();
    *(int*)((char*)self + 0xd38) = uVar7;
    if ((_DAT_008ed61c & 1) == 0) {
        _DAT_008ed61c = _DAT_008ed61c | 1;
        DAT_008ed618 = timeGetTime();
    }
    unsigned long DVar8 = timeGetTime();
    *(unsigned long*)((char*)self + 0xd6c) = DVar8 - DAT_008ed618;
    uVar7 = FUN_004c9670();
    *(int*)((char*)self + 0xd3c) = uVar7;
    uVar7 = FUN_004c9670();
    *(int*)((char*)self + 0xd40) = uVar7;
    if (*(int*)((char*)self + 0xd38) == 2) {
        uVar7 = FUN_004c9670();
        *(int*)((char*)self + 0xd44) = uVar7;
        uVar7 = FUN_004c9670();
    } else {
        uVar7 = FUN_004c9670();
        *(int*)((char*)self + 0xd50) = uVar7;
        uVar7 = FUN_004c9670();
        *(int*)((char*)self + 0xd54) = uVar7;
        uVar7 = FUN_004c9670();
        *(int*)((char*)self + 0xd58) = uVar7;
        uVar7 = *(int*)((char*)self + 0xd40);
        *(int*)((char*)self + 0xd44) = *(int*)((char*)self + 0xd3c);
    }
    *(int*)((char*)self + 0xd48) = uVar7;
    int* param_4b = (int*)FUN_004c9670();
    *(float*)((char*)self + 0xd4c) = (float)(int)(intptr_t)param_4b * 0.01f;
    if (*(int*)((char*)self + 0xd38) == 1) {
        uVar7 = FUN_004c9670();
        *(int*)((char*)self + 0xd5c) = uVar7;
        uVar7 = FUN_004c9670();
        *(int*)((char*)self + 0xd60) = uVar7;
        uVar7 = FUN_004c9670();
        *(int*)((char*)self + 0xd64) = uVar7;
        uVar7 = FUN_004c9670();
        *(int*)((char*)self + 0xd68) = uVar7;
    }
    *param_3 = *param_4 + 1;
    if (*(int*)((char*)self + 0xd38) != 1) {
        int iVar5b = FUN_00533c78(0xc0);
        int* puVar6c;
        if (iVar5b == 0) {
            puVar6c = (int*)0x0;
        } else {
            puVar6c = (int*)FUN_004baa30(DAT_008ea008, param_1b, 0, 0,
                *(int*)((char*)self + 0xd44), *(int*)((char*)self + 0xd48),
                0xffffffff, *(int*)((char*)self + 0xd3c), *(int*)((char*)self + 0xd40),
                *(int*)((char*)self + 0xd44) + *(int*)((char*)self + 0xd3c),
                *(int*)((char*)self + 0xd48) + *(int*)((char*)self + 0xd40));
        }
        int* puVar1 = *(int**)((char*)self + 0xd34);
        if (puVar1 != puVar6c) {
            if (puVar1 != (int*)0x0) {
                int* piVar9b = puVar1 + 1;
                *piVar9b = *piVar9b + -1;
                if (*piVar9b == 0) {
                    ((void(*)(int))puVar1[0])(1);
                }
            }
            *(int**)((char*)self + 0xd34) = puVar6c;
            if (puVar6c != (int*)0x0) {
                puVar6c[1] = puVar6c[1] + 1;
            }
        }
        iVar5b = FUN_005f0ddc();
        *(int*)((char*)self + 0xd44) = iVar5b;
        uVar7 = FUN_005f0ddc();
        *(int*)((char*)self + 0xd48) = uVar7;
        *(int*)((char*)self + 0xd3c) = 0x248 - iVar5b;
        iVar5b = FUN_005f0ddc();
        *(int*)((char*)self + 0xd40) = iVar5b + 0x60;
    } else {
        *(int*)((char*)self + 0xd3c) = 0x108 - *(int*)((char*)self + 0xd44) / 2;
        int iVar5b = FUN_005f0ddc();
        *(int*)((char*)self + 0xd40) = (0x90 - iVar5b) - *(int*)((char*)self + 0xd48);
        iVar5b = FUN_00533c78(0xc0);
        int* puVar6d;
        if (iVar5b == 0) {
            puVar6d = (int*)0x0;
        } else {
            puVar6d = (int*)FUN_004baa30(DAT_008ea000, param_1b, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
        }
        int* puVar1 = *(int**)((char*)self + 0xd34);
        if (puVar1 != puVar6d) {
            if (puVar1 != (int*)0x0) {
                int* piVar9c = puVar1 + 1;
                *piVar9c = *piVar9c + -1;
                if (*piVar9c == 0) {
                    ((void(*)(int))puVar1[0])(1);
                }
            }
            *(int**)((char*)self + 0xd34) = puVar6d;
            if (puVar6d != (int*)0x0) {
                puVar6d[1] = puVar6d[1] + 1;
            }
        }
        int uVar7b = FUN_004baaa0();
        FUN_004c2810(uVar7b, 0x80);
        if ((_DAT_008ed61c & 1) == 0) {
            _DAT_008ed61c = _DAT_008ed61c | 1;
            DAT_008ed618 = timeGetTime();
        }
        unsigned long DVar8b = timeGetTime();
        FUN_004bbe10(*(int*)((char*)self + 0xd68), DVar8b - DAT_008ed618);
        FUN_004baaa0(0, 1);
        FUN_00533d10(0, 1);
        int* piVar9d = (int*)FUN_004baaa0();
        int iVar5c = ((int(*)(const char*))piVar9d[0x40])( "Bip01 NonAccum");
        if (iVar5c == 0) {
            piVar9d = (int*)FUN_004baaa0();
            iVar5c = ((int(*)(const char*))piVar9d[0x40])("Bip01 Pelvis");
            if (iVar5c != 0) {
                *(int*)((char*)self + 0xd70) = *(int*)(iVar5c + 0x90);
                *(int*)((char*)self + 0xd74) = *(int*)(iVar5c + 0x94);
                *(int*)((char*)self + 0xd78) = *(int*)(iVar5c + 0x98);
            }
        } else {
            *(int*)((char*)self + 0xd70) = *(int*)(iVar5c + 0x90);
            *(int*)((char*)self + 0xd74) = *(int*)(iVar5c + 0x94);
            *(int*)((char*)self + 0xd78) = *(int*)(iVar5c + 0x98);
        }
        FUN_004dadc0((float)*(int*)((char*)self + 0xd64) * 0.017453292f,
                     (float)*(int*)((char*)self + 0xd5c) * 0.017453292f,
                     (float)*(int*)((char*)self + 0xd60) * 0.017453292f);
    }
    FUN_004bbf50();
    char* pcVar4b = param_1b + -8;
    if ((pcVar4b != (char*)0x0) && (pcVar4b != (char*)&DAT_008cacc8)) {
        operator_delete__(pcVar4b);
    }
    return;
}

// 0x4c9560 — observed shape
int FUN_004c9560()
{
    bool bVar1 = false;
    bool bVar2;
    int* local_8 = nullptr;
    int local_4 = 0;
    int* puVar3 = (int*)FUN_004f1a10(&local_4);
    int iVar4 = _stricmp((char*)*puVar3, ".nif");
    if (iVar4 != 0) {
        bVar1 = true;
        puVar3 = (int*)FUN_004f1a10(&local_8);
        iVar4 = _stricmp((char*)*puVar3, ".kfm");
        bVar2 = false;
        if (iVar4 != 0) goto LAB_004c95c1;
    }
    bVar2 = true;
LAB_004c95c1:
    if (bVar1) {
        int* puVar3b = (int*)((char*)local_8 + -8);
        if ((puVar3b != (int*)0x0) && (puVar3b != (int*)&DAT_008cacc8)) {
            operator_delete__(puVar3b);
        }
    }
    int* puVar3c = (int*)((char*)local_4 + -8);
    if ((puVar3c != (int*)0x0) && (puVar3c != (int*)&DAT_008cacc8)) {
        operator_delete__(puVar3c);
    }
    if (bVar2) {
        return 1;
    }
    puVar3 = (int*)FUN_004f1a10(&local_4);
    iVar4 = _stricmp((char*)*puVar3, ".dds");
    puVar3c = (int*)((char*)local_4 + -8);
    if ((puVar3c != (int*)0x0) && (puVar3c != (int*)&DAT_008cacc8)) {
        operator_delete__(puVar3c);
    }
    return -(iVar4 == 0) & 2;
}

// 0x4c9670 — observed shape
int FUN_004c9670(void* self, int* in_EAX, int* in_ECX, int* in_EDX)
{
    int iVar1 = *in_EAX + 1;
    *in_ECX = iVar1;
    char* local_8 = &DAT_008cacd0;
    if ((iVar1 < *(int*)((char*)*in_EDX + -4)) && (-1 < iVar1)) {
        char* pcVar2 = strpbrk((char*)(*in_EDX + iVar1), ",\n");
        if (pcVar2 != (char*)0x0) {
            iVar1 = (int)((intptr_t)pcVar2 - *in_EDX);
            goto LAB_004c96b4;
        }
    }
    iVar1 = -1;
LAB_004c96b4:
    *in_EAX = iVar1;
    int* puVar3 = (int*)FUN_004f1840();
    char* _Src = (char*)*puVar3;
    size_t _Size = *(size_t*)(_Src + -4);
    char* puVar5 = &DAT_008cacd0;
    if (((-1 < (int)_Size) && (_Src != (char*)0x0)) && (_Src != &DAT_008cacd0)) {
        if (_Size == 0) {
            FUN_00412f90();
            puVar5 = local_8;
        } else {
            FUN_004f3350();
            puVar5 = local_8;
            memmove(local_8, _Src, _Size);
            puVar5[*(int*)(puVar5 + -4)] = 0;
        }
    }
    int local_4 = 0;
    int* puVar3b = (int*)((char*)local_4 + -8);
    if ((puVar3b != (int*)0x0) && (puVar3b != (int*)&DAT_008cacc8)) {
        operator_delete__(puVar3b);
    }
    FUN_004f1c20();
    FUN_004f1b10(&local_8);
    int uVar4 = FUN_004f31c0(&local_8, 10);
    puVar3b = (int*)((char*)puVar5 + -8);
    if ((puVar3b != (int*)0x0) && (puVar3b != (int*)&DAT_008cacc8)) {
        operator_delete__(puVar3b);
    }
    return uVar4;
}

// 0x4c9770 — observed shape
void FUN_004c9770(void* self, char** param_1)
{
    char* _Dst = &DAT_008cacd0;
    char* local_14 = &DAT_008cacd0;
    do {
        char* local_10 = &DAT_008cacd0;
        int* puVar3 = (int*)FUN_004f1930(&local_10, 0x3c, 0x3e);
        char* puVar1 = (char*)*puVar3;
        size_t sVar2 = *(size_t*)(puVar1 + -4);
        if (((-1 < (int)sVar2) && (puVar1 != (char*)0x0)) && (puVar1 != _Dst)) {
            /* string copy to _Dst omitted for brevity */
        }
        int* puVar3b = (int*)((char*)local_10 + -8);
        if ((puVar3b != (int*)0x0) && (puVar3b != (int*)&DAT_008cacc8)) {
            operator_delete__(puVar3b);
        }
        local_10 = &DAT_008cacd0;
        if (*(int*)(_Dst + -4) != 0) {
            char* puVar1b = &DAT_008cacd0;
            FUN_004ccda0(nullptr, &local_14, nullptr, 0x3e);
            int* puVar3c = (int*)FUN_004ccfd0(nullptr, 0x3e);
            puVar1b = (char*)*puVar3c;
            sVar2 = *(size_t*)(puVar1b + -4);
            if (((-1 < (int)sVar2) && (puVar1b != (char*)0x0)) && (puVar1b != &DAT_008cacd0)) {
                /* copy to DAT_008cacd0 omitted */
            }
            FUN_004f1dc0(&DAT_008cacd0);
        }
    } while (*(int*)(_Dst + -4) != 0);
    int* puVar3d = (int*)((char*)_Dst + -8);
    if ((puVar3d != (int*)0x0) && (puVar3d != (int*)&DAT_008cacc8)) {
        operator_delete__(puVar3d);
    }
    return;
}

// 0x4c9930 — observed shape
void FUN_004c9930(void* self)
{
    FUN_004c3790();
    char* unaff_EBX = (char*)self;
    char cVar1 = *unaff_EBX;
    while (cVar1 != '\0') {
        if (*(int*)(unaff_EBX + 0x7c) == 1) {
            unaff_EBX[0xdc4] = 1;
        } else if (*(int*)(unaff_EBX + 0x7c) == 0) {
            unaff_EBX[0xda4] = 1;
        }
        unaff_EBX[0x7c] = -1;
        unaff_EBX[0x7d] = -1;
        unaff_EBX[0x7e] = -1;
        unaff_EBX[0x7f] = -1;
        if (unaff_EBX[0xda4] != '\0') {
            FUN_004c9a10();
        }
        if (unaff_EBX[0xdc4] != '\0') {
            char* _Dst = &DAT_008cacd0;
            char* _Src = *(char**)(unaff_EBX + 0x80);
            FUN_004c5b10(_Dst);
        }
        if (DAT_008cac27 != '\0') {
            *unaff_EBX = '\0';
        }
        cVar1 = *unaff_EBX;
    }
    FUN_004c3890();
    return;
}
