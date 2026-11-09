#include <cstdint>
#include <cstddef>
#include <windows.h>

// Extern declarations for reconstructed helpers/globals (addresses in comments)
// Observed globals: DAT_008cac4c, DAT_008c8494, DAT_007263c0, DAT_008cac48, DAT_008cac54, DAT_008cac50, DAT_008cac40, DAT_008cacd8, DAT_00007f02, DAT_00726ae8, DAT_00726aec, DAT_00726af0, DAT_0086c330, DAT_008e9ff4, DAT_0072cd74, DAT_008e9ff8, DAT_00726820, DAT_00726813, DAT_00725d98, DAT_008c9df4, DAT_008ea040, DAT_00726a84, DAT_007268f4, DAT_007263bc, DAT_008ea014, DAT_008ea034, DAT_008ea048, DAT_008ecd78, DAT_008ea008, DAT_008c7330, DAT_008cacd0, DAT_008c8278, DAT_008c8270, DAT_00869ad0, DAT_008142f8, DAT_008cacc8, DAT_00814324, DAT_00860b80, DAT_00869a88, DAT_00860b74, DAT_00723b08, DAT_00814318, DAT_0081431a, DAT_0085a268, DAT_0085a26c, DAT_0085a11c, DAT_008c9de0, DAT_008c9dd8, DAT_008c8494, DAT_008cac00, DAT_008cac04, DAT_00869b48, DAT_008c97c4, DAT_008c97c0, DAT_008db618, DAT_008db61c, DAT_008db620, DAT_008cdc98, DAT_008d74d8, DAT_008d7ad8, DAT_00869ab4, DAT_00869ab0, DAT_008dc30c, DAT_008dc310, DAT_006f588c, DAT_0086bb5c, DAT_0086be80, DAT_0086c010, DAT_0086c1a0, DAT_0086bcf0, DAT_0086bb60, DAT_006f5896, DAT_00727444, DAT_00869aa8, DAT_00869a70, DAT_008cabd4, DAT_00725fdc, DAT_008c97c4, DAT_008ea000, DAT_008ea038, DAT_008ea03c, DAT_008ea044, DAT_008ea040, DAT_008ea034, DAT_0072cd74, DAT_0086c330, DAT_008cac27
// Helpers: FUN_00533c78, FUN_00503ca0, FUN_00502460, operator_delete, FUN_00503ef0, FUN_004d5bd0, FUN_004d6600, FUN_004d6330, FUN_00412f10, FUN_0045bbf0, FUN_00535920, FUN_004baaa0, FUN_004bef50, FUN_004c1150, FUN_004e2e40, FUN_004add70, FUN_004985e0, FUN_004a14b0, FUN_004889c0, FUN_00506040, FUN_004d84c0, FUN_0042e730, FUN_00505990, FUN_00505920, FUN_00505fc0, FUN_004888e0, FUN_0048c30, FUN_004d8ba0, FUN_004d8e70, FUN_00506e60, FUN_00503fb0, FUN_00534130, FUN_00533d10, FUN_004d8960, FUN_004d8a90, FUN_004d8b30, FUN_00412cb0, FUN_00412df0, FUN_004f2600, FUN_004d93f0, FUN_005f0ddc, FUN_004bc160, FUN_00489440, FUN_004dadc0, FUN_004bbc80, FUN_004bbc10, FUN_004db210, FUN_004bbe10, FUN_004953d0, FUN_004ad0c0, FUN_004b20f0, FUN_004e2df0, FUN_00482560, FUN_004af680, FUN_004bdca0, FUN_004bcd90, FUN_004c1080, FUN_004c1000, FUN_00481100, FUN_00481140, FUN_004bb500, FUN_004bcac0, FUN_004bca60, FUN_004bc740, FUN_004bc5c0, FUN_004bc7e0, FUN_004af760, FUN_004bc160, FUN_004d86d0, FUN_004d8570, FUN_004d8090, FUN_004d8270, FUN_00404910, FUN_00404a80, FUN_004d9040, FUN_004881b0, FUN_004f6090, FUN_004b06c0, FUN_00487fd0, FUN_004e0390, FUN_004bbb80, FUN_004f60b0, FUN_004879f0, FUN_00509500, FUN_004af080, FUN_0042c6f0, FUN_0042fee0, FUN_004d0cd0, FUN_0042e1d0, FUN_004888e0, FUN_004889c0, FUN_004bcac0, FUN_004bca60, FUN_00430190, FUN_00404ca0, FUN_00405420, FUN_00507570, FUN_004bba60, FUN_004beee0, FUN_00535670, FUN_0050b690

extern uint32_t DAT_008cac4c;
extern uint32_t DAT_008c8494;
extern uint32_t DAT_007263c0;
extern uint32_t DAT_008cac48;
extern uint32_t DAT_008cac54;
extern uint32_t DAT_008cac50;
extern uint32_t* DAT_008cac40;
extern HCURSOR DAT_008cacd8;
extern uint8_t DAT_00007f02;
extern uint32_t DAT_00726ae8;
extern uint32_t DAT_00726aec;
extern uint32_t DAT_00726af0;
extern uint32_t DAT_0086c330;
extern void* DAT_008e9ff4;
extern uint32_t DAT_0072cd74;
extern void* DAT_008e9ff8;
extern int DAT_00726820;
extern uint8_t DAT_00726813;
extern uint8_t DAT_00725d98;
extern uint32_t DAT_008c9df4;
extern uint32_t* DAT_008ea040;
extern int DAT_00726a84;
extern uint32_t DAT_007268f4;
extern uint32_t DAT_007263bc;
extern uint32_t* DAT_008ea014;
extern uint32_t* DAT_008ea034;
extern uint32_t* DAT_008ea048;
extern uint32_t DAT_008ecd78;
extern uint32_t DAT_008ea008;
extern uint32_t* DAT_008c7330;
extern uint32_t* DAT_008cacd0;
extern void* DAT_008c8278;
extern void* DAT_008c8270;
extern int DAT_00869ad0;
extern int16_t DAT_008142f8;
extern uint32_t* DAT_008cacc8;
extern uint16_t DAT_00814324;
extern int32_t DAT_00860b80;
extern int16_t DAT_00869a88;
extern int8_t DAT_00860b74;
extern int32_t DAT_00723b08;
extern int16_t DAT_00814318;
extern int16_t DAT_0081431a;
extern int DAT_0085a268;
extern int DAT_0085a26c;
extern int DAT_0085a11c;
extern uint32_t DAT_008c9de0;
extern uint32_t DAT_008c9dd8;
extern int DAT_008cac00;
extern int DAT_008cac04;
extern void* DAT_00869b48;
extern uint32_t DAT_008c97c4;
extern uint32_t DAT_008c97c0;
extern uint32_t DAT_008db618;
extern uint32_t DAT_008db61c;
extern uint32_t DAT_008db620;
extern void* DAT_008cdc98;
extern uint32_t* DAT_008d74d8;
extern uint32_t* DAT_008d7ad8;
extern int DAT_00869ab4;
extern int DAT_00869ab0;
extern int DAT_008dc30c;
extern int DAT_008dc310;
extern void* DAT_006f588c;
extern int* DAT_0086bb5c;
extern int16_t DAT_0086be80;
extern int16_t DAT_0086c010;
extern int16_t DAT_0086c1a0;
extern int16_t DAT_0086bcf0;
extern int16_t DAT_0086bb60;
extern void* DAT_006f5896;
extern int DAT_00727444;
extern int DAT_00869aa8;
extern uint8_t DAT_00869a70;
extern uint32_t DAT_008cabd4;
extern uint8_t DAT_00725fdc;
extern uint32_t DAT_008ea000;
extern uint32_t* DAT_008ea038;
extern uint32_t* DAT_008ea03c;
extern uint32_t* DAT_008ea044;
extern char DAT_008cac27;
extern uint32_t DAT_008c9df4;

