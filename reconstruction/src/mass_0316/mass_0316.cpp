// mass_0316 — unverified decompiler-derived candidate definitions.
// Clean-room from Ghidra 12.2 pseudocode (analysis/pseudocode/functions/*).
// No compiler or test has been run; no PASS claim.
//
// Conventions used in this batch:
//  * `self` is the provider's `in_ECX` receiver, passed explicitly (never `this`).
//  * Byte offsets are expressed on a `uint32_t* p = (uint32_t*)self` view; every
//    `p[n]` therefore is the provider's `in_ECX[n]` (byte offset n*4).
//  * Where the listing shows a thiscall whose receiver is implied but not
//    printed (a constructor, a scalar deleting destructor, a push helper), the
//    receiver is reconstructed and the reasoning is noted at the call site.
//  * The three scalar-deleting destructors used for the three tracked element
//    arrays are FUN_0065d683 (array A), FUN_00615a4f (array B) and
//    FUN_00614343 (array C); all three take (self, flags) and free `self` when
//    bit 0 of `flags` is set.

#include <cstdint>
#include <cstddef>
#include <cmath>
#include <cstring>
#include <windows.h>

extern void __cdecl operator_delete(void* p);

extern void* __cdecl FUN_00533c78(uint32_t size);

// Pool allocator behind 0x65d612: (size, block/alignment hint).
extern void* __cdecl FUN_0065aaac(uint32_t param_1, uint32_t param_2);

// Head of the free/recycle list threaded through dword offset 0x78.
extern int32_t DAT_0072be30;

// Vtable installed by the 0x65d65d constructor body.
extern void* PTR_FUN_006ee224;

// --- helpers referenced by the assigned bodies -----------------------------
extern void* __thiscall FUN_005f6015(void* self);            // ctor, returns self
extern void __thiscall FUN_006338c7(void* self);
extern void* __cdecl FUN_0065d0b4(uint32_t size);
extern void* __thiscall FUN_0065cc1a(void* self);            // ctor, returns self
extern int32_t __cdecl FUN_0065d0ff(uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4);
extern int32_t __cdecl FUN_0065d35e(uint32_t p1);
extern int32_t __cdecl FUN_006a6952(uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4);
extern int32_t __cdecl FUN_006a699a(uint32_t p1);
extern void __thiscall FUN_00615a4f(void* self, uint32_t flags);   // array-B element dtor
extern void __thiscall FUN_00614343(void* self, uint32_t flags);   // array-C element dtor

// --- batch functions (declared so definition order stays task order) -------
// The size argument is elided at the 0x65d9d5 call site (Ghidra models the
// call as `FUN_0065d612()`); see the NEEDS_MANUAL note on the definition.
extern void* __cdecl FUN_0065d612(uint32_t param_1 = 0);
extern uint32_t __thiscall FUN_0065d491(void* self, uint32_t param_1, uint32_t param_2,
                                        uint32_t param_3, uint64_t param_4);
extern uint32_t __thiscall FUN_0065d501(void* self, const uint32_t* param_1);
extern uint32_t __thiscall FUN_0065d5bd(void* self, const void* param_1);
extern void __thiscall FUN_0065d683(void* self, uint8_t param_1);
extern int32_t __thiscall FUN_0065d6a4(void* self, int32_t param_1);
extern int32_t __thiscall FUN_0065d75e(void* self, uint32_t* param_1);
extern int32_t __thiscall FUN_0065d8c2(void* self, int32_t param_1);
extern uint32_t __thiscall FUN_0065d97c(void* self, uint32_t param_1, uint32_t param_2,
                                        uint32_t param_3, uint32_t param_4);
extern uint32_t __thiscall FUN_0065d9d5(void* self, uint32_t param_1, uint32_t param_2,
                                        uint32_t param_3, uint64_t param_4);
extern uint32_t __thiscall FUN_0065da35(void* self, uint32_t param_1, uint32_t param_2,
                                        uint32_t param_3);
