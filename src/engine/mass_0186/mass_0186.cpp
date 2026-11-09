// UNVERIFIED decompiler-derived reconstruction — Ghidra 12.2 pseudocode corpus,
// PE32 i386. Sources: analysis/pseudocode/functions/0x582fb0.c through
// 0x58f130.c (one complete listing per function). No PASS or byte-match claim.
#include <cstdint>
#include <cstddef>
#include <cmath>
#include <cstring>
#include <windows.h>

// ---------------------------------------------------------------------------
// Helpers reproducing recurring idioms in the listings.
// ---------------------------------------------------------------------------

// (**(code **)(*obj + slot))(...): virtual call through the object's vtable.
// The receiver is passed explicitly because these reconstructions are free
// functions; it is the value the listing keeps in the thiscall register.
template <typename R, typename... Args>
static R vcall(void* obj, uintptr_t slot, Args... args)
{
    using Fn = R (*)(void*, Args...);
    Fn fn = *reinterpret_cast<Fn*>(*reinterpret_cast<uintptr_t*>(obj) + slot);
    return fn(obj, args...);
}

// CONCAT22(hi, lo): the decompiler's fused 16-bit store.
static int32_t concat22(uint16_t hi, uint16_t lo)
{
    return static_cast<int32_t>((static_cast<uint32_t>(hi) << 16) | lo);
}

// CONCAT31(hi24, lo8).
static int32_t concat31(uint32_t hi24, uint8_t lo)
{
    return static_cast<int32_t>((hi24 & 0xFFFFFF00u) | lo);
}

static uint16_t high16(int32_t v)
{
    return static_cast<uint16_t>(static_cast<uint32_t>(v) >> 16);
}

// x87 comparison status word that the listings repack by hand:
// bit 8 = below, bit 10 = unordered, bit 14 = equal.
static uint16_t fcmp_status(float a, float b)
{
    return static_cast<uint16_t>(((a < b) ? 1u : 0u) << 8 |
                                 ((std::isnan(a) || std::isnan(b)) ? 1u : 0u) << 10 |
                                 ((a == b) ? 1u : 0u) << 14);
}

static int32_t pack_cmp(uint16_t hi, float a, float b)
{
    return concat22(hi, fcmp_status(a, b));
}

static uint32_t float_bits(float f)
{
    uint32_t u;
    std::memcpy(&u, &f, sizeof u);
    return u;
}

// ---------------------------------------------------------------------------
// External routines and globals referenced by the listings.
// ---------------------------------------------------------------------------
extern void* operator_delete(void* ptr);
extern void operator_delete__(void* ptr);

extern char FUN_004284c0(void* param);
extern void FUN_00431420(float* param);
extern void* FUN_00431450(void* out, float scale, void* src);
extern void* FUN_004760c0(void* out, const void* src);
extern void FUN_00491640(void);
extern void* FUN_00497ca0(void* out, void* src);
extern void FUN_00497cf0(float* dst, float* src);
extern long double FUN_004d4bc0(void);
extern float* FUN_0053ca60(void* out, int32_t src);
extern void FUN_00549b80(void);
extern void FUN_00549cd0(uint32_t param);
extern void FUN_005606f0(uint32_t index, int32_t* value);
extern long double FUN_00585940(float param_1, void* param_2);
extern void FUN_0058b8e0(float* param);
extern void FUN_0058fca0(uint32_t bits, float* vec);
extern char FUN_00596480(int32_t param_1, uint32_t param_2);
extern char FUN_00596cb0(int32_t param);
extern long double FUN_00599230(void* a, void* b, void* c, void* d, void* e);
extern long double FUN_00599680(void* a, void* b, void* c, void* d, void* e, void* f);
extern void FUN_00599e90(long double (*fn)(float, void*), int32_t a, int32_t b, void* p);
extern char FUN_0059a040(int32_t a, float b, float c, float d, float* e);
extern void FUN_0059a900(int32_t param);
extern int32_t FUN_005d8660(uint32_t param);

extern float DAT_00727430;
extern float DAT_00727434;
extern float DAT_00727438;
extern float DAT_007177c4;
extern float DAT_007177c8;
extern float DAT_007177cc;
extern char DAT_00728ac8;
extern void* PTR_FUN_006c4eb0;
extern void* PTR_FUN_006c4ff0;

// Scratch block the listings build on the stack and pass by address.  Field
// names follow the listing's local_XX labels; slot0 is the 4-byte hole in
// front of the three vectors.
struct VecBlock {
    int32_t slot0;
    float x;
    float y;
    float z;
    uint32_t w;
};

// Reconstructed definitions (forward declarations for mutual references).
void FUN_00582fb0(void* self, uint8_t param_1);
void FUN_00582ff0(void* self);
uint32_t FUN_00583070(void* self, int32_t param_1, uint32_t param_2, int32_t param_3);
void FUN_005831c0(void* self);
uint32_t FUN_005831f0(void* self, int32_t* param_1);
void FUN_005832c0(void* self, int32_t param_1, int32_t param_2);
int32_t FUN_00583390(float param_1, int32_t param_2, float* param_3, int32_t param_4, float* param_5);
long double FUN_00585ad0(float param_1, float* param_2);
uint32_t FUN_00589bf0(float param_1, int32_t param_2, float* param_3, int32_t param_4, float* param_5);
uint32_t FUN_0058a2e0(float param_1, int32_t param_2, float* param_3, int32_t param_4,
                      float* param_5, float* param_6, float* param_7, uint32_t param_8,
                      float* param_9, float* param_10);
void FUN_0058ad60(float param_1, int32_t param_2, float* param_3, int32_t param_4, float* param_5,
                  float* param_6, float* param_7);
uint16_t FUN_0058b940(float param_1, float* param_2, float* param_3, float* param_4, float* param_5,
                      float* param_6, float* param_7, uint32_t param_8, float* param_9,
                      float* param_10);
void FUN_0058edf0(void* self, uint32_t param_1);
void FUN_0058ee90(void* self);
void FUN_0058ef10(void* self);
void FUN_0058ef70(void* self, uint32_t param_1, int32_t param_2, uint32_t param_3, int32_t param_4,
                  uint32_t param_5, uint32_t param_6);
void FUN_0058f000(void* self, int32_t* param_1);
void FUN_0058f0c0(void* self, uint8_t param_1);
int32_t FUN_0058f0e0(int32_t param_1);
void FUN_0058f130(void* self);

// ---------------------------------------------------------------------------
// 0x582fb0
// ---------------------------------------------------------------------------
// 0x582fb0 — observed shape
// Releases the two owned sub-objects at +4 and +0, then optionally frees the
// receiver (deleting destructor).
void FUN_00582fb0(void* self, uint8_t param_1)
{
    uintptr_t base = reinterpret_cast<uintptr_t>(self);
    int32_t* piVar1;
    uint32_t* puVar2;

    puVar2 = *reinterpret_cast<uint32_t**>(base + 4);
    if (puVar2 != nullptr) {
        piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            vcall<void>(puVar2, 0, 1);
        }
    }
    puVar2 = *reinterpret_cast<uint32_t**>(base);
    if (puVar2 != nullptr) {
        piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            vcall<void>(puVar2, 0, 1);
        }
    }
    if ((param_1 & 1) != 0) {
        operator_delete(reinterpret_cast<void*>(base));
    }
}

// ---------------------------------------------------------------------------
// 0x582ff0
// ---------------------------------------------------------------------------
// 0x582ff0 — observed shape
// Clears the object array at +0x1c down to its counter at +0x24, dropping the
// live count at +0x28 and releasing each element.
void FUN_00582ff0(void* self)
{
    uintptr_t base = reinterpret_cast<uintptr_t>(self);
    int32_t iVar2;
    int32_t* piVar1;
    int32_t* piVar3;
    uint32_t* puVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    uint32_t uVar7;

    iVar2 = *reinterpret_cast<int32_t*>(base + 0x24);
    if ((iVar2 != 0) && (uVar6 = 0, iVar2 != 0)) {
        do {
            uVar7 = *reinterpret_cast<uint32_t*>(base + 0x1c);
            piVar3 = *reinterpret_cast<int32_t**>(static_cast<uintptr_t>(uVar7) + uVar6 * 4);
            *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(uVar7) + uVar6 * 4) = 0;
            if (piVar3 != nullptr) {
                *reinterpret_cast<int32_t*>(base + 0x28) =
                    *reinterpret_cast<int32_t*>(base + 0x28) + -1;
            }
            uVar5 = *reinterpret_cast<uint32_t*>(base + 0x24) - 1;
            if (uVar6 == uVar5) {
                *reinterpret_cast<uint32_t*>(base + 0x24) = uVar5;
            }
            if (piVar3 != nullptr) {
                puVar4 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(piVar3[1]));
                if (puVar4 != nullptr) {
                    piVar1 = reinterpret_cast<int32_t*>(puVar4 + 1);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) {
                        vcall<void>(puVar4, 0, 1);
                    }
                }
                puVar4 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(*piVar3));
                if (puVar4 != nullptr) {
                    piVar1 = reinterpret_cast<int32_t*>(puVar4 + 1);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) {
                        vcall<void>(puVar4, 0, 1);
                    }
                }
                operator_delete(piVar3);
            }
            uVar6 = uVar6 + 1;
        } while (uVar6 < *reinterpret_cast<uint32_t*>(base + 0x24));
    }
}

// ---------------------------------------------------------------------------
// 0x583070
// ---------------------------------------------------------------------------
// 0x583070 — observed shape
// Refreshes the collection (or sorts it in place) and orders the entries either
// by walking the array or by the accessor at 0x5d8660, reporting success.
uint32_t FUN_00583070(void* self, int32_t param_1, uint32_t param_2, int32_t param_3)
{
    uintptr_t base = reinterpret_cast<uintptr_t>(self);
    int32_t* in_ECX = reinterpret_cast<int32_t*>(self);
    uint32_t uVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    char cVar4;
    int32_t iVar5;
    uint32_t uVar6;
    int32_t iVar7;
    bool bVar8;

    if (static_cast<char>(param_3) == '\0') {
        FUN_00582ff0(self);
    }
    cVar4 = FUN_00596480(param_1, param_2);
    if ((cVar4 == '\0') || (in_ECX[10] == 0)) {
        return 0;
    }
    uVar6 = 1;
    if ((in_ECX[1] != 1) && ((in_ECX[2] != 0) && (1 < static_cast<uint32_t>(in_ECX[10])))) {
        uVar1 = static_cast<uint32_t>(in_ECX[9]);
        if (*in_ECX == 0) {
            param_2 = 0;
            if (uVar1 != 0) {
                do {
                    param_1 = *reinterpret_cast<int32_t*>(
                        static_cast<uintptr_t>(static_cast<uint32_t>(in_ECX[7])) + param_2 * 4);
                    uVar2 = param_2;
                    uVar6 = param_2;
                    if (param_1 != 0) {
                        while (uVar6 = uVar6 + 1, uVar6 < uVar1) {
                            iVar7 = *reinterpret_cast<int32_t*>(
                                static_cast<uintptr_t>(static_cast<uint32_t>(in_ECX[7])) +
                                uVar6 * 4);
                            if (iVar7 != 0) {
                                if (*reinterpret_cast<float*>(static_cast<uintptr_t>(iVar7) + 0x14) <
                                    *reinterpret_cast<float*>(static_cast<uintptr_t>(param_1) + 0x14)) {
                                    uVar3 = param_2;
                                    param_2 = uVar2;
                                    param_3 = iVar7;
                                    FUN_005606f0(uVar3, &param_3);
                                    FUN_005606f0(uVar6, &param_1);
                                    param_1 = iVar7;
                                    uVar2 = param_2;
                                }
                            }
                        }
                    }
                    param_2 = param_2 + 1;
                } while (param_2 < uVar1);
                return 1;
            }
        }
        else {
            iVar7 = *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(in_ECX[7])));
            param_3 = iVar7;
            if (1 < uVar1) {
                do {
                    iVar5 = FUN_005d8660(uVar6);
                    if ((iVar5 != 0) &&
                        ((*reinterpret_cast<float*>(static_cast<uintptr_t>(iVar7) + 0x14) <=
                          *reinterpret_cast<float*>(static_cast<uintptr_t>(iVar5) + 0x14)) ||
                         (bVar8 = iVar7 != 0, iVar7 = iVar5, bVar8))) {
                        // The listing does not materialise the thiscall receiver of this
                        // deleting helper; it is the element just fetched.
                        FUN_00582fb0(reinterpret_cast<void*>(static_cast<uintptr_t>(iVar5)), 1);
                    }
                    uVar6 = uVar6 + 1;
                } while (uVar6 < uVar1);
                param_3 = iVar7;
            }
            FUN_005606f0(0, &param_3);
        }
    }
    return 1;
}

// ---------------------------------------------------------------------------
// 0x5831c0
// ---------------------------------------------------------------------------
// 0x5831c0 — observed shape
// Non-deleting teardown: empties the collection, installs the base vtable and
// frees the backing array before releasing the trailing sub-object.
void FUN_005831c0(void* self)
{
    uintptr_t base = reinterpret_cast<uintptr_t>(self);
    int32_t* piVar1;
    uint32_t* puVar2;

    FUN_00582ff0(self);
    *reinterpret_cast<void**>(base + 0x18) = &PTR_FUN_006c4eb0;
    operator_delete__(*reinterpret_cast<void**>(base + 0x1c));
    puVar2 = *reinterpret_cast<uint32_t**>(base + 0x14);
    if (puVar2 != nullptr) {
        piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
            vcall<void>(puVar2, 0, 1);
        }
    }
}

// ---------------------------------------------------------------------------
// 0x5831f0
// ---------------------------------------------------------------------------
// 0x5831f0 — observed shape
// Predicate: the candidate reports kind 1 through its vtable and the receiver's
// +4 sub-object accepts it.
uint32_t FUN_005831f0(void* self, int32_t* param_1)
{
    uintptr_t base = reinterpret_cast<uintptr_t>(self);
    char cVar1;
    int32_t iVar2;

    iVar2 = vcall<int32_t>(param_1, 0xc);
    if (iVar2 == 1) {
        cVar1 = FUN_00596cb0(static_cast<int32_t>(base + 4));
        if (cVar1 != '\0') {
            return 1;
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x5832c0
// ---------------------------------------------------------------------------
// 0x5832c0 — observed shape
// Places a transformed copy of one source frame into the receiver's cached
// frame: origin from the parent position, three rows and three extents scaled
// by the frame's +0x30 field.
void FUN_005832c0(void* self, int32_t param_1, int32_t param_2)
{
    intptr_t in_ECX = reinterpret_cast<intptr_t>(self);
    float fVar1;
    int32_t iVar2;
    float* pfVar3;
    uint32_t* puVar4;
    uint32_t* puVar5;
    float local_18;
    float local_14;
    float local_10;
    uint8_t local_c[4];
    float local_8;
    float local_4;
    int32_t param_1_local;

    iVar2 = param_1;
    param_1_local = 3;
    pfVar3 = FUN_0053ca60(&local_18, param_1 + 4);
    fVar1 = *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x30);
    puVar5 = reinterpret_cast<uint32_t*>(in_ECX + 0x10);
    local_8 = fVar1 * pfVar3[1];
    local_4 = fVar1 * pfVar3[2];
    local_18 = fVar1 * *pfVar3 + *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x24);
    local_14 = local_8 + *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x28);
    local_10 = local_4 + *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x2c);
    *reinterpret_cast<float*>(in_ECX + 4) = local_18;
    *reinterpret_cast<float*>(in_ECX + 8) = local_14;
    *reinterpret_cast<float*>(in_ECX + 0xc) = local_10;
    pfVar3 = reinterpret_cast<float*>(in_ECX + 0x34);
    do {
        puVar4 = reinterpret_cast<uint32_t*>(
            FUN_0053ca60(local_c, static_cast<int32_t>(reinterpret_cast<intptr_t>(puVar5) +
                                                       (iVar2 - in_ECX))));
        *puVar5 = *puVar4;
        puVar5[1] = puVar4[1];
        puVar5[2] = puVar4[2];
        puVar5 = puVar5 + 3;
        *pfVar3 = *reinterpret_cast<float*>(reinterpret_cast<intptr_t>(pfVar3) +
                                            (iVar2 - in_ECX)) *
                  *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x30);
        param_1_local = param_1_local + -1;
        pfVar3 = pfVar3 + 1;
    } while (param_1_local != 0);
}

