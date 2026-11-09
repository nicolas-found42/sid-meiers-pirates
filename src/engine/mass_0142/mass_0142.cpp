#include <cstdint>
#include <cstddef>
#include <windows.h>

// extern helpers / globals referenced by the assigned corpus listings
extern "C" int FUN_00533c78(int size);
extern "C" int FUN_00539210(uint32_t a, uint32_t b, void* fmt, uint32_t count);
extern "C" void operator_delete__(void* p);
extern "C" void* thunk_FUN_00533c78(uint32_t n);
extern "C" void FUN_0054da10();
extern "C" void FUN_0054d8e0(int* p);
extern "C" char FUN_0054aab0(void* p);
extern "C" void FUN_0053a380(int p);
extern "C" void* FUN_0053a4c0(void* p);
extern "C" void* FUN_0053a5a0(uint32_t a, uint32_t b, void* c);
extern "C" void FUN_004493d0(void* p);
extern "C" void* FUN_0055b7f0(void* p);
extern "C" void* FUN_0054e050(void* a, void* b);
extern "C" void FUN_00513dc0();
extern "C" void* FUN_0051ac30(int p);
extern "C" unsigned char FUN_005f0ddc();
extern "C" void FUN_0054aae0();
extern "C" void FUN_0055b760();
extern "C" void* FUN_0055e0e0();
extern "C" void* FUN_0055d020();
extern "C" void* FUN_0055c7d0();
extern "C" void* FUN_0055bc50();
extern "C" void* FUN_0055adf0();
extern "C" void* DAT_007274a0;
extern "C" void* DAT_007274a4;
extern "C" void* DAT_0072747c;
extern "C" void* DAT_00727480;
extern "C" void* DAT_0071792c;
extern "C" void* DAT_00717930;
extern "C" void* DAT_00717910;
extern "C" void* DAT_007274a8;
extern "C" void* DAT_00717880;
extern "C" void* DAT_007178a4;
extern "C" void* DAT_007178c8;
extern "C" void* DAT_007178ec;
extern "C" void* DAT_00727460;
extern "C" void* DAT_00727484;
extern "C" void* DAT_007274cc;
extern "C" void* DAT_007274f0;
extern "C" void* DAT_007178c0;
extern "C" void* DAT_007178c4;
extern "C" void* DAT_00717908;
extern "C" void* DAT_0071790c;
extern "C" void* PTR_FUN_006c2228;
extern "C" void* PTR_FUN_006c2280;
extern "C" void* PTR_LAB_006c228c;
extern "C" void* DAT_00727b28;
extern "C" int* DAT_00727c30;

// 0x54ec00 — observed shape
// Image format describe/convert helper: copies channel data between
// descriptors at +0x28/+0x2c when they match known fourcc pairs, with
// bpp stride 4/3/2 and a delta-compression pass over the pixel payload.
int FUN_0054ec00(int param_1, int param_2)
{
  uint32_t uVar3 = *(uint32_t*)(param_1 + 0x44);
  uint32_t uVar4 = **(uint32_t**)(param_1 + 0x38);
  uint32_t uVar5 = **(uint32_t**)(param_1 + 0x3c);
  int iVar6;
  int local_1c;
  uint32_t uVar13;
  uint32_t local_c;
  if ((*(int*)(param_1 + 0x28) == (int)(intptr_t)&DAT_007274a0) &&
      (*(int*)(param_1 + 0x2c) == (int)(intptr_t)&DAT_007274a4)) {
    iVar6 = FUN_00533c78(0x50);
    if (iVar6 == 0) {
      param_2 = 0;
    } else {
      param_2 = FUN_00539210(uVar4, uVar5, &DAT_00717910, uVar3);
    }
    uVar13 = 0;
    if (uVar3 != 0) {
      do {
        int iSrcOff = *(int*)(*(int*)(param_1 + 0x38) + uVar13 * 4);
        int iDstOff = *(int*)(*(int*)(param_2 + 0x40) + uVar13 * 4) + *(int*)(param_2 + 0x34);
        local_c = *(int*)(*(int*)(param_1 + 0x3c) + uVar13 * 4);
        unsigned char* puVar7 = (unsigned char*)(*(int*)(*(int*)(param_1 + 0x40) + uVar13 * 4) + *(int*)(param_1 + 0x34));
        if (local_c != 0) {
          do {
            if (iSrcOff != 0) {
              int iVar10 = iSrcOff;
              do {
                *(unsigned char*)(iDstOff + 2) = puVar7[3];
                *(unsigned char*)(iDstOff + 3) = *puVar7;
                puVar7 += 4;
                iDstOff += 4;
                --iVar10;
              } while (iVar10 != 0);
            }
            --local_c;
          } while (local_c != 0);
        }
        ++uVar13;
      } while (uVar13 < uVar3);
    }
    iVar6 = 4;
    local_1c = 4;
  } else {
    if (*(int*)(param_1 + 0x28) != (int)(intptr_t)&DAT_0072747c) {
      return 0;
    }
    if ((*(int*)(param_1 + 0x2c) == (int)(intptr_t)&DAT_00727480) &&
        (*(int*)(param_2 + 0x1c) == (int)(intptr_t)&DAT_0071792c) &&
        (*(int*)(param_2 + 0x20) == (int)(intptr_t)&DAT_00717930)) {
      iVar6 = FUN_00533c78(0x50);
      if (iVar6 == 0) {
        param_2 = 0;
      } else {
        param_2 = FUN_00539210(uVar4, uVar5, &DAT_00717910, uVar3);
      }
      uVar13 = 0;
      if (uVar3 != 0) {
        do {
          local_c = *(int*)(*(int*)(param_1 + 0x3c) + uVar13 * 4);
          int iDstOff = *(int*)(*(int*)(param_2 + 0x40) + uVar13 * 4) + *(int*)(param_2 + 0x34);
          iVar6 = *(int*)(*(int*)(param_1 + 0x38) + uVar13 * 4);
          unsigned char* puVar7 = (unsigned char*)(*(int*)(*(int*)(param_1 + 0x40) + uVar13 * 4) + *(int*)(param_1 + 0x34));
          if (local_c != 0) {
            do {
              if (iVar6 != 0) {
                int iVar10 = iVar6;
                do {
                  *(unsigned char*)(iDstOff + 2) = 0xff;
                  *(unsigned char*)(iDstOff + 3) = *puVar7;
                  puVar7 += 3;
                  iDstOff += 4;
                  --iVar10;
                } while (iVar10 != 0);
              }
              --local_c;
            } while (local_c != 0);
          }
          ++uVar13;
        } while (uVar13 < uVar3);
      }
      local_1c = 4;
    } else {
      if (*(int*)(param_1 + 0x28) != (int)(intptr_t)&DAT_0072747c) {
        return 0;
      }
      if (*(int*)(param_1 + 0x2c) != (int)(intptr_t)&DAT_00727480) {
        return 0;
      }
      iVar6 = FUN_00533c78(0x50);
      if (iVar6 == 0) {
        param_2 = 0;
      } else {
        param_2 = FUN_00539210(uVar4, uVar5, &DAT_007274a8, uVar3);
      }
      local_1c = 2;
    }
    iVar6 = 3;
  }
  local_c = 0;
  if (uVar3 != 0) {
    do {
      char* pcVar9 = (char*)(*(int*)(*(int*)(param_2 + 0x40) + local_c * 4) + *(int*)(param_2 + 0x34));
      int iVar8 = *(int*)(*(int*)(param_1 + 0x38) + local_c * 4);
      char* pcVar14 = (char*)(*(int*)(*(int*)(param_1 + 0x40) + local_c * 4) + *(int*)(param_1 + 0x34));
      char* pcVar12 = pcVar14 + iVar6 * iVar8;
      int iVar11 = iVar8 - 1;
      int iVar10 = (int)(*(int*)(*(int*)(param_1 + 0x3c) + local_c * 4) - 1);
      char* local_14 = pcVar14 + iVar6;
      int local_10 = 0;
      if (iVar10 != 0) {
        char* local_4 = (char*)(intptr_t)iVar10;
        do {
          if (iVar11 == 0) {
            *pcVar9 = '\0';
          } else {
            int local_8 = iVar11;
            do {
              char cVar1 = *pcVar14;
              char cVar2 = *pcVar12;
              *pcVar9 = *local_14 - cVar1;
              local_14 += iVar6;
              pcVar14 += iVar6;
              pcVar9[1] = cVar2 - cVar1;
              pcVar12 += iVar6;
              pcVar9 += local_1c;
              --local_8;
            } while (local_8 != 0);
            if (iVar11 == 0) {
              *pcVar9 = '\0';
            } else {
              *pcVar9 = *pcVar14 - pcVar14[-iVar6];
            }
          }
          local_14 += iVar6;
          pcVar9[1] = *pcVar12 - *pcVar14;
          pcVar9 += local_1c;
          pcVar14 += iVar6;
          pcVar12 += iVar6;
          local_4 = (char*)(intptr_t)((int)(intptr_t)local_4 - 1);
          local_10 = iVar10;
        } while (local_4 != (char*)0x0);
      }
      char* local_4b = pcVar14 - (iVar8 * iVar6);
      if (iVar11 == 0) {
        *pcVar9 = '\0';
      } else {
        int local_8 = iVar11;
        do {
          char cVar1 = *pcVar14;
          char cVar2 = *local_4b;
          pcVar14 += iVar6;
          *pcVar9 = *local_14 - cVar1;
          pcVar9[1] = cVar1 - cVar2;
          local_4b += iVar6;
          local_14 += iVar6;
          pcVar9 += local_1c;
          --local_8;
        } while (local_8 != 0);
        if (iVar11 == 0) {
          *pcVar9 = '\0';
        } else {
          *pcVar9 = *pcVar14 - pcVar14[-iVar6];
        }
      }
      if (local_10 == 0) {
        pcVar9[1] = '\0';
      } else {
        pcVar9[1] = *pcVar14 - *local_4b;
      }
      ++local_c;
    } while (local_c < uVar3);
  }
  return param_2;
}

