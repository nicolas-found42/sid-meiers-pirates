#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cmath>

extern void FUN_006011da(uint32_t param_1, uint32_t param_2, uint32_t param_3);
extern void FUN_0060010b();
extern void operator_delete(void* ptr);
extern int FUN_00600136(int param_1);
extern int FUN_0060164a(int param_1);
extern void FUN_00601966(int param_1);
extern void thunk_FUN_005f148d(float* a, float* b);
extern void thunk_FUN_005f0fd8(int a, int b, int c);

extern void* PTR_FUN_006de000;
extern void* PTR_FUN_006de010;
extern void* PTR_FUN_006de020;
extern void* PTR_FUN_006de038;
extern void* PTR_FUN_006de048;
extern void* PTR_FUN_006de058;
extern void* PTR_FUN_006de068;
extern void* PTR_FUN_006de078;
extern void* PTR_FUN_006de088;
extern void* PTR_FUN_006de098;
extern void* PTR_FUN_006de0a8;
extern void* PTR_FUN_006de0b8;

// 0x606ed5 — observed shape
void FUN_00606ed5(void* self, uint32_t param_1)
{
  uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
  FUN_006011da(param_1, 0x20, 2);
  *in_ECX = reinterpret_cast<uint32_t>(&PTR_FUN_006de000);
}

// 0x606ef6 — observed shape
void FUN_00606ef6(void* self, uint32_t param_1)
{
  uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
  FUN_006011da(param_1, 0x40, 3);
  *in_ECX = reinterpret_cast<uint32_t>(&PTR_FUN_006de010);
}

// 0x606f17 — observed shape
void FUN_00606f17(void* self, uint8_t param_1)
{
  void* in_ECX = self;
  FUN_0060010b();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
}

// 0x606f38 — observed shape
void FUN_00606f38(void* self, uint32_t param_1)
{
  uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
  FUN_006011da(param_1, 0x10, 2);
  *in_ECX = reinterpret_cast<uint32_t>(&PTR_FUN_006de020);
}

