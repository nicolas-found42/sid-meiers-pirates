// Reconstruction batch mass_0091 — Sid Meier's Pirates! (2004), PE32 i386.
// Each definition mirrors the Ghidra 12.2 corpus listing for its address.
// Field offsets, constants, call order, and return shape are preserved.
#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void* DAT_008ea08c;
extern void* PTR_FUN_0070e93c;
extern void* PTR_FUN_0070bf4c;
extern void* PTR_FUN_0070bed4;
extern void* PTR_FUN_0070bf10;
extern void* DAT_00727c3c;
extern void* DAT_00727854;
extern void* DAT_00727438;
extern void* DAT_00727434;
extern void* DAT_00727430;
extern void* LAB_005cea70;

extern void FUN_00507480(int param_1);
extern void FUN_005075c0(void* self, int param_2, int param_3, int param_4);
extern void FUN_005077f0(uint32_t param_1, uint32_t param_2, uint32_t param_3);
extern float FUN_005f0ddc();
extern void FUN_005044d0(uint32_t param_1);
extern void FUN_0050cd70();
extern int FUN_0050cde0();
extern void FUN_00507d20(int* param_1);
extern void FUN_0050df50(void* self);
extern void FUN_0050e4d0();
extern void FUN_0050d520();
extern void FUN_0050d630();
extern void FUN_0050d880();
extern void FUN_0050d9c0(void* param_1);
extern void FUN_0050dec0(uint16_t param_1);
extern void* FUN_00522010();
extern void FUN_00522ab0(int param_1);
extern void FUN_00521e70(void* param_1, uint32_t param_2, uint32_t param_3);
extern void FUN_00522120();
extern void* FUN_00533c78(uint32_t size);
extern void FUN_00540c50();
extern void* FUN_0053cac0(void* dst, void* src, void* mat);
extern void FUN_00533d10(int a, int b);
extern void* FUN_004127b0(void* dst, uint32_t stride, uint32_t count, void* init);
extern void FUN_005542d0(int a, int b, uint32_t c, int d, int e, int f, int g, uint32_t h);
extern void operator_delete(void* p);
extern void operator_delete__(void* p);
extern void* FUN_005535d0(uint16_t a, void* b, int c, int d, int e, int f, int g, int h, void* i, uint16_t j, uint16_t k);
extern void* FUN_00551880(void* p);
extern void FUN_004aac50(void* p);
extern void FUN_00534130();
extern void FUN_00534350();
extern void FUN_00510d00(uint32_t f);
extern void* FUN_00500850();
extern void* FUN_005428c0();
extern void FUN_004aad70(void* p);
extern void FUN_004aacc0(int a);
extern void* FUN_005426d0();
extern void FUN_005606f0(int a, void* p);
extern void FUN_00491640();

// 0x50c4d0 — observed shape
// Self: ESI (int* field view). Receiver/arg: EDI float[4].
void FUN_0050c4d0(void* self, float* fparam)
{
    int32_t* s = (int32_t*)self;
    *(uint8_t*)((char*)s + 0xac * 4) = 1;
    typedef void (*NotifyFn)(float, float, int);
    NotifyFn fn = *(NotifyFn*)(*(intptr_t*)s + 0xa0);
    fn(fparam[0], fparam[2], s[0x18]);
    s[0xa9] = 0;
    s[0xa8] = 0;
    s[0xab] = (int32_t)(fparam[3] - fparam[2]);
    s[0xaa] = (int32_t)(fparam[1] - fparam[0]);
}

// 0x50c550 — observed shape
// Self: ESI. Guards: flag@0xac, range 0<=param<=limit@0xa4, enable@0xf2.
void FUN_0050c550(void* self, int32_t param_1)
{
    int32_t* s = (int32_t*)self;
    int32_t limit;
    float local_c = 0.0f;
    int32_t local_8 = 0;
    uint32_t local_4 = 0;
    if (((char)s[0xac] != '\0' && (limit = s[0xa4], param_1 <= limit) && (-1 < param_1)) && (*(char*)((char*)s + 0xf2) == '\0')) {
        FUN_00507480(limit);
        typedef void (*NotifyFn)(float, int32_t, uint32_t);
        NotifyFn fn = *(NotifyFn*)(*(intptr_t*)s + 0xa0);
        float v = ((float)param_1 / (float)limit) * (float)s[0xaa] - (float)s[0xa8];
        fn(v + local_c, local_8, local_4);
        s[0xa8] = local_8;
    }
}

// 0x50c5d0 — observed shape
// Self: ESI. Z-axis variant of 0x50c550 (limit@0xa5, range@0xab/0xa9).
void FUN_0050c5d0(void* self, int32_t param_1)
{
    int32_t* s = (int32_t*)self;
    int32_t limit;
    uint32_t local_c = 0;
    float local_8 = 0.0f;
    uint32_t local_4 = 0;
    if (((char)s[0xac] != '\0' && (limit = s[0xa5], param_1 <= limit) && (-1 < param_1)) && (*(char*)((char*)s + 0xf2) == '\0')) {
        FUN_00507480(limit);
        typedef void (*NotifyFn)(uint32_t, float, uint32_t);
        NotifyFn fn = *(NotifyFn*)(*(intptr_t*)s + 0xa0);
        float v = ((float)param_1 / (float)limit) * (float)s[0xab] - (float)s[0xa9];
        fn(local_c, v + local_8, local_4);
        s[0xa9] = (int32_t)local_8;
    }
}

// 0x50c7b0 — observed shape
// Self: ESI (receives on ESI); EAX holds unsigned pixel x. Scales by
// screen size from DAT_008ea08c vtables (+0x58 / +0x5c), clamps to [0,limit].
void FUN_0050c7b0(void* self, float param_1, int32_t eax_x)
{
    int32_t* s = (int32_t*)self;
    float fVar3 = (float)eax_x;
    if (eax_x < 0) fVar3 = fVar3 + 4.2949673e+09f;
    typedef int (*SizeFn)();
    SizeFn wfn = *(SizeFn*)(*(intptr_t*)DAT_008ea08c + 0x58);
    int w = wfn();
    fVar3 = (fVar3 / (float)w) * 1024.0f - (float)s[0xa6];
    float fVar4 = (float)(int32_t)param_1;
    if ((int32_t)param_1 < 0) fVar4 = fVar4 + 4.2949673e+09f;
    SizeFn hfn = *(SizeFn*)(*(intptr_t*)DAT_008ea08c + 0x5c);
    float fVar6 = (float)hfn();
    int32_t flag = s[0xac];
    float fVar1 = (float)s[0x17];
    float fVar2 = (float)s[0x19];
    fVar4 = (fVar4 / (float)(int32_t)fVar6) * 768.0f - (float)s[0xa7];
    float fStack_34 = 0.0f;
    if ((char)flag == '\0') {
        param_1 = fVar6;
    } else {
        param_1 = (fVar3 - fVar1) + (float)s[0xa8];
        fStack_34 = (fVar4 - -fVar2) + (float)s[0xa9];
        fVar6 = (float)FUN_005f0ddc();
        FUN_005f0ddc();
        if (0.0f <= fStack_34) {
            if ((float)s[0xab] < fStack_34) fStack_34 = (float)s[0xab];
        } else {
            fStack_34 = 0.0f;
        }
        if (0.0f <= param_1) {
            if ((float)s[0xaa] < param_1) param_1 = (float)s[0xaa];
        } else {
            param_1 = 0.0f;
        }
    }
    if ((char)flag == '\0') {
        typedef void (*NotifyFn)(float, float, int);
        NotifyFn fn = *(NotifyFn*)(*(intptr_t*)s + 0xa0);
        fn(fVar3, fVar4, s[0x18]);
    } else {
        fVar3 = (float)s[0x19];
        typedef void (*NotifyFn)(float, float, int);
        NotifyFn fn = *(NotifyFn*)(*(intptr_t*)s + 0xa0);
        fn((param_1 - (float)s[0xa8]) + fVar1, (fStack_34 - (float)s[0xa9]) + -fVar2, s[0x18]);
        s[0xa8] = (int32_t)-fVar3;
        // unaff_EDI source is not modeled; s[0xa9] assignment preserved as opaque
        s[0xa9] = s[0xa9];
    }
    if ((char)s[0xac] != '\0') {
        int iVar5 = (int)FUN_005f0ddc();
        int iVar7 = (int)FUN_005f0ddc();
        if (iVar5 - (int)fVar6 != 0) FUN_005075c0(self, 9, iVar5 - (int)fVar6, 0);
        if (iVar7 - (int)fStack_34 != 0) FUN_005075c0(self, 10, iVar7 - (int)fStack_34, 0);
    }
}

// 0x50ca90 — observed shape
// Self: ECX. Recomputes origin floats @0x298/0x29c when flag@0xf2 flips,
// then forwards to 0x50c7b0. Returns low byte of FUN_005077f0 result.
uint32_t FUN_0050ca90(void* self, int32_t param_1, int32_t param_2, uint32_t param_3)
{
    char cVar1 = *(char*)((char*)self + 0xf2);
    float fVar4 = (float)FUN_005077f0((uint32_t)param_1, (uint32_t)param_2, param_3);
    uint8_t uVar3 = (uint8_t)(uint32_t)fVar4;
    if (cVar1 != *(char*)((char*)self + 0xf2)) {
        fVar4 = (float)param_1;
        if (param_1 < 0) fVar4 = fVar4 + 4.2949673e+09f;
        typedef int (*SizeFn)();
        SizeFn wfn = *(SizeFn*)(*(intptr_t*)DAT_008ea08c + 0x58);
        int iVar5 = wfn();
        float fVar2 = (float)param_2;
        if (param_2 < 0) fVar2 = fVar2 + 4.2949673e+09f;
        SizeFn hfn = *(SizeFn*)(*(intptr_t*)DAT_008ea08c + 0x5c);
        int iVar6 = hfn();
        fVar4 = (fVar4 / (float)iVar5) * 1024.0f - *(float*)((char*)self + 0x5c);
        *(float*)((char*)self + 0x298) = fVar4;
        *(float*)((char*)self + 0x29c) = (fVar2 / (float)iVar6) * 768.0f - -*(float*)((char*)self + 100);
    }
    uint32_t uVar7 = (uint32_t)fVar4 >> 8;
    if (*(char*)((char*)self + 0xf2) != '\0') {
        FUN_0050c7b0(self, (float)param_2, param_1);
    }
    return (uVar7 << 8) | uVar3;
}

