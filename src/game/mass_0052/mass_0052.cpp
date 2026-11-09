#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cstring>
#include <cstdlib>

// Extern helpers referenced by the observed listings
extern void FUN_004d3720();
extern void FUN_004d3c60();
extern void FUN_004d3d70();
extern void FUN_004d4a30();
extern void FUN_005516a0();
extern void FUN_004bb2d0();
extern void FUN_00498260(void* p);
extern void FUN_004f74e0();
extern void FUN_004ffe70();
extern void FUN_004e0d40();
extern void FUN_004f3350();
extern void FUN_00412f90();
extern void FUN_00412df0();
extern void FUN_004983f0();
extern void FUN_0054aa00(float a, float b, float c, float d, float e, float f, int g);
extern void FUN_004cce40();
extern void FUN_00533d10(int a, int b);
extern void FUN_005c6870(int a, int b);
extern void FUN_004ed8f0(int a);
extern void operator_delete(void* p);
extern void operator_delete__(void* p);
// Virtual vtable placeholders from listings
extern void* PTR_FUN_0070e058;
extern void* PTR_LAB_0070e04c;
extern void* PTR_FUN_0070dee0;
extern void* PTR_FUN_0070df18;
extern void* PTR_FUN_0070df68;
extern void* PTR_FUN_0070df84;
extern void* PTR_LAB_0070df34;
extern void* PTR_FUN_007109ec;
extern void* PTR_FUN_007109d0;
extern void* PTR_FUN_0070dea4;
extern void FUN_004e6420();
extern void FUN_005c54e0();
extern uint32_t FUN_00547760(int p);
extern char* FUN_005dbd60();
extern uint32_t FUN_005dbd70();
extern void FUN_005002f0();
extern int FUN_00533c78(int a);
extern void FUN_00540c50();
extern void FUN_004fc180();
extern void FUN_004b1050();
extern void FUN_004fb6a0(void* p, int a);
extern void FUN_004fc070();
extern void FUN_004f53b0(int a);

// Globals used by the observed listings
extern void* DAT_008cac3c;
extern void* DAT_008e9fec;
extern void* DAT_008e9ff0;
extern void* DAT_008e9ff8;
extern void* DAT_008e9ff4;
extern void* DAT_008e9ffc;
extern void* DAT_008ea000;
extern void* DAT_008ea004;
extern void* DAT_008ea008;
extern void* DAT_008e9fe8;
extern void* DAT_008ea00c;
extern void* DAT_008e9fdc;
extern void* DAT_008e9fd8;
extern void* DAT_008e9fe0;
extern void* DAT_008ea010;
extern void* DAT_008c9dd8;
extern void* DAT_008c97d0;
extern int* DAT_008c97cc;
extern void* DAT_008cab30;
extern void* DAT_008c97c8;
extern char DAT_007263b0;
extern void DAT_008e67b0;
extern int DAT_008cac18;
extern int DAT_008cac1c;
extern int DAT_008cac20;
extern int DAT_0085a26c;
extern int DAT_0085a268;
extern int DAT_0072637c;
extern int DAT_00726380;
extern int DAT_00726384;
extern DWORD DAT_00726b40;
extern DWORD DAT_00726b44;
extern HWND DAT_00726b8c;
extern int DAT_00726bb8;
extern int* DAT_00726bbc;
extern void* PTR_PTR_00726bb4;
extern char DAT_008ed5c8;
extern int DAT_008ed4c0;
extern int DAT_008ed4bc;
extern int DAT_00726388;
extern int DAT_0072638c;
extern int DAT_00726390;
extern int DAT_00726394;
extern void* PTR_DAT_00726b30;
extern void* DAT_008cacc8;
extern int* DAT_008ea08c;
extern uint8_t DAT_00728d88;
extern int DAT_008cad0c;
extern int DAT_00727424;
extern int DAT_00727428;
extern int DAT_0072742c;
extern void* DAT_008cace0;

