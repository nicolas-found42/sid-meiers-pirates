// Reconstruction candidates for batch mass_0354 — Sid Meier's Pirates! (2004), PE32 i386.
// UNVERIFIED: translated by hand from Ghidra 12.2 pseudocode listings; no build was run.
// Corpus: analysis/pseudocode/functions/0x6be510.c ... 0x6be910.c
// The listings in this batch take no register receiver; they are free functions
// operating on static globals, on static arrays of 3-dword records, and on
// arrays of intrusive reference-counted object pointers.
#include <cstdint>
#include <cstddef>

// ---------------------------------------------------------------------------
// External data referenced by the translated listings.
// ---------------------------------------------------------------------------
extern int32_t  DAT_00727444;   // 0x727444: live-record counter

extern int      DAT_008d897c;   // 0x8d897c: cursor base of the 9-record array (0x6be510)
extern int      DAT_008d82bc;   // 0x8d82bc: cursor base of the 10-record array (0x6be590)

extern uint32_t DAT_008db620;   // 0x8db620: tail of a 0x3c0-entry, 3-dword record array
extern uint32_t DAT_008db680;   // 0x8db680: tail of an 8-entry, 3-dword record array
extern uint32_t DAT_008dbd10;   // 0x8dbd10: tail of a 0x8c-entry, 3-dword record array
extern uint32_t DAT_008dc310;   // 0x8dc310: tail of a 0x80-entry, 3-dword record array

extern uint32_t PTR_DAT_007267d0; // 0x7267d0: pointer slot (owned block start + 8)
extern uint32_t PTR_DAT_007267f0; // 0x7267f0: pointer slot (owned block start + 8)
extern uint32_t PTR_DAT_00726804; // 0x726804: pointer slot (owned block start + 8)
extern uint32_t PTR_PTR_007267d4; // 0x7267d4: vtable slot for the 0x6be760 pair

extern uint32_t DAT_008dc314;   // 0x8dc314: refcounted object pointer
extern uint32_t DAT_008dc318;   // 0x8dc318: refcounted object pointer
extern uint32_t DAT_008dc31c;   // 0x8dc31c: refcounted object pointer

extern uint32_t DAT_008dc920;   // 0x8dc920: tail of an array of object pointers
extern uint32_t DAT_008dc954;   // 0x8dc954: tail of a 3-slot pointer group / first slot
extern uint32_t DAT_008dc95c;   // 0x8dc95c: refcounted object pointer
extern uint32_t DAT_008dc960;   // 0x8dc960: refcounted object pointer
extern uint32_t DAT_008dc964;   // 0x8dc964: refcounted object pointer
extern uint32_t DAT_008dc968;   // 0x8dc968: refcounted object pointer

extern uint8_t  DAT_008cacc8;   // 0x8cacc8: static sentinel object (never freed)
extern uint8_t  DAT_008cacd0;   // 0x8cacd0: static "empty" block stamped back into slots

// Thunks written into, and restored out of, the first dword of each record.
extern uint8_t  PTR_FUN_006fd14c;
extern uint8_t  PTR_LAB_006fd148;
extern uint8_t  PTR_FUN_006f5864;

// ---------------------------------------------------------------------------
// External helpers referenced by the translated listings.
// ---------------------------------------------------------------------------
extern void operator_delete__(void* p);
extern void FUN_004baf50(void);
extern void FUN_004f0dc0(void);

// Virtual slot 0 of a refcounted object: destructor with a "delete" flag.
typedef void (__cdecl* vtbl_slot0_t)(void* obj, int deleteFlag);

// Observed intrusive-release sequence: read the object, decrement the dword at
// offset +4, and when the count reaches zero invoke virtual slot 0 with 1.
static inline void release_refcounted(uint32_t objectAddress)
{
    if (objectAddress == 0) {
        return;
    }
    uint32_t* const obj = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(objectAddress));
    int* const count = reinterpret_cast<int*>(obj) + 1;
    const int value = *count;
    *count = value - 1;
    if (value - 1 == 0) {
        const vtbl_slot0_t slot0 = reinterpret_cast<vtbl_slot0_t>(
            static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(obj)));
        slot0(obj, 1);
    }
}

