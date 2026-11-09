#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_00538630(void* param_1);
extern void FUN_00545cc0();
extern int FUN_00533c78(int param_1);
extern int FUN_00547f20(int param_1, int param_2);
extern void FUN_005460e0(void* param_1);
extern void* DAT_00727898;
extern void FUN_00557b10(void* param_1);
extern void FUN_006b34a0(int param_1);
extern void FUN_005606f0(uint32_t param_1, void* param_2);
extern void* FUN_00557d80(const char* param_1, int param_2);
extern float DAT_00727430;
extern float DAT_00727434;
extern float DAT_00727438;
extern float DAT_00717a7c;

// 0x547fa0 — observed shape
void FUN_00547fa0(void* self, int* param_1)
{
  int* piVar1 = param_1;
  int* in_ECX = static_cast<int*>(self);
  // unaff_ESI preserved via extra param
  FUN_00538630(param_1);
  if (static_cast<uint32_t>(piVar1[7]) < 0x500000b) {
    FUN_00545cc0();
    int uVar5 = 4;
    typedef void (__cdecl *Fn)(void**, int);
    Fn fn = reinterpret_cast<Fn>(*reinterpret_cast<void**>(*(intptr_t*)piVar1 + 0, 0) + 8);
    // *param: vtable dispatch at piVar1[0x57] + 8
    int* vtable57 = *reinterpret_cast<int**>(reinterpret_cast<uint8_t*>(piVar1) + 0x57*4);
    typedef void (__cdecl *Fn57)(void**, int);
    reinterpret_cast<Fn57>(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(vtable57) + 8))(&param_1, 4);
    // unaff_ESI / in_ECX checks handled generically below when supplied
    (void)fn; (void)uVar5; (void)in_ECX;
  } else {
    FUN_005460e0(reinterpret_cast<uint8_t*>(in_ECX) + 0xc);
  }
}

// 0x548050 — observed shape
void FUN_00548050(void* self, int param_1)
{
  int in_ECX = reinterpret_cast<int>(self);
  uint32_t uVar1;
  int iVar2 = param_1;
  // local_4 = FUN_00557b10(DAT_00727898)
  extern void FUN_00557b10_res();
  (void)in_ECX;
  uVar1 = *reinterpret_cast<uint32_t*>(param_1 + 0xc);
  if (*reinterpret_cast<uint32_t*>(param_1 + 8) <= uVar1) {
    FUN_006b34a0(*reinterpret_cast<int*>(param_1 + 0x14) + uVar1);
  }
  FUN_005606f0(uVar1, &DAT_00727898);
  void* result = FUN_00557d80("m_pcName", *reinterpret_cast<int*>(in_ECX + 0xc));
  uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
  if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
    FUN_006b34a0(*reinterpret_cast<int*>(iVar2 + 0x14) + uVar1);
  }
  FUN_005606f0(uVar1, &result);
}

// 0x5480d0 — observed shape
uint32_t FUN_005480d0(void* self, float* param_1)
{
  float* in_ECX = static_cast<float*>(self);
  if ((in_ECX[3] == param_1[3]) && (*in_ECX == *param_1) && (in_ECX[1] == param_1[1]) && (in_ECX[2] == param_1[2])) {
    return 1;
  }
  return 0;
}