// ---------------------------------------------------------------------------
// Appended reconstructions (retry batch): 0x50cd70 .. 0x50ee00.
// The small helpers below reproduce idioms that repeat verbatim in the listings.
// ---------------------------------------------------------------------------

extern void* thunk_FUN_00533c78(uint32_t size);

// Provider refcounted-object release: decrement the counter at +4 and, when it
// reaches zero, invoke vtable slot 0 with (object, 1).
static inline void ReleaseRef(void* p)
{
    if (p != NULL) {
        int32_t* rc = (int32_t*)((uint32_t*)p + 1);
        *rc = *rc - 1;
        if (*rc == 0) (*(void (**)(void*, int32_t))(*(uint32_t*)p))(p, 1);
    }
}

// Provider smart-pointer assignment: release the old value, store the new one
// and add a reference when it is non-null.
static inline void AssignRef(void** slot, void* p)
{
    if (*slot != p) {
        ReleaseRef(*slot);
        *slot = p;
        if (p != NULL) ((int32_t*)p)[1] = ((int32_t*)p)[1] + 1;
    }
}

// Ghidra ABS() emission applied to a float.
static inline float ABS_f(float v) { return v < 0.0f ? -v : v; }

// Forward declarations for reconstructions that use a receiver/side-register
// signature different from the batch-header prototypes above.
void FUN_0050cd70_recon(void* self, int32_t index_ebx);
int FUN_0050cde0_recon(void* self);
char FUN_0050ce20(void* self, int32_t param_1, int32_t param_2, uint32_t param_3, uint32_t param_4);
void FUN_0050cf80(void* self, int* param_1);
void FUN_0050d070(void* self, int* param_1);
void FUN_0050d2f0(void* self);
void FUN_0050d3e0(void* self, uint32_t param_2);
void FUN_0050d520_recon(void* self);
void FUN_0050d630_recon(void* self);
void FUN_0050d880_recon(void* self);
void FUN_0050dec0_recon(void* self, uint16_t param_bx, uint16_t param_1);
void FUN_0050e4d0_recon(void* self);
void FUN_0050ee00(void* self, uint32_t in_ECX, uint32_t in_EAX, int32_t param_1);

// 0x50cd70 — observed shape
// Self: ESI. Selection index: EBX (caller-carried). Bounds-checks the index
// against *(*(self+0x298)+0x2e8), then rebuilds the 256-byte state block and
// sets bit 0 of *(*(self+0x298)+0x20).
void FUN_0050cd70_recon(void* self, int32_t index_ebx)
{
    uint8_t* s = (uint8_t*)self;
    uint8_t local_100[256];

    if ((index_ebx < *(int32_t*)(*(intptr_t*)(s + 0x298) + 0x2e8)) && (-1 < index_ebx)) {
        FUN_00522010();
        FUN_00522ab0(index_ebx);
        FUN_00521e70(local_100, 0xffffffff, 0);
        uint8_t* pbVar1 = (uint8_t*)(*(intptr_t*)(s + 0x298) + 0x20);
        *pbVar1 = *pbVar1 | 1;
        FUN_00522120();
    }
}

// 0x50cde0 — observed shape
// Self: EAX. Linear search of the pointer table at *(*(self+0x298)+0x2dc) for
// the value stored at *(*(self+0x298)+0x2d0); returns its index or -1.
int FUN_0050cde0_recon(void* self)
{
    uint8_t* s = (uint8_t*)self;
    int32_t iVar1 = *(int32_t*)(s + 0x298);
    int32_t iVar2 = 0;

    if (0 < *(int32_t*)(iVar1 + 0x2e4)) {
        int32_t* piVar3 = *(int32_t**)(iVar1 + 0x2dc);
        do {
            if ((*piVar3 != 0) && (*piVar3 == *(int32_t*)(iVar1 + 0x2d0))) {
                return iVar2;
            }
            iVar2 = iVar2 + 1;
            piVar3 = piVar3 + 1;
        } while (iVar2 < *(int32_t*)(iVar1 + 0x2e4));
    }
    return -1;
}

// 0x50ce20 — observed shape
// Self: ECX. Input dispatch. First offers the event to the child object at
// self+0xf8 (virtual slot +4), then matches param_1 against the child handles
// at self+0x290/0x294/0x298 and toggles the visible bit at
// *(*(self+0x298)+0x20) on the (0x290, 0) pair.
char FUN_0050ce20(void* self, int32_t param_1, int32_t param_2, uint32_t param_3, uint32_t param_4)
{
    uint8_t* s = (uint8_t*)self;
    char cVar2;
    int32_t iVar1;
    // The batch header declares FUN_005075c0 void-returning, but the listing
    // propagates its AL result as this function's return value.
    typedef char (*DispatchFn)(void*, int32_t, int32_t, int32_t);
    DispatchFn dispatch = reinterpret_cast<DispatchFn>(&FUN_005075c0);

    if ((*(intptr_t**)(s + 0xf8) != NULL) &&
        (cVar2 = (*(char (**)(void*, int32_t, int32_t, uint32_t, uint32_t))(
             **(intptr_t**)(s + 0xf8) + 4))(*(void**)(s + 0xf8), param_1, param_2, param_3, param_4),
         cVar2 != '\0')) {
        return cVar2;
    }
    if ((param_1 == *(int32_t*)(s + 0x290)) && (param_2 == 0)) {
        iVar1 = *(int32_t*)(s + 0x298);
        if (*(uint8_t*)(iVar1 + 0x20) & 1) {
            *(uint8_t*)(iVar1 + 0x20) = *(uint8_t*)(iVar1 + 0x20) & 0xfe;
            FUN_005044d0(*(uint32_t*)(s + 0xfc));
            return '\x01';
        }
        *(uint8_t*)(iVar1 + 0x20) = *(uint8_t*)(iVar1 + 0x20) | 1;
        FUN_005044d0(*(uint32_t*)(s + 0xfc));
        return '\x01';
    }
    if ((param_1 == *(int32_t*)(s + 0x298)) ||
        (*(int32_t*)((intptr_t)param_1 + 0x24) == *(int32_t*)(s + 0x298))) {
        if (param_2 != 0xb) {
            return '\0';
        }
        FUN_0050cd70();
        FUN_005044d0(*(uint32_t*)(s + 0xfc));
    } else {
        if (param_1 != *(int32_t*)(s + 0x294)) {
            return dispatch(reinterpret_cast<void*>(static_cast<intptr_t>(param_1)), param_2,
                            (int32_t)param_3, (int32_t)param_4);
        }
        if (param_2 != 7) {
            if (param_2 == 8) {
                FUN_0050cde0();
                FUN_0050cd70();
                return dispatch(reinterpret_cast<void*>(static_cast<intptr_t>(param_1)), 0xb,
                                (int32_t)param_3, (int32_t)param_4);
            }
            return '\0';
        }
        FUN_0050cde0();
        FUN_0050cd70();
    }
    cVar2 = dispatch(reinterpret_cast<void*>(static_cast<intptr_t>(param_1)), 0xb,
                     (int32_t)param_3, (int32_t)param_4);
    return cVar2;
}

// 0x50cf80 — observed shape
// Self: ECX. Serialises this object: 0x50c7d0-style writer on param_1, then a
// 4-byte 1.0f payload through *(param_1[0x58]) slot 0xc, then the three child
// handles at self+0x290/0x294/0x298 through *(param_1) slot 0x2c.
void FUN_0050cf80(void* self, int* param_1)
{
    uint8_t* s = (uint8_t*)self;
    int* piVar1 = param_1;

    FUN_00507d20(param_1);
    int32_t one_bits = 0x3f800000;   // listing stores the float bits in param_1 itself
    uint32_t* writer = *(uint32_t**)((uint32_t*)piVar1 + 0x58);
    (*(void (**)(int32_t*, int32_t))(*writer + 0xc))(&one_bits, 4);
    (*(void (**)(int*, uint32_t))(*piVar1 + 0x2c))(piVar1, *(uint32_t*)(s + 0x290));
    (*(void (**)(int*, uint32_t))(*piVar1 + 0x2c))(piVar1, *(uint32_t*)(s + 0x294));
    (*(void (**)(int*, uint32_t))(*piVar1 + 0x2c))(piVar1, *(uint32_t*)(s + 0x298));
}

