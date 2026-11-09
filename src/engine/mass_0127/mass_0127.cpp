#include <cstdint>
#include <cstddef>
#include <cmath>

// ---------------------------------------------------------------------------
// x87 / CRT helpers and globals referenced by the listings below.
// ---------------------------------------------------------------------------
using float10 = long double;

extern "C" long double fsin(long double);
extern "C" long double fcos(long double);
extern "C" long double _CIasin(void);            // x87 fasin; input taken from ST0
extern "C" int sprintf(char* buffer, const char* format, ...);

extern float DAT_00727c7c;                        // asin clamp limit
extern float FUN_005534a0(float param_1, float param_2);  // atan2-style helper
extern void* thunk_FUN_00533c78(std::size_t size);        // allocator thunk

typedef void (*VtblMethod_ii)(int* param_1, int param_2);

// 0x53c800 — observed shape
void FUN_0053c800(float* self, float param_1, float param_2, float param_3, float param_4)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  fVar4 = (float10)fcos((float10)param_1);
  fVar5 = (float10)fsin((float10)param_1);
  fVar1 = (float)((float10)1.0 - fVar4);
  fVar6 = ((float10)1.0 - fVar4) * (float10)param_2;
  fVar2 = (float)((float10)param_3 * fVar6);
  fVar6 = fVar6 * (float10)param_4;
  fVar3 = fVar1 * param_3 * param_4;
  self[0] = (float)((float10)param_2 * (float10)param_2 * (float10)fVar1 + fVar4);
  self[1] = (float)((float10)fVar2 + fVar5 * (float10)param_4);
  self[2] = (float)(fVar6 - fVar5 * (float10)param_3);
  self[3] = (float)((float10)fVar2 - fVar5 * (float10)param_4);
  self[4] = (float)((float10)param_3 * (float10)param_3 * (float10)fVar1 + fVar4);
  self[5] = (float)(fVar5 * (float10)param_2) + fVar3;
  self[6] = (float)(fVar5 * (float10)param_3 + fVar6);
  self[7] = fVar3 - (float)(fVar5 * (float10)param_2);
  self[8] = (float)((float10)param_4 * (float10)param_4 * (float10)fVar1 + fVar4);
  return;
}

// 0x53c8d0 — observed shape
void FUN_0053c8d0(float* self, float* param_1, float* param_2)
{
  int iVar1;
  float* pfVar2;
  float local_24[4];
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  local_24[0] = self[2] * param_2[6] + *param_2 * *self + param_2[3] * self[1];
  local_24[3] = self[3] * *param_2 + param_2[3] * self[4] + self[5] * param_2[6];
  local_c = self[7] * param_2[3] + *param_2 * self[6] + self[8] * param_2[6];
  local_24[1] = param_2[4] * self[1] + param_2[1] * *self + param_2[7] * self[2];
  local_14 = param_2[1] * self[3] + param_2[4] * self[4] + param_2[7] * self[5];
  local_8 = self[7] * param_2[4] + self[8] * param_2[7] + param_2[1] * self[6];
  local_24[2] = param_2[5] * self[1] + param_2[2] * *self + param_2[8] * self[2];
  local_10 = param_2[2] * self[3] + param_2[5] * self[4] + param_2[8] * self[5];
  local_4 = self[7] * param_2[5] + self[8] * param_2[8] + param_2[2] * self[6];
  pfVar2 = local_24;
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

// 0x53c9e0 — observed shape
void FUN_0053c9e0(float* self, float* param_1, float param_2)
{
  int iVar1;
  float* pfVar2;
  float local_24[4];
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  local_24[0] = param_2 * *self;
  local_24[1] = param_2 * self[1];
  local_24[2] = param_2 * self[2];
  local_24[3] = param_2 * self[3];
  local_14 = param_2 * self[4];
  local_10 = param_2 * self[5];
  local_c = param_2 * self[6];
  local_8 = param_2 * self[7];
  local_4 = param_2 * self[8];
  pfVar2 = local_24;
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

// 0x53ca60 — observed shape
void FUN_0053ca60(float* self, float* param_1, float* param_2)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  fVar1 = self[8];
  fVar2 = param_2[2];
  fVar3 = self[6];
  fVar4 = *param_2;
  fVar5 = self[7];
  fVar6 = param_2[1];
  fVar7 = self[5];
  fVar8 = param_2[2];
  fVar9 = self[3];
  fVar10 = *param_2;
  fVar11 = self[4];
  fVar12 = param_2[1];
  *param_1 = *param_2 * *self + self[1] * param_2[1] + self[2] * param_2[2];
  param_1[1] = fVar11 * fVar12 + fVar9 * fVar10 + fVar7 * fVar8;
  param_1[2] = fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2;
  return;
}

// 0x53cac0 — observed shape
void FUN_0053cac0(float* param_1, float* param_2, float* param_3)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  fVar1 = param_3[8];
  fVar2 = param_2[2];
  fVar3 = param_3[5];
  fVar4 = param_2[1];
  fVar5 = param_3[2];
  fVar6 = *param_2;
  fVar7 = param_3[7];
  fVar8 = param_2[2];
  fVar9 = param_3[4];
  fVar10 = param_2[1];
  fVar11 = param_3[1];
  fVar12 = *param_2;
  *param_1 = *param_2 * *param_3 + param_3[3] * param_2[1] + param_3[6] * param_2[2];
  param_1[1] = fVar11 * fVar12 + fVar9 * fVar10 + fVar7 * fVar8;
  param_1[2] = fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2;
  return;
}

