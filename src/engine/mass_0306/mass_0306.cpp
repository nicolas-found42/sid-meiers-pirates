// Clean-room reconstruction from shipped bytes (Ghidra 12.2 corpus only).
// Batch mass_0306 — addresses 0x6539fb .. 0x6549a0.
// No byte-match claim: status unverified. FUN_*/LAB_*/DAT_* are corpus labels;
// types, struct layouts and parameter names are inferred from the listings.
// PE32 i386, image base 0x400000 per corpus addresses.

#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <string.h>
#include <math.h>

// ---- Symbols referenced only as code/data addresses (corpus labels) ----
extern void FUN_0068515d(), FUN_006851d8(), FUN_006853b7(), FUN_006854e3(),
            FUN_00685523(), FUN_0068557c(), FUN_006855b5(), FUN_00685649(),
            FUN_006857ac(), FUN_00685848(), FUN_006858fc(), FUN_00685983(),
            FUN_00685a2a(), FUN_00685adf(), FUN_00685b7b(), FUN_00685c03(),
            FUN_00685c5f(), FUN_00685ca7(), FUN_00685cf8(), FUN_006866b4(),
            FUN_00686780(), FUN_00686847(), FUN_00687743(), FUN_00688484(),
            FUN_00688558(), FUN_00688618(), FUN_0068874e(), FUN_006887e2(),
            FUN_006890b4();
extern void FUN_00689200(), FUN_006892c0(), FUN_00689a00(), FUN_0068a132(),
            FUN_0068a66c(), FUN_0068a6d8(), FUN_0068a80f(), FUN_0068a89c(),
            FUN_0068a992(), FUN_0068aade(), FUN_0068bd8e(), FUN_0068cf8a(),
            FUN_0068d663(), FUN_0068d77e(), FUN_0068e936(), FUN_0068f346(),
            FUN_0068f364(), FUN_0068f3d7(), FUN_0068f440(), FUN_0068f924(),
            FUN_0068f92f(), FUN_0068fcd8(), FUN_0068fe80(), FUN_0069013b(),
            FUN_00690192(), FUN_006901cd(), FUN_00690402(), FUN_00690a15();
extern void FUN_00691120(int*), FUN_006916f0(int*), FUN_00692220(int*),
            FUN_006562f0(int*);

extern void LAB_00685274(), LAB_006852f8(), LAB_006856eb(), LAB_00685da8(),
            LAB_00685e80(), LAB_00685f6c(), LAB_00686064(), LAB_0068613c(),
            LAB_00686aa1(), LAB_00686c74(), LAB_00686df4(), LAB_00686f50(),
            LAB_00687061(), LAB_00687415(), LAB_00687819(), LAB_006879ec(),
            LAB_00687b6c(), LAB_00687cc8(), LAB_00687dd9(), LAB_00687fd9(),
            LAB_0068818d(), LAB_00688884(), LAB_00688b30(), LAB_00688c78(),
            LAB_00688d39(), LAB_00688e25(), LAB_00688f1d(), LAB_00688ff5(),
            LAB_00689380(), LAB_006895e0(), LAB_00689840(), LAB_00689aa0(),
            LAB_00689dc0(), LAB_0068a03c(), LAB_0068a0d5(), LAB_0068a176(),
            LAB_0068a392(), LAB_0068a5a7(), LAB_0068a92e(), LAB_0068aa39(),
            LAB_0068b519(), LAB_0068b74b(), LAB_0068b81a(), LAB_0068b86a(),
            LAB_0068b955(), LAB_0068ba31(), LAB_0068ba96(), LAB_0068baf6(),
            LAB_0068bb51(), LAB_0068bb98(), LAB_0068bc07(), LAB_0068bcd9(),
            LAB_0068d12f(), LAB_0068ec18(), LAB_0068f49f(), LAB_0068f510(),
            LAB_0068f5e4(), LAB_0068fabb(), LAB_0068ffc0(), LAB_00690233(),
            LAB_006902cb(), LAB_00690314(), LAB_00690357(), LAB_00690486(),
            LAB_006904e5(), LAB_00690619(), LAB_0069068a(), LAB_00690752(),
            LAB_00690830(), LAB_00690873(), LAB_00690957(), LAB_00690a79();

// Data label used as a call slot in the 0x6539fb table (corpus label).
extern char DAT_00687261;
// 8-byte-stride float pair table used by the fast reciprocal routines.
extern uint8_t DAT_0071ed80[];

// x87 intrinsic helpers referenced by 0x653cd7 (corpus callee labels).
extern "C" uint32_t* __cdecl cpuid_basic_info(uint32_t);
extern "C" uint32_t* __cdecl cpuid_Version_info(uint32_t);
extern "C" uint32_t* __cdecl cpuid(uint32_t);
extern "C" char*     __cdecl builtin_strncpy(char*, const char*, size_t);

static inline float    as_float(uint32_t bits) { float f; memcpy(&f, &bits, 4); return f; }
static inline uint32_t as_bits(float f)        { uint32_t b; memcpy(&b, &f, 4); return b; }

