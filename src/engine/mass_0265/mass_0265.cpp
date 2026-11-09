// Reconstruction batch mass_0265
// Target: Sid Meier's Pirates! (2004), PE32 i386
//
// Field layout observed in this batch (byte offsets from the in_ECX receiver,
// exposed here as `self`):
//   +0x00 vtable pointer, +0x08 type code (1 and 4 select the packed path),
//   +0x10 pre-transform flag, +0x14 second transform flag,
//   +0x20 destination base, +0x24..+0x30 float erase/bias key,
//   +0x34 rounding-bias table (four float factors per pixel index),
//   +0x54 pre-transform enable, +0x58 staging buffer, +0x5c quantisation-error
//   buffer, +0x60 row stride, +0x64 (100 decimal) column stride,
//   +0x68 pixel count, +0x7c stored x87 control word.
// FUN_0060151e uses the int-indexed view of the same receiver: index 6 (+0x18),
// index 8 (+0x20), index 0x0d (+0x34), 0x1a (+0x68), 0x1d (+0x74), 0x1e (+0x78)
// and the nine-dword state block at +0x24.
//
// Receiver convention: the provider reports the destination object in in_ECX;
// every definition exposes it as `void* self` and never uses `this`.
//
// Every function in this batch is one member of the pixel-format conversion
// family: it walks `+0x68` samples of the 16-byte staging array (4 floats per
// sample, +0x7c holding the x87 control word), applies the per-format dither
// bias from the +0x34 table and the quantisation error carried at +0x5c, then
// packs the clamped channels into the destination surface at +0x20.

#include <cstdint>
#include <cstddef>
#include <cmath>
#include <windows.h>

extern void* FUN_00600136(void* self, void* param_1);
extern long double FUN_0060113f(float param_1);
extern long double FUN_00601191(float param_1);
extern long double FUN_0065427e(float param_1);
extern uint8_t DAT_007192a0;

// Local ROUND: the decompiler's ROUND converts the x87 value to the nearest
// integer before the channel is clamped and packed. std::lround reproduces
// round-half-away-from-zero; the original used the rounding mode held in the
// control word captured at +0x7c.
inline int32_t LocalRound(float v) {
    return static_cast<int32_t>(std::lround(v));
}

// 0x60151e — observed shape
// Saves the draw state, points +0x0d (int index) at the static scratch block,
// re-derives the nine-dword source area at self+0x24 through FUN_00600136
// unless the type code at +0x08 is 1 or 4, then runs the two vtable callbacks
// (slots +4 and +8) over that area and restores the saved state.
void FUN_0060151e(void* self)
{
    int32_t* in_ECX = reinterpret_cast<int32_t*>(self);
    int32_t local_28[4];
    int32_t local_18 = in_ECX[6];
    int32_t local_14 = in_ECX[0x0d];
    int32_t local_10 = in_ECX[8];
    int32_t iVar1 = in_ECX[0x1d];

    in_ECX[6] = 0;
    in_ECX[0x1d] = in_ECX[0x1e];
    in_ECX[8] = static_cast<int32_t>(reinterpret_cast<intptr_t>(local_28));
    int32_t iVar2 = in_ECX[0x1a];
    in_ECX[0x1a] = 1;
    in_ECX[0x0d] = static_cast<int32_t>(reinterpret_cast<intptr_t>(&DAT_007192a0));
    if ((in_ECX[2] != 1) && (in_ECX[2] != 4)) {
        int32_t local_8 = in_ECX[0x15];
        int32_t local_c = in_ECX[0x16];
        in_ECX[0x15] = 1;
        in_ECX[0x16] = static_cast<int32_t>(reinterpret_cast<intptr_t>(in_ECX + 9));
        FUN_00600136(self, in_ECX + 9);
        in_ECX[0x15] = local_8;
        in_ECX[0x16] = local_c;
    }
    (*reinterpret_cast<void (**)(int32_t, int32_t, int32_t*)>(
        static_cast<uintptr_t>(in_ECX[0]) + 8))(0, 0, in_ECX + 9);
    (*reinterpret_cast<void (**)(int32_t, int32_t, int32_t*)>(
        static_cast<uintptr_t>(in_ECX[0]) + 4))(0, 0, in_ECX + 9);
    in_ECX[8] = local_10;
    in_ECX[0x0d] = local_14;
    in_ECX[0x1a] = iVar2;
    in_ECX[0x1d] = iVar1;
    in_ECX[6] = local_18;
}

// 0x6015d0 — observed shape
// Clears every 16-byte sample whose four floats equal the erase key held at
// self+0x24..+0x30, walking the block that starts at param_1 for +0x68 samples.
void FUN_006015d0(void* self, uint32_t param_1)
{
    uintptr_t in_ECX = reinterpret_cast<uintptr_t>(self);
    uint32_t uVar1 = static_cast<uint32_t>(
        *(int32_t*)(in_ECX + 0x68) * 0x10 + static_cast<int32_t>(param_1));
    if (param_1 < uVar1) {
        int32_t iVar2 = static_cast<int32_t>(((uVar1 - param_1) - 1) >> 4) + 1;
        float* pfVar3 = reinterpret_cast<float*>(static_cast<uintptr_t>(param_1) + 8);
        do {
            if ((((pfVar3[-2] == *(float*)(in_ECX + 0x24)) &&
                  (pfVar3[-1] == *(float*)(in_ECX + 0x28))) &&
                 (*pfVar3 == *(float*)(in_ECX + 0x2c))) &&
                (pfVar3[1] == *(float*)(in_ECX + 0x30))) {
                pfVar3[1] = 0.0f;
                *pfVar3 = 0.0f;
                pfVar3[-1] = 0.0f;
                pfVar3[-2] = 0.0f;
            }
            pfVar3 = pfVar3 + 4;
            iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
    }
}

// 0x60164a — observed shape
// Encodes the 16-byte samples of param_1 into the staging buffer at self+0x58
// and returns that buffer. With +0x14 clear the samples are encoded through
// FUN_0060113f when the type code at +0x08 is 1 or 4 (all three channels),
// otherwise only the fourth float is encoded and the first three are copied.
// With +0x14 set the already-encoded channels are scaled by FUN_0065427e.
void* FUN_0060164a(void* self, void* param_1)
{
    uintptr_t in_ECX = reinterpret_cast<uintptr_t>(self);
    intptr_t pArg = reinterpret_cast<intptr_t>(param_1);
    intptr_t dst = *(int32_t*)(in_ECX + 0x58);
    intptr_t iVar1 = 0;
    uint32_t local_8;

    if (*(int32_t*)(in_ECX + 0x14) == 0) {
        uint16_t fpuControlWord = 0;  // observed: x87 control word read here
        *(uint32_t*)(in_ECX + 0x7c) = fpuControlWord;
        if ((*(int32_t*)(in_ECX + 8) == 1) || (*(int32_t*)(in_ECX + 8) == 4)) {
            local_8 = 0;
            if (*(int32_t*)(in_ECX + 0x68) != 0) {
                float* pfSrc = reinterpret_cast<float*>(pArg + 8);
                do {
                    long double fVar4 = FUN_0060113f(pfSrc[0]);
                    *(float*)(dst + iVar1) = static_cast<float>(fVar4);
                    fVar4 = FUN_0060113f(pfSrc[1]);
                    *(float*)(dst + iVar1 + 4) = static_cast<float>(fVar4);
                    fVar4 = FUN_0060113f(pfSrc[2]);
                    local_8 = local_8 + 1;
                    *(float*)(dst + iVar1 + 8) = static_cast<float>(fVar4);
                    *reinterpret_cast<uint32_t*>(dst + iVar1 + 0xc) =
                        *reinterpret_cast<uint32_t*>(&pfSrc[3]);
                    iVar1 = iVar1 + 0x10;
                    pfSrc = pfSrc + 4;
                } while (local_8 < *reinterpret_cast<uint32_t*>(in_ECX + 0x68));
            }
        }
        else {
            local_8 = 0;
            if (*(int32_t*)(in_ECX + 0x68) != 0) {
                float* pfSrc = reinterpret_cast<float*>(pArg + 8);
                do {
                    *reinterpret_cast<uint32_t*>(dst + iVar1) =
                        *reinterpret_cast<uint32_t*>(&pfSrc[0]);
                    *reinterpret_cast<uint32_t*>(dst + iVar1 + 4) =
                        *reinterpret_cast<uint32_t*>(&pfSrc[1]);
                    *reinterpret_cast<uint32_t*>(dst + iVar1 + 8) =
                        *reinterpret_cast<uint32_t*>(&pfSrc[2]);
                    long double fVar4 = FUN_0060113f(pfSrc[3]);
                    local_8 = local_8 + 1;
                    *(float*)(dst + iVar1 + 0xc) = static_cast<float>(fVar4);
                    iVar1 = iVar1 + 0x10;
                    pfSrc = pfSrc + 4;
                } while (local_8 < *reinterpret_cast<uint32_t*>(in_ECX + 0x68));
            }
        }
    }
    else if ((*(int32_t*)(in_ECX + 8) == 1) || (*(int32_t*)(in_ECX + 8) == 4)) {
        local_8 = 0;
        if (*(int32_t*)(in_ECX + 0x68) != 0) {
            intptr_t iBase = -pArg;
            float* pfSrc = reinterpret_cast<float*>(pArg + 8);
            do {
                long double fVar4 = FUN_0065427e(pfSrc[0]);
                *(float*)(reinterpret_cast<intptr_t>(pfSrc) + dst + iBase - 8) =
                    static_cast<float>(fVar4 * static_cast<long double>(pfSrc[0]));
                fVar4 = FUN_0065427e(pfSrc[1]);
                *(float*)(reinterpret_cast<intptr_t>(pfSrc) + dst + iBase - 4) =
                    static_cast<float>(fVar4 * static_cast<long double>(pfSrc[1]));
                fVar4 = FUN_0065427e(pfSrc[2]);
                local_8 = local_8 + 1;
                *(float*)(reinterpret_cast<intptr_t>(pfSrc) + dst + iBase) =
                    static_cast<float>(fVar4 * static_cast<long double>(pfSrc[2]));
                *(float*)(reinterpret_cast<intptr_t>(pfSrc) + dst + iBase + 4) = pfSrc[3];
                pfSrc = pfSrc + 4;
            } while (local_8 < *reinterpret_cast<uint32_t*>(in_ECX + 0x68));
        }
    }
    else {
        local_8 = 0;
        if (*(int32_t*)(in_ECX + 0x68) != 0) {
            intptr_t iBase = -0xc - pArg;
            float* pfSrc = reinterpret_cast<float*>(pArg + 0xc);
            do {
                *(float*)(reinterpret_cast<intptr_t>(pfSrc) + dst + iBase) = pfSrc[-3];
                *(float*)(reinterpret_cast<intptr_t>(pfSrc) + dst + 4 + iBase) = pfSrc[-2];
                *(float*)(reinterpret_cast<intptr_t>(pfSrc) + dst + 8 + iBase) = pfSrc[-1];
                long double fVar4 = FUN_0065427e(pfSrc[0]);
                local_8 = local_8 + 1;
                *(float*)(reinterpret_cast<intptr_t>(pfSrc) + dst + 0xc + iBase) =
                    static_cast<float>(fVar4 * static_cast<long double>(pfSrc[0]));
                pfSrc = pfSrc + 4;
            } while (local_8 < *reinterpret_cast<uint32_t*>(in_ECX + 0x68));
        }
    }
    return reinterpret_cast<void*>(dst);
}

// 0x60183d — observed shape
// In-place sample transform. With +0x14 clear each channel is linearised
// through FUN_00601191 (three channels for type 1/4, only the fourth float
// otherwise); with +0x14 set each channel is squared instead.
void FUN_0060183d(void* self, uint32_t param_1)
{
    uintptr_t in_ECX = reinterpret_cast<uintptr_t>(self);
    uint32_t uVar1 = param_1;
    uint32_t uVar3 = static_cast<uint32_t>(
        *(int32_t*)(in_ECX + 0x68) * 0x10 + static_cast<int32_t>(param_1));

    if (*(int32_t*)(in_ECX + 0x14) == 0) {
        uint16_t fpuControlWord = 0;  // observed: x87 control word read here
        *(uint32_t*)(in_ECX + 0x7c) = fpuControlWord;
        if ((*(int32_t*)(in_ECX + 8) == 1) || (*(int32_t*)(in_ECX + 8) == 4)) {
            if (uVar1 < uVar3) {
                int32_t iVar4 = static_cast<int32_t>(((uVar3 - uVar1) - 1) >> 4) + 1;
                float* pfVar2 = reinterpret_cast<float*>(static_cast<uintptr_t>(uVar1) + 8);
                do {
                    long double fVar5 = FUN_00601191(pfVar2[-2]);
                    pfVar2[-2] = static_cast<float>(fVar5);
                    fVar5 = FUN_00601191(pfVar2[-1]);
                    pfVar2[-1] = static_cast<float>(fVar5);
                    fVar5 = FUN_00601191(*pfVar2);
                    *pfVar2 = static_cast<float>(fVar5);
                    pfVar2 = pfVar2 + 4;
                    iVar4 = iVar4 + -1;
                } while (iVar4 != 0);
            }
        }
        else if (uVar1 < uVar3) {
            int32_t iVar4 = static_cast<int32_t>(((uVar3 - uVar1) - 1) >> 4) + 1;
            float* pfVar2 = reinterpret_cast<float*>(static_cast<uintptr_t>(uVar1) + 0xc);
            do {
                long double fVar5 = FUN_00601191(*pfVar2);
                *pfVar2 = static_cast<float>(fVar5);
                pfVar2 = pfVar2 + 4;
                iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
        }
    }
    else if ((*(int32_t*)(in_ECX + 8) == 1) || (*(int32_t*)(in_ECX + 8) == 4)) {
        if (param_1 < uVar3) {
            float* pfVar2 = reinterpret_cast<float*>(static_cast<uintptr_t>(param_1) + 8);
            int32_t iVar4 = static_cast<int32_t>(((uVar3 - param_1) - 1) >> 4) + 1;
            do {
                pfVar2[-2] = pfVar2[-2] * pfVar2[-2];
                pfVar2[-1] = pfVar2[-1] * pfVar2[-1];
                *pfVar2 = *pfVar2 * *pfVar2;
                pfVar2 = pfVar2 + 4;
                iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
        }
    }
    else if (param_1 < uVar3) {
        float* pfVar2 = reinterpret_cast<float*>(static_cast<uintptr_t>(param_1) + 0xc);
        int32_t iVar4 = static_cast<int32_t>(((uVar3 - param_1) - 1) >> 4) + 1;
        do {
            *pfVar2 = *pfVar2 * *pfVar2;
            pfVar2 = pfVar2 + 4;
            iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
    }
}

// 0x601966 — observed shape
// Folds the error buffer at self+0x5c into the +0x68 samples starting at
// param_1, then clears that error buffer (four dwords per sample plus two).
void FUN_00601966(void* self, void* param_1)
{
    uintptr_t in_ECX = reinterpret_cast<uintptr_t>(self);
    intptr_t pArg = reinterpret_cast<intptr_t>(param_1);
    uint32_t uVar4 = 0;

    if (*(int32_t*)(in_ECX + 0x68) != 0) {
        float* pfVar2 = reinterpret_cast<float*>(pArg + 8);
        do {
            float* pfVar1 = reinterpret_cast<float*>(
                reinterpret_cast<intptr_t>(pfVar2) + *(int32_t*)(in_ECX + 0x5c) +
                (8 - pArg));
            uVar4 = uVar4 + 1;
            pfVar2[-2] = pfVar1[0] + pfVar2[-2];
            pfVar2[-1] = pfVar1[1] + pfVar2[-1];
            *pfVar2 = pfVar1[2] + *pfVar2;
            pfVar2[1] = pfVar1[3] + pfVar2[1];
            pfVar2 = pfVar2 + 4;
        } while (uVar4 < *reinterpret_cast<uint32_t*>(in_ECX + 0x68));
    }
    uint32_t* puVar5 = reinterpret_cast<uint32_t*>(
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x5c)));
    for (int32_t iVar3 = static_cast<int32_t>(
             (*reinterpret_cast<uint32_t*>(in_ECX + 0x68) + 2u & 0xfffffffu) << 2);
         iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
    }
    for (int32_t iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *reinterpret_cast<uint8_t*>(puVar5) = 0;
        puVar5 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar5) + 1);
    }
}

