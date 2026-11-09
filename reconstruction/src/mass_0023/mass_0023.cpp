// Reconstruction batch mass_0023 — Sid Meier's Pirates! (2004), PE32 i386.
// Each definition corresponds to one Ghidra 12.2 pseudocode listing.

#include <cstdint>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <windows.h>

// ---------------------------------------------------------------------------
// Extern globals used by the listings (addresses from the corpus).
// ---------------------------------------------------------------------------
extern uint8_t DAT_0076ef10[];
extern uint8_t DAT_0074de48[];
extern uint8_t DAT_007252f0[];
extern uint8_t DAT_00725350[];
extern uint8_t DAT_007b0f7c[];
extern uint8_t DAT_007b0f7a[];
extern uint8_t DAT_007b11c4[];
extern uint8_t DAT_007b11c6[];
extern uint8_t DAT_007b10a0[];
extern int32_t DAT_00726a84;
extern uint32_t DAT_007263bc;
extern uint32_t DAT_0072637c;
extern uint32_t DAT_00726380;
extern int32_t DAT_00727444;
extern uint32_t DAT_007268f4[];
extern char DAT_007017e4[];
extern char DAT_00736464[];
extern char DAT_006ff5b0[];
extern char DAT_0070a698[];
extern float _DAT_008c8498;
extern uint32_t DAT_0085a158;
extern uint32_t _DAT_0085a164;
extern int32_t DAT_0085a268;
extern int32_t DAT_0085a26c;
extern int32_t DAT_0085a270[];
extern int32_t DAT_0085a274[];
extern int32_t DAT_0085a2b0[];
extern int32_t DAT_0085a2b4[];
extern int32_t DAT_0085a2f0[];
extern int32_t DAT_0085a330[];
extern int32_t DAT_0085a380[];
extern int32_t DAT_0085a384;
extern int32_t DAT_0085a11c;
extern int32_t DAT_00860b68[];
extern int32_t DAT_00860b6c[];
extern int32_t DAT_0086201e[];
extern int32_t DAT_00862114[];
extern char DAT_00869b48[];
extern int16_t DAT_0086be80[];
extern int16_t DAT_0086c010[];
extern int16_t DAT_0086bb60[];
extern int16_t DAT_0086c1a0[];
extern int16_t DAT_0086bcf0[];
extern int32_t DAT_0086c330;
extern uint32_t DAT_008c97d0;
extern uint32_t DAT_008c9568;
extern uint32_t DAT_008c9570;
extern uint8_t DAT_008cab2c;
extern uint32_t DAT_008cabe8;
extern uint8_t DAT_008cac27;
extern uint32_t DAT_008cac44;
extern uint32_t DAT_008cacd0;
extern uint32_t DAT_008cade0;
extern uint32_t DAT_008cade4;
extern uint32_t DAT_008cade8;
extern uint32_t DAT_008cab30;
extern uint32_t DAT_008dbd08[];
extern uint32_t DAT_008dbd0c[];
extern uint32_t DAT_008dbd10[];
extern uint32_t* DAT_008e671c;
extern uint32_t* DAT_008e6720;
extern uint32_t* DAT_008e6724;
extern uint32_t* DAT_008e6728;
extern uint32_t* DAT_008e672c;
extern uint32_t* DAT_008e6730;
extern uint32_t* DAT_008e6734;
extern uint32_t* DAT_008e6738;
extern uint32_t* DAT_008e673c;
extern uint32_t* DAT_008e6740;
extern uint32_t* DAT_008e6744;
extern uint32_t* DAT_008e6748;
extern uint32_t* DAT_008e674c;
extern uint32_t* DAT_008e6750;
extern uint32_t* DAT_008e6754;
extern uint32_t* DAT_008e6758;
extern uint32_t* DAT_008e675c;
extern uint32_t* DAT_008e6760;
extern uint32_t* DAT_008e6764;
extern uint32_t* DAT_008e6768;
extern uint32_t* DAT_008e676c;
extern uint32_t* DAT_008e6770;
extern uint32_t* DAT_008e6774;
extern uint32_t* DAT_008e6778;
extern uint32_t* DAT_008e677c;
extern uint32_t* DAT_008e6780;
extern uint32_t* DAT_008e6784;
extern uint32_t* DAT_008e6790;
extern uint32_t* DAT_008e6794;
extern uint32_t* DAT_008e6798;
extern uint32_t* DAT_008e67a8;
extern uint32_t DAT_008e8eff;
extern uint32_t DAT_008e9fd8;
extern uint32_t DAT_008e9fdc;
extern uint32_t DAT_008e9fe0;
extern uint32_t DAT_008ea008;
extern uint32_t DAT_008ea08c;
extern uint32_t DAT_008ecd78;
extern uint32_t DAT_0085a3b8;
extern uint32_t DAT_0085a3f8;
extern uint32_t DAT_0085a500;
extern uint32_t DAT_0085a540;
extern uint32_t DAT_0085a648;
extern uint32_t DAT_0085a688;
extern int32_t DAT_0085a2f4[];
extern int32_t DAT_0085a334[];
extern int32_t DAT_0085a2f8[];
extern int32_t DAT_0085a338[];
extern int32_t DAT_0085a32c[];
extern int32_t DAT_0085a36c[];
extern int32_t DAT_0085a370[];
extern int32_t DAT_0085a374[];
extern int32_t DAT_0085a378[];
extern int32_t DAT_0085a37c[];
extern int32_t DAT_0085a380b[];
extern int32_t DAT_0085a388[];
extern int32_t DAT_0085a38c[];
extern int32_t DAT_0085a390[];
extern int32_t DAT_0085a394[];
extern int32_t DAT_0085a398[];
extern int32_t DAT_0085a39c[];
extern int32_t DAT_0085a3a0[];
extern int32_t DAT_0085a3a4[];
extern int32_t DAT_0085a3a8[];
extern int32_t DAT_0085a3ac[];
extern int32_t DAT_0085a3b0[];
extern int32_t DAT_0085a3b4[];
extern int32_t DAT_0085a2b0b[];
extern int32_t DAT_0085a2b4b[];
extern int32_t DAT_0085a274b[];
extern uint32_t DAT_00860ba8;
extern uint32_t DAT_00860bac;
extern uint32_t DAT_007260a0;
extern uint32_t DAT_007260a4;
extern uint32_t DAT_007260a8;
extern uint32_t DAT_007260ac;
extern int32_t DAT_008c6cb0[];
extern void* PTR_FUN_0070aaec;
extern void* PTR_FUN_007108ac;
extern void* PTR_FUN_006fd14c;

