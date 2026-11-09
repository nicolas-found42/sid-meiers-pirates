// Band5 wave2 source reconstruction — unverified decompiler-derived candidate.
// No cl 13.10.3077. No PASS. See REPORT.md.
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

// ---------------------------------------------------------------------------
// 0x005ae050 — null-inner-guarded indirect call via slot 0x40
// Observed corpus: if (*(int**)(self+0xc)==NULL) return;
//   (**(code**)(**(int**)(self+0xc)+0x40))();
// WARNING jumptable at 0x005ae039 not recovered; treated as call.
// ---------------------------------------------------------------------------
typedef void (__thiscall *FnVt0TblFn0)(void*);
extern void __cdecl FUN_005c9200();
extern int g_dat_728dec;            // observed DAT_00728dec; address hypothesis

// 0x005ae050
void __thiscall FUN_005ae050(void* self)
{
    void* inner = *(void**)((uint8_t*)self + 0xc);
    if (!inner)
        return;
    void** vt = *(void***)inner;
    FnVt0TblFn0 f = (FnVt0TblFn0)vt[0x40 / 4];
    f(inner);
}

// ---------------------------------------------------------------------------
// 0x005c9270 — if DAT_00728dec == 0 call FUN_005c9200
// ---------------------------------------------------------------------------

// 0x005c9270
void __cdecl FUN_005c9270(void)
{
    if (g_dat_728dec == 0)
        FUN_005c9200();
}

// ---------------------------------------------------------------------------
// 0x005cce50 — store vtable pointer PTR_LAB_006c7db8 into *self
// ---------------------------------------------------------------------------
extern void* g_vt_6c7db8;           // observed PTR_LAB_006c7db8; address hypothesis

// 0x005cce50
void __thiscall FUN_005cce50(void* self)
{
    *(void**)self = g_vt_6c7db8;
}

// ---------------------------------------------------------------------------
// 0x005cd3c0 — increment u32 field at self+0x3c
// ---------------------------------------------------------------------------

// 0x005cd3c0
void __thiscall FUN_005cd3c0(void* self)
{
    *(uint32_t*)((uint8_t*)self + 0x3c) += 1;
}

// ---------------------------------------------------------------------------
// 0x005d01f0 — store param byte at self+0x18
// ---------------------------------------------------------------------------

// 0x005d01f0
void __thiscall FUN_005d01f0(void* self, uint8_t v)
{
    *(uint8_t*)((uint8_t*)self + 0x18) = v;
}

// ---------------------------------------------------------------------------
// 0x005da350 — tail sequence: FUN_005bed20 then FUN_005cb3f0
// ---------------------------------------------------------------------------
extern void __cdecl FUN_005bed20();
extern void __cdecl FUN_005cb3f0();

// 0x005da350
void __cdecl FUN_005da350(void)
{
    FUN_005bed20();
    FUN_005cb3f0();
}

// ---------------------------------------------------------------------------
// 0x00594f80 — 4-arg forwarder returning FUN_0059f180 result verbatim
// ---------------------------------------------------------------------------
extern uint8_t __cdecl FUN_0059f180(void*, void*, void*, void*);

// 0x00594f80
uint8_t __cdecl FUN_00594f80(void* p1, void* p2, void* p3, void* p4)
{
    return FUN_0059f180(p1, p2, p3, p4);
}

// ---------------------------------------------------------------------------
// 0x005a03a0 — call FUN_005a19c0, conditionally operator_delete on bit0 flag
// ---------------------------------------------------------------------------
extern void __cdecl FUN_005a19c0(void* self);
extern void __cdecl operator_delete(void*);

// 0x005a03a0
void __thiscall FUN_005a03a0(void* self, uint8_t flags)
{
    FUN_005a19c0(self);
    if (flags & 1)
        operator_delete(self);
}

// ---------------------------------------------------------------------------
// 0x005aa990 — same shape, callee FUN_005a8c00
// ---------------------------------------------------------------------------
extern void __cdecl FUN_005a8c00(void* self);

// 0x005aa990
void __thiscall FUN_005aa990(void* self, uint8_t flags)
{
    FUN_005a8c00(self);
    if (flags & 1)
        operator_delete(self);
}

// ---------------------------------------------------------------------------
// 0x005ac600 — sequence FUN_005ae010(param) then FUN_00545d20()
// ---------------------------------------------------------------------------
extern void __cdecl FUN_005ae010(void*);
extern void __cdecl FUN_00545d20();

// 0x005ac600
void __cdecl FUN_005ac600(void* param)
{
    FUN_005ae010(param);
    FUN_00545d20();
}

// ---------------------------------------------------------------------------
// 0x005ac9c0 — call FUN_005ac850, conditionally operator_delete on bit0 flag
// ---------------------------------------------------------------------------
extern void __cdecl FUN_005ac850(void* self);

// 0x005ac9c0
void __thiscall FUN_005ac9c0(void* self, uint8_t flags)
{
    FUN_005ac850(self);
    if (flags & 1)
        operator_delete(self);
}