// ---------------------------------------------------------------------------
// 0x6be510 — observed shape
// ---------------------------------------------------------------------------
// Walks 9 records downward (stride 0x30 dwords) from DAT_008d897c: stamps the
// 0x6fd14c destructor thunk at record-0x124, runs the base destructor, releases
// the three owned members at record-0x68 / -0xc0 / -0x108, decrements the live
// counter, then stamps the 0x6fd148 thunk.
void FUN_006be510(void)
{
    int iVar3 = 9;
    int* piVar4 = &DAT_008d897c;
    do {
        piVar4[-0x49] = static_cast<int>(reinterpret_cast<intptr_t>(&PTR_FUN_006fd14c));
        FUN_004baf50();
        release_refcounted(static_cast<uint32_t>(
            static_cast<uintptr_t>(piVar4[-0x1a])));
        release_refcounted(static_cast<uint32_t>(
            static_cast<uintptr_t>(piVar4[-0x30])));
        release_refcounted(static_cast<uint32_t>(
            static_cast<uintptr_t>(piVar4[-0x42])));
        DAT_00727444 = DAT_00727444 + -1;
        iVar3 = iVar3 + -1;
        piVar4[-0x49] = static_cast<int>(reinterpret_cast<intptr_t>(&PTR_LAB_006fd148));
        piVar4 = piVar4 + -0x30;
    } while (iVar3 != 0);
}

// ---------------------------------------------------------------------------
// 0x6be590 — observed shape
// ---------------------------------------------------------------------------
// Same sequence as 0x6be510, with 10 records and cursor base DAT_008d82bc.
void FUN_006be590(void)
{
    int iVar3 = 10;
    int* piVar4 = &DAT_008d82bc;
    do {
        piVar4[-0x49] = static_cast<int>(reinterpret_cast<intptr_t>(&PTR_FUN_006fd14c));
        FUN_004baf50();
        release_refcounted(static_cast<uint32_t>(
            static_cast<uintptr_t>(piVar4[-0x1a])));
        release_refcounted(static_cast<uint32_t>(
            static_cast<uintptr_t>(piVar4[-0x30])));
        release_refcounted(static_cast<uint32_t>(
            static_cast<uintptr_t>(piVar4[-0x42])));
        DAT_00727444 = DAT_00727444 + -1;
        iVar3 = iVar3 + -1;
        piVar4[-0x49] = static_cast<int>(reinterpret_cast<intptr_t>(&PTR_LAB_006fd148));
        piVar4 = piVar4 + -0x30;
    } while (iVar3 != 0);
}

// ---------------------------------------------------------------------------
// 0x6be610 — observed shape
// ---------------------------------------------------------------------------
// Frees the block whose payload starts 8 bytes past the slot value, unless the
// slot is null or already points at the static sentinel, then resets the slot.
void FUN_006be610(void)
{
    void* const puVar1 = reinterpret_cast<void*>(
        static_cast<uintptr_t>(PTR_DAT_007267d0 - 8u));
    if ((puVar1 != static_cast<void*>(nullptr)) &&
        (puVar1 != static_cast<void*>(&DAT_008cacc8))) {
        operator_delete__(puVar1);
    }
    PTR_DAT_007267d0 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&DAT_008cacd0));
}

// ---------------------------------------------------------------------------
// 0x6be640 — observed shape
// ---------------------------------------------------------------------------
// Walks 0x3c0 3-dword records downward from DAT_008db620, freeing the block 8
// bytes before each record's first dword and stamping the empty sentinel.
void FUN_006be640(void)
{
    uint32_t* puVar3 = &DAT_008db620;
    int iVar4 = 0x3c0;
    do {
        uint32_t* const piVar1 = puVar3 - 3;
        puVar3 = puVar3 - 3;
        void* const puVar2 = reinterpret_cast<void*>(
            static_cast<uintptr_t>(*piVar1 - 8u));
        if ((puVar2 != static_cast<void*>(nullptr)) &&
            (puVar2 != static_cast<void*>(&DAT_008cacc8))) {
            operator_delete__(puVar2);
        }
        iVar4 = iVar4 + -1;
        *puVar3 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&DAT_008cacd0));
    } while (iVar4 != 0);
}

