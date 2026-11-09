#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---------------------------------------------------------------------------
// External helpers and globals referenced by the translated listings.
// ---------------------------------------------------------------------------

// zlib-style allocator / free callbacks and their opaque handle.
typedef void* (*alloc_func_t)(int opaque, ...);
typedef void (*free_func_t)(int opaque, void* address);

// State-machine helpers used by the inflate core.
extern void FUN_006af9ad(void* state, void* strm, int arg);
extern int  FUN_006b2f4e(void* state, void* strm, int flush);
extern int  FUN_006b24c3(uint32_t state, int* strm, int flush);
extern int  FUN_006b2490(uint8_t lenbits, uint8_t distbits, uint32_t lencode,
                         uint32_t distcode, int strm);
extern int  FUN_006b2daa(uint32_t table, uint32_t* lens, uint32_t* work,
                         uint32_t codes, int strm);
extern int  FUN_006b2e23(uint32_t nlen, uint32_t ndist, uint32_t table,
                         int* lencode_bits, int* dist_bits, int* lencode_mask,
                         int* dist_mask, uint32_t codes, int strm);
extern void FUN_006b2a1a(uint32_t codes, int* strm);
extern void func_0x006b2f1d(void* a, void* b, void* c, void* d, int* strm);
extern int  FUN_006b305f(uint32_t lencode, int distcode, int lencode_table,
                         int dist_table, int state, int* strm);

extern void operator_delete__(void* p);

// Bit-mask table indexed by number of bits (1U << n) - 1.
extern uint32_t DAT_00722488[];
// Code-length permutation order used while reading the dynamic table header.
extern int32_t UNK_006f4cb0[];
// Jump table for the inflate state dispatch.
extern uint8_t DAT_006b01b5[];
// Vtable installed by the reconstructor at 0x6b3330.
extern void* PTR_FUN_006f5210;

static int ftol(float v) { return (int)v; }

// 0x6afa13 — observed shape
void* FUN_006afa13(int param_1)
{
    void* puVar1;
    int iVar2;
    uint32_t uVar3;

    puVar1 = (*(alloc_func_t*)(param_1 + 0x20))(*(int*)(param_1 + 0x28), 1);
    if (puVar1 != nullptr) {
        uVar3 = 8;
        iVar2 = (*(int (**)(int, int, int))(param_1 + 0x20))(*(int*)(param_1 + 0x28), 8, 0x5a0);
        ((uint32_t*)puVar1)[9] = (uint32_t)iVar2;
        if (iVar2 != 0) {
            iVar2 = (*(int (**)(int, int, int))(param_1 + 0x20))(*(int*)(param_1 + 0x28), 1, 0x40);
            ((uint32_t*)puVar1)[10] = (uint32_t)iVar2;
            if (iVar2 == 0) {
                (*(free_func_t*)(param_1 + 0x24))(*(int*)(param_1 + 0x28),
                                                  (void*)(uintptr_t)((uint32_t*)puVar1)[9]);
                (*(free_func_t*)(param_1 + 0x24))(*(int*)(param_1 + 0x28), puVar1);
                return nullptr;
            }
            *(uint32_t*)puVar1 = 0;
            ((uint32_t*)puVar1)[0xb] = (uint32_t)(iVar2 + 0x40);
            ((uint32_t*)puVar1)[0xe] = uVar3;
            FUN_006af9ad(puVar1, (void*)(uintptr_t)param_1, 0);
            return puVar1;
        }
        (*(free_func_t*)(param_1 + 0x24))(*(int*)(param_1 + 0x28), puVar1);
    }
    return nullptr;
}

// 0x6afa91 — observed shape
void FUN_006afa91(uint32_t* state, int* strm, int flush)
{
    uint32_t* puVar5 = state;
    uint32_t avail_in = (uint32_t)strm[1];
    uint32_t hold = state[8];
    uint32_t bits = state[7];
    uint8_t* out = (uint8_t*)(uintptr_t)state[0xd];
    uint8_t* in  = (uint8_t*)(uintptr_t)*strm;
    uint32_t out_left;
    uint32_t mode;
    uint32_t uVar8;
    uint32_t uStack_2c, uStack_28, uStack_24, uStack_20;
    uint32_t lencode_bits = 9, dist_bits = 6;
    uint32_t lencode_mask = 0, dist_mask = 0;
    uint8_t* pbStack_1c;
    uint8_t* pbStack_30;
    uint8_t bVar2;
    uint8_t* pbVar3;
    uint8_t* pbVar6;
    int iVar4;
    uint32_t sym, extra, base, rep;

    if (out < (uint8_t*)(uintptr_t)state[0xc]) {
        out_left = (uint32_t)((uint8_t*)(uintptr_t)state[0xc] - out) - 1;
    }
    else {
        out_left = state[0xb] - (uint32_t)(uintptr_t)out;
    }
    mode = *puVar5;
    if (mode < 10) {
        do {
            switch (mode) {
            case 0:
                for (; bits < 3; bits += 8) {
                    if (avail_in == 0) goto code_r0x006b010c;
                    flush = 0;
                    avail_in -= 1;
                    hold |= (uint32_t)*in << (bits & 0x1f);
                    in += 1;
                }
                uVar8 = (hold & 7) >> 1;
                puVar5[6] = hold & 1;
                if (uVar8 == 0) {
                    uVar8 = (uint32_t)(bits - 3) & 7;
                    hold = (hold >> 3) >> (uint32_t)(int8_t)uVar8;
                    bits = (bits - 3) - uVar8;
                    *puVar5 = 1;
                }
                else if (uVar8 == 1) {
                    func_0x006b2f1d(&uStack_2c, &uStack_28, &uStack_24, &uStack_20, strm);
                    uVar8 = (uint32_t)FUN_006b2490(
                        (uint8_t)uStack_2c, (uint8_t)uStack_28, uStack_24, uStack_20, (int)(uintptr_t)strm);
                    puVar5[1] = uVar8;
                    if (uVar8 == 0) goto LAB_006b0159;
                    hold >>= 3;
                    bits -= 3;
                    *puVar5 = 6;
                }
                else {
                    if (uVar8 == 2) {
                        hold >>= 3;
                        uVar8 = 3;
                        bits -= 3;
                        goto code_r0x006afb92;
                    }
                    if (uVar8 == 3) {
                        *puVar5 = 9;
                        strm[6] = (int)(uintptr_t)"invalid block type";
                        puVar5[8] = hold >> 3;
                        bits -= 3;
                        flush = -3;
                        goto code_r0x006afae3;
                    }
                }
                break;

            case 1:
                for (; bits < 0x20; bits += 8) {
                    if (avail_in == 0) goto code_r0x006b010c;
                    flush = 0;
                    avail_in -= 1;
                    hold |= (uint32_t)*in << (bits & 0x1f);
                    in += 1;
                }
                if ((~hold >> 0x10) != (hold & 0xffff)) {
                    *puVar5 = 9;
                    strm[6] = (int)(uintptr_t)"invalid stored block lengths";
                    goto code_r0x006b00cf;
                }
                puVar5[1] = hold & 0xffff;
                bits = 0;
                hold = 0;
                if (puVar5[1] == 0) goto code_r0x006afd3d;
                uVar8 = 2;
                goto code_r0x006afb92;

            case 2:
                if (avail_in == 0) goto code_r0x006b010c;
                if (out_left == 0) {
                    if (out == (uint8_t*)(uintptr_t)puVar5[0xb]) {
                        pbVar6 = (uint8_t*)(uintptr_t)puVar5[0xc];
                        pbVar3 = (uint8_t*)(uintptr_t)puVar5[10];
                        if (pbVar3 != pbVar6) {
                            if (pbVar3 < pbVar6) {
                                out_left = (uint32_t)(pbVar6 - pbVar3) - 1;
                            }
                            else {
                                out_left = puVar5[0xb] - (uint32_t)(uintptr_t)pbVar3;
                            }
                            out = pbVar3;
                            if (out_left != 0) goto code_r0x006afcfd;
                        }
                    }
                    puVar5[0xd] = (uint32_t)(uintptr_t)out;
                    flush = FUN_006b2f4e(puVar5, strm, flush);
                    pbStack_1c = (uint8_t*)(uintptr_t)puVar5[0xc];
                    out = (uint8_t*)(uintptr_t)puVar5[0xd];
                    if (out < pbStack_1c) {
                        out_left = (uint32_t)(pbStack_1c - out) - 1;
                    }
                    else {
                        out_left = puVar5[0xb] - (uint32_t)(uintptr_t)out;
                    }
                    pbStack_30 = (uint8_t*)(uintptr_t)puVar5[0xb];
                    if (out == pbStack_30) {
                        pbVar6 = (uint8_t*)(uintptr_t)puVar5[10];
                        if (pbVar6 != pbStack_1c) {
                            if (pbVar6 < pbStack_1c) {
                                out_left = (uint32_t)(pbStack_1c - pbVar6) - 1;
                            }
                            else {
                                out_left = (uint32_t)(pbStack_30 - pbVar6);
                            }
                            out = pbVar6;
                        }
                    }
                    if (out_left == 0) {
                        puVar5[8] = hold;
                        puVar5[7] = bits;
                        strm[1] = (int)avail_in;
                        strm[2] = (int)((uintptr_t)in + (strm[2] - *strm));
                        goto code_r0x006afaf6;
                    }
                }
code_r0x006afcfd:
                flush = 0;
                rep = puVar5[1];
                if (avail_in < rep) rep = avail_in;
                if (out_left < rep) rep = out_left;
                for (uVar8 = rep; uVar8 != 0; uVar8--) {
                    *out++ = *in++;
                }
                puVar5[1] = puVar5[1] - rep;
                avail_in -= rep;
                out_left -= rep;
                if (puVar5[1] == 0) {
code_r0x006afd3d:
                    *puVar5 = (puVar5[6] != 0) ? 7 : 0;
                    break;
                }
                break;

            case 3:
                for (; bits < 0xe; bits += 8) {
                    if (avail_in == 0) goto code_r0x006b010c;
                    flush = 0;
                    avail_in -= 1;
                    hold |= (uint32_t)*in << (bits & 0x1f);
                    in += 1;
                }
                puVar5[1] = hold & 0x3fff;
                if ((0x1d < (hold & 0x1f)) ||
                    (uVar8 = ((hold & 0x3fff) >> 5) & 0x1f, 0x1d < uVar8)) {
                    *puVar5 = 9;
                    strm[6] = (int)(uintptr_t)"too many length or distance symbols";
                    goto code_r0x006b00cf;
                }
                uVar8 = (uint32_t)(*(int (**)(int, uint32_t, int))(strm[8]))(
                    strm[10], uVar8 + 0x102 + (hold & 0x1f), 4);
                puVar5[3] = uVar8;
                if (uVar8 != 0) {
                    hold >>= 0xe;
                    bits -= 0xe;
                    puVar5[2] = 0;
                    *puVar5 = 4;
                    goto code_r0x006afe18;
                }
LAB_006b0159:
                flush = -4;
                goto LAB_006afada;

            case 4:
code_r0x006afe18:
                while (puVar5[2] < (puVar5[1] >> 10) + 4) {
                    for (; bits < 3; bits += 8) {
                        if (avail_in == 0) goto code_r0x006b010c;
                        flush = 0;
                        avail_in -= 1;
                        hold |= (uint32_t)*in << (bits & 0x1f);
                        in += 1;
                    }
                    *(uint32_t*)(puVar5[3] + (uint32_t)UNK_006f4cb0[puVar5[2]] * 4) = hold & 7;
                    puVar5[2] = puVar5[2] + 1;
                    bits -= 3;
                    hold >>= 3;
                }
                while (puVar5[2] < 0x13) {
                    *(uint32_t*)(puVar5[3] + (uint32_t)UNK_006f4cb0[puVar5[2]] * 4) = 0;
                    puVar5[2] = puVar5[2] + 1;
                }
                puVar5[4] = 7;
                flush = FUN_006b2daa(puVar5[3], puVar5 + 4, puVar5 + 5, puVar5[9], (int)(uintptr_t)strm);
                if (flush == 0) {
                    puVar5[2] = 0;
                    *puVar5 = 5;
                    goto code_r0x006aff93;
                }
                goto code_r0x006b0140;

            case 5:
code_r0x006aff93:
                while (puVar5[2] <
                       (((puVar5[1] >> 5) & 0x1f) + 0x102 + (puVar5[1] & 0x1f))) {
                    for (; bits < puVar5[4]; bits += 8) {
                        if (avail_in == 0) goto code_r0x006b010c;
                        flush = 0;
                        avail_in -= 1;
                        hold |= (uint32_t)*in << (bits & 0x1f);
                        in += 1;
                    }
                    iVar4 = (int)(puVar5[5] + (DAT_00722488[puVar5[4]] & hold) * 8);
                    bVar2 = *(uint8_t*)((uintptr_t)iVar4 + 1);
                    extra = (uint32_t)bVar2;
                    sym = *(uint32_t*)((uintptr_t)iVar4 + 4);
                    if (sym < 0x10) {
                        hold >>= (bVar2 & 0x1f);
                        bits -= extra;
                        *(uint32_t*)(puVar5[3] + puVar5[2] * 4) = sym;
                        puVar5[2] = puVar5[2] + 1;
                    }
                    else {
                        base = (sym == 0x12) ? 7 : sym - 0xe;
                        rep = (uint32_t)(sym == 0x12) * 8 + 3;
                        for (; bits < base + extra; bits += 8) {
                            if (avail_in == 0) goto code_r0x006b010c;
                            flush = 0;
                            avail_in -= 1;
                            hold |= (uint32_t)*in << (bits & 0x1f);
                            in += 1;
                        }
                        hold >>= (bVar2 & 0x1f);
                        rep = rep + (DAT_00722488[base] & hold);
                        hold >>= (base & 0x1f);
                        bits -= base + extra;
                        uVar8 = puVar5[2];
                        if (((((puVar5[1] >> 5) & 0x1f) + 0x102 + (puVar5[1] & 0x1f)) <
                             rep + uVar8)) {
code_r0x006b0124:
                            (*(void (**)(int, uint32_t))(strm[9]))(strm[10], puVar5[3]);
                            *puVar5 = 9;
                            strm[6] = (int)(uintptr_t)"invalid bit length repeat";
                            goto code_r0x006b00cf;
                        }
                        if (sym == 0x10) {
                            if (uVar8 == 0) goto code_r0x006b0124;
                            uVar8 = *(uint32_t*)(puVar5[3] - 4 + uVar8 * 4);
                        }
                        else {
                            uVar8 = 0;
                        }
                        do {
                            *(uint32_t*)(puVar5[3] + puVar5[2] * 4) = uVar8;
                            puVar5[2] = puVar5[2] + 1;
                            rep = rep - 1;
                        } while (rep != 0);
                        puVar5[2] = puVar5[2];
                        rep = 0;
                    }
                }
                puVar5[5] = 0;
                pbStack_1c = (uint8_t*)0x9;
                lencode_bits = 9;
                dist_bits = 6;
                flush = FUN_006b2e23((puVar5[1] & 0x1f) + 0x101,
                                     ((puVar5[1] >> 5) & 0x1f) + 1, puVar5[3],
                                     (int*)&lencode_bits, (int*)&dist_bits,
                                     (int*)&lencode_mask, (int*)&dist_mask,
                                     puVar5[9], (int)(uintptr_t)strm);
                if (flush == 0) {
                    uVar8 = (uint32_t)FUN_006b2490((uint8_t)lencode_bits, (uint8_t)dist_bits,
                                                   lencode_mask, dist_mask, (int)(uintptr_t)strm);
                    if (uVar8 == 0) goto LAB_006b0159;
                    puVar5[1] = uVar8;
                    (*(void (**)(int, uint32_t))(strm[9]))(strm[10], puVar5[3]);
                    *puVar5 = 6;
                    goto code_r0x006b002c;
                }
code_r0x006b0140:
                if (flush == -3) {
                    (*(void (**)(int, uint32_t))(strm[9]))(strm[10], puVar5[3]);
                    *puVar5 = 9;
                }
                goto LAB_006afada;

            case 6:
code_r0x006b002c:
                puVar5[8] = hold;
                puVar5[7] = bits;
                strm[1] = (int)avail_in;
                strm[2] = (int)((uintptr_t)in + (strm[2] - *strm));
                *strm = (int)(uintptr_t)in;
                puVar5[0xd] = (uint32_t)(uintptr_t)out;
                flush = FUN_006b24c3((uint32_t)(uintptr_t)puVar5, strm, flush);
                if (flush != 1) goto LAB_006afafb;
                flush = 0;
                FUN_006b2a1a(puVar5[1], strm);
                avail_in = (uint32_t)strm[1];
                out = (uint8_t*)(uintptr_t)puVar5[0xd];
                in = (uint8_t*)(uintptr_t)*strm;
                hold = puVar5[8];
                bits = puVar5[7];
                if (out < (uint8_t*)(uintptr_t)puVar5[0xc]) {
                    out_left = (uint32_t)((uint8_t*)(uintptr_t)puVar5[0xc] - out) - 1;
                }
                else {
                    out_left = puVar5[0xb] - (uint32_t)(uintptr_t)out;
                }
                if (puVar5[6] != 0) {
                    *puVar5 = 7;
                    goto code_r0x006b0166;
                }
                *puVar5 = 0;
                break;

            case 7:
code_r0x006b0166:
                puVar5[0xd] = (uint32_t)(uintptr_t)out;
                flush = FUN_006b2f4e(puVar5, strm, flush);
                out = (uint8_t*)(uintptr_t)puVar5[0xd];
                if ((uint8_t*)(uintptr_t)puVar5[0xc] == out) {
                    *puVar5 = 8;
                    goto code_r0x006b01ae;
                }
                puVar5[8] = hold;
                puVar5[7] = bits;
                strm[1] = (int)avail_in;
                iVar4 = *strm;
                *strm = (int)(uintptr_t)in;
                strm[2] = (int)((uintptr_t)in + (strm[2] - iVar4));
                puVar5[0xd] = (uint32_t)(uintptr_t)out;
                goto LAB_006afafb;

            case 8:
code_r0x006b01ae:
                flush = 1;
                goto LAB_006afada;

            case 9:
code_r0x006b00cf:
                flush = -3;
                goto LAB_006afada;

            default:
                break;
            }
            uVar8 = *puVar5;
        } while (uVar8 < 10);
    }
    flush = -2;
    goto LAB_006afada;

code_r0x006b010c:
    puVar5[8] = hold;
    puVar5[7] = bits;
    strm[1] = 0;
code_r0x006afaec:
    strm[2] = (int)((uintptr_t)in + (strm[2] - *strm));
code_r0x006afaf6:
    *strm = (int)(uintptr_t)in;
    puVar5[0xd] = (uint32_t)(uintptr_t)out;
    goto LAB_006afafb;

LAB_006afada:
    puVar5[8] = hold;
code_r0x006afae3:
    puVar5[7] = bits;
    strm[1] = (int)avail_in;
    strm[2] = (int)((uintptr_t)in + (strm[2] - *strm));
    *strm = (int)(uintptr_t)in;
    puVar5[0xd] = (uint32_t)(uintptr_t)out;
LAB_006afafb:
    FUN_006b2f4e(puVar5, strm, flush);
}

