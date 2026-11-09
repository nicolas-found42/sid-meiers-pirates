#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cstdio>
extern void FUN_00538400();
extern void FUN_00538430(int);
extern void FUN_00545600();
extern void FUN_00553060(uint32_t);
extern char FUN_00552bc0(int);
extern void FUN_00552c80();
extern void FUN_00552d20();
extern void FUN_00552aa0(int, uint32_t);
extern float FUN_0056a5f0(uint32_t, int, uint32_t, uint32_t, void*);
extern void FUN_005412c0(uint16_t);
extern void FUN_005531c0(int);
extern void FUN_00557b10(uint32_t);
extern void FUN_006b34a0(int);
extern void FUN_005606f0(uint32_t, void*);
extern void FUN_00548050(uint32_t);
extern void FUN_00557cb0(const char*, uint32_t);
extern void FUN_00557cf0(void*, uint32_t);
extern void FUN_00557d80(void*, uint32_t);
extern void FUN_00533c78(size_t);
extern void FUN_00538460(int);
extern void FUN_00547db0(int, uint32_t);
extern void FUN_004127b0(void*, int, int, const void*);
extern void FUN_005828d0(uint32_t);
extern void FUN_00579070();
extern void* PTR_FUN_006c46c8;
extern void* PTR_FUN_006c4750;
extern void DAT_007284e8;
extern void DAT_00728650;
extern void DAT_007289d0;
extern void DAT_007289c8;
extern void DAT_006c47fc;
extern void DAT_006c4804;
extern void operator_delete(void*);
extern void operator_delete__(char*);