// 0x54efb0 — observed shape
// 4-bit depth decode to RGB888, palette at *(param_4+0x18); two
// palette orders selected by *param_5 == 0xff vs 0xff0000.
void FUN_0054efb0(uint32_t param_1, int param_2, unsigned char* param_3, int param_4, int* param_5, int param_6)
{
  int iVar1 = *(int*)(param_4 + 0x18);
  if (param_5[1] == 0xff00) {
    unsigned char* pbVar2 = (unsigned char*)thunk_FUN_00533c78(param_1 * (uint32_t)param_2);
    uint32_t uVar5 = (param_1 >> 1) * (uint32_t)param_2;
    uint32_t uVar4 = 0;
    unsigned char* pbVar3 = pbVar2;
    if (uVar5 != 0) {
      do {
        *pbVar3 = *(unsigned char*)(uVar4 + param_6) >> 4;
        pbVar3[1] = *(unsigned char*)(uVar4 + param_6) & 0xf;
        ++uVar4;
        pbVar3 += 2;
      } while (uVar4 < uVar5);
    }
    if (*param_5 == 0xff) {
      if (param_2 != 0) {
        pbVar3 = pbVar2;
        do {
          if (param_1 != 0) {
            uint32_t uVar4b = param_1;
            do {
              *param_3 = *(unsigned char*)(iVar1 + (uint32_t)*pbVar3 * 4);
              param_3[1] = *(unsigned char*)(iVar1 + 1 + (uint32_t)*pbVar3 * 4);
              param_3[2] = *(unsigned char*)(iVar1 + 2 + (uint32_t)*pbVar3 * 4);
              param_3 += 3;
              ++pbVar3;
              --uVar4b;
            } while (uVar4b != 0);
          }
          --param_2;
        } while (param_2 != 0);
        operator_delete__(pbVar2);
        return;
      }
    } else if ((*param_5 == 0xff0000) && (param_2 != 0)) {
      pbVar3 = pbVar2;
      do {
        if (param_1 != 0) {
          uint32_t uVar4b = param_1;
          do {
            *param_3 = *(unsigned char*)(iVar1 + 2 + (uint32_t)*pbVar3 * 4);
            param_3[1] = *(unsigned char*)(iVar1 + 1 + (uint32_t)*pbVar3 * 4);
            param_3[2] = *(unsigned char*)(iVar1 + (uint32_t)*pbVar3 * 4);
            param_3 += 3;
            ++pbVar3;
            --uVar4b;
          } while (uVar4b != 0);
        }
        --param_2;
      } while (param_2 != 0);
    }
    operator_delete__(pbVar2);
  }
}

// 0x54f0c0 — observed shape
// Same 4-bit nibbles expansion, but output is a 16-entry 32-bit colour
// LUT built by per-channel shift/mask packing from the 24-byte param_5
// descriptor (mask words + shift bytes at +0x11..+0x17).
void FUN_0054f0c0(uint32_t param_1, int param_2, uint32_t* param_3, int param_4, uint32_t* param_5, int param_6)
{
  int iVar7 = *(int*)(param_4 + 0x18);
  unsigned char* pbVar9 = (unsigned char*)thunk_FUN_00533c78(param_1 * (uint32_t)param_2);
  uint32_t uVar10 = (param_1 >> 1) * (uint32_t)param_2;
  uint32_t uVar13 = 0;
  unsigned char* pbVar11 = pbVar9;
  if (uVar10 != 0) {
    do {
      *pbVar11 = *(unsigned char*)(uVar13 + param_6) >> 4;
      pbVar11[1] = *(unsigned char*)(uVar13 + param_6) & 0xf;
      ++uVar13;
      pbVar11 += 2;
    } while (uVar13 < uVar10);
  }
  unsigned char bVar1 = *(unsigned char*)((int)(intptr_t)param_5 + 0x16);
  uint32_t uMask0 = param_5[0];
  unsigned char bVar2 = *(unsigned char*)((int)(intptr_t)param_5 + 0x12);
  uint32_t uMask2 = param_5[2];
  unsigned char bVar3 = *(unsigned char*)((int)(intptr_t)param_5 + 0x11);
  unsigned char bVar4 = *(unsigned char*)((int)(intptr_t)param_5 + 0x15);
  uint32_t uMask1 = param_5[1];
  unsigned char bVar5 = (unsigned char)param_5[5];
  unsigned char bVar6 = (unsigned char)param_5[4];
  uint32_t uVar12 = (0xffU >> (*(unsigned char*)((int)(intptr_t)param_5 + 0x17) & 0x1f)) <<
    (*(unsigned char*)((int)(intptr_t)param_5 + 0x13) & 0x1f) & param_5[3];
  uint32_t auStack_40[16];
  uint32_t local_58 = 0;
  pbVar11 = (unsigned char*)(iVar7 + 1);
  do {
    auStack_40[local_58] =
      (uint32_t)(pbVar11[-1] >> (bVar5 & 0x1f)) << (bVar6 & 0x1f) & uMask0 |
      (uint32_t)(pbVar11[1] >> (bVar1 & 0x1f)) << (bVar2 & 0x1f) & uMask2 |
      (uint32_t)(*pbVar11 >> (bVar4 & 0x1f)) << (bVar3 & 0x1f) & uMask1 | uVar12;
    auStack_40[local_58 + 1] =
      (uint32_t)(pbVar11[3] >> (bVar5 & 0x1f)) << (bVar6 & 0x1f) & uMask0 |
      (uint32_t)(pbVar11[4] >> (bVar4 & 0x1f)) << (bVar3 & 0x1f) & uMask1 |
      (uint32_t)(pbVar11[5] >> (bVar1 & 0x1f)) << (bVar2 & 0x1f) & uMask2 | uVar12;
    auStack_40[local_58 + 2] =
      (uint32_t)(pbVar11[7] >> (bVar5 & 0x1f)) << (bVar6 & 0x1f) & uMask0 |
      (uint32_t)(pbVar11[8] >> (bVar4 & 0x1f)) << (bVar3 & 0x1f) & uMask1 |
      (uint32_t)(pbVar11[9] >> (bVar1 & 0x1f)) << (bVar2 & 0x1f) & uMask2 | uVar12;
    auStack_40[local_58 + 3] =
      (uint32_t)(pbVar11[0xb] >> (bVar5 & 0x1f)) << (bVar6 & 0x1f) & uMask0 |
      (uint32_t)(pbVar11[0xc] >> (bVar4 & 0x1f)) << (bVar3 & 0x1f) & uMask1 |
      (uint32_t)(pbVar11[0xd] >> (bVar1 & 0x1f)) << (bVar2 & 0x1f) & uMask2 | uVar12;
    local_58 += 4;
    pbVar11 += 0x10;
  } while (local_58 < 0x10);
  if (param_2 != 0) {
    pbVar11 = pbVar9;
    do {
      if (param_1 != 0) {
        uint32_t uVar10b = param_1;
        do {
          *param_3 = auStack_40[(uint32_t)*pbVar11];
          param_3 += 1;
          ++pbVar11;
          --uVar10b;
        } while (uVar10b != 0);
      }
      --param_2;
    } while (param_2 != 0);
  }
  operator_delete__(pbVar9);
}

