// Band4 wave2 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// 0x0054b530: growable-array append. +0x0c count, +0x08 capacity, +0x14 base.
// Appends FUN_00557b10(0x727938) result at index count; grows via 0x6b34a0
// when capacity <= count, then FUN_005606f0(index, &value).
// Corpus: analysis/pseudocode/functions/0x54b530.c
#include <stddef.h>
#include <stdint.h>

extern void  __cdecl FUN_005386f0(void* self);
extern void* __cdecl FUN_00557b10(void* arg);
extern void  __cdecl FUN_006b34a0(void* growTarget);
extern void  __cdecl FUN_005606f0(unsigned index, void** slot);

extern void* g_obj_727938;

struct Arr54b530 {
    uint32_t w_00;
    uint32_t w_04;
    uint32_t capacity_08;
    uint32_t count_0c;
    uint32_t w_10;
    void*    base_14;
};

// 0x0054b530
void __thiscall FUN_0054b530(Arr54b530* self)
{
    FUN_005386f0(self);
    void* value = FUN_00557b10(g_obj_727938);
    uint32_t idx = self->count_0c;
    if (self->capacity_08 <= idx) {
        FUN_006b34a0((uint8_t*)self->base_14 + idx);
    }
    FUN_005606f0(idx, &value);
}