// 0x548120 — observed shape
void FUN_00548120(void* self, int param_1, float* param_2)
{
  float* in_ECX = static_cast<float*>(self);
  float local_24, local_20, local_1c, local_18, local_14;
  float fVar1, fVar2;
  int iVar5;
  if (param_1 < 1) {
    in_ECX[0] = DAT_00727430;
    in_ECX[1] = DAT_00727434;
    in_ECX[2] = DAT_00727438;
    in_ECX[3] = 0.0f;
    return;
  }
  local_24 = param_2[0]; local_20 = param_2[1]; local_1c = param_2[2];
  local_18 = param_2[0]; local_14 = param_2[1]; fVar1 = param_2[2];
  iVar5 = 1;
  if (3 < param_1 + -1) {
    int iVar4 = ((param_1 - 5U >> 2) + 1);
    float* pfVar3 = param_2 + 5;
    iVar5 = iVar4 * 4 + 1;
    do {
      if (pfVar3[-2] < local_24) local_24 = pfVar3[-2];
      if (pfVar3[-1] < local_20) local_20 = pfVar3[-1];
      if (*pfVar3 < local_1c) local_1c = *pfVar3;
      if (local_18 < pfVar3[-2]) local_18 = pfVar3[-2];
      if (local_14 < pfVar3[-1]) local_14 = pfVar3[-1];
      if (fVar1 < *pfVar3) fVar1 = *pfVar3;
      if (pfVar3[1] < local_24) local_24 = pfVar3[1];
      if (pfVar3[2] < local_20) local_20 = pfVar3[2];
      if (pfVar3[3] < local_1c) local_1c = pfVar3[3];
      if (local_18 < pfVar3[1]) local_18 = pfVar3[1];
      if (local_14 < pfVar3[2]) local_14 = pfVar3[2];
      if (fVar1 < pfVar3[3]) fVar1 = pfVar3[3];
      if (pfVar3[4] < local_24) local_24 = pfVar3[4];
      if (pfVar3[5] < local_20) local_20 = pfVar3[5];
      if (pfVar3[6] < local_1c) local_1c = pfVar3[6];
      if (local_18 < pfVar3[4]) local_18 = pfVar3[4];
      if (local_14 < pfVar3[5]) local_14 = pfVar3[5];
      if (fVar1 < pfVar3[6]) fVar1 = pfVar3[6];
      if (pfVar3[7] < local_24) local_24 = pfVar3[7];
      if (pfVar3[8] < local_20) local_20 = pfVar3[8];
      if (pfVar3[9] < local_1c) local_1c = pfVar3[9];
      if (local_18 < pfVar3[7]) local_18 = pfVar3[7];
      if (local_14 < pfVar3[8]) local_14 = pfVar3[8];
      if (fVar1 < pfVar3[9]) fVar1 = pfVar3[9];
      pfVar3 += 0xc; iVar4--;
    } while (iVar4 != 0);
  }
  if (iVar5 < param_1) {
    float* pfVar3 = param_2 + iVar5 * 3 + 2;
    int rem = param_1 - iVar5;
    do {
      if (pfVar3[-2] < local_24) local_24 = pfVar3[-2];
      if (pfVar3[-1] < local_20) local_20 = pfVar3[-1];
      if (*pfVar3 < local_1c) local_1c = *pfVar3;
      if (local_18 < pfVar3[-2]) local_18 = pfVar3[-2];
      if (local_14 < pfVar3[-1]) local_14 = pfVar3[-1];
      if (fVar1 < *pfVar3) fVar1 = *pfVar3;
      pfVar3 += 3; rem--;
    } while (rem != 0);
  }
  iVar5 = 0;
  *in_ECX = (local_18 + local_24) * 0.5f;
  in_ECX[1] = (local_14 + local_20) * 0.5f;
  fVar2 = 0.0f;
  in_ECX[2] = (fVar1 + local_1c) * 0.5f;
  if (3 < param_1) {
    int iVar4 = ((param_1 - 4U >> 2) + 1);
    float* pfVar3 = param_2 + 5;
    iVar5 = iVar4 * 4;
    do {
      fVar1 = (pfVar3[-5] - in_ECX[0]) * (pfVar3[-5] - in_ECX[0]) + (pfVar3[-4] - in_ECX[1]) * (pfVar3[-4] - in_ECX[1]) + (pfVar3[-3] - in_ECX[2]) * (pfVar3[-3] - in_ECX[2]);
      if (fVar2 < fVar1) fVar2 = fVar1;
      fVar1 = (pfVar3[-2] - in_ECX[0]) * (pfVar3[-2] - in_ECX[0]) + (pfVar3[-1] - in_ECX[1]) * (pfVar3[-1] - in_ECX[1]) + (*pfVar3 - in_ECX[2]) * (*pfVar3 - in_ECX[2]);
      if (fVar2 < fVar1) fVar2 = fVar1;
      fVar1 = (pfVar3[1] - in_ECX[0]) * (pfVar3[1] - in_ECX[0]) + (pfVar3[2] - in_ECX[1]) * (pfVar3[2] - in_ECX[1]) + (pfVar3[3] - in_ECX[2]) * (pfVar3[3] - in_ECX[2]);
      if (fVar2 < fVar1) fVar2 = fVar1;
      fVar1 = (pfVar3[4] - in_ECX[0]) * (pfVar3[4] - in_ECX[0]) + (pfVar3[5] - in_ECX[1]) * (pfVar3[5] - in_ECX[1]) + (pfVar3[6] - in_ECX[2]) * (pfVar3[6] - in_ECX[2]);
      if (fVar2 < fVar1) fVar2 = fVar1;
      pfVar3 += 0xc; iVar4--;
    } while (iVar4 != 0);
  }
  if (iVar5 < param_1) {
    int rem = param_1 - iVar5;
    float* p2 = param_2 + iVar5 * 3 + 2;
    do {
      fVar1 = (p2[-2] - in_ECX[0]) * (p2[-2] - in_ECX[0]) + (p2[-1] - in_ECX[1]) * (p2[-1] - in_ECX[1]) + (*p2 - in_ECX[2]) * (*p2 - in_ECX[2]);
      if (fVar2 < fVar1) fVar2 = fVar1;
      p2 += 3; rem--;
    } while (rem != 0);
  }
  in_ECX[3] = SQRT(fVar2);
}