// 0x6b01dd — observed shape
int FUN_006b01dd(int param_1, int param_2)
{
    FUN_006af9ad((void*)(uintptr_t)param_1, (void*)(uintptr_t)param_2, 0);
    (*(void (**)(int, int))(param_2 + 0x24))(*(int*)(param_2 + 0x28), *(int*)(param_1 + 0x28));
    (*(void (**)(int, int))(param_2 + 0x24))(*(int*)(param_2 + 0x28), *(int*)(param_1 + 0x24));
    (*(void (**)(int, int))(param_2 + 0x24))(*(int*)(param_2 + 0x28), param_1);
    return 0;
}

// 0x6b0210 — observed shape
void FUN_006b0210(int param_1, int param_2, short* param_3, int param_4, int param_5)
{
    float* pfVar9 = *(float**)(param_2 + 0x50);
    int iVar10 = *(int*)(param_1 + 0x148) + 0x80;
    float local_120[16];
    float* pfVar7;
    float fVar1, fVar2, fVar3, fVar4, fVar5, fVar6;
    float local_20, local_1c, local_18, local_14, local_10, local_c, local_8;
    int iVar8;
    int count;

    pfVar7 = local_120;
    count = 8;
    do {
        if ((((param_3[8] == 0) && (param_3[0x10] == 0)) && (param_3[0x18] == 0)) &&
            (((param_3[0x20] == 0 && (param_3[0x28] == 0)) &&
              ((param_3[0x30] == 0 && (param_3[0x38] == 0)))))) {
            fVar1 = (float)(int)*param_3 * *pfVar9;
            pfVar7[0] = fVar1;
            pfVar7[8] = fVar1;
            pfVar7[0x10] = fVar1;
            pfVar7[0x18] = fVar1;
            pfVar7[0x20] = fVar1;
            pfVar7[0x28] = fVar1;
            pfVar7[0x30] = fVar1;
            pfVar7[0x38] = fVar1;
        }
        else {
            fVar1 = (float)(int)param_3[0x20] * pfVar9[0x20] + (float)(int)*param_3 * *pfVar9;
            fVar2 = (float)(int)*param_3 * *pfVar9 - (float)(int)param_3[0x20] * pfVar9[0x20];
            fVar3 = (float)(int)param_3[0x30] * pfVar9[0x30] +
                    (float)(int)param_3[0x10] * pfVar9[0x10];
            fVar4 = ((float)(int)param_3[0x10] * pfVar9[0x10] -
                     (float)(int)param_3[0x30] * pfVar9[0x30]) * 1.4142135f - fVar3;
            fVar5 = fVar3 + fVar1;
            fVar1 = fVar1 - fVar3;
            local_18 = fVar4 + fVar2;
            local_20 = fVar2 - fVar4;
            local_10 = (float)(int)param_3[8] * pfVar9[8];
            local_1c = (float)(int)param_3[0x28] * pfVar9[0x28] +
                       (float)(int)param_3[0x18] * pfVar9[0x18];
            fVar3 = (float)(int)param_3[0x28] * pfVar9[0x28] -
                    (float)(int)param_3[0x18] * pfVar9[0x18];
            fVar2 = (float)(int)param_3[0x38] * pfVar9[0x38] + local_10;
            local_10 = local_10 - (float)(int)param_3[0x38] * pfVar9[0x38];
            fVar6 = fVar2 + local_1c;
            fVar4 = (local_10 + fVar3) * 1.847759f;
            local_c = (fVar4 - fVar3 * 2.613126f) - fVar6;
            fVar2 = (fVar2 - local_1c) * 1.4142135f - local_c;
            local_8 = (local_10 * 1.0823922f - fVar4) + fVar2;
            pfVar7[0] = fVar6 + fVar5;
            pfVar7[0x38] = fVar5 - fVar6;
            pfVar7[8] = local_c + local_18;
            pfVar7[0x30] = local_18 - local_c;
            pfVar7[0x10] = fVar2 + local_20;
            pfVar7[0x28] = local_20 - fVar2;
            pfVar7[0x20] = local_8 + fVar1;
            pfVar7[0x18] = fVar1 - local_8;
        }
        pfVar9 = pfVar9 + 1;
        param_3 = param_3 + 1;
        pfVar7 = pfVar7 + 1;
    } while (--count != 0);

    local_c = 0.0f;
    pfVar7 = local_120 + 2;
    do {
        uint8_t* puVar11 = (uint8_t*)(uintptr_t)(*(int*)(param_4 + (int)local_c * 4) + param_5);
        local_14 = *pfVar7 + pfVar7[4] + pfVar7[2] + pfVar7[-2];
        local_18 = ((*pfVar7 - pfVar7[4]) * 1.4142135f - (*pfVar7 + pfVar7[4])) +
                   (pfVar7[-2] - pfVar7[2]);
        local_10 = pfVar7[-1] - pfVar7[5];
        fVar1 = (local_10 + (pfVar7[3] - pfVar7[1])) * 1.847759f;
        local_8 = (local_10 * 1.0823922f - fVar1) +
                  (((pfVar7[5] + pfVar7[-1]) - (pfVar7[3] + pfVar7[1])) * 1.4142135f -
                   ((fVar1 - (pfVar7[3] - pfVar7[1]) * 2.613126f) -
                    (pfVar7[5] + pfVar7[-1] + pfVar7[3] + pfVar7[1])));
        // NEEDS_MANUAL: the x87 ftol() arguments were dropped by the decompiler.
        // The eight scale-and-lookup operations below keep the observed store
        // order (0,7,1,6,2,5,4,3) and the observed (v + 4) >> 3 rounding.
        iVar8 = ftol(local_14 + local_8);
        puVar11[0] = *(uint8_t*)(((iVar8 + 4) >> 3 & 0x3ffU) + iVar10);
        iVar8 = ftol(local_14 - local_8);
        puVar11[7] = *(uint8_t*)(((iVar8 + 4) >> 3 & 0x3ffU) + iVar10);
        iVar8 = ftol(local_18 + local_10);
        puVar11[1] = *(uint8_t*)(((iVar8 + 4) >> 3 & 0x3ffU) + iVar10);
        iVar8 = ftol(local_18 - local_10);
        puVar11[6] = *(uint8_t*)(((iVar8 + 4) >> 3 & 0x3ffU) + iVar10);
        iVar8 = ftol(local_18 + local_8);
        puVar11[2] = *(uint8_t*)(((iVar8 + 4) >> 3 & 0x3ffU) + iVar10);
        iVar8 = ftol(local_18 - local_8);
        puVar11[5] = *(uint8_t*)(((iVar8 + 4) >> 3 & 0x3ffU) + iVar10);
        iVar8 = ftol(local_14 + local_10);
        puVar11[4] = *(uint8_t*)(((iVar8 + 4) >> 3 & 0x3ffU) + iVar10);
        iVar8 = ftol(local_14 - local_10);
        puVar11[3] = *(uint8_t*)(((iVar8 + 4) >> 3 & 0x3ffU) + iVar10);
        pfVar7 = pfVar7 + 8;
        local_c = (float)((int)local_c + 1);
    } while ((int)local_c < 8);
}

