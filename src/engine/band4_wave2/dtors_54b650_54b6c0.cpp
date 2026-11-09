// Band4 wave2 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// 0x0054b650: vtable 0x6c2020, iterate linked list at +0x4c (index 0x13),
// free *(node+8), free +0x38, vtable 0x6c2064 + FUN_005edba0, then
// 0x6c2010 + FUN_0054b990.
// 0x0054b6c0: vtable 0x6c2064, FUN_005edba0, vtable 0x6c2010, flag&1 delete.
// Corpus: 0x54b650.c, 0x54b6c0.c
#include <stddef.h>
#include <stdint.h>

extern void  __cdecl operator_delete(void* p);
extern void  __cdecl operator_delete__(void* p);
extern void  __cdecl FUN_005edba0(void* self);
extern void  __cdecl FUN_0054b990(void* self);

extern void* g_vtable_6c2020, *g_vtable_6c2064, *g_vtable_6c2010;

struct Node650 {
    Node650* next_00;
    uint32_t w_04;
    void*    payload_08;
};

struct Obj54b650 {
    void*     vtable_00;
    uint32_t  w_04;
    uint32_t  w_08;
    uint32_t  w_0c;
    uint32_t  w_10;
    uint32_t  w_14;
    uint32_t  w_18;
    uint32_t  w_1c;
    uint32_t  w_20;
    uint32_t  w_24;
    uint32_t  w_28;
    uint32_t  w_2c;
    uint32_t  w_30;
    uint32_t  w_34;
    void*     buf_38;    // index 0x0e
    uint32_t  w_3c;
    uint32_t  w_40;
    uint32_t  w_44;
    void*     vtable2;   // index 0x12
    Node650*  list_4c;   // index 0x13
};

// 0x0054b650
void __thiscall FUN_0054b650(Obj54b650* self)
{
    Node650* node = self->list_4c;
    self->vtable_00 = &g_vtable_6c2020;
    while (node != nullptr) {
        Node650* next = node->next_00;
        operator_delete__(node->payload_08);
        node = next;
    }
    operator_delete__(self->buf_38);
    self->vtable2 = &g_vtable_6c2064;
    FUN_005edba0(self);
    self->vtable2 = &g_vtable_6c2010;
    FUN_0054b990(self);
}

// 0x0054b6c0
void __thiscall FUN_0054b6c0(Obj54b650* self, uint8_t flag)
{
    self->vtable_00 = &g_vtable_6c2064;
    FUN_005edba0(self);
    self->vtable_00 = &g_vtable_6c2010;
    if ((flag & 1) != 0) {
        operator_delete(self);
    }
}
