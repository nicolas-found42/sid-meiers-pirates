// Band4 wave2 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// Deleting destructors; vtable resets, member deletes, conditional operator_delete.
// Corpus: analysis/pseudocode/functions/0x54ae80.c, 0x54b440.c
// Observed global: 0x727928 pointer freed by 0x54ae80; 0x727444 refcount dec.
// Observed vtables: 0x6c1fb4 (pre-dtor) / 0x6fd148 (post-dtor) for 0x54ae80;
// 0x6c1fc8 for 0x54b440. 0x54b440 fields: +0x0c,+0x10,+0x18,+0x14 (dwords).
#include <stddef.h>
#include <stdint.h>

extern void* __cdecl operator_new(int nbytes);
extern void  __cdecl operator_delete(void* p);
extern void  __cdecl operator_delete__(void* p);
extern void  __cdecl FUN_0055ad50(void);
extern void  __cdecl FUN_0054b490(void* self);
extern void  __cdecl FUN_00538400(void* self);

extern void* g_ptr_727928;
extern int   g_count_727444;

struct Obj54ae80 {
    void* vtable;   // +0x00
};

struct Obj54b440 {
    void*     vtable;    // +0x00
    uint32_t  w_04;
    uint32_t  w_08;
    void*     p_0c;
    void*     p_10;
    void*     peer_14;
    void*     p_18;
};

extern void* g_vtable_6c1fb4, *g_vtable_6fd148, *g_vtable_6c1fc8;

// 0x0054ae80 — deleting dtor, this in ECX, flag in AL
void __thiscall FUN_0054ae80(Obj54ae80* self, uint8_t flag)
{
    self->vtable = &g_vtable_6c1fb4;
    if (g_ptr_727928 != nullptr) {
        operator_delete__(g_ptr_727928);
    }
    g_ptr_727928 = nullptr;
    FUN_0055ad50();
    self->vtable = &g_vtable_6fd148;
    g_count_727444 -= 1;
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}

// 0x0054b440 — deleting dtor, this in ECX
void __thiscall FUN_0054b440(Obj54b440* self)
{
    self->vtable = &g_vtable_6c1fc8;
    operator_delete__(self->p_0c);
    operator_delete__(self->p_10);
    if (self->p_18 != nullptr) {
        typedef void (__cdecl *IncrFn)(void*, int);
        IncrFn fn = *(IncrFn*)self->p_18;
        // indirect call with this=(self->p_18), arg 1
        fn(self->p_18, 1);
    }
    FUN_0054b490(self);
    void* peer = self->peer_14;
    if (peer != nullptr) {
        uint32_t* rc = (uint32_t*)peer + 1; // +4 refcount
        *rc -= 1;
        if (*rc == 0) {
            typedef void (__cdecl *VCall)(void*, int);
            VCall v = *(VCall*)peer;
            v(peer, 1);
        }
    }
    FUN_00538400(self);
}
