//
// mass_0129.cpp — reconstruction batch mass_0129
// Target: Sid Meier's Pirates! (2004), PE32 i386
// Image: 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
//
// Each definition preserves the observed field offsets, constants,
// call order, return shape, and conditional structure of the Ghidra
// 12.2 pseudocode (analysis/pseudocode/functions/*.c).
//
// Register receivers (in_ECX) are modeled as an explicit `void* self`.
//
#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---------------------------------------------------------------------------
// Extern declarations: helpers and globals referenced by the assigned corpus
// files. No additional addresses are introduced.
// ---------------------------------------------------------------------------
extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);

void operator_delete(void* ptr);
void operator_delete__(void* ptr);

void FUN_00534810(int* param_1);
void FUN_00534d60(int param_1);
void FUN_0053e670(void* self);              // thiscall base destructor body
void FUN_00540410(int param_1);
void FUN_00540aa0(int param_1);
void FUN_00540c50(void);
void FUN_00541080(int param_1);
void FUN_00547680(int* param_1);
void FUN_005606f0(uint32_t param_1, void* param_2);
void FUN_006b34a0(int param_1);
uint32_t FUN_005dbd60(void);

void* FUN_00533c78(uint32_t size);
void* thunk_FUN_00533c78(int size);

void* FUN_00557b10(void* name);
void* FUN_00557b50(const char* name, int value);
void* FUN_00557d80(const char* name, const char* value);

extern void* PTR_FUN_0070bf4c;
extern void* PTR_FUN_0070bed4;
extern void* PTR_FUN_0070bf10;

extern void* DAT_00727598;
extern void* DAT_007275a0;
extern uint32_t* DAT_007275ac;
extern void* DAT_007275b0;
extern uint32_t* DAT_007275b8;
extern uint32_t* DAT_007275c4;
extern uint16_t DAT_007275c8;
extern void* DAT_007275cc;

// ---------------------------------------------------------------------------
// Local helpers used to render the observed virtual calls
// `(**(code **)*obj)(1)`: invoke vtable slot 0 with flag 1 and the object as
// the implicit receiver.
// ---------------------------------------------------------------------------
typedef void (*VirtualDestroyFn)(void* self, int flag);

static void CallVtableDestroy(void* obj)
{
    void** vtbl = *reinterpret_cast<void***>(obj);
    reinterpret_cast<VirtualDestroyFn>(vtbl[0])(obj, 1);
}

// Float/bit reinterpretation used by the reciprocal-square-root table walk.
union FloatBits {
    float f;
    uint32_t u;
};

// ---------------------------------------------------------------------------
// 0x53ed20 — observed shape
// Configure a property object (two calls through vtable slot +0x2c), release
// optional counter at self+200, read two values through the object at
// param_1[0x58] vtable slot +0xc, then re-read the flag captured up front.
// ---------------------------------------------------------------------------
void FUN_0053ed20(void* self_recon, int* param_1)
{
    int in_ECX = static_cast<int>(reinterpret_cast<intptr_t>(self_recon));
    uint8_t auStackY_9c[128];

    FUN_00534810(param_1);
    char cVar1 = static_cast<char>(*reinterpret_cast<uint32_t*>(in_ECX + 0xbc));

    typedef void (*VFn0)(void* self);
    typedef void (*VFn1)(void* self, uint32_t value);
    uint32_t vtbl0 = *reinterpret_cast<uint32_t*>(param_1);
    reinterpret_cast<VFn0>(*reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(vtbl0) + 0x2c))(param_1);
    reinterpret_cast<VFn1>(*reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(vtbl0) + 0x2c))(
        param_1, *reinterpret_cast<uint32_t*>(in_ECX + 0xc0));

    if (*reinterpret_cast<int32_t*>(in_ECX + 200) != 0) {
        FUN_005dbd60();
    }

    typedef void (*VFn2)(uint32_t self, uint8_t* dst, int count);
    uint32_t obj = *reinterpret_cast<uint32_t*>(param_1 + 0x58);
    uint32_t objVtbl = *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(obj));
    reinterpret_cast<VFn2>(*reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(objVtbl) + 0xc))(
        obj, auStackY_9c + 0x98, 1);

    if (cVar1 != '\0') {
        FUN_00547680(param_1);
    }
}

