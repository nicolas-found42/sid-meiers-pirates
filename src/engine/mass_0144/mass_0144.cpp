#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <cmath>

// ---------------------------------------------------------------------------
// Reconstruction batch mass_0144.
// Register receivers (in_ECX) are modeled as an explicit first parameter
// (`self`); Ghidra's thiscall receiver is not a source-level `this`.
// ---------------------------------------------------------------------------
// External helpers and globals observed in the supplied corpus listings.
// ---------------------------------------------------------------------------
extern void* thunk_FUN_00533c78(size_t size);
extern void  operator_delete(void* ptr);

extern uint32_t DAT_00727c44;
extern uint32_t DAT_007179b0[9];
extern uint8_t  DAT_007177ac;
extern uint8_t  PTR_FUN_006c25d0;

extern void     FUN_005517c0(int param_1);
extern int      FUN_00557b10(uint32_t param_1);
extern void     FUN_006b34a0(int param_1);
extern void     FUN_005606f0(uint32_t param_1, int* param_2);
extern void     FUN_00535880(void);
extern void     FUN_00558080(uint8_t* param_1, int param_2);
extern void     FUN_004db0a0(void);
extern void     FUN_00535750(uint32_t param_1);
extern void*    FUN_00545600(void);
extern void     FUN_00551110(void);
extern void     FUN_00535600(void);
extern void     FUN_00535300(int param_1, uint32_t param_2);
extern void     FUN_00538410(int* param_1, uint32_t param_2);
extern char     FUN_005bd960(int param_1, int** param_2);
extern void     FUN_00513ce0(uint32_t param_1);
extern char     FUN_00538360(uint32_t param_1);
extern uint32_t FUN_00538460(int param_1);

extern int    FUN_0053cc20(void* param_1);
extern void*  FUN_0053c8d0(void* param_1, uint32_t param_2);
extern void*  FUN_0053c9e0(void* param_1, float param_2);
extern float* FUN_0053ca60(void* param_1, void* param_2);

// 0x551a00 — observed shape
// Forwards self to FUN_005517c0, resolves DAT_00727c44 through FUN_00557b10,
// then reads the index at self+0xc and, when it exceeds the count at self+8,
// flushes the backing store at self+0x14 with FUN_006b34a0. Finishes by
// handing the index and the resolved value to FUN_005606f0.
void FUN_00551a00(int param_1)
{
    int iVar2 = param_1;
    int resolved;
    uint32_t uVar1;

    FUN_005517c0(param_1);
    resolved = FUN_00557b10(DAT_00727c44);
    uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
    if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int*>(iVar2 + 0x14) + static_cast<int>(uVar1));
    }
    FUN_005606f0(uVar1, &resolved);
}

// 0x551a50 — observed shape
// Invokes vtable slot +0x8 of the object found at param_1+0x15c twice: the
// first call bare, the second with (self+4, 4).
void FUN_00551a50(int self, int param_1)
{
    void* holder = *reinterpret_cast<void**>(param_1 + 0x15c);
    void** vtbl = *reinterpret_cast<void***>(holder);

    (*reinterpret_cast<void(**)()>(vtbl[0x8 / 4]))();
    reinterpret_cast<void (*)(void*, int)>(vtbl[0x8 / 4])(
        reinterpret_cast<void*>(self + 4), 4);
}

// 0x551a80 — observed shape
// Same shape as FUN_00551a50 against the object at param_1+0x160 and vtable
// slot +0xc: a bare call followed by (self+4, 4).
void FUN_00551a80(int self, int param_1)
{
    void* holder = *reinterpret_cast<void**>(param_1 + 0x160);
    void** vtbl = *reinterpret_cast<void***>(holder);

    (*reinterpret_cast<void(**)()>(vtbl[0xc / 4]))();
    reinterpret_cast<void (*)(void*, int)>(vtbl[0xc / 4])(
        reinterpret_cast<void*>(self + 4), 4);
}