// 0x606f59 — observed shape
void FUN_00606f59(void* self, uint32_t param_1, float* param_2, int param_3)
{
  uintptr_t in_ECX = reinterpret_cast<uintptr_t>(self);
  float* pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  uint32_t uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint32_t uVar12;
  uint32_t uVar13;
  int iVar14;
  uint32_t uVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  float local_58 = 0.0f;
  float local_54 = 0.0f;
  float local_50 = 0.0f;
  float local_4c = 0.0f;
  uint32_t local_38;
  uint32_t local_34;

  if (*(int*)(in_ECX + 0x54) != 0) {
    param_3 = FUN_00600136(param_3);
  }
  if (*(int*)(in_ECX + 0x10) != 0) {
    param_3 = FUN_0060164a(param_3);
  }
  uint32_t* local_8 = reinterpret_cast<uint32_t*>(
      *(int*)(in_ECX + 0x60) * param_1 +
      (*(int*)(in_ECX + 0x68) + -1) * (param_1 & 1) * 4 +
      *(int*)(in_ECX + 100) * reinterpret_cast<int>(param_2) + *(int*)(in_ECX + 0x20));
  uVar8 = param_1 & 3;
  uVar12 = reinterpret_cast<uint32_t>(param_2) & 3;
  iVar3 = *(int*)(in_ECX + 0x34);
  int iVarc8;
  if ((param_1 & 1) == 0) {
    iVar17 = 0;
    iVar14 = 1;
  } else {
    iVar17 = *(int*)(in_ECX + 0x68) + -1;
    iVar14 = -1;
  }
  iVarc8 = iVar17;
  uint32_t in_FPUControlWord = 0;  // observed: x87 control word read and stored
  *(uint32_t*)(in_ECX + 0x7c) = in_FPUControlWord;
  if (*(int*)(in_ECX + 0x5c) != 0) {
    FUN_00601966(param_3);
  }
  param_1 = 0;
  if (*(int*)(in_ECX + 0x68) != 0) {
    iVar10 = iVar14 * 0x10;
    iVar9 = iVarc8 * 0x10;
    param_2 = reinterpret_cast<float*>(iVar9 + 8 + param_3);
    iVar11 = (iVar14 + iVarc8) * 0x10;
    iVar17 = (iVarc8 - iVar14) * 0x10;
    do {
      fVar2 = *(float*)(iVar3 + (uVar12 + uVar8 * 8) * 4 + (param_1 & 3) * 4);
      fVar4 = (local_58 + param_2[-2]) * 511.0f;
      fVar5 = (local_54 + param_2[-1]) * 511.0f;
      fVar6 = (local_50 + *param_2) * 511.0f;
      fVar7 = (local_4c + param_2[1]) * 3.0f;
      local_38 = static_cast<uint32_t>(std::round(fVar4 + fVar2));
      local_34 = static_cast<uint32_t>(std::round(fVar5 + fVar2));
      uVar13 = static_cast<uint32_t>(std::round(fVar6 + fVar2));
      iVar18 = static_cast<int>(std::round(fVar7 + fVar2));
      if (*(int*)(in_ECX + 0x5c) != 0) {
        pfVar1 = reinterpret_cast<float*>(*(int*)(in_ECX + 0x5c) + 0x10 + iVar17);
        local_58 = (fVar4 - static_cast<float>(static_cast<int>(local_38))) * 0.0019569471f;
        *pfVar1 = local_58 * 0.1875f + *pfVar1;
        pfVar1 = reinterpret_cast<float*>(*(int*)(in_ECX + 0x5c) + 0x10 + iVar9);
        *pfVar1 = local_58 * 0.3125f + *pfVar1;
        pfVar1 = reinterpret_cast<float*>(*(int*)(in_ECX + 0x5c) + 0x10 + iVar11);
        *pfVar1 = local_58 * 0.0625f + *pfVar1;
        pfVar1 = reinterpret_cast<float*>(*(int*)(in_ECX + 0x5c) + 0x14 + iVar17);
        local_58 = local_58 * 0.4375f;
        local_54 = (fVar5 - static_cast<float>(static_cast<int>(local_34))) * 0.0019569471f;
        *pfVar1 = local_54 * 0.1875f + *pfVar1;
        pfVar1 = reinterpret_cast<float*>(*(int*)(in_ECX + 0x5c) + 0x14 + iVar9);
        *pfVar1 = local_54 * 0.3125f + *pfVar1;
        pfVar1 = reinterpret_cast<float*>(*(int*)(in_ECX + 0x5c) + 0x14 + iVar11);
        *pfVar1 = local_54 * 0.0625f + *pfVar1;
        pfVar1 = reinterpret_cast<float*>(*(int*)(in_ECX + 0x5c) + 0x18 + iVar17);
        local_54 = local_54 * 0.4375f;
        local_50 = (fVar6 - static_cast<float>(static_cast<int>(uVar13))) * 0.0019569471f;
        *pfVar1 = local_50 * 0.1875f + *pfVar1;
        pfVar1 = reinterpret_cast<float*>(*(int*)(in_ECX + 0x5c) + 0x18 + iVar9);
        *pfVar1 = local_50 * 0.3125f + *pfVar1;
        pfVar1 = reinterpret_cast<float*>(*(int*)(in_ECX + 0x5c) + 0x18 + iVar11);
        *pfVar1 = local_50 * 0.0625f + *pfVar1;
        pfVar1 = reinterpret_cast<float*>(*(int*)(in_ECX + 0x5c) + 0x1c + iVar17);
        local_50 = local_50 * 0.4375f;
        local_4c = (fVar7 - static_cast<float>(iVar18)) * 0.33333334f;
        *pfVar1 = local_4c * 0.1875f + *pfVar1;
        pfVar1 = reinterpret_cast<float*>(*(int*)(in_ECX + 0x5c) + 0x1c + iVar9);
        *pfVar1 = local_4c * 0.3125f + *pfVar1;
        pfVar1 = reinterpret_cast<float*>(*(int*)(in_ECX + 0x5c) + 0x1c + iVar11);
        *pfVar1 = local_4c * 0.0625f + *pfVar1;
        local_4c = local_4c * 0.4375f;
      }
      uVar15 = local_38;
      if (0x1fe < static_cast<int>(local_38)) {
        uVar15 = 0x1ff;
      }
      if (static_cast<int>(uVar15) < -0x1fe) {
        local_38 = 0xfffffe01u;
      } else if (0x1fe < static_cast<int>(local_38)) {
        local_38 = 0x1ff;
      }
      uVar15 = local_34;
      if (0x1fe < static_cast<int>(local_34)) {
        uVar15 = 0x1ff;
      }
      if (static_cast<int>(uVar15) < -0x1fe) {
        local_34 = 0xfffffe01u;
      } else if (0x1fe < static_cast<int>(local_34)) {
        local_34 = 0x1ff;
      }
      uVar15 = uVar13;
      if (0x1fe < static_cast<int>(uVar13)) {
        uVar15 = 0x1ff;
      }
      if (static_cast<int>(uVar15) < -0x1fe) {
        uVar13 = 0xfffffe01u;
      } else if (0x1fe < static_cast<int>(uVar13)) {
        uVar13 = 0x1ff;
      }
      iVar16 = iVar18;
      if (2 < iVar18) {
        iVar16 = 3;
      }
      if (iVar16 < -2) {
        iVar18 = -3;
      } else if (2 < iVar18) {
        iVar18 = 3;
      }
      (void)iVar16;
      *local_8 = ((uVar13 & 0x3ff | static_cast<uint32_t>(iVar18) << 10) << 10 | local_34 & 0x3ff) << 10 | local_38 & 0x3ff;
      local_8 = local_8 + iVar14;
      param_2 = param_2 + iVar14 * 4;
      iVar9 = iVar9 + iVar10;
      iVar17 = iVar17 + iVar10;
      iVar11 = iVar11 + iVar10;
      param_1 = param_1 + 1;
    } while (param_1 < *(uint32_t*)(in_ECX + 0x68));
  }
}