// ---------------------------------------------------------------------------
// 0x53eda0 — observed shape
// Destructor-like: run base destructor on the receiver, delete receiver when
// the low bit of param_1 is set.
// ---------------------------------------------------------------------------
void FUN_0053eda0(void* self_recon, uint8_t param_1)
{
    void* in_ECX = self_recon;

    FUN_0053e670(in_ECX);
    if ((param_1 & 1) != 0) {
        operator_delete(in_ECX);
    }
}

// ---------------------------------------------------------------------------
// 0x53edc0 — observed shape
// Serializer save: run base at param_1, emit the property named by
// DAT_00727598 through the vector/stream at +8/+0xc/+0x14.
// ---------------------------------------------------------------------------
void FUN_0053edc0(int param_1)
{
    int iVar2 = param_1;

    FUN_00534d60(param_1);
    void* slot = FUN_00557b10(DAT_00727598);
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
    if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int32_t*>(iVar2 + 0x14) + static_cast<int>(uVar1));
    }
    FUN_005606f0(uVar1, &slot);
}

// ---------------------------------------------------------------------------
// 0x53ee20 — observed shape
// Free the reciprocal-square-root table pointer and clear the global.
// ---------------------------------------------------------------------------
void FUN_0053ee20(void)
{
    operator_delete__(DAT_007275a0);
    DAT_007275a0 = nullptr;
}

// ---------------------------------------------------------------------------
// 0x53ee40 — observed shape
// Normalize param_2 vectors of 3 floats each, stride param_3 bytes, using the
// exponent-halving/table-based reciprocal square root approximation backed by
// DAT_007275a0 (128-entry float table). Unrolled by four, then a scalar tail.
// ---------------------------------------------------------------------------
void FUN_0053ee40(float* param_1, uint32_t param_2, int param_3)
{
    // One reciprocal-square-root normalize on the 3-float record at p.
    auto normalizeOne = [](float* p) {
        float fVar1 = *p * *p + p[2] * p[2] + p[1] * p[1];
        if (fVar1 == 0.0f) {
            fVar1 = 0.0f;
        } else {
            FloatBits bits;
            bits.f = fVar1;
            uint32_t uVar4 = (bits.u >> 0x17) - 0x7f;
            uint32_t uVar3 = bits.u & 0x7fffff;
            if ((uVar4 & 1) != 0) {
                uVar3 = uVar3 | 0x800000;
            }
            int32_t halfExp = static_cast<int16_t>(static_cast<int16_t>(uVar4) >> 1) + 0x7f;
            uint32_t approxBits =
                static_cast<uint32_t>(halfExp) * 0x800000u |
                reinterpret_cast<uint32_t*>(DAT_007275a0)[uVar3 >> 0x10];
            FloatBits approx;
            approx.u = approxBits;
            fVar1 = 1.0 / approx.f;
        }
        *p = fVar1 * *p;
        p[1] = fVar1 * p[1];
        p[2] = fVar1 * p[2];
    };

    uint32_t uVar2 = 0;
    if (3 < static_cast<int32_t>(param_2)) {
        int32_t iVar5 = static_cast<int32_t>((param_2 - 4) >> 2) + 1;
        uVar2 = static_cast<uint32_t>(iVar5) * 4;
        do {
            normalizeOne(param_1);
            param_1 = reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(param_1) + param_3);
            normalizeOne(param_1);
            param_1 = reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(param_1) + param_3);
            normalizeOne(param_1);
            param_1 = reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(param_1) + param_3);
            normalizeOne(param_1);
            param_1 = reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(param_1) + param_3);
            iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
    }
    if (uVar2 < param_2) {
        int32_t iVar5 = static_cast<int32_t>(param_2 - uVar2);
        do {
            normalizeOne(param_1);
            param_1 = reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(param_1) + param_3);
            iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
    }
}

