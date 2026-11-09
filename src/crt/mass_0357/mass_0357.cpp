// Reconstruction batch mass_0357 — unverified decompiler-derived candidate.
// No compiler, build, or test was run. Corpus: analysis/pseudocode/functions/<addr>.c
// Provider: Ghidra 12.2 (ghidra), PE32 i386, image
// 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9.
// These are global-slot refcount-release helpers: the slot payload carries its
// intrusive refcount at +0x4 and its virtual-destructor pointer at vtable[0].

#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void __cdecl operator_delete__(void* p);
extern void __cdecl FUN_004e6420(void);

// Sentinels observed as pointer targets / comparison values.
extern uint8_t DAT_008cacc8;
extern uint8_t DAT_008cacd0;

// Global pointer slots.
extern void* PTR_DAT_00726b9c;
extern void* PTR_DAT_00726b98;
extern void* PTR_DAT_00726ba0;
extern void* DAT_008e9fd8;
extern void* DAT_008e9fdc;
extern void* DAT_008e9fe0;
extern void* DAT_008e9fe4;
extern void* DAT_008e9fe8;
extern void* DAT_008e9fec;
extern void* DAT_008e9ff0;
extern void* DAT_008e9ff4;
extern void* DAT_008e9ff8;
extern void* DAT_008e9ffc;
extern void* DAT_008ea000;
extern void* DAT_008ea004;
extern void* DAT_008ea008;
extern void* DAT_008ea00c;
extern void* DAT_008ea010;

// Byte-addressable bases used for descending-slot sweeps.
extern uint8_t DAT_008ea034;
extern uint8_t DAT_008ea048;

// 0x6bf380 slots.
extern void* PTR_PTR_00726ba4;
extern void* PTR_FUN_0070df84;
extern void* PTR_FUN_0070df68;
extern void* DAT_00726bac;

// ---------------------------------------------------------------------------
// 0x6bf120
// 0x6bf120 — observed shape: release two global slots located at slot-8, each
// null-checked and compared against sentinel 0x8cacc8, then reset both slots
// to sentinel 0x8cacd0.
void FUN_6bf120(void)
{
    void* puVar1 = (void*)((uint8_t*)PTR_DAT_00726b9c - 8);
    if (puVar1 != nullptr && puVar1 != (void*)&DAT_008cacc8) {
        operator_delete__(puVar1);
    }
    puVar1 = (void*)((uint8_t*)PTR_DAT_00726b98 - 8);
    PTR_DAT_00726b9c = (void*)&DAT_008cacd0;
    if (puVar1 != nullptr && puVar1 != (void*)&DAT_008cacc8) {
        operator_delete__(puVar1);
    }
    PTR_DAT_00726b98 = (void*)&DAT_008cacd0;
    return;
}

// ---------------------------------------------------------------------------
// 0x6bf170
// 0x6bf170 — observed shape: same slot-8 release for PTR_DAT_00726ba0, then
// reset that single slot to sentinel 0x8cacd0.
void FUN_6bf170(void)
{
    void* puVar1 = (void*)((uint8_t*)PTR_DAT_00726ba0 - 8);
    if (puVar1 != nullptr && puVar1 != (void*)&DAT_008cacc8) {
        operator_delete__(puVar1);
    }
    PTR_DAT_00726ba0 = (void*)&DAT_008cacd0;
    return;
}

