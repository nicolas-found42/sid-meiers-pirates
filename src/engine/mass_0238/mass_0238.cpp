// UNVERIFIED decompiler-derived reconstruction — batch mass_0238.
// Target: Sid Meier's Pirates! (2004), PE32 i386.
// Sources: analysis/pseudocode/functions/0x5e1740.c .. 0x5e25a0.c (Ghidra 12.2).
// No compiler/byte-match claim; shapes follow the supplied listings.
// Globals PTR_*/DAT_* are corpus labels; layouts and types are inferred.

#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---- Observed globals (corpus labels) ----
extern void* PTR_FUN_006c9644;   // hash container vtable (third/final state)
extern void* PTR_FUN_006c9660;   // sub-object vtable at self+0x1c
extern void* PTR_FUN_006c966c;   // hash container vtable (second state)
extern void* PTR_FUN_006c9688;   // hash container vtable (first state)
extern void* PTR_FUN_006c96a4;   // hash container vtable (constructed state)
extern void* PTR_LAB_006c9638;   // hash container vtable (base state)
extern uint8_t DAT_006dd2a4[];   // format/key string passed to vtable[0]

// ---- Callees observed in the supplied listings (signatures inferred) ----
extern void operator_delete(void* memory);
extern void operator_delete__(void* memory);

extern void FUN_005c9a50();                 // corpus passes register arguments only
extern int  FUN_00535540(int* slot);
extern void* FUN_00533c78(uint32_t size);
extern void* thunk_FUN_00533c78(uint32_t size);

extern void FUN_005e0560(int* object);
extern void FUN_005e10f0(void* param);
extern void* FUN_005e12f0();
extern void* FUN_005e1360(void* param);
extern void FUN_005e1490(void* container);
extern void FUN_005e1500(void* self);
extern void FUN_005e15f0(void* self);
extern int  FUN_005e1aa0(void* self);
extern int  FUN_005e1c00(void* self);
extern int  FUN_005e2d50(int object);
extern char FUN_005e2d80(int src, void* dst);
extern void FUN_005e33f0(void* payload);
extern void FUN_005e3410(void* payload);
extern void FUN_005e3ea0(void* key);
extern void FUN_005e3f20(void* value);
extern int  FUN_005e3f50(void* slot);
extern void* FUN_005e4460(void* storage);
extern void FUN_005e45b0(void* param);
extern void FUN_005e4640(int param);
extern char FUN_005e4a40(int provider, uint32_t* out_a, uint32_t* out_b);
extern char FUN_005e4a80(int provider, void* key);
extern void FUN_005e4950(void* entry);
extern int  FUN_005e49d0(int object);
extern int  FUN_005e5920(uint32_t provider, uint32_t index);
extern int  FUN_005e5940(uint32_t provider, uint32_t index);
extern void FUN_005e5aa0(void* param);
extern void FUN_005e62a0(void* param);
extern void FUN_005e62f0(void* param);
extern void thunk_FUN_005e6540(void* param);
extern void FUN_005edba0();

// ===========================================================================
// Forward declarations of this batch (mutually referenced).
// ===========================================================================
void FUN_005e1740(void* self);
void FUN_005e1890(void* self, uint8_t param_1);
void FUN_005e18b0(void* self, void* key);
int  FUN_005e19a0(void* self, uint32_t key, void** out_value);
void FUN_005e1a10(void* self, void** iterator_slot, uint32_t* out_key, void** out_value);
void FUN_005e1da0(void* self, void* param_1);
int  FUN_005e1ee0(void* self, void* extra);
void FUN_005e2030(void* self, uint8_t param_1);
void FUN_005e2060(void* self);
void FUN_005e2120(void* self);
void FUN_005e22f0(void* self);
void FUN_005e2340(void* self);
void FUN_005e2380(void* self, uint32_t param_1);
uint8_t FUN_005e23b0(void* self, int param_1);
void FUN_005e2560(void* param_1);
void FUN_005e25a0(void* self);

// ===========================================================================
// Definitions
// ===========================================================================

// 0x5e1740 — observed shape: chained hash-container destructor; installs
// PTR_FUN_006c9688, and when the flag byte at self+0x10 is set walks the
// self[1] bucket slots deleting each node's payload (node[1]) via
// operator_delete__, then reinstalls PTR_FUN_006c966c and PTR_FUN_006c9644,
// calling FUN_005e1490 after each, and finally frees the bucket array self[2].
void FUN_005e1740(void* self)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    *reinterpret_cast<void**>(in_ECX) = PTR_FUN_006c9688;
    if ((*reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0x10) != '\0') &&
        in_ECX[1] != 0) {
        uint32_t uVar3 = 0;
        do {
            uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(in_ECX[2] + uVar3 * 4);
            while (puVar2 != nullptr) {
                uint32_t* puVar1 = puVar2 + 1;
                puVar2 = reinterpret_cast<uint32_t*>(*puVar2);
                operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(*puVar1)));
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < in_ECX[1]);
    }
    *reinterpret_cast<void**>(in_ECX) = PTR_FUN_006c966c;
    FUN_005e1490(self);
    *reinterpret_cast<void**>(in_ECX) = PTR_FUN_006c9644;
    FUN_005e1490(self);
    operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(in_ECX[2])));
}