// ---------------------------------------------------------------------------
// 0x53f150 — observed shape
// Accumulate param_2-scaled 36-byte blocks of param_3 into the 36-byte blocks
// starting at param_1+0x14, in groups of four plus a scalar tail.
// ---------------------------------------------------------------------------
void FUN_0053f150(int param_1, float param_2, int param_3, uint32_t param_4)
{
    uint32_t uVar7 = 0;

    if (3 < static_cast<int32_t>(param_4)) {
        int32_t iVar6 = static_cast<int32_t>((param_4 - 4) >> 2) + 1;
        uVar7 = static_cast<uint32_t>(iVar6) * 4;
        float* pfVar4 = reinterpret_cast<float*>(param_1 + 0x14);
        float* pfVar5 = reinterpret_cast<float*>(param_3 + 0x20);
        do {
            float* pfVar3 = pfVar4 + 0xc;
            iVar6 = iVar6 + -1;
            float fVar1 = pfVar5[-7];
            float fVar2 = pfVar5[-6];
            pfVar4[-5] = param_2 * pfVar5[-8] + pfVar4[-5];
            pfVar4[-4] = param_2 * fVar1 + pfVar4[-4];
            pfVar4[-3] = param_2 * fVar2 + pfVar4[-3];
            fVar1 = *reinterpret_cast<float*>(
                static_cast<intptr_t>(param_3 - param_1) - 0x34 + reinterpret_cast<intptr_t>(pfVar3));
            fVar2 = *reinterpret_cast<float*>(
                static_cast<intptr_t>(param_3 - param_1) - 0x30 + reinterpret_cast<intptr_t>(pfVar3));
            pfVar4[-2] = param_2 * pfVar5[-5] + pfVar4[-2];
            pfVar4[-1] = param_2 * fVar1 + pfVar4[-1];
            *pfVar4 = param_2 * fVar2 + *pfVar4;
            fVar1 = pfVar5[-1];
            fVar2 = *pfVar5;
            pfVar4[1] = param_2 * pfVar5[-2] + pfVar4[1];
            pfVar4[2] = param_2 * fVar1 + pfVar4[2];
            pfVar4[3] = param_2 * fVar2 + pfVar4[3];
            fVar1 = pfVar5[2];
            fVar2 = pfVar5[3];
            pfVar4[4] = param_2 * pfVar5[1] + pfVar4[4];
            pfVar4[5] = param_2 * fVar1 + pfVar4[5];
            pfVar4[6] = param_2 * fVar2 + pfVar4[6];
            pfVar4 = pfVar3;
            pfVar5 = pfVar5 + 0xc;
        } while (iVar6 != 0);
    }
    if (uVar7 < param_4) {
        int32_t iVar6 = static_cast<int32_t>(param_4 - uVar7);
        float* pfVar4 = reinterpret_cast<float*>(uVar7 * 0xc + 8 + param_1);
        float* pfVar5 = reinterpret_cast<float*>(uVar7 * 0xc + param_3);
        do {
            float* pfVar3 = pfVar4 + 3;
            iVar6 = iVar6 + -1;
            float fVar1 = *reinterpret_cast<float*>(
                static_cast<intptr_t>(param_3 - param_1) - 0x10 + reinterpret_cast<intptr_t>(pfVar3));
            float fVar2 = *reinterpret_cast<float*>(
                static_cast<intptr_t>(param_3 - param_1) - 0xc + reinterpret_cast<intptr_t>(pfVar3));
            pfVar4[-2] = param_2 * *pfVar5 + pfVar4[-2];
            pfVar4[-1] = param_2 * fVar1 + pfVar4[-1];
            *pfVar4 = param_2 * fVar2 + *pfVar4;
            pfVar4 = pfVar3;
            pfVar5 = pfVar5 + 3;
        } while (iVar6 != 0);
    }
}