// 0x6b05e0 — observed shape
void FUN_006b05e0(int param_1, int param_2, short* param_3, int param_4, int param_5)
{
    short* psVar5 = *(short**)(param_2 + 0x50);
    int iVar14 = *(int*)(param_1 + 0x148) + 0x80;
    int32_t buf[64];
    int32_t* puVar4;
    int32_t* pRow;
    int16_t* p16;
    int32_t local_8 = 0, local_c = 0;
    int32_t local_24, local_1c, local_28, local_18;
    int16_t sVar1, sVar2;
    uint16_t uVar3, uVar11;
    int32_t iVar12, iVar9, iVar8, iVar10, iVar2, iVar3, iVar4, iVar6;
    const uint16_t* psVar5b;
    int16_t* local_10 = param_3;
    int local_14 = 8;
    int local_20 = iVar14;
    uint8_t* puVar6;
    uint8_t uVar7;
    int local_c2;

    puVar4 = buf;
    do {
        sVar1 = local_10[0x38];
        local_8 = (int32_t)((uint32_t)local_8 & 0xffff0000u) | (uint16_t)sVar1;
        sVar2 = local_10[0x28];
        local_c = (int32_t)((uint32_t)local_c & 0xffff0000u) | (uint16_t)sVar2;
        uVar3 = (uint16_t)local_10[8];
        uVar11 = (uint16_t)local_10[0x10];
        local_28 = (int32_t)uVar3;
        local_18 = (int32_t)uVar11;
        if (((((((uVar3 == 0) && (uVar11 == 0)) && (local_10[0x18] == 0)) &&
              (local_10[0x20] == 0)) && (sVar2 == 0)) && (local_10[0x30] == 0)) &&
            (sVar1 == 0)) {
            iVar12 = (int)*local_10 * (int)*psVar5;
            puVar4[0] = iVar12;
            puVar4[8] = iVar12;
            puVar4[0x10] = iVar12;
            puVar4[0x18] = iVar12;
            puVar4[0x20] = iVar12;
            puVar4[0x28] = iVar12;
            puVar4[0x30] = iVar12;
            puVar4[0x38] = iVar12;
        }
        else {
            iVar12 = (int16_t)((int)*local_10 * (int)*psVar5);
            uint32_t uVar15 = (uint32_t)(uint16_t)(psVar5[0x20] * local_10[0x20]);
            iVar9 = (int32_t)(uVar15 + (uint32_t)iVar12);
            uint16_t uVar13 = (uint16_t)(psVar5[0x30] * local_10[0x30]);
            iVar12 = iVar12 - (int32_t)uVar15;
            iVar14 = (int32_t)uVar13 + (uint32_t)(uint16_t)(psVar5[0x10] * uVar11);
            local_24 = iVar9 + iVar14;
            iVar8 = (((int32_t)(int16_t)(psVar5[0x10] * uVar11) - (int32_t)(int16_t)uVar13) *
                         0x16a >> 8) - iVar14;
            local_18 = iVar9 - iVar14;
            local_1c = iVar8 + iVar12;
            uVar11 = (uint16_t)(psVar5[0x18] * local_10[0x18]);
            int32_t tP1 = (int16_t)iVar12 - (int16_t)iVar8;
            iVar9 = (int32_t)uVar11 + (uint32_t)(uint16_t)(psVar5[0x28] * sVar2);
            local_c = (int32_t)(uint32_t)(uint16_t)(psVar5[0x38] * sVar1) +
                      (int32_t)(uint32_t)(uint16_t)(psVar5[8] * uVar3);
            iVar14 = local_c;
            iVar8 = local_c + iVar9;
            iVar10 = (int32_t)(int16_t)(psVar5[8] * uVar3 - psVar5[0x38] * sVar1);
            iVar12 = (int32_t)(int16_t)(psVar5[0x28] * sVar2 - uVar11);
            int32_t iVar16 = (iVar12 + iVar10) * 0x1d9;
            int32_t tP3 = (int16_t)iVar9;
            local_8 = ((iVar12 * -0x29d >> 8) - iVar8) + (iVar16 >> 8);
            sVar2 = (int16_t)local_8;
            sVar1 = (int16_t)((uint32_t)(((int16_t)local_c - (int16_t)tP3) * 0x16a) >> 8) - sVar2;
            tP3 = ((int16_t)((uint32_t)(iVar10 * 0x115) >> 8) -
                   (int16_t)((uint32_t)iVar16 >> 8)) + sVar1;
            int32_t tP2 = (int16_t)iVar8;
            local_c = iVar14;
            puVar4[0x38] = (int32_t)(int16_t)local_24 - (int32_t)(int16_t)tP2;
            puVar4[0] = (int32_t)(int16_t)local_24 + (int32_t)(int16_t)tP2;
            puVar4[0x30] = (int32_t)(int16_t)local_1c - (int32_t)sVar2;
            puVar4[0x28] = (int32_t)(int16_t)tP1 - (int32_t)sVar1;
            puVar4[0x10] = (int32_t)(int16_t)tP1 + (int32_t)sVar1;
            puVar4[0x20] = (int32_t)(int16_t)tP3 + (int32_t)(int16_t)local_18;
            puVar4[0x18] = (int32_t)(int16_t)local_18 - (int32_t)(int16_t)tP3;
            puVar4[8] = (int32_t)sVar2 + (int32_t)(int16_t)local_1c;
        }
        local_10 = local_10 + 1;
        psVar5 = psVar5 + 1;
        puVar4 = puVar4 + 1;
        local_14 = local_14 + -1;
    } while (local_14 != 0);

    puVar4 = buf;
    local_c2 = 0;
    do {
        puVar6 = (uint8_t*)(uintptr_t)(*(int*)(param_4 + local_c2 * 4) + param_5);
        p16 = (int16_t*)puVar4;
        if ((((((p16[6] == 0 && p16[7] == 0) && p16[5] == 0) && p16[4] == 0) &&
              p16[3] == 0) && p16[2] == 0) && p16[1] == 0) {
            uVar7 = *(uint8_t*)((uint32_t)(((uint32_t)p16[0] >> 5) & 0x3ffU) + local_20);
            puVar6[0] = uVar7;
            puVar6[1] = uVar7;
            puVar6[2] = uVar7;
            puVar6[4] = uVar7;
            puVar6[5] = uVar7;
            puVar6[6] = uVar7;
            puVar6[7] = uVar7;
        }
        else {
            iVar12 = (uint32_t)p16[0] + (uint32_t)p16[8];
            iVar8 = (uint32_t)p16[0] - (uint32_t)p16[8];
            iVar9 = (uint32_t)p16[4] + (uint32_t)p16[0xc];
            iVar10 = (((int32_t)p16[4] - (int32_t)p16[0xc]) * 0x16a >> 8) - iVar9;
            local_24 = iVar9 + iVar12;
            local_18 = iVar12 - iVar9;
            local_1c = iVar10 + iVar8;
            int32_t tP1 = (int16_t)iVar8 - (int16_t)iVar10;
            iVar12 = (uint32_t)p16[6] + (uint32_t)p16[0xa];
            int32_t local_20b = (uint32_t)p16[0xa] - (uint32_t)p16[6];
            int32_t locc = (uint32_t)p16[2] + (uint32_t)p16[0xe];
            iVar9 = locc + iVar12;
            iVar8 = (int32_t)(int16_t)(p16[2] - p16[0xe]);
            iVar10 = ((int16_t)local_20b + iVar8) * 0x1d9;
            int32_t tP3 = (int16_t)iVar12;
            local_8 = (((int16_t)local_20b * -0x29d >> 8) - iVar9) + (iVar10 >> 8);
            sVar2 = (int16_t)local_8;
            sVar1 = (int16_t)((uint32_t)(((int16_t)locc - (int16_t)tP3) * 0x16a) >> 8) - sVar2;
            int32_t tP2 = (int16_t)iVar9;
            tP3 = ((int16_t)((uint32_t)(iVar8 * 0x115) >> 8) -
                   (int16_t)((uint32_t)iVar10 >> 8)) + sVar1;
            puVar6[0] = *(uint8_t*)(((uint32_t)((int16_t)tP2 + (int16_t)local_24) >> 5 & 0x3ffU) + local_20);
            puVar6[7] = *(uint8_t*)(((uint32_t)((int16_t)local_24 - (int16_t)tP2) >> 5 & 0x3ffU) + local_20);
            puVar6[1] = *(uint8_t*)(((uint32_t)((int32_t)sVar2 + (int16_t)local_1c) >> 5 & 0x3ffU) + local_20);
            puVar6[6] = *(uint8_t*)(((uint32_t)((int16_t)local_1c - (int32_t)sVar2) >> 5 & 0x3ffU) + local_20);
            uVar7 = *(uint8_t*)(((uint32_t)((int16_t)tP1 + (int32_t)sVar1) >> 5 & 0x3ffU) + local_20);
            puVar6[5] = *(uint8_t*)(((uint32_t)((int16_t)tP1 - (int32_t)sVar1) >> 5 & 0x3ffU) + local_20);
            puVar6[2] = uVar7;
            uVar7 = *(uint8_t*)(((uint32_t)((int16_t)local_18 - (int16_t)tP3) >> 5 & 0x3ffU) + local_20);
            puVar6[4] = *(uint8_t*)(((uint32_t)((int16_t)tP3 + (int16_t)local_18) >> 5 & 0x3ffU) + local_20);
        }
        puVar4 = puVar4 + 0x10;
        local_c2 = local_c2 + 1;
        puVar6[3] = uVar7;
    } while (local_c2 < 8);
}