// 0x551ab0 — observed shape
// Measures the NUL-terminated name in param_1, allocates a 0x19-byte
// extension past its terminator, and formats the projected-light mode word
// (PROJECTED_LIGHT / PROJECTED_SHADOW / ENVIRONMENT_MAP / FOG_MAP) into the
// tail. Case 3 falls through the switch; the tail pointer is returned.
char* FUN_00551ab0(char* param_1, uint32_t param_2)
{
    char cVar1;
    char* pcVar2 = param_1;

    do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = static_cast<char*>(thunk_FUN_00533c78(
        static_cast<size_t>(reinterpret_cast<intptr_t>(pcVar2) +
                            (0x19 - (reinterpret_cast<intptr_t>(param_1) + 1)))));
    switch (param_2) {
    case 0:
        sprintf(pcVar2, "%s = PROJECTED_LIGHT", param_1);
        return pcVar2;
    case 1:
        sprintf(pcVar2, "%s = PROJECTED_SHADOW", param_1);
        return pcVar2;
    case 2:
        sprintf(pcVar2, "%s = ENVIRONMENT_MAP", param_1);
        return pcVar2;
    case 3:
        sprintf(pcVar2, "%s = FOG_MAP", param_1);
    }
    return pcVar2;
}

// 0x551b50 — observed shape
// Measures the NUL-terminated name in param_1, allocates a 0x19-byte
// extension past its terminator, and formats the texture-coordinate mode
// word (WORLD_PARALLEL / WORLD_PERSPECTIVE / SPHERE_MAP /
// SPECULAR_CUBE_MAP / DIFFUSE_CUBE_MAP) into the tail. Case 4 falls through.
char* FUN_00551b50(char* param_1, uint32_t param_2)
{
    char cVar1;
    char* pcVar2 = param_1;

    do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = static_cast<char*>(thunk_FUN_00533c78(
        static_cast<size_t>(reinterpret_cast<intptr_t>(pcVar2) +
                            (0x19 - (reinterpret_cast<intptr_t>(param_1) + 1)))));
    switch (param_2) {
    case 0:
        sprintf(pcVar2, "%s = WORLD_PARALLEL", param_1);
        return pcVar2;
    case 1:
        sprintf(pcVar2, "%s = WORLD_PERSPECTIVE", param_1);
        return pcVar2;
    case 2:
        sprintf(pcVar2, "%s = SPHERE_MAP", param_1);
        return pcVar2;
    case 3:
        sprintf(pcVar2, "%s = SPECULAR_CUBE_MAP", param_1);
        return pcVar2;
    case 4:
        sprintf(pcVar2, "%s = DIFFUSE_CUBE_MAP", param_1);
    }
    return pcVar2;
}

// 0x551c10 — observed shape
// Constructor: runs the base constructor FUN_00535880, installs the vtable
// PTR_FUN_006c25d0, copies the 9-dword block DAT_007179b0 into the two
// matrices at word indices 0x39 and 0x45, zeroes the scalar fields around
// them, resets the two DAT_007177ac-state objects, and seeds the trailing
// flags (word 0x53 = 3, halfword at +0x17e = 0xffb5).
void FUN_00551c10(void* self)
{
    uint32_t* w = static_cast<uint32_t*>(self);
    uint8_t* const base = static_cast<uint8_t*>(self);
    uint32_t* puVar2;
    uint32_t* puVar3;
    int iVar1;

    FUN_00535880();
    *w = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c25d0));
    puVar2 = DAT_007179b0;
    puVar3 = w + 0x39;
    for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
    }
    w[0x42] = 0;
    w[0x43] = 0;
    w[0x44] = 0;
    puVar2 = DAT_007179b0;
    puVar3 = w + 0x45;
    for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
    }
    w[0x4e] = 0;
    w[0x4f] = 0;
    w[0x50] = 0;
    w[0x51] = 0;
    FUN_00558080(&DAT_007177ac, 0);
    FUN_00558080(&DAT_007177ac, 0);
    w[0x52] = 0;
    w[0x54] = 0;
    w[0x55] = 0;
    *reinterpret_cast<uint8_t*>(base + 0x158) = 0;
    *reinterpret_cast<uint16_t*>(base + 0x17c) = 0;
    w[0x53] = 3;
    *reinterpret_cast<uint16_t*>(base + 0x17e) = 0xffb5;
}