// 0x548600 — observed shape
void FUN_00548600(void* self, float* param_1)
{
  float* in_ECX = static_cast<float*>(self);
  float fVar4 = in_ECX[0] - param_1[0];
  float fVar5 = in_ECX[1] - param_1[1];
  float fVar6 = in_ECX[2] - param_1[2];
  float fVar7 = fVar5 * fVar5 + fVar6 * fVar6 + fVar4 * fVar4;
  float fVar1 = param_1[3] - in_ECX[3];
  bool bVar3 = fVar7 <= fVar1 * fVar1;
  if (fVar1 < 0.0f) {
    if (bVar3) return;
  } else if (bVar3) {
    in_ECX[0] = param_1[0]; in_ECX[1] = param_1[1]; in_ECX[2] = param_1[2]; in_ECX[3] = param_1[3];
    return;
  }
  fVar7 = SQRT(fVar7);
  if (DAT_00717a7c < fVar7) {
    float fVar8 = (fVar7 - fVar1) / (fVar7 + fVar7);
    in_ECX[0] = fVar4 * fVar8 + param_1[0];
    in_ECX[1] = fVar5 * fVar8 + param_1[1];
    in_ECX[2] = fVar6 * fVar8 + param_1[2];
  }
  in_ECX[3] = (fVar7 + in_ECX[3] + param_1[3]) * 0.5f;
}

// Additional declarations for appended reconstructions
extern void* FUN_0053ca60(void* param_1, intptr_t param_2);
extern void* FUN_0053c8d0(void* param_1, void* param_2);
extern void* FUN_0053cac0(void* param_1, float* param_2, void* param_3);
extern void FUN_0053c1d0(void* self);
extern long double FUN_0053c6b0(float param_1, float param_2, float param_3, float param_4);
extern void FUN_0053c800(float param_1, float param_2, float param_3, float param_4);
extern void FUN_00491640(void);
extern void FUN_004916d0(void* param_1, float* param_2);
extern float DAT_007179b0[];
extern void FUN_00557990(void);
extern void FUN_00551110(void* self);
extern void FUN_00535600(void* self);
extern void FUN_00535300(void* param_1, uint32_t param_2);
extern uint8_t PTR_FUN_006c1d28;
extern void FUN_00535880(void* self);
extern void FUN_005356e0(void* param_1);
extern void FUN_00535110(void* param_1);
extern void FUN_005357d0(void* param_1);
extern void FUN_00535150(void* param_1);
extern char FUN_00535460(void* param_1);
extern char FUN_00428470(int param_1);
extern void FUN_00535970(void* param_1);
extern void* DAT_007278a8;
extern void* FUN_00557cf0(const char* param_1, uint32_t param_2);
extern void* FUN_00535050(const char* param_1);
extern void operator_delete(void* param_1);
extern "C" int sprintf(char* param_1, const char* param_2, ...);

// 0x548720 — observed shape
void FUN_00548720(void* self, int param_1, int param_2)
{
  uint8_t* in_ECX = static_cast<uint8_t*>(self);
  uint8_t local_18[24];
  float* pfVar6 = reinterpret_cast<float*>(FUN_0053ca60(local_18, param_1));
  float fVar1 = *reinterpret_cast<float*>(param_2 + 0x30);
  float fVar2 = pfVar6[1];
  float fVar3 = pfVar6[2];
  float fVar4 = *reinterpret_cast<float*>(param_2 + 0x28);
  float fVar5 = *reinterpret_cast<float*>(param_2 + 0x2c);
  *reinterpret_cast<float*>(in_ECX) = fVar1 * *pfVar6 + *reinterpret_cast<float*>(param_2 + 0x24);
  reinterpret_cast<float*>(in_ECX)[1] = fVar1 * fVar2 + fVar4;
  reinterpret_cast<float*>(in_ECX)[2] = fVar1 * fVar3 + fVar5;
  reinterpret_cast<float*>(in_ECX)[3] =
      *reinterpret_cast<float*>(param_1 + 0xc) * *reinterpret_cast<float*>(param_2 + 0x30);
}

// 0x548880 — observed shape
char* FUN_00548880(char* param_1, uint32_t param_2)
{
  char cVar1;
  char* pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  intptr_t arg = reinterpret_cast<intptr_t>(pcVar2) +
                 (0x16 - (reinterpret_cast<intptr_t>(param_1) + 1));
  pcVar2 = reinterpret_cast<char*>(static_cast<intptr_t>(FUN_00533c78(static_cast<int>(arg))));
  switch (param_2) {
  case 0:
    sprintf(pcVar2, "%s = ALWAYS_FACE_CAMERA", param_1);
    return pcVar2;
  case 1:
    sprintf(pcVar2, "%s = ROTATE_ABOUT_UP", param_1);
    return pcVar2;
  case 2:
    sprintf(pcVar2, "%s = RIGID_FACE_CAMERA", param_1);
    return pcVar2;
  case 3:
    sprintf(pcVar2, "%s = ALWAYS_FACE_CENTER", param_1);
    return pcVar2;
  case 4:
    sprintf(pcVar2, "%s = RIGID_FACE_CENTER", param_1);
  }
  return pcVar2;
}

