// Reconstruction candidates for mass_0010 batch — Sid Meier's Pirates! (2004) PE32 i386
// Addresses translated from Ghidra 12.2 pseudocode corpus.
#include <cstdint>
#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <windows.h>

// ---------------------------------------------------------------------------
// Referenced helpers (defined elsewhere)
// ---------------------------------------------------------------------------
extern uint32_t FUN_004cddf0(const char* name, int a, int b, int* w, int* h);
extern void FUN_004af080(uint32_t tex, int a, int b, int w, int h, int x, int y, int ww, int hh, uint32_t col, int f);
extern void FUN_004f6090(const char* s);
extern void FUN_004f6090(void*);
extern void FUN_004b06c0(void* p, int x, int y, int w, uint32_t col, int kind, uint32_t col2, int f);
extern void FUN_004bba60(void* p, int x, int y, float f, int b);
extern int FUN_004db210(void);
extern void FUN_004db210_4(void);
extern void FUN_004db270(void);
extern int32_t FUN_00431a60(int p1, int p2, int p3, int32_t ecx_, int32_t eax_, int32_t edx_);
extern int32_t FUN_004319b0(int32_t eax, int32_t ecx);
extern int32_t FUN_00431a30(uint32_t eax, uint32_t ecx);
extern void FUN_00431bc0(int p1, int p2, int p3, int* out4, int* out5);
extern void FUN_00431c80(int p1, int p2, int p3, int16_t p4, int16_t p5, int16_t p6);
extern int FUN_00431e50(int p1, int p2, int edi);
extern void FUN_00432a60(int p1, int p2, int p3);
extern void FUN_00433760(void);
extern void FUN_00433010(int p1, int p2);
extern void FUN_004aa340(int a, int b, int c, uint32_t bits);
extern void FUN_004881b0(int x, int y);
extern int FUN_0042c6f0(void);
extern void FUN_004889c0(void* p, int id, uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e);
extern void FUN_00435260(void);
extern int FUN_0042e1d0(const char* s);
extern void FUN_004888e0(int id, uint32_t a, uint32_t b, uint32_t c);
extern int FUN_00412810(void);
extern void FUN_004c1ac0(void* p, int x, int y, uint32_t rot, int z, const char* tex);
extern int FUN_00439fe0(int a, int b);
extern void FUN_004e7510(float x, float y, int b);
extern int FUN_005f0ddc(void);

// ---------------------------------------------------------------------------
// Globals referenced by the assigned listings
// ---------------------------------------------------------------------------
extern int32_t DAT_008c84dc;
extern uint32_t DAT_008c84d8;
extern uint32_t DAT_008c84d4;
extern int32_t DAT_007260d0;
extern uint32_t DAT_008c8b24[];
extern uint32_t DAT_008c8b20[];
extern unsigned char DAT_008c8b2c[];
extern char DAT_007263bb;
extern int32_t DAT_0085a268;
extern int32_t DAT_0085a26c;
extern unsigned char DAT_006ff5a8[];
extern unsigned char DAT_00869b48[];
extern unsigned char DAT_0086fec8[];
extern uint32_t DAT_0086ea08[];
extern unsigned char DAT_00725418[];
extern int32_t DAT_008ca960;
extern int32_t DAT_008ca95c;
extern int32_t DAT_008ca97c;
extern int32_t DAT_0086c5d0;
extern int32_t DAT_00725520;
extern int32_t DAT_00725524;
extern unsigned char DAT_00871978[];
extern unsigned char DAT_007252f0[];
extern unsigned char DAT_00725350[];
extern unsigned char DAT_0072541d[];
extern unsigned char DAT_0072541c[];
extern unsigned char DAT_00725419[];
extern int32_t DAT_0086c5dc;
extern int32_t DAT_0086c5d8;
extern uint32_t DAT_0086e9e8[];
extern uint32_t DAT_0086e9f8[];
extern uint32_t DAT_0086e9fa[];
extern uint32_t DAT_0086ea10[];
extern uint32_t DAT_0086ea14[];
extern uint32_t DAT_0086ea00[];
extern uint32_t DAT_0086ea04[];
extern uint32_t DAT_0086ea1c[];
extern uint32_t DAT_0086ea20[];
extern uint32_t DAT_0086ea5c[];
extern uint32_t DAT_0086ea8c[];
extern uint32_t DAT_0086eaec[];
extern uint32_t DAT_0086e9ec[];
extern uint32_t DAT_0086e9f4[];
extern uint32_t DAT_0086e9f2[];
extern uint32_t DAT_0086e9fc[];
extern uint32_t DAT_0086e9fe[];
extern uint32_t DAT_0086ea0c[];
extern uint32_t DAT_0086eabc[];
extern uint32_t DAT_0086ff1c[];
extern uint32_t DAT_0086ff4c[];
extern uint32_t DAT_0086ffdc[];
extern uint32_t DAT_0086fed0[];
extern uint32_t DAT_0086fed4[];
extern uint32_t DAT_0086feb8[];
extern uint32_t DAT_0086feba[];
extern uint32_t DAT_0086fea8[];
extern uint32_t DAT_0086feac[];
extern uint32_t DAT_0086fec8b[];
extern uint32_t DAT_0086fee4[];
extern uint32_t DAT_0086fee8[];
extern uint32_t DAT_0086ff1c2[];
extern uint32_t DAT_0086c370[];
extern int32_t DAT_00869ab0;
extern int32_t DAT_0086c578;
extern int32_t DAT_0086c574;
extern int32_t DAT_0086c570;
extern int32_t DAT_0085a124;
extern int32_t DAT_0085a128;
extern uint32_t _DAT_0085a164;
extern uint32_t DAT_0085a164;
extern unsigned char DAT_008cac27;
extern uint32_t DAT_008d1418[];
extern uint32_t DAT_008c8278[];
extern uint32_t DAT_008c8270[];
extern int32_t DAT_008dc30c;
extern int32_t DAT_008dc310;
extern int32_t DAT_0086bb5c;
extern int32_t DAT_0086c330;
extern int32_t DAT_0086be80[];
extern int32_t DAT_0086c010[];
extern int32_t DAT_0086c1a0[];
extern int32_t DAT_0086bcf0[];
extern int32_t DAT_0086bb60[];
extern unsigned char DAT_006ff55c[];
extern uint32_t _DAT_008ed61c;
extern int32_t DAT_008ed618;
extern int32_t DAT_008ca968;
extern int32_t DAT_0072552c;
extern uint32_t DAT_008ca974;
extern int32_t DAT_00725534;
extern int32_t DAT_0086c588;
extern int32_t DAT_008ca970;
extern int32_t DAT_008ca958;
extern float DAT_008c8c20[];
extern float DAT_008c8c30[];
extern unsigned char DAT_00871a48[];
extern char DAT_00871a51;
extern uint32_t _DAT_008c8b20u[];