// 0x577d20 — observed shape
void FUN_00577d20(void* self) {
  uint32_t* in_ECX = (uint32_t*)self;
  in_ECX[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c46c8;
  if (in_ECX[4] != 0) {
    void** vtbl = (void**)(uint32_t)(uintptr_t)&DAT_007284e8;
    uint32_t idx = in_ECX[5];
    typedef void (__cdecl *Fn)(uint32_t);
    Fn fn = (Fn)vtbl[idx];
    fn(in_ECX[4]);
  }
  if (in_ECX[7] != 0) {
    void** vtbl = (void**)(uint32_t)(uintptr_t)&DAT_007284e8;
    uint32_t idx = in_ECX[8];
    typedef void (__cdecl *Fn)(uint32_t);
    Fn fn = (Fn)vtbl[idx];
    fn(in_ECX[7]);
  }
  if (in_ECX[10] != 0) {
    void** vtbl = (void**)(uint32_t)(uintptr_t)&DAT_007284e8;
    uint32_t idx = in_ECX[0xb];
    typedef void (__cdecl *Fn)(uint32_t);
    Fn fn = (Fn)vtbl[idx];
    fn(in_ECX[10]);
  }
  if (in_ECX[0xd] != 0) {
    void** vtbl = (void**)(uint32_t)(uintptr_t)&DAT_007284e8;
    uint32_t idx = in_ECX[0xe];
    typedef void (__cdecl *Fn)(uint32_t);
    Fn fn = (Fn)vtbl[idx];
    fn(in_ECX[0xd]);
  }
  FUN_00538400();
}

// 0x577d90 — observed shape
void FUN_00577d90(void* self, int param_1, int param_2, uint32_t param_3) {
  int in_ECX = (int)(intptr_t)self;
  if (*(int*)(in_ECX + 0x10) != 0) {
    void** vtbl = (void**)(uint32_t)(uintptr_t)&DAT_007284e8;
    uint32_t idx = *(int*)(in_ECX + 0x14);
    typedef void (__cdecl *Fn)(int);
    Fn fn = (Fn)vtbl[idx];
    fn(*(int*)(in_ECX + 0x10));
  }
  if ((param_1 == 0) || (param_2 == 0)) {
    *(uint32_t*)(in_ECX + 0xc) = 0;
    *(uint32_t*)(in_ECX + 0x10) = 0;
    *(uint32_t*)(in_ECX + 0x14) = 0;
    return;
  }
  *(int*)(in_ECX + 0xc) = param_2;
  *(int*)(in_ECX + 0x10) = param_1;
  *(uint32_t*)(in_ECX + 0x14) = param_3;
}

// 0x577df0 — observed shape
void FUN_00577df0(void* self, int param_1, int param_2, uint32_t param_3) {
  int in_ECX = (int)(intptr_t)self;
  if (*(int*)(in_ECX + 0x1c) != 0) {
    void** vtbl = (void**)(uint32_t)(uintptr_t)&DAT_007284e8;
    uint32_t idx = *(int*)(in_ECX + 0x20);
    typedef void (__cdecl *Fn)(int);
    Fn fn = (Fn)vtbl[idx];
    fn(*(int*)(in_ECX + 0x1c));
  }
  if ((param_1 == 0) || (param_2 == 0)) {
    *(uint32_t*)(in_ECX + 0x18) = 0;
    *(uint32_t*)(in_ECX + 0x1c) = 0;
    *(uint32_t*)(in_ECX + 0x20) = 0;
    return;
  }
  *(int*)(in_ECX + 0x18) = param_2;
  *(int*)(in_ECX + 0x1c) = param_1;
  *(uint32_t*)(in_ECX + 0x20) = param_3;
}

// 0x577e50 — observed shape
void FUN_00577e50(void* self, int param_1, int param_2, uint32_t param_3) {
  int in_ECX = (int)(intptr_t)self;
  if (*(int*)(in_ECX + 0x28) != 0) {
    void** vtbl = (void**)(uint32_t)(uintptr_t)&DAT_007284e8;
    uint32_t idx = *(int*)(in_ECX + 0x2c);
    typedef void (__cdecl *Fn)(int);
    Fn fn = (Fn)vtbl[idx];
    fn(*(int*)(in_ECX + 0x28));
  }
  if ((param_1 == 0) || (param_2 == 0)) {
    *(uint32_t*)(in_ECX + 0x24) = 0;
    *(uint32_t*)(in_ECX + 0x28) = 0;
    *(uint32_t*)(in_ECX + 0x2c) = 0;
    return;
  }
  *(int*)(in_ECX + 0x24) = param_2;
  *(int*)(in_ECX + 0x28) = param_1;
  *(uint32_t*)(in_ECX + 0x2c) = param_3;
}

// 0x577eb0 — observed shape
void FUN_00577eb0(void* self, int param_1, int param_2, uint32_t param_3) {
  int in_ECX = (int)(intptr_t)self;
  if (*(int*)(in_ECX + 0x34) != 0) {
    void** vtbl = (void**)(uint32_t)(uintptr_t)&DAT_007284e8;
    uint32_t idx = *(int*)(in_ECX + 0x38);
    typedef void (__cdecl *Fn)(int);
    Fn fn = (Fn)vtbl[idx];
    fn(*(int*)(in_ECX + 0x34));
  }
  if ((param_1 == 0) || (param_2 == 0)) {
    *(uint32_t*)(in_ECX + 0x30) = 0;
    *(uint32_t*)(in_ECX + 0x34) = 0;
    *(uint32_t*)(in_ECX + 0x38) = 0;
    return;
  }
  *(int*)(in_ECX + 0x30) = param_2;
  *(int*)(in_ECX + 0x34) = param_1;
  *(uint32_t*)(in_ECX + 0x38) = param_3;
}

// 0x5780b0 — observed shape
void FUN_005780b0(void* self, uint8_t param_1) {
  void* in_ECX = self;
  FUN_00577d20(in_ECX);
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
}

// 0x578270 — observed shape
void FUN_00578270(void* self, int param_1) {
  int in_ECX = (int)(intptr_t)self;
  FUN_00538430(param_1);
  int* piVar1 = (int*)(in_ECX + 0xc);
  typedef void (__cdecl *FnA)(int*, int);
  int vtbl = *(int*)(param_1 + 0x160);
  FnA fn1 = (FnA)(*(int*)(vtbl + 0xc));
  fn1(piVar1, 4);
  if (*piVar1 != 0) {
    FnA fn2 = (FnA)(*(int*)(*(int*)(param_1 + 0x160) + 0xc));
    fn2((int*)(in_ECX + 0x14), 4);
    void** vtbl2 = (void**)(uint32_t)(uintptr_t)&DAT_00728650;
    uint32_t idx = *(int*)(in_ECX + 0x14);
    typedef void (__cdecl *FnB)(int, uint32_t, int);
    FnB fnB = (FnB)vtbl2[idx];
    fnB(param_1, *(uint32_t*)(in_ECX + 0x10), *piVar1);
  }
  piVar1 = (int*)(in_ECX + 0x18);
  FnA fn3 = (FnA)(*(int*)(*(int*)(param_1 + 0x160) + 0xc));
  fn3(piVar1, 4);
  if (*piVar1 != 0) {
    FnA fn4 = (FnA)(*(int*)(*(int*)(param_1 + 0x160) + 0xc));
    fn4((int*)(in_ECX + 0x20), 4);
    void** vtbl3 = (void**)(uint32_t)(uintptr_t)&DAT_00728650;
    uint32_t idx = *(int*)(in_ECX + 0x20);
    typedef void (__cdecl *FnB)(int, uint32_t, int);
    FnB fnB = (FnB)vtbl3[idx];
    fnB(param_1, *(uint32_t*)(in_ECX + 0x1c), *piVar1);
  }
  piVar1 = (int*)(in_ECX + 0x24);
  FnA fn5 = (FnA)(*(int*)(*(int*)(param_1 + 0x160) + 0xc));
  fn5(piVar1, 4);
  if (*piVar1 != 0) {
    FnA fn6 = (FnA)(*(int*)(*(int*)(param_1 + 0x160) + 0xc));
    fn6((int*)(in_ECX + 0x2c), 4);
    void** vtbl4 = (void**)(uint32_t)(uintptr_t)&DAT_00728650;
    uint32_t idx = *(int*)(in_ECX + 0x2c);
    typedef void (__cdecl *FnB)(int, uint32_t, int);
    FnB fnB = (FnB)vtbl4[idx];
    fnB(param_1, *(uint32_t*)(in_ECX + 0x28), *piVar1);
  }
  piVar1 = (int*)(in_ECX + 0x30);
  FnA fn7 = (FnA)(*(int*)(*(int*)(param_1 + 0x160) + 0xc));
  fn7(piVar1, 4);
  if (*piVar1 != 0) {
    FnA fn8 = (FnA)(*(int*)(*(int*)(param_1 + 0x160) + 0xc));
    fn8((int*)(in_ECX + 0x38), 4);
    void** vtbl5 = (void**)(uint32_t)(uintptr_t)&DAT_00728650;
    uint32_t idx = *(int*)(in_ECX + 0x38);
    typedef void (__cdecl *FnB)(int, uint32_t, int);
    FnB fnB = (FnB)vtbl5[idx];
    fnB(param_1, *(uint32_t*)(in_ECX + 0x34), *piVar1);
  }
}

// 0x5784c0 — observed shape
void FUN_005784c0(void* self, uint32_t param_1) {
  int in_ECX = (int)(intptr_t)self;
  FUN_00553060(param_1);
  uint32_t* puVar3 = (uint32_t*)FUN_00545600();
  uint32_t* puVar2 = *(uint32_t**)(in_ECX + 0x58);
  if (puVar2 != puVar3) {
    if (puVar2 != (uint32_t*)0x0) {
      int* piVar1 = (int*)(puVar2 + 1);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        typedef void (__cdecl *Fn)(int);
        Fn* fnptr = (Fn*)(*puVar2);
        (*fnptr)(1);
      }
    }
    *(uint32_t**)(in_ECX + 0x58) = puVar3;
    if (puVar3 != (uint32_t*)0x0) {
      puVar3[1] = puVar3[1] + 1;
    }
  }
}