// 0x6539fb — observed shape: fills a 0x48-slot dispatch table with code
// pointers; slot 0x41 receives a data label (DAT_00687261) and slot 0x2d is
// written last. No other side effects, no return value.
void FUN_006539fb(void** self)
{
    self[2]    = (void*)&FUN_00688558;
    self[0x23] = (void*)&FUN_00688558;
    self[0]    = (void*)&FUN_006854e3;
    self[1]    = (void*)&FUN_00686780;
    self[3]    = (void*)&FUN_00688618;
    self[4]    = (void*)&LAB_00688b30;
    self[5]    = (void*)&FUN_0068557c;
    self[6]    = (void*)&FUN_006866b4;
    self[9]    = (void*)&FUN_00685523;
    self[10]   = (void*)&FUN_00686847;
    self[7]    = (void*)&FUN_006855b5;
    self[8]    = (void*)&FUN_006857ac;
    self[0x16] = (void*)&FUN_00685649;
    self[0x11] = (void*)&LAB_006856eb;
    self[0x15] = (void*)&FUN_006851d8;
    self[0x14] = (void*)&FUN_0068515d;
    self[0x19] = (void*)&FUN_006853b7;
    self[0x1a] = (void*)&LAB_006852f8;
    self[0x17] = (void*)&FUN_00685cf8;
    self[0x13] = (void*)&LAB_00688884;
    self[0x32] = (void*)&FUN_00685a2a;
    self[0x33] = (void*)&FUN_00685848;
    self[0x34] = (void*)&FUN_00685c03;
    self[0x35] = (void*)&FUN_00685adf;
    self[0x36] = (void*)&FUN_00685983;
    self[0x37] = (void*)&FUN_00685c5f;
    self[0x12] = (void*)&FUN_00685b7b;
    self[0x30] = (void*)&FUN_006858fc;
    self[0x31] = (void*)&FUN_00685ca7;
    self[0xb]  = (void*)&LAB_00685da8;
    self[0x1c] = (void*)&LAB_00685f6c;
    self[0xe]  = (void*)&LAB_00685e80;
    self[0x1d] = (void*)&LAB_00686064;
    self[0x3b] = (void*)&FUN_00687743;
    self[0x3c] = (void*)&LAB_00686c74;
    self[0x3d] = (void*)&LAB_00686df4;
    self[0x3e] = (void*)&LAB_00686f50;
    self[0x3f] = (void*)&LAB_00686aa1;
    self[0x40] = (void*)&LAB_00687415;
    self[0x41] = (void*)&DAT_00687261;
    self[0x42] = (void*)&LAB_00687061;
    self[0x45] = (void*)&LAB_00687061;
    self[0x47] = (void*)&LAB_0068613c;
    self[0x2d] = (void*)&LAB_00685274;
}

// 0x653b6e — observed shape: same 0x48-slot dispatch-table fill as 0x6539fb,
// with a different callee set at slots 7, 0x16, 0x11, 0x19, 0x1a, 0x1c, 0xe,
// 0x1d, 0x3b..0x45; slot 0x41 is a code label here and 0x2d is not written.
void FUN_00653b6e(void** self)
{
    self[2]    = (void*)&FUN_00688558;
    self[0x23] = (void*)&FUN_00688558;
    self[0]    = (void*)&FUN_006854e3;
    self[1]    = (void*)&FUN_00686780;
    self[3]    = (void*)&FUN_00688618;
    self[4]    = (void*)&LAB_00688b30;
    self[5]    = (void*)&FUN_0068557c;
    self[6]    = (void*)&FUN_006866b4;
    self[9]    = (void*)&FUN_00685523;
    self[10]   = (void*)&FUN_00686847;
    self[7]    = (void*)&FUN_0068874e;
    self[8]    = (void*)&FUN_006857ac;
    self[0x16] = (void*)&FUN_006887e2;
    self[0x11] = (void*)&LAB_00688c78;
    self[0x15] = (void*)&FUN_006851d8;
    self[0x14] = (void*)&FUN_0068515d;
    self[0x19] = (void*)&FUN_006890b4;
    self[0x1a] = (void*)&LAB_00688ff5;
    self[0x17] = (void*)&FUN_00685cf8;
    self[0x13] = (void*)&LAB_00688884;
    self[0x32] = (void*)&FUN_00685a2a;
    self[0x33] = (void*)&FUN_00685848;
    self[0x34] = (void*)&FUN_00685c03;
    self[0x35] = (void*)&FUN_00685adf;
    self[0x36] = (void*)&FUN_00685983;
    self[0x37] = (void*)&FUN_00685c5f;
    self[0x12] = (void*)&FUN_00685b7b;
    self[0x30] = (void*)&FUN_006858fc;
    self[0x31] = (void*)&FUN_00685ca7;
    self[0xb]  = (void*)&LAB_00685da8;
    self[0x1c] = (void*)&LAB_00688e25;
    self[0xe]  = (void*)&LAB_00688d39;
    self[0x1d] = (void*)&LAB_00688f1d;
    self[0x3b] = (void*)&FUN_00688484;
    self[0x3c] = (void*)&LAB_006879ec;
    self[0x3d] = (void*)&LAB_00687b6c;
    self[0x3e] = (void*)&LAB_00687cc8;
    self[0x3f] = (void*)&LAB_00687819;
    self[0x40] = (void*)&LAB_0068818d;
    self[0x41] = (void*)&LAB_00687fd9;
    self[0x42] = (void*)&LAB_00687dd9;
    self[0x45] = (void*)&LAB_00687dd9;
    self[0x47] = (void*)&LAB_0068613c;
}