// 0x607333 — observed shape
void FUN_00607333(void* self, uint32_t param_1)
{
  uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
  FUN_006011da(param_1, 0x10, 1);
  *in_ECX = reinterpret_cast<uint32_t>(&PTR_FUN_006de038);
}

// 0x607354 — observed shape
void FUN_00607354(void* self, uint32_t param_1)
{
  uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
  FUN_006011da(param_1, 0x20, 4);
  *in_ECX = reinterpret_cast<uint32_t>(&PTR_FUN_006de078);
}

// 0x607375 — observed shape
void FUN_00607375(void* self, uint32_t param_1)
{
  uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
  FUN_006011da(param_1, 0x10, 4);
  *in_ECX = reinterpret_cast<uint32_t>(&PTR_FUN_006de048);
}

// 0x607396 — observed shape
void FUN_00607396(void* self, uint32_t param_1)
{
  uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
  FUN_006011da(param_1, 0x20, 4);
  *in_ECX = reinterpret_cast<uint32_t>(&PTR_FUN_006de058);
}

// 0x6073b7 — observed shape
void FUN_006073b7(void* self, uint32_t param_1)
{
  uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
  FUN_006011da(param_1, 0x40, 4);
  *in_ECX = reinterpret_cast<uint32_t>(&PTR_FUN_006de068);
}

// 0x6073d8 — observed shape
void FUN_006073d8(void* self, uint32_t param_1)
{
  uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
  FUN_006011da(param_1, 0x40, 4);
  *in_ECX = reinterpret_cast<uint32_t>(&PTR_FUN_006de088);
}

// 0x6073f9 — observed shape
void FUN_006073f9(void* self, uint32_t param_1)
{
  uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
  FUN_006011da(param_1, 0x80, 4);
  *in_ECX = reinterpret_cast<uint32_t>(&PTR_FUN_006de098);
}

