#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void* DAT_00727c30;
extern void* DAT_00727c34;
extern void* DAT_00727c3c;
extern void* PTR_FUN_006c22b8;
extern void* PTR_FUN_006c23e0;
extern void* PTR_FUN_006c2478;

void FUN_005383d0();
void FUN_00538400();
void FUN_005386f0(int param);
void FUN_0053e5d0(uint32_t param);
void FUN_0053e630();
void FUN_0053e670();
void FUN_0053e760(int* param);
void FUN_0053edc0(int param);
int FUN_00533c78(unsigned int size);
int FUN_005456f0(int param);
uint32_t FUN_00556650(uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7, uint32_t p8, uint32_t p9);
int FUN_00557b10(void* param);
void FUN_005606f0(uint32_t idx, int* param);
void FUN_006b34a0(int addr);
void operator_delete(void* ptr);
uint32_t FUN_00551550(int* self);
void FUN_00551730(uint32_t param);
void FUN_00551750();
void FUN_00551770();

// 0x5512a0 — observed shape: clears global via DAT_00727c30, returns void.
void FUN_005512a0() {
    DAT_00727c30 = nullptr;
    return;
}

// 0x5512b0 — observed shape: in_ECX receiver; vtable init, zero fields, InitializeCriticalSection at +6 and +0xe (byte offsets 0x18 and 0x38), refcount release on field[3], set DAT_00727c30=self.
void FUN_005512b0(void* self) {
    auto* dv = static_cast<uint32_t*>(self);
    FUN_005383d0();
    dv[0] = reinterpret_cast<uint32_t>(PTR_FUN_006c22b8);
    dv[3] = 0;
    dv[0xc] = 0;
    dv[0xd] = 0;
    InitializeCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(dv + 6));
    dv[0x14] = 0;
    dv[0x15] = 0;
    InitializeCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(dv + 0xe));
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(dv[3]);
    if (puVar2 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using Fn = void(__cdecl*)(int);
            Fn fn = reinterpret_cast<Fn>(*puVar2);
            fn(1);
        }
        dv[3] = 0;
    }
    DAT_00727c30 = dv;
    *(reinterpret_cast<uint8_t*>(dv) + 0x16) = 0;
    return;
}

// 0x551370 — observed shape: in_ECX receiver; vtable init, DAT_00727c30=0, DeleteCriticalSection at +0xe and +6 (reverse order), refcount release on field[3], tail call FUN_00538400.
void FUN_00551370(void* self) {
    auto* dv = static_cast<uint32_t*>(self);
    dv[0] = reinterpret_cast<uint32_t>(PTR_FUN_006c22b8);
    DAT_00727c30 = nullptr;
    DeleteCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(dv + 0xe));
    DeleteCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(dv + 6));
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(dv[3]);
    if (puVar2 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using Fn = void(__cdecl*)(int);
            Fn fn = reinterpret_cast<Fn>(*puVar2);
            fn(1);
        }
    }
    FUN_00538400();
    return;
}

// 0x5513e0 — observed shape: in_ECX receiver + byte param; same teardown as 0x551370, then operator_delete if (param_1 & 1).
void FUN_005513e0(void* self, uint8_t param1) {
    auto* dv = static_cast<uint32_t*>(self);
    dv[0] = reinterpret_cast<uint32_t>(PTR_FUN_006c22b8);
    DAT_00727c30 = nullptr;
    DeleteCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(dv + 0xe));
    DeleteCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(dv + 6));
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(dv[3]);
    if (puVar2 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using Fn = void(__cdecl*)(int);
            Fn fn = reinterpret_cast<Fn>(*puVar2);
            fn(1);
        }
    }
    FUN_00538400();
    if ((param1 & 1) != 0) {
        operator_delete(dv);
    }
    return;
}