// 0x50d070 — observed shape
// Self: ESI (byte view). Initialiser: resolves the child chain of param_1,
// builds the renderer object graph at +0x58/+0x5c/+0x60/+0x64 from the provider
// block at *(self+8)+0xbc, then picks the geometry builder from the
// *(self+8)+0xc0 and self+1/self+2 flags.
void FUN_0050d070(void* self, int* param_1)
{
    uint8_t* s = (uint8_t*)self;

    *(uint32_t*)(s + 0x58) = 0;
    *(uint32_t*)(s + 0x5c) = 0;
    *(uint32_t*)(s + 0x60) = 0;
    *(uint32_t*)(s + 0x64) = 0;

    uint32_t uVar5;
    if (param_1 == NULL) {
        uVar5 = 0;
    } else {
        uint32_t bVar3 = 0;
        for (uint32_t** puVar6 = (uint32_t**)(*(void* (**)())(*param_1 + 4))();
             puVar6 != NULL; puVar6 = (uint32_t**)puVar6[1]) {
            if (puVar6 == (uint32_t**)&DAT_00727c3c) {
                bVar3 = 1;
                break;
            }
        }
        uVar5 = (0u - bVar3) & (uint32_t)(uintptr_t)param_1;
    }
    *(uint32_t*)(s + 8) = uVar5;

    // renderer object at +0x5c
    uint32_t* puVar6 = (uint32_t*)FUN_00533c78(0x40);
    if (puVar6 == NULL) {
        puVar6 = NULL;
    } else {
        FUN_00540c50();
        *puVar6 = (uint32_t)(uintptr_t)&PTR_FUN_0070e93c;
        *(uint8_t*)(puVar6 + 8) = 0;      // +0x20
        puVar6[9] = 4;                    // +0x24
        puVar6[10] = 0;                   // +0x28
        puVar6[0xb] = 0xffffffff;         // +0x2c
        puVar6[0xc] = 0;                  // +0x30
        puVar6[0xd] = 0;                  // +0x34
        puVar6[0xe] = 3;                  // +0x38
        puVar6[0xf] = 0;                  // +0x3c
    }
    AssignRef((void**)(s + 0x5c), puVar6);
    *(uint8_t*)(*(intptr_t*)(s + 0x5c) + 0x20) = 1;
    *(uint32_t*)(*(intptr_t*)(s + 0x5c) + 0x24) = 7;
    *(uint32_t*)(*(intptr_t*)(s + 0x5c) + 0x38) = 3;
    *(uint32_t*)(*(intptr_t*)(s + 0x5c) + 0x30) = 0;
    *(uint32_t*)(*(intptr_t*)(s + 0x5c) + 0x34) = 0;
    *(uint32_t*)(*(intptr_t*)(s + 0x5c) + 0x28) = 1;
    *(uint32_t*)(*(intptr_t*)(s + 0x5c) + 0x3c) = 1;

    // 0x24-byte display-mode descriptor at +0x60
    puVar6 = (uint32_t*)FUN_00533c78(0x24);
    if (puVar6 == NULL) {
        puVar6 = NULL;
    } else {
        FUN_00540c50();
        *puVar6 = (uint32_t)(uintptr_t)&PTR_FUN_0070bf4c;
        *(uint16_t*)(puVar6 + 8) = 0xec;  // +0x20
        *(uint8_t*)((intptr_t)puVar6 + 0x22) = 0;
    }
    AssignRef((void**)(s + 0x60), puVar6);
    {
        const intptr_t d = *(intptr_t*)(s + 0x60);
        *(uint8_t*)(d + 0x20) = *(uint8_t*)(d + 0x20) | 1;
        *(uint16_t*)(d + 0x20) = *(uint16_t*)(d + 0x20) & 0xffe3 | 2;
        *(uint16_t*)(d + 0x20) = *(uint16_t*)(d + 0x20) & 0xfe1f;
        *(uint8_t*)(d + 0x21) = *(uint8_t*)(d + 0x21) & 0xfd;
        *(uint8_t*)(d + 0x21) = *(uint8_t*)(d + 0x21) | 0x20;
    }

    // 0x28-byte sampler descriptor at +0x64
    puVar6 = (uint32_t*)FUN_00533c78(0x28);
    if (puVar6 == NULL) {
        puVar6 = NULL;
    } else {
        FUN_00540c50();
        *puVar6 = (uint32_t)(uintptr_t)&PTR_FUN_0070bed4;
        *(uint16_t*)(puVar6 + 8) = 3;     // +0x20
        puVar6[9] = 3;                    // +0x24
    }
    AssignRef((void**)(s + 0x64), puVar6);
    *(uint8_t*)(*(intptr_t*)(s + 0x64) + 0x20) = *(uint8_t*)(*(intptr_t*)(s + 0x64) + 0x20) & 0xfd;

    *(uint32_t*)(s + 4) = 0x40000000;

    uint8_t uVar4 = 0;
    if (param_1 != NULL) {
        for (uint32_t** puVar7 = (uint32_t**)(*(void* (**)())(*param_1 + 4))();
             puVar7 != NULL; puVar7 = (uint32_t**)puVar7[1]) {
            if (puVar7 == (uint32_t**)&DAT_00727854) {
                uVar4 = 1;
                break;
            }
        }
    }
    s[1] = uVar4;
    if (*(int32_t*)(*(intptr_t*)(s + 8) + 0xc0) == 0) {
        s[2] = 0;
    } else {
        s[2] = 1;
    }

    *(uint32_t*)(s + 0x14) = 0;
    *(uint32_t*)(s + 0x18) = 0;
    *(uint32_t*)(s + 0x1c) = 0xbf800000;
    FUN_00491640();
    *s = 1;
    *(uint32_t*)(s + 0x48) = 0;
    *(uint32_t*)(s + 0x4c) = 0;
    *(uint32_t*)(s + 0x2c) = 0;
    *(uint32_t*)(s + 0x30) = 0;
    *(uint32_t*)(s + 0x54) = 0;
    if (s[2] == '\0') {
        if (s[1] == '\0') {
            FUN_0050df50(self);
        } else {
            FUN_0050e4d0();
        }
    }

    void* puVar8 = *(void**)(s + 0x58);
    if (puVar8 != NULL) {
        ReleaseRef(puVar8);
        *(uint32_t*)(s + 0x58) = 0;
    }
}

// 0x50d2f0 — observed shape
// Self: ESI. Destructor: drops the four child objects at +0x58/+0x5c/+0x60/+0x64,
// frees the four heap blocks at +0x48/+0x4c/+0x2c/+0x30, then re-releases the
// child slots (already null) in reverse order.
void FUN_0050d2f0(void* self)
{
    uint8_t* s = (uint8_t*)self;

    void* puVar2 = *(void**)(s + 0x58);
    if (puVar2 != NULL) {
        ReleaseRef(puVar2);
        *(uint32_t*)(s + 0x58) = 0;
    }
    puVar2 = *(void**)(s + 0x5c);
    if (puVar2 != NULL) {
        ReleaseRef(puVar2);
        *(uint32_t*)(s + 0x5c) = 0;
    }
    puVar2 = *(void**)(s + 0x60);
    if (puVar2 != NULL) {
        ReleaseRef(puVar2);
        *(uint32_t*)(s + 0x60) = 0;
    }
    puVar2 = *(void**)(s + 0x64);
    if (puVar2 != NULL) {
        ReleaseRef(puVar2);
        *(uint32_t*)(s + 0x64) = 0;
    }

    if (*(void**)(s + 0x48) != NULL) {
        operator_delete(*(void**)(s + 0x48));
        *(uint32_t*)(s + 0x48) = 0;
    }
    if (*(void**)(s + 0x4c) != NULL) {
        operator_delete(*(void**)(s + 0x4c));
        *(uint32_t*)(s + 0x4c) = 0;
    }
    if (*(void**)(s + 0x2c) != NULL) {
        operator_delete(*(void**)(s + 0x2c));
        *(uint32_t*)(s + 0x2c) = 0;
    }
    if (*(void**)(s + 0x30) != NULL) {
        operator_delete(*(void**)(s + 0x30));
        *(uint32_t*)(s + 0x30) = 0;
    }

    ReleaseRef(*(void**)(s + 0x64));
    ReleaseRef(*(void**)(s + 0x60));
    ReleaseRef(*(void**)(s + 0x5c));
    ReleaseRef(*(void**)(s + 0x58));
}

// 0x50d3e0 — observed shape
// Self: param_1 (byte view). Builds the local 9-dword transform from
// *(self+8)+0x6c, transforms the base vector at self+0x14 into self+0x20..0x28,
// then runs the face builder selected by self[0]/self[1]/self[2] and finally
// re-submits the two vertex streams when a geometry build occurred.
void FUN_0050d3e0(void* self, uint32_t param_2)
{
    uint8_t* param_1 = (uint8_t*)self;
    uint8_t local_30[12];
    uint32_t local_24[9];

    uint32_t* puVar2 = (uint32_t*)(*(intptr_t*)(param_1 + 8) + 0x6c);
    uint32_t* puVar4 = local_24;
    for (int32_t iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar4 = puVar4 + 1;
    }
    uint32_t* puVar5 = (uint32_t*)FUN_0053cac0(local_30, param_1 + 0x14, local_24);
    *(uint32_t*)(param_1 + 0x20) = puVar5[0];
    *(uint32_t*)(param_1 + 0x24) = puVar5[1];
    *(uint32_t*)(param_1 + 0x28) = puVar5[2];

    if (*param_1 == '\0') {
        intptr_t iVar3 = *(intptr_t*)(param_1 + 8);
        intptr_t iVar1 = *(intptr_t*)(param_1 + 0x58);
        *(uint32_t*)(iVar1 + 0x5c) = *(uint32_t*)(iVar3 + 0x90);
        *(uint32_t*)(iVar1 + 0x60) = *(uint32_t*)(iVar3 + 0x94);
        *(uint32_t*)(iVar1 + 0x64) = *(uint32_t*)(iVar3 + 0x98);
        *(float*)(*(intptr_t*)(param_1 + 0x58) + 0x68) = ABS_f(*(float*)(*(intptr_t*)(param_1 + 8) + 0x9c));
        FUN_00533d10(0, 1);
    } else if (param_1[1] == '\0') {
        if (param_1[2] == '\0') {
            FUN_0050d520();
            FUN_0050d9c0(self);
            *param_1 = '\0';
        } else {
            FUN_0050d630();
            FUN_0050d9c0(self);
            *param_1 = '\0';
        }
    } else {
        FUN_0050d880();
        FUN_0050d9c0(self);
        *param_1 = '\0';
    }

    if (*(int32_t*)(param_1 + 0xc) != 0) {
        uint32_t* pRender = *(uint32_t**)(param_1 + 0x58);
        (*(void (**)(uint32_t*, uint32_t))(*pRender + 0x60))(pRender, param_2);
        *(uint32_t*)(*(intptr_t*)(param_1 + 0x5c) + 0x24) = 7;
        *(uint32_t*)(*(intptr_t*)(param_1 + 0x5c) + 0x38) = 4;
        *(uint32_t*)(*(intptr_t*)(param_1 + 0x5c) + 0x30) = 0;
        *(uint32_t*)(*(intptr_t*)(param_1 + 0x5c) + 0x34) = 0;
        *(uint32_t*)(*(intptr_t*)(param_1 + 0x5c) + 0x3c) = 2;
        pRender = *(uint32_t**)(param_1 + 0x58);
        (*(void (**)(uint32_t*, uint32_t))(*pRender + 0x60))(pRender, param_2);
        *(uint32_t*)(*(intptr_t*)(param_1 + 0x5c) + 0x24) = 7;
        *(uint32_t*)(*(intptr_t*)(param_1 + 0x5c) + 0x38) = 3;
        *(uint32_t*)(*(intptr_t*)(param_1 + 0x5c) + 0x30) = 0;
        *(uint32_t*)(*(intptr_t*)(param_1 + 0x5c) + 0x34) = 0;
        *(uint32_t*)(*(intptr_t*)(param_1 + 0x5c) + 0x3c) = 1;
    }
}