// 0x653cd7 — observed shape: CPUID feature query. Result is an x87 pair packed
// into EDX:EAX: high dword = capability word (vendor/model/feature bits),
// low dword = feature flag mask. A 12-byte vendor string compare against
// "AuthenticAMD" is performed but its result is not consumed by the caller
// path Ghidra recovered (dead compare preserved as observed).
uint64_t FUN_00653cd7(void)
{
    char     local_2c[16];
    int      local_1c;   // vendor string dwords: EBX, ECX, EDX (12 bytes)
    uint32_t local_18;
    int      local_14;
    char     cStack_10;
    uint32_t local_c;
    uint32_t local_8;

    cStack_10 = '\0';
    builtin_strncpy(local_2c, "AuthenticAMD", 0xd);
    cpuid_basic_info(0);
    local_8 = 1;

    uint32_t* piVar7 = cpuid_basic_info(0);
    local_18 = piVar7[2];
    local_1c = (int)piVar7[1];
    local_14 = (int)piVar7[3];

    if (*piVar7 != 0) {
        uint32_t* puVar2 = cpuid_Version_info(1);
        local_c = *puVar2;
        local_8 = (-(uint32_t)((puVar2[2] & 0x800000) != 0) & 0x20) | 3 |
                  (-(uint32_t)((puVar2[2] & 0x2000000) != 0) & 0x40);

        uint32_t* puVar3 = cpuid(0x80000000);
        local_18 = puVar3[2];
        if (0x80000000u < *puVar3) {
            uint32_t* eax = cpuid(0x80000001);
            local_18 = eax[2];
            local_8 = local_8 | 4 |
                      (-(uint32_t)((local_18 & 0x80000000u) != 0) & 0x80);

            int   iVar5 = 0xc;
            char* pcVar6 = local_2c;
            char* piVar  = (char*)&local_1c;
            int   iVar4 = 0;
            char  cVar1 = 0;
            do {
                if (iVar5 == 0) break;
                iVar5 = iVar5 + -1;
                iVar4 = *(int*)piVar;
                cVar1 = *pcVar6;
                pcVar6 = pcVar6 + 1;
                piVar  = piVar + 1;
            } while (cVar1 == (char)iVar4);

            local_8 = local_8 |
                      (-(uint32_t)((local_18 & 0x40000000u) != 0) & 0x100) |
                      (-(uint32_t)((local_18 & 0x400000u) != 0) & 0x200);
        }
    }
    return ((uint64_t)local_18 << 32) | (uint64_t)local_8;
}

// 0x653dbd — observed shape: dispatches on the low byte of the 0x653cd7 feature
// word. Bit 5 selects the SSEn/AMD code-pointer table; the sign bit (bit 7)
// gates it. AH of the same return value (bits 8..9, preserved from the
// register) selects an additional 5-slot override group. Bit 6 independently
// installs the 0x3c..0x45 group.
void FUN_00653dbd(void** self)
{
    uint64_t feat = FUN_00653cd7();
    uint8_t  bVar1 = (uint8_t)feat;
    uint8_t extraout_AH = (uint8_t)(feat >> 8);

    if (((bVar1 & 0x20) != 0) && ((int8_t)bVar1 < 0)) {
        self[0]    = (void*)&FUN_0069013b;
        self[1]    = (void*)&FUN_0068f364;
        self[2]    = (void*)&FUN_00690402;
        self[3]    = (void*)&LAB_0068b519;
        self[5]    = (void*)&FUN_00690192;
        self[6]    = (void*)&FUN_0068f3d7;
        self[7]    = (void*)&FUN_0068f440;
        self[8]    = (void*)&LAB_00690486;
        self[9]    = (void*)&FUN_006901cd;
        self[10]   = (void*)&FUN_0068f924;
        self[0xb]  = (void*)&LAB_0068b74b;
        self[0xd]  = (void*)&LAB_00690830;
        self[0xe]  = (void*)&LAB_00690873;
        self[0xf]  = (void*)&FUN_0068f92f;
        self[0x10] = (void*)&LAB_0068fabb;
        self[0x11] = (void*)&LAB_006904e5;
        self[0x12] = (void*)&LAB_00690233;
        self[0x13] = (void*)&FUN_0068f346;
        self[0x14] = (void*)&LAB_0068a03c;
        self[0x15] = (void*)&LAB_0068a0d5;
        self[0x16] = (void*)&FUN_00690a15;
        self[0x17] = (void*)&LAB_00690957;
        self[0x18] = (void*)&FUN_0068a132;
        self[0x19] = (void*)&LAB_0068a176;
        self[0x1a] = (void*)&LAB_0068a5a7;
        self[0x1b] = (void*)&LAB_0068b81a;
        self[0x1c] = (void*)&LAB_0068b86a;
        self[0x1d] = (void*)&LAB_0068b955;
        self[0x1e] = (void*)&FUN_0068a66c;
        self[0x1f] = (void*)&LAB_0068ba31;
        self[0x20] = (void*)&LAB_0068ba96;
        self[0x21] = (void*)&LAB_0068baf6;
        self[0x22] = (void*)&LAB_0068bb51;
        self[0x23] = (void*)&LAB_00690a79;
        self[0x24] = (void*)&FUN_0068a6d8;
        self[0x25] = (void*)&FUN_0068a80f;
        self[0x26] = (void*)&LAB_0068bb98;
        self[0x27] = (void*)&LAB_0068bc07;
        self[0x28] = (void*)&FUN_0068bd8e;
        self[0x29] = (void*)&FUN_0068cf8a;
        self[0x2a] = (void*)&LAB_0068d12f;
        self[0x2b] = (void*)&FUN_0068d663;
        self[0x2c] = (void*)&FUN_0068a89c;
        self[0x2d] = (void*)&LAB_0068a92e;
        self[0x37] = (void*)&LAB_00690619;
        self[0x34] = (void*)&LAB_0068f49f;
        self[0x31] = (void*)&LAB_006902cb;
        self[0x2f] = (void*)&LAB_00690314;
        self[0x35] = (void*)&LAB_0069068a;
        self[0x32] = (void*)&LAB_0068f510;
        self[0x38] = (void*)&FUN_0068a992;
        self[0x39] = (void*)&LAB_0068aa39;
        self[0x36] = (void*)&LAB_00690752;
        self[0x30] = (void*)&LAB_00690357;
        self[0x33] = (void*)&LAB_0068f5e4;
        self[4]    = (void*)&LAB_0068ec18;
        self[0x2e] = (void*)&FUN_0068aade;
        self[0x3b] = (void*)&FUN_0068fe80;
        self[0x3a] = (void*)&LAB_0068ffc0;

        if (((extraout_AH & 1) != 0) && ((extraout_AH & 2) != 0)) {
            self[0x10] = (void*)&FUN_0068fcd8;
            self[0x13] = (void*)&FUN_0068e936;
            self[0x27] = (void*)&LAB_0068bcd9;
            self[0x28] = (void*)&FUN_0068d77e;
            self[0x19] = (void*)&LAB_0068a392;
        }
    }
    if ((bVar1 & 0x40) != 0) {
        self[0x3f] = (void*)&FUN_00689a00;
        self[0x40] = (void*)&LAB_00689aa0;
        self[0x41] = (void*)&LAB_00689dc0;
        self[0x3c] = (void*)&LAB_00689380;
        self[0x3d] = (void*)&LAB_006895e0;
        self[0x3e] = (void*)&LAB_00689840;
        self[0x42] = (void*)&FUN_006892c0;
        self[0x45] = (void*)&FUN_00689200;
    }
}

