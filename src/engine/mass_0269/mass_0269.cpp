// Reconstruction batch mass_0269
// Target: Sid Meier's Pirates! (2004), PE32 i386
// Image: 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
//
// Field layout observed in this batch (all offsets byte offsets from the
// register receiver `self`):
//   +0x10 flag, +0x18 flag, +0x20 base pointer,
//   +0x60 row stride (param_1 multiplier), +0x64 (100) column stride (param_2 multiplier),
//   +0x68 pixel/count, +0x74 byte end offset, +0x54/+0x5c/+0x7c flags/ptr/cw.
//
// Receiver convention: the provider reports the destination object in
// in_ECX; each definition exposes it as `void* self` and never uses `this`.

#include <cstdint>
#include <cstddef>
#include <cmath>
#include <windows.h>

extern void* FUN_0060164a(void* param_3);
extern void* FUN_00600136(void* param_3);
extern void FUN_00601966(void* param_3);
extern void FUN_006015d0(void* param);
extern void FUN_0060183d(void* param);

// Local ROUND: the decompiler's ROUND rounds to the nearest integer.
// The exact rounding mode of the original (x87 round-to-nearest) is
// reproduced with std::nearbyint semantics guarded by the FPU control
// word captured at +0x7c; callers pass the already-scaled value. We keep
// the simplest faithful form here and note the manual follow-up.
inline int LocalRound(float v) {
    long r = std::lround(v);
    return (int)r;
}

// 0x607be3 — observed shape
// Copies pixel rows: pre-transform via 0x60164a when +0x10 set, then
// element-wise copy of 8-byte (2 x uint32) pixels, param_3 advancing 4
// dwords per pixel, count from +0x68.
void FUN_00607be3(void* self, int param_1, int param_2, uint32_t* param_3) {
    if (*(int*)((char*)self + 0x10) != 0) {
        param_3 = (uint32_t*)FUN_0060164a(param_3);
    }
    uint32_t* puVar1 = (uint32_t*)(*(int*)((char*)self + 0x60) * param_1 +
                                   *(int*)((char*)self + 100) * param_2 +
                                   *(int*)((char*)self + 0x20));
    uint32_t uVar2 = 0;
    if (*(int*)((char*)self + 0x68) != 0) {
        do {
            *puVar1 = *param_3;
            puVar1[1] = param_3[1];
            puVar1 = puVar1 + 2;
            uVar2 = uVar2 + 1;
            param_3 = param_3 + 4;
        } while (uVar2 < *(uint*)((char*)self + 0x68));
    }
}

// 0x607c36 — observed shape
// Same prologue and row address as 0x607be3, but copies the row as a flat
// dword stream: count is (+0x68 & 0xfffffff) << 2 dwords. A second, dead
// byte loop with a zero bound follows in the listing.
void FUN_00607c36(void* self, int param_1, int param_2, uint32_t* param_3) {
    if (*(int*)((char*)self + 0x10) != 0) {
        param_3 = (uint32_t*)FUN_0060164a(param_3);
    }
    uint32_t* puVar2 = (uint32_t*)(*(int*)((char*)self + 0x60) * param_1 +
                                   *(int*)((char*)self + 100) * param_2 +
                                   *(int*)((char*)self + 0x20));
    for (int iVar1 = (int)((*(uint*)((char*)self + 0x68) & 0xfffffffu) << 2); iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = *param_3;
        param_3 = param_3 + 1;
        puVar2 = puVar2 + 1;
    }
    for (int iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
        *(uint8_t*)puVar2 = *(uint8_t*)param_3;
        param_3 = (uint32_t*)((char*)param_3 + 1);
        puVar2 = (uint32_t*)((char*)puVar2 + 1);
    }
}