// ---------------------------------------------------------------------------
// 0x583390
// ---------------------------------------------------------------------------
// 0x583390 — observed shape
// Separating-axis sweep between two oriented frames with extents, followed by
// a containment/penetration fallback.  Each axis test returns the packed x87
// comparison flags when it separates; a full pass falls through to the
// containment test.
int32_t FUN_00583390(float param_1, int32_t param_2, float* param_3, int32_t param_4, float* param_5)
{
    float fVar1;
    float fVar2;
    float fVar3;
    float fVar4;
    int32_t iVar5;
    float local_90;
    float local_8c;
    float local_88;
    float local_80;
    float local_7c;
    float local_78;
    float local_74;
    float local_70;
    float local_6c;
    float local_68;
    float local_64;
    float local_60;
    float local_5c;
    float local_58;
    float local_54;
    float local_50;
    float local_4c;
    float local_48;
    float local_44;
    float local_40;
    float local_3c;
    float local_34;
    float local_30;
    float local_2c;
    float local_28;
    float local_24;
    float local_20;
    float local_1c;
    float local_18;
    float local_14;
    float local_10;
    float local_c;
    float local_8;

    local_34 = *param_5 - *param_3;
    local_30 = param_5[1] - param_3[1];
    local_2c = param_5[2] - param_3[2];
    local_90 = *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 4) -
               *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 4);
    local_8c = *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 8) -
               *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 8);
    local_88 = *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0xc) -
               *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0xc);
    local_44 = local_34 * param_1 + local_90;
    local_40 = local_8c + local_30 * param_1;
    local_3c = local_88 + local_2c * param_1;

    // The listing seeds the return register's upper half from the bit pattern of
    // local_44 before any axis test; preserved as observed.
    iVar5 = static_cast<int32_t>(float_bits(local_44) & 0xFFFF0000u);

    // One separating-axis test: on separation the packed comparison flags are
    // produced (low half) and the test reports true; otherwise it falls through,
    // leaving the accumulated high half in place.
    auto sep = [&iVar5](float a, float b, float a2) -> bool {
        if (a <= b) {
            const float nb = -b;
            iVar5 = static_cast<int32_t>(static_cast<uint32_t>(iVar5) & 0xFFFF0000u);
            if (a < nb) {
                iVar5 = pack_cmp(high16(iVar5), a2, nb);
                if (a2 < nb) {
                    return true;
                }
            }
            return false;
        }
        iVar5 = pack_cmp(high16(iVar5), a2, b);
        if ((a2 >= b) && (a2 != b)) {
            return true;
        }
        return false;
    };

    local_68 = *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x14) *
                   *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x14) +
               *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x10) *
                   *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x10) +
               *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x18) *
                   *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x18);
    local_64 = *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x10) *
                   *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x1c) +
               *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x24) *
                   *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x18) +
               *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x20) *
                   *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x14);
    local_60 = *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x28) *
                   *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x10) +
               *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x30) *
                   *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x18) +
               *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x2c) *
                   *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x14);
    local_80 = local_88 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x18) +
               local_90 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x10) +
               local_8c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x14);
    local_74 = local_3c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x18) +
               local_44 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x10) +
               local_40 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x14);
    local_28 = std::fabs(local_68);
    local_24 = std::fabs(local_64);
    local_20 = std::fabs(local_60);
    fVar1 = local_20 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x3c) +
            local_28 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x34) +
            local_24 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x38) +
            *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x34);
    if (sep(local_80, fVar1, local_74)) {
        return iVar5;
    }

    local_5c = *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x1c) *
                   *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x10) +
               *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x20) *
                   *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x14) +
               *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x24) *
                   *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x18);
    local_58 = *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x1c) *
                   *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x1c) +
               *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x20) *
                   *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x20) +
               *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x24) *
                   *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x24);
    local_54 = *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x28) *
                   *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x1c) +
               *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x2c) *
                   *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x20) +
               *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x30) *
                   *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x24);
    local_7c = local_90 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x1c) +
               local_88 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x24) +
               local_8c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x20);
    local_70 = local_44 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x1c) +
               local_3c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x24) +
               local_40 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x20);
    local_1c = std::fabs(local_5c);
    local_18 = std::fabs(local_58);
    local_14 = std::fabs(local_54);
    fVar1 = local_14 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x3c) +
            local_18 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x38) +
            local_1c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x34) +
            *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x38);
    if (sep(local_7c, fVar1, local_70)) {
        return iVar5;
    }

    local_50 = *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x28) *
                   *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x10) +
               *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x2c) *
                   *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x14) +
               *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x30) *
                   *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x18);
    local_4c = *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x1c) *
                   *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x28) +
               *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x20) *
                   *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x2c) +
               *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x24) *
                   *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x30);
    local_48 = *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x28) *
                   *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x28) +
               *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x2c) *
                   *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x2c) +
               *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x30) *
                   *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x30);
    local_78 = local_90 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x28) +
               local_88 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x30) +
               local_8c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x2c);
    local_6c = local_44 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x28) +
               local_3c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x30) +
               local_40 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x2c);
    local_10 = std::fabs(local_50);
    local_c = std::fabs(local_4c);
    local_8 = std::fabs(local_48);
    fVar1 = local_8 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x3c) +
            local_c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x38) +
            local_10 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x34) +
            *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x3c);
    if (sep(local_78, fVar1, local_6c)) {
        return iVar5;
    }

    fVar1 = local_8c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x14) +
            local_90 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x10) +
            local_88 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x18);
    fVar2 = local_28 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x34) +
            local_10 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x3c) +
            local_1c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x38) +
            *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x34);
    if (sep(fVar1, fVar2,
             local_40 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x14) +
                 local_44 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x10) +
                 local_3c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x18))) {
        return iVar5;
    }

    fVar1 = local_90 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x1c) +
            local_88 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x24) +
            local_8c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x20);
    fVar2 = local_24 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x34) +
            local_c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x3c) +
            local_18 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x38) +
            *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x38);
    if (sep(fVar1, fVar2,
             local_44 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x1c) +
                 local_3c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x24) +
                 local_40 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x20))) {
        return iVar5;
    }

    fVar1 = local_90 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x28) +
            local_88 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x30) +
            local_8c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x2c);
    fVar2 = local_20 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x34) +
            local_8 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x3c) +
            local_14 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x38) +
            *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x3c);
    if (sep(fVar1, fVar2,
             local_44 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x28) +
                 local_3c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x30) +
                 local_40 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x2c))) {
        return iVar5;
    }

    fVar1 = local_78 * local_5c - local_50 * local_7c;
    fVar2 = local_24 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x3c) +
            local_20 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x38) +
            local_1c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x3c) +
            local_10 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x38);
    if (sep(fVar1, fVar2, local_6c * local_5c - local_50 * local_70)) {
        return iVar5;
    }

    fVar1 = local_78 * local_58 - local_4c * local_7c;
    fVar2 = local_28 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x3c) +
            local_20 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x34) +
            local_18 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x3c) +
            local_c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x38);
    if (sep(fVar1, fVar2, local_6c * local_58 - local_4c * local_70)) {
        return iVar5;
    }

    fVar1 = local_78 * local_54 - local_48 * local_7c;
    fVar2 = local_28 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x38) +
            local_24 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x34) +
            local_14 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x3c) +
            local_8 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x38);
    if (sep(fVar1, fVar2, local_6c * local_54 - local_48 * local_70)) {
        return iVar5;
    }

    fVar1 = local_50 * local_80 - local_78 * local_68;
    fVar2 = local_18 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x3c) +
            local_14 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x38) +
            local_28 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x3c) +
            local_10 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x34);
    if (sep(fVar1, fVar2, local_50 * local_74 - local_6c * local_68)) {
        return iVar5;
    }

    fVar1 = local_4c * local_80 - local_78 * local_64;
    fVar2 = local_24 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x3c) +
            local_c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x34) +
            local_1c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x3c) +
            local_14 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x34);
    if (sep(fVar1, fVar2, local_4c * local_74 - local_6c * local_64)) {
        return iVar5;
    }

    fVar1 = local_48 * local_80 - local_78 * local_60;
    fVar2 = local_20 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x3c) +
            local_8 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x34) +
            local_1c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x38) +
            local_18 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x34);
    if (sep(fVar1, fVar2, local_48 * local_74 - local_6c * local_60)) {
        return iVar5;
    }

    fVar1 = local_7c * local_68 - local_5c * local_80;
    fVar2 = local_c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x3c) +
            local_8 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x38) +
            local_1c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x34) +
            local_28 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x38);
    if (sep(fVar1, fVar2, local_70 * local_68 - local_5c * local_74)) {
        return iVar5;
    }

    fVar1 = local_7c * local_64 - local_58 * local_80;
    fVar2 = local_10 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x3c) +
            local_8 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x34) +
            local_18 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x34) +
            local_24 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x38);
    if (sep(fVar1, fVar2, local_70 * local_64 - local_58 * local_74)) {
        return iVar5;
    }

    fVar1 = local_7c * local_60 - local_54 * local_80;
    fVar2 = local_10 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x38) +
            local_c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x34) +
            local_14 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x34) +
            local_20 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x38);
    if (sep(fVar1, fVar2, local_70 * local_60 - local_54 * local_74)) {
        return iVar5;
    }

    FUN_00497cf0(&local_80, &local_90);
    fVar1 = local_34 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x1c) +
            local_2c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x24) +
            local_30 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x20);
    fVar2 = local_34 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x28) +
            local_2c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x30) +
            local_30 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x2c);
    fVar3 = std::fabs(local_78 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x18) +
                      local_80 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x10) +
                      local_7c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x14));
    fVar4 = std::fabs(fVar2) * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x38) +
            std::fabs(fVar1) * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x3c) +
            std::fabs(fVar2 * local_5c - fVar1 * local_50) *
                *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x34) +
            std::fabs(fVar2 * local_58 - fVar1 * local_4c) *
                *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x38) +
            std::fabs(fVar2 * local_54 - fVar1 * local_48) *
                *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x3c);
    // Upper half of the return register as observed (the listing's extraout_var).
    uint16_t extraout_var = high16(iVar5);
    iVar5 = pack_cmp(extraout_var, fVar4, fVar3);
    if (fVar4 >= fVar3) {
        fVar3 = local_2c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x18) +
                local_34 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x10) +
                local_30 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x14);
        fVar4 = std::fabs(local_80 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x1c) +
                          local_78 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x24) +
                          local_7c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x20));
        fVar2 = std::fabs(fVar2) * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x34) +
                std::fabs(fVar3) * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x3c) +
                std::fabs(fVar3 * local_50 - fVar2 * local_68) *
                    *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x34) +
                std::fabs(fVar3 * local_48 - fVar2 * local_60) *
                    *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x3c) +
                std::fabs(fVar3 * local_4c - fVar2 * local_64) *
                    *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x38);
        iVar5 = pack_cmp(extraout_var, fVar2, fVar4);
        if (fVar2 >= fVar4) {
            fVar2 = std::fabs(local_80 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x28) +
                              local_78 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x30) +
                              local_7c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x2c));
            fVar1 = std::fabs(fVar1) * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x34) +
                    std::fabs(fVar3) * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x38) +
                    std::fabs(fVar1 * local_68 - fVar3 * local_5c) *
                        *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x34) +
                    std::fabs(fVar1 * local_64 - fVar3 * local_58) *
                        *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x38) +
                    std::fabs(fVar1 * local_60 - fVar3 * local_54) *
                        *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x3c);
            iVar5 = pack_cmp(extraout_var, fVar1, fVar2);
            if (fVar1 >= fVar2) {
                fVar1 = local_34 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x1c) +
                        local_2c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x24) +
                        local_30 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x20);
                fVar2 = local_34 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x28) +
                        local_2c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x30) +
                        local_30 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x2c);
                fVar3 = std::fabs(local_7c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x14) +
                                  local_78 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x18) +
                                  local_80 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x10));
                fVar4 = std::fabs(fVar2) * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x38) +
                        std::fabs(fVar1) * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x3c) +
                        std::fabs(fVar2 * local_64 - fVar1 * local_60) *
                            *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x34) +
                        std::fabs(fVar2 * local_58 - fVar1 * local_54) *
                            *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x38) +
                        std::fabs(fVar2 * local_4c - fVar1 * local_48) *
                            *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x3c);
                iVar5 = pack_cmp(extraout_var, fVar4, fVar3);
                if (fVar4 >= fVar3) {
                    fVar3 = local_30 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x14) +
                            local_34 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x10) +
                            local_2c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x18);
                    fVar4 = std::fabs(local_80 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x1c) +
                                      local_78 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x24) +
                                      local_7c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x20));
                    fVar2 = std::fabs(fVar3) * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x3c) +
                            std::fabs(fVar2) * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x34) +
                            std::fabs(fVar3 * local_60 - fVar2 * local_68) *
                                *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x34) +
                            std::fabs(fVar3 * local_54 - fVar2 * local_5c) *
                                *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x38) +
                            std::fabs(fVar3 * local_48 - fVar2 * local_50) *
                                *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x3c);
                    iVar5 = pack_cmp(extraout_var, fVar2, fVar4);
                    if (fVar2 >= fVar4) {
                        fVar2 = std::fabs(local_80 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x28) +
                                          local_78 * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x30) +
                                          local_7c * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x2c));
                        fVar1 = std::fabs(fVar3) * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x38) +
                                std::fabs(fVar1) * *reinterpret_cast<float*>(static_cast<uintptr_t>(param_4) + 0x34) +
                                std::fabs(fVar1 * local_68 - fVar3 * local_64) *
                                    *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x34) +
                                std::fabs(fVar1 * local_5c - fVar3 * local_58) *
                                    *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x38) +
                                std::fabs(fVar1 * local_50 - fVar3 * local_4c) *
                                    *reinterpret_cast<float*>(static_cast<uintptr_t>(param_2) + 0x3c);
                        iVar5 = pack_cmp(extraout_var, fVar1, fVar2);
                        if (fVar1 >= fVar2) {
                            return concat31(static_cast<uint32_t>(iVar5) >> 8, 1);
                        }
                    }
                }
            }
        }
    }
    return iVar5;
}

// ---------------------------------------------------------------------------
// 0x585ad0
// ---------------------------------------------------------------------------
// 0x585ad0 — observed shape
// Sweeps the local frame along one axis and returns the signed distance of the
// contact plane at +0x54.
long double FUN_00585ad0(float param_1, float* param_2)
{
    float local_18;
    float local_14;
    float local_10;
    float local_c;
    float local_8;
    float local_4;
    long double fVar1;

    local_18 = param_1 * param_2[6] + *param_2;
    local_14 = param_1 * param_2[7] + param_2[1];
    local_10 = param_1 * param_2[8] + param_2[2];
    local_c = param_2[3];
    local_8 = param_2[4];
    local_4 = param_2[5];
    fVar1 = (long double)FUN_00599680(&local_18, param_2 + 9, param_2 + 0x16, param_2 + 0x17,
                                      param_2 + 0x18, param_2 + 0x19);
    return fVar1 - (long double)param_2[0x15];
}