// 0x5e1890 — observed shape: vectoring-deleting destructor stub; runs
// FUN_005e1500 on the receiver and conditionally deletes it when the low
// bit of param_1 is set.
void FUN_005e1890(void* self, uint8_t param_1)
{
    FUN_005e1500(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5e18b0 — observed shape: hash-container insert; hashes the key through
// vtable+4, scans the bucket chain comparing node keys through vtable+8;
// on a hit replaces the stored value via vtable+0x10 and vtable+0xc; on a
// miss allocates a node through vtable+0x14, addrefs the key, assigns it
// through vtable+0xc, links the node at the bucket head and increments the
// element count (self[3]). Releases the temporary reference at the exit.
void FUN_005e18b0(void* self, void* key)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    void* const vptr = *reinterpret_cast<void**>(in_ECX);
    using HashFn = int (*)(uintptr_t);
    using EqFn = char (*)(uintptr_t, uintptr_t);
    using NodeFn = void (*)(void*);
    using AssignFn = void (*)(void*, void*);
    using AllocFn = void* (*)();
    HashFn hash = *reinterpret_cast<HashFn*>(reinterpret_cast<char*>(vptr) + 4);
    EqFn equal = *reinterpret_cast<EqFn*>(reinterpret_cast<char*>(vptr) + 8);
    AssignFn assign = *reinterpret_cast<AssignFn*>(reinterpret_cast<char*>(vptr) + 0xc);
    NodeFn replace = *reinterpret_cast<NodeFn*>(reinterpret_cast<char*>(vptr) + 0x10);
    AllocFn allocate = *reinterpret_cast<AllocFn*>(reinterpret_cast<char*>(vptr) + 0x14);

    int* piVar2 = reinterpret_cast<int*>(hash(reinterpret_cast<uintptr_t>(key)));
    int* piVar4 = *reinterpret_cast<int**>(in_ECX[2] + reinterpret_cast<intptr_t>(piVar2) * 4);
    int* piVar5;
    if (piVar4 != nullptr) {
        do {
            piVar5 = reinterpret_cast<int*>(piVar4[1]);
            if (equal(reinterpret_cast<uintptr_t>(piVar5),
                      reinterpret_cast<uintptr_t>(key)) != '\0') {
                replace(piVar4);
                // corpus increments/decrements the temporary refcount slot
                if (piVar2 != nullptr) {
                    piVar2[1] = piVar2[1] + 1;
                }
                assign(piVar4, key);
                goto release_temp;
            }
            piVar4 = reinterpret_cast<int*>(*piVar4);
        } while (piVar4 != nullptr);
    }
    {
        void* newNode = allocate();
        if (key != nullptr) {
            reinterpret_cast<int*>(key)[1] = reinterpret_cast<int*>(key)[1] + 1;
        }
        assign(newNode, key);
        // corpus reads the bucket index from a stack slot; the computed hash
        // (piVar2) is the only index produced in this frame.
        *reinterpret_cast<void**>(newNode) =
            *reinterpret_cast<void**>(in_ECX[2] + reinterpret_cast<intptr_t>(piVar2) * 4);
        *reinterpret_cast<void**>(in_ECX[2] + reinterpret_cast<intptr_t>(piVar2) * 4) = newNode;
        in_ECX[3] = in_ECX[3] + 1;
        piVar2 = reinterpret_cast<int*>(key);
    }
release_temp:
    if (piVar2 != nullptr) {
        int* piVar4b = piVar2 + 1;
        *piVar4b = *piVar4b + -1;
        if (*piVar4b == 0) {
            using DeleteFn = void (*)(int);
            DeleteFn fn = *reinterpret_cast<DeleteFn*>(reinterpret_cast<uintptr_t*>(piVar2));
            fn(1);
        }
    }
}

// 0x5e19a0 — observed shape: hash-container lookup; hashes the key through
// vtable+4, walks the bucket chain comparing keys through vtable+8; on a
// hit releases the caller's previous value, stores the entry's value into
// *out_value with a refcount bump, and returns 1; otherwise returns 0.
// NEEDS_MANUAL: the corpus passes the single slot (out_value) to the
// hash/compare vtable calls; the key arrives in an unmodelled register.
int FUN_005e19a0(void* self, uint32_t key, void** out_value)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    void* const vptr = *reinterpret_cast<void**>(in_ECX);
    using HashFn = int (*)(uintptr_t);
    using EqFn = char (*)(uintptr_t, uintptr_t);
    HashFn hash = *reinterpret_cast<HashFn*>(reinterpret_cast<char*>(vptr) + 4);
    EqFn equal = *reinterpret_cast<EqFn*>(reinterpret_cast<char*>(vptr) + 8);

    int iVar4 = hash(static_cast<uintptr_t>(key));
    int* piVar5 = *reinterpret_cast<int**>(in_ECX[2] + iVar4 * 4);
    if (piVar5 != nullptr) {
        do {
            if (equal(static_cast<uintptr_t>(key),
                      static_cast<uintptr_t>(piVar5[1])) != '\0') {
                uint32_t* puVar2 = static_cast<uint32_t*>(*out_value);
                if (puVar2 != reinterpret_cast<uint32_t*>(piVar5[2])) {
                    if (puVar2 != nullptr) {
                        int* piVar1 = reinterpret_cast<int*>(puVar2) + 1;
                        *piVar1 = *piVar1 + -1;
                        if (*piVar1 == 0) {
                            using DeleteFn = void (*)(int);
                            DeleteFn fn = *reinterpret_cast<DeleteFn*>(*reinterpret_cast<uintptr_t*>(puVar2));
                            fn(1);
                        }
                    }
                    int iVar4b = piVar5[2];
                    *out_value = reinterpret_cast<void*>(static_cast<intptr_t>(iVar4b));
                    if (iVar4b != 0) {
                        *reinterpret_cast<int*>(iVar4b + 4) =
                            *reinterpret_cast<int*>(iVar4b + 4) + 1;
                    }
                }
                return 1;
            }
            piVar5 = reinterpret_cast<int*>(*piVar5);
        } while (piVar5 != nullptr);
    }
    return 0;
}

