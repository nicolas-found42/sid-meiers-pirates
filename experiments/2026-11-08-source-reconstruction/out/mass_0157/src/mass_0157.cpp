// Reconstruction batch mass_0157: Sid Meier's Pirates! (2004) PE32 i386
#include <cstdint>
#include <cstddef>
#include <windows.h>

// observed externs (shared helpers/globals)
extern void operator_delete(void* p);
extern void operator_delete__(void* p);
// FUN_00561470 destructor (also defined below); used by 0x561450
extern void FUN_00561470_impl(void* self);
extern void FUN_00547d10();
extern void FUN_00549540();
extern void FUN_00549900();
// vtable anchors observed in listings
extern void* PTR_FUN_006c33a0;
extern void* PTR_FUN_006c33d8;
extern void* PTR_FUN_006c3470;
extern void* PTR_LAB_006c34b8;
extern void* PTR_FUN_006c34bc;
extern int DAT_00727d70;
extern void FUN_00539ba0();
extern void FUN_0053a110();
extern void FUN_005383d0();
extern char FUN_00539a60(int param_1);
extern void* FUN_00545600();
extern int FUN_00545630();
extern void FUN_0053a180(int param_1);
extern int FUN_00557b10(int param_1);
extern void FUN_005606f0(uint32_t value, uint32_t* out);
extern char FUN_00538460(int param_1);
extern void FUN_006b34a0(int value);
extern uint32_t FUN_005621f0(void* self, int param_1);
extern int FUN_005621d0(void* self);
extern int thunk_FUN_00533c78(int size);
extern void thunk_FUN_00540af0(int param_1);
extern int LAB_00562130(const void* lhs, const void* rhs);

// 0x561450 — observed shape: delta-deleting destructor wrapper: calls FUN_00561470 then conditionally operator_delete(self) if flag bit0 set
void FUN_00561450(void* self, uint8_t param_1)
{
    FUN_00561470_impl(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x561470 — observed shape: sets vtable ptr, frees array elements at offset 0x14 (count at +0x10), frees array at +0x14, clears it, tail-calls FUN_00547d10
void FUN_00561470_impl(void* self)
{
    uint32_t* fields = static_cast<uint32_t*>(self);
    uint32_t count = 0;
    fields[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c33a0);
    if (fields[4] != 0) {
        do {
            operator_delete__(*reinterpret_cast<void**>(fields[5] + count * 4));
            count = count + 1;
        } while (count < fields[4]);
    }
    operator_delete__(reinterpret_cast<void*>(fields[5]));
    fields[5] = 0;
    FUN_00547d10();
}

// 0x5616e0 — observed shape: constructs object by calling FUN_00549540 then inits fields
void FUN_005616e0(void* self)
{
    uint32_t* f = static_cast<uint32_t*>(self);
    FUN_00549540();
    f[0x47] = 0x3f800000;
    f[0x44] = 0;
    f[0x46] = 0;
    f[0x4b] = 0;
    f[0x4a] = 0;
    f[0x48] = 0;
    f[0x45] = 0x3f800000;
    f[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c33d8);
    f[0x49] = 0;
}

// 0x561750 — observed shape: calls FUN_00549900, copies three fields to offsets +0x11c..0x124, increments +0xc0
void FUN_00561750(void* self)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    FUN_00549900();
    *reinterpret_cast<uint32_t*>(b + 0x11c) = *reinterpret_cast<uint32_t*>(b + 0x6c);
    *reinterpret_cast<uint32_t*>(b + 0x120) = *reinterpret_cast<uint32_t*>(b + 0x78);
    *reinterpret_cast<uint32_t*>(b + 0x124) = *reinterpret_cast<uint32_t*>(b + 0x84);
    *reinterpret_cast<int*>(b + 0xc0) = *reinterpret_cast<int*>(b + 0xc0) + 1;
}

// 0x561a50 — observed shape: releases ref at +0x40, clears it, then releases indexed slot at +0x7c + *(+0x48)*4
void FUN_00561a50(void* self)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    uint32_t* puVar3 = *reinterpret_cast<uint32_t**>(b + 0x40);
    if (puVar3 != nullptr) {
        int* ref = reinterpret_cast<int*>(puVar3) + 1;
        *ref = *ref + -1;
        if (*ref == 0) {
            using DelFn = void(__cdecl *)(int);
            DelFn fn = *reinterpret_cast<DelFn*>(*puVar3);
            fn(1);
        }
        *reinterpret_cast<uint32_t*>(b + 0x40) = 0;
    }
    int* slot = reinterpret_cast<int*>(b + 0x7c + *reinterpret_cast<int*>(b + 0x48) * 4);
    puVar3 = reinterpret_cast<uint32_t*>(*slot);
    if (puVar3 != nullptr) {
        int* ref = reinterpret_cast<int*>(puVar3) + 1;
        *ref = *ref + -1;
        if (*ref == 0) {
            using DelFn = void(__cdecl *)(int);
            DelFn fn = *reinterpret_cast<DelFn*>(*puVar3);
            fn(1);
        }
        *slot = 0;
    }
}