// ---------------------------------------------------------------------------
// 0x589bf0
// ---------------------------------------------------------------------------
// 0x589bf0 — observed shape
// Sweeps one oriented box against a point/direction pair and reports whether the
// resulting distance exceeds the squared scale at +0x10.
uint32_t FUN_00589bf0(float param_1, int32_t param_2, float* param_3, int32_t param_4, float* param_5)
{
    int32_t iVar1;
    long double fVar2;
    long double fVar3;
    float local_48;
    float local_44;
    float local_40;
    float local_3c;
    float local_38;
    float local_34;
    float local_30;
    float local_2c;
    float local_28;
    float local_24;
    float local_20;
    float local_1c;
    float local_18;
    float local_14;
    float local_10;
    float local_c;
    float local_8;
    float local_4;
    uintptr_t p2 = static_cast<uintptr_t>(param_2);
    uintptr_t p4 = static_cast<uintptr_t>(param_4);

    iVar1 = param_4;
    local_1c = *reinterpret_cast<float*>(p2 + 0x34) + *reinterpret_cast<float*>(p2 + 0x34);
    local_24 = local_1c * *reinterpret_cast<float*>(p2 + 0x10);
    local_20 = local_1c * *reinterpret_cast<float*>(p2 + 0x14);
    local_1c = local_1c * *reinterpret_cast<float*>(p2 + 0x18);
    local_10 = *reinterpret_cast<float*>(p2 + 0x38) + *reinterpret_cast<float*>(p2 + 0x38);
    local_18 = local_10 * *reinterpret_cast<float*>(p2 + 0x1c);
    local_14 = local_10 * *reinterpret_cast<float*>(p2 + 0x20);
    local_10 = local_10 * *reinterpret_cast<float*>(p2 + 0x24);
    local_4 = *reinterpret_cast<float*>(p2 + 0x3c) + *reinterpret_cast<float*>(p2 + 0x3c);
    local_c = local_4 * *reinterpret_cast<float*>(p2 + 0x28);
    local_8 = local_4 * *reinterpret_cast<float*>(p2 + 0x2c);
    local_4 = local_4 * *reinterpret_cast<float*>(p2 + 0x30);
    local_40 = local_10 + local_1c;
    local_48 = (local_18 + local_24 + local_c) * 0.5f;
    local_44 = (local_14 + local_20 + local_8) * 0.5f;
    local_30 = *reinterpret_cast<float*>(p2 + 4) - local_48;
    local_2c = *reinterpret_cast<float*>(p2 + 8) - local_44;
    local_28 = *reinterpret_cast<float*>(p2 + 0xc) - (local_4 + local_40) * 0.5f;
    if (((*param_5 - *param_3 == DAT_00727430) && (param_5[1] - param_3[1] == DAT_00727434)) &&
        (param_5[2] - param_3[2] == DAT_00727438)) {
        fVar2 = (long double)FUN_00599230(reinterpret_cast<void*>(p4 + 4), &local_30, &param_3,
                                          &param_5, &param_4);
    }
    else {
        local_3c = (*param_5 - *param_3) * param_1;
        local_48 = *reinterpret_cast<float*>(p4 + 4);
        local_44 = *reinterpret_cast<float*>(p4 + 8);
        local_40 = *reinterpret_cast<float*>(p4 + 0xc);
        local_38 = (param_5[1] - param_3[1]) * param_1;
        local_34 = (param_5[2] - param_3[2]) * param_1;
        fVar2 = (long double)FUN_00599680(&local_48, &local_30, &param_2, &param_3, &param_5,
                                          &param_4);
    }
    fVar3 = (long double)*reinterpret_cast<float*>(iVar1 + 0x10) *
            (long double)*reinterpret_cast<float*>(iVar1 + 0x10);
    if ((std::isnan(fVar2) || std::isnan(fVar3)) ||
        ((fVar2 < fVar3) == (fVar2 == fVar3))) {
        return 0;
    }
    return 1;
}

// ---------------------------------------------------------------------------
// 0x58a2e0
// ---------------------------------------------------------------------------
// 0x58a2e0 — observed shape
// Contact solve for two oriented frames: builds the relative extents, probes the
// reference distance, then either refines by a recursive sweep or snaps the
// result to the face/edge centroid.
uint32_t FUN_0058a2e0(float param_1, int32_t param_2, float* param_3, int32_t param_4,
                      float* param_5, float* param_6, float* param_7, uint32_t param_8,
                      float* param_9, float* param_10)
{
    float local_a8;
    float local_a4;
    float local_a0;
    float blk[5];   // listing s local_9c[4] followed by local_98/local_94/local_90/local_8c
    float local_94;
    float* local_88;
    float local_84;
    float local_80;
    float local_7c;
    float local_78;
    float local_74;
    float local_70;
    float local_6c;
    float local_68;
    float local_64;
    float local_60;
    float local_5c;
    float local_58;
    float local_54;
    float local_50;
    float local_4c;
    float local_48;
    float local_44;
    float local_40;
    float local_3c;
    float local_38;
    float local_34;
    float local_30;
    float local_2c;
    float local_20;
    float fVar3;
    float fVar4;
    float fVar5;
    float fVar6;
    float fVar7;
    float fVar8;
    float fVar9;
    char cVar10;
    float* pfVar11;
    float* pfVar1;
    float* pfVar2;
    long double fVar12;
    long double fVar13;
    uintptr_t p2 = static_cast<uintptr_t>(param_2);
    uintptr_t p4 = static_cast<uintptr_t>(param_4);

    local_3c = *reinterpret_cast<float*>(p4 + 0x10) * *reinterpret_cast<float*>(p4 + 0x10);
    pfVar11 = reinterpret_cast<float*>(p2 + 0x10);
    pfVar1 = reinterpret_cast<float*>(p4 + 4);
    local_84 = *pfVar1;
    local_58 = *reinterpret_cast<float*>(p2 + 0x34) + *reinterpret_cast<float*>(p2 + 0x34);
    local_80 = *reinterpret_cast<float*>(p4 + 8);
    local_7c = *reinterpret_cast<float*>(p4 + 0xc);
    local_60 = local_58 * *pfVar11;
    pfVar2 = reinterpret_cast<float*>(p2 + 0x1c);
    local_5c = local_58 * *reinterpret_cast<float*>(p2 + 0x14);
    local_58 = local_58 * *reinterpret_cast<float*>(p2 + 0x18);
    local_4c = *reinterpret_cast<float*>(p2 + 0x38) + *reinterpret_cast<float*>(p2 + 0x38);
    local_54 = local_4c * *pfVar2;
    local_50 = local_4c * *reinterpret_cast<float*>(p2 + 0x20);
    local_4c = local_4c * *reinterpret_cast<float*>(p2 + 0x24);
    local_88 = reinterpret_cast<float*>(p2 + 0x28);
    local_40 = *reinterpret_cast<float*>(p2 + 0x3c) + *reinterpret_cast<float*>(p2 + 0x3c);
    local_48 = local_40 * *local_88;
    local_44 = local_40 * *reinterpret_cast<float*>(p2 + 0x2c);
    local_40 = local_40 * *reinterpret_cast<float*>(p2 + 0x30);
    local_a8 = (local_54 + local_60 + local_48) * 0.5f;
    local_a4 = (local_50 + local_5c + local_44) * 0.5f;
    local_6c = *reinterpret_cast<float*>(p2 + 4) - local_a8;
    local_68 = *reinterpret_cast<float*>(p2 + 8) - local_a4;
    local_64 = *reinterpret_cast<float*>(p2 + 0xc) - (local_40 + local_4c + local_58) * 0.5f;
    fVar12 = (long double)FUN_00599230(&local_84, &local_6c, &local_38, &local_34, &local_30);
    fVar12 = fVar12 - (long double)local_3c;
    local_2c = static_cast<float>(fVar12);
    fVar13 = (long double)0.0;
    if ((std::isnan(fVar12) || std::isnan(fVar13)) ||
        ((fVar12 < fVar13) == (fVar12 == fVar13))) {
        local_78 = *param_5 - *param_3;
        local_74 = param_5[1] - param_3[1];
        local_70 = param_5[2] - param_3[2];
        fVar3 = (local_78 * local_78 + local_74 * local_74 + local_70 * local_70) * param_1;
        if (std::isnan(fVar3) || ((fVar3 < 1e-05f) == (fVar3 == 1e-05f))) {
            FUN_00599e90(FUN_00585940, 4, 4, &local_84);
            fVar13 = (long double)FUN_00585940(param_1, &local_84);
            cVar10 = FUN_0059a040(0, local_2c, param_1, static_cast<float>(fVar13), param_6);
            if (cVar10 != '\0') {
                fVar3 = *param_6;
                local_6c = fVar3 * *param_3 + local_6c;
                local_68 = local_68 + fVar3 * param_3[1];
                local_64 = local_64 + fVar3 * param_3[2];
                fVar3 = *param_6;
                local_84 = fVar3 * *param_5 + local_84;
                local_80 = local_80 + fVar3 * param_5[1];
                local_7c = local_7c + fVar3 * param_5[2];
                FUN_00599230(&local_84, &local_6c, &local_38, &local_34, &local_30);
                local_20 = local_4c * local_34;
                local_a8 = local_60 * local_38 + local_6c + local_54 * local_34;
                local_a0 = local_58 * local_38 + local_64 + local_20;
                *param_7 = local_a8 + local_48 * local_30;
                param_7[1] = local_5c * local_38 + local_68 + local_50 * local_34 +
                             local_44 * local_30;
                param_7[2] = local_a0 + local_40 * local_30;
                if (static_cast<char>(param_8) == '\0') {
                    return 1;
                }
                fVar3 = *param_6;
                fVar7 = param_5[1];
                fVar9 = param_5[2];
                fVar4 = *reinterpret_cast<float*>(p4 + 8);
                fVar5 = *reinterpret_cast<float*>(p4 + 0xc);
                fVar8 = param_7[1];
                fVar6 = param_7[2];
                *param_10 = *param_7 - (fVar3 * *param_5 + *pfVar1);
                param_10[1] = fVar8 - (fVar3 * fVar7 + fVar4);
                param_10[2] = fVar6 - (fVar3 * fVar9 + fVar5);
                fVar3 = *param_6;
                fVar7 = param_3[1];
                fVar9 = *reinterpret_cast<float*>(p2 + 8);
                local_94 = fVar3 * param_3[2] + *reinterpret_cast<float*>(p2 + 0xc);
                fVar4 = param_7[1];
                fVar5 = param_7[2];
                *param_9 = *param_7 - (fVar3 * *param_3 + *reinterpret_cast<float*>(p2 + 4));
                param_9[1] = fVar4 - (fVar3 * fVar7 + fVar9);
                param_9[2] = fVar5 - local_94;
                fVar4 = *pfVar11 * *param_9 +
                        *reinterpret_cast<float*>(p2 + 0x14) * param_9[1] +
                        *reinterpret_cast<float*>(p2 + 0x18) * param_9[2];
                fVar5 = *pfVar2 * *param_9 +
                        *reinterpret_cast<float*>(p2 + 0x20) * param_9[1] +
                        *reinterpret_cast<float*>(p2 + 0x24) * param_9[2];
                fVar8 = *local_88 * *param_9 + local_88[1] * param_9[1] +
                        local_88[2] * param_9[2];
                fVar3 = param_9[2];
                fVar7 = param_9[1];
                fVar9 = *param_9;
                *param_9 = DAT_00727430;
                param_9[1] = DAT_00727434;
                param_9[2] = DAT_00727438;
                fVar3 = (fVar3 * fVar3 + fVar7 * fVar7 + fVar9 * fVar9) * 0.0001f;
                if (*reinterpret_cast<float*>(p2 + 0x34) - std::fabs(fVar4) < fVar3) {
                    pfVar11 = reinterpret_cast<float*>(FUN_00431450(blk, fVar4, pfVar11));
                    local_a8 = *pfVar11;
                    local_a4 = pfVar11[1];
                    local_a0 = pfVar11[2];
                    FUN_00491640();
                    FUN_00431420(&local_a8);
                }
                if (*reinterpret_cast<float*>(p2 + 0x38) - std::fabs(fVar5) < fVar3) {
                    pfVar11 = reinterpret_cast<float*>(FUN_00431450(blk, fVar5, pfVar2));
                    local_a8 = *pfVar11;
                    local_a4 = pfVar11[1];
                    local_a0 = pfVar11[2];
                    FUN_00491640();
                    FUN_00431420(&local_a8);
                }
                if (*reinterpret_cast<float*>(p2 + 0x3c) - std::fabs(fVar8) < fVar3) {
                    pfVar11 = reinterpret_cast<float*>(FUN_00431450(blk, fVar8, local_88));
                    local_a8 = *pfVar11;
                    local_a4 = pfVar11[1];
                    local_a0 = pfVar11[2];
                    FUN_00491640();
                    FUN_00431420(&local_a8);
                }
                FUN_00491640();
                FUN_00491640();
                return 1;
            }
        }
        return 0;
    }
    *param_6 = 0.0f;
    fVar3 = (param_5[2] * param_5[2] + param_5[1] * param_5[1] + *param_5 * *param_5) -
            (param_3[2] * param_3[2] + param_3[1] * param_3[1] + *param_3 * *param_3);
    if (1e-05f < fVar3) {
        FUN_0058fca0(0x3f800000, &DAT_00727430);
        blk[1] = *pfVar1 - *param_5;
        blk[2] = *reinterpret_cast<float*>(p4 + 8) - param_5[1];
        blk[3] = *reinterpret_cast<float*>(p4 + 0xc) - param_5[2];
        blk[4] = *reinterpret_cast<float*>(p4 + 0x10);
        cVar10 = static_cast<char>(FUN_00589bf0(param_1, param_2, param_3,
                                                static_cast<int32_t>(reinterpret_cast<uintptr_t>(blk)),
                                                &DAT_00727430));
        while (cVar10 != '\0') {
            blk[1] = blk[1] - *param_5;
            blk[2] = blk[2] - param_5[1];
            blk[3] = blk[3] - param_5[2];
            cVar10 = static_cast<char>(FUN_00589bf0(
                param_1, param_2, param_3, static_cast<int32_t>(reinterpret_cast<uintptr_t>(blk)),
                &DAT_00727430));
        }
        cVar10 = static_cast<char>(FUN_0058a2e0(
            param_1, param_2, param_3, static_cast<int32_t>(reinterpret_cast<uintptr_t>(blk)),
            param_5, &local_2c, param_7, param_8, param_9, param_10));
        if (cVar10 == '\x01') {
            return 1;
        }
    }
    if (-1e-05f <= fVar3) {
        fVar3 = *reinterpret_cast<float*>(p2 + 8);
        fVar7 = *reinterpret_cast<float*>(p4 + 8);
        local_a0 = *reinterpret_cast<float*>(p2 + 0xc) + *reinterpret_cast<float*>(p4 + 0xc);
        *param_7 = (*reinterpret_cast<float*>(p2 + 4) + *pfVar1) * 0.5f;
        param_7[1] = (fVar3 + fVar7) * 0.5f;
        param_7[2] = local_a0 * 0.5f;
        if (static_cast<char>(param_8) == '\0') {
            return 1;
        }
        fVar3 = param_7[1];
        fVar7 = *reinterpret_cast<float*>(p4 + 8);
        fVar9 = param_7[2];
        fVar4 = *reinterpret_cast<float*>(p4 + 0xc);
        *param_10 = *param_7 - *pfVar1;
        param_10[1] = fVar3 - fVar7;
        param_10[2] = fVar9 - fVar4;
        FUN_00491640();
    }
    else {
        fVar7 = *param_3;
        fVar8 = param_3[1];
        fVar9 = param_3[2];
        FUN_00491640();
        fVar3 = *reinterpret_cast<float*>(p4 + 0x10);
        local_a0 = fVar9 + fVar9;
        local_a8 = *reinterpret_cast<float*>(p2 + 4) - (fVar7 + fVar7) * fVar3;
        fVar7 = *reinterpret_cast<float*>(p2 + 8);
        fVar9 = *reinterpret_cast<float*>(p2 + 0xc);
        fVar4 = *reinterpret_cast<float*>(p4 + 8);
        fVar5 = *reinterpret_cast<float*>(p4 + 0xc);
        *param_10 = local_a8 - *pfVar1;
        param_10[1] = (fVar7 - (fVar8 + fVar8) * fVar3) - fVar4;
        param_10[2] = (fVar9 - local_a0 * fVar3) - fVar5;
        FUN_00491640();
        fVar3 = *reinterpret_cast<float*>(p4 + 0x10);
        fVar7 = param_10[1];
        fVar9 = param_10[2];
        *param_7 = fVar3 * *param_10;
        param_7[1] = fVar3 * fVar7;
        param_7[2] = fVar3 * fVar9;
        if (static_cast<char>(param_8) == '\0') {
            return 1;
        }
    }
    fVar3 = param_10[1];
    fVar7 = param_10[2];
    *param_9 = -*param_10;
    param_9[1] = -fVar3;
    param_9[2] = -fVar7;
    return 1;
}

