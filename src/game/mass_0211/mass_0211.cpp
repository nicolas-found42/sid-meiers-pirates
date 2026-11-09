#include <cstdint>
#include <cstddef>

extern int DAT_00728cfc;
extern int* DAT_00728cf8;
extern int DAT_00728d00;
extern int* DAT_00728d00_ptr;
extern void* DAT_00728d04;
extern int DAT_00717c64;
extern void* FUN_00533c78(uint32_t);
extern void FUN_005cb7c0();
extern void FUN_005be930(int);
extern void operator_delete(void*);
extern void operator_delete__(void*);
// 0x5bec30 — observed shape
void FUN_005bec30(int param_1)
{
  DAT_00728cfc = param_1;
  if (param_1 == 0) {
    if (DAT_00728cf8 != 0) {
      auto vtab = *reinterpret_cast<std::uintptr_t*>(DAT_00728cf8);
      auto fn = *reinterpret_cast<void(**)(void*)>(vtab + 8);
      fn(DAT_00728cf8);
    }
    DAT_00728cf8 = 0;
    DAT_00728d00 = 0;
    return;
  }
  int* piVar1 = *reinterpret_cast<int**>(param_1 + 0x60);
  if (DAT_00728cf8 != 0) {
    auto vtab = *reinterpret_cast<std::uintptr_t*>(DAT_00728cf8);
    auto fn = *reinterpret_cast<void(**)(void*)>(vtab + 8);
    fn(DAT_00728cf8);
  }
  DAT_00728cf8 = piVar1;
  if (piVar1 != 0) {
    auto vtab = *reinterpret_cast<std::uintptr_t*>(piVar1);
    auto fn = *reinterpret_cast<void(**)(void*)>(vtab + 4);
    fn(piVar1);
  }
  DAT_00728d00 = *reinterpret_cast<int*>(DAT_00728cfc + 0x5cc);
  return;
}

// 0x5beca0 — observed shape
void FUN_005beca0(void* self)
{
  int* ecx = reinterpret_cast<int*>(self);
  if (*reinterpret_cast<int*>(self) != 0) {
    int* piVar1 = reinterpret_cast<int*>(*ecx + 100);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      FUN_005cb7c0();
      return;
    }
  }
  return;
}

// 0x5becc0 — observed shape
void FUN_005becc0(void* self)
{
  int* piVar1 = reinterpret_cast<int*>(reinterpret_cast<int*>(self)[5]);
  reinterpret_cast<int*>(self)[2] = 0;
  if (piVar1 != 0) {
    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(piVar1);
    if (puVar2 != 0) {
      if (puVar2[-1] == 0) {
        operator_delete__(reinterpret_cast<void*>(puVar2 - 1));
      } else {
        auto fn = *reinterpret_cast<void(**)(int)>(*puVar2);
        fn(3);
      }
    }
    if (piVar1[2] != 0) {
      FUN_005be930(1);
    }
    operator_delete(piVar1);
  }
  operator_delete__(reinterpret_cast<void*>(*reinterpret_cast<void**>(self)));
  return;
}

// 0x5bed20 — observed shape
void FUN_005bed20()
{
  DAT_00728d04 = FUN_00533c78(0x18);
  if (DAT_00728d04 == 0) {
    DAT_00728d04 = 0;
    return;
  }
  auto* d = reinterpret_cast<uint32_t*>(DAT_00728d04);
  d[0] = 0;
  d[1] = 0;
  d[2] = 0;
  d[3] = 8;
  d[4] = 8;
  d[5] = 0;
  return;
}