// 0x5e1a10 — observed shape: hash-container iterator step; copies the
// current node's key to *out_key, releases the caller's previous value and
// stores the node value into *out_value (refcount bumped); advances to the
// next node, or, when the chain ends, resumes at hash(node key)+1 by
// scanning the remaining bucket slots; writes nullptr when exhausted.
// The container's vtable/count/bucket array live at self[0], self[1], self[2].
void FUN_005e1a10(void* self, void** iterator_slot, uint32_t* out_key, void** out_value)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    int* piVar5 = static_cast<int*>(*iterator_slot);
    *out_key = static_cast<uint32_t>(piVar5[1]);

    uint32_t* puVar2 = static_cast<uint32_t*>(*out_value);
    if (puVar2 != reinterpret_cast<uint32_t*>(piVar5[2])) {
        if (puVar2 != nullptr) {
            int* piVar1 = reinterpret_cast<int*>(puVar2) + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                using DeleteFn = void (*)(int);
                DeleteFn fn = *reinterpret_cast<DeleteFn*>(*reinterpret_cast<uintptr_t*>(puVar2));
                fn(1);
            }
        }
        int iVar3 = piVar5[2];
        *reinterpret_cast<int*>(out_value) = iVar3;
        if (iVar3 != 0) {
            *reinterpret_cast<int*>(iVar3 + 4) = *reinterpret_cast<int*>(iVar3 + 4) + 1;
        }
    }

    if (*piVar5 != 0) {
        *iterator_slot = reinterpret_cast<void*>(*piVar5);
        return;
    }

    void* const vptr = *reinterpret_cast<void**>(in_ECX);
    using HashFn = int (*)(uintptr_t);
    HashFn hash = *reinterpret_cast<HashFn*>(reinterpret_cast<char*>(vptr) + 4);
    int iVar3 = hash(static_cast<uintptr_t>(static_cast<uint32_t>(piVar5[1])));
    uint32_t uVar4 = static_cast<uint32_t>(iVar3) + 1;
    if (uVar4 < in_ECX[1]) {
        int* piVar6 = reinterpret_cast<int*>(in_ECX[2] + uVar4 * 4);
        do {
            if (*piVar6 != 0) {
                *iterator_slot = reinterpret_cast<void*>(*piVar6);
                return;
            }
            uVar4 = uVar4 + 1;
            piVar6 = piVar6 + 1;
        } while (uVar4 < in_ECX[1]);
    }
    *iterator_slot = nullptr;
}

// 0x5e1aa0 — observed shape: iterate the embedded hash map (container at
// self+0x2c header: vptr at +0x2c... i.e. map base self+8) producing the
// next non-null item of each stored collection; iterator node pointer at
// self+0x2c, collection cursor index at self+0x30, current collection at
// self+0x34; collection item array is at collection+0x28, count at +0x30.
// Returns 0 when the map is exhausted.
int FUN_005e1aa0(void* self)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    int iVar2 = *reinterpret_cast<int*>(base + 0x2c);
    do {
        if (iVar2 == 0) {
            return 0;
        }
        if (*reinterpret_cast<int*>(base + 0x34) == 0) {
            void* local_14 = nullptr;
            uint8_t local_10[4];
            FUN_005e1a10(base + 8, reinterpret_cast<void**>(base + 0x2c),
                         reinterpret_cast<uint32_t*>(local_10), &local_14);
            *reinterpret_cast<void**>(base + 0x34) = local_14;
            if (local_14 != nullptr) {
                uint32_t* piVar1 = static_cast<uint32_t*>(local_14) + 1;
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    using DeleteFn = void (*)(int);
                    DeleteFn fn = *reinterpret_cast<DeleteFn*>(*reinterpret_cast<uintptr_t*>(local_14));
                    fn(1);
                }
            }
        }
        iVar2 = *reinterpret_cast<int*>(base + 0x34);
        if (*reinterpret_cast<uint32_t*>(base + 0x30) <
            *reinterpret_cast<uint32_t*>(iVar2 + 0x30)) {
            do {
                uint32_t uVar3 = *reinterpret_cast<uint32_t*>(base + 0x30);
                *reinterpret_cast<uint32_t*>(base + 0x30) = uVar3 + 1;
                if (uVar3 < *reinterpret_cast<uint32_t*>(iVar2 + 0x30)) {
                    int iVar4 = *reinterpret_cast<int*>(
                        *reinterpret_cast<int*>(iVar2 + 0x28) + uVar3 * 4);
                    if (iVar4 != 0) {
                        return iVar4;
                    }
                }
            } while (*reinterpret_cast<uint32_t*>(base + 0x30) <
                     *reinterpret_cast<uint32_t*>(
                         *reinterpret_cast<int*>(base + 0x34) + 0x30));
        }
        *reinterpret_cast<uint32_t*>(base + 0x34) = 0;
        *reinterpret_cast<uint32_t*>(base + 0x30) = 0;
        iVar2 = *reinterpret_cast<int*>(base + 0x2c);
    } while (true);
}