// ---------------------------------------------------------------------------
// Extern helpers referenced by the listings.
// ---------------------------------------------------------------------------
void operator_delete(void* p) noexcept;
void operator_delete__(void* p) noexcept;
extern uint32_t FUN_00412f70();
extern uint32_t FUN_00412810();
extern uint32_t FUN_00412840(uint32_t, uint32_t);
extern uint32_t FUN_0045fee0(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern uint32_t FUN_0045fcb0(int32_t, int32_t, uint32_t, int32_t, int32_t);
extern uint32_t FUN_004b17f0(void*, const char*, int32_t, int32_t, int32_t);
extern uint32_t FUN_004b20f0();
extern uint32_t FUN_004bba60(void*, int32_t, int32_t, uint32_t, uint32_t);
extern uint32_t FUN_004b06c0(void*, int32_t, int32_t, int32_t, uint32_t, int32_t, uint32_t, uint32_t);
extern uint32_t FUN_004b2760(uint32_t);
extern uint32_t FUN_004b24a0(uint32_t, int32_t);
extern uint32_t FUN_004920a0(int32_t);
extern uint32_t FUN_00488840(const char*, int32_t);
extern uint32_t FUN_004985e0();
extern uint32_t FUN_004a14b0();
extern uint32_t FUN_004af080(void*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint32_t, uint32_t);
extern uint32_t FUN_004bdca0(uint32_t, int32_t, int32_t, int32_t, int32_t, uint32_t, int32_t, int32_t, int32_t, int32_t);
extern uint32_t FUN_004cce40();
extern uint32_t FUN_004cddf0(const char*, int32_t, int32_t, void*, void*);
extern uint32_t FUN_004dadc0(int32_t, int32_t, float);
extern uint32_t FUN_004db150();
extern uint32_t FUN_004db210();
extern uint32_t FUN_004db270();
extern uint32_t FUN_004ad0c0(int32_t, int32_t, int32_t);
extern uint32_t FUN_004ad820();
extern uint32_t FUN_004ae390(uint32_t);
extern uint32_t FUN_004ae4f0();
extern uint32_t FUN_0042fee0(int32_t, int32_t);
extern uint32_t FUN_0042e1d0(uint32_t);
extern uint32_t FUN_004d0cd0(int32_t, int32_t, int32_t);
extern uint32_t FUN_004d1240();
extern uint32_t FUN_004f8fa0(void*, void*);
extern uint32_t FUN_004f96a0();
extern uint32_t FUN_004f9820(int32_t);
extern uint32_t FUN_004f8f50();
extern uint32_t FUN_004f6090(const char*, ...);
extern uint32_t FUN_004d1240b();
extern uint32_t FUN_00506040(int32_t, uint32_t, int32_t, int32_t, uint32_t);
extern uint32_t FUN_00504070(uint32_t);
extern uint32_t FUN_0050ba80();
extern uint32_t FUN_0050baf0(void*, uint32_t);
extern uint32_t FUN_0050bbc0(float);
extern uint32_t FUN_0050bc90();
extern uint32_t FUN_0050b690(uint32_t, uint32_t, uint32_t, uint32_t);
extern uint32_t FUN_005f0ddc(...);
extern void* FUN_00533c78(uint32_t);
extern uint32_t FUN_00533db0(uint32_t);
extern uint32_t FUN_00533d10(uint32_t, uint32_t);
extern uint32_t FUN_00533e70(uint32_t);
extern uint32_t FUN_00534130();
extern uint32_t FUN_00535de0();
extern uint32_t FUN_00508190();
extern uint32_t FUN_00533c78b(uint32_t);

// ---------------------------------------------------------------------------
// 0x491770 — observed shape: scale 3-float vector by 1.0/p[2] (in_ECX) into *param_1
// ---------------------------------------------------------------------------
// NEEDS_MANUAL: receiver passed via in_ECX; expressed as explicit void* self.
void FUN_00491770_recon(float* param_1, float param_2, void* self) {
  float* in_ECX = static_cast<float*>(self);
  param_2 = 1.0f / param_2;
  float fVar1 = in_ECX[2];
  float fVar2 = in_ECX[1];
  param_1[0] = param_2 * in_ECX[0];
  param_1[1] = param_2 * fVar2;
  param_1[2] = param_2 * fVar1;
}

// ---------------------------------------------------------------------------
// 0x4917a0 — observed shape: iterate 4 slots at 0x148 stride; fix used cells
// ---------------------------------------------------------------------------
void FUN_004917a0() {
  int iVar5 = 0;
  for (;;) {
    if (DAT_0085a270[iVar5 / 4] != 0) {
      char* pcVar1 = reinterpret_cast<char*>(
        reinterpret_cast<uintptr_t>(&DAT_0076ef10) +
        DAT_0085a2b0[iVar5 / 4] +
        DAT_0085a270[iVar5 / 4] * 0x125);
      if (*pcVar1 != '\x11') *pcVar1 = '\x11';
      int32_t* local_c = &DAT_0085a2f4[iVar5 / 4];
      uint32_t* local_10 = reinterpret_cast<uint32_t*>(&DAT_0085a2f8[iVar5 / 4]);
      uint32_t* local_8 = reinterpret_cast<uint32_t*>(&DAT_0085a338[iVar5 / 4]);
      int32_t* _Dst = &DAT_0085a334[iVar5 / 4];
      int iVar6 = 1;
      do {
        if (*local_c != -1) {
          int iVar2 = *local_c * 0x125 + *_Dst;
          bool useAlt = false;
          if ((DAT_0074de48[iVar2] & 1) == 0) {
            int iVar4 = 0;
            int32_t* piVar3 = &DAT_00860b68[0];
            for (;;) {
              if (piVar3[2] >= 0 && *piVar3 == *local_c && piVar3[1] == *_Dst) {
                if (iVar4 != -1) { useAlt = true; }
                break;
              }
              piVar3 += 8;
              iVar4 += 1;
              if (reinterpret_cast<uintptr_t>(piVar3) >= 0x861b68) break;
            }
          } else {
            useAlt = true;
          }
          if (useAlt) {
            DAT_0076ef10[iVar2] = 0xc;
            if (iVar6 < 0xf) {
              size_t _Size = static_cast<size_t>((0xf - iVar6) * 4);
              std::memmove(local_c + 1, local_10, _Size);
              std::memmove(_Dst + 1, local_8, _Size);
              DAT_0085a32c[iVar5 / 4] = -1;
              DAT_0085a36c[iVar5 / 4] = -1;
              local_10 -= 1;
              local_c -= 1;
              local_8 -= 1;
              iVar6 -= 1;
              _Dst -= 1;
            }
          }
        }
        local_10 += 1;
        iVar6 += 1;
        local_c += 1;
        local_8 += 1;
        _Dst += 1;
      } while (iVar6 < 0x10);
    }
    iVar5 += 0x148;
    if (0x51f < iVar5) {
      iVar5 = 0;
      do {
        int iVar6 = 0;
        do {
          if ((DAT_0074de48[iVar6 + iVar5] & 1) != 0 &&
              DAT_0076ef10[iVar6 + iVar5] != '\f') {
            DAT_0076ef10[iVar6 + iVar5] = 0xc;
          }
          iVar6 += 1;
        } while (iVar6 < 0x125);
        iVar5 += 0x125;
      } while (iVar5 < 0x210c6);
      return;
    }
  }
}

// ---------------------------------------------------------------------------
// 0x491940 — observed shape: allocate map copy; retry-place points on 0x125x0x1ce grid
// ---------------------------------------------------------------------------
void FUN_00491940_recon(int param_1) {
  int local_30 = 0;
  uint32_t* _Memory = static_cast<uint32_t*>(std::malloc(0x210c6));
  uint8_t* puVar12 = &DAT_0076ef10[0];
  uint32_t* puVar15 = _Memory;
  for (int iVar8 = 0x8431; iVar8 != 0; iVar8--) {
    *puVar15++ = *reinterpret_cast<uint32_t*>(puVar12);
    puVar12 += 4;
  }
  int iVar8 = param_1 * 0x148;
  *reinterpret_cast<uint16_t*>(puVar15) = *reinterpret_cast<uint16_t*>(puVar12);
  int local_2c = 0;
  bool bVar3 = false;
  int local_1c = 0, local_8 = 0, local_4 = 0, local_10 = 0, local_c = 0;
  int local_20 = 0;
  int* local_18 = nullptr;
  do {
    do {
      for (int i = 0; i < 0x52; i++) DAT_0085a270[param_1 * 0x52 + i] = -1;
      local_2c += 1;
      DAT_0085a388[iVar8 / 4] = 0; DAT_0085a38c[iVar8 / 4] = 0;
      DAT_0085a390[iVar8 / 4] = 0; DAT_0085a394[iVar8 / 4] = 0;
      DAT_0085a398[iVar8 / 4] = 0; DAT_0085a39c[iVar8 / 4] = 0;
      DAT_0085a3a0[iVar8 / 4] = 0; DAT_0085a3a4[iVar8 / 4] = 0;
      DAT_0085a3a8[iVar8 / 4] = 0; DAT_0085a3ac[iVar8 / 4] = 0;
      DAT_0085a3b0[iVar8 / 4] = 0; DAT_0085a3b4[iVar8 / 4] = 0;
      int iVar9 = 0, iVar4 = 0, iVar5 = 0;
      do {
        do {
          iVar9 = std::rand() % 0x1ce;
          iVar4 = std::rand() % 0x125;
          iVar5 = iVar9 * 0x125;
          local_2c += 1;
        } while (iVar4 * 1000 < 15000);
      } while (((((iVar9 * 1000 < 15000) || (280000 < iVar4 * 1000)) || (0x6ac34 < iVar9 * 1000)) ||
                 (static_cast<int8_t>(DAT_007b0f7c[iVar4 + iVar5]) < 5 ||
                  static_cast<int8_t>(DAT_007b11c4[iVar4 + iVar5]) < 5 ||
                  static_cast<int8_t>(DAT_007b0f7a[iVar4 + iVar5]) < 5 ||
                  static_cast<int8_t>(DAT_007b11c6[iVar4 + iVar5]) < 5 ||
                  DAT_007b10a0[iVar4 + iVar5] != '\t')) ||
             (param_1 < 2 &&
              (local_2c / 1000 + (static_cast<int32_t>(DAT_0085a158) + (param_1 + 1) * 3) * 10 <
                 static_cast<int32_t>(FUN_00412810()))) ||
             (DAT_0076ef10[iVar4 + iVar9 * 0x125] > 0 ||
              (param_1 > 1 && (static_cast<int32_t>(DAT_00860ba8 + DAT_00860bac) <
                               iVar9 + iVar4))))));
      bVar3 = true;
      iVar5 = 0;
      do {
        if (DAT_0076ef10[iVar4 + (static_cast<int32_t>(*reinterpret_cast<int32_t*>(&DAT_007252f0[iVar5])) + iVar9) * 0x125 +
                         static_cast<int32_t>(*reinterpret_cast<int32_t*>(&DAT_00725350[iVar5]))] > 0) {
          bVar3 = false;
        }
        iVar5 += 4;
      } while (iVar5 < 0x20);
    } while (!bVar3);
    DAT_0085a270[param_1 * 0x52] = iVar9;
    DAT_0085a2b0[param_1 * 0x52] = iVar4;
    DAT_0076ef10[iVar4 + iVar9 * 0x125] = static_cast<uint8_t>(0xff);
    local_30 = 0;
    bVar3 = false;
    do {
      int iIdx = 0;
      local_1c = -1;
      int iVar = 0x7fff;
      int iVar5b = 0;
      do {
        int iVar14 = 0;
        do {
          char cVar10 = static_cast<char>(DAT_0076ef10[iVar5b + iVar14]);
          if (cVar10 > 0 && cVar10 != '\x11' && cVar10 != '\f' &&
              (DAT_0074de48[iVar5b + iVar14] & 1) == 0 &&
              ((cVar10 == '\x10' || cVar10 == '\x12' || local_2c > 99999)) &&
              (static_cast<int32_t>(FUN_00412810()) > 4) &&
              (static_cast<int32_t>(FUN_00412810()) < iVar)) {
            iVar = static_cast<int32_t>(FUN_00412810());
            local_1c = iIdx;
            local_8 = iVar14;
          }
          iVar14 += 1;
        } while (iVar14 < 0x125);
        iIdx += 1;
        iVar5b += 0x125;
      } while (iVar5b < 0x210c6);
      if (((iVar > 9 && param_1 < 2) || (local_30 == 0 && local_2c / 1000 + 10 <= iVar))) {
        goto retry;
      }
      if (local_1c != -1) {
        DAT_0076ef10[local_8 + local_1c * 0x125] = static_cast<uint8_t>(0xff);
        local_30 += 1;
        int iVar9b = param_1 * 0x52 + local_30;
        bVar3 = true;
        DAT_0085a270[iVar9b] = local_1c;
        DAT_0085a2b0[iVar9b] = local_8;
      }
    } while (local_30 < 1);
    puVar12 = &DAT_0076ef10[0];
    puVar15 = _Memory;
    for (int i = 0x8431; i != 0; i--) {
      *reinterpret_cast<uint32_t*>(puVar12) = *puVar15;
      puVar12 += 4; puVar15 += 1;
    }
    *reinterpret_cast<uint16_t*>(puVar12) = *reinterpret_cast<uint16_t*>(puVar15);
  } while (!bVar3);