// 0x5bed60 — observed shape
uint32_t FUN_005bed60(void* self, uint32_t param_2, int param_3, int param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7) {
  int ecx = reinterpret_cast<int>(self);
  if (*reinterpret_cast<int**>(ecx + 0x4c) == 0) {
    auto v1 = *reinterpret_cast<std::uintptr_t*>(*reinterpret_cast<int*>(DAT_00728d00_ptr));
    auto fn1 = *reinterpret_cast<void(**)(int,int)>(v1 + 0x84);
    fn1(0,0);
  } else {
    int iVar1 = *reinterpret_cast<int*>(DAT_00728d00_ptr);
    auto v2 = *reinterpret_cast<std::uintptr_t*>(*reinterpret_cast<int**>(ecx + 0x4c));
    auto fn2 = *reinterpret_cast<uint32_t(**)()>(v2 + 0x30);
    uint32_t uVar2 = fn2();
    auto v3 = *reinterpret_cast<std::uintptr_t*>(*reinterpret_cast<int*>(DAT_00728d00_ptr));
    auto fn3 = *reinterpret_cast<void(**)(uint32_t)>(v3 + 0x84);
    fn3(uVar2);
    if (*reinterpret_cast<int**>(ecx + 0x3c) != 0) {
      auto v4 = *reinterpret_cast<std::uintptr_t*>(*reinterpret_cast<int**>(ecx + 0x3c));
      auto fn4 = reinterpret_cast<void(**)(...)>(v4 + 0x28);
      // original receiver and trailing args passed through
      uint32_t arg0 = *reinterpret_cast<uint32_t*>(ecx + 0x4c);
      // preserve call shape conservatively
      fn4(arg0, param_3, param_4, param_5, param_6, param_7);
    }
  }
  if (*reinterpret_cast<int**>(ecx + 0x60) == 0) {
    auto v5 = *reinterpret_cast<std::uintptr_t*>(*reinterpret_cast<int*>(DAT_00728d00_ptr));
    auto fn5 = *reinterpret_cast<void(**)(void*)>(v5 + 0xf4);
    fn5(reinterpret_cast<void*>(ecx + 100));
    auto v6 = *reinterpret_cast<std::uintptr_t*>(*reinterpret_cast<int*>(DAT_00728d00_ptr));
    auto fn6 = *reinterpret_cast<void(**)(int,int)>(v6 + 0x94);
    fn6(0,0);
    if (param_4 == 0) {
      if (param_3 == 0) {
        param_4 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(0) + 0xbc + 0x38);
      } else {
        param_4 = *reinterpret_cast<int*>(param_3 + 0x28);
      }
    }
    if (*reinterpret_cast<int*>(param_4 + 8) != 0) {
      auto v7 = *reinterpret_cast<std::uintptr_t*>(*reinterpret_cast<int*>(DAT_00728d00_ptr));
      auto fn7 = *reinterpret_cast<void(**)(int)>(v7 + 0xa4);
      fn7(*reinterpret_cast<int*>(param_4 + 8));
      return 0;
    }
    auto v8 = *reinterpret_cast<std::uintptr_t*>(*reinterpret_cast<int*>(DAT_00728d00_ptr));
    auto fn8 = *reinterpret_cast<void(**)(uint32_t,int)>(v8 + 0xb4);
    fn8(*reinterpret_cast<uint32_t*>(param_4 + 0xc), 0);
  } else {
    auto v9 = *reinterpret_cast<std::uintptr_t*>(*reinterpret_cast<int*>(DAT_00728d00_ptr));
    auto fn9 = *reinterpret_cast<uint32_t(**)()>(v9 + 0x48);
    // corrected receiver
    {
      auto vv = *reinterpret_cast<std::uintptr_t*>(*reinterpret_cast<int**>(ecx + 0x60));
      auto f2 = *reinterpret_cast<uint32_t(**)()>(vv + 0x48);
      uint32_t u = f2();
      auto v10 = *reinterpret_cast<std::uintptr_t*>(*reinterpret_cast<int*>(DAT_00728d00_ptr));
      auto fn10 = *reinterpret_cast<void(**)(uint32_t)>(v10 + 0xf4);
      fn10(u);
    }
    {
      auto vv = *reinterpret_cast<std::uintptr_t*>(*reinterpret_cast<int**>(ecx + 0x60));
      auto f2 = *reinterpret_cast<uint32_t(**)(int)>(vv + 0x38);
      uint32_t u = f2(0);
      auto v11 = *reinterpret_cast<std::uintptr_t*>(*reinterpret_cast<int*>(DAT_00728d00_ptr));
      auto fn11 = *reinterpret_cast<void(**)(uint32_t)>(v11 + 0x94);
      fn11(u);
    }
    if (*reinterpret_cast<int**>(ecx + 0x50) != 0) {
      auto v12 = *reinterpret_cast<std::uintptr_t*>(*reinterpret_cast<int**>(ecx + 0x50));
      auto fn12 = reinterpret_cast<void(**)(...)>(v12 + 0x28);
      uint32_t arg0 = *reinterpret_cast<uint32_t*>(ecx + 0x60);
      fn12(arg0, param_3, param_4, 0, 0, 0, 0);
    }
    uint32_t uVar3 = 0;
    if (DAT_00717c64 != 0) {
      do {
        auto v13 = *reinterpret_cast<std::uintptr_t*>(*reinterpret_cast<int*>(DAT_00728d00_ptr));
        auto fn13 = *reinterpret_cast<void(**)(uint32_t,int,uint32_t,int)>(v13 + 0xd4);
        fn13(uVar3, 0xb, uVar3, 0);
        uVar3 = uVar3 + 1;
      } while (uVar3 < (uint32_t)DAT_00717c64);
      return 0;
    }
  }
  return 0;
}

