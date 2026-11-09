#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void operator_delete(void* ptr);
extern void operator_delete__(void* ptr);
extern void FUN_004f0dc0();
extern void FUN_004f32e0();
extern void FUN_004f0e40(void* a, int b, int c, int d);
extern void FUN_004fa4d0();

extern void* PTR_FUN_007108ac;
extern void* PTR_FUN_007108b0;
extern void* PTR_FUN_00710884;
extern void* PTR_FUN_006f5864;
extern void* PTR_DAT_007108b4;
extern int DAT_008cad08;
extern char DAT_008cacd0[];
extern char DAT_008cacc8[];

// 0x4fa470 — observed shape
void FUN_004fa470(void* self, uint8_t param_1) {
    uint32_t* obj = static_cast<uint32_t*>(self);
    *obj = reinterpret_cast<uint32_t>(&PTR_FUN_007108ac);
    operator_delete__(reinterpret_cast<void*>(obj[1]));
    if ((param_1 & 1) != 0) {
        operator_delete(obj);
    }
}

// 0x4fa4a0 — observed shape
void FUN_004fa4a0(void* self, uint8_t param_1) {
    uint32_t* obj = static_cast<uint32_t*>(self);
    *obj = reinterpret_cast<uint32_t>(&PTR_FUN_007108b0);
    operator_delete__(reinterpret_cast<void*>(obj[1]));
    if ((param_1 & 1) != 0) {
        operator_delete(obj);
    }
}

