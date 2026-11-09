//
// mass_0318.cpp — reconstruction batch mass_0318
// Target: Sid Meier's Pirates! (2004), PE32 i386
// Image: 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
//
// Each definition preserves the observed field offsets, constants, call
// order, return shape, and conditional structure of the Ghidra 12.2
// pseudocode (analysis/pseudocode/functions/*.c).
//
// Register receivers (in_ECX) are modeled as an explicit `void* self`.
// The listing's tables live at self+0x10 (surface table), self+0x14 (node
// table), self+0x18 (array slot table); self+0x6c holds the flag word and
// self+0x74 / self+0x78 / self+0x88 are scratch-handle slots. Raw 32-bit
// "addresses" from the provider listing are routed through P()/i32()/u32()
// so the exact dereference sequence stays visible.
//
#include <cstdint>
#include <cstddef>

// ---------------------------------------------------------------------------
// Provider-listing memory access helpers.
// ---------------------------------------------------------------------------
static inline void* P(uint32_t a)
{
    return reinterpret_cast<void*>(static_cast<uintptr_t>(a));
}
static inline int32_t  i32(const void* p) { return *static_cast<const int32_t*>(p); }
static inline uint32_t u32(const void* p) { return *static_cast<const uint32_t*>(p); }
static inline uint8_t  u8(const void* p)  { return *static_cast<const uint8_t*>(p); }
static inline double   f64(const void* p) { return *static_cast<const double*>(p); }
static inline void si32(void* p, int32_t v)  { *static_cast<int32_t*>(p) = v; }
static inline void su32(void* p, uint32_t v) { *static_cast<uint32_t*>(p) = v; }
static inline int32_t*  pi32(const void* p)  { return *static_cast<int32_t* const*>(p); }
static inline uint32_t* pu32(const void* p)  { return *static_cast<uint32_t* const*>(p); }

// ---------------------------------------------------------------------------
// Helpers referenced by the assigned corpus files. Only names that occur in
// the supplied listings are declared here.
// ---------------------------------------------------------------------------
int32_t  FUN_0065ccdf();
void     FUN_0065cc50(...);          // listing shows both `()` and `(param_1)`
int32_t  FUN_0065cea4();
uint32_t FUN_0065da35(uint32_t a, uint32_t b, uint32_t c);
uint32_t FUN_0065d9d5(uint32_t handle, uint32_t a, uint32_t b, double scale);
int32_t  FUN_0065db2e(int32_t a);
uint32_t FUN_0065cc6f(int32_t index, int32_t** out);
void     FUN_0065d5bd();
int32_t  FUN_0065fa14(void* self, int32_t a, int32_t b);
int32_t  FUN_0065fa89(void* self, int32_t a, int32_t b);
int32_t  FUN_0065fab6(void* self, uint32_t* param_1, int32_t param_2, int32_t param_3);
int32_t  FUN_0065f0a1(void* self, int32_t param_1, int32_t param_2);
int32_t  FUN_0065f17e(void* self, int32_t param_1, int32_t* param_2, double* param_3);
int32_t  FUN_0065f408(void* self, uint32_t param_1, int32_t* param_2, int32_t* param_3,
                      int32_t* param_4, int32_t* param_5, int32_t* param_6);
uint32_t FUN_0065fb5b(void* self, uint32_t* param_1);
int32_t  FUN_0066040e(void* self, int32_t param_1);
void     FUN_00660d40(void* self, int32_t param_1, int32_t* param_2, int32_t param_3);

// ---------------------------------------------------------------------------
// 0x65e58c — observed shape
// Walk the surface table and repoint each node's +4 field to self+0x74 when
// the surface flags carry 0x30 without 0x200, or to self+0x88 when bit 4 is
// set. Then walk the array-slot table and, for flagged slots (high bits of
// the header word non-zero), compact entries whose node lacks flag 0x20,
// rewrite the header word's low 20 bits, the stride at +4 and the count at
// +0xc, and relink the node chain.
// ---------------------------------------------------------------------------
uint32_t FUN_0065e58c(void* self)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t* puVar1;
    int32_t* piVar2;
    int32_t iVar3;
    uint32_t uVar4;
    int32_t iVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    uint32_t local_18;
    uint32_t local_14;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;

    uVar6 = 0;
    if (i32(base + 8) != 0) {
        do {
            iVar3 = i32(P(u32(base + 0x14) + uVar6 * 4));
            iVar5 = i32(P(u32(base + 0x10) + i32(P(iVar3 + 4)) * 4));
            uVar4 = u32(P(iVar5 + 4));
            if (((uVar4 & 0x30) != 0) && ((uVar4 & 0x200) == 0)) {
                su32(P(iVar3 + 4), u32(base + 0x74));
            }
            if ((u8(P(iVar5 + 4)) & 4) != 0) {
                su32(P(iVar3 + 4), u32(base + 0x88));
            }
            uVar6 = uVar6 + 1;
        } while (uVar6 < u32(base + 8));
    }
    local_14 = 0;
    if (i32(base + 0xc) != 0) {
        do {
            puVar1 = pu32(P(u32(base + 0x18) + local_14 * 4));
            uVar6 = *puVar1;
            if ((uVar6 & 0xfff00000) != 0) {
                local_c = 0;
                if (puVar1[3] != 0) {
                    local_18 = puVar1[3];
                    piVar2 = reinterpret_cast<int32_t*>(puVar1[4]);
                    do {
                        if ((u8(P(u32(base + 0x14) + *piVar2 * 4)) & 0x20) != 0) {
                            local_c = local_c + 1;
                        }
                        piVar2 = piVar2 + 1;
                        local_18 = local_18 - 1;
                    } while (local_18 != 0);
                }
                uVar4 = puVar1[3];
                if (local_c == uVar4) {
                    *puVar1 = 0;
                } else {
                    if (((local_c < uVar4) && (0xfffffff < (uVar6 & 0xf0000000))) &&
                        ((uVar6 & 0xf0000000) < 0x40000001)) {
                        uVar6 = puVar1[1] / (uVar6 & 0xfffff);
                        uVar7 = 0;
                        local_8 = 0;
                        if (uVar4 != 0) {
                            do {
                                iVar3 = i32(P(puVar1[4] + local_8 * 4));
                                if ((u8(P(u32(base + 0x14) + iVar3 * 4)) & 0x20) == 0) {
                                    local_10 = 0;
                                    si32(P(puVar1[4] + uVar7 * 4), iVar3);
                                    if (uVar6 != 0) {
                                        do {
                                            iVar3 = static_cast<int32_t>(puVar1[3] * local_10);
                                            local_10 = local_10 + 1;
                                            su32(P(puVar1[2] + (iVar3 + uVar7) * 4),
                                                 u32(P(puVar1[2] + (local_8 + iVar3) * 4)));
                                        } while (local_10 < uVar6);
                                    }
                                    uVar7 = uVar7 + 1;
                                }
                                local_8 = local_8 + 1;
                            } while (local_8 < puVar1[3]);
                        }
                        local_8 = 1;
                        if (1 < uVar6) {
                            local_18 = uVar7 << 2;
                            do {
                                local_10 = 0;
                                if (uVar7 != 0) {
                                    uVar4 = local_18;
                                    do {
                                        iVar3 = static_cast<int32_t>(puVar1[3] * local_8 + local_10);
                                        local_10 = local_10 + 1;
                                        su32(P(uVar4 + puVar1[2]),
                                             u32(P(puVar1[2] + iVar3 * 4)));
                                        uVar4 = uVar4 + 4;
                                    } while (local_10 < uVar7);
                                }
                                local_8 = local_8 + 1;
                                local_18 = local_18 + uVar7 * 4;
                            } while (local_8 < uVar6);
                        }
                        *puVar1 = *puVar1 ^ (*puVar1 ^ uVar7) & 0xfffff;
                        puVar1[1] = uVar7 * uVar6;
                        puVar1[3] = uVar7;
                    }
                    local_10 = 0;
                    if (puVar1[3] != 0) {
                        do {
                            iVar3 = i32(P(u32(base + 0x14) +
                                          i32(P(puVar1[4] + local_10 * 4)) * 4));
                            local_18 = u32(P(iVar3 + 0x18));
                            iVar5 = i32(P(iVar3 + 0x14));
                            while ((iVar5 != -1) &&
                                   ((u8(P(iVar5 * 4 + u32(base + 0x14))) & 0x20) != 0)) {
                                iVar5 = i32(P(iVar5 * 4 + u32(base + 0x14)));
                                local_18 = u32(P(iVar5 + 0x18));
                                iVar5 = i32(P(iVar5 + 0x14));
                            }
                            local_10 = local_10 + 1;
                            su32(P(iVar3 + 0x18), local_18);
                            si32(P(iVar3 + 0x14), iVar5);
                        } while (local_10 < puVar1[3]);
                    }
                }
            }
            local_14 = local_14 + 1;
        } while (local_14 < u32(base + 0xc));
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x65e79d — observed shape
// Same array-slot walk as 0x65e58c, but only headers outside
// {0x00000000, 0x10100000}; counts entries whose node *has* flag 0x20,
// compacts those entries, and returns false as soon as any slot was
// touched. No chain relink pass.
// ---------------------------------------------------------------------------
bool FUN_0065e79d(void* self)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t* puVar1;
    bool bVar2;
    int32_t* piVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    int32_t iVar6;
    uint32_t uVar7;
    uint32_t local_18;
    uint32_t local_14;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;

    bVar2 = false;
    local_14 = 0;
    if (i32(base + 0xc) != 0) {
        do {
            puVar1 = pu32(P(u32(base + 0x18) + local_14 * 4));
            uVar4 = *puVar1;
            if ((((uVar4 & 0xfff00000) != 0) && ((uVar4 & 0xfff00000) != 0x10100000)) &&
                (local_8 = 0, puVar1[3] != 0)) {
                local_18 = puVar1[3];
                piVar3 = reinterpret_cast<int32_t*>(puVar1[4]);
                do {
                    if ((u8(P(u32(base + 0x14) + *piVar3 * 4)) & 0x20) == 0) {
                        local_8 = local_8 + 1;
                    }
                    piVar3 = piVar3 + 1;
                    local_18 = local_18 - 1;
                } while (local_18 != 0);
                if (local_8 != 0) {
                    bVar2 = true;
                    if (local_8 == puVar1[3]) {
                        *puVar1 = 0;
                    } else if (((local_8 < puVar1[3]) && (0xfffffff < (uVar4 & 0xf0000000))) &&
                               ((uVar4 & 0xf0000000) < 0x40000001)) {
                        uVar4 = puVar1[1] / (uVar4 & 0xfffff);
                        uVar7 = 0;
                        uVar5 = 0;
                        do {
                            iVar6 = i32(P(puVar1[4] + uVar5 * 4));
                            if ((u8(P(u32(base + 0x14) + iVar6 * 4)) & 0x20) != 0) {
                                local_c = 0;
                                si32(P(puVar1[4] + uVar7 * 4), iVar6);
                                if (uVar4 != 0) {
                                    do {
                                        iVar6 = static_cast<int32_t>(puVar1[3] * local_c);
                                        local_c = local_c + 1;
                                        su32(P(puVar1[2] + (iVar6 + uVar7) * 4),
                                             u32(P(puVar1[2] + (iVar6 + uVar5) * 4)));
                                    } while (local_c < uVar4);
                                }
                                uVar7 = uVar7 + 1;
                            }
                            uVar5 = uVar5 + 1;
                        } while (uVar5 < puVar1[3]);
                        local_10 = 1;
                        if (1 < uVar4) {
                            local_18 = uVar7 << 2;
                            do {
                                local_c = 0;
                                if (uVar7 != 0) {
                                    uVar5 = local_18;
                                    do {
                                        iVar6 = static_cast<int32_t>(puVar1[3] * local_10 + local_c);
                                        local_c = local_c + 1;
                                        su32(P(uVar5 + puVar1[2]), u32(P(puVar1[2] + iVar6 * 4)));
                                        uVar5 = uVar5 + 4;
                                    } while (local_c < uVar7);
                                }
                                local_10 = local_10 + 1;
                                local_18 = local_18 + uVar7 * 4;
                            } while (local_10 < uVar4);
                        }
                        *puVar1 = *puVar1 ^ (*puVar1 ^ uVar7) & 0xfffff;
                        puVar1[1] = uVar7 * uVar4;
                        puVar1[3] = uVar7;
                    }
                }
            }
            local_14 = local_14 + 1;
        } while (local_14 < u32(base + 0xc));
    }
    return !bVar2;
}