// 0x578530 — observed shape
uint16_t FUN_00578530(void* self, int param_1) {
  int in_ECX = (int)(intptr_t)self;
  char cVar2 = FUN_00552bc0(param_1);
  if ((cVar2 != '\0') && (*(int16_t*)(in_ECX + 0x54) == *(int16_t*)(param_1 + 0x54))) {
    int* piVar1 = *(int**)(in_ECX + 0x58);
    if ((piVar1 == (int*)0x0) == (*(int*)(param_1 + 0x58) == 0)) {
      if ((piVar1 == (int*)0x0) ||
         (cVar2 = ((char(__cdecl *)(int))(*(int*)(*piVar1 + 0x1c)))(*(int*)(param_1 + 0x58)), cVar2 != '\0')) {
        return 1;
      }
      return 0;
    }
  }
  return 0;
}

// 0x578600 — observed shape
void FUN_00578600(void* self) {
  int in_ECX = (int)(intptr_t)self;
  int iVar2 = *(int*)(in_ECX + 0x58);
  *(uint32_t*)(in_ECX + 0x18) = 0x7f7fffff;
  *(uint32_t*)(in_ECX + 0x1c) = 0xff7fffff;
  if (iVar2 != 0) {
    float* pfVar1 = *(float**)(iVar2 + 0x10);
    int iVar3 = *(int*)(iVar2 + 0xc);
    if (pfVar1 != (float*)0x0) {
      if (*pfVar1 < 3.4028235e+38f) {
        *(float*)(in_ECX + 0x18) = *pfVar1;
      }
      iVar3 = (uint32_t)*(uint8_t*)(pfVar1 + 1) * (iVar3 + -1);
      if (-3.4028235e+38f < *(float*)((int)(intptr_t)pfVar1 + iVar3)) {
        *(float*)(in_ECX + 0x1c) = *(float*)((int)(intptr_t)pfVar1 + iVar3);
      }
    }
    if (iVar2 != 0) {
      pfVar1 = *(float**)(iVar2 + 0x1c);
      iVar3 = *(int*)(iVar2 + 0x18);
      if (pfVar1 != (float*)0x0) {
        if (*pfVar1 < *(float*)(in_ECX + 0x18)) {
          *(float*)(in_ECX + 0x18) = *pfVar1;
        }
        iVar3 = (uint32_t)*(uint8_t*)(pfVar1 + 1) * (iVar3 + -1);
        if (*(float*)(in_ECX + 0x1c) < *(float*)((int)(intptr_t)pfVar1 + iVar3)) {
          *(float*)(in_ECX + 0x1c) = *(float*)((int)(intptr_t)pfVar1 + iVar3);
        }
      }
      if (iVar2 != 0) {
        pfVar1 = *(float**)(iVar2 + 0x28);
        iVar3 = *(int*)(iVar2 + 0x24);
        if (pfVar1 != (float*)0x0) {
          if (*pfVar1 < *(float*)(in_ECX + 0x18)) {
            *(float*)(in_ECX + 0x18) = *pfVar1;
          }
          iVar3 = (uint32_t)*(uint8_t*)(pfVar1 + 1) * (iVar3 + -1);
          if (*(float*)(in_ECX + 0x1c) < *(float*)((int)(intptr_t)pfVar1 + iVar3)) {
            *(float*)(in_ECX + 0x1c) = *(float*)((int)(intptr_t)pfVar1 + iVar3);
          }
        }
        if (iVar2 != 0) {
          iVar3 = *(int*)(iVar2 + 0x30);
          pfVar1 = *(float**)(iVar2 + 0x34);
          if (pfVar1 != (float*)0x0) {
            if (*pfVar1 < *(float*)(in_ECX + 0x18)) {
              *(float*)(in_ECX + 0x18) = *pfVar1;
            }
            iVar2 = (uint32_t)*(uint8_t*)(pfVar1 + 1) * (iVar3 + -1);
            if (*(float*)(in_ECX + 0x1c) < *(float*)((int)(intptr_t)pfVar1 + iVar2)) {
              *(float*)(in_ECX + 0x1c) = *(float*)((int)(intptr_t)pfVar1 + iVar2);
            }
          }
        }
      }
    }
  }
}