extern uint32_t __thiscall FUN_0065da8c(void* self, uint32_t param_1);
extern uint32_t __thiscall FUN_0065dadc(void* self, const uint32_t* param_1);
extern uint32_t __thiscall FUN_0065db2e(void* self, uint32_t param_1);
extern const char* __thiscall FUN_0065db7d(void* self, int32_t param_1);
extern void __thiscall FUN_0065dba2(void* self);
extern uint32_t __thiscall FUN_0065dc39(void* self, const void* param_1);

// ---------------------------------------------------------------------------
// Element-stride resolver. Reads the format tag in dword 0, derives a stride
// from the tag class (0 -> 0, 0x50000000 / 0x70800000 -> dword 3,
// 0x50200000 -> 1, 0x6xxxxxxx -> 4, otherwise the low 20 tag bits), then
// bounds-checks `stride * param_1 + stride` against the capacity in dword 3.
// On success stores `dword 4 + stride * param_1 * 4` through param_2 and
// returns the stride; on overflow/underflow stores 0 and returns 0.
// 0x65d412 — observed shape
uint32_t __thiscall FUN_0065d412(void* self, int32_t param_1, int32_t* param_2)
{
    uint32_t* p = (uint32_t*)self;
    uint32_t tag = p[0];
    uint32_t stride = tag & 0xfff00000u;

    if (stride == 0u) {
        stride = 0u;
    }
    else if (stride != 0x50000000u) {
        if (stride == 0x50200000u) {
            stride = 1u;
        }
        else if (stride != 0x70800000u) {
            if ((tag & 0xf0000000u) == 0x60000000u) {
                stride = 4u;
            }
            else {
                stride = tag & 0xfffffu;
            }
        }
        else {
            stride = p[3];
        }
    }
    else {
        stride = p[3];
    }

    if ((int32_t)p[3] < (int32_t)(stride * (uint32_t)param_1 + stride)) {
        if (param_2 != nullptr) {
            *param_2 = 0;
        }
        stride = 0u;
    }
    else if (param_2 != nullptr) {
        *param_2 = (int32_t)p[4] + (int32_t)(stride * (uint32_t)param_1 * 4u);
    }
    return stride;
}

// ---------------------------------------------------------------------------
// Initializer for the 0x78-byte variant record. Stores the caller's selector
// dword in slot 1, the span/index dwords in slots 3 and 4, the 8-byte payload
// in the pair at byte offsets 0x20 and 0x28, seeds the "unset" sentinels with
// 0xffffffff (slots 2, 5, 0xc-0xe, 0x10-0x16, 0x1b, 0x1d), sets slot 6 to 1
// and clears slots 0, 0xf, 0x17-0x1a, 0x1c. Returns 0. Store order follows the
// listing.
// 0x65d491 — observed shape
uint32_t __thiscall FUN_0065d491(void* self, uint32_t param_1, uint32_t param_2,
                                 uint32_t param_3, uint64_t param_4)
{
    uint32_t* p = (uint32_t*)self;

    *(uint64_t*)(p + 8) = param_4;
    p[3] = param_2;
    *(uint64_t*)(p + 10) = param_4;
    p[1] = param_1;
    p[4] = param_3;
    p[2] = 0xffffffffu;
    p[5] = 0xffffffffu;
    p[0xc] = 0xffffffffu;
    p[0xd] = 0xffffffffu;
    p[0xe] = 0xffffffffu;
    p[0x10] = 0xffffffffu;
    p[0x11] = 0xffffffffu;
    p[0x12] = 0xffffffffu;
    p[0x13] = 0xffffffffu;
    p[0x14] = 0xffffffffu;
    p[0x15] = 0xffffffffu;
    p[0x16] = 0xffffffffu;
    p[0x1b] = 0xffffffffu;
    p[0x1d] = 0xffffffffu;
    p[6] = 1u;
    p[0] = 0u;
    p[0xf] = 0u;
    p[0x17] = 0u;
    p[0x18] = 0u;
    p[0x19] = 0u;
    p[0x1a] = 0u;
    p[0x1c] = 0u;
    return 0u;
}

