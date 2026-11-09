//
// mass_0136.cpp — reconstruction batch mass_0136
// Target: Sid Meier's Pirates! (2004), PE32 i386
// Image: 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
//
// Each definition preserves the observed field offsets, constants,
// call order, return shape, and conditional structure of the Ghidra
// 12.2 pseudocode (analysis/pseudocode/functions/*.c).
//
// Register receivers (in_ECX) are modeled as an explicit `void* self`.
//
#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---------------------------------------------------------------------------
// Extern declarations: helpers and globals referenced by the assigned corpus
// files. No additional addresses are introduced.
// ---------------------------------------------------------------------------
void operator_delete(void* ptr);
void operator_delete__(void* ptr);
void FUN_005e1490(void);
void FUN_0055f300(int capacity);
int  FUN_00533c78(int size);
int  FUN_0055a200(int flag);
void FUN_006b34a0(uint32_t count);
void FUN_005606f0(int flags, void* data);

// ---------------------------------------------------------------------------
// 0x545c50 — observed shape
// Destructor-like: vtable swap x2 then member (self+8) delete, conditional
// self delete when param_1 & 1.
// ---------------------------------------------------------------------------
void FUN_00545c50(void* self, uint8_t param_1)
{
    void** vtable = reinterpret_cast<void**>(self);
    *vtable = reinterpret_cast<void*>(&PTR_FUN_006c18c4);
    FUN_005e1490();
    *vtable = reinterpret_cast<void*>(&PTR_FUN_006c17f4);
    FUN_005e1490();
    operator_delete__(reinterpret_cast<void*>(vtable[2]));
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// ---------------------------------------------------------------------------
// 0x545cc0 — observed shape
// Append constant 4 to vector at +0x164 (count +0x16c, capacity +0x168)
// after virtual call through +0x15c[1]. Grow with doubling before insert.
// ---------------------------------------------------------------------------
void FUN_00545cc0(void* self)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    int32_t* count = reinterpret_cast<int32_t*>(base + 0x16c);
    int32_t* capacity = reinterpret_cast<int32_t*>(base + 0x168);
    int32_t* buffer = *reinterpret_cast<int32_t**>(base + 0x164);
    void* owner = *reinterpret_cast<void**>(base + 0x15c);

    using VFn = void (*)(void*);
    uint8_t tmp[8];
    (*reinterpret_cast<VFn**>(owner) + 0)[0](tmp);

    int32_t cap = *capacity;
    if (*count == cap) {
        int32_t newCap = (cap == 0) ? 1 : cap * 2;
        FUN_0055f300(newCap);
        buffer = *reinterpret_cast<int32_t**>(base + 0x164);
    }
    buffer[*count] = 4;
    ++*count;
}

// ---------------------------------------------------------------------------
// 0x545d20 — observed shape
// Append unaff_ESI to vector at +0x174 (count +0x17c, capacity +0x178),
// then loop unaff_ESI times appending unaff_EBX to vector at +0x164
// (count +0x16c, capacity +0x168). Virtual call through +0x15c[1] before
// each element read.
// ---------------------------------------------------------------------------
void FUN_00545d20(void* self, uint32_t unaff_ESI, uint32_t unaff_EBX)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    int32_t* countA = reinterpret_cast<int32_t*>(base + 0x17c);
    int32_t* capacityA = reinterpret_cast<int32_t*>(base + 0x178);
    int32_t* bufferA = *reinterpret_cast<int32_t**>(base + 0x174);
    int32_t* countB = reinterpret_cast<int32_t*>(base + 0x16c);
    int32_t* capacityB = reinterpret_cast<int32_t*>(base + 0x168);
    int32_t* bufferB = *reinterpret_cast<int32_t**>(base + 0x164);
    void* owner = *reinterpret_cast<void**>(base + 0x15c);

    using VFn = void (*)(void*, int);
    uint8_t tmp[8];
    (*reinterpret_cast<VFn**>(owner) + 0)[0](tmp, 4);

    int32_t cap = *capacityA;
    if (*countA == cap) {
        int32_t newCap = (cap == 0) ? 1 : cap * 2;
        FUN_0055f300(newCap);
        bufferA = *reinterpret_cast<int32_t**>(base + 0x174);
    }
    bufferA[*countA] = static_cast<int32_t>(unaff_ESI);
    ++*countA;

    uint32_t uVar2 = 0;
    if (unaff_ESI != 0) {
        do {
            (*reinterpret_cast<VFn**>(owner) + 0)[0](tmp, 4);
            int32_t capB = *capacityB;
            if (*countB == capB) {
                int32_t newCap = (capB == 0) ? 1 : capB * 2;
                FUN_0055f300(newCap);
                bufferB = *reinterpret_cast<int32_t**>(base + 0x164);
            }
            bufferB[*countB] = static_cast<int32_t>(unaff_EBX);
            ++uVar2;
            ++*countB;
        } while (uVar2 < unaff_ESI);
    }
}

