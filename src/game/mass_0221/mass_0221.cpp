//
// mass_0221.cpp — reconstruction batch mass_0221
// Target: Sid Meier's Pirates! (2004), PE32 i386
//
// Each definition preserves the observed field offsets, constants, call
// order, return shape, and conditional structure of the Ghidra 12.2
// pseudocode in analysis/pseudocode/functions/*.c.
//
// This family is the Direct3D 9 vertex/stream upload helpers plus a
// hash-table-backed resource container: the container allocates three
// 0x94-byte buckets (0x25 entries each) at self+0x14/0x24/0x34 and chains
// its destructor through the three sub-object vtable groups at
// self+0x0c/0x1c/0x2c. Register receivers (in_ECX) are modeled as an
// explicit `void* self` first parameter.
//
#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <windows.h>

namespace mass_0221_candidate {

// ---------------------------------------------------------------------------
// External helpers and globals referenced by the assigned listings only.
// ---------------------------------------------------------------------------
extern uint32_t DAT_00717c64;
extern uint32_t DAT_00727444;
extern uint32_t DAT_00727994;
extern uint32_t DAT_00728e88;

extern uint32_t PTR_LAB_006c7dcc;
extern uint32_t PTR_LAB_006fd148;
extern uint32_t PTR_FUN_006c7df4;
extern uint32_t PTR_FUN_006c7e10;
extern uint32_t PTR_FUN_006c7e68;
extern uint32_t PTR_FUN_006c7e70;

void        FUN_00497420(const char* format, ...);
uint32_t    FUN_0054aad0(void);
void        FUN_00513dc0(void);
uint32_t    FUN_005bfb30(uint32_t param_1);
uint32_t    FUN_005bfb50(void* param_1);
void        FUN_005d8430(void);
void        FUN_005e1490(void);
const char* FUN_005d8450(int32_t code);
void*       FUN_005412c0(uint32_t index = 0);
void        FUN_005542d0(uint32_t p1, uint32_t p2, int16_t p3, uint32_t p4,
                         uint32_t p5, uint32_t p6, uint32_t p7, uint32_t p8);
void        FUN_00552c80(void* self);
void        FUN_00552d20(void);
void        FUN_005aead0(int32_t* cursor, void* out_a, void** out_b);
void*       thunk_FUN_00533c78(uint32_t size);

void operator_delete(void* ptr);
void operator_delete__(void* ptr);

// ---------------------------------------------------------------------------
// Offset accessors: every observed field access goes through these so the
// original byte offsets stay visible in each definition.
// ---------------------------------------------------------------------------
static inline uint32_t& u32_at(void* base, std::size_t off)
{
    return *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(base) + off);
}

static inline int32_t& i32_at(void* base, std::size_t off)
{
    return *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(base) + off);
}

static inline uint16_t& u16_at(void* base, std::size_t off)
{
    return *reinterpret_cast<uint16_t*>(static_cast<uint8_t*>(base) + off);
}

static inline int16_t& i16_at(void* base, std::size_t off)
{
    return *reinterpret_cast<int16_t*>(static_cast<uint8_t*>(base) + off);
}

static inline uint8_t& u8_at(void* base, std::size_t off)
{
    return *reinterpret_cast<uint8_t*>(static_cast<uint8_t*>(base) + off);
}

static inline float& f32_at(void* base, std::size_t off)
{
    return *reinterpret_cast<float*>(static_cast<uint8_t*>(base) + off);
}

static inline void*& ptr_at(void* base, std::size_t off)
{
    return *reinterpret_cast<void**>(static_cast<uint8_t*>(base) + off);
}

// `**(int **)(base + off) = value`: the word at `off` holds a pointer and the
// listing stores through that pointer.
static inline void store_through_i32(void* base, std::size_t off, int32_t value)
{
    *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(u32_at(base, off))) = value;
}

// `**(int **)(base + off)`: load the int the word at `off` points at.
static inline int32_t load_through_i32(void* base, std::size_t off)
{
    return *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(u32_at(base, off)));
}

// ---------------------------------------------------------------------------
// Virtual-call shape: the receiver's vtable is loaded from its first word and
// the member is invoked through a byte offset. The listings spell the receiver
// explicitly for most slots; where a listing shows `(...)()` with no argument
// list the receiver is still passed in ECX and is called without it here.
// ---------------------------------------------------------------------------
static inline void* vfn(void* obj, std::size_t slot_byte)
{
    return (*reinterpret_cast<void***>(obj))[slot_byte / 4];
}

// Ghidra's ROUND(): float-to-int conversion; the observed uses are the colour
// packers (component * 255.0), where the truncating lowering is reproduced.
static inline int32_t ROUND(double value)
{
    return static_cast<int32_t>(value);
}

static inline float ABS(float value)
{
    return (value < 0.0f) ? -value : value;
}

// ---------------------------------------------------------------------------
// 0x5ccdd0 — container constructor: installs the label vtable, runs the base
// constructor, then clears the twelve words at self+0x30..self+0x48.
// ---------------------------------------------------------------------------
// 0x5ccdd0 — observed shape
void FUN_005ccdd0(void* self, uint32_t param_1, uint32_t param_2)
{
    u32_at(self, 0x04) = param_1;
    ptr_at(self, 0x00) = &PTR_LAB_006c7dcc;
    FUN_00513dc0();
    u32_at(self, 0x30) = 0;   // in_ECX[0xc]
    u32_at(self, 0x34) = 0;   // in_ECX[0xd]
    u32_at(self, 0x40) = 0;   // in_ECX[0x10]
    u32_at(self, 0x44) = 0;   // in_ECX[0x11]
    u32_at(self, 0x48) = 0;   // in_ECX[0x12]
    u32_at(self, 0x38) = 0;   // in_ECX[0xe]
    u32_at(self, 0x3c) = 0;   // in_ECX[0xf]
    u32_at(self, 0x08) = param_2;
}

// ---------------------------------------------------------------------------
// 0x5cce60 — ordered candidate probe over the three descriptor arrays.
// `param_1[0]` is a format tag, `param_2[0]` a stream class, `param_2[2]` a
// sub-variant flag and `param_3[0..0xd]` the candidate slots. The helper at
// vtable +0xc answers whether a candidate is acceptable.
// ---------------------------------------------------------------------------
static inline uint8_t call_5cce60(void* obj, int32_t* param_1, int32_t candidate)
{
    return reinterpret_cast<uint8_t(__cdecl*)(int32_t*, int32_t)>(vfn(obj, 0x0c))(param_1, candidate);
}

static inline int32_t check_5cce60(void* obj, int32_t* param_1, int32_t candidate)
{
    if (candidate == 0) {
        return 0;
    }
    return call_5cce60(obj, param_1, candidate) ? candidate : 0;
}

