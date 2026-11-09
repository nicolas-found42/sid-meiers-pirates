//
// mass_0304.cpp — reconstruction batch mass_0304
// Target: Sid Meier's Pirates! (2004), PE32 i386
// Image: 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
//
// Each definition preserves the observed field offsets, constants,
// call order, return shape, and conditional structure of the Ghidra
// 12.2 pseudocode (analysis/pseudocode/functions/*.c).
//
// Register receivers (in_ECX and friends) are modeled as an explicit
// `void* self`; state-block pointer lives at self+0xc4, the device
// array pointer at self+0xb0, and the interface kind at self+0x3c.
//
#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---------------------------------------------------------------------------
// Extern declarations: helpers referenced by the assigned corpus files.
// No address absent from those listings is introduced.
// ---------------------------------------------------------------------------
void*   FUN_0064e847(uint32_t handle, int32_t a, int32_t b);
int32_t FUN_006431b5(void* surface);
int32_t FUN_00644f8a(uint32_t a, uint32_t b, uint32_t c, uint32_t d, int32_t e);
int32_t FUN_00649053(uint32_t handle, float* out);
int32_t FUN_006490df(uint32_t handle, uint32_t* out, uint32_t count);
int32_t FUN_00649197(uint32_t handle, uint32_t out);
int32_t FUN_00649224(uint32_t handle, uint32_t out, uint32_t count);
int32_t FUN_006492dc(uint32_t handle, uint32_t out, uint32_t count);
int32_t FUN_0064939b(uint32_t handle, uint32_t out);
int32_t FUN_00649425(uint32_t handle, uint32_t out, uint32_t count);
int32_t FUN_006494ec(uint32_t handle, uint32_t out, uint32_t count);
int32_t FUN_006495a9(uint32_t handle, uint32_t out);
int32_t FUN_0063f9ca(uint32_t a, uint32_t b, uint32_t c);
int32_t FUN_0063faf9(int32_t surface, uint32_t a, uint32_t b, uint32_t count);
int32_t FUN_0063fb92(int32_t surface, uint32_t a, uint32_t b);
int32_t FUN_0063fc54(int32_t surface, uint32_t a, uint32_t b, uint32_t count);
int32_t FUN_0063fd69(int32_t surface, uint32_t a, uint32_t b, uint32_t count);
int32_t FUN_0063fee8(int32_t surface, uint32_t a, uint32_t b, uint32_t count);
int32_t FUN_0064007b(int32_t surface, uint32_t a, uint32_t b, uint32_t count);
int32_t FUN_0064017b(int32_t surface, uint32_t a, uint32_t b, uint32_t count);
int32_t FUN_006402aa(int32_t surface, uint32_t a, uint32_t b, uint32_t count);
int32_t FUN_00640408(int32_t surface, uint32_t a, uint32_t b, uint32_t count);

// x87 `ftol` / `frndint` renderings in the provider listing.
static int32_t x87_ftol(float value) { return static_cast<int32_t>(value); }
static int32_t x87_round_to_int(float value)
{
    return static_cast<int32_t>(value >= 0.0f ? value + 0.5f : value - 0.5f);
}

// ---------------------------------------------------------------------------
// 0x64f5ba — observed shape
// Resolve handle param_2, reject null or undersized sub-resource, then
// forward surface word pair plus the device slot's +0x40 field and the
// "sub-resource present" flag (puVar1[2] != -1) to FUN_00644f8a.
// ---------------------------------------------------------------------------
uint32_t FUN_0064f5ba(void* self, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    uint32_t* puVar1 = reinterpret_cast<uint32_t*>(FUN_0064e847(param_2, 1, 0));
    uint32_t uVar2;

    if (puVar1 == nullptr || (param_4 != 0xffffffffu && param_4 < puVar1[3])) {
        uVar2 = 0x8876086cu;
    } else {
        int32_t deviceArray = *reinterpret_cast<int32_t*>(base + 0xb0);
        uint32_t slotField = *reinterpret_cast<uint32_t*>(
            *reinterpret_cast<int32_t*>(deviceArray + static_cast<int32_t>(puVar1[5] * 4)) + 0x40);
        uVar2 = static_cast<uint32_t>(FUN_00644f8a(puVar1[1], puVar1[0], param_3, slotField,
                                                   puVar1[2] != 0xffffffffu));
    }
    return uVar2;
}

// ---------------------------------------------------------------------------
// 0x64f616 — observed shape
// If the handle's high bit is set it is a direct pointer (complemented);
// otherwise resolve it. Width/height are validated against the resolved
// surface's +0x10 field, then stored to the device slot at +0x48 / +0x4c.
// ---------------------------------------------------------------------------
uint32_t FUN_0064f616(void* self, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    uint32_t res;

    if (static_cast<int32_t>(param_2) < 0) {
        res = ~param_2;
    } else {
        res = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(FUN_0064e847(param_2, 1, 1)));
        if (res == 0) {
            return 0x8876086cu;
        }
    }

    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(
        static_cast<uintptr_t>(*reinterpret_cast<int32_t*>(static_cast<uintptr_t>(res) + 4)) + 0x10);
    if (uVar1 < param_4 || uVar1 < param_3) {
        return 0x8876086cu;
    }

    uint32_t* puVar1 = reinterpret_cast<uint32_t*>(res);
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    int32_t deviceArray = *reinterpret_cast<int32_t*>(base + 0xb0);
    int32_t slot = *reinterpret_cast<int32_t*>(deviceArray + static_cast<int32_t>(puVar1[5] * 4));
    *reinterpret_cast<uint32_t*>(slot + 0x48) = param_3;
    *reinterpret_cast<uint32_t*>(slot + 0x4c) = param_4;
    return 0;
}