// ---------------------------------------------------------------------------
// 0x545df0 — observed shape
// Append param_1 to vector at +0x174 (count +0x17c, capacity +0x178).
// Grow with doubling before insert.
// ---------------------------------------------------------------------------
void FUN_00545df0(void* self, uint32_t param_1)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    int32_t* count = reinterpret_cast<int32_t*>(base + 0x17c);
    int32_t* capacity = reinterpret_cast<int32_t*>(base + 0x178);
    int32_t* buffer = *reinterpret_cast<int32_t**>(base + 0x174);

    int32_t cap = *capacity;
    if (*count == cap) {
        int32_t newCap = (cap == 0) ? 1 : cap * 2;
        FUN_0055f300(newCap);
        buffer = *reinterpret_cast<int32_t**>(base + 0x174);
    }
    buffer[*count] = static_cast<int32_t>(param_1);
    ++*count;
}

// ---------------------------------------------------------------------------
// 0x545e30 — observed shape
// Fill array at +0x08 with FUN_00533c78/FUN_0055a200 values, tracking the
// transition count at +0x14 and the furthest written index at +0x10.
// Sized by unaff_ESI + 1.
// ---------------------------------------------------------------------------
void FUN_00545e30(void* self, uint32_t unaff_ESI)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    int32_t* limit = reinterpret_cast<int32_t*>(base + 0xc);
    int32_t* furthest = reinterpret_cast<int32_t*>(base + 0x10);
    int32_t* transitions = reinterpret_cast<int32_t*>(base + 0x14);
    int32_t* array = *reinterpret_cast<int32_t**>(base + 8);
    void* owner = *reinterpret_cast<void**>(base + 0x15c);

    using VFn = void (*)(void*, int);
    uint8_t tmp[8];
    (*reinterpret_cast<VFn**>(owner) + 0)[0](tmp, 4);

    uint32_t uVar1 = unaff_ESI + 1;
    FUN_006b34a0(uVar1);
    FUN_005606f0(0, tmp);

    uint32_t uVar4 = 1;
    if (1 < uVar1) {
        do {
            (*reinterpret_cast<VFn**>(owner) + 0)[0](tmp, 4);
            int32_t value = FUN_00533c78(0x10);
            if (value == 0) {
                value = 0;
            } else {
                value = FUN_0055a200(0);
            }
            if (uVar4 < static_cast<uint32_t>(*limit)) {
                if (uVar4 < static_cast<uint32_t>(*furthest)) {
                    if (value == 0) {
                        if (array[uVar4] != 0) {
                            *transitions = *transitions - 1;
                        }
                    } else if (array[uVar4] == 0) {
                        *transitions = *transitions + 1;
                    }
                } else {
                    *furthest = static_cast<int32_t>(uVar4 + 1);
                    if (value != 0) {
                        *transitions = *transitions + 1;
                    }
                }
                array[uVar4] = value;
            }
            ++uVar4;
        } while (uVar4 < uVar1);
    }
}

