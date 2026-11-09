// UNVERIFIED decompiler-derived reconstruction — cl 13.10.3077 absent on this host;
// no PASS / byte-match claim. Source: analysis/pseudocode/functions/0x6ae350.c .. 0x6af9ad.c
// (zlib-style deflate tree/bit-writer internals; original names not invented).
#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <windows.h>

// ---- corpus callees outside this batch ------------------------------------
void FUN_006ae2f0(int*);              // corpus label, body not in this batch
void FUN_006ae3b0(int*);              // corpus label, body not in this batch
void FUN_006b2a1a(int, void*);        // corpus label, body not in this batch

// ---- corpus callees inside this batch -------------------------------------
// Receiver registers are surfaced as an explicit self parameter; operands the
// provider left implicit in registers get trailing defaults (see call sites).
void FUN_006ae553(void* self = nullptr);
void FUN_006ae5b1(int k, void* self = nullptr, uint16_t* freq_base = nullptr);
void FUN_006ae663(void* self = nullptr, int* tbl = nullptr);
void FUN_006ae8d9(int lx = 0, void* self = nullptr, uint8_t* ltree = nullptr);
void FUN_006ae81b(uint8_t* tree, void* self = nullptr, int max_code = 0);
void FUN_006aed76(void* self, int param_1, int param_2, int param_3);
void FUN_006aefb1(void* self, uint8_t* tree1, uint8_t* tree2);
void FUN_006af365(void* self = nullptr);
int32_t FUN_006af3ba(void* self = nullptr);
void FUN_006af411(int param_1, uint32_t in_ECX_value = 0, uint8_t* in_EDX_data = nullptr);
void FUN_006af48b(int last, uint8_t* tree = nullptr, int16_t* bl = nullptr);
void FUN_006af4fb(int* param_1, void* self = nullptr);
void FUN_006af6de(void* self = nullptr);
void FUN_006af738(int param_1, uint32_t param_2, uint32_t param_3, int param_4);
void FUN_006af97b(uint32_t param_1, int param_2, int param_3);

// ---- corpus data labels ---------------------------------------------------
extern uint8_t DAT_006f4344[];   // byte code-length order table
extern uint8_t DAT_006f4a50[];   // extra-bit length table
extern uint8_t DAT_006f484f[];   // distance code table (index <= 0x100)
extern uint8_t DAT_006f4950[];   // distance code table (index >  0x100)
extern uint8_t DAT_006f4208[];   // extra bits per length code
extern uint8_t DAT_006f4b50[];   // base length per length code
extern uint8_t DAT_006f4280[];   // extra bits per distance code
extern uint8_t DAT_006f4bc8[];   // base distance per distance code
extern uint8_t DAT_006f47d8[];   // static literal/length tree image
extern uint8_t DAT_006f4358[];   // static distance tree image

// 0x6ae350 — observed shape: fseek to param_4 on FILE* at param_2+0xc, then
// fwrite; failures store 0x41/0x42 in status slot 5 of *(int*)param_1 and
// re-enter the same object through vtable slot 0.
void FUN_006ae350(int* param_1, int param_2, void* param_3, long param_4, size_t param_5) {
    FILE* fp = *(FILE**)((char*)(intptr_t)param_2 + 0xc);
    if (fseek(fp, param_4, 0) != 0) {
        uint32_t* vt = *(uint32_t**)param_1;
        vt[5] = 0x41;
        ((void (*)(int*))(*vt))(param_1);
    }
    size_t wrote = fwrite(param_3, 1, param_5, fp);
    if (wrote != param_5) {
        uint32_t* vt = *(uint32_t**)param_1;
        vt[5] = 0x42;
        ((void (*)(int*))(*vt))(param_1);
    }
    return;
}

// 0x6ae3d0 — observed shape: tmpfile() into slot 3 of param_2, three callback
// slots installed; on failure status 0x3f at obj+0x14, 0x50 zero bytes at
// obj+0x18, then dispatch slot 0 of the object.
void FUN_006ae3d0(int* param_1, uint32_t* param_2) {
    FILE* f = tmpfile();
    param_2[3] = (uint32_t)(uintptr_t)f;
    if (f == nullptr) {
        int obj = *param_1;
        *(uint32_t*)(obj + 0x14) = 0x3f;
        strncpy((char*)(obj + 0x18), "", 0x50);
        ((void (*)(int*))*(uint32_t*)obj)(param_1);
    }
    param_2[0] = (uint32_t)(uintptr_t)&FUN_006ae2f0;
    param_2[1] = (uint32_t)(uintptr_t)&FUN_006ae350;
    param_2[2] = (uint32_t)(uintptr_t)&FUN_006ae3b0;
    return;
}

// 0x6ae438 — observed shape: adler32 over chunks of 0x15b0 bytes, 16-way
// unrolled main body, both accumulators reduced modulo 0xfff1; a null buffer
// returns 1 with the high half left as the incoming high 16 bits.
uint32_t FUN_006ae438(uint32_t param_1, uint8_t* param_2, uint32_t param_3) {
    uint32_t uVar3 = param_1 & 0xffff;
    param_1 = param_1 >> 0x10;
    if (param_2 == (uint8_t*)0x0) {
        uVar3 = 1;
    } else {
        while (param_3 != 0) {
            uint32_t uVar2 = 0x15b0;
            if (param_3 < 0x15b0) {
                uVar2 = param_3;
            }
            param_3 = param_3 - uVar2;
            if (0xf < (int32_t)uVar2) {
                uint32_t uVar1 = uVar2 >> 4;
                uVar2 = uVar2 + uVar1 * -0x10;
                do {
                    int32_t iVar4 = (int32_t)(uVar3 + *param_2);
                    int32_t iVar5 = iVar4 + (uint32_t)param_2[1];
                    int32_t iVar6 = iVar5 + (uint32_t)param_2[2];
                    int32_t iVar7 = iVar6 + (uint32_t)param_2[3];
                    int32_t iVar8 = iVar7 + (uint32_t)param_2[4];
                    int32_t iVar9 = iVar8 + (uint32_t)param_2[5];
                    int32_t iVar10 = iVar9 + (uint32_t)param_2[6];
                    int32_t iVar11 = iVar10 + (uint32_t)param_2[7];
                    int32_t iVar12 = iVar11 + (uint32_t)param_2[8];
                    int32_t iVar13 = iVar12 + (uint32_t)param_2[9];
                    int32_t iVar14 = iVar13 + (uint32_t)param_2[10];
                    int32_t iVar15 = iVar14 + (uint32_t)param_2[0xb];
                    int32_t iVar16 = iVar15 + (uint32_t)param_2[0xc];
                    int32_t iVar17 = iVar16 + (uint32_t)param_2[0xd];
                    int32_t iVar18 = iVar17 + (uint32_t)param_2[0xe];
                    uVar3 = (uint32_t)(iVar18 + (uint32_t)param_2[0xf]);
                    param_1 = param_1 + (uint32_t)(iVar4 + iVar5 + iVar6 + iVar7 + iVar8 + iVar9 +
                                                   iVar10 + iVar11 + iVar12 + iVar13 + iVar14 +
                                                   iVar15 + iVar16 + iVar17 + iVar18) + uVar3;
                    param_2 = param_2 + 0x10;
                    uVar1 = uVar1 - 1;
                } while (uVar1 != 0);
            }
            for (; uVar2 != 0; uVar2 = uVar2 - 1) {
                uVar3 = uVar3 + *param_2;
                param_2 = param_2 + 1;
                param_1 = param_1 + uVar3;
            }
            uVar3 = uVar3 % 0xfff1;
            param_1 = param_1 % 0xfff1;
        }
        uVar3 = param_1 << 0x10 | uVar3;
    }
    return uVar3;
}

// 0x6ae553 — observed shape: zero three uint16 fields on a 4-byte stride
// (0x11e, 0x1e and 0x13 slots from +0x8c, +0x980 and +0xa74), clear the four
// 32-bit counters, then store 1 at +0x48c.
void FUN_006ae553(void* self) {
    uint8_t* s = (uint8_t*)self;
    uint16_t* p = (uint16_t*)(s + 0x8c);
    for (int32_t i = 0x11e; i != 0; i = i + -1) {
        *p = 0;
        p = p + 2;
    }
    p = (uint16_t*)(s + 0x980);
    for (int32_t i = 0x1e; i != 0; i = i + -1) {
        *p = 0;
        p = p + 2;
    }
    p = (uint16_t*)(s + 0xa74);
    for (int32_t i = 0x13; i != 0; i = i + -1) {
        *p = 0;
        p = p + 2;
    }
    *(uint32_t*)(s + 0x16a4) = 0;
    *(uint32_t*)(s + 0x16a0) = 0;
    *(uint32_t*)(s + 0x16a8) = 0;
    *(uint32_t*)(s + 0x1698) = 0;
    *(uint16_t*)(s + 0x48c) = 1;
    return;
}