// ---------------------------------------------------------------------------
// 0x6be680 — observed shape
// ---------------------------------------------------------------------------
// Same record teardown as 0x6be640, over 8 records ending at DAT_008db680.
void FUN_006be680(void)
{
    uint32_t* puVar3 = &DAT_008db680;
    int iVar4 = 8;
    do {
        uint32_t* const piVar1 = puVar3 - 3;
        puVar3 = puVar3 - 3;
        void* const puVar2 = reinterpret_cast<void*>(
            static_cast<uintptr_t>(*piVar1 - 8u));
        if ((puVar2 != static_cast<void*>(nullptr)) &&
            (puVar2 != static_cast<void*>(&DAT_008cacc8))) {
            operator_delete__(puVar2);
        }
        iVar4 = iVar4 + -1;
        *puVar3 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&DAT_008cacd0));
    } while (iVar4 != 0);
}

// ---------------------------------------------------------------------------
// 0x6be6c0 — observed shape
// ---------------------------------------------------------------------------
// Same record teardown as 0x6be640, over 0x8c records ending at DAT_008dbd10.
void FUN_006be6c0(void)
{
    uint32_t* puVar3 = &DAT_008dbd10;
    int iVar4 = 0x8c;
    do {
        uint32_t* const piVar1 = puVar3 - 3;
        puVar3 = puVar3 - 3;
        void* const puVar2 = reinterpret_cast<void*>(
            static_cast<uintptr_t>(*piVar1 - 8u));
        if ((puVar2 != static_cast<void*>(nullptr)) &&
            (puVar2 != static_cast<void*>(&DAT_008cacc8))) {
            operator_delete__(puVar2);
        }
        iVar4 = iVar4 + -1;
        *puVar3 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&DAT_008cacd0));
    } while (iVar4 != 0);
}

// ---------------------------------------------------------------------------
// 0x6be700 — observed shape
// ---------------------------------------------------------------------------
// Same record teardown as 0x6be640, over 0x80 records ending at DAT_008dc310.
void FUN_006be700(void)
{
    uint32_t* puVar3 = &DAT_008dc310;
    int iVar4 = 0x80;
    do {
        uint32_t* const piVar1 = puVar3 - 3;
        puVar3 = puVar3 - 3;
        void* const puVar2 = reinterpret_cast<void*>(
            static_cast<uintptr_t>(*piVar1 - 8u));
        if ((puVar2 != static_cast<void*>(nullptr)) &&
            (puVar2 != static_cast<void*>(&DAT_008cacc8))) {
            operator_delete__(puVar2);
        }
        iVar4 = iVar4 + -1;
        *puVar3 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&DAT_008cacd0));
    } while (iVar4 != 0);
}

// ---------------------------------------------------------------------------
// 0x6be740 — observed shape
// ---------------------------------------------------------------------------
// Releases the single refcounted object held in DAT_008dc314.
void FUN_006be740(void)
{
    release_refcounted(DAT_008dc314);
}

// ---------------------------------------------------------------------------
// 0x6be760 — observed shape
// ---------------------------------------------------------------------------
// Points the 0x7267d4 slot at the 0x6f5864 thunk, runs FUN_004f0dc0, then frees
// the block 8 bytes before PTR_DAT_007267f0 and resets that slot.
void FUN_006be760(void)
{
    PTR_PTR_007267d4 = static_cast<uint32_t>(
        reinterpret_cast<uintptr_t>(&PTR_FUN_006f5864));
    FUN_004f0dc0();
    void* const puVar1 = reinterpret_cast<void*>(
        static_cast<uintptr_t>(PTR_DAT_007267f0 - 8u));
    if ((puVar1 != static_cast<void*>(nullptr)) &&
        (puVar1 != static_cast<void*>(&DAT_008cacc8))) {
        operator_delete__(puVar1);
    }
    PTR_DAT_007267f0 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&DAT_008cacd0));
}