// 0x6019d8 — observed shape
// 24-bit BGR conversion: dither bias from the +0x34 table, three channels
// scaled by 255, quantisation error accumulated into the four planes of the
// +0x5c buffer, then clamped and written as B,G,R bytes at +0x20 with row
// stride +0x60 (three bytes per pixel).
void FUN_006019d8(void* self, uint32_t param_1, uint32_t param_2, float* param_3)
{
    uintptr_t in_ECX = reinterpret_cast<uintptr_t>(self);
    if (*(int32_t*)(in_ECX + 0x54) != 0) {
        param_3 = reinterpret_cast<float*>(FUN_00600136(self, param_3));
    }
    if (*(int32_t*)(in_ECX + 0x10) != 0) {
        param_3 = reinterpret_cast<float*>(FUN_0060164a(self, param_3));
    }
    float local_54 = 0.0f;
    float local_50 = 0.0f;
    float local_4c = 0.0f;
    uint32_t uVar9 = param_1 & 3;
    uint32_t uVar7 = param_2 & 3;
    intptr_t iVar3 = *(int32_t*)(in_ECX + 0x34);
    uint8_t* puVar16 = reinterpret_cast<uint8_t*>(
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x68) + -1) * (param_1 & 1) * 3 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x60)) * param_1 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 100)) * param_2 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x20)));
    int32_t iRow;
    int32_t iStep;
    if ((param_1 & 1) == 0) {
        iRow = 0;
        iStep = 1;
    }
    else {
        iRow = *(int32_t*)(in_ECX + 0x68) + -1;
        iStep = -1;
    }
    uint16_t fpuControlWord = 0;  // observed: x87 control word read here
    *(uint32_t*)(in_ECX + 0x7c) = fpuControlWord;
    intptr_t errBase = *(int32_t*)(in_ECX + 0x5c);
    if (errBase != 0) {
        FUN_00601966(self, param_3);
        iStep = (param_1 & 1) == 0 ? 1 : -1;
    }
    uint32_t row = 0;
    if (*(int32_t*)(in_ECX + 0x68) != 0) {
        int32_t iVar10 = iStep * 0x10;
        int32_t iVar8 = iRow * 0x10;
        int32_t iVar11 = (iStep + iRow) * 0x10;
        int32_t errOff = (iRow - iStep) * 0x10;
        float* src = reinterpret_cast<float*>(iVar8 + 8 + reinterpret_cast<intptr_t>(param_3));
        do {
            float fVar2 = *(float*)(iVar3 + (uVar7 + uVar9 * 8) * 4 + (row & 3) * 4);
            float fVar4 = (local_54 + src[-2]) * 255.0f;
            float fVar5 = (local_50 + src[-1]) * 255.0f;
            float fVar6 = (local_4c + src[0]) * 255.0f;
            int32_t red = LocalRound(fVar4 + fVar2);
            int32_t green = LocalRound(fVar5 + fVar2);
            int32_t blue = LocalRound(fVar6 + fVar2);
            if (errBase != 0) {
                float* pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + errOff);
                local_54 = (fVar4 - static_cast<float>(red)) * 0.003921569f;
                *pfVar1 = local_54 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + iVar8);
                *pfVar1 = local_54 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + iVar11);
                *pfVar1 = local_54 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + errOff);
                local_54 = local_54 * 0.4375f;
                local_50 = (fVar5 - static_cast<float>(green)) * 0.003921569f;
                *pfVar1 = local_50 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + iVar8);
                *pfVar1 = local_50 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + iVar11);
                *pfVar1 = local_50 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + errOff);
                local_50 = local_50 * 0.4375f;
                local_4c = (fVar6 - static_cast<float>(blue)) * 0.003921569f;
                *pfVar1 = local_4c * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + iVar8);
                *pfVar1 = local_4c * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + iVar11);
                *pfVar1 = local_4c * 0.0625f + *pfVar1;
                local_4c = local_4c * 0.4375f;
            }
            uint8_t blueByte = 0xff;
            int32_t clamp = red;
            if (0xfe < red) {
                clamp = 0xff;
            }
            if (clamp < 1) {
                red = 0;
            }
            else if (0xfe < red) {
                red = 0xff;
            }
            clamp = green;
            if (0xfe < green) {
                clamp = 0xff;
            }
            if (clamp < 1) {
                green = 0;
            }
            else if (0xfe < green) {
                green = 0xff;
            }
            clamp = blue;
            if (0xfe < blue) {
                clamp = 0xff;
            }
            if (clamp < 1) {
                blueByte = 0;
            }
            else if (blue < 0xff) {
                blueByte = static_cast<uint8_t>(blue);
            }
            *puVar16 = blueByte;
            puVar16[1] = static_cast<uint8_t>(green);
            puVar16[2] = static_cast<uint8_t>(red);
            src = src + iStep * 4;
            errOff = errOff + iVar10;
            puVar16 = puVar16 + iStep * 3;
            iVar8 = iVar8 + iVar10;
            iVar11 = iVar11 + iVar10;
            row = row + 1;
        } while (row < *reinterpret_cast<uint32_t*>(in_ECX + 0x68));
    }
}

