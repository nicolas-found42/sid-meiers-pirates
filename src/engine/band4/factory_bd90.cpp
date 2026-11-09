// Band4 reconstruction candidate (UNVERIFIED; no cl 13.10.3077).
// Factory/drop-in constructor. Corpus:
// analysis/pseudocode/functions/0x54bd90.c
//
// Observed layout of the new 0x34-byte object (dwords indexed by 4):
//   [0]  vptr = &PTR_FUN_0070dea4 (vtable at 0x0070dea4)
//   [8]  u16 field + u16 pad (halfword zeroed at both stores)
//   [9]  float 1.0f (0x3f800000)
//   [10] DAT_00727424, [11] DAT_00727428, [12] DAT_0072742c (three globals copied)
//   +0x20..+0x33: five u32 fields copied from (this = in_ECX)+0x20..0x30
// The 0x00727424..c triple is also touched by the collision kernels at
// 0x005859a0 (DAT_00727430/34/38 — different triple), so the owner of this
// object is unresolved; the "what/where" above is the observation, kept exact.
// FUN_00540c50 is called with the new object's vptr-installed state and then
// thunk_FUN_00540cf0(newObj, param_1) applies the caller's override.
#include <stddef.h>

extern const void* g_vtable_70dea4; // vtable at 0x0070dea4
extern unsigned    g_glob_727424, g_glob_727428, g_glob_72742c;

extern void* __cdecl FUN_00533c78(int nbytes);
extern void  __cdecl FUN_00540c50(void); // init helper, args unresolved
extern void  __cdecl FUN_00540cf0(void* obj, void* arg);

struct Object_bd90 {
    const void* vptr_00;
    char        pad_04[28];      // +0x04..+0x1f (only +0x20 dword at [8] observed dword-wise)
    unsigned    f_20;            // +0x20 (also written as u16 pair)
    float       f_24;            // +0x24 (seen as float 0x3f800000 via [9])
    unsigned    g_28, g_2c, g_30; // +0x28..+0x30
};

// 0x0054bd90
void* __thiscall FUN_0054bd90(void* arg)
{
    Object_bd90* obj = (Object_bd90*)FUN_00533c78(0x34);
    if (obj != NULL) {
        FUN_00540c50();
        obj->vptr_00 = &g_vtable_70dea4;
        obj->g_28 = g_glob_727424;
        obj->g_2c = g_glob_727428;
        obj->g_30 = g_glob_72742c;
        obj->f_24 = 1.0f;
        *(unsigned short*)&obj->f_20 = 0; // observed halfword store at +0x20
    }
    extern int g_this_54bd90; // this, for the override tail below
    FUN_00540cf0(obj, arg);
    *(unsigned short*)&obj->f_20 = *(unsigned short*)((char*)&g_this_54bd90 + 0x20);
    obj->f_24 = *(float*)((char*)&g_this_54bd90 + 0x24);
    obj->g_28 = *(unsigned*)((char*)&g_this_54bd90 + 0x28);
    obj->g_2c = *(unsigned*)((char*)&g_this_54bd90 + 0x2c);
    obj->g_30 = *(unsigned*)((char*)&g_this_54bd90 + 0x30);
    return obj;
}