// ---------------------------------------------------------------------------
// 0x53f2c0 — observed shape
// Blend param_2 into the 36-byte blocks at param_1+0x14 from the 36-byte
// blocks at param_3+0x1c, in groups of four plus a scalar tail.
// ---------------------------------------------------------------------------
void FUN_0053f2c0(int param_1, float param_2, int param_3, uint32_t param_4)
{
    float fVar3 = 1.0f - param_2;
    uint32_t uVar7 = 0;

    if (3 < static_cast<int32_t>(param_4)) {
        int32_t iVar6 = static_cast<int32_t>((param_4 - 4) >> 2) + 1;
        uVar7 = static_cast<uint32_t>(iVar6) * 4;
        float* pfVar4 = reinterpret_cast<float*>(param_1 + 0x14);
        float* pfVar5 = reinterpret_cast<float*>(param_3 + 0x1c);
        do {
            float fVar1 = pfVar5[-6];
            float fVar2 = pfVar5[-5];
            pfVar4[-5] = fVar3 * pfVar5[-7] + param_2 * pfVar4[-5];
            pfVar4[-4] = fVar3 * fVar1 + param_2 * pfVar4[-4];
            pfVar4[-3] = fVar3 * fVar2 + param_2 * pfVar4[-3];
            fVar1 = pfVar5[-3];
            fVar2 = *reinterpret_cast<float*>(
                static_cast<intptr_t>(param_3 - param_1) + reinterpret_cast<intptr_t>(pfVar4));
            pfVar4[-2] = fVar3 * pfVar5[-4] + param_2 * pfVar4[-2];
            pfVar4[-1] = fVar3 * fVar1 + param_2 * pfVar4[-1];
            *pfVar4 = fVar3 * fVar2 + param_2 * *pfVar4;
            fVar1 = *pfVar5;
            fVar2 = pfVar5[1];
            pfVar4[1] = fVar3 * pfVar5[-1] + param_2 * pfVar4[1];
            pfVar4[2] = fVar3 * fVar1 + param_2 * pfVar4[2];
            iVar6 = iVar6 + -1;
            pfVar4[3] = fVar3 * fVar2 + param_2 * pfVar4[3];
            fVar1 = pfVar5[3];
            fVar2 = pfVar5[4];
            pfVar4[4] = fVar3 * pfVar5[2] + param_2 * pfVar4[4];
            pfVar4[5] = fVar3 * fVar1 + param_2 * pfVar4[5];
            pfVar4[6] = fVar3 * fVar2 + param_2 * pfVar4[6];
            pfVar4 = pfVar4 + 0xc;
            pfVar5 = pfVar5 + 0xc;
        } while (iVar6 != 0);
    }
    if (uVar7 < param_4) {
        int32_t iVar6 = static_cast<int32_t>(param_4 - uVar7);
        float* pfVar4 = reinterpret_cast<float*>(uVar7 * 0xc + 8 + param_1);
        float* pfVar5 = reinterpret_cast<float*>(uVar7 * 0xc + param_3);
        do {
            iVar6 = iVar6 + -1;
            float fVar1 = pfVar5[1];
            float fVar2 = *reinterpret_cast<float*>(
                static_cast<intptr_t>(param_3 - param_1) - 0xc +
                reinterpret_cast<intptr_t>(pfVar4 + 3));
            pfVar4[-2] = fVar3 * *pfVar5 + param_2 * pfVar4[-2];
            pfVar4[-1] = fVar3 * fVar1 + param_2 * pfVar4[-1];
            *pfVar4 = fVar3 * fVar2 + param_2 * *pfVar4;
            pfVar4 = pfVar4 + 3;
            pfVar5 = pfVar5 + 3;
        } while (iVar6 != 0);
    }
}

// ---------------------------------------------------------------------------
// 0x53f560 — observed shape
// Build "<name> = ALPHA_*" text into a fresh buffer sized strlen(name)+0x16.
// ---------------------------------------------------------------------------
char* FUN_0053f560(char* param_1, uint32_t param_2)
{
    char* pcVar2 = param_1;
    char cVar1;
    do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');

    int total = 0x16 + static_cast<int>(pcVar2 - (param_1 + 1));
    char* out = reinterpret_cast<char*>(thunk_FUN_00533c78(total));
    switch (param_2) {
    case 0:
        sprintf(out, "%s = ALPHA_ONE", param_1);
        return out;
    case 1:
        sprintf(out, "%s = ALPHA_ZERO", param_1);
        return out;
    case 2:
        sprintf(out, "%s = ALPHA_SRCCOLOR", param_1);
        return out;
    case 3:
        sprintf(out, "%s = ALPHA_INVSRCCOLOR", param_1);
        return out;
    case 4:
        sprintf(out, "%s = ALPHA_DESTCOLOR", param_1);
        return out;
    case 5:
        sprintf(out, "%s = ALPHA_INVDESTCOLOR", param_1);
        return out;
    case 6:
        sprintf(out, "%s = ALPHA_SRCALPHA", param_1);
        return out;
    case 7:
        sprintf(out, "%s = ALPHA_INVSRCALPHA", param_1);
        return out;
    case 8:
        sprintf(out, "%s = ALPHA_DESTALPHA", param_1);
        return out;
    case 9:
        sprintf(out, "%s = ALPHA_INVDESTALPHA", param_1);
        return out;
    case 10:
        sprintf(out, "%s = ALPHA_SRCALPHASAT", param_1);
    }
    return out;
}