// 0x54f330 — observed shape
// Same nibble expand + 16-entry 32-bit LUT build as 0x54f0c0, but the
// packed channels include a fourth channel group selected from the
// param_5 shift/mask bytes (+0x11..+0x17) so all 16 entries carry
// four colour components with no separate alpha filler.
void FUN_0054f330(uint32_t param_1, int param_2, uint32_t* param_3, int param_4, uint32_t* param_5, int param_6)
{
  int iVar11 = *(int*)(param_4 + 0x18);
  unsigned char* pbVar14 = (unsigned char*)thunk_FUN_00533c78(param_1 * (uint32_t)param_2);
  uint32_t uVar16 = (param_1 >> 1) * (uint32_t)param_2;
  uint32_t uVar18 = 0;
  unsigned char* pbVar17 = pbVar14;
  if (uVar16 != 0) {
    do {
      *pbVar17 = *(unsigned char*)(uVar18 + param_6) >> 4;
      pbVar17[1] = *(unsigned char*)(uVar18 + param_6) & 0xf;
      ++uVar18;
      pbVar17 += 2;
    } while (uVar18 < uVar16);
  }
  unsigned char bVar1 = *(unsigned char*)((int)(intptr_t)param_5 + 0x17);
  unsigned char bVar2 = *(unsigned char*)((int)(intptr_t)param_5 + 0x13);
  uint32_t uMask3 = param_5[3];
  unsigned char bVar3 = *(unsigned char*)((int)(intptr_t)param_5 + 0x16);
  unsigned char bVar4 = *(unsigned char*)((int)(intptr_t)param_5 + 0x12);
  unsigned char bVar5 = (unsigned char)param_5[4];
  uint32_t uMask0 = param_5[0];
  uint32_t uMask2 = param_5[2];
  unsigned char bVar6 = *(unsigned char*)((int)(intptr_t)param_5 + 0x15);
  unsigned char bVar7 = *(unsigned char*)((int)(intptr_t)param_5 + 0x11);
  unsigned char bVar8 = (unsigned char)param_5[5];
  uint32_t uMask1 = param_5[1];
  uint32_t auStack_40[16];
  uint32_t local_58 = 0;
  pbVar17 = (unsigned char*)(iVar11 + 2);
  do {
    auStack_40[local_58] =
      (uint32_t)(pbVar17[-2] >> (bVar8 & 0x1f)) << (bVar5 & 0x1f) & uMask0 |
      (uint32_t)(pbVar17[-1] >> (bVar6 & 0x1f)) << (bVar7 & 0x1f) & uMask1 |
      (uint32_t)(pbVar17[1] >> (bVar1 & 0x1f)) << (bVar2 & 0x1f) & uMask3 |
      (uint32_t)(*pbVar17 >> (bVar3 & 0x1f)) << (bVar4 & 0x1f) & uMask2;
    unsigned char bVar9 = pbVar17[7];
    auStack_40[local_58 + 1] =
      (uint32_t)(pbVar17[2] >> (bVar8 & 0x1f)) << (bVar5 & 0x1f) & uMask0 |
      (uint32_t)(pbVar17[3] >> (bVar6 & 0x1f)) << (bVar7 & 0x1f) & uMask1 |
      (uint32_t)(pbVar17[4] >> (bVar3 & 0x1f)) << (bVar4 & 0x1f) & uMask2 |
      (uint32_t)(pbVar17[5] >> (bVar1 & 0x1f)) << (bVar2 & 0x1f) & uMask3;
    unsigned char* pbVar15 = pbVar17 + 0x10;
    unsigned char bVar10 = pbVar17[0xb];
    auStack_40[local_58 + 2] =
      (uint32_t)(pbVar17[6] >> (bVar8 & 0x1f)) << (bVar5 & 0x1f) & uMask0 |
      (uint32_t)(bVar9 >> (bVar6 & 0x1f)) << (bVar7 & 0x1f) & uMask1 |
      (uint32_t)(pbVar17[8] >> (bVar3 & 0x1f)) << (bVar4 & 0x1f) & uMask2 |
      (uint32_t)(pbVar17[9] >> (bVar1 & 0x1f)) << (bVar2 & 0x1f) & uMask3;
    auStack_40[local_58 + 3] =
      (uint32_t)(pbVar17[10] >> (bVar8 & 0x1f)) << (bVar5 & 0x1f) & uMask0 |
      (uint32_t)(bVar10 >> (bVar6 & 0x1f)) << (bVar7 & 0x1f) & uMask1 |
      (uint32_t)(pbVar17[0xc] >> (bVar3 & 0x1f)) << (bVar4 & 0x1f) & uMask2 |
      (uint32_t)(pbVar17[0xd] >> (bVar1 & 0x1f)) << (bVar2 & 0x1f) & uMask3;
    local_58 += 4;
    pbVar17 = pbVar15;
  } while (local_58 < 0x10);
  if (param_2 != 0) {
    pbVar17 = pbVar14;
    do {
      if (param_1 != 0) {
        uint32_t uVar16b = param_1;
        do {
          *param_3 = auStack_40[(uint32_t)*pbVar17];
          param_3 += 1;
          ++pbVar17;
          --uVar16b;
        } while (uVar16b != 0);
      }
      --param_2;
    } while (param_2 != 0);
  }
  operator_delete__(pbVar14);
}

// 0x550090 — observed shape
// Scalar deleting destructor seam: calls 0x54da10 then conditionally
// operator_delete's the ECX receiver when low bit of the flag is set.
void FUN_00550090(unsigned char param_1, void* self)
{
  FUN_0054da10();
  if ((param_1 & 1) != 0) {
    operator_delete__(self);
  }
}

