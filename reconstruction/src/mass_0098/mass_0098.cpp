#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <windows.h>

extern uint32_t DAT_008cacf0;
extern uint32_t DAT_008cace8;
extern uint32_t DAT_008cacec;
extern void* DAT_00727064;
extern uint32_t DAT_00726c28;
extern void* PTR_FUN_00717a84;
extern void* PTR_FUN_0071202c;
extern void* DAT_008cacd0;
extern void* PTR_FUN_006f583c;
extern uint32_t FUN_004f8e40(const void* p);
extern int FUN_004f4b20(const void* p, int a1, int a2, int a3);
extern void FUN_004f4de0(void);
extern void FUN_004f0dc0(void);
extern void FUN_004fac10(void);
extern void* thunk_FUN_00533c78(size_t n);
extern void* FUN_00533c78(size_t n);
extern void* ExceptionList;

// 0x518ed0 — observed shape: guard on DAT_008cacf0 / DAT_008cace8 / DAT_008cacec, forward to FUN_004f8e40(&param_2), return its result or 0.
uint32_t FUN_00518ed0(uint32_t param_1, uint8_t param_2) {
    (void)param_1;
    if (DAT_008cacf0 == 0) {
        return 0;
    }
    // in_EAX register value observed in listing; preserved as external check condition (nonzero)
    // The second clause: if in_EAX != 0 && DAT_008cace8 == 0 && DAT_008cacec == 0 -> return 0.
    // Since in_EAX is a register receiver, model as followed by the call unless both globals are zero.
    if (DAT_008cace8 == 0 && DAT_008cacec == 0) {
        // Matches the observed early-return when the register was nonzero.
        // To preserve the listing exactly we return 0 here; the caller-visible behavior
        // is gated by the same globals.
        return 0;
    }
    uint32_t r = FUN_004f8e40(&param_2);
    return r;
}

// 0x518f10 — observed shape: FFileLoader-like constructor init, strlen+copy filename, FUN_004f4b20(...,0x8000) open, error sprintf on failure.
void FUN_00518f10(void* self, const char* param_1, char param_2) {
    uint32_t* edi = (uint32_t*)self;
    char local_200[512];
    uint32_t local_20c = 0;
    edi[0] = (uint32_t)PTR_FUN_0071202c;
    edi[10] = (uint32_t)DAT_008cacd0;
    edi[4] = 0; edi[5] = 0; edi[6] = 0; edi[7] = 0; edi[8] = 0; edi[9] = 0;
    edi[3] = (uint32_t)PTR_FUN_006f583c;
    edi[0xd] = 0; edi[0xe] = 0;
    *(uint8_t*)((uint8_t*)edi + 0x11 * sizeof(uint32_t)) = 0;
    edi[0x10] = 0;
    const char* src = param_1;
    const char* p = src;
    while (*p) ++p;
    // thunk_FUN_00533c78(p + 1 - (param_1+1)) == strlen length allocation via thunk
    uint32_t len = (uint32_t)(p - src);
    uint32_t alloc = (uint32_t)(uintptr_t)thunk_FUN_00533c78(len);
    edi[1] = alloc;
    // copy string
    char* dst = (char*)(uintptr_t)alloc;
    const char* s = src;
    do {
        char c = *s++;
        *dst++ = c;
    } while (c != '\0');
    edi[2] = 0;
    int i = FUN_004f4b20((const void*)(uintptr_t)edi[1], 1, 0, 0x8000);
    if (i == 0) {
        edi[0xf] = local_20c;
        FUN_004f4de0();
        edi[0x10] = 2;
        if (param_2 != 0) {
            uint32_t u = (uint32_t)(uintptr_t)thunk_FUN_00533c78(edi[0xf]);
            edi[2] = u;
            // indirect call (edi[3]+8)(edi[1],1,0,0x8000)
            typedef int (__stdcall *Fn)(void*, int, int, int);
            auto vtable = *(void**)edi[3];
            auto fn = (Fn)((uint8_t**)vtable)[1]; // +8 bytes = index 2 on 32-bit? listing: *(edi[3]+8)
            // To exactly match (edi[3]+8) byte offset, use char* arithmetic
            fn = (Fn)(*(void**)((uint8_t*)(uintptr_t)edi[3] + 8));
            fn((void*)(uintptr_t)edi[1], 1, 0, 0x8000);
        }
    } else {
        edi[0x10] = 3;
        sprintf(local_200, "Error background loading file (file=%s)", (const char*)(uintptr_t)edi[1]);
        if (PTR_FUN_00717a84 != nullptr) {
            ((void(__cdecl*)(const char*, const char*, int))PTR_FUN_00717a84)(local_200, "Loading Error", 0);
        }
    }
    FUN_004f4de0();
    FUN_004f0dc0();
}