// 0x654053 — observed shape: affine transform of a 2-float input against a
// 16-float (4x4) matrix: out[i] = matrix[0xc+i] + v[1]*matrix[4+i]
//                                     + v[0]*matrix[i], with the columns
// swapped per the listing (row0 uses matrix[0..2], row1 [4..6], etc.).
float* FUN_00654053(float* param_1, float* param_2, float* param_3)
{
    *param_1 = param_3[0xc] + param_2[1] * param_3[4] + *param_2 * *param_3;
    param_1[1] = param_3[0xd] + param_2[1] * param_3[5] + *param_2 * param_3[1];
    param_1[2] = param_3[0xe] + param_2[1] * param_3[6] + *param_2 * param_3[2];
    param_1[3] = param_3[0xf] + param_2[1] * param_3[7] + *param_2 * param_3[3];
    return param_1;
}

// 0x6540be — observed shape: 2-component affine transform (translation column
// absent): out[i] = v[1]*matrix[4+i] + v[0]*matrix[i].
float* FUN_006540be(float* param_1, float* param_2, float* param_3)
{
    *param_1 = param_2[1] * param_3[4] + *param_2 * *param_3;
    param_1[1] = param_2[1] * param_3[5] + *param_2 * param_3[1];
    return param_1;
}

// 0x6540f5 — observed shape: 3-component affine transform; out[i] =
// matrix[0xc+i] + v[2]*matrix[8+i] + v[1]*matrix[4+i] + v[0]*matrix[i].
float* FUN_006540f5(float* param_1, float* param_2, float* param_3)
{
    *param_1 = param_3[0xc] + param_2[2] * param_3[8] + param_2[1] * param_3[4]
             + *param_2 * *param_3;
    param_1[1] = param_3[0xd] + param_2[2] * param_3[9] + param_2[1] * param_3[5]
               + *param_2 * param_3[1];
    param_1[2] = param_3[0xe] + param_2[2] * param_3[10] + param_2[1] * param_3[6]
               + *param_2 * param_3[2];
    param_1[3] = param_3[0xf] + param_2[2] * param_3[0xb] + param_2[1] * param_3[7]
               + *param_2 * param_3[3];
    return param_1;
}

// 0x654182 — observed shape: 3-component linear transform without translation
// column; out[i] = v[2]*matrix[8+i] + v[1]*matrix[4+i] + v[0]*matrix[i].
float* FUN_00654182(float* param_1, float* param_2, float* param_3)
{
    *param_1 = param_2[2] * param_3[8] + param_2[1] * param_3[4] + *param_2 * *param_3;
    param_1[1] = param_2[2] * param_3[9] + param_2[1] * param_3[5] + *param_2 * param_3[1];
    param_1[2] = param_2[2] * param_3[10] + param_2[1] * param_3[6] + *param_2 * param_3[2];
    return param_1;
}

