// Reconstruction batch mass_0359
// Sid Meier's Pirates! (2004) — PE32 i386
// Candidate definitions derived from Ghidra 12.2 pseudocode (corpus:
// analysis/pseudocode/functions/0x*.c). Pseudocode is provider output, not
// original source; shapes, offsets, constants and call order are preserved.
// This batch is a cluster of static/global teardown routines: refcounted
// object releases and buffer-pair resets. No byte-match claim.

#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---------------------------------------------------------------------------
// Observed helpers and globals (labels kept from the corpus listings)
// ---------------------------------------------------------------------------

// std::basic_string<char, std::char_traits<char>, std::allocator<char>>::~basic_string
// (the corpus listing calls the instantiated destructor on each 0x28-byte element)
extern void std_string_dtor(void* s);

extern void operator_delete(void* p);

extern void FUN_0052bfb0(void);   // sub-object teardown called first by 0x6bf890
extern void FUN_0052c060(void);   // sub-object teardown called first by 0x6bf920/0x6bf980

// Global string/record array whose one-past-end is DAT_008ecd30; element stride 0x28.
extern uint8_t DAT_008ecd30[];

// First heap buffer pair (reset by 0x6bf890).
extern uint8_t* DAT_008ed530;   // data
extern int32_t  DAT_008ed534;   // _DAT_008ed534: element count
extern int32_t  DAT_008ed538;   // _DAT_008ed538: capacity
extern uint8_t* DAT_008ed520;   // data
extern int32_t  DAT_008ed524;   // _DAT_008ed524: element count
extern int32_t  DAT_008ed528;   // _DAT_008ed528: capacity

// Second heap buffer pair (reset by 0x6bf920).
extern uint8_t* DAT_008ed560;   // data
extern int32_t  DAT_008ed564;   // _DAT_008ed564: element count
extern int32_t  DAT_008ed568;   // _DAT_008ed568: capacity
extern uint8_t* DAT_008ed550;   // data
extern int32_t  DAT_008ed554;   // _DAT_008ed554: element count
extern int32_t  DAT_008ed558;   // _DAT_008ed558: capacity

// Third heap buffer pair (reset by 0x6bf980).
extern uint8_t* DAT_008ed580;   // data
extern int32_t  DAT_008ed584;   // _DAT_008ed584: element count
extern int32_t  DAT_008ed588;   // _DAT_008ed588: capacity
extern uint8_t* DAT_008ed570;   // data
extern int32_t  DAT_008ed574;   // _DAT_008ed574: element count
extern int32_t  DAT_008ed578;   // _DAT_008ed578: capacity

// Singleton pointers to reference-counted objects: vtable at +0, refcount at +4.
typedef void (__thiscall* RefDestroyFn)(void* self, int32_t freeFlag);
struct RefCountedObj {
    RefDestroyFn* vtable;   // +0
    int32_t       refcount; // +4
};

extern RefCountedObj* DAT_00727594;
extern RefCountedObj* DAT_007275ac;