// 0x551ce0 — observed shape
// Recomputes the view-dependent lighting basis from self+0x154:
//  - mode 2: fixed 0.5/texture scale from the three axis vectors at
//    self+0x74/0x70, self+0x80/0x7c, self+0x8c/0x88 and zeroed bias fields;
//  - modes 3/4: identity basis built through FUN_0053cc20/FUN_0053c8d0 and
//    copied as 9 dwords to self+0x114;
//  - otherwise: scale by 1/self+0x9c, build the basis, then derive the
//    offset at self+0x138/0x13c/0x140 from self+0x108/0x10c/0x110 minus the
//    transformed point (FUN_0053ca60 on self+0x90).
// Always transforms self+0x15c into self+0x16c/0x170/0x174, bumps the frame
// counter at self+0xc0 and writes the plane distance at self+0x178.
void FUN_00551ce0(int self)
{
    uint32_t uVar1;
    uint32_t* puVar2;
    float* pfVar3;
    int iVar4;
    uint32_t* puVar5;
    uint8_t* puVar6;
    float fVar7;
    float local_94;
    float local_90;
    float local_8c;
    float local_88;
    float local_84;
    float local_80;
    float local_7c;
    uint8_t local_78[12];
    uint8_t local_6c[36];
    uint8_t local_48[36];
    uint8_t local_24[36];

    iVar4 = *reinterpret_cast<int*>(self + 0x154);
    if (iVar4 == 2) {
        *reinterpret_cast<uint32_t*>(self + 0x13c) = 0x3f000000u;
        *reinterpret_cast<uint32_t*>(self + 0x138) = 0x3f000000u;
        *reinterpret_cast<uint32_t*>(self + 0x140) = 0;
        *reinterpret_cast<uint32_t*>(self + 300) = 0;
        *reinterpret_cast<float*>(self + 0x114) =
            *reinterpret_cast<float*>(self + 0x74) * 0.5f;
        *reinterpret_cast<float*>(self + 0x120) =
            *reinterpret_cast<float*>(self + 0x70) * -0.5f;
        *reinterpret_cast<uint32_t*>(self + 0x130) = 0;
        *reinterpret_cast<float*>(self + 0x118) =
            *reinterpret_cast<float*>(self + 0x80) * 0.5f;
        *reinterpret_cast<float*>(self + 0x124) =
            *reinterpret_cast<float*>(self + 0x7c) * -0.5f;
        *reinterpret_cast<uint32_t*>(self + 0x134) = 0;
        *reinterpret_cast<float*>(self + 0x11c) =
            *reinterpret_cast<float*>(self + 0x8c) * 0.5f;
        *reinterpret_cast<float*>(self + 0x128) =
            *reinterpret_cast<float*>(self + 0x88) * -0.5f;
    }
    else if ((iVar4 == 3) || (iVar4 == 4)) {
        *reinterpret_cast<uint32_t*>(self + 0x140) = 0;
        *reinterpret_cast<uint32_t*>(self + 0x13c) = 0;
        *reinterpret_cast<uint32_t*>(self + 0x138) = 0;
        uVar1 = static_cast<uint32_t>(FUN_0053cc20(local_48));
        puVar2 = static_cast<uint32_t*>(FUN_0053c8d0(local_6c, uVar1));
        puVar5 = reinterpret_cast<uint32_t*>(self + 0x114);
        for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar5 = *puVar2;
            puVar2 = puVar2 + 1;
            puVar5 = puVar5 + 1;
        }
    }
    else {
        puVar6 = local_24;
        fVar7 = 1.0f / *reinterpret_cast<float*>(self + 0x9c);
        local_88 = fVar7;
        uVar1 = static_cast<uint32_t>(FUN_0053cc20(local_6c));
        FUN_0053c8d0(local_48, uVar1);
        puVar2 = static_cast<uint32_t*>(FUN_0053c9e0(puVar6, fVar7));
        puVar5 = reinterpret_cast<uint32_t*>(self + 0x114);
        for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar5 = *puVar2;
            puVar2 = puVar2 + 1;
            puVar5 = puVar5 + 1;
        }
        pfVar3 = FUN_0053ca60(local_78, reinterpret_cast<void*>(self + 0x90));
        local_84 = *reinterpret_cast<float*>(self + 0x108) - pfVar3[0];
        local_80 = *reinterpret_cast<float*>(self + 0x10c) - pfVar3[1];
        local_7c = *reinterpret_cast<float*>(self + 0x110) - pfVar3[2];
        *reinterpret_cast<float*>(self + 0x138) = local_84;
        *reinterpret_cast<float*>(self + 0x13c) = local_80;
        *reinterpret_cast<float*>(self + 0x140) = local_7c;
    }
    FUN_0053ca60(&local_94, reinterpret_cast<void*>(self + 0x15c));
    *reinterpret_cast<float*>(self + 0x16c) = local_94;
    *reinterpret_cast<float*>(self + 0x170) = local_90;
    *reinterpret_cast<int*>(self + 0xc0) =
        *reinterpret_cast<int*>(self + 0xc0) + 1;
    *reinterpret_cast<float*>(self + 0x178) =
        local_94 * *reinterpret_cast<float*>(self + 0x90) +
        local_8c * *reinterpret_cast<float*>(self + 0x98) +
        local_90 * *reinterpret_cast<float*>(self + 0x94) +
        *reinterpret_cast<float*>(self + 0x168) *
            *reinterpret_cast<float*>(self + 0x9c);
    *reinterpret_cast<float*>(self + 0x174) = local_8c;
}

