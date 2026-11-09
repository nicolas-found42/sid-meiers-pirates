// UNVERIFIED decompiler-derived reconstruction — batch mass_0266.
// Target: Sid Meier's Pirates! (2004), PE32 i386.
// Sources: analysis/pseudocode/functions/0x604918.c .. 0x606347.c (Ghidra 12.2).
// No compiler/byte-match claim; shapes follow the supplied listings.
//
// Field layout observed across this batch (byte offsets from the register
// receiver `self`, reported by the provider as in_ECX):
//   +0x10 pre-transform flag, +0x20 destination base, +0x34 dither table,
//   +0x38 palette/vertex array, +0x54 pre-transform flag,
//   +0x5c error-diffusion buffer, +0x60 row stride,
//   +0x64 (100) column stride, +0x68 pixel count,
//   +0x7c saved x87 control word.
//
// Receiver convention: the provider reports the destination object in
// in_ECX; each definition exposes it as `void* self` and never uses `this`.
#include <cstdint>
#include <cstddef>
#include <cmath>

// ---------------------------------------------------------------------------
// Helpers and globals observed in the supplied corpus listings.
// ---------------------------------------------------------------------------
extern void* FUN_00600136(void* param_3);
extern void* FUN_0060164a(void* param_3);
extern void FUN_00601966(void* param_3);
extern void FUN_006011da(uint32_t param_1, int param_2, int param_3);

extern char PTR_FUN_006dde4c[];
extern char PTR_FUN_006dde5c[];
extern char PTR_FUN_006dde6c[];
extern char PTR_FUN_006dde7c[];
extern char PTR_FUN_006dde8c[];
extern char PTR_FUN_006dde9c[];
extern char PTR_FUN_006ddeac[];
extern char PTR_FUN_006ddebc[];
extern char PTR_FUN_006ddecc[];
extern char PTR_FUN_006ddedc[];

// The decompiler's ROUND rounds to the nearest integer (x87 round-to-nearest).
inline int LocalRound(float v) {
    long r = std::lround(v);
    return (int)r;
}

// ---------------------------------------------------------------------------
// Translations
// ---------------------------------------------------------------------------

// 0x604918 — observed shape
// Uploads one row of 32-bit RGB10A2 texels. Prologue re-bases the source row
// when +0x54 / +0x10 are set. The dither table at +0x34 is indexed by
// (x&3, y&3, column&3). Residual channel error is scaled by 1/1023
// (0.0009775171) and diffused into +0x5c when that buffer exists.
void FUN_00604918(void* self, uint32_t param_1, float* param_2, int param_3)
{
    if (*(int*)((char*)self + 0x54) != 0) {
        param_3 = (int)(intptr_t)FUN_00600136((void*)(intptr_t)param_3);
    }
    if (*(int*)((char*)self + 0x10) != 0) {
        param_3 = (int)(intptr_t)FUN_0060164a((void*)(intptr_t)param_3);
    }
    float local_58 = 0.0f;
    float local_54 = 0.0f;
    float local_50 = 0.0f;
    float local_4c = 0.0f;
    uint32_t* local_8 = (uint32_t*)(*(int*)((char*)self + 0x60) * param_1 +
                                    (*(int*)((char*)self + 0x68) + -1) * (param_1 & 1) * 4 +
                                    *(int*)((char*)self + 100) * (int)param_2 +
                                    *(int*)((char*)self + 0x20));
    uint32_t uVar8 = param_1 & 3;
    uint32_t uVar12 = (uint32_t)param_2 & 3;
    int iVar3 = *(int*)((char*)self + 0x34);
    int iVar17;
    int iVar14;
    if ((param_1 & 1) == 0) {
        iVar17 = 0;
        iVar14 = 1;
    } else {
        iVar17 = *(int*)((char*)self + 0x68) + -1;
        iVar14 = -1;
    }
    // NEEDS_MANUAL: *(uint32_t*)((char*)self + 0x7c) = in_FPUControlWord
    if (*(int*)((char*)self + 0x5c) != 0) {
        FUN_00601966((void*)param_3);
    }
    uint32_t y = 0;
    if (*(int*)((char*)self + 0x68) != 0) {
        int iVar10 = iVar14 * 0x10;
        int iVar9 = iVar17 * 0x10;
        float* src = (float*)(iVar9 + 8 + param_3);
        int iVar11 = (iVar14 + iVar17) * 0x10;
        iVar17 = (iVar17 - iVar14) * 0x10;
        do {
            float fVar2 = *(float*)(iVar3 + (uVar12 + uVar8 * 8) * 4 + (y & 3) * 4);
            float fVar4 = (local_58 + src[-2]) * 1023.0f;
            float fVar5 = (local_54 + src[-1]) * 1023.0f;
            float fVar6 = (local_50 + *src) * 1023.0f;
            float fVar7 = (local_4c + src[1]) * 3.0f;
            uint32_t local_38 = (uint32_t)LocalRound(fVar4 + fVar2);
            uint32_t local_34 = (uint32_t)LocalRound(fVar5 + fVar2);
            uint32_t local_30 = (uint32_t)LocalRound(fVar6 + fVar2);
            int iVar13 = LocalRound(fVar7 + fVar2);
            if (*(int*)((char*)self + 0x5c) != 0) {
                float* pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x10 + iVar17);
                local_58 = (fVar4 - (float)(int)local_38) * 0.0009775171f;
                *pfVar1 = local_58 * 0.1875f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x10 + iVar9);
                *pfVar1 = local_58 * 0.3125f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x10 + iVar11);
                *pfVar1 = local_58 * 0.0625f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x14 + iVar17);
                local_58 = local_58 * 0.4375f;
                local_54 = (fVar5 - (float)(int)local_34) * 0.0009775171f;
                *pfVar1 = local_54 * 0.1875f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x14 + iVar9);
                *pfVar1 = local_54 * 0.3125f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x14 + iVar11);
                *pfVar1 = local_54 * 0.0625f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x18 + iVar17);
                local_54 = local_54 * 0.4375f;
                local_50 = (fVar6 - (float)(int)local_30) * 0.0009775171f;
                *pfVar1 = local_50 * 0.1875f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x18 + iVar9);
                *pfVar1 = local_50 * 0.3125f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x18 + iVar11);
                *pfVar1 = local_50 * 0.0625f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x1c + iVar17);
                local_50 = local_50 * 0.4375f;
                local_4c = (fVar7 - (float)iVar13) * 0.33333334f;
                *pfVar1 = local_4c * 0.1875f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x1c + iVar9);
                *pfVar1 = local_4c * 0.3125f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x1c + iVar11);
                *pfVar1 = local_4c * 0.0625f + *pfVar1;
                local_4c = local_4c * 0.4375f;
            }
            uint32_t uVar15 = local_38;
            if (0x3fe < (int)local_38) {
                uVar15 = 0x3ff;
            }
            if ((int)uVar15 < 1) {
                local_38 = 0;
            } else if (0x3fe < (int)local_38) {
                local_38 = 0x3ff;
            }
            uVar15 = local_34;
            if (0x3fe < (int)local_34) {
                uVar15 = 0x3ff;
            }
            if ((int)uVar15 < 1) {
                local_34 = 0;
            } else if (0x3fe < (int)local_34) {
                local_34 = 0x3ff;
            }
            uVar15 = local_30;
            if (0x3fe < (int)local_30) {
                uVar15 = 0x3ff;
            }
            if ((int)uVar15 < 1) {
                local_30 = 0;
            } else if (0x3fe < (int)local_30) {
                local_30 = 0x3ff;
            }
            int iVar16;
            if (iVar13 < 3) {
                iVar16 = iVar13;
            } else {
                iVar16 = 3;
            }
            if (iVar16 < 1) {
                iVar13 = 0;
            } else if (2 < iVar13) {
                iVar13 = 3;
            }
            *local_8 = ((((uint32_t)iVar13 << 10) | local_38) << 10 | local_34) << 10 | local_30;
            local_8 = local_8 + iVar14;
            src = src + iVar14 * 4;
            iVar9 = iVar9 + iVar10;
            iVar17 = iVar17 + iVar10;
            iVar11 = iVar11 + iVar10;
            y = y + 1;
        } while (y < *(uint*)((char*)self + 0x68));
    }
}