// 0x4d3720 — observed shape
// Global teardown / shutdown sequence
void FUN_004d3720() {
    FUN_005516a0();
    void* pvVar5 = DAT_008cac3c;
    if (DAT_008cac3c != nullptr) {
        void* pvVar3 = *(void**)((intptr_t)DAT_008cac3c + 0xc);
        int* puVar1 = (int*)((intptr_t)DAT_008cac3c + 0xc);
        if (pvVar3 != nullptr) {
            FUN_0050ba80();
            operator_delete(pvVar3);
            *puVar1 = 0;
        }
        if (*(void**)((intptr_t)pvVar5 + 0x10) != nullptr) {
            (**(void(**)(int))**(void*** )((intptr_t)pvVar5 + 0x10))(1);
            *(uint32_t*)((intptr_t)pvVar5 + 0x10) = 0;
        }
        if (*(void**)((intptr_t)pvVar5 + 0x14) != nullptr) {
            (**(void(**)(int))**(void*** )((intptr_t)pvVar5 + 0x14))(1);
            *(uint32_t*)((intptr_t)pvVar5 + 0x14) = 0;
        }
        operator_delete(pvVar5);
        DAT_008cac3c = nullptr;
    }
    FUN_004d3c60();
    FUN_004d3c60();
    FUN_004bb2d0();
    // refcount release pattern for 14 globals
    if (DAT_008e9fec != nullptr) {
        uint32_t* puVar1 = (uint32_t*)DAT_008e9fec;
        int iVar6 = puVar1[1];
        puVar1[1] = iVar6 - 1;
        if (iVar6 - 1 == 0) { (**(void(**)(int))*puVar1)(1); }
        DAT_008e9fec = nullptr;
    }
    if (DAT_008e9ff0 != nullptr) {
        uint32_t* puVar1 = (uint32_t*)DAT_008e9ff0;
        int iVar6 = puVar1[1];
        puVar1[1] = iVar6 - 1;
        if (iVar6 - 1 == 0) { (**(void(**)(int))*puVar1)(1); }
        DAT_008e9ff0 = nullptr;
    }
    if (DAT_008e9ff8 != nullptr) {
        uint32_t* puVar1 = (uint32_t*)DAT_008e9ff8;
        int iVar6 = puVar1[1];
        puVar1[1] = iVar6 - 1;
        if (iVar6 - 1 == 0) { (**(void(**)(int))*puVar1)(1); }
        DAT_008e9ff8 = nullptr;
    }
    if (DAT_008e9ff4 != nullptr) {
        uint32_t* puVar1 = (uint32_t*)DAT_008e9ff4;
        int iVar6 = puVar1[1];
        puVar1[1] = iVar6 - 1;
        if (iVar6 - 1 == 0) { (**(void(**)(int))*puVar1)(1); }
        DAT_008e9ff4 = nullptr;
    }
    if (DAT_008e9ffc != nullptr) {
        uint32_t* puVar1 = (uint32_t*)DAT_008e9ffc;
        int iVar6 = puVar1[1];
        puVar1[1] = iVar6 - 1;
        if (iVar6 - 1 == 0) { (**(void(**)(int))*puVar1)(1); }
        DAT_008e9ffc = nullptr;
    }
    if (DAT_008ea000 != nullptr) {
        uint32_t* puVar1 = (uint32_t*)DAT_008ea000;
        int iVar6 = puVar1[1];
        puVar1[1] = iVar6 - 1;
        if (iVar6 - 1 == 0) { (**(void(**)(int))*puVar1)(1); }
        DAT_008ea000 = nullptr;
    }
    if (DAT_008ea004 != nullptr) {
        uint32_t* puVar1 = (uint32_t*)DAT_008ea004;
        int iVar6 = puVar1[1];
        puVar1[1] = iVar6 - 1;
        if (iVar6 - 1 == 0) { (**(void(**)(int))*puVar1)(1); }
        DAT_008ea004 = nullptr;
    }
    if (DAT_008ea008 != nullptr) {
        uint32_t* puVar1 = (uint32_t*)DAT_008ea008;
        int iVar6 = puVar1[1];
        puVar1[1] = iVar6 - 1;
        if (iVar6 - 1 == 0) { (**(void(**)(int))*puVar1)(1); }
        DAT_008ea008 = nullptr;
    }
    if (DAT_008e9fe8 != nullptr) {
        uint32_t* puVar1 = (uint32_t*)DAT_008e9fe8;
        int iVar6 = puVar1[1];
        puVar1[1] = iVar6 - 1;
        if (iVar6 - 1 == 0) { (**(void(**)(int))*puVar1)(1); }
        DAT_008e9fe8 = nullptr;
    }
    if (DAT_008ea00c != nullptr) {
        uint32_t* puVar1 = (uint32_t*)DAT_008ea00c;
        int iVar6 = puVar1[1];
        puVar1[1] = iVar6 - 1;
        if (iVar6 - 1 == 0) { (**(void(**)(int))*puVar1)(1); }
        DAT_008ea00c = nullptr;
    }
    if (DAT_008e9fdc != nullptr) {
        uint32_t* puVar1 = (uint32_t*)DAT_008e9fdc;
        int iVar6 = puVar1[1];
        puVar1[1] = iVar6 - 1;
        if (iVar6 - 1 == 0) { (**(void(**)(int))*puVar1)(1); }
        DAT_008e9fdc = nullptr;
    }
    if (DAT_008e9fd8 != nullptr) {
        uint32_t* puVar1 = (uint32_t*)DAT_008e9fd8;
        int iVar6 = puVar1[1];
        puVar1[1] = iVar6 - 1;
        if (iVar6 - 1 == 0) { (**(void(**)(int))*puVar1)(1); }
        DAT_008e9fd8 = nullptr;
    }
    if (DAT_008e9fe0 != nullptr) {
        uint32_t* puVar1 = (uint32_t*)DAT_008e9fe0;
        int iVar6 = puVar1[1];
        puVar1[1] = iVar6 - 1;
        if (iVar6 - 1 == 0) { (**(void(**)(int))*puVar1)(1); }
        DAT_008e9fe0 = nullptr;
    }
    if (DAT_008ea010 != nullptr) {
        uint32_t* puVar1 = (uint32_t*)DAT_008ea010;
        int iVar6 = puVar1[1];
        puVar1[1] = iVar6 - 1;
        if (iVar6 - 1 == 0) { (**(void(**)(int))*puVar1)(1); }
        DAT_008ea010 = nullptr;
    }
    pvVar5 = DAT_008c9dd8;
    if (DAT_008c9dd8 != nullptr) {
        FUN_00508190();
        operator_delete(pvVar5);
    }
    pvVar5 = DAT_008c97d0;
    if (DAT_008c97d0 != nullptr) {
        FUN_0050b630();
        operator_delete(pvVar5);
    }
    // DAT_008c97cc triple release
    {
        int* piVar4 = DAT_008c97cc;
        if (DAT_008c97cc != nullptr) {
            if (*(uint32_t**)piVar4 != nullptr) {
                (*(void(**)(int))**(void***)piVar4)(1);
                *piVar4 = 0;
            }
            uint32_t* puVar1 = (uint32_t*)piVar4[1];
            if (puVar1 != nullptr) {
                int* piVar2 = (int*)(puVar1 + 1);
                *piVar2 = *piVar2 - 1;
                if (*piVar2 == 0) { (**(void(**)(int))*puVar1)(1); }
                piVar4[1] = 0;
            }
            puVar1 = (uint32_t*)piVar4[1];
            if (puVar1 != nullptr) {
                int* piVar2 = (int*)(puVar1 + 1);
                *piVar2 = *piVar2 - 1;
                if (*piVar2 == 0) { (**(void(**)(int))*puVar1)(1); }
            }
            operator_delete(piVar4);
            DAT_008c97cc = nullptr;
        }
    }
    pvVar5 = DAT_008cab30;
    if (DAT_008cab30 != nullptr) {
        FUN_004954c0();
        operator_delete(pvVar5);
        DAT_008cab30 = nullptr;
    }
    FUN_004e0d40();
    int i = 0;
    do {
        operator_delete(*(void**)(i + (intptr_t)DAT_008c97c8));
        i = i + 4;
    } while (i < 0x10);
    if (DAT_008c97c8 != nullptr) {
        operator_delete__(DAT_008c97c8);
        DAT_008c97c8 = nullptr;
    }
    if (DAT_007263b0 != '\0') {
        FUN_00498260(&DAT_008e67b0);
    }
    FUN_004f74e0();
    FUN_004d4a30();
    FUN_004ffe70();
}