// 0x50d520 — observed shape
// Self: ESI (byte view). Builds the back-face culled triangle list from the
// provider block at *(self+8)+0xbc: vertex array at block+0x20, triangle index
// array at block+0x44, triangle count at block+0x3c. Culled vertices are
// appended to the index list at self+0x54; the rest go through 0x50dec0.
void FUN_0050d520_recon(void* self)
{
    uint8_t* s = (uint8_t*)self;
    intptr_t iVar6 = *(intptr_t*)(*(intptr_t*)(s + 8) + 0xbc);
    uint32_t local_8 = (uint32_t)*(uint16_t*)(iVar6 + 0x3c);
    iVar6 = *(intptr_t*)(iVar6 + 0x44);

    *(uint32_t*)(s + 0x10) = (uint32_t)(uintptr_t)thunk_FUN_00533c78(local_8 * 0xc);
    *(uint32_t*)(s + 0xc) = 0;
    *(uint32_t*)(s + 0x50) = 0;
    *(uint32_t*)(s + 0x54) = (uint32_t)(uintptr_t)thunk_FUN_00533c78(local_8 * 6);

    if (local_8 != 0) {
        int32_t local_10 = 0;
        uint16_t* puVar7 = (uint16_t*)(iVar6 + 4);
        do {
            float* pfVar5 = (float*)(*(intptr_t*)(s + 0x48) + local_10);
            uint16_t uVar1 = puVar7[-2];
            uint16_t uVar2 = puVar7[-1];
            uint16_t uVar3 = *puVar7;
            if (*(float*)(s + 0x20) * *pfVar5 +
                    pfVar5[2] * *(float*)(s + 0x28) +
                    *(float*)(*(intptr_t*)(s + 0x48) + 4 + local_10) * *(float*)(s + 0x24) < 0.0f) {
                *(uint16_t*)(*(intptr_t*)(s + 0x54) + *(int32_t*)(s + 0x50) * 2) = uVar1;
                iVar6 = *(int32_t*)(s + 0x50) + 1;
                *(int32_t*)(s + 0x50) = iVar6;
                *(uint16_t*)(*(intptr_t*)(s + 0x54) + iVar6 * 2) = uVar2;
                iVar6 = *(int32_t*)(s + 0x50) + 1;
                *(int32_t*)(s + 0x50) = iVar6;
                *(uint16_t*)(*(intptr_t*)(s + 0x54) + iVar6 * 2) = uVar3;
                *(int32_t*)(s + 0x50) = *(int32_t*)(s + 0x50) + 1;
            } else {
                FUN_0050dec0(uVar2);
                FUN_0050dec0(uVar3);
                FUN_0050dec0(uVar1);
            }
            local_10 = local_10 + 0xc;
            puVar7 = puVar7 + 3;
            local_8 = local_8 - 1;
        } while (local_8 != 0);
    }
}

// 0x50d630 — observed shape
// Self: ESI (byte view). Same culled-triangle build as 0x50d520 but with an
// explicit face-normal test and an optional local vertex remap at self+0x2c/
// self+0x30 (built through 0x5542d0) when self[2] is set.
void FUN_0050d630_recon(void* self)
{
    uint8_t* s = (uint8_t*)self;
    intptr_t iVar8 = *(intptr_t*)(*(intptr_t*)(s + 8) + 0xbc);
    intptr_t iVar7 = *(intptr_t*)(*(intptr_t*)(s + 8) + 0xbc);
    int32_t local_30 = *(int32_t*)(iVar8 + 0x20);   // vertex array
    int32_t local_34 = *(int32_t*)(iVar8 + 0x44);   // triangle index array
    uint32_t local_28 = (uint32_t)*(uint16_t*)(iVar7 + 0x3c);
    uint32_t uVar10 = (uint32_t)*(uint16_t*)(iVar7 + 0xc);

    if (*(char*)(s + 2) != '\0') {
        if (*(int32_t*)(s + 0x2c) == 0) {
            int32_t iVarA = (int32_t)(intptr_t)thunk_FUN_00533c78(uVar10 * 0xc);
            if (iVarA == 0) {
                iVarA = 0;
            } else {
                FUN_004127b0((void*)(intptr_t)iVarA, 0xc, uVar10, &LAB_005cea70);
            }
            *(int32_t*)(s + 0x2c) = iVarA;
            iVarA = (int32_t)(intptr_t)thunk_FUN_00533c78(uVar10 * 0xc);
            if (iVarA == 0) {
                iVarA = 0;
            } else {
                FUN_004127b0((void*)(intptr_t)iVarA, 0xc, uVar10, &LAB_005cea70);
            }
            *(int32_t*)(s + 0x30) = iVarA;
        }
        FUN_005542d0(local_30,
                     (int)*(uint32_t*)(*(intptr_t*)(*(intptr_t*)(s + 8) + 0xbc) + 0x24),
                     uVar10,
                     (int)*(uint32_t*)(s + 0x2c),
                     (int)*(uint32_t*)(s + 0x30),
                     0, 0, 0xc);
        local_30 = *(int32_t*)(s + 0x2c);
    }

    *(uint32_t*)(s + 0x10) = (uint32_t)(uintptr_t)thunk_FUN_00533c78(local_28 * 0xc);
    *(uint32_t*)(s + 0xc) = 0;
    *(uint32_t*)(s + 0x50) = 0;
    *(uint32_t*)(s + 0x54) = (uint32_t)(uintptr_t)thunk_FUN_00533c78(local_28 * 6);

    if (local_28 != 0) {
        uint16_t* local_2c = (uint16_t*)(local_34 + 4);
        uint32_t uVar11 = 0;
        do {
            uint16_t uVar4 = *local_2c;
            uint16_t uVar5 = local_2c[-2];
            uint16_t uVar6 = local_2c[-1];
            // CONCAT22 as emitted by the decompiler: keep the high half, replace
            // the low 16 bits, so the scratch registers carry uVar5 / uVar4.
            uVar11 = (uVar11 & 0xffff0000u) | (uint32_t)uVar5;
            local_34 = (int32_t)(((uint32_t)local_34 & 0xffff0000u) | (uint32_t)uVar4);
            float* pfVar1 = (float*)(local_30 + (uint32_t)uVar6 * 0xc);
            float* pfVar2 = (float*)(local_30 + (uint32_t)uVar5 * 0xc);
            float* pfVar3 = (float*)(local_30 + (uint32_t)uVar4 * 0xc);
            if (((pfVar1[1] - pfVar2[1]) * (*pfVar3 - *pfVar1) -
                 (pfVar3[1] - pfVar1[1]) * (*pfVar1 - *pfVar2)) * *(float*)(s + 0x28) +
                ((pfVar3[2] - pfVar1[2]) * (*pfVar1 - *pfVar2) -
                 (pfVar1[2] - pfVar2[2]) * (*pfVar3 - *pfVar1)) * *(float*)(s + 0x24) +
                ((pfVar3[1] - pfVar1[1]) * (pfVar1[2] - pfVar2[2]) -
                 (pfVar3[2] - pfVar1[2]) * (pfVar1[1] - pfVar2[1])) * *(float*)(s + 0x20) < 0.0f) {
                *(uint16_t*)(*(intptr_t*)(s + 0x54) + *(int32_t*)(s + 0x50) * 2) = uVar5;
                iVar8 = *(int32_t*)(s + 0x50) + 1;
                *(int32_t*)(s + 0x50) = iVar8;
                uVar11 = (uVar11 & 0xffff0000u) | (uint32_t)uVar4;
                *(uint16_t*)(*(intptr_t*)(s + 0x54) + iVar8 * 2) = uVar6;
                iVar8 = *(int32_t*)(s + 0x50) + 1;
                *(int32_t*)(s + 0x50) = iVar8;
                *(uint16_t*)(*(intptr_t*)(s + 0x54) + iVar8 * 2) = uVar4;
                *(int32_t*)(s + 0x50) = *(int32_t*)(s + 0x50) + 1;
            } else {
                FUN_0050dec0(uVar6);
                FUN_0050dec0((uint16_t)local_34);
                FUN_0050dec0((uint16_t)uVar11);
            }
            local_2c = local_2c + 3;
            local_28 = local_28 - 1;
        } while (local_28 != 0);
    }
}

// 0x50d880 — observed shape
// Self: ESI (byte view). Culled-triangle build over the pre-tessellated index
// list at self+0x4c (three ushorts per triangle) with the vertex array at
// self+0x48 and the triangle count at self+0x44.
void FUN_0050d880_recon(void* self)
{
    uint8_t* s = (uint8_t*)self;
    int32_t iVar7 = 0;

    if (*(int32_t*)(*(intptr_t*)(*(intptr_t*)(s + 8) + 0xbc) + 0x20) != 0) {
        *(uint32_t*)(s + 0x10) = (uint32_t)(uintptr_t)thunk_FUN_00533c78(*(int32_t*)(s + 0x44) * 0xc);
        *(uint32_t*)(s + 0xc) = 0;
        *(uint32_t*)(s + 0x50) = 0;
        *(uint32_t*)(s + 0x54) = (uint32_t)(uintptr_t)thunk_FUN_00533c78(*(int32_t*)(s + 0x44) * 6);
        uint32_t local_4 = 0;
        if (*(int32_t*)(s + 0x44) != 0) {
            int32_t local_8 = 0;
            do {
                float* pfVar5 = (float*)(*(intptr_t*)(s + 0x48) + local_8);
                if (*pfVar5 * *(float*)(s + 0x20) +
                        pfVar5[2] * *(float*)(s + 0x28) +
                        *(float*)(*(intptr_t*)(s + 0x48) + 4 + local_8) * *(float*)(s + 0x24) < 0.0f) {
                    uint16_t uVar2 = *(uint16_t*)(iVar7 + 4 + *(intptr_t*)(s + 0x4c));
                    uint16_t* puVar1 = (uint16_t*)(iVar7 + *(intptr_t*)(s + 0x4c));
                    uint16_t uVar3 = puVar1[1];
                    *(uint16_t*)(*(intptr_t*)(s + 0x54) + *(int32_t*)(s + 0x50) * 2) = *puVar1;
                    int32_t iVar6 = *(int32_t*)(s + 0x50) + 1;
                    *(int32_t*)(s + 0x50) = iVar6;
                    *(uint16_t*)(*(intptr_t*)(s + 0x54) + iVar6 * 2) = uVar3;
                    iVar6 = *(int32_t*)(s + 0x50) + 1;
                    *(int32_t*)(s + 0x50) = iVar6;
                    *(uint16_t*)(*(intptr_t*)(s + 0x54) + iVar6 * 2) = uVar2;
                    *(int32_t*)(s + 0x50) = *(int32_t*)(s + 0x50) + 1;
                } else {
                    FUN_0050dec0(*(uint16_t*)(iVar7 + *(intptr_t*)(s + 0x4c) + 2));
                    FUN_0050dec0(*(uint16_t*)(*(intptr_t*)(s + 0x4c) + iVar7 + 4));
                    FUN_0050dec0(*(uint16_t*)(iVar7 + *(intptr_t*)(s + 0x4c)));
                }
                local_4 = local_4 + 1;
                local_8 = local_8 + 0xc;
                iVar7 = iVar7 + 6;
            } while (local_4 < *(uint32_t*)(s + 0x44));
        }
    }
}

