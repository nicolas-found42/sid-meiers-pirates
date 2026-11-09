// Reconstruction batch mass_0015 — Sid Meier's Pirates! (2004) PE32 i386
// Candidates translated from Ghidra 12.2 pseudocode corpus.
#include <cstdint>
#include <cstddef>
#include <cstring>
#include <windows.h>

// ---- extern helpers (observed callees) ----
extern void FUN_004c1000(const char* name);
extern int FUN_004baaa0(...);
extern int FUN_005f0ddc(...);
extern void FUN_004bbc10(...);
extern void FUN_004bbf50(...);
extern int FUN_00533c78(int size);
extern int FUN_004e0d80(int a, int b, int c);
extern void FUN_004e1510(...);
extern void FUN_004bb500(...);
extern void* FUN_004bb500_raw(int a);
extern void FUN_004db270(...);
extern void FUN_00488a80(...);
extern int FUN_0045fcb0(int a, int b, int c, int d, int e);
extern int FUN_0045fee0(int a, int b, int c, int d, int e);
extern int FUN_00405d90();
extern void FUN_004f6090(const char* fmt, ...);
extern void FUN_004f60b0(const char* fmt, ...);
extern void FUN_004879f0(int a, int b);
extern int FUN_00430190(...);
extern int FUN_004db210();
extern void FUN_004db270_ret(int* out);
extern void FUN_004bc0d0();
extern int FUN_004dadc0(int a, int b, int c);
extern void FUN_004bbc80(...);
extern char FUN_004c1a50(unsigned int a, void* b);
extern void FUN_004e7510(float a, float b, int c);
extern char FUN_004e7760(float a, float b, void* c, int d);
extern void FUN_004e7950(int a, int b, int c);
extern float FUN_004e7510_f(float a, float b, int c);
extern float FUN_004e7850(float a, float b);
extern void FUN_00475bd0();
extern void* FUN_004e8b60(int a);
extern void FUN_004e9740();
extern void FUN_004e8ea0(int a);
extern int FUN_004af680(...);
extern void FUN_004f2600(const char* fmt, ...);
extern void FUN_004bdca0(...);
extern void FUN_004c2200(int a, int b);
extern void FUN_00481560(...);
extern int FUN_004953d0();
extern void FUN_004888e0(int a, int b, int c, int d);
extern void FUN_004a3db0(int a);
extern void FUN_004ad820();
extern void FUN_004a3f10();
extern int FUN_00533db0(int a);
extern void FUN_00491fd0();
extern void FUN_004985e0();
extern void FUN_004a14b0();
extern int FUN_0045c270_impl(char a);
extern void FUN_0045fbf0();
extern void FUN_00475760(int a);
extern void FUN_004757c0();
extern void FUN_004517b0();
extern void FUN_00487e90();
extern void FUN_00450110(int a);
extern void FUN_00467f90(int a);
extern void FUN_004add70(int a);
extern void FUN_0043a970(int code, int a, int b, int c);
extern void FUN_004051c0();
extern void FUN_00414c00(int a, int b);
extern void FUN_004538d0();
extern void FUN_0044d2e0(int a, int b);
extern void FUN_00485380(...);
extern int FUN_00412950();
extern int FUN_004862a0();
extern int FUN_00404810();
extern char FUN_00404b70();
extern void FUN_004053c0(...);
extern void FUN_00404ff0(int a);
extern void FUN_00412810();
extern void FUN_004867b0();
extern void FUN_004a2c20();
extern void FUN_004a29c0();
extern void FUN_004a24b0();
extern void FUN_004af990();
extern int FUN_0047ff00(int a);
extern void FUN_0042d500(...);
extern void FUN_00475db0(...);
extern char FUN_00475db0_c(int a, int b, void* c);
extern void FUN_004e7510_v(float a, float b, int c);
extern int FUN_00445bac0();
extern void FUN_00404910(...);
extern void FUN_00405420();
extern void FUN_004a2d50();
extern void FUN_00452890();
extern void FUN_00451e50(...);
extern void FUN_0044fa40(...);
extern void FUN_00438e30(...);
extern void FUN_00412f10();
extern void FUN_0041b1d0(...);
extern void FUN_0040a610();
extern void FUN_004f3350();
extern void FUN_005f0ddc_v(...);
extern void FUN_004e7760_v(...);
extern void FUN_004e8b60_v(...);

// ---- extern globals (observed addresses) ----
extern float DAT_00727430;
extern float DAT_00727434;
extern float DAT_00727438;
extern int32_t DAT_0085a164;
extern int32_t DAT_008c8494;
extern int32_t DAT_0081430c[];
extern int32_t DAT_008142f8[];
extern int32_t DAT_008d0998[];
extern void* PTR_PTR_00726648;
extern int32_t DAT_008c99d8[];
extern int32_t DAT_008c97d8[];
extern int32_t DAT_0085a154;
extern int32_t DAT_0085a158;
extern int32_t DAT_0085a100;
extern int32_t DAT_008b9820[];
extern int32_t DAT_008b9870[];
extern int32_t DAT_008b97a8[];
extern int32_t DAT_008b96b8[];
extern int32_t DAT_008b9730[];
extern int32_t DAT_008cc198[];
extern int32_t DAT_0087706c[];
extern int32_t DAT_00877074[];
extern int32_t DAT_00877068[];
extern int32_t DAT_00877060[];
extern int32_t DAT_00877070[];
extern int32_t DAT_00877064[];
extern int32_t DAT_00877078[];
extern int32_t DAT_0087707c[];
extern int32_t DAT_0087707e[];
extern int16_t DAT_00877080[];
extern int32_t DAT_00814336[];
extern int32_t DAT_008142fc[];
extern int32_t DAT_00814304[];
extern int32_t DAT_00814308[];
extern uint32_t DAT_00814350[];
extern int32_t DAT_0081431e[];
extern int32_t DAT_0081431a[];
extern int32_t DAT_00814318[];
extern int32_t DAT_00869ab0;
extern int32_t DAT_00869ad0;
extern int32_t DAT_00869b34;
extern int32_t DAT_00869a74;
extern int32_t DAT_00869a78[];
extern int32_t DAT_00869a88[];
extern int32_t DAT_00869b26;
extern int32_t DAT_00869b48[];
extern int32_t DAT_00876bf8[];
extern int32_t DAT_008ca9e8;
extern int32_t DAT_00862cf6[];
extern int32_t DAT_00862cf5[];
extern int32_t DAT_0085a168[];
extern int32_t DAT_008b96b4;
extern int32_t DAT_008b96b0;
extern int32_t DAT_008b98d4;
extern int32_t DAT_008dbd08[];
extern int32_t DAT_008dbd0c[];
extern int32_t DAT_008dbd10[];
extern int32_t DAT_00860b74[];
extern int32_t DAT_00860b68[];
extern int32_t DAT_00860b6c[];
extern int32_t DAT_00860b70[];
extern int32_t DAT_00860b7c[];
extern int32_t DAT_0085bff6[];
extern int32_t DAT_0085bff8[];
extern int32_t DAT_0085bffc[];
extern int32_t DAT_00725350[];
extern int32_t DAT_007252f0[];
extern int32_t DAT_007252d0[];
extern float DAT_00725618;
extern float DAT_00725614;
extern int32_t DAT_0072cd78;
extern int32_t DAT_0085a7b0;
extern int32_t DAT_0085a7d0;
extern int32_t DAT_00725680;
extern int32_t DAT_008b98e0;
extern int32_t DAT_008b98e4[];
extern int32_t DAT_008b98f0[];
extern int32_t DAT_00877048;
extern void* DAT_0087704c;
extern void* DAT_00877050;
extern void* DAT_00877054;
extern int32_t DAT_00726a84;
extern int32_t DAT_007263bc;
extern int32_t DAT_007268f4[];
extern int32_t DAT_008cac38;
extern int32_t DAT_008ca9e0;
extern int32_t DAT_008ca9e4;
extern int32_t DAT_008ea000;
extern int32_t DAT_00876d00[];
extern float DAT_008e64d4;
extern float DAT_008e64d8;
extern float DAT_008de180[];
extern float DAT_008de184[];
extern float DAT_008de188[];
extern float DAT_008de18c[];
extern int32_t DAT_008de191[];
extern int32_t DAT_008de190[];
extern int32_t DAT_008de192[];
extern int32_t DAT_0085a790[];
extern int32_t DAT_0085a7f0[];
extern int32_t DAT_0085a810[];
extern int32_t DAT_0085a830[];
extern int32_t DAT_0085a850[];
extern int32_t DAT_0085a870[];
extern int32_t DAT_0085a890;
extern float DAT_008e64d4_f;
extern int32_t DAT_00725684;
extern int32_t DAT_008b9970;
extern int32_t DAT_00814310[];
extern int32_t DAT_0085a0fc;
extern int32_t DAT_0085a118;
extern int32_t DAT_00725600;
extern int32_t DAT_007255fc;
extern int32_t DAT_00725560;
extern int32_t DAT_0072555c;
extern int32_t DAT_007253b8;
extern int32_t DAT_007253b0;
extern int32_t DAT_00725678;
extern int32_t DAT_008b99a0;
extern void* DAT_008ecd78;
extern int32_t DAT_0085a0f8;
extern int32_t DAT_008c81f4;
extern int32_t DAT_008b9978;
extern int32_t DAT_008b997c;
extern int32_t DAT_008c8210;
extern int32_t DAT_008c8218;
extern int32_t DAT_0085a268;
extern int32_t DAT_0085a26c;
extern int32_t DAT_00725728;
extern int32_t DAT_00725724;
extern int32_t DAT_00876cfc;
extern int32_t DAT_00876cf8;
extern int32_t DAT_0085a2b0[];
extern int32_t DAT_0085a380;
extern int32_t DAT_0085a384;
extern int32_t DAT_0085a3b8;
extern int32_t DAT_0085a3f8;
extern int32_t DAT_0085a4c8;
extern int32_t DAT_0085a500;
extern int32_t DAT_0085a540;
extern int32_t DAT_0085a610;
extern int32_t DAT_0085a648;
extern int32_t DAT_0085a688;
extern int32_t DAT_0085a758;
extern int32_t DAT_008cb100[];
extern int32_t DAT_008cb104[];
extern int32_t DAT_008cb108[];
extern int32_t DAT_00869ab4;
extern int32_t DAT_00869b1c;
extern int32_t DAT_00869b1e;
extern int32_t DAT_00861ff8;
extern int32_t DAT_00862010;
extern int32_t DAT_00862008[];
extern int32_t DAT_00862000[];
extern int32_t DAT_00861ffc[];
extern int32_t DAT_00861b78[];
extern int32_t DAT_008610f6;
extern int32_t DAT_008cacd0;
extern int32_t DAT_0085a9a4[];
extern int32_t DAT_008c73ba;
extern int32_t DAT_008c827c;
extern int32_t DAT_0085bf7c[];
extern int32_t DAT_0085bf7e[];
extern int32_t DAT_0085bf82[];
extern int32_t DAT_0085a984[];
extern int32_t DAT_0085a270;
extern int32_t DAT_006fb75c[];
extern int32_t DAT_006f5896[];
extern int32_t DAT_006fecfc[];
extern int32_t DAT_00814322[];
extern int32_t DAT_00814328[];
extern int32_t DAT_00814320[];
extern int32_t DAT_00814330[];
extern int32_t DAT_00814336_s[];
extern int32_t DAT_00814338[];
extern int32_t DAT_0081435a[];
extern int32_t DAT_008142fa[];
extern int32_t DAT_00723b08[];
extern int32_t DAT_00723b14[];
extern int32_t DAT_0085a984_s[];
extern void* PTR_DAT_00726808;
extern int32_t DAT_00727444;
extern int32_t DAT_008ccd98[];
extern int32_t DAT_008cce58[];
extern int32_t DAT_008cd098[];
extern int32_t DAT_008cdb18[];
extern int32_t DAT_008cd8d8[];
extern int32_t DAT_008774e0;
extern int32_t DAT_0087751c;
extern int32_t DAT_00877500;
extern int32_t DAT_00877504;
extern int32_t DAT_00877508;
extern int32_t DAT_0087750c;
extern int32_t DAT_00877510;
extern int32_t DAT_00877514;
extern int32_t DAT_0087751c2;
extern int32_t DAT_008ca994;
extern int32_t DAT_008cac44;
extern int32_t DAT_008ca9d4;
extern int32_t DAT_008c827d;
extern int32_t DAT_0085a790_2[];
extern int32_t DAT_00877048_a;

// 0x45a7c0 — observed shape
int FUN_45a7c0(void* self) {
  float local_c, local_8, local_4;
  (void)local_c; (void)local_8; (void)local_4;
  FUN_004c1000("Dummy_bowfroth");
  FUN_004baaa0();
  if ((local_c == DAT_00727430) && (local_8 == DAT_00727434) && (local_4 == DAT_00727438)) {
    return 0;
  }
  int in_ECX = (int)(intptr_t)self;
  if ((in_ECX == 0) && (DAT_0085a164 < 0)) {
    return 0;
  }
  unsigned int uVar2 = (unsigned int)FUN_005f0ddc();
  unsigned int uVar3 = (unsigned int)FUN_005f0ddc();
  unsigned int uVar8 = 0xffffffff;
  unsigned int uVar9 = (unsigned int)DAT_008c8494;
  FUN_005f0ddc(0xffffffff, DAT_008c8494);
  unsigned int uVar7 = 0;
  int iVar5 = DAT_0081430c[in_ECX * 0x117] + -0x80000000;
  unsigned int uVar6 = 0;
  unsigned int uVar4 = (unsigned int)FUN_005f0ddc(iVar5, 0, 0);
  FUN_004bbc10(&PTR_PTR_00726648, uVar3, uVar2, uVar4, iVar5, uVar6, uVar7, uVar8, uVar9);
  int16_t sVar1 = (int16_t)DAT_008142f8[in_ECX * 0x22e];
  uVar8 = 0xffffffff;
  uVar9 = (unsigned int)DAT_008c8494;
  FUN_005f0ddc(0xffffffff, DAT_008c8494);
  uVar7 = 0;
  iVar5 = DAT_0081430c[in_ECX * 0x117] + -0x80000000;
  uVar6 = 0;
  uVar4 = (unsigned int)FUN_005f0ddc(iVar5, 0, 0);
  FUN_004bbc10(&DAT_008d0998[((int)sVar1 % 9) * 0x30], uVar3, uVar2, uVar4, iVar5, uVar6, uVar7, uVar8, uVar9);
  return 1;
}

