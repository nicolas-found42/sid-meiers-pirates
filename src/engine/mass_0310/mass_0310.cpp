// UNVERIFIED: no compiler run for this batch. Clean-room reconstruction from
// Ghidra 12.2 pseudocode (analysis profile 59fe0f4e...). No PASS claim.
// Bundled libpng 1.1.4 read/write transforms: swap, packswap, gamma setup,
// bit-depth coercion, shifts, filler/expand/dither and the row-transform driver.
#include <cstdint>
#include <cstddef>
#include <cmath>
#include <windows.h>

// ---- referenced helpers (declared extern, addresses from the listings) ----
extern void FUN_006565dd(int png, const char* msg);    // png_error, does not return
extern void FUN_006565fe(int png, const char* msg);    // png_warning
extern void* FUN_006924f1(int png, uint32_t size);     // png_malloc
extern void FUN_00658adc(int png, void* dst, int len); // png_read_data (below)
extern void FUN_00658b08(int png, uint32_t io, uint32_t fn); // png_set_read_fn (below)
extern void FUN_0065851e(int png);                     // png_build_gamma_table (below)
extern void FUN_0065741d(int* row_info, uint8_t* row); // png_do_swap
extern void FUN_00657450(int* row_info, uint8_t* row); // png_do_packswap
extern void FUN_0065755e(int png, int* row_info);      // png_read_transform_info
extern void FUN_00657647(int* row_info, int row);      // png_do_unpack
extern void FUN_0065775a(int* row_info, uint8_t* row, uint8_t* shift); // png_do_shift
extern void FUN_006578d8(int* row_info, uint8_t* row); // png_do_chop
extern void FUN_00657922(uint32_t* row_info, uint8_t* row, uint32_t filler, uint32_t flags);
extern void FUN_006580b4(uint8_t* row_info, int row, int trans_value); // png_do_expand
extern void FUN_00657b57(int* row_info, uint8_t* row, int gamma_table, uint8_t* gamma_16,
                         uint8_t gamma_shift);         // png_do_gamma
extern void FUN_00657ea9(uint* row_info, uint8_t* row, int palette, uint32_t trans,
                         int num_trans);               // png_do_expand_palette
extern void FUN_0065840d(int* row_info, uint8_t* row, int palette, int lookup); // png_do_dither
extern void FUN_0065893b(int png);                     // png_do_read_transformations (below)

// CRT helpers still reached through the x87 stack in the gamma builder.
extern "C" void _CIpow(void);   // pow(): operands passed in st(1)/st(0)
extern "C" int ftol(void);      // x87 truncation to long

