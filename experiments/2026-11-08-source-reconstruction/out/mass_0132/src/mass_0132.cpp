#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---------------------------------------------------------------------------
// External helpers and globals observed in the supplied corpus listings
// (addresses 0x542010 .. 0x542d70).
// ---------------------------------------------------------------------------
extern "C" int sprintf(char* buffer, const char* format, ...);

extern void operator_delete(void* ptr);
extern void operator_delete__(void* ptr);
extern void* thunk_FUN_00533c78(uint32_t size);

extern int  FUN_00541360(uint32_t context, uint16_t element, uint32_t param);
extern uint32_t FUN_00541810(int base, uint32_t param, int lo, int hi);

extern void FUN_005386f0(int object);
extern int  FUN_00539c10(uint32_t* object, uint8_t* tag);
extern void FUN_005403d0();
extern void FUN_00540c50();
extern void FUN_00540c90();
extern void FUN_00545df0(uint32_t count);
extern char FUN_0054a770(int object);
extern void FUN_005606f0(uint32_t index, void* value);
extern uint32_t FUN_00557b10(uint32_t value);
extern uint32_t FUN_00557bb0(const char* name, uint32_t value);
extern uint32_t FUN_00557c30(const char* name, uint32_t value);
extern uint32_t FUN_00557c70(const char* name, uint32_t value);
extern uint32_t FUN_00557d40(const char* name, uint32_t value);
extern uint32_t FUN_00557e10(const char* name);
extern void FUN_006b34a0(int index);

extern uint32_t DAT_007275e0;
extern uint8_t  DAT_007179a4;

extern uint8_t PTR_FUN_006c13f0;
extern uint8_t PTR_FUN_006c13f4;
extern uint8_t PTR_FUN_006c1430;
extern uint8_t PTR_FUN_006c143c;
extern uint8_t PTR_FUN_0070d038;
extern uint8_t PTR_FUN_00710bf8;

// Virtual dispatch shapes actually seen in the listings: entry 0 with a single
// dword argument, entry 1 with one pointer argument, entry 7 with one dword
// argument, and a stream reader at entry 2 taking (destination, byte count).
static void vtbl_call0(void* object, uint32_t argument)
{
    void** vtbl = *reinterpret_cast<void***>(object);
    reinterpret_cast<void (*)(void*, uint32_t)>(vtbl[0])(object, argument);
}

static void vtbl_call1(void* object, void* argument)
{
    void** vtbl = *reinterpret_cast<void***>(object);
    reinterpret_cast<void (*)(void*, void*)>(vtbl[1])(object, argument);
}

static int vtbl_call7(void* object, uint32_t argument)
{
    void** vtbl = *reinterpret_cast<void***>(object);
    return reinterpret_cast<int (*)(void*, uint32_t)>(vtbl[7])(object, argument);
}

static void stream_read(void* reader, void* destination, uint32_t count)
{
    void** vtbl = *reinterpret_cast<void***>(reader);
    reinterpret_cast<void (*)(void*, uint32_t)>(vtbl[2])(destination, count);
}

// ---------------------------------------------------------------------------
// 0x542010 — observed shape
// Recursive dual-pivot style partition over a uint16 array rooted at param_1;
// FUN_00541810 picks the pivot, FUN_00541360 compares elements against it
// (negative result means "keep scanning"), then the two boundary elements are
// swapped and both halves are recursed into.
// ---------------------------------------------------------------------------
// 0x00542010 — observed shape
void FUN_00542010(int param_1, uint32_t param_2, int param_3, int param_4)
{
    if (param_3 < param_4) {
        do {
            int iVar4 = param_3 + -1;
            uint32_t uVar2 = FUN_00541810(param_1, param_2, param_3, param_4);
            int iVar6 = param_4 + 1;
            int iVar5;
            int iVar3;
            for (;;) {
                do {
                    iVar5 = iVar6;
                    iVar6 = iVar5 + -1;
                    iVar3 = FUN_00541360(
                        uVar2,
                        *reinterpret_cast<uint16_t*>(param_1 + -2 + iVar5 * 2),
                        param_2);
                } while (iVar3 < 0);
                do {
                    iVar3 = iVar4 * 2;
                    iVar4 = iVar4 + 1;
                    iVar3 = FUN_00541360(
                        *reinterpret_cast<uint16_t*>(param_1 + 2 + iVar3),
                        uVar2, param_2);
                } while (iVar3 < 0);
                if (iVar6 <= iVar4) break;
                uint16_t uVar1 = *reinterpret_cast<uint16_t*>(param_1 + iVar4 * 2);
                *reinterpret_cast<uint16_t*>(param_1 + iVar4 * 2) =
                    *reinterpret_cast<uint16_t*>(param_1 + iVar6 * 2);
                *reinterpret_cast<uint16_t*>(param_1 + iVar6 * 2) = uVar1;
            }
            if (iVar6 == param_4) {
                param_4 = iVar5 + -2;
            } else {
                FUN_00542010(param_1, param_2, param_3, iVar6);
                param_3 = iVar5;
            }
        } while (param_3 < param_4);
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x5420e0 — observed shape
// Writes a chunk of named properties into the record object `param_1` (its
// writer advances through +0xc, with capacity at +8 and storage at +0x14).
// Each property is produced by a builder helper into `writer`, guarded by a
// capacity check on the record, then handed to FUN_005606f0.
// ---------------------------------------------------------------------------
// 0x005420e0 — observed shape
static void emit_field(int record, uint32_t* writer)
{
    uint8_t* rec = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(record)));
    uint32_t index = *reinterpret_cast<uint32_t*>(rec + 0xc);
    if (*reinterpret_cast<uint32_t*>(rec + 8) <= index) {
        FUN_006b34a0(*reinterpret_cast<int*>(rec + 0x14) + static_cast<int>(index));
    }
    FUN_005606f0(index, writer);
}