extern void* PTR_FUN_006c71b4;
extern void* LAB_004c2970;
extern void* thunk_FUN_00533c78(uint32_t);
extern void FUN_004127b0(void*, int, int, void*);
extern void FUN_0055f300(int);

// 0x5bef60 — observed shape
void FUN_005bef60(void* self, int param_1, uint32_t param_2)
{
  int* piVar2 = 0;
  *reinterpret_cast<void**>(self) = PTR_FUN_006c71b4;
  reinterpret_cast<int*>(self)[2] = param_1;
  reinterpret_cast<int*>(self)[5] = static_cast<int>(param_2);
  reinterpret_cast<int*>(self)[3] = 0;
  reinterpret_cast<int*>(self)[4] = 0;
  if (param_1 != 0) {
    int* piVar1 = reinterpret_cast<int*>(thunk_FUN_00533c78(param_1 * 4 + 4));
    if (piVar1 != 0) {
      piVar2 = piVar1 + 1;
      *piVar1 = param_1;
      FUN_004127b0(piVar2, 4, param_1, LAB_004c2970);
    }
  }
  reinterpret_cast<int*>(self)[1] = reinterpret_cast<int>(piVar2);
  return;
}

// 0x5befc0 — observed shape
void FUN_005befc0(void* self, uint32_t param_1, int* param_2)
{
  int ecx = reinterpret_cast<int>(self);
  int iVar3;
  if (*reinterpret_cast<uint32_t*>(ecx + 8) <= param_1) {
    return;
  }
  if (param_1 < *reinterpret_cast<uint32_t*>(ecx + 0xc)) {
    iVar3 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(ecx + 4) + param_1 * 4);
    if (*param_2 == 0) {
      if (iVar3 == 0) goto LAB_005bf019;
      iVar3 = *reinterpret_cast<int*>(ecx + 0x10) + -1;
    } else {
      if (iVar3 != 0) goto LAB_005bf019;
      iVar3 = *reinterpret_cast<int*>(ecx + 0x10) + 1;
    }
  } else {
    *reinterpret_cast<uint32_t*>(ecx + 0xc) = param_1 + 1;
    if (*param_2 == 0) goto LAB_005bf019;
    iVar3 = *reinterpret_cast<int*>(ecx + 0x10) + 1;
  }
  *reinterpret_cast<int*>(ecx + 0x10) = iVar3;