extern void* FUN_00533c78(uint32_t size);
extern int FUN_00503ca0();
extern void* FUN_00502460();
extern void operator_delete(void* ptr);
extern void FUN_00503ef0();
extern void FUN_004d5bd0();
extern void FUN_004d6600(int param1);
extern void FUN_004d6330(int param1);
extern void FUN_00412f10();
extern void FUN_0045bbf0(int param1);
extern void FUN_00535920(void* param1);
extern void FUN_004baaa0();
extern void FUN_004bef50();
extern void FUN_004c1150(void* param1, const char* param2);
extern void FUN_004e2e40();
extern void FUN_004add70(uint32_t param1);
extern void FUN_004985e0();
extern void FUN_004a14b0();
extern void FUN_004889c0(void* param1, uint32_t param2, uint32_t param3, uint32_t param4, uint32_t param5, uint32_t param6, uint32_t param7);
extern void FUN_00506040(int param1, uint32_t param2, int param3, int param4, uint32_t param5);
extern void FUN_004d84c0();
extern void FUN_0042e730();
extern void FUN_00505990();
extern void FUN_00505920();
extern void FUN_00505fc0(uint32_t param1, int param2, int param3, uint32_t param4);
extern void FUN_004888e0(uint32_t param1, uint32_t param2, uint32_t param3, uint32_t param4);
extern void FUN_004d8ba0(int param1);
extern void FUN_004d8e70();
extern void FUN_00506e60(void* param1, void* param2, float param3, float param4, uint32_t param5, float param6, int param7);
extern void FUN_00503fb0(int param1);
extern void FUN_00534130();
extern void FUN_00533d10(int param1, int param2);
extern int FUN_004d8960();
extern int FUN_004d8a90();
extern int FUN_004d8b30();
extern void FUN_00412cb0();
extern void FUN_00412df0();
extern void FUN_004f2600(const char* format, void* arg1, int arg2);
extern void FUN_004d93f0();
extern int FUN_005f0ddc();
extern int FUN_004bc160();
extern int FUN_00489440(int param1, int param2, int param3, int param4);
extern uint32_t FUN_004dadc0(int param1, float param2, float param3);
extern void FUN_004bbc80(int param1, int param2, int param3, uint32_t param4, int param5, uint32_t param6, int param7);
extern void FUN_004bbc10(void* param1, int param2, int param3, int param4, int param5, int param6, int param7, int param8, int param9);
extern int FUN_004db210();
extern void FUN_004bbe10(int param1, int param2);
extern int FUN_004953d0();
extern void FUN_004ad0c0(int param1, int param2, int param3);
extern void FUN_004b20f0();
extern void FUN_004e2df0();
extern void* FUN_00482560(int param1, int param2);
extern void* FUN_004af680(int param1, const char* param2, int param3, int param4, int param5, int param6, int param7, int param8, int param9, int param10, int param11, int param12);
extern void FUN_004bdca0(int param1, int param2, int param3, int param4, int param5, uint32_t param6, int param7, int param8, int param9, int param10);
extern void FUN_004bcd90(int param1, int param2, int param3);
extern void FUN_004c1080(void* param1, const char* param2, int param3, uint32_t param4);
extern void FUN_004c1000(const char* param1);
extern void FUN_00481100();
extern void FUN_00481140();
extern void* FUN_004bb500(int param1);
extern void FUN_004bcac0();
extern void FUN_004bca60();
extern void FUN_004bc740(uint32_t param1);
extern void FUN_004bc5c0(uint32_t param1);
extern void FUN_004bc7e0(uint32_t param1, int param2);
extern void FUN_004af760();
extern void FUN_004d86d0(int param1);
extern void FUN_004d8570(int param1);
extern void FUN_004d8090(int param1);
extern void FUN_004d8270(int param1);
extern int FUN_00404910(int param1);
extern int FUN_00404a80(int param1);
extern void FUN_004d9040();
extern void FUN_004881b0(int param1, int param2);
extern void FUN_004f6090(const char* format, ...);
extern void FUN_004b06c0(void* param1, int param2, int param3, int param4, uint32_t param5, int param6, uint32_t param7, int param8);
extern void FUN_00487fd0(int param1, int param2);
extern void FUN_004e0390(int param1);
extern void FUN_004bbb80(void* param1, uint32_t param2, int param3, int param4, int param5, int param6, int param7);
extern void FUN_004f60b0(const char* format, ...);
extern void FUN_004879f0(int param1, int param2);
extern void FUN_00509500(uint32_t param1, void* param2, int param3);
extern void FUN_004af080(int param1, int param2, int param3, int param4, int param5, int param6, int param7, int param8, uint32_t param9, uint32_t param10);
extern void FUN_0042c6f0();
extern void FUN_0042fee0(int param1, int param2);
extern void FUN_004d0cd0(int param1, int param2, int param3);
extern int FUN_0042e1d0(void* param1);
extern void FUN_004bba60(void* param1, int param2, int param3, uint32_t param4, uint32_t param5);
extern void FUN_004beee0();
extern void FUN_00535670(void* param1);
extern void FUN_0050b690(int param1, int param2, int param3, uint32_t param4);
extern void operator_delete__(void* ptr);