// 0x604ccd — observed shape
// Uploads one row of four 16-bit channels (8 bytes per texel). Same dither /
// error-diffusion structure as 0x604918, with channel residual scaled by
// 1/65535 (1.5259022e-05) and clamping to 0xffff. Each texel is emitted as
// two dwords built from the four clamped channels.
void FUN_00604ccd(void* self, uint32_t param_1, float* param_2, int param_3)
{
    if (*(int*)((char*)self + 0x54) != 0) {
        param_3 = (int)(intptr_t)FUN_00600136((void*)(intptr_t)param_3);
    }
    if (*(int*)((char*)self + 0x10) != 0) {
        param_3 = (int)(intptr_t)FUN_0060164a((void*)(intptr_t)param_3);
    }
    float local_60 = 0.0f;
    float local_5c = 0.0f;
    float local_58 = 0.0f;
    float local_54 = 0.0f;
    uint32_t* local_8 = (uint32_t*)(*(int*)((char*)self + 0x60) * param_1 +
                                    (*(int*)((char*)self + 0x68) + -1) * (param_1 & 1) * 8 +
                                    *(int*)((char*)self + 100) * (int)param_2 +
                                    *(int*)((char*)self + 0x20));
    uint32_t uVar8 = param_1 & 3;
    uint32_t uVar11 = (uint32_t)param_2 & 3;
    int iVar3 = *(int*)((char*)self + 0x34);
    int iVar14;
    int iVar13;
    if ((param_1 & 1) == 0) {
        iVar14 = 0;
        iVar13 = 1;
    } else {
        iVar14 = *(int*)((char*)self + 0x68) + -1;
        iVar13 = -1;
    }
    // NEEDS_MANUAL: *(uint32_t*)((char*)self + 0x7c) = in_FPUControlWord
    if (*(int*)((char*)self + 0x5c) != 0) {
        FUN_00601966((void*)param_3);
    }
    uint32_t y = 0;
    if (*(int*)((char*)self + 0x68) != 0) {
        int iVar9 = iVar13 * 0x10;
        int iVar10 = iVar14 * 0x10;
        int local_10 = (iVar13 + iVar14) * 0x10;
        int local_c = (iVar14 - iVar13) * 0x10;
        float* src = (float*)(iVar10 + 8 + param_3);
        do {
            float fVar2 = *(float*)(iVar3 + (uVar11 + uVar8 * 8) * 4 + (y & 3) * 4);
            float fVar4 = (local_60 + src[-2]) * 65535.0f;
            float fVar5 = (local_5c + src[-1]) * 65535.0f;
            float fVar6 = (local_58 + *src) * 65535.0f;
            float fVar7 = (local_54 + src[1]) * 65535.0f;
            uint32_t local_40 = (uint32_t)LocalRound(fVar4 + fVar2);
            uint32_t local_3c = (uint32_t)LocalRound(fVar5 + fVar2);
            uint32_t local_38 = (uint32_t)LocalRound(fVar6 + fVar2);
            int local_34 = LocalRound(fVar7 + fVar2);
            if (*(int*)((char*)self + 0x5c) != 0) {
                float* pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x10 + local_c);
                local_60 = (fVar4 - (float)(int)local_40) * 1.5259022e-05f;
                *pfVar1 = local_60 * 0.1875f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x10 + iVar10);
                *pfVar1 = local_60 * 0.3125f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x10 + local_10);
                *pfVar1 = local_60 * 0.0625f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x14 + local_c);
                local_60 = local_60 * 0.4375f;
                local_5c = (fVar5 - (float)(int)local_3c) * 1.5259022e-05f;
                *pfVar1 = local_5c * 0.1875f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x14 + iVar10);
                *pfVar1 = local_5c * 0.3125f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x14 + local_10);
                *pfVar1 = local_5c * 0.0625f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x18 + local_c);
                local_5c = local_5c * 0.4375f;
                local_58 = (fVar6 - (float)(int)local_38) * 1.5259022e-05f;
                *pfVar1 = local_58 * 0.1875f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x18 + iVar10);
                *pfVar1 = local_58 * 0.3125f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x18 + local_10);
                *pfVar1 = local_58 * 0.0625f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x1c + local_c);
                local_58 = local_58 * 0.4375f;
                local_54 = (fVar7 - (float)local_34) * 1.5259022e-05f;
                *pfVar1 = local_54 * 0.1875f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x1c + iVar10);
                *pfVar1 = local_54 * 0.3125f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x1c + local_10);
                *pfVar1 = local_54 * 0.0625f + *pfVar1;
                local_54 = local_54 * 0.4375f;
            }
            uint32_t uVar12 = local_40;
            if (0xfffe < (int)local_40) {
                uVar12 = 0xffff;
            }
            if ((int)uVar12 < 1) {
                local_40 = 0;
            } else if (0xfffe < (int)local_40) {
                local_40 = 0xffff;
            }
            uVar12 = local_3c;
            if (0xfffe < (int)local_3c) {
                uVar12 = 0xffff;
            }
            if ((int)uVar12 < 1) {
                local_3c = 0;
            } else if (0xfffe < (int)local_3c) {
                local_3c = 0xffff;
            }
            uVar12 = local_38;
            if (0xfffe < (int)local_38) {
                uVar12 = 0xffff;
            }
            if ((int)uVar12 < 1) {
                local_38 = 0;
            } else if (0xfffe < (int)local_38) {
                local_38 = 0xffff;
            }
            iVar14 = local_34;
            if (0xfffe < local_34) {
                iVar14 = 0xffff;
            }
            if (iVar14 < 1) {
                local_34 = 0;
            } else if (0xfffe < local_34) {
                local_34 = 0xffff;
            }
            *local_8 = local_3c << 0x10 | local_40;
            local_8[1] = (((local_34 << 0x10 | local_38) >> 0x10) | ((int)local_3c >> 0x1f)) << 0x10 |
                         (((local_38 << 0x10 | local_3c) >> 0x10) | ((int)local_40 >> 0x1f));
            local_8 = local_8 + iVar13 * 2;
            src = src + iVar13 * 4;
            local_c = local_c + iVar9;
            local_10 = local_10 + iVar9;
            iVar10 = iVar10 + iVar9;
            y = y + 1;
        } while (y < *(uint*)((char*)self + 0x68));
    }
}