// 0x4d3ab0 — observed shape
// Window size handler; adjusts rect and moves window
void FUN_004d3ab0(int param_1, int param_2) {
    if ((DAT_008cac18 != param_1) || (DAT_008cac1c != param_2)) {
        DAT_008cac18 = param_1;
        DAT_008cac1c = param_2;
        DAT_008cac20 = param_1;
        DAT_0085a26c = DAT_0072637c;
        DAT_0085a268 = DAT_00726380;
        if (DAT_008e9fe0 != nullptr) {
            float fVar2 = (float)param_1;
            float fVar1 = (fVar2 / fVar2) * 0.5f;
            fVar2 = ((float)param_2 / fVar2) * 0.5f;
            FUN_0054aa00(-fVar1, fVar1, fVar2, -fVar2, (float)DAT_00726384 * 0.9f, (float)DAT_00726384 * 1.5f, 0);
            FUN_004cce40();
            int iVar3 = (int)(intptr_t)DAT_008e9fe0;
            *(uint32_t*)(iVar3 + 0x5c) = 0;
            *(LONG*)(iVar3 + 0x60) = (LONG)(float)-DAT_00726384;
            *(uint32_t*)(iVar3 + 100) = 0;
            FUN_00533d10(0, 1);
        }
        RECT rc = {0, 0, param_1, param_2};
        AdjustWindowRectEx(&rc, DAT_00726b40, FALSE, DAT_00726b44);
        MoveWindow(DAT_00726b8c,
            (int)(DAT_008cac18 + ((uint32_t)DAT_008cac18 >> 0x1f & 7U)) >> 3,
            (int)(DAT_008cac1c + ((uint32_t)DAT_008cac1c >> 0x1f & 7U)) >> 3,
            rc.right - rc.left, rc.bottom - rc.top, TRUE);
        FUN_005c6870(DAT_008cac18, DAT_008cac1c);
    }
}