// 0x50d9c0 — observed shape
// Self: param_1 (byte view). Rebuilds the renderer geometry: expands the index
// list at self+0x10 (pairs), appends the culled triangles collected at
// self+0x54, then either re-points the D3D buffers at *(self+8)+0xbc or creates
// a fresh mesh/surface object at self+0x58 and rebinds the three children.
void FUN_0050d9c0(void* param_1)
{
    uint8_t* p = (uint8_t*)param_1;
    int32_t iVar14 = *(int32_t*)(*(intptr_t*)(*(intptr_t*)(p + 8) + 0xbc) + 0x20);
    if (iVar14 == 0) {
        return;
    }

    if (*(char*)(p + 2) != '\0') {
        iVar14 = *(int32_t*)(p + 0x2c);
    }
    uint32_t uVar13 = *(uint32_t*)(p + 0x50);
    uint16_t uVar17 = (uint16_t)((int16_t)(uVar13 / 3) + *(int16_t*)(p + 0xc));
    intptr_t iVar9 = *(intptr_t*)(p + 0x58);
    *(uint32_t*)(p + 0x34) = 0;
    *(uint16_t*)(p + 0x38) = uVar17;
    // The listing carries a "buffers were reallocated" flag in the low byte of
    // param_1; a set low bit selects the full renderer rebuild below.
    uint32_t reallocated = (uint32_t)(uintptr_t)param_1 & 0xffffff00u;

    if ((iVar9 == 0) ||
        ((uint32_t)*(uint16_t*)(*(intptr_t*)(iVar9 + 0xbc) + 0xc) <
             uVar13 + 1 + *(int32_t*)(p + 0xc) * 2) ||
        (*(uint32_t*)(*(intptr_t*)(iVar9 + 0xbc) + 0x40) < (uint32_t)uVar17 * 3)) {
        int32_t iVar18 = (int32_t)(uVar13 + 1 + *(int32_t*)(p + 0xc) * 2);
        reallocated = (reallocated & 0xffffff00u) | 1;
        int32_t iVar12 = (int32_t)(intptr_t)thunk_FUN_00533c78((uint32_t)iVar18 * 0xc);
        if (iVar12 == 0) {
            iVar12 = 0;
        } else {
            FUN_004127b0((void*)(intptr_t)iVar12, 0xc, (uint32_t)iVar18, &LAB_005cea70);
        }
        *(int32_t*)(p + 0x3c) = iVar12;
        *(uint32_t*)(p + 0x40) = (uint32_t)(uintptr_t)thunk_FUN_00533c78(
            (uint32_t)*(uint16_t*)(p + 0x38) * 6);
    } else {
        *(uint32_t*)(p + 0x3c) = *(uint32_t*)(*(intptr_t*)(iVar9 + 0xbc) + 0x20);
        *(uint32_t*)(p + 0x40) = *(uint32_t*)(*(intptr_t*)(iVar9 + 0xbc) + 0x44);
    }

    uVar13 = 0;
    *(float*)(p + 0x20) = *(float*)(p + 0x20) * 1e+09f;
    *(float*)(p + 0x24) = *(float*)(p + 0x24) * 1e+09f;
    *(float*)(p + 0x28) = *(float*)(p + 0x28) * 1e+09f;

    if (*(int32_t*)(p + 0xc) != 0) {
        float* pfVar3 = (float*)(iVar14 + **(int16_t**)(p + 0x10) * 0xc);
        float fVar5 = *(float*)(p + 0x24);
        float fVar6 = pfVar3[1];
        float fVar7 = *(float*)(p + 0x28);
        float fVar8 = pfVar3[2];
        float* pfVar4 = (float*)(*(intptr_t*)(p + 0x3c) + *(int32_t*)(p + 0x34) * 0xc);
        *pfVar4 = *(float*)(p + 0x20) + *pfVar3;
        pfVar4[1] = fVar5 + fVar6;
        pfVar4[2] = fVar7 + fVar8;
        *(int32_t*)(p + 0x34) = *(int32_t*)(p + 0x34) + 1;
    }

    uint32_t uVar16 = 0;
    if (*(int32_t*)(p + 0xc) != 0) {
        do {
            *(int16_t*)(*(intptr_t*)(p + 0x40) + (uVar13 & 0xffff) * 2) =
                *(int16_t*)(p + 0x34) + 1;
            *(uint16_t*)(*(intptr_t*)(p + 0x40) + ((uVar13 + 1) & 0xffff) * 2) =
                *(uint16_t*)(p + 0x34);
            *(uint16_t*)(*(intptr_t*)(p + 0x40) + ((uVar13 + 2) & 0xffff) * 2) = 0;
            uint32_t* puVar15 = (uint32_t*)(iVar14 +
                *(int16_t*)(*(intptr_t*)(p + 0x10) + uVar16 * 4) * 0xc);
            uint32_t* puVar20 = (uint32_t*)(*(intptr_t*)(p + 0x3c) + *(int32_t*)(p + 0x34) * 0xc);
            *puVar20 = *puVar15;
            puVar20[1] = puVar15[1];
            puVar20[2] = puVar15[2];
            uVar13 = uVar13 + 3;
            int32_t iVar18 = *(int32_t*)(p + 0x34) + 1;
            *(int32_t*)(p + 0x34) = iVar18;
            puVar15 = (uint32_t*)(*(intptr_t*)(p + 0x3c) + iVar18 * 0xc);
            puVar20 = (uint32_t*)(iVar14 +
                *(int16_t*)(*(intptr_t*)(p + 0x10) + 2 + uVar16 * 4) * 0xc);
            *puVar15 = *puVar20;
            puVar15[1] = puVar20[1];
            puVar15[2] = puVar20[2];
            *(int32_t*)(p + 0x34) = *(int32_t*)(p + 0x34) + 1;
            uVar16 = uVar16 + 1;
        } while (uVar16 < *(uint32_t*)(p + 0xc));
    }

    uVar16 = 0;
    if (*(uint32_t*)(p + 0x50) != 0) {
        do {
            *(int16_t*)(*(intptr_t*)(p + 0x40) + (uVar13 & 0xffff) * 2) =
                *(int16_t*)(p + 0x34) + 2;
            *(int16_t*)(*(intptr_t*)(p + 0x40) + ((uVar13 + 1) & 0xffff) * 2) =
                *(int16_t*)(p + 0x34) + 1;
            *(uint16_t*)(*(intptr_t*)(p + 0x40) + ((uVar13 + 2) & 0xffff) * 2) =
                *(uint16_t*)(p + 0x34);
            uint32_t* puVar15 = (uint32_t*)(iVar14 +
                (uint32_t)*(uint16_t*)(*(intptr_t*)(p + 0x54) + uVar16 * 2) * 0xc);
            uint32_t* puVar20 = (uint32_t*)(*(intptr_t*)(p + 0x3c) + *(int32_t*)(p + 0x34) * 0xc);
            *puVar20 = *puVar15;
            puVar20[1] = puVar15[1];
            puVar20[2] = puVar15[2];
            uVar13 = uVar13 + 3;
            int32_t iVar18 = *(int32_t*)(p + 0x34) + 1;
            *(int32_t*)(p + 0x34) = iVar18;
            puVar15 = (uint32_t*)(*(intptr_t*)(p + 0x3c) + iVar18 * 0xc);
            puVar20 = (uint32_t*)(iVar14 +
                (uint32_t)*(uint16_t*)(*(intptr_t*)(p + 0x54) + 2 + uVar16 * 2) * 0xc);
            *puVar15 = *puVar20;
            puVar15[1] = puVar20[1];
            puVar15[2] = puVar20[2];
            iVar18 = *(int32_t*)(p + 0x34) + 1;
            *(int32_t*)(p + 0x34) = iVar18;
            puVar15 = (uint32_t*)(*(intptr_t*)(p + 0x3c) + iVar18 * 0xc);
            puVar20 = (uint32_t*)(iVar14 +
                (uint32_t)*(uint16_t*)(*(intptr_t*)(p + 0x54) + 4 + uVar16 * 2) * 0xc);
            *puVar15 = *puVar20;
            puVar15[1] = puVar20[1];
            puVar15[2] = puVar20[2];
            *(int32_t*)(p + 0x34) = *(int32_t*)(p + 0x34) + 1;
            uVar16 = uVar16 + 3;
        } while (uVar16 < *(uint32_t*)(p + 0x50));
    }

    if (*(void**)(p + 0x10) != NULL) {
        operator_delete__(*(void**)(p + 0x10));
        *(uint32_t*)(p + 0x10) = 0;
    }
    if (*(void**)(p + 0x54) != NULL) {
        operator_delete__(*(void**)(p + 0x54));
        *(uint32_t*)(p + 0x54) = 0;
    }

    if ((reallocated & 0xff) == 0) {
        uint32_t* prov = *(uint32_t**)(iVar9 + 0xbc);
        (*(void (**)(uint32_t*, uint32_t))(*(uint32_t*)prov + 0x34))(prov, *(uint16_t*)(p + 0x34));
        (*(void (**)(uint32_t*, uint32_t))(*(uint32_t*)prov + 0x40))(prov, *(uint16_t*)(p + 0x38));
        uint8_t* pbVar2 = (uint8_t*)(*(intptr_t*)(iVar9 + 0xbc) + 0x32);
        *pbVar2 = *pbVar2 | 1;
        pbVar2 = (uint8_t*)(*(intptr_t*)(iVar9 + 0xbc) + 0x32);
        *pbVar2 = *pbVar2 | 0x30;
    } else {
        int32_t iVarA = (int32_t)(intptr_t)FUN_00533c78(0x58);
        uint32_t uVar19 = 0;
        if (iVarA != 0) {
            uVar19 = (uint32_t)(uintptr_t)FUN_005535d0(
                *(uint16_t*)(p + 0x34),
                (void*)(intptr_t)*(uint32_t*)(p + 0x3c),
                0, 0, 0, 0, 0,
                (int)*(uint16_t*)(p + 0x38),
                (void*)(intptr_t)*(uint32_t*)(p + 0x40),
                *(uint16_t*)(p + 0x34),
                *(uint16_t*)(p + 0x38));
        }
        iVarA = (int32_t)(intptr_t)FUN_00533c78(0xcc);
        uint32_t* puVar15b;
        if (iVarA == 0) {
            puVar15b = NULL;
        } else {
            puVar15b = (uint32_t*)FUN_00551880((void*)(intptr_t)uVar19);
        }
        AssignRef((void**)(p + 0x58), puVar15b);

        // The renderer temporarily adds a reference to each child before
        // handing it to 0x4aac50, then drops it again.
        uint32_t* puVar20b = *(uint32_t**)(p + 0x5c);
        if (puVar20b != NULL) {
            puVar20b[1] = puVar20b[1] + 1;
        }
        void* sp = puVar20b;
        FUN_004aac50(&sp);
        ReleaseRef(puVar20b);

        puVar20b = *(uint32_t**)(p + 0x60);
        if (puVar20b != NULL) {
            puVar20b[1] = puVar20b[1] + 1;
        }
        sp = puVar20b;
        FUN_004aac50(&sp);
        ReleaseRef(puVar20b);

        puVar20b = *(uint32_t**)(p + 0x64);
        if (puVar20b != NULL) {
            puVar20b[1] = puVar20b[1] + 1;
        }
        sp = puVar20b;
        FUN_004aac50(&sp);
        ReleaseRef(puVar20b);

        FUN_00534130();
        FUN_00534350();
        uint32_t uVar10 = (uint32_t)(uintptr_t)DAT_00727438;
        uint32_t uVar19b = (uint32_t)(uintptr_t)DAT_00727434;
        intptr_t iVarC = *(intptr_t*)(*(intptr_t*)(p + 0x58) + 0xbc);
        *(uint32_t*)(iVarC + 0x10) = (uint32_t)(uintptr_t)DAT_00727430;
        *(uint32_t*)(iVarC + 0x14) = uVar19b;
        *(uint32_t*)(iVarC + 0x18) = uVar10;
        *(uint32_t*)(iVarC + 0x1c) = 0x4e6e6b28;   // 1e9f
    }

    *(float*)(*(intptr_t*)(p + 0x58) + 0x68) = ABS_f(*(float*)(*(intptr_t*)(p + 8) + 0x9c));
    {
        uint32_t* puVar15c = (uint32_t*)(*(intptr_t*)(p + 8) + 0x6c);
        uint32_t* puVar20c = (uint32_t*)(*(intptr_t*)(p + 0x58) + 0x38);
        for (int32_t iVarD = 9; iVarD != 0; iVarD = iVarD + -1) {
            *puVar20c = *puVar15c;
            puVar15c = puVar15c + 1;
            puVar20c = puVar20c + 1;
        }
    }
    {
        intptr_t iVarE = *(intptr_t*)(p + 8);
        intptr_t iVarF = *(intptr_t*)(p + 0x58);
        *(uint32_t*)(iVarF + 0x5c) = *(uint32_t*)(iVarE + 0x90);
        *(uint32_t*)(iVarF + 0x60) = *(uint32_t*)(iVarE + 0x94);
        *(uint32_t*)(iVarF + 0x64) = *(uint32_t*)(iVarE + 0x98);
    }
    FUN_00533d10(0, 1);
}

