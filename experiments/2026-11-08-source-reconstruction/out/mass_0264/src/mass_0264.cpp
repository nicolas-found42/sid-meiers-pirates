// Reconstruction batch mass_0264 — Sid Meier's Pirates! (2004), PE32 i386.
// Candidate definitions translated from Ghidra 12.2 pseudocode (one file per function).
// Provider register receivers (in_ECX / in_ESI / in_EDI / in_EBX / in_EAX) are modeled as
// an explicit `self` parameter; no `this` is used in free functions.

#include <cstdint>
#include <cstddef>
#include <cmath>
#include <cstring>
#include <new>
#include <windows.h>

// ---------------------------------------------------------------------------
// Externs referenced by the listings in this batch.
// ---------------------------------------------------------------------------
extern void* FUN_00533c78(std::uint32_t n);                 // allocator
extern void  FUN_004127b0(void* p, std::uint32_t elem, std::uint32_t count, void* ctor);
extern void  FUN_005fbd85(void* p);                         // element ctor
extern void  FUN_005f6015(void* p);                         // element ctor
extern std::uint32_t FUN_005fbd9b(std::uint32_t a, std::uint32_t b, std::uint32_t c);
extern void  FUN_005fe8fc(std::uint32_t mode);
extern void  FUN_005f8ea2(int enter);

extern std::uint32_t FUN_0060a6fc(std::uint32_t p);
extern std::uint32_t FUN_006013a6(std::uint32_t p);

extern std::int32_t FUN_005fd056();
extern std::int32_t FUN_005fd160();
extern std::int32_t FUN_005fd233();
extern std::int32_t FUN_005fd406();
extern std::int32_t FUN_005fd5dc();
extern std::int32_t FUN_005fd9a4();
extern std::int32_t FUN_005fde98();
extern std::int32_t FUN_005fe23a();
extern std::int32_t FUN_005fe94b();

extern std::int32_t FUN_005ff6e1(std::int32_t* a, std::int32_t* b);
extern void FUN_005ff7c0(void* self);
extern void FUN_005ff879(void* self);
extern std::int32_t FUN_005ff8a2(void* self, std::uint32_t* p1, std::int32_t* p2,
                                 std::uint32_t p3, std::uint32_t* p4, std::uint32_t p5,
                                 std::uint32_t p6);
extern std::int32_t FUN_005ffd96(void* self, std::uint32_t* p1, std::int32_t* p2,
                                 std::uint32_t p3, std::uint32_t* p4, std::uint32_t p5,
                                 std::uint32_t p6);
extern std::int32_t FUN_005fefd1(void* self);
extern std::int32_t FUN_0060064e(void* self);
extern void FUN_0060010b(void* self);
extern std::uint32_t FUN_00600136(void* self, std::int32_t param_1);

extern double FUN_0065427e(float v);

// Globals observed in the listings.
extern void* PTR_FUN_006dddd0;
extern void* PTR_FUN_006de0d8;
extern void* DAT_00719320;
extern void* DAT_007192a0;
extern std::uint32_t DAT_006dd2d4;
extern std::uint32_t DAT_006dd2e4;
extern float DAT_006dd5d0[];
extern float DAT_006dd5d4[];
extern float DAT_006dd9d0[];
extern float DAT_006dd9d4[];

// ---------------------------------------------------------------------------
// Blend-setup: validates two render states, builds edge-count/accumulator tables from the
// two index buffers, accumulates weighted vertex contributions, clamps by blend mode,
// then releases each accumulated vertex buffer through its vtable.
// ---------------------------------------------------------------------------
// 0x5fefd1 — observed shape
std::uint32_t FUN_005fefd1(void* self_arg) {
    std::int32_t* self = static_cast<std::int32_t*>(self_arg);
    std::int32_t* local_1c = nullptr;
    std::int32_t* local_c = nullptr;
    std::int32_t* local_18 = nullptr;
    void* local_10 = nullptr;
    std::uint32_t uVar13 = 0;

    if (*reinterpret_cast<std::int32_t*>(self[1] + 0x70) != 1 ||
        *reinterpret_cast<std::int32_t*>(*self + 0x70) != 1) {
        return 0x80004005u;
    }

    std::uint32_t uVar16 = static_cast<std::uint32_t>(self[2]);
    std::int32_t* piVar5 = static_cast<std::int32_t*>(FUN_005fbd9b(
        *reinterpret_cast<std::uint32_t*>(*self + 0x68),
        *reinterpret_cast<std::uint32_t*>(self[1] + 0x68),
        (~(uVar16 >> 0x10)) & 1u));
    local_1c = static_cast<std::int32_t*>(FUN_005fbd9b(
        *reinterpret_cast<std::uint32_t*>(*self + 0x6c),
        *reinterpret_cast<std::uint32_t*>(self[1] + 0x6c),
        (~(uVar16 >> 0x11)) & 1u));

    if (piVar5 == nullptr || local_1c == nullptr) {
        uVar13 = 0x80004005u;
    } else {
        std::int32_t iVar3 = *piVar5;              // first index buffer length
        std::int32_t iVar4 = *local_1c;            // second index buffer length
        std::int32_t iVar9 = *reinterpret_cast<std::int32_t*>(self[1] + 0x6c);

        local_c = static_cast<std::int32_t*>(
            FUN_00533c78(static_cast<std::uint32_t>(iVar9 * 0xc + 4)));
        if (local_c != nullptr) {
            *local_c = iVar9;
            local_c += 1;
            FUN_004127b0(local_c, 0xc, static_cast<std::uint32_t>(iVar9),
                         reinterpret_cast<void*>(&FUN_005fbd85));
        }

        if (local_c != nullptr) {
            iVar9 = *reinterpret_cast<std::int32_t*>(*self + 0x68);
            local_10 = FUN_00533c78(static_cast<std::uint32_t>(iVar9 << 4));
            if (local_10 != nullptr) {
                FUN_004127b0(local_10, 0x10, static_cast<std::uint32_t>(iVar9),
                             reinterpret_cast<void*>(&FUN_005f6015));
            }

            if (local_10 != nullptr) {
                // Pass 1: count distinct use of each target vertex (slot [idx*3 + 2]).
                std::int32_t* piVar17 = local_1c + 1;
                while (piVar17 < reinterpret_cast<std::int32_t*>(
                                    iVar4 + reinterpret_cast<std::intptr_t>(local_1c))) {
                    std::int32_t* piVar10 = reinterpret_cast<std::int32_t*>(
                        *piVar17 + reinterpret_cast<std::intptr_t>(piVar17));
                    for (std::int32_t* piVar7 = piVar17 + 1; piVar17 = piVar10, piVar7 < piVar10;
                         piVar7 += 2) {
                        local_c[*piVar7 * 3 + 2] = local_c[*piVar7 * 3 + 2] + 1;
                    }
                }

                // Pass 2: allocate/zero one vertex buffer per referenced index, accumulate.
                std::int32_t local_20 = 0;
                bool out_of_memory = false;
                piVar17 = local_1c + 1;
                while (!out_of_memory &&
                       piVar17 < reinterpret_cast<std::int32_t*>(
                                     iVar4 + reinterpret_cast<std::intptr_t>(local_1c))) {
                    std::int32_t* piVar10 = reinterpret_cast<std::int32_t*>(
                        *piVar17 + reinterpret_cast<std::intptr_t>(piVar17));
                    piVar17 += 1;

                    for (std::int32_t* piVar7 = piVar17; piVar7 < piVar10; piVar7 += 2) {
                        std::int32_t* piVar15 = local_c + *piVar7 * 3;
                        if (*piVar15 == 0) {
                            if (local_18 == nullptr) {
                                std::int32_t n = *reinterpret_cast<std::int32_t*>(self[1] + 0x68);
                                std::int32_t buf = static_cast<std::int32_t>(
                                    reinterpret_cast<std::intptr_t>(
                                        FUN_00533c78(static_cast<std::uint32_t>(n << 4))));
                                if (buf != 0) {
                                    FUN_004127b0(reinterpret_cast<void*>(buf), 0x10,
                                                 static_cast<std::uint32_t>(n),
                                                 reinterpret_cast<void*>(&FUN_005f6015));
                                }
                                *piVar15 = buf;
                                if (buf == 0) { out_of_memory = true; break; }
                            } else {
                                *piVar15 = *local_18;
                                *local_18 = 0;
                                local_18 = reinterpret_cast<std::int32_t*>(local_18[1]);
                            }
                            std::uint32_t* pu = reinterpret_cast<std::uint32_t*>(*piVar15);
                            for (std::int32_t k =
                                     (*reinterpret_cast<std::uint32_t*>(self[1] + 0x68) & 0xfffffffu)
                                     << 2;
                                 k != 0; --k) {
                                *pu++ = 0;
                            }
                        }
                    }
                    if (out_of_memory) break;

                    // (*(*in_ECX)[+4])(local_20, 0, local_10);
                    {
                        using SetFn = void (*)(void*, std::int32_t, std::int32_t, void*);
                        SetFn set_fn = *reinterpret_cast<SetFn*>(*self + 4);
                        set_fn(self, local_20, 0, local_10);
                    }

                    // Accumulate this edge's contribution into each target vertex buffer.
                    if (piVar5 + 1 < reinterpret_cast<std::int32_t*>(
                                          iVar3 + reinterpret_cast<std::intptr_t>(piVar5))) {
                        float* pfVar11 = reinterpret_cast<float*>(
                            reinterpret_cast<std::intptr_t>(local_10) + 8);
                        std::int32_t* piVar7 = piVar5 + 1;
                        do {
                            std::int32_t* piVar15 = reinterpret_cast<std::int32_t*>(
                                *piVar7 + reinterpret_cast<std::intptr_t>(piVar7));
                            if (piVar17 < piVar10) {
                                std::int32_t* local_8 = piVar17;
                                do {
                                    std::int32_t iVar9b = local_c[*local_8 * 3];
                                    for (std::int32_t* piVar8 = piVar7 + 1; piVar8 < piVar15;
                                         piVar8 += 2) {
                                        float fVar2 = static_cast<float>(piVar8[1]) *
                                                      static_cast<float>(local_8[1]);
                                        float* pf = reinterpret_cast<float*>(
                                            *piVar8 * 0x10 + iVar9b);
                                        *pf = fVar2 * pfVar11[-2] + *pf;
                                        pf = reinterpret_cast<float*>(*piVar8 * 0x10 + 4 + iVar9b);
                                        *pf = fVar2 * pfVar11[-1] + *pf;
                                        pf = reinterpret_cast<float*>(*piVar8 * 0x10 + 8 + iVar9b);
                                        *pf = fVar2 * *pfVar11 + *pf;
                                        pf = reinterpret_cast<float*>(*piVar8 * 0x10 + 0xc + iVar9b);
                                        *pf = fVar2 * pfVar11[1] + *pf;
                                    }
                                    local_8 += 2;
                                } while (local_8 < piVar10);
                            }
                            pfVar11 += 4;
                            piVar7 = piVar15;
                        } while (piVar15 < reinterpret_cast<std::int32_t*>(
                                               iVar3 + reinterpret_cast<std::intptr_t>(piVar5)));
                    }

                    // Release finished vertex buffers; clamp components per blend mode.
                    for (; piVar17 < piVar10; piVar17 += 2) {
                        std::int32_t* piVar15 = local_c + *piVar17 * 3;
                        std::int32_t* piVar7 = piVar15 + 2;
                        *piVar7 = *piVar7 - 1;
                        if (*piVar7 == 0) {
                            std::int32_t mode = *reinterpret_cast<std::int32_t*>(*self + 8);
                            if (mode == 1) {
                                std::uint32_t cnt = 0, off = 0;
                                const std::uint32_t total =
                                    *reinterpret_cast<std::uint32_t*>(self[1] + 0x68);
                                while (cnt < total) {
                                    for (int c = 0; c < 4; ++c) {
                                        float* pf = reinterpret_cast<float*>(*piVar15 + off + c * 4);
                                        float v = *pf;
                                        if (0.0f <= v) v = (1.0f <= v) ? 1.0f : v;
                                        else v = 0.0f;
                                        *pf = v;
                                    }
                                    ++cnt;
                                    off += 0x10;
                                }
                            } else if (mode == 2) {
                                // First three components clamp to [-1,1]; w clamps to [0,1].
                                std::uint32_t cnt = 0, off = 0;
                                const std::uint32_t total =
                                    *reinterpret_cast<std::uint32_t*>(self[1] + 0x68);
                                while (cnt < total) {
                                    for (int c = 0; c < 3; ++c) {
                                        float* pf = reinterpret_cast<float*>(*piVar15 + off + c * 4);
                                        float v = *pf;
                                        if (-1.0f <= v) v = (1.0f <= v) ? 1.0f : v;
                                        else v = -1.0f;
                                        *pf = v;
                                    }
                                    {
                                        float* pf = reinterpret_cast<float*>(*piVar15 + off + 0xc);
                                        float v = *pf;
                                        if (0.0f <= v) v = (1.0f <= v) ? 1.0f : v;
                                        else v = 0.0f;
                                        *pf = v;
                                    }
                                    ++cnt;
                                    off += 0x10;
                                }
                            } else if (mode == 3) {
                                std::uint32_t cnt = 0, off = 0;
                                const std::uint32_t total =
                                    *reinterpret_cast<std::uint32_t*>(self[1] + 0x68);
                                while (cnt < total) {
                                    for (int c = 0; c < 4; ++c) {
                                        float* pf = reinterpret_cast<float*>(*piVar15 + off + c * 4);
                                        float v = *pf;
                                        if (-1.0f <= v) v = (1.0f <= v) ? 1.0f : v;
                                        else v = -1.0f;
                                        *pf = v;
                                    }
                                    ++cnt;
                                    off += 0x10;
                                }
                            }

                            // (*(*(in_ECX[1]) + 8))(*piVar17, 0, *piVar15);
                            {
                                using RelFn = void (*)(std::int32_t*, std::int32_t, std::int32_t);
                                RelFn rel = *reinterpret_cast<RelFn*>(self[1] + 8);
                                rel(reinterpret_cast<std::int32_t*>(self), *piVar17, *piVar15);
                            }
                            piVar15[1] = static_cast<std::int32_t>(
                                reinterpret_cast<std::intptr_t>(local_18));
                            local_18 = piVar15;
                        }
                    }

                    local_20 += 1;
                    piVar17 = piVar10;
                }

                if (!out_of_memory) {
                    uVar13 = 0;
                    goto cleanup;
                }
            }
        }
        uVar13 = 0x8007000eu;
    }

cleanup:
    if (local_c != nullptr) FUN_005fe8fc(3);
    operator delete(local_1c);
    operator delete(piVar5);
    operator delete(local_10);
    operator delete(nullptr);
    return uVar13;
}