// NEEDS_MANUAL: the listing stores the x87 FPU control word into +0x7c
// (`*(uint*)(in_ECX + 0x7c) = in_FPUControlWord`). That value exists only
// at runtime on the x87 stack register and has no reconstructable operand
// in the listing, so no literal is fabricated; the store site is marked
// below and must be supplied by an inline-asm FPU-control capture.
// 0x607c82 — observed shape
// Grayscale/luminance conversion + dithered 16-bit RGB565 packing.
// Pre-transforms: 0x600136 when +0x54 set, 0x60164a when +0x10 set.
// Row direction flips on param_1 parity (low byte): even -> start 0,
// step +1; odd -> start count-1, step -1. After a luminance pass it
// optionally calls 0x601966 when +0x5c set, then per-pixel: sample a
// dither value from table at +0x34 (index (uVar9 + uVar6*8)*4 +
// (param_1&3)*4 bytes), scale (local + channel)*65535, round, feed back
// error diffusion into the +0x5c error buffer (weights 0.1875/0.3125/
// 0.0625/0.4375), clamp to [0,0xffff], and store (high<<16)|low.
void FUN_00607c82(void* self, uint32_t param_1, uint32_t param_2, float* param_3) {
    if (*(int*)((char*)self + 0x54) != 0) {
        param_3 = (float*)FUN_00600136(param_3);
    }
    if (*(int*)((char*)self + 0x10) != 0) {
        param_3 = (float*)FUN_0060164a(param_3);
    }
    float local_54 = 0.0f;
    float local_48 = 0.0f;
    uint32_t uVar6 = param_1 & 3;
    uint32_t uVar9 = param_2 & 3;
    uint32_t* local_8 = (uint32_t*)(*(int*)((char*)self + 0x60) * param_1 +
                                   (*(int*)((char*)self + 0x68) + -1) * (param_1 & 1) * 4 +
                                   *(int*)((char*)self + 100) * param_2 + *(int*)((char*)self + 0x20));
    int iVar2 = *(int*)((char*)self + 0x34);
    int iVar13;
    int iVar5;
    uint32_t param_1w = param_1;
    uint32_t param_2w;
    if ((param_1 & 1) == 0) {
        iVar13 = 0;
        param_2w = 1;
    } else {
        iVar13 = *(int*)((char*)self + 0x68) + -1;
        param_2w = -1;
    }
    iVar5 = param_2w;
    // NEEDS_MANUAL: *(uint32_t*)((char*)self + 0x7c) = in_FPUControlWord
    uint32_t uVar10 = 0;
    if (*(int*)((char*)self + 0x68) != 0) {
        float* pfVar7 = param_3;
        do {
            uVar10 = uVar10 + 1;
            *pfVar7 = *pfVar7 * 0.2125f + pfVar7[1] * 0.7154f + pfVar7[2] * 0.0721f;
            pfVar7 = pfVar7 + 4;
        } while (uVar10 < *(uint*)((char*)self + 0x68));
    }
    if (*(int*)((char*)self + 0x5c) != 0) {
        FUN_00601966(param_3);
    }
    param_1w = 0;
    if (*(int*)((char*)self + 0x68) != 0) {
        int iVar11 = param_2w * 0x10;
        int iVar8 = iVar13 << 4;
        int iVar12 = (param_2w + iVar13) * 0x10;
        int param_2off = (iVar13 - param_2w) * 0x10;
        do {
            float fVar1 = *(float*)(iVar2 + (uVar9 + uVar6 * 8) * 4 + (param_1w & 3) * 4);
            float fVar3 = (local_54 + *(float*)((char*)param_3 + iVar8)) * 65535.0f;
            float fVar4 = (local_48 + ((float*)((char*)param_3 + iVar8))[3]) * 65535.0f;
            uint32_t local_34 = (uint32_t)LocalRound(fVar3 + fVar1);
            int iVar13b = LocalRound(fVar4 + fVar1);
            if (*(int*)((char*)self + 0x5c) != 0) {
                float* pfVar7 = (float*)(param_2off + 0x10 + *(int*)((char*)self + 0x5c));
                local_54 = (fVar3 - (float)(int)local_34) * 1.5259022e-05f;
                *pfVar7 = local_54 * 0.1875f + *pfVar7;
                pfVar7 = (float*)(iVar8 + 0x10 + *(int*)((char*)self + 0x5c));
                *pfVar7 = local_54 * 0.3125f + *pfVar7;
                pfVar7 = (float*)(iVar12 + 0x10 + *(int*)((char*)self + 0x5c));
                *pfVar7 = local_54 * 0.0625f + *pfVar7;
                pfVar7 = (float*)(param_2off + 0x1c + *(int*)((char*)self + 0x5c));
                local_54 = local_54 * 0.4375f;
                local_48 = (fVar4 - (float)iVar13b) * 1.5259022e-05f;
                *pfVar7 = local_48 * 0.1875f + *pfVar7;
                pfVar7 = (float*)(iVar8 + 0x1c + *(int*)((char*)self + 0x5c));
                *pfVar7 = local_48 * 0.3125f + *pfVar7;
                pfVar7 = (float*)(iVar12 + 0x1c + *(int*)((char*)self + 0x5c));
                *pfVar7 = local_48 * 0.0625f + *pfVar7;
                local_48 = local_48 * 0.4375f;
            }
            uVar10 = local_34;
            if (0xfffe < (int)local_34) {
                uVar10 = 0xffff;
            }
            if ((int)uVar10 < 1) {
                local_34 = 0;
            } else if (0xfffe < (int)local_34) {
                local_34 = 0xffff;
            }
            int iVar14 = iVar13b;
            if (0xfffe < iVar13b) {
                iVar14 = 0xffff;
            }
            if (iVar14 < 1) {
                iVar13b = 0;
            } else if (0xfffe < iVar13b) {
                iVar13b = 0xffff;
            }
            *local_8 = (uint32_t)(iVar13b << 0x10 | local_34);
            local_8 = local_8 + iVar5;
            param_2off = param_2off + iVar11;
            iVar8 = iVar8 + iVar11;
            iVar12 = iVar12 + iVar11;
            param_1w = param_1w + 1;
        } while (param_1w < *(uint*)((char*)self + 0x68));
    }
}