// 0x605084 — observed shape
// Nearest-palette search plus 8-bit alpha upload (one ushort per texel:
// high byte = alpha, low byte = palette index). The palette at +0x38 is
// searched over 256 four-float entries by squared 3D distance.
void FUN_00605084(void* self, float* param_1, uint32_t param_2, uint32_t param_3)
{
    if (*(int*)((char*)self + 0x54) != 0) {
        param_3 = (uint32_t)(intptr_t)FUN_00600136((void*)(intptr_t)param_3);
    }
    if (*(int*)((char*)self + 0x10) != 0) {
        param_3 = (uint32_t)(intptr_t)FUN_0060164a((void*)(intptr_t)param_3);
    }
    int iVar5 = (int)param_3;
    float local_3c = 0.0f;
    uint32_t uVar6 = (uint32_t)(uintptr_t)param_1 & 3;
    uint32_t uVar9 = param_2 & 3;
    int iVar2 = *(int*)((char*)self + 0x34);
    uint16_t* puVar12 = (uint16_t*)(*(int*)((char*)self + 0x60) * (int)(intptr_t)param_1 +
                                    (*(int*)((char*)self + 0x68) + -1) *
                                        ((uint32_t)(uintptr_t)param_1 & 1) * 2 +
                                    *(int*)((char*)self + 100) * (int)param_2 +
                                    *(int*)((char*)self + 0x20));
    int iVar13;
    if (((uint32_t)(uintptr_t)param_1 & 1) == 0) {
        iVar13 = 0;
        param_1 = (float*)0x1;
    } else {
        iVar13 = *(int*)((char*)self + 0x68) + -1;
        param_1 = (float*)0xffffffff;
    }
    int iVar4 = (int)(intptr_t)param_1;
    // NEEDS_MANUAL: *(uint32_t*)((char*)self + 0x7c) = in_FPUControlWord
    if (*(int*)((char*)self + 0x5c) != 0) {
        FUN_00601966((void*)param_3);
    }
    param_2 = 0;
    if (*(int*)((char*)self + 0x68) != 0) {
        int iVar7 = (int)(intptr_t)param_1 * 0x10;
        int iVar10 = (int)(intptr_t)param_1 + iVar13;
        int local_1c = (iVar13 - (int)(intptr_t)param_1) * 0x10;
        param_1 = (float*)(iVar13 * 0x10 + 8 + param_3);
        iVar10 = iVar10 * 0x10;
        do {
            float* local_8 = *(float**)((char*)self + 0x38);
            uint32_t local_18 = 0;
            int j = 0;
            float local_14 = 3.4028235e38f;
            do {
                float fVar3 = (param_1[-2] - *local_8) * (param_1[-2] - *local_8) +
                              (param_1[-1] - local_8[1]) * (param_1[-1] - local_8[1]) +
                              (*param_1 - local_8[2]) * (*param_1 - local_8[2]);
                if (fVar3 < local_14) {
                    local_18 = (uint32_t)j;
                    local_14 = fVar3;
                }
                j = j + 1;
                local_8 = local_8 + 4;
            } while (j < 0x100);
            float fVar3 = (local_3c + param_1[1]) * 255.0f;
            uint32_t uVar8 = (uint32_t)LocalRound(
                fVar3 + *(float*)(iVar2 + (uVar9 + uVar6 * 8) * 4 + (param_2 & 3) * 4));
            if (*(int*)((char*)self + 0x5c) != 0) {
                float* pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x1c + local_1c);
                local_3c = (fVar3 - (float)(int)uVar8) * 0.003921569f;
                *pfVar1 = local_3c * 0.1875f + *pfVar1;
                pfVar1 = (float*)((*(int*)((char*)self + 0x5c) - iVar5) + 0x14 +
                                  (int)(intptr_t)param_1);
                *pfVar1 = local_3c * 0.3125f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x1c + iVar10);
                *pfVar1 = local_3c * 0.0625f + *pfVar1;
                local_3c = local_3c * 0.4375f;
            }
            uint32_t uVar11 = uVar8;
            if (0xfe < (int)uVar8) {
                uVar11 = 0xff;
            }
            if ((int)uVar11 < 1) {
                uVar8 = 0;
            } else if (0xfe < (int)uVar8) {
                uVar8 = 0xff;
            }
            param_1 = param_1 + iVar4 * 4;
            iVar10 = iVar10 + iVar7;
            *puVar12 = (uint16_t)(((uVar8 & 0xff) << 8) | (local_18 & 0xff));
            local_1c = local_1c + iVar7;
            puVar12 = puVar12 + iVar4;
            param_2 = param_2 + 1;
        } while (param_2 < *(uint*)((char*)self + 0x68));
    }
}

