#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---------------------------------------------------------------------------
// Extern globals referenced by the supplied listings.
// ---------------------------------------------------------------------------
extern std::int32_t DAT_00727080;
extern std::int32_t DAT_0072c774;
extern char DAT_00860b74;
extern char DAT_00860b7c;
extern char DAT_00860b80;
extern std::uintptr_t DAT_008ecd78;
extern char DAT_008cac26;
extern char DAT_008cac27;
extern char DAT_008cacd0;
extern std::int32_t DAT_008e8ec4;
extern std::int32_t DAT_008e8ec8;
extern std::int32_t DAT_008e8eec;
extern std::int32_t DAT_008e8ef0;
extern std::int32_t DAT_008e8ef4;
extern char DAT_008e8eff;
extern std::uint8_t* DAT_008e9fd8;
extern std::int32_t DAT_008e67b0;
extern std::int32_t* DAT_008ed2c8;
extern std::int32_t DAT_008c8200;
extern std::int32_t DAT_008c7320;
extern std::int32_t DAT_008c7328;
extern std::int32_t DAT_008c7330;
extern std::int32_t DAT_008c7334;
extern std::int32_t DAT_008c7338;
extern std::int32_t DAT_008c733c;
extern std::int32_t DAT_008c7340;
extern std::int32_t DAT_008c734c;
extern char DAT_008c7190;
extern char DAT_008c7191;
extern char DAT_008c7192;
extern std::int32_t DAT_008c718c;
extern std::int32_t DAT_008c7194;
extern std::int32_t DAT_008c7198;
extern std::uint8_t DAT_008c71a4;
extern std::int32_t DAT_008c71a0;
extern std::uint16_t DAT_0086e9e8;
extern std::int32_t DAT_0070bdfc;
extern float DAT_008e8f28;
extern float DAT_008e8f2c;
extern float DAT_008e8f30;

// ---------------------------------------------------------------------------
// Extern helpers referenced by the supplied listings.
// ---------------------------------------------------------------------------
extern std::int32_t FUN_005f0ddc();
extern std::int32_t FUN_005f0ddc(std::int32_t, std::int32_t, std::int32_t, std::int32_t);
extern void FUN_004889c0(void*, std::int32_t);
extern void FUN_004890c0(void*);
extern void FUN_00489130(void*);
extern void FUN_00488ed0(std::uint32_t);
extern void FUN_00488fc0(void*, std::int32_t, std::uint32_t);
extern void FUN_004985e0();
extern void FUN_004a14b0();
extern void FUN_00488840(const char*, std::int32_t);
extern void FUN_004a0d90();
extern void FUN_0049af70(std::int32_t, std::int32_t);
extern void FUN_0049aed0(std::int32_t, std::int32_t);
extern void FUN_004986e0(void*, std::int32_t);
extern void FUN_004987a0(void*, std::uint32_t, std::uint32_t, std::uint32_t, float, float, float);
extern std::int32_t FUN_004a0b70(std::int32_t);
extern void FUN_004a0df0(std::int32_t, void*);
extern void FUN_004a1090(std::int32_t, std::int32_t, std::uint32_t);
extern void FUN_00489210(void*);
extern void FUN_00489040(void*, std::uint32_t, std::uint32_t);
extern void FUN_0049fb80(void*, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t,
                         std::uint32_t, std::int32_t, std::int32_t, std::int32_t, std::int32_t,
                         std::uint32_t, std::int32_t, std::int32_t);
extern void FUN_004e7510(float, float, std::int32_t);
extern void FUN_00491640();
extern void FUN_004a92d0();
extern void FUN_00488a80(std::int32_t, float, float, float, std::int32_t, std::int32_t,
                         std::int32_t, std::int32_t, std::int32_t, std::uint32_t, std::int32_t);

// Forward declarations for reconstructed functions called by later listings.
void FUN_004a78a0(char param_1);
void FUN_004a7a40(char param_1);
void FUN_004a8cc0();
std::int32_t FUN_004a8ed0(std::uint16_t* self);
std::int32_t FUN_004a8fb0(std::uint16_t* self, char in_AL);
float* FUN_004a9020(void* self, float* out, std::int32_t param_1);

// 0x4a77e0 — observed shape
void FUN_004a77e0(std::int32_t self) {
  std::int32_t iVar1;
  if (4 < self) {
    DAT_00727080 = DAT_00727080 * 0x343fd + 0x269ec3;
    iVar1 = FUN_005f0ddc(0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000);
    FUN_004889c0(&DAT_008c734c, 0x93 - iVar1);
  }
}

