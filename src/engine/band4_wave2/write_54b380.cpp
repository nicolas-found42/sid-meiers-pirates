// Band4 wave2 reconstruction candidates (UNVERIFIED; no cl 13.10.3077).
// 0x0054b380: byte-serialization dispatcher; target pointer at +0x158 (index
// 0x58), fields +0x0c / +0x14 select path; fallback writes to a 128-byte stack
// buffer at +0x98.
// Corpus: analysis/pseudocode/functions/0x54b380.c
#include <stddef.h>
#include <stdint.h>

extern void  __cdecl FUN_00538430(void* self);
extern void  __cdecl FUN_00545950(void* p);
extern void  __thiscall FUN_0054b380(int* self);

typedef int (__cdecl *WriteFn)(void* self, uint8_t flag);

struct Obj54b380 {
    void*    vtable_00;
    uint32_t w_04;
    int      flag_0c;
    int      pad_10;
    int      flag_14;
    uint8_t  pad_18[0x158 - 0x18];
    void*    sink_158;
};

// 0x0054b380
void __thiscall FUN_0054b380(Obj54b380* self, uint8_t flag)
{
    uint8_t stackBuf[128];
    FUN_00538430(self);
    if (self->flag_0c != 0) {
        typedef void (__cdecl *W)(uint8_t);
        void** vt = *(void***)self->sink_158;
        // observed: (**(sink_vt+0x0c))((flag<<8)|? ) — CONCAT31(?,1) then call
        W w = (W)vt[0x0c / 4];
        w((uint8_t)(flag | 0));
        FUN_00545950((void*)(uintptr_t)self->flag_0c);
        return;
    }
    uint8_t byteArg = (uint8_t)(flag << 0); // observed shift left 8 of low byte
    void** vt = *(void***)self->sink_158;
    if (self->flag_14 == 0) {
        typedef void (__cdecl *W2)(uint8_t, int);
        W2 w = (W2)vt[0x0c / 4];
        w(byteArg, 1);
        W2 w2 = (W2)vt[0x0c / 4];
        w2(stackBuf + 0x98 - 128 + 128, 1); // observed: auStackY_9c+0x98 second call
        return;
    }
    typedef void (__cdecl *W3)(void);
    W3 w3 = (W3)vt[0x0c / 4];
    w3();
    typedef void (__cdecl *W4)(uint8_t*, int);
    W4 w4 = (W4)vt[0x0c / 4];
    w4(stackBuf + 0x98 - 128 + 128, 1);
    void** vt2 = *(void***)self;
    typedef void (__cdecl *W5)(void*, int);
    W5 w5 = (W5)vt2[0x2c / 4];
    w5(self, self->flag_14);
}