// 0x6052cc — observed shape
// Builds the 8-bit palette-index row: for each source vertex, scans the 256
// RGBA entries at +0x38 and stores the index of the closest by squared 4D
// distance. No dither / diffusion in this variant.
void FUN_006052cc(void* self, uint32_t param_1, float param_2, uint32_t param_3)
{
    if (*(int*)((char*)self + 0x54) != 0) {
        param_3 = (uint32_t)(intptr_t)FUN_00600136((void*)(intptr_t)param_3);
    }
    if (*(int*)((char*)self + 0x10) != 0) {
        param_3 = (uint32_t)(intptr_t)FUN_0060164a((void*)(intptr_t)param_3);
    }
    uint8_t* puVar2 = (uint8_t*)(*(int*)((char*)self + 0x60) * param_1 +
                                 *(int*)((char*)self + 100) * (int)param_2 +
                                 *(int*)((char*)self + 0x20));
    uint32_t i = 0;
    if (*(int*)((char*)self + 0x68) != 0) {
        float* pfVar5 = (float*)(param_3 + 8);
        do {
            float* pfVar3 = *(float**)((char*)self + 0x38);
            uint32_t uVar4 = 0;
            int j = 0;
            float best = 3.4028235e38f;
            do {
                float fVar1 = (pfVar5[-2] - *pfVar3) * (pfVar5[-2] - *pfVar3) +
                              (pfVar5[-1] - pfVar3[1]) * (pfVar5[-1] - pfVar3[1]) +
                              (*pfVar5 - pfVar3[2]) * (*pfVar5 - pfVar3[2]) +
                              (pfVar5[1] - pfVar3[3]) * (pfVar5[1] - pfVar3[3]);
                if (fVar1 < best) {
                    uVar4 = (uint32_t)j;
                    best = fVar1;
                }
                j = j + 1;
                pfVar3 = pfVar3 + 4;
            } while (j < 0x100);
            *puVar2 = (uint8_t)uVar4;
            puVar2 = puVar2 + 1;
            i = i + 1;
            pfVar5 = pfVar5 + 4;
        } while (i < *(uint*)((char*)self + 0x68));
    }
}

// 0x605393 — observed shape
// Converts each source vertex to luminance in place (0.2125/0.7154/0.0721),
// then uploads one 8-bit luma row with dither and error diffusion
// (residual scaled by 1/255 = 0.003921569).
void FUN_00605393(void* self, uint32_t param_1, uint32_t param_2, float* param_3)
{
    if (*(int*)((char*)self + 0x54) != 0) {
        param_3 = (float*)FUN_00600136(param_3);
    }
    if (*(int*)((char*)self + 0x10) != 0) {
        param_3 = (float*)FUN_0060164a(param_3);
    }
    float local_38 = 0.0f;
    uint32_t uVar3 = param_1 & 3;
    uint32_t uVar6 = param_2 & 3;
    uint8_t* puVar12 = (uint8_t*)(*(int*)((char*)self + 0x60) * param_1 +
                                  *(int*)((char*)self + 100) * param_2 +
                                  (*(int*)((char*)self + 0x68) + -1) * (param_1 & 1) +
                                  *(int*)((char*)self + 0x20));
    int iVar1 = *(int*)((char*)self + 0x34);
    int iVar10;
    uint32_t iStep;
    if ((param_1 & 1) == 0) {
        iVar10 = 0;
        iStep = 1;
    } else {
        iVar10 = *(int*)((char*)self + 0x68) + -1;
        iStep = 0xffffffffu;
    }
    // NEEDS_MANUAL: *(uint32_t*)((char*)self + 0x7c) = in_FPUControlWord
    uint32_t uVar7 = 0;
    if (*(int*)((char*)self + 0x68) != 0) {
        float* pfVar4 = param_3;
        do {
            uVar7 = uVar7 + 1;
            *pfVar4 = *pfVar4 * 0.2125f + pfVar4[1] * 0.7154f + pfVar4[2] * 0.0721f;
            pfVar4 = pfVar4 + 4;
        } while (uVar7 < *(uint*)((char*)self + 0x68));
    }
    if (*(int*)((char*)self + 0x5c) != 0) {
        FUN_00601966(param_3);
    }
    param_2 = 0;
    if (*(int*)((char*)self + 0x68) != 0) {
        int iVar8 = (int)iStep * 0x10;
        int iVar5 = iVar10 << 4;
        int iVar9 = (int)(iStep + (uint32_t)iVar10) * 0x10;
        int local_8 = (iVar10 - (int)iStep) * 0x10;
        do {
            float fVar2 = (local_38 + *(float*)(iVar5 + (int)(intptr_t)param_3)) * 255.0f;
            iVar10 = LocalRound(
                fVar2 + *(float*)(iVar1 + (uVar6 + uVar3 * 8) * 4 + (param_2 & 3) * 4));
            if (*(int*)((char*)self + 0x5c) != 0) {
                float* pfVar4 = (float*)(local_8 + 0x10 + *(int*)((char*)self + 0x5c));
                local_38 = (fVar2 - (float)iVar10) * 0.003921569f;
                *pfVar4 = local_38 * 0.1875f + *pfVar4;
                pfVar4 = (float*)(iVar5 + 0x10 + *(int*)((char*)self + 0x5c));
                *pfVar4 = local_38 * 0.3125f + *pfVar4;
                pfVar4 = (float*)(iVar9 + 0x10 + *(int*)((char*)self + 0x5c));
                *pfVar4 = local_38 * 0.0625f + *pfVar4;
                local_38 = local_38 * 0.4375f;
            }
            int iVar11 = iVar10;
            if (0xfe < iVar10) {
                iVar11 = 0xff;
            }
            if (iVar11 < 1) {
                iVar10 = 0;
            } else if (0xfe < iVar10) {
                iVar10 = 0xff;
            }
            *puVar12 = (uint8_t)iVar10;
            local_8 = local_8 + iVar8;
            puVar12 = puVar12 + (int)iStep;
            iVar5 = iVar5 + iVar8;
            iVar9 = iVar9 + iVar8;
            param_2 = param_2 + 1;
        } while (param_2 < *(uint*)((char*)self + 0x68));
    }
}