// 0x53cb20 — observed shape
uint32_t FUN_0053cb20(float* self, float* param_1)
{
  float fVar1;
  float fVar2;
  float* pfVar3;
  float* pfVar4;
  int iVar5;

  *param_1 = self[4] * self[8] - self[7] * self[5];
  param_1[1] = self[7] * self[2] - self[8] * self[1];
  param_1[2] = self[5] * self[1] - self[4] * self[2];
  param_1[3] = self[5] * self[6] - self[8] * self[3];
  param_1[4] = *self * self[8] - self[6] * self[2];
  param_1[5] = self[3] * self[2] - self[5] * *self;
  param_1[6] = self[7] * self[3] - self[4] * self[6];
  param_1[7] = self[6] * self[1] - self[7] * *self;
  param_1[8] = self[4] * *self - self[3] * self[1];
  fVar1 = param_1[3] * self[1] + *param_1 * *self + param_1[6] * self[2];
  fVar2 = std::fabs(fVar1);
  if (!std::isnan(fVar2) && fVar2 < 1e-06f != (fVar2 == 1e-06f)) {
    // x87 status word packing observed in the listing.
    return (uint32_t)(uint16_t)((uint16_t)(fVar2 < 1e-06f) << 8 |
                                (uint16_t)std::isnan(fVar2) << 10 |
                                (uint16_t)(fVar2 == 1e-06f) << 0xe);
  }
  fVar1 = 1.0f / fVar1;
  iVar5 = 3;
  pfVar3 = param_1 + 2;
  do {
    pfVar4 = pfVar3 + 3;
    iVar5 = iVar5 + -1;
    pfVar3[-2] = fVar1 * pfVar3[-2];
    pfVar3[-1] = fVar1 * pfVar3[-1];
    *pfVar3 = fVar1 * *pfVar3;
    pfVar3 = pfVar4;
  } while (iVar5 != 0);
  // CONCAT31((int3)((uint)pfVar4 >> 8), 1): low byte 1, upper bytes of the cursor.
  return ((uint32_t)(uintptr_t)pfVar4 & 0xffffff00u) | 1u;
}