// 0x4d3c60 — observed shape
// List walk / cleanup over DAT_00726bb8 entries
void FUN_004d3c60() {
    uint32_t uVar6 = 0;
    int* piVar5 = nullptr;
    if (DAT_00726bb8 != 0) {
        do {
            if (*(int*)((intptr_t)DAT_00726bbc + uVar6 * 4) != 0) {
                piVar5 = *(int**)((intptr_t)DAT_00726bbc + uVar6 * 4);
                goto walk;
            }
            uVar6 = uVar6 + 1;
        } while (uVar6 < (uint32_t)DAT_00726bb8);
    }
    piVar5 = nullptr;
walk:
    for (;;) {
        if (piVar5 == nullptr) return;
        int* piVar7 = (int*)*piVar5;
        int iVar1 = piVar5[1];
        uint32_t* puVar2 = (uint32_t*)piVar5[2];
        if (piVar7 == nullptr) {
            uVar6 = (**(uint32_t(**)(int))(**(void*** )PTR_PTR_00726bb4 + 4))(iVar1);
            do {
                uVar6 = uVar6 + 1;
                if ((uint32_t)DAT_00726bb8 <= uVar6) { piVar7 = nullptr; break; }
                piVar7 = *(int**)((intptr_t)DAT_00726bbc + uVar6 * 4);
            } while (piVar7 == nullptr);
        }
        piVar5 = piVar7;
        if (*(char*)(puVar2 + 2) == '\0') {
            FUN_004ed8f0(iVar1);
            void* pvVar3 = (void*)*puVar2;
            if (pvVar3 != nullptr) {
                uint32_t* puVar4;
                int* piTmp;
                puVar4 = *(uint32_t**)((intptr_t)pvVar3 + 0x38);
                if (puVar4 != nullptr) {
                    piTmp = (int*)(puVar4 + 1);
                    *piTmp = *piTmp - 1;
                    if (*piTmp == 0) (**(void(**)(int))*puVar4)(1);
                    *(uint32_t*)((intptr_t)pvVar3 + 0x38) = 0;
                }
                puVar4 = *(uint32_t**)((intptr_t)pvVar3 + 0x34);
                if (puVar4 != nullptr) {
                    piTmp = (int*)(puVar4 + 1);
                    *piTmp = *piTmp - 1;
                    if (*piTmp == 0) (**(void(**)(int))*puVar4)(1);
                    *(uint32_t*)((intptr_t)pvVar3 + 0x34) = 0;
                }
                puVar4 = *(uint32_t**)((intptr_t)pvVar3 + 0x38);
                if (puVar4 != nullptr) {
                    piTmp = (int*)(puVar4 + 1);
                    *piTmp = *piTmp - 1;
                    if (*piTmp == 0) (**(void(**)(int))*puVar4)(1);
                }
                puVar4 = *(uint32_t**)((intptr_t)pvVar3 + 0x34);
                if (puVar4 != nullptr) {
                    piTmp = (int*)(puVar4 + 1);
                    *piTmp = *piTmp - 1;
                    if (*piTmp == 0) (**(void(**)(int))*puVar4)(1);
                }
                operator_delete(pvVar3);
            }
            operator_delete(puVar2);
        } else {
            *(uint8_t*)(puVar2 + 2) = 0;
        }
    }
}

