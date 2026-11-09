// Band7 wave3 source reconstruction — unverified decompiler-derived candidates.
// No cl 13.10.3077. No PASS. See REPORT.md.
#include <stdint.h>

// ---------------------------------------------------------------------------
// 0x0063ef52 — return ~(*(uint16*)(param_1+0x42) * 0xb4 + *(int*)(param_1+0xa4))
// Observed corpus: return ~((uint)*(ushort *)(p+0x42) * 0xb4 + *(int *)(p+0xa4));
// ---------------------------------------------------------------------------

// 0x0063ef52
uint32_t FUN_0063ef52(int param_1)
{
    uint8_t* base = (uint8_t*)param_1;
    uint32_t lo = *(uint16_t*)(base + 0x42);
    int32_t hi = *(int32_t*)(base + 0xa4);
    return ~((uint32_t)lo * 0xb4 + (uint32_t)hi);
}

// ---------------------------------------------------------------------------
// 0x00629ca0 — forward (&param_1,&param_2,&param_3) to FUN_00629bb0
// Observed corpus: FUN_00629bb0(&param_1,&param_2,&param_3);
// ---------------------------------------------------------------------------
extern void FUN_00629bb0(void* p1, void* p2, void* p3);

// 0x00629ca0
void FUN_00629ca0(uint8_t param_1, uint8_t param_2, uint8_t param_3)
{
    FUN_00629bb0(&param_1, &param_2, &param_3);
}

// ---------------------------------------------------------------------------
// 0x00629dca — forward (&param_1,&param_2,&param_3) to FUN_00629cba
// Observed corpus: FUN_00629cba(&param_1,&param_2,&param_3);
// ---------------------------------------------------------------------------
extern void FUN_00629cba(void* p1, void* p2, void* p3);

// 0x00629dca
void FUN_00629dca(uint8_t param_1, uint8_t param_2, uint8_t param_3)
{
    FUN_00629cba(&param_1, &param_2, &param_3);
}

// ---------------------------------------------------------------------------
// 0x0062e228 — forward (&param_1,&param_2,&param_3,param_4) to FUN_0062dfd6
// Observed corpus: FUN_0062dfd6(&p1,&p2,&p3,param_4);
// ---------------------------------------------------------------------------
extern void FUN_0062dfd6(void* p1, void* p2, void* p3, uint32_t param_4);

// 0x0062e228
void FUN_0062e228(uint8_t param_1, uint8_t param_2, uint8_t param_3, uint32_t param_4)
{
    FUN_0062dfd6(&param_1, &param_2, &param_3, param_4);
}

// ---------------------------------------------------------------------------
// 0x0062e401 — forward (&param_1,&param_2,&param_3,param_4) to FUN_0062e245
// Observed corpus: FUN_0062e245(&p1,&p2,&p3,param_4);
// ---------------------------------------------------------------------------
extern void FUN_0062e245(void* p1, void* p2, void* p3, uint32_t param_4);

// 0x0062e401
void FUN_0062e401(uint8_t param_1, uint8_t param_2, uint8_t param_3, uint32_t param_4)
{
    FUN_0062e245(&param_1, &param_2, &param_3, param_4);
}
// ---------------------------------------------------------------------------
// 0x00641286 — indirect call via inner vtable slot +0x0c
// Observed corpus: (**(param+0x0c) + 0x0c)(*(param+0x0c), param_2, param_3).
// ---------------------------------------------------------------------------
typedef void (__cdecl *Fn02)(void*, uint32_t, uint32_t);

// 0x00641286
void FUN_00641286(uint8_t* param_1, uint32_t param_2, uint32_t param_3)
{
    void* inner = *(void**)(param_1 + 0x0c);
    void** vt = *(void***)inner;
    ((Fn02)vt[0x0c / 4])(inner, param_2, param_3);
}

// ---------------------------------------------------------------------------
// 0x006412b9 — indirect call via inner vtable slot +0x14
// Observed corpus: (**(param+0x0c) + 0x14)(*(param+0x0c), param_2, param_3).
// ---------------------------------------------------------------------------

// 0x006412b9
void FUN_006412b9(uint8_t* param_1, uint32_t param_2, uint32_t param_3)
{
    void* inner = *(void**)(param_1 + 0x0c);
    void** vt = *(void***)inner;
    ((Fn02)vt[0x14 / 4])(inner, param_2, param_3);
}

// ---------------------------------------------------------------------------
// 0x006412d4 — indirect call via inner vtable slot +0x18
// Observed corpus: (**(param+0x0c) + 0x18)(*(param+0x0c), param_2, param_3).
// ---------------------------------------------------------------------------

// 0x006412d4
void FUN_006412d4(uint8_t* param_1, uint32_t param_2, uint32_t param_3)
{
    void* inner = *(void**)(param_1 + 0x0c);
    void** vt = *(void***)inner;
    ((Fn02)vt[0x18 / 4])(inner, param_2, param_3);
}

// ---------------------------------------------------------------------------
// 0x006412ef — indirect call via inner vtable slot +0x1c
// Observed corpus: (**(param+0x0c) + 0x1c)(*(param+0x0c), param_2, param_3).
// ---------------------------------------------------------------------------

// 0x006412ef
void FUN_006412ef(uint8_t* param_1, uint32_t param_2, uint32_t param_3)
{
    void* inner = *(void**)(param_1 + 0x0c);
    void** vt = *(void***)inner;
    ((Fn02)vt[0x1c / 4])(inner, param_2, param_3);
}

// ---------------------------------------------------------------------------
// 0x0064130a — indirect call via inner vtable slot +0x20
// Observed corpus: (**(param+0x0c) + 0x20)(*(param+0x0c), param_2, param_3).
// ---------------------------------------------------------------------------

