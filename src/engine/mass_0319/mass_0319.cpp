// UNVERIFIED decompiler-derived reconstruction — cl 13.10.3077 absent; no PASS.
// Batch mass_0319. Corpus: Ghidra 12.2 pseudocode,
// analysis/pseudocode/functions/0x66*.c. Target is PE32 i386; 32-bit fields
// that receive addresses are called out where the listing truncates them.
//
// Observed record shapes (from the listings in this batch only):
//   ctx+0x04 count of types, ctx+0x08 count of nodes, ctx+0x0c count of groups,
//   ctx+0x10 type table, ctx+0x14 node table, ctx+0x18 group table.
//   node: byte3@0x03, typeIndex@0x04, next@0x08, key8@0x08, f0c@0x0c,
//         parent@0x14, f18@0x18, weight(lo)@0x20 double, label@0x30,
//         order@0x34, f38@0x38, f3c@0x3c, block@0x48, chain@0x4c...
//   type: flags32@0x04, byte5@0x05, size@0x08, f0c@0x0c, offset@0x10,
//         f14@0x14, owner@0x18, ptr@0x20, lo@0x28, hi@0x2c, count@0x30.
//   group: tag@0x00, count1@0x04, list1@0x08, count2@0x0c, list2@0x10,
//          count3@0x14, list3@0x18, count4@0x1c, list4@0x20, flag@0x24,
//          value@0x30.

#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---- observed-record access helpers (byte offsets are the contract) --------
static inline uint8_t* Bytes(void* p) { return static_cast<uint8_t*>(p); }
static inline int32_t& I32(void* p, std::size_t o) { return *reinterpret_cast<int32_t*>(Bytes(p) + o); }
static inline uint32_t& U32(void* p, std::size_t o) { return *reinterpret_cast<uint32_t*>(Bytes(p) + o); }
static inline uint8_t& U8(void* p, std::size_t o) { return *(Bytes(p) + o); }
static inline double& F64(void* p, std::size_t o) { return *reinterpret_cast<double*>(Bytes(p) + o); }
static inline void*& PTR(void* p, std::size_t o) { return *reinterpret_cast<void**>(Bytes(p) + o); }

// ---- callee corpus labels (signatures inferred from call sites) ------------
extern void*    __cdecl FUN_00533c78(uint32_t bytes);   // allocation (0x661fbd)
extern void     __cdecl operator_delete(void* p);
extern int32_t  __cdecl FUN_0065ccac(void* self);
extern void     __cdecl FUN_0065de79(void);
extern int32_t  __cdecl FUN_0065d9d5(void* owner78, int32_t a, int32_t b, double key);
extern void     __cdecl FUN_0065e1b9(void (*fn)(void), void* list, uint32_t count, void* self);
extern void     __cdecl FUN_00660d8e(void* node, int32_t* outA, int32_t* outB, int32_t index);

// Averages each child from FUN_00660d8e as outB/(outA+1), sorts the child
// list, recurses into every child, then appends this group's index post-order
// to param_2. Group flag +0x24 marks an already-emitted group.
// 0x660e0e — observed shape: recursive group walk with post-order emit.
int32_t FUN_00660e0e(void* self, uint32_t param_1, int32_t* param_2, int32_t* param_3)
{
    uint32_t uVar5 = 0;
    uint32_t k = 0;
    void*    saved;
    void*    grp;
    int32_t* a18;
    int32_t  local_10 = 0;
    int32_t  local_c = 0;

    grp = PTR(PTR(self, 0x18), param_1 * 4);
    if (I32(grp, 0x24) != 0) return 0;
    saved = self;
    a18 = (int32_t*)PTR(grp, 0x18);
    if (I32(grp, 0x14) != 0) {
        do {
            local_10 = 0;
            local_c = 0;
            int32_t idx = a18[k];
            void* child = PTR(PTR(saved, 0x18), idx * 4);
            FUN_00660d8e(child, &local_c, &local_10, idx);
            k = k + 1;
            I32(child, 0x30) = local_10 / (local_c + 1);
        } while (k < U32(grp, 0x14));
    }
    FUN_0065e1b9(FUN_0065de79, PTR(grp, 0x18), U32(grp, 0x14), self);
    uVar5 = 0;
    if (I32(grp, 0x14) != 0) {
        do {
            int32_t r = FUN_00660e0e(self, (uint32_t)a18[uVar5], param_2, param_3);
            if (r < 0) return r;
            uVar5 = uVar5 + 1;
        } while (uVar5 < U32(grp, 0x14));
    }
    if (I32(grp, 0x24) == 0) {
        uint32_t n = 0;
        I32(grp, 0x24) = 1;
        param_2[*param_3] = (int32_t)param_1;
        *param_3 = *param_3 + 1;
        if (I32(grp, 0x14) != 0) {
            do {
                void** arr18 = (void**)PTR(self, 0x18);
                void* node = arr18[a18[n]];
                uint32_t cnt = U32(node, 0x1c);
                uint32_t found = 0;
                uint32_t i = 0;
                int32_t* a20 = (int32_t*)PTR(node, 0x20);
                int32_t* cur = a20;
                if (cnt != 0) {
                    do {
                        if (I32(arr18[cur[0]], 0x24) == 0) {
                            if (found != 0xffffffff) goto LAB_00660f31;
                            found = i;
                        }
                        i = i + 1;
                        cur = cur + 1;
                    } while (i < cnt);
                    if (found != 0xffffffff) {
LAB_00660f31:
                        if (i == cnt) {
                            void* nxt = arr18[a20[found]];
                            uint32_t cnt2 = U32(nxt, 0x14);
                            uint32_t j = 0;
                            if (cnt2 != 0) {
                                int32_t* lst = (int32_t*)PTR(nxt, 0x18);
                                do {
                                    if (I32(arr18[lst[0]], 0x24) == 0) break;
                                    j = j + 1;
                                    lst = lst + 1;
                                } while (j < cnt2);
                            }
                            if (cnt2 <= j) {
                                int32_t r = FUN_00660e0e(self, (uint32_t)a20[found], param_2, param_3);
                                if (r < 0) return r;
                            }
                        }
                    }
                }
                n = n + 1;
            } while (n < U32(grp, 0x14));
        }
    }
    return 0;
}

// Slot param_1[param_3 + param_2*4] is -1 until filled; the first node of a
// type seeds +0x0c/+0x10, otherwise FUN_0065d9d5 is consulted with the node's
// 64-bit value at +0x20.
// 0x660f99 — observed shape: memoized lookup by slot.
int32_t FUN_00660f99(void* self, int32_t* param_1, int32_t param_2, uint32_t param_3, uint32_t param_4)
{
    int32_t* slot = param_1 + (param_3 + param_2 * 4);
    if (*slot == -1) {
        uint32_t off = param_4 * 4;
        void* e = PTR(PTR(self, 0x14), off);
        if (I32(e, 0xc) == -1) {
            I32(e, 0xc) = param_2;
            I32(e, 0x10) = (int32_t)param_3;
        }
        else {
            param_4 = (uint32_t)FUN_0065d9d5(PTR(self, 0x78), param_2, (int32_t)param_3, F64(e, 0x20));
        }
        *slot = (int32_t)param_4;
    }
    return *slot;
}