// 0x6ae5b1 — observed shape: sift-down over the heap at self+0xb54 (length at
// self+0x1448, depth bytes at self+0x1450); the key array base arrives in EDI
// and is read as uint16 at base + node*4.
void FUN_006ae5b1(int k, void* self_p, uint16_t* freq_base) {
    uint8_t* s = (uint8_t*)self_p;
    int32_t iVar3 = *(int32_t*)(s + 0xb54 + k * 4);
    int32_t heap_len = *(int32_t*)(s + 0x1448);
    int32_t iVar7 = k * 2;
    uint32_t bVar8 = (uint32_t)(iVar7 < heap_len);   // SBORROW4(j, heap_len)
    int32_t iVar5 = iVar7 - heap_len;
    int32_t iVar4 = 0;
    if (iVar7 <= heap_len) {
        do {
            int32_t iVar6 = iVar7;
            if (bVar8 != (uint32_t)(iVar5 < 0)) {
                iVar5 = *(int32_t*)(s + 0xb58 + iVar7 * 4);
                uint16_t uVar1 = *(uint16_t*)((uint8_t*)freq_base + iVar5 * 4);
                uint16_t uVar2 =
                    *(uint16_t*)((uint8_t*)freq_base +
                                 *(int32_t*)(s + 0xb54 + iVar7 * 4) * 4);
                if ((uVar1 < uVar2) ||
                    ((uVar1 == uVar2 &&
                      (*(uint8_t*)(s + iVar5 + 0x1450) <=
                       *(uint8_t*)(s + *(int32_t*)(s + 0xb54 + iVar7 * 4) + 0x1450))))) {
                    iVar6 = iVar7 + 1;
                }
            }
            iVar5 = *(int32_t*)(s + 0xb54 + iVar6 * 4);
            uint16_t uVar1b = *(uint16_t*)((uint8_t*)freq_base + iVar3 * 4);
            uint16_t uVar2b = *(uint16_t*)((uint8_t*)freq_base + iVar5 * 4);
            if ((uVar1b < uVar2b) ||
                ((uVar1b == uVar2b &&
                  (*(uint8_t*)(s + iVar3 + 0x1450) <= *(uint8_t*)(s + iVar5 + 0x1450))))) {
                break;
            }
            *(int32_t*)(s + 0xb54 + k * 4) = iVar5;
            iVar4 = *(int32_t*)(s + 0x1448);
            iVar7 = iVar6 * 2;
            bVar8 = (uint32_t)(iVar7 < iVar4);      // SBORROW4(j, heap_len)
            iVar5 = iVar7 - iVar4;
            k = iVar6;
        } while (iVar7 <= iVar4);
    }
    *(int32_t*)(s + 0xb54 + k * 4) = iVar3;
    return;
}

// 0x6ae663 — observed shape: tree construction helper. tbl[0] is the node
// array base, tbl[1] the max code index and tbl[2] a descriptor whose slots
// 0,1,2,4 are read; it clears eight 32-bit bit-length counters at self+0xb34,
// walks the heap at self+0xb54 down from self+0x144c, derives lengths at
// node*4+2, accumulates self+0x16a0 / self+0x16a4 and finally re-balances the
// length distribution over self+0xb34.
// NEEDS_MANUAL: the three-field blob tbl is a by-value tree_desc image; field
// meaning beyond the observed reads is not stated by the listing.
void FUN_006ae663(void* self_p, int* tbl) {
    uint8_t* s = (uint8_t*)self_p;
    int32_t iVar3 = tbl[1];
    uint32_t local_8 = 0;
    int32_t iVar4 = tbl[0];
    int32_t* piVar13 = (int32_t*)tbl[2];
    int32_t iVar12 = piVar13[0];
    int32_t iVar5 = piVar13[1];
    int32_t iVar6 = piVar13[2];
    uint32_t uVar7 = (uint32_t)piVar13[4];
    uint32_t* puVar14 = (uint32_t*)(s + 0xb34);
    for (int32_t iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar14 = 0;
        puVar14 = puVar14 + 1;
    }
    *(uint16_t*)(iVar4 + 2 + *(int32_t*)(s + 0xb54 + *(int32_t*)(s + 0x144c) * 4) * 4) = 0;
    int32_t iVar9 = *(int32_t*)(s + 0x144c) + 1;
    if (iVar9 < 0x23d) {
        int32_t* local_18 = (int32_t*)(s + 0xb54 + iVar9 * 4);
        int32_t local_20 = 0x23d - iVar9;
        iVar9 = iVar9 + local_20;
        do {
            int32_t iVar8 = *local_18;
            int32_t iVar10 = iVar8 * 4;
            uint32_t uVar11 = (uint32_t)*(uint16_t*)(iVar4 + 2 +
                                                     (uint32_t)*(uint16_t*)(iVar10 + 2 + iVar4) * 4) + 1;
            if ((int32_t)uVar7 < (int32_t)uVar11) {
                local_8 = local_8 + 1;
                uVar11 = uVar7;
            }
            *(int16_t*)(iVar10 + 2 + iVar4) = (int16_t)uVar11;
            if (iVar8 <= iVar3) {
                int16_t* psVar15 = (int16_t*)(s + 0xb34 + uVar11 * 2);
                *psVar15 = *psVar15 + 1;
                int32_t extra = 0;
                if (iVar6 <= iVar8) {
                    extra = *(int32_t*)(iVar5 + (iVar8 - iVar6) * 4);
                }
                uint16_t uVar2 = *(uint16_t*)(iVar10 + iVar4);
                *(int32_t*)(s + 0x16a0) =
                    *(int32_t*)(s + 0x16a0) + (extra + (int32_t)uVar11) * (uint32_t)uVar2;
                if (iVar12 != 0) {
                    *(int32_t*)(s + 0x16a4) =
                        *(int32_t*)(s + 0x16a4) +
                        ((uint32_t)*(uint16_t*)(iVar10 + 2 + iVar12) + (uint32_t)extra) *
                            (uint32_t)uVar2;
                }
            }
            local_18 = local_18 + 1;
            local_20 = local_20 + -1;
        } while (local_20 != 0);
        if (local_8 != 0) {
            uint16_t* local_14 = (uint16_t*)(s + 0xb34 + uVar7 * 2);
            do {
                iVar12 = (int32_t)uVar7 - 1;
                int16_t* psVar15 = (int16_t*)(s + 0xb34 + iVar12 * 2);
                for (; *psVar15 == 0; psVar15 = psVar15 + -1) {
                    iVar12 = iVar12 + -1;
                }
                psVar15 = (int16_t*)(s + 0xb34 + iVar12 * 2);
                *psVar15 = *psVar15 + -1;
                local_8 = local_8 + -2;
                psVar15 = (int16_t*)(s + 0xb36 + iVar12 * 2);
                *psVar15 = *psVar15 + 2;
                *local_14 = *local_14 - 1;
            } while (0 < (int32_t)local_8);
            if (uVar7 != 0) {
                local_8 = uVar7;
                do {
                    int32_t n = (int32_t)(uint32_t)*local_14;
                    if (n != 0) {
                        int32_t* pHeap = (int32_t*)(s + 0xb54 + iVar9 * 4);
                        do {
                            pHeap = pHeap + -1;
                            iVar9 = iVar9 + -1;
                            if (*pHeap <= iVar3) {
                                uint16_t* puVar1 = (uint16_t*)(iVar4 + *pHeap * 4);
                                if (puVar1[1] != local_8) {
                                    *(int32_t*)(s + 0x16a0) =
                                        *(int32_t*)(s + 0x16a0) +
                                        (int32_t)(local_8 - puVar1[1]) * (uint32_t)*puVar1;
                                    puVar1[1] = (uint16_t)local_8;
                                }
                                n = n - 1;
                            }
                        } while (n != 0);
                    }
                    local_8 = local_8 - 1;
                    local_14 = local_14 + -1;
                } while (local_8 != 0);
            }
        }
    }
    return;
}

// 0x6ae81b — observed shape: scan_tree over the node array in EAX with the
// node count in ECX; it reads len at node*4+2 into the run-length counters at
// self+0xa74 (per length), self+0xab4/self+0xab8/self+0xabc, with run limits
// 7/4 or 0x8a/3 depending on whether the first length is zero.
void FUN_006ae81b(uint8_t* tree, void* self_p, int max_code) {
    uint8_t* s = (uint8_t*)self_p;
    uint32_t local_c = 0xffffffff;
    uint16_t uVar2 = *(uint16_t*)(tree + 2);
    int32_t iVar5 = 7;
    int32_t iVar6 = 0;
    int32_t iStack_1c = 4;
    if (uVar2 == 0) {
        iVar5 = 0x8a;
        iStack_1c = 3;
    }
    *(uint16_t*)(tree + 6 + max_code * 4) = 0xffff;
    if (-1 < max_code) {
        uint16_t* local_8 = (uint16_t*)(tree + 6);
        int32_t iVar7 = max_code + 1;
        uint32_t uVar3 = (uint32_t)uVar2;
        do {
            uint32_t uVar4 = (uint32_t)*local_8;
            iVar6 = iVar6 + 1;
            if ((iVar5 <= iVar6) || (uVar3 != uVar4)) {
                if (iVar6 < iStack_1c) {
                    int16_t* psVar1 = (int16_t*)(s + 0xa74 + uVar3 * 4);
                    *psVar1 = *psVar1 + (int16_t)iVar6;
                } else if (uVar3 == 0) {
                    if (iVar6 < 0xb) {
                        *(int16_t*)(s + 0xab8) = *(int16_t*)(s + 0xab8) + 1;
                    } else {
                        *(int16_t*)(s + 0xabc) = *(int16_t*)(s + 0xabc) + 1;
                    }
                } else {
                    if (uVar3 != local_c) {
                        int16_t* psVar1 = (int16_t*)(s + 0xa74 + uVar3 * 4);
                        *psVar1 = *psVar1 + 1;
                    }
                    *(int16_t*)(s + 0xab4) = *(int16_t*)(s + 0xab4) + 1;
                }
                iVar6 = 0;
                if (uVar4 == 0) {
                    iVar5 = 0x8a;
                LAB_006ae8c1:
                    iStack_1c = 3;
                } else if (uVar3 == uVar4) {
                    iVar5 = 6;
                    goto LAB_006ae8c1;
                } else {
                    iVar5 = 7;
                    iStack_1c = 4;
                }
                local_c = uVar3;
            }
            local_8 = local_8 + 2;
            iVar7 = iVar7 + -1;
            uVar3 = uVar4;
        } while (iVar7 != 0);
    }
    return;
}