// 0x60741d — observed shape
void FUN_0060741d(void* self, uint32_t param_1, float* param_2, int param_3)
{
  uintptr_t in_ECX = reinterpret_cast<uintptr_t>(self);
  float* pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  uint32_t uVar8;
  int iVar9;
  int iVar10;
  uint32_t uVar11;
  int iVar12;
  int iVar13;
  uint32_t uVar14;
  float local_60 = 0.0f;
  float local_5c = 0.0f;
  float local_58 = 0.0f;
  float local_54 = 0.0f;
  uint32_t local_40;
  int local_3c;
  uint32_t local_38;
  int local_34;

  if (*(int*)(in_ECX + 0x54) != 0) {
    param_3 = FUN_00600136(param_3);
  }
  if (*(int*)(in_ECX + 0x10) != 0) {
    param_3 = FUN_0060164a(param_3);
  }
  uint32_t* local_8 = reinterpret_cast<uint32_t*>(
      *(int*)(in_ECX + 0x60) * param_1 +
      (*(int*)(in_ECX + 0x68) + -1) * (param_1 & 1) * 8 +
      *(int*)(in_ECX + 100) * reinterpret_cast<int>(param_2) + *(int*)(in_ECX + 0x20));
  uVar8 = param_1 & 3;
  uVar11 = reinterpret_cast<uint32_t>(param_2) & 3;
  iVar3 = *(int*)(in_ECX + 0x34);
  int iVarc;
  if ((param_1 & 1) == 0) {
    iVar13 = 0;
    iVar12 = 1;
  } else {
    iVar13 = *(int*)(in_ECX + 0x68) + -1;
    iVar12 = -1;
  }
  iVarc = iVar13;
  uint32_t in_FPUControlWord = 0;  // observed: x87 control word read and stored
  *(uint32_t*)(in_ECX + 0x7c) = in_FPUControlWord;
  if (*(int*)(in_ECX + 0x5c) != 0) {
    FUN_00601966(param_3);
  }
  param_1 = 0;
  if (*(int*)(in_ECX + 0x68) != 0) {
    iVar9 = iVar12 * 0x10;
    iVar10 = iVarc * 0x10;
    int local_10 = (iVar12 + iVarc) * 0x10;
    int local_c = (iVarc - iVar12) * 0x10;
    param_2 = reinterpret_cast<float*>(iVar10 + 8 + param_3);
    do {
      fVar2 = *(float*)(iVar3 + (uVar11 + uVar8 * 8) * 4 + (param_1 & 3) * 4);
      fVar4 = (local_60 + param_2[-2]) * 32767.0f;
      fVar5 = (local_5c + param_2[-1]) * 32767.0f;
      fVar6 = (local_58 + *param_2) * 32767.0f;
      fVar7 = (local_54 + param_2[1]) * 32767.0f;
      local_40 = static_cast<uint32_t>(std::round(fVar4 + fVar2));
      local_3c = static_cast<int>(std::round(fVar5 + fVar2));
      local_38 = static_cast<uint32_t>(std::round(fVar6 + fVar2));
      local_34 = static_cast<int>(std::round(fVar7 + fVar2));
      if (*(int*)(in_ECX + 0x5c) != 0) {
        pfVar1 = reinterpret_cast<float*>(*(int*)(in_ECX + 0x5c) + 0x10 + local_c);
        local_60 = (fVar4 - static_cast<float>(static_cast<int>(local_40))) * 3.051851e-05f;
        *pfVar1 = local_60 * 0.1875f + *pfVar1;
        pfVar1 = reinterpret_cast<float*>(*(int*)(in_ECX + 0x5c) + 0x10 + iVar10);
        *pfVar1 = local_60 * 0.3125f + *pfVar1;
        pfVar1 = reinterpret_cast<float*>(*(int*)(in_ECX + 0x5c) + 0x10 + local_10);
        *pfVar1 = local_60 * 0.0625f + *pfVar1;
        pfVar1 = reinterpret_cast<float*>(*(int*)(in_ECX + 0x5c) + 0x14 + local_c);
        local_60 = local_60 * 0.4375f;
        local_5c = (fVar5 - static_cast<float>(local_3c)) * 3.051851e-05f;
        *pfVar1 = local_5c * 0.1875f + *pfVar1;
        pfVar1 = reinterpret_cast<float*>(*(int*)(in_ECX + 0x5c) + 0x14 + iVar10);
        *pfVar1 = local_5c * 0.3125f + *pfVar1;
        pfVar1 = reinterpret_cast<float*>(*(int*)(in_ECX + 0x5c) + 0x14 + local_10);
        *pfVar1 = local_5c * 0.0625f + *pfVar1;
        pfVar1 = reinterpret_cast<float*>(*(int*)(in_ECX + 0x5c) + 0x18 + local_c);
        local_5c = local_5c * 0.4375f;
        local_58 = (fVar6 - static_cast<float>(static_cast<int>(local_38))) * 3.051851e-05f;
        *pfVar1 = local_58 * 0.1875f + *pfVar1;
        pfVar1 = reinterpret_cast<float*>(*(int*)(in_ECX + 0x5c) + 0x18 + iVar10);
        *pfVar1 = local_58 * 0.3125f + *pfVar1;
        pfVar1 = reinterpret_cast<float*>(*(int*)(in_ECX + 0x5c) + 0x18 + local_10);
        *pfVar1 = local_58 * 0.0625f + *pfVar1;
        pfVar1 = reinterpret_cast<float*>(*(int*)(in_ECX + 0x5c) + 0x1c + local_c);
        local_58 = local_58 * 0.4375f;
        local_54 = (fVar7 - static_cast<float>(local_34)) * 3.051851e-05f;
        *pfVar1 = local_54 * 0.1875f + *pfVar1;
        pfVar1 = reinterpret_cast<float*>(*(int*)(in_ECX + 0x5c) + 0x1c + iVar10);
        *pfVar1 = local_54 * 0.3125f + *pfVar1;
        pfVar1 = reinterpret_cast<float*>(*(int*)(in_ECX + 0x5c) + 0x1c + local_10);
        *pfVar1 = local_54 * 0.0625f + *pfVar1;
        local_54 = local_54 * 0.4375f;
      }
      uVar14 = local_40;
      if (0x7ffe < static_cast<int>(local_40)) {
        uVar14 = 0x7fff;
      }
      if (static_cast<int>(uVar14) < -0x7ffe) {
        local_40 = 0xffff8001u;
      } else if (0x7ffe < static_cast<int>(local_40)) {
        local_40 = 0x7fff;
      }
      iVar13 = local_3c;
      if (0x7ffe < local_3c) {
        iVar13 = 0x7fff;
      }
      if (iVar13 < -0x7ffe) {
        local_3c = -0x7fff;
      } else if (0x7ffe < local_3c) {
        local_3c = 0x7fff;
      }
      uVar14 = local_38;
      if (0x7ffe < static_cast<int>(local_38)) {
        uVar14 = 0x7fff;
      }
      if (static_cast<int>(uVar14) < -0x7ffe) {
        local_38 = 0xffff8001u;
      } else if (0x7ffe < static_cast<int>(local_38)) {
        local_38 = 0x7fff;
      }
      iVar13 = local_34;
      if (0x7ffe < local_34) {
        iVar13 = 0x7fff;
      }
      if (iVar13 < -0x7ffe) {
        local_34 = -0x7fff;
      } else if (0x7ffe < local_34) {
        local_34 = 0x7fff;
      }
      local_8[1] = static_cast<uint32_t>(local_34) << 0x10 | local_38 & 0xffff;
      *local_8 = static_cast<uint32_t>(local_3c) << 0x10 | local_40 & 0xffff;
      local_8 = local_8 + iVar12 * 2;
      param_2 = param_2 + iVar12 * 4;
      local_c = local_c + iVar9;
      local_10 = local_10 + iVar9;
      iVar10 = iVar10 + iVar9;
      param_1 = param_1 + 1;
    } while (param_1 < *(uint32_t*)(in_ECX + 0x68));
  }
}