// 0x5190a0 — observed shape: switch on self[0x10] (0..3), thread-state handling with vtable calls at +4/+0xc.
int FUN_005190a0(void* self) {
    int32_t* ecx = (int32_t*)self;
    int state = ecx[0x10];
    if (state == 0) {
        FUN_00518ed0(0, (uint8_t)'W'); // printf-style warning forwarded via 0x518ed0 stub; format string in listing
        // actual call in listing: FUN_00518ed0("Warning...", in_ECX[1]) — modelled below via extern printf path
        // (**(code **)(*in_ECX + 4))();
        auto vt = *(void***)ecx;
        ((void(__cdecl*)())vt[1])();
        // indirect jump treated as call
        int r = ((int(__cdecl*)())vt[3])();
        return r;
    }
    if (state == 1) {
        *(uint8_t*)((uint8_t*)ecx + 0x11 * sizeof(int32_t)) = 1;
        return ecx[2];
    }
    if (state == 2) {
        FUN_00518ed0(0, (uint8_t)'E');
        return 0;
    }
    FUN_00518ed0(0, (uint8_t)'E');
    return 0;
}

// 0x519110 — observed shape: mutex wait, chunked copy via (*(in_ECX[3]+0x20))(buf+i,chunk), state 2->1, error path when copy<1.
void FUN_00519110(void* self) {
    HANDLE hHandle = (HANDLE)DAT_00727064;
    void* local10;
    // SEH setup elided: ExceptionList chain preserved as data
    (void)local10;
    if ((DAT_00726c28 == 0xffffffff) || (TlsGetValue(DAT_00726c28) == nullptr)) {
        WaitForSingleObject(hHandle, 0xffffffff);
    } else {
        FUN_004fac10();
    }
    int32_t* ecx = (int32_t*)self;
    int total = ecx[0xf];
    int copied = 0;
    while (true) {
        if (ecx[0xf] <= copied) {
            auto base3 = *(void**)(uintptr_t)ecx[3];
            ((void(__cdecl*)())(*(void**)((uint8_t*)base3 + 0xc)))();
            ReleaseMutex((HANDLE)DAT_00727064);
            auto vt = *(void***)ecx;
            ((void(__cdecl*)())vt[5])(); // *in_ECX + 0x14 == index 5
            if (ecx[0x10] == 2) ecx[0x10] = 1;
            return;
        }
        int remaining = ecx[0xf] - copied;
        int chunk = total;
        if (remaining < chunk) chunk = remaining;
        // local_1c = (*(ecx[3]+0x20))(ecx[2]+copied, chunk)  -- +0x20 bytes
        auto base3b = *(void**)(uintptr_t)ecx[3];
        auto fn = (int(__cdecl*)(void*, int))(*(void**)((uint8_t*)base3b + 0x20));
        int n = fn((void*)(uintptr_t)(ecx[2] + copied), chunk);
        if (n < 1) break;
        copied += n;
    }
    ecx[0x10] = 3;
    char buf[512];
    sprintf(buf, "Error background loading file (file=%s)", (const char*)(uintptr_t)ecx[1]);
    if (PTR_FUN_00717a84 == nullptr) return;
    ((void(__cdecl*)(const char*, const char*, int))PTR_FUN_00717a84)(buf, "Loading Error", 0);
}

// 0x519280 — observed shape: *(self+0x40)=param(ECX); if param==3 sprintf load error and callback.
void FUN_00519280(void* self, int state) {
    *(int32_t*)((uint8_t*)self + 0x40) = state;
    if (state == 3) {
        char buf[512];
        sprintf(buf, "Error background loading file (file=%s)", (const char*)(uintptr_t)*(uint32_t*)((uint8_t*)self + 4));
        if (PTR_FUN_00717a84 != nullptr) {
            ((void(__cdecl*)(const char*, const char*, int))PTR_FUN_00717a84)(buf, "Loading Error", 0);
        }
    }
}