// 0x6b0a20 — observed shape
void FUN_006b0a20(int param_1, int param_2, short* param_3, int param_4, int param_5)
{
    short* ps = *(short**)(param_2 + 0x50);
    int iVar4 = *(int*)(param_1 + 0x148) + 0x80;
    int local_30 = iVar4;
    int32_t buf[64];
    int32_t* piVar1 = buf;
    int32_t local_38, local_34, local_30v, local_2c, local_28, local_24, local_20;
    int32_t local_1c, local_18, local_14, local_10, local_c, local_8;
    int32_t iVar3, iVar6, iVar7, iVar8, iVar9, iVar10;
    uint8_t* puVar2;
    uint8_t uVar5;
    int local_18b;

    local_18 = 8;
    do {
        if ((((param_3[8] == 0) && (param_3[0x10] == 0)) && (param_3[0x18] == 0)) &&
            (((param_3[0x20] == 0 && (param_3[0x28] == 0)) &&
              ((param_3[0x30] == 0 && (param_3[0x38] == 0)))))) {
            iVar3 = (int)*param_3 * (int)*ps * 4;
            piVar1[0] = iVar3;
            piVar1[8] = iVar3;
            piVar1[0x10] = iVar3;
            piVar1[0x18] = iVar3;
            piVar1[0x20] = iVar3;
            piVar1[0x28] = iVar3;
            piVar1[0x30] = iVar3;
            piVar1[0x38] = iVar3;
        }
        else {
            iVar4 = ((int)ps[0x30] * (int)param_3[0x30] +
                     (int)ps[0x10] * (int)param_3[0x10]) * 0x1151;
            local_14 = iVar4 + (int)ps[0x30] * (int)param_3[0x30] * -0x3b21;
            iVar4 = (int)ps[0x10] * (int)param_3[0x10] * 0x187e + iVar4;
            iVar3 = ((int)ps[0x20] * (int)param_3[0x20] + (int)*param_3 * (int)*ps) * 0x2000;
            iVar6 = iVar4 + iVar3;
            local_38 = iVar6;
            iVar9 = ((int)*param_3 * (int)*ps -
                     (int)ps[0x20] * (int)param_3[0x20]) * 0x2000;
            local_34 = iVar3 - iVar4;
            local_2c = iVar9 - local_14;
            iVar4 = (int)ps[0x38] * (int)param_3[0x38];
            local_28 = iVar9 + local_14;
            iVar9 = (int)ps[0x28] * (int)param_3[0x28];
            iVar10 = (int)ps[0x18] * (int)param_3[0x18];
            iVar7 = (int)ps[8] * (int)param_3[8];
            local_1c = iVar7 + iVar9;
            local_20 = (local_1c + iVar4 + iVar10) * 0x25a1;
            iVar8 = (iVar4 + iVar7) * -0x1ccd;
            local_c = (iVar9 + iVar10) * -0x5203;
            local_10 = local_20 + (iVar4 + iVar10) * -0x3ec5;
            local_20 = local_20 + local_1c * -0xc7c;
            iVar3 = iVar4 * 0x98e + iVar8 + local_10;
            iVar4 = iVar9 * 0x41b3 + local_20 + local_c;
            iVar9 = iVar10 * 0x6254 + local_10 + local_c;
            iVar8 = iVar7 * 0x300b + local_20 + iVar8;
            piVar1[0] = (iVar6 + 0x400 + iVar8) >> 0xb;
            piVar1[0x38] = ((iVar6 - iVar8) + 0x400) >> 0xb;
            piVar1[0x30] = ((local_28 - iVar9) + 0x400) >> 0xb;
            piVar1[0x28] = ((local_2c - iVar4) + 0x400) >> 0xb;
            piVar1[8] = (local_28 + 0x400 + iVar9) >> 0xb;
            piVar1[0x10] = (local_2c + 0x400 + iVar4) >> 0xb;
            piVar1[0x20] = ((local_34 - iVar3) + 0x400) >> 0xb;
            piVar1[0x18] = (local_34 + 0x400 + iVar3) >> 0xb;
        }
        param_3 = param_3 + 1;
        ps = ps + 1;
        piVar1 = piVar1 + 1;
    } while (--local_18 != 0);

    piVar1 = buf;
    local_24 = 0;
    do {
        puVar2 = (uint8_t*)(uintptr_t)(*(int*)(param_4 + local_24 * 4) + param_5);
        local_18 = piVar1[1];
        if ((((local_18 == 0) && (piVar1[2] == 0)) &&
             ((piVar1[3] == 0 && (((piVar1[4] == 0 && (piVar1[5] == 0)) &&
                                   (piVar1[6] == 0)))))) &&
            (piVar1[7] == 0)) {
            uVar5 = *(uint8_t*)((uint32_t)((*piVar1 + 0x10) >> 5 & 0x3ffU) + local_30);
            puVar2[0] = uVar5;
            puVar2[1] = uVar5;
            puVar2[2] = uVar5;
            puVar2[3] = uVar5;
            puVar2[5] = uVar5;
            puVar2[6] = uVar5;
            puVar2[7] = uVar5;
        }
        else {
            iVar9 = (piVar1[6] + piVar1[2]) * 0x1151;
            iVar3 = piVar1[2] * 0x187e + iVar9;
            iVar9 = iVar9 + piVar1[6] * -0x3b21;
            local_2c = (*piVar1 - piVar1[4]) * 0x2000;
            iVar10 = (piVar1[4] + *piVar1) * 0x2000;
            iVar4 = iVar10 + iVar3;
            iVar10 = iVar10 - iVar3;
            local_28 = local_2c + iVar9;
            local_2c = local_2c - iVar9;
            iVar3 = piVar1[5];
            local_14 = piVar1[3];
            iVar9 = piVar1[7];
            local_20 = (local_18 + iVar3 + iVar9 + local_14) * 0x25a1;
            iVar6 = (iVar9 + local_18) * -0x1ccd;
            local_c = (iVar3 + local_14) * -0x5203;
            local_10 = local_20 + (iVar9 + local_14) * -0x3ec5;
            local_1c = local_20 + (local_18 + iVar3) * -0xc7c;
            local_8 = iVar9 * 0x98e + iVar6 + local_10;
            iVar3 = iVar3 * 0x41b3 + local_1c + local_c;
            local_14 = local_14 * 0x6254 + local_10 + local_c;
            iVar6 = local_18 * 0x300b + local_1c + iVar6;
            puVar2[0] = *(uint8_t*)((uint32_t)((iVar4 + 0x20000 + iVar6) >> 0x12 & 0x3ffU) + local_30);
            puVar2[7] = *(uint8_t*)((uint32_t)(((iVar4 - iVar6) + 0x20000) >> 0x12 & 0x3ffU) + local_30);
            puVar2[1] = *(uint8_t*)((uint32_t)((local_28 + 0x20000 + local_14) >> 0x12 & 0x3ffU) + local_30);
            puVar2[6] = *(uint8_t*)((uint32_t)(((local_28 - local_14) + 0x20000) >> 0x12 & 0x3ffU) + local_30);
            puVar2[2] = *(uint8_t*)((uint32_t)((local_2c + 0x20000 + iVar3) >> 0x12 & 0x3ffU) + local_30);
            puVar2[5] = *(uint8_t*)((uint32_t)(((local_2c - iVar3) + 0x20000) >> 0x12 & 0x3ffU) + local_30);
            puVar2[3] = *(uint8_t*)((uint32_t)((iVar10 + 0x20000 + local_8) >> 0x12 & 0x3ffU) + local_30);
            uVar5 = *(uint8_t*)((uint32_t)(((iVar10 - local_8) + 0x20000) >> 0x12 & 0x3ffU) + local_30);
        }
        piVar1 = piVar1 + 8;
        local_24 = local_24 + 1;
        puVar2[4] = uVar5;
    } while (local_24 < 8);
}

// 0x6b0f10 — observed shape
void FUN_006b0f10(short* param_1, short* param_2, int* param_3, int param_4, int param_5, int param_6)
{
    short* local_48 = param_1;
    short* local_44 = param_2;
    int* local_40 = param_3;
    int local_3c = 8;
    int iVar5, iVar6, iVar7, iVar8, iVar9, iVar10, iVar11, iVar12, iVar13, iVar14;
    int iVar15, iVar16, iVar17;
    int local_8;

    do {
        iVar15 = ((int)local_48[0x10] * (int)local_44[0x10] +
                  (int)local_48[0x30] * (int)local_44[0x30]) * 0x1151;
        iVar8 = (int)local_48[0x30] * (int)local_44[0x30] * -0x3b21 + iVar15;
        iVar15 = (int)local_48[0x10] * (int)local_44[0x10] * 0x187e + iVar15;
        iVar9 = ((int)local_48[0x20] * (int)local_44[0x20] +
                 (int)*local_48 * (int)*local_44) * 0x2000;
        iVar5 = ((int)*local_48 * (int)*local_44 -
                 (int)local_48[0x20] * (int)local_44[0x20]) * 0x2000;
        iVar10 = iVar9 + iVar15;
        iVar6 = iVar5 + iVar8;
        iVar9 = iVar9 - iVar15;
        iVar5 = iVar5 - iVar8;
        iVar15 = (int)local_48[0x38] * (int)local_44[0x38];
        iVar11 = (int)local_48[0x18] * (int)local_44[0x18];
        iVar16 = (int)local_48[8] * (int)local_44[8];
        iVar8 = (int)local_48[0x28] * (int)local_44[0x28];
        iVar7 = (iVar15 + iVar16) * -0x1ccd;
        iVar13 = (iVar8 + iVar11) * -0x5203;
        iVar17 = (iVar15 + iVar11 + iVar8 + iVar16) * 0x25a1;
        iVar12 = (iVar15 + iVar11) * -0x3ec5 + iVar17;
        iVar17 = (iVar8 + iVar16) * -0xc7c + iVar17;
        iVar15 = iVar7 + iVar12 + iVar15 * 0x98e;
        iVar14 = iVar13 + iVar17 + iVar8 * 0x41b3;
        iVar8 = iVar12 + iVar13 + iVar11 * 0x6254;
        iVar7 = iVar7 + iVar17 + iVar16 * 0x300b;
        local_40[0x20] = ((iVar9 - iVar15) + 0x400) >> 0xb;
        local_40[0x18] = (iVar15 + iVar9 + 0x400) >> 0xb;
        local_40[0x28] = ((iVar5 - iVar14) + 0x400) >> 0xb;
        local_40[0x30] = ((iVar6 - iVar8) + 0x400) >> 0xb;
        local_40[0x10] = (iVar14 + iVar5 + 0x400) >> 0xb;
        local_40[8] = (iVar8 + iVar6 + 0x400) >> 0xb;
        local_40[0x38] = ((iVar10 - iVar7) + 0x400) >> 0xb;
        *local_40 = (iVar10 + iVar7 + 0x400) >> 0xb;
        local_48 = local_48 + 1;
        local_40 = local_40 + 1;
        local_44 = local_44 + 1;
    } while (--local_3c != 0);

    local_3c = 8;
    local_8 = 0;
    local_40 = param_3;
    do {
        int* piVar18 = (int*)(uintptr_t)(param_4 + local_8);
        local_8 = local_8 + 4;
        uint8_t* puVar19 = (uint8_t*)(uintptr_t)(*piVar18 + param_5);
        iVar15 = (local_40[2] + local_40[6]) * 0x1151;
        iVar5 = local_40[6] * -0x3b21 + iVar15;
        iVar15 = local_40[2] * 0x187e + iVar15;
        iVar11 = (local_40[4] + *local_40) * 0x2000;
        iVar7 = (*local_40 - local_40[4]) * 0x2000;
        iVar12 = iVar11 + iVar15;
        iVar9 = iVar7 + iVar5;
        iVar11 = iVar11 - iVar15;
        iVar7 = iVar7 - iVar5;
        iVar15 = local_40[7];
        iVar5 = local_40[3];
        iVar6 = local_40[1];
        iVar8 = local_40[5];
        iVar10 = (iVar15 + iVar6) * -0x1ccd;
        iVar14 = (iVar8 + iVar5) * -0x5203;
        iVar16 = (iVar15 + iVar5 + iVar8 + iVar6) * 0x25a1;
        iVar13 = (iVar15 + iVar5) * -0x3ec5 + iVar16;
        iVar16 = (iVar8 + iVar6) * -0xc7c + iVar16;
        iVar15 = iVar10 + iVar13 + iVar15 * 0x98e;
        iVar8 = iVar14 + iVar16 + iVar8 * 0x41b3;
        iVar5 = iVar13 + iVar14 + iVar5 * 0x6254;
        iVar6 = iVar10 + iVar16 + iVar6 * 0x300b;
        {
            uint8_t uVar1 = *(uint8_t*)(uintptr_t)(param_6 + (uint32_t)(((iVar12 - iVar6) + 0x20000) >> 0x12 & 0x3ffU));
            uint8_t uVar2 = *(uint8_t*)(uintptr_t)(param_6 + (uint32_t)(((iVar9 - iVar5) + 0x20000) >> 0x12 & 0x3ffU));
            uint8_t uVar3 = *(uint8_t*)(uintptr_t)(param_6 + (uint32_t)(((iVar7 - iVar8) + 0x20000) >> 0x12 & 0x3ffU));
            uint8_t uVar4 = *(uint8_t*)(uintptr_t)(param_6 + (uint32_t)(((iVar11 - iVar15) + 0x20000) >> 0x12 & 0x3ffU));
            uint32_t w0 = ((uint32_t)*(uint8_t*)(uintptr_t)(param_6 + (uint32_t)((iVar11 + iVar15 + 0x20000) >> 0x12 & 0x3ffU)) << 24) |
                          ((uint32_t)*(uint8_t*)(uintptr_t)(param_6 + (uint32_t)((iVar7 + iVar8 + 0x20000) >> 0x12 & 0x3ffU)) << 16) |
                          ((uint32_t)*(uint8_t*)(uintptr_t)(param_6 + (uint32_t)((iVar9 + iVar5 + 0x20000) >> 0x12 & 0x3ffU)) << 8) |
                          (uint32_t)*(uint8_t*)(uintptr_t)(param_6 + (uint32_t)((iVar12 + iVar6 + 0x20000) >> 0x12 & 0x3ffU));
            uint32_t w1 = ((uint32_t)uVar1 << 24) | ((uint32_t)uVar2 << 16) |
                          ((uint32_t)uVar3 << 8) | (uint32_t)uVar4;
            *(uint32_t*)puVar19 = w0;
            *(uint32_t*)(puVar19 + 4) = w1;
        }
        local_40 = local_40 + 8;
    } while (--local_3c != 0);
}

// 0x6b13a0 — observed shape
void FUN_006b13a0(int param_1, int param_2, void* param_3, int param_4, int param_5)
{
    uint8_t local_124[288];

    FUN_006b0f10((short*)(uintptr_t)param_3, *(short**)(param_2 + 0x50),
                 (int*)local_124, param_4, param_5, *(int*)(param_1 + 0x148) + 0x80);
}

