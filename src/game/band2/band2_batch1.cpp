// Band 2 batch 1 — decompiler-derived reconstruction candidates (UNVERIFIED, no PASS claim)
// Built from analysis/team/band2/deep/*.md and analysis/pseudocode/functions/*.c
// All functions are hypotheses; cl 13.10.3077 is absent so nothing is byte-matched.
#include <windows.h>
#include <string.h>

namespace band2_candidate {

// 0x004c3a20 — two-word inequality predicate (EAX=this at entry, RET plain)
// Observed: compares [EAX+0x88]/[EAX+0x8c] vs DAT_008dc30c/DAT_008dc310; returns 0 if both equal else 1.
extern int gRefA_8dc30c;
extern int gRefB_8dc310;
struct TwoWord_4c3a20 {
    char _pad[0x88];
    int field_88;
    int field_8c;
    int IsNotEqualToRef() const { return field_88 != gRefA_8dc30c || field_8c != gRefB_8dc310; }
};

// 0x004d5850 — constant-return-7 leaf (MOV EAX,7; RET)
inline int FUN_004d5850(void) { return 7; }

// 0x004f4e50 — conditional field getter, ECX=this, RET plain
// Observed: if (*(this+0x2c)==0) return *(this+0x24); else return *(*(this+0x2c)+0x18);
inline void* FUN_004f4e50(void* pThis) {
    char* t = (char*)pThis;
    if (*(int*)(t + 0x2c) == 0) return *(void**)(t + 0x24);
    return *(void**)(*(int*)(t + 0x2c) + 0x18);
}

// 0x004f8bc0 — OutputDebugStringA forwarder (1 stack arg, RET plain)
inline void FUN_004f8bc0(LPCSTR msg) { OutputDebugStringA(msg); }

// 0x0050b060 — thiscall modulo, ECX=this, RET 4: (u16)v % *(this+4)
struct Modulo_50b060 {
    unsigned divisor_4;
    unsigned Mod(unsigned short v) { return (unsigned)v % divisor_4; }
};

// 0x00513ce0 — empty stdcall stub (RET 4, 1 arg)
inline void __stdcall FUN_00513ce0(int unused) { (void)unused; }

// 0x004ccc10 — scalar deleting dtor (ECX=this, RET 4)
// Observed: PUSH ESI; MOV ESI,ECX; CALL 0x4cd250; TEST [ESP+8],1; conditional operator_delete(ESI); MOV EAX,ESI; RET 4.
// Hand-authored dtor source; deleting-dtor bytes are compiler lowering, not reproduced here.
struct ScalarDtor_4ccc10 {
    ~ScalarDtor_4ccc10() { /* body at 0x4cd250, unreconstructed */ }
};
// Sketch of call shape only — MSVC emits this via `delete` on heap instances.

// 0x004f7dc0 — vtable-swap deleting dtor (ECX=this, RET 4)
// Observed: vtable 0x710678 -> CALL 0x4e6420 -> vtable 0x71065c -> CALL 0x4e6420 -> operator_delete([ESI+8]) -> conditional operator_delete(ESI).
struct Dtor_4f7dc0 {
    void* vtable_override; // layout placeholder; real class unknown
    void* BaseDtorSegment(); // 0x4e6420 (inferred)
    ~Dtor_4f7dc0();
};

// 0x00514060 — single-vtable deleting dtor, band tail (ECX=this, RET 4)
// Observed: vtable 0x711994 -> operator_delete([ESI+4]) -> conditional operator_delete(ESI).
struct Dtor_514060 {
    void* vtable_override;
    void* member_4; // [this+4], freed via 0x5f08dc
    ~Dtor_514060() { operator delete(member_4); }
};

// 0x00500460 — shader-lib dispatch by name (__cdecl, 6 args, RET plain)
// Observed: strstr(name,"NiD3DXEffectShaderLib") -> 0x5e0220; else strstr(name,"NSBShaderLib") -> 0x5e7c90; else 0.
extern void* FUN_005e0220(void*, void*, void*, void*, void*);
extern void* FUN_005e7c90(void*, void*, void*, void*, void*);
inline void* FUN_00500460(const char* name, void* a, void* b, void* c, void* d, void* e) {
    if (strstr(name, "NiD3DXEffectShaderLib")) return FUN_005e0220(a, b, c, d, e);
    if (strstr(name, "NSBShaderLib")) return FUN_005e7c90(a, b, c, d, e);
    return 0;
}

} // namespace band2_candidate
