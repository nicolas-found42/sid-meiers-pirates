// Band5 dtors batch 2/5 — unverified decompiler-derived candidate.
// No cl 13.10.3077. No PASS. See REPORT.md.


#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

extern void __cdecl operator_delete(void* p);
extern void __cdecl operator_delete__(void* p);

extern void __cdecl FUN_005e1490(void* self);
extern void __cdecl FUN_005edba0(void* self);

// ---------------------------------------------------------------------------
// 0x005bde80 — scalar-deleting destructor (unverified), Class_6c6ff8, vtable 0x6c6ff8
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c6ff8; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5bde80.c (see manifest).
extern void* g_vt_6c6ff8;  // observed vtable 0x6c6ff8; address hypothesis
// 0x005bde80
void __thiscall FUN_005bde80(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c6ff8;  // 0x6c6ff8
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005bdec0 — scalar-deleting destructor (unverified), Class_6c704c, vtable 0x6c704c
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c704c; call FUN_005e1490; vt 0x6c6ff8; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5bdec0.c (see manifest).
extern void* g_vt_6c704c;  // observed vtable 0x6c704c; address hypothesis
// 0x005bdec0
void __thiscall FUN_005bdec0(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c704c;  // 0x6c704c
    FUN_005e1490(self);
    *(void**)self = g_vt_6c6ff8;  // 0x6c6ff8
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005bdf20 — scalar-deleting destructor (unverified), Class_6c7014, vtable 0x6c7014
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c7014; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5bdf20.c (see manifest).
extern void* g_vt_6c7014;  // observed vtable 0x6c7014; address hypothesis
// 0x005bdf20
void __thiscall FUN_005bdf20(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c7014;  // 0x6c7014
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005bdf60 — scalar-deleting destructor (unverified), Class_6c7068, vtable 0x6c7068
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c7068; call FUN_005e1490; vt 0x6c7014; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5bdf60.c (see manifest).
extern void* g_vt_6c7068;  // observed vtable 0x6c7068; address hypothesis
// 0x005bdf60
void __thiscall FUN_005bdf60(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c7068;  // 0x6c7068
    FUN_005e1490(self);
    *(void**)self = g_vt_6c7014;  // 0x6c7014
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005bffc0 — scalar-deleting destructor (unverified), Class_6c71c8, vtable 0x6c71c8
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c71c8; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5bffc0.c (see manifest).
extern void* g_vt_6c71c8;  // observed vtable 0x6c71c8; address hypothesis
// 0x005bffc0
void __thiscall FUN_005bffc0(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c71c8;  // 0x6c71c8
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005c0000 — scalar-deleting destructor (unverified), PURE, vtable 0x6c7278
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c7278; call FUN_005e1490; vt 0x6c71c8; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5c0000.c (see manifest).
extern void* g_vt_6c7278;  // observed vtable 0x6c7278; address hypothesis
// 0x005c0000
void __thiscall FUN_005c0000(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c7278;  // 0x6c7278
    FUN_005e1490(self);
    *(void**)self = g_vt_6c71c8;  // 0x6c71c8
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005c0040 — scalar-deleting destructor (unverified), Class_6c71e4, vtable 0x6c71e4
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c71e4; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5c0040.c (see manifest).
extern void* g_vt_6c71e4;  // observed vtable 0x6c71e4; address hypothesis
// 0x005c0040
void __thiscall FUN_005c0040(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c71e4;  // 0x6c71e4
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005c0080 — scalar-deleting destructor (unverified), Class_6c7294, vtable 0x6c7294
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c7294; call FUN_005e1490; vt 0x6c71e4; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5c0080.c (see manifest).
extern void* g_vt_6c7294;  // observed vtable 0x6c7294; address hypothesis
// 0x005c0080
void __thiscall FUN_005c0080(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c7294;  // 0x6c7294
    FUN_005e1490(self);
    *(void**)self = g_vt_6c71e4;  // 0x6c71e4
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005c0100 — scalar-deleting destructor (unverified), Class_6c72b0, vtable 0x6c72b0
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c72b0; call FUN_005e1490; vt 0x6c7200; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5c0100.c (see manifest).
extern void* g_vt_6c72b0;  // observed vtable 0x6c72b0; address hypothesis
extern void* g_vt_6c7200;  // observed vtable 0x6c7200; address hypothesis
// 0x005c0100
void __thiscall FUN_005c0100(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c72b0;  // 0x6c72b0
    FUN_005e1490(self);
    *(void**)self = g_vt_6c7200;  // 0x6c7200
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005c0140 — scalar-deleting destructor (unverified), Class_6c721c, vtable 0x6c721c
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c721c; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5c0140.c (see manifest).
extern void* g_vt_6c721c;  // observed vtable 0x6c721c; address hypothesis
// 0x005c0140
void __thiscall FUN_005c0140(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c721c;  // 0x6c721c
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005c0180 — scalar-deleting destructor (unverified), Class_6c72cc, vtable 0x6c72cc
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c72cc; call FUN_005e1490; vt 0x6c721c; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5c0180.c (see manifest).
extern void* g_vt_6c72cc;  // observed vtable 0x6c72cc; address hypothesis
// 0x005c0180
void __thiscall FUN_005c0180(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c72cc;  // 0x6c72cc
    FUN_005e1490(self);
    *(void**)self = g_vt_6c721c;  // 0x6c721c
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005c01e0 — scalar-deleting destructor (unverified), Class_6c72e8, vtable 0x6c72e8
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c72e8; call FUN_005edba0; vt 0x6c7238; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5c01e0.c (see manifest).
extern void* g_vt_6c72e8;  // observed vtable 0x6c72e8; address hypothesis
extern void* g_vt_6c7238;  // observed vtable 0x6c7238; address hypothesis
// 0x005c01e0
void __thiscall FUN_005c01e0(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c72e8;  // 0x6c72e8
    FUN_005edba0(self);
    *(void**)self = g_vt_6c7238;  // 0x6c7238
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005c7d70 — scalar-deleting destructor (unverified), Class_6c76f4, vtable 0x6c76f4
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c76f4; free 0x4; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5c7d70.c (see manifest).
extern void* g_vt_6c76f4;  // observed vtable 0x6c76f4; address hypothesis
// 0x005c7d70
void __thiscall FUN_005c7d70(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c76f4;  // 0x6c76f4
    operator_delete__(*(void**)((uint8_t*)self + 0x4));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005c7da0 — scalar-deleting destructor (unverified), Class_6c76f8, vtable 0x6c76f8
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c76f8; free 0x4; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5c7da0.c (see manifest).
extern void* g_vt_6c76f8;  // observed vtable 0x6c76f8; address hypothesis
// 0x005c7da0
void __thiscall FUN_005c7da0(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c76f8;  // 0x6c76f8
    operator_delete__(*(void**)((uint8_t*)self + 0x4));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005c8cd0 — scalar-deleting destructor (unverified), Class_6c76fc, vtable 0x6c76fc
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c76fc; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5c8cd0.c (see manifest).
extern void* g_vt_6c76fc;  // observed vtable 0x6c76fc; address hypothesis
// 0x005c8cd0
void __thiscall FUN_005c8cd0(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c76fc;  // 0x6c76fc
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