// 0x6541e3 — observed shape: full 4x4 matrix times 4-vector; out[i] =
// v[3]*matrix[0xc+i] + v[2]*matrix[8+i] + v[1]*matrix[4+i] + v[0]*matrix[i].
float* FUN_006541e3(float* param_1, float* param_2, float* param_3)
{
    *param_1 = param_2[3] * param_3[0xc] + param_2[2] * param_3[8]
             + param_2[1] * param_3[4] + *param_2 * *param_3;
    param_1[1] = param_2[3] * param_3[0xd] + param_2[2] * param_3[9]
               + param_2[1] * param_3[5] + *param_2 * param_3[1];
    param_1[2] = param_2[3] * param_3[0xe] + param_2[2] * param_3[10]
               + param_2[1] * param_3[6] + *param_2 * param_3[2];
    param_1[3] = param_2[3] * param_3[0xf] + param_2[2] * param_3[0xb]
               + param_2[1] * param_3[7] + *param_2 * param_3[3];
    return param_1;
}

// 0x65427e — observed shape: fast reciprocal-square-root style magnitude
// decode over an IEEE-754 bit pattern. The 0xff8-scaled table index selects a
// 2-float entry at DAT_0071ed80; the second factor re-encodes the exponent field
// of (0xbeffffff - bits) >> 1 & 0xff800000. Returns an x87 80-bit value.
long double FUN_0065427e(uint32_t param_1)
{
    uint32_t uVar1 = (param_1 >> 0xc) & 0xff8;
    float    f     = as_float((param_1 & 0xffffff) | 0x3f000000);
    float    g     = as_float(((0xbeffffffu - param_1) >> 1) & 0xff800000);
    return ((long double)f * *(float*)(DAT_0071ed80 + uVar1)
            + *(float*)(DAT_0071ed80 + uVar1 + 4)) * (long double)g;
}

// 0x6542c3 — observed shape: normalizes a 3-vector. Zero input yields a zero
// vector; a magnitude whose float bit pattern is within 1e-5 of 1.0 is copied
// (unless in-place); otherwise the vector is scaled by the reciprocal-sqrt
// approximation built from DAT_0071ed80 and the exponent of fVar1.
float* FUN_006542c3(float* param_1, float* param_2)
{
    long double fVar5 = (long double)*param_2 * (long double)*param_2
                      + (long double)param_2[1] * (long double)param_2[1]
                      + (long double)param_2[2] * (long double)param_2[2];
    float fVar1 = (float)fVar5;

    if (fVar1 == 0.0f) {
        *param_1 = 0.0f;
        param_1[1] = 0.0f;
        param_1[2] = 0.0f;
    } else if (as_bits(fabsf((float)(fVar5 - 1.0L))) < 0x3727c5ad) {
        if (param_1 != param_2) {
            *param_1 = *param_2;
            param_1[1] = param_2[1];
            param_1[2] = param_2[2];
        }
    } else {
        uint32_t uVar4 = (uint32_t)fVar1 >> 0xc & 0xff8;
        float fVar3 = (as_float(((uint32_t)fVar1 & 0xffffff) | 0x3f000000)
                       * *(float*)(DAT_0071ed80 + uVar4)
                       + *(float*)(DAT_0071ed80 + uVar4 + 4))
                    * as_float(((0xbeffffffu - (uint32_t)(int32_t)fVar1) >> 1) & 0xff800000);
        *param_1 = *param_2 * fVar3;
        param_1[1] = param_2[1] * fVar3;
        param_1[2] = param_2[2] * fVar3;
    }
    return param_1;
}

// 0x65438f — observed shape: 4x4 matrix multiply, param_1 = param_2 * param_3.
// Fast path: when param_3 aliases the destination and param_2 does not, the
// outer loop is transposed (destination rows advance by one float, source
// columns by one float). When all three alias, param_3 is first copied to a
// 16-float stack buffer. Main path multiplies rows of param_2 by columns of
// param_3 (stride 4) into 4-float destination rows.
void FUN_0065438f(float* param_1, float* param_2, float* param_3)
{
    float local_44[16];

    if (param_3 == param_1) {
        if (param_2 != param_1) {
            int iVar6 = -4;
            do {
                int   iVar5 = -0x10;
                float fVar1 = param_3[iVar6 + 4];
                float fVar2 = param_3[iVar6 + 8];
                float fVar3 = param_3[iVar6 + 0xc];
                float fVar4 = param_3[iVar6 + 0x10];
                do {
                    param_1[iVar5 + 0x10] =
                        (float)((long double)fVar4 * (long double)param_2[iVar5 + 0x13]
                              + (long double)fVar2 * (long double)param_2[iVar5 + 0x11]
                              + (long double)fVar1 * (long double)param_2[iVar5 + 0x10]
                              + (long double)fVar3 * (long double)param_2[iVar5 + 0x12]);
                    iVar5 = iVar5 + 4;
                } while (iVar5 != 0);
                param_1 = param_1 + 1;
                iVar6 = iVar6 + 1;
            } while (iVar6 != 0);
            return;
        }
        float* pfVar7 = local_44;
        for (int iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
            *pfVar7 = *param_3;
            param_3 = param_3 + 1;
            pfVar7 = pfVar7 + 1;
        }
        param_3 = local_44;
    }

    int iVar6 = -4;
    do {
        int   iVar5 = -4;
        float fVar1 = *param_2;
        float fVar2 = param_2[1];
        float fVar3 = param_2[2];
        float fVar4 = param_2[3];
        do {
            param_1[iVar5 + 4] =
                (float)((long double)fVar4 * (long double)param_3[iVar5 + 0x10]
                      + (long double)fVar2 * (long double)param_3[iVar5 + 8]
                      + (long double)fVar1 * (long double)param_3[iVar5 + 4]
                      + (long double)fVar3 * (long double)param_3[iVar5 + 0xc]);
            iVar5 = iVar5 + 1;
        } while (iVar5 != 0);
        param_2 = param_2 + 4;
        param_1 = param_1 + 4;
        iVar6 = iVar6 + 1;
    } while (iVar6 != 0);
}