// ---------------------------------------------------------------------------
// 0x65e935 — observed shape
// Predicate over two "linked path" cursors (node index + accumulated weight):
// an unset lhs cursor adopts the rhs pair; otherwise both chains are walked
// to equal length and then compared step by step, storing the walk result at
// *param_2 and the index at *param_1. Returns 0.
// ---------------------------------------------------------------------------
uint32_t FUN_0065e935(void* self, int32_t* param_1, int32_t* param_2,
                      int32_t param_3, int32_t param_4)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    int32_t iVar1;
    int32_t iVar2;
    int32_t iVar4;
    int32_t iVar5;
    uint32_t uVar3;
    uint32_t local_8;

    iVar2 = *param_1;
    if ((iVar2 == -1) && (*param_2 == 0)) {
        *param_2 = param_4;
        iVar2 = param_3;
LAB_0065ea1e:
        *param_1 = iVar2;
    } else if ((param_3 != -1) || (param_4 != 0)) {
        uVar3 = 0;
        local_8 = 0;
        if (iVar2 != -1) {
            iVar4 = iVar2;
            do {
                iVar4 = i32(P(i32(P(u32(base + 0x14) + iVar4 * 4)) + 0x14));
                uVar3 = uVar3 + 1;
            } while (iVar4 != -1);
        }
        if (param_3 != -1) {
            iVar4 = param_3;
            do {
                iVar4 = i32(P(i32(P(u32(base + 0x14) + iVar4 * 4)) + 0x14));
                local_8 = local_8 + 1;
            } while (iVar4 != -1);
        }
        iVar4 = *param_2;
        if (local_8 < uVar3) {
            iVar5 = static_cast<int32_t>(uVar3 - local_8);
            do {
                iVar2 = i32(P(u32(base + 0x14) + iVar2 * 4));
                iVar4 = i32(P(iVar2 + 0x18));
                iVar2 = i32(P(iVar2 + 0x14));
                uVar3 = uVar3 - 1;
                iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
        }
        if (uVar3 < local_8) {
            iVar5 = static_cast<int32_t>(local_8 - uVar3);
            do {
                iVar5 = iVar5 + -1;
                iVar1 = i32(P(u32(base + 0x14) + param_3 * 4));
                param_4 = i32(P(iVar1 + 0x18));
                param_3 = i32(P(iVar1 + 0x14));
            } while (iVar5 != 0);
        }
        while (true) {
            if ((iVar4 == param_4) && (iVar2 == param_3)) {
                *param_2 = iVar4;
                goto LAB_0065ea1e;
            }
            if ((iVar2 == -1) || (param_3 == -1)) break;
            iVar2 = i32(P(u32(base + 0x14) + iVar2 * 4));
            iVar5 = i32(P(u32(base + 0x14) + param_3 * 4));
            iVar4 = i32(P(iVar2 + 0x18));
            param_4 = i32(P(iVar5 + 0x18));
            iVar2 = i32(P(iVar2 + 0x14));
            param_3 = i32(P(iVar5 + 0x14));
        }
        *param_2 = 0;
        *param_1 = -1;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x65ea37 — observed shape
// Only handles header kind 0x50000000 (else true). Rejects surfaces without
// bit 1 or carrying bit 0x1000. Accumulates an AND-mask of pair relations
// (4/8/2/4) over the slot's operand list and ORs it into the node word.
// With param_2 set it folds the paired operands' +0x20 weights: an
// all-shared/zero folding collapses to a fresh merge node; a two-operand
// relation can flip to a negation. Otherwise it classifies operands into
// ready/not-ready groups, keeps the largest ready group, and rewrites the
// slot header (0x10000001 / 0x20400001 / size|0x50000000) and its id list.
// ---------------------------------------------------------------------------
bool FUN_0065ea37(void* self, uint32_t* param_1, int32_t param_2)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t* puVar1;
    uint32_t* puVar2;
    bool bVar3;
    uint32_t* puVar4;
    uint32_t uVar5;
    int32_t* piVar6;
    int32_t iVar7;
    uint32_t uVar8;
    int32_t iVar9;
    int32_t iVar10;
    uint32_t uVar11;
    uint32_t* puVar13;
    bool bVar15;
    double local_3c;
    int32_t* local_2c;
    int32_t local_28;
    uint32_t local_24;
    uint32_t local_20;
    int32_t* local_1c;
    uint32_t local_18;
    int32_t* local_14;
    int32_t local_10;
    uint32_t local_c;
    uint32_t uCount;

    puVar4 = param_1;
    if ((*param_1 & 0xfff00000) != 0x50000000) {
        return true;
    }
    puVar1 = pu32(P(u32(base + 0x14) + static_cast<int32_t>(param_1[4]) * 4));
    uVar11 = u32(P(i32(P(u32(base + 0x10) + puVar1[1] * 4)) + 4));
    if ((uVar11 & 1) == 0) {
        return true;
    }
    if ((uVar11 & 0x1000) != 0) {
        return true;
    }
    uVar11 = *param_1 & 0xfffff;
    local_18 = 0xe;
    if (uVar11 != 0) {
        piVar6 = reinterpret_cast<int32_t*>(param_1[2]);
        local_14 = piVar6 + uVar11;
        local_24 = uVar11;
        do {
            iVar9 = i32(base + 0x14);
            if (param_2 == 0) {
                puVar13 = pu32(P(static_cast<uint32_t>(iVar9) + *piVar6 * 4));
                iVar10 = *local_14;
            } else {
                puVar13 = pu32(P(static_cast<uint32_t>(iVar9) +
                                 i32(P(i32(P(static_cast<uint32_t>(iVar9) + *piVar6 * 4)) + 0x30)) * 4));
                iVar10 = i32(P(i32(P(static_cast<uint32_t>(iVar9) + *local_14 * 4)) + 0x30));
            }
            puVar2 = pu32(P(static_cast<uint32_t>(iVar9) + iVar10 * 4));
            uVar8 = *puVar13;
            local_c = 0;
            if (((((uVar8 & 4) != 0) && ((*puVar2 & 4) != 0)) ||
                 (((uVar8 & 8) != 0 && ((*puVar2 & 8) != 0)))) || (puVar13 == puVar2)) {
                local_c = 4;
            }
            if ((((uVar8 & 4) != 0) && ((*puVar2 & 8) != 0)) ||
                (((uVar8 & 8) != 0 && ((*puVar2 & 4) != 0)))) {
                local_c = local_c | 8;
            }
            if (((uVar8 & 2) != 0) && ((*puVar2 & 2) != 0)) {
                local_c = local_c | 2;
            }
            local_18 = local_18 & local_c;
            local_14 = local_14 + 1;
            piVar6 = piVar6 + 1;
            local_24 = local_24 - 1;
        } while (local_24 != 0);
    }
    *puVar1 = *puVar1 | local_18;
    if (param_2 != 0) {
        local_24 = 0xffffffff;
        local_3c = 0.0;
        local_c = 0;
        local_10 = 0;
        local_20 = 0;
        if (uVar11 != 0) {
            local_1c = reinterpret_cast<int32_t*>(param_1[2]);
            iVar9 = i32(base + 0x14);
            local_2c = local_1c + uVar11;
            do {
                uVar8 = u32(P(i32(P(static_cast<uint32_t>(iVar9) + *local_2c * 4)) + 0x30));
                uVar5 = u32(P(i32(P(static_cast<uint32_t>(iVar9) + *local_1c * 4)) + 0x30));
                iVar10 = i32(P(static_cast<uint32_t>(iVar9) + uVar8 * 4));
                iVar7 = i32(P(static_cast<uint32_t>(iVar9) + uVar5 * 4));
                if (((u8(P(i32(P(u32(base + 0x10) + i32(P(iVar7 + 4)) * 4)) + 5)) & 1) == 0) ||
                    (i32(P(iVar7 + 8)) != -1)) {
                    bVar15 = false;
                } else {
                    bVar15 = true;
                }
                if (((u8(P(i32(P(u32(base + 0x10) + i32(P(iVar10 + 4)) * 4)) + 5)) & 1) == 0) ||
                    (i32(P(iVar10 + 8)) != -1)) {
                    bVar3 = false;
                } else {
                    bVar3 = true;
                }
                if (((bVar15) && (f64(P(static_cast<uint32_t>(iVar7) + 0x20)) == 0.0)) ||
                    ((bVar3 && (f64(P(static_cast<uint32_t>(iVar10) + 0x20)) == 0.0)))) {
LAB_0065ec37:
                    local_c = local_c + 1;
                } else {
                    if (bVar15) {
                        if (bVar3) {
                            local_3c = f64(P(static_cast<uint32_t>(iVar10) + 0x20)) *
                                           f64(P(static_cast<uint32_t>(iVar7) + 0x20)) + local_3c;
                            goto LAB_0065ec37;
                        }
                        if (f64(P(static_cast<uint32_t>(iVar7) + 0x20)) != 1.0) break;
                        uVar5 = uVar8;
                    } else if ((!bVar3) ||
                               (f64(P(static_cast<uint32_t>(iVar10) + 0x20)) != 1.0)) {
                        break;
                    }
                    local_10 = local_10 + 1;
                    local_24 = uVar5;
                }
                local_20 = local_20 + 1;
                local_1c = local_1c + 1;
                local_2c = local_2c + 1;
            } while (local_20 < uVar11);
            if (((local_10 == 1) && (uVar11 - 1 == local_c)) && (local_3c == 0.0)) {
                *param_1 = 0;
                puVar1[0xc] = local_24;
                return false;
            }
        }
        if (uVar11 == local_c) {
            *param_1 = 0;
            uVar11 = FUN_0065d9d5(u32(base + 0x78), 0, 0, local_3c);
            puVar1[0xc] = uVar11;
            su32(P(i32(P(u32(base + 0x14) + uVar11 * 4)) + 0x30), uVar11);
            return false;
        }
    }
    local_28 = 0;
    local_c = 0;
    local_10 = 0;
    bVar15 = false;
    if (uVar11 != 0) {
        local_14 = reinterpret_cast<int32_t*>(param_1[2]);
        piVar6 = local_14 + uVar11;
        local_2c = reinterpret_cast<int32_t*>(static_cast<intptr_t>(uVar11));
        do {
            iVar9 = i32(base + 0x14);
            iVar10 = *piVar6;
            iVar7 = i32(P(static_cast<uint32_t>(iVar9) + *local_14 * 4));
            if (param_2 != 0) {
                iVar7 = i32(P(static_cast<uint32_t>(iVar9) + i32(P(iVar7 + 0x30)) * 4));
                iVar10 = i32(P(i32(P(static_cast<uint32_t>(iVar9) + iVar10 * 4)) + 0x30));
            }
            iVar9 = i32(P(static_cast<uint32_t>(iVar9) + iVar10 * 4));
            if (((((u8(P(i32(P(u32(base + 0x10) + i32(P(iVar7 + 4)) * 4)) + 5)) & 1) == 0) ||
                  (i32(P(iVar7 + 8)) != -1)) ||
                 (f64(P(static_cast<uint32_t>(iVar7) + 0x20)) != 0.0)) &&
                ((((u8(P(i32(P(u32(base + 0x10) + i32(P(iVar9 + 4)) * 4)) + 5)) & 1) == 0 ||
                   (i32(P(iVar9 + 8)) != -1)) ||
                  (f64(P(static_cast<uint32_t>(iVar9) + 0x20)) != 0.0)))) {
                local_c = local_c + 1;
                local_10 = 0;
            } else {
                local_28 = local_28 + 1;
                local_10 = local_10 + 1;
            }
            local_14 = local_14 + 1;
            piVar6 = piVar6 + 1;
            local_2c = reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(local_2c) - 1);
        } while (local_2c != reinterpret_cast<int32_t*>(0));
        if (((local_28 != 0) && ((local_c != 2 || ((u8(base + 0x6c) & 0x20) != 0)))) &&
            ((local_c == 1 || ((local_28 == local_10 || ((u8(base + 0x6c) & 6) == 0)))))) {
            if (local_c == 0) {
                *param_1 = 0;
                return false;
            }
            local_c = 0;
            local_28 = static_cast<int32_t>(uVar11 << 2);
            local_2c = reinterpret_cast<int32_t*>(0);
            local_14 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(local_28));
            do {
                uVar8 = param_1[2];
                iVar9 = i32(P(uVar8 + reinterpret_cast<intptr_t>(local_2c) * 4));
                iVar10 = i32(base + 0x14);
                local_10 = i32(P(static_cast<uint32_t>(iVar10) + iVar9 * 4));
                if (param_2 == 0) {
                    iVar7 = i32(P(reinterpret_cast<intptr_t>(local_14) + uVar8));
                } else {
                    local_10 = i32(P(static_cast<uint32_t>(iVar10) +
                                     i32(P(local_10 + 0x30)) * 4));
                    iVar7 = i32(P(i32(P(static_cast<uint32_t>(iVar10) +
                                        i32(P(reinterpret_cast<intptr_t>(local_14) + uVar8)) * 4)) +
                                  0x30));
                }
                iVar10 = i32(P(static_cast<uint32_t>(iVar10) + iVar7 * 4));
                if (((u8(P(i32(P(u32(base + 0x10) + i32(P(local_10 + 4)) * 4)) + 5)) & 1) == 0) ||
                    (i32(P(local_10 + 8)) != -1)) {
LAB_0065ee57:
                    if (((u8(P(i32(P(u32(base + 0x10) + i32(P(iVar10 + 4)) * 4)) + 5)) & 1) != 0) &&
                        (i32(P(iVar10 + 8)) == -1)) {
                        if (f64(P(static_cast<uint32_t>(iVar10) + 0x20)) == 0.0) goto LAB_0065ee99;
                    }
                    si32(P(uVar8 + local_c * 4), iVar9);
                    su32(P(static_cast<uint32_t>(local_28) + param_1[2]),
                         u32(P(reinterpret_cast<intptr_t>(local_14) + param_1[2])));
                    local_28 = local_28 + 4;
                    local_c = local_c + 1;
                } else if (f64(P(static_cast<uint32_t>(local_10) + 0x20)) != 0.0) {
                    goto LAB_0065ee57;
                }
LAB_0065ee99:
                local_14 = reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(local_14) + 4);
                local_2c = reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(local_2c) + 1);
            } while (reinterpret_cast<intptr_t>(local_2c) < static_cast<intptr_t>(uVar11));
            {
                uint32_t* puVar12 = P(uVar11 * 4 + param_1[2]);
                uint32_t* puVar14 = P(param_1[2] + local_c * 4);
                for (uVar8 = local_c & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
                    *puVar14 = *puVar12;
                    puVar12 = puVar12 + 1;
                    puVar14 = puVar14 + 1;
                }
                for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
                    *reinterpret_cast<uint8_t*>(puVar14) = *reinterpret_cast<uint8_t*>(puVar12);
                    puVar12 = P(reinterpret_cast<intptr_t>(puVar12) + 1);
                    puVar14 = P(reinterpret_cast<intptr_t>(puVar14) + 1);
                }
            }
            if (local_c == 1) {
                uVar8 = 0x20500001;
            } else {
                uVar8 = local_c & 0xfffff | 0x50000000;
            }
            *param_1 = uVar8;
            param_1[1] = local_c * 2;
            bVar15 = uVar11 != local_c;
            param_1[3] = 1;
            uCount = local_c;
            uVar11 = uCount;
        }
    }
    uCount = uVar11;
    if ((uCount < 2) || ((uCount == 2 && ((u8(base + 0x6c) & 0x20) == 0)))) {
        local_c = 0;
        if (uCount != 0) {
            local_2c = reinterpret_cast<int32_t*>(static_cast<intptr_t>(uCount) << 2);
            do {
                if (param_2 == 0) {
                    iVar9 = i32(P(u32(base + 0x14) + i32(P(puVar4[2] + local_c * 4)) * 4));
                    iVar10 = i32(P(u32(base + 0x14) +
                                   i32(P(reinterpret_cast<intptr_t>(local_2c) + puVar4[2])) * 4));
                } else {
                    iVar10 = i32(base + 0x14);
                    iVar9 = i32(P(static_cast<uint32_t>(iVar10) +
                                  i32(P(i32(P(static_cast<uint32_t>(iVar10) +
                                             i32(P(puVar4[2] + local_c * 4)) * 4)) + 0x30)) * 4));
                    iVar10 = i32(P(static_cast<uint32_t>(iVar10) +
                                   i32(P(i32(P(static_cast<uint32_t>(iVar10) +
                                              i32(P(reinterpret_cast<intptr_t>(local_2c) +
                                                   puVar4[2])) * 4)) + 0x30)) * 4));
                }
                if (((((u8(P(i32(P(u32(base + 0x10) + i32(P(iVar9 + 4)) * 4)) + 5)) & 1) == 0) ||
                      (i32(P(iVar9 + 8)) != -1)) ||
                     (f64(P(static_cast<uint32_t>(iVar9) + 0x20)) != 1.0)) &&
                    ((((u8(P(i32(P(u32(base + 0x10) + i32(P(iVar10 + 4)) * 4)) + 5)) & 1) == 0 ||
                       (i32(P(iVar10 + 8)) != -1)) ||
                      (f64(P(static_cast<uint32_t>(iVar10) + 0x20)) != 1.0)))) {
                    break;
                }
                local_c = local_c + 1;
                local_2c = reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(local_2c) + 4);
            } while (local_c < uCount);
        }
        if (local_c == uCount) {
            local_c = 0;
            if (uCount != 0) {
                local_28 = static_cast<int32_t>(uCount << 2);
                do {
                    piVar6 = reinterpret_cast<int32_t*>(puVar4[2] + local_c * 4);
                    if (param_2 == 0) {
                        iVar9 = i32(P(u32(base + 0x14) + *piVar6 * 4));
                    } else {
                        iVar9 = i32(P(u32(base + 0x14) +
                                      i32(P(i32(P(u32(base + 0x14) + *piVar6 * 4)) + 0x30)) * 4));
                    }
                    if ((((u8(P(i32(P(u32(base + 0x10) + i32(P(iVar9 + 4)) * 4)) + 5)) & 1) != 0) &&
                         (i32(P(iVar9 + 8)) == -1)) &&
                        (f64(P(static_cast<uint32_t>(iVar9) + 0x20)) == 1.0)) {
                        *piVar6 = i32(P(puVar4[2] + static_cast<uint32_t>(local_28)));
                    }
                    local_28 = local_28 + 4;
                    local_c = local_c + 1;
                } while (local_c < uCount);
            }
            if (uCount == 2) {
                *puVar4 = 0x20400001;
                puVar4[1] = 2;
            } else {
                *puVar4 = 0x10000001;
                puVar4[1] = 1;
            }
            bVar15 = true;
        }
    }
    return !bVar15;
}