void FUN_005420e0(void* self, int record)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    int iVar2 = record;

    FUN_005386f0(record);
    uint32_t writer = FUN_00557b10(DAT_007275e0);
    emit_field(iVar2, &writer);

    writer = FUN_00557c30("m_usVertices", *reinterpret_cast<uint16_t*>(base + 0xc));
    emit_field(iVar2, &writer);

    writer = FUN_00557d40("m_pkVertex", *reinterpret_cast<uint32_t*>(base + 0x20));
    emit_field(iVar2, &writer);

    writer = FUN_00557d40("m_pkNormal", *reinterpret_cast<uint32_t*>(base + 0x24));
    emit_field(iVar2, &writer);

    writer = FUN_00557c70("NormalBinormalTangent",
                          static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(base + 0x30)) & 0xf000);
    emit_field(iVar2, &writer);

    writer = FUN_00557e10("m_kBound");
    emit_field(iVar2, &writer);

    writer = FUN_00557d40("m_pkColor", *reinterpret_cast<uint32_t*>(base + 0x28));
    emit_field(iVar2, &writer);

    writer = FUN_00557c30("Num Texture Sets",
                          static_cast<uint32_t>(*reinterpret_cast<uint8_t*>(base + 0x30)) & 0x3f);
    emit_field(iVar2, &writer);

    writer = FUN_00557d40("m_pkTexture", *reinterpret_cast<uint32_t*>(base + 0x2c));
    emit_field(iVar2, &writer);

    writer = FUN_00557c30("m_usDirtyFlags", *reinterpret_cast<uint16_t*>(base + 0x32));
    emit_field(iVar2, &writer);

    writer = FUN_00557bb0("m_ucKeepFlags", *reinterpret_cast<uint8_t*>(base + 0x34));
    emit_field(iVar2, &writer);

    writer = FUN_00557bb0("m_ucCompressFlags", *reinterpret_cast<uint8_t*>(base + 0x35));
    emit_field(iVar2, &writer);

    return;
}

