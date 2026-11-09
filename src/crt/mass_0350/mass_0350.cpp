//
// mass_0350.cpp — reconstruction batch mass_0350
// Target: Sid Meier's Pirates! (2004), PE32 i386
// Image: 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
//
// Each definition preserves the observed field offsets, constants, call
// order, return shape, and conditional structure of the Ghidra 12.2
// pseudocode in analysis/pseudocode/functions/*.c.
//
// This family is a tagged variant payload: the tag/count word lives at
// self+0x10, the payload words at self+0x18..self+0x64 (or self+0x58..),
// the side payload at self+0x98..self+0xa4, the string pointer at
// self+0x0c, the owned string at self+0x18 / self+0xd8, and a flags byte
// at self+0x14. Register receivers (in_ECX) are modeled as an explicit
// `void* self` first parameter.
//
#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---------------------------------------------------------------------------
// External helpers and globals referenced by the assigned listings only.
// ---------------------------------------------------------------------------
extern uint32_t PTR_FUN_006f5380;

void  operator_delete__(void* ptr);
void  operator_delete(void* ptr);
void* thunk_FUN_00533c78(uint32_t size);

void FUN_006b50f0(void* self);
void FUN_006b3dd0(int32_t param_1);
void FUN_006b40e0(int32_t param_1, int32_t param_2);
void FUN_006b3f10(int32_t* param_1);
void FUN_006b3f90(int32_t* param_1);
void FUN_006b3fc0(int32_t param_1, int32_t param_2);

// Sibling members used by this family; defined later in this file where the
// batch assigns them, declared here so the earlier definitions can call them.
bool FUN_006b4f80(void* obj, const char* text);
bool FUN_006b4fe0(void* obj, uint32_t value);
bool FUN_006b5000(void* obj, void* buffer, int32_t count);
bool FUN_006b5020(void* obj, uint32_t* string_slot);
bool FUN_006b5090(void* obj, uint32_t* value_slot);

// ---------------------------------------------------------------------------
// Offset accessors: every observed field access goes through these so the
// original byte offsets stay visible in each definition.
// ---------------------------------------------------------------------------
static inline uint32_t& u32_at(void* base, std::size_t off)
{
    return *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(base) + off);
}

static inline uint8_t& u8_at(void* base, std::size_t off)
{
    return *reinterpret_cast<uint8_t*>(static_cast<uint8_t*>(base) + off);
}

static inline char*& str_at(void* base, std::size_t off)
{
    return *reinterpret_cast<char**>(static_cast<uint8_t*>(base) + off);
}

// NUL-terminated length, mirroring the observed scan loop (end - (start + 1)).
static std::size_t text_length(const char* text)
{
    const char* p = text;
    char c;
    do {
        c = *p++;
    } while (c != '\0');
    return static_cast<std::size_t>(p - (text + 1));
}

// ---------------------------------------------------------------------------
// Virtual-call shapes observed in the listings: the receiver's vtable is
// loaded from its first word and the member is called through a byte offset.
// The original is __thiscall; the receiver is passed explicitly here.
// ---------------------------------------------------------------------------
typedef int32_t (__cdecl* VtableGet)(void* self);
typedef void    (__cdecl* VtableSet)(void* self, int32_t value);
typedef int32_t (__cdecl* StreamWrite)(void* self, void* buffer, int32_t count);

static inline int32_t vtable_get(void* obj, std::size_t slot_byte)
{
    void** vtbl = *reinterpret_cast<void***>(obj);
    return reinterpret_cast<VtableGet>(vtbl[slot_byte / 4])(obj);
}

static inline void vtable_set(void* obj, std::size_t slot_byte, int32_t value)
{
    void** vtbl = *reinterpret_cast<void***>(obj);
    reinterpret_cast<VtableSet>(vtbl[slot_byte / 4])(obj, value);
}

