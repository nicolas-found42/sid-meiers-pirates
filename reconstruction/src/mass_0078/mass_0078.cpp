#include <cstdint>
#include <cstddef>
#include <windows.h>

// Extern globals used by the corpus
extern HANDLE DAT_00726c30;
extern DWORD DAT_00726c28;
extern int DAT_008cad00;
extern unsigned char DAT_008cacd0;
extern unsigned char DAT_008cacc8;

extern void FUN_004fac10(void);
extern void* FUN_004f3050(uint param_1);
extern uint32_t FUN_004f7c50(void* a, int b);
extern int FUN_0051bfc0(void* a);
extern DWORD FUN_004fda70(void* self);
extern void FUN_00412df0(void* a, DWORD b);
extern void FUN_004fd930(uint32_t a, void* b);
extern void FUN_00524e90(uint32_t a);
extern uint32_t FUN_004fd880(int32_t* param_1);
extern uint32_t FUN_004f7c50b(void* a, int b);
extern char FUN_004f7cc0(void* p);
extern void FUN_004f7be0(void* p);
extern uint32_t FUN_004f7a30(void* a, void* b, void* c);
extern int DAT_008caccc;
extern void FUN_00412f90(void);
extern void FUN_004f3350(void);
extern void FUN_004ed8f0(int a);
extern void FUN_004f0fd0(void);
extern int FUN_00533c78(int a);
extern int FUN_004fb640(void);
extern void FUN_004fb6a0(void* a, int b);
extern void FUN_004fc070(void);
extern void FUN_004e6420(void);
extern char FUN_004fe3a0(void);
extern char FUN_004fbd10(void* a, void* b);
extern uint32_t FUN_004fe080(int param_1);
extern void FUN_00412f10(void);
extern void FUN_004f30d0(int a);
extern void FUN_00412e50(void* a);
extern void* thunk_FUN_00533c78(int a);
extern void FUN_004f2600(const char* a, ...);
extern void FUN_004f1930(void* a, int b, int c);
extern void FUN_00412fb0(void);
extern void FUN_004129c0(void* a, void* b, void* c, void* d);
extern void FUN_00412a60(void* a, void* b);
extern void FUN_00489300(void);
extern void FUN_004fdca0(void);
extern int DAT_00710aa4;
extern int DAT_006f5894;
extern int DAT_00710a30;
extern int DAT_00710a50;
extern void FUN_004f30a0(void);
extern void* FUN_004f3a80(int param_1);
extern void FUN_004f3ad0(void);
extern void FUN_004f1810(void);
extern void FUN_00412c90(void);
extern char FUN_004fd630(void* self, unsigned int in_EAX);
extern void FUN_00412ec0(void);
extern void FUN_004b0df0(void* p);
extern void operator_delete__(void* p);
extern void operator_delete(void* p);
extern uint32_t FUN_004f7c50(void* a, int b);
extern void FUN_004f5670(void);
extern uint32_t FUN_004fda70_recon(int* param_1);
extern void FUN_004fd930_recon(uint32_t a, uint32_t b, void* self);
extern uint32_t FUN_004fe080_recon(int param_1, int* self, int count, uint32_t limit);
extern uint32_t FUN_004fe080(int param_1, void* path);
extern void FUN_00412df0(void);
extern "C" void* memmove(void* dst, const void* src, size_t n);
extern "C" int _stricmp(const char* a, const char* b);
extern "C" char* strrchr(const char* s, int c);
extern void* PTR_FUN_00710a4c;
extern void* PTR_FUN_007109ec;
extern void* PTR_FUN_007109d0;
extern void* PTR_FUN_00710aac;