// Candidate slots are unified onto the double key at node+0x20; mismatching
// entries are remapped through the param_1 table, and when no slot yields a
// key every slot is overwritten with the single matching table entry.
// 0x660ffb — observed shape: key unification; returns 0 on every path.
uint32_t FUN_00660ffb(void* self, int32_t* param_1, int32_t* param_2, uint32_t param_3)
{
    uint32_t uVar4 = 1;
    uint32_t uVar3 = 0;
    int32_t* piVar2 = param_2;

    if (1 < param_3) {
        do {
            if (F64(PTR(PTR(self, 0x14), piVar2[uVar4] * 4), 0x20) !=
                F64(PTR(PTR(self, 0x14), piVar2[0] * 4), 0x20)) {
                uVar4 = 0;
                if (param_3 == 0) return 0;
                do {
                    int32_t n = 0;
                    do {
                        uVar3 = (uint32_t)((n + (int32_t)uVar4) & 3);
                        int32_t iVar1 = param_1[uVar3];
                        if ((iVar1 != -1) &&
                            (F64(PTR(PTR(self, 0x14), piVar2[uVar4] * 4), 0x20) ==
                             F64(PTR(PTR(self, 0x14), iVar1 * 4), 0x20))) {
                            piVar2[uVar4] = param_1[uVar3];
                            break;
                        }
                        n = n + 1;
                    } while (n < 4);
                    uVar4 = uVar4 + 1;
                    if (param_3 <= uVar4) return 0;
                } while (true);
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < param_3);
    }
    {
        int32_t n = 0;
        while (true) {
            uVar3 = (uint32_t)((n - 1) & 3);
            int32_t iVar1 = param_1[uVar3];
            if ((iVar1 != -1) &&
                (F64(PTR(PTR(self, 0x14), piVar2[0] * 4), 0x20) ==
                 F64(PTR(PTR(self, 0x14), iVar1 * 4), 0x20))) break;
            n = n + 1;
            if (3 < n) return 0;
        }
    }
    {
        uint32_t k = 0;
        if (param_3 == 0) return 0;
        do {
            piVar2[k] = param_1[uVar3];
            k = k + 1;
        } while (k < param_3);
    }
    return 0;
}

// With ctx flag word 0x6c low bits clear the masks are zeroed; otherwise masks
// are validated (E_FAIL 0x80004005 for duplicate bits, more than one zero slot
// when bit 2 is set, or more than four distinct bits) and candidate ids with
// equal double keys are merged before FUN_00660f99 canonicalizes changed ids.
// 0x6610ec — observed shape: 4-slot alias/overlap resolver.
uint32_t FUN_006610ec(void* self, int32_t* param_1, int32_t* param_2, uint32_t* param_3)
{
    uint32_t uVar4 = 0;
    uint32_t uVar2 = 0;
    uint32_t uVar6 = 0;
    uint32_t local_8 = 0;
    uint32_t local_c = 0;
    uint32_t local_18 = 0;
    uint32_t local_1c = 0;
    int32_t  iVar3 = 0;
    int32_t  local_2c[4];
    int32_t* local_14 = param_1;
    int32_t* piVar1 = nullptr;

    do {
        if (param_2[uVar2] == -1) break;
        local_8 = local_8 + 1;
        uVar2 = uVar2 + 1;
    } while (uVar2 < 4);
    if (local_8 == 0) return 0;
    if ((U32(self, 0x6c) & 6) == 0) {
        if (local_8 != 0) {
            uint32_t* puVar8 = param_3;
            for (uVar2 = local_8; uVar2 != 0; uVar2 = uVar2 - 1) {
                *puVar8 = 0;
                puVar8 = puVar8 + 1;
            }
        }
    }
    else {
        uVar2 = 1;
        if (1 < local_8) {
            do {
                if (F64(PTR(PTR(self, 0x14), param_2[0] * 4), 0x20) !=
                    F64(PTR(PTR(self, 0x14), param_2[uVar2] * 4), 0x20)) break;
                uVar2 = uVar2 + 1;
            } while (uVar2 < local_8);
        }
        if (uVar2 == local_8) {
            *param_3 = 0;
            local_8 = 1;
        }
        uVar2 = 0;
        if (local_8 != 0) {
            do {
                uVar4 = uVar4 + (uint32_t)(param_3[uVar2] == 0);
                uVar2 = uVar2 + 1;
            } while (uVar2 < local_8);
        }
        if (((U8(self, 0x6c) & 4) != 0) && (uVar4 != 0)) {
            if (1 < uVar4) return 0x80004005;
            uVar2 = 0;
            if (local_8 != 0) {
                do {
                    if ((param_3[uVar2] & 8) != 0) return 0x80004005;
                    if (param_3[uVar2] == 0) param_3[uVar2] = 8;
                    uVar2 = uVar2 + 1;
                } while (uVar2 < local_8);
            }
            uVar4 = 0;
        }
        uVar2 = 0;
        uVar6 = 0;
        if (local_8 != 0) {
            do {
                if ((uVar6 & param_3[uVar2]) != 0) return 0x80004005;
                uVar6 = uVar6 | param_3[uVar2];
                uVar2 = uVar2 + 1;
            } while (uVar2 < local_8);
        }
        iVar3 = 0;
        uVar2 = 0;
        do {
            if ((uVar6 & (1u << (uVar2 & 0x1f))) != 0) iVar3 = iVar3 + 1;
            uVar2 = uVar2 + 1;
        } while (uVar2 < 4);
        if (4 < (uint32_t)(iVar3 + (int32_t)uVar4)) return 0x80004005;
    }
    local_1c = 0;
    local_14 = param_1;
    for (;;) {
        piVar1 = local_14;
        local_c = 0;
        local_2c[0] = local_14[0];
        local_2c[1] = local_14[1];
        local_2c[2] = local_14[2];
        local_2c[3] = local_14[3];
        if (local_8 == 0) goto LAB_006612a5;
        do {
            uVar4 = 0;
            uVar2 = param_3[local_c];
            do {
                if ((uVar2 & (1u << (uVar4 & 0x1f))) != 0) {
                    iVar3 = local_2c[uVar4];
                    if (iVar3 == -1) {
                        local_2c[uVar4] = param_2[local_c];
                    }
                    else if (F64(PTR(PTR(self, 0x14), iVar3 * 4), 0x20) !=
                             F64(PTR(PTR(self, 0x14), param_2[local_c] * 4), 0x20)) {
                        break;
                    }
                }
                uVar4 = uVar4 + 1;
            } while (uVar4 < 4);
        } while ((3 < uVar4) && (local_c = local_c + 1, local_c < local_8));
        if (local_8 <= local_c) goto LAB_006612a5;
        local_1c = local_1c + 1;
        local_14 = local_14 + 4;
        continue;

LAB_006612a5:
        local_18 = 0;
        if (local_8 != 0) {
            int32_t* piVar5 = param_2;
            do {
                uVar2 = 0;
                if (param_3[local_18] == 0) {
                    do {
                        if ((local_2c[uVar2] != -1) &&
                            (F64(PTR(PTR(self, 0x14), local_2c[uVar2] * 4), 0x20) ==
                             F64(PTR(PTR(self, 0x14), param_2[local_18] * 4), 0x20))) break;
                        uVar2 = uVar2 + 1;
                    } while (uVar2 < 4);
                    if (3 < uVar2) {
                        uVar2 = 0;
                        do {
                            if (local_2c[uVar2] == -1) {
                                local_2c[uVar2] = *piVar5;
                                break;
                            }
                            uVar2 = uVar2 + 1;
                        } while (uVar2 < 4);
                        if (uVar2 == 4) break;
                    }
                }
                local_18 = local_18 + 1;
                piVar5 = piVar5 + 1;
            } while (local_18 < local_8);
            if (local_8 > local_18) {
                local_1c = local_1c + 1;
                local_14 = local_14 + 4;
                continue;
            }
        }
        break;
    }
LAB_00661342:
    uVar2 = 0;
    do {
        iVar3 = local_2c[uVar2];
        if (iVar3 != piVar1[uVar2]) {
            iVar3 = FUN_00660f99(self, param_1, (int32_t)local_1c, uVar2, (uint32_t)iVar3);
        }
        uVar2 = uVar2 + 1;
        param_2[uVar2 - 1] = iVar3;
    } while (uVar2 < 4);
    return 0;
}

// Node group id +0x48 must lie in [param_3, param_4); a parent walk from the
// id at the head of the param_2 descriptor's 0x10 table must end at the node's
// own (parent, f18) pair. An unassigned group (-1) returns 1.
// 0x66138f — observed shape: containment test.
uint32_t FUN_0066138f(void* self, int32_t param_1, void* param_2, uint32_t param_3, uint32_t param_4)
{
    void* n = PTR(PTR(self, 0x14), param_1 * 4);
    uint32_t uVar2 = U32(n, 0x48);
    uint32_t uVar4;

    if (uVar2 == 0xffffffff) {
        uVar4 = 1;
    }
    else {
        uVar4 = 0;
        if ((param_3 <= uVar2) && (uVar2 < param_4)) {
            int32_t head = I32(PTR(param_2, 0x10), 0);
            void* m = PTR(PTR(self, 0x14), head * 4);
            int32_t iVar5 = I32(m, 0x18);
            int32_t iVar3 = I32(m, 0x14);
            if (iVar3 != -1) {
                do {
                    if (iVar3 == I32(n, 0x14)) break;
                    void* p = PTR(PTR(self, 0x14), iVar3 * 4);
                    iVar5 = I32(p, 0x18);
                    iVar3 = I32(p, 0x14);
                } while (iVar3 != -1);
            }
            if ((iVar3 == I32(n, 0x14)) && (iVar5 == I32(n, 0x18))) uVar4 = 1;
        }
    }
    return uVar4;
}

// Compares the three leading int fields at +0x04, +0x08 and +0x0c of two nodes.
// 0x6613f9 — observed shape: structural identity of two nodes.
uint32_t FUN_006613f9(void* self, int32_t param_1, int32_t param_2)
{
    void* a = PTR(PTR(self, 0x14), param_1 * 4);
    void* b = PTR(PTR(self, 0x14), param_2 * 4);
    if ((I32(a, 4) == I32(b, 4)) &&
        (I32(a, 8) == I32(b, 8)) &&
        (I32(a, 0xc) == I32(b, 0xc))) {
        return 1;
    }
    return 0;
}

// Groups tagged 0x10100000 negate the incoming double and return list1[slot];
// groups tagged 0x20400000/0x20500000 scan two list2 lanes, scaling by the
// candidate's double at +0x20 and adding param_3 unless the tag is 0x20500000.
// 0x66144c — observed shape: resolve a node to a group-local value.
uint32_t FUN_0066144c(void* self, uint32_t param_1, double* param_2, double* param_3)
{
    void* node = PTR(PTR(self, 0x14), param_1 * 4);
    int32_t iVar1 = I32(node, 0x48);
    uint32_t uVar5 = 0xffffffff;

    if ((iVar1 != -1) && (I32(node, 8) == -1)) {
        uint8_t* blk = (uint8_t*)PTR(PTR(self, 0x18), iVar1 * 4);
        uint32_t uVar9 = U32(blk, 0) & 0xfff00000;
        uint32_t* base = (uint32_t*)PTR(blk, 8);
        uint32_t* idx = (uint32_t*)PTR(blk, 0x10);
        if (uVar9 == 0x10100000) {
            uint32_t k = 0;
            if (U32(blk, 0xc) != 0) {
                do {
                    if ((int32_t)idx[k] == (int32_t)param_1) break;
                    k = k + 1;
                } while (k < U32(blk, 0xc));
            }
            if (param_2 != nullptr) *param_2 = -*param_2;
            uVar5 = base[k];
        }
        else if ((uVar9 == 0x20500000) || (uVar9 == 0x20400000)) {
            uint32_t uVar10 = 0;
            if (U32(blk, 0xc) != 0) {
                do {
                    if ((int32_t)idx[uVar10] == (int32_t)param_1) break;
                    uVar10 = uVar10 + 1;
                } while (uVar10 < U32(blk, 0xc));
            }
            uint32_t uVar3 = U32(blk, 0xc);
            uint32_t lane = 0;
            uint32_t* puVar8 = base + uVar10;
            int32_t* local_8 = (int32_t*)(base + (uVar3 + uVar10));
            do {
                uVar5 = *puVar8;
                void* m = PTR(PTR(self, 0x14), (*local_8) * 4);
                if (((U8(PTR(PTR(self, 0x10), I32(m, 4) * 4), 5) & 1) != 0) &&
                    (I32(m, 8) == -1)) {
                    if (param_2 != nullptr) {
                        double dVar4 = F64(m, 0x20) * *param_2;
                        if (uVar9 != 0x20500000) {
                            dVar4 = dVar4 + *param_3;
                            param_2 = param_3;
                        }
                        *param_2 = dVar4;
                    }
                    return uVar5;
                }
                lane = lane + 1;
                puVar8 = puVar8 + uVar3;
                local_8 = local_8 - uVar3;
            } while (lane < 2);
            if ((uVar9 == 0x20400000) && (base[uVar10] == base[uVar3 + uVar10])) {
                if (param_2 != nullptr) *param_2 = *param_2 + *param_2;
                uVar5 = base[uVar10];
            }
            else {
                uVar5 = 0xffffffff;
            }
        }
    }
    return uVar5;
}

// Type entries matching all bits of param_2 and none of param_3 are sized
// (+0x08 = node->0x0c + 1), stacked at +0x10, owned by param_1 (+0x18) and
// their nodes rebased onto those offsets while node->0x0c accumulates; the
// final size lands in entry param_1 and flag 0x400 sets entry byte5 bit 2.
// 0x6615b9 — observed shape: three-pass size/offset assignment.
uint32_t FUN_006615b9(void* self, int32_t param_1, uint32_t param_2, uint32_t param_3)
{
    uint32_t uVar5 = 0;
    uint32_t uVar6 = 0;
    uint32_t local_8 = 0;
    int32_t  iVar7 = 0;
    bool     bVar4 = false;

    if (I32(self, 4) != 0) {
        do {
            void* t = PTR(PTR(self, 0x10), uVar5 * 4);
            uVar6 = U32(t, 4);
            if (((uVar6 & param_2) == param_2) && ((param_3 & uVar6) == 0)) {
                U32(t, 8) = 0;
            }
            uVar5 = uVar5 + 1;
        } while (uVar5 < U32(self, 4));
    }
    uVar5 = 0;
    if (I32(self, 8) != 0) {
        do {
            void* n = PTR(PTR(self, 0x14), uVar5 * 4);
            void* t = PTR(PTR(self, 0x10), I32(n, 4) * 4);
            if (((U32(t, 4) & param_2) == param_2) && ((param_3 & U32(t, 4)) == 0)) {
                uVar6 = (uint32_t)(I32(n, 0xc) + 1);
                if (U32(t, 8) <= uVar6) U32(t, 8) = uVar6;
            }
            uVar5 = uVar5 + 1;
        } while (uVar5 < U32(self, 8));
    }
    uVar5 = 0;
    if (I32(self, 4) != 0) {
        do {
            void* t = PTR(PTR(self, 0x10), uVar5 * 4);
            uVar6 = U32(t, 4);
            if (((uVar6 & param_2) == param_2) && ((param_3 & uVar6) == 0)) {
                I32(t, 0x10) = iVar7;
                I32(t, 0x18) = param_1;
                if ((uVar6 & 0x400) != 0) bVar4 = true;
                iVar7 = iVar7 + I32(t, 8);
                U32(t, 8) = 0;
            }
            uVar5 = uVar5 + 1;
        } while (uVar5 < U32(self, 4));
    }
    local_8 = 0;
    if (I32(self, 8) != 0) {
        do {
            void* n = PTR(PTR(self, 0x14), local_8 * 4);
            void* t = PTR(PTR(self, 0x10), I32(n, 4) * 4);
            if (((U32(t, 4) & param_2) == param_2) && ((param_3 & U32(t, 4)) == 0)) {
                U32(n, 4) = U32(t, 0x18);
                I32(n, 0xc) = I32(n, 0xc) + I32(t, 0x10);
            }
            local_8 = local_8 + 1;
        } while (local_8 < U32(self, 8));
    }
    I32(PTR(PTR(self, 0x10), param_1 * 4), 8) = iVar7;
    if (bVar4) {
        U8(PTR(PTR(self, 0x10), param_1 * 4), 5) |= 4;
    }
    return 0;
}

// Skips the surplus links of the longer parent chain, then walks both chains
// in lockstep comparing the f18 (+0x18) labels.
// 0x6616de — observed shape: parent-chain label comparison.
bool FUN_006616de(void* self, int32_t param_1, int32_t param_2, int32_t param_3, int32_t param_4)
{
    uint32_t uVar3 = 0;
    uint32_t local_8 = 0;
    bool     bVar4 = false;

    if (param_1 != -1) {
        int32_t iVar2 = param_1;
        do {
            iVar2 = I32(PTR(PTR(self, 0x14), iVar2 * 4), 0x14);
            local_8 = local_8 + 1;
        } while (iVar2 != -1);
    }
    if (param_3 != -1) {
        int32_t iVar2 = param_3;
        do {
            iVar2 = I32(PTR(PTR(self, 0x14), iVar2 * 4), 0x14);
            uVar3 = uVar3 + 1;
        } while (iVar2 != -1);
    }
    if (uVar3 < local_8) {
        int32_t iVar2 = (int32_t)(local_8 - uVar3);
        do {
            void* iVar1 = PTR(PTR(self, 0x14), param_1 * 4);
            param_2 = I32(iVar1, 0x18);
            local_8 = local_8 - 1;
            iVar2 = iVar2 - 1;
            param_1 = I32(iVar1, 0x14);
        } while (iVar2 != 0);
        bVar4 = uVar3 < local_8;
    }
    if (!(bVar4 || uVar3 == local_8)) {
        int32_t iVar2 = (int32_t)(uVar3 - local_8);
        do {
            iVar2 = iVar2 - 1;
            void* iVar1 = PTR(PTR(self, 0x14), param_3 * 4);
            param_4 = I32(iVar1, 0x18);
            param_3 = I32(iVar1, 0x14);
        } while (iVar2 != 0);
    }
    if (param_1 != param_3) {
        do {
            void* iVar2 = PTR(PTR(self, 0x14), param_1 * 4);
            void* iVar1 = PTR(PTR(self, 0x14), param_3 * 4);
            param_2 = I32(iVar2, 0x18);
            param_4 = I32(iVar1, 0x18);
            param_1 = I32(iVar2, 0x14);
            param_3 = I32(iVar1, 0x14);
        } while (param_1 != param_3);
    }
    return param_2 != param_4;
}

// Walks the chain at desc->0x1c[param_4 + param_3*4]; an overlap is confirmed
// when a 12-byte record (desc->0x58 indexed through desc->0x54) has its key
// above the candidate's +0x48 and both ids share a parent chain (FUN_006616de).
// Returns the first overlapping node id, else -1.
// 0x661793 — observed shape: overlap probe against a candidate chain.
int32_t FUN_00661793(void* self, void* desc, uint32_t param_2, int32_t param_3, int32_t param_4)
{
    void* node = PTR(PTR(self, 0x14), param_2 * 4);
    int32_t* a1c = (int32_t*)PTR(desc, 0x1c);
    int32_t* a50 = (int32_t*)PTR(desc, 0x50);
    uint32_t* a4c = (uint32_t*)PTR(desc, 0x4c);
    int32_t* a54 = (int32_t*)PTR(desc, 0x54);
    uint8_t* a58 = (uint8_t*)PTR(desc, 0x58);

    param_3 = a1c[param_4 + param_3 * 4];
    if (param_3 == -1) return -1;
    do {
        void* iVar3 = PTR(PTR(self, 0x14), param_3 * 4);
        if ((uint32_t)I32(iVar3, 0x48) < U32(node, 0x58)) {
            if (U32(iVar3, 0x58) <= U32(node, 0x48)) return -1;
            if ((I32(node, 0x14) == I32(iVar3, 0x14)) &&
                (I32(node, 0x18) == I32(iVar3, 0x14))) {
                return param_3;
            }
            void* iVar6;
            void* other;
            if (U32(node, 0x48) < U32(iVar3, 0x48)) {
                iVar6 = node;
                other = iVar3;
            }
            else {
                iVar6 = iVar3;
                other = node;
            }
            uint32_t f74 = (uint32_t)I32(iVar6, 0x74);
            int32_t iVar7 = a50[f74];
            uint32_t uVar5 = a4c[f74];
            uint32_t lane = 0;
            if (uVar5 != 0) {
                do {
                    uint32_t* rec = (uint32_t*)(a58 + a54[iVar7 + (int32_t)lane] * 0xc);
                    if (*rec <= U32(other, 0x48)) break;
                    int32_t r = FUN_006616de(self, I32(other, 0x14), I32(other, 0x18),
                                             (int32_t)rec[1], (int32_t)rec[2]);
                    if (r == 0) return param_3;
                    lane = lane + 1;
                } while (lane < uVar5);
            }
        }
        param_3 = I32(iVar3, 0x30);
        if (param_3 == -1) return -1;
    } while (true);
}

// A per-node spread count comes from desc->0x08[node->0x0c]; lanes are paired
// while FUN_00661793 reports no overlap; the result is local_8 << 29 with bit
// 28 set when param_4 >= 1 and param_3 bit0 is clear, then widened by
// FUN_00661793 failures (uVar4 << 24) until param_6 is met.
// 0x661891 — observed shape: pairing search over the four lanes in local_4c.
uint32_t FUN_00661891(void* self, void* desc, int32_t param_2, uint32_t param_3,
                      int32_t param_4, uint32_t* param_5, uint32_t param_6)
{
    void* node = PTR(PTR(self, 0x14), param_2 * 4);
    int32_t* a8 = (int32_t*)PTR(desc, 8);
    int32_t* a18 = (int32_t*)PTR(desc, 0x18);
    int32_t* a30 = (int32_t*)PTR(desc, 0x30);
    int32_t* a34 = (int32_t*)PTR(desc, 0x34);
    uint32_t* a38 = (uint32_t*)PTR(desc, 0x38);
    uint8_t* a10 = (uint8_t*)PTR(desc, 0x10);
    int32_t* a14 = (int32_t*)PTR(desc, 0x14);
    uint32_t local_24 = (uint32_t)a8[I32(node, 0xc)];
    void*    local_20 = node;
    uint32_t local_c = 4;
    void*    local_18 = self;
    uint32_t local_4c[9];
    int32_t  local_28 = 0;
    uint32_t local_1c = 0;
    uint32_t local_14 = 0;
    uint32_t* local_10 = nullptr;
    uint32_t uVar3 = 0;
    uint32_t uVar4 = 0;
    uint32_t uVar6 = 0;
    uint32_t local_8 = 0;
    int32_t  iVar2 = 0;
    int32_t  iVar5 = 0;

    if ((U8(node, 3) & 0x80) != 0) {
        local_c = 1;
    }
    else {
        bool bVar7 = (local_24 == 0);
        bool bVar8 = false;
        bool out = false;
        if (local_24 == 1) {
            if ((U8(self, 0x6c) & 4) != 0) out = true;
            else { bVar7 = false; bVar8 = true; }
        }
        if (!out) {
            if ((!bVar7 && !bVar8) && ((U8(self, 0x6c) & 2) != 0)) {
                out = true;
            }
            else {
                iVar2 = FUN_0065ccac(self);
                if (iVar2 != 0) out = true;
            }
        }
        if (out) local_c = 1;
    }
    local_4c[4] = 0xffffffff;
    local_4c[5] = 0xffffffff;
    local_4c[6] = 0xffffffff;
    local_4c[7] = 0xffffffff;
    local_4c[0] = 0xffffffff;
    local_4c[1] = 0xffffffff;
    local_4c[2] = 0xffffffff;
    local_4c[3] = 0xffffffff;
    local_8 = 4;
    param_2 = 0;
    {
        int32_t off = I32(node, 0xc) << 4;
        do {
            local_28 = *(int32_t*)((uint8_t*)a18 + off);
            local_1c = 0;
            if (local_28 == -1) {
                local_8 = local_8 - 1;
            }
            else {
                local_4c[8] = *(uint32_t*)((uint8_t*)a30 + off);
                local_14 = 0;
                if (local_4c[8] == 0) {
                    local_8 = local_8 - 1;
                }
                else {
                    local_10 = a38 + *(int32_t*)((uint8_t*)a34 + off);
                    do {
                        uVar6 = *(uint32_t*)(a10 + (*local_10 & 0xfffffffc));
                        if (uVar6 != 0xffffffff) local_1c = 1;
                        if (((param_3 == uVar6) &&
                             (uVar6 = (uint32_t)a14[*local_10], uVar6 != 0xffffffff)) &&
                            ((local_4c[uVar6 + 4] == 0xffffffff) &&
                             ((local_c != 1 || (param_2 == (int32_t)uVar6)))) &&
                            ((iVar2 = FUN_00661793(self, desc, local_28, param_3, (int32_t)uVar6)) == -1)) {
                            local_8 = local_8 - 1;
                            local_4c[uVar6 + 4] = (uint32_t)param_2;
                            local_4c[param_2] = uVar6;
                            break;
                        }
                        local_14 = local_14 + 1;
                        local_10 = local_10 + 1;
                    } while (local_14 < local_4c[8]);
                    if (local_1c == 0) local_8 = local_8 - 1;
                }
            }
            uVar6 = 0;
            param_2 = param_2 + 1;
            off = off + 4;
        } while (param_2 < 4);
    }
    uVar3 = local_8 << 0x1d;
    if (param_6 <= uVar3) return uVar3;
    iVar5 = 0;
    if (param_4 < 0) {
        if ((param_3 & 1) != 0) iVar5 = 1;
    }
    else if (!(param_4 < 1) && ((param_3 & 1) == 0)) {
        iVar5 = 1;
    }
    uVar3 = uVar3 | ((uint32_t)iVar5 << 0x1c);
    param_4 = (int32_t)uVar3;
    if (uVar3 < param_6) {
        do {
            if ((local_4c[uVar6] == 0xffffffff) &&
                ((iVar5 = a18[uVar6 + I32(node, 0xc) * 4]) != -1)) {
                uVar4 = 0;
                if (local_c != 0) {
                    do {
                        uVar3 = (uVar4 + uVar6) & 3;
                        if (local_24 == 1) {
                            bool turn;
                            if ((U8(local_18, 0x70) & 2) == 0) {
                                turn = true;
                            }
                            else {
                                uint32_t tag = U32(PTR(PTR(local_18, 0x18),
                                                       I32(local_20, 0x48) * 4), 0);
                                turn = ((tag & 0xfff00000) != 0x50000000) ||
                                       (3 < (tag & 0xfffff));
                            }
                            if (turn) uVar3 = 3 - uVar3;
                        }
                        if ((local_4c[uVar3 + 4] == 0xffffffff) &&
                            ((iVar2 = FUN_00661793(self, desc, iVar5, param_3, (int32_t)uVar3)) == -1)) {
                            local_4c[uVar3 + 4] = uVar6;
                            local_4c[uVar6] = uVar3;
                            break;
                        }
                        uVar4 = uVar4 + 1;
                    } while (uVar4 < local_c);
                }
                if (local_c == uVar4) return 0xffffffff;
                if ((U8(desc, 0x60) & 1) == 0) {
                    param_4 = (int32_t)((uint32_t)param_4 + uVar4 * 0x1000000);
                    uVar3 = (uint32_t)param_4;
                    if (param_6 <= uVar3) return uVar3;
                }
                else {
                    uVar3 = (uint32_t)param_4;
                    if (1 < local_24) {
                        param_4 = (int32_t)((uint32_t)param_4 + uVar4 * 0x1000000);
                        uVar3 = (uint32_t)param_4;
                        if (param_6 <= uVar3) return uVar3;
                    }
                }
            }
            uVar6 = uVar6 + 1;
        } while (uVar6 < 4);
        if (param_5 != nullptr) {
            param_5[0] = local_4c[0];
            param_5[1] = local_4c[1];
            param_5[2] = local_4c[2];
            param_5[3] = local_4c[3];
        }
    }
    return uVar3;
}

// Walks the node sibling chain for the state record keyed by param_1[0]; each
// match bumps the a4c counter and writes a 12-byte record into a58 (indexed by
// the staged offset a54[sum]) holding the type tag, a type-dependent lane pair
// and the widest +0x58 seen among children whose type byte5 has bit 7 set.
// 0x661b07 — observed shape: record emission along a node chain.
void FUN_00661b07(void* self, void* state, int32_t param_2, int32_t param_3)
{
    void** arr10 = (void**)PTR(self, 0x10);
    void** arr14 = (void**)PTR(self, 0x14);
    void** arr18 = (void**)PTR(self, 0x18);
    int32_t* a4c = (int32_t*)PTR(state, 0x4c);
    int32_t* a50 = (int32_t*)PTR(state, 0x50);
    int32_t* a54 = (int32_t*)PTR(state, 0x54);
    uint32_t* a58 = (uint32_t*)PTR(state, 0x58);
    int32_t  iVar2;
    int32_t  iVar3;
    int32_t  iVar5;
    int32_t  iVar8;
    uint32_t uVar6;
    uint32_t uVar4;

    do {
        iVar2 = I32(arr14[param_2], 0x38);
        if (iVar2 != -1) param_2 = iVar2;
        void* node = arr14[param_2];
        if (I32(node, 4) == I32(state, 0)) {
            iVar3 = I32(node, 0x74);
            if (PTR(state, 0x58) != nullptr) {
                iVar5 = iVar3 * 4;
                iVar5 = a50[iVar3] + a4c[iVar3];
                a54[iVar5] = iVar5;
                iVar5 = iVar5 * 0xc;
                uint8_t* recBase = (uint8_t*)a58 + iVar5;
                I32(recBase, 0) = param_3;
                uVar6 = U32(arr18[param_3], 0) & 0xfff00000;
                if ((uVar6 == 0x20700000) || (uVar6 == 0x20800000) || (uVar6 == 0x11500000)) {
                    I32(recBase, 4) = I32(node, 0x14);
                    I32(recBase, 8) = I32(node, 0x18);
                }
                else {
                    int32_t* list2 = (int32_t*)PTR(arr18[param_3], 0x10);
                    void* nd = arr14[list2[0]];
                    I32(recBase, 4) = I32(nd, 0x14);
                    I32(recBase, 8) = I32(nd, 0x18);
                }
                iVar8 = I32(recBase, 4);
                uVar4 = U32(recBase, 8);
                while (true) {
                    if (iVar8 == I32(node, 0x14)) break;
                    void* child = arr14[iVar8];
                    if ((U8(arr10[I32(child, 4)], 5) & 0x80) != 0) {
                        I32(recBase, 4) = iVar8;
                        U32(recBase, 8) = uVar4;
                        I32(recBase, 0) = I32(child, 0x58);
                        if (U32(node, 0x58) < U32(child, 0x58)) {
                            U32(node, 0x58) = U32(child, 0x58);
                        }
                    }
                    uVar4 = U32(child, 0x18);
                    iVar8 = I32(child, 0x14);
                }
            }
            a4c[iVar3] = a4c[iVar3] + 1;
        }
        param_2 = I32(node, 8);
    } while (param_2 != -1);
}

// Forwards onto FUN_00661b07 with the node's parent id at +0x14.
// 0x661c8a — observed shape: parent-chain forwarder; no-op when parent is -1.
void FUN_00661c8a(void* self, void* state, int32_t param_2, int32_t param_3)
{
    int32_t iVar1 = I32(PTR(PTR(self, 0x14), param_2 * 4), 0x14);
    if (iVar1 != -1) {
        FUN_00661b07(self, state, iVar1, param_3);
    }
}

// Frees words 2..8, 0x0c..0x11 and 0x13..0x16, then zeroes 0x19 words; slots
// 9..0x0b and 0x12 are deliberately not freed.
// 0x661cb0 — observed shape: owned-pointer release and clear.
void FUN_00661cb0(void** param_1)
{
    operator_delete(param_1[2]);
    operator_delete(param_1[3]);
    operator_delete(param_1[4]);
    operator_delete(param_1[5]);
    operator_delete(param_1[6]);
    operator_delete(param_1[7]);
    operator_delete(param_1[8]);
    operator_delete(param_1[0xc]);
    operator_delete(param_1[0xd]);
    operator_delete(param_1[0xe]);
    operator_delete(param_1[0xf]);
    operator_delete(param_1[0x10]);
    operator_delete(param_1[0x11]);
    operator_delete(param_1[0x13]);
    operator_delete(param_1[0x14]);
    operator_delete(param_1[0x15]);
    operator_delete(param_1[0x16]);
    for (int32_t iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 - 1) {
        *param_1 = nullptr;
        param_1 = param_1 + 1;
    }
}

// Selection-sorts param_1 through the permutation array (param_2), keyed by
// node+0x10 with the earlier index winning ties, then copies the permuted
// elements back into param_1.
// 0x661d51 — observed shape: keyed selection sort; returns 0.
uint32_t FUN_00661d51(void* self, int32_t* param_1, int32_t* order, uint32_t param_3, int32_t param_4)
{
    uint32_t local_24[4];
    uint32_t local_14;
    uint32_t local_8;
    uint32_t uVar5;
    void** arr14 = (void**)PTR(self, 0x14);

    if (param_4 != 0) {
        uVar5 = 0;
        if (param_3 != 0) {
            do {
                order[uVar5] = (int32_t)uVar5;
                uVar5 = uVar5 + 1;
            } while (uVar5 < param_3);
        }
        local_14 = 0;
        if (param_3 != 0) {
            do {
                int32_t* piVar1 = order + local_14;
                int32_t iVar3 = *piVar1;
                uint32_t key = U32(arr14[param_1[iVar3]], 0x10);
                local_8 = local_14;
                local_14 = local_14 + 1;
                for (uVar5 = local_14; uVar5 < param_3; uVar5 = uVar5 + 1) {
                    uint32_t k2 = U32(arr14[param_1[order[uVar5]]], 0x10);
                    if ((k2 < key) || ((k2 == key) && (uVar5 < local_8))) {
                        local_8 = uVar5;
                        key = k2;
                    }
                }
                int32_t* piVar2 = order + local_8;
                *piVar1 = *piVar2;
                *piVar2 = iVar3;
            } while (local_14 < param_3);
        }
    }
    uVar5 = 0;
    if (param_3 != 0) {
        do {
            local_24[uVar5] = (uint32_t)param_1[order[uVar5]];
            uVar5 = uVar5 + 1;
        } while (uVar5 < param_3);
        if (param_3 != 0) {
            uint32_t* puVar6 = local_24;
            for (; param_3 != 0; param_3 = param_3 - 1) {
                *param_1 = (int32_t)*puVar6;
                puVar6 = puVar6 + 1;
                param_1 = param_1 + 1;
            }
        }
    }
    return 0;
}

// For the node (and its +0x38 substitute) updates +0x54 min, +0x58 max and
// +0x5c counter; when the node has a next sibling (0x08) the owning type
// entry's +0x28 min, +0x2c max and +0x30 counter are updated too.
// 0x661e32 — observed shape: value propagation along a node chain.
void FUN_00661e32(void* self, int32_t param_1, uint32_t param_2)
{
    while (true) {
        void* iVar2 = PTR(PTR(self, 0x14), param_1 * 4);
        if (I32(iVar2, 0x38) != -1) {
            iVar2 = PTR(PTR(self, 0x14), I32(iVar2, 0x38) * 4);
        }
        void* iVar1 = PTR(PTR(self, 0x10), I32(iVar2, 4) * 4);
        if (param_2 < U32(iVar2, 0x54)) U32(iVar2, 0x54) = param_2;
        if (U32(iVar2, 0x58) < param_2) U32(iVar2, 0x58) = param_2;
        I32(iVar2, 0x5c) = I32(iVar2, 0x5c) + 1;
        if (I32(iVar2, 8) == -1) break;
        if (param_2 < U32(iVar1, 0x28)) U32(iVar1, 0x28) = param_2;
        if (U32(iVar1, 0x2c) < param_2) U32(iVar1, 0x2c) = param_2;
        I32(iVar1, 0x30) = I32(iVar1, 0x30) + 1;
        param_1 = I32(iVar2, 8);
    }
}

// Sets node->0x48, pushes the node onto the type bucket at type+0x20 (index
// node->0x10 + node->0xc*4) fixing the displaced head's +0x50, then propagates
// the value from the node's parent chain via FUN_00661e32.
// 0x661e90 — observed shape: group membership assignment.
void FUN_00661e90(void* self, int32_t param_1, uint32_t param_2)
{
    void* iVar2 = PTR(PTR(self, 0x14), param_1 * 4);
    void* iVar3 = PTR(PTR(self, 0x10), I32(iVar2, 4) * 4);
    U32(iVar2, 0x48) = param_2;
    void* p = PTR(iVar3, 0x20);
    if (p != nullptr) {
        int32_t* piVar1 = (int32_t*)((uint8_t*)p + (I32(iVar2, 0x10) + I32(iVar2, 0xc) * 4) * 4);
        if (*piVar1 != -1) {
            I32(iVar2, 0x4c) = *piVar1;
            U32(PTR(PTR(self, 0x14), *piVar1 * 4), 0x50) = (uint32_t)param_1;
        }
        *piVar1 = param_1;
    }
    if (I32(iVar2, 0x14) != -1) {
        FUN_00661e32(self, I32(iVar2, 0x14), param_2);
    }
}

// Folds child aggregates into the parent (+0x54 min, +0x58 max, +0x5c sum,
// plus the identity fields +0x04..0x10 and +0x48..0x50), then re-points every
// child's +0x54 at the parent value.
// 0x661ef2 — observed shape: aggregate fold; returns 0.
uint32_t FUN_00661ef2(void* self)
{
    uint32_t uVar4 = 0;
    uint32_t uVar5 = 0;
    bool     bVar3 = false;

    if (I32(self, 8) != 0) {
        do {
            void* n = PTR(PTR(self, 0x14), uVar4 * 4);
            if (I32(n, 0x38) != -1) {
                void* m = PTR(PTR(self, 0x14), I32(n, 0x38) * 4);
                U32(n, 4) = U32(m, 4);
                U32(n, 8) = U32(m, 8);
                U32(n, 0xc) = U32(m, 0xc);
                U32(n, 0x10) = U32(m, 0x10);
                U32(n, 0x48) = U32(m, 0x48);
                U32(n, 0x4c) = U32(m, 0x4c);
                U32(n, 0x50) = U32(m, 0x50);
                uVar5 = U32(m, 0x54);
                if (uVar5 == 0xffffffff) {
                    U32(m, 0x54) = U32(n, 0x54);
                    U32(m, 0x58) = U32(n, 0x58);
                    U32(m, 0x5c) = U32(n, 0x5c);
                }
                else {
                    if (U32(n, 0x54) <= uVar5) uVar5 = U32(n, 0x54);
                    U32(n, 0x54) = uVar5;
                    U32(m, 0x54) = uVar5;
                    uVar5 = U32(m, 0x58);
                    if (U32(m, 0x58) <= U32(n, 0x58)) uVar5 = U32(n, 0x58);
                    U32(n, 0x58) = uVar5;
                    U32(m, 0x58) = uVar5;
                    I32(m, 0x5c) = I32(m, 0x5c) + I32(n, 0x5c);
                }
                bVar3 = true;
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < U32(self, 8));
        if (bVar3 && (U32(self, 8) != 0)) {
            uVar4 = 0;
            do {
                void* n = PTR(PTR(self, 0x14), uVar4 * 4);
                int32_t p = I32(n, 0x38);
                if (p != -1) {
                    U32(n, 0x54) = U32(PTR(PTR(self, 0x14), p * 4), 0x54);
                }
                uVar4 = uVar4 + 1;
            } while (uVar4 < U32(self, 8));
        }
    }
    return 0;
}

// Clears per-type/per-node aggregates; sizes each type from node->0x0c + 1 when
// flags4 has bit 1 and not bit 0x40; allocates one block of sum << 4 bytes,
// seeds it with 0xffffffff and gives each type a 16-byte-per-unit slice at
// +0x20. Per group it then runs the sibling (0x661e32) and bucket (0x661e90)
// passes; tag 0x10000000 groups with ctx bit 0xcc&4 clear swap the +0x34 order
// of paired members. Finally type min/max are applied, +0x4c/+0x50 are rebased
// and 0x661ef2 runs when ctx+0xd8 is set.
// 0x661fbd — observed shape: layout and aggregate pass over the three tables.
uint32_t FUN_00661fbd(void* self)
{
    uint32_t  uVar5 = 0;
    uint32_t  uVar6 = 0;
    uint32_t  uVar3 = 0;
    uint32_t  local_8 = 0;
    uint8_t*  local_10 = nullptr;
    int32_t   iVar8 = 0;
    uint32_t* puVar9 = nullptr;
    void**    arr10 = (void**)PTR(self, 0x10);
    void**    arr14 = (void**)PTR(self, 0x14);

    if (I32(self, 4) != 0) {
        do {
            void* e = arr10[uVar5];
            U32(e, 0x28) = 0xffffffff;
            uVar5 = uVar5 + 1;
            U32(e, 0x2c) = 0;
            U32(e, 0x30) = 0;
            U32(e, 0x20) = 0;
        } while (uVar5 < U32(self, 4));
    }
    uVar5 = 0;
    if (I32(self, 8) != 0) {
        do {
            void* n = arr14[uVar5];
            U32(n, 0x34) = uVar5;
            uVar5 = uVar5 + 1;
            U32(n, 0x54) = 0xffffffff;
            U32(n, 0x58) = 0;
            U32(n, 0x5c) = 0;
            U32(n, 0x48) = 0xffffffff;
            U32(n, 0x4c) = 0xffffffff;
            U32(n, 0x50) = 0xffffffff;
        } while (uVar5 < U32(self, 8));
    }
    if (I32(self, 0xdc) != 0) {
        uVar5 = 0;
        if (I32(self, 4) != 0) {
            do {
                U32(arr10[uVar5], 0x10) = 0;
                uVar5 = uVar5 + 1;
            } while (uVar5 < U32(self, 4));
        }
        uVar5 = 0;
        if (I32(self, 8) != 0) {
            do {
                void* n = arr14[uVar5];
                void* t = arr10[I32(n, 4)];
                if (((U32(t, 4) & 0x40) == 0) && ((U32(t, 4) & 2) != 0)) {
                    uVar6 = (uint32_t)(I32(n, 0xc) + 1);
                    if (U32(t, 0x10) < uVar6) U32(t, 0x10) = uVar6;
                }
                uVar5 = uVar5 + 1;
            } while (uVar5 < U32(self, 8));
        }
        {
            int32_t cnt = I32(self, 4);
            uVar5 = 0;
            for (int32_t i = 0; i < cnt; i = i + 1) {
                uVar5 = uVar5 + U32(arr10[i], 0x10);
            }
        }
        local_10 = (uint8_t*)FUN_00533c78(uVar5 << 4);
        if (local_10 == nullptr) return 0x8007000e;
        puVar9 = (uint32_t*)local_10;
        for (iVar8 = (int32_t)((uVar5 & 0xfffffff) << 2); iVar8 != 0; iVar8 = iVar8 - 1) {
            *puVar9 = 0xffffffff;
            puVar9 = puVar9 + 1;
        }
        // observed zero-trip tail of the init loop (memset residue)
        for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 - 1) {
            *(uint8_t*)puVar9 = 0xff;
            puVar9 = (uint32_t*)((uint8_t*)puVar9 + 1);
        }
        iVar8 = 0;
        uVar5 = 0;
        if (I32(self, 4) != 0) {
            do {
                void* t = arr10[uVar5];
                uint32_t off = U32(t, 0x10);
                U32(t, 0x20) = (0u - (uint32_t)(off != 0)) &
                               (uint32_t)(uintptr_t)(local_10 + (std::size_t)iVar8 * 16);
                iVar8 = iVar8 + (int32_t)off;
                uVar5 = uVar5 + 1;
            } while (uVar5 < U32(self, 4));
        }
    }
    local_8 = 0;
    if (I32(self, 0xc) != 0) {
        do {
            uVar5 = 0;
            uint8_t* blk = (uint8_t*)PTR(PTR(self, 0x18), local_8 * 4);
            if ((blk != nullptr) && ((U32(blk, 0) & 0xfff00000) != 0)) {
                uint32_t* list1 = (uint32_t*)PTR(blk, 8);
                uint32_t* list2 = (uint32_t*)PTR(blk, 0x10);
                if (U32(blk, 4) != 0) {
                    do {
                        FUN_00661e32(self, (int32_t)list1[uVar5], local_8);
                        uVar5 = uVar5 + 1;
                    } while (uVar5 < U32(blk, 4));
                }
                uVar5 = 0;
                if (U32(blk, 0xc) != 0) {
                    do {
                        FUN_00661e90(self, (int32_t)list2[uVar5], local_8);
                        uVar5 = uVar5 + 1;
                    } while (uVar5 < U32(blk, 0xc));
                }
                if (((U32(blk, 0) & 0xfff00000) == 0x10000000) &&
                    ((U8(self, 0xcc) & 4) == 0)) {
                    uint32_t local_c = 0;
                    if (U32(blk, 0xc) != 0) {
                        do {
                            void* n1 = arr14[list2[local_c]];
                            void* n2 = arr14[list1[local_c]];
                            uVar6 = U32(arr10[I32(n1, 4)], 4);
                            if (((uVar6 & 0x1020) == 0) && ((uVar6 & 1) != 0) &&
                                (I32(n2, 0x3c) == 0)) {
                                uVar3 = U32(n1, 0x34);
                                U32(n1, 0x34) = U32(n2, 0x34);
                                U32(n2, 0x34) = uVar3;
                            }
                            local_c = local_c + 1;
                        } while (local_c < U32(blk, 0xc));
                    }
                }
            }
            local_8 = local_8 + 1;
        } while (local_8 < U32(self, 0xc));
    }
    uVar5 = 0;
    if (I32(self, 8) != 0) {
        do {
            void* n = arr14[uVar5];
            void* t = arr10[I32(n, 4)];
            uVar6 = U32(t, 0x28);
            if (uVar6 < U32(n, 0x54)) U32(n, 0x54) = uVar6;
            uVar6 = U32(t, 0x2c);
            if (U32(n, 0x58) < uVar6) U32(n, 0x58) = uVar6;
            uVar5 = uVar5 + 1;
        } while (uVar5 < U32(self, 8));
    }
    if (I32(self, 0xdc) != 0) {
        uVar5 = 0;
        if (I32(self, 8) != 0) {
            do {
                void* n = arr14[uVar5];
                if (I32(n, 0x4c) == -1) {
                    U32(n, 0x4c) = 0;
                }
                else {
                    void* m = arr14[I32(n, 0x4c)];
                    uVar6 = U32(m, 0x58);
                    U32(n, 0x4c) = uVar6;
                    uVar3 = U32(m, 0x48);
                    if (uVar6 <= uVar3) U32(n, 0x4c) = uVar3 + 1;
                }
                if (I32(n, 0x50) == -1) {
                    U32(n, 0x50) = 0xffffffff;
                }
                else {
                    void* m = arr14[I32(n, 0x50)];
                    uVar6 = U32(m, 0x54);
                    U32(n, 0x50) = uVar6;
                    uVar3 = U32(m, 0x48);
                    if (uVar3 < uVar6) U32(n, 0x50) = uVar3;
                }
                uVar5 = uVar5 + 1;
            } while (uVar5 < U32(self, 8));
        }
    }
    if (I32(self, 0xd8) != 0) {
        FUN_00661ef2(self);
    }
    operator_delete(local_10);
    return 0;
}

// For the node's group (ctx+0x18[param_2]) when the node's type flags4 has bit
// 1 and param_3 is set, the node's +0x48 id is appended to list3 (+0x14/+0x18)
// and the node is appended to the group owning that id (list4 +0x1c/+0x20).
// Recurses into the node's +0x08 sibling first, then walks +0x14 parents.
// 0x66228a — observed shape: recursive membership count.
void FUN_0066228a(void* self, int32_t param_1, int32_t param_2, int32_t param_3)
{
    void** arr10 = (void**)PTR(self, 0x10);
    void** arr14 = (void**)PTR(self, 0x14);
    void** arr18 = (void**)PTR(self, 0x18);

    while (true) {
        void* iVar1 = arr18[param_2];
        void* iVar2 = arr14[param_1];
        if ((param_3 != 0) && ((U8(arr10[I32(iVar2, 4)], 4) & 2) != 0)) {
            if (I32(iVar1, 0x18) != 0) {
                int32_t* a18 = (int32_t*)PTR(iVar1, 0x18);
                a18[I32(iVar1, 0x14)] = I32(iVar2, 0x48);
            }
            I32(iVar1, 0x14) = I32(iVar1, 0x14) + 1;
            iVar1 = arr18[I32(iVar2, 0x48)];
            if (I32(iVar1, 0x20) != 0) {
                int32_t* a20 = (int32_t*)PTR(iVar1, 0x20);
                a20[I32(iVar1, 0x1c)] = param_2;
            }
            I32(iVar1, 0x1c) = I32(iVar1, 0x1c) + 1;
        }
        if (I32(iVar2, 8) != -1) {
            FUN_0066228a(self, I32(iVar2, 8), param_2, 1);
        }
        param_1 = I32(iVar2, 0x14);
        if (param_1 == -1) break;
        param_3 = 1;
    }
}