// 0x5e1b70 — observed shape: keyed element fetch; looks the key up through
// FUN_005e19a0, and if the index is below the collection count (+0x30)
// returns the element from the collection array (+0x28); releases the
// looked-up collection and returns 0 on miss/out-of-range.
uint32_t FUN_005e1b70(void* self, uint32_t key, uint32_t param_2)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t uVar2 = 0;
    void* local_10 = nullptr;
    FUN_005e19a0(base + 8, key, &local_10);
    if (local_10 == nullptr) {
        return 0;
    }
    uint32_t* entry = static_cast<uint32_t*>(local_10);
    if (param_2 < entry[0xc]) {
        uVar2 = *reinterpret_cast<uint32_t*>(entry[10] + param_2 * 4);
    }
    int iVar1 = static_cast<int>(entry[1]);
    entry[1] = static_cast<uint32_t>(iVar1 - 1);
    if (iVar1 - 1 == 0) {
        using DeleteFn = void (*)(int);
        DeleteFn fn = *reinterpret_cast<DeleteFn*>(reinterpret_cast<uintptr_t*>(entry));
        fn(1);
    }
    return uVar2;
}

// 0x5e1c00 — observed shape: fetch the collection for the current map
// node (node pointer at self+0x2c) and forward it to FUN_005e3f50 with the
// sub-object at self+0x38; releases the looked-up collection and returns 0
// when there is no iterator state.
uint32_t FUN_005e1c00(void* self)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    if (*reinterpret_cast<int*>(base + 0x2c) != 0) {
        void* local_14 = nullptr;
        uint8_t local_10[4];
        FUN_005e1a10(base + 8, reinterpret_cast<void**>(base + 0x2c),
                     reinterpret_cast<uint32_t*>(local_10), &local_14);
        uint32_t* puVar2 = static_cast<uint32_t*>(local_14);
        if (local_14 != nullptr) {
            uint32_t uVar3 = FUN_005e3f50(base + 0x38);
            int iVar1 = static_cast<int>(puVar2[1]);
            puVar2[1] = static_cast<uint32_t>(iVar1 - 1);
            if (iVar1 - 1 == 0) {
                using DeleteFn = void (*)(int);
                DeleteFn fn = *reinterpret_cast<DeleteFn*>(reinterpret_cast<uintptr_t*>(puVar2));
                fn(1);
            }
            return uVar3;
        }
    }
    return 0;
}

// 0x5e1ca0 — observed shape: teardown of the loaded map state; releases
// self+0x4c (vtable+0x124 with 0, then vtable+8) and clears +0x4c/+0x50,
// then drains the embedded map (container at self+8) releasing each value
// through FUN_005e3f20, and finally frees the +0x20 list payloads through
// FUN_005e33f0.
void FUN_005e1ca0(void* self)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    int* piVar3 = *reinterpret_cast<int**>(base + 0x4c);
    if (piVar3 == nullptr) {
        return;
    }
    if (*reinterpret_cast<uint8_t*>(base + 0x50) != '\0') {
        using Fn124 = void (*)(void*, int);
        Fn124 fn = *reinterpret_cast<Fn124*>(reinterpret_cast<char*>(piVar3) + 0x124);
        fn(piVar3, 0);
    }
    {
        void* obj = *reinterpret_cast<void**>(base + 0x4c);
        using Fn8 = void (*)(void*);
        Fn8 fn = *reinterpret_cast<Fn8*>(reinterpret_cast<char*>(*reinterpret_cast<void**>(obj)) + 8);
        fn(obj);
    }
    *reinterpret_cast<uint32_t*>(base + 0x4c) = 0;
    *reinterpret_cast<uint8_t*>(base + 0x50) = 0;

    int iStack_14 = 0;
    uint32_t uVar2 = 0;
    if (*reinterpret_cast<uint32_t*>(base + 0xc) != 0) {
        int* piVar4 = *reinterpret_cast<int**>(base + 0x10);
        do {
            if (*piVar4 != 0) {
                iStack_14 = (*reinterpret_cast<int**>(base + 0x10))[uVar2];
                goto first_value;
            }
            uVar2 = uVar2 + 1;
            piVar4 = piVar4 + 1;
        } while (uVar2 < *reinterpret_cast<uint32_t*>(base + 0xc));
    }
    iStack_14 = 0;
first_value:
    while (iStack_14 != 0) {
        void* puStack_18 = nullptr;
        uint8_t auStack_10[4];
        FUN_005e1a10(base + 8, reinterpret_cast<void**>(&iStack_14),
                     reinterpret_cast<uint32_t*>(auStack_10), &puStack_18);
        uint32_t* puVar1 = static_cast<uint32_t*>(puStack_18);
        FUN_005e3f20(puStack_18);
        if (puVar1 != nullptr) {
            int* piVar5 = reinterpret_cast<int*>(puVar1) + 1;
            *piVar5 = *piVar5 + -1;
            if (*piVar5 == 0) {
                using DeleteFn = void (*)(int);
                DeleteFn fn = *reinterpret_cast<DeleteFn*>(reinterpret_cast<uintptr_t*>(puVar1));
                fn(1);
            }
        }
    }

    int* puVar1 = *reinterpret_cast<int**>(base + 0x20);
    iStack_14 = 0;
    while (puVar1 != nullptr) {
        int* node = puVar1;
        puVar1 = reinterpret_cast<int*>(*puVar1);
        // corpus omits the register argument; the node payload is node[2]
        FUN_005e33f0(reinterpret_cast<void*>(static_cast<uintptr_t>(node[2])));
    }
}