// 0x53cc20 — observed shape
void FUN_0053cc20(float* self, float* param_1)
{
  float uVar1;
  float uVar2;
  float uVar3;
  float uVar4;
  float uVar5;
  float uVar6;
  float uVar7;
  float uVar8;

  uVar3 = self[3];
  uVar4 = self[4];
  uVar1 = self[1];
  uVar2 = self[2];
  uVar5 = self[5];
  uVar6 = self[7];
  uVar7 = self[6];
  uVar8 = self[8];
  *param_1 = *self;
  param_1[3] = uVar1;
  param_1[6] = uVar2;
  param_1[1] = uVar3;
  param_1[4] = uVar4;
  param_1[7] = uVar5;
  param_1[2] = uVar7;
  param_1[5] = uVar6;
  param_1[8] = uVar8;
  return;
}

// 0x53cca0 — observed shape
uint32_t FUN_0053cca0(float* self)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint32_t uVar5;
  uint16_t uVar6;

  fVar1 = std::sqrt(self[6] * self[6] + self[3] * self[3] + *self * *self);
  uVar5 = (uint32_t)(uint16_t)((uint16_t)(fVar1 < 1e-05f) << 8 |
                               (uint16_t)std::isnan(fVar1) << 10 |
                               (uint16_t)(fVar1 == 1e-05f) << 0xe);
  if (fVar1 >= 1e-05f) {
    fVar1 = 1.0f / fVar1;
    fVar3 = fVar1 * *self;
    *self = fVar3;
    fVar2 = fVar1 * self[3];
    fVar1 = fVar1 * self[6];
    self[3] = fVar2;
    self[6] = fVar1;
    fVar4 = fVar2 * self[4] + fVar1 * self[7] + fVar3 * self[1];
    fVar3 = self[1] - fVar3 * fVar4;
    self[1] = fVar3;
    fVar2 = self[4] - fVar2 * fVar4;
    self[4] = fVar2;
    fVar1 = self[7] - fVar1 * fVar4;
    self[7] = fVar1;
    fVar1 = std::sqrt(fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1);
    uVar5 = (uint32_t)(uint16_t)((uint16_t)(fVar1 < 1e-05f) << 8 |
                                 (uint16_t)std::isnan(fVar1) << 10 |
                                 (uint16_t)(fVar1 == 1e-05f) << 0xe);
    if (fVar1 >= 1e-05f) {
      fVar1 = 1.0f / fVar1;
      self[1] = fVar1 * self[1];
      self[4] = fVar1 * self[4];
      self[7] = fVar1 * self[7];
      fVar1 = self[2] * *self + self[5] * self[3] + self[8] * self[6];
      fVar3 = self[2] - fVar1 * *self;
      self[2] = fVar3;
      fVar2 = self[5] - fVar1 * self[3];
      self[5] = fVar2;
      fVar1 = self[8] - fVar1 * self[6];
      self[8] = fVar1;
      fVar1 = fVar2 * self[4] + fVar1 * self[7] + fVar3 * self[1];
      fVar2 = self[2] - fVar1 * self[1];
      self[2] = fVar2;
      fVar3 = self[5] - fVar1 * self[4];
      self[5] = fVar3;
      fVar1 = self[8] - fVar1 * self[7];
      self[8] = fVar1;
      fVar1 = std::sqrt(fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1);
      uVar6 = (uint16_t)(fVar1 < 1e-05f) << 8 | (uint16_t)std::isnan(fVar1) << 10 |
              (uint16_t)(fVar1 == 1e-05f) << 0xe;
      uVar5 = (uint32_t)uVar6;
      if (fVar1 >= 1e-05f) {
        fVar1 = 1.0f / fVar1;
        self[2] = fVar1 * self[2];
        self[5] = fVar1 * self[5];
        self[8] = fVar1 * self[8];
        // CONCAT31((uint3)(byte)(uVar6 >> 8), 1)
        return ((uint32_t)(uVar6 >> 8) << 8) | 1u;
      }
    }
  }
  return uVar5;
}

