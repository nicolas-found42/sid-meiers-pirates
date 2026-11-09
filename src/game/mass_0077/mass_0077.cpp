#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_00412f10();
extern void FUN_004fc360(uint32_t param_1, uint32_t param_2);
extern int FUN_00533c78(uint32_t size);
extern int FUN_004fe5e0(uint32_t param_1, uint32_t param_2, char* param_3, char* param_4, uint32_t param_5, bool param_6);
extern void FUN_004fb6a0(void* ptr, int flag);
extern void FUN_004e6420();
extern void FUN_004fc070();
extern void operator_delete(void* ptr);
extern void operator_delete__(void* ptr);
extern void FUN_004f0dc0();
extern void FUN_004fe030();
extern void FUN_00412e50(const void* ptr);
extern void FUN_004fb970(const void* ptr, uint32_t param_2, uint32_t param_3);
extern void FUN_004f3350();
extern uint32_t FUN_004fc690(uint32_t param_1, uint32_t param_2);
extern void _strupr(char* str);
extern uint32_t FUN_004fbf10();
extern void FUN_004f1840();
extern void FUN_00524e90(uint32_t ptr);
extern uint32_t FUN_004fdf40(uint32_t ptr, uint32_t param_1, uint32_t param_2);

// 0x4fc0b0 — observed shape
void FUN_004fc0b0(void* self, uint32_t param_1, char* param_2, int* param_3) {
    char* in_EAX = nullptr;
    uint32_t in_ECX = 0;
    uint32_t unaff_EDI = 0;
    (void)self;
    if ((in_EAX != nullptr) && (*in_EAX != '\0')) {
        FUN_00412f10();
        FUN_004fc360(unaff_EDI, in_ECX);
    }
    FUN_004fc360(unaff_EDI, in_ECX);
    if (in_EAX != nullptr && *in_EAX != '\0' && param_2 != nullptr && *param_2 != '\0') {
        int iVar1 = FUN_00533c78(0x4c);
        if (iVar1 == 0) {
            iVar1 = 0;
        } else {
            iVar1 = FUN_004fe5e0(unaff_EDI, param_1, in_EAX, param_2, in_ECX, param_3 == nullptr);
        }
        *(uint32_t*)(iVar1 + 0x18) = 0;
        if ((*(uint8_t*)(iVar1 + 0x24) & 1) == 0) {
            *(uint8_t*)(iVar1 + 0x24) = *(uint8_t*)(iVar1 + 0x24) | 1;
            ResumeThread(*(HANDLE*)(iVar1 + 0x2c));
        }
        if (param_3 != nullptr) {
            *param_3 = iVar1;
        }
    }
}

// 0x4fc180 — observed shape
void FUN_004fc180(void* self) {
    int* piVar1 = nullptr;
    int* piVar3 = nullptr;
    int* piVar6 = nullptr;
    uint32_t uVar2 = 0;
    int iVar4 = 0;
    uint32_t* puVar5 = nullptr;
    int in_EAX = (int)(intptr_t)self;
    FUN_004fb6a0((void*)(intptr_t)in_EAX, 1);
    uVar2 = 0;
    if (*(uint32_t*)(in_EAX + 0x24) != 0) {
        piVar3 = *(int**)(in_EAX + 0x28);
        do {
            if (*piVar3 != 0) {
                piVar3 = *(int**)(in_EAX + 0x28);
                piVar3 = (int*)piVar3[uVar2];
                goto joined_r0x004fc1b3;
            }
            uVar2 = uVar2 + 1;
            piVar3 = piVar3 + 1;
        } while (uVar2 < *(uint32_t*)(in_EAX + 0x24));
    }
    piVar3 = (int*)0x0;
joined_r0x004fc1b3:
    do {
        if (piVar3 == (int*)0x0) {
            FUN_004e6420();
            return;
        }
        piVar6 = (int*)*piVar3;
        piVar1 = (int*)piVar3[2];
        if (piVar6 == (int*)0x0) {
            iVar4 = (int)((uint32_t(*)(int))(*(uint32_t*)(in_EAX + 0x20) + 4))(piVar3[1]);
            uVar2 = iVar4 + 1;
            if (uVar2 < *(uint32_t*)(in_EAX + 0x24)) {
                puVar5 = (uint32_t*)(*(int*)(in_EAX + 0x28) + uVar2 * 4);
                do {
                    piVar6 = (int*)*puVar5;
                    if (piVar6 != (int*)0x0) goto LAB_004fc204;
                    uVar2 = uVar2 + 1;
                    puVar5 = puVar5 + 1;
                } while (uVar2 < *(uint32_t*)(in_EAX + 0x24));
            }
            piVar6 = (int*)0x0;
        }
LAB_004fc204:
        (void)(**(uint32_t(**)(void))(*piVar1 + 0xc))();
        puVar5 = (uint32_t*)piVar1[10];
        if (puVar5 != (uint32_t*)0x0) {
            FUN_004fb6a0(puVar5, 1);
            FUN_004fc070();
            *puVar5 = 0x7109ec;
            FUN_004e6420();
            *puVar5 = 0x7109d0;
            FUN_004e6420();
            operator_delete__((void*)puVar5[2]);
            operator_delete(puVar5);
            piVar1[10] = 0;
        }
        (void)(**(uint32_t(**)(void))(*piVar1 + 0xc))();
        puVar5 = (uint32_t*)piVar1[10];
        if (puVar5 != (uint32_t*)0x0) {
            FUN_004fb6a0(puVar5, 1);
            FUN_004fc070();
            *puVar5 = 0x7109ec;
            FUN_004e6420();
            *puVar5 = 0x7109d0;
            FUN_004e6420();
            operator_delete__((void*)puVar5[2]);
            operator_delete(puVar5);
            piVar1[10] = 0;
        }
        piVar1[0xb] = 0x7109b0;
        CloseHandle((HANDLE)piVar1[0xc]);
        *piVar1 = 0x6f5864;
        FUN_004f0dc0();
        puVar5 = (uint32_t*)(piVar1[7] + -8);
        if ((puVar5 != (uint32_t*)0x0) && (puVar5 != (uint32_t*)0x8cacc8)) {
            operator_delete__(puVar5);
        }
        piVar1[7] = 0x8cacd0;
        operator_delete(piVar1);
        piVar3 = piVar6;
    } while (true);
}

