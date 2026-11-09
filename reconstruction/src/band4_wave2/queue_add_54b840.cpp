// Band4 wave2 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// 0x0054b840: addref obj at param_1+0xb4, read flags at obj2+0x20: route to
// FUN_0054b730 insert, else allocate via (+0x10)+4 vcall and FUN_00524a60.
// Corpus: analysis/pseudocode/functions/0x54b840.c
#include <stddef.h>
#include <stdint.h>

extern void  __thiscall FUN_0054b730(void* self, void* param_1);
extern void  __cdecl FUN_00524a60(void* p);

struct Q54b840 {
    uint8_t  pad[0x34];
    uint8_t  flag_34;
    void*    allocFn_10; // +0x10 vtable-ish
};

// 0x0054b840
int __thiscall FUN_0054b840(Q54b840* self, void* param_1)
{
    void* obj = *(void**)((uint8_t*)param_1 + 0xb4);
    if (obj != nullptr) {
        ((uint32_t*)obj)[1] += 1;
    }
    uint32_t rc = ((uint32_t*)obj)[1];
    ((uint32_t*)obj)[1] = rc - 1;
    if (rc - 1 == 0) {
        typedef void (__cdecl *VCall)(void*, int);
        VCall v = *(VCall*)obj;
        v(obj, 1);
    }
    void* inner = *(void**)((uint8_t*)obj + 8); // obj[2]
    uint8_t flags = *(uint8_t*)((uint8_t*)inner + 0x20);
    if (((flags & 1) == 0) ||
        (self->flag_34 != 0 && ((*(uint16_t*)((uint8_t*)inner + 0x20) >> 0xd & 1) != 0))) {
        FUN_0054b730(self, param_1);
        return 1;
    }
    typedef void* (__cdecl *AllocFn)(void*);
    AllocFn af = *(AllocFn*)self->allocFn_10; // (*(int*)(+0x10)+4)
    void* rec = ((void*(*)(void*))af)(self);
    *(void**)((uint8_t*)rec + 8) = param_1;
    FUN_00524a60(rec);
    return 1;
}