// 0x551f00 — observed shape
// Runs FUN_004db0a0 and then the lighting update at 0x551ce0.
void FUN_00551f00(void)
{
    FUN_004db0a0();
    // NEEDS_MANUAL: the listing calls FUN_00551ce0 with no explicit
    // argument; its ECX receiver is not surfaced by this function.
    FUN_00551ce0(0);
}

// 0x551f30 — observed shape
// Base update FUN_00535750(param_1), then a refcounted assignment of the
// object returned by FUN_00545600 to self+0x144: release the previous
// object through its leading virtual slot when its counter at +4 drops to
// zero, store the new pointer and bump its counter.
void FUN_00551f30(void* self, uint32_t param_1)
{
    uint8_t* const base = static_cast<uint8_t*>(self);
    uint32_t* puVar2;
    uint32_t* puVar3;
    uint32_t* piVar1;

    FUN_00535750(param_1);
    puVar3 = static_cast<uint32_t*>(FUN_00545600());
    puVar2 = *reinterpret_cast<uint32_t**>(base + 0x144);
    if (puVar2 != puVar3) {
        if (puVar2 != nullptr) {
            piVar1 = puVar2 + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                void** vtbl = *reinterpret_cast<void***>(puVar2);
                reinterpret_cast<void (*)(int)>(vtbl[0])(1);
            }
        }
        *reinterpret_cast<uint32_t**>(base + 0x144) = puVar3;
        if (puVar3 != nullptr) {
            puVar3[1] = puVar3[1] + 1;
        }
    }
}

// 0x551fb0 — observed shape
// Destructor: reinstalls PTR_FUN_006c25d0, runs FUN_00551110, releases the
// refcounted object at word 0x51 through its leading virtual slot when its
// counter reaches zero, runs FUN_00535600 and, when bit 0 of param_1 is
// set, frees the receiver with operator_delete.
void FUN_00551fb0(void* self, uint8_t param_1)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    uint32_t* puVar2;
    uint32_t* piVar1;

    *in_ECX = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c25d0));
    FUN_00551110();
    puVar2 = reinterpret_cast<uint32_t*>(in_ECX[0x51]);
    if (puVar2 != nullptr) {
        piVar1 = puVar2 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            void** vtbl = *reinterpret_cast<void***>(puVar2);
            reinterpret_cast<void (*)(int)>(vtbl[0])(1);
        }
    }
    FUN_00535600();
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
}