// 0x65741d — observed shape
// png_do_swap: 16-bit samples are byte-swapped in place.
void FUN_0065741d(int* param_1, uint8_t* param_2)
{
    uint8_t uVar1;
    int iVar2;

    if (*(char*)((int)param_1 + 9) == '\x10' &&
        (iVar2 = (uint32_t)*(uint8_t*)((int)param_1 + 10) * *param_1, iVar2 != 0)) {
        do {
            uVar1 = *param_2;
            *param_2 = param_2[1];
            param_2[1] = uVar1;
            param_2 = param_2 + 2;
            iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
    }
}

// 0x657450 — observed shape
// png_do_packswap: reverses the sample order inside each packed byte.
void FUN_00657450(int* param_1, uint8_t* param_2)
{
    uint8_t bVar1;
    uint8_t uVar2;
    int iVar3;

    bVar1 = *(uint8_t*)(param_1 + 2);       // row_info.color_type, offset 0x08
    if ((bVar1 & 2) != 0) {
        iVar3 = *param_1;                   // width
        if (*(char*)((int)param_1 + 9) == '\b') {      // bit_depth == 8
            if (bVar1 == 2) {
                if (iVar3 != 0) {
                    do {
                        uVar2 = *param_2;
                        *param_2 = param_2[2];
                        param_2[2] = uVar2;
                        param_2 = param_2 + 3;
                        iVar3 = iVar3 + -1;
                    } while (iVar3 != 0);
                }
            } else if (bVar1 == 6 && iVar3 != 0) {
                do {
                    uVar2 = *param_2;
                    *param_2 = param_2[2];
                    param_2[2] = uVar2;
                    param_2 = param_2 + 4;
                    iVar3 = iVar3 + -1;
                } while (iVar3 != 0);
            }
        } else if (*(char*)((int)param_1 + 9) == '\x10') {  // bit_depth == 16
            if (bVar1 == 2) {
                if (iVar3 != 0) {
                    param_2 = param_2 + 1;
                    do {
                        uVar2 = param_2[-1];
                        param_2[-1] = param_2[3];
                        param_2[3] = uVar2;
                        uVar2 = *param_2;
                        *param_2 = param_2[4];
                        param_2[4] = uVar2;
                        param_2 = param_2 + 6;
                        iVar3 = iVar3 + -1;
                    } while (iVar3 != 0);
                }
            } else if (bVar1 == 6 && iVar3 != 0) {
                param_2 = param_2 + 1;
                do {
                    uVar2 = param_2[-1];
                    param_2[-1] = param_2[3];
                    param_2[3] = uVar2;
                    uVar2 = *param_2;
                    *param_2 = param_2[4];
                    param_2[4] = uVar2;
                    param_2 = param_2 + 8;
                    iVar3 = iVar3 + -1;
                } while (iVar3 != 0);
            }
        }
    }
}

// 0x657513 — observed shape
// png_set_gamma: remembers the pair and flags PNG_GAMMA when they are not inverses.
void FUN_00657513(int param_1, double param_2, double param_3)
{
    if (0.05 < fabs(param_2 * param_3 - 1.0)) {
        *(uint8_t*)(param_1 + 0x61) = *(uint8_t*)(param_1 + 0x61) | 0x20;
    }
    *(float*)(param_1 + 0x130) = (float)param_3;
    *(float*)(param_1 + 0x134) = (float)param_2;
}

// 0x65755e — observed shape
// png_read_transform_info: rewrites the row descriptor for the enabled transforms.
void FUN_0065755e(int param_1, int* param_2)
{
    uint8_t bVar1;

    if ((*(uint8_t*)(param_1 + 0x61) & 0x10) == 0) goto LAB_006575ab;
    if (*(uint8_t*)((int)param_2 + 0x19) == 3) {
        *(char*)((int)param_2 + 0x19) = (*(int16_t*)(param_1 + 0x10a) != 0) * '\x04' + '\x02';
LAB_006575a3:
        *(uint8_t*)(param_2 + 6) = 8;
    } else {
        if (*(int16_t*)(param_1 + 0x10a) != 0) {
            *(uint8_t*)((int)param_2 + 0x19) = *(uint8_t*)((int)param_2 + 0x19) | 4;
        }
        if (*(uint8_t*)(param_2 + 6) < 8) goto LAB_006575a3;
    }
    *(uint16_t*)((int)param_2 + 0x16) = 0;
LAB_006575ab:
    if ((*(uint8_t*)(param_1 + 0x61) & 0x20) != 0) {
        param_2[10] = *(int*)(param_1 + 0x130);
    }
    if (((*(uint8_t*)(param_1 + 0x61) & 4) != 0) && ((char)param_2[6] == '\x10')) {
        *(uint8_t*)(param_2 + 6) = 8;
    }
    if (((*(uint8_t*)(param_1 + 0x60) & 0x40) != 0) &&
        ((((*(char*)((int)param_2 + 0x19) == '\x02') || (*(char*)((int)param_2 + 0x19) == '\x06')) &&
          (*(int*)(param_1 + 0x174) != 0)) && ((char)param_2[6] == '\b'))) {
        *(uint8_t*)((int)param_2 + 0x19) = 3;
    }
    if (((*(uint8_t*)(param_1 + 0x60) & 4) != 0) && (*(uint8_t*)(param_2 + 6) < 8)) {
        *(uint8_t*)(param_2 + 6) = 8;
    }
    bVar1 = *(uint8_t*)((int)param_2 + 0x19);
    if ((bVar1 == 3) || ((bVar1 & 2) == 0)) {
        *(uint8_t*)((int)param_2 + 0x1d) = 1;
    } else {
        *(uint8_t*)((int)param_2 + 0x1d) = 3;
    }
    if ((bVar1 & 4) != 0) {
        *(char*)((int)param_2 + 0x1d) = *(char*)((int)param_2 + 0x1d) + '\x01';
    }
    if (((*(uint8_t*)(param_1 + 0x61) & 0x80) != 0) && ((bVar1 == 2) || (bVar1 == 0))) {
        *(char*)((int)param_2 + 0x1d) = *(char*)((int)param_2 + 0x1d) + '\x01';
    }
    bVar1 = (char)param_2[6] * *(char*)((int)param_2 + 0x1d);
    *(uint8_t*)((int)param_2 + 0x1e) = bVar1;
    param_2[3] = (uint32_t)bVar1 * *param_2 + 7 >> 3;
}

// 0x657647 — observed shape
// png_do_unpack: expands 1/2/4-bit samples to 8-bit, end of row first.
void FUN_00657647(int* param_1, int param_2)
{
    uint8_t bVar1;
    int iVar2;
    int iVar3;
    uint8_t* pbVar4;
    uint8_t* pbVar5;

    bVar1 = *(uint8_t*)((int)param_1 + 9);
    if (bVar1 < 8) {
        iVar2 = *param_1;
        if (bVar1 == 1) {
            pbVar4 = (uint8_t*)((iVar2 - 1U >> 3) + param_2);
            pbVar5 = (uint8_t*)(iVar2 + -1 + param_2);
            iVar3 = 7 - (iVar2 - 1U & 7);
            if (iVar2 != 0) {
                param_2 = iVar2;
                do {
                    *pbVar5 = *pbVar4 >> ((uint8_t)iVar3 & 0x1f) & 1;
                    if (iVar3 == 7) {
                        iVar3 = 0;
                        pbVar4 = pbVar4 + -1;
                    } else {
                        iVar3 = iVar3 + 1;
                    }
                    pbVar5 = pbVar5 + -1;
                    param_2 = param_2 + -1;
                } while (param_2 != 0);
            }
        } else if (bVar1 == 2) {
            pbVar4 = (uint8_t*)((iVar2 - 1U >> 2) + param_2);
            pbVar5 = (uint8_t*)(iVar2 + -1 + param_2);
            iVar3 = (3 - (iVar2 - 1U & 3)) * 2;
            if (iVar2 != 0) {
                param_2 = iVar2;
                do {
                    *pbVar5 = *pbVar4 >> ((uint8_t)iVar3 & 0x1f) & 3;
                    if (iVar3 == 6) {
                        iVar3 = 0;
                        pbVar4 = pbVar4 + -1;
                    } else {
                        iVar3 = iVar3 + 2;
                    }
                    pbVar5 = pbVar5 + -1;
                    param_2 = param_2 + -1;
                } while (param_2 != 0);
            }
        } else if (bVar1 == 4) {
            pbVar4 = (uint8_t*)((iVar2 - 1U >> 1) + param_2);
            pbVar5 = (uint8_t*)(iVar2 + -1 + param_2);
            iVar3 = (1 - (iVar2 - 1U & 1)) * 4;
            if (iVar2 != 0) {
                param_2 = iVar2;
                do {
                    *pbVar5 = *pbVar4 >> ((uint8_t)iVar3 & 0x1f) & 0xf;
                    if (iVar3 == 4) {
                        iVar3 = 0;
                        pbVar4 = pbVar4 + -1;
                    } else {
                        iVar3 = 4;
                    }
                    pbVar5 = pbVar5 + -1;
                    param_2 = param_2 + -1;
                } while (param_2 != 0);
            }
        }
        *(uint8_t*)((int)param_1 + 9) = 8;
        *(uint8_t*)((int)param_1 + 0xb) = *(uint8_t*)((int)param_1 + 10) << 3;
        param_1[1] = (uint32_t)*(uint8_t*)((int)param_1 + 10) * iVar2;
    }
}

// 0x65775a — observed shape
// png_do_shift: right-shifts each sample by (bit_depth - shift[channel]).
// The provider reuses param_1 as scratch and returns it clobbered; the routine
// is a void row transform, so that return value is emitted as void.
void FUN_0065775a(int* param_1, uint8_t* param_2, uint8_t* param_3)
{
    uint8_t* pbVar9;
    char cVar2;
    bool bVar3;
    uint8_t bVar4;
    uint16_t uVar5;
    uint8_t bVar6;
    uint32_t uVar7;
    int iVar8;
    int iVar12;
    int local_18[4];

    pbVar9 = param_2;
    if (*(uint8_t*)(param_1 + 2) == 3) {
        return;
    }
    bVar3 = false;
    iVar12 = *param_1;
    if ((*(uint8_t*)(param_1 + 2) & 2) == 0) {
        local_18[0] = (uint32_t)*(uint8_t*)((int)param_1 + 9) - (uint32_t)param_3[3];
        uVar7 = 1;
    } else {
        uVar7 = (uint32_t)*(uint8_t*)((int)param_1 + 9);
        local_18[0] = (uint32_t)*(uint8_t*)((int)param_1 + 9) - (uint32_t)*param_3;
        local_18[1] = (uint32_t)*(uint8_t*)((int)param_1 + 9) - (uint32_t)param_3[1];
        local_18[2] = (uint32_t)*(uint8_t*)((int)param_1 + 9) - (uint32_t)param_3[2];
        uVar7 = 3;
    }
    iVar8 = local_18[0];
    if ((*(uint8_t*)(param_1 + 2) & 4) != 0) {
        local_18[uVar7] = (uint32_t)*(uint8_t*)((int)param_1 + 9) - (uint32_t)param_3[4];
        uVar7 = uVar7 + 1;
        iVar8 = local_18[0];
    }
    if (uVar7 == 0) {
        return;
    }
    for (int iVar10 = 0; iVar10 < (int)uVar7; iVar10 = iVar10 + 1) {
        if (local_18[iVar10] < 1) {
            local_18[iVar10] = 0;
            iVar8 = local_18[0];
        } else {
            bVar3 = true;
        }
    }
    if (!bVar3) {
        return;
    }
    cVar2 = *(char*)((int)param_1 + 9);
    if (cVar2 == '\x02') {
        for (iVar12 = param_1[1]; iVar12 != 0; iVar12 = iVar12 + -1) {
            *param_2 = *param_2 >> 1 & 0x55;
            param_2 = param_2 + 1;
        }
    } else if (cVar2 == '\x04') {
        bVar6 = (uint8_t)iVar8;
        uVar7 = 0xf0 >> (bVar6 & 0x1f) & 0xfffffff0;
        bVar4 = (uint8_t)uVar7 | (uint8_t)(0xf >> (bVar6 & 0x1f));
        for (iVar12 = param_1[1]; iVar12 != 0; iVar12 = iVar12 + -1) {
            *param_2 = *param_2 >> (bVar6 & 0x1f) & bVar4;
            param_2 = param_2 + 1;
        }
    } else if (cVar2 == '\b') {
        if (iVar12 * (int)uVar7 != 0) {
            uint32_t uVar11 = 0;
            do {
                *param_2 = *param_2 >> (*(uint8_t*)&local_18[uVar11 % uVar7] & 0x1f);
                param_2 = param_2 + 1;
                uVar11 = uVar11 + 1;
            } while (uVar11 < (uint32_t)(iVar12 * uVar7));
        }
    } else if (cVar2 == '\x10') {
        uint32_t uVar11 = 0;
        if (iVar12 * (int)uVar7 != 0) {
            do {
                uVar5 = (uint16_t)(((uint16_t)pbVar9[0] << 8) | pbVar9[1])
                        >> (*(uint8_t*)&local_18[uVar11 % uVar7] & 0x1f);
                pbVar9[0] = (uint8_t)(uVar5 >> 8);
                pbVar9[1] = (uint8_t)uVar5;
                pbVar9 = pbVar9 + 2;
                uVar11 = uVar11 + 1;
            } while (uVar11 < (uint32_t)(iVar12 * uVar7));
        }
    }
}

// 0x6578d8 — observed shape
// png_do_chop: keeps the high byte of every 16-bit sample, dropping to 8 bits.
void FUN_006578d8(int* param_1, uint8_t* param_2)
{
    uint8_t uVar1;
    int iVar2;
    uint8_t* puVar3;

    if (*(char*)((int)param_1 + 9) == '\x10') {
        iVar2 = (uint32_t)*(uint8_t*)((int)param_1 + 10) * *param_1;
        if (iVar2 != 0) {
            puVar3 = param_2;
            do {
                uVar1 = *param_2;
                param_2 = param_2 + 2;
                *puVar3 = uVar1;
                puVar3 = puVar3 + 1;
                iVar2 = iVar2 + -1;
            } while (iVar2 != 0);
        }
        *(uint8_t*)((int)param_1 + 9) = 8;
        *(uint8_t*)((int)param_1 + 0xb) = *(uint8_t*)((int)param_1 + 10) << 3;
        param_1[1] = (uint32_t)*(uint8_t*)((int)param_1 + 10) * *param_1;
    }
}

// 0x657922 — observed shape
// png_do_read_filler: inserts one filler channel (gray->GA, RGB->RGBA) 8 or 16 bit.
// param_4 bit 0x80 selects filler-after / filler-before placement.
void FUN_00657922(uint32_t* param_1, uint8_t* param_2, uint32_t param_3, uint32_t param_4)
{
    uint32_t uVar1;
    uint8_t* puVar2;
    uint8_t uVar3;
    uint8_t bVar4;
    uint32_t uVar5;
    uint8_t* puVar6;
    uint8_t* puVar7;

    uVar1 = *param_1;
    bVar4 = (uint8_t)(param_3 >> 8);
    uVar3 = (uint8_t)param_3;
    if ((char)param_1[2] == '\0') {
        if (*(char*)((int)param_1 + 9) == '\b') {
            puVar2 = (uint8_t*)((int)param_2 + uVar1);
            puVar6 = puVar2 + uVar1;
            if ((param_4 & 0x80) == 0) {
                if (uVar1 != 0) {
                    uint32_t n = uVar1;
                    do {
                        puVar2 = puVar2 + -1;
                        puVar6[-1] = *puVar2;
                        puVar6 = puVar6 + -2;
                        n = n - 1;
                        *puVar6 = uVar3;
                    } while (n != 0);
                }
            } else {
                if (1 < uVar1) {
                    uint32_t n = uVar1 - 1;
                    do {
                        puVar2 = puVar2 + -1;
                        puVar6[-1] = uVar3;
                        puVar6 = puVar6 + -2;
                        n = n - 1;
                        *puVar6 = *puVar2;
                    } while (n != 0);
                }
                puVar6[-1] = uVar3;
            }
            *(uint8_t*)((int)param_1 + 10) = 2;
            *(uint8_t*)((int)param_1 + 0xb) = 0x10;
            uVar1 = uVar1 * 2;
        } else {
            if (*(char*)((int)param_1 + 9) != '\x10') {
                return;
            }
            if ((param_4 & 0x80) == 0) {
                param_2 = (uint8_t*)(uVar1 + (int)param_2);
                puVar6 = param_2 + uVar1;
                if (uVar1 != 0) {
                    param_4 = uVar1;
                    do {
                        puVar2 = param_2 + -1;
                        param_2 = param_2 + -2;
                        puVar6[-1] = *puVar2;
                        puVar6[-2] = *param_2;
                        puVar6[-3] = bVar4;
                        puVar6 = puVar6 + -4;
                        param_4 = param_4 - 1;
                        *puVar6 = uVar3;
                    } while (param_4 != 0);
                }
            } else {
                puVar6 = (uint8_t*)((int)param_2 + uVar1);
                puVar2 = puVar6 + uVar1;
                if (1 < uVar1) {
                    param_4 = uVar1 - 1;
                    uVar5 = param_3 >> 8;
                    do {
                        puVar2[-1] = (char)uVar5;
                        puVar2[-2] = uVar3;
                        puVar2[-3] = puVar6[-1];
                        puVar6 = puVar6 + -2;
                        puVar2 = puVar2 + -4;
                        param_4 = param_4 - 1;
                        *puVar2 = *puVar6;
                        uVar5 = (uint32_t)bVar4;
                    } while (param_4 != 0);
                }
                puVar2[-1] = bVar4;
                puVar2[-2] = uVar3;
            }
            *(uint8_t*)((int)param_1 + 10) = 2;
            *(uint8_t*)((int)param_1 + 0xb) = 0x20;
            uVar1 = uVar1 << 2;
        }
    } else {
        if ((char)param_1[2] != '\x02') {
            return;
        }
        if (*(char*)((int)param_1 + 9) == '\b') {
            puVar6 = (uint8_t*)((int)param_2 + uVar1 * 3);
            puVar2 = puVar6 + uVar1;
            if ((param_4 & 0x80) == 0) {
                if (uVar1 != 0) {
                    uint32_t n = uVar1;
                    do {
                        puVar2[-1] = puVar6[-1];
                        puVar2[-2] = puVar6[-2];
                        puVar6 = puVar6 + -3;
                        puVar2[-3] = *puVar6;
                        puVar2 = puVar2 + -4;
                        n = n - 1;
                        *puVar2 = uVar3;
                    } while (n != 0);
                }
            } else {
                if (1 < uVar1) {
                    uint32_t n = uVar1 - 1;
                    do {
                        puVar2[-1] = uVar3;
                        puVar2[-2] = puVar6[-1];
                        puVar7 = puVar6 + -2;
                        puVar6 = puVar6 + -3;
                        puVar2[-3] = *puVar7;
                        puVar2 = puVar2 + -4;
                        n = n - 1;
                        *puVar2 = *puVar6;
                    } while (n != 0);
                }
                puVar2[-1] = uVar3;
            }
            *(uint8_t*)((int)param_1 + 0xb) = 0x20;
            uVar1 = uVar1 << 2;
        } else {
            if (*(char*)((int)param_1 + 9) != '\x10') {
                return;
            }
            if ((param_4 & 0x80) == 0) {
                puVar6 = (uint8_t*)((int)param_2 + uVar1 * 3);
                puVar2 = puVar6 + uVar1;
                if (uVar1 != 0) {
                    uint32_t n = uVar1;
                    do {
                        puVar2[-1] = puVar6[-1];
                        puVar2[-2] = puVar6[-2];
                        puVar2[-3] = puVar6[-3];
                        puVar2[-4] = puVar6[-4];
                        puVar2[-5] = puVar6[-5];
                        puVar6 = puVar6 + -6;
                        puVar2[-6] = *puVar6;
                        puVar2[-7] = bVar4;
                        puVar2 = puVar2 + -8;
                        n = n - 1;
                        *puVar2 = uVar3;
                    } while (n != 0);
                }
            } else {
                puVar6 = (uint8_t*)((int)param_2 + uVar1 * 3);
                puVar2 = puVar6 + uVar1;
                if (1 < uVar1) {
                    uint32_t n = uVar1 - 1;
                    do {
                        puVar2[-1] = bVar4;
                        puVar2[-2] = uVar3;
                        puVar2[-3] = puVar6[-1];
                        puVar2[-4] = puVar6[-2];
                        puVar2[-5] = puVar6[-3];
                        puVar2[-6] = puVar6[-4];
                        puVar7 = puVar6 + -5;
                        puVar6 = puVar6 + -6;
                        puVar2[-7] = *puVar7;
                        puVar2 = puVar2 + -8;
                        n = n - 1;
                        *puVar2 = *puVar6;
                    } while (n != 0);
                }
                puVar2[-1] = bVar4;
                puVar2[-2] = uVar3;
            }
            *(uint8_t*)((int)param_1 + 0xb) = 0x40;
            uVar1 = uVar1 << 3;
        }
        *(uint8_t*)((int)param_1 + 10) = 4;
    }
    param_1[1] = uVar1;
}

// 0x657b57 — observed shape
// png_do_gamma: expands 1/2/4-bit grey into bytes, then maps every sample
// through the 8-bit table (param_3) or the 16-bit table (param_4, indexed by
// high byte >> param_5). param_2 is advanced in place.
void FUN_00657b57(int* param_1, uint8_t* param_2, int param_3, uint8_t* param_4, uint8_t param_5)
{
    uint8_t bVar1;
    char cVar2;
    uint16_t uVar3;
    int iVar4;
    int iVar5;
    uint8_t* pbVar6;
    uint32_t uVar7;
    uint32_t uVar8;
    uint32_t uVar9;
    uint32_t uVar10;
    int iVar11;

    iVar5 = (int)param_4;
    iVar4 = param_3;
    bVar1 = *(uint8_t*)((int)param_1 + 9);
    iVar11 = *param_1;
    if (((bVar1 < 9) && (param_3 != 0)) || ((bVar1 == 0x10 && (param_4 != nullptr)))) {
        cVar2 = (char)param_1[2];
        if (cVar2 == '\0') {
            if ((bVar1 == 2) && (param_4 = param_2, iVar11 != 0)) {
                param_3 = (iVar11 - 1U >> 2) + 1;
                do {
                    uVar7 = (uint32_t)*param_4;
                    uVar9 = uVar7 & 0xc0;
                    uVar8 = uVar7 & 3;
                    uVar10 = uVar7 & 0xc;
                    uVar7 = uVar7 & 0x30;
                    param_3 = param_3 + -1;
                    *param_4 = (uint8_t)((uint8_t)((uint8_t)(
                            *(uint8_t*)(((uVar10 << 2 | uVar10) << 2 | (int)uVar10 >> 2 | uVar10) + iVar4) & 0xcf |
                            *(uint8_t*)((((uVar8 << 2 | uVar8) << 2 | uVar8) << 2 | uVar8) + iVar4) >> 2) >> 2 |
                            *(uint8_t*)(((int)((int)uVar7 >> 2 | uVar7) >> 2 | uVar7 << 2 | uVar7) + iVar4) & 0xc3) >> 2) |
                        (*(uint8_t*)(((int)((int)((int)uVar9 >> 2 | uVar9) >> 2 | uVar9) >> 2 | uVar9) + iVar4) & 0xc0);
                    param_4 = param_4 + 1;
                } while (param_3 != 0);
            }
            cVar2 = *(char*)((int)param_1 + 9);
            if (cVar2 == '\x04') {
                if (iVar11 != 0) {
                    iVar11 = (iVar11 - 1U >> 1) + 1;
                    do {
                        uVar8 = *param_2 & 0xf0;
                        uVar7 = *param_2 & 0xf;
                        *param_2 = *(uint8_t*)(((int)uVar8 >> 4 | uVar8) + iVar4) & 0xf0 |
                                   *(uint8_t*)((uVar7 << 4 | uVar7) + iVar4) >> 4;
                        param_2 = param_2 + 1;
                        iVar11 = iVar11 + -1;
                    } while (iVar11 != 0);
                }
            } else if (cVar2 == '\b') {
                if (iVar11 != 0) {
                    do {
                        *param_2 = *(uint8_t*)((uint32_t)*param_2 + iVar4);
                        param_2 = param_2 + 1;
                        iVar11 = iVar11 + -1;
                    } while (iVar11 != 0);
                }
            } else if (cVar2 == '\x10') {
                for (; iVar11 != 0; iVar11 = iVar11 + -1) {
                    uVar3 = *(uint16_t*)(*(int*)(iVar5 + (uint32_t)(param_2[1] >> (param_5 & 0x1f)) * 4) +
                                         (uint32_t)*param_2 * 2);
                    *param_2 = (uint8_t)((uint16_t)uVar3 >> 8);
                    param_2[1] = (uint8_t)uVar3;
                    param_2 = param_2 + 2;
                }
            }
        } else if (cVar2 == '\x02') {
            if (bVar1 == 8) {
                if (iVar11 != 0) {
                    do {
                        *param_2 = *(uint8_t*)((uint32_t)*param_2 + param_3);
                        param_2[1] = *(uint8_t*)((uint32_t)param_2[1] + param_3);
                        param_2[2] = *(uint8_t*)((uint32_t)param_2[2] + param_3);
                        param_2 = param_2 + 3;
                        iVar11 = iVar11 + -1;
                    } while (iVar11 != 0);
                }
            } else if (iVar11 != 0) {
                pbVar6 = param_2;
                int n = iVar11;
                do {
                    uVar3 = *(uint16_t*)(*(int*)((int)param_4 + (uint32_t)(pbVar6[1] >> (param_5 & 0x1f)) * 4) +
                                         (uint32_t)*pbVar6 * 2);
                    pbVar6[1] = (uint8_t)uVar3;
                    *pbVar6 = (uint8_t)((uint16_t)uVar3 >> 8);
                    uVar3 = *(uint16_t*)(*(int*)((int)param_4 + (uint32_t)(pbVar6[3] >> (param_5 & 0x1f)) * 4) +
                                         (uint32_t)pbVar6[2] * 2);
                    pbVar6[3] = (uint8_t)uVar3;
                    pbVar6[2] = (uint8_t)((uint16_t)uVar3 >> 8);
                    uVar3 = *(uint16_t*)(*(int*)((int)param_4 + (uint32_t)(pbVar6[5] >> (param_5 & 0x1f)) * 4) +
                                         (uint32_t)pbVar6[4] * 2);
                    pbVar6[4] = (uint8_t)((uint16_t)uVar3 >> 8);
                    pbVar6[5] = (uint8_t)uVar3;
                    pbVar6 = pbVar6 + 6;
                    n = n - 1;
                } while (n != 0);
            }
        } else if (cVar2 == '\x04') {
            if (bVar1 == 8) {
                if (iVar11 != 0) {
                    do {
                        *param_2 = *(uint8_t*)((uint32_t)*param_2 + param_3);
                        param_2 = param_2 + 2;
                        iVar11 = iVar11 + -1;
                    } while (iVar11 != 0);
                }
            } else {
                for (; iVar11 != 0; iVar11 = iVar11 + -1) {
                    uVar3 = *(uint16_t*)(*(int*)((int)param_4 + (uint32_t)(param_2[1] >> (param_5 & 0x1f)) * 4) +
                                         (uint32_t)*param_2 * 2);
                    *param_2 = (uint8_t)((uint16_t)uVar3 >> 8);
                    param_2[1] = (uint8_t)uVar3;
                    param_2 = param_2 + 4;
                }
            }
        } else if (cVar2 == '\x06') {
            if (bVar1 == 8) {
                if (iVar11 != 0) {
                    do {
                        *param_2 = *(uint8_t*)((uint32_t)*param_2 + param_3);
                        param_2[1] = *(uint8_t*)((uint32_t)param_2[1] + param_3);
                        param_2[2] = *(uint8_t*)((uint32_t)param_2[2] + param_3);
                        param_2 = param_2 + 4;
                        iVar11 = iVar11 + -1;
                    } while (iVar11 != 0);
                }
            } else if (iVar11 != 0) {
                pbVar6 = param_2;
                int n = iVar11;
                do {
                    uVar3 = *(uint16_t*)(*(int*)((int)param_4 + (uint32_t)(pbVar6[1] >> (param_5 & 0x1f)) * 4) +
                                         (uint32_t)*pbVar6 * 2);
                    pbVar6[1] = (uint8_t)uVar3;
                    *pbVar6 = (uint8_t)((uint16_t)uVar3 >> 8);
                    uVar3 = *(uint16_t*)(*(int*)((int)param_4 + (uint32_t)(pbVar6[3] >> (param_5 & 0x1f)) * 4) +
                                         (uint32_t)pbVar6[2] * 2);
                    pbVar6[3] = (uint8_t)uVar3;
                    pbVar6[2] = (uint8_t)((uint16_t)uVar3 >> 8);
                    uVar3 = *(uint16_t*)(*(int*)((int)param_4 + (uint32_t)(pbVar6[5] >> (param_5 & 0x1f)) * 4) +
                                         (uint32_t)pbVar6[4] * 2);
                    pbVar6[4] = (uint8_t)((uint16_t)uVar3 >> 8);
                    pbVar6[5] = (uint8_t)uVar3;
                    pbVar6 = pbVar6 + 8;
                    n = n - 1;
                } while (n != 0);
            }
        }
    }
}

// 0x657ea9 — observed shape
// png_do_expand_palette: unpacks sub-byte indices, then expands them through
// the 3-byte palette (param_3); with a trans table (param_4, param_5 entries)
// the result becomes RGBA with 0xff for indices past the table.
void FUN_00657ea9(uint* param_1, uint8_t* param_2, int param_3, uint32_t param_4, int param_5)
{
    uint8_t bVar1;
    uint32_t uVar2;
    uint* puVar3;
    int iVar4;
    uint8_t* puVar5;
    uint8_t* pbVar6;
    uint32_t uVar7;
    uint32_t local_8;

    iVar4 = (int)param_2;
    puVar3 = param_1;
    uVar2 = *param_1;
    if ((char)param_1[2] == '\x03') {
        bVar1 = *(uint8_t*)((int)param_1 + 9);
        if (bVar1 < 8) {
            local_8 = uVar2;
            if (bVar1 == 1) {
                uint32_t nShift = 7 - (uVar2 - 1 & 7);
                pbVar6 = (uint8_t*)((uVar2 - 1 >> 3) + (int)param_2);
                if (uVar2 != 0) {
                    param_2 = (uint8_t*)((uVar2 - 1) + (int)param_2);
                    do {
                        *param_2 = *pbVar6 >> (nShift & 0x1f) & 1;
                        if (nShift == 7) {
                            nShift = 0;
                            pbVar6 = pbVar6 + -1;
                        } else {
                            nShift = nShift + 1;
                        }
                        param_2 = param_2 + -1;
                        local_8 = local_8 - 1;
                    } while (local_8 != 0);
                }
            } else if (bVar1 == 2) {
                uint32_t nShift = (3 - (uVar2 - 1 & 3)) * 2;
                pbVar6 = (uint8_t*)((uVar2 - 1 >> 2) + (int)param_2);
                if (uVar2 != 0) {
                    param_2 = (uint8_t*)((uVar2 - 1) + (int)param_2);
                    do {
                        *param_2 = *pbVar6 >> (nShift & 0x1f) & 3;
                        if (nShift == 6) {
                            nShift = 0;
                            pbVar6 = pbVar6 + -1;
                        } else {
                            nShift = nShift + 2;
                        }
                        param_2 = param_2 + -1;
                        local_8 = local_8 - 1;
                    } while (local_8 != 0);
                }
            } else if (bVar1 == 4) {
                uint32_t nShift = (uVar2 & 1) << 2;
                pbVar6 = (uint8_t*)((uVar2 - 1 >> 1) + (int)param_2);
                if (uVar2 != 0) {
                    param_2 = (uint8_t*)((uVar2 - 1) + (int)param_2);
                    do {
                        *param_2 = *pbVar6 >> (nShift & 0x1f) & 0xf;
                        if (nShift == 4) {
                            nShift = 0;
                            pbVar6 = pbVar6 + -1;
                        } else {
                            nShift = 4;
                        }
                        param_2 = param_2 + -1;
                        local_8 = local_8 - 1;
                    } while (local_8 != 0);
                }
            }
            *(uint8_t*)((int)puVar3 + 9) = 8;
            *(uint8_t*)((int)puVar3 + 0xb) = 8;
            puVar3[1] = uVar2;
        }
        if (*(char*)((int)puVar3 + 9) == '\b') {
            pbVar6 = (uint8_t*)((uVar2 - 1) + iVar4);
            if (param_4 == 0) {
                uVar7 = uVar2 * 3;
                puVar5 = (uint8_t*)((uVar7 - 1) + iVar4);
                if (uVar2 != 0) {
                    param_4 = uVar2;
                    do {
                        *puVar5 = *(uint8_t*)((uint32_t)*pbVar6 * 3 + 2 + param_3);
                        puVar5[-1] = *(uint8_t*)((uint32_t)*pbVar6 * 3 + 1 + param_3);
                        puVar5[-2] = *(uint8_t*)(param_3 + (uint32_t)*pbVar6 * 3);
                        puVar5 = puVar5 + -3;
                        pbVar6 = pbVar6 + -1;
                        param_4 = param_4 - 1;
                    } while (param_4 != 0);
                }
                *(uint8_t*)((int)puVar3 + 0xb) = 0x18;
                *(uint8_t*)(puVar3 + 2) = 2;
                *(uint8_t*)((int)puVar3 + 10) = 3;
            } else {
                uVar7 = uVar2 * 4;
                puVar5 = (uint8_t*)((uVar7 - 1) + iVar4);
                if (uVar2 != 0) {
                    uint32_t n = uVar2;
                    do {
                        if ((int)(uint32_t)*pbVar6 < param_5) {
                            *puVar5 = *(uint8_t*)(*pbVar6 + param_4);
                        } else {
                            *puVar5 = 0xff;
                        }
                        puVar5[-1] = *(uint8_t*)((uint32_t)*pbVar6 * 3 + 2 + param_3);
                        puVar5[-2] = *(uint8_t*)((uint32_t)*pbVar6 * 3 + 1 + param_3);
                        puVar5[-3] = *(uint8_t*)(param_3 + (uint32_t)*pbVar6 * 3);
                        puVar5 = puVar5 + -4;
                        pbVar6 = pbVar6 + -1;
                        n = n - 1;
                    } while (n != 0);
                }
                *(uint8_t*)((int)puVar3 + 0xb) = 0x20;
                *(uint8_t*)(puVar3 + 2) = 6;
                *(uint8_t*)((int)puVar3 + 10) = 4;
            }
            *(uint8_t*)((int)puVar3 + 9) = 8;
            puVar3[1] = uVar7;
        }
    }
}

// 0x6580b4 — observed shape
// png_do_expand: unpacks 1/2/4-bit grey to bytes, then (with a tRNS value)
// appends an alpha channel using trans_values (param_3) as the transparent key;
// RGB rows expand the same way through the three 16-bit trans components.
void FUN_006580b4(uint8_t* param_1, int param_2, int param_3)
{
    int iVar1;
    int* piVar2;
    uint8_t bVar3;
    int iVar4;
    uint8_t* pbVar5;
    int iVar6;
    uint16_t uVar7;
    uint8_t* puVar8;
    uint8_t* puVar9;
    int local_c;

    iVar4 = param_3;
    iVar6 = param_2;
    piVar2 = (int*)param_1;
    iVar1 = *(int*)param_1;
    if ((char)*(int*)((int)param_1 + 8) == '\0') {
        uVar7 = 0;
        if (param_3 != 0) {
            uVar7 = *(uint16_t*)(param_3 + 8);
        }
        bVar3 = *(uint8_t*)((int)param_1 + 9);
        if (bVar3 < 8) {
            local_c = iVar1;
            if (bVar3 == 1) {
                uVar7 = uVar7 * 0xff;
                param_1 = (uint8_t*)(iVar1 + -1 + param_2);
                pbVar5 = (uint8_t*)((iVar1 - 1U >> 3) + param_2);
                if (iVar1 != 0) {
                    param_2 = 7 - (iVar1 - 1U & 7);
                    do {
                        *param_1 = -((*pbVar5 >> ((uint8_t)param_2 & 0x1f) & 1) != 0);
                        if (param_2 == 7) {
                            param_2 = 0;
                            pbVar5 = pbVar5 + -1;
                        } else {
                            param_2 = param_2 + 1;
                        }
                        param_1 = param_1 + -1;
                        local_c = local_c + -1;
                    } while (local_c != 0);
                }
            } else if (bVar3 == 2) {
                uVar7 = uVar7 * 0x55;
                param_1 = (uint8_t*)(iVar1 + -1 + param_2);
                pbVar5 = (uint8_t*)((iVar1 - 1U >> 2) + param_2);
                if (iVar1 != 0) {
                    param_2 = (3 - (iVar1 - 1U & 3)) * 2;
                    do {
                        bVar3 = *pbVar5 >> ((uint8_t)param_2 & 0x1f) & 3;
                        *param_1 = ((bVar3 << 2 | bVar3) << 2 | bVar3) << 2 | bVar3;
                        if (param_2 == 6) {
                            param_2 = 0;
                            pbVar5 = pbVar5 + -1;
                        } else {
                            param_2 = param_2 + 2;
                        }
                        param_1 = param_1 + -1;
                        local_c = local_c + -1;
                    } while (local_c != 0);
                }
            } else if (bVar3 == 4) {
                uVar7 = uVar7 * 0x11;
                param_1 = (uint8_t*)(iVar1 + -1 + param_2);
                pbVar5 = (uint8_t*)((iVar1 - 1U >> 1) + param_2);
                if (iVar1 != 0) {
                    param_2 = (iVar1 - 1U & 1) * -4 + 4;
                    do {
                        bVar3 = *pbVar5 >> ((uint8_t)param_2 & 0x1f);
                        *param_1 = bVar3 << 4 | bVar3 & 0xf;
                        iVar4 = 4;
                        if (param_2 == 4) {
                            iVar4 = 0;
                            pbVar5 = pbVar5 + -1;
                        }
                        param_1 = param_1 + -1;
                        local_c = local_c + -1;
                        param_2 = iVar4;
                    } while (local_c != 0);
                }
            }
            *(uint8_t*)((int)piVar2 + 9) = 8;
            *(uint8_t*)((int)piVar2 + 0xb) = 8;
            piVar2[1] = iVar1;
        }
        if (param_3 == 0) {
            return;
        }
        if (*(char*)((int)piVar2 + 9) == '\b') {
            pbVar5 = (uint8_t*)(iVar1 + -1 + iVar6);
            puVar8 = (uint8_t*)(iVar6 + -1 + iVar1 * 2);
            if (iVar1 != 0) {
                iVar6 = iVar1;
                do {
                    if (*pbVar5 == uVar7) {
                        *puVar8 = 0;
                    } else {
                        *puVar8 = 0xff;
                    }
                    puVar8[-1] = *pbVar5;
                    puVar8 = puVar8 + -2;
                    pbVar5 = pbVar5 + -1;
                    iVar6 = iVar6 + -1;
                } while (iVar6 != 0);
            }
        } else if (*(char*)((int)piVar2 + 9) == '\x10') {
            puVar8 = (uint8_t*)(piVar2[1] + -1 + iVar6);
            puVar9 = (uint8_t*)(iVar6 + -1 + piVar2[1] * 2);
            if (iVar1 != 0) {
                param_3 = iVar1;
                do {
                    if ((uint16_t)(((uint16_t)puVar8[-1] << 8) | *puVar8) == uVar7) {
                        *puVar9 = 0;
                        puVar9[-1] = 0;
                    } else {
                        *puVar9 = 0xff;
                        puVar9[-1] = 0xff;
                    }
                    puVar9[-2] = *puVar8;
                    puVar9[-3] = puVar8[-1];
                    puVar9 = puVar9 + -4;
                    puVar8 = puVar8 + -2;
                    param_3 = param_3 + -1;
                } while (param_3 != 0);
            }
        }
        *(uint8_t*)(piVar2 + 2) = 4;
        *(uint8_t*)((int)piVar2 + 10) = 2;
        bVar3 = *(char*)((int)piVar2 + 9) << 1;
    } else {
        if ((char)*(int*)((int)param_1 + 8) != '\x02') {
            return;
        }
        if (param_3 == 0) {
            return;
        }
        if (*(char*)((int)param_1 + 9) == '\b') {
            pbVar5 = (uint8_t*)(*(int*)((int)param_1 + 4) + -1 + param_2);
            puVar8 = (uint8_t*)(param_2 + -1 + iVar1 * 4);
            if (iVar1 != 0) {
                param_3 = iVar1;
                do {
                    if (((uint16_t)pbVar5[-2] == *(uint16_t*)(iVar4 + 2)) &&
                        ((uint16_t)pbVar5[-1] == *(uint16_t*)(iVar4 + 4)) &&
                        ((uint16_t)*pbVar5 == *(uint16_t*)(iVar4 + 6))) {
                        *puVar8 = 0;
                    } else {
                        *puVar8 = 0xff;
                    }
                    puVar8[-1] = *pbVar5;
                    puVar8[-2] = pbVar5[-1];
                    puVar8[-3] = pbVar5[-2];
                    puVar8 = puVar8 + -4;
                    pbVar5 = pbVar5 + -3;
                    param_3 = param_3 + -1;
                } while (param_3 != 0);
            }
        } else if (*(char*)((int)param_1 + 9) == '\x10') {
            puVar8 = (uint8_t*)(*(int*)((int)param_1 + 4) + -1 + param_2);
            puVar9 = (uint8_t*)(param_2 + -1 + iVar1 * 8);
            if (iVar1 != 0) {
                param_2 = iVar1;
                do {
                    if (((uint16_t)(((uint16_t)puVar8[-5] << 8) | puVar8[-4]) == *(int16_t*)(param_3 + 2)) &&
                        ((uint16_t)(((uint16_t)puVar8[-3] << 8) | puVar8[-2]) == *(int16_t*)(param_3 + 4)) &&
                        ((uint16_t)(((uint16_t)puVar8[-1] << 8) | *puVar8) == *(int16_t*)(param_3 + 6))) {
                        *puVar9 = 0;
                        puVar9[-1] = 0;
                    } else {
                        *puVar9 = 0xff;
                        puVar9[-1] = 0xff;
                    }
                    puVar9[-2] = *puVar8;
                    puVar9[-3] = puVar8[-1];
                    puVar9[-4] = puVar8[-2];
                    puVar9[-5] = puVar8[-3];
                    puVar9[-6] = puVar8[-4];
                    puVar9[-7] = puVar8[-5];
                    puVar9 = puVar9 + -8;
                    puVar8 = puVar8 + -6;
                    param_2 = param_2 + -1;
                } while (param_2 != 0);
            }
        }
        *(uint8_t*)((int)param_1 + 8) = 6;
        *(uint8_t*)((int)param_1 + 10) = 4;
        bVar3 = *(char*)((int)param_1 + 9) << 2;
    }
    *(uint8_t*)((int)piVar2 + 0xb) = bVar3;
    piVar2[1] = (uint32_t)bVar3 * iVar1 >> 3;
}

// 0x65840d — observed shape
// png_do_dither: 8-bit RGB/RGBA rows collapse to palette indices through the
// 32768-entry lookup (param_3); index rows (param_4 != 0) are remapped through
// the palette lookup table; the row descriptor becomes 8-bit palette.
void FUN_0065840d(int* param_1, uint8_t* param_2, int param_3, int param_4)
{
    char cVar1;
    uint8_t bVar2;
    int* piVar3;
    int iVar4;
    uint8_t* pbVar5;
    uint8_t* pbVar6;
    uint8_t* pbVar7;

    piVar3 = param_1;
    cVar1 = (char)param_1[2];
    iVar4 = *param_1;
    if (((cVar1 == '\x02') && (param_3 != 0)) && (*(char*)((int)param_1 + 9) == '\b')) {
        if (iVar4 != 0) {
            pbVar7 = param_2;
            int n = iVar4;
            do {
                bVar2 = *pbVar7;
                pbVar5 = pbVar7 + 1;
                pbVar6 = pbVar7 + 2;
                pbVar7 = pbVar7 + 3;
                n = n - 1;
                *param_2 = *(uint8_t*)((((bVar2 & 0xf8) << 5 | *pbVar5 & 0xf8) << 2 |
                                       (int)(uint32_t)*pbVar6 >> 3) + param_3);
                param_2 = param_2 + 1;
            } while (n != 0);
        }
    } else {
        if (((cVar1 != '\x06') || (param_3 == 0)) || (*(char*)((int)param_1 + 9) != '\b')) {
            if (cVar1 != '\x03') {
                return;
            }
            if (param_4 == 0) {
                return;
            }
            if (*(char*)((int)param_1 + 9) != '\b') {
                return;
            }
            for (; iVar4 != 0; iVar4 = iVar4 + -1) {
                *param_2 = *(uint8_t*)((uint32_t)*param_2 + param_4);
                param_2 = param_2 + 1;
            }
            return;
        }
        if (iVar4 != 0) {
            pbVar7 = param_2;
            int n = iVar4;
            do {
                bVar2 = *pbVar7;
                pbVar5 = pbVar7 + 1;
                pbVar6 = pbVar7 + 2;
                pbVar7 = pbVar7 + 4;
                n = n - 1;
                *param_2 = *(uint8_t*)((((bVar2 & 0xf8) << 5 | *pbVar5 & 0xf8) << 2 |
                                       (int)(uint32_t)*pbVar6 >> 3) + param_3);
                param_2 = param_2 + 1;
            } while (n != 0);
        }
    }
    *(uint8_t*)((int)piVar3 + 0xb) = *(uint8_t*)((int)piVar3 + 9);
    *(uint8_t*)(piVar3 + 2) = 3;
    *(uint8_t*)((int)piVar3 + 10) = 1;
    piVar3[1] = (uint32_t)*(uint8_t*)((int)piVar3 + 9) * iVar4 + 7 >> 3;
}

// 0x65851e — observed shape
// png_build_gamma_table: 8-bit builds a 256-byte table; 16-bit builds
// (1 << (8 - shift)) rows of 256 uint16 entries. pow() is still invoked through
// the x87 stack (base/exponent left by the inlined prologue), hence the bare
// _CIpow()/ftol() pair; row 0x144 is gamma_16_table, 0x12c is gamma_shift.
void FUN_0065851e(int param_1)
{
    uint32_t uVar7;
    uint32_t uVar8;
    int iVar10;
    int iVar12;
    uint32_t uVar13;
    uint16_t local_10;
    uint32_t local_8;
    uint8_t bVar2;
    uint8_t bVar9;

    if (*(float*)(param_1 + 0x130) != 0.0) {
        if (*(uint8_t*)(param_1 + 0x117) < 9) {
            *(void**)(param_1 + 0x138) = FUN_006924f1(param_1, 0x100);
            for (iVar10 = 0; iVar10 < 0x100; iVar10 = iVar10 + 1) {
                _CIpow();
                uint8_t uVar4 = (uint8_t)ftol();
                *(uint8_t*)(iVar10 + *(int*)(param_1 + 0x138)) = uVar4;
            }
        } else {
            if ((*(uint8_t*)(param_1 + 0x116) & 2) == 0) {
                local_8 = (uint32_t)*(uint8_t*)(param_1 + 0x153);
            } else {
                local_8 = (uint32_t)*(uint8_t*)(param_1 + 0x150);
                if ((uint32_t)*(uint8_t*)(param_1 + 0x150) < (uint32_t)*(uint8_t*)(param_1 + 0x151)) {
                    local_8 = (uint32_t)*(uint8_t*)(param_1 + 0x151);
                }
                if (local_8 < *(uint8_t*)(param_1 + 0x152)) {
                    local_8 = (uint32_t)*(uint8_t*)(param_1 + 0x152);
                }
            }
            if (local_8 == 0) {
                local_8 = 0;
            } else {
                local_8 = 0x10 - local_8;
            }
            if (((*(uint8_t*)(param_1 + 0x61) & 4) != 0) && ((int)local_8 < 5)) {
                local_8 = 5;
            }
            if (8 < (int)local_8) {
                local_8 = 8;
            }
            if ((int)local_8 < 0) {
                local_8 = 0;
            }
            bVar2 = (uint8_t)local_8;
            bVar9 = 8 - bVar2;
            iVar10 = 1 << (bVar9 & 0x1f);
            *(uint32_t*)(param_1 + 300) = local_8 & 0xff;
            *(void**)(param_1 + 0x144) = FUN_006924f1(param_1, iVar10 << 2);
            if ((*(uint16_t*)(param_1 + 0x60) & 0x480) == 0) {
                for (int i = 0; i < iVar10; i = i + 1) {
                    *(void**)(*(int*)(param_1 + 0x144) + i * 4) = FUN_006924f1(param_1, 0x200);
                    for (iVar12 = 0; iVar12 < 0x200; iVar12 = iVar12 + 2) {
                        _CIpow();
                        uint16_t uVar5 = (uint16_t)ftol();
                        *(uint16_t*)(iVar12 + *(int*)(*(int*)(param_1 + 0x144) + i * 4)) = uVar5;
                    }
                }
            } else {
                for (int i = 0; i < iVar10; i = i + 1) {
                    *(void**)(*(int*)(param_1 + 0x144) + i * 4) = FUN_006924f1(param_1, 0x200);
                }
                uVar13 = 0;
                for (int i = 0; i < 0x100; i = i + 1) {
                    _CIpow();
                    uVar7 = (uint32_t)ftol();
                    if (uVar13 <= uVar7) {
                        local_10 = (uint16_t)((i & 0xff) << 8) | (uint16_t)i;
                        do {
                            uint32_t uVar11 = uVar13 >> (bVar9 & 0x1f);
                            uVar8 = 0xff >> (bVar2 & 0x1f) & uVar13;
                            uVar13 = uVar13 + 1;
                            *(uint16_t*)(*(int*)(*(int*)(param_1 + 0x144) + uVar8 * 4) + uVar11 * 2) = local_10;
                        } while (uVar13 <= uVar7);
                    }
                }
                if (uVar13 < (uint32_t)(iVar10 << 8)) {
                    do {
                        *(uint16_t*)(*(int*)(*(int*)(param_1 + 0x144) +
                                             (0xff >> (bVar2 & 0x1f) & uVar13) * 4) +
                                     (uVar13 >> (bVar9 & 0x1f)) * 2) = 0xffff;
                        uVar13 = uVar13 + 1;
                    } while (uVar13 < (uint32_t)(iVar10 << 8));
                }
            }
        }
    }
}

// 0x658825 — observed shape
// png_do_write_transformations: builds the gamma tables when WRITE_GAMMA is set
// and applies them to an 8-bit palette; WRITE_SHIFT then right-shifts the palette
// entries by 8 - sig_bit (0x150/0x151/0x152).
void FUN_00658825(int param_1)
{
    char cVar1;
    int iVar2;
    uint8_t* pbVar3;
    int iVar4;
    uint32_t uVar5;
    int iVar6;
    int local_8;

    iVar2 = param_1;
    cVar1 = *(char*)(param_1 + 0x116);
    if ((*(uint32_t*)(param_1 + 0x60) & 0x602000) != 0) {
        FUN_0065851e(param_1);
        if (cVar1 == '\x03') {
            uVar5 = (uint32_t)*(uint16_t*)(param_1 + 0x108);
            if (uVar5 != 0) {
                pbVar3 = (uint8_t*)(*(int*)(param_1 + 0x104) + 2);
                do {
                    pbVar3[-2] = *(uint8_t*)((uint32_t)pbVar3[-2] + *(int*)(param_1 + 0x138));
                    pbVar3[-1] = *(uint8_t*)((uint32_t)pbVar3[-1] + *(int*)(param_1 + 0x138));
                    *pbVar3 = *(uint8_t*)((uint32_t)*pbVar3 + *(int*)(param_1 + 0x138));
                    pbVar3 = pbVar3 + 3;
                    uVar5 = uVar5 - 1;
                } while (uVar5 != 0);
            }
        }
    }
    if (((*(uint8_t*)(param_1 + 0x60) & 8) != 0) && (cVar1 == '\x03')) {
        pbVar3 = (uint8_t*)(param_1 + 0x152);
        iVar6 = 8 - (uint32_t)*(uint8_t*)(param_1 + 0x150);
        param_1 = 8 - (uint32_t)*(uint8_t*)(param_1 + 0x151);
        local_8 = 8 - (uint32_t)*pbVar3;
        if ((iVar6 < 0) || (8 < iVar6)) {
            iVar6 = 0;
        }
        if ((param_1 < 0) || (8 < param_1)) {
            param_1 = 0;
        }
        if ((local_8 < 0) || (8 < local_8)) {
            local_8 = 0;
        }
        if (*(uint16_t*)(iVar2 + 0x108) != 0) {
            iVar4 = 0;
            uVar5 = (uint32_t)*(uint16_t*)(iVar2 + 0x108);
            do {
                pbVar3 = (uint8_t*)(iVar4 + *(int*)(iVar2 + 0x104));
                *pbVar3 = *pbVar3 >> ((uint8_t)iVar6 & 0x1f);
                pbVar3 = (uint8_t*)(iVar4 + 1 + *(int*)(iVar2 + 0x104));
                *pbVar3 = *pbVar3 >> ((uint8_t)param_1 & 0x1f);
                pbVar3 = (uint8_t*)(iVar4 + 2 + *(int*)(iVar2 + 0x104));
                *pbVar3 = *pbVar3 >> ((uint8_t)local_8 & 0x1f);
                iVar4 = iVar4 + 3;
                uVar5 = uVar5 - 1;
            } while (uVar5 != 0);
        }
    }
}

// 0x65893b — observed shape
// png_do_read_transformations: dispatch order is expand -> gamma -> 16-to-8 ->
// dither -> shift -> unpack -> packswap -> read filler -> swap.
void FUN_0065893b(int param_1)
{
    int iVar1;

    if (*(int*)(param_1 + 0xdc) == 0) {
        FUN_006565dd(param_1, "NULL row buffer");
    }
    if ((*(uint8_t*)(param_1 + 0x61) & 0x10) != 0) {
        if (*(char*)(param_1 + 0xf8) == '\x03') {
            FUN_00657ea9((uint*)(param_1 + 0xf0), (uint8_t*)(*(int*)(param_1 + 0xdc) + 1),
                         *(int*)(param_1 + 0x104), *(uint32_t*)(param_1 + 0x15c),
                         *(uint16_t*)(param_1 + 0x10a));
        } else {
            if (*(int16_t*)(param_1 + 0x10a) == 0) {
                iVar1 = 0;
            } else {
                iVar1 = param_1 + 0x160;
            }
            FUN_006580b4((uint8_t*)(param_1 + 0xf0), *(int*)(param_1 + 0xdc) + 1, iVar1);
        }
    }
    if (((*(uint8_t*)(param_1 + 0x61) & 0x20) != 0) && (*(char*)(param_1 + 0x116) != '\x03')) {
        FUN_00657b57((int*)(param_1 + 0xf0), (uint8_t*)(*(int*)(param_1 + 0xdc) + 1),
                     *(int*)(param_1 + 0x138), *(uint8_t**)(param_1 + 0x144),
                     *(uint8_t*)(param_1 + 300));
    }
    if ((*(uint8_t*)(param_1 + 0x61) & 4) != 0) {
        FUN_006578d8((int*)(param_1 + 0xf0), (uint8_t*)(*(int*)(param_1 + 0xdc) + 1));
    }
    if ((*(uint8_t*)(param_1 + 0x60) & 0x40) != 0) {
        FUN_0065840d((int*)(param_1 + 0xf0), (uint8_t*)(*(int*)(param_1 + 0xdc) + 1),
                     *(int*)(param_1 + 0x174), *(int*)(param_1 + 0x178));
        if (*(int*)(param_1 + 0xf4) == 0) {
            FUN_006565dd(param_1, "png_do_dither returned rowbytes=0");
        }
    }
    if ((*(uint8_t*)(param_1 + 0x60) & 8) != 0) {
        FUN_0065775a((int*)(param_1 + 0xf0), (uint8_t*)(*(int*)(param_1 + 0xdc) + 1),
                     (uint8_t*)(param_1 + 0x155));
    }
    if ((*(uint8_t*)(param_1 + 0x60) & 4) != 0) {
        FUN_00657647((int*)(param_1 + 0xf0), *(int*)(param_1 + 0xdc) + 1);
    }
    if ((*(uint8_t*)(param_1 + 0x60) & 1) != 0) {
        FUN_00657450((int*)(param_1 + 0xf0), (uint8_t*)(*(int*)(param_1 + 0xdc) + 1));
    }
    if ((*(uint8_t*)(param_1 + 0x61) & 0x80) != 0) {
        FUN_00657922((uint*)(param_1 + 0xf0), (uint8_t*)(*(int*)(param_1 + 0xdc) + 1),
                     *(uint16_t*)(param_1 + 0x11e), *(uint32_t*)(param_1 + 0x5c));
    }
    if ((*(uint8_t*)(param_1 + 0x60) & 0x10) != 0) {
        FUN_0065741d((int*)(param_1 + 0xf0), (uint8_t*)(*(int*)(param_1 + 0xdc) + 1));
    }
}

// 0x658adc — observed shape
// png_read_data: rejects a missing callback, then tail-calls read_data_fn(0x50).
void FUN_00658adc(int param_1, void* param_2, int param_3)
{
    if (*(void**)(param_1 + 0x50) == nullptr) {
        FUN_006565dd(param_1, "Call to NULL read function");
    }
    reinterpret_cast<void (*)(int, void*, int)>(*(void**)(param_1 + 0x50))(param_1, param_2, param_3);
}

// 0x658b08 — observed shape
// png_set_read_fn: io_ptr -> 0x54, read_data_fn -> 0x50; a pre-existing
// write_data_fn (0x4c) is cleared with a two-part warning.
void FUN_00658b08(int param_1, uint32_t param_2, uint32_t param_3)
{
    *(uint32_t*)(param_1 + 0x54) = param_2;
    *(uint32_t*)(param_1 + 0x50) = param_3;
    if (*(int*)(param_1 + 0x4c) != 0) {
        *(uint32_t*)(param_1 + 0x4c) = 0;
        FUN_006565fe(param_1, "It's an error to set both read_data_fn and write_data_fn in the ");
        FUN_006565fe(param_1, "same structure.  Resetting write_data_fn to NULL.");
    }
    *(uint32_t*)(param_1 + 0x120) = 0;
}

// 0x658b49 — observed shape
// Provider registers: in_ECX = packed 16-bit colour (r 5 bits @11, g 6 bits @5,
// b 5 bits @0), in_EAX = float4 destination. Writes normalized RGBA.
void FUN_00658b49(float* out, uint32_t packed)
{
    out[0] = (float)(packed >> 0xb & 0x1f) * 0.032258064;
    out[1] = (float)(packed >> 5 & 0x3f) * 0.015873017;
    out[2] = (float)(packed & 0x1f) * 0.032258064;
    out[3] = 1.0;
}

// 0x658b97 — observed shape
// Provider receiver in_ECX = 16 consecutive float4 colours. Un-premultiplies:
// alpha 0 zeroes RGB, alpha < 1 divides RGB by alpha (clamped to 1); alpha kept.
int FUN_00658b97(float* self)
{
    float* in_ECX = self;
    float fVar1;
    float fVar2;
    int iVar3;

    iVar3 = 0x10;
    do {
        if (in_ECX[3] == 0.0) {
            in_ECX[0] = 0.0;
            in_ECX[1] = 0.0;
            fVar1 = 0.0;
            in_ECX[2] = fVar1;
        } else if (in_ECX[3] < 1.0) {
            fVar1 = 1.0 / in_ECX[3];
            if (in_ECX[3] <= in_ECX[0]) {
                fVar2 = 1.0;
            } else {
                fVar2 = fVar1 * in_ECX[0];
            }
            in_ECX[0] = fVar2;
            if (in_ECX[3] <= in_ECX[1]) {
                fVar2 = 1.0;
            } else {
                fVar2 = fVar1 * in_ECX[1];
            }
            in_ECX[1] = fVar2;
            if (in_ECX[3] <= in_ECX[2]) {
                fVar1 = 1.0;
            } else {
                fVar1 = fVar1 * in_ECX[2];
            }
            in_ECX[2] = fVar1;
        }
        in_ECX = in_ECX + 4;
        iVar3 = iVar3 + -1;
        if (iVar3 == 0) {
            return 0;
        }
    } while (true);
}

// 0x658c1b — observed shape
// Provider receivers: in_ECX = float4 destination, in_EAX = float4 source, both
// 16 entries. Premultiplies source RGB by its alpha into the destination.
int FUN_00658c1b(float* dst, const float* src)
{
    int iVar1;

    iVar1 = 0x10;
    do {
        dst[0] = src[3] * src[0];
        iVar1 = iVar1 + -1;
        dst[1] = src[1] * src[3];
        dst[2] = src[2] * src[3];
        dst[3] = src[3];
        src = src + 4;
        dst = dst + 4;
    } while (iVar1 != 0);
    return 0;
}