// 0x53ce40 — observed shape
void FUN_0053ce40(float* self, float* param_1, float* param_2)
{
  int iVar1;
  float* pfVar2;
  float local_24[4];
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  local_24[0] = self[6] * param_2[6] + *param_2 * *self + param_2[3] * self[3];
  local_24[3] = self[1] * *param_2 + param_2[3] * self[4] + self[7] * param_2[6];
  local_c = param_2[3] * self[5] + *param_2 * self[2] + self[8] * param_2[6];
  local_24[1] = param_2[4] * self[3] + param_2[1] * *self + param_2[7] * self[6];
  local_14 = param_2[1] * self[1] + param_2[4] * self[4] + param_2[7] * self[7];
  local_8 = self[5] * param_2[4] + self[8] * param_2[7] + param_2[1] * self[2];
  local_24[2] = param_2[5] * self[3] + param_2[2] * *self + param_2[8] * self[6];
  local_10 = param_2[2] * self[1] + param_2[5] * self[4] + param_2[8] * self[7];
  local_4 = self[5] * param_2[5] + self[8] * param_2[8] + param_2[2] * self[2];
  pfVar2 = local_24;
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

// 0x53cf50 — observed shape
void FUN_0053cf50(float* self, float* param_1, float* param_2)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;

  fVar1 = self[2];
  fVar8 = self[1];
  fVar2 = self[4];
  fVar3 = self[5];
  fVar4 = self[8];
  *param_1 = *self;
  param_2[2] = 0.0f;
  if (std::fabs(fVar1) < 1e-08f) {
    param_1[1] = fVar2;
    param_1[2] = fVar4;
    *param_2 = fVar8;
    param_2[1] = fVar3;
    fVar8 = 1.0f;
    self[0] = 1.0f;   // 0x3f800000
    self[5] = 0.0f;
    self[7] = 0.0f;
    self[8] = 1.0f;   // 0x3f800000
  }
  else {
    fVar5 = std::sqrt(fVar8 * fVar8 + fVar1 * fVar1);
    fVar6 = 1.0f / fVar5;
    fVar8 = fVar8 * fVar6;
    fVar6 = fVar6 * fVar1;
    fVar7 = fVar3 * fVar8 + fVar3 * fVar8 + (fVar4 - fVar2) * fVar6;
    fVar1 = fVar7 * fVar6;
    param_1[1] = fVar2 + fVar1;
    param_1[2] = fVar4 - fVar1;
    *param_2 = fVar5;
    param_2[1] = fVar3 - fVar7 * fVar8;
    self[0] = 1.0f;   // 0x3f800000
    self[5] = fVar6;
    self[7] = fVar6;
    self[8] = -fVar8;
  }
  self[1] = 0.0f;
  self[2] = 0.0f;
  self[3] = 0.0f;
  self[4] = fVar8;
  self[6] = 0.0f;
  return;
}