// ---------------------------------------------------------------------------
// 0x58ad60
// ---------------------------------------------------------------------------
// 0x58ad60 — observed shape
// Clamps the contact point into the reference box, then repeats for the second
// box, projecting along the three local axes with a 0.99 slop.
void FUN_0058ad60(float param_1, int32_t param_2, float* param_3, int32_t param_4, float* param_5,
                  float* param_6, float* param_7)
{
    float fVar1;
    float fVar2;
    float fVar3;
    float fVar4;
    float fVar5;
    float fVar6;
    float fVar7;
    float fVar8;
    float fVar9;
    float fVar10;
    char cVar11;
    float local_50;
    float local_4c;
    VecBlock local_14;
    uintptr_t p2 = static_cast<uintptr_t>(param_2);
    uintptr_t p4 = static_cast<uintptr_t>(param_4);

    FUN_0058fca0(0x3f800000, &DAT_00727430);
    local_14.x = *param_7;
    local_14.y = param_7[1];
    local_14.z = param_7[2];
    local_14.w = 0x3c23d70a;
    cVar11 = static_cast<char>(FUN_00589bf0(
        param_1, param_2, param_3, static_cast<int32_t>(reinterpret_cast<uintptr_t>(&local_14)),
        &DAT_00727430));
    if (cVar11 == '\0') {
        fVar1 = *param_6;
        fVar8 = fVar1 * *param_3 + *reinterpret_cast<float*>(p2 + 4);
        fVar9 = fVar1 * param_3[1] + *reinterpret_cast<float*>(p2 + 8);
        fVar10 = fVar1 * param_3[2] + *reinterpret_cast<float*>(p2 + 0xc);
        fVar1 = *param_7 - fVar8;
        fVar3 = param_7[1] - fVar9;
        fVar2 = param_7[2] - fVar10;
        local_50 = fVar1 * *reinterpret_cast<float*>(p2 + 0x10) +
                   fVar3 * *reinterpret_cast<float*>(p2 + 0x14) +
                   fVar2 * *reinterpret_cast<float*>(p2 + 0x18);
        local_4c = fVar1 * *reinterpret_cast<float*>(p2 + 0x1c) +
                   fVar3 * *reinterpret_cast<float*>(p2 + 0x20) +
                   fVar2 * *reinterpret_cast<float*>(p2 + 0x24);
        fVar1 = fVar1 * *reinterpret_cast<float*>(p2 + 0x28) +
                fVar3 * *reinterpret_cast<float*>(p2 + 0x2c) +
                fVar2 * *reinterpret_cast<float*>(p2 + 0x30);
        fVar2 = *reinterpret_cast<float*>(p2 + 0x34) * 0.99f;
        if (local_50 <= fVar2) {
            if (local_50 < -fVar2) {
                local_50 = -*reinterpret_cast<float*>(p2 + 0x34);
            }
        }
        else {
            local_50 = *reinterpret_cast<float*>(p2 + 0x34);
        }
        fVar2 = *reinterpret_cast<float*>(p2 + 0x38) * 0.99f;
        if (local_4c <= fVar2) {
            if (local_4c < -fVar2) {
                local_4c = -*reinterpret_cast<float*>(p2 + 0x38);
            }
        }
        else {
            local_4c = *reinterpret_cast<float*>(p2 + 0x38);
        }
        fVar2 = *reinterpret_cast<float*>(p2 + 0x3c) * 0.99f;
        if (fVar1 <= fVar2) {
            if (fVar1 < -fVar2) {
                fVar1 = -*reinterpret_cast<float*>(p2 + 0x3c);
            }
        }
        else {
            fVar1 = *reinterpret_cast<float*>(p2 + 0x3c);
        }
        fVar2 = *reinterpret_cast<float*>(p2 + 0x2c);
        fVar3 = *reinterpret_cast<float*>(p2 + 0x30);
        fVar4 = *reinterpret_cast<float*>(p2 + 0x20);
        fVar5 = *reinterpret_cast<float*>(p2 + 0x24);
        fVar6 = *reinterpret_cast<float*>(p2 + 0x14);
        fVar7 = *reinterpret_cast<float*>(p2 + 0x18);
        *param_7 = local_50 * *reinterpret_cast<float*>(p2 + 0x10) + fVar8 +
                   local_4c * *reinterpret_cast<float*>(p2 + 0x1c) +
                   fVar1 * *reinterpret_cast<float*>(p2 + 0x28);
        param_7[1] = local_50 * fVar6 + fVar9 + local_4c * fVar4 + fVar1 * fVar2;
        param_7[2] = local_50 * fVar7 + fVar10 + local_4c * fVar5 + fVar1 * fVar3;
    }
    cVar11 = static_cast<char>(FUN_00589bf0(
        param_1, param_4, param_5, static_cast<int32_t>(reinterpret_cast<uintptr_t>(&local_14)),
        &DAT_00727430));
    if (cVar11 == '\0') {
        fVar1 = *param_6;
        fVar8 = fVar1 * *param_5 + *reinterpret_cast<float*>(p4 + 4);
        fVar9 = fVar1 * param_5[1] + *reinterpret_cast<float*>(p4 + 8);
        fVar10 = fVar1 * param_5[2] + *reinterpret_cast<float*>(p4 + 0xc);
        fVar1 = *param_7 - fVar8;
        fVar3 = param_7[1] - fVar9;
        fVar2 = param_7[2] - fVar10;
        local_50 = fVar1 * *reinterpret_cast<float*>(p4 + 0x10) +
                   fVar3 * *reinterpret_cast<float*>(p4 + 0x14) +
                   fVar2 * *reinterpret_cast<float*>(p4 + 0x18);
        local_4c = fVar1 * *reinterpret_cast<float*>(p4 + 0x1c) +
                   fVar3 * *reinterpret_cast<float*>(p4 + 0x20) +
                   fVar2 * *reinterpret_cast<float*>(p4 + 0x24);
        fVar1 = fVar1 * *reinterpret_cast<float*>(p4 + 0x28) +
                fVar3 * *reinterpret_cast<float*>(p4 + 0x2c) +
                fVar2 * *reinterpret_cast<float*>(p4 + 0x30);
        fVar2 = *reinterpret_cast<float*>(p4 + 0x34) * 0.99f;
        if (local_50 <= fVar2) {
            if (local_50 < -fVar2) {
                local_50 = -*reinterpret_cast<float*>(p4 + 0x34);
            }
        }
        else {
            local_50 = *reinterpret_cast<float*>(p4 + 0x34);
        }
        fVar2 = *reinterpret_cast<float*>(p4 + 0x38) * 0.99f;
        if (local_4c <= fVar2) {
            if (local_4c < -fVar2) {
                local_4c = -*reinterpret_cast<float*>(p4 + 0x38);
            }
        }
        else {
            local_4c = *reinterpret_cast<float*>(p4 + 0x38);
        }
        fVar2 = *reinterpret_cast<float*>(p4 + 0x3c) * 0.99f;
        if (fVar1 <= fVar2) {
            if (fVar1 < -fVar2) {
                fVar1 = -*reinterpret_cast<float*>(p4 + 0x3c);
            }
        }
        else {
            fVar1 = *reinterpret_cast<float*>(p4 + 0x3c);
        }
        fVar2 = *reinterpret_cast<float*>(p4 + 0x2c);
        fVar3 = *reinterpret_cast<float*>(p4 + 0x30);
        fVar4 = *reinterpret_cast<float*>(p4 + 0x20);
        fVar5 = *reinterpret_cast<float*>(p4 + 0x24);
        fVar6 = *reinterpret_cast<float*>(p4 + 0x14);
        fVar7 = *reinterpret_cast<float*>(p4 + 0x18);
        *param_7 = local_50 * *reinterpret_cast<float*>(p4 + 0x10) + fVar8 +
                   local_4c * *reinterpret_cast<float*>(p4 + 0x1c) +
                   fVar1 * *reinterpret_cast<float*>(p4 + 0x28);
        param_7[1] = local_50 * fVar6 + fVar9 + local_4c * fVar4 + fVar1 * fVar2;
        param_7[2] = local_50 * fVar7 + fVar10 + local_4c * fVar5 + fVar1 * fVar3;
    }
}