// 0x50dec0 — observed shape
// Self: EAX (byte view: edge count at +0xc, pair array at +0x10). Removes the
// edge {param_bx, param_1} from the pair list, compacting with the last entry,
// or appends it when absent. param_bx models the unaffiliated BX vertex the
// listing reads from the caller.
void FUN_0050dec0_recon(void* self, uint16_t param_bx, uint16_t param_1)
{
    uint8_t* s = (uint8_t*)self;
    uint32_t uVar1 = *(uint32_t*)(s + 0xc);
    uint32_t uVar4 = 0;

    if (uVar1 != 0) {
        int16_t* psVar2 = *(int16_t**)(s + 0x10);
        int16_t* psVar3 = psVar2;
        do {
            if (((*psVar3 == (int16_t)param_bx) && (psVar3[1] == (int16_t)param_1)) ||
                ((*psVar3 == (int16_t)param_1) && (psVar3[1] == (int16_t)param_bx))) {
                if (1 < uVar1) {
                    psVar2[uVar4 * 2] = psVar2[uVar1 * 2 + -2];
                    *(uint16_t*)(*(intptr_t*)(s + 0x10) + 2 + uVar4 * 4) =
                        *(uint16_t*)(*(intptr_t*)(s + 0x10) + -2 + *(int32_t*)(s + 0xc) * 4);
                }
                *(int32_t*)(s + 0xc) = *(int32_t*)(s + 0xc) + -1;
                return;
            }
            uVar4 = uVar4 + 1;
            psVar3 = psVar3 + 2;
        } while (uVar4 < *(uint32_t*)(s + 0xc));
    }
    *(int16_t*)(*(intptr_t*)(s + 0x10) + uVar1 * 4) = (int16_t)param_bx;
    *(int16_t*)(*(intptr_t*)(s + 0x10) + 2 + *(int32_t*)(s + 0xc) * 4) = (int16_t)param_1;
    *(int32_t*)(s + 0xc) = *(int32_t*)(s + 0xc) + 1;
}

// Shared tail of every emitted triangle: face normal (v1-v0)x(v2-v1) stored at
// normals + count*3, the three indices written at indices + count*6, count++.
static inline void EmitTriangle(int32_t vertices, float* normals, uint8_t* indices,
                                int32_t* count, uint16_t v0, uint16_t v1, uint16_t v2)
{
    const float* p0 = (const float*)(vertices + (uint32_t)v0 * 0xc);
    const float* p1 = (const float*)(vertices + (uint32_t)v1 * 0xc);
    const float* p2 = (const float*)(vertices + (uint32_t)v2 * 0xc);
    float d10 = p1[0] - p0[0];
    float d11 = p1[1] - p0[1];
    float d12 = p1[2] - p0[2];
    float d20 = p2[0] - p1[0];
    float d21 = p2[1] - p1[1];
    float d22 = p2[2] - p1[2];
    float* out = normals + (uint32_t)*count * 3;
    out[0] = d21 * d12 - d22 * d11;
    out[1] = d22 * d10 - d12 * d20;
    out[2] = d11 * d20 - d21 * d10;
    *(uint16_t*)(indices + (uint32_t)*count * 6) = v0;
    *(uint16_t*)(indices + (uint32_t)*count * 6 + 2) = v1;
    *(uint16_t*)(indices + (uint32_t)*count * 6 + 4) = v2;
    *count = *count + 1;
}