// 0x561ab0 — observed shape: forwards to thunk_FUN_00540af0, then when FUN_00545630()==6 refreshes six refcounted slots at +0x7c
void FUN_00561ab0(void* self, int param_1)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    thunk_FUN_00540af0(param_1);
    int iVar3 = FUN_00545630();
    if (iVar3 == 6) {
        int* piVar5 = reinterpret_cast<int*>(b + 0x7c);
        iVar3 = 6;
        do {
            uint32_t* puVar4 = reinterpret_cast<uint32_t*>(FUN_00545600());
            uint32_t* puVar2 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(*piVar5)));
            if (puVar2 != puVar4) {
                if (puVar2 != nullptr) {
                    int* piVar1 = reinterpret_cast<int*>(puVar2) + 1;
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) {
                        using DelFn = void(__cdecl *)(int);
                        DelFn fn = *reinterpret_cast<DelFn*>(*puVar2);
                        fn(1);
                    }
                }
                *piVar5 = static_cast<int>(reinterpret_cast<uintptr_t>(puVar4));
                if (puVar4 != nullptr) {
                    int* ref = reinterpret_cast<int*>(puVar4) + 1;
                    *ref = *ref + 1;
                }
            }
            piVar5 = piVar5 + 1;
            iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
    }
}

// 0x561b10 — observed shape: returns 0 unless FUN_00539a60 passes, then ANDs slot+0x14 virtual results across six +0x7c objects
uint8_t FUN_00561b10(void* self, int param_1)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    char cVar1 = FUN_00539a60(param_1);
    if (cVar1 == '\0') {
        return 0;
    }
    uint8_t bVar3 = 1;
    int* piVar4 = reinterpret_cast<int*>(b + 0x7c);
    int iVar5 = 6;
    do {
        if (*piVar4 != 0) {
            uint32_t* vtable = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(*piVar4)));
            using TestFn = uint8_t(__cdecl *)(int);
            TestFn fn = *reinterpret_cast<TestFn*>(reinterpret_cast<uint8_t*>(vtable) + 0x14);
            uint8_t bVar2 = fn(param_1);
            bVar3 = bVar3 & bVar2;
        }
        piVar4 = piVar4 + 1;
        iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    return bVar3;
}

// 0x561c60 — observed shape: constructs via FUN_00539ba0, installs vtable 0x6c3470, clears +0x7c..+0x90 and releases those refs
void FUN_00561c60(void* self)
{
    uint32_t* f = static_cast<uint32_t*>(self);
    FUN_00539ba0();
    f[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c3470);
    int* piVar4 = reinterpret_cast<int*>(f + 0x1f);
    *piVar4 = 0;
    f[0x20] = 0;
    f[0x21] = 0;
    f[0x22] = 0;
    f[0x23] = 0;
    f[0x24] = 0;
    int iVar3 = 6;
    do {
        piVar4[-0xc] = 0;
        piVar4[-6] = 0;
        uint32_t* puVar2 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(*piVar4)));
        if (puVar2 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar2) + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                using DelFn = void(__cdecl *)(int);
                DelFn fn = *reinterpret_cast<DelFn*>(*puVar2);
                fn(1);
            }
            *piVar4 = 0;
        }
        piVar4 = piVar4 + 1;
        iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    f[0x12] = 0;
}