// 0x60557c — observed shape
// Luminance conversion plus 8-bit luma + 8-bit alpha upload packed into one
// ushort per texel (low byte = luma, high byte = alpha).
void FUN_0060557c(void* self, uint32_t param_1, uint32_t param_2, float* param_3)
{
    if (*(int*)((char*)self + 0x54) != 0) {
        param_3 = (float*)FUN_00600136(param_3);
    }
    if (*(int*)((char*)self + 0x10) != 0) {
        param_3 = (float*)FUN_0060164a(param_3);
    }
    float local_50 = 0.0f;
    float local_44 = 0.0f;
    uint16_t* local_8 = (uint16_t*)(*(int*)((char*)self + 0x60) * param_1 +
                                    (*(int*)((char*)self + 0x68) + -1) * (param_1 & 1) * 2 +
                                    *(int*)((char*)self + 100) * param_2 +
                                    *(int*)((char*)self + 0x20));
    uint32_t uVar5 = param_1 & 3;
    uint32_t uVar8 = param_2 & 3;
    int iVar2 = *(int*)((char*)self + 0x34);
    int iVar12;
    int iVar13;
    uint32_t iStep;
    if ((param_1 & 1) == 0) {
        iVar12 = 0;
        iVar13 = 1;
        iStep = 1;
    } else {
        iVar12 = *(int*)((char*)self + 0x68) + -1;
        iStep = 0xffffffffu;
        iVar13 = -1;
    }
    // NEEDS_MANUAL: *(uint32_t*)((char*)self + 0x7c) = in_FPUControlWord
    uint32_t uVar9 = 0;
    if (*(int*)((char*)self + 0x68) != 0) {
        float* pfVar6 = param_3;
        do {
            uVar9 = uVar9 + 1;
            *pfVar6 = *pfVar6 * 0.2125f + pfVar6[1] * 0.7154f + pfVar6[2] * 0.0721f;
            pfVar6 = pfVar6 + 4;
        } while (uVar9 < *(uint*)((char*)self + 0x68));
    }
    if (*(int*)((char*)self + 0x5c) != 0) {
        FUN_00601966(param_3);
    }
    param_1 = 0;
    if (*(int*)((char*)self + 0x68) != 0) {
        int iVar10 = iVar13 * 0x10;
        int iVar7 = iVar12 << 4;
        int iVar14 = (iVar13 + iVar12) * 0x10;
        iVar12 = (iVar12 - (int)iStep) * 0x10;
        do {
            float fVar1 = *(float*)(iVar2 + (uVar8 + uVar5 * 8) * 4 + (param_1 & 3) * 4);
            float fVar3 = (local_50 + *(float*)((int)(intptr_t)param_3 + iVar7)) * 255.0f;
            float fVar4 = (local_44 + ((float*)((int)(intptr_t)param_3 + iVar7))[3]) * 255.0f;
            int local_30 = LocalRound(fVar3 + fVar1);
            int local_24 = LocalRound(fVar4 + fVar1);
            if (*(int*)((char*)self + 0x5c) != 0) {
                float* pfVar6 = (float*)(iVar12 + 0x10 + *(int*)((char*)self + 0x5c));
                local_50 = (fVar3 - (float)local_30) * 0.003921569f;
                *pfVar6 = local_50 * 0.1875f + *pfVar6;
                pfVar6 = (float*)(iVar7 + 0x10 + *(int*)((char*)self + 0x5c));
                *pfVar6 = local_50 * 0.3125f + *pfVar6;
                pfVar6 = (float*)(iVar14 + 0x10 + *(int*)((char*)self + 0x5c));
                *pfVar6 = local_50 * 0.0625f + *pfVar6;
                pfVar6 = (float*)(iVar12 + 0x1c + *(int*)((char*)self + 0x5c));
                local_50 = local_50 * 0.4375f;
                local_44 = (fVar4 - (float)local_24) * 0.003921569f;
                *pfVar6 = local_44 * 0.1875f + *pfVar6;
                pfVar6 = (float*)(iVar7 + 0x1c + *(int*)((char*)self + 0x5c));
                *pfVar6 = local_44 * 0.3125f + *pfVar6;
                pfVar6 = (float*)(iVar14 + 0x1c + *(int*)((char*)self + 0x5c));
                *pfVar6 = local_44 * 0.0625f + *pfVar6;
                local_44 = local_44 * 0.4375f;
            }
            int iVar11 = local_30;
            if (0xfe < local_30) {
                iVar11 = 0xff;
            }
            if (iVar11 < 1) {
                local_30 = 0;
            } else if (0xfe < local_30) {
                local_30 = 0xff;
            }
            iVar11 = local_24;
            if (0xfe < local_24) {
                iVar11 = 0xff;
            }
            if (iVar11 < 1) {
                local_24 = 0;
            } else if (0xfe < local_24) {
                local_24 = 0xff;
            }
            iVar7 = iVar7 + iVar10;
            iVar12 = iVar12 + iVar10;
            iVar14 = iVar14 + iVar10;
            *local_8 = (uint16_t)((uint8_t)local_24 << 8 | (uint16_t)local_30);
            local_8 = local_8 + iVar13;
            param_1 = param_1 + 1;
        } while (param_1 < *(uint*)((char*)self + 0x68));
    }
}

