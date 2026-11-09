#include <cstdint>
#include <cstddef>
#include <windows.h>

// 0x60b97b — observed shape
void FUN_0060b97b(void* self)
{
    uint32_t* v = (uint32_t*)self;
    v[0] = 0xffffffff;
    v[1] = 0xffffffff;
    v[2] = 0;
    v[3] = 0;
}

// 0x60b98d — observed shape
extern void* FUN_00533c78(int);
extern void operator_delete(void*);

// NEEDS_MANUAL: preserves error strings as analyzed; helper names inferred from corpus
uint32_t FUN_0060b98d(void* self, LPCWSTR param_1, int param_2) {
    HANDLE pvVar1;
    DWORD DVar2;
    LPVOID pvVar3;
    _OSVERSIONINFOA local_9c{};
    LPCWSTR local_8 = nullptr;

    if (param_1 == nullptr)
        return 0x8876086c;

    if (param_2 == 0) {
        pvVar1 = CreateFileA((LPCSTR)param_1, 0x80000000, 1, (LPSECURITY_ATTRIBUTES)0x0, 3, 0x10000000, (HANDLE)0x0);
    } else {
        local_9c.dwOSVersionInfoSize = 0x94;
        GetVersionExA(&local_9c);
        if (local_9c.dwPlatformId != 2) {
            int cbMultiByte = WideCharToMultiByte(0xfde9, 0, param_1, -1, (LPSTR)0x0, 0, (LPCSTR)0x0, (LPBOOL)0x0);
            local_8 = (LPCWSTR)FUN_00533c78(cbMultiByte);
            if (local_8 == nullptr)
                return 0x8007000e;
            WideCharToMultiByte(0xfde9, 0, param_1, -1, (LPSTR)local_8, cbMultiByte, (LPCSTR)0x0, (LPBOOL)0x0);
            param_1 = local_8;
            param_2 = 0;
        }
        if (param_2 == 0)
            pvVar1 = CreateFileA((LPCSTR)param_1, 0x80000000, 1, (LPSECURITY_ATTRIBUTES)0x0, 3, 0x10000000, (HANDLE)0x0);
        else
            pvVar1 = CreateFileW(param_1, 0x80000000, 1, (LPSECURITY_ATTRIBUTES)0x0, 3, 0x10000000, (HANDLE)0x0);
    }
    ((HANDLE*)self)[0] = pvVar1;
    operator_delete((void*)local_8);
    if (((HANDLE*)self)[0] != (HANDLE)0xffffffff) {
        HANDLE h = CreateFileMappingA((HANDLE)((HANDLE*)self)[0], (LPSECURITY_ATTRIBUTES)0x0, 2, 0, 0, (LPCSTR)0x0);
        ((HANDLE*)self)[1] = h;
        if (h != (HANDLE)0xffffffff) {
            DWORD sz = GetFileSize((HANDLE)((HANDLE*)self)[0], (LPDWORD)0x0);
            ((DWORD*)self)[3] = sz;
            if (sz != 0xffffffff) {
                if (sz == 0) {
                    ((void**)self)[2] = nullptr;
                } else {
                    LPVOID view = MapViewOfFile((HANDLE)((HANDLE*)self)[1], 4, 0, 0, 0);
                    ((LPVOID*)self)[2] = view;
                    if (view == nullptr) goto LAB_0060bab2;
                }
                return 0;
            }
        }
    }
LAB_0060bab2:
    GetLastError();
    return 0x88760b59;
}

// 0x60bacb — observed shape
uint32_t FUN_0060bacb(void* self)
{
    uint32_t* v = (uint32_t*)self;
    if (v[2] != 0) {
        UnmapViewOfFile((LPCVOID)(uintptr_t)v[2]);
        v[2] = 0;
        v[3] = 0;
    }
    if (v[1] != 0xffffffff) {
        CloseHandle((HANDLE)(uintptr_t)v[1]);
        v[1] = 0xffffffff;
    }
    if (v[0] != 0xffffffff) {
        CloseHandle((HANDLE)(uintptr_t)v[0]);
        v[0] = 0xffffffff;
    }
    return 0;
}

// 0x60bb0e — observed shape
extern uint32_t FUN_0060bacb(void* self);