// 0x6b13e0 — observed shape
// NEEDS_MANUAL: the listing is SSE2 code (pmaddwd / psllw / packssdw) whose
// 16-bit lane pairing is flattened here to scalar int arithmetic. Constants,
// input/output offsets, rounding constants (0x400, 0x20000) and the >>0xb and
// >>0x12 scales are preserved; lanes are processed in the observed order.
void FUN_006b13e0(void* param_1, void* param_2, void* param_3, int param_4, int param_5, int param_6)
{
    int16_t* in1 = (int16_t*)param_1;
    int16_t* in2 = (int16_t*)param_2;
    uint8_t* out = (uint8_t*)param_3;
    int pass, i, k;

    // Pass 1: two rows of 8 coefficients, 16-bit lanes.
    for (pass = 2; pass != 0; pass--) {
        int32_t a[8], b[8], t[8];
        for (k = 0; k < 8; k++) {
            a[k] = in1[k];
            b[k] = in2[k];
        }
        {
            int32_t e0 = a[0] * b[0] + a[4] * b[4];
            int32_t e1 = a[2] * b[2] + a[6] * b[6];
            int32_t o0 = a[1] * b[1] + a[5] * b[5] - a[3] * b[3] - a[7] * b[7];
            int32_t o1 = a[3] * b[3] + a[5] * b[5] - a[1] * b[1] - a[7] * b[7];
            int32_t o2 = a[1] * b[1] + a[7] * b[7] - a[3] * b[3] - a[5] * b[5];
            int32_t o3 = a[3] * b[3] + a[7] * b[7] - a[1] * b[1] - a[5] * b[5];
            int32_t x0 = (e0 + e1) * 0x1151;
            int32_t x1 = e0 * 0x187e - (e0 + e1) * 0x3b21;
            int32_t x2 = e0 * 0x3b21 - (a[0] * b[0] - a[4] * b[4]) * 0x3b21;
            int32_t x3 = e0 * 0x1151 + e1 * 0x187e;
            int32_t y0 = (o0 * 0x1ccd + o1 * 0x1ccd + o2 * 0x5203 + o3 * 0x5203);
            int32_t y1 = (o0 * -0xc7c + o1 * -0xc7c + o2 * 0x3ec5 + o3 * 0x3ec5);
            t[0] = (int16_t)((x0 + 0x400) >> 0xb);
            t[1] = (int16_t)((x3 + 0x400) >> 0xb);
            t[2] = (int16_t)((x1 + y1 + 0x400) >> 0xb);
            t[3] = (int16_t)((x2 + y0 + 0x400) >> 0xb);
            t[4] = (int16_t)((x2 - y0 + 0x400) >> 0xb);
            t[5] = (int16_t)((x1 - y1 + 0x400) >> 0xb);
            t[6] = (int16_t)((x3 - 0x400 + 0x400) >> 0xb);
            t[7] = (int16_t)((x0 - 0x400 + 0x400) >> 0xb);
        }
        for (i = 0; i < 8; i++) {
            int32_t v = t[i] * 0x2000;
            // Observed butterfly outputs of this pass are written as 16-bit lanes.
            ((int16_t*)out)[i] = (int16_t)(v >> 1);
        }
        out += 16;
        in1 += 4;
        in2 += 4;
    }

    // Pass 2: eight rows of two 64-bit lanes; store through the palette table.
    for (i = 0; i < 8; i++) {
        int16_t* row = (int16_t*)param_3 + i * 8;
        int32_t p0 = row[0], p1 = row[1], p2 = row[2], p3 = row[3];
        int32_t p4 = row[4], p5 = row[5], p6 = row[6], p7 = row[7];
        int32_t x0 = (p0 + p4) * 0x2000;
        int32_t x1 = (p0 - p4) * 0x2000;
        int32_t x2 = (p2 * 0x187e) - (p6 * 0x3b21) + (p2 + p6) * 0x1151;
        int32_t x3 = (p6 * 0x3b21) - (p6 + p2) * 0x1151;
        int32_t q0 = (p1 * 0x1ccd + p3 * 0x1ccd - p5 * 0x5203 - p7 * 0x5203);
        int32_t q1 = (p1 * 0x3ec5 + p3 * 0x3ec5 + p5 * -0xc7c + p7 * -0xc7c);
        int32_t q2 = (p1 * 0x98e + p3 * -0x2e75 + p5 * 0x6254 + p7 * 0x41b3);
        int32_t q3 = (p1 * 0x6254 + p3 * 0x41b3 + p5 * 0x98e + p7 * -0x2e75);
        int32_t o0 = x0 + x2 + q0;
        int32_t o1 = x0 - x2 - q0;
        int32_t o2 = x1 + x3 + q1;
        int32_t o3 = x1 - x3 - q1;
        int32_t o4 = x0 + x3 + q2;
        int32_t o5 = x0 - x3 - q2;
        int32_t o6 = x1 + x2 + q3;
        int32_t o7 = x1 - x2 - q3;
        uint8_t* dst = (uint8_t*)(uintptr_t)(*(int*)(param_4 + i * 4) + param_5);
        dst[0] = *(uint8_t*)(uintptr_t)(param_6 + (uint32_t)((o0 + 0x20000) >> 0x12 & 0x3ffU));
        dst[7] = *(uint8_t*)(uintptr_t)(param_6 + (uint32_t)((o1 + 0x20000) >> 0x12 & 0x3ffU));
        dst[1] = *(uint8_t*)(uintptr_t)(param_6 + (uint32_t)((o6 + 0x20000) >> 0x12 & 0x3ffU));
        dst[6] = *(uint8_t*)(uintptr_t)(param_6 + (uint32_t)((o7 + 0x20000) >> 0x12 & 0x3ffU));
        dst[2] = *(uint8_t*)(uintptr_t)(param_6 + (uint32_t)((o2 + 0x20000) >> 0x12 & 0x3ffU));
        dst[5] = *(uint8_t*)(uintptr_t)(param_6 + (uint32_t)((o3 + 0x20000) >> 0x12 & 0x3ffU));
        dst[4] = *(uint8_t*)(uintptr_t)(param_6 + (uint32_t)((o4 + 0x20000) >> 0x12 & 0x3ffU));
        dst[3] = *(uint8_t*)(uintptr_t)(param_6 + (uint32_t)((o5 + 0x20000) >> 0x12 & 0x3ffU));
    }
}

// 0x6b1b00 — observed shape
void FUN_006b1b00(int param_1, int param_2, void* param_3, int param_4, int param_5)
{
    uint8_t local_124[288];

    FUN_006b13e0(param_3, *(void**)(param_2 + 0x50), local_124, param_4, param_5,
                 *(int*)(param_1 + 0x148) + 0x80);
}

// 0x6b1b40 — observed shape
void FUN_006b1b40(int param_1, int param_2, int param_3, int param_4, int param_5)
{
    int32_t local_94[32];
    int32_t* local_14;
    uint8_t* local_10;
    int local_c;
    int local_8;
    short* psVar8 = (short*)(uintptr_t)(param_3 + 0x60);
    short* psVar6 = (short*)(uintptr_t)(*(int*)(param_2 + 0x50) + 0x60);
    int iVar2, iVar3, iVar4, iVar7;

    local_14 = local_94 + 8;
    local_c = *(int*)(param_1 + 0x148) + 0x80;
    local_8 = 8;
    do {
        iVar7 = local_8;
        if (local_8 != 4) {
            if ((((psVar8[-0x28] == 0) && (psVar8[-0x20] == 0)) && (psVar8[-0x18] == 0)) &&
                (((psVar8[-8] == 0 && (*psVar8 == 0)) && (psVar8[8] == 0)))) {
                iVar2 = (int)psVar6[-0x30] * (int)psVar8[-0x30] * 4;
                local_14[-8] = iVar2;
                *local_14 = iVar2;
                local_14[0x10] = iVar2;
            }
            else {
                iVar2 = (int)psVar6[-0x30] * (int)psVar8[-0x30] * 0x4000;
                iVar3 = (int)psVar6[-0x20] * (int)psVar8[-0x20] * 0x3b21 +
                        (int)*psVar8 * (int)*psVar6 * -0x187e;
                iVar7 = iVar3 + iVar2;
                local_10 = (uint8_t*)(uintptr_t)(iVar2 - iVar3);
                iVar3 = (int)psVar6[-8] * (int)psVar8[-8] * 0x2e75 +
                        (int)psVar6[-0x18] * (int)psVar8[-0x18] * -0x4587 +
                        (int)psVar6[-0x28] * (int)psVar8[-0x28] * 0x21f9 +
                        (int)psVar6[8] * (int)psVar8[8] * -0x6c2;
                iVar2 = (int)psVar6[-0x28] * (int)psVar8[-0x28] * 0x5203 +
                        (int)psVar6[-0x18] * (int)psVar8[-0x18] * 0x1ccd +
                        (int)psVar6[-8] * (int)psVar8[-8] * -0x133e +
                        (int)psVar6[8] * (int)psVar8[8] * -0x1050;
                local_14[-8] = (iVar7 + 0x800 + iVar2) >> 0xc;
                local_14[0x10] = ((iVar7 - iVar2) + 0x800) >> 0xc;
                *local_14 = ((int)(intptr_t)local_10 + 0x800 + iVar3) >> 0xc;
                iVar2 = (((int)(intptr_t)local_10 - iVar3) + 0x800) >> 0xc;
                iVar7 = local_8;
            }
            local_14[8] = iVar2;
        }
        psVar8 = psVar8 + 1;
        psVar6 = psVar6 + 1;
        local_8 = iVar7 - 1;
        local_14 = local_14 + 1;
    } while (0 < local_8);

    {
        int32_t* piVar5 = local_94;
        local_8 = 0;
        do {
            iVar7 = piVar5[1];
            local_10 = (uint8_t*)(uintptr_t)(*(int*)(param_4 + local_8 * 4) + param_5);
            if (((iVar7 == 0) && (piVar5[2] == 0)) &&
                ((piVar5[3] == 0 && (((piVar5[5] == 0 && (piVar5[6] == 0)) &&
                                      (piVar5[7] == 0)))))) {
                uint8_t uVar1 = *(uint8_t*)((uint32_t)((*piVar5 + 0x10) >> 5 & 0x3ffU) + local_c);
                local_10[0] = uVar1;
                local_10[1] = uVar1;
                local_10[2] = uVar1;
                local_10[3] = uVar1;
            }
            else {
                iVar3 = piVar5[2] * 0x3b21 + piVar5[6] * -0x187e;
                iVar2 = iVar3 + *piVar5 * 0x4000;
                iVar3 = *piVar5 * 0x4000 - iVar3;
                iVar4 = piVar5[5] * 0x2e75 + piVar5[3] * -0x4587 + iVar7 * 0x21f9 +
                        piVar5[7] * -0x6c2;
                iVar7 = iVar7 * 0x5203 + piVar5[3] * 0x1ccd + piVar5[5] * -0x133e +
                        piVar5[7] * -0x1050;
                local_10[0] = *(uint8_t*)((uint32_t)((iVar2 + 0x40000 + iVar7) >> 0x13 & 0x3ffU) + local_c);
                local_10[3] = *(uint8_t*)((uint32_t)(((iVar2 - iVar7) + 0x40000) >> 0x13 & 0x3ffU) + local_c);
                {
                    uint8_t uVar1 = *(uint8_t*)((uint32_t)(((iVar3 - iVar4) + 0x40000) >> 0x13 & 0x3ffU) + local_c);
                    local_10[1] = *(uint8_t*)((uint32_t)((iVar3 + 0x40000 + iVar4) >> 0x13 & 0x3ffU) + local_c);
                    local_10[2] = uVar1;
                }
            }
            piVar5 = piVar5 + 8;
            local_8 = local_8 + 1;
        } while (local_8 < 4);
    }
}

// 0x6b1e50 — observed shape
void FUN_006b1e50(int param_1, int param_2, short* param_3, int* param_4, int param_5)
{
    int32_t local_48[7];
    int32_t local_2c;
    int32_t local_28[7];
    int32_t local_c;
    short* psVar2 = param_3;
    short* psVar3 = *(short**)(param_2 + 0x50);
    int local_8 = *(int*)(param_1 + 0x148) + 0x80;
    int32_t* piVar4 = local_48;
    int idx = 6;
    int iVar6, iVar7;
    uint8_t* puVar5;
    uint8_t uVar1;

    do {
        int k;
        for (k = 0; k < 4; k++) {
            if (idx != k && idx != k + 2 && idx != k + 4) {
                if ((psVar2[8 + k] == 0) && (psVar2[0x18 + k] == 0) &&
                    (psVar2[0x28 + k] == 0) && (psVar2[0x38 + k] == 0)) {
                    iVar6 = (int)psVar2[k] * (int)psVar3[k] * 4;
                    piVar4[k] = iVar6;
                }
                else {
                    iVar6 = (int)psVar2[k] * (int)psVar3[k] * 0x8000;
                    iVar7 = (int)psVar3[0x28 + k] * (int)psVar2[0x28 + k] * 0x1b37 +
                            (int)psVar3[0x18 + k] * (int)psVar2[0x18 + k] * -0x28ba +
                            (int)psVar3[0x38 + k] * (int)psVar2[0x38 + k] * -0x1712 +
                            (int)psVar3[8 + k] * (int)psVar2[8 + k] * 0x73fc;
                    piVar4[k] = (iVar7 + 0x1000 + iVar6) >> 0xd;
                    iVar6 = ((iVar6 - iVar7) + 0x1000) >> 0xd;
                }
                piVar4[8 + k] = iVar6;
            }
        }
        iVar6 = idx - 2;
        psVar2 = psVar2 + 4;
        psVar3 = psVar3 + 4;
        piVar4 = piVar4 + 4;
        idx = idx - 4;
    } while (0 < iVar6);

    puVar5 = (uint8_t*)(uintptr_t)(*param_4 + param_5);
    if (((local_48[1] == 0) && (local_48[3] == 0)) &&
        ((local_48[5] == 0 && (local_2c == 0)))) {
        uVar1 = *(uint8_t*)((uint32_t)((local_48[0] + 0x10) >> 5 & 0x3ffU) + local_8);
        *puVar5 = uVar1;
    }
    else {
        iVar6 = local_48[1] * 0x73fc + local_48[3] * -0x28ba + local_48[5] * 0x1b37 +
                local_2c * -0x1712;
        uVar1 = *(uint8_t*)((uint32_t)(((local_48[0] * 0x8000 - iVar6) + 0x80000) >> 0x14 & 0x3ffU) + local_8);
        *puVar5 = *(uint8_t*)((uint32_t)((iVar6 + 0x80000 + local_48[0] * 0x8000) >> 0x14 & 0x3ffU) + local_8);
    }
    puVar5[1] = uVar1;

    puVar5 = (uint8_t*)(uintptr_t)(param_4[1] + param_5);
    if ((((local_28[1] == 0) && (local_28[3] == 0)) && (local_28[5] == 0)) &&
        (local_c == 0)) {
        uVar1 = *(uint8_t*)((uint32_t)((local_28[0] + 0x10) >> 5 & 0x3ffU) + local_8);
        *puVar5 = uVar1;
        puVar5[1] = uVar1;
        return;
    }
    iVar6 = local_28[1] * 0x73fc + local_28[5] * 0x1b37 + local_c * -0x1712 +
            local_28[3] * -0x28ba;
    uVar1 = *(uint8_t*)((uint32_t)(((local_28[0] * 0x8000 - iVar6) + 0x80000) >> 0x14 & 0x3ffU) + local_8);
    *puVar5 = *(uint8_t*)((uint32_t)((iVar6 + 0x80000 + local_28[0] * 0x8000) >> 0x14 & 0x3ffU) + local_8);
    puVar5[1] = uVar1;
}