// ---------------------------------------------------------------------------
// 0x5423b0 — observed shape
// Builds an identity permutation of the receiver's element count (at +0xc)
// into *param_1, sorts it through FUN_00542010 using param_3 as context, then
// inverts the permutation into *param_2.
// ---------------------------------------------------------------------------
// 0x005423b0 — observed shape
void FUN_005423b0(void* self, int* param_1, int* param_2, uint32_t param_3)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    uint16_t uVar1 = *reinterpret_cast<uint16_t*>(base + 0xc);

    uintptr_t first = reinterpret_cast<uintptr_t>(
        thunk_FUN_00533c78(static_cast<uint32_t>(uVar1) * 2));
    *param_1 = static_cast<int>(first);

    uintptr_t second = reinterpret_cast<uintptr_t>(
        thunk_FUN_00533c78(static_cast<uint32_t>(uVar1) * 2));
    *param_2 = static_cast<int>(second);

    uint16_t uVar2 = 0;
    if (uVar1 != 0) {
        uint16_t* cursor = reinterpret_cast<uint16_t*>(first);
        do {
            *cursor = uVar2;
            uVar2 = static_cast<uint16_t>(uVar2 + 1);
            ++cursor;
        } while (uVar2 < uVar1);
    }

    FUN_00542010(static_cast<int>(first), param_3, 0,
                 static_cast<int>(uVar1) - 1);

    uVar2 = 0;
    if (uVar1 != 0) {
        uint16_t* order = reinterpret_cast<uint16_t*>(first);
        do {
            *reinterpret_cast<uint16_t*>(
                second + static_cast<uint32_t>(*order) * 2) = uVar2;
            uVar2 = static_cast<uint16_t>(uVar2 + 1);
            ++order;
        } while (uVar2 < uVar1);
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x542430 — observed shape
// Measures param_1, allocates strlen + 0x14 bytes, then sprintf's the
// addressing-mode string selected by param_2 (default falls through with the
// buffer untouched, as observed).
// ---------------------------------------------------------------------------
// 0x00542430 — observed shape
char* FUN_00542430(char* param_1, uint32_t param_2)
{
    char* pcVar2 = param_1;
    char cVar1;
    do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');

    pcVar2 = static_cast<char*>(thunk_FUN_00533c78(static_cast<uint32_t>(
        reinterpret_cast<intptr_t>(pcVar2) +
        (0x14 - reinterpret_cast<intptr_t>(param_1 + 1)))));

    switch (param_2) {
    case 0:
        sprintf(pcVar2, "%s = CLAMP_S_CLAMP_T", param_1);
        return pcVar2;
    case 1:
        sprintf(pcVar2, "%s = CLAMP_S_WRAP_T", param_1);
        return pcVar2;
    case 2:
        sprintf(pcVar2, "%s = WRAP_S_CLAMP_T", param_1);
        return pcVar2;
    case 3:
        sprintf(pcVar2, "%s = WRAP_S_WRAP_T", param_1);
    }
    return pcVar2;
}

// ---------------------------------------------------------------------------
// 0x5424d0 — observed shape
// Same buffer builder as 0x542430, allocating strlen + 0x1e bytes and
// formatting the filter-mode string selected by param_2.
// ---------------------------------------------------------------------------
// 0x005424d0 — observed shape
char* FUN_005424d0(char* param_1, uint32_t param_2)
{
    char* pcVar2 = param_1;
    char cVar1;
    do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');

    pcVar2 = static_cast<char*>(thunk_FUN_00533c78(static_cast<uint32_t>(
        reinterpret_cast<intptr_t>(pcVar2) +
        (0x1e - reinterpret_cast<intptr_t>(param_1 + 1)))));

    switch (param_2) {
    case 0:
        sprintf(pcVar2, "%s = FILTER_NEAREST", param_1);
        return pcVar2;
    case 1:
        sprintf(pcVar2, "%s = FILTER_BILERP", param_1);
        return pcVar2;
    case 2:
        sprintf(pcVar2, "%s = FILTER_TRILERP", param_1);
        return pcVar2;
    case 3:
        sprintf(pcVar2, "%s = FILTER_NEAREST_MIPNEAREST", param_1);
        return pcVar2;
    case 4:
        sprintf(pcVar2, "%s = FILTER_NEAREST_MIPLERP", param_1);
        return pcVar2;
    case 5:
        sprintf(pcVar2, "%s = FILTER_BILERP_MIPNEAREST", param_1);
    }
    return pcVar2;
}

// ---------------------------------------------------------------------------
// 0x5425b0 — observed shape
// Scalar deleting destructor: restores the base vtable, frees the +4 owner and
// conditionally frees the object itself.
// ---------------------------------------------------------------------------
// 0x005425b0 — observed shape
void FUN_005425b0(void* self, uint8_t param_1)
{
    uint32_t* object = reinterpret_cast<uint32_t*>(self);

    *object = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c13f0));
    operator_delete__(reinterpret_cast<void*>(
        static_cast<uintptr_t>(object[1])));
    if ((param_1 & 1) != 0) {
        operator_delete(object);
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x5425e0 — observed shape
// Destructor body: installs the vtable, releases every element of the two
// vector members at +0xb (count +0xd) and at +0x11 (count at +0xc of the
// vector), restores the +0x28 vtable of the embedded member, frees the +0xb
// array, then runs the base destructor.
// ---------------------------------------------------------------------------
// 0x005425e0 — observed shape
void FUN_005425e0(void* self)
{
    uint32_t* object = reinterpret_cast<uint32_t*>(self);
    uint32_t uVar2 = 0;

    *object = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c13f4));

    if (object[0xd] != 0) {
        do {
            uint32_t* element = *reinterpret_cast<uint32_t**>(
                static_cast<uintptr_t>(object[0xb]) + uVar2 * 4);
            if (element != nullptr) {
                vtbl_call0(element, 1);
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < object[0xd]);
    }

    if (object[0x11] != 0) {
        uVar2 = 0;
        int vector = static_cast<int>(object[0x11]);
        if (*reinterpret_cast<int*>(vector + 0xc) != 0) {
            do {
                uint32_t* element = *reinterpret_cast<uint32_t**>(
                    static_cast<uintptr_t>(*reinterpret_cast<int*>(vector + 4)) + uVar2 * 4);
                if (element != nullptr) {
                    vtbl_call0(element, 1);
                }
                uVar2 = uVar2 + 1;
            } while (uVar2 < *reinterpret_cast<uint32_t*>(vector + 0xc));
        }
        vtbl_call0(reinterpret_cast<void*>(static_cast<uintptr_t>(
                       static_cast<uint32_t>(vector))), 1);
    }

    object[10] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c13f0));
    operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(object[0xb])));
    FUN_00540c90();
    return;
}

// ---------------------------------------------------------------------------
// 0x542690 — observed shape
// Stores the flag at +0x24; when clearing it, scans the slot array at +0x2c
// (count +0x34) from index 1 and keeps the flag set if any slot is occupied.
// ---------------------------------------------------------------------------
// 0x00542690 — observed shape
void FUN_00542690(void* self, int param_1)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);

    *reinterpret_cast<uint8_t*>(base + 0x24) = (param_1 != 0);
    if (param_1 == 0) {
        uint32_t uVar2 = 1;
        if (1 < *reinterpret_cast<uint32_t*>(base + 0x34)) {
            int* piVar1 = *reinterpret_cast<int**>(base + 0x2c);
            for (;;) {
                piVar1 = piVar1 + 1;
                if (*piVar1 != 0) {
                    *reinterpret_cast<uint8_t*>(base + 0x24) = 1;
                    break;
                }
                uVar2 = uVar2 + 1;
                if (*reinterpret_cast<uint32_t*>(base + 0x34) <= uVar2) {
                    return;
                }
            }
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x5426d0 — observed shape
// Default constructor: vtable, zeroed members, mode 3, two zeroed 16-bit
// fields at +0x14 and +0x16 (the latter 0xffb5) and a null tail pointer.
// ---------------------------------------------------------------------------
// 0x005426d0 — observed shape
void FUN_005426d0(void* self)
{
    uint32_t* object = reinterpret_cast<uint32_t*>(self);
    uint8_t* base = reinterpret_cast<uint8_t*>(self);

    *object = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c1430));
    object[1] = 0;
    object[2] = 3;
    object[3] = 0;
    object[4] = 0;
    *reinterpret_cast<uint16_t*>(base + 0x14) = 0;
    *reinterpret_cast<uint16_t*>(base + 0x16) = 0xffb5;
    object[6] = 0;
    return;
}