// 0x5cce60 — observed shape
int32_t FUN_005cce60(int32_t* param_1, int32_t* param_2, int32_t* param_3)
{
    int32_t iVar4 = *param_1;
    void* piVar3 = reinterpret_cast<void*>(static_cast<uintptr_t>(FUN_0054aad0()));
    if (param_1[1] != 0) {
        return 0;
    }

    const int32_t iVar1 = *param_2;

    if (iVar1 == 4) {
        if (iVar4 != 9 && iVar4 != 1) {
            iVar4 = param_3[0xb];
            if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
                return iVar4;
            }
            iVar4 = param_3[0xd];
            if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
                return iVar4;
            }
            return check_5cce60(piVar3, param_1, param_3[0xc]);   // LAB_005ccec5
        }
        iVar4 = param_3[0xd];
        if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
            return iVar4;
        }
        iVar4 = param_3[0xc];
        if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
            return iVar4;
        }
        return check_5cce60(piVar3, param_1, param_3[0xb]);       // LAB_005ccef9
    }

    switch (iVar4) {
    case 0:
    case 2:
        if (iVar1 == 3) {
            iVar4 = param_3[8];
            if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
                return iVar4;
            }
            iVar4 = param_3[9];
            if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
                return iVar4;
            }
            iVar4 = param_3[10];
            if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
                return iVar4;
            }
        }
        if (*param_2 == 1) {
            iVar4 = param_3[1];
            if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
                return iVar4;
            }
            iVar4 = *param_3;
            if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
                return iVar4;
            }
            iVar4 = param_3[2];
            if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
                return iVar4;
            }
            iVar4 = param_3[5];
        }
        else {
            iVar4 = param_3[2];
            if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
                return iVar4;
            }
            iVar4 = param_3[5];
            if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
                return iVar4;
            }
            iVar4 = param_3[1];
            if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
                return iVar4;
            }
            iVar4 = *param_3;
        }
        if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
            return iVar4;
        }
        iVar4 = param_3[3];                                       // LAB_005cd1c5
        if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
            return iVar4;
        }
        return check_5cce60(piVar3, param_1, param_3[4]);         // LAB_005ccefc
    case 1:
    case 3:
        break;
    case 4:
        if (iVar1 != 1 && iVar1 != 2) {
            iVar4 = param_3[8];                                   // LAB_005cd067
            if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
                return iVar4;
            }
        }
        break;
    case 5:
        if (iVar1 != 1 && iVar1 != 2) {
            iVar4 = param_3[9];
            if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
                return iVar4;
            }
        }
        break;
    case 6:
        if (iVar1 != 1 && iVar1 != 2) {
            iVar4 = param_3[10];                                  // LAB_005cd067
            if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
                return iVar4;
            }
        }
        break;
    case 8:
        iVar4 = param_3[0xb];
        if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
            return iVar4;
        }
        iVar4 = param_3[0xd];
        if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
            return iVar4;
        }
        return check_5cce60(piVar3, param_1, param_3[0xc]);       // LAB_005ccec5
    case 9:
        iVar4 = param_3[0xc];
        if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
            return iVar4;
        }
        iVar4 = param_3[0xd];
        if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
            return iVar4;
        }
        return check_5cce60(piVar3, param_1, param_3[0xb]);       // LAB_005ccef9
    default:
        return 0;
    }

    if (*param_2 == 3) {
        if (param_2[2] == 1) {
            iVar4 = param_3[8];
            if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
                return iVar4;
            }
            iVar4 = param_3[9];
            if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
                return iVar4;
            }
            iVar4 = param_3[10];
            if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
                return iVar4;
            }
        }
        else {
            iVar4 = param_3[9];
            if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
                return iVar4;
            }
            iVar4 = param_3[10];
            if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
                return iVar4;
            }
            iVar4 = param_3[8];
            if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
                return iVar4;
            }
        }
    }

    if (*param_2 == 1) {
        if (param_2[2] == 1) {
            iVar4 = param_3[3];
            if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
                return iVar4;
            }
            iVar4 = param_3[4];
            if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
                return iVar4;
            }
            return check_5cce60(piVar3, param_1, param_3[5]);     // LAB_005cd168
        }
        iVar4 = param_3[4];
        if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
            return iVar4;
        }
        iVar4 = param_3[5];
    }
    else {
        iVar4 = param_3[5];
        if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
            return iVar4;
        }
        if (param_2[2] == 1) {
            iVar4 = param_3[3];                                   // LAB_005cd1c5
            if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
                return iVar4;
            }
            return check_5cce60(piVar3, param_1, param_3[4]);     // LAB_005ccefc
        }
        iVar4 = param_3[4];
    }

    if (iVar4 != 0 && call_5cce60(piVar3, param_1, iVar4) != 0) {
        return iVar4;
    }
    return check_5cce60(piVar3, param_1, param_3[3]);             // LAB_005ccefc
}

// ---------------------------------------------------------------------------
// 0x5cd2c0 — walks the list head DAT_00727994 through the next pointer at
// +0x34 and releases each attached object (word at +0x2c) through its first
// vtable slot with argument 1.
// ---------------------------------------------------------------------------
// 0x5cd2c0 — observed shape
void FUN_005cd2c0(void)
{
    for (uint32_t item = DAT_00727994; item != 0; item = u32_at(reinterpret_cast<void*>(static_cast<uintptr_t>(item)), 0x34)) {
        uint32_t* puVar1 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(u32_at(reinterpret_cast<void*>(static_cast<uintptr_t>(item)), 0x2c)));
        if (puVar1 != nullptr) {
            u32_at(reinterpret_cast<void*>(static_cast<uintptr_t>(item)), 0x2c) = 0;
            void** vtbl = *reinterpret_cast<void***>(puVar1);
            reinterpret_cast<void(__cdecl*)(uint32_t)>(vtbl[0])(1u);
        }
    }
}

// ---------------------------------------------------------------------------
// 0x5cd310 — forwards a lock request to vtable +0x2c and keeps the receiver
// only when the call did not report a negative result. The listing returns the
// receiver word itself (the scratch out-slot local_4 is left unread).
// ---------------------------------------------------------------------------
// 0x5cd310 — observed shape
uint32_t FUN_005cd310(int32_t* param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    uint32_t local_4 = 0;
    int32_t iVar1 = reinterpret_cast<int32_t(__cdecl*)(int32_t*, uint32_t, uint32_t, uint32_t*, uint32_t)>(vfn(param_1, 0x2c))(param_1, param_2, param_3, &local_4, param_4);
    const uint32_t mask = static_cast<uint32_t>((iVar1 < 0) - 1);
    return static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_1)) & mask;
}

// ---------------------------------------------------------------------------
// 0x5cd350 — strided row copy: `param_5` rows of `param_4` bytes, source rows
// packed, destination rows `param_3` bytes apart.
// ---------------------------------------------------------------------------
// 0x5cd350 — observed shape
void FUN_005cd350(void* param_1, void* param_2, int32_t param_3, uint32_t param_4, int32_t param_5)
{
    if (param_5 != 0) {
        do {
            uint8_t* puVar2 = static_cast<uint8_t*>(param_2);
            uint8_t* puVar3 = static_cast<uint8_t*>(param_1);
            for (uint32_t uVar1 = param_4 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
                *reinterpret_cast<uint32_t*>(puVar3) = *reinterpret_cast<uint32_t*>(puVar2);
                puVar2 += 4;
                puVar3 += 4;
            }
            for (uint32_t uVar1 = param_4 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
                *puVar3 = *puVar2;
                puVar2 += 1;
                puVar3 += 1;
            }
            param_1 = static_cast<uint8_t*>(param_1) + param_3;
            param_2 = static_cast<uint8_t*>(param_2) + param_4;
            param_5 = param_5 - 1;
        } while (param_5 != 0);
    }
}

// ---------------------------------------------------------------------------
// 0x5cd3a0 — success predicate over vtable +0x30.
// ---------------------------------------------------------------------------
// 0x5cd3a0 — observed shape
bool FUN_005cd3a0(int32_t* param_1)
{
    int32_t iVar1 = reinterpret_cast<int32_t(__cdecl*)(int32_t*)>(vfn(param_1, 0x30))(param_1);
    return -1 < iVar1;
}

// ---------------------------------------------------------------------------
// 0x5cd450 — prepare slot `param_2` of the buffer object at param_1+4: the
// vtable +0x24 member is always called, then +0x20 fetches the slot. The
// result is recorded in the word array at [param_1+0x1c] when the index is
// inside the capacity at [param_1+0x14].
// ---------------------------------------------------------------------------
// 0x5cd450 — observed shape
uint32_t FUN_005cd450(void* param_1, uint32_t param_2)
{
    int32_t* piVar1 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(u32_at(param_1, 0x04)));
    reinterpret_cast<void(__cdecl*)(void*, uint32_t)>(vfn(piVar1, 0x24))(param_1, param_2);
    int32_t iVar2 = reinterpret_cast<int32_t(__cdecl*)(void*, uint32_t)>(vfn(piVar1, 0x20))(param_1, param_2);
    if (iVar2 == 0) {
        return 0;
    }
    if (param_2 < u32_at(param_1, 0x14)) {
        *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(u32_at(param_1, 0x1c)) + param_2 * 4) = iVar2;
    }
    return 1;
}

// ---------------------------------------------------------------------------
// 0x5cd490 — vertex-layout planner. Computes the stream flags for the vertex
// count in `param_2` and hands back the byte offsets of every stream: base
// offset in *param_4, positions in *param_6, normals in *param_7, colours in
// *param_8, texture coordinates in *param_9. The flag word in *param_3
// receives bit 1 (no weights), 10 (weights), 0x10 (normals), 0x40 (colours)
// and the coordinate-set count shifted by 8 (capped by DAT_00717c64).
// ---------------------------------------------------------------------------
// 0x5cd490 — observed shape
void FUN_005cd490(void* param_1, void* param_2, uint32_t* param_3, int32_t* param_4,
                  uint32_t* param_5, int32_t* param_6, int32_t* param_7,
                  int32_t* param_8, int32_t* param_9)
{
    int16_t sVar2 = 0;

    *param_3 = 0;
    *param_4 = 0;
    if (param_2 != nullptr) {
        sVar2 = i16_at(param_2, 0x20);
    }
    *param_5 = 0;
    int32_t iVar1 = *param_4;
    *param_4 = iVar1 + 0xc;
    *param_6 = iVar1 + 0xc;
    if (sVar2 == 0) {
        *param_3 = *param_3 | 2;
    }
    else {
        *param_3 = 10;
        *param_4 = *param_4 + 0xc;
    }
    if (i32_at(param_1, 0x24) != 0) {
        *param_3 = *param_3 | 0x10;
        *param_7 = *param_4;
        *param_4 = *param_4 + 0xc;
    }
    if (i32_at(param_1, 0x28) != 0) {
        *param_3 = *param_3 | 0x40;
        *param_8 = *param_4;
        *param_4 = *param_4 + 4;
    }
    uint32_t uVar3 = u8_at(param_1, 0x30) & 0x3f;
    if ((u8_at(param_1, 0x30) & 0x3f) == 0) {
        uVar3 = 1;
    }
    else {
        if (DAT_00717c64 < uVar3) {
            uVar3 = DAT_00717c64;
        }
        if (uVar3 == 0) {
            return;
        }
    }
    *param_3 = *param_3 | uVar3 << 8;
    *param_9 = *param_4;
    *param_4 = *param_4 + uVar3 * 8;
}

