// Reconstruction batch mass_0322 — Sid Meier's Pirates! (2004), PE32 i386
// Addresses 0x66be13..0x6711a3. Pseudocode corpus: Ghidra 12.2.
// Receiver registers (in_ECX) are explicit leading `void* self` parameters.
// Field offsets, constants, call order and conditional structure preserved.
#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---- Helpers referenced by the listed corpus (extern) ----
extern "C" {
void     FUN_00661fbd(void);
void     FUN_0066254f(void);
void     FUN_00662568(void);
void     FUN_006338c7(void);
void     FUN_005f6015(void);
void     FUN_00614343(...);
int32_t  FUN_0065cc50(void* rec = nullptr);
void*    FUN_0065d097(void);
int      FUN_0065cd09(void);
int      FUN_0065f17e(uint32_t a, void* b, void* c);
int      FUN_0065f408(uint32_t a, void* b, void* c, void* d, void* e, void* f);
uint32_t FUN_0065d9d5(uint32_t a, uint32_t b, uint32_t c, double d);
int      FUN_0065da35(uint32_t a, uint32_t b, uint32_t c);
void     FUN_0065e1b9(void* fn, uint32_t* arr, uint32_t n, void* self);
void     FUN_0065e4c1(int a, void* out);
void     FUN_00664e87(uint32_t a, uint32_t b);
void     FUN_00664f08(uint32_t a, uint32_t b);
int      FUN_0065dd82(uint32_t a, uint32_t b, void* self);
int      FUN_0065ddd1(uint32_t a, uint32_t b, void* self);
int      FUN_006627d8(uint32_t a, void* self);
int      FUN_00662977(uint32_t a, uint32_t b, void* self);
uint32_t FUN_006634e9(void);
uint32_t FUN_0065e4f2(void);
uint32_t FUN_00664b28(void);
void*    FUN_00533c78(uint32_t size);
void     operator_delete(void* p);
// defined later in this translation unit
uint32_t FUN_0066be13(void* self);
}

// Record layout used by the whole 0x66xxxx family:
//   +0x00 type/class word; +0x04 capacity/size; +0x08 index array ptr;
//   +0x0c used count; +0x10 node-index array ptr.
struct ReconRec {
    uint32_t  type;
    uint32_t  cap;
    uint32_t* idx;
    uint32_t  used;
    uint32_t* nids;
};

// 0x66be13 — observed shape
// Pass 1 collects nodes flagged 0x100 (and not 0xc00), orders them via
// FUN_0065dd82 and re-points failed merges at self+0x74.  Pass 2 collects
// nodes whose type flags bit 0x40 (or when self+0xdc != 0), orders them via
// FUN_0065ddd1 and merges with FUN_00664f08.
uint32_t FUN_0066be13(void* self) {
    uint8_t*  S     = (uint8_t*)self;
    uint32_t** nodes = *(uint32_t***)(S + 0x14);
    uint32_t** types = *(uint32_t***)(S + 0x10);
    uint32_t result  = 0;
    bool     changed = false;

    FUN_00661fbd();
    uint32_t* buf = (uint32_t*)FUN_00533c78(*(int32_t*)(S + 8) << 2);
    if (buf == nullptr) {
        result = 0x8007000e;
    } else {
        uint32_t i = 0;
        uint32_t count = 0;
        if (*(int32_t*)(S + 8) != 0) {
            do {
                int32_t rec = (int32_t)(uintptr_t)nodes[i];
                *(uint32_t*)((uint8_t*)(uintptr_t)rec + 0x30) = i;
                uint32_t flags = *(uint32_t*)((uint8_t*)types[*(int32_t*)((uint8_t*)(uintptr_t)rec + 4)] + 4);
                if (((flags & 0x100) != 0) && ((flags & 0xc00) == 0)) {
                    buf[count] = i;
                    count++;
                }
                i++;
            } while (i < *(uint32_t*)(S + 8));
        }
        FUN_0065e1b9((void*)(uintptr_t)FUN_0065dd82, buf, count, self);

        uint32_t k = 1;
        bool     inner = false;
        if (1 < count) {
            do {
                changed = inner;
                uint32_t* cur = buf + k;
                int32_t r = FUN_0065dd82(
                    *(uint32_t*)((uint8_t*)nodes[buf[k - 1]] + 0x30), *cur, self);
                if (r == 0) {
                    *(uint32_t*)((uint8_t*)nodes[*cur] + 4) = *(uint32_t*)(S + 0x74);
                    *(uint32_t*)((uint8_t*)nodes[*cur] + 0x30) =
                        *(uint32_t*)((uint8_t*)nodes[buf[k - 1]] + 0x30);
                    changed = true;
                }
                k++;
                inner = changed;
            } while (k < count);
            if (inner) {
                FUN_00662568();
            }
        }

        i = 0;
        count = 0;
        inner = false;
        if (*(int32_t*)(S + 8) != 0) {
            do {
                int32_t  rec  = (int32_t)(uintptr_t)nodes[i];
                uint8_t* rp   = (uint8_t*)(uintptr_t)rec;
                *(uint32_t*)(rp + 0x30) = i;
                int32_t type = *(int32_t*)(rp + 4);
                if ((*(int32_t*)(S + 0x74) != type) &&
                    (((*(uint8_t*)((uint8_t*)types[type] + 4) & 0x40) != 0) ||
                     (*(int32_t*)(S + 0xdc) != 0))) {
                    buf[count] = i;
                    count++;
                }
                i++;
            } while (i < *(uint32_t*)(S + 8));
        }
        FUN_0065e1b9((void*)(uintptr_t)FUN_0065ddd1, buf, count, self);

        uint32_t first = 0;
        if (count != 0) {
            first = buf[0];
        }
        k = 1;
        if (1 < count) {
            do {
                uint32_t cur = buf[k];
                int32_t r = FUN_0065ddd1(first, cur, self);
                if (r == 0) {
                    FUN_00664f08(first, cur);
                    *(uint32_t*)((uint8_t*)nodes[buf[k]] + 4) = *(uint32_t*)(S + 0x74);
                    inner = true;
                } else {
                    first = cur;
                }
                k++;
            } while (k < count);
            if (inner) {
                FUN_00662568();
                changed = true;
            }
        }
        operator_delete(buf);
        result = (uint32_t)!changed;
    }
    return result;
}