// 0x551500 — observed shape: param_1 is a struct pointer used via byte offsets; calls FUN_005386f0, reads DAT_00727c34 via FUN_00557b10, bounds-check on *(+0xc) vs *(+8), calls FUN_006b34a0 with *(+0x14)+idx, then FUN_005606f0.
void FUN_00551500(int param1) {
    int iVar2 = param1;
    FUN_005386f0(param1);
    param1 = FUN_00557b10(DAT_00727c34);
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
    if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(iVar2 + 0x14) + static_cast<int>(uVar1));
    }
    FUN_005606f0(uVar1, &param1);
    return;
}
// 0x551550 — observed shape: int* receiver; if param[0x57]==0 calls vfunc at +0xc with param+9, else calls vfunc at +0x38; stores result to param+0x67 byte, then calls vfunc at +0x1c; returns 0.
uint32_t FUN_00551550(int* self) {
    uint8_t uVar1;
    if (self[0x57] == 0) {
        using FnA = uint8_t(__thiscall*)(int*, int*);
        FnA fa = reinterpret_cast<FnA>(*reinterpret_cast<void**>(*self + 0xc));
        uVar1 = fa(self, self + 9);
        *(reinterpret_cast<uint8_t*>(self) + 0x67 * 4) = uVar1;
        using FnB = void(__thiscall*)(int*);
        FnB fb = reinterpret_cast<FnB>(*reinterpret_cast<void**>(*self + 0x1c));
        fb(self);
        return 0;
    }
    using FnC = uint8_t(__thiscall*)(int*);
    FnC fc = reinterpret_cast<FnC>(*reinterpret_cast<void**>(*self + 0x38));
    uVar1 = fc(self);
    *(reinterpret_cast<uint8_t*>(self) + 0x67 * 4) = uVar1;
    using FnB2 = void(__thiscall*)(int*);
    FnB2 fb2 = reinterpret_cast<FnB2>(*reinterpret_cast<void**>(*self + 0x1c));
    fb2(self);
    return 0;
}

// 0x5515a0 — observed shape: in_ECX receiver; sets *(+0x1a0)=0xffffffff, _beginthreadex with start FUN_00551550 self as arg, stores handle at +0x1ac, SetThreadPriority -1, ResumeThread, sets *(+0x198)=1.
void FUN_005515a0(void* self) {
    char* base = static_cast<char*>(self);
    *reinterpret_cast<int*>(base + 0x1a0) = -1;
    uint32_t local_4 = 0;
    HANDLE hThread = reinterpret_cast<HANDLE>(_beginthreadex(nullptr, 0, FUN_00551550, static_cast<int*>(self), 4, &local_4));
    *reinterpret_cast<HANDLE*>(base + 0x1ac) = hThread;
    SetThreadPriority(hThread, -1);
    ResumeThread(*reinterpret_cast<HANDLE*>(base + 0x1ac));
    *reinterpret_cast<int*>(base + 0x198) = 1;
    return;
}

// 0x551600 — observed shape: in_ECX receiver + int param; polls thread state (+0x198 =1/2): GetExitCodeThread, if !=STILL_ACTIVE (0x103) CloseHandle and reset to 0; if param!=0 and state 1 or 4 calls FUN_005456f0(param); returns current state.
int FUN_00551600(int param1, void* self) {
    char* base = static_cast<char*>(self);
    int iVar1 = *reinterpret_cast<int*>(base + 0x198);
    if (iVar1 == 1 || iVar1 == 2) {
        DWORD local_4 = static_cast<DWORD>(reinterpret_cast<uintptr_t>(self));
        GetExitCodeThread(*reinterpret_cast<HANDLE*>(base + 0x1ac), &local_4);
        if (local_4 != 0x103) {
            CloseHandle(*reinterpret_cast<HANDLE*>(base + 0x1ac));
            *reinterpret_cast<int*>(base + 0x198) = 0;
        }
    }
    iVar1 = *reinterpret_cast<int*>(base + 0x198);
    if (param1 != 0) {
        if (iVar1 == 1 || iVar1 == 4) {
            FUN_005456f0(param1);
        }
        iVar1 = *reinterpret_cast<int*>(base + 0x198);
    }
    return iVar1;
}

// 0x551680 — observed shape: in_ECX receiver; sets *(+0x198)=4, SuspendThread(handle at +0x1ac).
void FUN_00551680(void* self) {
    char* base = static_cast<char*>(self);
    *reinterpret_cast<int*>(base + 0x198) = 4;
    SuspendThread(*reinterpret_cast<HANDLE*>(base + 0x1ac));
    return;
}

// 0x5516a0 — observed shape: in_ECX receiver; if state==4 ResumeThread and state=1; if state 1/2 WaitForSingleObject INFINITE then GetExitCodeThread/CloseHandle if not STILL_ACTIVE; returns byte at +0x19c.
uint8_t FUN_005516a0(void* self) {
    char* base = static_cast<char*>(self);
    DWORD local_4 = static_cast<DWORD>(reinterpret_cast<uintptr_t>(self));
    if (*reinterpret_cast<int*>(base + 0x198) == 4) {
        ResumeThread(*reinterpret_cast<HANDLE*>(base + 0x1ac));
        *reinterpret_cast<int*>(base + 0x198) = 1;
    }
    if (*reinterpret_cast<int*>(base + 0x198) == 1 || *reinterpret_cast<int*>(base + 0x198) == 2) {
        WaitForSingleObject(*reinterpret_cast<HANDLE*>(base + 0x1ac), 0xffffffff);
        if (*reinterpret_cast<int*>(base + 0x198) == 1 || *reinterpret_cast<int*>(base + 0x198) == 2) {
            GetExitCodeThread(*reinterpret_cast<HANDLE*>(base + 0x1ac), &local_4);
            if (local_4 != 0x103) {
                CloseHandle(*reinterpret_cast<HANDLE*>(base + 0x1ac));
                *reinterpret_cast<int*>(base + 0x198) = 0;
            }
        }
    }
    return *reinterpret_cast<uint8_t*>(base + 0x19c);
}
// 0x551730 — observed shape: in_ECX receiver + param; calls FUN_0053e5d0(param), sets *self = PTR_FUN_006c23e0.
void FUN_00551730(uint32_t param, void* self) {
    FUN_0053e5d0(param);
    *static_cast<uint32_t*>(self) = reinterpret_cast<uint32_t>(PTR_FUN_006c23e0);
    return;
}