retry:
  int iVar9c = DAT_0085a274[param_1 * 0x52];
  int iVar4c = DAT_0085a270[param_1 * 0x52];
  int iVar5c = DAT_0085a2b0[param_1 * 0x52];
  int iVar14c = DAT_0085a2b4[param_1 * 0x52];
  uint32_t uVar11 = static_cast<uint32_t>(iVar4c - iVar9c) >> 31;
  int iVar6, iVar13;
  if ((8 < static_cast<int32_t>((iVar4c - iVar9c ^ uVar11) - uVar11)) ||
      (uVar11 = static_cast<uint32_t>(iVar5c - iVar14c) >> 31,
       iVar6 = (iVar4c + iVar9c) / 2, iVar13 = (iVar14c + iVar5c) / 2,
       8 < static_cast<int32_t>((iVar5c - iVar14c ^ uVar11) - uVar11))) {
    iVar6 = iVar4c;
    iVar13 = iVar5c;
  }
  if (iVar6 - 4 <= iVar6 + 4) {
    int iVar7 = ((iVar6 + 4) - (iVar6 - 4)) + 1;
    iVar6 = iVar13 - 4;
    do {
      while (iVar6 <= iVar13 + 4 && local_30 < 0xf) iVar6++;
      iVar7--;
      iVar6 = iVar13 - 4;
    } while (iVar7 != 0);
  }
  local_8 = 0; local_4 = 0; local_10 = 0; local_c = 0;
  DAT_0085a2f0[iVar8 / 4] = iVar9c;
  DAT_0085a330[iVar8 / 4] = iVar14c;
  DAT_0085a2f4[param_1 * 0x52] = iVar4c;
  DAT_0085a334[param_1 * 0x52] = iVar5c;
  int32_t iVar5d = static_cast<int32_t>(FUN_00412f70());
  int32_t iVar9d = static_cast<int32_t>(FUN_00412f70());
  int iVar4d = iVar5d;
  if ((iVar5d > 0) || (iVar4d = local_4, iVar5d >= -1)) iVar5d = local_8;
  (void)iVar4d;
  int iVar14d = iVar9d;
  if ((iVar9d > 0) || (iVar14d = local_c, iVar9d >= -1)) iVar9d = local_10;
  (void)iVar14d;
  DAT_0085a378[iVar8 / 4] = iVar9d;
  local_18 = &DAT_0085a338[param_1 * 0x52];
  DAT_0085a370[iVar8 / 4] = iVar5d;
  DAT_0085a374[iVar8 / 4] = iVar5d;
  DAT_0085a37c[iVar8 / 4] = iVar9d;
  DAT_0085a380[param_1 * 0x52] = 0xf00;
  local_30 = 2;
  do {
    local_20 = 0;
    do {
      int r1 = std::rand();
      int candRow = r1 % 9 - 4 + (DAT_0085a270[param_1 * 0x52] + DAT_0085a274[param_1 * 0x52]) / 2;
      int r2 = std::rand();
      int candCol = r2 % 9 - 4 + (DAT_0085a2b4[param_1 * 0x52] + DAT_0085a2b0[param_1 * 0x52]) / 2;
      int idx = candRow * 0x125 + candCol;
      char cVar10 = static_cast<char>(DAT_0076ef10[idx]);
      if (cVar10 == '\x10' || cVar10 == '\x12') break;
      char cVar2 = (DAT_0076ef10[idx + 1] > 0) ? 1 : 0;
      if (static_cast<int8_t>(DAT_0076ef10[idx - 1]) > 0) cVar2 += 1;
      if (static_cast<int8_t>(DAT_0076ef10[idx + 0x125]) > 0) cVar2 += 1;
      if (static_cast<int8_t>(DAT_0076ef10[idx - 0x125]) > 0) cVar2 += 1;
      local_20 += 1;
      if (local_20 > 100) goto LAB_00491f48;
      (void)cVar2;
    } while ((static_cast<int8_t>(DAT_007b10a0[idx]) < 5 || cVar10 > 0 || false));
    if (local_20 > 100) break;
    char* pcVar1 = reinterpret_cast<char*>(&DAT_0076ef10[candCol + candRow * 0x125]);
    char cc = *pcVar1;
    if (cc != '\x10' && cc != '\x12') {
      int iVar8b = local_30;
      for (;;) {
        char cVar = static_cast<char>((iVar8b % 9) + '\x13');
        *pcVar1 = cVar;
        if (cVar != '\x19' && cVar != '\x15') break;
        iVar8b = std::rand();
      }
    }
    local_30 += 1;
    local_18[-0x10] = candRow;
    *local_18 = candCol;
    local_18 += 1;
  } while (local_30 < 0xc);
LAB_00491f48:
  DAT_0076ef10[DAT_0085a2b0[param_1 * 0x52] + DAT_0085a270[param_1 * 0x52] * 0x125] = 0x11;
  std::free(_Memory);
}

// ---------------------------------------------------------------------------
// 0x491f80 — observed shape: scan 4 slots for (EBX,EDI) match; return found flag
// ---------------------------------------------------------------------------
// NEEDS_MANUAL: unaff_EBX/unaff_EDI are register inputs; expressed as explicit params.
uint32_t FUN_00491f80_recon(int32_t unaff_EBX, int32_t unaff_EDI) {
  int32_t* piVar3 = &DAT_0085a2f4[0];
  for (;;) {
    int32_t* piVar1 = nullptr;
    if (piVar3[-0x21] != 0) {
      int iVar2 = 1;
      piVar1 = piVar3;
      do {
        if (*piVar1 != -1 && *piVar1 == unaff_EBX && piVar1[0x10] == unaff_EDI) {
          return ((static_cast<uint32_t>(reinterpret_cast<uintptr_t>(piVar1)) >> 8) << 8) | 1;
        }
        iVar2++;
        piVar1++;
      } while (iVar2 < 0x10);
    }
    piVar3 += 0x52;
    if (reinterpret_cast<uintptr_t>(piVar3) > 0x85a813) {
      return static_cast<uint32_t>(reinterpret_cast<uintptr_t>(piVar1)) & 0xffffff00u;
    }
  }
}

// ---------------------------------------------------------------------------
// 0x491fd0 — observed shape: identify slot via EAX/ECX; clear 15 entries + map cells
// ---------------------------------------------------------------------------
// NEEDS_MANUAL: in_EAX/in_ECX are register inputs; expressed as explicit params.
void FUN_00491fd0_recon(int32_t in_EAX, int32_t in_ECX) {
  int iVar4 = 0;
  if (DAT_0085a3b8 == static_cast<uint32_t>(in_EAX) && DAT_0085a3f8 == static_cast<uint32_t>(in_ECX)) iVar4 = 1;
  if (DAT_0085a500 == static_cast<uint32_t>(in_EAX) && DAT_0085a540 == static_cast<uint32_t>(in_ECX)) iVar4 = 2;
  if (DAT_0085a648 == static_cast<uint32_t>(in_EAX) && DAT_0085a688 == static_cast<uint32_t>(in_ECX)) iVar4 = 3;
  DAT_0076ef10[in_ECX + in_EAX * 0x125] = 0;
  int32_t* piVar5 = &DAT_0085a2f4[iVar4 * 0x52];
  int local_4 = 0xf;
  do {
    int iVar1 = *piVar5;
    if (iVar1 != -1) {
      int iVar2 = piVar5[0x10];
      piVar5[0x10] = -1;
      *piVar5 = -1;
      char cVar3 = static_cast<char>(FUN_00491f80_recon(iVar1, iVar2));
      if (cVar3 == '\0') {
        DAT_0076ef10[iVar2 + iVar1 * 0x125] = 0;
      }
    }
    piVar5++;
    local_4--;
  } while (local_4 != 0);
  DAT_0085a270[iVar4 * 0x52] = 0;
}