// 0x550100 — observed shape
// Reference-counted image factory: resolves a matching descriptor via
// 0x55b7f0/0x54e050 or the ECX vtable (+0x2c/+0x30), converts through
// FUN_00539210, and releases borrowed refs on every exit path.
void* FUN_00550100(uint32_t* param_1, int* param_2, uint32_t* param_3, char param_4, void* self)
{
  void* local_4 = nullptr;
  if ((3 < (int)param_1[3]) && ((int)param_1[3] < 7) && (*param_2 != (int)param_1[3])) {
    void* puVar3 = FUN_0055b7f0(param_1);
    if (puVar3 != nullptr) {
      ((int*)puVar3)[1] = ((int*)puVar3)[1] + 1;
      local_4 = puVar3;
    }
    param_1 = (uint32_t*)local_4;
  }
  void* puVar3 = nullptr;
  if ((param_4 != '\0') && (param_1[0x11] < 2)) {
    int iVar5 = *param_2;
    if (iVar5 == 0 || iVar5 == 1 || iVar5 == 8 || iVar5 == 9) {
      void* puVar4 = FUN_0054e050(param_1, param_3);
      if (puVar4 != nullptr) {
        ((int*)puVar4)[1] = ((int*)puVar4)[1] + 1;
        param_1 = (uint32_t*)puVar4;
        puVar3 = puVar4;
      }
    }
  }
  if ((param_3 != nullptr) && (param_3[10] == (uint32_t)param_2[7]) &&
      (param_3[0xb] == (uint32_t)param_2[8]) && (param_4 == '\0' || 1 < param_3[0x11])) {
    if ((void*)param_3 == (void*)param_1) {
      if (puVar3 != nullptr) {
        int* piVar1 = (int*)puVar3 + 1;
        *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) (**(void(**)(int))include_vtbl(puVar3))(1);
      }
      if (local_4 != nullptr) {
        int* piVar1 = (int*)local_4 + 1;
        *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) (**(void(**)(int))include_vtbl(local_4))(1);
      }
      return param_3;
    }
    char cVar2 = (**(char(**)(void*, void*, uint32_t))(**((void***)self) + 0x2c))(param_3, param_1, 0xffffffff);
    if (cVar2 != '\0') {
      if (puVar3 != nullptr) {
        int* piVar1 = (int*)puVar3 + 1;
        *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) (**(void(**)(int))include_vtbl(puVar3))(1);
      }
      if (local_4 == nullptr) {
        return param_3;
      }
      int* piVar1 = (int*)local_4 + 1;
      *piVar1 = *piVar1 - 1;
      if (*piVar1 == 0) {
        (**(void(**)(int))include_vtbl(local_4))(1);
        return param_3;
      }
      return param_3;
    }
  }
  puVar3 = nullptr;
  if ((*param_2 == 8 || *param_2 == 9)) {
    void* puVar4 = (**(void*(**)(void*, void*))(**((void***)self) + 0x30))(param_1, param_2);
    if (puVar4 != nullptr) {
      ((int*)puVar4)[1] = ((int*)puVar4)[1] + 1;
      param_1 = (uint32_t*)puVar4;
      puVar3 = puVar4;
    }
  }
  int iVar5 = FUN_00533c78(0x50);
  void* puVar4;
  if (iVar5 == 0) {
    puVar4 = nullptr;
  } else {
    puVar4 = (void*)FUN_00539210(*(uint32_t*)((char*)param_1 + 0xe*4),
                                  *(uint32_t*)((char*)param_1 + 0xf*4), param_2, param_1[0x11]);
  }
  char cVar2 = (**(char(**)(void*, void*, uint32_t))(**((void***)self) + 0x2c))(puVar4, param_1, 0xffffffff);
  if (cVar2 == '\0') {
    if (puVar3 != nullptr) {
      int* piVar1 = (int*)puVar3 + 1;
      *piVar1 = *piVar1 - 1;
      if (*piVar1 == 0) (**(void(**)(int))include_vtbl(puVar3))(1);
    }
    return nullptr;
  }
  if (puVar3 != nullptr) {
    int* piVar1 = (int*)puVar3 + 1;
    *piVar1 = *piVar1 - 1;
    if (*piVar1 == 0) (**(void(**)(int))include_vtbl(puVar3))(1);
  }
  return puVar4;
}

// ---------------------------------------------------------------------------
// Additional externs used only by the definitions appended below.

// Converer signature actually invoked through pcVar12 in 0x550340: seven
// register/stack arguments (row widths, row pointers, palette, plane scratch).
typedef void (*ImageConvFn)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t*, uint32_t, unsigned char*);

extern "C" void LAB_0054cd00();
extern "C" void DAT_0054ce10();
extern "C" void LAB_0054cee0();
extern "C" void LAB_0054d0e0();
extern "C" void LAB_0054d190();
extern "C" void LAB_0054d250();
extern "C" void LAB_0054d2d0();
extern "C" void LAB_0054d360();
extern "C" void LAB_0054d3e0();
extern "C" void LAB_0054d460();
extern "C" void LAB_0054d500();
extern "C" void LAB_0054d580();
extern "C" void LAB_0054d610();
extern "C" void LAB_0054d690();
extern "C" void LAB_0054d7c0();
extern "C" void LAB_0054d840();
extern "C" void LAB_0054f5e0();
extern "C" void LAB_0054f870();
extern "C" void LAB_0054f930();
extern "C" void LAB_0054fb50();
extern "C" void DAT_0054fe30();
extern "C" void FUN_0054ce20();
extern "C" void FUN_0054cf60();
extern "C" void FUN_0054d020();
extern "C" void FUN_0054d720();