// ---------------------------------------------------------------------------
// 0x542700 — observed shape
// Constructing form: same layout as 0x5426d0 but seeded from the parameters,
// with an intrusive reference-count bump on the object at param_1.
// ---------------------------------------------------------------------------
// 0x00542700 — observed shape
void FUN_00542700(void* self, int param_1, uint32_t param_2, uint32_t param_3,
                  uint32_t param_4, uint32_t param_5)
{
    uint32_t* object = reinterpret_cast<uint32_t*>(self);
    uint8_t* base = reinterpret_cast<uint8_t*>(self);

    *object = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c1430));
    object[1] = static_cast<uint32_t>(param_1);
    if (param_1 != 0) {
        *reinterpret_cast<int*>(static_cast<uintptr_t>(static_cast<uint32_t>(param_1)) + 4) += 1;
    }
    object[2] = param_3;
    object[3] = param_4;
    object[4] = param_2;
    *reinterpret_cast<uint16_t*>(base + 0x14) = 0;
    *reinterpret_cast<uint16_t*>(base + 0x16) = 0xffb5;
    object[6] = param_5;
    return;
}

// ---------------------------------------------------------------------------
// 0x542750 — observed shape
// Destructor: installs the vtable, frees the +0x18 tail pointer and releases
// the +4 owner when its intrusive reference count drops to zero.
// ---------------------------------------------------------------------------
// 0x00542750 — observed shape
void FUN_00542750(void* self)
{
    uint32_t* object = reinterpret_cast<uint32_t*>(self);

    *object = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c1430));
    operator_delete(reinterpret_cast<void*>(static_cast<uintptr_t>(object[6])));

    uint32_t* owner = reinterpret_cast<uint32_t*>(
        static_cast<uintptr_t>(object[1]));
    if (owner != nullptr) {
        uint32_t* count = owner + 1;
        *count = *count + static_cast<uint32_t>(-1);
        if (*count == 0) {
            vtbl_call0(owner, 1);
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x542780 — observed shape
// Field-by-field equality test against param_1; the +4 owner is compared
// through its vtable entry 7 when present, then the scalar members, the two
// 16-bit fields and finally the +0x18 pointer (FUN_0054a770 decides the
// "different" answer there).
// ---------------------------------------------------------------------------
// 0x00542780 — observed shape
uint32_t FUN_00542780(void* self, int param_1)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    int iVar1;

    if (*reinterpret_cast<int**>(base + 4) == nullptr) {
        if (*reinterpret_cast<int*>(static_cast<uintptr_t>(static_cast<uint32_t>(param_1)) + 4) != 0) {
            return 0;
        }
    } else {
        char cVar2 = static_cast<char>(vtbl_call7(
            *reinterpret_cast<void**>(base + 4),
            static_cast<uint32_t>(*reinterpret_cast<int*>(
                static_cast<uintptr_t>(static_cast<uint32_t>(param_1)) + 4))));
        if (cVar2 == '\0') {
            return 0;
        }
    }
    if (*reinterpret_cast<int*>(base + 8) !=
        *reinterpret_cast<int*>(static_cast<uintptr_t>(static_cast<uint32_t>(param_1)) + 8)) {
        return 0;
    }
    if (*reinterpret_cast<int*>(base + 0xc) !=
        *reinterpret_cast<int*>(static_cast<uintptr_t>(static_cast<uint32_t>(param_1)) + 0xc)) {
        return 0;
    }
    if (*reinterpret_cast<int*>(base + 0x10) !=
        *reinterpret_cast<int*>(static_cast<uintptr_t>(static_cast<uint32_t>(param_1)) + 0x10)) {
        return 0;
    }
    if (*reinterpret_cast<int16_t*>(base + 0x14) !=
        *reinterpret_cast<int16_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(param_1)) + 0x14)) {
        return 0;
    }
    if (*reinterpret_cast<int16_t*>(base + 0x16) !=
        *reinterpret_cast<int16_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(param_1)) + 0x16)) {
        return 0;
    }
    iVar1 = *reinterpret_cast<int*>(base + 0x18);
    if (iVar1 != 0) {
        if (*reinterpret_cast<int*>(static_cast<uintptr_t>(static_cast<uint32_t>(param_1)) + 0x18) != 0) {
            char cVar2 = FUN_0054a770(
                *reinterpret_cast<int*>(static_cast<uintptr_t>(static_cast<uint32_t>(param_1)) + 0x18));
            if (cVar2 == '\0') {
                return 1;
            }
            return 0;
        }
        if (iVar1 != 0) goto LAB_00542801;
    }
    if (*reinterpret_cast<int*>(static_cast<uintptr_t>(static_cast<uint32_t>(param_1)) + 0x18) != 0) {
        return 0;
    }
    if (iVar1 == 0) {
        return 1;
    }
LAB_00542801:
    if (*reinterpret_cast<int*>(static_cast<uintptr_t>(static_cast<uint32_t>(param_1)) + 0x18) == 0) {
        return 0;
    }
    return 1;
}