// 0x4a7840 — observed shape
void FUN_004a7840() {
  DAT_008c8200 = static_cast<std::int32_t>(
      static_cast<char>((&DAT_00860b74)[DAT_0072c774 * 0x20]));
  if ((static_cast<std::int32_t>((&DAT_00860b80)[DAT_0072c774 * 8]) < 4) &&
      ((static_cast<std::int32_t>((&DAT_00860b7c)[DAT_0072c774 * 8]) / 0x32 < 1))) {
    DAT_008c8200 = DAT_008c8200 + 0xb;
    return;
  }
  if ((&DAT_00860b80)[DAT_0072c774 * 8] == 7) {
    DAT_008c8200 = DAT_008c8200 + 7;
  }
}

// 0x4a78a0 — observed shape
void FUN_004a78a0(char param_1) {
  char cVar1;
  std::int32_t iVar2;
  using CheckFn = char (*)();
  FUN_004a7840();
  FUN_004890c0(&DAT_008c7330);
  if (param_1 == '\0') {
    FUN_004985e0();
    FUN_004a14b0();
    FUN_004985e0();
    FUN_004a14b0();
  }
  cVar1 = (reinterpret_cast<CheckFn>(
               *reinterpret_cast<void**>(DAT_008ecd78 + 0x18)))();
  if ((cVar1 != '\0') && ((DAT_008cac27 == '\0' || (DAT_008cac26 != '\0')))) {
    while (true) {
      iVar2 = DAT_008e8ec4 - DAT_008e8ec8;
      if (iVar2 < 0) {
        iVar2 = iVar2 + 100;
      }
      if (iVar2 == 0) break;
      Sleep(0x28);
    }
    FUN_004a0d90();
    FUN_0049af70(*DAT_008ed2c8, 0);
    FUN_0049aed0(0xc, 0xfffffffe);
  }
  iVar2 = static_cast<std::int32_t>(reinterpret_cast<std::uintptr_t>(DAT_008e9fd8));
  if (DAT_008e9fd8 != nullptr) {
    *(std::int32_t*)(DAT_008e9fd8 + 4) = *(std::int32_t*)(DAT_008e9fd8 + 4) + 1;
  }
  FUN_004986e0(&DAT_008e67b0, iVar2);
  if (((DAT_008c8200 == 5) || (DAT_008c8200 == 6)) && (DAT_008e8eff == '\0')) {
    FUN_004985e0();
    FUN_004a14b0();
  }
}

// 0x4a7a40 — observed shape
void FUN_004a7a40(char param_1) {
  char cVar1;
  std::int32_t iVar2;
  std::uint32_t uVar3;
  std::uint32_t uVar4;
  using CheckFn = char (*)();
  FUN_00489130(&DAT_008c7330);
  if ((DAT_008c8200 == 5) || (DAT_008c8200 == 6)) {
    FUN_004985e0();
    FUN_004a14b0();
  }
  if (param_1 == '\0') {
    FUN_004985e0();
    FUN_004a14b0();
    FUN_004985e0();
    FUN_004a14b0();
    FUN_00488ed0(0x3f800000);
  }
  cVar1 = (reinterpret_cast<CheckFn>(
               *reinterpret_cast<void**>(DAT_008ecd78 + 0x18)))();
  if ((cVar1 != '\0') && ((DAT_008cac27 == '\0' || (DAT_008cac26 != '\0')))) {
    while (true) {
      iVar2 = DAT_008e8ec4 - DAT_008e8ec8;
      if (iVar2 < 0) {
        iVar2 = iVar2 + 100;
      }
      if (iVar2 == 0) break;
      Sleep(0x28);
    }
    if ((DAT_008e8eec != 0) && ((DAT_008e8ef0 - DAT_008e8eec >> 2) != 0)) {
      DAT_008e8ef0 = DAT_008e8ef0 + -4;
    }
    FUN_0049af70(*DAT_008ed2c8, 0);
    uVar4 = 0xfffffffe;
    uVar3 = static_cast<std::uint32_t>(FUN_004a0b70(0xfffffffe));
    FUN_0049aed0(static_cast<std::int32_t>(uVar3), static_cast<std::int32_t>(uVar4));
  }
  FUN_004986e0(&DAT_008e67b0, 0);
}