// 0x4fc300 — observed shape
void FUN_004fc300(void* self, uint8_t param_1) {
    uint32_t* in_EAX = (uint32_t*)self;
    uint32_t* puVar1 = nullptr;
    FUN_004fe030();
    in_EAX[0xb] = 0x7109b0;
    CloseHandle((HANDLE)in_EAX[0xc]);
    *in_EAX = 0x6f5864;
    FUN_004f0dc0();
    puVar1 = (uint32_t*)(in_EAX[7] + -8);
    if ((puVar1 != (uint32_t*)0x0) && (puVar1 != (uint32_t*)0x8cacc8)) {
        operator_delete__(puVar1);
    }
    in_EAX[7] = 0x8cacd0;
    if ((param_1 & 1) != 0) {
        operator_delete(in_EAX);
    }
}

// 0x4fc360 — observed shape
void FUN_004fc360(void* self, uint32_t param_1, uint32_t param_2) {
    char cVar1 = 0;
    int iVar2 = 0;
    char* pcVar3 = nullptr;
    HANDLE hFindFile = nullptr;
    CHAR* pCVar4 = nullptr;
    size_t _Size = 0;
    BOOL BVar5 = 0;
    char* pcVar6 = nullptr;
    WIN32_FIND_DATAA local_140;
    (void)self;
    FUN_00412f10();
    pcVar3 = (char*)0x8cacd0 + *(int*)0x8caccc;
    for (pcVar6 = (char*)0x8cacd0; pcVar6 < pcVar3; pcVar6 = pcVar6 + 1) {
        if (*pcVar6 == '/') {
            *pcVar6 = '\\';
        }
    }
    if (*(char*)((int)0x8caccc + *(int*)0x8caccc + 3) != '\\') {
        FUN_00412e50((void*)0x70c164);
    }
    FUN_004fb970((void*)0x8cacd0, 0, param_2);
    FUN_00412e50((void*)0x710a34);
    FUN_00412e50((void*)0x710a30);
    hFindFile = FindFirstFileA((char*)0x8cacd0, &local_140);
    if (hFindFile != (HANDLE)0xffffffff) {
        do {
            iVar2 = *(int*)0x8caccc;
            pCVar4 = local_140.cFileName;
            do {
                cVar1 = *pCVar4;
                pCVar4 = pCVar4 + 1;
            } while (cVar1 != '\0');
            _Size = (int)(intptr_t)pCVar4 - (int)(intptr_t)(local_140.cFileName + 1);
            if ((0 < (int)_Size) && (-1 < *(int*)0x8caccc)) {
                if (*(int*)0x8caccc < (int)(_Size + *(int*)0x8caccc)) {
                    FUN_004f3350();
                    ((char*)0x8cacd0)[*(int*)0x8caccc] = 0;
                }
                memmove((char*)0x8cacd0 + iVar2, local_140.cFileName, _Size);
            }
            FUN_004fc690(param_1, 0);
            BVar5 = FindNextFileA(hFindFile, &local_140);
        } while (BVar5 != 0);
        FindClose(hFindFile);
    }
}