// ---------------------------------------------------------------------------
// 0x542810 — observed shape
// Lexicographic compare of the six floats at +0x1c..+0x30, encoding the x87
// comparison result as bit 0xe (equal), bit 8 (less) and bit 10 (unordered).
// When every component compares equal the returned word keeps the high byte
// of the last comparison and sets bit 0.
// ---------------------------------------------------------------------------
// 0x00542810 — observed shape
static uint16_t fp_compare(float lhs, float rhs)
{
    return static_cast<uint16_t>(static_cast<uint32_t>(lhs < rhs) << 8) |
           static_cast<uint16_t>(
               static_cast<uint32_t>((lhs != lhs) || (rhs != rhs)) << 10) |
           static_cast<uint16_t>(static_cast<uint32_t>(lhs == rhs) << 0xe);
}

uint16_t FUN_00542810(void* self, int param_1)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    uint8_t* other =
        reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(param_1)));
    uint16_t uVar3 = static_cast<uint16_t>(FUN_00542780(self, param_1));

    if (static_cast<char>(uVar3) != '\0') {
        float fVar1 = *reinterpret_cast<float*>(other + 0x1c);
        float fVar2 = *reinterpret_cast<float*>(base + 0x1c);
        uVar3 = fp_compare(fVar2, fVar1);
        if (fVar2 == fVar1) {
            fVar1 = *reinterpret_cast<float*>(other + 0x20);
            fVar2 = *reinterpret_cast<float*>(base + 0x20);
            uVar3 = fp_compare(fVar2, fVar1);
            if (fVar2 == fVar1) {
                fVar1 = *reinterpret_cast<float*>(other + 0x24);
                fVar2 = *reinterpret_cast<float*>(base + 0x24);
                uVar3 = fp_compare(fVar2, fVar1);
                if (fVar2 == fVar1) {
                    fVar1 = *reinterpret_cast<float*>(other + 0x28);
                    fVar2 = *reinterpret_cast<float*>(base + 0x28);
                    uVar3 = fp_compare(fVar2, fVar1);
                    if (fVar2 == fVar1) {
                        fVar1 = *reinterpret_cast<float*>(other + 0x2c);
                        fVar2 = *reinterpret_cast<float*>(base + 0x2c);
                        uVar3 = fp_compare(fVar2, fVar1);
                        if (fVar2 == fVar1) {
                            fVar1 = *reinterpret_cast<float*>(other + 0x30);
                            fVar2 = *reinterpret_cast<float*>(base + 0x30);
                            uVar3 = fp_compare(fVar2, fVar1);
                            if (fVar2 == fVar1) {
                                return static_cast<uint16_t>(
                                    (uVar3 & 0xff00) | 1);
                            }
                        }
                    }
                }
            }
        }
    }
    return static_cast<uint16_t>(uVar3 & 0xff00);
}

// ---------------------------------------------------------------------------
// 0x542890 — observed shape
// Runs the 0x542780 comparison, then folds in an equality test of the +0x1c
// dword. The decompiler forms the result from the shifted self field and the
// comparison's low byte; both are preserved here.
// ---------------------------------------------------------------------------
// 0x00542890 — observed shape
uint32_t FUN_00542890(void* self, int param_1)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    uint8_t* other =
        reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(param_1)));
    uint32_t uVar1 = FUN_00542780(self, param_1);

    if (static_cast<char>(uVar1) == '\0') {
        return uVar1;
    }
    return (static_cast<uint32_t>(*reinterpret_cast<int*>(base + 0x1c)) >> 8) |
           (*reinterpret_cast<int*>(base + 0x1c) ==
                    *reinterpret_cast<int*>(other + 0x1c)
                ? 1u
                : 0u);
}

// ---------------------------------------------------------------------------
// 0x5428c0 — observed shape
// Vector-of-slots constructor: base ctor, two vtables, seven capacity/active
// counters, a 0x1c-byte slot array, seven initialized empty slots (each
// capacity-checked with its own index) and the trailing member state.
// ---------------------------------------------------------------------------
// 0x005428c0 — observed shape
void FUN_005428c0(void* self)
{
    uint32_t* object = reinterpret_cast<uint32_t*>(self);
    uint8_t* base = reinterpret_cast<uint8_t*>(self);

    FUN_00540c50();
    *object = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c13f4));
    object[10] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c13f0));
    object[0xc] = 7;
    object[0xf] = 1;
    object[0xd] = 0;
    object[0xe] = 0;
    object[0xb] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(
        thunk_FUN_00533c78(0x1c)));

    // Seven slots; the observed per-index guard is "capacity == 0" for slot 0
    // and "capacity < index + 1" for the rest.
    for (uint32_t i = 0; i < 7; ++i) {
        uint32_t local_4 = 0;
        if (object[0xc] < i + 1) {
            FUN_006b34a0(static_cast<int>(object[0xf]) + static_cast<int>(i));
        }
        FUN_005606f0(i, &local_4);
    }

    object[0x10] = 0;
    *reinterpret_cast<uint8_t*>(base + 0x24) = 0;
    object[0x11] = 0;
    object[8] = 2;
    return;
}