// 0x60580a — observed shape
// Luminance conversion plus 4:4 packed 8-bit upload (one byte per texel,
// high nibble / low nibble), residual scaled by 1/15 (0.06666667).
void FUN_0060580a(void* self, uint32_t param_1, uint32_t param_2, float* param_3)
{
    if (*(int*)((char*)self + 0x54) != 0) {
        param_3 = (float*)FUN_00600136(param_3);
    }
    if (*(int*)((char*)self + 0x10) != 0) {
        param_3 = (float*)FUN_0060164a(param_3);
    }
    float local_54 = 0.0f;
    float local_48 = 0.0f;
    uint32_t uVar5 = param_1 & 3;
    uint32_t uVar8 = param_2 & 3;
    uint8_t* pbVar13 = (uint8_t*)((*(int*)((char*)self + 0x68) + -1) * (param_1 & 1) +
                                  *(int*)((char*)self + 0x60) * param_1 +
                                  *(int*)((char*)self + 100) * param_2 +
                                  *(int*)((char*)self + 0x20));
    int iVar2 = *(int*)((char*)self + 0x34);
    int startIndex;
    int iStep;
    if ((param_1 & 1) == 0) {
        startIndex = 0;
        iStep = 1;
    } else {
        startIndex = *(int*)((char*)self + 0x68) + -1;
        iStep = -1;
    }
    // NEEDS_MANUAL: the listing forms CONCAT22(local_c._2_2_, in_FPUControlWord)
    // and stores it to *(int*)((char*)self + 0x7c); local_c is then reused as
    // a row-base offset, so the control-word value is not recoverable here.
    uint32_t uVar9 = 0;
    if (*(int*)((char*)self + 0x68) != 0) {
        float* pfVar6 = param_3;
        do {
            uVar9 = uVar9 + 1;
            *pfVar6 = pfVar6[1] * 0.7154f + *pfVar6 * 0.2125f + pfVar6[2] * 0.0721f;
            pfVar6 = pfVar6 + 4;
        } while (uVar9 < *(uint*)((char*)self + 0x68));
    }
    if (*(int*)((char*)self + 0x5c) != 0) {
        FUN_00601966(param_3);
    }
    uint32_t local_8 = 0;
    if (*(int*)((char*)self + 0x68) != 0) {
        int iVar10 = iStep * 0x10;
        int iVar7 = startIndex << 4;
        int local_c = (iStep + startIndex) * 0x10;
        int rowOff = (startIndex - iStep) * 0x10;
        do {
            float fVar1 = *(float*)(iVar2 + (uVar8 + uVar5 * 8) * 4 + (local_8 & 3) * 4);
            float fVar3 = (local_54 + *(float*)((int)(intptr_t)param_3 + iVar7)) * 15.0f;
            float fVar4 = (local_48 + ((float*)((int)(intptr_t)param_3 + iVar7))[3]) * 15.0f;
            int local_34 = LocalRound(fVar3 + fVar1);
            int iVar11 = LocalRound(fVar4 + fVar1);
            if (*(int*)((char*)self + 0x5c) != 0) {
                float* pfVar6 = (float*)(*(int*)((char*)self + 0x5c) + 0x10 + rowOff);
                local_54 = (fVar3 - (float)local_34) * 0.06666667f;
                *pfVar6 = local_54 * 0.1875f + *pfVar6;
                pfVar6 = (float*)(*(int*)((char*)self + 0x5c) + 0x10 + iVar7);
                *pfVar6 = local_54 * 0.3125f + *pfVar6;
                pfVar6 = (float*)(*(int*)((char*)self + 0x5c) + 0x10 + local_c);
                *pfVar6 = local_54 * 0.0625f + *pfVar6;
                pfVar6 = (float*)(*(int*)((char*)self + 0x5c) + 0x1c + rowOff);
                local_54 = local_54 * 0.4375f;
                local_48 = (fVar4 - (float)iVar11) * 0.06666667f;
                *pfVar6 = local_48 * 0.1875f + *pfVar6;
                pfVar6 = (float*)(*(int*)((char*)self + 0x5c) + 0x1c + iVar7);
                *pfVar6 = local_48 * 0.3125f + *pfVar6;
                pfVar6 = (float*)(*(int*)((char*)self + 0x5c) + 0x1c + local_c);
                *pfVar6 = local_48 * 0.0625f + *pfVar6;
                local_48 = local_48 * 0.4375f;
            }
            int iVar12;
            if (local_34 < 0xf) {
                iVar12 = local_34;
            } else {
                iVar12 = 0xf;
            }
            if (iVar12 < 1) {
                local_34 = 0;
            } else if (0xe < local_34) {
                local_34 = 0xf;
            }
            if (iVar11 < 0xf) {
                iVar12 = iVar11;
            } else {
                iVar12 = 0xf;
            }
            if (iVar12 < 1) {
                iVar11 = 0;
            } else if (0xe < iVar11) {
                iVar11 = 0xf;
            }
            *pbVar13 = (uint8_t)(iVar11 << 4 | (uint8_t)local_34);
            rowOff = rowOff + iVar10;
            pbVar13 = pbVar13 + iStep;
            local_c = local_c + iVar10;
            iVar7 = iVar7 + iVar10;
            local_8 = local_8 + 1;
        } while (local_8 < *(uint*)((char*)self + 0x68));
    }
}

// 0x605aab — observed shape
// Luminance conversion plus single 16-bit channel upload (residual scaled by
// 1/65535 = 1.5259022e-05), clamped to 0xffff.
void FUN_00605aab(void* self, uint32_t param_1, uint32_t param_2, float* param_3)
{
    if (*(int*)((char*)self + 0x54) != 0) {
        param_3 = (float*)FUN_00600136(param_3);
    }
    if (*(int*)((char*)self + 0x10) != 0) {
        param_3 = (float*)FUN_0060164a(param_3);
    }
    float local_38 = 0.0f;
    uint32_t uVar4 = param_1 & 3;
    uint32_t uVar7 = param_2 & 3;
    int iVar1 = *(int*)((char*)self + 0x34);
    uint16_t* puVar11 = (uint16_t*)(*(int*)((char*)self + 0x60) * param_1 +
                                    *(int*)((char*)self + 100) * param_2 +
                                    (*(int*)((char*)self + 0x68) + -1) * (param_1 & 1) * 2 +
                                    *(int*)((char*)self + 0x20));
    int iVar12;
    uint32_t iStep;
    if ((param_1 & 1) == 0) {
        iVar12 = 0;
        iStep = 1;
    } else {
        iVar12 = *(int*)((char*)self + 0x68) + -1;
        iStep = 0xffffffffu;
    }
    int iVar3 = (int)iStep;
    // NEEDS_MANUAL: *(uint32_t*)((char*)self + 0x7c) = in_FPUControlWord
    uint32_t uVar8 = 0;
    if (*(int*)((char*)self + 0x68) != 0) {
        float* pfVar5 = param_3;
        do {
            uVar8 = uVar8 + 1;
            *pfVar5 = *pfVar5 * 0.2125f + pfVar5[1] * 0.7154f + pfVar5[2] * 0.0721f;
            pfVar5 = pfVar5 + 4;
        } while (uVar8 < *(uint*)((char*)self + 0x68));
    }
    if (*(int*)((char*)self + 0x5c) != 0) {
        FUN_00601966(param_3);
    }
    param_1 = 0;
    if (*(int*)((char*)self + 0x68) != 0) {
        int iVar9 = iVar3 * 0x10;
        int iVar6 = iVar12 << 4;
        int iVar10 = (iVar3 + iVar12) * 0x10;
        param_2 = (uint32_t)((iVar12 - iVar3) * 0x10);
        do {
            float fVar2 = (local_38 + *(float*)(iVar6 + (int)(intptr_t)param_3)) * 65535.0f;
            iVar12 = LocalRound(
                fVar2 + *(float*)(iVar1 + (uVar7 + uVar4 * 8) * 4 + (param_1 & 3) * 4));
            if (*(int*)((char*)self + 0x5c) != 0) {
                float* pfVar5 = (float*)((int)param_2 + 0x10 + *(int*)((char*)self + 0x5c));
                local_38 = (fVar2 - (float)iVar12) * 1.5259022e-05f;
                *pfVar5 = local_38 * 0.1875f + *pfVar5;
                pfVar5 = (float*)(iVar6 + 0x10 + *(int*)((char*)self + 0x5c));
                *pfVar5 = local_38 * 0.3125f + *pfVar5;
                pfVar5 = (float*)(iVar10 + 0x10 + *(int*)((char*)self + 0x5c));
                *pfVar5 = local_38 * 0.0625f + *pfVar5;
                local_38 = local_38 * 0.4375f;
            }
            int iVar13 = iVar12;
            if (0xfffe < iVar12) {
                iVar13 = 0xffff;
            }
            if (iVar13 < 1) {
                iVar12 = 0;
            } else if (0xfffe < iVar12) {
                iVar12 = 0xffff;
            }
            *puVar11 = (uint16_t)iVar12;
            param_2 = param_2 + (uint32_t)iVar9;
            puVar11 = puVar11 + iVar3;
            iVar6 = iVar6 + iVar9;
            iVar10 = iVar10 + iVar9;
            param_1 = param_1 + 1;
        } while (param_1 < *(uint*)((char*)self + 0x68));
    }
}