// 0x4fc690 — observed shape
uint32_t FUN_004fc690(void* self, uint32_t param_1, uint32_t param_2) {
    uint32_t* puVar1 = nullptr;
    uint8_t uVar2 = 0;
    int iVar3 = 0;
    char* pcVar4 = nullptr;
    uint32_t uVar5 = 0;
    uint32_t local_c = 0;
    int local_4 = 0;
    (void)self;
    FUN_00412f10();
    _strupr((char*)0x8cacd0);
    iVar3 = FUN_00533c78(0x38);
    if (iVar3 == 0) {
        local_c = 0;
    } else {
        local_c = FUN_004fbf10();
    }
    iVar3 = *(int*)0x8caccc;
    if ((*(int*)0x8caccc + -1 < *(int*)0x8caccc) && (-1 < *(int*)0x8caccc + -1)) {
        uVar2 = *(uint8_t*)((int)0x8caccc + *(int*)0x8caccc + 3);
        *(uint8_t*)((int)0x8caccc + *(int*)0x8caccc + 3) = 0;
        pcVar4 = strrchr((char*)0x8cacd0, 0x5c);
        *(uint8_t*)((int)0x8caccc + iVar3 + 3) = uVar2;
        if ((pcVar4 != (char*)0x0) && (-1 < (int)(intptr_t)(pcVar4 + -0x8cacd0))) {
            FUN_004f1840();
            FUN_00524e90(local_c);
            puVar1 = (uint32_t*)(local_4 + -8);
            if ((puVar1 != (uint32_t*)0x0) && (puVar1 != (uint32_t*)0x8cacc8)) {
                operator_delete__(puVar1);
            }
            goto LAB_004fc75d;
        }
    }
    FUN_00524e90(local_c);
LAB_004fc75d:
    uVar5 = FUN_004fdf40(local_c, param_1, param_2);
    return uVar5;
}

// 0x4fc7a0 — observed shape
void FUN_004fc7a0(uint32_t param_1, int param_2) {
    uint8_t uVar1 = 0;
    bool bVar2 = false;
    bool bVar3 = false;
    int iVar4 = param_2;
    char cVar5 = 0;
    int iVar6 = 0;
    char* pcVar7 = nullptr;
    uint32_t* puVar8 = nullptr;
    char* pcVar9 = nullptr;
    char* local_4 = nullptr;
    extern void FUN_004fbd10(int, int);
    extern void FUN_004f1840();
    extern int _stricmp(char*, const char*);
    extern void FUN_00412ec0();
    extern char FUN_0051bfc0(char**);
    extern void FUN_004129c0(int*, int);
    iVar4 = param_2;
    bVar3 = false;
    FUN_004fbd10(param_2, 1);
    if (3 < *(int*)(*(int*)(iVar4 + 8) + -4)) {
        bVar3 = true;
        FUN_004f1840();
        iVar6 = _stricmp(local_4, ".FPK");
        if (iVar6 == 0) {
            bVar2 = true;
            goto LAB_004fc809;
        }
    }
    bVar2 = false;
LAB_004fc809:
    if ((bVar3) && (pcVar7 = local_4 + -8, pcVar7 != (char*)0x0) && (pcVar7 != (char*)0x8cacc8)) {
        operator_delete__(pcVar7);
    }
    if (bVar2) {
        FUN_00412ec0();
        iVar6 = *(int*)0x8caccc;
        if ((*(int*)0x8caccc + -1 < *(int*)0x8caccc) && (-1 < *(int*)0x8caccc + -1)) {
            uVar1 = *(uint8_t*)((int)0x8caccc + *(int*)0x8caccc + 3);
            *(uint8_t*)((int)0x8caccc + *(int*)0x8caccc + 3) = 0;
            pcVar7 = strrchr((char*)0x8cacd0, 0x5c);
            *(uint8_t*)((int)0x8caccc + iVar6 + 3) = uVar1;
            if ((pcVar7 != (char*)0x0) && (-1 < (int)(intptr_t)(pcVar7 + -0x8cacd0))) {
                pcVar7 = pcVar7 + -0x8caccf;
                pcVar9 = pcVar7;
                if (*(int*)0x8caccc < (int)(intptr_t)pcVar7) {
                    pcVar9 = (char*)(intptr_t)*(int*)0x8caccc;
                }
                if ((pcVar7 == (char*)(intptr_t)*(int*)0x8caccc || (int)(intptr_t)pcVar7 < *(int*)0x8caccc) && pcVar7 != (char*)(intptr_t)*(int*)0x8caccc) {
                    if ((0 < (int)(intptr_t)pcVar9) && (0 < *(int*)0x8caccc)) {
                        memmove((void*)0x8cacd0, pcVar9 + 0x8cacd0, (*(int*)0x8caccc - (int)(intptr_t)pcVar9) + 1);
                        *(int*)0x8caccc = *(int*)0x8caccc - (int)(intptr_t)pcVar9;
                    }
                } else if (*(int*)0x8caccc != 0) {
                    *(char*)0x8cacd0 = 0;
                    *(int*)0x8caccc = 0;
                }
            }
        }
        _strupr((char*)0x8cacd0);
        cVar5 = FUN_0051bfc0(&local_4);
        if ((cVar5 != '\0') && (FUN_004fe030(), local_4 != (char*)0x0)) {
            FUN_004fc300(1);
        }
        FUN_004129c0(&param_2, iVar4 + 8);
        FUN_00412ec0();
        puVar8 = (uint32_t*)(param_2 + -8);
        if ((puVar8 != (uint32_t*)0x0) && (puVar8 != (uint32_t*)0x8cacc8)) {
            operator_delete__(puVar8);
        }
        FUN_004fc690(param_1, 1);
    }
}