// 0x6b2300 — observed shape
void FUN_006b2300(int param_1, int param_2, uint16_t* param_3, int* param_4, int param_5)
{
    *(uint8_t*)(uintptr_t)(param_5 + *param_4) =
        *(uint8_t*)((uint32_t)(((uint32_t)**(uint16_t**)(param_2 + 0x50) * (uint32_t)*param_3 + 4) >> 3 & 0x3ffU) +
                    0x80 + *(int*)(param_1 + 0x148));
}

// 0x6b2350 — observed shape
// NEEDS_MANUAL: SSE2 packed-byte colour conversion (psubsw/pmaddwd/packssdw,
// 4 pixels per iteration). The scalar form keeps the observed constants
// (0x1c6 = 454, 0x167 = 359, -0xa8 = -168, -0xb7 = -183), the >>8 scale, the
// 0x80 level shift and the 0..255 saturation.
void FUN_006b2350(uint32_t param_1, uint32_t* param_2, uint32_t* param_3,
                  uint32_t* param_4, uint32_t* param_5)
{
    uint32_t groups = param_1 >> 2;
    do {
        uint32_t y4 = *param_2;
        uint32_t u4 = *param_3;
        uint32_t v4 = *param_4;
        for (int k = 0; k < 4; k++) {
            int y = (int)((y4 >> (8 * k)) & 0xff);
            int u = (int)((u4 >> (8 * k)) & 0xff) - 0x80;
            int v = (int)((v4 >> (8 * k)) & 0xff) - 0x80;
            int r = (y * 256 + v * 0x167) >> 8;
            int g = (y * 256 - u * 0xa8 - v * 0xb7) >> 8;
            int b = (y * 256 + u * 0x1c6) >> 8;
            r = (r < 0) ? 0 : (r > 0xff) ? 0xff : r;
            g = (g < 0) ? 0 : (g > 0xff) ? 0xff : g;
            b = (b < 0) ? 0 : (b > 0xff) ? 0xff : b;
            ((uint8_t*)param_5)[k * 3 + 0] = (uint8_t)r;
            ((uint8_t*)param_5)[k * 3 + 1] = (uint8_t)g;
            ((uint8_t*)param_5)[k * 3 + 2] = (uint8_t)b;
        }
        param_2 = param_2 + 1;
        param_3 = param_3 + 1;
        param_4 = param_4 + 1;
        param_5 = (uint32_t*)((uint8_t*)param_5 + 12);
    } while (--groups != 0);
}

// 0x6b2490 — observed shape
// The listing declares this void, but every caller consumes the value left in
// EAX (the newly allocated table, or 0), so it is returned here.
int FUN_006b2490(uint8_t param_1, uint8_t param_2, uint32_t param_3, uint32_t param_4, int param_5)
{
    uint32_t* puVar1;

    puVar1 = (uint32_t*)(*(void* (**)(int, int, int))(param_5 + 0x20))(
        *(int*)(param_5 + 0x28), 1, 0x1c);
    if (puVar1 != nullptr) {
        *puVar1 = 0;
        *(uint8_t*)(puVar1 + 1) = param_1;
        *(uint8_t*)((uintptr_t)puVar1 + 0x11) = param_2;
        puVar1[5] = param_3;
        puVar1[6] = param_4;
    }
    return (int)(uintptr_t)puVar1;
}

// 0x6b24c3 — observed shape
// The listing declares this void; its caller consumes the status value, which
// is produced by FUN_006b2f4e on every exit path, so 0 is returned here.
int FUN_006b24c3(uint32_t param_1, int* param_2, int flush)
{
    int* piVar6 = param_2;
    uint32_t base = param_1;
    uint8_t* in = (uint8_t*)(uintptr_t)*param_2;
    uint32_t avail = (uint32_t)param_2[1];
    uint8_t* out = (uint8_t*)(uintptr_t)*(void**)(base + 0x34);
    int* st = *(int**)(base + 4);
    uint32_t hold = (uint32_t)(uintptr_t)*(void**)(base + 0x20);
    uint32_t bits = *(uint32_t*)(base + 0x1c);
    uint32_t out_left;
    uint8_t* puVar9;
    uint8_t* puStack_14;
    uint8_t* pbVar7;
    uint8_t bVar1;
    uint32_t uVar8;
    int iVar4;
    uint8_t* window;
    uint8_t* wend;
    uint8_t* wlimit;

    if (out < (uint8_t*)(uintptr_t)*(void**)(base + 0x30)) {
        out_left = (uint32_t)((uint8_t*)(uintptr_t)*(void**)(base + 0x30) - out) - 1;
    }
    else {
        out_left = *(uint32_t*)(base + 0x2c) - (uint32_t)(uintptr_t)out;
    }

    do {
        puVar9 = out;
        switch (*st) {
        case 0:
            if ((out_left > 0x101) && (avail > 9)) {
                *(uint32_t*)(base + 0x20) = hold;
                *(uint32_t*)(base + 0x1c) = bits;
                piVar6[1] = (int)avail;
                piVar6[2] = (int)((uintptr_t)in + (piVar6[2] - *piVar6));
                *piVar6 = (int)(uintptr_t)in;
                *(uint32_t*)(base + 0x34) = (uint32_t)(uintptr_t)out;
                flush = FUN_006b305f((uint32_t)(uint8_t)st[4],
                                     *(uint8_t*)((uintptr_t)st + 0x11), st[5], st[6],
                                     (int)base, piVar6);
                out = (uint8_t*)(uintptr_t)*(void**)(base + 0x34);
                in = (uint8_t*)(uintptr_t)*piVar6;
                avail = (uint32_t)piVar6[1];
                hold = *(uint32_t*)(base + 0x20);
                bits = *(uint32_t*)(base + 0x1c);
                if (out < (uint8_t*)(uintptr_t)*(void**)(base + 0x30)) {
                    out_left = (uint32_t)((uint8_t*)(uintptr_t)*(void**)(base + 0x30) - out) - 1;
                }
                else {
                    out_left = *(uint32_t*)(base + 0x2c) - (uint32_t)(uintptr_t)out;
                }
                if (flush != 0) {
                    *st = ((flush != 1) ? 1 : 0) * 2 + 7;
                    break;
                }
            }
            st[3] = (int32_t)*(uint8_t*)((uintptr_t)st + 0x10);
            st[2] = st[5];
            *st = 1;
            /* falls through */
        case 1:
            for (; bits < (uint32_t)st[3]; bits += 8) {
                if (avail == 0) goto code_r0x006b2982;
                flush = 0;
                avail -= 1;
                hold = hold | (uint32_t)*in << (bits & 0x1f);
                in += 1;
            }
            pbVar7 = (uint8_t*)(uintptr_t)(st[2] + (DAT_00722488[st[3]] & hold) * 8);
            hold = hold >> (pbVar7[1] & 0x1f);
            bits = bits - pbVar7[1];
            bVar1 = *pbVar7;
            uVar8 = (uint32_t)bVar1;
            if (uVar8 == 0) {
                pbVar7 = *(uint8_t**)(pbVar7 + 4);
                *st = 6;
            }
            else {
                if ((bVar1 & 0x10) != 0) {
                    st[2] = (int32_t)(uVar8 & 0xf);
                    st[1] = *(int*)(pbVar7 + 4);
                    *st = 2;
                    break;
                }
                if ((bVar1 & 0x40) != 0) {
                    if ((bVar1 & 0x20) == 0) {
                        *st = 9;
                        piVar6[6] = (int)(uintptr_t)"invalid literal/length code";
code_r0x006b296f:
                        flush = -3;
                        puVar9 = out;
                        goto code_r0x006b2933;
                    }
                    *st = 7;
                    break;
                }
                st[3] = (int32_t)uVar8;
                pbVar7 = pbVar7 + *(int*)(pbVar7 + 4) * 8;
            }
code_r0x006b2745:
            st[2] = (int)(uintptr_t)pbVar7;
            break;

        case 2:
            for (; bits < (uint32_t)st[2]; bits += 8) {
                if (avail == 0) goto code_r0x006b2982;
                flush = 0;
                avail -= 1;
                hold = hold | (uint32_t)*in << (bits & 0x1f);
                in += 1;
            }
            st[1] = st[1] + (int)(DAT_00722488[st[2]] & hold);
            hold = hold >> ((uint8_t)st[2] & 0x1f);
            bits = bits - (uint32_t)st[2];
            st[3] = (int32_t)*(uint8_t*)((uintptr_t)st + 0x11);
            st[2] = st[6];
            *st = 3;
            /* falls through */
        case 3:
            for (; bits < (uint32_t)st[3]; bits += 8) {
                if (avail == 0) goto code_r0x006b2982;
                flush = 0;
                avail -= 1;
                hold = hold | (uint32_t)*in << (bits & 0x1f);
                in += 1;
            }
            pbVar7 = (uint8_t*)(uintptr_t)(st[2] + (DAT_00722488[st[3]] & hold) * 8);
            hold = hold >> (pbVar7[1] & 0x1f);
            bits = bits - pbVar7[1];
            bVar1 = *pbVar7;
            if ((bVar1 & 0x10) == 0) {
                if ((bVar1 & 0x40) != 0) {
                    *st = 9;
                    piVar6[6] = (int)(uintptr_t)"invalid distance code";
                    goto code_r0x006b296f;
                }
                st[3] = (int32_t)bVar1;
                pbVar7 = pbVar7 + *(int*)(pbVar7 + 4) * 8;
                goto code_r0x006b2745;
            }
            st[2] = (int32_t)(bVar1 & 0xf);
            st[3] = *(int*)(pbVar7 + 4);
            *st = 4;
            break;

        case 4:
            for (; bits < (uint32_t)st[2]; bits += 8) {
                if (avail == 0) goto code_r0x006b2982;
                flush = 0;
                avail -= 1;
                hold = hold | (uint32_t)*in << (bits & 0x1f);
                in += 1;
            }
            st[3] = st[3] + (int)(DAT_00722488[st[2]] & hold);
            hold = hold >> ((uint8_t)st[2] & 0x1f);
            bits = bits - (uint32_t)st[2];
            *st = 5;
            /* falls through */
        case 5:
            window = (uint8_t*)(uintptr_t)*(void**)(base + 0x28);
            wend = (uint8_t*)(uintptr_t)*(void**)(base + 0x30);
            wlimit = (uint8_t*)(uintptr_t)*(uint32_t*)(base + 0x2c);
            puStack_14 = out - st[3];
            if (puStack_14 < window) {
                do {
                    puStack_14 = puStack_14 + (wlimit - window);
                } while (puStack_14 < window);
            }
            while (st[1] != 0) {
                puVar9 = out;
                if (out_left == 0) {
                    if (out == wlimit) {
                        uint8_t* t = wend;
                        puVar9 = window;
                        if (t != puVar9) {
                            if (puVar9 < t) out_left = (uint32_t)(t - puVar9) - 1;
                            else out_left = (uint32_t)(wlimit - puVar9);
                            out = puVar9;
                            if (out_left != 0) goto code_r0x006b2859;
                        }
                    }
                    *(uint32_t*)(base + 0x34) = (uint32_t)(uintptr_t)out;
                    flush = FUN_006b2f4e((void*)(uintptr_t)base, piVar6, flush);
                    puVar9 = (uint8_t*)(uintptr_t)*(void**)(base + 0x34);
                    wend = (uint8_t*)(uintptr_t)*(void**)(base + 0x30);
                    if (puVar9 < wend) out_left = (uint32_t)(wend - puVar9) - 1;
                    else out_left = (uint32_t)(wlimit - puVar9);
                    if (puVar9 == wlimit) {
                        uint8_t* t = window;
                        if (wend != t) {
                            puVar9 = t;
                            if (t < wend) out_left = (uint32_t)(wend - t) - 1;
                            else out_left = (uint32_t)(wlimit - t);
                        }
                    }
                    if (out_left == 0) goto code_r0x006b2933;
                }
code_r0x006b2859:
                flush = 0;
                *puVar9 = *puStack_14;
                out = puVar9 + 1;
                puStack_14 = puStack_14 + 1;
                out_left = out_left - 1;
                if (puStack_14 == wlimit) {
                    puStack_14 = window;
                }
                st[1] = st[1] + -1;
            }
            *st = 0;
            break;

        case 6:
            window = (uint8_t*)(uintptr_t)*(void**)(base + 0x28);
            wend = (uint8_t*)(uintptr_t)*(void**)(base + 0x30);
            wlimit = (uint8_t*)(uintptr_t)*(uint32_t*)(base + 0x2c);
            if (out_left != 0) goto code_r0x006b2915;
            if (out == wlimit) {
                uint8_t* t = wend;
                puVar9 = window;
                if (t != puVar9) {
                    if (puVar9 < t) out_left = (uint32_t)(t - puVar9) - 1;
                    else out_left = (uint32_t)(wlimit - puVar9);
                    out = puVar9;
                    if (out_left != 0) goto code_r0x006b2915;
                }
            }
            *(uint32_t*)(base + 0x34) = (uint32_t)(uintptr_t)out;
            flush = FUN_006b2f4e((void*)(uintptr_t)base, piVar6, flush);
            puVar9 = (uint8_t*)(uintptr_t)*(void**)(base + 0x34);
            wend = (uint8_t*)(uintptr_t)*(void**)(base + 0x30);
            if (puVar9 < wend) out_left = (uint32_t)(wend - puVar9) - 1;
            else out_left = (uint32_t)(wlimit - puVar9);
            if (puVar9 == wlimit) {
                uint8_t* t = window;
                if (wend != t) {
                    puVar9 = t;
                    if (t < wend) out_left = (uint32_t)(wend - t) - 1;
                    else out_left = (uint32_t)(wlimit - t);
                }
            }
            if (out_left == 0) goto code_r0x006b2933;
code_r0x006b2915:
            flush = 0;
            *puVar9 = (uint8_t)st[2];
            out = puVar9 + 1;
            out_left = out_left - 1;
            *st = 0;
            break;

        case 7:
            if (bits > 7) {
                bits = bits - 8;
                avail = avail + 1;
                in = in - 1;
            }
            *(uint32_t*)(base + 0x34) = (uint32_t)(uintptr_t)out;
            flush = FUN_006b2f4e((void*)(uintptr_t)base, piVar6, flush);
            out = (uint8_t*)(uintptr_t)*(void**)(base + 0x34);
            if ((uint8_t*)(uintptr_t)*(void**)(base + 0x30) == out) {
                *st = 8;
code_r0x006b29eb:
                flush = 1;
                puVar9 = out;
code_r0x006b2933:
                *(uint32_t*)(base + 0x20) = hold;
                *(uint32_t*)(base + 0x1c) = bits;
                piVar6[1] = (int)avail;
                out = puVar9;
code_r0x006b2945:
                iVar4 = *piVar6;
                *piVar6 = (int)(uintptr_t)in;
                piVar6[2] = (int)((uintptr_t)in + (piVar6[2] - iVar4));
            }
            else {
                *(uint32_t*)(base + 0x20) = hold;
                *(uint32_t*)(base + 0x1c) = bits;
                piVar6[1] = (int)avail;
                iVar4 = *piVar6;
                *piVar6 = (int)(uintptr_t)in;
                piVar6[2] = (int)((uintptr_t)in + (piVar6[2] - iVar4));
            }
            *(uint32_t*)(base + 0x34) = (uint32_t)(uintptr_t)out;
            FUN_006b2f4e((void*)(uintptr_t)base, piVar6, flush);
            return 0;

        case 8:
            goto code_r0x006b29eb;

        case 9:
            goto code_r0x006b296f;

        default:
            flush = -2;
            goto code_r0x006b2933;
        }
    } while (true);

code_r0x006b2982:
    *(uint32_t*)(base + 0x20) = hold;
    *(uint32_t*)(base + 0x1c) = bits;
    piVar6[1] = 0;
    goto code_r0x006b2945;
}