// ---------------------------------------------------------------------------
// 0x64f681 — observed shape
// Upload a CPU-side block into the resolved surface. For an unresolved
// (positive) handle the state block at self+0xc4 is first programmed to
// (1,3,param_4,4,1). Format 1 converts ints to 0/1, format 2 truncates
// floats, format 3 copies raw words (4-wide fast path) or row-wise words.
// ---------------------------------------------------------------------------
uint32_t FUN_0064f681(void* self, uint32_t param_2, uint32_t* param_3, uint32_t param_4)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    uint32_t* local_8;

    if (static_cast<int32_t>(param_2) < 0) {
        local_8 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(~param_2));
    } else {
        uint8_t* dev = *reinterpret_cast<uint8_t**>(base + 0xc4);
        *reinterpret_cast<uint32_t*>(dev + 4) = 1;
        *reinterpret_cast<uint32_t*>(dev + 0) = 3;
        *reinterpret_cast<uint32_t*>(dev + 0x10) = param_4;
        *reinterpret_cast<uint32_t*>(dev + 0x14) = 4;
        *reinterpret_cast<uint32_t*>(dev + 0x18) = 1;
        local_8 = reinterpret_cast<uint32_t*>(FUN_0064e847(param_2, 1, 1));
        if (local_8 == nullptr) {
            return 0x8876086cu;
        }
    }

    uint8_t* piVar1 = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(local_8[1]));
    if (!(*reinterpret_cast<int32_t*>(piVar1 + 0x10) != 0 && local_8[2] == 0xffffffffu &&
          param_4 <= *reinterpret_cast<uint32_t*>(piVar1 + 0x10))) {
        return 0x8876086cu;
    }

    if (*reinterpret_cast<int32_t*>(base + 0x3c) == 3) {
        return static_cast<uint32_t>(FUN_006490df(~reinterpret_cast<uint32_t>(
                                                     reinterpret_cast<uintptr_t>(local_8)),
                                                 param_3, param_4));
    }

    int32_t  format = *reinterpret_cast<int32_t*>(piVar1 + 0);
    uint32_t stride = *reinterpret_cast<uint32_t*>(piVar1 + 0x14);
    if (*reinterpret_cast<int32_t*>(piVar1 + 4) != 1) {
        return 0x8876086cu;
    }

    uint32_t* buffer = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(local_8[0]));
    uint32_t  limit = (stride < 5) ? stride : 4u;

    if (format == 1) {
        if (param_4 != 0) {
            uint32_t rows = param_4;
            do {
                if (limit != 0) {
                    uint32_t* dst = buffer;
                    uint32_t  n = limit;
                    uintptr_t srcDelta = reinterpret_cast<uintptr_t>(param_3) -
                                         reinterpret_cast<uintptr_t>(buffer);
                    do {
                        float v = *reinterpret_cast<float*>(reinterpret_cast<uintptr_t>(dst) + srcDelta);
                        *dst = (v != 0.0f) ? 1u : 0u;
                        ++dst;
                        --n;
                    } while (n != 0);
                }
                buffer += stride;
                ++param_3;
                --rows;
            } while (rows != 0);
        }
    } else if (format == 2) {
        if (param_4 != 0) {
            uint32_t rows = param_4;
            do {
                if (limit != 0) {
                    uint32_t* dst = buffer;
                    uint32_t  n = limit;
                    uintptr_t srcDelta = reinterpret_cast<uintptr_t>(param_3) -
                                         reinterpret_cast<uintptr_t>(buffer);
                    do {
                        float v = *reinterpret_cast<float*>(reinterpret_cast<uintptr_t>(dst) + srcDelta);
                        *dst = static_cast<uint32_t>(x87_ftol(v));
                        ++dst;
                        --n;
                    } while (n != 0);
                }
                buffer += stride;
                ++param_3;
                --rows;
            } while (rows != 0);
        }
    } else if (format == 3) {
        if (stride == 4) {
            int32_t n = static_cast<int32_t>((param_4 & 0xfffffffu) << 2);
            for (; n != 0; --n) {
                *buffer = *param_3;
                ++param_3;
                ++buffer;
            }
            // trailing byte loop has zero trip count in the observed build
        } else {
            for (; param_4 != 0; --param_4) {
                if (limit != 0) {
                    uint32_t* dst = buffer;
                    uint32_t  n = limit;
                    uintptr_t srcDelta = reinterpret_cast<uintptr_t>(param_3) -
                                         reinterpret_cast<uintptr_t>(buffer);
                    do {
                        *dst = *reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(dst) + srcDelta);
                        ++dst;
                        --n;
                    } while (n != 0);
                }
                ++param_3;
                buffer += stride;
            }
        }
    } else {
        return 0x8876086cu;
    }

    return static_cast<uint32_t>(FUN_006431b5(local_8));
}

