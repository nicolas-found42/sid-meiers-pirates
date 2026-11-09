// Mass reconstruction batch mass_0311 — unverified decompiler-derived candidate.
// Target: Sid Meier's Pirates! (2004), PE32 i386.
// No compiler/test run. Correlated externally via observed pseudocode shapes.

#include <cstdint>
#include <cstddef>
#include <cmath>
#include <windows.h>

typedef unsigned char byte;
typedef uint16_t ushort;
typedef uint32_t undefined4;

// ---- extern globals observed in the listings ----
extern float DAT_006edec4[];   // low-end coefficient row (n != 6)
extern float DAT_006edee4[];   // high-end coefficient row (n != 6)
extern float DAT_006edf04[];   // low-end coefficient row (n == 6)
extern float DAT_006edf1c[];   // high-end coefficient row (n == 6)
extern float DAT_006edf3c[];   // second basis row (n != 1)
extern float DAT_006edf4c[];   // first basis row (n != 1)
extern float DAT_006edf5c[];   // second basis row (n == 1)
extern float DAT_006edf68[];   // first basis row (n == 1)
extern float DAT_0071fda8;
extern float DAT_0071fdac;
extern float DAT_0071fdb0;
extern float DAT_0071fdb4;
extern float _DAT_0071fdb8;
extern float _DAT_0071fdbc;
extern float _DAT_0071fdc0;
extern int DAT_006edf78[];     // code LUT, 4-entry palette
extern int DAT_006edf88[];     // code LUT, 3-entry palette
extern int DAT_006edf98[];     // code LUT, 8-entry ramp (inverse orientation)
extern int DAT_006edfb8[];     // code LUT, 6-entry ramp
extern void *PTR_FUN_006edfd0; // vtable-style function pointer table head

// ---- extern helpers observed in the listings ----
extern void FUN_00658b49(float *rgba); // fills a caller-resident RGBA color from a register-selected entry
extern int FUN_00658b97(void);
extern int FUN_00658c1b(void *dst256);

// ---- forward declarations for functions defined below ----
uint32_t FUN_00658c4b(void *self);
void FUN_00658d4e(float *param_1, float *param_2, const float *param_3, uint32_t param_4);
void FUN_00659075(float *param_1, float *param_2, const float *param_3, float param_4);
int FUN_006595f5(void *points, ushort *param_1, float param_2, int param_3);
uint32_t FUN_00659f48(float *param_1, ushort *param_2);
int FUN_0065a08a(int param_1, uint32_t *param_2);
int FUN_0065a10f(int param_1, byte *param_2);
int FUN_0065a24d(void *param_1, int param_2, int param_3);
void FUN_0065a371(undefined4 *param_1, int param_2, int param_3);
int FUN_0065a4a0(char *param_1, float param_2, int param_3);

static inline int ROUNDf(float v) { return (int)std::floor(v + 0.5f); }

// ---------------------------------------------------------------------------
// 0x658c4b — observed shape
// ---------------------------------------------------------------------------
// in_ECX is the receiver (a float[3] RGB triple); the packing matches the
// 5:6:5 layout produced by the later color functions.
uint FUN_00658c4b(void *self)
{
  float *v = (float *)self;
  float local_20;
  float local_1c;
  float local_18;

  if (0.0f <= v[0]) {
    if (1.0f < v[0]) {
      local_20 = 1.0f;
    }
    else {
      local_20 = v[0];
    }
  }
  else {
    local_20 = 0.0f;
  }
  if (0.0f <= v[1]) {
    if (1.0f < v[1]) {
      local_1c = 1.0f;
    }
    else {
      local_1c = v[1];
    }
  }
  else {
    local_1c = 0.0f;
  }
  if (0.0f <= v[2]) {
    if (v[2] <= 1.0f) {
      local_18 = v[2];
    }
    else {
      local_18 = 1.0f;
    }
  }
  else {
    local_18 = 0.0f;
  }
  return ((uint)ROUNDf(local_20 * 31.0f + 0.5f) << 6 | (uint)ROUNDf(local_1c * 63.0f + 0.5f)) << 5 |
         (uint)ROUNDf(local_18 * 31.0f + 0.5f);
}