// 0x4a7bc0 — observed shape
void FUN_004a7bc0() {
  std::uint32_t uVar1;
  std::uint32_t uVar2;
  std::uint32_t uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  if (DAT_008e9fd8 != nullptr) {
    uVar1 = *(std::uint32_t*)(DAT_008e9fd8 + 0x104);
    uVar2 = *(std::uint32_t*)(DAT_008e9fd8 + 0x108);
    uVar3 = *(std::uint32_t*)(DAT_008e9fd8 + 0x10c);
    fVar4 = *(float*)(DAT_008e9fd8 + 0x110);
    fVar5 = *(float*)(DAT_008e9fd8 + 0x114);
    fVar6 = *(float*)(DAT_008e9fd8 + 0x118);
    FUN_004985e0();
    FUN_004a14b0();
    FUN_004987a0(&DAT_008e67b0, uVar1, uVar2, uVar3, -fVar4, -fVar5, -fVar6);
  }
}

// 0x4a7cd0 — observed shape
void FUN_004a7cd0(std::uint32_t param_1, std::uint32_t param_2, char param_3) {
  char cVar1;
  std::int32_t iVar2;
  using CheckFn = char (*)();
  DAT_008c7328 = 0;
  FUN_004a7a40(1);
  FUN_004890c0(&DAT_008c7340);
  FUN_004890c0(&DAT_008c733c);
  FUN_004890c0(&DAT_008c7338);
  if (param_3 != '\0') {
    FUN_004985e0();
    FUN_004a14b0();
    FUN_004985e0();
    FUN_004a14b0();
    cVar1 = (reinterpret_cast<CheckFn>(
                 *reinterpret_cast<void**>(DAT_008ecd78 + 0x18)))();
    if (cVar1 == '\0') {
      FUN_00488840("The audio manager has not been properly initialized yet", 0);
    } else if (DAT_008e8eff == '\0') {
      FUN_004985e0();
      FUN_004a14b0();
    }
  }
  cVar1 = (reinterpret_cast<CheckFn>(
               *reinterpret_cast<void**>(DAT_008ecd78 + 0x18)))();
  if ((cVar1 != '\0') && ((DAT_008cac27 == '\0' || (DAT_008cac26 != '\0')))) {
    while (true) {
      iVar2 = DAT_008e8ec4 - DAT_008e8ec8;
      if (iVar2 < 0) {
        iVar2 = iVar2 + 100;
      }
      if (iVar2 == 0) break;
      Sleep(0x28);
    }
    FUN_004a0d90();
    FUN_0049af70(*DAT_008ed2c8, 0);
    FUN_0049aed0(0x15, 0xfffffffe);
  }
  FUN_0049aed0(0x16, static_cast<std::int32_t>(param_2));
  FUN_0049aed0(0x17, static_cast<std::int32_t>(param_1));
}

// 0x4a7ee0 — observed shape
void FUN_004a7ee0(char param_1) {
  char cVar1;
  std::int32_t iVar2;
  std::uint32_t uVar3;
  std::uint32_t uVar4;
  using CheckFn = char (*)();
  FUN_00489130(&DAT_008c7340);
  FUN_00489130(&DAT_008c733c);
  FUN_00489130(&DAT_008c7338);
  if (param_1 != '\0') {
    FUN_004985e0();
    FUN_004a14b0();
    FUN_004985e0();
    FUN_004a14b0();
    FUN_00488ed0(0x3f800000);
  }
  cVar1 = (reinterpret_cast<CheckFn>(
               *reinterpret_cast<void**>(DAT_008ecd78 + 0x18)))();
  if ((cVar1 != '\0') && ((DAT_008cac27 == '\0' || (DAT_008cac26 != '\0')))) {
    while (true) {
      iVar2 = DAT_008e8ec4 - DAT_008e8ec8;
      if (iVar2 < 0) {
        iVar2 = iVar2 + 100;
      }
      if (iVar2 == 0) break;
      Sleep(0x28);
    }
    if ((DAT_008e8eec != 0) && ((DAT_008e8ef0 - DAT_008e8eec >> 2) != 0)) {
      DAT_008e8ef0 = DAT_008e8ef0 + -4;
    }
    FUN_0049af70(*DAT_008ed2c8, 0);
    uVar4 = 0xfffffffe;
    uVar3 = static_cast<std::uint32_t>(FUN_004a0b70(0xfffffffe));
    FUN_0049aed0(static_cast<std::int32_t>(uVar3), static_cast<std::int32_t>(uVar4));
  }
  FUN_004a78a0(1);
}

