// Reconstruction candidates — batch mass_0325
// Sid Meier's Pirates! (2004), PE32 i386.
// Corpus: analysis/pseudocode/functions/<addr>.c (Ghidra 12.2 pseudocode).
// Provider register receivers (in_ECX/in_ESI/in_EDI/in_EBX/in_EAX) are modeled
// as an explicit `self` (or typed) parameter; `this` is never used.

#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---- Referenced corpus callees (labels preserved; signatures inferred) ----
int64_t  FUN_00672e90(uint32_t tag = 0);          // 64-bit pair returned in EAX:EDX
int32_t  FUN_0065d0b4(uint32_t size = 0);
void*    FUN_0065cc1a();
int32_t  FUN_0065d0ff(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
int32_t  FUN_0065d9d5(uint32_t a, uint32_t b, uint32_t c, uint64_t d);
int32_t  FUN_0065d8c2();
int32_t  FUN_0065db2e();
int32_t  FUN_0065e4f2();
int32_t  FUN_0065d501();
int32_t  FUN_0065d35e();
int32_t  FUN_0065cc50();
int32_t  FUN_0065d97c(const void* fmt, uint32_t a, uint64_t b);
void     FUN_00614343(int32_t mode = 0);
void     FUN_006626da();
void     FUN_0066275f();
int32_t  FUN_00675ec3(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f);
int32_t  FUN_006757c4(uint32_t a, uint32_t b);
void     FUN_006951ca(uint32_t ecx, void* p, int32_t n);
int32_t  FUN_00677874(void* self, uint32_t* mesh, int32_t flag);
int32_t  FUN_006779be(void* self, int32_t a, int32_t* b, int32_t c, uint32_t d, uint32_t e);
int32_t  FUN_006788f0(void* self, uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e,
                      int32_t* out, uint32_t* count);
int32_t  FUN_00678a4f(void* self);
int32_t  FUN_00678a8e(void* self, uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e,
                      uint32_t* flags, uint32_t* unmatched, uint32_t* maxRows);
int32_t  FUN_006790f7(void* self, uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e);
int32_t  FUN_006792a2(void* self, int32_t a, uint32_t b, int32_t c);
int32_t  FUN_0067967f(void* self);
int32_t  FUN_00677000(uint32_t a, int32_t b, uint32_t c, uint32_t d, void* e, uint32_t* f);

// ---- Observed globals ----
extern uint8_t DAT_006c3b94[];

// ============================================================================
// 0x677176 — observed shape
// Copies the six-slot source mesh tables (vertex array at +8, index array at
// +0x10) into the 0x18 array of containers, then propagates the +0x38 render
// id from the 0x2b8 array onto the 0x14 array. Counts live at 0x2c0 / 0x2bc.
// ============================================================================
uint32_t FUN_00677176(void* self_raw)
{
    uint8_t* self = (uint8_t*)self_raw;
    uint32_t i = 0;
    uint32_t count = *(uint32_t*)(self + 0x2c0);

    if (count != 0) {
        do {
            int32_t off = (int32_t)i * 4;
            int32_t src = *(int32_t*)(off + *(int32_t*)(self + 0x2b4));
            uint32_t* dst = *(uint32_t**)(*(int32_t*)(*(int32_t*)(self + 0x18) + off) + 8);
            uint32_t* s = *(uint32_t**)(src + 8);
            uint32_t n = *(uint32_t*)(src + 4) & 0x3fffffff;
            for (; n != 0; --n) *dst++ = *s++;
            // residual trailing byte loop in the listing has a zero trip count
            for (uint32_t k = 0; k != 0; --k) {
                *(uint8_t*)dst = *(uint8_t*)s;
                s = (uint32_t*)((uint8_t*)s + 1);
                dst = (uint32_t*)((uint8_t*)dst + 1);
            }

            int32_t src2 = *(int32_t*)(off + *(int32_t*)(self + 0x2b4));
            uint32_t* dst2 = *(uint32_t**)(*(int32_t*)(*(int32_t*)(self + 0x18) + off) + 0x10);
            uint32_t* s2 = *(uint32_t**)(src2 + 0x10);
            uint32_t n2 = *(uint32_t*)(src2 + 0xc) & 0x3fffffff;
            for (; n2 != 0; --n2) *dst2++ = *s2++;
            for (uint32_t k = 0; k != 0; --k) {
                *(uint8_t*)dst2 = *(uint8_t*)s2;
                s2 = (uint32_t*)((uint8_t*)s2 + 1);
                dst2 = (uint32_t*)((uint8_t*)dst2 + 1);
            }
            ++i;
        } while (i < *(uint32_t*)(self + 0x2c0));
    }

    uint32_t v = 0;
    if (*(int32_t*)(self + 700) != 0) {
        do {
            int32_t off = (int32_t)v * 4;
            int32_t prev = (int32_t)v * 4;
            ++v;
            *(uint32_t*)(*(int32_t*)(*(int32_t*)(self + 0x14) + prev) + 0x38) =
                *(uint32_t*)(*(int32_t*)(*(int32_t*)(self + 0x2b8) + off) + 0x38);
        } while (v < *(uint32_t*)(self + 700));
    }
    return 0;
}

// ============================================================================
// 0x677223 — observed shape
// Pass 1 counts per-slot mesh needs (6-entry local table) for entries whose
// origin byte (+0x6c) is 3 and definition id (+4) matches self+0x80.
// Pass 2 creates 0x72100000-prefixed indexed containers per nonzero slot and
// links them through FUN_00675ec3 / FUN_0065d9d5.
// Pass 3 converts a second container family (0x10000000 prefix) using the
// +0x3e / 0x1f render flags against self+0x88.
// Pass 4 releases each container with FUN_0065db2e and clears the slot word.
// Pass 5 rebuilds containers for render states with 0x200, or 0x10 with type 1.
// NEEDS_MANUAL: `extraout_ECX`, `extraout_ECX_00` and `extraout_ECX_01` are
// decompiler register artifacts around FUN_00672e90; the receiver stands in for
// extraout_ECX, the other two are unrecovered index/hi values.
// ============================================================================
uint32_t FUN_00677223(void* self_raw)
{
    uint8_t* self = (uint8_t*)self_raw;
    uint32_t local_34[6] = {0};
    uint32_t entry_count = *(uint32_t*)(self + 0xc);

    if (entry_count != 0) {
        int32_t* ppContainer = *(int32_t**)(self + 0x18);
        int32_t remaining = (int32_t)entry_count;
        do {
            uint32_t* container = (uint32_t*)*ppContainer;
            if (container != 0) {
                uint32_t* mesh = (uint32_t*)*container;
                if (mesh != 0) {
                    uint32_t n = container[1];
                    uint32_t k = 0;
                    if (n != 0) {
                        int32_t* piVar6 = (int32_t*)container[2];
                        do {
                            int32_t e = *(int32_t*)(*(int32_t*)(self + 0x14) + *piVar6 * 4);
                            if (*(int32_t*)(e + 4) == *(int32_t*)(self + 0x80)) {
                                if (5 < *(uint8_t*)(e + 0x6d)) break;
                                if (*(int8_t*)(e + 0x6c) == 3) {
                                    uint32_t tag = (uint32_t)(uintptr_t)mesh & 0xfff00000;
                                    int64_t r = FUN_00672e90();
                                    int32_t hi = (int32_t)((uint64_t)r >> 32);
                                    uint32_t cand = *(int32_t*)(self + 0x10) + 1;
                                    if ((int32_t)r == 0 && tag != 0x11000000) {
                                        if (local_34[hi] < cand) local_34[hi] = cand;
                                    } else if (local_34[hi] < cand &&
                                               *(int32_t*)(self + 0x3c) != 0) {
                                        local_34[hi] = cand;
                                    }
                                }
                            }
                            ++k;
                            ++piVar6;
                        } while (k < n);
                    }
                }
            }
            ++ppContainer;
            --remaining;
        } while (remaining != 0);
    }

    for (int32_t slot = 0; slot < 6; ++slot) {
        uint32_t need = local_34[slot];
        if (need == 0) continue;

        void* obj = 0;
        if (FUN_0065d0b4() != 0) obj = FUN_0065cc1a();
        if (obj == 0) return 0x8007000e;

        uint32_t hr = (uint32_t)FUN_0065d0ff(need & 0xfffff | 0x72100000, need, need, 0);
        if ((int32_t)hr < 0) return hr;

        for (uint32_t i = 0; i < need; ++i) {
            uint32_t v = (uint32_t)FUN_0065d9d5(*(uint32_t*)(self + 0x88), 0, i, 0);
            *(uint32_t*)(*(int32_t*)((uint8_t*)obj + 0x10) + i * 4) = v;
            if (*(int32_t*)(*(int32_t*)((uint8_t*)obj + 0x10) + i * 4) == -1) {
                FUN_00614343();
                return 0x8007000e;
            }
        }

        hr = (uint32_t)FUN_00675ec3(*(uint32_t*)(self + 0x18), *(uint32_t*)(self + 0xc), 3,
                                    (uint32_t)slot, need,
                                    *(uint32_t*)((uint8_t*)obj + 0x10));
        if ((int32_t)hr < 0) {
            FUN_00614343();
            return hr;
        }

        for (uint32_t i = 0; i < need; ++i) {
            int32_t idx = FUN_0065d9d5(*(uint32_t*)(self + 0x80), (uint32_t)slot, i, 0);
            if (idx == -1) {
                FUN_00614343();
                return 0x8007000e;
            }
            int32_t e = *(int32_t*)(*(int32_t*)(self + 0x14) + idx * 4);
            *(uint32_t*)(e + 0x3c) = 0;
            *(uint32_t*)(e + 0x6c) = ((uint32_t)slot << 8) | 3;
            *(int32_t*)(*(int32_t*)((uint8_t*)obj + 8) + i * 4) = idx;
        }

        uint32_t hr2 = (uint32_t)FUN_0065d8c2();
        if ((int32_t)hr2 < 0) return hr2;
    }

    for (uint32_t i = 0; i < entry_count; ++i) {
        uint32_t* container = *(uint32_t**)(*(int32_t*)(self + 0x18) + i * 4);
        int32_t first = (int32_t)(*container & 0xfffff);
        int64_t r = FUN_00672e90();
        int32_t hi = (int32_t)((uint64_t)r >> 32);
        if ((int32_t)r != 0 || hi == 0x11000000) {
            int32_t idx;
            if (hi == 0x11000000) {
                idx = *(int32_t*)container[2];
            } else {
                idx = ((int32_t*)container[2])[0]; // NEEDS_MANUAL: extraout_ECX_00
            }
            int32_t e = *(int32_t*)(*(int32_t*)(self + 0x14) + idx * 4);
            if (((*(uint8_t*)(e + 0x3e) & 0x1f) != 0) &&
                *(int32_t*)(e + 4) == *(int32_t*)(self + 0x88)) {
                void* obj = 0;
                if (FUN_0065d0b4() != 0) obj = FUN_0065cc1a();
                if (obj == 0) return 0x8007000e;

                uint32_t hr = (uint32_t)FUN_0065d0ff((uint32_t)first & 0xfffff | 0x10000000,
                                                    (uint32_t)first, (uint32_t)first, 0);
                if ((int32_t)hr < 0) return hr;

                uint32_t start = *container & 0xfffff;
                if ((*container & 0xfff00000) == 0x11000000) start = 0;

                int32_t slot = 0;
                if (first != 0) {
                    uint32_t walk = start << 2;
                    do {
                        uint32_t elem = *(uint32_t*)(*(int32_t*)(self + 0x14) +
                                                     *(int32_t*)(walk + container[2]) * 4);
                        *(int32_t*)(*(int32_t*)((uint8_t*)obj + 8) + slot * 4) =
                            *(int32_t*)(walk + container[2]);
                        uint32_t v = (uint32_t)FUN_0065d9d5(*(uint32_t*)(self + 0x88), 0,
                                                            *(uint32_t*)(elem + 0x10), 0);
                        ++slot;
                        *(uint32_t*)(*(int32_t*)((uint8_t*)obj + 0x10) + (slot - 1) * 4) = v;
                        uint32_t next = walk + 4;
                        *(uint32_t*)(walk + container[2]) =
                            *(uint32_t*)(*(int32_t*)((uint8_t*)obj + 0x10) + (slot - 1) * 4);
                        walk = next;
                    } while (slot < first);
                }

                uint32_t hr2 = (uint32_t)FUN_0065d8c2();
                if ((int32_t)hr2 < 0) return hr2;
            }
        }
    }

    for (uint32_t i = 0; i < entry_count; ++i) {
        uint32_t hr = (uint32_t)FUN_0065db2e();
        if ((int32_t)hr < 0) return hr;
        **(uint32_t**)(*(int32_t*)(self + 0x18) + i * 4) = 0;
    }

    uint32_t n = *(uint32_t*)(self + 0xc);
    for (uint32_t i = 0; i < n; ++i) {
        uint32_t* container = *(uint32_t**)(*(int32_t*)(self + 0x18) + i * 4);
        if (*container == 0) continue;

        int32_t first = (int32_t)(*container & 0xfffff);
        int32_t hi = (int32_t)FUN_00672e90();
        // NEEDS_MANUAL: extraout_ECX_01 is the unrecovered EDX half of the call.
        int32_t hi2 = 0;
        if (hi != 0 || hi2 == 0x11000000) {
            uint32_t off = (-(uint32_t)(hi2 != 0x11000000) & (uint32_t)first) * 4;
            int32_t e = *(int32_t*)(*(int32_t*)(self + 0x14) +
                                    *(int32_t*)(off + container[2]) * 4);
            uint32_t flags = *(uint32_t*)(*(int32_t*)(*(int32_t*)(self + 0x10) +
                                                     *(int32_t*)(e + 4) * 4) + 4);
            if (((flags & 0x200) != 0) ||
                ((flags & 0x10) != 0 && *(int8_t*)(e + 0x6c) == 1)) {
                void* obj = 0;
                if (FUN_0065d0b4() != 0) obj = FUN_0065cc1a();
                if (obj == 0) return 0x8007000e;

                uint32_t hr = (uint32_t)FUN_0065d0ff((uint32_t)first & 0xfffff | 0x10000000,
                                                    (uint32_t)first, (uint32_t)first, 0);
                if ((int32_t)hr < 0) return hr;
                hr = (uint32_t)FUN_0065cc50();
                if ((int32_t)hr < 0) return hr;

                int32_t slot = 0;
                if (first != 0) {
                    uint32_t src = container[2];
                    uint32_t off2 = off;
                    do {
                        *(uint32_t*)(*(int32_t*)((uint8_t*)obj + 8) + slot * 4) =
                            *(uint32_t*)(src + off2);
                        uint32_t v = (uint32_t)FUN_0065d9d5(*(uint32_t*)(self + 0x88), 0,
                                                            (uint32_t)slot, 0);
                        *(uint32_t*)(*(int32_t*)((uint8_t*)obj + 0x10) + slot * 4) = v;
                        *(uint32_t*)(off2 + container[2]) =
                            *(uint32_t*)(*(int32_t*)((uint8_t*)obj + 0x10) + slot * 4);
                        src = container[2];
                        if (*(int32_t*)(src + off2) == -1) return 0x8007000e;
                        ++slot;
                        off2 += 4;
                    } while (slot < first);
                }
                FUN_0065d8c2();
            }
        }
        FUN_0065db2e();
        *container = 0;
    }

    return (uint32_t)FUN_0065e4f2();
}

// ============================================================================
// 0x677783 — observed shape
// Calls FUN_006757c4 on the container array, then clears +0x28/+0x24 of every
// container; for each 0x11000000-tagged container it saves +0x24, calls
// FUN_006951ca(self, container, 1) and restores +0x24. Returns the HRESULT.
// ============================================================================
int32_t FUN_00677783(void* self_raw)
{
    uint8_t* self = (uint8_t*)self_raw;
    int32_t hr = FUN_006757c4(*(uint32_t*)(self + 0x18), *(uint32_t*)(self + 0xc));
    if (hr >= 0) {
        uint32_t i = 0;
        if (*(int32_t*)(self + 0xc) != 0) {
            do {
                *(uint32_t*)(*(int32_t*)(*(int32_t*)(self + 0x18) + i * 4) + 0x28) = 0;
                int32_t off = (int32_t)i * 4;
                ++i;
                *(uint32_t*)(*(int32_t*)(*(int32_t*)(self + 0x18) + off) + 0x24) = 0;
            } while (i < *(uint32_t*)(self + 0xc));
        }

        uint32_t k = 0;
        if (*(int32_t*)(self + 0xc) != 0) {
            do {
                uint32_t* container = *(uint32_t**)(*(int32_t*)(self + 0x18) + k * 4);
                int64_t r = FUN_00672e90(*container & 0xfff00000);
                if ((int32_t)r != 0 || (int32_t)((uint64_t)r >> 32) == 0x11000000) {
                    uint32_t saved = container[9];
                    FUN_006951ca((uint32_t)(uintptr_t)self, container, 1);
                    container[9] = saved;
                }
                ++k;
            } while (k < *(uint32_t*)(self + 0xc));
        }
    }
    return hr;
}

// ============================================================================
// 0x677811 — observed shape
// Scans the container array for entries tagged 0x72100000 or 0x11000000 (or a
// nonzero low half); stores the slot index into the 0x450 array and the count
// at 0x480. Returns 1 << count, or -1 when more than 0xc slots qualify.
// ============================================================================
int32_t FUN_00677811(void* self_raw)
{
    uint8_t* self = (uint8_t*)self_raw;
    uint32_t count = 0;
    uint32_t i = 0;
    uint32_t total = *(uint32_t*)(self + 0xc);

    if (total != 0) {
        uint32_t* dst = (uint32_t*)(self + 0x450);
        do {
            int64_t r = FUN_00672e90(**(uint32_t**)(*(int32_t*)(self + 0x18) + i * 4) & 0xfff00000);
            int32_t hi = (int32_t)((uint64_t)r >> 32);
            if ((int32_t)r != 0 || hi == 0x72100000 || hi == 0x11000000) {
                if (0xb < count) return -1;
                *dst = i;
                ++count;
                ++dst;
            }
            ++i;
        } while (i < total);
    }
    *(uint32_t*)(self + 0x480) = count;
    return (int32_t)(1u << (count & 0x1f));
}

// ============================================================================
// 0x677874 — observed shape
// Recursive per-container flush. A nonzero low half of the tag masks the early
// path: empty index list (+0x14) returns 1, otherwise a nonzero param_2 forces
// FUN_006626da and returns 0; param_2 == 0 is promoted to 1. Then every index in
// +0x18 is fed back through FUN_00677874 on the container at +0x18. Returns 1
// if all children succeed, else 0.
// ============================================================================
int32_t FUN_00677874(void* self_raw, uint32_t* param_1, int32_t param_2)
{
    uint8_t* self = (uint8_t*)self_raw;
    int32_t tag = (int32_t)FUN_00672e90(*param_1 & 0xfff00000);
    uint32_t i = 0;

    if (tag != 0) {
        if (param_1[5] == 0) return 1;
        if (param_2 != 0) {
            FUN_006626da();
            return 0;
        }
        param_2 = 1;
    }

    if (param_1[5] != 0) {
        do {
            int32_t r = FUN_00677874(
                self,
                *(uint32_t**)(*(int32_t*)(self + 0x18) + *(int32_t*)(param_1[6] + i * 4) * 4),
                param_2);
            if (r == 0) return 0;
            ++i;
        } while (i < param_1[5]);
    }
    return 1;
}

// ============================================================================
// 0x6778eb — observed shape
// Walks the container array (max 0x41 entries): clears +0x28, then for each
// container whose +0x24 and +4 are nonzero checks every index in +8 against the
// origin byte (+0x6c == 1) and calls FUN_006626da on a hit. Also flushes each
// container through FUN_00677874(self, container, 0); a failure returns 1.
// ============================================================================
uint32_t FUN_006778eb(void* self_raw)
{
    uint8_t* self = (uint8_t*)self_raw;
    uint32_t fail = 0;

    if (*(uint32_t*)(self + 0xc) < 0x41) {
        uint32_t i = 0;
        if (*(uint32_t*)(self + 0xc) != 0) {
            do {
                int32_t off = (int32_t)i * 4;
                ++i;
                *(uint32_t*)(*(int32_t*)(*(int32_t*)(self + 0x18) + off) + 0x28) = 0;
            } while (i < *(uint32_t*)(self + 0xc));
        }

        i = 0;
        if (*(int32_t*)(self + 0xc) != 0) {
            do {
                uint32_t k = 0;
                int32_t container = *(int32_t*)(*(int32_t*)(self + 0x18) + i * 4);
                *(int32_t*)(self + 0x100) = container;
                if (*(int32_t*)(container + 0x24) != 0 && *(int32_t*)(container + 4) != 0) {
                    do {
                        int32_t e = *(int32_t*)(*(int32_t*)(self + 0x14) +
                            *(int32_t*)(*(int32_t*)(*(int32_t*)(self + 0x100) + 8) + k * 4) * 4);
                        if (*(int8_t*)(e + 0x6c) == 1) {
                            FUN_006626da();
                            fail = 1;
                        }
                        ++k;
                    } while (k < *(uint32_t*)(*(int32_t*)(self + 0x100) + 4));
                }
                if (FUN_00677874(self, *(uint32_t**)(self + 0x100), 0) == 0) {
                    fail = 1;
                    break;
                }
                ++i;
            } while (i < *(uint32_t*)(self + 0xc));
        }
    } else {
        FUN_006626da();
        fail = 1;
    }
    return fail;
}

// ============================================================================
// 0x6779be — observed shape
// Mode 0: moves unmatched (non-0x11000000 / non-0x72100000) nodes into the
// six bucket slots, keyed by the container class at +0xc, rejecting class > 5
// and conflicting bucket contents. Mode 1: same but ignores the class and scans
// six free slots for a node id match (-1 wildcard). Mode 2: collects the
// 0x11000000 / 0x72100000 nodes into free slots. Returns 0 on conflict, 1 else.
// ============================================================================
uint32_t FUN_006779be(void* self_raw, int32_t param_1, int32_t* param_2, int32_t param_3,
                      uint32_t param_4, uint32_t param_5)
{
    uint8_t* self = (uint8_t*)self_raw;

    if (param_5 == 0) {
        param_5 = 0;
        if (param_4 != 0) {
            do {
                int32_t* slotp = (int32_t*)(param_3 + param_5 * 4);
                uint32_t* node = (uint32_t*)*slotp;
                if (((*node & 0xfff00000) != 0x11000000) &&
                    ((*node & 0xfff00000) != 0x72100000)) {
                    int32_t nodeId = *(int32_t*)node[2];
                    int32_t e = *(int32_t*)(*(int32_t*)(self + 0x14) + nodeId * 4);
                    uint32_t flags = *(uint16_t*)(*(int32_t*)(*(int32_t*)(self + 0x10) +
                                                             *(int32_t*)(e + 4) * 4) + 4);
                    if ((flags & 0x840) != 0) {
                        uint32_t cls = *(uint32_t*)(e + 0xc);
                        if (5 < cls) return 0;
                        int32_t* bucket = (int32_t*)(param_1 + cls * 4);
                        if (*bucket != 0) return 0;
                        int32_t* piVar5 = param_2 + cls;
                        if (*piVar5 == -1) {
                            *piVar5 = nodeId;
                        } else if (*piVar5 != nodeId) {
                            return 0;
                        }
                        *bucket = (int32_t)(uintptr_t)node;
                        *slotp = 0;
                        *piVar5 = *(int32_t*)node[2];
                    }
                }
                ++param_5;
            } while (param_5 < param_4);
        }
    } else if (param_5 == 1) {
        param_5 = 0;
        if (param_4 != 0) {
            do {
                int32_t* slotp = (int32_t*)(param_3 + param_5 * 4);
                uint32_t* node = (uint32_t*)*slotp;
                if ((node != 0) && ((*node & 0xfff00000) != 0x11000000) &&
                    ((*node & 0xfff00000) != 0x72100000)) {
                    uint32_t k = 0;
                    int32_t* scan = param_2;
                    do {
                        if (*(int32_t*)(param_1 + k * 4) == 0 &&
                            (*scan == *(int32_t*)node[2] || *scan == -1)) {
                            break;
                        }
                        ++k;
                        ++scan;
                    } while (k < 6);
                    if (k == 6) return 0;
                    param_2[k] = *(int32_t*)node[2];
                    *(uint32_t**)(k * 4 + param_1) = node;
                    *slotp = 0;
                }
                ++param_5;
            } while (param_5 < param_4);
        }
    } else if (param_5 == 2) {
        param_5 = 0;
        if (param_4 != 0) {
            do {
                int32_t* slotp = (int32_t*)(param_3 + param_5 * 4);
                uint32_t* node = (uint32_t*)*slotp;
                if ((node != 0) &&
                    (((*node & 0xfff00000) == 0x11000000) ||
                     ((*node & 0xfff00000) == 0x72100000))) {
                    uint32_t k = 0;
                    do {
                        if (*(int32_t*)(param_1 + k * 4) == 0) break;
                        ++k;
                    } while (k < 6);
                    if (k == 6) return 0;
                    param_2[k] = *(int32_t*)node[2];
                    *(uint32_t**)(k * 4 + param_1) = node;
                    *slotp = 0;
                }
                ++param_5;
            } while (param_5 < param_4);
        }
    }
    return 1;
}

// ============================================================================
// 0x677b94 — observed shape
// Validates a slot mask (popcount < 7, mask + 7 must fit in the 0x480 list),
// splits the 0x450-listed containers into selected (bit set) and unselected
// (origin byte 3, +0x3c == 0) groups, then runs the six FUN_006779be passes.
// When param_2 == 0 it merges each paired 0x22c/0x230 entry: allocates via
// FUN_0065d9d5, rewrites every index in the container's +8 array to the new id,
// stores the container headers into the local tables and stamps +4 with
// self+0x74. Finally contact sizes 0x220/0x224 are set to 6 and 1 is returned.
// ============================================================================
uint32_t FUN_00677b94(void* self_raw, uint32_t param_1, int32_t param_2)
{
    uint8_t* self = (uint8_t*)self_raw;
    int32_t local_5c[6] = {0};
    int32_t local_44[6] = {0};
    int32_t local_2c[6];
    uint32_t bits = 0;
    uint32_t t = param_1;

    do {
        if (t == 0) break;
        ++bits;
        t = t & (t - 1);
    } while (bits < 7);

    if (bits < 7 && *(int32_t*)(self + 0x480) - (int32_t)bits < 7) {
        int32_t n44 = 0;
        int32_t n5c = 0;
        uint32_t i = 0;

        if (*(int32_t*)(self + 0x480) != 0) {
            int32_t* listed = (int32_t*)(self + 0x450);
            do {
                uint32_t* c = *(uint32_t**)(*(int32_t*)(self + 0x18) + *listed * 4);
                uint32_t tag = *c & 0xfff00000;
                if ((param_1 & (1u << (i & 0x1f))) == 0) {
                    if (tag == 0x11000000) return 0;
                    if (tag != 0x72100000) {
                        int32_t e = *(int32_t*)(*(int32_t*)(self + 0x14) +
                            *(int32_t*)(c[2] + (*c & 0xfffff) * 4) * 4);
                        if (*(int8_t*)(e + 0x6c) != 3) return 0;
                        if (*(int32_t*)(e + 0x3c) != 0) return 0;
                    }
                    local_44[n44++] = (int32_t)(uintptr_t)c;
                } else {
                    if (c[9] == 1) return 0;
                    local_5c[n5c++] = (int32_t)(uintptr_t)c;
                }
                ++i;
                ++listed;
            } while (i < *(uint32_t*)(self + 0x480));
        }

        for (int32_t k = 0; k < 6; ++k) local_2c[k] = -1;

        int32_t ok = FUN_006779be(self, *(int32_t*)(self + 0x22c), local_2c,
                                  (int32_t)(uintptr_t)local_44, (uint32_t)n44, 0);
        if (ok != 0) {
            ok = FUN_006779be(self, *(int32_t*)(self + 0x230), local_2c,
                              (int32_t)(uintptr_t)local_5c, (uint32_t)n5c, 0);
        }
        if (ok != 0) {
            ok = FUN_006779be(self, *(int32_t*)(self + 0x22c), local_2c,
                              (int32_t)(uintptr_t)local_44, (uint32_t)n44, 1);
        }
        if (ok != 0) {
            ok = FUN_006779be(self, *(int32_t*)(self + 0x230), local_2c,
                              (int32_t)(uintptr_t)local_5c, (uint32_t)n5c, 1);
        }
        if (ok != 0) {
            ok = FUN_006779be(self, *(int32_t*)(self + 0x22c), local_2c,
                              (int32_t)(uintptr_t)local_44, (uint32_t)n44, 2);
        }
        if (ok != 0) {
            ok = FUN_006779be(self, *(int32_t*)(self + 0x230), local_2c,
                              (int32_t)(uintptr_t)local_5c, (uint32_t)n5c, 2);
        }

        if (ok != 0) {
            if (param_2 == 0) {
                for (int32_t k = 0; k < 6; ++k) {
                    local_5c[k] = 0;
                    local_44[k] = 0;
                }
                param_2 = 0;
                uint32_t off = 0;
                do {
                    if (*(int32_t*)(off + *(int32_t*)(self + 0x22c)) != 0 ||
                        *(int32_t*)(off + *(int32_t*)(self + 0x230)) != 0) {
                        int32_t* merged = 0;
                        uint32_t* c230 = *(uint32_t**)(off + *(int32_t*)(self + 0x230));
                        if (c230 != 0) merged = (int32_t*)(*c230 & 0xfff00000);

                        int64_t r = FUN_00672e90();
                        uint32_t lo = (uint32_t)r;
                        if (lo == 0) {
                            int64_t r2 = FUN_00672e90();
                            r = ((uint64_t)(uint32_t)((uint64_t)r2 >> 32) << 32) | lo;
                            if ((int32_t)r2 == 0) goto next_pair;
                        }
                        lo = (uint32_t)r;

                        int32_t newIndex = -1;
                        if (lo != 0) {
                            int32_t e = *(int32_t*)(*(int32_t*)(self + 0x14) +
                                **(int32_t**)((int32_t)((uint64_t)r >> 32) + 8) * 4);
                            newIndex = FUN_0065d9d5(*(uint32_t*)(e + 4),
                                                    *(uint32_t*)(e + 0xc),
                                                    *(uint32_t*)(e + 0x10),
                                                    *(uint64_t*)(e + 0x20));
                            if (newIndex == -1) return 0;
                            uint32_t n = **(uint32_t**)(off + *(int32_t*)(self + 0x22c)) & 0xfffff;
                            for (uint32_t k = 0; k < n; ++k) {
                                *(uint32_t*)(*(int32_t*)(*(int32_t*)(off +
                                    *(int32_t*)(self + 0x22c)) + 8) + k * 4) = (uint32_t)newIndex;
                            }
                            int32_t ent = *(int32_t*)(*(int32_t*)(self + 0x14) + newIndex * 4);
                            *(int32_t*)((uint8_t*)local_5c + off) = e;
                            FUN_0065d501();
                            *(int32_t*)(ent + 0xc) = param_2;
                        }

                        int32_t r3 = (int32_t)FUN_00672e90();
                        if (r3 != 0) {
                            int32_t e2 = *(int32_t*)(*(int32_t*)(self + 0x14) +
                                **(int32_t**)(*(int32_t*)(off + *(int32_t*)(self + 0x230)) + 8) * 4);
                            if (newIndex == -1) {
                                newIndex = FUN_0065d9d5(*(uint32_t*)(e2 + 4),
                                                        *(uint32_t*)(e2 + 0xc),
                                                        *(uint32_t*)(e2 + 0x10),
                                                        *(uint64_t*)(e2 + 0x20));
                                if (newIndex == -1) return 0;
                            }
                            uint32_t n = **(uint32_t**)(off + *(int32_t*)(self + 0x230)) & 0xfffff;
                            for (uint32_t k = 0; k < n; ++k) {
                                *(uint32_t*)(*(int32_t*)(*(int32_t*)(off +
                                    *(int32_t*)(self + 0x230)) + 8) + k * 4) = (uint32_t)newIndex;
                            }
                            *(int32_t*)((uint8_t*)local_44 + off) = e2;
                            if (lo == 0) {
                                int32_t* ent2 = *(int32_t**)(*(int32_t*)(self + 0x14) +
                                                            newIndex * 4);
                                FUN_0065d501();
                                *(int32_t*)((uint8_t*)ent2 + 0xc) = param_2;
                            }
                        }
                        if (newIndex == -1) return 0;
                    }
                next_pair:
                    ++param_2;
                    off += 4;
                } while (off < 0x18);

                for (uint32_t off2 = 0; off2 < 0x18; off2 += 4) {
                    if (*(int32_t*)((uint8_t*)local_5c + off2) != 0) {
                        *(uint32_t*)(*(int32_t*)((uint8_t*)local_5c + off2) + 4) =
                            *(uint32_t*)(self + 0x74);
                    }
                    if (*(int32_t*)((uint8_t*)local_44 + off2) != 0) {
                        *(uint32_t*)(*(int32_t*)((uint8_t*)local_44 + off2) + 4) =
                            *(uint32_t*)(self + 0x74);
                    }
                }
            }
            *(uint32_t*)(self + 0x220) = 6;
            *(uint32_t*)(self + 0x224) = 6;
            return 1;
        }
    }
    return 0;
}

// ============================================================================
// 0x677f73 — observed shape
// Builds the full 0x22c/0x230 container pairs from the cross-index of the two
// lists: for every 0x22c entry and every 0x230 entry it searches the shared
// index arrays for an overlap (direct id or +0x38 link), and on a hit allocates
// a 0x74 object, deduplicates the matched ids into four locals, fills the id /
// index arrays with freshly allocated 0x304-table slots, and registers the pair
// in the 0x2c4/0x2c8 tables and the 0x22c list. A second phase resolves
// single-element contacts (type 3) into paired 3/4 render entries. A third phase
// shifts the 0x230 list and appends the newly created pairs. Returns 0, 1, or
// an 0x8000xxxx status; cleanup releases a half-registered object.
// NEEDS_MANUAL: FUN_00672e90's EDX half is used as an object pointer at several
// sites; the corpus does not expose the proxied object.
// ============================================================================
uint32_t* FUN_00677f73(void* self_raw, int32_t* param_1)
{
    uint8_t* self = (uint8_t*)self_raw;
    uint32_t local_d0[16] = {0};
    int32_t  aiStack_90[16] = {0};
    uint32_t local_50[5] = {0};

    uint32_t* result = 0;
    int32_t  created = 0;
    void*    obj = 0;
    uint32_t idx22c = 0;
    uint32_t stride = 0;
    int32_t  remain = 0;
    uint32_t local_28 = 0, local_1c = 0, local_10 = 0, local_c = 0, local_8 = 0;
    uint32_t local_30 = 0;
    uint32_t* local_14 = 0;
    uint32_t* local_24 = 0;
    uint32_t* local_18 = 0;
    uint32_t* puVar3 = 0;
    uint32_t* puVar11 = 0;

    do {
        int32_t head = *(int32_t*)(*(int32_t*)(self + 0x22c) + idx22c * 4);
        if (((head != 0) && (*(int32_t*)(head + 0xc) != 0)) &&
            ((local_10 = 0), *(int32_t*)(self + 0x224) != 0)) {
            do {
                obj = 0;
                puVar3 = *(uint32_t**)(*(int32_t*)(self + 0x230) + local_10 * 4);
                local_18 = puVar3;
                if ((puVar3 != 0) && (*puVar3 != 0)) {
                    local_28 = 0;
                    local_50[4] = (uint32_t)(local_10 < 6);
                    local_c = *puVar3 & 0xfffff;
                    if (local_c != 0) {
                        stride = puVar3[1] / local_c;
                        uint32_t peer = *(uint32_t*)(*(int32_t*)(self + 0x22c) + idx22c * 4);
                        local_24 = 0;
                        local_1c = 0;
                        if (*(int32_t*)(peer + 0xc) != 0) {
                            local_30 = *(uint32_t*)(*(int32_t*)(*(int32_t*)(self + 0x22c) +
                                                                idx22c * 4) + 0xc);
                            do {
                                if (local_50[4] < stride) {
                                    int32_t walk = (int32_t)(local_c * local_50[4]) * 4;
                                    remain = (int32_t)(stride - local_50[4]);
                                    do {
                                        if (local_c != 0) {
                                            local_14 = *(uint32_t**)(*(int32_t*)(peer + 0x10) +
                                                                    local_1c * 4);
                                            uint32_t* elem = (uint32_t*)(puVar3[2] + walk);
                                            local_8 = local_c;
                                            do {
                                                uint32_t v = *elem;
                                                uint32_t linked = *(uint32_t*)(*(int32_t*)
                                                    (*(int32_t*)(self + 0x14) + (int32_t)v * 4) + 0x38);
                                                if (((v == (uint32_t)(uintptr_t)local_14) ||
                                                     (linked == (uint32_t)(uintptr_t)local_14)) &&
                                                    (idx22c < local_10)) {
                                                    uint32_t* sib = *(uint32_t**)
                                                        (*(int32_t*)(self + 0x230) + idx22c * 4);
                                                    if ((sib != 0) && (*sib != 0) &&
                                                        ((*sib & 0xfff00000) != 0x11000000)) {
                                                        local_24 = (uint32_t*)(uintptr_t)1;
                                                        local_28 = peer;
                                                    }
                                                }
                                                ++elem;
                                                --local_8;
                                            } while (local_8 != 0);
                                        }
                                        walk += (int32_t)local_c * 4;
                                        --remain;
                                    } while (remain != 0);
                                }
                                ++local_1c;
                            } while (local_1c < local_30);

                            if (local_24 != 0) {
                                if (param_1 == 0) {
                                    local_50[0] = 0xffffffff;
                                    local_50[1] = 0xffffffff;
                                    local_50[2] = 0xffffffff;
                                    local_8 = 0;
                                    local_50[3] = 0xffffffff;
                                    local_c = 0;
                                    if (puVar3[1] != 0) {
                                        do {
                                            if (*(uint32_t**)(local_28 + 0xc) != 0) {
                                                puVar11 = *(uint32_t**)(local_28 + 0x10);
                                                local_30 = *(uint32_t*)(puVar3[2] + local_c * 4);
                                                local_24 = *(uint32_t**)(local_28 + 0xc);
                                                do {
                                                    uint32_t v = *puVar11;
                                                    if ((v == local_30) ||
                                                        (v == *(uint32_t*)(*(int32_t*)
                                                            (*(int32_t*)(self + 0x14) + local_30 * 4) + 0x38))) {
                                                        uint32_t u = 0;
                                                        if (local_8 != 0) {
                                                            do {
                                                                if (local_50[u] == v) break;
                                                                ++u;
                                                            } while (u < local_8);
                                                        }
                                                        if (u == local_8) {
                                                            local_50[local_8] = v;
                                                            ++local_8;
                                                        }
                                                    }
                                                    ++puVar11;
                                                    local_24 = (uint32_t*)((int32_t)local_24 - 1);
                                                } while (local_24 != 0);
                                            }
                                            ++local_c;
                                        } while (local_c < puVar3[1]);
                                    }

                                    int32_t raw = FUN_0065d0b4(0x74);
                                    if (raw == 0) {
                                        obj = 0;
                                    } else {
                                        obj = FUN_0065cc1a();
                                    }
                                    if (obj != 0) {
                                        puVar11 = (uint32_t*)(uintptr_t)FUN_0065d0ff(
                                            local_8 & 0xfffff | 0x10000000, local_8, local_8, 0);
                                        result = puVar11;
                                        if ((int32_t)(intptr_t)puVar11 < 0) goto cleanup_78757;

                                        uint32_t* init = *(uint32_t**)((uint8_t*)obj + 0x10);
                                        for (uint32_t u = local_8; u != 0; --u) *init++ = 0xffffffff;

                                        local_1c = 0;
                                        if (puVar3[1] != 0) {
                                            do {
                                                local_c = 0;
                                                if (*(int32_t*)(local_28 + 0xc) != 0) {
                                                    do {
                                                        uint32_t eid = *(uint32_t*)
                                                            (puVar3[2] + local_1c * 4);
                                                        int32_t table = *(int32_t*)(self + 0x14);
                                                        local_14 = *(uint32_t**)(table + eid * 4);
                                                        uint32_t link = *(uint32_t*)
                                                            (*(int32_t*)(local_28 + 0x10) + local_c * 4);
                                                        if ((link == eid) ||
                                                            (link == local_14[0xe])) {
                                                            local_30 = *(uint32_t*)(table + link * 4);
                                                            int32_t slot = (int32_t)
                                                                (local_1c % local_8) * 4;
                                                            int32_t cur = *(int32_t*)
                                                                (slot + *(int32_t*)((uint8_t*)obj + 0x10));
                                                            if (cur == -1) {
                                                                uint32_t ip = *(uint32_t*)(self + 0x408);
                                                                if (0x3f < ip) goto err_783e6;
                                                                cur = *(int32_t*)(self + 0x304 + ip * 4);
                                                                *(uint32_t*)(self + 0x408) = ip + 1;
                                                                int32_t ent = *(int32_t*)
                                                                    (table + cur * 4);
                                                                uint32_t linkTag = *(uint32_t*)
                                                                    (self + 0x88);
                                                                *(uint32_t*)(ent + 0x3c) = 0;
                                                                *(uint32_t*)(ent + 0x38) = 0xffffffff;
                                                                *(uint32_t*)(ent + 4) = linkTag;
                                                                *(uint32_t*)(ent + 0x10) =
                                                                    *(uint32_t*)(local_30 + 0x10);
                                                                if (cur == -1) goto err_783e6;
                                                            }
                                                            if (*(uint32_t*)
                                                                    (*(int32_t*)(local_28 + 0x10) +
                                                                     local_c * 4) == local_14[0xe]) {
                                                                uint32_t ip2 = *(uint32_t*)
                                                                    (self + 0x408);
                                                                if (0x3f < ip2) goto err_783e6;
                                                                uint32_t partner = *(uint32_t*)
                                                                    (self + 0x304 + ip2 * 4);
                                                                *(uint32_t*)(self + 0x408) = ip2 + 1;
                                                                int32_t ent2 = *(int32_t*)
                                                                    (*(int32_t*)(self + 0x14) + partner * 4);
                                                                *(uint32_t*)(ent2 + 0x10) =
                                                                    *(uint32_t*)(local_30 + 0x10);
                                                                *(uint32_t*)(ent2 + 0x3c) = local_14[0xf];
                                                                *(int32_t*)(ent2 + 0x38) = cur;
                                                                *(uint32_t*)(ent2 + 4) =
                                                                    *(uint32_t*)(self + 0x88);
                                                                local_30 = partner;
                                                                *(uint32_t*)(local_18[2] + local_1c * 4) =
                                                                    partner;
                                                            } else {
                                                                *(int32_t*)(local_18[2] + local_1c * 4) =
                                                                    cur;
                                                            }
                                                            *(uint32_t*)(slot + *(int32_t*)
                                                                ((uint8_t*)obj + 8)) = *(uint32_t*)
                                                                (*(int32_t*)(local_28 + 0x10) + local_c * 4);
                                                            *(int32_t*)(slot + *(int32_t*)
                                                                ((uint8_t*)obj + 0x10)) = cur;
                                                            *(uint32_t*)(*(int32_t*)
                                                                (*(int32_t*)(self + 0x14) + cur * 4) + 0x3c) = 0;
                                                            puVar3 = local_18;
                                                        }
                                                        ++local_c;
                                                    } while (local_c < *(uint32_t*)(local_28 + 0xc));
                                                }
                                                ++local_1c;
                                            } while (local_1c < puVar3[1]);
                                        }

                                        int32_t* count220 = (int32_t*)(self + 0x220);
                                        *(int32_t*)(*(int32_t*)(self + 0x22c) + *count220 * 4) =
                                            (int32_t)(uintptr_t)obj;
                                        *count220 = *count220 + 1;
                                        uint32_t* count404 = (uint32_t*)(self + 0x404);
                                        if (*count404 < 0xc) {
                                            *(int32_t*)(self + 0x2c4 + *count404 * 4) =
                                                (int32_t)(uintptr_t)obj;
                                            *count404 = *count404 + 1;
                                            obj = 0;
                                            goto next_780ef;
                                        }
                                    }
                                err_783e6:
                                    result = (uint32_t*)(uintptr_t)0x8007000e;
                                    goto cleanup_78757;
                                }
                                *param_1 = *param_1 + 1;
                                *param_1 = *param_1 + 1;
                            }
                        }
                    }
                }
            next_780ef:
                ++local_10;
            } while (local_10 < *(uint32_t*)(self + 0x224));
        }
        obj = 0;
        ++idx22c;
    } while (idx22c < 6);

    local_28 = 0;
    if (*(int32_t*)(self + 0x220) != 0) {
        do {
            int32_t* pair = *(int32_t**)(*(int32_t*)(self + 0x22c) + local_28 * 4);
            if ((pair != 0) && (*pair != 0)) {
                int32_t n3 = pair[3];
                local_24 = 0;
                if (n3 != 0) {
                    uint32_t* pi = (uint32_t*)pair[4];
                    do {
                        if (*(int32_t*)(*(int32_t*)(*(int32_t*)(self + 0x14) + *pi * 4) + 0x10) == 3) {
                            local_24 = (uint32_t*)(uintptr_t)1;
                            idx22c = *pi;
                        }
                        ++pi;
                        --n3;
                    } while (n3 != 0);

                    if (local_24 != 0) {
                        local_8 = 0;
                        local_10 = 6;
                        if (6 < *(uint32_t*)(self + 0x224)) {
                            int32_t* pp = (int32_t*)(*(int32_t*)(self + 0x230) + 0x18);
                            do {
                                int32_t* c = (int32_t*)*pp;
                                if ((c != 0) && (*c != 0) && ((local_18 = 0), c[1] != 0)) {
                                    local_14 = (uint32_t*)c[2];
                                    do {
                                        uint32_t slotIdx = local_8;
                                        if ((*(uint32_t*)(*(int32_t*)
                                                (*(int32_t*)(self + 0x14) + *local_14 * 4) + 0x38) == idx22c) ||
                                            (*local_14 == idx22c)) {
                                            if (0xf < local_8)
                                                return (uint32_t*)(uintptr_t)0x80004005;
                                            ++local_8;
                                            aiStack_90[slotIdx] = (int32_t)(uintptr_t)c;
                                        }
                                        local_18 = (uint32_t*)((int32_t)local_18 + 1);
                                        ++local_14;
                                    } while (local_18 < (uint32_t*)c[1]);
                                }
                                ++local_10;
                                pp += 1;
                            } while (local_10 < *(uint32_t*)(self + 0x224));
                        }

                        if (param_1 != 0) {
                            local_10 = 0;
                            if (*(int32_t*)(self + 0xc) != 0) {
                                local_18 = *(uint32_t**)(self + 0x18);
                                do {
                                    int32_t* c = (int32_t*)*local_18;
                                    if ((c != 0) && (*c != 0) && (c[10] != 1)) {
                                        local_14 = 0;
                                        if ((uint32_t*)c[1] != 0) {
                                            puVar3 = (uint32_t*)c[2];
                                            do {
                                                if ((*(uint32_t*)(*(int32_t*)
                                                        (*(int32_t*)(self + 0x14) + *puVar3 * 4) + 0x38) == idx22c) ||
                                                    (*puVar3 == idx22c)) {
                                                    if (0xf < local_8)
                                                        return (uint32_t*)(uintptr_t)0x80004005;
                                                    ++local_8;
                                                }
                                                local_14 = (uint32_t*)((int32_t)local_14 + 1);
                                                ++puVar3;
                                            } while (local_14 < (uint32_t*)c[1]);
                                        }
                                    }
                                    ++local_10;
                                    ++local_18;
                                } while (local_10 < *(uint32_t*)(self + 0xc));
                            }
                            if (local_8 == 0) goto next_786c9;
                            *param_1 = *param_1 + 1;
                        }

                        if ((local_8 != 0) && (param_1 == 0)) {
                            if (0xb < *(uint32_t*)(self + 0x404))
                                return (uint32_t*)(uintptr_t)1;

                            int32_t rawA = FUN_0065d0b4(0x74);
                            int32_t objA = (rawA == 0) ? 0 : (int32_t)(uintptr_t)FUN_0065cc1a();
                            int32_t rawB = FUN_0065d0b4(0x74);
                            int32_t objB = (rawB == 0) ? 0 : (int32_t)(uintptr_t)FUN_0065cc1a();
                            if ((objA == 0) || (objB == 0)) return (uint32_t*)(uintptr_t)0x8007000e;
                            uint32_t ip = *(uint32_t*)(self + 0x408);
                            if (0x40 < ip) return (uint32_t*)(uintptr_t)0x8007000e;

                            local_30 = *(uint32_t*)(self + 0x308 + ip * 4);
                            int32_t slotB = *(int32_t*)(self + 0x304 + ip * 4);
                            int32_t entA = *(int32_t*)(*(int32_t*)(self + 0x14) + local_30 * 4);
                            *(uint32_t*)(entA + 0x38) = 0xffffffff;
                            *(uint32_t*)(entA + 0x10) = 3;
                            *(uint32_t*)(entA + 0x3c) = 0;
                            int32_t entB = *(int32_t*)(*(int32_t*)(self + 0x14) + slotB * 4);
                            *(uint32_t*)(entB + 0x38) = 0xffffffff;
                            *(uint32_t*)(entB + 0x10) = 4;
                            *(uint32_t*)(entB + 0x3c) = 0;
                            *(int32_t*)(self + 0x408) = *(int32_t*)(self + 0x408) + 2;

                            local_10 = 0;
                            if (local_8 != 0) {
                                do {
                                    int32_t c = aiStack_90[local_10];
                                    local_18 = 0;
                                    if (*(int32_t*)(c + 4) != 0) {
                                        do {
                                            local_24 = (uint32_t*)(*(int32_t*)(c + 8) +
                                                                   (int32_t)local_18 * 4);
                                            int32_t e = *(int32_t*)(*(int32_t*)(self + 0x14) +
                                                                    *local_24 * 4);
                                            if (*(uint32_t*)(e + 0x38) == idx22c) {
                                                *(uint32_t*)(e + 0x38) = local_30;
                                            } else if (*local_24 == idx22c) {
                                                *local_24 = local_30;
                                            }
                                            local_18 = (uint32_t*)((int32_t)local_18 + 1);
                                            c = aiStack_90[local_10];
                                        } while (local_18 < *(uint32_t**)(c + 4));
                                    }
                                    ++local_10;
                                } while (local_10 < local_8);
                            }

                            local_14 = (uint32_t*)(uintptr_t)FUN_0065d0ff(0x10000001, 1, 1, 0);
                            if ((int32_t)(intptr_t)local_14 < 0) return local_14;
                            local_14 = (uint32_t*)(uintptr_t)FUN_0065d0ff(0x10000001, 1, 1, 0);
                            int32_t slotIdx = created;
                            if ((int32_t)(intptr_t)local_14 < 0) return local_14;

                            **(int32_t**)(objA + 0x10) = slotB;
                            **(uint32_t**)(objA + 8) = idx22c;
                            *(uint32_t*)(objA + 0x28) = 1;
                            **(uint32_t**)(objB + 0x10) = local_30;
                            **(int32_t**)(objB + 8) = slotB;
                            *(uint32_t*)(objA + 0x28) = 2;
                            *(int32_t*)(self + 0x2c4 + *(int32_t*)(self + 0x404) * 4) = objA;
                            *(uint32_t*)(self + 0x2c8 + *(int32_t*)(self + 0x404) * 4) = (uint32_t)objB;
                            *(int32_t*)(self + 0x404) = *(int32_t*)(self + 0x404) + 2;
                            *(int32_t*)(*(int32_t*)(self + 0x22c) +
                                        *(int32_t*)(self + 0x220) * 4) = objA;
                            *(int32_t*)(self + 0x220) = *(int32_t*)(self + 0x220) + 1;
                            ++created;
                            local_d0[slotIdx] = (uint32_t)objB;
                        }
                    }
                }
            }
        next_786c9:
            ++local_28;
        } while (local_28 < *(uint32_t*)(self + 0x220));
    }

    uint32_t n224 = *(uint32_t*)(self + 0x224);
    if (0x200 < n224 + (uint32_t)created) return (uint32_t*)(uintptr_t)0x80004005;
    if (5 < n224) {
        int32_t dst = (int32_t)(n224 + (uint32_t)created) * 4;
        do {
            *(uint32_t*)(*(int32_t*)(self + 0x230) + dst) =
                *(uint32_t*)(*(int32_t*)(self + 0x230) + n224 * 4);
            --n224;
            dst -= 4;
        } while (5 < n224);
    }
    if (created != 0) {
        int32_t dst = 0x18;
        int32_t left = created;
        do {
            // corpus copies from the local_d0 block at stack offset +0x204
            *(uint32_t*)(dst + *(int32_t*)(self + 0x230)) = local_d0[dst / 4 - 6];
            dst += 4;
            --left;
        } while (left != 0);
    }
    *(int32_t*)(self + 0x224) = *(int32_t*)(self + 0x224) + created;
    result = 0;

cleanup_78757:
    if (obj != 0) FUN_00614343(1);
    return result;
}

// ============================================================================
// 0x678775 — observed shape
// Starts from 0x12, subtracts 3 for every non-0x11000000 entry among the six
// 0x230 containers, then counts 0x22c entries whose +0xc slot list has an entry
// missing from every non-single (+0xa != 1) 0x18 container's +8 array (direct
// id or +0x38 link). Returns 1 when the survivor count exceeds the threshold.
// NEEDS_MANUAL: FUN_00672e90's EDX half is dereferenced as an object pointer.
// ============================================================================
uint32_t FUN_00678775(void* self_raw)
{
    uint8_t* self = (uint8_t*)self_raw;
    int32_t* listed = *(int32_t**)(self + 0x230);
    uint32_t threshold = 0x12;
    int32_t left = 6;

    do {
        if (((uint32_t*)*listed != 0) && ((*(uint32_t*)*listed & 0xfff00000) != 0x11000000)) {
            threshold -= 3;
        }
        ++listed;
        --left;
    } while (left != 0);

    int32_t n220 = *(int32_t*)(self + 0x220);
    uint32_t survivors = 0;
    if (n220 != 0) {
        int32_t* pp = *(int32_t**)(self + 0x22c);
        do {
            if (*pp != 0) {
                uint32_t slotCount = *(uint32_t*)(*pp + 0xc);
                uint32_t slot = 0;
                if (slotCount != 0) {
                    uint32_t total = *(uint32_t*)(self + 0xc);
                    do {
                        uint32_t k = 0;
                        if (total != 0) {
                            int32_t* pc = *(int32_t**)(self + 0x18);
                            do {
                                if (((uint32_t*)*pc)[10] != 1) {
                                    int64_t r = FUN_00672e90(*(uint32_t*)*pc & 0xfff00000);
                                    int32_t hi = (int32_t)((uint64_t)r >> 32);
                                    if ((int32_t)r == 0) {
                                        uint32_t m = 0;
                                        total = *(uint32_t*)(hi + 4); // NEEDS_MANUAL: EDX half as pointer
                                        if (total != 0) {
                                            int32_t target = *(int32_t*)
                                                (*(int32_t*)(*pp + 0x10) + slot * 4);
                                            int32_t* ids = *(int32_t**)(hi + 8);
                                            do {
                                                if ((*(int32_t*)(*(int32_t*)
                                                        (*(int32_t*)(self + 0x14) + *ids * 4) + 0x38) == target) ||
                                                    (*ids == target)) break;
                                                ++m;
                                                ++ids;
                                            } while (m < total);
                                        }
                                        if (m != total) break;
                                    }
                                }
                                ++k;
                                ++pc;
                            } while (k < *(uint32_t*)(self + 0xc));
                        }
                        total = *(uint32_t*)(self + 0xc);
                        if (k != total) ++survivors;
                        ++slot;
                    } while (slot < slotCount);
                }
            }
            ++pp;
            --n220;
        } while (n220 != 0);
        if (threshold < survivors) return 1;
    }
    return 0;
}

// ============================================================================
// 0x6788a9 — observed shape
// Recursive predicate: a node marked +0x28 == 1 returns 1 if any child (indexed
// through the +0x18 array into the 0x18 container list) is flagged, otherwise 0.
// ============================================================================
uint32_t FUN_006788a9(void* self_raw, int32_t param_1)
{
    uint8_t* self = (uint8_t*)self_raw;
    uint32_t result = 1;

    if (*(int32_t*)(param_1 + 0x28) == 1) {
        uint32_t i = 0;
        if (*(int32_t*)(param_1 + 0x14) != 0) {
            do {
                int32_t child = *(int32_t*)(*(int32_t*)(self + 0x18) +
                    *(int32_t*)(*(int32_t*)(param_1 + 0x18) + i * 4) * 4);
                if (FUN_006788a9(self, child) != 0) return 1;
                ++i;
            } while (i < *(uint32_t*)(param_1 + 0x14));
        }
        result = 0;
    }
    return result;
}

// ============================================================================
// 0x6788f0 — observed shape
// Collects the +0x38 (or direct) ids of every row of the containers in
// [param_2, param_3) whose elements match one of the param_4/param_5 "wanted"
// ids and whose entry +0xc is -1. Deduplicates into param_6 (max 0x20, else
// FUN_006626da + 0x80004005) and bumps *param_7. Returns 0 when the range is
// exhausted.
// ============================================================================
uint32_t FUN_006788f0(void* self_raw, uint32_t param_1, uint32_t param_2, uint32_t param_3,
                      int32_t param_4, uint32_t param_5, int32_t* param_6, uint32_t* param_7)
{
    uint8_t* self = (uint8_t*)self_raw;
    uint32_t cur = param_2;

    do {
        if (param_3 <= cur) return 0;

        uint32_t* node = *(uint32_t**)(param_1 + cur * 4);
        if ((node != 0) && (*node != 0)) {
            uint32_t cols = *node & 0xfffff;
            uint32_t rows = node[1];
            uint32_t row = 0;
            if (rows / cols != 0) {
                uint32_t rowOff = 0;
                do {
                    bool match = false;
                    if (cols != 0) {
                        int32_t* elem = (int32_t*)(node[2] + rowOff);
                        uint32_t left = cols;
                        do {
                            int32_t e = *(int32_t*)(*(int32_t*)(self + 0x14) + *elem * 4);
                            uint32_t q = 0;
                            if (param_5 != 0) {
                                do {
                                    int32_t want = *(int32_t*)(param_4 + q * 4);
                                    if ((*elem == want || *(int32_t*)(e + 0x38) == want) &&
                                        *(int32_t*)(e + 0xc) == -1) {
                                        match = true;
                                    }
                                    ++q;
                                } while (q < param_5);
                            }
                            ++elem;
                            --left;
                        } while (left != 0);

                        if (match) {
                            uint32_t k = 0;
                            uint32_t off = rowOff;
                            do {
                                int32_t linked = *(int32_t*)(*(int32_t*)
                                    (*(int32_t*)(self + 0x14) +
                                     *(int32_t*)(off + node[2]) * 4) + 0x38);
                                if (linked == -1) linked = *(int32_t*)(off + node[2]);

                                uint32_t n = *param_7;
                                uint32_t m = 0;
                                if (n != 0) {
                                    do {
                                        if (param_6[m] == linked) break;
                                        ++m;
                                    } while (m < *param_7);
                                }
                                if (m == n) {
                                    if (m == 0x20) {
                                        FUN_006626da();
                                        return 0x80004005;
                                    }
                                    param_6[n] = linked;
                                    *param_7 = *param_7 + 1;
                                }
                                ++k;
                                off += 4;
                            } while (k < cols);
                        }
                    }
                    ++row;
                    rowOff += cols * 4;
                } while (row < rows / cols);
            }
        }
        ++cur;
    } while (true);
}

// ============================================================================
// 0x678a4f — observed shape
// Propagates the class (+0xc) and render state (+0x10) of the entry named by
// +0x38 back onto every entry in the 0x14 table that has a +0x38 link.
// ============================================================================
uint32_t FUN_00678a4f(void* self_raw)
{
    uint8_t* self = (uint8_t*)self_raw;
    uint32_t i = 0;

    if (*(int32_t*)(self + 8) != 0) {
        do {
            int32_t e = *(int32_t*)(*(int32_t*)(self + 0x14) + i * 4);
            if (*(int32_t*)(e + 0x38) != -1) {
                int32_t off = *(int32_t*)(e + 0x38) * 4;
                *(uint32_t*)(e + 0xc) =
                    *(uint32_t*)(*(int32_t*)(*(int32_t*)(self + 0x14) + off) + 0xc);
                *(uint32_t*)(e + 0x10) =
                    *(uint32_t*)(*(int32_t*)(*(int32_t*)(self + 0x14) + off) + 0x10);
            }
            ++i;
        } while (i < *(uint32_t*)(self + 8));
    }
    return 0;
}

// ============================================================================
// 0x678a8e — observed shape
// For containers [param_2, param_3) and wanted ids param_4/param_5: per row
// counts elements whose id (or +0x38 link) matches a wanted id, tracks the
// maximum per-row hit count into *param_6, sets *param_7 when a single-element
// container (or any element of a non-0x50000000 container) resolves to render
// type 3, and sets *param_8 when a row is partially matched.
// ============================================================================
uint32_t FUN_00678a8e(void* self_raw, uint32_t param_1, uint32_t param_2, uint32_t param_3,
                      int32_t param_4, uint32_t param_5, uint32_t* param_6,
                      uint32_t* param_7, uint32_t* param_8)
{
    uint8_t* self = (uint8_t*)self_raw;
    uint32_t maxRows = 0;

    *param_7 = 0;
    *param_8 = 0;

    for (uint32_t c = param_2; c < param_3; ++c) {
        uint32_t* node = *(uint32_t**)(param_1 + c * 4);
        if ((node == 0) || (*node == 0)) continue;

        uint32_t cols = *node & 0xfffff;
        uint32_t rows = node[1];
        uint32_t hits = 0;

        if (param_5 != 0) {
            int32_t* want = (int32_t*)param_4;
            uint32_t wantLeft = param_5;
            do {
                if (rows / cols != 0) {
                    uint32_t row = 0;
                    uint32_t rowCount = rows / cols;
                    do {
                        uint32_t matched = 0;
                        if (cols != 0) {
                            int32_t off = (int32_t)row * 4;
                            uint32_t left = cols;
                            do {
                                int32_t id = *(int32_t*)(off + node[2]);
                                int32_t e = *(int32_t*)(*(int32_t*)(self + 0x14) + id * 4);
                                if ((*(int32_t*)(e + 0x38) == *want) || (id == *want)) {
                                    ++matched;
                                    ++hits;
                                    if (maxRows < hits) maxRows = hits;

                                    if ((node[3] == 1) &&
                                        (*(int32_t*)(*(int32_t*)(*(int32_t*)(self + 0x14) +
                                            *(int32_t*)node[4] * 4) + 0x10) == 3)) {
                                        *param_7 = 1;
                                    }
                                    if (((*node & 0xfff00000) != 0x50000000) && node[3] != 0) {
                                        uint32_t k = 0;
                                        do {
                                            int32_t e2 = *(int32_t*)(*(int32_t*)
                                                (*(int32_t*)(self + 0x14) +
                                                 *(int32_t*)(node[4] + k * 4) * 4) + 0x10);
                                            if (e2 == 3) *param_7 = 1;
                                            ++k;
                                        } while (k < node[3]);
                                    }
                                }
                                off += 4;
                                --left;
                            } while (left != 0);
                        }
                        if ((matched != cols) && (matched != 0)) *param_8 = 1;
                        ++row;
                        --rowCount;
                    } while (rowCount != 0);
                }
                ++want;
                --wantLeft;
            } while (wantLeft != 0);
        }
    }
    *param_6 = maxRows;
    return 0;
}

// ============================================================================
// 0x678c07 — observed shape
// Builds the per-class parameter blocks for the "ship part" containers.
// Phase 1 marks every entry whose flags (+4 indirect) carry 0x200 without 0x180:
// local_f0[cls*4 .. +3] and local_70[cls] become 1 (cls bound by self+0x38).
// Phase 2 walks 0x22c then 0x230 containers; for each with ids and a non-3
// first render class it locates an adjacent single-element contact, evaluates
// elements positionally (position table local_170) into a free local_40 slot
// (8 slots, else 0x80004005), flags out-of-range coordinates through
// FUN_0066275f, allocates new 0x5..." entries via FUN_0065d9d5(local_2c, ...)
// and rewrites the index arrays, then processes the neighbouring contact's ids
// with class 3. Phase 3 stamps +4 with self+0x74 for every position-flag entry.
// ============================================================================
uint32_t FUN_00678c07(void* self_raw)
{
    uint8_t* self = (uint8_t*)self_raw;
    float    local_170[32] = {0};
    int32_t  local_f0[32] = {0};
    int32_t  local_70[8] = {0};
    float    local_50[4] = {0};
    int32_t  local_40[5];

    uint32_t entryCount = *(uint32_t*)(self + 8);
    uint32_t limit = entryCount;
    int32_t  posTable = FUN_0065d97c(&DAT_006c3b94, 0x311, 0x400000008);

    uint32_t i = 0;
    if (entryCount != 0) {
        int32_t defs = *(int32_t*)(self + 0x10);
        int32_t* entries = *(int32_t**)(self + 0x14);
        do {
            uint32_t flags = *(uint32_t*)(*(int32_t*)(defs + *(int32_t*)(*entries + 4) * 4) + 4);
            if (((flags & 0x200) != 0) && ((flags & 0x180) == 0)) {
                uint32_t cls = *(uint32_t*)(*entries + 0xc);
                if (*(uint32_t*)(self + 0x38) < cls) {
                    FUN_006626da();
                    return 0x80004005;
                }
                local_f0[cls * 4] = 1;
                local_f0[cls * 4 + 1] = 1;
                local_f0[cls * 4 + 2] = 1;
                local_f0[cls * 4 + 3] = 1;
                local_70[cls] = 1;
            }
            ++i;
            ++entries;
        } while (i < limit);
    }

    uint32_t n224 = *(uint32_t*)(self + 0x224);
    uint32_t n220 = *(uint32_t*)(self + 0x220);
    uint32_t slotIdx = 0;

    if (n220 + n224 != 0) {
        do {
            uint32_t* node;
            if (slotIdx < n220) {
                node = *(uint32_t**)(*(int32_t*)(self + 0x22c) + slotIdx * 4);
            } else {
                node = *(uint32_t**)(*(int32_t*)(self + 0x230) + (slotIdx - n220) * 4);
            }

            int32_t neighbour = 0;
            if (((node != 0) && (node[3] != 0)) && (*(int32_t*)node[4] != -1) &&
                ((*node & 0xfff00000) != 0)) {
                int32_t firstNode = *(int32_t*)(*(int32_t*)(self + 0x14) +
                                                *(int32_t*)node[4] * 4);
                if ((*(int32_t*)(firstNode + 0x10) != 3) && (node[3] != 4) && (n220 <= slotIdx)) {
                    int32_t span = 1;
                    if ((slotIdx - n220) + 1 < n224) {
                        uint32_t j = (slotIdx - n220) + 1;
                        uint32_t j2 = (slotIdx - n220) + 1;
                        do {
                            int32_t nb = *(int32_t*)(*(int32_t*)(self + 0x230) + j2 * 4);
                            if ((nb != 0) && ((*(uint16_t*)(nb + 2) & 0xfff0) != 0)) break;
                            ++span;
                            ++j;
                            j2 = j;
                        } while (j < *(uint32_t*)(self + 0x224));
                    }
                    uint32_t target = (uint32_t)(span - (int32_t)n220) + slotIdx;
                    if (target < *(uint32_t*)(self + 0x224)) {
                        neighbour = *(int32_t*)(*(int32_t*)(self + 0x230) + target * 4);
                        if ((*(int32_t*)(neighbour + 0xc) != 1) ||
                            (*(int32_t*)(*(int32_t*)(*(int32_t*)(self + 0x14) +
                                **(int32_t**)(neighbour + 0x10) * 4) + 0x10) != 3)) {
                            neighbour = 0;
                        }
                    }
                }

                uint32_t cols = *node & 0xfffff;
                local_40[4] = (int32_t)(node[1] / cols);
                uint32_t row = 0;
                if (local_40[4] != 0) {
                    uint32_t off = 0;
                    uint32_t* base = node;
                    do {
                        uint32_t* cur = node;
                        local_40[0] = 0;
                        local_40[1] = 0;
                        local_40[2] = 0;
                        local_40[3] = 0;
                        uint32_t* elem = (uint32_t*)(base[2] + off);
                        int32_t table = *(int32_t*)(self + 0x14);

                        if (((*(uint8_t*)(*(int32_t*)(*(int32_t*)(self + 0x10) +
                                *(int32_t*)(*(int32_t*)(table + *elem * 4) + 4) * 4) + 5) & 1) != 0) &&
                            (*elem < limit)) {
                            uint32_t e = 0;
                            if (cols != 0) {
                                uint32_t tag = *node & 0xfff00000;
                                do {
                                    uint32_t cls = e;
                                    if (tag != 0x50000000) {
                                        cls = *(uint32_t*)(*(int32_t*)(table +
                                            *(int32_t*)(node[4] + e * 4) * 4) + 0x10);
                                    }
                                    local_50[cls] = (float)*(double*)
                                        (*(int32_t*)(table + *elem * 4) + 0x20);
                                    local_40[cls] = 1;
                                    ++e;
                                    ++elem;
                                } while (e < cols);
                            }

                            int32_t nb = neighbour;
                            if (nb != 0) {
                                uint32_t left = *(uint32_t*)(nb + 4);
                                if (left != 0) {
                                    uint32_t* ids = *(uint32_t**)(nb + 8);
                                    do {
                                        int32_t e2 = *(int32_t*)(table + *ids * 4);
                                        if (((*(uint8_t*)(*(int32_t*)(*(int32_t*)(self + 0x10) +
                                                *(int32_t*)(e2 + 4) * 4) + 5) & 1) != 0) &&
                                            (*ids < limit)) {
                                            local_40[3] = 1;
                                            local_50[3] = (float)*(double*)(e2 + 0x20);
                                        }
                                        --left;
                                        ++ids;
                                    } while (left != 0);
                                }
                            }

                            uint32_t group = 0;
                            uint32_t groupBase = 0;
                            do {
                                uint32_t q = 0;
                                if (local_70[group] == 0) {
                                    uint32_t free = 1;
                                    do {
                                        if ((*(int32_t*)((uint8_t*)local_40 + q) != 0) &&
                                            (*(float*)((uint8_t*)local_50 + q) !=
                                             *(float*)((uint8_t*)local_170 + groupBase + q)) &&
                                            (*(int32_t*)((uint8_t*)local_f0 + groupBase + q) != 0)) {
                                            free = 0;
                                        }
                                        q += 4;
                                    } while (q < 0x10);
                                    if (free != 0) break;
                                }
                                ++group;
                                groupBase += 0x10;
                            } while (groupBase < 0x80);

                            if (group == 8) {
                                FUN_006626da();
                                return 0x80004005;
                            }

                            uint32_t t = 0;
                            uint32_t outOfRange = 0;
                            do {
                                if (local_40[t] != 0) {
                                    int32_t idx = (int32_t)(t + group * 4);
                                    float f = local_50[t];
                                    local_f0[idx] = 1;
                                    local_170[idx] = f;
                                    if ((1.0f < f) || (f < -1.0f)) outOfRange = 1;
                                }
                                ++t;
                            } while (t < 4);
                            if (outOfRange != 0) FUN_0066275f();

                            uint32_t e = 0;
                            uint32_t eoff = off;
                            do {
                                uint32_t cls;
                                if ((*cur & 0xfff00000) == 0x50000000) {
                                    cls = e;
                                } else {
                                    cls = *(uint32_t*)(*(int32_t*)(table +
                                        *(int32_t*)(cur[4] + e * 4) * 4) + 0x10);
                                }
                                int32_t newIdx = FUN_0065d9d5(posTable, group, cls,
                                    *(uint64_t*)(*(int32_t*)(table +
                                        *(int32_t*)(eoff + cur[2]) * 4) + 0x20));
                                *(uint32_t*)(*(int32_t*)(*(int32_t*)(self + 0x14) +
                                                         newIdx * 4) + 0x3c) = 0;
                                ++e;
                                *(int32_t*)(eoff + cur[2]) = newIdx;
                                eoff += 4;
                            } while (e < cols);

                            if (neighbour != 0) {
                                uint32_t e3 = 0;
                                while (e3 < *(uint32_t*)(neighbour + 4)) {
                                    uint32_t id = *(uint32_t*)(*(int32_t*)(neighbour + 8) + e3 * 4);
                                    int32_t ent = *(int32_t*)(*(int32_t*)(self + 0x14) + id * 4);
                                    if (((*(uint8_t*)(*(int32_t*)(*(int32_t*)(self + 0x10) +
                                            *(int32_t*)(ent + 4) * 4) + 5) & 1) != 0) && (id < limit)) {
                                        uint32_t v = (uint32_t)FUN_0065d9d5(posTable, group, 3,
                                                    *(uint64_t*)(ent + 0x20));
                                        *(uint32_t*)(*(int32_t*)(neighbour + 8) + e3 * 4) = v;
                                    }
                                    ++e3;
                                }
                            }
                        }

                        ++row;
                        off += cols * 4;
                        base = node;
                    } while (row < (uint32_t)local_40[4]);
                }
            }

            n224 = *(uint32_t*)(self + 0x224);
            n220 = *(uint32_t*)(self + 0x220);
            ++slotIdx;
        } while (slotIdx < n220 + n224);
    }

    uint32_t k = 0;
    if (limit != 0) {
        do {
            int32_t e = *(int32_t*)(*(int32_t*)(self + 0x14) + k * 4);
            if ((*(uint8_t*)(*(int32_t*)(*(int32_t*)(self + 0x10) +
                                        *(int32_t*)(e + 4) * 4) + 5) & 1) != 0) {
                *(uint32_t*)(e + 4) = *(uint32_t*)(self + 0x74);
            }
            ++k;
        } while (k < limit);
    }
    return 0;
}

// ============================================================================
// 0x6790f7 — observed shape
// Cross-checks the 0x230 slot list against the 0x22c list for the given wanted
// ids (param_4/param_5): 0x60000000 / 0x60500000 / 0x60a00000 / 0x60f00000 and
// 0x72100000 nodes require ordered containment and reject entries that carry
// render flags (+0x3e & 0x1f) or a +0x38 link (0x80004005). Returns 1 when an
// earlier slot holds an intersecting node, else 0.
// ============================================================================
uint32_t FUN_006790f7(void* self_raw, uint32_t param_1, uint32_t param_2, uint32_t param_3,
                      int32_t param_4, uint32_t param_5)
{
    uint8_t* self = (uint8_t*)self_raw;
    uint32_t local_8 = 0;

    if (param_3 != 0) {
        do {
            uint32_t* node = *(uint32_t**)(param_2 + local_8 * 4);
            uint32_t want = 0;
            if ((node != 0) && (*node != 0)) {
                uint32_t tag = *node & 0xfff00000;
                uint32_t cols = *node & 0xfffff;

                bool special = (tag == 0x60000000 || tag == 0x60500000 ||
                                tag == 0x60a00000 || tag == 0x60f00000 || tag == 0x72100000);
                if (!special) {
                    if (param_5 != 0) {
                        uint32_t rows = node[1];
                        do {
                            uint32_t k = 0;
                            if (rows != 0) {
                                int32_t target = *(int32_t*)(param_4 + want * 4);
                                int32_t* ids = (int32_t*)node[2];
                                do {
                                    uint32_t* peer = *(uint32_t**)(param_2 + param_1 * 4);
                                    if (((*ids == target) ||
                                         (*(int32_t*)(*(int32_t*)(*(int32_t*)(self + 0x14) +
                                                                  *ids * 4) + 0x38) == target)) &&
                                        (peer != 0) && (param_1 < local_8) &&
                                        ((peer != 0) && (*peer != 0)) &&
                                        ((*peer & 0xfff00000) != 0x11000000)) {
                                        return 1;
                                    }
                                    ++k;
                                    rows = node[1];
                                    ++ids;
                                } while (k < rows);
                            }
                            ++want;
                        } while (want < param_5);
                    }
                } else {
                    if (tag == 0x72100000) cols = 0;
                    uint32_t target = 0;
                    if (param_5 != 0) {
                        uint32_t rows = node[1];
                        do {
                            if (cols < rows) {
                                int32_t* ids = (int32_t*)(node[2] + cols * 4);
                                uint32_t pos = cols;
                                do {
                                    int32_t* peer = *(int32_t**)(param_2 + param_1 * 4);
                                    if (((*ids == *(int32_t*)(param_4 + target * 4)) &&
                                         (peer != 0)) && (param_1 < local_8) && (*peer != 0)) {
                                        return 1;
                                    }
                                    int32_t e = *(int32_t*)(*(int32_t*)(self + 0x14) + *ids * 4);
                                    if (((*(uint8_t*)(e + 0x3e) & 0x1f) != 0) ||
                                        (*(int32_t*)(e + 0x38) != -1)) {
                                        FUN_006626da();
                                        return 0x80004005;
                                    }
                                    ++pos;
                                    rows = node[1];
                                    ++ids;
                                } while (pos < rows);
                            }
                            ++target;
                        } while (target < param_5);
                    }
                }
            }
            ++local_8;
        } while (local_8 < param_3);
    }
    return 0;
}

// ============================================================================
// 0x6792a2 — observed shape
// Finds the first 0x230 (or given array) container whose first id resolves to
// class param_3 and owner self+0x88 (no element may render as class 2). Then
// expands it: 0x50000000 nodes are copied verbatim (index array + id array) and
// get a fresh FUN_0065d9d5 id appended; other nodes are split row-wise, copying
// each row and either keeping the row id or allocating a class-2 child and
// recursing into FUN_006792a2 when the row entry belongs to self+0x88. Frees the
// working object at the end (FUN_0065d35e/FUN_00614343) and returns the last
// status (0 on success, -0x7fffbffb / -0x7ff8fff2 on failure).
// ============================================================================
int32_t FUN_006792a2(void* self_raw, int32_t param_1, uint32_t param_2, int32_t param_3)
{
    uint8_t* self = (uint8_t*)self_raw;
    uint32_t* found = 0;
    uint32_t foundIdx = 0;
    uint32_t i = 0;

    if (param_2 == 0) {
        FUN_006626da();
        return -0x7fffbffb;
    }

    do {
        uint32_t* node = *(uint32_t**)(param_1 + i * 4);
        if (node != 0) {
            if (((*node & 0xfff00000) != 0) && ((*node & 0xfffff) != 0)) {
                uint32_t nth = node[3];
                if (nth != 0) {
                    int32_t* ids = (int32_t*)node[4];
                    int32_t e = *(int32_t*)(*(int32_t*)(self + 0x14) + *ids * 4);
                    if ((*(int32_t*)(e + 0xc) == param_3) &&
                        (*(int32_t*)(e + 4) == *(int32_t*)(self + 0x88))) {
                        foundIdx = i;
                        found = node;
                        uint32_t k = 0;
                        do {
                            if (*(int32_t*)(*(int32_t*)(*(int32_t*)(self + 0x14) +
                                                        *ids * 4) + 0x10) == 2) {
                                return 0;
                            }
                            ++k;
                            ++ids;
                        } while (k < nth);
                    }
                }
            }
        }
        ++i;
    } while (i < param_2);

    if (found == 0) {
        FUN_006626da();
        return -0x7fffbffb;
    }

    uint32_t* obj = 0;
    uint32_t cols = *found & 0xfffff;
    int32_t status = 0;

    if ((*found & 0xfff00000) == 0x50000000) {
        int32_t raw = FUN_0065d0b4();
        obj = (raw == 0) ? 0 : (uint32_t*)(uintptr_t)FUN_0065cc1a();
        if (obj == 0) return -0x7ff8fff2;

        status = FUN_0065d0ff(*found, found[1], found[3] + 1, 0);
        if (status < 0) goto cleanup;
        status = FUN_0065cc50();
        if (status < 0) goto cleanup;

        int32_t newIdx = FUN_0065d9d5(*(uint32_t*)(self + 0x88), (uint32_t)param_3, 2, 0);
        if (newIdx == -1) {
            status = -0x7ff8fff2;
            goto cleanup;
        }

        {
            uint32_t* src = (uint32_t*)found[2];
            uint32_t* dst = *(uint32_t**)((uint8_t*)obj + 8);
            uint32_t n = *(uint32_t*)((uint8_t*)obj + 4) & 0x3fffffff;
            for (; n != 0; --n) *dst++ = *src++;
            src = (uint32_t*)found[4];
            dst = *(uint32_t**)((uint8_t*)obj + 0x10);
            n = found[3] & 0x3fffffff;
            for (; n != 0; --n) *dst++ = *src++;
        }
        *(int32_t*)(*(int32_t*)((uint8_t*)obj + 0x10) + found[3] * 4) = newIdx;
    } else {
        int32_t raw = FUN_0065d0b4();
        obj = (raw == 0) ? 0 : (uint32_t*)(uintptr_t)FUN_0065cc1a();
        if (obj == 0) return -0x7ff8fff2;

        uint32_t rows = found[1] / cols;
        uint32_t sel = ((cols + 1) ^ *found) & 0xfffff ^ *found;
        status = FUN_0065d0ff(sel, found[1] + rows, found[3] + 1, 0);
        if (status < 0) goto cleanup;
        status = FUN_0065cc50();
        if (status < 0) goto cleanup;

        uint32_t row = 0;
        if (rows != 0) {
            uint32_t rowOff = cols * 4;
            uint32_t dstA = 0;
            uint32_t srcOff = 0;
            int32_t stride = (int32_t)(cols * 4) + 4;
            do {
                bool uniform = true;
                if (1 < cols) {
                    int32_t* p = (int32_t*)(found[2] + srcOff);
                    int32_t firstId = *p;
                    int32_t left = (int32_t)cols - 1;
                    do {
                        ++p;
                        if (*(int32_t*)(*(int32_t*)(*(int32_t*)(self + 0x14) + *p * 4) + 0x10) !=
                            *(int32_t*)(*(int32_t*)(*(int32_t*)(self + 0x14) + firstId * 4) + 0x10)) {
                            uniform = false;
                        }
                        --left;
                    } while (left != 0);
                }

                {
                    uint32_t* src = (uint32_t*)(found[2] + srcOff);
                    uint32_t* dst = (uint32_t*)(*(int32_t*)((uint8_t*)obj + 8) + dstA);
                    for (uint32_t n = cols; n != 0; --n) *dst++ = *src++;
                }

                if (uniform) {
                    *(uint32_t*)(rowOff + *(int32_t*)((uint8_t*)obj + 8)) =
                        *(uint32_t*)(srcOff + found[2]);
                } else {
                    int32_t id = *(int32_t*)(dstA + *(int32_t*)((uint8_t*)obj + 8));
                    int32_t e = *(int32_t*)(*(int32_t*)(self + 0x14) + id * 4);
                    uint32_t cls = *(uint32_t*)(e + 0xc);
                    int32_t child = FUN_0065d9d5(*(uint32_t*)(e + 4), cls, 2, 0);
                    if (child == -1) {
                        status = -0x7ff8fff2;
                        goto cleanup;
                    }
                    *(int32_t*)(rowOff + *(int32_t*)((uint8_t*)obj + 8)) = child;
                    if (*(int32_t*)(e + 4) == *(int32_t*)(self + 0x88)) {
                        int32_t r = FUN_006792a2(self, param_1, foundIdx, (int32_t)cls);
                        if (r < 0) {
                            status = r;
                            goto cleanup;
                        }
                    }
                }

                int32_t tail = FUN_0065d9d5(*(uint32_t*)(self + 0x88), (uint32_t)param_3, 2, 0);
                if (tail == -1) {
                    status = -0x7ff8fff2;
                    goto cleanup;
                }
                {
                    uint32_t* src = (uint32_t*)found[4];
                    uint32_t* dst = *(uint32_t**)((uint8_t*)obj + 0x10);
                    uint32_t n = found[3] & 0x3fffffff;
                    for (; n != 0; --n) *dst++ = *src++;
                }
                ++row;
                *(int32_t*)(*(int32_t*)((uint8_t*)obj + 0x10) + found[3] * 4) = tail;
                srcOff += cols * 4;
                dstA += (uint32_t)stride;
                rowOff += (uint32_t)stride;
            } while (row < rows);
        }
    }

    FUN_0065d35e();
    FUN_00614343();
    obj = 0;
    status = 0;

cleanup:
    if (obj != 0) FUN_00614343();
    return status;
}

// ============================================================================
// 0x67967f — observed shape
// For every 0x230 slot below self+0x4c whose tag is 0x60000000/0x60500000 and
// whose first mapped element belongs to self+0x88, calls FUN_006792a2 on the
// 0x22c list with the element class; a negative status aborts.
// ============================================================================
int32_t FUN_0067967f(void* self_raw)
{
    uint8_t* self = (uint8_t*)self_raw;
    uint32_t i = 0;

    if (*(int32_t*)(self + 0x4c) != 0) {
        do {
            uint32_t* node = *(uint32_t**)(*(int32_t*)(self + 0x230) + i * 4);
            if (node != 0) {
                uint32_t tag = *node & 0xfff00000;
                if ((tag == 0x60500000) || (tag == 0x60000000)) {
                    int32_t e = *(int32_t*)(*(int32_t*)(self + 0x14) +
                        *(int32_t*)(node[2] + (*node & 0xfffff) * 4) * 4);
                    if (*(int32_t*)(e + 4) == *(int32_t*)(self + 0x88)) {
                        int32_t r = FUN_006792a2(self, *(int32_t*)(self + 0x22c),
                                                 *(uint32_t*)(self + 0x220),
                                                 *(int32_t*)(e + 0xc));
                        if (r < 0) return r;
                    }
                }
            }
            ++i;
        } while (i < *(uint32_t*)(self + 0x4c));
    }
    return 0;
}

// ============================================================================
// 0x6796fd — observed shape
// Two-list mesh rebuild driver (param_1 = "already merged", param_2 = "forced").
// Step 1 clears +0xc on every owned 0x14 entry.
// Step 2 walks the 0x22c list: for 0x6xx/0x72100000 nodes it fills the id/class
// tables via FUN_006788f0 + FUN_00677000 and the 0x74/0x5c slot maxima; for the
// other tags it resolves pending links, checks them with FUN_006790f7 and merges
// the chosen slot pair through FUN_00678a4f.
// Step 3 walks the 0x230 list the same way and performs the single-element
// (0x50000000) merge, rewiring every referencing container row to the new ids.
// Returns 0, or 0x8000xxxx / -0x7fffbffb / -0x7ff8fff2 statuses.
// NEEDS_MANUAL: several corpus locals use the EDX half of FUN_00672e90 and raw
// pointer values as indices (0x14c/0xd4 windows, local_b8, +0x38 writes); the
// branch-B early exits in the corpus jump to the shared tail label 0x67a5b1 -
// they are modeled here as "skip this 0x22c entry" (the only coherent effect).
// ============================================================================
int32_t FUN_006796fd(void* self_raw, int32_t param_1, int32_t param_2)
{
    uint8_t* self = (uint8_t*)self_raw;
    int32_t  local_26c[32] = {0};
    int32_t  local_1ec[32] = {0};
    int32_t  local_16c[8] = {0};
    uint32_t local_14c[24] = {0};
    uint32_t local_d4[24] = {0};
    uint32_t local_74[6] = {0};
    uint32_t local_5c[6] = {0};
    uint32_t local_b8[17] = {0};
    int32_t  ec_flags[6] = {0};

    uint32_t idx = 0, off = 0;
    uint32_t m8 = 0, m10 = 0, m18 = 0, m1c = 0, m20 = 0, m24 = 0, m28 = 0;
    uint32_t m30 = 0, m34 = 0, m38 = 0, m3c = 0, m44 = 0, m40 = 0, m2c = 0;
    uint32_t m1cOut = 0;
    uint32_t pending = 0;
    uint32_t word = 0;
    uint32_t* dnode = 0;
    uint32_t* obj2 = 0;
    int32_t  hc = 0;
    bool     more = false;
    int32_t  status = 0;

    {
        uint32_t i = 0;
        if (*(int32_t*)(self + 8) != 0) {
            do {
                int32_t e = *(int32_t*)(*(int32_t*)(self + 0x14) + i * 4);
                if (*(int32_t*)(e + 4) == *(int32_t*)(self + 0x88)) {
                    *(uint32_t*)(e + 0xc) = 0xffffffff;
                }
                ++i;
            } while (i < *(uint32_t*)(self + 8));
        }
    }

    // ---- step 2: 0x22c list ------------------------------------------------
    idx = 0;
    off = 0;
    if ((*(int32_t*)(self + 0x22c) != 0) && (*(int32_t*)(self + 0x220) != 0)) {
        do {
            uint32_t* node = *(uint32_t**)(off + *(int32_t*)(self + 0x22c));
            if (node != 0) {
                uint32_t tag = *node & 0xfff00000;
                if ((tag != 0) && (tag != 0x11000000)) {
                    if ((tag == 0x60000000) || (tag == 0x60500000) ||
                        (tag == 0x60a00000) || (tag == 0x60f00000) || (tag == 0x72100000)) {
                        int32_t h = *(int32_t*)(off + *(int32_t*)(self + 0x22c));
                        m28 = 0;
                        m18 = 0;
                        m1c = 0;
                        FUN_006788f0(self, *(uint32_t*)(self + 0x230), 0,
                                     *(uint32_t*)(self + 0x224), *(uint32_t*)(h + 0x10),
                                     *(uint32_t*)(h + 0xc), local_1ec, &m1c);
                        m8 = 0;
                        if (*(int32_t*)(*(int32_t*)(*(int32_t*)(self + 0x22c) + off) + 0xc) != 0) {
                            m38 = idx;
                            do {
                                int32_t eid = *(int32_t*)(*(int32_t*)
                                    (*(int32_t*)(*(int32_t*)(self + 0x22c) + off) + 0x10) + m8 * 4);
                                int32_t ent = *(int32_t*)(*(int32_t*)(self + 0x14) + eid * 4);
                                *(uint32_t*)(ent + 0xc) = idx;
                                uint32_t r1 = (uint32_t)FUN_00677000(
                                    *(uint32_t*)(self + 0x22c), (int32_t)idx + 1,
                                    *(uint32_t*)(self + 0x220), (uint32_t)eid, (void*)ent,
                                    &m1cOut);
                                uint32_t r2 = (uint32_t)FUN_00677000(
                                    *(uint32_t*)(self + 0x230), 0,
                                    *(uint32_t*)(self + 0x224), (uint32_t)eid, (void*)ent,
                                    &m1cOut);
                                if (m28 < r2) m28 = r2;
                                pending = (m1cOut == 0) ? r1 : 0xffffffffu;
                                if (m18 < pending) m18 = pending;
                                int32_t widx = *(int32_t*)(ent + 0x10) + (int32_t)off;
                                ++m8;
                                local_d4[widx] = r2;
                                hc = *(int32_t*)(*(int32_t*)(self + 0x22c) + off);
                                local_14c[widx] = pending;
                            } while (m8 < *(uint32_t*)(hc + 0xc));
                        }
                        local_74[m38] = m18;
                        local_5c[m38] = m28;
                        if (m1c != 0) {
                            m38 = idx;
                            m8 = 0;
                            do {
                                int32_t eid = local_1ec[m8];
                                int32_t ent = *(int32_t*)(*(int32_t*)(self + 0x14) + eid * 4);
                                *(uint32_t*)(ent + 0xc) = idx;
                                uint32_t r = (uint32_t)FUN_00677000(
                                    *(uint32_t*)(self + 0x230), 0,
                                    *(uint32_t*)(self + 0x224), (uint32_t)eid, (void*)ent,
                                    &m1cOut);
                                if (m28 < r) m28 = r;
                                ++m8;
                                local_d4[*(int32_t*)(ent + 0x10) + (int32_t)off] = r;
                            } while (m8 < m1c);
                        }
                        local_5c[m38] = m28;
                    } else {
                        uint32_t nth = node[3];
                        m20 = 0;
                        m1c = 0;
                        if (nth != 0) {
                            int32_t* ids = (int32_t*)node[4];
                            do {
                                if (*(int32_t*)(*(int32_t*)(*(int32_t*)(self + 0x14) +
                                                           *ids * 4) + 0xc) == -1) {
                                    m20 = 1;
                                } else {
                                    m1c = 1;
                                }
                                ++ids;
                                --nth;
                            } while (nth != 0);
                            if (m1c != 0) {
                                if (m20 == 0) goto next_22c;
                                goto err_62da;
                            }
                        }

                        int32_t h2 = *(int32_t*)(*(int32_t*)(self + 0x22c) + off);
                        m24 = 0;
                        m3c = (int32_t)idx + 1;
                        FUN_006788f0(self, *(uint32_t*)(self + 0x22c), (uint32_t)m3c,
                                     *(uint32_t*)(self + 0x220), *(uint32_t*)(h2 + 0x10),
                                     *(uint32_t*)(h2 + 0xc), local_26c, &m24);
                        int32_t h3 = *(int32_t*)(off + *(int32_t*)(self + 0x22c));
                        int32_t singleEnt = 0;
                        FUN_006788f0(self, *(uint32_t*)(self + 0x230), 0,
                                     *(uint32_t*)(self + 0x224), *(uint32_t*)(h3 + 0x10),
                                     *(uint32_t*)(h3 + 0xc), local_26c, &m24);
                        h3 = *(int32_t*)(off + *(int32_t*)(self + 0x22c));
                        if (*(int32_t*)(h3 + 0xc) == 1) {
                            singleEnt = *(int32_t*)(*(int32_t*)(self + 0x14) +
                                                    **(int32_t**)(h3 + 0x10) * 4);
                            if (*(int32_t*)(singleEnt + 0x10) != 4) singleEnt = 0;
                        }

                        m10 = 0;
                        m1c = 0;
                        do {
                            int32_t h4 = *(int32_t*)(off + *(int32_t*)(self + 0x22c));
                            int32_t r = FUN_006790f7(self, m10,
                                                     *(uint32_t*)(self + 0x230),
                                                     *(uint32_t*)(self + 0x224),
                                                     *(uint32_t*)(h4 + 0x10),
                                                     *(uint32_t*)(h4 + 0xc));
                            if (r < 0) return r;
                            if (r != 1) {
                                if (singleEnt == 0) {
                                    if (local_74[m10] <= idx) goto lab_67994b;
                                } else {
                                    uint32_t scan = 0;
                                    do {
                                        if (local_14c[m1c + scan] <= idx) {
                                            m30 = scan;
                                            break;
                                        }
                                        ++scan;
                                    } while (scan < 3);
                                    if (scan != 3) break;
                                }
                            }
                            ++m10;
                            ++m1c;
                        } while (m10 < 6);
                        if (singleEnt != 0) *(uint32_t*)(singleEnt + 0x10) = m30;

                    lab_67994b:
                        if (m10 == 6) goto joined_679e00;

                        m18 = 0;
                        m28 = 0;
                        m8 = 0;
                        if (m24 != 0) {
                            m38 = m10;
                            do {
                                int32_t eid = local_26c[m8];
                                int32_t ent = *(int32_t*)(*(int32_t*)(self + 0x14) + eid * 4);
                                *(uint32_t*)(ent + 0xc) = m10;
                                uint32_t r1 = (uint32_t)FUN_00677000(
                                    *(uint32_t*)(self + 0x22c), m3c,
                                    *(uint32_t*)(self + 0x220), (uint32_t)eid, (void*)ent,
                                    &m1cOut);
                                uint32_t r2 = (uint32_t)FUN_00677000(
                                    *(uint32_t*)(self + 0x230), 0,
                                    *(uint32_t*)(self + 0x224), (uint32_t)eid, (void*)ent,
                                    &m1cOut);
                                if (m28 < r2) m28 = r2;
                                if ((*(uint32_t*)(self + 0x4c) <= r2) &&
                                    (*(uint32_t*)(ent + 0x10) == 3)) {
                                    ec_flags[m10] = 1;
                                }
                                if (m1cOut != 0) ec_flags[m10] = 1;
                                pending = ((m28 == 0) && (m1cOut == 0)) ? r1 : 0xffffffffu;
                                if (m18 < pending) m18 = pending;
                                int32_t widx = *(int32_t*)(ent + 0x10) + (int32_t)m10 * 4;
                                ++m8;
                                local_d4[widx] = r2;
                                more = (m8 < m24);
                                local_14c[widx] = pending;
                            } while (more);
                        }
                        local_74[m10] = m18;
                        local_5c[m10] = m28;
                        FUN_00678a4f(self);
                    }
                }
            }
        next_22c:
            ++idx;
            off += 4;
        } while (idx < *(uint32_t*)(self + 0x220));
    }

    // ---- step 3: 0x230 list ------------------------------------------------
    idx = 0;
    if ((*(int32_t*)(self + 0x230) != 0) && (*(int32_t*)(self + 0x224) != 0)) {
        do {
            uint32_t base230 = idx * 4;
            dnode = *(uint32_t**)(base230 + *(int32_t*)(self + 0x230));
            if (dnode != 0) {
                uint32_t dtag = *dnode & 0xfff00000;
                if ((dtag != 0) && (dtag != 0x11000000)) {
                    if ((dtag == 0x60000000) || (dtag == 0x60500000) ||
                        (dtag == 0x60a00000) || (dtag == 0x60f00000) ||
                        (dtag == 0x72300000) || (dtag == 0x72500000) ||
                        (dtag == 0x72100000) || (dtag == 0x72600000) ||
                        (dtag == 0x72700000) || (dtag == 0x72800000) ||
                        (dtag == 0x72a00000) || (dtag == 0x72900000) ||
                        (dtag == 0x72b00000)) {
                        m10 = 0;
                        m8 = 0;
                        if (dnode[3] != 0) {
                            do {
                                uint32_t eoff = m8 * 4;
                                int32_t e = *(int32_t*)(*(int32_t*)(self + 0x14) +
                                    *(int32_t*)(eoff + dnode[4]) * 4);
                                if ((*(uint32_t*)(self + 200) & 0xffff) == 0x104) {
                                    *(uint32_t*)(e + 0xc) = idx;
                                    m38 = idx;
                                } else {
                                    m38 = idx + 2;
                                    *(uint32_t*)(e + 0xc) = m38;
                                }
                                uint32_t r1 = (uint32_t)FUN_00677000(
                                    *(uint32_t*)(self + 0x230), (int32_t)idx + 1,
                                    *(uint32_t*)(self + 0x224),
                                    *(uint32_t*)(dnode[4] + eoff), (void*)e, &m1cOut);
                                if (m10 < r1) m10 = r1;
                                int32_t hh = *(int32_t*)(self + 0x230);
                                local_d4[*(int32_t*)(e + 0x10) + (int32_t)m38 * 4] = r1;
                                int32_t dn2 = *(int32_t*)(base230 + hh);
                                m20 = 0;
                                FUN_006788f0(self, (uint32_t)hh, idx + 1,
                                             *(uint32_t*)(self + 0x224),
                                             *(uint32_t*)(dn2 + 0x10),
                                             *(uint32_t*)(dn2 + 0xc), local_1ec, &m20);
                                m1c = 0;
                                if (m20 != 0) {
                                    do {
                                        int32_t eid = local_1ec[m1c];
                                        int32_t e2 = *(int32_t*)(*(int32_t*)(self + 0x14) +
                                                                eid * 4);
                                        *(uint32_t*)(e2 + 0xc) = m38;
                                        uint32_t r2 = (uint32_t)FUN_00677000(
                                            *(uint32_t*)(self + 0x230), (int32_t)idx + 1,
                                            *(uint32_t*)(self + 0x224), (uint32_t)eid, (void*)e2,
                                            &m1cOut);
                                        if (m10 < r2) m10 = r2;
                                        ++m1c;
                                        local_d4[*(int32_t*)(e2 + 0x10) + (int32_t)m38 * 4] = r2;
                                    } while (m1c < m20);
                                }
                                FUN_00678a4f(self);
                                ++m8;
                                base230 = idx * 4;
                                dnode = *(uint32_t**)(base230 + *(int32_t*)(self + 0x230));
                            } while (m8 < dnode[3]);
                        }
                        if (local_5c[m38] < m10) local_5c[m38] = m10;
                    } else if ((dtag != 0x72200000) && (dtag != 0x72400000)) {
                        if ((*(uint32_t*)(self + 200) & 0xffff) == 0x101) {
                            uint32_t* pn = *(uint32_t**)(base230 + *(int32_t*)(self + 0x230));
                            uint32_t cols2 = *pn & 0xfffff;
                            m30 = pn[1] / cols2;
                            m20 = 0;
                            m34 = 0;
                            if (m30 != 0) {
                                uint32_t rowAddr = pn[2];
                                uint32_t stride = cols2 * 4;
                                do {
                                    uint32_t priors = 0;
                                    int32_t e1 = *(int32_t*)(*(int32_t*)(self + 0x14) +
                                        *(int32_t*)rowAddr * 4);
                                    if (m34 != 0) {
                                        uint32_t walk = pn[2];
                                        do {
                                            int32_t e2 = *(int32_t*)(*(int32_t*)(self + 0x14) +
                                                *(int32_t*)walk * 4);
                                            if ((*(int32_t*)(e1 + 4) == *(int32_t*)(e2 + 4)) &&
                                                (*(int32_t*)(e1 + 8) == *(int32_t*)(e2 + 8)) &&
                                                (*(int32_t*)(e1 + 0xc) == *(int32_t*)(e2 + 0xc))) {
                                                break;
                                            }
                                            ++priors;
                                            walk += stride;
                                        } while (priors < m34);
                                    }
                                    if ((m34 == priors) &&
                                        (*(int32_t*)(e1 + 4) == *(int32_t*)(self + 0x88)) &&
                                        (1 < *(uint32_t*)(e1 + 0xc))) {
                                        ++m20;
                                    }
                                    ++m34;
                                    rowAddr += stride;
                                } while (m34 < m30);
                                if (2 < m20) {
                                    if (param_1 != 0) return -0x7fffbffb;
                                    if (param_2 != 0) return -0x7fffbffb;
                                    goto err_62da;
                                }
                            }
                        }

                        {
                            uint32_t nth2 = dnode[3];
                            bool anyB = false;
                            m1c = 0;
                            if (nth2 != 0) {
                                int32_t* ids = (int32_t*)dnode[4];
                                do {
                                    if (*(int32_t*)(*(int32_t*)(*(int32_t*)(self + 0x14) +
                                                               *ids * 4) + 0xc) == -1) {
                                        m1c = 1;
                                    } else {
                                        anyB = true;
                                    }
                                    ++ids;
                                    --nth2;
                                } while (nth2 != 0);
                                if (anyB) {
                                    if (m1c == 0) goto next_230;
                                    goto err_62da;
                                }
                            }
                        }

                        int32_t h5 = *(int32_t*)(*(int32_t*)(self + 0x230) + (int32_t)idx * 4);
                        m2c = 0;
                        FUN_006788f0(self, *(uint32_t*)(self + 0x230), (uint32_t)idx + 1,
                                     *(uint32_t*)(self + 0x224), *(uint32_t*)(h5 + 0x10),
                                     *(uint32_t*)(h5 + 0xc), local_16c, &m2c);
                        m1c = 0xffffffff;
                        m10 = 0xffffffff;
                        m8 = *(uint32_t*)(self + 200) & 0xffff;
                        if ((m8 == 0x102) || (m8 == 0x103)) {
                            int32_t* pn2 = *(int32_t**)(*(int32_t*)(self + 0x230) +
                                                        (int32_t)idx * 4);
                            if (*pn2 == 0x50000004) {
                                int32_t* first = (int32_t*)pn2[2];
                                int32_t ea = *(int32_t*)(*(int32_t*)(self + 0x14) + *first * 4);
                                if (*(int32_t*)(ea + 4) == *(int32_t*)(self + 0x88)) {
                                    m1c = *(uint32_t*)(ea + 0xc);
                                }
                                int32_t eb = *(int32_t*)(*(int32_t*)(self + 0x14) +
                                                         first[4] * 4);
                                if (*(int32_t*)(eb + 4) == *(int32_t*)(self + 0x88)) {
                                    m10 = *(uint32_t*)(eb + 0xc);
                                }
                            }
                        }

                        m34 = 0;
                        m24 = 0;
                        if (m2c == 0) {
                            m18 = 1;
                            if (*(int32_t*)(self + 0x44c) == 0) m18 = 0;
                            goto after_flag;
                        }
                        do {
                            uint32_t scanIdx = idx + 1;
                            if (scanIdx < *(uint32_t*)(self + 0x224)) {
                                uint32_t left = *(uint32_t*)(self + 0x224) - scanIdx;
                                do {
                                    uint32_t* nd = *(uint32_t**)(*(int32_t*)(self + 0x230) +
                                                                 scanIdx * 4);
                                    if ((nd != 0) && ((*nd & 0xfff00000) == 0x70f00000)) {
                                        uint32_t cnt = *nd & 0xfffff;
                                        if (cnt != 0) {
                                            int32_t* ids = (int32_t*)nd[2];
                                            uint32_t q = cnt;
                                            do {
                                                if (*ids == local_16c[m24]) m34 = 1;
                                                ++ids;
                                                --q;
                                            } while (q != 0);
                                        }
                                    }
                                    ++scanIdx;
                                    --left;
                                } while (left != 0);
                            }
                            ++m24;
                        } while (m24 < m2c);
                        if (m34 == 0) {
                            m18 = 1;
                            if (*(int32_t*)(self + 0x44c) == 0) m18 = 0;
                            goto after_flag;
                        }
                        m18 = 0;

                    after_flag:
                        {
                            uint32_t* nodePtr = *(uint32_t**)((int32_t)idx * 4 +
                                                              *(int32_t*)(self + 0x230));
                            word = *nodePtr;
                            if (((word & 0xfffff) == 1) && ((word & 0xfff00000) != 0x50000000) &&
                                (m2c == 1) &&
                                (*(int32_t*)(*(int32_t*)(*(int32_t*)(self + 0x14) +
                                                         local_16c[0] * 4) + 0x10) == 3) &&
                                (m18 != 0)) {
                                m24 = 1;
                                do {
                                    bool found = (idx < local_5c[m24]) &&
                                                 (local_b8[(m24 - 1) * 4] <= idx);
                                    if (found) break;
                                    ++m24;
                                } while (m24 < 6);
                                if (m24 == 6) goto lab_679ff2;
                            } else {
                            lab_679ff2:
                                m24 = (m18 != 0) ? 1 : 0;
                                while ((m24 < 6) &&
                                       ((idx < local_5c[m24]) || (m24 == m1c) || (m24 == m10))) {
                                    ++m24;
                                }
                            }

                            if ((m24 != 0) && (m18 == 0) &&
                                (*(int32_t*)(self + 0x44c) != 0)) {
                                goto joined_679e00;
                            }
                            if (m24 == 6) {
                                if ((*(uint32_t*)(self + 200) & 0xffff) != 0x104) goto err_62da;
                                if (param_2 == 0) goto err_62da;
                                return -0x7fffbffb;
                            }

                            m3c = 0;
                            if (((word & 0xfff00000) == 0x50000000) && (m8 < 0x104) &&
                                (nodePtr[3] == 1)) {
                                int32_t boff = (int32_t)idx * 4;
                                int32_t h6 = *(int32_t*)(boff + *(int32_t*)(self + 0x230));
                                FUN_00678a8e(self, *(uint32_t*)(self + 0x230),
                                             (uint32_t)idx + 1, *(uint32_t*)(self + 0x224),
                                             *(uint32_t*)(h6 + 0x10),
                                             *(uint32_t*)(h6 + 0xc),
                                             &m28, &m44, &m40);
                                if (m44 != 0) m28 = 4;
                                bool lt4 = m28 < 4;
                                if (lt4) m28 = 3;
                                if (!lt4 && m28 != 4) m28 = 4;

                                int32_t raw = FUN_0065d0b4();
                                obj2 = (raw == 0) ? 0 :
                                       (uint32_t*)(uintptr_t)FUN_0065cc1a();
                                if (obj2 == 0) return -0x7ff8fff2;

                                uint32_t* src = *(uint32_t**)(boff +
                                                              *(int32_t*)(self + 0x230));
                                int32_t hr = FUN_0065d0ff(src[0], src[1], m28, 0);
                                if (hr < 0) return hr;
                                hr = FUN_0065cc50();
                                if (hr < 0) return hr;

                                {
                                    uint32_t* s2 = *(uint32_t**)(*(int32_t*)(boff +
                                        *(int32_t*)(self + 0x230)) + 8);
                                    uint32_t* d2 = *(uint32_t**)((uint8_t*)obj2 + 8);
                                    for (uint32_t n = *(uint32_t*)((uint8_t*)obj2 + 4) & 0x3fffffff;
                                         n != 0; --n) *d2++ = *s2++;
                                }

                                int32_t hh2 = *(int32_t*)(boff + *(int32_t*)(self + 0x230));
                                uint32_t saveCount = *(uint32_t*)(hh2 + 0xc);
                                uint32_t* slotPtr = *(uint32_t**)(hh2 + 0x10);
                                uint32_t* dstB = &local_74[2];
                                m30 = saveCount;
                                for (; saveCount != 0; --saveCount) *dstB++ = *slotPtr++;

                                *(uint32_t**)(boff + *(int32_t*)(self + 0x230)) = obj2;
                                hr = FUN_0065d8c2();
                                if (hr < 0) return hr;

                                m10 = 0;
                                m1c = 0;
                                m3c = 0;
                                {
                                    uint32_t refScan = 0;
                                    uint32_t maxRef = 0;
                                    if (m30 != 0) {
                                        do {
                                            m18 = 0;
                                            if (*(int32_t*)(self + 8) != 0) {
                                                do {
                                                    int32_t ent = *(int32_t*)
                                                        (*(int32_t*)(self + 0x14) + m18 * 4);
                                                    if ((m18 == local_74[refScan + 2]) ||
                                                        (*(uint32_t*)(ent + 0x38) ==
                                                         local_74[refScan + 2])) {
                                                        if (m28 != 0) {
                                                            uint32_t q = 0;
                                                            do {
                                                                uint32_t v = (uint32_t)FUN_0065d9d5(
                                                                    *(uint32_t*)(self + 0x88),
                                                                    m24, q, 0);
                                                                *(uint32_t*)(obj2[4] + q * 4) = v;
                                                                if (*(int32_t*)(obj2[4] + q * 4) == -1)
                                                                    return -0x7ff8fff2;
                                                                int32_t ne = *(int32_t*)
                                                                    (*(int32_t*)(self + 0x14) +
                                                                     *(int32_t*)(obj2[4] + q * 4) * 4);
                                                                *(uint32_t*)(ne + 0x48) =
                                                                    *(uint32_t*)(ent + 0x48);
                                                                *(uint32_t*)(ne + 0x54) =
                                                                    *(uint32_t*)(ent + 0x54);
                                                                *(uint32_t*)(ne + 0x58) =
                                                                    *(uint32_t*)(ent + 0x58);
                                                                ++q;
                                                                *(uint32_t*)(ne + 0x3c) =
                                                                    *(uint32_t*)(ent + 0x3c);
                                                            } while (q < m28);
                                                        }

                                                        uint32_t scan2 = idx + 1;
                                                        while (scan2 < *(uint32_t*)(self + 0x224)) {
                                                            uint32_t* nd = *(uint32_t**)
                                                                (*(int32_t*)(self + 0x230) + scan2 * 4);
                                                            if ((nd != 0) && (*nd != 0)) {
                                                                uint32_t cols3 = *nd & 0xfffff;
                                                                uint32_t rows3 = nd[1] / cols3;
                                                                uint32_t r3 = 0;
                                                                while (r3 < rows3) {
                                                                    uint32_t ro = r3 * cols3 * 4;
                                                                    if (cols3 < 3) {
                                                                        if (cols3 == 1) {
                                                                            if (*(uint32_t*)
                                                                                    (nd[2] + ro) == m18) {
                                                                                uint32_t repl = (m28 == 4) ?
                                                                                    *(uint32_t*)(obj2[4] + 0xc) :
                                                                                    *(uint32_t*)obj2[4];
                                                                                *(uint32_t*)(nd[2] + ro) = repl;
                                                                                if (m10 < scan2) m10 = scan2;
                                                                            }
                                                                        } else {
                                                                            for (uint32_t c3 = 0; c3 < cols3; ++c3) {
                                                                                if (*(uint32_t*)(nd[2] + ro + c3 * 4) == m18) {
                                                                                    *(uint32_t*)(nd[2] + ro + c3 * 4) =
                                                                                        *(uint32_t*)(obj2[4] + c3 * 4);
                                                                                    if (m10 < scan2) m10 = scan2;
                                                                                }
                                                                            }
                                                                        }
                                                                    } else {
                                                                        for (uint32_t c3 = 0; c3 < cols3; ++c3) {
                                                                            if (*(uint32_t*)(nd[2] + ro + c3 * 4) == m18) {
                                                                                *(uint32_t*)(nd[2] + ro + c3 * 4) =
                                                                                    *(uint32_t*)(obj2[4] + c3 * 4);
                                                                                if (m10 < scan2) m10 = scan2;
                                                                            }
                                                                        }
                                                                    }
                                                                    ++r3;
                                                                }
                                                            }
                                                            ++scan2;
                                                        }
                                                        m3c = 1;
                                                        maxRef = m10;
                                                    }
                                                    ++m18;
                                                } while (m18 < *(uint32_t*)(self + 8));
                                            }
                                            ++refScan;
                                        } while (refScan < m30);
                                    }
                                    if (local_5c[m24] < maxRef) local_5c[m24] = maxRef;
                                    if (local_d4[m24 * 4] < maxRef) local_d4[m24 * 4] = maxRef;
                                    if (local_d4[m24 * 4 + 1] < maxRef) local_d4[m24 * 4 + 1] = maxRef;
                                    if (local_d4[m24 * 4 + 2] < maxRef) local_d4[m24 * 4 + 2] = maxRef;
                                    if (local_d4[m24 * 4 + 3] < maxRef) local_d4[m24 * 4 + 3] = maxRef;
                                    if (m3c != 0) goto next_230;
                                }
                            }

                            m10 = 0;
                            if (m2c == 0) {
                                *(uint32_t*)((int32_t)idx * 4 + *(int32_t*)(self + 0x230)) = 0;
                            } else {
                                m8 = 0;
                                do {
                                    int32_t eid = local_16c[m8];
                                    int32_t ent = *(int32_t*)(*(int32_t*)(self + 0x14) +
                                                              eid * 4);
                                    *(uint32_t*)(ent + 0xc) = m24;
                                    uint32_t r = (uint32_t)FUN_00677000(
                                        *(uint32_t*)(self + 0x230), (uint32_t)idx + 1,
                                        *(uint32_t*)(self + 0x224), (uint32_t)eid, (void*)ent,
                                        &m1cOut);
                                    if (m10 < r) m10 = r;
                                    ++m8;
                                    local_d4[*(int32_t*)(ent + 0x10) + (int32_t)m24 * 4] = r;
                                } while (m8 < m2c);
                                if (local_5c[m24] < m10) local_5c[m24] = m10;
                                FUN_00678a4f(self);
                            }
                        }
                    }
                }
            }
        next_230:
            ++idx;
        } while (idx < *(uint32_t*)(self + 0x224));
    }

    if ((*(int32_t*)(self + 0x22c) == 0) ||
        ((*(uint32_t*)(self + 200) & 0xffff) != 0x104) || (param_1 != 0)) {
        status = 0;
    } else {
        status = FUN_0067967f(self);
        if (status >= 0) status = 0;
    }
    return status;

err_62da:
    FUN_006626da();
    return -0x7fffbffb;

joined_679e00:
    if (param_1 == 0) {
        if (param_2 == 0) goto err_62da;
    }
    return -0x7fffbffb;
}

// ============================================================================
// 0x67a679 — observed shape
// Scans param_1[0..param_2) for the first container whose +0xc count covers
// param_4 and whose element list contains every wanted id (param_3). With
// param_5 == 0 the match also requires the target entry's +0x3c to be 0 and
// allows a +0x38 link; otherwise only the direct id or the +0x38 link is
// checked. A container with a zero count trivially matches. Returns the
// container pointer (as an integer) or 0.
// ============================================================================
uint32_t FUN_0067a679(void* self_raw, int32_t param_1, uint32_t param_2, int32_t param_3,
                      uint32_t param_4, int32_t param_5)
{
    uint8_t* self = (uint8_t*)self_raw;

    for (uint32_t i = 0; i < param_2; ++i) {
        int32_t c = *(int32_t*)(param_1 + i * 4);
        if ((c == 0) || (param_4 > *(uint32_t*)(c + 0xc))) continue;

        if (param_4 == 0) return (uint32_t)*(int32_t*)(param_1 + i * 4);

        bool all = true;
        for (uint32_t w = 0; w < param_4; ++w) {
            int32_t id = *(int32_t*)(param_3 + w * 4);
            int32_t e = *(int32_t*)(*(int32_t*)(self + 0x14) + id * 4);
            uint32_t cnt = *(uint32_t*)(c + 0xc);
            uint32_t n = 0;
            bool found = (cnt == 0);

            if (param_5 == 0) {
                if (cnt != 0) {
                    int32_t* ids = *(int32_t**)(c + 0x10);
                    do {
                        int32_t v = *ids;
                        if (((v == id) && (*(int32_t*)(e + 0x3c) == 0)) ||
                            ((v == *(int32_t*)(e + 0x38)) &&
                             (*(int32_t*)(*(int32_t*)(*(int32_t*)(self + 0x14) + v * 4) +
                                          0x3c) == 0))) {
                            break;
                        }
                        ++n;
                        ++ids;
                    } while (n < cnt);
                    found = (n == cnt);
                }
            } else {
                if (cnt != 0) {
                    int32_t* ids = *(int32_t**)(c + 0x10);
                    do {
                        if ((*ids == id) || (*ids == *(int32_t*)(e + 0x38))) break;
                        ++n;
                        ++ids;
                    } while (n < cnt);
                    found = (n == cnt);
                }
            }

            if (found) {
                all = false;
                break;
            }
        }
        if (all) return (uint32_t)*(int32_t*)(param_1 + i * 4);
    }
    return 0;
}
