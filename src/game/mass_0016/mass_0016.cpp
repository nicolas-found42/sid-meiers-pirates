#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cstdlib>

// extern helpers / globals referenced by the observed listings
extern void FUN_004879f0(int,int);
extern void FUN_00488b00(void*,int,float,float,int,int,int,int,int,int,int);
extern int FUN_0045ac90(int,int,int,int,int,int,int,int);
extern int FUN_004db270();
extern int FUN_004db210();
extern int FUN_0044ea50(int);
extern int FUN_0044eb10(int,int,int,int,int);
extern int FUN_0045fc70(int,int);
extern int FUN_0045fcb0(int,int,uint,int,uint);
extern int FUN_0045fee0(int,int,uint,int,uint);
extern int FUN_0045fd40(int,int,uint,int,uint);
extern void FUN_004f6090(const char*,...);
extern void FUN_004f60b0(const char*,...);
extern void FUN_00430190(int,int,void*,int,int,int,int,int,int,int);
extern uint32_t FUN_00460480();
extern void FUN_004600d0();
extern void FUN_00467f90(uint**);
extern void FUN_00467430(int);
extern void FUN_00467df0();
extern int FUN_0045bbf0(int);
extern void FUN_00413710(int,int,int);
extern void FUN_004bbc10(void*,int,int,int,int,int,int,int,int);
extern void FUN_004bbc80(int,int,int,int,int,int,int);
extern void FUN_0045b770(int,int,int);
extern int FUN_0045aa10(int,int);
extern void FUN_004bbe10(int,int);
extern void FUN_004c2200(int,int);
extern void FUN_004bcb60();
extern void FUN_004a2d50(int,int);
extern void FUN_004a40a0();
extern void FUN_004bc250(int);
extern void FUN_004bc7e0(int,int);
extern void FUN_004af760();
extern void FUN_004bcd30(int);
extern void FUN_004bcd00(int);
extern void FUN_004bca60();
extern void FUN_004bcac0();
extern void FUN_004bc790(int);
extern void FUN_004bc740(int);
extern void FUN_00465b40(int,int,int,int,char);
extern void FUN_00478410(int,int);
extern void FUN_00465db0(uint*,uint*,int*,char);
extern void FUN_00414c00(int,int);
extern void FUN_004ae850(int,int,int);
extern int FUN_00404810();
extern void FUN_004888e0(int,int,int,int);
extern void FUN_0043a970(int,int,int,int);
extern void FUN_004428a30(int);
extern void FUN_00415730();
extern void FUN_0045cab0(int);
extern void FUN_0045d2b0();
extern void FUN_0042d500(int,void*);
extern void FUN_004a3790();
extern void FUN_004e7950(int,int,int);
extern void FUN_004add70(int);
extern void FUN_00489440(int,int,int,int);
extern void FUN_00412840(float,float);
extern void FUN_004ad0c0(int,int,int,int,int,int,int);
extern void FUN_00489360(int,int,int,int,int);
extern void FUN_004e7510(float,float,int);
extern int FUN_005f0ddc(int,int,int,int);
extern int FUN_004a2d50_(int,int);
extern int FUN_0045a940(int);
extern void FUN_004aec30(int,int,int,int,int,int,int,int,int);
extern void FUN_00488a80(int,float,float,int,int,int,int,int,int,int,int);
extern void FUN_005516a0();
extern int FUN_00551600(int);
extern void FUN_005451a0(int);
extern int FUN_004baaa0();
extern void FUN_004985e0();
extern void FUN_004a14b0();
extern void FUN_00488840(const char*,int);
extern void FUN_00488f40(void*,int,int);
extern void FUN_004b06c0(void*,int,int,int,int,int,int,int);
extern void FUN_00428500(void*,int,int);
extern int FUN_00428950();
extern void FUN_00412950(int,int,int,int);
extern int FUN_0045e6b0();
extern int FUN_00405d90();
extern int FUN_00405d50();
extern void FUN_00414fc0(int,int);
extern void FUN_00466f00(int);
extern char FUN_00475b00();
extern int FUN_004ae7d0(int,int,int,int*,int*);
extern char FUN_004ae900(int,int,int*,float*);
extern void FUN_004d9d40(void*,int,int,int,int,int,int,int);
extern void FUN_004cce40();
extern void FUN_004ad820();
extern int FUN_004953d0();
extern int FUN_004dadc0(int,int,int);
extern void FUN_004bf9c0(void*,int);
extern void FUN_004bc950(void*,int);
extern void FUN_0045b5d0();
extern void FUN_0045b740();
extern void FUN_0044ce60();
extern void FUN_0044d2e0(int,int);
extern int FUN_0045fa70(int,int,int);
extern int FUN_00477450(int);
extern int FUN_00412810();
extern void FUN_004750c0(uint**,int,uint*,int,uint*);
extern int FUN_004db150();
extern void FUN_00404ca0();
extern int FUN_00405e20();
extern void FUN_004bc250_(int);
extern void FUN_004a2d50b(int,int);
extern void FUN_004bdca0(void*,int,int,int,int,int,int,int,int,int);
extern void FUN_004c0980(int,int);
extern void* FUN_00533c78(int);
extern void FUN_004ae7d0_(int,int,int,int*,int*);
extern void FUN_004e7760(float,float,void*,int);
extern void FUN_00475850();
extern int FUN_0042d460();
extern int FUN_0045c270(int);
extern void FUN_00412f70();
extern char* _itoa(int,char*,int);

extern int DAT_008b98f0;
extern int DAT_008b96b4;
extern int DAT_008b96b0;
extern int DAT_00860b68;
extern int DAT_00860b70;
extern int DAT_0085b170;
extern int DAT_00860b80;
extern int DAT_00869b48;
extern int DAT_00876bf8;
extern int DAT_008ca9e8;
extern int DAT_00860b94;
extern int DAT_0085a164;
extern int DAT_00814304;
extern int DAT_00814308;
extern int DAT_0081430c;
extern int DAT_00814310;
extern int DAT_00814350;
extern int DAT_008142f8;
extern int DAT_0085a154;
extern int DAT_0085a158;
extern int DAT_0085a26c;
extern int DAT_0085a268;
extern int DAT_00869ab0;
extern int DAT_00869ab4;
extern int DAT_00869ab8;
extern int DAT_00725678;
extern int DAT_00725684;
extern int DAT_008b97a8;
extern int DAT_008b9730;
extern int DAT_00814754;
extern int DAT_008b9988;
extern int DAT_00725740;
extern int DAT_008b9984;
extern int DAT_008b98e4;
extern int DAT_00725604;
extern int DAT_0072560c;
extern int DAT_00725610;
extern int DAT_00725608;
extern int DAT_008ca9c4;
extern int DAT_00725680;
extern int DAT_0081431a;
extern int DAT_00814318;
extern int DAT_00723b08;
extern int DAT_00723b1c;
extern int DAT_008142f8b;
extern char DAT_00876bec[];
extern int DAT_007b10a0;
extern int DAT_0076ef10;
extern int DAT_0074de48;
extern int DAT_0072cd80;
extern int DAT_007d2168;
extern int DAT_0085a270;
extern int DAT_0085a2b0;
extern int DAT_0085a380;
extern int DAT_00876cfc;
extern int DAT_00876cf8;
extern int DAT_008b9978;
extern int DAT_008b997c;
extern int DAT_008b98d4;

// 0x45fbf0 — observed shape
void FUN_0045fbf0() {
  int iVar2 = 0;
  do {
    int r1 = rand();
    (&DAT_008b98f0)[iVar2] = (r1 % 0x15 + -10 + DAT_008b96b4) * 1000;
    int r2 = rand();
    (&DAT_008b98e4)[iVar2] = (r2 % 0x15 + -10 + DAT_008b96b0) * 1000;
    if (iVar2 == 0) DAT_008b98f0 = (DAT_008b96b4 + 10) * 1000;
    iVar2++;
  } while (iVar2 < 3);
}

// 0x45fc70 — observed shape
int FUN_0045fc70(int esi, int edx) {
  int iVar1 = 0;
  int* piVar2 = &DAT_00860b68;
  while (((piVar2[2] < 0 || (*piVar2 != esi)) || (piVar2[1] != edx))) {
    piVar2 += 8; iVar1++;
    if (0x861b67 < (int)(uintptr_t)piVar2) return -1;
  }
  return iVar1;
}

// 0x45fcb0 — observed shape
int FUN_0045fcb0(int param_1, int param_2, uint32_t param_3, int param_4, uint32_t param_5) {
  int iVar4 = -1, iVar6 = 0;
  uint32_t uVar3 = (param_3 != 0x10) - 1 & 0x54;
  if (uVar3 != 0xffffffd4) {
    uint32_t* puVar5 = (uint32_t*)(uintptr_t)&DAT_00860b70;
    do {
      if (((param_3 & (1u << ((uint8_t)puVar5[1] & 0x1f))) != 0) && ((*puVar5 & param_5) == 0)) {
        int iVar1 = puVar5[-1] - param_2;
        int iVar2 = puVar5[-2] - param_1;
        if (iVar2 < 0) iVar2 = -iVar2;
        if (iVar1 < 0) iVar1 = -iVar1;
        if (iVar1 < iVar2) iVar1 = iVar1 + iVar2 * 2; else iVar1 = iVar2 + iVar1 * 2;
        if (iVar1 / 2 < param_4) { iVar4 = iVar6; param_4 = iVar1 / 2; }
      }
      iVar6++; puVar5 += 8;
    } while (iVar6 < (int)(uVar3 + 0x2c));
  }
  return iVar4;
}

// 0x45fd40 — observed shape
int FUN_0045fd40(int param_1, int param_2, uint32_t param_3, int param_4, uint32_t param_5) {
  int local_4 = -1;
  int* piVar4 = &DAT_0085b170;
  uint32_t* puVar3 = (uint32_t*)(uintptr_t)&DAT_00860b70;
  int iVar5 = 2;
  do {
    for (int slot = 0; slot < 4; slot++) {
      uint32_t* entry = puVar3 + slot * 8;
      int* coord = piVar4 + slot * 4;
      if (((param_3 & (1u << ((uint8_t)entry[1] & 0x1f))) != 0) && ((*entry & param_5) == 0)) {
        int iVar1 = coord[1] - param_2;
        int iVar2 = coord[0] - param_1;
        if (iVar2 < 0) iVar2 = -iVar2;
        if (iVar1 < 0) iVar1 = -iVar1;
        if (iVar1 < iVar2) iVar1 = iVar1 + iVar2 * 2; else iVar1 = iVar2 + iVar1 * 2;
        if (iVar1 / 2 < param_4) { local_4 = iVar5 + slot - 2; param_4 = iVar1 / 2; }
      }
    }
    int iVar1 = iVar5 + 2;
    puVar3 += 0x20; piVar4 += 0x10; iVar5 += 4;
    if (!(iVar1 < 0x80)) break;
  } while (true);
  return local_4;
}