// 0x578740 — observed shape
void FUN_00578740(void* self) {
  int in_ECX = (int)(intptr_t)self;
  if ((*(char*)(in_ECX + 0x5c) != '\0') &&
     (*(int*)(*(int*)(in_ECX + 0x34) + 0xbc)) &&
     (*(uint16_t*)(in_ECX + 0x54) < (*(uint8_t*)( *(int*)(*(int*)(in_ECX + 0x34) + 0xbc) + 0x30) & 0x3f))) {
    int iVar1 = *(int*)(*(int*)(in_ECX + 0x34) + 0xbc);
    int iVar2 = *(int*)(in_ECX + 0x58);
    float local_1c = 0.0f;
    if (iVar2 != 0) {
      if (*(int*)(iVar2 + 0x10) != 0) {
        local_1c = FUN_0056a5f0(*(uint32_t*)(in_ECX + 0x2c), *(int*)(iVar2 + 0x10), *(uint32_t*)(iVar2 + 0x14), *(uint32_t*)(iVar2 + 0xc), (void*)(in_ECX + 0x44));
      }
    }
    iVar2 = *(int*)(in_ECX + 0x58);
    float local_18 = 0.0f;
    if (iVar2 != 0) {
      if (*(int*)(iVar2 + 0x1c) != 0) {
        local_18 = FUN_0056a5f0(*(uint32_t*)(in_ECX + 0x2c), *(int*)(iVar2 + 0x1c), *(uint32_t*)(iVar2 + 0x20), *(uint32_t*)(iVar2 + 0x18), (void*)(in_ECX + 0x4c));
      }
    }
    iVar2 = *(int*)(in_ECX + 0x58);
    float local_14 = 1.0f;
    if (iVar2 != 0) {
      if (*(int*)(iVar2 + 0x28) != 0) {
        local_14 = FUN_0056a5f0(*(uint32_t*)(in_ECX + 0x2c), *(int*)(iVar2 + 0x28), *(uint32_t*)(iVar2 + 0x2c), *(uint32_t*)(iVar2 + 0x24), (void*)(in_ECX + 0x48));
      }
    }
    iVar2 = *(int*)(in_ECX + 0x58);
    float local_10 = 1.0f;
    if (iVar2 != 0) {
      if (*(int*)(iVar2 + 0x34) != 0) {
        local_10 = FUN_0056a5f0(*(uint32_t*)(in_ECX + 0x2c), *(int*)(iVar2 + 0x34), *(uint32_t*)(iVar2 + 0x38), *(uint32_t*)(iVar2 + 0x30), (void*)(in_ECX + 0x50));
      }
    }
    iVar2 = *(int*)(in_ECX + 0x58);
    float fVar5 = local_14 / *(float*)(iVar2 + 0x44);
    float fVar3 = *(float*)(iVar2 + 0x3c);
    float fVar4 = *(float*)(iVar2 + 0x40);
    float fVar6 = local_10 / *(float*)(iVar2 + 0x48);
    float* pfVar7 = (float*)FUN_005412c0(*(uint16_t*)(in_ECX + 0x54));
    if (*(uint16_t*)(iVar1 + 0xc) != 0) {
      uint32_t uVar8 = (uint32_t)*(uint16_t*)(iVar1 + 0xc);
      do {
        uVar8 = uVar8 - 1;
        *pfVar7 = fVar5 * *pfVar7 + ((1.0f - fVar5) * 0.5f - (local_1c - fVar3 * fVar5));
        pfVar7[1] = fVar6 * pfVar7[1] + (1.0f - fVar6) * 0.5f + (local_18 - fVar4 * fVar6);
        pfVar7 = pfVar7 + 2;
      } while (uVar8 != 0);
    }
    iVar2 = *(int*)(in_ECX + 0x58);
    *(float*)(iVar2 + 0x3c) = local_1c;
    *(float*)(iVar2 + 0x40) = local_18;
    *(float*)(iVar2 + 0x44) = local_14;
    *(float*)(iVar2 + 0x48) = local_10;
    *(uint8_t*)(iVar1 + 0x32) = *(uint8_t*)(iVar1 + 0x32) | 8;
    *(uint8_t*)(in_ECX + 0x5c) = 0;
  }
}