// 0x4fd4c0 — observed shape
bool FUN_004fd4c0(void* self, uint32_t param_1) {
    int* piVar1;
    char cVar2;
    LPVOID pvVar3;
    int iVar4;
    void* uVar5;
    uint32_t uVar6;
    bool bVar7;
    void* puStack_4;

    HANDLE hHandle = DAT_00726c30;
    bVar7 = false;
    if (DAT_00726c28 != 0xffffffff) {
        pvVar3 = TlsGetValue(DAT_00726c28);
        if (pvVar3 != (LPVOID)0x0) {
            FUN_004fac10();
            goto LAB_004fd4f9;
        }
    }
    WaitForSingleObject(hHandle, 0xffffffff);
LAB_004fd4f9:
    piVar1 = (int*)((char*)self + 0x3c);
    cVar2 = ((char(*)()) (*(void**)((intptr_t)*piVar1 + 0x18)))();
    if (cVar2 != '\0' && param_1 < *(uint32_t*)((char*)self + 0x7c)) {
        ((void(*)(void*, int)) (*(void**)((intptr_t)*piVar1 + 0x1c)))((void*)((intptr_t)*(int*)((char*)self + 0x80) + 4) * param_1 + *(int*)((char*)self + 0x88), 0);
        iVar4 = ((int(*)(void**, int)) (*(void**)((intptr_t)*piVar1 + 0x20)))(&puStack_4, 4);
        if (iVar4 == 4) {
            iVar4 = *piVar1;
            if (*(int*)((char*)self + 8) == 0) {
                uVar5 = FUN_004f3050(param_1);
                uVar6 = ((uint32_t(*)(void*)) (*(void**)((intptr_t)iVar4 + 0x20)))(uVar5);
                bVar7 = (uVar6 == param_1);
                FUN_004f30a0();
            } else {
                puStack_4 = &DAT_008cacd0;
                uVar5 = FUN_004f3a80((int)(param_1 * 2));
                iVar4 = ((int(*)(void*)) (*(void**)((intptr_t)iVar4 + 0x20)))(uVar5);
                bVar7 = ((uint32_t)iVar4 == param_1 * 2);
                FUN_004f3ad0();
                FUN_004f1810();
                FUN_00412c90();
            }
        }
    }
    ReleaseMutex(DAT_00726c30);
    return bVar7;
}

// 0x4fd5e0 — observed shape
uint8_t FUN_004fd5e0(void* self, uint32_t in_EAX) {
    uint8_t uVar1 = 0;
    if (*(int*)((char*)self + 0x70) != 0) {
        if (in_EAX < *(uint32_t*)((char*)self + 0x84) || (uVar1 = 0, *(uint32_t*)((char*)self + 0x84) + 0x10 <= in_EAX)) {
            uVar1 = (uint8_t)FUN_004fd630(self, in_EAX);
        }
        FUN_00412ec0();
    }
    return uVar1;
}

// 0x4fd630 — observed shape
char FUN_004fd630(void* self, uint32_t in_EAX) {
    int* piVar1;
    char cVar3;
    unsigned char* param_1;
    void* puVar4;
    uint32_t uVar5;

    intptr_t iVar2 = (intptr_t)self;
    piVar1 = (int*)((intptr_t)self + 0x70);
    cVar3 = '\0';
    param_1 = &DAT_008cacd0;
    if (*piVar1 != 0) {
        *(uint32_t*)(iVar2 + 0x84) = in_EAX - (in_EAX & 0xf);
        uVar5 = 0;
        cVar3 = '\x01';
        do {
            if (0xf < uVar5 || *(uint32_t*)(iVar2 + 0x7c) <= *(int*)(iVar2 + 0x84) + (int)uVar5) break;
            cVar3 = FUN_004fd4c0(self, *(int*)(iVar2 + 0x84) + uVar5);
            FUN_004b0df0(&param_1);
            uVar5 = uVar5 + 1;
        } while (cVar3 != '\0');
    }
    puVar4 = (void*)(param_1 + -8);
    if (puVar4 != (void*)0x0 && puVar4 != &DAT_008cacc8) {
        operator_delete__(puVar4);
    }
    return cVar3;
}

// 0x4fd6c0 — observed shape
void FUN_004fd6c0(void) {
    HANDLE hHandle;
    LPVOID pvVar1;
    uint32_t uVar2;

    hHandle = DAT_00726c30;
    if (DAT_008cad00 != 0) {
        if (DAT_00726c28 == 0xffffffff || (pvVar1 = TlsGetValue(DAT_00726c28), pvVar1 == (LPVOID)0x0)) {
            WaitForSingleObject(hHandle, 0xffffffff);
        } else {
            FUN_004fac10();
        }
        uVar2 = 0;
        if (*(int*)(DAT_008cad00 + 0xc) != 0) {
            do {
                ((void(*)()) (*(void**)(*(int*)(*(int*)(*(int*)(DAT_008cad00 + 4) + uVar2 * 4) + 0x3c) + 0xc)))();
                uVar2 = uVar2 + 1;
            } while (uVar2 < *(uint32_t*)(DAT_008cad00 + 0xc));
        }
    }
    return;
}

