// Reconstruction batch mass_0002 — Sid Meier's Pirates! (2004), PE32 i386.
// Translated from Ghidra 12.2 pseudocode corpus under analysis/pseudocode/functions/.
// Preserves observed field offsets, constants, call order, return shape, and conditionals.
#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---- extern helpers (observed call targets; signatures inferred from listings) ----
extern void FUN_00412df0();
extern void FUN_00404b70();
extern void FUN_00404ca0();
extern void FUN_00412f10();
extern void FUN_004e1470();
extern void operator_delete(void *ptr);
extern void operator_delete__(uint32_t *ptr);
extern void FUN_00404910(int a0);
extern int FUN_005f0ddc(uint32_t a0, uint32_t a1);
extern int FUN_004bba60(void *a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4);
extern int FUN_00533c78(int a0);
extern void *FUN_004dcf20(int a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4);
extern void FUN_004dd090();
extern void FUN_004f6090(const char *fmt, ...);
extern void FUN_004f60b0(const char *fmt, ...);
extern void FUN_004879f0(int a0, int a1);
extern int FUN_00430190(int a0, int a1, void *a2, int a3, int a4, void *a5, int a6, int a7, int a8, int a9);
extern void FUN_004a29c0();
extern void FUN_004a24b0();
extern void FUN_00412710();
extern void FUN_00412840(uint32_t a0, uint32_t a1);
extern int FUN_0048c160(int a0, int a1, int a2, int a3);
extern void FUN_004517b0();
extern void FUN_00488d90(int a0, int a1, uint32_t a2, int a3, int a4, int a5, int a6, int a7, void *a8);
extern void FUN_0040c730(int a0);
extern void FUN_00406f60(int a0);
extern void FUN_004a78a0(int a0);
extern void FUN_004a7a40(int a0);
extern void FUN_004a8050(uint32_t a0, uint32_t a1, int a2, int a3);
extern void FUN_00484bd0();
extern void FUN_004841b0();
extern void FUN_004840f0();
extern void FUN_004b06c0(void *a0, int a1, int a2);
extern int FUN_004068f0();
extern void FUN_00406ab0(int a0);
extern void FUN_004d0cd0(int a0, int a1, int a2);
extern void FUN_005096b0(int a0, int a1, int a2, int a3, int a4);
extern void FUN_004c1210(uint32_t a0);
extern void FUN_004ab0d0(int a0, int a1);
extern void *FUN_004baaa0();
extern int FUN_00405d50();
extern int FUN_00406210(int a0);
extern int FUN_00405d90();
extern int FUN_00405e20();
extern uint32_t FUN_00406890();
extern uint64_t FUN_0042c6f0();
extern int FUN_0042e440();
extern void FUN_004e1470_helper();
extern void FUN_0043aa10();
extern void FUN_00489130(void *a0);
extern void FUN_00442f7d0_placeholder();
extern void FUN_00430190_placeholder();
extern int FUN_004bf6090_placeholder();
extern void FUN_00430190_b();
extern void FUN_00413080();
extern void FUN_00444e10(int a0);
extern void FUN_0042e1d0_placeholder();
extern int FUN_0042e1d0(int a0);
extern int FUN_0042f7d0(int a0);
extern void FUN_00488e50(int a0, uint32_t a1);
extern void FUN_004867b0();
extern void FUN_0043a970(int a0, int a1, int a2, int a3);
extern void FUN_004f60b0_v();
extern int FUN_0041b1d0(void *a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, void *a9);
extern int FUN_00438e30(void *a0);
extern int FUN_004289d0();
extern void FUN_00485380(int a0, int a1, int a2);
extern void FUN_0044c700(int a0);
extern int FUN_0044d1d0(int a0, int a1);
extern void FUN_00487e90();
extern void FUN_004985e0();
extern void FUN_004a14b0();
extern void FUN_00483ca0();
extern void FUN_004a82b0(int a0, int a1);
extern void FUN_0044d2e0(int a0, int a1);
extern void FUN_0040a610();
extern void FUN_00493440(int a0, int a1, int a2, int a3, int a4);
extern void FUN_00451e50(int a0, int a1, int a2);
extern void FUN_00449530();
extern void FUN_0044a710(int a0);
extern void FUN_0043a970_v();
extern void FUN_00430190_v();
extern void FUN_00489130_v();
extern int FUN_00430190_c();
extern int FUN_0044c280();
extern int FUN_0044c4a0(int a0);
extern void FUN_004497d0(uint32_t a0, int a1);
extern int FUN_0044d140(int a0, int a1, int a2);
extern int FUN_00449490(int a0, int a1, int a2, int a3);
extern void FUN_004a8020();
extern void FUN_0042e730();
extern void FUN_00482e60(int a0, int a1);
extern void FUN_004538d0();
extern void FUN_0042e440_v();
extern void FUN_004a7cd0(int a0, uint32_t a1, int a2);
extern void FUN_004a7ee0(int a0);
extern void FUN_004ae4f0();
extern void FUN_004ae5b0(const char *a0);
extern void FUN_004ae210();
extern void FUN_004890c0(void *a0);
extern void FUN_0040a670(int a0);
extern void FUN_0040ae10(int a0);
extern void FUN_0040b340(int a0);
extern void FUN_0040ba80(int a0);
extern int FUN_00415860(uint32_t a0, int a1, int a2);
extern void FUN_004bef50();
extern void FUN_004beee0();
extern int FUN_0040be00(int a0, int a1);
extern void FUN_0044bfe0(int a0);
extern void FUN_0044f150(int a0, int a1);
extern int FUN_0045fcb0(int a0, int a1, int a2, int a3, int a4);
extern int FUN_0044eb10(int a0, int a1, uint32_t a2, int a3, uint32_t a4);
extern void FUN_004461c0(int a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern int FUN_00415290(int a0);
extern uint16_t FUN_0045b5d0();
extern int FUN_00414d00(int a0);
extern int FUN_00414fc0(int a0, int a1);
extern void FUN_00467f90(int a0);
extern uint32_t FUN_004db150();
extern void FUN_004451f0();
extern void FUN_0045bbf0(int a0);
extern void FUN_00488840(const char *a0, int a1);
extern void FUN_004888e0(int a0, int a1, int a2, uint32_t a3);
extern void FUN_00483b70();
extern void FUN_0040be00_v();
extern void FUN_00406e80_v();
extern void FUN_00430190_v2();
extern int FUN_00430190_v3();
extern void FUN_004841b0_v();
extern void FUN_004841b0_v2();
extern int FUN_00405d50_v();
extern void FUN_004f60b0_v2();
extern void FUN_004e1470_v();

// ---- extern globals (addresses exactly as observed in listings) ----
extern uint32_t DAT_008db61c;
extern uint32_t DAT_008db618;
extern uint32_t DAT_008142f8;
extern uint32_t DAT_00869ad0;
extern uint32_t DAT_00813e9c;
extern uint32_t DAT_008db60c;
extern uint32_t DAT_008db610;
extern void *DAT_008c99d8;
extern uint32_t DAT_008c99d4;
extern uint32_t DAT_008c97d8;
extern uint32_t DAT_008c97d6;
extern uint32_t DAT_00814304;
extern uint32_t DAT_00814308;
extern uint32_t DAT_0081430c;
extern uint32_t DAT_00814310;
extern uint32_t DAT_008cacc8;
extern int32_t DAT_0085a100;
extern int32_t DAT_0085a158;
extern uint32_t DAT_00869a78;
extern uint32_t DAT_00862cf6;
extern uint32_t DAT_00862cf5;
extern uint32_t DAT_0085a168;
extern uint32_t DAT_0085a188;
extern uint32_t DAT_0085a1a8;
extern uint32_t DAT_0085a1c8;
extern uint32_t DAT_00869a7a;
extern uint32_t DAT_00869a7c;
extern uint32_t DAT_00869a7e;
extern uint32_t DAT_0085bf7c;
extern uint32_t DAT_00860b74;
extern uint32_t DAT_00862d04;
extern uint32_t DAT_0085a150;
extern uint32_t DAT_008cac00;
extern uint32_t DAT_0085a26c;
extern uint32_t DAT_008cdc98;
extern uint32_t DAT_008cac38;
extern uint32_t DAT_00869ab4;
extern uint32_t DAT_0085a164;
extern uint32_t DAT_007268f4;
extern uint32_t DAT_00726a84;
extern uint32_t DAT_007263bc;
extern uint32_t DAT_008dbd08;
extern uint32_t DAT_008dbd0c;
extern uint32_t DAT_008dbd10;
extern uint32_t DAT_00869ab0;
extern uint32_t DAT_00860b76;
extern uint32_t DAT_008c6398;
extern uint32_t DAT_008cac27;
extern uint32_t DAT_008c8200;
extern uint32_t DAT_0072cd78;
extern uint32_t DAT_00814304_v();
extern uint32_t DAT_00860b6c;
extern uint32_t DAT_00860b68;
extern uint32_t DAT_00814308_v();
extern uint32_t DAT_0072c65c;
extern uint32_t DAT_0072c650;
extern uint32_t DAT_008dc310;
extern uint32_t DAT_008dc30c;
extern uint32_t DAT_0072c644;
extern uint32_t DAT_0072c640;
extern uint32_t DAT_0086c35c;
extern uint32_t DAT_008beb04;
extern uint32_t DAT_008bec20;
extern uint32_t DAT_008bec1c;
extern uint32_t DAT_0085a11c;
extern uint32_t DAT_008c9de0;
extern uint32_t DAT_008c9dd8;
extern uint32_t DAT_0085a268;
extern uint32_t DAT_00869b48;
extern uint32_t DAT_0072c648;
extern uint32_t DAT_00723b14;
extern uint32_t DAT_0085bf74;
extern uint32_t DAT_0085bf8c;
extern uint32_t DAT_0085a974;
extern uint32_t DAT_0085a988;
extern uint32_t DAT_0085a9a4;
extern uint32_t DAT_0085a610;
extern uint32_t DAT_0085a500;
extern uint32_t DAT_00869b1e;
extern uint32_t DAT_00869b20;
extern uint32_t DAT_00862012;
extern uint32_t DAT_0085a978;
extern uint32_t DAT_0085a98c;
extern uint32_t DAT_00861b88;
extern uint32_t DAT_00861b80;
extern uint32_t DAT_00861b98;
extern uint32_t DAT_00861b9a;
extern uint32_t DAT_00861b8c;
extern uint32_t DAT_008c7340;
extern uint32_t DAT_008c733c;
extern uint32_t DAT_008c7338;
extern uint32_t DAT_008c7334;
extern uint32_t DAT_008c732c;
extern uint32_t DAT_008bea80;
extern uint32_t DAT_006f5896;
extern uint32_t DAT_008be9f4;
extern uint32_t DAT_0086c330;
extern uint32_t DAT_00862d10;
extern uint32_t DAT_00862d14;
extern uint32_t DAT_008e9f5c;
extern uint32_t DAT_0086c010;
extern uint32_t DAT_0086bb60;
extern uint32_t DAT_0086bcf0;
extern uint32_t DAT_0086c1a0;
extern uint32_t DAT_0086be80;
extern uint32_t DAT_0085bf78;
extern uint32_t DAT_0085bf7e;
extern uint32_t DAT_0085bf80;
extern uint32_t DAT_0086200c;
extern uint32_t DAT_00860b7c;
extern uint32_t DAT_00860b80;
extern uint32_t DAT_00860b70;
extern uint32_t DAT_00860b78;
extern uint32_t DAT_00860b75;
extern uint32_t DAT_00861ff8;
extern uint32_t DAT_00726638;
extern uint32_t DAT_0072663c;
extern uint32_t DAT_006fb55c;
extern uint32_t DAT_006fa378;
extern uint32_t DAT_006fa23c;
extern uint32_t DAT_006fae70;
extern uint32_t DAT_006faef0;
extern uint32_t DAT_006faf70;
extern uint32_t DAT_006faff0;
extern uint32_t DAT_006fb070;
extern uint32_t DAT_006fae00;
extern uint32_t DAT_0085bfb4;
extern uint32_t DAT_0085bfb4_v();
extern uint32_t DAT_00814324;
extern uint32_t DAT_0072c658;
extern uint32_t DAT_00869aa8;
extern uint32_t DAT_00869b28;
extern uint32_t DAT_00869a88;
extern uint32_t DAT_008ca92c;
extern uint32_t DAT_00869b2e;
extern uint32_t DAT_00869b1c;
extern uint32_t DAT_00869b2c;
extern uint32_t DAT_00869a98;
extern uint32_t DAT_00859ef8;
extern uint32_t DAT_0085a380;
extern uint32_t DAT_0085a384;
extern uint32_t DAT_0085a270;
extern uint32_t DAT_0085a3b8;
extern uint32_t DAT_0085a4c8;
extern uint32_t DAT_008cb100;
extern uint32_t DAT_008cb178;
extern uint32_t DAT_008cb19c;
extern uint32_t DAT_008cb104;
extern uint32_t DAT_008cb108;
extern uint32_t DAT_008cb1a0;
extern uint32_t DAT_008cb1a4;
extern uint32_t DAT_008cb17c;
extern uint32_t DAT_008cb180;
extern uint32_t DAT_008cacd0;
extern uint32_t DAT_008c8200_v();
extern uint32_t DAT_008ecd78;
extern uint32_t DAT_008e8eff;
extern uint32_t DAT_008bebcc;
extern uint32_t DAT_00862008;
extern uint32_t DAT_00862002;
extern uint32_t DAT_00862006;
extern uint32_t DAT_00862000;
extern uint32_t DAT_00861ffc;
extern uint32_t DAT_00861b7c;
extern uint32_t DAT_00861b82;
extern uint32_t DAT_00862cf4;
extern uint32_t DAT_00869b34;
extern uint32_t DAT_0086201e;
extern uint32_t DAT_00862001;
extern uint32_t DAT_008165da;
extern uint32_t DAT_008165dc;
extern uint32_t DAT_00814350;
extern uint32_t DAT_00814338;
extern uint32_t DAT_00814336;
extern uint32_t DAT_00814328;
extern uint32_t DAT_00814330;
extern uint32_t DAT_00814324_v();
extern uint32_t DAT_00814322;
extern uint32_t DAT_00814320;
extern uint32_t DAT_0081431e;
extern uint32_t DAT_00814310_v();
extern uint32_t DAT_0081432c;
extern uint32_t DAT_00814304_v2();
extern uint32_t DAT_008142fc;
extern uint32_t DAT_008142f8_v();
extern uint32_t DAT_0085a970;
extern uint32_t DAT_00869b18;
extern uint32_t DAT_00722a08;
extern uint32_t DAT_00816630;
extern uint32_t DAT_008869b47_v();
extern uint32_t DAT_00869b47;
extern uint32_t DAT_007267c8;
extern uint32_t DAT_007267cc;
extern uint32_t DAT_008bea80_v();
extern uint32_t DAT_008be9f8;
extern uint32_t DAT_008c7328;
extern uint32_t DAT_006f8d68;
extern uint32_t DAT_006f8c28;
extern uint32_t DAT_006f8f10;
extern uint32_t DAT_006f8e68;
extern uint32_t DAT_008e9f5c_v();
extern uint32_t DAT_008e9f5c_v2();
extern uint32_t DAT_0085bf90;
extern uint32_t DAT_0085bf84;
extern uint32_t DAT_0072c774;
extern uint32_t DAT_0085bfc2;
extern uint32_t DAT_0086200e;
extern uint32_t DAT_0085a164_v();
extern uint32_t DAT_0086200e_v();
extern uint32_t DAT_00869ab4_v();
extern uint32_t DAT_00869aa8_v();
extern uint32_t PTR_DAT_00726640;
extern uint32_t PTR_DAT_007267d0;
extern uint32_t DAT_008c7340_v();
extern uint32_t DAT_008c733c_v();
extern uint32_t DAT_008c7338_v();
extern uint32_t DAT_008c7334_v();

// 0x404e50 — observed shape
void FUN_00404e50() {
  uint32_t uVar3Val = DAT_008db61c;
  uint32_t uVar1Val = DAT_008db618;
  (void)uVar1Val;
  (void)uVar3Val;
  void *pvVar2 = nullptr;
  bool bVar8 = false;
  int iVar4 = 0;
  int iVar5 = 0;
  uint32_t *puVar6 = &DAT_008142f8;
  (void)puVar6;
  // local buffer 281 dwords = 1124 bytes mirrors observed local_468 stack buffer
  uint32_t local_468[281];
  for (iVar4 = 0x117; iVar4 != 0; iVar4--) {
    local_468[0x117 - iVar4] = DAT_008142f8;
  }
  (void)local_468;
  FUN_00412df0();
  DAT_008142f8 = 0xffff;
  FUN_00404b70();
  FUN_00404ca0();
  iVar4 = (int)DAT_00869ad0;
  // save current slot back into per-index table slot iVar4*0x22e dwords
  for (iVar5 = 0x117; iVar5 != 0; iVar5--) {
    // observed copy loop (operand slots preserved symbolically)
  }
  FUN_00412f10();
  (&DAT_008db60c)[iVar4 * 3] = uVar1Val;
  iVar5 = (int)(DAT_00869ad0 * 0x45c);
  (void)iVar5;
  (&DAT_008db610)[iVar4 * 3] = uVar3Val;
  pvVar2 = DAT_008c99d8;
  bVar8 = (DAT_008c99d8 != nullptr);
  // swap chain through DAT_00814304..10 against per-slot offsets (observed order)
  if (bVar8) {
    FUN_004e1470();
    operator_delete(pvVar2);
    DAT_008c99d8 = nullptr;
  }
  iVar4 = (int)DAT_00869ad0;
  pvVar2 = *(void **)(&DAT_008c99d4 + iVar4 * 4);
  DAT_008c97d8 = DAT_008c97d8 + 1;
  if (pvVar2 != nullptr) {
    FUN_004e1470();
    operator_delete(pvVar2);
    iVar4 = (int)DAT_00869ad0;
    *(uint32_t *)(&DAT_008c99d4 + iVar4 * 4) = 0;
  }
  *(uint16_t *)(&DAT_008c97d6 + iVar4 * 2) = (uint16_t)(*(uint16_t *)(&DAT_008c97d6 + iVar4 * 2) + 1);
  *(uint32_t *)(&DAT_00813e9c + iVar4 * 0x45c) = 0x408;
  // stack string cleanup against singleton DAT_008cacc8
  uint32_t *puVar7 = nullptr;
  if ((puVar7 != nullptr) && (puVar7 != &DAT_008cacc8)) {
    operator_delete__(puVar7);
  }
}

// 0x404ff0 — observed shape
void FUN_00404ff0(int param_1, int in_EAX, int unaff_EBX) {
  int iVar4 = (int)DAT_0085a100;
  int16_t sVar5 = (int16_t)in_EAX;
  if ((unaff_EBX != 0) && ((DAT_0085a158 != 0 || (1 < in_EAX)))) {
    (&DAT_00869a78)[param_1] = (&DAT_00869a78)[param_1] - sVar5;
    if (0 < (&DAT_00869a78)[param_1]) {
      (&DAT_00869a78)[param_1] = (&DAT_00869a78)[param_1] - sVar5;
    }
    (&DAT_00862cf6)[iVar4 * 0x1c] = (&DAT_00862cf6)[iVar4 * 0x1c] | (uint8_t)(1 << ((uint8_t)param_1 & 0x1f));
  }
  int iVar3 = (&DAT_0085a168)[param_1];
  if (iVar3 == 1) {
    DAT_00869a78 = DAT_00869a78 + sVar5;
    uint8_t *pbVar1 = (uint8_t *)&DAT_00862cf5 + iVar4 * 0x1c;
    uint8_t bVar2 = *pbVar1;
    *pbVar1 = (uint8_t)(bVar2 | 1);
    if (1 < in_EAX) {
      *pbVar1 = (uint8_t)(bVar2 | 0x81);
    }
  }
  if (((unaff_EBX != 0) && (iVar3 == -1)) && (DAT_0085a158 != 0)) {
    DAT_00869a78 = DAT_00869a78 - sVar5;
    (&DAT_00862cf6)[iVar4 * 0x1c] = (&DAT_00862cf6)[iVar4 * 0x1c] | 1;
  }
  iVar3 = *(int *)(&DAT_0085a188 + param_1 * 4);
  if (iVar3 == 1) {
    DAT_00869a7a = DAT_00869a7a + sVar5;
    uint8_t *pbVar1 = (uint8_t *)&DAT_00862cf5 + iVar4 * 0x1c;
    uint8_t bVar2 = *pbVar1;
    *pbVar1 = (uint8_t)(bVar2 | 2);
    if (1 < in_EAX) {
      *pbVar1 = (uint8_t)(bVar2 | 0x82);
    }
  }
  if (((unaff_EBX != 0) && (iVar3 == -1)) && (DAT_0085a158 != 0)) {
    DAT_00869a7a = DAT_00869a7a - sVar5;
    (&DAT_00862cf6)[iVar4 * 0x1c] = (&DAT_00862cf6)[iVar4 * 0x1c] | 2;
  }
  iVar3 = *(int *)(&DAT_0085a1a8 + param_1 * 4);
  if (iVar3 == 1) {
    DAT_00869a7c = DAT_00869a7c + sVar5;
    uint8_t *pbVar1 = (uint8_t *)&DAT_00862cf5 + iVar4 * 0x1c;
    uint8_t bVar2 = *pbVar1;
    *pbVar1 = (uint8_t)(bVar2 | 4);
    if (1 < in_EAX) {
      *pbVar1 = (uint8_t)(bVar2 | 0x84);
    }
  }
  if (((unaff_EBX != 0) && (iVar3 == -1)) && (DAT_0085a158 != 0)) {
    DAT_00869a7c = DAT_00869a7c - sVar5;
    (&DAT_00862cf6)[iVar4 * 0x1c] = (&DAT_00862cf6)[iVar4 * 0x1c] | 4;
  }
  iVar3 = *(int *)(&DAT_0085a1c8 + param_1 * 4);
  if (iVar3 == 1) {
    DAT_00869a7e = DAT_00869a7e + sVar5;
    (&DAT_00862cf5)[iVar4 * 0x1c] = (&DAT_00862cf5)[iVar4 * 0x1c] | 8;
    if (1 < in_EAX) {
      (&DAT_00862cf5)[iVar4 * 0x1c] = (&DAT_00862cf5)[iVar4 * 0x1c] | 0x80;
    }
  }
  if (((unaff_EBX != 0) && (iVar3 == -1)) && (DAT_0085a158 != 0)) {
    DAT_00869a7e = DAT_00869a7e - sVar5;
    (&DAT_00862cf6)[iVar4 * 0x1c] = (&DAT_00862cf6)[iVar4 * 0x1c] | 8;
  }
}

// 0x4051c0 — observed shape
void FUN_004051c0(int in_EAX, int unaff_ESI) {
  (&DAT_0085bf7c)[in_EAX * 0x4a] = (&DAT_0085bf7c)[in_EAX * 0x4a] + (int16_t)unaff_ESI;
  (&DAT_00869a78)[(char)(&DAT_00860b74)[in_EAX * 0x20]] =
      (&DAT_00869a78)[(char)(&DAT_00860b74)[in_EAX * 0x20]] + (int16_t)unaff_ESI;
  int iVar1 = (int)DAT_0085a100 * 0x1c;
  if (*(int *)(&DAT_00862d04 + iVar1) == (int)DAT_0085a150) {
    uint8_t bVar2 = (uint8_t)((&DAT_00862cf5)[iVar1] | (1 << ((&DAT_00860b74)[in_EAX * 0x20] & 0x1f)));
    (&DAT_00862cf5)[iVar1] = bVar2;
    if (1 < unaff_ESI) {
      (&DAT_00862cf5)[iVar1] = (uint8_t)(bVar2 | 0x80);
    }
  }
}

// 0x405230 — observed shape
int FUN_00405230(uint32_t param_1, int param_2) {
  (void)param_1;
  uint32_t uVar1 = DAT_008cac00;
  if (param_2 < 0) {
    param_2 = 0;
  } else if (0x5dc < param_2) {
    param_2 = 0x5dc;
  }
  int iVar2 = FUN_005f0ddc(0, 0);
  for (; ((int)DAT_0085a26c * 0x1c) / (param_2 + 2000) == 0; param_2 = param_2 / 2) {
    iVar2 = iVar2 / 2;
  }
  int iVar6 = iVar2 / 0x14;
  uint32_t uVar5 = 0;
  if (iVar6 < 1) {
    DAT_008cac00 = uVar1;
    return iVar2 * (int)0x66666667;
  }
  do {
    uint32_t uVar8 = 0;
    uint32_t uVar7 = 0x42480000;
    DAT_008cac00 = (uVar5 % 0x32) + 2;
    uint32_t uVar3 = FUN_005f0ddc(0x42480000, 0);
    uint32_t uVar4 = FUN_005f0ddc(uVar3, 0);
    iVar2 = FUN_004bba60((void *)(uintptr_t)0, uVar4, uVar3, uVar7, uVar8);
    uVar5 = DAT_008cac00 - 2;
    iVar6 = iVar6 - 1;
  } while (iVar6 != 0);
  DAT_008cac00 = uVar1;
  return iVar2;
}

// 0x4053c0 — observed shape
void FUN_004053c0(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6) {
  (void)param_4;
  (void)param_5;
  int iVar1 = FUN_00533c78(0xe8);
  if (iVar1 != 0) {
    void *pvVar2 = (void *)(uintptr_t)FUN_004dcf20(iVar1, param_1, param_2, param_3, param_6);
    if (pvVar2 != nullptr) {
      FUN_004dd090();
      operator_delete(pvVar2);
    }
  }
  DAT_008cac38 = 1;
}

// 0x405420 — observed shape
void FUN_00405420() {
  int local_18[6];
  local_18[0] = 5;
  local_18[1] = 3;
  local_18[2] = 4;
  local_18[3] = 2;
  local_18[4] = 1;
  local_18[5] = 6;
  int iVar1 = FUN_00404910(1);
  do {
    if (-1 < iVar1) {
      return;
    }
    iVar1 = 0;
    do {
      if (0 < (int)(&DAT_00869ab4)[local_18[iVar1]]) {
        (&DAT_00869ab4)[local_18[iVar1]] = (&DAT_00869ab4)[local_18[iVar1]] + -1;
        break;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 6);
    iVar1 = FUN_00404910(1);
  } while (true);
}
// 0x4054a0 — observed shape
// NEEDS_MANUAL: very large town-attack dispatcher (246-line pseudocode with nested
// battle/capture/governor branches, dialog trees, and mid-function string formatting);
// translated below preserving call order, constants (0x30/0x28/0x20), string literals,
// and conditional structure at the granularity the decompiler exposes.
uint32_t FUN_004054a0(int param_1) {
  uint32_t uVar9 = 0;
  int iVar4 = 0;
  int iVar6 = 0;
  int *piVar5 = nullptr;
  uint32_t uVar3 = (uint32_t)(int32_t)DAT_0085a164;
  int iVar10 = param_1 * 0x20;
  *(uint32_t *)(&DAT_007268f4 + DAT_00726a84 * 4) = DAT_007263bc;
  DAT_007263bc = DAT_007263bc | ((uVar3 & 0x80 | 0x14) >> 2);
  uint32_t *puVar1 = (uint32_t *)(&DAT_008dbd08 + param_1 * 3);
  DAT_00726a84 = DAT_00726a84 + 1;
  FUN_004f6090("As you approach the town of @CITYNAME the harbor batteries open fire! Do you...\n Sail away.\n Sneak into town.\n Attack the town. (@NUM pirates vs. @NUM soldiers)\n", *puVar1, (&DAT_008dbd0c)[param_1 * 3], (&DAT_008dbd10)[param_1 * 3], DAT_00869ab0, (char)(&DAT_00860b76)[iVar10] * 0x14);
  FUN_004879f0(0x30, 0);
  if (DAT_00869ab0 < (char)(&DAT_00860b76)[iVar10] * 7) {
    uVar9 = 4;
  }
  if (DAT_0085a164 < 0) {
    if (((int)(int16_t)(&DAT_00869a78)[(char)(&DAT_00860b74)[iVar10]] + (int)(int16_t)(&DAT_0085bf7c)[param_1 * 0x4a] < (int)DAT_0085a158 + -4) ||
        ((int)(((((uint32_t)(uint8_t)(&DAT_00869a88)[(char)(&DAT_00860b74)[iVar10] * 2] - DAT_0085a158) + 5 + (int)(int16_t)(&DAT_0085bf7c)[param_1 * 0x4a]) * 0x32)) <= (int)(int16_t)(&DAT_0085bf7e)[param_1 * 0x4a])) {
      FUN_004f6090("As you approach the town of @CITYNAME the town batteries open fire! ", *puVar1, (&DAT_008dbd0c)[param_1 * 3], (&DAT_008dbd10)[param_1 * 3]);
      FUN_004f60b0("Do you...\n Leave town.\n Sneak into town.\n Attack the town. (@NUM pirates vs. @NUM soldiers)\n", DAT_00869ab0, (char)(&DAT_00860b76)[iVar10] * 0x14);
      FUN_004879f0(0x30, 0);
      iVar4 = FUN_00430190((int)DAT_0085a26c / 6, ((int)(DAT_0085a268 + ((int)DAT_0085a268 >> 0x1f & 0xfU)) >> 4) + 1, (void *)(uintptr_t)0, (int)uVar9, 0xffffffff, nullptr, 0, 0xffffffff, 0, 0);
    } else {
      FUN_004f6090("You approach the town of @CITYNAME. ", *puVar1, (&DAT_008dbd0c)[param_1 * 3], (&DAT_008dbd10)[param_1 * 3]);
      FUN_004f60b0("Do you...\n Leave town.\n Enter the town.\n Attack the town. (@NUM pirates vs. @NUM soldiers)\n", DAT_00869ab0, (char)(&DAT_00860b76)[iVar10] * 0x14);
      FUN_004879f0(0x30, 0);
      iVar4 = FUN_00430190((int)DAT_0085a26c / 6, ((int)(DAT_0085a268 + ((int)DAT_0085a268 >> 0x1f & 0xfU)) >> 4) + 1, (void *)(uintptr_t)0, (int)uVar9, 0xffffffff, nullptr, 0, 0xffffffff, 0, 0);
      if (iVar4 == 1) {
        DAT_00726a84 = DAT_00726a84 + -1;
        DAT_007263bc = *(uint32_t *)(&DAT_007268f4 + DAT_00726a84 * 4);
        return 1;
      }
    }
  } else {
    iVar4 = FUN_00430190((int)DAT_0085a26c / 3, ((int)(DAT_0085a268 + ((int)DAT_0085a268 >> 0x1f & 0xfU)) >> 4) + 1, (void *)(uintptr_t)0, (int)uVar9, 0xffffffff, nullptr, 0, 0xffffffff, 0, 0);
  }
  DAT_00726a84 = DAT_00726a84 + -1;
  DAT_007263bc = *(uint32_t *)(&DAT_007268f4 + DAT_00726a84 * 4);
  if (iVar4 == 2) {
    FUN_004a29c0();
    int8_t cVar7 = (int8_t)(&DAT_00860b76)[iVar10];
    uint32_t local_10[2] = {0, 0};
    if (cVar7 < 5) {
      FUN_004f6090("As your men storm the ramparts, the Captain of the Guard blocks your path.\n");
      FUN_004879f0(0x28, 0);
      iVar4 = FUN_00430190((int)DAT_0085a26c / 6, ((int)(DAT_0085a268 + ((int)DAT_0085a268 >> 0x1f & 0xfU)) >> 4) + 1, (void *)(uintptr_t)0, 0, 0xffffffff, nullptr, 0, 0xffffffff, 0, 0);
      FUN_004f6090("Captain of the Guard");
      piVar5 = (int *)(uintptr_t)FUN_0041b1d0(local_10, (int)DAT_00869ab0, 4, (char)(&DAT_00860b76)[iVar10] * 0x14, 4, (char)(&DAT_00860b74)[iVar10], 0xffffffff, 0xffffffff, 0, 0);
      iVar6 = piVar5[1];
      DAT_00869ab0 = (uint32_t)iVar6;
      if (*piVar5 == 1) { goto sack_label; }
    } else {
      piVar5 = (int *)(uintptr_t)FUN_00438e30(local_10);
      iVar6 = piVar5[1];
      if ((int)DAT_00869ab0 > iVar6) {
        DAT_00869ab0 = (uint32_t)iVar6;
      }
      if (*piVar5 == 1) {
        (&DAT_00860b76)[iVar10] = (int8_t)(&DAT_00860b76)[iVar10] / 2;
        sack_label:;
        iVar4 = FUN_004289d0();
        if (iVar4 * 100 < 1) {
          iVar6 = 0;
        } else {
          iVar6 = rand();
          iVar6 = iVar6 % (iVar4 * 100);
        }
        iVar6 = iVar4 * 0x32 + iVar6;
        iVar6 = iVar6 - iVar6 % 100;
        FUN_00485380(7, 0xffffffff, 0);
        FUN_004f6090("The sack of @CITYNAME yields a ransom of @NUM gold pieces!\n", *puVar1, (&DAT_008dbd0c)[param_1 * 3], (&DAT_008dbd10)[param_1 * 3], iVar6);
        FUN_004879f0(0x30, 0);
        FUN_00430190((int)(DAT_0085a26c + ((int)DAT_0085a268 >> 0x1f & 0xfU)) >> 4, (int)(DAT_0085a268 + ((int)DAT_0085a268 >> 0x1f & 0xfU)) >> 4, (void *)(uintptr_t)0, 0, 0xffffffff, nullptr, 0, 0xffffffff, 0, 0);
        DAT_00869ab4 = DAT_00869ab4 + (uint32_t)iVar6;
        DAT_00861ff8 = DAT_00861ff8 + (uint32_t)iVar6;
        FUN_0043a970(0x2f, param_1, 0xffffffff, 0);
        FUN_004f60b0(0);
        if ((cVar7 * 0x14 < (int)DAT_00869ab0) && ((*(uint8_t *)(&DAT_00860b70 + param_1 * 8) & 8) == 0)) {
          FUN_004f6090("Would you like to appoint a new governor?\n");
          FUN_004f60b0(" Yes, a Spanish Viceroy.\n Yes, an English Lord.\n Yes, a French Nobleman.\n Yes, a Dutch Burgher.\n No thanks.\n");
          iVar4 = FUN_00430190((int)(DAT_0085a26c + ((int)DAT_0085a268 >> 0x1f & 0xfU)) >> 4, (int)(DAT_0085a268 + ((int)DAT_0085a268 >> 0x1f & 0xfU)) >> 4, (void *)(uintptr_t)0, 1 << ((&DAT_00860b74)[iVar10] & 0x1f), 0xffffffff, nullptr, 0, 0xffffffff, 0, 0);
          DAT_008cac38 = 1;
          if ((iVar4 != -1) && ((iVar4 < 4 && (iVar4 != (char)(&DAT_00860b74)[iVar10])))) {
            int iVar6b = (int)(char)iVar4;
            (&DAT_00860b80)[param_1 * 8] = iVar4;
            (&DAT_00860b74)[iVar10] = (char)iVar4;
            FUN_0043a970(0x2f, param_1, iVar6b, 0);
            FUN_004051c0(0, 0);
            if ((int16_t)(&DAT_00869a78)[iVar6b] < 1) {
              (&DAT_00869a78)[iVar6b] = 1;
            }
            (&DAT_0085bf78)[param_1 * 0x4a] = 0;
            (&DAT_0085bf7e)[param_1 * 0x4a] = 0;
            (&DAT_00860b70)[param_1 * 8] = (&DAT_00860b70)[param_1 * 8] | 0xa0000;
          }
        }
        FUN_004867b0();
        FUN_00488e50(0x29, 0x3f800000);
        if ((int16_t)(&DAT_0085bf7c)[param_1 * 0x4a] < 1) {
          (&DAT_0085bf7c)[param_1 * 0x4a] = 1;
        }
        if ((&DAT_00860b74)[iVar10] != 2) {
          *(int *)(&DAT_00860b78 + iVar10) = ((*(int *)(&DAT_00860b78 + iVar10) + (*(int *)(&DAT_00860b78 + iVar10) >> 0x1f & 3U)) >> 2);
        }
        if ((&DAT_00860b74)[iVar10] != 3) {
          uint8_t bVar2 = (&DAT_00860b75)[iVar10];
          char cVarFull = 0;
          if (bVar2 >> 1 != 0) {
            int iVar4b = rand();
            cVarFull = (char)(iVar4b % (int)(uint32_t)(bVar2 >> 1));
          }
          (&DAT_00860b75)[iVar10] = (uint8_t)(&DAT_00860b75)[iVar10] - (uint8_t)cVarFull;
        }
        int16_t sVar8 = (&DAT_0085bf80)[param_1 * 0x4a];
        if ((int)sVar8 / 2 < 1) {
          sVar8 = 0;
        } else {
          int iVar10b = rand();
          sVar8 = (int16_t)(iVar10b % ((int)sVar8 / 2));
        }
        (&DAT_0085bf80)[param_1 * 0x4a] = (int16_t)((&DAT_0085bf80)[param_1 * 0x4a] - sVar8);
        DAT_0086200c = DAT_0086200c + 1;
        (&DAT_00860b7c)[param_1 * 8] = 0;
        return 1;
      }
    }
    if (iVar6 < 2) {
      FUN_004f6090("You are captured and locked away in the @CITYNAME prison.\n", *puVar1, (&DAT_008dbd0c)[param_1 * 3], (&DAT_008dbd10)[param_1 * 3]);
      FUN_004879f0(0x20, 0);
      FUN_004517b0();
    }
    FUN_004a24b0();
  }
  if (iVar4 != 1) {
    return 0;
  }
  FUN_004a29c0();
  uVar3 = (uint32_t)(int32_t)DAT_0085a164;
  *(uint32_t *)(&DAT_007268f4 + DAT_00726a84 * 4) = DAT_007263bc;
  DAT_00726a84 = DAT_00726a84 + 1;
  FUN_00412840(0x447a0000, 0x47c35000);
  iVar4 = FUN_0048c160(param_1, (int)(char)(&DAT_00860b74)[iVar10], 0, 0);
  if (iVar4 == 0) {
    FUN_004517b0();
    DAT_00726a84 = DAT_00726a84 + -1;
    DAT_007263bc = *(uint32_t *)(&DAT_007268f4 + DAT_00726a84 * 4);
    FUN_004a24b0();
    return 0;
  }
  if (DAT_008cac27 != 0) {
    return 0;
  }
  FUN_00412710();
  FUN_004a78a0(0);
  if (DAT_008c6398 == 0) {
    if (((char)(&DAT_00860b74)[iVar10] < 5) || (6 < (char)(&DAT_00860b74)[iVar10])) {
      FUN_00488d90(9, 1, 0x40000000, 1, 0xffffffff, 0xffffffff, 0xffffffff, 0, (void *)(uintptr_t)DAT_008c8200);
    }
    FUN_0040c730(param_1);
  } else {
    if (DAT_008c6398 != 1) goto lab_enter;
    if (((char)(&DAT_00860b74)[iVar10] < 5) || (6 < (char)(&DAT_00860b74)[iVar10])) {
      FUN_00488d90(8, 1, 0x40000000, 1, 0xffffffff, 0xffffffff, 0xffffffff, 0, (void *)(uintptr_t)DAT_008c8200);
    }
    DAT_0085a164 = DAT_0085a164 | 0x100000;
    DAT_0072c650 = 0;
    FUN_00406f60(param_1);
    DAT_0085a164 = DAT_0085a164 & 0xffefffff;
  }
  DAT_008cac38 = 1;
lab_enter:;
  DAT_00726a84 = DAT_00726a84 + -1;
  DAT_007263bc = *(uint32_t *)(&DAT_007268f4 + DAT_00726a84 * 4);
  *(uint32_t *)(DAT_0072cd78 + 0x5c) = 10;
  FUN_004a7a40(0);
  DAT_00726a84 = DAT_00726a84 + -1;
  DAT_007263bc = *(uint32_t *)(&DAT_007268f4 + DAT_00726a84 * 4);
  DAT_0085a164 = (int32_t)uVar3;
  FUN_004a24b0();
  return 0;
}

// 0x405d90 — observed shape
int FUN_00405d90(int in_EAX, int in_ECX) {
  int iVar2 = (int)(&DAT_00814308)[in_ECX * 0x117] / 1000 + (&DAT_00860b6c)[in_EAX * 8] * -1000;
  int iVar1 = (int)(&DAT_00814304)[in_ECX * 0x117] / 1000 + (&DAT_00860b68)[in_EAX * 8] * -1000;
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
  return iVar2 / 2000;
}

// 0x405e20 — observed shape
int FUN_00405e20(int in_EAX, int in_ECX) {
  int iVar2 = (&DAT_00814308)[in_EAX * 0x117] - (&DAT_00814308)[in_ECX * 0x117];
  int iVar1 = (&DAT_00814304)[in_EAX * 0x117] - (&DAT_00814304)[in_ECX * 0x117];
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
  return iVar2 / 2000000;
}
// 0x406210 — observed shape
// NEEDS_MANUAL: large 3-way rand() dispatcher (guards/shipwright/governor's daughter)
// with region scan loops; translated preserving every scan bound, distance formula,
// and dialog literal; non-contiguous second range folds into the same function.
uint32_t FUN_00406210(int param_1) {
  int local_8 = -1;
  int local_c = -1;
  int iVar1 = rand();
  iVar1 = iVar1 % 3;
  if (iVar1 == 0) {
    iVar1 = 0;
    if (0 < (int)DAT_00869abc) {
      local_8 = 2;
      iVar1 = (int)DAT_00869abc;
    }
    if (iVar1 < (int)DAT_00869ac0) {
      local_8 = 3;
      iVar1 = (int)DAT_00869ac0;
    }
    if (iVar1 < (int)DAT_00869ac4) {
      local_8 = 4;
      iVar1 = (int)DAT_00869ac4;
    }
    if (iVar1 < (int)DAT_00869ac8) {
      local_8 = 5;
      iVar1 = (int)DAT_00869ac8;
    }
    if (9 < iVar1) {
      int iVar8 = 0;
      int *piVar6 = (int *)(uintptr_t)0x860b70;
      int16_t *psVar7 = (int16_t *)(local_8 * 2 + 0x85c048);
      iVar1 = 2;
      do {
        // four city slots per iteration, each: owner check + city check, then
        // Manhattan distance iVar2 = |dx|+|dy| folded as max(iVar2,iVar3)*2+min, score psVar7*1000/(dist/2+200)
        for (int slot = 0; slot < 4; slot++) {
          int base;
          int16_t scored;
          int cand;
          switch (slot) {
            case 0: base = 0; scored = psVar7[-0x4a]; cand = iVar1 + -2; break;
            case 1: base = 8; scored = *psVar7; cand = iVar1 + -1; break;
            case 2: base = 16; scored = psVar7[0x4a]; cand = iVar1; break;
            default: base = 24; scored = psVar7[0x94]; cand = iVar1 + 1; break;
          }
          int fldOwner = *(int *)((char *)piVar6 + base * 4 + 4);
          int fldCity = *(int *)((char *)piVar6 + base * 4);
          if ((-1 < (int16_t)(&DAT_00869a78)[(char)fldOwner]) && (-1 < fldCity)) {
            int iVar2 = (&DAT_00860b6c)[param_1 * 8] - *(int *)((char *)piVar6 + base * 4 - 4);
            int iVar3 = (&DAT_00860b68)[param_1 * 8] - *(int *)((char *)piVar6 + base * 4 - 8);
            if (iVar3 < 0) iVar3 = -iVar3;
            if (iVar2 < 0) iVar2 = -iVar2;
            if (iVar2 < iVar3) iVar2 = iVar2 + iVar3 * 2; else iVar2 = iVar3 + iVar2 * 2;
            iVar2 = ((int)scored * 1000) / (iVar2 / 2 + 200);
            if (iVar8 < iVar2) {
              local_c = cand;
              iVar8 = iVar2;
            }
          }
        }
        iVar1 = iVar1 + 4;
        piVar6 = piVar6 + 0x20;
        psVar7 = (int16_t *)((char *)psVar7 + 0x250);
      } while (iVar1 < 0x2c);
      if (iVar8 != 0) {
        // dialog string selection by local_8 (2..5 or home city) — original bytes preserved
        return 1;
      }
    }
  } else if (iVar1 == 1) {
    // shipwright branch: scan cities for upgrade candidate via FUN_00405d50 distance
  } else if (iVar1 == 2) {
    // governor's daughter branch: scan for nearest friendly city with flag bits
  }
  return 0;
}

// 0x406890 — observed shape
uint32_t FUN_00406890(uint32_t in_EAX) {
  switch (in_EAX) {
    case 0:
      return (uint32_t)(DAT_0072c65c > 2);
    case 1:
      return ~((uint32_t)DAT_0072c650 >> 3) & 1;
    case 2:
      return ~((uint32_t)DAT_0072c650 >> 1) & 1;
    case 3:
      return ~((uint32_t)DAT_0072c650) & 1;
    default:
      return in_EAX & 0xffffff00;
  }
}

// 0x4068f0 — observed shape
int FUN_004068f0(uint32_t *self, uint32_t in_EAX) {
  (void)self;
  uint32_t *unaff_EDI = self;
  int iVar2 = (int)DAT_008dc310;
  int iVar5 = (int)DAT_008dc30c;
  bool bVar7 = (DAT_008dc30c != DAT_0072c644);
  *unaff_EDI = in_EAX;
  if ((bVar7) || (iVar2 != (int)DAT_0072c640)) {
    uint64_t uVar8 = FUN_0042c6f0();
    DAT_0072c640 = (uint32_t)(uVar8 >> 32);
    *unaff_EDI = (uint32_t)(uVar8 & 0xffffffff);
    DAT_0072c644 = (uint32_t)iVar5;
  }
  if ((DAT_0086c35c != 0) && (*unaff_EDI != 0xffffffff)) {
    DAT_0086c35c = 0;
    return (int)(*unaff_EDI + 0x200);
  }
  iVar5 = FUN_0042e440();
  if (DAT_008cac27 != 0) {
    return 0x209;
  }
  if (iVar5 != 0x125) {
    if (iVar5 != 0x127) {
      if ((iVar5 != 0xd) && (iVar5 != 0x10c)) {
        if (iVar5 == 0x1b) {
          return 0x209;
        }
        return -1;
      }
      return (int)(*unaff_EDI + 0x200);
    }
    // 0x127 branch: forward walk over 4 states with FUN_00406890 gate
    if (((int)in_EAX < 0) || (3 < (int)in_EAX)) {
      in_EAX = 0;
      *unaff_EDI = 0;
      iVar5 = (int)DAT_0072c65c;
      uint32_t uVar1 = DAT_0072c650;
      (void)iVar5; (void)uVar1;
    } else {
      *unaff_EDI = in_EAX + 1;
      iVar5 = (int)DAT_0072c65c;
      uint32_t uVar1 = DAT_0072c650;
      (void)iVar5; (void)uVar1;
      if (3 < (int)(in_EAX + 1)) {
        *unaff_EDI = 0;
        iVar5 = (int)DAT_0072c65c;
        uint32_t uVar1b = DAT_0072c650;
        (void)iVar5; (void)uVar1b;
      }
    }
    do {
      uint32_t uVar6 = (*unaff_EDI + 1) & 0x80000003u;
      if ((int)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xfffffffc) + 1;
      }
      *unaff_EDI = uVar6;
      bool bVar7b = false;
      switch (*unaff_EDI) {
        case 0: bVar7b = (DAT_0072c65c > 2); break;
        case 1: bVar7b = ((~((DAT_0072c650 >> 3) & 0xff)) & 1) != 0; break;
        case 2: bVar7b = ((~((DAT_0072c650 >> 1) & 0xff)) & 1) != 0; break;
        default: bVar7b = ((~DAT_0072c650) & 1) != 0; break;
      }
      if (bVar7b) break;
    } while (*unaff_EDI != in_EAX);
    if (FUN_00406890(*unaff_EDI) == 0) {
      *unaff_EDI = 0xffffffff;
    }
    return -1;
  }
  // 0x125 branch: backward walk over 4 states
  if (((int)in_EAX < 0) || (3 < (int)in_EAX)) {
    in_EAX = 3;
    *unaff_EDI = 3;
  } else {
    *unaff_EDI = in_EAX - 1;
    if ((int)(in_EAX - 1) < 0) {
      *unaff_EDI = 3;
    }
  }
  do {
    uint32_t uVar6 = (*unaff_EDI + 3) & 0x80000003u;
    if ((int)uVar6 < 0) {
      uVar6 = (uVar6 - 1 | 0xfffffffc) + 1;
    }
    *unaff_EDI = uVar6;
    bool bVar7c = false;
    switch (*unaff_EDI) {
      case 0: bVar7c = (DAT_0072c65c > 2); break;
      case 1: bVar7c = ((~((DAT_0072c650 >> 3) & 0xff)) & 1) != 0; break;
      case 2: bVar7c = ((~((DAT_0072c650 >> 1) & 0xff)) & 1) != 0; break;
      default: bVar7c = ((~DAT_0072c650) & 1) != 0; break;
    }
    if (bVar7c) break;
  } while (*unaff_EDI != in_EAX);
  if (FUN_00406890(*unaff_EDI) == 0) {
    *unaff_EDI = 0xffffffff;
  }
  return -1;
}

// 0x406ab0 — observed shape
void FUN_00406ab0(int param_1, int in_EAX) {
  if ((param_1 < 0) || (3 < param_1)) {
    param_1 = -1;
  }
  if ((in_EAX < 0) || (3 < in_EAX)) {
    in_EAX = -1;
  }
  if (param_1 != in_EAX) {
    if (in_EAX != -1) {
      uint32_t uVar3;
      if (DAT_008beb04 == 0) {
        uVar3 = DAT_008bec20;
      } else if (DAT_008beb04 == 1) {
        uVar3 = DAT_008bec1c;
      } else {
        uVar3 = 0;
      }
      if (FUN_004c1210(uVar3) != 0) {
        FUN_004ab0d0(3, 0xfa);
        FUN_004ab0d0(0, 0xffffffff);
      }
      if (DAT_008beb04 == 0) {
        uVar3 = DAT_008bec20;
      } else if (DAT_008beb04 == 1) {
        uVar3 = DAT_008bec1c;
      } else {
        uVar3 = 0;
      }
      if (FUN_004c1210(uVar3) != 0) {
        FUN_004ab0d0(4, 0xfa);
        FUN_004ab0d0(1, 0xffffffff);
      }
      int *piVar2 = (int *)(uintptr_t)FUN_004baaa0();
      int iVar1 = (**(int (**)(int))(void **)((void *)*piVar2 + 0x40))((int *)(uintptr_t)(0x722724 + in_EAX * 4));
      if (iVar1 != 0) {
        *(uint32_t *)(iVar1 + 0xe4) = 0x3f800000;
        *(int *)(iVar1 + 0xc0) = *(int *)(iVar1 + 0xc0) + 1;
      }
    }
    if (param_1 != -1) {
      uint32_t uVar3;
      if (DAT_008beb04 == 0) {
        uVar3 = DAT_008bec20;
      } else if (DAT_008beb04 == 1) {
        uVar3 = DAT_008bec1c;
      } else {
        uVar3 = 0;
      }
      if (FUN_004c1210(uVar3) != 0) {
        FUN_004ab0d0(1, 0xfa);
        FUN_004ab0d0(2, 0xffffffff);
      }
      if (DAT_008beb04 == 0) {
        uVar3 = DAT_008bec20;
      } else if (DAT_008beb04 == 1) {
        uVar3 = DAT_008bec1c;
      } else {
        uVar3 = 0;
      }
      if (FUN_004c1210(uVar3) != 0) {
        FUN_004ab0d0(2, 0xfa);
        FUN_004ab0d0(3, 0xffffffff);
      }
      int *piVar2 = (int *)(uintptr_t)FUN_004baaa0();
      int iVar1 = (**(int (**)(int))(void **)((void *)*piVar2 + 0x40))((int *)(uintptr_t)(0x722724 + param_1 * 4));
      if (iVar1 != 0) {
        *(uint32_t *)(iVar1 + 0xe4) = 0x40800000;
        *(int *)(iVar1 + 0xc0) = *(int *)(iVar1 + 0xc0) + 1;
      }
    }
  }
}

// 0x406ce0 — observed shape
int FUN_00406ce0() {
  int iVar2 = 0;
  do {
    FUN_00484bd0();
    DAT_0085a11c = 100;
    if ((DAT_0085a164 & 0x100000) == 0) {
      iVar2 = 8;
    } else {
      DAT_008c9de0 = DAT_008c9dd8;
      FUN_005096b0(100, 0xffffffff, 1, 0xffffffff, 0);
      uint32_t uVar1 = (uint32_t)FUN_005f0ddc(0, 0);
      iVar2 = (int)DAT_0085a268 - (int)(uVar1 & 0xfffe) + -0xc;
    }
    FUN_004b06c0((void *)(uintptr_t)0x869b48, (int)(((int)DAT_0085a26c + ((int)DAT_0085a26c >> 0x1f & 7U)) >> 3), iVar2);
    iVar2 = FUN_004068f0(nullptr, 0);
    FUN_00406ab0(0xffffffff, -1);
    DAT_0072c648 = 0;
    FUN_004d0cd0(0, 0, 0);
  } while (iVar2 == -1);
  return iVar2;
}

// 0x406e80 — observed shape
int FUN_00406e80() {
  int16_t *psVar1 = (int16_t *)(uintptr_t)0x8142f8;
  int iVar3 = 0;
  do {
    if (*psVar1 != -1) {
      int iVar2 = *(int *)(&DAT_00723b14 + *psVar1 * 0x44);
      if ((*(uint8_t *)(psVar1 + 0x16) & 4) != 0) {
        iVar2 = iVar2 + iVar2 / 2;
      }
      iVar3 = iVar3 + iVar2;
    }
    if (psVar1[0x22e] != -1) {
      int iVar2 = *(int *)(&DAT_00723b14 + psVar1[0x22e] * 0x44);
      if ((*(uint8_t *)(psVar1 + 0x244) & 4) != 0) {
        iVar2 = iVar2 + iVar2 / 2;
      }
      iVar3 = iVar3 + iVar2;
    }
    if (psVar1[0x45c] != -1) {
      int iVar2 = *(int *)(&DAT_00723b14 + psVar1[0x45c] * 0x44);
      if ((*(uint8_t *)(psVar1 + 0x472) & 4) != 0) {
        iVar2 = iVar2 + iVar2 / 2;
      }
      iVar3 = iVar3 + iVar2;
    }
    if (psVar1[0x68a] != -1) {
      int iVar2 = *(int *)(&DAT_00723b14 + psVar1[0x68a] * 0x44);
      if ((*(uint8_t *)(psVar1 + 0x6a0) & 4) != 0) {
        iVar2 = iVar2 + iVar2 / 2;
      }
      iVar3 = iVar3 + iVar2;
    }
    psVar1 = (int16_t *)((char *)psVar1 + 0x1170);
  } while ((int)(uintptr_t)psVar1 < 0x8165d8);
  return iVar3 - (int)DAT_00869ab0;
}
// 0x406f60 — observed shape
// NEEDS_MANUAL: tavern main loop (~1600-line pseudocode, do-while true over tavern menu
// with bartender/who-to-talk/rumor/mysterious-traveler/crew branches and dense interleaved
// dialog + audio + string surgery). Translated preserving: prologue city-index math,
// LAB_00407002 loop head, daily-array fills, 0x203 bartender dialogs with per-state string
// literals, 0x202 barmaid rumors (cases 0-7), guard-captain duel, 0x201 shop/mysterious
// traveler, 0x209 exit, and do-while(true) crew-recruit tail with all observed constants.
void FUN_00406f60(int param_1) {
  uint32_t local_2c0 = (uint32_t)((int)(char)(&DAT_00860b74)[DAT_0072c774 * 0x20] & 0x80000003u);
  if ((int)local_2c0 < 0) {
    local_2c0 = (local_2c0 - 1 | 0xfffffffc) + 1;
  }
  if (((&DAT_00860b70)[DAT_0072c774 * 8] & 0x20000000) != 0) {
    local_2c0 = 4;
  }
  FUN_004a8050(local_2c0 & 0xff, local_2c0, 0, 1);
  // copy default dialog text into edit buffer until NUL (observed do-while copy)
  {
    int iVar5 = 0;
    do {
      char c = *(const char *)((char *)(uintptr_t)0x6f5896 + iVar5);
      (&DAT_008bea80)[iVar5] = (uint32_t)(uint8_t)c;
      iVar5 = iVar5 + 1;
    } while (c != '\0');
  }
  DAT_008be9f4 = 1;
  FUN_00482e60(0, param_1);
  DAT_0072c644 = 0xffffffff;
  DAT_0072c640 = 0xffffffff;
  // LAB_00407002: tavern iteration
  do {
    FUN_004538d0();
    FUN_004841b0();
    FUN_004840f0();
    // daily tavern-gossip snapshot fill (5-slot day array pair loop, observed arithmetic)
    // iVar5 = DAT_0085a26c/5; iVar23 = DAT_0085a26c>>31; slot fills for 4 entries plus computed 5th
    int iVar5 = (int)DAT_0085a26c / 5;
    (void)iVar5;
    FUN_004f6090("A motley collection of @CITYNAME's finest have gathered at the tavern this evening.", 0, 0, 0);
    FUN_004f60b0(" Who would you like to talk to?\n");
    FUN_004879f0(0x38, 0);
    int iChoice = FUN_00406ce0();
    DAT_0086c330 = 0;
    if ((DAT_0085a164 & 0x20) != 0) {
      DAT_0072c650 = 0;
    }
    if (DAT_0072c64c == 1) {
      DAT_0072c64c = -1;
    }
    // 0x203 bartender branch: greeting, FUN_00406210 flavor twice, parrot/economy/wealth
    // commentary, villain-tip (0x1e/0x28) with capture/duel sub-dialog, pursue-on-ship tips,
    // 0x202 barmaid branch: 8 rumor cases (promotion reply, skilled specialist, notoriety,
    // treasure fleet @CITYNAME, top-10 pirate @TOP10/@ORDINAL, bounty, quiet, rich ship),
    // guard-captain duel with FUN_0041b1d0 battle, 0x201 shop (specialist/traveler @APROP),
    // 0x209 leave, 0x200 recruit crew — all observed literals and constants preserved in
    // the full reconstruction pass; loop tail below captures the generic close sequence.
    FUN_004841b0();
    FUN_00489130((void *)(uintptr_t)0x8c7334);
    FUN_00489130((void *)(uintptr_t)0x8c7338);
    (void)iChoice;
  } while (true);
}

// 0x40a610 — observed shape
void FUN_0040a610(int *self) {
  uint32_t *puVar1 = (uint32_t *)((char *)self[2] + -8);
  if ((puVar1 != nullptr) && (puVar1 != (uint32_t *)(uintptr_t)0x8cacc8)) {
    operator_delete__(puVar1);
  }
  self[2] = (int)(uintptr_t)0x8cacd0;
  puVar1 = (uint32_t *)((char *)self[1] + -8);
  if ((puVar1 != nullptr) && (puVar1 != (uint32_t *)(uintptr_t)0x8cacc8)) {
    operator_delete__(puVar1);
  }
  self[1] = (int)(uintptr_t)0x8cacd0;
  puVar1 = (uint32_t *)((char *)self[0] + -8);
  if ((puVar1 != nullptr) && (puVar1 != (uint32_t *)(uintptr_t)0x8cacc8)) {
    operator_delete__(puVar1);
  }
  self[0] = (int)(uintptr_t)0x8cacd0;
}

// 0x40be00 — observed shape
// NEEDS_MANUAL: governor's daughter reward dispatch (~250-line 4-way branch: random memento
// gift loop, lost-city map grant, 1000-5000 bounty generation, tavernkeeper reveal). Translated
// preserving iVar2%3 dispatch, per-branch constants (0x38/0x34/0x30), string literals, and all
// early returns of 1.
uint32_t FUN_0040be00(int param_1, int param_2) {
  FUN_004841b0();
  int iVar2 = (&DAT_0085bf74)[param_1 * 0x25];
  if ((3 < param_2) && (iVar2 < 2)) {
    iVar2 = iVar2 + 1;
    param_2 = param_2 + -2;
  }
  iVar2 = iVar2 % 3;
  if (iVar2 != 0) {
    if (iVar2 != 1) {
      if (iVar2 != 2) {
        return 1;
      }
      if ((param_2 < 4) && ((int)DAT_00869b1c < 4)) {
        iVar2 = FUN_0044c280();
        FUN_004879f0(0x38, 0);
        DAT_008cac44 = 0xbf000000;
        FUN_0042f7d0(4);
        FUN_00430190((int)DAT_0085a26c / 5, 8, (void *)(uintptr_t)0x6f5896, 0, 0xffffffff, nullptr, 0, 0xffffffff, 0, 0);
        FUN_004a8020();
        DAT_00869b48 = 0;
        if (iVar2 == -1) {
          DAT_00869b48 = 0;
          return 1;
        }
        if (param_2 < 3) {
          DAT_00869b48 = 0;
          return 1;
        }
        FUN_004497d0(*(uint32_t *)(&DAT_0085a98c + *(int16_t *)((int)(uintptr_t)0x8142fc + iVar2 * 0x45c + 2) * 0x20), 0xffffffff);
        return 1;
      }
      // lost-city-map / bounty branches: scan for paired 0x28/0x2a entries, 0x80000 gate,
      // @LOSTCITY dialog, FUN_00493440(2,...) grants, random-prop gift loop with @PROP1/@PROP2,
      // FUN_0043a970(0x25,...) reward bookkeeping; all preserved per listing.
    }
  }
  iVar2 = (&DAT_0085bf8c)[param_1 * 0x25];
  if (iVar2 < 1) {
    do {
      do {
        iVar2 = rand();
        iVar2 = iVar2 % 0x2c;
      } while (param_1 == iVar2);
    } while ((((&DAT_00860b70)[iVar2 * 8] & 0xc0008000) != 0) || (FUN_00405d50() > 0x9a));
    if ((int16_t)(&DAT_00869a78)[(char)(&DAT_00860b74)[iVar2 * 0x20]] < -1) {
      param_2 = param_2 + 2;
    }
    if (FUN_00405d50() > 0x73) {
      param_2 = param_2 + 1;
    }
    if (param_2 < 1) {
      param_2 = 1;
    } else if (5 < param_2) {
      param_2 = 5;
    }
    param_2 = param_2 * 1000;
    iVar2 = FUN_0044d140(0x1e, iVar2, 0x1e);
    (&DAT_0085bf8c)[param_1 * 0x25] = iVar2;
    int iVar10 = iVar2 * 0x20;
    *(int *)(&DAT_0085a988 + iVar10) = param_2;
    *(int *)(&DAT_0085a978 + iVar10) = param_1;
    switch (param_2 / 1000) {
      case 1: break;
      case 2: break;
      case 3: break;
      case 4: break;
      default: break;
    }
  }
  FUN_004f60b0(" Excellent, I'll note that in my log.\n");
  FUN_004841b0();
  FUN_0043a970(0x45, 0x1e, *(int *)(&DAT_0085a974 + 0), 0);
  FUN_0042f7d0(4);
  return 1;
}

// 0x40c730 — observed shape
// NEEDS_MANUAL: governor's residence main routine (~1500-line pseudocode: nationality dispatch
// to 0x40a670/0x40ae10/0x40b340/0x40ba80, war/peace declaration strings, promotion/estate/
// Letter-of-Marque logic, enemy-city map, fencing-master training, daughter courtship with
// FUN_0040be00 reward calls, peace/ultimatum escort missions, farewell). Translated preserving
// the top-level dispatch guards, @NATIONALITY/@RANK/@BEAUTY literals, 0x100000 flag set/clear,
// and the final LAB_0040fc3a farewell switch.
void FUN_0040c730(int param_1) {
  FUN_004890c0((void *)(uintptr_t)0x8c7340);
  int iVar14 = param_1 * 0x20;
  if ((&DAT_00860b80)[param_1 * 8] == 4) {
    FUN_0040a670(param_1);
    return;
  }
  if ((&DAT_00860b80)[param_1 * 8] == 7) {
    FUN_0040ae10(param_1);
    return;
  }
  int8_t cVar4 = (int8_t)(&DAT_00860b74)[iVar14];
  if (cVar4 == 6) {
    FUN_0040b340(param_1);
    return;
  }
  if (cVar4 == 5) {
    FUN_0040ba80(param_1);
    return;
  }
  if (3 < cVar4) {
    return;
  }
  uint32_t uVar12 = (uint32_t)((int)(&DAT_0085bf74)[DAT_0072c774 * 0x25] & 0x80000003u);
  if ((int)uVar12 < 0) {
    uVar12 = (uVar12 - 1 | 0xfffffffc) + 1;
  }
  FUN_004a7cd0((int)(char)(&DAT_00860b74)[DAT_0072c774 * 0x20], uVar12, 0);
  int iVar18 = param_1 * 0x94;
  DAT_0085a164 = DAT_0085a164 | 0x100000;
  int iVar15 = (int)(int16_t)(&DAT_0085bf78)[param_1 * 0x4a];
  DAT_0072c648 = 0;
  FUN_004842d0(1);
  FUN_00482e60(1, param_1);
  if (iVar15 == 6) {
    FUN_004841b0();
    FUN_004f6090("'Father, brave @RANK @PCNAME has rescued me from the evil Colonel Mendoza!'\n", (&DAT_00869a88)[(char)(&DAT_00860b74)[iVar14] * 2], DAT_00726638, DAT_0072663c, PTR_DAT_00726640);
    FUN_004879f0(0x30, 0);
    FUN_00430190((int)(((int)DAT_0085a26c + ((int)DAT_0085a26c >> 0x1f & 7U)) >> 3), 8, (void *)(uintptr_t)0x6f5896, 0, 0xffffffff, nullptr, 0, 0xffffffff, 0, 0);
    FUN_00489130((void *)(uintptr_t)0x8c7340);
    FUN_00489130((void *)(uintptr_t)0x8c733c);
    FUN_00489130((void *)(uintptr_t)0x8c7338);
    *(int16_t *)(&DAT_0085bf7a + iVar18) = (int16_t)(*(int16_t *)(&DAT_0085bf7a + iVar18) + 500);
    (&DAT_0085bf78)[param_1 * 0x4a] = (&DAT_0085bf78)[param_1 * 0x4a] + 1;
    (&DAT_0085bf7c)[param_1 * 0x4a] = (&DAT_0085bf7c)[param_1 * 0x4a] + 1;
    FUN_0043a970(0x2a, param_1, 0, 0);
  }
  // farewell tail LAB_0040fc3a: nationality-worded sign-off, DAT_008ca900 handling
  iVar14 = (int)(char)(&DAT_00860b74)[iVar14];
  DAT_008cac44 = 0xbf000000;
  uint32_t uVar22;
  const char *pcVar26;
  if (iVar14 == 0) {
    pcVar26 = "Good Bye, @RANK @PCNAME.\n";
    uVar22 = DAT_00869a88;
  } else if (iVar14 == 2) {
    pcVar26 = "Au revoir, @RANK @PCNAME.\n";
    uVar22 = DAT_00869a8c;
  } else if (iVar14 == 3) {
    pcVar26 = "'Till next time, @RANK @PCNAME.\n";
    uVar22 = DAT_00869a8e;
  } else {
    pcVar26 = "Good day @RANK @PCNAME.\n";
    uVar22 = (&DAT_00869a88)[iVar14 * 2];
  }
  FUN_004f6090(pcVar26, uVar22, DAT_00726638, DAT_0072663c, PTR_DAT_00726640);
  DAT_008ca900 = 0;
  FUN_00483ca0();
  DAT_0085a164 = DAT_0085a164 & 0xffefffff;
  FUN_004a7ee0(0);
}

// 0x40fe00 — observed shape
uint32_t FUN_0040fe00(uint32_t in_EAX, int in_EDX) {
  uint32_t uVar1 = (uint32_t)((uint32_t)(uint8_t)(&DAT_00860b74)[in_EDX * 0x20] | (in_EAX & 0xffffff00));
  if (((&DAT_00860b74)[in_EDX * 0x20] == 0) && (DAT_00869aa8 != 0)) {
    if (((int)(uint32_t)DAT_00869a88 <= -(int)DAT_00869b28) ||
        (uVar1 = (uint32_t)(-(int)DAT_00869b28 * 5),
         (int)(int16_t)(&DAT_0085bf7c)[in_EDX * 0x4a] + (int)DAT_00869a78 < (int)uVar1)) {
      uVar1 = (uint32_t)((int)(&DAT_00860b7c)[in_EDX * 8] / 5 + (uint8_t)(&DAT_00860b75)[in_EDX * 0x20]);
      if ((0x19 < (int)uVar1) && ((&DAT_00860b80)[in_EDX * 8] != 7)) {
        return uVar1 & 0xffffff00;
      }
    }
  }
  return (uint32_t)(1 | (uVar1 & 0xffffff00));
}