// 0x6077f2 — observed shape
void FUN_006077f2(void* self, uint32_t param_1)
{
  uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
  FUN_006011da(param_1, 0x20, 1);
  *in_ECX = reinterpret_cast<uint32_t>(&PTR_FUN_006de0a8);
}

// 0x607813 — observed shape
void FUN_00607813(void* self, uint32_t param_1)
{
  uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
  FUN_006011da(param_1, 0x30, 1);
  *in_ECX = reinterpret_cast<uint32_t>(&PTR_FUN_006de0b8);
}

// 0x607834 — observed shape
void FUN_00607834(void* self, uint32_t param_1, uint32_t param_2, int param_3)
{
  uintptr_t in_ECX = reinterpret_cast<uintptr_t>(self);
  float* pfVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  uint32_t uVar8;
  int iVar9;
  int iVar10;
  uint32_t uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  float local_48 = 0.0f;
  float local_44 = 0.0f;

  if (*(int*)(in_ECX + 0x54) != 0) {
    param_3 = FUN_00600136(param_3);
  }
  if (*(int*)(in_ECX + 0x10) != 0) {
    param_3 = FUN_0060164a(param_3);
  }
  uVar8 = param_1 & 3;
  uVar11 = param_2 & 3;
  uint16_t* local_c = reinterpret_cast<uint16_t*>(
      *(int*)(in_ECX + 0x60) * param_1 + (*(int*)(in_ECX + 0x68) + -1) * (param_1 & 1) * 2 +
      *(int*)(in_ECX + 100) * param_2 + *(int*)(in_ECX + 0x20));
  iVar3 = *(int*)(in_ECX + 0x34);
  int iVarc;
  if ((param_1 & 1) == 0) {
    iVar13 = 0;
    param_1 = 1;
  } else {
    iVar13 = *(int*)(in_ECX + 0x68) + -1;
    param_1 = -1;
  }
  iVarc = iVar13;
  (void)param_2;
  uint32_t in_FPUControlWord = 0;  // observed: x87 control word read and stored
  *(uint32_t*)(in_ECX + 0x7c) = in_FPUControlWord;
  if (*(int*)(in_ECX + 0x5c) != 0) {
    FUN_00601966(param_3);
  }
  uint32_t local_8 = 0;
  if (*(int*)(in_ECX + 0x68) != 0) {
    iVar9 = static_cast<int>(param_1) * 0x10;
    int param2_ = (static_cast<int>(param_1) + iVarc) * 0x10;
    iVar14 = iVarc << 4;
    int param1_ = (iVarc - static_cast<int>(param_1)) * 0x10;
    do {
      pfVar1 = reinterpret_cast<float*>(iVar14 + param_3);
      thunk_FUN_005f148d(pfVar1, pfVar1);
      fVar2 = *(float*)(iVar3 + (uVar11 + uVar8 * 8) * 4 + (local_8 & 3) * 4);
      fVar5 = (local_48 + *pfVar1) * 127.0f;
      fVar6 = (local_44 + pfVar1[1]) * 127.0f;
      iVar13 = static_cast<int>(std::round(fVar5 + fVar2));
      iVar12 = static_cast<int>(std::round(fVar6 + fVar2));
      if (*(int*)(in_ECX + 0x5c) != 0) {
        pfVar1 = reinterpret_cast<float*>(*(int*)(in_ECX + 0x5c) + 0x10 + param1_);
        local_48 = (fVar5 - static_cast<float>(iVar13)) * 0.007874016f;
        *pfVar1 = local_48 * 0.1875f + *pfVar1;
        pfVar1 = reinterpret_cast<float*>(iVar14 + 0x10 + *(int*)(in_ECX + 0x5c));
        *pfVar1 = local_48 * 0.3125f + *pfVar1;
        pfVar1 = reinterpret_cast<float*>(*(int*)(in_ECX + 0x5c) + 0x10 + param2_);
        *pfVar1 = local_48 * 0.0625f + *pfVar1;
        pfVar1 = reinterpret_cast<float*>(*(int*)(in_ECX + 0x5c) + 0x14 + param1_);
        local_48 = local_48 * 0.4375f;
        local_44 = (fVar6 - static_cast<float>(iVar12)) * 0.007874016f;
        *pfVar1 = local_44 * 0.1875f + *pfVar1;
        pfVar1 = reinterpret_cast<float*>(iVar14 + 0x14 + *(int*)(in_ECX + 0x5c));
        *pfVar1 = local_44 * 0.3125f + *pfVar1;
        pfVar1 = reinterpret_cast<float*>(*(int*)(in_ECX + 0x5c) + 0x14 + param2_);
        *pfVar1 = local_44 * 0.0625f + *pfVar1;
        local_44 = local_44 * 0.4375f;
      }
      iVar4 = 0x7f;
      iVar10 = iVar13;
      if (0x7e < iVar13) {
        iVar10 = iVar4;
      }
      if (iVar10 < -0x7e) {
        iVar13 = -0x7f;
      } else if (0x7e < iVar13) {
        iVar13 = iVar4;
      }
      iVar10 = iVar12;
      if (0x7e < iVar12) {
        iVar10 = iVar4;
      }
      if (iVar10 < -0x7e) {
        iVar12 = -0x7f;
      } else if (0x7e < iVar12) {
        iVar12 = iVar4;
      }
      *local_c = static_cast<uint16_t>(static_cast<int8_t>(iVar12) << 8 | static_cast<uint8_t>(static_cast<int8_t>(iVar13)));
      local_c = local_c + static_cast<int>(param_1);
      param1_ = param1_ + iVar9;
      param2_ = param2_ + iVar9;
      iVar14 = iVar14 + iVar9;
      local_8 = local_8 + 1;
    } while (local_8 < *(uint32_t*)(in_ECX + 0x68));
    (void)param1_;
    (void)param2_;
  }
}