// ---------------------------------------------------------------------------
// 0x58b940
// ---------------------------------------------------------------------------
// 0x58b940 — observed shape
// Swept contact between two oriented boxes: accumulates the earliest time of
// impact over the sixteen separating axes, then dispatches on the winning axis
// to place the contact point and emit the surface normals.
uint16_t FUN_0058b940(float param_1, float* param_2, float* param_3, float* param_4, float* param_5,
                      float* param_6, float* param_7, uint32_t param_8, float* param_9,
                      float* param_10)
{
    float fVar1;
    float fVar2;
    float fVar3;
    int32_t iVar4;
    char cVar5;
    float* pfVar6;
    float* pfVar8;
    float* pfVar9;
    int32_t iVar10;
    uint32_t uVar11;
    long double fVar12;
    float* pfVar13;
    float* pfVar14;
    float* pfVar15;
    uint32_t* puVar16;
    float local_134;
    float* pfPlane;
    float denom;
    float negI;
    void* pv;
    float local_130;
    int32_t local_12c;
    float local_128;
    float local_124;
    float local_120;
    float local_11c;
    float local_118;
    float local_114;
    float local_110;
    float local_10c;
    float local_108;
    float local_104[38];
    float s_6c[3];
    float s_60[3];
    float s_54[3];
    float s_48[3];
    float s_3c[3];
    float s_30[3];
    float s_24[3];
    float s_18[3];
    float s_c[3];

    pfVar9 = param_2 + 4;
    local_104[1] = *param_5 - *param_3;
    local_104[2] = param_5[1] - param_3[1];
    local_104[3] = param_5[2] - param_3[2];
    local_118 = param_4[1] - param_2[1];
    local_114 = param_4[2] - param_2[2];
    local_110 = param_4[3] - param_2[3];
    local_104[0x13] = (*param_5 - *param_3) * param_1 + local_118;
    local_104[0x14] = local_114 + (param_5[1] - param_3[1]) * param_1;
    local_104[0x15] = local_110 + (param_5[2] - param_3[2]) * param_1;
    uVar11 = 0;
    iVar10 = 0;
    *param_6 = 0.0f;
    local_12c = 0;

    local_104[4] = param_4[4] * *pfVar9 + param_4[5] * param_2[5] + param_4[6] * param_2[6];
    local_104[5] = *pfVar9 * param_4[7] + param_4[9] * param_2[6] + param_4[8] * param_2[5];
    local_104[6] = *pfVar9 * param_4[10] + param_4[0xc] * param_2[6] + param_4[0xb] * param_2[5];
    local_124 = local_114 * param_2[5] + local_118 * *pfVar9 + local_110 * param_2[6];
    local_10c = local_104[0x14] * param_2[5] + local_104[0x13] * *pfVar9 +
                local_104[0x15] * param_2[6];
    local_104[0x16] = std::fabs(local_104[4]);
    local_104[0x17] = std::fabs(local_104[5]);
    local_104[0x18] = std::fabs(local_104[6]);
    fVar1 = local_104[0x16] * param_4[0xd] + local_104[0x18] * param_4[0xf] +
            local_104[0x17] * param_4[0xe] + param_2[0xd];
    if (local_124 <= fVar1) {
        if (local_124 < -fVar1) {
            if (local_10c < -fVar1) {
                return 0;
            }
            fVar1 = -(((fVar1 + local_124) * param_1) / (local_10c - local_124));
            if (0.0f < fVar1) {
                iVar10 = -1;
                *param_6 = fVar1;
                uVar11 = 1;
                local_12c = -1;
            }
        }
    }
    else {
        if (fVar1 < local_10c) {
            return 0;
        }
        fVar1 = ((fVar1 - local_124) * param_1) / (local_10c - local_124);
        if (0.0f < fVar1) {
            uVar11 = 1;
            *param_6 = fVar1;
            iVar10 = 1;
            local_12c = 1;
        }
    }

    local_104[7] = param_4[4] * param_2[7] + param_2[9] * param_4[6] + param_2[8] * param_4[5];
    local_104[8] = param_4[7] * param_2[7] + param_4[8] * param_2[8] + param_4[9] * param_2[9];
    local_104[9] = param_4[10] * param_2[7] + param_4[0xb] * param_2[8] + param_4[0xc] * param_2[9];
    local_120 = local_118 * param_2[7] + local_110 * param_2[9] + local_114 * param_2[8];
    local_108 = local_104[0x13] * param_2[7] + local_104[0x15] * param_2[9] +
                local_104[0x14] * param_2[8];
    local_104[0x19] = std::fabs(local_104[7]);
    local_104[0x1a] = std::fabs(local_104[8]);
    local_104[0x1b] = std::fabs(local_104[9]);
    fVar1 = local_104[0x19] * param_4[0xd] + local_104[0x1b] * param_4[0xf] +
            local_104[0x1a] * param_4[0xe] + param_2[0xe];
    if (local_120 <= fVar1) {
        if (local_120 < -fVar1) {
            if (local_108 < -fVar1) {
                return 0;
            }
            fVar1 = -(((local_120 + fVar1) * param_1) / (local_108 - local_120));
            if (*param_6 < fVar1) {
                iVar10 = -1;
                *param_6 = fVar1;
                uVar11 = 2;
                local_12c = -1;
            }
        }
    }
    else {
        if (fVar1 < local_108) {
            return 0;
        }
        fVar1 = ((fVar1 - local_120) * param_1) / (local_108 - local_120);
        if (*param_6 < fVar1) {
            iVar10 = 1;
            *param_6 = fVar1;
            uVar11 = 2;
            local_12c = 1;
        }
    }

    local_104[10] = param_4[4] * param_2[10] + param_2[0xc] * param_4[6] +
                    param_2[0xb] * param_4[5];
    local_104[0xb] = param_4[7] * param_2[10] + param_4[8] * param_2[0xb] +
                     param_4[9] * param_2[0xc];
    local_104[0xc] = param_4[10] * param_2[10] + param_4[0xb] * param_2[0xb] +
                     param_4[0xc] * param_2[0xc];
    local_11c = local_118 * param_2[10] + local_110 * param_2[0xc] + local_114 * param_2[0xb];
    local_104[0] = local_104[0x13] * param_2[10] + local_104[0x15] * param_2[0xc] +
                   local_104[0x14] * param_2[0xb];
    local_104[0x1c] = std::fabs(local_104[10]);
    local_104[0x1d] = std::fabs(local_104[0xb]);
    local_104[0x1e] = std::fabs(local_104[0xc]);
    fVar1 = local_104[0x1c] * param_4[0xd] + local_104[0x1e] * param_4[0xf] +
            local_104[0x1d] * param_4[0xe] + param_2[0xf];
    if (local_11c <= fVar1) {
        if (local_11c < -fVar1) {
            if (local_104[0] < -fVar1) {
                return 0;
            }
            fVar1 = -(((local_11c + fVar1) * param_1) / (local_104[0] - local_11c));
            if (*param_6 < fVar1) {
                iVar10 = -1;
                *param_6 = fVar1;
                uVar11 = 3;
                local_12c = -1;
            }
        }
    }
    else {
        if (fVar1 < local_104[0]) {
            return 0;
        }
        fVar1 = ((fVar1 - local_11c) * param_1) / (local_104[0] - local_11c);
        if (*param_6 < fVar1) {
            iVar10 = 1;
            *param_6 = fVar1;
            uVar11 = 3;
            local_12c = 1;
        }
    }

    local_104[0xd] = local_110 * param_4[6] + local_118 * param_4[4] + local_114 * param_4[5];
    local_104[0x10] = local_104[0x15] * param_4[6] + local_104[0x13] * param_4[4] +
                      local_104[0x14] * param_4[5];
    fVar1 = local_104[0x16] * param_2[0xd] + local_104[0x19] * param_2[0xe] +
            local_104[0x1c] * param_2[0xf] + param_4[0xd];
    if (local_104[0xd] <= fVar1) {
        if (local_104[0xd] < -fVar1) {
            if (local_104[0x10] < -fVar1) {
                return 0;
            }
            fVar1 = -(((local_104[0xd] + fVar1) * param_1) / (local_104[0x10] - local_104[0xd]));
            if (*param_6 < fVar1) {
                iVar10 = -1;
                *param_6 = fVar1;
                uVar11 = 4;
                local_12c = -1;
            }
        }
    }
    else {
        if (fVar1 < local_104[0x10]) {
            return 0;
        }
        fVar1 = ((fVar1 - local_104[0xd]) * param_1) / (local_104[0x10] - local_104[0xd]);
        if (*param_6 < fVar1) {
            iVar10 = 1;
            *param_6 = fVar1;
            uVar11 = 4;
            local_12c = 1;
        }
    }

    local_104[0xe] = local_118 * param_4[7] + local_110 * param_4[9] + local_114 * param_4[8];
    local_104[0x11] = local_104[0x13] * param_4[7] + local_104[0x15] * param_4[9] +
                      local_104[0x14] * param_4[8];
    fVar1 = local_104[0x17] * param_2[0xd] + local_104[0x1a] * param_2[0xe] +
            local_104[0x1d] * param_2[0xf] + param_4[0xe];
    if (local_104[0xe] <= fVar1) {
        if (local_104[0xe] < -fVar1) {
            if (local_104[0x11] < -fVar1) {
                return 0;
            }
            fVar1 = -(((local_104[0xe] + fVar1) * param_1) / (local_104[0x11] - local_104[0xe]));
            if (*param_6 < fVar1) {
                iVar10 = -1;
                *param_6 = fVar1;
                uVar11 = 5;
                local_12c = -1;
            }
        }
    }
    else {
        if (fVar1 < local_104[0x11]) {
            return 0;
        }
        fVar1 = ((fVar1 - local_104[0xe]) * param_1) / (local_104[0x11] - local_104[0xe]);
        if (*param_6 < fVar1) {
            iVar10 = 1;
            *param_6 = fVar1;
            uVar11 = 5;
            local_12c = 1;
        }
    }

    local_104[0xf] = local_118 * param_4[10] + local_110 * param_4[0xc] + local_114 * param_4[0xb];
    local_104[0x12] = local_104[0x13] * param_4[10] + local_104[0x15] * param_4[0xc] +
                      local_104[0x14] * param_4[0xb];
    fVar1 = local_104[0x18] * param_2[0xd] + local_104[0x1e] * param_2[0xf] +
            local_104[0x1b] * param_2[0xe] + param_4[0xf];
    if (local_104[0xf] <= fVar1) {
        if (local_104[0xf] < -fVar1) {
            if (local_104[0x12] < -fVar1) {
                return 0;
            }
            fVar1 = -(((local_104[0xf] + fVar1) * param_1) / (local_104[0x12] - local_104[0xf]));
            if (*param_6 < fVar1) {
                iVar10 = -1;
                *param_6 = fVar1;
                uVar11 = 6;
                local_12c = -1;
            }
        }
    }
    else {
        if (fVar1 < local_104[0x12]) {
            return 0;
        }
        fVar1 = ((fVar1 - local_104[0xf]) * param_1) / (local_104[0x12] - local_104[0xf]);
        if (*param_6 < fVar1) {
            iVar10 = 1;
            *param_6 = fVar1;
            uVar11 = 6;
            local_12c = 1;
        }
    }

    fVar1 = local_11c * local_104[7] - local_104[10] * local_120;
    fVar2 = local_104[0x1c] * param_2[0xe] + local_104[0x19] * param_2[0xf] +
            local_104[0x17] * param_4[0xf] + local_104[0x18] * param_4[0xe];
    if (fVar2 < fVar1) {
        fVar3 = local_104[0] * local_104[7] - local_104[10] * local_108;
        if (fVar2 < fVar3) {
            return 0;
        }
        fVar1 = ((fVar2 - fVar1) * param_1) / (fVar3 - fVar1);
        if (*param_6 < fVar1) {
            iVar10 = 1;
            *param_6 = fVar1;
            uVar11 = 7;
            local_12c = 1;
        }
    }
    else {
        local_134 = -fVar2;
        if (fVar1 < local_134) {
            fVar3 = local_104[0] * local_104[7] - local_104[10] * local_108;
            if (fVar3 < local_134) {
                return 0;
            }
            fVar1 = -(((fVar1 + fVar2) * param_1) / (fVar3 - fVar1));
            if (*param_6 < fVar1) {
                iVar10 = -1;
                *param_6 = fVar1;
                uVar11 = 7;
                local_12c = -1;
            }
        }
    }

    fVar1 = local_11c * local_104[8] - local_104[0xb] * local_120;
    fVar2 = local_104[0x16] * param_4[0xf] + local_104[0x18] * param_4[0xd] +
            local_104[0x1d] * param_2[0xe] + local_104[0x1a] * param_2[0xf];
    if (fVar1 <= fVar2) {
        local_134 = -fVar2;
        if (fVar1 < local_134) {
            fVar3 = local_104[0] * local_104[8] - local_104[0xb] * local_108;
            if (fVar3 < local_134) {
                return 0;
            }
            fVar1 = -(((fVar1 + fVar2) * param_1) / (fVar3 - fVar1));
            if (*param_6 < fVar1) {
                iVar10 = -1;
                *param_6 = fVar1;
                uVar11 = 8;
                local_12c = -1;
            }
        }
    }
    else {
        fVar3 = local_104[0] * local_104[8] - local_104[0xb] * local_108;
        if (fVar2 < fVar3) {
            return 0;
        }
        fVar1 = ((fVar2 - fVar1) * param_1) / (fVar3 - fVar1);
        if (*param_6 < fVar1) {
            iVar10 = 1;
            *param_6 = fVar1;
            uVar11 = 8;
            local_12c = 1;
        }
    }

    fVar1 = local_11c * local_104[9] - local_104[0xc] * local_120;
    fVar2 = local_104[0x1e] * param_2[0xe] + local_104[0x1b] * param_2[0xf] +
            local_104[0x17] * param_4[0xd] + local_104[0x16] * param_4[0xe];
    if (fVar1 <= fVar2) {
        local_134 = -fVar2;
        if (fVar1 < local_134) {
            fVar3 = local_104[0] * local_104[9] - local_104[0xc] * local_108;
            if (fVar3 < local_134) {
                return 0;
            }
            fVar1 = -(((fVar1 + fVar2) * param_1) / (fVar3 - fVar1));
            if (*param_6 < fVar1) {
                iVar10 = -1;
                *param_6 = fVar1;
                uVar11 = 9;
                local_12c = -1;
            }
        }
    }
    else {
        fVar3 = local_104[0] * local_104[9] - local_104[0xc] * local_108;
        if (fVar2 < fVar3) {
            return 0;
        }
        fVar1 = ((fVar2 - fVar1) * param_1) / (fVar3 - fVar1);
        if (*param_6 < fVar1) {
            iVar10 = 1;
            *param_6 = fVar1;
            uVar11 = 9;
            local_12c = 1;
        }
    }

    fVar1 = local_104[10] * local_124 - local_11c * local_104[4];
    fVar2 = local_104[0x1c] * param_2[0xd] + local_104[0x16] * param_2[0xf] +
            local_104[0x1a] * param_4[0xf] + local_104[0x1b] * param_4[0xe];
    if (fVar1 <= fVar2) {
        local_134 = -fVar2;
        if (fVar1 < local_134) {
            fVar3 = local_104[10] * local_10c - local_104[0] * local_104[4];
            if (fVar3 < local_134) {
                return 0;
            }
            fVar1 = -(((fVar1 + fVar2) * param_1) / (fVar3 - fVar1));
            if (*param_6 < fVar1) {
                iVar10 = -1;
                *param_6 = fVar1;
                uVar11 = 10;
                local_12c = -1;
            }
        }
    }
    else {
        fVar3 = local_104[10] * local_10c - local_104[0] * local_104[4];
        if (fVar2 < fVar3) {
            return 0;
        }
        fVar1 = ((fVar2 - fVar1) * param_1) / (fVar3 - fVar1);
        if (*param_6 < fVar1) {
            iVar10 = 1;
            *param_6 = fVar1;
            uVar11 = 10;
            local_12c = 1;
        }
    }

    fVar1 = local_104[0xb] * local_124 - local_11c * local_104[5];
    fVar2 = local_104[0x1d] * param_2[0xd] + local_104[0x17] * param_2[0xf] +
            local_104[0x19] * param_4[0xf] + local_104[0x1b] * param_4[0xd];
    if (fVar1 <= fVar2) {
        local_134 = -fVar2;
        if (fVar1 < local_134) {
            fVar3 = local_104[0xb] * local_10c - local_104[0] * local_104[5];
            if (fVar3 < local_134) {
                return 0;
            }
            fVar1 = -(((fVar1 + fVar2) * param_1) / (fVar3 - fVar1));
            if (*param_6 < fVar1) {
                iVar10 = -1;
                *param_6 = fVar1;
                uVar11 = 0xb;
                local_12c = -1;
            }
        }
    }
    else {
        fVar3 = local_104[0xb] * local_10c - local_104[0] * local_104[5];
        if (fVar2 < fVar3) {
            return 0;
        }
        fVar1 = ((fVar2 - fVar1) * param_1) / (fVar3 - fVar1);
        if (*param_6 < fVar1) {
            iVar10 = 1;
            *param_6 = fVar1;
            uVar11 = 0xb;
            local_12c = 1;
        }
    }

    fVar1 = local_104[0xc] * local_124 - local_11c * local_104[6];
    fVar2 = local_104[0x1e] * param_2[0xd] + local_104[0x18] * param_2[0xf] +
            local_104[0x1a] * param_4[0xd] + local_104[0x19] * param_4[0xe];
    if (fVar1 <= fVar2) {
        local_134 = -fVar2;
        if (fVar1 < local_134) {
            fVar3 = local_104[0xc] * local_10c - local_104[0] * local_104[6];
            if (fVar3 < local_134) {
                return 0;
            }
            fVar1 = -(((fVar1 + fVar2) * param_1) / (fVar3 - fVar1));
            if (*param_6 < fVar1) {
                iVar10 = -1;
                *param_6 = fVar1;
                uVar11 = 0xc;
                local_12c = -1;
            }
        }
    }
    else {
        fVar3 = local_104[0xc] * local_10c - local_104[0] * local_104[6];
        if (fVar2 < fVar3) {
            return 0;
        }
        fVar1 = ((fVar2 - fVar1) * param_1) / (fVar3 - fVar1);
        if (*param_6 < fVar1) {
            iVar10 = 1;
            *param_6 = fVar1;
            uVar11 = 0xc;
            local_12c = 1;
        }
    }

    fVar1 = local_120 * local_104[4] - local_104[7] * local_124;
    fVar2 = local_104[0x1d] * param_4[0xf] + local_104[0x1e] * param_4[0xe] +
            local_104[0x19] * param_2[0xd] + local_104[0x16] * param_2[0xe];
    if (fVar1 <= fVar2) {
        local_134 = -fVar2;
        if (fVar1 < local_134) {
            fVar3 = local_108 * local_104[4] - local_104[7] * local_10c;
            if (fVar3 < local_134) {
                return 0;
            }
            fVar1 = -(((fVar1 + fVar2) * param_1) / (fVar3 - fVar1));
            if (*param_6 < fVar1) {
                iVar10 = -1;
                *param_6 = fVar1;
                uVar11 = 0xd;
                local_12c = -1;
            }
        }
    }
    else {
        fVar3 = local_108 * local_104[4] - local_104[7] * local_10c;
        if (fVar2 < fVar3) {
            return 0;
        }
        fVar1 = ((fVar2 - fVar1) * param_1) / (fVar3 - fVar1);
        if (*param_6 < fVar1) {
            iVar10 = 1;
            *param_6 = fVar1;
            uVar11 = 0xd;
            local_12c = 1;
        }
    }

    fVar1 = local_120 * local_104[5] - local_104[8] * local_124;
    fVar2 = local_104[0x1c] * param_4[0xf] + local_104[0x1e] * param_4[0xd] +
            local_104[0x1a] * param_2[0xd] + local_104[0x17] * param_2[0xe];
    if (fVar1 <= fVar2) {
        local_134 = -fVar2;
        if (fVar1 < local_134) {
            fVar3 = local_108 * local_104[5] - local_104[8] * local_10c;
            if (fVar3 < local_134) {
                return 0;
            }
            fVar1 = -(((fVar1 + fVar2) * param_1) / (fVar3 - fVar1));
            if (*param_6 < fVar1) {
                iVar10 = -1;
                *param_6 = fVar1;
                uVar11 = 0xe;
                local_12c = -1;
            }
        }
    }
    else {
        fVar3 = local_108 * local_104[5] - local_104[8] * local_10c;
        if (fVar2 < fVar3) {
            return 0;
        }
        fVar1 = ((fVar2 - fVar1) * param_1) / (fVar3 - fVar1);
        if (*param_6 < fVar1) {
            iVar10 = 1;
            *param_6 = fVar1;
            uVar11 = 0xe;
            local_12c = 1;
        }
    }

    local_128 = local_120 * local_104[6] - local_104[9] * local_124;
    local_130 = local_104[0x1d] * param_4[0xd] + local_104[0x1c] * param_4[0xe] +
                local_104[0x1b] * param_2[0xd] + local_104[0x18] * param_2[0xe];
    if (local_128 <= local_130) {
        local_134 = -local_130;
        if (local_128 < local_134) {
            fVar1 = local_108 * local_104[6] - local_104[9] * local_10c;
            if (fVar1 < local_134) {
                return 0;
            }
            fVar1 = -(((local_128 + local_130) * param_1) / (fVar1 - local_128));
            if (*param_6 < fVar1) {
                iVar10 = -1;
                *param_6 = fVar1;
                uVar11 = 0xf;
                local_12c = -1;
            }
        }
    }
    else {
        fVar1 = local_108 * local_104[6] - local_104[9] * local_10c;
        if (local_130 < fVar1) {
            return 0;
        }
        fVar1 = ((local_130 - local_128) * param_1) / (fVar1 - local_128);
        if (fVar1 <= *param_6) {
            // listing rejoins the dispatch check (0xf < uVar11 can never hold here)
        }
        else {
            iVar10 = 1;
            *param_6 = fVar1;
            uVar11 = 0xf;
            local_12c = 1;
        }
    }

    pfVar8 = param_2;
    pfVar13 = param_3;
    pfVar14 = param_4;
    pfVar15 = param_5;
    switch (uVar11) {
    case 0:
        fVar12 = (long double)FUN_004d4bc0();
        local_134 = static_cast<float>(fVar12);
        fVar12 = (long double)FUN_004d4bc0();
        if ((long double)local_134 - fVar12 <= (long double)1e-06) {
            if ((long double)local_134 - fVar12 < (long double)-1e-06) {
                FUN_0058b8e0(param_2);
                pfVar8 = reinterpret_cast<float*>(FUN_004760c0(local_104 + 0x13, param_3));
                local_104[0x17] = *pfVar8;
                local_104[0x18] = pfVar8[1];
                local_104[0x19] = pfVar8[2];
                cVar5 = static_cast<char>(FUN_00583390(
                    param_1,
                    static_cast<int32_t>(reinterpret_cast<uintptr_t>(local_104 + 0x16)),
                    &DAT_00727430, static_cast<int32_t>(reinterpret_cast<uintptr_t>(param_4)),
                    param_5));
                while (cVar5 != '\0') {
                    pfVar8 = reinterpret_cast<float*>(FUN_004760c0(&local_10c, param_3));
                    local_104[0x17] = *pfVar8;
                    local_104[0x18] = pfVar8[1];
                    local_104[0x19] = pfVar8[2];
                    cVar5 = static_cast<char>(FUN_00583390(
                        param_1,
                        static_cast<int32_t>(reinterpret_cast<uintptr_t>(local_104 + 0x16)),
                        &DAT_00727430, static_cast<int32_t>(reinterpret_cast<uintptr_t>(param_4)),
                        param_5));
                }
                pfVar8 = local_104 + 0x16;
                pfVar13 = param_4;
            }
        }
        else {
            FUN_0058b8e0(param_4);
            pfVar8 = reinterpret_cast<float*>(FUN_004760c0(local_104 + 0x10, param_5));
            local_104[0x17] = *pfVar8;
            local_104[0x18] = pfVar8[1];
            local_104[0x19] = pfVar8[2];
            cVar5 = static_cast<char>(FUN_00583390(
                param_1, static_cast<int32_t>(reinterpret_cast<uintptr_t>(param_2)), param_3,
                static_cast<int32_t>(reinterpret_cast<uintptr_t>(local_104 + 0x16)),
                &DAT_00727430));
            while (cVar5 != '\0') {
                pfVar8 = reinterpret_cast<float*>(FUN_004760c0(local_104 + 0xd, param_5));
                local_104[0x17] = *pfVar8;
                local_104[0x18] = pfVar8[1];
                local_104[0x19] = pfVar8[2];
                cVar5 = static_cast<char>(FUN_00583390(
                    param_1, static_cast<int32_t>(reinterpret_cast<uintptr_t>(param_2)), param_3,
                    static_cast<int32_t>(reinterpret_cast<uintptr_t>(local_104 + 0x16)),
                    &DAT_00727430));
            }
            pfVar8 = param_2;
            pfVar13 = local_104 + 0x16;
        }
        // LAB_0058cf22
        FUN_0058b940(param_1, pfVar8, param_3, pfVar13, param_5, &local_134, param_7, param_8,
                     param_9, param_10);
        pfVar8 = reinterpret_cast<float*>(
            FUN_00497ca0(&local_118, reinterpret_cast<void*>(static_cast<uintptr_t>(param_4) + 1)));
        local_104[1] = *pfVar8 * 0.5f;
        local_104[2] = pfVar8[1] * 0.5f;
        local_104[3] = pfVar8[2] * 0.5f;
        *param_7 = local_104[1];
        param_7[1] = local_104[2];
        param_7[2] = local_104[3];
        goto lab_e5fb;

    default:
        iVar4 = static_cast<int32_t>(uVar11) * 3;
        negI = static_cast<float>(-iVar10);
        if (local_104[iVar4 + 1] <= 0.0f) {
            if (0.0f <= local_104[iVar4 + 1]) {
                fVar1 = 0.0f;
            }
            else {
                fVar1 = static_cast<float>(local_12c) * param_4[0xd];
            }
        }
        else {
            fVar1 = negI * param_4[0xd];
        }
        if (local_104[iVar4 + 2] <= 0.0f) {
            if (0.0f <= local_104[iVar4 + 2]) {
                fVar2 = 0.0f;
            }
            else {
                fVar2 = static_cast<float>(local_12c) * param_4[0xe];
            }
        }
        else {
            fVar2 = negI * param_4[0xe];
        }
        if (local_104[iVar4 + 3] <= 0.0f) {
            if (0.0f <= local_104[iVar4 + 3]) {
                fVar3 = 0.0f;
            }
            else {
                fVar3 = static_cast<float>(local_12c) * param_4[0xf];
            }
        }
        else {
            fVar3 = negI * param_4[0xf];
        }
        *param_7 = fVar1 * param_4[4] + *param_5 * *param_6 + fVar2 * param_4[7] +
                   fVar3 * param_4[10] + param_4[1];
        param_7[1] = fVar1 * param_4[5] + fVar2 * param_4[8] + fVar3 * param_4[0xb] +
                     *param_6 * param_5[1] + param_4[2];
        param_7[2] = fVar1 * param_4[6] + fVar2 * param_4[9] + fVar3 * param_4[0xc] +
                     *param_6 * param_5[2] + param_4[3];
        pfVar8 = param_4;
        pfVar13 = param_5;
        pfVar14 = param_2;
        pfVar15 = param_3;
        goto lab_e5f3;

    case 4:
    case 5:
    case 6:
        negI = static_cast<float>(-iVar10);
        if (local_104[uVar11] <= 0.0f) {
            if (0.0f <= local_104[uVar11]) {
                fVar1 = 0.0f;
            }
            else {
                fVar1 = negI * param_2[0xd];
            }
        }
        else {
            fVar1 = static_cast<float>(local_12c) * param_2[0xd];
        }
        if (local_104[uVar11 + 3] <= 0.0f) {
            if (0.0f <= local_104[uVar11 + 3]) {
                fVar2 = 0.0f;
            }
            else {
                fVar2 = negI * param_2[0xe];
            }
        }
        else {
            fVar2 = static_cast<float>(local_12c) * param_2[0xe];
        }
        if (local_104[uVar11 + 6] <= 0.0f) {
            if (0.0f <= local_104[uVar11 + 6]) {
                fVar3 = 0.0f;
            }
            else {
                fVar3 = negI * param_2[0xf];
            }
        }
        else {
            fVar3 = static_cast<float>(local_12c) * param_2[0xf];
        }
        *param_7 = fVar1 * *pfVar9 + fVar2 * param_2[7] + fVar3 * param_2[10] +
                   *param_6 * *param_3 + param_2[1];
        param_7[1] = fVar1 * param_2[5] + fVar2 * param_2[8] + fVar3 * param_2[0xb] +
                     *param_6 * param_3[1] + param_2[2];
        param_7[2] = param_3[2] * *param_6 + fVar1 * param_2[6] + fVar2 * param_2[9] +
                     fVar3 * param_2[0xc] + param_2[3];
        goto lab_e5f3;

    case 7:
        if (local_104[10] <= 0.0f) {
            if (0.0f <= local_104[10]) {
                local_120 = 0.0f;
            }
            else {
                local_120 = static_cast<float>(local_12c) * param_2[0xe];
            }
        }
        else {
            local_120 = static_cast<float>(-iVar10) * param_2[0xe];
        }
        if (local_104[7] <= 0.0f) {
            if (0.0f <= local_104[7]) {
                local_11c = 0.0f;
            }
            else {
                local_11c = static_cast<float>(-iVar10) * param_2[0xf];
            }
        }
        else {
            local_11c = static_cast<float>(local_12c) * param_2[0xf];
        }
        if (local_104[6] <= 0.0f) {
            if (0.0f <= local_104[6]) {
                local_108 = 0.0f;
            }
            else {
                local_108 = static_cast<float>(local_12c) * param_4[0xe];
            }
        }
        else {
            local_108 = static_cast<float>(-iVar10) * param_4[0xe];
        }
        if (local_104[5] <= 0.0f) {
            if (0.0f <= local_104[5]) {
                local_104[0] = 0.0f;
            }
            else {
                local_104[0] = static_cast<float>(-iVar10) * param_4[0xf];
            }
        }
        else {
            local_104[0] = static_cast<float>(local_12c) * param_4[0xf];
        }
        denom = 1.0f - local_104[4] * local_104[4];
        if (std::fabs(denom) <= 1e-06f) {
            fVar2 = 0.0f;
        }
        else {
            pfVar6 = reinterpret_cast<float*>(FUN_00431450(s_3c, *param_6, local_104 + 1));
            local_118 = local_118 + *pfVar6;
            local_114 = local_114 + pfVar6[1];
            local_110 = local_110 + pfVar6[2];
            fVar2 = (local_108 * local_104[5] + local_104[0] * local_104[6] +
                     local_114 * param_2[5] + local_110 * param_2[6] + local_118 * *pfVar9 +
                     ((local_120 * local_104[7] + local_11c * local_104[10]) -
                      (local_118 * param_4[4] + local_114 * param_4[5] +
                       local_110 * param_4[6])) *
                         local_104[4]) /
                    denom;
            local_104[1] = local_118;
            local_104[2] = local_114;
            local_104[3] = local_110;
        }
        break;

    case 8:
        if (local_104[0xb] <= 0.0f) {
            if (0.0f <= local_104[0xb]) {
                local_120 = 0.0f;
            }
            else {
                local_120 = static_cast<float>(local_12c) * param_2[0xe];
            }
        }
        else {
            local_120 = static_cast<float>(-iVar10) * param_2[0xe];
        }
        if (local_104[8] <= 0.0f) {
            if (0.0f <= local_104[8]) {
                local_11c = 0.0f;
            }
            else {
                local_11c = static_cast<float>(-iVar10) * param_2[0xf];
            }
        }
        else {
            local_11c = static_cast<float>(local_12c) * param_2[0xf];
        }
        if (local_104[6] <= 0.0f) {
            if (0.0f <= local_104[6]) {
                local_10c = 0.0f;
            }
            else {
                local_10c = static_cast<float>(-iVar10) * param_4[0xd];
            }
        }
        else {
            local_10c = static_cast<float>(local_12c) * param_4[0xd];
        }
        if (local_104[4] <= 0.0f) {
            if (0.0f <= local_104[4]) {
                local_104[0] = 0.0f;
            }
            else {
                local_104[0] = static_cast<float>(local_12c) * param_4[0xf];
            }
        }
        else {
            local_104[0] = static_cast<float>(-iVar10) * param_4[0xf];
        }
        denom = 1.0f - local_104[5] * local_104[5];
        if (std::fabs(denom) <= 1e-06f) {
            fVar2 = 0.0f;
        }
        else {
            pfVar6 = reinterpret_cast<float*>(FUN_00431450(s_30, *param_6, local_104 + 1));
            local_118 = local_118 + *pfVar6;
            local_114 = local_114 + pfVar6[1];
            local_110 = local_110 + pfVar6[2];
            fVar2 = (local_10c * local_104[4] + local_104[0] * local_104[6] +
                     local_114 * param_2[5] + local_110 * param_2[6] + local_118 * *pfVar9 +
                     ((local_120 * local_104[8] + local_11c * local_104[0xb]) -
                      (local_118 * param_4[7] + local_110 * param_4[9] +
                       local_114 * param_4[8])) *
                         local_104[5]) /
                    denom;
            local_104[1] = local_118;
            local_104[2] = local_114;
            local_104[3] = local_110;
        }
        break;

    case 9:
        if (local_104[0xc] <= 0.0f) {
            if (0.0f <= local_104[0xc]) {
                local_120 = 0.0f;
            }
            else {
                local_120 = static_cast<float>(local_12c) * param_2[0xe];
            }
        }
        else {
            local_120 = static_cast<float>(-iVar10) * param_2[0xe];
        }
        if (local_104[9] <= 0.0f) {
            if (0.0f <= local_104[9]) {
                local_11c = 0.0f;
            }
            else {
                local_11c = static_cast<float>(-iVar10) * param_2[0xf];
            }
        }
        else {
            local_11c = static_cast<float>(local_12c) * param_2[0xf];
        }
        if (local_104[5] <= 0.0f) {
            if (0.0f <= local_104[5]) {
                local_10c = 0.0f;
            }
            else {
                local_10c = static_cast<float>(local_12c) * param_4[0xd];
            }
        }
        else {
            local_10c = static_cast<float>(-iVar10) * param_4[0xd];
        }
        if (local_104[4] <= 0.0f) {
            if (0.0f <= local_104[4]) {
                local_108 = 0.0f;
            }
            else {
                local_108 = static_cast<float>(-iVar10) * param_4[0xe];
            }
        }
        else {
            local_108 = static_cast<float>(local_12c) * param_4[0xe];
        }
        denom = 1.0f - local_104[6] * local_104[6];
        if (std::fabs(denom) <= 1e-06f) {
            fVar2 = 0.0f;
        }
        else {
            pfVar6 = reinterpret_cast<float*>(FUN_00431450(s_18, *param_6, local_104 + 1));
            local_118 = local_118 + *pfVar6;
            local_114 = local_114 + pfVar6[1];
            local_110 = local_110 + pfVar6[2];
            fVar2 = (local_10c * local_104[4] + local_108 * local_104[5] +
                     local_114 * param_2[5] + local_110 * param_2[6] + local_118 * *pfVar9 +
                     ((local_120 * local_104[9] + local_11c * local_104[0xc]) -
                      (local_118 * param_4[10] + local_110 * param_4[0xc] +
                       local_114 * param_4[0xb])) *
                         local_104[6]) /
                    denom;
            local_104[1] = local_118;
            local_104[2] = local_114;
            local_104[3] = local_110;
        }
        break;

    case 10:
        if (local_104[10] <= 0.0f) {
            if (0.0f <= local_104[10]) {
                local_124 = 0.0f;
            }
            else {
                local_124 = static_cast<float>(-iVar10) * param_2[0xd];
            }
        }
        else {
            local_124 = static_cast<float>(local_12c) * param_2[0xd];
        }
        if (local_104[4] <= 0.0f) {
            if (0.0f <= local_104[4]) {
                local_11c = 0.0f;
            }
            else {
                local_11c = static_cast<float>(local_12c) * param_2[0xf];
            }
        }
        else {
            local_11c = static_cast<float>(-iVar10) * param_2[0xf];
        }
        if (local_104[9] <= 0.0f) {
            if (0.0f <= local_104[9]) {
                local_108 = 0.0f;
            }
            else {
                local_108 = static_cast<float>(local_12c) * param_4[0xe];
            }
        }
        else {
            local_108 = static_cast<float>(-iVar10) * param_4[0xe];
        }
        if (local_104[8] <= 0.0f) {
            if (0.0f <= local_104[8]) {
                local_104[0] = 0.0f;
            }
            else {
                local_104[0] = static_cast<float>(-iVar10) * param_4[0xf];
            }
        }
        else {
            local_104[0] = static_cast<float>(local_12c) * param_4[0xf];
        }
        denom = 1.0f - local_104[7] * local_104[7];
        if (std::fabs(denom) <= 1e-06f) {
            fVar2 = 0.0f;
        }
        else {
            pfVar6 = reinterpret_cast<float*>(FUN_00431450(s_48, *param_6, local_104 + 1));
            local_118 = local_118 + *pfVar6;
            local_114 = local_114 + pfVar6[1];
            local_110 = local_110 + pfVar6[2];
            fVar2 = (local_108 * local_104[8] + local_104[0] * local_104[9] +
                     local_118 * param_2[7] + local_110 * param_2[9] + local_114 * param_2[8] +
                     ((local_124 * local_104[4] + local_11c * local_104[10]) -
                      (local_118 * param_4[4] + local_114 * param_4[5] +
                       local_110 * param_4[6])) *
                         local_104[7]) /
                    denom;
            local_104[1] = local_118;
            local_104[2] = local_114;
            local_104[3] = local_110;
        }
        goto lab_dedf;

    case 0xb:
        if (local_104[0xb] <= 0.0f) {
            if (0.0f <= local_104[0xb]) {
                local_124 = 0.0f;
            }
            else {
                local_124 = static_cast<float>(-iVar10) * param_2[0xd];
            }
        }
        else {
            local_124 = static_cast<float>(local_12c) * param_2[0xd];
        }
        if (local_104[5] <= 0.0f) {
            if (0.0f <= local_104[5]) {
                local_11c = 0.0f;
            }
            else {
                local_11c = static_cast<float>(local_12c) * param_2[0xf];
            }
        }
        else {
            local_11c = static_cast<float>(-iVar10) * param_2[0xf];
        }
        if (local_104[9] <= 0.0f) {
            if (0.0f <= local_104[9]) {
                local_10c = 0.0f;
            }
            else {
                local_10c = static_cast<float>(-iVar10) * param_4[0xd];
            }
        }
        else {
            local_10c = static_cast<float>(local_12c) * param_4[0xd];
        }
        if (local_104[7] <= 0.0f) {
            if (0.0f <= local_104[7]) {
                local_104[0] = 0.0f;
            }
            else {
                local_104[0] = static_cast<float>(local_12c) * param_4[0xf];
            }
        }
        else {
            local_104[0] = static_cast<float>(-iVar10) * param_4[0xf];
        }
        denom = 1.0f - local_104[8] * local_104[8];
        if (std::fabs(denom) <= 1e-06f) {
            fVar2 = 0.0f;
        }
        else {
            pfVar6 = reinterpret_cast<float*>(FUN_00431450(s_24, *param_6, local_104 + 1));
            local_118 = local_118 + *pfVar6;
            local_114 = local_114 + pfVar6[1];
            local_110 = local_110 + pfVar6[2];
            fVar2 = (local_10c * local_104[7] + local_104[0] * local_104[9] +
                     local_118 * param_2[7] + local_110 * param_2[9] + local_114 * param_2[8] +
                     ((local_124 * local_104[5] + local_11c * local_104[0xb]) -
                      (local_118 * param_4[7] + local_110 * param_4[9] +
                       local_114 * param_4[8])) *
                         local_104[8]) /
                    denom;
            local_104[1] = local_118;
            local_104[2] = local_114;
            local_104[3] = local_110;
        }
        goto lab_dedf;

    case 0xc:
        if (local_104[0xc] <= 0.0f) {
            if (0.0f <= local_104[0xc]) {
                local_124 = 0.0f;
            }
            else {
                local_124 = static_cast<float>(-iVar10) * param_2[0xd];
            }
        }
        else {
            local_124 = static_cast<float>(local_12c) * param_2[0xd];
        }
        if (local_104[6] <= 0.0f) {
            if (0.0f <= local_104[6]) {
                local_11c = 0.0f;
            }
            else {
                local_11c = static_cast<float>(local_12c) * param_2[0xf];
            }
        }
        else {
            local_11c = static_cast<float>(-iVar10) * param_2[0xf];
        }
        if (local_104[8] <= 0.0f) {
            if (0.0f <= local_104[8]) {
                local_10c = 0.0f;
            }
            else {
                local_10c = static_cast<float>(local_12c) * param_4[0xd];
            }
        }
        else {
            local_10c = static_cast<float>(-iVar10) * param_4[0xd];
        }
        if (local_104[7] <= 0.0f) {
            if (0.0f <= local_104[7]) {
                local_108 = 0.0f;
            }
            else {
                local_108 = static_cast<float>(-iVar10) * param_4[0xe];
            }
        }
        else {
            local_108 = static_cast<float>(local_12c) * param_4[0xe];
        }
        denom = 1.0f - local_104[9] * local_104[9];
        if (std::fabs(denom) <= 1e-06f) {
            fVar2 = 0.0f;
        }
        else {
            pfVar6 = reinterpret_cast<float*>(FUN_00431450(s_c, *param_6, local_104 + 1));
            local_118 = local_118 + *pfVar6;
            local_114 = local_114 + pfVar6[1];
            local_110 = local_110 + pfVar6[2];
            fVar2 = (local_10c * local_104[7] + local_108 * local_104[8] +
                     local_118 * param_2[7] + local_110 * param_2[9] + local_114 * param_2[8] +
                     ((local_124 * local_104[6] + local_11c * local_104[0xc]) -
                      (local_118 * param_4[10] + local_110 * param_4[0xc] +
                       local_114 * param_4[0xb])) *
                         local_104[9]) /
                    denom;
            local_104[1] = local_118;
            local_104[2] = local_114;
            local_104[3] = local_110;
        }
        goto lab_dedf;

    case 0xd:
        if (local_104[7] <= 0.0f) {
            if (0.0f <= local_104[7]) {
                local_124 = 0.0f;
            }
            else {
                local_124 = static_cast<float>(local_12c) * param_2[0xd];
            }
        }
        else {
            local_124 = static_cast<float>(-iVar10) * param_2[0xd];
        }
        if (local_104[4] <= 0.0f) {
            if (0.0f <= local_104[4]) {
                local_120 = 0.0f;
            }
            else {
                local_120 = static_cast<float>(-iVar10) * param_2[0xe];
            }
        }
        else {
            local_120 = static_cast<float>(local_12c) * param_2[0xe];
        }
        if (local_104[0xc] <= 0.0f) {
            if (0.0f <= local_104[0xc]) {
                local_108 = 0.0f;
            }
            else {
                local_108 = static_cast<float>(local_12c) * param_4[0xe];
            }
        }
        else {
            local_108 = static_cast<float>(-iVar10) * param_4[0xe];
        }
        if (local_104[0xb] <= 0.0f) {
            if (0.0f <= local_104[0xb]) {
                local_104[0] = 0.0f;
            }
            else {
                local_104[0] = static_cast<float>(-iVar10) * param_4[0xf];
            }
        }
        else {
            local_104[0] = static_cast<float>(local_12c) * param_4[0xf];
        }
        denom = 1.0f - local_104[10] * local_104[10];
        if (std::fabs(denom) <= 1e-06f) {
            fVar1 = 0.0f;
        }
        else {
            pfVar6 = reinterpret_cast<float*>(FUN_00431450(s_60, *param_6, local_104 + 1));
            local_118 = local_118 + *pfVar6;
            local_114 = local_114 + pfVar6[1];
            local_110 = local_110 + pfVar6[2];
            fVar1 = (local_108 * local_104[0xb] + local_104[0] * local_104[0xc] +
                     local_118 * param_2[10] + local_110 * param_2[0xc] +
                     local_114 * param_2[0xb] +
                     ((local_124 * local_104[4] + local_120 * local_104[7]) -
                      (local_118 * param_4[4] + local_114 * param_4[5] +
                       local_110 * param_4[6])) *
                         local_104[10]) /
                    denom;
            local_104[1] = local_118;
            local_104[2] = local_114;
            local_104[3] = local_110;
        }
        goto lab_e568;

    case 0xe:
        if (local_104[8] <= 0.0f) {
            if (0.0f <= local_104[8]) {
                local_124 = 0.0f;
            }
            else {
                local_124 = static_cast<float>(local_12c) * param_2[0xd];
            }
        }
        else {
            local_124 = static_cast<float>(-iVar10) * param_2[0xd];
        }
        if (local_104[5] <= 0.0f) {
            if (0.0f <= local_104[5]) {
                local_120 = 0.0f;
            }
            else {
                local_120 = static_cast<float>(-iVar10) * param_2[0xe];
            }
        }
        else {
            local_120 = static_cast<float>(local_12c) * param_2[0xe];
        }
        if (local_104[0xc] <= 0.0f) {
            if (0.0f <= local_104[0xc]) {
                local_10c = 0.0f;
            }
            else {
                local_10c = static_cast<float>(-iVar10) * param_4[0xd];
            }
        }
        else {
            local_10c = static_cast<float>(local_12c) * param_4[0xd];
        }
        if (local_104[10] <= 0.0f) {
            if (0.0f <= local_104[10]) {
                local_104[0] = 0.0f;
            }
            else {
                local_104[0] = static_cast<float>(local_12c) * param_4[0xf];
            }
        }
        else {
            local_104[0] = static_cast<float>(-iVar10) * param_4[0xf];
        }
        denom = 1.0f - local_104[0xb] * local_104[0xb];
        if (std::fabs(denom) <= 1e-06f) {
            fVar1 = 0.0f;
        }
        else {
            pfVar6 = reinterpret_cast<float*>(FUN_00431450(s_54, *param_6, local_104 + 1));
            local_118 = local_118 + *pfVar6;
            local_114 = local_114 + pfVar6[1];
            local_110 = local_110 + pfVar6[2];
            fVar1 = (local_10c * local_104[10] + local_104[0] * local_104[0xc] +
                     local_118 * param_2[10] + local_110 * param_2[0xc] +
                     local_114 * param_2[0xb] +
                     ((local_124 * local_104[5] + local_120 * local_104[8]) -
                      (local_118 * param_4[7] + local_110 * param_4[9] +
                       local_114 * param_4[8])) *
                         local_104[0xb]) /
                    denom;
            local_104[1] = local_118;
            local_104[2] = local_114;
            local_104[3] = local_110;
        }
        goto lab_e568;

    case 0xf:
        if (local_104[9] <= 0.0f) {
            if (0.0f <= local_104[9]) {
                local_124 = 0.0f;
            }
            else {
                local_124 = static_cast<float>(local_12c) * param_2[0xd];
            }
        }
        else {
            local_124 = static_cast<float>(-iVar10) * param_2[0xd];
        }
        if (local_104[6] <= 0.0f) {
            if (0.0f <= local_104[6]) {
                local_120 = 0.0f;
            }
            else {
                local_120 = static_cast<float>(-iVar10) * param_2[0xe];
            }
        }
        else {
            local_120 = static_cast<float>(local_12c) * param_2[0xe];
        }
        if (local_104[0xb] <= 0.0f) {
            if (0.0f <= local_104[0xb]) {
                local_10c = 0.0f;
            }
            else {
                local_10c = static_cast<float>(local_12c) * param_4[0xd];
            }
        }
        else {
            local_10c = static_cast<float>(-iVar10) * param_4[0xd];
        }
        if (local_104[10] <= 0.0f) {
            if (0.0f <= local_104[10]) {
                local_108 = 0.0f;
            }
            else {
                local_108 = static_cast<float>(-iVar10) * param_4[0xe];
            }
        }
        else {
            local_108 = static_cast<float>(local_12c) * param_4[0xe];
        }
        denom = 1.0f - local_104[0xc] * local_104[0xc];
        if (std::fabs(denom) <= 1e-06f) {
            fVar1 = 0.0f;
        }
        else {
            pfVar6 = reinterpret_cast<float*>(FUN_00431450(s_6c, *param_6, local_104 + 1));
            local_118 = local_118 + *pfVar6;
            local_114 = local_114 + pfVar6[1];
            local_110 = local_110 + pfVar6[2];
            fVar1 = (local_10c * local_104[10] + local_108 * local_104[0xb] +
                     local_118 * param_2[10] + local_110 * param_2[0xc] +
                     local_114 * param_2[0xb] +
                     ((local_124 * local_104[6] + local_120 * local_104[9]) -
                      (local_118 * param_4[10] + local_110 * param_4[0xc] +
                       local_114 * param_4[0xb])) *
                         local_104[0xc]) /
                    denom;
            local_104[1] = local_118;
            local_104[2] = local_114;
            local_104[3] = local_110;
        }
        goto lab_e568;
    }

    // Cases 7-9 rejoin here with their winning axis still selected.
    *param_7 = fVar2 * *pfVar9 + local_120 * param_2[7] + local_11c * param_2[10] +
               *param_6 * *param_3 + param_2[1];
    param_7[1] = fVar2 * param_2[5] + local_120 * param_2[8] + local_11c * param_2[0xb] +
                 *param_6 * param_3[1] + param_2[2];
    fVar1 = local_120 * param_2[9] + local_11c * param_2[0xc];
    goto lab_e5cc;

lab_dedf:
    *param_7 = local_124 * *pfVar9 + fVar2 * param_2[7] + local_11c * param_2[10] +
               *param_6 * *param_3 + param_2[1];
    param_7[1] = local_124 * param_2[5] + fVar2 * param_2[8] + local_11c * param_2[0xb] +
                 *param_6 * param_3[1] + param_2[2];
    fVar1 = local_11c * param_2[0xc];
    goto lab_e5c3;

lab_e568:
    *param_7 = local_124 * *pfVar9 + local_120 * param_2[7] + fVar1 * param_2[10] +
               *param_6 * *param_3 + param_2[1];
    param_7[1] = local_124 * param_2[5] + local_120 * param_2[8] + fVar1 * param_2[0xb] +
                 *param_6 * param_3[1] + param_2[2];
    fVar1 = fVar1 * param_2[0xc];
    fVar2 = local_120;

lab_e5c3:
    fVar1 = fVar2 * param_2[9] + fVar1;
    fVar2 = local_124;

lab_e5cc:
    param_7[2] = param_3[2] * *param_6 + fVar2 * param_2[6] + fVar1 + param_2[3];

lab_e5f3:
    FUN_0058ad60(param_1, pfVar8, pfVar13, pfVar14, pfVar15, param_6, param_7);

lab_e5fb:
    if (static_cast<char>(param_8) != '\0') {
        puVar16 = reinterpret_cast<uint32_t*>(&DAT_00727430);
        FUN_004760c0(s_6c, param_2 + 1);
        cVar5 = FUN_004284c0(puVar16);
        if (cVar5 != '\0') {
            *param_9 = DAT_007177c4;
            param_9[1] = DAT_007177c8;
            param_9[2] = DAT_007177cc;
            fVar1 = param_9[1];
            fVar2 = param_9[2];
            *param_10 = -*param_9;
            param_10[1] = -fVar1;
            param_10[2] = -fVar2;
            return 1;
        }
        pv = FUN_00431450(s_6c, *param_6, param_3);
        pv = FUN_00497ca0(s_54, pv);
        pfVar8 = reinterpret_cast<float*>(FUN_004760c0(s_60, pv));
        local_114 = pfVar8[1];
        local_118 = *pfVar8;
        local_110 = pfVar8[2];
        pfPlane = param_2 + 10;
        local_104[0xd] = local_118 * *pfVar9 + local_110 * param_2[6] + local_114 * param_2[5];
        local_104[0xe] = local_118 * param_2[7] + local_110 * param_2[9] +
                         local_114 * param_2[8];
        fVar1 = param_2[0xb];
        fVar2 = param_2[0xc];
        fVar3 = *pfPlane;
        *param_9 = DAT_00727430;
        param_9[1] = DAT_00727434;
        local_104[0xf] = local_118 * fVar3 + local_110 * fVar2 + local_114 * fVar1;
        param_9[2] = DAT_00727438;
        if (param_2[0xd] * 0.99f - std::fabs(local_104[0xd]) < 0.0f) {
            pfVar9 = reinterpret_cast<float*>(FUN_00431450(s_6c, local_104[0xd], pfVar9));
            local_10c = *pfVar9;
            local_108 = pfVar9[1];
            local_104[0] = pfVar9[2];
            FUN_00491640();
            FUN_00431420(&local_10c);
        }
        if (param_2[0xe] * 0.99f - std::fabs(local_104[0xe]) < 0.0f) {
            pfVar9 = reinterpret_cast<float*>(FUN_00431450(s_6c, local_104[0xe], param_2 + 7));
            local_10c = *pfVar9;
            local_108 = pfVar9[1];
            local_104[0] = pfVar9[2];
            FUN_00491640();
            FUN_00431420(&local_10c);
        }
        if (param_2[0xf] * 0.99f - std::fabs(local_104[0xf]) < 0.0f) {
            pfVar9 = reinterpret_cast<float*>(FUN_00431450(s_6c, local_104[0xf], pfPlane));
            local_10c = *pfVar9;
            local_108 = pfVar9[1];
            local_104[0] = pfVar9[2];
            FUN_00491640();
            FUN_00431420(&local_10c);
        }
        cVar5 = FUN_004284c0(&DAT_00727430);
        if (cVar5 != '\0') {
            *param_9 = local_118;
            param_9[1] = local_114;
            param_9[2] = local_110;
        }
        FUN_00491640();
        pv = FUN_00431450(s_6c, *param_6, param_5);
        pv = FUN_00497ca0(s_54, pv);
        pfVar9 = reinterpret_cast<float*>(FUN_004760c0(s_60, pv));
        local_118 = *pfVar9;
        local_114 = pfVar9[1];
        local_110 = pfVar9[2];
        local_104[0xd] = local_118 * param_4[4] + local_110 * param_4[6] +
                         local_114 * param_4[5];
        local_104[0xe] = local_118 * param_4[7] + local_110 * param_4[9] +
                         local_114 * param_4[8];
        fVar1 = param_4[0xb];
        fVar2 = param_4[0xc];
        fVar3 = param_4[10];
        *param_10 = DAT_00727430;
        param_10[1] = DAT_00727434;
        local_104[0xf] = local_118 * fVar3 + local_110 * fVar2 + local_114 * fVar1;
        param_10[2] = DAT_00727438;
        if (param_4[0xd] * 0.99f - std::fabs(local_104[0xd]) < 0.0f) {
            pfVar9 = reinterpret_cast<float*>(FUN_00431450(s_6c, local_104[0xd], param_4 + 4));
            local_10c = *pfVar9;
            local_108 = pfVar9[1];
            local_104[0] = pfVar9[2];
            FUN_00491640();
            FUN_00431420(&local_10c);
        }
        if (param_4[0xe] * 0.99f - std::fabs(local_104[0xe]) < 0.0f) {
            pfVar9 = reinterpret_cast<float*>(FUN_00431450(s_6c, local_104[0xe], param_4 + 7));
            local_10c = *pfVar9;
            local_108 = pfVar9[1];
            local_104[0] = pfVar9[2];
            FUN_00491640();
            FUN_00431420(&local_10c);
        }
        if (param_4[0xf] * 0.99f - std::fabs(local_104[0xf]) < 0.0f) {
            pfVar9 = reinterpret_cast<float*>(FUN_00431450(s_6c, local_104[0xf], param_4 + 10));
            local_10c = *pfVar9;
            local_108 = pfVar9[1];
            local_104[0] = pfVar9[2];
            FUN_00491640();
            FUN_00431420(&local_10c);
        }
        cVar5 = FUN_004284c0(&DAT_00727430);
        if (cVar5 != '\0') {
            *param_10 = local_118;
            param_10[1] = local_114;
            param_10[2] = local_110;
        }
        FUN_00491640();
    }
    return 1;
}