// 0x6ae8d9 — observed shape: bit-emitter for a code/length pair stream. It
// walks the tree nodes in ECX (len at node*4+2, code at node*4), keeping the
// previous length in local_18 and a pending run count in iVar5, and pushes
// every code through the pending-bit accumulator at self+0x16b0 with the bit
// count at self+0x16b4, flushing two bytes into self+0x8 + self+0x14 whenever
// a field would cross the 16-bit boundary. Run-length extras use the counters
// at self+0xab4/0xab6, 0xab8/0xaba and 0xabc/0xabe. ltree arrives in ECX and
// the last node index in EDX.
void FUN_006ae8d9(int lx, void* self_p, uint8_t* ltree) {
    uint8_t* s = (uint8_t*)self_p;
    uint16_t uVar1 = 0;
    uint8_t bVar2;
    uint32_t uVar3;
    uint16_t uVar4 = 0;
    int32_t iVar5;
    int32_t iVar6;
    uint32_t uVar7;
    int32_t iStack_2c;
    int32_t local_1c;
    uint32_t local_18;
    uint16_t* local_10;
    uint32_t local_c;
    int32_t local_8;

    local_18 = 0xffffffff;
    iVar6 = 7;
    iStack_2c = 4;
    if (*(uint16_t*)(ltree + 2) == 0) {
        iVar6 = 0x8a;
        iStack_2c = 3;
    }
    if (-1 < lx) {
        local_10 = (uint16_t*)(ltree + 6);
        local_1c = lx + 1;
        iVar5 = 0;
        local_c = (uint32_t)*(uint16_t*)(ltree + 2);
        do {
            uVar3 = (uint32_t)*local_10;
            local_8 = iVar5 + 1;
            if ((iVar6 <= local_8) || (local_c != uVar3)) {
                if (local_8 < iStack_2c) {
                    do {
                        uVar7 = (uint32_t)*(uint16_t*)(s + 0xa76 + local_c * 4);
                        bVar2 = (uint8_t)*(int32_t*)(s + 0x16b4);
                        if ((int32_t)(0x10 - uVar7) < *(int32_t*)(s + 0x16b4)) {
                            uVar4 = *(uint16_t*)(s + 0xa74 + local_c * 4);
                            *(uint16_t*)(s + 0x16b0) =
                                *(uint16_t*)(s + 0x16b0) | (uint16_t)(uVar4 << (bVar2 & 0x1f));
                            *(uint8_t*)(*(int32_t*)(s + 8) + *(int32_t*)(s + 0x14)) =
                                *(uint8_t*)(s + 0x16b0);
                            *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                            *(uint8_t*)(*(int32_t*)(s + 0x14) + *(int32_t*)(s + 8)) =
                                *(uint8_t*)(s + 0x16b1);
                            *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                            iVar6 = *(int32_t*)(s + 0x16b4) + -0x10;
                            *(uint16_t*)(s + 0x16b0) =
                                (uint16_t)(uVar4 >> (0x10U - (uint8_t)*(int32_t*)(s + 0x16b4) & 0x1f));
                        } else {
                            iVar6 = *(int32_t*)(s + 0x16b4);
                            *(uint16_t*)(s + 0x16b0) =
                                *(uint16_t*)(s + 0x16b0) |
                                (uint16_t)(*(int16_t*)(s + 0xa74 + local_c * 4) << (bVar2 & 0x1f));
                        }
                        local_8 = local_8 + -1;
                        *(uint32_t*)(s + 0x16b4) = (uint32_t)(iVar6 + (int32_t)uVar7);
                    } while (local_8 != 0);
                } else {
                    if (local_c == 0) {
                        iVar6 = *(int32_t*)(s + 0x16b4);
                        bVar2 = (uint8_t)iVar6;
                        if (local_8 < 0xb) {
                            uVar4 = *(uint16_t*)(s + 0xaba);
                            if ((int32_t)(0x10 - (uint32_t)uVar4) < iVar6) {
                                uVar1 = *(uint16_t*)(s + 0xab8);
                                *(uint16_t*)(s + 0x16b0) =
                                    *(uint16_t*)(s + 0x16b0) | (uint16_t)(uVar1 << (bVar2 & 0x1f));
                                *(uint8_t*)(*(int32_t*)(s + 8) + *(int32_t*)(s + 0x14)) =
                                    *(uint8_t*)(s + 0x16b0);
                                *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                                *(uint8_t*)(*(int32_t*)(s + 0x14) + *(int32_t*)(s + 8)) =
                                    *(uint8_t*)(s + 0x16b1);
                                *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                                iVar6 = *(int32_t*)(s + 0x16b4) + -0x10;
                                *(uint16_t*)(s + 0x16b0) =
                                    (uint16_t)(uVar1 >> (0x10U - (uint8_t)*(int32_t*)(s + 0x16b4) & 0x1f));
                            } else {
                                *(uint16_t*)(s + 0x16b0) =
                                    *(uint16_t*)(s + 0x16b0) |
                                    (uint16_t)(*(int16_t*)(s + 0xab8) << (bVar2 & 0x1f));
                            }
                            iVar6 = iVar6 + (int32_t)(uint32_t)uVar4;
                            iVar5 = iVar5 + -2;
                            *(int32_t*)(s + 0x16b4) = iVar6;
                            if (iVar6 < 0xe) {
                                *(uint16_t*)(s + 0x16b0) =
                                    *(uint16_t*)(s + 0x16b0) |
                                    (uint16_t)(iVar5 << ((uint8_t)iVar6 & 0x1f));
                                iVar6 = iVar6 + 3;
                                goto LAB_006aed3b;
                            }
                            *(uint16_t*)(s + 0x16b0) =
                                *(uint16_t*)(s + 0x16b0) |
                                (uint16_t)(iVar5 << ((uint8_t)iVar6 & 0x1f));
                            *(uint8_t*)(*(int32_t*)(s + 8) + *(int32_t*)(s + 0x14)) =
                                *(uint8_t*)(s + 0x16b0);
                            *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                            *(uint8_t*)(*(int32_t*)(s + 0x14) + *(int32_t*)(s + 8)) =
                                *(uint8_t*)(s + 0x16b1);
                            *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                            uVar4 = (uint16_t)((uint16_t)iVar5 >>
                                               (0x10U - (uint8_t)*(int32_t*)(s + 0x16b4) & 0x1f));
                            iVar6 = *(int32_t*)(s + 0x16b4) + -0xd;
                        } else {
                            uVar4 = *(uint16_t*)(s + 0xabe);
                            if ((int32_t)(0x10 - (uint32_t)uVar4) < iVar6) {
                                uVar1 = *(uint16_t*)(s + 0xabc);
                                *(uint16_t*)(s + 0x16b0) =
                                    *(uint16_t*)(s + 0x16b0) | (uint16_t)(uVar1 << (bVar2 & 0x1f));
                                *(uint8_t*)(*(int32_t*)(s + 8) + *(int32_t*)(s + 0x14)) =
                                    *(uint8_t*)(s + 0x16b0);
                                *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                                *(uint8_t*)(*(int32_t*)(s + 0x14) + *(int32_t*)(s + 8)) =
                                    *(uint8_t*)(s + 0x16b1);
                                *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                                iVar6 = *(int32_t*)(s + 0x16b4) + -0x10;
                                *(uint16_t*)(s + 0x16b0) =
                                    (uint16_t)(uVar1 >> (0x10U - (uint8_t)*(int32_t*)(s + 0x16b4) & 0x1f));
                            } else {
                                *(uint16_t*)(s + 0x16b0) =
                                    *(uint16_t*)(s + 0x16b0) |
                                    (uint16_t)(*(int16_t*)(s + 0xabc) << (bVar2 & 0x1f));
                            }
                            iVar6 = iVar6 + (int32_t)(uint32_t)uVar4;
                            iVar5 = iVar5 + -10;
                            *(int32_t*)(s + 0x16b4) = iVar6;
                            if (iVar6 < 10) {
                                *(uint16_t*)(s + 0x16b0) =
                                    *(uint16_t*)(s + 0x16b0) |
                                    (uint16_t)(iVar5 << ((uint8_t)iVar6 & 0x1f));
                                iVar6 = iVar6 + 7;
                                goto LAB_006aed3b;
                            }
                            *(uint16_t*)(s + 0x16b0) =
                                *(uint16_t*)(s + 0x16b0) |
                                (uint16_t)(iVar5 << ((uint8_t)iVar6 & 0x1f));
                            *(uint8_t*)(*(int32_t*)(s + 8) + *(int32_t*)(s + 0x14)) =
                                *(uint8_t*)(s + 0x16b0);
                            *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                            *(uint8_t*)(*(int32_t*)(s + 0x14) + *(int32_t*)(s + 8)) =
                                *(uint8_t*)(s + 0x16b1);
                            *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                            uVar4 = (uint16_t)((uint16_t)iVar5 >>
                                               (0x10U - (uint8_t)*(int32_t*)(s + 0x16b4) & 0x1f));
                            iVar6 = *(int32_t*)(s + 0x16b4) + -9;
                        }
                    } else {
                        if (local_c != local_18) {
                            uVar7 = (uint32_t)*(uint16_t*)(s + 0xa76 + local_c * 4);
                            bVar2 = (uint8_t)*(int32_t*)(s + 0x16b4);
                            if ((int32_t)(0x10 - uVar7) < *(int32_t*)(s + 0x16b4)) {
                                uVar4 = *(uint16_t*)(s + 0xa74 + local_c * 4);
                                *(uint16_t*)(s + 0x16b0) =
                                    *(uint16_t*)(s + 0x16b0) | (uint16_t)(uVar4 << (bVar2 & 0x1f));
                                *(uint8_t*)(*(int32_t*)(s + 8) + *(int32_t*)(s + 0x14)) =
                                    *(uint8_t*)(s + 0x16b0);
                                *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                                *(uint8_t*)(*(int32_t*)(s + 0x14) + *(int32_t*)(s + 8)) =
                                    *(uint8_t*)(s + 0x16b1);
                                *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                                iVar6 = *(int32_t*)(s + 0x16b4) + -0x10;
                                *(uint16_t*)(s + 0x16b0) =
                                    (uint16_t)(uVar4 >> (0x10U - (uint8_t)*(int32_t*)(s + 0x16b4) & 0x1f));
                            } else {
                                iVar6 = *(int32_t*)(s + 0x16b4);
                                *(uint16_t*)(s + 0x16b0) =
                                    *(uint16_t*)(s + 0x16b0) |
                                    (uint16_t)(*(int16_t*)(s + 0xa74 + local_c * 4) << (bVar2 & 0x1f));
                            }
                            *(uint32_t*)(s + 0x16b4) = (uint32_t)(iVar6 + (int32_t)uVar7);
                            local_8 = iVar5;
                        }
                        uVar4 = *(uint16_t*)(s + 0xab6);
                        iVar6 = *(int32_t*)(s + 0x16b4);
                        if ((int32_t)(0x10 - (uint32_t)uVar4) < iVar6) {
                            uVar1 = *(uint16_t*)(s + 0xab4);
                            *(uint16_t*)(s + 0x16b0) =
                                *(uint16_t*)(s + 0x16b0) | (uint16_t)(uVar1 << ((uint8_t)iVar6 & 0x1f));
                            *(uint8_t*)(*(int32_t*)(s + 8) + *(int32_t*)(s + 0x14)) =
                                *(uint8_t*)(s + 0x16b0);
                            *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                            *(uint8_t*)(*(int32_t*)(s + 0x14) + *(int32_t*)(s + 8)) =
                                *(uint8_t*)(s + 0x16b1);
                            *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                            iVar6 = *(int32_t*)(s + 0x16b4) + -0x10;
                            *(uint16_t*)(s + 0x16b0) =
                                (uint16_t)(uVar1 >> (0x10U - (uint8_t)*(int32_t*)(s + 0x16b4) & 0x1f));
                        } else {
                            *(uint16_t*)(s + 0x16b0) =
                                *(uint16_t*)(s + 0x16b0) |
                                (uint16_t)(*(int16_t*)(s + 0xab4) << ((uint8_t)iVar6 & 0x1f));
                        }
                        iVar6 = iVar6 + (int32_t)(uint32_t)uVar4;
                        local_8 = local_8 + -3;
                        *(int32_t*)(s + 0x16b4) = iVar6;
                        if (iVar6 < 0xf) {
                            *(uint16_t*)(s + 0x16b0) =
                                *(uint16_t*)(s + 0x16b0) |
                                (uint16_t)(local_8 << ((uint8_t)iVar6 & 0x1f));
                            iVar6 = iVar6 + 2;
                            goto LAB_006aed3b;
                        }
                        *(uint16_t*)(s + 0x16b0) =
                            *(uint16_t*)(s + 0x16b0) |
                            (uint16_t)(local_8 << ((uint8_t)iVar6 & 0x1f));
                        *(uint8_t*)(*(int32_t*)(s + 8) + *(int32_t*)(s + 0x14)) =
                            *(uint8_t*)(s + 0x16b0);
                        *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                        *(uint8_t*)(*(int32_t*)(s + 0x14) + *(int32_t*)(s + 8)) =
                            *(uint8_t*)(s + 0x16b1);
                        *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                        uVar4 = (uint16_t)((uint16_t)local_8 >>
                                           (0x10U - (uint8_t)*(int32_t*)(s + 0x16b4) & 0x1f));
                        iVar6 = *(int32_t*)(s + 0x16b4) + -0xe;
                    }
                    *(uint16_t*)(s + 0x16b0) = uVar4;
                LAB_006aed3b:
                    *(int32_t*)(s + 0x16b4) = iVar6;
                }
            LAB_006aed41:
                local_8 = 0;
                local_18 = local_c;
                if (uVar3 == 0) {
                    iVar6 = 0x8a;
                } else {
                    if (local_c != uVar3) {
                        iVar6 = 7;
                        iStack_2c = 4;
                        goto LAB_006aed64;
                    }
                    iVar6 = 6;
                }
                iStack_2c = 3;
            }
        LAB_006aed64:
            local_10 = local_10 + 2;
            local_1c = local_1c + -1;
            iVar5 = local_8;
            local_c = uVar3;
        } while (local_1c != 0);
    }
    return;
}