// ---------------------------------------------------------------------------
// 0x65f0a1 — observed shape
// Reachability predicate: param_1 equals param_2, or param_2 is a node whose
// surface carries bit 2 and whose owning array (reached through node+0x48)
// either references param_1 directly (kind 0x10000000) or has a 0x20500000
// pair whose left or right half reaches param_1. Recurses on the halves.
// ---------------------------------------------------------------------------
int32_t FUN_0065f0a1(void* self, int32_t param_1, int32_t param_2)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t* puVar1;
    uint32_t uVar2;
    int32_t iVar3;
    int32_t uVar4;
    int32_t* piVar5;

    if (param_1 == param_2) {
        return 1;
    }
    iVar3 = i32(P(u32(base + 0x14) + param_2 * 4));
    if ((u8(P(i32(P(u32(base + 0x10) + i32(P(iVar3 + 4)) * 4)) + 4)) & 2) == 0) {
        return 0;
    }
    puVar1 = pu32(P(u32(base + 0x18) + i32(P(iVar3 + 0x48)) * 4));
    if ((*puVar1 & 0xfff00000) == 0x10000000) {
        uVar2 = 0;
        if (puVar1[3] != 0) {
            piVar5 = reinterpret_cast<int32_t*>(puVar1[4]);
            do {
                if (*piVar5 == param_2) break;
                uVar2 = uVar2 + 1;
                piVar5 = piVar5 + 1;
            } while (uVar2 < puVar1[3]);
        }
        iVar3 = FUN_0065f0a1(self, param_1, i32(P(puVar1[2] + uVar2 * 4)));
        if (iVar3 == 0) goto LAB_0065f122;
LAB_0065f11a:
        uVar4 = 1;
    } else {
LAB_0065f122:
        if ((*puVar1 & 0xfff00000) == 0x20500000) {
            uVar2 = 0;
            if (puVar1[3] != 0) {
                piVar5 = reinterpret_cast<int32_t*>(puVar1[4]);
                do {
                    if (*piVar5 == param_2) break;
                    uVar2 = uVar2 + 1;
                    piVar5 = piVar5 + 1;
                } while (uVar2 < puVar1[3]);
            }
            iVar3 = FUN_0065f0a1(self, param_1, i32(P(puVar1[2] + uVar2 * 4)));
            if ((iVar3 != 0) ||
                (iVar3 = FUN_0065f0a1(self, param_1,
                                      i32(P(puVar1[2] + (puVar1[3] + uVar2) * 4))), iVar3 != 0)) {
                goto LAB_0065f11a;
            }
        }
        uVar4 = 0;
    }
    return uVar4;
}

// ---------------------------------------------------------------------------
// 0x65f17e — observed shape
// Weight query for node param_1 with an in/out owner pair. A node already
// owned (node+0x40) or equal to *param_2 answers 1.0 / its cached weight.
// Otherwise the node's owning array is peeled by kind:
//   0x10000000  -> forward to the single operand
//   0x10100000  -> forward and negate
//   0x20400000  -> sum both operands (or double a shared one)
//   0x20500000  -> multiply by the paired operand's weight when the pair
//                  carries flag 0x100 and no owner
// On success the node's +0x40 / +0x28 cache and the caller's pair are
// written; a mismatched pair yields 0x80004005.
// ---------------------------------------------------------------------------
int32_t FUN_0065f17e(void* self, int32_t param_1, int32_t* param_2, double* param_3)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t* puVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    int32_t iVar4;
    int32_t iVar5;
    int32_t iVar6;
    uint32_t uVar7;
    int32_t* piVar8;
    uint32_t uVar9;
    double local_24;
    int32_t local_1c;
    double local_18;
    int32_t iStack_14;
    double local_10;
    int32_t iStack_c;
    int32_t local_8;

    local_1c = i32(P(u32(base + 0x14) + param_1 * 4));
    if (param_1 == *param_2) {
LAB_0065f19d:
        local_8 = param_1;
        local_24 = 1.0;
        goto LAB_0065f3ce;
    }
    local_8 = i32(P(local_1c + 0x40));
    if (local_8 != -1) {
        local_24 = f64(P(local_1c + 0x28));
        goto LAB_0065f3ce;
    }
    if ((i32(P(local_1c + 8)) != -1) ||
        ((u8(P(i32(P(u32(base + 0x10) + i32(P(local_1c + 4)) * 4)) + 4)) & 2) == 0)) {
        goto LAB_0065f19d;
    }
    puVar1 = pu32(P(u32(base + 0x18) + i32(P(local_1c + 0x48)) * 4));
    uVar2 = puVar1[3];
    uVar3 = 0;
    if (uVar2 != 0) {
        piVar8 = reinterpret_cast<int32_t*>(puVar1[4]);
        do {
            if (*piVar8 == param_1) break;
            uVar3 = uVar3 + 1;
            piVar8 = piVar8 + 1;
        } while (uVar3 < uVar2);
    }
    if (uVar3 != uVar2) {
        uVar9 = *puVar1 & 0xfff00000;
        if (uVar9 == 0x10000000) {
            local_8 = -1;
            iVar4 = FUN_0065f17e(self, i32(P(puVar1[2] + uVar3 * 4)), &local_8, &local_24);
            if (-1 < iVar4) goto LAB_0065f3ce;
        } else if (uVar9 == 0x10100000) {
            local_8 = -1;
            iVar4 = FUN_0065f17e(self, i32(P(puVar1[2] + uVar3 * 4)), &local_8, &local_24);
            if (-1 < iVar4) {
                local_24 = -local_24;
                goto LAB_0065f3ce;
            }
        } else if (uVar9 == 0x20400000) {
            iVar4 = i32(P(puVar1[2] + uVar3 * 4));
            iVar6 = i32(P(puVar1[2] + (uVar2 + uVar3) * 4));
            local_8 = -1;
            if (iVar4 != iVar6) {
                iVar5 = FUN_0065f17e(self, iVar4, &local_8, &local_10);
                if ((iVar5 < 0) ||
                    (iVar5 = FUN_0065f17e(self, iVar6, &local_8, &local_18), iVar5 < 0)) {
                    local_8 = -1;
                    iVar6 = FUN_0065f17e(self, iVar6, &local_8, &local_18);
                    if ((iVar6 < 0) ||
                        (iVar4 = FUN_0065f17e(self, iVar4, &local_8, &local_10), iVar4 < 0)) {
                        goto LAB_0065f3c5;
                    }
                }
                /* CONCAT44 pairs of the two 64-bit stack slots: the sum of
                   the doubles returned through &local_18 and &local_10. */
                local_24 = local_18 + local_10;
                goto LAB_0065f3ce;
            }
            iVar4 = FUN_0065f17e(self, iVar4, &local_8, &local_24);
            if (-1 < iVar4) {
                local_24 = local_24 + local_24;
                goto LAB_0065f3ce;
            }
        } else if (uVar9 == 0x20500000) {
            iStack_c = i32(P(puVar1[2] + uVar3 * 4));
            iStack_14 = i32(P(puVar1[2] + (uVar2 + uVar3) * 4));
            if (iStack_c != iStack_14) {
                iVar6 = iStack_14 * 4;
                iVar4 = i32(P(static_cast<uint32_t>(iVar6) + u32(base + 0x14)));
                if (((u32(P(i32(P(u32(base + 0x10) + i32(P(iVar4 + 4)) * 4)) + 4)) & 0x100) != 0) &&
                    (i32(P(iVar4 + 8)) == -1)) {
                    local_8 = -1;
                    iVar4 = FUN_0065f17e(self, iStack_c, &local_8, &local_24);
                    if (iVar4 < 0) goto LAB_0065f376;
                    iVar4 = i32(P(static_cast<uint32_t>(iVar6) + u32(base + 0x14)));
LAB_0065f3ba:
                    local_24 = local_24 * f64(P(iVar4 + 0x20));
                    goto LAB_0065f3ce;
                }
LAB_0065f376:
                iVar4 = i32(P(static_cast<uint32_t>(iStack_c * 4) + u32(base + 0x14)));
                if (((u32(P(i32(P(u32(base + 0x10) + i32(P(iVar4 + 4)) * 4)) + 4)) & 0x100) != 0) &&
                    (i32(P(iVar4 + 8)) == -1)) {
                    local_8 = -1;
                    iVar4 = iStack_14;
                    iStack_14 = iStack_c * 4;
                    iVar4 = FUN_0065f17e(self, iVar4, &local_8, &local_24);
                    if (-1 < iVar4) {
                        iVar4 = i32(P(static_cast<uint32_t>(iStack_14) + u32(base + 0x14)));
                        goto LAB_0065f3ba;
                    }
                }
            }
        }
    }
LAB_0065f3c5:
    local_24 = 1.0;
    local_8 = param_1;
LAB_0065f3ce:
    if ((*param_2 == -1) || (local_8 == *param_2)) {
        si32(P(local_1c + 0x40), local_8);
        *param_2 = local_8;
        *reinterpret_cast<double*>(P(local_1c + 0x28)) = local_24;
        *param_3 = local_24;
        uVar7 = 0;
    } else {
        uVar7 = 0x80004005;
    }
    return static_cast<int32_t>(uVar7);
}

// ---------------------------------------------------------------------------
// 0x65fa14 — observed shape
// Structural identity of two nodes: offsets +4, +8, +0xc, +0x14 and +0x18
// of the node records at table[a] and table[b] must all match (a and b are
// pre-scaled by 4 before indexing).
// ---------------------------------------------------------------------------
int32_t FUN_0065fa14(void* self, int32_t param_1, int32_t param_2)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    int32_t uVar1;

    param_2 = param_2 * 4;
    param_1 = param_1 * 4;
    if ((((i32(P(i32(P(u32(base + 0x14) + param_1)) + 4)) ==
           i32(P(i32(P(u32(base + 0x14) + param_2)) + 4))) &&
          (i32(P(i32(P(u32(base + 0x14) + param_1)) + 8)) ==
           i32(P(i32(P(u32(base + 0x14) + param_2)) + 8)))) &&
         (i32(P(i32(P(u32(base + 0x14) + param_1)) + 0xc)) ==
          i32(P(i32(P(u32(base + 0x14) + param_2)) + 0xc)))) &&
        ((i32(P(i32(P(u32(base + 0x14) + param_1)) + 0x14)) ==
          i32(P(i32(P(u32(base + 0x14) + param_2)) + 0x14)) &&
          (i32(P(i32(P(u32(base + 0x14) + param_1)) + 0x18)) ==
           i32(P(i32(P(u32(base + 0x14) + param_2)) + 0x18))))) {
        uVar1 = 1;
    } else {
        uVar1 = 0;
    }
    return uVar1;
}