// 0x607f2a — observed shape
// RGB (3-channel) sibling of 0x607c82. Same pre-transforms (0x600136
// when +0x54, 0x60164a when +0x10), same parity direction logic, same
// error-diffusion weights, but three channels read from param_3 at
// offsets -2/-1/0 from a base of (iVar8 + 8 + param_3); the destination
// is a `ushort` triple stepped by 3, stored as [2]=col0, [1]=col1,
// [0]=col2 (in that assignment order, i.e. swapped). FPUControlWord is
// concat'd into param_2 and stored at +0x7c.
void FUN_00607f2a(void* self, uint32_t param_1, uint32_t param_2, float* param_3) {
    if (*(int*)((char*)self + 0x54) != 0) {
        param_3 = (float*)FUN_00600136(param_3);
    }
    if (*(int*)((char*)self + 0x10) != 0) {
        param_3 = (float*)FUN_0060164a(param_3);
    }
    float local_54 = 0.0f;
    float local_50 = 0.0f;
    float local_4c = 0.0f;
    uint32_t uVar9 = param_1 & 3;
    uint32_t uVar7 = param_2 & 3;
    int iVar3 = *(int*)((char*)self + 0x34);
    uint16_t* puVar15 = (uint16_t*)(*(int*)((char*)self + 0x60) * param_1 +
                                   (*(int*)((char*)self + 0x68) + -1) * (param_1 & 1) * 6 +
                                   *(int*)((char*)self + 100) * param_2 + *(int*)((char*)self + 0x20));
    int iVar13;
    int iVar12;
    uint32_t param_1w;
    if ((param_1 & 1) == 0) {
        iVar13 = 0;
        iVar12 = 1;
        param_1w = 1;
    } else {
        iVar13 = *(int*)((char*)self + 0x68) + -1;
        param_1w = -1;
        iVar12 = -1;
    }
    // NEEDS_MANUAL: the listing forms CONCAT22(param_2._2_2_, in_FPUControlWord)
    // and stores it at +0x7c: the high 16 bits are param_2's high half, the
    // low 16 bits are the runtime x87 FPU control word (not reconstructable).
    *(uint32_t*)((char*)self + 0x7c) = param_2; // low half placeholder=FPU cw
    if (*(int*)((char*)self + 0x5c) != 0) {
        FUN_00601966(param_3);
        iVar12 = param_1w;
    }
    param_1w = 0;
    if (*(int*)((char*)self + 0x68) != 0) {
        int iVar10 = iVar12 * 0x10;
        int iVar8 = iVar13 * 0x10;
        int iVar11 = (iVar12 + iVar13) * 0x10;
        int param_2off = (iVar13 - iVar12) * 0x10;
        param_3 = (float*)(iVar8 + 8 + (intptr_t)param_3);
        do {
            float fVar2 = *(float*)(iVar3 + (uVar7 + uVar9 * 8) * 4 + (param_1w & 3) * 4);
            float fVar4 = (local_54 + param_3[-2]) * 65535.0f;
            float fVar5 = (local_50 + param_3[-1]) * 65535.0f;
            float fVar6 = (local_4c + *param_3) * 65535.0f;
            int local_34 = LocalRound(fVar4 + fVar2);
            int local_30 = LocalRound(fVar5 + fVar2);
            int iVar13b = LocalRound(fVar6 + fVar2);
            if (*(int*)((char*)self + 0x5c) != 0) {
                float* pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x10 + param_2off);
                local_54 = (fVar4 - (float)local_34) * 1.5259022e-05f;
                *pfVar1 = local_54 * 0.1875f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x10 + iVar8);
                *pfVar1 = local_54 * 0.3125f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x10 + iVar11);
                *pfVar1 = local_54 * 0.0625f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x14 + param_2off);
                local_54 = local_54 * 0.4375f;
                local_50 = (fVar5 - (float)local_30) * 1.5259022e-05f;
                *pfVar1 = local_50 * 0.1875f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x14 + iVar8);
                *pfVar1 = local_50 * 0.3125f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x14 + iVar11);
                *pfVar1 = local_50 * 0.0625f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x18 + param_2off);
                local_50 = local_50 * 0.4375f;
                local_4c = (fVar6 - (float)iVar13b) * 1.5259022e-05f;
                *pfVar1 = local_4c * 0.1875f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x18 + iVar8);
                *pfVar1 = local_4c * 0.3125f + *pfVar1;
                pfVar1 = (float*)(*(int*)((char*)self + 0x5c) + 0x18 + iVar11);
                *pfVar1 = local_4c * 0.0625f + *pfVar1;
                local_4c = local_4c * 0.4375f;
            }
            int iVar14 = local_34;
            if (0xfffe < local_34) iVar14 = 0xffff;
            if (iVar14 < 1) local_34 = 0;
            else if (0xfffe < local_34) local_34 = 0xffff;
            iVar14 = local_30;
            if (0xfffe < local_30) iVar14 = 0xffff;
            if (iVar14 < 1) local_30 = 0;
            else if (0xfffe < local_30) local_30 = 0xffff;
            iVar14 = iVar13b;
            if (0xfffe < iVar13b) iVar14 = 0xffff;
            if (iVar14 < 1) iVar13b = 0;
            else if (0xfffe < iVar13b) iVar13b = 0xffff;
            puVar15[1] = (uint16_t)local_30;
            puVar15[2] = (uint16_t)local_34;
            param_3 = param_3 + iVar12 * 4;
            param_2off = param_2off + iVar10;
            *puVar15 = (uint16_t)(short)iVar13b;
            puVar15 = puVar15 + iVar12 * 3;
            iVar8 = iVar8 + iVar10;
            iVar11 = iVar11 + iVar10;
            param_1w = param_1w + 1;
        } while (param_1w < *(uint*)((char*)self + 0x68));
    }
}