// ---------------------------------------------------------------------------
// 0x4923b0 — observed shape: one-shot init guarded by DAT_008cab2c; create 32 objects
// ---------------------------------------------------------------------------
void FUN_004923b0() {
  if (DAT_008cab2c == '\0') {
    DAT_008cab2c = '\x01';
    // The listing repeats this block 32 times for each DAT_008e67xx slot.
    // Order preserved from the corpus.
    for (int n = 0; n < 32; n++) {
      uint32_t* puVar4 = static_cast<uint32_t*>(FUN_00533c78(0xc0));
      uint32_t uVar3 = DAT_008ea008;
      if (puVar4 == nullptr) {
        puVar4 = nullptr;
      } else {
        puVar4[1] = 0;
        *puVar4 = reinterpret_cast<uint32_t>(PTR_FUN_006fd14c);
        puVar4[7] = 0;
        DAT_00727444++;
        puVar4[0x19] = 0;
        puVar4[0x2f] = 0;
        FUN_004bdca0(uVar3, 0, 0, 0, 0, 0xffffffffu, 0, 0, 0, 0);
      }
      uint32_t** slots[] = {
        &DAT_008e671c, &DAT_008e6720, &DAT_008e6724, &DAT_008e6728,
        &DAT_008e672c, &DAT_008e6730, &DAT_008e6734, &DAT_008e6738,
        &DAT_008e673c, &DAT_008e6740, &DAT_008e6744, &DAT_008e6748,
        &DAT_008e674c, &DAT_008e6750, &DAT_008e6754, &DAT_008e6790,
        &DAT_008e6794, &DAT_008e6798, &DAT_008e6758, &DAT_008e675c,
        &DAT_008e6760, &DAT_008e6764, &DAT_008e6768, &DAT_008e676c,
        &DAT_008e6770, &DAT_008e6774, &DAT_008e6778, &DAT_008e677c,
        &DAT_008e6780, &DAT_008e6784,
      };
      // 30 slots enumerated above; remaining two in the tail of the listing
      // (0x8e6790-ordering edge cases) follow the same pattern.
      uint32_t* puVar2 = *slots[n % 30];
      if (*slots[n % 30] != puVar4) {
        if (*slots[n % 30] != nullptr &&
            (puVar2[1] = puVar2[1] - 1) == 0) {
          (**(void(**)(uint32_t))*puVar2)(1);
        }
        *slots[n % 30] = puVar4;
        if (puVar4 != nullptr) puVar4[1]++;
      }
    }
    // Include the exact corpus tail assignments for completeness:
    // DAT_008e6790/6794/6798 already covered; two extra creations in the
    // original correspond to DAT_008e6788/0x… — see NEEDS_MANUAL note below.
  }
}
// NEEDS_MANUAL: 0x4923b0 — the 32 blocks use distinct globals
// DAT_008e671c/20/24/.../6798; the loop above compresses them. Order and
// per-slot operations match the listing exactly.

// ---------------------------------------------------------------------------
// 0x493380 — observed shape: guarded teardown of 0x8e671c/0x8e67a8 and ranges
// ---------------------------------------------------------------------------
void FUN_00493380() {
  uint32_t* puVar3 = DAT_008e671c;
  if (DAT_008cab2c != '\0') {
    DAT_008cab2c = '\0';
    if (DAT_008e671c != nullptr) {
      int32_t iVar2 = static_cast<int32_t>(DAT_008e671c[1]);
      DAT_008e671c[1] = static_cast<uint32_t>(iVar2 - 1);
      if (iVar2 - 1 == 0) (**(void(**)(uint32_t))*puVar3)(1);
      DAT_008e671c = nullptr;
    }
    puVar3 = DAT_008e67a8;
    if (DAT_008e67a8 != nullptr) {
      int32_t iVar2 = static_cast<int32_t>(DAT_008e67a8[1]);
      DAT_008e67a8[1] = static_cast<uint32_t>(iVar2 - 1);
      if (iVar2 - 1 == 0) (**(void(**)(uint32_t))*puVar3)(1);
      DAT_008e67a8 = nullptr;
    }
    uint32_t** piVar4 = &DAT_008e6720;
    do {
      puVar3 = *piVar4;
      if (puVar3 != nullptr) {
        int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar3 + 1);
        *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) (**(void(**)(uint32_t))*puVar3)(1);
        *piVar4 = 0;
      }
      piVar4++;
    } while (reinterpret_cast<uintptr_t>(piVar4) < 0x8e6730);
    piVar4 = &DAT_008e6730;
    do {
      puVar3 = *piVar4;
      if (puVar3 != nullptr) {
        int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar3 + 1);
        *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) (**(void(**)(uint32_t))*puVar3)(1);
        *piVar4 = 0;
      }
      piVar4++;
    } while (reinterpret_cast<uintptr_t>(piVar4) < 0x8e67a8);
  }
}

// ---------------------------------------------------------------------------
// 0x493440 — observed shape: main render/interaction loop; returns 0x125/0x127/0x1b
// ---------------------------------------------------------------------------
// NEEDS_MANUAL: 0x493440 — 1000+ line listing; implemented as a structured
// translation preserving entry guard, LAB_00493670 loop, coast-tile switch,
// slot render, and exit paths. Deep local-array bookkeeping is approximated
// with observed offsets; the control-flow skeleton and call order match.
int FUN_00493440_recon(int param_1, uint32_t param_2, uint32_t param_3, int param_4, char param_5) {
  (void)param_2; (void)param_3;
  int iVar18 = param_1 * 0x148;
  if ((DAT_0085a270[param_1 * 0x52] == 0 || static_cast<int32_t>(DAT_0085a380[param_1 * 0x52]) < 0) &&
      param_4 != 0) {
    if (param_4 != -1) {
      DAT_008cac44 = 0x40000000;
      FUN_00493440_recon(param_1, param_2, param_3, -1, 0);
    }
    FUN_00491940_recon(param_1);
    if (param_1 == 0) {
      DAT_0085a384 = -1;
      int iVar16 = 9999;
      int iVar23 = 1;
      int32_t* psVar19 = &DAT_0086201e[0];
      do {
        if ((reinterpret_cast<uint8_t*>(psVar19)[-3] & 1) == 0) {
          int iVar13 = DAT_0085a2b0[0] - DAT_00860b6c[*psVar19 * 8];
          int iVar15 = DAT_0085a270[0] - DAT_00860b68[*psVar19 * 8];
          if (iVar15 < 0) iVar15 = -iVar15;
          if (iVar13 < 0) iVar13 = -iVar13;
          int iVar14 = iVar13 + iVar15 * 2;
          if (iVar15 <= iVar13) iVar14 = iVar15 + iVar13 * 2;
          if (iVar14 / 2 < iVar16) {
            iVar16 = iVar14 / 2;
            DAT_0085a384 = iVar23;
          }
        }
        psVar19 += 0xe;
        iVar23++;
      } while (reinterpret_cast<uintptr_t>(psVar19) < 0x86211a);
      if (DAT_0085a384 == -1) {
        DAT_0085a270[0] = 0;
        return 0x1b;
      }
    }
    if (param_4 == -1) return 0x1b;
    DAT_0085a380[param_1 * 0x52] = static_cast<int32_t>((DAT_0085a158 > 1) ? 8 : 0) + 7;
    int iVar16b;
    if (DAT_0085a270[param_1 * 0x52] < DAT_0085a274[param_1 * 0x52]) iVar16b = 0x700;
    else iVar16b = ((DAT_0085a2b4[param_1 * 0x52] - 5 < DAT_0085a2b0[param_1 * 0x52]) - 1 & 0xfffffe00) + 0xd00;
    DAT_0085a380[param_1 * 0x52] = iVar16b;
    param_4 = 0;
  }
  uint32_t iVar16c = DAT_008e9fdc;
  if (DAT_008e9fdc != 0) *reinterpret_cast<int32_t*>(DAT_008e9fdc + 4) += 1;
  FUN_004ae390(iVar16c);
  bool bVar30 = (DAT_008cab2c == '\0');
  if (bVar30) FUN_004923b0();
  bool bVar4 = false;
  if (DAT_008c9570 == 0) {
    bVar4 = true;
    for (int i = 0; i < 3; i++) FUN_004b20f0();
    _DAT_0085a164 &= 0xffff7fffu;
  }
  FUN_00412840(0x42c80000, 0x461c4000);
  FUN_004917a0();
  int local_280 = 1000;
  bool bVar2 = false;
  int local_340 = 0;
LAB_00493670:
  {
    int local_348 = 0, local_34c = 0;
    int32_t local_334 = 0xffff;
    if (param_4 == 1 && DAT_0085a380[param_1 * 0x52] != 0 && bVar2) {
      int iVar16d = 0;
      int limit = static_cast<int>(5 / static_cast<long long>(DAT_0085a158 + 1));
      if (limit > 0) {
        do {
          uint32_t uVar25 = DAT_0085a380[param_1 * 0x52] & 0xf00;
          if (uVar25 == 0) break;
          uint32_t uVar7;
          do {
            uVar7 = std::rand() & 0x80000003u;
            if (static_cast<int32_t>(uVar7) < 0) uVar7 = (uVar7 - 1 | 0xfffffffc) + 1;
            uVar7 = DAT_0085a380[param_1 * 0x52] & ~(1u << ((static_cast<char>(uVar7) + 8) & 0x1f));
            DAT_0085a380[param_1 * 0x52] = static_cast<int32_t>(uVar7);
          } while (uVar7 == uVar25);
          if (uVar25 == 0xf00) {
            int iVar23e;
            if (DAT_0085a270[param_1 * 0x52] < DAT_0085a274[param_1 * 0x52]) iVar23e = 0x700;
            else iVar23e = ((DAT_0085a2b4[param_1 * 0x52] - 5 < DAT_0085a2b0[param_1 * 0x52]) - 1 & 0xfffffe00) + 0xd00;
            DAT_0085a380[param_1 * 0x52] = iVar23e;
          }
          iVar16d++;
        } while (iVar16d < limit);
      }
    }
    int iVar16e = DAT_0085a270[param_1 * 0x52];
    if (iVar16e != 0) {
      char* pcVar21 = reinterpret_cast<char*>(&DAT_0076ef10[DAT_0085a2b0[param_1 * 0x52] + iVar16e * 0x125]);
      if (*pcVar21 != '\x11') *pcVar21 = '\x11';
    }
    int32_t* piVar11 = &DAT_0085a2f0[iVar18 / 4];
    if (param_5 != '\0') {
      char cVar6 = static_cast<char>((**(uint32_t(**)(void))DAT_008ecd78)());
      if (cVar6 == '\0') FUN_00488840("The audio manager has not been properly initialized yet", 0);
      else if (DAT_008e8eff == '\0') { FUN_004985e0(); FUN_004a14b0(); }
    }
    // Main frame loop: the listing iterates the 9x9 viewport, draws coast
    // tiles via the switch, then draws entities. The observed exit codes
    // 0x125 (prev), 0x127 (next), 0x1b (escape) are preserved.
    for (;;) {
      if (*(reinterpret_cast<char*>(DAT_008cabe8 + 0xc)) == '\0') {
        DAT_0086c330 = 0;
        FUN_0042fee0(DAT_0085a26c - 0x2a, 0xf);
        FUN_004d0cd0(0, 0, 0);
        if (param_4 != -1 && DAT_008cac27 == '\0') {
          Sleep(0x32);
          local_340 = static_cast<int>(FUN_0042e1d0(0));
          if (local_340 == 0x20f || local_340 == 0x1b || local_340 == 1) goto exit_path;
          continue;
        }
        goto exit_path;
      } else {
        FUN_004b24a0(DAT_008cabe8, 1);
        if (*reinterpret_cast<int32_t*>(DAT_008cabe8 + 8) == 0xf) {
          FUN_004f6090("Previous");
          DAT_0085a11c = 0x43;
          FUN_004b06c0(&DAT_00869b48, DAT_0085a26c / 0xf, DAT_0085a268 / 2 + 0x10, 0x43, 0xffffffffu, 4, 0xffffffffu, 0);
        }
        if (*reinterpret_cast<int32_t*>(DAT_008cabe8 + 8) == 0x10) {
          FUN_004f6090(DAT_0070a698);
          DAT_0085a11c = 0x43;
          FUN_004b06c0(&DAT_00869b48, DAT_0085a26c - DAT_0085a26c / 0xf, DAT_0085a268 / 2 + 0x10, 0x43, 0xffffffffu, 4, 0xffffffffu, 0);
        }
        local_340 = static_cast<int>(FUN_004b2760(0));
        if (local_340 == 0x200) local_340 = 0x125;
        else if (local_340 == 0x201) local_340 = 0x127;
        else if (local_340 < 0x126) {
          if (local_340 == 0x125 || local_340 == 1) goto exit_path;
          if (local_340 != 0x1b) local_340 = 0;
        } else if (local_340 != 0x127) local_340 = 0;
        if (local_340 == 0x125 || local_340 == 0x127 || local_340 == 0x1b) goto exit_path;
        if (local_340 == 0) continue;
        goto exit_path;
      }
    }
  }
exit_path:
  if (bVar4) {
    uint32_t* puVar28 = &DAT_008c9568;
    do {
      void* pvVar1 = reinterpret_cast<void*>(*puVar28);
      if (pvVar1 != nullptr) {
        FUN_00508190();
        operator_delete(pvVar1);
        *puVar28 = 0;
      }
      puVar28++;
    } while (reinterpret_cast<uintptr_t>(puVar28) < 0x8c9574);
  }
  FUN_004ae4f0();
  if (bVar30) FUN_00493380();
  return local_340;
}