// 0x601cd5 — observed shape
// 32-bit ARGB conversion: four channels scaled by 255, error distributed over
// the four planes at +0x5c (0x10/0x14/0x18/0x1c), channels clamped and packed
// as A,R,G,B into the +0x20 surface with row stride +0x60 dwords.
void FUN_00601cd5(void* self, uint32_t param_1, int32_t param_2, float* param_3)
{
    uintptr_t in_ECX = reinterpret_cast<uintptr_t>(self);
    if (*(int32_t*)(in_ECX + 0x54) != 0) {
        param_3 = reinterpret_cast<float*>(FUN_00600136(self, param_3));
    }
    if (*(int32_t*)(in_ECX + 0x10) != 0) {
        param_3 = reinterpret_cast<float*>(FUN_0060164a(self, param_3));
    }
    float local_58 = 0.0f;
    float local_54 = 0.0f;
    float local_50 = 0.0f;
    float local_4c = 0.0f;
    uint32_t* local_8 = reinterpret_cast<uint32_t*>(
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x60)) * param_1 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x68) + -1) * (param_1 & 1) * 4 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 100)) * static_cast<uintptr_t>(param_2) +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x20)));
    uint32_t uVar8 = param_1 & 3;
    uint32_t uVar12 = static_cast<uint32_t>(param_2) & 3;
    intptr_t iVar3 = *(int32_t*)(in_ECX + 0x34);
    int32_t iRow;
    int32_t iStep;
    if ((param_1 & 1) == 0) {
        iRow = 0;
        iStep = 1;
    }
    else {
        iRow = *(int32_t*)(in_ECX + 0x68) + -1;
        iStep = -1;
    }
    uint16_t fpuControlWord = 0;  // observed: x87 control word read here
    *(uint32_t*)(in_ECX + 0x7c) = fpuControlWord;
    intptr_t errBase = *(int32_t*)(in_ECX + 0x5c);
    if (errBase != 0) {
        FUN_00601966(self, param_3);
    }
    uint32_t row = 0;
    if (*(int32_t*)(in_ECX + 0x68) != 0) {
        int32_t iVar10 = iStep * 0x10;
        int32_t iVar9 = iRow * 0x10;
        float* src = reinterpret_cast<float*>(iVar9 + 8 + reinterpret_cast<intptr_t>(param_3));
        int32_t iVar11 = (iStep + iRow) * 0x10;
        int32_t errOff = (iRow - iStep) * 0x10;
        do {
            float fVar2 = *(float*)(iVar3 + (uVar12 + uVar8 * 8) * 4 + (row & 3) * 4);
            float fVar4 = (local_58 + src[-2]) * 255.0f;
            float fVar5 = (local_54 + src[-1]) * 255.0f;
            float fVar6 = (local_50 + src[0]) * 255.0f;
            float fVar7 = (local_4c + src[1]) * 255.0f;
            uint32_t red = static_cast<uint32_t>(LocalRound(fVar4 + fVar2));
            uint32_t green = static_cast<uint32_t>(LocalRound(fVar5 + fVar2));
            uint32_t blue = static_cast<uint32_t>(LocalRound(fVar6 + fVar2));
            int32_t alpha = LocalRound(fVar7 + fVar2);
            if (errBase != 0) {
                float* pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + errOff);
                local_58 = (fVar4 - static_cast<float>(static_cast<int32_t>(red))) * 0.003921569f;
                *pfVar1 = local_58 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + iVar9);
                *pfVar1 = local_58 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + iVar11);
                *pfVar1 = local_58 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + errOff);
                local_58 = local_58 * 0.4375f;
                local_54 = (fVar5 - static_cast<float>(static_cast<int32_t>(green))) * 0.003921569f;
                *pfVar1 = local_54 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + iVar9);
                *pfVar1 = local_54 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + iVar11);
                *pfVar1 = local_54 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + errOff);
                local_54 = local_54 * 0.4375f;
                local_50 = (fVar6 - static_cast<float>(static_cast<int32_t>(blue))) * 0.003921569f;
                *pfVar1 = local_50 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + iVar9);
                *pfVar1 = local_50 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + iVar11);
                *pfVar1 = local_50 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x1c + errOff);
                local_50 = local_50 * 0.4375f;
                local_4c = (fVar7 - static_cast<float>(alpha)) * 0.003921569f;
                *pfVar1 = local_4c * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x1c + iVar9);
                *pfVar1 = local_4c * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x1c + iVar11);
                *pfVar1 = local_4c * 0.0625f + *pfVar1;
                local_4c = local_4c * 0.4375f;
            }
            uint32_t clamp = red;
            if (0xfe < static_cast<int32_t>(red)) {
                clamp = 0xff;
            }
            if (static_cast<int32_t>(clamp) < 1) {
                red = 0;
            }
            else if (0xfe < static_cast<int32_t>(red)) {
                red = 0xff;
            }
            clamp = green;
            if (0xfe < static_cast<int32_t>(green)) {
                clamp = 0xff;
            }
            if (static_cast<int32_t>(clamp) < 1) {
                green = 0;
            }
            else if (0xfe < static_cast<int32_t>(green)) {
                green = 0xff;
            }
            clamp = blue;
            if (0xfe < static_cast<int32_t>(blue)) {
                clamp = 0xff;
            }
            if (static_cast<int32_t>(clamp) < 1) {
                blue = 0;
            }
            else if (0xfe < static_cast<int32_t>(blue)) {
                blue = 0xff;
            }
            int32_t clampA = alpha;
            if (0xfe < alpha) {
                clampA = 0xff;
            }
            if (clampA < 1) {
                alpha = 0;
            }
            else if (0xfe < alpha) {
                alpha = 0xff;
            }
            *local_8 = (((static_cast<uint32_t>(alpha) << 8) | red) << 8 | green) << 8 | blue;
            local_8 = local_8 + iStep;
            src = src + iStep * 4;
            iVar9 = iVar9 + iVar10;
            errOff = errOff + iVar10;
            iVar11 = iVar11 + iVar10;
            row = row + 1;
        } while (row < *reinterpret_cast<uint32_t*>(in_ECX + 0x68));
    }
}

// 0x602084 — observed shape
// 24-bit-per-channel format packed into 32 bits: three channels scaled by 255,
// error spread over the three planes at +0x5c (0x10/0x14/0x18), channels
// clamped and packed as R,G,B into a dword of the +0x20 surface.
void FUN_00602084(void* self, uint32_t param_1, uint32_t param_2, float* param_3)
{
    uintptr_t in_ECX = reinterpret_cast<uintptr_t>(self);
    if (*(int32_t*)(in_ECX + 0x54) != 0) {
        param_3 = reinterpret_cast<float*>(FUN_00600136(self, param_3));
    }
    if (*(int32_t*)(in_ECX + 0x10) != 0) {
        param_3 = reinterpret_cast<float*>(FUN_0060164a(self, param_3));
    }
    float local_54 = 0.0f;
    float local_50 = 0.0f;
    float local_4c = 0.0f;
    uint32_t uVar7 = param_1 & 3;
    uint32_t* local_8 = reinterpret_cast<uint32_t*>(
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x60)) * param_1 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x68) + -1) * (param_1 & 1) * 4 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 100)) * param_2 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x20)));
    intptr_t iVar3 = *(int32_t*)(in_ECX + 0x34);
    int32_t iRow;
    int32_t iStep;
    if ((param_1 & 1) == 0) {
        iRow = 0;
        iStep = 1;
    }
    else {
        iRow = *(int32_t*)(in_ECX + 0x68) + -1;
        iStep = -1;
    }
    uint16_t fpuControlWord = 0;  // observed: x87 control word read here
    *(uint32_t*)(in_ECX + 0x7c) = fpuControlWord;
    intptr_t errBase = *(int32_t*)(in_ECX + 0x5c);
    if (errBase != 0) {
        FUN_00601966(self, param_3);
    }
    uint32_t row = 0;
    if (*(int32_t*)(in_ECX + 0x68) != 0) {
        int32_t iVar9 = iStep * 0x10;
        int32_t iVar8 = iRow * 0x10;
        int32_t iVar10 = (iStep + iRow) * 0x10;
        int32_t errOff = (iRow - iStep) * 0x10;
        float* src = reinterpret_cast<float*>(iVar8 + 8 + reinterpret_cast<intptr_t>(param_3));
        do {
            float fVar2 = *(float*)(iVar3 + ((param_2 & 3) + uVar7 * 8) * 4 + (row & 3) * 4);
            float fVar4 = (local_54 + src[-2]) * 255.0f;
            float fVar5 = (local_50 + src[-1]) * 255.0f;
            float fVar6 = (local_4c + src[0]) * 255.0f;
            int32_t red = LocalRound(fVar4 + fVar2);
            uint32_t green = static_cast<uint32_t>(LocalRound(fVar5 + fVar2));
            uint32_t blue = static_cast<uint32_t>(LocalRound(fVar6 + fVar2));
            if (errBase != 0) {
                float* pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + errOff);
                local_54 = (fVar4 - static_cast<float>(red)) * 0.003921569f;
                *pfVar1 = local_54 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + iVar8);
                *pfVar1 = local_54 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + iVar10);
                *pfVar1 = local_54 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + errOff);
                local_54 = local_54 * 0.4375f;
                local_50 = (fVar5 - static_cast<float>(static_cast<int32_t>(green))) * 0.003921569f;
                *pfVar1 = local_50 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + iVar8);
                *pfVar1 = local_50 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + iVar10);
                *pfVar1 = local_50 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + errOff);
                local_50 = local_50 * 0.4375f;
                local_4c = (fVar6 - static_cast<float>(static_cast<int32_t>(blue))) * 0.003921569f;
                *pfVar1 = local_4c * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + iVar8);
                *pfVar1 = local_4c * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + iVar10);
                *pfVar1 = local_4c * 0.0625f + *pfVar1;
                local_4c = local_4c * 0.4375f;
            }
            int32_t clamp = red;
            if (0xfe < red) {
                clamp = 0xff;
            }
            if (clamp < 1) {
                red = 0;
            }
            else if (0xfe < red) {
                red = 0xff;
            }
            uint32_t clampU = green;
            if (0xfe < static_cast<int32_t>(green)) {
                clampU = 0xff;
            }
            if (static_cast<int32_t>(clampU) < 1) {
                green = 0;
            }
            else if (0xfe < static_cast<int32_t>(green)) {
                green = 0xff;
            }
            clampU = blue;
            if (0xfe < static_cast<int32_t>(blue)) {
                clampU = 0xff;
            }
            if (static_cast<int32_t>(clampU) < 1) {
                blue = 0;
            }
            else if (0xfe < static_cast<int32_t>(blue)) {
                blue = 0xff;
            }
            *local_8 = (static_cast<uint32_t>(red) << 8 | green) << 8 | blue;
            local_8 = local_8 + iStep;
            src = src + iStep * 4;
            iVar8 = iVar8 + iVar9;
            errOff = errOff + iVar9;
            iVar10 = iVar10 + iVar9;
            row = row + 1;
        } while (row < *reinterpret_cast<uint32_t*>(in_ECX + 0x68));
    }
}

// 0x60239a — observed shape
// 16-bit 5-6-5 conversion: red and blue scaled by 31, green by 63, error
// spread over the three planes at +0x5c, channels clamped to 5/6/5 bits and
// packed as 5-6-5 into a word of the +0x20 surface.
void FUN_0060239a(void* self, uint32_t param_1, uint32_t param_2, float* param_3)
{
    uintptr_t in_ECX = reinterpret_cast<uintptr_t>(self);
    if (*(int32_t*)(in_ECX + 0x54) != 0) {
        param_3 = reinterpret_cast<float*>(FUN_00600136(self, param_3));
    }
    if (*(int32_t*)(in_ECX + 0x10) != 0) {
        param_3 = reinterpret_cast<float*>(FUN_0060164a(self, param_3));
    }
    float local_54 = 0.0f;
    float local_50 = 0.0f;
    float local_4c = 0.0f;
    uint32_t uVar7 = param_1 & 3;
    uint16_t* local_8 = reinterpret_cast<uint16_t*>(
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x60)) * param_1 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x68) + -1) * (param_1 & 1) * 2 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 100)) * param_2 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x20)));
    intptr_t iVar3 = *(int32_t*)(in_ECX + 0x34);
    int32_t iRow;
    int32_t iStep;
    if ((param_1 & 1) == 0) {
        iRow = 0;
        iStep = 1;
    }
    else {
        iRow = *(int32_t*)(in_ECX + 0x68) + -1;
        iStep = -1;
    }
    uint16_t fpuControlWord = 0;  // observed: x87 control word read here
    *(uint32_t*)(in_ECX + 0x7c) = fpuControlWord;
    intptr_t errBase = *(int32_t*)(in_ECX + 0x5c);
    if (errBase != 0) {
        FUN_00601966(self, param_3);
    }
    uint32_t row = 0;
    if (*(int32_t*)(in_ECX + 0x68) != 0) {
        int32_t iVar9 = iStep * 0x10;
        int32_t iVar8 = iRow * 0x10;
        int32_t iVar10 = (iStep + iRow) * 0x10;
        int32_t errOff = (iRow - iStep) * 0x10;
        float* src = reinterpret_cast<float*>(iVar8 + 8 + reinterpret_cast<intptr_t>(param_3));
        do {
            float fVar2 = *(float*)(iVar3 + ((param_2 & 3) + uVar7 * 8) * 4 + (row & 3) * 4);
            float fVar4 = (local_54 + src[-2]) * 31.0f;
            float fVar5 = (local_50 + src[-1]) * 63.0f;
            float fVar6 = (local_4c + src[0]) * 31.0f;
            int32_t red = LocalRound(fVar4 + fVar2);
            uint32_t green = static_cast<uint32_t>(LocalRound(fVar5 + fVar2));
            int32_t blue = LocalRound(fVar6 + fVar2);
            if (errBase != 0) {
                float* pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + errOff);
                local_54 = (fVar4 - static_cast<float>(red)) * 0.032258064f;
                *pfVar1 = local_54 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + iVar8);
                *pfVar1 = local_54 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + iVar10);
                *pfVar1 = local_54 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + errOff);
                local_54 = local_54 * 0.4375f;
                local_50 = (fVar5 - static_cast<float>(static_cast<int32_t>(green))) * 0.015873017f;
                *pfVar1 = local_50 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + iVar8);
                *pfVar1 = local_50 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + iVar10);
                *pfVar1 = local_50 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + errOff);
                local_50 = local_50 * 0.4375f;
                local_4c = (fVar6 - static_cast<float>(blue)) * 0.032258064f;
                *pfVar1 = local_4c * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + iVar8);
                *pfVar1 = local_4c * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + iVar10);
                *pfVar1 = local_4c * 0.0625f + *pfVar1;
                local_4c = local_4c * 0.4375f;
            }
            int32_t clamp = red;
            if (red < 0x1f) {
                clamp = red;
            }
            else {
                clamp = 0x1f;
            }
            if (clamp < 1) {
                red = 0;
            }
            else if (0x1e < red) {
                red = 0x1f;
            }
            uint32_t clampU = green;
            if (0x3e < static_cast<int32_t>(green)) {
                clampU = 0x3f;
            }
            if (static_cast<int32_t>(clampU) < 1) {
                green = 0;
            }
            else if (0x3e < static_cast<int32_t>(green)) {
                green = 0x3f;
            }
            clamp = blue;
            if (0x1e < blue) {
                clamp = 0x1f;
            }
            if (clamp < 1) {
                blue = 0;
            }
            else if (0x1e < blue) {
                blue = 0x1f;
            }
            *local_8 = static_cast<uint16_t>(
                static_cast<uint16_t>((static_cast<uint32_t>(red) << 6 | green) << 5)) |
                static_cast<uint16_t>(blue);
            local_8 = local_8 + iStep;
            src = src + iStep * 4;
            iVar8 = iVar8 + iVar9;
            errOff = errOff + iVar9;
            iVar10 = iVar10 + iVar9;
            row = row + 1;
        } while (row < *reinterpret_cast<uint32_t*>(in_ECX + 0x68));
    }
}