// 0x552000 — observed shape
// Assignment operator: base assign FUN_00535300(param_1, param_2), then
// refcounted copy of self+0x144 into param_1+0x144, a 9-dword matrix copy
// from self+0xe4, and field-by-field copies of the trailing state
// (self+0x108..+0x110, +0x148..+0x178, +0x17c/+0x17e).
void FUN_00552000(int self, int param_1, uint32_t param_2)
{
    uint32_t* piVar1;
    uint32_t* puVar3;
    uint32_t* puVar4;
    int in_ECX = self;
    int iVar2;

    FUN_00535300(param_1, param_2);
    puVar3 = *reinterpret_cast<uint32_t**>(param_1 + 0x144);
    if (puVar3 != *reinterpret_cast<uint32_t**>(in_ECX + 0x144)) {
        if (puVar3 != nullptr) {
            piVar1 = puVar3 + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
                void** vtbl = *reinterpret_cast<void***>(puVar3);
                reinterpret_cast<void (*)(int)>(vtbl[0])(1);
            }
        }
        iVar2 = *reinterpret_cast<int*>(in_ECX + 0x144);
        *reinterpret_cast<int*>(param_1 + 0x144) = iVar2;
        if (iVar2 != 0) {
            *reinterpret_cast<int*>(iVar2 + 4) =
                *reinterpret_cast<int*>(iVar2 + 4) + 1;
        }
    }
    puVar3 = reinterpret_cast<uint32_t*>(in_ECX + 0xe4);
    puVar4 = reinterpret_cast<uint32_t*>(param_1 + 0xe4);
    for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
    }
    *reinterpret_cast<uint32_t*>(param_1 + 0x108) =
        *reinterpret_cast<uint32_t*>(in_ECX + 0x108);
    *reinterpret_cast<uint32_t*>(param_1 + 0x10c) =
        *reinterpret_cast<uint32_t*>(in_ECX + 0x10c);
    *reinterpret_cast<uint32_t*>(param_1 + 0x110) =
        *reinterpret_cast<uint32_t*>(in_ECX + 0x110);
    *reinterpret_cast<uint32_t*>(param_1 + 0x148) =
        *reinterpret_cast<uint32_t*>(in_ECX + 0x148);
    *reinterpret_cast<uint32_t*>(param_1 + 0x14c) =
        *reinterpret_cast<uint32_t*>(in_ECX + 0x14c);
    *reinterpret_cast<uint32_t*>(param_1 + 0x150) =
        *reinterpret_cast<uint32_t*>(in_ECX + 0x150);
    *reinterpret_cast<uint32_t*>(param_1 + 0x154) =
        *reinterpret_cast<uint32_t*>(in_ECX + 0x154);
    *reinterpret_cast<uint8_t*>(param_1 + 0x158) =
        *reinterpret_cast<uint8_t*>(in_ECX + 0x158);
    *reinterpret_cast<uint32_t*>(param_1 + 0x15c) =
        *reinterpret_cast<uint32_t*>(in_ECX + 0x15c);
    *reinterpret_cast<uint32_t*>(param_1 + 0x160) =
        *reinterpret_cast<uint32_t*>(in_ECX + 0x160);
    *reinterpret_cast<uint32_t*>(param_1 + 0x164) =
        *reinterpret_cast<uint32_t*>(in_ECX + 0x164);
    *reinterpret_cast<uint32_t*>(param_1 + 0x168) =
        *reinterpret_cast<uint32_t*>(in_ECX + 0x168);
    *reinterpret_cast<uint32_t*>(param_1 + 0x16c) =
        *reinterpret_cast<uint32_t*>(in_ECX + 0x16c);
    *reinterpret_cast<uint32_t*>(param_1 + 0x170) =
        *reinterpret_cast<uint32_t*>(in_ECX + 0x170);
    *reinterpret_cast<uint32_t*>(param_1 + 0x174) =
        *reinterpret_cast<uint32_t*>(in_ECX + 0x174);
    *reinterpret_cast<uint32_t*>(param_1 + 0x178) =
        *reinterpret_cast<uint32_t*>(in_ECX + 0x178);
    *reinterpret_cast<uint16_t*>(param_1 + 0x17c) =
        *reinterpret_cast<uint16_t*>(in_ECX + 0x17c);
    *reinterpret_cast<uint16_t*>(param_1 + 0x17e) =
        *reinterpret_cast<uint16_t*>(in_ECX + 0x17e);
}

// 0x552730 — observed shape
// Two-slot initializer: stores param_1 at self+0 and param_2 at self+4.
void FUN_00552730(void* self, uint32_t param_1, uint32_t param_2)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);

    *in_ECX = param_1;
    in_ECX[1] = param_2;
}