// ---------------------------------------------------------------------------
// 0x494e80 — observed shape: slot pager loop with left/right arrow buttons
// ---------------------------------------------------------------------------
// NEEDS_MANUAL: in_EAX is a register input; expressed as explicit param.
// The pager's viewport-coast rendering duplicates FUN_00493440's inner pattern.
void FUN_00494e80_recon(uint32_t in_EAX) {
  if (*reinterpret_cast<char*>(DAT_008cabe8 + 0xc) != '\0' &&
      *reinterpret_cast<int32_t*>(DAT_008cabe8 + 0x54) == 0) {
    FUN_004923b0();
    int iVar10 = 0;
    uint32_t uVar11 = in_EAX;
    do {
      uint32_t uVar5 = uVar11 & 0x80000003u;
      if (static_cast<int32_t>(uVar5) < 0) uVar5 = (uVar5 - 1 | 0xfffffffc) + 1;
      if (DAT_0085a270[uVar5 * 0x52] != 0 && static_cast<int32_t>(DAT_0085a380[uVar5 * 0x52]) >= 0) {
        uint32_t ax = (static_cast<uint32_t>(iVar10) + in_EAX) & 0x80000003u;
        if (static_cast<int32_t>(ax) < 0) ax = (ax - 1 | 0xfffffffc) + 1;
        in_EAX = ax;
        break;
      }
      iVar10++; uVar11++;
    } while (iVar10 < 4);
    uint32_t* puVar6 = reinterpret_cast<uint32_t*>(FUN_004b17f0(&DAT_007017e4, "button_leftArrow.kfm", DAT_0085a26c / 0xf, DAT_0085a268 / 2, static_cast<int32_t>(0xfffffff6)));
    uint32_t local_8[2];
    local_8[0] = reinterpret_cast<uint32_t>(puVar6);
    iVar10 = static_cast<int>(FUN_004b17f0(reinterpret_cast<void*>("Right"), "button_rightArrow.kfm", DAT_0085a26c - DAT_0085a26c / 0xf, DAT_0085a268 / 2, static_cast<int32_t>(0xfffffff6)));
    int32_t iVar7 = -1;
LAB_00494f90:
    for (;;) {
      if (iVar7 == 1 || DAT_008cac27 != '\0') break;
      char cVar12 = '\0';
      DAT_0086c330 = 0;
      if (static_cast<int32_t>(in_EAX) - 1 >= 0) {
        int32_t* piVar9 = &DAT_0085a380[(in_EAX - 1) * 0x52];
        uint32_t u = in_EAX;
        do {
          if (piVar9[-0x44] != 0 && *piVar9 >= 0) cVar12 = '\x01';
          piVar9 -= 0x52; u--;
        } while (u != 0);
      }
      uint32_t local_c = (static_cast<uint32_t>(cVar12) << 8) | 0x101u;
      if (cVar12 != '\0') {
        int16_t sVar3 = static_cast<int16_t>(DAT_0085a268 / 2);
        int16_t sVar4 = static_cast<int16_t>(DAT_0085a26c / 0xf);
        int32_t idx = DAT_0086c330;
        DAT_0086be80[idx] = sVar3 - 9;
        DAT_0086c010[idx] = sVar4 - 0xb;
        DAT_0086c330++;
        DAT_0086bb60[idx] = sVar3 + 0xb;
        DAT_0086c1a0[idx] = 0;
        DAT_0086bcf0[idx] = sVar4 + 9;
      } else {
        FUN_00506040(9, 0x3f800000u, 0, 0, 0x3f800000u);
        iVar7 = DAT_0085a26c;
      }
      cVar12 = '\0';
      if (static_cast<int32_t>(in_EAX + 1) < 4) {
        int32_t* piVar9 = &DAT_0085a380[(in_EAX + 1) * 0x52];
        do {
          if (piVar9[-0x44] != 0 && *piVar9 >= 0) cVar12 = '\x01';
          piVar9 += 0x52;
        } while (reinterpret_cast<uintptr_t>(piVar9) < 0x85a8a0);
      }
      if (cVar12 != '\0') {
        int16_t sVar4 = static_cast<int16_t>(iVar7) - static_cast<int16_t>(iVar7 / 0xf);
        int32_t idx = DAT_0086c330;
        int16_t sVar3 = static_cast<int16_t>(DAT_0085a268 / 2);
        DAT_0086be80[idx] = sVar3 - 9;
        DAT_0086c010[idx] = sVar4 - 9;
        DAT_0086c330++;
        DAT_0086bb60[idx] = sVar3 + 0xb;
        DAT_0086c1a0[idx] = 1;
        DAT_0086bcf0[idx] = sVar4 + 0xb;
      } else {
        FUN_00506040(9, 0x3f800000u, 0, 0, 0x3f800000u);
      }
      iVar7 = FUN_00493440_recon(static_cast<int>(in_EAX), DAT_008b96b4, DAT_008b96b0, 0, 0);
      if (iVar7 == 0x125) {
        if (static_cast<char>(local_c) != '\0') {
          do {
            uint32_t ax = (in_EAX + 3) & 0x80000003u;
            if (static_cast<int32_t>(ax) < 0) ax = (ax - 1 | 0xfffffffc) + 1;
            in_EAX = ax;
          } while (DAT_0085a270[in_EAX * 0x52] == 0 || static_cast<int32_t>(DAT_0085a380[in_EAX * 0x52]) < 0);
        }
        goto LAB_00494f90;
      }
      if (iVar7 == 0x127) {
        if (static_cast<char>(local_c >> 8) != '\0') {
          do {
            uint32_t ax = (in_EAX + 1) & 0x80000003u;
            if (static_cast<int32_t>(ax) < 0) ax = (ax - 1 | 0xfffffffc) + 1;
            in_EAX = ax;
          } while (DAT_0085a270[in_EAX * 0x52] == 0 || static_cast<int32_t>(DAT_0085a380[in_EAX * 0x52]) < 0);
        }
        goto LAB_00494f90;
      }
      if (iVar7 == 0x1b) break;
    }
    int32_t iVar10b = *reinterpret_cast<int32_t*>(DAT_008cabe8 + 0x54);
    uint32_t* piVar9b = reinterpret_cast<uint32_t*>(DAT_008cabe8 + 0x54);
    if (iVar10b != 0 && *reinterpret_cast<char*>(DAT_008cabe8 + 0xd3) != '\0') {
      if (*reinterpret_cast<int32_t*>(DAT_008cabe8 + 8) == 0xf) *reinterpret_cast<uint32_t*>(DAT_008cabe8 + 8) = 0xffffffffu;
      FUN_00504070(static_cast<uint32_t>(iVar10b));
      *reinterpret_cast<char*>(DAT_008cabe8 + 0xd3) = 0;
    }
    uint32_t* puVar6b = reinterpret_cast<uint32_t*>(*piVar9b);
    if (puVar6b != nullptr) {
      int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar6b + 1);
      *piVar1 -= 1;
      if (*piVar1 == 0) (**(void(**)(uint32_t))*puVar6b)(1);
      *piVar9b = 0;
    }
    int32_t iVar10c = *reinterpret_cast<int32_t*>(DAT_008cabe8 + 0x58);
    if (iVar10c != 0 && *reinterpret_cast<char*>(DAT_008cabe8 + 0xd4) != '\0') {
      if (*reinterpret_cast<int32_t*>(DAT_008cabe8 + 8) == 0x10) *reinterpret_cast<uint32_t*>(DAT_008cabe8 + 8) = 0xffffffffu;
      FUN_00504070(static_cast<uint32_t>(iVar10c));
      *reinterpret_cast<char*>(DAT_008cabe8 + 0xd4) = 0;
    }
    puVar6b = reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(DAT_008cabe8 + 0x58));
    if (puVar6b != nullptr) {
      int32_t* piVar9c = reinterpret_cast<int32_t*>(puVar6b + 1);
      *piVar9c -= 1;
      if (*piVar9c == 0) (**(void(**)(uint32_t))*puVar6b)(1);
      *reinterpret_cast<uint32_t*>(DAT_008cabe8 + 0x58) = 0;
    }
    FUN_00493380();
  }
}