// ---------------------------------------------------------------------------
// 0x64f844 — observed shape
// Download the resolved surface into a float array: zero the destination,
// then per row convert ints to float 0/1 (fmt 1), ints to float (fmt 2),
// or bit-copy floats (fmt 3). Row stride comes from +0x14, width is
// min(stride, 4).
// ---------------------------------------------------------------------------
uint32_t FUN_0064f844(uint32_t param_1, int32_t param_2, float* param_3, uint32_t param_4)
{
    if (param_4 == 0) {
        return 0;
    }
    if (param_3 == nullptr) {
        return 0x8876086cu;
    }

    int32_t* piVar4 = reinterpret_cast<int32_t*>(FUN_0064e847(static_cast<uint32_t>(param_2), 1, 0));
    if (piVar4 == nullptr) {
        return 0x8876086cu;
    }
    uint8_t* piVar1 = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(piVar4[1]));
    if (!(*reinterpret_cast<int32_t*>(piVar1 + 0x10) != 0 &&
          piVar4[2] == -1 &&
          param_4 <= *reinterpret_cast<uint32_t*>(piVar1 + 0x10) &&
          *reinterpret_cast<int32_t*>(piVar1 + 4) == 1)) {
        return 0x8876086cu;
    }

    uintptr_t srcBase = static_cast<uintptr_t>(static_cast<uint32_t>(piVar4[0]));
    uint32_t  stride = *reinterpret_cast<uint32_t*>(piVar1 + 0x14);
    int32_t   format = *reinterpret_cast<int32_t*>(piVar1 + 0);
    param_1 = (stride < 5) ? stride : 4u;

    {
        uintptr_t dst = reinterpret_cast<uintptr_t>(param_3);
        for (int32_t iVar6 = static_cast<int32_t>((param_4 & 0xfffffffu) << 2); iVar6 != 0; --iVar6) {
            *reinterpret_cast<float*>(dst) = 0.0f;
            dst += 4;
        }
        // trailing byte loop has zero trip count in the observed build
    }

    if (format == 1) {
        for (uint32_t row = 0; row < param_4; ++row) {
            for (uint32_t i = 0; i < param_1; ++i) {
                int32_t v = *reinterpret_cast<int32_t*>(srcBase + (row * stride + i) * 4);
                param_3[row * 4 + i] = static_cast<float>(v != 0);
            }
        }
        return 0;
    }
    if (format == 2) {
        for (uint32_t row = 0; row < param_4; ++row) {
            for (uint32_t i = 0; i < param_1; ++i) {
                int32_t v = *reinterpret_cast<int32_t*>(srcBase + (row * stride + i) * 4);
                param_3[row * 4 + i] = static_cast<float>(v);
            }
        }
        return 0;
    }
    if (format == 3) {
        for (uint32_t row = 0; row < param_4; ++row) {
            for (uint32_t i = 0; i < param_1; ++i) {
                param_3[row * 4 + i] =
                    *reinterpret_cast<float*>(srcBase + (row * stride + i) * 4);
            }
        }
        return 0;
    }
    return 0x8876086cu;
}

// ---------------------------------------------------------------------------
// 0x64f987 — observed shape
// Lock/read a format-2 sub-resource: program state (2,3,param_4,4,4),
// require resolved surface kind 2 with +0x10 >= param_4 and no
// sub-resource, then dispatch (software path) or download + release.
// ---------------------------------------------------------------------------
int32_t FUN_0064f987(void* self, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    uint32_t* puVar3;

    if (static_cast<int32_t>(param_2) < 0) {
        puVar3 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(~param_2));
    } else {
        uint8_t* dev = *reinterpret_cast<uint8_t**>(base + 0xc4);
        *reinterpret_cast<uint32_t*>(dev + 4) = 2;
        *reinterpret_cast<uint32_t*>(dev + 0) = 3;
        *reinterpret_cast<uint32_t*>(dev + 0x10) = param_4;
        *reinterpret_cast<uint32_t*>(dev + 0x14) = 4;
        *reinterpret_cast<uint32_t*>(dev + 0x18) = 4;
        puVar3 = reinterpret_cast<uint32_t*>(FUN_0064e847(param_2, 1, 1));
        if (puVar3 == nullptr) {
            return -0x7789f794;
        }
    }

    uint8_t* iVar2 = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(puVar3[1]));
    if (*reinterpret_cast<int32_t*>(iVar2 + 4) != 2 ||
        *reinterpret_cast<uint32_t*>(iVar2 + 0x10) < param_4 ||
        puVar3[2] != 0xffffffffu) {
        return -0x7789f794;
    }

    if (*reinterpret_cast<int32_t*>(base + 0x3c) == 3) {
        return FUN_00649224(~reinterpret_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar3)),
                            param_3, param_4);
    }

    int32_t iVar3 = FUN_0063fc54(*reinterpret_cast<int32_t*>(iVar2), puVar3[0], param_3, param_4);
    if (iVar3 < 0) {
        return iVar3;
    }
    return static_cast<int32_t>(FUN_006431b5(puVar3));
}

// ---------------------------------------------------------------------------
// 0x64fa27 — observed shape
// Plain read: zero count returns success; otherwise resolve the handle,
// require a format-2 surface with +0x10 >= param_4 and no sub-resource,
// then download through FUN_0063fee8.
// ---------------------------------------------------------------------------
uint32_t FUN_0064fa27(uint32_t param_1, uint32_t param_2, int32_t param_3, uint32_t param_4)
{
    (void)param_1;
    if (param_4 == 0) {
        return 0;
    }
    if (param_3 != 0) {
        uint32_t* puVar3 = reinterpret_cast<uint32_t*>(FUN_0064e847(param_2, 1, 0));
        if (puVar3 != nullptr) {
            uint8_t* iVar1 = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(puVar3[1]));
            if (*reinterpret_cast<uint32_t*>(iVar1 + 0x10) != 0 &&
                puVar3[2] == 0xffffffffu &&
                param_4 <= *reinterpret_cast<uint32_t*>(iVar1 + 0x10) &&
                *reinterpret_cast<int32_t*>(iVar1 + 4) == 2) {
                return static_cast<uint32_t>(FUN_0063fee8(
                    *reinterpret_cast<int32_t*>(iVar1), puVar3[0],
                    static_cast<uint32_t>(param_3), param_4));
            }
        }
    }
    return 0x8876086cu;
}