// 0x5e1da0 — observed shape: populate collections for the loaded provider;
// walks the +0x20 list, asks the provider object at param_1[0xd] through
// vtable+4 for each entry, marks entry+0x38 when FUN_005e4a80 accepts the
// key and calls FUN_005e4950; then looks the provider entry up in the map
// (container at self+8); when missing it allocates 0x44 bytes, constructs
// the value via FUN_005e4460, swaps it into the out slot with refcount
// handling, calls FUN_005e3ea0/FUN_005e18b0, then FUN_005e45b0(param_1)
// and releases the value.
void FUN_005e1da0(void* self, void* param_1)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(base + 0x20);
    uint32_t** param = static_cast<uint32_t**>(param_1);
    while (puVar2 != nullptr) {
        uint32_t* ppuVar6 = reinterpret_cast<uint32_t*>(puVar2[2]);
        uint32_t* puVar3 = reinterpret_cast<uint32_t*>(ppuVar6[1]);
        puVar2 = reinterpret_cast<uint32_t*>(*puVar2);

        void* owner = reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(param[0xd]));
        using LookupFn = void* (*)(void*);
        LookupFn lookup = *reinterpret_cast<LookupFn*>(
            reinterpret_cast<char*>(*reinterpret_cast<void**>(owner)) + 4);
        lookup(owner); // NEEDS_MANUAL: corpus leaves this call's register arguments unmodelled

        char cVar5 = FUN_005e4a80(*reinterpret_cast<int*>(base + 0x4c), puVar3);
        if (cVar5 != '\0') {
            *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(ppuVar6) + 0x38) = 1;
            FUN_005e4950(ppuVar6);
        }
    }

    uint32_t* ppuVar6 = static_cast<uint32_t*>(param[2]);
    void* owner = reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(param[0xd]));
    using AllocFn = void* (*)(void*);
    AllocFn allocate = *reinterpret_cast<AllocFn*>(
        reinterpret_cast<char*>(*reinterpret_cast<void**>(owner)) + 4);
    if (ppuVar6 == nullptr) {
        ppuVar6 = static_cast<uint32_t*>(allocate(owner));
    }

    uint32_t** ppuStack_14 = nullptr;
    char cVar5 = static_cast<char>(FUN_005e19a0(
        base + 8, static_cast<uint32_t>(reinterpret_cast<uintptr_t>(ppuVar6)),
        reinterpret_cast<void**>(&ppuStack_14)));
    uint32_t** ppuVar8 = ppuStack_14;
    if ((cVar5 == '\0') || (ppuStack_14 == nullptr)) {
        uint8_t* puStack_10 = static_cast<uint8_t*>(FUN_00533c78(0x44));
        uint32_t** ppuVar7;
        if (puStack_10 == nullptr) {
            ppuVar7 = nullptr;
        } else {
            ppuVar7 = static_cast<uint32_t**>(FUN_005e4460(puStack_10));
        }
        if (ppuVar8 != ppuVar7) {
            if (ppuVar8 != nullptr) {
                uint32_t** ppuVar1 = ppuVar8 + 1;
                *ppuVar1 = reinterpret_cast<uint32_t*>(
                    reinterpret_cast<intptr_t>(*ppuVar1) - 1);
                if (*ppuVar1 == nullptr) {
                    using DeleteFn = void (*)();
                    DeleteFn fn = *reinterpret_cast<DeleteFn*>(
                        reinterpret_cast<uintptr_t*>(*ppuVar8));
                    fn();
                }
            }
            ppuVar8 = ppuVar7;
            ppuStack_14 = ppuVar7;
            if (ppuVar7 != nullptr) {
                ppuVar7[1] = reinterpret_cast<uint32_t*>(
                    reinterpret_cast<intptr_t>(ppuVar7[1]) + 1);
            }
        }
        FUN_005e3ea0(ppuVar6);
        if (ppuVar8 != nullptr) {
            ppuVar8[1] = reinterpret_cast<uint32_t*>(
                reinterpret_cast<intptr_t>(ppuVar8[1]) + 1);
        }
        FUN_005e18b0(base + 8, ppuVar6);
    }

    FUN_005e45b0(param_1);
    if (ppuVar8 != nullptr) {
        uint32_t** ppuVar6b = ppuVar8 + 1;
        *ppuVar6b = reinterpret_cast<uint32_t*>(
            reinterpret_cast<intptr_t>(*ppuVar6b) - 1);
        if (*ppuVar6b == nullptr) {
            using DeleteFn = void (*)();
            DeleteFn fn = *reinterpret_cast<DeleteFn*>(
                reinterpret_cast<uintptr_t*>(*ppuVar8));
            fn();
        }
    }
}