// ---------------------------------------------------------------------------
// 0x542a20 — observed shape
// Scalar deleting destructor forwarding to the 0x5425e0 destructor body.
// ---------------------------------------------------------------------------
// 0x00542a20 — observed shape
void FUN_00542a20(void* self, uint8_t param_1)
{
    FUN_005425e0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x542a40 — observed shape
// Constructing form of 0x5428c0: same slot-vector layout, but slot 0 receives
// a freshly built 0x1c-byte record seeded from FUN_00539c10(param_1, tag) and
// each subsequent slot is filled with a null pointer.
// ---------------------------------------------------------------------------
// 0x00542a40 — observed shape
void FUN_00542a40(void* self, uint32_t* param_1)
{
    uint32_t* object = reinterpret_cast<uint32_t*>(self);
    uint8_t* base = reinterpret_cast<uint8_t*>(self);

    FUN_00540c50();
    *object = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c13f4));
    object[10] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c13f0));
    object[0xc] = 7;
    object[0xf] = 1;
    object[0xd] = 0;
    object[0xe] = 0;
    object[0xb] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(
        thunk_FUN_00533c78(0x1c)));

    int iVar2 = FUN_00539c10(param_1, &DAT_007179a4);

    uint32_t* slot = static_cast<uint32_t*>(thunk_FUN_00533c78(0x1c));
    if (slot == nullptr) {
        slot = nullptr;
    } else {
        *slot = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c1430));
        slot[1] = static_cast<uint32_t>(iVar2);
        if (iVar2 != 0) {
            *reinterpret_cast<int*>(static_cast<uintptr_t>(static_cast<uint32_t>(iVar2)) + 4) += 1;
        }
        slot[2] = 3;
        slot[3] = 1;
        slot[4] = 0;
        *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(slot) + 0x14) = 0;
        *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(slot) + 0x16) = 0xffb5;
        slot[6] = 0;
    }

    if (object[0xc] == 0) {
        FUN_006b34a0(static_cast<int>(object[0xf]));
    }
    FUN_005606f0(0, &slot);

    for (uint32_t i = 1; i < 7; ++i) {
        slot = nullptr;
        if (object[0xc] < i + 1) {
            FUN_006b34a0(static_cast<int>(object[0xf]) + static_cast<int>(i));
        }
        FUN_005606f0(i, &slot);
    }

    object[0x10] = 0;
    *reinterpret_cast<uint8_t*>(base + 0x24) = 0;
    object[8] = 2;
    object[0x11] = 0;
    return;
}