// ---------------------------------------------------------------------------
// 0x5cd550 — positional-only stream upload. Plans the layout with 0x5cd490,
// optionally re-plans when the destination surface does not match, then fills
// the position stream (and, when the source supplies them, the colour stream
// and the blend-weight stream) before unlocking.
// ---------------------------------------------------------------------------
// 0x5cd550 — observed shape
int32_t FUN_005cd550(int32_t* param_1, float param_2, uint32_t param_3, void* param_4, uint32_t param_5)
{
    int32_t* piVar2 = param_1;
    uint32_t uStack_40 = reinterpret_cast<uint32_t(__cdecl*)(void)>(vfn(param_1, 0x38))();
    if (static_cast<uint16_t>(uStack_40) == 0) {
        return 0;
    }
    uint32_t uStack_24 = static_cast<uint32_t>(piVar2[8]);      // +0x20 positions
    uint32_t uStack_2c = static_cast<uint32_t>(piVar2[9]);      // +0x24 blend weights
    float* pfVar9 = reinterpret_cast<float*>(static_cast<uintptr_t>(static_cast<uint32_t>(piVar2[10])));  // +0x28 colours
    uint32_t uStack_34 = u8_at(piVar2, 0x30) & 0x3f;
    if (uStack_34 > 8) {
        uStack_34 = 8;
    }
    int32_t iStack_38 = 0;
    int32_t iStack_44 = 0;
    uint32_t iStack_30 = 0;
    uint32_t uStack_28 = 0;
    uint32_t iStack_20 = 0;
    uint32_t iStack_1c = 0;
    // The listing passes the address of its own first parameter as the
    // positions out-slot; preserved literally.
    FUN_005cd490(piVar2, nullptr, reinterpret_cast<uint32_t*>(&iStack_38), &iStack_44,
                 &iStack_30, reinterpret_cast<int32_t*>(&param_1),
                 reinterpret_cast<int32_t*>(&uStack_28),
                 reinterpret_cast<int32_t*>(&iStack_20),
                 reinterpret_cast<int32_t*>(&iStack_1c));

    void* orig_param_4 = param_4;
    void* desc = reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(piVar2[0xe])));
    u32_at(desc, 0x08) = static_cast<uint32_t>(iStack_38);
    u32_at(desc, 0x0c) = 0;
    if (i32_at(desc, 0x14) != 0) {
        store_through_i32(desc, 0x18, iStack_44);
    }

    // Corpus: CONCAT31(param_1._1_3_, 1) — only the low byte of the receiver
    // word is replaced; the other three bytes survive.
    uint32_t state = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_1) & 0xffffff00u) | 1u;
    uint32_t uVar8;

    if (param_5 == 0) {
        bool needs_alloc;
        int32_t aiStack_18[4] = { 0, 0, 0, 0 };
        uint32_t uStack_8 = 0;
        uint32_t iStack_4 = 0;
        if (param_4 == nullptr) {
            needs_alloc = true;
        }
        else {
            int32_t* piVar1 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(u32_at(param_4, 0x08)));
            if (piVar1 == nullptr) {
                needs_alloc = true;
            }
            else if ((u16_at(piVar2, 0x32) & 0xf000) == 0x8000) {
                needs_alloc = true;
            }
            else {
                reinterpret_cast<void(__cdecl*)(int32_t*, int32_t*)>(vfn(piVar1, 0x34))(piVar1, aiStack_18);
                needs_alloc = (aiStack_18[0] != 100) ||
                              (iStack_4 != static_cast<uint32_t>(iStack_38)) ||
                              (uStack_8 < (uStack_40 & 0xffffu) * static_cast<uint32_t>(iStack_44));
            }
        }
        if (needs_alloc) {
            uint8_t cVar3 = static_cast<uint8_t>(FUN_005cd450(desc, 0));
            if (cVar3 == 0) {
                return 0;
            }
            if (i32_at(desc, 0x14) == 0) {
                param_4 = nullptr;
            }
            else {
                param_4 = reinterpret_cast<void*>(static_cast<uintptr_t>(
                    static_cast<uint32_t>(load_through_i32(desc, 0x1c))));
            }
            param_3 = 0xfff;
        }
        else {
            param_4 = orig_param_4;
        }
        param_5 = 0;
        int32_t iVar4 = reinterpret_cast<int32_t(__cdecl*)(void*, uint32_t, uint32_t, uint32_t*, uint32_t)>(vfn(reinterpret_cast<void*>(static_cast<uintptr_t>(u32_at(param_4, 0x08))), 0x2c))(
            reinterpret_cast<void*>(static_cast<uintptr_t>(u32_at(param_4, 0x08))),
            u32_at(param_4, 0x0c), u32_at(param_4, 0x14), &param_5, u32_at(param_4, 0x10));
        uVar8 = static_cast<uint32_t>((iVar4 < 0) - 1) & param_5;
    }
    else {
        // Corpus: (uint)param_1._1_3_ << 8.
        state = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_1) & 0xffffff00u);
        uVar8 = param_5;
    }

    if (param_2 == 0.0f) {
        if ((param_3 & 1) != 0) {
            FUN_005cd350(reinterpret_cast<void*>(static_cast<uintptr_t>(iStack_30 + uVar8)),
                         reinterpret_cast<void*>(static_cast<uintptr_t>(uStack_24)),
                         iStack_44, 0xc, static_cast<int32_t>(uStack_40 & 0xffffu));
        }
        if ((uStack_2c != 0) && ((param_3 & 2) != 0)) {
            FUN_005cd350(reinterpret_cast<void*>(static_cast<uintptr_t>(uStack_28 + uVar8)),
                         reinterpret_cast<void*>(static_cast<uintptr_t>(uStack_2c)),
                         iStack_44, 0xc, static_cast<int32_t>(uStack_40 & 0xffffu));
        }
    }
    else if ((param_3 & 1) != 0) {
        int32_t iVar4 = 0;
        if (uStack_2c != 0) {
            iVar4 = static_cast<int32_t>(uStack_28 + uVar8);
        }
        FUN_005542d0(static_cast<uint32_t>(piVar2[8]), static_cast<uint32_t>(piVar2[9]),
                     static_cast<int16_t>(piVar2[3]),
                     iStack_30 + uVar8, static_cast<uint32_t>(iVar4),
                     0, 0, static_cast<uint32_t>(iStack_44));
    }
    if ((pfVar9 != nullptr) && ((param_3 & 4) != 0)) {
        uint32_t* puVar5 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(iStack_20 + uVar8));
        for (uint32_t uVar7 = uStack_40 & 0xffffu; uVar7 != 0; uVar7 = uVar7 - 1) {
            iStack_20 = static_cast<uint32_t>(ROUND(pfVar9[3] * 255.0));
            uStack_24 = static_cast<uint32_t>(ROUND(*pfVar9 * 255.0));
            uStack_28 = static_cast<uint32_t>(ROUND(pfVar9[1] * 255.0));
            param_2 = pfVar9[2] * 255.0f;
            uStack_2c = static_cast<uint32_t>(ROUND(param_2));
            *puVar5 = ((static_cast<uint32_t>(iStack_20) << 8 | uStack_24) << 8 | uStack_28) << 8 | uStack_2c;
            puVar5 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar5) + iStack_44);
            pfVar9 = pfVar9 + 4;
        }
    }
    if (((param_3 & 8) != 0) && uStack_34 != 0) {
        uint32_t uVar7 = 0;
        uint32_t uVar10 = uStack_40 & 0xffffu;
        int32_t iVar4 = static_cast<int32_t>(uVar8 + iStack_1c);
        do {
            uint32_t uVar12 = 8;
            int32_t iVar11 = iStack_44;
            uint32_t uVar6 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(FUN_005412c0(uVar7)));
            FUN_005cd350(reinterpret_cast<void*>(static_cast<uintptr_t>(iVar4)),
                         reinterpret_cast<void*>(static_cast<uintptr_t>(uVar6)),
                         iVar11, uVar12, static_cast<int32_t>(uVar10));
            uVar7 = uVar7 + 1;
            iVar4 = iVar4 + 8;
        } while (uVar7 < uStack_34);
    }
    // The listing short-circuits: the unlock member is only reached when the
    // low byte of the receiver word is non-zero.
    if ((state & 0xffu) == 0) {
        return static_cast<int32_t>(reinterpret_cast<uintptr_t>(param_4));
    }
    int32_t lock_rc = reinterpret_cast<int32_t(__cdecl*)(void)>(
        vfn(reinterpret_cast<void*>(static_cast<uintptr_t>(u32_at(param_4, 0x08))), 0x30))();
    if (-1 < lock_rc) {
        return static_cast<int32_t>(reinterpret_cast<uintptr_t>(param_4));
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x5cd8b0 — builds a vertex stream with positions, optional colours and
// optional texture coordinates. Stride is 0x10 with texture coordinates and
// 0x14 with colours; the flags word is 4 | 0x40 (colours) | 0x100 (texcoords).
// ---------------------------------------------------------------------------
// 0x5cd8b0 — observed shape
int32_t FUN_005cd8b0(void* param_1, uint16_t param_2, uint32_t* param_3, float* param_4,
                     uint32_t* param_5, uint8_t param_6, void* param_7, int32_t param_8)
{
    float* pfVar9 = param_4;
    if ((param_2 == 0) || (param_3 == nullptr)) {
        return 0;
    }
    uint32_t local_24 = 4;
    int32_t iVar7 = 0x10;
    // The corpus reuses the texture-coordinate parameter slot for the byte
    // offset of the colour stream; kept as a separate offset here.
    uintptr_t uv_off = 0;
    if (param_4 != nullptr) {
        uv_off = 0x10;
        local_24 = 0x44;
        iVar7 = 0x14;
    }
    int32_t iVar8 = iVar7;
    int32_t local_1c = 0;
    if (param_5 != nullptr) {
        local_24 = local_24 | 0x100;
        iVar8 = iVar7 + 8;
        local_1c = iVar7;
    }
    u32_at(param_1, 0x08) = local_24;
    u32_at(param_1, 0x0c) = 0;
    if (i32_at(param_1, 0x14) != 0) {
        store_through_i32(param_1, 0x18, iVar8);
    }
    bool bVar2 = true;
    if (param_8 == 0) {
        bool needs_alloc;
        int32_t local_18[4] = { 0, 0, 0, 0 };
        uint32_t uStack_8 = 0;
        uint32_t uStack_4 = 0;
        if (param_7 == nullptr) {
            needs_alloc = true;
        }
        else {
            int32_t* piVar1 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(u32_at(param_7, 0x08)));
            if (piVar1 == nullptr) {
                needs_alloc = true;
            }
            else {
                reinterpret_cast<void(__cdecl*)(int32_t*, int32_t*)>(vfn(piVar1, 0x34))(piVar1, local_18);
                needs_alloc = (local_18[0] != 100) ||
                              (uStack_4 != local_24) ||
                              (uStack_8 < static_cast<uint32_t>(param_2) * static_cast<uint32_t>(iVar8));
            }
        }
        if (needs_alloc) {
            uint8_t cVar3 = static_cast<uint8_t>(FUN_005cd450(param_1, 0));
            if (cVar3 == 0) {
                return 0;
            }
            param_7 = reinterpret_cast<void*>(static_cast<uintptr_t>(FUN_005bfb30(0)));
        }
        param_8 = static_cast<int32_t>(FUN_005cd310(
            reinterpret_cast<int32_t*>(static_cast<uintptr_t>(u32_at(param_7, 0x08))),
            u32_at(param_7, 0x0c), u32_at(param_7, 0x14), u32_at(param_7, 0x10)));
    }
    else {
        bVar2 = false;
    }
    if (((param_6 & 1) != 0) && (param_2 != 0)) {
        uint32_t* puVar4 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(param_8) + 0x0c));
        uint32_t uVar6 = param_2;
        do {
            puVar4[-3] = param_3[0];
            puVar4[-2] = param_3[1];
            puVar4[-1] = 0;
            *puVar4 = 0x3f800000;
            puVar4 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar4) + iVar8);
            param_3 = param_3 + 2;
            uVar6 = uVar6 - 1;
        } while (uVar6 != 0);
    }
    if (((pfVar9 != nullptr) && ((param_6 & 4) != 0)) && (param_2 != 0)) {
        uint32_t* puVar5 = reinterpret_cast<uint32_t*>(uv_off + static_cast<uint32_t>(param_8));
        uint32_t uVar6 = param_2;
        do {
            *puVar5 = (((static_cast<uint32_t>(ROUND(pfVar9[3] * 255.0)) << 8) |
                        static_cast<uint32_t>(ROUND(*pfVar9 * 255.0))) << 8 |
                       static_cast<uint32_t>(ROUND(pfVar9[1] * 255.0))) << 8 |
                      static_cast<uint32_t>(ROUND(pfVar9[2] * 255.0));
            puVar5 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar5) + iVar8);
            pfVar9 = pfVar9 + 4;
            uVar6 = uVar6 - 1;
        } while (uVar6 != 0);
    }
    if (((param_5 != nullptr) && ((param_6 & 2) != 0)) && (param_2 != 0)) {
        uint32_t* puVar4 = reinterpret_cast<uint32_t*>(static_cast<uint32_t>(param_8) + local_1c);
        uint32_t uVar6 = param_2;
        do {
            puVar4[0] = param_5[0];
            puVar4[1] = param_5[1];
            param_5 = param_5 + 2;
            puVar4 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar4) + iVar8);
            uVar6 = uVar6 - 1;
        } while (uVar6 != 0);
    }
    if (bVar2) {
        int32_t iVar7b = reinterpret_cast<int32_t(__cdecl*)(void)>(
            vfn(reinterpret_cast<void*>(static_cast<uintptr_t>(u32_at(param_7, 0x08))), 0x30))();
        if (iVar7b < 0) {
            return 0;
        }
    }
    return static_cast<int32_t>(reinterpret_cast<uintptr_t>(param_7));
}