// 0x548940 — observed shape
uint32_t FUN_00548940(int param_1, float param_2, float param_3, float param_4,
                      float* param_5, uint32_t* param_6, uint32_t* param_7)
{
  float fVar1 = *reinterpret_cast<float*>(param_1 + 0x90) - param_2;
  float fVar2 = *reinterpret_cast<float*>(param_1 + 0x94) - param_3;
  float fVar3 = *reinterpret_cast<float*>(param_1 + 0x98) - param_4;
  if (fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3 < 0.001f) {
    return 0;
  }
  FUN_00491640();
  uint32_t* puVar6 = param_7;
  uint32_t* puVar8 = param_6;
  float* pfVar5 = param_5;
  param_2 = -*reinterpret_cast<float*>(param_1 + 0x104);
  param_3 = -*reinterpret_cast<float*>(param_1 + 0x108);
  param_4 = *reinterpret_cast<float*>(param_1 + 0x10c);
  *param_5 = param_2;
  param_5[1] = param_3;
  param_4 = -param_4;
  param_5[2] = param_4;
  *param_6 = *reinterpret_cast<uint32_t*>(param_1 + 0x110);
  param_6[1] = *reinterpret_cast<uint32_t*>(param_1 + 0x114);
  param_6[2] = *reinterpret_cast<uint32_t*>(param_1 + 0x118);
  *param_7 = *reinterpret_cast<uint32_t*>(param_1 + 0x11c);
  param_7[1] = *reinterpret_cast<uint32_t*>(param_1 + 0x120);
  param_7[2] = *reinterpret_cast<uint32_t*>(param_1 + 0x124);
  float fVar4 = fVar1 * *param_5 + fVar2 * param_5[1] + fVar3 * param_5[2];
  if (fVar4 < 0.999999f) {
    FUN_004916d0(&param_2, param_5);
    float fVar10 = param_2;
    float fVar11 = param_3;
    float fVar12 = param_4;
    long double fVar9 = FUN_0053c6b0(fVar4, param_2, param_3, param_4);
    FUN_0053c800(static_cast<float>(fVar9), fVar10, fVar11, fVar12);
    *pfVar5 = fVar1;
    pfVar5[1] = fVar2;
    pfVar5[2] = fVar3;
    uint32_t* puVar7 =
        reinterpret_cast<uint32_t*>(FUN_0053ca60(&param_2, reinterpret_cast<intptr_t>(puVar8)));
    *puVar8 = *puVar7;
    puVar8[1] = puVar7[1];
    puVar8[2] = puVar7[2];
    puVar8 = reinterpret_cast<uint32_t*>(FUN_0053ca60(&param_2, reinterpret_cast<intptr_t>(puVar6)));
    *puVar6 = *puVar8;
    puVar6[1] = puVar8[1];
    puVar6[2] = puVar8[2];
  }
  return 1;
}

// 0x548b20 — observed shape
// Ghidra typed local_34 as 9 dwords; the copy loop below transfers 13.
void FUN_00548b20(void* self, uint32_t* param_1, void* param_2)
{
  uint8_t* in_ECX = static_cast<uint8_t*>(self);
  uint8_t* p2 = static_cast<uint8_t*>(param_2);
  uint8_t local_70[24];
  uint8_t local_58[36];
  uint32_t local_34[13];
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  int iVar4;

  local_4 = *reinterpret_cast<float*>(p2 + 0x30) * *reinterpret_cast<float*>(in_ECX + 0x30);
  uint32_t* puVar2 = reinterpret_cast<uint32_t*>(FUN_0053c8d0(local_58, p2));
  uint32_t* puVar5 = local_34;
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar5 = puVar5 + 1;
  }
  float* pfVar3 =
      reinterpret_cast<float*>(FUN_0053ca60(local_70, reinterpret_cast<intptr_t>(p2 + 0x24)));
  float fVar1 = *reinterpret_cast<float*>(in_ECX + 0x30);
  local_10 = fVar1 * *pfVar3 + *reinterpret_cast<float*>(in_ECX + 0x24);
  local_c = fVar1 * pfVar3[1] + *reinterpret_cast<float*>(in_ECX + 0x28);
  local_8 = fVar1 * pfVar3[2] + *reinterpret_cast<float*>(in_ECX + 0x2c);
  puVar2 = local_34;
  for (iVar4 = 0xd; iVar4 != 0; iVar4 = iVar4 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
}