// ---------------------------------------------------------------------------
// Additional extern declarations: helpers and globals referenced only by the
// definitions below. No addresses are introduced beyond the corpus listings.
// ---------------------------------------------------------------------------
void FUN_00545450(void);
void FUN_005459f0(void);
void FUN_00545ab0(void);
void FUN_0056f540(void);
int  thunk_FUN_00533c78(int size);
void FUN_0057a3f0(uint32_t count);
void FUN_00581300(uint32_t index, void* value);

extern uint8_t  DAT_00727560;
extern uint8_t  DAT_007273fc;
extern uint32_t DAT_0072784c;
extern int32_t  DAT_00727850;
extern CRITICAL_SECTION DAT_00727834;
extern int32_t  DAT_00727444;
extern uint32_t PTR_FUN_006c18e0;
extern uint32_t PTR_LAB_006fd148;
extern uint32_t PTR_FUN_006c1998;
extern uint32_t PTR_FUN_006c17bc;
extern uint32_t PTR_FUN_006c1848;

// ---------------------------------------------------------------------------
// 0x545f10 — observed shape
// Clear flag bit 0x10 and set bits 0xe in the ushort at +0x20, then walk the
// virtual list returned by vtable[1] looking for &DAT_00727560. When found,
// recurse over the elements of the +0xb8 array (count at +0xc0).
// ---------------------------------------------------------------------------
void FUN_00545f10(int* param_1)
{
    uint8_t* bytes = reinterpret_cast<uint8_t*>(param_1);
    *reinterpret_cast<uint16_t*>(bytes + 0x20) = static_cast<uint16_t>(
        (*reinterpret_cast<uint16_t*>(bytes + 0x20) & 0xffef) | 0xe);

    using VRetFn = void* (*)(void*);
    void* puVar3 =
        reinterpret_cast<VRetFn*>(*reinterpret_cast<void**>(param_1))[1](param_1);

    uint8_t bVar2;
    for (;;) {
        if (puVar3 == 0) {
            bVar2 = 0;
            break;
        }
        if (puVar3 == static_cast<void*>(&DAT_00727560)) {
            bVar2 = 1;
            break;
        }
        puVar3 = reinterpret_cast<void**>(puVar3)[1];
    }

    uint32_t uVar4 = (bVar2 != 0)
        ? static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_1))
        : 0;
    if (uVar4 == 0) {
        return;
    }

    uint8_t* obj = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(uVar4));
    uint32_t count = *reinterpret_cast<uint32_t*>(obj + 0xc0);
    for (uint32_t uVar5 = 0; uVar5 < count; ++uVar5) {
        int32_t iVar1 = *reinterpret_cast<int32_t*>(
            static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(obj + 0xb8)) +
            uVar5 * 4);
        if (iVar1 != 0) {
            FUN_00545f10(reinterpret_cast<int*>(static_cast<uintptr_t>(iVar1)));
        }
    }
}

// ---------------------------------------------------------------------------
// 0x545f90 — observed shape
// If the dword at +0x1c is below 0x401000c, scan the pointer array at +0x130
// (count at +0x138); for each element whose virtual list contains
// &DAT_007273fc with element[9] == 0, recurse via FUN_00545f10.
// ---------------------------------------------------------------------------
void FUN_00545f90(void* self)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    if (*reinterpret_cast<uint32_t*>(base + 0x1c) >= 0x401000c) {
        return;
    }
    if (*reinterpret_cast<uint32_t*>(base + 0x138) == 0) {
        return;
    }

    using VRetFn = void* (*)(void*);
    for (uint32_t uVar3 = 0;
         uVar3 < *reinterpret_cast<uint32_t*>(base + 0x138); ++uVar3) {
        uint32_t* entries = reinterpret_cast<uint32_t*>(
            static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(base + 0x130)));
        uint32_t* piVar1 = reinterpret_cast<uint32_t*>(
            static_cast<uintptr_t>(entries[uVar3]));
        if (piVar1 == 0) {
            continue;
        }
        for (void* puVar2 = reinterpret_cast<VRetFn*>(
                 reinterpret_cast<void*>(static_cast<uintptr_t>(piVar1[0])))[1](piVar1);
             puVar2 != 0;
             puVar2 = reinterpret_cast<void**>(puVar2)[1]) {
            if (puVar2 == static_cast<void*>(&DAT_007273fc)) {
                if (piVar1[9] == 0) {
                    FUN_00545f10(reinterpret_cast<int*>(piVar1));
                }
                break;
            }
        }
    }
}