// 0x60269d — observed shape
// 16-bit 5-5-5 conversion: all three channels scaled by 31, error spread over
// the three planes at +0x5c, channels clamped to five bits each and packed as
// 5-5-5 into a word of the +0x20 surface.
void FUN_0060269d(void* self, uint32_t param_1, uint32_t param_2, float* param_3)
{
    uintptr_t in_ECX = reinterpret_cast<uintptr_t>(self);
    if (*(int32_t*)(in_ECX + 0x54) != 0) {
        param_3 = reinterpret_cast<float*>(FUN_00600136(self, param_3));
    }
    if (*(int32_t*)(in_ECX + 0x10) != 0) {
        param_3 = reinterpret_cast<float*>(FUN_0060164a(self, param_3));
    }
    float local_54 = 0.0f;
    float local_50 = 0.0f;
    float local_4c = 0.0f;
    uint32_t uVar7 = param_1 & 3;
    uint16_t* local_8 = reinterpret_cast<uint16_t*>(
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x60)) * param_1 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x68) + -1) * (param_1 & 1) * 2 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 100)) * param_2 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x20)));
    intptr_t iVar3 = *(int32_t*)(in_ECX + 0x34);
    int32_t iRow;
    int32_t iStep;
    if ((param_1 & 1) == 0) {
        iRow = 0;
        iStep = 1;
    }
    else {
        iRow = *(int32_t*)(in_ECX + 0x68) + -1;
        iStep = -1;
    }
    uint16_t fpuControlWord = 0;  // observed: x87 control word read here
    *(uint32_t*)(in_ECX + 0x7c) = fpuControlWord;
    intptr_t errBase = *(int32_t*)(in_ECX + 0x5c);
    if (errBase != 0) {
        FUN_00601966(self, param_3);
    }
    uint32_t row = 0;
    if (*(int32_t*)(in_ECX + 0x68) != 0) {
        int32_t iVar9 = iStep * 0x10;
        int32_t iVar8 = iRow * 0x10;
        int32_t iVar10 = (iStep + iRow) * 0x10;
        int32_t errOff = (iRow - iStep) * 0x10;
        float* src = reinterpret_cast<float*>(iVar8 + 8 + reinterpret_cast<intptr_t>(param_3));
        do {
            float fVar2 = *(float*)(iVar3 + ((param_2 & 3) + uVar7 * 8) * 4 + (row & 3) * 4);
            float fVar4 = (local_54 + src[-2]) * 31.0f;
            float fVar5 = (local_50 + src[-1]) * 31.0f;
            float fVar6 = (local_4c + src[0]) * 31.0f;
            int32_t red = LocalRound(fVar4 + fVar2);
            uint32_t green = static_cast<uint32_t>(LocalRound(fVar5 + fVar2));
            int32_t blue = LocalRound(fVar6 + fVar2);
            if (errBase != 0) {
                float* pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + errOff);
                local_54 = (fVar4 - static_cast<float>(red)) * 0.032258064f;
                *pfVar1 = local_54 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + iVar8);
                *pfVar1 = local_54 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + iVar10);
                *pfVar1 = local_54 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + errOff);
                local_54 = local_54 * 0.4375f;
                local_50 = (fVar5 - static_cast<float>(static_cast<int32_t>(green))) * 0.032258064f;
                *pfVar1 = local_50 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + iVar8);
                *pfVar1 = local_50 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + iVar10);
                *pfVar1 = local_50 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + errOff);
                local_50 = local_50 * 0.4375f;
                local_4c = (fVar6 - static_cast<float>(blue)) * 0.032258064f;
                *pfVar1 = local_4c * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + iVar8);
                *pfVar1 = local_4c * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + iVar10);
                *pfVar1 = local_4c * 0.0625f + *pfVar1;
                local_4c = local_4c * 0.4375f;
            }
            int32_t clamp = red;
            if (red < 0x1f) {
                clamp = red;
            }
            else {
                clamp = 0x1f;
            }
            if (clamp < 1) {
                red = 0;
            }
            else if (0x1e < red) {
                red = 0x1f;
            }
            uint32_t clampU = green;
            if (0x1e < static_cast<int32_t>(green)) {
                clampU = 0x1f;
            }
            if (static_cast<int32_t>(clampU) < 1) {
                green = 0;
            }
            else if (0x1e < static_cast<int32_t>(green)) {
                green = 0x1f;
            }
            clamp = blue;
            if (0x1e < blue) {
                clamp = 0x1f;
            }
            if (clamp < 1) {
                blue = 0;
            }
            else if (0x1e < blue) {
                blue = 0x1f;
            }
            *local_8 = static_cast<uint16_t>(
                static_cast<uint16_t>((static_cast<uint32_t>(red) << 5 | green) << 5)) |
                static_cast<uint16_t>(blue);
            local_8 = local_8 + iStep;
            src = src + iStep * 4;
            iVar8 = iVar8 + iVar9;
            errOff = errOff + iVar9;
            iVar10 = iVar10 + iVar9;
            row = row + 1;
        } while (row < *reinterpret_cast<uint32_t*>(in_ECX + 0x68));
    }
}

// 0x60299c — observed shape
// 16-bit ARGB1555 conversion: three colour channels scaled by 31, alpha taken
// straight from the fourth float (1-bit), error spread over the four planes at
// +0x5c, channels clamped and packed as A,R,G,B (5-5-5-1).
void FUN_0060299c(void* self, uint32_t param_1, int32_t param_2, float* param_3)
{
    uintptr_t in_ECX = reinterpret_cast<uintptr_t>(self);
    if (*(int32_t*)(in_ECX + 0x54) != 0) {
        param_3 = reinterpret_cast<float*>(FUN_00600136(self, param_3));
    }
    if (*(int32_t*)(in_ECX + 0x10) != 0) {
        param_3 = reinterpret_cast<float*>(FUN_0060164a(self, param_3));
    }
    float local_58 = 0.0f;
    float local_54 = 0.0f;
    float local_50 = 0.0f;
    float local_4c = 0.0f;
    uint16_t* local_8 = reinterpret_cast<uint16_t*>(
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x60)) * param_1 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x68) + -1) * (param_1 & 1) * 2 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 100)) * static_cast<uintptr_t>(param_2) +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x20)));
    uint32_t uVar8 = param_1 & 3;
    uint32_t uVar12 = static_cast<uint32_t>(param_2) & 3;
    intptr_t iVar4 = *(int32_t*)(in_ECX + 0x34);
    int32_t iRow;
    int32_t iStep;
    if ((param_1 & 1) == 0) {
        iRow = 0;
        iStep = 1;
    }
    else {
        iRow = *(int32_t*)(in_ECX + 0x68) + -1;
        iStep = -1;
    }
    uint16_t fpuControlWord = 0;  // observed: x87 control word read here
    *(uint32_t*)(in_ECX + 0x7c) = fpuControlWord;
    intptr_t errBase = *(int32_t*)(in_ECX + 0x5c);
    if (errBase != 0) {
        FUN_00601966(self, param_3);
    }
    uint32_t row = 0;
    if (*(int32_t*)(in_ECX + 0x68) != 0) {
        int32_t iVar10 = iStep * 0x10;
        int32_t iVar9 = iRow * 0x10;
        float* src = reinterpret_cast<float*>(iVar9 + 8 + reinterpret_cast<intptr_t>(param_3));
        int32_t iVar11 = (iStep + iRow) * 0x10;
        int32_t errOff = (iRow - iStep) * 0x10;
        do {
            float fVar2 = *(float*)(iVar4 + (uVar12 + uVar8 * 8) * 4 + (row & 3) * 4);
            float fVar5 = (local_58 + src[-2]) * 31.0f;
            float fVar6 = (local_54 + src[-1]) * 31.0f;
            float fVar7 = (local_50 + src[0]) * 31.0f;
            float fVar3 = src[1];
            uint32_t red = static_cast<uint32_t>(LocalRound(fVar5 + fVar2));
            uint32_t green = static_cast<uint32_t>(LocalRound(fVar6 + fVar2));
            int32_t blue = LocalRound(fVar7 + fVar2);
            int32_t alpha = LocalRound(local_4c + fVar3 + fVar2);
            if (errBase != 0) {
                float* pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + errOff);
                local_58 = (fVar5 - static_cast<float>(static_cast<int32_t>(red))) * 0.032258064f;
                *pfVar1 = local_58 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + iVar9);
                *pfVar1 = local_58 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + iVar11);
                *pfVar1 = local_58 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + errOff);
                local_58 = local_58 * 0.4375f;
                local_54 = (fVar6 - static_cast<float>(static_cast<int32_t>(green))) * 0.032258064f;
                *pfVar1 = local_54 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + iVar9);
                *pfVar1 = local_54 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + iVar11);
                *pfVar1 = local_54 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + errOff);
                local_54 = local_54 * 0.4375f;
                local_50 = (fVar7 - static_cast<float>(blue)) * 0.032258064f;
                *pfVar1 = local_50 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + iVar9);
                *pfVar1 = local_50 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + iVar11);
                *pfVar1 = local_50 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x1c + errOff);
                local_50 = local_50 * 0.4375f;
                local_4c = (local_4c + fVar3) - static_cast<float>(alpha);
                *pfVar1 = local_4c * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x1c + iVar9);
                *pfVar1 = local_4c * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x1c + iVar11);
                *pfVar1 = local_4c * 0.0625f + *pfVar1;
                local_4c = local_4c * 0.4375f;
            }
            uint32_t clampU = red;
            if (0x1e < static_cast<int32_t>(red)) {
                clampU = 0x1f;
            }
            if (static_cast<int32_t>(clampU) < 1) {
                red = 0;
            }
            else if (0x1e < static_cast<int32_t>(red)) {
                red = 0x1f;
            }
            clampU = green;
            if (0x1e < static_cast<int32_t>(green)) {
                clampU = 0x1f;
            }
            if (static_cast<int32_t>(clampU) < 1) {
                green = 0;
            }
            else if (0x1e < static_cast<int32_t>(green)) {
                green = 0x1f;
            }
            int32_t clamp = blue;
            if (0x1e < blue) {
                clamp = 0x1f;
            }
            if (clamp < 1) {
                blue = 0;
            }
            else if (0x1e < blue) {
                blue = 0x1f;
            }
            int32_t clampA = alpha;
            if (alpha < 1) {
                clampA = alpha;
            }
            else {
                clampA = 1;
            }
            if (clampA < 1) {
                alpha = 0;
            }
            else if (0 < alpha) {
                alpha = 1;
            }
            *local_8 = static_cast<uint16_t>(
                static_cast<uint16_t>(
                    ((static_cast<uint32_t>(alpha) << 5 | red) << 5 | green) << 5)) |
                static_cast<uint16_t>(blue);
            local_8 = local_8 + iStep;
            src = src + iStep * 4;
            iVar9 = iVar9 + iVar10;
            errOff = errOff + iVar10;
            iVar11 = iVar11 + iVar10;
            row = row + 1;
        } while (row < *reinterpret_cast<uint32_t*>(in_ECX + 0x68));
    }
}