// 0x548bf0 — observed shape
void FUN_00548bf0(void* self, uint8_t param_1)
{
  void* in_ECX = self;
  FUN_0053c1d0(in_ECX);
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
}

// 0x548c10 — observed shape
void FUN_00548c10(void* self, int param_1)
{
  uint8_t* in_ECX = static_cast<uint8_t*>(self);
  int* piVar1;
  float fVar2;
  float fVar3;
  uint8_t bVar4;
  char cVar5;
  uint32_t* puVar6;
  float* pfVar7;
  int iVar8;
  int iVar9;
  uint32_t* puVar10;
  uint32_t uVar11;
  uint32_t* puVar12;
  float* pfVar13;
  float local_114;
  float local_110;
  float local_10c;
  float local_108;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  float local_f0;
  // The 9-float matrix block spans local_ec..local_cc; local_c0 follows it.
  float local_ec[10];
  float& local_d0 = local_ec[7];
  float& local_cc = local_ec[8];
  float& local_c0 = local_ec[9];
  float local_c8;
  float local_c4;
  uint8_t local_bc[12];
  uint8_t local_b0[12];
  uint8_t local_a4[12];
  uint8_t local_98[12];
  uint8_t local_8c[12];
  uint8_t local_80[12];
  uint8_t local_74[12];
  uint32_t local_68[13];
  uint32_t local_34[13];

  if (*reinterpret_cast<int*>(in_ECX + 0x24) == 0) {
    FUN_00557990();
  }
  else {
    puVar10 = reinterpret_cast<uint32_t*>(
        static_cast<intptr_t>(*reinterpret_cast<int*>(in_ECX + 0x24) + 0x6c));
    puVar6 = local_68;
    for (iVar8 = 0xd; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar6 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  puVar6 = reinterpret_cast<uint32_t*>(FUN_00548b20(self, local_34, in_ECX + 0x38));
  bVar4 = *reinterpret_cast<uint8_t*>(in_ECX + 0xec);
  puVar10 = reinterpret_cast<uint32_t*>(in_ECX + 0x6c);
  puVar12 = puVar10;
  for (iVar8 = 0xd; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar12 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar12 = puVar12 + 1;
  }
  bVar4 = bVar4 & 7;
  pfVar7 = DAT_007179b0;
  pfVar13 = local_ec;
  for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pfVar13 = *pfVar7;
    pfVar7 = pfVar7 + 1;
    pfVar13 = pfVar13 + 1;
  }
  switch (bVar4) {
  case 0:
  case 3:
    if (bVar4 == 3) {
      cVar5 = static_cast<char>(
          FUN_00548940(param_1, *reinterpret_cast<float*>(in_ECX + 0x90),
                       *reinterpret_cast<float*>(in_ECX + 0x94),
                       *reinterpret_cast<float*>(in_ECX + 0x98), &local_114,
                       reinterpret_cast<uint32_t*>(&local_108),
                       reinterpret_cast<uint32_t*>(&local_fc)));
      if (cVar5 == '\0') break;
    }
    else {
      local_114 = -*reinterpret_cast<float*>(param_1 + 0x104);
      local_110 = -*reinterpret_cast<float*>(param_1 + 0x108);
      local_10c = -*reinterpret_cast<float*>(param_1 + 0x10c);
      local_108 = *reinterpret_cast<float*>(param_1 + 0x110);
      local_104 = *reinterpret_cast<float*>(param_1 + 0x114);
      local_100 = *reinterpret_cast<float*>(param_1 + 0x118);
      local_fc = *reinterpret_cast<float*>(param_1 + 0x11c);
      local_f8 = *reinterpret_cast<float*>(param_1 + 0x120);
      local_f4 = *reinterpret_cast<float*>(param_1 + 0x124);
    }
    pfVar7 = reinterpret_cast<float*>(FUN_0053cac0(local_80, &local_114, puVar10));
    local_114 = *pfVar7;
    local_110 = pfVar7[1];
    local_10c = pfVar7[2];
    pfVar7 = reinterpret_cast<float*>(FUN_0053cac0(local_8c, &local_108, puVar10));
    local_108 = *pfVar7;
    local_104 = pfVar7[1];
    local_100 = pfVar7[2];
    pfVar7 = reinterpret_cast<float*>(FUN_0053cac0(local_bc, &local_fc, puVar10));
    local_fc = *pfVar7;
    local_f8 = pfVar7[1];
    local_f4 = pfVar7[2];
    fVar2 = SQRT(local_f8 * local_f8 + local_104 * local_104);
    if (fVar2 <= 1e-06f) {
      local_ec[2] = local_114;
      local_ec[0] = -local_fc;
      local_ec[3] = -local_f8;
      local_ec[6] = -local_f4;
      local_ec[5] = local_110;
      local_ec[1] = -local_108;
      local_ec[4] = -local_104;
      local_d0 = -local_100;
      local_cc = local_10c;
      local_c0 = local_d0;
    }
    else {
      fVar2 = 1.0f / fVar2;
      local_ec[2] = local_114;
      local_ec[5] = local_110;
      local_cc = local_10c;
      fVar3 = local_104 * fVar2;
      fVar2 = -(fVar2 * local_f8);
      local_ec[0] = local_fc * fVar3 + local_108 * fVar2;
      local_ec[3] = fVar3 * local_f8 + local_104 * fVar2;
      local_ec[6] = local_f4 * fVar3 + local_100 * fVar2;
      local_ec[1] = local_108 * fVar3 - local_fc * fVar2;
      local_ec[4] = fVar3 * local_104 - fVar2 * local_f8;
      local_d0 = local_100 * fVar3 - local_f4 * fVar2;
    }
    break;
  case 1:
    local_c8 = *reinterpret_cast<float*>(param_1 + 0x90) - *reinterpret_cast<float*>(in_ECX + 0x90);
    local_c4 = *reinterpret_cast<float*>(param_1 + 0x94) - *reinterpret_cast<float*>(in_ECX + 0x94);
    local_f0 = *reinterpret_cast<float*>(in_ECX + 0x9c);
    local_c0 = *reinterpret_cast<float*>(param_1 + 0x98) - *reinterpret_cast<float*>(in_ECX + 0x98);
    pfVar7 = reinterpret_cast<float*>(FUN_0053cac0(local_98, &local_c8, puVar10));
    local_114 = (1.0f / local_f0) * *pfVar7;
    local_10c = (1.0f / local_f0) * pfVar7[2];
    fVar2 = SQRT(local_114 * local_114 + local_10c * local_10c);
    if (1e-12f <= fVar2) {
      local_ec[3] = 0.0f;
      local_f0 = 1.0f / fVar2;
      local_ec[1] = 0.0f;
      local_ec[4] = 1.0f;
      local_d0 = 0.0f;
      local_ec[5] = 0.0f;
      local_ec[2] = local_114 * local_f0;
      local_ec[0] = local_10c * local_f0;
      local_ec[6] = -local_ec[2];
      local_cc = local_ec[0];
    }
    break;
  case 2:
  case 4:
    if (bVar4 == 4) {
      cVar5 = static_cast<char>(
          FUN_00548940(param_1, *reinterpret_cast<float*>(in_ECX + 0x90),
                       *reinterpret_cast<float*>(in_ECX + 0x94),
                       *reinterpret_cast<float*>(in_ECX + 0x98), &local_fc,
                       reinterpret_cast<uint32_t*>(&local_108),
                       reinterpret_cast<uint32_t*>(&local_114)));
      if (cVar5 == '\0') break;
    }
    else {
      local_fc = -*reinterpret_cast<float*>(param_1 + 0x104);
      local_f8 = -*reinterpret_cast<float*>(param_1 + 0x108);
      local_f4 = -*reinterpret_cast<float*>(param_1 + 0x10c);
      local_108 = *reinterpret_cast<float*>(param_1 + 0x110);
      local_104 = *reinterpret_cast<float*>(param_1 + 0x114);
      local_100 = *reinterpret_cast<float*>(param_1 + 0x118);
      local_114 = *reinterpret_cast<float*>(param_1 + 0x11c);
      local_110 = *reinterpret_cast<float*>(param_1 + 0x120);
      local_10c = *reinterpret_cast<float*>(param_1 + 0x124);
    }
    pfVar7 = reinterpret_cast<float*>(FUN_0053cac0(local_74, &local_fc, puVar10));
    local_fc = *pfVar7;
    local_f8 = pfVar7[1];
    local_f4 = pfVar7[2];
    pfVar7 = reinterpret_cast<float*>(FUN_0053cac0(local_b0, &local_108, puVar10));
    local_108 = *pfVar7;
    local_104 = pfVar7[1];
    local_100 = pfVar7[2];
    pfVar7 = reinterpret_cast<float*>(FUN_0053cac0(local_a4, &local_114, puVar10));
    local_114 = *pfVar7;
    local_110 = pfVar7[1];
    local_10c = pfVar7[2];
    local_ec[1] = local_108;
    local_ec[4] = local_104;
    local_d0 = local_100;
    local_ec[2] = local_fc;
    local_ec[5] = local_f8;
    local_cc = local_f4;
    local_ec[0] = local_114;
    local_ec[3] = local_110;
    local_ec[6] = local_10c;
  }
  puVar6 = reinterpret_cast<uint32_t*>(FUN_0053c8d0(local_34, local_ec));
  iVar8 = *reinterpret_cast<int*>(in_ECX + 0xc0);
  for (iVar9 = 9; iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar10 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar10 = puVar10 + 1;
  }
  uVar11 = 0;
  if (iVar8 != 0) {
    do {
      piVar1 = *reinterpret_cast<int**>(
          *reinterpret_cast<int*>(in_ECX + 0xb8) + uVar11 * 4);
      if (piVar1 != nullptr) {
        typedef void (__cdecl *Fn)(uint32_t, uint8_t);
        int vtbl = *piVar1;
        Fn fn = *reinterpret_cast<Fn*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(vtbl)) + 0x48);
        fn(*reinterpret_cast<uint32_t*>(in_ECX + 0xf0), *reinterpret_cast<uint8_t*>(in_ECX + 0xf4));
      }
      uVar11 = uVar11 + 1;
    } while (uVar11 < *reinterpret_cast<uint32_t*>(in_ECX + 0xc0));
  }
}