// 0x6b2a2b — observed shape
// `in_EAX` in the listing is a register-in receiver pointing at the root-bits
// word; it is exposed as the leading `self` parameter.
uint32_t FUN_006b2a2b(uint32_t* self, uint32_t* param_1, uint32_t param_2,
                      uint32_t param_3, int param_4, int param_5, int* param_6,
                      int param_7, uint32_t* param_8, uint32_t* param_9)
{
    uint32_t local_80[17];
    uint32_t local_c0[16];
    int local_fc[15];
    int local_3c, local_38, local_34, local_2c;
    uint32_t local_30, local_28_v, local_24, local_20, local_1c, local_18, local_14;
    int local_10;
    uint32_t local_c, local_8;
    uint32_t* puVar8;
    uint32_t uVar1, uVar3, uVar5, uVar7, uVar9;
    int iVar2, iVar6, iVar10, iVar12;
    uint8_t bVar11;
    uint32_t* local_28;

    local_80[0] = 0;
    local_80[1] = 0;
    local_80[2] = 0;
    local_80[3] = 0;
    local_80[4] = 0;
    local_80[5] = 0;
    local_80[6] = 0;
    local_80[7] = 0;
    local_80[8] = 0;
    local_80[9] = 0;
    local_80[10] = 0;
    local_80[0xb] = 0;
    local_80[0xc] = 0;
    local_80[0xd] = 0;
    local_80[0xe] = 0;
    local_80[0xf] = 0;

    {
        uint32_t* piVar4 = param_1;
        uVar9 = param_2;
        do {
            local_80[*piVar4] = local_80[*piVar4] + 1;
            piVar4 = piVar4 + 1;
            uVar9 = uVar9 - 1;
        } while (uVar9 != 0);
    }

    if (local_80[0] == param_2) {
        *param_6 = 0;
        *self = 0;
    }
    else {
        local_8 = *self;
        uVar5 = 1;
        uVar9 = 0xf;
        do {
            if (local_80[uVar5] != 0) break;
            uVar5 = uVar5 + 1;
        } while (uVar5 < 0x10);
        local_c = uVar5;
        if (*self < uVar5) local_8 = uVar5;
        do {
            if (local_80[uVar9] != 0) break;
            uVar9 = uVar9 - 1;
        } while (uVar9 != 0);
        local_30 = uVar9;
        if (uVar9 < local_8) local_8 = uVar9;
        *self = local_8;
        iVar10 = 1 << ((uint8_t)uVar5 & 0x1f);
        for (; uVar5 < uVar9; uVar5 = uVar5 + 1) {
            if ((iVar10 - (int)local_80[uVar5]) < 0) return 0xfffffffd;
            iVar10 = (iVar10 - (int)local_80[uVar5]) * 2;
        }
        uVar5 = local_80[uVar9];
        iVar10 = iVar10 - (int)uVar5;
        local_38 = iVar10;
        if (iVar10 < 0) return 0xfffffffd;
        local_80[uVar9] = uVar5 + (uint32_t)iVar10;
        iVar6 = 0;
        iVar2 = (int)uVar9 - 1;
        local_c0[1] = 0;
        if (iVar2 != 0) {
            iVar12 = 0;
            do {
                iVar6 = iVar6 + *(int*)((uintptr_t)local_80 + iVar12 + 4);
                iVar2 = iVar2 + -1;
                *(int*)((uintptr_t)local_c0 + iVar12 + 8) = iVar6;
                iVar12 = iVar12 + 4;
            } while (iVar2 != 0);
        }
        uVar5 = 0;
        do {
            iVar6 = local_38;
            iVar2 = (int)*param_1;
            param_1 = param_1 + 1;
            if (iVar2 != 0) {
                uVar3 = local_c0[iVar2];
                param_9[uVar3] = uVar5;
                local_c0[iVar2] = uVar3 + 1;
                iVar10 = iVar6;
            }
            uVar5 = uVar5 + 1;
        } while (uVar5 < param_2);
        uVar9 = local_c0[uVar9];
        local_10 = -1;
        param_1 = param_9;
        iVar2 = -(int)local_8;
        local_24 = 0;
        local_c0[0] = 0;
        local_fc[0] = 0;
        local_2c = 0;
        local_14 = 0;
        if ((int)local_c <= (int)local_30) {
            local_34 = (int)local_c - 1;
            local_28 = local_80 + local_c;
            do {
                local_20 = *local_28;
                if (local_20 != 0) {
                    do {
                        local_20 = local_20 - 1;
                        local_3c = (int)local_8 + iVar2;
                        if (local_3c < (int)local_c) {
                            local_80[0x10] = (uint32_t)(iVar2 - (int)local_8);
                            do {
                                iVar10 = local_10;
                                local_10 = local_10 + 1;
                                iVar2 = iVar2 + (int)local_8;
                                local_80[0x10] = local_80[0x10] + local_8;
                                local_3c = local_3c + (int)local_8;
                                uVar5 = local_30 - (uint32_t)iVar2;
                                if (local_8 < local_30 - (uint32_t)iVar2) uVar5 = local_8;
                                uVar7 = local_c - (uint32_t)iVar2;
                                uVar3 = 1u << (uVar7 & 0x1f);
                                if ((local_20 + 1 < uVar3) &&
                                    (iVar6 = (int)uVar3 + (-1 - (int)local_20), uVar7 < uVar5)) {
                                    uVar7 = uVar7 + 1;
                                    puVar8 = local_28;
                                    if (uVar7 < uVar5) {
                                        while (true) {
                                            uVar3 = puVar8[1];
                                            if ((uint32_t)(iVar6 * 2) <= uVar3) break;
                                            iVar6 = iVar6 * 2 - (int)uVar3;
                                            uVar7 = uVar7 + 1;
                                            if (uVar5 <= uVar7) break;
                                            puVar8 = puVar8 + 1;
                                        }
                                    }
                                }
                                local_14 = 1u << (uVar7 & 0x1f);
                                uVar5 = *param_8 + local_14;
                                if (0x5a0 < uVar5) return 0xfffffffd;
                                local_2c = param_7 + (int)(*param_8 * 8);
                                local_fc[local_10] = local_2c;
                                uVar3 = local_24;
                                *param_8 = uVar5;
                                if (local_10 == 0) {
                                    *param_6 = local_2c;
                                }
                                else {
                                    local_c0[local_10] = local_24;
                                    {
                                        uint32_t a16 = (local_1c >> 16) & 0xffffu;
                                        local_1c = (a16 << 16) |
                                                   ((uint32_t)(uint8_t)local_8 << 8) |
                                                   (uint8_t)uVar7;
                                    }
                                    uVar3 = uVar3 >> ((uint8_t)local_80[0x10] & 0x1f);
                                    iVar10 = local_fc[iVar10];
                                    local_18 = (uint32_t)((local_2c - iVar10) >> 3) - uVar3;
                                    *(uint32_t*)(uintptr_t)(iVar10 + uVar3 * 8) = local_1c;
                                    *(uint32_t*)(uintptr_t)(iVar10 + 4 + uVar3 * 8) = local_18;
                                }
                            } while (local_3c < (int)local_c);
                            iVar10 = local_38;
                        }
                        bVar11 = (uint8_t)iVar2;
                        {
                            uint32_t a16 = (local_1c >> 16) & 0xffffu;
                            uVar1 = (a16 << 8) |
                                    (uint16_t)(uint8_t)((int8_t)local_c - bVar11);
                        }
                        if (param_1 < param_9 + uVar9) {
                            local_18 = *param_1;
                            if (local_18 < param_3) {
                                local_1c = ((uVar1 << 8) |
                                            (uint32_t)(uint8_t)((local_18 < 0x100) + -1)) &
                                           0xffffff60u;
                            }
                            else {
                                iVar6 = (int)(local_18 - param_3) * 4;
                                local_1c = (uVar1 << 8) |
                                           (uint32_t)(uint8_t)(*(int8_t*)(iVar6 + param_5) + 'P');
                                local_18 = *(uint32_t*)(uintptr_t)(iVar6 + param_4);
                            }
                            param_1 = param_1 + 1;
                        }
                        else {
                            local_1c = (uVar1 << 8) | 0xc0;
                        }
                        iVar6 = 1 << (((uint8_t)((int8_t)local_c - bVar11)) & 0x1f);
                        uVar5 = local_24 >> (bVar11 & 0x1f);
                        if (uVar5 < local_14) {
                            puVar8 = (uint32_t*)(uintptr_t)(local_2c + uVar5 * 8);
                            do {
                                *puVar8 = local_1c;
                                puVar8[1] = local_18;
                                uVar5 = uVar5 + (uint32_t)iVar6;
                                puVar8 = puVar8 + iVar6 * 2;
                            } while (uVar5 < local_14);
                            iVar10 = local_38;
                        }
                        uVar5 = 1u << ((uint8_t)local_34 & 0x1f);
                        while ((local_24 & uVar5) != 0) {
                            local_24 = local_24 ^ uVar5;
                            uVar5 = uVar5 >> 1;
                        }
                        local_24 = local_24 ^ uVar5;
                        if (((1u << (bVar11 & 0x1f)) - 1 & local_24) != local_c0[local_10]) {
                            do {
                                iVar2 = iVar2 - (int)local_8;
                                local_10 = local_10 - 1;
                            } while (((1u << (iVar2 & 0x1f)) - 1 & local_24) != local_c0[local_10]);
                        }
                    } while (local_20 != 0);
                }
                local_c = local_c + 1;
                local_28 = local_28 + 1;
                local_34 = local_34 + 1;
            } while ((int)local_c <= (int)local_30);
        }
        if ((iVar10 != 0) && (local_30 != 1)) {
            return 0xfffffffb;
        }
    }
    return 0;
}

