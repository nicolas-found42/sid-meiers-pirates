// Band5 dtors batch 4/5 — unverified decompiler-derived candidate.
// No cl 13.10.3077. No PASS. See REPORT.md.


#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

extern void __cdecl operator_delete(void* p);
extern void __cdecl operator_delete__(void* p);

extern void __cdecl FUN_00552d20(void* self);
extern void __cdecl FUN_005cce50(void* self);
extern void __cdecl FUN_005cea90(void* self);
extern void __cdecl FUN_005d6040(void* self);
extern void __cdecl FUN_005db500(void* self);
extern void __cdecl FUN_005e1490(void* self);
extern void __cdecl FUN_005edba0(void* self);

// ---------------------------------------------------------------------------
// 0x005cd410 — scalar-deleting destructor (unverified), Class_6c7e10, vtable 0x6c7e10
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c7e10; call FUN_005e1490; vt 0x6c7df4; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5cd410.c (see manifest).
extern void* g_vt_6c7e10;  // observed vtable 0x6c7e10; address hypothesis
extern void* g_vt_6c7df4;  // observed vtable 0x6c7df4; address hypothesis
// 0x005cd410
void __thiscall FUN_005cd410(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c7e10;  // 0x6c7e10
    FUN_005e1490(self);
    *(void**)self = g_vt_6c7df4;  // 0x6c7df4
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005ce7b0 — scalar-deleting destructor (unverified), Class_6c7e70, vtable 0x6c7e70
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c7e70; call FUN_00552d20; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5ce7b0.c (see manifest).
extern void* g_vt_6c7e70;  // observed vtable 0x6c7e70; address hypothesis
// 0x005ce7b0
void __thiscall FUN_005ce7b0(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c7e70;  // 0x6c7e70
    FUN_00552d20(self);
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005cee30 — scalar-deleting destructor (unverified), Class_6c7fb8, vtable 0x6c7fb8
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c7fb8; call FUN_005cce50; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5cee30.c (see manifest).
extern void* g_vt_6c7fb8;  // observed vtable 0x6c7fb8; address hypothesis
// 0x005cee30
void __thiscall FUN_005cee30(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c7fb8;  // 0x6c7fb8
    FUN_005cce50(self);
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // corpus also contains refcount-held member handling (e.g. in_ECX[3]) before return; see corpus file.
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005cf030 — scalar-deleting destructor (unverified), Class_6c8034, vtable 0x6c8034
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c8034; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5cf030.c (see manifest).
extern void* g_vt_6c8034;  // observed vtable 0x6c8034; address hypothesis
// 0x005cf030
void __thiscall FUN_005cf030(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c8034;  // 0x6c8034
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // corpus also contains refcount-held member handling (e.g. in_ECX[3]) before return; see corpus file.
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005cf7a0 — scalar-deleting destructor (unverified), Class_6c8190, vtable 0x6c8190
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c8190; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5cf7a0.c (see manifest).
extern void* g_vt_6c8190;  // observed vtable 0x6c8190; address hypothesis
// 0x005cf7a0
void __thiscall FUN_005cf7a0(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c8190;  // 0x6c8190
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005cf7e0 — scalar-deleting destructor (unverified), Class_6c81b8, vtable 0x6c81b8
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c81b8; call FUN_005e1490; vt 0x6c8190; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5cf7e0.c (see manifest).
extern void* g_vt_6c81b8;  // observed vtable 0x6c81b8; address hypothesis
// 0x005cf7e0
void __thiscall FUN_005cf7e0(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c81b8;  // 0x6c81b8
    FUN_005e1490(self);
    *(void**)self = g_vt_6c8190;  // 0x6c8190
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005cf840 — scalar-deleting destructor (unverified), Class_6c81d4, vtable 0x6c81d4
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c81d4; call FUN_005edba0; vt 0x6c81ac; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5cf840.c (see manifest).
extern void* g_vt_6c81d4;  // observed vtable 0x6c81d4; address hypothesis
extern void* g_vt_6c81ac;  // observed vtable 0x6c81ac; address hypothesis
// 0x005cf840
void __thiscall FUN_005cf840(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c81d4;  // 0x6c81d4
    FUN_005edba0(self);
    *(void**)self = g_vt_6c81ac;  // 0x6c81ac
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005d07d0 — scalar-deleting destructor (unverified), Class_6c824c, vtable 0x6c824c
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c824c; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5d07d0.c (see manifest).
extern void* g_vt_6c824c;  // observed vtable 0x6c824c; address hypothesis
// 0x005d07d0
void __thiscall FUN_005d07d0(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c824c;  // 0x6c824c
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005d0810 — scalar-deleting destructor (unverified), Class_6c8268, vtable 0x6c8268
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c8268; call FUN_005e1490; vt 0x6c824c; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5d0810.c (see manifest).
extern void* g_vt_6c8268;  // observed vtable 0x6c8268; address hypothesis
// 0x005d0810
void __thiscall FUN_005d0810(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c8268;  // 0x6c8268
    FUN_005e1490(self);
    *(void**)self = g_vt_6c824c;  // 0x6c824c
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005d1880 — scalar-deleting destructor (unverified), Class_6c84c8, vtable 0x6c84c8
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c84c8; call FUN_005cea90; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5d1880.c (see manifest).
extern void* g_vt_6c84c8;  // observed vtable 0x6c84c8; address hypothesis
// 0x005d1880
void __thiscall FUN_005d1880(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c84c8;  // 0x6c84c8
    FUN_005cea90(self);
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // corpus also contains refcount-held member handling (e.g. in_ECX[3]) before return; see corpus file.
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005d2340 — scalar-deleting destructor (unverified), Class_6c85e4, vtable 0x6c85e4
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c85e4; vt 0x6c85d8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5d2340.c (see manifest).
extern void* g_vt_6c85e4;  // observed vtable 0x6c85e4; address hypothesis
extern void* g_vt_6c85d8;  // observed vtable 0x6c85d8; address hypothesis
// 0x005d2340
void __thiscall FUN_005d2340(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c85e4;  // 0x6c85e4
    *(void**)self = g_vt_6c85d8;  // 0x6c85d8
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // corpus also contains refcount-held member handling (e.g. in_ECX[3]) before return; see corpus file.
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005d2780 — scalar-deleting destructor (unverified), Class_6c86b4, vtable 0x6c86b4
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c86b4; free 0x4; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5d2780.c (see manifest).
extern void* g_vt_6c86b4;  // observed vtable 0x6c86b4; address hypothesis
// 0x005d2780
void __thiscall FUN_005d2780(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c86b4;  // 0x6c86b4
    operator_delete__(*(void**)((uint8_t*)self + 0x4));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005d5b60 — scalar-deleting destructor (unverified), Class_6c8798, vtable 0x6c8798
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c8798; call FUN_005db500; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5d5b60.c (see manifest).
extern void* g_vt_6c8798;  // observed vtable 0x6c8798; address hypothesis
// 0x005d5b60
void __thiscall FUN_005d5b60(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c8798;  // 0x6c8798
    FUN_005db500(self);
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005d61a0 — scalar-deleting destructor (unverified), Class_6c88fc, vtable 0x6c88fc
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c88fc; free 0x8; vt 0x6c88ac; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5d61a0.c (see manifest).
extern void* g_vt_6c88fc;  // observed vtable 0x6c88fc; address hypothesis
extern void* g_vt_6c88ac;  // observed vtable 0x6c88ac; address hypothesis
// 0x005d61a0
void __thiscall FUN_005d61a0(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c88fc;  // 0x6c88fc
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    *(void**)self = g_vt_6c88ac;  // 0x6c88ac
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005d61e0 — scalar-deleting destructor (unverified), Class_6c8930, vtable 0x6c8930
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c8930; call FUN_005d6040; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5d61e0.c (see manifest).
extern void* g_vt_6c8930;  // observed vtable 0x6c8930; address hypothesis
// 0x005d61e0
void __thiscall FUN_005d61e0(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c8930;  // 0x6c8930
    FUN_005d6040(self);
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