// 0x4fd730 — observed shape
void FUN_004fd730(void) {
    uintptr_t iVar1;
    uint32_t uVar2;

    if (DAT_008cad00 != 0) {
        uVar2 = 0;
        if (*(int*)(DAT_008cad00 + 0xc) != 0) {
            do {
                iVar1 = (uintptr_t)(*(int*)(*(int*)(DAT_008cad00 + 4) + uVar2 * 4));
                ((void(*)(void*, int, int, int)) (*(void**)(*(int*)(iVar1 + 0x3c) + 8)))((void*)*(undefined4*)(iVar1 + 0x6c), 1, 0, 0x8000);
                uVar2 = uVar2 + 1;
            } while (uVar2 < *(uint32_t*)(DAT_008cad00 + 0xc));
        }
        ReleaseMutex(DAT_00726c30);
    }
    return;
}

// 0x4fd780 — observed shape
void FUN_004fd780(void* self, uint8_t param_1) {
    void** pObj = (void**)self;

    *pObj = &PTR_FUN_00710a4c;
    operator_delete__(pObj[1]);
    if ((param_1 & 1) != 0) {
        operator_delete(pObj);
    }
}

// 0x4fd7b0 — observed shape
uint32_t FUN_004fd7b0(int param_1, int param_2) {
    char cVar2;
    int iVar1;
    DWORD DVar3;
    int iVar4;

    cVar2 = (char)FUN_0051bfc0(&param_2);
    if (cVar2 == '\0') {
        return 0;
    }
    iVar1 = *(int*)(param_1 + 8);
    iVar4 = param_2 * 8;
    DVar3 = GetTickCount();
    *(DWORD*)(iVar1 + iVar4 + 4) = DVar3;
    FUN_00412ec0();
    return 1;
}

// 0x4fd810 — observed shape
void FUN_004fd810(void* self, void* in_EDI) {
    uint32_t uVar1;
    DWORD DVar2;
    uintptr_t uVar3;
    int local_8;

    uVar1 = FUN_004fda70(in_EDI);
    DVar2 = GetTickCount();
    uVar3 = (uintptr_t)self;
    FUN_00412df0((void*)uVar3, DVar2);
    uVar3 = (uintptr_t)FUN_004f7c50((void*)uVar3, (int)DVar2);
    FUN_004fd930(uVar1, (void*)uVar3);
    if (((void*)(intptr_t)(local_8 - 8) != (void*)0x0) &&
        ((void*)(intptr_t)(local_8 - 8) != &DAT_008cacc8)) {
        operator_delete__((void*)(intptr_t)(local_8 - 8));
    }
    FUN_00524e90(uVar1);
    return;
}

// 0x4fd880 — observed shape
uint32_t FUN_004fd880_recon(int* param_1, void* self) {
    uint32_t uVar1;
    uint32_t uVar2;
    int iVar3;
    int* piVar4;
    intptr_t iVar5 = (intptr_t)self;

    if (*param_1 == 0) {
        return 0xffffffff;
    }
    uVar1 = *(uint32_t*)(iVar5 + 0xc);
    uVar2 = 0;
    if (uVar1 != 0) {
        piVar4 = *(int**)(iVar5 + 4);
        do {
            if (*piVar4 == 0) {
                (*(int**)(iVar5 + 4))[uVar2] = *param_1;
                *(int*)(iVar5 + 0x10) = *(int*)(iVar5 + 0x10) + 1;
                return uVar2;
            }
            uVar2 = uVar2 + 1;
            piVar4 = piVar4 + 1;
        } while (uVar2 < *(uint32_t*)(iVar5 + 0xc));
    }
    if ((*(uint32_t*)(iVar5 + 8) <= uVar1) && (FUN_004f5670(), *(uint32_t*)(iVar5 + 8) <= uVar1)) {
        return uVar1;
    }
    if (uVar1 < *(uint32_t*)(iVar5 + 0xc)) {
        if (*param_1 == 0) {
            if (*(int*)(*(int*)(iVar5 + 4) + uVar1 * 4) == 0) goto LAB_004fd917;
            iVar3 = *(int*)(iVar5 + 0x10) + -1;
        } else {
            if (*(int*)(*(int*)(iVar5 + 4) + uVar1 * 4) != 0) goto LAB_004fd917;
            iVar3 = *(int*)(iVar5 + 0x10) + 1;
        }
    } else {
        *(uint32_t*)(iVar5 + 0xc) = uVar1 + 1;
        if (*param_1 == 0) goto LAB_004fd917;
        iVar3 = *(int*)(iVar5 + 0x10) + 1;
    }
    *(int*)(iVar5 + 0x10) = iVar3;
LAB_004fd917:
    *(int*)(*(int*)(iVar5 + 4) + uVar1 * 4) = *param_1;
    return uVar1;
}