// ---------------------------------------------------------------------------
// 0x542bf0 — observed shape
// Replaces slot (param_1 + 6) of the +0x2b array with param_2, maintaining
// the occupied counter at +0x40, then re-derives the "any slot occupied" flag
// at +0x24 the same way 0x542690 does.
// ---------------------------------------------------------------------------
// 0x00542bf0 — observed shape
void FUN_00542bf0(void* self, int param_1, int param_2)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    int value = param_2;
    uint32_t slot = static_cast<uint32_t>(param_1) + 6;
    bool empty;

    if (slot < *reinterpret_cast<uint32_t*>(base + 0x34)) {
        uint32_t* element = *reinterpret_cast<uint32_t**>(
            static_cast<uintptr_t>(static_cast<uint32_t>(
                *reinterpret_cast<int*>(base + 0x2c))) + slot * 4);
        // Observed: decrement for (clear, occupied) and increment for
        // (set, empty) pairs.
        if ((param_2 == 0 && element != nullptr) ||
            (param_2 != 0 && element == nullptr)) {
            *reinterpret_cast<int*>(base + 0x40) += (param_2 == 0) ? -1 : 1;
        }
        FUN_005606f0(slot, &value);
        if (element != nullptr) {
            vtbl_call0(element, 1);
        }
        empty = (param_2 == 0);
    } else {
        if (*reinterpret_cast<uint32_t*>(base + 0x30) <= slot) {
            FUN_006b34a0(*reinterpret_cast<int*>(base + 0x3c) + static_cast<int>(slot));
        }
        FUN_005606f0(slot, &value);
        if (value == 0) {
            empty = true;
        } else {
            *reinterpret_cast<int*>(base + 0x40) += 1;
            empty = false;
        }
    }

    *reinterpret_cast<uint8_t*>(base + 0x24) = empty ? 0 : 1;
    if (empty) {
        uint32_t uVar5 = 1;
        if (1 < *reinterpret_cast<uint32_t*>(base + 0x34)) {
            int* piVar3 = *reinterpret_cast<int**>(base + 0x2c);
            for (;;) {
                piVar3 = piVar3 + 1;
                if (*piVar3 != 0) {
                    *reinterpret_cast<uint8_t*>(base + 0x24) = 1;
                    break;
                }
                uVar5 = uVar5 + 1;
                if (*reinterpret_cast<uint32_t*>(base + 0x34) <= uVar5) {
                    return;
                }
            }
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x542cb0 — observed shape
// Lazily creates the +0x44 vector (0x18-byte object, vtable 0x710bf8) and
// either replaces slot param_1 (releasing the old element) or, when the slot
// is beyond the current active count, stores the value with a capacity guard.
// ---------------------------------------------------------------------------
// 0x00542cb0 — observed shape
void FUN_00542cb0(void* self, uint32_t param_1, int param_2)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);

    if (*reinterpret_cast<int*>(base + 0x44) == 0) {
        uint32_t* vector = static_cast<uint32_t*>(thunk_FUN_00533c78(0x18));
        if (vector == nullptr) {
            vector = nullptr;
        } else {
            *vector = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_00710bf8));
            vector[2] = 0;
            vector[5] = 1;
            vector[3] = 0;
            vector[4] = 0;
            vector[1] = 0;
        }
        *reinterpret_cast<uint32_t**>(base + 0x44) = vector;
    }

    int iVar1 = *reinterpret_cast<int*>(base + 0x44);
    if (param_1 < *reinterpret_cast<uint32_t*>(iVar1 + 0xc)) {
        uint32_t* element = *reinterpret_cast<uint32_t**>(
            static_cast<uintptr_t>(static_cast<uint32_t>(
                *reinterpret_cast<int*>(iVar1 + 4))) + param_1 * 4);
        FUN_005606f0(param_1, &param_2);
        if (element != nullptr) {
            vtbl_call0(element, 1);
        }
    } else if (param_2 != 0) {
        if (*reinterpret_cast<uint32_t*>(iVar1 + 8) <= param_1) {
            FUN_006b34a0(*reinterpret_cast<int*>(iVar1 + 0x14) + static_cast<int>(param_1));
        }
        FUN_005606f0(param_1, &param_2);
        return;
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x542d70 — observed shape
// Chunk loader for the object graph: two 4-byte header reads feed the +0x20
// counter and the element count, the version at param_1[7] selects the record
// layout (0x303000d / 0x4010000 / 0x5000010 thresholds), each element is read
// with a 4-byte (old) or 1-byte (new) presence flag and optionally built into
// a 0x1c- or 0x34-byte record, and a trailing version-gated block fills the
// +0x44-vector member. The "occupied" byte at +0x24 is recomputed last.
//
// NEEDS_MANUAL: the listing reports stack-slot aliasing for the read targets
// and a live-in ESI count (unaff_ESI); the reads are modeled as explicit
// locals and the count as an extra register-input parameter.
// ---------------------------------------------------------------------------
// 0x00542d70 — observed shape
void FUN_00542d70(void* self, int* param_1, uint32_t unaff_ESI)
{
    uint32_t* object = reinterpret_cast<uint32_t*>(self);
    uint8_t* base = reinterpret_cast<uint8_t*>(self);

    uintptr_t reader = static_cast<uint32_t>(param_1[0x57]);
    uint32_t version = static_cast<uint32_t>(param_1[7]);
    int32_t readWord = 0;
    int32_t slotValue = 0;

    FUN_005403d0();

    stream_read(reinterpret_cast<void*>(reader), &readWord, 4);
    object[8] = static_cast<uint32_t>(readWord);
    stream_read(reinterpret_cast<void*>(reader), &readWord, 4);

    FUN_006b34a0(static_cast<int>(unaff_ESI));
    uint32_t uVar7 = (version < 0x303000d) ? unaff_ESI + 1 : unaff_ESI;
    FUN_00545df0(uVar7);

    uVar7 = 0;
    if (unaff_ESI != 0) {
        do {
            int* node = nullptr;
            uint8_t flagByte = 0;

            if (version < 0x4010000) {
                // Reads a dword into the scratch slot; the flag is forced to
                // zero on this path (observed `unaff_EDI = 0`).
                stream_read(reinterpret_cast<void*>(reader), &slotValue, 4);
                flagByte = 0;
            } else {
                stream_read(reinterpret_cast<void*>(reader), &flagByte, 1);
            }
            char cVar6 = static_cast<char>(flagByte);
            uint32_t uVar4 = uVar7;

            // The listing reaches the legacy insertion body either from the
            // old-version path or from the new-version path when the element
            // index is not 5 (jump to LAB_00542e47).
            bool legacy = (version < 0x303000d) || (uVar7 != 5);
            if (legacy) {
                if (version < 0x303000d && 4 < uVar7) {
                    FUN_00545df0(0);
                    uVar4 = uVar7 + 1;
                }
                FUN_00545df0(static_cast<uint32_t>(cVar6));
                if (cVar6 != '\0') {
                    node = static_cast<int*>(thunk_FUN_00533c78(0x1c));
                    if (node == nullptr) {
                        node = nullptr;
                    } else {
                        *node = static_cast<int>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c1430));
                        node[1] = 0;
                        node[2] = 3;
                        node[3] = 0;
                        node[4] = 0;
                        *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(node) + 0x14) = 0;
                        *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(node) + 0x16) = 0xffb5;
                        node[6] = 0;
                    }
                    vtbl_call1(node, param_1);
                }
                if ((uVar4 < static_cast<uint32_t>(object[0xc])) ||
                    (FUN_006b34a0(static_cast<int>(object[0xf]) + static_cast<int>(uVar4)),
                     uVar4 < static_cast<uint32_t>(object[0xc]))) {
                    if (uVar4 < static_cast<uint32_t>(object[0xd])) {
                        if (node == nullptr) {
                            if (*reinterpret_cast<int*>(
                                    static_cast<uintptr_t>(object[0xb]) + uVar4 * 4) != 0) {
                                object[0xe] = object[0xe] - 1;
                            }
                        } else if (*reinterpret_cast<int*>(
                                       static_cast<uintptr_t>(object[0xb]) + uVar4 * 4) == 0) {
                            object[0xe] = object[0xe] + 1;
                        }
                    } else {
                        object[0xd] = uVar4 + 1;
                        if (node != nullptr) {
                            object[0xe] = object[0xe] + 1;
                        }
                    }
                    *reinterpret_cast<int**>(
                        static_cast<uintptr_t>(object[0xb]) + uVar4 * 4) = node;
                }
            } else {
                FUN_00545df0(static_cast<uint32_t>(cVar6));
                if (cVar6 != '\0') {
                    node = static_cast<int*>(thunk_FUN_00533c78(0x34));
                    if (node == nullptr) {
                        node = nullptr;
                    } else {
                        node[1] = 0;
                        node[2] = 3;
                        node[3] = 0;
                        node[4] = 0;
                        *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(node) + 0x14) = 0;
                        *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(node) + 0x16) = 0xffb5;
                        node[6] = 0;
                        *node = static_cast<int>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c143c));
                        node[7] = 0x3f800000;
                        node[8] = 0;
                        node[9] = 0x3f000000;
                        node[10] = 0;
                        node[0xb] = 0;
                        node[0xc] = 0x3f000000;
                    }
                    vtbl_call1(node, param_1);
                }
                if (static_cast<uint32_t>(object[0xc]) < 6) {
                    FUN_006b34a0(static_cast<int>(object[0xf]) + 5);
                }
                FUN_005606f0(5, &slotValue);
            }
            uVar7 = uVar7 + 1;
        } while (uVar7 < unaff_ESI);
    }

    if (0x5000010 < version) {
        int32_t count2 = 0;
        stream_read(reinterpret_cast<void*>(reader), &count2, 4);
        FUN_00545df0(static_cast<uint32_t>(count2));
        if (count2 != 0) {
            uint32_t* vector = static_cast<uint32_t*>(thunk_FUN_00533c78(0x18));
            if (vector == nullptr) {
                vector = nullptr;
            } else {
                *vector = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_00710bf8));
                vector[2] = 0;
                vector[5] = 1;
                vector[3] = 0;
                vector[4] = 0;
                vector[1] = 0;
            }
            object[0x11] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(vector));

            uint32_t index = 0;
            for (;;) {
                uint8_t flag2 = 0;
                stream_read(reinterpret_cast<void*>(reader), &flag2, 1);
                FUN_00545df0(static_cast<uint32_t>(flag2));

                int* element = nullptr;
                if (flag2 != '\0') {
                    element = static_cast<int*>(thunk_FUN_00533c78(0x20));
                    if (element == nullptr) {
                        element = nullptr;
                    } else {
                        element[1] = 0;
                        element[2] = 3;
                        element[3] = 0;
                        element[4] = 0;
                        *reinterpret_cast<uint16_t*>(
                            reinterpret_cast<uint8_t*>(element) + 0x14) = 0;
                        *reinterpret_cast<uint16_t*>(
                            reinterpret_cast<uint8_t*>(element) + 0x16) = 0xffb5;
                        element[6] = 0;
                        *element = static_cast<int>(reinterpret_cast<uintptr_t>(&PTR_FUN_0070d038));
                        element[7] = 0;
                    }
                    vtbl_call1(element, param_1);
                }

                int vectorObj = static_cast<int>(object[0x11]);
                if ((index < *reinterpret_cast<uint32_t*>(vectorObj + 8)) ||
                    (FUN_006b34a0(*reinterpret_cast<int*>(vectorObj + 0x14) +
                                  static_cast<int>(index)),
                     index < *reinterpret_cast<uint32_t*>(vectorObj + 8))) {
                    if (index < *reinterpret_cast<uint32_t*>(vectorObj + 0xc)) {
                        if (element == nullptr) {
                            if (*reinterpret_cast<int*>(
                                    static_cast<uintptr_t>(*reinterpret_cast<int*>(vectorObj + 4)) +
                                    index * 4) != 0) {
                                *reinterpret_cast<int*>(vectorObj + 0x10) =
                                    *reinterpret_cast<int*>(vectorObj + 0x10) - 1;
                            }
                        } else if (*reinterpret_cast<int*>(
                                       static_cast<uintptr_t>(*reinterpret_cast<int*>(vectorObj + 4)) +
                                       index * 4) == 0) {
                            *reinterpret_cast<int*>(vectorObj + 0x10) =
                                *reinterpret_cast<int*>(vectorObj + 0x10) + 1;
                        }
                    } else {
                        *reinterpret_cast<uint32_t*>(vectorObj + 0xc) = index + 1;
                        if (element != nullptr) {
                            *reinterpret_cast<int*>(vectorObj + 0x10) =
                                *reinterpret_cast<int*>(vectorObj + 0x10) + 1;
                        }
                    }
                    *reinterpret_cast<int**>(
                        static_cast<uintptr_t>(*reinterpret_cast<int*>(vectorObj + 4)) +
                        index * 4) = element;
                }

                index = index + 1;
                if (static_cast<uint32_t>(count2) <= index) break;
            }
        }
    }

    uint32_t scan = 1;
    *reinterpret_cast<uint8_t*>(base + 0x24) = 0;
    if (1 < static_cast<uint32_t>(object[0xd])) {
        int* entry = reinterpret_cast<int*>(static_cast<uintptr_t>(object[0xb]));
        for (;;) {
            entry = entry + 1;
            if (*entry != 0) {
                *reinterpret_cast<uint8_t*>(base + 0x24) = 1;
                break;
            }
            scan = scan + 1;
            if (static_cast<uint32_t>(object[0xd]) <= scan) {
                return;
            }
        }
    }
    return;
}