// 0x654474 — observed shape: same 4x4 product as 0x65438f but always writes to
// a 17-float stack staging buffer when param_1 aliases either source, copying
// the 16 results back to param_1 afterwards.
void FUN_00654474(float* param_1, float* param_2, float* param_3)
{
    float  local_48[17];
    float* pfVar5;

    if ((param_1 == param_2) || (pfVar5 = param_1, param_1 == param_3)) {
        pfVar5 = local_48;
    }
    int iVar8 = -4;
    do {
        int    iVar7  = -4;
        float* pfVar6 = pfVar5 + iVar8 + 4;
        float  fVar1 = *param_2;
        float  fVar2 = param_2[1];
        float  fVar3 = param_2[2];
        float  fVar4 = param_2[3];
        do {
            *pfVar6 = (float)((long double)fVar4 * (long double)param_3[iVar7 + 0x10]
                            + (long double)fVar2 * (long double)param_3[iVar7 + 8]
                            + (long double)fVar1 * (long double)param_3[iVar7 + 4]
                            + (long double)fVar3 * (long double)param_3[iVar7 + 0xc]);
            pfVar6 = pfVar6 + 4;
            iVar7 = iVar7 + 1;
        } while (iVar7 != 0);
        param_2 = param_2 + 4;
        iVar8 = iVar8 + 1;
    } while (iVar8 != 0);

    if (pfVar5 != param_1) {
        for (int iVar8b = 0x10; iVar8b != 0; iVar8b = iVar8b + -1) {
            *param_1 = *pfVar5;
            pfVar5 = pfVar5 + 1;
            param_1 = param_1 + 1;
        }
    }
}

// 0x654504 — observed shape: fills the math dispatch table (8 entries plus the
// slot-0x23 duplicate of the 4x4 multiply).
void FUN_00654504(void** self)
{
    self[0]    = (void*)&FUN_00654053;
    self[1]    = (void*)&FUN_006540f5;
    self[2]    = (void*)&FUN_006541e3;
    self[3]    = (void*)&FUN_0065438f;
    self[4]    = (void*)&FUN_00654474;
    self[5]    = (void*)&FUN_006540be;
    self[6]    = (void*)&FUN_00654182;
    self[7]    = (void*)&FUN_006542c3;
    self[0x23] = (void*)&FUN_006541e3;
}

// 0x654550 — observed shape: releases the 0xcc "stream finished" state. The
// receiver arrives in ESI and is modelled as self. When state != 0xcc it calls
// through self[0x6a] (flush/detach hook), clears progress (self[0x23]) and
// enters state 0xcc. Then, while the hook's +8 counter is non-zero, it writes
// 0x30 to vtable slot 5 and redispatches through vtable slot 0. Final state is
// 0xcd, or 0xce when self[0x11] is non-zero. Always returns 1.
int FUN_00654550(int* self)
{
    if (self[5] != 0xcc) {
        (*(void (**)())(uintptr_t)self[0x6a])();
        self[0x23] = 0;
        self[5] = 0xcc;
    }
    int iVar1 = *(int*)(self[0x6a] + 8);
    while (iVar1 != 0) {
        uint32_t* puVar2 = (uint32_t*)*self;
        puVar2[5] = 0x30;
        ((void (*)())(uintptr_t)*puVar2)();
        iVar1 = *(int*)(self[0x6a] + 8);
    }
    self[5] = (self[0x11] != 0) + 0xcd;
    return 1;
}

// 0x6545c0 — observed shape: consumes up to self[0x1d] bytes at offset
// self[0x23]. A non-0xcd state first reports an "unexpected state" (0x14) with
// the old state. If the read offset already reached self[0x1d] it raises 0x7b
// with -1 and returns 0. Otherwise it publishes the window {begin, end} through
// the self[2] callback, calls self[0x6b]+4 to fetch a slice and advances the
// offset by the produced count.
int FUN_006545c0(int* param_1, uint32_t param_2, uint32_t param_3)
{
    int* piVar4 = param_1;
    int  iVar1  = param_1[5];

    if (iVar1 != 0xcd) {
        uint32_t* puVar2 = (uint32_t*)*param_1;
        puVar2[5] = 0x14;
        puVar2[6] = (uint32_t)iVar1;
        ((void (*)(int*))(uintptr_t)*puVar2)(param_1);
    }
    uint32_t uVar3 = (uint32_t)piVar4[0x1d];
    if (uVar3 <= (uint32_t)piVar4[0x23]) {
        int iVar1b = *piVar4;
        *(uint32_t*)(iVar1b + 0x14) = 0x7b;
        (*(void (**)(int*, int))(uintptr_t)(iVar1b + 4))(piVar4, 0xffffffff);
        return 0;
    }
    uint32_t* puVar2 = (uint32_t*)piVar4[2];
    if (puVar2 != 0) {
        puVar2[1] = (uint32_t)piVar4[0x23];
        puVar2[2] = uVar3;
        ((void (*)(int*))(uintptr_t)*puVar2)(piVar4);
    }
    int* produced = (int*)0;
    (*(void (**)(int*, uint32_t, int**, uint32_t))(uintptr_t)(piVar4[0x6b] + 4))(
        piVar4, param_2, &produced, param_3);
    piVar4[0x23] = piVar4[0x23] + (int)(intptr_t)produced;
    return (int)(intptr_t)produced;
}