// 0x561ce0 — observed shape: destructor: installs vtable 0x6c3470, releases +0x40, deletes 6x2 raw pointers at +0x4c/+0x64, releases +0x7c array and +0x88 array, tail-calls FUN_0053a110
void FUN_00561ce0(void* self)
{
    uint32_t* f = static_cast<uint32_t*>(self);
    f[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c3470);
    f[0xe] = 0;
    f[0xf] = 0;
    uint32_t* puVar5 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(f[0x10])));
    if (puVar5 != nullptr) {
        int* piVar4 = reinterpret_cast<int*>(puVar5) + 1;
        *piVar4 = *piVar4 + -1;
        if (*piVar4 == 0) {
            using DelFn = void(__cdecl *)(int);
            DelFn fn = *reinterpret_cast<DelFn*>(*puVar5);
            fn(1);
        }
        f[0x10] = 0;
    }
    int* piVar4 = reinterpret_cast<int*>(f + 0x1f);
    int iVar3 = 6;
    do {
        operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(piVar4[-0xc]))));
        operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(piVar4[-6]))));
        puVar5 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(*piVar4)));
        if (puVar5 != nullptr) {
            int* ref = reinterpret_cast<int*>(puVar5) + 1;
            *ref = *ref + -1;
            if (*ref == 0) {
                using DelFn = void(__cdecl *)(int);
                DelFn fn = *reinterpret_cast<DelFn*>(*puVar5);
                fn(1);
            }
            *piVar4 = 0;
        }
        piVar4 = piVar4 + 1;
        iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    uint32_t* puVar6 = f + 0x25;
    iVar3 = 6;
    do {
        uint32_t* puVar2 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(puVar6[-1])));
        puVar6 = puVar6 + -1;
        if (puVar2 != nullptr) {
            int* ref = reinterpret_cast<int*>(puVar2) + 1;
            *ref = *ref + -1;
            if (*ref == 0) {
                using DelFn = void(__cdecl *)(int);
                DelFn fn = *reinterpret_cast<DelFn*>(*puVar2);
                fn(1);
            }
        }
        iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    FUN_0053a110();
}

// 0x562080 — observed shape: deleting destructor: runs FUN_00561ce0 then conditionally operator_delete(self) if flag bit0 set
void FUN_00562080(void* self, uint8_t param_1)
{
    FUN_00561ce0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5620a0 — observed shape: FUN_0053a180 init, queries FUN_00557b10(DAT_00727d70), grows buffer when count(+0x8) <= index(+0xc), then FUN_005606f0(index, &value)
void FUN_005620a0(int param_1)
{
    int self = param_1;
    FUN_0053a180(param_1);
    uint32_t value = static_cast<uint32_t>(FUN_00557b10(DAT_00727d70));
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(self + 0xc);
    if (*reinterpret_cast<uint32_t*>(self + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(self + 0x14) + static_cast<int>(uVar1));
    }
    FUN_005606f0(uVar1, &value);
}

// 0x562180 — observed shape: installs vtable 0x6c34b8, operator_delete__ on the six pointers at +0x4..+0x18
void FUN_00562180(void* self)
{
    uint32_t* f = static_cast<uint32_t*>(self);
    f[0] = reinterpret_cast<uint32_t>(&PTR_LAB_006c34b8);
    operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(f[1]))));
    operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(f[2]))));
    operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(f[3]))));
    operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(f[4]))));
    operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(f[5]))));
    operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(f[6]))));
}

// 0x5621d0 — observed shape: sums the first *(u16*)(self+0x22) entries of the u16 array at self+0x18
int FUN_005621d0(void* self)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    uint32_t uVar3 = *reinterpret_cast<uint16_t*>(b + 0x22);
    int iVar1 = 0;
    if (uVar3 != 0) {
        uint16_t* puVar2 = reinterpret_cast<uint16_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(*reinterpret_cast<uint32_t*>(b + 0x18))));
        do {
            iVar1 = iVar1 + static_cast<int>(*puVar2);
            puVar2 = puVar2 + 1;
            uVar3 = uVar3 - 1;
        } while (uVar3 != 0);
    }
    return iVar1;
}