// 0x60822d — observed shape
// RGB (3-byte) -> RGBA float via 0.003921569 (=1/255). Source end is
// base + (+0x74) bytes. Channel order [2],[1],[0] then alpha 1.0.
// Finishes with optional 0x6015d0 (+0x18) / 0x60183d (+0x10) on the tail
// pointer pfVar4 + (+0x68)*-4.
void FUN_0060822d(void* self, int param_1, int param_2, float* param_3) {
    uint8_t* pbVar2 = (uint8_t*)(*(int*)((char*)self + 0x60) * param_1 +
                                 *(int*)((char*)self + 100) * param_2 +
                                 *(int*)((char*)self + 0x20));
    uint8_t* pbVar3 = pbVar2 + *(int*)((char*)self + 0x74);
    float* pfVar4 = param_3;
    if (pbVar2 < pbVar3) {
        do {
            *param_3 = (float)pbVar2[2] * 0.003921569f;
            pfVar4 = param_3 + 4;
            param_3[1] = (float)pbVar2[1] * 0.003921569f;
            uint8_t bVar1 = *pbVar2;
            pbVar2 = pbVar2 + 3;
            param_3[2] = (float)bVar1 * 0.003921569f;
            param_3[3] = 1.0f;
            param_3 = pfVar4;
        } while (pbVar2 < pbVar3);
    }
    if (*(int*)((char*)self + 0x18) != 0) {
        FUN_006015d0(pfVar4 + *(int*)((char*)self + 0x68) * -4);
    }
    if (*(int*)((char*)self + 0x10) != 0) {
        FUN_0060183d(pfVar4 + *(int*)((char*)self + 0x68) * -4);
    }
}

// 0x6082c5 — observed shape
// RGBA8888 (uint32) -> RGBA float via 0.003921569, channels
// [byte2],[byte1],[byte0],[byte3], memcpy-style loop advancing source
// one dword and destination 4 floats per pixel.
void FUN_006082c5(void* self, int param_1, int param_2, float* param_3) {
    uint32_t* puVar2 = (uint32_t*)(*(int*)((char*)self + 0x60) * param_1 +
                                  *(int*)((char*)self + 100) * param_2 +
                                  *(int*)((char*)self + 0x20));
    uint32_t* puVar1 = puVar2 + *(int*)((char*)self + 0x68);
    float* pfVar4 = param_3;
    if (puVar2 < puVar1) {
        do {
            *param_3 = (float)*(uint8_t*)((char*)puVar2 + 2) * 0.003921569f;
            param_3[1] = (float)*(uint8_t*)((char*)puVar2 + 1) * 0.003921569f;
            uint32_t* puVar3 = puVar2 + 1;
            pfVar4 = param_3 + 4;
            param_3[2] = (float)(*puVar2 & 0xff) * 0.003921569f;
            param_3[3] = (float)*(uint8_t*)((char*)puVar2 + 3) * 0.003921569f;
            puVar2 = puVar3;
            param_3 = pfVar4;
        } while (puVar3 < puVar1);
    }
    if (*(int*)((char*)self + 0x18) != 0) {
        FUN_006015d0(pfVar4 + *(int*)((char*)self + 0x68) * -4);
    }
    if (*(int*)((char*)self + 0x10) != 0) {
        FUN_0060183d(pfVar4 + *(int*)((char*)self + 0x68) * -4);
    }
}

// 0x608377 — observed shape
// RGB888 (uint32 low 3 bytes) -> RGBA float via 0.003921569, channels
// [byte2],[byte1],[byte0], alpha 1.0.
void FUN_00608377(void* self, int param_1, int param_2, float* param_3) {
    uint32_t* puVar3 = (uint32_t*)(*(int*)((char*)self + 0x60) * param_1 +
                                  *(int*)((char*)self + 100) * param_2 +
                                  *(int*)((char*)self + 0x20));
    uint32_t* puVar1 = puVar3 + *(int*)((char*)self + 0x68);
    float* pfVar4 = param_3;
    if (puVar3 < puVar1) {
        do {
            *param_3 = (float)*(uint8_t*)((char*)puVar3 + 2) * 0.003921569f;
            param_3[1] = (float)*(uint8_t*)((char*)puVar3 + 1) * 0.003921569f;
            uint32_t uVar2 = *puVar3;
            puVar3 = puVar3 + 1;
            pfVar4 = param_3 + 4;
            param_3[2] = (float)(uVar2 & 0xff) * 0.003921569f;
            param_3[3] = 1.0f;
            param_3 = pfVar4;
        } while (puVar3 < puVar1);
    }
    if (*(int*)((char*)self + 0x18) != 0) {
        FUN_006015d0(pfVar4 + *(int*)((char*)self + 0x68) * -4);
    }
    if (*(int*)((char*)self + 0x10) != 0) {
        FUN_0060183d(pfVar4 + *(int*)((char*)self + 0x68) * -4);
    }
}