// 0x5e1ee0 — observed shape: reload the provider state; requires both
// self+0x4c and the flag at self+0x50, calls vtable[0] of that object with
// DAT_006dd2a4 and a local scratch, walks the +0x20 list calling
// thunk_FUN_005e6540 with the caller's extra object, drains the embedded
// map through FUN_005e1a10, then releases the extra object (vtable+8) and
// returns 1.
// NEEDS_MANUAL: corpus passes stack-register slots to FUN_005e1a10 here.
int FUN_005e1ee0(void* self, void* extra)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    if ((*reinterpret_cast<int*>(base + 0x4c) == 0) ||
        (*reinterpret_cast<uint8_t*>(base + 0x50) == '\0')) {
        return 0;
    }

    uint32_t local_1c = 0;
    {
        void* obj = *reinterpret_cast<void**>(base + 0x4c);
        using Fn0 = void (*)(void*, uint8_t*, uint32_t*);
        Fn0 fn = *reinterpret_cast<Fn0*>(*reinterpret_cast<void**>(obj));
        fn(obj, DAT_006dd2a4, &local_1c);
    }

    uint32_t* puVar1 = *reinterpret_cast<uint32_t**>(base + 0x20);
    while (puVar1 != nullptr) {
        puVar1 = reinterpret_cast<uint32_t*>(*puVar1);
        thunk_FUN_005e6540(extra);
    }

    int iVar3 = 0;
    uint32_t uVar2 = 0;
    if (*reinterpret_cast<uint32_t*>(base + 0xc) != 0) {
        int* piVar4 = *reinterpret_cast<int**>(base + 0x10);
        do {
            if (*piVar4 != 0) {
                iVar3 = (*reinterpret_cast<int**>(base + 0x10))[uVar2];
                goto first_value;
            }
            uVar2 = uVar2 + 1;
            piVar4 = piVar4 + 1;
        } while (uVar2 < *reinterpret_cast<uint32_t*>(base + 0xc));
    }
    iVar3 = 0;
first_value:
    while (iVar3 != 0) {
        void* value = nullptr;
        uint32_t key = 0;
        FUN_005e1a10(base + 8, reinterpret_cast<void**>(&iVar3), &key, &value);
    }

    {
        using Fn8 = void (*)(void*);
        Fn8 fn = *reinterpret_cast<Fn8*>(
            reinterpret_cast<char*>(*reinterpret_cast<void**>(extra)) + 8);
        fn(extra);
    }
    return 1;
}

// 0x5e2030 — observed shape: vectoring-deleting destructor stub; runs
// FUN_005e1740 on the receiver and conditionally deletes it when the low
// bit of param_1 is set.
void FUN_005e2030(void* self, uint8_t param_1)
{
    FUN_005e1740(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x5e2060 — observed shape: constructor; clears [0]/[1], installs
// PTR_FUN_006c9644 at [2] with bucket count 0x25 at [3], allocates and
// zeroes the 0x25-dword bucket array at [4], sets the byte flag at +0x18,
// installs PTR_FUN_006c96a4 at [2], initialises [7] with PTR_FUN_006c9660
// and zeros [8..0xd], runs FUN_005e62a0, then clears [0x13], the byte at
// +0x50 and the byte at +0x51.
void FUN_005e2060(void* self)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    *in_ECX = 0;
    in_ECX[1] = 0;
    in_ECX[2] = reinterpret_cast<uint32_t>(PTR_FUN_006c9644);
    in_ECX[3] = 0x25;
    in_ECX[5] = 0;
    uint32_t* puVar1 = static_cast<uint32_t*>(thunk_FUN_00533c78(0x94));
    in_ECX[4] = reinterpret_cast<uint32_t>(puVar1);
    for (uint32_t uVar2 = in_ECX[3] & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar1 = 0;
        puVar1 = puVar1 + 1;
    }
    for (int iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *reinterpret_cast<uint8_t*>(puVar1) = 0;
        puVar1 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar1) + 1);
    }
    *reinterpret_cast<uint8_t*>(in_ECX + 6) = 1;
    in_ECX[2] = reinterpret_cast<uint32_t>(PTR_FUN_006c96a4);
    in_ECX[10] = 0;
    in_ECX[8] = 0;
    in_ECX[9] = 0;
    in_ECX[7] = reinterpret_cast<uint32_t>(PTR_FUN_006c9660);
    in_ECX[0xb] = 0;
    in_ECX[0xc] = 0;
    in_ECX[0xd] = 0;
    FUN_005e62a0(self);
    in_ECX[0x13] = 0;
    *reinterpret_cast<uint8_t*>(in_ECX + 0x14) = 0;
    *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0x51) = 0;
}