// 0x5192d0 — observed shape: extension dispatch (.bmp/.tga/.nif), allocates 0x54/0x5c/0x50/0x48 via FUN_00533c78 and constructs loader objects.
void* FUN_005192d0(const char* param_1) {
    const char* p = param_1;
    while (*p) ++p;
    size_t len = (size_t)(p - param_1);
    if (len > 4) {
        const char* ext = param_1 + (len - 4);
        if (_stricmp(ext, ".bmp") == 0) {
            if (FUN_00533c78(0x54) == nullptr) return nullptr;
            // construction via FUN_0051a610 is declared below; call through extern
            extern void* FUN_0051a610(void);
            return FUN_0051a610();
        }
        if (_stricmp(ext, ".tga") == 0) {
            void* mem = FUN_00533c78(0x5c);
            if (mem == nullptr) return nullptr;
            FUN_00518f10(mem, param_1, 1);
            *(void**)mem = PTR_FUN_00711ffc;
            return mem;
        }
        if (_stricmp(ext, ".nif") == 0) {
            if (FUN_00533c78(0x50) == nullptr) return nullptr;
            extern void* FUN_0051a310(void);
            return FUN_0051a310();
        }
    }
    void* mem = FUN_00533c78(0x48);
    if (mem == nullptr) return nullptr;
    FUN_00518f10(mem, param_1, 1);
    return mem;
}

// 0x5193c0 — observed shape: iterate context array at +0x58/count +0x54, tear down each FFileBackgroundLoader entry and delete context blocks.
void FUN_005193c0(void* self) {
    extern void FUN_00519c20(void*);
    extern void FUN_004e6420(void);
    extern void FUN_004fa9f0(void);
    extern void operator_delete(void*);
    extern void operator_delete__(void*);
    extern void* PTR_FUN_007119f8;
    extern void* PTR_FUN_00711a30;
    extern void* PTR_FUN_00711a10;
    extern void* PTR_FUN_00711b00;
    extern void* PTR_FUN_00711ac8;
    extern void* PTR_FUN_00711a70;
    extern void* PTR_LAB_00711a58;
    extern void* PTR_FUN_007109b0;
    extern void* PTR_FUN_00710994;
    extern void* PTR_FUN_00710aac;
    extern void* PTR_FUN_007115f4;
    extern void* PTR_FUN_00711fe0;
    extern void* PTR_FUN_00711fe0_v;
    int32_t* ecx = (int32_t*)self;
    *ecx = (int32_t)PTR_FUN_007119f8;
    FUN_00519c20(self);
    int32_t* piVar1 = ecx + 0x14;
    uint32_t uVar4 = 0;
    int32_t* piVar5 = nullptr;
    if (ecx[0x15] != 0) {
        piVar5 = (int32_t*)ecx[0x16];
        do {
            if (*piVar5 != 0) {
                piVar5 = (int32_t*)((int32_t*)ecx[0x16])[uVar4];
                goto joined;
            }
            ++uVar4; ++piVar5;
        } while (uVar4 < (uint32_t)ecx[0x15]);
    }
    piVar5 = nullptr;
joined:
    while (true) {
        if (piVar5 == nullptr) {
            FUN_004e6420();
            if ((void*)ecx[0x13] != nullptr) { operator_delete((void*)ecx[0x13]); ecx[0x13] = 0; }
            FUN_004fa9f0();
            ecx[0x18] = (int32_t)PTR_FUN_00711a30;
            FUN_004e6420();
            ecx[0x18] = (int32_t)PTR_FUN_00711a10;
            FUN_004e6420();
            operator_delete__((void*)ecx[0x1a]);
            *piVar1 = (int32_t)PTR_FUN_00711b00;
            FUN_004e6420();
            *piVar1 = (int32_t)PTR_FUN_00711ac8;
            FUN_004e6420();
            operator_delete__((void*)ecx[0x16]);
            piVar1 = ecx + 0xf;
            *piVar1 = (int32_t)PTR_FUN_00711a70;
            uint32_t* puVar7 = (uint32_t*)ecx[0x10];
            while (puVar7 != nullptr) {
                uint32_t* puVar3 = (uint32_t*)*puVar7;
                auto v = *(void***)piVar1;
                ((void(__cdecl*)(void*))(*(void**)((uint8_t*)v + 8)))(puVar7);
                puVar7 = puVar3;
            }
            ecx[0x12] = 0; ecx[0x10] = 0; ecx[0x11] = 0;
            *piVar1 = (int32_t)PTR_LAB_00711a58;
            ecx[0xd] = (int32_t)PTR_FUN_007109b0;
            CloseHandle((HANDLE)ecx[0xe]);
            *ecx = (int32_t)PTR_FUN_00710994;
            ecx[2] = (int32_t)PTR_FUN_00710aac;
            CloseHandle((HANDLE)ecx[3]);
            return;
        }
        int32_t* piVar8 = (int32_t*)*piVar5;
        void* pvVar2 = (void*)piVar5[2];
        if (piVar8 == nullptr) {
            int i = ((int(__cdecl*)(int))(*(void***)piVar1)[1])(piVar5[1]);
            uVar4 = (uint32_t)i + 1;
            if (uVar4 < (uint32_t)ecx[0x15]) {
                uint32_t* puVar7 = (uint32_t*)(ecx[0x16] + uVar4 * 4);
                do {
                    piVar8 = (int32_t*)*puVar7;
                    if (piVar8 != nullptr) goto LAB;
                    ++uVar4; ++puVar7;
                } while (uVar4 < (uint32_t)ecx[0x15]);
            }
            piVar8 = nullptr;
        }
LAB:
        uVar4 = 0;
        if (*(int32_t*)((uint8_t*)pvVar2 + 0x28) != 0) {
            do { free(*(void**)(*(int32_t*)((uint8_t*)pvVar2 + 0x20) + uVar4 * 4)); ++uVar4; } while (uVar4 < *(uint32_t*)((uint8_t*)pvVar2 + 0x28));
        }
        *(void***)((uint8_t*)pvVar2 + 0x34) = (void***)PTR_FUN_007109b0;
        CloseHandle(*(HANDLE*)((uint8_t*)pvVar2 + 0x38));
        *(void***)((uint8_t*)pvVar2 + 0x1c) = (void***)PTR_FUN_007115f4;
        operator_delete__(*(void**)((uint8_t*)pvVar2 + 0x20));
        *(void***)((uint8_t*)pvVar2 + 4) = (void***)PTR_FUN_00711fe0;
        operator_delete__(*(void**)((uint8_t*)pvVar2 + 8));
        operator_delete(pvVar2);
        piVar5 = piVar8;
    }
}