// 0x605c9c — observed shape
// Two signed 8-bit channels packed into one ushort (low byte, high byte),
// each clamped to [-127, 127]; residual scaled by 1/127 (0.007874016).
void FUN_00605c9c(void* self, uint32_t param_1, uint32_t param_2, int param_3)
{
    if (*(int*)((char*)self + 0x54) != 0) {
        param_3 = (int)(intptr_t)FUN_00600136((void*)(intptr_t)param_3);
    }
    if (*(int*)((char*)self + 0x10) != 0) {
        param_3 = (int)(intptr_t)FUN_0060164a((void*)(intptr_t)param_3);
    }
    float local_50 = 0.0f;
    float local_4c = 0.0f;
    uint32_t uVar6 = param_1 & 3;
    uint32_t uVar8 = param_2 & 3;
    uint16_t* local_8 = (uint16_t*)(*(int*)((char*)self + 0x60) * param_1 +
                                    (*(int*)((char*)self + 0x68) + -1) * (param_1 & 1) * 2 +
                                    *(int*)((char*)self + 100) * param_2 +
                                    *(int*)((char*)self + 0x20));
    int iVar3 = *(int*)((char*)self + 0x34);
    int iVar11;
    int iVar12;
    uint32_t iStep;
    if ((param_1 & 1) == 0) {
        iVar11 = 0;
        iVar12 = 1;
        iStep = 1;
    } else {
        iVar11 = *(int*)((char*)self + 0x68) + -1;
        iStep = 0xffffffffu;
        iVar12 = -1;
    }
    // NEEDS_MANUAL: *(uint32_t*)((char*)self + 0x7c) = in_FPUControlWord
    if (*(int*)((char*)self + 0x5c) != 0) {
        FUN_00601966((void*)param_3);
    }
    param_1 = 0;
    if (*(int*)((char*)self + 0x68) != 0) {
        int iVar9 = iVar12 * 0x10;
        int iVar7 = iVar11 << 4;
        int iVar13 = (iVar12 + iVar11) * 0x10;
        iVar11 = (iVar11 - (int)iStep) * 0x10;
        do {
            float fVar2 = *(float*)(iVar3 + (uVar8 + uVar6 * 8) * 4 + (param_1 & 3) * 4);
            float fVar4 = (local_50 + *(float*)(param_3 + iVar7)) * 127.0f;
            float fVar5 = (local_4c + ((float*)(param_3 + iVar7))[1]) * 127.0f;
            int local_30 = LocalRound(fVar4 + fVar2);
            int iVar14 = LocalRound(fVar5 + fVar2);
            if (*(int*)((char*)self + 0x5c) != 0) {
                float* pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x10 + iVar11);
                local_50 = (fVar4 - (float)local_30) * 0.007874016f;
                *pfVar1 = local_50 * 0.1875f + *pfVar1;
                pfVar1 = (float*)(iVar7 + 0x10 + *(int*)((char*)self + 0x5c));
                *pfVar1 = local_50 * 0.3125f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x10 + iVar13);
                *pfVar1 = local_50 * 0.0625f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x14 + iVar11);
                local_50 = local_50 * 0.4375f;
                local_4c = (fVar5 - (float)iVar14) * 0.007874016f;
                *pfVar1 = local_4c * 0.1875f + *pfVar1;
                pfVar1 = (float*)(iVar7 + 0x14 + *(int*)((char*)self + 0x5c));
                *pfVar1 = local_4c * 0.3125f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x14 + iVar13);
                *pfVar1 = local_4c * 0.0625f + *pfVar1;
                local_4c = local_4c * 0.4375f;
            }
            int iVar10;
            if (local_30 < 0x7f) {
                iVar10 = local_30;
            } else {
                iVar10 = 0x7f;
            }
            if (iVar10 < -0x7e) {
                local_30 = -0x7f;
            } else if (0x7e < local_30) {
                local_30 = 0x7f;
            }
            if (iVar14 < 0x7f) {
                iVar10 = iVar14;
            } else {
                iVar10 = 0x7f;
            }
            if (iVar10 < -0x7e) {
                iVar14 = -0x7f;
            } else if (0x7e < iVar14) {
                iVar14 = 0x7f;
            }
            iVar7 = iVar7 + iVar9;
            iVar11 = iVar11 + iVar9;
            iVar13 = iVar13 + iVar9;
            *local_8 = (uint16_t)(((uint8_t)(int8_t)iVar14 << 8) | (uint8_t)local_30);
            local_8 = local_8 + iVar12;
            param_1 = param_1 + 1;
        } while (param_1 < *(uint*)((char*)self + 0x68));
    }
}