// ---------------------------------------------------------------------------
// 0x546000 — observed shape
// First pass: for each object at +0x130 (+0x138 count), take the pointer at
// obj+8; if absent from the +0x08 table (count +0x10), grow with
// FUN_006b34a0 / FUN_005606f0 at index +0x10 and clear the object's dword 0.
// Second pass: add the virtual result at vtable[0x30/4] to the value stored
// at obj[2].
// ---------------------------------------------------------------------------
void FUN_00546000(void* self)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);

    uint32_t local_8;
    FUN_006b34a0(1);
    local_8 = 0;
    FUN_005606f0(0, &local_8);
    local_8 = 0;

    if (*reinterpret_cast<int32_t*>(base + 0x138) != 0) {
        do {
            uint32_t* entries = reinterpret_cast<uint32_t*>(
                static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(base + 0x130)));
            uint32_t obj = entries[local_8];
            void* puVar1 = reinterpret_cast<void*>(static_cast<uintptr_t>(
                *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(obj) + 8)));
            void* local_4 = puVar1;

            if (puVar1 != 0) {
                uint32_t uVar5 = 0;
                bool skip = false;
                if (*reinterpret_cast<uint32_t*>(base + 0x10) != 0) {
                    uint32_t* puVar7 = reinterpret_cast<uint32_t*>(
                        static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(base + 8)));
                    do {
                        if (static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar1)) ==
                            puVar7[uVar5]) {
                            if (uVar5 != 0) {
                                skip = true;
                            }
                            break;
                        }
                        ++uVar5;
                    } while (uVar5 < *reinterpret_cast<uint32_t*>(base + 0x10));
                }
                if (!skip) {
                    uVar5 = *reinterpret_cast<uint32_t*>(base + 0x10);
                    if (*reinterpret_cast<uint32_t*>(base + 0xc) <= uVar5) {
                        FUN_006b34a0(*reinterpret_cast<int32_t*>(base + 0x18) + uVar5);
                    }
                    FUN_005606f0(static_cast<int>(uVar5), &local_4);
                    *reinterpret_cast<uint32_t*>(puVar1) = 0;
                }
            }
            ++local_8;
        } while (local_8 < *reinterpret_cast<uint32_t*>(base + 0x138));
    }

    using VFn = int (*)(void*);
    for (uint32_t uVar5 = 0;
         uVar5 < *reinterpret_cast<uint32_t*>(base + 0x138); ++uVar5) {
        uint32_t* entries = reinterpret_cast<uint32_t*>(
            static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(base + 0x130)));
        uint32_t* piVar2 = reinterpret_cast<uint32_t*>(
            static_cast<uintptr_t>(entries[uVar5]));
        int32_t* piVar3 =
            reinterpret_cast<int32_t*>(static_cast<uintptr_t>(piVar2[2]));
        if (piVar3 != 0) {
            int32_t iVar4 = *piVar3;
            VFn fn = reinterpret_cast<VFn*>(
                reinterpret_cast<void*>(static_cast<uintptr_t>(piVar2[0])))[0x30 / 4];
            int32_t iVar6 = fn(piVar2);
            *piVar3 = iVar6 + iVar4;
        }
    }
}