// 0x607aa4 — observed shape
void FUN_00607aa4(void* self, int param_1, int param_2, uint32_t* param_3)
{
  uintptr_t in_ECX = reinterpret_cast<uintptr_t>(self);
  uint32_t* puVar1;
  uint32_t uVar2;

  if (*(int*)(in_ECX + 0x10) != 0) {
    param_3 = reinterpret_cast<uint32_t*>(FUN_0060164a(reinterpret_cast<int>(param_3)));
  }
  puVar1 = reinterpret_cast<uint32_t*>(
      *(int*)(in_ECX + 0x60) * param_1 + *(int*)(in_ECX + 100) * param_2 +
      *(int*)(in_ECX + 0x20));
  uVar2 = 0;
  if (*(int*)(in_ECX + 0x68) != 0) {
    do {
      *puVar1 = *param_3;
      puVar1 = puVar1 + 1;
      uVar2 = uVar2 + 1;
      param_3 = param_3 + 4;
    } while (uVar2 < *(uint32_t*)(in_ECX + 0x68));
  }
}

// 0x607af1 — observed shape
void FUN_00607af1(void* self, int param_1, int param_2, int param_3)
{
  uintptr_t in_ECX = reinterpret_cast<uintptr_t>(self);
  uint32_t uVar1;
  int iVar2;

  uVar1 = 0;
  if (*(int*)(in_ECX + 0x10) != 0) {
    param_3 = FUN_0060164a(param_3);
  }
  iVar2 = *(int*)(in_ECX + 0x60) * param_1 + *(int*)(in_ECX + 100) * param_2 +
          *(int*)(in_ECX + 0x20);
  if (*(int*)(in_ECX + 0x68) != 0) {
    do {
      thunk_FUN_005f0fd8(iVar2, param_3, 1);
      param_3 = param_3 + 0x10;
      iVar2 = iVar2 + 2;
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint32_t*)(in_ECX + 0x68));
  }
}