// 0x4fd930 — observed shape
void FUN_004fd930_recon(uint32_t param_1, uint32_t param_2, void* self) {
    char cVar1;
    char cVar2;
    void* puVar3;
    int iVar4;
    intptr_t iVar5 = (intptr_t)self;
    int local_8;

    if (*(uint32_t*)(iVar5 + 8) <= param_1) {
        return;
    }
    if (param_1 < *(uint32_t*)(iVar5 + 0xc)) {
        FUN_004f7c50(&DAT_008cacd0, 0);
        cVar1 = FUN_004f7cc0((void*)(uintptr_t)param_2);
        puVar3 = (void*)(intptr_t)(local_8 - 8);
        if ((puVar3 != (void*)0x0) && (puVar3 != &DAT_008cacc8)) {
            operator_delete__(puVar3);
        }
        FUN_004f7c50(&DAT_008cacd0, 0);
        cVar2 = FUN_004f7cc0((void*)(intptr_t)(*(int*)(iVar5 + 4) + (int)param_1 * 8));
        if (cVar1 == '\0') {
            puVar3 = (void*)(intptr_t)(local_8 - 8);
            if ((puVar3 != (void*)0x0) && (puVar3 != &DAT_008cacc8)) {
                operator_delete__(puVar3);
            }
            if (cVar2 == '\0') goto LAB_004fda51;
            iVar4 = *(int*)(iVar5 + 0x10) + 1;
        } else {
            puVar3 = (void*)(intptr_t)(local_8 - 8);
            if ((puVar3 != (void*)0x0) && (puVar3 != &DAT_008cacc8)) {
                operator_delete__(puVar3);
            }
            if (cVar2 != '\0') goto LAB_004fda51;
            iVar4 = *(int*)(iVar5 + 0x10) + -1;
        }
    } else {
        *(uint32_t*)(iVar5 + 0xc) = param_1 + 1;
        FUN_004f7c50(&DAT_008cacd0, 0);
        cVar1 = FUN_004f7cc0((void*)(uintptr_t)param_2);
        puVar3 = (void*)(intptr_t)(local_8 - 8);
        if ((puVar3 != (void*)0x0) && (puVar3 != &DAT_008cacc8)) {
            operator_delete__(puVar3);
        }
        if (cVar1 != '\0') goto LAB_004fda51;
        iVar4 = *(int*)(iVar5 + 0x10) + 1;
    }
    *(int*)(iVar5 + 0x10) = iVar4;
LAB_004fda51:
    FUN_004f7be0((void*)(uintptr_t)param_2);
    return;
}