// ---------------------------------------------------------------------------
// 0x5460e0 — observed shape
// Serialize: virtual vtable[2] call on the object at +0x15c with &self,
// allocate 5 bytes via thunk_FUN_00533c78, store the pointer at self+0,
// serialize (pointer, 4), then terminate the pointed-to byte at unaff_EDI.
// ---------------------------------------------------------------------------
void FUN_005460e0(void* self, uint32_t unaff_EDI)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    using VFn = void (*)(void*, ...);

    void* local_4 = self;
    void* owner = *reinterpret_cast<void**>(base + 0x15c);
    VFn* vt = reinterpret_cast<VFn*>(*reinterpret_cast<void**>(owner));

    vt[2](&local_4);
    int32_t iVar1 = thunk_FUN_00533c78(5);
    *reinterpret_cast<int32_t*>(local_4) = iVar1;
    vt[2](reinterpret_cast<void*>(static_cast<intptr_t>(iVar1)), 4);
    *reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(
        static_cast<uint32_t>(unaff_EDI) +
        static_cast<uint32_t>(*reinterpret_cast<int32_t*>(local_4)))) = 0;
}

// ---------------------------------------------------------------------------
// 0x546140 — observed shape
// Thread-affine critical section around a +1/+1 reference-swapped assignment
// into self+0x194, releasing the previous object when its count reaches zero.
// ---------------------------------------------------------------------------
void FUN_00546140(void* self, void* param_1)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    using VFn = void (*)(void*, int);

    DWORD DVar3 = GetCurrentThreadId();
    if (DAT_0072784c != DVar3) {
        EnterCriticalSection(&DAT_00727834);
        DAT_0072784c = GetCurrentThreadId();
    }
    DAT_00727850 = DAT_00727850 + 1;

    void* puVar2 = *reinterpret_cast<void**>(base + 0x194);
    if (puVar2 != param_1) {
        if (puVar2 != 0) {
            int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar2) + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                VFn fn = *reinterpret_cast<VFn*>(*reinterpret_cast<void**>(puVar2));
                fn(puVar2, 1);
            }
        }
        *reinterpret_cast<void**>(base + 0x194) = param_1;
        if (param_1 != 0) {
            int32_t* piVar1 = reinterpret_cast<int32_t*>(param_1) + 1;
            *piVar1 = *piVar1 + 1;
        }
    }

    DVar3 = GetCurrentThreadId();
    if (DAT_0072784c == DVar3) {
        DAT_00727850 = DAT_00727850 + -1;
        if (DAT_00727850 == 0) {
            DAT_0072784c = 0;
            LeaveCriticalSection(&DAT_00727834);
        }
    }
}

// ---------------------------------------------------------------------------
// 0x5461d0 — observed shape
// Install vtable PTR_FUN_006c18e0, release each element of the +0x04 block
// (element count stored in the dword before the block), then delete the block.
// ---------------------------------------------------------------------------
void FUN_005461d0(void* self)
{
    uint32_t* d = reinterpret_cast<uint32_t*>(self);
    using VFn = void (*)(void*, int);

    d[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c18e0));
    int32_t iVar2 = static_cast<int32_t>(d[1]);
    if (iVar2 != 0) {
        int32_t iVar4 = *reinterpret_cast<int32_t*>(
            reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar2)) - 4);
        int32_t iVar5 = iVar2 + iVar4 * 4;
        if (-1 < iVar4 + -1) {
            do {
                uint32_t* puVar3 = *reinterpret_cast<uint32_t**>(
                    reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar5)) - 4);
                iVar5 = iVar5 + -4;
                if (puVar3 != 0) {
                    int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar3) + 1;
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) {
                        VFn fn = *reinterpret_cast<VFn*>(
                            reinterpret_cast<void*>(static_cast<uintptr_t>(puVar3[0])));
                        fn(puVar3, 1);
                    }
                }
                iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
        }
        operator_delete__(reinterpret_cast<void*>(static_cast<intptr_t>(iVar2 + -4)));
    }
}