// ---------------------------------------------------------------------------
// Two-stage init: validates the format word, wires capability flags into both device
// objects, creates wrappers, then runs the eight sub-initializers in order.
// ---------------------------------------------------------------------------
// 0x5ff591 — observed shape
std::int32_t FUN_005ff591(void* self_arg, std::int32_t param_1, std::int32_t param_2,
                          std::uint32_t param_3) {
    std::int32_t* self = static_cast<std::int32_t*>(self_arg);
    std::int32_t iVar1;

    self[1] = 0;
    *self = 0;
    self[2] = static_cast<std::int32_t>(param_3);

    if (((param_3 & 0xffffu) == 0) || (5u < (param_3 & 0xffffu)) ||
        ((param_3 & 0xff800000u) != 0)) {
        return static_cast<std::int32_t>(0x88760c6cu);   // -0x7789f794
    }

    *reinterpret_cast<std::uint32_t*>(param_2 + 0x48) = param_3 & 0x200000u;
    *reinterpret_cast<std::uint32_t*>(param_1 + 0x48) = param_3 & 0x400000u;
    *reinterpret_cast<std::uint32_t*>(param_1 + 0x40) = param_3 & 0x80000u;
    *reinterpret_cast<std::uint32_t*>(param_1 + 0x44) = param_3 & 0x100000u;

    iVar1 = static_cast<std::int32_t>(FUN_0060a6fc(static_cast<std::uint32_t>(param_1)));
    self[1] = iVar1;
    if (iVar1 != 0) {
        iVar1 = static_cast<std::int32_t>(FUN_0060a6fc(static_cast<std::uint32_t>(param_2)));
        *self = iVar1;
        if (iVar1 != 0) {
            iVar1 = static_cast<std::int32_t>(FUN_006013a6(static_cast<std::uint32_t>(iVar1)));
            if (iVar1 < 0) goto cleanup;

            iVar1 = FUN_005fd056();
            if (iVar1 < 0) iVar1 = FUN_005fd160();
            if (iVar1 < 0) iVar1 = FUN_005fd233();
            if (iVar1 < 0) iVar1 = FUN_005fd406();
            if (iVar1 < 0) iVar1 = FUN_005fd5dc();
            if (iVar1 < 0) iVar1 = FUN_005fd9a4();
            if (iVar1 < 0) iVar1 = FUN_005fde98();
            if (iVar1 < 0) iVar1 = FUN_005fe23a();
            if (iVar1 < 0) iVar1 = FUN_005fefd1(self);
            if (iVar1 >= 0) {
                iVar1 = 0;
                goto cleanup;
            }
        }
    }
    iVar1 = static_cast<std::int32_t>(0x80004005u); // -0x7fffbffb

cleanup:
    if (self[1] != 0) {
        using ReleaseFn = void (*)(void*, std::uint32_t);
        ReleaseFn rel = *reinterpret_cast<ReleaseFn*>(self[1]);
        rel(reinterpret_cast<void*>(self), 1);
        self[1] = 0;
    }
    if (*self != 0) {
        using ReleaseFn = void (*)(void*, std::uint32_t);
        ReleaseFn rel = *reinterpret_cast<ReleaseFn*>(*self);
        rel(reinterpret_cast<void*>(self), 1);
        *self = 0;
    }
    return iVar1;
}

// ---------------------------------------------------------------------------
// Zero five dwords of the receiver (constructor-style reset).
// ---------------------------------------------------------------------------
// 0x5ff6ce — observed shape
void FUN_005ff6ce(void* self_arg) {
    std::int32_t* self = static_cast<std::int32_t*>(self_arg);
    *self = 0;
    self[1] = 0;
    self[2] = 0;
    self[3] = 0;
    self[4] = 0;
}

// ---------------------------------------------------------------------------
// Row-wise block copy between two locked surface descriptors: queries both formats,
// rounds the height up for DXn formats, copies min(pitch) bytes per row.
// NEEDS_MANUAL: the two data pointers used as copy source/dest (Ghidra local_10/local_18)
// are the out-parameters of the +0x34 lock calls that the listing elides; their concrete
// binding is not observable from this corpus file.
// ---------------------------------------------------------------------------
// 0x5ff6e1 — observed shape
std::int32_t FUN_005ff6e1(std::int32_t* param_1, std::int32_t* param_2) {
    std::uint32_t local_3c[7] = {0, 0, 0, 0, 0, 0, 0};
    std::uint32_t local_14 = 0;
    std::uint32_t local_1c = 0;
    std::uint32_t local_20 = 0;
    std::uint32_t local_c = 0;
    std::uint32_t local_8 = 0;
    void* local_10 = nullptr;   // source base from the +0x34 lock out-param
    void* local_18 = nullptr;   // destination base from the +0x34 lock out-param
    std::int32_t iVar1;

    {
        using GetDescFn = void (*)(std::int32_t*, std::uint32_t*);
        GetDescFn fn = *reinterpret_cast<GetDescFn*>(*param_1 + 0x30);
        fn(param_1, local_3c);
    }
    {
        using LockFn = std::int32_t (*)(std::int32_t*, std::uint32_t*, std::uint32_t, std::uint32_t);
        LockFn fn = *reinterpret_cast<LockFn*>(*param_1 + 0x34);
        iVar1 = fn(param_1, &local_14, 0, 0);
    }
    if (iVar1 < 0) return iVar1;

    {
        using LockFn = std::int32_t (*)(std::int32_t*, std::uint32_t*, std::uint32_t, std::uint32_t);
        LockFn fn = *reinterpret_cast<LockFn*>(*param_2 + 0x34);
        iVar1 = fn(param_2, &local_1c, 0, 0);
    }
    if (iVar1 < 0) {
        using UnlockFn = void (*)(std::int32_t*);
        UnlockFn fn = *reinterpret_cast<UnlockFn*>(*param_1 + 0x38);
        fn(param_1);
        return iVar1;
    }

    if (local_3c[0] == 0x31545844u || local_3c[0] == 0x32545844u ||
        local_3c[0] == 0x33545844u || local_3c[0] == 0x34545844u ||
        local_3c[0] == 0x35545844u) {
        local_20 = (local_20 + 3) >> 2;
    }

    local_c = local_1c;
    if (static_cast<std::int32_t>(local_14) <= static_cast<std::int32_t>(local_1c)) {
        local_c = local_14;
    }
    local_8 = 0;
    if (local_20 != 0) {
        do {
            std::uint32_t* puVar3 = static_cast<std::uint32_t*>(local_10);
            std::uint32_t* puVar4 = static_cast<std::uint32_t*>(local_18);
            for (std::uint32_t uVar2 = local_c >> 2; uVar2 != 0; --uVar2) *puVar4++ = *puVar3++;
            for (std::uint32_t uVar2 = local_c & 3; uVar2 != 0; --uVar2) {
                *reinterpret_cast<std::uint8_t*>(puVar4) =
                    *reinterpret_cast<std::uint8_t*>(puVar3);
                puVar3 = reinterpret_cast<std::uint32_t*>(
                    reinterpret_cast<std::intptr_t>(puVar3) + 1);
                puVar4 = reinterpret_cast<std::uint32_t*>(
                    reinterpret_cast<std::intptr_t>(puVar4) + 1);
            }
            local_10 = reinterpret_cast<void*>(reinterpret_cast<std::intptr_t>(local_10) + local_14);
            local_18 = reinterpret_cast<void*>(reinterpret_cast<std::intptr_t>(local_18) + local_1c);
            local_8 += 1;
        } while (local_8 < local_20);
    }

    iVar1 = 0;
    {
        using UnlockFn = void (*)(std::int32_t*);
        UnlockFn fn = *reinterpret_cast<UnlockFn*>(*param_2 + 0x38);
        fn(param_2);
    }
    {
        using UnlockFn = void (*)(std::int32_t*);
        UnlockFn fn = *reinterpret_cast<UnlockFn*>(*param_1 + 0x38);
        fn(param_1);
    }
    return iVar1;
}

