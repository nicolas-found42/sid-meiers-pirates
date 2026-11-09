#include <cstdint>
#include <cstddef>
extern "C" int FUN_005e5b50(uint32_t param_1);
extern "C" uint32_t* FUN_005e5960(uint32_t param_1, uint32_t kind, uint32_t param_2);
extern "C" void FUN_006b3e90(uint32_t param_3);
extern "C" void FUN_006b40e0(uint32_t param_4, int param_5);
extern "C" void FUN_006b40c0(int on);
extern "C" char FUN_005e5bb0(uint32_t* vtbl);

extern "C" void FUN_006b3eb0(uint32_t v);
extern "C" void FUN_006b4110(uint32_t p, float f);
extern "C" void FUN_006b3ed0(void* v);
extern "C" void FUN_006b4140(void* a, void* b);
extern "C" void FUN_006b3ef0(void* v);
extern "C" void FUN_006b4180(void* a, void* b);
extern "C" void FUN_006b3f10(uint32_t v);
extern "C" void FUN_006b41d0(uint32_t p, int v);

// 0x5e5c60 — observed shape
uint32_t FUN_005e5c60(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, int param_5) {
  int iVar2 = FUN_005e5b50(param_1);
  if (iVar2 == 0) {
    uint32_t* puVar3 = FUN_005e5960(param_1, 3, param_2);
    FUN_006b3e90(param_3);
    if (param_5 != 0) {
      FUN_006b40e0(param_4, param_5);
      FUN_006b40c0(1);
    }
    char cVar1 = FUN_005e5bb0(puVar3);
    if (cVar1 != '\0') return 1;
    if (puVar3 != nullptr) {
      using F = void(*)(int);
      F fn = reinterpret_cast<F>((*puVar3) ? *(void**)puVar3 : nullptr);
      // (*puVar3)(1) — invoke vtable[0] effectively slot at *puVar3
      fn(1);
    }
  }
  return 0;
}

// 0x5e5ce0 — observed shape
uint32_t FUN_005e5ce0(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, float param_5) {
  int iVar2 = FUN_005e5b50(param_1);
  if (iVar2 == 0) {
    uint32_t* puVar3 = FUN_005e5960(param_1, 4, param_2);
    FUN_006b3eb0(param_3);
    if (param_5 != 0.0f) {
      FUN_006b4110(param_4, param_5);
      FUN_006b40c0(1);
    }
    char cVar1 = FUN_005e5bb0(puVar3);
    if (cVar1 != '\0') return 1;
    if (puVar3 != nullptr) {
      using F = void(*)(int);
      F fn = reinterpret_cast<F>(*(void**)puVar3);
      fn(1);
    }
  }
  return 0;
}

// 0x5e5d70 — observed shape
uint32_t FUN_005e5d70(uint32_t param_1, uint32_t param_2, uint32_t* param_3, uint32_t* param_4, uint32_t* param_5) {
  int iVar2 = FUN_005e5b50(param_1);
  if (iVar2 == 0) {
    uint32_t* puVar3 = FUN_005e5960(param_1, 5, param_2);
    uint32_t local_18 = param_3[0];
    uint32_t local_14 = param_3[1];
    FUN_006b3ed0(&local_18);
    if (param_5 != nullptr) {
      uint32_t local_8 = param_4[0];
      uint32_t local_4 = param_4[1];
      uint32_t local_10 = param_5[0];
      uint32_t local_c = param_5[1];
      (void)local_8; (void)local_4; (void)local_10; (void)local_c;
      FUN_006b4140(&local_8, &local_10);
      FUN_006b40c0(1);
    }
    char cVar1 = FUN_005e5bb0(puVar3);
    if (cVar1 != '\0') return 1;
    if (puVar3 != nullptr) {
      using F = void(*)(int);
      F fn = reinterpret_cast<F>(*(void**)puVar3);
      fn(1);
    }
  }
  return 0;
}