// 0x552780 — observed shape
// Formats the application time source name (APP_TIME / APP_INIT) into a
// 0xc-byte extension allocated past the NUL terminator; returns the tail.
// Case 1 returns early; case 0 falls through to the common return.
char* FUN_00552780(char* param_1, int param_2)
{
    char cVar1;
    char* pcVar2 = param_1;

    do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = static_cast<char*>(thunk_FUN_00533c78(
        static_cast<size_t>(reinterpret_cast<intptr_t>(pcVar2) +
                            (0xc - (reinterpret_cast<intptr_t>(param_1) + 1)))));
    if (param_2 == 0) {
        sprintf(pcVar2, "%s = APP_TIME", param_1);
    }
    else if (param_2 == 1) {
        sprintf(pcVar2, "%s = APP_INIT", param_1);
        return pcVar2;
    }
    return pcVar2;
}

// 0x5527e0 — observed shape
// Formats the wrap mode name (LOOP / REVERSE / CLAMP) into a 0xb-byte
// extension allocated past the NUL terminator; returns the tail.
char* FUN_005527e0(char* param_1, int param_2)
{
    char cVar1;
    char* pcVar2 = param_1;

    do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = static_cast<char*>(thunk_FUN_00533c78(
        static_cast<size_t>(reinterpret_cast<intptr_t>(pcVar2) +
                            (0xb - (reinterpret_cast<intptr_t>(param_1) + 1)))));
    if (param_2 == 0) {
        sprintf(pcVar2, "%s = LOOP", param_1);
    }
    else {
        if (param_2 == 1) {
            sprintf(pcVar2, "%s = REVERSE", param_1);
            return pcVar2;
        }
        if (param_2 == 2) {
            sprintf(pcVar2, "%s = CLAMP", param_1);
            return pcVar2;
        }
    }
    return pcVar2;
}

// 0x552860 — observed shape
// Counts the nodes of the chain linked through +0x38 starting at the
// receiver; returns the node count.
int FUN_00552860(int self)
{
    int iVar1 = 0;
    int in_ECX = self;

    for (; in_ECX != 0; in_ECX = *reinterpret_cast<int*>(in_ECX + 0x38)) {
        iVar1 = iVar1 + 1;
    }
    return iVar1;
}

// 0x5528a0 — observed shape
// Clears bit 3 of the flags byte at self+0xc, stores 0xff7fffff at self+0x24
// and, when bit 0 of the flags halfword is set, mirrors that value at
// self+0x20.
void FUN_005528a0(void* self)
{
    uint8_t* const base = static_cast<uint8_t*>(self);

    *reinterpret_cast<uint8_t*>(base + 0xc) =
        static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(base + 0xc) & 0xf7);
    *reinterpret_cast<uint32_t*>(base + 0x24) = 0xff7fffff;
    if ((*reinterpret_cast<uint16_t*>(base + 0xc) & 1) != 0) {
        *reinterpret_cast<uint32_t*>(base + 0x20) = 0xff7fffff;
    }
}