// 0x605f66 — observed shape
// Uploads one 16-bit texel packing 4:4:6 channels, each signed-clamped
// ([-15,15], [-15,15], [-63,63]); residuals scaled by 1/15 and 1/63.
void FUN_00605f66(void* self, uint32_t param_1, uint32_t param_2, float* param_3)
{
    if (*(int*)((char*)self + 0x54) != 0) {
        param_3 = (float*)FUN_00600136(param_3);
    }
    if (*(int*)((char*)self + 0x10) != 0) {
        param_3 = (float*)FUN_0060164a(param_3);
    }
    float local_58 = 0.0f;
    float local_54 = 0.0f;
    float local_4c = 0.0f;
    uint16_t* local_8 = (uint16_t*)(*(int*)((char*)self + 0x60) * param_1 +
                                    (*(int*)((char*)self + 0x68) + -1) * (param_1 & 1) * 2 +
                                    *(int*)((char*)self + 100) * param_2 +
                                    *(int*)((char*)self + 0x20));
    uint32_t uVar7 = param_1 & 3;
    uint32_t uVar10 = param_2 & 3;
    int iVar3 = *(int*)((char*)self + 0x34);
    int iVar11;
    int iVar14;
    uint32_t iStep;
    if ((param_1 & 1) == 0) {
        iVar11 = 0;
        iVar14 = 1;
        iStep = 1;
    } else {
        iVar11 = *(int*)((char*)self + 0x68) + -1;
        iStep = 0xffffffffu;
        iVar14 = -1;
    }
    // NEEDS_MANUAL: *(uint32_t*)((char*)self + 0x7c) = in_FPUControlWord
    if (*(int*)((char*)self + 0x5c) != 0) {
        FUN_00601966(param_3);
    }
    param_1 = 0;
    if (*(int*)((char*)self + 0x68) != 0) {
        int iVar9 = iVar14 * 0x10;
        int iVar8 = iVar11 * 0x10;
        int iVar15 = (iVar14 + iVar11) * 0x10;
        int local_c = (iVar11 - (int)iStep) * 0x10;
        param_3 = (float*)(iVar8 + 0xc + (int)(intptr_t)param_3);
        do {
            float fVar2 = *(float*)(iVar3 + (uVar10 + uVar7 * 8) * 4 + (param_1 & 3) * 4);
            float fVar4 = (local_58 + param_3[-3]) * 15.0f;
            float fVar5 = (local_54 + param_3[-2]) * 15.0f;
            float fVar6 = (local_4c + *param_3) * 63.0f;
            int local_38 = LocalRound(fVar4 + fVar2);
            uint32_t uVar16 = (uint32_t)LocalRound(fVar5 + fVar2);
            iVar11 = LocalRound(fVar6 + fVar2);
            if (*(int*)((char*)self + 0x5c) != 0) {
                float* pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x10 + local_c);
                local_58 = (fVar4 - (float)local_38) * 0.06666667f;
                *pfVar1 = local_58 * 0.1875f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x10 + iVar8);
                *pfVar1 = local_58 * 0.3125f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x10 + iVar15);
                *pfVar1 = local_58 * 0.0625f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x14 + local_c);
                local_58 = local_58 * 0.4375f;
                local_54 = (fVar5 - (float)(int)uVar16) * 0.06666667f;
                *pfVar1 = local_54 * 0.1875f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x14 + iVar8);
                *pfVar1 = local_54 * 0.3125f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x14 + iVar15);
                *pfVar1 = local_54 * 0.0625f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x1c + local_c);
                local_54 = local_54 * 0.4375f;
                local_4c = (fVar6 - (float)iVar11) * 0.015873017f;
                *pfVar1 = local_4c * 0.1875f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x1c + iVar8);
                *pfVar1 = local_4c * 0.3125f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x1c + iVar15);
                *pfVar1 = local_4c * 0.0625f + *pfVar1;
                local_4c = local_4c * 0.4375f;
            }
            int iVar13 = local_38;
            if (0xe < local_38) {
                iVar13 = 0xf;
            }
            if (iVar13 < -0xe) {
                local_38 = -0xf;
            } else if (0xe < local_38) {
                local_38 = 0xf;
            }
            uint32_t uVar12;
            if ((int)uVar16 < 0xf) {
                uVar12 = uVar16;
            } else {
                uVar12 = 0xf;
            }
            if ((int)uVar12 < -0xe) {
                uVar16 = 0xfffffff1u;
            } else if (0xe < (int)uVar16) {
                uVar16 = 0xf;
            }
            if (iVar11 < 0x3f) {
                iVar13 = iVar11;
            } else {
                iVar13 = 0x3f;
            }
            if (iVar13 < -0x3e) {
                iVar11 = -0x3f;
            } else if (0x3e < iVar11) {
                iVar11 = 0x3f;
            }
            *local_8 = (uint16_t)(((uVar16 & 0x1f | (uint32_t)(iVar11 << 5)) << 5) |
                                  ((uint16_t)local_38 & 0x1f));
            local_8 = local_8 + iVar14;
            param_3 = param_3 + iVar14 * 4;
            local_c = local_c + iVar9;
            iVar8 = iVar8 + iVar9;
            iVar15 = iVar15 + iVar9;
            param_1 = param_1 + 1;
        } while (param_1 < *(uint*)((char*)self + 0x68));
    }
}

// 0x605f03 — observed shape
// Constructor/destructor-style stub: forwards (param_1, 0x18, 1) to
// FUN_006011da and installs the vtable at PTR_FUN_006dde4c.
void FUN_00605f03(void* self, uint32_t param_1)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    FUN_006011da(param_1, 0x18, 1);
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006dde4c;
}

// 0x605f24 — observed shape
// Same shape as 0x605f03 with size 0x20 and vtable PTR_FUN_006dde5c.
void FUN_00605f24(void* self, uint32_t param_1)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    FUN_006011da(param_1, 0x20, 1);
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006dde5c;
}

// 0x605f45 — observed shape
// Same shape as 0x605f03 with size 0x20 and vtable PTR_FUN_006dde6c.
void FUN_00605f45(void* self, uint32_t param_1)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    FUN_006011da(param_1, 0x20, 1);
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006dde6c;
}

// 0x606281 — observed shape
// Size 0x10, vtable PTR_FUN_006dde7c.
void FUN_00606281(void* self, uint32_t param_1)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    FUN_006011da(param_1, 0x10, 1);
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006dde7c;
}

// 0x6062a2 — observed shape
// Size 0x10, vtable PTR_FUN_006dde8c.
void FUN_006062a2(void* self, uint32_t param_1)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    FUN_006011da(param_1, 0x10, 1);
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006dde8c;
}

// 0x6062c3 — observed shape
// Size 0x10, vtable PTR_FUN_006dde9c.
void FUN_006062c3(void* self, uint32_t param_1)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    FUN_006011da(param_1, 0x10, 1);
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006dde9c;
}

// 0x6062e4 — observed shape
// Size 0x10, vtable PTR_FUN_006ddeac.
void FUN_006062e4(void* self, uint32_t param_1)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    FUN_006011da(param_1, 0x10, 1);
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006ddeac;
}

// 0x606305 — observed shape
// Size 8, vtable PTR_FUN_006ddebc.
void FUN_00606305(void* self, uint32_t param_1)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    FUN_006011da(param_1, 8, 1);
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006ddebc;
}

// 0x606326 — observed shape
// Size 8, vtable PTR_FUN_006ddecc.
void FUN_00606326(void* self, uint32_t param_1)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    FUN_006011da(param_1, 8, 1);
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006ddecc;
}

// 0x606347 — observed shape
// Size 0x10, vtable PTR_FUN_006ddedc.
void FUN_00606347(void* self, uint32_t param_1)
{
    uint32_t* in_ECX = static_cast<uint32_t*>(self);
    FUN_006011da(param_1, 0x10, 1);
    *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006ddedc;
}