// ---------------------------------------------------------------------------
// Teardown: unbind surfaces, optionally blit the staging surface into the target, then
// release the four owned surface slots.
// ---------------------------------------------------------------------------
// 0x5ff7c0 — observed shape
std::uint32_t FUN_005ff7c0(void* self_arg) {
    std::uint8_t* self = static_cast<std::uint8_t*>(self_arg);
    std::int32_t* piVar1;

    piVar1 = *reinterpret_cast<std::int32_t**>(self + 8);
    if (piVar1 == nullptr) piVar1 = *reinterpret_cast<std::int32_t**>(self + 4);
    if (piVar1 != nullptr) {
        using UnbindFn = void (*)(void*);
        UnbindFn fn = *reinterpret_cast<UnbindFn*>(*reinterpret_cast<std::int32_t*>(piVar1) + 0x38);
        fn(reinterpret_cast<void*>(piVar1));
    }

    if ((*reinterpret_cast<std::int32_t*>(self + 4) != 0) &&
        (*reinterpret_cast<std::int32_t*>(self + 8) != 0) &&
        (*reinterpret_cast<std::int32_t*>(self + 0x10) != 0) &&
        ((*self & 1u) == 0)) {
        FUN_005f8ea2(1);
        std::int32_t* surface = *reinterpret_cast<std::int32_t**>(self + 0x10);
        std::int32_t iVar2;
        {
            using BlitFn = std::int32_t (*)(void*, std::uint32_t, std::uint32_t,
                                            std::uint32_t, std::uint32_t);
            BlitFn fn = *reinterpret_cast<BlitFn*>(*reinterpret_cast<std::int32_t*>(surface) + 0x78);
            iVar2 = fn(reinterpret_cast<void*>(surface),
                       *reinterpret_cast<std::uint32_t*>(self + 8), 0,
                       *reinterpret_cast<std::uint32_t*>(self + 4), 0);
        }
        FUN_005f8ea2(0);
        if (iVar2 < 0) {
            FUN_005f8ea2(1);
            FUN_005ff6e1(*reinterpret_cast<std::int32_t**>(self + 8),
                         *reinterpret_cast<std::int32_t**>(self + 4));
            FUN_005f8ea2(0);
        }
    }

    std::int32_t* p8 = *reinterpret_cast<std::int32_t**>(self + 8);
    if (p8 != nullptr) {
        using ReleaseFn = void (*)(void*);
        ReleaseFn fn = *reinterpret_cast<ReleaseFn*>(*reinterpret_cast<std::int32_t*>(p8) + 8);
        fn(reinterpret_cast<void*>(p8));
        std::memset(self + 8, 0, 0x10);
    }
    std::int32_t* pc = *reinterpret_cast<std::int32_t**>(self + 0xc);
    if (pc != nullptr) {
        using ReleaseFn = void (*)(void*);
        ReleaseFn fn = *reinterpret_cast<ReleaseFn*>(*reinterpret_cast<std::int32_t*>(pc) + 8);
        fn(reinterpret_cast<void*>(pc));
        std::memset(self + 0xc, 0, 0x10);
    }
    std::int32_t* p10 = *reinterpret_cast<std::int32_t**>(self + 0x10);
    if (p10 != nullptr) {
        using ReleaseFn = void (*)(void*);
        ReleaseFn fn = *reinterpret_cast<ReleaseFn*>(*reinterpret_cast<std::int32_t*>(p10) + 8);
        fn(reinterpret_cast<void*>(p10));
        std::memset(self + 0x10, 0, 0x10);
    }
    std::int32_t* p4 = *reinterpret_cast<std::int32_t**>(self + 4);
    if (p4 != nullptr) {
        using ReleaseFn = void (*)(void*);
        ReleaseFn fn = *reinterpret_cast<ReleaseFn*>(*reinterpret_cast<std::int32_t*>(p4) + 8);
        fn(reinterpret_cast<void*>(p4));
        std::memset(self + 4, 0, 0x10);
    }
    return 0;
}

// ---------------------------------------------------------------------------
// One-dword reset of the receiver.
// ---------------------------------------------------------------------------
// 0x5ff873 — observed shape
void FUN_005ff873(void* self_arg) {
    *static_cast<std::int32_t*>(self_arg) = 0;
}

// ---------------------------------------------------------------------------
// Releases the owned interface: calls vtable+0x28 (finalize), then vtable+8 (release),
// and clears the owned slot.
// ---------------------------------------------------------------------------
// 0x5ff879 — observed shape
std::uint32_t FUN_005ff879(void* self_arg) {
    std::int32_t** self = static_cast<std::int32_t**>(self_arg);
    std::int32_t* piVar1 = *self;
    if (piVar1 != nullptr) {
        {
            using FinalizeFn = void (*)(void*);
            FinalizeFn fn = *reinterpret_cast<FinalizeFn*>(*piVar1 + 0x28);
            fn(static_cast<void*>(piVar1));
        }
        piVar1 = *self;
        if (piVar1 != nullptr) {
            {
                using ReleaseFn = void (*)(void*);
                ReleaseFn fn = *reinterpret_cast<ReleaseFn*>(*piVar1 + 8);
                fn(static_cast<void*>(piVar1));
            }
            *self = nullptr;
        }
    }
    return 0;
}

// Surface descriptor as produced by the method at vtable+0x30.
// Offsets follow the frame layout observed in the listing.
struct SurfaceDesc {
    std::uint32_t format;            // +0x00
    std::uint32_t type;              // +0x04
    std::uint32_t usage;             // +0x08
    std::uint32_t pool;              // +0x0c
    std::uint32_t multiSampleType;   // +0x10
    std::uint32_t multiSampleQuality;// +0x14
    std::uint32_t width;             // +0x18
    std::uint32_t height;            // +0x1c
    std::uint32_t unk20;             // +0x20
    std::uint32_t unk24;             // +0x24
    std::uint32_t unk28;             // +0x28
    std::uint32_t unk2c;             // +0x2c
    std::uint32_t unk30;             // +0x30
    std::uint32_t unk34;             // +0x34
    std::uint32_t unk38;             // +0x38
    std::uint32_t unk3c;             // +0x3c
    std::uint32_t unk40;             // +0x40
    std::uint32_t unk44;             // +0x44
    std::uint32_t unk48;             // +0x48
};

// Surface rect as passed to / returned by the lock methods.
struct SurfaceRect {
    std::int32_t left;    // +0x00
    std::int32_t top;     // +0x04
    std::int32_t right;   // +0x08
    std::int32_t bottom;  // +0x0c
    std::int32_t v0;      // +0x10
    std::int32_t v1;      // +0x14
};

static bool is_dxt(std::uint32_t fmt) {
    return fmt == 0x31545844u || fmt == 0x32545844u || fmt == 0x33545844u ||
           fmt == 0x34545844u || fmt == 0x35545844u;
}