void FUN_0060bb0e(void* self)
{
    int* v = (int*)self;
    if (*v == -1) return;
    FUN_0060bacb(self);
}

// 0x60bb19 — observed shape
void FUN_0060bb19(void* self)
{
    uint32_t* v = (uint32_t*)self;
    if (*v != 0) {
        DeleteObject((HGDIOBJ)(uintptr_t)*v);
    }
}
// 0x60bb27 — observed shape
extern CRITICAL_SECTION DAT_0072a640;
extern int32_t DAT_0072a658;
extern int32_t DAT_0072a65c;

void FUN_0060bb27(void)
{
    LONG LVar1;
    while (true) {
        LVar1 = InterlockedCompareExchange((LONG*)&DAT_0072a65c, 1, 0);
        if (LVar1 != 1) break;
        Sleep(1);
    }
    if (DAT_0072a658 == 0) {
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_0072a640);
    }
    DAT_0072a658 = DAT_0072a658 + 1;
    InterlockedExchange((LONG*)&DAT_0072a65c, 0);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0072a640);
}

// 0x60bb7c — observed shape
extern CRITICAL_SECTION DAT_0072a640;
extern int32_t DAT_0072a658;
extern int32_t DAT_0072a65c;

void FUN_0060bb7c(void)
{
    LONG LVar1;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0072a640);
    while (true) {
        LVar1 = InterlockedCompareExchange((LONG*)&DAT_0072a65c, 1, 0);
        if (LVar1 != 1) break;
        Sleep(1);
    }
    DAT_0072a658 = DAT_0072a658 + -1;
    if (DAT_0072a658 == 0) {
        DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_0072a640);
    }
    InterlockedExchange((LONG*)&DAT_0072a65c, 0);
}

// 0x60bbcd — observed shape
void FUN_0060bbcd(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3)
{
    uint32_t* v = (uint32_t*)self;
    v[3] = 0;
    v[4] = 0;
    v[0] = param_1;
    v[1] = param_2;
    v[2] = param_3;
}

// 0x60bbf1 — observed shape
void FUN_0060bbf1(void* self, uint32_t param_1, uint32_t param_2)
{
    uint32_t* v = (uint32_t*)self;
    v[2] = 0;
    v[3] = 0;
    v[0] = param_1;
    v[1] = param_2;
}

// 0x60bc0f — observed shape
extern void FUN_0060bc0f(void* self);
extern void operator_delete(void*);

void FUN_0060bc0f(void* self)
{
    uint8_t* base = (uint8_t*)self;
    void* pvVar1 = *(void**)(base + 0xc);
    if (pvVar1 != nullptr) {
        FUN_0060bc0f(self);
        operator_delete(pvVar1);
    }
}
// 0x60bc29 — observed shape
extern void FUN_0060bc0f(void* self);
extern void operator_delete(void*);