// 0x5621f0 — observed shape: structural equality of two records: header u16/s16 fields at +0x1c..+0x24, then byte compares of the buffers at +0x4,+0xc,+0x8,+0x14,+0x18,+0x10 (size 2*count, 2*count, 4*count, 6*count or 2*sum, 2*count)
uint32_t FUN_005621f0(void* self, int param_1)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    uint8_t* o = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(param_1)));
    uint16_t uVar1 = *reinterpret_cast<uint16_t*>(b + 0x1c);
    if (uVar1 != *reinterpret_cast<uint16_t*>(o + 0x1c)) {
        return 0;
    }
    if ((*reinterpret_cast<int16_t*>(b + 0x1e) != *reinterpret_cast<int16_t*>(o + 0x1e)) ||
        (*reinterpret_cast<uint16_t*>(b + 0x20) != *reinterpret_cast<uint16_t*>(o + 0x20)) ||
        (*reinterpret_cast<int16_t*>(b + 0x22) != *reinterpret_cast<int16_t*>(o + 0x22)) ||
        (*reinterpret_cast<int16_t*>(b + 0x24) != *reinterpret_cast<int16_t*>(o + 0x24))) {
        return 0;
    }
    uint32_t n = static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(b + 0x20)) << 1;
    bool bVar8 = true;
    char* pcVar6 = reinterpret_cast<char*>(static_cast<uintptr_t>(static_cast<uint32_t>(*reinterpret_cast<uint32_t*>(b + 4))));
    char* pcVar7 = reinterpret_cast<char*>(static_cast<uintptr_t>(static_cast<uint32_t>(*reinterpret_cast<uint32_t*>(o + 4))));
    do {
        if (n == 0) break;
        n = n - 1;
        bVar8 = *pcVar6 == *pcVar7;
        pcVar6 = pcVar6 + 1;
        pcVar7 = pcVar7 + 1;
    } while (bVar8);
    uint32_t uVar3 = 0;
    if (!bVar8) {
        return 0;
    }
    n = static_cast<uint32_t>(uVar1) * 2;
    bVar8 = true;
    pcVar6 = reinterpret_cast<char*>(static_cast<uintptr_t>(static_cast<uint32_t>(*reinterpret_cast<uint32_t*>(b + 0xc))));
    pcVar7 = reinterpret_cast<char*>(static_cast<uintptr_t>(static_cast<uint32_t>(*reinterpret_cast<uint32_t*>(o + 0xc))));
    do {
        if (n == 0) break;
        n = n - 1;
        bVar8 = *pcVar6 == *pcVar7;
        pcVar6 = pcVar6 + 1;
        pcVar7 = pcVar7 + 1;
    } while (bVar8);
    if (!bVar8) {
        return 0;
    }
    uint32_t uVar2 = static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(b + 0x24)) * static_cast<uint32_t>(uVar1);
    n = uVar2 * 4;
    bVar8 = true;
    pcVar6 = reinterpret_cast<char*>(static_cast<uintptr_t>(static_cast<uint32_t>(*reinterpret_cast<uint32_t*>(b + 8))));
    pcVar7 = reinterpret_cast<char*>(static_cast<uintptr_t>(static_cast<uint32_t>(*reinterpret_cast<uint32_t*>(o + 8))));
    do {
        if (n == 0) break;
        n = n - 1;
        bVar8 = *pcVar6 == *pcVar7;
        pcVar6 = pcVar6 + 1;
        pcVar7 = pcVar7 + 1;
    } while (bVar8);
    uVar3 = uVar2;
    if (bVar8) {
        if (*reinterpret_cast<uint16_t*>(b + 0x22) == 0) {
            n = static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(b + 0x1e)) * 6;
            bVar8 = true;
            pcVar6 = reinterpret_cast<char*>(static_cast<uintptr_t>(static_cast<uint32_t>(*reinterpret_cast<uint32_t*>(b + 0x14))));
            pcVar7 = reinterpret_cast<char*>(static_cast<uintptr_t>(static_cast<uint32_t>(*reinterpret_cast<uint32_t*>(o + 0x14))));
            do {
                if (n == 0) break;
                n = n - 1;
                bVar8 = *pcVar6 == *pcVar7;
                pcVar6 = pcVar6 + 1;
                pcVar7 = pcVar7 + 1;
            } while (bVar8);
        }
        else {
            n = static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(b + 0x22)) << 1;
            uVar3 = 0;
            bVar8 = true;
            pcVar6 = reinterpret_cast<char*>(static_cast<uintptr_t>(static_cast<uint32_t>(*reinterpret_cast<uint32_t*>(b + 0x18))));
            pcVar7 = reinterpret_cast<char*>(static_cast<uintptr_t>(static_cast<uint32_t>(*reinterpret_cast<uint32_t*>(o + 0x18))));
            do {
                if (n == 0) break;
                n = n - 1;
                bVar8 = *pcVar6 == *pcVar7;
                pcVar6 = pcVar6 + 1;
                pcVar7 = pcVar7 + 1;
            } while (bVar8);
            if (!bVar8) {
                return 0;
            }
            uVar3 = static_cast<uint32_t>(FUN_005621d0(self));
            n = uVar3 << 1;
            bVar8 = true;
            pcVar6 = reinterpret_cast<char*>(static_cast<uintptr_t>(static_cast<uint32_t>(*reinterpret_cast<uint32_t*>(b + 0x14))));
            pcVar7 = reinterpret_cast<char*>(static_cast<uintptr_t>(static_cast<uint32_t>(*reinterpret_cast<uint32_t*>(o + 0x14))));
            do {
                if (n == 0) break;
                n = n - 1;
                bVar8 = *pcVar6 == *pcVar7;
                pcVar6 = pcVar6 + 1;
                pcVar7 = pcVar7 + 1;
            } while (bVar8);
        }
        if (bVar8) {
            char* pcVar = reinterpret_cast<char*>(static_cast<uintptr_t>(static_cast<uint32_t>(*reinterpret_cast<uint32_t*>(b + 0x10))));
            uVar3 = uVar2;
            if ((pcVar == nullptr) == (*reinterpret_cast<uint32_t*>(o + 0x10) == 0)) {
                if (pcVar != nullptr) {
                    uVar3 = 0;
                    bVar8 = true;
                    pcVar7 = reinterpret_cast<char*>(static_cast<uintptr_t>(static_cast<uint32_t>(*reinterpret_cast<uint32_t*>(o + 0x10))));
                    do {
                        if (uVar2 == 0) break;
                        uVar2 = uVar2 - 1;
                        bVar8 = *pcVar == *pcVar7;
                        pcVar = pcVar + 1;
                        pcVar7 = pcVar7 + 1;
                    } while (bVar8);
                    if (!bVar8) {
                        return 0;
                    }
                }
                return 1;
            }
        }
    }
    return uVar3 & 0xffffff00u;
}