// ---------------------------------------------------------------------------
// 0x64fa86 — observed shape
// Lock for read: program state (2,3,param_4,4,4), validate format-2
// surface with +0x10 >= param_4 and no sub-resource; software dispatch
// FUN_006492dc, hardware path FUN_0064017b then release.
// ---------------------------------------------------------------------------
int32_t FUN_0064fa86(void* self, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    uint32_t* puVar3;

    if (static_cast<int32_t>(param_2) < 0) {
        puVar3 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(~param_2));
    } else {
        uint8_t* dev = *reinterpret_cast<uint8_t**>(base + 0xc4);
        *reinterpret_cast<uint32_t*>(dev + 4) = 2;
        *reinterpret_cast<uint32_t*>(dev + 0) = 3;
        *reinterpret_cast<uint32_t*>(dev + 0x10) = param_4;
        *reinterpret_cast<uint32_t*>(dev + 0x14) = 4;
        *reinterpret_cast<uint32_t*>(dev + 0x18) = 4;
        puVar3 = reinterpret_cast<uint32_t*>(FUN_0064e847(param_2, 1, 1));
        if (puVar3 == nullptr) {
            return -0x7789f794;
        }
    }

    uint8_t* iVar2 = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(puVar3[1]));
    if (*reinterpret_cast<int32_t*>(iVar2 + 4) != 2 ||
        *reinterpret_cast<uint32_t*>(iVar2 + 0x10) < param_4 ||
        puVar3[2] != 0xffffffffu) {
        return -0x7789f794;
    }

    if (*reinterpret_cast<int32_t*>(base + 0x3c) == 3) {
        return FUN_006492dc(~reinterpret_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar3)),
                            param_3, param_4);
    }

    int32_t iVar3 = FUN_0064017b(*reinterpret_cast<int32_t*>(iVar2), puVar3[0], param_3, param_4);
    if (iVar3 < 0) {
        return iVar3;
    }
    return static_cast<int32_t>(FUN_006431b5(puVar3));
}

// ---------------------------------------------------------------------------
// 0x64fb26 — observed shape
// Plain read variant: resolve, require format-2 surface with nonzero
// +0x10 >= param_4 and no sub-resource, then FUN_00640408.
// ---------------------------------------------------------------------------
uint32_t FUN_0064fb26(uint32_t param_1, uint32_t param_2, int32_t param_3, uint32_t param_4)
{
    (void)param_1;
    if (param_4 == 0) {
        return 0;
    }
    if (param_3 != 0) {
        uint32_t* puVar3 = reinterpret_cast<uint32_t*>(FUN_0064e847(param_2, 1, 0));
        if (puVar3 != nullptr) {
            uint8_t* iVar1 = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(puVar3[1]));
            if (*reinterpret_cast<uint32_t*>(iVar1 + 0x10) != 0 &&
                puVar3[2] == 0xffffffffu &&
                param_4 <= *reinterpret_cast<uint32_t*>(iVar1 + 0x10) &&
                *reinterpret_cast<int32_t*>(iVar1 + 4) == 2) {
                return static_cast<uint32_t>(FUN_00640408(
                    *reinterpret_cast<int32_t*>(iVar1), puVar3[0],
                    static_cast<uint32_t>(param_3), param_4));
            }
        }
    }
    return 0x8876086cu;
}

// ---------------------------------------------------------------------------
// 0x64fb85 — observed shape
// Lock for write: state (2,3,param_4,4,4); software dispatch FUN_00649425,
// hardware path FUN_0063faf9 then release.
// ---------------------------------------------------------------------------
int32_t FUN_0064fb85(void* self, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    uint32_t* puVar3;

    if (static_cast<int32_t>(param_2) < 0) {
        puVar3 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(~param_2));
    } else {
        uint8_t* dev = *reinterpret_cast<uint8_t**>(base + 0xc4);
        *reinterpret_cast<uint32_t*>(dev + 4) = 2;
        *reinterpret_cast<uint32_t*>(dev + 0) = 3;
        *reinterpret_cast<uint32_t*>(dev + 0x10) = param_4;
        *reinterpret_cast<uint32_t*>(dev + 0x14) = 4;
        *reinterpret_cast<uint32_t*>(dev + 0x18) = 4;
        puVar3 = reinterpret_cast<uint32_t*>(FUN_0064e847(param_2, 1, 1));
        if (puVar3 == nullptr) {
            return -0x7789f794;
        }
    }

    uint8_t* iVar2 = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(puVar3[1]));
    if (*reinterpret_cast<int32_t*>(iVar2 + 4) != 2 ||
        *reinterpret_cast<uint32_t*>(iVar2 + 0x10) < param_4 ||
        puVar3[2] != 0xffffffffu) {
        return -0x7789f794;
    }

    if (*reinterpret_cast<int32_t*>(base + 0x3c) == 3) {
        return FUN_00649425(~reinterpret_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar3)),
                            param_3, param_4);
    }

    int32_t iVar3 = FUN_0063faf9(*reinterpret_cast<int32_t*>(iVar2), puVar3[0], param_3, param_4);
    if (iVar3 < 0) {
        return iVar3;
    }
    return static_cast<int32_t>(FUN_006431b5(puVar3));
}