LAB_005bf019:;
  int* piVar2 = reinterpret_cast<int*>(*reinterpret_cast<int*>(ecx + 4) + param_1 * 4);
  iVar3 = *piVar2;
  if (iVar3 != *param_2) {
    if (iVar3 != 0) {
      int* piVar1 = reinterpret_cast<int*>(iVar3 + 100);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        FUN_005cb7c0();
      }
    }
    iVar3 = *param_2;
    *piVar2 = iVar3;
    if (iVar3 != 0) {
      *reinterpret_cast<int*>(iVar3 + 100) = *reinterpret_cast<int*>(iVar3 + 100) + 1;
    }
  }
  return;
}

// 0x5bf050 — observed shape
void FUN_005bf050(void* self)
{
  int ecx = reinterpret_cast<int>(self);
  uint32_t uVar4 = 0;
  if (*reinterpret_cast<int*>(ecx + 0xc) != 0) {
    do {
      int iVar2 = *reinterpret_cast<int*>(ecx + 4);
      int iVar3 = *reinterpret_cast<int*>(iVar2 + uVar4 * 4);
      if (iVar3 != 0) {
        int* piVar1 = reinterpret_cast<int*>(iVar3 + 100);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          FUN_005cb7c0();
        }
        *reinterpret_cast<int*>(iVar2 + uVar4 * 4) = 0;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *reinterpret_cast<uint32_t*>(ecx + 0xc));
  }
  *reinterpret_cast<uint32_t*>(ecx + 0xc) = 0;
  *reinterpret_cast<uint32_t*>(ecx + 0x10) = 0;
  return;
}

// 0x5bf090 — observed shape
void FUN_005bf090(void* self, int* param_1)
{
  int* in_ECX = reinterpret_cast<int*>(self);
  uint32_t uVar1 = 0;
  if (in_ECX[2] != 0) {
    int* piVar3 = reinterpret_cast<int*>(*in_ECX);
    do {
      if (*piVar3 == *param_1) {
        if (uVar1 != 0xffffffff) {
          return;
        }
        break;
      }
      uVar1 = uVar1 + 1;
      piVar3 = piVar3 + 1;
    } while (uVar1 < (uint32_t)in_ECX[2]);
  }
  int iVar2 = in_ECX[1];
  if (in_ECX[2] == iVar2) {
    if (iVar2 == 0) {
      iVar2 = 1;
    } else {
      iVar2 = iVar2 * 2;
    }
    FUN_0055f300(iVar2);
  }
  *reinterpret_cast<int*>(*in_ECX + in_ECX[2] * 4) = *param_1;
  in_ECX[2] = in_ECX[2] + 1;
  return;
}