// ---------------------------------------------------------------------------
// 0x658d4e — observed shape
// ---------------------------------------------------------------------------
// Fits two scalar endpoints (out-low / out-high) to a 16-sample channel set by
// alternating least squares. param_4 selects 6- or 8-entry basis rows
// (6 => DAT_006edf1c/DAT_006edf04, otherwise DAT_006edee4/DAT_006edec4).
void FUN_00658d4e(float *param_1,float *param_2,const float *param_3,uint32_t param_4)
{
  float *pfVar6;
  float *pfVarB;
  uint32_t uVar4;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_58[8];
  float local_2c;
  float local_28;
  float local_34;
  uint32_t local_24;

  if (param_4 == 6) {
    pfVar6 = DAT_006edf1c;
    pfVarB = DAT_006edf04;
  }
  else {
    pfVar6 = DAT_006edee4;
    pfVarB = DAT_006edec4;
  }
  uVar4 = 0;
  local_8 = 1.0f;
  local_c = 0.0f;
  if (param_4 == 8) {
    do {
      const float *pfVar3 = param_3 + uVar4;
      if (*pfVar3 < local_8) {
        local_8 = *pfVar3;
      }
      if (local_c < *pfVar3) {
        local_c = *pfVar3;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x10);
  }
  else {
    do {
      const float *pfVar3 = param_3 + uVar4;
      if ((*pfVar3 < local_8) && (0.0f < *pfVar3)) {
        local_8 = *pfVar3;
      }
      if ((local_c < *pfVar3) && (*pfVar3 < 1.0f)) {
        local_c = *pfVar3;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x10);
    if (local_8 == local_c) {
      local_c = 1.0f;
    }
  }
  uVar4 = param_4 - 1;
  local_28 = (float)(int)uVar4;
  if ((int)uVar4 < 0) {
    local_28 = local_28 + 4.2949673e+09f;
  }
  local_24 = 0;
  while (0.00390625f <= local_c - local_8) {
    local_2c = local_28 / (local_c - local_8);
    if (param_4 != 0) {
      uint32_t uVar7 = param_4;
      for (uint32_t i = 0; i < uVar7; i++) {
        local_58[i] = local_8 * pfVar6[i] + local_c * pfVarB[i];
      }
    }
    if (param_4 == 6) {
      local_58[6] = 0.0f;          // observed as the two words after the 6-entry blend
      local_58[7] = 1.0f;
    }
    local_10 = 0.0f;
    local_14 = 0.0f;
    local_18 = 0.0f;
    local_1c = 0.0f;
    for (uint32_t uVar7 = 0; uVar7 < 0x10; uVar7++) {
      const float *pfVar3 = param_3 + uVar7;
      float fVar1 = (*pfVar3 - local_8) * local_2c;
      bool skip = false;
      uint32_t local_34;
      if (!(fVar1 >= 0.0f)) {
        if (fVar1 < local_28) {
          local_34 = (uint32_t)ROUNDf(fVar1 + 0.5f);
        }
        else {
          if (param_4 == 6) {
            float fVar2 = (local_c + 1.0f) * 0.5f;
            if (fVar2 < *pfVar3) {
              skip = true;                      // LAB_00658f79
            }
          }
          if (!skip) {
            local_34 = uVar4;
          }
        }
      }
      else if ((param_4 != 6) || (local_8 * 0.5f < *pfVar3)) {
        local_34 = 0;
      }
      else {
        skip = true;
      }
      if (!skip) {
        if (local_34 < param_4) {
          local_10 = (*pfVar3 - local_58[local_34]) * pfVar6[local_34] + local_10;
          local_18 = pfVar6[local_34] * pfVar6[local_34] + local_18;
          local_14 = (*pfVar3 - local_58[local_34]) * pfVarB[local_34] + local_14;
          float fVar1b = pfVarB[local_34];
          local_1c = fVar1b * fVar1b + local_1c;
        }
      }
    }
    if (0.0f < local_18) {
      local_8 = local_8 - local_10 / local_18;
    }
    if (0.0f < local_1c) {
      local_c = local_c - local_14 / local_1c;
    }
    float fVar1c = local_c;
    if (local_c < local_8) {
      local_c = local_8;
      local_8 = fVar1c;
    }
    if (((local_10 * local_10 < 0.015625f) && (local_14 * local_14 < 0.015625f)) ||
        (local_24 = local_24 + 1, 7 < local_24)) break;
  }
  if (0.0f <= local_8) {
    if (1.0f < local_8) {
      local_8 = 1.0f;
    }
  }
  else {
    local_8 = 0.0f;
  }
  *param_1 = local_8;
  if (0.0f <= local_c) {
    if (1.0f < local_c) {
      local_c = 1.0f;
    }
  }
  else {
    local_c = 0.0f;
  }
  *param_2 = local_c;
  return;
}

// ---------------------------------------------------------------------------
// 0x659075 — observed shape
// ---------------------------------------------------------------------------
// Two-endpoint palette fit over a 16-point cloud: principal-axis score over four
// sign combinations, then up to eight Gauss-Newton refinement passes using the
// 6/8-entry basis rows selected by param_4 (the listing compares the float
// against denormal 4.2039e-45f, i.e. the integer pattern 1).
void FUN_00659075(float *param_1,float *param_2,const float *param_3,float param_4)
{
  int iVar10 = (int)param_4;
  float *pfA;
  float *pfB;
  float minv[3];
  float maxv[3];
  float ext[3];
  float len2;
  float rot[32];

  if (param_4 == 4.2039e-45f) {         // denormal literals compare against bit pattern 1
    pfA = DAT_006edf68;
    pfB = DAT_006edf5c;
  }
  else {
    pfA = DAT_006edf4c;
    pfB = DAT_006edf3c;
  }
  maxv[0] = 0.0f;
  maxv[1] = 0.0f;
  maxv[2] = 0.0f;
  minv[0] = DAT_0071fda8;
  minv[1] = DAT_0071fdac;
  minv[2] = DAT_0071fdb0;

  for (int i = 0; i < 0x10; i++) {
    const float *pfVar12 = param_3 + i * 4;
    if (pfVar12[0] < minv[0]) minv[0] = pfVar12[0];
    if (pfVar12[1] < minv[1]) minv[1] = pfVar12[1];
    if (pfVar12[2] < minv[2]) minv[2] = pfVar12[2];
    if (maxv[0] < pfVar12[0]) maxv[0] = pfVar12[0];
    if (maxv[1] < pfVar12[1]) maxv[1] = pfVar12[1];
    if (maxv[2] < pfVar12[2]) maxv[2] = pfVar12[2];
  }

  ext[0] = maxv[0] - minv[0];
  ext[1] = maxv[1] - minv[1];
  ext[2] = maxv[2] - minv[2];
  len2 = ext[0] * ext[0] + ext[1] * ext[1] + ext[2] * ext[2];

  if (1.1754944e-38f <= len2) {
    float fVar7 = 1.0f / len2;
    float cx = (maxv[0] + minv[0]) * 0.5f;
    float cy = (maxv[1] + minv[1]) * 0.5f;
    float cz = (maxv[2] + minv[2]) * 0.5f;
    float score[4] = {0.0f, 0.0f, 0.0f, 0.0f};

    for (int i = 0; i < 0x10; i++) {
      const float *pfVar12 = param_3 + i * 4;
      float local_44 = (pfVar12[0] - cx) * ext[0] * fVar7;
      float local_40 = (pfVar12[1] - cy) * ext[1] * fVar7;
      float fVar2 = (pfVar12[2] - cz) * fVar7 * ext[2];
      float fVar8 = local_40 + fVar2 + local_44;
      score[0] = fVar8 * fVar8 + score[0];
      fVar8 = (local_40 + local_44) - fVar2;
      score[1] = fVar8 * fVar8 + score[1];
      fVar8 = (local_44 - local_40) + fVar2;
      score[2] = fVar8 * fVar8 + score[2];
      fVar2 = (local_44 - local_40) - fVar2;
      score[3] = fVar2 * fVar2 + score[3];
    }
    uint32_t uVar16 = 0;
    for (uint32_t uVar14 = 1; uVar14 < 4; uVar14++) {
      if (score[0] < score[uVar14]) {
        score[0] = score[uVar14];
        uVar16 = uVar14;
      }
    }
    float fVar3 = minv[1];   // per-iteration capture of the current y minimum
    float fVar9 = maxv[2];   // per-iteration capture of the current z maximum
    if ((uVar16 & 2) != 0) {
      minv[1] = maxv[1];
      maxv[1] = fVar3;
    }
    if ((uVar16 & 1) != 0) {
      maxv[2] = minv[2];
      minv[2] = fVar9;
    }

    if (0.00024414062f <= len2) {
      float nMinus1 = (float)(int)(param_4 - 1.0f);
      if ((int)(param_4 - 1.0f) < 0) {
        nMinus1 = nMinus1 + 4.2949673e+09f;
      }
      uint32_t local_64 = 0;
      while (true) {
        for (int i = 0; i < iVar10; i++) {
          rot[i * 4 + 0] = maxv[0] * pfB[i] + minv[0] * pfA[i];
          rot[i * 4 + 1] = maxv[1] * pfB[i] + minv[1] * pfA[i];
          rot[i * 4 + 2] = maxv[2] * pfB[i] + minv[2] * pfA[i];
        }
        float ex = maxv[0] - minv[0];
        float ey = maxv[1] - minv[1];
        float ez = maxv[2] - minv[2];
        float fVar9b = ex * ex + ey * ey + ez * ez;
        if (fVar9b < 0.00024414062f) break;
        float fVar9c = nMinus1 / fVar9b;
        float local_44 = fVar9c * ex;
        float local_40 = ey * fVar9c;
        float local_3c = fVar9c * ez;
        float local_54 = 0.0f;
        float local_50 = 0.0f;
        float local_4c = 0.0f;
        float accA = 0.0f;
        float accB = 0.0f;
        float sumBx = 0.0f;
        float sumBy = 0.0f;
        float sumBz = 0.0f;
        float sumAx = 0.0f;
        float sumAy = 0.0f;
        float sumAz = 0.0f;
        for (int i = 0; i < 0x10; i++) {
          const float *pfVar17 = param_3 + i * 4;
          float fVar4 = (pfVar17[0] - minv[0]) * fVar9c * ex +
                        (pfVar17[1] - minv[1]) * fVar9c * ey +
                        (pfVar17[2] - minv[2]) * ez * fVar9c;
          uint32_t local_84;
          if (fVar4 < nMinus1) {
            local_84 = (uint32_t)ROUNDf(fVar4 + 0.5f);
          }
          else {
            local_84 = (uint32_t)(iVar10 + -1);
          }
          float local_74 = rot[local_84 * 4 + 1] - pfVar17[1];
          float fVar7b = pfA[local_84] * 0.125f;
          float fVar2b = pfB[local_84] * 0.125f;
          accA = fVar7b * pfA[local_84] + accA;
          sumAx = fVar7b * (rot[local_84 * 4 + 0] - pfVar17[0]) + sumAx;
          sumAy = fVar7b * local_74 + sumAy;
          sumAz = fVar7b * (rot[local_84 * 4 + 2] - pfVar17[2]) + sumAz;
          accB = fVar2b * pfB[local_84] + accB;
          sumBx = fVar2b * (rot[local_84 * 4 + 0] - pfVar17[0]) + sumBx;
          sumBy = local_74 * fVar2b + sumBy;
          sumBz = fVar2b * (rot[local_84 * 4 + 2] - pfVar17[2]) + sumBz;
        }
        local_54 = sumAx;
        local_50 = sumAy;
        local_4c = sumAz;
        if (0.0f < accA) {
          accA = -1.0f / accA;
          minv[0] = local_54 * accA + minv[0];
          minv[1] = local_50 * accA + minv[1];
          minv[2] = accA * local_4c + minv[2];
        }
        if (0.0f < accB) {
          accB = -1.0f / accB;
          maxv[0] = sumBx * accB + maxv[0];
          maxv[1] = sumBy * accB + maxv[1];
          maxv[2] = accB * sumBz + maxv[2];
        }
        if (((((local_54 * local_54 < 1.5258789e-05f) && (local_50 * local_50 < 1.5258789e-05f)) &&
              (local_4c * local_4c < 1.5258789e-05f)) &&
             (((sumBx * sumBx < 1.5258789e-05f &&
                (sumBy * sumBy < 1.5258789e-05f)) &&
               (sumBz * sumBz < 1.5258789e-05f)))) ||
            (local_64 = local_64 + 1, 7 < local_64)) break;
      }
      *param_1 = minv[0];
      param_1[1] = minv[1];
      param_1[2] = minv[2];
      *param_2 = maxv[0];
      param_2[1] = maxv[1];
    }
    else {
      *param_1 = minv[0];
      param_1[1] = minv[1];
      param_1[2] = minv[2];
      param_2[1] = maxv[1];
      *param_2 = maxv[0];
    }
  }
  else {
    *param_1 = minv[0];
    param_1[1] = minv[1];
    param_1[2] = minv[2];
    param_2[1] = maxv[1];
    *param_2 = maxv[0];
  }
  param_2[2] = maxv[2];
  return;
}

// ---------------------------------------------------------------------------
// 0x6595f5 — observed shape
// ---------------------------------------------------------------------------
// Converts a 16-point (4-float stride) color cloud into a packed palette-index
// word. The diffusion taps live in one overlapping stack frame in the listing;
// they are modelled here as per-channel error arrays with the same Floyd-
// Steinberg weights (7/16, 3/16, 5/16, 1/16) and edge guards.
int FUN_006595f5(void *points,ushort *param_1,float param_2,int param_3)
{
  const float *pts = (const float *)points;
  int n;
  float work[64];
  float eX[21] = {0.0f};
  float eY[21] = {0.0f};
  float eZ[21] = {0.0f};
  float mn[4] = {0.0f, 0.0f, 0.0f, 0.0f};
  float mx[4] = {0.0f, 0.0f, 0.0f, 0.0f};

  if (param_2 == 0.0f) {
    n = 4;
  }
  else {
    int under = 0;
    for (int i = 0; i < 0x10; i++) {
      if (pts[i * 4 + 3] < 0.5f) under++;
    }
    if (under == 0x10) {
      param_1[1] = 0xffff;
      param_1[2] = 0xffff;
      param_1[3] = 0xffff;
      param_1[0] = 0;
      return 0;
    }
    n = 4 - (under != 0);
  }
  if (param_3 != 0) {
    for (int i = 0; i < 21; i++) {
      eX[i] = 0.0f;
      eY[i] = 0.0f;
      eZ[i] = 0.0f;
    }
  }
  for (int i = 0; i < 0x10; i++) {
    float local_1c = pts[i * 4 + 0];
    float local_18 = pts[i * 4 + 1];
    float local_14 = pts[i * 4 + 2];
    if (param_3 != 0) {
      local_1c = local_1c + eX[i];
      local_18 = local_18 + eY[i];
      local_14 = local_14 + eZ[i];
    }
    float qx = (float)ROUNDf(local_1c * 31.0f + 0.5f);
    float local_20 = qx * 0.032258064f;
    float qy = (float)ROUNDf(local_18 * 63.0f + 0.5f);
    float local_8 = qy * 0.015873017f;
    float qz = (float)ROUNDf(local_14 * 31.0f + 0.5f);
    float fVar3 = qz * 0.032258064f;
    work[i * 4 + 0] = local_20 * DAT_0071fda8;
    work[i * 4 + 1] = local_8 * DAT_0071fdac;
    work[i * 4 + 2] = fVar3 * DAT_0071fdb0;
    work[i * 4 + 3] = 1.0f;
    if (param_3 != 0) {
      float fVar1 = local_1c - local_20;
      float fVar2 = local_18 - local_8;
      float fVar4 = local_14 - fVar3;
      uint32_t uVar11 = (uint32_t)i & 3;
      if (uVar11 != 3) {
        eX[i + 1] = fVar1 * 0.4375f + eX[i + 1];
        eY[i + 1] = fVar2 * 0.4375f + eY[i + 1];
        eZ[i + 1] = fVar4 * 0.4375f + eZ[i + 1];
      }
      if (i < 0xc) {
        if (uVar11 != 0) {
          eX[i + 3] = fVar1 * 0.1875f + eX[i + 3];
          eY[i + 3] = fVar2 * 0.1875f + eY[i + 3];
          eZ[i + 3] = fVar4 * 0.1875f + eZ[i + 3];
        }
        eX[i + 4] = fVar1 * 0.3125f + eX[i + 4];
        eY[i + 4] = fVar2 * 0.3125f + eY[i + 4];
        eZ[i + 4] = fVar4 * 0.3125f + eZ[i + 4];
        if (uVar11 != 3) {
          eX[i + 5] = fVar1 * 0.0625f + eX[i + 5];
          eY[i + 5] = fVar2 * 0.0625f + eY[i + 5];
          eZ[i + 5] = fVar4 * 0.0625f + eZ[i + 5];
        }
      }
    }
  }
  FUN_00659075(mn, mx, work, (float)n);
  float local_dc = mn[0] * _DAT_0071fdb8;
  float local_d8 = mn[1] * _DAT_0071fdbc;
  float local_d4 = mn[2] * _DAT_0071fdc0;
  float local_44 = mx[0] * _DAT_0071fdb8;
  float local_40 = mx[1] * _DAT_0071fdbc;
  float local_3c = mx[2] * _DAT_0071fdc0;
  uint uVar6 = FUN_00658c4b(mn);
  uint uVar7 = FUN_00658c4b(mx);
  ushort uVar10 = (ushort)uVar6;
  ushort uVar13 = (ushort)uVar7;
  if ((n == 4) && (uVar10 == uVar13)) {
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[0] = uVar10;
    param_1[1] = uVar13;
    return 0;
  }
  {
    float colTmpA[4];
    float colTmpB[4];
    float sc[4];
    float ec[4];
    float ramp[4][4];
    int *lut;

    FUN_00658b49(colTmpA);
    FUN_00658b49(colTmpB);
    mn[0] = local_dc * DAT_0071fda8;
    mn[1] = local_d8 * DAT_0071fdac;
    mn[2] = local_d4 * DAT_0071fdb0;
    mx[0] = local_44 * DAT_0071fda8;
    mx[1] = local_40 * DAT_0071fdac;
    mx[2] = local_3c * DAT_0071fdb0;
    // the listing leaves the fourth component of both endpoints uninitialized
    // on the stack (fStack_10 / fStack_48); it is carried as 0.0f here.
    if ((n == 3) == (uVar10 <= uVar13)) {
      param_1[0] = uVar10;
      param_1[1] = uVar13;
      sc[0] = mn[0]; sc[1] = mn[1]; sc[2] = mn[2]; sc[3] = 0.0f;
      ec[0] = mx[0]; ec[1] = mx[1]; ec[2] = mx[2]; ec[3] = 0.0f;
    }
    else {
      param_1[1] = uVar10;
      param_1[0] = uVar13;
      sc[0] = mx[0]; sc[1] = mx[1]; sc[2] = mx[2]; sc[3] = 0.0f;
      ec[0] = mn[0]; ec[1] = mn[1]; ec[2] = mn[2]; ec[3] = 0.0f;
    }
    for (int c = 0; c < 4; c++) {
      ramp[0][c] = sc[c];
      ramp[3][c] = ec[c];
    }
    if (n == 3) {
      lut = DAT_006edf88;
      for (int c = 0; c < 4; c++) {
        ramp[1][c] = (ec[c] - sc[c]) * 0.5f + sc[c];
        ramp[2][c] = ec[c];
      }
    }
    else {
      lut = DAT_006edf78;
      for (int c = 0; c < 4; c++) {
        ramp[1][c] = (ec[c] - sc[c]) * 0.33333334f + sc[c];
        ramp[2][c] = (ec[c] - sc[c]) * 0.6666667f + sc[c];
      }
    }
    float dX = ec[0] - sc[0];
    float dY = ec[1] - sc[1];
    float dZ = ec[2] - sc[2];
    float nMinus1 = (float)(n - 1);
    float step;
    if ((short)uVar10 == (short)uVar13) {
      step = 0.0f;
    }
    else {
      step = nMinus1 / (dX * dX + dY * dY + dZ * dZ);
    }
    float deltaX = dX * step;
    float deltaY = step * dY;
    float deltaZ = step * dZ;
    if (param_3 != 0) {
      for (int i = 0; i < 21; i++) {
        eX[i] = 0.0f;
        eY[i] = 0.0f;
        eZ[i] = 0.0f;
      }
    }
    uint32_t acc = 0;
    for (int i = 0; i < 0x10; i++) {
      if ((n != 3) || (0.5f <= pts[i * 4 + 3])) {
        float local_1c = DAT_0071fda8 * pts[i * 4 + 0];
        float local_18 = DAT_0071fdac * pts[i * 4 + 1];
        float local_14 = DAT_0071fdb0 * pts[i * 4 + 2];
        if (param_3 != 0) {
          local_1c = DAT_0071fda8 * pts[i * 4 + 0] + eX[i];
          local_18 = DAT_0071fdac * pts[i * 4 + 1] + eY[i];
          local_14 = DAT_0071fdb0 * pts[i * 4 + 2] + eZ[i];
        }
        float fVar1 = (local_1c - sc[0]) * deltaX +
                      (local_18 - sc[1]) * deltaY + (local_14 - sc[2]) * deltaZ;
        int iVar7;
        if (!(fVar1 >= 0.0f)) {
          if (fVar1 < nMinus1) {
            int local_60 = ROUNDf(fVar1 + 0.5f);
            iVar7 = lut[local_60];
          }
          else {
            iVar7 = 1;
          }
        }
        else {
          iVar7 = 0;
        }
        acc = (uint32_t)((uint32_t)iVar7 << 0x1e) | (acc >> 2);
        if (param_3 != 0) {
          uint32_t uVar12 = (uint32_t)i & 3;
          float wgt = work[i * 4 + 3];
          float fVar1b = (local_1c - ramp[iVar7][0]) * wgt;
          float fVar2 = (local_18 - ramp[iVar7][1]) * wgt;
          float fVar3 = (local_14 - ramp[iVar7][2]) * wgt;
          if (uVar12 != 3) {
            eX[i + 1] = fVar1b * 0.4375f + eX[i + 1];
            eY[i + 1] = fVar2 * 0.4375f + eY[i + 1];
            eZ[i + 1] = fVar3 * 0.4375f + eZ[i + 1];
          }
          if (i < 0xc) {
            if (uVar12 != 0) {
              eX[i + 3] = fVar1b * 0.1875f + eX[i + 3];
              eY[i + 3] = fVar2 * 0.1875f + eY[i + 3];
              eZ[i + 3] = fVar3 * 0.1875f + eZ[i + 3];
            }
            eX[i + 4] = fVar1b * 0.3125f + eX[i + 4];
            eY[i + 4] = fVar2 * 0.3125f + eY[i + 4];
            eZ[i + 4] = fVar3 * 0.3125f + eZ[i + 4];
            if (uVar12 != 3) {
              eX[i + 5] = fVar1b * 0.0625f + eX[i + 5];
              eY[i + 5] = fVar2 * 0.0625f + eY[i + 5];
              eZ[i + 5] = fVar3 * 0.0625f + eZ[i + 5];
            }
          }
        }
      }
      else {
        acc = (acc >> 2) | 0xc0000000u;
      }
    }
    *(uint32_t *)(param_1 + 2) = acc;
  }
  return 0;
}

// ---------------------------------------------------------------------------
// 0x659f48 — observed shape
// ---------------------------------------------------------------------------
// Expands 16 two-bit palette codes into 16 RGBA float quads. Entry order in the
// observed 16-byte-stride palette is {A, B, A+d/3, A+2d/3} (or {A, B, A+d/2, 0}).
uint32_t FUN_00659f48(float *param_1,ushort *param_2)
{
  ushort uVar2 = param_2[0];
  ushort uVar3;
  float pal[4][4];

  FUN_00658b49(pal[0]);
  uVar3 = param_2[1];
  FUN_00658b49(pal[1]);

  if (uVar3 < uVar2) {
    pal[2][0] = (pal[1][0] - pal[0][0]) * 0.33333334f + pal[0][0];
    pal[2][1] = (pal[1][1] - pal[0][1]) * 0.33333334f + pal[0][1];
    pal[2][2] = (pal[1][2] - pal[0][2]) * 0.33333334f + pal[0][2];
    pal[2][3] = (pal[1][3] - pal[0][3]) * 0.33333334f + pal[0][3];
    pal[3][0] = (pal[1][0] - pal[0][0]) * 0.6666667f + pal[0][0];
    pal[3][1] = (pal[1][1] - pal[0][1]) * 0.6666667f + pal[0][1];
    pal[3][2] = (pal[1][2] - pal[0][2]) * 0.6666667f + pal[0][2];
    pal[3][3] = (pal[1][3] - pal[0][3]) * 0.6666667f + pal[0][3];
  }
  else {
    pal[2][0] = (pal[1][0] - pal[0][0]) * 0.5f + pal[0][0];
    pal[2][1] = (pal[1][1] - pal[0][1]) * 0.5f + pal[0][1];
    pal[2][2] = (pal[1][2] - pal[0][2]) * 0.5f + pal[0][2];
    pal[2][3] = (pal[1][3] - pal[0][3]) * 0.5f + pal[0][3];
    pal[3][0] = 0.0f;
    pal[3][1] = 0.0f;
    pal[3][2] = 0.0f;
    pal[3][3] = 0.0f;
  }
  uint32_t uVar6 = *(uint32_t *)(param_2 + 2);
  for (int iVar4 = 0; iVar4 < 0x10; iVar4++) {
    uint32_t uVar5 = uVar6 & 3;
    *param_1 = pal[uVar5][0];
    param_1[1] = pal[uVar5][1];
    param_1[2] = pal[uVar5][2];
    param_1[3] = pal[uVar5][3];
    param_1 = param_1 + 4;
    uVar6 = uVar6 >> 2;
  }
  return 0;
}

// ---------------------------------------------------------------------------
// 0x65a08a — observed shape
// ---------------------------------------------------------------------------
// Expands two 32-bit words of 4-bit intensity codes into the fourth float of
// each of the 16 point records (0xc + 16*i, second half at 0x8c + 16*i).
int FUN_0065a08a(int param_1,uint32_t *param_2)
{
  int iVar1 = (int)FUN_00659f48((float *)param_1, (ushort *)(param_2 + 2));
  if (-1 < iVar1) {
    uint32_t uVar3 = *param_2;
    float *pfVar2 = (float *)(param_1 + 0xc);
    for (int iVar1b = 0; iVar1b < 8; iVar1b++) {
      uint32_t uVar4 = uVar3 & 0xf;
      uVar3 = uVar3 >> 4;
      *pfVar2 = (float)uVar4 * 0.06666667f;
      pfVar2 = pfVar2 + 4;
    }
    uVar3 = param_2[1];
    pfVar2 = (float *)(param_1 + 0x8c);
    for (int iVar1c = 0; iVar1c < 8; iVar1c++) {
      uint32_t uVar4 = uVar3 & 0xf;
      uVar3 = uVar3 >> 4;
      *pfVar2 = (float)uVar4 * 0.06666667f;
      pfVar2 = pfVar2 + 4;
    }
    iVar1 = 0;
  }
  return iVar1;
}

// ---------------------------------------------------------------------------
// 0x65a10f — observed shape
// ---------------------------------------------------------------------------
// Builds an 8-entry intensity ramp from two endpoint bytes, then expands two
// 24-bit fields of 3-bit codes into the fourth float of each point record.
int FUN_0065a10f(int param_1,byte *param_2)
{
  float local_24[8];
  int iVar3 = (int)FUN_00659f48((float *)param_1, (ushort *)(param_2 + 8));
  if (-1 < iVar3) {
    local_24[0] = (float)*param_2 * 0.003921569f;
    local_24[1] = (float)param_2[1] * 0.003921569f;
    if (param_2[1] < *param_2) {
      uint32_t uVar4 = 1;
      do {
        float fVar1 = (float)(int)(7 - uVar4);
        if ((int)(7 - uVar4) < 0) {
          fVar1 = fVar1 + 4.2949673e+09f;
        }
        float fVar2 = (float)(int)uVar4;
        if ((int)uVar4 < 0) {
          fVar2 = fVar2 + 4.2949673e+09f;
        }
        uVar4 = uVar4 + 1;
        local_24[uVar4] = (fVar2 * local_24[1] + fVar1 * local_24[0]) * 0.14285715f;
      } while (uVar4 < 7);
    }
    else {
      uint32_t uVar4 = 1;
      do {
        float fVar1 = (float)(int)(5 - uVar4);
        if ((int)(5 - uVar4) < 0) {
          fVar1 = fVar1 + 4.2949673e+09f;
        }
        float fVar2 = (float)(int)uVar4;
        if ((int)uVar4 < 0) {
          fVar2 = fVar2 + 4.2949673e+09f;
        }
        uVar4 = uVar4 + 1;
        local_24[uVar4] = (fVar2 * local_24[1] + fVar1 * local_24[0]) * 0.2f;
      } while (uVar4 < 5);
      local_24[6] = 0.0f;
      local_24[7] = 1.0f;
    }
    uint32_t uVar4 = *(const uint32_t *)(const void *)(param_2 + 2) & 0xffffffu;
    float *pfVar5 = (float *)(param_1 + 0xc);
    for (int i = 0; i < 8; i++) {
      uint32_t uVar6 = uVar4 & 7;
      uVar4 = uVar4 >> 3;
      *pfVar5 = local_24[uVar6];
      pfVar5 = pfVar5 + 4;
    }
    uVar4 = *(const uint32_t *)(const void *)(param_2 + 5) & 0xffffffu;
    pfVar5 = (float *)(param_1 + 0x8c);
    for (int i = 0; i < 8; i++) {
      uint32_t uVar6 = uVar4 & 7;
      uVar4 = uVar4 >> 3;
      *pfVar5 = local_24[uVar6];
      pfVar5 = pfVar5 + 4;
    }
    iVar3 = 0;
  }
  return iVar3;
}

// ---------------------------------------------------------------------------
// 0x65a24d — observed shape
// ---------------------------------------------------------------------------
// Copies 16 point records into a local (x,y,z) workspace while Floyd-Steinberg
// quantizing the fourth component to integers, then packs the palette indices.
int FUN_0065a24d(void *param_1,int param_2,int param_3)
{
  float local_150[64] = {0.0f};   // listing leaves this uninitialized when param_3 == 0
  float local_50[21] = {0.0f};

  if (param_3 != 0) {
    for (int i = 0; i < 0x10; i++) {
      local_50[i] = 0.0f;
    }
    const float *pfVar4 = (const float *)(param_2 + 0xc);
    for (int i = 0; i < 0x10; i++) {
      float fVar2 = local_50[i];
      local_150[i * 4 + 0] = pfVar4[-3 + i * 4];
      float fVar3 = pfVar4[-2 + i * 4];
      local_150[i * 4 + 1] = pfVar4[-2 + i * 4];
      local_150[i * 4 + 2] = pfVar4[-1 + i * 4];
      float local_8 = fVar2 + pfVar4[i * 4];
      uint32_t local_c = (uint32_t)ROUNDf(fVar2 + pfVar4[i * 4] + 0.5f);
      float fVar2b = (float)(int)local_c;
      local_150[i * 4 + 3] = fVar2b;
      float fVar2c = local_8 - fVar2b;
      uint32_t uVar1 = (uint32_t)i & 3;
      if (uVar1 != 3) {
        local_50[i + 1] = fVar2c * 0.4375f + local_50[i + 1];
      }
      if (i < 0xc) {
        if (uVar1 != 0) {
          local_50[i + 3] = fVar2c * 0.1875f + local_50[i + 3];
        }
        local_50[i + 4] = fVar2c * 0.3125f + local_50[i + 4];
        if (uVar1 != 3) {
          local_50[i + 5] = fVar2c * 0.0625f + local_50[i + 5];
        }
      }
      (void)fVar3;
    }
  }
  int iVar5 = FUN_006595f5(local_150, (ushort *)param_1, 1.0f, param_3);
  if (-1 < iVar5) {
    iVar5 = 0;
  }
  return iVar5;
}

// ---------------------------------------------------------------------------
// 0x65a371 — observed shape
// ---------------------------------------------------------------------------
// Quantizes 16 fourth-component samples to 4-bit codes (MSB-first nibble packing
// into two dwords), with Floyd-Steinberg error diffusion, then packs the palette
// indices at param_1+8.
void FUN_0065a371(undefined4 *param_1,int param_2,int param_3)
{
  uint32_t *puVar3 = (uint32_t *)param_1;
  float local_54[21] = {0.0f};
  uint32_t uVar5 = 0;

  puVar3[0] = 0;
  puVar3[1] = 0;
  if (param_3 != 0) {
    for (int i = 0; i < 0x10; i++) {
      local_54[i] = 0.0f;
    }
  }
  const float *local_8 = (const float *)(param_2 + 0xc);
  do {
    float value = local_8[uVar5 * 4];
    if (param_3 != 0) {
      value = value + local_54[uVar5];
    }
    float local_c = value * 15.0f + 0.5f;
    int local_10 = ROUNDf(local_c);
    uint32_t *puVar1 = puVar3 + (uVar5 >> 3);
    *puVar1 = *puVar1 >> 4 | (uint32_t)local_10 << 0x1c;
    if (param_3 != 0) {
      float fVar2 = (float)local_10;
      if (local_10 < 0) {
        fVar2 = fVar2 + 4.2949673e+09f;
      }
      uint32_t uVar6 = uVar5 & 3;
      fVar2 = value - fVar2 * 0.06666667f;
      if (uVar6 != 3) {
        local_54[uVar5 + 1] = fVar2 * 0.4375f + local_54[uVar5 + 1];
      }
      if (uVar5 < 0xc) {
        if (uVar6 != 0) {
          local_54[uVar5 + 3] = fVar2 * 0.1875f + local_54[uVar5 + 3];
        }
        local_54[uVar5 + 4] = fVar2 * 0.3125f + local_54[uVar5 + 4];
        if (uVar6 != 3) {
          local_54[uVar5 + 5] = fVar2 * 0.0625f + local_54[uVar5 + 5];
        }
      }
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x10);
  FUN_006595f5((void *)(uintptr_t)param_2, (ushort *)(puVar3 + 2), 0.0f, param_3);
  return;
}

// ---------------------------------------------------------------------------
// 0x65a4a0 — observed shape
// ---------------------------------------------------------------------------
// Single-channel 16-value fit: quantizes the fourth float of each point record,
// fits two endpoints (6- or 8-entry basis), then emits six bytes of 3-bit codes.
// param_2 is observed as a pointer value passed through a float parameter.
int FUN_0065a4a0(char *param_1,float param_2,int param_3)
{
  const float *pf = (const float *)(uintptr_t)param_2 + 3;
  float vals[16];
  float err[21] = {0.0f};
  float vmin = pf[0];
  float vmax = pf[0];

  if (param_3 != 0) {
    for (int i = 0; i < 0x10; i++) {
      err[i] = 0.0f;
    }
  }
  for (int i = 0; i < 0x10; i++) {
    float value = pf[i * 4];
    if (param_3 != 0) {
      value = value + err[i];
    }
    float local_10 = (float)ROUNDf(value * 255.0f + 0.5f);
    float fVar1 = local_10 * 0.003921569f;
    vals[i] = fVar1;
    if (vmin <= fVar1) {
      if (vmax < fVar1) {
        vmax = fVar1;
      }
    }
    else {
      vmin = fVar1;
    }
    if (param_3 != 0) {
      float fVar1b = value - fVar1;
      uint32_t uVar10 = (uint32_t)i & 3;
      if (uVar10 != 3) {
        err[i + 1] = fVar1b * 0.4375f + err[i + 1];
      }
      if (i < 0xc) {
        if (uVar10 != 0) {
          err[i + 3] = fVar1b * 0.1875f + err[i + 3];
        }
        err[i + 4] = fVar1b * 0.3125f + err[i + 4];
        if (uVar10 != 3) {
          err[i + 5] = fVar1b * 0.0625f + err[i + 5];
        }
      }
    }
  }
  int iVar8 = FUN_006595f5((void *)(uintptr_t)param_2, (ushort *)(param_1 + 8), 0.0f, param_3);
  if (iVar8 < 0) {
    return iVar8;
  }
  if (vmin == 1.0f) {
    param_1[0] = (char)-1;
    param_1[1] = (char)-1;
    for (int i = 2; i < 8; i++) param_1[i] = '\0';
    return 0;
  }
  int nch;
  if ((vmin == 0.0f) || (vmax == 1.0f)) {
    nch = 6;
  }
  else {
    nch = 8;
  }
  float e0;
  float e1;
  FUN_00658d4e(&e0, &e1, vals, (uint32_t)nch);
  uint32_t uVar13 = (uint32_t)ROUNDf(e0 * 255.0f + 0.5f);
  uint32_t uVar11 = (uint32_t)ROUNDf(e1 * 255.0f + 0.5f);
  float fVar1 = (float)(uVar13 & 0xff) * 0.003921569f;
  float fVar2 = (float)(uVar11 & 0xff) * 0.003921569f;
  char cVar6 = (char)uVar13;
  char cVar7 = (char)uVar11;
  float ramp[8];
  int *lut;

  if (nch == 8) {
    if (cVar6 == cVar7) {
      *param_1 = cVar6;
      param_1[1] = cVar7;
      for (int i = 2; i < 8; i++) param_1[i] = '\0';
      return 0;
    }
    param_1[1] = cVar6;
    ramp[0] = fVar2;
    ramp[1] = fVar1;
    *param_1 = cVar7;
    for (uint32_t k = 1; k < 7; k++) {
      float fVar3 = (float)(int)(7 - k);
      float fVar4 = (float)(int)k;
      ramp[k + 1] = (fVar4 * fVar1 + fVar3 * fVar2) * 0.14285715f;
    }
    lut = DAT_006edf98;
  }
  else {
    *param_1 = cVar6;
    ramp[0] = fVar1;
    ramp[1] = fVar2;
    param_1[1] = cVar7;
    for (uint32_t k = 1; k < 5; k++) {
      float fVar3 = (float)(int)(5 - k);
      float fVar4 = (float)(int)k;
      ramp[k + 1] = (fVar4 * fVar2 + fVar3 * fVar1) * 0.2f;
    }
    lut = DAT_006edfb8;
    ramp[6] = 0.0f;
    ramp[7] = 1.0f;
  }
  int iVar8b = nch - 1;
  float local_10 = (float)iVar8b;
  if (iVar8b < 0) {
    local_10 = local_10 + 4.2949673e+09f;
  }
  float local_20;
  if (ramp[0] == ramp[1]) {
    local_20 = 0.0f;
  }
  else {
    local_20 = local_10 / (ramp[1] - ramp[0]);
  }
  if (param_3 != 0) {
    for (int i = 0; i < 0x10; i++) {
      err[i] = 0.0f;
    }
  }
  char *pcVar5 = param_1;
  uint32_t uVar13b = 0;
  do {
    uint32_t uVar12 = 0;
    uint32_t uVar10b = uVar13b + 8;
    for (uint32_t i = uVar13b; i < uVar10b; i++) {
      float value = pf[i * 4];
      if (param_3 != 0) {
        value = value + err[i];
      }
      float fVar1c = (value - ramp[0]) * local_20;
      int iVar8c;
      if (!(fVar1c >= 0.0f)) {
        if (fVar1c < local_10) {
          int local_24 = ROUNDf(fVar1c + 0.5f);
          iVar8c = lut[local_24];
        }
        else {
          float fVar1d = (ramp[1] + 1.0f) * 0.5f;
          if ((nch != 6) || (fVar1d < value)) {
            iVar8c = 1;
          }
          else {
            iVar8c = 7;
          }
        }
      }
      else if ((nch != 6) || (ramp[0] * 0.5f < value)) {
        iVar8c = 0;
      }
      else {
        iVar8c = 6;
      }
      uVar12 = uVar12 >> 3 | (uint32_t)iVar8c << 0x15;
      if (param_3 != 0) {
        float fVar1e = value - ramp[iVar8c];
        uint32_t uVar11b = (uint32_t)i & 3;
        if (uVar11b != 3) {
          err[i + 1] = fVar1e * 0.4375f + err[i + 1];
        }
        if (i < 0xc) {
          if (uVar11b != 0) {
            err[i + 3] = fVar1e * 0.1875f + err[i + 3];
          }
          err[i + 4] = fVar1e * 0.3125f + err[i + 4];
          if (uVar11b != 3) {
            err[i + 5] = fVar1e * 0.0625f + err[i + 5];
          }
        }
      }
    }
    pcVar5[2] = (char)(uVar12 & 0xff);
    pcVar5[3] = (char)((uVar12 >> 8) & 0xff);
    pcVar5[4] = (char)((uVar12 >> 16) & 0xff);
    pcVar5 = pcVar5 + 3;
    uVar13b = uVar10b;
  } while (uVar10b < 0x10);
  return 0;
}

// ---------------------------------------------------------------------------
// 0x65a974 — observed shape
// ---------------------------------------------------------------------------
int FUN_0065a974(undefined4 param_1,undefined4 param_2)
{
  int iVar1 = FUN_0065a08a((int)param_1, (uint32_t *)(uintptr_t)param_2);
  if (-1 < iVar1) {
    iVar1 = FUN_00658b97();
    if (-1 < iVar1) {
      iVar1 = 0;
    }
  }
  return iVar1;
}

// ---------------------------------------------------------------------------
// 0x65a99a — observed shape
// ---------------------------------------------------------------------------
int FUN_0065a99a(undefined4 param_1,undefined4 param_2)
{
  int iVar1 = FUN_0065a10f((int)param_1, (byte *)(uintptr_t)param_2);
  if (-1 < iVar1) {
    iVar1 = FUN_00658b97();
    if (-1 < iVar1) {
      iVar1 = 0;
    }
  }
  return iVar1;
}

// ---------------------------------------------------------------------------
// 0x65a9c0 — observed shape
// ---------------------------------------------------------------------------
int FUN_0065a9c0(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  byte local_104[256];
  int iVar1 = FUN_00658c1b(local_104);
  (void)param_2;
  if (-1 < iVar1) {
    FUN_0065a371((undefined4 *)(uintptr_t)param_1, (int)(uintptr_t)local_104, (int)param_3);
    iVar1 = 0;
  }
  return iVar1;
}

// ---------------------------------------------------------------------------
// 0x65a9f9 — observed shape
// ---------------------------------------------------------------------------
int FUN_0065a9f9(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  byte local_104[256];
  int iVar1 = FUN_00658c1b(local_104);
  (void)param_2;
  if (-1 < iVar1) {
    iVar1 = FUN_0065a4a0((char *)(uintptr_t)param_1, (float)(uintptr_t)local_104, (int)param_3);
    if (-1 < iVar1) {
      iVar1 = 0;
    }
  }
  return iVar1;
}

// ---------------------------------------------------------------------------
// 0x65aa32 — observed shape
// ---------------------------------------------------------------------------
void FUN_0065aa32(void *self,int param_1,int param_2)
{
  uint32_t *p = (uint32_t *)self;
  _SYSTEM_INFO local_28;

  p[0] = 0;
  GetSystemInfo(&local_28);
  p[2] = 0;
  p[3] = 0;
  p[4] = 0;
  p[1] = local_28.dwPageSize;
  uint32_t uVar1 = (local_28.dwPageSize - 1) + (uint32_t)param_2 & ~(local_28.dwPageSize - 1);
  p[1] = uVar1;
  if (param_1 == 0) {
    param_1 = 0x100000;
  }
  p[5] = (uVar1 - 1) + (uint32_t)param_1 & ~(uVar1 - 1);
  return;
}

// ---------------------------------------------------------------------------
// 0x65aa8a — observed shape
// ---------------------------------------------------------------------------
void FUN_0065aa8a(void *self)
{
  int *p = (int *)self;
  while (*p != 0) {
    int *lpAddress = (int *)(uintptr_t)*p;
    *p = *lpAddress;
    VirtualFree(lpAddress, 0, 0x8000);
  }
  return;
}

// ---------------------------------------------------------------------------
// 0x65aaac — observed shape
// ---------------------------------------------------------------------------
int FUN_0065aaac(void *self,int param_1,int param_2)
{
  uint32_t *p = (uint32_t *)self;
  uint32_t uVar3 = (((uint32_t)param_2 + 0xffffffffu + p[2]) & ~((uint32_t)param_2 - 1u)) +
                   (uint32_t)param_1;
  uint32_t uVar1;
  uint32_t dwSize = 0;

  if (p[4] < uVar3) {
    uVar3 = (((uint32_t)param_2 + 3u) & ~((uint32_t)param_2 - 1u)) + (uint32_t)param_1;
    for (uVar1 = p[5]; uVar1 < uVar3; uVar1 = uVar1 * 2) {
    }
    int *lpAddress = (int *)VirtualAlloc((LPVOID)0x0, uVar1, 0x2000, 4);
    if (lpAddress == (int *)0x0) {
      return 0;
    }
    dwSize = (p[1] + 0xffffffffu + uVar3) & ~(p[1] - 1u);
    LPVOID pvVar2 = VirtualAlloc(lpAddress, dwSize, 0x1000, 4);
    if (pvVar2 == (LPVOID)0x0) {
      VirtualFree(lpAddress, 0, 0x8000);
      return 0;
    }
    *lpAddress = (int)*p;
    *p = (uint32_t)(uintptr_t)lpAddress;
    p[4] = uVar1;
    p[3] = dwSize;
  }
  else {
    uVar1 = p[3];
    if (uVar3 <= uVar1) {
      p[2] = uVar3;
      return (int)((*p - (uint32_t)param_1) + uVar3);
    }
    dwSize = (p[1] + 0xffffffffu + uVar3) & ~(p[1] - 1u);
    LPVOID pvVar2 = VirtualAlloc((LPVOID)(uintptr_t)(*p + uVar1), dwSize - uVar1, 0x1000, 4);
    if (pvVar2 == (LPVOID)0x0) {
      return 0;
    }
    p[3] = dwSize;
  }
  p[2] = uVar3;
  return (int)((*p - (uint32_t)param_1) + uVar3);
}

// ---------------------------------------------------------------------------
// 0x65ab96 — observed shape
// ---------------------------------------------------------------------------
void FUN_0065ab96(void *self,undefined4 param_1)
{
  uint32_t *p = (uint32_t *)self;
  p[2] = 0;
  p[3] = 0;
  p[0] = (uint32_t)(uintptr_t)&PTR_FUN_006edfd0;
  p[1] = param_1;
  return;
}

// ---------------------------------------------------------------------------
// 0x65abb5 — observed shape
// ---------------------------------------------------------------------------
bool FUN_0065abb5(void *self,int param_1)
{
  bool bVar1 = false;
  if (param_1 != 0) {
    bVar1 = *(int *)(param_1 + 4) == *(int *)((char *)self + 4);
  }
  return bVar1;
}

// ---------------------------------------------------------------------------
// 0x65abd0 — observed shape
// ---------------------------------------------------------------------------
uint FUN_0065abd0(undefined4 *param_1,int param_2)
{
  uint uVar1;
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = (uint)(param_2 == 0);
  }
  else {
    void *v = *(void **)param_1;
    typedef uint (__stdcall *vtfn_t)(void *, int);
    uVar1 = ((vtfn_t)(*(void **)v))(v, param_2);
  }
  return uVar1;
}