// 0x60841f — observed shape
// RGB565 unpack: R = (v>>11)*0.032258064, G = ((v>>5)&0x3f)*0.015873017,
// B = ((byte)v & 0x1f)*0.032258064, alpha 1.0. Source stepped per ushort.
void FUN_0060841f(void* self, int param_1, int param_2, float* param_3) {
    uint16_t* puVar2 = (uint16_t*)(*(int*)((char*)self + 0x60) * param_1 +
                                  *(int*)((char*)self + 100) * param_2 +
                                  *(int*)((char*)self + 0x20));
    uint16_t* puVar1 = puVar2 + *(int*)((char*)self + 0x68);
    for (; puVar2 < puVar1; puVar2 = puVar2 + 1) {
        *param_3 = (float)(*puVar2 >> 0xb) * 0.032258064f;
        param_3[1] = (float)(*puVar2 >> 5 & 0x3f) * 0.015873017f;
        param_3[2] = (float)((uint8_t)*puVar2 & 0x1f) * 0.032258064f;
        param_3[3] = 1.0f;
        param_3 = param_3 + 4;
    }
    if (*(int*)((char*)self + 0x18) != 0) {
        FUN_006015d0(param_3 + *(int*)((char*)self + 0x68) * -4);
    }
    if (*(int*)((char*)self + 0x10) != 0) {
        FUN_0060183d(param_3 + *(int*)((char*)self + 0x68) * -4);
    }
}

// 0x6084cc — observed shape
// RGB555 unpack: R = ((v>>10)&0x1f)*0.032258064,
// G = ((v>>5)&0x1f)*0.032258064, B = ((byte)v & 0x1f)*0.032258064,
// alpha 1.0.
void FUN_006084cc(void* self, int param_1, int param_2, float* param_3) {
    uint16_t* puVar2 = (uint16_t*)(*(int*)((char*)self + 0x60) * param_1 +
                                  *(int*)((char*)self + 100) * param_2 +
                                  *(int*)((char*)self + 0x20));
    uint16_t* puVar1 = puVar2 + *(int*)((char*)self + 0x68);
    for (; puVar2 < puVar1; puVar2 = puVar2 + 1) {
        *param_3 = (float)(*puVar2 >> 10 & 0x1f) * 0.032258064f;
        param_3[1] = (float)(*puVar2 >> 5 & 0x1f) * 0.032258064f;
        param_3[2] = (float)((uint8_t)*puVar2 & 0x1f) * 0.032258064f;
        param_3[3] = 1.0f;
        param_3 = param_3 + 4;
    }
    if (*(int*)((char*)self + 0x18) != 0) {
        FUN_006015d0(param_3 + *(int*)((char*)self + 0x68) * -4);
    }
    if (*(int*)((char*)self + 0x10) != 0) {
        FUN_0060183d(param_3 + *(int*)((char*)self + 0x68) * -4);
    }
}

// 0x608576 — observed shape
// RGB555 + 1-bit alpha: as 0x6084cc, but alpha = (float)(v>>0xf).
void FUN_00608576(void* self, int param_1, int param_2, float* param_3) {
    uint16_t* puVar2 = (uint16_t*)(*(int*)((char*)self + 0x60) * param_1 +
                                  *(int*)((char*)self + 100) * param_2 +
                                  *(int*)((char*)self + 0x20));
    uint16_t* puVar1 = puVar2 + *(int*)((char*)self + 0x68);
    for (; puVar2 < puVar1; puVar2 = puVar2 + 1) {
        *param_3 = (float)(*puVar2 >> 10 & 0x1f) * 0.032258064f;
        param_3[1] = (float)(*puVar2 >> 5 & 0x1f) * 0.032258064f;
        param_3[2] = (float)((uint8_t)*puVar2 & 0x1f) * 0.032258064f;
        param_3[3] = (float)(*puVar2 >> 0xf);
        param_3 = param_3 + 4;
    }
    if (*(int*)((char*)self + 0x18) != 0) {
        FUN_006015d0(param_3 + *(int*)((char*)self + 0x68) * -4);
    }
    if (*(int*)((char*)self + 0x10) != 0) {
        FUN_0060183d(param_3 + *(int*)((char*)self + 0x68) * -4);
    }
}