// ---------------------------------------------------------------------------
// 0x64fc25 — observed shape
// Plain read variant: resolve, require format-2 surface with nonzero
// +0x10 >= param_4 and no sub-resource, then FUN_0063fd69.
// ---------------------------------------------------------------------------
uint32_t FUN_0064fc25(uint32_t param_1, uint32_t param_2, int32_t param_3, uint32_t param_4)
{
    (void)param_1;
    if (param_4 == 0) {
        return 0;
    }
    if (param_3 != 0) {
        uint32_t* puVar3 = reinterpret_cast<uint32_t*>(FUN_0064e847(param_2, 1, 0));
        if (puVar3 != nullptr) {
            uint8_t* iVar1 = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(puVar3[1]));
            if (*reinterpret_cast<uint32_t*>(iVar1 + 0x10) != 0 &&
                puVar3[2] == 0xffffffffu &&
                param_4 <= *reinterpret_cast<uint32_t*>(iVar1 + 0x10) &&
                *reinterpret_cast<int32_t*>(iVar1 + 4) == 2) {
                return static_cast<uint32_t>(FUN_0063fd69(
                    *reinterpret_cast<int32_t*>(iVar1), puVar3[0],
                    static_cast<uint32_t>(param_3), param_4));
            }
        }
    }
    return 0x8876086cu;
}

// ---------------------------------------------------------------------------
// 0x64fc84 — observed shape
// Lock for write: state (2,3,param_4,4,4); software dispatch FUN_006494ec,
// hardware path FUN_0064007b then release.
// ---------------------------------------------------------------------------
int32_t FUN_0064fc84(void* self, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    uint32_t* puVar3;

    if (static_cast<int32_t>(param_2) < 0) {
        puVar3 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(~param_2));
    } else {
        uint8_t* dev = *reinterpret_cast<uint8_t**>(base + 0xc4);
        *reinterpret_cast<uint32_t*>(dev + 4) = 2;
        *reinterpret_cast<uint32_t*>(dev + 0) = 3;
        *reinterpret_cast<uint32_t*>(dev + 0x10) = param_4;
        *reinterpret_cast<uint32_t*>(dev + 0x14) = 4;
        *reinterpret_cast<uint32_t*>(dev + 0x18) = 4;
        puVar3 = reinterpret_cast<uint32_t*>(FUN_0064e847(param_2, 1, 1));
        if (puVar3 == nullptr) {
            return -0x7789f794;
        }
    }

    uint8_t* iVar2 = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(puVar3[1]));
    if (*reinterpret_cast<int32_t*>(iVar2 + 4) != 2 ||
        *reinterpret_cast<uint32_t*>(iVar2 + 0x10) < param_4 ||
        puVar3[2] != 0xffffffffu) {
        return -0x7789f794;
    }

    if (*reinterpret_cast<int32_t*>(base + 0x3c) == 3) {
        return FUN_006494ec(~reinterpret_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar3)),
                            param_3, param_4);
    }

    int32_t iVar3 = FUN_0064007b(*reinterpret_cast<int32_t*>(iVar2), puVar3[0], param_3, param_4);
    if (iVar3 < 0) {
        return iVar3;
    }
    return static_cast<int32_t>(FUN_006431b5(puVar3));
}

// ---------------------------------------------------------------------------
// 0x64fd24 — observed shape
// Plain read variant: resolve, require format-2 surface with nonzero
// +0x10 >= param_4 and no sub-resource, then FUN_006402aa.
// ---------------------------------------------------------------------------
uint32_t FUN_0064fd24(uint32_t param_1, uint32_t param_2, int32_t param_3, uint32_t param_4)
{
    (void)param_1;
    if (param_4 == 0) {
        return 0;
    }
    if (param_3 != 0) {
        uint32_t* puVar3 = reinterpret_cast<uint32_t*>(FUN_0064e847(param_2, 1, 0));
        if (puVar3 != nullptr) {
            uint8_t* iVar1 = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(puVar3[1]));
            if (*reinterpret_cast<uint32_t*>(iVar1 + 0x10) != 0 &&
                puVar3[2] == 0xffffffffu &&
                param_4 <= *reinterpret_cast<uint32_t*>(iVar1 + 0x10) &&
                *reinterpret_cast<int32_t*>(iVar1 + 4) == 2) {
                return static_cast<uint32_t>(FUN_006402aa(
                    *reinterpret_cast<int32_t*>(iVar1), puVar3[0],
                    static_cast<uint32_t>(param_3), param_4));
            }
        }
    }
    return 0x8876086cu;
}

// ---------------------------------------------------------------------------
// 0x64fd83 — observed shape
// Partial-update lock: state (2,3,0,4,4); require surface kind 2 and,
// when the size field is nonzero, no sub-resource. Software dispatch
// FUN_00649197, hardware path FUN_0063fb92 (result ignored) then release.
// ---------------------------------------------------------------------------
uint32_t FUN_0064fd83(void* self, uint32_t param_2, uint32_t param_3)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    uint32_t* puVar4;

    if (static_cast<int32_t>(param_2) < 0) {
        puVar4 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(~param_2));
    } else {
        uint8_t* dev = *reinterpret_cast<uint8_t**>(base + 0xc4);
        *reinterpret_cast<uint32_t*>(dev + 4) = 2;
        *reinterpret_cast<uint32_t*>(dev + 0) = 3;
        *reinterpret_cast<uint32_t*>(dev + 0x10) = 0;
        *reinterpret_cast<uint32_t*>(dev + 0x14) = 4;
        *reinterpret_cast<uint32_t*>(dev + 0x18) = 4;
        puVar4 = reinterpret_cast<uint32_t*>(FUN_0064e847(param_2, 1, 1));
        if (puVar4 == nullptr) {
            return 0x8876086cu;
        }
    }

    uint8_t* iVar2 = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(puVar4[1]));
    if (*reinterpret_cast<int32_t*>(iVar2 + 4) != 2 ||
        (*reinterpret_cast<int32_t*>(iVar2 + 0x10) != 0 && puVar4[2] == 0xffffffffu)) {
        return 0x8876086cu;
    }

    if (*reinterpret_cast<int32_t*>(base + 0x3c) == 3) {
        return static_cast<uint32_t>(FUN_00649197(
            ~reinterpret_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar4)), param_3));
    }

    FUN_0063fb92(*reinterpret_cast<int32_t*>(iVar2), puVar4[0], param_3);
    return static_cast<uint32_t>(FUN_006431b5(puVar4));
}