// 0x4a8020 — observed shape
void FUN_004a8020() {
  FUN_00489130(&DAT_008c7340);
  FUN_00489130(&DAT_008c733c);
  FUN_00489130(&DAT_008c7338);
}

// 0x4a8050 — observed shape
void FUN_004a8050(std::uint32_t param_1, std::uint32_t param_2, char param_3, char param_4) {
  char cVar1;
  std::int32_t iVar2;
  using CheckFn = char (*)();
  FUN_004a7a40(1);
  FUN_004890c0(&DAT_008c7334);
  FUN_004890c0(&DAT_008c7338);
  if (param_3 != '\0') {
    FUN_004985e0();
    FUN_004a14b0();
    FUN_004985e0();
    FUN_004a14b0();
    cVar1 = (reinterpret_cast<CheckFn>(
                 *reinterpret_cast<void**>(DAT_008ecd78 + 0x18)))();
    if (cVar1 == '\0') {
      FUN_00488840("The audio manager has not been properly initialized yet", 0);
    } else if (DAT_008e8eff == '\0') {
      FUN_004985e0();
      FUN_004a14b0();
    }
  }
  cVar1 = (reinterpret_cast<CheckFn>(
               *reinterpret_cast<void**>(DAT_008ecd78 + 0x18)))();
  if ((cVar1 != '\0') && ((DAT_008cac27 == '\0' || (DAT_008cac26 != '\0')))) {
    while (true) {
      iVar2 = DAT_008e8ec4 - DAT_008e8ec8;
      if (iVar2 < 0) {
        iVar2 = iVar2 + 100;
      }
      if (iVar2 == 0) break;
      Sleep(0x28);
    }
    FUN_004a0d90();
    FUN_0049af70(*DAT_008ed2c8, 0);
    FUN_0049aed0(0x18, 0xfffffffe);
  }
  FUN_0049aed0(0x19, static_cast<std::int32_t>(param_1));
  FUN_0049aed0(0x1a, static_cast<std::int32_t>(param_2));
  if ((param_4 != '\0') && (DAT_008e8eff == '\0')) {
    FUN_004985e0();
    FUN_004a14b0();
  }
}

// 0x4a82b0 — observed shape
void FUN_004a82b0(char param_1, char param_2) {
  char cVar1;
  std::int32_t iVar2;
  std::uint32_t uVar3;
  std::uint32_t uVar4;
  using CheckFn = char (*)();
  FUN_00489130(&DAT_008c7334);
  FUN_00489130(&DAT_008c7338);
  if (param_1 != '\0') {
    FUN_004985e0();
    FUN_004a14b0();
    FUN_004985e0();
    FUN_004a14b0();
    FUN_00488ed0(0x3f800000);
  }
  FUN_004985e0();
  FUN_004a14b0();
  cVar1 = (reinterpret_cast<CheckFn>(
               *reinterpret_cast<void**>(DAT_008ecd78 + 0x18)))();
  if ((cVar1 != '\0') && ((DAT_008cac27 == '\0' || (DAT_008cac26 != '\0')))) {
    while (true) {
      iVar2 = DAT_008e8ec4 - DAT_008e8ec8;
      if (iVar2 < 0) {
        iVar2 = iVar2 + 100;
      }
      if (iVar2 == 0) break;
      Sleep(0x28);
    }
    if ((DAT_008e8eec != 0) && ((DAT_008e8ef0 - DAT_008e8eec >> 2) != 0)) {
      DAT_008e8ef0 = DAT_008e8ef0 + -4;
    }
    FUN_0049af70(*DAT_008ed2c8, 0);
    uVar4 = 0xfffffffe;
    uVar3 = static_cast<std::uint32_t>(FUN_004a0b70(0xfffffffe));
    FUN_0049aed0(static_cast<std::int32_t>(uVar3), static_cast<std::int32_t>(uVar4));
  }
  if (param_2 != '\0') {
    FUN_004a78a0(1);
  }
}