// 0x4fc970 — observed shape
uint32_t FUN_004fc970(void* self) {
    uint8_t uVar1 = 0;
    int iVar2 = 0;
    char cVar3 = 0;
    uint32_t uVar4 = 0;
    char* pcVar5 = nullptr;
    uint32_t* puVar6 = nullptr;
    int in_ECX = (int)(intptr_t)self;
    int local_8 = 0;
    uint32_t local_4 = 0;
    extern void FUN_00412ec0();
    extern void FUN_004f1840();
    extern char FUN_0051bfc0(uint32_t*);
    uVar4 = 0;
    local_4 = 0;
    if (((in_ECX != 0) && (*(int**)(in_ECX + 0x10) != (int*)0x0)) && (iVar2 = **(int**)(in_ECX + 0x10), *(char*)(*(int*)(iVar2 + -4) + -1 + iVar2) != '\\')) {
        FUN_00412ec0();
        iVar2 = *(int*)0x8caccc;
        if ((*(int*)0x8caccc + -1 < *(int*)0x8caccc) && (-1 < *(int*)0x8caccc + -1)) {
            uVar1 = *(uint8_t*)((int)0x8caccc + *(int*)0x8caccc + 3);
            *(uint8_t*)((int)0x8caccc + *(int*)0x8caccc + 3) = 0;
            pcVar5 = strrchr((char*)0x8cacd0, 0x5c);
            *(uint8_t*)((int)0x8caccc + iVar2 + 3) = uVar1;
            if ((pcVar5 != (char*)0x0) && (-1 < (int)(intptr_t)(pcVar5 + -0x8cacd0))) {
                FUN_004f1840();
                FUN_00412ec0();
                puVar6 = (uint32_t*)(local_8 + -8);
                if ((puVar6 != (uint32_t*)0x0) && (puVar6 != (uint32_t*)0x8cacc8)) {
                    operator_delete__(puVar6);
                }
            }
        }
        _strupr((char*)0x8cacd0);
        cVar3 = FUN_0051bfc0(&local_4);
        uVar4 = local_4;
        if (cVar3 == '\0') {
            uVar4 = 0;
        }
    }
    return uVar4;
}

// 0x4fcaa0 — observed shape
uint32_t FUN_004fcaa0(uint32_t param_1, uint32_t param_2, uint32_t param_3) {
    int iVar1 = FUN_00533c78(8);
    if (iVar1 == 0) {
        return 0;
    }
    return FUN_004fcae0(param_1, param_2, param_3);
}

// 0x4fcae0 — observed shape
void FUN_004fcae0(void* self, int param_1, int param_2, uint32_t param_3) {
    uint32_t* puVar1 = nullptr;
    uint32_t* unaff_EDI = (uint32_t*)self;
    extern void FUN_004f4b20(int, int, int, uint32_t);
    *unaff_EDI = 0x710a38;
    unaff_EDI[1] = 0;
    puVar1 = (uint32_t*)FUN_00533c78(0x30);
    if (puVar1 == (uint32_t*)0x0) {
        unaff_EDI[1] = 0;
        return;
    }
    puVar1[7] = 0x8cacd0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    *puVar1 = 0x6f583c;
    puVar1[10] = 0;
    puVar1[0xb] = 0;
    if (param_1 != 0) {
        FUN_004f4b20(param_1, param_2 + 1, 0, param_3);
    }
    unaff_EDI[1] = (uint32_t)(intptr_t)puVar1;
}