// 0x66bfdf — observed shape
// Matrix-edge de-duplication.  For every record with a 1..4 class nibble,
// compares ordered edge pairs (arity 1..4 patterns) and removes duplicates
// via FUN_00664f08, then compacts the record's index/edge arrays.
uint32_t FUN_0066bfdf(void* self) {
    uint8_t*   S     = (uint8_t*)self;
    uint32_t** nodes = *(uint32_t***)(S + 0x14);
    uint32_t** types = *(uint32_t***)(S + 0x10);
    uint32_t** recs  = *(uint32_t***)(S + 0x18);
    bool changed = false;
    uint32_t local_8 = 0;

    FUN_0066254f();
    uint32_t ri = 0;
    if (*(int32_t*)(S + 0xc) != 0) {
        do {
            int32_t iVar12 = -1;
            uint32_t* rec = recs[ri];
            uint32_t cls = rec[0] & 0xf0000000;
            if ((0xfffffff < cls) && (cls < 0x40000001)) {
                uint32_t local_14 = rec[0] & 0xfffff;
                uint32_t arity = rec[1] / local_14;
                int      iVar4 = FUN_0065cd09();
                uint32_t local_1c = local_14;
                uint32_t local_c = 1;
                if (1 < local_14) {
                    int iVar5    = (int)(local_14 * 4);
                    int local_10 = 4;
                    int local_24 = iVar5;
                    do {
                        local_24 += 4;
                        int iVar9 = (int)(uintptr_t)nodes;
                        if (((*(uint16_t*)((uint8_t*)types[*(int32_t*)((uint8_t*)nodes[*(int32_t*)((uint8_t*)(uintptr_t)rec[4] + local_10)] + 4)] + 4) & 0x1020) == 0) &&
                            ((local_8 = 0), local_10 != 0)) {
                            int local_20 = iVar5;
                            do {
                                int iVar10 = *(int32_t*)((uint8_t*)(uintptr_t)rec[4] + local_8 * 4);
                                if ((iVar10 == -1) ||
                                    ((*(uint16_t*)((uint8_t*)types[*(int32_t*)((uint8_t*)nodes[iVar10] + 4)] + 4) & 0x1020) != 0)) {
                                    goto LAB_0066c373;
                                }
                                if (arity == 1) {
                                    int32_t a = *(int32_t*)((uint8_t*)(uintptr_t)rec[2] + local_10);
                                    if (a == -1) {
                                        a = iVar12;
                                    } else {
                                        a = *(int32_t*)((uint8_t*)nodes[a] + 0x30);
                                    }
                                    int32_t b = *(int32_t*)((uint8_t*)(uintptr_t)rec[2] + local_8 * 4);
                                    if (b == -1) {
                                        b = iVar12;
                                    } else {
                                        b = *(int32_t*)((uint8_t*)nodes[b] + 0x30);
                                    }
                                    if (a != b) goto LAB_0066c117;
LAB_0066c38b:
                                    FUN_00664f08(*(uint32_t*)((uint8_t*)(uintptr_t)rec[4] + local_8 * 4),
                                                 *(int32_t*)((uint8_t*)(uintptr_t)rec[4] + local_10));
                                    local_1c = local_1c - 1;
                                    *(uint32_t*)((uint8_t*)(uintptr_t)rec[4] + local_10) = 0xffffffff;
                                    break;
                                }
LAB_0066c117:
                                if (arity == 2) {
                                    uint8_t* base2 = (uint8_t*)(uintptr_t)rec[2];
                                    int32_t a = *(int32_t*)(base2 + local_10);
                                    if (a == -1) {
                                        a = iVar12;
                                    } else {
                                        a = *(int32_t*)((uint8_t*)nodes[a] + 0x30);
                                    }
                                    int32_t b = *(int32_t*)(base2 + local_8 * 4);
                                    int32_t b30;
                                    if (b == -1) {
                                        b30 = iVar12;
                                    } else {
                                        b30 = *(int32_t*)((uint8_t*)nodes[b] + 0x30);
                                    }
                                    if (a == b30) {
                                        int32_t c = *(int32_t*)(base2 + local_24);
                                        if (c == -1) {
                                            a = iVar12;
                                        } else {
                                            a = *(int32_t*)((uint8_t*)nodes[c] + 0x30);
                                        }
                                        int32_t d = *(int32_t*)(base2 + local_20);
                                        if (d == -1) {
                                            b30 = iVar12;
                                        } else {
                                            b30 = *(int32_t*)((uint8_t*)nodes[d] + 0x30);
                                        }
                                        if (a == b30) goto LAB_0066c38b;
                                    }
                                    if (iVar4 != 0) {
                                        int32_t e = *(int32_t*)(base2 + local_10);
                                        if (e == -1) {
                                            a = iVar12;
                                        } else {
                                            a = *(int32_t*)((uint8_t*)nodes[e] + 0x30);
                                        }
                                        int32_t f = *(int32_t*)(base2 + local_20);
                                        if (f == -1) {
                                            b30 = iVar12;
                                        } else {
                                            b30 = *(int32_t*)((uint8_t*)nodes[f] + 0x30);
                                        }
                                        if (a == b30) {
                                            int32_t g = *(int32_t*)(base2 + local_24);
                                            if (g == -1) {
                                                a = iVar12;
                                            } else {
                                                a = *(int32_t*)((uint8_t*)nodes[g] + 0x30);
                                            }
                                            if (b == -1) {
                                                b = iVar12;
                                            } else {
                                                b = *(int32_t*)((uint8_t*)nodes[b] + 0x30);
                                            }
                                            if (a == b) goto LAB_0066c38b;
                                            goto LAB_0066c1ea;
                                        }
                                    }
                                } else {
LAB_0066c1ea:
                                    if (arity == 3) {
                                        uint8_t* base3 = (uint8_t*)(uintptr_t)rec[2];
                                        int32_t a = *(int32_t*)(base3 + local_10);
                                        if (a == -1) {
                                            a = iVar12;
                                        } else {
                                            a = *(int32_t*)((uint8_t*)nodes[a] + 0x30);
                                        }
                                        int32_t b = *(int32_t*)(base3 + local_8 * 4);
                                        if (b == -1) {
                                            b = iVar12;
                                        } else {
                                            b = *(int32_t*)((uint8_t*)nodes[b] + 0x30);
                                        }
                                        if (a == b) {
                                            int32_t c = *(int32_t*)(base3 + local_24);
                                            if (c == -1) {
                                                a = iVar12;
                                            } else {
                                                a = *(int32_t*)((uint8_t*)nodes[c] + 0x30);
                                            }
                                            int32_t d = *(int32_t*)(base3 + local_20);
                                            if (d == -1) {
                                                b = iVar12;
                                            } else {
                                                b = *(int32_t*)((uint8_t*)nodes[d] + 0x30);
                                            }
                                            if (a == b) {
                                                int32_t e = *(int32_t*)(base3 + (local_c + local_14 * 2) * 4);
                                                uint32_t local_38;
                                                if (e == -1) {
                                                    local_38 = 0xffffffff;
                                                } else {
                                                    local_38 = *(int32_t*)((uint8_t*)nodes[e] + 0x30);
                                                }
                                                int32_t f = *(int32_t*)(base3 + (local_14 * 2 + local_8) * 4);
                                                if (f == -1) {
                                                    f = iVar12;
                                                } else {
                                                    f = *(int32_t*)((uint8_t*)nodes[f] + 0x30);
                                                }
                                                if (local_38 == (uint32_t)f) goto LAB_0066c38b;
                                                goto LAB_0066c295;
                                            }
                                        }
                                    } else {
LAB_0066c295:
                                        if (arity == 4) {
                                            uint8_t* base4 = (uint8_t*)(uintptr_t)rec[2];
                                            int32_t a = *(int32_t*)(base4 + local_10);
                                            if (a == -1) {
                                                a = iVar12;
                                            } else {
                                                a = *(int32_t*)((uint8_t*)nodes[a] + 0x30);
                                            }
                                            int32_t b = *(int32_t*)(base4 + local_8 * 4);
                                            if (b == -1) {
                                                b = iVar12;
                                            } else {
                                                b = *(int32_t*)((uint8_t*)nodes[b] + 0x30);
                                            }
                                            if (a == b) {
                                                int32_t c = *(int32_t*)(base4 + local_24);
                                                if (c == -1) {
                                                    a = iVar12;
                                                } else {
                                                    a = *(int32_t*)((uint8_t*)nodes[c] + 0x30);
                                                }
                                                int32_t d = *(int32_t*)(base4 + local_20);
                                                if (d == -1) {
                                                    b = iVar12;
                                                } else {
                                                    b = *(int32_t*)((uint8_t*)nodes[d] + 0x30);
                                                }
                                                if (a == b) {
                                                    int32_t e = *(int32_t*)(base4 + (local_c + local_14 * 2) * 4);
                                                    uint32_t local_38;
                                                    if (e == -1) {
                                                        local_38 = 0xffffffff;
                                                    } else {
                                                        local_38 = *(int32_t*)((uint8_t*)nodes[e] + 0x30);
                                                    }
                                                    int32_t f = *(int32_t*)(base4 + (local_14 * 2 + local_8) * 4);
                                                    if (f == -1) {
                                                        f = iVar12;
                                                    } else {
                                                        f = *(int32_t*)((uint8_t*)nodes[f] + 0x30);
                                                    }
                                                    if (local_38 == (uint32_t)f) {
                                                        int32_t g = *(int32_t*)(base4 + (local_c + local_14 * 3) * 4);
                                                        if (g == -1) {
                                                            local_38 = 0xffffffff;
                                                        } else {
                                                            local_38 = *(int32_t*)((uint8_t*)nodes[g] + 0x30);
                                                        }
                                                        int32_t h = *(int32_t*)(base4 + (local_14 * 3 + local_8) * 4);
                                                        if (h == -1) {
                                                            h = iVar12;
                                                        } else {
                                                            h = *(int32_t*)((uint8_t*)nodes[h] + 0x30);
                                                        }
                                                        if (local_38 == (uint32_t)h) goto LAB_0066c38b;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
LAB_0066c373:
                                local_8 = local_8 + 1;
                                local_20 += 4;
                            } while (local_8 < local_c);
                        }
                        local_c = local_c + 1;
                        local_10 += 4;
                    } while (local_c < local_14);

                    if (local_1c < local_14) {
                        local_c = 0;
                        if (local_14 != 0) {
                            iVar12 = 0;
                            do {
                                int iVar9b = (int)(local_c * 4);
                                int32_t iVar4b = *(int32_t*)((uint8_t*)(uintptr_t)rec[4] + iVar9b);
                                if (iVar4b != -1) {
                                    *(int32_t*)((uint8_t*)(uintptr_t)rec[4] + iVar12) = iVar4b;
                                    if (arity != 0) {
                                        int iVar4c = iVar12;
                                        uint32_t uVar11 = arity;
                                        do {
                                            uint8_t* srcp = (uint8_t*)(uintptr_t)rec[2] + iVar9b;
                                            iVar9b += iVar5;
                                            *(uint32_t*)((uint8_t*)(uintptr_t)rec[2] + iVar4c) = *(uint32_t*)srcp;
                                            iVar4c += iVar5;
                                            uVar11 = uVar11 - 1;
                                        } while (uVar11 != 0);
                                    }
                                    iVar12 = iVar12 + 4;
                                }
                                local_c = local_c + 1;
                            } while (local_c < local_14);
                        }
                        if (1 < arity) {
                            int iVar4d = (int)(arity - 1);
                            int iVar12b = iVar5;
                            int local_24b = (int)(local_1c * 4);
                            do {
                                if (local_1c != 0) {
                                    uint32_t local_38 = local_1c;
                                    int iVar9c = iVar12b;
                                    int iVar10b = local_24b;
                                    do {
                                        *(uint32_t*)((uint8_t*)(uintptr_t)rec[2] + iVar10b) =
                                            *(uint32_t*)((uint8_t*)(uintptr_t)rec[2] + iVar9c);
                                        iVar9c += 4;
                                        iVar10b += 4;
                                        local_38 = local_38 - 1;
                                    } while (local_38 != 0);
                                }
                                iVar12b += iVar5;
                                local_24b = local_24b + (int)(local_1c * 4);
                                iVar4d = iVar4d + -1;
                            } while (iVar4d != 0);
                        }
                        rec[0] = rec[0] ^ ((rec[0] ^ local_1c) & 0xfffff);
                        rec[1] = local_1c * arity;
                        rec[3] = local_1c;
                        changed = true;
                    }
                }
            }
            ri = ri + 1;
        } while (ri < *(uint32_t*)(S + 0xc));
        if (changed) {
            FUN_00662568();
            return 0;
        }
    }
    return 1;
}

// 0x66c4b7 — observed shape
// Builds the list of records whose edges are fully flagged 0x1020, then
// repeatedly folds duplicate edges (FUN_006627d8) until stable.
uint32_t FUN_0066c4b7(void* self, uint32_t param_1) {
    uint8_t*   S     = (uint8_t*)self;
    uint32_t** nodes = *(uint32_t***)(S + 0x14);
    uint32_t** types = *(uint32_t***)(S + 0x10);
    uint32_t** recs  = *(uint32_t***)(S + 0x18);
    bool bVar7 = false;
    uint32_t uVar12;

    uint32_t local_8 = 0;
    uint32_t* buf = (uint32_t*)FUN_00533c78(*(int32_t*)(S + 0xc) << 2);
    if (buf == nullptr) {
        uVar12 = 0x8007000e;
    } else {
        uint32_t i = 0;
        if (*(int32_t*)(S + 0xc) != 0) {
            do {
                uint32_t* rec = recs[i];
                uint32_t cls = rec[0] & 0xfff00000;
                if ((((cls != 0) &&
                      (((param_1 == 0 || rec[9] == 0) && (cls != 0x10f00000)) &&
                       ((cls != 0x20700000 && (cls != 0x11100000)))))) &&
                    (cls != 0x11200000)) &&
                   (((cls != 0x11300000 && (cls != 0x11400000)) &&
                     ((cls != 0x20800000 && ((cls != 0x20900000 && (cls != 0x11500000))))))) {
                    uint32_t n = rec[3];
                    uint32_t k = 0;
                    if (n != 0) {
                        int32_t* p = (int32_t*)(uintptr_t)rec[4];
                        do {
                            if ((*(uint16_t*)((uint8_t*)types[*(int32_t*)((uint8_t*)nodes[*p] + 4)] + 4) & 0x1020) != 0) break;
                            k = k + 1;
                            p = p + 1;
                        } while (k < n);
                    }
                    if (n <= k) {
                        buf[local_8] = i;
                        local_8 = local_8 + 1;
                    }
                }
                i = i + 1;
            } while (i < *(uint32_t*)(S + 0xc));
        }

        while (true) {
            uVar12 = local_8;
            bool bVar13 = false;
            FUN_0066254f();
            FUN_0065e1b9((void*)(uintptr_t)FUN_00662977, buf, local_8, self);
            if (local_8 == 0) break;

            uint32_t k = 1;
            uint32_t rem = local_8;
            uint32_t* slot = buf;
            do {
                uint32_t uVar4 = *slot;
                if (uVar4 != 0xffffffff) {
                    for (uint32_t j = k; j < local_8; j++) {
                        uint32_t uVar5 = buf[j];
                        if (uVar5 != 0xffffffff) {
                            if ((uVar5 <= uVar4) || (FUN_006627d8(uVar5, self) != 0)) break;
                            uint32_t* r4 = recs[uVar4];
                            uint32_t* r5 = recs[uVar5];
                            uint32_t t = 0;
                            if (*(int32_t*)((uint8_t*)r4 + 0xc) != 0) {
                                do {
                                    int byteOff = (int)(t * 4);
                                    t = t + 1;
                                    *(uint32_t*)((uint8_t*)nodes[*(int32_t*)((uint8_t*)(uintptr_t)r5[4] + byteOff)] + 0x30) =
                                        *(uint32_t*)((uint8_t*)(uintptr_t)r4[4] + byteOff);
                                } while (t < *(uint32_t*)((uint8_t*)r4 + 0xc));
                            }
                            buf[j] = 0xffffffff;
                            r5[0] = 0;
                            r5[1] = 0;
                            r5[3] = 0;
                            bVar7 = true;
                            bVar13 = true;
                        }
                    }
                }
                slot = slot + 1;
                k = k + 1;
                rem = rem - 1;
            } while (rem != 0);

            if (!bVar13) break;
            bVar13 = local_8 != 0;
            local_8 = 0;
            uint32_t m = 0;
            if (bVar13) {
                do {
                    uint32_t uVar4b = buf[m];
                    if (uVar4b != 0xffffffff) {
                        uint8_t* rec8 = (uint8_t*)(uintptr_t)recs[uVar4b];
                        uint32_t cnt = *(uint32_t*)(rec8 + 4);
                        uint32_t t = 0;
                        if (cnt != 0) {
                            int32_t* p = *(int32_t**)(rec8 + 8);
                            do {
                                if (*(int32_t*)((uint8_t*)nodes[*p] + 0x30) != *p) break;
                                t = t + 1;
                                p = p + 1;
                            } while (t < cnt);
                        }
                        if (t != cnt) {
                            buf[local_8] = uVar4b;
                            local_8 = local_8 + 1;
                        }
                    }
                    m = m + 1;
                } while (m < uVar12);
            }
            FUN_00662568();
        }

        if (bVar7) {
            FUN_0066be13(self);
        }
        uVar12 = (uint32_t)!bVar7;
        operator_delete(buf);
    }
    return uVar12;
}

// 0x66c73e — observed shape
// Edge-record normalizer: constant-folds arity-2 node pairs for 0x204/0x205
// records, resolves 0x300/0x110 chains, converts 0x300 records to
// 0x100/0x101/0x205 forms, folds 0x105 records into 0x106 targets and finally
// rewrites 0x104 records.  All indices are into self+0x18 record array.
uint32_t FUN_0066c73e(void* self) {
    uint8_t*   S     = (uint8_t*)self;
    uint32_t** nodes = *(uint32_t***)(S + 0x14);
    uint32_t** types = *(uint32_t***)(S + 0x10);
    uint32_t** recs  = *(uint32_t***)(S + 0x18);
    int32_t  local_3c = -1;
    int32_t  local_1c = -1;
    uint32_t* local_14 = nullptr;
    double*   local_10 = nullptr;
    uint32_t  local_24 = 0;
    uint32_t  local_8  = 0;
    double    dVar1, dVar2;
    uint8_t   buf4[4];

    FUN_00661fbd();
    uint32_t uVar6 = 0;
    if (*(int32_t*)(S + 8) != 0) {
        do {
            *(uint32_t*)((uint8_t*)nodes[uVar6] + 0x40) = 0xffffffff;
            uVar6 = uVar6 + 1;
        } while (uVar6 < *(uint32_t*)(S + 8));
    }

    // ---- pass 1: 0x204/0x205 arity-2 constant folding ----
    uint32_t ai = 0;
    if (*(int32_t*)(S + 0xc) != 0) {
        do {
            ReconRec* r = (ReconRec*)recs[ai];
            uint32_t cls = r->type & 0xfff00000;
            if ((cls != 0) &&
                ((r->used == 0) || ((*(uint8_t*)nodes[r->nids[0]]) & 0x40) == 0) &&
                ((cls == 0x20400000) || (cls == 0x20500000)) &&
                (r->used != 0)) {
                uint32_t arity = r->used;
                for (uint32_t ar = 0; ar < arity; ar++) {
                    uint32_t* pair[4];
                    pair[0] = &r->idx[ar];
                    pair[1] = &r->idx[arity + ar];
                    for (uint32_t c = 0; c < 2; c++) {
                        int32_t local_74[4];
                        local_74[0] = (int32_t)(uintptr_t)nodes[*pair[0]];
                        local_74[1] = (int32_t)(uintptr_t)nodes[*pair[1]];
                        if ((*(uint8_t*)((uint8_t*)types[*(int32_t*)((uint8_t*)(uintptr_t)local_74[c] + 4)] + 4) & 2) != 0) {
                            if (*(int32_t*)((uint8_t*)(uintptr_t)local_74[c] + 8) == -1) {
                                ReconRec* other = (ReconRec*)recs[*(int32_t*)((uint8_t*)(uintptr_t)local_74[c] + 0x48)];
                                if (((other->type ^ r->type) & 0xfff00000) == 0) {
                                    uint32_t n = other->used;
                                    uint32_t pos = 0;
                                    if (n != 0) {
                                        uint32_t* pp = other->nids;
                                        do {
                                            if (*pp == *pair[c]) break;
                                            pos = pos + 1;
                                            pp = pp + 1;
                                        } while (pos < n);
                                    }
                                    uint32_t local_30 = 0;
                                    pair[2] = &other->idx[pos];
                                    uint32_t local_38 = 0xffffffff;
                                    pair[3] = &other->idx[n + pos];
                                    local_74[3] = (int32_t)(uintptr_t)nodes[*pair[3]];
                                    local_74[2] = (int32_t)(uintptr_t)nodes[*pair[2]];
                                    if ((*(uint32_t*)((uint8_t*)(uintptr_t)local_74[c] + 0x5c) == 1) &&
                                        (*pair[2] != *pair[3])) {
                                        FUN_0065f17e(*pair[1 - c], &local_38, buf4);
                                        uint32_t t = local_38;
                                        int32_t rr = FUN_0065f17e(*pair[c], &t, buf4);
                                        local_38 = t;
                                        local_30 = (uint32_t)(rr >= 0);
                                    }
                                    uint32_t local_20 = 2;
                                    do {
                                        uint32_t local_34 = 5 - local_20;
                                        uint32_t local_44 =
                                            *(uint32_t*)((uint8_t*)types[*(int32_t*)((uint8_t*)(uintptr_t)local_74[local_20] + 4)] + 4) & 0x100;
                                        if ((local_44 != 0) &&
                                            (*(int32_t*)((uint8_t*)(uintptr_t)local_74[local_20] + 8) == -1) &&
                                            ((*(uint8_t*)((uint8_t*)types[*(int32_t*)((uint8_t*)(uintptr_t)local_74[1 - c] + 4)] + 5) & 1) != 0) &&
                                            (*(int32_t*)((uint8_t*)(uintptr_t)local_74[1 - c] + 8) == -1)) {
                                            dVar1 = 0.0;
                                            if ((r->type & 0xfff00000) == 0x20400000) {
                                                dVar1 = *(double*)((uint8_t*)(uintptr_t)local_74[local_20] + 0x20) +
                                                        *(double*)((uint8_t*)(uintptr_t)local_74[1 - c] + 0x20);
                                            } else if ((r->type & 0xfff00000) == 0x20500000) {
                                                dVar1 = *(double*)((uint8_t*)(uintptr_t)local_74[local_20] + 0x20) *
                                                        *(double*)((uint8_t*)(uintptr_t)local_74[1 - c] + 0x20);
                                            }
                                            *pair[c] = *pair[local_34];
                                            *pair[1 - c] = FUN_0065d9d5(*(uint32_t*)(S + 0x78), 0, 0, dVar1);
LAB_0066ca9f:
                                            *(uint32_t*)((uint8_t*)nodes[r->nids[ar]] + 0x40) = 0xffffffff;
                                            local_8 = 1;
                                            goto LAB_0066cab9;
                                        }
                                        if ((*(uint32_t*)((uint8_t*)(uintptr_t)local_74[c] + 0x5c) == 1) &&
                                            ((*(uint32_t*)((uint8_t*)(uintptr_t)local_74[1 - c] + 0x48) == 0xffffffff) ||
                                             (*(uint32_t*)((uint8_t*)(uintptr_t)local_74[1 - c] + 0x48) <
                                              *(uint32_t*)((uint8_t*)(uintptr_t)local_74[c] + 0x48))) &&
                                            (*(int32_t*)((uint8_t*)(uintptr_t)local_74[1 - c] + 8) == -1)) {
                                            uint32_t local_48;
                                            uint32_t* srcp;
                                            bool doSwap = true;
                                            if (((local_44 == 0) ||
                                                 (*(int32_t*)((uint8_t*)(uintptr_t)local_74[local_20] + 8) != -1)) ||
                                                ((*(uint8_t*)((uint8_t*)types[*(int32_t*)((uint8_t*)(uintptr_t)local_74[1 - c] + 4)] + 5) & 1) != 0)) {
                                                local_48 = local_20;
                                                uint32_t v = *pair[local_20];
                                                if (*pair[local_34] == v) goto LAB_0066c9f5;
                                                if (local_30 == 0) {
                                                    uint32_t t2 = local_38;
                                                    int32_t rr = FUN_0065f17e(v, &t2, buf4);
                                                    local_38 = t2;
                                                    if (rr < 0) {
                                                        doSwap = (*pair[1 - c] == *pair[local_48]);
                                                    }
                                                } else {
                                                    doSwap = (*pair[1 - c] == *pair[local_48]);
                                                }
                                                srcp = doSwap ? pair[local_34] : nullptr;
                                            } else {
                                                srcp = pair[local_20];
                                            }
                                            if (srcp == nullptr) goto LAB_0066c9f5;
                                            uint32_t v = *pair[1 - c];
                                            *pair[1 - c] = *srcp;
                                            *srcp = v;
                                            int32_t ndp = local_74[c];
                                            *(uint32_t*)((uint8_t*)(uintptr_t)ndp + 0x60) = 0;
                                            *(uint32_t*)((uint8_t*)(uintptr_t)ndp + 100) = 0;
                                            *(uint32_t*)((uint8_t*)(uintptr_t)ndp + 0x40) = 0xffffffff;
                                            goto LAB_0066ca9f;
                                        }
LAB_0066c9f5:
                                        local_20 = local_20 + 1;
                                    } while (local_20 < 4);
                                }
                            }
                        }
LAB_0066cab9:
                        c = c + 1;
                    }
                    ar = ar + 1;
                }
            }
            ai = ai + 1;
        } while (ai < *(uint32_t*)(S + 0xc));
        if (local_8 != 0) {
            local_8 = 0;
            local_24 = 1;
            FUN_00661fbd();
        }
    }

    // ---- pass 2: resolve 0x300/0x110 node chains through 0x204/0x205 parents ----
    uint32_t bi = 0;
    if (*(int32_t*)(S + 0xc) != 0) {
        do {
            ReconRec* r = (ReconRec*)recs[bi];
            uint32_t cls = r->type & 0xfff00000;
            if ((cls != 0) &&
                ((r->used == 0) || ((*(uint8_t*)nodes[r->nids[0]]) & 0x40) == 0) &&
                ((cls == 0x30000000) || (cls == 0x11000000)) &&
                (r->used != 0)) {
                for (uint32_t k = 0; k < r->used; k++) {
                    uint32_t* slot = &r->idx[k];
                    uint32_t cur = *slot;
                    uint8_t* nd = (uint8_t*)nodes[cur];
                    uint8_t* ti = (uint8_t*)types[*(uint32_t*)(nd + 4)];
                    while (((ti[4] & 2) != 0) && (*(int32_t*)(nd + 8) == -1)) {
                        uint32_t pos = r->used;
                        if (pos < r->cap) {
                            uint32_t* pp = &r->idx[pos];
                            do {
                                if (cur == *pp) break;
                                pos = pos + 1;
                                pp = pp + 1;
                            } while (pos < r->cap);
                            if (pos < r->cap) break;
                        }
                        ReconRec* pr = (ReconRec*)recs[*(int32_t*)(nd + 0x48)];
                        uint32_t n = pr->used;
                        uint32_t j = 0;
                        if (n != 0) {
                            uint32_t* pp = pr->nids;
                            do {
                                if (*pp == cur) break;
                                j = j + 1;
                                pp = pp + 1;
                            } while (j < n);
                        }
                        if ((pr->type & 0xfff00000) == 0x20400000) {
                            uint32_t a = pr->idx[j];
                            if (a != pr->idx[n + j]) break;
                            cur = a;
                        } else {
                            if ((pr->type & 0xfff00000) != 0x20500000) break;
                            uint32_t a = pr->idx[j];
                            uint32_t b = pr->idx[n + j];
                            uint8_t* na = (uint8_t*)nodes[a];
                            if ((((*(uint8_t*)((uint8_t*)types[*(uint32_t*)(na + 4)] + 5)) & 1) == 0) ||
                                (*(double*)(na + 0x20) <= 0.0)) {
                                uint8_t* nb = (uint8_t*)nodes[b];
                                if ((((*(uint8_t*)((uint8_t*)types[*(uint32_t*)(nb + 4)] + 5)) & 1) == 0) ||
                                    (*(double*)(nb + 0x20) <= 0.0)) break;
                                cur = a;
                            } else {
                                cur = b;
                            }
                        }
                        nd = (uint8_t*)nodes[cur];
                        ti = (uint8_t*)types[*(uint32_t*)(nd + 4)];
                    }
                    if (*slot != cur) {
                        *slot = cur;
                        local_8 = 1;
                    }
                }
            }
            bi = bi + 1;
        } while (bi < *(uint32_t*)(S + 0xc));
    }
    if (local_8 != 0) {
        local_8 = 0;
        local_24 = 1;
        FUN_00661fbd();
    }

    // ---- pass 3: 0x300 record node rewrites through 0x101/0x205 parents ----
    uint32_t ci = 0;
    if (*(int32_t*)(S + 0xc) != 0) {
        do {
            ReconRec* r = (ReconRec*)recs[ci];
            uint32_t cls = r->type & 0xfff00000;
            if ((cls != 0) &&
                ((r->used == 0) || ((*(uint8_t*)nodes[r->nids[0]]) & 0x40) == 0) &&
                (cls == 0x30000000) && (r->used != 0)) {
                for (uint32_t j = 0; j < r->used; j++) {
                    uint32_t* slotj = &r->idx[j];
                    uint8_t* nd = (uint8_t*)nodes[*slotj];
                    if (((*(uint8_t*)((uint8_t*)types[*(uint32_t*)(nd + 4)] + 4) & 2) != 0) &&
                        (*(int32_t*)(nd + 8) == -1)) {
                        ReconRec* pr = (ReconRec*)recs[*(int32_t*)(nd + 0x48)];
                        uint32_t n = pr->used;
                        uint32_t pos = 0;
                        if (n != 0) {
                            uint32_t* pp = pr->nids;
                            do {
                                if (*pp == *slotj) break;
                                pos = pos + 1;
                                pp = pp + 1;
                            } while (pos < n);
                        }
                        uint32_t kind;
                        if ((pr->type & 0xfff00000) == 0x10100000) kind = 1;
                        else if ((pr->type & 0xfff00000) == 0x20500000) kind = 2;
                        else goto LAB_0066d045;
                        if (kind != 0) {
                            uint32_t l38 = pos;
                            uint32_t l34 = pr->used + pos;
                            for (uint32_t t = 0; t < kind; t++) {
                                uint32_t lc = pr->idx[l38];
                                uint8_t* ln = (uint8_t*)nodes[lc];
                                if ((pr->type & 0xfff00000) != 0x20500000 ||
                                    ((*(uint8_t*)((uint8_t*)types[*(uint32_t*)((uint8_t*)nodes[pr->idx[l34]] + 4)] + 5) & 1) != 0 &&
                                     (*(uint32_t*)((uint8_t*)nodes[pr->idx[l34]] + 8) == 0xffffffff) &&
                                     (*(double*)((uint8_t*)nodes[pr->idx[l34]] + 0x20) < 0.0))) {
                                    if (lc == r->idx[j + 2 * r->used]) {
                                        uint32_t l18 = r->idx[r->used + j];
                                        uint8_t* ln2 = (uint8_t*)nodes[l18];
                                        if (((*(uint8_t*)((uint8_t*)types[*(uint32_t*)(ln2 + 4)] + 5) & 1) == 0) ||
                                            (*(uint32_t*)(ln2 + 8) != 0xffffffff) ||
                                            (*(double*)(ln2 + 0x20) != 0.0))
                                            goto LAB_0066ce96;
                                        r->idx[j] = lc;
                                        r->idx[r->used + j] = lc;
                                        r->idx[j + 2 * r->used] = l18;
                                    } else {
LAB_0066ce96:
                                        if (((*(uint8_t*)((uint8_t*)types[*(uint32_t*)(ln + 4)] + 4) & 2) == 0) ||
                                            (*(uint32_t*)(ln + 8) != 0xffffffff))
                                            goto LAB_0066cf9a;
                                        ReconRec* pr2 = (ReconRec*)recs[*(uint32_t*)(ln + 0x48)];
                                        if ((pr2->type & 0xfff00000) != 0x30000000) goto LAB_0066cf9a;
                                        uint32_t p2 = 0;
                                        if (pr2->used != 0) {
                                            uint8_t* pp = (uint8_t*)pr2->nids;
                                            do {
                                                if (*(uint32_t*)pp == lc) break;
                                                p2 = p2 + 1;
                                                pp = pp + 4;
                                            } while (p2 < pr2->used);
                                        }
                                        uint8_t* A1 = (uint8_t*)nodes[pr2->idx[p2]];
                                        uint8_t* A2 = (uint8_t*)nodes[pr2->idx[p2 + 2 * pr2->used]];
                                        uint8_t* A3 = (uint8_t*)nodes[pr2->idx[p2 + pr2->used]];
                                        int cA, cB;
                                        if ((*(uint32_t*)A1 & 8) == 0) {
                                            if (((*(uint8_t*)((uint8_t*)types[*(uint32_t*)(A1 + 4)] + 5) & 1) == 0) ||
                                                (*(uint32_t*)(A1 + 8) != 0xffffffff) ||
                                                (*(double*)(A1 + 0x20) <= 0.0))
                                                goto LAB_0066cf9a;
                                            cA = 1;
                                        } else cA = 0;
                                        if ((*(uint8_t*)A3 & 8) == 0) {
                                            if (((*(uint8_t*)((uint8_t*)types[*(uint32_t*)(A3 + 4)] + 5) & 1) == 0) ||
                                                (*(uint32_t*)(A3 + 8) != 0xffffffff) ||
                                                (*(double*)(A3 + 0x20) <= 0.0))
                                                goto LAB_0066cf9a;
                                            cB = 1;
                                        } else cB = 0;
                                        uint32_t v30 = r->idx[r->used + j];
                                        uint32_t v34 = r->idx[j + 2 * r->used];
                                        r->idx[j] = pr2->idx[p2];
                                        r->idx[r->used + j] = (cA == 0) ? v30 : v34;
                                        r->idx[j + 2 * r->used] = (cB == 0) ? v30 : v34;
                                        (void)A2;
                                    }
                                    local_8 = 1;
                                    break;
                                }
LAB_0066cf9a:
                                l38 += pr->used;
                                l34 -= pr->used;
                            }
                        }
                    }
LAB_0066d045:
                    ;
                }
            }
            ci = ci + 1;
        } while (ci < *(uint32_t*)(S + 0xc));
    }
    if (local_8 != 0) {
        local_8 = 0;
        local_24 = 1;
        FUN_00661fbd();
    }

    // ---- pass 4: 0x105 record folding through 0x106 parents ----
    uint32_t di = 0;
    if (*(int32_t*)(S + 0xc) != 0) {
        do {
            ReconRec* r = (ReconRec*)recs[di];
            uint32_t cls = r->type & 0xfff00000;
            if ((cls != 0) &&
                ((r->used == 0) || ((*(uint8_t*)nodes[r->nids[0]]) & 0x40) == 0) &&
                (cls == 0x10500000)) {
                uint32_t local_30 = 0xffffffff;
                uint32_t local_44 = 0xffffffff;
                uint32_t l18 = 0;
                if (r->cap != 0) {
                    do {
                        uint32_t uVar6b = r->idx[l18];
                        uint8_t* nd = (uint8_t*)nodes[uVar6b];
                        if (((*(uint8_t*)((uint8_t*)types[*(uint32_t*)(nd + 4)] + 4) & 2) != 0) &&
                            (*(int32_t*)(nd + 8) == -1)) {
                            ReconRec* l28 = (ReconRec*)recs[*(int32_t*)(nd + 0x48)];
                            if ((l28->type & 0xfff00000) == 0x20500000) {
                                uint32_t l20 = 0;
                                if (l28->used != 0) {
                                    uint8_t* pp = (uint8_t*)l28->nids;
                                    do {
                                        if (*(uint32_t*)pp == uVar6b) break;
                                        l20 = l20 + 1;
                                        pp = pp + 4;
                                    } while (l20 < l28->used);
                                }
                                uint32_t l2c = 0;
                                uint32_t l34 = 1;
                                do {
                                    uint32_t l50 = l28->idx[l28->used * l2c + l20];
                                    uint8_t* pv14 = (uint8_t*)nodes[l50];
                                    if (((*(uint8_t*)((uint8_t*)types[*(uint32_t*)(pv14 + 4)] + 4) & 2) != 0) &&
                                        (*(uint32_t*)(pv14 + 8) == 0xffffffff)) {
                                        ReconRec* l40 = (ReconRec*)recs[*(uint32_t*)(pv14 + 0x48)];
                                        if ((l40->type & 0xfff00000) == 0x10600000) {
                                            if (*(uint32_t*)(pv14 + 0x5c) == 1) {
                                                uint32_t u6 = *(uint32_t*)pv14;
                                                uint32_t u10 = *(uint32_t*)nodes[r->nids[l18]] | u6;
                                                uint32_t u11 = u10 & 0xe000000;
                                                uint32_t u9 = 0x8000000;
                                                if (((u10 & 0x8000000) != 0) ||
                                                    ((u9 = 0x4000000, (u10 & 0x4000000) != 0)) ||
                                                    ((u9 = 0x2000000, (u10 & 0x2000000) != 0))) {
                                                    u11 = u9;
                                                }
                                                if ((u6 & 0xe000000) != u11) {
                                                    *(uint32_t*)pv14 = (u6 & 0xf1ffffff) | u11;
                                                    local_8 = 1;
                                                }
                                            }
                                            if (((S[0x6c] & 0x40) != 0) && (r->used == 1) &&
                                                ((*(uint8_t*)((uint8_t*)nodes[r->nids[l18]] + 3) & 2) != 0)) {
                                                uint32_t u6b = 0;
                                                if (l40->used != 0) {
                                                    uint8_t* pp = (uint8_t*)l40->nids;
                                                    do {
                                                        if (*(uint32_t*)pp == l50) break;
                                                        pp = pp + 4;
                                                        u6b = u6b + 1;
                                                    } while (u6b < l40->used);
                                                }
                                                local_30 = l40->idx[u6b];
                                                local_44 = l28->idx[l28->used * l34 + l20];
                                            }
                                        }
                                    }
                                    l2c = l2c + 1;
                                    l34 = l34 - 1;
                                } while (l2c < 2);
                            }
                        }
                        l18 = l18 + 1;
                    } while (l18 < r->cap);
                    if (local_30 != 0xffffffff) {
                        int32_t iVar7 = FUN_0065da35(0x50100004, 0xffffffff, 0xffffffff);
                        int32_t iVar20;
                        if ((iVar7 == -1) ||
                            ((iVar20 = FUN_0065da35(0x10000001, 0xffffffff, 0xffffffff)) == -1)) {
                            return 0x8007000e;
                        }
                        ReconRec* rec7r = (ReconRec*)recs[iVar7];
                        uint8_t*  rec20 = (uint8_t*)recs[iVar20];
                        FUN_0065cc50();
                        FUN_0065cc50();
                        rec7r->idx[0] = local_30;
                        rec7r->idx[1] = local_30;
                        rec7r->idx[2] = local_44;
                        rec7r->idx[3] = local_44;
                        uint32_t off = 0;
                        do {
                            uint32_t v = FUN_0065d9d5(*(uint32_t*)(S + 0x88), 0, 0, 0.0);
                            *(uint32_t*)((uint8_t*)rec7r->nids + off) = v;
                            if (*(uint32_t*)((uint8_t*)rec7r->nids + off) == 0xffffffff) {
                                return 0x8007000e;
                            }
                            uint32_t newIdx = *(uint32_t*)((uint8_t*)rec7r->nids + off);
                            *(uint32_t*)((uint8_t*)nodes[newIdx] + 0x14) =
                                *(uint32_t*)((uint8_t*)nodes[r->nids[0]] + 0x14);
                            *(uint32_t*)((uint8_t*)nodes[newIdx] + 0x18) =
                                *(uint32_t*)((uint8_t*)nodes[r->nids[0]] + 0x18);
                            uint8_t* nv = (uint8_t*)nodes[newIdx];
                            *(uint32_t*)nv = *(uint32_t*)nv | (*(uint32_t*)nodes[r->nids[0]] & 0xe000000);
                            off = off + 4;
                        } while (off < 0x10);
                        *(uint32_t*)(uintptr_t)(*(uint32_t*)(rec20 + 8)) =
                            *(uint32_t*)((uint8_t*)rec7r->nids + 8);
                        *(uint32_t*)(uintptr_t)(*(uint32_t*)(rec20 + 0x10)) = r->nids[0];
                        FUN_00614343();
                        *(int32_t*)(S + 0xc) = *(int32_t*)(S + 0xc) + -1;
                        int32_t pd = *(int32_t*)(S + 0xc);
                        while (pd = pd - 1, (int32_t)di < pd) {
                            uint32_t* dst = (uint32_t*)((uint8_t*)recs + pd * 4);
                            *dst = dst[-1];
                        }
                        *(uint32_t*)((uint8_t*)recs + di * 4) = (uint32_t)(uintptr_t)rec7r;
                        *(uint32_t*)((uint8_t*)recs + 4 + di * 4) = (uint32_t)(uintptr_t)rec20;
                        FUN_00661fbd();
                        local_8 = 1;
                    }
                }
            }
            di = di + 1;
        } while (di < *(uint32_t*)(S + 0xc));
    }
    if (local_8 != 0) {
        local_8 = 0;
        local_24 = 1;
        FUN_00661fbd();
    }

    // ---- pass 5: 0x104 record node rewrites through 0x204 parents ----
    uint32_t ei = 0;
    if (*(int32_t*)(S + 0xc) != 0) {
        do {
            ReconRec* r = (ReconRec*)recs[ei];
            uint32_t cls = r->type & 0xfff00000;
            if ((cls != 0) &&
                ((r->used == 0) || ((*(uint8_t*)nodes[r->nids[0]]) & 0x40) == 0) &&
                (cls == 0x10400000) && (r->cap != 0)) {
                for (uint32_t k = 0; k < r->cap; k++) {
                    uint32_t* l50 = &r->idx[k];
                    uint8_t* nd = (uint8_t*)nodes[*l50];
                    if (((*(uint8_t*)((uint8_t*)types[*(uint32_t*)(nd + 4)] + 4) & 2) != 0) &&
                        (*(int32_t*)(nd + 8) == -1)) {
                        ReconRec* pr = (ReconRec*)recs[*(int32_t*)(nd + 0x48)];
                        if ((pr->type & 0xfff00000) == 0x20400000) {
                            uint32_t l20 = 0;
                            if (pr->used != 0) {
                                uint8_t* pp = (uint8_t*)pr->nids;
                                do {
                                    if (*(uint32_t*)pp == *l50) break;
                                    l20 = l20 + 1;
                                    pp = pp + 4;
                                } while (l20 < pr->used);
                            }
                            uint32_t l2c = 0;
                            uint32_t* pi = &pr->idx[l20];
                            do {
                                uint8_t* pb = (uint8_t*)nodes[*pi];
                                if (((*(uint8_t*)((uint8_t*)types[*(uint32_t*)(pb + 4)] + 5) & 1) != 0) &&
                                    ((*(uint8_t*)pb & 2) != 0) &&
                                    (*(int32_t*)(pb + 8) == -1)) {
                                    local_8 = 1;
                                    *l50 = pr->idx[(1 - l2c) * pr->used + l20];
                                    break;
                                }
                                l2c = l2c + 1;
                                pi = pi + pr->used;
                            } while (l2c < 2);
                        }
                    }
                }
            }
            ei = ei + 1;
        } while (ei < *(uint32_t*)(S + 0xc));
    }

    // ---- tail: rebuild 0x204/0x205 records from node weights ----
    uVar6 = 0;
    if ((local_8 != 0) || (local_24 != 0)) goto LAB_0066df6d;
    {
        uint32_t local_2c = *(uint32_t*)(S + 0xc);
        local_24 = 0;
        if (local_2c == 0) {
LAB_0066df3c:
            uVar6 = FUN_006634e9();
            if (((int32_t)uVar6 < 0) || ((uVar6 = FUN_0065e4f2()), (int32_t)uVar6 < 0) ||
                ((uVar6 = FUN_00664b28()), (int32_t)uVar6 < 0)) {
                goto LAB_0066df6d;
            }
        } else {
            do {
                local_2c = local_2c - 1;
                ReconRec* r = (ReconRec*)recs[local_2c];
                uint32_t arity = r->used;
                uint32_t local_34 = arity;
                if ((arity == 0) ||
                    ((*(uint8_t*)nodes[r->nids[0]] & 0x40) == 0)) {
                    if (((r->type & 0xfff00000) == 0x20400000) ||
                        ((r->type & 0xfff00000) == 0x20500000)) {
                        if (arity > local_24) {
                            local_24 = arity;
                            if (arity < 17) local_24 = 16;
                            operator_delete(local_14);
                            local_14 = (uint32_t*)FUN_00533c78((int)local_24 << 2);
                            if (local_14 != nullptr) {
                                operator_delete(local_10);
                                local_10 = (double*)FUN_00533c78();
                                if (local_10 != nullptr) goto LAB_0066d62e;
                            }
                            goto LAB_0066df86;
                        }
LAB_0066d62e:
                        {
                            uint32_t l18 = 0;
                            if (arity != 0) {
                                uint32_t* l28p = local_14;
                                double*   l38p = local_10;
                                do {
                                    *l28p = 0xffffffff;
                                    *l38p = 1.0;
                                    int32_t rr = FUN_0065f17e(r->nids[l18], l28p, l38p);
                                    if ((rr < 0) || (*l28p == r->nids[l18])) break;
                                    l18 = l18 + 1;
                                    l38p = l38p + 1;
                                    l28p = l28p + 1;
                                } while (l18 < arity);
                            }
                            if (l18 != arity) goto LAB_0066d9c9;

                            uint32_t pdVar17 = 0;
                            uint32_t local_40 = 1;
                            uint32_t local_44 = 1;
                            if (arity != 0) {
                                do {
                                    if ((pdVar17 != 0) && (local_10[pdVar17] != local_10[pdVar17 - 1])) {
                                        local_44 = 0;
                                    }
                                    if ((local_10[pdVar17] < -1.0) || (1.0 < local_10[pdVar17])) {
                                        local_40 = 0;
                                    }
                                    pdVar17 = pdVar17 + 1;
                                } while (pdVar17 < arity);
                                if (local_44 != 0) goto LAB_0066d6eb;
                            } else {
LAB_0066d6eb:
                                if (local_10[0] == 2.0) {
                                    uint32_t nv = (arity & 0xfffff) | 0x20400000;
                                    if (r->type != nv) {
                                        r->type = nv;
                                        uint32_t need = arity * 2;
                                        local_8 = 1;
                                        if (r->cap < need) {
                                            uint32_t* np = (uint32_t*)FUN_0065d097();
                                            r->idx = np;
                                            if (np == nullptr) goto LAB_0066df86;
                                            r->cap = need;
                                            for (uint32_t z = need; z != 0; z--) {
                                                *np = 0xffffffff;
                                                np = np + 1;
                                            }
                                        }
                                    }
                                    uint32_t l28i = 0;
                                    if (arity != 0) {
                                        uint32_t off = arity * 4;
                                        do {
                                            uint32_t v = local_14[l28i];
                                            if (r->idx[l28i] != v) {
                                                r->idx[l28i] = v;
                                                local_8 = 1;
                                            }
                                            v = local_14[l28i];
                                            if (*(uint32_t*)((uint8_t*)r->idx + off) != v) {
                                                *(uint32_t*)((uint8_t*)r->idx + off) = v;
                                                local_8 = 1;
                                            }
                                            l28i = l28i + 1;
                                            off = off + 4;
                                        } while (l28i < arity);
                                    }
                                    goto LAB_0066d9c9;
                                }
                                if (local_10[0] == 1.0) {
                                    uint32_t l28i = 0;
                                    r->type = (arity & 0xfffff) | 0x10000000;
                                    r->cap = arity;
                                    if (arity != 0) {
                                        do {
                                            uint32_t next = l28i + 1;
                                            r->idx[l28i] = local_14[l28i];
                                            l28i = next;
                                        } while (next < arity);
                                    }
                                } else {
                                    if (local_10[0] != 0.0) {
                                        if (local_10[0] == -1.0) {
                                            uint32_t nv = (arity & 0xfffff) | 0x10100000;
                                            if (r->type != nv) {
                                                r->type = nv;
                                                r->cap = arity;
                                                local_8 = 1;
                                            }
                                            uint32_t l28i = 0;
                                            if (arity != 0) {
                                                do {
                                                    uint32_t v = local_14[l28i];
                                                    if (r->idx[l28i] != v) {
                                                        r->idx[l28i] = v;
                                                        local_8 = 1;
                                                    }
                                                    l28i = l28i + 1;
                                                } while (l28i < arity);
                                            }
                                            goto LAB_0066d9c9;
                                        }
                                        goto LAB_0066d8b3;
                                    }
                                    r->type = (arity & 0xfffff) | 0x10000000;
                                    r->cap = arity;
                                    if ((local_1c == -1) &&
                                        ((local_1c = (int32_t)FUN_0065d9d5(*(uint32_t*)(S + 0x78), 0, 0, 0.0)), local_1c == -1)) {
                                        goto LAB_0066df86;
                                    }
                                    pdVar17 = 0;
                                    if (arity != 0) {
                                        do {
                                            r->idx[pdVar17] = (uint32_t)local_1c;
                                            pdVar17 = pdVar17 + 1;
                                        } while (pdVar17 < arity);
                                    }
                                }
                                local_8 = 1;
                            }
LAB_0066d8b3:
                            if (((*(uint8_t*)(S + 0x6e) & 0x10) == 0) || (local_40 != 0)) {
                                uint32_t nv = (arity & 0xfffff) | 0x20500000;
                                if (r->type != nv) {
                                    r->type = nv;
                                    uint32_t need = arity * 2;
                                    local_8 = 1;
                                    if (r->cap < need) {
                                        uint32_t* np = (uint32_t*)FUN_0065d097();
                                        r->idx = np;
                                        if (np == nullptr) goto LAB_0066df86;
                                        r->cap = need;
                                        for (uint32_t z = need; z != 0; z--) {
                                            *np = 0xffffffff;
                                            np = np + 1;
                                        }
                                    }
                                }
                                uint32_t l18b = 0;
                                if (arity != 0) {
                                    uint32_t off = arity * 4;
                                    do {
                                        uint32_t v = local_14[l18b];
                                        if (r->idx[l18b] != v) {
                                            r->idx[l18b] = v;
                                            local_8 = 1;
                                        }
                                        uint32_t nid = *(uint32_t*)((uint8_t*)r->idx + off);
                                        uint8_t* iVar7p = nullptr;
                                        if (nid != 0xffffffff) {
                                            iVar7p = (uint8_t*)nodes[nid];
                                        }
                                        if ((iVar7p == nullptr) ||
                                            ((*(uint8_t*)((uint8_t*)types[*(uint32_t*)(iVar7p + 4)] + 5) & 1) == 0) ||
                                            (*(int32_t*)(iVar7p + 8) != -1) ||
                                            (*(double*)(iVar7p + 0x20) != local_10[l18b])) {
                                            uint32_t vv = FUN_0065d9d5(*(uint32_t*)(S + 0x78), 0, 0, local_10[l18b]);
                                            *(uint32_t*)((uint8_t*)r->idx + off) = vv;
                                            if (*(uint32_t*)((uint8_t*)r->idx + off) == 0xffffffff) {
                                                goto LAB_0066df86;
                                            }
                                            local_8 = 1;
                                        }
                                        l18b = l18b + 1;
                                        off = off + 4;
                                    } while (l18b < arity);
                                }
                            }
LAB_0066d9c9:
                            if ((r->type & 0xfff00000) == 0x20500000) {
                                uint32_t n = r->used;
                                uint32_t pdVar16b = 0;
                                uint32_t l28v = 0;
                                uint32_t l38v = 0;
                                uint8_t* reachNode = nullptr;
                                if (n != 0) {
                                    while (true) {
                                        uint32_t l18v = 0xffffffff, l20v = 0xffffffff;
                                        uint32_t l34v = 0xffffffff, l30v = 0xffffffff;
                                        uint32_t* l14p = local_14 + pdVar16b;
                                        *l14p = 0xffffffff;
                                        int32_t rr = FUN_0065f408(r->nids[pdVar16b], l14p, &l18v, &l20v, &l34v, &l30v);
                                        if (rr < 0) break;
                                        if ((l18v != 0xffffffff) && (l20v != 0xffffffff)) {
                                            if (*(double*)((uint8_t*)nodes[l18v] + 0x20) <
                                                *(double*)((uint8_t*)nodes[l20v] + 0x20)) {
                                                l18v = 0xffffffff;
                                            } else {
                                                l20v = 0xffffffff;
                                            }
                                        }
                                        uint32_t pdVar15 = 0;
                                        uint32_t pdVar17b = 0;
                                        if (l30v == 0xffffffff) {
LAB_0066daa0:
                                            if ((l34v == 0xffffffff) && (l18v != 0xffffffff)) {
                                                reachNode = (uint8_t*)nodes[l18v];
                                                pdVar17b = 1;
                                                goto LAB_0066db12;
                                            }
                                            if (((l30v != 0xffffffff) || (l34v != 0xffffffff)) ||
                                                (l20v == 0xffffffff)) goto LAB_0066dadf;
                                            local_10[pdVar16b] = *(double*)((uint8_t*)nodes[l20v] + 0x20);
                                            pdVar15 = 0x20300000;
                                            pdVar17b = 0;
                                        } else {
                                            if (l34v != 0xffffffff) {
                                                dVar1 = *(double*)((uint8_t*)nodes[l30v] + 0x20);
                                                dVar2 = *(double*)((uint8_t*)nodes[l34v] + 0x20);
                                                if (((dVar1 != dVar1) || (dVar2 != dVar2)) ||
                                                    (dVar1 < dVar2) == (dVar1 == dVar2)) {
                                                    l30v = 0xffffffff;
                                                } else {
                                                    l34v = 0xffffffff;
                                                }
                                            }
                                            if (l30v == 0xffffffff) goto LAB_0066daa0;
LAB_0066dadf:
                                            if ((l18v != 0xffffffff) || (l20v != 0xffffffff)) break;
                                            if (l34v == 0xffffffff) {
                                                if (l30v == 0xffffffff) break;
                                                reachNode = (uint8_t*)nodes[l30v];
                                                pdVar17b = 0;
LAB_0066db12:
                                                local_10[pdVar16b] = *(double*)(reachNode + 0x20);
                                                pdVar15 = 0x20200000;
                                            } else {
                                                local_10[pdVar16b] = *(double*)((uint8_t*)nodes[l34v] + 0x20);
                                                pdVar15 = 0x20300000;
                                                pdVar17b = 1;
                                            }
                                        }
                                        if (pdVar16b == 0) {
                                            l38v = pdVar17b;
                                            l28v = pdVar15;
                                        } else if ((pdVar15 != l28v) || (pdVar17b != l38v)) {
                                            break;
                                        }
                                        pdVar16b = pdVar16b + 1;
                                        if (n <= pdVar16b) break;
                                    }
                                }
                                if (pdVar16b == n) {
                                    if ((*(uint8_t*)(S + 0x6c) & 0x80) != 0) {
                                        uint32_t u6 = n & 0xfffff;
                                        uint32_t l44 = FUN_0065da35(u6 | 0x10100000, n, n);
                                        uint32_t l50 = FUN_0065da35(u6 | 0x20400000, n * 2, n);
                                        int32_t  i7 = FUN_0065da35(u6 | 0x30000000, n * 3, n);
                                        if (((l44 != 0xffffffff) && (l50 != 0xffffffff)) && (i7 != -1)) {
                                            ReconRec* l20r = (ReconRec*)recs[l44];
                                            ReconRec* l18r = (ReconRec*)recs[l50];
                                            ReconRec* l8r  = (ReconRec*)recs[i7];
                                            FUN_0065cc50();
                                            FUN_0065cc50();
                                            FUN_0065cc50();
                                            bool b21 = (l38v == 0);
                                            l38v = 0;
                                            if (b21) {
                                                for (uint32_t idx = 0; idx < n; idx++) {
                                                    uint32_t v = FUN_0065d9d5(*(uint32_t*)(S + 0x78), 0, 0, local_10[idx]);
                                                    l20r->idx[idx] = v;
                                                    l18r->idx[idx] = local_14[idx];
                                                    if (l20r->idx[idx] == 0xffffffff) goto LAB_0066df86;
                                                }
                                            } else {
                                                for (uint32_t idx = 0; idx < n; idx++) {
                                                    l20r->idx[idx] = local_14[idx];
                                                    uint32_t v = FUN_0065d9d5(*(uint32_t*)(S + 0x78), 0, 0, local_10[idx]);
                                                    l18r->idx[idx] = v;
                                                    if (l18r->idx[idx] == 0xffffffff) goto LAB_0066df86;
                                                }
                                            }
                                            if (((local_3c != -1) ||
                                                 ((local_3c = (int32_t)FUN_0065d9d5(*(uint32_t*)(S + 0x78), 0, 0, 1.0)), local_3c != -1)) &&
                                                ((local_1c != -1) ||
                                                 ((local_1c = (int32_t)FUN_0065d9d5(*(uint32_t*)(S + 0x78), 0, 0, 0.0)), local_1c != -1))) {
                                                if (l28v == 0x20300000) {
                                                    for (uint32_t idx = 0; idx < n; idx++) {
                                                        l8r->idx[idx] = (uint32_t)local_3c;
                                                        l8r->idx[2 * idx] = (uint32_t)local_1c;
                                                    }
                                                } else {
                                                    for (uint32_t idx = 0; idx < n; idx++) {
                                                        l8r->idx[idx] = (uint32_t)local_1c;
                                                        l8r->idx[2 * idx] = (uint32_t)local_3c;
                                                    }
                                                }
                                                for (uint32_t idx = 0; idx < n; idx++) {
                                                    uint32_t v1 = FUN_0065d9d5(*(uint32_t*)(S + 0x88), 0, 0, 0.0);
                                                    l20r->nids[idx] = v1;
                                                    uint32_t v2 = FUN_0065d9d5(*(uint32_t*)(S + 0x88), 0, 0, 0.0);
                                                    l18r->nids[idx] = v2;
                                                    l8r->nids[idx] = r->nids[idx];
                                                    if ((l20r->nids[idx] == 0xffffffff) ||
                                                        (l18r->nids[idx] == 0xffffffff)) {
                                                        goto LAB_0066df86;
                                                    }
                                                    l18r->idx[2 * idx] = l20r->nids[idx];
                                                    l8r->idx[idx] = l18r->nids[idx];
                                                }
                                                uint32_t cnt3 = *(uint32_t*)(S + 0xc) - 3;
                                                while (local_2c < cnt3) {
                                                    cnt3 = cnt3 - 1;
                                                    *(uint32_t*)((uint8_t*)recs + 0xc + cnt3 * 4) =
                                                        *(uint32_t*)((uint8_t*)recs + cnt3 * 4);
                                                }
                                                recs[local_2c + 1] = (uint32_t)(uintptr_t)l20r;
                                                recs[local_2c + 2] = (uint32_t)(uintptr_t)l18r;
                                                recs[local_2c + 3] = (uint32_t)(uintptr_t)l8r;
                                                r->type = 0;
                                                goto LAB_0066df25;
                                            }
                                        }
LAB_0066df86:
                                        uVar6 = 0x8007000e;
                                        goto LAB_0066df6d;
                                    }
                                    r->type = ((l28v ^ n) & 0xfffff) ^ l28v;
                                    for (uint32_t idx = 0; idx < n; idx++) {
                                        uint32_t base = (l38v != 0) ? 0 : n;
                                        r->idx[base + idx] = local_14[idx];
                                        uint32_t v = FUN_0065d9d5(*(uint32_t*)(S + 0x78), 0, 0, local_10[idx]);
                                        r->idx[base + idx] = v;
                                        if (r->idx[base + idx] == 0xffffffff) goto LAB_0066df86;
                                    }
LAB_0066df25:
                                    local_8 = 1;
                                }
                            }
                        }
                    }
                }
            } while (local_2c != 0);
            if (local_8 == 0) goto LAB_0066df3c;
        }
        uVar6 = (uint32_t)(local_8 == 0);
    }
LAB_0066df6d:
    operator_delete(local_14);
    operator_delete(local_10);
    return uVar6;
}

// 0x66df8d — observed shape
// Rebuilds node field +0x30/+0x40 snapshots, propagates 0x14/0x18 through
// record groups, then reorders records whose first node's +0x48 changed.
uint32_t FUN_0066df8d(void* self) {
    uint8_t*   S     = (uint8_t*)self;
    uint32_t** nodes = *(uint32_t***)(S + 0x14);
    uint32_t** types = *(uint32_t***)(S + 0x10);
    uint32_t** recs  = *(uint32_t***)(S + 0x18);
    bool bVar4 = false;
    uint32_t uVar8 = 0;

    if (*(int32_t*)(S + 8) != 0) {
        do {
            uint8_t* nd = (uint8_t*)nodes[uVar8];
            uint8_t* ti = (uint8_t*)types[*(uint32_t*)(nd + 4)];
            *(uint32_t*)(nd + 0x30) = *(uint32_t*)(nd + 0x14);
            *(uint32_t*)(nd + 0x40) = *(uint32_t*)(nd + 0x18);
            uint32_t flags = *(uint32_t*)(ti + 4);
            if ((flags & 0x10) == 0) {
                if ((flags & 0x11028) == 0) {
                    *(uint32_t*)(nd + 0x18) = 0;
                    *(uint32_t*)(nd + 0x14) = 0xffffffff;
                }
            } else {
                *(uint32_t*)(nd + 0x18) = 1;
                *(uint32_t*)(nd + 0x14) = 0xffffffff;
            }
            uVar8 = uVar8 + 1;
        } while (uVar8 < *(uint32_t*)(S + 8));
    }

    uint32_t recIdx = *(uint32_t*)(S + 0xc);
    while (recIdx != 0) {
        recIdx = recIdx - 1;
        ReconRec* r = (ReconRec*)recs[recIdx];
        if ((r->type & 0xfff00000) != 0) {
            uVar8 = 1;
            if (1 < r->used) {
                do {
                    FUN_00664e87((uint32_t)(uintptr_t)nodes[r->nids[0]],
                                 (uint32_t)(uintptr_t)nodes[r->nids[uVar8]]);
                    uVar8 = uVar8 + 1;
                } while (uVar8 < r->used);
            }
            uint32_t li = 1;
            if (1 < r->used) {
                do {
                    uint32_t next = li + 1;
                    *(uint32_t*)((uint8_t*)nodes[r->nids[li]] + 0x14) =
                        *(uint32_t*)((uint8_t*)nodes[r->nids[0]] + 0x14);
                    *(uint32_t*)((uint8_t*)nodes[r->nids[li]] + 0x18) =
                        *(uint32_t*)((uint8_t*)nodes[r->nids[0]] + 0x18);
                    li = next;
                } while ((int32_t)next < (int32_t)r->used);
            }
            uint32_t u8 = r->type;
            uint32_t cls = u8 & 0xfff00000;
            if (((cls == 0x20700000) || (cls == 0x20800000)) || (cls == 0x11500000)) {
                uint32_t lc = 0;
                if (r->used != 0) {
                    do {
                        uint32_t nid = r->nids[lc];
                        uint32_t mid = *(uint32_t*)((uint8_t*)nodes[r->idx[lc]] + 0x14);
                        *(uint32_t*)((uint8_t*)nodes[nid] + 0x14) =
                            *(uint32_t*)((uint8_t*)nodes[mid] + 0x14);
                        *(uint32_t*)((uint8_t*)nodes[nid] + 0x18) =
                            *(uint32_t*)((uint8_t*)nodes[mid] + 0x18);
                        lc = lc + 1;
                    } while (lc < r->used);
                }
            } else if (cls == 0x11200000) {
                uint32_t cnt = r->cap / (u8 & 0xfffff);
                uint32_t l8 = 0;
                if (r->used != 0) {
                    do {
                        uint32_t lc = 0;
                        if (cnt != 0) {
                            do {
                                for (int32_t iv = (int32_t)r->idx[r->used * lc + l8];
                                     iv != -1;
                                     iv = *(int32_t*)((uint8_t*)nodes[iv] + 8)) {
                                    uint32_t mid = *(uint32_t*)((uint8_t*)nodes[r->nids[l8]] + 0x14);
                                    FUN_00664e87((uint32_t)(uintptr_t)nodes[iv],
                                                 (uint32_t)(uintptr_t)nodes[mid]);
                                }
                                lc = lc + 1;
                            } while (lc < cnt);
                        }
                        l8 = l8 + 1;
                    } while (l8 < r->used);
                }
            } else if (((u8 & 0xf0000000) < 0x10000000) || (0x40000000 < (u8 & 0xf0000000))) {
                if (r->used == 0) {
                    uVar8 = 0;
                    if (r->cap != 0) {
                        do {
                            *(uint32_t*)((uint8_t*)nodes[r->idx[uVar8]] + 0x14) = 0xffffffff;
                            uint32_t off = uVar8 * 4;
                            uVar8 = uVar8 + 1;
                            *(uint32_t*)((uint8_t*)nodes[r->idx[off / 4]] + 0x18) = 1;
                        } while (uVar8 < r->cap);
                    }
                } else {
                    uint32_t lc = 0;
                    if (r->cap != 0) {
                        do {
                            for (int32_t iv = (int32_t)r->idx[lc];
                                 iv != -1;
                                 iv = *(int32_t*)((uint8_t*)nodes[iv] + 8)) {
                                FUN_00664e87((uint32_t)(uintptr_t)nodes[iv],
                                             (uint32_t)(uintptr_t)nodes[r->nids[0]]);
                            }
                            lc = lc + 1;
                        } while (lc < r->cap);
                    }
                }
            } else {
                uint32_t cnt = r->cap / (u8 & 0xfffff);
                uint32_t l8 = 0;
                if (r->used != 0) {
                    do {
                        uint32_t lc = 0;
                        if (cnt != 0) {
                            do {
                                for (int32_t iv = (int32_t)r->idx[r->used * lc + l8];
                                     iv != -1;
                                     iv = *(int32_t*)((uint8_t*)nodes[iv] + 8)) {
                                    FUN_00664e87((uint32_t)(uintptr_t)nodes[iv],
                                                 (uint32_t)(uintptr_t)nodes[r->nids[l8]]);
                                }
                                lc = lc + 1;
                            } while (lc < cnt);
                        }
                        l8 = l8 + 1;
                    } while (l8 < r->used);
                }
            }
        }
    }

    FUN_005f6015();
    uint32_t lc2 = 0;
    if (*(int32_t*)(S + 0xc) != 0) {
        do {
            ReconRec* r = (ReconRec*)recs[lc2];
            uint32_t cls = r->type & 0xfff00000;
            if ((((cls != 0) && (cls != 0x10f00000)) &&
                 ((cls != 0x20700000 &&
                   (((cls != 0x11100000) && (cls != 0x11200000)) && (cls != 0x11300000)) &&
                   ((cls != 0x11400000) && (cls != 0x20800000)))) && (cls != 0x20900000)) &&
                (cls != 0x11500000)) {
                uint8_t* nd0 = (uint8_t*)nodes[r->nids[0]];
                if ((*(uint8_t*)((uint8_t*)types[*(uint32_t*)(nd0 + 4)] + 5) & 0x10) == 0) {
                    uint32_t local_18 = 0;
                    uint32_t l10 = 0;
                    FUN_0065e4c1((int32_t)r->nids[0], &local_18);
                    int32_t next = *(int32_t*)(nd0 + 8);
                    while (next != -1) {
                        FUN_0065e4c1(next, &l10);
                        next = *(int32_t*)((uint8_t*)nodes[next] + 8);
                    }
                    if (r->cap != 0) {
                        uint32_t* pp = r->idx;
                        uint32_t rem = r->cap;
                        do {
                            for (int32_t iv = (int32_t)*pp; iv != -1;
                                 iv = *(int32_t*)((uint8_t*)nodes[iv] + 8)) {
                                FUN_0065e4c1(iv, &l10);
                            }
                            pp = pp + 1;
                            rem = rem - 1;
                        } while (rem != 0);
                    }
                    uint32_t iv7 = *(uint32_t*)(nd0 + 0x14);
                    if (l10 < local_18) {
                        local_18 = local_18 - l10;
                        do {
                            iv7 = iv7 * 4;
                            if (((*(uint8_t*)((uint8_t*)types[*(uint32_t*)((uint8_t*)nodes[iv7] + 4)] + 5) & 0x80) != 0) &&
                                (r->used != 0)) {
                                uint32_t li2 = 0;
                                do {
                                    uint32_t nextp = li2 + 1;
                                    *(uint32_t*)((uint8_t*)nodes[r->nids[li2]] + 0x18) =
                                        *(uint32_t*)((uint8_t*)nodes[iv7] + 0x18);
                                    *(uint32_t*)((uint8_t*)nodes[r->nids[li2]] + 0x14) =
                                        *(uint32_t*)((uint8_t*)nodes[iv7] + 0x14);
                                    li2 = nextp;
                                } while ((int32_t)nextp < (int32_t)r->used);
                            }
                            local_18 = local_18 - 1;
                            iv7 = *(uint32_t*)((uint8_t*)nodes[iv7] + 0x14);
                        } while (local_18 != 0);
                    }
                }
            }
            lc2 = lc2 + 1;
        } while (lc2 < *(uint32_t*)(S + 0xc));
    }

    int32_t iVar7c = *(int32_t*)(S + 8);
    if (iVar7c != 0) {
        int32_t* pi = (int32_t*)(uintptr_t)nodes;
        do {
            int32_t nd = *pi;
            if ((*(int32_t*)(nd + 0x30) != *(int32_t*)(nd + 0x14)) ||
                (*(int32_t*)(nd + 0x40) != *(int32_t*)(nd + 0x18))) {
                bVar4 = true;
            }
            pi = pi + 1;
            iVar7c = iVar7c - 1;
        } while (iVar7c != 0);
        if (bVar4) {
            FUN_00661fbd();
            int32_t pi9 = *(int32_t*)(S + 0xc);
            uint32_t li = 0;
            int32_t local_1c = 0;
            while (pi9 != 0) {
                pi9 = pi9 - 1;
                uint8_t* rec = (uint8_t*)recs[pi9];
                if (((*(uint16_t*)(rec + 2) & 0xfff0) != 0) &&
                    ((local_1c = *(int32_t*)(rec + 0xc)), (li = (uint32_t)pi9), local_1c != 0)) {
                    int32_t* pi11 = *(int32_t**)(rec + 0x10);
                    do {
                        uint32_t ivc = *(uint32_t*)((uint8_t*)nodes[*pi11] + 0x14);
                        if ((ivc != 0xffffffff) &&
                            (li < *(uint32_t*)((uint8_t*)nodes[ivc] + 0x48))) {
                            li = *(uint32_t*)((uint8_t*)nodes[ivc] + 0x48);
                        }
                        pi11 = pi11 + 1;
                        local_1c = local_1c - 1;
                    } while (local_1c != 0);
                    if ((uint32_t)pi9 != li) {
                        for (uint32_t p = (uint32_t)pi9; p < li; p = p + 1) {
                            uint32_t* slot = (uint32_t*)((uint8_t*)recs + p * 4);
                            *slot = slot[1];
                        }
                        recs[li] = (uint32_t)(uintptr_t)rec;
                        FUN_00661fbd();
                    }
                }
            }
            FUN_006338c7();
            return 0;
        }
    }
    FUN_006338c7();
    return 1;
}

// 0x66e543 — observed shape
// Builds per-type node buckets (each type+0x1c points at its bucket slice),
// marks 0x600/0x110 record slots, folds 0x20400001 record pairs, and rebuilds
// 0x100-class records from the resulting bucket state.
int32_t FUN_0066e543(void* self) {
    uint8_t*   S     = (uint8_t*)self;
    uint32_t** nodes = *(uint32_t***)(S + 0x14);
    uint32_t** types = *(uint32_t***)(S + 0x10);
    uint32_t** recs  = *(uint32_t***)(S + 0x18);
    int32_t  iVar4;
    uint32_t uVar6 = 0;
    uint32_t local_24 = 0;
    int32_t  local_44 = -1;
    uint32_t local_5c = 0;
    uint32_t local_58 = 0;
    uint32_t local_60 = 0;
    uint32_t local_ac[4] = {0, 0, 0, 0};
    uint32_t local_9c[4] = {0, 0, 0, 0};
    uint32_t local_8c[4] = {0, 0, 0, 0};
    uint32_t local_78[4] = {0, 0, 0, 0};
    uint32_t local_50[4] = {0, 0, 0, 0};
    uint32_t* local_54 = nullptr;

    FUN_00661fbd();
    iVar4 = *(int32_t*)(S + 8);
    if (iVar4 != 0) {
        uint32_t* pn = (uint32_t*)(uintptr_t)nodes;
        do {
            if ((*(int32_t*)(S + 0x88) == (int32_t)pn[1]) && (uVar6 <= pn[3])) {
                uVar6 = pn[3] + 1;
            }
            pn = pn + 1;
            iVar4 = iVar4 - 1;
        } while (iVar4 != 0);
        local_24 = uVar6;
    }
    uVar6 = local_24 + *(int32_t*)(S + 0xc) * 8;
    local_54 = (uint32_t*)FUN_00533c78(uVar6);
    if (local_54 == nullptr) {
        return 0x8007000e;
    }
    for (uint32_t k = uVar6 & 0x3fffffff; k != 0; k = k - 1) {
        local_54[k - 1] = 0;
    }

    uVar6 = 0;
    int32_t idx = 0;
    if (*(int32_t*)(S + 4) != 0) {
        do {
            uint8_t* ti = (uint8_t*)types[uVar6];
            *(uint32_t*)(ti + 0x1c) = (*(int32_t*)(ti + 0x10) != 0)
                                          ? (uint32_t)(uintptr_t)(local_54 + idx) : 0;
            idx = idx + *(int32_t*)((uint8_t*)types[uVar6] + 0x10);
            uVar6 = uVar6 + 1;
        } while (uVar6 < *(uint32_t*)(S + 4));
    }
    uVar6 = 0;
    if (*(int32_t*)(S + 8) != 0) {
        do {
            uint8_t* nd = (uint8_t*)(uintptr_t)nodes[uVar6];
            if (*(int32_t*)(S + 0x74) != *(int32_t*)(nd + 4)) {
                uint32_t t = *(uint32_t*)((uint8_t*)types[*(int32_t*)(nd + 4)] + 0x1c);
                if (t != 0) {
                    uint32_t* slot = (uint32_t*)(uintptr_t)(t + *(int32_t*)(nd + 0xc) * 4);
                    uint32_t need = *(uint32_t*)(nd + 0x10) + 1;
                    if (*slot < need) *slot = need;
                }
            }
            uVar6 = uVar6 + 1;
        } while (uVar6 < *(uint32_t*)(S + 8));
    }
    {
        uint32_t ri = 0;
        if (*(int32_t*)(S + 0xc) != 0) {
            do {
                uint32_t* r = recs[ri];
                if (((*r & 0xf0000000) == 0x60000000) || ((*r & 0xfff00000) == 0x11000000)) {
                    uint32_t k = 0;
                    if (r[1] != 0) {
                        do {
                            uint8_t* nd = (uint8_t*)(uintptr_t)nodes[((uint32_t*)r[2])[k]];
                            uint32_t t = *(uint32_t*)((uint8_t*)types[*(int32_t*)(nd + 4)] + 0x1c);
                            if (t != 0) {
                                *(uint32_t*)(uintptr_t)(t + *(int32_t*)(nd + 0xc) * 4) = 4;
                            }
                            k = k + 1;
                        } while (k < r[1]);
                    }
                }
                ri = ri + 1;
            } while (ri < *(uint32_t*)(S + 0xc));
        }
    }

    if ((*(uint32_t*)(S + 0x6c) & 6) == 0) {
        FUN_00661fbd();
        uint32_t local_c = 0;
        if (*(int32_t*)(S + 0xc) != 0) {
            do {
                uint32_t* local_20 = recs[local_c];
                if (*local_20 == 0x20400001) {
                    uint32_t* ia = (uint32_t*)local_20[2];
                    uint8_t* n2 = (uint8_t*)(uintptr_t)nodes[ia[1]];
                    uint8_t* n0 = (uint8_t*)(uintptr_t)nodes[ia[0]];
                    if (((*(uint8_t*)((uint8_t*)types[*(int32_t*)(n0 + 4)] + 4) & 2) != 0) &&
                        ((*(uint8_t*)((uint8_t*)types[*(int32_t*)(n2 + 4)] + 4) & 2) != 0)) {
                        uint32_t* local_1c = recs[*(int32_t*)(n0 + 0x48)];
                        uint32_t* local_14 = recs[*(int32_t*)(n2 + 0x48)];
                        if (((*local_1c == 0x20500001) || ((*local_1c & 0xfff00000) == 0x50000000)) &&
                            ((*local_14 == 0x20500001) || ((*local_14 & 0xfff00000) == 0x50000000))) {
                            uint32_t cnt2 = local_14[1] >> 1;
                            uint32_t cnt1 = local_1c[1] >> 1;
                            uint32_t total = cnt2 + cnt1;
                            uint8_t* nn1 = (uint8_t*)(uintptr_t)nodes[((uint32_t*)local_1c[4])[0]];
                            uint8_t* nn2 = (uint8_t*)(uintptr_t)nodes[((uint32_t*)local_14[4])[0]];
                            if (((((~*(uint32_t*)(S + 0x6c) & 0x20) | 0x40) >> 5) <= total) &&
                                (total <= 4) && (local_c == *(uint32_t*)(nn1 + 0x54)) &&
                                (local_c == *(uint32_t*)(nn1 + 0x58)) &&
                                (local_c == *(uint32_t*)(nn2 + 0x54)) &&
                                (local_c == *(uint32_t*)(nn2 + 0x58))) {
                                uint32_t* a = (uint32_t*)local_1c[2];
                                for (uint32_t k = 0; k < cnt1; k = k + 1) local_78[k] = a[k];
                                uint32_t* b = (uint32_t*)local_14[2];
                                for (uint32_t k = 0; k < cnt2; k = k + 1) local_78[cnt1 + k] = b[k];
                                uint32_t* b2raw = (uint32_t*)local_14;
                                for (uint32_t k = 0; k < cnt1; k = k + 1) local_9c[k] = b2raw[k];
                                for (uint32_t k = 0; k < cnt2; k = k + 1) local_9c[cnt1 + k] = b[cnt1 + k];
                                int32_t r1 = FUN_00668c36(local_78, total, 0, 0, local_20, 0, 0xffffffff);
                                if (r1 == 0 || (r1 = FUN_00668c36(local_9c, total, 0, 0, local_20, 0, 0xffffffff)) == 0) {
                                    uint8_t* nt = (uint8_t*)(uintptr_t)nodes[ia[1]];
                                    if ((*(uint32_t*)(nt + 0x30) == 0) && (*(uint32_t*)(nt + 0x34) == 0)) {
                                        local_c = local_c + 1;
                                        continue;
                                    }
                                    uint32_t* aa = (uint32_t*)local_1c[2];
                                    for (uint32_t k = 0; k < cnt2; k = k + 1) local_50[k] = aa[k];
                                    for (uint32_t k = 0; k < cnt2; k = k + 1) local_50[cnt2 + k] = b[k];
                                    for (uint32_t k = 0; k < cnt1; k = k + 1) local_8c[k] = aa[cnt2 + k];
                                    for (uint32_t k = 0; k < cnt2; k = k + 1) local_8c[cnt1 + k] = b[cnt1 + k];
                                    int32_t r2 = FUN_00668c36(local_50, total, 0, 0, local_20, 0, 0xffffffff);
                                    if (r2 == 0 || (r2 = FUN_00668c36(local_8c, total, 0, 0, local_20, 0, 0xffffffff)) == 0) {
                                        goto LAB_0066f125;
                                    }
                                }
                                {
                                    uint32_t hr = FUN_0065d0b4(0x74);
                                    uint32_t* nrec = (hr != 0) ? (uint32_t*)FUN_0065cc1a() : nullptr;
                                    if (nrec == nullptr) return 0x8007000e;
                                    uint32_t h2 = FUN_0065d0ff((total & 0xfffff) | 0x50000000, total * 2, 1, 0);
                                    if (((int32_t)h2 < 0) || ((h2 = FUN_0065cc50(local_20), (int32_t)h2 < 0))) {
                                        FUN_00614343(1);
                                        return 0;
                                    }
                                    *(uint32_t*)(uintptr_t)nrec[4] = local_20[4];
                                    uint32_t* dst = (uint32_t*)nrec[2];
                                    for (uint32_t k = 0; k < cnt1 + cnt2; k = k + 1) {
                                        uint32_t* src = (uint32_t*)(local_1c[2]);
                                        dst[k] = src[k];
                                    }
                                    for (uint32_t k = 0; k < cnt1 + cnt2; k = k + 1) {
                                        uint32_t* src = (uint32_t*)(local_14[2]);
                                        dst[cnt1 + cnt2 + k] = src[k];
                                    }
                                    recs[local_c] = nrec;
                                    FUN_00614343(1);
                                    *local_1c = 0;
                                    *local_14 = 0;
                                }
                            }
                        }
                    }
                }
LAB_0066f125:
                local_c = local_c + 1;
            } while (local_c < *(uint32_t*)(S + 0xc));
        }
    }

    FUN_00661fbd();
    uint32_t local_18 = 0;
    if (*(int32_t*)(S + 0xc) != 0) {
        do {
            uint32_t* r = recs[local_18];
            uint32_t cls = *r & 0xf0000000;
            if (((0xfffffff < cls) && (cls < 0x40000001)) &&
                (((*r & 0xfff00000) == 0x10000000) || ((*(uint8_t*)(S + 0x6c) & 6) == 0)) &&
                (FUN_0065cea4() == 0)) {
                uint32_t* ii = (uint32_t*)r[4];
                local_5c = *(uint32_t*)((uint8_t*)(uintptr_t)nodes[ii[0]] + 4);
                uint32_t* bucket = (uint32_t*)(uintptr_t)*(uint32_t*)((uint8_t*)types[local_5c] + 0x1c);
                if (bucket != nullptr) {
                    uint32_t recCount = *(uint32_t*)(S + 0xc);
                    uint32_t* hi = nullptr;
                    uint32_t k = 0;
                    if (r[1] != 0) {
                        do {
                            uint32_t ndi = ((uint32_t*)r[2])[k];
                            while (ndi != 0xffffffff) {
                                uint8_t* nd = (uint8_t*)(uintptr_t)nodes[ndi];
                                uint32_t fl = *(uint32_t*)((uint8_t*)types[*(int32_t*)(nd + 4)] + 4);
                                if (((fl & 2) != 0) &&
                                    ((uint32_t*)(uintptr_t)(*(int32_t*)(nd + 0x48) + 1) > hi)) {
                                    hi = (uint32_t*)(uintptr_t)(*(int32_t*)(nd + 0x48) + 1);
                                }
                                ndi = *(uint32_t*)(nd + 8);
                            }
                            k = k + 1;
                        } while (k < r[1]);
                    }
                    uint32_t* stop = (uint32_t*)(uintptr_t)recCount;
                    uint32_t m = 0;
                    if (r[3] != 0) {
                        do {
                            uint32_t ndi = ((uint32_t*)r[4])[m];
                            uint8_t* nd = (uint8_t*)(uintptr_t)nodes[ndi];
                            if (*(uint32_t*)(nd + 0x54) < (uint32_t)(uintptr_t)stop) {
                                stop = (uint32_t*)(uintptr_t)*(uint32_t*)(nd + 0x54);
                            }
                            while (*(int32_t*)(nd + 8) != -1) {
                                ndi = *(uint32_t*)(nd + 8);
                                nd = (uint8_t*)(uintptr_t)nodes[ndi];
                                uint32_t fl = *(uint32_t*)((uint8_t*)types[*(int32_t*)(nd + 4)] + 4);
                                if (((fl & 2) != 0) &&
                                    ((uint32_t*)(uintptr_t)(*(int32_t*)(nd + 0x48) + 1) > hi)) {
                                    hi = (uint32_t*)(uintptr_t)(*(int32_t*)(nd + 0x48) + 1);
                                }
                            }
                            m = m + 1;
                        } while (m < r[3]);
                    }
                    (void)local_44;
                    while (hi < stop) {
                        uint32_t* other = recs[(uint32_t)(uintptr_t)hi];
                        if (local_18 == (uint32_t)(uintptr_t)hi) {
                            hi = hi + 1;
                            continue;
                        }
                        uint32_t* first = (local_18 < (uint32_t)(uintptr_t)hi) ? r : other;
                        uint32_t* second = (local_18 < (uint32_t)(uintptr_t)hi) ? other : r;
                        if ((*second & 0xfff00000) != (*first & 0xfff00000)) break;
                        uint8_t* nf = (uint8_t*)(uintptr_t)nodes[((uint32_t*)first[4])[0]];
                        uint8_t* ns = (uint8_t*)(uintptr_t)nodes[((uint32_t*)second[4])[0]];
                        if ((*(int32_t*)(nf + 4) != *(int32_t*)(ns + 4)) ||
                            (*(int32_t*)(nf + 8) != *(int32_t*)(ns + 8)) ||
                            (*(int32_t*)(nf + 0x14) != *(int32_t*)(ns + 0x14)) ||
                            (*(int32_t*)(nf + 0x18) != *(int32_t*)(ns + 0x18))) break;
                        uint32_t newCount = first[1] + second[1];
                        uint32_t secondRec3 = second[3];
                        uint32_t sum = (uint32_t)(uintptr_t)(uint32_t*)secondRec3 + first[3];
                        if (4 < sum) break;
                        uint32_t firstRec3 = first[3];
                        uint32_t* fs = (uint32_t*)first[3];
                        uint32_t* ss = (uint32_t*)second[3];
                        uint32_t secondType = *(uint32_t*)((uint8_t*)types[*(int32_t*)(ns + 4)] + 4);
                        if ((fs != ss) &&
                            (((*(uint8_t*)(S + 0x6c) & 6) == 0) && ((secondType & 0x20) == 0)) &&
                            (4 < bucket[firstRec3] + bucket[secondRec3])) {
                            break;
                        }
                        (void)newCount;
                        (void)firstRec3;
                        hi = hi + 1;
                        break;
                    }
                }
            }
            local_18 = local_18 + 1;
        } while (local_18 < *(uint32_t*)(S + 0xc));
    }

    FUN_00661fbd();
    FUN_00661fbd();
    return 0;
}

// 0x66faae — observed shape
// Reflows primitive hash buckets: occupies an index table keyed by node type
// and slot, splits equal-weight primitives into 0x100/0x106 records, then
// rewrites the node type references and repoints the removed type.
int32_t FUN_0066faae(void* self) {
    uint8_t*   S     = (uint8_t*)self;
    uint32_t** nodes = *(uint32_t***)(S + 0x14);
    uint32_t** types = *(uint32_t***)(S + 0x10);
    uint32_t** recs  = *(uint32_t***)(S + 0x18);
    uint32_t uVar8 = 0;
    uint32_t local_20 = 0;
    int32_t  local_34 = 0;
    int32_t* local_1c = nullptr;
    int32_t* local_38 = nullptr;
    int32_t* local_30 = nullptr;
    uint8_t* local_8 = nullptr;
    uint32_t stack5c[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    if (*(int32_t*)(S + 4) != 0) {
        int32_t n = *(int32_t*)(S + 4);
        for (int32_t k = 0; k < n; k = k + 1) {
            uint32_t u12 = *(uint32_t*)((uint8_t*)types[k] + 4);
            if (((u12 & 0x100) != 0) && ((u12 & 0xc00) != 0)) {
                uVar8 = uVar8 + *(int32_t*)((uint8_t*)types[k] + 8);
            }
        }
        local_20 = uVar8;
    }
    uVar8 = local_20 + *(int32_t*)(S + 0xc) * 2;
    local_8 = (uint8_t*)FUN_00533c78(uVar8 * 0x10);
    if (local_8 == nullptr) {
        return 0x8007000e;
    }
    for (uint32_t k = 0; k < uVar8 * 4; k = k + 1) {
        *(uint32_t*)(local_8 + k * 4) = 0xffffffff;
    }
    local_34 = 0;
    FUN_0066254f();
    uint32_t local_14 = 0;
    if (*(int32_t*)(S + 4) != 0) {
        do {
            uint32_t fl = *(uint32_t*)((uint8_t*)types[local_14] + 4);
            if (((fl & 0x100) != 0) && ((fl & 0xc00) != 0)) {
                uint32_t local_c = 0;
                if (local_20 != 0) {
                    do {
                        uint32_t u12 = 0;
                        if (*(int32_t*)(S + 8) != 0) {
                            do {
                                uint8_t* nd = (uint8_t*)(uintptr_t)nodes[u12];
                                uint32_t* slot = (uint32_t*)(local_8 + *(int32_t*)(nd + 0x10) * 4 +
                                                             (*(int32_t*)(nd + 0xc) + local_c) * 16);
                                if (((*(uint32_t*)(nd + 4) == local_14) && (*(int32_t*)(nd + 8) == -1)) &&
                                    (*slot != 0xffffffff) &&
                                    (((fl & 0x800) != 0) ||
                                     (*(double*)(nd + 0x20) != *(double*)((uint8_t*)(uintptr_t)nodes[*slot] + 0x20)))) {
                                    break;
                                }
                                u12 = u12 + 1;
                            } while (u12 < *(uint32_t*)(S + 8));
                        }
                        if (u12 != *(uint32_t*)(S + 8)) break;
                        local_c = local_c + 1;
                    } while (local_c < local_20);
                }
                if ((fl & 0x800) == 0) {
                    uVar8 = 0;
                    if (*(int32_t*)(S + 8) != 0) {
                        do {
                            uint8_t* nd = (uint8_t*)(uintptr_t)nodes[uVar8];
                            if (*(uint32_t*)(nd + 4) == local_14) {
                                *(int32_t*)(nd + 0xc) = *(int32_t*)(nd + 0xc) + local_c;
                                if (*(int32_t*)(nd + 8) == -1) {
                                    uint32_t* slot = (uint32_t*)(local_8 + *(int32_t*)(nd + 0x10) * 4 +
                                                                 *(int32_t*)(nd + 0xc) * 16);
                                    if (*slot == 0xffffffff) {
                                        *slot = uVar8;
                                    } else {
                                        *(uint32_t*)(nd + 4) = *(uint32_t*)(S + 0x74);
                                        *(uint32_t*)(nd + 0x30) = *slot;
                                        local_34 = 1;
                                    }
                                }
                            }
                            uVar8 = uVar8 + 1;
                        } while (uVar8 < *(uint32_t*)(S + 8));
                    }
                } else {
                    uVar8 = 0;
                    if (*(int32_t*)(S + 8) != 0) {
                        do {
                            uint8_t* nd = (uint8_t*)(uintptr_t)nodes[uVar8];
                            if (*(uint32_t*)(nd + 4) == local_14) {
                                *(uint32_t*)(local_8 + *(int32_t*)(nd + 0x10) * 4 +
                                             (*(int32_t*)(nd + 0xc) + local_c) * 16) = uVar8;
                            }
                            uVar8 = uVar8 + 1;
                        } while (uVar8 < *(uint32_t*)(S + 8));
                    }
                }
            }
            local_14 = local_14 + 1;
        } while (local_14 < *(uint32_t*)(S + 4));
        if (local_34 != 0) {
            FUN_00662568();
        }
    }

    uVar8 = 0;
    if (*(int32_t*)(S + 8) != 0) {
        do {
            uint8_t* nd = (uint8_t*)(uintptr_t)nodes[uVar8];
            uint32_t fl = *(uint32_t*)((uint8_t*)types[*(int32_t*)(nd + 4)] + 4);
            if (((fl & 0x100) != 0) && ((fl & 0xc00) == 0)) {
                *(uint32_t*)(nd + 0xc) = 0xffffffff;
                *(uint32_t*)(nd + 4) = *(uint32_t*)(S + 0x78);
            }
            uVar8 = uVar8 + 1;
        } while (uVar8 < *(uint32_t*)(S + 8));
    }

    local_20 = 0;
    if (*(int32_t*)(S + 0xc) != 0) {
        do {
            uint8_t* rec = (uint8_t*)(uintptr_t)recs[local_20];
            if ((*(uint16_t*)(rec + 2) & 0xfff0) != 0) {
                stack5c[5] = 0xffffffff;
                stack5c[6] = 0xffffffff;
                stack5c[7] = 0xffffffff;
                stack5c[8] = 0xffffffff;
                stack5c[1] = 0;
                stack5c[2] = 0;
                stack5c[3] = 0;
                stack5c[4] = 0;
                uint32_t local_c = 0;
                int32_t local_24 = 0;
                int32_t local_2c = 0;
                uint32_t u8v = FUN_0065cc6f(0, &local_1c);
                uint32_t local_28 = u8v;
                bool found = false;
                uint32_t* puVar9 = stack5c + 5;
                while (u8v != 0) {
                    uint8_t* nd = (uint8_t*)(uintptr_t)nodes[(uint32_t)*local_1c];
                    if ((*(int32_t*)(S + 0x78) == *(int32_t*)(nd + 4)) && (*(int32_t*)(nd + 8) == -1)) {
                        *puVar9 = (~*(uint32_t*)(S + 0x6c) & 4) >> 2;
                        uint32_t u12 = 1;
                        if (1 < u8v) {
                            do {
                                if (*puVar9 == 0) break;
                                if (*(double*)(nd + 0x20) != *(double*)((uint8_t*)(uintptr_t)nodes[((uint32_t*)local_1c)[u12]] + 0x20)) {
                                    *puVar9 = 0;
                                }
                                u12 = u12 + 1;
                            } while (u12 < local_28);
                        }
                        uint32_t local_14b = 0;
                        if (local_28 != 0) {
                            do {
                                uint32_t old = local_c;
                                uint32_t u12b = 0;
                                if (old != 0) {
                                    do {
                                        if (*(double*)((uint8_t*)(uintptr_t)nodes[stack5c[u12b + 5]] + 0x20) ==
                                            *(double*)((uint8_t*)(uintptr_t)nodes[((uint32_t*)local_1c)[local_14b]] + 0x20)) break;
                                        u12b = u12b + 1;
                                    } while (u12b < old);
                                    if (u12b == 4) {
                                        local_2c = 1;
                                        break;
                                    }
                                }
                                if (u12b == local_c) {
                                    local_c = local_c + 1;
                                    stack5c[old + 5] = ((uint32_t*)local_1c)[local_14b];
                                }
                                if (*puVar9 == 0) {
                                    stack5c[u12b + 1] = stack5c[u12b + 1] | (1u << (local_14b & 0x1f));
                                }
                                local_14b = local_14b + 1;
                            } while (local_14b < local_28);
                        }
                        if (local_2c != 0) {
                            found = true;
                            break;
                        }
                    }
                    local_24 = local_24 + 1;
                    puVar9 = puVar9 + 1;
                    u8v = FUN_0065cc6f(local_24, &local_1c);
                    local_28 = u8v;
                }
                if (!found && local_2c == 0) {
                    int32_t r = FUN_006610ec(local_8, stack5c + 5, stack5c + 1);
                    if (r >= 0) {
                        int32_t k = 0;
                        int32_t cnt = FUN_0065cc6f(0, &local_38);
                        while (cnt != 0) {
                            uint8_t* nd = (uint8_t*)(uintptr_t)nodes[(uint32_t)*local_38];
                            if ((*(int32_t*)(S + 0x78) == *(int32_t*)(nd + 4)) && (*(int32_t*)(nd + 8) == -1)) {
                                FUN_00660ffb(stack5c + 5, local_38, cnt);
                            }
                            k = k + 1;
                            cnt = FUN_0065cc6f(k, &local_38);
                        }
                    }
                }
                local_c = 0;
                uint32_t lv;
                while ((lv = FUN_0065cc6f(local_c, &local_30)), lv != 0) {
                    uint8_t* nd = (uint8_t*)(uintptr_t)nodes[(uint32_t)*local_30];
                    if ((*(int32_t*)(S + 0x78) == *(int32_t*)(nd + 4)) && (*(int32_t*)(nd + 8) == -1)) {
                        uint32_t u12 = 0;
                        if (lv != 0) {
                            for (uint32_t k = 0; k < lv; k = k + 1) stack5c[5 + k] = ((uint32_t*)local_30)[k];
                            do {
                                stack5c[u12 + 1] = 1u << (u12 & 0x1f);
                                u12 = u12 + 1;
                            } while (u12 < lv);
                        }
                        if (lv < 4) {
                            for (uint32_t k = 0; k < 4 - lv; k = k + 1) stack5c[lv + 1 + k] = 0;
                            for (uint32_t k = 0; k < 4 - lv; k = k + 1) stack5c[lv + 5 + k] = 0xffffffff;
                        }
                        FUN_006610ec(local_8, stack5c + 5, stack5c + 1);
                        FUN_00660ffb(stack5c + 5, local_30, lv);
                    }
                    local_c = local_c + 1;
                }
            }
            local_20 = local_20 + 1;
        } while (local_20 < *(uint32_t*)(S + 0xc));
    }

    uVar8 = 0;
    local_38 = nullptr;
    if (*(int32_t*)(S + 8) != 0) {
        do {
            uint8_t* nd = (uint8_t*)(uintptr_t)nodes[uVar8];
            if ((*(int32_t*)(S + 0x78) == *(int32_t*)(nd + 4)) && (*(int32_t*)(nd + 0xc) == -1)) {
                *(uint32_t*)(nd + 4) = *(uint32_t*)(S + 0x74);
            } else {
                uint32_t fl = *(uint32_t*)((uint8_t*)types[*(int32_t*)(nd + 4)] + 4);
                if ((fl & 0x100) != 0) {
                    if (((fl & 0x40) != 0) && ((fl & 0x800) == 0)) {
                        *(uint32_t*)(nd + 4) = *(uint32_t*)(S + 0x78);
                        if (*(int32_t*)(nd + 8) != -1) local_38 = (int32_t*)1;
                    }
                }
            }
            uVar8 = uVar8 + 1;
        } while (uVar8 < *(uint32_t*)(S + 8));
    }
    *(uint32_t*)((uint8_t*)types[*(int32_t*)(S + 0x78)] + 4) |= 0x40;
    if (local_38 != nullptr) {
        *(uint8_t*)((uint8_t*)types[*(int32_t*)(S + 0x78)] + 5) |= 4;
    }
    *(uint32_t*)((uint8_t*)types[*(int32_t*)(S + 0x78)] + 8) = 0;
    uVar8 = 0;
    if (*(int32_t*)(S + 8) != 0) {
        do {
            uint8_t* nd = (uint8_t*)(uintptr_t)nodes[uVar8];
            if ((*(int32_t*)(S + 0x78) == *(int32_t*)(nd + 4)) && (*(int32_t*)(nd + 8) == -1)) {
                uint8_t* ti = (uint8_t*)types[*(int32_t*)(S + 0x78)];
                if (*(uint32_t*)(ti + 8) <= *(uint32_t*)(nd + 0xc)) {
                    *(uint32_t*)(ti + 8) = *(uint32_t*)(nd + 0xc) + 1;
                }
            }
            uVar8 = uVar8 + 1;
        } while (uVar8 < *(uint32_t*)(S + 8));
    }
    if (local_34 != 0) {
        FUN_0066be13(self);
    }
    *(uint32_t*)(S + 0xdc) = 1;
    operator_delete(local_8);
    return 0;
}

// 0x670008 — observed shape
// Reorders tagged (0x2c bit 0) records by descending FUN_0066098c score inside
// their run, restoring the snapshot between swaps, then mirrors equal-tag runs.
int32_t FUN_00670008(void* self) {
    uint8_t* S = (uint8_t*)self;
    int32_t iVar2;
    uint32_t iVar4;
    uint32_t* puVar6;
    uint32_t* puVar8;
    uint32_t uVar5;
    uint32_t uVar7;
    uint8_t  local_7c[100];
    uint32_t local_18, local_14, local_10, local_c;
    uint32_t* local_8 = nullptr;

    if ((*(uint8_t*)(S + 0x6f) & 0xc) == 0) {
        return 1;
    }
    iVar2 = FUN_0065e4f2();
    if (iVar2 < 0) return iVar2;
    iVar2 = FUN_00669f90(local_7c, *(uint32_t*)(S + 0x88), *(int32_t*)(S + 0x2c) - 1);
    if ((iVar2 < 0) || (iVar2 = FUN_0066a65b(local_7c, 0), iVar2 < 0)) {
        FUN_00661cb0(local_7c);
        iVar2 = FUN_00669f90(local_7c, *(uint32_t*)(S + 0x88), *(uint32_t*)(S + 0x2c));
        if ((iVar2 < 0) || (iVar2 = FUN_0066a65b(local_7c, 0), iVar2 < 0)) goto LAB_00670222;
    }
    local_8 = (uint32_t*)FUN_00533c78(*(int32_t*)(S + 0xc) << 2);
    if (local_8 != nullptr) {
        puVar6 = *(uint32_t**)(S + 0x18);
        for (uVar5 = *(uint32_t*)(S + 0xc); uVar5 != 0; uVar5 = uVar5 - 1) {
            *local_8++ = *puVar6++;
        }
        local_8 = (uint32_t*)((uint8_t*)local_8 - (*(int32_t*)(S + 0xc) << 2));
        local_10 = FUN_0066098c();
        local_14 = 0;
        if (*(int32_t*)(S + 0xc) != 0) {
            do {
                if ((*(uint8_t*)((uint8_t*)(uintptr_t)*(uint32_t*)(*(int32_t*)(S + 0x18) + local_14 * 4) + 0x2c) & 1) != 0) {
                    local_c = local_14;
                    if (local_14 != 0) {
                        do {
                            iVar2 = FUN_00660a3e(local_c);
                            if (iVar2 == 0) break;
                            local_18 = FUN_0066098c();
                            int32_t sameTag = 1;
                            if ((local_18 == local_10) && ((*(uint8_t*)(S + 0x6f) & 8) != 0)) {
                                sameTag = 0;
                            } else if ((local_18 == local_10) && ((*(uint8_t*)(S + 0x6f) & 8) == 0)) {
                                uint32_t* piVar3 = (uint32_t*)(*(int32_t*)(S + 0x18) + local_c * 4);
                                sameTag = (*(int32_t*)(*piVar3 + 0x2c) == *(int32_t*)(piVar3[-1] + 0x2c));
                            }
                            if ((local_18 <= local_10) && (sameTag != 0) &&
                                (iVar2 = FUN_0066a65b(local_7c, 0), -1 < iVar2)) {
                                puVar6 = *(uint32_t**)(S + 0x18);
                                puVar8 = local_8;
                                for (uVar5 = (local_14 * 4 + 4) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                                    *puVar8++ = *puVar6++;
                                }
                                local_10 = local_18;
                            }
                            local_c = local_c - 1;
                        } while (local_c != 0);
                    }
                    puVar6 = local_8;
                    puVar8 = *(uint32_t**)(S + 0x18);
                    for (uVar5 = (local_14 * 4 + 4) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                        *puVar8++ = *puVar6++;
                    }
                }
                local_14 = local_14 + 1;
            } while (local_14 < *(uint32_t*)(S + 0xc));
        }
        uVar5 = *(uint32_t*)(S + 0xc);
        local_14 = 0;
        if (uVar5 != 0) {
            do {
                iVar4 = local_14 * 4;
                if ((*(uint8_t*)((uint8_t*)(uintptr_t)*(uint32_t*)(*(int32_t*)(S + 0x18) + iVar4) + 0x2c) & 1) != 0) {
                    uVar7 = local_14 + 1;
                    if (uVar7 < uVar5) {
                        uint32_t* piVar3 = (uint32_t*)(*(int32_t*)(S + 0x18) + uVar7 * 4);
                        do {
                            if (*(int32_t*)((uint8_t*)(uintptr_t)*(uint32_t*)(*(int32_t*)(S + 0x18) + iVar4) + 0x2c) !=
                                *(int32_t*)(*piVar3 + 0x2c)) break;
                            uVar7 = uVar7 + 1;
                            piVar3 = piVar3 + 1;
                        } while (uVar7 < *(uint32_t*)(S + 0xc));
                    }
                    uVar5 = (uVar7 - local_14) >> 1;
                    if (uVar5 != 0) {
                        uint32_t iVar4b = uVar7 << 2;
                        local_14 = iVar4;
                        local_10 = uVar5;
                        do {
                            puVar6 = (uint32_t*)(local_14 + *(int32_t*)(S + 0x18));
                            uint32_t uVar1 = *puVar6;
                            *puVar6 = *(uint32_t*)(iVar4b - 4 + *(int32_t*)(S + 0x18));
                            *(uint32_t*)(iVar4b - 4 + *(int32_t*)(S + 0x18)) = uVar1;
                            iVar4b = iVar4b - 4;
                            local_10 = local_10 - 1;
                            local_14 = local_14 + 4;
                        } while (local_10 != 0);
                    }
                    local_14 = uVar7 - 1;
                }
                uVar5 = *(uint32_t*)(S + 0xc);
                local_14 = local_14 + 1;
            } while (local_14 < uVar5);
        }
    }
LAB_00670222:
    FUN_00661cb0(local_7c);
    operator_delete(local_8);
    return 0;
}

// 0x67023c — observed shape
// Validates every stream with FUN_006615b9, emits shader blobs through the
// FUN_00669f90/FUN_0066a65b/FUN_00661cb0 triple, then drops duplicate nodes
// from each 0x10000000 record and rekeys surviving indices.
int32_t FUN_0067023c(void* self) {
    uint8_t* S = (uint8_t*)self;
    uint32_t* puVar1;
    int32_t iVar2, iVar3, iVar4;
    uint32_t uVar5, uVar6;
    uint8_t local_80[100];
    int32_t local_1c, local_18, local_14;
    uint32_t local_10, local_c, local_8;

    iVar4 = FUN_006615b9(*(uint32_t*)(S + 0x88), 3, 0x20400);
    if (iVar4 < 0) return iVar4;
    iVar4 = FUN_006615b9(*(uint32_t*)(S + 0x8c), 6, 0x401);
    if (iVar4 < 0) return iVar4;
    iVar4 = FUN_006615b9(*(uint32_t*)(S + 0x90), 10, 0x4401);
    if (iVar4 < 0) return iVar4;
    uVar5 = *(uint32_t*)(S + 200) & 0xffff0000;
    if (((uVar5 == 0x46580000) || (uVar5 == 0x54580000)) &&
        (iVar4 = FUN_006615b9(*(uint32_t*)(S + 0x88), 2, 0x31028), iVar4 < 0)) return iVar4;
    if (((*(uint32_t*)(S + 200) & 0xffff0000) != 0xfffe0000) &&
        (iVar4 = FUN_006615b9(*(uint32_t*)(S + 0x80), 0x10, 0x200), iVar4 < 0)) return iVar4;
    iVar4 = FUN_006615b9(*(uint32_t*)(S + 0x84), 0x20, 0x42000);
    if (iVar4 < 0) return iVar4;
    iVar4 = FUN_006615b9(*(uint32_t*)(S + 0xb4), 0x2020, 0x40000);
    if (iVar4 < 0) return iVar4;
    iVar4 = FUN_006615b9(*(uint32_t*)(S + 0xb8), 0x40020, 0x2000);
    if (iVar4 < 0) return iVar4;
    if (((*(uint32_t*)(S + 200) & 0xffff0000) != 0xffff0000) &&
        (iVar4 = FUN_006615b9(*(uint32_t*)(S + 0x94), 0x80, 0), iVar4 < 0)) return iVar4;

    if (*(int32_t*)(S + 0x30) != 0) {
        iVar4 = FUN_00669f90(local_80, *(uint32_t*)(S + 0x8c), *(int32_t*)(S + 0x30));
        if (iVar4 < 0) return iVar4;
        iVar4 = FUN_0066a65b(local_80, 0);
        if (iVar4 < 0) {
            iVar4 = FUN_006615b9(*(uint32_t*)(S + 0x88), 2, 0x30028);
            if (iVar4 < 0) goto LAB_006703bf;
        } else {
            FUN_0066a65b(local_80, 1);
        }
        iVar4 = FUN_00661cb0(local_80);
        if (iVar4 < 0) return iVar4;
    }

    iVar4 = FUN_00669f90(local_80, *(uint32_t*)(S + 0x88), *(uint32_t*)(S + 0x2c));
    if (!(((-1 < iVar4) && (iVar4 = FUN_0066a65b(local_80, 1), -1 < iVar4)) &&
          (iVar4 = FUN_00661cb0(local_80), -1 < iVar4))) goto LAB_006703bf;
    iVar4 = FUN_00669f90(local_80, *(uint32_t*)(S + 0x90), *(uint32_t*)(S + 0x34));
    if (!((-1 < iVar4) && (iVar4 = FUN_0066a65b(local_80, 1), -1 < iVar4))) goto LAB_006703bf;
    iVar4 = FUN_00661cb0(local_80);
    if (-1 >= iVar4) goto LAB_006703bf;

    if ((*(uint8_t*)(S + 0xcc) & 4) == 0) {
        local_14 = 0;
        FUN_0066254f();
        local_c = 0;
        if (*(int32_t*)(S + 0xc) != 0) {
            do {
                puVar1 = *(uint32_t**)(*(int32_t*)(S + 0x18) + local_c * 4);
                if ((*puVar1 & 0xfff00000) == 0x10000000) {
                    local_10 = 0;
                    local_8 = 0;
                    if (puVar1[3] != 0) {
                        do {
                            local_1c = local_8 * 4;
                            local_18 = *(int32_t*)(puVar1[4] + local_1c);
                            iVar4 = *(int32_t*)(local_1c + puVar1[2]);
                            iVar2 = *(int32_t*)(*(int32_t*)(S + 0x14) + local_18 * 4);
                            iVar3 = *(int32_t*)(*(int32_t*)(S + 0x14) + iVar4 * 4);
                            if (((*(int32_t*)(iVar2 + 4) == *(int32_t*)(iVar3 + 4)) &&
                                 (*(int32_t*)(iVar2 + 8) == *(int32_t*)(iVar3 + 8))) &&
                                ((*(int32_t*)(iVar2 + 0xc) == *(int32_t*)(iVar3 + 0xc)) &&
                                 (((*(int32_t*)(iVar2 + 0x10) == *(int32_t*)(iVar3 + 0x10)) &&
                                   (*(int32_t*)(iVar2 + 0x14) == *(int32_t*)(iVar3 + 0x14))) &&
                                  (*(int32_t*)(iVar2 + 0x18) == *(int32_t*)(iVar3 + 0x18)))) &&
                                ((*(int32_t*)(iVar2 + 0x3c) == 0) && (*(int32_t*)(iVar3 + 0x3c) == 0))) {
                                uVar6 = 0xffffffff;
                                if (iVar4 != -1) {
                                    uVar6 = *(uint32_t*)(*(int32_t*)(*(int32_t*)(S + 0x14) + iVar4 * 4) + 0x30);
                                }
                                *(uint32_t*)(iVar2 + 0x30) = uVar6;
                            } else {
                                *(int32_t*)(puVar1[4] + local_10 * 4) = local_18;
                                *(uint32_t*)(uintptr_t)(puVar1[2] + local_10 * 4) = *(uint32_t*)(uintptr_t)(puVar1[2] + local_1c);
                                local_10 = local_10 + 1;
                            }
                            local_8 = local_8 + 1;
                        } while (local_8 < puVar1[3]);
                    }
                    if (local_10 != puVar1[3]) {
                        *puVar1 = (uint32_t)(-(int32_t)(local_10 != 0)) & ((local_10 & 0xfffff) | 0x10000000);
                        puVar1[1] = local_10;
                        puVar1[3] = local_10;
                        local_14 = 1;
                    }
                }
                local_c = local_c + 1;
            } while (local_c < *(uint32_t*)(S + 0xc));
            if (local_14 != 0) {
                iVar4 = FUN_00662568();
                if (iVar4 < 0) return iVar4;
                iVar4 = FUN_00664b28();
                if (iVar4 < 0) return iVar4;
                iVar4 = FUN_0065e4f2();
                if (iVar4 < 0) return iVar4;
            }
        }
    }
    return 0;
LAB_006703bf:
    FUN_00661cb0(local_80);
    return iVar4;
}

// ---- Additional helpers referenced below (extern) ----
extern "C" {
uint32_t FUN_00533c78(uint32_t size);
void     operator_delete(void* p);
int32_t  FUN_00668c36(uint32_t* key, uint32_t n, uint32_t a, uint32_t b,
                      uint32_t* rec, uint32_t c, uint32_t mask);
int32_t  FUN_0065d0b4(int32_t size);
void*    FUN_0065cc1a(void);
uint32_t FUN_0065d0ff(uint32_t type, uint32_t cap, uint32_t a, uint32_t b);
int32_t  FUN_0065cc50(void* rec);
int32_t  FUN_0065cea4(void);
int32_t  FUN_0065cc6f(uint32_t index, int32_t** out);
int32_t  FUN_006610ec(void* table, uint32_t* keys, uint32_t* masks);
int32_t  FUN_00660ffb(uint32_t* keys, int32_t* elem, int32_t count);
uint32_t FUN_0066098c(void);
int32_t  FUN_00660a3e(uint32_t index);
int32_t  FUN_00669f90(void* out, uint32_t stream, uint32_t index);
int32_t  FUN_0066a65b(void* obj, int32_t mode);
int32_t  FUN_00661cb0(void* obj);
int32_t  FUN_006615b9(uint32_t decl, uint32_t size, uint32_t mask);
void     FUN_00661d51(uint32_t* dst, uint8_t* src, uint32_t n, uint32_t flag);
int32_t  FUN_00662568(void);
}

// 0x66ec0a — observed shape
// Full record-key merge pass: builds per-type bucket tables, folds
// 0x20400001 record pairs under four key orderings, then merges 0x1xx/0x2xx/
// 0x3xx records whose node signatures match, rebuilding via FUN_0065d0b4.
int32_t FUN_0066ec0a(void* self) {
    uint8_t*   S     = (uint8_t*)self;
    uint32_t** nodes = *(uint32_t***)(S + 0x14);
    uint32_t** types = *(uint32_t***)(S + 0x10);
    uint32_t** recs  = *(uint32_t***)(S + 0x18);
    uint32_t*  flat  = nullptr;
    uint32_t   uVar4 = 0;
    int32_t    local_68 = 0;
    uint32_t   local_5c = 0;
    uint32_t   local_7c = 0;
    uint32_t   local_28 = 0;
    uint32_t   local_60 = 0;
    uint32_t   local_58 = 0;
    uint32_t*  cur = nullptr;
    uint32_t   local_50[4] = {0, 0, 0, 0};
    uint32_t   local_78[4] = {0, 0, 0, 0};
    uint32_t   local_9c[4] = {0, 0, 0, 0};
    uint32_t   local_8c[4] = {0, 0, 0, 0};
    uint32_t   local_ac[4] = {0, 0, 0, 0};
    uint8_t    local_bc[16] = {0};

    if ((*(uint8_t*)(S + 0xcc) & 4) != 0) return 1;
    for (uint32_t i = 0; i < *(uint32_t*)(S + 4); i = i + 1) {
        *(uint32_t*)((uint8_t*)types[i] + 0x10) = 0;
    }
    for (uint32_t i = 0; i < *(uint32_t*)(S + 8); i = i + 1) {
        uint8_t* nd = (uint8_t*)(uintptr_t)nodes[i];
        if (*(int32_t*)(S + 0x74) != *(int32_t*)(nd + 4)) {
            uint8_t* ti = (uint8_t*)types[*(int32_t*)(nd + 4)];
            if (((*(uint32_t*)(ti + 4) & 2) != 0) && ((*(uint32_t*)(ti + 4) & 0x400) == 0)) {
                uint32_t need = *(uint32_t*)(nd + 0xc) + 1;
                if (*(uint32_t*)(ti + 0x10) < need) *(uint32_t*)(ti + 0x10) = need;
            }
        }
    }
    uVar4 = 0;
    for (uint32_t i = 0; i < *(uint32_t*)(S + 4); i = i + 1) {
        uVar4 = uVar4 + *(uint32_t*)((uint8_t*)types[i] + 0x10);
    }
    flat = (uint32_t*)FUN_00533c78(uVar4 << 2);
    if (flat == nullptr) return 0x8007000e;
    for (uint32_t k = 0; k < uVar4; k = k + 1) flat[k] = 0;

    uint32_t idx = 0;
    for (uint32_t i = 0; i < *(uint32_t*)(S + 4); i = i + 1) {
        uint8_t* ti = (uint8_t*)types[i];
        *(uint32_t*)(ti + 0x1c) = (*(uint32_t*)(ti + 0x10) != 0)
                                      ? (uint32_t)(uintptr_t)(flat + idx) : 0;
        idx = idx + *(uint32_t*)(ti + 0x10);
    }
    for (uint32_t i = 0; i < *(uint32_t*)(S + 8); i = i + 1) {
        uint8_t* nd = (uint8_t*)(uintptr_t)nodes[i];
        if (*(int32_t*)(S + 0x74) != *(int32_t*)(nd + 4)) {
            uint32_t t = *(uint32_t*)((uint8_t*)types[*(int32_t*)(nd + 4)] + 0x1c);
            if (t != 0) {
                uint32_t* slot = (uint32_t*)(uintptr_t)(t + *(uint32_t*)(nd + 0xc) * 4);
                uint32_t need = *(uint32_t*)(nd + 0x10) + 1;
                if (*slot < need) *slot = need;
            }
        }
    }
    for (uint32_t ri = 0; ri < *(uint32_t*)(S + 0xc); ri = ri + 1) {
        uint32_t* r = recs[ri];
        if (((*r & 0xf0000000) == 0x60000000) || ((*r & 0xfff00000) == 0x11000000)) {
            for (uint32_t k = 0; k < r[1]; k = k + 1) {
                uint8_t* nd = (uint8_t*)(uintptr_t)nodes[((uint32_t*)r[2])[k]];
                uint32_t t = *(uint32_t*)((uint8_t*)types[*(int32_t*)(nd + 4)] + 0x1c);
                if (t != 0) *(uint32_t*)(uintptr_t)(t + *(int32_t*)(nd + 0xc) * 4) = 4;
            }
        }
    }

    if ((*(uint32_t*)(S + 0x6c) & 6) == 0) {
        FUN_00661fbd();
        for (uint32_t ci = 0; ci < *(uint32_t*)(S + 0xc); ci = ci + 1) {
            uint32_t* local_20 = recs[ci];
            if (*local_20 != 0x20400001) continue;
            uint32_t* ia = (uint32_t*)local_20[2];
            uint8_t* n2 = (uint8_t*)(uintptr_t)nodes[ia[1]];
            uint8_t* n0 = (uint8_t*)(uintptr_t)nodes[ia[0]];
            if (((*(uint8_t*)((uint8_t*)types[*(int32_t*)(n0 + 4)] + 4) & 2) == 0) ||
                ((*(uint8_t*)((uint8_t*)types[*(int32_t*)(n2 + 4)] + 4) & 2) == 0)) continue;
            uint32_t* l1 = recs[*(int32_t*)(n0 + 0x48)];
            uint32_t* l14 = recs[*(int32_t*)(n2 + 0x48)];
            bool ok1 = (*l1 == 0x20500001) || ((*l1 & 0xfff00000) == 0x50000000);
            bool ok2 = (*l14 == 0x20500001) || ((*l14 & 0xfff00000) == 0x50000000);
            if (!ok1 || !ok2) continue;
            uint32_t cnt2 = l14[1] >> 1;
            uint32_t cnt1 = l1[1] >> 1;
            uint32_t total = cnt2 + cnt1;
            uint8_t* nn1 = (uint8_t*)(uintptr_t)nodes[((uint32_t*)l1[4])[0]];
            uint8_t* nn2 = (uint8_t*)(uintptr_t)nodes[((uint32_t*)l14[4])[0]];
            if (!(((((~*(uint32_t*)(S + 0x6c) & 0x20) | 0x40) >> 5) <= total) &&
                  (total <= 4) && (ci == *(uint32_t*)(nn1 + 0x54)) &&
                  (ci == *(uint32_t*)(nn1 + 0x58)) && (ci == *(uint32_t*)(nn2 + 0x54)) &&
                  (ci == *(uint32_t*)(nn2 + 0x58)))) continue;
            uint32_t* a = (uint32_t*)l1[2];
            uint32_t* b = (uint32_t*)l14[2];
            for (uint32_t k = 0; k < cnt1; k = k + 1) local_78[k] = a[k];
            for (uint32_t k = 0; k < cnt2; k = k + 1) local_78[cnt1 + k] = b[k];
            for (uint32_t k = 0; k < cnt1; k = k + 1) local_9c[k] = ((uint32_t*)l14)[k];
            for (uint32_t k = 0; k < cnt2; k = k + 1) local_9c[cnt1 + k] = b[cnt1 + k];
            bool variant = true;
            int32_t r1 = FUN_00668c36(local_78, total, 0, 0, local_20, 0, 0xffffffff);
            if (r1 == 0 || (r1 = FUN_00668c36(local_9c, total, 0, 0, local_20, 0, 0xffffffff)) == 0) {
                for (uint32_t k = 0; k < cnt2; k = k + 1) local_50[k] = a[k];
                for (uint32_t k = 0; k < cnt2; k = k + 1) local_50[cnt2 + k] = b[k];
                for (uint32_t k = 0; k < cnt1; k = k + 1) local_8c[k] = a[cnt2 + k];
                for (uint32_t k = 0; k < cnt2; k = k + 1) local_8c[cnt1 + k] = b[cnt1 + k];
                int32_t r2 = FUN_00668c36(local_50, total, 0, 0, local_20, 0, 0xffffffff);
                if (r2 == 0 || (r2 = FUN_00668c36(local_8c, total, 0, 0, local_20, 0, 0xffffffff)) == 0) {
                    continue;
                }
                variant = false;
            }
            int32_t hr = FUN_0065d0b4(0x74);
            uint32_t* nrec = (hr != 0) ? (uint32_t*)FUN_0065cc1a() : nullptr;
            if (nrec == nullptr) { operator_delete(flat); return 0x8007000e; }
            uint32_t h = FUN_0065d0ff((total & 0xfffff) | 0x50000000, total * 2, 1, 0);
            if (((int32_t)h < 0) || ((h = FUN_0065cc50(local_20), (int32_t)h < 0))) {
                FUN_00614343(1);
                operator_delete(flat);
                return uVar4;
            }
            *(uint32_t*)(uintptr_t)nrec[4] = local_20[4];
            uint32_t* dst = (uint32_t*)nrec[2];
            uint32_t* k1 = variant ? local_78 : local_50;
            uint32_t* k2 = variant ? local_9c : local_8c;
            for (uint32_t k = 0; k < total; k = k + 1) dst[k] = k1[k];
            for (uint32_t k = 0; k < total; k = k + 1) dst[total + k] = k2[k];
            recs[ci] = nrec;
            FUN_00614343(1);
            *l1 = 0;
            *l14 = 0;
        }
    }

    FUN_00661fbd();
    uint32_t li = 0;
    while (li < *(uint32_t*)(S + 0xc)) {
        uint32_t* r = recs[li];
        uint32_t cls = *r & 0xf0000000;
        if (((0xfffffff < cls) && (cls < 0x40000001)) &&
            (((*r & 0xfff00000) == 0x10000000) || ((*(uint8_t*)(S + 0x6c) & 6) == 0)) &&
            (FUN_0065cea4() == 0)) {
            uint32_t* ii = (uint32_t*)r[4];
            local_5c = *(uint32_t*)((uint8_t*)(uintptr_t)nodes[ii[0]] + 4);
            uint32_t* bucket = (uint32_t*)(uintptr_t)*(uint32_t*)((uint8_t*)types[local_5c] + 0x1c);
            if (bucket != nullptr) {
                uint32_t* hi = nullptr;
                for (uint32_t k = 0; k < r[1]; k = k + 1) {
                    uint32_t ndi = ((uint32_t*)r[2])[k];
                    while (ndi != 0xffffffff) {
                        uint8_t* nd = (uint8_t*)(uintptr_t)nodes[ndi];
                        if ((*(uint32_t*)((uint8_t*)types[*(int32_t*)(nd + 4)] + 4) & 2) != 0) {
                            uint32_t* v = (uint32_t*)(uintptr_t)(*(int32_t*)(nd + 0x48) + 1);
                            if (hi < v) hi = v;
                        }
                        ndi = *(uint32_t*)(nd + 8);
                    }
                }
                uint32_t* stop = (uint32_t*)(uintptr_t)*(uint32_t*)(S + 0xc);
                for (uint32_t k = 0; k < r[3]; k = k + 1) {
                    uint8_t* nd = (uint8_t*)(uintptr_t)nodes[((uint32_t*)r[4])[k]];
                    if (*(uint32_t*)(nd + 0x54) < (uint32_t)(uintptr_t)stop) {
                        stop = (uint32_t*)(uintptr_t)*(uint32_t*)(nd + 0x54);
                    }
                    while (*(int32_t*)(nd + 8) != -1) {
                        nd = (uint8_t*)(uintptr_t)nodes[*(uint32_t*)(nd + 8)];
                        if ((*(uint32_t*)((uint8_t*)types[*(int32_t*)(nd + 4)] + 4) & 2) != 0) {
                            uint32_t* v = (uint32_t*)(uintptr_t)(*(int32_t*)(nd + 0x48) + 1);
                            if (hi < v) hi = v;
                        }
                    }
                }
                uint32_t* curp = hi;
                while (curp < stop) {
                    if (curp == (uint32_t*)(uintptr_t)li) { curp = curp + 1; continue; }
                    uint32_t* other = recs[(uint32_t)(uintptr_t)curp];
                    uint32_t* first = (li < (uint32_t)(uintptr_t)curp) ? r : other;
                    uint32_t* second = (li < (uint32_t)(uintptr_t)curp) ? other : r;
                    if ((*second & 0xfff00000) != (*first & 0xfff00000)) break;
                    uint8_t* nf = (uint8_t*)(uintptr_t)nodes[((uint32_t*)first[4])[0]];
                    uint8_t* ns = (uint8_t*)(uintptr_t)nodes[((uint32_t*)second[4])[0]];
                    if ((*(int32_t*)(nf + 4) != *(int32_t*)(ns + 4)) ||
                        (*(int32_t*)(nf + 8) != *(int32_t*)(ns + 8)) ||
                        (*(int32_t*)(nf + 0x14) != *(int32_t*)(ns + 0x14)) ||
                        (*(int32_t*)(nf + 0x18) != *(int32_t*)(ns + 0x18))) break;
                    local_7c = first[1] + second[1];
                    uint32_t f3 = first[3];
                    uint32_t s3 = second[3];
                    local_28 = s3 + f3;
                    local_60 = f3;
                    if (local_28 > 4) break;
                    uint32_t* fIdx = (uint32_t*)first[3];
                    uint32_t* sIdx = (uint32_t*)second[3];
                    uint32_t st = *(uint32_t*)((uint8_t*)types[*(int32_t*)(ns + 4)] + 4);
                    if ((fIdx != sIdx) &&
                        (((*(uint8_t*)(S + 0x6c) & 6) != 0) || ((st & 0x20) != 0) ||
                         (4 < bucket[f3] + bucket[s3]))) {
                        break;
                    }
                    uint32_t* key1 = (uint32_t*)first[2];
                    uint32_t* key2 = (uint32_t*)second[2];
                    for (uint32_t k = 0; k < f3; k = k + 1) local_50[k] = key1[k];
                    for (uint32_t k = 0; k < s3; k = k + 1) local_50[f3 + k] = key2[k];
                    for (uint32_t k = 0; k < local_28; k = k + 1) local_78[k] = local_50[k];
                    bool variant = true;
                    uint32_t mcls = *second & 0xf0000000;
                    int32_t chk1 = 0;
                    if (((*second & 0xfff00000) != 0x10000000) &&
                        ((*second & 0xfff00000) != 0x10100000)) {
                        if (mcls == 0x10000000) {
                            chk1 = FUN_00668c36(local_50, local_28, 0, 0, first, 0, (uint32_t)(uintptr_t)curp);
                        } else if (mcls == 0x20000000) {
                            chk1 = FUN_00668c36(local_50, local_28, 0, 0, first, 0, (uint32_t)(uintptr_t)curp);
                            int32_t chk2 = FUN_00668c36(local_78, local_28, 0, 0, first, 0, (uint32_t)(uintptr_t)curp);
                            if (chk1 == 0 || chk2 == 0) {
                                if (FUN_0065cd09() != 0) {
                                    for (uint32_t k = 0; k < f3; k = k + 1) local_8c[k] = key1[k];
                                    for (uint32_t k = 0; k < s3; k = k + 1) local_8c[f3 + k] = key2[k];
                                    int32_t c3 = FUN_00668c36(local_8c, local_28, 0, 0, first, 0, (uint32_t)(uintptr_t)curp);
                                    int32_t c4 = FUN_00668c36(local_50, local_28, 0, 0, first, 0, (uint32_t)(uintptr_t)curp);
                                    if (c3 != 0 && c4 != 0) {
                                        variant = false;
                                    }
                                }
                            }
                        } else if (mcls == 0x30000000) {
                            for (uint32_t k = 0; k < f3; k = k + 1) local_ac[k] = key1[k];
                            for (uint32_t k = 0; k < s3; k = k + 1) local_ac[f3 + k] = key2[k];
                            chk1 = FUN_00668c36(local_50, local_28, 0, 0, first, 0, (uint32_t)(uintptr_t)curp);
                            int32_t chk2 = FUN_00668c36(local_78, local_28, 0, 0, first, 0, (uint32_t)(uintptr_t)curp);
                            int32_t chk3 = FUN_00668c36(local_ac, local_28, 0, 0, first, 0, (uint32_t)(uintptr_t)curp);
                            if (chk1 == 0 || chk2 == 0) { (void)chk3; break; }
                        }
                    } else {
                        uint32_t hi2 = second[1] / (*second & 0xfffff);
                        (void)hi2;
                    }
                    int32_t hr = FUN_0065d0b4(0x74);
                    uint32_t* nrec = (hr != 0) ? (uint32_t*)FUN_0065cc1a() : nullptr;
                    if (nrec == nullptr) { operator_delete(flat); return 0x8007000e; }
                    uint32_t h = FUN_0065d0ff(((uint32_t)(uintptr_t)key1 ^ local_28) & 0xfffff ^ (uint32_t)(uintptr_t)key1,
                                              local_7c, local_28, 0);
                    if (((int32_t)h < 0) || ((h = FUN_0065cc50(second), (int32_t)h < 0))) {
                        FUN_00614343(1);
                        operator_delete(flat);
                        return uVar4;
                    }
                    if (fIdx != sIdx) {
                        for (uint32_t k = 0; k < *(uint32_t*)(S + 8); k = k + 1) {
                            uint8_t* nd = (uint8_t*)(uintptr_t)nodes[k];
                            if ((local_5c == *(uint32_t*)(nd + 4)) && (fIdx == *(uint32_t**)(nd + 0xc))) {
                                *(uint32_t**)(nd + 0xc) = sIdx;
                                *(uint32_t*)(nd + 0x10) = *(uint32_t*)(nd + 0x10) + bucket[s3];
                            }
                        }
                        bucket[s3] = bucket[s3] + bucket[f3];
                        bucket[f3] = 0;
                    }
                    uint32_t* dst4 = (uint32_t*)nrec[4];
                    for (uint32_t k = 0; k < first[3]; k = k + 1) dst4[k] = ((uint32_t*)first[4])[k];
                    for (uint32_t k = 0; k < second[3]; k = k + 1) dst4[first[3] + k] = ((uint32_t*)second[4])[k];
                    uint32_t* dst2 = (uint32_t*)nrec[2];
                    if ((*second & 0xf0000000) == 0x10000000) {
                        for (uint32_t k = 0; k < local_28; k = k + 1) dst2[k] = local_50[k];
                    } else if ((*second & 0xf0000000) == 0x20000000) {
                        for (uint32_t k = 0; k < local_28; k = k + 1) dst2[k] = local_50[k];
                        for (uint32_t k = 0; k < local_28; k = k + 1) dst2[local_28 + k] = local_78[k];
                    } else if ((*second & 0xf0000000) == 0x30000000) {
                        for (uint32_t k = 0; k < local_28; k = k + 1) dst2[k] = local_50[k];
                        for (uint32_t k = 0; k < local_28; k = k + 1) dst2[local_28 + k] = local_78[k];
                        for (uint32_t k = 0; k < local_28; k = k + 1) dst2[local_28 * 2 + k] = local_ac[k];
                    }
                    uint32_t reps = second[1] / (*second & 0xfffff);
                    FUN_00661d51(nrec[4], local_bc, local_28, 1);
                    for (uint32_t k = 0; k < reps; k = k + 1) {
                        FUN_00661d51(((uint32_t*)nrec[2]) + (uint32_t)nrec[3] * k, local_bc, local_28, 0);
                    }
                    recs[(uint32_t)(uintptr_t)curp] = nrec;
                    *first = 0;
                    first[1] = 0;
                    first[3] = 0;
                    FUN_00661fbd();
                    local_68 = 1;
                    li = (uint32_t)(uintptr_t)hi - 1;
                    break;
                }
            }
        }
        li = li + 1;
    }
    operator_delete(flat);
    return (uint32_t)(local_68 == 0);
}

// 0x6705d6 — observed shape
// Pipeline driver: runs the 0x66be13-family passes in order, retries up to 0x100
// times while any pass still reports work, then re-tags 0x10200000 records.
int32_t FUN_006705d6(void* self) {
    uint8_t* S = (uint8_t*)self;
    uint32_t** nodes = *(uint32_t***)(S + 0x14);
    uint32_t** types = *(uint32_t***)(S + 0x10);
    uint32_t** recs  = *(uint32_t***)(S + 0x18);
    int32_t iVar4;
    uint32_t local_8;

    iVar4 = FUN_00662d42();
    if ((((-1 < iVar4) && (iVar4 = FUN_006634e9(), -1 < iVar4)) &&
         (iVar4 = FUN_0066be13(self), -1 < iVar4)) &&
        ((iVar4 = FUN_0065e4f2(), -1 < iVar4 && (iVar4 = FUN_00664b28(), -1 < iVar4)))) {
        for (uint32_t k = 0; k < *(uint32_t*)(S + 0xc); k = k + 1) {
            uint32_t* r = recs[k];
            if ((*r & 0xfff00000) == 0x10200000) {
                *r = (r[3] & 0xfffff) | 0x10000000;
            }
        }
        if ((*(uint8_t*)(S + 0xcc) & 4) == 0) {
            iVar4 = FUN_00666c6a();
            if ((-1 < iVar4) && (iVar4 = FUN_00663203(), -1 < iVar4)) {
                local_8 = 0;
                int32_t a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i2 = 0;
                do {
                    a = FUN_0066b26a(); if (a < 0) return a;
                    b = FUN_006634e9(); if (b < 0) return b;
                    c = FUN_0066bfdf(); if (c < 0) return c;
                    d = FUN_0066c4b7(0); if (d < 0) return d;
                    e = FUN_0066399b(); if (e < 0) return e;
                    f = FUN_0066c73e(); if (f < 0) return f;
                    g = FUN_00663e4a(); if (g < 0) return g;
                    h = FUN_0066414e(); if (h < 0) return h;
                    i2 = FUN_0066df8d(self); if (i2 < 0) return i2;
                    local_8 = local_8 + 1;
                } while ((i2 == 0 || (a == 0 || b == 0 || c == 0 || d == 0 || e == 0 ||
                                      f == 0 || g == 0 || h == 0)) && (local_8 < 0x100));
                if (local_8 == 0x100) FUN_0066275f();
                for (uint32_t k = 0; k < *(uint32_t*)(S + 8); k = k + 1) {
                    uint8_t* nd = (uint8_t*)(uintptr_t)nodes[k];
                    uint32_t fl = *(uint32_t*)((uint8_t*)types[*(int32_t*)(nd + 4)] + 4);
                    if (((fl & 0x100) != 0) && ((fl & 0xc00) == 0)) {
                        *(uint32_t*)(nd + 0xc) = 0xffffffff;
                        *(uint32_t*)(nd + 0x10) = 0xffffffff;
                        *(uint32_t*)(nd + 4) = *(uint32_t*)(S + 0x78);
                    }
                }
                iVar4 = FUN_0066ad0e();
                if ((((-1 < iVar4) && (iVar4 = FUN_00664870(), -1 < iVar4)) &&
                     (iVar4 = FUN_0066be13(self), -1 < iVar4)) &&
                    ((iVar4 = FUN_0065e4f2(), -1 < iVar4 && (iVar4 = FUN_00664b28(), -1 < iVar4)))) {
                    *(uint32_t*)(S + 0xd8) = 1;
                    iVar4 = 0;
                }
            }
        } else {
            *(uint32_t*)(S + 0xd8) = 1;
            iVar4 = 0;
        }
    }
    return iVar4;
}

// 0x670854 — observed shape
// Post-merge driver: executes the 0x66c4b7 dedup loop (up to 0x100 rounds),
// then 0x66ec0a, the vtable pass 0x10, 0x66faae, 0x670008 and 0x67023c.
int32_t FUN_00670854(void* self) {
    uint8_t* S = (uint8_t*)self;
    int32_t iVar1;
    uint32_t uVar2;
    iVar1 = FUN_00666c6a();
    if (((-1 < iVar1) && (iVar1 = FUN_0066e543(self), -1 < iVar1)) &&
        (iVar1 = FUN_00668498(1), -1 < iVar1)) {
        uVar2 = 0;
        do {
            iVar1 = FUN_0066c4b7(1);
            if (iVar1 != 0) {
                if (iVar1 < 0) return iVar1;
                if (iVar1 == 1) break;
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < 0x100);
        iVar1 = FUN_00666ea3();
        if (((-1 < iVar1) && (iVar1 = FUN_0066ec0a(self), -1 < iVar1)) &&
            ((iVar1 = (*(int32_t (**)(void*))(*(uint32_t*)S + 0x10))(self), -1 < iVar1 &&
              ((iVar1 = FUN_00668498(0), -1 < iVar1 && (iVar1 = FUN_0066faae(self), -1 < iVar1)))))) {
            *(uint32_t*)(S + 0xdc) = 1;
            iVar1 = FUN_006686e2();
            if ((-1 < iVar1) &&
                (((((iVar1 = FUN_00670008(self), -1 < iVar1 && (iVar1 = FUN_00660ba6(), -1 < iVar1)) &&
                    (iVar1 = (*(int32_t (**)(void*))(*(uint32_t*)S + 0x14))(self), -1 < iVar1)) &&
                   ((iVar1 = (*(int32_t (**)(void*))(*(uint32_t*)S + 0x18))(self), -1 < iVar1 &&
                     (iVar1 = FUN_0065e4f2(), -1 < iVar1)))) &&
                  ((iVar1 = FUN_00664b28(), -1 < iVar1 &&
                    ((iVar1 = FUN_0067023c(self), -1 < iVar1 && (iVar1 = FUN_00668a1e(), -1 < iVar1)))))))) {
                iVar1 = 0;
            }
        }
    }
    return iVar1;
}

// 0x67095f — observed shape
// Clears the two pipeline-dirty flags, reports 0 through param_1, and runs the
// 0x6705d6 then 0x670854 stages.
int32_t FUN_0067095f(void* self, uint32_t* param_1) {
    uint8_t* S = (uint8_t*)self;
    int32_t iVar1;
    *(uint32_t*)(S + 0xd8) = 0;
    *(uint32_t*)(S + 0xdc) = 0;
    if (param_1 != nullptr) *param_1 = 0;
    iVar1 = FUN_006705d6(self);
    if (-1 < iVar1) {
        iVar1 = FUN_00670854(self);
        if (-1 < iVar1) iVar1 = 0;
    }
    return iVar1;
}

// 0x67099c — observed shape
// Vtable/type-descriptor initializer for the pipeline object.
void FUN_0067099c(void* self, uint32_t param_1) {
    uint32_t* S = (uint32_t*)self;
    FUN_006a0152();
    S[0x56] = param_1;
    S[0] = (uint32_t)(uintptr_t)&PTR_FUN_006ee5d0;
    S[0x3c] = (uint32_t)(uintptr_t)&PTR_s_Position_0071fdc8;
    S[0x3d] = (uint32_t)(uintptr_t)&PTR_s_Tessfactor_00720008;
    S[0x3e] = (uint32_t)(uintptr_t)&PTR_s_Color_007202b8;
}

// 0x670ae4 — observed shape
// Validates the 4 vertex-element slots (0xb/0xd layout, or 0x1/0x5 layout when
// flag 0x40 is set); every inconsistency is reported through FUN_006626da.
int32_t FUN_00670ae4(void* self) {
    int32_t* S = (int32_t*)self;
    int32_t iVar1, iVar2, iVar5;
    uint32_t uVar3;
    int32_t local_64[16];
    int32_t local_24[8];

    if (S[0x56] != 0) return 0;
    local_24[7] = 0;
    local_24[6] = 0;
    local_24[4] = 0;
    if ((*(uint8_t*)(S + 0x1c) & 0x40) == 0) {
        for (int32_t k = 0; k < 16; k = k + 1) local_64[k] = 0;
        local_24[0] = 0;
        local_24[1] = 0;
        local_24[2] = 0;
        local_24[3] = 0;
        if (S[2] != 0) {
            do {
                int32_t nd = *(int32_t*)(S[5] + local_24[6] * 4);
                if ((*(uint8_t*)(*(int32_t*)(S[4] + *(int32_t*)(nd + 4) * 4) + 4) & 0x20) != 0) {
                    local_24[5] = (**(int32_t (***)(int32_t))(S[0] + 0x54))(*(int32_t*)(nd + 0x6c));
                    uVar3 = (**(uint32_t (***)(int32_t))(S[0] + 0x58))(*(int32_t*)(nd + 0x6c));
                    if (local_24[5] == 0xb) {
                        if (uVar3 < 4) {
                            local_64[*(int32_t*)(nd + 0x10) + (int32_t)uVar3 * 4] = 1;
                            local_24[uVar3] = *(int32_t*)(nd + 0x60);
                        }
                    } else if (((local_24[5] == 0xd) && (uVar3 == 0)) && (*(int32_t*)(nd + 0x10) != 0) &&
                               (local_24[4] == 0)) {
                        FUN_006626da();
                        local_24[4] = 1;
                        local_24[7] = 1;
                    }
                }
                local_24[6] = local_24[6] + 1;
            } while ((uint32_t)local_24[6] < (uint32_t)S[2]);
        }
        local_24[4] = 0;
        local_24[5] = 1;
        for (uint32_t u = 0; u < 4; u = u + 1) {
            iVar1 = 0;
            for (int32_t k = 0; k < 4; k = k + 1) {
                if (local_64[u * 4 + k] != 0) iVar1 = iVar1 + 1;
            }
            if (iVar1 == 0) {
                if (u == 0) {
                    FUN_006626da();
                    local_24[7] = 1;
                }
                local_24[4] = 1;
            } else {
                if (iVar1 != 4) {
                    FUN_006626da();
                    local_24[7] = 1;
                }
                if (local_24[4] != 0) local_24[5] = 0;
            }
        }
        if (local_24[5] != 0) goto LAB_00670d06;
    } else {
        local_24[0] = 0;
        local_24[1] = 0;
        local_24[2] = 0;
        local_24[5] = 0;
        local_24[3] = 0;
        if (S[2] != 0) {
            do {
                int32_t nd = *(int32_t*)(S[5] + local_24[6] * 4);
                if ((*(uint8_t*)(*(int32_t*)(S[4] + *(int32_t*)(nd + 4) * 4) + 4) & 0x20) != 0) {
                    iVar1 = (**(int32_t (***)(int32_t))(S[0] + 0x54))(*(int32_t*)(nd + 0x6c));
                    iVar2 = (**(int32_t (***)(int32_t))(S[0] + 0x58))(*(int32_t*)(nd + 0x6c));
                    if (iVar1 == 1) {
                        if (iVar2 == 0) {
                            local_24[*(int32_t*)(nd + 0x10)] = 1;
                            local_24[4] = *(int32_t*)(nd + 0x60);
                        }
                    } else if (((iVar1 == 5) && (iVar2 == 0)) &&
                               ((*(int32_t*)(nd + 0x10) != 0 && (local_24[5] == 0)))) {
                        FUN_006626da();
                        local_24[5] = 1;
                        local_24[7] = 1;
                    }
                }
                local_24[6] = local_24[6] + 1;
            } while ((uint32_t)local_24[6] < (uint32_t)S[2]);
        }
        iVar5 = 0;
        for (uint32_t u = 0; u < 4; u = u + 1) {
            if (local_24[u] != 0) iVar5 = iVar5 + 1;
        }
        if (iVar5 == 4) goto LAB_00670d06;
    }
    FUN_006626da();
    local_24[7] = 1;
LAB_00670d06:
    return (uint32_t)(-(int32_t)(local_24[7] != 0)) & 0x80004005;
}

// 0x670d47 — observed shape
// Maps a declaration (vtable +0x54/+0x58) to a stream role (param_2/3/4).
int32_t FUN_00670d47(void* self, int32_t param_1, uint32_t* param_2,
                     uint32_t* param_3, uint32_t* param_4) {
    int32_t* S = (int32_t*)self;
    int32_t iVar1;
    uint32_t uVar2;
    uint32_t uVar3;

    iVar1 = (**(int32_t (***)(int32_t))(S[0] + 0x54))(*(int32_t*)(param_1 + 0x6c));
    uVar2 = (**(uint32_t (***)(int32_t))(S[0] + 0x58))(*(int32_t*)(param_1 + 0x6c));
    *param_2 = uVar2;
    if ((*(uint8_t*)((uint8_t*)S + 0x1c) & 0x40) == 0) {
        uVar3 = 0;
        if (iVar1 == 0xb) {
            if (3 < uVar2) return 0x80004005;
            *param_3 = 8;
        } else if (iVar1 == 0xd) {
            if (uVar2 != 0) return 0x80004005;
            uVar3 = 1;
            *param_3 = 9;
        } else if (iVar1 == 0x11) {
            if (uVar2 != 0) return 0x80004005;
            *param_3 = 0x11;
            *param_2 = 1;
        } else if (iVar1 == 0x12) {
            if (uVar2 != 0) return 0x80004005;
            *param_3 = 0x11;
            *param_2 = 0;
        } else {
            if (iVar1 != 0xffff) return 0x80004005;
            *param_3 = 0;
            uVar3 = 0;
        }
        if (param_4 == nullptr) return 0;
        *param_4 = uVar3;
        return 0;
    }
    if (param_4 != nullptr) *param_4 = 0;
    if (iVar1 == 5) {
        if ((*param_2 != 0) || (param_4 == nullptr)) goto LAB_00670da3;
        *param_4 = 1;
    }
    if (iVar1 == 0xffff) {
        *param_3 = 0;
        return 0;
    }
LAB_00670da3:
    *param_3 = 6;
    *param_2 = *(uint32_t*)(param_1 + 0xc);
    return 0;
}

// 0x670e35 — observed shape
// Variant role mapping without the flag-0x40 branch and without param_4.
int32_t FUN_00670e35(void* self, int32_t param_1, uint32_t* param_2, uint32_t* param_3) {
    int32_t* S = (int32_t*)self;
    int32_t iVar1;
    uint32_t uVar2;

    iVar1 = (**(int32_t (***)(int32_t))(S[0] + 0x54))(*(int32_t*)(param_1 + 0x6c));
    if (iVar1 == 0xffff) {
        *param_3 = 0;
        uVar2 = (**(uint32_t (***)(int32_t))(S[0] + 0x58))(*(int32_t*)(param_1 + 0x6c));
    } else {
        if (iVar1 == 0x11) {
            *param_3 = 0x11;
            *param_2 = 1;
            return 0;
        }
        if (iVar1 == 0x12) {
            *param_3 = 0x11;
            *param_2 = 0;
            return 0;
        }
        *param_3 = 1;
        uVar2 = *(uint32_t*)(param_1 + 0xc);
    }
    *param_2 = uVar2;
    return 0;
}

// 0x670eac — observed shape
// Folds duplicate 0x11/0x12 nodes: keeps the first of each, renumbers the rest
// downward so the highest free slot is reused.
int32_t FUN_00670eac(void* self) {
    int32_t* S = (int32_t*)self;
    int32_t* piVar1;
    uint32_t* puVar2;
    int32_t iVar3, iVar6, iVar7;
    uint32_t uVar4, uVar5, uVar8;
    uint32_t local_14, local_10, local_c, local_8;

    local_c = 0xffffffff;
    local_10 = 0xffffffff;
    local_14 = 0;
    if (S[2] != 0) {
        do {
            int32_t iVar6off = local_14 * 4;
            int32_t nd = *(int32_t*)(iVar6off + S[5]);
            if ((*(uint8_t*)(*(int32_t*)(S[4] + *(int32_t*)(nd + 4) * 4) + 4) & 0x10) != 0) {
                int32_t kind = *(int32_t*)(nd + 0x6c);
                if (kind == 0x11 || kind == 0x12) {
                    puVar2 = *(uint32_t**)(iVar6off + S[5]);
                    *puVar2 = *puVar2 & 0x40000000;
                    if (**(int32_t**)(iVar6off + S[5]) == 0) {
                        nd = *(int32_t*)(iVar6off + S[5]);
                        iVar3 = *(int32_t*)(nd + 0x6c);
                        if (iVar3 == 0x11) {
                            if (local_c != 0xffffffff) goto LAB_00670fa2;
                            local_c = local_14;
                        }
                        if (iVar3 == 0x12) {
                            if (local_10 == 0xffffffff) {
                                local_10 = local_14;
                                goto LAB_00670f4c;
                            }
                            nd = *(int32_t*)(S[5] + iVar6off);
                            local_8 = *(uint32_t*)(*(int32_t*)(S[5] + local_10 * 4) + 0xc);
LAB_00670f9f:
                            *(uint32_t*)(nd + 0xc) = local_8;
                        } else {
LAB_00670f4c:
                            uVar4 = *(uint32_t*)(nd + 0xc);
                            local_8 = 0xffffffff;
                            uVar8 = 0;
                            if (S[2] != 0) {
                                do {
                                    int32_t n2 = *(int32_t*)(S[5] + uVar8 * 4);
                                    if ((*(uint8_t*)(*(int32_t*)(S[4] + *(int32_t*)(n2 + 4) * 4) + 4) & 0x10) != 0) {
                                        uVar5 = *(uint32_t*)(n2 + 0xc);
                                        if (uVar4 < uVar5) {
                                            if ((int32_t)local_8 <= (int32_t)uVar5) local_8 = uVar5;
                                            piVar1 = (int32_t*)(*(int32_t*)(S[5] + uVar8 * 4) + 0xc);
                                            *piVar1 = *piVar1 - 1;
                                        }
                                    }
                                    uVar8 = uVar8 + 1;
                                } while (uVar8 < (uint32_t)S[2]);
                                if (local_8 != 0xffffffff) {
                                    nd = *(int32_t*)(iVar6off + S[5]);
                                    goto LAB_00670f9f;
                                }
                            }
                        }
                    }
                }
            }
LAB_00670fa2:
            local_14 = local_14 + 1;
        } while (local_14 < (uint32_t)S[2]);
    }
    return 0;
}

// 0x670fb9 — observed shape
// Uploads every 0x20800000 record, drops 0x100-flagged node types, then runs
// the 0x18 sub-passes and the vtable +0x98 hook.
int32_t FUN_00670fb9(void* self) {
    uint32_t* S = (uint32_t*)self;
    uint32_t* puVar1;
    uint32_t uVar2, uVar5;
    bool bVar3;
    int32_t iVar4;
    uint32_t local_c;

    if (S[0x17] != 0) {
        bVar3 = false;
        S[0x3f] = 0;
        if (S[3] != 0) {
            do {
                puVar1 = *(uint32_t**)(S[6] + S[0x3f] * 4);
                S[0x40] = (int32_t)(uintptr_t)puVar1;
                if ((*puVar1 & 0xfff00000) == 0x20800000) {
                    iVar4 = FUN_00695e74();
                    if (iVar4 < 0) return iVar4;
                    bVar3 = bVar3 || (iVar4 == 0);
                }
                S[0x3f] = S[0x3f] + 1;
            } while ((uint32_t)S[0x3f] < (uint32_t)S[3]);
            if (bVar3) FUN_006959c5();
        }
    }
    if (S[0xc] != 0) {
        local_c = 0;
        do {
            if (0xf < local_c) goto LAB_006710b5;
            uVar2 = S[3];
            uVar5 = 0;
            bVar3 = true;
            if (uVar2 != 0) {
                do {
                    S[0x40] = *(int32_t*)(S[6] + uVar5 * 4);
                    iVar4 = FUN_0069632a();
                    if (iVar4 < 0) return iVar4;
                    if (iVar4 == 0) bVar3 = false;
                    iVar4 = FUN_0065db2e(*(int32_t*)(S[0x40]));
                    if (iVar4 < 0) return iVar4;
                    *(uint32_t*)(uintptr_t)S[0x40] = 0;
                    uVar5 = uVar5 + 1;
                } while (uVar5 < uVar2);
            }
            iVar4 = FUN_0065e4f2();
            if (iVar4 < 0) return iVar4;
            local_c = local_c + 1;
        } while (!bVar3);
        if (0xf < local_c) {
LAB_006710b5:
            uVar2 = S[3];
            uVar5 = 0;
            bVar3 = true;
            if (uVar2 != 0) {
                do {
                    S[0x40] = *(int32_t*)(S[6] + uVar5 * 4);
                    iVar4 = FUN_0069632a();
                    if (iVar4 < 0) return iVar4;
                    if (iVar4 == 0) { FUN_006626da(); bVar3 = false; }
                    iVar4 = FUN_0065db2e(*(int32_t*)(S[0x40]));
                    if (iVar4 < 0) return iVar4;
                    *(uint32_t*)(uintptr_t)S[0x40] = 0;
                    uVar5 = uVar5 + 1;
                } while (uVar5 < uVar2);
            }
            iVar4 = FUN_0065e4f2();
            if (iVar4 < 0) return iVar4;
            if (!bVar3) return -0x7fffbffb;
        }
    }
    if (((*(uint8_t*)((uint8_t*)S + 0x1c) & 0x40) == 0) &&
        (iVar4 = (*(int32_t (**)(void*))(*(uint32_t*)S + 0x98))(self), iVar4 < 0)) {
        return iVar4;
    }
    if (S[0x18] != 0) {
        iVar4 = FUN_006a2842();
        if (iVar4 < 0) return iVar4;
        FUN_006959c5();
        iVar4 = FUN_00664b28();
        if (iVar4 < 0) return iVar4;
        iVar4 = FUN_0069de84();
        if (iVar4 < 0) return iVar4;
    }
    return 0;
}

// 0x6711a3 — observed shape
// Creates the vertex declaration/stream binding for a 0x200000/0x400000/
// 0x800000 format through FUN_006a48dd/FUN_006a2b66 + vtable +100.
int32_t FUN_006711a3(void* self, int32_t param_1) {
    int32_t* S = (int32_t*)self;
    int32_t iVar1;
    uint32_t uVar2;

    if (S[0x56] == 0) {
        iVar1 = FUN_006a48dd(0x200001f);
        if (-1 < iVar1) {
            iVar1 = *(int32_t*)(param_1 + 0x3c);
            if (iVar1 == 0x200000) {
                uVar2 = 0x90000000;
            } else if (iVar1 == 0x400000) {
                uVar2 = 0xa0000000;
            } else {
                if (iVar1 != 0x800000) {
                    FUN_006626da();
                    return -0x7fffbffb;
                }
                uVar2 = 0x98000000;
            }
            iVar1 = FUN_006a2b66(uVar2);
            if (((-1 < iVar1) &&
                 (iVar1 = (**(int32_t (***)(uint32_t, uint32_t, uint32_t))(S[0] + 100))(
                      (*(uint32_t*)(param_1 + 0xc) & 0x7ff) | 0xa0000800, 0xf0000, 0), -1 < iVar1)) &&
                (iVar1 = FUN_0069fcf5(), -1 < iVar1)) {
                iVar1 = 0;
            }
        }
    } else {
        iVar1 = 0;
    }
    return iVar1;
}