// ---------------------------------------------------------------------------
// Copy-assignment body over the whole 0x78-byte record: dwords 1-6, the two
// 8-byte pairs at 0x20/0x28, dword 0, then dwords 0xc-0x1d in listing order.
// Returns 0x80004005 (E_FAIL) for a null source, 0 otherwise.
// 0x65d501 — observed shape
uint32_t __thiscall FUN_0065d501(void* self, const uint32_t* param_1)
{
    uint32_t* p = (uint32_t*)self;
    uint32_t result;

    if (param_1 == nullptr) {
        result = 0x80004005u;
    }
    else {
        p[1] = param_1[1];
        p[2] = param_1[2];
        p[3] = param_1[3];
        p[4] = param_1[4];
        p[5] = param_1[5];
        p[6] = param_1[6];
        *(uint64_t*)(p + 8) = *(const uint64_t*)(param_1 + 8);
        *(uint64_t*)(p + 10) = *(const uint64_t*)(param_1 + 10);
        p[0] = param_1[0];
        p[0xc] = param_1[0xc];
        p[0xd] = param_1[0xd];
        p[0xe] = param_1[0xe];
        p[0x10] = param_1[0x10];
        p[0xf] = param_1[0xf];
        p[0x11] = param_1[0x11];
        p[0x12] = param_1[0x12];
        p[0x13] = param_1[0x13];
        p[0x14] = param_1[0x14];
        p[0x15] = param_1[0x15];
        p[0x16] = param_1[0x16];
        p[0x17] = param_1[0x17];
        p[0x18] = param_1[0x18];
        p[0x19] = param_1[0x19];
        p[0x1a] = param_1[0x1a];
        p[0x1b] = param_1[0x1b];
        p[0x1c] = param_1[0x1c];
        p[0x1d] = param_1[0x1d];
        result = 0u;
    }
    return result;
}

// ---------------------------------------------------------------------------
// Copies the six trailing dwords at byte offsets 0x60, 0x64, 0x68, 0x6c, 0x70,
// 0x74 from the source record (listing order: 0x60, 0x64, 0x68, 0x6c, 0x70,
// 0x74). Returns 0x80004005 (E_FAIL) for a null source, 0 otherwise.
// 0x65d5bd — observed shape
uint32_t __thiscall FUN_0065d5bd(void* self, const void* param_1)
{
    uint8_t* p = (uint8_t*)self;
    const uint8_t* src = (const uint8_t*)param_1;
    uint32_t result;

    if (param_1 == nullptr) {
        result = 0x80004005u;
    }
    else {
        *(uint32_t*)(p + 0x60) = *(const uint32_t*)(src + 0x60);
        *(uint32_t*)(p + 0x64) = *(const uint32_t*)(src + 0x64);
        *(uint32_t*)(p + 0x68) = *(const uint32_t*)(src + 0x68);
        *(uint32_t*)(p + 0x6c) = *(const uint32_t*)(src + 0x6c);
        *(uint32_t*)(p + 0x70) = *(const uint32_t*)(src + 0x70);
        *(uint32_t*)(p + 0x74) = *(const uint32_t*)(src + 0x74);
        result = 0u;
    }
    return result;
}

// ---------------------------------------------------------------------------
// Allocator used by the factory bodies at 0x65d97c / 0x65d9d5 / 0x65dadc: when
// the recycle list head DAT_0072be30 is empty it delegates to the pool
// allocator 0x65aaac with a 0x10 hint; otherwise it pops the head node and
// advances the list through the node's dword at offset 0x78.
// NEEDS_MANUAL: the listing types this function as returning void and drops the
// allocator result, but both call sites (0x65d9d5, 0x65dadc) consume EAX as the
// new object pointer, so the observed operations are returned here instead.
// 0x65d612 — observed shape
void* __cdecl FUN_0065d612(uint32_t param_1)
{
    if (DAT_0072be30 == 0) {
        return FUN_0065aaac(param_1, 0x10);
    }
    void* node = (void*)(intptr_t)DAT_0072be30;
    DAT_0072be30 = *(int32_t*)(DAT_0072be30 + 0x78);
    return node;
}