// 0x549470 — observed shape
void FUN_00549470(void* self)
{
  void** in_ECX = static_cast<void**>(self);
  *in_ECX = &PTR_FUN_006c1d28;
  FUN_00551110(self);
  FUN_00535600(self);
}

// 0x549490 — observed shape
void FUN_00549490(void* self, int param_1, uint32_t param_2)
{
  uint8_t* in_ECX = static_cast<uint8_t*>(self);
  FUN_00535300(reinterpret_cast<void*>(static_cast<intptr_t>(param_1)), param_2);
  *reinterpret_cast<uint32_t*>(param_1 + 0xe4) = *reinterpret_cast<uint32_t*>(in_ECX + 0xe4);
  *reinterpret_cast<uint32_t*>(param_1 + 0xe8) = *reinterpret_cast<uint32_t*>(in_ECX + 0xe8);
  *reinterpret_cast<uint32_t*>(param_1 + 0xec) = *reinterpret_cast<uint32_t*>(in_ECX + 0xec);
  *reinterpret_cast<uint32_t*>(param_1 + 0xf0) = *reinterpret_cast<uint32_t*>(in_ECX + 0xf0);
  *reinterpret_cast<uint32_t*>(param_1 + 0xf4) = *reinterpret_cast<uint32_t*>(in_ECX + 0xf4);
  *reinterpret_cast<uint32_t*>(param_1 + 0xf8) = *reinterpret_cast<uint32_t*>(in_ECX + 0xf8);
  *reinterpret_cast<uint32_t*>(param_1 + 0xfc) = *reinterpret_cast<uint32_t*>(in_ECX + 0xfc);
  *reinterpret_cast<uint32_t*>(param_1 + 0x100) = *reinterpret_cast<uint32_t*>(in_ECX + 0x100);
  *reinterpret_cast<uint32_t*>(param_1 + 0x104) = *reinterpret_cast<uint32_t*>(in_ECX + 0x104);
  *reinterpret_cast<uint32_t*>(param_1 + 0x108) = *reinterpret_cast<uint32_t*>(in_ECX + 0x108);
}