// 0x5e5e30 — observed shape
uint32_t FUN_005e5e30(uint32_t param_1, uint32_t param_2, uint32_t* param_3, uint32_t* param_4, uint32_t* param_5) {
  int iVar2 = FUN_005e5b50(param_1);
  if (iVar2 == 0) {
    uint32_t* puVar3 = FUN_005e5960(param_1, 6, param_2);
    uint32_t local_24 = param_3[0];
    uint32_t local_20 = param_3[1];
    uint32_t local_1c = param_3[2];
    FUN_006b3ef0(&local_24);
    if (param_5 != nullptr) {
      uint32_t local_c = param_4[0];
      uint32_t local_8 = param_4[1];
      uint32_t local_4 = param_4[2];
      uint32_t local_18 = param_5[0];
      uint32_t local_14 = param_5[1];
      uint32_t local_10 = param_5[2];
      (void)local_c; (void)local_8; (void)local_4; (void)local_18; (void)local_14; (void)local_10;
      FUN_006b4180(&local_c, &local_18);
      FUN_006b40c0(1);
    }
    char cVar1 = FUN_005e5bb0(puVar3);
    if (cVar1 != '\0') return 1;
    if (puVar3 != nullptr) {
      using F = void(*)(int);
      F fn = reinterpret_cast<F>(*(void**)puVar3);
      fn(1);
    }
  }
  return 0;
}

// 0x5e5f00 — observed shape
uint32_t FUN_005e5f00(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, int param_5) {
  int iVar2 = FUN_005e5b50(param_1);
  if (iVar2 == 0) {
    uint32_t* puVar3 = FUN_005e5960(param_1, 7, param_2);
    FUN_006b3f10(param_3);
    if (param_5 != 0) {
      FUN_006b41d0(param_4, param_5);
      FUN_006b40c0(1);
    }
    char cVar1 = FUN_005e5bb0(puVar3);
    if (cVar1 != '\0') return 1;
    if (puVar3 != nullptr) {
      using F = void(*)(int);
      F fn = reinterpret_cast<F>(*(void**)puVar3);
      fn(1);
    }
  }
  return 0;
}

// ---------------------------------------------------------------- appended block

// helpers referenced by the definitions below
extern "C" void FUN_006b4b90(void* p);
extern "C" void FUN_006b3f40(uint32_t v);
extern "C" void FUN_006b3f60(void* p);
extern "C" void FUN_006b4230(void* a, void* b);
extern "C" void FUN_006b3f90(void* p);
extern "C" void FUN_006b4290(void* a, void* b);
extern "C" void FUN_006b3fc0(uint32_t a, uint32_t b);
extern "C" void FUN_005edba0(void);
extern "C" char FUN_006b52e0(char* s, uint32_t* a, uint32_t* b);
extern "C" void* thunk_FUN_00533c78(uint32_t size);
extern "C" void operator_delete__(void* p);
extern "C" int FUN_005e7ba0(void);
extern "C" int FUN_005f8222(int* a, uint32_t b, int c, int d, uint32_t* e, int f, uint32_t* g, int** h);
extern "C" int FUN_005f8112(uint32_t a, int b, int c, uint32_t* d, uint32_t* e, int** f);
extern "C" int FUN_005e3460(int* a, int b, uint32_t c, uint32_t d, uint32_t e, int f,
                            uint32_t g, uint32_t h, uint32_t i, uint32_t j);
extern "C" int func_0x005e3d90(uint32_t a, uint32_t b);
extern "C" int FUN_005f7452(uint32_t a, int b, uint32_t c, uint32_t d, uint32_t e, int f, int g,
                            int h, uint32_t i, uint32_t j, int k, int l, int m, uint32_t* n);
extern "C" int FUN_005f7519(uint32_t a, int b, uint32_t c, uint32_t d, uint32_t e, int f, int g,
                            int h, int i, uint32_t j, uint32_t k, int l, int m, int n,
                            uint32_t* o);
extern "C" int FUN_005f74b7(uint32_t a, int b, uint32_t c, uint32_t d, int e, int f, int g,
                            uint32_t h, uint32_t i, int j, int k, int l, uint32_t* m);
extern "C" int FUN_00540540(uint32_t a);
extern "C" char FUN_004879c0(void* a, int b);
extern "C" char FUN_005be240(uint32_t a, int* b, uint32_t** c);
extern "C" int tolower(int c);
extern "C" char* strstr(const char* haystack, const char* needle);
extern "C" char* builtin_strncpy(char* dst, const char* src, size_t n);

extern "C" uint32_t DAT_007290b8;
extern "C" uint32_t DAT_00727c30;
extern "C" uint32_t DAT_0072798c;
extern "C" uint32_t DAT_00727dc8;
extern "C" void* PTR_FUN_006c9928[];   // vtable installed at self+4
extern "C" void* ExceptionList;        // NT_TIB exception chain
extern "C" uint8_t LAB_006b983b;       // SEH handler address