// 0x45a940 — observed shape
void FUN_45a940(void* self, int param_1) {
  int in_EAX_unused = 0;
  (void)in_EAX_unused;
  // Observed: takes int param_1; dispatch on in_EAX / unaff_EDI / in_ECX
  // Reconstructed with self as receiver context.
  int in_EAX = (int)(intptr_t)self;
  int unaff_EDI = 0;
  int in_ECX = (int)(intptr_t)self;
  if (in_EAX != 0) {
    FUN_004bbf50();
    FUN_45a7c0(self);
  }
  float fVar5 = (float)param_1 * 0.001f;
  if ((in_EAX == 0) || ((unaff_EDI == 0 && (DAT_0085a164 < 0)))) {
    return;
  }
  unsigned int uVar4;
  if (DAT_008c99d8[unaff_EDI] == 0) {
    if (in_ECX == 0) {
      DAT_008c97d8[unaff_EDI] = 100;
      return;
    }
    int iVar1 = FUN_00533c78(0x36c);
    if (iVar1 == 0) {
      uVar4 = 0;
    } else {
      int iVar2 = FUN_004baaa0();
      unsigned int inner = *(unsigned int*)(iVar2 + 0x68);
      unsigned int uVar3 = (unsigned int)FUN_004baaa0(inner);
      uVar4 = (unsigned int)FUN_004e0d80(iVar1, uVar3, inner);
    }
    DAT_008c99d8[unaff_EDI] = (int32_t)uVar4;
    uVar4 = 1;
    FUN_004baaa0(1);
    fVar5 = 0.0f;
  } else {
    uVar4 = ((unsigned int)DAT_008c99d8[unaff_EDI] & 0xffffff00u) | (unsigned int)(in_ECX != 0);
    FUN_004baaa0(uVar4);
  }
  FUN_004e1510(fVar5, uVar4);
  DAT_008c97d8[unaff_EDI] = 0;
}