// 0x552aa0 — observed shape
// Copy-assign: base FUN_00538410, then the flags halfword at +0xc and the
// seven dwords +0x10..+0x28. When self+0x34 is set it resolves that object
// through FUN_005bd960(NULL-safe out) and stores it at dst+0x34 only if the
// vtable-derived type token (slot +4) of the resolved and source objects
// match; otherwise dst+0x34 is cleared. Finally, when self+0x38 is set, the
// object it yields for param_2 (vtable slot +8) replaces the refcounted
// pointer at dst+0x38, releasing the previous one when its counter reaches
// zero.
void FUN_00552aa0(int self, int* param_1, uint32_t param_2)
{
    int* piVar3 = param_1;
    uint32_t* puVar2;
    int* piVar1;
    char cVar4;
    int* piVar5;
    uint32_t* puVar6;

    FUN_00538410(param_1, param_2);
    *reinterpret_cast<uint16_t*>(piVar3 + 3) =
        *reinterpret_cast<uint16_t*>(self + 0xc);
    piVar3[4] = *reinterpret_cast<int*>(self + 0x10);
    piVar3[5] = *reinterpret_cast<int*>(self + 0x14);
    piVar3[6] = *reinterpret_cast<int*>(self + 0x18);
    piVar3[7] = *reinterpret_cast<int*>(self + 0x1c);
    piVar3[8] = *reinterpret_cast<int*>(self + 0x20);
    piVar3[9] = *reinterpret_cast<int*>(self + 0x24);
    piVar3[10] = *reinterpret_cast<int*>(self + 0x28);
    if (*reinterpret_cast<int*>(self + 0x34) != 0) {
        cVar4 = FUN_005bd960(*reinterpret_cast<int*>(self + 0x34), &param_1);
        piVar1 = param_1;
        if (cVar4 != '\0') {
            int* source = *reinterpret_cast<int**>(self + 0x34);
            void** vtblResolved = *reinterpret_cast<void***>(param_1);
            param_1 = reinterpret_cast<int*>(
                reinterpret_cast<int* (*)()>(vtblResolved[0x4 / 4])());
            void** vtblSource = *reinterpret_cast<void***>(source);
            piVar5 = reinterpret_cast<int*>(
                reinterpret_cast<int* (*)()>(vtblSource[0x4 / 4])());
            if (piVar5 == param_1) {
                piVar3[0xd] = reinterpret_cast<int>(reinterpret_cast<intptr_t>(piVar1));
                goto LAB_00552b2e;
            }
        }
        piVar3[0xd] = 0;
    }
LAB_00552b2e:
    if (*reinterpret_cast<int**>(self + 0x38) != 0) {
        int* owner = *reinterpret_cast<int**>(self + 0x38);
        void** vtbl = *reinterpret_cast<void***>(owner);
        puVar6 = reinterpret_cast<uint32_t*>(
            reinterpret_cast<uint32_t* (*)(uint32_t)>(vtbl[0x8 / 4])(param_2));
        puVar2 = reinterpret_cast<uint32_t*>(piVar3[0xe]);
        if (puVar2 != puVar6) {
            if (puVar2 != nullptr) {
                piVar1 = reinterpret_cast<int*>(puVar2 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    void** oldVtbl = *reinterpret_cast<void***>(puVar2);
                    reinterpret_cast<void (*)(int)>(oldVtbl[0])(1);
                }
            }
            piVar3[0xe] = reinterpret_cast<int>(reinterpret_cast<intptr_t>(puVar6));
            if (puVar6 != nullptr) {
                puVar6[1] = puVar6[1] + 1;
            }
        }
    }
}

// 0x552b70 — observed shape
// Forwards param_1 to FUN_00513ce0 and, when self+0x38 holds an object,
// invokes its vtable slot +0x28 with the same value.
void FUN_00552b70(void* self, uint32_t param_1)
{
    uint8_t* const base = static_cast<uint8_t*>(self);

    FUN_00513ce0(param_1);
    if (*reinterpret_cast<int**>(base + 0x38) != 0) {
        int* obj = *reinterpret_cast<int**>(base + 0x38);
        void** vtbl = *reinterpret_cast<void***>(obj);
        reinterpret_cast<void (*)(uint32_t)>(vtbl[0x28 / 4])(param_1);
    }
}

// 0x552b90 — observed shape
// Validates param_1 through FUN_00538360; on success invokes the vtable slot
// +0x14 of the object at self+0x38 and reports 1, otherwise 0.
uint8_t FUN_00552b90(void* self, uint32_t param_1)
{
    uint8_t* const base = static_cast<uint8_t*>(self);
    char cVar1;

    cVar1 = FUN_00538360(param_1);
    if (cVar1 == '\0') {
        return 0;
    }
    if (*reinterpret_cast<int**>(base + 0x38) != 0) {
        int* obj = *reinterpret_cast<int**>(base + 0x38);
        void** vtbl = *reinterpret_cast<void***>(obj);
        reinterpret_cast<void (*)(uint32_t)>(vtbl[0x14 / 4])(param_1);
    }
    return 1;
}