// 0x6bf850 — observed shape: destroy the 0x100-element std::string array ending
// at &DAT_008ecd30, walking backwards with a 0x28 stride.
void FUN_006bf850(void)
{
    uint8_t* this_ptr = reinterpret_cast<uint8_t*>(DAT_008ecd30);
    int32_t iVar1 = 0x100;

    do {
        this_ptr = this_ptr - 0x28;
        std_string_dtor(this_ptr);
        iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
}

// 0x6bf890 — observed shape: run the base teardown, then release and zero the
// first buffer pair followed by the second buffer pair.
void FUN_006bf890(void)
{
    FUN_0052bfb0();
    if (DAT_008ed530 != (void*)0x0) {
        operator_delete(DAT_008ed530);
    }
    DAT_008ed530 = (void*)0x0;
    DAT_008ed534 = 0;
    DAT_008ed538 = 0;
    if (DAT_008ed520 != (void*)0x0) {
        operator_delete(DAT_008ed520);
    }
    DAT_008ed520 = (void*)0x0;
    DAT_008ed524 = 0;
    DAT_008ed528 = 0;
}

// 0x6bf920 — observed shape: same teardown on the 0x8ed560/0x8ed550 pairs.
void FUN_006bf920(void)
{
    FUN_0052c060();
    if (DAT_008ed560 != (void*)0x0) {
        operator_delete(DAT_008ed560);
    }
    DAT_008ed560 = (void*)0x0;
    DAT_008ed564 = 0;
    DAT_008ed568 = 0;
    if (DAT_008ed550 != (void*)0x0) {
        operator_delete(DAT_008ed550);
    }
    DAT_008ed550 = (void*)0x0;
    DAT_008ed554 = 0;
    DAT_008ed558 = 0;
}

// 0x6bf980 — observed shape: same teardown on the 0x8ed580/0x8ed570 pairs.
void FUN_006bf980(void)
{
    FUN_0052c060();
    if (DAT_008ed580 != (void*)0x0) {
        operator_delete(DAT_008ed580);
    }
    DAT_008ed580 = (void*)0x0;
    DAT_008ed584 = 0;
    DAT_008ed588 = 0;
    if (DAT_008ed570 != (void*)0x0) {
        operator_delete(DAT_008ed570);
    }
    DAT_008ed570 = (void*)0x0;
    DAT_008ed574 = 0;
    DAT_008ed578 = 0;
}

// 0x6bfa20 — observed shape: decrement the singleton's refcount at +4 and call
// vtable[0](object, 1) when it reaches zero.
void FUN_006bfa20(void)
{
    RefCountedObj* puVar2 = DAT_00727594;
    int32_t iVar1;

    if (DAT_00727594 != (RefCountedObj*)0x0) {
        iVar1 = puVar2->refcount;
        puVar2->refcount = iVar1 + -1;
        if (iVar1 + -1 == 0) {
            puVar2->vtable[0](puVar2, 1);
        }
    }
}

// Additional singletons released by group 2.
extern RefCountedObj* DAT_007275b8;
extern RefCountedObj* DAT_007275c4;
extern RefCountedObj* DAT_007275f0;
extern RefCountedObj* DAT_007275fc;
extern RefCountedObj* DAT_00727618;

// 0x6bfa40 — observed shape: refcount release of the 0x7275ac singleton.
void FUN_006bfa40(void)
{
    RefCountedObj* puVar2 = DAT_007275ac;
    int32_t iVar1;

    if (DAT_007275ac != (RefCountedObj*)0x0) {
        iVar1 = puVar2->refcount;
        puVar2->refcount = iVar1 + -1;
        if (iVar1 + -1 == 0) {
            puVar2->vtable[0](puVar2, 1);
        }
    }
}

// 0x6bfa60 — observed shape: refcount release of the 0x7275b8 singleton.
void FUN_006bfa60(void)
{
    RefCountedObj* puVar2 = DAT_007275b8;
    int32_t iVar1;

    if (DAT_007275b8 != (RefCountedObj*)0x0) {
        iVar1 = puVar2->refcount;
        puVar2->refcount = iVar1 + -1;
        if (iVar1 + -1 == 0) {
            puVar2->vtable[0](puVar2, 1);
        }
    }
}

// 0x6bfa80 — observed shape: refcount release of the 0x7275c4 singleton.
void FUN_006bfa80(void)
{
    RefCountedObj* puVar2 = DAT_007275c4;
    int32_t iVar1;

    if (DAT_007275c4 != (RefCountedObj*)0x0) {
        iVar1 = puVar2->refcount;
        puVar2->refcount = iVar1 + -1;
        if (iVar1 + -1 == 0) {
            puVar2->vtable[0](puVar2, 1);
        }
    }
}

// 0x6bfaa0 — observed shape: refcount release of the 0x7275f0 singleton.
void FUN_006bfaa0(void)
{
    RefCountedObj* puVar2 = DAT_007275f0;
    int32_t iVar1;

    if (DAT_007275f0 != (RefCountedObj*)0x0) {
        iVar1 = puVar2->refcount;
        puVar2->refcount = iVar1 + -1;
        if (iVar1 + -1 == 0) {
            puVar2->vtable[0](puVar2, 1);
        }
    }
}

// 0x6bfac0 — observed shape: refcount release of the 0x7275fc singleton.
void FUN_006bfac0(void)
{
    RefCountedObj* puVar2 = DAT_007275fc;
    int32_t iVar1;

    if (DAT_007275fc != (RefCountedObj*)0x0) {
        iVar1 = puVar2->refcount;
        puVar2->refcount = iVar1 + -1;
        if (iVar1 + -1 == 0) {
            puVar2->vtable[0](puVar2, 1);
        }
    }
}

// 0x6bfae0 — observed shape: refcount release of the 0x727618 singleton.
void FUN_006bfae0(void)
{
    RefCountedObj* puVar2 = DAT_00727618;
    int32_t iVar1;

    if (DAT_00727618 != (RefCountedObj*)0x0) {
        iVar1 = puVar2->refcount;
        puVar2->refcount = iVar1 + -1;
        if (iVar1 + -1 == 0) {
            puVar2->vtable[0](puVar2, 1);
        }
    }
}

// Additional singletons released by group 3.
extern RefCountedObj* DAT_0072792c;
extern RefCountedObj* DAT_00727980;
extern uint8_t       DAT_007279e4[];   // one-past-end of a 7-slot pointer block
extern RefCountedObj* DAT_00727c9c;
extern RefCountedObj* DAT_00727cb0;
extern RefCountedObj* DAT_00727cd8;
extern RefCountedObj* DAT_00727d2c;
extern RefCountedObj* DAT_00727d38;

// 0x6bfb20 — observed shape: refcount release of the 0x72792c singleton.
void FUN_006bfb20(void)
{
    RefCountedObj* puVar2 = DAT_0072792c;
    int32_t iVar1;

    if (DAT_0072792c != (RefCountedObj*)0x0) {
        iVar1 = puVar2->refcount;
        puVar2->refcount = iVar1 + -1;
        if (iVar1 + -1 == 0) {
            puVar2->vtable[0](puVar2, 1);
        }
    }
}

// 0x6bfb50 — observed shape: refcount release of the 0x727980 singleton.
void FUN_006bfb50(void)
{
    RefCountedObj* puVar2 = DAT_00727980;
    int32_t iVar1;

    if (DAT_00727980 != (RefCountedObj*)0x0) {
        iVar1 = puVar2->refcount;
        puVar2->refcount = iVar1 + -1;
        if (iVar1 + -1 == 0) {
            puVar2->vtable[0](puVar2, 1);
        }
    }
}

// 0x6bfb80 — observed shape: walk 7 pointer slots backwards from the word
// before DAT_007279e4 (0x7279e0 .. 0x7279c8) and refcount-release each one.
void FUN_006bfb80(void)
{
    RefCountedObj** puVar3 = reinterpret_cast<RefCountedObj**>(DAT_007279e4);
    int32_t iVar4 = 7;

    do {
        puVar3 = puVar3 - 1;
        RefCountedObj* puVar2 = *puVar3;
        if (puVar2 != (RefCountedObj*)0x0) {
            int32_t* piVar1 = &puVar2->refcount;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                puVar2->vtable[0](puVar2, 1);
            }
        }
        iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
}

// 0x6bfbb0 — observed shape: refcount release of the 0x727c9c singleton.
void FUN_006bfbb0(void)
{
    RefCountedObj* puVar2 = DAT_00727c9c;
    int32_t iVar1;

    if (DAT_00727c9c != (RefCountedObj*)0x0) {
        iVar1 = puVar2->refcount;
        puVar2->refcount = iVar1 + -1;
        if (iVar1 + -1 == 0) {
            puVar2->vtable[0](puVar2, 1);
        }
    }
}

// 0x6bfbd0 — observed shape: refcount release of the 0x727cb0 singleton.
void FUN_006bfbd0(void)
{
    RefCountedObj* puVar2 = DAT_00727cb0;
    int32_t iVar1;

    if (DAT_00727cb0 != (RefCountedObj*)0x0) {
        iVar1 = puVar2->refcount;
        puVar2->refcount = iVar1 + -1;
        if (iVar1 + -1 == 0) {
            puVar2->vtable[0](puVar2, 1);
        }
    }
}

// 0x6bfbf0 — observed shape: refcount release of the 0x727cd8 singleton.
void FUN_006bfbf0(void)
{
    RefCountedObj* puVar2 = DAT_00727cd8;
    int32_t iVar1;

    if (DAT_00727cd8 != (RefCountedObj*)0x0) {
        iVar1 = puVar2->refcount;
        puVar2->refcount = iVar1 + -1;
        if (iVar1 + -1 == 0) {
            puVar2->vtable[0](puVar2, 1);
        }
    }
}

// 0x6bfc10 — observed shape: refcount release of the 0x727d2c singleton.
void FUN_006bfc10(void)
{
    RefCountedObj* puVar2 = DAT_00727d2c;
    int32_t iVar1;

    if (DAT_00727d2c != (RefCountedObj*)0x0) {
        iVar1 = puVar2->refcount;
        puVar2->refcount = iVar1 + -1;
        if (iVar1 + -1 == 0) {
            puVar2->vtable[0](puVar2, 1);
        }
    }
}

// 0x6bfc30 — observed shape: refcount release of the 0x727d38 singleton.
void FUN_006bfc30(void)
{
    RefCountedObj* puVar2 = DAT_00727d38;
    int32_t iVar1;

    if (DAT_00727d38 != (RefCountedObj*)0x0) {
        iVar1 = puVar2->refcount;
        puVar2->refcount = iVar1 + -1;
        if (iVar1 + -1 == 0) {
            puVar2->vtable[0](puVar2, 1);
        }
    }
}