// ---------------------------------------------------------------------------
// 0x65fa89 — observed shape
// True when the two nodes are the same index or share any bit in their
// +0x40 mask word.
// ---------------------------------------------------------------------------
int32_t FUN_0065fa89(void* self, int32_t param_1, int32_t param_2)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    int32_t uVar1;

    if ((param_1 == param_2) ||
        ((u32(P(i32(P(u32(base + 0x14) + param_2 * 4)) + 0x40)) &
          u32(P(i32(P(u32(base + 0x14) + param_1 * 4)) + 0x40))) != 0)) {
        uVar1 = 1;
    } else {
        uVar1 = 0;
    }
    return uVar1;
}

// ---------------------------------------------------------------------------
// 0x65f408 — observed shape
// Owner/provenance resolution over the slot table. Rejects nodes that are
// already owned, missing surface flag 1, or whose surface lacks bit 2.
// Kind dispatch:
//   0x10000000  recurse into the single operand
//   0x20500000  recurse into the left operand, then the right (unless equal)
//   0x20200000  pick the unowned side; param_6/param_3 gate the weight test
//   0x20300000  like 0x20200000 but with param_5/param_4 aliases
//   0x30000000  validates both operands' weights (0/1 and 1/0), then peels
//               the child node's owning array: kind 0x10100000 negates and
//               forwards, kind 0x20400000 pairs the two operands through
//               the nested array, then commits the resolved pair.
// ---------------------------------------------------------------------------
int32_t FUN_0065f408(void* self, uint32_t param_1, int32_t* param_2, int32_t* param_3,
                     int32_t* param_4, int32_t* param_5, int32_t* param_6)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint8_t* pbVar1;
    uint32_t* puVar2;
    int32_t iVar3;
    uint32_t* puVar4;
    int32_t iVar5;
    int32_t iVar6;
    uint32_t uVar7;
    int32_t* piVar8;
    uint32_t uVar9;
    int32_t* piVar10;
    int32_t iVar11;
    uint32_t uVar12;
    int32_t* local_10;
    uint32_t local_8;

    pbVar1 = reinterpret_cast<uint8_t*>(P(u32(base + 0x14) + param_1 * 4));
    if (((i32(P(pbVar1 + 8)) != -1) || ((*pbVar1 & 1) == 0)) ||
        ((u8(P(i32(P(u32(base + 0x10) + i32(P(pbVar1 + 4)) * 4)) + 4)) & 2) == 0)) {
        return -0x7fffbffb;
    }
    puVar2 = pu32(P(u32(base + 0x18) + i32(P(pbVar1 + 0x48)) * 4));
    uVar7 = puVar2[3];
    uVar9 = 0;
    if (uVar7 != 0) {
        piVar10 = reinterpret_cast<int32_t*>(puVar2[4]);
        do {
            if (*piVar10 == static_cast<int32_t>(param_1)) break;
            uVar9 = uVar9 + 1;
            piVar10 = piVar10 + 1;
        } while (uVar9 < uVar7);
    }
    if (uVar9 == uVar7) {
        return -0x7fffbffb;
    }
    uVar12 = *puVar2 & 0xfff00000;
    if (uVar12 == 0x10000000) {
        iVar6 = i32(P(puVar2[2] + uVar9 * 4));
LAB_0065f4df:
        /* CONCAT44(param_6, param_5) is the provider's packing of the two
           trailing stack arguments; both are still forwarded here. */
        iVar6 = FUN_0065f408(self, static_cast<uint32_t>(iVar6), param_2, param_3,
                             param_4, param_5, param_6);
        if (iVar6 < 0) {
            return iVar6;
        }
        return 0;
    }
    if (uVar12 == 0x20500000) {
        iVar11 = i32(P(puVar2[2] + uVar9 * 4));
        iVar6 = i32(P(puVar2[2] + (uVar7 + uVar9) * 4));
        iVar5 = FUN_0065f408(self, static_cast<uint32_t>(iVar11), param_2, param_3,
                             param_4, param_5, param_6);
        if (iVar5 < 0) {
            return iVar5;
        }
        if (iVar11 == iVar6) {
            return 0;
        }
        goto LAB_0065f4df;
    }
    if (uVar12 == 0x20200000) {
        iVar6 = i32(P(puVar2[2] + uVar9 * 4));
        iVar11 = i32(P(puVar2[2] + (uVar7 + uVar9) * 4));
        if (((*param_2 != -1) && (iVar11 != *param_2)) ||
            ((iVar5 = i32(P(u32(base + 0x14) + iVar6 * 4)),
              (u32(P(i32(P(u32(base + 0x10) + i32(P(iVar5 + 4)) * 4)) + 4)) & 0x100) == 0) ||
             (i32(P(iVar5 + 8)) != -1))) {
            if ((*param_2 != -1) && (iVar6 != *param_2)) {
                return -0x7fffbffb;
            }
            iVar5 = i32(P(u32(base + 0x14) + iVar11 * 4));
            if ((u32(P(i32(P(u32(base + 0x10) + i32(P(iVar5 + 4)) * 4)) + 4)) & 0x100) == 0) {
                return -0x7fffbffb;
            }
            if (i32(P(iVar5 + 8)) != -1) {
                return -0x7fffbffb;
            }
            if ((*param_6 != -1) &&
                (f64(P(i32(P(u32(base + 0x14) + *param_6 * 4)) + 0x20)) <=
                 f64(P(i32(P(u32(base + 0x14) + iVar11 * 4)) + 0x20)))) {
                return 0;
            }
LAB_0065f5c0:
            *param_2 = iVar6;
            *param_6 = iVar11;
            return 0;
        }
        if ((*param_3 != -1) &&
            (f64(P(i32(P(u32(base + 0x14) + iVar6 * 4)) + 0x20)) <=
             f64(P(i32(P(u32(base + 0x14) + *param_3 * 4)) + 0x20)))) {
            return 0;
        }
LAB_0065f638:
        *param_2 = iVar11;
        *param_3 = iVar6;
        return 0;
    }
    if (uVar12 == 0x20300000) {
        iVar6 = i32(P(puVar2[2] + uVar9 * 4));
        iVar11 = i32(P(puVar2[2] + (uVar7 + uVar9) * 4));
        if ((((*param_2 != -1) && (iVar11 != *param_2)) ||
             (iVar5 = i32(P(u32(base + 0x14) + iVar6 * 4)),
              (u32(P(i32(P(u32(base + 0x10) + i32(P(iVar5 + 4)) * 4)) + 4)) & 0x100) == 0)) ||
            (i32(P(iVar5 + 8)) != -1)) {
            if ((*param_2 != -1) && (iVar6 != *param_2)) {
                return -0x7fffbffb;
            }
            iVar5 = i32(P(u32(base + 0x14) + iVar11 * 4));
            if ((u32(P(i32(P(u32(base + 0x10) + i32(P(iVar5 + 4)) * 4)) + 4)) & 0x100) == 0) {
                return -0x7fffbffb;
            }
            if (i32(P(iVar5 + 8)) != -1) {
                return -0x7fffbffb;
            }
            param_6 = param_4;
            if ((*param_4 != -1) &&
                (f64(P(i32(P(u32(base + 0x14) + iVar11 * 4)) + 0x20)) <=
                 f64(P(i32(P(u32(base + 0x14) + *param_4 * 4)) + 0x20)))) {
                return 0;
            }
            goto LAB_0065f5c0;
        }
        param_3 = param_5;
        if ((*param_5 != -1) &&
            (f64(P(i32(P(u32(base + 0x14) + *param_5 * 4)) + 0x20)) <=
             f64(P(i32(P(u32(base + 0x14) + iVar6 * 4)) + 0x20)))) {
            return 0;
        }
        goto LAB_0065f638;
    }
    if (uVar12 != 0x30000000) {
        return -0x7fffbffb;
    }
    iVar6 = i32(P(u32(base + 0x14) +
                  i32(P(puVar2[2] + (uVar9 + puVar2[3]) * 4)) * 4));
    iVar11 = i32(P(u32(base + 0x14) +
                   i32(P(puVar2[2] + (uVar9 + puVar2[3] * 2) * 4)) * 4));
    iVar5 = i32(base + 0x10);
    if ((u32(P(i32(P(static_cast<uint32_t>(iVar5) + i32(P(iVar6 + 4)) * 4)) + 4)) & 0x100) == 0) {
        return -0x7fffbffb;
    }
    if (i32(P(iVar6 + 8)) != -1) {
        return -0x7fffbffb;
    }
    if ((u32(P(i32(P(static_cast<uint32_t>(iVar5) + i32(P(iVar11 + 4)) * 4)) + 4)) & 0x100) == 0) {
        return -0x7fffbffb;
    }
    if (i32(P(iVar11 + 8)) != -1) {
        return -0x7fffbffb;
    }
    if ((f64(P(iVar6 + 0x20)) != 0.0) || (f64(P(iVar11 + 0x20)) != 1.0)) {
        if (f64(P(iVar6 + 0x20)) != 1.0) {
            return -0x7fffbffb;
        }
        if (f64(P(iVar11 + 0x20)) != 0.0) {
            return -0x7fffbffb;
        }
    }
    iVar11 = i32(P(puVar2[2] + uVar9 * 4));
    iVar3 = i32(P(u32(base + 0x14) + iVar11 * 4));
    if ((u8(P(i32(P(static_cast<uint32_t>(iVar5) + i32(P(iVar3 + 4)) * 4)) + 4)) & 2) == 0) {
        return -0x7fffbffb;
    }
    puVar2 = pu32(P(u32(base + 0x18) + i32(P(iVar3 + 0x48)) * 4));
    uVar7 = *puVar2 & 0xfff00000;
    if ((uVar7 != 0x20400000) && (uVar7 != 0x10100000)) {
        return -0x7fffbffb;
    }
    uVar9 = puVar2[3];
    param_1 = 0;
    if (uVar9 != 0) {
        local_10 = reinterpret_cast<int32_t*>(puVar2[4]);
        do {
            if (*local_10 == iVar11) break;
            param_1 = param_1 + 1;
            local_10 = local_10 + 1;
        } while (param_1 < uVar9);
    }
    if (uVar7 == 0x10100000) {
        piVar8 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(
            FUN_0065d9d5(u32(base + 0x78), 0, 0, 0.0)));
        piVar10 = reinterpret_cast<int32_t*>(P(puVar2[2] + param_1 * 4));
        if (piVar8 == reinterpret_cast<int32_t*>(static_cast<uintptr_t>(0xffffffffu))) {
            return -0x7ff8fff2;
        }
        goto LAB_0065f8ce;
    }
    local_8 = 0;
    local_10 = reinterpret_cast<int32_t*>(P(puVar2[2] + (param_1 + uVar9) * 4));
    do {
        iVar11 = *local_10;
        iVar5 = i32(P(u32(base + 0x14) + iVar11 * 4));
        if (((u8(P(i32(P(u32(base + 0x10) + i32(P(iVar5 + 4)) * 4)) + 4)) & 2) != 0) &&
            (puVar4 = pu32(P(u32(base + 0x18) + i32(P(iVar5 + 0x48)) * 4)),
             (*puVar4 & 0xfff00000) == 0x10100000)) {
            local_10 = reinterpret_cast<int32_t*>(0);
            if (puVar4[3] == 0) goto LAB_0065f8ae;
            piVar10 = reinterpret_cast<int32_t*>(puVar4[4]);
            goto LAB_0065f896;
        }
        local_8 = local_8 + 1;
        local_10 = reinterpret_cast<int32_t*>(
            reinterpret_cast<intptr_t>(local_10) - static_cast<intptr_t>(uVar9) * 4);
    } while (local_8 < 2);
    piVar10 = param_2;
    piVar8 = param_2;
    goto LAB_0065f8c4;
    while (true) {
        local_10 = reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(local_10) + 1);
        piVar10 = piVar10 + 1;
        if (puVar4[3] <= static_cast<uint32_t>(reinterpret_cast<uintptr_t>(local_10))) break;
LAB_0065f896:
        if (iVar11 == *piVar10) break;
    }
LAB_0065f8ae:
    piVar8 = reinterpret_cast<int32_t*>(P(puVar2[2] + (uVar9 * local_8 + param_1) * 4));
    piVar10 = reinterpret_cast<int32_t*>(
        P(puVar4[2] + static_cast<uint32_t>(reinterpret_cast<uintptr_t>(local_10)) * 4));
LAB_0065f8c4:
    if (local_8 == 2) {
        return -0x7fffbffb;
    }
