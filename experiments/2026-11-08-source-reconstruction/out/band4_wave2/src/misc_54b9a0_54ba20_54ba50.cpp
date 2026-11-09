// Band4 wave2 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// 0x0054b9a0: copy bytes +0x34/+0x35 via thunk_FUN_00538410.
// 0x0054ba20: bool wrapper over FUN_00556280.
// 0x0054ba50: deleting dtor, vtable 0x6c2088, FUN_005562a0, flag&1 delete.
// Corpus: 0x54b9a0.c, 0x54ba20.c, 0x54ba50.c
#include <stddef.h>
#include <stdint.h>

extern void  __cdecl thunk_FUN_00538410(void* dst, void* src);
extern int   __cdecl FUN_00556280(void* p);
extern void  __cdecl operator_delete(void* p);
extern void  __cdecl FUN_005562a0(void* self);

extern void* g_vtable_6c2088;

struct Obj54b9a0 {
    void*   vtable_00;
    uint32_t w_04;
    uint32_t w_08;
    uint32_t w_0c;
    uint32_t w_10;
    uint32_t w_14;
    uint32_t w_18;
    uint32_t w_1c;
    uint32_t w_20;
    uint32_t w_24;
    uint32_t w_28;
    uint32_t w_2c;
    uint32_t w_30;
    uint8_t b_34;
    uint8_t b_35;
};

// 0x0054b9a0
void __thiscall FUN_0054b9a0(Obj54b9a0* src, Obj54b9a0* dst)
{
    thunk_FUN_00538410(dst, src);
    dst->b_34 = src->b_34;
    dst->b_35 = src->b_35;
}

// 0x0054ba20
bool __cdecl FUN_0054ba20(void* p)
{
    return FUN_00556280(p) != 0;
}

// 0x0054ba50
void __thiscall FUN_0054ba50(Obj54b9a0* self, uint8_t flag)
{
    self->vtable_00 = &g_vtable_6c2088;
    FUN_005562a0(self);
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}