// 0x550340 — observed shape
// Surface blit/convert dispatcher. Rejects mismatched plane counts, derives
// the row range from the -1 sentinel or the explicit index, then either
// memcpy's whole planes (identical fourcc pair at +0x28/+0x2c) or probes the
// image-type globals through FUN_0054aab0 to pick a per-format converter.
// Palette-order markers 0xff00/0xff/0xff0000 gate the 24bpp path.
uint32_t FUN_00550340(int param_1, int param_2, uint32_t param_3)
{
  uint32_t uVar8;
  uint32_t uVar9;
  uint32_t uVar10;
  uint32_t* puVar11;
  uint32_t* puVar13;
  ImageConvFn pcVar12 = nullptr;
  int iVar3;
  int iVar6;
  char cVar2;
  char cVar4;
  char cVar5;
  unsigned char local_30[12];
  int local_24 = 0;
  // scratch the converter call consumes; FUN_0054d8e0 leaves the palette-order
  // markers 0xff00 / 0xff / 0xff0000 in these stack slots
  uint32_t local_18 = 0;
  uint32_t local_14 = 0;
  bool doCopy = false;

  if ((**(int**)(param_2 + 0x38) != **(int**)(param_1 + 0x38)) ||
      (**(int**)(param_2 + 0x3c) != **(int**)(param_1 + 0x3c))) {
    return 0;
  }
  if (param_3 == 0xffffffff) {
    if (*(uint32_t*)(param_2 + 0x44) < *(uint32_t*)(param_1 + 0x44)) {
      return 0;
    }
    param_3 = 0;
    uVar8 = *(uint32_t*)(param_1 + 0x44) - 1;
  } else {
    if (*(uint32_t*)(param_2 + 0x44) <= param_3) {
      return 0;
    }
    if (*(uint32_t*)(param_1 + 0x44) <= param_3) {
      return 0;
    }
    uVar8 = param_3;
  }
  if ((*(int*)(param_2 + 0x28) == *(int*)(param_1 + 0x28)) &&
      (*(int*)(param_2 + 0x2c) == *(int*)(param_1 + 0x2c))) {
    for (; param_3 <= uVar8; param_3 = param_3 + 1) {
      iVar6 = *(int*)(*(int*)(param_2 + 0x40) + param_3 * 4);
      uVar9 = (uint32_t)(*(int*)(*(int*)(param_2 + 0x40) + param_3 * 4 + 4) - iVar6);
      puVar11 = (uint32_t*)(*(int*)(param_2 + 0x34) + iVar6);
      puVar13 = (uint32_t*)(*(int*)(*(int*)(param_1 + 0x40) + param_3 * 4) + *(int*)(param_1 + 0x34));
      for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
        *puVar13 = *puVar11;
        puVar11 = puVar11 + 1;
        puVar13 = puVar13 + 1;
      }
      for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(unsigned char*)puVar13 = *(unsigned char*)puVar11;
        puVar11 = (uint32_t*)((intptr_t)puVar11 + 1);
        puVar13 = (uint32_t*)((intptr_t)puVar13 + 1);
      }
    }
    if (*(int*)(param_2 + 0x30) == 0) {
      return 1;
    }
    if (*(int*)(param_1 + 0x30) != 0) {
      FUN_0053a380(*(int*)(param_2 + 0x30));
      return 1;
    }
    iVar6 = FUN_00533c78(0x28);
    if (iVar6 != 0) {
      void* pVar = FUN_0053a4c0((void*)(intptr_t)*(int*)(param_2 + 0x30));
      FUN_004493d0(pVar);
      return 1;
    }
    FUN_004493d0(nullptr);
    return 1;
  }
  iVar6 = *(int*)(param_2 + 0xc);
  cVar5 = *(char*)(param_1 + 0x24);
  iVar3 = *(int*)(param_1 + 0xc);
  cVar2 = *(char*)(param_2 + 0x24);
  FUN_0054d8e0((int*)(param_1 + 0xc));
  FUN_0054d8e0((int*)(param_2 + 0xc));
  if (iVar3 == 4) {
    return 0;
  }
  if (iVar3 == 5) {
    return 0;
  }
  if (iVar3 == 6) {
    return 0;
  }
  if (cVar5 == 0x18) {
    if (local_14 != 0xff00) {
      return 0;
    }
    if ((local_18 != 0xff) && (local_18 != 0xff0000)) {
      return 0;
    }
  }
  cVar4 = FUN_0054aab0(&DAT_00717880);
  if (cVar4 == '\0') {
    cVar4 = FUN_0054aab0(&DAT_007178a4);
    if (cVar4 == '\0') {
      cVar4 = FUN_0054aab0(&DAT_007178c8);
      if (cVar4 == '\0') {
        cVar4 = FUN_0054aab0(&DAT_007178ec);
        if (cVar4 == '\0') {
          cVar4 = FUN_0054aab0(&DAT_00727460);
          if (cVar4 == '\0') {
            cVar4 = FUN_0054aab0(&DAT_00727484);
            if (cVar4 == '\0') {
              cVar4 = FUN_0054aab0(&DAT_007274a8);
              if (cVar4 == '\0') {
                cVar4 = FUN_0054aab0(&DAT_00717910);
                if (cVar4 == '\0') {
                  cVar5 = FUN_0054aab0(&DAT_007274cc);
                  if ((cVar5 == '\0') ||
                      (cVar5 = FUN_0054aab0(&DAT_007274f0), cVar5 == '\0')) {
                    cVar5 = FUN_0054aab0(&DAT_007274f0);
                    if ((cVar5 == '\0') ||
                        (cVar5 = FUN_0054aab0(&DAT_007274cc), cVar5 == '\0')) {
                      if ((iVar6 != 0) && (iVar6 != 1)) {
                        return 0;
                      }
                      cVar5 = FUN_0054aab0(&DAT_00727484);
                      if (cVar5 == '\0') {
                        cVar5 = FUN_0054aab0(&DAT_00727460);
                        if (cVar5 == '\0') {
                          return 0;
                        }
                        if (cVar2 == 0x10) {
                          pcVar12 = (ImageConvFn)&LAB_0054d250;
                        } else if (cVar2 == 0x18) {
                          pcVar12 = (ImageConvFn)&LAB_0054d3e0;
                        } else {
                          if (cVar2 != ' ') {
                            return 0;
                          }
                          pcVar12 = (ImageConvFn)&LAB_0054d500;
                        }
                      } else if (cVar2 == 0x10) {
                        if (local_24 == 0) {
                          pcVar12 = (ImageConvFn)&LAB_0054d360;
                        } else {
                          pcVar12 = (ImageConvFn)&LAB_0054d2d0;
                        }
                      } else if (cVar2 == 0x18) {
                        pcVar12 = (ImageConvFn)&LAB_0054d460;
                      } else {
                        if (cVar2 != ' ') {
                          return 0;
                        }
                        if (local_24 == 0) {
                          pcVar12 = (ImageConvFn)&LAB_0054d610;
                        } else {
                          pcVar12 = (ImageConvFn)&LAB_0054d580;
                        }
                      }
                    } else {
                      pcVar12 = (ImageConvFn)&DAT_0054ce10;
                    }
                  } else {
                    pcVar12 = (ImageConvFn)&LAB_0054cd00;
                  }
                } else {
                  if ((iVar3 != 8) && (iVar3 != 9)) {
                    return 0;
                  }
                  if (cVar5 == 0x10) {
                    pcVar12 = (ImageConvFn)&FUN_0054d720;
                  } else {
                    if (cVar5 != ' ') {
                      return 0;
                    }
                    pcVar12 = (ImageConvFn)&LAB_0054d690;
                  }
                }
              } else {
                if ((iVar3 != 8) && (iVar3 != 9)) {
                  return 0;
                }
                if (cVar5 == 0x10) {
                  pcVar12 = (ImageConvFn)&LAB_0054d840;
                } else {
                  if (cVar5 != ' ') {
                    return 0;
                  }
                  pcVar12 = (ImageConvFn)&LAB_0054d7c0;
                }
              }
            } else {
              if ((iVar3 != 0) && (iVar3 != 1)) {
                return 0;
              }
              if (cVar5 == 0x10) {
                pcVar12 = (ImageConvFn)&FUN_0054d020;
              } else if (cVar5 == 0x18) {
                pcVar12 = (ImageConvFn)&LAB_0054d0e0;
              } else {
                if (cVar5 != ' ') {
                  return 0;
                }
                pcVar12 = (ImageConvFn)&LAB_0054d190;
              }
            }
          } else {
            if ((iVar3 != 0) && (iVar3 != 1)) {
              return 0;
            }
            if (cVar5 == 0x10) {
              pcVar12 = (ImageConvFn)&FUN_0054ce20;
            } else if (cVar5 == 0x18) {
              pcVar12 = (ImageConvFn)&LAB_0054cee0;
            } else {
              if (cVar5 != ' ') {
                return 0;
              }
              pcVar12 = (ImageConvFn)&FUN_0054cf60;
            }
          }
        } else {
          if (*(int*)(param_2 + 0x30) == 0) {
            return 0;
          }
          if ((iVar3 != 0) && (iVar3 != 1)) {
            cVar5 = FUN_0054aab0(&DAT_007178c8);
            if (cVar5 == '\0') {
              return 0;
            }
            for (; param_3 <= uVar8; param_3 = param_3 + 1) {
              iVar6 = *(int*)(*(int*)(param_2 + 0x40) + param_3 * 4);
              uVar9 = (uint32_t)(*(int*)(*(int*)(param_2 + 0x40) + param_3 * 4 + 4) - iVar6);
              puVar11 = (uint32_t*)(*(int*)(param_2 + 0x34) + iVar6);
              puVar13 = (uint32_t*)(*(int*)(*(int*)(param_1 + 0x40) + param_3 * 4) + *(int*)(param_1 + 0x34));
              for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
                *puVar13 = *puVar11;
                puVar11 = puVar11 + 1;
                puVar13 = puVar13 + 1;
              }
              for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
                *(unsigned char*)puVar13 = *(unsigned char*)puVar11;
                puVar11 = (uint32_t*)((intptr_t)puVar11 + 1);
                puVar13 = (uint32_t*)((intptr_t)puVar13 + 1);
              }
            }
            if (*(int*)(param_2 + 0x30) == 0) {
              return 0;
            }
            iVar6 = FUN_00533c78(0x28);
            if (iVar6 != 0) {
              void* pVar = FUN_0053a5a0(0, 0x100,
                                        (void*)(intptr_t)*(int*)(*(int*)(param_2 + 0x30) + 0x18));
              FUN_004493d0(pVar);
              return 1;
            }
            FUN_004493d0(nullptr);
            return 1;
          }
          if (cVar5 == 0x10) {
            pcVar12 = (ImageConvFn)&LAB_0054fb50;
          } else if (cVar5 == 0x18) {
            pcVar12 = (ImageConvFn)&LAB_0054f870;
          } else {
            if (cVar5 != ' ') {
              return 0;
            }
            pcVar12 = (ImageConvFn)&DAT_0054fe30;
          }
        }
      } else {
        if (*(int*)(param_2 + 0x30) == 0) {
          return 0;
        }
        if ((iVar3 != 0) && (iVar3 != 1)) {
          cVar5 = FUN_0054aab0(&DAT_007178ec);
          if (cVar5 == '\0') {
            return 0;
          }
          for (; param_3 <= uVar8; param_3 = param_3 + 1) {
            int* piRow = (int*)(*(int*)(param_2 + 0x40) + param_3 * 4);
            iVar6 = *piRow;
            uVar9 = (uint32_t)(piRow[1] - iVar6);
            puVar11 = (uint32_t*)(*(int*)(param_2 + 0x34) + iVar6);
            puVar13 = (uint32_t*)(*(int*)(*(int*)(param_1 + 0x40) + param_3 * 4) + *(int*)(param_1 + 0x34));
            for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
              *puVar13 = *puVar11;
              puVar11 = puVar11 + 1;
              puVar13 = puVar13 + 1;
            }
            for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
              *(unsigned char*)puVar13 = *(unsigned char*)puVar11;
              puVar11 = (uint32_t*)((intptr_t)puVar11 + 1);
              puVar13 = (uint32_t*)((intptr_t)puVar13 + 1);
            }
          }
          doCopy = true;
        } else if (cVar5 == 0x10) {
          pcVar12 = (ImageConvFn)&LAB_0054f5e0;
        } else if (cVar5 == 0x18) {
          pcVar12 = (ImageConvFn)&LAB_0054f870;
        } else {
          if (cVar5 != ' ') {
            return 0;
          }
          pcVar12 = (ImageConvFn)&LAB_0054f930;
        }
      }
    } else {
      if (*(int*)(param_2 + 0x30) == 0) {
        return 0;
      }
      if ((iVar3 != 0) && (iVar3 != 1)) {
        cVar5 = FUN_0054aab0(&DAT_00717880);
        if (cVar5 == '\0') {
          return 0;
        }
        for (; param_3 <= uVar8; param_3 = param_3 + 1) {
          iVar6 = *(int*)(*(int*)(param_2 + 0x40) + param_3 * 4);
          uVar9 = (uint32_t)(*(int*)(*(int*)(param_2 + 0x40) + param_3 * 4 + 4) - iVar6);
          puVar11 = (uint32_t*)(*(int*)(param_2 + 0x34) + iVar6);
          puVar13 = (uint32_t*)(*(int*)(*(int*)(param_1 + 0x40) + param_3 * 4) + *(int*)(param_1 + 0x34));
          for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
            *puVar13 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar13 = puVar13 + 1;
          }
          for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
            *(unsigned char*)puVar13 = *(unsigned char*)puVar11;
            puVar11 = (uint32_t*)((intptr_t)puVar11 + 1);
            puVar13 = (uint32_t*)((intptr_t)puVar13 + 1);
          }
        }
        if (*(int*)(param_2 + 0x30) == 0) {
          return 0;
        }
        iVar6 = FUN_00533c78(0x28);
        if (iVar6 != 0) {
          void* pVar = FUN_0053a5a0(0, 0x10,
                                    (void*)(intptr_t)*(int*)(*(int*)(param_2 + 0x30) + 0x18));
          FUN_004493d0(pVar);
          return 1;
        }
        FUN_004493d0(nullptr);
        return 1;
      }
      if (cVar5 == 0x18) {
        pcVar12 = (ImageConvFn)&FUN_0054efb0;
      } else {
        if (cVar5 != ' ') {
          return 0;
        }
        pcVar12 = (ImageConvFn)&FUN_0054f330;
      }
    }
  } else {
    if (*(int*)(param_2 + 0x30) == 0) {
      return 0;
    }
    if ((iVar3 != 0) && (iVar3 != 1)) {
      cVar5 = FUN_0054aab0(&DAT_007178a4);
      if (cVar5 == '\0') {
        return 0;
      }
      for (; param_3 <= uVar8; param_3 = param_3 + 1) {
        int* piRow = (int*)(*(int*)(param_2 + 0x40) + param_3 * 4);
        iVar6 = *piRow;
        uVar9 = (uint32_t)(piRow[1] - iVar6);
        puVar11 = (uint32_t*)(*(int*)(param_2 + 0x34) + iVar6);
        puVar13 = (uint32_t*)(*(int*)(*(int*)(param_1 + 0x40) + param_3 * 4) + *(int*)(param_1 + 0x34));
        for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
          *puVar13 = *puVar11;
          puVar11 = puVar11 + 1;
          puVar13 = puVar13 + 1;
        }
        for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
          *(unsigned char*)puVar13 = *(unsigned char*)puVar11;
          puVar11 = (uint32_t*)((intptr_t)puVar11 + 1);
          puVar13 = (uint32_t*)((intptr_t)puVar13 + 1);
        }
      }
      doCopy = true;
    } else if (cVar5 == 0x18) {
      pcVar12 = (ImageConvFn)&FUN_0054efb0;
    } else {
      if (cVar5 != ' ') {
        return 0;
      }
      pcVar12 = (ImageConvFn)&FUN_0054f0c0;
    }
  }
  if (doCopy) {
    // shared tail for the copied-plane path: refresh or clone the palette
    // block owned by the destination descriptor, then mark palette entry 0
    // opaque when the descriptor carries a palette payload.
    if (*(int*)(param_2 + 0x30) == 0) {
      return 0;
    }
    if (*(int*)(param_1 + 0x30) == 0) {
      iVar6 = FUN_00533c78(0x28);
      if (iVar6 == 0) {
        FUN_004493d0(nullptr);
      } else {
        void* pVar = FUN_0053a4c0((void*)(intptr_t)*(int*)(param_2 + 0x30));
        FUN_004493d0(pVar);
      }
    } else {
      FUN_0053a380(*(int*)(param_2 + 0x30));
    }
    if (*(int*)(*(int*)(param_1 + 0x30) + 0x10) == 0) {
      return 1;
    }
    *(unsigned char*)(*(int*)(*(int*)(param_1 + 0x30) + 0x18) + 3) = 0xff;
    return 1;
  }
  if (uVar8 < param_3) {
    return 1;
  }
  do {
    (*pcVar12)(*(uint32_t*)(*(int*)(param_1 + 0x38) + param_3 * 4),
               *(uint32_t*)(*(int*)(param_1 + 0x3c) + param_3 * 4),
               (uint32_t)(*(int*)(*(int*)(param_1 + 0x40) + param_3 * 4) + *(int*)(param_1 + 0x34)),
               (uint32_t)*(int*)(param_2 + 0x30), &local_18,
               (uint32_t)(*(int*)(*(int*)(param_2 + 0x40) + param_3 * 4) + *(int*)(param_2 + 0x34)),
               local_30);
    param_3 = param_3 + 1;
  } while (param_3 <= uVar8);
  return 1;
}