// 0x602d2c — observed shape
// 16-bit ARGB4444 conversion: all four channels scaled by 15, error spread over
// the four planes at +0x5c, channels clamped to four bits and packed as
// A,R,G,B nibbles.
void FUN_00602d2c(void* self, uint32_t param_1, int32_t param_2, float* param_3)
{
    uintptr_t in_ECX = reinterpret_cast<uintptr_t>(self);
    if (*(int32_t*)(in_ECX + 0x54) != 0) {
        param_3 = reinterpret_cast<float*>(FUN_00600136(self, param_3));
    }
    if (*(int32_t*)(in_ECX + 0x10) != 0) {
        param_3 = reinterpret_cast<float*>(FUN_0060164a(self, param_3));
    }
    float local_58 = 0.0f;
    float local_54 = 0.0f;
    float local_50 = 0.0f;
    float local_4c = 0.0f;
    uint16_t* local_8 = reinterpret_cast<uint16_t*>(
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x60)) * param_1 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x68) + -1) * (param_1 & 1) * 2 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 100)) * static_cast<uintptr_t>(param_2) +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x20)));
    uint32_t uVar8 = param_1 & 3;
    uint32_t uVar12 = static_cast<uint32_t>(param_2) & 3;
    intptr_t iVar3 = *(int32_t*)(in_ECX + 0x34);
    int32_t iRow;
    int32_t iStep;
    if ((param_1 & 1) == 0) {
        iRow = 0;
        iStep = 1;
    }
    else {
        iRow = *(int32_t*)(in_ECX + 0x68) + -1;
        iStep = -1;
    }
    uint16_t fpuControlWord = 0;  // observed: x87 control word read here
    *(uint32_t*)(in_ECX + 0x7c) = fpuControlWord;
    intptr_t errBase = *(int32_t*)(in_ECX + 0x5c);
    if (errBase != 0) {
        FUN_00601966(self, param_3);
    }
    uint32_t row = 0;
    if (*(int32_t*)(in_ECX + 0x68) != 0) {
        int32_t iVar10 = iStep * 0x10;
        int32_t iVar9 = iRow * 0x10;
        float* src = reinterpret_cast<float*>(iVar9 + 8 + reinterpret_cast<intptr_t>(param_3));
        int32_t iVar11 = (iStep + iRow) * 0x10;
        int32_t errOff = (iRow - iStep) * 0x10;
        do {
            float fVar2 = *(float*)(iVar3 + (uVar12 + uVar8 * 8) * 4 + (row & 3) * 4);
            float fVar4 = (local_58 + src[-2]) * 15.0f;
            float fVar5 = (local_54 + src[-1]) * 15.0f;
            float fVar6 = (local_50 + src[0]) * 15.0f;
            float fVar7 = (local_4c + src[1]) * 15.0f;
            uint32_t red = static_cast<uint32_t>(LocalRound(fVar4 + fVar2));
            uint32_t green = static_cast<uint32_t>(LocalRound(fVar5 + fVar2));
            int32_t blue = LocalRound(fVar6 + fVar2);
            int32_t alpha = LocalRound(fVar7 + fVar2);
            if (errBase != 0) {
                float* pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + errOff);
                local_58 = (fVar4 - static_cast<float>(static_cast<int32_t>(red))) * 0.06666667f;
                *pfVar1 = local_58 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + iVar9);
                *pfVar1 = local_58 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + iVar11);
                *pfVar1 = local_58 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + errOff);
                local_58 = local_58 * 0.4375f;
                local_54 = (fVar5 - static_cast<float>(static_cast<int32_t>(green))) * 0.06666667f;
                *pfVar1 = local_54 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + iVar9);
                *pfVar1 = local_54 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + iVar11);
                *pfVar1 = local_54 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + errOff);
                local_54 = local_54 * 0.4375f;
                local_50 = (fVar6 - static_cast<float>(blue)) * 0.06666667f;
                *pfVar1 = local_50 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + iVar9);
                *pfVar1 = local_50 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + iVar11);
                *pfVar1 = local_50 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x1c + errOff);
                local_50 = local_50 * 0.4375f;
                local_4c = (fVar7 - static_cast<float>(alpha)) * 0.06666667f;
                *pfVar1 = local_4c * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x1c + iVar9);
                *pfVar1 = local_4c * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x1c + iVar11);
                *pfVar1 = local_4c * 0.0625f + *pfVar1;
                local_4c = local_4c * 0.4375f;
            }
            uint32_t clampU = red;
            if (0xe < static_cast<int32_t>(red)) {
                clampU = 0xf;
            }
            if (static_cast<int32_t>(clampU) < 1) {
                red = 0;
            }
            else if (0xe < static_cast<int32_t>(red)) {
                red = 0xf;
            }
            clampU = green;
            if (0xe < static_cast<int32_t>(green)) {
                clampU = 0xf;
            }
            if (static_cast<int32_t>(clampU) < 1) {
                green = 0;
            }
            else if (0xe < static_cast<int32_t>(green)) {
                green = 0xf;
            }
            int32_t clamp = blue;
            if (0xe < blue) {
                clamp = 0xf;
            }
            if (clamp < 1) {
                blue = 0;
            }
            else if (0xe < blue) {
                blue = 0xf;
            }
            clamp = alpha;
            if (alpha < 0xf) {
                clamp = alpha;
            }
            else {
                clamp = 0xf;
            }
            if (clamp < 1) {
                alpha = 0;
            }
            else if (0xe < alpha) {
                alpha = 0xf;
            }
            *local_8 = static_cast<uint16_t>(
                static_cast<uint16_t>(
                    ((static_cast<uint32_t>(alpha) << 4 | red) << 4 | green) << 4)) |
                static_cast<uint16_t>(blue);
            local_8 = local_8 + iStep;
            src = src + iStep * 4;
            iVar9 = iVar9 + iVar10;
            errOff = errOff + iVar10;
            iVar11 = iVar11 + iVar10;
            row = row + 1;
        } while (row < *reinterpret_cast<uint32_t*>(in_ECX + 0x68));
    }
}

// 0x6030bc — observed shape
// 8-bit 3-3-2 conversion: red and green scaled by 7, blue by 3, error spread
// over the three planes at +0x5c, channels clamped to 3/3/2 bits and packed
// into one byte per pixel.
void FUN_006030bc(void* self, uint32_t param_1, uint32_t param_2, float* param_3)
{
    uintptr_t in_ECX = reinterpret_cast<uintptr_t>(self);
    if (*(int32_t*)(in_ECX + 0x54) != 0) {
        param_3 = reinterpret_cast<float*>(FUN_00600136(self, param_3));
    }
    if (*(int32_t*)(in_ECX + 0x10) != 0) {
        param_3 = reinterpret_cast<float*>(FUN_0060164a(self, param_3));
    }
    float local_58 = 0.0f;
    float local_54 = 0.0f;
    float local_50 = 0.0f;
    uint32_t uVar7 = param_1 & 3;
    uint32_t uVar9 = param_2 & 3;
    uint8_t* local_10 = reinterpret_cast<uint8_t*>(
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x68) + -1) * (param_1 & 1) +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x60)) * param_1 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 100)) * param_2 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x20)));
    intptr_t iVar3 = *(int32_t*)(in_ECX + 0x34);
    int32_t iRow;
    int32_t iStep;
    if ((param_1 & 1) == 0) {
        iRow = 0;
        iStep = 1;
    }
    else {
        iRow = *(int32_t*)(in_ECX + 0x68) + -1;
        iStep = -1;
    }
    uint16_t fpuControlWord = 0;  // observed: x87 control word read here
    *(uint32_t*)(in_ECX + 0x7c) = fpuControlWord;
    intptr_t errBase = *(int32_t*)(in_ECX + 0x5c);
    if (errBase != 0) {
        FUN_00601966(self, param_3);
    }
    uint32_t row = 0;
    if (*(int32_t*)(in_ECX + 0x68) != 0) {
        int32_t iVar10 = iStep * 0x10;
        int32_t iVar8 = iRow * 0x10;
        int32_t iVar13 = (iStep + iRow) * 0x10;
        int32_t errOff = (iRow - iStep) * 0x10;
        float* src = reinterpret_cast<float*>(iVar8 + 8 + reinterpret_cast<intptr_t>(param_3));
        do {
            float fVar2 = *(float*)(iVar3 + (uVar9 + uVar7 * 8) * 4 + (row & 3) * 4);
            float fVar4 = (local_58 + src[-2]) * 7.0f;
            float fVar5 = (local_54 + src[-1]) * 7.0f;
            float fVar6 = (local_50 + src[0]) * 3.0f;
            int32_t red = LocalRound(fVar4 + fVar2);
            int32_t green = LocalRound(fVar5 + fVar2);
            int32_t blue = LocalRound(fVar6 + fVar2);
            if (errBase != 0) {
                float* pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + errOff);
                local_58 = (fVar4 - static_cast<float>(red)) * 0.14285715f;
                *pfVar1 = local_58 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + iVar8);
                *pfVar1 = local_58 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + iVar13);
                *pfVar1 = local_58 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + errOff);
                local_58 = local_58 * 0.4375f;
                local_54 = (fVar5 - static_cast<float>(green)) * 0.14285715f;
                *pfVar1 = local_54 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + iVar8);
                *pfVar1 = local_54 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + iVar13);
                *pfVar1 = local_54 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + errOff);
                local_54 = local_54 * 0.4375f;
                local_50 = (fVar6 - static_cast<float>(blue)) * 0.33333334f;
                *pfVar1 = local_50 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + iVar8);
                *pfVar1 = local_50 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + iVar13);
                *pfVar1 = local_50 * 0.0625f + *pfVar1;
                local_50 = local_50 * 0.4375f;
            }
            int32_t clamp = red;
            if (red < 7) {
                clamp = red;
            }
            else {
                clamp = 7;
            }
            if (clamp < 1) {
                red = 0;
            }
            else if (6 < red) {
                red = 7;
            }
            clamp = green;
            if (green < 7) {
                clamp = green;
            }
            else {
                clamp = 7;
            }
            if (clamp < 1) {
                green = 0;
            }
            else if (6 < green) {
                green = 7;
            }
            clamp = blue;
            if (blue < 3) {
                clamp = blue;
            }
            else {
                clamp = 3;
            }
            if (clamp < 1) {
                blue = 0;
            }
            else if (2 < blue) {
                blue = 3;
            }
            *local_10 = static_cast<uint8_t>(
                static_cast<uint8_t>(
                    (static_cast<uint8_t>(red) << 3) | static_cast<uint8_t>(green)) << 2) |
                static_cast<uint8_t>(blue);
            local_10 = local_10 + iStep;
            src = src + iStep * 4;
            errOff = errOff + iVar10;
            iVar8 = iVar8 + iVar10;
            iVar13 = iVar13 + iVar10;
            row = row + 1;
        } while (row < *reinterpret_cast<uint32_t*>(in_ECX + 0x68));
    }
}