// 0x562300 — observed shape: constructs via FUN_005383d0, installs vtable 0x6c34bc, clears field +0x10
void FUN_00562300(void* self)
{
    uint32_t* f = static_cast<uint32_t*>(self);
    FUN_005383d0();
    f[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c34bc);
    f[4] = 0;
}

// 0x562350 — observed shape: FUN_00538460 gate, equal counts at +0xc, then element-wise FUN_005621f0 over 0x2c-sized records at +0x10
uint8_t FUN_00562350(void* self, int param_1)
{
    uint8_t* b = static_cast<uint8_t*>(self);
    uint8_t* o = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(param_1)));
    char cVar2 = FUN_00538460(param_1);
    if (cVar2 == '\0') {
        return 0;
    }
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(b + 0xc);
    if (uVar1 != *reinterpret_cast<uint32_t*>(o + 0xc)) {
        return 0;
    }
    uint32_t uVar5 = 0;
    if (uVar1 != 0) {
        int iVar4 = *reinterpret_cast<int*>(b + 0x10);
        int iVar3 = *reinterpret_cast<int*>(o + 0x10) - iVar4;
        do {
            char cVar1 = static_cast<char>(FUN_005621f0(reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(iVar4))), iVar4 + iVar3));
            if (cVar1 == '\0') {
                return 0;
            }
            uVar5 = uVar5 + 1;
            iVar4 = iVar4 + 0x2c;
        } while (uVar5 < uVar1);
    }
    return 1;
}

// 0x5623c0 — observed shape: reallocates the 8-byte record array to param_1 entries, copying count(+0x8) records, then frees and stores base/length
void FUN_005623c0(void* self, int param_1)
{
    int* ecx = static_cast<int*>(self);
    int iVar2;
    if (param_1 == ecx[1]) {
        return;
    }
    if (param_1 == 0) {
        iVar2 = 0;
    }
    else {
        iVar2 = thunk_FUN_00533c78(param_1 * 8);
        uint32_t uVar3 = 0;
        if (ecx[2] != 0) {
            do {
                int iVar1 = ecx[0];
                *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(iVar2 + static_cast<int>(uVar3) * 8))) =
                    *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(iVar1 + static_cast<int>(uVar3) * 8)));
                *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(iVar2 + 4 + static_cast<int>(uVar3) * 8))) =
                    *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(iVar1 + 4 + static_cast<int>(uVar3) * 8)));
                uVar3 = uVar3 + 1;
            } while (uVar3 < static_cast<uint32_t>(ecx[2]));
        }
    }
    operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(ecx[0]))));
    ecx[0] = iVar2;
    ecx[1] = param_1;
}