// ---------------------------------------------------------------------------
// Attach a surface: validates an optional source rect, optionally creates an intermediate
// texture at a block-aligned size, copies through FUN_005ff6e1, retries once with
// param_6|0x10000 through the "create surface" fallback, then fills the 0x54-byte
// internal record and AddRefs the attached surface.
// NEEDS_MANUAL: the meaning of the descriptor fields at +0x44/+0x48 is not named by the
// provider; they are preserved positionally.
// ---------------------------------------------------------------------------
// 0x5ff8a2 — observed shape
std::int32_t FUN_005ff8a2(void* self_arg, std::uint32_t* param_1, std::int32_t* param_2,
                          std::uint32_t param_3, std::uint32_t* param_4, std::uint32_t param_5,
                          std::uint32_t param_6) {
    std::int32_t* self = static_cast<std::int32_t*>(self_arg);   // in_ECX
    SurfaceDesc desc{};
    std::uint32_t* local_18 = reinterpret_cast<std::uint32_t*>(
        reinterpret_cast<std::uint8_t*>(self) + 0x18);
    std::uint32_t local_44 = 0, local_40 = 0, local_3c = 0, local_38 = 0;
    std::int32_t local_8 = 0;
    std::uint32_t local_1c = 0;
    std::uint32_t local_2c = 0;
    std::uint32_t local_28 = 0, local_24 = 0;
    std::int32_t local_10 = 0;
    std::uint32_t local_54 = 0, local_50 = 0, local_4c = 0, local_48 = 0;
    std::uint32_t uVar4 = 0;
    std::int32_t local_c = 0;
    std::int32_t* local_14 = nullptr;
    std::int32_t* local_20 = nullptr;
    std::uint32_t local_34 = 0;
    std::uint32_t* puVar5 = nullptr;
    std::uint32_t* puVar1 = nullptr;
    std::uint32_t* puVar6 = nullptr;

    FUN_005ff7c0(self);
    {
        using GetDescFn = void (*)(std::int32_t*, SurfaceDesc*);
        GetDescFn fn = *reinterpret_cast<GetDescFn*>(*param_2 + 0x30);
        fn(param_2, &desc);
    }
    puVar5 = local_18;

    if (param_4 == nullptr) {
        local_3c = desc.width;
        local_38 = desc.height;
        local_44 = 0;
        local_40 = 0;
        local_8 = 0;
        local_1c = ~param_6 & 1u;
    } else {
        local_44 = param_4[0];
        local_40 = param_4[1];
        local_3c = param_4[2];
        local_38 = param_4[3];
        if ((static_cast<std::int32_t>(local_44) < 0) || (desc.width < local_3c) ||
            (static_cast<std::int32_t>(local_3c) < static_cast<std::int32_t>(local_44)) ||
            (static_cast<std::int32_t>(local_40) < 0) || (desc.height < local_38) ||
            (static_cast<std::int32_t>(local_38) < static_cast<std::int32_t>(local_40))) {
            return static_cast<std::int32_t>(0x88760c6cu);   // -0x7789f794
        }
        local_1c = 1;
        local_8 = 0;
        if ((local_44 != 0) || (local_3c != desc.width) || (local_40 != 0) ||
            (local_38 != desc.height)) {
            local_8 = 1;
        }
        if (((param_6 & 1) != 0) || (local_8 != 0)) local_1c = 0;
    }

    local_2c = param_6 & 0x10000u;
    if (local_2c != 0) {
        local_28 = desc.width;
        local_24 = desc.height;
        local_10 = 0;
        if (is_dxt(desc.format)) {
            uVar4 = desc.height | desc.width;
            while ((uVar4 & 3) != 0) {
                local_10 = local_10 + 1;
                uVar4 = (desc.height | desc.width) << (local_10 & 0x1f);
            }
        }
        puVar1 = local_18 + 4;
        {
            using DeviceFn = void (*)(std::int32_t*, std::uint32_t*);
            DeviceFn fn = *reinterpret_cast<DeviceFn*>(*param_2 + 0xc);
            fn(param_2, puVar1);
        }
        puVar5 = puVar5 + 3;
        {
            using CreateTextureFn = std::int32_t (*)(void*, std::uint32_t, std::uint32_t,
                                                     std::uint32_t, std::uint32_t, std::uint32_t,
                                                     std::uint32_t, std::uint32_t*, std::uint32_t);
            CreateTextureFn fn = *reinterpret_cast<CreateTextureFn*>(
                *reinterpret_cast<std::int32_t*>(*puVar1) + 0x5c);
            local_c = fn(reinterpret_cast<void*>(*puVar1),
                         local_28 << (local_10 & 0x1f),
                         local_24 << (local_10 & 0x1f),
                         static_cast<std::uint32_t>(local_10 + 1), 0, desc.format,
                         static_cast<std::uint32_t>((desc.pool == 3) + 2), puVar5, 0);
        }
        if (local_c >= 0) {
            puVar6 = local_18 + 2;
            {
                using GetLevelFn = std::int32_t (*)(void*, std::int32_t, std::uint32_t*);
                GetLevelFn fn = *reinterpret_cast<GetLevelFn*>(
                    *reinterpret_cast<std::int32_t*>(puVar5) + 0x48);
                local_c = fn(reinterpret_cast<void*>(puVar5), local_10, puVar6);
            }
            if (local_c >= 0) {
                bool copied = (local_1c == 0);
                if (copied) {
                    local_14 = nullptr;
                    FUN_005f8ea2(1);
                    local_c = FUN_005ff6e1(param_2, reinterpret_cast<std::int32_t*>(*puVar6));
                    FUN_005f8ea2(0);
                    if (local_c < 0) {
                        if (local_10 == 0) {
                            using CreateSurfaceFn = std::int32_t (*)(
                                void*, std::uint32_t, std::uint32_t, std::uint32_t,
                                std::uint32_t, std::uint32_t, std::uint32_t,
                                std::int32_t**, std::uint32_t);
                            CreateSurfaceFn fn = *reinterpret_cast<CreateSurfaceFn*>(
                                *reinterpret_cast<std::int32_t*>(*puVar1) + 0x70);
                            local_c = fn(reinterpret_cast<void*>(*puVar1), local_28, local_24,
                                         desc.format, 0, 0, 1, &local_14, 0);
                        } else {
                            local_c = -1;
                        }
                        if (local_c >= 0) {
                            using UpdateFn = std::int32_t (*)(void*, std::int32_t*, std::uint32_t,
                                                              std::int32_t*, std::uint32_t,
                                                              std::uint32_t);
                            UpdateFn fn = *reinterpret_cast<UpdateFn*>(
                                *reinterpret_cast<std::int32_t*>(*puVar1) + 0x88);
                            local_c = fn(reinterpret_cast<void*>(*puVar1), param_2, 0, local_14, 0, 0);
                            if (local_c < 0) {
                                using ReleaseFn = void (*)(void*);
                                ReleaseFn rel = *reinterpret_cast<ReleaseFn*>(*local_14 + 8);
                                rel(static_cast<void*>(local_14));
                            } else {
                                local_c = FUN_005ff6e1(local_14,
                                                       reinterpret_cast<std::int32_t*>(*puVar6));
                                using ReleaseFn = void (*)(void*);
                                ReleaseFn rel = *reinterpret_cast<ReleaseFn*>(*local_14 + 8);
                                rel(static_cast<void*>(local_14));
                                if (local_c >= 0) goto surface_ok;
                            }
                        }
                        // Failure path: drop the created surface entry.
                        {
                            std::int32_t* piVar2 = reinterpret_cast<std::int32_t*>(*puVar6);
                            if (piVar2 != nullptr) {
                                using ReleaseFn = void (*)(void*);
                                ReleaseFn rel = *reinterpret_cast<ReleaseFn*>(*piVar2 + 8);
                                rel(static_cast<void*>(piVar2));
                                *puVar6 = 0;
                            }
                        }
                        goto release_and_fail;
                    }
                }
            surface_ok:
                local_14 = reinterpret_cast<std::int32_t*>(*puVar6);
                goto lock_path;
            }
        }
        {
            std::int32_t* piVar2 = reinterpret_cast<std::int32_t*>(local_18[2]);
            if (piVar2 != nullptr) {
                using ReleaseFn = void (*)(void*);
                ReleaseFn rel = *reinterpret_cast<ReleaseFn*>(*piVar2 + 8);
                rel(static_cast<void*>(piVar2));
                local_18[2] = 0;
            }
        }
    release_and_fail:
        {
            std::int32_t* piVar2 = reinterpret_cast<std::int32_t*>(*puVar5);
            if (piVar2 != nullptr) {
                using ReleaseFn = void (*)(void*);
                ReleaseFn rel = *reinterpret_cast<ReleaseFn*>(*piVar2 + 8);
                rel(static_cast<void*>(piVar2));
                *puVar5 = 0;
            }
            piVar2 = reinterpret_cast<std::int32_t*>(*puVar1);
            if (piVar2 != nullptr) {
                ReleaseFn rel = *reinterpret_cast<ReleaseFn*>(*piVar2 + 8);
                rel(static_cast<void*>(piVar2));
                *puVar1 = 0;
            }
        }
        return local_c;
    }

    local_14 = param_2;

lock_path:
    uVar4 = ((param_6 & 1) | 0x80u) << 4;
    {
        bool need_lock;
        if (local_1c == 0 || local_2c != 0 || (desc.usage & 0x20000u) == 0) {
            need_lock = true;
        } else if ((param_6 & 0x20000u) == 0) {
            FUN_005f8ea2(1);
            std::int32_t iVar3;
            {
                using GetSurfaceFn = std::int32_t (*)(std::int32_t*, std::uint32_t*,
                                                      std::int32_t**);
                GetSurfaceFn fn = *reinterpret_cast<GetSurfaceFn*>(*param_2 + 0x2c);
                iVar3 = fn(param_2, &DAT_006dd2e4, &local_20);
            }
            if (iVar3 >= 0) {
                using QueryFn = std::int32_t (*)(void*);
                QueryFn q = *reinterpret_cast<QueryFn*>(*local_20 + 0x34);
                if (q(static_cast<void*>(local_20)) == 1) {
                    uVar4 = uVar4 | 0x2000u;
                    local_8 = 0;
                }
                if (local_20 != nullptr) {
                    using ReleaseFn = void (*)(void*);
                    ReleaseFn rel = *reinterpret_cast<ReleaseFn*>(*local_20 + 8);
                    rel(static_cast<void*>(local_20));
                    local_20 = nullptr;
                }
            }
            FUN_005f8ea2(0);
            need_lock = true;
        } else {
            uVar4 = uVar4 | 0x2000u;
            local_8 = 0;
            need_lock = false;
        }

        if (need_lock) {
            if (local_8 != 0) {
                // Align the source rect to the block size implied by the format.
                std::uint32_t fmt = desc.format;
                if (fmt < 0x34545845u) {
                    if (fmt == 0x34545844u || fmt == 0x31545844u || fmt == 0x32545844u) {
                        goto align_block4;
                    }
                    if (fmt == 0x32595559u) goto align_block2;
                    if (fmt != 0x33545844u) goto align_none;
                    goto align_block4;
                } else {
                    if (fmt == 0x35545844u) goto align_block4;
                    if (fmt == 0x42475247u || fmt == 0x47424752u || fmt == 0x59565955u)
                        goto align_block2;
                    goto align_none;
                }
            align_block4:
                local_4c = (local_3c + 3) & 0xfffffffc;
                local_54 = local_44 & 0xfffffffc;
                local_50 = local_40 & 0xfffffffc;
                local_48 = (local_38 + 3) & 0xfffffffc;
                if (desc.width < local_4c) local_4c = desc.width;
                if (desc.height < local_48) local_48 = desc.height;
                goto rect_checked;
            align_block2:
                local_54 = local_44 & 0xfffffffe;
                local_4c = (local_3c + 1) & 0xfffffffe;
                local_50 = local_40;
                local_48 = local_38;
                if (desc.width < local_4c) local_4c = desc.width;
                goto rect_checked;
            align_none:
                local_54 = local_44;
                local_50 = local_40;
                local_4c = local_3c;
                local_48 = local_38;
            rect_checked:
                if (local_54 == 0 && local_4c == desc.width && local_50 == 0 &&
                    local_48 == desc.height) {
                    local_8 = 0;
                } else {
                    local_8 = 1;
                }
            }

            if (local_2c != 0) {
                using LockFn = std::int32_t (*)(void*, std::uint32_t*, SurfaceRect*, std::uint32_t);
                LockFn fn = *reinterpret_cast<LockFn*>(*local_14 + 0x34);
                std::int32_t iVar3 = fn(
                    static_cast<void*>(local_14), &local_34,
                    (local_8 != 0) ? reinterpret_cast<SurfaceRect*>(&local_54) : nullptr,
                    uVar4);
                if (iVar3 < 0) return iVar3;
                goto fill_record;
            }
        }

        FUN_005f8ea2(1);
        {
            using LockFn = std::int32_t (*)(void*, std::uint32_t*, SurfaceRect*, std::uint32_t);
            LockFn fn = *reinterpret_cast<LockFn*>(*local_14 + 0x34);
            std::int32_t iVar3 = fn(
                static_cast<void*>(local_14), &local_34,
                (local_8 != 0) ? reinterpret_cast<SurfaceRect*>(&local_54) : nullptr, uVar4);
            FUN_005f8ea2(0);
            if (iVar3 < 0) {
                return FUN_005ff8a2(self, param_1, param_2, param_3, param_4, param_5,
                                    param_6 | 0x10000u);
            }
        }
    }

fill_record:
    if (local_8 != 0) {
        local_44 = local_44 - local_54;
        local_3c = local_3c - local_54;
        local_40 = local_40 - local_50;
        local_38 = local_38 - local_50;
    }
    param_1[0] = local_34;                       // +0x00
    param_1[1] = desc.format;                    // +0x04
    param_1[2] = local_34;                       // +0x08
    param_1[6] = desc.width;                     // +0x18
    param_1[7] = desc.height;                    // +0x1c
    param_1[10] = local_44;                      // +0x28
    param_1[9] = 1;                              // +0x24
    param_1[0xb] = local_40;                     // +0x2c
    param_1[0xf] = 1;                            // +0x3c
    param_1[0x10] = 1;                           // +0x40
    param_1[0x13] = param_5;                     // +0x4c
    param_1[0xc] = local_3c;                     // +0x30
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[8] = 0;
    param_1[0xe] = 0;
    param_1[0x11] = 0;
    param_1[0x12] = 0;
    param_1[0x14] = param_3;                     // +0x50
    param_1[0xd] = local_38;                     // +0x34
    local_18[1] = reinterpret_cast<std::uint32_t>(param_2);
    *local_18 = param_6;
    {
        using AddRefFn = void (*)(std::int32_t*);
        AddRefFn fn = *reinterpret_cast<AddRefFn*>(*param_2 + 4);
        fn(param_2);
    }
    return 0;
}