// ---------------------------------------------------------------------------
// 0x58edf0
// ---------------------------------------------------------------------------
// 0x58edf0 — observed shape
// Constructs the object: installs the vtable, zeroes the runtime fields and
// seeds the three axis vectors.
void FUN_0058edf0(void* self, uint32_t param_1)
{
    uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
    float* pf = reinterpret_cast<float*>(self);
    uint32_t uVar1;

    FUN_00549cd0(param_1);
    in_ECX[0x11] = 0;
    in_ECX[0x12] = 0;
    *reinterpret_cast<uint8_t*>(reinterpret_cast<uintptr_t>(self) + 0x4c) = 0;
    *reinterpret_cast<uint8_t*>(reinterpret_cast<uintptr_t>(self) + 0x4d) = 0;
    in_ECX[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c4ff0));
    pf[4] = DAT_00727430;
    pf[5] = DAT_00727434;
    pf[6] = DAT_00727438;
    pf[7] = DAT_00727430;
    pf[8] = DAT_00727434;
    uVar1 = float_bits(DAT_00727438);
    in_ECX[0xc] = 0;
    in_ECX[0xd] = 0;
    in_ECX[0xe] = 0;
    *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(self) + 0x50) = 0;
    in_ECX[0xf] = 0;
    in_ECX[0x10] = 0;
    *reinterpret_cast<uint8_t*>(reinterpret_cast<uintptr_t>(self) + 0x52) = 0;
    in_ECX[10] = 2;
    in_ECX[0xb] = 3;
    in_ECX[9] = uVar1;
}