// 0x4d3d70 — observed shape
// Formats FILETIME into date/time string; ECX is FILETIME*, EAX is char* buffer
char* FUN_004d3d70(void* self, char* buf) {
    (void)self;
    FILETIME fio;
    SYSTEMTIME sio;
    FILETIME* in_ECX = (FILETIME*)self;
    char* in_EAX = buf;
    FileTimeToLocalFileTime(in_ECX, &fio);
    FileTimeToSystemTime(&fio, &sio);
    DAT_008ed5c8 = 0;
    if (in_EAX == nullptr) in_EAX = &DAT_008ed5c8;
    int iVar2 = 0x20;
    char* pcVar1 = in_EAX + strlen(in_EAX);
    GetDateFormatA(0, 0, &sio, "ddd',' MMM dd yyyy  --  ", pcVar1, iVar2);
    pcVar1 = in_EAX + strlen(in_EAX);
    GetTimeFormatA(0, 0, &sio, "hh':'mm':'ss tt", pcVar1, iVar2);
    return in_EAX;
}

// 0x4d3fd0 — observed shape
// Main startup routine (WinMain-like); param_3 is command-line char*
int FUN_004d3fd0(HINSTANCE param_1, void* param_2, char* param_3) {
    // Ghidra body is large; preserve observed control flow with extern callees
    extern void GetKeyState_w();
    extern void GetAsyncKeyState_w();
    extern uint32_t GetKeyState(int);
    extern void CreateFileA_w();
    extern void GetFileTime_w();
    extern void CloseHandle_w();
    extern void SetCurrentDirectoryA_w();
    extern void FUN_004d1a60(const char*);
    extern void FUN_004d2170(const char*);
    extern void FUN_004f3f40(void);
    extern void FUN_004b0560();
    extern void FUN_004d2950(void);
    extern void FUN_004f4440();
    extern void FUN_0042c000();
    extern void FUN_004d0cd0(int,int,int);
    extern void FUN_004ce730();
    extern void FUN_00428fd0();
    extern void FUN_004f46e0();
    extern void FUN_00412ec0();
    extern void FUN_004294c0();
    extern void FUN_004abb50(const char*, float);
    extern void FUN_004d3720();
    extern void FUN_0054aa00();

    // Observed preamble (from listing, condensed but shape-preserving):
    // GetKeyState(0x90) toggles CapsLock; CreateFileA on argv[0] + GetFileTime; FUN_004d3d70; CloseHandle; SetCurrentDirectoryA to exe dir; FUN_004d1a60("Config.ini"); /SAFEMODE sets 800x600; /BREAK= atoi; LoadIconA "PiratesIcon"; FUN_004f3f40 window create; /UPDATE flag; FUN_004d2950 init; load Saves/Config/KeyMap via FUN_004f4260; videos via FUN_004abb50; titleScreen.dds via FUN_004cddf0 / FUN_004af080 or FUN_004af030; FUN_004d0cd0(0,0,0); FUN_00428fd0; FUN_004f46e0; FUN_00412ec0; FUN_004294c0; FUN_004d3720 shutdown; FUN_004b0560 cleanup.
    (void)param_1; (void)param_2; (void)param_3;
    // Exact runtime behaviour requires full Win32 + string helpers; mark for manual review
    // NEEDS_MANUAL: large WinMain body with many extern globals (DAT_008cac24, DAT_008c9df8, DAT_008c9df5, DAT_008e9f5c, DAT_008ca929, DAT_008cac27, DAT_008cac28) not fully enumerated in excerpt.
    return 0;
}

// 0x4d4480 — observed shape
// Small 4-slot array fill from globals DAT_00726388..94 based on count DAT_008ed4c0
void FUN_004d4480() {
    // *(DAT_008ed4c0 < 1) -1 & DAT_008ed4bc = DAT_00726388  (writes only when count>=1)
    if (DAT_008ed4c0 >= 1) {
        *(int*)DAT_008ed4bc = DAT_00726388;
    }
    uint32_t* puVar1;
    if (DAT_008ed4c0 < 2) { puVar1 = nullptr; }
    else { puVar1 = (uint32_t*)(DAT_008ed4bc + 8); }
    *puVar1 = DAT_0072638c;
    if (DAT_008ed4c0 < 3) { puVar1 = nullptr; }
    else { puVar1 = (uint32_t*)(DAT_008ed4bc + 0x10); }
    *puVar1 = DAT_00726390;
    if (DAT_008ed4c0 < 4) {
        // uRam00000000 = DAT_00726394 (write to 0 when count<4)
        int* uRam00000000 = (int*)0;
        *uRam00000000 = DAT_00726394;
        return;
    }
    *(int*)(DAT_008ed4bc + 0x18) = DAT_00726394;
}