// 0x53d060 — observed shape
uint32_t FUN_0053d060(float* self, float* param_1, float* param_2)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  float* pfVar7;
  intptr_t iVar8;
  float* pfVar9;
  float* pfVar10;
  float* pfVar11;
  int iVar12;
  float local_28;
  float local_24;
  int local_20;
  float local_18;
  int local_10;
  uint32_t local_c;

  iVar8 = (intptr_t)param_2 - (intptr_t)param_1;
  local_20 = 0;
  local_c = 2;
  pfVar9 = param_1;
  do {
    local_10 = 0;
    do {
      iVar6 = local_20;
      if (3 < (int)local_c) {
        pfVar10 = (float*)(iVar8 + 0xc + (intptr_t)pfVar9);
        pfVar7 = pfVar9 + 1;
        do {
          fVar2 = std::fabs(pfVar7[-1]) + std::fabs(*pfVar7);
          if (fVar2 == std::fabs(pfVar10[-3]) + fVar2) goto LAB_0053d184;
          fVar2 = std::fabs(pfVar7[1]) + std::fabs(*pfVar7);
          if (fVar2 == std::fabs(*(float*)(iVar8 + (intptr_t)pfVar7)) + fVar2) {
            iVar6 = iVar6 + 1;
            goto LAB_0053d184;
          }
          fVar2 = std::fabs(pfVar7[1]) + std::fabs(pfVar7[2]);
          if (fVar2 == std::fabs(pfVar10[-1]) + fVar2) {
            iVar6 = iVar6 + 2;
            goto LAB_0053d184;
          }
          fVar2 = std::fabs(pfVar7[3]) + std::fabs(pfVar7[2]);
          if (fVar2 == std::fabs(*pfVar10) + fVar2) {
            iVar6 = iVar6 + 3;
            goto LAB_0053d184;
          }
          iVar6 = iVar6 + 4;
          pfVar7 = pfVar7 + 4;
          pfVar10 = pfVar10 + 4;
        } while (iVar6 < -1);
      }
      if (iVar6 < 2) {
        pfVar7 = param_1 + iVar6;
        do {
          if (std::fabs(*pfVar7) + std::fabs(pfVar7[1]) ==
              std::fabs(*(float*)(iVar8 + (intptr_t)pfVar7)) + std::fabs(*pfVar7) +
                  std::fabs(pfVar7[1])) break;
          iVar6 = iVar6 + 1;
          pfVar7 = pfVar7 + 1;
        } while (iVar6 < 2);
      }
LAB_0053d184:
      if (iVar6 == local_20) break;
      fVar2 = (pfVar9[1] - *pfVar9) /
              (*(float*)(iVar8 + (intptr_t)pfVar9) + *(float*)(iVar8 + (intptr_t)pfVar9));
      fVar1 = std::sqrt(fVar2 * fVar2 + 1.0f);
      if (0.0f <= fVar2) {
        fVar2 = (param_1[iVar6] - *pfVar9) +
                *(float*)(iVar8 + (intptr_t)pfVar9) / (fVar1 + fVar2);
      }
      else {
        fVar2 = (param_1[iVar6] - *pfVar9) +
                *(float*)(iVar8 + (intptr_t)pfVar9) / (fVar2 - fVar1);
      }
      iVar12 = iVar6 + -1;
      local_28 = 1.0f;
      local_24 = 1.0f;
      local_18 = 0.0f;
      if (local_20 <= iVar12) {
        pfVar7 = (float*)((intptr_t)self + 0xc + iVar12 * 4);
        pfVar10 = param_1 + iVar6;
        do {
          fVar1 = local_28 * *(float*)((intptr_t)param_2 + iVar12 * 4);
          fVar5 = local_24 * *(float*)((intptr_t)param_2 + iVar12 * 4);
          fVar4 = std::fabs(fVar1);
          fVar3 = std::fabs(fVar2);
          if ((std::isnan(fVar3) || std::isnan(fVar4)) ||
              fVar3 < fVar4 == (fVar3 == fVar4)) {
            fVar1 = fVar1 / fVar2;
            local_24 = std::sqrt(fVar1 * fVar1 + 1.0f);
            *(float*)(iVar8 + (intptr_t)pfVar10) = local_24 * fVar2;
            local_24 = 1.0f / local_24;
            local_28 = local_24 * fVar1;
          }
          else {
            fVar2 = fVar2 / fVar1;
            local_28 = std::sqrt(fVar2 * fVar2 + 1.0f);
            *(float*)(iVar8 + (intptr_t)pfVar10) = fVar1 * local_28;
            local_28 = 1.0f / local_28;
            local_24 = fVar2 * local_28;
          }
          fVar2 = *pfVar10 - local_18;
          iVar12 = iVar12 + -1;
          pfVar11 = pfVar10 + -1;
          fVar1 = fVar5 * local_24;
          fVar1 = fVar1 + fVar1 + (pfVar10[-1] - fVar2) * local_28;
          local_18 = local_28 * fVar1;
          *pfVar10 = local_18 + fVar2;
          fVar2 = local_24 * fVar1 - fVar5;
          fVar1 = *(float*)((intptr_t)pfVar11 + 4 +
                            ((intptr_t)self - (intptr_t)param_1));
          *(float*)((intptr_t)pfVar11 + 4 + ((intptr_t)self - (intptr_t)param_1)) =
              fVar1 * local_24 + local_28 * pfVar7[-3];
          pfVar7[-3] = local_24 * pfVar7[-3] - fVar1 * local_28;
          fVar1 = pfVar7[1];
          pfVar7[1] = fVar1 * local_24 + local_28 * *pfVar7;
          *pfVar7 = local_24 * *pfVar7 - fVar1 * local_28;
          fVar1 = pfVar7[4];
          pfVar7[4] = local_28 * pfVar7[3] + local_24 * fVar1;
          pfVar7[3] = local_24 * pfVar7[3] - fVar1 * local_28;
          pfVar7 = pfVar7 + -1;
          pfVar10 = pfVar11;
        } while (local_20 <= iVar12);
      }
      local_10 = local_10 + 1;
      *pfVar9 = *pfVar9 - local_18;
      *(float*)(iVar8 + (intptr_t)pfVar9) = fVar2;
      *(uint32_t*)((intptr_t)param_2 + iVar6 * 4) = 0;
    } while (local_10 < 0x20);
    if (local_10 == 0x20) {
      return 0;
    }
    local_20 = local_20 + 1;
    local_c = local_c - 1;
    pfVar9 = pfVar9 + 1;
    if (0x7fffffff < local_c) {
      return 1;
    }
  } while (true);
}