// 0x4a8420 — observed shape
void FUN_004a8420() {
  char cVar1;
  std::int32_t iVar2;
  using CheckFn = char (*)();
  FUN_004890c0(&DAT_008c7320);
  cVar1 = (reinterpret_cast<CheckFn>(
               *reinterpret_cast<void**>(DAT_008ecd78 + 0x18)))();
  if ((cVar1 != '\0') && ((DAT_008cac27 == '\0' || (DAT_008cac26 != '\0')))) {
    while (true) {
      iVar2 = DAT_008e8ec4 - DAT_008e8ec8;
      if (iVar2 < 0) {
        iVar2 = iVar2 + 100;
      }
      if (iVar2 == 0) break;
      Sleep(0x28);
    }
    FUN_004a0d90();
    FUN_0049af70(*DAT_008ed2c8, 0);
    FUN_0049aed0(0x1b, 0xfffffffe);
  }
  if (DAT_008e8eff == '\0') {
    FUN_004985e0();
    FUN_004a14b0();
    if (DAT_008e8eff == '\0') {
      FUN_004985e0();
      FUN_004a14b0();
    }
  }
}

// 0x4a85a0 — observed shape
void FUN_004a85a0() {
  char cVar1;
  std::int32_t iVar2;
  std::uint32_t uVar3;
  std::uint32_t uVar4;
  using CheckFn = char (*)();
  FUN_00489130(&DAT_008c7320);
  FUN_004985e0();
  FUN_004a14b0();
  FUN_00488ed0(0x3f800000);
  cVar1 = (reinterpret_cast<CheckFn>(
               *reinterpret_cast<void**>(DAT_008ecd78 + 0x18)))();
  if ((cVar1 != '\0') && ((DAT_008cac27 == '\0' || (DAT_008cac26 != '\0')))) {
    while (true) {
      iVar2 = DAT_008e8ec4 - DAT_008e8ec8;
      if (iVar2 < 0) {
        iVar2 = iVar2 + 100;
      }
      if (iVar2 == 0) break;
      Sleep(0x28);
    }
    if ((DAT_008e8eec != 0) && ((DAT_008e8ef0 - DAT_008e8eec >> 2) != 0)) {
      DAT_008e8ef0 = DAT_008e8ef0 + -4;
    }
    FUN_0049af70(*DAT_008ed2c8, 0);
    uVar4 = 0xfffffffe;
    uVar3 = static_cast<std::uint32_t>(FUN_004a0b70(0xfffffffe));
    FUN_0049aed0(static_cast<std::int32_t>(uVar3), static_cast<std::int32_t>(uVar4));
  }
}