LAB_0065f8ce:
    if ((((*param_2 == -1) ||
          (piVar8 == reinterpret_cast<int32_t*>(static_cast<uint32_t>(*param_2)))) &&
         (iVar11 = i32(P(u32(base + 0x14) + static_cast<uint32_t>(
                                        reinterpret_cast<uintptr_t>(piVar10)) * 4)),
          (u32(P(i32(P(u32(base + 0x10) + i32(P(iVar11 + 4)) * 4)) + 4)) & 0x100) != 0)) &&
        (i32(P(iVar11 + 8)) == -1)) {
        if (f64(P(iVar6 + 0x20)) == 1.0) {
            if ((*param_4 != -1) &&
                (f64(P(i32(P(u32(base + 0x14) + static_cast<uint32_t>(
                                      reinterpret_cast<uintptr_t>(piVar10)) * 4)) + 0x20)) <=
                 f64(P(i32(P(u32(base + 0x14) + *param_4 * 4)) + 0x20)))) {
                return 0;
            }
        } else {
            param_4 = param_6;
            if ((*param_6 != -1) &&
                (f64(P(i32(P(u32(base + 0x14) + *param_6 * 4)) + 0x20)) <=
                 f64(P(i32(P(u32(base + 0x14) + static_cast<uint32_t>(
                                      reinterpret_cast<uintptr_t>(piVar10)) * 4)) + 0x20)))) {
                return 0;
            }
        }
        *param_2 = static_cast<int32_t>(reinterpret_cast<uintptr_t>(piVar8));
        *param_4 = static_cast<int32_t>(reinterpret_cast<uintptr_t>(piVar10));
        return 0;
    }
    if ((((*param_2 != -1) &&
          (piVar10 != reinterpret_cast<int32_t*>(static_cast<uint32_t>(*param_2)))) ||
         (iVar11 = i32(P(u32(base + 0x14) + static_cast<uint32_t>(
                                        reinterpret_cast<uintptr_t>(piVar8)) * 4)),
          (u32(P(i32(P(u32(base + 0x10) + i32(P(iVar11 + 4)) * 4)) + 4)) & 0x100) == 0)) ||
        (i32(P(iVar11 + 8)) != -1)) {
        return -0x7fffbffb;
    }
    if (f64(P(iVar6 + 0x20)) == 1.0) {
        if ((*param_5 != -1) &&
            (f64(P(i32(P(u32(base + 0x14) + *param_5 * 4)) + 0x20)) <=
             f64(P(i32(P(u32(base + 0x14) + static_cast<uint32_t>(
                                  reinterpret_cast<uintptr_t>(piVar8)) * 4)) + 0x20)))) {
            return 0;
        }
    } else {
        param_5 = param_3;
        if ((*param_3 != -1) &&
            (f64(P(i32(P(u32(base + 0x14) + static_cast<uint32_t>(
                                  reinterpret_cast<uintptr_t>(piVar8)) * 4)) + 0x20)) <=
             f64(P(i32(P(u32(base + 0x14) + *param_3 * 4)) + 0x20)))) {
            return 0;
        }
    }
    *param_2 = static_cast<int32_t>(reinterpret_cast<uintptr_t>(piVar10));
    *param_5 = static_cast<int32_t>(reinterpret_cast<uintptr_t>(piVar8));
    return 0;
}