// ---------------------------------------------------------------------------
// 0x53f6b0 — observed shape
// Build "<name> = TEST_*" text into a fresh buffer sized strlen(name)+0x16.
// ---------------------------------------------------------------------------
char* FUN_0053f6b0(char* param_1, uint32_t param_2)
{
    char* pcVar2 = param_1;
    char cVar1;
    do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');

    int total = 0x16 + static_cast<int>(pcVar2 - (param_1 + 1));
    char* out = reinterpret_cast<char*>(thunk_FUN_00533c78(total));
    switch (param_2) {
    case 0:
        sprintf(out, "%s = TEST_ALWAYS", param_1);
        return out;
    case 1:
        sprintf(out, "%s = TEST_LESS", param_1);
        return out;
    case 2:
        sprintf(out, "%s = TEST_EQUAL", param_1);
        return out;
    case 3:
        sprintf(out, "%s = TEST_LESSEQUAL", param_1);
        return out;
    case 4:
        sprintf(out, "%s = TEST_GREATER", param_1);
        return out;
    case 5:
        sprintf(out, "%s = TEST_NOTEQUAL", param_1);
        return out;
    case 6:
        sprintf(out, "%s = TEST_GREATEREQUAL", param_1);
        return out;
    case 7:
        sprintf(out, "%s = TEST_NEVER", param_1);
    }
    return out;
}

// ---------------------------------------------------------------------------
// 0x53f950 — observed shape
// Allocate a 0x24 object, init base + vtable PTR_FUN_0070bf4c, fields at
// +0x20 (0xec) and +0x22 (0), then swap it into singleton DAT_007275ac.
// ---------------------------------------------------------------------------
void FUN_0053f950(void)
{
    uint32_t* puVar3 = static_cast<uint32_t*>(FUN_00533c78(0x24));
    if (puVar3 == nullptr) {
        puVar3 = nullptr;
    } else {
        FUN_00540c50();
        *reinterpret_cast<void**>(puVar3) = &PTR_FUN_0070bf4c;
        *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(puVar3) + 0x20) = 0xec;
        *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(puVar3) + 0x22) = 0;
    }

    uint32_t* puVar2 = DAT_007275ac;
    if (DAT_007275ac != puVar3) {
        if (DAT_007275ac != nullptr) {
            int32_t iVar1 = static_cast<int32_t>(DAT_007275ac[1]);
            DAT_007275ac[1] = static_cast<uint32_t>(iVar1 - 1);
            if (iVar1 - 1 == 0) {
                CallVtableDestroy(puVar2);
            }
        }
        DAT_007275ac = puVar3;
        if (puVar3 != nullptr) {
            puVar3[1] = puVar3[1] + 1;
        }
    }
}

// ---------------------------------------------------------------------------
// 0x53f9b0 — observed shape
// Release singleton DAT_007275ac: decrement refcount, destroy at zero, clear.
// ---------------------------------------------------------------------------
void FUN_0053f9b0(void)
{
    uint32_t* puVar2 = DAT_007275ac;
    if (DAT_007275ac != nullptr) {
        int32_t iVar1 = static_cast<int32_t>(DAT_007275ac[1]);
        DAT_007275ac[1] = static_cast<uint32_t>(iVar1 - 1);
        if (iVar1 - 1 == 0) {
            CallVtableDestroy(puVar2);
        }
        DAT_007275ac = nullptr;
    }
}

// ---------------------------------------------------------------------------
// 0x53fd90 — observed shape
// Allocate a 0x28 object, init base + vtable PTR_FUN_0070bed4, fields at
// +0x20 (3) and +0x24 (3), then swap it into singleton DAT_007275b8.
// ---------------------------------------------------------------------------
void FUN_0053fd90(void)
{
    uint32_t* puVar3 = static_cast<uint32_t*>(FUN_00533c78(0x28));
    if (puVar3 == nullptr) {
        puVar3 = nullptr;
    } else {
        FUN_00540c50();
        *reinterpret_cast<void**>(puVar3) = &PTR_FUN_0070bed4;
        *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(puVar3) + 0x20) = 3;
        puVar3[9] = 3;
    }

    uint32_t* puVar2 = DAT_007275b8;
    if (DAT_007275b8 != puVar3) {
        if (DAT_007275b8 != nullptr) {
            int32_t iVar1 = static_cast<int32_t>(DAT_007275b8[1]);
            DAT_007275b8[1] = static_cast<uint32_t>(iVar1 - 1);
            if (iVar1 - 1 == 0) {
                CallVtableDestroy(puVar2);
            }
        }
        DAT_007275b8 = puVar3;
        if (puVar3 != nullptr) {
            puVar3[1] = puVar3[1] + 1;
        }
    }
}