void FUN_0060bc29(void* self, uint8_t param_1)
{
    FUN_0060bc0f(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x60bc4a — observed shape
extern void FUN_0060f79a(void* self);
extern void FUN_0060b97b(void* self);
extern void FUN_005fbd85(void* self);

void FUN_0060bc4a(void* self)
{
    uint8_t* b = (uint8_t*)self;
    FUN_0060f79a(self);
    FUN_0060b97b(self);
    FUN_005fbd85(self);
    *(uint32_t*)(b + 0x38) = 0;
    *(uint32_t*)(b + 0x58) = 0;
    *(uint32_t*)(b + 100) = 0;
    *(uint32_t*)(b + 0x68) = 0;
    *(uint32_t*)(b + 0x5c) = 0;
    *(uint32_t*)(b + 0x60) = 0;
    *(uint32_t*)(b + 0x6c) = 0;
}

// 0x60bc7f — observed shape
extern void FUN_0060bc29(void* self, uint8_t param_1);
extern void operator_delete(void*);
extern void FUN_0060bb19(void* self);
extern void FUN_0060bb0e(void* self);
extern void FUN_006338c7(void* self);

void FUN_0060bc7f(void* self)
{
    uint8_t* b = (uint8_t*)self;
    if (*(int32_t*)(b + 0x38) != 0) {
        FUN_0060bc29(self, 1);
    }
    void* pvVar1 = *(void**)(b + 0x6c);
    if (pvVar1 != nullptr) {
        FUN_0060bc7f(self);
        operator_delete(pvVar1);
    }
    if ((*(int32_t*)(b + 0x58) != 0) && (*(int32_t*)(b + 100) != 0)) {
        int32_t* p58 = *(int32_t**)(b + 0x58);
        using Fn = void(__stdcall *)(int32_t*, int32_t);
        Fn fn = *(Fn*)(*(intptr_t**)p58 + 4);
        fn(p58, *(int32_t*)(b + 100));
    }
    FUN_0060bb19(self);
    FUN_0060bb0e(self);
    FUN_006338c7(self);
}

// 0x60bcd8 — observed shape
extern void FUN_0060bc7f(void* self);
extern void operator_delete(void*);

void FUN_0060bcd8(void* self, uint8_t param_1)
{
    FUN_0060bc7f(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x60bcf9 — observed shape
extern void* FUN_0065aaac(uint32_t, uint32_t);
extern uint32_t FUN_0060b98d(void* self, LPCWSTR param_1, int param_2);
extern void FUN_0060fcd3(uint32_t, uint32_t, uint32_t, const char*, const void*);
extern uint32_t FUN_0060f7b4(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);

// NEEDS_MANUAL: string path arithmetic preserved; exact wide-char length derivation subtle
uint32_t FUN_0060bcf9(void* self, WCHAR* param_1, LPSTR param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7, uint32_t param_8)
{
    uint8_t* b = (uint8_t*)self;
    WCHAR local_108[130];
    int32_t iVar5 = (int32_t)param_6;
    *(uint32_t*)(b + 0x58) = param_6;
    if (param_2 != nullptr) {
        WideCharToMultiByte(0xfde9, 0, param_1, -1, (LPSTR)local_108, 0x104, (LPCSTR)0x0, (LPBOOL)0x0);
        param_1 = local_108;
    }
    if (iVar5 == 0) {
        DWORD nBufferLength = GetFullPathNameA((LPCSTR)param_1, 0, (LPSTR)0x0, (LPSTR*)0x0);
        param_6 = nBufferLength + 1;
        iVar5 = (int32_t)(intptr_t)FUN_0065aaac(param_6, 1);
        *(int32_t*)(b + 0x60) = iVar5;
        if (iVar5 != 0) {
            iVar5 = (int32_t)(intptr_t)FUN_0065aaac(param_6, 1);
            *(int32_t*)(b + 0x5c) = iVar5;
            if (iVar5 != 0) {
                GetFullPathNameA((LPCSTR)param_1, nBufferLength, *(LPSTR*)(b + 0x60), &param_2);
                *(uint8_t*)(nBufferLength + *(int32_t*)(b + 0x60)) = 0;
                uint32_t* puVar4 = *(uint32_t**)(b + 0x60);
                uint32_t* puVar7 = *(uint32_t**)(b + 0x5c);
                for (uint32_t uVar6 = param_6 >> 2; uVar6 != 0; uVar6--) {
                    *puVar7++ = *puVar4++;
                }
                for (uint32_t uVar6 = param_6 & 3; uVar6 != 0; uVar6--) {
                    *(uint8_t*)puVar7 = *(uint8_t*)puVar4;
                    puVar4 = (uint32_t*)((uint8_t*)puVar4 + 1);
                    puVar7 = (uint32_t*)((uint8_t*)puVar7 + 1);
                }
                if (param_2 != nullptr) *param_2 = '\0';
                uint32_t uVar6 = FUN_0060b98d(*(uint8_t**)(b + 0x5c), 0, 0);
                if ((int32_t)uVar6 < 0) {
                    FUN_0060fcd3(param_5, param_4, 0x5e3, "failed to open source file: \'%s\'", param_1);
                    return uVar6;
                }
                *(uint32_t*)(b + 100) = *(uint32_t*)(b + 0x44);
                *(uint32_t*)(b + 0x68) = *(uint32_t*)(b + 0x48);
                goto LAB_0060be87;
            }
        }
    } else {
        WCHAR* pWVar3 = param_1;
        WCHAR WVar2;
        do {
            WVar2 = *pWVar3;
            pWVar3 = (WCHAR*)((uint8_t*)pWVar3 + 1);
        } while ((char)WVar2 != '\0');
        char* pcVar1 = (char*)((uint8_t*)pWVar3 + (1 - ((uint8_t*)param_1 + 1)));
        uint32_t* puVar4 = (uint32_t*)FUN_0065aaac((uint32_t)(uintptr_t)pcVar1, 1);
        *(uint32_t**)(b + 0x5c) = puVar4;
        if (puVar4 != nullptr) {
            pWVar3 = param_1;
            for (uint32_t uVar6 = (uint32_t)(uintptr_t)pcVar1 >> 2; uVar6 != 0; uVar6--) {
                *puVar4 = *(uint32_t*)pWVar3;
                pWVar3 += 2;
                puVar4++;
            }
            for (uint32_t uVar6 = (uint32_t)(uintptr_t)pcVar1 & 3; uVar6 != 0; uVar6--) {
                *(char*)puVar4 = (char)*pWVar3;
                pWVar3 = (WCHAR*)((uint8_t*)pWVar3 + 1);
                puVar4 = (uint32_t*)((uint8_t*)puVar4 + 1);
            }
            {
                uint32_t* p58 = *(uint32_t**)(b + 0x58);
                using Fn = uint32_t(__stdcall*)(uint32_t*, uint32_t, uint32_t*, uint32_t, uint8_t*, uint8_t*);
                Fn fn = *(Fn*)(*(uint32_t**)p58 + 4);
                param_6 = fn(p58, param_7, *(uint32_t**)(b + 0x5c), param_8, b + 100, b + 0x68);
            }
            if ((int32_t)param_6 < 0) {
                FUN_0060fcd3(param_5, param_4, 0x5e3, "failed to open source file: \'%s\'", param_1);
                return param_6;
            }
LAB_0060be87:
            uint32_t uVar6 = FUN_0060f7b4(*(uint32_t*)(b + 100), *(uint32_t*)(b + 0x68), *(uint32_t*)(b + 0x5c), 1, param_3, param_5);
            if ((int32_t)uVar6 < 0) return uVar6;
            return 0;
        }
    }
    return 0x8007000e;
}

// 0x60beaa — observed shape
extern uint32_t FUN_0060f7b4(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);

int32_t FUN_0060beaa(void* self, int32_t param_1, int32_t param_2, uint32_t param_3, uint32_t param_4)
{
    uint8_t* b = (uint8_t*)self;
    int32_t iVar1;
    if ((param_2 == 0) || (param_1 != 0)) {
        *(int32_t*)(b + 100) = param_1;
        *(int32_t*)(b + 0x68) = param_2;
        iVar1 = (int32_t)FUN_0060f7b4((uint32_t)param_1, (uint32_t)param_2, 0, 1, param_3, param_4);
        if (-1 < iVar1) {
            iVar1 = 0;
        }
    } else {
        iVar1 = -0x7789f794;
    }
    return iVar1;
}

// 0x60bee5 — observed shape
void FUN_0060bee5(void* self, uint32_t param_1)
{
    uint32_t* v = (uint32_t*)self;
    v[1] = 0;
    v[0] = param_1;
    v[2] = 1;
}

// 0x60bf00 — observed shape
extern void FUN_0060bf00(void* self);
extern void operator_delete(void*);

void FUN_0060bf00(void* self)
{
    void* pvVar1 = *(void**)((uint8_t*)self + 4);
    if (pvVar1 != nullptr) {
        FUN_0060bf00(self);
        operator_delete(pvVar1);
    }
}

// 0x60bf1a — observed shape
extern void FUN_0060bf00(void* self);
extern void operator_delete(void*);

void FUN_0060bf1a(void* self, uint8_t param_1)
{
    FUN_0060bf00(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x60bf3b — observed shape
extern void FUN_0060bf3b(void* self);
extern void operator_delete(void*);

void FUN_0060bf3b(void* self)
{
    void* pvVar1 = *(void**)((uint8_t*)self + 0x28);
    if (pvVar1 != nullptr) {
        FUN_0060bf3b(self);
        operator_delete(pvVar1);
    }
}
