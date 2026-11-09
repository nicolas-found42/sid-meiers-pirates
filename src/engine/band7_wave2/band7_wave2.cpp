// Band7 wave2 source reconstruction — unverified decompiler-derived candidates.
// No cl 13.10.3077. No PASS. See REPORT.md.
#include <stdint.h>

// ---------------------------------------------------------------------------
// 0x006338c7 — empty function, immediate return
// Observed corpus: body is just `return;` (span 1).
// ---------------------------------------------------------------------------

// 0x006338c7
void FUN_006338c7(void)
{
    return;
}

// ---------------------------------------------------------------------------
// 0x006321e1 — zero u32 fields at self+0x04..+0x14 (thiscall, ECX)
// Observed corpus: *(self+0x04)=0; +0x08=0; +0x0c=0; +0x10=0; +0x14=0.
// ---------------------------------------------------------------------------

// 0x006321e1
void __thiscall FUN_006321e1(void* self)
{
    *(uint32_t*)((uint8_t*)self + 0x04) = 0;
    *(uint32_t*)((uint8_t*)self + 0x08) = 0;
    *(uint32_t*)((uint8_t*)self + 0x0c) = 0;
    *(uint32_t*)((uint8_t*)self + 0x10) = 0;
    *(uint32_t*)((uint8_t*)self + 0x14) = 0;
}

// ---------------------------------------------------------------------------
// 0x0065676f — zero 0x10 u32 words at param_2
// Observed corpus: for (i=0x10; i!=0; i--) *param_2++ = 0;
// param_1 unused in body.
// ---------------------------------------------------------------------------

// 0x0065676f
void FUN_0065676f(uint32_t param_1, uint32_t* param_2)
{
    for (int i = 0x10; i != 0; --i) {
        *param_2 = 0;
        ++param_2;
    }
}
// ---------------------------------------------------------------------------
// 0x0062952f — link-list init at self+0x0c..0x20 (thiscall, ECX)
// Observed corpus: pu=self+0x0c; *(self+0x14)=0; *pu=0;
// *(self+0x1c)=pu; *(self+0x18)=pu; *(self+0x20)=0.
// ---------------------------------------------------------------------------

// 0x0062952f
void __thiscall FUN_0062952f(void* self)
{
    uint32_t* pu = (uint32_t*)((uint8_t*)self + 0x0c);
    *(uint32_t*)((uint8_t*)self + 0x14) = 0;
    *pu = 0;
    *(uint32_t**)((uint8_t*)self + 0x1c) = pu;
    *(uint32_t**)((uint8_t*)self + 0x18) = pu;
    *(uint32_t*)((uint8_t*)self + 0x20) = 0;
}

// ---------------------------------------------------------------------------
// 0x006564c0 — zero fields at (*param_1)+0x6c and +0x14
// Observed corpus: i=*param_1; *(i+0x6c)=0; *(i+0x14)=0.
// ---------------------------------------------------------------------------

// 0x006564c0
void FUN_006564c0(int* param_1)
{
    int base = *param_1;
    *(uint32_t*)((uint8_t*)base + 0x6c) = 0;
    *(uint32_t*)((uint8_t*)base + 0x14) = 0;
}

// ---------------------------------------------------------------------------
// 0x0065ac33 — call FUN_0065ab96(1), set vtable, clear +0x10, return self
// Observed corpus: FUN_0065ab96(1); p[4]=0; *p=&PTR_FUN_006edfdc; return p.
// p arrives in EDX (extraout_EDX) — convention unverified.
// ---------------------------------------------------------------------------
extern void FUN_0065ab96(uint32_t param_1);
extern void* g_ptr_FUN_006edfdc; // observed PTR_FUN_006edfdc; address hypothesis

// 0x0065ac33
uint32_t* FUN_0065ac33(uint32_t* self)
{
    FUN_0065ab96(1);
    self[4] = 0;
    self[0] = (uint32_t)(uintptr_t)g_ptr_FUN_006edfdc;
    return self;
}

// ---------------------------------------------------------------------------
// 0x0065c3ac — store two params at self[0..1] (thiscall, ECX)
// Observed corpus: *in_ECX=param_1; in_ECX[1]=param_2.
// ---------------------------------------------------------------------------

// 0x0065c3ac
void __thiscall FUN_0065c3ac(void* self, uint32_t param_1, uint32_t param_2)
{
    uint32_t* p = (uint32_t*)self;
    p[0] = param_1;
    p[1] = param_2;
}

// ---------------------------------------------------------------------------
// 0x006417d1 — init self[0]=3, [3..6]=0 (thiscall, ECX)
// Observed corpus order: [0]=3; [4]=0; [5]=0; [3]=0; [6]=0.
// ---------------------------------------------------------------------------

// 0x006417d1
void __thiscall FUN_006417d1(void* self)
{
    uint32_t* p = (uint32_t*)self;
    p[0] = 3;
    p[4] = 0;
    p[5] = 0;
    p[3] = 0;
    p[6] = 0;
}

// ---------------------------------------------------------------------------
// 0x00644faa — forward second param to FUN_0064121f
// Observed corpus: FUN_0064121f(param_2); param_1 unused.
// ---------------------------------------------------------------------------
extern void FUN_0064121f(uint32_t param_2);

// 0x00644faa
void FUN_00644faa(uint32_t param_1, uint32_t param_2)
{
    FUN_0064121f(param_2);
}

// ---------------------------------------------------------------------------
// 0x0062947f — vtable init: [0]=PTR_FUN_006e1934, [1]=1, [2]=0, [3]=0
// Observed corpus order: [3]=0; [2]=0; [0]=vt; [1]=1.
// ---------------------------------------------------------------------------
extern void* g_ptr_FUN_006e1934; // observed PTR_FUN_006e1934; address hypothesis

