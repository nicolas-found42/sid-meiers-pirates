// Reconstruction candidates for batch mass_0353 — Sid Meier's Pirates! (2004), PE32 i386.
// UNVERIFIED: translated by hand from Ghidra 12.2 pseudocode listings; no build was run.
// Corpus: analysis/pseudocode/functions/0x6bddc0.c ... 0x6be490.c
// The listings in this batch take no register receiver; they are free functions
// operating on globals and on static arrays of 3-dword records.
#include <cstdint>
#include <cstddef>

// ---------------------------------------------------------------------------
// External data referenced by the translated listings.
// ---------------------------------------------------------------------------
extern uint32_t DAT_008cadec;   // 0x8cadec: refcounted object pointer
extern uint32_t DAT_008cadf8;   // 0x8cadf8
extern uint32_t DAT_008cadf4;   // 0x8cadf4
extern uint32_t DAT_008cadf0;   // 0x8cadf0
extern uint32_t PTR_DAT_00726640; // 0x726640: pointer slot (stored as an integer value)
extern uint32_t DAT_00727444;   // 0x727444: object counter
extern uint8_t DAT_008cacc8;    // 0x8cacc8: static sentinel object
extern uint8_t DAT_008cacd0;    // 0x8cacd0: static empty-string/static sentinel

// Head/tail of the static record arrays torn down by the 0x6bde70..0x6be490 group.
// Each record is three dwords; the first dword holds the owned pointer.
extern uint32_t DAT_008cb108[0xc0]; // 0x8cb108: 0x40 records, walked downward
extern uint32_t DAT_008cb180[0x30]; // 0x8cb180: 0x10 records
extern uint32_t DAT_008cb1a4[0x09]; // 0x8cb1a4: 0x03 records
extern uint32_t DAT_008cb1e0[0x0f]; // 0x8cb1e0: 0x05 records
extern int      DAT_008cba7c;       // 0x8cba7c: record-array cursor base (4 records)
extern int      DAT_008cb77c;       // 0x8cb77c
extern int      DAT_008cb47c;       // 0x8cb47c (3 records)
extern int      DAT_008cf5bc;       // 0x8cf5bc (9 records)
extern int      DAT_008ceefc;       // 0x8ceefc (0x18 records)
extern int      DAT_008cdcfc;       // 0x8cdcfc (0x2e records)
extern int      DAT_008d09fc;       // 0x8d09fc (0x1b records)
extern int      DAT_008d10bc;       // 0x8d10bc (9 records)
extern int      DAT_008d43bc;       // 0x8d43bc (0x44 records)
extern int      DAT_008d753c;       // 0x8d753c (0x42 records)
extern int      DAT_008d7b3c;       // 0x8d7b3c (8 records)

// ---------------------------------------------------------------------------
// External helpers referenced by the translated listings.
// ---------------------------------------------------------------------------
extern void operator_delete__(void* p);
extern void FUN_004baf50(void);

// Thunks stored into, and restored out of, the first dword of each record.
extern uint8_t PTR_FUN_006fd14c;
extern uint8_t PTR_LAB_006fd148;

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
// 0x6bddc0 — observed shape
// ---------------------------------------------------------------------------
void FUN_006bddc0(void)
{
    release_refcounted(DAT_008cadec);
}

// ---------------------------------------------------------------------------
// 0x6bdde0 — observed shape
// ---------------------------------------------------------------------------
void FUN_006bdde0(void)
{
    release_refcounted(DAT_008cadf8);
}

// ---------------------------------------------------------------------------
// 0x6bde00 — observed shape
// ---------------------------------------------------------------------------
void FUN_006bde00(void)
{
    release_refcounted(DAT_008cadf4);
}

// ---------------------------------------------------------------------------
// 0x6bde20 — observed shape
// ---------------------------------------------------------------------------
void FUN_006bde20(void)
{
    release_refcounted(DAT_008cadf0);
}

// ---------------------------------------------------------------------------
// 0x6bde40 — observed shape
// ---------------------------------------------------------------------------
void FUN_006bde40(void)
{
    void* const puVar1 = reinterpret_cast<void*>(
        static_cast<uintptr_t>(PTR_DAT_00726640 - 8u));
    if ((puVar1 != static_cast<void*>(nullptr)) &&
        (puVar1 != static_cast<void*>(&DAT_008cacc8))) {
        operator_delete__(puVar1);
    }
    PTR_DAT_00726640 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&DAT_008cacd0));
}

// ---------------------------------------------------------------------------
// 0x6bde70 — observed shape
// ---------------------------------------------------------------------------
void FUN_006bde70(void)
{
    uint32_t* puVar3 = &DAT_008cb108[0];
    int iVar4 = 0x40;
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
// 0x6bdeb0 — observed shape
// ---------------------------------------------------------------------------
void FUN_006bdeb0(void)
{
    uint32_t* puVar3 = &DAT_008cb180[0];
    int iVar4 = 0x10;
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
// 0x6bdef0 — observed shape
// ---------------------------------------------------------------------------
void FUN_006bdef0(void)
{
    uint32_t* puVar3 = &DAT_008cb1a4[0];
    int iVar4 = 3;
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
// 0x6bdf30 — observed shape
// ---------------------------------------------------------------------------
void FUN_006bdf30(void)
{
    uint32_t* puVar3 = &DAT_008cb1e0[0];
    int iVar4 = 5;
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
// 0x6bdf70 — observed shape
// ---------------------------------------------------------------------------
void FUN_006bdf70(void)
{
    int iVar3 = 4;
    int* piVar4 = &DAT_008cba7c;
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
// 0x6bdff0 — observed shape
// ---------------------------------------------------------------------------
void FUN_006bdff0(void)
{
    int iVar3 = 4;
    int* piVar4 = &DAT_008cb77c;
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
// 0x6be070 — observed shape
// ---------------------------------------------------------------------------
void FUN_006be070(void)
{
    int iVar3 = 3;
    int* piVar4 = &DAT_008cb47c;
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
// 0x6be0f0 — observed shape
// ---------------------------------------------------------------------------
void FUN_006be0f0(void)
{
    int iVar3 = 9;
    int* piVar4 = &DAT_008cf5bc;
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
// 0x6be170 — observed shape
// ---------------------------------------------------------------------------
void FUN_006be170(void)
{
    int iVar3 = 0x18;
    int* piVar4 = &DAT_008ceefc;
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
// 0x6be1f0 — observed shape
// ---------------------------------------------------------------------------
void FUN_006be1f0(void)
{
    int iVar3 = 0x2e;
    int* piVar4 = &DAT_008cdcfc;
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
// 0x6be270 — observed shape
// ---------------------------------------------------------------------------
void FUN_006be270(void)
{
    int iVar3 = 0x1b;
    int* piVar4 = &DAT_008d09fc;
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
// 0x6be300 — observed shape
// ---------------------------------------------------------------------------
void FUN_006be300(void)
{
    int iVar3 = 9;
    int* piVar4 = &DAT_008d10bc;
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
// 0x6be390 — observed shape
// ---------------------------------------------------------------------------
void FUN_006be390(void)
{
    int iVar3 = 0x44;
    int* piVar4 = &DAT_008d43bc;
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
// 0x6be410 — observed shape
// ---------------------------------------------------------------------------
void FUN_006be410(void)
{
    int iVar3 = 0x42;
    int* piVar4 = &DAT_008d753c;
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
// 0x6be490 — observed shape
// ---------------------------------------------------------------------------
void FUN_006be490(void)
{
    int iVar3 = 8;
    int* piVar4 = &DAT_008d7b3c;
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