// 0x5789c0 — observed shape
void FUN_005789c0(void* self, uint8_t param_1) {
  uint32_t* in_ECX = (uint32_t*)self;
  in_ECX[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c4750;
  uint32_t* puVar2 = (uint32_t*)in_ECX[0x16];
  if (puVar2 != (uint32_t*)0x0) {
    int* piVar1 = (int*)(puVar2 + 1);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      typedef void (__cdecl *Fn)(int);
      Fn* fnptr = (Fn*)(*puVar2);
      (*fnptr)(1);
    }
    in_ECX[0x16] = 0;
  }
  puVar2 = (uint32_t*)in_ECX[0x16];
  if (puVar2 != (uint32_t*)0x0) {
    int* piVar1 = (int*)(puVar2 + 1);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      typedef void (__cdecl *Fn)(int);
      Fn* fnptr = (Fn*)(*puVar2);
      (*fnptr)(1);
    }
  }
  FUN_00552d20();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
}

// 0x578a20 — observed shape
void FUN_00578a20(void* self, int param_1, uint32_t param_2) {
  int in_ECX = (int)(intptr_t)self;
  FUN_00552aa0(param_1, param_2);
  *(uint32_t*)(param_1 + 0x44) = *(uint32_t*)(in_ECX + 0x44);
  *(uint32_t*)(param_1 + 0x4c) = *(uint32_t*)(in_ECX + 0x4c);
  *(uint32_t*)(param_1 + 0x48) = *(uint32_t*)(in_ECX + 0x48);
  *(uint32_t*)(param_1 + 0x50) = *(uint32_t*)(in_ECX + 0x50);
  *(uint16_t*)(param_1 + 0x54) = *(uint16_t*)(in_ECX + 0x54);
  uint32_t* puVar2 = *(uint32_t**)(in_ECX + 0x58);
  if (puVar2 != (uint32_t*)0x0) {
    uint32_t* puVar3 = *(uint32_t**)(param_1 + 0x58);
    if (puVar3 != puVar2) {
      if (puVar3 != (uint32_t*)0x0) {
        int* piVar1 = (int*)(puVar3 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          typedef void (__cdecl *Fn)(int);
          Fn* fnptr = (Fn*)(*puVar3);
          (*fnptr)(1);
        }
      }
      *(uint32_t**)(param_1 + 0x58) = puVar2;
      if (puVar2 != (uint32_t*)0x0) {
        puVar2[1] = puVar2[1] + 1;
      }
    }
    *(uint32_t*)(param_1 + 0x44) = 0;
    *(uint32_t*)(param_1 + 0x4c) = 0;
    *(uint32_t*)(param_1 + 0x48) = 0;
    *(uint32_t*)(param_1 + 0x50) = 0;
    FUN_00578600((void*)param_1);
  }
}