// 0x550b20 — observed shape
// Builds a converted image from a source object: asks the ECX receiver's
// vtable (+4) to fill the descriptor scratch, allocates the destination via
// 0x539210, then walks the per-plane row array. Each row object comes from
// vtable (+8) on the (re-loaded) receiver and is ref-counted, copied, and
// released; a plane-size mismatch destroys the destination and fails.
// in_ESI/in_EDI are the caller-supplied register dimensions that Ghidra left
// unmodelled.
void* FUN_00550b20(int* param_1, void* self, uint32_t in_ESI, uint32_t in_EDI)
{
  int iVar3;
  char cVar2;
  uint32_t* puVar4;
  uint32_t* puVar7;
  uint32_t* puVar9;
  uint32_t* puVar10;
  int* piVar1;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar8;
  uint32_t uStack_3c = 0;
  int aiStack_38[2] = {0, 0};
  unsigned char local_30[4];
  unsigned char local_2c[8];
  unsigned char local_24[20];
  int iStack_10 = 0;
  uint32_t uStack_c = 0;
  int iStack_8 = 0;

  iVar3 = *param_1;
  if (iVar3 != 0) {
    FUN_00513dc0();
    cVar2 = ((char(*)(void*, int, void*, intptr_t, void*, void*))
             (*((void***)self))[1])(self, iVar3, local_24, (intptr_t)&uStack_3c + 3,
                                    local_2c, local_30);
    if (cVar2 != '\0') {
      iVar3 = FUN_00533c78(0x50);
      uVar6 = uStack_c;
      if (iVar3 == 0) {
        return nullptr;
      }
      puVar4 = (uint32_t*)(intptr_t)FUN_00539210(in_ESI, in_EDI, aiStack_38, uStack_c);
      if (puVar4 == nullptr) {
        return nullptr;
      }
      uVar8 = 0;
      if (uVar6 == 0) {
        return puVar4;
      }
      while (true) {
        iVar3 = *(int*)(iStack_10 + uVar8 * 4);
        if (iVar3 == 0) {
          ((void(*)(void*, int))(*((void***)puVar4))[0])(puVar4, 1);
          return nullptr;
        }
        puVar7 = nullptr;
        puVar10 = nullptr;
        puVar9 = puVar4;
        if (!((uVar8 != 0) || (iStack_8 == 0))) {
          FUN_0051ac30(iStack_8);
        } else {
          puVar10 = (uint32_t*)(((int(*)(void*, int, int))(*((void***)self))[2])
                                (self, iVar3, 0));
          if (puVar10 == nullptr) {
            // LAB_00550cb7
            ((void(*)(void*, int))(*((void***)puVar4))[0])(puVar4, 1);
            return nullptr;
          }
          puVar10[1] = puVar10[1] + 1;
        }
        puVar7 = puVar10;
        if (puVar10 == nullptr) {
          ((void(*)(void*, int))(*((void***)puVar4))[0])(puVar4, 1);
          return nullptr;
        }
        piVar1 = (int*)puVar10[0x10];
        if (*(int*)(puVar4[0x10] + 4 + uVar8 * 4) - *(int*)(puVar4[0x10] + uVar8 * 4) !=
            piVar1[1] - *piVar1) {
          ((void(*)(void*, int))(*((void***)puVar4))[0])(puVar4, 1);
          // LAB_00550cc3: release the row object and fail
          piVar1 = (int*)puVar7 + 1;
          *piVar1 = *piVar1 - 1;
          if (*piVar1 == 0) {
            ((void(*)(void*, int))(*((void***)puVar7))[0])(puVar7, 1);
          }
          return nullptr;
        }
        uVar5 = (uint32_t)(piVar1[1] - *piVar1);
        puVar7 = (uint32_t*)(puVar10[0xd] + *piVar1);
        puVar4 = (uint32_t*)(*(int*)(puVar4[0x10] + uVar8 * 4) + puVar9[0xd]);
        for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar4 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar4 = puVar4 + 1;
        }
        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(unsigned char*)puVar4 = *(unsigned char*)puVar7;
          puVar7 = (uint32_t*)((intptr_t)puVar7 + 1);
          puVar4 = (uint32_t*)((intptr_t)puVar4 + 1);
        }
        puVar4 = puVar9;
        if ((uVar8 == 0) && ((aiStack_38[0] == 2) || (aiStack_38[0] == 3))) {
          FUN_004493d0((void*)(intptr_t)puVar10[0xc]);
          puVar4 = puVar9;
        }
        piVar1 = (int*)puVar10 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          ((void(*)(void*, int))(*((void***)puVar10))[0])(puVar10, 1);
        }
        uVar8 = uVar8 + 1;
        if (uStack_c <= uVar8) {
          return puVar4;
        }
        self = (void*)(intptr_t)uStack_3c;
      }
    }
  }
  return nullptr;
}