// ---------------------------------------------------------------------------
// 0x005adcb0 — FUN_005ae060(p1,p2) then *(p1+0x14)=*(self+0x14)
// Observed ECX=this, param_1 is destination object.
// ---------------------------------------------------------------------------
extern void __cdecl FUN_005ae060(void*, void*);

// 0x005adcb0
void __thiscall FUN_005adcb0(void* self, void* dest, void* p2)
{
    FUN_005ae060(dest, p2);
    *(void**)((uint8_t*)dest + 0x14) = *(void**)((uint8_t*)self + 0x14);
}

// ---------------------------------------------------------------------------
// 0x005ae010 — FUN_00538630(param), then FUN_00545cc0 twice
// ---------------------------------------------------------------------------
extern void __cdecl FUN_00538630(void*);
extern void __cdecl FUN_00545cc0();

// 0x005ae010
void __cdecl FUN_005ae010(void* param)
{
    FUN_00538630(param);
    FUN_00545cc0();
    FUN_00545cc0();
}

// ---------------------------------------------------------------------------
// 0x005ae030 — return 1 if inner null else call inner vfunc at 0x3c
// ---------------------------------------------------------------------------
typedef int (__thiscall *FnVt0TblFnInt)(void*);

// 0x005ae030
int __thiscall FUN_005ae030(void* self)
{
    void* inner = *(void**)((uint8_t*)self + 0xc);
    if (!inner)
        return 1;
    void** vt = *(void***)inner;
    FnVt0TblFnInt f = (FnVt0TblFnInt)vt[0x3c / 4];
    return f(inner);
}

// ---------------------------------------------------------------------------
// 0x005ae0d0 — FUN_00513ce0(param); if inner != null call inner vt[0x28](param)
// ---------------------------------------------------------------------------
extern void __cdecl FUN_00513ce0(void*);

// 0x005ae0d0
void __thiscall FUN_005ae0d0(void* self, void* param)
{
    FUN_00513ce0(param);
    void* inner = *(void**)((uint8_t*)self + 0xc);
    if (inner) {
        void** vt = *(void***)inner;
        typedef void (__thiscall *F)(void*, void*);
        F f = (F)vt[0x28 / 4];
        f(inner, param);
    }
}

// ---------------------------------------------------------------------------
// 0x005ae700 — FUN_00552c80(); self[0x11]=0; self[0x12]=0; *self=PTR_006c5988
// ---------------------------------------------------------------------------
extern void* g_vt_6c5988;           // observed PTR_FUN_006c5988; address hypothesis
extern void __cdecl FUN_00552c80(void* self);

// 0x005ae700
void __thiscall FUN_005ae700(void* self)
{
    FUN_00552c80(self);
    ((void**)self)[0x11] = 0;
    ((void**)self)[0x12] = 0;
    *(void**)self = g_vt_6c5988;
}

// ---------------------------------------------------------------------------
// 0x005ae720 — *self=PTR_006c5988; operator_delete(self[0x11]); FUN_00552d20()
// Order preserved per corpus.
// ---------------------------------------------------------------------------

// 0x005ae720
void __thiscall FUN_005ae720(void* self)
{
    *(void**)self = g_vt_6c5988;
    operator_delete(((void**)self)[0x11]);
    FUN_00552d20();
}

// ---------------------------------------------------------------------------
// 0x005aea60 — virtual call on *self slot 0x6c, then FUN_005340b0(p1,p2)
// ---------------------------------------------------------------------------
extern void __cdecl FUN_005340b0(void*, void*);

// 0x005aea60
void __thiscall FUN_005aea60(void* self, void* p1, void* p2)
{
    void** vt = *(void***)self;
    typedef void (__thiscall *F)(void*);
    F f = (F)vt[0x6c / 4];
    f(self);
    FUN_005340b0(p1, p2);
}

// ---------------------------------------------------------------------------
// 0x005aec90 — *self=PTR_006c5a40; FUN_005edba0(); *self=PTR_LAB_006c5a18
// ---------------------------------------------------------------------------
extern void* g_vt_6c5a40;           // observed PTR_FUN_006c5a40; address hypothesis
extern void* g_vt_6c5a18;           // observed PTR_LAB_006c5a18; address hypothesis
extern void __cdecl FUN_005edba0();

// 0x005aec90
void __thiscall FUN_005aec90(void* self)
{
    *(void**)self = g_vt_6c5a40;
    FUN_005edba0();
    *(void**)self = g_vt_6c5a18;
}

// ---------------------------------------------------------------------------
// 0x005b0ed0 — call FUN_005bbd50, conditionally operator_delete on bit0 flag
// ---------------------------------------------------------------------------
extern void __cdecl FUN_005bbd50(void* self);

// 0x005b0ed0
void __thiscall FUN_005b0ed0(void* self, uint8_t flags)
{
    FUN_005bbd50(self);
    if (flags & 1)
        operator_delete(self);
}