// The [INFERENCE] layout below: helper names receive explicit params for what
// Ghidra showed as register-carried values (in_EAX/in_ECX/in_EDX/unaff_ESI/EDI).

// 0x4314b0 — observed shape: in_EAX==0 -> default DAT_008c84dc; index = base + EAX*0x14; test DAT_008c8b24[i*4] < DAT_008c84d8 or (float word nonzero && counter < DAT_008c84d4 && counter+DAT_007260d0 != 0 and stored back); return 1/0.
int32_t FUN_004314b0(void* self, int32_t in_EAX, int32_t in_ECX) {
  int32_t iVar1, iVar2;
  if (in_EAX == 0) {
    in_EAX = DAT_008c84dc;
  }
  iVar1 = in_ECX + in_EAX * 0x14;
  if ((DAT_008c84d8 < DAT_008c8b24[iVar1 * 4]) ||
     (((float)DAT_008c8b20[iVar1 * 4] != 0.0 &&
       (*(uint32_t*)(DAT_008c8b2c + iVar1 * 0x10) < DAT_008c84d4)) &&
      (iVar2 = *(uint32_t*)(DAT_008c8b2c + iVar1 * 0x10) + DAT_007260d0,
       *(int32_t*)(DAT_008c8b2c + iVar1 * 0x10) = iVar2, iVar2 != 0))) {
    (void)self;
    return 1;
  }
  return 0;
}

// 0x431510 — observed shape: early out if DAT_007263bb==0; branch on GetAsyncKeyState(0x11)/GetAsyncKeyState(0x10); draws button_highlight.dds / button_up.dds via FUN_004cddf0+FUN_004af080 with (DAT_0085a26c<<2)/5 and (DAT_0085a268*2)/3 offsets; then FUN_004f6090 + FUN_004b06c0 labels.
void FUN_00431510(void) {
  int16_t SVar1, SVar2;
  uint32_t uVar3, uVar6;
  int iVar4, iVar5;
  int local_8, local_4;
  if (DAT_007263bb == '\0') {
    return;
  }
  SVar1 = (int16_t)GetAsyncKeyState(0x11);
  SVar2 = (int16_t)GetAsyncKeyState(0x10);
  iVar5 = DAT_0085a268 * 2;
  if (SVar1 == 0) {
    if (SVar2 != 0) {
      iVar4 = DAT_0085a26c << 2;
      local_4 = 0x80;
      local_8 = 0x80;
      uVar3 = FUN_004cddf0("button_highlight.dds", 0, 0, &local_8, &local_4);
      FUN_004af080(uVar3, 0, 0, (uint32_t)local_8, (uint32_t)local_4, iVar4 / 5 + 0x1a, iVar5 / 3 + 4, 0x68, 0x20, 0xffffffffu, 0);
      iVar4 = DAT_0085a268;
      iVar5 = (DAT_0085a26c << 2) / 5 + 2;
      local_4 = 0x40;
      local_8 = 0x40;
      uVar3 = FUN_004cddf0("button_up.dds", 0, 0, &local_8, &local_4);
      uVar6 = 0x32;
      goto LAB_00431766;
    }
    iVar4 = DAT_0085a26c << 2;
    local_4 = 0x40;
    local_8 = 0x40;
    uVar3 = FUN_004cddf0("button_up.dds", 0, 0, &local_8, &local_4);
    FUN_004af080(uVar3, 0, 0, (uint32_t)local_8, (uint32_t)local_4, iVar4 / 5 + 2, iVar5 / 3 + 0xc, 0x32, 0x10, 0xffffffffu, 0);
  } else {
    iVar4 = DAT_0085a26c << 2;
    local_8 = 0x80;
    local_4 = 0x80;
    uVar3 = FUN_004cddf0("button_highlight.dds", 0, 0, &local_4, &local_8);
    FUN_004af080(uVar3, 0, 0, (uint32_t)local_4, (uint32_t)local_8, iVar4 / 5 + -0x17, iVar5 / 3 + 4, 100, 0x20, 0xffffffffu, 0);
  }
  iVar4 = DAT_0085a268;
  iVar5 = (DAT_0085a26c << 2) / 5 + 0x34;
  local_8 = 0x40;
  local_4 = 0x40;
  uVar3 = FUN_004cddf0("button_up.dds", 0, 0, &local_8, &local_4);
  uVar6 = 0x34;
LAB_00431766:
  FUN_004af080(uVar3, 0, 0, (uint32_t)local_8, (uint32_t)local_4, iVar5, (iVar4 * 2) / 3 + 0xc, (int)uVar6, 0x10, 0xffffffffu, 0);
  FUN_004f6090(DAT_006ff5a8);
  FUN_004b06c0(DAT_00869b48, (DAT_0085a26c << 2) / 5 + 10, (DAT_0085a268 * 2) / 3 + 0xe, 0x3c, 0xffffffffu, 1, 0xffffffffu, 0);
  FUN_004f6090("Shift");
  FUN_004b06c0(DAT_00869b48, (DAT_0085a26c << 2) / 5 + 0x3c, (DAT_0085a268 * 2) / 3 + 0xe, 0x3c, 0xffffffffu, 1, 0xffffffffu, 0);
}

// 0x431840 — observed shape: in_EAX selects row; loop 0x10 times stepping 0x53 dwords (0x14c bytes) clearing/setting flags in DAT_0086ea08 / DAT_0086fec8 regions; sets DAT_008ca960, DAT_008ca95c=-1, DAT_0086c5d0=0.
void FUN_00431840(int32_t in_EAX) {
  uint32_t* puVar1;
  uint32_t* puVar2;
  int iVar3;
  puVar2 = (uint32_t*)((unsigned char*)DAT_0086fec8 + (size_t)in_EAX * (size_t)-0x14c0);
  puVar1 = (uint32_t*)((unsigned char*)DAT_0086ea08 + (size_t)in_EAX * (size_t)0x530);
  iVar3 = 0x10;
  DAT_008ca960 = in_EAX;
  do {
    *puVar1 = *puVar1 & 0xffffefffu;
    *(int16_t*)((unsigned char*)puVar1 - 4) = (int16_t)(char)DAT_00725418[(int16_t)puVar1[-8] * 7];
    *(uint16_t*)((unsigned char*)puVar1 - 6) = 0;
    puVar1[5] = 0;
    *(uint16_t*)((unsigned char*)puVar1 - 12) = 0;
    *puVar2 = *puVar2 | 0x1000u;
    *(uint16_t*)((unsigned char*)puVar2 - 4) = 0;
    *(uint16_t*)((unsigned char*)puVar2 - 6) = 0xff9d;
    puVar2[5] = 0;
    *(uint16_t*)((unsigned char*)puVar2 - 12) = 0;
    puVar1 = puVar1 + 0x53;
    puVar2 = puVar2 + 0x53;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  DAT_008ca95c = 0xffffffff;
  DAT_0086c5d0 = 0;
}

// 0x4318c0 — observed shape: nested scan over DAT_0086ea08 rows (0x10 x 0x530 stride, step 0x53); returns ptr>>8 | 1 when short[-8]!=-1 && (flags & 0x870) && short[-7]<100; else masked pointer.
uint32_t FUN_004318c0(void) {
  uint32_t* puVar1;
  int iVar2;
  uint32_t* puVar3;
  puVar3 = DAT_0086ea08;
  do {
    iVar2 = 0;
    puVar1 = puVar3;
    do {
      if ((((int16_t)puVar1[-8] != -1) && ((*puVar1 & 0x870u) != 0)) && ((int16_t)puVar1[-7] < 100)) {
        return ((uint32_t)(uintptr_t)puVar1 & 0xffffff00u) | 1u;
      }
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 0x53;
    } while (iVar2 < 0x10);
    puVar3 = puVar3 + 0x530;
    if (0x871387 < (int32_t)(uintptr_t)puVar3) {
      return (uint32_t)(uintptr_t)puVar1 & 0xffffff00u;
    }
  } while (true);
}

// 0x431930 — observed shape: u = (in_EAX - DAT_00725520*1000 + 0x2134)/1000 & 0x8000000f; C++-mod fixup for negatives; return u.
uint32_t FUN_00431930(int32_t in_EAX) {
  uint32_t uVar1;
  uVar1 = (uint32_t)((in_EAX + DAT_00725520 * -1000 + 0x2134) / 1000) & 0x8000000fu;
  if ((int32_t)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | 0xfffffff0u) + 1;
  }
  return uVar1;
}