// 0x4fcb60 — observed shape
void FUN_004fcb60(void* self, uint8_t param_1) {
    uint32_t* in_ECX = (uint32_t*)self;
    *in_ECX = 0x710a38;
    (void)(**(uint32_t(**)(void))(*(int*)in_ECX[1] + 0xc))();
    if ((uint32_t*)in_ECX[1] != (uint32_t*)0x0) {
        (void)(**(uint32_t(**)(void))in_ECX[1])(1);
        in_ECX[1] = 0;
    }
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
}
// 0x4fcbe0 — observed shape
void FUN_004fcbe0(void* self) {
    uint32_t* pvParam = nullptr;
    BOOL BVar1 = 0;
    uint32_t* unaff_ESI = (uint32_t*)self;
    uint32_t local_24 = 0;
    uint32_t local_20 = 0;
    uint32_t local_1c = 0;
    uint32_t local_18 = 0;
    uint32_t local_14 = 0;
    uint32_t local_10 = 0;
    uint32_t local_c = 0;
    uint32_t local_8 = 0;
    uint32_t local_4 = 0;
    *unaff_ESI = 0;
    unaff_ESI[1] = 0;
    unaff_ESI[2] = 0;
    unaff_ESI[3] = 0;
    unaff_ESI[4] = 0;
    unaff_ESI[5] = 0;
    unaff_ESI[6] = 0;
    *unaff_ESI = 0x1c;
    BVar1 = SystemParametersInfoA(0x36, 0x1c, unaff_ESI, 0);
    if (BVar1 != 0) {
        local_18 = 0;
        local_14 = 0;
        local_10 = 0;
        local_c = 0;
        local_8 = 0;
        local_4 = 0;
        local_1c = 0x1c;
        SystemParametersInfoA(0x37, 0x1c, &local_1c, 2);
    }
    pvParam = unaff_ESI + 7;
    *pvParam = 0;
    unaff_ESI[8] = 0;
    *pvParam = 8;
    BVar1 = SystemParametersInfoA(0x3a, 8, pvParam, 0);
    if (BVar1 != 0) {
        local_20 = 0;
        local_24 = 8;
        SystemParametersInfoA(0x3b, 8, &local_24, 2);
    }
}

// 0x4fcc90 — observed shape
uint32_t FUN_004fcc90(void* self, int in_EAX, uint32_t in_EDX, uint32_t param_1) {
    uint32_t uVar1 = 0;
    int in_ECX = (int)(intptr_t)self;
    bool bVar2 = false;
    bVar2 = *(int*)(*(int*)(in_ECX + 0x18) + 0x20) != 1;
    uVar1 = *(int*)(in_ECX + 8) + -1 + *(uint32_t*)(in_ECX + 0xc);
    if ((in_EDX != 0) || (in_EAX != 1)) {
        if (in_EAX == 0) {
            if (0 < (int)in_EDX) {
                if ((bVar2) || (in_EDX <= uVar1)) {
                    return in_EDX;
                }
                return uVar1;
            }
        } else if (in_EAX == 1) {
            if (0 < (int)in_EDX) {
                if ((!bVar2) && (uVar1 < in_EDX + param_1)) {
                    return uVar1;
                }
LAB_004fccfe:
                return in_EDX + param_1;
            }
            if (-(int)in_EDX < (int)param_1 || -(int)param_1 == (int)in_EDX) goto LAB_004fccfe;
        } else {
            if (in_EAX != 2) {
                return param_1;
            }
            if (-1 < (int)in_EDX) {
                return uVar1;
            }
            if ((bVar2) || (-(int)in_EDX < (int)uVar1 || -(int)uVar1 == (int)in_EDX)) {
                return uVar1 + in_EDX;
            }
        }
        param_1 = *(uint32_t*)(in_ECX + 0xc);
    }
    return param_1;
}