// Raster descriptor produced by the method at vtable+0x20 (distinct from SurfaceDesc).
struct RasterDesc {
    std::uint32_t format;   // +0x00
    std::uint32_t flags;    // +0x04
    std::uint32_t usage;    // +0x08
    std::uint32_t pool;     // +0x0c
    std::uint32_t width;    // +0x10
    std::uint32_t height;   // +0x14
    std::uint32_t extent;   // +0x18
};

// ---------------------------------------------------------------------------
// Attach path with an explicit lock rect: validates the requested rect against the
// raster extents, block-aligns it for compressed formats, locks, records the sub-rect
// deltas into the 0x54-byte internal record, and AddRefs the surface.
// ---------------------------------------------------------------------------
// 0x5ffd96 — observed shape
std::int32_t FUN_005ffd96(void* self_arg, std::uint32_t* param_1, std::int32_t* param_2,
                          std::uint32_t param_3, std::uint32_t* param_4, std::uint32_t param_5,
                          std::uint32_t param_6) {
    std::int32_t* self = static_cast<std::int32_t*>(self_arg);
    RasterDesc desc{};
    bool bVar1 = false;
    std::uint32_t uVar2 = 0;
    std::uint32_t uVar3 = 0;
    std::uint32_t uVar5 = 0;
    std::uint32_t local_1c = 0;
    std::int32_t local_14 = 0;
    std::int32_t local_8 = 0;
    std::uint32_t local_34[6] = {0, 0, 0, 0, 0, 0};   // left, top, right, bottom, v0, v1
    std::uint32_t local_4c[4] = {0, 0, 0, 0};
    std::uint32_t local_3c = 0;
    std::uint32_t local_38 = 0;
    std::uint32_t local_24 = 0;
    std::uint32_t local_20 = 0;
    std::uint32_t local_c = 0;

    const std::int32_t* local_10 = self;

    if (*self != 0) FUN_005ff879(self);

    {
        using GetDescFn = void (*)(std::int32_t*, RasterDesc*);
        GetDescFn fn = *reinterpret_cast<GetDescFn*>(*param_2 + 0x20);
        fn(param_2, &desc);
    }

    if (param_4 == nullptr) {
        bVar1 = false;
        local_34[2] = desc.width;
        local_34[3] = desc.height;
        uVar3 = ~param_6 & 1u;
        local_34[0] = 0;
        local_34[1] = 0;
        local_24 = 0;
        local_20 = desc.extent;
    } else {
        for (int i = 0; i < 6; ++i) local_34[i] = param_4[i];
        if (desc.width < local_34[2]) return static_cast<std::int32_t>(0x88760c6cu);
        if (local_34[2] < local_34[0]) return static_cast<std::int32_t>(0x88760c6cu);
        if (desc.height < local_34[3]) return static_cast<std::int32_t>(0x88760c6cu);
        if (local_34[3] < local_34[1]) return static_cast<std::int32_t>(0x88760c6cu);
        if (desc.extent < local_20) return static_cast<std::int32_t>(0x88760c6cu);
        if (local_20 < local_24) return static_cast<std::int32_t>(0x88760c6cu);
        if (local_34[0] != 0 || local_34[2] != desc.width || local_34[1] != 0 ||
            local_34[3] != desc.height || local_24 != 0 || local_20 != desc.extent) {
            bVar1 = true;
        } else {
            bVar1 = false;
        }
        if (((param_6 & 1) != 0) || bVar1) uVar3 = 0;
        else uVar3 = 1;
    }

    uVar2 = local_20;
    if (desc.pool == 0 && ((desc.usage & 0x200u) == 0)) {
        return static_cast<std::int32_t>(0x88760c6cu);
    }

    uVar5 = ((param_6 & 1) | 0x80u) << 4;
    local_c = uVar5;

    if (uVar3 != 0 && ((desc.usage & 0x200u) != 0)) {
        if ((param_6 & 0x20000u) == 0) {
            FUN_005f8ea2(1);
            std::int32_t* probe = nullptr;
            std::int32_t iVar4;
            {
                using ProbeFn = std::int32_t (*)(std::int32_t*, std::uint32_t*, std::int32_t**);
                ProbeFn fn = *reinterpret_cast<ProbeFn*>(*param_2 + 0x1c);
                iVar4 = fn(param_2, &DAT_006dd2d4, &probe);
            }
            if (iVar4 >= 0) {
                using QueryFn = std::int32_t (*)(void*);
                QueryFn q = *reinterpret_cast<QueryFn*>(*probe + 0x34);
                if (q(static_cast<void*>(probe)) == 1) {
                    uVar5 = uVar5 | 0x2000u;
                    bVar1 = false;
                    local_c = uVar5;
                }
                if (probe != nullptr) {
                    using ReleaseFn = void (*)(void*);
                    ReleaseFn rel = *reinterpret_cast<ReleaseFn*>(*probe + 8);
                    rel(static_cast<void*>(probe));
                    probe = nullptr;
                }
            }
            FUN_005f8ea2(0);
        } else {
            uVar5 = uVar5 | 0x2000u;
        }
    }

    // Align the destination rect to the block size implied by the format.
    if (bVar1) {
        const std::uint32_t fmt = desc.format;
        int align = 0;   // 0 = none, 2 = 2-pixel, 4 = 4-pixel
        bool full4 = false;
        bool full2 = false;
        if (fmt < 0x34545845u) {
            if (fmt == 0x34545844u || fmt == 0x31545844u || fmt == 0x32545844u) {
                align = 4;
            } else if (fmt == 0x32595559u) {
                align = 2;
            } else if (fmt == 0x33545844u) {
                align = 4;
            }
        } else {
            if (fmt == 0x35545844u) {
                align = 4;
            } else if (fmt == 0x42475247u || fmt == 0x47424752u || fmt == 0x59565955u) {
                align = 2;
            }
        }

        if (align == 4) {
            local_4c[0] = local_34[0] & 0xfffffffc;
            local_4c[2] = (local_34[2] + 3) & 0xfffffffc;
            local_4c[1] = local_34[1] & 0xfffffffc;
            local_4c[3] = (local_34[3] + 3) & 0xfffffffc;
            local_3c = local_24;
            if (desc.width < local_4c[2]) local_4c[2] = desc.width;
            if (desc.height < local_4c[3]) local_4c[3] = desc.height;
            local_38 = uVar2;
            if (local_4c[0] == 0 && local_4c[2] == desc.width && local_4c[1] == 0 &&
                local_4c[3] == desc.height && local_24 == 0 && uVar2 == desc.extent) {
                uVar5 = local_c;
                full4 = true;
            }
        } else if (align == 2) {
            local_4c[0] = local_34[0] & 0xfffffffe;
            local_4c[2] = (local_34[2] + 1) & 0xfffffffe;
            local_4c[3] = local_34[3];
            local_4c[1] = local_34[1];
            local_3c = local_24;
            if (desc.width < local_4c[2]) local_4c[2] = desc.width;
            local_38 = uVar2;
            if (local_4c[0] == 0 && local_4c[2] == desc.width && local_34[1] == 0 &&
                local_34[3] == desc.height && local_24 == 0 && uVar2 == desc.extent) {
                full2 = true;
            }
        }

        if (full4 || full2) goto lock_full;

        if (align == 0) {
            for (int i = 0; i < 6; ++i) local_4c[i] = local_34[i];
        }
        uVar5 = local_c;
    }

    {
        using LockRectFn = std::int32_t (*)(std::int32_t*, std::uint32_t*, std::uint32_t*,
                                            std::uint32_t);
        LockRectFn fn = *reinterpret_cast<LockRectFn*>(*param_2 + 0x24);
        std::int32_t iVar4 = fn(param_2, &local_1c, local_4c, uVar5);
        if (iVar4 < 0) return iVar4;
        local_34[0] = local_34[0] - local_4c[0];
        local_34[2] = local_34[2] - local_4c[0];
        local_34[1] = local_34[1] - local_4c[1];
        local_34[3] = local_34[3] - local_4c[1];
        local_24 = local_24 - local_3c;
        local_20 = uVar2 - local_3c;
        goto fill_record;
    }

lock_full:
    {
        using LockFn = std::int32_t (*)(std::int32_t*, std::uint32_t*, std::uint32_t,
                                        std::uint32_t);
        LockFn fn = *reinterpret_cast<LockFn*>(*param_2 + 0x24);
        std::int32_t iVar4 = fn(param_2, &local_1c, 0, uVar5);
        if (iVar4 < 0) return iVar4;
    }

fill_record:
    param_1[0x0] = static_cast<std::uint32_t>(local_14);
    param_1[0x11] = 0;
    param_1[0x12] = 0;
    param_1[0x01] = desc.format;
    param_1[0x02] = local_1c;
    param_1[0x03] = static_cast<std::uint32_t>(local_14);
    param_1[0x04] = 0;
    param_1[0x05] = 0;
    param_1[0x08] = 0;
    param_1[0x09] = desc.extent;
    for (int i = 0; i < 6; ++i) param_1[10 + i] = local_34[i];
    param_1[0x13] = param_5;
    param_1[0x06] = desc.width;
    param_1[0x14] = param_3;
    param_1[0x07] = desc.height;
    param_1[0x10] = 1;
    *const_cast<std::int32_t*>(local_10) = reinterpret_cast<std::intptr_t>(param_2);
    {
        using AddRefFn = void (*)(std::int32_t*);
        AddRefFn fn = *reinterpret_cast<AddRefFn*>(*param_2 + 4);
        fn(param_2);
    }
    return 0;
}