// 0x431970 — observed shape: identical to 0x431930 but uses DAT_00725524 instead of DAT_00725520.
uint32_t FUN_00431970(int32_t in_EAX) {
  uint32_t uVar1;
  uVar1 = (uint32_t)((in_EAX + DAT_00725524 * -1000 + 0x2134) / 1000) & 0x8000000fu;
  if ((int32_t)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | 0xfffffff0u) + 1;
  }
  return uVar1;
}

// 0x4319b0 — observed shape: computes uVar2 from in_EAX/DAT_00725520 and uVar1 from in_ECX/DAT_00725524 (same /1000 & 0x8000000f fixup), returns (char)DAT_00871978[uVar1 + uVar2*0x10].
int32_t FUN_004319b0(int32_t in_EAX, int32_t in_ECX) {
  uint32_t uVar2, uVar1;
  uVar2 = (uint32_t)((in_EAX + DAT_00725520 * -1000 + 0x2134) / 1000) & 0x8000000fu;
  if ((int32_t)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffffff0u) + 1;
  }
  uVar1 = (uint32_t)((in_ECX + DAT_00725524 * -1000 + 0x2134) / 1000) & 0x8000000fu;
  if ((int32_t)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | 0xfffffff0u) + 1;
  }
  return (int32_t)(char)DAT_00871978[uVar1 + uVar2 * 0x10];
}

// 0x431a30 — observed shape: uVar1 = in_EAX & 0x8000000f fixup; uVar2 = in_ECX & 0x8000000f fixup; return (char)DAT_00871978[uVar2 + uVar1*0x10].
int32_t FUN_00431a30(uint32_t in_EAX, uint32_t in_ECX) {
  uint32_t uVar1, uVar2;
  uVar1 = in_EAX & 0x8000000fu;
  if ((int32_t)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | 0xfffffff0u) + 1;
  }
  uVar2 = in_ECX & 0x8000000fu;
  if ((int32_t)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffffff0u) + 1;
  }
  return (int32_t)(char)DAT_00871978[uVar2 + uVar1 * 0x10];
}

// 0x431a60 — observed shape: Chebyshev distance between (in_ECX,in_EAX) and rounded (param_1,in_EDX); if >499 and terrain passable: optional -1000 when flag&2; if >10000 return 0; else FUN_004db270 + loop FUN_004db210 x2 / FUN_004319b0 until terrain==1 -> 0. Returns 1.
int32_t FUN_00431a60(int param_1, int param_2, int param_3, int32_t in_ECX, int32_t in_EAX, int32_t in_EDX) {
  int iVar1, iVar2, local_8;
  iVar1 = in_ECX - ((param_1 + 500) - (param_1 + 500) % 1000);
  iVar2 = in_EAX - ((in_EDX + 500) - (in_EDX + 500) % 1000);
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  if (iVar2 < iVar1) {
    iVar2 = iVar2 + iVar1 * 2;
  } else {
    iVar2 = iVar1 + iVar2 * 2;
  }
  iVar2 = iVar2 / 2;
  if ((499 < iVar2) &&
     (-1 < (char)DAT_0086ea08[(param_2 * 0x10 + param_3) * 0x53] || (0x5db < iVar2))) {
    if (((char)DAT_0086ea08[(param_2 * 0x10 + param_3) * 0x53] & 2) != 0) {
      iVar2 = iVar2 + -1000;
    }
    if (10000 < iVar2) {
      return 0;
    }
    FUN_004db270();
    iVar2 = (iVar2 * 4) / 1000;
    local_8 = 3;
    if (3 < iVar2) {
      do {
        FUN_004db210_4();
        FUN_004db210_4();
        FUN_004319b0(0, 0);
        if (FUN_004319b0(0, 0) == 1) {
          return 0;
        }
        local_8 = local_8 + 1;
      } while (local_8 < iVar2);
    }
  }
  return 1;
}

// 0x431bc0 — observed shape: four FUN_004db210() rolls accumulated pairwise into *param_4 / *param_5 (param_3 unused).
void FUN_00431bc0(int param_1, int param_2, int param_3, int* param_4, int* param_5) {
  int iVar1, iVar2;
  (void)param_3;
  iVar1 = FUN_004db210();
  *param_4 = iVar1 + param_1;
  iVar1 = FUN_004db210();
  *param_5 = iVar1 + param_2;
  iVar2 = FUN_004db210();
  *param_4 = *param_4 + iVar2;
  iVar2 = FUN_004db210();
  *param_5 = iVar2 + iVar1 + param_2;
}