// 0x4a86a0 — observed shape
void FUN_004a86a0() {
  char cVar1;
  std::uint8_t* puVar2;
  std::int32_t iVar3;
  std::int32_t iVar4;
  std::uint32_t local_68;
  std::uint32_t uStack_64 = 0;
  std::uint32_t uStack_5c = 0;
  std::uint32_t uStack_58 = 0;
  std::uint32_t uStack_3c = 0;
  void* puStack_2c = nullptr;
  void* puStack_4 = nullptr;
  using CheckFn = char (*)();
  DAT_008c7192 = 1;
  DAT_008c7190 = 0;
  puVar2 = &DAT_008c71a4;
  do {
    iVar4 = 0x10;
    do {
      *(std::uint32_t*)(puVar2 + -4) = 0;
      *puVar2 = 0;
      *(std::uint32_t*)(puVar2 + 4) = 0xffffffff;
      puVar2 = puVar2 + 0xc;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  } while (reinterpret_cast<std::uintptr_t>(puVar2) < 0x8c7324);
  DAT_008c7191 = 1;
  FUN_004890c0(&DAT_008c718c);
  local_68 = 0xc;
  cVar1 = (reinterpret_cast<CheckFn>(
               *reinterpret_cast<void**>(DAT_008ecd78 + 0x18)))();
  if ((cVar1 != '\0') && ((DAT_008cac27 == '\0' || (DAT_008cac26 != '\0')))) {
    while (true) {
      iVar4 = DAT_008e8ef0;
      iVar3 = DAT_008e8ec4 - DAT_008e8ec8;
      if (iVar3 < 0) {
        iVar3 = iVar3 + 100;
      }
      if (iVar3 == 0) break;
      Sleep(0x28);
    }
    if ((DAT_008e8eec == 0) ||
        (static_cast<std::uint32_t>(DAT_008e8ef4 - DAT_008e8eec >> 2) <=
         static_cast<std::uint32_t>(DAT_008e8ef0 - DAT_008e8eec >> 2))) {
      FUN_004a0df0(DAT_008e8ef0, &local_68);
    } else {
      FUN_004a1090(DAT_008e8ef0, 1, local_68);
      DAT_008e8ef0 = iVar4 + 4;
    }
    FUN_0049af70(*DAT_008ed2c8, 0);
    FUN_0049aed0(0xd, 0xfffffffe);
  }
  puStack_4 = &DAT_008cacd0;
  uStack_64 = 0x17;
  puStack_2c = &DAT_0070bdfc;
  uStack_5c = 2;
  FUN_004985e0();
  FUN_004a14b0();
  if (DAT_008e8eff == '\0') {
    puStack_4 = &DAT_008cacd0;
    uStack_64 = 0x22;
    puStack_2c = &DAT_008c7198;
    uStack_5c = 7;
    uStack_58 = 0xffffffff;
    uStack_3c = 0xbf800000;
    FUN_004985e0();
    FUN_004a14b0();
    if (DAT_008e8eff == '\0') {
      puStack_4 = &DAT_008cacd0;
      uStack_64 = 0x22;
      puStack_2c = &DAT_008c7194;
      uStack_5c = 8;
      uStack_58 = 0xffffffff;
      uStack_3c = 0xbf800000;
      FUN_004985e0();
      FUN_004a14b0();
    }
  }
  (void)puStack_4;
  (void)uStack_64;
  (void)uStack_5c;
  (void)uStack_58;
  (void)uStack_3c;
  (void)puStack_2c;
}

// 0x4a88d0 — observed shape
void FUN_004a88d0() {
  char cVar1;
  std::uint32_t uVar2;
  std::int32_t* piVar3;
  std::int32_t iVar4;
  std::uint32_t uVar5;
  using CheckFn = char (*)();
  piVar3 = &DAT_008c71a0;
  do {
    iVar4 = 0x10;
    do {
      if (*piVar3 != 0) {
        FUN_00489210(piVar3);
      }
      piVar3 = piVar3 + 3;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    Sleep(0x28);
  } while (reinterpret_cast<std::uintptr_t>(piVar3) < 0x8c7320);
  FUN_00488fc0(&DAT_008c718c, 0xffffffff, 0xbf800000);
  FUN_00488ed0(0x3f800000);
  FUN_00489130(&DAT_008c718c);
  if (DAT_008c7192 != '\0') {
    FUN_004985e0();
    FUN_004a14b0();
  }
  FUN_004985e0();
  FUN_004a14b0();
  FUN_004985e0();
  FUN_004a14b0();
  cVar1 = (reinterpret_cast<CheckFn>(
               *reinterpret_cast<void**>(DAT_008ecd78 + 0x18)))();
  if ((cVar1 != '\0') && ((DAT_008cac27 == '\0' || (DAT_008cac26 != '\0')))) {
    while (true) {
      iVar4 = DAT_008e8ec4 - DAT_008e8ec8;
      if (iVar4 < 0) {
        iVar4 = iVar4 + 100;
      }
      if (iVar4 == 0) break;
      Sleep(0x28);
    }
    if ((DAT_008e8eec != 0) && ((DAT_008e8ef0 - DAT_008e8eec >> 2) != 0)) {
      DAT_008e8ef0 = DAT_008e8ef0 + -4;
    }
    FUN_0049af70(*DAT_008ed2c8, 0);
    uVar5 = 0xfffffffe;
    uVar2 = static_cast<std::uint32_t>(FUN_004a0b70(0xfffffffe));
    FUN_0049aed0(static_cast<std::int32_t>(uVar2), static_cast<std::int32_t>(uVar5));
  }
}

// 0x4a8a70 — observed shape
void FUN_004a8a70(std::int32_t param_1, std::int32_t param_2) {
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  std::int32_t iVar10;
  if (DAT_008e9fd8 != nullptr) {
    fVar5 = static_cast<float>(param_1);
    fVar1 = *(float*)(DAT_008e9fd8 + 0x98);
    fVar6 = static_cast<float>(param_2);
    FUN_004e7510(fVar5, fVar6, 0);
    iVar10 = FUN_005f0ddc();
    fVar7 = fVar5 - fVar5;
    fVar8 = fVar6 - fVar6;
    fVar2 = *(float*)(DAT_008e9fd8 + 0x40);
    fVar9 = static_cast<float>(iVar10) - fVar1;
    fVar3 = *(float*)(DAT_008e9fd8 + 0x4c);
    fVar4 = *(float*)(DAT_008e9fd8 + 0x58);
    DAT_008e8f28 = fVar5;
    DAT_008e8f2c = fVar6;
    DAT_008e8f30 = fVar1;
    FUN_00491640();
    FUN_004985e0();
    FUN_004a14b0();
    FUN_004987a0(&DAT_008e67b0, static_cast<std::uint32_t>(static_cast<std::int32_t>(fVar7)),
                 static_cast<std::uint32_t>(static_cast<std::int32_t>(fVar8)),
                 static_cast<std::uint32_t>(static_cast<std::int32_t>(fVar9)),
                 -(fVar9 * fVar3 - fVar8 * fVar4),
                 -(fVar4 * fVar7 - fVar9 * fVar2),
                 -(fVar8 * fVar2 - fVar3 * fVar7));
  }
  FUN_004a92d0();
  FUN_004a8cc0();
}

// 0x4a8cc0 — observed shape
void FUN_004a8cc0() {
  std::uint32_t uVar1;
  std::uint32_t uVar2;
  std::uint32_t uVar3;
  char cVar4;
  std::uint32_t uVar5;
  std::uint32_t* puVar6;
  std::uint32_t* puVar7;
  std::uint16_t* local_a4;
  std::uint32_t* local_a0;
  std::int32_t local_9c;
  float pos[3] = {0.0f, 0.0f, 0.0f};
  using CheckFn = char (*)();
  local_a4 = &DAT_0086e9e8;
  local_a0 = &DAT_008c71a0;
  do {
    local_9c = 0x10;
    puVar7 = local_a0;
    do {
      if ((*(std::uint32_t*)(local_a4 + 0x10) & 0x800) == 0) {
        if (*(char*)(puVar7 + 1) != '\0') {
          FUN_00489040(puVar7, puVar7[2], 0x3e800000);
          *(std::uint8_t*)(puVar7 + 1) = 0;
        }
      } else if (*(char*)(puVar7 + 1) == '\0') {
        if ((local_a0 == &DAT_008c71a0) || ((*(std::uint32_t*)(local_a4 + 0x10) & 2) != 0)) {
          uVar5 = static_cast<std::uint32_t>(
              FUN_004a8ed0(reinterpret_cast<std::uint16_t*>(puVar7)));
          puVar6 = reinterpret_cast<std::uint32_t*>(
              FUN_004a9020(reinterpret_cast<void*>(local_a4), pos, 0));
          uVar1 = puVar6[0];
          uVar2 = puVar6[1];
          uVar3 = puVar6[2];
          cVar4 = (reinterpret_cast<CheckFn>(
                       *reinterpret_cast<void**>(DAT_008ecd78 + 0x18)))();
          if (cVar4 == '\0') {
            FUN_00488840("The audio manager has not been properly initialized yet", 0);
            *(std::uint8_t*)(puVar7 + 1) = 1;
            puVar7[2] = uVar5;
          } else {
            FUN_0049fb80(&DAT_008e67b0, uVar5, 0, uVar1, uVar2, uVar3, 0xffffffff, 0xffffffff,
                         0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff, 1);
            *(std::uint8_t*)(puVar7 + 1) = 1;
            puVar7[2] = uVar5;
          }
        }
      } else {
        (void)puVar6;
        (void)FUN_004a9020(reinterpret_cast<void*>(local_a4), pos, 0);
        cVar4 = (reinterpret_cast<CheckFn>(
                     *reinterpret_cast<void**>(DAT_008ecd78 + 0x18)))();
        if (cVar4 != '\0') {
          FUN_004985e0();
          FUN_004a14b0();
        }
      }
      local_a4 = local_a4 + 0xa6;
      puVar7 = puVar7 + 3;
      local_9c = local_9c + -1;
    } while (local_9c != 0);
    local_a0 = local_a0 + 0x30;
  } while (reinterpret_cast<std::uintptr_t>(local_a0) < 0x8c7320);
}

// 0x4a8ed0 — observed shape
std::int32_t FUN_004a8ed0(std::uint16_t* self) {
  std::int16_t sVar1;
  if (self == nullptr) {
    return -1;
  }
  switch (*self) {
    case 0:
    case 1:
    case 2:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
      break;
    case 3: {
      sVar1 = static_cast<std::int16_t>(self[1]);
      if (sVar1 < 1) {
        if (sVar1 < 3) {
          return (((sVar1 < 6 ? 1 : 0) - 1) & 0xd5) - 1;
        }
      } else if (sVar1 < 3) {
        return 0xd2;
      }
      if (sVar1 < 6) {
        return 0xd3;
      }
      return (((sVar1 < 6 ? 1 : 0) - 1) & 0xd5) - 1;
    }
    case 4: {
      sVar1 = static_cast<std::int16_t>(self[1]);
      if ((sVar1 < 1) || (2 < sVar1)) {
        return (((sVar1 < 3 ? 1 : 0) - 1) & 0xd7) - 1;
      }
      return 0xd5;
    }
    default:
      return -1;
  }
  sVar1 = static_cast<std::int16_t>(self[1]);
  if (sVar1 < 1) {
    if (sVar1 < 3) {
      return (((sVar1 < 6 ? 1 : 0) - 1) & 0xd2) - 1;
    }
  } else if (sVar1 < 3) {
    return 0xcf;
  }
  if (sVar1 < 6) {
    return 0xd0;
  }
  return (((sVar1 < 6 ? 1 : 0) - 1) & 0xd2) - 1;
}

// 0x4a8fb0 — observed shape
std::int32_t FUN_004a8fb0(std::uint16_t* self, char in_AL) {
  if (self != nullptr) {
    switch (*self) {
      case 0:
      case 3:
      case 7:
      case 9:
        return 0xca;
      case 1:
      case 2:
      case 6:
      case 8:
        return 0xcc - static_cast<std::uint32_t>(in_AL != '\0' ? 1 : 0);
      case 4:
        return 0xce;
      case 5:
        return static_cast<std::int32_t>(
            static_cast<std::uint32_t>(in_AL == '\0' ? 1 : 0) * 2 + 0xcb);
    }
  }
  return -1;
}

// 0x4a9020 — observed shape
float* FUN_004a9020(void* self, float* out, std::int32_t param_1) {
  std::int32_t iVar1;
  std::int32_t iVar2;
  if (self == nullptr) {
    out[0] = 0.0f;
    out[1] = 0.0f;
    out[2] = 0.0f;
    return out;
  }
  FUN_004e7510(static_cast<float>(*(std::int32_t*)((std::uint8_t*)self + 0x74 + param_1 * 4)),
               static_cast<float>(*(std::int32_t*)((std::uint8_t*)self + 0xa4 + param_1 * 4)), 0);
  iVar2 = FUN_005f0ddc();
  iVar1 = *(std::int32_t*)((std::uint8_t*)self + 0xa4 + param_1 * 4);
  out[0] = static_cast<float>(*(std::int32_t*)((std::uint8_t*)self + 0x74 + param_1 * 4));
  out[1] = static_cast<float>(iVar1);
  out[2] = static_cast<float>(iVar2);
  return out;
}

// 0x4a90a0 — observed shape
void FUN_004a90a0(std::uint32_t param_1, std::int32_t self) {
  char cVar1;
  std::int32_t uVar2;
  std::uint32_t* puVar3;
  float pos[3] = {0.0f, 0.0f, 0.0f};
  using CheckFn = char (*)();
  if (self != 0) {
    if (DAT_008c7192 != '\0') {
      DAT_008c7192 = '\0';
      cVar1 = (reinterpret_cast<CheckFn>(
                   *reinterpret_cast<void**>(DAT_008ecd78 + 0x18)))();
      if (cVar1 == '\0') {
        FUN_00488840("The audio manager has not been properly initialized yet", 0);
      } else if (DAT_008e8eff == '\0') {
        FUN_004985e0();
        FUN_004a14b0();
      }
    }
    uVar2 = FUN_004a8fb0(
        reinterpret_cast<std::uint16_t*>(static_cast<std::uintptr_t>(self)), 0);
    puVar3 = reinterpret_cast<std::uint32_t*>(FUN_004a9020(
        reinterpret_cast<void*>(static_cast<std::uintptr_t>(self)), pos,
        static_cast<std::int32_t>(param_1)));
    FUN_00488a80(uVar2, static_cast<float>(puVar3[0]), static_cast<float>(puVar3[1]),
                 static_cast<float>(puVar3[2]), 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0,
                 0xbf800000, 0xffffffff);
  }
}