// 0x0062947f
void __thiscall FUN_0062947f(void* self)
{
    uint32_t* p = (uint32_t*)self;
    p[3] = 0;
    p[2] = 0;
    p[0] = (uint32_t)(uintptr_t)g_ptr_FUN_006e1934;
    p[1] = 1;
}

// ---------------------------------------------------------------------------
// 0x006412a1 — indirect call via inner vtable slot +0x10
// Observed corpus: (**(param+0x0c) + 0x10)(*(param+0x0c), param_2).
// ---------------------------------------------------------------------------
typedef void (__cdecl *Fn00)(void*, uint32_t);

// 0x006412a1
void FUN_006412a1(uint8_t* param_1, uint32_t param_2)
{
    void* inner = *(void**)(param_1 + 0x0c);
    void** vt = *(void***)inner;
    ((Fn00)vt[0x10 / 4])(inner, param_2);
}
// ---------------------------------------------------------------------------
// 0x0064137d — indirect call via inner vtable slot +0x30
// Observed corpus: (**(param+0x0c) + 0x30)(*(param+0x0c), param_2).
// ---------------------------------------------------------------------------

// 0x0064137d
void FUN_0064137d(uint8_t* param_1, uint32_t param_2)
{
    void* inner = *(void**)(param_1 + 0x0c);
    void** vt = *(void***)inner;
    ((Fn00)vt[0x30 / 4])(inner, param_2);
}

// ---------------------------------------------------------------------------
// 0x00641395 — indirect call via inner vtable slot +0x34
// Observed corpus: (**(param+0x0c) + 0x34)(*(param+0x0c), param_2).
// ---------------------------------------------------------------------------

// 0x00641395
void FUN_00641395(uint8_t* param_1, uint32_t param_2)
{
    void* inner = *(void**)(param_1 + 0x0c);
    void** vt = *(void***)inner;
    ((Fn00)vt[0x34 / 4])(inner, param_2);
}

// ---------------------------------------------------------------------------
// 0x006413ad — indirect call via inner vtable slot +0x44
// Observed corpus: (**(param+0x0c) + 0x44)(*(param+0x0c), param_2).
// ---------------------------------------------------------------------------

// 0x006413ad
void FUN_006413ad(uint8_t* param_1, uint32_t param_2)
{
    void* inner = *(void**)(param_1 + 0x0c);
    void** vt = *(void***)inner;
    ((Fn00)vt[0x44 / 4])(inner, param_2);
}

// ---------------------------------------------------------------------------
// 0x0065d07f — DAT_0072be28=0; DAT_0072be2c=param_1
// ---------------------------------------------------------------------------
extern uint32_t g_dat_72be28; // observed DAT_0072be28; address hypothesis
extern uint32_t g_dat_72be2c; // observed DAT_0072be2c; address hypothesis

// 0x0065d07f
void FUN_0065d07f(uint32_t param_1)
{
    g_dat_72be28 = 0;
    g_dat_72be2c = param_1;
}

// ---------------------------------------------------------------------------
// 0x0065d5fa — DAT_0072be30=0; DAT_0072be34=param_1
// ---------------------------------------------------------------------------
extern uint32_t g_dat_72be30; // observed DAT_0072be30; address hypothesis
extern uint32_t g_dat_72be34; // observed DAT_0072be34; address hypothesis

// 0x0065d5fa
void FUN_0065d5fa(uint32_t param_1)
{
    g_dat_72be30 = 0;
    g_dat_72be34 = param_1;
}

// ---------------------------------------------------------------------------
// 0x0062a46a — *self=param_1; FUN_0060d291()
// Observed corpus: *in_ECX=param_1; FUN_0060d291();
// ---------------------------------------------------------------------------
extern void FUN_0060d291(void);

// 0x0062a46a
void __thiscall FUN_0062a46a(void* self, uint32_t param_1)
{
    *(uint32_t*)self = param_1;
    FUN_0060d291();
}

// ---------------------------------------------------------------------------
// 0x0062a5d2 — zero init with self-link at [4] (thiscall, ECX)
// Observed corpus order: [3]=0; [2]=0; [4]=self; [5]=0; [1]=0; [0]=0; [6]=0.
// ---------------------------------------------------------------------------

// 0x0062a5d2
void __thiscall FUN_0062a5d2(void* self)
{
    uint32_t* p = (uint32_t*)self;
    p[3] = 0;
    p[2] = 0;
    p[4] = (uint32_t)(uintptr_t)self;
    p[5] = 0;
    p[1] = 0;
    p[0] = 0;
    p[6] = 0;
}

// ---------------------------------------------------------------------------
// 0x0062ee93 — forward (param_2, param_3, 0) to FUN_0062d2ee
// Observed corpus: FUN_0062d2ee(param_2,param_3,0); param_1 unused.
// ---------------------------------------------------------------------------
extern void FUN_0062d2ee(uint32_t param_2, uint32_t param_3, uint32_t param_4);

// 0x0062ee93
void FUN_0062ee93(uint32_t param_1, uint32_t param_2, uint32_t param_3)
{
    FUN_0062d2ee(param_2, param_3, 0);
}

// ---------------------------------------------------------------------------
// 0x0062f5d8 — forward (param_2, param_3, 0) to FUN_0062eccf
// Observed corpus: FUN_0062eccf(param_2,param_3,0); param_1 unused.
// ---------------------------------------------------------------------------
extern void FUN_0062eccf(uint32_t param_2, uint32_t param_3, uint32_t param_4);

// 0x0062f5d8
void FUN_0062f5d8(uint32_t param_1, uint32_t param_2, uint32_t param_3)
{
    FUN_0062eccf(param_2, param_3, 0);
}