// ---------------------------------------------------------------------------
// 0x5cdb30 — transforms a stack of skinned positions (3 floats each) by
// `param_3 * weight + param_2` into the position stream, then writes the
// optional colour and blend-weight streams. Stride is 0xc, 0x10 with colours.
// ---------------------------------------------------------------------------
// 0x5cdb30 — observed shape
int32_t FUN_005cdb30(void* param_1, float param_2, float param_3, uint8_t param_4,
                     void* param_5, float* param_6, uint32_t ecx_in = 0)
{
    float* pfVar10 = reinterpret_cast<float*>(static_cast<uintptr_t>(u32_at(param_1, 0x1c)));  // colours
    uint16_t local_2c = u16_at(param_1, 0x10);
    float* pfVar12 = reinterpret_cast<float*>(static_cast<uintptr_t>(u32_at(param_1, 0x14)));  // positions
    uint32_t* local_28 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(u32_at(param_1, 0x18)));  // blend weights
    uint32_t local_30 = 2;
    int32_t iVar13 = 0xc;
    uint32_t local_20 = 0;
    int32_t local_1c = 0;
    if (pfVar10 != nullptr) {
        local_20 = 0xc;
        local_30 = 0x42;
        iVar13 = 0x10;
    }
    int32_t iVar14 = iVar13;
    if (local_28 != nullptr) {
        local_30 = local_30 | 0x100;
        iVar14 = iVar13 + 8;
        local_1c = iVar13;
    }
    void* dest_obj = reinterpret_cast<void*>(static_cast<uintptr_t>(u32_at(param_1, 0x24)));
    u32_at(dest_obj, 0x08) = local_30;
    u32_at(dest_obj, 0x0c) = 0;
    if (i32_at(dest_obj, 0x14) != 0) {
        store_through_i32(dest_obj, 0x18, iVar14);
    }
    bool bVar3 = true;
    uint32_t local_24 = ecx_in;
    if (param_6 == nullptr) {
        bool needs_alloc;
        int32_t local_18[4] = { 0, 0, 0, 0 };
        uint32_t uStack_8 = 0;
        uint32_t uStack_4 = 0;
        if (param_5 == nullptr) {
            needs_alloc = true;
        }
        else {
            int32_t* piVar1 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(u32_at(param_5, 0x08)));
            if (piVar1 == nullptr) {
                needs_alloc = true;
            }
            else {
                reinterpret_cast<void(__cdecl*)(int32_t*, int32_t*)>(vfn(piVar1, 0x34))(piVar1, local_18);
                needs_alloc = (local_18[0] != 100) ||
                              (uStack_4 != local_30) ||
                              (uStack_8 < static_cast<uint32_t>(local_2c) * static_cast<uint32_t>(iVar14));
            }
        }
        if (needs_alloc) {
            uint8_t cVar4 = static_cast<uint8_t>(FUN_005cd450(dest_obj, 0));
            if (cVar4 == 0) {
                return 0;
            }
            if (i32_at(dest_obj, 0x14) == 0) {
                param_5 = nullptr;
            }
            else {
                param_5 = reinterpret_cast<void*>(static_cast<uintptr_t>(
                    static_cast<uint32_t>(load_through_i32(dest_obj, 0x1c))));
            }
        }
        local_30 = 0;
        int32_t iVar13b = reinterpret_cast<int32_t(__cdecl*)(void*, uint32_t, uint32_t, uint32_t*, uint32_t)>(
            vfn(reinterpret_cast<void*>(static_cast<uintptr_t>(u32_at(param_5, 0x08))), 0x2c))(
                reinterpret_cast<void*>(static_cast<uintptr_t>(u32_at(param_5, 0x08))),
                u32_at(param_5, 0x0c), u32_at(param_5, 0x14), &local_30, u32_at(param_5, 0x10));
        param_6 = reinterpret_cast<float*>(static_cast<uintptr_t>(
            static_cast<uint32_t>((iVar13b < 0) - 1) & local_30));
    }
    else {
        bVar3 = false;
    }
    if ((param_4 & 1) != 0) {
        uint32_t uVar8 = local_2c;
        uint32_t uVar9 = 0;
        float* pfVar5 = param_6;
        if (uVar8 > 3) {
            int32_t iVar13c = static_cast<int32_t>((uVar8 - 4) >> 2) + 1;
            uVar9 = static_cast<uint32_t>(iVar13c) * 4;
            float* pfVar11 = pfVar12;
            do {
                pfVar12 = pfVar11 + 0xc;
                float fVar2 = param_3 * pfVar11[2] + param_2;
                *pfVar5 = fVar2 * pfVar11[0];
                pfVar5[1] = fVar2 * pfVar11[1];
                pfVar5[2] = fVar2;
                pfVar5 = reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(pfVar5) + iVar14);
                fVar2 = param_3 * pfVar11[5] + param_2;
                *pfVar5 = fVar2 * pfVar11[3];
                pfVar5[1] = fVar2 * pfVar11[4];
                pfVar5[2] = fVar2;
                pfVar5 = reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(pfVar5) + iVar14);
                fVar2 = param_3 * pfVar11[8] + param_2;
                *pfVar5 = fVar2 * pfVar11[6];
                pfVar5[1] = fVar2 * pfVar11[7];
                pfVar5[2] = fVar2;
                pfVar5 = reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(pfVar5) + iVar14);
                fVar2 = param_3 * pfVar11[0xb] + param_2;
                *pfVar5 = fVar2 * pfVar11[9];
                pfVar5[1] = fVar2 * pfVar11[10];
                pfVar5[2] = fVar2;
                pfVar5 = reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(pfVar5) + iVar14);
                iVar13c = iVar13c - 1;
                pfVar11 = pfVar12;
            } while (iVar13c != 0);
        }
        if (uVar9 < uVar8) {
            int32_t iVar13d = static_cast<int32_t>(uVar8 - uVar9);
            do {
                float fVar2 = param_3 * pfVar12[2] + param_2;
                *pfVar5 = fVar2 * pfVar12[0];
                pfVar5[1] = fVar2 * pfVar12[1];
                pfVar5[2] = fVar2;
                pfVar5 = reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(pfVar5) + iVar14);
                iVar13d = iVar13d - 1;
                pfVar12 = pfVar12 + 3;
            } while (iVar13d != 0);
        }
    }
    if ((pfVar10 != nullptr) && ((param_4 & 2) != 0)) {
        uint32_t* puVar6 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(local_20 + reinterpret_cast<uintptr_t>(param_6)));
        for (uint32_t uVar9 = local_2c; uVar9 != 0; uVar9 = uVar9 - 1) {
            local_20 = static_cast<uint32_t>(ROUND(pfVar10[1] * 255.0));
            local_24 = static_cast<uint32_t>(ROUND(pfVar10[2] * 255.0));
            *puVar6 = ((static_cast<uint32_t>(ROUND(pfVar10[3] * 255.0)) << 8 |
                        static_cast<uint32_t>(ROUND(*pfVar10 * 255.0))) << 8 |
                       local_20) << 8 | local_24;
            puVar6 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar6) + iVar14);
            pfVar10 = pfVar10 + 4;
        }
    }
    if ((local_28 != nullptr) && ((param_4 & 4) != 0)) {
        uint32_t* puVar7 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(local_1c + reinterpret_cast<uintptr_t>(param_6)));
        for (uint32_t uVar9 = local_2c; uVar9 != 0; uVar9 = uVar9 - 1) {
            puVar7[0] = local_28[0];
            puVar7[1] = local_28[1];
            local_28 = local_28 + 2;
            puVar7 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar7) + iVar14);
        }
    }
    if (bVar3) {
        int32_t iVar13e = reinterpret_cast<int32_t(__cdecl*)(void)>(
            vfn(reinterpret_cast<void*>(static_cast<uintptr_t>(u32_at(param_5, 0x08))), 0x30))();
        if (iVar13e < 0) {
            return 0;
        }
    }
    return static_cast<int32_t>(reinterpret_cast<uintptr_t>(param_5));
}