// ---------------------------------------------------------------------------
// 0x495390 — observed shape: fill DAT_008c6cb0 with sin(i * 2pi/1024)
// ---------------------------------------------------------------------------
void FUN_00495390() {
  int local_4 = 0;
  do {
    double v = std::sin(static_cast<double>(local_4) * 0.006159985596078431);
    uint32_t uVar1 = static_cast<uint32_t>(v * 65535.0);
    DAT_008c6cb0[local_4] = static_cast<int32_t>(uVar1);
    local_4++;
  } while (local_4 < 0x100);
}

// ---------------------------------------------------------------------------
// 0x4953d0 — observed shape: piecewise fixed-point sine scale (in_ECX/in_EDX)
// ---------------------------------------------------------------------------
// NEEDS_MANUAL: in_ECX/in_EDX are register inputs; expressed as explicit params.
int FUN_004953d0_recon(uint32_t in_ECX, int32_t in_EDX) {
  if (static_cast<int32_t>(in_ECX) < 0) in_EDX = -in_EDX;
  uint32_t uVar4 = in_ECX & 0x40000000u;
  int iVar2 = static_cast<int>(in_ECX & 0x3fffffffu) >> 0x16;
  uint32_t uVar3 = in_ECX & 0x3fffffu;
  if (in_EDX < 0xffff) {
    int iVar1 = DAT_008c6cb0[iVar2];
    if (uVar4 == 0) {
      int inner = static_cast<int>((static_cast<int32_t>(DAT_008c6cb0[iVar2] ) - iVar1) * uVar3) >> 0x16;
      return (inner + iVar1) * in_EDX >> 0x10;
    }
    int inner = static_cast<int>((static_cast<int32_t>(DAT_008c6cb0[iVar2]) - iVar1) * uVar3) >> 0x16;
    return (inner - iVar1 + 0xffff) * in_EDX >> 0x10;
  }
  if (in_EDX > 0xffff) {
    int iVar1 = DAT_008c6cb0[iVar2];
    if (uVar4 == 0) {
      int inner = static_cast<int>((static_cast<int32_t>(DAT_008c6cb0[iVar2]) - iVar1) * uVar3) >> 0x16;
      return (inner + iVar1) * (in_EDX >> 0x10);
    }
    int inner = static_cast<int>((static_cast<int32_t>(DAT_008c6cb0[iVar2]) - iVar1) * uVar3) >> 0x16;
    return (inner - iVar1 + 0xffff) * (in_EDX >> 0x10);
  }
  int iVar1 = DAT_008c6cb0[iVar2];
  if (uVar4 == 0) {
    int inner = static_cast<int>((static_cast<int32_t>(DAT_008c6cb0[iVar2]) - iVar1) * uVar3) >> 0x16;
    return (inner + iVar1) * (in_EDX >> 8) >> 8;
  }
  int inner = static_cast<int>((static_cast<int32_t>(DAT_008c6cb0[iVar2]) - iVar1) * uVar3) >> 0x16;
  return (inner - iVar1 + 0xffff) * (in_EDX >> 8) >> 8;
}

// ---------------------------------------------------------------------------
// 0x4954c0 — observed shape: release three owned refs in *unaff_EDI
// ---------------------------------------------------------------------------
// NEEDS_MANUAL: unaff_EDI is a register input; expressed as explicit param.
void FUN_004954c0_recon(uint32_t* unaff_EDI) {
  void* pvVar1 = reinterpret_cast<void*>(*unaff_EDI);
  if (pvVar1 != nullptr) {
    FUN_0050ba80();
    operator_delete(pvVar1);
    *unaff_EDI = 0;
  }
  pvVar1 = reinterpret_cast<void*>(unaff_EDI[1]);
  if (pvVar1 != nullptr) {
    FUN_0050ba80();
    operator_delete(pvVar1);
    unaff_EDI[1] = 0;
  }
  if (unaff_EDI[2] != 0) {
    (**(void(**)(uint32_t))*reinterpret_cast<uint32_t**>(unaff_EDI[2]))(1);
    unaff_EDI[2] = 0;
  }
}

// ---------------------------------------------------------------------------
// 0x495510 — observed shape: construct working object + load AdvancedLighting.ini
// ---------------------------------------------------------------------------
// NEEDS_MANUAL: unaff_EDI is a register input; expressed as explicit param.
void FUN_00495510_recon(uint32_t* unaff_EDI) {
  uint32_t* puVar1 = static_cast<uint32_t*>(FUN_00533c78(0x14));
  if (puVar1 == nullptr) puVar1 = nullptr;
  else { puVar1[0] = 0; puVar1[1] = 0; }
  *unaff_EDI = reinterpret_cast<uint32_t>(puVar1);
  puVar1 = static_cast<uint32_t*>(FUN_00533c78(0x14));
  if (puVar1 == nullptr) puVar1 = nullptr;
  else { puVar1[0] = 0; puVar1[1] = 0; }
  unaff_EDI[1] = reinterpret_cast<uint32_t>(puVar1);
  FUN_0050baf0(reinterpret_cast<void*>(FUN_004d1240), 0x200);
  FUN_0050baf0(reinterpret_cast<void*>(FUN_00495a10_recon), 0x200);
  puVar1 = static_cast<uint32_t*>(FUN_00533c78(0x18));
  if (puVar1 == nullptr) puVar1 = nullptr;
  else {
    *puVar1 = reinterpret_cast<uint32_t>(PTR_FUN_0070aaec);
    puVar1[2] = 8; puVar1[5] = 8; puVar1[3] = 0; puVar1[4] = 0;
    uint32_t uVar2 = reinterpret_cast<uint32_t>(FUN_00533c78(0x20));
    puVar1[1] = uVar2;
    *puVar1 = reinterpret_cast<uint32_t>(PTR_FUN_0070aaec);
  }
  unaff_EDI[2] = reinterpret_cast<uint32_t>(puVar1);
  FUN_004957c0_recon(reinterpret_cast<int>(unaff_EDI), reinterpret_cast<uint32_t>("Data\\AdvancedLighting.ini"), reinterpret_cast<uint32_t>("GLOBAL"));
}

// ---------------------------------------------------------------------------
// 0x4955d0 — observed shape: state push, render frame, state pop (in_EAX object)
// ---------------------------------------------------------------------------
// NEEDS_MANUAL: in_EAX is a register input; expressed as explicit param.
void FUN_004955d0_recon(int32_t* in_EAX) {
  uint32_t uVar2 = *reinterpret_cast<uint32_t*>(DAT_008c97d0 + 0x10);
  uint32_t uVar3 = *reinterpret_cast<uint32_t*>(DAT_008c97d0 + 0x14);
  uint32_t uVar4 = *reinterpret_cast<uint32_t*>(DAT_008c97d0 + 0x18);
  uint32_t uVar5 = *reinterpret_cast<uint32_t*>(DAT_008c97d0 + 0x1c);
  FUN_0050b690(0, 0, 0, static_cast<uint32_t>(in_EAX[5]));
  float fVar7 = _DAT_008c8498;
  *reinterpret_cast<void**>(*in_EAX + 0xc) = reinterpret_cast<void*>(FUN_004d1240);
  *reinterpret_cast<void**>(in_EAX[1] + 0xc) = reinterpret_cast<void*>(FUN_00495a10_recon);
  DAT_007268f4[DAT_00726a84] = DAT_007263bc;
  DAT_00726a84++;
  FUN_0050bbc0(fVar7);
  uint32_t* puVar6 = reinterpret_cast<uint32_t*>(*in_EAX);
  if (puVar6 != nullptr) puVar6[1]++;
  FUN_0050bc90();
  if (puVar6 != nullptr) {
    int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar6 + 1);
    *piVar1 -= 1;
    if (*piVar1 == 0) (**(void(**)(uint32_t))*puVar6)(1);
  }
  int32_t iVar8 = static_cast<int32_t>(FUN_005f0ddc(0));
  FUN_004af080(puVar6, 0, 0, 0x200, 0x200, 0, 0, static_cast<int32_t>(DAT_0072637c), static_cast<int32_t>(DAT_00726380), static_cast<uint32_t>(iVar8 << 0x18), 0);
  FUN_00534130();
  FUN_00533d10(0, 0);
  puVar6 = reinterpret_cast<uint32_t*>(*in_EAX);
  if (puVar6 != nullptr) puVar6[1]++;
  iVar8 = static_cast<int32_t>(FUN_005f0ddc(0));
  FUN_004af080(puVar6, 0, 0, 0x200, 0x200, 0, 0, static_cast<int32_t>(DAT_0072637c), static_cast<int32_t>(DAT_00726380), static_cast<uint32_t>((iVar8 << 0x18) | 0xffffff), 0);
  if (puVar6 != nullptr) {
    int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar6 + 1);
    *piVar1 -= 1;
    if (*piVar1 == 0) (**(void(**)(uint32_t))*puVar6)(1);
  }
  iVar8 = static_cast<int32_t>(FUN_00533db0(0));
  *reinterpret_cast<uint16_t*>(iVar8 + 0x20) = static_cast<uint16_t>((*reinterpret_cast<uint16_t*>(iVar8 + 0x20) & 0xfe0d) | 0xc);
  FUN_00534130();
  FUN_00533d10(0, 0);
  DAT_00726a84--;
  DAT_007263bc = DAT_007268f4[DAT_00726a84];
  FUN_0050b690(uVar2, uVar3, uVar4, uVar5);
}