// 0x578aa0 — observed shape
void FUN_00578aa0(int param_1) {
  int iVar2 = param_1;
  FUN_005531c0(param_1);
  param_1 = (int)FUN_00557b10((uint32_t)(uintptr_t)&DAT_007289c8);
  uint32_t uVar1 = *(uint32_t*)(iVar2 + 0xc);
  if (*(uint32_t*)(iVar2 + 8) <= uVar1) {
    FUN_006b34a0(*(int*)(iVar2 + 0x14) + uVar1);
  }
  FUN_005606f0(uVar1, (void*)&param_1);
}

// 0x578af0 — observed shape
uint32_t* FUN_00578af0(uint32_t param_1) {
  uint32_t* puVar1 = (uint32_t*)FUN_00533c78(0x60);
  if (puVar1 == (uint32_t*)0x0) {
    FUN_00578a20((void*)0, 0, param_1);
    return (uint32_t*)0x0;
  }
  FUN_00552c80();
  *puVar1 = (uint32_t)(uintptr_t)&PTR_FUN_006c4750;
  puVar1[0x16] = 0;
  *(uint16_t*)(puVar1 + 0x15) = 0;
  puVar1[0x11] = 0;
  puVar1[0x13] = 0;
  puVar1[0x12] = 0;
  puVar1[0x14] = 0;
  *(uint8_t*)(puVar1 + 0x17) = 0;
  FUN_00578a20(puVar1, (int)(intptr_t)puVar1, param_1);
  return puVar1;
}