// 0x45fee0 — observed shape
int FUN_0045fee0(int param_1, int param_2, uint32_t param_3, int param_4, uint32_t param_5) {
  int local_4 = -1; int best = param_4;
  int* piVar4 = &DAT_00860b80; int iVar3 = 2;
  do {
    for (int slot = 0; slot < 4; slot++) {
      int off = slot * 8;
      uint8_t flag = *(uint8_t*)((char*)piVar4 - 12 + off + slot*0);
      // observed condition uses bytes at piVar4-3, +5, +0xd, +0x15 strides
      if (((param_3 & (1u << (flag & 0x1f))) != 0) && ((param_4 == -1 || (piVar4[off] == param_4)) && ((piVar4[off-4] & param_5) == 0))) {
        int iVar1 = piVar4[off-5] - param_2;
        int iVar2 = piVar4[off-6] - param_1;
        if (iVar2 < 0) iVar2 = -iVar2;
        if (iVar1 < 0) iVar1 = -iVar1;
        if (iVar1 < iVar2) iVar1 = iVar1 + iVar2 * 2; else iVar1 = iVar2 + iVar1 * 2;
        if (iVar1 / 2 < best) { local_4 = iVar3 + slot - 2; best = iVar1 / 2; }
      }
    }
    int iVar1 = iVar3 + 2; piVar4 += 0x20; iVar3 += 4;
    if (!(iVar1 < 0x80)) break;
  } while (true);
  return local_4;
}

// 0x4600a0 — observed shape
void FUN_004600a0() {
  FUN_004879f0(0x20, 0);
  int iVar2 = 0;
  do {
    char* pcVar1 = (char*)(uintptr_t)&DAT_00869b48 + iVar2;
    (&DAT_00876bf8)[iVar2] = *pcVar1;
    iVar2++;
    if (*pcVar1 == '\0') break;
  } while (true);
  DAT_008ca9e8 = 100;
}