// 0x654650 — observed shape: pump/step driver. A 0xca state first calls
// 0x691120; if self[0x10] is set it enters terminal state 0xcf and returns 1,
// otherwise it falls to 0xcb. Non-0xcb states (other than 0xcc) raise 0x14
// with the old state and then run the 0x654550 teardown path. In state 0xcb,
// when the source object (self[0x6e]) has a non-zero +0x10 field it loops:
// invoke self[2], then self[0x6e] as a step function; 0 ends the driver, 2
// breaks the loop to teardown, 3/1 bump the self[2] progress counter and wrap it
// by self[0x51]. On break/exit, self[0x27] = self[0x25] then teardown.
int FUN_00654650(int* param_1)
{
    if (param_1[5] == 0xca) {
        FUN_00691120(param_1);
        if (param_1[0x10] != 0) {
            param_1[5] = 0xcf;
            return 1;
        }
        param_1[5] = 0xcb;
    }

    int iVar3 = param_1[5];
    if (iVar3 != 0xcb) {
        if (iVar3 != 0xcc) {
            uint32_t* puVar2 = (uint32_t*)*param_1;
            puVar2[5] = 0x14;
            puVar2[6] = (uint32_t)iVar3;
            ((void (*)(int*))(uintptr_t)*puVar2)(param_1);
        }
        return FUN_00654550(param_1);   // receiver supplied in ESI by the listing
    }

    if (*(int*)(param_1[0x6e] + 0x10) != 0) {
        for (;;) {
            if ((int*)param_1[2] != 0) {
                (*(void (**)(int*))(uintptr_t)param_1[2])(param_1);
            }
            iVar3 = (*(int (**)(int*))(uintptr_t)param_1[0x6e])(param_1);
            if (iVar3 == 0) {
                return 0;
            }
            if (iVar3 == 2) break;
            int iVar1 = param_1[2];
            if ((iVar1 != 0) &&
                ((iVar3 == 3 || iVar3 == 1) &&
                 (iVar3 = *(int*)(iVar1 + 4) + 1, *(int*)(iVar1 + 4) = iVar3,
                  *(int*)(iVar1 + 8) <= iVar3))) {
                *(int*)(iVar1 + 8) = *(int*)(iVar1 + 8) + param_1[0x51];
            }
        }
    }
    param_1[0x27] = param_1[0x25];
    return FUN_00654550(param_1);
}

// 0x654730 — observed shape: (re)initialises a 0x76-dword object: reports
// constructor-argument mismatches through vtable slot 5 (codes 0xc/0x15 with
// expected 0x3e/0x1d8), preserves self[0] and self[3] across the zero-fill,
// then re-installs them, sets self[4]=1, calls the two init helpers, clears the
// listed fields and ends in state 200 (0xc8).
void FUN_00654730(int* param_1, int param_2, int param_3)
{
    param_1[1] = 0;
    if (param_2 != 0x3e) {
        uint32_t* puVar1 = (uint32_t*)*param_1;
        puVar1[5] = 0xc;
        puVar1[6] = 0x3e;
        puVar1[7] = (uint32_t)param_2;
        ((void (*)(int*))(uintptr_t)*puVar1)(param_1);
    }
    if (param_3 != 0x1d8) {
        uint32_t* puVar1 = (uint32_t*)*param_1;
        puVar1[5] = 0x15;
        puVar1[6] = 0x1d8;
        puVar1[7] = (uint32_t)param_3;
        ((void (*)(int*))(uintptr_t)*puVar1)(param_1);
    }
    int  iVar2 = param_1[3];
    int  iVar3 = *param_1;
    int* piVar5 = param_1;
    for (int iVar4 = 0x76; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar5 = 0;
        piVar5 = piVar5 + 1;
    }
    *param_1 = iVar3;
    param_1[3] = iVar2;
    param_1[4] = 1;
    FUN_00692220(param_1);
    param_1[2] = 0;
    param_1[6] = 0;
    param_1[0x2a] = 0;
    param_1[0x2b] = 0;
    param_1[0x2c] = 0;
    param_1[0x2d] = 0;
    param_1[0x2e] = 0;
    param_1[0x32] = 0;
    param_1[0x2f] = 0;
    param_1[0x33] = 0;
    param_1[0x30] = 0;
    param_1[0x34] = 0;
    param_1[0x31] = 0;
    param_1[0x35] = 0;
    param_1[0x4d] = 0;
    FUN_006562f0(param_1);
    FUN_006916f0(param_1);
    param_1[5] = 200;
}