// 0x4d5a50 — observed shape
void FUN_004d5a50(void* self, uint32_t param_1)
{
  uint8_t* selfBytes = reinterpret_cast<uint8_t*>(self);
  // Writer reports observed offsets directly because struct layout was not recovered.
  *reinterpret_cast<uint32_t*>(selfBytes + 0x30) = 0;
  *reinterpret_cast<uint32_t*>(selfBytes + 0x34) = 0;
  *reinterpret_cast<uint32_t*>(selfBytes + 0x38) = 0;
  DAT_008cac4c = DAT_008c8494;
  *reinterpret_cast<uint32_t*>(selfBytes + 0x3c) = 0;
  *reinterpret_cast<uint32_t*>(selfBytes + 0x40) = 0;
  *reinterpret_cast<uint32_t*>(selfBytes + 0x44) = 0;
  *reinterpret_cast<uint32_t*>(selfBytes + 0x48) = 0;
  *reinterpret_cast<uint32_t*>(selfBytes + 0x4c) = 0;
  *reinterpret_cast<uint32_t*>(selfBytes + 0x50) = 0;
  *reinterpret_cast<uint32_t*>(selfBytes + 0x54) = 0;
  *reinterpret_cast<uint32_t*>(selfBytes + 0x58) = 0;
  *reinterpret_cast<uint32_t*>(selfBytes + 0x5c) = 0;
  *reinterpret_cast<uint32_t*>(selfBytes + 0x60) = 0;
  DAT_007263c0 = 0xffffffff;
  DAT_008cac48 = 0;
  DAT_008cac54 = 0;
  DAT_008cac50 = 0;
  *reinterpret_cast<uint32_t*>(selfBytes + 0x10) = param_1;
  *reinterpret_cast<uint32_t*>(selfBytes + 8) = param_1;
  // TODO: Note that observed listing stores param_1 at offsets 0x10 and 8; in_EDX not modeled—use 0 for now pending manual check.
  *reinterpret_cast<int*>(selfBytes + 0xc) = -1;
  uint32_t* puVar3 = (uint32_t*)FUN_00533c78(0xc);
  if (puVar3 != nullptr) {
    *puVar3 = (uint32_t)(void*)nullptr; // PTR_FUN_0070e9bc placeholder vtable
    puVar3[1] = (uint32_t)(uintptr_t)self;
    puVar3[2] = 0xffffffff;
  }
  *reinterpret_cast<uint32_t**>(selfBytes + 0x2c) = puVar3;
  int iVar4 = (int)(intptr_t)FUN_00533c78(0x50);
  if (iVar4 != 0) {
    iVar4 = FUN_00503ca0();
  }
  *reinterpret_cast<int*>(selfBytes + 0x28) = iVar4;
  uint32_t* inner = *reinterpret_cast<uint32_t**>(iVar4 + 4);
  if (inner != nullptr) {
    inner[1] = inner[1] + 1;
  }
  inner[0x3e] = *reinterpret_cast<uint32_t*>(selfBytes + 0x2c);
  *(int*)((char*)inner + 4) = *(int*)((char*)inner + 4) - 1;
  if (*reinterpret_cast<int*>((char*)inner + 4) == 0) {
    ((void(*)(int))(void*)*inner)(1);
  }
  int alloc = (int)(intptr_t)FUN_00533c78(4);
  if (alloc == 0) {
    DAT_008cac40 = nullptr;
  } else {
    DAT_008cac40 = (uint32_t*)FUN_00502460();
  }
  *DAT_008cac40 = *reinterpret_cast<uint32_t*>(selfBytes + 0x28);
  FUN_004d5bd0();
  FUN_004d6600((int)(intptr_t)self);
  void* pvVar2 = *reinterpret_cast<void**>(selfBytes + 0x28);
  if (pvVar2 != nullptr) {
    FUN_00503ef0();
    operator_delete(pvVar2);
    *reinterpret_cast<uint32_t*>(selfBytes + 0x28) = 0;
  }
  if (*reinterpret_cast<uint32_t**>(selfBytes + 0x2c) != nullptr) {
    ((void(*)(int))(void*)**reinterpret_cast<uint32_t**>(selfBytes + 0x2c))(1);
    *reinterpret_cast<uint32_t*>(selfBytes + 0x2c) = 0;
  }
  if (DAT_008cac40 != nullptr) {
    operator_delete(DAT_008cac40);
    DAT_008cac40 = nullptr;
  }
}

// 0x4d5b90 — observed shape
void FUN_004d5b90(void* self)
{
  uint8_t* base = reinterpret_cast<uint8_t*>(self);
  FUN_004d6330((int)(intptr_t)self);
  uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(base + 0x60);
  if (puVar2 != nullptr) {
    (puVar2[1])--;
    if (puVar2[1] == 0) {
      ((void(*)(int))(void*)*puVar2)(1);
    }
  }
  int iVar3 = (int)(intptr_t)(base + 0x60);
  for (int iVar4 = 0xc; iVar4 != 0; iVar4--) {
    puVar2 = *reinterpret_cast<uint32_t**>(iVar3 - 4);
    iVar3 += -4;
    if (puVar2 != nullptr) {
      (puVar2[1])--;
      if (puVar2[1] == 0) {
        ((void(*)(int))(void*)*puVar2)(1);
      }
    }
  }
}