// 0x50df50 — observed shape
// Self: param_1 (byte view). Builds per-triangle face normals from the vertex
// array at *(*(self+8)+0xbc)+0x20 and the triangle index array at
// *(*(self+8)+0xbc)+0x44 (count at +0x3c), then stores the copy at self+0x48.
// The forced 4x unrolled body and the zero-length tail copy are preserved.
void FUN_0050df50(void* self)
{
    uint8_t* p = (uint8_t*)self;
    intptr_t iVar16 = *(intptr_t*)(*(intptr_t*)(p + 8) + 0xbc);
    int32_t iVar4 = *(int32_t*)(iVar16 + 0x20);
    iVar16 = *(intptr_t*)(iVar16 + 0x44);
    uint32_t uVar19 = (uint32_t)*(uint16_t*)(*(intptr_t*)(*(intptr_t*)(p + 8) + 0xbc) + 0x3c);
    uint32_t uVar17 = uVar19 * 0xc;
    uint32_t* puVar11 = (uint32_t*)thunk_FUN_00533c78(uVar17);
    uint32_t uVar14 = 0;
    float fVar5, fVar6, fVar7, fVar8, fVar9, fVar10;

    if (3 < uVar19) {
        uint16_t* puVar12 = (uint16_t*)(iVar16 + 4);
        int32_t local_54 = (int32_t)((uVar19 - 4) >> 2) + 1;
        uVar14 = (uint32_t)local_54 * 4;
        float* pfVar15 = (float*)(puVar11 + 6);
        do {
            float* pfVar1 = (float*)(iVar4 + (uint32_t)puVar12[-2] * 0xc);
            float* pfVar2 = (float*)(iVar4 + (uint32_t)puVar12[-1] * 0xc);
            fVar5 = *pfVar2 - *pfVar1;
            float* pfVar3 = (float*)(iVar4 + (uint32_t)*puVar12 * 0xc);
            fVar8 = pfVar2[1] - pfVar1[1];
            fVar6 = pfVar2[2] - pfVar1[2];
            fVar9 = *pfVar3 - *pfVar2;
            fVar10 = pfVar3[1] - pfVar2[1];
            fVar7 = pfVar3[2] - pfVar2[2];
            pfVar15[-6] = fVar10 * fVar6 - fVar7 * fVar8;
            pfVar15[-5] = fVar7 * fVar5 - fVar6 * fVar9;
            pfVar15[-4] = fVar8 * fVar9 - fVar10 * fVar5;

            pfVar1 = (float*)(iVar4 + (uint32_t)puVar12[1] * 0xc);
            pfVar2 = (float*)(iVar4 + (uint32_t)puVar12[2] * 0xc);
            fVar5 = *pfVar2 - *pfVar1;
            fVar8 = pfVar2[1] - pfVar1[1];
            fVar6 = pfVar2[2] - pfVar1[2];
            pfVar1 = (float*)(iVar4 + (uint32_t)puVar12[3] * 0xc);
            fVar9 = *pfVar1 - *pfVar2;
            fVar10 = pfVar1[1] - pfVar2[1];
            fVar7 = pfVar1[2] - pfVar2[2];
            pfVar15[-3] = fVar10 * fVar6 - fVar7 * fVar8;
            pfVar15[-2] = fVar7 * fVar5 - fVar6 * fVar9;
            pfVar15[-1] = fVar8 * fVar9 - fVar10 * fVar5;

            pfVar1 = (float*)(iVar4 + (uint32_t)puVar12[4] * 0xc);
            pfVar2 = (float*)(iVar4 + (uint32_t)puVar12[5] * 0xc);
            pfVar3 = (float*)(iVar4 + (uint32_t)puVar12[6] * 0xc);
            fVar5 = *pfVar2 - *pfVar1;
            fVar8 = pfVar2[1] - pfVar1[1];
            fVar6 = pfVar2[2] - pfVar1[2];
            fVar9 = *pfVar3 - *pfVar2;
            fVar10 = pfVar3[1] - pfVar2[1];
            fVar7 = pfVar3[2] - pfVar2[2];
            *pfVar15 = fVar10 * fVar6 - fVar7 * fVar8;
            pfVar15[1] = fVar7 * fVar5 - fVar6 * fVar9;
            pfVar15[2] = fVar8 * fVar9 - fVar10 * fVar5;

            pfVar1 = (float*)(iVar4 + (uint32_t)puVar12[7] * 0xc);
            pfVar2 = (float*)(iVar4 + (uint32_t)puVar12[8] * 0xc);
            fVar5 = *pfVar2 - *pfVar1;
            pfVar3 = (float*)(iVar4 + (uint32_t)puVar12[9] * 0xc);
            fVar8 = pfVar2[1] - pfVar1[1];
            fVar6 = pfVar2[2] - pfVar1[2];
            fVar9 = *pfVar3 - *pfVar2;
            fVar10 = pfVar3[1] - pfVar2[1];
            puVar12 = puVar12 + 0xc;
            fVar7 = pfVar3[2] - pfVar2[2];
            pfVar15[3] = fVar10 * fVar6 - fVar7 * fVar8;
            pfVar15[4] = fVar7 * fVar5 - fVar6 * fVar9;
            pfVar15[5] = fVar8 * fVar9 - fVar10 * fVar5;
            local_54 = local_54 + -1;
            pfVar15 = pfVar15 + 0xc;
        } while (local_54 != 0);
    }

    if (uVar14 < uVar19) {
        int32_t local_50 = (int32_t)(uVar19 - uVar14);
        uint16_t* puVar12 = (uint16_t*)(iVar16 + 4 + uVar14 * 6);
        float* pfVar15 = (float*)(puVar11 + uVar14 * 3);
        do {
            float* pfVar1 = (float*)(iVar4 + (uint32_t)puVar12[-2] * 0xc);
            float* pfVar2 = (float*)(iVar4 + (uint32_t)puVar12[-1] * 0xc);
            fVar5 = *pfVar2 - *pfVar1;
            float* pfVar3 = (float*)(iVar4 + (uint32_t)*puVar12 * 0xc);
            fVar8 = pfVar2[1] - pfVar1[1];
            fVar6 = pfVar2[2] - pfVar1[2];
            fVar9 = *pfVar3 - *pfVar2;
            puVar12 = puVar12 + 3;
            fVar10 = pfVar3[1] - pfVar2[1];
            fVar7 = pfVar3[2] - pfVar2[2];
            *pfVar15 = fVar10 * fVar6 - fVar7 * fVar8;
            pfVar15[1] = fVar7 * fVar5 - fVar6 * fVar9;
            pfVar15[2] = fVar8 * fVar9 - fVar10 * fVar5;
            local_50 = local_50 + -1;
            pfVar15 = pfVar15 + 3;
        } while (local_50 != 0);
    }

    uint32_t* puVar13 = (uint32_t*)thunk_FUN_00533c78(uVar17);
    *(uint32_t**)(p + 0x48) = puVar13;
    uint32_t* puVar18 = puVar11;
    for (uint32_t n = uVar17 >> 2; n != 0; n = n - 1) {
        *puVar13 = *puVar18;
        puVar18 = puVar18 + 1;
        puVar13 = puVar13 + 1;
    }
    // zero-length byte tail copy, exactly as emitted by the decompiler
    for (int32_t iVar16b = 0; iVar16b != 0; iVar16b = iVar16b + -1) {
        *(uint8_t*)puVar13 = *(uint8_t*)puVar18;
        puVar18 = (uint32_t*)((intptr_t)puVar18 + 1);
        puVar13 = (uint32_t*)((intptr_t)puVar13 + 1);
    }
    operator_delete(puVar11);
}

// 0x50e4d0 — observed shape
// Self: EAX (byte view). Rebuilds the triangle soup from the packed index strip
// at *(*(self+8)+0xbc)+0x48 (element count in its first ushort), dropping
// degenerate faces and recomputing normals. The forced 4x unrolled main loop and
// the leftover-iteration tail are preserved; the counter at self+0x44 is the
// produced triangle count.
void FUN_0050e4d0_recon(void* self)
{
    uint8_t* p = (uint8_t*)self;
    intptr_t iVar19 = *(intptr_t*)(*(intptr_t*)(p + 8) + 0xbc);
    int32_t iVar6 = *(int32_t*)(iVar19 + 0x20);
    if (iVar6 == 0) {
        return;
    }

    intptr_t iVar7 = *(intptr_t*)(iVar19 + 0x48);
    uint16_t uVar14 = **(uint16_t**)(iVar19 + 0x44);
    uint32_t uVar21 = (uint32_t)uVar14 - 2;
    *(uint32_t*)(p + 0x44) = 0;
    uint32_t* local_50 = (uint32_t*)thunk_FUN_00533c78(uVar21 * 0xc);
    if (local_50 == NULL) {
        local_50 = NULL;
    } else {
        FUN_004127b0(local_50, 0xc, uVar21, &LAB_005cea70);
    }
    uint8_t* puVar15 = (uint8_t*)thunk_FUN_00533c78(uVar21 * 6);
    uint32_t uVar18 = 0;
    bool local_5d = true;
    uint32_t local_4c = 0;
    uint32_t local_48 = 0;
    uint32_t uVar16, uVar20;
    uint16_t uVar5;

    if (3 < (int)uVar21) {
        int32_t local_44 = (int32_t)((uVar14 - 6) >> 2) + 1;
        local_48 = (uint32_t)local_44 * 4;
        local_5d = true;
        do {
            // block A
            if (local_5d) {
                uVar16 = uVar18 & 0xffff;
                uVar20 = *(uint16_t*)(iVar7 + uVar16 * 2);
                uVar5 = *(uint16_t*)(iVar7 + 2 + uVar16 * 2);
                uVar14 = *(uint16_t*)(iVar7 + 4 + uVar16 * 2);
                uVar18 = uVar18 + 2;
                local_4c = uVar18;
            } else {
                uint16_t* puVar4 = (uint16_t*)(iVar7 + (uVar18 & 0xffff) * 2);
                uVar20 = *puVar4;
                uVar5 = puVar4[-1];
                uVar14 = puVar4[1];
            }
            local_5d = !local_5d;
            if (((uVar20 != uVar5) && (uVar5 != uVar14)) && (uVar14 != uVar20)) {
                EmitTriangle(iVar6, (float*)local_50, puVar15, (int32_t*)(p + 0x44),
                             (uint16_t)uVar20, uVar5, uVar14);
            }

            // block B
            if (local_5d) {
                uVar16 = uVar18 & 0xffff;
                uVar20 = *(uint16_t*)(iVar7 + uVar16 * 2);
                uVar5 = *(uint16_t*)(iVar7 + 2 + uVar16 * 2);
                uVar14 = *(uint16_t*)(iVar7 + 4 + uVar16 * 2);
                uVar18 = uVar18 + 2;
                local_4c = uVar18;
            } else {
                uint16_t* puVar4 = (uint16_t*)(iVar7 + (uVar18 & 0xffff) * 2);
                uVar20 = *puVar4;
                uVar5 = puVar4[-1];
                uVar14 = puVar4[1];
            }
            if (((uVar20 != uVar5) && (uVar5 != uVar14)) && (uVar14 != uVar20)) {
                EmitTriangle(iVar6, (float*)local_50, puVar15, (int32_t*)(p + 0x44),
                             (uint16_t)uVar20, uVar5, uVar14);
            }

            // block C
            if (local_5d) {
                uint16_t* puVar4 = (uint16_t*)(iVar7 + (uVar18 & 0xffff) * 2);
                uVar20 = *puVar4;
                uVar5 = puVar4[-1];
                uVar14 = puVar4[1];
            } else {
                uVar16 = uVar18 & 0xffff;
                uVar20 = *(uint16_t*)(iVar7 + uVar16 * 2);
                uVar5 = *(uint16_t*)(iVar7 + 2 + uVar16 * 2);
                uVar14 = *(uint16_t*)(iVar7 + 4 + uVar16 * 2);
                uVar18 = uVar18 + 2;
                local_4c = uVar18;
            }
            if (((uVar20 != uVar5) && (uVar5 != uVar14)) && (uVar14 != uVar20)) {
                EmitTriangle(iVar6, (float*)local_50, puVar15, (int32_t*)(p + 0x44),
                             (uint16_t)uVar20, uVar5, uVar14);
            }

            // block D
            if (local_5d) {
                uVar14 = *(uint16_t*)(iVar7 + (uVar18 & 0xffff) * 2);
                uVar5 = *(uint16_t*)(iVar7 + 2 + (uVar18 & 0xffff) * 2);
                uVar20 = *(uint16_t*)(iVar7 + 4 + (uVar18 & 0xffff) * 2);
                uVar18 = uVar18 + 2;
                local_4c = uVar18;
            } else {
                uint16_t* puVar4 = (uint16_t*)(iVar7 + (uVar18 & 0xffff) * 2);
                uVar14 = *puVar4;
                uVar5 = puVar4[-1];
                uVar20 = puVar4[1];
            }
            uint32_t local_58 = (uint32_t)uVar5;
            local_5d = !local_5d;
            if (uVar14 != uVar5) {
                if ((uVar5 != uVar20) && (uVar20 != uVar14)) {
                    EmitTriangle(iVar6, (float*)local_50, puVar15, (int32_t*)(p + 0x44),
                                 uVar14, (uint16_t)local_58, (uint16_t)uVar20);
                }
                uVar18 = local_4c;
            }
            local_44 = local_44 + -1;
        } while (local_44 != 0);
    }

    if (local_48 < uVar21) {
        int32_t local_40 = (int32_t)(uVar21 - local_48);
        do {
            if (local_5d) {
                uVar21 = uVar18 & 0xffff;
                uVar20 = *(uint16_t*)(iVar7 + uVar21 * 2);
                uVar5 = *(uint16_t*)(iVar7 + 2 + uVar21 * 2);
                uVar14 = *(uint16_t*)(iVar7 + 4 + uVar21 * 2);
                uVar18 = uVar18 + 2;
            } else {
                uint16_t* puVar4 = (uint16_t*)(iVar7 + (uVar18 & 0xffff) * 2);
                uVar20 = *puVar4;
                uVar5 = puVar4[-1];
                uVar14 = puVar4[1];
            }
            local_5d = (local_5d == false);
            if (((uVar20 != uVar5) && (uVar5 != uVar14)) && (uVar14 != uVar20)) {
                EmitTriangle(iVar6, (float*)local_50, puVar15, (int32_t*)(p + 0x44),
                             (uint16_t)uVar20, uVar5, uVar14);
            }
            local_40 = local_40 + -1;
        } while (local_40 != 0);
    }

    uint8_t* puVar17 = (uint8_t*)thunk_FUN_00533c78(*(int32_t*)(p + 0x44) * 0xc);
    *(uint8_t**)(p + 0x48) = puVar17;
    uint32_t* puVar22 = local_50;
    for (uint32_t n = (uint32_t)(*(int32_t*)(p + 0x44) * 0xc) >> 2; n != 0; n = n - 1) {
        *(uint32_t*)puVar17 = *puVar22;
        puVar22 = puVar22 + 1;
        puVar17 = puVar17 + 4;
    }
    // zero-length byte tail copy, exactly as emitted by the decompiler
    for (int32_t iVarA = 0; iVarA != 0; iVarA = iVarA + -1) {
        *(uint8_t*)puVar17 = *(uint8_t*)puVar22;
        puVar22 = (uint32_t*)((intptr_t)puVar22 + 1);
        puVar17 = puVar17 + 1;
    }

    uint8_t* puVar17b = (uint8_t*)thunk_FUN_00533c78(*(int32_t*)(p + 0x44) * 6);
    *(uint8_t**)(p + 0x4c) = puVar17b;
    uint32_t uVar18b = (uint32_t)(*(int32_t*)(p + 0x44) * 6);
    uint8_t* puVar22b = puVar15;
    for (uint32_t n = uVar18b >> 2; n != 0; n = n - 1) {
        *(uint32_t*)puVar17b = *(uint32_t*)puVar22b;
        puVar22b = puVar22b + 4;
        puVar17b = puVar17b + 4;
    }
    for (uint32_t n = uVar18b & 3; n != 0; n = n - 1) {
        *(uint8_t*)puVar17b = *(uint8_t*)puVar22b;
        puVar22b = puVar22b + 1;
        puVar17b = puVar17b + 1;
    }
    operator_delete(local_50);
    operator_delete(puVar15);
}

