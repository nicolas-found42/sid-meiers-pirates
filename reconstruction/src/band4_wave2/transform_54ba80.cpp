// Band4 wave2 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// 0x0054ba80 (non-contiguous): copy +0x1c to +0x20; grow buffers +0x28/+0x2c
// when count > cap; compute fVar2/fVar3/fVar4 from *(+0x0c)+0x104/0x108/0x10c;
// dot product with (0x28,0x2c,0x30), minus 0x34 when flag +0x35 set; sort
// FUN_00556330(0, count-1).
// Corpus: analysis/pseudocode/functions/0x54ba80.c
#include <stddef.h>
#include <stdint.h>

extern void  __cdecl operator_delete__(void* p);
extern void* __cdecl thunk_FUN_00533c78(int nbytes);
extern void  __cdecl FUN_00556330(int lo, int hi);

struct Obj54ba80 {
    void*    vtable_00;
    uint32_t w_04;
    void*    transform_0c; // +0x0c -> +0x104/0x108/0x10c floats
    uint32_t w_10;
    void*    nodes_14;
    uint32_t count_1c;
    uint32_t count_20;
    uint32_t capacity_24;
    void*    bufA_28;
    void*    bufB_2c;
    uint32_t w_30;
    uint32_t w_34;
    uint8_t  flag_35;
    uint8_t  pad_36[2];
};

// 0x0054ba80
void __thiscall FUN_0054ba80(Obj54ba80* self)
{
    self->count_20 = self->count_1c;
    if (self->count_1c == 0) {
        return;
    }
    if (self->count_1c > self->capacity_24) {
        operator_delete__(*(void**)((uint8_t*)self + 0x28));
        self->capacity_24 = self->count_20;
        self->bufA_28 = thunk_FUN_00533c78((int)(self->count_20 * 4));
        operator_delete__(*(void**)((uint8_t*)self + 0x2c));
        self->bufB_2c = thunk_FUN_00533c78((int)(self->capacity_24 << 2));
    }
    float fx = *(float*)((uint8_t*)self->transform_0c + 0x104);
    float fy = *(float*)((uint8_t*)self->transform_0c + 0x108);
    float fz = *(float*)((uint8_t*)self->transform_0c + 0x10c);
    void* node = self->nodes_14;
    int subtract = (self->flag_35 != 0) ? 1 : 0;
    for (uint32_t i = 0; i < self->count_20; ++i) {
        void** np = (void**)node;
        uint32_t* dsts = (uint32_t*)self->bufA_28;
        float* dstf = (float*)self->bufB_2c;
        void* entry = np[2];
        dsts[i] = (uint32_t)(uintptr_t)entry;
        uint8_t* e = (uint8_t*)entry;
        float d = fx * *(float*)(e + 0x28) + fz * *(float*)(e + 0x30) + fy * *(float*)(e + 0x2c);
        if (subtract) {
            d -= *(float*)(e + 0x34);
        }
        dstf[i] = d;
        node = np[0];
    }
    FUN_00556330(0, (int)(self->count_20 - 1));
}