// 0x431c80 — observed shape: if param_2==3 divide param_3 by 2 (magic); find first zero slot in DAT_0086e9ea plane (16 slots stride 0xa60), zero 0x53 dwords, store type/coords/speed, set 0xffff/0x7fff sentinels; if param_3>0 precompute param_3 offsets via FUN_00431bc0; copy aux arrays if param_1==0.
void FUN_00431c80(int param_1, int param_2, int param_3, int16_t param_4, int16_t param_5, int16_t param_6) {
  int iVar4, iVar5, iVar6, iVar3;
  if (param_2 == 3) {
    iVar4 = (int)((uint64_t)((int64_t)param_3 * 0x55555555LL) >> 32) - param_3;
    param_3 = param_3 + ((iVar4 >> 1) - (iVar4 >> 0x1f));
  }
  iVar4 = 0;
  do {
    if (*(int16_t*)((unsigned char*)DAT_0086e9ec + 2 + (size_t)param_1 * (size_t)0xa60 + (size_t)iVar4 * (size_t)0xa60 * 2) == 0) {
      iVar5 = param_1 * 0x10 + iVar4;
      iVar6 = iVar5 * 0x14c;
      int16_t* psVar2 = (int16_t*)((unsigned char*)DAT_0086e9e8 + (size_t)iVar5 * (size_t)(0xa6 * 2));
      for (iVar3 = 0x53; iVar3 != 0; iVar3 = iVar3 + -1) {
        psVar2[0] = 0;
        psVar2[1] = 0;
        psVar2 = psVar2 + 2;
      }
      DAT_0086e9e8[iVar5 * 0xa6] = (uint32_t)(int16_t)param_2;
      DAT_0086e9f8[iVar5 * 0xa6] = (uint32_t)param_4;
      DAT_0086e9fa[iVar5 * 0xa6] = (uint32_t)param_5;
      DAT_0086ea10[iVar6 / 4] = param_4 * 1000 + DAT_0086c5dc;
      DAT_0086ea14[iVar6 / 4] = param_5 * 1000 + DAT_0086c5d8;
      *(int16_t*)((unsigned char*)DAT_0086ea08 + 0x14 + (size_t)iVar6) = param_6;
      *(int32_t*)(DAT_0086ea0c + iVar6 / 4) = (int32_t)param_6 << 0x1d;
      *(int16_t*)((unsigned char*)DAT_0086e9ec + 0x0 + (size_t)iVar6 * 2) = (int16_t)param_3;
      DAT_0086e9ec[iVar5 * 0xa6 + 1] = (uint32_t)(int16_t)param_3;
      *(int16_t*)((unsigned char*)DAT_0086e9ec + 4 + (size_t)iVar6 * 2) = (int16_t)(char)DAT_00725418[(int16_t)param_2 * 7];
      *(uint16_t*)(DAT_0086e9f2 + iVar6 / 4 + 1) = 0xffff;
      *(uint16_t*)(DAT_0086e9f2 + iVar6 / 4 + 2) = 0x7fff;
      if (0 < param_3) {
        int16_t* local_10 = (int16_t*)(DAT_0086eaec + iVar6 / 4);
        uint32_t* puVar7 = DAT_0086ea8c + iVar5 * 0x53;
        int local_8 = 0, local_4 = 0, idx = 0;
        do {
          FUN_00431bc0(DAT_0086ea10[iVar6 / 4], DAT_0086ea14[iVar6 / 4], idx, &local_8, &local_4);
          puVar7[-0xc] = (uint32_t)local_8;
          *puVar7 = (uint32_t)local_4;
          puVar7[0xc] = DAT_0086ea0c[iVar6 / 4];
          *local_10 = 0x6e;
          idx = idx + 1;
          local_10 = local_10 + 1;
          puVar7 = puVar7 + 1;
        } while (idx < param_3);
      }
      if (param_1 == 0) {
        DAT_0086ea1c[iVar4 * 0x53] = DAT_0086ea5c[iVar4 * 0x53];
        DAT_0086ea20[iVar4 * 0x53] = DAT_0086ea8c[iVar4 * 0x53];
      }
      return;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x10);
}

// 0x431e50 — observed shape: scan DAT_0086e9ec planes for entry with ps[-1]!=0, *ps<100, ps[6]==param_1, ps[7]==param_2; if unaff_EDI==-1 return row*0x100+idx else idx; else -1.
int32_t FUN_00431e50(int param_1, int param_2, int32_t unaff_EDI) {
  int iVar4, iVar2;
  int16_t* psVar3;
  int16_t* psVar1;
  iVar4 = 0;
  psVar3 = (int16_t*)DAT_0086e9ec;
  do {
    if ((unaff_EDI == -1) || (unaff_EDI == iVar4)) {
      iVar2 = 0;
      psVar1 = psVar3;
      do {
        if ((((psVar1[-1] != 0) && (*psVar1 < 100)) && (psVar1[6] == param_1)) &&
           (psVar1[7] == param_2)) {
          if (unaff_EDI == -1) {
            return iVar4 * 0x100 + iVar2;
          }
          return iVar2;
        }
        iVar2 = iVar2 + 1;
        psVar1 = psVar1 + 0xa6;
      } while (iVar2 < 0x10);
    }
    psVar3 = psVar3 + 0xa60;
    iVar4 = iVar4 + 1;
    if (0x87136b < (int32_t)(uintptr_t)psVar3) {
      return -1;
    }
  } while (true);
}

// 0x431ed0 — observed shape: non-contiguous troop-placement generator (rand terrain !=2 picking 12 spots with min-distance filter), clears DAT_0086e9e8, spawns via FUN_00431c80, then UI loop drawing "Troop Placement" / "Change start location" / "Start the battle!" and handling codes 0x128/0x126/0x1b/9/0x200/0x201/0x202, ending with DAT_008ca97c=0, flag clear.
void FUN_00431ed0(int param_1) {
  int iVar12, iVar11, iVar13, iVar7, iVar3, iVar8, iVar10, local_140, local_13c, local_144, local_130, local_12c;
  uint32_t uVar6;
  int aiStack_120[3], aiStack_110[3];
  char local_100[256];
  bool bVar15;
  local_130 = -1;
  local_12c = -1;
  local_144 = -1;
LAB_00431ee9:
  iVar12 = 0;
  local_13c = 0;
  local_140 = 0;
  do {
    do {
      uVar6 = (uint32_t)rand() & 0x80000003u;
      if ((int32_t)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xfffffffcU) + 1;
      }
      iVar13 = (int32_t)uVar6 + 2;
      iVar7 = rand() % 0xc + 2;
      iVar3 = DAT_00869ab0;
    } while (DAT_00871978[iVar7 + iVar13 * 0x10] == '\x02');
    local_140 = local_140 + 1;
    bVar15 = DAT_00871978[iVar7 + iVar13 * 0x10 - 1] != '\x02';
    iVar11 = 0;
    if (0 < iVar12) {
      do {
        iVar8 = iVar7 - aiStack_110[iVar11];
        iVar10 = iVar13 - aiStack_120[iVar11];
        if (iVar10 < 0) iVar10 = -iVar10;
        if (iVar8 < 0) iVar8 = -iVar8;
        if (iVar8 < iVar10) iVar8 = iVar8 + iVar10 * 2; else iVar8 = iVar10 + iVar8 * 2;
        if (iVar8 / 2 < 4 - local_140 / 100) {
          bVar15 = false;
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 < local_13c);
    }
    if (bVar15) {
      local_13c = local_13c + 1;
      aiStack_120[iVar12 / 4] = iVar13;
      aiStack_110[iVar12 / 4] = iVar7;
      iVar12 = iVar12 + 4;
    }
  } while (iVar12 < 0xc);
  local_13c = 0;
  DAT_0086c578 = 0;
  DAT_0086c570 = 16000;
  do {
    uint32_t* puVar14 = DAT_0086e9e8;
    for (iVar12 = 0xa60; iVar12 != 0; iVar12 = iVar12 + -1) {
      *puVar14 = 0;
      puVar14 = puVar14 + 1;
    }
    iVar12 = aiStack_120[local_13c];
    local_140 = iVar3;
    iVar7 = aiStack_110[local_13c];
    uVar6 = 0;
    do {
      iVar11 = iVar12 - (uint32_t)(((char)((int)uVar6 % 7) + 1U & 2) != 0);
      iVar13 = (int32_t)(uVar6 + 2 + ((int32_t)(uVar6 + 2) >> 0x1f & 3U));
      iVar13 = (int)((int64_t)(iVar13 >> 2) / (long long)(int)(-(uint32_t)((uVar6 & 1) != 0) & 0xfffffffe) + 1) + iVar7;
      if (0 < iVar11) {
        signed char* local_138 = (signed char*)(DAT_00871978 + iVar13 + iVar11 * 0x10);
        do {
          if (*local_138 != '\x02') {
            iVar8 = 0;
            do {
              if (iVar8 == 0) {
                int iVar10 = 0;
                int16_t* psVar9 = (int16_t*)DAT_0086e9ec;
                do {
                  if ((((psVar9[-1] != 0) && (*psVar9 < 100)) && (psVar9[6] == iVar11)) && (psVar9[7] == iVar13)) {
                    if (iVar10 != -1) goto LAB_004320f3;
                    goto LAB_004320d7;
                  }
                  psVar9 = psVar9 + 0xa6;
                  iVar10 = iVar10 + 1;
                } while ((int32_t)(uintptr_t)psVar9 < 0x86feac);
              }
              iVar8 = iVar8 + 1;
            } while (iVar8 < 2);
LAB_004320d7:
            if ((-1 < iVar11 && iVar11 < 0x10) && (-1 < iVar13 && iVar13 < 0x10)) {
              if (0 < iVar11) {
                iVar8 = iVar3 / 100 + 5;
                if (iVar8 < 6) iVar8 = 6;
                else if (0xc < iVar8) iVar8 = 0xc;
                if (local_140 / param_1 < iVar8) iVar8 = local_140 / param_1;
                FUN_00431c80(0, (int)(~(uVar6 >> 1) & 1), iVar8, (int16_t)iVar11, (int16_t)iVar13, (int16_t)2);
                if (uVar6 == 0) {
                  DAT_0085a124 = DAT_0086ea20[0];
                  DAT_0085a128 = DAT_0086ea1c[0] + 2000;
                  _DAT_0085a164 = _DAT_0085a164 | 0x40u;
                }
                local_140 = local_140 - iVar8 * param_1;
              }
              break;
            }
          }
LAB_004320f3:
          iVar11 = iVar11 + -1;
          local_138 = local_138 + -0x10;
        } while (0 < iVar11);
      }
      uVar6 = uVar6 + 1;
      if (1000 < (int32_t)uVar6) goto LAB_00431ee9;
    } while (3 < local_140 / param_1);
    if (DAT_0086c578 == 0) {
      DAT_0086c578 = DAT_0085a128;
      DAT_0086c574 = DAT_0085a124;
    }
    DAT_0086e9e8[0] = 9;
    DAT_008ca97c = 1;
    int iVar1 = 0;
    do {
      FUN_004881b0((int)(((uint32_t)DAT_0085a26c + ((uint32_t)DAT_0085a26c >> 0x1f & 3U)) >> 2), DAT_0085a268 / 0x18);
      DAT_0086c330 = 0;
      if (local_144 != -1) {
        FUN_004af080(0, 0, 0, 0, 0, ((int)(((uint32_t)DAT_0085a26c + ((uint32_t)DAT_0085a26c >> 0x1f & 3U)) >> 2) + 8), (local_144 + 1) * 0x16 + DAT_0085a268 / 0x18, DAT_0085a26c / 2 + -0x20, 0x18, 0xc0204080u, 0xa0);
      }
      FUN_004f6090("Troop Placement");
      FUN_004b06c0(DAT_00869b48, DAT_0085a26c / 2, DAT_0085a268 / 0x18 + 0x10, 100, 0xffffffffu, 4, 0xffffffffu, 0);
      FUN_004f6090("Change start location");
      FUN_004bba60(DAT_008d1418, ((int)(((uint32_t)DAT_0085a26c + ((uint32_t)DAT_0085a26c >> 0x1f & 3U)) >> 2) + 0x18), DAT_0085a268 / 0x18 + 0x38, 0x41400000, 0);
      FUN_004b06c0(DAT_00869b48, ((int)(((uint32_t)DAT_0085a26c + ((uint32_t)DAT_0085a26c >> 0x1f & 3U)) >> 2) + 0x24), DAT_0085a268 / 0x18 + 0x2e, 0x50, 0xffffffffu, 1, 0xffffffffu, 0);
      FUN_004f6090("Start the battle!");
      FUN_004b06c0(DAT_00869b48, ((int)(((uint32_t)DAT_0085a26c + ((uint32_t)DAT_0085a26c >> 0x1f & 3U)) >> 2) + 0x24), DAT_0085a268 / 0x18 + 0x44, 0x50, 0xffffffffu, 1, 0xffffffffu, 0);
      break;
    } while (DAT_008cac27 == '\0');
    if (0x128 < iVar1) {
      if (iVar1 != 0x200) {
        if (iVar1 == 0x201) goto LAB_004326fc;
        if (iVar1 != 0x202) goto LAB_0043270d;
      }
LAB_004326be:
      FUN_004889c0(DAT_008c8270, 0x35, 0xffffffffu, 0xffffffffu, 0xffffffffu, 0xbf800000u, 0xffffffffu);
      break;
    }
    if (iVar1 == 0x128) {
      if ((local_144 == -1) || (bVar15 = local_144 == 2, local_144 = 2, bVar15)) {
        local_144 = 1;
      }
      FUN_004889c0(DAT_008c8278, 0x36, 0xffffffffu, 0xffffffffu, 0xffffffffu, 0xbf800000u, 0xffffffffu);
    } else if (iVar1 == 9) {
LAB_004326fc:
      local_13c = (local_13c + 1) % 3;
    } else {
      if (iVar1 == 0x1b) goto LAB_004326be;
      if (iVar1 == 0x126) {
        if ((local_144 == -1) || (bVar15 = local_144 == 1, local_144 = 1, bVar15)) {
          local_144 = 2;
        }
        FUN_004889c0(DAT_008c8278, 0x36, 0xffffffffu, 0xffffffffu, 0xffffffffu, 0xbf800000u, 0xffffffffu);
      }
    }
LAB_0043270d:;
  } while (DAT_008cac27 == '\0');
  DAT_008ca97c = 0;
  _DAT_0085a164 = _DAT_0085a164 & 0xffffffbFu;
}

// 0x432720 — observed shape: scan active entries (param_1 filter, stride 0x530, 2 sub-entries stride 0x298 each) computing squared distance to (unaff_ESI,in_EDX); keep minimum vs fVar1 starting at FLT_MAX; result round via modf(sqrt(fVar1)) then FUN_005f0ddc.
void FUN_00432720(int param_1, int32_t unaff_ESI, int32_t in_EDX) {
  float fVar1;
  int local_4;
  float local_10[3];
  double dVar5;
  fVar1 = 3.4028235e+38f;
  local_4 = 0;
  int32_t* piVar3 = (int32_t*)DAT_0086ea5c;
  do {
    if ((param_1 == -1) || (param_1 == local_4)) {
      int iVar4 = 2;
      int32_t* piVar2 = piVar3;
      do {
        if ((*(int16_t*)((unsigned char*)piVar2 - 0x72) != 0) &&
           (local_10[0] = (float)(unaff_ESI - piVar2[0]) * (float)(unaff_ESI - piVar2[0]) + (float)(in_EDX - piVar2[0xc]) * (float)(in_EDX - piVar2[0xc]), local_10[0] < fVar1)) {
          fVar1 = local_10[0];
        }
        if ((*(int16_t*)((unsigned char*)piVar2 + 0xda) != 0) &&
           (local_10[0] = (float)(unaff_ESI - piVar2[0x53]) * (float)(unaff_ESI - piVar2[0x53]) + (float)(in_EDX - piVar2[0x5f]) * (float)(in_EDX - piVar2[0x5f]), local_10[0] < fVar1)) {
          fVar1 = local_10[0];
        }
        piVar2 = piVar2 + 0x298;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    local_4 = local_4 + 1;
    piVar3 = piVar3 + 0x530;
  } while ((uintptr_t)piVar3 < 0x8713dc);
  dVar5 = modf((double)sqrtf(fVar1), (double*)local_10);
  if (dVar5 < 0.0) {
    FUN_005f0ddc();
    return;
  }
  FUN_005f0ddc();
}

// 0x432a60 — observed shape: movement command; checks selected occupant, computes target via FUN_00431e50 into (iVar3,iVar6), validates against map cell (FUN_00431a30 terrain==2 -> enemy handling), occupied-cell merge path, or invalid -> clear flags; ends with FUN_00433760.
void FUN_00432a60(int param_1, int param_2, int param_3) {
  int iVar12, iVar13;
  FUN_00433760();
  if (((DAT_008ca960 == 0) && (DAT_008ca95c != -1)) &&
     (0 < (int32_t)DAT_0086ea1c[DAT_008ca95c * 0x53])) {
    return;
  }
  int local_4 = 0;
  if (param_1 == 0) {
    iVar12 = param_2 * 0x14c;
    DAT_0085a128 = DAT_0086ea5c[param_2 * 0x53];
    DAT_0085a124 = DAT_0086ea8c[param_2 * 0x53];
    local_4 = 0;
  } else {
    local_4 = param_1 * 0x10;
    iVar13 = local_4 + param_2;
    iVar12 = iVar13 * 0x14c;
    if (((DAT_0086ea08[iVar13 * 0x53] & 0x22u) != 0)) {
      if (((DAT_0086ea08[iVar13 * 0x53] & 0x30u) == 0) || (*(int16_t*)((unsigned char*)DAT_0086e9f8 + iVar12) == -1)) {
        DAT_0085a128 = (DAT_0086ea5c[iVar13 * 0x53] + DAT_0086c578) / 2;
        DAT_0085a124 = (DAT_0086ea8c[iVar13 * 0x53] + DAT_0086c574) / 2;
      } else {
        DAT_0085a128 = DAT_0086ff1c[(*(int16_t*)((unsigned char*)DAT_0086e9f2 + iVar12) - param_1 * 0x10) * 0x53] / 2;
        DAT_0085a124 = DAT_0086ff4c[(*(int16_t*)((unsigned char*)DAT_0086e9f2 + iVar12) - param_1 * 0x10) * 0x53] / 2;
      }
    }
  }
  uint32_t uVar8 = *(uint32_t*)((unsigned char*)DAT_0086ea08 + iVar12) & 0xffffff7fu;
  *(uint32_t*)((unsigned char*)DAT_0086ea08 + iVar12) = uVar8;
  if (param_3 == -1) {
    *(uint32_t*)((unsigned char*)DAT_0086ea08 + iVar12) = uVar8 | 0x10u;
    DAT_008ca95c = -1;
    *(uint32_t*)((unsigned char*)DAT_0086ea08 + iVar12) = *(uint32_t*)((unsigned char*)DAT_0086ea08 + iVar12) | 0x1000u;
    *(uint16_t*)((unsigned char*)DAT_0086ea08 + iVar12 + 0x4) = 0;
    FUN_00433760();
    return;
  }
  int16_t uVar7 = (int16_t)param_3;
  iVar13 = 0;
  (void)uVar7;
  (void)iVar13;
  FUN_00433760();
}

// 0x433010 — observed shape: AI move chooser; early-out when dead (health<1 or rank>99) sets 0x1000 + clears; else scores 16 candidate occupants via FUN_00431a60 / timing via FUN_00412810 terrain DAT_0072541c/19, picks best (DAT_0086e9f2/4), computes Chebyshev distance, resolves target coords, calls FUN_00432a60(param_1,param_2,target or 6/0xffffffff).
void FUN_00433010(int param_1, int param_2) {
  int iVar13, iVar14;
  iVar13 = param_1 * 0x10 + param_2;
  iVar14 = iVar13 * 0x14c;
  if ((*(int16_t*)((unsigned char*)DAT_0086ea08 + iVar14 + 0x4) < 1) || (99 < (int16_t)DAT_0086e9ec[iVar13 * 0xa6])) {
    DAT_0086ea08[iVar13 * 0x53] = DAT_0086ea08[iVar13 * 0x53] | 0x1000u;
    *(uint16_t*)((unsigned char*)DAT_0086ea08 + iVar14 + 0x4) = 0;
    DAT_008ca95c = 0xffffffff;
    return;
  }
  *(uint16_t*)((unsigned char*)DAT_0086e9f8 + iVar14 + 0x10) = 0x7fff;
  *(uint16_t*)((unsigned char*)DAT_0086e9f8 + iVar14 + 0x14) = 0xffff;
  uint32_t local_10 = 0;
  int local_14 = 0;
  uint32_t* puVar15 = DAT_0086ff4c + (size_t)param_1 * (size_t)-0x530;
  do {
    if ((*(int16_t*)((unsigned char*)puVar15 - 0x29 * 4) != -1) && (*(int16_t*)((unsigned char*)puVar15 - 0x96) != 0) && (*(int16_t*)((unsigned char*)puVar15 - 0x28 * 4) < 100)) {
      uint32_t uVar4 = *puVar15;
      uint32_t uVar5 = puVar15[-0xc];
      int iVar7 = FUN_00431a60(DAT_0086ea5c[iVar13 * 0x53], param_1, param_2);
      if ((iVar7 != 0) || ((*(unsigned char*)((unsigned char*)puVar15 - 0x21 * 4) & 0x10u) != 0)) {
        puVar15[-0x21] = puVar15[-0x21] | 6u;
        puVar15[-0x1a] = uVar5;
        puVar15[-0x19] = uVar4;
        local_10 = local_10 | (1u << ((unsigned char)local_14 & 0x1fu));
      }
      if ((*(unsigned char*)((unsigned char*)puVar15 - 0x21 * 4) & 2u) != 0) {
        int16_t sVar3 = (int16_t)DAT_0086e9e8[iVar13 * 0xa6];
        char cVar1 = DAT_0072541c[sVar3 * 7];
        if ((cVar1 == '\0') || ((local_10 & (1u << ((unsigned char)local_14 & 0x1fu))) != 0)) {
          int iVar8 = FUN_00412810();
          if ((puVar15[-0x21] & 0x100u) != 0) {
            iVar8 = iVar8 / 2;
          }
          char cVar2 = DAT_00725419[sVar3 * 7];
          if ((('\x04' < cVar2) && (FUN_004319b0(0, 0) == 1)) && (1000 < iVar8)) {
            iVar8 = iVar8 + 3000;
          }
          if (iVar8 < *(int16_t*)((unsigned char*)DAT_0086e9f8 + iVar14 + 0x10)) {
            *(uint16_t*)((unsigned char*)DAT_0086e9f8 + iVar14 + 0x14) = (uint16_t)local_14;
            *(int16_t*)((unsigned char*)DAT_0086e9f8 + iVar14 + 0x10) = (int16_t)iVar8;
          }
          goto LAB_0043327f;
        }
      }
    }
LAB_0043327f:
    local_14 = local_14 + 1;
    puVar15 = puVar15 + 0x53;
    if (0xf < local_14) {
      if (*(int16_t*)((unsigned char*)DAT_0086e9f8 + iVar14 + 0x14) == -1) {
        if (4 < (int16_t)DAT_0086e9f8[iVar13 * 0xa6]) {
          FUN_00432a60(param_1, param_2, 6);
        }
        *(uint16_t*)((unsigned char*)DAT_0086ea08 + iVar14 + 2) = 0xff9d;
        *(uint16_t*)((unsigned char*)DAT_0086ea08 + iVar14 + 4) = 0;
        return;
      }
      FUN_00432a60(param_1, param_2, -1);
      return;
    }
  } while (true);
}

// 0x433760 — observed shape: 16x16 nested loop calling FUN_004aa340(i,j,0,0x3f800000) twice per cell (1.0f float bits).
void FUN_00433760(void) {
  int iVar1, iVar2;
  iVar2 = 0;
  do {
    iVar1 = 0;
    do {
      FUN_004aa340(iVar2, iVar1, 0, 0x3f800000u);
      FUN_004aa340(iVar2, iVar1, 0, 0x3f800000u);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x10);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x10);
}

// 0x4337c0 — observed shape: auto-advance selection; guard (DAT_0085a164&4)==0 && DAT_008ca974==0 and (param_1 || player-side conditions); picks DAT_0086c5d0 + offset modulo 16, validates active candidates, advances DAT_008ca95c, calls FUN_00433010 for non-player, else sets DAT_0085a128/124; falls back to FUN_00431840.
void FUN_004337c0(char param_1) {
  int iVar1, iVar2, iVar4, iVar5;
  uint32_t uVar3;
  if ((((DAT_0085a164 & 4u) == 0) && (DAT_008ca974 == 0)) &&
     ((param_1 != '\0' ||
      (((DAT_008ca960 != 0 || (DAT_008ca95c == 0xffffffff)) ||
       (*(int16_t*)((unsigned char*)DAT_0086ea08 + (size_t)DAT_008ca95c * (size_t)0x14c + 4) < 1)))))) {
    DAT_00725534 = 0xffffffff;
    DAT_008ca95c = DAT_0086c5d0;
    DAT_0086c588 = 0xffffffff;
    FUN_00433760();
    iVar2 = DAT_008ca960;
    iVar4 = DAT_008ca960 * 0x10;
    iVar5 = iVar4 + DAT_008ca95c;
    if ((*(int16_t*)((unsigned char*)DAT_0086e9ec + (size_t)iVar5 * (size_t)(0xa6 * 2)) < 100 && ((*(unsigned char*)((unsigned char*)DAT_0086ea08 + (size_t)iVar5 * (size_t)0x14c) & 0x50u) == 0)) ||
       (*(int16_t*)((unsigned char*)DAT_0086ea08 + (size_t)iVar5 * (size_t)0x14c + 4) < 1)) {
      if (0 < *(int16_t*)((unsigned char*)DAT_0086ea08 + (size_t)iVar5 * (size_t)0x14c + 4)) {
        if (DAT_008ca960 == 0) {
          return;
        }
        FUN_00433010(DAT_008ca960, DAT_008ca95c);
        return;
      }
      DAT_0086ea08[iVar5 * 0x53] = DAT_0086ea08[iVar5 * 0x53] | 0x1000u;
    }
    iVar5 = 0;
    while (true) {
      uVar3 = (uint32_t)(DAT_0086c5d0 + iVar5) & 0x8000000fu;
      if ((int32_t)uVar3 < 0) {
        uVar3 = (uVar3 - 1 | 0xfffffff0u) + 1;
      }
      iVar1 = iVar4 + (int32_t)uVar3;
      if ((*(unsigned char*)((unsigned char*)DAT_0086ea08 + (size_t)iVar1 * (size_t)0x14c + 1) & 0x10u) == 0 &&
         (0 < *(int16_t*)((unsigned char*)DAT_0086ea08 + (size_t)iVar1 * (size_t)0x14c + 4)) &&
         (0 < *(int16_t*)((unsigned char*)DAT_0086e9ec + (size_t)iVar1 * (size_t)(0xa6 * 2) + 2) &&
         (*(int16_t*)((unsigned char*)DAT_0086e9ec + (size_t)iVar1 * (size_t)(0xa6 * 2)) < 100))) {
        break;
      }
      iVar5 = iVar5 + 1;
      if (0xf < iVar5) {
        FUN_00431840(0);
        return;
      }
    }
    DAT_008ca95c = (int32_t)uVar3;
    if (iVar2 != 0) {
      FUN_00433010(iVar2, (int32_t)uVar3);
      return;
    }
    if (uVar3 != 0xffffffffu) {
      DAT_0085a128 = DAT_0086ea5c[uVar3 * 0x53];
      DAT_0085a124 = DAT_0086ea8c[uVar3 * 0x53];
    }
  }
}

// 0x433930 — observed shape: reads float pair at DAT_008c8c20/30 indexed by DAT_008c84dc*0x140; 8-way direction quantize (threshold 0.35, square 500/-500, iVar4 0..7); if |f1|+|f2|>=0.35 computes target via FUN_00431e50 and draws XLandBattleArrow.dds via FUN_004c1ac0 when empty.
void FUN_00433930(void) {
  float fVar1, fVar2;
  int iVar3, iVar4, iVar5, iVar6, iVar7;
  fVar1 = *(float*)((unsigned char*)DAT_008c8c20 + (size_t)DAT_008c84dc * (size_t)0x140);
  fVar2 = *(float*)((unsigned char*)DAT_008c8c30 + (size_t)DAT_008c84dc * (size_t)0x140);
  iVar7 = 0;
  iVar5 = 0;
  iVar6 = 0;
  iVar4 = 0;
  if (fVar1 <= 0.35f) {
    if (-0.35f <= fVar1) {
      if (0.35f < fVar2) {
        iVar7 = 0;
        iVar5 = 500;
        iVar4 = 2;
        goto LAB_00433a34;
      }
      if (-0.35f <= fVar2) goto LAB_00433a34;
      iVar7 = (int)0x80000000;
      iVar4 = 6;
    } else {
      iVar6 = 500;
      if (0.35f < fVar2) {
        iVar7 = (int)0xc0000000;
        iVar5 = 500;
        iVar4 = 1;
        goto LAB_00433a34;
      }
      if (-0.35f <= fVar2) {
        iVar7 = (int)0x80000000;
        iVar4 = 0;
        goto LAB_00433a34;
      }
      iVar7 = (int)0xa0000000;
      iVar4 = 7;
    }
  } else {
    iVar6 = -500;
    if (0.35f < fVar2) {
      iVar7 = 0x20000000;
      iVar5 = 500;
      iVar4 = 3;
      goto LAB_00433a34;
    }
    if (-0.35f <= fVar2) {
      iVar7 = 0x40000000;
      iVar4 = 4;
      goto LAB_00433a34;
    }
    iVar7 = 0x60000000;
    iVar4 = 5;
  }
  iVar5 = -500;
LAB_00433a34:
  (void)iVar3;
  (void)iVar6;
  (void)iVar5;
  (void)iVar7;
  if (0.35f <= (float)(fabs(fVar1) + fabs(fVar2))) {
    int iVar3b = DAT_008ca970 * 0x10 + DAT_008ca95c;
    int target = FUN_00431e50(*(int16_t*)((unsigned char*)DAT_0086e9f8 + (size_t)iVar3b * (size_t)(0xa6 * 2)) + DAT_007252f0[iVar4], *(int16_t*)((unsigned char*)DAT_0086e9fa + (size_t)iVar3b * (size_t)(0xa6 * 2)) + DAT_00725350[iVar4], -1);
    if (target == -1) {
      int iVar4b = DAT_008ca960 * 0x10 + DAT_008ca95c;
      FUN_004c1ac0(DAT_0086c370, DAT_0086ea5c[iVar4b * 0x53] + iVar5, DAT_0086ea8c[iVar4b * 0x53] + iVar6, (uint32_t)(iVar7 + 0x40000000), 0x2d, "XLandBattleArrow.dds");
    }
  }
}

// 0x433ae0 — observed shape: clear 0x40 dwords at DAT_00871978; 0xaa-iteration random-walk stamping terrain (!bVar1+1) near (0xd,9) setting 1 when within dist 3, else stepping; then 16x16 pass marking 5 where water/flag rules fail and FUN_005f0ddc()<1.
void FUN_00433ae0(void) {
  bool bVar1;
  uint32_t uVar7, uVar6, uVar2;
  int local_4;
  uint32_t* puVar8;
  uVar7 = 0xffffffffu;
  uVar6 = 0xffffffffu;
  bVar1 = false;
  puVar8 = (uint32_t*)DAT_00871978;
  for (int iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  local_4 = 0xaa;
  do {
    if (((((int32_t)uVar7 < 0) || ((int32_t)uVar6 < 0)) || (0xf < (int32_t)uVar7)) ||
       ((0xf < (int32_t)uVar6 || (rand() % 5 == 0)))) {
      uVar7 = (uint32_t)rand() & 0x8000000fu;
      if ((int32_t)uVar7 < 0) {
        uVar7 = (uVar7 - 1 | 0xfffffff0u) + 1;
      }
      uVar6 = (uint32_t)rand() & 0x8000000fu;
      if ((int32_t)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xfffffff0u) + 1;
      }
      bVar1 = (bool)(bVar1 ^ 1);
    } else {
      int iVar4 = (int32_t)uVar7 - 0xd;
      DAT_00871978[uVar6 + uVar7 * 0x10] = (unsigned char)((!bVar1) + '\x01');
      int iVar5 = (int32_t)uVar6 - 9;
      if (iVar4 < 0) iVar4 = -iVar4;
      if (iVar5 < 0) iVar5 = -iVar5;
      if (iVar5 < iVar4) iVar5 = iVar5 + iVar4 * 2; else iVar5 = iVar4 + iVar5 * 2;
      if (iVar5 / 2 < 3) {
        DAT_00871978[uVar6 + uVar7 * 0x10] = '\x01';
      }
      uVar2 = (uint32_t)rand() & 0x80000001u;
      bool bVar9 = uVar2 == 0;
      if ((int32_t)uVar2 < 0) {
        bVar9 = (uVar2 - 1 | 0xfffffffeU) == 0xffffffffU;
      }
      if (bVar9) {
        uVar2 = (uint32_t)rand() & 0x80000001u;
        if ((int32_t)uVar2 < 0) {
          uVar2 = (uVar2 - 1 | 0xfffffffeU) + 1;
        }
        uVar6 = uVar6 + ((-(uint32_t)(uVar2 != 0) & 2u) - 1u);
      } else {
        uVar2 = (uint32_t)rand() & 0x80000001u;
        if ((int32_t)uVar2 < 0) {
          uVar2 = (uVar2 - 1 | 0xfffffffeU) + 1;
        }
        uVar7 = uVar7 + ((-(uint32_t)(uVar2 != 0) & 2u) - 1u);
      }
    }
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  int iVar4 = 0;
  do {
    int iVar5 = 0;
    do {
      if ((((iVar5 < 6) || (10 < iVar5)) && ((DAT_008ca958 == '\0' || ((iVar5 < 4 || (10 < iVar5)))))) || (iVar4 < 0xe)) {
        if (iVar4 == 0xd) {
          if ((iVar5 == 7) || (iVar5 == 8)) {
            *(unsigned char*)(DAT_00871a48 + iVar5) = 5;
          } else if (iVar5 == 9) {
            DAT_00871a51 = 0;
          }
        }
      } else {
        DAT_00871978[iVar5 + iVar4 * 0x10] = 5;
      }
      FUN_004e7510((float)((DAT_00725520 + -8 + iVar4) * 1000), (float)((DAT_00725524 + -8 + iVar5) * 1000), 1);
      int iVar3 = FUN_005f0ddc();
      if (iVar3 < 1) {
        DAT_00871978[iVar5 + iVar4 * 0x10] = 5;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0x10);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x10);
}