// 0x4fcd30 — observed shape
void FUN_004fcd30(void* self) {
    uint32_t uVar1 = 0;
    int in_ECX = (int)(intptr_t)self;
    extern uint32_t* thunk_FUN_00533c78(int);
    if (*(void**)(in_ECX + 0x1c) != (void*)0x0) {
        operator_delete__(*(void**)(in_ECX + 0x1c));
        *(uint32_t*)(in_ECX + 0x1c) = 0;
    }
    if (*(int*)(in_ECX + 4) != 0) {
        uVar1 = (uint32_t)(intptr_t)thunk_FUN_00533c78(*(int*)(in_ECX + 4));
        *(uint32_t*)(in_ECX + 0x1c) = uVar1;
    }
}

// 0x4fcd60 — observed shape
void FUN_004fcd60(void* self) {
    int iVar1 = 0;
    int unaff_ESI = (int)(intptr_t)self;
    DWORD local_4 = 0;
    iVar1 = *(int*)(*(int*)(unaff_ESI + 0x18) + 0x20);
    if (iVar1 != 3) {
        if (iVar1 == 1) {
            *(uint32_t*)(unaff_ESI + 0x10) = 0;
            *(uint32_t*)(unaff_ESI + 0x14) = 0;
            return;
        }
        local_4 = *(DWORD*)(unaff_ESI + 0x14);
        if (local_4 != 0) {
            WriteFile(*(HANDLE*)(*(int*)(unaff_ESI + 0x18) + 4), *(LPCVOID*)(unaff_ESI + 0x1c), local_4, &local_4, (LPOVERLAPPED)0x0);
        }
        *(uint32_t*)(unaff_ESI + 0x14) = 0;
    }
}

// 0x4fcf80 — observed shape
int FUN_004fcf80(void* self) {
    int* piVar1 = nullptr;
    DWORD DVar2 = 0;
    int lDistanceToMove = 0;
    uint32_t uVar3 = 0;
    int in_ECX = (int)(intptr_t)self;
    int iVar4 = 0;
    piVar1 = *(int**)(in_ECX + 0x18);
    DVar2 = SetFilePointer((HANDLE)piVar1[1], 0, (PLONG)0x0, 1);
    if (DVar2 == 0xffffffff) {
        DVar2 = (DWORD)(**(uint32_t(**)(void))(*piVar1 + 0x10))();
    }
    iVar4 = (DVar2 - *(int*)(in_ECX + 0x10)) + *(int*)(in_ECX + 0x14);
    lDistanceToMove = (int)FUN_004fcc90(piVar1, 0, 0, iVar4);
    if (lDistanceToMove != iVar4) {
        uVar3 = (*(uint32_t*)(in_ECX + 0x10) - DVar2) + lDistanceToMove;
        if ((-1 < (int)uVar3) && (uVar3 < *(uint32_t*)(in_ECX + 0x10))) {
            *(uint32_t*)(in_ECX + 0x14) = uVar3;
            return lDistanceToMove;
        }
        FUN_004fcd60(piVar1);
        piVar1 = *(int**)(in_ECX + 0x18);
        DVar2 = SetFilePointer((HANDLE)piVar1[1], lDistanceToMove, (PLONG)0x0, 0);
        if (DVar2 == 0xffffffff) {
            (void)(**(uint32_t(**)(void))(*piVar1 + 0x10))();
        }
    }
    return lDistanceToMove;
}

// --- helpers/globals referenced by the definitions below ---
extern void FUN_004fac10();
extern void FUN_004fd630(int param_1);
extern void FUN_004fd880(void* obj);
extern int FUN_0045a0b0();
extern int FUN_004f76e0();
extern void FUN_004f7e00(void* obj);
extern void FUN_004b9650();
extern char FUN_004fd7b0(void* obj, uint32_t param_1, uint32_t param_2);
extern char FUN_004fd4c0(uint32_t param_1, uint32_t param_2);
extern char FUN_004fd5e0(uint32_t param_1);
extern void FUN_004fd810(uint32_t param_1, uint32_t param_2);
extern uint32_t DAT_00726c28;
extern HANDLE DAT_00726c30;
extern int* DAT_008cad00;
extern int DAT_008cad04;
extern uint32_t PTR_FUN_00710a4c[];

extern uint8_t FUN_004fd180(int param_1, void* self);
extern uint8_t FUN_004fd260(int param_1, void* self);
extern void FUN_004fd340(void* self);