// 0x5e5f80 — observed shape
uint32_t FUN_005e5f80(uint32_t param_1, uint32_t param_2, uint32_t* param_3) {
  int iVar2 = FUN_005e5b50(param_1);
  if (iVar2 == 0) {
    uint32_t* puVar3 = FUN_005e5960(param_1, 8, param_2);
    uint32_t local[9];
    // listing fills a contiguous 9-dword buffer, skipping param_3[3] and param_3[7]
    local[0] = param_3[0];
    local[1] = param_3[1];
    local[2] = param_3[2];
    local[3] = param_3[4];
    local[4] = param_3[5];
    local[5] = param_3[6];
    local[6] = param_3[8];
    local[7] = param_3[9];
    local[8] = param_3[10];
    FUN_006b4b90(&local[0]);
    FUN_006b40c0(0);
    char cVar1 = FUN_005e5bb0(puVar3);
    if (cVar1 != '\0') return 1;
    if (puVar3 != nullptr) {
      using F = void(*)(int);
      F fn = reinterpret_cast<F>(*(void**)puVar3);
      fn(1);
    }
  }
  return 0;
}

// 0x5e6030 — observed shape
uint32_t FUN_005e6030(uint32_t param_1, uint32_t param_2, uint32_t param_3) {
  int iVar2 = FUN_005e5b50(param_1);
  if (iVar2 == 0) {
    uint32_t* puVar3 = FUN_005e5960(param_1, 9, param_2);
    FUN_006b3f40(param_3);
    FUN_006b40c0(0);
    char cVar1 = FUN_005e5bb0(puVar3);
    if (cVar1 != '\0') return 1;
    if (puVar3 != nullptr) {
      using F = void(*)(int);
      F fn = reinterpret_cast<F>(*(void**)puVar3);
      fn(1);
    }
  }
  return 0;
}

// 0x5e6090 — observed shape
uint32_t FUN_005e6090(uint32_t param_1, uint32_t param_2, uint32_t* param_3, uint32_t* param_4,
                      uint32_t* param_5) {
  int iVar2 = FUN_005e5b50(param_1);
  if (iVar2 == 0) {
    uint32_t* puVar3 = FUN_005e5960(param_1, 10, param_2);
    uint32_t local_24 = param_3[0];
    uint32_t local_20 = param_3[1];
    uint32_t local_1c = param_3[2];
    uint32_t local_18, local_14, local_10;
    uint32_t local_c, local_8, local_4;
    FUN_006b3f60(&local_24);
    if (param_5 != nullptr) {
      local_c = param_4[0];
      local_8 = param_4[1];
      local_4 = param_4[2];
      local_18 = param_5[0];
      local_14 = param_5[1];
      local_10 = param_5[2];
      FUN_006b4230(&local_c, &local_18);
      FUN_006b40c0(1);
    }
    char cVar1 = FUN_005e5bb0(puVar3);
    if (cVar1 != '\0') return 1;
    if (puVar3 != nullptr) {
      using F = void(*)(int);
      F fn = reinterpret_cast<F>(*(void**)puVar3);
      fn(1);
    }
  }
  return 0;
}

// 0x5e6160 — observed shape
uint32_t FUN_005e6160(uint32_t param_1, uint32_t param_2, uint32_t* param_3, uint32_t* param_4,
                      uint32_t* param_5) {
  int iVar2 = FUN_005e5b50(param_1);
  if (iVar2 == 0) {
    uint32_t* puVar3 = FUN_005e5960(param_1, 10, param_2);
    uint32_t local_30 = param_3[0];
    uint32_t local_2c = param_3[1];
    uint32_t local_28 = param_3[2];
    uint32_t local_24 = param_3[3];
    uint32_t local_20, local_1c, local_18, local_14;
    uint32_t local_10, local_c, local_8, local_4;
    FUN_006b3f90(&local_30);
    if (param_5 != nullptr) {
      local_10 = param_4[0];
      local_c = param_4[1];
      local_8 = param_4[2];
      local_4 = param_4[3];
      local_20 = param_5[0];
      local_1c = param_5[1];
      local_18 = param_5[2];
      local_14 = param_5[3];
      FUN_006b4290(&local_10, &local_20);
      FUN_006b40c0(1);
    }
    char cVar1 = FUN_005e5bb0(puVar3);
    if (cVar1 != '\0') return 1;
    if (puVar3 != nullptr) {
      using F = void(*)(int);
      F fn = reinterpret_cast<F>(*(void**)puVar3);
      fn(1);
    }
  }
  return 0;
}