// ---------------------------------------------------------------------------
// 0x5cde70 — indexed (skinned) vertex upload. The index array at param_3+0xc
// selects source vertices; positions are copied, weights are re-emitted with
// the observed ILLEGAL WEIGHTS diagnostic, and the optional normal, colour and
// texture-coordinate streams are gathered through the same indices.
// ---------------------------------------------------------------------------
// 0x5cde70 — observed shape
int32_t FUN_005cde70(void* param_1, uint32_t param_2, void* param_3, uint32_t param_4,
                     void* param_5, uint32_t param_6)
{
    (void)param_2;   // not referenced by the listing body

    int32_t color_src = i32_at(param_1, 0x28);
    int32_t pos_src = i32_at(param_1, 0x20);
    uint32_t normal_src = u32_at(param_1, 0x24);
    uint32_t coord_sets = u8_at(param_1, 0x30) & 0x3f;
    if (coord_sets > 8) {
        coord_sets = 8;
    }
    int32_t index_base = i32_at(param_3, 0x0c);
    uint32_t weight_count = u16_at(param_3, 0x20);
    uint16_t vertex_count = u16_at(param_3, 0x1c);
    int32_t obj_offset = 0;
    int32_t stride = 0;
    int32_t pos_src_saved = pos_src;
    uint32_t pos_out = 0;
    uint32_t weight_out = 0;
    uint32_t normal_out = 0;
    uint32_t color_out = 0;
    uint32_t uv_out = 0;
    FUN_005cd490(param_1, param_3, reinterpret_cast<uint32_t*>(&obj_offset), &stride,
                 &pos_out, reinterpret_cast<int32_t*>(&weight_out),
                 reinterpret_cast<int32_t*>(&normal_out),
                 reinterpret_cast<int32_t*>(&color_out),
                 reinterpret_cast<int32_t*>(&uv_out));

    void* dest_obj = reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(i32_at(param_3, 0x28))));
    u32_at(dest_obj, 0x08) = static_cast<uint32_t>(obj_offset);
    u32_at(dest_obj, 0x0c) = 0;
    if (i32_at(dest_obj, 0x14) != 0) {
        store_through_i32(dest_obj, 0x18, stride);
    }
    bool bVar4 = true;
    if (param_6 == 0) {
        bool needs_alloc;
        int32_t local_118[4] = { 0, 0, 0, 0 };
        uint32_t uStack_108 = 0;
        int32_t iStack_104 = 0;
        if (param_5 == nullptr) {
            needs_alloc = true;
        }
        else {
            int32_t* piVar2 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(u32_at(param_5, 0x08)));
            if (piVar2 == nullptr) {
                needs_alloc = true;
            }
            else if ((u16_at(param_1, 0x32) & 0xf000) == 0x8000) {
                needs_alloc = true;
            }
            else {
                reinterpret_cast<void(__cdecl*)(int32_t*, int32_t*)>(vfn(piVar2, 0x34))(piVar2, local_118);
                needs_alloc = (local_118[0] != 100) ||
                              (iStack_104 != obj_offset) ||
                              (uStack_108 < static_cast<uint32_t>(vertex_count) * static_cast<uint32_t>(stride));
            }
        }
        if (needs_alloc) {
            uint8_t cVar5 = static_cast<uint8_t>(FUN_005cd450(dest_obj, 0));
            if (cVar5 == 0) {
                return 0;
            }
            if (i32_at(dest_obj, 0x14) == 0) {
                obj_offset = 0;
            }
            else {
                obj_offset = load_through_i32(dest_obj, 0x1c);
            }
            param_4 = 0xfff;
        }
        else {
            obj_offset = static_cast<int32_t>(reinterpret_cast<uintptr_t>(param_5));
        }
        uint32_t uStack_128 = 0;
        int32_t iVar13 = reinterpret_cast<int32_t(__cdecl*)(void*, uint32_t, uint32_t, uint32_t*, uint32_t)>(
            vfn(reinterpret_cast<void*>(static_cast<uintptr_t>(u32_at(reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(obj_offset))), 0x08))), 0x2c))(
                reinterpret_cast<void*>(static_cast<uintptr_t>(u32_at(reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(obj_offset))), 0x08))),
                u32_at(reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(obj_offset))), 0x0c),
                u32_at(reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(obj_offset))), 0x14),
                &uStack_128,
                u32_at(reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(obj_offset))), 0x10));
        param_6 = static_cast<uint32_t>((iVar13 < 0) - 1) & uStack_128;
        pos_src = pos_src_saved;
    }
    else {
        obj_offset = static_cast<int32_t>(reinterpret_cast<uintptr_t>(param_5));
        bVar4 = false;
    }

    uint32_t* puVar11 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(pos_out) + param_6));
    if ((param_4 & 1) != 0) {
        uint32_t uVar6 = 0;
        if (vertex_count != 0) {
            do {
                uint32_t* puVar1 = reinterpret_cast<uint32_t*>(
                    static_cast<uintptr_t>(static_cast<uint32_t>(pos_src) +
                                           static_cast<uint32_t>(u16_at(reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(index_base))), uVar6 * 2)) * 0xc));
                puVar11[0] = puVar1[0];
                puVar11[1] = puVar1[1];
                puVar11[2] = puVar1[2];
                uVar6 = uVar6 + 1;
                puVar11 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar11) + stride);
            } while (uVar6 < vertex_count);
        }
        int32_t weight_src = i32_at(param_3, 0x08);
        int32_t iVar13b = static_cast<int32_t>(weight_out + param_6);
        uVar6 = 0;
        if (vertex_count != 0) {
            uint32_t uVar15 = weight_count & 0xffff;
            do {
                float fVar3 = 1.0f;
                uint32_t uVar12 = 0;
                if (uVar15 > 3) {
                    int32_t iVar9 = static_cast<int32_t>((uVar15 - 4) >> 2) + 1;
                    uVar12 = static_cast<uint32_t>(iVar9) * 4;
                    float* pfVar7 = reinterpret_cast<float*>(static_cast<uintptr_t>(static_cast<uint32_t>(weight_src) + 8));
                    do {
                        iVar9 = iVar9 - 1;
                        fVar3 = (((fVar3 - pfVar7[-2]) - pfVar7[-1]) - *pfVar7) - pfVar7[1];
                        pfVar7 = pfVar7 + 4;
                    } while (iVar9 != 0);
                }
                for (; uVar12 < uVar15; uVar12 = uVar12 + 1) {
                    fVar3 = fVar3 - f32_at(reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(weight_src))), uVar12 * 4);
                }
                if (1e-05 < ABS(fVar3)) {
                    char local_100[256];
                    sprintf(local_100, "ILLEGAL WEIGHTS! Vertex %4d - Weight Sum %8.5f  (%8.5f)\n",
                            uVar6, static_cast<double>(1.0f - fVar3), static_cast<double>(fVar3));
                }
                uVar12 = 0;
                if (0 < static_cast<int32_t>(uVar15 - 1)) {
                    uint32_t uVar8 = 0;
                    do {
                        uVar12 = uVar12 + 1;
                        *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(iVar13b)) + uVar8 * 4) =
                            *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(weight_src)) + uVar8 * 4);
                        uVar8 = uVar12 & 0xffff;
                    } while (static_cast<int32_t>(uVar8) < static_cast<int32_t>(uVar15 - 1));
                }
                if ((static_cast<int16_t>(weight_count) == 3) || (static_cast<int16_t>(weight_count) == 1)) {
                    int32_t iVar9b = static_cast<int32_t>(uVar12 & 0xffff) * 4;
                    *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(iVar9b + iVar13b)) =
                        *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(iVar9b + weight_src));
                }
                weight_src = weight_src + static_cast<int32_t>(uVar15 * 4);
                uVar6 = uVar6 + 1;
                iVar13b = iVar13b + stride;
            } while (uVar6 < vertex_count);
        }
    }
    if ((normal_src != 0) && ((param_4 & 2) != 0)) {
        puVar11 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(normal_out + param_6));
        uint32_t uVar6 = 0;
        if (vertex_count != 0) {
            do {
                uint32_t* puVar1 = reinterpret_cast<uint32_t*>(
                    static_cast<uintptr_t>(normal_src +
                                           static_cast<uint32_t>(u16_at(reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(index_base))), uVar6 * 2)) * 0xc));
                puVar11[0] = puVar1[0];
                puVar11[1] = puVar1[1];
                puVar11[2] = puVar1[2];
                uVar6 = uVar6 + 1;
                puVar11 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar11) + stride);
            } while (uVar6 < vertex_count);
        }
    }
    if ((color_src != 0) && ((param_4 & 4) != 0)) {
        uint32_t* puVar10 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(color_out + param_6));
        uint32_t uVar6 = 0;
        if (vertex_count != 0) {
            void* color_base = reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(color_src)));
            do {
                uint32_t idx = static_cast<uint32_t>(u16_at(reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(index_base))), uVar6 * 2));
                int32_t c3 = ROUND(f32_at(color_base, idx * 0x10 + 0x0c) * 255.0);
                uint32_t c0 = static_cast<uint32_t>(ROUND(f32_at(color_base, idx * 0x10 + 0x00) * 255.0));
                uint32_t c1 = static_cast<uint32_t>(ROUND(f32_at(color_base, idx * 0x10 + 0x04) * 255.0));
                uint32_t c2 = static_cast<uint32_t>(ROUND(f32_at(color_base, idx * 0x10 + 0x08) * 255.0));
                *puVar10 = ((static_cast<uint32_t>(c3) << 8 | c0) << 8 | c1) << 8 | c2;
                uVar6 = uVar6 + 1;
                puVar10 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar10) + stride);
            } while (uVar6 < vertex_count);
        }
    }
    if (((param_4 & 8) != 0) && (coord_sets != 0)) {
        uint32_t uVar6 = 0;
        uint32_t uVar15 = vertex_count;
        uint32_t* uv_base = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(uv_out + param_6));
        do {
            uint32_t* puVar11b = uv_base;
            // This listing shows the gather helper invoked with no argument
            // (the argument register is not rewritten at that point).
            int32_t uv_table = static_cast<int32_t>(reinterpret_cast<uintptr_t>(FUN_005412c0()));
            uint32_t uVar12 = 0;
            if (uVar15 != 0) {
                do {
                    uint32_t uVar8 = static_cast<uint32_t>(u16_at(reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(index_base))), uVar12 * 2));
                    puVar11b[0] = u32_at(reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(uv_table))), uVar8 * 8);
                    puVar11b[1] = u32_at(reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(uv_table))), 4 + uVar8 * 8);
                    uVar12 = uVar12 + 1;
                    puVar11b = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar11b) + stride);
                } while (uVar12 < uVar15);
            }
            uVar6 = uVar6 + 1;
            uv_base = uv_base + 2;
        } while (uVar6 < coord_sets);
    }
    if (bVar4) {
        int32_t iVar13c = reinterpret_cast<int32_t(__cdecl*)(void)>(
            vfn(reinterpret_cast<void*>(static_cast<uintptr_t>(u32_at(reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(obj_offset))), 0x08))), 0x30))();
        if (iVar13c < 0) {
            return 0;
        }
    }
    return obj_offset;
}