// ---------------------------------------------------------------------------
// 0x65fab6 — observed shape
// Row-pair scan used by slot selection: for each of the stride rows, take the
// two node indices at columns param_2 / param_3, require both surfaces carry
// flag 0x40 and the two nodes differ structurally (FUN_0065fa14 == 0).
// Returns 1 on the first such pair, else 0.
// ---------------------------------------------------------------------------
uint32_t FUN_0065fab6(void* self, uint32_t* param_1, int32_t param_2, int32_t param_3)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t* puVar1;
    uint32_t uVar2;
    int32_t iVar3;
    int32_t iVar4;
    uint32_t uVar5;
    int32_t* piVar6;
    uint32_t local_8;

    uVar2 = param_1[1];
    uVar5 = *param_1 & 0xfffff;
    local_8 = 0;
    if (uVar2 / uVar5 != 0) {
        puVar1 = param_1 + 2;
        iVar3 = i32(base + 0x14);
        param_1 = reinterpret_cast<uint32_t*>(*puVar1 + param_3 * 4);
        piVar6 = reinterpret_cast<int32_t*>(*puVar1 + param_2 * 4);
        do {
            if ((((u8(P(i32(P(u32(base + 0x10) +
                               i32(P(i32(P(static_cast<uint32_t>(iVar3) + *piVar6 * 4)) + 4)) * 4)) +
                          4)) & 0x40) != 0) &&
                ((u8(P(i32(P(u32(base + 0x10) +
                              i32(P(i32(P(static_cast<uint32_t>(iVar3) + *param_1 * 4)) + 4)) * 4)) +
                           4)) & 0x40) != 0)) &&
                (iVar4 = FUN_0065fa14(self, *piVar6, static_cast<int32_t>(*param_1)), iVar4 == 0)) {
                return 1;
            }
            local_8 = local_8 + 1;
            param_1 = param_1 + uVar5;
            piVar6 = piVar6 + uVar5;
        } while (local_8 < uVar2 / uVar5);
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x65fb5b — observed shape
// Splits a slot array into per-group sub-slots. When the merge probe
// FUN_0065ccdf() reports "not merged", slots whose surface carries flag 0x40
// are funnelled into one sub-slot per distinct structural group and their
// entries are removed from the source slot; the loop then repeatedly picks
// the first column whose ready-column count is maximal, emits a sub-slot
// (0x10000001 / 0x20400001 / size|0x50000000) and clears those columns,
// retrying through joined_r0x0065fda1 until no column remains. The "already
// merged" path emits one single-element sub-slot per column.
// ---------------------------------------------------------------------------
uint32_t FUN_0065fb5b(void* self, uint32_t* param_1)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t uVar1;
    uint32_t uVar2;
    bool bVar3;
    bool bVar4;
    uint32_t uVar5;
    int32_t iVar6;
    uint32_t uVar7;
    uint32_t uVar8;
    int32_t iVar9;
    int32_t* piVar10;
    int32_t iVar11;
    uint32_t local_30;
    int32_t local_2c;
    uint32_t local_20;
    uint32_t local_1c;
    uint32_t local_18;
    uint32_t local_10;
    uint32_t local_8;

    uVar1 = param_1[3];
    uVar5 = param_1[1] / uVar1;
    iVar6 = FUN_0065ccdf();
    if (iVar6 == 0) {
        local_1c = 0;
        local_10 = uVar1;
        if (uVar1 != 0) {
            do {
                uVar7 = param_1[4];
                iVar6 = i32(P(uVar7 + local_1c * 4));
                if ((iVar6 != -1) &&
                    ((u8(P(i32(P(u32(base + 0x10) +
                                  i32(P(i32(P(u32(base + 0x14) + iVar6 * 4)) + 4)) * 4)) + 4)) &
                      0x40) != 0)) {
                    local_8 = 0;
                    for (uVar8 = local_1c; uVar8 < uVar1; uVar8 = uVar8 + 1) {
                        if ((i32(P(uVar7 + uVar8 * 4)) != -1) &&
                            (iVar6 = FUN_0065fa14(self, i32(P(param_1[4] + local_1c * 4)),
                                                  i32(P(param_1[4] + uVar8 * 4))), iVar6 != 0)) {
                            local_8 = local_8 + 1;
                        }
                    }
                    iVar6 = static_cast<int32_t>(
                        FUN_0065da35((*param_1 ^ local_8) & 0xfffff ^ *param_1,
                                     0xffffffff, 0xffffffff));
                    if (iVar6 == -1) {
                        return 0x8007000e;
                    }
                    iVar6 = i32(P(u32(base + 0x18) + iVar6 * 4));
                    FUN_0065cc50(param_1);
                    local_30 = u32(P(param_1[4] + local_1c * 4));
                    local_8 = 0;
                    for (uVar7 = local_1c; uVar7 < uVar1; uVar7 = uVar7 + 1) {
                        iVar9 = i32(P(param_1[4] + uVar7 * 4));
                        if ((iVar9 != -1) &&
                            (iVar9 = FUN_0065fa14(self, static_cast<int32_t>(local_30), iVar9),
                             iVar9 != 0)) {
                            local_18 = 0;
                            if (uVar5 != 0) {
                                do {
                                    iVar9 = static_cast<int32_t>(param_1[3] * local_18);
                                    iVar11 = i32(P(iVar6 + 0xc)) *
                                             static_cast<int32_t>(local_18);
                                    local_18 = local_18 + 1;
                                    su32(P(u32(P(iVar6 + 8)) +
                                           (iVar11 + static_cast<int32_t>(local_8)) * 4),
                                         u32(P(param_1[2] +
                                               (iVar9 + static_cast<int32_t>(uVar7)) * 4)));
                                } while (local_18 < uVar5);
                            }
                            su32(P(u32(P(iVar6 + 0x10)) + local_8 * 4),
                                 u32(P(param_1[4] + uVar7 * 4)));
                            su32(P(param_1[4] + uVar7 * 4), 0xffffffff);
                            local_10 = local_10 - 1;
                            local_8 = local_8 + 1;
                        }
                    }
                }
                local_1c = local_1c + 1;
            } while (local_1c < uVar1);
        }
        local_2c = FUN_0065cea4();
        bVar3 = true;
        bVar4 = true;
        if ((local_2c == 0) && (local_20 = 0, uVar1 != 0)) {
            piVar10 = reinterpret_cast<int32_t*>(param_1[4]);
            do {
                if ((*piVar10 != -1) &&
                    ((u8(P(i32(P(u32(base + 0x10) +
                                  i32(P(i32(P(u32(base + 0x14) + *piVar10 * 4)) + 4)) * 4)) + 5)) &
                      0x10) != 0)) {
                    local_2c = 1;
                    break;
                }
                local_20 = local_20 + 1;
                piVar10 = piVar10 + 1;
            } while (local_20 < uVar1);
        }
joined_r0x0065fda1:
        if (local_10 != 0) {
            if ((local_10 < 5) && (local_2c == 0)) {
                bVar3 = false;
                bVar4 = false;
            }
            local_8 = 0;
            local_18 = 0;
            if (uVar1 == 0) {
                return 0;
            }
            do {
                if (i32(P(param_1[4] + local_18 * 4)) != -1) {
                    uVar7 = 0;
                    local_1c = 0;
                    do {
                        if (3 < local_1c) break;
                        uVar8 = param_1[4];
                        if (((i32(P(uVar8 + uVar7 * 4)) != -1) &&
                             ((!bVar3 ||
                               (iVar6 = FUN_0065fa89(self, i32(P(uVar8 + local_18 * 4)),
                                                     i32(P(uVar8 + uVar7 * 4))), iVar6 != 0)))) &&
                            ((!bVar4 ||
                              (iVar6 = FUN_0065fab6(self, param_1,
                                                    static_cast<int32_t>(local_18),
                                                    static_cast<int32_t>(uVar7)), iVar6 == 0)))) {
                            local_1c = local_1c + 1;
                        }
                        uVar7 = uVar7 + 1;
                    } while (uVar7 < uVar1);
                    if (local_8 < local_1c) {
                        local_8 = local_1c;
                        local_30 = local_18;
                    }
                }
                local_18 = local_18 + 1;
            } while (local_18 < uVar1);
            if (local_8 == 0) {
                return 0;
            }
            iVar6 = static_cast<int32_t>(
                FUN_0065da35((*param_1 ^ local_8) & 0xfffff ^ *param_1, 0xffffffff, 0xffffffff));
            if (iVar6 == -1) {
                return 0x8007000e;
            }
            iVar6 = i32(P(u32(base + 0x18) + iVar6 * 4));
            FUN_0065cc50(param_1);
            uVar2 = u32(P(param_1[4] + local_30 * 4));
            local_18 = 0;
            local_20 = 0;
            do {
                if (3 < local_18) break;
                iVar9 = i32(P(param_1[4] + local_20 * 4));
                if (((iVar9 != -1) &&
                     ((!bVar3 || (iVar9 = FUN_0065fa89(self, static_cast<int32_t>(uVar2), iVar9),
                                   iVar9 != 0)))) &&
                    ((!bVar4 || (iVar9 = FUN_0065fab6(self, param_1,
                                                      static_cast<int32_t>(local_30),
                                                      static_cast<int32_t>(local_20)),
                                 iVar9 == 0)))) {
                    local_1c = 0;
                    if (uVar5 != 0) {
                        do {
                            iVar9 = static_cast<int32_t>(param_1[3] * local_1c);
                            iVar11 = i32(P(iVar6 + 0xc)) * static_cast<int32_t>(local_1c);
                            local_1c = local_1c + 1;
                            su32(P(u32(P(iVar6 + 8)) +
                                   (iVar11 + static_cast<int32_t>(local_18)) * 4),
                                 u32(P(param_1[2] +
                                       (iVar9 + static_cast<int32_t>(local_20)) * 4)));
                        } while (local_1c < uVar5);
                    }
                    su32(P(u32(P(iVar6 + 0x10)) + local_18 * 4),
                         u32(P(param_1[4] + local_20 * 4)));
                    su32(P(param_1[4] + local_20 * 4), 0xffffffff);
                    local_10 = local_10 - 1;
                    local_18 = local_18 + 1;
                }
                local_20 = local_20 + 1;
            } while (local_20 < uVar1);
            goto joined_r0x0065fda1;
        }
    } else {
        local_1c = 0;
        if (uVar1 != 0) {
            do {
                iVar6 = static_cast<int32_t>(
                    FUN_0065da35(*param_1 & 0xfff00001 | 1, 0xffffffff, 0xffffffff));
                if (iVar6 == -1) {
                    return 0x8007000e;
                }
                iVar6 = i32(P(u32(base + 0x18) + iVar6 * 4));
                FUN_0065cc50(param_1);
                uVar7 = 0;
                if (uVar5 != 0) {
                    do {
                        su32(P(u32(P(iVar6 + 8)) + uVar7 * 4),
                             u32(P(param_1[2] + (param_1[3] * uVar7 + local_1c) * 4)));
                        uVar7 = uVar7 + 1;
                    } while (uVar7 < uVar5);
                }
                iVar9 = static_cast<int32_t>(local_1c * 4);
                local_1c = local_1c + 1;
                su32(P(u32(P(iVar6 + 0x10))), u32(P(param_1[4] + iVar9)));
            } while (local_1c < uVar1);
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x65ff49 — observed shape
// Packs the slot array's columns into sub-slots of at most four columns.
// While more than four columns remain, group the columns sharing the same
// structural key (offsets +4/+8/+0xc/+0x48 of both members), emit
// size|0x50000000 (or 0x10000001 / 0x20400001 for one/two columns), copy
// the entries, and mark the used columns -1. The tail (<5 columns) is a
// single sub-slot; if more than one sub-slot was produced the remainder is
// built up level by level through FUN_0065d9d5(1.0) merges.
// ---------------------------------------------------------------------------
uint32_t FUN_0065ff49(void* self, uint32_t* param_1)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t uVar1;
    int32_t iVar2;
    int32_t iVar3;
    uint32_t* puVar4;
    uint32_t uVar5;
    int32_t iVar6;
    uint32_t uVar7;
    int32_t iVar8;
    bool bVar9;
    int32_t local_50;
    int32_t local_4c;
    int32_t local_48;
    int32_t local_44;
    int32_t local_40;
    int32_t local_3c;
    int32_t local_38;
    int32_t local_34;
    uint32_t local_28;
    int32_t local_24;
    uint32_t local_20;
    uint32_t local_1c;
    uint32_t local_18;
    uint32_t local_14;
    int32_t local_10;
    uint32_t local_c;
    uint32_t local_8;
    intptr_t uStage;

    puVar4 = param_1;
    uVar5 = *param_1 & 0xfffff;
    uStage = 0;
    local_14 = uVar5;
    if (uVar5 == 0) {
        return 0;
    }
    do {
        local_8 = 0;
        if (local_14 < 5) {
            local_8 = local_14;
        } else if (uVar5 != 0) {
            local_20 = 0;
            local_24 = static_cast<int32_t>(uVar5 << 2);
            local_28 = 1;
            do {
                uVar1 = puVar4[2];
                if (i32(P(uVar1 + local_20)) != -1) {
                    iVar6 = i32(P(u32(base + 0x14) + i32(P(uVar1 + local_20)) * 4));
                    iVar8 = i32(P(u32(base + 0x14) + i32(P(uVar1 + local_24)) * 4));
                    local_1c = 1;
                    local_18 = local_28;
                    if (local_28 < uVar5) {
                        local_10 = local_24;
                        do {
                            local_10 = local_10 + 4;
                            if (i32(P(puVar4[2] + local_10)) != -1) {
                                iVar2 = i32(P(u32(base + 0x14) +
                                              i32(P(puVar4[2] + local_18 * 4)) * 4));
                                iVar3 = i32(P(u32(base + 0x14) +
                                              i32(P(puVar4[2] + local_10)) * 4));
                                if ((((((i32(P(iVar6 + 4)) == i32(P(iVar2 + 4))) &&
                                       (i32(P(iVar6 + 8)) == i32(P(iVar2 + 8)))) &&
                                      (i32(P(iVar6 + 0xc)) == i32(P(iVar2 + 0xc)))) &&
                                     ((i32(P(iVar6 + 0x48)) == i32(P(iVar2 + 0x48)) &&
                                       (i32(P(iVar8 + 4)) == i32(P(iVar3 + 4)))))) &&
                                    ((i32(P(iVar8 + 8)) == i32(P(iVar3 + 8)) &&
                                      ((i32(P(iVar8 + 0xc)) == i32(P(iVar3 + 0xc)) &&
                                        (i32(P(iVar8 + 0x48)) ==
                                         i32(P(iVar3 + 0x48)))))))) &&
                                   (local_1c = local_1c + 1, local_1c == 4)) {
                                    break;
                                }
                            }
                            local_18 = local_18 + 1;
                        } while (local_18 < uVar5);
                    }
                    if (local_8 < local_1c) {
                        local_8 = local_1c;
                        local_34 = i32(P(iVar6 + 4));
                        local_44 = i32(P(iVar8 + 4));
                        local_38 = i32(P(iVar6 + 8));
                        local_48 = i32(P(iVar8 + 8));
                        local_3c = i32(P(iVar6 + 0xc));
                        local_40 = i32(P(iVar6 + 0x48));
                        local_4c = i32(P(iVar8 + 0xc));
                        local_50 = i32(P(iVar8 + 0x48));
                    }
                    if (local_8 == 4) break;
                }
                local_20 = local_20 + 4;
                local_24 = local_24 + 4;
                bVar9 = local_28 < uVar5;
                local_28 = local_28 + 1;
            } while (bVar9);
        }
        iVar6 = static_cast<int32_t>(
            FUN_0065da35(local_8 & 0xfffff | 0x50000000, 0xffffffff, 0xffffffff));
        if (iVar6 == -1) {
            return 0x8007000e;
        }
        iVar6 = i32(P(u32(base + 0x18) + iVar6 * 4));
        FUN_0065cc50();
        local_28 = 0;
        local_20 = 0;
        if (uVar5 != 0) {
            local_10 = static_cast<int32_t>(uVar5 << 2);
            local_24 = static_cast<int32_t>(local_8 << 2);
            do {
                if (local_8 <= local_28) break;
                if (i32(P(puVar4[2] + local_20 * 4)) != -1) {
                    iVar8 = i32(P(u32(base + 0x14) +
                                  i32(P(puVar4[2] + local_20 * 4)) * 4));
                    iVar2 = i32(P(u32(base + 0x14) + i32(P(puVar4[2] + local_10)) * 4));
                    if ((local_14 < 5) ||
                        ((((local_34 == i32(P(iVar8 + 4)) &&
                            (local_38 == i32(P(iVar8 + 8)))) &&
                           (local_3c == i32(P(iVar8 + 0xc)))) &&
                          (((local_40 == i32(P(iVar8 + 0x48)) &&
                             (local_44 == i32(P(iVar2 + 4)))) &&
                            ((local_48 == i32(P(iVar2 + 8)) &&
                              ((local_4c == i32(P(iVar2 + 0xc)) &&
                                (local_50 == i32(P(iVar2 + 0x48))))))))))) {
                        su32(P(u32(P(iVar6 + 8)) + local_28 * 4),
                             u32(P(puVar4[2] + local_20 * 4)));
                        su32(P(u32(P(iVar6 + 8)) + static_cast<uint32_t>(local_24)),
                             u32(P(puVar4[2] + local_10)));
                        su32(P(puVar4[2] + local_20 * 4), 0xffffffff);
                        su32(P(puVar4[2] + local_10), 0xffffffff);
                        local_28 = local_28 + 1;
                        local_24 = local_24 + 4;
                    }
                }
                local_10 = local_10 + 4;
                local_20 = local_20 + 1;
            } while (local_20 < uVar5);
        }
        if (uVar5 < 5) {
            su32(P(u32(P(iVar6 + 0x10))), u32(P(puVar4[4])));
        } else {
            /* fourth argument is the literal 0 in the listing */
            uVar7 = FUN_0065d9d5(u32(base + 0x88), 0xffffffff, 0xffffffff, 0.0);
            su32(P(u32(P(iVar6 + 0x10))), uVar7);
            if (i32(P(u32(P(iVar6 + 0x10)))) == -1) {
                return 0x8007000e;
            }
            su32(P(i32(P(u32(base + 0x14) + i32(P(u32(P(iVar6 + 0x10)))) * 4)) + 0x14),
                 u32(P(i32(P(u32(base + 0x14) + i32(P(puVar4[4])) * 4)) + 0x14)));
            su32(P(i32(P(u32(base + 0x14) + i32(P(u32(P(iVar6 + 0x10)))) * 4)) + 0x18),
                 u32(P(i32(P(u32(base + 0x14) + i32(P(puVar4[4])) * 4)) + 0x18)));
        }
        local_14 = local_14 - local_8;
        uStage = uStage + 1;
        if (local_14 == 0) {
            if (uStage < 2) {
                return 0;
            }
            /* fourth argument is 0x3ff0000000000000, i.e. 1.0 */
            iVar6 = static_cast<int32_t>(
                FUN_0065d9d5(u32(base + 0x78), 0xffffffff, 0, 1.0));
            if (iVar6 == -1) {
                return 0x8007000e;
            }
            do {
                local_1c = u32(base + 0xc) - static_cast<uint32_t>(uStage);
                local_18 = 0;
                if (uStage != 0) {
                    local_28 = 0;
                    do {
                        local_c = static_cast<uint32_t>(uStage) - local_28;
                        if (4 < local_c) {
                            local_c = 4;
                        }
                        if (local_c == 1) {
                            uVar5 = 0x10000001;
                        } else if (local_c == 2) {
                            uVar5 = 0x20400001;
                        } else {
                            uVar5 = local_c & 0xfffff | 0x50000000;
                        }
                        iVar8 = static_cast<int32_t>(
                            FUN_0065da35(uVar5, 0xffffffff, 0xffffffff));
                        if (iVar8 == -1) {
                            return 0x8007000e;
                        }
                        iVar8 = i32(P(u32(base + 0x18) + iVar8 * 4));
                        FUN_0065cc50();
                        local_14 = 0;
                        if (local_c != 0) {
                            local_20 = local_c << 2;
                            local_24 = static_cast<int32_t>(local_1c << 2);
                            do {
                                su32(P(u32(P(iVar8 + 8)) + local_14 * 4),
                                     u32(P(u32(P(i32(P(u32(base + 0x18) +
                                                        static_cast<uint32_t>(local_24))) +
                                                 0x10)))));
                                if (2 < local_c) {
                                    si32(P(u32(P(iVar8 + 8)) + local_20), iVar6);
                                }
                                local_24 = local_24 + 4;
                                local_20 = local_20 + 4;
                                local_14 = local_14 + 1;
                            } while (local_14 < local_c);
                        }
                        if (uStage < 5) {
                            su32(P(u32(P(iVar8 + 0x10))), u32(P(puVar4[4])));
                        } else {
                            uVar7 = FUN_0065d9d5(u32(base + 0x88), 0xffffffff,
                                                 0xffffffff, 0.0);
                            su32(P(u32(P(iVar8 + 0x10))), uVar7);
                            if (i32(P(u32(P(iVar8 + 0x10)))) == -1) {
                                return 0x8007000e;
                            }
                            su32(P(i32(P(u32(base + 0x14) +
                                          i32(P(u32(P(iVar8 + 0x10)))) * 4)) + 0x14),
                                 u32(P(i32(P(u32(base + 0x14) +
                                              i32(P(puVar4[4])) * 4)) + 0x14)));
                            su32(P(i32(P(u32(base + 0x14) +
                                          i32(P(u32(P(iVar8 + 0x10)))) * 4)) + 0x18),
                                 u32(P(i32(P(u32(base + 0x14) +
                                              i32(P(puVar4[4])) * 4)) + 0x18)));
                        }
                        local_1c = local_1c + local_c;
                        local_28 = local_28 + 4;
                        local_18 = local_18 + 1;
                    } while (local_28 < static_cast<uint32_t>(uStage));
                }
                uStage = local_18;
                if (local_18 < 2) {
                    return 0;
                }
            } while (true);
        }
    } while (true);
}

// ---------------------------------------------------------------------------
// 0x66040e — observed shape
// If any entry of the passed slot disagrees structurally with its first
// entry, rebuild the slot as a plain 0x10000001 list: clone each entry into
// a fresh node, copy the entry index list, force a fresh 0x88 handle, mirror
// the chain links and source node word, then re-split it with 0x65fb5b.
// ---------------------------------------------------------------------------
int32_t FUN_0066040e(void* self, int32_t param_1)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t uVar1;
    uint32_t* puVar2;
    int32_t iVar3;
    int32_t iVar4;
    uint32_t uVar5;
    uint32_t* local_c;
    uint32_t local_8;

    iVar3 = FUN_0065db2e(param_1);
    if (iVar3 == -1) {
        return -0x7ff8fff2;
    }
    iVar3 = i32(P(u32(base + 0x18) + iVar3 * 4));
    FUN_0065cc50();
    uVar1 = u32(P(param_1 + 0xc));
    local_8 = 0;
    if (uVar1 != 0) {
        local_c = pu32(P(param_1 + 0x10));
        uVar5 = *local_c;
        do {
            iVar4 = FUN_0065fa14(self, static_cast<int32_t>(uVar5),
                                 static_cast<int32_t>(*local_c));
            if (iVar4 == 0) break;
            local_8 = local_8 + 1;
            local_c = local_c + 1;
        } while (local_8 < uVar1);
    }
    if (local_8 != uVar1) {
        iVar4 = static_cast<int32_t>(
            FUN_0065da35(uVar1 & 0xfffff | 0x10000000, 0xffffffff, 0xffffffff));
        if (iVar4 == -1) {
            return -0x7ff8fff2;
        }
        puVar2 = pu32(P(u32(base + 0x18) + iVar4 * 4));
        FUN_0065cc50();
        local_8 = 0;
        if (i32(P(iVar3 + 0xc)) != 0) {
            do {
                iVar4 = static_cast<int32_t>(local_8 * 4);
                su32(P(static_cast<uint32_t>(iVar4) + puVar2[4]),
                     u32(P(static_cast<uint32_t>(iVar4) + u32(P(iVar3 + 0x10)))));
                uVar5 = FUN_0065d9d5(u32(base + 0x88), 0xffffffff, 0xffffffff, 0.0);
                su32(P(static_cast<uint32_t>(iVar4) + puVar2[2]), uVar5);
                su32(P(static_cast<uint32_t>(iVar4) + u32(P(iVar3 + 0x10))),
                     u32(P(static_cast<uint32_t>(iVar4) + puVar2[2])));
                if (i32(P(static_cast<uint32_t>(iVar4) + u32(P(iVar3 + 0x10)))) == -1) {
                    return -0x7ff8fff2;
                }
                FUN_0065d5bd();
                su32(P(i32(P(u32(base + 0x14) +
                              i32(P(static_cast<uint32_t>(iVar4) +
                                   u32(P(iVar3 + 0x10)))) * 4)) + 0x14),
                     u32(P(i32(P(u32(base + 0x14) +
                                  i32(P(static_cast<uint32_t>(iVar4) +
                                       u32(P(param_1 + 0x10)))) * 4)) + 0x14)));
                local_8 = local_8 + 1;
                su32(P(i32(P(u32(base + 0x14) +
                              i32(P(static_cast<uint32_t>(iVar4) +
                                   u32(P(iVar3 + 0x10)))) * 4)) + 0x18),
                     u32(P(i32(P(u32(base + 0x14) +
                                  i32(P(static_cast<uint32_t>(iVar4) +
                                       u32(P(param_1 + 0x10)))) * 4)) + 0x18)));
                su32(P(i32(P(u32(base + 0x14) +
                              i32(P(static_cast<uint32_t>(iVar4) +
                                   u32(P(iVar3 + 0x10)))) * 4))),
                     u32(P(i32(P(u32(base + 0x14) +
                                  i32(P(static_cast<uint32_t>(iVar4) +
                                       u32(P(param_1 + 0x10)))) * 4)))));
            } while (local_8 < u32(P(iVar3 + 0xc)));
        }
        /* The listing calls FUN_0065fb5b() with no explicit stack argument;
           the array just rebuilt (puVar2) is forwarded as its param_1. */
        iVar3 = static_cast<int32_t>(FUN_0065fb5b(self, puVar2));
        if (iVar3 < 0) {
            return iVar3;
        }
        *puVar2 = 0;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6605b4 — observed shape
// Two-pass ordering-key refresh over the slot rows. Pass 1: for every live
// node of each row, set bit (key+0x24 & 0x1f) in the node's +0x40 mask and
// store 1 at key+0x28. Pass 2: for the same nodes, clear key+0x28 and
// advance the key at +0x24 modulo 32. Rows are advanced by printed
// width*4 bytes per row.
// ---------------------------------------------------------------------------
uint32_t FUN_006605b4(void* self, uint32_t* param_1)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    int32_t iVar1;
    int32_t iVar2;
    uint32_t uVar3;
    int32_t iVar4;
    uint32_t uVar5;
    uint32_t local_14;
    uint32_t local_c;
    int32_t local_8;

    if ((*param_1 & 0xfff00000) != 0) {
        uVar3 = *param_1 & 0xfffff;
        local_14 = param_1[1] / uVar3;
        if (local_14 != 0) {
            local_8 = 0;
            do {
                if (uVar3 != 0) {
                    iVar4 = local_8;
                    local_c = uVar3;
                    do {
                        iVar1 = i32(P(u32(base + 0x14) +
                                      i32(P(static_cast<uint32_t>(iVar4) + param_1[2])) * 4));
                        if ((i32(P(iVar1 + 0x48)) != -1) && (i32(P(iVar1 + 8)) == -1)) {
                            iVar2 = i32(P(u32(base + 0x18) + i32(P(iVar1 + 0x48)) * 4));
                            su32(P(iVar1 + 0x40),
                                 u32(P(iVar1 + 0x40)) |
                                     (1u << (u32(P(iVar2 + 0x24)) & 0x1f)));
                            su32(P(iVar2 + 0x28), 1);
                        }
                        iVar4 = iVar4 + 4;
                        local_c = local_c - 1;
                    } while (local_c != 0);
                    iVar4 = local_8;
                    uVar5 = uVar3;
                    do {
                        iVar1 = i32(P(u32(base + 0x14) +
                                      i32(P(static_cast<uint32_t>(iVar4) + param_1[2])) * 4));
                        iVar2 = i32(P(iVar1 + 0x48));
                        if (((iVar2 != -1) && (i32(P(iVar1 + 8)) == -1)) &&
                            (iVar1 = i32(P(u32(base + 0x18) + iVar2 * 4)),
                             i32(P(iVar1 + 0x28)) != 0)) {
                            su32(P(iVar1 + 0x28), 0);
                            su32(P(iVar1 + 0x24),
                                 (u32(P(iVar1 + 0x24)) + 1u) & 0x1f);
                        }
                        iVar4 = iVar4 + 4;
                        uVar5 = uVar5 - 1;
                    } while (uVar5 != 0);
                }
                local_8 = local_8 + static_cast<int32_t>(uVar3 * 4);
                local_14 = local_14 - 1;
            } while (local_14 != 0);
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x660699 — observed shape
// Group search for a fixed-size operand list. For every candidate node found
// by following the slot's +0x34 chain, try to complete a param_3-long list
// whose members share the candidate's shape (+4/+8/+0xc/+0x14/+0x18) and
// sit on the same chain segment; keep the completion with the smallest
// squared distance in +0x48, then either reuse the cached slot or allocate a
// new 0x10000001 slot, fill it (entry list, fresh 0x88 nodes with the
// original chain links and node word), shift the slot table to insert it,
// and bump *param_4. Returns 0x8007000e on allocation failure.
// ---------------------------------------------------------------------------
uint32_t FUN_00660699(void* self, uint32_t param_1, int32_t* param_2,
                      uint32_t param_3, int32_t* param_4)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t* puVar1;
    int32_t iVar2;
    uint32_t uVar3;
    int32_t iVar4;
    uint32_t uVar5;
    int32_t iVar6;
    int32_t iVar7;
    int32_t* piVar8;
    int32_t iVar9;
    uint32_t uVar10;
    int32_t* piVar11;
    int32_t local_40[4];
    int32_t local_30[4];
    int32_t* local_20;
    int32_t local_1c;
    int32_t local_18;
    uint32_t local_14;
    int32_t local_10;
    int32_t* local_c;
    uint32_t local_8;

    local_14 = 0xffffffff;
    iVar2 = i32(P(u32(base + 0x14) +
                  i32(P(i32(P(u32(base + 0x18) + param_1 * 4)) + 0x10)) * 4));
    local_1c = i32(P(iVar2 + 0x14));
    iVar6 = *param_2;
    local_18 = i32(P(iVar2 + 0x18));
    do {
        iVar2 = i32(P(u32(base + 0x14) + iVar6 * 4));
        local_10 = iVar2;
        if ((i32(P(iVar2 + 0x10)) == 0) &&
            ((u32(P(iVar2 + 0x48)) == 0xffffffff) || (u32(P(iVar2 + 0x48)) < param_1))) {
            iVar4 = local_1c;
            iVar7 = local_18;
            if (local_1c != -1) {
                do {
                    if (iVar4 == i32(P(iVar2 + 0x14))) break;
                    iVar4 = i32(P(u32(base + 0x14) + iVar4 * 4));
                    iVar7 = i32(P(iVar4 + 0x18));
                    iVar4 = i32(P(iVar4 + 0x14));
                } while (iVar4 != -1);
            }
            if ((iVar4 == i32(P(iVar2 + 0x14))) && (iVar7 == i32(P(iVar2 + 0x18)))) {
                local_30[0] = iVar6;
                local_8 = 1;
                if (1 < param_3) {
                    piVar8 = param_2 + 1;
                    local_c = piVar8;
                    local_20 = reinterpret_cast<int32_t*>(
                        reinterpret_cast<intptr_t>(local_30) -
                        reinterpret_cast<intptr_t>(param_2));
LAB_0066074b:
                    iVar6 = *piVar8;
                    do {
                        iVar7 = i32(P(u32(base + 0x14) + iVar6 * 4));
                        if ((u32(P(iVar7 + 0x10)) == local_8) &&
                            ((((u32(P(iVar7 + 0x48)) == 0xffffffff) ||
                               (u32(P(iVar7 + 0x48)) < param_1)) &&
                              (i32(P(iVar7 + 4)) == i32(P(iVar2 + 4)))) &&
                             ((i32(P(iVar7 + 0xc)) == i32(P(iVar2 + 0xc)) &&
                               (i32(P(iVar7 + 8)) == i32(P(iVar2 + 8))))))) {
                            iVar4 = local_18;
                            iVar9 = local_1c;
                            if (local_1c != -1) {
                                do {
                                    if (iVar9 == i32(P(iVar7 + 0x14))) break;
                                    iVar9 = i32(P(u32(base + 0x14) + iVar9 * 4));
                                    iVar4 = i32(P(iVar9 + 0x18));
                                    iVar9 = i32(P(iVar9 + 0x14));
                                } while (iVar9 != -1);
                            }
                            if ((iVar9 == i32(P(iVar7 + 0x14))) &&
                                (iVar4 == i32(P(iVar7 + 0x18)))) {
                                goto LAB_006607bc;
                            }
                        }
                        iVar6 = i32(P(iVar7 + 0x34));
                        local_c = piVar8;
                        if (iVar6 == *piVar8) break;
                    } while (true);
                }
LAB_006607dd:
                if (local_8 == param_3) {
                    uVar10 = 0;
                    uVar5 = 0;
                    if (param_3 != 0) {
                        do {
                            if (i32(P(i32(P(u32(base + 0x14) +
                                             local_30[uVar5] * 4)) + 0x48)) != 0) {
                                iVar6 = static_cast<int32_t>(param_1) -
                                        i32(P(i32(P(u32(base + 0x14) +
                                                     local_30[uVar5] * 4)) + 0x48));
                                uVar10 = uVar10 + static_cast<uint32_t>(iVar6 * iVar6);
                            }
                            uVar5 = uVar5 + 1;
                        } while (uVar5 < param_3);
                    }
                    if (uVar10 < local_14) {
                        local_14 = uVar10;
                        piVar8 = local_30;
                        piVar11 = local_40;
                        for (uVar5 = param_3; uVar5 != 0; uVar5 = uVar5 - 1) {
                            *piVar11 = *piVar8;
                            piVar8 = piVar8 + 1;
                            piVar11 = piVar11 + 1;
                        }
                    }
                }
            }
        }
        iVar6 = i32(P(iVar2 + 0x34));
        if (iVar6 == *param_2) {
            if (local_14 == 0xffffffff) {
                uVar5 = FUN_0065da35(param_3 & 0xfffff | 0x10000000, 0xffffffff, 0xffffffff);
                if (uVar5 == 0xffffffff) {
                    return 0x8007000e;
                }
                iVar2 = i32(P(u32(base + 0x18) + uVar5 * 4));
                local_14 = uVar5;
                FUN_0065cc50();
                local_8 = 0;
                if (param_3 != 0) {
                    do {
                        iVar6 = static_cast<int32_t>(local_8 * 4);
                        local_20 = param_2 + local_8;
                        si32(P(static_cast<uint32_t>(iVar6) + u32(P(iVar2 + 8))),
                             *local_20);
                        /* fourth argument is the literal 0 in the listing */
                        uVar3 = FUN_0065d9d5(u32(base + 0x88),
                                             static_cast<uint32_t>(*param_4), local_8, 0.0);
                        su32(P(static_cast<uint32_t>(iVar6) + u32(P(iVar2 + 0x10))), uVar3);
                        if (i32(P(static_cast<uint32_t>(iVar6) +
                                  u32(P(iVar2 + 0x10)))) == -1) {
                            return 0x8007000e;
                        }
                        si32(P(i32(P(u32(base + 0x14) +
                                      i32(P(static_cast<uint32_t>(iVar6) +
                                           u32(P(iVar2 + 0x10)))) * 4)) + 0x18),
                             local_18);
                        si32(P(i32(P(u32(base + 0x14) +
                                      i32(P(static_cast<uint32_t>(iVar6) +
                                           u32(P(iVar2 + 0x10)))) * 4)) + 0x14),
                             local_1c);
                        su32(P(i32(P(u32(base + 0x14) +
                                      i32(P(static_cast<uint32_t>(iVar6) +
                                           u32(P(iVar2 + 0x10)))) * 4))),
                             u32(P(i32(P(u32(base + 0x14) +
                                          i32(P(static_cast<uint32_t>(iVar6) +
                                               u32(P(iVar2 + 8)))) * 4)))));
                        local_8 = local_8 + 1;
                        su32(P(i32(P(u32(base + 0x14) +
                                      i32(P(static_cast<uint32_t>(iVar6) +
                                           u32(P(iVar2 + 0x10)))) * 4)) + 0x34),
                             u32(P(i32(P(u32(base + 0x14) +
                                          i32(P(static_cast<uint32_t>(iVar6) +
                                               u32(P(iVar2 + 8)))) * 4)) + 0x34)));
                        su32(P(i32(P(u32(base + 0x14) +
                                      i32(P(static_cast<uint32_t>(iVar6) +
                                           u32(P(iVar2 + 8)))) * 4)) + 0x34),
                             u32(P(static_cast<uint32_t>(iVar6) +
                                   u32(P(iVar2 + 0x10)))));
                        *local_20 = i32(P(static_cast<uint32_t>(iVar6) +
                                          u32(P(iVar2 + 0x10))));
                    } while (local_8 < param_3);
                    uVar5 = local_14;
                }
                for (; param_1 < uVar5; uVar5 = uVar5 - 1) {
                    puVar1 = reinterpret_cast<uint32_t*>(P(u32(base + 0x18) + uVar5 * 4));
                    *puVar1 = puVar1[-1];
                }
                su32(P(u32(base + 0x18) + uVar5 * 4), static_cast<uint32_t>(iVar2));
                *param_4 = *param_4 + 1;
            } else {
                piVar8 = local_40;
                for (; param_3 != 0; param_3 = param_3 - 1) {
                    *param_2 = *piVar8;
                    piVar8 = piVar8 + 1;
                    param_2 = param_2 + 1;
                }
            }
            return 0;
        }
    } while (true);
LAB_006607bc:
    uVar5 = local_8 + 1;
    local_8 = uVar5;
    si32(P(reinterpret_cast<intptr_t>(local_30) -
           reinterpret_cast<intptr_t>(param_2) +
           reinterpret_cast<intptr_t>(piVar8)), iVar6);
    piVar8 = piVar8 + 1;
    local_c = piVar8;
    if (param_3 <= uVar5) goto LAB_006607dd;
    goto LAB_0066074b;
}

// ---------------------------------------------------------------------------
// 0x66098c — observed shape
// Counts ordering-key run boundaries on the slot table. With flag 0x4000000
// set: seed from the first slot and count each slot whose +0x2c differs from
// its predecessor. With 0x8000000 instead: walk forward, counting a slot
// whose +0x2c low bit is set and whose key differs from its successor (the
// loop body also advances the cursor twice when the keys match).
// ---------------------------------------------------------------------------
uint32_t FUN_0066098c(void* self)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    int32_t* piVar1;
    uint32_t uVar2;
    uint32_t uVar3;
    uint32_t local_c;
    uint32_t local_8;

    uVar3 = 0;
    local_8 = 0;
    if ((u32(base + 0x6c) & 0x4000000) == 0) {
        if (((u32(base + 0x6c) & 0x8000000) != 0) &&
            (uVar2 = u32(base + 0xc), uVar2 != 0)) {
            local_c = 1;
            do {
                if ((((u8(P(i32(P(u32(base + 0x18) + uVar3 * 4)) + 0x2c)) & 1) != 0) &&
                     (local_8 = local_8 + 1, local_c < uVar2)) &&
                    (piVar1 = reinterpret_cast<int32_t*>(P(u32(base + 0x18) + uVar3 * 4)),
                     i32(P(piVar1[0] + 0x2c)) == i32(P(piVar1[1] + 0x2c)))) {
                    uVar3 = uVar3 + 1;
                    local_c = local_c + 1;
                }
                uVar3 = uVar3 + 1;
                local_c = local_c + 1;
            } while (uVar3 < uVar2);
        }
    } else {
        if (u32(base + 0xc) == 0) {
            return 0;
        }
        local_8 = static_cast<uint32_t>(
            (u8(P(i32(P(u32(P(u32(base + 0x18))))) + 0x2c)) & 1) == 0);
        uVar3 = 1;
        if (1 < u32(base + 0xc)) {
            do {
                if (((u8(P(i32(P(u32(base + 0x18) + uVar3 * 4)) + 0x2c)) & 1) != 0) &&
                    (piVar1 = reinterpret_cast<int32_t*>(P(u32(base + 0x18) + uVar3 * 4)),
                     i32(P(piVar1[0] + 0x2c)) != i32(P(piVar1[-1] + 0x2c)))) {
                    local_8 = local_8 + 1;
                }
                uVar3 = uVar3 + 1;
            } while (uVar3 < u32(base + 0xc));
        }
    }
    return local_8;
}

// ---------------------------------------------------------------------------
// 0x660a3e — observed shape
// Reorders the slot table so the entries sharing the ordering key at
// node+0x2c around index param_1 are gathered: it finds the equal-key run,
// reverses the prefix and the run, then when the run is non-empty rotates it
// into place, moving the neighbours one slot and returning 1 (0 when the
// first key is not flagged with bit 1 or nothing moved).
// ---------------------------------------------------------------------------
uint32_t FUN_00660a3e(void* self, uint32_t param_1)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t uVar1;
    int32_t iVar2;
    uint32_t uVar3;
    uint32_t* puVar4;
    int32_t iVar5;
    int32_t iVar6;
    int32_t iVar7;
    int32_t local_14;
    uint32_t local_10;
    int32_t* local_8;

    iVar5 = static_cast<int32_t>(param_1 * 4);
    local_8 = reinterpret_cast<int32_t*>(P(u32(base + 0x18) + iVar5));
    iVar7 = *local_8;
    uVar1 = u32(P(iVar7 + 0x2c));
    iVar2 = static_cast<int32_t>(param_1);
    if ((uVar1 & 1) == 0) {
        return 0;
    }
    while ((iVar2 != 0 &&
            (local_8 = local_8 - 1, uVar1 < u32(P(*local_8 + 0x2c))))) {
        iVar2 = iVar2 + -1;
    }
    local_10 = static_cast<uint32_t>(param_1 - iVar2) >> 1;
    if (local_10 != 0) {
        local_8 = reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(iVar2) << 2);
        iVar6 = iVar5;
        do {
            puVar4 = reinterpret_cast<uint32_t*>(
                P(u32(base + 0x18) +
                  static_cast<uint32_t>(reinterpret_cast<intptr_t>(local_8))));
            uVar3 = *puVar4;
            *puVar4 = u32(P(u32(base + 0x18) + static_cast<uint32_t>(iVar6 - 4)));
            su32(P(u32(base + 0x18) + static_cast<uint32_t>(iVar6 - 4)), uVar3);
            local_8 = reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(local_8) + 4);
            iVar6 = iVar6 + -4;
            local_10 = local_10 - 1;
        } while (local_10 != 0);
    }
    local_14 = iVar2;
    if (iVar2 != 0) {
        uVar1 = u32(P(iVar7 + 0x2c));
        local_8 = reinterpret_cast<int32_t*>(
            P(u32(P(u32(base + 0x18))) + static_cast<uint32_t>(-4 + iVar2 * 4)));
        if (u32(P(*local_8 + 0x2c)) < uVar1) {
            local_14 = iVar2 + -1;
            goto LAB_00660b4d;
        }
        do {
            if (uVar1 != u32(P(*local_8 + 0x2c))) break;
            local_8 = local_8 - 1;
            local_14 = local_14 + -1;
        } while (local_14 != 0);
    }
    local_8 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(
        static_cast<uint32_t>(iVar2 - local_14) >> 1));
    if (local_8 != reinterpret_cast<int32_t*>(0)) {
        local_10 = static_cast<uint32_t>(local_14) << 2;
        iVar7 = iVar2 << 2;
        do {
            puVar4 = reinterpret_cast<uint32_t*>(P(u32(base + 0x18) + local_10));
            uVar3 = *puVar4;
            *puVar4 = u32(P(u32(base + 0x18) + static_cast<uint32_t>(iVar7 - 4)));
            su32(P(u32(base + 0x18) + static_cast<uint32_t>(iVar7 - 4)), uVar3);
            local_10 = local_10 + 4;
            iVar7 = iVar7 + -4;
            local_8 = reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(local_8) - 1);
        } while (local_8 != reinterpret_cast<int32_t*>(0));
    }