// 0x578b70 — observed shape
uint32_t FUN_00578b70(float* self, float* param_1) {
  float* in_ECX = self;
  if (*in_ECX == *param_1) {
    uint8_t* pbVar2 = (uint8_t*)in_ECX[1];
    uint8_t* pbVar4 = (uint8_t*)param_1[1];
    uint32_t iVar3 = 0;
    bool bVar5 = false;
    uint8_t bVar1 = 0;
    bool need = false;
    do {
      bVar1 = *pbVar2;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
        iVar3 = (1 - (uint32_t)bVar5) - (uint32_t)(bVar5 != 0);
        need = true;
        break;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) {
        iVar3 = (1 - (uint32_t)bVar5) - (uint32_t)(bVar5 != 0);
        need = true;
        break;
      }
      pbVar2 = pbVar2 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    if (need && iVar3 == 0) return 0;
    if (!need || iVar3 != 0) return 1;
  }
  return 1;
}

// 0x578c70 — observed shape
uint32_t FUN_00578c70(void* self, int param_1) {
  int in_ECX = (int)(intptr_t)self;
  if (param_1 != 0) {
    char cVar2 = FUN_00538460(param_1);
    if (cVar2 != '\0') {
      uint32_t uVar1 = *(uint32_t*)(in_ECX + 0x10);
      if (uVar1 != *(uint32_t*)(param_1 + 0x10)) return 0;
      uint32_t uVar5 = 0;
      if (uVar1 != 0) {
        int iVar4 = *(int*)(in_ECX + 0x14);
        int iVar3 = *(int*)(param_1 + 0x14) - iVar4;
        do {
          uint32_t r = FUN_00578b70((float*)(iVar4 + iVar3), (float*)0);
          if (r != 0) return 0;
          uVar5 = uVar5 + 1;
          iVar4 = iVar4 + 8;
        } while (uVar5 < uVar1);
      }
      return 1;
    }
  }
  return 0;
}

// 0x578ce0 — observed shape
void FUN_00578ce0(void* self, int param_1, uint32_t param_2) {
  int* in_ECX = (int*)self;
  FUN_00547db0(param_1, param_2);
  *(int*)(param_1 + 0x10) = in_ECX[4];
  int* piVar4 = (int*)0x0;
  if (in_ECX[4] != 0) {
    uint32_t* puVar2 = (uint32_t*)((uint32_t(__cdecl *)())(*(uint32_t*)*in_ECX + 4))();
    if (puVar2 == (uint32_t*)(uintptr_t)&DAT_007289d0) {
      int iVar1 = in_ECX[4];
      int* piVar3 = (int*)FUN_00533c78(iVar1 * 8 + 4);
      if (piVar3 != (int*)0x0) {
        piVar4 = piVar3 + 1;
        *piVar3 = iVar1;
        FUN_004127b0(piVar4, 8, iVar1, (const void*)0x578b60);
      }
      *(int**)(param_1 + 0x14) = piVar4;
      uint32_t uVar5 = 0;
      if (in_ECX[4] != 0) {
        do {
          int iVar1b = uVar5 * 8;
          *(uint32_t*)(iVar1b + *(int*)(param_1 + 0x14)) = *(uint32_t*)(iVar1b + in_ECX[5]);
          FUN_005828d0(*(uint32_t*)(iVar1b + 4 + in_ECX[5]));
          uVar5 = uVar5 + 1;
        } while (uVar5 < (uint32_t)in_ECX[4]);
      }
      return;
    }
  }
  *(uint32_t*)(param_1 + 0x14) = 0;
}