// ---------------------------------------------------------------------------
// 0x546220 — observed shape
// Base destruction via FUN_00545450, conditional delete when bit 0 is set.
// ---------------------------------------------------------------------------
void FUN_00546220(void* self, uint8_t param_1)
{
    FUN_00545450();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// ---------------------------------------------------------------------------
// 0x546240 — observed shape
// Base destruction via FUN_005461d0, conditional delete when bit 0 is set.
// ---------------------------------------------------------------------------
void FUN_00546240(void* self, uint8_t param_1)
{
    FUN_005461d0();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// ---------------------------------------------------------------------------
// 0x546260 — observed shape
// Thread-affine critical section around FUN_0056f540, with the same
// last-leaver unlock protocol.
// ---------------------------------------------------------------------------
void FUN_00546260(void* self)
{
    (void)self;

    DWORD DVar1 = GetCurrentThreadId();
    if (DAT_0072784c != DVar1) {
        EnterCriticalSection(&DAT_00727834);
        DAT_0072784c = GetCurrentThreadId();
    }
    DAT_00727850 = DAT_00727850 + 1;
    FUN_0056f540();
    DVar1 = GetCurrentThreadId();
    if (DAT_0072784c == DVar1) {
        DAT_00727850 = DAT_00727850 + -1;
        if (DAT_00727850 == 0) {
            DAT_0072784c = 0;
            LeaveCriticalSection(&DAT_00727834);
        }
    }
}

// ---------------------------------------------------------------------------
// 0x5462d0 — observed shape
// Add a reference to param_1, store it through FUN_00581300 at slot +0x1a0,
// then release the acquired reference.
// ---------------------------------------------------------------------------
void FUN_005462d0(void* self, void* param_1)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    using VFn = void (*)(void*, int);

    void* puVar2 = param_1;
    if (param_1 != 0) {
        int32_t* piVar1 = reinterpret_cast<int32_t*>(param_1) + 1;
        *piVar1 = *piVar1 + 1;
    }
    FUN_00581300(*reinterpret_cast<uint32_t*>(base + 0x1a0), &param_1);
    if (puVar2 != 0) {
        int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar2) + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            VFn fn = *reinterpret_cast<VFn*>(*reinterpret_cast<void**>(puVar2));
            fn(puVar2, 1);
        }
    }
}

// ---------------------------------------------------------------------------
// 0x546510 — observed shape
// Read a count from the +0x15c object stream, size via FUN_0057a3f0, then for
// each index read an object id, resolve it through the +0x130 table (unless
// -1), take a reference, store through FUN_00581300, and release it.
// ---------------------------------------------------------------------------
void FUN_00546510(void* self, int32_t unaff_EBX, uint32_t unaff_EBP)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    using VFn = void (*)(void*, uintptr_t);

    uint32_t local_c;
    void* owner = *reinterpret_cast<void**>(base + 0x15c);
    VFn* vt = reinterpret_cast<VFn*>(*reinterpret_cast<void**>(owner));

    vt[2](&local_c, 4);
    FUN_0057a3f0(unaff_EBP);

    for (uint32_t uVar2 = 0; uVar2 < unaff_EBP; ++uVar2) {
        uint8_t streamBuf[4];
        vt[2](streamBuf, 4);

        uint32_t* puVar3;
        if (unaff_EBX == -1) {
            puVar3 = 0;
        }
        else {
            uint32_t* entries = reinterpret_cast<uint32_t*>(
                static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(base + 0x130)));
            puVar3 = reinterpret_cast<uint32_t*>(
                static_cast<uintptr_t>(entries[static_cast<uint32_t>(unaff_EBX)]));
        }
        if (puVar3 != 0) {
            puVar3[1] = puVar3[1] + 1;
        }
        local_c = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar3));
        FUN_00581300(uVar2, &local_c);
        if (puVar3 != 0) {
            int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar3) + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                using VRelFn = void (*)(void*, int);
                VRelFn fn = *reinterpret_cast<VRelFn*>(
                    reinterpret_cast<void*>(static_cast<uintptr_t>(puVar3[0])));
                fn(puVar3, 1);
            }
        }
    }
}