// ---------------------------------------------------------------------------
// 0x5ce370 — releases every entry of the bucket array at self+0x14 (count at
// self+0x10) through 0x5aead0, frees the five payload words at entry+8 each,
// and finally runs the base destructor.
// ---------------------------------------------------------------------------
// 0x5ce370 — observed shape
void FUN_005ce370(void* self)
{
    uintptr_t local_8 = reinterpret_cast<uintptr_t>(self) + 0x0c;
    (void)local_8;   // assigned by the listing, never read afterwards

    int32_t local_10 = 0;
    if (u32_at(self, 0x10) != 0) {
        int32_t* piVar4 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(u32_at(self, 0x14)));
        uint32_t uVar3 = 0;
        do {
            if (*piVar4 != 0) {
                local_10 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(u32_at(self, 0x14)))[uVar3];
                break;
            }
            uVar3 = uVar3 + 1;
            piVar4 = piVar4 + 1;
        } while (uVar3 < u32_at(self, 0x10));
    }
    while (local_10 != 0) {
        uint8_t local_4[4] = { 0, 0, 0, 0 };
        void* local_c = nullptr;
        FUN_005aead0(&local_10, local_4, &local_c);
        void* pvVar2 = local_c;
        if (local_c != nullptr) {
            uint32_t* puVar6 = reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(local_c) + 8);
            int32_t iVar5 = 5;
            do {
                void* pvVar1 = reinterpret_cast<void*>(static_cast<uintptr_t>(*puVar6));
                if (pvVar1 != nullptr) {
                    int32_t* piVar4b = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(u32_at(pvVar1, 0x20)));
                    if (piVar4b != nullptr) {
                        reinterpret_cast<void(__cdecl*)(int32_t*)>(vfn(piVar4b, 0x08))(piVar4b);
                    }
                    FUN_005d8430();
                    operator_delete(pvVar1);
                }
                puVar6 = puVar6 + 1;
                iVar5 = iVar5 - 1;
            } while (iVar5 != 0);
            operator_delete(pvVar2);
        }
    }
    FUN_005e1490();
}