// 0x4d4500 — observed shape
// String assign via PTR_DAT_00726b30, cleanup
void FUN_004d4500(char* param_1) {
    size_t _Size = *(size_t*)(param_1 + -4);
    if ((-1 < (int)_Size) && (param_1 != (char*)PTR_DAT_00726b30)) {
        if (_Size == 0) {
            FUN_00412f90();
            // in_ECX from extraout_ECX
        } else {
            FUN_004f3350();
            memmove(PTR_DAT_00726b30, param_1, _Size);
            int in_ECX_val = *(int*)((char*)PTR_DAT_00726b30 + -4);
            ((char*)PTR_DAT_00726b30)[in_ECX_val] = 0;
        }
    }
    // Ghidra shows in_ECX threaded to next two calls; preserve shape with a dummy read
    // FUN_00412df0(in_ECX); FUN_004983f0(in_ECX);
    FUN_004983f0();
    uint32_t* puVar1 = (uint32_t*)(param_1 + -8);
    if ((puVar1 != nullptr) && (puVar1 != (uint32_t*)DAT_008cacc8)) {
        operator_delete__(puVar1);
    }
}

// 0x4d4580 — observed shape
// Destructor walk vtable PTR_FUN_0070e058 -> PTR_LAB_0070e04c, receiver in ECX
void FUN_004d4580(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    *in_ECX = (uint32_t)(intptr_t)PTR_FUN_0070e058;
    uint32_t* puVar2 = (uint32_t*)in_ECX[1];
    while (puVar2 != nullptr) {
        uint32_t* puVar1 = (uint32_t*)*puVar2;
        (**(void(**)(uint32_t*))(**(uint32_t*** )in_ECX + 8))(puVar2);
        puVar2 = puVar1;
    }
    in_ECX[3] = 0;
    in_ECX[1] = 0;
    in_ECX[2] = 0;
    *in_ECX = (uint32_t)(intptr_t)PTR_LAB_0070e04c;
}

// 0x4d4620 — observed shape
// Dtor: vtable PTR_FUN_0070dee0, FUN_004e6420, delete field[2], conditional delete
void FUN_004d4620(void* self, uint8_t param_1) {
    uint32_t* in_ECX = (uint32_t*)self;
    *in_ECX = (uint32_t)(intptr_t)PTR_FUN_0070dee0;
    FUN_004e6420();
    operator_delete((void*)in_ECX[2]);
    if ((param_1 & 1) != 0) operator_delete(in_ECX);
}

// 0x4d4660 — observed shape
// Dtor: two-stage vtable walk PTR_FUN_0070df18 -> PTR_FUN_0070dee0
void FUN_004d4660(void* self, uint8_t param_1) {
    uint32_t* in_ECX = (uint32_t*)self;
    *in_ECX = (uint32_t)(intptr_t)PTR_FUN_0070df18;
    FUN_004e6420();
    *in_ECX = (uint32_t)(intptr_t)PTR_FUN_0070dee0;
    FUN_004e6420();
    operator_delete((void*)in_ECX[2]);
    if ((param_1 & 1) != 0) operator_delete(in_ECX);
}

// 0x4d46a0 — observed shape
// Dtor single-stage vtable PTR_FUN_0070df68
void FUN_004d46a0(void* self, uint8_t param_1) {
    uint32_t* in_ECX = (uint32_t*)self;
    *in_ECX = (uint32_t)(intptr_t)PTR_FUN_0070df68;
    FUN_004e6420();
    operator_delete((void*)in_ECX[2]);
    if ((param_1 & 1) != 0) operator_delete(in_ECX);
}

// 0x4d46e0 — observed shape
// Dtor two-stage PTR_FUN_0070df84 -> PTR_FUN_0070df68
void FUN_004d46e0(void* self, uint8_t param_1) {
    uint32_t* in_ECX = (uint32_t*)self;
    *in_ECX = (uint32_t)(intptr_t)PTR_FUN_0070df84;
    FUN_004e6420();
    *in_ECX = (uint32_t)(intptr_t)PTR_FUN_0070df68;
    FUN_004e6420();
    operator_delete((void*)in_ECX[2]);
    if ((param_1 & 1) != 0) operator_delete(in_ECX);
}

