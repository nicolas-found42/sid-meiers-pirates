// Band5 dtors batch 3/5 — unverified decompiler-derived candidate.
// No cl 13.10.3077. No PASS. See REPORT.md.


#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

extern void __cdecl operator_delete(void* p);
extern void __cdecl operator_delete__(void* p);

extern void __cdecl FUN_00547650(void* self);
extern void __cdecl FUN_0055a310(void* self);
extern void __cdecl FUN_005e1490(void* self);
extern void __cdecl FUN_005edba0(void* self);

// ---------------------------------------------------------------------------
// 0x005c8d10 — scalar-deleting destructor (unverified), Class_6c77d4, vtable 0x6c77d4
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c77d4; call FUN_005e1490; vt 0x6c76fc; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5c8d10.c (see manifest).
extern void* g_vt_6c77d4;  // observed vtable 0x6c77d4; address hypothesis
extern void* g_vt_6c76fc;  // observed vtable 0x6c76fc; address hypothesis
// 0x005c8d10
void __thiscall FUN_005c8d10(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c77d4;  // 0x6c77d4
    FUN_005e1490(self);
    *(void**)self = g_vt_6c76fc;  // 0x6c76fc
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005c8d50 — scalar-deleting destructor (unverified), Class_6c7718, vtable 0x6c7718
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c7718; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5c8d50.c (see manifest).
extern void* g_vt_6c7718;  // observed vtable 0x6c7718; address hypothesis
// 0x005c8d50
void __thiscall FUN_005c8d50(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c7718;  // 0x6c7718
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005c8d90 — scalar-deleting destructor (unverified), Class_6c77f0, vtable 0x6c77f0
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c77f0; call FUN_005e1490; vt 0x6c7718; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5c8d90.c (see manifest).
extern void* g_vt_6c77f0;  // observed vtable 0x6c77f0; address hypothesis
// 0x005c8d90
void __thiscall FUN_005c8d90(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c77f0;  // 0x6c77f0
    FUN_005e1490(self);
    *(void**)self = g_vt_6c7718;  // 0x6c7718
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005c8dd0 — scalar-deleting destructor (unverified), Class_6c7734, vtable 0x6c7734
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c7734; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5c8dd0.c (see manifest).
extern void* g_vt_6c7734;  // observed vtable 0x6c7734; address hypothesis
// 0x005c8dd0
void __thiscall FUN_005c8dd0(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c7734;  // 0x6c7734
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005c8e10 — scalar-deleting destructor (unverified), Class_6c780c, vtable 0x6c780c
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c780c; call FUN_005e1490; vt 0x6c7734; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5c8e10.c (see manifest).
extern void* g_vt_6c780c;  // observed vtable 0x6c780c; address hypothesis
// 0x005c8e10
void __thiscall FUN_005c8e10(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c780c;  // 0x6c780c
    FUN_005e1490(self);
    *(void**)self = g_vt_6c7734;  // 0x6c7734
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005c8e50 — scalar-deleting destructor (unverified), Class_6c7750, vtable 0x6c7750
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c7750; call FUN_005e1490; call FUN_005e1490; vt 0x6fd148; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5c8e50.c (see manifest).
extern void* g_vt_6c7750;  // observed vtable 0x6c7750; address hypothesis
extern void* g_vt_6fd148;  // observed vtable 0x6fd148; address hypothesis
// 0x005c8e50
void __thiscall FUN_005c8e50(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c7750;  // 0x6c7750
    FUN_005e1490(self);
    FUN_005e1490(self);
    *(void**)self = g_vt_6fd148;  // 0x6fd148
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // corpus also contains refcount-held member handling (e.g. in_ECX[3]) before return; see corpus file.
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005c9530 — scalar-deleting destructor (unverified), Class_6c787c, vtable 0x6c787c
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c787c; free 0x4; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5c9530.c (see manifest).
extern void* g_vt_6c787c;  // observed vtable 0x6c787c; address hypothesis
// 0x005c9530
void __thiscall FUN_005c9530(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c787c;  // 0x6c787c
    operator_delete__(*(void**)((uint8_t*)self + 0x4));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005c9a00 — scalar-deleting destructor (unverified), Class_6c78d8, vtable 0x6c78d8
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c78d8; call FUN_00547650; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5c9a00.c (see manifest).
extern void* g_vt_6c78d8;  // observed vtable 0x6c78d8; address hypothesis
// 0x005c9a00
void __thiscall FUN_005c9a00(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c78d8;  // 0x6c78d8
    FUN_00547650(self);
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // corpus also contains refcount-held member handling (e.g. in_ECX[3]) before return; see corpus file.
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005c9e40 — scalar-deleting destructor (unverified), PSVERSION, vtable 0x6c799c
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c799c; call FUN_0055a310; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5c9e40.c (see manifest).
extern void* g_vt_6c799c;  // observed vtable 0x6c799c; address hypothesis
// 0x005c9e40
void __thiscall FUN_005c9e40(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c799c;  // 0x6c799c
    FUN_0055a310(self);
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // corpus also contains refcount-held member handling (e.g. in_ECX[3]) before return; see corpus file.
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005cbef0 — scalar-deleting destructor (unverified), D3DFMT_R8G8B8, vtable 0x6c7d60
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c7d60; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5cbef0.c (see manifest).
extern void* g_vt_6c7d60;  // observed vtable 0x6c7d60; address hypothesis
// 0x005cbef0
void __thiscall FUN_005cbef0(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c7d60;  // 0x6c7d60
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005cbf30 — scalar-deleting destructor (unverified), Class_6c7d90, vtable 0x6c7d90
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c7d90; call FUN_005e1490; vt 0x6c7d60; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5cbf30.c (see manifest).
extern void* g_vt_6c7d90;  // observed vtable 0x6c7d90; address hypothesis
// 0x005cbf30
void __thiscall FUN_005cbf30(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c7d90;  // 0x6c7d90
    FUN_005e1490(self);
    *(void**)self = g_vt_6c7d60;  // 0x6c7d60
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005cbf90 — scalar-deleting destructor (unverified), Class_6c7dac, vtable 0x6c7dac
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c7dac; call FUN_005edba0; vt 0x6c7d7c; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5cbf90.c (see manifest).
extern void* g_vt_6c7dac;  // observed vtable 0x6c7dac; address hypothesis
extern void* g_vt_6c7d7c;  // observed vtable 0x6c7d7c; address hypothesis
// 0x005cbf90
void __thiscall FUN_005cbf90(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c7dac;  // 0x6c7dac
    FUN_005edba0(self);
    *(void**)self = g_vt_6c7d7c;  // 0x6c7d7c
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005cbfc0 — scalar-deleting destructor (unverified), Class_6c7d88, vtable 0x6c7d88
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c7d88; free 0x4; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5cbfc0.c (see manifest).
extern void* g_vt_6c7d88;  // observed vtable 0x6c7d88; address hypothesis
// 0x005cbfc0
void __thiscall FUN_005cbfc0(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c7d88;  // 0x6c7d88
    operator_delete__(*(void**)((uint8_t*)self + 0x4));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005cbff0 — scalar-deleting destructor (unverified), Class_6c7d8c, vtable 0x6c7d8c
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c7d8c; free 0x4; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5cbff0.c (see manifest).
extern void* g_vt_6c7d8c;  // observed vtable 0x6c7d8c; address hypothesis
// 0x005cbff0
void __thiscall FUN_005cbff0(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c7d8c;  // 0x6c7d8c
    operator_delete__(*(void**)((uint8_t*)self + 0x4));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005cd3d0 — scalar-deleting destructor (unverified), Class_6c7df4, vtable 0x6c7df4
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c7df4; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5cd3d0.c (see manifest).
extern void* g_vt_6c7df4;  // observed vtable 0x6c7df4; address hypothesis
// 0x005cd3d0
void __thiscall FUN_005cd3d0(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c7df4;  // 0x6c7df4
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