// 0x5bf0f0 — observed shape
void FUN_005bf0f0(void* self)
{
  int* in_ECX = reinterpret_cast<int*>(self);
  *reinterpret_cast<void**>(self) = PTR_FUN_006c71b4;
  int iVar2 = in_ECX[1];
  if (iVar2 != 0) {
    int iVar3 = *reinterpret_cast<int*>(iVar2 + -4);
    int iVar4 = iVar2 + iVar3 * 4;
    if (-1 < iVar3 + -1) {
      do {
        int* piVar1 = reinterpret_cast<int*>(iVar4 + -4);
        iVar4 = iVar4 + -4;
        if (*piVar1 != 0) {
          piVar1 = reinterpret_cast<int*>(*piVar1 + 100);
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            FUN_005cb7c0();
          }
        }
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    operator_delete__(reinterpret_cast<void*>(iVar2 + -4));
  }
  return;
}

extern void* PTR_LAB_006c71b8;
extern int DAT_00717c6c;
extern void FUN_005bef60(int, int);
extern void FUN_005bf0f0(void*);
extern void FUN_005becc0(void*);
extern void FUN_005bf160(void*);

// 0x5bf140 — observed shape
void FUN_005bf140(void* self, uint8_t param_1)
{
  FUN_005bf0f0(self);
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
  return;
}

// 0x5bf160 — observed shape
void FUN_005bf160(void* self)
{
  uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
  *in_ECX = reinterpret_cast<uint32_t>(PTR_LAB_006c71b8);
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  FUN_005bef60(DAT_00717c64, 1);
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  *reinterpret_cast<uint8_t*>(in_ECX + 0x19) = 0;
  *reinterpret_cast<uint8_t*>(reinterpret_cast<int>(self) + 0x65) = 0;
  in_ECX[0x1a] = 0;
  *reinterpret_cast<uint8_t*>(in_ECX + 1) = 0;
  return;
}

// 0x5bf1c0 — observed shape
void FUN_005bf1c0()
{
  void* pvVar1 = DAT_00728d04;
  if (DAT_00728d04 != 0) {
    FUN_005becc0(pvVar1);
    operator_delete(pvVar1);
  }
  DAT_00728d04 = 0;
  return;
}

// 0x5bf1f0 — observed shape
uint32_t FUN_005bf1f0(void* self, uint32_t* param_1, uint32_t* param_2)
{
  int in_ECX = reinterpret_cast<int>(self);
  uint32_t* puVar6 = param_2;
  uint32_t* puVar5 = param_1;
  int iVar3;
  if ((uint32_t)DAT_00717c64 <= (uint32_t)param_1) {
    if ((uint32_t)DAT_00717c6c <= (uint32_t)param_1) {
      return 1;
    }
    param_1 = param_2;
    if (param_2 != 0) {
      param_2[0x19] = param_2[0x19] + 1;
    }
    FUN_005befc0(self, (uint32_t)puVar5, &param_1);
    if (puVar6 != 0) {
      uint32_t* puVar1 = puVar6 + 0x19;
      *puVar1 = *puVar1 - 1;
      if (*puVar1 == 0) {
        FUN_005cb7c0();
      }
    }
  }
  iVar3 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(in_ECX + 0x24) + (int)puVar5 * 4);
  if (iVar3 != 0) {
    *reinterpret_cast<int*>(in_ECX + 0x18) = *reinterpret_cast<int*>(in_ECX + 0x18) + -1;
    uint32_t* puVar4 = *reinterpret_cast<uint32_t**>(iVar3 + 4);
    if (puVar4 != 0) {
      puVar4[1] = puVar4[1] + 1;
    }
    if (puVar4 != 0) {
      int* piVar2 = reinterpret_cast<int*>(puVar4) + 1;
      *piVar2 = *piVar2 + -1;
      if (*piVar2 == 0) {
        auto fn = *reinterpret_cast<void(**)(int)>(*puVar4);
        fn(1);
      }
    }
    if (puVar4 != 0) {
      *reinterpret_cast<int*>(in_ECX + 0x1c) = *reinterpret_cast<int*>(in_ECX + 0x1c) + -1;
    }
  }
  param_1 = puVar6;
  if (puVar6 != 0) {
    puVar6[0x19] = puVar6[0x19] + 1;
  }
  FUN_005befc0(self, (uint32_t)puVar5, &param_1);
  if (puVar6 == 0) {
    iVar3 = *reinterpret_cast<int*>(in_ECX + 0x14);
    if ((iVar3 == (int)puVar5 + 1U) && (iVar3 != 0)) {
      while (*reinterpret_cast<int*>(*reinterpret_cast<int*>(in_ECX + 0x24) + -4 + iVar3 * 4) != 0) {
        if (*reinterpret_cast<int*>(in_ECX + 0x14) == 0) {
          return 0;
        }
      }
      *reinterpret_cast<int*>(in_ECX + 0x14) = iVar3 + -1;
    }
  } else {
    uint32_t* puVar1 = puVar6 + 0x19;
    *puVar1 = *puVar1 - 1;
    if (*puVar1 == 0) {
      FUN_005cb7c0();
    }
    *puVar6 = (uint32_t)puVar5;
    if (*reinterpret_cast<uint32_t**>(in_ECX + 0x14) == puVar5) {
      *reinterpret_cast<int*>(in_ECX + 0x14) = (int)*reinterpret_cast<uint32_t**>(in_ECX + 0x14) + 1;
    }
    *reinterpret_cast<int*>(in_ECX + 0x18) = *reinterpret_cast<int*>(in_ECX + 0x18) + 1;
    uint32_t* puVar4 = reinterpret_cast<uint32_t*>(puVar6[1]);
    if (puVar4 != 0) {
      puVar4[1] = puVar4[1] + 1;
    }
    if (puVar4 != 0) {
      int* piVar2 = reinterpret_cast<int*>(puVar4) + 1;
      *piVar2 = *piVar2 + -1;
      if (*piVar2 == 0) {
        auto fn = *reinterpret_cast<void(**)(int)>(*puVar4);
        fn(1);
      }
    }
    if (puVar4 != 0) {
      *reinterpret_cast<int*>(in_ECX + 0x1c) = *reinterpret_cast<int*>(in_ECX + 0x1c) + 1;
      return 0;
    }
  }
  return 0;
}