// 0x5e2120 — observed shape: destructor/cleanup; calls FUN_005c9a50,
// FUN_005e12f0 and releases its result through vtable+8, runs FUN_005e1ca0,
// frees *self, builds a temporary container (vptr PTR_FUN_006c9644, count
// 0x25, allocated 0x94-byte bucket array zeroed), selects the first
// non-null value into [0xb]/self+0x2c and drains the map through
// FUN_005e1a10/FUN_005e18b0, then FUN_005e1490 on the map at self+8,
// destroys the +0x20 list payloads, and re-installs the sub-object vptrs
// at self+0x1c (PTR_FUN_006c9660 then PTR_LAB_006c9638) around
// FUN_005edba0/FUN_005e5aa0/FUN_005e15f0 calls.
// NEEDS_MANUAL: corpus leaves several register-only call arguments here.
void FUN_005e2120(void* self)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    FUN_005c9a50();
    {
        int* piVar2 = static_cast<int*>(FUN_005e12f0());
        void* vptr = *reinterpret_cast<void**>(piVar2);
        using Fn8 = void (*)(void*);
        Fn8 fn = *reinterpret_cast<Fn8*>(reinterpret_cast<char*>(vptr) + 8);
        fn(piVar2);
    }
    FUN_005e1ca0(self);
    operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(in_ECX[0])));

    void* ppuStack_24 = PTR_FUN_006c9644;
    uint32_t uStack_20 = 0x25;
    uint32_t uStack_18 = 0;
    uint32_t* puStack_1c = static_cast<uint32_t*>(thunk_FUN_00533c78(0x94));
    uint32_t uVar3 = 0;
    uint32_t* puVar6 = puStack_1c;
    for (uint32_t uVar5 = uStack_20; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
    }
    (void)ppuStack_24;
    (void)uStack_18;
    uint8_t uStack_14 = 1;
    (void)uStack_14;
    ppuStack_24 = PTR_FUN_006c96a4;
    int iVar4;
    if (uStack_20 != 0) {
        do {
            if (puStack_1c[uVar3] != 0) {
                iVar4 = static_cast<int>(puStack_1c[uVar3]);
                goto first_entry;
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < uStack_20);
    }
    iVar4 = 0;
first_entry:
    {
        int* piVar2 = reinterpret_cast<int*>(in_ECX + 0xb);
        *piVar2 = iVar4;
        while (iVar4 != 0) {
            uint32_t auStack_30[2];
            void* tmpValue = nullptr;
            // corpus omits the third (register) iterator out-argument
            FUN_005e1a10(base + 8, reinterpret_cast<void**>(piVar2),
                         reinterpret_cast<uint32_t*>(auStack_30), &tmpValue);
            FUN_005e18b0(base + 8, reinterpret_cast<void*>(
                static_cast<uintptr_t>(auStack_30[0])));
            iVar4 = *piVar2;
        }
    }

    FUN_005e1490(base + 8);
    {
        uint32_t* puVar6b = reinterpret_cast<uint32_t*>(in_ECX[8]);
        while (puVar6b != nullptr) {
            void* pvVar1 = reinterpret_cast<void*>(static_cast<uintptr_t>(puVar6b[2]));
            puVar6b = reinterpret_cast<uint32_t*>(*puVar6b);
            if (pvVar1 != nullptr) {
                FUN_005e3410(pvVar1);
                operator_delete(pvVar1);
            }
        }
    }
    {
        uint32_t* puVar6b = in_ECX + 7;
        FUN_005edba0();
        FUN_005e15f0(puVar6b);
        FUN_005e5aa0(puVar6b);
        *reinterpret_cast<void**>(puVar6b) = PTR_FUN_006c9660;
        FUN_005edba0();
        *reinterpret_cast<void**>(puVar6b) = PTR_LAB_006c9638;
        FUN_005e15f0(puVar6b);
    }
}

// 0x5e22f0 — observed shape: bind the iterator to the first non-null value
// of the embedded map (count +0xc, bucket array +0x10); stores it at
// self+0x2c, resets self+0x30/self+0x34, then calls FUN_005e1aa0 to walk.
void FUN_005e22f0(void* self)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    int iVar2;
    uint32_t uVar1 = 0;
    if (*reinterpret_cast<uint32_t*>(base + 0xc) != 0) {
        int* piVar3 = *reinterpret_cast<int**>(base + 0x10);
        do {
            if (*piVar3 != 0) {
                iVar2 = (*reinterpret_cast<int**>(base + 0x10))[uVar1];
                goto first_value;
            }
            uVar1 = uVar1 + 1;
            piVar3 = piVar3 + 1;
        } while (uVar1 < *reinterpret_cast<uint32_t*>(base + 0xc));
    }
    iVar2 = 0;
first_value:
    *reinterpret_cast<int*>(base + 0x2c) = iVar2;
    if (iVar2 == 0) {
        return;
    }
    *reinterpret_cast<uint32_t*>(base + 0x34) = 0;
    *reinterpret_cast<uint32_t*>(base + 0x30) = 0;
    FUN_005e1aa0(self);
}

// 0x5e2340 — observed shape: select the first non-null value of the
// embedded map (count +0xc, buckets +0x10), store it at self+0x2c and call
// FUN_005e1c00; clears self+0x2c and still calls FUN_005e1c00 when empty.
void FUN_005e2340(void* self)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t uVar1 = 0;
    if (*reinterpret_cast<uint32_t*>(base + 0xc) != 0) {
        int* piVar2 = *reinterpret_cast<int**>(base + 0x10);
        do {
            if (*piVar2 != 0) {
                *reinterpret_cast<int*>(base + 0x2c) =
                    (*reinterpret_cast<int**>(base + 0x10))[uVar1];
                FUN_005e1c00(self);
                return;
            }
            uVar1 = uVar1 + 1;
            piVar2 = piVar2 + 1;
        } while (uVar1 < *reinterpret_cast<uint32_t*>(base + 0xc));
    }
    *reinterpret_cast<uint32_t*>(base + 0x2c) = 0;
    FUN_005e1c00(self);
}