// 0x551750 — observed shape: in_ECX receiver; calls FUN_0053e630(), sets *self = PTR_FUN_006c23e0.
void FUN_00551750(void* self) {
    FUN_0053e630();
    *static_cast<uint32_t*>(self) = reinterpret_cast<uint32_t>(PTR_FUN_006c23e0);
    return;
}

// 0x551770 — observed shape: in_ECX receiver; sets *self = PTR_FUN_006c23e0, then FUN_0053e670().
void FUN_00551770(void* self) {
    *static_cast<uint32_t*>(self) = reinterpret_cast<uint32_t>(PTR_FUN_006c23e0);
    FUN_0053e670();
    return;
}

// 0x551790 — observed shape: in_ECX receiver + byte param; sets *self = PTR_FUN_006c23e0, calls FUN_0053e670(), operator_delete if (param & 1).
void FUN_00551790(void* self, uint8_t param1) {
    *static_cast<uint32_t*>(self) = reinterpret_cast<uint32_t>(PTR_FUN_006c23e0);
    FUN_0053e670();
    if ((param1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// 0x5517c0 — observed shape: param_1 is a struct pointer; same pattern as 0x551500 but with DAT_00727c3c and FUN_0053edc0.
void FUN_005517c0(int param1) {
    int iVar2 = param1;
    FUN_0053edc0(param1);
    param1 = FUN_00557b10(DAT_00727c3c);
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
    if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(iVar2 + 0x14) + static_cast<int>(uVar1));
    }
    FUN_005606f0(uVar1, &param1);
    return;
}

// 0x551810 — observed shape: in_ECX receiver, 9 params; allocates 0x54 via FUN_00533c78; on null calls FUN_00551730(0) and sets vtable, else forwards 9 params to FUN_00556650 then FUN_00551730(result) and sets *self = PTR_FUN_006c2478.
void FUN_00551810(void* self, uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7, uint32_t p8, uint32_t p9) {
    int iVar1 = FUN_00533c78(0x54);
    if (iVar1 == 0) {
        FUN_00551730(0, self);
        *static_cast<uint32_t*>(self) = reinterpret_cast<uint32_t>(PTR_FUN_006c2478);
        return;
    }
    uint32_t uVar2 = FUN_00556650(p1, p2, p3, p4, p5, p6, p7, p8, p9);
    FUN_00551730(uVar2, self);
    *static_cast<uint32_t*>(self) = reinterpret_cast<uint32_t>(PTR_FUN_006c2478);
    return;
}

// 0x551880 — observed shape: in_ECX receiver + param; calls FUN_00551730(param), sets *self = PTR_FUN_006c2478.
void FUN_00551880(uint32_t param, void* self) {
    FUN_00551730(param, self);
    *static_cast<uint32_t*>(self) = reinterpret_cast<uint32_t>(PTR_FUN_006c2478);
    return;
}

// 0x5518a0 — observed shape: in_ECX receiver; calls FUN_00551750(), sets *self = PTR_FUN_006c2478.
void FUN_005518a0(void* self) {
    FUN_00551750(self);
    *static_cast<uint32_t*>(self) = reinterpret_cast<uint32_t>(PTR_FUN_006c2478);
    return;
}

// 0x5518c0 — observed shape: int* param; calls FUN_0053e760(param), then vfunc at (*param + 200) with no args.
void FUN_005518c0(int* param) {
    FUN_0053e760(param);
    using Fn = void(__thiscall*)(int*);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(*param + 200));
    fn(param);
    return;
}

// 0x551930 — observed shape: in_ECX receiver + byte param; calls FUN_00551770(), operator_delete if (param & 1).
void FUN_00551930(void* self, uint8_t param1) {
    FUN_00551770(self);
    if ((param1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}