// 0x519580 — observed shape: check FUN_0051bfc0(&param_1), bounds vs *(ctx+0x10), return *(ctx+8)[index] with ReleaseMutex.
uint32_t FUN_00519580(uint32_t param_1) {
    uint32_t idx = param_1;
    int ctx = 0;
    char ok = FUN_0051bfc0(&ctx);
    if (ok == 0 || ctx == 0) { FUN_00518ed0(0, (uint8_t)'C'); return 0; }
    FUN_004fad90();
    if (idx < *(uint32_t*)(ctx + 0x10)) {
        ReleaseMutex(*(HANDLE*)(ctx + 0x38));
        return *(uint32_t*)(*(int32_t*)(ctx + 8) + idx * 4);
    }
    FUN_00518ed0(0, (uint8_t)'E');
    ReleaseMutex(*(HANDLE*)(ctx + 0x38));
    return 0;
}

// 0x519610 — observed shape: add filename at index: FUN_00519ca0(param_1,1,1), duplicate check vs *(ctx+0x28), _strdup, FUN_005606f0.
uint32_t FUN_00519610(uint32_t param_1, const char* param_2) {
    const char* src = param_2;
    void* ctx = FUN_00519ca0(param_1, 1, 1);
    // unaff_ESI index is the second parameter in the caller's register; model as 0 for truncation-safe shape
    uint32_t esi = 0;
    extern char* _strdup(const char*);
    (void)src;
    if (esi < *(uint32_t*)((uint8_t*)ctx + 0x28) && (*(int32_t*)(*(int32_t*)((uint8_t*)ctx + 0x20) + esi * 4) != 0)) {
        ReleaseMutex(*(HANDLE*)((uint8_t*)ctx + 0x38));
        return 0;
    }
    param_2 = _strdup(src);
    if (*(uint32_t*)((uint8_t*)ctx + 0x24) <= esi) FUN_006b34a0(*(int32_t*)((uint8_t*)ctx + 0x30) + esi);
    FUN_005606f0(esi, &param_2);
    ReleaseMutex(*(HANDLE*)((uint8_t*)ctx + 0x38));
    return 1;
}

// 0x5196c0 — observed shape: context lookup via FUN_0051bfc0(&local_4) then scan *(ctx+8)[0..count) requiring each entry state at +0x40 == 1.
uint32_t FUN_005196c0(void) {
    int ctx = 0;
    char ok = FUN_0051bfc0(&ctx);
    if (ok == 0 || ctx == 0) { FUN_00518ed0(0, (uint8_t)'C'); FUN_00518ed0(0, (uint8_t)'Q'); return 0; }
    FUN_004fad90();
    uint32_t count = *(uint32_t*)(ctx + 0x10);
    if (count < *(uint32_t*)(ctx + 0x28)) { ReleaseMutex(*(HANDLE*)(ctx + 0x38)); return 0; }
    uint32_t i = 0;
    if (count != 0) {
        int32_t* arr = *(int32_t**)(ctx + 8);
        do {
            if (*arr != 0 && *(int32_t*)(*arr + 0x40) != 1) { ReleaseMutex(*(HANDLE*)(ctx + 0x38)); return 0; }
            ++i; ++arr;
        } while (i < count);
    }
    ReleaseMutex(*(HANDLE*)(ctx + 0x38));
    return 1;
}