// 0x654830 — observed shape: derives the block modes (self[10]) and column
// class (self[0xb]) from the mode at self[9] and the media state at self[0x37].
// Receiver arrives in ESI; modelled as self. Modes 1/3/4 map directly; mode 3
// additionally inspects a 3-int descriptor (values 1/2/3, or 0x52/0x47/0x42)
// and the byte at self+0x4b*4. Invalid combinations are reported through vtable
// slot 1 (codes 0x6f and 0x72). All paths converge on the fixed field
// initialisation at LAB_00654953.
void FUN_00654830(void* selfv)
{
    int*    self = (int*)selfv;
    int     iVar1;
    int*    piVar2;
    int     iVar3;
    int     iVar4;
    int     iVar5;
    uint32_t uVar6;

    iVar1 = self[9];
    if (iVar1 == 1) {
        self[10] = 1;
        self[0xb] = 1;
        goto LAB_00654953;
    }
    if (iVar1 != 3) {
        if (iVar1 == 4) {
            if ((self[0x4a] == 0) || (uVar6 = *(uint8_t*)(self + 0x4b), uVar6 == 0)) {
                self[10] = 4;
                self[0xb] = 4;
            } else {
                if (uVar6 != 2) {
                    iVar1 = *self;
                    *(uint32_t*)(iVar1 + 0x14) = 0x72;
                    *(uint32_t*)(iVar1 + 0x18) = uVar6;
                    (*(void (**)())(uintptr_t)(iVar1 + 4))();
                }
                self[10] = 5;
                self[0xb] = 4;
            }
        } else {
            self[10] = 0;
            self[0xb] = 0;
        }
        goto LAB_00654953;
    }

    if (self[0x47] == 0) {
        if (self[0x4a] == 0) {
            piVar2 = (int*)self[0x37];
            iVar1  = *piVar2;
            iVar3  = piVar2[0x15];
            iVar4  = piVar2[0x2a];
            if (iVar1 == 1) {
                if ((iVar3 == 2) && (iVar4 == 3)) {
                    self[10] = 3;
                    self[0xb] = 2;
                    goto LAB_00654953;
                }
            } else if (((iVar1 == 0x52) && (iVar3 == 0x47)) && (iVar4 == 0x42)) {
                goto LAB_006548d7;
            }
            iVar5 = *self;
            *(int*)(iVar5 + 0x18) = iVar1;
            *(int*)(iVar5 + 0x1c) = iVar3;
            *(int*)(iVar5 + 0x20) = iVar4;
            *(uint32_t*)(iVar5 + 0x14) = 0x6f;
        } else {
            uVar6 = *(uint8_t*)(self + 0x4b);
            if (uVar6 == 0) {
LAB_006548d7:
                self[10] = 2;
                self[0xb] = 2;
                goto LAB_00654953;
            }
            if (uVar6 == 1) goto LAB_00654936;
            iVar5 = *self;
            *(uint32_t*)(iVar5 + 0x14) = 0x72;
            *(uint32_t*)(iVar5 + 0x18) = uVar6;
        }
        (*(void (**)())(uintptr_t)(iVar5 + 4))();
    }

LAB_00654936:
    self[10] = 3;
    self[0xb] = 2;

LAB_00654953:
    self[0xe]  = 0;
    self[0xf]  = 0x3ff00000;
    self[0xc]  = 1;
    self[0xd]  = 1;
    self[0x10] = 0;
    self[0x11] = 0;
    self[0x12] = 0;
    self[0x13] = 1;
    self[0x14] = 1;
    self[0x15] = 0;
    self[0x16] = 2;
    self[0x17] = 0;
    self[0x18] = 0x100;
    self[0x22] = 0;
    self[0x19] = 0;
    self[0x1a] = 0;
    self[0x1b] = 0;
}

// 0x6549a0 — observed shape: state machine step. 200 runs the two setup
// callbacks (self[0x6e]+4 and self[6]+8) and falls through into 0xc9, which
// polls self[0x6e]; a step returning 1 latches the block init (0x654830) and
// state 0xca. 0xca is terminal-success. 0xcb..0xd0 and 0xd2 forward the step
// result. Unknown states are reported (0x14) through vtable slot 0.
int FUN_006549a0(int* param_1)
{
    int iVar2 = param_1[5];
    int iVar3 = 0;

    switch (iVar2) {
    case 200:
        (*(void (**)(int*))(uintptr_t)(param_1[0x6e] + 4))(param_1);
        (*(void (**)(int*))(uintptr_t)(param_1[6] + 8))(param_1);
        param_1[5] = 0xc9;
        /* fall through */
    case 0xc9:
        iVar3 = (*(int (**)(int*))(uintptr_t)param_1[0x6e])(param_1);
        if (iVar3 == 1) {
            FUN_00654830((void*)param_1);   // receiver supplied in ESI by the listing
            param_1[5] = 0xca;
            return 1;
        }
        break;
    case 0xca:
        return 1;
    case 0xcb:
    case 0xcc:
    case 0xcd:
    case 0xce:
    case 0xcf:
    case 0xd0:
    case 0xd2:
        return (*(int (**)(int*))(uintptr_t)param_1[0x6e])(param_1);
    default:
        uint32_t* puVar1 = (uint32_t*)*param_1;
        puVar1[5] = 0x14;
        puVar1[6] = (uint32_t)iVar2;
        ((void (*)(int*))(uintptr_t)*puVar1)(param_1);
    }
    return iVar3;
}