// 0x4fda70 — observed shape
uint32_t FUN_004fda70_recon(int* param_1) {
    uint32_t* puVar1;
    int iVar2;
    int* piVar3;
    DWORD DVar4;
    int* puVar5;
    int iVar6;
    uint32_t uVar7;
    int* piVar8;
    uint32_t uVar9;
    int local_8[2];

    piVar3 = param_1;
    uVar9 = (uint32_t)param_1[4];
    if (param_1[4] == 0x32) {
        DVar4 = GetTickCount();
        puVar1 = (uint32_t*)(param_1 + 4);
        uVar7 = 0;
        uVar9 = 0;
        param_1 = (int*)0x0;
        if (*puVar1 != 0) {
            piVar8 = (int*)(piVar3[2] + 4);
            do {
                if (uVar9 <= DVar4 - (uint32_t)*piVar8) {
                    uVar9 = DVar4 - (uint32_t)*piVar8;
                    param_1 = (int*)(uintptr_t)uVar7;
                }
                uVar7 = uVar7 + 1;
                piVar8 = piVar8 + 2;
            } while (uVar7 < *puVar1);
        }
        piVar8 = (int*)FUN_004f7a30(piVar3 + 1, local_8, param_1);
        iVar6 = DAT_008caccc;
        iVar2 = *piVar3;
        if (iVar2 == 1) {
            operator_delete((void*)*piVar8);
        } else if (iVar2 == 2) {
            operator_delete__((void*)*piVar8);
        } else if (((iVar2 == 3) && (-1 < DAT_008caccc)) &&
                   ((void*)*piVar8 != &DAT_008cacd0)) {
            if (DAT_008caccc == 0) {
                FUN_00412f90();
            } else {
                FUN_004f3350();
                memmove((void*)*piVar8, &DAT_008cacd0, (size_t)iVar6);
                *(uint8_t*)(*piVar8 + *(int*)(*piVar8 + -4)) = 0;
            }
        }
        if (((void*)(intptr_t)(local_8[0] - 8) != (void*)0x0) &&
            ((void*)(intptr_t)(local_8[0] - 8) != &DAT_008cacc8)) {
            operator_delete__((void*)(intptr_t)(local_8[0] - 8));
        }
        uVar9 = 0;
        if (piVar3[8] != 0) {
            piVar8 = (int*)piVar3[9];
            do {
                if (*piVar8 != 0) {
                    piVar8 = (int*)((int*)piVar3[9])[uVar9];
                    goto LAB_004fdb6f;
                }
                uVar9 = uVar9 + 1;
                piVar8 = piVar8 + 1;
            } while (uVar9 < (uint32_t)piVar3[8]);
        }
        piVar8 = (int*)0x0;
LAB_004fdb6f:
        if (piVar8 != (int*)0x0) {
            do {
                iVar2 = piVar8[1];
                uVar9 = (uint32_t)piVar8[2];
                piVar8 = (int*)*piVar8;
                if (piVar8 == (int*)0x0) {
                    iVar6 = ((int(*)(int))(*(void**)(piVar3[7] + 4)))(iVar2);
                    uVar7 = (uint32_t)(iVar6 + 1);
                    if (uVar7 < (uint32_t)piVar3[8]) {
                        puVar5 = (int*)(piVar3[9] + (int)uVar7 * 4);
                        do {
                            piVar8 = (int*)*puVar5;
                            if (piVar8 != (int*)0x0) goto LAB_004fdba5;
                            uVar7 = uVar7 + 1;
                            puVar5 = puVar5 + 1;
                        } while (uVar7 < (uint32_t)piVar3[8]);
                    }
                    piVar8 = (int*)0x0;
                }
LAB_004fdba5:
                if ((int*)uVar9 == param_1) {
                    FUN_004ed8f0(iVar2);
                    break;
                }
                if (piVar8 == (int*)0x0) {
                    return (uint32_t)(uintptr_t)param_1;
                }
            } while (true);
        }
        uVar9 = (uint32_t)(uintptr_t)param_1;
    }
    return uVar9;
}

// 0x4fdbe0 — observed shape
uint8_t FUN_004fdbe0_recon(HANDLE* param_1, const char* in_EAX, const char* in_ECX,
                           const char* in_EDI) {
    HANDLE pvVar1;
    DWORD DVar2;
    HWND hWnd;
    BOOL BVar3;
    uint8_t uVar4 = 0;

    if ((in_EAX != (const char*)0x0) && (*in_EAX != '\0')) {
        pvVar1 = CreateMutexA((LPSECURITY_ATTRIBUTES)0x0, 0, in_EAX);
        *param_1 = pvVar1;
        if (pvVar1 != (HANDLE)0x0) {
            DVar2 = GetLastError();
            if (DVar2 == 0xb7) {
                if ((((in_EDI != (const char*)0x0) && (*in_EDI != '\0')) &&
                     (in_ECX != (const char*)0x0)) && (*in_ECX != '\0')) {
                    hWnd = FindWindowA(in_EDI, in_ECX);
                    if (hWnd != (HWND)0x0) {
                        BVar3 = IsIconic(hWnd);
                        if (BVar3 != 0) {
                            ShowWindow(hWnd, 9);
                        }
                        SetForegroundWindow(hWnd);
                        return 0;
                    }
                }
            } else {
                uVar4 = 1;
            }
        }
    }
    return uVar4;
}

// 0x4fdc60 — observed shape
void FUN_004fdc60_recon(HMODULE in_EAX) {
    DWORD DVar1;
    CHAR local_104[260];

    if (in_EAX != (HMODULE)0x0) {
        DVar1 = GetModuleFileNameA(in_EAX, local_104, 0x104);
        if (DVar1 != 0) {
            FUN_004fdca0();
        }
    }
    return;
}