// 0x550cf0 — observed shape
// Palette colour randomiser: only three fourcc pairs are accepted, then the
// destination's alpha byte (offset 3 of each 32-bit entry) is overwritten from
// FUN_005f0ddc. The 0xff pointer sentinel means "already done" and returns
// success without touching anything.
uint32_t FUN_00550cf0(int param_1, unsigned char* param_2)
{
  int iVar1;
  int iVar4;
  unsigned char uVar2;
  char cVar3;
  uint32_t uVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  unsigned char* puVar8;
  uint32_t local_10;

  if (param_1 == 0) {
    return 0;
  }
  if ((intptr_t)param_2 == 0xff) {
    return 1;
  }
  iVar1 = *(int*)(param_1 + 0x28);
  if (!((iVar1 == (int)(intptr_t)DAT_007178c0 &&
         *(int*)(param_1 + 0x2c) == (int)(intptr_t)DAT_007178c4) ||
        (iVar1 == (int)(intptr_t)DAT_00717908 &&
         *(int*)(param_1 + 0x2c) == (int)(intptr_t)DAT_0071790c) ||
        (iVar1 == (int)(intptr_t)DAT_007274a0 &&
         *(int*)(param_1 + 0x2c) == (int)(intptr_t)DAT_007274a4))) {
    return 0;
  }
  if ((iVar1 == (int)(intptr_t)DAT_007274a0) &&
      (*(int*)(param_1 + 0x2c) == (int)(intptr_t)DAT_007274a4)) {
    iVar1 = *(int*)(param_1 + 0x48);
    uVar6 = 0;
    if (*(uint32_t*)(param_1 + 0x44) != 0) {
      do {
        iVar4 = *(int*)(*(int*)(param_1 + 0x38) + uVar6 * 4);
        local_10 = 0;
        if (iVar4 != 0) {
          uVar5 = *(uint32_t*)(*(int*)(param_1 + 0x3c) + uVar6 * 4);
          param_2 = (unsigned char*)
                    (*(int*)(*(int*)(param_1 + 0x40) + uVar6 * 4) + *(int*)(param_1 + 0x34) + 3);
          do {
            uVar7 = 0;
            if (uVar5 != 0) {
              puVar8 = param_2;
              do {
                uVar2 = FUN_005f0ddc();
                *puVar8 = uVar2;
                puVar8 = puVar8 + iVar4 * iVar1;
                uVar5 = *(uint32_t*)(*(int*)(param_1 + 0x3c) + uVar6 * 4);
                uVar7 = uVar7 + 1;
              } while (uVar7 < uVar5);
            }
            param_2 = param_2 + iVar1;
            local_10 = local_10 + 1;
          } while (local_10 < *(uint32_t*)(*(int*)(param_1 + 0x38) + uVar6 * 4));
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint32_t*)(param_1 + 0x44));
      return 1;
    }
  } else if ((iVar1 == (int)(intptr_t)DAT_00717908) &&
             (*(int*)(param_1 + 0x2c) == (int)(intptr_t)DAT_0071790c)) {
    iVar1 = *(int*)(param_1 + 0x30);
    uVar6 = 0;
    if (*(int*)(iVar1 + 0x10) != 0) {
      puVar8 = (unsigned char*)(*(int*)(iVar1 + 0x18) + 3);
      do {
        uVar2 = FUN_005f0ddc();
        *puVar8 = uVar2;
        uVar6 = uVar6 + 1;
        puVar8 = puVar8 + 4;
      } while (uVar6 < *(uint32_t*)(iVar1 + 0x10));
      return 1;
    }
  } else {
    cVar3 = FUN_0054aab0(&DAT_007178a4);
    if (cVar3 != '\0') {
      iVar1 = *(int*)(param_1 + 0x30);
      uVar6 = 0;
      if (*(int*)(iVar1 + 0x10) != 0) {
        puVar8 = (unsigned char*)(*(int*)(iVar1 + 0x18) + 3);
        do {
          uVar2 = FUN_005f0ddc();
          *puVar8 = uVar2;
          uVar6 = uVar6 + 1;
          puVar8 = puVar8 + 4;
        } while (uVar6 < *(uint32_t*)(iVar1 + 0x10));
      }
    }
  }
  return 1;
}

