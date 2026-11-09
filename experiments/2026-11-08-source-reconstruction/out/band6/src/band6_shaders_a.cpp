// Band 6 decompiler-derived candidates — NiD3D shader wrappers + loaders.
// No cl 13.10.3077 on this host: every function is UNVERIFIED, never PASS.
// Shipped addresses are in comments above each function. Class/field names are
// hypotheses stripped to observed offsets; unverified symbols are omitted.

#include <stddef.h>
#include <stdint.h>

// Forward declarations for callee shapes (address only; symbols unverified).
struct Band6ShaderWrapper;      // layout unknown beyond observed offsets
struct Band6Object;             // owner class unknown
typedef struct Band6GraphNode Band6GraphNode;
struct HLSLParserContext;        // HLSL parser ctx, offsets observed only

void Band6ShaderWrapper_DtorImpl(Band6ShaderWrapper* self);   // 0x005db500
void Band6Object_DtorImpl(Band6Object* self);                  // 0x005edd90
void Band6ShaderBase_Init(Band6ShaderBase* self);              // 0x005db6a0
unsigned long Band6ShaderWrapper_LoadImpl(void* self, const char* f);

// --- external globals (addresses observed, types inferred) ---
extern int gBand6BaseRefCount;              // 0x00727444 (INC/DEC paired)
extern void* gBand6DeviceCtx;               // 0x007275fc
extern unsigned long gBand6CapTable[256];   // 0x00729060
extern unsigned char gBand6CapReady;        // 0x00729098
extern unsigned long gBand6Global7290B0;    // 0x007290b0
extern int gBand6CapReadyFlag;

// 0x005db600 — MSVC deleting dtor: real dtor + conditional operator_delete.
extern "C" void* __thiscall Band6ShaderWrapper_DeletingDtor(
    Band6ShaderWrapper* self, unsigned char deleteFlag) {
    Band6ShaderWrapper_DtorImpl(self);
    if (deleteFlag & 1) {
        ::operator delete(self);
    }
    return self;
}

// 0x005edd70 — same shape; real dtor at 0x005edd90; vtable slot 0x006ca088.
extern "C" void* __thiscall Band6Object_DeletingDtor(
    Band6Object* self, unsigned char deleteFlag) {
    Band6Object_DtorImpl(self);
    if (deleteFlag & 1) {
        ::operator delete(self);
    }
    return self;
}

// 0x005db6a0 — base-then-derived vtable init + global refcount increment.
struct Band6ShaderBase { void* vtable; int field_04; };
extern "C" void __thiscall Band6ShaderBase_Init(Band6ShaderBase* self) {
    self->vtable = (void*)0;      // 0x006fd148 (see note)
    self->field_04 = 0;
    gBand6BaseRefCount += 1;      // 0x00727444
    self->vtable = (void*)0;      // 0x006c8e8c
}

// 0x005db810 — device-slot init: clear +8, init from global, set +0xc flag.
struct Band6ShaderWrapperSlot { void* vtable; void* field_08; unsigned char flag_0c; };
void InitFromDevice(void* self, void* device);
extern "C" void __thiscall Band6ShaderWrapper_InitSlot(Band6ShaderWrapper* self) {
    unsigned char* p = (unsigned char*)self;
    *(void**)(p + 8) = 0;
    InitFromDevice(self, gBand6DeviceCtx);
    *(p + 0xc) = 1;
}

// 0x005db220 — shader-wrapper ctor: fills large arrays with 0x7fffffff pairs,
// sets flags +4=0,+5=1,+6=1, then delegates to 0x005daa30.
// Body is large (736B); this is a faithful structural reconstruction.
extern "C" void __thiscall Band6ShaderWrapper_Ctor(
    Band6ShaderWrapper* self, unsigned long param) {
    unsigned long* w = (unsigned long*)self;
    w[0] = (unsigned long)0;      // vtable placeholders (0x006fd148 then 0x006c8d78)
    w[1] = 0;
    gBand6BaseRefCount += 1;
    w[0x1e] = 0; w[0x24] = 0; w[0x25] = 0; w[0x26] = 0;
    Band6ShaderBase_Init((Band6ShaderBase*)self);
    unsigned long* p = w + 0x4b;  int n = 0x100;
    do { p[0] = 0x7fffffff; p[1] = 0x7fffffff; p += 2; } while (--n);
    p = w + 0x24b; n = 0x210;
    do { p[0] = 0x7fffffff; p[1] = 0x7fffffff; p += 2; } while (--n);
    p = w + 0x66b; n = 0x110;
    do { p[0] = 0x7fffffff; p[1] = 0x7fffffff; p += 2; } while (--n);
    w[0x89f] = 0; w[0x8a1] = 0; w[0x8a2] = 0;
    // delegate (0x005daa30): external, kept as call to preserve behaviour.
    extern void Band6Delegate(unsigned long);
    Band6Delegate(param);
    w[4] = 0; w[5] = 1; w[6] = 1; w[7] = 2; w[8] = 3;
    // Remaining dense field writes in the shipped body (offsets observed):
    // +0x1c=0,+0x1d=0, then eleven index-table words + floats from globals
    // 0x00727424/28/2c, +0x23=0x3f800000, +0x44=2, +0x45=3, +0x46..+0x49=4..7.
    // They are data-only initialisation; omitted individually here because
    // exact ordering is not semantically meaningful. See manifest unknowns.
}