// 0x4fdca0 — observed shape
// WARNING: corpus removes unreachable block at ram,0x004fdf2c
void FUN_004fdca0_recon(int in_EAX, uint16_t* in_ECX) {
    char* pcVar1;
    uint16_t uVar2;
    uint16_t uVar3;
    int iVar4;
    void* puVar5;
    DWORD dwLen;
    LPVOID lpData;
    BOOL BVar6;
    int iVar7;
    uint8_t* puVar8;
    uint8_t* puVar9;
    uint8_t* local_20;
    char* local_1c;
    DWORD local_18;
    LPVOID local_14;
    uint16_t* local_10;
    LPVOID local_c;
    uint32_t local_8;
    uint8_t local_4[4];

    if (in_EAX != 0) {
        FUN_00412f10();
        iVar4 = DAT_008caccc + -4;
        iVar7 = 4;
        if (iVar4 < 0) {
            iVar4 = 0;
        }
        if (DAT_008caccc < iVar4 + 4) {
            iVar7 = DAT_008caccc - iVar4;
        }
        if (DAT_008caccc < iVar4) {
            iVar7 = 0;
        }
        if ((iVar4 == 0) && (iVar7 == DAT_008caccc)) {
            FUN_00412df0();
        } else {
            local_20 = &DAT_008cacd0;
            FUN_004f30d0(iVar4);
            FUN_00412df0();
            puVar5 = (void*)(intptr_t)((intptr_t)local_20 - 8);
            if ((puVar5 != (void*)0x0) && (puVar5 != &DAT_008cacc8)) {
                operator_delete__(puVar5);
            }
        }
        pcVar1 = local_1c;
        iVar4 = _stricmp(local_1c, ".exe");
        pcVar1 = pcVar1 - 8;
        if ((pcVar1 != (char*)0x0) && (pcVar1 != (char*)&DAT_008cacc8)) {
            operator_delete__((void*)pcVar1);
        }
        if (iVar4 != 0) {
            FUN_00412e50(&DAT_00710aa4);
        }
        dwLen = GetFileVersionInfoSizeA((LPCSTR)&DAT_008cacd0, &local_18);
        if ((dwLen != 0) &&
            (lpData = (LPVOID)thunk_FUN_00533c78((int)dwLen), lpData != (LPVOID)0x0)) {
            BVar6 = GetFileVersionInfoA((LPCSTR)&DAT_008cacd0, local_18, dwLen, lpData);
            if ((BVar6 != 0) &&
                (BVar6 = VerQueryValueA(lpData, "\\", &local_14, (PUINT)&local_20), BVar6 != 0)) {
                *in_ECX = *(uint16_t*)((intptr_t)local_14 + 10);
                in_ECX[1] = *(uint16_t*)((intptr_t)local_14 + 8);
                uVar2 = *(uint16_t*)((intptr_t)local_14 + 0xe);
                in_ECX[2] = uVar2;
                uVar3 = *(uint16_t*)((intptr_t)local_14 + 0xc);
                in_ECX[3] = uVar3;
                FUN_004f2600("%d.%d.%d.%d", *in_ECX, in_ECX[1], uVar2, uVar3);
                FUN_00412f90();
                BVar6 = VerQueryValueA(lpData, "\\VarFileInfo\\Translation", &local_10,
                                       (PUINT)&local_20);
                if ((BVar6 != 0) && ((uint8_t*)0x3 < local_20)) {
                    local_1c = (char*)&DAT_008cacd0;
                    FUN_004f2600("\\StringFileInfo\\%04x%04x\\FileVersion", *local_10, local_10[1]);
                    BVar6 = VerQueryValueA(lpData, local_1c, &local_c, (PUINT)&local_20);
                    if (BVar6 != 0) {
                        FUN_00412f10();
                        local_8 = 0;
                        FUN_004f1930(local_4, 0x28, 0x29);
                        FUN_00412ec0();
                        FUN_00412fb0();
                        if (*(int*)(*(int*)(in_ECX + 4) + -4) != 0) {
                            puVar9 = &DAT_00710a50;
                            puVar8 = local_4;
                            FUN_004129c0(&local_8, in_ECX + 4, puVar8, &DAT_00710a50);
                            FUN_00412a60(puVar8, puVar9);
                            FUN_00489300();
                            FUN_00412fb0();
                            FUN_00412fb0();
                        }
                    }
                    FUN_00412fb0();
                }
            }
            operator_delete__(lpData);
        }
    }
    return;
}