// ---------------------------------------------------------------------------
// Base-class destructor body: install the vtable, free the three owned blocks.
// ---------------------------------------------------------------------------
// 0x60010b — observed shape
void FUN_0060010b(void* self_arg) {
    std::int32_t* self = static_cast<std::int32_t*>(self_arg);
    *reinterpret_cast<void**>(self) = &PTR_FUN_006dddd0;
    operator delete(reinterpret_cast<void*>(self[0xe]));
    operator delete(reinterpret_cast<void*>(self[0x16]));
    operator delete(reinterpret_cast<void*>(self[0x17]));
}

static inline float clamp01(float v) {
    if (0.0f <= v) return (1.0f <= v) ? 1.0f : v;
    return 0.0f;
}
static inline float clamp11(float v) {
    if (-1.0f <= v) return (1.0f <= v) ? 1.0f : v;
    return -1.0f;
}

// ---------------------------------------------------------------------------
// Vertex color/layout conversion across the four source/destination component modes.
// Only the observed mode pairs appear in the listing: (1→2), (1→3), (1→4),
// (2→1), (2→3), (2→4), (3→1), (3→2), (3→4).
// ---------------------------------------------------------------------------
// 0x600136 — observed shape
std::uint32_t FUN_00600136(void* self_arg, std::int32_t param_1) {
    std::int32_t* self = static_cast<std::int32_t*>(self_arg);
    const std::int32_t src_mode = self[2];                // +0x8
    const std::int32_t dst_mode = *reinterpret_cast<std::int32_t*>(
        reinterpret_cast<std::uint8_t*>(self) + 0x54);    // +0x54
    float* dst = reinterpret_cast<float*>(
        static_cast<std::intptr_t>(*reinterpret_cast<std::int32_t*>(
            reinterpret_cast<std::uint8_t*>(self) + 0x58)));  // +0x58
    const std::uint32_t count = *reinterpret_cast<std::uint32_t*>(
        reinterpret_cast<std::uint8_t*>(self) + 0x68);        // +0x68
    const float* src = reinterpret_cast<const float*>(static_cast<std::intptr_t>(param_1) + 8);

    if (src_mode == 1) {
        if (dst_mode == 2) {
            for (std::uint32_t i = 0; i < count; ++i) {
                dst[0] = (src[-2] + 1.0f) * 0.5f;
                dst[1] = (src[-1] + 1.0f) * 0.5f;
                dst[2] = (*src + 1.0f) * 0.5f;
                dst[3] = src[1];
                src += 4; dst += 4;
            }
        } else if (dst_mode == 3) {
            for (std::uint32_t i = 0; i < count; ++i) {
                dst[0] = (src[-2] + 1.0f) * 0.5f;
                dst[1] = (src[-1] + 1.0f) * 0.5f;
                dst[2] = (*src + 1.0f) * 0.5f;
                dst[3] = (src[1] + 1.0f) * 0.5f;
                src += 4; dst += 4;
            }
        } else if (dst_mode == 4) {
            for (std::uint32_t i = 0; i < count; ++i) {
                dst[0] = clamp01(src[-2]);
                dst[1] = clamp01(src[-1]);
                dst[2] = clamp01(*src);
                dst[3] = clamp01(src[1]);
                src += 4; dst += 4;
            }
        }
    } else if (src_mode == 2) {
        if (dst_mode == 1) {
            for (std::uint32_t i = 0; i < count; ++i) {
                dst[0] = src[-2] * 2.0f - 1.0f;
                dst[1] = src[-1] * 2.0f - 1.0f;
                dst[2] = *src * 2.0f - 1.0f;
                dst[3] = src[1];
                src += 4; dst += 4;
            }
        } else if (dst_mode == 3) {
            for (std::uint32_t i = 0; i < count; ++i) {
                dst[0] = src[-2];
                dst[1] = src[-1];
                dst[2] = *src;
                dst[3] = (src[1] + 1.0f) * 0.5f;
                src += 4; dst += 4;
            }
        } else if (dst_mode == 4) {
            for (std::uint32_t i = 0; i < count; ++i) {
                dst[0] = clamp11(src[-2]);
                dst[1] = clamp11(src[-1]);
                dst[2] = clamp11(*src);
                dst[3] = clamp01(src[1]);
                src += 4; dst += 4;
            }
        }
    } else if (src_mode == 3) {
        if (dst_mode == 1) {
            for (std::uint32_t i = 0; i < count; ++i) {
                dst[0] = src[-2] * 2.0f - 1.0f;
                dst[1] = src[-1] * 2.0f - 1.0f;
                dst[2] = *src * 2.0f - 1.0f;
                dst[3] = src[1] * 2.0f - 1.0f;
                src += 4; dst += 4;
            }
        } else if (dst_mode == 2) {
            for (std::uint32_t i = 0; i < count; ++i) {
                dst[0] = src[-2];
                dst[1] = src[-1];
                dst[2] = *src;
                dst[3] = (*src * 2.0f) - 1.0f;   // note: listing reuses *pfVar4, not pfVar4[1]
                src += 4; dst += 4;
            }
        } else if (dst_mode == 4) {
            for (std::uint32_t i = 0; i < count; ++i) {
                dst[0] = clamp11(src[-2]);
                dst[1] = clamp11(src[-1]);
                dst[2] = clamp11(*src);
                dst[3] = clamp11(src[1]);
                src += 4; dst += 4;
            }
        }
    }
    return static_cast<std::uint32_t>(*reinterpret_cast<std::int32_t*>(
        reinterpret_cast<std::uint8_t*>(self) + 0x58));
}

// ---------------------------------------------------------------------------
// Bulk conversion of the staging float buffer to 16-bit packed pixels, driven by the
// source format word: BGRX-family splats RGB565, YUY2/UYVY splats YCbCr 4:2:2.
// ---------------------------------------------------------------------------
// 0x60064e — observed shape
std::uint32_t FUN_0060064e(void* self_arg) {
    std::uint8_t* self = static_cast<std::uint8_t*>(self_arg);
    if (*reinterpret_cast<std::int32_t*>(self + 0xa0) == 0) return 0;
    if (*reinterpret_cast<std::int32_t*>(self + 0xa4) == 0) return 0;

    float* src = *reinterpret_cast<float**>(self + 0x80);
    std::uint16_t* dst = reinterpret_cast<std::uint16_t*>(
        *reinterpret_cast<std::int32_t*>(self + 0x94) * *reinterpret_cast<std::int32_t*>(self + 0x64) +
        *reinterpret_cast<std::int32_t*>(self + 0x88) * *reinterpret_cast<std::int32_t*>(self + 0x60) +
        *reinterpret_cast<std::int32_t*>(self + 0x84) * 2 +
        *reinterpret_cast<std::int32_t*>(self + 0x20));

    const std::uint32_t fmt = *reinterpret_cast<std::uint32_t*>(self + 4);
    const std::uint32_t shiftA = *reinterpret_cast<std::uint32_t*>(self + 0xa8) & 0x1f;
    const std::uint32_t shiftB = *reinterpret_cast<std::uint32_t*>(self + 0xac) & 0x1f;

    if (fmt != 0x32595559u) {
        if (fmt == 0x42475247u || fmt == 0x47424752u) {
            std::uint32_t y = *reinterpret_cast<std::uint32_t*>(self + 0x84);
            while (y < *reinterpret_cast<std::uint32_t*>(self + 0x8c)) {
                dst[0] = static_cast<std::uint16_t>(
                    (static_cast<int>(std::lround(src[1] * 255.0f + 0.5f)) << shiftA) |
                    (static_cast<int>(std::lround(src[0] * 255.0f + 0.5f)) << shiftB));
                dst[1] = static_cast<std::uint16_t>(
                    (static_cast<int>(std::lround(src[5] * 255.0f + 0.5f)) << shiftA) |
                    (static_cast<int>(std::lround(src[2] * 255.0f + 0.5f)) << shiftB));
                src += 8;
                y += 2;
                dst += 2;
            }
            *reinterpret_cast<std::int32_t*>(self + 0xa0) = 0;
            return 0;
        }
        if (fmt != 0x59565955u) {
            *reinterpret_cast<std::int32_t*>(self + 0xa0) = 0;
            return 0;
        }
    }

    {
        std::uint32_t y = *reinterpret_cast<std::uint32_t*>(self + 0x84);
        while (y < *reinterpret_cast<std::uint32_t*>(self + 0x8c)) {
            int iY0 = static_cast<int>(std::lround(src[2] * 24.966 + src[1] * 128.553 +
                                                   src[0] * 65.481 + 0.5)) + 0x10;
            int iY1 = static_cast<int>(std::lround(src[5] * 128.553 + src[6] * 24.966 +
                                                   src[4] * 65.481 + 0.5)) + 0x10;
            int iU  = static_cast<int>(std::lround(((src[2] * 112.0 - src[1] * 74.203) -
                                                    src[0] * 37.797) + 0.5)) + 0x80;
            int iV  = static_cast<int>(std::lround((src[0] * 112.0 -
                                                    (src[2] * 18.214 + src[1] * 93.786)) + 0.5)) + 0x80;
            if (iY0 < 0) iY0 = 0; else if (0xff < iY0) iY0 = 0xff;
            if (iY1 < 0) iY1 = 0; else if (0xff < iY1) iY1 = 0xff;
            if (iU < 0) iU = 0; else if (0xff < iU) iU = 0xff;
            if (iV < 0) iV = 0; else if (0xff < iV) iV = 0xff;

            dst[0] = static_cast<std::uint16_t>((iY0 << shiftA) | (iU << shiftB));
            dst[1] = static_cast<std::uint16_t>((iY1 << shiftA) | (iV << shiftB));
            src += 8;
            y += 2;
            dst += 2;
        }
    }
    *reinterpret_cast<std::int32_t*>(self + 0xa0) = 0;
    return 0;
}