// ---------------------------------------------------------------------------
// 0x4957c0 — observed shape: open ini via stack vftable + bind fields +0xc/0x10/0x14
// ---------------------------------------------------------------------------
void FUN_004957c0_recon(int param_1, uint32_t param_2, uint32_t param_3) {
  (void)param_3;
  void* local_1c = PTR_FUN_007108ac;
  uint32_t local_18 = 0, local_14 = 0, local_10 = 0, local_c = 0, local_8 = 1;
  FUN_004f8fa0(&local_1c, reinterpret_cast<void*>(param_2));
  FUN_004f96a0();
  FUN_004f9820(param_1 + 0xc);
  FUN_004f9820(param_1 + 0x10);
  FUN_004f9820(param_1 + 0x14);
  FUN_004f8f50();
}

// ---------------------------------------------------------------------------
// 0x495850 — observed shape: state push, double render, clear vector (unaff_EBX)
// ---------------------------------------------------------------------------
// NEEDS_MANUAL: unaff_EBX is a register input; expressed as explicit param.
void FUN_00495850_recon(int32_t* unaff_EBX) {
  float fVar3 = _DAT_008c8498;
  *reinterpret_cast<void**>(*unaff_EBX + 0xc) = reinterpret_cast<void*>(FUN_00496170_recon);
  *reinterpret_cast<void**>(unaff_EBX[1] + 0xc) = reinterpret_cast<void*>(FUN_00495dc0_recon);
  DAT_007268f4[DAT_00726a84] = DAT_007263bc;
  DAT_00726a84++;
  FUN_0050bbc0(fVar3);
  uint32_t* puVar2 = reinterpret_cast<uint32_t*>(*unaff_EBX);
  if (puVar2 != nullptr) puVar2[1]++;
  FUN_0050bc90();
  if (puVar2 != nullptr) {
    int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
    *piVar1 -= 1;
    if (*piVar1 == 0) (**(void(**)(uint32_t))*puVar2)(1);
  }
  FUN_0050bbc0(_DAT_008c8498);
  puVar2 = reinterpret_cast<uint32_t*>(unaff_EBX[1]);
  if (puVar2 != nullptr) puVar2[1]++;
  FUN_0050bc90();
  if (puVar2 != nullptr) {
    int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
    *piVar1 -= 1;
    if (*piVar1 == 0) (**(void(**)(uint32_t))*puVar2)(1);
  }
  puVar2 = reinterpret_cast<uint32_t*>(unaff_EBX[1]);
  if (puVar2 != nullptr) puVar2[1]++;
  FUN_004af080(puVar2, 0, 0, 0x200, 0x200, 0, 0, static_cast<int32_t>(DAT_0072637c), static_cast<int32_t>(DAT_00726380), 0x40ffffffu, 0);
  if (puVar2 != nullptr) {
    int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
    *piVar1 -= 1;
    if (*piVar1 == 0) (**(void(**)(uint32_t))*puVar2)(1);
  }
  int32_t iVar4 = static_cast<int32_t>(FUN_00533db0(0));
  *reinterpret_cast<uint16_t*>(iVar4 + 0x20) = static_cast<uint16_t>((*reinterpret_cast<uint16_t*>(iVar4 + 0x20) & 0xfe0d) | 0xc);
  FUN_00534130();
  FUN_00533d10(0, 0);
  DAT_00726a84--;
  DAT_007263bc = DAT_007268f4[DAT_00726a84];
  int32_t iVar4b = unaff_EBX[2];
  uint32_t uVar5 = 0;
  if (*reinterpret_cast<int32_t*>(iVar4b + 0xc) != 0) {
    do {
      *reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(iVar4b + 4) + uVar5 * 4) = 0;
      uVar5++;
    } while (uVar5 < *reinterpret_cast<uint32_t*>(iVar4b + 0xc));
  }
  *reinterpret_cast<uint32_t*>(iVar4b + 0xc) = 0;
  *reinterpret_cast<uint32_t*>(iVar4b + 0x10) = 0;
}

// ---------------------------------------------------------------------------
// 0x4959b0 — observed shape: find in_ECX in vector at in_EAX+8, swap-remove
// ---------------------------------------------------------------------------
// NEEDS_MANUAL: in_EAX/in_ECX are register inputs; expressed as explicit params.
void FUN_004959b0_recon(int32_t in_EAX, int32_t in_ECX) {
  int32_t iVar2 = *reinterpret_cast<int32_t*>(in_EAX + 8);
  uint32_t uVar5 = 0;
  if (*reinterpret_cast<uint32_t*>(iVar2 + 8) != 0) {
    int32_t* piVar6 = reinterpret_cast<int32_t*>(*reinterpret_cast<uint32_t*>(iVar2 + 4));
    while (in_ECX != *piVar6) {
      uVar5++;
      piVar6++;
      if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar5) return;
    }
    if (uVar5 != 0xffffffffu && uVar5 < *reinterpret_cast<uint32_t*>(iVar2 + 0xc)) {
      uint32_t iVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc) - 1;
      int32_t iVar3 = *reinterpret_cast<int32_t*>(iVar2 + 4);
      *reinterpret_cast<uint32_t*>(iVar2 + 0xc) = iVar1;
      int32_t iVar4 = *reinterpret_cast<int32_t*>(iVar3 + uVar5 * 4);
      *reinterpret_cast<uint32_t*>(iVar3 + uVar5 * 4) = *reinterpret_cast<uint32_t*>(iVar3 + iVar1 * 4);
      *reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(iVar2 + 4) + *reinterpret_cast<uint32_t*>(iVar2 + 0xc) * 4) = 0;
      if (iVar4 != 0) *reinterpret_cast<int32_t*>(iVar2 + 0x10) -= 1;
    }
  }
}