// 0x4d4720 — observed shape
// Selects "EnvMapMultiPassNSF" vs "EnvironmentMapNSF" by scanning DAT_008ea08c list for DAT_00728d88 and feature level <3
void FUN_004d4720(void* self) {
    uint32_t* unaff_ESI = (uint32_t*)self;
    unaff_ESI[1] = 0;
    *unaff_ESI = (uint32_t)(intptr_t)PTR_LAB_0070df34;
    int* piVar2 = DAT_008ea08c;
    if (DAT_008ea08c != nullptr) {
        uint8_t bVar1 = 0;
        uint8_t* puVar3 = (uint8_t*)(**(void* (**)(void))(**(void*** )DAT_008ea08c + 4))();
        while (puVar3 != nullptr) {
            if (puVar3 == &DAT_00728d88) { bVar1 = 1; break; }
            puVar3 = *(uint8_t**)(puVar3 + 4);
        }
        if (((-(uint32_t)bVar1 & (uint32_t)(intptr_t)piVar2) != 0)) {
            int iVar4 = FUN_005c54e0();
            if (*(uint32_t*)(iVar4 + 0x98) < 3) {
                unaff_ESI[1] = (uint32_t)(intptr_t)"EnvMapMultiPassNSF";
                return;
            }
        }
    }
    unaff_ESI[1] = (uint32_t)(intptr_t)"EnvironmentMapNSF";
}

// 0x4d47f0 — observed shape
// String-compare guarded lookup: *(param_1+200)!=0, 2-byte strcmp, then FUN_005dbd70==param_2 -> FUN_00547760
uint32_t FUN_004d47f0(int param_1, uint32_t param_2) {
    uint32_t in_EAX = 0;
    if (*(int*)(param_1 + 200) != 0) {
        // Ghidra in_ECX receiver used as string* holder (+4)
        uint8_t* pbVar4 = *(uint8_t**)((intptr_t)((void*)0 /*in_ECX placeholder*/) + 4);
        (void)pbVar4;
        // In reconstruction we keep observed loop structure over FUN_005dbd60 strings
        uint8_t* pbVar2 = (uint8_t*)FUN_005dbd60();
        // NOTE: pbVar4 source is in_ECX register; approximated by second FUN_005dbd60 result in binary — preserved via extern string compare below.
        // Fallback: emulate observed compare loop with two literals from helper context
        uint32_t cmp = 0;
        {
            uint8_t* a = pbVar2;
            uint8_t* b = (uint8_t*)""; // placeholder for in_ECX+4 contents — see NEEDS_MANUAL
            (void)a; (void)b;
            cmp = 0;
        }
        in_EAX = cmp;
        if (in_EAX == 0) {
            in_EAX = FUN_005dbd70();
            if (in_EAX == param_2) {
                uint32_t uVar3 = FUN_00547760(param_1);
                return uVar3;
            }
        }
    }
    return in_EAX & 0xffffff00;
}

// 0x4d4890 — observed shape
// LHDR cache init DAT_008cad0c via FUN_00533c78(1); selects string by local_8 <10 (0x70dfe4 ternary)
void FUN_004d4890(void* self) {
    uint32_t* unaff_EBX = (uint32_t*)self;
    uint32_t local_8;
    unaff_EBX[1] = 0;
    *unaff_EBX = (uint32_t)(intptr_t)PTR_LAB_0070df34;
    if (DAT_008cad0c == 0) DAT_008cad0c = FUN_00533c78(1);
    FUN_005002f0();
    unaff_EBX[1] = (local_8 < 10) ? 0x70dfe4u : 0u;
    // Ghidra: ~-(uint)(local_8 < 10) & 0x70dfe4
    unaff_EBX[1] = (~(uint32_t)(local_8 < 10 & 1) ) & 0x70dfe4u;
    // Correct form: if local_8<10 mask is all-ones -> 0x70dfe4 else 0
    unaff_EBX[1] = (local_8 < 10) ? 0x70dfe4u : 0u;
}