// ---------------------------------------------------------------------------
// Line-level source-surface reader: flushes pending conversion, re-binds the row window,
// then walks the requested span converting packed 16-bit source pixels to float RGBA
// (BGRX/G?RG fast path) or YCbCr 4:2:2 (subsampled chroma with edge replication).
// NEEDS_MANUAL: the object at +0x2c is the surface whose packed reader the listing calls
// through an unnamed vtable slot.
// ---------------------------------------------------------------------------
// 0x600951 — observed shape
std::int32_t FUN_00600951(void* self_arg, std::uint32_t param_1, float* param_2,
                          std::uint32_t param_3) {
    std::uint8_t* self = static_cast<std::uint8_t*>(self_arg);
    std::int32_t in_ECX_dummy = 0;
    (void)in_ECX_dummy;

    if (*reinterpret_cast<std::int32_t*>(self + 0xa4) == 0) return static_cast<std::int32_t>(0x8007000e); // -0x7ff8fff2

    if ((param_1 < *reinterpret_cast<std::uint32_t*>(self + 0x88)) ||
        (*reinterpret_cast<std::uint32_t*>(self + 0x90) <= param_1) ||
        (reinterpret_cast<std::uintptr_t>(param_2) <
         *reinterpret_cast<std::uintptr_t*>(self + 0x94)) ||
        (*reinterpret_cast<std::uintptr_t*>(self + 0x98) <=
         reinterpret_cast<std::uintptr_t>(param_2))) {
        std::int32_t iVar10 = FUN_0060064e(self);
        if (iVar10 < 0) return iVar10;
        *reinterpret_cast<std::uint32_t*>(self + 0x90) = param_1 + 1;
        *reinterpret_cast<std::uint32_t*>(self + 0x88) = param_1;
        *reinterpret_cast<std::uintptr_t*>(self + 0x94) =
            reinterpret_cast<std::uintptr_t>(param_2);
        *reinterpret_cast<std::uintptr_t*>(self + 0x98) =
            reinterpret_cast<std::uintptr_t>(param_2) + 1;

        if (param_3 != 0) {
            std::uint32_t stride = *reinterpret_cast<std::uint32_t*>(self + 0x84);
            float* pfVar12 = *reinterpret_cast<float**>(self + 0x80);
            std::uint32_t width = *reinterpret_cast<std::uint32_t*>(self + 0x68);
            std::uint16_t* puVar13 = reinterpret_cast<std::uint16_t*>(
                *reinterpret_cast<std::int32_t*>(self + 0x60) * static_cast<std::int32_t>(param_1) +
                *reinterpret_cast<std::int32_t*>(self + 0x64) *
                    static_cast<std::int32_t>(reinterpret_cast<std::intptr_t>(param_2)) +
                static_cast<std::int32_t>(stride) * 2 +
                *reinterpret_cast<std::int32_t*>(self + 0x20));
            if ((width & 1) != 0) width += 1;

            const std::uint32_t fmt = *reinterpret_cast<std::uint32_t*>(self + 4);
            const std::uint32_t shiftA =
                *reinterpret_cast<std::uint16_t*>(self + 0xa8) & 0x1f;
            const std::uint32_t shiftB =
                *reinterpret_cast<std::uint16_t*>(self + 0xac) & 0x1f;
            const std::uint32_t limit = *reinterpret_cast<std::uint32_t*>(self + 0x8c);

            if (fmt != 0x32595559u) {
                if (fmt == 0x42475247u || fmt == 0x47424752u) {
                    std::uint32_t x = stride;
                    if (limit <= stride) return 0;
                    do {
                        std::uint16_t lo = puVar13[0];
                        std::uint16_t hi = puVar13[1];
                        float r = static_cast<float>((hi >> shiftB) & 0xff) * 0.003921569f;
                        float g = static_cast<float>((lo >> shiftA) & 0xff) * 0.003921569f;
                        float b = static_cast<float>((hi >> shiftA) & 0xff) * 0.003921569f;
                        float a = static_cast<float>((lo >> shiftB) & 0xff) * 0.003921569f;
                        pfVar12[0] = g;
                        pfVar12[1] = a;
                        pfVar12[2] = b;
                        pfVar12[3] = 1.0f;
                        pfVar12[4] = g;
                        pfVar12[5] = r;
                        pfVar12[6] = b;
                        pfVar12[7] = 1.0f;
                        pfVar12 += 8;
                        puVar13 += 2;
                        x += 2;
                    } while (x < limit);
                    return 0;
                }
                if (fmt != 0x59565955u) return 0;
            }

            if (param_3 < limit) {
                do {
                    const std::uint16_t s0 = puVar13[0];
                    float fVar5 = 0.0f;   // chroma U-ish
                    float fVar6 = 0.0f;   // chroma V-ish
                    const std::uint32_t idx = param_3;

                    if ((idx & 1) == 0) {
                        fVar5 = static_cast<float>((s0 >> shiftB) & 0xff) - 128.0f;
                        fVar6 = static_cast<float>((puVar13[1] >> shiftB) & 0xff);
                    } else if ((idx & 1) == 1 && width == 2) {
                        fVar5 = static_cast<float>((puVar13[-1] >> shiftB) & 0xff) - 128.0f;
                        fVar6 = static_cast<float>((s0 >> shiftB) & 0xff);
                    } else if (idx == 1 && width == 4) {
                        fVar5 = static_cast<float>(
                            ((puVar13[1] >> shiftB) & 0xff) * 8 +
                            ((puVar13[-1] >> shiftB) & 0xff) * 8 + 8 >> 4) - 128.0f;
                        fVar6 = static_cast<float>(
                            ((s0 >> shiftB) & 0xff) * 8 +
                            ((puVar13[2] >> shiftB) & 0xff) * 8 + 8 >> 4);
                    } else if (idx == width - 1) {
                        fVar5 = static_cast<float>(
                            (((puVar13[-1] >> shiftB) & 0xff) * 0x11 -
                             ((puVar13[-3] >> shiftB) & 0xff)) + 8 >> 4) - 128.0f;
                        fVar6 = static_cast<float>(
                            (((s0 >> shiftB) & 0xff) * 0x11 -
                             ((puVar13[-2] >> shiftB) & 0xff)) + 8 >> 4);
                    } else if (idx == 1) {
                        fVar5 = static_cast<float>(
                            ((((puVar13[1] >> shiftB) & 0xff) * 9 +
                              ((puVar13[-1] >> shiftB) & 0xff) * 8) -
                             ((puVar13[3] >> shiftB) & 0xff)) + 8 >> 4) - 128.0f;
                        fVar6 = static_cast<float>(
                            ((((puVar13[2] >> shiftB) & 0xff) * 9 +
                              ((s0 >> shiftB) & 0xff) * 8) -
                             ((puVar13[4] >> shiftB) & 0xff)) + 8 >> 4);
                    } else if (idx == width - 3) {
                        fVar5 = static_cast<float>(
                            ((((puVar13[-1] >> shiftB) & 0xff) * 9 +
                              ((puVar13[1] >> shiftB) & 0xff) * 8) -
                             ((puVar13[-3] >> shiftB) & 0xff)) + 8 >> 4) - 128.0f;
                        fVar6 = static_cast<float>(
                            ((((puVar13[2] >> shiftB) & 0xff) * 8 + 8) -
                             ((puVar13[-2] >> shiftB) & 0xff)) +
                            ((s0 >> shiftB) & 0xff) * 9 >> 4);
                    } else {
                        fVar5 = static_cast<float>(
                            (((((puVar13[-1] >> shiftB) & 0xff) +
                               ((puVar13[1] >> shiftB) & 0xff)) * 9 -
                              ((puVar13[-3] >> shiftB) & 0xff)) -
                             ((puVar13[3] >> shiftB) & 0xff)) + 8 >> 4) - 128.0f;
                        fVar6 = static_cast<float>(
                            (((((puVar13[2] >> shiftB) & 0xff) +
                               ((s0 >> shiftB) & 0xff)) * 9 -
                              ((puVar13[4] >> shiftB) & 0xff)) -
                             ((puVar13[-2] >> shiftB) & 0xff)) + 8 >> 4);
                    }

                    float fVar7 = (static_cast<float>((s0 >> shiftA) & 0xff) - 16.0f) * 0.00456621f;
                    float fVar8 = (fVar6 - 128.0f) * 0.00625893f + fVar7;
                    param_2[0] = fVar8;
                    fVar6 = (fVar7 - fVar5 * 0.00153632f) - (fVar6 - 128.0f) * 0.00318811f;
                    param_2[1] = fVar6;
                    fVar7 = fVar5 * 0.00791071f + fVar7;
                    param_2[2] = fVar7;
                    param_2[3] = 1.0f;
                    param_2[0] = clamp01(fVar8);
                    param_2[1] = clamp01(fVar6);
                    param_2[2] = clamp01(fVar7);

                    puVar13 += 1;
                    param_3 += 1;
                    param_2 += 4;
                } while (param_3 < limit);
            }
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// Derived destructor: install vtable, free every per-row allocation in the
// [0x32,0x34) x [0x35,0x36) grid, then the two owned blocks, then the base body.
// ---------------------------------------------------------------------------
// 0x600fd8 — observed shape
void FUN_00600fd8(void* self_arg) {
    std::int32_t* self = static_cast<std::int32_t*>(self_arg);
    *reinterpret_cast<void**>(self) = &PTR_FUN_006de0d8;
    if (self[0x3d] != 0 && self[0x3e] != 0) {
        std::int32_t local_8 = self[0x3e];
        std::uint32_t uVar2 = static_cast<std::uint32_t>(self[0x35]);
        if (uVar2 < static_cast<std::uint32_t>(self[0x36])) {
            do {
                for (std::uint32_t uVar1 = static_cast<std::uint32_t>(self[0x32]);
                     uVar1 < static_cast<std::uint32_t>(self[0x34]); uVar1 += 4) {
                    operator delete(*reinterpret_cast<void**>(local_8 + 4));
                    local_8 += 8;
                }
                uVar2 += 1;
            } while (uVar2 < static_cast<std::uint32_t>(self[0x36]));
        }
    }
    operator delete(reinterpret_cast<void*>(self[0x3c]));
    operator delete(reinterpret_cast<void*>(self[0x3e]));
    FUN_0060010b(self);
}

// ---------------------------------------------------------------------------
// Quantizes the stored color scale to the format's bit depth (15 for DXT2/DXT3,
// 255 otherwise) and rewrites the four channel values plus the derived scale.
// ---------------------------------------------------------------------------
// 0x60105d — observed shape
void FUN_0060105d(void* self_arg) {
    std::uint8_t* self = static_cast<std::uint8_t*>(self_arg);
    const std::uint32_t fmt = *reinterpret_cast<std::uint32_t*>(self + 4);
    float scale;
    if (fmt == 0x32545844u || fmt == 0x33545844u) scale = 15.0f;
    else scale = 255.0f;

    *reinterpret_cast<float*>(self + 0x80) = scale;
    *reinterpret_cast<float*>(self + 0x84) = 1.0f / scale;

    *reinterpret_cast<float*>(self + 0x24) =
        static_cast<float>(static_cast<int>(std::lround(*reinterpret_cast<float*>(self + 0x24) * 31.0f + 0.5f))) * 0.032258064f;
    *reinterpret_cast<float*>(self + 0x28) =
        static_cast<float>(static_cast<int>(std::lround(*reinterpret_cast<float*>(self + 0x28) * 63.0f + 0.5f))) * 0.015873017f;
    *reinterpret_cast<float*>(self + 0x2c) =
        static_cast<float>(static_cast<int>(std::lround(*reinterpret_cast<float*>(self + 0x2c) * 31.0f + 0.5f))) * 0.032258064f;
    *reinterpret_cast<float*>(self + 0x30) =
        static_cast<float>(static_cast<int>(std::lround(
            *reinterpret_cast<float*>(self + 0x80) * *reinterpret_cast<float*>(self + 0x30) + 0.5f))) *
        *reinterpret_cast<float*>(self + 0x84);
}

// ---------------------------------------------------------------------------
// Table-lookup gamma curve: index = round(sin(x) * x * 254), interpolate between
// adjacent table entries.
// ---------------------------------------------------------------------------
// 0x60113f — observed shape
long double FUN_0060113f(float param_1) {
    long double fVar3 = static_cast<long double>(FUN_0065427e(param_1));
    float fVar2 = static_cast<float>(fVar3 * static_cast<long double>(param_1) * 254.0L);
    std::int32_t iVar1 = static_cast<std::int32_t>(std::lround(fVar2));
    long double base = static_cast<long double>(static_cast<std::uint32_t>(iVar1));
    return (static_cast<long double>(fVar2) - base) *
               (static_cast<long double>(DAT_006dd5d4[iVar1]) -
                static_cast<long double>(DAT_006dd5d0[iVar1])) +
           static_cast<long double>(DAT_006dd5d0[iVar1]);
}

// ---------------------------------------------------------------------------
// Same lookup/interpolation as 0x60113f, with the index derived as x*x*254.
// ---------------------------------------------------------------------------
// 0x601191 — observed shape
long double FUN_00601191(float param_1) {
    float fVar2 = param_1 * param_1 * 254.0f;
    std::int32_t iVar1 = static_cast<std::int32_t>(std::lround(fVar2));
    long double base = static_cast<long double>(static_cast<std::uint32_t>(iVar1));
    return (static_cast<long double>(fVar2) - base) *
               (static_cast<long double>(DAT_006dd9d4[iVar1]) -
                static_cast<long double>(DAT_006dd9d0[iVar1])) +
           static_cast<long double>(DAT_006dd9d0[iVar1]);
}

// ---------------------------------------------------------------------------
// Rebinds the raster record to a new surface descriptor: copies the four base fields and
// the six-word sub-rect, selects the row-order table from the flag word, derives the
// byte-stride from the pitch in bits, seeds the color from the packed color word, then
// rescales the rect bookkeeping and optionally allocates the row shadow buffer.
// ---------------------------------------------------------------------------
// 0x6011da — observed shape
void FUN_006011da(void* self_arg, std::uint32_t* param_1, std::uint32_t param_2,
                  std::int32_t param_3) {
    std::int32_t* self = static_cast<std::int32_t*>(self_arg);

    *reinterpret_cast<void**>(self) = &PTR_FUN_006dddd0;
    self[8] = static_cast<std::int32_t>(param_1[0]);
    self[1] = static_cast<std::int32_t>(param_1[1]);
    self[0x18] = static_cast<std::int32_t>(param_1[2]);
    self[0x19] = static_cast<std::int32_t>(param_1[3]);

    {
        std::uint32_t* src = param_1 + 10;
        std::int32_t* dst = self + 0xf;
        for (int i = 6; i != 0; --i) *dst++ = static_cast<std::int32_t>(*src++);
    }

    void* order_table = (param_1[0x10] == 0) ? &DAT_007192a0 : &DAT_00719320;
    self[0xd] = static_cast<std::int32_t>(reinterpret_cast<std::intptr_t>(order_table));

    std::uint32_t byte_stride = param_2 >> 3;
    self[0x1e] = static_cast<std::int32_t>(byte_stride);
    self[0x15] = 0;
    self[0x16] = 0;
    self[3] = (param_2 != 0) ? 1 : 0;
    self[2] = param_3;
    self[6] = static_cast<std::int32_t>(param_1[0x13]);
    self[7] = (self[1] == 0x29 || self[1] == 0x28) ? 1 : 0;
    self[0xe] = 0;
    self[4] = static_cast<std::int32_t>(param_1[0x12]);
    self[5] = 0;
    self[0x17] = 0;

    if (self[6] != 0) {
        const std::uint32_t color = param_1[0x13];
        *reinterpret_cast<float*>(&self[9]) =
            static_cast<float>((color >> 0x10) & 0xff) * 0.003921569f;
        *reinterpret_cast<float*>(&self[10]) =
            static_cast<float>((color >> 8) & 0xff) * 0.003921569f;
        *reinterpret_cast<float*>(&self[0xb]) =
            static_cast<float>(color & 0xff) * 0.003921569f;
        *reinterpret_cast<float*>(&self[0xc]) =
            static_cast<float>(color >> 0x18) * 0.003921569f;
    }

    if (param_3 == 2) {
        if (self[1] != 0x3d) self[4] = 0;
    } else if (param_3 == 3) {
        self[4] = 0;
    }

    {
        std::int32_t span = self[0x11] - self[0xf];
        self[0x1a] = span;
        self[0x1b] = self[0x12] - self[0x10];
        self[0x1d] = static_cast<std::int32_t>(span * static_cast<std::int32_t>(byte_stride));
        self[0x1c] = self[0x14] - self[0x13];
    }

    if (param_2 != 0) {
        self[8] += self[0xf] * static_cast<std::int32_t>(byte_stride) +
                   self[0x18] * self[0x10] + self[0x19] * self[0x13];
        self[0x11] = self[0x1a];
        self[0x12] = self[0x1b];
        self[0xf] = 0;
        self[0x10] = 0;
        self[0x13] = 0;
        self[0x14] = self[0x1c];
    }

    if (param_1[0x11] != 0) {
        std::int32_t span = self[0x1a];
        std::uint32_t* buf = static_cast<std::uint32_t*>(
            FUN_00533c78(static_cast<std::uint32_t>((span + 2) * 0x10)));
        if (buf != nullptr) {
            FUN_004127b0(buf, 0x10, static_cast<std::uint32_t>(span + 2),
                         reinterpret_cast<void*>(&FUN_005f6015));
        }
        self[0x17] = static_cast<std::int32_t>(reinterpret_cast<std::intptr_t>(buf));
        if (buf != nullptr) {
            std::uint32_t* puVar5 = buf;
            for (std::int32_t n = ((span + 2) & 0xfffffffu) << 2; n != 0; --n) *puVar5++ = 0;
        }
    }
}

// ---------------------------------------------------------------------------
// Prepares the destination-side record: propagates the destination format class, then
// allocates the destination vertex block when either the format class or the owned
// buffer marker is set.
// ---------------------------------------------------------------------------
// 0x6013a6 — observed shape
std::uint32_t FUN_006013a6(void* self_arg, std::int32_t param_1) {
    std::uint8_t* self = static_cast<std::uint8_t*>(self_arg);
    std::uint32_t iVar1;
    std::int32_t* iVar2;

    if ((*reinterpret_cast<std::int32_t*>(self + 8) !=
         *reinterpret_cast<std::int32_t*>(param_1 + 8)) &&
        (*reinterpret_cast<std::int32_t*>(self + 8) != 4)) {
        *reinterpret_cast<std::int32_t*>(self + 0x54) =
            *reinterpret_cast<std::int32_t*>(param_1 + 8);
    }

    if ((*reinterpret_cast<std::int32_t*>(self + 0x54) != 0) ||
        (*reinterpret_cast<std::int32_t*>(self + 0x10) != 0)) {
        iVar1 = static_cast<std::uint32_t>(*reinterpret_cast<std::int32_t*>(self + 0x68));
        iVar2 = static_cast<std::int32_t*>(FUN_00533c78(iVar1 << 4));
        if (iVar2 == nullptr) {
            iVar2 = nullptr;
        } else {
            FUN_004127b0(iVar2, 0x10, iVar1, reinterpret_cast<void*>(&FUN_005f6015));
        }
        *reinterpret_cast<std::int32_t*>(self + 0x58) =
            static_cast<std::int32_t>(reinterpret_cast<std::intptr_t>(iVar2));
        if (iVar2 == nullptr) return 0x8007000eu;

        if ((*reinterpret_cast<std::int32_t*>(self + 0x10) != 0) &&
            (*reinterpret_cast<std::int32_t*>(param_1 + 0x10) != 0)) {
            *reinterpret_cast<std::int32_t*>(param_1 + 0x14) = 1;
            *reinterpret_cast<std::int32_t*>(self + 0x14) = 1;
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// Builds the 256-entry float RGBA palette: all-white when no palette source is present,
// otherwise expanded from the 4-byte-per-entry source block (note the 0x400-byte bound
// on the source walk).
// ---------------------------------------------------------------------------
// 0x601429 — observed shape
std::uint32_t FUN_00601429(void* self_arg, std::int32_t param_1) {
    std::uint8_t* self = static_cast<std::uint8_t*>(self_arg);
    std::uint32_t uVar3;
    std::uint32_t uVar4;
    std::int32_t iVar5 = 0;

    std::int32_t block = static_cast<std::int32_t>(
        reinterpret_cast<std::intptr_t>(FUN_00533c78(0x1000)));
    if (block != 0) {
        FUN_004127b0(reinterpret_cast<void*>(block), 0x10, 0x100,
                     reinterpret_cast<void*>(&FUN_005f6015));
    } else {
        block = 0;
    }
    *reinterpret_cast<std::int32_t*>(self + 0x38) = block;

    if (block == 0) return 0x8007000eu;

    if (*reinterpret_cast<std::int32_t*>(param_1 + 0x50) == 0) {
        uVar3 = 0;
        do {
            *reinterpret_cast<std::uint32_t*>(uVar3 + 0xc + *reinterpret_cast<std::int32_t*>(self + 0x38)) = 0x3f800000u;
            *reinterpret_cast<std::uint32_t*>(uVar3 + 0x8 + *reinterpret_cast<std::int32_t*>(self + 0x38)) = 0x3f800000u;
            *reinterpret_cast<std::uint32_t*>(uVar3 + 0x4 + *reinterpret_cast<std::int32_t*>(self + 0x38)) = 0x3f800000u;
            *reinterpret_cast<std::uint32_t*>(uVar3 + 0x0 + *reinterpret_cast<std::int32_t*>(self + 0x38)) = 0x3f800000u;
            uVar3 += 0x10;
        } while (uVar3 < 0x1000);
    } else {
        do {
            uVar4 = uVar3 + 4;
            const std::uint8_t* src =
                reinterpret_cast<const std::uint8_t*>(static_cast<std::intptr_t>(
                    *reinterpret_cast<std::int32_t*>(param_1 + 0x50)) + uVar3);
            float* dst = reinterpret_cast<float*>(
                static_cast<std::intptr_t>(
                    *reinterpret_cast<std::int32_t*>(self + 0x38)) + iVar5);
            dst[0] = static_cast<float>(src[0]) * 0.003921569f;
            dst[1] = static_cast<float>(src[1]) * 0.003921569f;
            dst[2] = static_cast<float>(src[2]) * 0.003921569f;
            dst[3] = static_cast<float>(src[3]) * 0.003921569f;
            uVar3 = uVar4;
            iVar5 += 0x10;
        } while (uVar4 < 0x400);
    }
    return 0;
}