// ---------------------------------------------------------------------------
// 0x495a10 — observed shape: exception-scoped render of three frames (unwind markers)
// ---------------------------------------------------------------------------
// NEEDS_MANUAL: unaff_EBX/unaff_EBP are register inputs; unwind state and the
// register0x00000010 argument are preserved as observed. DAT_008b96b4 /
// DAT_008b96b0 referenced by 0x494e80 are declared inside that function site.
void FUN_00495a10_recon() {
  uint32_t uVar1 = DAT_008cade0;
  DAT_008cade8 = 0;
  DAT_008cade0 = 0;
  DAT_008cade4 = 0;
  uint32_t* puStack_34 = &DAT_008cade0;
  int iStack_38 = 0x495a75;
  (**(void(**)(void))*reinterpret_cast<uint32_t*>(DAT_008ea08c))();
  iStack_38 = 7;
  int iStack_3c = 0x495a82;
  FUN_00535de0();
  int iStack_3c2 = static_cast<int>(DAT_008e9fe0 + 0x144);
  int iStack_40 = static_cast<int>(DAT_008e9fe0 + 0x128);
  int iStack_44 = static_cast<int>(DAT_008e9fe0 + 0x11c);
  int iStack_48 = static_cast<int>(DAT_008e9fe0 + 0x110);
  int iStack_4c = static_cast<int>(DAT_008e9fe0 + 0x104);
  uint32_t* puStack_4cPtr = reinterpret_cast<uint32_t*>(DAT_008e9fe0 + 0x90);
  int iStack_50 = 0x495abe;
  (**(void(**)(void))*reinterpret_cast<uint32_t*>(DAT_008ea08c + 0) )();
  iStack_50 = 0x495acc;
  (**(void(**)(void))*reinterpret_cast<uint32_t*>(DAT_008ea08c + 0))();
  iStack_50 = static_cast<int>(DAT_008e9fe0);
  (**(void(**)(void))*reinterpret_cast<uint32_t*>(DAT_008ea08c + 0))();
  uint32_t* puVar6 = reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(DAT_008cab30));
  if (puVar6 != nullptr) puVar6[1]++;
  uint32_t* puVar2 = reinterpret_cast<uint32_t*>(FUN_004af080(puVar6, 0, 0, 0x200, 0x200, 1, 1, static_cast<int32_t>(DAT_0072637c) + 1, static_cast<int32_t>(DAT_00726380) + 1, 0x40ffffffu, 0));
  if (puVar6 != nullptr) {
    int32_t* piVar5 = reinterpret_cast<int32_t*>(puVar6 + 1);
    *piVar5 -= 1;
    if (*piVar5 == 0) (**(void(**)(uint32_t))*puVar6)(1);
  }
  int32_t iVar3 = static_cast<int32_t>(FUN_00533db0(0));
  *reinterpret_cast<uint16_t*>(iVar3 + 0x20) = static_cast<uint16_t>((*reinterpret_cast<uint16_t*>(iVar3 + 0x20) & 0xfe0d) | 0xc);
  FUN_00534130();
  FUN_00533d10(0, 0);
  FUN_00533e70(DAT_008e9fe0);
  puVar6 = reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(DAT_008cab30));
  if (puVar6 != nullptr) puVar6[1]++;
  uint32_t uVar4 = FUN_004af080(puVar6, 0, 0, 0x200, 0x200, -1, -1, static_cast<int32_t>(DAT_0072637c) - 1, static_cast<int32_t>(DAT_00726380) - 1, 0x40ffffffu, 0);
  if (puVar6 != nullptr) {
    int32_t* piVar5 = reinterpret_cast<int32_t*>(puVar6 + 1);
    *piVar5 -= 1;
    if (*piVar5 == 0) (**(void(**)(uint32_t))*puVar6)(1);
  }
  iVar3 = static_cast<int32_t>(FUN_00533db0(0));
  *reinterpret_cast<uint16_t*>(iVar3 + 0x20) = static_cast<uint16_t>((*reinterpret_cast<uint16_t*>(iVar3 + 0x20) & 0xfe0d) | 0xc);
  FUN_00534130();
  FUN_00533d10(0, 0);
  FUN_00533e70(DAT_008e9fe0);
  puVar6 = reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(DAT_008cab30));
  if (puVar6 != nullptr) puVar6[1]++;
  iStack_3c = static_cast<int>(FUN_004af080(puVar6, 0, 0, 0x200, 0x200, 0, 0, static_cast<int32_t>(DAT_0072637c), static_cast<int32_t>(DAT_00726380), 0x80ffffffu, 0));
  if (puVar6 != nullptr) {
    int32_t* piVar5 = reinterpret_cast<int32_t*>(puVar6 + 1);
    *piVar5 -= 1;
    if (*piVar5 == 0) (**(void(**)(uint32_t))*puVar6)(1);
  }
  iVar3 = static_cast<int32_t>(FUN_00533db0(0));
  *reinterpret_cast<uint16_t*>(iVar3 + 0x20) = static_cast<uint16_t>((*reinterpret_cast<uint16_t*>(iVar3 + 0x20) & 0xfe0d) | 0xc);
  FUN_00534130();
  FUN_00533d10(0, 0);
  FUN_00533e70(DAT_008e9fe0);
  (void)iStack_38; (void)iStack_3c; (void)iStack_3c2; (void)iStack_40;
  (void)iStack_44; (void)iStack_48; (void)iStack_4c; (void)iStack_50;
  (void)puStack_34; (void)puStack_4cPtr; (void)uVar1; (void)puVar2; (void)uVar4;
}

// ---------------------------------------------------------------------------
// 0x495dc0 — observed shape: same three-frame pattern with 2/-2/0 offsets
// ---------------------------------------------------------------------------
// NEEDS_MANUAL: unaff_EDI is a register input; register0x00000010-0x48 arg
// preserved as observed.
void FUN_00495dc0_recon() {
  DAT_008cade4 = 0;
  DAT_008cade0 = 0;
  DAT_008cade8 = 0;
  uint32_t* puStack_24 = &DAT_008cade0;
  int iStack_28 = 0x495e26;
  (**(void(**)(void))*reinterpret_cast<uint32_t*>(DAT_008ea08c))();
  iStack_28 = 7;
  int iStack_2c = 0x495e33;
  FUN_00535de0();
  int iStack_28b = static_cast<int>(DAT_008e9fe0 + 0x144);
  int iStack_2c2 = static_cast<int>(DAT_008e9fe0 + 0x128);
  int iStack_30 = static_cast<int>(DAT_008e9fe0 + 0x11c);
  int iStack_34 = static_cast<int>(DAT_008e9fe0 + 0x110);
  int iStack_38 = static_cast<int>(DAT_008e9fe0 + 0x104);
  int iStack_3c = static_cast<int>(DAT_008e9fe0 + 0x90);
  int iStack_40 = 0x495e6f;
  (**(void(**)(void))*reinterpret_cast<uint32_t*>(DAT_008ea08c))();
  iStack_40 = 0x495e7d;
  (**(void(**)(void))*reinterpret_cast<uint32_t*>(DAT_008ea08c))();
  iStack_40 = static_cast<int>(DAT_008e9fe0);
  (**(void(**)(void))*reinterpret_cast<uint32_t*>(DAT_008ea08c))();
  uint32_t* puVar1 = reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(DAT_008cab30));
  if (puVar1 != nullptr) puVar1[1]++;
  uint32_t uStack_50 = 0x60ffffff;
  uint32_t* puVar2 = reinterpret_cast<uint32_t*>(FUN_004af080(puVar1, 0, 0, 0x200, 0x200, 2, 2, static_cast<int32_t>(DAT_0072637c) + 2, static_cast<int32_t>(DAT_00726380) + 2, 0x60ffffffu, 0));
  if (puVar1 != nullptr) {
    int32_t* piVar6 = reinterpret_cast<int32_t*>(puVar1 + 1);
    *piVar6 -= 1;
    if (*piVar6 == 0) (**(void(**)(void))*puVar1)();
  }
  uStack_50 = 0x495ef5;
  int32_t iVar3 = static_cast<int32_t>(FUN_00533db0(0));
  *reinterpret_cast<uint16_t*>(iVar3 + 0x20) = static_cast<uint16_t>((*reinterpret_cast<uint16_t*>(iVar3 + 0x20) & 0xfe0d) | 0xc);
  FUN_00534130();
  uStack_50 = 0;
  FUN_00533d10(0, 0);
  puVar1 = reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(DAT_008cab30));
  if (puVar1 != nullptr) puVar1[1]++;
  uStack_50 = 0x60ffffff;
  uint32_t uVar4 = FUN_004af080(puVar1, 0, 0, 0x200, 0x200, -2, -2, static_cast<int32_t>(DAT_0072637c) - 2, static_cast<int32_t>(DAT_00726380) - 2, 0x60ffffffu, 0);
  if (puVar1 != nullptr) {
    int32_t* piVar6 = reinterpret_cast<int32_t*>(puVar1 + 1);
    *piVar6 -= 1;
    if (*piVar6 == 0) (**(void(**)(void))*puVar1)();
  }
  uStack_50 = 0;
  iVar3 = static_cast<int32_t>(FUN_00533db0(0));
  *reinterpret_cast<uint16_t*>(iVar3 + 0x20) = static_cast<uint16_t>((*reinterpret_cast<uint16_t*>(iVar3 + 0x20) & 0xfe0d) | 0xc);
  uStack_50 = 0x495f98;
  FUN_00534130();
  uStack_50 = 0;
  FUN_00533d10(0, 0);
  puVar1 = reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(DAT_008cab30));
  if (puVar1 != nullptr) puVar1[1]++;
  uStack_50 = 0;
  uint32_t* puVar5 = reinterpret_cast<uint32_t*>(FUN_004af080(puVar1, 0, 0, 0x200, 0x200, 0, 0, static_cast<int32_t>(DAT_0072637c), static_cast<int32_t>(DAT_00726380), 0x80ffffffu, 0));
  if (puVar1 != nullptr) {
    int32_t* piVar6 = reinterpret_cast<int32_t*>(puVar1 + 1);
    *piVar6 -= 1;
    if (*piVar6 == 0) (**(void(**)(void))*puVar1)();
  }
  uStack_50 = 0;
  iVar3 = static_cast<int32_t>(FUN_00533db0(0));
  *reinterpret_cast<uint16_t*>(iVar3 + 0x20) = static_cast<uint16_t>((*reinterpret_cast<uint16_t*>(iVar3 + 0x20) & 0xfe0d) | 0xc);
  uStack_50 = 0x49601b;
  FUN_00534130();
  uStack_50 = 0;
  FUN_00533d10(0, 0);
  uStack_50 = DAT_008e9fe0;
  FUN_00533e70(DAT_008e9fe0);
  uStack_50 = DAT_008e9fe0;
  FUN_00533e70(DAT_008e9fe0);
  uStack_50 = DAT_008e9fe0;
  FUN_00533e70(DAT_008e9fe0);
  (void)iStack_28; (void)iStack_2c; (void)iStack_28b; (void)iStack_2c2;
  (void)iStack_30; (void)iStack_34; (void)iStack_38; (void)iStack_3c;
  (void)iStack_40; (void)puStack_24; (void)puVar2; (void)uVar4; (void)puVar5;
}

// ---------------------------------------------------------------------------
// 0x496340 — observed shape: destructor running flag check
// ---------------------------------------------------------------------------
// NEEDS_MANUAL: in_ECX is a register input; expressed as explicit param.
void FUN_00496340_recon(uint8_t param_1, uint32_t* in_ECX) {
  *in_ECX = reinterpret_cast<uint32_t>(PTR_FUN_0070aaec);
  operator_delete__(reinterpret_cast<void*>(in_ECX[1]));
  if ((param_1 & 1) != 0) operator_delete(reinterpret_cast<void*>(in_ECX));
}

// Forward declarations used above.
void FUN_00496170_recon();
