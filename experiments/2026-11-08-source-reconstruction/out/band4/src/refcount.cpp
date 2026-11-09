// Band4 reconstruction candidates (UNVERIFIED; no cl 13.10.3077 on this host).
// Clean room: derived from shipped-bytes pseudocode + REA dossiers in
// analysis/team/band4/deep/. Type and field names are hypotheses.
#include <stddef.h> // NULL

struct RefObj {
    void* vtable_00; // +0x0: vptr; slot 0 is the scalar-deleting destructor
    int   refcnt_04; // +0x4: intrusive refcount (release-if-last)
};

// DAT_0072792c (0x0072792c): single global strong reference (owner unknown).
extern RefObj* g_ref_slot_72792c;

// 0x0054ae10
// Observed: global refcount release. If g_ref_slot_72792c != NULL, decrement
// refcnt; on zero call vtable slot 0 with pushed 1; then clear the global.
// Evidence: REA ev_b169e73f1cc753109bbd25334ae25f7255063a4023d7704a970f4717749b9883,
// ev_5d7dee39d78fa076960be3c2b899d02e09724771627791ea1695e48e904380c5,
// ev_da6db88bfb3dca67882d2f6636b6bd91692cc5c67cd55618beee3fea9439d58d;
// corpus analysis/pseudocode/functions/0x54ae10.c
void __cdecl FUN_0054ae10(void)
{
    RefObj* obj = g_ref_slot_72792c;
    if (obj != NULL) {
        if (--obj->refcnt_04 == 0) {
            // Slot-0 call with pushed 1: MSVC "vector deleting destructor"
            // convention (low bit = delete storage). Spelled as a virtual
            // deleting-destructor call in real source; cast spells the bytes.
            ((void (__cdecl **)(int))obj->vtable_00)[0](1);
        }
        g_ref_slot_72792c = NULL;
    }
}

// 0x0054ae40
// Observed: replace-global with addref. If global != next: release the old
// strong reference (decrement, slot-0 call on zero), store next, then
// ++next->refcnt when next != NULL. Sibling of 0x0054ae10.
// Corpus analysis/pseudocode/functions/0x54ae40.c
void __cdecl FUN_0054ae40(RefObj* next)
{
    RefObj* cur = g_ref_slot_72792c;
    if (cur != next) {
        if (cur != NULL) {
            if (--cur->refcnt_04 == 0) {
                ((void (__cdecl **)(int))cur->vtable_00)[0](1);
            }
        }
        g_ref_slot_72792c = next;
        if (next != NULL) {
            ++next->refcnt_04;
        }
    }
}