// 0x6aed76 — observed shape: emits three fixed-width fields (param_1-0x101 at
// 5 bits, param_2-1 at 5 bits, param_3-4 at 4 bits) plus param_3 three-bit
// lengths taken from DAT_006f4344, then runs the two bit-stream passes; all
// pending-bit state lives at self+0x16b0/0x16b4 and flushing copies two bytes
// to self+0x8 + self+0x14.
void FUN_006aed76(void* self_p, int param_1, int param_2, int param_3) {
    uint8_t* s = (uint8_t*)self_p;
    uint16_t uVar1;
    int32_t iVar2;
    int32_t iVar3 = *(int32_t*)(s + 0x16b4);

    if (iVar3 < 0xc) {
        *(uint16_t*)(s + 0x16b0) =
            *(uint16_t*)(s + 0x16b0) | (uint16_t)(param_1 + -0x101 << ((uint8_t)iVar3 & 0x1f));
        *(int32_t*)(s + 0x16b4) = iVar3 + 5;
    } else {
        *(uint16_t*)(s + 0x16b0) =
            *(uint16_t*)(s + 0x16b0) | (uint16_t)(param_1 + -0x101 << ((uint8_t)iVar3 & 0x1f));
        *(uint8_t*)(*(int32_t*)(s + 0x14) + *(int32_t*)(s + 8)) = *(uint8_t*)(s + 0x16b0);
        *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
        *(uint8_t*)(*(int32_t*)(s + 0x14) + *(int32_t*)(s + 8)) = *(uint8_t*)(s + 0x16b1);
        iVar3 = *(int32_t*)(s + 0x16b4);
        *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
        *(int32_t*)(s + 0x16b4) = iVar3 + -0xb;
        *(uint16_t*)(s + 0x16b0) =
            (uint16_t)((uint16_t)(param_1 + -0x101) >> (0x10U - (uint8_t)iVar3 & 0x1f));
    }
    iVar3 = *(int32_t*)(s + 0x16b4);
    if (iVar3 < 0xc) {
        *(uint16_t*)(s + 0x16b0) =
            *(uint16_t*)(s + 0x16b0) | (uint16_t)(param_2 + -1 << ((uint8_t)iVar3 & 0x1f));
        *(int32_t*)(s + 0x16b4) = iVar3 + 5;
    } else {
        *(uint16_t*)(s + 0x16b0) =
            *(uint16_t*)(s + 0x16b0) | (uint16_t)(param_2 + -1 << ((uint8_t)iVar3 & 0x1f));
        *(uint8_t*)(*(int32_t*)(s + 0x14) + *(int32_t*)(s + 8)) = *(uint8_t*)(s + 0x16b0);
        *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
        *(uint8_t*)(*(int32_t*)(s + 0x14) + *(int32_t*)(s + 8)) = *(uint8_t*)(s + 0x16b1);
        iVar3 = *(int32_t*)(s + 0x16b4);
        *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
        *(int32_t*)(s + 0x16b4) = iVar3 + -0xb;
        *(uint16_t*)(s + 0x16b0) =
            (uint16_t)((uint16_t)(param_2 + -1) >> (0x10U - (uint8_t)iVar3 & 0x1f));
    }
    iVar3 = *(int32_t*)(s + 0x16b4);
    if (iVar3 < 0xd) {
        *(uint16_t*)(s + 0x16b0) =
            *(uint16_t*)(s + 0x16b0) | (uint16_t)(param_3 + -4 << ((uint8_t)iVar3 & 0x1f));
        *(int32_t*)(s + 0x16b4) = iVar3 + 4;
    } else {
        *(uint16_t*)(s + 0x16b0) =
            *(uint16_t*)(s + 0x16b0) | (uint16_t)(param_3 + -4 << ((uint8_t)iVar3 & 0x1f));
        *(uint8_t*)(*(int32_t*)(s + 0x14) + *(int32_t*)(s + 8)) = *(uint8_t*)(s + 0x16b0);
        *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
        *(uint8_t*)(*(int32_t*)(s + 0x14) + *(int32_t*)(s + 8)) = *(uint8_t*)(s + 0x16b1);
        iVar3 = *(int32_t*)(s + 0x16b4);
        *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
        *(int32_t*)(s + 0x16b4) = iVar3 + -0xc;
        *(uint16_t*)(s + 0x16b0) =
            (uint16_t)((uint16_t)(param_3 + -4) >> (0x10U - (uint8_t)iVar3 & 0x1f));
    }
    iVar3 = 0;
    if (0 < param_3) {
        do {
            iVar2 = *(int32_t*)(s + 0x16b4);
            if (iVar2 < 0xe) {
                *(uint16_t*)(s + 0x16b0) =
                    *(uint16_t*)(s + 0x16b0) |
                    (uint16_t)(*(int16_t*)(s + 0xa76 +
                                           (uint32_t)DAT_006f4344[iVar3] * 4) <<
                               ((uint8_t)iVar2 & 0x1f));
                *(int32_t*)(s + 0x16b4) = iVar2 + 3;
            } else {
                uVar1 = *(uint16_t*)(s + 0xa76 +
                                     (uint32_t)DAT_006f4344[iVar3] * 4);
                *(uint16_t*)(s + 0x16b0) =
                    *(uint16_t*)(s + 0x16b0) | (uint16_t)(uVar1 << ((uint8_t)iVar2 & 0x1f));
                *(uint8_t*)(*(int32_t*)(s + 0x14) + *(int32_t*)(s + 8)) = *(uint8_t*)(s + 0x16b0);
                *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                *(uint8_t*)(*(int32_t*)(s + 0x14) + *(int32_t*)(s + 8)) = *(uint8_t*)(s + 0x16b1);
                iVar2 = *(int32_t*)(s + 0x16b4);
                *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                *(int32_t*)(s + 0x16b4) = iVar2 + -0xd;
                *(uint16_t*)(s + 0x16b0) = (uint16_t)(uVar1 >> (0x10U - (uint8_t)iVar2 & 0x1f));
            }
            iVar3 = iVar3 + 1;
        } while (iVar3 < param_3);
    }
    // Operands of both passes are implicit in registers at this site.
    FUN_006ae8d9();
    FUN_006ae8d9();
    return;
}