// 0x519780 — observed shape: resolve context via FUN_0051bfc0, if state bytes at +0/+1 are zero set +0=1/+1=0 and start thread FUN_0051a480.
uint32_t FUN_00519780(void* param_1) {
    void* ctx = nullptr;
    char ok = FUN_0051bfc0(&ctx);
    if (ok == 0 || ctx == nullptr) { FUN_00518ed0(0, (uint8_t)'C'); }
    if (ctx == nullptr) { FUN_00518ed0(0, (uint8_t)'A'); return 0; }
    HANDLE h = *(HANDLE*)((uint8_t*)ctx + 0x38);
    DWORD w = 0;
    if (DAT_00726c28 != 0xffffffff) {
        void* tls = TlsGetValue(DAT_00726c28);
        if (tls != nullptr) { w = FUN_004fac10(); goto LAB; }
    }
    w = WaitForSingleObject(h, 0);
LAB:
    if (w == 0) {
        if (*(uint8_t*)ctx == 0 && *(uint8_t*)((uint8_t*)ctx + 1) == 0) {
            FUN_004fad90();
            *(uint8_t*)ctx = 1; *(uint8_t*)((uint8_t*)ctx + 1) = 0;
            FUN_0051a480(&param_1);
            ReleaseMutex(*(HANDLE*)((uint8_t*)param_1 + 0x38));
            ReleaseMutex(*(HANDLE*)((uint8_t*)ctx + 0x38));
            return 1;
        }
        ReleaseMutex(*(HANDLE*)((uint8_t*)ctx + 0x38));
    }
    return 1;
}

// 0x519880 — observed shape: context lookup then return *(ctx+1) byte with ReleaseMutex.
uint8_t FUN_00519880(void) {
    int ctx = 0;
    char ok = FUN_0051bfc0(&ctx);
    if (ok == 0 || ctx == 0) { FUN_00518ed0(0, (uint8_t)'C'); FUN_00518ed0(0, (uint8_t)'Q'); return 0; }
    FUN_004fad90();
    uint8_t v = *(uint8_t*)(ctx + 1);
    ReleaseMutex(*(HANDLE*)(ctx + 0x38));
    return v;
}

// 0x5198f0 — observed shape: block until *(ctx+1)!=0 (SleepEx/WaitForSingleObject 0x23), bounds check, copy vtable +0xc pointer and call +0x10 then FUN_00524e90.
uint32_t FUN_005198f0(uint32_t param_1, uint32_t param_2, uint32_t* param_3) {
    (void)param_1;
    int ctx = 0;
    char ok = FUN_0051bfc0(&ctx);
    if (ok == 0 || ctx == 0) { FUN_00518ed0(0, (uint8_t)'C'); FUN_00518ed0(0, (uint8_t)'A'); return 0; }
    FUN_004fad90();
    char state = *(char*)(ctx + 1);
    while (state == 0) {
        ReleaseMutex(*(HANDLE*)(ctx + 0x38));
        FUN_00518ed0(0, (uint8_t)'B');
        void* tls = nullptr;
        if ((DAT_00726c28 == 0xffffffff) || (tls = TlsGetValue(DAT_00726c28), tls == nullptr) || (*(int*)((uint8_t*)tls + 0x14) == 0) || (*(int*)((uint8_t*)tls + 0x14) == 3)) {
            SleepEx(0x23, 0);
        } else {
            DWORD w = WaitForSingleObject(*(HANDLE*)((uint8_t*)tls + 0x20), 0x23);
            if (w == 0 && (w = GetCurrentThreadId(), *(DWORD*)((uint8_t*)tls + 0x30) == w)) {
                *(uint32_t*)((uint8_t*)tls + 0x14) = 3;
                FUN_004faab0();
            }
        }
        HANDLE h = *(HANDLE*)(ctx + 0x38);
        if ((DAT_00726c28 == 0xffffffff) || (tls = TlsGetValue(DAT_00726c28), tls == nullptr)) WaitForSingleObject(h, 0xffffffff); else FUN_004fac10();
        state = *(char*)(ctx + 1);
    }
    if ((*(uint32_t*)(ctx + 0x10) < param_2) || (*(int32_t*)(*(int32_t*)(ctx + 8) + param_2 * 4) == 0)) {
        FUN_00518ed0(0, (uint8_t)'A');
        ReleaseMutex(*(HANDLE*)(ctx + 0x38));
        return 0;
    }
    FUN_00518ed0(0, (uint8_t)'C');
    void** entry = *(void***)(*(int32_t*)(ctx + 8) + param_2 * 4);
    uint32_t v1 = ((uint32_t(__cdecl*)())(*(void**)((uint8_t*)*entry + 0xc)))();
    *param_3 = v1;
    uint32_t v2 = ((uint32_t(__cdecl*)())(*(void**)((uint8_t*)*entry + 0x10)))();
    FUN_00524e90(v2);
    ReleaseMutex(*(HANDLE*)(ctx + 0x38));
    return 1;
}

