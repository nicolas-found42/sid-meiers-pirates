// Reconstruction batch mass_0071 — Sid Meier's Pirates! (2004), PE32 i386.
// Target image: 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---------------------------------------------------------------------------
// Extern declarations (only symbols referenced by the observed listings)
// ---------------------------------------------------------------------------
extern uint8_t  DAT_008cacf8;     // global "suppress path handling" flag
extern uint8_t  DAT_008cacd0;     // shared string buffer base (SSO header at -8/-4)
extern int32_t  DAT_008cace0;     // single fallback object
extern int32_t* DAT_008cacdc;     // global container object (self)
extern uint8_t  DAT_008cacc8;     // sentinel compared against static buffer
extern uint32_t DAT_008caccc;     // string length mirrored into the buffer header
extern int32_t  DAT_008cad04;     // global "language loaded" flag
extern uint8_t  DAT_00710800;     // comparator/table blob passed to FUN_004f9950
extern int32_t  LAB_004f8060(const void* a, const void* b); // qsort comparator

extern uint32_t PTR_FUN_00710658; // vtable of the container object
extern uint32_t PTR_FUN_007106a0;
extern uint32_t PTR_FUN_007106a8;
extern uint32_t PTR_FUN_007106ac;
extern uint32_t PTR_FUN_007108ac; // vtable of the stack parser object
extern uint32_t PTR_FUN_0070db70;
extern uint32_t PTR_FUN_007109d0;
extern uint32_t PTR_FUN_007109ec;
extern uint32_t PTR_FUN_006f5864;

// Helpers referenced by the listings (signatures preserved from the decompiler).
extern int32_t  FUN_004f1390(void);
extern void     FUN_004f4b20(const char* path, int32_t a2, int32_t a3, int32_t a4);
extern void     FUN_00412d10(void);
extern uint32_t FUN_004f1310(void);
extern int32_t  FUN_004f5480(const char* name, uint32_t* out);
extern void*    FUN_00533c78(uint32_t size);
extern uint32_t FUN_004d4b00(uint32_t a1, uint32_t a2, int32_t a3, int32_t a4, int32_t a5);
extern void     FUN_004d4aa0(int32_t flag);
extern void*    FUN_004f0e40(const char* name, int32_t a2, int32_t a3, int32_t a4);
extern int32_t  FUN_004f11a0(void* p, int32_t n);
extern void     FUN_004f0dc0(void);
extern void     FUN_00412ff0(void);
extern uint32_t FUN_004f1370(...);
extern void*    FUN_004129c0(uint8_t* buf, int32_t n);
extern void     FUN_00412fb0(void);
extern void     FUN_004fc180(void);
extern void     FUN_004b1050(void);
extern void     FUN_004fb6a0(void* obj, int32_t flag);
extern void     FUN_004fc070(void);
extern void     FUN_004e6420(void);
extern int32_t  FUN_004fb7c0(uint32_t obj);
extern uint32_t FUN_004fc970(uint32_t obj);
extern int32_t  thunk_FUN_00533c78(uint32_t size);
extern void     FUN_004f32e0(void);
extern char     FUN_004f8fa0(void* a, int32_t b);
extern void     FUN_004f7630(void);
extern void     FUN_00412ec0(void);
extern void     FUN_00412f10(void);
extern void     FUN_004f96a0(void);
extern void     FUN_004f9950(void* a, void** b);
extern void     FUN_004f2aa0(void* p);
extern void     FUN_004f80b0(void* p);
extern void     FUN_004f8f50(void);
extern char     FUN_004f4ed0(void);
extern int32_t  FUN_004f7f80(void);
extern int32_t  FUN_004fd020(void* a, const char* b, int32_t c);
extern void     FUN_004f7ed0(void);
extern void     FUN_00412df0(void);
extern void     FUN_004f61a0(void* self, int32_t** a, int32_t** b, uint32_t p);
extern void     FUN_004f6f40(void);
extern void     FUN_004f6fa0(void* self, int32_t** a, int32_t** b);
extern void     operator_delete__(void* p);
extern void     operator_delete(void* p);

extern "C" {
char*   strchr(const char* s, int c);
char*   strncat(char* dst, const char* src, size_t n);
char*   strncpy(char* dst, const char* src, size_t n);
void    qsort(void* base, size_t n, size_t width, int (*cmp)(const void*, const void*));
int32_t _stricmp(const char* a, const char* b);
int32_t _strnicmp(const char* a, const char* b, size_t n);
char*   setlocale(int category, const char* locale);
}

// ---------------------------------------------------------------------------
// Forward declarations of this batch's definitions.
// ---------------------------------------------------------------------------
int32_t  FUN_004f4f50(const char* path);
uint32_t FUN_004f50b0(const char* src, const char* dst, char bReplace);
uint32_t FUN_004f5290(uint32_t param_1, uint32_t param_2);
void     FUN_004f5330(int32_t key);
void     FUN_004f53b0(char param_1);
int32_t  FUN_004f5480(const char* name, uint32_t* out);
void     FUN_004f5550(void);
void     FUN_004f55a0(void* self);
void     FUN_004f5640(void* self, uint8_t flags);
void     FUN_004f5670(void* self, uint32_t newSize);
void     FUN_004f5720(void* self, uint32_t index, uint32_t* value);
void     FUN_004f5780(void* self);
char     FUN_004f5870(int32_t* self, int32_t handle);
void     FUN_004f5bd0(uint32_t param_1);
void     FUN_004f5ce0(void* self, int32_t in_eax, int32_t in_esi);
void     FUN_004f5db0(uint32_t param_1, char** param_2);
uint32_t FUN_004f5ef0(uint32_t param_1, void* self);
uint8_t  FUN_004f5fe0(uint32_t param_1, void* self, int32_t in_esi);
uint32_t FUN_004f6040(const char* param_1, void* self);
int32_t  FUN_004f60d0(uint32_t param_1, int32_t* self);