// 0x5bf320 — observed shape
void FUN_005bf320(void* self, int param_1)
{
  int* piVar2 = 0;
  int* in_ECX = reinterpret_cast<int*>(self);
  in_ECX[1] = param_1;
  in_ECX[2] = 0;
  if (param_1 != 0) {
    int* piVar1 = reinterpret_cast<int*>(thunk_FUN_00533c78(param_1 * 0x6c + 4));
    if (piVar1 != 0) {
      piVar2 = piVar1 + 1;
      *piVar1 = param_1;
      FUN_004127b0(piVar2, 0x6c, param_1, reinterpret_cast<void*>(&FUN_005bf160));
    }
  }
  *in_ECX = reinterpret_cast<int>(piVar2);
  return;
}

extern void FUN_005ca660(uint32_t);
extern void FUN_005bf050(void*);
extern void FUN_005cd3c0();
extern void FUN_005bf320(void*, int);

// 0x5bf370 — observed shape
void FUN_005bf370(void* self)
{
  uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
  *in_ECX = reinterpret_cast<uint32_t>(PTR_LAB_006c71b8);
  FUN_005ca660(in_ECX[0xe]);
  {
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(in_ECX[0xf]);
    if (puVar2 != 0) {
      int* piVar1 = reinterpret_cast<int*>(puVar2) + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        auto fn = *reinterpret_cast<void(**)(int)>(*puVar2);
        fn(1);
      }
      in_ECX[0xf] = 0;
    }
  }
  operator_delete__(reinterpret_cast<void*>(in_ECX[0x10]));
  operator_delete__(reinterpret_cast<void*>(in_ECX[0x11]));
  operator_delete__(reinterpret_cast<void*>(in_ECX[0x12]));
  {
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(in_ECX[0x13]);
    if (puVar2 != 0) {
      int* piVar1 = reinterpret_cast<int*>(puVar2) + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        auto fn = *reinterpret_cast<void(**)(int)>(*puVar2);
        fn(1);
      }
      in_ECX[0x13] = 0;
    }
  }
  {
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(in_ECX[0x14]);
    if (puVar2 != 0) {
      int* piVar1 = reinterpret_cast<int*>(puVar2) + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        auto fn = *reinterpret_cast<void(**)(int)>(*puVar2);
        fn(1);
      }
      in_ECX[0x14] = 0;
    }
  }
  operator_delete__(reinterpret_cast<void*>(in_ECX[0x15]));
  operator_delete__(reinterpret_cast<void*>(in_ECX[0x16]));
  operator_delete__(reinterpret_cast<void*>(in_ECX[0x17]));
  {
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(in_ECX[0x18]);
    if (puVar2 != 0) {
      int* piVar1 = reinterpret_cast<int*>(puVar2) + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        auto fn = *reinterpret_cast<void(**)(int)>(*puVar2);
        fn(1);
      }
      in_ECX[0x18] = 0;
    }
  }
  FUN_005bf050(self);
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  {
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(in_ECX[0x18]);
    if (puVar2 != 0) {
      int* piVar1 = reinterpret_cast<int*>(puVar2) + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        auto fn = *reinterpret_cast<void(**)(int)>(*puVar2);
        fn(1);
      }
    }
  }
  {
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(in_ECX[0x14]);
    if (puVar2 != 0) {
      int* piVar1 = reinterpret_cast<int*>(puVar2) + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        auto fn = *reinterpret_cast<void(**)(int)>(*puVar2);
        fn(1);
      }
    }
  }
  {
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(in_ECX[0x13]);
    if (puVar2 != 0) {
      int* piVar1 = reinterpret_cast<int*>(puVar2) + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        auto fn = *reinterpret_cast<void(**)(int)>(*puVar2);
        fn(1);
      }
    }
  }
  {
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(in_ECX[0xf]);
    if (puVar2 != 0) {
      int* piVar1 = reinterpret_cast<int*>(puVar2) + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        auto fn = *reinterpret_cast<void(**)(int)>(*puVar2);
        fn(1);
      }
    }
  }
  FUN_005bf0f0(self);
  return;
}