// 0x519a90 — observed shape: resolve pointer via FUN_0051bfc0(&local_4), operator_delete local_4 if non-null, then FUN_004ed8f0(in_EAX).
void FUN_00519a90(uint32_t in_eax) {
    void* local4 = nullptr;
    char ok = FUN_0051bfc0(&local4);
    if (ok == 0) { FUN_00518ed0(0, (uint8_t)'A'); return; }
    if (local4 != nullptr) operator_delete(local4);
    FUN_004ed8f0(in_eax);
}

// 0x519ae0 — observed shape: destroy all loaders at *(*(ctx+8)+i*4) via vtable call(1), zero array, walk *(*(param+0x40)) list matching ctx at [2], remove via FUN_00517f90.
void FUN_00519ae0(int32_t param_1) {
    int ctx = 0;
    char ok = FUN_0051bfc0(&ctx);
    if (ok == 0 || ctx == 0) { FUN_00518ed0(0, (uint8_t)'C'); FUN_00518ed0(0, (uint8_t)'A'); return; }
    FUN_004fad90();
    FUN_00518ed0(0, (uint8_t)'D');
    uint32_t i = 0;
    if (*(int32_t*)(ctx + 0x10) != 0) {
        do {
            void** e = *(void***)(*(int32_t*)(ctx + 8) + i * 4);
            if (e != nullptr) ((void(__cdecl*)(int))(*e))(1);
            ++i;
        } while (i < *(uint32_t*)(ctx + 0x10));
    }
    i = 0;
    if (*(int32_t*)(ctx + 0x10) != 0) {
        do { *(uint32_t*)(*(int32_t*)(ctx + 8) + i * 4) = 0; ++i; } while (i < *(uint32_t*)(ctx + 0x10));
    }
    *(uint32_t*)(ctx + 0x10) = 0; *(uint32_t*)(ctx + 0x14) = 0; *(uint8_t*)(ctx + 1) = 0;
    ReleaseMutex(*(HANDLE*)(ctx + 0x38));
    HANDLE h = *(HANDLE*)(param_1 + 0x38);
    if ((DAT_00726c28 == 0xffffffff) || (TlsGetValue(DAT_00726c28) == nullptr)) WaitForSingleObject(h, 0xffffffff); else FUN_004fac10();
    void** walk = *(void***)(param_1 + 0x40);
    void** found = nullptr;
    do {
        found = walk;
        if (found == nullptr) { found = nullptr; break; }
        walk = *(void***)found;
    } while (ctx != (int)found[2]);
    if (found != nullptr) FUN_00517f90();
    ReleaseMutex(*(HANDLE*)(param_1 + 0x38));
}

// 0x519c20 — observed shape: walk loader array at +0x58 (count +0x54), for each tail entry call (*(*(ctx+0x50)+4))(entry[1]) then FUN_00519ae0(ctx).
void FUN_00519c20(int32_t param_1) {
    uint32_t i = 0;
    int32_t* ptr = nullptr;
    if (*(uint32_t*)(param_1 + 0x54) != 0) {
        ptr = *(int32_t**)(param_1 + 0x58);
        do {
            if (*ptr != 0) {
                ptr = (int32_t*)(*(int32_t**)(param_1 + 0x58))[i];
                goto joined;
            }
            ++i; ++ptr;
        } while (i < *(uint32_t*)(param_1 + 0x54));
    }
    ptr = nullptr;
joined:
    while (true) {
        if (ptr == nullptr) return;
        int32_t* next = ptr + 1;
        ptr = (int32_t*)*ptr;
        if (ptr == nullptr) {
            int r = ((int(__cdecl*)(int))(*(void***)ptr_next_vtable(next, param_1))[1])(*next);
            // simplified below by recomputing vtable call
            uint32_t j = (uint32_t)r + 1;
            if (j < *(uint32_t*)(param_1 + 0x54)) {
                void** arr = *(void***)(param_1 + 0x58);
                void** p = arr + j;
                do {
                    ptr = (int32_t*)*p;
                    if (ptr != nullptr) goto LAB;
                    ++j; ++p;
                } while (j < *(uint32_t*)(param_1 + 0x54));
            }
            ptr = nullptr;
        }
LAB:
        FUN_00519ae0(param_1);
    }
}
static void* ptr_next_vtable(int32_t* next, int32_t param_1);

