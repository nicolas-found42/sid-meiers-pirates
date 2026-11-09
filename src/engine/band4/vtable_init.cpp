// Band4 reconstruction candidate (UNVERIFIED; no cl 13.10.3077).
#include <stddef.h>

extern void* g_vtable_6c2088; // vtable object at 0x006c2088 (contents unknown)

struct VtableInit_b990 {
    void* vptr_00;
    void __thiscall FUN_0054b990(void);
    void __thiscall FUN_005562a0(void); // tail callee (0x005562a0)
};

// 0x0054b990 — install vtable, then terminal call to 0x005562a0.
// Corpus analysis/pseudocode/functions/0x54b990.c
void __thiscall VtableInit_b990::FUN_0054b990(void)
{
    vptr_00 = &g_vtable_6c2088;
    FUN_005562a0();
}