LAB_00660b4d:
    if (local_14 == iVar2) {
        uVar3 = 0;
    } else {
        param_1 = param_1 - static_cast<uint32_t>(local_14) >> 1;
        if (param_1 != 0) {
            local_14 = local_14 << 2;
            iVar7 = iVar5;
            do {
                puVar4 = reinterpret_cast<uint32_t*>(
                    P(u32(base + 0x18) + static_cast<uint32_t>(local_14)));
                uVar3 = *puVar4;
                *puVar4 = u32(P(u32(base + 0x18) + static_cast<uint32_t>(iVar7 - 4)));
                su32(P(u32(base + 0x18) + static_cast<uint32_t>(iVar7 - 4)), uVar3);
                local_14 = local_14 + 4;
                iVar7 = iVar7 + -4;
                param_1 = param_1 - 1;
            } while (param_1 != 0);
        }
        puVar4 = reinterpret_cast<uint32_t*>(P(u32(base + 0x18) + iVar5));
        uVar3 = puVar4[-1];
        puVar4[-1] = *puVar4;
        su32(P(u32(base + 0x18) + iVar5), uVar3);
        uVar3 = 1;
    }
    return uVar3;
}

// ---------------------------------------------------------------------------
// 0x660ba6 — observed shape
// Clears every node's +0x30 owner slot, then for each non-empty slot table
// entry walks the cc6f group spans: when the span's first node is already
// owned, require all members on one chain and no key mismatch (else abandon
// the span), then copy the owner slot's +0x30 into every member and report
// a change. For 0x10000000 slots, nodes without owner but with identical
// shape/links and a null +0x3c adopt the operand's node as owner.
// ---------------------------------------------------------------------------
bool FUN_00660ba6(void* self)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    int32_t* piVar1;
    uint32_t* puVar2;
    int32_t iVar3;
    int32_t iVar4;
    int32_t iVar5;
    bool bVar6;
    uint32_t uVar7;
    int32_t local_18;
    uint32_t local_14;
    int32_t* local_10;
    uint32_t local_c;
    uint32_t local_8;

    uVar7 = 0;
    bVar6 = false;
    if (i32(base + 8) != 0) {
        do {
            su32(P(i32(P(u32(base + 0x14) + uVar7 * 4)) + 0x30), 0xffffffff);
            uVar7 = uVar7 + 1;
        } while (uVar7 < u32(base + 8));
    }
    local_14 = 0;
    if (i32(base + 0xc) != 0) {
        do {
            puVar2 = pu32(P(u32(base + 0x18) + local_14 * 4));
            if ((*puVar2 & 0xfff00000) != 0) {
                local_18 = 0;
                while ((local_8 = FUN_0065cc6f(local_18, &local_10)) != 0) {
                    if (i32(P(i32(P(u32(base + 0x14) + *local_10 * 4)) + 0x30)) !=
                        -1) {
                        local_c = 1;
                        if (1 < local_8) {
                            do {
                                if ((i32(P(i32(P(u32(base + 0x14) +
                                                 local_10[local_c] * 4)) + 0x30)) == -1) ||
                                    (iVar3 = i32(base + 0x14),
                                     i32(P(i32(P(static_cast<uint32_t>(iVar3) +
                                                  i32(P(i32(P(static_cast<uint32_t>(iVar3) +
                                                               *local_10 * 4)) + 0x30)) *
                                                      4)) + 0xc)) !=
                                         i32(P(i32(P(static_cast<uint32_t>(iVar3) +
                                                     i32(P(i32(P(static_cast<uint32_t>(iVar3) +
                                                                  local_10[local_c] * 4)) +
                                                              0x30)) * 4)) + 0xc)))) {
                                    break;
                                }
                                local_c = local_c + 1;
                            } while (local_c < local_8);
                            if (local_c < local_8) goto LAB_00660c8d;
                        }
                        uVar7 = 0;
                        if (local_8 != 0) {
                            do {
                                piVar1 = local_10 + uVar7;
                                uVar7 = uVar7 + 1;
                                *piVar1 = i32(P(i32(P(u32(base + 0x14) + *piVar1 * 4)) +
                                                0x30));
                            } while (uVar7 < local_8);
                        }
                        bVar6 = true;
                    }
LAB_00660c8d:
                    local_18 = local_18 + 1;
                }
                if (((*puVar2 & 0xfff00000) == 0x10000000) &&
                    (local_c = 0, puVar2[3] != 0)) {
                    do {
                        iVar3 = i32(P(puVar2[4] + local_c * 4));
                        iVar4 = i32(P(u32(base + 0x14) + iVar3 * 4));
                        iVar5 = i32(P(u32(base + 0x14) +
                                      i32(P(puVar2[2] + local_c * 4)) * 4));
                        if (((i32(P(iVar4 + 4)) == i32(P(iVar5 + 4))) &&
                             ((((i32(P(iVar4 + 8)) == i32(P(iVar5 + 8)) &&
                                 (i32(P(iVar4 + 0x10)) == i32(P(iVar5 + 0x10)))) &&
                                (i32(P(iVar4 + 0x14)) == i32(P(iVar5 + 0x14)))) &&
                               ((i32(P(iVar4 + 0x18)) == i32(P(iVar5 + 0x18)) &&
                                 (i32(P(iVar5 + 0x38)) == -1)))))) &&
                            (i32(P(iVar4 + 0x3c)) == 0)) {
                            si32(P(iVar5 + 0x30), iVar3);
                        }
                        local_c = local_c + 1;
                    } while (local_c < puVar2[3]);
                }
            }
            local_14 = local_14 + 1;
        } while (local_14 < u32(base + 0xc));
    }
    return !bVar6;
}