// 0x60862e — observed shape
// ARGB4444 unpack: R = ((byte1)&0xf)*0.06666667,
// G = ((byte0)>>4)*0.06666667, B = ((byte0)&0xf)*0.06666667,
// A = (v>>12)*0.06666667. Source stepped per ushort.
void FUN_0060862e(void* self, int param_1, int param_2, float* param_3) {
    uint16_t* puVar2 = (uint16_t*)(*(int*)((char*)self + 0x60) * param_1 +
                                  *(int*)((char*)self + 100) * param_2 +
                                  *(int*)((char*)self + 0x20));
    uint16_t* puVar1 = puVar2 + *(int*)((char*)self + 0x68);
    for (; puVar2 < puVar1; puVar2 = puVar2 + 1) {
        *param_3 = (float)(*(uint8_t*)((char*)puVar2 + 1) & 0xf) * 0.06666667f;
        param_3[1] = (float)(uint8_t)((uint8_t)*puVar2 >> 4) * 0.06666667f;
        param_3[2] = (float)((uint8_t)*puVar2 & 0xf) * 0.06666667f;
        param_3[3] = (float)(*puVar2 >> 0xc) * 0.06666667f;
        param_3 = param_3 + 4;
    }
    if (*(int*)((char*)self + 0x18) != 0) {
        FUN_006015d0(param_3 + *(int*)((char*)self + 0x68) * -4);
    }
    if (*(int*)((char*)self + 0x10) != 0) {
        FUN_0060183d(param_3 + *(int*)((char*)self + 0x68) * -4);
    }
}

// 0x6086e5 — observed shape
// RGB10A2 unpack (low-to-high field order): R = (v&0x3ff),
// G = (v>>10)&0x3ff, B = (v>>20)&0x3ff, each *0.0009775171;
// A = (v>>30)*0.33333334. Source stepped per dword.
void FUN_006086e5(void* self, int param_1, int param_2, float* param_3) {
    uint32_t* puVar3 = (uint32_t*)(*(int*)((char*)self + 0x60) * param_1 +
                                  *(int*)((char*)self + 100) * param_2 +
                                  *(int*)((char*)self + 0x20));
    uint32_t* puVar1 = puVar3 + *(int*)((char*)self + 0x68);
    float* pfVar4 = param_3;
    if (puVar3 < puVar1) {
        do {
            *param_3 = (float)(*puVar3 & 0x3ff) * 0.0009775171f;
            param_3[1] = (float)(*puVar3 >> 10 & 0x3ff) * 0.0009775171f;
            param_3[2] = (float)(*puVar3 >> 0x14 & 0x3ff) * 0.0009775171f;
            uint32_t uVar2 = *puVar3;
            puVar3 = puVar3 + 1;
            pfVar4 = param_3 + 4;
            param_3[3] = (float)(uVar2 >> 0x1e) * 0.33333334f;
            param_3 = pfVar4;
        } while (puVar3 < puVar1);
    }
    if (*(int*)((char*)self + 0x18) != 0) {
        FUN_006015d0(pfVar4 + *(int*)((char*)self + 0x68) * -4);
    }
    if (*(int*)((char*)self + 0x10) != 0) {
        FUN_0060183d(pfVar4 + *(int*)((char*)self + 0x68) * -4);
    }
}

// 0x6087c7 — observed shape
// ARGB8888 unpack (dword little-endian bytes): R = (v&0xff),
// G = byte1, B = byte2, A = byte3, each *0.003921569.
void FUN_006087c7(void* self, int param_1, int param_2, float* param_3) {
    uint32_t* puVar2 = (uint32_t*)(*(int*)((char*)self + 0x60) * param_1 +
                                  *(int*)((char*)self + 100) * param_2 +
                                  *(int*)((char*)self + 0x20));
    uint32_t* puVar1 = puVar2 + *(int*)((char*)self + 0x68);
    float* pfVar4 = param_3;
    if (puVar2 < puVar1) {
        do {
            uint32_t* puVar3 = puVar2 + 1;
            *param_3 = (float)(*puVar2 & 0xff) * 0.003921569f;
            pfVar4 = param_3 + 4;
            param_3[1] = (float)*(uint8_t*)((char*)puVar2 + 1) * 0.003921569f;
            param_3[2] = (float)*(uint8_t*)((char*)puVar2 + 2) * 0.003921569f;
            param_3[3] = (float)*(uint8_t*)((char*)puVar2 + 3) * 0.003921569f;
            puVar2 = puVar3;
            param_3 = pfVar4;
        } while (puVar3 < puVar1);
    }
    if (*(int*)((char*)self + 0x18) != 0) {
        FUN_006015d0(pfVar4 + *(int*)((char*)self + 0x68) * -4);
    }
    if (*(int*)((char*)self + 0x10) != 0) {
        FUN_0060183d(pfVar4 + *(int*)((char*)self + 0x68) * -4);
    }
}