// 0x50ee00 — observed shape
// Self: EDI (int* field view); ECX and EAX supply the two provider handles.
// Constructor: clears the field block, stores the handles at +0x20/+0x1c, then
// builds the renderer children at +0x04/+0x08/+0x0c/+0x10/+0x28/+0x14 and the
// 0x1c-byte sub-object behind *(child5+0x2c) via 0x5606f0.
void FUN_0050ee00(void* self, uint32_t in_ECX, uint32_t in_EAX, int32_t param_1)
{
    int32_t* e = (int32_t*)self;

    e[0] = 0;
    e[1] = 0;
    e[2] = 0;
    e[3] = 0;
    e[4] = 0;
    e[5] = 0;
    e[10] = 0;
    e[0xc] = 0;
    e[0xd] = 0;
    e[0xe] = 0;
    e[0xf] = 0;
    e[0x10] = 0;
    e[0x11] = 0;
    e[0x12] = 0;
    e[0x13] = 0;

    e[8] = (int32_t)in_ECX;
    uint32_t* puVar2 = (uint32_t*)(intptr_t)e[0];
    e[7] = (int32_t)in_EAX;
    *(uint8_t*)(e + 6) = 0;
    if (puVar2 != NULL) {
        int32_t* piVar1 = (int32_t*)(puVar2 + 1);
        *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) {
            (*(void (**)(uint32_t*, int32_t))(*puVar2))(puVar2, 1);
        }
        e[0] = 0;
    }
    puVar2 = (uint32_t*)(intptr_t)e[10];
    if (puVar2 != NULL) {
        int32_t* piVar1 = (int32_t*)(puVar2 + 1);
        *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) {
            (*(void (**)(uint32_t*, int32_t))(*puVar2))(puVar2, 1);
        }
        e[10] = 0;
    }

    e[0xc] = 0x3f800000;
    e[0xb] = param_1;
    e[0xd] = 0x3f800000;
    e[0xe] = 0x3f800000;
    e[0x10] = 0x3f800000;
    e[0xf] = 0x3f800000;
    e[0x11] = 0x3f800000;
    e[0x12] = 0x3f800000;
    e[0x13] = 0;
    e[0x17] = 0;
    e[0x16] = 0;
    e[0x14] = 0;
    FUN_00510d00(0x3dcccccd);

    // renderer object at +0x04
    puVar2 = (uint32_t*)FUN_00533c78(0x40);
    if (puVar2 == NULL) {
        puVar2 = NULL;
    } else {
        FUN_00540c50();
        *puVar2 = (uint32_t)(uintptr_t)&PTR_FUN_0070e93c;
        *(uint8_t*)(puVar2 + 8) = 0;      // +0x20
        puVar2[9] = 4;                    // +0x24
        puVar2[10] = 0;                   // +0x28
        puVar2[0xb] = 0xffffffff;         // +0x2c
        puVar2[0xc] = 0;                  // +0x30
        puVar2[0xd] = 0;                  // +0x34
        puVar2[0xe] = 3;                  // +0x38
        puVar2[0xf] = 0;                  // +0x3c
    }
    AssignRef((void**)&e[1], puVar2);
    *(uint8_t*)(e[1] + 0x20) = 0;
    *(uint32_t*)(e[1] + 0x3c) = 3;

    // display-mode descriptor at +0x08
    puVar2 = (uint32_t*)FUN_00533c78(0x24);
    if (puVar2 == NULL) {
        puVar2 = NULL;
    } else {
        FUN_00540c50();
        *puVar2 = (uint32_t)(uintptr_t)&PTR_FUN_0070bf4c;
        *(uint16_t*)(puVar2 + 8) = 0xec;  // +0x20
        *(uint8_t*)((intptr_t)puVar2 + 0x22) = 0;
    }
    AssignRef((void**)&e[2], puVar2);
    *(uint16_t*)(e[2] + 0x20) = *(uint16_t*)(e[2] + 0x20) | 1;
    *(uint16_t*)(e[2] + 0x20) = *(uint16_t*)(e[2] + 0x20) & 0xffed | 0xc;
    *(uint16_t*)(e[2] + 0x20) = *(uint16_t*)(e[2] + 0x20) & 0xfeff | 0xe0;
    *(uint8_t*)(e[2] + 0x21) = *(uint8_t*)(e[2] + 0x21) & 0xfd;
    *(uint8_t*)(e[2] + 0x21) = *(uint8_t*)(e[2] + 0x21) | 0x20;

    // sampler descriptor at +0x0c
    puVar2 = (uint32_t*)FUN_00533c78(0x28);
    if (puVar2 == NULL) {
        puVar2 = NULL;
    } else {
        FUN_00540c50();
        *puVar2 = (uint32_t)(uintptr_t)&PTR_FUN_0070bed4;
        *(uint16_t*)(puVar2 + 8) = 3;     // +0x20
        puVar2[9] = 3;                    // +0x24
    }
    AssignRef((void**)&e[3], puVar2);
    *(uint16_t*)(e[3] + 0x20) = *(uint16_t*)(e[3] + 0x20) | 1;
    *(uint8_t*)(e[3] + 0x20) = *(uint8_t*)(e[3] + 0x20) & 0xfd;

    // render-state descriptor at +0x10
    puVar2 = (uint32_t*)FUN_00533c78(0x2c);
    if (puVar2 == NULL) {
        puVar2 = NULL;
    } else {
        FUN_00540c50();
        *puVar2 = (uint32_t)(uintptr_t)&PTR_FUN_0070bf10;
        *(uint16_t*)(puVar2 + 8) = 0;     // +0x20
        puVar2[9] = 0;                    // +0x24
        puVar2[10] = 1;                   // +0x28
    }
    AssignRef((void**)&e[4], puVar2);
    *(uint32_t*)(e[4] + 0x24) = 1;
    *(uint32_t*)(e[4] + 0x28) = 0;

    AssignRef((void**)&e[10], FUN_00500850());
    FUN_004aad70((void*)(intptr_t)e[10]);
    FUN_004aacc0(0);

    // mesh object at +0x14
    int32_t iVarA = (int32_t)(intptr_t)FUN_00533c78(0x48);
    uint32_t* puVar3;
    if (iVarA == 0) {
        puVar3 = NULL;
    } else {
        puVar3 = (uint32_t*)FUN_005428c0();
    }
    AssignRef((void**)&e[5], puVar3);

    *(uint32_t*)(e[5] + 0x20) = 3;
    int32_t iVar4 = **(int32_t**)(e[5] + 0x2c);
    if (iVar4 == 0) {
        iVar4 = (int32_t)(intptr_t)FUN_00533c78(0x1c);
        if (iVar4 == 0) {
            iVar4 = 0;
        } else {
            iVar4 = (int32_t)(intptr_t)FUN_005426d0();
        }
        param_1 = iVar4;
        FUN_005606f0(0, &param_1);
    }
    *(uint32_t*)((intptr_t)iVar4 + 0xc) = 2;
    if (**(int32_t**)(e[5] + 0x2c) != 0) {
        *(uint32_t*)((intptr_t)**(int32_t**)(e[5] + 0x2c) + 0x10) = 0;
        return;
    }
    iVar4 = (int32_t)(intptr_t)FUN_00533c78(0x1c);
    if (iVar4 == 0) {
        iVar4 = 0;
    } else {
        iVar4 = (int32_t)(intptr_t)FUN_005426d0();
    }
    param_1 = iVar4;
    FUN_005606f0(0, &param_1);
    *(uint32_t*)((intptr_t)iVar4 + 0x10) = 0;
}
