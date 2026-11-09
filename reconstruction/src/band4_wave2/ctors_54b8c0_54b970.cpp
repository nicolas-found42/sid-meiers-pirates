// Band4 wave2 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// 0x0054b8c0: ctor A; 0x0054b970: ctor B init.
// 54b8c0: FUN_0054b970 base, vtable 0x6c2020, fields +0x48..+0x5c,
// alloc 0xd4 via thunk_FUN_00533c78, zero words, +0x10=0x80,+0x3c=0x35.
// 54b970: FUN_005565b0 base, vtable 0x6c2088, byte +0x35=1, byte +0x0d.. wait
// +0x35=0, *(+0xd)=1.
// Corpus: 0x54b8c0.c, 0x54b970.c
#include <stddef.h>
#include <stdint.h>

extern void* __cdecl thunk_FUN_00533c78(int nbytes);
extern void  __thiscall FUN_005565b0(void* self);
extern void  __thiscall FUN_0054b970(void* self);

extern void* g_vtable_6c2020, *g_vtable_6c2064, *g_vtable_6c2088;

struct Obj54b8c0 {
    void*    vtable_00;
    uint32_t w_04;
    uint32_t w_08;
    uint32_t w_0c;
    uint32_t p_10;
    uint32_t w_14;
    uint32_t w_18;
    uint32_t w_1c;
    uint32_t w_20;
    uint32_t w_24;
    uint32_t w_28;
    uint32_t w_2c;
    uint32_t w_30;
    uint8_t  b_34;
    uint8_t  b_35;
    void*    buf_38;
    uint32_t w_3c;
    uint32_t w_40;
    uint32_t w_44;
    uint32_t w_48;
    uint32_t w_4c;
    uint32_t w_50;
    uint32_t w_54;
    void*    vtable2_10; // index 0x10 (dword at +0x40) holds 0x6c2064 in ctor
};

// 0x0054b970 — ctor init, this in ECX
void __thiscall FUN_0054b970(Obj54b8c0* self)
{
    FUN_005565b0(self);
    self->vtable_00 = &g_vtable_6c2088;
    *(uint8_t*)((uint8_t*)self + 0x35) = 1;
    // observed: *(u1*)(this+0xd)=1 ; *(u1*)(this+0x35)=0
    *(uint8_t*)((uint8_t*)self + 0x0d) = 1;
    *(uint8_t*)((uint8_t*)self + 0x35) = 0;
}

// 0x0054b8c0 — ctor, this in ECX
void __thiscall FUN_0054b8c0(Obj54b8c0* self)
{
    FUN_0054b970(self);
    self->vtable_00 = &g_vtable_6c2020;
    self->w_54 = 0; // index 0x15
    self->w_4c = 0; // index 0x13
    self->w_50 = 0; // index 0x14
    self->vtable2_10 = &g_vtable_6c2064; // index 0x12
    self->p_10 = 0x80; // index 0x10
    self->w_14 = 0; // index 0x11
    self->w_3c = 0x35; // index 0x0f
    uint32_t* buf = (uint32_t*)thunk_FUN_00533c78(0xd4);
    self->buf_38 = buf; // index 0x0e
    for (uint32_t n = self->w_3c & 0x3fffffff; n != 0; --n) {
        *buf++ = 0;
    }
    for (int i = 0; i != 0; i = i - 1) {
        *(uint8_t*)buf = 0;
        buf = (uint32_t*)((uint8_t*)buf + 1);
    }
    self->w_58 = 0; // index 0x16
}