// 0x550ef0 — observed shape
// Surface-factory constructor: chains the base ctor 0x54aae0/0x55b760, installs
// both vtables (self and the sub-object at +0xfb), then registers five
// concrete image back-ends (0x60/0x54/0x50/0x84/0x1d4 bytes) into the
// singly-linked list at +0xfc with the count at +0xfe.
void FUN_00550ef0(void* self)
{
  uint32_t* pSelf = (uint32_t*)self;
  int* piVar1;
  int iVar2;
  uint32_t* puVar4;
  void* subobj;

  ((void(*)(void*))&FUN_0054aae0)(self);
  pSelf[0] = (uint32_t)(intptr_t)&PTR_FUN_006c2228;
  ((void(*)(void*))&FUN_0055b760)(self);
  piVar1 = (int*)(pSelf + 0xfb);
  subobj = (void*)piVar1;
  pSelf[0xfe] = 0;
  pSelf[0xfc] = 0;
  pSelf[0xfd] = 0;
  *piVar1 = (int)(intptr_t)&PTR_FUN_006c2280;

  iVar2 = FUN_00533c78(0x60);
  void* pCtor = (iVar2 == 0) ? nullptr : FUN_0055e0e0();
  puVar4 = (uint32_t*)((void*(*)(void*))(*((void***)subobj))[1])(subobj);
  puVar4[2] = (uint32_t)(intptr_t)pCtor;
  puVar4[1] = 0;
  puVar4[0] = pSelf[0xfc];
  if (pSelf[0xfc] == 0) {
    pSelf[0xfd] = (uint32_t)(intptr_t)puVar4;
  } else {
    *(uint32_t*)(pSelf[0xfc] + 4) = (uint32_t)(intptr_t)puVar4;
  }
  pSelf[0xfc] = (uint32_t)(intptr_t)puVar4;
  pSelf[0xfe] = pSelf[0xfe] + 1;

  iVar2 = FUN_00533c78(0x54);
  pCtor = (iVar2 == 0) ? nullptr : FUN_0055d020();
  puVar4 = (uint32_t*)((void*(*)(void*))(*((void***)subobj))[1])(subobj);
  puVar4[2] = (uint32_t)(intptr_t)pCtor;
  puVar4[1] = 0;
  puVar4[0] = pSelf[0xfc];
  if (pSelf[0xfc] == 0) {
    pSelf[0xfd] = (uint32_t)(intptr_t)puVar4;
  } else {
    *(uint32_t*)(pSelf[0xfc] + 4) = (uint32_t)(intptr_t)puVar4;
  }
  pSelf[0xfc] = (uint32_t)(intptr_t)puVar4;
  pSelf[0xfe] = pSelf[0xfe] + 1;

  iVar2 = FUN_00533c78(0x50);
  pCtor = (iVar2 == 0) ? nullptr : FUN_0055c7d0();
  puVar4 = (uint32_t*)((void*(*)(void*))(*((void***)subobj))[1])(subobj);
  puVar4[2] = (uint32_t)(intptr_t)pCtor;
  puVar4[1] = 0;
  puVar4[0] = pSelf[0xfc];
  if (pSelf[0xfc] == 0) {
    pSelf[0xfd] = (uint32_t)(intptr_t)puVar4;
  } else {
    *(uint32_t*)(pSelf[0xfc] + 4) = (uint32_t)(intptr_t)puVar4;
  }
  pSelf[0xfc] = (uint32_t)(intptr_t)puVar4;
  pSelf[0xfe] = pSelf[0xfe] + 1;

  iVar2 = FUN_00533c78(0x84);
  pCtor = (iVar2 == 0) ? nullptr : FUN_0055bc50();
  puVar4 = (uint32_t*)((void*(*)(void*))(*((void***)subobj))[1])(subobj);
  puVar4[2] = (uint32_t)(intptr_t)pCtor;
  puVar4[1] = 0;
  puVar4[0] = pSelf[0xfc];
  if (pSelf[0xfc] == 0) {
    pSelf[0xfd] = (uint32_t)(intptr_t)puVar4;
  } else {
    *(uint32_t*)(pSelf[0xfc] + 4) = (uint32_t)(intptr_t)puVar4;
  }
  pSelf[0xfc] = (uint32_t)(intptr_t)puVar4;
  pSelf[0xfe] = pSelf[0xfe] + 1;

  iVar2 = FUN_00533c78(0x1d4);
  pCtor = (iVar2 == 0) ? nullptr : FUN_0055adf0();
  puVar4 = (uint32_t*)((void*(*)(void*))(*((void***)subobj))[1])(subobj);
  puVar4[2] = (uint32_t)(intptr_t)pCtor;
  puVar4[1] = 0;
  puVar4[0] = pSelf[0xfc];
  if (pSelf[0xfc] == 0) {
    pSelf[0xfd] = (uint32_t)(intptr_t)puVar4;
    pSelf[0xfc] = (uint32_t)(intptr_t)puVar4;
    pSelf[0xfe] = pSelf[0xfe] + 1;
    return;
  }
  *(uint32_t*)(pSelf[0xfc] + 4) = (uint32_t)(intptr_t)puVar4;
  pSelf[0xfc] = (uint32_t)(intptr_t)puVar4;
  pSelf[0xfe] = pSelf[0xfe] + 1;
}

// 0x5510a0 — observed shape
// Installs the singleton vtable and publishes the receiver as the current
// surface manager (DAT_00727b28).
void FUN_005510a0(void* self)
{
  *(void**)self = (void*)&PTR_LAB_006c228c;
  DAT_00727b28 = self;
}

// 0x5510b0 — observed shape
// Teardown counterpart of 0x5510a0: reinstalls the vtable and clears the
// published surface manager pointer.
void FUN_005510b0(void* self)
{
  *(void**)self = (void*)&PTR_LAB_006c228c;
  DAT_00727b28 = nullptr;
}

// 0x551110 — observed shape
// Forwards one argument to vtable slot +0xec of the current manager.
void FUN_00551110(uint32_t param_1)
{
  if (DAT_00727c30 != nullptr) {
    ((void(*)(void*, uint32_t))(*((void***)DAT_00727c30))[0xec / 4])(DAT_00727c30, param_1);
  }
}

// 0x551130 — observed shape
// Forwards one argument to vtable slot +0xe4 of the current manager.
void FUN_00551130(uint32_t param_1)
{
  if (DAT_00727c30 != nullptr) {
    ((void(*)(void*, uint32_t))(*((void***)DAT_00727c30))[0xe4 / 4])(DAT_00727c30, param_1);
  }
}

// 0x551150 — observed shape
// Forwards one argument to vtable slot +0xe8 of the current manager.
void FUN_00551150(uint32_t param_1)
{
  if (DAT_00727c30 != nullptr) {
    ((void(*)(void*, uint32_t))(*((void***)DAT_00727c30))[0xe8 / 4])(DAT_00727c30, param_1);
  }
}

// 0x551170 — observed shape
// Forwards one argument to vtable slot +0xf0 of the current manager.
void FUN_00551170(uint32_t param_1)
{
  if (DAT_00727c30 != nullptr) {
    ((void(*)(void*, uint32_t))(*((void***)DAT_00727c30))[0xf0 / 4])(DAT_00727c30, param_1);
  }
}

// 0x551190 — observed shape
// Forwards one argument to vtable slot +0xf4 of the current manager.
void FUN_00551190(uint32_t param_1)
{
  if (DAT_00727c30 != nullptr) {
    ((void(*)(void*, uint32_t))(*((void***)DAT_00727c30))[0xf4 / 4])(DAT_00727c30, param_1);
  }
}

// 0x5511b0 — observed shape
// Forwards one argument to vtable slot +0xf8 of the current manager.
void FUN_005511b0(uint32_t param_1)
{
  if (DAT_00727c30 != nullptr) {
    ((void(*)(void*, uint32_t))(*((void***)DAT_00727c30))[0xf8 / 4])(DAT_00727c30, param_1);
  }
}

// 0x5511d0 — observed shape
// Forwards one argument to vtable slot +0xfc of the current manager.
void FUN_005511d0(uint32_t param_1)
{
  if (DAT_00727c30 != nullptr) {
    ((void(*)(void*, uint32_t))(*((void***)DAT_00727c30))[0xfc / 4])(DAT_00727c30, param_1);
  }
}

// 0x5511f0 — observed shape
// Normalises a point against the manager's current extent: queries vtable
// +0x58/+0x5c for width/height and stores the u/signed-to-float ratios, with
// the v coordinate flipped (1.0 - y/h). Returns 0 when either extent is zero.
uint32_t FUN_005511f0(int param_1, int param_2, float* param_3, float* param_4, void* self)
{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;

  iVar3 = ((int(*)(void*))(*((void***)self))[0x58 / 4])(self);
  iVar4 = ((int(*)(void*))(*((void***)self))[0x5c / 4])(self);
  if ((iVar3 == 0) || (iVar4 == 0)) {
    return 0;
  }
  fVar1 = (float)param_1;
  if (param_1 < 0) {
    fVar1 = fVar1 + 4294967296.0f;
  }
  fVar2 = (float)iVar3;
  if (iVar3 < 0) {
    fVar2 = fVar2 + 4294967296.0f;
  }
  *param_3 = fVar1 / fVar2;
  fVar1 = (float)param_2;
  if (param_2 < 0) {
    fVar1 = fVar1 + 4294967296.0f;
  }
  fVar2 = (float)iVar4;
  if (iVar4 < 0) {
    fVar2 = fVar2 + 4294967296.0f;
  }
  *param_4 = 1.0f - fVar1 / fVar2;
  return 1;
}