// 0x4fdf40 — observed shape
// WARNING: corpus removes unreachable block at ram,0x004fe016
uint32_t FUN_004fdf40_recon(int* param_1, int unaff_EBX) {
    uint8_t uVar1;
    char* pcVar2;
    int iVar3;
    uint32_t uVar4 = 0;

    FUN_00412f10();
    iVar3 = DAT_008caccc;
    if ((DAT_008caccc + -1 < DAT_008caccc) && (-1 < DAT_008caccc + -1)) {
        uVar1 = *(uint8_t*)((intptr_t)&DAT_008caccc + DAT_008caccc + 3);
        *(uint8_t*)((intptr_t)&DAT_008caccc + DAT_008caccc + 3) = 0;
        pcVar2 = strrchr((const char*)&DAT_008cacd0, 0x2e);
        *(uint8_t*)((intptr_t)&DAT_008caccc + iVar3 + 3) = uVar1;
        if ((pcVar2 != (char*)0x0) && (-1 < (int)(intptr_t)(pcVar2 - 0x8cacd0))) goto LAB_004fdfac;
    }
    FUN_00412e50(&DAT_006f5894);
    FUN_00412e50(&DAT_00710a30);
LAB_004fdfac:
    iVar3 = ((int(*)(void*, int, int, int))(*(void**)(*param_1 + 8)))(&DAT_008cacd0, 1, 0, 0);
    if (iVar3 == 0) {
        FUN_004f0fd0();
        if (unaff_EBX == 0) {
            iVar3 = FUN_00533c78(0x20);
            if (iVar3 == 0) {
                unaff_EBX = 0;
            } else {
                unaff_EBX = FUN_004fb640();
            }
            param_1[10] = unaff_EBX;
        }
        uVar4 = FUN_004fe080(unaff_EBX, &DAT_008cacd0);
    }
    return uVar4;
}

// 0x4fe030 — observed shape
void FUN_004fe030_recon(int* self) {
    void* puVar1;

    ((void(*)(void))(*(void**)(*self + 0xc)))();
    puVar1 = (void*)self[10];
    if (puVar1 != (void*)0x0) {
        FUN_004fb6a0(puVar1, 1);
        FUN_004fc070();
        *(void**)puVar1 = &PTR_FUN_007109ec;
        FUN_004e6420();
        *(void**)puVar1 = &PTR_FUN_007109d0;
        FUN_004e6420();
        operator_delete__(((void**)puVar1)[2]);
        operator_delete(puVar1);
        self[10] = 0;
    }
    return;
}

// 0x4fe080 — observed shape
uint32_t FUN_004fe080_recon(int param_1, int* self, int unaff_EBP, uint32_t unaff_ESI) {
    char cVar1;
    int iVar2;
    int* puVar3;
    uint32_t uVar4;
    uint32_t local_10[2];
    uint32_t uStack_8;

    local_10[0] = 0;
    if (param_1 != 0) {
        cVar1 = ((char(*)(void))(*(void**)(*self + 0x18)))();
        if (cVar1 != '\0') {
            iVar2 = ((int(*)(void*, int))(*(void**)(*self + 0x20)))(self + 0xd, 4);
            if ((iVar2 == 4) && ((uint32_t)self[0xd] < 3)) {
                iVar2 = ((int(*)(void*, int))(*(void**)(*self + 0x20)))(local_10, 4);
                if ((iVar2 == 4) && (uVar4 = 0, unaff_ESI != 0)) {
                    do {
                        puVar3 = (int*)thunk_FUN_00533c78(0x28);
                        if (puVar3 != (int*)0x0) {
                            puVar3[2] = (int)(intptr_t)&DAT_008cacd0;
                            puVar3[3] = (int)(intptr_t)&DAT_008cacd0;
                            *puVar3 = 0;
                            puVar3[1] = 0;
                            puVar3[4] = 0;
                            puVar3[5] = 0;
                            puVar3[6] = 0;
                            puVar3[7] = 0;
                            puVar3[8] = 0;
                            puVar3[9] = 0;
                            cVar1 = FUN_004fe3a0();
                            if (cVar1 != '\0') {
                                cVar1 = FUN_004fbd10(puVar3, (void*)(uintptr_t)uStack_8);
                                if (cVar1 != '\0') {
                                    unaff_EBP = unaff_EBP + 1;
                                }
                            }
                        }
                        uVar4 = uVar4 + 1;
                    } while (uVar4 < unaff_ESI);
                    return (uint32_t)unaff_EBP;
                }
            }
            return 0;
        }
    }
    return 0;
}