// 0x6033d1 — observed shape
// 8-bit grey conversion: the fourth float of each sample is scaled by 255,
// its quantisation error accumulated into the +0x1c plane of the +0x5c buffer,
// clamped to a byte and written to the +0x20 surface.
void FUN_006033d1(void* self, uint32_t param_1, uint32_t param_2, float* param_3)
{
    uintptr_t in_ECX = reinterpret_cast<uintptr_t>(self);
    if (*(int32_t*)(in_ECX + 0x54) != 0) {
        param_3 = reinterpret_cast<float*>(FUN_00600136(self, param_3));
    }
    if (*(int32_t*)(in_ECX + 0x10) != 0) {
        param_3 = reinterpret_cast<float*>(FUN_0060164a(self, param_3));
    }
    float local_2c = 0.0f;
    uint32_t uVar4 = param_1 & 3;
    uint32_t uVar6 = param_2 & 3;
    intptr_t iVar2 = *(int32_t*)(in_ECX + 0x34);
    uint8_t* puVar11 = reinterpret_cast<uint8_t*>(
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x68) + -1) * (param_1 & 1) +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x60)) * param_1 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 100)) * param_2 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x20)));
    int32_t iRow;
    int32_t iStep;
    if ((param_1 & 1) == 0) {
        iRow = 0;
        iStep = 1;
    }
    else {
        iRow = *(int32_t*)(in_ECX + 0x68) + -1;
        iStep = -1;
    }
    uint16_t fpuControlWord = 0;  // observed: x87 control word read here
    *(uint32_t*)(in_ECX + 0x7c) = fpuControlWord;
    intptr_t errBase = *(int32_t*)(in_ECX + 0x5c);
    if (errBase != 0) {
        FUN_00601966(self, param_3);
    }
    uint32_t row = 0;
    if (*(int32_t*)(in_ECX + 0x68) != 0) {
        int32_t iVar7 = iStep * 0x10;
        int32_t iVar5 = iRow * 0x10;
        int32_t iVar8 = (iStep + iRow) * 0x10;
        int32_t errOff = (iRow - iStep) * 0x10;
        float* src = reinterpret_cast<float*>(iVar5 + 0xc + reinterpret_cast<intptr_t>(param_3));
        do {
            float fVar3 = (local_2c + *src) * 255.0f;
            int32_t gray = LocalRound(fVar3 + *(float*)(iVar2 + (uVar6 + uVar4 * 8) * 4 + (row & 3) * 4));
            if (errBase != 0) {
                float* pfVar1 = reinterpret_cast<float*>(errBase + 0x1c + errOff);
                local_2c = (fVar3 - static_cast<float>(gray)) * 0.003921569f;
                *pfVar1 = local_2c * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x1c + iVar5);
                *pfVar1 = local_2c * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x1c + iVar8);
                *pfVar1 = local_2c * 0.0625f + *pfVar1;
                local_2c = local_2c * 0.4375f;
            }
            int32_t clamp = gray;
            if (0xfe < gray) {
                clamp = 0xff;
            }
            if (clamp < 1) {
                gray = 0;
            }
            else if (0xfe < gray) {
                gray = 0xff;
            }
            *puVar11 = static_cast<uint8_t>(gray);
            src = src + iStep * 4;
            errOff = errOff + iVar7;
            puVar11 = puVar11 + iStep;
            iVar5 = iVar5 + iVar7;
            iVar8 = iVar8 + iVar7;
            row = row + 1;
        } while (row < *reinterpret_cast<uint32_t*>(in_ECX + 0x68));
    }
}

// 0x603592 — observed shape
// 16-bit ARGB2332 conversion: red and green scaled by 7, blue by 3 and alpha
// by 255, error spread over the four planes at +0x5c, channels clamped and
// packed as A,R,G,B (3-3-2 plus 8-bit alpha) into a word.
void FUN_00603592(void* self, uint32_t param_1, int32_t param_2, float* param_3)
{
    uintptr_t in_ECX = reinterpret_cast<uintptr_t>(self);
    if (*(int32_t*)(in_ECX + 0x54) != 0) {
        param_3 = reinterpret_cast<float*>(FUN_00600136(self, param_3));
    }
    if (*(int32_t*)(in_ECX + 0x10) != 0) {
        param_3 = reinterpret_cast<float*>(FUN_0060164a(self, param_3));
    }
    float local_58 = 0.0f;
    float local_54 = 0.0f;
    float local_50 = 0.0f;
    float local_4c = 0.0f;
    uint16_t* local_8 = reinterpret_cast<uint16_t*>(
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x60)) * param_1 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x68) + -1) * (param_1 & 1) * 2 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 100)) * static_cast<uintptr_t>(param_2) +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x20)));
    uint32_t uVar8 = param_1 & 3;
    uint32_t uVar12 = static_cast<uint32_t>(param_2) & 3;
    intptr_t iVar3 = *(int32_t*)(in_ECX + 0x34);
    int32_t iRow;
    int32_t iStep;
    if ((param_1 & 1) == 0) {
        iRow = 0;
        iStep = 1;
    }
    else {
        iRow = *(int32_t*)(in_ECX + 0x68) + -1;
        iStep = -1;
    }
    uint16_t fpuControlWord = 0;  // observed: x87 control word read here
    *(uint32_t*)(in_ECX + 0x7c) = fpuControlWord;
    intptr_t errBase = *(int32_t*)(in_ECX + 0x5c);
    if (errBase != 0) {
        FUN_00601966(self, param_3);
    }
    uint32_t row = 0;
    if (*(int32_t*)(in_ECX + 0x68) != 0) {
        int32_t iVar10 = iStep * 0x10;
        int32_t iVar9 = iRow * 0x10;
        int32_t iVar11 = (iStep + iRow) * 0x10;
        int32_t errOff = (iRow - iStep) * 0x10;
        float* src = reinterpret_cast<float*>(iVar9 + 8 + reinterpret_cast<intptr_t>(param_3));
        do {
            float fVar2 = *(float*)(iVar3 + (uVar12 + uVar8 * 8) * 4 + (row & 3) * 4);
            float fVar4 = (local_58 + src[-2]) * 7.0f;
            float fVar5 = (local_54 + src[-1]) * 7.0f;
            float fVar6 = (local_50 + src[0]) * 3.0f;
            float fVar7 = (local_4c + src[1]) * 255.0f;
            uint32_t red = static_cast<uint32_t>(LocalRound(fVar4 + fVar2));
            uint32_t green = static_cast<uint32_t>(LocalRound(fVar5 + fVar2));
            int32_t blue = LocalRound(fVar6 + fVar2);
            int32_t alpha = LocalRound(fVar7 + fVar2);
            if (errBase != 0) {
                float* pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + errOff);
                local_58 = (fVar4 - static_cast<float>(static_cast<int32_t>(red))) * 0.14285715f;
                *pfVar1 = local_58 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + iVar9);
                *pfVar1 = local_58 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + iVar11);
                *pfVar1 = local_58 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + errOff);
                local_58 = local_58 * 0.4375f;
                local_54 = (fVar5 - static_cast<float>(static_cast<int32_t>(green))) * 0.14285715f;
                *pfVar1 = local_54 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + iVar9);
                *pfVar1 = local_54 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + iVar11);
                *pfVar1 = local_54 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + errOff);
                local_54 = local_54 * 0.4375f;
                local_50 = (fVar6 - static_cast<float>(blue)) * 0.33333334f;
                *pfVar1 = local_50 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + iVar9);
                *pfVar1 = local_50 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + iVar11);
                *pfVar1 = local_50 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x1c + errOff);
                local_50 = local_50 * 0.4375f;
                local_4c = (fVar7 - static_cast<float>(alpha)) * 0.003921569f;
                *pfVar1 = local_4c * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x1c + iVar9);
                *pfVar1 = local_4c * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x1c + iVar11);
                *pfVar1 = local_4c * 0.0625f + *pfVar1;
                local_4c = local_4c * 0.4375f;
            }
            uint32_t clampU = red;
            if (static_cast<int32_t>(red) < 7) {
                clampU = red;
            }
            else {
                clampU = 7;
            }
            if (static_cast<int32_t>(clampU) < 1) {
                red = 0;
            }
            else if (6 < static_cast<int32_t>(red)) {
                red = 7;
            }
            clampU = green;
            if (6 < static_cast<int32_t>(green)) {
                clampU = 7;
            }
            if (static_cast<int32_t>(clampU) < 1) {
                green = 0;
            }
            else if (6 < static_cast<int32_t>(green)) {
                green = 7;
            }
            int32_t clamp = blue;
            if (2 < blue) {
                clamp = 3;
            }
            if (clamp < 1) {
                blue = 0;
            }
            else if (2 < blue) {
                blue = 3;
            }
            clamp = alpha;
            if (0xfe < alpha) {
                clamp = 0xff;
            }
            if (clamp < 1) {
                alpha = 0;
            }
            else if (0xfe < alpha) {
                alpha = 0xff;
            }
            *local_8 = static_cast<uint16_t>(
                static_cast<uint16_t>(
                    ((static_cast<uint32_t>(alpha) << 3 | red) << 3 | green) << 2)) |
                static_cast<uint16_t>(blue);
            local_8 = local_8 + iStep;
            src = src + iStep * 4;
            iVar9 = iVar9 + iVar10;
            errOff = errOff + iVar10;
            iVar11 = iVar11 + iVar10;
            row = row + 1;
        } while (row < *reinterpret_cast<uint32_t*>(in_ECX + 0x68));
    }
}

// 0x60392a — observed shape
// 16-bit RGB444 conversion: three channels scaled by 15, error spread over the
// three planes at +0x5c, channels clamped to four bits and packed as R,G,B
// nibbles.
void FUN_0060392a(void* self, uint32_t param_1, uint32_t param_2, float* param_3)
{
    uintptr_t in_ECX = reinterpret_cast<uintptr_t>(self);
    if (*(int32_t*)(in_ECX + 0x54) != 0) {
        param_3 = reinterpret_cast<float*>(FUN_00600136(self, param_3));
    }
    if (*(int32_t*)(in_ECX + 0x10) != 0) {
        param_3 = reinterpret_cast<float*>(FUN_0060164a(self, param_3));
    }
    float local_54 = 0.0f;
    float local_50 = 0.0f;
    float local_4c = 0.0f;
    uint32_t uVar7 = param_1 & 3;
    uint16_t* local_8 = reinterpret_cast<uint16_t*>(
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x60)) * param_1 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x68) + -1) * (param_1 & 1) * 2 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 100)) * param_2 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x20)));
    intptr_t iVar3 = *(int32_t*)(in_ECX + 0x34);
    int32_t iRow;
    int32_t iStep;
    if ((param_1 & 1) == 0) {
        iRow = 0;
        iStep = 1;
    }
    else {
        iRow = *(int32_t*)(in_ECX + 0x68) + -1;
        iStep = -1;
    }
    uint16_t fpuControlWord = 0;  // observed: x87 control word read here
    *(uint32_t*)(in_ECX + 0x7c) = fpuControlWord;
    intptr_t errBase = *(int32_t*)(in_ECX + 0x5c);
    if (errBase != 0) {
        FUN_00601966(self, param_3);
    }
    uint32_t row = 0;
    if (*(int32_t*)(in_ECX + 0x68) != 0) {
        int32_t iVar9 = iStep * 0x10;
        int32_t iVar8 = iRow * 0x10;
        int32_t iVar10 = (iStep + iRow) * 0x10;
        int32_t errOff = (iRow - iStep) * 0x10;
        float* src = reinterpret_cast<float*>(iVar8 + 8 + reinterpret_cast<intptr_t>(param_3));
        do {
            float fVar2 = *(float*)(iVar3 + ((param_2 & 3) + uVar7 * 8) * 4 + (row & 3) * 4);
            float fVar4 = (local_54 + src[-2]) * 15.0f;
            float fVar5 = (local_50 + src[-1]) * 15.0f;
            float fVar6 = (local_4c + src[0]) * 15.0f;
            int32_t red = LocalRound(fVar4 + fVar2);
            uint32_t green = static_cast<uint32_t>(LocalRound(fVar5 + fVar2));
            int32_t blue = LocalRound(fVar6 + fVar2);
            if (errBase != 0) {
                float* pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + errOff);
                local_54 = (fVar4 - static_cast<float>(red)) * 0.06666667f;
                *pfVar1 = local_54 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + iVar8);
                *pfVar1 = local_54 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + iVar10);
                *pfVar1 = local_54 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + errOff);
                local_54 = local_54 * 0.4375f;
                local_50 = (fVar5 - static_cast<float>(static_cast<int32_t>(green))) * 0.06666667f;
                *pfVar1 = local_50 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + iVar8);
                *pfVar1 = local_50 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + iVar10);
                *pfVar1 = local_50 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + errOff);
                local_50 = local_50 * 0.4375f;
                local_4c = (fVar6 - static_cast<float>(blue)) * 0.06666667f;
                *pfVar1 = local_4c * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + iVar8);
                *pfVar1 = local_4c * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + iVar10);
                *pfVar1 = local_4c * 0.0625f + *pfVar1;
                local_4c = local_4c * 0.4375f;
            }
            int32_t clamp = red;
            if (red < 0xf) {
                clamp = red;
            }
            else {
                clamp = 0xf;
            }
            if (clamp < 1) {
                red = 0;
            }
            else if (0xe < red) {
                red = 0xf;
            }
            uint32_t clampU = green;
            if (0xe < static_cast<int32_t>(green)) {
                clampU = 0xf;
            }
            if (static_cast<int32_t>(clampU) < 1) {
                green = 0;
            }
            else if (0xe < static_cast<int32_t>(green)) {
                green = 0xf;
            }
            clamp = blue;
            if (0xe < blue) {
                clamp = 0xf;
            }
            if (clamp < 1) {
                blue = 0;
            }
            else if (0xe < blue) {
                blue = 0xf;
            }
            *local_8 = static_cast<uint16_t>(
                static_cast<uint16_t>(
                    (static_cast<uint32_t>(red) << 4 | green) << 4)) |
                static_cast<uint16_t>(blue);
            local_8 = local_8 + iStep;
            src = src + iStep * 4;
            iVar8 = iVar8 + iVar9;
            errOff = errOff + iVar9;
            iVar10 = iVar10 + iVar9;
            row = row + 1;
        } while (row < *reinterpret_cast<uint32_t*>(in_ECX + 0x68));
    }
}