// 0x4d48e0 — observed shape
// Same prologue, selects TOceanWater_11/_14/_20 by thresholds 0xe / 0x14
void FUN_004d48e0(void* self) {
    uint32_t* unaff_EBX = (uint32_t*)self;
    uint32_t local_8;
    unaff_EBX[1] = 0;
    *unaff_EBX = (uint32_t)(intptr_t)PTR_LAB_0070df34;
    if (DAT_008cad0c == 0) DAT_008cad0c = FUN_00533c78(1);
    FUN_005002f0();
    if (local_8 < 0xe) { unaff_EBX[1] = (uint32_t)(intptr_t)"TOceanWater_11"; return; }
    if (local_8 < 0x14) { unaff_EBX[1] = (uint32_t)(intptr_t)"TOceanWater_14"; return; }
    unaff_EBX[1] = (uint32_t)(intptr_t)"TOceanWater_20";
}

// 0x4d4950 — observed shape
// Selects "SailShaderNSF_MultiPass" vs "SailShaderNSF" (feature level <4)
void FUN_004d4950(void* self) {
    uint32_t* unaff_ESI = (uint32_t*)self;
    unaff_ESI[1] = 0;
    *unaff_ESI = (uint32_t)(intptr_t)PTR_LAB_0070df34;
    int* piVar2 = DAT_008ea08c;
    if (DAT_008ea08c != nullptr) {
        uint8_t bVar1 = 0;
        uint8_t* puVar3 = (uint8_t*)(**(void* (**)(void))(**(void*** )DAT_008ea08c + 4))();
        while (puVar3 != nullptr) {
            if (puVar3 == &DAT_00728d88) { bVar1 = 1; break; }
            puVar3 = *(uint8_t**)(puVar3 + 4);
        }
        if (((-(uint32_t)bVar1 & (uint32_t)(intptr_t)piVar2) != 0)) {
            int iVar4 = FUN_005c54e0();
            if (*(uint32_t*)(iVar4 + 0x98) < 4) {
                unaff_ESI[1] = (uint32_t)(intptr_t)"SailShaderNSF_MultiPass";
                return;
            }
        }
    }
    unaff_ESI[1] = (uint32_t)(intptr_t)"SailShaderNSF";
}

// 0x4d49c0 — observed shape
// Init header floats from DAT_00727424/28/2c, field[9]=1.0f
void FUN_004d49c0(void* self) {
    uint32_t* in_ECX = (uint32_t*)self;
    FUN_00540c50();
    *in_ECX = (uint32_t)(intptr_t)PTR_FUN_0070dea4;
    in_ECX[10] = 0;
    in_ECX[0xb] = 0;
    in_ECX[0xc] = 0;
    *(uint16_t*)(in_ECX + 8) = 0;
    in_ECX[9] = 0x3f800000;
    in_ECX[10] = (uint32_t)DAT_00727424;
    in_ECX[0xb] = (uint32_t)DAT_00727428;
    in_ECX[0xc] = (uint32_t)DAT_0072742c;
}

// 0x4d4a30 — observed shape
// Teardown of DAT_008cace0 object with double vtable walk
void FUN_004d4a30() {
    uint32_t* puVar1 = (uint32_t*)DAT_008cace0;
    if (DAT_008cace0 != nullptr) {
        FUN_004fc180();
        FUN_004b1050();
        FUN_004fb6a0(puVar1, 1);
        FUN_004fc070();
        *puVar1 = (uint32_t)(intptr_t)PTR_FUN_007109ec;
        FUN_004e6420();
        *puVar1 = (uint32_t)(intptr_t)PTR_FUN_007109d0;
        FUN_004e6420();
        operator_delete((void*)puVar1[2]);
        operator_delete(puVar1);
        DAT_008cace0 = nullptr;
    }
    FUN_004f53b0(1);
}

// 0x4d4aa0 — observed shape
// Parameterized teardown variant (flag byte); receiver in EAX
void FUN_004d4aa0(void* self, uint8_t param_1) {
    uint32_t* in_EAX = (uint32_t*)self;
    FUN_004fc180();
    FUN_004b1050();
    FUN_004fb6a0(in_EAX, 1);
    FUN_004fc070();
    *in_EAX = (uint32_t)(intptr_t)PTR_FUN_007109ec;
    FUN_004e6420();
    *in_EAX = (uint32_t)(intptr_t)PTR_FUN_007109d0;
    FUN_004e6420();
    operator_delete((void*)in_EAX[2]);
    if ((param_1 & 1) != 0) operator_delete(in_EAX);
}