// 0x578e80 — observed shape
void FUN_00578e80(uint32_t param_1) {
  int iVar3 = param_1;
  FUN_00548050(param_1);
  param_1 = (int)FUN_00557b10((uint32_t)(uintptr_t)&DAT_007289d0);
  uint32_t uVar2 = *(uint32_t*)(iVar3 + 0xc);
  if (*(uint32_t*)(iVar3 + 8) <= uVar2) {
    FUN_006b34a0(*(int*)(iVar3 + 0x14) + uVar2);
  }
  FUN_005606f0(uVar2, (void*)&param_1);
  param_1 = (int)FUN_00557cb0("m_uiNumKeys", *(uint32_t*)(iVar3 + 0x10));
  uVar2 = *(uint32_t*)(iVar3 + 0xc);
  if (*(uint32_t*)(iVar3 + 8) <= uVar2) {
    FUN_006b34a0(*(int*)(iVar3 + 0x14) + uVar2);
  }
  FUN_005606f0(uVar2, (void*)&param_1);
  param_1 = 0;
  if (*(int*)(iVar3 + 0x10) != 0) {
    do {
      uint32_t uVar2b = param_1;
      char* pcVar4 = (char*)FUN_00557cf0(&DAT_006c4804, *(uint32_t*)(*(int*)(iVar3 + 0x14) + param_1 * 8));
      char* pcVar5 = (char*)FUN_00557d80(&DAT_006c47fc, *(uint32_t*)(*(int*)(iVar3 + 0x14) + 4 + uVar2b * 8));
      char* pcVar6 = pcVar4;
      char cVar1 = 0;
      do { cVar1 = *pcVar6; pcVar6 = pcVar6 + 1; } while (cVar1 != '\0');
      char* pcVar7 = pcVar5;
      do { cVar1 = *pcVar7; pcVar7 = pcVar7 + 1; } while (cVar1 != '\0');
      pcVar6 = (char*)FUN_00533c78(pcVar6 + (int)(pcVar7 + ((4 - (int)(intptr_t)(pcVar5 + 1)) - (int)(intptr_t)(pcVar4 + 1))));
      sprintf(pcVar6, "%s : %s", pcVar4, pcVar5);
      int iVar8 = (int)FUN_00557d80("TextKey", (uint32_t)(intptr_t)pcVar6);
      uVar2 = *(uint32_t*)(iVar3 + 0xc);
      if ((uVar2 < *(uint32_t*)(iVar3 + 8)) || (FUN_006b34a0(*(int*)(iVar3 + 0x14) + uVar2), uVar2 < *(uint32_t*)(iVar3 + 8))) {
        if (uVar2 < *(uint32_t*)(iVar3 + 0xc)) {
          if (iVar8 == 0) {
            if (*(int*)(*(int*)(iVar3 + 4) + uVar2 * 4) != 0) {
              int iVar9 = *(int*)(iVar3 + 0x10) + -1;
              *(int*)(iVar3 + 0x10) = iVar9;
            }
          } else if (*(int*)(*(int*)(iVar3 + 4) + uVar2 * 4) == 0) {
            int iVar9 = *(int*)(iVar3 + 0x10) + 1;
            *(int*)(iVar3 + 0x10) = iVar9;
          }
        } else {
          *(uint32_t*)(iVar3 + 0xc) = uVar2 + 1;
          if (iVar8 != 0) {
            int iVar9 = *(int*)(iVar3 + 0x10) + 1;
            *(int*)(iVar3 + 0x10) = iVar9;
          }
        }
        *(int*)(*(int*)(iVar3 + 4) + uVar2 * 4) = iVar8;
      }
      operator_delete__(pcVar4);
      operator_delete__(pcVar5);
      operator_delete__(pcVar6);
      param_1 = param_1 + 1;
    } while (param_1 < *(uint32_t*)(iVar3 + 0x10));
  }
}

// 0x579050 — observed shape
void FUN_00579050(void* self, uint8_t param_1) {
  void* in_ECX = self;
  FUN_00579070();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
}