// 0x5e6240 — observed shape
uint32_t FUN_005e6240(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4) {
  int iVar2 = FUN_005e5b50(param_1);
  if (iVar2 == 0) {
    uint32_t* puVar3 = FUN_005e5960(param_1, 0xb, param_2);
    FUN_006b3fc0(param_3, param_4);
    char cVar1 = FUN_005e5bb0(puVar3);
    if (cVar1 != '\0') return 1;
    if (puVar3 != nullptr) {
      using F = void(*)(int);
      F fn = reinterpret_cast<F>(*(void**)puVar3);
      fn(1);
    }
  }
  return 0;
}

// 0x5e62a0 — observed shape
void FUN_005e62a0(void* self) {
  void* local_c;
  uint8_t* puStack_8;
  uint32_t local_4;

  puStack_8 = &LAB_006b983b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(uint32_t*)((uint8_t*)self + 0x10) = 0;
  *(uint32_t*)((uint8_t*)self + 8) = 0;
  *(uint32_t*)((uint8_t*)self + 0xc) = 0;
  *(void**)((uint8_t*)self + 4) = (void*)PTR_FUN_006c9928;
  local_4 = 0;
  FUN_005edba0();
  ExceptionList = local_c;
  (void)puStack_8;
  (void)local_4;
}

// 0x5e62f0 — observed shape
void FUN_005e62f0(void) {
  DAT_007290b8 = 0;
}