// 0x6aefb1 — observed shape: distance/extra-bit emitter. Walks the pending
// length buffer at self+0x1690 (count at self+0x1698, uint16 codes at
// self+0x169c), writing literal/length codes from tree1 (param_1) and distance
// codes from tree2 (param_2); extra bits come from DAT_006f4a50 and the
// DAT_006f4208/DAT_006f4b50 (length) and DAT_006f4280/DAT_006f4bc8 (distance)
// tables. Ends by emitting the end-of-block code from tree1+0x400/0x402 and
// stores that width at self+0x16ac.
void FUN_006aefb1(void* self_p, uint8_t* tree1_p, uint8_t* tree2_p) {
    uint8_t* s = (uint8_t*)self_p;
    uint8_t* const param_1 = tree1_p;
    uint8_t* const param_2 = tree2_p;
    uint16_t* puVar1;
    uint8_t bVar2;
    uint16_t uVar3;
    uint16_t uVar4 = 0;
    uint32_t uVar5;
    int32_t iVar6;
    int32_t iVar7;
    uint32_t uVar8;
    int32_t iVar9;
    uint32_t uVar10;
    uint32_t uVar11;
    uint32_t uVar12;

    uVar5 = 0;
    if (*(int32_t*)(s + 0x1698) != 0) {
        do {
            uVar12 = (uint32_t)*(uint16_t*)(*(int32_t*)(s + 0x169c) + uVar5 * 2);
            uVar11 = (uint32_t)*(uint8_t*)(uVar5 + *(int32_t*)(s + 0x1690));
            uVar5 = uVar5 + 1;
            if (uVar12 == 0) {
                iVar6 = *(int32_t*)(s + 0x16b4);
                puVar1 = (uint16_t*)(param_1 + uVar11 * 4);
                uVar11 = (uint32_t)puVar1[1];
                if ((int32_t)(0x10 - uVar11) < iVar6) {
                    uVar3 = *puVar1;
                    *(uint16_t*)(s + 0x16b0) =
                        *(uint16_t*)(s + 0x16b0) | (uint16_t)(uVar3 << ((uint8_t)iVar6 & 0x1f));
                    *(uint8_t*)(*(int32_t*)(s + 8) + *(int32_t*)(s + 0x14)) =
                        *(uint8_t*)(s + 0x16b0);
                    *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                    *(uint8_t*)(*(int32_t*)(s + 0x14) + *(int32_t*)(s + 8)) =
                        *(uint8_t*)(s + 0x16b1);
                    *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                    iVar6 = *(int32_t*)(s + 0x16b4) + -0x10 + (int32_t)uVar11;
                    *(uint16_t*)(s + 0x16b0) =
                        (uint16_t)(uVar3 >> (0x10U - (uint8_t)*(int32_t*)(s + 0x16b4) & 0x1f));
                } else {
                    *(uint16_t*)(s + 0x16b0) =
                        *(uint16_t*)(s + 0x16b0) | (uint16_t)(*puVar1 << ((uint8_t)iVar6 & 0x1f));
                    iVar6 = iVar6 + (int32_t)uVar11;
                }
            LAB_006af2b1:
                *(int32_t*)(s + 0x16b4) = iVar6;
            } else {
                uVar10 = (uint32_t)DAT_006f4a50[uVar11];
                iVar7 = (int32_t)(uVar10 * 4);
                uVar8 = (uint32_t)*(uint16_t*)(param_1 + iVar7 + 0x406);
                iVar9 = *(int32_t*)(s + 0x16b4);
                if ((int32_t)(0x10 - uVar8) < iVar9) {
                    uVar3 = *(uint16_t*)(param_1 + 0x404 + uVar10 * 4);
                    *(uint16_t*)(s + 0x16b0) =
                        *(uint16_t*)(s + 0x16b0) | (uint16_t)(uVar3 << ((uint8_t)iVar9 & 0x1f));
                    *(uint8_t*)(*(int32_t*)(s + 8) + *(int32_t*)(s + 0x14)) =
                        *(uint8_t*)(s + 0x16b0);
                    *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                    *(uint8_t*)(*(int32_t*)(s + 0x14) + *(int32_t*)(s + 8)) =
                        *(uint8_t*)(s + 0x16b1);
                    *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                    iVar9 = *(int32_t*)(s + 0x16b4) + -0x10;
                    *(uint16_t*)(s + 0x16b0) =
                        (uint16_t)(uVar3 >> (0x10U - (uint8_t)*(int32_t*)(s + 0x16b4) & 0x1f));
                } else {
                    *(uint16_t*)(s + 0x16b0) =
                        *(uint16_t*)(s + 0x16b0) |
                        (uint16_t)(*(int16_t*)(param_1 + 0x404 + uVar10 * 4) <<
                                   ((uint8_t)iVar9 & 0x1f));
                }
                *(uint32_t*)(s + 0x16b4) = (uint32_t)(iVar9 + (int32_t)uVar8);
                iVar9 = *(int32_t*)(DAT_006f4208 + iVar7);
                if (iVar9 != 0) {
                    iVar6 = (int32_t)uVar11 - *(int32_t*)(DAT_006f4b50 + iVar7);
                    iVar7 = *(int32_t*)(s + 0x16b4);
                    if (0x10 - iVar9 < iVar7) {
                        *(uint16_t*)(s + 0x16b0) =
                            *(uint16_t*)(s + 0x16b0) |
                            (uint16_t)(iVar6 << ((uint8_t)iVar7 & 0x1f));
                        *(uint8_t*)(*(int32_t*)(s + 8) + *(int32_t*)(s + 0x14)) =
                            *(uint8_t*)(s + 0x16b0);
                        *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                        *(uint8_t*)(*(int32_t*)(s + 0x14) + *(int32_t*)(s + 8)) =
                            *(uint8_t*)(s + 0x16b1);
                        *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                        iVar7 = *(int32_t*)(s + 0x16b4) + -0x10;
                        *(uint16_t*)(s + 0x16b0) =
                            (uint16_t)((uint16_t)iVar6 >>
                                       (0x10U - (uint8_t)*(int32_t*)(s + 0x16b4) & 0x1f));
                    } else {
                        *(uint16_t*)(s + 0x16b0) =
                            *(uint16_t*)(s + 0x16b0) |
                            (uint16_t)(iVar6 << ((uint8_t)iVar7 & 0x1f));
                    }
                    *(int32_t*)(s + 0x16b4) = iVar7 + iVar9;
                }
                uVar11 = uVar12 - 1;
                if (uVar11 < 0x100) {
                    bVar2 = DAT_006f484f[uVar12];
                } else {
                    bVar2 = DAT_006f4950[uVar11 >> 7];
                }
                iVar7 = (int32_t)((uint32_t)bVar2 * 4);
                puVar1 = (uint16_t*)(iVar7 + param_2);
                uVar3 = puVar1[1];
                iVar9 = *(int32_t*)(s + 0x16b4);
                if ((int32_t)(0x10 - (uint32_t)uVar3) < iVar9) {
                    uVar4 = *puVar1;
                    *(uint16_t*)(s + 0x16b0) =
                        *(uint16_t*)(s + 0x16b0) | (uint16_t)(uVar4 << ((uint8_t)iVar9 & 0x1f));
                    *(uint8_t*)(*(int32_t*)(s + 8) + *(int32_t*)(s + 0x14)) =
                        *(uint8_t*)(s + 0x16b0);
                    *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                    *(uint8_t*)(*(int32_t*)(s + 0x14) + *(int32_t*)(s + 8)) =
                        *(uint8_t*)(s + 0x16b1);
                    *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                    iVar9 = *(int32_t*)(s + 0x16b4) + -0x10;
                    *(uint16_t*)(s + 0x16b0) =
                        (uint16_t)(uVar4 >> (0x10U - (uint8_t)*(int32_t*)(s + 0x16b4) & 0x1f));
                } else {
                    *(uint16_t*)(s + 0x16b0) =
                        *(uint16_t*)(s + 0x16b0) | (uint16_t)(*puVar1 << ((uint8_t)iVar9 & 0x1f));
                }
                iVar9 = iVar9 + (int32_t)(uint32_t)uVar3;
                *(int32_t*)(s + 0x16b4) = iVar9;
                iVar6 = *(int32_t*)(DAT_006f4280 + iVar7);
                if (iVar6 != 0) {
                    iVar7 = (int32_t)uVar11 - *(int32_t*)(DAT_006f4bc8 + iVar7);
                    if (0x10 - iVar6 < iVar9) {
                        *(uint16_t*)(s + 0x16b0) =
                            *(uint16_t*)(s + 0x16b0) |
                            (uint16_t)(iVar7 << ((uint8_t)iVar9 & 0x1f));
                        *(uint8_t*)(*(int32_t*)(s + 8) + *(int32_t*)(s + 0x14)) =
                            *(uint8_t*)(s + 0x16b0);
                        *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                        *(uint8_t*)(*(int32_t*)(s + 0x14) + *(int32_t*)(s + 8)) =
                            *(uint8_t*)(s + 0x16b1);
                        *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                        iVar6 = *(int32_t*)(s + 0x16b4) + -0x10 + iVar6;
                        *(uint16_t*)(s + 0x16b0) =
                            (uint16_t)((uint16_t)iVar7 >>
                                       (0x10U - (uint8_t)*(int32_t*)(s + 0x16b4) & 0x1f));
                    } else {
                        *(uint16_t*)(s + 0x16b0) =
                            *(uint16_t*)(s + 0x16b0) |
                            (uint16_t)(iVar7 << ((uint8_t)iVar9 & 0x1f));
                        iVar6 = iVar9 + iVar6;
                    }
                    goto LAB_006af2b1;
                }
            }
        } while (uVar5 < *(uint32_t*)(s + 0x1698));
    }
    uVar3 = *(uint16_t*)(param_1 + 0x402);
    iVar9 = *(int32_t*)(s + 0x16b4);
    if ((int32_t)(0x10 - (uint32_t)uVar3) < iVar9) {
        uVar4 = *(uint16_t*)(param_1 + 0x400);
        *(uint16_t*)(s + 0x16b0) =
            *(uint16_t*)(s + 0x16b0) | (uint16_t)(uVar4 << ((uint8_t)iVar9 & 0x1f));
        *(uint8_t*)(*(int32_t*)(s + 8) + *(int32_t*)(s + 0x14)) = *(uint8_t*)(s + 0x16b0);
        *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
        *(uint8_t*)(*(int32_t*)(s + 0x14) + *(int32_t*)(s + 8)) = *(uint8_t*)(s + 0x16b1);
        *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
        iVar9 = *(int32_t*)(s + 0x16b4) + -0x10;
        *(uint16_t*)(s + 0x16b0) =
            (uint16_t)(uVar4 >> (0x10U - (uint8_t)*(int32_t*)(s + 0x16b4) & 0x1f));
    } else {
        *(uint16_t*)(s + 0x16b0) =
            *(uint16_t*)(s + 0x16b0) |
            (uint16_t)(*(int16_t*)(param_1 + 0x400) << ((uint8_t)iVar9 & 0x1f));
    }
    *(uint32_t*)(s + 0x16b4) = (uint32_t)(iVar9 + (int32_t)uVar3);
    *(uint32_t*)(s + 0x16ac) = (uint32_t)*(uint16_t*)(param_1 + 0x402);
    return;
}