// ---------------------------------------------------------------------------
// 0x6be7a0 — observed shape
// ---------------------------------------------------------------------------
// Releases the single refcounted object held in DAT_008dc31c.
void FUN_006be7a0(void)
{
    release_refcounted(DAT_008dc31c);
}

// ---------------------------------------------------------------------------
// 0x6be7c0 — observed shape
// ---------------------------------------------------------------------------
// Releases the single refcounted object held in DAT_008dc318.
void FUN_006be7c0(void)
{
    release_refcounted(DAT_008dc318);
}

// ---------------------------------------------------------------------------
// 0x6be7e0 — observed shape
// ---------------------------------------------------------------------------
// Walks 0x180 object-pointer slots downward from DAT_008dc920, releasing each.
void FUN_006be7e0(void)
{
    uint32_t* puVar3 = &DAT_008dc920;
    int iVar4 = 0x180;
    do {
        uint32_t* const current = puVar3 - 1;
        puVar3 = current;
        release_refcounted(*current);
        iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
}

// ---------------------------------------------------------------------------
// 0x6be810 — observed shape
// ---------------------------------------------------------------------------
// Frees the block 8 bytes before PTR_DAT_00726804 and resets that slot.
void FUN_006be810(void)
{
    void* const puVar1 = reinterpret_cast<void*>(
        static_cast<uintptr_t>(PTR_DAT_00726804 - 8u));
    if ((puVar1 != static_cast<void*>(nullptr)) &&
        (puVar1 != static_cast<void*>(&DAT_008cacc8))) {
        operator_delete__(puVar1);
    }
    PTR_DAT_00726804 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&DAT_008cacd0));
}

// ---------------------------------------------------------------------------
// 0x6be840 — observed shape
// ---------------------------------------------------------------------------
// Releases the single refcounted object held in DAT_008dc920.
void FUN_006be840(void)
{
    release_refcounted(DAT_008dc920);
}

// ---------------------------------------------------------------------------
// 0x6be860 — observed shape
// ---------------------------------------------------------------------------
// Walks 3 object-pointer slots downward (stride 4 dwords) from DAT_008dc954,
// releasing each.
void FUN_006be860(void)
{
    uint32_t* puVar3 = &DAT_008dc954;
    int iVar4 = 3;
    do {
        uint32_t* const current = puVar3 - 4;
        puVar3 = current;
        release_refcounted(*current);
        iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
}

// ---------------------------------------------------------------------------
// 0x6be890 — observed shape
// ---------------------------------------------------------------------------
// Releases the single refcounted object held in DAT_008dc954.
void FUN_006be890(void)
{
    release_refcounted(DAT_008dc954);
}

// ---------------------------------------------------------------------------
// 0x6be8b0 — observed shape
// ---------------------------------------------------------------------------
// Releases the single refcounted object held in DAT_008dc968.
void FUN_006be8b0(void)
{
    release_refcounted(DAT_008dc968);
}

// ---------------------------------------------------------------------------
// 0x6be8d0 — observed shape
// ---------------------------------------------------------------------------
// Releases the single refcounted object held in DAT_008dc964.
void FUN_006be8d0(void)
{
    release_refcounted(DAT_008dc964);
}

// ---------------------------------------------------------------------------
// 0x6be8f0 — observed shape
// ---------------------------------------------------------------------------
// Releases the single refcounted object held in DAT_008dc960.
void FUN_006be8f0(void)
{
    release_refcounted(DAT_008dc960);
}

// ---------------------------------------------------------------------------
// 0x6be910 — observed shape
// ---------------------------------------------------------------------------
// Releases the single refcounted object held in DAT_008dc95c.
void FUN_006be910(void)
{
    release_refcounted(DAT_008dc95c);
}