// ---------------------------------------------------------------------------
// 0x64fe1b — observed shape
// Read-only helper: resolve, reject when the surface reports a size with
// a live sub-resource or has kind != 2, else FUN_0063fee8 with count 1.
// ---------------------------------------------------------------------------
uint32_t FUN_0064fe1b(uint32_t param_1, uint32_t param_2, uint32_t param_3)
{
    (void)param_1;
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(FUN_0064e847(param_2, 1, 0));
    if (puVar2 == nullptr) {
        return 0x8876086cu;
    }
    uint8_t* iVar1 = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(puVar2[1]));
    if ((*reinterpret_cast<int32_t*>(iVar1 + 0x10) != 0 && puVar2[2] == 0xffffffffu) ||
        *reinterpret_cast<int32_t*>(iVar1 + 4) != 2) {
        return 0x8876086cu;
    }
    return static_cast<uint32_t>(FUN_0063fee8(*reinterpret_cast<int32_t*>(iVar1), puVar2[0],
                                              param_3, 1));
}

// ---------------------------------------------------------------------------
// 0x64fe63 — observed shape
// Partial-update lock: state (2,3,0,4,4); require surface kind 2 and,
// when the size field is nonzero, no sub-resource. Software dispatch
// FUN_0064939b, hardware path FUN_0063faf9 with count 1 then release.
// ---------------------------------------------------------------------------
int32_t FUN_0064fe63(void* self, uint32_t param_2, uint32_t param_3)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    uint32_t* puVar3;

    if (static_cast<int32_t>(param_2) < 0) {
        puVar3 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(~param_2));
    } else {
        uint8_t* dev = *reinterpret_cast<uint8_t**>(base + 0xc4);
        *reinterpret_cast<uint32_t*>(dev + 4) = 2;
        *reinterpret_cast<uint32_t*>(dev + 0) = 3;
        *reinterpret_cast<uint32_t*>(dev + 0x10) = 0;
        *reinterpret_cast<uint32_t*>(dev + 0x14) = 4;
        *reinterpret_cast<uint32_t*>(dev + 0x18) = 4;
        puVar3 = reinterpret_cast<uint32_t*>(FUN_0064e847(param_2, 1, 1));
        if (puVar3 == nullptr) {
            return -0x7789f794;
        }
    }

    uint8_t* iVar2 = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(puVar3[1]));
    if (*reinterpret_cast<int32_t*>(iVar2 + 4) != 2 ||
        (*reinterpret_cast<int32_t*>(iVar2 + 0x10) != 0 && puVar3[2] == 0xffffffffu)) {
        return -0x7789f794;
    }

    if (*reinterpret_cast<int32_t*>(base + 0x3c) == 3) {
        return FUN_0064939b(~reinterpret_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar3)),
                            param_3);
    }

    int32_t iVar3 = FUN_0063faf9(*reinterpret_cast<int32_t*>(iVar2), puVar3[0], param_3, 1);
    if (iVar3 < 0) {
        return iVar3;
    }
    return static_cast<int32_t>(FUN_006431b5(puVar3));
}

// ---------------------------------------------------------------------------
// 0x64ff04 — observed shape
// Read-only helper: reject null out pointer, unresolved handle, or a
// surface that reports a size together with a live sub-resource; then
// FUN_0063fd69 with count 1.
// ---------------------------------------------------------------------------
uint32_t FUN_0064ff04(uint32_t param_1, uint32_t param_2, int32_t param_3)
{
    (void)param_1;
    if (param_3 == 0) {
        return 0x8876086cu;
    }
    uint32_t* puVar1 = reinterpret_cast<uint32_t*>(FUN_0064e847(param_2, 1, 0));
    if (puVar1 == nullptr) {
        return 0x8876086cu;
    }
    if (*reinterpret_cast<int32_t*>(static_cast<uintptr_t>(puVar1[1]) + 0x10) != 0 &&
        puVar1[2] == 0xffffffffu) {
        return 0x8876086cu;
    }
    return static_cast<uint32_t>(FUN_0063fd69(static_cast<int32_t>(puVar1[1]), puVar1[0],
                                             static_cast<uint32_t>(param_3), 1));
}

// Saturating float->byte conversion used by the color pack. The provider
// listing renders the x87 min/max test as: value < 1.0 truncates toward
// zero (0 across the finite [0,1) range), otherwise the byte is 0xff.
static uint32_t color_channel_byte(float v)
{
    if (v < 1.0f) {
        return static_cast<uint32_t>(x87_ftol(v));
    }
    return 0xffu;
}