// 0x549540 — observed shape
void FUN_00549540(void* self)
{
  uint32_t* in_ECX = static_cast<uint32_t*>(self);
  FUN_00535880(self);
  *in_ECX = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c1d28));
  in_ECX[0x3a] = 0;
  in_ECX[0x3b] = 0;
  in_ECX[0x3c] = 0;
  in_ECX[0x3d] = 0;
  in_ECX[0x3e] = 0;
  in_ECX[0x3f] = 0;
  in_ECX[0x40] = 0;
  in_ECX[0x41] = 0;
  in_ECX[0x42] = 0;
  in_ECX[0x39] = 0x3f800000;
  in_ECX[0x3a] = 0x3f800000;
  in_ECX[0x3b] = 0x3f800000;
  in_ECX[0x3c] = 0x3f800000;
  in_ECX[0x3d] = 0x3f800000;
  in_ECX[0x3e] = 0x3f800000;
  in_ECX[0x3f] = 0x3f800000;
  in_ECX[0x40] = 0x3f800000;
  in_ECX[0x41] = 0x3f800000;
  in_ECX[0x42] = 0x3f800000;
  in_ECX[0x43] = 0;
}

// 0x5495e0 — observed shape
void FUN_005495e0(void* self, uint8_t param_1)
{
  void** in_ECX = static_cast<void**>(self);
  *in_ECX = &PTR_FUN_006c1d28;
  FUN_00551110(self);
  FUN_00535600(self);
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x549610 — observed shape
void FUN_00549610(void* self, int param_1)
{
  uint8_t* in_ECX = static_cast<uint8_t*>(self);
  FUN_005356e0(reinterpret_cast<void*>(static_cast<intptr_t>(param_1)));
  int* piVar = *reinterpret_cast<int**>(param_1 + 0x15c);
  typedef void (__cdecl *Fn)(void*, int);
  int vtbl = *piVar;
  Fn fn = *reinterpret_cast<Fn*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(vtbl)) + 8);
  fn(in_ECX + 0xe4, 4);
  FUN_00535110(reinterpret_cast<void*>(static_cast<intptr_t>(param_1)));
  FUN_00535110(reinterpret_cast<void*>(static_cast<intptr_t>(param_1)));
  FUN_00535110(reinterpret_cast<void*>(static_cast<intptr_t>(param_1)));
}