// 0x4fa4d0 — observed shape
void FUN_004fa4d0(void* self) {
    uint32_t* obj = static_cast<uint32_t*>(self);
    *obj = reinterpret_cast<uint32_t>(&PTR_FUN_00710884);
    FUN_004f0dc0();
    DeleteFileA(reinterpret_cast<LPCSTR>(obj[10]));
    DAT_008cad08 = DAT_008cad08 + -1;
    uint32_t* puVar1 = reinterpret_cast<uint32_t*>(obj[10] + -8);
    if ((puVar1 != nullptr) && (puVar1 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
        operator_delete__(puVar1);
    }
    obj[10] = reinterpret_cast<uint32_t>(&DAT_008cacd0);
    *obj = reinterpret_cast<uint32_t>(&PTR_FUN_006f5864);
    FUN_004f0dc0();
    puVar1 = reinterpret_cast<uint32_t*>(obj[7] + -8);
    if ((puVar1 != nullptr) && (puVar1 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
        operator_delete__(puVar1);
    }
    obj[7] = reinterpret_cast<uint32_t>(&DAT_008cacd0);
}

// 0x4fa550 — observed shape
void FUN_004fa550(void* self, uint8_t param_1) {
    FUN_004fa4d0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x4fa570 — observed shape
void FUN_004fa570(void* self) {
    uint32_t* unaff_ESI = static_cast<uint32_t*>(self);
    unaff_ESI[7] = reinterpret_cast<uint32_t>(&DAT_008cacd0);
    unaff_ESI[1] = 0;
    unaff_ESI[2] = 0;
    unaff_ESI[3] = 0;
    unaff_ESI[4] = 0;
    unaff_ESI[5] = 0;
    unaff_ESI[6] = 0;
    *unaff_ESI = reinterpret_cast<uint32_t>(&PTR_FUN_00710884);
    int* piVar1 = reinterpret_cast<int*>(unaff_ESI + 10);
    *piVar1 = reinterpret_cast<int>(&DAT_008cacd0);
    if (*reinterpret_cast<int*>(*reinterpret_cast<char**>(piVar1) + -8) < 0x104) {
        uint32_t uVar3 = *reinterpret_cast<uint32_t*>(*reinterpret_cast<char**>(piVar1) + -4);
        FUN_004f32e0();
        *reinterpret_cast<uint32_t*>(*reinterpret_cast<char**>(piVar1) + -4) = 0x104;
        *reinterpret_cast<uint32_t*>(*reinterpret_cast<char**>(piVar1) + -4) = uVar3;
    }
    GetTempFileNameA(".", reinterpret_cast<LPCSTR>(&PTR_DAT_007108b4), 0, reinterpret_cast<LPSTR>(*piVar1));
    char* pcVar4 = reinterpret_cast<char*>(*piVar1);
    char* pcVar5 = pcVar4;
    char cVar2;
    do {
        cVar2 = *pcVar5;
        pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    *reinterpret_cast<int*>(pcVar4 + -4) = static_cast<int>(pcVar5 - (pcVar4 + 1));
    FUN_004f0e40(reinterpret_cast<void*>(*piVar1), 2, 0, 0x8000);
    DAT_008cad08 = DAT_008cad08 + 1;
}

// 0x4fa610 — observed shape
void FUN_004fa610(void* self) {
    int* unaff_ESI = static_cast<int*>(self);
    int iVar2 = unaff_ESI[4];
    while (iVar2 != 0) {
        if (unaff_ESI[4] != 0) {
            iVar2 = unaff_ESI[4] + -1;
            unaff_ESI[4] = iVar2;
            int* piVar1 = *reinterpret_cast<int**>(unaff_ESI[2] + iVar2 * 4);
            *reinterpret_cast<int*>(unaff_ESI[2] + iVar2 * 4) = 0;
            if (piVar1 != nullptr) {
                unaff_ESI[5] = unaff_ESI[5] + -1;
                uint32_t* puVar3 = reinterpret_cast<uint32_t*>(piVar1[1] + -8);
                if ((puVar3 != nullptr) && (puVar3 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
                    operator_delete__(puVar3);
                }
                piVar1[1] = reinterpret_cast<int>(&DAT_008cacd0);
                puVar3 = reinterpret_cast<uint32_t*>(*piVar1 + -8);
                if ((puVar3 != nullptr) && (puVar3 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
                    operator_delete__(puVar3);
                }
                *piVar1 = reinterpret_cast<int>(&DAT_008cacd0);
                operator_delete(piVar1);
            }
        }
        iVar2 = unaff_ESI[4];
    }
    unaff_ESI[1] = reinterpret_cast<int>(&PTR_FUN_007108b0);
    operator_delete__(reinterpret_cast<void*>(unaff_ESI[2]));
    uint32_t* puVar3 = reinterpret_cast<uint32_t*>(*unaff_ESI + -8);
    if ((puVar3 != nullptr) && (puVar3 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
        operator_delete__(puVar3);
    }
    *unaff_ESI = reinterpret_cast<int>(&DAT_008cacd0);
}

// 0x4fa6c0 — observed shape
uint32_t FUN_004fa6c0(int param_1, int* param_2, char param_3, void* self_unused) {
    extern uint32_t FUN_004b9650();
    extern uint32_t FUN_004f85e0(int* a, void** b);
    extern uint32_t FUN_004f3ee0();
    extern void FUN_004f2600(void* a, void* b);
    extern void FUN_00412f90();
    extern void FUN_004f3350();
    extern void FUN_004f84d0(void** a);
    extern void FUN_004f2aa0(void** a);
    extern void FUN_004b0b90(int a);
    extern void FUN_004b0df0(void** a);
    extern void* DAT_00710530;
    int* piVar1 = param_2;
    void* param_2_str = reinterpret_cast<void*>(&DAT_008cacd0);
    uint32_t local_8 = 0;
    FUN_004b9650();
    char cVar3 = (*reinterpret_cast<char(**)(int*)>(*piVar1 + 0x18))();
    uint32_t uVar7 = 0;
    if (cVar3 != '\0') {
        uint32_t uVar4 = (*reinterpret_cast<uint32_t(**)(int*,int,int)>(*piVar1 + 0x1c))(0, 1);
        uint32_t uVar5 = (*reinterpret_cast<uint32_t(**)(int*)>(*piVar1 + 0x10))();
        if (uVar4 < uVar5) {
            do {
                if (piVar1[0xc] == 1) {
                    wchar_t* pwStack_10 = reinterpret_cast<wchar_t*>(&DAT_008cacd0);
                    FUN_004f85e0(piVar1, reinterpret_cast<void**>(&pwStack_10));
                    wchar_t* pwVar9 = pwStack_10;
                    if ((pwStack_10 != nullptr) && (static_cast<int>(wcslen(pwStack_10)) > -1)) {
                        FUN_004f3ee0();
                        void* puStack_4 = &DAT_008cacd0;
                        void* puStack_c = &DAT_008cacd0;
                        FUN_004f2600(&DAT_00710530, puStack_c);
                        void* _Src = puStack_4;
                        size_t sVar6 = *reinterpret_cast<size_t*>(static_cast<char*>(puStack_4) + -4);
                        if ((-1 < static_cast<int>(sVar6)) && (static_cast<char*>(puStack_4) != static_cast<char*>(param_2_str))) {
                            if (sVar6 == 0) {
                                FUN_00412f90();
                            } else {
                                FUN_004f3350();
                                char* puVar2 = static_cast<char*>(param_2_str);
                                memmove(param_2_str, _Src, sVar6);
                                puVar2[*reinterpret_cast<int*>(puVar2 + -4)] = 0;
                                pwVar9 = pwStack_10;
                            }
                        }
                        uint32_t* puVar8 = reinterpret_cast<uint32_t*>(static_cast<char*>(_Src) + -8);
                        if ((puVar8 != nullptr) && (puVar8 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
                            operator_delete__(puVar8);
                        }
                        puVar8 = reinterpret_cast<uint32_t*>(static_cast<char*>(puStack_c) + -8);
                        if ((puVar8 != nullptr) && (puVar8 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
                            operator_delete__(puVar8);
                        }
                        puStack_c = &DAT_008cacd0;
                    }
                    pwVar9 = pwVar9 + -4;
                    if ((pwVar9 != nullptr) && (pwVar9 != reinterpret_cast<wchar_t*>(&DAT_008cacc8))) {
                        operator_delete__(pwVar9);
                    }
                } else {
                    FUN_004f84d0(&param_2_str);
                }
                if (param_3 != '\0') {
                    FUN_004f2aa0(&param_2_str);
                }
                if (local_8 < *reinterpret_cast<uint32_t*>(static_cast<char*>(param_2_str) + -4)) {
                    local_8 = *reinterpret_cast<uint32_t*>(static_cast<char*>(param_2_str) + -4);
                }
                if (*reinterpret_cast<uint32_t*>(param_1 + 8) <= *reinterpret_cast<uint32_t*>(param_1 + 0xc)) {
                    FUN_004b0b90(param_1);
                }
                FUN_004b0df0(&param_2_str);
                uVar7 = (*reinterpret_cast<uint32_t(**)(int*,int,int)>(*piVar1 + 0x1c))(0, 1);
                uVar4 = (*reinterpret_cast<uint32_t(**)(int*)>(*piVar1 + 0x10))();
            } while (uVar7 < uVar4);
            uVar7 = local_8;
        }
    }
    uint32_t* puVar8 = reinterpret_cast<uint32_t*>(static_cast<char*>(param_2_str) + -8);
    if ((puVar8 != nullptr) && (puVar8 != reinterpret_cast<uint32_t*>(&DAT_008cacc8))) {
        operator_delete__(puVar8);
    }
    return uVar7;
}

// 0x4fa8b0 — observed shape
void FUN_004fa8b0(void* self, uint8_t param_1) {
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    *in_ECX = reinterpret_cast<uint32_t>(&PTR_FUN_00710994);
    in_ECX[2] = reinterpret_cast<uint32_t>(&PTR_FUN_00710aac);
    CloseHandle(reinterpret_cast<HANDLE>(in_ECX[3]));
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
}

extern void* PTR_FUN_00710994;
extern void* PTR_FUN_00710aac;
extern void* PTR_FUN_007109ac;
extern void* PTR_FUN_007109b0;
extern void* PTR_FUN_007109b4;
extern void* DAT_008cacf4;
extern uint32_t DAT_00726c28;
extern uint8_t DAT_007149ac[];
extern void LAB_004fac80();
extern void FUN_004fab70(void* obj, uint32_t priority);
extern void FUN_004faab0(void* self);
extern void FUN_004fae60(void* self);
extern void _CxxThrowException(void* pExceptionObject, void* pThrowInfo);
extern uintptr_t _beginthreadex(void* security, uint32_t stack_size, void* start_address,
                                void* arglist, uint32_t initflag, uint32_t* thread_id);
extern void* thunk_FUN_00533c78(uint32_t size);

// 0x4fa8e0 — observed shape
void FUN_004fa8e0(void* self, uint32_t param_1, uint32_t param_2) {
    (void)param_1;
    uint32_t* unaff_ESI = static_cast<uint32_t*>(self);
    *unaff_ESI = reinterpret_cast<uint32_t>(&PTR_FUN_00710994);
    unaff_ESI[2] = reinterpret_cast<uint32_t>(&PTR_FUN_00710aac);
    HANDLE pvVar1 = CreateSemaphoreA(nullptr, 0, 1000000, nullptr);
    unaff_ESI[3] = reinterpret_cast<uint32_t>(pvVar1);
    unaff_ESI[5] = 1;
    unaff_ESI[6] = 0;
    unaff_ESI[0xc] = 0;
    *reinterpret_cast<uint8_t*>(unaff_ESI + 7) = 0;
    *reinterpret_cast<uint8_t*>(unaff_ESI + 1) = 0;
    *reinterpret_cast<uint8_t*>(unaff_ESI + 9) =
        static_cast<uint8_t>((*reinterpret_cast<uint8_t*>(unaff_ESI + 9) & 0xfe) | 2);
    unaff_ESI[0xb] = 0;
    unaff_ESI[8] = 0;
    pvVar1 = CreateEventA(nullptr, 1, 0, nullptr);
    unaff_ESI[8] = reinterpret_cast<uint32_t>(pvVar1);
    if (pvVar1 == nullptr) {
        param_2 = 0xffffffff;
        _CxxThrowException(&param_2, &DAT_007149ac);
    }
    uintptr_t uVar2 = _beginthreadex(nullptr, param_2, reinterpret_cast<void*>(&LAB_004fac80),
                                     unaff_ESI, 4, reinterpret_cast<uint32_t*>(unaff_ESI + 0xc));
    unaff_ESI[0xb] = static_cast<uint32_t>(uVar2);
    if (uVar2 == 0) {
        CloseHandle(reinterpret_cast<HANDLE>(unaff_ESI[8]));
        unaff_ESI[8] = 0;
        param_2 = 0xffffffff;
        _CxxThrowException(&param_2, &DAT_007149ac);
    }
    if (DAT_008cacf4 == nullptr) {
        if (DAT_00726c28 != 0xffffffff) {
            TlsSetValue(DAT_00726c28, nullptr);
        }
        DAT_008cacf4 = unaff_ESI;
    }
    LPVOID pvVar3 = (DAT_00726c28 == 0xffffffff) ? nullptr : TlsGetValue(DAT_00726c28);
    unaff_ESI[4] = reinterpret_cast<uint32_t>(pvVar3);
    if (pvVar3 == nullptr) {
        unaff_ESI[4] = reinterpret_cast<uint32_t>(unaff_ESI);
    }
    unaff_ESI[5] = 0;
    FUN_004fab70(unaff_ESI, unaff_ESI[5]);
}

// 0x4fa9f0 — observed shape
void FUN_004fa9f0(void* self) {
    uint8_t* base = static_cast<uint8_t*>(self);
    if ((*reinterpret_cast<int*>(base + 0x30) != 0) &&
        (*reinterpret_cast<DWORD*>(base + 0x30) != GetCurrentThreadId())) {
        *reinterpret_cast<uint8_t*>(base + 0x1c) = 1;
        if ((*reinterpret_cast<DWORD*>(base + 0x30) == GetCurrentThreadId()) &&
            (*reinterpret_cast<DWORD*>(base + 0x30) == GetCurrentThreadId())) {
            *reinterpret_cast<uint32_t*>(base + 0x14) = 3;
            FUN_004faab0(self);
        }
        if ((*reinterpret_cast<int*>(base + 0x30) != 0) &&
            ((*reinterpret_cast<uint8_t*>(base + 0x24) & 1) != 0)) {
            WaitForSingleObject(*reinterpret_cast<HANDLE*>(base + 0x2c), 0xffffffff);
        }
        if (*reinterpret_cast<int**>(base + 0x10) != nullptr) {
            int* pObj = *reinterpret_cast<int**>(base + 0x10);
            (*reinterpret_cast<void (**)(int*)>(*pObj + 0x14))(pObj);
        }
        CloseHandle(*reinterpret_cast<HANDLE*>(base + 0x2c));
        *reinterpret_cast<uint32_t*>(base + 0x2c) = 0;
        CloseHandle(*reinterpret_cast<HANDLE*>(base + 0x20));
        *reinterpret_cast<uint32_t*>(base + 0x20) = 0;
        *reinterpret_cast<uint32_t*>(base + 0x30) = 0;
        if (DAT_00726c28 != 0xffffffff) {
            TlsSetValue(DAT_00726c28, nullptr);
        }
    }
}

// 0x4faa90 — observed shape
void FUN_004faa90(void* self) {
    uint8_t* base = static_cast<uint8_t*>(self);
    if (*reinterpret_cast<DWORD*>(base + 0x30) == GetCurrentThreadId()) {
        *reinterpret_cast<uint32_t*>(base + 0x14) = 3;
        FUN_004faab0(self);
    }
}

// 0x4faab0 — observed shape
void FUN_004faab0(void* self) {
    int* unaff_ESI = static_cast<int*>(self);
    if (static_cast<char>(unaff_ESI[1]) == '\0') {
        *reinterpret_cast<uint8_t*>(unaff_ESI + 1) = 1;
        unaff_ESI[5] = 3;
        if (unaff_ESI[4] != 0) {
            int pInner = unaff_ESI[4];
            (*reinterpret_cast<void (**)(int)>(*reinterpret_cast<int*>(pInner) + 0x14))(pInner);
        }
        (*reinterpret_cast<void (**)(int*)>(*unaff_ESI + 8))(unaff_ESI);
        *reinterpret_cast<uint8_t*>(unaff_ESI + 9) =
            static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(unaff_ESI + 9) & 0xfe);
        int* piVar1 = (DAT_00726c28 == 0xffffffff)
                          ? nullptr
                          : static_cast<int*>(TlsGetValue(DAT_00726c28));
        if (piVar1 == unaff_ESI) {
            ReleaseSemaphore(reinterpret_cast<HANDLE>(unaff_ESI[3]), 1, nullptr);
            SetEvent(reinterpret_cast<HANDLE>(unaff_ESI[8]));
            ExitThread(0);
        }
    }
}

// 0x4fab20 — observed shape
void FUN_004fab20(void) {
    if (DAT_00726c28 != 0xffffffff) {
        LPVOID pvVar1 = TlsGetValue(DAT_00726c28);
        if ((pvVar1 != nullptr) && (*reinterpret_cast<int*>(static_cast<uint8_t*>(pvVar1) + 0x14) != 0) &&
            (*reinterpret_cast<int*>(static_cast<uint8_t*>(pvVar1) + 0x14) != 3)) {
            DWORD DVar2 = WaitForSingleObject(*reinterpret_cast<HANDLE*>(static_cast<uint8_t*>(pvVar1) + 0x20), 1);
            if (DVar2 == 0) {
                FUN_004faa90(pvVar1);
            }
            return;
        }
    }
    SleepEx(1, 0);
}

// 0x4fab70 — observed shape
void FUN_004fab70(void* obj, uint32_t priority) {
    switch (priority) {
    default:
        SetThreadPriority(*reinterpret_cast<HANDLE*>(static_cast<uint8_t*>(obj) + 0x2c), 0);
        return;
    case 1:
        SetThreadPriority(*reinterpret_cast<HANDLE*>(static_cast<uint8_t*>(obj) + 0x2c), 1);
        return;
    case 2:
        SetThreadPriority(*reinterpret_cast<HANDLE*>(static_cast<uint8_t*>(obj) + 0x2c), 2);
        return;
    case 0xfffffffe:
        SetThreadPriority(*reinterpret_cast<HANDLE*>(static_cast<uint8_t*>(obj) + 0x2c), -2);
        return;
    case 0xffffffff:
        SetThreadPriority(*reinterpret_cast<HANDLE*>(static_cast<uint8_t*>(obj) + 0x2c), -1);
        return;
    }
}

// 0x4fac10 — observed shape
uint32_t FUN_004fac10(void* self, HANDLE hWait, uint32_t timeout) {
    uint8_t* base = static_cast<uint8_t*>(self);
    HANDLE local_8[2];
    local_8[0] = *reinterpret_cast<HANDLE*>(base + 0x20);
    if ((*reinterpret_cast<int*>(base + 0x14) == 0) || (*reinterpret_cast<int*>(base + 0x14) == 3)) {
        return WaitForSingleObject(hWait, timeout);
    }
    DWORD DVar1 = WaitForMultipleObjects(2, local_8, 0, timeout);
    if (DVar1 == 0) {
        if (*reinterpret_cast<DWORD*>(base + 0x30) == GetCurrentThreadId()) {
            *reinterpret_cast<uint32_t*>(base + 0x14) = 3;
            FUN_004faab0(self);
        }
    } else if (DVar1 != 1) {
        return DVar1;
    }
    return 0;
}

// 0x4fad30 — observed shape
void FUN_004fad30(void* self, uint8_t param_1) {
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    *in_ECX = reinterpret_cast<uint32_t>(&PTR_FUN_007109ac);
    if (in_ECX[1] != 0xffffffff) {
        TlsFree(in_ECX[1]);
    }
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
}

// 0x4fad60 — observed shape
void FUN_004fad60(void* self, uint8_t param_1) {
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    *in_ECX = reinterpret_cast<uint32_t>(&PTR_FUN_007109b0);
    CloseHandle(reinterpret_cast<HANDLE>(in_ECX[1]));
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
}

// 0x4fad90 — observed shape
void FUN_004fad90(void* self) {
    uint8_t* base = static_cast<uint8_t*>(self);
    HANDLE hHandle = *reinterpret_cast<HANDLE*>(base + 4);
    if (DAT_00726c28 != 0xffffffff) {
        LPVOID pvVar1 = TlsGetValue(DAT_00726c28);
        if (pvVar1 != nullptr) {
            FUN_004fac10(self, hHandle, 0xffffffff);
            return;
        }
    }
    WaitForSingleObject(hHandle, 0xffffffff);
}

// 0x4fadc0 — observed shape
void FUN_004fadc0(void* self, int param_1, uint8_t param_2, int param_3) {
    int* unaff_ESI = static_cast<int*>(self);
    unaff_ESI[3] = param_1;
    *unaff_ESI = reinterpret_cast<int>(&PTR_FUN_007109b4);
    *reinterpret_cast<uint8_t*>(unaff_ESI + 1) = param_2;
    unaff_ESI[4] = param_3;
    void* uVar1 = thunk_FUN_00533c78(static_cast<uint32_t>(param_1) << 2);
    unaff_ESI[2] = reinterpret_cast<int>(uVar1);
    int iVar4 = 0;
    if (0 < unaff_ESI[3]) {
        do {
            int iVar3 = unaff_ESI[4];
            int* piVar2 = static_cast<int*>(thunk_FUN_00533c78(static_cast<uint32_t>(iVar3 * 4 + 4)));
            if (piVar2 == nullptr) {
                piVar2 = nullptr;
            } else {
                *piVar2 = iVar3;
                piVar2 = piVar2 + 1;
                if (-1 < iVar3 + -1) {
                    int* piVar5 = piVar2;
                    for (; iVar3 != 0; iVar3 = iVar3 + -1) {
                        *piVar5 = reinterpret_cast<int>(&DAT_008cacd0);
                        piVar5 = piVar5 + 1;
                    }
                }
            }
            *reinterpret_cast<int**>(unaff_ESI[2] + iVar4 * 4) = piVar2;
            iVar4 = iVar4 + 1;
        } while (iVar4 < unaff_ESI[3]);
    }
}

// 0x4fae40 — observed shape
void FUN_004fae40(void* self, uint8_t param_1) {
    FUN_004fae60(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}