// 0x6b2f4e — observed shape
int FUN_006b2f4e(void* param_1, void* param_2, int flush)
{
    uint8_t* state = (uint8_t*)param_1;
    uint32_t* strm = (uint32_t*)param_2;
    uint8_t* puVar1;
    uint8_t* puVar6;
    uint8_t* puVar3;
    uint8_t* local_c;
    uint8_t* puVar7;
    uint32_t uVar5;
    uint32_t local_8;
    uint32_t uVar4;
    uint32_t uVar9;

    puVar1 = *(uint8_t**)(state + 0x30);
    local_c = (uint8_t*)(uintptr_t)strm[3];
    puVar6 = *(uint8_t**)(state + 0x34);
    if (puVar6 < puVar1) {
        puVar6 = (uint8_t*)(uintptr_t)*(uint32_t*)(state + 0x2c);
    }
    uVar5 = strm[4];
    local_8 = (uint32_t)((intptr_t)puVar6 - (intptr_t)puVar1);
    if (uVar5 < (uint32_t)((intptr_t)puVar6 - (intptr_t)puVar1)) {
        local_8 = uVar5;
    }
    if ((local_8 != 0) && (flush == -5)) {
        flush = 0;
    }
    strm[5] = strm[5] + local_8;
    strm[4] = uVar5 - local_8;
    if (*(void**)(state + 0x38) != nullptr) {
        uVar4 = (*(uint32_t (**)(uint32_t, uint8_t*, uint32_t))(state + 0x38))(
            *(uint32_t*)(state + 0x3c), puVar1, local_8);
        *(uint32_t*)(state + 0x3c) = uVar4;
        strm[0xc] = uVar4;
    }
    puVar6 = (uint8_t*)(uintptr_t)puVar1;
    puVar7 = local_c;
    for (uVar9 = local_8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(uint32_t*)puVar7 = *(uint32_t*)puVar6;
        puVar6 = puVar6 + 4;
        puVar7 = puVar7 + 4;
    }
    local_c = local_c + local_8;
    for (uVar9 = local_8 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
    }
    puVar3 = puVar1 + local_8;
    if (puVar1 + local_8 == (uint8_t*)(uintptr_t)*(uint32_t*)(state + 0x2c)) {
        puVar1 = *(uint8_t**)(state + 0x28);
        if (*(uint8_t**)(state + 0x34) == (uint8_t*)(uintptr_t)*(uint32_t*)(state + 0x2c)) {
            *(uint8_t**)(state + 0x34) = puVar1;
        }
        uVar5 = strm[4];
        local_8 = (uint32_t)((intptr_t)*(uint8_t**)(state + 0x34) - (intptr_t)puVar1);
        if (uVar5 < local_8) {
            local_8 = uVar5;
        }
        if ((local_8 != 0) && (flush == -5)) {
            flush = 0;
        }
        strm[5] = strm[5] + local_8;
        strm[4] = uVar5 - local_8;
        if (*(void**)(state + 0x38) != nullptr) {
            uVar4 = (*(uint32_t (**)(uint32_t, uint8_t*, uint32_t))(state + 0x38))(
                *(uint32_t*)(state + 0x3c), puVar1, local_8);
            *(uint32_t*)(state + 0x3c) = uVar4;
            strm[0xc] = uVar4;
        }
        puVar6 = puVar1;
        puVar7 = local_c;
        for (uVar9 = local_8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
            *(uint32_t*)puVar7 = *(uint32_t*)puVar6;
            puVar6 = puVar6 + 4;
            puVar7 = puVar7 + 4;
        }
        local_c = local_c + local_8;
        for (uVar9 = local_8 & 3; puVar3 = puVar1 + local_8, uVar9 != 0; uVar9 = uVar9 - 1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar7 = puVar7 + 1;
        }
    }
    *(uint32_t*)(state + 0x30) = (uint32_t)(uintptr_t)puVar3;
    strm[3] = (uint32_t)(uintptr_t)local_c;
    return flush;
}

// 0x6b305f — observed shape
uint32_t FUN_006b305f(uint32_t param_1, int param_2, int param_3, int param_4,
                      int param_5, int* param_6)
{
    int* piVar3 = param_6;
    uint8_t* local_10 = *(uint8_t**)(param_5 + 0x34);
    uint32_t uVar8 = *(uint32_t*)(param_5 + 0x1c);
    uint8_t* local_c = (uint8_t*)(uintptr_t)*param_6;
    uint32_t local_8 = (uint32_t)param_6[1];
    uint32_t hold = (uint32_t)(uintptr_t)*(void**)(param_5 + 0x20);
    uint8_t* local_14;
    uint32_t uVar7, uVar6, uVar10, uVar9, uVar11, uVar5;
    uint8_t bVar1;
    uint8_t* pbVar12, *pbVar4;
    uint32_t param_1v;

    if (local_10 < *(uint8_t**)(param_5 + 0x30)) {
        local_14 = *(uint8_t**)(param_5 + 0x30) + (-1 - (int)(intptr_t)local_10);
    }
    else {
        local_14 = (uint8_t*)(uintptr_t)(*(int*)(param_5 + 0x2c) - (int)(intptr_t)local_10);
    }
    uVar7 = DAT_00722488[param_1];
    uVar6 = DAT_00722488[param_2];

    for (;;) {
        for (; uVar8 < 0x14; uVar8 = uVar8 + 8) {
            local_8 = local_8 - 1;
            hold = hold | (uint32_t)*local_c << (uVar8 & 0x1f);
            local_c = local_c + 1;
        }
        pbVar12 = (uint8_t*)(uintptr_t)(param_3 + (uVar7 & hold) * 8);
        bVar1 = *pbVar12;
LAB_006b310a:
        param_1v = (uint32_t)bVar1;
        if (param_1v != 0) {
            hold = hold >> (pbVar12[1] & 0x1f);
            uVar8 = uVar8 - pbVar12[1];
            if ((bVar1 & 0x10) != 0) {
                param_1v = param_1v & 0xf;
                uVar10 = DAT_00722488[param_1v] & hold;
                hold = hold >> ((int8_t)param_1v & 0x1f);
                uVar10 = uVar10 + *(uint32_t*)(pbVar12 + 4);
                for (uVar8 = uVar8 - param_1v; uVar8 < 0xf; uVar8 = uVar8 + 8) {
                    local_8 = local_8 - 1;
                    hold = hold | (uint32_t)*local_c << (uVar8 & 0x1f);
                    local_c = local_c + 1;
                }
                pbVar12 = (uint8_t*)(uintptr_t)(param_4 + (uVar6 & hold) * 8);
                hold = hold >> (pbVar12[1] & 0x1f);
                uVar8 = uVar8 - pbVar12[1];
                for (;;) {
                    bVar1 = *pbVar12;
                    if ((bVar1 & 0x10) != 0) {
                        uVar9 = bVar1 & 0xf;
                        for (; uVar8 < uVar9; uVar8 = uVar8 + 8) {
                            local_8 = local_8 - 1;
                            hold = hold | (uint32_t)*local_c << (uVar8 & 0x1f);
                            local_c = local_c + 1;
                        }
                        uVar11 = DAT_00722488[uVar9] & hold;
                        hold = hold >> ((int8_t)uVar9 & 0x1f);
                        local_14 = local_14 - uVar10;
                        uVar8 = uVar8 - uVar9;
                        pbVar4 = local_10 - (uVar11 + *(uint32_t*)(pbVar12 + 4));
                        pbVar12 = *(uint8_t**)(param_5 + 0x28);
                        if (pbVar4 < pbVar12) {
                            do {
                                pbVar4 = pbVar4 + (*(int*)(param_5 + 0x2c) - (int)(intptr_t)pbVar12);
                            } while (pbVar4 < pbVar12);
                            uVar9 = *(uint32_t*)(param_5 + 0x2c) - (uint32_t)(uintptr_t)pbVar4;
                            if (uVar9 < uVar10) {
                                param_1v = uVar10 - uVar9;
                                do {
                                    *local_10 = *pbVar4;
                                    local_10 = local_10 + 1;
                                    pbVar4 = pbVar4 + 1;
                                    uVar9 = uVar9 - 1;
                                } while (uVar9 != 0);
                                pbVar12 = *(uint8_t**)(param_5 + 0x28);
                                do {
                                    *local_10 = *pbVar12;
                                    local_10 = local_10 + 1;
                                    pbVar12 = pbVar12 + 1;
                                    param_1v = param_1v - 1;
                                } while (param_1v != 0);
                            }
                            else {
                                *local_10 = *pbVar4;
                                local_10[1] = pbVar4[1];
                                local_10 = local_10 + 2;
                                pbVar4 = pbVar4 + 2;
                                param_1v = uVar10 - 2;
                                do {
                                    *local_10 = *pbVar4;
                                    local_10 = local_10 + 1;
                                    pbVar4 = pbVar4 + 1;
                                    param_1v = param_1v - 1;
                                } while (param_1v != 0);
                            }
                        }
                        else {
                            *local_10 = *pbVar4;
                            local_10[1] = pbVar4[1];
                            local_10 = local_10 + 2;
                            pbVar4 = pbVar4 + 2;
                            param_1v = uVar10 - 2;
                            do {
                                *local_10 = *pbVar4;
                                local_10 = local_10 + 1;
                                pbVar4 = pbVar4 + 1;
                                param_1v = param_1v - 1;
                            } while (param_1v != 0);
                        }
                        goto LAB_006b327a;
                    }
                    if ((bVar1 & 0x40) != 0) break;
                    pbVar12 = pbVar12 + ((DAT_00722488[(uint8_t)bVar1] & hold) +
                                         *(uint32_t*)(pbVar12 + 4)) * 8;
                    hold = hold >> (pbVar12[1] & 0x1f);
                    uVar8 = uVar8 - pbVar12[1];
                }
                piVar3[6] = (int)(uintptr_t)"invalid distance code";
                uVar7 = (uint32_t)piVar3[1] - local_8;
                if (uVar8 >> 3 < (uint32_t)piVar3[1] - local_8) {
                    uVar7 = uVar8 >> 3;
                }
LAB_006b32ea:
                uVar5 = 0xfffffffd;
                goto LAB_006b32ed;
            }
            if ((bVar1 & 0x40) == 0) {
                pbVar12 = pbVar12 + ((DAT_00722488[param_1v] & hold) +
                                     *(uint32_t*)(pbVar12 + 4)) * 8;
                bVar1 = *pbVar12;
                goto LAB_006b310a;
            }
            uVar6 = uVar8 >> 3;
            if ((bVar1 & 0x20) == 0) {
                uVar7 = (uint32_t)piVar3[1] - local_8;
                piVar3[6] = (int)(uintptr_t)"invalid literal/length code";
                if (uVar6 < uVar7) {
                    uVar7 = uVar6;
                }
                goto LAB_006b32ea;
            }
            uVar7 = (uint32_t)piVar3[1] - local_8;
            if (uVar6 < uVar7) {
                uVar7 = uVar6;
            }
            uVar5 = 1;
            goto LAB_006b32ed;
        }
        hold = hold >> (pbVar12[1] & 0x1f);
        uVar8 = uVar8 - pbVar12[1];
        local_14 = local_14 - 1;
        *local_10 = pbVar12[4];
        local_10 = local_10 + 1;
LAB_006b327a:
        if ((local_14 < (uint8_t*)0x102) || (local_8 < 10)) {
            uVar7 = (uint32_t)piVar3[1] - local_8;
            if (uVar8 >> 3 < (uint32_t)piVar3[1] - local_8) {
                uVar7 = uVar8 >> 3;
            }
            uVar5 = 0;
LAB_006b32ed:
            *(uint32_t*)(param_5 + 0x20) = hold;
            *(uint32_t*)(param_5 + 0x1c) = uVar8 + uVar7 * -8;
            piVar3[1] = (int)(uVar7 + local_8);
            {
                int iVar2 = *piVar3;
                *piVar3 = (int)((uintptr_t)local_c - uVar7);
                piVar3[2] = piVar3[2] + (((int)(uintptr_t)local_c - (int)uVar7) - iVar2);
            }
            *(uint8_t**)(param_5 + 0x34) = local_10;
            return uVar5;
        }
    }
}

// 0x6b3330 — observed shape
void FUN_006b3330(void* self)
{
    uint32_t* ecx = (uint32_t*)self;
    int* piVar1;
    int iVar2, iVar4, iVar5;
    uint32_t* puVar3;

    *ecx = (uint32_t)(uintptr_t)&PTR_FUN_006f5210;
    iVar2 = (int)ecx[1];
    if (iVar2 != 0) {
        iVar4 = *(int*)(uintptr_t)(iVar2 + -4);
        iVar5 = iVar2 + iVar4 * 4;
        if (-1 < iVar4 + -1) {
            do {
                puVar3 = *(uint32_t**)(uintptr_t)(iVar5 + -4);
                iVar5 = iVar5 + -4;
                if (puVar3 != nullptr) {
                    piVar1 = (int*)(puVar3 + 1);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) {
                        (*(void (**)(int))(*puVar3))(1);
                    }
                }
                iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
        }
        operator_delete__((void*)(uintptr_t)(iVar2 + -4));
    }
}