// 0x0064130a
void FUN_0064130a(uint8_t* param_1, uint32_t param_2, uint32_t param_3)
{
    void* inner = *(void**)(param_1 + 0x0c);
    void** vt = *(void***)inner;
    ((Fn02)vt[0x20 / 4])(inner, param_2, param_3);
}
// ---------------------------------------------------------------------------
// 0x00641325 — indirect call via inner vtable slot +0x24
// Observed corpus: (**(param+0x0c) + 0x24)(*(param+0x0c), param_2, param_3, param_4).
// ---------------------------------------------------------------------------
typedef void (__cdecl *Fn03)(void*, uint32_t, uint32_t, uint32_t);

// 0x00641325
void FUN_00641325(uint8_t* param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    void* inner = *(void**)(param_1 + 0x0c);
    void** vt = *(void***)inner;
    ((Fn03)vt[0x24 / 4])(inner, param_2, param_3, param_4);
}

// ---------------------------------------------------------------------------
// 0x00641343 — indirect call via inner vtable slot +0x28
// Observed corpus: (**(param+0x0c) + 0x28)(*(param+0x0c), param_2, param_3, param_4).
// ---------------------------------------------------------------------------

// 0x00641343
void FUN_00641343(uint8_t* param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    void* inner = *(void**)(param_1 + 0x0c);
    void** vt = *(void***)inner;
    ((Fn03)vt[0x28 / 4])(inner, param_2, param_3, param_4);
}

// ---------------------------------------------------------------------------
// 0x00641361 — indirect call via inner vtable slot +0x2c
// Observed corpus: (**(param+0x0c) + 0x2c)(*(param+0x0c), param_2).
// ---------------------------------------------------------------------------
typedef void (__cdecl *Fn01)(void*, uint32_t);

// 0x00641361
void FUN_00641361(uint8_t* param_1, uint32_t param_2)
{
    void* inner = *(void**)(param_1 + 0x0c);
    void** vt = *(void***)inner;
    ((Fn01)vt[0x2c / 4])(inner, param_2);
}

// ---------------------------------------------------------------------------
// 0x006413c5 — indirect call via inner vtable slot +0x38
// Observed corpus: (**(param+0x0c) + 0x38)(*(param+0x0c), param_2, param_3, param_4).
// ---------------------------------------------------------------------------

// 0x006413c5
void FUN_006413c5(uint8_t* param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    void* inner = *(void**)(param_1 + 0x0c);
    void** vt = *(void***)inner;
    ((Fn03)vt[0x38 / 4])(inner, param_2, param_3, param_4);
}

// ---------------------------------------------------------------------------
// 0x006413e3 — indirect call via inner vtable slot +0x3c
// Observed corpus: (**(param+0x0c) + 0x3c)(*(param+0x0c), param_2, param_3, param_4).
// ---------------------------------------------------------------------------

// 0x006413e3
void FUN_006413e3(uint8_t* param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    void* inner = *(void**)(param_1 + 0x0c);
    void** vt = *(void***)inner;
    ((Fn03)vt[0x3c / 4])(inner, param_2, param_3, param_4);
}
// ---------------------------------------------------------------------------
// 0x0064144c — indirect call via inner vtable slot +0x48
// Observed corpus: (**(param+0x0c) + 0x48)(*(param+0x0c), param_2, param_3, param_4).
// ---------------------------------------------------------------------------

// 0x0064144c
void FUN_0064144c(uint8_t* param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    void* inner = *(void**)(param_1 + 0x0c);
    void** vt = *(void***)inner;
    ((Fn03)vt[0x48 / 4])(inner, param_2, param_3, param_4);
}

// ---------------------------------------------------------------------------
// 0x0064146a — indirect call via inner vtable slot +0x4c
// Observed corpus: (**(param+0x0c) + 0x4c)(*(param+0x0c), param_2, param_3, param_4).
// ---------------------------------------------------------------------------

// 0x0064146a
void FUN_0064146a(uint8_t* param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    void* inner = *(void**)(param_1 + 0x0c);
    void** vt = *(void***)inner;
    ((Fn03)vt[0x4c / 4])(inner, param_2, param_3, param_4);
}

// ---------------------------------------------------------------------------
// 0x00641488 — indirect call via inner vtable slot +0x50
// Observed corpus: (**(param+0x0c) + 0x50)(*(param+0x0c), param_2, param_3, param_4).
// ---------------------------------------------------------------------------

// 0x00641488
void FUN_00641488(uint8_t* param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    void* inner = *(void**)(param_1 + 0x0c);
    void** vt = *(void***)inner;
    ((Fn03)vt[0x50 / 4])(inner, param_2, param_3, param_4);
}

// ---------------------------------------------------------------------------
// 0x0064487e — forward (param_2, param_3, 0) to FUN_0063ed81
// Observed corpus: FUN_0063ed81(param_2,param_3,0); param_1 unused.
// ---------------------------------------------------------------------------
extern void FUN_0063ed81(uint32_t param_2, uint32_t param_3, uint32_t param_4);

// 0x0064487e
void FUN_0064487e(uint32_t param_1, uint32_t param_2, uint32_t param_3)
{
    FUN_0063ed81(param_2, param_3, 0);
}

// ---------------------------------------------------------------------------
// 0x0064ea67 — forward (param_2, param_3, 0) to FUN_0064d495
// Observed corpus: FUN_0064d495(param_2,param_3,0); param_1 unused.
// ---------------------------------------------------------------------------
extern void FUN_0064d495(uint32_t param_2, uint32_t param_3, uint32_t param_4);

// 0x0064ea67
void FUN_0064ea67(uint32_t param_1, uint32_t param_2, uint32_t param_3)
{
    FUN_0064d495(param_2, param_3, 0);
}