// ---------------------------------------------------------------------------
// 0x53fdf0 — observed shape
// Release singleton DAT_007275b8: decrement refcount, destroy at zero, clear.
// ---------------------------------------------------------------------------
void FUN_0053fdf0(void)
{
    uint32_t* puVar2 = DAT_007275b8;
    if (DAT_007275b8 != nullptr) {
        int32_t iVar1 = static_cast<int32_t>(DAT_007275b8[1]);
        DAT_007275b8[1] = static_cast<uint32_t>(iVar1 - 1);
        if (iVar1 - 1 == 0) {
            CallVtableDestroy(puVar2);
        }
        DAT_007275b8 = nullptr;
    }
}

// ---------------------------------------------------------------------------
// 0x53fe20 — observed shape
// Serializer save: base save, then emit m_bZTest, m_bZWrite from bitfield
// self+0x20 and m_eTest indexed through the contiguous TEST_* name table.
// ---------------------------------------------------------------------------
void FUN_0053fe20(void* self_recon, int param_1)
{
    int in_ECX = static_cast<int>(reinterpret_cast<intptr_t>(self_recon));
    int iVar2 = param_1;

    FUN_00540410(param_1);
    void* slot = FUN_00557b10(DAT_007275b0);
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
    if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int32_t*>(iVar2 + 0x14) + static_cast<int>(uVar1));
    }
    FUN_005606f0(uVar1, &slot);

    slot = FUN_00557b50("m_bZTest", *reinterpret_cast<uint8_t*>(in_ECX + 0x20) & 1);
    uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
    if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int32_t*>(iVar2 + 0x14) + static_cast<int>(uVar1));
    }
    FUN_005606f0(uVar1, &slot);

    slot = FUN_00557b50("m_bZWrite", *reinterpret_cast<uint8_t*>(in_ECX + 0x20) >> 1 & 1);
    uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
    if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int32_t*>(iVar2 + 0x14) + static_cast<int>(uVar1));
    }
    FUN_005606f0(uVar1, &slot);

    // Eight contiguous name pointers observed as local_20[4] followed by
    // local_10/local_c/local_8/local_4.
    const char* local_20[8];
    local_20[0] = "TEST_ALWAYS";
    local_20[1] = "TEST_LESS";
    local_20[2] = "TEST_EQUAL";
    local_20[3] = "TEST_LESSEQUAL";
    local_20[4] = "TEST_GREATER";
    local_20[5] = "TEST_NOTEQUAL";
    local_20[6] = "TEST_GREATEREQUAL";
    local_20[7] = "TEST_NEVER";

    slot = FUN_00557d80("m_eTest", local_20[*reinterpret_cast<int32_t*>(in_ECX + 0x24)]);
    uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
    if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int32_t*>(iVar2 + 0x14) + static_cast<int>(uVar1));
    }
    FUN_005606f0(uVar1, &slot);
}

// ---------------------------------------------------------------------------
// 0x53ff70 — observed shape
// Build "<name> = SOURCE_*" text into a fresh buffer sized strlen(name)+0x1a.
// ---------------------------------------------------------------------------
char* FUN_0053ff70(char* param_1, int param_2)
{
    char* pcVar2 = param_1;
    char cVar1;
    do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');

    int total = 0x1a + static_cast<int>(pcVar2 - (param_1 + 1));
    char* out = reinterpret_cast<char*>(thunk_FUN_00533c78(total));
    if (param_2 == 0) {
        sprintf(out, "%s = SOURCE_IGNORE", param_1);
    } else {
        if (param_2 == 1) {
            sprintf(out, "%s = SOURCE_EMISSIVE", param_1);
            return out;
        }
        if (param_2 == 2) {
            sprintf(out, "%s = SOURCE_AMB_DIFF", param_1);
            return out;
        }
    }
    return out;
}