// 0x53d400 — observed shape
uint32_t FUN_0053d400(float* self, float* param_1, float* param_2, float* param_3)
{
  float10 fVar1;

  if (self[2] <= -1.0f) {
    fVar1 = -(float10)DAT_00727c7c;
  }
  else if (1.0f <= self[2]) {
    fVar1 = (float10)DAT_00727c7c;
  }
  else {
    fVar1 = (float10)_CIasin();   // x87 fasin, ST0 input is self[2]
  }
  fVar1 = -fVar1;
  *param_2 = (float)fVar1;
  if (fVar1 < (float10)DAT_00727c7c) {
    if (-(float10)DAT_00727c7c < fVar1) {
      fVar1 = (float10)FUN_005534a0(-self[5], self[8]);
      *param_1 = (float)-fVar1;
      // second call result is consumed from ST0 (Ghidra: extraout_ST0)
      fVar1 = (float10)FUN_005534a0(-self[1], *self);
      *param_3 = (float)-fVar1;
      return 1;
    }
    fVar1 = (float10)FUN_005534a0(self[3], self[4]);
    *param_3 = 0.0f;
    *param_1 = (float)fVar1;
    return 0;
  }
  fVar1 = (float10)FUN_005534a0(self[3], self[4]);
  *param_3 = 0.0f;
  *param_1 = (float)-fVar1;
  return 0;
}

// 0x53d510 — observed shape
uint32_t FUN_0053d510(float* self, float* param_1, float* param_2, float* param_3)
{
  float10 fVar1;

  if (self[7] <= -1.0f) {
    fVar1 = -(float10)DAT_00727c7c;
  }
  else if (1.0f <= self[7]) {
    fVar1 = (float10)DAT_00727c7c;
  }
  else {
    fVar1 = (float10)_CIasin();   // x87 fasin, ST0 input is self[7]
  }
  fVar1 = -fVar1;
  *param_2 = (float)fVar1;
  if (fVar1 < (float10)DAT_00727c7c) {
    if (-(float10)DAT_00727c7c < fVar1) {
      fVar1 = (float10)FUN_005534a0(-self[1], self[4]);
      *param_1 = (float)-fVar1;
      // second call result is consumed from ST0 (Ghidra: extraout_ST0)
      fVar1 = (float10)FUN_005534a0(-self[6], self[8]);
      *param_3 = (float)-fVar1;
      return 1;
    }
    fVar1 = (float10)FUN_005534a0(self[2], *self);
    *param_3 = 0.0f;
    *param_1 = (float)fVar1;
    return 0;
  }
  fVar1 = (float10)FUN_005534a0(self[2], *self);
  *param_3 = 0.0f;
  *param_1 = (float)-fVar1;
  return 0;
}