// 0x4fe190 — observed shape
int FUN_004fe190_recon(int param_1, int in_EAX, int* self, uint32_t unaff_EBX, int unaff_ESI) {
    HANDLE hHandle;
    int iVar1;
    LPVOID pvVar2;
    int iVar3;

    hHandle = (HANDLE)self[0xc];
    if (DAT_00726c28 != 0xffffffff) {
        pvVar2 = TlsGetValue(DAT_00726c28);
        if (pvVar2 != (LPVOID)0x0) {
            FUN_004fac10();
            goto LAB_004fe1c1;
        }
    }
    WaitForSingleObject(hHandle, 0xffffffff);
LAB_004fe1c1:
    iVar3 = 0;
    if ((unaff_ESI != 0) && (param_1 != 0)) {
        if (in_EAX == 0) {
            in_EAX = *(int*)(unaff_ESI + 0x18);
        }
        iVar1 = *(int*)(unaff_ESI + 0x14);
        if (*(uint32_t*)(unaff_ESI + 0x18) < (uint32_t)(iVar1 + in_EAX)) {
            in_EAX = *(uint32_t*)(unaff_ESI + 0x18) - iVar1;
        }
        if (in_EAX != 0) {
            ((void(*)(void*, int))(*(void**)(*self + 0x1c)))(
                (void*)(intptr_t)(*(int*)(unaff_ESI + 0x1c) + iVar1), 0);
            iVar3 = ((int(*)(void*, int))(*(void**)(*self + 0x20)))(
                (void*)(uintptr_t)unaff_EBX, in_EAX);
            *(int*)(unaff_ESI + 0x14) = *(int*)(unaff_ESI + 0x14) + iVar3;
        }
    }
    ReleaseMutex((HANDLE)self[0xc]);
    return iVar3;
}

// 0x4fe220 — observed shape
uint32_t FUN_004fe220_recon(uint32_t in_EAX, uint32_t in_ECX, int in_EDX) {
    uint32_t uVar1;
    uint32_t uVar2;

    uVar2 = 0;
    if (in_EDX == 0) {
        return 0;
    }
    if ((in_ECX == 0) && (in_EAX == 1)) {
        return *(uint32_t*)(in_EDX + 0x14);
    }
    if (in_EAX == 0) {
        if (0 < (int)in_ECX) {
            uVar2 = *(uint32_t*)(in_EDX + 0x18);
            if (in_ECX <= uVar2) {
                *(uint32_t*)(in_EDX + 0x14) = in_ECX;
                return in_ECX;
            }
            goto LAB_004fe292;
        }
    } else if (in_EAX == 1) {
        uVar2 = *(uint32_t*)(in_EDX + 0x14);
        if (-1 < (int)in_ECX) {
            uVar2 = uVar2 + in_ECX;
            uVar1 = *(uint32_t*)(in_EDX + 0x18);
            if (uVar1 < uVar2) {
                *(uint32_t*)(in_EDX + 0x14) = uVar1;
                return uVar1;
            }
            goto LAB_004fe292;
        }
        if (-(int)in_ECX < (int)uVar2) {
            *(uint32_t*)(in_EDX + 0x14) = uVar2 + in_ECX;
            return uVar2 + in_ECX;
        }
    } else {
        if ((in_EAX != 2) || (uVar2 = *(uint32_t*)(in_EDX + 0x18), -1 < (int)in_ECX))
            goto LAB_004fe292;
        if ((-(int)in_ECX < (int)uVar2) || (-(int)uVar2 == (int)in_ECX)) {
            *(uint32_t*)(in_EDX + 0x14) = uVar2 + in_ECX;
            return uVar2 + in_ECX;
        }
    }
    uVar2 = 0;
LAB_004fe292:
    *(uint32_t*)(in_EDX + 0x14) = uVar2;
    return uVar2;
}

// 0x4fe2a0 — observed shape
void FUN_004fe2a0_recon(void* self, uint8_t param_1) {
    void** pObj = (void**)self;

    *pObj = &PTR_FUN_00710aac;
    CloseHandle((HANDLE)pObj[1]);
    if ((param_1 & 1) != 0) {
        operator_delete(pObj);
    }
    return;
}