// ---------------------------------------------------------------------------
// 0x4f4f50 — observed shape: path has a separator (and DAT_008cacf8 clear) ->
// tries FUN_004f1390 first; otherwise, when DAT_008cace0 is set and
// FUN_004f5480 resolves the name, copies the file via FUN_004f4b20 with mode
// 1/0x8000 and finishes through FUN_00412d10.
// ---------------------------------------------------------------------------
// 0x4f4f50 — observed shape
int32_t FUN_004f4f50(const char* path)
{
    bool    bPlain;
    int32_t r;

    if (DAT_008cacf8 == '\0' &&
        (strchr(path, '\\') != nullptr || strchr(path, '/') != nullptr)) {
        bPlain = false;
        r = FUN_004f1390();
        if (r != 0) {
            return r;
        }
    } else {
        bPlain = true;
    }
    if ((DAT_008cace0 == 0) || (r = FUN_004f5480(path, nullptr), r == 0)) {
        if (bPlain) {
            return FUN_004f1390();
        }
    } else {
        FUN_004f4b20(path, 1, 0, 0x8000);
        FUN_00412d10();
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x4f50b0 — observed shape: ECM copy helper. src at in_ECX, dst at in_EAX,
// "replace" byte at in_EBX. Rejects the copy with error 0x50 when
// FUN_004f1310 reports a blocking condition; copies directly when the source
// has no separator or DAT_008cace0 is clear; otherwise resolves the entry
// through FUN_004f5480 and either rewrites it with FUN_004f0e40/FUN_004f4f50
// or renames it via FUN_004f1370.
// ---------------------------------------------------------------------------
// 0x4f50b0 — observed shape
uint32_t FUN_004f50b0(const char* src, const char* dst, char bReplace)
{
    uint8_t  local_2c[4];
    void**   local_28;
    uint32_t local_24;
    uint32_t local_20;
    uint32_t local_1c;
    uint32_t local_18;
    uint32_t local_14;
    uint32_t local_10;
    char*    local_c;
    bool     bPlain;
    int32_t  iVar6;
    uint32_t uVar7;

    local_28 = nullptr;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c  = nullptr;
    iVar6    = 0;
    uVar7    = 0;

    if (bReplace == '\0' && FUN_004f1310() != 0) {
        SetLastError(0x50);
        return 2;
    }
    if (DAT_008cacf8 == '\0' &&
        (strchr(src, '\\') != nullptr || strchr(src, '/') != nullptr)) {
        bPlain = false;
        if (CopyFileA(src, dst, (uint32_t)(bReplace == '\0')) != 0) {
            return 0;
        }
    } else {
        bPlain = true;
    }
    if (DAT_008cace0 == 0) {
        if (bPlain) {
            BOOL ok = CopyFileA(src, dst, (uint32_t)(bReplace == '\0'));
            return (uint32_t)(ok == 0);
        }
    } else {
        iVar6 = FUN_004f5480(dst, nullptr);
        if (iVar6 != 0 && *(int32_t**)((uint8_t*)iVar6 + 0x10) != nullptr) {
            int32_t s0 = **(int32_t**)((uint8_t*)iVar6 + 0x10);
            if (*(char*)(*(int32_t*)(s0 - 4) + (s0 - 1)) != '\\') {
                local_28 = (void**)&PTR_FUN_006f5864;
                local_c  = (char*)&DAT_008cacd0;
                local_24 = 0;
                local_20 = 0;
                local_1c = 0;
                local_18 = 0;
                local_14 = 0;
                local_10 = 0;
                uVar7 = (uint32_t)(uintptr_t)FUN_004f0e40(dst, 2, 0, 0x8000);
                if (uVar7 == 0) {
                    uVar7 = 1;
                    int32_t* piVar8 = (int32_t*)FUN_004f4f50(nullptr);
                    if (piVar8 != nullptr) {
                        int32_t iVar = FUN_004f11a0(piVar8 + 1, *piVar8);
                        uVar7 = (uint32_t)(iVar != *piVar8);
                        operator_delete__(piVar8);
                    }
                    FUN_004f0dc0();
                }
                FUN_00412ff0();
                return uVar7;
            }
        }
        if (bPlain) {
            if (iVar6 == 0) {
                return FUN_004f1370();
            }
            uint32_t* puVar9 = (uint32_t*)FUN_004129c0(local_2c, iVar6 + 8);
            uint32_t  r = FUN_004f1370(*puVar9);
            FUN_00412fb0();
            return r;
        }
    }
    return 1;
}

// ---------------------------------------------------------------------------
// 0x4f5290 — observed shape: lazily creates the global container object
// (vtable PTR_FUN_00710658, fields +8/+0xc/+0x10/+0x14/+4 cleared, +0x14 = 1),
// allocates 0x34 bytes for a new entry and builds it with FUN_004d4b00, then
// grows the container (FUN_004f5670) and stores the entry (FUN_004f5720).
// ---------------------------------------------------------------------------
// 0x4f5290 — observed shape
uint32_t FUN_004f5290(uint32_t param_1, uint32_t param_2)
{
    uint32_t  uVar2 = 0;
    int32_t   iVar1;

    if (DAT_008cacdc == nullptr) {
        DAT_008cacdc = (int32_t*)FUN_00533c78(0x18);
        if (DAT_008cacdc == nullptr) {
            DAT_008cacdc = nullptr;
        } else {
            DAT_008cacdc[2] = 0;
            DAT_008cacdc[5] = 1;
            DAT_008cacdc[3] = 0;
            DAT_008cacdc[4] = 0;
            DAT_008cacdc[1] = 0;
            DAT_008cacdc[0] = (int32_t)(intptr_t)&PTR_FUN_00710658;
        }
    }
    iVar1 = (int32_t)(intptr_t)FUN_00533c78(0x34);
    if (iVar1 != 0) {
        uVar2 = FUN_004d4b00(param_1, param_2, 0, 0, 0);
    }
    if ((uint32_t)DAT_008cacdc[2] <= (uint32_t)DAT_008cacdc[3]) {
        // in_EDX (the new capacity) is not visible in this listing.
        FUN_004f5670(DAT_008cacdc, 0u);
    }
    // in_ECX (slot index) and in_EDX (value pointer) are not visible here.
    FUN_004f5720(DAT_008cacdc, 0u, &uVar2);
    return uVar2;
}

// ---------------------------------------------------------------------------
// 0x4f5330 — observed shape: linear search of the global container for a key
// equal to in_EAX; clears the matching slot, decrements the live counter at
// +0x10, shrinks the used count at +0xc when the removed slot was the last
// one, releases the entry through FUN_004d4aa0(1) and compacts via
// FUN_004f55a0.
// ---------------------------------------------------------------------------
// 0x4f5330 — observed shape
void FUN_004f5330(int32_t key)
{
    int32_t* iVar3 = DAT_008cacdc;
    uint32_t uVar4;

    if (DAT_008cacdc != nullptr &&
        (uVar4 = 0, *(int32_t*)((uint8_t*)DAT_008cacdc + 8) != 0)) {
        int32_t* piVar1 = *(int32_t**)((uint8_t*)DAT_008cacdc + 4);
        int32_t* piVar5 = piVar1;
        while (key != *piVar5) {
            uVar4 = uVar4 + 1;
            piVar5 = piVar5 + 1;
            if (*(uint32_t*)((uint8_t*)DAT_008cacdc + 8) <= uVar4) {
                return;
            }
        }
        if (-1 < (int32_t)uVar4) {
            if (uVar4 < *(uint32_t*)((uint8_t*)DAT_008cacdc + 0xc)) {
                int32_t iVar2 = piVar1[uVar4];
                piVar1[uVar4] = 0;
                if (iVar2 != 0) {
                    *(int32_t*)((uint8_t*)iVar3 + 0x10) =
                        *(int32_t*)((uint8_t*)iVar3 + 0x10) + -1;
                }
                uint32_t uVar6 = *(int32_t*)((uint8_t*)iVar3 + 0xc) - 1;
                if (uVar4 == uVar6) {
                    *(uint32_t*)((uint8_t*)iVar3 + 0xc) = uVar6;
                }
            }
            if (key != 0) {
                FUN_004d4aa0(1);
            }
            FUN_004f55a0(iVar3);
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x4f53b0 — observed shape: destroys every live entry of the global
// container (base/derived destructor pairs plus operator_delete on the owned
// buffer at +8 and on the entry itself), zeroes the slot table, resets the
// used counters and, when param_1 is set, runs the container's own deleting
// destructor and clears DAT_008cacdc.
// ---------------------------------------------------------------------------
// 0x4f53b0 — observed shape
void FUN_004f53b0(char param_1)
{
    int32_t* puVar2 = DAT_008cacdc;
    uint32_t uVar3;

    if (DAT_008cacdc != nullptr) {
        uVar3 = 0;
        if (DAT_008cacdc[3] != 0) {
            do {
                int32_t* puVar1 = *(int32_t**)(puVar2[1] + (int32_t)(uVar3 * 4));
                if (puVar1 != nullptr) {
                    FUN_004fc180();
                    FUN_004b1050();
                    FUN_004fb6a0(puVar1, 1);
                    FUN_004fc070();
                    *puVar1 = (int32_t)(intptr_t)&PTR_FUN_007109ec;
                    FUN_004e6420();
                    *puVar1 = (int32_t)(intptr_t)&PTR_FUN_007109d0;
                    FUN_004e6420();
                    operator_delete__((void*)puVar1[2]);
                    operator_delete(puVar1);
                    puVar2 = DAT_008cacdc;
                }
                uVar3 = uVar3 + 1;
            } while (uVar3 < (uint32_t)puVar2[3]);
        }
        uVar3 = 0;
        if (puVar2[3] != 0) {
            do {
                *(uint32_t*)(puVar2[1] + (int32_t)(uVar3 * 4)) = 0;
                uVar3 = uVar3 + 1;
            } while (uVar3 < (uint32_t)puVar2[3]);
        }
        puVar2[3] = 0;
        puVar2[4] = 0;
    }
    if ((param_1 != '\0') && (puVar2 != nullptr)) {
        (reinterpret_cast<void (*)(int32_t*, int32_t)>(
            *reinterpret_cast<intptr_t*>(puVar2[0])))(puVar2, 1);
        DAT_008cacdc = nullptr;
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x4f5480 — observed shape: reverse scan of the global container looking for
// the entry matched by FUN_004fb7c0 for the name at param_1; when a match is
// found it reports FUN_004fc970(entry) through param_2; falls back to the
// single object DAT_008cace0, and finally reports NULL/0.
// ---------------------------------------------------------------------------
// 0x4f5480 — observed shape
int32_t FUN_004f5480(const char* name, uint32_t* out)
{
    uint32_t uVar1;
    int32_t  iVar2;
    int32_t  iVar3;

    if (name != nullptr && *name != '\0') {
        if (DAT_008cacdc != 0) {
            iVar2 = *(int32_t*)((uint8_t*)DAT_008cacdc + 0xc);
            while (iVar2 = iVar2 + -1, -1 < iVar2) {
                uVar1 = *(uint32_t*)(*(int32_t*)((uint8_t*)DAT_008cacdc + 4) +
                                     (int32_t)((uint32_t)iVar2 * 4));
                iVar3 = 0;
                if (*name != '\0') {
                    iVar3 = FUN_004fb7c0(uVar1);
                }
                if (out != nullptr) {
                    uVar1 = FUN_004fc970(uVar1);
                    *out = uVar1;
                }
                if (iVar3 != 0) {
                    return iVar3;
                }
            }
        }
        iVar2 = DAT_008cace0;
        if (DAT_008cace0 != 0) {
            iVar3 = 0;
            if (*name != '\0') {
                iVar3 = FUN_004fb7c0((uint32_t)iVar2);
            }
            if (out != nullptr) {
                uVar1 = FUN_004fc970((uint32_t)iVar2);
                *out = uVar1;
            }
            if (iVar3 != 0) {
                return iVar3;
            }
        }
    }
    if (out != nullptr) {
        *out = 0;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x4f5550 — observed shape: releases the entries of the global container in
// reverse order until one release reports failure, then releases the single
// object DAT_008cace0.
// ---------------------------------------------------------------------------
// 0x4f5550 — observed shape
void FUN_004f5550(void)
{
    int32_t iVar1;
    int32_t iVar2;

    if (DAT_008cacdc != 0) {
        iVar2 = *(int32_t*)((uint8_t*)DAT_008cacdc + 0xc);
        while (iVar2 = iVar2 + -1, -1 < iVar2) {
            iVar1 = (int32_t)FUN_004fc970(*(uint32_t*)(*(int32_t*)((uint8_t*)DAT_008cacdc + 4) +
                                                       (int32_t)((uint32_t)iVar2 * 4)));
            if (iVar1 != 0) {
                return;
            }
        }
    }
    FUN_004fc970((uint32_t)DAT_008cace0);
    return;
}

// ---------------------------------------------------------------------------
// 0x4f55a0 — observed shape: compacts the slot table of `self` in place when
// the live counter (+0x10) differs from the used count (+0xc), then rebuilds
// the slot array sized to the live counter and frees the previous array.
// ---------------------------------------------------------------------------
// 0x4f55a0 — observed shape
void FUN_004f55a0(void* self)
{
    uint8_t* s = static_cast<uint8_t*>(self);
    int32_t  iVar1;
    int32_t  iVar2;
    int32_t  iVar6;
    void*    pvVar3;
    uint32_t uVar4;
    uint32_t uVar5;

    if (*(int32_t*)(s + 0x10) != *(int32_t*)(s + 0xc)) {
        if (*(int32_t*)(s + 0x10) != 0 &&
            (uVar5 = 0, *(int32_t*)(s + 0xc) != 0)) {
            iVar6 = 0;
            do {
                iVar1 = *(int32_t*)(s + 4);
                iVar2 = *(int32_t*)(iVar1 + (int32_t)(uVar5 * 4));
                if (iVar2 != 0) {
                    if (*(int32_t*)(iVar6 + iVar1) != iVar2) {
                        *(int32_t*)(iVar6 + iVar1) = iVar2;
                    }
                    iVar6 = iVar6 + 4;
                }
                uVar5 = uVar5 + 1;
            } while (uVar5 < *(uint32_t*)(s + 0xc));
        }
        iVar6 = *(int32_t*)(s + 0x10);
        pvVar3 = *(void**)(s + 4);
        *(int32_t*)(s + 0xc) = iVar6;
        *(int32_t*)(s + 8) = iVar6;
        if (iVar6 == 0) {
            *(uint32_t*)(s + 4) = 0;
        } else {
            uVar4 = (uint32_t)(intptr_t)thunk_FUN_00533c78((uint32_t)(iVar6 << 2));
            *(uint32_t*)(s + 4) = uVar4;
            uVar5 = 0;
            if (*(int32_t*)(s + 0xc) != 0) {
                do {
                    *(uint32_t*)(*(int32_t*)(s + 4) + (int32_t)(uVar5 * 4)) =
                        *(uint32_t*)((int32_t)(intptr_t)pvVar3 + (int32_t)(uVar5 * 4));
                    uVar5 = uVar5 + 1;
                } while (uVar5 < *(uint32_t*)(s + 0xc));
                operator_delete__(pvVar3);
                return;
            }
        }
        operator_delete__(pvVar3);
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x4f5640 — observed shape: container destructor; reinstates the vtable,
// frees the slot array at +4 and deletes the object itself when the low bit
// of the flag byte is set.
// ---------------------------------------------------------------------------
// 0x4f5640 — observed shape
void FUN_004f5640(void* self, uint8_t flags)
{
    int32_t* in_ECX = static_cast<int32_t*>(self);

    *in_ECX = (int32_t)(intptr_t)&PTR_FUN_00710658;
    operator_delete__((void*)in_ECX[1]);
    if ((flags & 1) != 0) {
        operator_delete(in_ECX);
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x4f5670 — observed shape: resizes the slot table of `self` to newSize
// (in_EDX): trims the live counter when shrinking, reallocates newSize*4
// bytes, copies the used prefix, zero-fills the tail and frees the old array.
// ---------------------------------------------------------------------------
// 0x4f5670 — observed shape
void FUN_004f5670(void* self, uint32_t newSize)
{
    uint8_t* s = static_cast<uint8_t*>(self);

    if (newSize != *(uint32_t*)(s + 8)) {
        if (newSize < *(uint32_t*)(s + 0xc)) {
            uint32_t uVar3 = newSize;
            do {
                if (*(int32_t*)(*(int32_t*)(s + 4) + (int32_t)(uVar3 * 4)) != 0) {
                    *(uint32_t*)(*(int32_t*)(s + 4) + (int32_t)(uVar3 * 4)) = 0;
                    *(int32_t*)(s + 0x10) = *(int32_t*)(s + 0x10) + -1;
                }
                uVar3 = uVar3 + 1;
            } while (uVar3 < *(uint32_t*)(s + 0xc));
            *(uint32_t*)(s + 0xc) = newSize;
        }
        void* pvVar1 = *(void**)(s + 4);
        *(uint32_t*)(s + 8) = newSize;
        if (newSize == 0) {
            *(uint32_t*)(s + 4) = 0;
        } else {
            uint32_t uVar2 = (uint32_t)(intptr_t)thunk_FUN_00533c78(newSize * 4);
            *(uint32_t*)(s + 4) = uVar2;
            uint32_t uVar3 = 0;
            if (*(int32_t*)(s + 0xc) != 0) {
                do {
                    *(uint32_t*)(*(int32_t*)(s + 4) + (int32_t)(uVar3 * 4)) =
                        *(uint32_t*)((int32_t)(intptr_t)pvVar1 + (int32_t)(uVar3 * 4));
                    uVar3 = uVar3 + 1;
                } while (uVar3 < *(uint32_t*)(s + 0xc));
            }
            uVar3 = *(uint32_t*)(s + 0xc);
            if (uVar3 < *(uint32_t*)(s + 8)) {
                do {
                    *(uint32_t*)(*(int32_t*)(s + 4) + (int32_t)(uVar3 * 4)) = 0;
                    uVar3 = uVar3 + 1;
                } while (uVar3 < *(uint32_t*)(s + 8));
                operator_delete__(pvVar1);
                return;
            }
        }
        operator_delete__(pvVar1);
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x4f5720 — observed shape: stores *value (in_EDX) into slot `index`
// (in_ECX) of `self` (in_EAX), growing the used count when the slot was
// beyond the current count, and keeping the live counter at +0x10 in sync.
// ---------------------------------------------------------------------------
// 0x4f5720 — observed shape
void FUN_004f5720(void* self, uint32_t index, uint32_t* value)
{
    uint8_t* s = static_cast<uint8_t*>(self);

    if (index < *(uint32_t*)(s + 8)) {
        if (index < *(uint32_t*)(s + 0xc)) {
            int32_t iVar1 = *(int32_t*)(*(int32_t*)(s + 4) + (int32_t)(index * 4));
            if (*value == 0) {
                if (iVar1 != 0) {
                    *(int32_t*)(s + 0x10) = *(int32_t*)(s + 0x10) + -1;
                }
            } else if (iVar1 == 0) {
                *(int32_t*)(s + 0x10) = *(int32_t*)(s + 0x10) + 1;
                *(int32_t*)(*(int32_t*)(s + 4) + (int32_t)(index * 4)) = (int32_t)*value;
                return;
            }
        } else {
            *(uint32_t*)(s + 0xc) = index + 1;
            if (*value != 0) {
                *(int32_t*)(s + 0x10) = *(int32_t*)(s + 0x10) + 1;
                *(int32_t*)(*(int32_t*)(s + 4) + (int32_t)(index * 4)) = (int32_t)*value;
                return;
            }
        }
        *(int32_t*)(*(int32_t*)(s + 4) + (int32_t)(index * 4)) = (int32_t)*value;
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x4f5780 — observed shape: constructor for the parser object at in_ESI;
// installs the four vtable sub-objects (PTR_FUN_007106ac/-a0/-a8), clears the
// per-table counters, initialises the two string members at +0x68/+0x6c
// (pointing at DAT_008cacd0 with the length from DAT_008caccc), sets the
// initial field count 6, the tail byte 0x40 and finally calls setlocale(2,"").
// ---------------------------------------------------------------------------
// 0x4f5780 — observed shape
void FUN_004f5780(void* self)
{
    int32_t* unaff_ESI = static_cast<int32_t*>(self);

    *(int32_t**)unaff_ESI = reinterpret_cast<int32_t*>(&PTR_FUN_0070db70);
    unaff_ESI[7] = 1;
    unaff_ESI[2] = (int32_t)(intptr_t)&PTR_FUN_007106ac;
    unaff_ESI[4] = 0;
    unaff_ESI[5] = 0;
    unaff_ESI[6] = 0;
    unaff_ESI[3] = 0;
    unaff_ESI[0xd] = 1;
    unaff_ESI[10] = 0;
    unaff_ESI[0xb] = 0;
    unaff_ESI[0xc] = 0;
    unaff_ESI[9] = 0;
    unaff_ESI[8] = (int32_t)(intptr_t)&PTR_FUN_007106ac;
    unaff_ESI[0x13] = 1;
    unaff_ESI[0x10] = 0;
    unaff_ESI[0x11] = 0;
    unaff_ESI[0x12] = 0;
    unaff_ESI[0xf] = 0;
    unaff_ESI[0xe] = (int32_t)(intptr_t)&PTR_FUN_007106a0;
    unaff_ESI[0x19] = 1;
    unaff_ESI[0x16] = 0;
    unaff_ESI[0x17] = 0;
    unaff_ESI[0x18] = 0;
    unaff_ESI[0x15] = 0;
    unaff_ESI[0x14] = (int32_t)(intptr_t)&PTR_FUN_007106a8;

    int32_t* piVar1 = unaff_ESI + 0x1a;
    *piVar1 = (int32_t)(intptr_t)&DAT_008cacd0;
    uint32_t uVar2 = DAT_008caccc;
    if (DAT_008cacc8 < 0xfff) {
        FUN_004f32e0();
    }
    *(uint32_t*)(*piVar1 + -4) = 0xfff;
    *(uint32_t*)(*piVar1 + -4) = uVar2;

    piVar1 = unaff_ESI + 0x1b;
    *piVar1 = (int32_t)(intptr_t)&DAT_008cacd0;
    uVar2 = DAT_008caccc;
    if (DAT_008cacc8 < 0xfff) {
        FUN_004f32e0();
    }
    *(uint32_t*)(*piVar1 + -4) = 0xfff;
    *(uint32_t*)(*piVar1 + -4) = uVar2;

    unaff_ESI[1] = 6;
    unaff_ESI[0x1c] = 0;
    unaff_ESI[0x1d] = 0;
    unaff_ESI[0x1e] = 0;
    *(uint8_t*)(unaff_ESI + 0x1f) = 0x40;
    setlocale(2, "");
    return;
}

// ---------------------------------------------------------------------------
// 0x4f5870 — observed shape: grammar/property loader. Parses the file handle
// (in_ECX) through the stack parser object (vtable PTR_FUN_007108ac), and for
// every declared name allocates a 0xc-byte descriptor and classifies it by
// _stricmp against "__NUM", "__STR", "__CHAR", "__VAR", "__GEN", "__PER",
// "__MALE", "__MP", "__FEMALE", "__FP", "__NEUTER", "__NP", "__SING",
// "__PLUR"; __VAR additionally walks the parser variable table and refreshes
// both string members. Each descriptor is appended to self at +0x3c/+0x44 and
// the table is sorted with LAB_004f8060 when any entry was added.
// ---------------------------------------------------------------------------
// 0x4f5870 — observed shape
char FUN_004f5870(int32_t* self, int32_t handle)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    char     local_29;
    char*    local_28;
    int32_t* local_24;
    int32_t  local_20;
    void**   local_1c;
    uint32_t local_18;
    uint32_t local_14;
    int32_t  local_10;
    uint32_t local_c;
    uint32_t local_8;
    int32_t  local_4;
    char*    pcVar3;
    int32_t  iVar1;
    int32_t  iVar2;
    uint32_t uVar4;
    int32_t* piVar5;

    // local_4 is filled by FUN_00412f10 through an output argument the
    // listing does not spell out.
    local_4 = 0;
    local_29 = (char)(handle != 0);
    pcVar3 = (char*)&DAT_008cacd0;
    local_14 = 0;
    local_8 = 1;
    local_10 = 0;
    local_c = 0;
    local_18 = 0;
    local_1c = (void**)&PTR_FUN_007108ac;
    local_28 = (char*)&DAT_008cacd0;
    if (((bool)local_29) &&
        (local_29 = FUN_004f8fa0(&local_1c, handle), local_29 != '\0')) {
        FUN_004f7630();
        local_20 = 0;
        if (0 < local_10) {
            do {
                local_24 = (int32_t*)FUN_00533c78(0xc);
                if (local_24 == nullptr) {
                    local_24 = nullptr;
                } else {
                    local_24[1] = (int32_t)(intptr_t)&DAT_008cacd0;
                    local_24[2] = 0;
                }
                piVar5 = local_24;
                if ((-1 < local_20) && (local_20 < local_10)) {
                    FUN_00412ec0();
                }
                FUN_00412f10();
                FUN_004f96a0();
                FUN_004f9950(&DAT_00710800, (void**)&local_28);
                pcVar3 = local_28;
                iVar1 = _stricmp(local_28, "__NUM");
                if (iVar1 == 0) {
                    *piVar5 = 0;
                } else {
                    iVar1 = _stricmp(pcVar3, "__STR");
                    if (iVar1 == 0) {
                        *piVar5 = 1;
                    } else {
                        iVar1 = _stricmp(pcVar3, "__CHAR");
                        if (iVar1 == 0) {
                            *piVar5 = 2;
                        } else {
                            iVar2 = _stricmp(pcVar3, "__VAR");
                            iVar1 = local_4;
                            if (iVar2 == 0) {
                                *piVar5 = 3;
                                FUN_00412f10();
                                pcVar3 = local_28;
                                uVar4 = 0;
                                if (*(int32_t*)(iVar1 + 0x10) != 0) {
                                    do {
                                        int32_t elem = *(int32_t*)
                                            (*(int32_t*)(iVar1 + 8) + (int32_t)(uVar4 * 4));
                                        iVar2 = _stricmp(pcVar3, *(char**)elem);
                                        if (iVar2 == 0) {
                                            FUN_004f2aa0((void*)(elem + 4));
                                            FUN_004f80b0((void*)(elem + 4));
                                        }
                                        uVar4 = uVar4 + 1;
                                    } while (uVar4 < *(uint32_t*)(iVar1 + 0x10));
                                }
                                piVar5 = local_24;
                            } else {
                                iVar1 = _stricmp(pcVar3, "__GEN");
                                if (iVar1 == 0) {
                                    *piVar5 = 4;
                                } else {
                                    iVar1 = _stricmp(pcVar3, "__PER");
                                    if (iVar1 == 0) {
                                        *piVar5 = 5;
                                    } else {
                                        iVar1 = _stricmp(pcVar3, "__MALE");
                                        if (iVar1 == 0) {
                                            *piVar5 = 6;
                                        } else {
                                            iVar1 = _stricmp(pcVar3, "__MP");
                                            if (iVar1 == 0) {
                                                *piVar5 = 9;
                                            } else {
                                                iVar1 = _stricmp(pcVar3, "__FEMALE");
                                                if (iVar1 == 0) {
                                                    *piVar5 = 7;
                                                } else {
                                                    iVar1 = _stricmp(pcVar3, "__FP");
                                                    if (iVar1 == 0) {
                                                        *piVar5 = 10;
                                                    } else {
                                                        iVar1 = _stricmp(pcVar3, "__NEUTER");
                                                        if (iVar1 == 0) {
                                                            *piVar5 = 8;
                                                        } else {
                                                            iVar1 = _stricmp(pcVar3, "__NP");
                                                            if (iVar1 == 0) {
                                                                *piVar5 = 0xb;
                                                            } else {
                                                                iVar1 = _stricmp(pcVar3, "__SING");
                                                                if (iVar1 == 0) {
                                                                    *piVar5 = 0xc;
                                                                } else {
                                                                    iVar1 = _stricmp(pcVar3, "__PLUR");
                                                                    *piVar5 = (int32_t)
                                                                        ((-((uint32_t)(iVar1 != 0)) &
                                                                          0xfffffff4u) + 0xd);
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                local_24 = *(int32_t**)(base + 0x44);
                if ((uintptr_t)local_24 < *(uint32_t*)(base + 0x40) ||
                    (FUN_004f5670(self, 0u),
                     (uintptr_t)local_24 < *(uint32_t*)(base + 0x40))) {
                    if ((uintptr_t)local_24 < *(uint32_t*)(base + 0x44)) {
                        if (*(int32_t*)(*(int32_t*)(base + 0x3c) +
                                        (int32_t)((intptr_t)local_24 * 4)) == 0) {
                            goto LAB_004f5b5e;
                        }
                    } else {
                        *(uint32_t*)(base + 0x44) = (uint32_t)((intptr_t)local_24 + 1);
LAB_004f5b5e:
                        *(int32_t*)(base + 0x48) = *(int32_t*)(base + 0x48) + 1;
                    }
                    *(int32_t*)(*(int32_t*)(base + 0x3c) +
                                (int32_t)((intptr_t)local_24 * 4)) = (int32_t)(intptr_t)piVar5;
                }
                local_20 = local_20 + 1;
            } while (local_20 < local_10);
        }
        if (*(int32_t*)(base + 0x48) != 0) {
            qsort(*(void**)(base + 0x3c), *(size_t*)(base + 0x44), 4,
                  reinterpret_cast<int (*)(const void*, const void*)>(&LAB_004f8060));
        }
    }
    pcVar3 = pcVar3 + -8;
    if ((pcVar3 != nullptr) && (pcVar3 != (char*)&DAT_008cacc8)) {
        operator_delete__(pcVar3);
    }
    FUN_004f8f50();
    return local_29;
}

// ---------------------------------------------------------------------------
// 0x4f5bd0 — observed shape: maps GetUserDefaultLangID() to a language code
// (7->0x11, 9->9/7/6, 10->0x24, 0xc->0xd, 0x10->0x17, 0x13->4, 0x16->0x1e/0x1f,
// default 6), probes availability with FUN_004f5fe0 and installs the choice
// through FUN_004f5fe0 + FUN_004f5ce0.
// ---------------------------------------------------------------------------
// 0x4f5bd0 — observed shape
void FUN_004f5bd0(uint32_t param_1)
{
    uint32_t uVar3 = 6;
    LANGID   LVar2 = GetUserDefaultLangID();
    char     cVar1;

    switch (LVar2 & 0x3ff) {
    case 7:
        uVar3 = 0x11;
        break;
    case 9:
        uVar3 = 6;
        LVar2 = GetUserDefaultLangID();
        if (LVar2 >> 10 == 2) {
            cVar1 = FUN_004f5fe0(7, DAT_008cacdc, 0);
            if (cVar1 != '\0') {
                uVar3 = 7;
            }
        } else if ((LVar2 >> 10 == 4) &&
                   (cVar1 = FUN_004f5fe0(9, DAT_008cacdc, 0), cVar1 != '\0')) {
            uVar3 = 9;
        }
        break;
    case 10:
        uVar3 = 0x24;
        break;
    case 0xc:
        uVar3 = 0xd;
        break;
    case 0x10:
        uVar3 = 0x17;
        break;
    case 0x13:
        uVar3 = 4;
        break;
    case 0x16:
        uVar3 = 0x1e;
        LVar2 = GetUserDefaultLangID();
        if ((LVar2 >> 10 == 1) &&
            (cVar1 = FUN_004f5fe0(0x1f, DAT_008cacdc, 0), cVar1 != '\0')) {
            uVar3 = 0x1f;
        }
        break;
    default:
        break;
    }
    FUN_004f5fe0(uVar3, DAT_008cacdc, 0);
    FUN_004f5ce0(DAT_008cacdc, (int32_t)param_1, 0);
    return;
}

// ---------------------------------------------------------------------------
// 0x4f5ce0 — observed shape: stores param at in_EAX into self[1], invokes the
// second vfunc of self, and when in_ESI is non-null loads the current language
// through FUN_004f4ed0; on success it lazily creates self[0x1c] (0x8c bytes,
// FUN_004f7f80), installs the language with FUN_004fd020 and on failure tears
// the object down; otherwise the existing object is released. The temporary
// string buffer is freed unless it is the static one.
// ---------------------------------------------------------------------------
// 0x4f5ce0 — observed shape
void FUN_004f5ce0(void* self, int32_t in_eax, int32_t in_esi)
{
    int32_t* unaff_EDI = static_cast<int32_t*>(self);
    void*    pvVar1;
    char     cVar2;
    int32_t  iVar3;
    uint32_t uStack_c = 0;

    unaff_EDI[1] = in_eax;
    {
        intptr_t vtable = *reinterpret_cast<intptr_t*>(unaff_EDI);
        (reinterpret_cast<void (*)()>(*reinterpret_cast<intptr_t*>(vtable + 8)))();
    }
    if (in_esi != 0) {
        cVar2 = FUN_004f4ed0();
        if (cVar2 != '\0') {
            if (unaff_EDI[0x1c] == 0) {
                iVar3 = (int32_t)(intptr_t)FUN_00533c78(0x8c);
                if (iVar3 == 0) {
                    iVar3 = 0;
                } else {
                    iVar3 = FUN_004f7f80();
                }
                unaff_EDI[0x1c] = iVar3;
            }
            iVar3 = FUN_004fd020((void*)(intptr_t)unaff_EDI[0x1c], (const char*)&DAT_008cacd0, 1);
            if (iVar3 != 0) {
                pvVar1 = (void*)(intptr_t)unaff_EDI[0x1c];
                if (pvVar1 != nullptr) {
                    FUN_004f7ed0();
                    operator_delete(pvVar1);
                    unaff_EDI[0x1c] = 0;
                }
                DAT_008cad04 = 0;
            }
            goto LAB_004f5d92;
        }
    }
    pvVar1 = (void*)(intptr_t)unaff_EDI[0x1c];
    if (pvVar1 != nullptr) {
        FUN_004f7ed0();
        operator_delete(pvVar1);
        unaff_EDI[0x1c] = 0;
    }
LAB_004f5d92:
    if ((&uStack_c != nullptr) && (&uStack_c != (uint32_t*)&DAT_008cacc8)) {
        operator_delete__(&uStack_c);
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x4f5db0 — observed shape: clears the destination string for every known
// language code (4, 6, 7, 9, 0xd, 0x11, 0x17, 0x1e, 0x1f, 0x24) via
// FUN_00412f10; for an unknown code it truncates the buffer to empty by
// clearing its length header and first character.
// ---------------------------------------------------------------------------
// 0x4f5db0 — observed shape
void FUN_004f5db0(uint32_t param_1, char** param_2)
{
    switch (param_1) {
    case 4:
        FUN_00412f10();
        return;
    case 6:
        FUN_00412f10();
        return;
    case 7:
        FUN_00412f10();
        return;
    case 9:
        FUN_00412f10();
        return;
    case 0xd:
        FUN_00412f10();
        return;
    case 0x11:
        FUN_00412f10();
        return;
    case 0x17:
        FUN_00412f10();
        return;
    case 0x1e:
        FUN_00412f10();
        return;
    case 0x1f:
        FUN_00412f10();
        return;
    case 0x24:
        FUN_00412f10();
        return;
    default:
        break;
    }
    if (*(int32_t*)((uint8_t*)*param_2 + -4) != 0) {
        *(uint8_t*)*param_2 = 0;
        *(uint32_t*)(*param_2 - 4) = 0;
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x4f5ef0 — observed shape: dispatches on self->+4 (in_ECX); the known
// language codes (4, 6, 7, 9, 0xd, 0x11, 0x17, 0x1e, 0x1f, 0x24) refresh the
// text via FUN_00412f10 and then finish through FUN_00412df0, while every
// other value goes straight to FUN_00412df0 and returns param_1.
// ---------------------------------------------------------------------------
// 0x4f5ef0 — observed shape
uint32_t FUN_004f5ef0(uint32_t param_1, void* self)
{
    int32_t* in_ECX = static_cast<int32_t*>(self);

    switch (*(uint32_t*)((uint8_t*)in_ECX + 4)) {
    case 4:
    case 6:
    case 7:
    case 9:
    case 0xd:
    case 0x11:
    case 0x17:
    case 0x1e:
    case 0x1f:
    case 0x24:
        FUN_00412f10();
        break;
    default:
        FUN_00412df0();
        return param_1;
    }
    FUN_00412df0();
    return param_1;
}

// ---------------------------------------------------------------------------
// 0x4f5fe0 — observed shape: installs language param_1 into self (in_ECX) by
// invoking the vfunc at vtable+8 with the local string buffer; reports success
// when the current language (FUN_004f4ed0) matches, then frees the temporary
// buffer unless it is the static one.
// ---------------------------------------------------------------------------
// 0x4f5fe0 — observed shape
uint8_t FUN_004f5fe0(uint32_t param_1, void* self, int32_t in_esi)
{
    int32_t* in_ECX = static_cast<int32_t*>(self);
    char*    local_4 = (char*)&DAT_008cacd0;
    uint32_t* puVar2;
    uint8_t  uVar3;
    char     cVar1;

    {
        intptr_t vtable = *reinterpret_cast<intptr_t*>(in_ECX);
        (reinterpret_cast<void (*)(uint32_t, char**)>(
            *reinterpret_cast<intptr_t*>(vtable + 8)))(param_1, &local_4);
    }
    if (*(int32_t*)((uint8_t*)(intptr_t)in_esi + -4) != 0) {
        cVar1 = FUN_004f4ed0();
        if (cVar1 == '\0') {
            uVar3 = 0;
            goto LAB_004f6014;
        }
    }
    uVar3 = 1;
LAB_004f6014:
    puVar2 = (uint32_t*)((uint8_t*)(intptr_t)in_esi - 8);
    if ((puVar2 != nullptr) && (puVar2 != (uint32_t*)&DAT_008cacc8)) {
        operator_delete__(puVar2);
    }
    return uVar3;
}

// ---------------------------------------------------------------------------
// 0x4f6040 — observed shape: case-insensitive prefix search over the
// descriptor table of self (in_EDI); compares param_1 with each entry name
// using the entry's own recorded length, returning the slot index or
// 0xffffffff.
// ---------------------------------------------------------------------------
// 0x4f6040 — observed shape
uint32_t FUN_004f6040(const char* param_1, void* self)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t uVar2 = 0;
    int32_t  iVar1;

    if (*(int32_t*)(base + 0x44) != 0) {
        do {
            iVar1 = *(int32_t*)(*(int32_t*)(base + 0x3c) + (int32_t)(uVar2 * 4));
            iVar1 = _strnicmp(*(char**)(iVar1 + 4), param_1,
                              *(size_t*)(*(int32_t*)(iVar1 + 4) - 4));
            if (iVar1 == 0) {
                return uVar2;
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint32_t*)(base + 0x44));
    }
    return 0xffffffff;
}

// ---------------------------------------------------------------------------
// 0x4f60d0 — observed shape: resolves the current entry of self (in_ESI) into
// local_4/local_8, optionally applies the language transforms
// (FUN_004f6f40 / FUN_004f6fa0) when DAT_008cad04 is set and self[1] != 6,
// calls the second vfunc with the resulting string, and appends or copies that
// string into the fixed buffer at self[0x1e] limited by self[0x1d].
// ---------------------------------------------------------------------------
// 0x4f60d0 — observed shape
int32_t FUN_004f60d0(uint32_t param_1, int32_t* self)
{
    int32_t* unaff_ESI = self;
    char     cVar1;
    char*    _Dest;
    char*    pcVar2;
    int32_t* local_8;
    int32_t* local_4;
    int32_t* piVar3;

    local_8 = unaff_ESI + 0x1b;
    piVar3 = unaff_ESI + 0x1a;
    local_4 = piVar3;
    FUN_00412f10();
    if (*(int32_t*)(*piVar3 - 4) != 0) {
        FUN_004f61a0(unaff_ESI, &local_4, &local_8, param_1);
        if ((DAT_008cad04 != 0) && (unaff_ESI[1] != 6)) {
            FUN_004f6f40();
            FUN_004f6fa0(unaff_ESI, &local_4, &local_8);
        }
        piVar3 = local_8;
    }
    {
        intptr_t vtable = *reinterpret_cast<intptr_t*>(unaff_ESI);
        (reinterpret_cast<void (*)(int32_t*)>(
            *reinterpret_cast<intptr_t*>(vtable + 4)))(piVar3);
    }
    _Dest = (char*)(intptr_t)unaff_ESI[0x1e];
    if (_Dest != nullptr) {
        if ((char)param_1 != '\0') {
            pcVar2 = _Dest;
            do {
                cVar1 = *pcVar2;
                pcVar2 = pcVar2 + 1;
            } while (cVar1 != '\0');
            strncat(_Dest, (char*)*piVar3,
                    (size_t)((unaff_ESI[0x1d] - ((int32_t)(intptr_t)pcVar2 -
                                                  (int32_t)(intptr_t)(_Dest + 1))) - 1));
            return *piVar3;
        }
        strncpy(_Dest, (char*)*piVar3, (size_t)(unaff_ESI[0x1d] - 1));
    }
    return *piVar3;
}