// ---------------------------------------------------------------------------
// 0x5ce430 — resource-container constructor: installs the two label vtables,
// bumps the module count, then builds three 0x25-entry bucket groups (each a
// 0x94-byte zero-filled array at +0x14, +0x24, +0x34) and registers param_1.
// ---------------------------------------------------------------------------
// 0x5ce430 — observed shape
void FUN_005ce430(void* self, int32_t* param_1)
{
    ptr_at(self, 0x00) = &PTR_LAB_006fd148;
    u32_at(self, 0x04) = 0;
    DAT_00727444 = DAT_00727444 + 1;
    ptr_at(self, 0x00) = &PTR_FUN_006c7e68;
    ptr_at(self, 0x0c) = &PTR_FUN_006c7df4;
    u32_at(self, 0x10) = 0x25;
    u32_at(self, 0x18) = 0;
    {
        uint32_t* puVar1 = reinterpret_cast<uint32_t*>(thunk_FUN_00533c78(0x94));
        u32_at(self, 0x14) = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar1));
        for (uint32_t uVar2 = u32_at(self, 0x10) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar1 = 0;
            puVar1 = puVar1 + 1;
        }
        // The byte tail loop never runs: its counter starts at zero.
        for (int32_t iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
            *reinterpret_cast<uint8_t*>(puVar1) = 0;
            puVar1 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar1) + 1);
        }
    }
    ptr_at(self, 0x0c) = &PTR_FUN_006c7e10;
    ptr_at(self, 0x1c) = &PTR_FUN_006c7df4;
    u32_at(self, 0x20) = 0x25;
    u32_at(self, 0x28) = 0;
    {
        uint32_t* puVar1 = reinterpret_cast<uint32_t*>(thunk_FUN_00533c78(0x94));
        u32_at(self, 0x24) = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar1));
        for (uint32_t uVar2 = u32_at(self, 0x20) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar1 = 0;
            puVar1 = puVar1 + 1;
        }
        for (int32_t iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
            *reinterpret_cast<uint8_t*>(puVar1) = 0;
            puVar1 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar1) + 1);
        }
    }
    ptr_at(self, 0x1c) = &PTR_FUN_006c7e10;
    ptr_at(self, 0x2c) = &PTR_FUN_006c7df4;
    u32_at(self, 0x30) = 0x25;
    u32_at(self, 0x38) = 0;
    {
        uint32_t* puVar1 = reinterpret_cast<uint32_t*>(thunk_FUN_00533c78(0x94));
        u32_at(self, 0x34) = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar1));
        for (uint32_t uVar2 = u32_at(self, 0x30) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar1 = 0;
            puVar1 = puVar1 + 1;
        }
        for (int32_t iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
            *reinterpret_cast<uint8_t*>(puVar1) = 0;
            puVar1 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar1) + 1);
        }
    }
    ptr_at(self, 0x2c) = &PTR_FUN_006c7e10;
    u32_at(self, 0x08) = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_1));
    reinterpret_cast<void(__cdecl*)(int32_t*)>(vfn(param_1, 0x04))(param_1);
    FUN_005e1490();
    FUN_005e1490();
    FUN_005e1490();
    u32_at(self, 0x3c) = 0;
}

// ---------------------------------------------------------------------------
// 0x5ce550 — resource-container destructor: for each of the three bucket
// groups it unlinks every entry and frees the five payload words of each
// entry, then tears the groups down and clears the registered object.
// ---------------------------------------------------------------------------
// 0x5ce550 — observed shape
void FUN_005ce550(void* self)
{
    ptr_at(self, 0x00) = &PTR_FUN_006c7e68;

    uint32_t local_c = 0;
    do {
        uint32_t* local_10 = nullptr;
        if (local_c == 0) {
            local_10 = reinterpret_cast<uint32_t*>(self) + 3;      // self + 0x0c
        }
        else if (local_c == 1) {
            local_10 = reinterpret_cast<uint32_t*>(self) + 7;      // self + 0x1c
        }
        else if (local_c == 2) {
            local_10 = reinterpret_cast<uint32_t*>(self) + 0xb;    // self + 0x2c
        }

        int32_t* piVar4 = nullptr;
        bool found = false;
        if (local_10[1] != 0) {
            piVar4 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(local_10[2]));
            uint32_t uVar3 = 0;
            do {
                if (*piVar4 != 0) {
                    piVar4 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(local_10[2]))[uVar3];
                    found = true;
                    break;
                }
                uVar3 = uVar3 + 1;
                piVar4 = piVar4 + 1;
            } while (uVar3 < local_10[1]);
        }
        if (!found) {
            piVar4 = nullptr;
        }

        while (piVar4 != nullptr) {
            int32_t* piVar6 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(*piVar4)));
            void* pvVar1 = reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(piVar4[2])));
            if (piVar6 == nullptr) {
                int32_t iVar7 = reinterpret_cast<int32_t(__cdecl*)(uint32_t)>(vfn(
                    reinterpret_cast<void*>(static_cast<uintptr_t>(local_10[0])), 0x04))(static_cast<uint32_t>(piVar4[1]));
                uint32_t uVar3b = static_cast<uint32_t>(iVar7 + 1);
                piVar6 = nullptr;
                if (uVar3b < local_10[1]) {
                    uint32_t* puVar5 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(local_10[2] + uVar3b * 4));
                    do {
                        if (*puVar5 != 0) {
                            piVar6 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(*puVar5));
                            break;
                        }
                        uVar3b = uVar3b + 1;
                        puVar5 = puVar5 + 1;
                    } while (uVar3b < local_10[1]);
                }
            }
            piVar4 = piVar6;
            if (pvVar1 != nullptr) {
                uint32_t* puVar5 = reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(pvVar1) + 8);
                int32_t iVar7 = 5;
                do {
                    void* pvVar2 = reinterpret_cast<void*>(static_cast<uintptr_t>(*puVar5));
                    if (pvVar2 != nullptr) {
                        int32_t* piVar6b = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(u32_at(pvVar2, 0x20)));
                        if (piVar6b != nullptr) {
                            reinterpret_cast<void(__cdecl*)(int32_t*)>(vfn(piVar6b, 0x08))(piVar6b);
                        }
                        FUN_005d8430();
                        operator_delete(pvVar2);
                    }
                    puVar5 = puVar5 + 1;
                    iVar7 = iVar7 - 1;
                } while (iVar7 != 0);
                operator_delete(pvVar1);
            }
        }

        local_c = local_c + 1;
        if (2 < local_c) {
            FUN_005e1490();
            FUN_005e1490();
            FUN_005e1490();
            int32_t* registered = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(u32_at(self, 0x08)));
            reinterpret_cast<void(__cdecl*)(int32_t*)>(vfn(registered, 0x08))(registered);
            u32_at(self, 0x08) = 0;

            ptr_at(self, 0x2c) = &PTR_FUN_006c7e10;
            FUN_005e1490();
            ptr_at(self, 0x2c) = &PTR_FUN_006c7df4;
            FUN_005e1490();
            operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(u32_at(self, 0x34))));

            ptr_at(self, 0x1c) = &PTR_FUN_006c7e10;
            FUN_005e1490();
            ptr_at(self, 0x1c) = &PTR_FUN_006c7df4;
            FUN_005e1490();
            operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(u32_at(self, 0x24))));

            ptr_at(self, 0x0c) = &PTR_FUN_006c7e10;
            FUN_005e1490();
            ptr_at(self, 0x0c) = &PTR_FUN_006c7df4;
            FUN_005e1490();
            operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(u32_at(self, 0x14))));

            ptr_at(self, 0x00) = &PTR_LAB_006fd148;
            DAT_00727444 = DAT_00727444 + -1;
            return;
        }
    } while (true);
}