// 0x608879 — observed shape
// RGB888 opaque variant of 0x6087c7: R = (v&0xff), G = byte1, B = byte2,
// each *0.003921569, alpha forced to 1.0.
void FUN_00608879(void* self, int param_1, int param_2, float* param_3) {
    uint32_t* puVar2 = (uint32_t*)(*(int*)((char*)self + 0x60) * param_1 +
                                  *(int*)((char*)self + 100) * param_2 +
                                  *(int*)((char*)self + 0x20));
    uint32_t* puVar1 = puVar2 + *(int*)((char*)self + 0x68);
    float* pfVar4 = param_3;
    if (puVar2 < puVar1) {
        do {
            uint32_t* puVar3 = puVar2 + 1;
            *param_3 = (float)(*puVar2 & 0xff) * 0.003921569f;
            pfVar4 = param_3 + 4;
            param_3[1] = (float)*(uint8_t*)((char*)puVar2 + 1) * 0.003921569f;
            param_3[2] = (float)*(uint8_t*)((char*)puVar2 + 2) * 0.003921569f;
            param_3[3] = 1.0f;
            puVar2 = puVar3;
            param_3 = pfVar4;
        } while (puVar3 < puVar1);
    }
    if (*(int*)((char*)self + 0x18) != 0) {
        FUN_006015d0(pfVar4 + *(int*)((char*)self + 0x68) * -4);
    }
    if (*(int*)((char*)self + 0x10) != 0) {
        FUN_0060183d(pfVar4 + *(int*)((char*)self + 0x68) * -4);
    }
}

// 0x608921 — observed shape
// RG16 (two ushorts per pixel) unpack: R = (low16)*1.5259022e-05,
// G = (high16)*1.5259022e-05, B = 1.0, A = 1.0.
void FUN_00608921(void* self, int param_1, int param_2, float* param_3) {
    uint32_t* puVar2 = (uint32_t*)(*(int*)((char*)self + 0x60) * param_1 +
                                  *(int*)((char*)self + 100) * param_2 +
                                  *(int*)((char*)self + 0x20));
    uint32_t* puVar1 = puVar2 + *(int*)((char*)self + 0x68);
    float* pfVar4 = param_3;
    if (puVar2 < puVar1) {
        do {
            uint32_t* puVar3 = puVar2 + 1;
            *param_3 = (float)(*puVar2 & 0xffff) * 1.5259022e-05f;
            pfVar4 = param_3 + 4;
            param_3[1] = (float)*(uint16_t*)((char*)puVar2 + 2) * 1.5259022e-05f;
            param_3[2] = 1.0f;
            param_3[3] = 1.0f;
            puVar2 = puVar3;
            param_3 = pfVar4;
        } while (puVar3 < puVar1);
    }
    if (*(int*)((char*)self + 0x18) != 0) {
        FUN_006015d0(pfVar4 + *(int*)((char*)self + 0x68) * -4);
    }
    if (*(int*)((char*)self + 0x10) != 0) {
        FUN_0060183d(pfVar4 + *(int*)((char*)self + 0x68) * -4);
    }
}

// 0x6089bf — observed shape
// RGB10A2 unpack, swapped field order vs 0x6086e5: R = (v>>20)&0x3ff,
// G = (v>>10)&0x3ff, B = (v&0x3ff), each *0.0009775171;
// A = (v>>30)*0.33333334.
void FUN_006089bf(void* self, int param_1, int param_2, float* param_3) {
    uint32_t* puVar3 = (uint32_t*)(*(int*)((char*)self + 0x60) * param_1 +
                                  *(int*)((char*)self + 100) * param_2 +
                                  *(int*)((char*)self + 0x20));
    uint32_t* puVar1 = puVar3 + *(int*)((char*)self + 0x68);
    float* pfVar4 = param_3;
    if (puVar3 < puVar1) {
        do {
            *param_3 = (float)(*puVar3 >> 0x14 & 0x3ff) * 0.0009775171f;
            param_3[1] = (float)(*puVar3 >> 10 & 0x3ff) * 0.0009775171f;
            param_3[2] = (float)(*puVar3 & 0x3ff) * 0.0009775171f;
            uint32_t uVar2 = *puVar3;
            puVar3 = puVar3 + 1;
            pfVar4 = param_3 + 4;
            param_3[3] = (float)(uVar2 >> 0x1e) * 0.33333334f;
            param_3 = pfVar4;
        } while (puVar3 < puVar1);
    }
    if (*(int*)((char*)self + 0x18) != 0) {
        FUN_006015d0(pfVar4 + *(int*)((char*)self + 0x68) * -4);
    }
    if (*(int*)((char*)self + 0x10) != 0) {
        FUN_0060183d(pfVar4 + *(int*)((char*)self + 0x68) * -4);
    }
}

// NEEDS_MANUAL: the third channel of 0x608aa1 is produced by an
// `__aullshr()` intrinsic call with no visible operands in the listing
// (a 64-bit shift of the qword at source+4, extracting ushort index 0).
// The 8-byte stride, the surrounding low/high 16-bit reads and the
// trailing `+6` ushort read pin the layout to RGBA16 (4 x ushort);
// the channel below reads that qword's low ushort explicitly.
// 0x608aa1 — observed shape
// RGBA16 (4 x ushort = 8 bytes per pixel): each channel
// *1.5259022e-05. Row end is base + (+0x68)*2 dwords; source steps
// 2 dwords per pixel.
void FUN_00608aa1(void* self, int param_1, int param_2, float* param_3) {
    uint32_t* puVar3 = (uint32_t*)(*(int*)((char*)self + 0x60) * param_1 +
                                  *(int*)((char*)self + 100) * param_2 +
                                  *(int*)((char*)self + 0x20));
    uint32_t* puVar1 = puVar3 + *(int*)((char*)self + 0x68) * 2;
    for (; puVar3 < puVar1; puVar3 = puVar3 + 2) {
        *param_3 = (float)(*puVar3 & 0xffff) * 1.5259022e-05f;
        param_3[1] = (float)(*puVar3 >> 0x10) * 1.5259022e-05f;
        uint16_t uVar2 = *(uint16_t*)((char*)puVar3 + 4); // __aullshr() result in listing
        param_3[2] = (float)uVar2 * 1.5259022e-05f;
        param_3[3] = (float)*(uint16_t*)((char*)puVar3 + 6) * 1.5259022e-05f;
        param_3 = param_3 + 4;
    }
    if (*(int*)((char*)self + 0x18) != 0) {
        FUN_006015d0(param_3 + *(int*)((char*)self + 0x68) * -4);
    }
    if (*(int*)((char*)self + 0x10) != 0) {
        FUN_0060183d(param_3 + *(int*)((char*)self + 0x68) * -4);
    }
}