// 0x4fd020 — observed shape
int FUN_004fd020(int param_1, void* self, int* in_EAX, char in_BL, char in_BP) {
    HANDLE hHandle = nullptr;
    LPVOID pvVar1 = nullptr;
    int iVar2 = 0;
    uint32_t uVar3 = 0;
    int iVar4 = 0;
    uint8_t auStackY_a8[0xa0];

    FUN_004fd340(self);
    hHandle = DAT_00726c30;
    if (*(int*)(intptr_t)(*in_EAX - 4) == 0) {
        return 3;
    }
    if ((DAT_00726c28 == 0xffffffff) || (pvVar1 = TlsGetValue(DAT_00726c28), pvVar1 == (LPVOID)0x0)) {
        WaitForSingleObject(hHandle, 0xffffffff);
    } else {
        FUN_004fac10();
    }
    iVar2 = ((int (*)(void*, int, int, int))*(uint32_t*)(*(int*)(param_1 + 0x3c) + 8))((void*)(intptr_t)*in_EAX, 1, 0, 0x8000);
    if (iVar2 == 0) {
        if (DAT_008cad00 == nullptr) {
            DAT_008cad00 = (int*)FUN_00533c78(0x18);
            if (DAT_008cad00 == nullptr) {
                DAT_008cad00 = nullptr;
            } else {
                DAT_008cad00[2] = 0;
                DAT_008cad00[5] = 1;
                DAT_008cad00[3] = 0;
                DAT_008cad00[4] = 0;
                DAT_008cad00[1] = 0;
                DAT_008cad00[0] = (int)(intptr_t)&PTR_FUN_00710a4c;
            }
        }
        FUN_004fd880(auStackY_a8 + 0x9c);
        iVar2 = FUN_004fd180(param_1, self);
        if ((iVar2 == 0) && (iVar2 = FUN_004fd260(param_1, self), iVar2 == 0)) {
            uVar3 = ((uint32_t (*)(int, int))*(uint32_t*)(*(int*)(param_1 + 0x3c) + 0x1c))(0, 1);
            *(uint32_t*)(param_1 + 0x88) = uVar3;
            if (in_BP != '\0') {
                iVar4 = FUN_00533c78(0x18);
                if (iVar4 == 0) {
                    iVar4 = 0;
                } else {
                    iVar4 = FUN_0045a0b0();
                }
                *(int*)(param_1 + 0x70) = iVar4;
                if (iVar4 == 0) {
                    iVar2 = 10;
                } else {
                    FUN_004fd630(param_1);
                }
            }
            if (in_BL != '\0') {
                DAT_008cad04 = param_1;
            }
        }
    } else {
        iVar2 = 9;
    }
    ReleaseMutex(DAT_00726c30);
    return iVar2;
}

// 0x4fd180 — observed shape
uint8_t FUN_004fd180(int param_1, void* self) {
    uint8_t auStack_4[4];
    int iVar2 = 0;
    char cVar1 = '\0';

    cVar1 = ((char (*)(void))*(uint32_t*)(*(int*)self + 0x18))();
    if (cVar1 == '\0') {
        return 9;
    }
    iVar2 = ((int (*)(void*))*(uint32_t*)(*(int*)(param_1 + 0x3c) + 0x20))(auStack_4);
    if (iVar2 == 4) {
        return 2;
    }
    return 0xc;
}

// 0x4fd260 — observed shape
uint8_t FUN_004fd260(int param_1, void* self) {
    char cVar1 = '\0';
    int iVar2 = 0;
    int iVar3 = 0;
    bool bVar4 = false;
    uint32_t uVar5 = 0;
    // stack frame mirrored as bytes: ebp-0x10 (second read), ebp-0xa, ebp-0x8, ebp-0x4
    uint8_t stack[0x10];

    cVar1 = ((char (*)(void))*(uint32_t*)(*(int*)self + 0x18))();
    if (cVar1 == '\0') {
        return 9;
    }
    if (*(int*)(param_1 + 0x78) == 0) {
        return 0;
    }
    iVar2 = FUN_00533c78(0x10);
    if (iVar2 == 0) {
        iVar2 = 0;
    } else {
        iVar2 = FUN_004f76e0();
    }
    *(int*)(param_1 + 0x74) = iVar2;
    if (iVar2 == 0) {
        return 10;
    }
    bVar4 = false;
    uVar5 = 0;
    while (uVar5 < *(uint32_t*)(param_1 + 0x78)) {
        iVar2 = ((int (*)(void*, int))*(uint32_t*)(*(int*)self + 0x20))(stack + 0xc, 4);
        iVar3 = ((int (*)(void*, int))*(uint32_t*)(*(int*)self + 0x20))(stack, 4);
        bVar4 = (iVar2 != 4) || (iVar3 != 4);
        uVar5 = uVar5 + 8;
        if (bVar4) break;
        FUN_00524e90(*(uint32_t*)(stack + 8));
    }
    return (uint8_t)((-(int)bVar4) & 0xb);
}

