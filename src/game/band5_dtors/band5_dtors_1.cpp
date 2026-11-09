// Band5 dtors batch 1/5 — unverified decompiler-derived candidate.
// No cl 13.10.3077. No PASS. See REPORT.md.


#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

extern void __cdecl operator_delete(void* p);
extern void __cdecl operator_delete__(void* p);

extern void __cdecl FUN_00538400(void* self);
extern void __cdecl FUN_00552d20(void* self);
extern void __cdecl FUN_00559020(void* self);
extern void __cdecl FUN_005931d0(void* self);
extern void __cdecl FUN_005e1490(void* self);
extern void __cdecl FUN_005e4780(void* self);
extern void __cdecl FUN_005edba0(void* self);

// ---------------------------------------------------------------------------
// 0x005930a0 — scalar-deleting destructor (unverified), Class_6c5148, vtable 0x6c5148
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c5148; free 0x4; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5930a0.c (see manifest).
extern void* g_vt_6c5148;  // observed vtable 0x6c5148; address hypothesis
// 0x005930a0
void __thiscall FUN_005930a0(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c5148;  // 0x6c5148
    operator_delete__(*(void**)((uint8_t*)self + 0x4));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x00593830 — scalar-deleting destructor (unverified), Class_6c4eb4, vtable 0x6c4eb4
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c514c; call FUN_005931d0; free 0x8; vt 0x6c4eb4; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/593830.c (see manifest).
extern void* g_vt_6c514c;  // observed vtable 0x6c514c; address hypothesis
extern void* g_vt_6c4eb4;  // observed vtable 0x6c4eb4; address hypothesis
// 0x00593830
void __thiscall FUN_00593830(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c514c;  // 0x6c514c
    FUN_005931d0(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    *(void**)self = g_vt_6c4eb4;  // 0x6c4eb4
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x0059aa00 — scalar-deleting destructor (unverified), Class_6c51d8, vtable 0x6c51d8
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c51d8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/59aa00.c (see manifest).
extern void* g_vt_6c51d8;  // observed vtable 0x6c51d8; address hypothesis
// 0x0059aa00
void __thiscall FUN_0059aa00(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c51d8;  // 0x6c51d8
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // corpus also contains refcount-held member handling (e.g. in_ECX[3]) before return; see corpus file.
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005a8960 — scalar-deleting destructor (unverified), Class_6c52d4, vtable 0x6c52d4
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c52d4; free 0x4; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5a8960.c (see manifest).
extern void* g_vt_6c52d4;  // observed vtable 0x6c52d4; address hypothesis
// 0x005a8960
void __thiscall FUN_005a8960(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c52d4;  // 0x6c52d4
    operator_delete__(*(void**)((uint8_t*)self + 0x4));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005ab980 — scalar-deleting destructor (unverified), Class_6c5350, vtable 0x6c5350
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c5350; call FUN_00538400; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5ab980.c (see manifest).
extern void* g_vt_6c5350;  // observed vtable 0x6c5350; address hypothesis
// 0x005ab980
void __thiscall FUN_005ab980(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c5350;  // 0x6c5350
    FUN_00538400(self);
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // corpus also contains refcount-held member handling (e.g. in_ECX[3]) before return; see corpus file.
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005ae850 — scalar-deleting destructor (unverified), NiMeshParticleSystem, vtable 0x6c5988
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c5988; free 0x44; call FUN_00552d20; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5ae850.c (see manifest).
extern void* g_vt_6c5988;  // observed vtable 0x6c5988; address hypothesis
// 0x005ae850
void __thiscall FUN_005ae850(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c5988;  // 0x6c5988
    operator_delete__(*(void**)((uint8_t*)self + 0x44));
    FUN_00552d20(self);
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005aebe0 — scalar-deleting destructor (unverified), Class_6c5a40, vtable 0x6c5a40
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c5a40; call FUN_005edba0; vt 0x6c5a18; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5aebe0.c (see manifest).
extern void* g_vt_6c5a40;  // observed vtable 0x6c5a40; address hypothesis
extern void* g_vt_6c5a18;  // observed vtable 0x6c5a18; address hypothesis
// 0x005aebe0
void __thiscall FUN_005aebe0(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c5a40;  // 0x6c5a40
    FUN_005edba0(self);
    *(void**)self = g_vt_6c5a18;  // 0x6c5a18
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005aec10 — scalar-deleting destructor (unverified), Class_6c5a24, vtable 0x6c5a24
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c5a24; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5aec10.c (see manifest).
extern void* g_vt_6c5a24;  // observed vtable 0x6c5a24; address hypothesis
// 0x005aec10
void __thiscall FUN_005aec10(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c5a24;  // 0x6c5a24
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005aec50 — scalar-deleting destructor (unverified), Class_6c5a4c, vtable 0x6c5a4c
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c5a4c; call FUN_005e1490; vt 0x6c5a24; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5aec50.c (see manifest).
extern void* g_vt_6c5a4c;  // observed vtable 0x6c5a4c; address hypothesis
// 0x005aec50
void __thiscall FUN_005aec50(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c5a4c;  // 0x6c5a4c
    FUN_005e1490(self);
    *(void**)self = g_vt_6c5a24;  // 0x6c5a24
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005b4d30 — scalar-deleting destructor (unverified), Class_6fd148, vtable 0x6fd148
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: call FUN_005e4780; vt 0x6fd148; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5b4d30.c (see manifest).
extern void* g_vt_6fd148;  // observed vtable 0x6fd148; address hypothesis
// 0x005b4d30
void __thiscall FUN_005b4d30(void* self, uint8_t flags)
{
    FUN_005e4780(self);
    *(void**)self = g_vt_6fd148;  // 0x6fd148
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005b83b0 — scalar-deleting destructor (unverified), Class_6c66b4, vtable 0x6c66b4
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c66b4; free 0x10; free 0x1c; call FUN_00538400; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5b83b0.c (see manifest).
extern void* g_vt_6c66b4;  // observed vtable 0x6c66b4; address hypothesis
// 0x005b83b0
void __thiscall FUN_005b83b0(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c66b4;  // 0x6c66b4
    operator_delete__(*(void**)((uint8_t*)self + 0x10));
    operator_delete__(*(void**)((uint8_t*)self + 0x1c));
    FUN_00538400(self);
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // corpus also contains refcount-held member handling (e.g. in_ECX[3]) before return; see corpus file.
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005b93c0 — scalar-deleting destructor (unverified), Class_6c6830, vtable 0x6c6830
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c6830; free 0x50; call FUN_00559020; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5b93c0.c (see manifest).
extern void* g_vt_6c6830;  // observed vtable 0x6c6830; address hypothesis
// 0x005b93c0
void __thiscall FUN_005b93c0(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c6830;  // 0x6c6830
    operator_delete__(*(void**)((uint8_t*)self + 0x50));
    FUN_00559020(self);
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005bbe70 — scalar-deleting destructor (unverified), Class_6c6c18, vtable 0x6c6c18
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c6c18; free 0xc; call FUN_00538400; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5bbe70.c (see manifest).
extern void* g_vt_6c6c18;  // observed vtable 0x6c6c18; address hypothesis
// 0x005bbe70
void __thiscall FUN_005bbe70(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c6c18;  // 0x6c6c18
    operator_delete__(*(void**)((uint8_t*)self + 0xc));
    FUN_00538400(self);
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005bda90 — scalar-deleting destructor (unverified), Class_6c6fdc, vtable 0x6c6fdc
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c6fdc; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5bda90.c (see manifest).
extern void* g_vt_6c6fdc;  // observed vtable 0x6c6fdc; address hypothesis
// 0x005bda90
void __thiscall FUN_005bda90(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c6fdc;  // 0x6c6fdc
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005bdad0 — scalar-deleting destructor (unverified), Class_6c7030, vtable 0x6c7030
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c7030; call FUN_005e1490; vt 0x6c6fdc; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5bdad0.c (see manifest).
extern void* g_vt_6c7030;  // observed vtable 0x6c7030; address hypothesis
// 0x005bdad0
void __thiscall FUN_005bdad0(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c7030;  // 0x6c7030
    FUN_005e1490(self);
    *(void**)self = g_vt_6c6fdc;  // 0x6c6fdc
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