// 0x603c29 — observed shape
// 32-bit ARGB2101010 conversion: the three colour channels are scaled by 1023
// and alpha by 3, error spread over the four planes at +0x5c, channels clamped
// to ten/ten/ten/two bits and packed as A,B,G,R.
void FUN_00603c29(void* self, uint32_t param_1, int32_t param_2, float* param_3)
{
    uintptr_t in_ECX = reinterpret_cast<uintptr_t>(self);
    if (*(int32_t*)(in_ECX + 0x54) != 0) {
        param_3 = reinterpret_cast<float*>(FUN_00600136(self, param_3));
    }
    if (*(int32_t*)(in_ECX + 0x10) != 0) {
        param_3 = reinterpret_cast<float*>(FUN_0060164a(self, param_3));
    }
    float local_58 = 0.0f;
    float local_54 = 0.0f;
    float local_50 = 0.0f;
    float local_4c = 0.0f;
    uint32_t* local_8 = reinterpret_cast<uint32_t*>(
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x60)) * param_1 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x68) + -1) * (param_1 & 1) * 4 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 100)) * static_cast<uintptr_t>(param_2) +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x20)));
    uint32_t uVar8 = param_1 & 3;
    uint32_t uVar12 = static_cast<uint32_t>(param_2) & 3;
    intptr_t iVar3 = *(int32_t*)(in_ECX + 0x34);
    int32_t iRow;
    int32_t iStep;
    if ((param_1 & 1) == 0) {
        iRow = 0;
        iStep = 1;
    }
    else {
        iRow = *(int32_t*)(in_ECX + 0x68) + -1;
        iStep = -1;
    }
    uint16_t fpuControlWord = 0;  // observed: x87 control word read here
    *(uint32_t*)(in_ECX + 0x7c) = fpuControlWord;
    intptr_t errBase = *(int32_t*)(in_ECX + 0x5c);
    if (errBase != 0) {
        FUN_00601966(self, param_3);
    }
    uint32_t row = 0;
    if (*(int32_t*)(in_ECX + 0x68) != 0) {
        int32_t iVar10 = iStep * 0x10;
        int32_t iVar9 = iRow * 0x10;
        int32_t iVar11 = (iStep + iRow) * 0x10;
        int32_t errOff = (iRow - iStep) * 0x10;
        float* src = reinterpret_cast<float*>(iVar9 + 8 + reinterpret_cast<intptr_t>(param_3));
        do {
            float fVar2 = *(float*)(iVar3 + (uVar12 + uVar8 * 8) * 4 + (row & 3) * 4);
            float fVar4 = (local_58 + src[-2]) * 1023.0f;
            float fVar5 = (local_54 + src[-1]) * 1023.0f;
            float fVar6 = (local_50 + src[0]) * 1023.0f;
            float fVar7 = (local_4c + src[1]) * 3.0f;
            uint32_t red = static_cast<uint32_t>(LocalRound(fVar4 + fVar2));
            uint32_t green = static_cast<uint32_t>(LocalRound(fVar5 + fVar2));
            uint32_t blue = static_cast<uint32_t>(LocalRound(fVar6 + fVar2));
            int32_t alpha = LocalRound(fVar7 + fVar2);
            if (errBase != 0) {
                float* pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + errOff);
                local_58 = (fVar4 - static_cast<float>(static_cast<int32_t>(red))) * 0.0009775171f;
                *pfVar1 = local_58 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + iVar9);
                *pfVar1 = local_58 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + iVar11);
                *pfVar1 = local_58 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + errOff);
                local_58 = local_58 * 0.4375f;
                local_54 = (fVar5 - static_cast<float>(static_cast<int32_t>(green))) * 0.0009775171f;
                *pfVar1 = local_54 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + iVar9);
                *pfVar1 = local_54 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + iVar11);
                *pfVar1 = local_54 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + errOff);
                local_54 = local_54 * 0.4375f;
                local_50 = (fVar6 - static_cast<float>(static_cast<int32_t>(blue))) * 0.0009775171f;
                *pfVar1 = local_50 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + iVar9);
                *pfVar1 = local_50 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + iVar11);
                *pfVar1 = local_50 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x1c + errOff);
                local_50 = local_50 * 0.4375f;
                local_4c = (fVar7 - static_cast<float>(alpha)) * 0.33333334f;
                *pfVar1 = local_4c * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x1c + iVar9);
                *pfVar1 = local_4c * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x1c + iVar11);
                *pfVar1 = local_4c * 0.0625f + *pfVar1;
                local_4c = local_4c * 0.4375f;
            }
            uint32_t clampU = red;
            if (0x3fe < static_cast<int32_t>(red)) {
                clampU = 0x3ff;
            }
            if (static_cast<int32_t>(clampU) < 1) {
                red = 0;
            }
            else if (0x3fe < static_cast<int32_t>(red)) {
                red = 0x3ff;
            }
            clampU = green;
            if (0x3fe < static_cast<int32_t>(green)) {
                clampU = 0x3ff;
            }
            if (static_cast<int32_t>(clampU) < 1) {
                green = 0;
            }
            else if (0x3fe < static_cast<int32_t>(green)) {
                green = 0x3ff;
            }
            clampU = blue;
            if (0x3fe < static_cast<int32_t>(blue)) {
                clampU = 0x3ff;
            }
            if (static_cast<int32_t>(clampU) < 1) {
                blue = 0;
            }
            else if (0x3fe < static_cast<int32_t>(blue)) {
                blue = 0x3ff;
            }
            int32_t clamp = alpha;
            if (alpha < 3) {
                clamp = alpha;
            }
            else {
                clamp = 3;
            }
            if (clamp < 1) {
                alpha = 0;
            }
            else if (2 < alpha) {
                alpha = 3;
            }
            *local_8 = static_cast<uint32_t>(
                ((static_cast<uint32_t>(alpha) << 10 | blue) << 10 | green) << 10) | red;
            local_8 = local_8 + iStep;
            src = src + iStep * 4;
            iVar9 = iVar9 + iVar10;
            errOff = errOff + iVar10;
            iVar11 = iVar11 + iVar10;
            row = row + 1;
        } while (row < *reinterpret_cast<uint32_t*>(in_ECX + 0x68));
    }
}

// 0x603fde — observed shape
// 32-bit ARGB8888 conversion: four channels scaled by 255, error spread over
// the four planes at +0x5c, channels clamped and packed as A,B,G,R.
void FUN_00603fde(void* self, uint32_t param_1, int32_t param_2, float* param_3)
{
    uintptr_t in_ECX = reinterpret_cast<uintptr_t>(self);
    if (*(int32_t*)(in_ECX + 0x54) != 0) {
        param_3 = reinterpret_cast<float*>(FUN_00600136(self, param_3));
    }
    if (*(int32_t*)(in_ECX + 0x10) != 0) {
        param_3 = reinterpret_cast<float*>(FUN_0060164a(self, param_3));
    }
    float local_58 = 0.0f;
    float local_54 = 0.0f;
    float local_50 = 0.0f;
    float local_4c = 0.0f;
    uint32_t* local_8 = reinterpret_cast<uint32_t*>(
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x60)) * param_1 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x68) + -1) * (param_1 & 1) * 4 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 100)) * static_cast<uintptr_t>(param_2) +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x20)));
    uint32_t uVar8 = param_1 & 3;
    uint32_t uVar12 = static_cast<uint32_t>(param_2) & 3;
    intptr_t iVar3 = *(int32_t*)(in_ECX + 0x34);
    int32_t iRow;
    int32_t iStep;
    if ((param_1 & 1) == 0) {
        iRow = 0;
        iStep = 1;
    }
    else {
        iRow = *(int32_t*)(in_ECX + 0x68) + -1;
        iStep = -1;
    }
    uint16_t fpuControlWord = 0;  // observed: x87 control word read here
    *(uint32_t*)(in_ECX + 0x7c) = fpuControlWord;
    intptr_t errBase = *(int32_t*)(in_ECX + 0x5c);
    if (errBase != 0) {
        FUN_00601966(self, param_3);
    }
    uint32_t row = 0;
    if (*(int32_t*)(in_ECX + 0x68) != 0) {
        int32_t iVar10 = iStep * 0x10;
        int32_t iVar9 = iRow * 0x10;
        int32_t iVar11 = (iStep + iRow) * 0x10;
        int32_t errOff = (iRow - iStep) * 0x10;
        float* src = reinterpret_cast<float*>(iVar9 + 8 + reinterpret_cast<intptr_t>(param_3));
        do {
            float fVar2 = *(float*)(iVar3 + (uVar12 + uVar8 * 8) * 4 + (row & 3) * 4);
            float fVar4 = (local_58 + src[-2]) * 255.0f;
            float fVar5 = (local_54 + src[-1]) * 255.0f;
            float fVar6 = (local_50 + src[0]) * 255.0f;
            float fVar7 = (local_4c + src[1]) * 255.0f;
            uint32_t red = static_cast<uint32_t>(LocalRound(fVar4 + fVar2));
            uint32_t green = static_cast<uint32_t>(LocalRound(fVar5 + fVar2));
            uint32_t blue = static_cast<uint32_t>(LocalRound(fVar6 + fVar2));
            int32_t alpha = LocalRound(fVar7 + fVar2);
            if (errBase != 0) {
                float* pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + errOff);
                local_58 = (fVar4 - static_cast<float>(static_cast<int32_t>(red))) * 0.003921569f;
                *pfVar1 = local_58 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + iVar9);
                *pfVar1 = local_58 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + iVar11);
                *pfVar1 = local_58 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + errOff);
                local_58 = local_58 * 0.4375f;
                local_54 = (fVar5 - static_cast<float>(static_cast<int32_t>(green))) * 0.003921569f;
                *pfVar1 = local_54 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + iVar9);
                *pfVar1 = local_54 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + iVar11);
                *pfVar1 = local_54 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + errOff);
                local_54 = local_54 * 0.4375f;
                local_50 = (fVar6 - static_cast<float>(static_cast<int32_t>(blue))) * 0.003921569f;
                *pfVar1 = local_50 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + iVar9);
                *pfVar1 = local_50 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + iVar11);
                *pfVar1 = local_50 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x1c + errOff);
                local_50 = local_50 * 0.4375f;
                local_4c = (fVar7 - static_cast<float>(alpha)) * 0.003921569f;
                *pfVar1 = local_4c * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x1c + iVar9);
                *pfVar1 = local_4c * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x1c + iVar11);
                *pfVar1 = local_4c * 0.0625f + *pfVar1;
                local_4c = local_4c * 0.4375f;
            }
            uint32_t clampU = red;
            if (0xfe < static_cast<int32_t>(red)) {
                clampU = 0xff;
            }
            if (static_cast<int32_t>(clampU) < 1) {
                red = 0;
            }
            else if (0xfe < static_cast<int32_t>(red)) {
                red = 0xff;
            }
            clampU = green;
            if (0xfe < static_cast<int32_t>(green)) {
                clampU = 0xff;
            }
            if (static_cast<int32_t>(clampU) < 1) {
                green = 0;
            }
            else if (0xfe < static_cast<int32_t>(green)) {
                green = 0xff;
            }
            clampU = blue;
            if (0xfe < static_cast<int32_t>(blue)) {
                clampU = 0xff;
            }
            if (static_cast<int32_t>(clampU) < 1) {
                blue = 0;
            }
            else if (0xfe < static_cast<int32_t>(blue)) {
                blue = 0xff;
            }
            int32_t clamp = alpha;
            if (0xfe < alpha) {
                clamp = 0xff;
            }
            if (clamp < 1) {
                alpha = 0;
            }
            else if (0xfe < alpha) {
                alpha = 0xff;
            }
            *local_8 = static_cast<uint32_t>(
                ((static_cast<uint32_t>(alpha) << 8 | blue) << 8 | green) << 8) | red;
            local_8 = local_8 + iStep;
            src = src + iStep * 4;
            iVar9 = iVar9 + iVar10;
            errOff = errOff + iVar10;
            iVar11 = iVar11 + iVar10;
            row = row + 1;
        } while (row < *reinterpret_cast<uint32_t*>(in_ECX + 0x68));
    }
}