// ---------------------------------------------------------------------------
// 0x53fff0 — observed shape
// Build "<name> = LIGHTING_*" text into a fresh buffer sized strlen(name)+0x1a.
// ---------------------------------------------------------------------------
char* FUN_0053fff0(char* param_1, int param_2)
{
    char* pcVar2 = param_1;
    char cVar1;
    do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');

    int total = 0x1a + static_cast<int>(pcVar2 - (param_1 + 1));
    char* out = reinterpret_cast<char*>(thunk_FUN_00533c78(total));
    if (param_2 == 0) {
        sprintf(out, "%s = LIGHTING_E", param_1);
    } else if (param_2 == 1) {
        sprintf(out, "%s = LIGHTING_E_A_D", param_1);
        return out;
    }
    return out;
}

// ---------------------------------------------------------------------------
// 0x5401f0 — observed shape
// Allocate a 0x2c object, init base + vtable PTR_FUN_0070bf10, fields at
// +0x20 (0), +0x24 (0), +0x28 (1), then swap it into singleton DAT_007275c4.
// ---------------------------------------------------------------------------
void FUN_005401f0(void)
{
    uint32_t* puVar3 = static_cast<uint32_t*>(FUN_00533c78(0x2c));
    if (puVar3 == nullptr) {
        puVar3 = nullptr;
    } else {
        FUN_00540c50();
        *reinterpret_cast<void**>(puVar3) = &PTR_FUN_0070bf10;
        *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(puVar3) + 0x20) = 0;
        puVar3[9] = 0;
        puVar3[10] = 1;
    }

    uint32_t* puVar2 = DAT_007275c4;
    if (DAT_007275c4 != puVar3) {
        if (DAT_007275c4 != nullptr) {
            int32_t iVar1 = static_cast<int32_t>(DAT_007275c4[1]);
            DAT_007275c4[1] = static_cast<uint32_t>(iVar1 - 1);
            if (iVar1 - 1 == 0) {
                CallVtableDestroy(puVar2);
            }
        }
        DAT_007275c4 = puVar3;
        if (puVar3 != nullptr) {
            puVar3[1] = puVar3[1] + 1;
        }
    }
}

// ---------------------------------------------------------------------------
// 0x540260 — observed shape
// Release singleton DAT_007275c4: decrement refcount, destroy at zero, clear.
// ---------------------------------------------------------------------------
void FUN_00540260(void)
{
    uint32_t* puVar2 = DAT_007275c4;
    if (DAT_007275c4 != nullptr) {
        int32_t iVar1 = static_cast<int32_t>(DAT_007275c4[1]);
        DAT_007275c4[1] = static_cast<uint32_t>(iVar1 - 1);
        if (iVar1 - 1 == 0) {
            CallVtableDestroy(puVar2);
        }
        DAT_007275c4 = nullptr;
    }
}

// ---------------------------------------------------------------------------
// 0x5403d0 — observed shape
// Base deserialize, then for pre-0xa000102 objects read two bytes through the
// vtable slot +8 of the object at +0x15c and store the ESI register artifact
// into DAT_007275c8.
// ---------------------------------------------------------------------------
void FUN_005403d0(int param_1, uint16_t unaff_SI)
{
    int iVar1 = param_1;

    FUN_00540aa0(param_1);
    if (*reinterpret_cast<uint32_t*>(iVar1 + 0x1c) < 0xa000102) {
        typedef void (*ReadFn)(uint32_t self, int* dst, int count);
        uint32_t obj = *reinterpret_cast<uint32_t*>(iVar1 + 0x15c);
        uint32_t objVtbl = *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(obj));
        reinterpret_cast<ReadFn>(*reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(objVtbl) + 8))(
            obj, &param_1, 2);
        DAT_007275c8 = unaff_SI;
    }
}

// ---------------------------------------------------------------------------
// 0x540410 — observed shape
// Serializer save: base save, then emit the property named by DAT_007275cc
// through the vector/stream at +8/+0xc/+0x14.
// ---------------------------------------------------------------------------
void FUN_00540410(int param_1)
{
    int iVar2 = param_1;

    FUN_00541080(param_1);
    void* slot = FUN_00557b10(DAT_007275cc);
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
    if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
        FUN_006b34a0(*reinterpret_cast<int32_t*>(iVar2 + 0x14) + static_cast<int>(uVar1));
    }
    FUN_005606f0(uVar1, &slot);
}