// ---------------------------------------------------------------------------
// 0x64ff4c — observed shape
// Update a resolved surface from floats. Format 3 copies floats, format 1
// writes 0/1 words, format 2 writes rounded ints, or — for a single-word
// surface — packs four saturating channels into one ARGB word.
// ---------------------------------------------------------------------------
uint32_t FUN_0064ff4c(void* self, uint32_t param_2, float* param_3)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    uint8_t* piVar8;

    if (static_cast<int32_t>(param_2) < 0) {
        piVar8 = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(~param_2));
    } else {
        uint8_t* dev = *reinterpret_cast<uint8_t**>(base + 0xc4);
        *reinterpret_cast<uint32_t*>(dev + 4) = 1;
        *reinterpret_cast<uint32_t*>(dev + 0) = 3;
        *reinterpret_cast<uint32_t*>(dev + 0x10) = 0;
        *reinterpret_cast<uint32_t*>(dev + 0x14) = 4;
        *reinterpret_cast<uint32_t*>(dev + 0x18) = 1;
        piVar8 = reinterpret_cast<uint8_t*>(FUN_0064e847(param_2, 1, 1));
        if (piVar8 == nullptr) {
            return 0x8876086cu;
        }
    }

    uint8_t* piVar1 = *reinterpret_cast<uint8_t**>(piVar8 + 4);
    if ((*reinterpret_cast<int32_t*>(piVar1 + 0x10) != 0 &&
         *reinterpret_cast<int32_t*>(piVar8 + 8) == -1) ||
        (*reinterpret_cast<int32_t*>(piVar1 + 4) != 1 &&
         *reinterpret_cast<int32_t*>(piVar1 + 4) != 0)) {
        return 0x8876086cu;
    }

    if (*reinterpret_cast<int32_t*>(base + 0x3c) == 3) {
        return static_cast<uint32_t>(FUN_00649053(
            ~reinterpret_cast<uint32_t>(reinterpret_cast<uintptr_t>(piVar8)), param_3));
    }

    uint32_t uVar6 = *reinterpret_cast<uint32_t*>(piVar1 + 0x14);
    int32_t  iVar5 = *reinterpret_cast<int32_t*>(piVar1 + 0);
    uint8_t* buffer = *reinterpret_cast<uint8_t**>(piVar8 + 0);

    if (iVar5 == 3) {
        float* pfVar9 = reinterpret_cast<float*>(buffer);
        for (; uVar6 != 0; --uVar6) {
            *pfVar9 = *param_3;
            ++param_3;
            ++pfVar9;
        }
    } else if (iVar5 == 2) {
        if (uVar6 == 1) {
            uint32_t a = color_channel_byte(param_3[3]);
            uint32_t r = color_channel_byte(param_3[0]);
            uint32_t g = color_channel_byte(param_3[1]);
            uint32_t b = color_channel_byte(param_3[2]);
            *reinterpret_cast<uint32_t*>(buffer) = ((a << 8 | r) << 8 | g) << 8 | b;
        } else if (uVar6 != 0) {
            uint32_t uVar7 = 0;
            do {
                *reinterpret_cast<int32_t*>(buffer + uVar7 * 4) = x87_round_to_int(param_3[uVar7]);
                ++uVar7;
            } while (uVar7 < uVar6);
        }
    } else if (iVar5 == 1) {
        uint32_t uVar7 = 0;
        if (uVar6 != 0) {
            do {
                *reinterpret_cast<uint32_t*>(buffer + uVar7 * 4) =
                    (param_3[uVar7] != 0.0f) ? 1u : 0u;
                ++uVar7;
            } while (uVar7 < uVar6);
        }
    } else {
        return 0x8876086cu;
    }

    return static_cast<uint32_t>(FUN_006431b5(piVar8));
}

// ---------------------------------------------------------------------------
// 0x6501ac — observed shape
// Read a resolved surface back into floats. Requires a live resource
// (+0x10 != 0 means no sub-resource) and kind 0 or 1 plus +0x18 == 1;
// clears four floats, then per format writes 0/1, unpacks one ARGB word
// with scale 0.003921569, integer values, or raw floats. Width is
// min(+0x14, 4).
// ---------------------------------------------------------------------------
uint32_t FUN_006501ac(uint32_t param_1, uint32_t param_2, float* param_3)
{
    (void)param_1;
    if (param_3 == nullptr) {
        return 0x8876086cu;
    }
    uint8_t* piVar3 = reinterpret_cast<uint8_t*>(FUN_0064e847(param_2, 1, 0));
    if (piVar3 == nullptr) {
        return 0x8876086cu;
    }
    uint8_t* piVar1 = *reinterpret_cast<uint8_t**>(piVar3 + 4);
    if (!(*reinterpret_cast<int32_t*>(piVar1 + 0x10) == 0 ||
          *reinterpret_cast<int32_t*>(piVar3 + 8) != -1)) {
        return 0x8876086cu;
    }
    int32_t kind = *reinterpret_cast<int32_t*>(piVar1 + 4);
    if (!(-1 < kind && kind < 2)) {
        return 0x8876086cu;
    }
    if (*reinterpret_cast<int32_t*>(piVar1 + 0x18) != 1) {
        return 0x8876086cu;
    }

    uint32_t uVar5 = *reinterpret_cast<uint32_t*>(piVar1 + 0x14);
    int32_t  iVar2 = *reinterpret_cast<int32_t*>(piVar1 + 0);
    if (uVar5 > 4) {
        uVar5 = 4;
    }
    param_3[0] = 0.0f;
    param_3[1] = 0.0f;
    param_3[2] = 0.0f;
    param_3[3] = 0.0f;
    uint8_t* buffer = *reinterpret_cast<uint8_t**>(piVar3 + 0);

    if (iVar2 == 1) {
        uint32_t uVar4 = 0;
        if (uVar5 == 0) {
            return 0;
        }
        do {
            param_3[uVar4] =
                static_cast<float>(*reinterpret_cast<int32_t*>(buffer + uVar4 * 4) != 0);
            ++uVar4;
        } while (uVar4 < uVar5);
        return 0;
    }
    if (iVar2 == 2) {
        if (uVar5 == 1) {
            uint32_t packed = *reinterpret_cast<uint32_t*>(buffer);
            param_3[0] = static_cast<float>(packed >> 0x10 & 0xff) * 0.003921569f;
            param_3[1] = static_cast<float>(packed >> 8 & 0xff) * 0.003921569f;
            param_3[2] = static_cast<float>(packed & 0xff) * 0.003921569f;
            param_3[3] = static_cast<float>(packed >> 0x18) * 0.003921569f;
            return 0;
        }
        uint32_t uVar4 = 0;
        if (uVar5 == 0) {
            return 0;
        }
        do {
            param_3[uVar4] = static_cast<float>(*reinterpret_cast<int32_t*>(buffer + uVar4 * 4));
            ++uVar4;
        } while (uVar4 < uVar5);
        return 0;
    }
    if (iVar2 == 3) {
        uint32_t uVar4 = 0;
        if (uVar5 == 0) {
            return 0;
        }
        do {
            param_3[uVar4] = *reinterpret_cast<float*>(buffer + uVar4 * 4);
            ++uVar4;
        } while (uVar4 < uVar5);
        return 0;
    }
    return 0x8876086cu;
}