// 0x5e2380 — observed shape: provider rebind sequence; FUN_005e12f0,
// FUN_005e10f0(param_1), FUN_005e12f0, FUN_005e1360(*self), FUN_005e1ee0.
void FUN_005e2380(void* self, uint32_t param_1)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    FUN_005e12f0();
    FUN_005e10f0(reinterpret_cast<void*>(static_cast<uintptr_t>(param_1)));
    FUN_005e12f0();
    FUN_005e1360(reinterpret_cast<void*>(static_cast<uintptr_t>(in_ECX[0])));
    FUN_005e1ee0(self, nullptr);
}

// 0x5e23b0 — observed shape: one-shot provider load; when self+0x4c is set
// and the flag at self+0x51 is clear, queries FUN_005e4a40 for two counts,
// runs FUN_005e62f0, builds a 0x3c-byte object per first-list item through
// FUN_005e2d50/FUN_005e2d80/FUN_005e0560, builds a 0x38-byte object per
// second-list item through FUN_005e49d0/FUN_005e4640/FUN_005e1da0, then
// frees the +0x20 list entries whose byte at +0x38 is clear through
// FUN_005e3410/operator_delete and notifies FUN_00535540, sets the guard
// byte at self+0x51 and returns 1.
uint8_t FUN_005e23b0(void* self, int param_1)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t uVar6 = 0;
    if ((*reinterpret_cast<int*>(base + 0x4c) != 0) &&
        (*reinterpret_cast<uint8_t*>(base + 0x51) == '\0')) {
        uint32_t local_18 = 0;
        uint32_t local_14 = 0;
        char cVar3 = FUN_005e4a40(*reinterpret_cast<int*>(base + 0x4c),
                                  &local_18, &local_14);
        if (cVar3 == '\0') {
            return 0;
        }
        FUN_005e62f0(self);
        if (local_18 != 0) {
            do {
                int iVar4 = FUN_005e5920(
                    *reinterpret_cast<uint32_t*>(base + 0x4c), uVar6);
                if (iVar4 != 0) {
                    int local_10 = static_cast<int>(
                        reinterpret_cast<uintptr_t>(FUN_00533c78(0x3c)));
                    if (local_10 == 0) {
                        local_10 = 0;
                    } else {
                        local_10 = FUN_005e2d50(local_10);
                    }
                    cVar3 = FUN_005e2d80(iVar4, base + 0x38);
                    if (cVar3 != '\0') {
                        FUN_005e0560(&local_10);
                    }
                }
                uVar6 = uVar6 + 1;
            } while (uVar6 < local_18);
        }
        uVar6 = 0;
        if (local_14 != 0) {
            do {
                int iVar4 = FUN_005e5940(
                    *reinterpret_cast<uint32_t*>(base + 0x4c), uVar6);
                if (iVar4 != 0) {
                    int local_10 = static_cast<int>(
                        reinterpret_cast<uintptr_t>(FUN_00533c78(0x38)));
                    int iVar5;
                    if (local_10 == 0) {
                        iVar5 = 0;
                    } else {
                        iVar5 = FUN_005e49d0(local_10);
                    }
                    FUN_005e4640(iVar4);
                    *reinterpret_cast<int*>(iVar5 + 0x14) =
                        static_cast<int>(reinterpret_cast<intptr_t>(self));
                    FUN_005e1da0(reinterpret_cast<void*>(static_cast<uintptr_t>(iVar5)),
                                 reinterpret_cast<void*>(static_cast<uintptr_t>(param_1)));
                }
                uVar6 = uVar6 + 1;
            } while (uVar6 < local_14);
        }
        {
            int* piVar1 = *reinterpret_cast<int**>(base + 0x20);
            while (piVar1 != nullptr) {
                void* pvVar2 = reinterpret_cast<void*>(static_cast<uintptr_t>(piVar1[2]));
                piVar1 = reinterpret_cast<int*>(*piVar1);
                if (*reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(pvVar2) + 0x38)
                    == '\0') {
                    FUN_005e3410(pvVar2);
                    operator_delete(pvVar2);
                    if (piVar1 == nullptr) {
                        param_1 = 0;
                    } else {
                        param_1 = piVar1[1];
                    }
                    FUN_00535540(&param_1);
                }
            }
        }
        *reinterpret_cast<uint8_t*>(base + 0x51) = 1;
    }
    return 1;
}

// 0x5e2560 — observed shape: reference-counted object release plus delete;
// releases the object stored at param_1+8 (vtable[0](1) when the count
// drops to zero), clears the slot, then runs FUN_005e25a0 on param_1 and
// deletes it.
void FUN_005e2560(void* param_1)
{
    uint8_t* base = static_cast<uint8_t*>(param_1);
    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(base + 8);
    if (puVar2 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar2) + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using DeleteFn = void (*)(int);
            DeleteFn fn = *reinterpret_cast<DeleteFn*>(reinterpret_cast<uintptr_t*>(puVar2));
            fn(1);
        }
        *reinterpret_cast<uint32_t*>(base + 8) = 0;
    }
    if (param_1 != nullptr) {
        FUN_005e25a0(param_1);
        operator_delete(param_1);
    }
}

// 0x5e25a0 — observed shape: release the object stored in the receiver's
// field +8 (decrement its refcount at +4 and call vtable[0](1) when it
// reaches zero); the slot itself is left untouched.
void FUN_005e25a0(void* self)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(base + 8);
    if (puVar2 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar2) + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            using DeleteFn = void (*)(int);
            DeleteFn fn = *reinterpret_cast<DeleteFn*>(reinterpret_cast<uintptr_t*>(puVar2));
            fn(1);
        }
    }
}
