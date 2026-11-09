// Band 6 decompiler-derived candidates — context-routed create variants + effect lib.
// UNVERIFIED. Each mirrors the shared create pattern of 0x005dc640 but takes
// its operands from the caller's vtable (0x005dd0c0/0x005dd1b0/0x005dce40/0x005dcf80).
// Operand bytes observed in corpus; names are hypotheses.

#include <stddef.h>
#include <stdint.h>

typedef void* (*VFn)(void*);
struct SObj { void* vtable; };

extern void* operator new(size_t);
extern void Band6Fatal(int, int, const char*, ...);
extern unsigned long Band6ShaderAssemble(void*, void*, unsigned long, void*, void*, void**, unsigned long*, void*);

// 0x005dce40 — vertex variant A: vtable pocket 0x006c8ed8, reader at vtable+0x24.
extern "C" void* __thiscall Band6CreateVertexShaderFromContext(void* self, void* a, void* b) {
    (void)b;
    SObj* obj = (SObj*)operator new(0x34);
    if (!obj) return 0;
    unsigned long* w = (unsigned long*)obj;
    extern void Band6ShaderInitCommon(void*, void*);
    Band6ShaderInitCommon(obj, 0);
    extern unsigned char Band6ReadCtxA(void*, void*, void*, void*, void*, void*);
    unsigned char* out1 = 0; unsigned long* out2 = 0; void* out3 = 0; void* out4 = 0;
    unsigned char ok = Band6ReadCtxA(self, a, &out1, &out2, &out3, &out4);
    w[9] = (unsigned long)out1; (void)w;
    if (ok) {
        extern unsigned long Band6NativeCreateVS(void*, void*, void*, void*);
        if (!Band6NativeCreateVS(obj, out3, out1, out4)) {
            Band6Fatal(1, 0, "Failed CreateVertexShader call on %s\n",
                (const char*)out1);
            return 0;
        }
    }
    return obj;
}

// 0x005dcf80 — vertex variant B: reader at vtable+0x28.
extern "C" void* __thiscall Band6CreateVertexShaderFromContext2(void* self, void* a, void* b) {
    SObj* obj = (SObj*)operator new(0x34);
    if (!obj) return 0;
    extern void Band6ShaderInitCommon(void*, void*);
    Band6ShaderInitCommon(obj, 0);
    extern unsigned char Band6ReadCtxB(void*, void*, void*, void*, void*, void*);
    unsigned char* out1 = 0; unsigned long l1 = 0, l2 = 0; void* p1 = 0;
    unsigned long dl = 0;
    unsigned char ok = Band6ReadCtxB(self, a, b, &dl, &l1, &l2, &p1);
    if (ok) {
        extern unsigned long Band6NativeCreateVS(void*, void*, void*, void*);
        if (!Band6NativeCreateVS(obj, p1, (void*)l1, (void*)l2)) {
            Band6Fatal(1, 0, "Failed CreateVertexShader call on %s\n", (const char*)out1);
            return 0;
        }
    }
    return obj;
}

// 0x005dd0c0 — pixel variant A: pocket 0x006c8e98 (0x28 bytes), reader vtable+0x24.
extern "C" void* __thiscall Band6CreatePixelShaderFromContext(void* self, void* a) {
    SObj* obj = (SObj*)operator new(0x28);
    if (!obj) return 0;
    extern void Band6ShaderInitCommon(void*, void*);
    Band6ShaderInitCommon(obj, 0);
    extern unsigned char Band6ReadCtxC(void*, void*, void*, void*, void*, void*);
    unsigned char* out1 = 0; unsigned long l1 = 0, l2 = 0; void* p1 = 0;
    unsigned char ok = Band6ReadCtxC(self, a, &l1, &out1, &l2, &p1);
    if (ok) {
        extern unsigned long Band6NativeCreatePS(void*);
        if (Band6NativeCreatePS(obj)) return obj;
        Band6Fatal(1, 0, "Failed CreatePixelShader call on %s\n", (const char*)out1);
    }
    return obj;
}

// 0x005dd1b0 — pixel variant B: reader vtable+0x28.
extern "C" void* __thiscall Band6CreatePixelShaderFromContext2(void* self, void* a, void* b) {
    SObj* obj = (SObj*)operator new(0x28);
    if (!obj) return 0;
    extern void Band6ShaderInitCommon(void*, void*);
    Band6ShaderInitCommon(obj, 0);
    extern unsigned char Band6ReadCtxD(void*, void*, void*, void*, void*, void*);
    unsigned char* out1 = 0; unsigned long l1 = 0, l2 = 0;
    unsigned char ok = Band6ReadCtxD(self, a, b, &l1, &out1, &l2, (void**)&b);
    if (ok) {
        extern unsigned long Band6NativeCreatePS(void*);
        if (Band6NativeCreatePS(obj)) return obj;
        Band6Fatal(1, 0, "Failed CreatePixelShader call on %s\n", (const char*)out1);
    }
    return obj;
}

// 0x005e0880 — NiD3DXEffectShaderLib ctor: vtable pockets 0x006c9468/0x006c9424/
// 0x006c9408/0x006c949c, 0x94-byte array allocation at +0xc, size 0x25.
// SEH frame observed; registration string "NiD3DXEffectShaderLib".
struct EffectLib { void* vtable; int pad[0x2e]; void* arr; int count; };
extern "C" void __thiscall Band6NiD3DXEffectShaderLib_Ctor(void* self) {
    EffectLib* e = (EffectLib*)self;
    extern void Band6RegisterShaderLib(const char*);
    Band6RegisterShaderLib("NiD3DXEffectShaderLib");
    e->vtable = (void*)0;  // 0x006c9468
    e->pad[5] = 0; e->pad[3] = 0; e->pad[4] = 0;   // +0x1c etc. (observed)
    e->pad[2] = (int)(void*)0;  // 0x006c9424
    e->count = 0x25;
    e->arr = operator new(0x94);
    unsigned long* it = (unsigned long*)e->arr;
    for (unsigned long i = e->count & 0x3fffffff; i; --i) *it++ = 0;
    e->pad[6] = (int)(void*)0;  // 0x006c949c
}