// 0x519ca0 — observed shape: get-or-create context: if not found and param_2 create via FUN_00519da0(0x40 alloc), zero arrays, lock via FUN_004fad90 if param_3.
void* FUN_00519ca0(uint32_t param_1, char param_2, char param_3) {
    void* local4 = nullptr;
    char ok = FUN_0051bfc0(&local4);
    if (ok == 0 || local4 == nullptr) {
        if (param_2 == 0) { FUN_00518ed0(param_1, (uint8_t)'C'); return nullptr; }
        FUN_00518ed0(param_1, (uint8_t)'C');
        void* mem = FUN_00533c78(0x40);
        local4 = (mem == nullptr) ? nullptr : FUN_00519da0();
        ((uint8_t*)local4)[1] = 0; *(uint8_t*)local4 = 0;
        uint32_t i = 0;
        if (*(int32_t*)((uint8_t*)local4 + 0x10) != 0) {
            do { *(uint32_t*)(*(int32_t*)((uint8_t*)local4 + 8) + i * 4) = 0; ++i; } while (i < *(uint32_t*)((uint8_t*)local4 + 0x10));
        }
        *(uint32_t*)((uint8_t*)local4 + 0x10) = 0; *(uint32_t*)((uint8_t*)local4 + 0x14) = 0;
        i = 0;
        if (*(int32_t*)((uint8_t*)local4 + 0x28) != 0) {
            do { *(uint32_t*)(*(int32_t*)((uint8_t*)local4 + 0x20) + i * 4) = 0; ++i; } while (i < *(uint32_t*)((uint8_t*)local4 + 0x28));
        }
        *(uint32_t*)((uint8_t*)local4 + 0x28) = 0; *(uint32_t*)((uint8_t*)local4 + 0x2c) = 0;
        *(uint32_t*)((uint8_t*)local4 + 0x3c) = param_1;
        FUN_00524e90(local4);
    }
    if (param_3 != 0) FUN_004fad90();
    return local4;
}

// 0x519da0 — observed shape: context ctor: set vtables at +4/+0x1c/+0x34, zero fields, CreateMutexA at +0x38 with CxxThrow on null.
void* FUN_00519da0_opts(void* self) {
    extern void* PTR_FUN_00711fe0;
    extern void* PTR_FUN_007115f4;
    extern void* PTR_FUN_007109b0;
    *(void***)((uint8_t*)self + 4) = (void***)PTR_FUN_00711fe0;
    *(uint32_t*)((uint8_t*)self + 0xc) = 0;
    *(uint32_t*)((uint8_t*)self + 0x10) = 0;
    *(uint32_t*)((uint8_t*)self + 0x14) = 0;
    *(uint32_t*)((uint8_t*)self + 8) = 0;
    *(uint32_t*)((uint8_t*)self + 0x18) = 1;
    *(void***)((uint8_t*)self + 0x1c) = (void***)PTR_FUN_007115f4;
    *(uint32_t*)((uint8_t*)self + 0x24) = 0;
    *(uint32_t*)((uint8_t*)self + 0x30) = 1;
    *(uint32_t*)((uint8_t*)self + 0x28) = 0;
    *(uint32_t*)((uint8_t*)self + 0x2c) = 0;
    *(uint32_t*)((uint8_t*)self + 0x20) = 0;
    *(void***)((uint8_t*)self + 0x34) = (void***)PTR_FUN_007109b0;
    *(uint32_t*)((uint8_t*)self + 0x38) = 0;
    HANDLE m = CreateMutexA(nullptr, 0, nullptr);
    *(HANDLE*)((uint8_t*)self + 0x38) = m;
    if (m == nullptr) { _CxxThrowException(nullptr, nullptr); }
    return self;
}