// 0x5bf560 — observed shape
void FUN_005bf560(void* self, uint32_t param_1)
{
  int* in_ECX = reinterpret_cast<int*>(self);
  int iVar1 = (int)reinterpret_cast<uintptr_t>(FUN_00533c78(0xc));
  int iVar4 = 0;
  int* local_4;
  if (iVar1 == 0) {
    local_4 = 0;
  } else {
    local_4 = reinterpret_cast<int*>(iVar1);
    FUN_005bf320(local_4, static_cast<int>(param_1));
  }
  uint32_t uVar3 = 0;
  if (param_1 != 0) {
    do {
      iVar1 = (uVar3 < (uint32_t)local_4[1]) ? (*local_4 + iVar4) : 0;
      int iVar2 = in_ECX[1];
      if (in_ECX[2] == iVar2) {
        if (iVar2 == 0) {
          iVar2 = 1;
        } else {
          iVar2 = iVar2 * 2;
        }
        FUN_0055f300(iVar2);
      }
      *reinterpret_cast<int*>(*in_ECX + in_ECX[2] * 4) = iVar1;
      in_ECX[2] = in_ECX[2] + 1;
      uVar3 = uVar3 + 1;
      iVar4 = iVar4 + 0x6c;
    } while (uVar3 < param_1);
  }
  local_4[2] = in_ECX[5];
  in_ECX[5] = reinterpret_cast<int>(local_4);
  return;
}

// 0x5bf6e0 — observed shape
uint32_t FUN_005bf6e0(uint32_t param_1, uint32_t* param_2, uint32_t* param_3)
{
  switch (param_1) {
  case 0:
    *param_2 = 1;
    *param_3 = 0x50;
    return 1;
  case 1:
    *param_2 = 1;
    *param_3 = 0x40;
    return 1;
  case 2:
    *param_2 = 1;
    *param_3 = 0x80;
    return 1;
  case 3:
    *param_2 = 1;
    *param_3 = 0x20;
    return 1;
  case 4:
    *param_2 = 2;
    *param_3 = 0x20;
    return 1;
  default:
    return 0;
  }
}

// 0x5bf7b0 — observed shape
void FUN_005bf7b0(void* self)
{
  int in_ECX = reinterpret_cast<int>(self);
  auto v = *reinterpret_cast<std::uintptr_t*>(*reinterpret_cast<int**>(in_ECX + 0x5a4));
  auto fn = *reinterpret_cast<void(**)()>(v + 4);
  fn();
  FUN_005cd3c0();
  return;
}

// 0x5bf800 — observed shape
uint32_t FUN_005bf800(void* self, uint32_t param_1)
{
  int in_ECX = reinterpret_cast<int>(self);
  auto v = *reinterpret_cast<std::uintptr_t*>(*reinterpret_cast<int**>(in_ECX + 0x5cc));
  auto fn = *reinterpret_cast<void(**)(uint32_t)>(v + 0x44);
  fn(param_1);
  if (((char)param_1 == '\0') || ((*reinterpret_cast<uint32_t*>(in_ECX + 0x294) & 0x100) != 0)) {
    return 1;
  }
  return 0;
}