// ---------------------------------------------------------------------------
// 0x58ee90
// ---------------------------------------------------------------------------
// 0x58ee90 — observed shape
// Default constructor body: same field seeding as 0x58edf0 without an argument.
void FUN_0058ee90(void* self)
{
    uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
    float* pf = reinterpret_cast<float*>(self);

    FUN_00549cd0(0);
    in_ECX[0x11] = 0;
    in_ECX[0x12] = 0;
    *reinterpret_cast<uint8_t*>(reinterpret_cast<uintptr_t>(self) + 0x4c) = 0;
    *reinterpret_cast<uint8_t*>(reinterpret_cast<uintptr_t>(self) + 0x4d) = 0;
    in_ECX[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c4ff0));
    pf[4] = DAT_00727430;
    pf[5] = DAT_00727434;
    pf[6] = DAT_00727438;
    pf[7] = DAT_00727430;
    pf[8] = DAT_00727434;
    pf[9] = DAT_00727438;
    in_ECX[0xc] = 0;
    in_ECX[0xd] = 0;
    in_ECX[0xe] = 0;
    *reinterpret_cast<uint16_t*>(reinterpret_cast<uintptr_t>(self) + 0x50) = 0;
    in_ECX[0xf] = 0;
    in_ECX[0x10] = 0;
    *reinterpret_cast<uint8_t*>(reinterpret_cast<uintptr_t>(self) + 0x52) = 0;
    in_ECX[10] = 2;
    in_ECX[0xb] = 3;
}

