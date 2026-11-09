// Band4 wave2 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// 0x0054bc20: addref *(param_1+0xb4); FUN_005e4780; flag check (+0x20 of
// inner obj, +0x34 of self): return 0 if bit0 set or (bit13 && flag);
// else allocate via (+0x10)+4 vcall, store param_1 at +8, FUN_00524a60, ret 1.
// Corpus: analysis/pseudocode/functions/0x54bc20.c
#include <stddef.h>
#include <stdint.h>

extern void  __cdecl FUN_005e4780(void* self);
extern void  __cdecl FUN_00524a60(void* p);

struct Q54bc20 {
    uint8_t pad[0x34];
    uint8_t flag_34;
    void*   allocFn_10;
};

// 0x0054bc20
int __thiscall FUN_0054bc20(Q54bc20* self, void* param_1)
{
    void* obj = *(void**)((uint8_t*)param_1 + 0xb4);
    if (obj != nullptr) {
        ((uint32_t*)obj)[1] += 1;
    }
    FUN_005e4780(self);
    void* inner = obj ? *(void**)((uint8_t*)obj + 8) : nullptr;
    uint8_t flags = inner ? *(uint8_t*)((uint8_t*)inner + 0x20) : 0;
    if (!((flags & 1) == 0) ||
        (self->flag_34 != 0 && ((*(uint16_t*)((uint8_t*)inner + 0x20) >> 0xd & 1) != 0))) {
        return 0;
    }
    typedef void* (__cdecl *AllocFn)(void*);
    AllocFn af = *(AllocFn*)self->allocFn_10;
    void* rec = ((void*(*)(void*))af)(self);
    *(void**)((uint8_t*)rec + 8) = param_1;
    FUN_00524a60(rec);
    return 1;
}