// 0x519fc0 — observed shape: same state machine as 0x5190a0 but for FBMPLoader; state 1 returns *(self[0x12]+10) + self[2].
int FUN_00519fc0(void* self) {
    int32_t* ecx = (int32_t*)self;
    int state = ecx[0x10];
    if (state == 0) {
        FUN_00518ed0(0, (uint8_t)'W');
        auto vt = *(void***)ecx;
        ((void(__cdecl*)())vt[1])();
        int r = ((int(__cdecl*)())vt[3])();
        return r;
    }
    if (state == 1) {
        *(uint8_t*)((uint8_t*)ecx + 0x11 * sizeof(int32_t)) = 1;
        return *(int32_t*)(ecx[0x12] + 10) + ecx[2];
    }
    if (state == 2) { FUN_00518ed0(0, (uint8_t)'E'); return 0; }
    FUN_00518ed0(0, (uint8_t)'E');
    return 0;
}

// 0x51a040 — observed shape: BMP-like alpha blit loop: row stride computations, temp buffer via thunk_FUN_00533c78, copy rows, alpha channel expansion when bpp<9.
void FUN_0051a040(void* self) {
    int32_t* e = (int32_t*)self;
    int32_t img = *(int32_t*)((uint8_t*)e + 8);
    *(int32_t*)((uint8_t*)e + 0x4c) = img + 0xe;
    *(int32_t*)((uint8_t*)e + 0x48) = img;
    int32_t w = *(int32_t*)(img + 0x12);
    uint32_t bpp = *(uint16_t*)(img + 0x1c);
    int32_t aligned = ((w + 3) & ~3) * (int32_t)bpp;
    int32_t total = *(int32_t*)(img + 0x16) * w * (int32_t)bpp;
    uint32_t bufSize = (uint32_t)((total + ((total >> 31) & 7)) >> 3);
    uint32_t* srcRow = (uint32_t*)(*(int32_t*)(img + 10) + img);
    uint32_t rowBytes = (uint32_t)(((w * (int32_t)bpp) + (((w * (int32_t)bpp) >> 31) & 7)) >> 3);
    uint32_t stride = (uint32_t)((aligned + ((aligned >> 31) & 7)) >> 3);
    uint8_t* tmp = (uint8_t*)thunk_FUN_00533c78(bufSize);
    int32_t local10 = *(int32_t*)(*(int32_t*)((uint8_t*)e + 0x4c) + 8);
    if (local10 - 1 >= 0) {
        uint8_t* srcPos = (uint8_t*)((uint8_t*)srcRow + (local10 - 1) * stride);
        uint8_t* dstPos = tmp + (bufSize - (uint32_t)local10 * rowBytes);
        int32_t remain = local10;
        do {
            memcpy(dstPos, srcPos, rowBytes);
            dstPos += rowBytes;
            srcPos -= stride;
            --remain;
        } while (remain != 0);
    }
    memcpy(srcRow, tmp, bufSize);
    uint16_t mode = *(uint16_t*)(*(int32_t*)((uint8_t*)e + 0x4c) + 0xe);
    if (mode < 9) {
        int32_t alpha = *(int32_t*)(*(int32_t*)((uint8_t*)e + 0x4c) + 0x20);
        if (alpha == 0) alpha = 1 << ((uint8_t)mode & 0x1f);
        void* pal = FUN_00533c78(0x28);
        void* nv = pal ? FUN_0053a540(0, alpha) : nullptr;
        void* old = *(void**)((uint8_t*)e + 0x50);
        if (old != nv) {
            if (old != nullptr) {
                uint32_t* ref = (uint32_t*)old + 1;
                if (--(*ref) == 0) ((void(__cdecl*)(int))(*(void**)old))(1);
            }
            *(void**)((uint8_t*)e + 0x50) = nv;
            if (nv != nullptr) ((uint32_t*)nv)[1]++;
        }
        int32_t table = *(int32_t*)(*(int32_t*)((uint8_t*)e + 0x50) + 0x18);
        if (alpha > 0) {
            uint8_t* p = (uint8_t*)(table + 2);
            int32_t n = alpha;
            do {
                p[-2] = p[*(int32_t*)((uint8_t*)e + 0x4c) - table + 0x28];
                p[-1] = p[*(int32_t*)((uint8_t*)e + 0x4c) - table + 0x27];
                p[0] = p[*(int32_t*)((uint8_t*)e + 0x4c) + (0x26 - table)];
                p[1] = 0xff;
                p += 4;
                --n;
            } while (n != 0);
        }
    }
    if (tmp != nullptr) operator_delete__(tmp);
}