// ---------------------------------------------------------------------------
// 0x58ef10
// ---------------------------------------------------------------------------
// 0x58ef10 — observed shape
// Non-deleting destructor: releases the two owned buffers, the three referenced
// objects, then tears down the base.
void FUN_0058ef10(void* self)
{
    uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);

    in_ECX[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c4ff0));
    operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(in_ECX[0x11])));
    operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(in_ECX[0x12])));
    if (in_ECX[0xc] != 0) {
        vcall<void>(reinterpret_cast<void*>(static_cast<uintptr_t>(in_ECX[0xc])), 8, 1);
    }
    if (in_ECX[0xd] != 0) {
        vcall<void>(reinterpret_cast<void*>(static_cast<uintptr_t>(in_ECX[0xd])), 8, 1);
    }
    if (in_ECX[0xe] != 0) {
        vcall<void>(reinterpret_cast<void*>(static_cast<uintptr_t>(in_ECX[0xe])), 0, 1);
    }
    in_ECX[0xe] = 0;
    FUN_00549b80();
}

// ---------------------------------------------------------------------------
// 0x58ef70
// ---------------------------------------------------------------------------
// 0x58ef70 — observed shape
// Handshake between two objects: publishes the shared index into both embedded
// descriptors, refreshes the two receivers' caches and forwards to the
// receiver's dispatcher.
void FUN_0058ef70(void* self, uint32_t param_1, int32_t param_2, uint32_t param_3, int32_t param_4,
                  uint32_t param_5, uint32_t param_6)
{
    uintptr_t base = reinterpret_cast<uintptr_t>(self);
    int32_t iVar1;
    uintptr_t other = static_cast<uintptr_t>(param_2);

    *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(
        static_cast<int32_t>(*reinterpret_cast<uint32_t*>(base + 0x38))) + 4) = param_1;
    iVar1 = static_cast<int32_t>(*reinterpret_cast<uint32_t*>(base + 0x38));
    *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(iVar1) + 0x10) =
        *reinterpret_cast<uint32_t*>(base + 0x1c);
    *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(iVar1) + 0x14) =
        *reinterpret_cast<uint32_t*>(base + 0x20);
    *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(iVar1) + 0x18) =
        *reinterpret_cast<uint32_t*>(base + 0x24);
    FUN_0059a900(static_cast<int32_t>(*reinterpret_cast<uint32_t*>(base + 0xc) + 0x6c));

    *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(
        static_cast<int32_t>(*reinterpret_cast<uint32_t*>(other + 0x38))) + 4) = param_1;
    iVar1 = static_cast<int32_t>(*reinterpret_cast<uint32_t*>(other + 0x38));
    *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(iVar1) + 0x10) =
        *reinterpret_cast<uint32_t*>(other + 0x1c);
    *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(iVar1) + 0x14) =
        *reinterpret_cast<uint32_t*>(other + 0x20);
    *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(iVar1) + 0x18) =
        *reinterpret_cast<uint32_t*>(other + 0x24);
    FUN_0059a900(param_4 + 0x6c);

    vcall<void>(reinterpret_cast<void*>(static_cast<uintptr_t>(
                    static_cast<int32_t>(*reinterpret_cast<uint32_t*>(base + 0x38)))),
                4, *reinterpret_cast<uint32_t*>(other + 0x38), param_3, param_4, param_5,
                param_6);
}

// ---------------------------------------------------------------------------
// 0x58f000
// ---------------------------------------------------------------------------
// 0x58f000 — observed shape
// Rebinds the two cached targets at +0x30/+0x34, cloning the incoming object and
// pushing the cache down through its vtable slot 0x14.
void FUN_0058f000(void* self, int32_t* param_1)
{
    uintptr_t base = reinterpret_cast<uintptr_t>(self);
    int32_t* piVar1;

    if (*reinterpret_cast<int32_t**>(base + 0x30) != nullptr) {
        vcall<void>(*reinterpret_cast<void**>(base + 0x30), 8, 1);
    }
    if (*reinterpret_cast<int32_t**>(base + 0x34) != nullptr) {
        vcall<void>(*reinterpret_cast<void**>(base + 0x34), 8, 1);
    }
    *reinterpret_cast<uint32_t*>(base + 0x30) =
        static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_1));
    if (param_1 == nullptr) {
        *reinterpret_cast<uint32_t*>(base + 0x34) = 0;
    }
    else {
        piVar1 = vcall<int32_t*>(param_1, 0x18);
        *reinterpret_cast<uint32_t*>(base + 0x34) =
            static_cast<uint32_t>(reinterpret_cast<uintptr_t>(piVar1));
        if (*reinterpret_cast<int32_t*>(base + 0xc) != 0) {
            vcall<void>(piVar1, 0x14, *reinterpret_cast<uint32_t*>(base + 0x30),
                        static_cast<uint32_t>(*reinterpret_cast<int32_t*>(base + 0xc) + 0x6c));
            return;
        }
    }
}

// ---------------------------------------------------------------------------
// 0x58f0c0
// ---------------------------------------------------------------------------
// 0x58f0c0 — observed shape
// Deleting destructor wrapper around 0x58ef10.
void FUN_0058f0c0(void* self, uint8_t param_1)
{
    FUN_0058ef10(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// ---------------------------------------------------------------------------
// 0x58f0e0
// ---------------------------------------------------------------------------
// 0x58f0e0 — observed shape
// Walks the node chain at +0x24 until a node carries a live payload at +0xb0 and
// returns that node.
int32_t FUN_0058f0e0(int32_t param_1)
{
    uint32_t* puVar1;
    int32_t iVar2;

    if (param_1 != 0) {
        while (param_1 = static_cast<int32_t>(
                   *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(param_1) + 0x24)),
               param_1 != 0) {
            puVar1 = *reinterpret_cast<uint32_t**>(static_cast<uintptr_t>(param_1) + 0xb0);
            if (puVar1 != nullptr) {
                iVar2 = static_cast<int32_t>(puVar1[1]);
                puVar1[1] = static_cast<uint32_t>(iVar2 + 1);
                puVar1[1] = static_cast<uint32_t>(iVar2);
                if (iVar2 == 0) {
                    vcall<void>(puVar1, 0, 1);
                }
                return param_1;
            }
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x58f130
// ---------------------------------------------------------------------------
// 0x58f130 — observed shape
// Recomputes the cached position at +0x1c from the shared target, or from the
// payload carried by the next live node, and flags the cache valid.
void FUN_0058f130(void* self)
{
    uintptr_t base = reinterpret_cast<uintptr_t>(self);
    float fVar1;
    float fVar2;
    float fVar3;
    float fVar4;
    uint32_t uVar5;
    int32_t iVar6;
    float* pfVar7;
    uint32_t* puVar8;
    float s_c[3];

    if (*reinterpret_cast<int32_t*>(base + 0x30) != 0) {
        vcall<void>(reinterpret_cast<void*>(static_cast<uintptr_t>(
                        *reinterpret_cast<int32_t*>(base + 0x34))),
                    0x14, *reinterpret_cast<uint32_t*>(base + 0x30),
                    static_cast<uint32_t>(*reinterpret_cast<int32_t*>(base + 0xc) + 0x6c));
    }
    if (DAT_00728ac8 == '\0') {
        *reinterpret_cast<uint8_t*>(base + 0x4c) = 1;
        *reinterpret_cast<uint8_t*>(base + 0x4d) = 1;
        return;
    }
    if (*reinterpret_cast<int32_t*>(
            static_cast<uintptr_t>(*reinterpret_cast<int32_t*>(base + 0xc)) + 0x24) == 0) {
        *reinterpret_cast<uint32_t*>(base + 0x1c) = *reinterpret_cast<uint32_t*>(base + 0x10);
        *reinterpret_cast<uint8_t*>(base + 0x4c) = 1;
        *reinterpret_cast<uint8_t*>(base + 0x4d) = 1;
        *reinterpret_cast<uint32_t*>(base + 0x20) = *reinterpret_cast<uint32_t*>(base + 0x14);
        *reinterpret_cast<uint32_t*>(base + 0x24) = *reinterpret_cast<uint32_t*>(base + 0x18);
        return;
    }
    iVar6 = FUN_0058f0e0(*reinterpret_cast<int32_t*>(base + 0xc));
    if ((iVar6 == 0) ||
        (puVar8 = *reinterpret_cast<uint32_t**>(static_cast<uintptr_t>(iVar6) + 0xb0),
         puVar8 == nullptr)) {
        puVar8 = reinterpret_cast<uint32_t*>(FUN_0053ca60(
            s_c, static_cast<int32_t>(base + 0x10)));
        *reinterpret_cast<uint32_t*>(base + 0x1c) = *puVar8;
        *reinterpret_cast<uint32_t*>(base + 0x20) = puVar8[1];
        uVar5 = puVar8[2];
        *reinterpret_cast<uint8_t*>(base + 0x4c) = 1;
        *reinterpret_cast<uint8_t*>(base + 0x4d) = 1;
        *reinterpret_cast<uint32_t*>(base + 0x24) = uVar5;
        return;
    }
    iVar6 = static_cast<int32_t>(puVar8[1]);
    puVar8[1] = static_cast<uint32_t>(iVar6 + 1);
    puVar8[1] = static_cast<uint32_t>(iVar6);
    if (iVar6 == 0) {
        vcall<void>(puVar8, 0, 1);
    }
    pfVar7 = FUN_0053ca60(s_c, static_cast<int32_t>(base + 0x10));
    fVar1 = static_cast<float>(static_cast<int32_t>(puVar8[8]));
    fVar2 = pfVar7[1];
    fVar3 = static_cast<float>(static_cast<int32_t>(puVar8[9]));
    fVar4 = pfVar7[2];
    *reinterpret_cast<float*>(base + 0x1c) = static_cast<float>(static_cast<int32_t>(puVar8[7])) +
                                            *pfVar7;
    *reinterpret_cast<uint8_t*>(base + 0x4c) = 1;
    *reinterpret_cast<uint8_t*>(base + 0x4d) = 1;
    *reinterpret_cast<float*>(base + 0x20) = fVar1 + fVar2;
    *reinterpret_cast<float*>(base + 0x24) = fVar3 + fVar4;
}

