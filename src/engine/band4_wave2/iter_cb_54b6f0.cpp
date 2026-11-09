// Band4 wave2 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// 0x0054b6f0: if *(+0x0c)!=0, read value at +0x050c ( (*(int*)(in_ECX+0x0c)+0x188 )
// ), iterate FUN_0054b580() and invoke vcall +0x70 with that value, then
// FUN_00556430.
// Corpus: analysis/pseudocode/functions/0x54b6f0.c
#include <stddef.h>
#include <stdint.h>

extern uint32_t __thiscall FUN_0054b580(void* self);
extern void  __thiscall FUN_00556430(void* self);

struct Obj54b6f0 {
    void*    vtable_00;
    uint32_t w_04;
    void*    src_0c;
};

// 0x0054b6f0
void __thiscall FUN_0054b6f0(Obj54b6f0* self)
{
    if (self->src_0c == nullptr) {
        return;
    }
    void* aux = *(void**)((uint8_t*)self->src_0c + 0x188);
    void* el = (void*)(uintptr_t)FUN_0054b580(self);
    while (el != nullptr) {
        void** vt = *(void***)el;
        typedef void (__cdecl *Cb)(void*, void*);
        Cb cb = (Cb)vt[0x70 / 4];
        cb(el, aux);
        el = (void*)(uintptr_t)FUN_0054b580(self);
    }
    FUN_00556430(self);
}