// 0x4600d0 — observed shape
void FUN_004600d0() {
  int iVar8 = 0;
  int local_14[5] = {0,0,0,0,0};
  char* pcVar3 = (char*)(uintptr_t)&DAT_00860b94;
  do {
    signed char cVar1 = pcVar3[-0x20];
    if (cVar1 != -1) local_14[cVar1]++;
    cVar1 = *pcVar3; if (cVar1 != -1) local_14[cVar1]++;
    cVar1 = pcVar3[0x20]; if (cVar1 != -1) local_14[cVar1]++;
    cVar1 = pcVar3[0x40]; if (cVar1 != -1) local_14[cVar1]++;
    pcVar3 += 0x80;
  } while ((int)(uintptr_t)pcVar3 < 0x861114);
  while (true) {
    int iVar4 = rand() % 0x2c; iVar8++;
    if (iVar8 < 99) {
      int iVar5 = DAT_008b96b0 - (&DAT_00860b68)[iVar4*8+1];
      int iVar7 = DAT_008b96b4 - (&DAT_00860b68)[iVar4*8];
      if (iVar7 < 0) iVar7 = -iVar7;
      if (iVar5 < 0) iVar5 = -iVar5;
      if (iVar5 < iVar7) iVar5 = iVar5 + iVar7*2; else iVar5 = iVar7 + iVar5*2;
      if (0x9a < iVar5/2) continue;
    }
    if ((((&DAT_00860b70)[iVar4*8] & 2) != 0) && (((&DAT_00860b70)[iVar4*8] & 0xc0001000) == 0)) {
      int iVar5 = iVar4 * 0x20;
      int iVar8b = (&DAT_00860b70)[iVar4*8+3];
      (&DAT_00860b70)[iVar4*8] |= 0x1000;
      int iVar7 = (iVar8b < 1) ? 0 : rand() % iVar8b;
      if ((((char)(*(char*)(uintptr_t)(&DAT_00860b70+ iVar5 + 6)) * 5 < iVar7) && (2 < local_14[(char)(*(char*)(uintptr_t)(&DAT_00860b70 + iVar5 + 4))])) && (iVar8b = FUN_0044ea50((int)(char)(*(char*)(uintptr_t)(&DAT_00860b70 + iVar5 + 4))), iVar8b < 4) && (((iVar8b = FUN_0045fcb0((&DAT_00860b68)[iVar4*8],(&DAT_00860b68)[iVar4*8+1], 1u << ((uint8_t)iVar8b & 0x1f), 9999, 0xc0008000), iVar8b != -1 && ((char)(*(char*)(uintptr_t)(&DAT_00860b70 + iVar8b*0x20 + 6)) * 2 < (int)(char)(*(char*)(uintptr_t)(&DAT_00860b70 + iVar8b*0x20 + 6)))) && (iVar8b = FUN_0044eb10(iVar8b, iVar4, (-(uint32_t)((*(char*)(uintptr_t)(&DAT_00860b70 + iVar8b*0x20 + 4)) != '\0') & 0xfffffff6) + 0x10, 0xffffffff, 7), iVar8b != -1))) {
        (&DAT_0085a974)[iVar8b*8] = iVar4;
        (&DAT_00814350)[*(int*)(uintptr_t)(&DAT_0085a97c + iVar8b*0x20) * 0x117] |= 0x800000;
      }
      int pick = rand() % 5;
      int uVar10 = 10, iVar5b = 7; uint32_t uVar9 = 0xffffffff;
      if (pick == 0) {
        uint8_t b = *(uint8_t*)(uintptr_t)(&DAT_00860b70 + iVar5 + 4);
        int t = FUN_0045fee0((&DAT_00860b68)[iVar4*8],(&DAT_00860b68)[iVar4*8+1], 1u << (b & 0x1f), 7, 0x80008000);
        if (t == -1) t = 0x2e;
        iVar8b = t; uVar10 = 10; iVar5b = (-(uint32_t)(b != 0) & 0xd) + 7;
      } else if (pick < 3) {
        if (pick == 1) {
          uint8_t b = *(uint8_t*)(uintptr_t)(&DAT_00860b70 + iVar5 + 4);
          int t = FUN_0045fee0((&DAT_00860b68)[iVar4*8],(&DAT_00860b68)[iVar4*8+1], 1u << (b & 0x1f), 7, 0x80008000);
          if (t == -1) t = 0x2e;
          iVar8b = t; uVar10 = 3; iVar5b = (-(uint32_t)(b != 0) & 0xfffffffd) + 8;
        } else {
          int t = FUN_0045fee0((&DAT_00860b68)[iVar4*8],(&DAT_00860b68)[iVar4*8+1], 0x20, 0xffffffff, 0x80008000);
          if (t == -1) t = 0x2e;
          iVar8b = t; uVar10 = 9; iVar5b = 0;
        }
      } else if (pick == 3) {
        uint8_t b = *(uint8_t*)(uintptr_t)(&DAT_00860b70 + iVar5 + 4);
        int t = FUN_0045fee0((&DAT_00860b68)[iVar4*8],(&DAT_00860b68)[iVar4*8+1], 1u << (b & 0x1f), 7, 0x80008000);
        if (t == -1) t = 0x2e;
        iVar8b = t; uVar10 = 5; iVar5b = (-(uint32_t)(b != 0) & 0xfffffff6) + 0xc;
      } else {
        int t = FUN_0045fee0((&DAT_00860b68)[iVar4*8],(&DAT_00860b68)[iVar4*8+1], 0x10, 0xffffffff, 0x80008000);
        if (t == -1) t = 0x2e;
        iVar8b = t; uVar10 = 6;
        uint32_t r = rand() & 0x80000001; if ((int)r < 0) r = (r - 1 | 0xfffffffe) + 1;
        iVar5b = 2 - (r != 0);
      }
      int res = FUN_0044eb10(iVar8b, iVar4, iVar5b, uVar9, uVar10);
      if (res != -1) {
        (&DAT_0085a974)[res*8] = iVar4;
        (&DAT_00814350)[*(int*)(uintptr_t)(&DAT_0085a97c + res*0x20) * 0x117] |= 0x800000;
      }
      return;
    }
  }
}

// NEEDS_MANUAL: interior case bodies for 0x460480 elided in provider listing excerpt; outer flow, constants and call order preserved below
// 0x460480 — observed shape
uint32_t FUN_00460480() {
  DAT_0085a140 = DAT_0085a150 / 72000;
  int iVar8 = 0; uint32_t* puVar4 = (uint32_t*)(uintptr_t)&DAT_00814350;
  do {
    if (((short)puVar4[-0x16] != -1) && ((*puVar4 & 0x1000) != 0)) iVar8++;
    if (((short)puVar4[0x101] != -1) && ((puVar4[0x117] & 0x1000) != 0)) iVar8++;
    if (((short)puVar4[0x218] != -1) && ((puVar4[0x22e] & 0x1000) != 0)) iVar8++;
    if (((short)puVar4[0x32f] != -1) && ((puVar4[0x345] & 0x1000) != 0)) iVar8++;
    puVar4 += 0x45c;
  } while ((int)(uintptr_t)puVar4 < 0x859f50);
  if (iVar8 == 0) DAT_00722a08 = -1;
  else if (DAT_00722a08 != -1) goto LAB;
  if ((DAT_0085a150 / 6000) % 0xc == 1) FUN_00415730();
LAB:
  {
    int iVar5 = 8 - ((-(uint32_t)((DAT_00869b34 & 0x40) != 0) & 0xfffffffd) + 4);
    iVar5 = (iVar5 < 1) ? 0 : rand() % iVar5;
    iVar5 += 1;
    int t = FUN_00404810();
    if (((t == 0) || (((DAT_00869ab8 == 0 && ((_DAT_0085a164 & 0x200) != 0)) && ((&DAT_008142f8)[iVar5 * 0x22e] != -1)))) && (((1 < DAT_00869b1a && ((_DAT_0085a164 & 0x480) == 0)) && (10 < DAT_00869ab0)))) {
      FUN_004888e0(0x54,0xffffffff,0xffffffff,0xbf800000);
      FUN_004f6090("Your second lieutenant approaches you on the quarterdeck. ");
      if (((_DAT_0085a164 & 0x200) == 0) || ((&DAT_008142f8)[iVar5 * 0x22e] == -1)) {
        FUN_004f60b0("'Captain, we've been sailing over @NUM months with only @NUM gold pieces to show for it. Perhaps we should return to port and divide up the plunder.'\n", (int)DAT_00869b1a, DAT_00869ab4);
      } else {
        FUN_004f60b0("'Captain, we've been sailing for @NUM long months. I'm taking the '@SHIPNAME' and heading back to port with some of the boys.' 'Good riddance, you slackers', you reply.\n", (int)DAT_00869b1a, (&DAT_008db618)[iVar5*3], (&DAT_008db61c)[iVar5*3], (&DAT_008db620)[iVar5*3]);
      }
      FUN_004879f0(0x20,0);
      FUN_00430190(DAT_0085a26c / 0x14, ((int)(DAT_0085a268 + (DAT_0085a268 >> 0x1f & 3U)) >> 2) + 1, &DAT_006fb75c,0,0xffffffff,0,0,0xffffffff,0,0);
      if (((_DAT_0085a164 & 0x200) != 0) && ((&DAT_008142f8)[iVar5 * 0x22e] != -1)) {
        // copy fleet entry iVar5 -> iVar12, reset fields, run 100 sailing ticks, adjust crew/gold
        int iVar12 = 8;
        for (int tries = 0; tries < 256; tries++) {
          short* ps = (short*)(uintptr_t)(&DAT_008165d8 + iVar12 * 0x22e);
          if (*ps != -1) break;
          int iVar9 = iVar12 * 0x45c;
          int* src = (int*)(uintptr_t)(&DAT_008142f8 + iVar5 * 0x22e);
          int* dst = (int*)(uintptr_t)(&DAT_008142f8 + iVar12 * 0x22e);
          for (int k = 0x117; k != 0; k--) { *dst++ = *src++; }
          *(uint16_t*)(uintptr_t)(&DAT_008142fa + iVar9) = 0;
          *(uint16_t*)(uintptr_t)(&DAT_008142fc + iVar12 * 0x117) = 4;
          uint16_t u = (uint16_t)FUN_0045fee0(DAT_008b96b4, DAT_008b96b0, 0x10, 0xffffffff, 0x80008000);
          *(uint16_t*)(uintptr_t)(&DAT_00814338 + iVar9) = u;
          (&DAT_00814336)[iVar12 * 0x22e] = u;
          uint32_t u11 = (&DAT_00814350)[iVar12 * 0x117];
          (&DAT_0081431e)[iVar12 * 0x22e] = (short)((int)(DAT_00869ab0 + (DAT_00869ab0 >> 0x1f & 3U)) >> 2);
          *(short*)(uintptr_t)(&DAT_00814328 + iVar9) = (short)((int)(DAT_00869ab4 + (DAT_00869ab4 >> 0x1f & 7U)) >> 3);
          _DAT_0085a164 |= 0x400;
          (&DAT_00814350)[iVar12 * 0x117] = u11 & 0xfffffbff;
          for (int n = 100; n != 0; n--) FUN_00467f90((uint**)iVar12);
          _DAT_0085a164 &= 0xfffffbff;
          FUN_00467df0();
          DAT_00869ab0 = DAT_00869ab0 - ((int)(DAT_00869ab0 + (DAT_00869ab0 >> 0x1f & 3U)) >> 2);
          FUN_0045bbf0(1);
          _DAT_00869a76 = _DAT_00869a76 - 3;
          DAT_00869ab4 = DAT_00869ab4 - ((int)(DAT_00869ab4 + (DAT_00869ab4 >> 0x1f & 7U)) >> 3);
          goto LAB2;
        }
        FUN_00467df0();
        DAT_00869ab0 = DAT_00869ab0 - ((int)(DAT_00869ab0 + (DAT_00869ab0 >> 0x1f & 3U)) >> 2);
        FUN_0045bbf0(1);
        _DAT_00869a76 = _DAT_00869a76 - 3;
        DAT_00869ab4 = DAT_00869ab4 - ((int)(DAT_00869ab4 + (DAT_00869ab4 >> 0x1f & 7U)) >> 3);
      LAB2:
        _DAT_0085a164 &= 0xfffffdff;
      } else {
        _DAT_0085a164 |= 0x200;
        _DAT_0085a164 &= 0xfffffdff;
      }
    } else {
      _DAT_0085a164 &= 0xfffffdff;
    }
  }
  if (DAT_0085a154 != 0) { _DAT_00869a76 = _DAT_00869a76 + 1; DAT_00869b1a = DAT_00869b1a + 1; }
  if ((DAT_00869b34 & 4) == 0) {
    int i8 = (int)((int64_t)DAT_00869ab8 * (int64_t)-0x66666667 >> 32);
    DAT_00869ab8 = DAT_00869ab8 + ((i8 >> 2) - (i8 >> 0x1f));
  }
  int iVar5b = (DAT_00869ab0 + 1) / (int)((DAT_00869b34 & 4 | 8) >> 2);
  int iVar8b = DAT_008ca9ec + DAT_00869ab8 * 10;
  int iVar12 = (iVar5b == 0) ? 0xc : iVar8b / iVar5b;
  iVar8b = iVar8b - iVar5b;
  DAT_00869ab8 = iVar8b / 10; DAT_008ca9ec = iVar8b % 10;
  if (iVar8b < 0) {
    DAT_008ca9ec = 0; DAT_00869ab8 = 0;
    if ((_DAT_0085a164 & 0x400) == 0) {
      FUN_004f6090("Captain, the men are starving.");
      DAT_00869a74 = DAT_00869a74 - 1; _DAT_00869a76 = _DAT_00869a76 + 1;
      FUN_004879f0(0x20,0);
      int i8 = 0; do { char* pc = (char*)(uintptr_t)&DAT_00869b48 + i8; (&DAT_00876bf8)[i8] = *pc; i8++; if (*pc=='\0') break; } while(true);
      DAT_008ca9e8 = 100;
      FUN_004888e0(0x3f,0xffffffff,0xffffffff,0xbf800000);
      _DAT_0085a164 |= 0x200;
    }
  } else {
    FUN_004f6090(iVar12 < 4 ? "Captain, we only have food for @NUM months." : "@NUM months food.", iVar12);
  }
  // decay crew/morale at 0x814318 stride 0x8b8 and process port events 0x85a8b0 stride 6,
  // then random port spacing updates at 0x860b70 and rivalry checks at 0x85a168
  // with constants 0xc0000000, 0xffffff7e, 0xfffff7ff, 0xffffefff, 0xfffeffff, 0x13/0x11/0x10
  // returning 1 / 0xffffffff / 0 per observed paths.
  return 0;
}

// 0x460f50 — observed shape
uint32_t FUN_00460f50(char param_1, uint8_t param_2, int in_EAX, int in_EDX, char in_CL) {
  if (in_CL == '\0') param_2 = (uint8_t)(_DAT_0085a164 >> 7) & 1;
  if (param_2 == 0) {
    if ((in_EAX < 0x41eb1) || (in_EDX < 0x347d9)) {
      if (in_EDX < 0x6e281) {
        if (in_EDX < 0x6ac35) return 0;
        if (0x8777 < in_EAX) return 0;
        if (param_1 != '\0') {
          uint32_t u3 = (int)(0x1a10ab20U - DAT_00814304) >> 0x1f;
          uint32_t u4 = (int)(0x2112cc0U - DAT_00814308) >> 0x1f;
          if ((int)((0x1a10ab20U - DAT_00814304 ^ u3) - u3) < (int)((0x2112cc0U - DAT_00814308 ^ u4) - u4)) {
            DAT_00814304 = in_EDX * 1000; if (0x1a10ab1f < DAT_00814304) DAT_00814304 = 0x1a10ab20; DAT_0081430c = 0xc0000000;
          } else {
            DAT_00814308 = in_EAX * 1000; if (DAT_00814308 < 0x2112cc1) DAT_00814308 = 0x2112cc0; DAT_0081430c = 0;
          }
        }
      } else if (param_1 != '\0') {
        DAT_00814304 = in_EDX * 1000; DAT_0081430c = 0xc0000000; if (0x1ae4c3ff < DAT_00814304) DAT_00814304 = 0x1ae4c400;
      }
    } else if (param_1 != '\0') {
      uint32_t u3 = (int)(270000000U - DAT_00814308) >> 0x1f;
      uint32_t u4 = (int)(215000000U - DAT_00814304) >> 0x1f;
      DAT_0081430c = 0x80000000;
      if ((int)((215000000U - DAT_00814304 ^ u4) - u4) < (int)((270000000U - DAT_00814308 ^ u3) - u3)) {
        DAT_00814304 = in_EDX * 1000; if (214999999 < DAT_00814304) DAT_00814304 = 215000000;
      } else {
        DAT_00814308 = in_EAX * 1000; if (269999999 < DAT_00814308) DAT_00814308 = 270000000;
      }
    }
    if (param_1 != '\0') {
      FUN_004f6090("You have strayed too far from the action. You turn around and set sail for the heart of the Caribbean!\n");
      FUN_004879f0(0x30,0);
      FUN_00430190(DAT_0085a26c / 6, (int)(DAT_0085a268 + (DAT_0085a268 >> 0x1f & 0xfU)) >> 4, &DAT_006fb55c,0,0xffffffff,0,0,0xffffffff,0,0);
      return 1;
    }
  } else {
    if ((((14999 < in_EAX) && (14999 < in_EDX)) && (in_EAX < 0x445c1)) && (in_EDX < 0x6ac35)) return 0;
    if (param_1 != '\0') {
      int* pi = &DAT_0085a7b0;
      do {
        int v = *pi;
        if (v < 15000000) v = 15000000;
        else if (v < 0x1a10ab21) { if (v < 15000000) v = 15000000; }
        else v = 0x1a10ab20;
        *pi = v;
        int w = pi[8];
        if (w < 15000000) w = 15000000;
        else if (w < 0x10b07601) { if (w < 15000000) w = 15000000; }
        else w = 280000000;
        pi[8] = w; pi[0x18] = pi[0x18] + -0x80000000; pi[0x30] = *pi; pi[0x38] = pi[8]; pi[0x20] = 0;
        pi++;
      } while ((int)(uintptr_t)pi < 0x85a7d0);
      FUN_004a2d50(*(int*)(uintptr_t)(&DAT_00877048 + DAT_0085a790 * 4), 0xffffffff);
    }
    if (param_1 != '\0') {
      FUN_004f6090("You have strayed too far from the action. You turn around and walk further inland.\n");
      FUN_004879f0(0x30,0);
      FUN_00430190(DAT_0085a26c / 6, (int)(DAT_0085a268 + (DAT_0085a268 >> 0x1f & 0xfU)) >> 4, &DAT_006fb55c,0,0xffffffff,0,0,0xffffffff,0,0);
    }
  }
  return 1;
}

// NEEDS_MANUAL: interior fleet-render loop bodies for 0x4612b0 are extensive; head, sea/land branches, crew/wind reporting and audio tail preserved, fleet loop condensed with observed priority constants
// 0x4612b0 — observed shape
void FUN_004612b0(void* param_1, char param_2, int in_ECX, int in_EAX) {
  if ((_DAT_0085a164 & 0x40) == 0) { in_ECX += FUN_004db210(); in_EAX += -500 + FUN_004db210(); }
  int z[8] = {0,0,0,0,0,0,0,0};
  FUN_00460f50(1,0,in_EAX,in_ECX,0);
  int iVar6 = DAT_0072cd78;
  int local_118 = (DAT_00725678 + 1) / 2;
  *(float*)(DAT_0072cd78 + 0x10) = (float)local_118 * *(float*)(DAT_0072cd78 + 0x14);
  FUN_004e7950(iVar6,in_ECX,in_EAX);
  if ((DAT_008ca9f0 == '\0') && (DAT_007253b8 != 0x4b0)) {
    DAT_007253b8 = (int)((DAT_007253b8 & 3) + 4 + DAT_007253b8) % 0x960;
    FUN_004add70(DAT_007253b8);
  }
  int iVar15 = DAT_008b98e0;
  uint32_t uVar16 = _DAT_0085a164;
  _DAT_007255fc = 0x10; _DAT_008b998c = 0x10;
  DAT_008b98fc = DAT_008b98fc + ((int)((DAT_0081430c - DAT_008b98fc) + (DAT_0081430c - DAT_008b98fc >> 0x1f & 7U)) >> 3);
  uint32_t sea = _DAT_0085a164 & 0x40;
  DAT_0085a124 = in_EAX; DAT_0085a128 = in_ECX; DAT_0085a134 = in_EAX; DAT_0085a138 = in_ECX;
  DAT_008b98dc = FUN_00489440(DAT_008b98dc, DAT_00725688, 0x46, 0);
  int i6 = DAT_0087751c;
  if ((uVar16 & 4) == 0) { iVar15 += DAT_008b98dc; DAT_008b98e0 = iVar15; }
  if (iVar15 < 100) { iVar15 = 100; DAT_008b98e0 = 100; }
  if ((DAT_008ee200 & 1) == 0) { DAT_008ee200 |= 1; DAT_008ee1fc = DAT_0085a0fc * 500; }
  DAT_008ee1fc = DAT_008ee1fc + (DAT_0085a0fc * 500 - DAT_008ee1fc) / 10;
  uVar16 = (((iVar15 * 3) / 2) * DAT_00725678) / 2 + DAT_008ee1fc;
  uint32_t local_110 = uVar16;
  if (param_1 == nullptr) {
    if (sea == 0) {
      int v = ((int)(uVar16 - 0x9c4) / 3 + 0x9c4) * DAT_00725678;
      local_110 = (int)(v + (v >> 0x1f & 3U)) >> 2;
      if ((int)local_110 < 0x1389) { if ((int)local_110 < 500) local_110 = 500; } else local_110 = 5000;
      uVar16 = local_110;
      int l118 = DAT_0085a0fc * 0x50 + 1000;
      FUN_00412840((float)l118,(float)(DAT_0085a0fc * 0x50 + 75000));
      FUN_004ad0c0(DAT_0085a138, DAT_0085a134 - (int)(uVar16 << 7) / 0x28, (int)(uVar16 * 0x50) / 0x28, 0, 0x15555555, 0, 0x238e38e3);
      DAT_008b98d8 = 0;
    } else {
      uint32_t f80 = _DAT_0085a164 & 0x80;
      if (f80 != 0) { DAT_0085a138 = DAT_0085a7b0 / 1000; DAT_0085a134 = DAT_0085a7d0 / 1000; }
      DAT_00877518 = FUN_00489440(DAT_00877518, 0x2d82d8, 0x38e38e3, 0);
      DAT_0087751c = i6 + DAT_00877518; DAT_008b98d8 = DAT_0087751c;
      if (f80 == 0) {
        uVar16 = (int)uVar16 / 3; local_110 = uVar16;
        FUN_00412840(0x43fa0000f, 0x46ea6000f);
        FUN_00489360(DAT_0085a138, (int)(uVar16 + 5000 + ((int)(uVar16 + 5000) >> 0x1f & 7U)) >> 3, (int)((uVar16 + 8000) * 0x20) / 0x32, 0, 0x1c71c71c);
      } else {
        int l118 = (DAT_0085a7f0 * 5 + 0x30d4) * 2;
        FUN_00412840(0x43fa0000f,(float)l118);
        int l1 = DAT_0085a7d0 / 1000 - FUN_004db210();
        int l2 = DAT_0085a7b0 / 1000 - FUN_004db210();
        FUN_004e7510((float)l2,(float)l1,1);
        uint32_t sp, dv;
        if ((_DAT_0085a164 & 0x1000) == 0) { sp = 6000 / (long long)(DAT_0085a158 + 2); dv = (int)(0x2ee / (long long)(DAT_0085a158 + 2)) + DAT_0085a7f0; }
        else { sp = 1000; dv = DAT_0085a7f0 + 0xfa; }
        FUN_00489360(DAT_0085a138, dv, sp, 0, 0x1c71c71c);
      }
    }
  } else {
    ((void(*)())param_1)();
  }
  int i1430c = DAT_0081430c;
  _DAT_007255fc = 0x10; _DAT_008b998c = 0x10;
  uint32_t diff = DAT_00725600 - DAT_0081430c;
  int adiff = (diff ^ (int)diff >> 0x1f) - ((int)diff >> 0x1f);
  DAT_0072560c = 1000;
  if (0x40000000 < adiff) {
    int s = ((int)diff < 1) ? ((-1 < (int)diff) - 1) : 1;
    diff = (-0x80000000 - adiff) * s;
  }
  int iVar13 = ((int)diff / 0x50) * DAT_0085a0f8;
  int l114 = FUN_004db210();
  int l15 = FUN_004db210();
  int ship = (int)DAT_008142f8;
  l114 = FUN_004db210();
  if ((_DAT_0085a164 & 0x80) != 0) { l114 /= 10; l15 /= 10; }
  int l118 = FUN_005f0ddc(0,0,0,0);
  if ((char)(*(int*)(uintptr_t)(&DAT_00723b20 + ship * 0x44)) < '\0') {
    DAT_00814346 = FUN_0045b770((int)DAT_008142f8 % 9, i1430c, (int)DAT_00814346);
    int o = FUN_0045aa10(0,1);
    FUN_004bbc10((void*)(uintptr_t)o, DAT_00814304/1000, DAT_00814308/1000, l118, i1430c + -0x80000000, l114, (l15 + DAT_00814314 * -8) - iVar13, 0xffffffff, DAT_008c8494);
    FUN_004bbe10(0,(int)DAT_00814346); FUN_004c2200(100,0); FUN_004bcb60();
    if (param_2 != '\0') { FUN_004a2d50(o, DAT_00814310); FUN_004a40a0(); }
    FUN_004bc250(100); FUN_004bc7e0(0,1); FUN_004af760();
    FUN_004bcd30((DAT_007253bc - i1430c) + -0x80000000);
    // condensed flag/tree sprites and damage-report blocks (0x31 / 0x64 thresholds)
  } else {
    FUN_004bbc10((void*)(uintptr_t)(&DAT_008cba18 + ((int)DAT_008142f8 % 9) * 0x30), DAT_00814304/1000, DAT_00814308/1000, l118, i1430c + -0x80000000, l114, (l15 + DAT_00814314 * -8) - iVar13, 0xffffffff, 0);
    FUN_004c2200(100,0);
  }
  FUN_0045a940(DAT_0085a150);
  if ((int)DAT_00814318 + (int)DAT_0081431a == 0) FUN_004f6090("Crew:@NUM Cannon:@NUM", DAT_00869ab0, DAT_00869acc);
  else FUN_004f6090("Crew:@NUM Cannon:@NUM Damage:@NUM/@NUM%", DAT_00869ab0, DAT_00869acc, (int)DAT_0081431a, (int)DAT_00814318);
  if ((_DAT_0085a164 & 4) == 0) {
    DAT_008b98d0 = DAT_008b98d0 - ((int)(DAT_008b98d0 + (DAT_008b98d0 >> 0x1f & 7U)) >> 3);
    DAT_008b98cc = DAT_008b98cc - ((int)(DAT_008b98cc + (DAT_008b98cc >> 0x1f & 7U)) >> 3);
  }
  if ((_DAT_0085a164 & 0x20) == 0) {
    FUN_004f6090("Wind: @NUM", DAT_007253bc / 0xb60b60);
    FUN_004f6090((DAT_00869aac & 1) == 0 ? "Battle Sails" : "Full Sails");
  }
  // fleet loop 8..0x100, coastal audio, wake sprites (0x8b98f0/0x8b98e4) and stream shutdown tail
  // preserved in outline: per-ship FUN_004ae7d0/FUN_004aec30/FUN_0045ac90 prioritization,
  // DAT_008c9de8/DAT_008c9dd8 camera setup, audio channels via FUN_004985e0/FUN_004a14b0.
  if (DAT_008ca9e8 == '\0') {
    if ((DAT_008b9988 != -1) && ((&DAT_008142f8)[DAT_008b9988 * 0x22e] != -1) && (((&DAT_00814350)[DAT_008b9988 * 0x117] & 8) != 0) && (((&DAT_00814350)[DAT_008b9988 * 0x117] & 0x100000) == 0 && (DAT_008b9984 < 0x96)) && ((-1 < DAT_0085a164 && (((byte)DAT_007253b0 & 1) == 0)))) {
      FUN_004f6090("Press keypad '5' to attack @NATIONALITY @SHIPTYPE", (int)*(short*)(uintptr_t)(&DAT_008142fc + DAT_008b9988 * 0x117), (int)(&DAT_008142f8)[DAT_008b9988 * 0x22e]);
      DAT_0085a11c = 0x4b;
    }
    if ((DAT_0085a164 < '\0') && (DAT_008b9978 == 0)) {
      FUN_004f6090("Press 'r' to return to ship.");
      DAT_0085a11c = 0x4b;
      FUN_004b06c0(&DAT_00869b48, DAT_0085a26c/2, 8, 0x4b, 0xffffffff, 4, 0xffffffff, 0);
    }
  } else {
    DAT_008ca9e8 = DAT_008ca9e8 + -1;
  }
  FUN_004f6090("@NUM/@NUM", DAT_00725604, DAT_008b9988);
}

// NEEDS_MANUAL: interior city-render switch (cases 0-7) and crowd loops for 0x463cd0 are extensive; head, grid walk, nearest-city bookkeeping and departure tail preserved, interior condensed
// 0x463cd0 — observed shape
void FUN_00463cd0(void* param_1, void* param_2, int* param_3, uint32_t param_4) {
  DAT_008b9990 = (char)param_4;
  int local_c0 = (-(uint32_t)((char)param_4 != '\0') & 0xfffffffa) + 0x10;
  int iVar13 = DAT_00725678 * local_c0;
  int iVar4 = iVar13 / 2;
  int local_c8 = -1;
  int local_d0 = 0;
  int iVar5 = DAT_00725678;
  if (0 < iVar4) {
    do {
      int local_d4 = 0;
      int iVar9 = (-(uint32_t)((_DAT_0085a164 & 0xc0) != 0) & 0xfffffff8) + 8;
      if (0 < iVar4 + iVar9) {
        do {
          int i5 = (int)(iVar13 + (iVar13 >> 0x1f & 3U)) >> 2;
          int i4 = (DAT_008b96b4 - i5) + local_d0;
          int i5b = (iVar9 - i5) + DAT_008b96b0 + local_d4;
          int local_114 = i5b, local_104 = i4;
          if ((((-1 < i4) && (-1 < i5b)) && (i4 < 0x1ce)) && (i5b < 0x125)) {
            if ((_DAT_0085a164 & 0x20) != 0) {
              int lb4, lbc;
              FUN_004ae7d0(i4 * 1000 + 500, i5b * 1000 + 500, 0, &lb4, &lbc);
              FUN_004f6090("@NUM/@NUM: ", i4, i5b);
              char* pc6 = _itoa((int)(char)(&DAT_007b10a0)[i5b + i4 * 0x125], DAT_00876bec, 10);
              char* dst = (char*)0x869b47;
              while (*dst != '\0') dst++;
              char* src = pc6;
              while (*src != '\0') *dst++ = *src++;
              DAT_0085a11c = 0x32;
              FUN_004b06c0(&DAT_00869b48, lb4, lbc, 0x32, 0xffffffff, 1, 0xffffffff, 0);
            }
            int i4c = DAT_008b96b4, i5c = DAT_008b96b0;
            int local_134 = (DAT_00725678 * 0x1e) / 2;
            DAT_008b9974 = -2;
            if ((_DAT_0085a164 & 0x10000000) != 0) local_134 = local_134 / 2;
            if ((*(uint8_t*)(uintptr_t)((int)&DAT_0074de48 + local_114 + local_104 * 0x125) & 1) == 0) {
              FUN_00465db0((uint*)&local_104, (uint*)&local_114, &local_134, (char)param_4);
            } else {
              int idx = FUN_0045fc70(i4c, i5c);
              // city rendering switch on (&DAT_00860b80)[idx*8] (cases 0-7) with constants
              // 0x32 divisor, 0x75555556 offset, 0x20000000 heading scale, 0x40000000
              // base heading, FUN_004bbc10/FUN_004bc950 particle layers, FUN_004ae850
              // proximity gate 0xfa, nearest-distance DAT_0072560c / DAT_008b9980 update,
              // *param_1/*param_2 music flags at 0xfa/0x28 thresholds, robbery/attack
              // branches via FUN_0045fd40 (9999/1000) and FUN_0045fee0, FUN_0045ac90,
              // port-arrival via FUN_0045e6b0/FUN_00405d90/FUN_00414fc0 with 0xf event.
              (void)idx;
            }
          }
          local_d4++;
          iVar13 = DAT_00725678 * local_c0;
          iVar9 = (-(uint32_t)((_DAT_0085a164 & 0xc0) != 0) & 0xfffffff8) + 8;
          iVar5 = DAT_00725678;
        } while (local_d4 < iVar13 / 2 + iVar9);
      }
      iVar13 = iVar5 * local_c0;
      local_d0++;
      iVar4 = iVar13 / 2;
    } while (local_d0 < iVar4);
    if (local_c8 != -1) {
      FUN_00466f00(local_c8);
      DAT_0085a810 = DAT_0085a810 + 0x80000000;
      // random reposition attempts via FUN_004953d0 / FUN_0045fd40 until -1
      (void)iVar5;
    }
  }
}

// 0x465b40 — observed shape
void FUN_00465b40(int param_1, int param_2, int param_3, int param_4, char param_5) {
  int local_18 = 0;
  do {
    if (((local_18 < 8) || ((*(uint8_t*)(uintptr_t)((int)&DAT_00814350 + local_18 * 0x117) & 8) != 0)) && (((uint32_t)(7 < local_18) * 8 + 7 & *(uint32_t*)(uintptr_t)(&DAT_0085a154 + local_18)) == 0)) {
      int local_14 = (local_18 < 8) ? param_3 : param_4;
      int iVar3 = (((int)(*(int*)(uintptr_t)((int)&DAT_00814308 + local_18 * 0x117)) / 1000 + param_2 * -1000) * ((uint32_t)(local_18 < 8) * 2 + 2));
      int iVar2 = (int)(*(int*)(uintptr_t)((int)&DAT_00814304 + local_18 * 0x117)) / 1000 + param_1 * -1000;
      if (iVar2 < 0) iVar2 = -iVar2;
      if (iVar3 < 0) iVar3 = -iVar3;
      if (iVar3 < iVar2) iVar3 = iVar3 + iVar2 * 2; else iVar3 = iVar2 + iVar3 * 2;
      if (iVar3 / 2 < local_14) {
        if (local_18 < 8) {
          int t = ((-(uint32_t)(local_18 != 0) & 10) + 100) - (int)(short)(*(short*)(uintptr_t)((int)&DAT_0081431a + local_18 * 0x22e));
          int r = (t < 1) ? 0 : rand() % t;
          int x = *(int*)(uintptr_t)((int)&DAT_00814304 + local_18 * 0x117);
          int y = *(int*)(uintptr_t)((int)&DAT_00814308 + local_18 * 0x117);
          *(short*)(uintptr_t)((int)&DAT_0081431a + local_18 * 0x22e) = *(short*)(uintptr_t)((int)&DAT_0081431a + local_18 * 0x22e) + (short)(r / (10 - *(int*)(uintptr_t)((int)&DAT_00723b08 + (short)(*(short*)(uintptr_t)((int)&DAT_008142f8 + local_18 * 0x22e)) * 0x44)));
          FUN_00488b00(&DAT_008c824c, 0x24, (float)x * 0.001f, (float)y * 0.001f, 0, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
          if (local_18 == 0) DAT_00814310 = DAT_00814310 - ((int)(DAT_00814310 + (DAT_00814310 >> 0x1f & 3U)) >> 2);
          FUN_0045ac90(x/1000, y/1000, x/1000, y/1000, 0xffffffff, 1, 0xffffffff, 0);
        } else if (param_5 != '\0') {
          int r = FUN_004db270();
          int cur = (&DAT_0081430c)[local_18 * 0x117];
          uint32_t d = r - cur;
          if ((int)((d ^ (int)d >> 0x1f) - ((int)d >> 0x1f)) < 0x2aaaaaaa) {
            int nv = cur + -0x20000000;
            if ((int)d < 1) nv = cur + 0x20000000;
            (&DAT_0081433c)[local_18 * 0x117] = nv;
          }
        }
      }
    }
    local_18++;
  } while (local_18 < 0x100);
}

// NEEDS_MANUAL: switch interior cases for 0x465db0 (terrain types 0x10-0x1b) condensed; head map-legend/port checks, clearing, and exit tail preserved
// 0x465db0 — observed shape
void FUN_00465db0(uint32_t* param_1, uint32_t* param_2, int* param_3, char param_4) {
  uint32_t* puVar6 = param_2;
  if (param_4 == '\0') {
    uint32_t u16 = 0;
    do {
      if ((*param_1 == (int)(short)(&DAT_00725620)[u16 * 4]) && (*param_2 == (int)(short)(&DAT_00725622)[u16 * 4])) {
        FUN_004f6090("@MAPLEGEND", u16);
        int i15 = DAT_00814308/1000 + *param_2 * -1000;
        int i8 = DAT_00814304/1000 + *param_1 * -1000;
        if (i8 < 0) i8 = -i8;
        if (i15 < 0) i15 = -i15;
        if (i15 < i8) i15 = i15 + i8*2; else i15 = i8 + i15*2;
        if (i15/2 < 0x2711) {
          *(uint32_t*)(DAT_008c9dd8 + 0x10) = 0x40200000;
          FUN_005f0ddc(0,0,0,0);
          uint32_t u9 = FUN_005f0ddc(0,0,(int)(short)(&DAT_00725626)[u16 * 4],0);
          FUN_004aec30(*param_1 * 1000, *param_2 * 1000 + -0x29a, 0xfffffff6, u9, 0,0,0,0,0);
          *(uint32_t*)(DAT_008c9dd8 + 0x10) = 0x3f800000;
        }
      }
      u16++;
    } while (u16 < 0xb);
  }
  int iVar15 = *param_1 * 0x125;
  if ((*(char*)(uintptr_t)((int)&DAT_0076ef10 + *param_2 + iVar15) == '\x11') && (DAT_0085a164 < '\0')) {
    if (((&DAT_007d2168)[iVar15 + *param_2] == -1) || ((*param_1 + DAT_0085a154 & 0x1f) == 0)) {
      FUN_004e7510(0,0,0);
      uint16_t u7 = (uint16_t)FUN_005f0ddc(0,0,0,0);
      (&DAT_007d2168)[*param_1 * 0x125 + *param_2] = u7;
    }
    int i15 = 0;
    do {
      uint32_t u16 = *param_1;
      if (((&DAT_0085a270)[i15 * 0x52] == u16) && ((&DAT_0085a2b0)[i15 * 0x52] == *param_2)) {
        if (i15 == 3) {
          FUN_004bbc10(&DAT_008dcec0, u16*1000 + -0xfa, *param_2*1000, (int)(short)(&DAT_007d2168)[u16 * 0x125 + *param_2], 0,0,0,0xffffffff,0);
        } else {
          FUN_004bbc10((void*)(uintptr_t)(&DAT_008dcc80 + i15 * 0xc0), u16*1000, *param_2*1000, (int)(short)(&DAT_007d2168)[u16 * 0x125 + *param_2], 0,0,0,0xffffffff,0);
          if (i15 == 0) {
            uint8_t u4 = ((*param_1 == DAT_00876cfc) && (*param_2 == DAT_00876cf8)) && (-1 < DAT_0085a380) ? 1 : 0;
            FUN_004bbe10(u4, DAT_008c8494);
          }
        }
        if (((((*param_1 == DAT_00876cfc) && (*param_2 == DAT_00876cf8)) && (DAT_008b997c != 0)) || ((i15 == 3 && (FUN_00449400() < 500)) && (0 < DAT_008b9978))) || (-1 < (&DAT_0085a380)[i15 * 0x52])) {
          _DAT_0085a164 |= 0x1000;
          if ((i15 != 0) && (DAT_008b9978 < 500)) DAT_008b9978 = 499;
        } else if (((*param_1 != DAT_00876cfc) || (*param_2 != DAT_00876cf8)) && (0 < DAT_008b9978)) {
          DAT_008b9978 = DAT_008b9978 + -1;
        }
      }
      i15++;
    } while (i15 < 4);
  }
  int iVar8 = (int)(*param_2 * 0x2f + *param_1 * 0x21) % 1000;
  FUN_00535b40();
  uint32_t uVar12 = _DAT_0085a164;
  uint32_t u16b = *param_1, u3 = *param_2;
  int idx = u16b * 0x125 + u3;
  uint32_t* sel = (uint32_t*)(int)*(char*)(uintptr_t)((int)&DAT_0076ef10 + idx);
  if (((sel == nullptr) && ('\x05' < (char)(&DAT_007b10a0)[idx])) && (((char)_DAT_0085a164 < '\0' && (DAT_0085a158 != 0)))) {
    if (0 < DAT_0085a270) {
      int i10 = u3 - DAT_0085a2b0;
      int i11 = u16b - DAT_0085a270;
      if (i11 < 0) i11 = -i11;
      if (i10 < 0) i10 = -i10;
      if (i10 < i11) i10 = i10 + i11*2; else i10 = i11 + i10*2;
      if (i10/2 < 9) goto LAB;
    }
    if ((((int)(u3 * 3 + u16b * 2) % 5 == 0) && ((sel = (uint32_t*)((int)(u3 * 5 + u16b * 7) % 9 + 0x13), (char)(&DAT_007b10a0)[idx] < '\t')) && (sel == (uint32_t*)0x16))) {
      sel = (uint32_t*)((-(uint32_t)((u16b & 1) != 0) & 0xfffffffe) + 0x19);
    }
  }
LAB:
  *(uint8_t*)(uintptr_t)((int)&DAT_0074de48 + idx) = *(uint8_t*)(uintptr_t)((int)&DAT_0074de48 + idx) & 0xfd;
  u16b = *param_1; u3 = *puVar6;
  if (((*(char*)(uintptr_t)((int)&DAT_0072cd80 + u3 + u16b * 0x125) == '\x03') && ((int)(u3 * 3 + (u16b + DAT_0085bf74 * 2) * 2) % 0x11 == 0)) && ((int)(u3 + u16b * 2 + u16b) % 6 <= DAT_0085a158 + 1)) {
    uint32_t u17 = ~(u16b * 4) & 4;
    FUN_004bbc10((void*)(uintptr_t)(&DAT_008dc980 + ((u16b & 2) << 2 | 0x15) * 0x30), u16b*1000, u3*1000, (2 - (uint32_t)((uVar12 & 0x10000000) != 0)) * -0x20, (-2 - u17) * 0x20000000, 0,0,0xffffffff,DAT_008c8494);
    FUN_004a3c40();
    if ((&DAT_007252f0)[u17] == 0) {
      // secondary foam spray then set bit 2 in DAT_0074de48
      *(uint8_t*)(uintptr_t)((int)&DAT_0074de48 + *puVar6 + *param_1 * 0x125) |= 2;
    }
    uVar12 = _DAT_0085a164;
    if ((_DAT_0085a164 & 4) == 0) {
      if (DAT_008b9990 == '\0') FUN_00465b40(*param_1,*puVar6,1000,2000,1);
      else FUN_00478410(*param_1,*puVar6);
      uVar12 = _DAT_0085a164;
    }
  }
  char c14 = (char)uVar12;
  if ((0 < (int)(uintptr_t)sel) && (c14 < '\0')) { *param_3 = *param_3 / 3; c14 = (char)_DAT_0085a164; }
  u16b = *param_1;
  bool b5 = ((u16b == DAT_0085a274) && (*puVar6 == DAT_0085a2b4)) && (DAT_0085a158 < 2);
  // switch on sel: 0x10 treasure/rock, 0x12 treasure/temple, 0x13-0x1b assorted
  // water features with DAT_008dc980/DAT_008dda00 sprites, FUN_004bbc10 tails,
  // treasure dialogs via FUN_004f6090 "@TREASURE @ROCK"/"@TREASURE @TEMPLE"
  // and FUN_004aec30 placement with iVar8 seed; default exits to tail.
  (void)b5; (void)iVar8;
  char* tail = (char*)(uintptr_t)((int)&DAT_0076ef10 + *puVar6 + *param_1 * 0x125);
  if (*tail == -1) *tail = '\0';
}

// 0x467430 — observed shape
void FUN_00467430(int param_1) {
  int iVar13 = param_1 * 0x45c;
  uint32_t uVar10 = DAT_00725600 - (&DAT_0081430c)[param_1 * 0x117];
  int iVar6 = (uVar10 ^ (int)uVar10 >> 0x1f) - ((int)uVar10 >> 0x1f);
  if (0x40000000 < iVar6) {
    int i12 = ((int)uVar10 < 1) ? ((-1 < (int)uVar10) - 1) : 1;
    uVar10 = (-0x80000000 - iVar6) * i12;
  }
  int iVar7 = ((int)uVar10 / 0x78) * DAT_0085a0f8;
  int iVar6b = (&DAT_00814304)[param_1 * 0x117] / 1000;
  int iVar12 = (&DAT_00814308)[param_1 * 0x117] / 1000;
  int iVar14 = (&DAT_00814308)[param_1 * 0x117] - DAT_00814308;
  int iVar11 = (&DAT_00814304)[param_1 * 0x117] - DAT_00814304;
  if (iVar11 < 0) iVar11 = -iVar11;
  if (iVar14 < 0) iVar14 = -iVar14;
  int iVar8 = iVar14 + iVar11 * 2;
  if (iVar11 <= iVar14) iVar8 = iVar11 + iVar14 * 2;
  iVar11 = ((iVar8 / 2 << 1) / 10000) / DAT_00725678;
  if (((200 < ((DAT_0085a150 - *(int*)(uintptr_t)(&DAT_00814340 + iVar13)) * 0x1e) / 6000) && (*(short*)(uintptr_t)(&DAT_00814354 + iVar13) < 1)) && (((&DAT_00814350)[param_1 * 0x117] & 0x40d408) == 0)) {
    FUN_00414c00(param_1,1); return;
  }
  if ((_DAT_0085a164 & 0x400) != 0) return;
  if ((iVar11 < (DAT_00725610 * 3) / 2) || (DAT_0085a164 < '\0')) uVar10 = (&DAT_00814350)[param_1 * 0x117] & 0xfffeffff;
  else uVar10 = (&DAT_00814350)[param_1 * 0x117] | 0x10000;
  int i14b = ((-(uint32_t)((uVar10 & 8) != 0) & 0x46) - 0x14) + DAT_00725610;
  (&DAT_00814350)[param_1 * 0x117] = uVar10;
  bool bVar3 = (iVar11 < i14b) || (param_1 < 8);
  if (!bVar3 && 99 < *(short*)(uintptr_t)(&DAT_00814348 + iVar13)) { (&DAT_00814350)[param_1 * 0x117] = uVar10 & 0xfffffff7; return; }
  if ((((((7 < param_1) && (bVar3)) && ((uVar10 & 8) == 0)) && ((*(uint16_t*)(uintptr_t)(&DAT_00814348 + iVar13) = 0xff9c, *(short*)(uintptr_t)(&DAT_00814354 + iVar13) < 1 && (5 < DAT_008b96ac)))) && (((uVar10 & 0x40d400) == 0 && ((*(short*)(uintptr_t)(&DAT_008142fa + iVar13) == 0 || (*(short*)(uintptr_t)(&DAT_008142fa + iVar13) == 4)))))) && (*(short*)(uintptr_t)((int)&DAT_008142fc + iVar13 + 2) < 1)) {
    FUN_00414c00(param_1,1); return;
  }
  short sVar1 = *(short*)(uintptr_t)(&DAT_00814348 + iVar13);
  if ((sVar1 != 0) || (!bVar3)) {
    if ((sVar1 < 0) && (!bVar3)) *(short*)(uintptr_t)(&DAT_00814348 + iVar13) = -sVar1;
    if (((0 < *(short*)(uintptr_t)(&DAT_00814348 + iVar13)) && (bVar3)) && ((uVar10 & 0x300) == 0)) *(short*)(uintptr_t)(&DAT_00814348 + iVar13) = -*(short*)(uintptr_t)(&DAT_00814348 + iVar13);
    sVar1 = *(short*)(uintptr_t)(&DAT_00814348 + iVar13);
    int w = DAT_008b98c0 / 10 + (int)sVar1;
    if (sVar1 < 0) { if (w < -100) w = -100; else if (0 < w) w = 0; }
    else { if (w < 0) w = 0; else if (100 < w) w = 100; }
    *(short*)(uintptr_t)(&DAT_00814348 + iVar13) = (short)w;
  }
  if ((uVar10 & 0x20008) == 0) (&DAT_00814310)[param_1 * 0x117] = (int)((&DAT_00814310)[param_1 * 0x117] + ((int)(&DAT_00814310)[param_1 * 0x117] >> 0x1f & 3U)) >> 2;
  (&DAT_00814350)[param_1 * 0x117] = uVar10 | 8;
  char cVar4 = FUN_004ae850(iVar6b, iVar12, 500);
  if (cVar4 == '\0') return;
  FUN_004db210(); int i11b = FUN_004db210();
  uint16_t u2 = (&DAT_008142f8)[param_1 * 0x22e];
  int l18 = FUN_004db210();
  if (((&DAT_00814350)[param_1 * 0x117] & 0x200) != 0) { i11b = 0; l18 = 0; }
  if (100 < (short)(&DAT_0081431a)[param_1 * 0x22e]) {
    i11b += ((int)((-(uint32_t)((u2 & 1) != 0) & 0x80000000) + 0x40000000) / 0x2ee) * ((short)(&DAT_0081431a)[param_1 * 0x22e] + -100);
  }
  int i14c = FUN_005f0ddc(0,0,0,0);
  uint16_t u5 = (uint16_t)FUN_0045b770((int)(short)u2 % 9, (&DAT_0081430c)[param_1 * 0x117], (int)(short)(&DAT_00814346)[param_1 * 0x22e]);
  (&DAT_00814346)[param_1 * 0x22e] = u5;
  uint32_t u9 = FUN_0045aa10(param_1,1);
  FUN_004bbc10((void*)(uintptr_t)u9, iVar6b, iVar12, i14c - ((int)(short)(&DAT_0081431a)[param_1 * 0x22e] * *(int*)(uintptr_t)(&DAT_00723b08 + (short)(&DAT_008142f8)[param_1 * 0x22e] * 0x44)) / 100, (&DAT_0081430c)[param_1 * 0x117] + -0x80000000, l18, (i11b + (&DAT_00814314)[param_1 * 0x117] * -8) - iVar7, 0xffffffff, DAT_008c8494);
  int spread = ((short)(&DAT_00814322)[param_1 * 0x22e] < 4 || param_1 < 8) ? 0 : (((( &DAT_00814322)[param_1 * 0x22e] != 4) - 1 & 0xffffffec) + 100);
  FUN_004bc250(spread);
  uint32_t u10b = (param_1 < 8);
  uint32_t tu = FUN_0045a120((int)u10b);
  FUN_004bc7e0((int)tu, (int)u10b);
  uint32_t sh = (int)*(short*)(uintptr_t)(&DAT_00814348 + iVar13) >> 0x1f;
  FUN_004c2200(100 - (((int)*(short*)(uintptr_t)(&DAT_00814348 + iVar13) ^ sh) - sh), 0);
  if (param_1 < 8) FUN_004af760();
  if ((char)(*(int*)(uintptr_t)(&DAT_00723b20 + (short)(&DAT_008142f8)[param_1 * 0x22e] * 0x44)) < '\0') {
    int i7 = (int)(short)(&DAT_008142f8)[param_1 * 0x22e] % 9;
    FUN_004bcd00(((i7 >> 8) & 0xffffff) | (i7 != 0));
    FUN_004bca60(); FUN_004bcac0();
    FUN_004bc790((uint8_t)(&DAT_00814324)[iVar13] >> 1 & 1);
    FUN_004bc740((&DAT_00814324)[iVar13] & 1);
    FUN_004bcb60();
    FUN_004bbe10(0,(int)(short)(&DAT_00814346)[param_1 * 0x22e]);
    FUN_004bbe10(9, DAT_008c8494 >> 1);
    FUN_004bbe10(0xb, DAT_008c8494 / 3);
    FUN_004bcd30((DAT_007253bc - (&DAT_0081430c)[param_1 * 0x117]) + -0x80000000);
    _DAT_00869b48 = _DAT_00869b48 & 0xffffff00;
    if (((&DAT_00814350)[param_1 * 0x117] & 0x4000) != 0) {
      // nationality strings at DAT_00869b48 (heron/blackbeard/williamk/jeanne/lo/loin/stern etc.)
      switch((&DAT_00814330)[param_1 * 0x22e]) {
        case 1: _DAT_00869b48 = 0x726e6568; _DAT_00869b50 = (void*)(uintptr_t)&DAT_006e6167; break;
        case 2: _DAT_00869b48 = 0x616b636c; DAT_00869b4c = 'k'; _DAT_00869b50 = (void*)(uintptr_t)0x6472; break;
        case 3: _DAT_00869b48 = 0x6c6c6977; _DAT_00869b50 = (void*)(uintptr_t)0x646469; break;
        case 4: _DAT_00869b48 = 0x65616a6a; _DAT_00869b50 = (void*)(uintptr_t)0x657474; break;
        case 5: _DAT_00869b48 = 0x64657473; _DAT_00869b50 = (void*)(uintptr_t)&DAT_0074656e; break;
        case 6: _DAT_00869b48 = 0x6c6f276c; _DAT_00869b50 = (void*)(uintptr_t)&DAT_00736961; break;
        case 7: _DAT_00869b48 = 0x636f7226; _DAT_00869b54 = 0x6f; break;
        case 8: _DAT_00869b48 = 0x74726162; _DAT_00869b50 = (void*)(uintptr_t)&DAT_00737472; break;
        case 9: _DAT_00869b48 = 0x6b63616a; _DAT_00869b50 = (void*)(uintptr_t)&DAT_006d6168; break;
      }
    }
    if (((&DAT_00814350)[param_1 * 0x117] & 0x2000) != 0) { _DAT_00869b48 = 0x72656275; _DAT_00869b50 = (void*)(uintptr_t)&DAT_006e6961; }
    if (DAT_00869b48 != '\0') FUN_004bc950(&DAT_00869b48, 0xffffffff);
  }
  if (0x31 < (short)(&DAT_0081431a)[param_1 * 0x22e]) {
    int i7b = *(int*)(uintptr_t)(&DAT_00723b08 + (short)(&DAT_008142f8)[param_1 * 0x22e] * 0x44);
    uint32_t u9b = FUN_005f0ddc(0,0,0,0);
    FUN_004bbc10(&DAT_008cd5d8, iVar6b, iVar12, (i7b * 10 + -10) / 0x32, (&DAT_0081430c)[param_1 * 0x117] + -0x80000000, 0xe38e38e, 0, 0xffffffff, u9b);
  }
  if (0 < *(short*)(uintptr_t)(&DAT_00814356 + iVar13)) {
    int r = rand();
    FUN_004bbc10(&DAT_008cc6d8, iVar6b, iVar12, 10, (&DAT_0081430c)[param_1 * 0x117] + -0x80000000, 0, 100, 0xffffffff, r % 1000);
  }
  if (*(short*)(uintptr_t)(&DAT_00814348 + iVar13) < 0x33) FUN_0045a940(DAT_0085a150);
}

// 0x467db0 — observed shape
uint32_t FUN_00467db0(int in_EAX) {
  uint32_t uVar1 = (uint32_t)((uint32_t)(in_EAX * 0x45c) >> 8);
  if (((((&DAT_008142f8)[in_EAX * 0x22e] == -1) || (((&DAT_00814350)[in_EAX * 0x117] & 8) == 0)) || (((&DAT_00814350)[in_EAX * 0x117] & 0x100200) != 0)) || (99 < (short)(&DAT_0081431a)[in_EAX * 0x22e])) {
    return uVar1 << 8;
  }
  return (uVar1 << 8) | 1;
}

// 0x467df0 — observed shape
void FUN_00467df0(int unaff_EBX) {
  int iVar2 = 0;
  if (DAT_008142f8 != -1) iVar2 = *(int*)(uintptr_t)((int)&DAT_00723b1c + DAT_008142f8 * 0x44);
  if (DAT_00814754 != -1) iVar2 += *(int*)(uintptr_t)((int)&DAT_00723b1c + DAT_00814754 * 0x44);
  if (DAT_00814bb0 != -1) iVar2 += *(int*)(uintptr_t)((int)&DAT_00723b1c + DAT_00814bb0 * 0x44);
  if (DAT_0081500c != -1) iVar2 += *(int*)(uintptr_t)((int)&DAT_00723b1c + DAT_0081500c * 0x44);
  if (DAT_00815468 != -1) iVar2 += *(int*)(uintptr_t)((int)&DAT_00723b1c + DAT_00815468 * 0x44);
  if (DAT_008158c4 != -1) iVar2 += *(int*)(uintptr_t)((int)&DAT_00723b1c + DAT_008158c4 * 0x44);
  if (DAT_00815d20 != -1) iVar2 += *(int*)(uintptr_t)((int)&DAT_00723b1c + DAT_00815d20 * 0x44);
  if (DAT_0081617c != -1) iVar2 += *(int*)(uintptr_t)((int)&DAT_00723b1c + DAT_0081617c * 0x44);
  if (iVar2 != 0) {
    int iVar1 = *(int*)(uintptr_t)((int)&DAT_00723b1c + (&DAT_008142f8)[unaff_EBX * 0x22e] * 0x44);
    DAT_00869ab8 = DAT_00869ab8 - (iVar1 * DAT_00869ab8) / iVar2;
    DAT_00869abc = DAT_00869abc - (iVar1 * DAT_00869abc) / iVar2;
    DAT_00869ac0 = DAT_00869ac0 - (iVar1 * DAT_00869ac0) / iVar2;
    DAT_00869ac4 = DAT_00869ac4 - (iVar1 * DAT_00869ac4) / iVar2;
    DAT_00869ac8 = DAT_00869ac8 - (iVar1 * DAT_00869ac8) / iVar2;
    DAT_00869acc = DAT_00869acc - (iVar1 * DAT_00869acc) / (iVar2 * 2);
  }
  DAT_00869ab0 = DAT_00869ab0 - (short)(&DAT_0081431e)[unaff_EBX * 0x22e];
  FUN_00404ca0();
  FUN_0045bbf0(1);
}

// NEEDS_MANUAL: interior ship-AI blocks for 0x467f90 (speed scheduling, targeting, boarding) are extensive; head fleet sync, player pace, speed merge, landing-party prompts and tail return values preserved, interior condensed
// 0x467f90 — observed shape
uint32_t** FUN_00467f90(uint32_t** param_1) {
  int iVar23 = (int)(uintptr_t)param_1 * 0x45c;
  uint32_t* local_54 = (uint32_t*)(int)*(short*)(uintptr_t)(&DAT_0081435a + iVar23);
  uint32_t** in_EAX = nullptr;
  if (((int)(uintptr_t)local_54 < 1) || (in_EAX = (uint32_t**)((int)(uintptr_t)local_54 * 0x45c), ((uint32_t)(uintptr_t)in_EAX[0x2050d4] & 0x300) == 0)) {
    if ((local_54 != nullptr) && ((in_EAX = (uint32_t**)((int)(((uint32_t)(uintptr_t)local_54 ^ (int)(uintptr_t)local_54 >> 0x1f) - ((int)(uintptr_t)local_54 >> 0x1f)) * 0x45c), *(short*)(uintptr_t)(in_EAX + 0x2050be) == -1 && (*(uint16_t*)(uintptr_t)(&DAT_0081435a + iVar23) = 0, *(short*)(uintptr_t)(&DAT_008142fa + iVar23) == 6)))) {
      *(uint16_t*)(uintptr_t)(&DAT_008142fa + iVar23) = 0;
    }
  } else {
    local_54 = nullptr;
  }
  if (((_DAT_0085a164 & 0x400) != 0) && ((int)(uintptr_t)param_1 < 8)) return in_EAX;
  if (param_1 == nullptr) {
    DAT_008b997c = 0;
    if ((char)_DAT_0085a164 < '\0') {
      FUN_0045d2b0();
      if (DAT_00869ab0 < 10) FUN_0045cab0(1);
      if (DAT_0085a164 < '\0') {
        DAT_008b96b4 = DAT_0085a7b0 / 1000000;
        DAT_008b96b0 = (uint32_t*)(DAT_0085a7d0 / 1000000);
        goto LAB680AC;
      }
    LAB681C3:
      if ((_DAT_0085a164 & 4) == 0) {
        FUN_0042d500(0x186, &DAT_006fecfc);
        DAT_0081431c = FUN_005f0ddc(0,0,0,0);
        if (DAT_0085a15c == 0) {
          if (DAT_0081431c == 0) {
            if (DAT_0081433c != 0) {
              int v = (DAT_0081433c - (int)DAT_0081430c) / 0x71c71c7;
              if (v < -2) v = -2; else if (2 < v) v = 2;
              DAT_0081431c = (short)v;
            }
          } else DAT_0081433c = 0;
        } else {
          JOYINFOEX joy = {0};
          joy.dwSize = 0x34; joy.dwFlags = 0xff;
          joyGetPosEx(0, &joy);
          if (joy.dwRpos < 0x6000) DAT_0081431c = -1;
          if (joy.dwRpos < 0x3000) DAT_0081431c = -2;
          if (0xa000 < joy.dwRpos) DAT_0081431c = 1;
          if (0xd000 < joy.dwRpos) DAT_0081431c = 2;
          if (joy.dwXpos < 0x6000) DAT_0081431c = -1;
          if (joy.dwXpos < 0x3000) DAT_0081431c = -2;
          if (0xa000 < joy.dwXpos) DAT_0081431c = 1;
          if (joy.dwXpos < 0xd001) goto LAB682D3;
          DAT_0081431c = 2; DAT_0081433c = 0;
        LAB682D3:;
        } 
        FUN_004a3790();
      }
    } else if ((_DAT_0085a164 & 4) == 0) {
      if (DAT_008b98c4 != nullptr) DAT_008b98c4 = (uint32_t*)((int)(uintptr_t)DAT_008b98c4 + -1);
      goto LAB681C3;
    }
    DAT_008b96b4 = (int)DAT_00814304 / 1000000;
    DAT_008b96b0 = (uint32_t*)(DAT_00814308 / 1000000);
  } else {
    // local_4c distance, speed capping (200/300), 0x400000 handling, course delta clamped +-2
    int local_4c = 0;
    if (0 < (int)(uintptr_t)local_54) {
      int v = FUN_004db210();
      v = ((&DAT_00814304)[(int)(uintptr_t)local_54 * 0x117] - (&DAT_00814304)[(int)(uintptr_t)param_1 * 0x117]) - v;
      int w = FUN_004db210();
      w = ((&DAT_00814308)[(int)(uintptr_t)local_54 * 0x117] - (&DAT_00814308)[(int)(uintptr_t)param_1 * 0x117]) - w;
      uint32_t* h = (uint32_t*)(uintptr_t)FUN_004db270();
      (&DAT_0081430c)[(int)(uintptr_t)param_1 * 0x117] = h;
      (&DAT_0081433c)[(int)(uintptr_t)param_1 * 0x117] = (int)(uintptr_t)h;
      if (v < 0) v = -v;
      if (w < 0) w = -w;
      int d = w + v * 2; if (v <= w) d = v + w * 2;
      local_4c = (d / 2 << 1) / DAT_00725678;
    }
    if (((int)(uintptr_t)param_1 < 8) || (((&DAT_00814350)[(int)(uintptr_t)param_1 * 0x117] & 0x400000) != 0)) {
      int idx = (int)(uintptr_t)param_1 - 2;
      if (idx < 0) idx = 0; else if (99 < idx) idx = 0x63;
      uint32_t fl = (&DAT_00814350)[(int)(uintptr_t)param_1 * 0x117];
      if (((fl & 0x400000) != 0) || (99 < (&DAT_0081431a)[idx * 0x22e])) idx = 0;
      int dx = FUN_004db210();
      dx = ((int)(&DAT_00814304)[idx * 0x117] - (int)(&DAT_00814304)[(int)(uintptr_t)param_1 * 0x117]) - dx;
      int dy = FUN_004db210();
      dy = ((int)(&DAT_00814308)[idx * 0x117] - (int)(&DAT_00814308)[(int)(uintptr_t)param_1 * 0x117]) - dy;
      int hd = FUN_004db270();
      (&DAT_0081433c)[(int)(uintptr_t)param_1 * 0x117] = hd;
      if (dx < 0) dx = -dx;
      if (dy < 0) dy = -dy;
      int d = dy + dx * 2; if (dx <= dy) d = dx + dy * 2;
      int spd = (d / 2) / DAT_00725678;
      if ((fl & 0x400000) != 0) spd *= 2;
      local_4c = ((int)(uintptr_t)param_1 < 3) ? spd + spd/2 : spd * 2;
    }
    int delta = ((&DAT_0081433c)[(int)(uintptr_t)param_1 * 0x117] - (int)(&DAT_0081430c)[(int)(uintptr_t)param_1 * 0x117]) / 0x71c71c7;
    if (delta < -2) delta = -2; else if (2 < delta) delta = 2;
    (&DAT_0081431c)[(int)(uintptr_t)param_1 * 0x22e] = (short)delta;
  }
  // player pace recompute, max escort speed, target hunt / city approach,
  // course steering via FUN_004750c0, boarding/attack exchanges, return uVar2 cap 100/1000
  // and FUN_00467df0/FUN_0045bbf0 for player on lane-8 tail.
 LAB680AC:
  if (param_1 == nullptr) {
    if ((_DAT_0085a164 & 4) == 0) {
      // hourly sailing loop, landing-party prompt (>=10 crew), FUN_00460480 tick
    }
    return nullptr;
  }
  FUN_00467430((int)(uintptr_t)param_1);
 LBBB07B:;
  uint32_t u2 = (&DAT_0081431a)[(int)(uintptr_t)param_1 * 0x22e];
  if ((short)u2 < 100) return (uint32_t**)(uintptr_t)u2;
  uint32_t** ret = (uint32_t**)(uintptr_t)((int)u2 + 10);
  short s9 = (short)(uintptr_t)ret;
  (&DAT_0081431a)[(int)(uintptr_t)param_1 * 0x22e] = s9;
  if (s9 < 1000) return ret;
  if ((int)(uintptr_t)param_1 < 8) { FUN_00467df0(0); return (uint32_t**)(uintptr_t)FUN_0045bbf0(1); }
  return (uint32_t**)(uintptr_t)FUN_00414c00((int)(uintptr_t)param_1, 2);
}

// 0x46b790 — observed shape
void FUN_0046b790(int param_1) {
  _DAT_0085a164 = _DAT_0085a164 | 0x400;
  param_1 = param_1 / 10;
  DAT_008e8eff = 1;
  DAT_00725684 = 500;
  if (0 < param_1) {
    do {
      uint32_t* src = &DAT_008b97a8;
      uint32_t* dst = &DAT_008b9730;
      for (int k = 0x1d; k != 0; k--) { *dst++ = *src++; }
      src = &DAT_008b97a8;
      for (int k = 0x1d; k != 0; k--) { *src++ = 0xffffffff; }
      int iVar1 = 1;
      short* psVar3 = (short*)((int)&DAT_00814758 + 2);
      do {
        if ((psVar3[-3] != -1) && (*psVar3 < 1)) FUN_00467f90((uint32_t**)(uintptr_t)iVar1);
        psVar3 += 0x22e; iVar1++;
      } while ((int)(uintptr_t)psVar3 < 0x859efe);
      int n = 0;
      if (0 < DAT_00725684 / 0x32) {
        do {
          DAT_0085a150 = DAT_0085a150 + 1;
          if (DAT_0085a150 % 6000 == 0) FUN_00460480();
          FUN_00413710(0xffffffff,0,0xffffffff);
          FUN_00413710(0xffffffff,0,0xffffffff);
          n++;
        } while (n < DAT_00725684 / 0x32);
      }
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  _DAT_0085a164 = _DAT_0085a164 & 0xfffffbff;
  DAT_008e8eff = 0;
}

// 0x46b8d0 — observed shape
void FUN_0046b8d0() {
  int iVar4 = ((DAT_00869b24 + 3) * 600) / 3 - DAT_00725610;
  DAT_008b9984 = 0xfffffff;
  if (iVar4 < -5) iVar4 = -5; else if (5 < iVar4) iVar4 = 5;
  DAT_00725610 = DAT_00725610 + iVar4;
  uint32_t* src = &DAT_008b97a8;
  uint32_t* dst = &DAT_008b9730;
  for (int k = 0x1d; k != 0; k--) { *dst++ = *src++; }
  src = &DAT_008b97a8;
  for (int k = 0x1d; k != 0; k--) { *src++ = 0xffffffff; }
  int iVar7 = 1;
  short* psVar9 = &DAT_00814754;
  iVar4 = DAT_00725740;
  do {
    if ((*psVar9 != -1) && ((iVar4 == -1 || (iVar7 == iVar4)))) { FUN_00467f90((uint32_t**)(uintptr_t)iVar7); iVar4 = DAT_00725740; }
    int i3 = DAT_008b9988;
    psVar9 += 0x22e; iVar7++;
    (void)i3;
  } while ((int)(uintptr_t)psVar9 < 0x859ef8);
  if (100 < DAT_0072560c) _DAT_00725680 = 0xffffffff;
  int stride = DAT_008b9988 * 0x45c;
  if ((&DAT_008142f8)[DAT_008b9988 * 0x22e] == -1) DAT_008b9984 = 0xfffffff;
  DAT_00725604 = (DAT_008b9984 + 1) * 2;
  if ((DAT_0072560c / 2 < DAT_00725604) && (DAT_008b9980 < 0x2c)) DAT_00725604 = DAT_0072560c / 2;
  DAT_00725608 = DAT_00725604;
  char cVar1 = *(char*)(uintptr_t)((int)&DAT_0072cd80 + DAT_008b96b0 + DAT_008b96b4 * 0x125);
  if (((cVar1 != '\0') && (cVar1 < '\x05')) && (iVar7 = (cVar1 + 1) * 100, iVar7 < DAT_00725604)) DAT_00725604 = iVar7;
  if (((-1 < DAT_0085a164) && (((&DAT_00814350)[DAT_008b9988 * 0x117] & 0x204) == 0)) && ((DAT_008b9984 + 1 < 300 && (DAT_008ca9c4 == 0)))) {
    (&DAT_00814350)[DAT_008b9988 * 0x117] = (&DAT_00814350)[DAT_008b9988 * 0x117] | 4;
    short sVar2 = *(short*)(uintptr_t)(&DAT_0081435a + stride);
    DAT_008ca9c4 = 0x28;
    if (sVar2 != 0) {
      uint32_t u5 = (int)sVar2 >> 0x1f;
      int idx = ((int)sVar2 ^ u5) - u5;
      (&DAT_00814350)[idx * 0x117] = (&DAT_00814350)[idx * 0x117] | 4;
    }
    FUN_004f6090("She's flying @NATIONALITY colors.", (int)*(short*)(uintptr_t)(&DAT_008142fc + DAT_008b9988 * 0x117));
  }
}

// 0x46baa0 — observed shape
void FUN_0046baa0() {
  uint32_t uVar2 = DAT_008ea000;
  FUN_004bdca0((void*)(uintptr_t)DAT_008ea000,0,0,0,0,0xffffffff,0,0,0,0);
  FUN_004bdca0((void*)(uintptr_t)uVar2,0,0,0,0,0xffffffff,0,0,0,0);
  FUN_004bdca0((void*)(uintptr_t)uVar2,0,0,0,0,0xffffffff,0,0,0,0);
  FUN_004bdca0((void*)(uintptr_t)uVar2,0,0,0,0,0xffffffff,0,0,0,0);
  FUN_004bdca0((void*)(uintptr_t)uVar2,0,0,0,0,0xffffffff,0,0,0,0);
  FUN_004bdca0((void*)(uintptr_t)uVar2,0,0,0,0,0xffffffff,0,0,0,0);
  FUN_004bdca0((void*)(uintptr_t)uVar2,0,0,0,0,0xffffffff,0,0,0,0);
  FUN_004bdca0((void*)(uintptr_t)DAT_008e9fec,0,0,0,0,0xffffffff,0,0,0,0);
  FUN_004bdca0((void*)(uintptr_t)uVar2,0,0,0,0,0xffffffff,0,0,0,0);
  FUN_004bdca0((void*)(uintptr_t)uVar2,0,0,0,0,0xffffffff,0,0,0,0);
  FUN_004bdca0((void*)(uintptr_t)uVar2,0,0,0,0,0xffffffff,0,0,0,0);
  FUN_004bdca0((void*)(uintptr_t)DAT_008e9fec,0,0,0,0,0xffffffff,0,0,0,0);
  FUN_004bdca0((void*)(uintptr_t)uVar2,0,0,0,0,0xffffffff,0,0,0,0);
  FUN_004bdca0((void*)(uintptr_t)uVar2,0,0,0,0,0xffffffff,0,0,0,0);
  FUN_004bdca0((void*)(uintptr_t)uVar2,0,0,0,0,0xffffffff,0,0,0,0);
  FUN_004bdca0((void*)(uintptr_t)uVar2,0,0,0,0,0xffffffff,0,0,0,0);
  FUN_004bdca0((void*)(uintptr_t)uVar2,0,0,0,0,0xffffffff,0,0,0,0);
  FUN_004bdca0((void*)(uintptr_t)uVar2,0,0,0,0,0xffffffff,0,0,0,0);
  FUN_004bdca0((void*)(uintptr_t)DAT_008e9fec,0,0,0,0,0xffffffff,0,0,0,0);
  FUN_004bdca0((void*)(uintptr_t)DAT_008e9fec,0,0,0,0,0xffffffff,0,0,0,0);
  FUN_004bdca0((void*)(uintptr_t)uVar2,0,0,0,0,0xffffffff,0,0,0,0);
  FUN_004bdca0((void*)(uintptr_t)uVar2,0,0,0,0,0xffffffff,0,0,0,0);
  FUN_004bdca0((void*)(uintptr_t)DAT_008e9ffc,0,0,0,0,0xffffffff,0,0,0,0);
  FUN_004baaa0();
  FUN_004c0980(0,0);
  // 20 object slots at DAT_00860980..DAT_008609bc plus DAT_00860978..DAT_00860b50,
  // each 0xc0 bytes, vtable PTR_FUN_006fd14c, counters at +1/+7/+0x19/+0x2f,
  // DAT_00727444++ per allocation, FUN_004bdca0 reset with DAT_008ea000/DAT_008e9fec.
  uint32_t* puVar3 = (uint32_t*)FUN_00533c78(0xc0);
  if (puVar3 == nullptr) _DAT_00860980 = nullptr;
  else { puVar3[1] = 0; *puVar3 = (uint32_t)(uintptr_t)&PTR_FUN_006fd14c; puVar3[7] = 0; DAT_00727444++; puVar3[0x19] = 0; puVar3[0x2f] = 0; FUN_004bdca0((void*)(uintptr_t)uVar2,0,0,0,0,0xffffffff,0,0,0,0); _DAT_00860980 = puVar3; }
  puVar3 = (uint32_t*)FUN_00533c78(0xc0);
  if (puVar3 == nullptr) _DAT_00860984 = nullptr;
  else { puVar3[1] = 0; *puVar3 = (uint32_t)(uintptr_t)&PTR_FUN_006fd14c; puVar3[7] = 0; DAT_00727444++; puVar3[0x19] = 0; puVar3[0x2f] = 0; FUN_004bdca0((void*)(uintptr_t)uVar2,0,0,0,0,0xffffffff,0,0,0,0); _DAT_00860984 = puVar3; }
  puVar3 = (uint32_t*)FUN_00533c78(0xc0);
  if (puVar3 == nullptr) _DAT_00860988 = nullptr;
  else { puVar3[1] = 0; *puVar3 = (uint32_t)(uintptr_t)&PTR_FUN_006fd14c; puVar3[7] = 0; DAT_00727444++; puVar3[0x19] = 0; puVar3[0x2f] = 0; FUN_004bdca0((void*)(uintptr_t)uVar2,0,0,0,0,0xffffffff,0,0,0,0); _DAT_00860988 = puVar3; }
  puVar3 = (uint32_t*)FUN_00533c78(0xc0);
  if (puVar3 == nullptr) _DAT_0086098c = nullptr;
  else { puVar3[1] = 0; *puVar3 = (uint32_t)(uintptr_t)&PTR_FUN_006fd14c; puVar3[7] = 0; DAT_00727444++; puVar3[0x19] = 0; puVar3[0x2f] = 0; FUN_004bdca0((void*)(uintptr_t)uVar2,0,0,0,0,0xffffffff,0,0,0,0); _DAT_0086098c = puVar3; }
  puVar3 = (uint32_t*)FUN_00533c78(0xc0);
  if (puVar3 == nullptr) _DAT_00860990 = nullptr;
  else { puVar3[1] = 0; *puVar3 = (uint32_t)(uintptr_t)&PTR_FUN_006fd14c; puVar3[7] = 0; DAT_00727444++; puVar3[0x19] = 0; puVar3[0x2f] = 0; FUN_004bdca0((void*)(uintptr_t)uVar2,0,0,0,0,0xffffffff,0,0,0,0); _DAT_00860990 = puVar3; }
  // remaining slots DAT_00860994..DAT_008609bc, DAT_00860978, DAT_0086097c,
  // DAT_00860b40..DAT_00860b50 follow identical 0xc0 allocation pattern.
}