// 0x552bc0 — observed shape
// Strict equality against param_1: FUN_00538460 gates the comparison, then
// the flags halfword at +0xc must agree on bits 0, 1-2, 4 and 5, the four
// floats +0x10/+0x14/+0x18/+0x1c must compare equal, and the optional
// pointer at +0x34 must be consistently absent. Returns 1 on equality and a
// value whose low byte is zero otherwise (the listing's comparison-flag word).
uint32_t FUN_00552bc0(int self, int param_1)
{
    float fVar1;
    float fVar2;
    uint8_t bVar3;
    uint32_t uVar4;
    uint32_t uVar6;
    int iVar5;
    uint8_t bVar7;

    uVar4 = FUN_00538460(param_1);
    if (static_cast<char>(uVar4) != '\0') {
        uVar6 = (uVar4 >> 16) & 0xffffu;
        bVar3 = static_cast<uint8_t>(*reinterpret_cast<uint16_t*>(param_1 + 0xc));
        bVar7 = static_cast<uint8_t>(*reinterpret_cast<uint16_t*>(self + 0xc));
        if (((((bVar3 ^ bVar7) & 1) != 0) || (((bVar3 ^ bVar7) & 6) != 0)) ||
            ((((bVar3 ^ bVar7) >> 4 & 1) != 0) ||
             (bVar3 = static_cast<uint8_t>((bVar3 ^ bVar7) >> 5),
              uVar4 = (uVar4 & 0xffffff00u) | bVar3, (bVar3 & 1) != 0))) {
            goto LAB_00552c6f;
        }
        fVar1 = *reinterpret_cast<float*>(param_1 + 0x10);
        fVar2 = *reinterpret_cast<float*>(self + 0x10);
        uVar4 = (uVar6 << 16) | (static_cast<uint32_t>(fVar2 < fVar1) << 8) |
                (static_cast<uint32_t>(std::isnan(fVar2) || std::isnan(fVar1)) << 10) |
                (static_cast<uint32_t>(fVar2 == fVar1) << 14);
        if (fVar2 != fVar1) goto LAB_00552c6f;
        fVar1 = *reinterpret_cast<float*>(param_1 + 0x14);
        fVar2 = *reinterpret_cast<float*>(self + 0x14);
        uVar4 = (uVar6 << 16) | (static_cast<uint32_t>(fVar2 < fVar1) << 8) |
                (static_cast<uint32_t>(std::isnan(fVar2) || std::isnan(fVar1)) << 10) |
                (static_cast<uint32_t>(fVar2 == fVar1) << 14);
        if (fVar2 != fVar1) goto LAB_00552c6f;
        fVar1 = *reinterpret_cast<float*>(param_1 + 0x18);
        fVar2 = *reinterpret_cast<float*>(self + 0x18);
        uVar4 = (uVar6 << 16) | (static_cast<uint32_t>(fVar2 < fVar1) << 8) |
                (static_cast<uint32_t>(std::isnan(fVar2) || std::isnan(fVar1)) << 10) |
                (static_cast<uint32_t>(fVar2 == fVar1) << 14);
        if (fVar2 != fVar1) goto LAB_00552c6f;
        fVar1 = *reinterpret_cast<float*>(param_1 + 0x1c);
        fVar2 = *reinterpret_cast<float*>(self + 0x1c);
        uVar4 = (uVar6 << 16) | (static_cast<uint32_t>(fVar2 < fVar1) << 8) |
                (static_cast<uint32_t>(std::isnan(fVar2) || std::isnan(fVar1)) << 10) |
                (static_cast<uint32_t>(fVar2 == fVar1) << 14);
        if (fVar2 != fVar1) goto LAB_00552c6f;
        if (*reinterpret_cast<int*>(self + 0x34) != 0) {
            iVar5 = *reinterpret_cast<int*>(param_1 + 0x34);
            uVar4 = 0;
            if (iVar5 == 0) goto LAB_00552c6f;
            if (*reinterpret_cast<int*>(self + 0x34) != 0) goto LAB_00552c68;
        }
        uVar4 = *reinterpret_cast<uint32_t*>(param_1 + 0x34);
        iVar5 = 0;
        if (uVar4 == 0) {
LAB_00552c68:
            return 1;
        }
    }
LAB_00552c6f:
    return uVar4 & 0xffffff00u;
}