// 0x53d620 — observed shape
uint32_t FUN_0053d620(float* self, float* param_1, float* param_2, float* param_3)
{
  float10 fVar1;

  if (self[6] <= -1.0f) {
    fVar1 = -(float10)DAT_00727c7c;
  }
  else if (1.0f <= self[6]) {
    fVar1 = (float10)DAT_00727c7c;
  }
  else {
    fVar1 = (float10)_CIasin();   // x87 fasin, ST0 input is self[6]
  }
  *param_2 = (float)fVar1;
  if (fVar1 < (float10)DAT_00727c7c) {
    if (-(float10)DAT_00727c7c < fVar1) {
      fVar1 = (float10)FUN_005534a0(self[3], *self);
      *param_1 = (float)-fVar1;
      // second call result is consumed from ST0 (Ghidra: extraout_ST0)
      fVar1 = (float10)FUN_005534a0(self[7], self[8]);
      *param_3 = (float)-fVar1;
      return 1;
    }
    fVar1 = (float10)FUN_005534a0(-self[1], self[2]);
    *param_3 = 0.0f;
    *param_1 = (float)fVar1;
    return 0;
  }
  fVar1 = (float10)FUN_005534a0(-self[1], self[2]);
  *param_3 = 0.0f;
  *param_1 = (float)-fVar1;
  return 0;
}

// 0x53d720 — observed shape
void FUN_0053d720(float* self, float param_1, float param_2, float param_3)
{
  float10 fVar4;
  float10 fVar5;
  float* puVar2;
  int iVar3;
  float local_90[3];
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24[9];

  fVar4 = (float10)fcos((float10)param_1);
  local_6c = 1.0f;   // 0x3f800000
  local_68 = 0.0f;
  local_64 = 0.0f;
  local_60 = 0.0f;
  local_54 = 0.0f;
  local_90[1] = 0.0f;
  local_84 = 0.0f;
  local_80 = 1.0f;   // 0x3f800000
  local_7c = 0.0f;
  local_74 = 0.0f;
  local_40 = 0.0f;
  local_34 = 0.0f;
  local_30 = 0.0f;
  local_2c = 0.0f;
  local_28 = 1.0f;   // 0x3f800000
  fVar5 = (float10)fsin((float10)param_1);
  local_5c = (float)fVar4;
  local_58 = (float)fVar5;
  local_50 = (float)-fVar5;
  local_4c = (float)fVar4;
  fVar4 = (float10)fcos((float10)param_2);
  fVar5 = (float10)fsin((float10)param_2);
  local_90[0] = (float)fVar4;
  local_90[2] = (float)-fVar5;
  local_78 = (float)fVar5;
  local_70 = (float)fVar4;
  fVar4 = (float10)fcos((float10)param_3);
  fVar5 = (float10)fsin((float10)param_3);
  local_48 = (float)fVar4;
  local_44 = (float)fVar5;
  local_3c = (float)-fVar5;
  local_38 = (float)fVar4;
  // FUN_0053c8d0 writes its 9-float product into its param_1 and returns that
  // same buffer; the listing feeds that buffer into the second call.
  FUN_0053c8d0(self, local_24, &local_48);          // local_24 = self * Rz
  FUN_0053c8d0(self, local_90, local_24);           // local_90 = self * local_24
  puVar2 = local_90;
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *self = *puVar2;
    puVar2 = puVar2 + 1;
    self = self + 1;
  }
  return;
}