// ---------------------------------------------------------------------------
// 0x5465c0 — observed shape
// Thread-affine critical section around FUN_0056f540, then clear the four
// vector state dwords at +0x16c, +0x17c, +0x170 and +0x180.
// ---------------------------------------------------------------------------
void FUN_005465c0(void* self)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);

    DWORD DVar1 = GetCurrentThreadId();
    if (DAT_0072784c != DVar1) {
        EnterCriticalSection(&DAT_00727834);
        DAT_0072784c = GetCurrentThreadId();
    }
    DAT_00727850 = DAT_00727850 + 1;
    FUN_0056f540();
    *reinterpret_cast<uint32_t*>(base + 0x16c) = 0;
    *reinterpret_cast<uint32_t*>(base + 0x17c) = 0;
    *reinterpret_cast<uint32_t*>(base + 0x170) = 0;
    *reinterpret_cast<uint32_t*>(base + 0x180) = 0;
    DVar1 = GetCurrentThreadId();
    if (DAT_0072784c == DVar1) {
        DAT_00727850 = DAT_00727850 + -1;
        if (DAT_00727850 == 0) {
            DAT_0072784c = 0;
            LeaveCriticalSection(&DAT_00727834);
        }
    }
}

// ---------------------------------------------------------------------------
// 0x546640 — observed shape
// Base destruction via FUN_005459f0, conditional delete when bit 0 is set.
// ---------------------------------------------------------------------------
void FUN_00546640(void* self, uint8_t param_1)
{
    FUN_005459f0();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// ---------------------------------------------------------------------------
// 0x546660 — observed shape
// Base destruction via FUN_00545ab0, conditional delete when bit 0 is set.
// ---------------------------------------------------------------------------
void FUN_00546660(void* self, uint8_t param_1)
{
    FUN_00545ab0();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// ---------------------------------------------------------------------------
// 0x546680 — observed shape
// Construct: install PTR_LAB_006fd148/PTR_FUN_006c1998, bump DAT_00727444,
// install PTR_FUN_006c17bc at +0x08 and count 0x25 at +0x0c, allocate 0x94
// bytes at +0x10, zero (0x25 & 0x3fffffff) dwords, byte flag at +0x18,
// retarget +0x08 to PTR_FUN_006c1848, store param_1 byte at +0x1c.
// ---------------------------------------------------------------------------
void FUN_00546680(void* self, uint8_t param_1)
{
    uint32_t* d = reinterpret_cast<uint32_t*>(self);

    d[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_LAB_006fd148));
    d[1] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    d[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c1998));
    d[2] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c17bc));
    d[3] = 0x25;
    d[5] = 0;
    uint32_t* puVar1 = reinterpret_cast<uint32_t*>(
        static_cast<uintptr_t>(static_cast<uint32_t>(thunk_FUN_00533c78(0x94))));
    d[4] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar1));
    for (uint32_t uVar2 = d[3] & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar1 = 0;
        puVar1 = puVar1 + 1;
    }
    /* Observed zero-trip byte loop retained from the decompiler structure. */
    for (int32_t iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *reinterpret_cast<uint8_t*>(puVar1) = 0;
        puVar1 = reinterpret_cast<uint32_t*>(
            reinterpret_cast<uint8_t*>(puVar1) + 1);
    }
    *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(d) + 0x18) = 1;
    d[2] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c1848));
    *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(d) + 0x1c) = param_1;
}