// ---------------------------------------------------------------------------
// 0x5ce740 — scalar deleting destructor: runs 0x5ce550 and frees the object
// when bit 0 of the flag is set.
// ---------------------------------------------------------------------------
// 0x5ce740 — observed shape
void FUN_005ce740(void* self, uint8_t param_1)
{
    FUN_005ce550(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// ---------------------------------------------------------------------------
// 0x5ce760 — derived constructor: runs the base constructor and installs the
// float bounds pair (-3.4028235e38f, 3.4028235e38f) at self+0x18/self+0x1c.
// ---------------------------------------------------------------------------
// 0x5ce760 — observed shape
void FUN_005ce760(void* self)
{
    FUN_00552c80(self);
    ptr_at(self, 0x00) = &PTR_FUN_006c7e70;
    u32_at(self, 0x18) = 0xff7fffff;
    u32_at(self, 0x1c) = 0x7f7fffff;
}

// ---------------------------------------------------------------------------
// 0x5ce790 — derived destructor: installs the label vtable and runs the base
// destructor.
// ---------------------------------------------------------------------------
// 0x5ce790 — observed shape
void FUN_005ce790(void* self)
{
    ptr_at(self, 0x00) = &PTR_FUN_006c7e70;
    FUN_00552d20();
}

// ---------------------------------------------------------------------------
// 0x5ce800 — creates the offscreen surface for a source texture: derives the
// mip level from the requested size, shifts the stored dimensions by that
// level, and calls vtable +0x5c on the device object at [self+8]+0x60.
// ---------------------------------------------------------------------------
// 0x5ce800 — observed shape
uint32_t FUN_005ce800(void* self, void* param_1)
{
    uint32_t uVar2 = FUN_005bfb50(static_cast<uint8_t*>(self) + 0x0c);
    int32_t iVar4 = i32_at(param_1, 0x44);
    i32_at(self, 0x48) = iVar4;
    int32_t* piVar1 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(
        u32_at(reinterpret_cast<void*>(static_cast<uintptr_t>(u32_at(self, 0x08))), 0x60)));
    uint32_t uVar3 = static_cast<uint32_t>(iVar4 - 1);
    uint32_t uVar5 = DAT_00728e88;
    if (uVar3 < DAT_00728e88) {
        uVar5 = uVar3;
    }
    uint32_t uVar6 = u32_at(self, 0x44) >> (uVar5 & 0x1f);
    uVar3 = u32_at(self, 0x40) >> (uVar5 & 0x1f);
    u32_at(self, 0x5c) = uVar5;
    u32_at(self, 0x44) = uVar6;
    u32_at(self, 0x40) = uVar3;
    iVar4 = reinterpret_cast<int32_t(__cdecl*)(int32_t*, uint32_t, uint32_t, int32_t, uint32_t, uint32_t, uint32_t, void*, uint32_t)>(
        vfn(piVar1, 0x5c))(piVar1, uVar3, uVar6, static_cast<int32_t>(u32_at(self, 0x48) - uVar5),
                           0, uVar2, 1, static_cast<uint8_t*>(self) + 0x60, 0);
    if (iVar4 < 0) {
        const char* uVar2b = FUN_005d8450(iVar4);
        FUN_00497420("NiDX9SourceTextureData::CreateSurf> Failed CreateImageSurface - %s\n", uVar2b);
        u32_at(self, 0x60) = 0;
        return 0;
    }
    return 1;
}

// ---------------------------------------------------------------------------
// 0x5ce8a0 — copies the source texture data into the locked surface. The
// listing reads the surface description through stack slots the +0x34 query
// fills; they are modelled as one descriptor plus the level index, row count
// and locked surface the listing keeps beside it. The destination word
// (puVar10) is null on entry in both copy paths, as the listing shows.
// ---------------------------------------------------------------------------
struct SurfaceDesc_5ce8a0 {
    uint8_t  pad_00[0x0c];
    int32_t  field_0c;    // +0x0c
    uint8_t  pad_10[0x24]; // +0x10..+0x33
    uint32_t field_34;    // +0x34 base of the locked pixels
    uint32_t field_38;    // +0x38 pointer to the level size table
    uint32_t field_40;    // +0x40 pointer to the row-offset table
    uint32_t field_48;    // +0x48
};

// 0x5ce8a0 — observed shape
void FUN_005ce8a0(uint32_t param_1, uint32_t param_2, void* param_3)
{
    (void)param_1;   // not referenced by the listing body
    (void)param_2;   // not referenced by the listing body

    uint8_t local_20[4] = { 0, 0, 0, 0 };
    void* desc_slot = local_20;      // corpus: puStack_30 = local_20

    int32_t iVar1 = reinterpret_cast<int32_t(__cdecl*)(void*)>(vfn(param_3, 0x30))(param_3);
    if (iVar1 < 0) {
        const char* uVar2 = FUN_005d8450(iVar1);
        FUN_00497420("NiDX9SourceTextureData::CopyDataToSurface> Failed GetDesc - %s", uVar2);
        return;
    }

    uint32_t* puVar10 = nullptr;
    void** ppuVar9 = &desc_slot;
    iVar1 = reinterpret_cast<int32_t(__cdecl*)(void*, void**, uint32_t, uint32_t)>(
        vfn(param_3, 0x34))(param_3, ppuVar9, 0, 0);
    if (iVar1 < 0) {
        const char* uVar2 = FUN_005d8450(iVar1);
        FUN_00497420("NiDX9SourceTextureData::CopyDataToSurface> Failed GetSurfaceLevel - %s", uVar2);
        return;
    }

    SurfaceDesc_5ce8a0* info = nullptr;   // corpus: iStack_14
    int32_t level = 0;                    // corpus: iStack_10
    uint32_t rows = 0;                    // corpus: uStack_1c
    void* surface = nullptr;              // corpus: piStack_c

    void** ppuVar6 = reinterpret_cast<void**>(static_cast<uintptr_t>(
        static_cast<uint32_t>(*reinterpret_cast<int32_t*>(static_cast<uintptr_t>(info->field_38) + level * 4)) *
        static_cast<uint32_t>(info->field_48)));

    if ((ppuVar9 == ppuVar6) || ((3 < info->field_0c) && (info->field_0c < 7))) {
        int32_t iVar1b = *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(info->field_40) + level * 4);
        uint32_t uVar4 = static_cast<uint32_t>(
            *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(info->field_40) + level * 4 + 4) - iVar1b);
        uint32_t* puVar3 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(info->field_34 + static_cast<uint32_t>(iVar1b)));
        for (uint32_t uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar10 = *puVar3;
            puVar3 = puVar3 + 1;
            puVar10 = puVar10 + 1;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *reinterpret_cast<uint8_t*>(puVar10) = *reinterpret_cast<uint8_t*>(puVar3);
            puVar3 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar3) + 1);
            puVar10 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar10) + 1);
        }
    }
    else {
        uint32_t* puVar3 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(
            static_cast<uint32_t>(*reinterpret_cast<int32_t*>(static_cast<uintptr_t>(info->field_40) + level * 4)) +
            info->field_34));
        uint32_t uVar5 = 0;
        if (rows != 0) {
            do {
                uint32_t* puVar7 = puVar3;
                uint32_t* puVar8 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(
                    uVar5 * reinterpret_cast<uintptr_t>(ppuVar9) + reinterpret_cast<uintptr_t>(puVar10)));
                for (uint32_t uVar4b = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(ppuVar6)) >> 2; uVar4b != 0; uVar4b = uVar4b - 1) {
                    *puVar8 = *puVar7;
                    puVar7 = puVar7 + 1;
                    puVar8 = puVar8 + 1;
                }
                puVar3 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar3) + reinterpret_cast<uintptr_t>(ppuVar6));
                for (uint32_t uVar4c = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(ppuVar6)) & 3; uVar4c != 0; uVar4c = uVar4c - 1) {
                    *reinterpret_cast<uint8_t*>(puVar8) = *reinterpret_cast<uint8_t*>(puVar7);
                    puVar7 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar7) + 1);
                    puVar8 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar8) + 1);
                }
                uVar5 = uVar5 + 1;
            } while (uVar5 < rows);
            reinterpret_cast<void(__cdecl*)(void*)>(vfn(surface, 0x38))(surface);
            return;
        }
    }
    reinterpret_cast<void(__cdecl*)(void*)>(vfn(param_3, 0x38))(param_3);
}

} // namespace mass_0221_candidate