// 0x4fd340 — observed shape
void FUN_004fd340(void* self) {
    int base = (int)(intptr_t)self;
    int* piVar1 = nullptr;
    int* piVar5 = nullptr;
    int iVar2 = 0;
    int* puVar3 = nullptr;
    uint32_t uVar4 = 0;
    bool bVar6 = false;

    *(uint32_t*)(base + 4) = 1;
    *(uint32_t*)(base + 8) = 0;
    *(uint32_t*)(base + 0xc) = 6;
    FUN_004f7e00((void*)(intptr_t)(base + 0x10));
    ((void (*)(void))*(uint32_t*)(*(int*)(base + 0x3c) + 0xc))();
    puVar3 = DAT_008cad00;
    if (DAT_008cad00 != nullptr) {
        uVar4 = 0;
        if (DAT_008cad00[2] != 0) {
            piVar1 = (int*)(intptr_t)DAT_008cad00[1];
            piVar5 = piVar1;
            do {
                if (base == *piVar5) {
                    if ((-1 < (int)uVar4) && (uVar4 < (uint32_t)DAT_008cad00[3])) {
                        iVar2 = piVar1[uVar4];
                        piVar1[uVar4] = 0;
                        if (iVar2 != 0) {
                            puVar3[4] = puVar3[4] - 1;
                        }
                        if (uVar4 == (uint32_t)(puVar3[3] - 1)) {
                            puVar3[3] = puVar3[3] - 1;
                        }
                    }
                    break;
                }
                uVar4 = uVar4 + 1;
                piVar5 = piVar5 + 1;
            } while (uVar4 < (uint32_t)DAT_008cad00[2]);
        }
        if (puVar3[4] == 0) {
            ((void (*)(int))*(uint32_t*)(intptr_t)*puVar3)(1);
            DAT_008cad00 = nullptr;
        }
    }
    {
        uint8_t* p = *(uint8_t**)(intptr_t)(base + 0x6c);
        if (*(int*)(p - 4) != 0) {
            *p = 0;
            *(uint32_t*)(p - 4) = 0;
        }
    }
    if (*(int*)(base + 0x70) != 0) {
        FUN_004b9650();
        if (*(int**)(base + 0x70) != nullptr) {
            uint32_t vtbl = *(uint32_t*)(intptr_t)*(uint32_t*)(base + 0x70);
            ((void (*)(int))*(uint32_t*)(intptr_t)vtbl)(1);
            *(uint32_t*)(base + 0x70) = 0;
        }
    }
    if (*(int*)(base + 0x74) != 0) {
        FUN_004e6420();
        if (*(int**)(base + 0x74) != nullptr) {
            uint32_t vtbl = *(uint32_t*)(intptr_t)*(uint32_t*)(base + 0x74);
            ((void (*)(int))*(uint32_t*)(intptr_t)vtbl)(1);
            *(uint32_t*)(base + 0x74) = 0;
        }
    }
    bVar6 = (base == DAT_008cad04);
    *(uint32_t*)(base + 0x78) = 0;
    *(uint32_t*)(base + 0x7c) = 0;
    *(uint32_t*)(base + 0x80) = 0;
    *(uint32_t*)(base + 0x84) = 0;
    *(uint32_t*)(base + 0x88) = 0;
    if (bVar6) {
        DAT_008cad04 = 0;
    }
    return;
}

// 0x4fd440 — observed shape
char FUN_004fd440(int param_1, uint32_t param_2, void* self) {
    int base = (int)(intptr_t)self;
    uint32_t uVar2 = (uint32_t)param_1;
    uint32_t uVar3 = 0;
    char cVar1 = '\0';
    int scratch = param_1;

    if (*(int*)(base + 0x74) != 0) {
        extern char FUN_0051bfc0(int*);
        cVar1 = FUN_0051bfc0(&scratch);
        if (cVar1 == '\0') {
            return '\0';
        }
        uVar2 = (uint32_t)scratch;
    }
    uVar3 = param_2;
    cVar1 = FUN_004fd7b0((void*)(intptr_t)(base + 0x10), uVar2, param_2);
    if (cVar1 != '\0') {
        return '\x01';
    }
    if (*(int*)(base + 0x70) == 0) {
        cVar1 = FUN_004fd4c0(uVar2, uVar3);
    } else {
        cVar1 = FUN_004fd5e0(uVar3);
        uVar3 = param_2;
    }
    if (cVar1 != '\0') {
        FUN_004fd810(uVar2, uVar3);
    }
    return cVar1;
}