// 0x562440 — observed shape: sums the weight at +4 of each 8-byte record, four at a time, then scales every weight by 1/sum
void FUN_00562440(void* self)
{
    uint32_t* f = static_cast<uint32_t*>(self);
    float fVar3 = 0.0f;
    uint32_t uVar2 = f[2];
    uint32_t uVar6 = 0;
    if (3 < static_cast<int>(uVar2)) {
        int iVar5 = static_cast<int>((uVar2 - 4) >> 2) + 1;
        uVar6 = static_cast<uint32_t>(iVar5 * 4);
        float* pfVar4 = reinterpret_cast<float*>(static_cast<uintptr_t>(static_cast<uint32_t>(f[0] + 0xc)));
        do {
            iVar5 = iVar5 + -1;
            fVar3 = fVar3 + pfVar4[-2] + *pfVar4 + pfVar4[2] + pfVar4[4];
            pfVar4 = pfVar4 + 8;
        } while (iVar5 != 0);
    }
    if (uVar6 < uVar2) {
        float* pfVar4 = reinterpret_cast<float*>(static_cast<uintptr_t>(static_cast<uint32_t>(f[0] + 4 + uVar6 * 8)));
        int iVar5 = static_cast<int>(uVar2 - uVar6);
        do {
            fVar3 = fVar3 + *pfVar4;
            pfVar4 = pfVar4 + 2;
            iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
    }
    uVar6 = 0;
    if (uVar2 != 0) {
        do {
            int iVar5 = static_cast<int>(uVar6 * 8);
            int iVar1 = static_cast<int>(uVar6 * 8);
            uVar6 = uVar6 + 1;
            *reinterpret_cast<float*>(static_cast<uintptr_t>(static_cast<uint32_t>(f[0] + 4 + iVar1))) =
                (1.0f / fVar3) * *reinterpret_cast<float*>(static_cast<uintptr_t>(static_cast<uint32_t>(f[0] + 4 + iVar5)));
        } while (uVar6 < static_cast<uint32_t>(f[2]));
    }
}

// 0x5624c0 — observed shape: order-preserving subsequence check of param_1's u16 array inside self's u16 array
uint32_t FUN_005624c0(void* self, int* param_1)
{
    uint32_t* ecx = static_cast<uint32_t*>(self);
    uint32_t uVar2 = 0;
    uint32_t uVar4 = 0;
    uint16_t* pThis = reinterpret_cast<uint16_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(ecx[0])));
    uint16_t* pOther = reinterpret_cast<uint16_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(param_1[0])));
    if (param_1[2] != 0) {
        uint32_t uVar1 = ecx[2];
        do {
            if (uVar2 < uVar1) {
                uint16_t* puVar3 = pThis + uVar2;
                do {
                    if (pOther[uVar4] <= *puVar3) break;
                    uVar2 = uVar2 + 1;
                    puVar3 = puVar3 + 1;
                } while (uVar2 < uVar1);
            }
            if ((uVar2 == uVar1) ||
                (reinterpret_cast<int16_t*>(pThis)[uVar2] != reinterpret_cast<int16_t*>(pOther)[uVar4])) {
                return uVar2 & 0xffffff00u;
            }
            uVar2 = uVar2 + 1;
            uVar4 = uVar4 + 1;
        } while (uVar4 < static_cast<uint32_t>(param_1[2]));
    }
    return 1;
}

// 0x562530 — observed shape: bsearch (2-byte elements, comparator LAB_00562130) of each record key at (*param_1)+i*8 in self's u16 array
uint32_t FUN_00562530(void* self, int* param_1)
{
    uint32_t* ecx = static_cast<uint32_t*>(self);
    int* piVar2 = param_1;
    uint32_t uVar1 = static_cast<uint32_t>(param_1[2]);
    if (uVar1 != 0) {
        uint32_t uVar4 = 0;
        do {
            uint8_t* keys = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(piVar2[0])));
            int* value = *reinterpret_cast<int**>(keys + uVar4 * 8);
            void* pvVar3 = bsearch(&value,
                                   reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(ecx[0]))),
                                   static_cast<size_t>(ecx[2]),
                                   2,
                                   &LAB_00562130);
            if (pvVar3 == nullptr) {
                return 0;
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < uVar1);
    }
    return 1;
}