// 0x60438d — observed shape
// 24-bit-in-32-bit B,G,R conversion: three channels scaled by 255, error
// spread over the three planes at +0x5c, channels clamped and packed as B,G,R
// into a dword of the +0x20 surface.
void FUN_0060438d(void* self, uint32_t param_1, uint32_t param_2, float* param_3)
{
    uintptr_t in_ECX = reinterpret_cast<uintptr_t>(self);
    if (*(int32_t*)(in_ECX + 0x54) != 0) {
        param_3 = reinterpret_cast<float*>(FUN_00600136(self, param_3));
    }
    if (*(int32_t*)(in_ECX + 0x10) != 0) {
        param_3 = reinterpret_cast<float*>(FUN_0060164a(self, param_3));
    }
    float local_54 = 0.0f;
    float local_50 = 0.0f;
    float local_4c = 0.0f;
    uint32_t uVar7 = param_1 & 3;
    uint32_t* local_8 = reinterpret_cast<uint32_t*>(
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x60)) * param_1 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x68) + -1) * (param_1 & 1) * 4 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 100)) * param_2 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x20)));
    intptr_t iVar3 = *(int32_t*)(in_ECX + 0x34);
    int32_t iRow;
    int32_t iStep;
    if ((param_1 & 1) == 0) {
        iRow = 0;
        iStep = 1;
    }
    else {
        iRow = *(int32_t*)(in_ECX + 0x68) + -1;
        iStep = -1;
    }
    uint16_t fpuControlWord = 0;  // observed: x87 control word read here
    *(uint32_t*)(in_ECX + 0x7c) = fpuControlWord;
    intptr_t errBase = *(int32_t*)(in_ECX + 0x5c);
    if (errBase != 0) {
        FUN_00601966(self, param_3);
    }
    uint32_t row = 0;
    if (*(int32_t*)(in_ECX + 0x68) != 0) {
        int32_t iVar9 = iStep * 0x10;
        int32_t iVar8 = iRow * 0x10;
        int32_t iVar10 = (iStep + iRow) * 0x10;
        int32_t errOff = (iRow - iStep) * 0x10;
        float* src = reinterpret_cast<float*>(iVar8 + 8 + reinterpret_cast<intptr_t>(param_3));
        do {
            float fVar2 = *(float*)(iVar3 + ((param_2 & 3) + uVar7 * 8) * 4 + (row & 3) * 4);
            float fVar4 = (local_54 + src[-2]) * 255.0f;
            float fVar5 = (local_50 + src[-1]) * 255.0f;
            float fVar6 = (local_4c + src[0]) * 255.0f;
            uint32_t red = static_cast<uint32_t>(LocalRound(fVar4 + fVar2));
            uint32_t green = static_cast<uint32_t>(LocalRound(fVar5 + fVar2));
            int32_t blue = LocalRound(fVar6 + fVar2);
            if (errBase != 0) {
                float* pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + errOff);
                local_54 = (fVar4 - static_cast<float>(static_cast<int32_t>(red))) * 0.003921569f;
                *pfVar1 = local_54 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + iVar8);
                *pfVar1 = local_54 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + iVar10);
                *pfVar1 = local_54 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + errOff);
                local_54 = local_54 * 0.4375f;
                local_50 = (fVar5 - static_cast<float>(static_cast<int32_t>(green))) * 0.003921569f;
                *pfVar1 = local_50 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + iVar8);
                *pfVar1 = local_50 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + iVar10);
                *pfVar1 = local_50 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + errOff);
                local_50 = local_50 * 0.4375f;
                local_4c = (fVar6 - static_cast<float>(blue)) * 0.003921569f;
                *pfVar1 = local_4c * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + iVar8);
                *pfVar1 = local_4c * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x18 + iVar10);
                *pfVar1 = local_4c * 0.0625f + *pfVar1;
                local_4c = local_4c * 0.4375f;
            }
            uint32_t clampU = red;
            if (0xfe < static_cast<int32_t>(red)) {
                clampU = 0xff;
            }
            if (static_cast<int32_t>(clampU) < 1) {
                red = 0;
            }
            else if (0xfe < static_cast<int32_t>(red)) {
                red = 0xff;
            }
            clampU = green;
            if (0xfe < static_cast<int32_t>(green)) {
                clampU = 0xff;
            }
            if (static_cast<int32_t>(clampU) < 1) {
                green = 0;
            }
            else if (0xfe < static_cast<int32_t>(green)) {
                green = 0xff;
            }
            int32_t clamp = blue;
            if (0xfe < blue) {
                clamp = 0xff;
            }
            if (clamp < 1) {
                blue = 0;
            }
            else if (0xfe < blue) {
                blue = 0xff;
            }
            *local_8 = static_cast<uint32_t>(
                (static_cast<uint32_t>(blue) << 8 | green) << 8) | red;
            local_8 = local_8 + iStep;
            src = src + iStep * 4;
            iVar8 = iVar8 + iVar9;
            errOff = errOff + iVar9;
            iVar10 = iVar10 + iVar9;
            row = row + 1;
        } while (row < *reinterpret_cast<uint32_t*>(in_ECX + 0x68));
    }
}

// 0x6046a3 — observed shape
// 32-bit two-channel format: the first two floats of each sample are scaled by
// 65535, the error of both channels is accumulated into the two planes at
// +0x5c (0x10 and 0x14), clamped to 16 bits and packed as high,low words.
void FUN_006046a3(void* self, uint32_t param_1, uint32_t param_2, void* param_3)
{
    uintptr_t in_ECX = reinterpret_cast<uintptr_t>(self);
    if (*(int32_t*)(in_ECX + 0x54) != 0) {
        param_3 = FUN_00600136(self, param_3);
    }
    if (*(int32_t*)(in_ECX + 0x10) != 0) {
        param_3 = FUN_0060164a(self, param_3);
    }
    float local_54 = 0.0f;
    float local_50 = 0.0f;
    uint32_t uVar7 = param_1 & 3;
    uint32_t uVar9 = param_2 & 3;
    uint32_t* local_8 = reinterpret_cast<uint32_t*>(
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x60)) * param_1 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x68) + -1) * (param_1 & 1) * 4 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 100)) * param_2 +
        static_cast<uintptr_t>(*(int32_t*)(in_ECX + 0x20)));
    intptr_t iVar3 = *(int32_t*)(in_ECX + 0x34);
    int32_t iRow;
    int32_t iStep;
    if ((param_1 & 1) == 0) {
        iRow = 0;
        iStep = 1;
    }
    else {
        iRow = *(int32_t*)(in_ECX + 0x68) + -1;
        iStep = -1;
    }
    int32_t sampleStep = iStep;
    uint16_t fpuControlWord = 0;  // observed: x87 control word read here
    *(uint32_t*)(in_ECX + 0x7c) = fpuControlWord;
    intptr_t errBase = *(int32_t*)(in_ECX + 0x5c);
    if (errBase != 0) {
        FUN_00601966(self, param_3);
    }
    uint32_t row = 0;
    if (*(int32_t*)(in_ECX + 0x68) != 0) {
        int32_t iVar10 = sampleStep * 0x10;
        int32_t iVar8 = iRow << 4;
        int32_t iVar11 = (sampleStep + iRow) * 0x10;
        int32_t errOff = (iRow - sampleStep) * 0x10;
        do {
            float fVar2 = *(float*)(iVar3 + (uVar9 + uVar7 * 8) * 4 + (row & 3) * 4);
            float* src = reinterpret_cast<float*>(
                reinterpret_cast<intptr_t>(param_3) + iVar8);
            float fVar4 = (local_54 + src[0]) * 65535.0f;
            float fVar5 = (local_50 + src[1]) * 65535.0f;
            uint32_t low = static_cast<uint32_t>(LocalRound(fVar4 + fVar2));
            int32_t high = LocalRound(fVar5 + fVar2);
            if (errBase != 0) {
                float* pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + errOff);
                local_54 = (fVar4 - static_cast<float>(static_cast<int32_t>(low))) * 1.5259022e-05f;
                *pfVar1 = local_54 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + iVar8);
                *pfVar1 = local_54 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x10 + iVar11);
                *pfVar1 = local_54 * 0.0625f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + errOff);
                local_54 = local_54 * 0.4375f;
                local_50 = (fVar5 - static_cast<float>(high)) * 1.5259022e-05f;
                *pfVar1 = local_50 * 0.1875f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + iVar8);
                *pfVar1 = local_50 * 0.3125f + *pfVar1;
                pfVar1 = reinterpret_cast<float*>(errBase + 0x14 + iVar11);
                *pfVar1 = local_50 * 0.0625f + *pfVar1;
                local_50 = local_50 * 0.4375f;
            }
            uint32_t clampU = low;
            if (0xfffe < static_cast<int32_t>(low)) {
                clampU = 0xffff;
            }
            if (static_cast<int32_t>(clampU) < 1) {
                low = 0;
            }
            else if (0xfffe < static_cast<int32_t>(low)) {
                low = 0xffff;
            }
            int32_t clamp = high;
            if (0xfffe < high) {
                clamp = 0xffff;
            }
            if (clamp < 1) {
                high = 0;
            }
            else if (0xfffe < high) {
                high = 0xffff;
            }
            *local_8 = static_cast<uint32_t>(high) << 0x10 | low;
            local_8 = local_8 + sampleStep;
            errOff = errOff + iVar10;
            iVar8 = iVar8 + iVar10;
            iVar11 = iVar11 + iVar10;
            row = row + 1;
        } while (row < *reinterpret_cast<uint32_t*>(in_ECX + 0x68));
    }
}