// ---------------------------------------------------------------------------
// 0x6bf1a0
// 0x6bf1a0 — observed shape: intrusive-refcount release of DAT_008e9fd8.
// Read slot[1], store slot[1]-1, and when the new count is zero call the
// virtual destructor vtable[0] with argument 1.
void FUN_6bf1a0(void)
{
    void** puVar2 = (void**)DAT_008e9fd8;
    if (DAT_008e9fd8 != nullptr) {
        int32_t iVar1 = (int32_t)(intptr_t)puVar2[1];
        puVar2[1] = (void*)(intptr_t)(iVar1 - 1);
        if (iVar1 - 1 == 0) {
            typedef void (__cdecl* DestroyFn)(int);
            ((DestroyFn)(*(void***)puVar2)[0])(1);
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x6bf1c0
// 0x6bf1c0 — observed shape: intrusive-refcount release of DAT_008e9fdc;
// zero count triggers vtable[0](1).
void FUN_6bf1c0(void)
{
    void** puVar2 = (void**)DAT_008e9fdc;
    if (DAT_008e9fdc != nullptr) {
        int32_t iVar1 = (int32_t)(intptr_t)puVar2[1];
        puVar2[1] = (void*)(intptr_t)(iVar1 - 1);
        if (iVar1 - 1 == 0) {
            typedef void (__cdecl* DestroyFn)(int);
            ((DestroyFn)(*(void***)puVar2)[0])(1);
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x6bf1e0
// 0x6bf1e0 — observed shape: intrusive-refcount release of DAT_008e9fe0;
// zero count triggers vtable[0](1).
void FUN_6bf1e0(void)
{
    void** puVar2 = (void**)DAT_008e9fe0;
    if (DAT_008e9fe0 != nullptr) {
        int32_t iVar1 = (int32_t)(intptr_t)puVar2[1];
        puVar2[1] = (void*)(intptr_t)(iVar1 - 1);
        if (iVar1 - 1 == 0) {
            typedef void (__cdecl* DestroyFn)(int);
            ((DestroyFn)(*(void***)puVar2)[0])(1);
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x6bf200
// 0x6bf200 — observed shape: intrusive-refcount release of DAT_008e9fe4;
// zero count triggers vtable[0](1).
void FUN_6bf200(void)
{
    void** puVar2 = (void**)DAT_008e9fe4;
    if (DAT_008e9fe4 != nullptr) {
        int32_t iVar1 = (int32_t)(intptr_t)puVar2[1];
        puVar2[1] = (void*)(intptr_t)(iVar1 - 1);
        if (iVar1 - 1 == 0) {
            typedef void (__cdecl* DestroyFn)(int);
            ((DestroyFn)(*(void***)puVar2)[0])(1);
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x6bf220
// 0x6bf220 — observed shape: intrusive-refcount release of DAT_008e9fe8;
// zero count triggers vtable[0](1).
void FUN_6bf220(void)
{
    void** puVar2 = (void**)DAT_008e9fe8;
    if (DAT_008e9fe8 != nullptr) {
        int32_t iVar1 = (int32_t)(intptr_t)puVar2[1];
        puVar2[1] = (void*)(intptr_t)(iVar1 - 1);
        if (iVar1 - 1 == 0) {
            typedef void (__cdecl* DestroyFn)(int);
            ((DestroyFn)(*(void***)puVar2)[0])(1);
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x6bf240
// 0x6bf240 — observed shape: intrusive-refcount release of DAT_008e9fec;
// zero count triggers vtable[0](1).
void FUN_6bf240(void)
{
    void** puVar2 = (void**)DAT_008e9fec;
    if (DAT_008e9fec != nullptr) {
        int32_t iVar1 = (int32_t)(intptr_t)puVar2[1];
        puVar2[1] = (void*)(intptr_t)(iVar1 - 1);
        if (iVar1 - 1 == 0) {
            typedef void (__cdecl* DestroyFn)(int);
            ((DestroyFn)(*(void***)puVar2)[0])(1);
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x6bf260
// 0x6bf260 — observed shape: intrusive-refcount release of DAT_008e9ff0;
// zero count triggers vtable[0](1).
void FUN_6bf260(void)
{
    void** puVar2 = (void**)DAT_008e9ff0;
    if (DAT_008e9ff0 != nullptr) {
        int32_t iVar1 = (int32_t)(intptr_t)puVar2[1];
        puVar2[1] = (void*)(intptr_t)(iVar1 - 1);
        if (iVar1 - 1 == 0) {
            typedef void (__cdecl* DestroyFn)(int);
            ((DestroyFn)(*(void***)puVar2)[0])(1);
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x6bf280
// 0x6bf280 — observed shape: intrusive-refcount release of DAT_008e9ff4;
// zero count triggers vtable[0](1).
void FUN_6bf280(void)
{
    void** puVar2 = (void**)DAT_008e9ff4;
    if (DAT_008e9ff4 != nullptr) {
        int32_t iVar1 = (int32_t)(intptr_t)puVar2[1];
        puVar2[1] = (void*)(intptr_t)(iVar1 - 1);
        if (iVar1 - 1 == 0) {
            typedef void (__cdecl* DestroyFn)(int);
            ((DestroyFn)(*(void***)puVar2)[0])(1);
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x6bf2a0
// 0x6bf2a0 — observed shape: intrusive-refcount release of DAT_008e9ff8;
// zero count triggers vtable[0](1).
void FUN_6bf2a0(void)
{
    void** puVar2 = (void**)DAT_008e9ff8;
    if (DAT_008e9ff8 != nullptr) {
        int32_t iVar1 = (int32_t)(intptr_t)puVar2[1];
        puVar2[1] = (void*)(intptr_t)(iVar1 - 1);
        if (iVar1 - 1 == 0) {
            typedef void (__cdecl* DestroyFn)(int);
            ((DestroyFn)(*(void***)puVar2)[0])(1);
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x6bf2c0
// 0x6bf2c0 — observed shape: intrusive-refcount release of DAT_008e9ffc;
// zero count triggers vtable[0](1).
void FUN_6bf2c0(void)
{
    void** puVar2 = (void**)DAT_008e9ffc;
    if (DAT_008e9ffc != nullptr) {
        int32_t iVar1 = (int32_t)(intptr_t)puVar2[1];
        puVar2[1] = (void*)(intptr_t)(iVar1 - 1);
        if (iVar1 - 1 == 0) {
            typedef void (__cdecl* DestroyFn)(int);
            ((DestroyFn)(*(void***)puVar2)[0])(1);
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x6bf2e0
// 0x6bf2e0 — observed shape: intrusive-refcount release of DAT_008ea000;
// zero count triggers vtable[0](1).
void FUN_6bf2e0(void)
{
    void** puVar2 = (void**)DAT_008ea000;
    if (DAT_008ea000 != nullptr) {
        int32_t iVar1 = (int32_t)(intptr_t)puVar2[1];
        puVar2[1] = (void*)(intptr_t)(iVar1 - 1);
        if (iVar1 - 1 == 0) {
            typedef void (__cdecl* DestroyFn)(int);
            ((DestroyFn)(*(void***)puVar2)[0])(1);
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x6bf300
// 0x6bf300 — observed shape: intrusive-refcount release of DAT_008ea004;
// zero count triggers vtable[0](1).
void FUN_6bf300(void)
{
    void** puVar2 = (void**)DAT_008ea004;
    if (DAT_008ea004 != nullptr) {
        int32_t iVar1 = (int32_t)(intptr_t)puVar2[1];
        puVar2[1] = (void*)(intptr_t)(iVar1 - 1);
        if (iVar1 - 1 == 0) {
            typedef void (__cdecl* DestroyFn)(int);
            ((DestroyFn)(*(void***)puVar2)[0])(1);
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x6bf320
// 0x6bf320 — observed shape: intrusive-refcount release of DAT_008ea008;
// zero count triggers vtable[0](1).
void FUN_6bf320(void)
{
    void** puVar2 = (void**)DAT_008ea008;
    if (DAT_008ea008 != nullptr) {
        int32_t iVar1 = (int32_t)(intptr_t)puVar2[1];
        puVar2[1] = (void*)(intptr_t)(iVar1 - 1);
        if (iVar1 - 1 == 0) {
            typedef void (__cdecl* DestroyFn)(int);
            ((DestroyFn)(*(void***)puVar2)[0])(1);
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x6bf340
// 0x6bf340 — observed shape: intrusive-refcount release of DAT_008ea00c;
// zero count triggers vtable[0](1).
void FUN_6bf340(void)
{
    void** puVar2 = (void**)DAT_008ea00c;
    if (DAT_008ea00c != nullptr) {
        int32_t iVar1 = (int32_t)(intptr_t)puVar2[1];
        puVar2[1] = (void*)(intptr_t)(iVar1 - 1);
        if (iVar1 - 1 == 0) {
            typedef void (__cdecl* DestroyFn)(int);
            ((DestroyFn)(*(void***)puVar2)[0])(1);
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x6bf360
// 0x6bf360 — observed shape: intrusive-refcount release of DAT_008ea010;
// zero count triggers vtable[0](1).
void FUN_6bf360(void)
{
    void** puVar2 = (void**)DAT_008ea010;
    if (DAT_008ea010 != nullptr) {
        int32_t iVar1 = (int32_t)(intptr_t)puVar2[1];
        puVar2[1] = (void*)(intptr_t)(iVar1 - 1);
        if (iVar1 - 1 == 0) {
            typedef void (__cdecl* DestroyFn)(int);
            ((DestroyFn)(*(void***)puVar2)[0])(1);
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x6bf380
// 0x6bf380 — observed shape: install two successive vtable pointers into
// PTR_PTR_00726ba4, flushing via FUN_004e6420 after each; then free the
// DAT_00726bac slot.
void FUN_6bf380(void)
{
    PTR_PTR_00726ba4 = (void*)&PTR_FUN_0070df84;
    FUN_004e6420();
    PTR_PTR_00726ba4 = (void*)&PTR_FUN_0070df68;
    FUN_004e6420();
    operator_delete__(DAT_00726bac);
    return;
}

// ---------------------------------------------------------------------------
// 0x6bf410
// 0x6bf410 — observed shape: descending sweep of 8 slots starting at
// DAT_008ea034-4 down to DAT_008ea014; each non-null payload's refcount at +4
// is decremented and vtable[0](1) is called when it reaches zero.
void FUN_6bf410(void)
{
    uint8_t* puVar3 = (uint8_t*)&DAT_008ea034;
    int iVar4 = 8;
    do {
        puVar3 -= 4;
        void** puVar2 = *(void***)puVar3;
        if (puVar2 != nullptr) {
            int32_t* piVar1 = (int32_t*)(puVar2 + 1);
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) {
                typedef void (__cdecl* DestroyFn)(int);
                ((DestroyFn)(*(void***)puVar2)[0])(1);
            }
        }
        iVar4 = iVar4 - 1;
    } while (iVar4 != 0);
    return;
}

// ---------------------------------------------------------------------------
// 0x6bf440
// 0x6bf440 — observed shape: descending sweep of 5 slots starting at
// DAT_008ea048-4 down to DAT_008ea034; each non-null payload's refcount at +4
// is decremented and vtable[0](1) is called when it reaches zero.
void FUN_6bf440(void)
{
    uint8_t* puVar3 = (uint8_t*)&DAT_008ea048;
    int iVar4 = 5;
    do {
        puVar3 -= 4;
        void** puVar2 = *(void***)puVar3;
        if (puVar2 != nullptr) {
            int32_t* piVar1 = (int32_t*)(puVar2 + 1);
            *piVar1 = *piVar1 - 1;
            if (*piVar1 == 0) {
                typedef void (__cdecl* DestroyFn)(int);
                ((DestroyFn)(*(void***)puVar2)[0])(1);
            }
        }
        iVar4 = iVar4 - 1;
    } while (iVar4 != 0);
    return;
}