// Vtable slot 3 (byte offset 0xc): bounded stream write returning the count.
static inline int32_t stream_write(void* obj, void* buffer, int32_t count)
{
    void** vtbl = *reinterpret_cast<void***>(obj);
    return reinterpret_cast<StreamWrite>(vtbl[3])(obj, buffer, count);
}

// ---------------------------------------------------------------------------
// 0x6b4110 — stores the single payload word and side word under tag 4.
// ---------------------------------------------------------------------------
// 0x6b4110 — observed shape
uint32_t FUN_006b4110(void* self, uint32_t param_1, uint32_t param_2)
{
    if (u32_at(self, 0x10) == 4) {
        u32_at(self, 0x58) = param_1;
        u32_at(self, 0x98) = param_2;
        return 1;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6b4140 — stores two payload words and two side words under tag 5.
// The return is the CONCAT31 of the last stored word with 1.
// ---------------------------------------------------------------------------
// 0x6b4140 — observed shape
uint32_t FUN_006b4140(void* self, const uint32_t* param_1, const uint32_t* param_2,
                      uint32_t eax_in = 0)
{
    if (u32_at(self, 0x10) == 5) {
        u32_at(self, 0x58) = param_1[0];
        u32_at(self, 0x5c) = param_1[1];
        u32_at(self, 0x98) = param_2[0];
        uint32_t value = param_2[1];
        u32_at(self, 0x9c) = value;
        return (value & 0xffffff00u) | 1u;
    }
    return eax_in & 0xffffff00u;
}

// ---------------------------------------------------------------------------
// 0x6b4180 — stores three payload words and three side words under tag 6.
// ---------------------------------------------------------------------------
// 0x6b4180 — observed shape
uint32_t FUN_006b4180(void* self, const uint32_t* param_1, const uint32_t* param_2,
                      uint32_t eax_in = 0)
{
    if (u32_at(self, 0x10) == 6) {
        u32_at(self, 0x58) = param_1[0];
        u32_at(self, 0x5c) = param_1[1];
        u32_at(self, 0x60) = param_1[2];
        u32_at(self, 0x98) = param_2[0];
        u32_at(self, 0x9c) = param_2[1];
        uint32_t value = param_2[2];
        u32_at(self, 0xa0) = value;
        return (value & 0xffffff00u) | 1u;
    }
    return eax_in & 0xffffff00u;
}

// ---------------------------------------------------------------------------
// 0x6b41d0 — stores four payload words and four side words under tag 7.
// The listing spells the fourth payload offset as decimal 100 (0x64).
// ---------------------------------------------------------------------------
// 0x6b41d0 — observed shape
uint32_t FUN_006b41d0(void* self, const uint32_t* param_1, const uint32_t* param_2,
                      uint32_t eax_in = 0)
{
    if (u32_at(self, 0x10) == 7) {
        u32_at(self, 0x58) = param_1[0];
        u32_at(self, 0x5c) = param_1[1];
        u32_at(self, 0x60) = param_1[2];
        u32_at(self, 0x64) = param_1[3];   // corpus: offset 100
        u32_at(self, 0x98) = param_2[0];
        u32_at(self, 0x9c) = param_2[1];
        u32_at(self, 0xa0) = param_2[2];
        uint32_t value = param_2[3];
        u32_at(self, 0xa4) = value;
        return (value & 0xffffff00u) | 1u;
    }
    return eax_in & 0xffffff00u;
}

// ---------------------------------------------------------------------------
// 0x6b4230 — tag 10 with implicit homogeneous complement: only three payload
// words and three side words are copied, the fourth word of each group is
// the float constant 1.0f (0x3f800000).
// ---------------------------------------------------------------------------
// 0x6b4230 — observed shape
uint32_t FUN_006b4230(void* self, const uint32_t* param_1, const uint32_t* param_2,
                      uint32_t eax_in = 0)
{
    if (u32_at(self, 0x10) == 10) {
        u32_at(self, 0x58) = param_1[0];
        u32_at(self, 0x5c) = param_1[1];
        u32_at(self, 0x60) = param_1[2];
        u32_at(self, 0x64) = 0x3f800000u;   // corpus: offset 100
        u32_at(self, 0x98) = param_2[0];
        u32_at(self, 0x9c) = param_2[1];
        uint32_t value = param_2[2];
        u32_at(self, 0xa0) = value;
        u32_at(self, 0xa4) = 0x3f800000u;
        return (value & 0xffffff00u) | 1u;
    }
    return eax_in & 0xffffff00u;
}

// ---------------------------------------------------------------------------
// 0x6b4290 — tag 10, full four-word payload and four-word side copy (the
// homogeneous complement stored by 0x6b4230 when it pins the fourth word).
// ---------------------------------------------------------------------------
// 0x6b4290 — observed shape
uint32_t FUN_006b4290(void* self, const uint32_t* param_1, const uint32_t* param_2,
                      uint32_t eax_in = 0)
{
    if (u32_at(self, 0x10) == 10) {
        u32_at(self, 0x58) = param_1[0];
        u32_at(self, 0x5c) = param_1[1];
        u32_at(self, 0x60) = param_1[2];
        u32_at(self, 0x64) = param_1[3];   // corpus: offset 100
        u32_at(self, 0x98) = param_2[0];
        u32_at(self, 0x9c) = param_2[1];
        u32_at(self, 0xa0) = param_2[2];
        uint32_t value = param_2[3];
        u32_at(self, 0xa4) = value;
        return (value & 0xffffff00u) | 1u;
    }
    return eax_in & 0xffffff00u;
}

// ---------------------------------------------------------------------------
// 0x6b45c0 — writes the self+0x18 string, then, only when the flags byte has
// bit 0 set, the self+0x98 word. Short first write fails the whole check.
// ---------------------------------------------------------------------------
// 0x6b45c0 — observed shape
uint32_t FUN_006b45c0(void* self, void* param_1)
{
    if (!FUN_006b4f80(param_1, reinterpret_cast<const char*>(u32_at(self, 0x18)))) {
        return 0;
    }
    if (((u8_at(self, 0x14) & 1) == 0) ||
        FUN_006b4fe0(param_1, u32_at(self, 0x98))) {
        return 1;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6b4610 — the mirror of 0x6b45c0: word first, then the optional string and
// second word pair; a clear flags bit 0 short-circuits to success.
// ---------------------------------------------------------------------------
// 0x6b4610 — observed shape
uint32_t FUN_006b4610(void* self, void* param_1)
{
    if (FUN_006b4fe0(param_1, u32_at(self, 0x18))) {
        if ((u8_at(self, 0x14) & 1) == 0) {
            return 1;
        }
        if (FUN_006b4fe0(param_1, u32_at(self, 0x58)) &&
            FUN_006b4fe0(param_1, u32_at(self, 0x98))) {
            return 1;
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6b4800 — word at self+0x18, then the string at self+0xd8; both must
// succeed.
// ---------------------------------------------------------------------------
// 0x6b4800 — observed shape
bool FUN_006b4800(void* self, void* param_1)
{
    if (!FUN_006b4fe0(param_1, u32_at(self, 0x18))) {
        return false;
    }
    return FUN_006b4f80(param_1, reinterpret_cast<const char*>(u32_at(self, 0xd8)));
}

// ---------------------------------------------------------------------------
// 0x6b4870 — length-prefixed string read into self+0x18, then the
// self+0x98 word, gated by flags bit 0.
// ---------------------------------------------------------------------------
// 0x6b4870 — observed shape
uint32_t FUN_006b4870(void* self, void* param_1)
{
    if (!FUN_006b5020(param_1, &u32_at(self, 0x18))) {
        return 0;
    }
    if (((u8_at(self, 0x14) & 1) == 0) ||
        FUN_006b5090(param_1, &u32_at(self, 0x98))) {
        return 1;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6b48c0 — mirror of 0x6b4870: word at self+0x18 first, then the optional
// string at self+0x58 and word at self+0x98.
// ---------------------------------------------------------------------------
// 0x6b48c0 — observed shape
uint32_t FUN_006b48c0(void* self, void* param_1)
{
    if (FUN_006b5090(param_1, &u32_at(self, 0x18))) {
        if ((u8_at(self, 0x14) & 1) == 0) {
            return 1;
        }
        if (FUN_006b5090(param_1, &u32_at(self, 0x58)) &&
            FUN_006b5090(param_1, &u32_at(self, 0x98))) {
            return 1;
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6b4ab0 — word at self+0x18, then the length-prefixed string stored
// through self+0xd8; both must succeed.
// ---------------------------------------------------------------------------
// 0x6b4ab0 — observed shape
bool FUN_006b4ab0(void* self, void* param_1)
{
    if (!FUN_006b5090(param_1, &u32_at(self, 0x18))) {
        return false;
    }
    return FUN_006b5020(param_1, &u32_at(self, 0xd8));
}

// ---------------------------------------------------------------------------
// 0x6b4af0 — destroying delete: reinstates the base vtable, releases the
// tag-2 payload and the self+0xd8 allocation, runs the member teardown, and
// finally frees the object when the low delete-flag bit is set.
// ---------------------------------------------------------------------------
// 0x6b4af0 — observed shape
void FUN_006b4af0(void* self, uint8_t param_1)
{
    u32_at(self, 0x00) = reinterpret_cast<uint32_t>(&PTR_FUN_006f5380);
    if (u32_at(self, 0x10) == 2) {
        operator_delete__(reinterpret_cast<void*>(u32_at(self, 0x18)));
    }
    operator_delete__(reinterpret_cast<void*>(u32_at(self, 0xd8)));
    FUN_006b50f0(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// ---------------------------------------------------------------------------
// 0x6b4b40 — tag-8 exporter: nine words at 0x18/0x1c/0x20/0x28/0x2c/0x30/
// 0x38/0x3c/0x40 into param_1[0..8]. Note the gaps at 0x24 and 0x34.
// ---------------------------------------------------------------------------
// 0x6b4b40 — observed shape
uint32_t FUN_006b4b40(void* self, uint32_t* param_1)
{
    if (u32_at(self, 0x10) == 8) {
        param_1[0] = u32_at(self, 0x18);
        param_1[1] = u32_at(self, 0x1c);
        param_1[2] = u32_at(self, 0x20);
        param_1[3] = u32_at(self, 0x28);
        param_1[4] = u32_at(self, 0x2c);
        param_1[5] = u32_at(self, 0x30);
        param_1[6] = u32_at(self, 0x38);
        param_1[7] = u32_at(self, 0x3c);
        param_1[8] = u32_at(self, 0x40);
        return 1;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6b4b90 — tag-8 importer: same nine non-contiguous words, writing the tag
// word first.
// ---------------------------------------------------------------------------
// 0x6b4b90 — observed shape
void FUN_006b4b90(void* self, const uint32_t* param_1)
{
    u32_at(self, 0x10) = 8;
    u32_at(self, 0x18) = param_1[0];
    u32_at(self, 0x1c) = param_1[1];
    u32_at(self, 0x20) = param_1[2];
    u32_at(self, 0x28) = param_1[3];
    u32_at(self, 0x2c) = param_1[4];
    u32_at(self, 0x30) = param_1[5];
    u32_at(self, 0x38) = param_1[6];
    u32_at(self, 0x3c) = param_1[7];
    u32_at(self, 0x40) = param_1[8];
}

// ---------------------------------------------------------------------------
// 0x6b4be0 — variant copy-assignment.
//
// First the two scalar sub-objects are carried over through the virtual
// getter/setter pair on slots +0x4/+0xc and +0x8/+0x10, then the tag and the
// trailing word are copied, the self+0xd8 allocation is dropped, and the
// payload is rebuilt per tag (1..0xb).
//
// The corpus passes `auStack_52 + -10` as one of the two payload source
// blocks in cases 5, 6 and 10; that frame slot is never written in the
// listing (Ghidra aliases the two source copies onto overlapping stack
// temporaries). It is modeled as a zeroed scratch block so the observed call
// order and the two-block argument shape survive verbatim.
// ---------------------------------------------------------------------------
// 0x6b4be0 — observed shape
void FUN_006b4be0(int32_t* self, int32_t* param_1)
{
    int32_t aux_stack[3] = {};
    int32_t pair_block[2] = {};     // corpus: iStack_4c..iStack_48 (case 5)
    int32_t triple_block[3] = {};   // corpus: iStack_4c..iStack_44 (case 6)
    int32_t quad_head[4] = {};      // corpus: iStack_4c..iStack_40 (case 10)
    int32_t quad_side[4] = {};      // corpus: iStack_3c..iStack_30 (case 10)

    vtable_set(self, 0x0c, vtable_get(param_1, 0x04));
    vtable_set(self, 0x10, vtable_get(param_1, 0x08));

    self[4] = param_1[4];
    self[5] = param_1[5];
    operator_delete__(reinterpret_cast<void*>(self[0x36]));
    self[0x36] = 0;

    switch (self[4]) {
    case 1:
        u8_at(self, 0x18) = static_cast<uint8_t>(param_1[6]);
        self[4] = 1;
        return;
    case 2:
        FUN_006b3dd0(param_1[6]);
        FUN_006b40e0(param_1[0x16], param_1[0x26]);
        return;
    case 3: {
        int32_t value = param_1[6];
        self[4] = 3;
        self[6] = value;
        FUN_006b40e0(param_1[0x16], param_1[0x26]);
        return;
    }
    case 4: {
        int32_t value = param_1[6];
        self[4] = 4;
        self[6] = value;
        FUN_006b4110(self, static_cast<uint32_t>(param_1[0x16]),
                     static_cast<uint32_t>(param_1[0x26]));
        return;
    }
    case 5: {
        int32_t value6 = param_1[6];
        int32_t value7 = param_1[7];
        self[4] = 5;
        self[6] = value6;
        self[7] = value7;
        pair_block[1] = param_1[0x17];
        pair_block[0] = param_1[0x16];
        FUN_006b4140(self, reinterpret_cast<const uint32_t*>(pair_block),
                     reinterpret_cast<const uint32_t*>(aux_stack));
        return;
    }
    case 6: {
        int32_t value6 = param_1[6];
        int32_t value7 = param_1[7];
        int32_t value8 = param_1[8];
        self[4] = 6;
        self[6] = value6;
        self[8] = value8;
        self[7] = value7;
        triple_block[0] = param_1[0x26];
        triple_block[1] = param_1[0x27];
        triple_block[2] = param_1[0x28];
        FUN_006b4180(self, reinterpret_cast<const uint32_t*>(aux_stack),
                     reinterpret_cast<const uint32_t*>(triple_block));
        return;
    }
    case 7:
        FUN_006b3f10(param_1 + 6);
        FUN_006b41d0(self, reinterpret_cast<const uint32_t*>(param_1 + 0x16),
                     reinterpret_cast<const uint32_t*>(param_1 + 0x26));
        return;
    case 8: {
        int32_t block[9];
        block[0] = param_1[6];
        block[1] = param_1[7];
        block[2] = param_1[8];
        block[3] = param_1[10];
        block[6] = param_1[0xe];
        block[4] = param_1[0xb];
        block[5] = param_1[0xc];
        block[7] = param_1[0xf];
        block[8] = param_1[0x10];
        FUN_006b4b90(self, reinterpret_cast<const uint32_t*>(block));
        return;
    }
    case 9: {
        self[4] = 9;
        int32_t* src = param_1 + 6;
        int32_t* dst = self + 6;
        for (int32_t i = 0x10; i != 0; --i) {
            *dst = *src;
            ++src;
            ++dst;
        }
        return;
    }
    case 10: {
        quad_head[0] = param_1[6];
        quad_head[2] = param_1[8];
        quad_head[1] = param_1[7];
        quad_head[3] = param_1[9];
        quad_side[1] = param_1[0x17];
        quad_side[2] = param_1[0x18];
        quad_side[0] = param_1[0x16];
        quad_side[3] = param_1[0x19];
        FUN_006b3f90(quad_head);
        FUN_006b4290(self, reinterpret_cast<const uint32_t*>(quad_side),
                     reinterpret_cast<const uint32_t*>(aux_stack));
        return;
    }
    case 0xb:
        FUN_006b3fc0(param_1[6], param_1[0x36]);
        break;
    default:
        break;
    }
}

// ---------------------------------------------------------------------------
// 0x6b4f10 — replaces the owned string at self+0x0c with a heap copy of
// param_1. An empty or null argument leaves the slot null. The allocation
// size is the measured length plus one, mirroring
// `ptr + (1 - (start + 1))`.
// ---------------------------------------------------------------------------
// 0x6b4f10 — observed shape
void FUN_006b4f10(void* self, char* param_1)
{
    operator_delete__(str_at(self, 0x0c));
    str_at(self, 0x0c) = nullptr;
    if (param_1 != nullptr) {
        // The corpus compares exactly one byte against the empty string.
        bool differs = (*param_1 != '\0');
        if (differs) {
            std::size_t length = text_length(param_1);
            char* copy = static_cast<char*>(
                thunk_FUN_00533c78(static_cast<uint32_t>(length + 1)));
            str_at(self, 0x0c) = copy;
            char c;
            do {
                c = *param_1;
                param_1 = param_1 + 1;
                *copy = c;
                copy = copy + 1;
            } while (c != '\0');
        }
    }
}

// ---------------------------------------------------------------------------
// 0x6b4f80 — length-prefixed string write: a 4-byte length word followed by
// the bytes. A short length write fails; a zero length succeeds outright.
//
// The corpus consumes the measured length twice through `unaff_retaddr` and
// `unaff_EDI` (a stack copy and a callee-saved-register copy of the same
// value, kept alive across the virtual call). Both are folded back onto the
// measured length here.
// ---------------------------------------------------------------------------
// 0x6b4f80 — observed shape
bool FUN_006b4f80(void* obj, const char* text)
{
    int32_t length = 0;
    if (text != nullptr) {
        length = static_cast<int32_t>(text_length(text));
    }
    if (stream_write(obj, &length, 4) != 4) {
        return false;
    }
    if (length == 0) {
        return true;
    }
    if (stream_write(obj, const_cast<char*>(text), length) != length) {
        return false;
    }
    return true;
}

// ---------------------------------------------------------------------------
// 0x6b4fe0 — value write: the listing takes a one-byte parameter but writes
// four bytes starting at its stack slot, so the slot is modeled as the full
// 32-bit word the call sites pass.
// ---------------------------------------------------------------------------
// 0x6b4fe0 — observed shape
bool FUN_006b4fe0(void* obj, uint32_t value)
{
    uint32_t slot = value;
    int32_t written = stream_write(obj, &slot, 4);
    return written == 4;
}

// ---------------------------------------------------------------------------
// 0x6b5000 — word-array write: count * 4 bytes from buffer, success only on
// a full transfer.
// ---------------------------------------------------------------------------
// 0x6b5000 — observed shape
bool FUN_006b5000(void* obj, void* buffer, int32_t count)
{
    int32_t bytes = count * 4;
    int32_t written = stream_write(obj, buffer, bytes);
    return written == bytes;
}