// 0x607b49 — observed shape
void FUN_00607b49(void* self, int param_1, int param_2, int param_3)
{
  uintptr_t in_ECX = reinterpret_cast<uintptr_t>(self);
  uint32_t uVar1;
  int iVar2;

  uVar1 = 0;
  if (*(int*)(in_ECX + 0x10) != 0) {
    param_3 = FUN_0060164a(param_3);
  }
  iVar2 = *(int*)(in_ECX + 0x60) * param_1 + *(int*)(in_ECX + 100) * param_2 +
          *(int*)(in_ECX + 0x20);
  if (*(int*)(in_ECX + 0x68) != 0) {
    do {
      thunk_FUN_005f0fd8(iVar2, param_3, 2);
      param_3 = param_3 + 0x10;
      iVar2 = iVar2 + 4;
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint32_t*)(in_ECX + 0x68));
  }
}

// 0x607ba2 — observed shape
void FUN_00607ba2(void* self, int param_1, int param_2, uint32_t param_3)
{
  uintptr_t in_ECX = reinterpret_cast<uintptr_t>(self);

  if (*(int*)(in_ECX + 0x10) != 0) {
    param_3 = static_cast<uint32_t>(FUN_0060164a(static_cast<int>(param_3)));
  }
  thunk_FUN_005f0fd8(*(int*)(in_ECX + 0x60) * param_1 + *(int*)(in_ECX + 100) * param_2 +
                     *(int*)(in_ECX + 0x20), static_cast<int>(param_3), *(int*)(in_ECX + 0x68) << 2);
}
