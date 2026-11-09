// Band5 dtors batch 5/5 — unverified decompiler-derived candidate.
// No cl 13.10.3077. No PASS. See REPORT.md.


#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

extern void __cdecl operator_delete(void* p);
extern void __cdecl operator_delete__(void* p);

extern void __cdecl FUN_005c71a0(void* self);
extern void __cdecl FUN_005d8cd0(void* self);
extern void __cdecl FUN_005dd9a0(void* self);
extern void __cdecl FUN_005e1490(void* self);

// ---------------------------------------------------------------------------
// 0x005d7530 — scalar-deleting destructor (unverified), Class_6c8980, vtable 0x6c8980
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c8980; free 0x30; call FUN_005c71a0; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5d7530.c (see manifest).
extern void* g_vt_6c8980;  // observed vtable 0x6c8980; address hypothesis
// 0x005d7530
void __thiscall FUN_005d7530(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c8980;  // 0x6c8980
    operator_delete__(*(void**)((uint8_t*)self + 0x30));
    FUN_005c71a0(self);
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // corpus also contains refcount-held member handling (e.g. in_ECX[3]) before return; see corpus file.
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005d86a0 — scalar-deleting destructor (unverified), E_OUTOFMEMORY, vtable 0x6c8c28
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c8c28; free 0x4; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5d86a0.c (see manifest).
extern void* g_vt_6c8c28;  // observed vtable 0x6c8c28; address hypothesis
// 0x005d86a0
void __thiscall FUN_005d86a0(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c8c28;  // 0x6c8c28
    operator_delete__(*(void**)((uint8_t*)self + 0x4));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005d86d0 — scalar-deleting destructor (unverified), Class_6c8c2c, vtable 0x6c8c2c
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c8c2c; free 0x4; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5d86d0.c (see manifest).
extern void* g_vt_6c8c2c;  // observed vtable 0x6c8c2c; address hypothesis
// 0x005d86d0
void __thiscall FUN_005d86d0(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c8c2c;  // 0x6c8c2c
    operator_delete__(*(void**)((uint8_t*)self + 0x4));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005d8c50 — scalar-deleting destructor (unverified), Class_6c8c30, vtable 0x6c8c30
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c8c30; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5d8c50.c (see manifest).
extern void* g_vt_6c8c30;  // observed vtable 0x6c8c30; address hypothesis
// 0x005d8c50
void __thiscall FUN_005d8c50(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c8c30;  // 0x6c8c30
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005d8c90 — scalar-deleting destructor (unverified), Class_6c8c4c, vtable 0x6c8c4c
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c8c4c; call FUN_005e1490; vt 0x6c8c30; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5d8c90.c (see manifest).
extern void* g_vt_6c8c4c;  // observed vtable 0x6c8c4c; address hypothesis
// 0x005d8c90
void __thiscall FUN_005d8c90(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c8c4c;  // 0x6c8c4c
    FUN_005e1490(self);
    *(void**)self = g_vt_6c8c30;  // 0x6c8c30
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005d8fb0 — scalar-deleting destructor (unverified), Class_6c8c68, vtable 0x6c8c68
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c8c68; call FUN_005d8cd0; call FUN_005e1490; call FUN_005e1490; free 0x18; call FUN_005dd9a0; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5d8fb0.c (see manifest).
extern void* g_vt_6c8c68;  // observed vtable 0x6c8c68; address hypothesis
// 0x005d8fb0
void __thiscall FUN_005d8fb0(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c8c68;  // 0x6c8c68
    FUN_005d8cd0(self);
    FUN_005e1490(self);
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x18));
    FUN_005dd9a0(self);
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005d9190 — scalar-deleting destructor (unverified), Class_6c8c98, vtable 0x6c8c98
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c8c98; call FUN_005dd9a0; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5d9190.c (see manifest).
extern void* g_vt_6c8c98;  // observed vtable 0x6c8c98; address hypothesis
// 0x005d9190
void __thiscall FUN_005d9190(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c8c98;  // 0x6c8c98
    FUN_005dd9a0(self);
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005d9590 — scalar-deleting destructor (unverified), Class_6c8cc8, vtable 0x6c8cc8
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c8cc8; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5d9590.c (see manifest).
extern void* g_vt_6c8cc8;  // observed vtable 0x6c8cc8; address hypothesis
// 0x005d9590
void __thiscall FUN_005d9590(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c8cc8;  // 0x6c8cc8
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005d95d0 — scalar-deleting destructor (unverified), Class_6c8d04, vtable 0x6c8d04
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c8d04; call FUN_005e1490; vt 0x6c8cc8; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5d95d0.c (see manifest).
extern void* g_vt_6c8d04;  // observed vtable 0x6c8d04; address hypothesis
// 0x005d95d0
void __thiscall FUN_005d95d0(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c8d04;  // 0x6c8d04
    FUN_005e1490(self);
    *(void**)self = g_vt_6c8cc8;  // 0x6c8cc8
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005d9610 — scalar-deleting destructor (unverified), Class_6c8ce4, vtable 0x6c8ce4
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c8ce4; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5d9610.c (see manifest).
extern void* g_vt_6c8ce4;  // observed vtable 0x6c8ce4; address hypothesis
// 0x005d9610
void __thiscall FUN_005d9610(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c8ce4;  // 0x6c8ce4
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005d9650 — scalar-deleting destructor (unverified), Class_6c8d20, vtable 0x6c8d20
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c8d20; call FUN_005e1490; vt 0x6c8ce4; call FUN_005e1490; free 0x8; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5d9650.c (see manifest).
extern void* g_vt_6c8d20;  // observed vtable 0x6c8d20; address hypothesis
// 0x005d9650
void __thiscall FUN_005d9650(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c8d20;  // 0x6c8d20
    FUN_005e1490(self);
    *(void**)self = g_vt_6c8ce4;  // 0x6c8ce4
    FUN_005e1490(self);
    operator_delete__(*(void**)((uint8_t*)self + 0x8));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

// ---------------------------------------------------------------------------
// 0x005d9690 — scalar-deleting destructor (unverified), Class_6c8d00, vtable 0x6c8d00
// Observed: *self = vtable; body call(s); operator_delete__ on member slot(s);
//   if ((flags & 1) != 0) operator_delete(self); plain RET 0x4 (__thiscall, void return).
//   Pattern: vt 0x6c8d00; free 0x4; flags&1 test; flagged operator_delete(self).
// Corpus: analysis/pseudocode/functions/5d9690.c (see manifest).
extern void* g_vt_6c8d00;  // observed vtable 0x6c8d00; address hypothesis
// 0x005d9690
void __thiscall FUN_005d9690(void* self, uint8_t flags)
{
    *(void**)self = g_vt_6c8d00;  // 0x6c8d00
    operator_delete__(*(void**)((uint8_t*)self + 0x4));
    if ((flags & 1) != 0) {
        operator_delete(self);
    }
    // return; // RET 0x4 observed; no return value. No operator_delete definition here.
}