// ---------------------------------------------------------------------------
// 0x660d40 — observed shape
// Depth marker: when node+0x38 differs from param_3, store the marker, bump
// the caller's change counter and recurse over the node's operand list
// (node+0x18 entries resolved through the self+0x18 slot table).
// ---------------------------------------------------------------------------
void FUN_00660d40(void* self, int32_t param_1, int32_t* param_2, int32_t param_3)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    uint32_t uVar1;

    if (i32(P(param_1 + 0x38)) != param_3) {
        si32(P(param_1 + 0x38), param_3);
        *param_2 = *param_2 + 1;
        uVar1 = 0;
        if (i32(P(param_1 + 0x14)) != 0) {
            do {
                FUN_00660d40(
                    self,
                    i32(P(u32(base + 0x18) +
                          i32(P(i32(P(param_1 + 0x18)) + uVar1 * 4)) * 4)),
                    param_2, param_3);
                uVar1 = uVar1 + 1;
            } while (uVar1 < u32(P(param_1 + 0x14)));
        }
    }
}

// ---------------------------------------------------------------------------
// 0x660d8e — observed shape
// Marks param_1's subtree with depth param_4, then walks the whole slot
// table: for each unowned (node+0x24 == 0) node, inspect its operands and
// bias *param_3 by -0x10000 when the operand descends from param_4's side
// and is itself owned, or by +0x10000 when it descends from the other side.
// ---------------------------------------------------------------------------
void FUN_00660d8e(void* self, uint32_t param_1, uint32_t param_2,
                  int32_t* param_3, uint32_t param_4)
{
    uint8_t* base = static_cast<uint8_t*>(self);
    int32_t iVar1;
    int32_t iVar2;
    int32_t iVar3;
    uint32_t uVar4;

    iVar3 = static_cast<int32_t>(param_4);
    FUN_00660d40(self, static_cast<int32_t>(param_1),
                 reinterpret_cast<int32_t*>(static_cast<uintptr_t>(param_2)),
                 static_cast<int32_t>(param_4));
    param_4 = 0;
    if (i32(base + 0xc) != 0) {
        do {
            iVar1 = i32(P(u32(base + 0x18) + param_4 * 4));
            uVar4 = 0;
            if ((i32(P(iVar1 + 0x24)) == 0) && (i32(P(iVar1 + 0x14)) != 0)) {
                do {
                    iVar2 = i32(P(u32(base + 0x18) +
                                  i32(P(i32(P(iVar1 + 0x18)) + uVar4 * 4)) * 4));
                    if (iVar3 == i32(P(iVar1 + 0x38))) {
                        if (i32(P(iVar2 + 0x24)) != 0) {
                            *param_3 = *param_3 + -0x10000;
                        }
                    } else if (iVar3 == i32(P(iVar2 + 0x38))) {
                        *param_3 = *param_3 + 0x10000;
                    }
                    uVar4 = uVar4 + 1;
                } while (uVar4 < u32(P(iVar1 + 0x14)));
            }
            param_4 = param_4 + 1;
        } while (param_4 < u32(base + 0xc));
    }
}