// 0x6af365 — observed shape: sums three uint16 fields on a 4-byte stride
// (7 slots from self+0x8c, 0x79 from self+0xa8, 0x80 from self+0x28c) and
// stores 1 - ((second_sum >> 2) < first_sum) as a byte at self+0x1c.
void FUN_006af365(void* self_p) {
    uint8_t* s = (uint8_t*)self_p;
    uint32_t uVar2 = 0;
    uint32_t uVar4 = 0;
    uint16_t* puVar1 = (uint16_t*)(s + 0x8c);
    int32_t iVar3 = 7;
    do {
        uVar4 = uVar4 + *puVar1;
        puVar1 = puVar1 + 2;
        iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    puVar1 = (uint16_t*)(s + 0xa8);
    iVar3 = 0x79;
    do {
        uVar2 = uVar2 + *puVar1;
        puVar1 = puVar1 + 2;
        iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    puVar1 = (uint16_t*)(s + 0x28c);
    iVar3 = 0x80;
    do {
        uVar4 = uVar4 + *puVar1;
        puVar1 = puVar1 + 2;
        iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    *(int8_t*)(s + 0x1c) = (int8_t)(1 - (uVar2 >> 2 < uVar4));
    return;
}

// 0x6af3ba — observed shape: flushes the pending bit buffer (two bytes when
// the count is >= 9, one when >= 1) into self+0x8 + self+0x14, then clears
// self+0x16b0/0x16b4; returns the receiver pointer, which the caller uses as
// the object base.
int32_t FUN_006af3ba(void* self_p) {
    uint8_t* s = (uint8_t*)self_p;
    if (*(int32_t*)(s + 0x16b4) < 9) {
        if (*(int32_t*)(s + 0x16b4) < 1) goto LAB_006af400;
        *(uint8_t*)(*(int32_t*)(s + 8) + *(int32_t*)(s + 0x14)) = *(uint8_t*)(s + 0x16b0);
    } else {
        *(uint8_t*)(*(int32_t*)(s + 8) + *(int32_t*)(s + 0x14)) = *(uint8_t*)(s + 0x16b0);
        *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
        *(uint8_t*)(*(int32_t*)(s + 0x14) + *(int32_t*)(s + 8)) = *(uint8_t*)(s + 0x16b1);
    }
    *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
LAB_006af400:
    *(uint16_t*)(s + 0x16b0) = 0;
    *(uint32_t*)(s + 0x16b4) = 0;
    return (int32_t)(intptr_t)self_p;
}

// 0x6af411 — observed shape: flush, store block type 8 at self+0x16ac, and
// when param_1 is non-zero append the big-endian length plus its one's
// complement (four bytes) from the value in ECX; then copy ECX bytes from the
// pointer in EDX.
void FUN_006af411(int param_1, uint32_t in_ECX_value, uint8_t* in_EDX_data) {
    uint32_t code = in_ECX_value;
    uint8_t* data = in_EDX_data;
    int32_t iVar1 = FUN_006af3ba();
    *(uint32_t*)(iVar1 + 0x16ac) = 8;
    if (param_1 != 0) {
        *(uint8_t*)(*(int32_t*)(iVar1 + 0x14) + *(int32_t*)(iVar1 + 8)) = (uint8_t)code;
        *(int32_t*)(iVar1 + 0x14) = *(int32_t*)(iVar1 + 0x14) + 1;
        uint8_t bVar2 = (uint8_t)(code >> 8);
        *(uint8_t*)(*(int32_t*)(iVar1 + 0x14) + *(int32_t*)(iVar1 + 8)) = bVar2;
        *(int32_t*)(iVar1 + 0x14) = *(int32_t*)(iVar1 + 0x14) + 1;
        *(uint8_t*)(*(int32_t*)(iVar1 + 0x14) + *(int32_t*)(iVar1 + 8)) = (uint8_t)~code;
        *(int32_t*)(iVar1 + 0x14) = *(int32_t*)(iVar1 + 0x14) + 1;
        *(uint8_t*)(*(int32_t*)(iVar1 + 0x14) + *(int32_t*)(iVar1 + 8)) = (uint8_t)~bVar2;
        *(int32_t*)(iVar1 + 0x14) = *(int32_t*)(iVar1 + 0x14) + 1;
    }
    for (; code != 0; code = code + -1) {
        *(uint8_t*)(*(int32_t*)(iVar1 + 0x14) + *(int32_t*)(iVar1 + 8)) = *data;
        *(int32_t*)(iVar1 + 0x14) = *(int32_t*)(iVar1 + 0x14) + 1;
        data = data + 1;
    }
    return;
}

// 0x6af48b — observed shape: rebuilds canonical codes. The bl array in EDX is
// accumulated into a 16-entry ushort table (doubling each step); each node of
// the tree in EBX with non-zero len at node*4+2 gets the next code of that
// length, bit-reversed into the code field at node*4.
void FUN_006af48b(int last, uint8_t* tree_base, int16_t* bl) {
    uint16_t auStack_24[16];
    int32_t iVar8 = 0;
    uint32_t uVar2 = 0;
    int32_t iVar4 = 1;
    do {
        uVar2 = (uint32_t)(((int32_t)*(int16_t*)(((uint8_t*)bl) + iVar4 * 2 - 2) +
                            (int32_t)uVar2) * 2) &
                0xffff;
        auStack_24[iVar4] = (uint16_t)uVar2;
        iVar4 = iVar4 + 1;
    } while (iVar4 < 0x10);
    if (-1 < last) {
        do {
            uint32_t uVar6 = (uint32_t)*(uint16_t*)(tree_base + 2 + iVar8 * 4);
            if (uVar6 != 0) {
                uVar2 = auStack_24[uVar6];
                uint32_t uVar7 = (uint32_t)uVar2;
                auStack_24[uVar6] = (uint16_t)(uVar2 + 1);
                uint32_t uVar1 = 0;
                uint32_t uVar3 = 0;
                uint32_t uVar5 = 0;
                do {
                    uVar3 = uVar1;
                    uVar5 = uVar7 & 1;
                    uVar7 = uVar7 >> 1;
                    uVar6 = uVar6 - 1;
                    uVar1 = (uVar3 | uVar5) << 1;
                } while (0 < (int32_t)uVar6);
                *(uint16_t*)(tree_base + iVar8 * 4) = (uint16_t)(uVar3 | uVar5);
            }
            iVar8 = iVar8 + 1;
        } while (iVar8 <= last);
    }
    return;
}

// 0x6af4fb — observed shape: builds the Huffman heap for one tree descriptor
// (param_1[0] node array, param_1[1] max_code/last, param_1[2] descriptor).
// Nodes with non-zero freq enter the heap at self+0xb54 (len self+0x1448,
// depth self+0x1450); a missing second node is synthesised, the heap is
// ordered by repeated FUN_006ae5b1 sifts, then pairs are merged at
// local_10++ accumulating self+0x16a0/0x16a4 until one node remains.
void FUN_006af4fb(int* param_1, void* self_p) {
    uint8_t* s = (uint8_t*)self_p;
    int32_t local_10 = ((int32_t*)param_1[2])[3];
    int32_t local_c = -1;
    int32_t iVar8 = *(int32_t*)param_1[2];
    int32_t iVar7 = 0;
    int32_t iVar4 = *param_1;
    *(uint32_t*)(s + 0x1448) = 0;
    *(uint32_t*)(s + 0x144c) = 0x23d;
    if (0 < local_10) {
        do {
            if (*(int16_t*)(iVar4 + iVar7 * 4) == 0) {
                *(uint16_t*)(iVar4 + 2 + iVar7 * 4) = 0;
            } else {
                *(int32_t*)(s + 0x1448) = *(int32_t*)(s + 0x1448) + 1;
                *(int32_t*)(s + 0xb54 + *(int32_t*)(s + 0x1448) * 4) = iVar7;
                *(uint8_t*)(s + iVar7 + 0x1450) = 0;
                local_c = iVar7;
            }
            iVar7 = iVar7 + 1;
        } while (iVar7 < local_10);
    }
    while (*(int32_t*)(s + 0x1448) < 2) {
        if (local_c < 2) {
            iVar7 = local_c + 1;
            local_c = iVar7;
        } else {
            iVar7 = 0;
        }
        *(int32_t*)(s + 0x1448) = *(int32_t*)(s + 0x1448) + 1;
        *(int32_t*)(s + 0xb54 + *(int32_t*)(s + 0x1448) * 4) = iVar7;
        *(uint16_t*)(iVar7 * 4 + iVar4) = 1;
        *(uint8_t*)(s + 0x1450 + iVar7) = 0;
        *(int32_t*)(s + 0x16a0) = *(int32_t*)(s + 0x16a0) + -1;
        if (iVar8 != 0) {
            *(int32_t*)(s + 0x16a4) =
                *(int32_t*)(s + 0x16a4) - (uint32_t)*(uint16_t*)(iVar7 * 4 + 2 + iVar8);
        }
    }
    param_1[1] = local_c;
    for (iVar8 = *(int32_t*)(s + 0x1448) / 2; 0 < iVar8; iVar8 = iVar8 + -1) {
        FUN_006ae5b1(iVar8);
    }
    do {
        uint32_t uVar5 = *(uint32_t*)(s + 0xb54 + *(int32_t*)(s + 0x1448) * 4);
        iVar8 = *(int32_t*)(s + 0xb58);
        *(int32_t*)(s + 0x1448) = *(int32_t*)(s + 0x1448) + -1;
        *(uint32_t*)(s + 0xb58) = uVar5;
        FUN_006ae5b1(1);
        *(int32_t*)(s + 0x144c) = *(int32_t*)(s + 0x144c) + -1;
        iVar7 = *(int32_t*)(s + 0xb58);
        *(int32_t*)(s + 0xb54 + *(int32_t*)(s + 0x144c) * 4) = iVar8;
        *(int32_t*)(s + 0x144c) = *(int32_t*)(s + 0x144c) + -1;
        *(int32_t*)(s + 0xb54 + *(int32_t*)(s + 0x144c) * 4) = iVar7;
        int16_t* psVar1 = (int16_t*)(iVar4 + iVar7 * 4);
        int16_t* psVar2 = (int16_t*)(iVar4 + iVar8 * 4);
        *(int16_t*)(iVar4 + local_10 * 4) = *psVar1 + *psVar2;
        uint8_t bVar3 = *(uint8_t*)(s + 0x1450 + iVar8);
        uint8_t bVar6 = *(uint8_t*)(s + 0x1450 + iVar7);
        if (bVar6 <= bVar3) {
            bVar6 = bVar3;
        }
        *(uint8_t*)(s + 0x1450 + local_10) = bVar6 + 1;
        psVar1[1] = (int16_t)local_10;
        psVar2[1] = (int16_t)local_10;
        *(int32_t*)(s + 0xb58) = local_10;
        local_10 = local_10 + 1;
        FUN_006ae5b1(1);
    } while (1 < *(int32_t*)(s + 0x1448));
    *(int32_t*)(s + 0x144c) = *(int32_t*)(s + 0x144c) + -1;
    *(uint32_t*)(s + 0xb54 + *(int32_t*)(s + 0x144c) * 4) = *(uint32_t*)(s + 0xb58);
    FUN_006ae663();
    FUN_006af48b(local_c);
    return;
}

// 0x6af6de — observed shape: two scan_tree passes, one FUN_006af4fb pass on
// self+0xb28, then a backward walk of lengths from index 0x12 (stopping when
// the entry for DAT_006f4344[i] is non-zero or the index drops below 3), and
// finally an adjustment of self+0x16a0 by i*3 + 0x11.
// NEEDS_MANUAL: the provider shows no argument list for the scan_tree and
// FUN_006af4fb calls at this site; the EAX operand is not recovered.
void FUN_006af6de(void* self_p) {
    uint8_t* s = (uint8_t*)self_p;
    FUN_006ae81b(s);
    FUN_006ae81b(s);
    FUN_006af4fb((int*)(s + 0xb28));
    int32_t iVar1 = 0x12;
    do {
        if (*(int16_t*)(s + 0xa76 + (uint32_t)DAT_006f4344[iVar1] * 4) != 0) break;
        iVar1 = iVar1 + -1;
    } while (2 < iVar1);
    *(int32_t*)(s + 0x16a0) = *(int32_t*)(s + 0x16a0) + iVar1 * 3 + 0x11;
    return;
}

// 0x6af738 — observed shape: writes param_4 as a 3-bit code (two-byte flush
// when the pending count is >= 0xe) and then calls FUN_006af411(1); param_2
// and param_3 are listed but not read.
void FUN_006af738(int param_1, uint32_t param_2, uint32_t param_3, int param_4) {
    uint8_t* s = (uint8_t*)(intptr_t)param_1;
    (void)param_2;
    (void)param_3;
    int32_t iVar1 = *(int32_t*)(s + 0x16b4);
    if (iVar1 < 0xe) {
        *(uint16_t*)(s + 0x16b0) =
            *(uint16_t*)(s + 0x16b0) | (uint16_t)(param_4 << ((uint8_t)iVar1 & 0x1f));
        *(int32_t*)(s + 0x16b4) = iVar1 + 3;
    } else {
        *(uint16_t*)(s + 0x16b0) =
            *(uint16_t*)(s + 0x16b0) | (uint16_t)(param_4 << ((uint8_t)iVar1 & 0x1f));
        *(uint8_t*)(*(int32_t*)(s + 8) + *(int32_t*)(s + 0x14)) = *(uint8_t*)(s + 0x16b0);
        *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
        *(uint8_t*)(*(int32_t*)(s + 0x14) + *(int32_t*)(s + 8)) = *(uint8_t*)(s + 0x16b1);
        iVar1 = *(int32_t*)(s + 0x16b4);
        *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
        *(int32_t*)(s + 0x16b4) = iVar1 + -0xd;
        *(uint16_t*)(s + 0x16b0) = (uint16_t)((uint16_t)param_4 >> (0x10U - (uint8_t)iVar1 & 0x1f));
    }
    FUN_006af411(1);
    return;
}

// 0x6af7c4 — observed shape: stored/fixed/dynamic block choice. With
// self+0x7c < 1 it assumes a stored limited-size block of param_3+5 bytes;
// otherwise it picks the smaller of the dynamic sizes self+0x16a0/0x16a4
// (each +10, >>3), compares it against param_3+4 (or param_2 == 0) and
// either emits a fixed-type header (param_4+2) plus the static trees, or a
// dynamic-type header (param_4+4) plus FUN_006aed76 on the tree counts. The
// fixed path uses DAT_006f47d8/DAT_006f4358, the dynamic path self+0x980 and
// self+0x8c. Finally resets via FUN_006ae553 and, for a dynamic block, the
// bit buffer via FUN_006af3ba.
// NEEDS_MANUAL: the corpus assigns the result of FUN_006af6de (declared void)
// to iVar2 and later passes iVar2+1; the true source of that value is not
// visible in the listing, so iVar2 stays at its initial 0.
void FUN_006af7c4(int param_1, int param_2, int param_3, int param_4) {
    uint8_t* s = (uint8_t*)(intptr_t)param_1;
    int32_t iVar1;
    int32_t iVar2 = 0;
    uint32_t bVar3;
    uint32_t uVar4;
    uint32_t uVar5;
    int32_t iVar6;
    uint8_t* puVar7;
    uint8_t* puVar8;

    if (*(int32_t*)(s + 0x7c) < 1) {
        uVar4 = (uint32_t)(param_3 + 5);
    } else {
        if (*(int8_t*)(s + 0x1c) == '\x02') {
            FUN_006af365();
        }
        FUN_006af4fb((int*)(s + 0xb10));
        FUN_006af4fb((int*)(s + 0xb1c));
        FUN_006af6de();   // corpus: iVar2 = FUN_006af6de();
        uVar5 = (uint32_t)(*(int32_t*)(s + 0x16a0) + 10) >> 3;
        uVar4 = (uint32_t)(*(int32_t*)(s + 0x16a4) + 10) >> 3;
        if (uVar5 < uVar4) goto LAB_006af825;
    }
    uVar5 = uVar4;
LAB_006af825:
    if ((uVar5 < (uint32_t)(param_3 + 4)) || (param_2 == 0)) {
        iVar1 = *(int32_t*)(s + 0x16b4);
        bVar3 = (uint32_t)(uint8_t)iVar1;
        if (uVar4 == uVar5) {
            iVar2 = param_4 + 2;
            if (iVar1 < 0xe) {
                *(uint16_t*)(s + 0x16b0) =
                    *(uint16_t*)(s + 0x16b0) | (uint16_t)(iVar2 << (bVar3 & 0x1f));
                *(int32_t*)(s + 0x16b4) = iVar1 + 3;
            } else {
                *(uint16_t*)(s + 0x16b0) =
                    *(uint16_t*)(s + 0x16b0) | (uint16_t)(iVar2 << (bVar3 & 0x1f));
                *(uint8_t*)(*(int32_t*)(s + 8) + *(int32_t*)(s + 0x14)) = *(uint8_t*)(s + 0x16b0);
                *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                *(uint8_t*)(*(int32_t*)(s + 0x14) + *(int32_t*)(s + 8)) = *(uint8_t*)(s + 0x16b1);
                iVar1 = *(int32_t*)(s + 0x16b4);
                *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                *(int32_t*)(s + 0x16b4) = iVar1 + -0xd;
                *(uint16_t*)(s + 0x16b0) =
                    (uint16_t)((uint16_t)iVar2 >> (0x10U - (uint8_t)iVar1 & 0x1f));
            }
            puVar8 = DAT_006f47d8;
            puVar7 = DAT_006f4358;
        } else {
            iVar6 = param_4 + 4;
            if (iVar1 < 0xe) {
                *(uint16_t*)(s + 0x16b0) =
                    *(uint16_t*)(s + 0x16b0) | (uint16_t)(iVar6 << (bVar3 & 0x1f));
                *(int32_t*)(s + 0x16b4) = iVar1 + 3;
            } else {
                *(uint16_t*)(s + 0x16b0) =
                    *(uint16_t*)(s + 0x16b0) | (uint16_t)(iVar6 << (bVar3 & 0x1f));
                *(uint8_t*)(*(int32_t*)(s + 8) + *(int32_t*)(s + 0x14)) = *(uint8_t*)(s + 0x16b0);
                *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                *(uint8_t*)(*(int32_t*)(s + 0x14) + *(int32_t*)(s + 8)) = *(uint8_t*)(s + 0x16b1);
                iVar1 = *(int32_t*)(s + 0x16b4);
                *(int32_t*)(s + 0x14) = *(int32_t*)(s + 0x14) + 1;
                *(int32_t*)(s + 0x16b4) = iVar1 + -0xd;
                *(uint16_t*)(s + 0x16b0) =
                    (uint16_t)((uint16_t)iVar6 >> (0x10U - (uint8_t)iVar1 & 0x1f));
            }
            FUN_006aed76(s, *(int32_t*)(s + 0xb14) + 1, *(int32_t*)(s + 0xb20) + 1, iVar2 + 1);
            puVar8 = (uint8_t*)(s + 0x980);
            puVar7 = (uint8_t*)(s + 0x8c);
        }
        FUN_006aefb1(s, puVar7, puVar8);
    } else {
        FUN_006af738((int)(intptr_t)s, (uint32_t)param_2, (uint32_t)param_3, param_4);
    }
    FUN_006ae553();
    if (param_4 != 0) {
        FUN_006af3ba();
    }
    return;
}

// 0x6af97b — observed shape: dwBytes = param_2 * param_3, flags 8, then
// GetProcessHeap followed by HeapAlloc; the listing drops the result.
void FUN_006af97b(uint32_t param_1, int param_2, int param_3) {
    (void)param_1;
    SIZE_T dwBytes = (SIZE_T)(param_2 * param_3);
    DWORD dwFlags = 8;
    HANDLE hHeap = GetProcessHeap();
    HeapAlloc(hHeap, dwFlags, dwBytes);
    return;
}

// 0x6af9ad — observed shape: copies param_1[0xf] out when param_3 is set;
// for states 4/5 dispatches the callback at param_2+0x24 with
// *(param_2+0x28) and param_1[3]; for state 6 calls FUN_006b2a1a(param_1[1],
// param_2); then resets slots 0xc/0xd to param_1[10], clears 0/7/8 and, when
// param_1[0xe] is set, invokes it with (0,0,0) storing the result in
// param_1[0xf] and at param_2+0x30.
void FUN_006af9ad(int* param_1, int param_2, int* param_3) {
    int32_t iVar1;
    if (param_3 != (int*)0x0) {
        *param_3 = param_1[0xf];
    }
    if ((*param_1 == 4) || (*param_1 == 5)) {
        ((void (*)(uint32_t, int))(*(uint32_t*)((intptr_t)param_2 + 0x24)))(
            *(uint32_t*)((intptr_t)param_2 + 0x28), param_1[3]);
    }
    if (*param_1 == 6) {
        FUN_006b2a1a(param_1[1], (void*)(intptr_t)param_2);
    }
    param_1[0xd] = param_1[10];
    param_1[0xc] = param_1[10];
    *param_1 = 0;
    param_1[7] = 0;
    param_1[8] = 0;
    if ((void*)param_1[0xe] != (void*)0x0) {
        iVar1 = ((int32_t (*)(int, int, int))(intptr_t)param_1[0xe])(0, 0, 0);
        param_1[0xf] = iVar1;
        *(int32_t*)((intptr_t)param_2 + 0x30) = iVar1;
    }
    return;
}