// 0x53d850 — observed shape
void FUN_0053d850(float* self)
{
  float* in_ECX;
  float fVar1;
  int iVar2;
  int iVar3;

  in_ECX = self;
  iVar3 = 3;
  do {
    iVar2 = 3;
    do {
      fVar1 = std::fabs(*in_ECX);
      if ((!std::isnan(fVar1) && fVar1 < 1e-08f != (fVar1 == 1e-08f)) &&
          (*in_ECX != 0.0f)) {
        *in_ECX = 0.0f;
      }
      in_ECX = in_ECX + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

// 0x53d8a0 — observed shape
void FUN_0053d8a0(float* self, void* param_1, float* param_2)
{
  float* in_ECX;
  int iVar1;
  float* pfVar2;
  float local_30[3];
  float local_24[4];
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  in_ECX = self;
  pfVar2 = local_24;
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar2 = *in_ECX;
    in_ECX = in_ECX + 1;
    pfVar2 = pfVar2 + 1;
  }
  // Both sub-calls take the matrix in ECX (the function receiver).
  FUN_0053cf50(self, (float*)param_1, local_30);
  FUN_0053d060(self, (float*)param_1, local_30);
  *param_2 = local_24[0];
  param_2[2] = local_c;
  param_2[1] = local_24[3];
  param_2[4] = local_14;
  param_2[3] = local_24[1];
  param_2[6] = local_24[2];
  param_2[5] = local_8;
  param_2[8] = local_4;
  param_2[7] = local_10;
  if ((param_2[8] * param_2[4] - param_2[5] * param_2[7]) * *param_2 +
      (param_2[5] * param_2[6] - param_2[8] * param_2[3]) * param_2[1] +
      (param_2[3] * param_2[7] - param_2[6] * param_2[4]) * param_2[2] < 0.0f) {
    param_2[6] = -param_2[6];
    param_2[7] = -param_2[7];
    param_2[8] = -param_2[8];
  }
  return;
}

// 0x53d980 — observed shape
void FUN_0053d980(int* self, void* param_1)
{
  int* in_ECX;
  void** vtbl;
  int iVar1;
  int iVar2;

  in_ECX = self;
  iVar1 = 3;
  do {
    iVar2 = 3;
    do {
      vtbl = *(void***)(*(void**)((char*)param_1 + 0x15c));
      ((VtblMethod_ii)vtbl[2])(in_ECX, 4);
      in_ECX = in_ECX + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

// 0x53d9c0 — observed shape
void FUN_0053d9c0(int* self, void* param_1)
{
  int* in_ECX;
  void** vtbl;
  int iVar1;
  int iVar2;

  FUN_0053d850((float*)self);
  in_ECX = self;
  iVar1 = 3;
  do {
    iVar2 = 3;
    do {
      vtbl = *(void***)(*(void**)((char*)param_1 + 0x160));
      ((VtblMethod_ii)vtbl[3])(in_ECX, 4);
      in_ECX = in_ECX + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

// 0x53da70 — observed shape
char* FUN_0053da70(char* param_1, uint32_t param_2)
{
  char cVar1;
  char* pcVar2;

  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  // allocation size is strlen(param_1) + 0x16
  pcVar2 = (char*)thunk_FUN_00533c78((std::size_t)(pcVar2 + 0x16 - (param_1 + 1)));
  switch (param_2) {
  case 0:
    sprintf(pcVar2, "%s = TEST_NEVER", param_1);
    return pcVar2;
  case 1:
    sprintf(pcVar2, "%s = TEST_LESS", param_1);
    return pcVar2;
  case 2:
    sprintf(pcVar2, "%s = TEST_EQUAL", param_1);
    return pcVar2;
  case 3:
    sprintf(pcVar2, "%s = TEST_LESSEQUAL", param_1);
    return pcVar2;
  case 4:
    sprintf(pcVar2, "%s = TEST_GREATER", param_1);
    return pcVar2;
  case 5:
    sprintf(pcVar2, "%s = TEST_NOTEQUAL", param_1);
    return pcVar2;
  case 6:
    sprintf(pcVar2, "%s = TEST_GREATEREQUAL", param_1);
    return pcVar2;
  case 7:
    sprintf(pcVar2, "%s = TEST_ALWAYS", param_1);
  }
  return pcVar2;
}
