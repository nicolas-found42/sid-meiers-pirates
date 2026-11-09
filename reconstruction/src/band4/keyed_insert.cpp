// Band4 reconstruction candidate (UNVERIFIED; no cl 13.10.3077).
// Keyed insert-then-release member helper. Evidence (AEA dossier):
// analysis/team/band4/deep/0x005651a0.md (REA ev_4825ceea... etc.)
#include <stddef.h>

struct RefObj_51a0 {
    void* vtable_00;
    int   refcnt_04;
};

struct Manager_51a0 {
    virtual void slot_fn_00(void);
    // ... slots 1..30 omitted ...
    virtual void lookup_insert_7c(void* keySlot, unsigned short key); // slot 0x1f
};
struct Holder_51a0 {
    Manager_51a0*  mgr_50;    // +0x50
    unsigned char  dirty_54;  // +0x54
    void __thiscall FUN_005651a0(unsigned short key, RefObj_51a0* handle);
};

// 0x005651a0 — __thiscall (RET 0x8). First virtual call is recvKey(key)
// on the manager's slot 0x7c with the address of the key slot pushed;
// then release-if-last on the handle; then dirty_54 = 1.
void __thiscall Holder_51a0::FUN_005651a0(unsigned short key, RefObj_51a0* handle)
{
    mgr_50->lookup_insert_7c(&key, key);
    if (handle != NULL) {
        if (--handle->refcnt_04 == 0) {
            ((void (__cdecl **)(int))handle->vtable_00)[0](1);
        }
    }
    dirty_54 = 1;
}