// ---------------------------------------------------------------------------
// Pushes a node onto the recycle/free list: links the current head into the
// node's dword at offset 0x78 and makes the node the new head. Null is ignored.
// Void return.
// 0x65d63f — observed shape
void __cdecl FUN_0065d63f(int32_t param_1)
{
    if (param_1 != 0) {
        *(int32_t*)(param_1 + 0x78) = DAT_0072be30;
        DAT_0072be30 = param_1;
    }
    return;
}

// ---------------------------------------------------------------------------
// Constructor body. Installs the vtable PTR_FUN_006ee224 in dword 0 and zeroes
// dword slots 1, 7, 4, 2, 8, 5, 3, 9, 6 in that listing order (three tracked
// arrays of count/pointer/capacity slots). Void return.
// 0x65d65d — observed shape
void __thiscall FUN_0065d65d(void* self)
{
    uint32_t* p = (uint32_t*)self;

    p[0] = (uint32_t)(uintptr_t)&PTR_FUN_006ee224;
    p[1] = 0u;
    p[7] = 0u;
    p[4] = 0u;
    p[2] = 0u;
    p[8] = 0u;
    p[5] = 0u;
    p[3] = 0u;
    p[9] = 0u;
    p[6] = 0u;
    return;
}

// ---------------------------------------------------------------------------
// Scalar-deleting destructor for the array-A element class: runs the base
// teardown 0x6338c7 (receiver passed implicitly in the listing, reconstructed
// here) and frees the receiver when bit 0 of the flags argument is set.
// 0x65d683 — observed shape
void __thiscall FUN_0065d683(void* self, uint8_t param_1)
{
    FUN_006338c7(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// ---------------------------------------------------------------------------
// Appends param_1 to tracked array A (count in dword 1, block in dword 4,
// capacity in dword 7) and returns the new index. When full, grows to 0x10 for
// an empty block otherwise doubles the capacity, copies the live dwords,
// zero-fills the remainder, frees the old block and installs the new one. On
// allocation failure the appended element is destroyed through 0x65d683 and -1
// is returned.
// 0x65d6a4 — observed shape
int32_t __thiscall FUN_0065d6a4(void* self, int32_t param_1)
{
    uint32_t* p = (uint32_t*)self;
    int32_t cap = (int32_t)p[7];

    if ((int32_t)p[1] == cap) {
        cap = (cap == 0) ? 0x10 : cap * 2;
        uint32_t* grown = (uint32_t*)FUN_00533c78((uint32_t)cap << 2);
        if (grown == nullptr) {
            if (param_1 != 0) {
                FUN_0065d683((void*)(intptr_t)param_1, 1);
            }
            return -1;
        }
        uint32_t* src = (uint32_t*)p[4];
        uint32_t* dst = grown;
        for (uint32_t n = p[1] & 0x3fffffffu; n != 0; --n) {
            *dst++ = *src++;
        }
        // The listing also emits a byte-tail copy loop; its trip count is zero.
        uint32_t* tail = grown + p[1];
        for (uint32_t n = ((uint32_t)cap - p[1]) & 0x3fffffffu; n != 0; --n) {
            *tail++ = 0u;
        }
        // Byte-tail zero loop of the memcpy expansion; trip count zero.
        operator_delete((void*)p[4]);
        p[7] = (uint32_t)cap;
        p[4] = (uint32_t)(uintptr_t)grown;
    }
    *(int32_t*)(p[4] + p[1] * 4u) = param_1;
    int32_t index = (int32_t)p[1];
    p[1] = (uint32_t)(index + 1);
    return index;
}

// ---------------------------------------------------------------------------
// Appends the variant record param_1 to tracked array B (count in dword 2,
// block in dword 5, capacity in dword 8) and returns the new index. Growth base
// is 0x400; on allocation failure the record is destroyed through 0x615a4f and
// -1 is returned. For a non-null record whose referenced array-A element has
// bit 0 of its byte 5 set and whose dword 2 is still -1, the record's flags
// dword 0 is tagged: bit 0x80 marks a classified variant, bit 1 for the values
// 0.0/1.0, bit 2 for an integral payload, bit 4 for a strictly positive payload,
// bit 8 for a payload <= 0, bit 0x10 for |payload| < 1. The payload is the
// double at record byte offset 0x20.
// NEEDS_MANUAL: the two x87 comparisons Ghidra prints against `extraout_ST0`
// lost their operand (an unmodelled fldz); they are reproduced against 0.0,
// which is the only reading consistent with the paired bit 4 / bit 8 tests.
// 0x65d75e — observed shape
int32_t __thiscall FUN_0065d75e(void* self, uint32_t* param_1)
{
    uint32_t* p = (uint32_t*)self;
    int32_t cap = (int32_t)p[8];

    if ((int32_t)p[2] == cap) {
        cap = (cap == 0) ? 0x400 : cap * 2;
        uint32_t* grown = (uint32_t*)FUN_00533c78((uint32_t)cap << 2);
        if (grown == nullptr) {
            if (param_1 != nullptr) {
                FUN_00615a4f((void*)param_1, 1);
            }
            return -1;
        }
        uint32_t* src = (uint32_t*)p[5];
        uint32_t* dst = grown;
        for (uint32_t n = p[2] & 0x3fffffffu; n != 0; --n) {
            *dst++ = *src++;
        }
        // Byte-tail copy loop of the memcpy expansion; trip count zero.
        uint32_t* tail = grown + p[2];
        for (uint32_t n = ((uint32_t)cap - p[2]) & 0x3fffffffu; n != 0; --n) {
            *tail++ = 0u;
        }
        // Byte-tail zero loop of the memcpy expansion; trip count zero.
        operator_delete((void*)p[5]);
        p[5] = (uint32_t)(uintptr_t)grown;
        p[8] = (uint32_t)cap;
    }

    if (param_1 != nullptr &&
        (*(uint8_t*)(*(int32_t*)(p[4] + param_1[1] * 4u) + 5) & 1) != 0 &&
        param_1[2] == 0xffffffffu) {
        *(uint8_t*)param_1 = (uint8_t)(*(uint8_t*)param_1 | 0x80);
        double value = *(double*)((uint8_t*)param_1 + 0x20);
        if (value == 0.0 || value == 1.0) {
            param_1[0] |= 1u;
        }
        int32_t truncated = (int32_t)value;                 // listing: ftol()
        if (std::fabs(value - (double)truncated) < 1e-06) {
            param_1[0] |= 2u;
        }
        if (value > 0.0) {
            param_1[0] |= 4u;
        }
        if (value <= 0.0) {
            param_1[0] |= 8u;
        }
        double magnitude = std::fabs(value);
        if (magnitude < 1.0) {
            param_1[0] |= 0x10u;
        }
    }
    *(uint32_t**)(p[5] + p[2] * 4u) = param_1;
    int32_t index = (int32_t)p[2];
    p[2] = (uint32_t)(index + 1);
    return index;
}

// ---------------------------------------------------------------------------
// Appends param_1 to tracked array C (count in dword 3, block in dword 6,
// capacity in dword 9) and returns the new index. Growth base is 0x100;
// allocation failure destroys the appended element through 0x614343 and
// returns -1. Same copy/zero-fill/free sequence as the other two push helpers.
// 0x65d8c2 — observed shape
int32_t __thiscall FUN_0065d8c2(void* self, int32_t param_1)
{
    uint32_t* p = (uint32_t*)self;
    int32_t cap = (int32_t)p[9];

    if ((int32_t)p[3] == cap) {
        cap = (cap == 0) ? 0x100 : cap * 2;
        uint32_t* grown = (uint32_t*)FUN_00533c78((uint32_t)cap << 2);
        if (grown == nullptr) {
            if (param_1 != 0) {
                FUN_00614343((void*)(intptr_t)param_1, 1);
            }
            return -1;
        }
        uint32_t* src = (uint32_t*)p[6];
        uint32_t* dst = grown;
        for (uint32_t n = p[3] & 0x3fffffffu; n != 0; --n) {
            *dst++ = *src++;
        }
        // Byte-tail copy loop of the memcpy expansion; trip count zero.
        uint32_t* tail = grown + p[3];
        for (uint32_t n = ((uint32_t)cap - p[3]) & 0x3fffffffu; n != 0; --n) {
            *tail++ = 0u;
        }
        // Byte-tail zero loop of the memcpy expansion; trip count zero.
        operator_delete((void*)p[6]);
        p[9] = (uint32_t)cap;
        p[6] = (uint32_t)(uintptr_t)grown;
    }
    *(int32_t*)(p[6] + p[3] * 4u) = param_1;
    int32_t index = (int32_t)p[3];
    p[3] = (uint32_t)(index + 1);
    return index;
}

// ---------------------------------------------------------------------------
// Factory for an array-A element: allocates 0x34 bytes, runs the element
// constructor 0x5f6015, fills the element from the four arguments through
// 0x6a6952, then appends it to array A through 0x65d6a4 and returns that index.
// A failing fill destroys the element through 0x65d683; allocation or fill
// failure yields 0xffffffff.
// 0x65d97c — observed shape
uint32_t __thiscall FUN_0065d97c(void* self, uint32_t param_1, uint32_t param_2,
                                 uint32_t param_3, uint32_t param_4)
{
    void* obj = FUN_00533c78(0x34);
    if (obj != nullptr) {
        obj = FUN_005f6015(obj);
    }
    if (obj != nullptr) {
        int32_t filled = FUN_006a6952(param_1, param_2, param_3, param_4);
        if (filled >= 0) {
            return (uint32_t)FUN_0065d6a4(self, (int32_t)(intptr_t)obj);
        }
        FUN_0065d683(obj, 1);
    }
    return 0xffffffffu;
}

// ---------------------------------------------------------------------------
// Factory for an array-B record: takes a record from 0x65d612 (pool alloc, or
// the recycle list at DAT_0072be30), runs the record constructor 0x5f6015,
// initializes it from the four arguments through 0x65d491, then appends it to
// array B through 0x65d75e and returns that index. A failing initialize
// destroys the record through 0x615a4f; otherwise 0xffffffff is returned.
// The listing shows the 0x615a4f call with neither receiver nor flag; both are
// reconstructed here as the created record and flags 1.
// 0x65d9d5 — observed shape
uint32_t __thiscall FUN_0065d9d5(void* self, uint32_t param_1, uint32_t param_2,
                                 uint32_t param_3, uint64_t param_4)
{
    void* obj = FUN_0065d612();
    if (obj != nullptr) {
        obj = FUN_005f6015(obj);
    }
    if (obj != nullptr) {
        int32_t inited = (int32_t)FUN_0065d491(obj, param_1, param_2, param_3, param_4);
        if (inited >= 0) {
            return (uint32_t)FUN_0065d75e(self, (uint32_t*)obj);
        }
        FUN_00615a4f(obj, 1);
    }
    return 0xffffffffu;
}

// ---------------------------------------------------------------------------
// Factory for an array-C element: allocates 0x74 bytes through 0x65d0b4, runs
// the element constructor 0x65cc1a, fills it from three arguments plus a zero
// fourth through 0x65d0ff, then appends it to array C through 0x65d8c2 and
// returns that index. A failing fill destroys the element through 0x614343;
// allocation or fill failure yields 0xffffffff.
// 0x65da35 — observed shape
uint32_t __thiscall FUN_0065da35(void* self, uint32_t param_1, uint32_t param_2,
                                 uint32_t param_3)
{
    void* obj = FUN_0065d0b4(0x74);
    if (obj != nullptr) {
        obj = FUN_0065cc1a(obj);
    }
    if (obj != nullptr) {
        int32_t filled = FUN_0065d0ff(param_1, param_2, param_3, 0);
        if (filled >= 0) {
            return (uint32_t)FUN_0065d8c2(self, (int32_t)(intptr_t)obj);
        }
        FUN_00614343(obj, 1);
    }
    return 0xffffffffu;
}

// ---------------------------------------------------------------------------
// Single-argument variant of the array-A factory: allocates 0x34 bytes, runs
// the element constructor 0x5f6015, fills the element from 0x6a699a, appends it
// to array A through 0x65d6a4 and returns that index. A failing fill destroys
// the element through 0x65d683; allocation or fill failure yields 0xffffffff.
// 0x65da8c — observed shape
uint32_t __thiscall FUN_0065da8c(void* self, uint32_t param_1)
{
    void* obj = FUN_00533c78(0x34);
    if (obj != nullptr) {
        obj = FUN_005f6015(obj);
    }
    if (obj != nullptr) {
        int32_t filled = FUN_006a699a(param_1);
        if (filled >= 0) {
            return (uint32_t)FUN_0065d6a4(self, (int32_t)(intptr_t)obj);
        }
        FUN_0065d683(obj, 1);
    }
    return 0xffffffffu;
}

// ---------------------------------------------------------------------------
// Copy/factory variant for an array-B record: takes a record from 0x65d612 with
// a 0x80 size hint, runs the record constructor 0x5f6015, copy-assigns the
// source record into it through 0x65d501, then appends it to array B through
// 0x65d75e and returns that index. A failing copy destroys the record through
// 0x615a4f; otherwise 0xffffffff is returned. The listing spells the 0x615a4f
// call as `FUN_00615a4f(1)`; the receiver is reconstructed as the new record.
// 0x65dadc — observed shape
uint32_t __thiscall FUN_0065dadc(void* self, const uint32_t* param_1)
{
    void* obj = FUN_0065d612(0x80);
    if (obj != nullptr) {
        obj = FUN_005f6015(obj);
    }
    if (obj != nullptr) {
        int32_t copied = (int32_t)FUN_0065d501(obj, param_1);
        if (copied >= 0) {
            return (uint32_t)FUN_0065d75e(self, (uint32_t*)obj);
        }
        FUN_00615a4f(obj, 1);
    }
    return 0xffffffffu;
}

// ---------------------------------------------------------------------------
// Single-argument variant of the array-C factory: allocates 0x74 bytes through
// 0x65d0b4, runs the element constructor 0x65cc1a, fills the element from
// 0x65d35e, appends it to array C through 0x65d8c2 and returns that index. A
// failing fill destroys the element through 0x614343; allocation or fill
// failure yields 0xffffffff.
// 0x65db2e — observed shape
uint32_t __thiscall FUN_0065db2e(void* self, uint32_t param_1)
{
    void* obj = FUN_0065d0b4(0x74);
    if (obj != nullptr) {
        obj = FUN_0065cc1a(obj);
    }
    if (obj != nullptr) {
        int32_t filled = FUN_0065d35e(param_1);
        if (filled >= 0) {
            return (uint32_t)FUN_0065d8c2(self, (int32_t)(intptr_t)obj);
        }
        FUN_00614343(obj, 1);
    }
    return 0xffffffffu;
}

// ---------------------------------------------------------------------------
// Direction classifier: resolves element index param_1 of tracked array A
// (block in dword 4) and tests bit 0x20 of the element's byte 4. Returns the
// literal "output" when the bit is set, "input" otherwise.
// 0x65db7d — observed shape
const char* __thiscall FUN_0065db7d(void* self, int32_t param_1)
{
    uint32_t* p = (uint32_t*)self;
    const char* kind = "input";

    if ((*(uint8_t*)(*(int32_t*)(p[4] + *(int32_t*)(param_1 + 4) * 4u) + 4) & 0x20) != 0) {
        kind = "output";
    }
    return kind;
}

// ---------------------------------------------------------------------------
// Destructor body. Reinstalls the vtable PTR_FUN_006ee224, then walks the three
// tracked arrays in order: array A (count in dword 1, block in dword 4) with
// 0x65d683, array B (count in dword 2, block in dword 5) with 0x615a4f, array C
// (count in dword 3, block in dword 6) with 0x614343; each non-null element is
// destroyed with flags 1, then the block itself is freed. Void return.
// 0x65dba2 — observed shape
void __thiscall FUN_0065dba2(void* self)
{
    uint32_t* p = (uint32_t*)self;

    p[0] = (uint32_t)(uintptr_t)&PTR_FUN_006ee224;
    if (p[4] != 0) {
        uint32_t i = 0;
        if (p[1] != 0) {
            do {
                if (*(int32_t*)(p[4] + i * 4u) != 0) {
                    FUN_0065d683((void*)(intptr_t)*(int32_t*)(p[4] + i * 4u), 1);
                }
                ++i;
            } while (i < p[1]);
        }
        operator_delete((void*)p[4]);
    }
    if (p[5] != 0) {
        uint32_t i = 0;
        if (p[2] != 0) {
            do {
                if (*(int32_t*)(p[5] + i * 4u) != 0) {
                    FUN_00615a4f((void*)(intptr_t)*(int32_t*)(p[5] + i * 4u), 1);
                }
                ++i;
            } while (i < p[2]);
        }
        operator_delete((void*)p[5]);
    }
    if (p[6] != 0) {
        uint32_t i = 0;
        if (p[3] != 0) {
            do {
                if (*(int32_t*)(p[6] + i * 4u) != 0) {
                    FUN_00614343((void*)(intptr_t)*(int32_t*)(p[6] + i * 4u), 1);
                }
                ++i;
            } while (i < p[3]);
        }
        operator_delete((void*)p[6]);
    }
    return;
}

// ---------------------------------------------------------------------------
// Deep-copy builder over another instance of the same layout. For each of the
// three tracked arrays it resets the destination count, copies the source
// capacity verbatim, allocates that many dwords, and re-creates every source
// element through the matching factory (0x65da8c for array A at source +0x10,
// 0x65dadc for array B at source +0x14, 0x65db2e for array C at source +0x18),
// appending into this instance. Returns 0 on success and 0x8007000e
// (E_OUTOFMEMORY) as soon as an allocation fails or a factory returns -1.
// Count/pointer/capacity destinations are dwords 1/4/7 (A), 2/5/8 (B) and
// 3/6/9 (C).
// 0x65dc39 — observed shape
uint32_t __thiscall FUN_0065dc39(void* self, const void* param_1)
{
    uint32_t* p = (uint32_t*)self;
    const uint8_t* src = (const uint8_t*)param_1;
    uint32_t i = 0;

    p[1] = 0u;
    int32_t capA = *(const int32_t*)(src + 4);
    p[7] = (uint32_t)capA;
    void* blockA = FUN_00533c78((uint32_t)(capA << 2));
    p[4] = (uint32_t)(uintptr_t)blockA;
    if (blockA != nullptr) {
        if (*(const int32_t*)(src + 4) != 0) {
            do {
                int32_t made = (int32_t)FUN_0065da8c(
                    self, *(const uint32_t*)(src + 0x10 + i * 4u));
                if (made == -1) {
                    return 0x8007000eu;
                }
                ++i;
            } while (i < *(const uint32_t*)(src + 4));
        }
        p[2] = 0u;
        int32_t capB = *(const int32_t*)(src + 8);
        p[8] = (uint32_t)capB;
        void* blockB = FUN_00533c78((uint32_t)(capB << 2));
        i = 0;
        p[5] = (uint32_t)(uintptr_t)blockB;
        if (blockB != nullptr) {
            if (*(const int32_t*)(src + 8) != 0) {
                do {
                    int32_t made = (int32_t)FUN_0065dadc(
                        self, (const uint32_t*)(uintptr_t)*(const uint32_t*)(src + 0x14 + i * 4u));
                    if (made == -1) {
                        return 0x8007000eu;
                    }
                    ++i;
                } while (i < *(const uint32_t*)(src + 8));
            }
            p[3] = 0u;
            int32_t capC = *(const int32_t*)(src + 0xc);
            p[9] = (uint32_t)capC;
            void* blockC = FUN_00533c78((uint32_t)(capC << 2));
            i = 0;
            p[6] = (uint32_t)(uintptr_t)blockC;
            if (blockC != nullptr) {
                if (*(const int32_t*)(src + 0xc) != 0) {
                    do {
                        int32_t made = (int32_t)FUN_0065db2e(
                            self, *(const uint32_t*)(src + 0x18 + i * 4u));
                        if (made == -1) {
                            return 0x8007000eu;
                        }
                        ++i;
                    } while (i < *(const uint32_t*)(src + 0xc));
                }
                return 0u;
            }
        }
    }
    return 0x8007000eu;
}