// 0x549660 — observed shape
void FUN_00549660(void* self, int param_1)
{
  uint8_t* in_ECX = static_cast<uint8_t*>(self);
  FUN_005357d0(reinterpret_cast<void*>(static_cast<intptr_t>(param_1)));
  int* piVar = *reinterpret_cast<int**>(param_1 + 0x160);
  typedef void (__cdecl *Fn)(void*, int);
  int vtbl = *piVar;
  Fn fn = *reinterpret_cast<Fn*>(reinterpret_cast<uint8_t*>(static_cast<intptr_t>(vtbl)) + 0xc);
  fn(in_ECX + 0xe4, 4);
  FUN_00535150(reinterpret_cast<void*>(static_cast<intptr_t>(param_1)));
  FUN_00535150(reinterpret_cast<void*>(static_cast<intptr_t>(param_1)));
  FUN_00535150(reinterpret_cast<void*>(static_cast<intptr_t>(param_1)));
}

// 0x5496b0 — observed shape
uint32_t FUN_005496b0(void* self, int param_1)
{
  uint8_t* in_ECX = static_cast<uint8_t*>(self);
  char cVar1 = FUN_00535460(reinterpret_cast<void*>(static_cast<intptr_t>(param_1)));
  if (cVar1 != '\0') {
    if (*reinterpret_cast<float*>(in_ECX + 0xe4) == *reinterpret_cast<float*>(param_1 + 0xe4)) {
      cVar1 = FUN_00428470(param_1 + 0xe8);
      if (cVar1 == '\0') {
        cVar1 = FUN_00428470(param_1 + 0xf4);
        if (cVar1 == '\0') {
          cVar1 = FUN_00428470(param_1 + 0x100);
          if (cVar1 == '\0') {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

// 0x549730 — observed shape
void FUN_00549730(void* self, int param_1)
{
  uint8_t* in_ECX = static_cast<uint8_t*>(self);
  int iVar2 = param_1;
  uint32_t uVar1;
  typedef void* (*SerializeFn)(void*);
  FUN_00535970(reinterpret_cast<void*>(static_cast<intptr_t>(param_1)));
  uint32_t value = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(
      reinterpret_cast<SerializeFn>(&FUN_00557b10)(DAT_007278a8)));
  uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
  if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
    FUN_006b34a0(*reinterpret_cast<int*>(iVar2 + 0x14) + uVar1);
  }
  FUN_005606f0(uVar1, &value);

  value = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(
      FUN_00557cf0("m_fDimmer", *reinterpret_cast<uint32_t*>(in_ECX + 0xe4))));
  uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
  if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
    FUN_006b34a0(*reinterpret_cast<int*>(iVar2 + 0x14) + uVar1);
  }
  FUN_005606f0(uVar1, &value);

  value = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(FUN_00535050("m_kAmb")));
  uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
  if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
    FUN_006b34a0(*reinterpret_cast<int*>(iVar2 + 0x14) + uVar1);
  }
  FUN_005606f0(uVar1, &value);

  value = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(FUN_00535050("m_kDiff")));
  uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
  if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
    FUN_006b34a0(*reinterpret_cast<int*>(iVar2 + 0x14) + uVar1);
  }
  FUN_005606f0(uVar1, &value);

  value = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(FUN_00535050("m_kSpec")));
  uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
  if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
    FUN_006b34a0(*reinterpret_cast<int*>(iVar2 + 0x14) + uVar1);
  }
  FUN_005606f0(uVar1, &value);
}

// 0x549860 — observed shape
void FUN_00549860(void* self, int param_1, uint32_t param_2)
{
  uint8_t* in_ECX = static_cast<uint8_t*>(self);
  FUN_00549490(self, param_1, param_2);
  *reinterpret_cast<uint32_t*>(param_1 + 0x110) = *reinterpret_cast<uint32_t*>(in_ECX + 0x110);
  *reinterpret_cast<uint32_t*>(param_1 + 0x114) = *reinterpret_cast<uint32_t*>(in_ECX + 0x114);
  *reinterpret_cast<uint32_t*>(param_1 + 0x118) = *reinterpret_cast<uint32_t*>(in_ECX + 0x118);
}