// 0x608b9b — observed shape
// Packed 8-bit RGB332: R = (byte>>5)*0.14285715, G = ((byte>>2)&7)*0.14285715,
// B = (byte&3)*0.33333334, alpha 1.0. One byte per pixel.
void FUN_00608b9b(void* self, int param_1, int param_2, float* param_3) {
    uint8_t* pbVar1 = (uint8_t*)(*(int*)((char*)self + 0x60) * param_1 +
                                *(int*)((char*)self + 100) * param_2 +
                                *(int*)((char*)self + 0x20));
    uint8_t* pbVar2 = pbVar1 + *(int*)((char*)self + 0x68);
    for (; pbVar1 < pbVar2; pbVar1 = pbVar1 + 1) {
        *param_3 = (float)(*pbVar1 >> 5) * 0.14285715f;
        param_3[1] = (float)(*pbVar1 >> 2 & 7) * 0.14285715f;
        param_3[2] = (float)(*pbVar1 & 3) * 0.33333334f;
        param_3[3] = 1.0f;
        param_3 = param_3 + 4;
    }
    if (*(int*)((char*)self + 0x18) != 0) {
        FUN_006015d0(param_3 + *(int*)((char*)self + 0x68) * -4);
    }
    if (*(int*)((char*)self + 0x10) != 0) {
        FUN_0060183d(param_3 + *(int*)((char*)self + 0x68) * -4);
    }
}

// 0x608c45 — observed shape
// Alpha-only (single byte per pixel) -> RGBA float with R=G=B=0 and
// A = (byte)*0.003921569.
void FUN_00608c45(void* self, int param_1, int param_2, float* param_3) {
    uint8_t* pbVar2 = (uint8_t*)(*(int*)((char*)self + 0x60) * param_1 +
                                *(int*)((char*)self + 100) * param_2 +
                                *(int*)((char*)self + 0x20));
    uint8_t* pbVar3 = pbVar2 + *(int*)((char*)self + 0x68);
    float* puVar4 = param_3;
    if (pbVar2 < pbVar3) {
        do {
            *param_3 = 0.0f;
            puVar4 = param_3 + 4;
            param_3[1] = 0.0f;
            param_3[2] = 0.0f;
            uint8_t bVar1 = *pbVar2;
            pbVar2 = pbVar2 + 1;
            param_3[3] = (float)bVar1 * 0.003921569f;
            param_3 = puVar4;
        } while (pbVar2 < pbVar3);
    }
    if (*(int*)((char*)self + 0x18) != 0) {
        FUN_006015d0(puVar4 + *(int*)((char*)self + 0x68) * -4);
    }
    if (*(int*)((char*)self + 0x10) != 0) {
        FUN_0060183d(puVar4 + *(int*)((char*)self + 0x68) * -4);
    }
}

// 0x608cc3 — observed shape
// RGB332 + separate 8-bit alpha: two bytes per pixel; colour decoded
// from the first byte as in 0x608b9b, alpha = second byte*0.003921569.
void FUN_00608cc3(void* self, int param_1, int param_2, float* param_3) {
    uint8_t* pbVar2 = (uint8_t*)(*(int*)((char*)self + 0x60) * param_1 +
                                *(int*)((char*)self + 100) * param_2 +
                                *(int*)((char*)self + 0x20));
    uint8_t* pbVar1 = pbVar2 + *(int*)((char*)self + 0x68) * 2;
    for (; pbVar2 < pbVar1; pbVar2 = pbVar2 + 2) {
        *param_3 = (float)(*pbVar2 >> 5) * 0.14285715f;
        param_3[1] = (float)(*pbVar2 >> 2 & 7) * 0.14285715f;
        param_3[2] = (float)(*pbVar2 & 3) * 0.33333334f;
        param_3[3] = (float)pbVar2[1] * 0.003921569f;
        param_3 = param_3 + 4;
    }
    if (*(int*)((char*)self + 0x18) != 0) {
        FUN_006015d0(param_3 + *(int*)((char*)self + 0x68) * -4);
    }
    if (*(int*)((char*)self + 0x10) != 0) {
        FUN_0060183d(param_3 + *(int*)((char*)self + 0x68) * -4);
    }
}