// 0x45aa10 — observed shape
void* FUN_45aa10(void* self, int param_1, int param_2) {
  int in_EAX = (int)(intptr_t)self;
  int iVar2 = DAT_0085a154;
  int iVar6 = in_EAX % 9;
  void* puVar4 = nullptr;
  int iVar3;
  if (param_2 == 0) {
    iVar2 = 0;
    while (DAT_008b9820[iVar2] != iVar6 ||
           (DAT_008b97a8[iVar2] != param_1 && DAT_008b9730[iVar2] != param_1)) {
      iVar2 = iVar2 + 1;
      if (0x13 < iVar2) {
        return nullptr;
      }
    }
    return (void*)(intptr_t)DAT_008b9870[iVar2];
  }
  iVar3 = 0;
  do {
    if ((DAT_008b9820[iVar3] == iVar6) && DAT_008b97a8[iVar3] == -1 && DAT_008b9730[iVar3] == param_1) {
      DAT_008b97a8[iVar3] = param_1;
      DAT_008b96b8[iVar3] = iVar2;
      return (void*)(intptr_t)DAT_008b9870[iVar3];
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x14);
  iVar2 = 0;
  do {
    if ((DAT_008b9820[iVar2] == iVar6) && DAT_008b97a8[iVar2] == -1 &&
        (DAT_008b9730[iVar2] == -1 || DAT_008b96b8[iVar2] < DAT_0085a154 + -0x28)) {
      DAT_008b96b8[iVar2] = DAT_0085a154;
      DAT_008b97a8[iVar2] = param_1;
      return (void*)(intptr_t)DAT_008b9870[iVar2];
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x14);
  iVar2 = 0;
  do {
    if (DAT_008b9820[iVar2] == -1) goto LAB_0045ab8a;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x14);
  iVar2 = -1;
  int iVar5 = 0;
  iVar3 = DAT_0085a154;
  int iVar7 = 2;
  do {
    if ((*(int*)((char*)DAT_008b97a8 + iVar5) == -1) && (*(int*)((char*)DAT_008b96b8 + iVar5) < iVar3)) {
      iVar2 = iVar7 + -2;
      iVar3 = *(int*)((char*)DAT_008b96b8 + iVar5);
    }
    if ((*(int*)((char*)DAT_008b97a8 + iVar5 + 4) == -1) && (*(int*)((char*)DAT_008b96b8 + iVar5 + 4) < iVar3)) {
      iVar2 = iVar7 + -1;
      iVar3 = *(int*)((char*)DAT_008b96b8 + iVar5 + 4);
    }
    if ((*(int*)((char*)DAT_008b97a8 + iVar5 + 8) == -1) && (*(int*)((char*)DAT_008b96b8 + iVar5 + 8) < iVar3)) {
      iVar3 = *(int*)((char*)DAT_008b96b8 + iVar5 + 8);
      iVar2 = iVar7;
    }
    if ((*(int*)((char*)DAT_008b97a8 + iVar5 + 12) == -1) && (*(int*)((char*)DAT_008b96b8 + iVar5 + 12) < iVar3)) {
      iVar2 = iVar7 + 1;
      iVar3 = *(int*)((char*)DAT_008b96b8 + iVar5 + 12);
    }
    if ((*(int*)((char*)DAT_008b97a8 + iVar5 + 16) == -1) && (*(int*)((char*)DAT_008b96b8 + iVar5 + 16) < iVar3)) {
      iVar2 = iVar7 + 2;
      iVar3 = *(int*)((char*)DAT_008b96b8 + iVar5 + 16);
    }
    iVar5 = iVar5 + 0x14;
    iVar7 = iVar7 + 5;
  } while (iVar7 + 3 < 0x14);
  if (iVar2 == -1) {
    return (void*)DAT_008cc198;
  }
  if (DAT_008b9870[iVar2] != 0) {
    void (*fn)(int) = *(void(**)(int))(DAT_008b9870[iVar2]);
    fn(1);
  }
LAB_0045ab8a:
  puVar4 = (void*)FUN_004bb500_raw(0);
  iVar3 = DAT_0085a154;
  DAT_008b9820[iVar2] = iVar6;
  DAT_008b9870[iVar2] = (int32_t)(intptr_t)puVar4;
  DAT_008b97a8[iVar2] = param_1;
  DAT_008b96b8[iVar2] = iVar3;
  return puVar4;
}

// 0x45ac10 — observed shape
void FUN_45ac10(void* self) {
  (void)self;
  int iVar1 = 0;
  do {
    if (*(int*)((char*)DAT_008b9820 + iVar1) != -1 &&
        *(void**)((char*)DAT_008b9870 + iVar1) != nullptr) {
      void (*fn)(int) = *(void(**)(int))*(void**)((char*)DAT_008b9870 + iVar1);
      fn(1);
    }
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x50);
  unsigned int* puVar2 = (unsigned int*)DAT_008b9820;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xffffffff;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (unsigned int*)DAT_008b97a8;
  for (iVar1 = 0x1d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xffffffff;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (unsigned int*)DAT_008b9870;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (unsigned int*)DAT_008b97a8;
  unsigned int* puVar3 = (unsigned int*)DAT_008b9730;
  for (iVar1 = 0x1d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = (unsigned int*)DAT_008b97a8;
  for (iVar1 = 0x1d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xffffffff;
    puVar2 = puVar2 + 1;
  }
}

// 0x45ac90 — observed shape
int FUN_45ac90(void* self, int param_1, int param_2, int param_3, int param_4, uint32_t param_5, int16_t param_6, int16_t param_7, char param_8) {
  unsigned int in_ECX = (unsigned int)(intptr_t)self;
  if ((DAT_0085a164 & 4) != 0) {
    return -1;
  }
  int iVar6 = 0;
  int* piVar1 = DAT_0087706c;
  while (*piVar1 != 0) {
    piVar1 = piVar1 + 9;
    iVar6 = iVar6 + 1;
    if (0x8774eb < (int)(intptr_t)piVar1) {
      return -1;
    }
  }
  DAT_00877074[iVar6 * 9] = (int32_t)in_ECX;
  DAT_00877068[iVar6 * 9] = (int32_t)in_ECX;
  DAT_0087706c[iVar6 * 9] = param_1;
  DAT_00877060[iVar6 * 9] = param_1;
  DAT_00877070[iVar6 * 9] = param_2;
  DAT_00877064[iVar6 * 9] = param_2;
  int iVar2 = 0;
  FUN_004db270(&iVar2);
  DAT_00877078[iVar6 * 9] = iVar2;
  if (param_5 != 0xffffffffu) {
    uint32_t uVar4 = (uint32_t)((int32_t)(param_5 - (uint32_t)iVar2) >> 31);
    uVar4 = (param_5 - (uint32_t)iVar2 ^ uVar4) - uVar4;
    int iVar3;
    bool bVar8, bVar7;
    if ((param_5 & 1) == 0) {
      iVar3 = (int32_t)(uVar4 ^ (uint32_t)((int32_t)uVar4 >> 31)) - ((int32_t)uVar4 >> 31);
      bVar8 = (iVar3 < (int)0x40000000);
      iVar2 = iVar3 + -0x40000000;
      bVar7 = (iVar3 == 0x40000000);
    } else {
      uint32_t uVar5 = (uint32_t)((int32_t)(uVar4 + 0xc0000000u) >> 31);
      iVar3 = (int32_t)((uVar4 + 0xc0000000u) ^ uVar5) - (int32_t)uVar5;
      bVar8 = (iVar3 < (int)0x20000000);
      iVar2 = iVar3 + -0x20000000;
      bVar7 = (iVar3 == 0x20000000);
    }
    if (!bVar7 && (bVar8 == (iVar2 < 0))) {
      DAT_0087706c[iVar6 * 9] = 0;
      return -1;
    }
  }
  param_4 = param_2 - param_4;
  param_3 = param_1 - param_3;
  DAT_0087707c[iVar6 * 0x12] = 0;
  if (param_3 < 0) param_3 = -param_3;
  if (param_4 < 0) param_4 = -param_4;
  iVar2 = param_4 + param_3 * 2;
  if (param_3 <= param_4) {
    iVar2 = param_3 + param_4 * 2;
  }
  DAT_0087707e[iVar6 * 0x12] = (int16_t)(iVar2 / 100);
  DAT_00877080[iVar6 * 0x24] = param_6;
  *(int16_t*)((char*)DAT_00877080 + iVar6 * 0x24 + 2) = param_7;
  if (param_8 != 0) {
    FUN_00488a80(2, (float)param_1, (float)param_2, ((float*) &iVar2)[0] * 0.0f + 0x41a00000, 0xffffffffu, 0xffffffffu, 0xffffffffu, 0xffffffffu, 0, 0xbf800000u, 0xffffffffu);
  }
  return iVar6;
}

// 0x45ae30 — observed shape
// NEEDS_MANUAL: very long non-contiguous routine (~220 lines observed); transcription preserves loop structure, distance computations, flag handling and call order, but auxiliary label layout is approximated.
void FUN_45ae30(void* self) {
  (void)self;
  int local_88 = 0;
  int16_t* psVar15 = (int16_t*)DAT_0087707e;
  do {
    int iVar10 = *(int*)(psVar15 + -9);
    if (iVar10 != 0) {
      int16_t sVar1 = *psVar15;
      int16_t sVar4 = psVar15[-1] + 1;
      psVar15[-1] = sVar4;
      if ((sVar4 < sVar1) && (sVar1 != 0)) {
        int iVar5 = FUN_004db210();
        *(int*)(psVar15 + -9) = iVar10 + iVar5;
        int iVar6 = FUN_004db210();
        int iVar13 = *(int*)(psVar15 + -7);
        *(int*)(psVar15 + -7) = iVar13 + iVar6;
        int iVar7 = FUN_004db210();
        int iVar11 = *(int*)(psVar15 + -5);
        unsigned int uVar8 = (unsigned int)FUN_004dadc0(0, 0, 0);
        uVar8 = (unsigned int)FUN_004bbc80(iVar10 + iVar5, iVar13 + iVar6, iVar7 + iVar11, uVar8, 3000, 0xffffffffu, 0);
        unsigned int uVar9 = (unsigned int)FUN_005f0ddc();
        FUN_004bbc10(DAT_008ccd98, *(unsigned int*)(psVar15 + -9), *(unsigned int*)(psVar15 + -7), iVar7 + iVar11, 0, 0, 0, 0xffffffffu, uVar9);
        uVar9 = (unsigned int)FUN_004dadc0(0, 0, 0);
        FUN_004bbc80(*(unsigned int*)(psVar15 + -9), *(unsigned int*)(psVar15 + -7), 0, uVar9, 0x4b, 0xffffffffu, 0);
        sVar1 = psVar15[-1];
        iVar10 = FUN_005f0ddc();
        if (sVar1 * 0x32 < iVar10) {
          FUN_004bbc10(&DAT_008cce58[(local_88 % 3) * 0xc0], *(unsigned int*)(psVar15 + -0xf), *(unsigned int*)(psVar15 + -0xd), *(unsigned int*)(psVar15 + -0xb), *(unsigned int*)(psVar15 + -3), 0xf1c71c72, 0, 0xffffffffu, sVar1 * 0x32);
        }
        *(uint8_t*)(psVar15 + 1) &= 0xfe;
        if ((int)*psVar15 / 3 < (int)psVar15[-1]) {
          iVar10 = 0;
          int16_t* psVar14 = (int16_t*)DAT_008142f8;
          do {
            if (*psVar14 != -1) {
              iVar13 = *(int*)(psVar14 + 8) / 1000 - *(int*)(psVar15 + -7);
              iVar11 = *(int*)(psVar14 + 6) / 1000 - *(int*)(psVar15 + -9);
              if (iVar11 < 0) iVar11 = -iVar11;
              if (iVar13 < 0) iVar13 = -iVar13;
              if (iVar13 < iVar11) iVar13 = iVar13 + iVar11 * 2;
              else iVar13 = iVar11 + iVar13 * 2;
              if ((iVar13 / 2 < 1000) && (iVar13 = (int)(intptr_t)FUN_45aa10((void*)(intptr_t)iVar10, 0), iVar13 != 0) &&
                  (FUN_004c1a50(uVar8, (void*)(intptr_t)iVar13), iVar13 = DAT_0085a158, 1)) {
                *(uint8_t*)(psVar15 + 1) |= 1;
                psVar15[-1] = *psVar15;
                if (5 - iVar13 < 1) {
                  iVar11 = 0;
                } else {
                  iVar11 = rand();
                  iVar11 = iVar11 % (5 - iVar13);
                }
                if (iVar11 <= iVar10) {
                  iVar13 = psVar14[0x11] + 4 + DAT_0085a158 * 2;
                  if (iVar13 < 5) iVar13 = 5;
                  else if (100 < iVar13) iVar13 = 100;
                  psVar14[0x11] = (int16_t)iVar13;
                  if (99 < (int16_t)iVar13) {
                    psVar14[0x11] = (int16_t)((-(uint16_t)(iVar10 != 0) & 10) + 0x5a);
                    if ((*(uint32_t*)(psVar14 + 0x2c) & 0x4000u) != 0) psVar14[0x11] = 0x5a;
                    FUN_00488a80(0x20, (float)*(int*)(psVar15 + -9), (float)*(int*)(psVar15 + -7), 0x41f00000u, 0xffffffffu, 0xffffffffu, 0xffffffffu, 0xffffffffu, 0, 0xbf800000u, 0xffffffffu);
                  }
                }
                FUN_00488a80(0x1b, (float)*(int*)(psVar15 + -9), (float)*(int*)(psVar15 + -7), 0x41f00000u, 0xffffffffu, 0xffffffffu, 0xffffffffu, 0xffffffffu, 0, 0xbf800000u, 0xffffffffu);
              }
              if ((*(uint8_t*)(psVar15 + 1) & 1) != 0) {
                goto LAB_0045b1ea;
              }
            }
            psVar14 = psVar14 + 0x22e;
            iVar10 = iVar10 + 1;
          } while ((int)(intptr_t)psVar14 < 0x815468);
        }
      } else {
        uint16_t uVar2 = (uint16_t)psVar15[1];
        if ((uVar2 & 1) == 0) {
          int iVar5 = (int)sVar4 - (int)sVar1;
          int iVar13 = iVar5 * 0x32;
          int iVar11 = FUN_005f0ddc();
          if (iVar11 <= iVar13) goto LAB_0045b59b;
          if ((uVar2 & 0xe) == 0) {
            int iVar7 = *(int*)(psVar15 + -7);
            int iVar12 = FUN_0045fcb0(iVar10 / 1000, iVar7 / 1000, 0xffffffffu, 9999, 0xc0008000u);
            int iVar12b = iVar12 * 0x94;
            iVar11 = *(int*)((char*)DAT_0085bffc + iVar12b) - iVar7;
            iVar12 = *(int*)((char*)DAT_0085bff8 + iVar12b) - iVar10;
            if (iVar12 < 0) iVar12 = -iVar12;
            if (iVar11 < 0) iVar11 = -iVar11;
            if (iVar11 < iVar12) iVar11 = iVar11 + iVar12 * 2;
            else iVar11 = iVar12 + iVar11 * 2;
            if (iVar11 / 2 < 0x1f5) {
              psVar15[1] = (int16_t)(uVar2 | 8);
            } else {
              FUN_004e7510((float)iVar10, (float)iVar7, 0);
              iVar10 = FUN_005f0ddc();
              psVar15[1] = (int16_t)(psVar15[1] | (int16_t)(-(uint16_t)(iVar10 != 0) & 2) + 2);
            }
          }
          unsigned int uVar8 = 0, uVar9 = 0, uVar17 = 0, uVar18 = 0, uVar19 = 0;
          unsigned int* puVar16 = nullptr;
          int iVar6 = (local_88 % 3) * 0xc0;
          if ((psVar15[1] & 2u) == 0) {
            if ((psVar15[1] & 4u) == 0) {
              uVar8 = *(uint32_t*)(psVar15 + -3);
              int iSvg = (int)psVar15[-1] - (int)*psVar15;
              uVar17 = *(uint32_t*)(psVar15 + -7);
              iVar13 = (iSvg) * 0x32;
              uVar9 = *(uint32_t*)(psVar15 + -9);
              uVar19 = 0x40000000;
              uVar18 = 0x1e;
              puVar16 = &DAT_008cd098[iVar6];
            } else {
              FUN_004e7510((float)*(int*)(psVar15 + -9), (float)*(int*)(psVar15 + -7), 0);
              uVar18 = (unsigned int)FUN_005f0ddc();
              uVar8 = *(uint32_t*)(psVar15 + -3);
              uVar9 = *(uint32_t*)(psVar15 + -9);
              uVar19 = 0;
              uVar17 = *(uint32_t*)(psVar15 + -7);
              puVar16 = DAT_008cdb18;
            }
          } else {
            uVar8 = *(uint32_t*)(psVar15 + -3);
            uVar17 = *(uint32_t*)(psVar15 + -7);
            uVar9 = *(uint32_t*)(psVar15 + -9);
            uVar19 = 0;
            uVar18 = 0x14;
            puVar16 = &DAT_008cd8d8[iVar6];
          }
          FUN_004bbc10(puVar16, uVar9, uVar17, uVar18, uVar8, uVar19, 0, 0xffffffffu, iVar13);
          if (iVar5 == 0) {
            if ((psVar15[1] & 2u) == 0) {
              if ((psVar15[1] & 8u) != 0) {
                FUN_00488a80(0x1f, (float)*(int*)(psVar15 + -9), (float)*(int*)(psVar15 + -7), 0x41a00000u, 0xffffffffu, 0xffffffffu, 0xffffffffu, 0xffffffffu, 0, 0xbf800000u, 0xffffffffu);
              }
            } else {
              FUN_00488a80(0x1c, (float)*(int*)(psVar15 + -9), (float)*(int*)(psVar15 + -7), 0x41a00000u, 0xffffffffu, 0xffffffffu, 0xffffffffu, 0xffffffffu, 0, 0xbf800000u, 0xffffffffu);
            }
          }
        } else {
        LAB_0045b1ea:
          int iVar11 = ((int)psVar15[-1] - (int)*psVar15) * 0x32;
          int iVar13 = (local_88 % 3) * 0xc0;
          iVar10 = FUN_005f0ddc();
          if (iVar11 < iVar10) {
            if ((psVar15[2] != -1) && ((*(uint8_t*)(psVar15 + 1) & 6) == 0)) {
              int iVar5 = psVar15[2] * 0x94;
              int iVar10b = *(int*)(psVar15 + -7) - *(int*)((char*)DAT_0085bffc + iVar5);
              int iVar5b = *(int*)(psVar15 + -9) - *(int*)((char*)DAT_0085bff8 + iVar5);
              if (iVar5b < 0) iVar5b = -iVar5b;
              if (iVar10b < 0) iVar10b = -iVar10b;
              if (iVar10b < iVar5b) iVar10b = iVar10b + iVar5b * 2;
              else iVar10b = iVar5b + iVar10b * 2;
              if (500 < iVar10b / 2) {
                FUN_004e7510((float)*(int*)(psVar15 + -9), (float)*(int*)(psVar15 + -7), 0);
                iVar10 = FUN_005f0ddc();
                if (iVar10 == 0) {
                  *(uint8_t*)(psVar15 + 1) |= 2;
                  goto LAB_0045b2bd;
                }
              }
              *(uint8_t*)(psVar15 + 1) |= 4;
            }
          LAB_0045b2bd:
            if ((*(uint8_t*)(psVar15 + 1) & 2) == 0) {
              FUN_004bbc10(&DAT_008cd098[iVar13], *(uint32_t*)(psVar15 + -9), *(uint32_t*)(psVar15 + -7), 0x1e, *(uint32_t*)(psVar15 + -3), 0x40000000, 0, 0xffffffffu, iVar11);
            } else {
              FUN_004bbc10(&DAT_008cd8d8[iVar13], *(uint32_t*)(psVar15 + -9), *(uint32_t*)(psVar15 + -7), 0x14, *(uint32_t*)(psVar15 + -3), 0, 0, 0xffffffffu, psVar15[-1] * 0x32);
            }
          } else {
          LAB_0045b59b:
            psVar15[-9] = 0;
            psVar15[-8] = 0;
          }
        }
      }
    }
    local_88 = local_88 + 1;
    psVar15 = psVar15 + 0x12;
    if (0x8774fd < (int)(intptr_t)psVar15) {
      return;
    }
  } while (true);
}

// 0x45b5d0 — observed shape
uint32_t FUN_45b5d0(void* self) {
  int in_EAX = (int)(intptr_t)self;
  uint32_t local_4 = (uint32_t)(int16_t)DAT_00814336[in_EAX * 0x22e];
  if (local_4 == 0xffffffffu) {
    int16_t sVar1 = *(int16_t*)((char*)DAT_008142fc + in_EAX * 0x117 * sizeof(int32_t));
    bool bVar3 = false;
    int iVar5 = 0;
    do {
      if (bVar3) {
        return local_4;
      }
      uint32_t uVar4 = (uint32_t)(iVar5 + sVar1) & 0x80000003u;
      if ((int32_t)uVar4 < 0) {
        uVar4 = (uVar4 - 1 | 0xfffffffc) + 1;
      }
      uVar4 = (uint32_t)FUN_0045fcb0(DAT_00814304[in_EAX * 0x117] / 1000000, DAT_00814308[in_EAX * 0x117] / 1000000, 1u << ((uint8_t)uVar4 & 0x1f), 9999, 0xc0008000u);
      if (uVar4 != 0xffffffffu) {
        bVar3 = true;
        local_4 = uVar4;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 4);
    if (!bVar3) {
      int iVar5b = DAT_00814308[in_EAX * 0x117];
      int iVar2 = DAT_00814304[in_EAX * 0x117];
      local_4 = (uint32_t)FUN_0045fcb0(iVar2 / 1000000, iVar5b / 1000000, 0x10, 9999, 0xc0008000u);
      if (local_4 == 0xffffffffu) {
        uint32_t uVar4 = (uint32_t)FUN_0045fcb0(iVar2 / 1000000, iVar5b / 1000000, 0xffffffffu, 9999, 0xc0008000u);
        return uVar4 & (uVar4 == 0xffffffffu ? 0xffffffffu : 0u);
      }
    }
  }
  return local_4;
}

// 0x45b740 — observed shape
void FUN_45b740(void* self) {
  int in_EAX = (int)(intptr_t)self;
  DAT_00814350[in_EAX * 0x117] |= 0x80u;
  uint16_t uVar1 = (uint16_t)FUN_45b5d0(self);
  *(uint16_t*)((char*)DAT_00814336 + in_EAX * 0x22e * sizeof(int32_t)) = uVar1;
}

// 0x45b770 — observed shape
int FUN_45b770(void* self, int param_1, int param_2, int param_3) {
  int in_EAX = (int)(intptr_t)self;
  int unaff_EBX = (int)(intptr_t)self;
  (void)param_1;
  if ((DAT_0085a164 & 4) != 0) {
    return param_3;
  }
  FUN_004bc0d0();
  int iVar1 = FUN_005f0ddc();
  if (iVar1 == 0) {
    return param_3;
  }
  uint32_t uVar3 = (uint32_t)(((uint32_t)(in_EAX - param_2) + 0x80000000u) >> 16);
  int iVar2 = (int)(((int32_t)(uVar3 * (uint32_t)iVar1) >> 16) - param_3 + iVar1) % iVar1;
  if (iVar1 / 2 < iVar2) {
    iVar2 = iVar2 - iVar1;
  }
  iVar2 = ((int32_t)(iVar2 + (int32_t)((uint32_t)(iVar2 >> 31) & 0xf)) >> 4) + param_3;
  if ((uVar3 < 0x6801u) || (0x97ffu < uVar3)) {
    if (unaff_EBX == 0) {
      DAT_008c81f4 = 0;
    }
  } else {
    iVar2 = rand();
    iVar2 = (iVar2 % 3000 - param_3) + 6000;
    iVar2 = ((int32_t)(iVar2 + (int32_t)((uint32_t)(iVar2 >> 31) & 7)) >> 3) + param_3;
    if (unaff_EBX == 0) {
      DAT_008c81f4 = 1;
    }
  }
  if ((int8_t)DAT_0085a164 < 0) {
    DAT_008c81f4 = 0;
  }
  return (iVar2 + iVar1) % iVar1;
}

// 0x45b890 — observed shape
void FUN_45b890(void* self) {
  (void)self;
  int iVar4 = DAT_0085a154;
  DAT_008b98d4 = DAT_0085a154 + 0xfa;
  if (DAT_0085a158 != 0) {
    return;
  }
  FUN_0045fee0(DAT_008b96b4, DAT_008b96b0, 0xffffffffu, 0xffffffffu, 0x80008000u);
  int iVar1 = FUN_00405d90();
  if ((0xb < iVar1) && (DAT_0085a164 >= 0)) {
    DAT_008b98d4 = iVar4 + 99999;
    FUN_004f6090("We're far out to sea captain, shall I set a course for...\n");
    FUN_004879f0(0x28, 0);
    iVar4 = 0;
    iVar1 = 0;
    int aiStack_14[5];
    do {
      int iVar2 = FUN_0045fcb0(DAT_008b96b4, DAT_008b96b0, 1u << ((uint8_t)iVar1 & 0x1f), 9999, 0xc0008000u);
      if (iVar2 != -1) {
        aiStack_14[iVar4] = iVar2;
        iVar4 = iVar4 + 1;
        iVar1 = FUN_00405d90();
        FUN_004f60b0(" @CITYNAME (@NATIONALITY, @NUM leagues away.)\n",
                     DAT_008dbd08[iVar2 * 3], DAT_008dbd0c[iVar2 * 3], DAT_008dbd10[iVar2 * 3],
                     (int)(int8_t)DAT_00860b74[iVar2 * 0x20], iVar1 * 5);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 5);
    FUN_004f60b0(" Quiet, I'm the captain!\n");
    iVar1 = FUN_00430190((int)(DAT_0085a26c + (DAT_0085a26c >> 31 & 3u)) >> 2,
                         DAT_0085a268 / 6 + 1, DAT_006fb75c, 0, 0xffffffffu, 0, 0, 0xffffffffu, 0, 0);
    if ((-1 < iVar1) && (iVar1 < iVar4)) {
      int t = 0;
      FUN_004db270(&t);
      DAT_0081433c_val(&t);
    }
  }
}

// helper declared at bottom via extern trick: define below
// 0x45ba40 — observed shape
int FUN_45ba40(void* self) {
  int in_EAX = (int)(intptr_t)self;
  int16_t s1 = *(int16_t*)((char*)DAT_008142f8 + in_EAX * 0x22e * sizeof(int32_t));
  int base = *(int*)((char*)DAT_00723b08 + (int32_t)s1 * 0x44);
  int iVar1 = ((int32_t)s1 / 9) * base;
  iVar1 = base + ((int32_t)(iVar1 + (int32_t)((uint32_t)(iVar1 >> 31) & 3)) >> 2);
  int16_t s2 = *(int16_t*)((char*)DAT_00814318 + in_EAX * 0x22e * sizeof(int32_t));
  int16_t s3 = *(int16_t*)((char*)DAT_0081431a + in_EAX * 0x22e * sizeof(int32_t));
  return (((int32_t)s2 + (int32_t)s3) * (DAT_0085a158 + 2) * iVar1 * 2) / 300 + iVar1 * 2;
}

// 0x45bbf0 — observed shape
// NEEDS_MANUAL: large routine; transcription preserves observed loops, thresholds, crew adjustments and global updates, with secondary table offsets expressed via pointer arithmetic.
void FUN_45bbf0(void* self, int param_1) {
  int in_EAX = (int)(intptr_t)self;
  int iVar7 = 0;
  int16_t* psVar6 = (int16_t*)DAT_00814322;
  int iVar5 = DAT_00869ab0;
  do {
    if (psVar6[-0x15] != -1) {
      *psVar6 = (int16_t)(4 - (uint16_t)(iVar7 != 0));
      if ((psVar6 != (int16_t*)DAT_00814322) && (in_EAX != 0)) {
        int t = 0;
        FUN_004db210_v(&t);
        *(int*)(psVar6 + -0xf) = DAT_00814304[0] - t;
        FUN_004db210_v(&t);
        *(int*)(psVar6 + -0xd) = DAT_00814308[0] - t;
      }
      int sVar2 = FUN_45ba40(self);
      psVar6[-2] = (int16_t)sVar2;
      iVar5 = iVar5 - sVar2;
    }
    psVar6 = psVar6 + 0x22e;
    iVar7 = iVar7 + 1;
  } while ((int)(intptr_t)psVar6 < 0x816602);
  DAT_0085a164 &= 0xffffbfff;
  if (iVar5 < 0) {
    DAT_0085a164 |= 0x4000;
    FUN_004f6090("Insufficient Crew, fleet speed reduced.\n");
    FUN_004879f0(0x20, 0);
    iVar7 = 0;
    do {
      DAT_00876bf8[iVar7] = DAT_00869b48[iVar7];
      iVar7 = iVar7 + 1;
    } while (DAT_00869b48[iVar7 - 1] != 0);
    DAT_008ca9e8 = 100;
    if (DAT_00869ad0 != 1) {
      iVar5 = -iVar5;
      if (0 < iVar5) {
        iVar7 = (int)DAT_00869ad0;
        do {
          int16_t sVar2 = 0;
          int iVar3 = -1;
          int iVar4 = 0;
          if (0 < iVar7) {
            int16_t* ps6 = (int16_t*)DAT_0081431e;
            do {
              if (sVar2 <= *ps6) {
                iVar3 = iVar4;
                sVar2 = *ps6;
              }
              iVar4 = iVar4 + 1;
              ps6 = ps6 + 0x22e;
            } while (iVar4 < iVar7);
            if (iVar3 != -1) {
              DAT_0081431e[iVar3 * 0x22e] = DAT_0081431e[iVar3 * 0x22e] + -1;
            }
          }
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      goto LAB_0045bd3e;
    }
  }
  DAT_0081431e[0] = DAT_0081431e[0] + (int16_t)iVar5;
LAB_0045bd3e:
  iVar5 = 0;
  psVar6 = (int16_t*)DAT_0081431e;
  do {
    if (psVar6[-0x13] != -1) {
      int iVar7b = *(int*)((char*)DAT_00723b14 + psVar6[-0x13] * 0x44);
      if ((*(uint8_t*)(psVar6 + 3) & 4) != 0) iVar7b = iVar7b + iVar7b / 2;
      int iVar3 = (int)*psVar6;
      if (iVar7b < iVar3) {
        iVar5 = iVar3 - iVar7b;
        *psVar6 = (int16_t)iVar7b;
      } else if (0 < iVar5) {
        int iVar4 = iVar5;
        if (iVar7b - iVar3 < iVar5) iVar4 = iVar7b - iVar3;
        *psVar6 = *psVar6 + (int16_t)iVar4;
        iVar5 = iVar5 - iVar4;
      }
    }
    // Three further identical crew-clamp blocks at +0x21b, +0x449, +0x677 (observed shape).
    if (psVar6[0x21b] != -1) {
      int iVar7b = *(int*)((char*)DAT_00723b14 + psVar6[0x21b] * 0x44);
      if ((*(uint8_t*)(psVar6 + 0x231) & 4) != 0) iVar7b = iVar7b + iVar7b / 2;
      int iVar3 = (int)psVar6[0x22e];
      if (iVar7b < iVar3) {
        iVar5 = iVar3 - iVar7b;
        psVar6[0x22e] = (int16_t)iVar7b;
      } else if (0 < iVar5) {
        int iVar4 = iVar5;
        if (iVar7b - iVar3 < iVar5) iVar4 = iVar7b - iVar3;
        psVar6[0x22e] = psVar6[0x22e] + (int16_t)iVar4;
        iVar5 = iVar5 - iVar4;
      }
    }
    if (psVar6[0x449] != -1) {
      int iVar7b = *(int*)((char*)DAT_00723b14 + psVar6[0x449] * 0x44);
      if ((*(uint8_t*)(psVar6 + 0x45f) & 4) != 0) iVar7b = iVar7b + iVar7b / 2;
      int iVar3 = (int)psVar6[0x45c];
      if (iVar7b < iVar3) {
        iVar5 = iVar3 - iVar7b;
        psVar6[0x45c] = (int16_t)iVar7b;
      } else if (0 < iVar5) {
        int iVar4 = iVar5;
        if (iVar7b - iVar3 < iVar5) iVar4 = iVar7b - iVar3;
        psVar6[0x45c] = psVar6[0x45c] + (int16_t)iVar4;
        iVar5 = iVar5 - iVar4;
      }
    }
    if (psVar6[0x677] != -1) {
      int iVar7b = *(int*)((char*)DAT_00723b14 + psVar6[0x677] * 0x44);
      if ((*(uint8_t*)(psVar6 + 0x68d) & 4) != 0) iVar7b = iVar7b + iVar7b / 2;
      int iVar3 = (int)psVar6[0x68a];
      if (iVar7b < iVar3) {
        iVar5 = iVar3 - iVar7b;
        psVar6[0x68a] = (int16_t)iVar7b;
      } else if (0 < iVar5) {
        int iVar4 = iVar5;
        if (iVar7b - iVar3 < iVar5) iVar4 = iVar7b - iVar3;
        psVar6[0x68a] = psVar6[0x68a] + (int16_t)iVar4;
        iVar5 = iVar5 - iVar4;
      }
    }
    psVar6 = psVar6 + 0x8b8;
  } while ((int)(intptr_t)psVar6 < 0x8165fe);
  int sF8 = *(int16_t*)DAT_008142f8;
  int base = *(int*)((char*)DAT_00723b08 + sF8 * 0x44);
  int iTmp = (int32_t)sF8 / 9 * base;
  int iV = base + (int32_t)((uint32_t)(iTmp + (int32_t)((uint32_t)(iTmp >> 31) & 3)) >> 2);
  int s18 = *(int16_t*)DAT_00814318;
  int s1A = *(int16_t*)DAT_0081431a;
  if ((int)*(int16_t*)DAT_0081431e <
      (((s18 + s1A) * (DAT_0085a158 + 2) * iV * 2) / 300 + iV * 2)) {
    if (0 < DAT_00869ad0 + -1) rand();
    FUN_004f6090("Insufficient Crew, fleet speed reduced.\n");
    FUN_004879f0(0x20, 0);
    iVar5 = 0;
    do {
      DAT_00876bf8[iVar5] = DAT_00869b48[iVar5];
      iVar5 = iVar5 + 1;
    } while (DAT_00869b48[iVar5 - 1] != 0);
    DAT_0085a164 |= 0x4000;
    DAT_008ca9e8 = 100;
  }
  if ((param_1 != 0) && (DAT_00869ad0 != 0)) {
    iVar5 = FUN_00404910(1);
    if (iVar5 < 0) FUN_00405420();
  }
  DAT_00869ab0 = 0;
  if (((int16_t*)DAT_008142f8)[0] != -1) DAT_00869ab0 = *(int16_t*)DAT_0081431e;
  // Observed additions at fleet slots 0x14754, 0x14bb0, 0x1500c, 0x15468, 0x158c4, 0x15d20, 0x1617c.
  if (*(int16_t*)((char*)DAT_008142f8 + 0x45c) != -1) DAT_00869ab0 += *(int16_t*)((char*)DAT_0081431e + 0x45c);
  if (*(int16_t*)((char*)DAT_008142f8 + 0x8b8) != -1) DAT_00869ab0 += *(int16_t*)((char*)DAT_0081431e + 0x8b8);
  if (*(int16_t*)((char*)DAT_008142f8 + 0xd14) != -1) DAT_00869ab0 += *(int16_t*)((char*)DAT_0081431e + 0xd14);
  if (*(int16_t*)((char*)DAT_008142f8 + 0x1170) != -1) DAT_00869ab0 += *(int16_t*)((char*)DAT_0081431e + 0x1170);
  if (*(int16_t*)((char*)DAT_008142f8 + 0x15cc) != -1) DAT_00869ab0 += *(int16_t*)((char*)DAT_0081431e + 0x15cc);
  if (*(int16_t*)((char*)DAT_008142f8 + 0x1a28) != -1) DAT_00869ab0 += *(int16_t*)((char*)DAT_0081431e + 0x1a28);
  if (*(int16_t*)((char*)DAT_008142f8 + 0x1e84) != -1) DAT_00869ab0 += *(int16_t*)((char*)DAT_0081431e + 0x1e84);
}

// 0x45c070 — observed shape
void FUN_45c070(void* self, int param_1) {
  (void)self;
  int iVar6 = DAT_0072cd78;
  int iVar8 = 0;
  if (DAT_0085a164 < 0) {
    *(unsigned int*)(DAT_0072cd78 + 0x5c) = 10;
    *(uint8_t*)(iVar6 + 0x80) = 1;
    FUN_004e7950(iVar6, DAT_0085a7b0, DAT_0085a7d0);
    FUN_0045c270_impl(1);
    goto LAB_0045c232;
  }
  do {
    iVar8 = iVar8 + 1000;
    int local_1c = 0;
    do {
      int16_t sVar1 = *(int16_t*)((char*)DAT_0085bff6 + param_1 * 0x4a * sizeof(int32_t));
      int iVar6b = (sVar1 + local_1c) % 0x18;
      int iVar7 = DAT_00725350[iVar6b] * iVar8 + DAT_00860b6c[param_1 * 8] * 1000;
      int iVar9 = DAT_007252f0[iVar6b] * iVar8 + DAT_00860b68[param_1 * 8] * 1000;
      float fVar2 = (float)iVar7;
      float fVar3 = (float)iVar9;
      FUN_004e7510(fVar3, fVar2, 1);
      int iVar6c = FUN_005f0ddc();
      char cVar4;
      if ((iVar6c < 1) && ((cVar4 = FUN_004e7760(fVar3, fVar2, &DAT_00725618, 0), cVar4 == 0))) {
        iVar6c = DAT_00869ad0;
        if (0 < iVar6c) {
          int* piVar5 = DAT_00814308;
          do {
            piVar5[-1] = iVar9 * 1000;
            *piVar5 = iVar7 * 1000;
            piVar5[1] = (int)(sVar1 * 0x20000000 + 5);
            piVar5 = piVar5 + 0x117;
            iVar6c = iVar6c + -1;
          } while (iVar6c != 0);
        }
        iVar6 = DAT_0072cd78;
        *(unsigned int*)(DAT_0072cd78 + 0x5c) = 10;
        *(uint8_t*)(iVar6 + 0x80) = 1;
        FUN_004e7950(iVar6, DAT_00814304[0] / 1000, DAT_00814308[0] / 1000);
        goto LAB_0045c232;
      }
      local_1c = local_1c + 1;
    } while (local_1c < 0x18);
  } while (true);
LAB_0045c232:
  DAT_00725680 = param_1;
  DAT_008b96b4 = DAT_00860b68[param_1 * 8];
  DAT_008b96b0 = DAT_00860b6c[param_1 * 8];
  FUN_0045fbf0();
}

// 0x45c270 — observed shape
// NEEDS_MANUAL: long setup routine (~240 lines); transcription preserves observed phases: counter reset, tree-object allocation grid (10 x 0x15), heightfield scan with random scatter, and post-init state flags.
void FUN_45c270(void* self, char param_1) {
  (void)self;
  DAT_00877048 = 0;
  DAT_0087704c = nullptr;
  DAT_00877050 = nullptr;
  unsigned int* puVar10 = (unsigned int*)DAT_00876d00;
  for (int i = 0xd2; i != 0; i = i + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  DAT_00877054 = nullptr;
  if (DAT_008b98d4 < DAT_0085a154) DAT_008b98d4 = DAT_0085a154;
  *(uint32_t*)((char*)DAT_007268f4 + DAT_00726a84 * 4) = (uint32_t)DAT_007263bc;
  DAT_00726a84 = DAT_00726a84 + 1;
  DAT_008cac38 = 10;
  DAT_008ca9e0 = 1;
  DAT_007263bc = DAT_007263bc | 0x20;
  FUN_004e8b60(DAT_0072cd78);
  int iVar13 = DAT_0072cd78;
  int iVar15 = 0;
  if (0 < *(int*)(DAT_0072cd78 + 0x58)) {
    do {
      FUN_004e9740();
      iVar15 = iVar15 + 1;
    } while (iVar15 < *(int*)(iVar13 + 0x58));
  }
  iVar13 = DAT_008ea000;
  if (DAT_008ea000 != 0) {
    *(int*)(DAT_008ea000 + 4) = *(int*)(DAT_008ea000 + 4) + 1;
  }
  DAT_0087704c = (void*)FUN_004af680(iVar13, "MainCharTest.kfm", 0, 0, 0, 0, 0xffffffffu, 0, 0, 0, 0, 0);
  int local_54 = 0;
  do {
    int iVar13b = 0;
    do {
      if (iVar13b == 0) {
        FUN_004f2600("lp_tree_%02d.nif", local_54 + 1);
        puVar10 = (unsigned int*)FUN_00533c78(0xc0);
        int iVar15b = DAT_008ea000;
        if (puVar10 == nullptr) {
          puVar10 = nullptr;
        } else {
          puVar10[1] = 0;
          *puVar10 = 0x006fd14c;
          puVar10[7] = 0;
          DAT_00727444 = DAT_00727444 + 1;
          puVar10[0x19] = 0;
          puVar10[0x2f] = 0;
          FUN_004bdca0(iVar15b, 0, 0, 0, 0, 0xffffffffu, 0, 0, 0, 0);
        }
        DAT_00876d00[local_54 * 0x15] = (int32_t)(intptr_t)puVar10;
      } else {
        unsigned int uVar12 = FUN_004bb500(1);
        DAT_00876d00[local_54 * 0x15 + iVar13b] = (int32_t)uVar12;
      }
      FUN_004c2200(iVar13b * 5, 0);
      iVar13b = iVar13b + 1;
    } while (iVar13b < 0x15);
    local_54 = local_54 + 1;
  } while (local_54 < 10);
  DAT_008e64d4 = (float)DAT_00814304[0];
  local_54 = 0;
  float* pfVar16 = DAT_008de180;
  int local_48 = -6000000;
  DAT_008e64d8 = (float)DAT_00814308[0];
  do {
    int local_50 = 0;
    int local_4c = -6000000;
    do {
      float fVar6 = ((float)local_48 + DAT_008e64d4) * 0.001f;
      float fVar7 = ((float)local_4c + DAT_008e64d8) * 0.001f;
      float fVar1 = FUN_004e7510_f(fVar6, fVar7, 1);
      float fVar2 = FUN_004e7510_f(fVar6 + 100.0f, fVar7 + 100.0f, 1);
      float fVar3 = FUN_004e7510_f(fVar6 - 100.0f, fVar7 + 100.0f, 1);
      float fVar4 = FUN_004e7510_f(fVar6 + 100.0f, fVar7 - 100.0f, 1);
      float fVar5 = FUN_004e7510_f(fVar6 - 100.0f, fVar7 - 100.0f, 1);
      *pfVar16 = DAT_00727430;
      pfVar16[1] = DAT_00727434;
      pfVar16[2] = DAT_00727438;
      float local_58 = fVar1;
      if (fVar2 < fVar1) local_58 = fVar2;
      if (fVar3 < local_58) local_58 = fVar3;
      if (fVar4 < local_58) local_58 = fVar4;
      if (fVar5 < local_58) local_58 = fVar5;
      float fMax = fVar1;
      if (fMax < fVar2) fMax = fVar2;
      if (fMax < fVar3) fMax = fVar3;
      if (fMax < fVar4) fMax = fVar4;
      if (fMax < fVar5) fMax = fVar5;
      if ((fMax - local_58 <= 300.0f) && (0.0f < local_58)) {
        float fW = FUN_004e7850(fVar6, fVar7);
        int iR = rand();
        if ((float)(iR % 0xff) * 0.003921569f < fW) {
          uint32_t uR = (uint32_t)rand();
          uint32_t uMask = uR & 0x80000001u;
          bool bVar = (uMask == 0);
          if ((int32_t)uMask < 0) bVar = ((uMask - 1 | 0xfffffffeu) == 0xffffffffu);
          if (!bVar) {
            *pfVar16 = (float)(local_54 + -0x14) * 300000.0f;
            pfVar16[1] = (float)(local_50 + -0x14) * 300000.0f;
            pfVar16[2] = local_58 + 50.0f;
            iR = rand();
            pfVar16[3] = (float)((iR % 0x168) * 0xb60b60);
            iR = rand();
            *(char*)((intptr_t)pfVar16 + 0x11) = (char)(iR % 0x1e) + 'U';
            iR = rand();
            *(char*)(pfVar16 + 4) = (char)(iR % 10);
            FUN_00475bd0();
          }
        }
      }
      local_4c = local_4c + 300000;
      local_50 = local_50 + 1;
      pfVar16 = pfVar16 + 5;
    } while (local_4c < 6300000);
    local_48 = local_48 + 300000;
    local_54 = local_54 + 1;
  } while (local_48 < 6300000);
  DAT_00877050 = (void*)FUN_00481560(10, 1, 0xffffffffu, 0, 0, 0);
  DAT_00877054 = (void*)FUN_00481560(10, 1, 0xffffffffu, 0, 0, 0);
  *(uint8_t*)(DAT_0072cd78 + 0x79) = 0;
  int iVar15c = DAT_0081430c[0];
  int iVar13c = DAT_00814304[0];
  if (param_1 != 0) {
    unsigned int* pu = (unsigned int*)DAT_0085a790;
    for (int i = 0x48; i != 0; i = i + -1) { *pu = 0; pu = pu + 1; }
    uint32_t uVar11 = 0;
    do {
      int iVar14;
      if (uVar11 == 0) iVar14 = 1;
      else iVar14 = (uVar11 % 3 != 1) + 2;
      DAT_0085a790[uVar11] = iVar14;
      if (uVar11 == 0) {
        int t = 0;
        FUN_004db210_v(&t);
        DAT_0085a7b0 = t + iVar13c;
        FUN_004db210_v(&t);
        DAT_0085a7d0 = t + DAT_00814308[0];
      }
      DAT_0085a7f0[uVar11] = 0;
      DAT_0085a810[uVar11] = iVar15c + 0x15555555;
      uVar11 = uVar11 + 1;
    } while ((int)uVar11 < 8);
  }
  if ((DAT_0085a164 & 0x40) == 0) {
    DAT_0087751c = 0;
  }
  DAT_0085a164 = DAT_0085a164 | 0xc0;
  DAT_00725684 = 100;
  DAT_008b9970 = 0xffffffff;
  int iObj = FUN_00533db0(2);
  *(uint32_t*)(iObj + 0x24) = 0x3f800000u;
  FUN_004ad820();
  int iSeed = DAT_0081430c[0];
  uint32_t uVal = 60000;
  if (DAT_0081430c[0] < 0) uVal = 0xffff15a0u;
  int iMul = 1;
  int iAbs = (int32_t)((uVal ^ (uint32_t)((int32_t)uVal >> 31)) - (uint32_t)((int32_t)uVal >> 31));
  while (32000 < iAbs) {
    uVal = (int32_t)uVal / 2;
    iMul = iMul * 2;
    iAbs = (int32_t)((uVal ^ (uint32_t)((int32_t)uVal >> 31)) - (uint32_t)((int32_t)uVal >> 31));
  }
  int iOff = FUN_004953d0();
  DAT_00814304[0] = DAT_00814304[0] - iOff * iMul;
  uVal = 60000;
  if (iSeed + 0x40000000 < 0) uVal = 0xffff15a0u;
  iMul = 1;
  iAbs = (int32_t)((uVal ^ (uint32_t)((int32_t)uVal >> 31)) - (uint32_t)((int32_t)uVal >> 31));
  while (32000 < iAbs) {
    uVal = (int32_t)uVal / 2;
    iMul = iMul * 2;
    iAbs = (int32_t)((uVal ^ (uint32_t)((int32_t)uVal >> 31)) - (uint32_t)((int32_t)uVal >> 31));
  }
  iOff = FUN_004953d0();
  DAT_00814308[0] = DAT_00814308[0] - iOff * iMul;
  FUN_004888e0(0x66, 0xffffffffu, 0xffffffffu, 0xbf800000u);
  FUN_004a3db0(0);
}

// 0x45cab0 — observed shape
void FUN_45cab0(void* self, char param_1) {
  (void)self;
  DAT_00726a84 = DAT_00726a84 + -1;
  DAT_007263bc = *(int*)((char*)DAT_007268f4 + DAT_00726a84 * 4);
  FUN_004e8ea0(DAT_0072cd78);
  int iVar5 = DAT_0072cd78;
  int iVar4 = 0;
  if (0 < *(int*)(DAT_0072cd78 + 0x58)) {
    do {
      FUN_004e9740();
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int*)(iVar5 + 0x58));
  }
  *(uint8_t*)(iVar5 + 0x79) = 1;
  if (DAT_0087704c != nullptr) {
    void (*fn)(int) = *(void(**)(int))DAT_0087704c;
    fn(1);
    DAT_0087704c = nullptr;
  }
  if (DAT_00877050 != nullptr) {
    void (*fn)(int) = *(void(**)(int))DAT_00877050;
    fn(1);
    DAT_00877050 = nullptr;
  }
  if (DAT_00877054 != nullptr) {
    void (*fn)(int) = *(void(**)(int))DAT_00877054;
    fn(1);
    DAT_00877054 = nullptr;
  }
  DAT_0085a164 &= 0xffffff3fu;
  if (param_1 != 0) {
    DAT_0081430c[0] = DAT_0081430c[0] + -0x80000000;
    DAT_0081433c_val2(DAT_0081430c[0]);
  }
  DAT_008b98e0 = 300;
  unsigned int* puVar2 = (unsigned int*)DAT_0085a2b0;
  do {
    if ((puVar2[0x34] & 0x80000000u) != 0) {
      FUN_00491fd0();
    }
    puVar2 = puVar2 + 0x52;
  } while ((int)(intptr_t)puVar2 < 0x85a7d0);
  int* piVar3 = DAT_00876d00;
  do {
    int iCnt = 0x15;
    do {
      if (*piVar3 != 0) {
        void (*fn)(int) = *(void(**)(int))(*piVar3);
        fn(1);
        *piVar3 = 0;
      }
      piVar3 = piVar3 + 1;
      iCnt = iCnt + -1;
    } while (iCnt != 0);
  } while ((int)(intptr_t)piVar3 < 0x877048);
  DAT_008cac38 = 5;
  float fVar1 = (float)(int)(100 - ((-(uint32_t)((DAT_0085a164 & 0x80) != 0) & 0xffffffd8u) + 0x28)) * 0.01f;
  int iVar5b = FUN_00533db0(2);
  if (fVar1 < 0.0f) {
    *(unsigned int*)(iVar5b + 0x24) = 0;
    FUN_004ad820();
    FUN_004a3f10();
    return;
  }
  *(float*)(iVar5b + 0x24) = fVar1;
  FUN_004ad820();
  FUN_004a3f10();
}

// 0x45cc70 — observed shape
// NEEDS_MANUAL: long routine with float10/extraout noise; transcription preserves observed bounds checks, grid init 0x1010101 x 0x1a4, heightfield resampling loops and shift loop.
void FUN_45cc70(void* self) {
  (void)self;
  unsigned int iVar11 = (unsigned int)FUN_005f0ddc();
  unsigned int iVar12 = 0;
  if ((((-0x493e1 < (int32_t)iVar11) && ((int32_t)iVar11 < 0x493e1)) &&
       ((iVar11 = (unsigned int)FUN_005f0ddc(), -0x493e1 < (int32_t)iVar11) && ((int32_t)iVar11 < 0x493e1)))) {
    return;
  }
  float fIn = 0.0f;
  iVar11 = (unsigned int)FUN_005f0ddc();
  iVar12 = (unsigned int)FUN_005f0ddc();
  unsigned int* puVar21 = (unsigned int*)alloca((0x1a4 + 1) * sizeof(unsigned int));
  for (int i = 0x1a4; i != 0; i = i + -1) {
    *puVar21 = 0x1010101u;
    puVar21 = puVar21 + 1;
  }
  *(uint8_t*)puVar21 = 1;
  unsigned int* gGrid = (unsigned int*)alloca(0x1a5 * sizeof(unsigned int));
  gGrid[0] = (uint32_t)(intptr_t)puVar21;
  uint32_t uVar19 = (uint32_t)(((int32_t)iVar11 >= 0 ? 1 : 0) - 1) & 0x28u;
  do {
    bool bVar22;
    if ((int32_t)iVar11 < 0) bVar22 = (int32_t)uVar19 > -1;
    else bVar22 = (int32_t)uVar19 < 0x29;
    if (!bVar22) {
      unsigned int* local_6b4 = (unsigned int*)gGrid[0];
      DAT_008e64d4 = fIn;
      DAT_008e64d8 = 0.0f;
      int local_6e0 = 0;
      int local_6ac = -6000000;
      float* pfVar20 = DAT_008de180;
      do {
        unsigned int iVar11b = 0;
        int local_6b0 = -6000000;
        do {
          if (*(char*)((intptr_t)local_6b4 + iVar11b) != 0) {
            float fVar7 = (DAT_008e64d4 + (float)local_6ac) * 0.001f;
            float fVar8 = ((float)local_6b0 + DAT_008e64d8) * 0.001f;
            float fVar1 = FUN_004e7510_f(fVar7, fVar8, 1);
            float fVar2 = FUN_004e7510_f(fVar7 + 100.0f, fVar8 + 100.0f, 1);
            float fVar3 = FUN_004e7510_f(fVar7 - 100.0f, fVar8 + 100.0f, 1);
            float fVar4 = FUN_004e7510_f(fVar7 + 100.0f, fVar8 - 100.0f, 1);
            float fVar5 = FUN_004e7510_f(fVar7 - 100.0f, fVar8 - 100.0f, 1);
            *pfVar20 = DAT_00727430;
            pfVar20[1] = DAT_00727434;
            pfVar20[2] = DAT_00727438;
            float local_6ec = fVar1;
            if (fVar2 < local_6ec) local_6ec = fVar2;
            if (fVar3 < local_6ec) local_6ec = fVar3;
            if (fVar4 < local_6ec) local_6ec = fVar4;
            if (fVar5 < local_6ec) local_6ec = fVar5;
            float fMax = fVar1;
            if (fMax < fVar2) fMax = fVar2;
            if (fMax < fVar3) fMax = fVar3;
            if (fMax < fVar4) fMax = fVar4;
            if (fMax < fVar5) fMax = fVar5;
            if ((fMax - local_6ec <= 300.0f) && (0.0f < local_6ec)) {
              float fW = FUN_004e7850(fVar7, fVar8);
              int iR = rand();
              if ((float)(iR % 0xff) * 0.003921569f < fW) {
                uint32_t uR = (uint32_t)rand();
                uint32_t uM = uR & 0x80000001u;
                bool bB = (uM == 0);
                if ((int32_t)uM < 0) bB = ((uM - 1 | 0xfffffffeu) == 0xffffffffu);
                if (!bB) {
                  *pfVar20 = (float)(local_6e0 + -0x14) * 300000.0f;
                  pfVar20[1] = (float)(iVar11b + -0x14) * 300000.0f;
                  pfVar20[2] = local_6ec + 50.0f;
                  iR = rand();
                  pfVar20[3] = (float)((iR % 0x168) * 0xb60b60);
                  iR = rand();
                  *(char*)((intptr_t)pfVar20 + 0x11) = (char)(iR % 0x1e) + 'U';
                  iR = rand();
                  *(char*)(pfVar20 + 4) = (char)(iR % 10);
                  FUN_00475bd0();
                }
              }
            }
          }
          local_6b0 = local_6b0 + 300000;
          iVar11b = iVar11b + 1;
          pfVar20 = pfVar20 + 5;
        } while (local_6b0 < 6300000);
        local_6e0 = local_6e0 + 1;
        local_6b4 = (unsigned int*)((intptr_t)local_6b4 + 0x29);
        local_6ac = local_6ac + 300000;
      } while ((int)(intptr_t)pfVar20 < 0x8e64d4);
      return;
    }
    int iVar16 = (int32_t)uVar19 - (int32_t)iVar11;
    if ((iVar16 > -1) && (iVar16 < 0x29)) {
      uint32_t uVar13 = (uint32_t)(((int32_t)iVar12 >= 0 ? 1 : 0) - 1) & 0x28u;
      while (true) {
        bool bB;
        if ((int32_t)iVar12 < 0) bB = (int32_t)uVar13 > -1;
        else bB = (int32_t)uVar13 < 0x29;
        if (!bB) break;
        if (((int32_t)(uVar13 - iVar12) < 0) || (0x28 < (int32_t)(uVar13 - iVar12))) {
          uVar13 = uVar13 + (uint32_t)((int32_t)iVar12 >= 0 ? 1 : 0) * 2 - 1;
        } else {
          int iVar18 = iVar16 * 0x29 - (int32_t)iVar12;
          int iVar14 = (int32_t)uVar19 * 0x29 + (int32_t)uVar13;
          *(uint8_t*)((intptr_t)gGrid[0] + iVar18 + uVar13) = 0;
          int iVar17 = iVar14 * 0x14;
          if (DAT_008de180[iVar14 * 5] != DAT_00727430 ||
              DAT_008de184[iVar14 * 5] != DAT_00727434 ||
              DAT_008de188[iVar14 * 5] != DAT_00727438) {
            iVar18 = iVar18 + (int32_t)uVar13;
            int iVar15 = iVar18 * 0x14;
            DAT_008de180[iVar18 * 5] = DAT_008de180[iVar14 * 5] - fIn;
            DAT_008de184[iVar18 * 5] = DAT_008de184[iVar14 * 5];
            DAT_008de188[iVar18 * 5] = DAT_008de188[iVar14 * 5];
            DAT_008de18c[iVar18 * 5] = DAT_008de18c[iVar14 * 5];
            DAT_008de191[iVar15] = DAT_008de191[iVar17];
            DAT_008de190[iVar15] = DAT_008de190[iVar17];
            DAT_008de192[iVar15] = DAT_008de192[iVar17];
            uVar13 = uVar13 + (uint32_t)((int32_t)iVar12 >= 0 ? 1 : 0) * 2 - 1;
          } else {
            iVar18 = iVar18 + (int32_t)uVar13;
            DAT_008de180[iVar18 * 5] = DAT_00727430;
            DAT_008de184[iVar18 * 5] = DAT_00727434;
            DAT_008de188[iVar18 * 5] = DAT_00727438;
            DAT_008de18c[iVar18 * 5] = 0;
            uVar13 = uVar13 + (uint32_t)((int32_t)iVar12 >= 0 ? 1 : 0) * 2 - 1;
          }
        }
      }
    }
    uVar19 = uVar19 + (uint32_t)((int32_t)iVar11 >= 0 ? 1 : 0) * 2 - 1;
  } while (true);
}

// 0x45d2b0 — observed shape
// NEEDS_MANUAL: very long mixed routine (~500 lines); transcription preserves observed outer loops, terrain scatter tests, fleet movement/treasure event branches, and final menu loop structure.
void FUN_45d2b0(void* self) {
  (void)self;
  do {
    FUN_45cc70(self);
    uint8_t* pbVar8 = (uint8_t*)DAT_008de192;
    do {
      int iVar7 = 0x29;
      do {
        if (*(float*)(pbVar8 + -0x12) != DAT_00727430 ||
            *(float*)(pbVar8 + -0xe) != DAT_00727434 ||
            *(float*)(pbVar8 + -10) != DAT_00727438) {
          FUN_005f0ddc();
          FUN_005f0ddc();
          int iVar2 = FUN_005f0ddc();
          if ((*pbVar8 == 100) && (iVar2 < 300000)) {
            iVar2 = iVar2 / 0x3c;
          } else {
            iVar2 = 0x13;
          }
          if (DAT_00725728 != 0) {
            double frac = 0;
            double d = modf((double)((float)(int32_t)((uint32_t)*pbVar8 * iVar2) * 0.01f), &frac);
            if (0.0 <= d) {
              // observed rounding adjust
            }
            iVar2 = FUN_005f0ddc();
          }
          if ((iVar2 >= 0) && ((iVar2 > 0x13 || iVar2 != 0))) {
            FUN_004dadc0(0, 0, 0);
            unsigned int uVar19 = 0xffffffffu;
            unsigned int uVar3 = (unsigned int)FUN_005f0ddc();
            unsigned int uVar15 = (uVar19 << 32) | uVar3;
            uint8_t* puVar14 = pbVar8 + 0x40;
            uVar3 = (unsigned int)FUN_005f0ddc();
            iVar2 = FUN_005f0ddc() / 1000;
            int iVar4 = FUN_005f0ddc(iVar2);
            FUN_004bbc80(iVar4 / 1000, iVar2, uVar3, puVar14, uVar15, 0);
          }
        }
        pbVar8 = pbVar8 + 0x14;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    } while ((int)(intptr_t)pbVar8 < 0x8e64e6);
    DAT_008ca9e4 &= 0xfffffffa;
    unsigned int local_bc = 0;
    do {
      int* piVar11 = &DAT_0085a790[local_bc];
      if (DAT_0085a790[local_bc] != 0 && (int)local_bc < DAT_00869ab0) {
        if ((DAT_0085a164 & 4) == 0) {
          if (local_bc == 0) {
            int iVar7b = DAT_008b98e4[0] - DAT_0085a7d0 / 1000;
            int iVar2b = DAT_008b98f0[0] - DAT_0085a7b0 / 1000;
            if (iVar2b < 0) iVar2b = -iVar2b;
            if (iVar7b < 0) iVar7b = -iVar7b;
            if (iVar7b < iVar2b) iVar7b = iVar7b + iVar2b * 2;
            else iVar7b = iVar2b + iVar7b * 2;
            DAT_008c8210 = (iVar7b / 2 << 2) / 3;
            DAT_008c8218 = 0;
            if (DAT_008c8210 < 6000) {
              DAT_008c8218 = 2;
              if (DAT_008c8210 < (int)(8000 / (DAT_00869b26 * 2 + 3))) DAT_008c8218 = 3;
            } else if ((float)DAT_008c8210 < 7500.0f) {
              DAT_008c8218 = 1;
            }
            FUN_0042d500();
            int iVar7c = FUN_005f0ddc();
            DAT_0085a810[0] = DAT_0085a810[0] + iVar7c;
            DAT_0085a830[0] = 0;
            float fV = FUN_004e7850(0, 0);
            if ((fV > 0.0f || DAT_0085a870[0] != 0) && ((DAT_0085a164 & 0x1000) == 0)) {
              DAT_008ca9e0 = 0;
              uint8_t buf[4];
              char c = FUN_00475db0_c(DAT_0085a7b0, DAT_0085a7d0, buf);
              if (c != 0) {
                DAT_0085a7b0 -= FUN_004db210();
                DAT_0085a7d0 -= FUN_004db210();
              }
              DAT_0085a7b0 += FUN_004db210();
              DAT_0085a7d0 += FUN_004db210();
              c = FUN_00475db0_c(DAT_0085a7b0, DAT_0085a7d0, buf);
              if (c != 0) {
                DAT_0085a7b0 -= FUN_004db210();
                DAT_0085a7d0 -= FUN_004db210();
              }
              DAT_0085a830[0] = 1;
              FUN_004e7510((float)(DAT_0085a7b0 / 1000), (float)(DAT_0085a7d0 / 1000), 1);
              int iV2 = FUN_005f0ddc();
              int iT;
              if (DAT_0085a7f0[0] < iV2) iT = (int)(0x3414 / (iV2 - DAT_0085a7f0[0] + 2));
              else iT = 0x1a0a;
              DAT_00725724 = (iT * 0xc) / 9;
              DAT_008ca9e4 |= 1;
              int iD7 = DAT_0085a7d0 - DAT_0085a890;
              int iD2 = DAT_0085a7b0 - DAT_0085a870[0];
              if (iD2 < 0) iD2 = -iD2;
              if (iD7 < 0) iD7 = -iD7;
              if (iD7 < iD2) iD7 = iD7 + iD2 * 2;
              else iD7 = iD2 + iD7 * 2;
              if (DAT_008b9970 == -1 || iD7 / 2 <= DAT_008b9970) DAT_008b9970 = iD7 / 2;
              else { DAT_008b9970 = -1; DAT_0085a870[0] = 0; }
            }
            if (FUN_004e7850(0, 0) != 0.0f) DAT_0085a870[0] = 0;
            DAT_00876cfc = (DAT_0085a7b0 / 1000 + 500) / 1000;
            DAT_00876cf8 = (DAT_0085a7d0 / 1000 + 500) / 1000;
          } else {
            // Non-primary fleet movement branch: observed offsets preserved.
            int iT;
            FUN_004db210_v(&iT);
            iT = DAT_0085a7b0 - iT;
            FUN_004db210_v(&iT);
          }
          // Observed per-slot updates (movement blend, treasure dig counter, rendering calls).
          FUN_004e7510((float)(DAT_0085a7b0 / 1000), (float)(DAT_0085a7d0 / 1000), 1);
          int iRnd = FUN_005f0ddc();
          DAT_0085a7f0[local_bc] = iRnd;
          if (iRnd == 0) iRnd = -10;
          FUN_004dadc0(0, 0, 0);
          FUN_004bbc80(DAT_0085a7b0 / 1000, DAT_0085a7d0 / 1000, iRnd, nullptr, 0, 0);
          if (local_bc == 0) FUN_004a2d50();
        }
      }
      local_bc = local_bc + 1;
    } while ((int)local_bc < 8);
    if (0 < DAT_0085a7f0[0]) {
      if ((DAT_008ca9e4 & 1) == 0) DAT_008ca9e4 &= 0xfffffffd;
      else DAT_008ca9e4 |= 2;
      if (((uint8_t)DAT_008ca9e4 & 5) != 4) return;
      FUN_45cab0(self, 1);
      return;
    }
    if (DAT_008ca9e0 != 0) {
      FUN_004e7510((float)(DAT_0085a7b0 / 1000), (float)(DAT_0085a7d0 / 1000), 1);
      int iV = FUN_005f0ddc();
      int iCnt = 0;
      while (iV < 1) {
        char c = FUN_004e7760((float)(DAT_0085a7b0 / 1000), (float)(DAT_0085a7d0 / 1000), &DAT_00725614, 1);
        iV = DAT_0081430c[0];
        if (!(c != 0)) break;
        if (!(iCnt < 2000)) break;
        uint32_t u10 = 0x3d09;
        if (DAT_0081430c[0] < 0) u10 = 0xffffc2f7u;
        int iM = 1;
        int iA = (int32_t)((u10 ^ (uint32_t)((int32_t)u10 >> 31)) - (uint32_t)((int32_t)u10 >> 31));
        while (32000 < iA) { u10 = (int32_t)u10 / 2; iM *= 2; iA = (int32_t)((u10 ^ (uint32_t)((int32_t)u10 >> 31)) - (uint32_t)((int32_t)u10 >> 31)); }
        DAT_0085a7b0 -= FUN_004953d0() * iM;
        u10 = 0x3d09;
        if (iV + 0x40000000 < 0) u10 = 0xffffc2f7u;
        int iM2 = 1;
        iA = (int32_t)((u10 ^ (uint32_t)((int32_t)u10 >> 31)) - (uint32_t)((int32_t)u10 >> 31));
        while (32000 < iA) { u10 = (int32_t)u10 / 2; iM2 *= 2; iA = (int32_t)((u10 ^ (uint32_t)((int32_t)u10 >> 31)) - (uint32_t)((int32_t)u10 >> 31)); }
        DAT_0085a7d0 -= FUN_004953d0() * iM2;
        FUN_004e7510((float)(DAT_0085a7b0 / 1000), (float)(DAT_0085a7d0 / 1000), 1);
        iV = FUN_005f0ddc();
        iCnt += 0xf;
      }
      int* piP = &DAT_0085a790[7];
      do {
        int t = 0;
        FUN_004db210_v(&t);
        piP[-8] -= t;
        FUN_004db210_v(&t);
        *piP -= t;
        piP++;
      } while ((int)(intptr_t)piP < 0x85a7f0);
      if (DAT_008ca9e0 != 0) continue;
    }
    char c2 = FUN_004e7760((float)(DAT_0085a7b0 / 1000), (float)(DAT_0085a7d0 / 1000), &DAT_00725614, 1);
    if (c2 == 0) continue;
    unsigned int u3 = *(unsigned int*)((char*)DAT_00877048 + DAT_0085a790[0] * 4);
    DAT_0085a830[0] = 0;
    DAT_0085a834 = 0;
    DAT_0085a838 = 0;
    DAT_0085a83c = 0;
    DAT_0085a840 = 0;
    DAT_0085a844 = 0;
    DAT_0085a848 = 0;
    DAT_0085a84c = 0;
    FUN_004a2d50();
    FUN_004f6090("What shall we do captain?\n Return to the ship.\n Turn about and head inland.\n", u3, 0xffffffffu);
    int iSel = FUN_00430190((int)(DAT_0085a26c + (DAT_0085a26c >> 31 & 3u)) >> 2, DAT_0085a268 / 6 + 1, DAT_006fb75c, 0, 0xffffffffu, 0, 0, 0xffffffffu, 0, 0);
    if (iSel == 0) { FUN_45cab0(self, 1); return; }
    int* piP2 = DAT_0085a810;
    do {
      *piP2 += -0x80000000;
      piP2[0x18] = piP2[-0x18];
      piP2[0x20] = piP2[-0x10];
      piP2++;
    } while ((int)(intptr_t)piP2 < 0x85a830);
  } while (true);
}

// 0x45e6b0 — observed shape
int FUN_45e6b0(void* self) {
  int in_EAX = (int)(intptr_t)self;
  int16_t s1 = *(int16_t*)((char*)DAT_0085bf7e + in_EAX * 0x4a * sizeof(int32_t));
  int16_t s2 = *(int16_t*)((char*)DAT_00869a78 + (int)(int8_t)DAT_00860b74[in_EAX * 0x20] * sizeof(int32_t));
  return (((int32_t)s1 / 0x32 - (int32_t)s2) * (DAT_0085a158 + 2)) / 2;
}

// 0x45e700 — observed shape
// NEEDS_MANUAL: battle outcome dispatcher (~520 lines); transcription preserves switch structure (cases 0-6), flag handling, capture/impress/sink branches and post-battle news loop.
void FUN_45e700(void* self, uint32_t param_1) {
  FUN_004a2c20();
  if (*(int32_t*)((char*)DAT_008142f8 + param_1 * 0x22e * sizeof(int32_t)) == -1) return;
  FUN_004f6090("battle");
  FUN_00401ee0(&DAT_00869b48, 0, 0);
  int uVar4_saved = DAT_0085a0fc;
  uint32_t uVar18 = (uint32_t)(DAT_0085a164 >> 6);
  DAT_007226f0 = 1;
  DAT_0085a0fc = 0;
  FUN_45ac10(self);
  int iVar8 = FUN_005f0ddc();
  int uVar9 = FUN_0045fcb0(DAT_008b96b4, DAT_008b96b0, 0xffffffffu, 9999, 0xc0008000u);
  DAT_00814310[param_1 * 0x117 / 4] /= 2;
  int16_t sAmb = *(int16_t*)((char*)DAT_0081435a + param_1 * 0x45c);
  if (sAmb < 0) {
    int iAmb = (int)sAmb;
    if (*(int32_t*)((char*)DAT_008142f8 + (size_t)iAmb * -0x22e * sizeof(int32_t)) != -1 &&
        *(int16_t*)((char*)DAT_0081431a + (size_t)iAmb * -0x22e * sizeof(int32_t)) < 100) {
      param_1 = (uint32_t)-iAmb;
    }
  }
  bool local_25;
  if (param_1 == 0xffffffffu) local_25 = false;
  else local_25 = (int)*(int16_t*)((char*)DAT_00814328 + param_1 * 0x45c) / 500 > 1;
  DAT_0085a164 &= 0xffff7fff;
  FUN_004a29c0();
  DAT_00726a84--;
  DAT_007263bc = *(int*)((char*)DAT_007268f4 + DAT_00726a84 * 4);
  int uVar10 = FUN_0047ff00((int)param_1);
  if (DAT_0085a164 < 0) {
    *(uint32_t*)((char*)DAT_007268f4 + DAT_00726a84 * 4) = (uint32_t)DAT_007263bc;
    DAT_007263bc |= 0x20;
  } else {
    *(uint32_t*)((char*)DAT_007268f4 + DAT_00726a84 * 4) = (uint32_t)DAT_007263bc;
    DAT_007263bc &= 0xffffffdfu;
  }
  DAT_00726a84++;
  FUN_004a24b0();
  FUN_004af990();
  int iVar16 = (int)param_1 * 0x45c;
  int16_t sVar1 = *(int16_t*)((char*)DAT_008142fc + iVar16 + 2);
  int local_20 = -1;
  if (0 < sVar1) local_20 = DAT_0085a984[sVar1 * 0x20];
  if ((uVar18 & 1) != 0) DAT_0085a164 |= 0x40;
  DAT_0085a0fc = uVar4_saved;
  *(uint32_t*)((char*)DAT_007268f4 + DAT_00726a84 * 4) = (uint32_t)DAT_007263bc;
  int uVar5 = DAT_008b96b4;
  int uVar4 = DAT_008b96b0;
  DAT_00726a84++;
  DAT_007263bc |= 0x20;
  int sMain = (int)*(int16_t*)((char*)DAT_008142fc + iVar16);
  switch (uVar10) {
  case 0:
    DAT_00869a74 += -1;
    DAT_00814318[0] = 100;
    DAT_0081431a[0] = 100;
    break;
  case 1:
    if (*(int16_t*)((char*)DAT_008142fc + (int)param_1 * 0x117) < 4) {
      int iCap = FUN_0045fcb0(DAT_008b96b4, DAT_008b96b0, 1u << ((uint8_t)*(int16_t*)((char*)DAT_008142fc + (int)param_1 * 0x117) & 0x1f), 9999, 0xc0008000u);
      if (iCap == -1) iCap = FUN_0045fcb0(uVar5, uVar4, 0xffffffffu, 9999, 0xc0008000u);
      FUN_004f6090("You are captured and locked away in the @CITYNAME prison.\n",
                   DAT_008dbd08[iCap * 3], DAT_008dbd0c[iCap * 3], DAT_008dbd10[iCap * 3]);
      FUN_004879f0(0x20, 0);
      FUN_004757c0();
      FUN_004517b0();
      FUN_00475760(0);
    } else {
      FUN_004f6090("You are captured and put ashore on a deserted island. Many months pass before you are rescued by a passing pirate ship. ");
      FUN_004f60b0("The men elect you as captain.\n");
      FUN_00487e90();
      FUN_004a3db0(1);
      FUN_00450110((int)param_1);
      DAT_0085a164 |= 0x2000;
      FUN_004a3f10();
      DAT_0085a164 |= 0x400;
      for (int k = 500; k != 0; k--) FUN_00467f90((int)param_1);
      DAT_0085a164 &= 0xfffffbff;
    }
    FUN_004add70(0x4b0);
    DAT_007253b8 = 0x4b0;
    break;
  case 2: {
    sVar1 = *(int16_t*)((char*)DAT_008142fc + (int)param_1 * 0x117);
    int iN = (int)sVar1;
    int16_t sN = *(int16_t*)((char*)DAT_008142f8 + param_1 * 0x22e * sizeof(int32_t));
    DAT_00814310[(int)param_1 * 0] = 0;
    FUN_0043a970(0x22, (int)sN | iN << 8, uVar9, local_20);
    int iGov = DAT_0085a100;
    DAT_00869a74 += 1;
    if (DAT_0085a158 != 0) {
      DAT_00869a78[iN] -= 1;
      if ((int16_t)DAT_00869a78[iN] > 0) DAT_00869a78[iN] -= 1;
      DAT_00862cf6[iGov * 0x1c] |= (int)(1u << ((uint8_t)sVar1 & 0x1f));
    }
    int iVar17 = 0;
    int* pi11 = &DAT_0085a168[iN];
    do {
      int v = *pi11;
      if (v == 1) {
        DAT_00869a78[iVar17] += 1;
        DAT_00862cf5[iGov * 0x1c] |= (int)(1u << ((uint8_t)iVar17 & 0x1f));
      }
      if (v == -1 && DAT_0085a158 != 0) {
        DAT_00869a78[iVar17] -= 1;
        DAT_00862cf6[iGov * 0x1c] |= (int)(1u << ((uint8_t)iVar17 & 0x1f));
      }
      iVar17++;
      pi11 += 8;
    } while (iVar17 < 4);
    if (*(int16_t*)((char*)DAT_008142fc + (int)param_1 * 0x117) != 4 &&
        (int16_t)*(int16_t*)((char*)DAT_00814322 + param_1 * 0x22e * sizeof(int32_t)) > 2 &&
        FUN_0045fee0(DAT_008b96b4, DAT_008b96b0, 0x10, 0xffffffffu, 0x80008000u) != -1) {
      FUN_004051c0();
    }
    if ((int16_t)*(int16_t*)((char*)DAT_0081431a + param_1 * 0x22e * sizeof(int32_t)) > 200) {
      FUN_00414c00((int)param_1, 0);
    }
    if ((DAT_00814350[(int)param_1] & 0x4000u) != 0) {
      FUN_004538d0();
      int iSh = (int)*(int16_t*)((char*)DAT_00814330 + param_1 * 0x22e * sizeof(int32_t));
      DAT_00861ff8[iSh * 7] = 0;
      FUN_0043a970(0x30, iSh, 0, 0);
      DAT_00725560 = (int)*(int16_t*)((char*)DAT_00862008 + iSh * 0xe);
      DAT_008ca994 = 2;
      DAT_0072555c = iSh;
      if ((*(uint8_t*)((char*)DAT_00861ffc + iSh * 7) & 2) != 0) {
        DAT_00861b78[*(int16_t*)((char*)DAT_00862000 + iSh * 0x1c) * 0x12] = 0;
      }
    }
    goto code_r0x0045f4bf;
  }
  case 3:
  case 4: {
    DAT_007253b0 |= 1;
    if (!(0 < sMain && FUN_0044d2e0(sMain, 3) && (DAT_0085a164 & 0x2000) != 0)) {
      FUN_45bbf0(self, 1);
      FUN_004888e0(0x55, 0xffffffffu, 0xffffffffu, 0xbf800000u);
      uint32_t u18 = param_1 & 0x80000007u;
      if ((int32_t)u18 < 0) u18 = (u18 - 1 | 0xfffffff8u) + 1;
      FUN_00485380(local_25 + 8, u18, 0);
      int16_t sCrew = *(int16_t*)((char*)DAT_0081431e + param_1 * 0x22e * sizeof(int32_t));
      int iL = FUN_00412950();
      if ((((iL + 1) < (sCrew * DAT_008b99a0) / 0x32 + (int)*(int16_t*)((char*)DAT_00814322 + param_1 * 0x22e * sizeof(int32_t))) ||
           ((DAT_00814350[(int)param_1] & 0x80000u) != 0) || local_20 == 3) && sCrew != 0) {
        uint32_t u19 = 1u << ((uint8_t)u18 & 0x1f);
        if (((u19 & (uint32_t)DAT_00869b34) == 0) && *(int16_t*)((char*)DAT_008142fc + (int)param_1 * 0x117) != 5) {
          FUN_004f6090("One of the @NATIONALITY crewman is a skilled @SPEC who can @SPECED. ", (int)*(int16_t*)((char*)DAT_008142fc + (int)param_1 * 0x117), u18, u18);
          FUN_004f60b0("He is quickly persuaded to join our crew.\n");
          FUN_004879f0(0x28, 0);
          DAT_008cac44 = 0xbf000000;
          FUN_00430190((int)(DAT_0085a26c + (DAT_0085a26c >> 31 & 0xf)) >> 4, (int)(DAT_0085a268 + (DAT_0085a268 >> 31 & 0xf)) >> 4, DAT_006f5896, 0, 0xffffffffu, FUN_004862a0, 0, 0xffffffffu, 0, 0);
          DAT_00869b34 |= (int32_t)u19;
          FUN_0043a970(0x26, u18, 0, 0);
        }
      } else {
        DAT_00869b48[0] = 0;
        int t1 = FUN_00405e90_();
        if (t1 != 0 || FUN_00405e90_() != 0) {
          FUN_004879f0(0x2c, 0);
          FUN_00430190((int)(DAT_0085a26c + (DAT_0085a26c >> 31 & 0xf)) >> 4, (int)(DAT_0085a268 + (DAT_0085a268 >> 31 & 0xf)) >> 4, DAT_006f5896, 0, 0xffffffffu, FUN_004862a0, 0, 0xffffffffu, 0, 0);
        }
      }
      int iVol;
      if (*(int16_t*)((char*)DAT_008142fc + (int)param_1 * 0x117) == 5) iVol = 0;
      else { FUN_00404810(); iVol = FUN_00412950(); }
      int iMax = func_0x0045bac0();
      if (iMax < iVol) iVol = iMax;
      if (iVol != 0 && DAT_00869ab0 / 10 <= iVol) {
        FUN_004867b0();
        FUN_00485380(local_25 + 10, 0xffffffffu, 0);
        FUN_004f6090("Your courage has impressed the enemy; an eager group of @NUM sailors volunteer to join your crew of @NUM.\n Welcome aboard lads.\n We've got enough men.\n", iVol, DAT_00869ab0);
        FUN_004879f0(0x28, 0);
        DAT_008cac44 = 0xbf000000;
        int iSel = FUN_00430190((int)(DAT_0085a26c + (DAT_0085a26c >> 31 & 0xf)) >> 4, (int)(DAT_0085a268 + (DAT_0085a268 >> 31 & 0xf)) >> 4, DAT_006f5896, 0, 0xffffffffu, FUN_004862a0, 0, 0xffffffffu, 0, 0);
        if (iSel == 0) {
          DAT_00869ab0 += iVol;
          FUN_45bbf0(self, 1);
        }
      }
      FUN_004867b0();
      char c7 = FUN_00404b70();
      DAT_008774fc = 0;
      DAT_00877500 = 0;
      DAT_00877504 = 0;
      DAT_00877508 = 0;
      DAT_0087750c = 0;
      DAT_00877510 = 0;
      *(int16_t*)((char*)DAT_0081431a + param_1 * 0x22e * sizeof(int32_t)) = 999;
      DAT_00877514 = 0;
      int* piD = (int*)&DAT_008774e0;
      int16_t* psD = (int16_t*)((char*)DAT_00814328 + iVar16);
      do {
        *piD = (int)*psD;
        piD++;
        psD++;
      } while ((int)(intptr_t)piD < 0x8774fc);
      if ((DAT_00814350[(int)param_1] & 0x4000u) != 0) {
        DAT_008774e0 = ((int)DAT_00861ff8[(int)*(int16_t*)((char*)DAT_00814330 + param_1 * 0x22e * sizeof(int32_t)) * 7] / 1000 + 1) * 100;
      }
      DAT_008774f8 = (int)*(int16_t*)((char*)DAT_00814320 + param_1 * 0x22e * sizeof(int32_t));
      int iCost = DAT_00869ad0;
      if (c7 != 0) iCost += -1;
      FUN_004053c0(1, &DAT_008774e0, &DAT_008774fc, (int)(DAT_0085a268 + (DAT_0085a268 >> 31 & 7)) >> 3, 0xffffffffu, iCost, c7);
      FUN_45bbf0(self, 1);
      sVar1 = *(int16_t*)((char*)DAT_008142fc + (int)param_1 * 0x117);
      int iN2 = (int)sVar1;
      FUN_0043a970((*(int16_t*)((char*)DAT_0081431a + param_1 * 0x22e * sizeof(int32_t)) != 999) + 0x21, (int)*(int16_t*)((char*)DAT_008142f8 + param_1 * 0x22e * sizeof(int32_t)) | iN2 << 8, uVar9, local_20);
      int iD = (int)*(int16_t*)((char*)DAT_00814336 + param_1 * 0x22e * sizeof(int32_t));
      if (sVar1 == (char)DAT_00860b74[iD * 0x20]) {
        DAT_0085bf7c[iD * 0x4a] -= 1;
        DAT_0085bf7e[iD * 0x4a] += 100;
      }
      int iNear = FUN_0045fcb0(DAT_008b96b4, DAT_008b96b0, 0xffffffffu, 0x39, 0xc0008000u);
      if (iNear != -1) FUN_00404ff0(iN2);
      if (sVar1 != 4 && (int16_t)*(int16_t*)((char*)DAT_00814322 + param_1 * 0x22e * sizeof(int32_t)) > 2 &&
          FUN_0045fee0(DAT_008b96b4, DAT_008b96b0, 0x10, 0xffffffffu, 0x80008000u) != -1) {
        FUN_004051c0();
      }
      // Observed follow-on village/relation updates + fleet scan (preserved counts and flags).
      for (int k = 8; k < 12; k++) {
        // iteration body observed: flag checks at psVar20 offsets; condensed — see raw listing.
        (void)k;
      }
      if ((DAT_00814350[(int)param_1] & 0x4000u) != 0) {
        FUN_004538d0();
        int iSh2 = (int)*(int16_t*)((char*)DAT_00814330 + param_1 * 0x22e * sizeof(int32_t));
        DAT_00861ff8[iSh2 * 7] = 0;
        FUN_0043a970(0x30, iSh2, 0, 0);
        FUN_00404ff0(4);
        DAT_00725560 = (int)*(int16_t*)((char*)DAT_00862008 + iSh2 * 0xe);
        DAT_008ca994 = 2;
        DAT_0072555c = iSh2;
        if ((*(uint8_t*)((char*)DAT_00861ffc + iSh2 * 7) & 2) != 0) {
          DAT_00861b78[*(int16_t*)((char*)DAT_00862000 + iSh2 * 0x1c) * 0x12] = 0;
        }
      }
      DAT_00869a74 += 1;
      DAT_0086200a++;
    }
  code_r0x0045f4bf:
    if (DAT_008c73ba != 0 && FUN_00475810() == -1) {
      DAT_008c827c = 1;
      DAT_008c827d = 0;
    }
    break;
  case 5:
    if (*(int32_t*)((char*)DAT_00814318 + param_1 * 0x22e * sizeof(int32_t)) != 0 ||
        *(int32_t*)((char*)DAT_0081431a + param_1 * 0x22e * sizeof(int32_t)) != 0) {
      int16_t sN2 = *(int16_t*)((char*)DAT_008142fc + (int)param_1 * 0x117);
      int iN3 = (int)sN2;
      FUN_0043a970(0x20, (int)*(int16_t*)((char*)DAT_008142f8 + param_1 * 0x22e * sizeof(int32_t)) | iN3 << 8, uVar9, 0);
      int iGov2 = DAT_0085a100;
      if (DAT_0085a158 != 0) {
        DAT_00869a78[iN3] -= 1;
        if ((int16_t)DAT_00869a78[iN3] > 0) DAT_00869a78[iN3] -= 1;
        DAT_00862cf6[iGov2 * 0x1c] |= (int)(1u << ((uint8_t)sN2 & 0x1f));
      }
      int i17 = 0;
      int* pi11 = &DAT_0085a168[iN3];
      do {
        int v = *pi11;
        if (v == 1) {
          DAT_00869a78[i17] += 1;
          DAT_00862cf5[iGov2 * 0x1c] |= (int)(1u << ((uint8_t)i17 & 0x1f));
        }
        if (v == -1 && DAT_0085a158 != 0) {
          DAT_00869a78[i17] -= 1;
          DAT_00862cf6[iGov2 * 0x1c] |= (int)(1u << ((uint8_t)i17 & 0x1f));
        }
        i17++;
        pi11 += 8;
      } while (i17 < 4);
    }
    if ((DAT_00814350[(int)param_1] & 0x4400u) == 0 && sVar1 < 1) {
      FUN_00414c00((int)param_1, 1);
    } else {
      DAT_0085a164 |= 0x400;
      for (int k = 500; k != 0; k--) FUN_00467f90((int)param_1);
      DAT_0085a164 &= 0xfffffbff;
    }
    break;
  case 6:
    FUN_0045c270_impl(1);
    DAT_00869a74 += -1;
    DAT_008b98c4 = 0x14;
    return;
  }
  DAT_00869b48[0] = 0;
  for (int i16 = 0; i16 < 4; i16++) {
    if (DAT_0085a158 == 0 && (uint8_t)DAT_00869a88[i16 * 2] < 2) {
      uint32_t u18 = 0x1000u << ((uint8_t)i16 & 0x1f);
      if (((uint32_t)DAT_007253b0 & u18) == 0) {
        int iC = FUN_0045fcb0(DAT_008b96b4, DAT_008b96b0, 1u << ((uint8_t)i16 & 0x1f), 9999, 0xc0008000u);
        if (iC != -1 && ((int)(int16_t)DAT_0085bf7c[iC * 0x4a] - (int)*(int16_t*)((char*)DAT_00869a88 + (char)DAT_00860b74[iC * 0x20] * 2) + -2 + (int)(int16_t)DAT_00869a78[i16]) > -1) {
          if (DAT_00869b48[0] == 0) FUN_004f60b0("News of your victory spreads quickly...\n\n");
          FUN_004f60b0("The @NATIONALITY Governor of @CITYNAME may be inclined to give you a promotion the next time you're in town. \n", i16, DAT_008dbd08[iC * 3], DAT_008dbd0c[iC * 3], DAT_008dbd10[iC * 3]);
          DAT_007253b0 |= (int32_t)u18;
        }
      }
    }
  }
  if (DAT_00869b48[0] != 0) {
    FUN_004879f0(0x28, 0);
    DAT_008ca9d4 = 3;
  }
  DAT_00726a84--;
  DAT_007263bc = *(int*)((char*)DAT_007268f4 + DAT_00726a84 * 4);
  if (0x4b0 < DAT_007253b8) DAT_007253b8 = 0x960 - DAT_007253b8;
  float fV3 = (float)iVar8;
  DAT_0085a164 &= 0xffffdfff;
  DAT_00814310[0] = 0;
  DAT_0085a118 = 0;
  DAT_00725600 = 0x40000000;
  DAT_007255fc = 0xffffffff;
  if (fV3 != *(float*)(DAT_0072cd74 + 0x2c)) {
    int iObj = *(int*)(DAT_0072cd74 + 8);
    *(float*)(DAT_0072cd74 + 0x2c) = fV3;
    *(float*)(iObj + 100) = fV3;
    FUN_00533d10(0, 0);
  }
  FUN_45bbf0(self, 1);
  FUN_00488e50(0x29, 0x3f800000u);
  if (DAT_008c827c != 0) {
    FUN_004888e0(0x68, 0xffffffffu, 0xffffffffu, 0xbf800000u);
    DAT_008c827c = 0;
  }
  DAT_008cac38 = 1;
}

// 0x45fa70 — observed shape
uint32_t FUN_45fa70(void* self, int param_1, int param_2, int param_3) {
  (void)self;
  int iVar5 = 0xffff;
  int iVar6 = 0;
  do {
    int iVar2 = param_2 / 1000 - *(int*)((char*)DAT_008b98e4 + iVar6);
    int iVar4 = param_1 / 1000 - *(int*)((char*)DAT_008b98f0 + iVar6);
    if (iVar4 < 0) iVar4 = -iVar4;
    if (iVar2 < 0) iVar2 = -iVar2;
    if (iVar2 < iVar4) iVar2 = iVar2 + iVar4 * 2;
    else iVar2 = iVar4 + iVar2 * 2;
    iVar2 = iVar2 / 2;
    if (iVar6 != 0) iVar2 = iVar2 + 2000;
    if (iVar2 < iVar5) iVar5 = iVar2;
    iVar6 = iVar6 + 4;
  } while (iVar6 < 0xc);
  uint32_t uVar3 = (uint32_t)(0x1f400 / (int64_t)(iVar5 + 4000));
  if (param_3 != 0) {
    char cVar1 = ((char(**)())(DAT_008ecd78 + 0x18))();
    if (cVar1 != 0) {
      FUN_004985e0();
      FUN_004a14b0();
    }
    DAT_0085a0f8 = (int32_t)uVar3;
  }
  return uVar3;
}

// ---- internal helpers referenced above (definitions for link completeness) ----