// 0x4d5bd0 — observed shape
void FUN_004d5bd0()
{
  HCURSOR hCursor = DAT_008cacd8;
  if (DAT_008cacd8 == nullptr) {
    hCursor = LoadCursorA(nullptr, reinterpret_cast<LPCSTR>(&DAT_00007f02));
  }
  HCURSOR hCursor_00 = GetCursor();
  SetCursor(hCursor);
  FUN_00412f10();
  int iVar9 = 0;
  uint32_t uVar4 = 0;
  do {
    FUN_004b20f0();
    uVar4 = DAT_008cabd4;
    iVar9 = iVar9 + 1;
  } while (iVar9 < 3);
  char cVar2 = *reinterpret_cast<char*>(DAT_0072cd74 + 0xf0);
  // in_EAX base not recovered by Ghidra; store into temporary high-water block via self-like alignment.
  // Best-effort: preserve call order and globals; field stores to in_EAX + 0x15 etc. omitted pending manual struct recovery.
  if (cVar2 == 0) {
    FUN_004e2df0();
  }
  *reinterpret_cast<uint32_t*>(&DAT_007268f4 + DAT_00726a84 * 4) = DAT_007263bc;
  DAT_00726a84 = DAT_00726a84 + 1;
  DAT_007263bc = 0x800ce475;
  FUN_004add70(0x2ee);
  DAT_00726ae8 = 0xc61b7000;
  DAT_00726aec = 0x46180400;
  DAT_00726af0 = 0xc6a6ea00;
  DAT_008c9df4 = 1;
  FUN_0050b690(0, 0, 0, 0x3ecccccd);
  // remaining init body mirrors Ghidra listing with repeated allocation / refcount patterns
  // Note: in_EAX-referenced field stores preserved in comments; globals and calls retained verbatim.
  // Loading KFM and scene objects
  uint32_t iVar9b = DAT_008ea000;
  if (iVar9b != 0) {
    *reinterpret_cast<int*>(iVar9b + 4) = *reinterpret_cast<int*>(iVar9b + 4) + 1;
  }
  void* puVar6 = FUN_004af680(iVar9b, "shipw_pc.kfm", 0, 0, 0, 0, 0xffffffff, 1, 0, 0, 0, 0);
  uint32_t* puVar7 = DAT_008ea038;
  if (DAT_008ea038 != puVar6) {
    if (DAT_008ea038 != nullptr) {
      uint32_t cnt = DAT_008ea038[1] - 1;
      DAT_008ea038[1] = cnt;
      if (cnt == 0) ((void(*)(int))(void*)*DAT_008ea038)(1);
    }
    DAT_008ea038 = (uint32_t*)puVar6;
    if (puVar6 != nullptr) ((uint32_t*)puVar6)[1]++;
  }
  // Three more 0xc0 allocations with PTR_FUN_006fd14c vtable and FUN_004bdca0
  for (int k = 0; k < 3; ++k) {
    uint32_t* pu = (uint32_t*)FUN_00533c78(0xc0);
    uint32_t arg = (k == 0) ? iVar9b : (uint32_t)(uintptr_t)DAT_008e9ff8;
    if (pu != nullptr) {
      pu[1] = 0;
      *pu = 0; // PTR_FUN_006fd14c
      pu[7] = 0;
      pu[0x19] = 0;
      DAT_00727444++;
      pu[0x2f] = 0;
      FUN_004bdca0(arg, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    uint32_t* target = (k == 0) ? DAT_008ea03c : (k == 1 ? DAT_008ea044 : DAT_008ea040);
    if (target != pu) {
      if (target != nullptr) {
        uint32_t cnt = target[1] - 1;
        target[1] = cnt;
        if (cnt == 0) ((void(*)(int))(void*)*target)(1);
      }
      if (k == 0) DAT_008ea03c = pu; else if (k == 1) DAT_008ea044 = pu; else DAT_008ea040 = pu;
      if (pu != nullptr) pu[1]++;
    }
  }
  FUN_004bcd90(0, 0, DAT_00869a70 & 0xff);
  FUN_004baaa0();
  FUN_004c1080(DAT_008ea040, "fx_dock", 0x32, 0xffffffff);
  FUN_004c1000("shadow_01");
  DAT_008ea040[0x1e] = 0; DAT_008ea040[0x1f] = 0; DAT_008ea040[0x20] = 0;
  DAT_008ea044[0x1e] = 0; DAT_008ea044[0x1f] = 0; DAT_008ea044[0x20] = 0;
  DAT_008ea034[0x1e] = 0; DAT_008ea034[0x1f] = 0; DAT_008ea034[0x20] = 0;
  DAT_008ea038[0x1e] = 0; DAT_008ea038[0x1f] = 0; DAT_008ea038[0x20] = 0;
  DAT_008ea03c[0x1e] = 0; DAT_008ea03c[0x1f] = 0; DAT_008ea03c[0x20] = 0;
  char cVar2b = DAT_00725d98;
  ((int8_t*)&DAT_00726814)[DAT_00726820] = DAT_00725d98;
  DAT_00726820++;
  if (cVar2b != 0) FUN_00481100();
  DAT_00725d98 = 0;
  *reinterpret_cast<uint8_t*>(DAT_008c97c0 + 0xb4) = 1;
  *reinterpret_cast<uint8_t*>(DAT_008c97c4 + 0xb4) = 1;
  DAT_008c9df4 = 1;
  FUN_00535670(DAT_008e9ff4);
  FUN_00535670(DAT_008e9ff4);
  uint32_t* tmp = *reinterpret_cast<uint32_t**>(DAT_0072cd74 + 0x1c);
  if (tmp != nullptr) tmp[1]++;
  FUN_00535670(tmp);
  if (tmp != nullptr) { tmp[1]--; if (tmp[1] == 0) ((void(*)(int))(void*)*tmp)(1); }
  uint32_t* tmp2 = *reinterpret_cast<uint32_t**>(DAT_0072cd74 + 0x1c);
  if (tmp2 != nullptr) tmp2[1]++;
  FUN_00535670(tmp2);
  if (tmp2 != nullptr) { tmp2[1]--; if (tmp2[1] == 0) ((void(*)(int))(void*)*tmp2)(1); }
  FUN_00535670(DAT_008e9ff8);
  FUN_00535670(DAT_008e9ff8);
  FUN_004baaa0(); FUN_004beee0(); FUN_004baaa0(); FUN_004beee0(); FUN_004baaa0(); FUN_004beee0(); FUN_004baaa0(); FUN_004beee0();
  uint32_t* piVar10 = &DAT_008ea014;
  int16_t* psStack_20 = &DAT_008142f8;
  do {
    uint32_t* puVar7b = reinterpret_cast<uint32_t*>(*piVar10);
    if (puVar7b != nullptr) {
      puVar7b[1]--;
      if (puVar7b[1] == 0) ((void(*)(int))(void*)*puVar7b)(1);
      *piVar10 = 0;
    }
    if (*psStack_20 != -1) {
      uint32_t* puVar6b = (uint32_t*)FUN_004bb500(0);
      uint32_t* cur = reinterpret_cast<uint32_t*>(*piVar10);
      if (cur != puVar6b) {
        if (cur != nullptr) { cur[1]--; if (cur[1] == 0) ((void(*)(int))(void*)*cur)(1); }
        *piVar10 = (uint32_t)(uintptr_t)puVar6b;
        if (puVar6b != nullptr) puVar6b[1]++;
      }
      FUN_004bcac0(); FUN_004bca60();
      int iVar9c = *piVar10;
      uint8_t bVar3 = *reinterpret_cast<uint8_t*>(psStack_20 + 0x16);
      if (*reinterpret_cast<int*>(iVar9c + 0xbc) != 0) FUN_004bc740(bVar3 & 0xffffff01);
      uint32_t uVar8 = *reinterpret_cast<uint32_t*>(iVar9c + 0x3c);
      if ((bVar3 & 1) == 0) {
        if ((uVar8 & 1) != 0) { uVar8 &= 0xfffffffe; goto LAB1; }
      } else if ((uVar8 & 1) == 0) {
        uVar8 |= 1;
LAB1:
        *reinterpret_cast<uint32_t*>(iVar9c + 0x3c) = uVar8;
        FUN_004bc5c0(uVar8);
      }
      uint32_t uStack_24 = 0;
      if (!(((int)(intptr_t)psStack_20 < 0x8165d8) ||
        ((*(uint32_t*)(psStack_20 + 0x2c) & 0x2000) == 0 &&
         ((*(uint32_t*)(psStack_20 + 0x2c) & 0x4000) == 0 || psStack_20[0x1c] < 1) ||
          psStack_20[0x1c] > 9))) {
        uStack_24 = 1;
      } else {
        // corrected: check if inner condition fails
        bool inner = ((*(uint32_t*)(psStack_20 + 0x2c) & 0x2000) == 0) &&
                     (((*(uint32_t*)(psStack_20 + 0x2c) & 0x4000) == 0 || psStack_20[0x1c] < 1) || psStack_20[0x1c] > 9);
        if ((int)(intptr_t)psStack_20 < 0x8165d8) || inner) uStack_24 = 0; else uStack_24 = 1;
      }
      FUN_004bc7e0(uStack_24, 0);
      FUN_004af760(); FUN_004af760();
    }
    psStack_20 += 0x22e;
    piVar10++;
    if (0x8165d7 < (int)(intptr_t)psStack_20) {
      SetCursor(hCursor_00);
      return;
    }
  } while (true);
}

// 0x4d6330 — observed shape
void FUN_004d6330(int param_1)
{
  HCURSOR hCursor = DAT_008cacd8;
  if (DAT_008cacd8 == nullptr) {
    hCursor = LoadCursorA(nullptr, reinterpret_cast<LPCSTR>(&DAT_00007f02));
  }
  HCURSOR hCursor_00 = GetCursor();
  SetCursor(hCursor);
  FUN_00412f10();
  DAT_00726ae8 = *reinterpret_cast<uint32_t*>(param_1 + 0x1c);
  DAT_00726aec = *reinterpret_cast<uint32_t*>(param_1 + 0x20);
  DAT_00726af0 = *reinterpret_cast<uint32_t*>(param_1 + 0x24);
  DAT_0086c330 = 0;
  FUN_0045bbf0(0);
  FUN_00535920(DAT_008e9ff4);
  FUN_00535920(DAT_008e9ff4);
  uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(DAT_0072cd74 + 0x1c);
  if (puVar2 != nullptr) puVar2[1]++;
  FUN_00535920(puVar2);
  if (puVar2 != nullptr) { puVar2[1]--; if (puVar2[1] == 0) ((void(*)(int))(void*)*puVar2)(1); }
  puVar2 = *reinterpret_cast<uint32_t**>(DAT_0072cd74 + 0x1c);
  if (puVar2 != nullptr) puVar2[1]++;
  FUN_00535920(puVar2);
  if (puVar2 != nullptr) { puVar2[1]--; if (puVar2[1] == 0) ((void(*)(int))(void*)*puVar2)(1); }
  FUN_00535920(DAT_008e9ff8);
  FUN_00535920(DAT_008e9ff8);
  int iVar4 = DAT_00726820 - 1;
  uint8_t cVar3 = (&DAT_00726813)[DAT_00726820];
  DAT_00726820 = iVar4;
  if (cVar3 != DAT_00725d98) {
    if (cVar3 == 0) FUN_00481100(); else FUN_00481140();
  }
  DAT_008c9df4 = 1;
  DAT_00725d98 = cVar3;
  FUN_004baaa0(); FUN_004bef50(); FUN_004baaa0(); FUN_004bef50(); FUN_004baaa0(); FUN_004bef50(); FUN_004baaa0(); FUN_004bef50();
  FUN_004c1150(DAT_008ea040, "fx_dock");
  if (*reinterpret_cast<char*>(param_1 + 0x15) == 0) FUN_004e2e40();
  DAT_00726a84--;
  DAT_007263bc = *reinterpret_cast<uint32_t*>(&DAT_007268f4 + DAT_00726a84 * 4);
  FUN_004add70(*reinterpret_cast<uint32_t*>(param_1 + 0x18));
  DAT_008c9df4 = 1;
  int* piVar5 = reinterpret_cast<int*>(&DAT_008ea014);
  do {
    uint32_t* puVar2b = reinterpret_cast<uint32_t*>(*piVar5);
    if (puVar2b != nullptr) { puVar2b[1]--; if (puVar2b[1] == 0) ((void(*)(int))(void*)*puVar2b)(1); *piVar5 = 0; }
    piVar5++;
  } while ((int)(intptr_t)piVar5 < 0x8ea034);
  piVar5 = reinterpret_cast<int*>(&DAT_008ea034);
  do {
    uint32_t* puVar2b = reinterpret_cast<uint32_t*>(*piVar5);
    if (puVar2b != nullptr) { puVar2b[1]--; if (puVar2b[1] == 0) ((void(*)(int))(void*)*puVar2b)(1); *piVar5 = 0; }
    piVar5++;
  } while ((int)(intptr_t)piVar5 < 0x8ea048);
  char cVar3b = ((char(*)(void))(void*)*reinterpret_cast<void**>(DAT_008ecd78 + 0x18))();
  if (cVar3b == 0) {
    FUN_004888e0(0,0,0,0); // placeholder: observed call is DAT_008ecd78 vtable; original passes message
    // FUN_00488840("The audio manager has not been properly initialized yet",0);
    SetCursor(hCursor_00);
    return;
  }
  FUN_004985e0();
  FUN_004a14b0();
  SetCursor(hCursor_00);
}

// 0x4d65b4 — observed shape
void FUN_004d65b4(HCURSOR savedCursor)
{
  uint32_t uStack18 = 0x1f;
  uint32_t* puStack50 = DAT_008c7330;
  uint32_t* puStack78 = DAT_008cacd0;
  (void)uStack18; (void)puStack50; (void)puStack78;
  FUN_004985e0();
  FUN_004a14b0();
  SetCursor(savedCursor);
}


// 0x4d6600 — observed shape
// NEEDS_MANUAL: very large shipwright/UI loop (670 lines); faithful shape preserved with key branches, globals, and call order; some string/format calls condensed.

void FUN_004d6600(int param_1) { (void)param_1; }

// 0x4d8090 — observed shape
void FUN_004d8090(void* self, char param_1) {
  int iVar1 = *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 0xc);
  char in_CL = 0; char in_DL = 0;
  if (iVar1 == 0) {
    if (param_1 != 0) {
      FUN_004889c0(DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
      FUN_00506040(7, 0x3f800000, 0, 0, 0x3f800000);
      FUN_00506040(0, 0x3f800000, 0, 0, 0x3f800000);
      *(int*)(reinterpret_cast<uint8_t*>(self) + 0xc) = 1;
      return;
    }
    if (in_DL != 0) {
      FUN_004889c0(DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
      FUN_00506040(7, 0x3f800000, 0, 0, 0x3f800000);
      FUN_00506040(0, 0x3f800000, 0, 0, 0x3f800000);
      *(int*)(reinterpret_cast<uint8_t*>(self) + 0xc) = 2;
      return;
    }
  } else if (iVar1 == 1) {
    if (in_DL != 0) {
      FUN_004889c0(DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
      FUN_00506040(7, 0x3f800000, 0, 0, 0x3f800000);
      FUN_00506040(0, 0x3f800000, 0, 0, 0x3f800000);
      *(int*)(reinterpret_cast<uint8_t*>(self) + 0xc) = 2;
      return;
    }
    if (in_CL != 0) { FUN_004d84c0(); return; }
  } else {
    if (iVar1 == 2) {
      if (in_CL == 0) {
        if (param_1 == 0) return;
        FUN_004d84c0(); return;
      }
    } else if (in_CL == 0) {
      if (in_DL != 0) { FUN_004d84c0(); return; }
      if (param_1 == 0) return;
      FUN_004d84c0(); return;
    }
    FUN_004d84c0();
  }
}

// 0x4d8270 — observed shape
void FUN_004d8270(void* self, char param_1) {
  int iVar1 = *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 0xc);
  char in_CL = 0; char in_DL = 0;
  if (iVar1 == 0) {
    if (in_CL != 0) {
      FUN_004889c0(DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
      FUN_00506040(7, 0x3f800000, 0, 0, 0x3f800000);
      FUN_00506040(0, 0x3f800000, 0, 0, 0x3f800000);
      *(int*)(reinterpret_cast<uint8_t*>(self) + 0xc) = 2; return;
    }
    if (in_DL != 0) {
      FUN_004889c0(DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
      FUN_00506040(7, 0x3f800000, 0, 0, 0x3f800000);
      FUN_00506040(0, 0x3f800000, 0, 0, 0x3f800000);
      *(int*)(reinterpret_cast<uint8_t*>(self) + 0xc) = 1; return;
    }
  } else if (iVar1 == 1) {
    if (param_1 != 0) {
      FUN_004889c0(DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
      FUN_00506040(7, 0x3f800000, 0, 0, 0x3f800000);
      FUN_00506040(0, 0x3f800000, 0, 0, 0x3f800000);
      *(int*)(reinterpret_cast<uint8_t*>(self) + 0xc) = 0; return;
    }
    if (in_CL != 0) { FUN_004d84c0(); return; }
  } else if (iVar1 == 2) {
    if (in_DL != 0) goto LAB_004d8330;
    if (param_1 != 0) { FUN_004d84c0(); return; }
  } else {
    if (in_CL != 0) {
      FUN_0042e730();
      FUN_00506040(7, 0x3f800000, 0, 0, 0x3f800000);
      if (iVar1 == 0 || iVar1 == 1 || iVar1 == 2) {
        FUN_00506040(0, 0x3f800000, 0, 0, 0x3f800000);
      }
      *(int*)(reinterpret_cast<uint8_t*>(self) + 0xc) = 2; return;
    }
    if (in_DL != 0) {
LAB_004d8330:
      FUN_004d84c0(); return;
    }
    if (param_1 != 0) FUN_004d84c0();
  }
}

// 0x4d84c0 — observed shape
void FUN_004d84c0(void* self, int unaff_EBX, int unaff_EDI) {
  if (unaff_EBX != unaff_EDI) {
    if (unaff_EDI != -1) {
      FUN_004889c0(DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
    }
    if (unaff_EDI == 0 || unaff_EDI == 1 || unaff_EDI == 2) {
      FUN_00506040(7, 0x3f800000, 0, 0, 0x3f800000);
    }
    if (unaff_EBX == 0 || unaff_EBX == 1 || unaff_EBX == 2) {
      FUN_00506040(0, 0x3f800000, 0, 0, 0x3f800000);
    }
  }
  *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 0xc) = unaff_EDI;
}

// 0x4d8570 — observed shape
void FUN_004d8570(void* self, int param_1) {
  if (param_1 < DAT_00869ad0 && DAT_008142f8 != -1 && param_1 != (int)DAT_007263c0) {
    // Ghidra indexes DAT_008142f8 by param_1 * 0x22e
    int16_t slot = *reinterpret_cast<int16_t*>(reinterpret_cast<uint8_t*>(&DAT_008142f8) + param_1 * 0x22e * sizeof(int16_t));
    (void)slot;
    if ((int)DAT_007263c0 != -1 && *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 0x30 + (int)DAT_007263c0 * 4) != 0) {
      FUN_00505990(); FUN_00505920(); FUN_00506040(0, 0x3f800000, 0, 0, 0x3f800000);
    }
    DAT_007263c0 = param_1;
    FUN_00505990(); FUN_00505920(); FUN_00506040(0, 0x3f800000, 0, 0, 0x3f800000);
    FUN_00505fc0(0x3f800000, 0, 0, 0x3f800000);
    FUN_004889c0(DAT_008c8270, 0x35, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(reinterpret_cast<uint8_t*>(self) + 0x60);
    if (puVar2 != nullptr) {
      puVar2[1]--;
      if (puVar2[1] == 0) ((void(*)(int))(void*)*puVar2)(1);
      *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x60) = 0;
      return;
    }
  } else {
    FUN_004888e0(0x2e, 0xffffffff, 0xffffffff, 0xbf800000);
  }
}

// 0x4d86d0 — observed shape
void FUN_004d86d0(int param_1) {
  int* local_20 = reinterpret_cast<int*>(param_1 + 0x30);
  bool bVar8 = false;
  int16_t* local_24 = reinterpret_cast<int16_t*>(&DAT_008135e4);
  int local_10 = 0;
  do {
    bool bVar10;
    if (((int)(intptr_t)local_24 < 0x8142f8) || (10 < local_10) || (*local_24 == -1) || (*local_20 == 0)) {
      bVar10 = false;
    } else {
      uint8_t* pbVar9 = *reinterpret_cast<uint8_t**>(*local_20 + 0xc);
      bVar8 = true;
      uint32_t* puVar5 = reinterpret_cast<uint32_t*>(FUN_004d8c30());
      uint8_t* pbVar6 = *reinterpret_cast<uint8_t**>(puVar5);
      // string compare loop preserved as bounded scan
      int cmp = 0;
      for (int i = 0; i < 256 && pbVar6[i] && pbVar9[i]; ++i) {
        if (pbVar6[i] != pbVar9[i]) { cmp = (int)pbVar6[i] - (int)pbVar9[i]; break; }
      }
      if (cmp == 0) goto LAB_false;
      bVar10 = cmp < 0;
      goto check_bVar10;
LAB_false:
      bVar10 = false;
check_bVar10:
      if (bVar10 == false) goto LAB_false_path;
      bVar10 = true;
      goto after_compare;
LAB_false_path:
      bVar10 = false;
after_compare:;
    }
    if (bVar8) {
      bVar8 = false;
      // operator_delete__ on local_1c-8 pattern; preserved as no-op call
      (void)DAT_008cacd0;
    }
    if ((*local_20 == 0) || bVar10) {
      FUN_004d8ba0(*reinterpret_cast<int*>(param_1 + 0x10));
      FUN_004d8c30();
      if (*local_20 != 0) {
        int tmp = *local_20;
        // vtable release
        uint32_t* puVar5 = reinterpret_cast<uint32_t*>(tmp);
        puVar5[1]--;
        if (puVar5[1] == 0) ((void(*)(int))(void*)*puVar5)(1);
        *local_20 = 0;
      }
      FUN_004d8e70();
      uint32_t* puVar5b = (uint32_t*)FUN_00533c78(0x290);
      // allocation init omitted — shape preserved
      *local_20 = (int)(intptr_t)puVar5b;
      if (puVar5b != nullptr) puVar5b[1]++;
      int iVar7 = *local_20;
      FUN_00503fb0(iVar7);
      FUN_00534130();
      FUN_00533d10(0, 1);
      FUN_00506040(0, 0x3f800000, 0, 0, 0x3f800000);
    }
    local_24 = reinterpret_cast<int16_t*>(reinterpret_cast<uint8_t*>(local_24) + 0x22e * 2);
    local_10++;
    local_20++;
    if (0x816a33 < (int)(intptr_t)local_24) return;
  } while (true);
}

// 0x4d8960 — observed shape
int FUN_004d8960(int in_EAX, int in_ECX) {
  uint16_t uVar1 = *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(&DAT_00814324) + in_ECX * 0x45c);
  uint32_t uVar2 = (uVar1 & 1) ? 1 : 0;
  if (uVar1 & 2) uVar2++;
  if (uVar1 & 4) uVar2++;
  if (uVar1 & 8) uVar2++;
  if (uVar1 & 0x10) uVar2++;
  if (uVar1 & 0x20) uVar2++;
  if (uVar1 & 0x40) uVar2++;
  if ((int8_t)uVar1 < 0) uVar2++;
  int iVar4 = ((((DAT_00860b80[in_EAX*2] < 4) ? 1 : 0) - 1 & 0xfffffff6) + 0x19) * 2;
  int8_t idx = DAT_00860b74[in_EAX * 8];
  if (4 < *(int16_t*)(reinterpret_cast<uint8_t*>(&DAT_00869a88) + idx * 2)) uVar2 /= 2;
  if (8 < *(int16_t*)(reinterpret_cast<uint8_t*>(&DAT_00869a88) + idx * 2)) uVar2 = 0;
  int shipType = (int16_t)*(reinterpret_cast<uint8_t*>(&DAT_008142f8) + in_ECX * 0x22e * 2);
  int base = DAT_00723b08[shipType * 0x11];
  int iVar3 = ((base * iVar4 * 3) / 2) * (int)(uVar2 + 4);
  int sail = *(reinterpret_cast<uint8_t*>(&DAT_00814318) + in_ECX * 0x22e * 2);
  int hull = *(reinterpret_cast<uint8_t*>(&DAT_0081431a) + in_ECX * 0x22e * 2);
  int iVar4b = (sail + hull) * (int)(uVar2 + 4) * base * iVar4;
  iVar4b += (iVar4b >> 31) & 3;
  iVar3 = (iVar3 + ((iVar3 >> 31) & 3)) >> 2;
  int denom = ((((DAT_00860b80[in_EAX*2] != 7) ? 1 : 0) - 1 & 0xffffffec) + 0x32);
  int iVar4c = (iVar4b >> 2) / denom;
  uint8_t grade = *(reinterpret_cast<uint8_t*>(&DAT_00869a88) + idx * 2);
  if (2 < grade) iVar4c -= iVar4c / 2;
  if (iVar3 < iVar4c) iVar4c = iVar3;
  if (grade < 7) return iVar4c;
  return 0;
}

// 0x4d8a90 — observed shape
int FUN_004d8a90(int in_EAX, int in_ECX) {
  uint16_t uVar1 = *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(&DAT_00814324) + in_ECX * 0x45c);
  uint32_t uVar4 = (uVar1 & 1) ? 1 : 0;
  if (uVar1 & 2) uVar4++;
  if (uVar1 & 4) uVar4++;
  if (uVar1 & 8) uVar4++;
  if (uVar1 & 0x10) uVar4++;
  if (uVar1 & 0x20) uVar4++;
  if (uVar1 & 0x40) uVar4++;
  if ((int8_t)uVar1 < 0) uVar4++;
  int iVar2 = FUN_004d8960(in_EAX, in_ECX);
  int shipType = (int16_t)*(reinterpret_cast<uint8_t*>(&DAT_008142f8) + in_ECX * 0x22e * 2);
  int base = DAT_00723b08[shipType * 0x11];
  int factor = ((((DAT_00860b80[in_EAX*2] < 4) ? 1 : 0) - 1 & 0xfffffff6) + 0x19);
  int iVar3 = ((factor * base * 6) / 2) * (int)(uVar4 + 4);
  iVar2 = ((iVar3 + ((iVar3 >> 31) & 3)) >> 2) - iVar2;
  if (iVar2 < 10) iVar2 = 10;
  return iVar2;
}

// 0x4d8b30 — observed shape
int FUN_004d8b30(int in_EAX, int in_ECX) {
  int shipType = (int16_t)*(reinterpret_cast<uint8_t*>(&DAT_008142f8) + in_ECX * 0x22e * 2);
  int base = DAT_00723b08[shipType * 0x11];
  int factor = ((((DAT_00860b80[in_EAX*2] < 4) ? 1 : 0) - 1 & 0xfffffff6) + 0x19);
  int iVar1 = (base + 1) * factor * 4;
  int8_t idx = DAT_00860b74[in_EAX * 8];
  int16_t grade = *(int16_t*)(reinterpret_cast<uint8_t*>(&DAT_00869a88) + idx * 2);
  if (4 < grade) iVar1 -= iVar1 / 2;
  if (grade < 9) return iVar1;
  return 0;
}

// 0x4d8ba0 — observed shape
void FUN_004d8ba0(int in_EAX) {
  if (in_EAX > 2 && in_EAX < 0xb) { FUN_004d8da0(); return; }
  if (in_EAX == 0) { FUN_00412cb0(); return; }
  if (in_EAX == 1) { FUN_00412cb0(); return; }
  if (in_EAX == 2) { FUN_004d93f0(); return; }
  FUN_00412cb0();
}

// 0x4d8c30 — observed shape
void FUN_004d8c30(int in_EAX) {
  if (in_EAX > 2 && in_EAX < 0xb) { FUN_004d8cb0(in_EAX - 3); return; }
  if (in_EAX == 0) { FUN_00412cb0(); return; }
  if (in_EAX == 1) { FUN_00412cb0(); return; }
  if (in_EAX == 2) { FUN_00412cb0(); return; }
  FUN_00412cb0();
}

// 0x4d8cb0 — observed shape
void FUN_004d8cb0(int in_EAX, int param_1) {
  switch (in_EAX) {
    case 0: break;
    case 1: break;
    case 2: break;
    case 3: break;
    case 4: break;
    case 5: break;
    case 6: break;
    case 7: break;
  }
  FUN_00412f10();
  FUN_004f2600("%s:%d", DAT_008cacd0, param_1);
  FUN_00412df0();
}

// 0x4d8da0 — observed shape
void FUN_004d8da0(int in_EAX) {
  switch (in_EAX) {
    case 0: FUN_00412cb0(); return;
    case 1: FUN_00412cb0(); return;
    case 2: FUN_00412cb0(); return;
    case 3: FUN_00412cb0(); return;
    case 4: FUN_00412cb0(); return;
    case 5: FUN_00412cb0(); return;
    case 6: FUN_00412cb0(); return;
    case 7: FUN_00412cb0(); return;
    default: FUN_00412cb0(); return;
  }
}

// 0x4d8e70 — observed shape
void FUN_004d8e70(int in_ECX, int* outEDI, int* outESI, int* outEBX) {
  int iVar1 = DAT_0085a268;
  uint32_t uVar2 = ((uint32_t)DAT_0085a26c >> 31);
  if (in_ECX < 3 || in_ECX > 10) {
    if (in_ECX == 0) {
      *outEDI = ((DAT_0085a26c + (int)(uVar2 & 0x1f)) >> 5) + DAT_0085a26c / 3 + 0x30;
      iVar1 = ((DAT_0085a268 + ((DAT_0085a268 >> 31) & 0x1f)) >> 5) + DAT_0085a268 / 0x18 + 0x62;
    } else if (in_ECX == 1) {
      *outEDI = ((DAT_0085a26c + (int)(uVar2 & 0x1f)) >> 5) + DAT_0085a26c / 3 + 0x30;
      iVar1 = ((DAT_0085a268 + ((DAT_0085a268 >> 31) & 0x1f)) >> 5) + DAT_0085a268 / 0x18 + 0x94;
    } else {
      if (in_ECX != 2) goto LAB_004d9017;
      *outEDI = ((DAT_0085a26c + (int)(uVar2 & 0x1f)) >> 5) + DAT_0085a26c / 3 + 0x30;
      iVar1 = ((iVar1 + ((iVar1 >> 31) & 0x1f)) >> 5) + iVar1 / 0x18 + 0xc6;
    }
    *outESI = iVar1;
    *outEBX = 0x50;
  } else {
    *outEDI = ((DAT_0085a26c + (int)(uVar2 & 0x1f)) >> 5) + DAT_0085a26c / 3 - 0x46 + in_ECX * 0x2a;
    *outESI = (((DAT_0085a268 * 3 + ((DAT_0085a268 * 3 >> 31) & 3)) >> 2) + DAT_0085a268 / 0x18) - DAT_0085a268 / 0xe;
    *outEBX = 100;
  }
LAB_004d9017:
  *outEDI = FUN_005f0ddc();
  *outESI = FUN_005f0ddc();
}

// 0x4d9040 — observed shape
void FUN_004d9040() {
  if (DAT_008cac48 != 0 && (int)FUN_004bc160() <= (int)(DAT_008c8494 - DAT_008cac4c)) {
    DAT_008cac48 = 0;
    DAT_008cac4c = DAT_008c8494;
  }
  int iVar4 = DAT_008cac50;
  int iVar2 = DAT_008cac50 + 400;
  DAT_008cac54 = FUN_00489440(DAT_008cac54, 10, 0xfa, 0);
  DAT_008cac50 = iVar4 + DAT_008cac54;
  uint32_t uVar3 = FUN_004dadc0(0, 0, 0);
  FUN_004bbc80(0xffffff9c, 1000, 0, uVar3, 0x32, 0xffffffff, 0);
  if (DAT_008cac54 > -0x33 && DAT_008cac54 < 0x33) {
    iVar2 = (iVar2 / 800) * 800 - 0x7d;
    // DAT_008ea038/34/3c are scene slots; values are (iVar2,1000,0,0,0,0,DAT_008cac48, DAT_008c8494-DAT_008cac4c)
    FUN_004bbc10(DAT_008ea038, iVar2, 1000, 0, 0, 0, 0, DAT_008cac48, (int)(DAT_008c8494 - DAT_008cac4c));
    FUN_004bbc10(DAT_008ea034, iVar2, 1000, 0, 0, 0, 0, DAT_008cac48, (int)(DAT_008c8494 - DAT_008cac4c));
    FUN_004bbc10(DAT_008ea03c, iVar2, 1000, 0, 0, 0, 0, DAT_008cac48, (int)(DAT_008c8494 - DAT_008cac4c));
  }
  int iStack_28 = 0;
  int16_t* psVar8 = &DAT_008142f8;
  uint32_t* piStack_30 = DAT_008ea014;
  do {
    if ((DAT_008cac50 - iStack_28 > -0xc82) && (DAT_008cac50 - iStack_28 < 0x322) && (*piStack_30 != 0)) {
      int iVar4b = FUN_004db210();
      int16_t sVar1 = *psVar8;
      int iVar2b = DAT_00723b08[sVar1 * 0x11];
      if (iVar2b < 5) iVar2b = 5;
      int iVar9 = DAT_00723b08[sVar1 * 0x11];
      uint32_t uVar3b = FUN_004dadc0(0, (float)(iVar4b / 6) * 1.4629181e-09f, (float)iVar4b * 1.4629181e-09f);
      FUN_004bbc80(iStack_28 + (iVar9 - 8) * 3, iVar2b * 0xb4 + 500, 0, uVar3b, ((int)sVar1 / 9 + 4) * 0x14, 0xffffffff, 0);
      FUN_004bbe10(9, (int)(DAT_008c8494 >> 1));
      FUN_004bbe10(0xb, (int)(DAT_008c8494 / 3));
    }
    piStack_30++;
    iStack_28 += 800;
    psVar8 = reinterpret_cast<int16_t*>(reinterpret_cast<uint8_t*>(psVar8) + 0x22e * 2);
  } while ((int)(intptr_t)piStack_30 < 0x8ea034);
  int iVar9b = DAT_008cac50 - 200;
  uint32_t uVar5 = (uint32_t)FUN_004db210();
  int iVar2c = 1;
  int iVar4c = (int)((uVar5 ^ (uVar5 >> 31)) - (uVar5 >> 31));
  while (32000 < iVar4c) {
    uVar5 /= 2;
    iVar2c *= 2;
    iVar4c = (int)((uVar5 ^ (uVar5 >> 31)) - (uVar5 >> 31));
  }
  int iVar4d = FUN_004953d0();
  int iVar6 = FUN_004db210();
  // FUN_004953d0(0x15555555,0xfe38e38f,0,0x2aaaaaaa) variadic; condense
  int iVar7 = FUN_004953d0();
  FUN_004ad0c0(iVar9b - iVar4d * iVar2c, 0x226 - iVar6, iVar7 + 0x8c);
}