// 0x5e6300 — observed shape
int FUN_005e6300(char* param_1, char param_2) {
  char cVar1;
  char* pcVar2;
  int iVar3;
  int iVar4;
  char* pcVar5;
  char* pcVar6;
  char* pcVar7;
  uint32_t local_c;
  int local_8;
  uint32_t local_4;

  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar3 = (int)(pcVar2 - (param_1 + 1));
  pcVar2 = (char*)thunk_FUN_00533c78((uint32_t)(iVar3 + 6));
  iVar4 = 0;
  if (iVar3 != 0) {
    pcVar7 = pcVar2;
    local_8 = iVar3;
    do {
      iVar4 = tolower((int)pcVar7[(int)param_1 - (int)pcVar2]);
      *pcVar7 = (char)iVar4;
      pcVar7 = pcVar7 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar4 = local_8;
  }
  pcVar2[iVar4] = '\0';
  pcVar7 = strstr(pcVar2, "projection");
  if ((pcVar7 != nullptr) && (pcVar7 != pcVar2)) {
    pcVar6 = pcVar7 + 10;
    pcVar5 = pcVar7 + 4;
    cVar1 = pcVar7[10];
    while (cVar1 != '\0') {
      *pcVar5 = cVar1;
      pcVar7 = pcVar6 + 1;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
      cVar1 = *pcVar7;
    }
    *pcVar5 = '\0';
  }
  if (param_2 != '\0') {
    pcVar7 = strstr(pcVar2, "transpose");
    if (pcVar7 == nullptr) {
      pcVar7 = pcVar2 + -1;
      do {
        pcVar6 = pcVar7;
        pcVar7 = pcVar6 + 1;
      } while (pcVar6[1] != '\0');
      builtin_strncpy(pcVar6 + 1, "transpose", 10);
    } else {
      *pcVar7 = '\0';
    }
  }
  local_c = 0;
  local_4 = 0;
  cVar1 = FUN_006b52e0(pcVar2, &local_c, &local_4);
  operator_delete__(pcVar2);
  if (cVar1 == '\0') {
    return 0;
  }
  iVar4 = FUN_005e7ba0();
  *(char**)(iVar4 + 0xc) = param_1;
  *(uint32_t*)(iVar4 + 0x10) = local_c;
  return iVar4;
}

// 0x5e6420 — observed shape
uint32_t FUN_005e6420(int* param_1, uint32_t param_2, uint32_t* param_3, int* entry_EAX) {
  // entry_EAX — entry EAX (Ghidra "unaff_retaddr"); object whose vtable +0x10/+0x8 are used
  using VRel = void(*)(int*);
  using V0c = char*(*)(int*);
  using V10 = uint32_t(*)(int*);

  int iVar2;
  char cVar1;
  char* pcVar3;
  uint32_t uVar4;
  char* pcVar5;
  uint32_t local_4 = 0;
  int* pObj = param_1;  // the call writes through &param_1, i.e. replaces the object pointer

  iVar2 = FUN_005f8222(pObj, param_2, 0, 0, param_3, 0, &local_4, &pObj);
  if (-1 < iVar2) {
    if (pObj != nullptr) {
      reinterpret_cast<VRel>(*(void**)(*pObj + 8))(pObj);
    }
    return local_4;
  }
  if (pObj != nullptr) {
    pcVar3 = reinterpret_cast<V0c>(*(void**)(*pObj + 0xc))(pObj);
    if (pcVar3 != nullptr) {
      uVar4 = reinterpret_cast<V10>(*(void**)(*entry_EAX + 0x10))(entry_EAX);
      pcVar5 = (char*)thunk_FUN_00533c78(uVar4);
      *param_3 = (uint32_t)pcVar5;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        *pcVar5 = cVar1;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
    }
    reinterpret_cast<VRel>(*(void**)(*entry_EAX + 8))(entry_EAX);
  }
  return 0;
}

// 0x5e64b0 — observed shape
uint32_t FUN_005e64b0(uint32_t param_1, uint32_t* param_2, int* entry_ESI) {
  // entry_ESI — entry ESI (Ghidra "unaff_ESI"); object whose vtable +0x10/+0x8 are used
  using VRel = void(*)(int*);
  using V0c = char*(*)(int*);
  using V10 = uint32_t(*)(int*);

  int iVar2;
  char cVar1;
  char* pcVar3;
  uint32_t uVar4;
  char* pcVar5;
  int* local_8 = nullptr;
  uint32_t local_4 = 0;

  iVar2 = FUN_005f8112(param_1, 0, 0, param_2, &local_4, &local_8);
  if (-1 < iVar2) {
    if (local_8 != nullptr) {
      reinterpret_cast<VRel>(*(void**)(*local_8 + 8))(local_8);
    }
    return local_4;
  }
  if (local_8 != nullptr) {
    pcVar3 = reinterpret_cast<V0c>(*(void**)(*local_8 + 0xc))(local_8);
    if (pcVar3 != nullptr) {
      uVar4 = reinterpret_cast<V10>(*(void**)(*entry_ESI + 0x10))(entry_ESI);
      pcVar5 = (char*)thunk_FUN_00533c78(uVar4);
      *param_2 = (uint32_t)pcVar5;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        *pcVar5 = cVar1;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
    }
    reinterpret_cast<VRel>(*(void**)(*entry_ESI + 8))(entry_ESI);
  }
  return 0;
}

// 0x5e6540 — observed shape
void FUN_005e6540(int* param_1, uint32_t* self) {
  using V24 = uint32_t(*)(int*, int, uint32_t);
  uint32_t uVar1 = reinterpret_cast<V24>(*(void**)(*param_1 + 0x24))(param_1, 0, self[1]);
  self[0] = uVar1;
}

// 0x5e6560 — observed shape
void FUN_005e6560(void* self) {
  uint32_t local_4 = 0;
  int iVar1;
  if (*(int*)((uint8_t*)self + 0x20) == 0) {
    if (*(int*)((uint8_t*)self + 0x1c) == 0) {
      iVar1 = 0;
    } else {
      iVar1 = FUN_005f7452(*(uint32_t*)(DAT_00727c30 + 0x60),
                           *(int*)((uint8_t*)self + 0x1c),
                           *(uint32_t*)((uint8_t*)self + 0x2c),
                           *(uint32_t*)((uint8_t*)self + 0x30),
                           0xffffffffu, 0, 0, 1, 0xffffffffu, 0xffffffffu, 0, 0, 0, &local_4);
    }
    if (-1 < iVar1) {
      *(uint32_t*)((uint8_t*)self + 0x28) = local_4;
    }
  }
}

// 0x5e65c0 — observed shape
void FUN_005e65c0(void* self) {
  uint32_t local_4 = 0;
  int iVar1;
  if (*(int*)((uint8_t*)self + 0x20) == 0) {
    if (*(int*)((uint8_t*)self + 0x1c) == 0) {
      iVar1 = 0;
    } else {
      iVar1 = FUN_005f7519(*(uint32_t*)(DAT_00727c30 + 0x60),
                           *(int*)((uint8_t*)self + 0x1c),
                           *(uint32_t*)((uint8_t*)self + 0x2c),
                           *(uint32_t*)((uint8_t*)self + 0x30),
                           *(uint32_t*)((uint8_t*)self + 0x34),
                           1, 0, 0, 1, 0xffffffffu, 0xffffffffu, 0, 0, 0, &local_4);
    }
    if (-1 < iVar1) {
      *(uint32_t*)((uint8_t*)self + 0x28) = local_4;
    }
  }
}

// 0x5e6620 — observed shape
void FUN_005e6620(void* self) {
  uint32_t local_4 = 0;
  int iVar1;
  if (*(int*)((uint8_t*)self + 0x20) == 0) {
    if (*(int*)((uint8_t*)self + 0x1c) == 0) {
      iVar1 = 0;
    } else {
      iVar1 = FUN_005f74b7(*(uint32_t*)(DAT_00727c30 + 0x60),
                           *(int*)((uint8_t*)self + 0x1c),
                           *(uint32_t*)((uint8_t*)self + 0x2c),
                           0xffffffffu, 0, 0, 1, 0xffffffffu, 0xffffffffu, 0, 0, 0, &local_4);
    }
    if (-1 < iVar1) {
      *(uint32_t*)((uint8_t*)self + 0x28) = local_4;
    }
  }
}

// 0x5e6680 — observed shape
uint32_t FUN_005e6680(int* param_1, int param_2, uint32_t param_3, uint32_t param_4,
                      uint32_t param_5, int param_6, uint32_t param_7, uint32_t param_8,
                      uint32_t param_9, uint32_t param_10, uint32_t* self, int* unaff_EBX,
                      int* entry_EAX) {
  // self       — entry ECX receiver
  // unaff_EBX  — entry EBX (Ghidra "unaff_EBX"); source vector pointer reused by the copies
  // entry_EAX  — entry EAX (Ghidra "piStack_4"); object whose vtable +0xd0 is invoked
  using VFnS = void(*)(int*, uint32_t, int);
  using VFnU = void(*)(int*, uint32_t, uint32_t);
  using VFnP = void(*)(int*, uint32_t, uint32_t*);
  using VFnB = void(*)(int*, uint32_t, uint8_t);
  using VFnN = void(*)(int*, uint32_t, uint32_t*, uint32_t);

  int iVar1;
  uint32_t* puVar2;
  char cVar3;
  uint32_t uVar4;
  int iVar5;
  uint32_t* local_94;
  uint32_t local_90;
  int local_8c;
  // contiguous 16-dword block spanning Ghidra's local_88[5] .. uStack_4c:
  //   v[0..4] = local_88[0..4], v[5] = iStack_74, v[6] = iStack_70, v[7] = iStack_6c,
  //   v[8] = iStack_68, v[9] = iStack_64, v[10] = iStack_60, v[11] = iStack_5c,
  //   v[12] = iStack_58, v[13] = iStack_54, v[14] = iStack_50, v[15] = uStack_4c
  int v[16];
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  uint8_t local_2c[40];

  if (self[3] != 0) {
    return FUN_005e3460(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8,
                        param_9, param_10);
  }
  if (self[9] != 0) {
    iVar5 = func_0x005e3d90(*(uint32_t*)(param_6 + 0x28), self[9]);
    if (iVar5 == 0) {
      return 0;
    }
    reinterpret_cast<VFnS>(*(void**)(*entry_EAX + 0xd0))(entry_EAX, *self, iVar5);
    return 1;
  }
  if (self[4] == 0) {
    return 0;
  }
  if (self[4] == 6) {
    iVar5 = self[5];
    if (iVar5 == 2) {
      if (self[10] == 0) {
        FUN_005e65c0(self);
      }
    } else if (iVar5 == 3) {
      if (self[10] == 0) {
        FUN_005e6620(self);
      }
    } else if ((iVar5 == 1) && (self[10] == 0)) {
      FUN_005e6560(self);
    }
    reinterpret_cast<VFnU>(*(void**)(*param_1 + 0xd0))(param_1, *self, self[10]);
    return 1;
  }
  if (param_2 == 0) {
    return 0;
  }
  if (*(char*)((uint8_t*)self + 8) == '\0') {
    iVar5 = FUN_00540540(self[1]);
    if (iVar5 == 0) {
      return 0;
    }
    iVar1 = self[4];
    if (iVar1 == 3) {
      reinterpret_cast<VFnU>(*(void**)(*param_1 + 0x78))(param_1, *self,
                                                          *(uint32_t*)(iVar5 + 0x10));
      return 1;
    }
    if (iVar1 == 2) {
      cVar3 = FUN_004879c0(&DAT_0072798c, iVar5);
      if (cVar3 == '\0') {
        cVar3 = FUN_004879c0(&DAT_00727dc8, iVar5);
        if (cVar3 == '\0') goto LAB_005e6c06;
        v[0] = *(int*)(iVar5 + 0x18);
        local_90 = *(uint32_t*)(iVar5 + 0x10);
        local_8c = *(int*)(iVar5 + 0x14);
        if (self[6] != 3) {
          v[1] = *(int*)(iVar5 + 0x1c);
          goto LAB_005e6c06;
        }
      } else {
        puVar2 = *(uint32_t**)(iVar5 + 0x14);
        if (*(int*)(iVar5 + 0x10) == 2) {
          local_90 = puVar2[0];
          local_8c = (int)puVar2[1];
          v[0] = 0;
          v[1] = (int)0x3f800000u;
          goto LAB_005e6c06;
        }
        local_90 = puVar2[0];
        if (*(int*)(iVar5 + 0x10) != 3) {
          local_8c = (int)puVar2[1];
          v[0] = (int)puVar2[2];
          v[1] = (int)puVar2[3];
          local_3c = (int)local_90;
          local_38 = local_8c;
          local_34 = v[0];
          local_30 = v[1];
          goto LAB_005e6c06;
        }
        local_8c = (int)puVar2[1];
        v[0] = (int)puVar2[2];
      }
      v[1] = (int)0x3f800000u;
LAB_005e6c06:
      reinterpret_cast<VFnP>(*(void**)(*param_1 + 0x88))(param_1, *self, &local_90);
      return 1;
    }
    if (iVar1 != 1) {
      if (iVar1 == 5) {
        reinterpret_cast<VFnU>(*(void**)(*param_1 + 0x68))(param_1, *self,
                                                            *(uint32_t*)(iVar5 + 0x10));
        return 1;
      }
      if (iVar1 == 4) {
        reinterpret_cast<VFnB>(*(void**)(*param_1 + 0x58))(param_1, *self,
                                                            *(uint8_t*)(iVar5 + 0x10));
        return 1;
      }
      return 0;
    }
    iVar1 = *(int*)(iVar5 + 0x10);
    puVar2 = *(uint32_t**)(iVar5 + 0x14);
    reinterpret_cast<void(*)(int*, uint32_t, uint8_t*)>(*(void**)(*param_1 + 0x10))(
        param_1, *self, local_2c);
    if (iVar1 == 0x10) {
      int* piVar7 = v;
      uint32_t* piVar6 = puVar2;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *piVar7 = (int)*piVar6;
        piVar6 = piVar6 + 1;
        piVar7 = piVar7 + 1;
      }
    } else {
      v[0] = (int)puVar2[0];
      if (self[0xb] == 3) {
        v[1] = (int)puVar2[1];
        v[2] = (int)puVar2[2];
        v[3] = 0;
        v[4] = (int)puVar2[3];
        v[5] = (int)puVar2[4];
        v[6] = (int)puVar2[5];
        v[7] = 0;
        v[8] = (int)puVar2[6];
        v[9] = (int)puVar2[7];
        v[10] = (int)puVar2[8];
        v[11] = 0;
        if (self[0xc] == 3) goto LAB_005e6d3a;
        v[12] = (int)puVar2[9];
        v[13] = (int)puVar2[10];
        v[14] = (int)puVar2[0xb];
      } else {
        v[1] = (int)puVar2[1];
        v[2] = (int)puVar2[2];
        v[3] = (int)puVar2[3];
        v[4] = (int)puVar2[4];
        v[5] = (int)puVar2[5];
        v[6] = (int)puVar2[6];
        v[7] = (int)puVar2[7];
        v[8] = (int)puVar2[8];
        v[9] = (int)puVar2[9];
        v[10] = (int)puVar2[10];
        v[11] = (int)puVar2[0xb];
LAB_005e6d3a:
        v[12] = 0;
        v[13] = 0;
        v[14] = 0;
      }
      v[15] = (int)0x3f800000u;
    }
    uVar4 = *self;
    iVar5 = *param_1;
    if (local_30 == 3) {
      reinterpret_cast<VFnP>(*(void**)(iVar5 + 0xb0))(param_1, uVar4, (uint32_t*)v);
      return 1;
    }
    goto LAB_005e6d7f;
  }
  v[2] = 0;
  local_94 = nullptr;
  cVar3 = FUN_005be240(self[1], &v[2], &local_94);
  if (cVar3 == '\0') {
    return 0;
  }
  iVar5 = self[4];
  if (iVar5 == 3) {
    if (v[2] == 4) {
      reinterpret_cast<VFnP>(*(void**)(*param_1 + 0x78))(param_1, *self, local_94);
      return 1;
    }
    return 0;
  }
  if (iVar5 == 2) {
    if (v[2] == 8) {
      local_90 = local_94[0];
      local_8c = (int)local_94[1];
      v[0] = 0;
      v[1] = (int)0x3f800000u;
    } else if (v[2] == 0xc) {
      local_90 = local_94[0];
      local_8c = (int)local_94[1];
      v[0] = (int)local_94[2];
      v[1] = (int)0x3f800000u;
    } else if (v[2] == 0x10) {
      local_90 = local_94[0];
      local_8c = (int)local_94[1];
      v[0] = (int)local_94[2];
      v[1] = (int)local_94[3];
      local_3c = (int)local_90;
      local_38 = local_8c;
      local_34 = v[0];
      local_30 = v[1];
    } else if (0x10 < (uint32_t)v[2]) {
      reinterpret_cast<VFnN>(*(void**)(*param_1 + 0x90))(param_1, *self, local_94,
                                                          (uint32_t)v[2] >> 4);
      return 1;
    }
    reinterpret_cast<VFnP>(*(void**)(*param_1 + 0x88))(param_1, *self, &local_90);
    return 1;
  }
  if (iVar5 != 1) {
    if (iVar5 == 5) {
      if (v[2] == 4) {
        reinterpret_cast<VFnU>(*(void**)(*param_1 + 0x68))(param_1, *self, *local_94);
        return 1;
      }
      return 0;
    }
    if (iVar5 != 4) {
      return 0;
    }
    if (v[2] == 1) {
      reinterpret_cast<VFnB>(*(void**)(*param_1 + 0x58))(param_1, *self,
                                                          *(uint8_t*)local_94);
      return 1;
    }
    return 0;
  }
  reinterpret_cast<void(*)(int*, uint32_t, uint8_t*)>(*(void**)(*param_1 + 0x10))(
      param_1, *self, local_2c);
  if (local_8c == 0x40) {
    int* piVar6 = v;
    for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *piVar6 = *unaff_EBX;
      unaff_EBX = unaff_EBX + 1;
      piVar6 = piVar6 + 1;
    }
  } else {
    v[0] = *unaff_EBX;
    v[1] = unaff_EBX[1];
    v[2] = unaff_EBX[2];
    if (self[0xb] == 3) {
      v[3] = 0;
      v[4] = unaff_EBX[3];
      v[5] = unaff_EBX[4];
      v[6] = unaff_EBX[5];
      v[7] = 0;
      v[8] = unaff_EBX[6];
      v[9] = unaff_EBX[7];
      v[10] = unaff_EBX[8];
      v[11] = 0;
      if (self[0xc] == 3) goto LAB_005e6a2d;
      v[12] = unaff_EBX[9];
      v[13] = unaff_EBX[10];
      v[14] = unaff_EBX[0xb];
    } else {
      v[3] = unaff_EBX[3];
      v[4] = unaff_EBX[4];
      v[5] = unaff_EBX[5];
      v[6] = unaff_EBX[6];
      v[7] = unaff_EBX[7];
      v[8] = unaff_EBX[8];
      v[9] = unaff_EBX[9];
      v[10] = unaff_EBX[10];
      v[11] = unaff_EBX[0xb];
LAB_005e6a2d:
      v[12] = 0;
      v[13] = 0;
      v[14] = 0;
    }
    v[15] = (int)0x3f800000u;
  }
  uVar4 = *self;
  iVar5 = *param_1;
  if (local_30 == 3) {
    // the listing records this indirect call with no arguments
    reinterpret_cast<void(*)(void)>(*(void**)(iVar5 + 0xb0))();
    return 1;
  }
LAB_005e6d7f:
  reinterpret_cast<VFnP>(*(void**)(iVar5 + 0x98))(param_1, uVar4, (uint32_t*)v);
  return 1;
}