// ---------------------------------------------------------------------------
// 0x6502ff — observed shape
// States query: program state (4,4,0); require a resolved kind-4 resource
// whose format is also 4 and that has no live sub-resource. Software
// dispatch FUN_006495a9, otherwise FUN_0063f9ca against the device slot's
// +0x40 field followed by release on non-negative status.
// ---------------------------------------------------------------------------
int32_t FUN_006502ff(void* self, uint32_t param_2, uint32_t param_3)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);

    uint8_t* dev = *reinterpret_cast<uint8_t**>(base + 0xc4);
    *reinterpret_cast<uint32_t*>(dev + 4) = 4;
    *reinterpret_cast<uint32_t*>(dev + 0) = 4;
    *reinterpret_cast<uint32_t*>(dev + 0x10) = 0;

    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(FUN_0064e847(param_2, 1, 1));
    uint8_t* piVar1;
    int32_t  iVar3;

    if (puVar2 == nullptr) {
        iVar3 = -0x7789f794;
    } else {
        piVar1 = *reinterpret_cast<uint8_t**>(reinterpret_cast<uint8_t*>(puVar2) + 4);
        if ((*reinterpret_cast<int32_t*>(piVar1 + 0x10) != 0 &&
             puVar2[2] == 0xffffffffu) ||
            *reinterpret_cast<int32_t*>(piVar1 + 4) != 4 ||
            *reinterpret_cast<int32_t*>(piVar1 + 0) != 4) {
            iVar3 = -0x7789f794;
        } else if (*reinterpret_cast<int32_t*>(base + 0x3c) == 3) {
            iVar3 = FUN_006495a9(~reinterpret_cast<uint32_t>(
                                     reinterpret_cast<uintptr_t>(puVar2)), param_3);
        } else {
            int32_t deviceArray = *reinterpret_cast<int32_t*>(base + 0xb0);
            uint32_t slotField = *reinterpret_cast<uint32_t*>(
                *reinterpret_cast<int32_t*>(deviceArray + static_cast<int32_t>(puVar2[5] * 4)) + 0x40);
            iVar3 = FUN_0063f9ca(param_3, puVar2[0], slotField);
            if (-1 < iVar3) {
                iVar3 = FUN_006431b5(puVar2);
            }
        }
    }
    return iVar3;
}

// ---------------------------------------------------------------------------
// 0x65039a — observed shape
// Look up a device-slot entry at self+0x18 + index*0x18 and return the
// object's virtual +0xc result (0 when the entry is empty). Requires a
// resolved kind-4 resource of format 4 with no live sub-resource.
// ---------------------------------------------------------------------------
uint32_t FUN_0065039a(void* self, uint32_t param_2, uint32_t* param_3)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(self);
    uint32_t local_8 = 0;

    if (param_3 == nullptr) {
        local_8 = 0x8876086cu;
    } else {
        uint32_t* puVar3 = reinterpret_cast<uint32_t*>(FUN_0064e847(param_2, 1, 0));
        uint8_t* piVar1;
        if (puVar3 == nullptr) {
            local_8 = 0x8876086cu;
        } else {
            piVar1 = *reinterpret_cast<uint8_t**>(reinterpret_cast<uint8_t*>(puVar3) + 4);
            if ((*reinterpret_cast<int32_t*>(piVar1 + 0x10) != 0 &&
                 puVar3[2] == 0xffffffffu) ||
                *reinterpret_cast<int32_t*>(piVar1 + 4) != 4 ||
                *reinterpret_cast<int32_t*>(piVar1 + 0) != 4) {
                local_8 = 0x8876086cu;
            } else {
                int32_t deviceArray = *reinterpret_cast<int32_t*>(base + 0xb0);
                int32_t slotField = *reinterpret_cast<int32_t*>(
                    *reinterpret_cast<int32_t*>(deviceArray +
                                                static_cast<int32_t>(puVar3[5] * 4)) + 0x40);
                int32_t iVar4 = static_cast<int32_t>(puVar3[0]);
                if (slotField != 0) {
                    iVar4 = *reinterpret_cast<int32_t*>(
                        static_cast<uintptr_t>(*reinterpret_cast<int32_t*>(slotField + 8)) +
                        iVar4 * 4);
                }
                int32_t entry = *reinterpret_cast<int32_t*>(base + 0x18) + iVar4 * 0x18;
                if (*reinterpret_cast<int32_t*>(entry + 4) == 0) {
                    *param_3 = 0;
                } else {
                    int32_t* obj = *reinterpret_cast<int32_t**>(entry + 4);
                    using VFn = uint32_t (*)(int32_t*);
                    VFn fn = *reinterpret_cast<VFn*>(
                        static_cast<uintptr_t>(*reinterpret_cast<int32_t*>(obj) + 0xc));
                    *param_3 = fn(obj);
                }
            }
        }
    }
    return local_8;
}