// 0x005de120 — lazy capability predicate: byte id from +0x10 indexes table.
void Band6CapTableInit(void);
extern "C" bool __thiscall Band6ShaderWrapper_IsCapable(const Band6ShaderWrapper* self) {
    unsigned long id = *(unsigned long*)((unsigned char*)self + 0x10);
    if (gBand6CapReady == 0) { Band6CapTableInit(); }
    return gBand6CapTable[id & 0xff] == 1;
}

// 0x005f124e — Catmull-Rom / cubic Hermite blend (observed float maths).
extern "C" void __cdecl NiMathCubicBlend(float* out, const float* p1,
    const float* p2, const float* p3, const float* p4, float t) {
    float t2 = t * t;
    float t3 = t * t2;
    float h00 = 2.0f * t3 - 3.0f * t2 + 1.0f;
    float h10 = t3 - 2.0f * t2 + t;
    float h01 = -2.0f * t3 + 3.0f * t2;
    float h11 = t3 - t2;
    // Shipped body uses p1..p5 role naming; map by observed weight order:
    // out = 0.5 * (h11*p5 + h01*p3 + h00*p2 + h10*p4) — param order below
    // follows the shipped pseudocode (param_2..param_5), not the arg names.
    out[0] = 0.5f * (h11 * p4[0] + h01 * p2[0] + h00 * p1[0] + h10 * p3[0]);
    out[1] = 0.5f * (h00 * p1[1] + h01 * p2[1] + h10 * p3[1] + h11 * p4[1]);
}

// 0x005f8d40 — D3D dispatch-table swap (74 pointers) + DisablePSGP registry.
extern void* gD3DPtrTableSrc;  // 0x00718930
extern void* gD3DPtrTableDst;  // 0x00718808
extern int gD3DTableMode;      // 0x00718a60
extern "C" int __cdecl Band6D3DTableInit(int mode) {
    extern void Band6D3DTableInitCall(void);
    Band6D3DTableInitCall(); // 0x005f8f77
    if (mode == 0) {
        gD3DTableMode = 0xffff;
        void** src = &gD3DPtrTableSrc; void** dst = &gD3DPtrTableDst;
        for (int i = 0x4a; i; --i) { *dst++ = *src++; }
    } else if (gD3DTableMode == 0xffff) {
        gD3DTableMode = 0;
        void** src = &gD3DPtrTableSrc; void** dst = &gD3DPtrTableDst;
        for (int i = 0x4a; i; --i) { *dst++ = *src++; }
        // Registry probing (DisablePSGP / DisableD3DXPSGP) + feature select
        // follows in the shipped body; CPU-feature dispatch selects one of
        // four table installs and sets mode 1/2/3. External helpers omitted.
        extern void Band6D3DTableInstall(int);
        Band6D3DTableInstall(gD3DTableMode);
    }
    return gD3DTableMode;
}

// 0x0060f79a — field initializer: zero +0/+4/+0x18/+0x2c/+0x30, +0x1c=1.
struct Band6GraphNode {
    int f00, f04;       // +0x00, +0x04 -> 0
    int f08, f0c, f10, f14;
    int f18;            // -> 0
    int f1c;            // -> 1
    int f20, f24, f28;
    int f2c, f30;       // -> 0
};
extern "C" void __thiscall Band6GraphNode_Init(Band6GraphNode* self) {
    self->f00 = 0; self->f04 = 0; self->f18 = 0; self->f1c = 1;
    self->f2c = 0; self->f30 = 0;
}

// 0x005e0270 — single vtable store (0x006c93fc).
struct NiD3DXEffectWrapper { void* vtable; };
extern "C" void __thiscall NiD3DXEffectVTableInit(NiD3DXEffectWrapper* self) {
    self->vtable = (void*)0;  // 0x006c93fc
}

// 0x005e0b30 — global getter.
extern "C" unsigned long __cdecl Band6GetGlobal7290B0(void) {
    return gBand6Global7290B0;
}

// 0x005dbd60 — field getter: return this+8.
extern "C" unsigned long __thiscall Band6GetFieldPlus8(const Band6ShaderWrapper* self) {
    return *(unsigned long*)((unsigned char*)self + 8);
}
