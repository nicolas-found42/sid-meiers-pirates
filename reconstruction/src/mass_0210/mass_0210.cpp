// Reconstruction batch mass_0210
// Sid Meier's Pirates! (2004), PE32 i386
// Image: 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
#include <cstdint>
#include <cstddef>
#include <windows.h>

extern char FUN_005bd960(uint32_t param_1, void** out_link);
extern void FUN_005c9cd0(uint32_t param_2, uint32_t param_3);
extern void FUN_004b1100();
extern void FUN_004b10d0();
extern void* DAT_00727868;
extern void FUN_00547790();
extern void FUN_005bd9b0();
extern void FUN_00547890();
extern void FUN_005bfa50(int param_1);
extern uint32_t FUN_005dbd60(int param_1);
extern void FUN_0057ede0(uint32_t param_1, int param_2);
extern char FUN_005e19a0(uint32_t param_1, void** out_link);

// 0x5be280 — observed shape
uint32_t FUN_005be280(uint32_t param_1, uint32_t param_2, uint32_t param_3)
{
  int local_4 = 0;
  void* link = nullptr;
  char cVar1 = FUN_005bd960(param_1, &link);
  // Preserve observed local write-back shape: local_4 is the out slot.
  local_4 = (int)(intptr_t)link;
  if ((cVar1 == '\0') || (local_4 == 0)) {
    return 0;
  }
  FUN_005c9cd0(param_2, param_3);
  return 1;
}

// 0x5be310 — observed shape
void FUN_005be310(uint32_t* param_1)
{
  uint32_t* puVar2 = (uint32_t*)param_1[2];
  if (puVar2 != (uint32_t*)0x0) {
    int* piVar1 = (int*)puVar2 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      auto fn = (void (__cdecl *)(int))*(void**)puVar2;
      fn(1);
    }
    param_1[2] = 0;
  }
  FUN_004b1100();
  param_1[1] = 0;
  *(uint32_t**)param_1 = (uint32_t*)DAT_00727868;
  DAT_00727868 = param_1;
  FUN_004b10d0();
}

// 0x5be360 — observed shape
void FUN_005be360(void* self)
{
  uint32_t* in_ECX = (uint32_t*)self;
  int* piVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  uint32_t uVar5;
  int* piVar6;
  int iVar7;
  uint32_t* puVar8;
  uint32_t* puStack_8 = nullptr;
  uint32_t* local_4;

  in_ECX[0] = 0x6c70d0; // &PTR_FUN_006c70d0 vtable pointer
  local_4 = in_ECX;
  FUN_00547790();
  if ((uint32_t*)in_ECX[6] != (uint32_t*)0x0) {
    auto fn = (void (__cdecl *)(int))**(void***)in_ECX[6];
    fn(1);
  }
  if ((uint32_t*)in_ECX[8] != (uint32_t*)0x0) {
    auto fn = (void (__cdecl *)(int))**(void***)in_ECX[8];
    fn(1);
  }
  uVar5 = 0;
  if (in_ECX[10] != 0) {
    piVar6 = (int*)in_ECX[0xb];
    do {
      if (*piVar6 != 0) {
        piVar6 = (int*)((int*)in_ECX[0xb])[uVar5];
        goto LAB_005be3b6;
      }
      uVar5 = uVar5 + 1;
      piVar6 = piVar6 + 1;
    } while (uVar5 < in_ECX[10]);
  }
  piVar6 = (int*)0x0;
LAB_005be3b6:
  if (piVar6 != (int*)0x0) {
    do {
      iVar2 = piVar6[1];
      iVar3 = piVar6[2];
      piVar6 = (int*)*piVar6;
      if (piVar6 == (int*)0x0) {
        auto getIndex = (int (__cdecl *))(in_ECX[9] + 4);
        // in_ECX[9] is a function pointer table base; call entry at +4
        iVar7 = ((int (__cdecl *)(int))*(void**)((char*)in_ECX[9] + 4))(iVar2);
        uVar5 = (uint32_t)iVar7 + 1;
        if (uVar5 < in_ECX[10]) {
          puVar8 = (uint32_t*)(in_ECX[0xb] + uVar5 * 4);
          do {
            piVar6 = (int*)*puVar8;
            if (piVar6 != (int*)0x0) goto LAB_005be3f2;
            uVar5 = uVar5 + 1;
            puVar8 = puVar8 + 1;
          } while (uVar5 < in_ECX[10]);
        }
        piVar6 = (int*)0x0;
      }
LAB_005be3f2:
      if (iVar3 != 0) {
        cVar4 = FUN_005bd960((uint32_t)iVar2, (void**)&puStack_8);
        puVar8 = puStack_8;
        if ((cVar4 != '\0') && (puStack_8 != (uint32_t*)0x0)) {
          if (puStack_8[1] == 1) {
            FUN_005bfa50(iVar2);
          }
          piVar1 = (int*)puVar8 + 1;
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            auto fn = (void (__cdecl *)(int))*(void**)puVar8;
            fn(1);
          }
        }
      }
    } while (piVar6 != (int*)0x0);
    in_ECX = local_4;
  }
  in_ECX[5] = 0;
  FUN_005bd9b0();
  FUN_00547890();
}

// 0x5be470 — observed shape
void FUN_005be470(int param_1)
{
  uint32_t uVar1;
  if (param_1 != 0) {
    *(int*)(param_1 + 4) = *(int*)(param_1 + 4) + 1;
    uVar1 = FUN_005dbd60(param_1);
    FUN_0057ede0(uVar1, param_1);
  }
}

// 0x5be4a0 — observed shape
uint32_t* FUN_005be4a0(uint32_t param_1)
{
  int* piVar1;
  uint32_t* puVar2;
  char cVar3;
  uint32_t* local_4 = (uint32_t*)0x0;

  cVar3 = FUN_005e19a0(param_1, (void**)&local_4);
  puVar2 = local_4;
  if (cVar3 == '\0') {
    if (local_4 != (uint32_t*)0x0) {
      piVar1 = (int*)local_4 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        auto fn = (void (__cdecl *)(int))*(void**)local_4;
        fn(1);
      }
    }
    return (uint32_t*)0x0;
  }
  if (local_4 != (uint32_t*)0x0) {
    piVar1 = (int*)local_4 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      auto fn = (void (__cdecl *)(int))*(void**)local_4;
      fn(1);
    }
  }
  return puVar2;
}

extern void FUN_005e1a10(int* param_1, void* param_2, void** out_link);
extern void FUN_005bde00();
extern void FUN_00547860();
extern uint32_t* FUN_00533c78(uint32_t size);
extern HMODULE FUN_005dbe20();
extern void FUN_005e1490();

// 0x5be570 — observed shape
uint32_t* FUN_005be570(void* self)
{
  uint32_t* puVar1;
  uint32_t uVar2;
  int iVar3;
  int* piVar4;
  uint32_t* local_8;
  uint8_t local_4[4];

  iVar3 = *(int*)((char*)self + 0x20);
  uVar2 = 0;
  if (iVar3 != 0) {
    if (*(uint32_t*)(iVar3 + 4) != 0) {
      piVar4 = *(int**)(iVar3 + 8);
      do {
        if (*piVar4 != 0) {
          iVar3 = (*(int**)(iVar3 + 8))[uVar2];
          goto LAB_005be59f;
        }
        uVar2 = uVar2 + 1;
        piVar4 = piVar4 + 1;
      } while (uVar2 < *(uint32_t*)(iVar3 + 4));
    }
    iVar3 = 0;
LAB_005be59f:
    *(int*)((char*)self + 0x1c) = iVar3;
    if (iVar3 != 0) {
      local_8 = (uint32_t*)0x0;
      FUN_005e1a10((int*)((char*)self + 0x1c), local_4, (void**)&local_8);
      puVar1 = local_8;
      if (local_8 != (uint32_t*)0x0) {
        piVar4 = (int*)local_8 + 1;
        *piVar4 = *piVar4 + -1;
        if (*piVar4 == 0) {
          auto fn = (void (__cdecl *)(int))*(void**)local_8;
          fn(1);
        }
      }
      return puVar1;
    }
  }
  return (uint32_t*)0x0;
}

// 0x5be650 — observed shape
void FUN_005be650(uint8_t param_1, void* self)
{
  FUN_005bde00();
  if ((param_1 & 1) != 0) {
    operator delete(self);
  }
}

// 0x5be670 — observed shape
void FUN_005be670(void* self)
{
  uint32_t* puVar1;
  uint32_t* puVar2;
  uint32_t* in_ECX = (uint32_t*)self;
  uint32_t uVar3;
  int iVar4;

  FUN_00547860();
  in_ECX[0] = 0x6c70d0; // &PTR_FUN_006c70d0
  in_ECX[5] = 0;
  in_ECX[9] = 0x6c6fdc; // &PTR_FUN_006c6fdc
  in_ECX[10] = 0x25;
  in_ECX[0xc] = 0;
  puVar1 = FUN_00533c78(0x94);
  in_ECX[0xb] = (uint32_t)(intptr_t)puVar1;
  for (uVar3 = in_ECX[10] & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(uint8_t*)puVar1 = 0;
    puVar1 = (uint32_t*)((int)(intptr_t)puVar1 + 1);
  }
  *(uint8_t*)((char*)in_ECX + 0xd) = 1;
  in_ECX[9] = 0x6c713c; // &PTR_FUN_006c713c
  puVar1 = FUN_00533c78(0x14);
  if (puVar1 == (uint32_t*)0x0) {
    puVar1 = (uint32_t*)0x0;
  } else {
    puVar1[0] = 0x6c6ff8; // &PTR_FUN_006c6ff8
    puVar1[1] = 0x3b;
    puVar1[3] = 0;
    puVar2 = FUN_00533c78(0xec);
    puVar1[2] = (uint32_t)(intptr_t)puVar2;
    for (uVar3 = puVar1[1] & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(uint8_t*)puVar2 = 0;
      puVar2 = (uint32_t*)((int)(intptr_t)puVar2 + 1);
    }
    *(uint8_t*)((char*)puVar1 + 4) = 1;
    puVar1[0] = 0x6c7158; // &PTR_FUN_006c7158
  }
  in_ECX[6] = (uint32_t)(intptr_t)puVar1;
  puVar1 = FUN_00533c78(0x14);
  if (puVar1 == (uint32_t*)0x0) {
    in_ECX[8] = 0;
    return;
  }
  puVar1[0] = 0x6c7014; // &PTR_FUN_006c7014
  puVar1[1] = 0x25;
  puVar1[3] = 0;
  puVar2 = FUN_00533c78(0x94);
  puVar1[2] = (uint32_t)(intptr_t)puVar2;
  for (uVar3 = puVar1[1] & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(uint8_t*)puVar2 = 0;
    puVar2 = (uint32_t*)((int)(intptr_t)puVar2 + 1);
  }
  *(uint8_t*)((char*)puVar1 + 4) = 0;
  puVar1[0] = 0x6c7174; // &PTR_FUN_006c7174
  in_ECX[8] = (uint32_t)(intptr_t)puVar1;
}

// 0x5be790 — observed shape
void FUN_005be790(uint8_t param_1, void* self)
{
  FUN_005be360(self);
  if ((param_1 & 1) != 0) {
    operator delete(self);
  }
}

// 0x5be7b0 — observed shape
void FUN_005be7b0(void* self)
{
  int* piVar1;
  uint32_t* puVar2;
  HMODULE hLibModule;
  uint32_t uVar3;
  uint32_t* local_8;
  uint8_t local_4[4];

  puVar2 = FUN_005be570(self);
  while (puVar2 != (uint32_t*)0x0) {
    hLibModule = FUN_005dbe20();
    uVar3 = FUN_005dbd60(0);
    FUN_005bfa50((int)uVar3);
    if (hLibModule != (HMODULE)0x0) {
      FreeLibrary(hLibModule);
    }
    if ((*(int*)((char*)self + 0x20) == 0) || (*(int*)((char*)self + 0x1c) == 0)) break;
    local_8 = (uint32_t*)0x0;
    FUN_005e1a10((int*)((char*)self + 0x1c), local_4, (void**)&local_8);
    puVar2 = local_8;
    if (local_8 == (uint32_t*)0x0) break;
    piVar1 = (int*)local_8 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      auto fn = (void (__cdecl *)(int))*(void**)local_8;
      fn(1);
    }
  }
  FUN_005e1490();
}

extern void* DAT_00728cf4;
extern void* DAT_00727864;
extern void FUN_00497420(const char* msg);
extern uint32_t DAT_00717c64;
extern uint32_t DAT_00717c68;
extern void operator_delete__(void* p);

// 0x5be840 — observed shape
void FUN_005be840()
{
  int iVar1;
  if (DAT_00728cf4 == nullptr) {
    iVar1 = (int)(intptr_t)FUN_00533c78(0x38);
    if (iVar1 == 0) {
      DAT_00727864 = nullptr;
    } else {
      FUN_005be670((void*)(intptr_t)iVar1);
      DAT_00727864 = (void*)(intptr_t)iVar1;
    }
    DAT_00728cf4 = DAT_00727864;
  }
  if (DAT_00727864 == nullptr) {
    FUN_00497420("Failed to create shader factory!");
  }
}

// 0x5be8c0 — observed shape
uint32_t FUN_005be8c0(void* self, int param_1, int param_2)
{
  uint32_t uVar1 = *(uint32_t*)((char*)self + 0x14);
  if ((uint32_t)(param_1 + (int)uVar1) <= DAT_00717c64) {
    if ((uint32_t)(*(int*)((char*)self + 0x1c) + param_2) <= DAT_00717c68) {
      uint32_t hi = (uint32_t)(uVar1 + (uint32_t)param_2 >> 8) & 0xffffff;
      uint32_t lo = (uint32_t)(1 - (DAT_00717c68 < uVar1 + (uint32_t)param_2 ? 1 : 0));
      return (hi << 8) | lo;
    }
  }
  return uVar1 & 0xffffff00;
}

// 0x5be930 — observed shape
void FUN_005be930(uint8_t param_1, void* self)
{
  FUN_005be950(self);
  if ((param_1 & 1) != 0) {
    operator delete(self);
  }
}

// 0x5be950 — observed shape
void FUN_005be950(void* self)
{
  uint32_t* puVar1 = *(uint32_t**)self;
  if (puVar1 != (uint32_t*)0x0) {
    if (puVar1[-1] == 0) {
      operator_delete__((void*)(puVar1 + -1));
    } else {
      auto fn = (void (__cdecl *)(int))*(void**)puVar1;
      fn(3);
    }
  }
  void* pvVar2 = (void*)((int*)self)[2];
  if (pvVar2 != (void*)0x0) {
    FUN_005be950(pvVar2);
    operator delete(pvVar2);
  }
}

// 0x5be990 — observed shape
void FUN_005be990(void* self, char* param_1)
{
  char cVar1;
  char* pcVar2;
  int iVar3;
  char* pcVar4;
  bool bVar5;

  operator_delete__(*(void**)((char*)self + 0x40));
  *(uint32_t*)((char*)self + 0x40) = 0;
  if (param_1 != (char*)0x0) {
    iVar3 = 1;
    bVar5 = true;
    pcVar2 = param_1;
    pcVar4 = "";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar5 = *pcVar2 == *pcVar4;
      pcVar2 = pcVar2 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (!bVar5) {
      pcVar2 = param_1;
      do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      pcVar2 = (char*)FUN_00533c78((uint32_t)(pcVar2 + (1 - (int)(intptr_t)(param_1 + 1))));
      *(char**)((char*)self + 0x40) = pcVar2;
      do {
        cVar1 = *param_1;
        param_1 = param_1 + 1;
        *pcVar2 = cVar1;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
    }
  }
}

// 0x5bea00 — observed shape
void FUN_005bea00(void* self, char* param_1)
{
  char cVar1;
  char* pcVar2;
  int iVar3;
  char* pcVar4;
  bool bVar5;

  operator_delete__(*(void**)((char*)self + 0x44));
  *(uint32_t*)((char*)self + 0x44) = 0;
  if (param_1 != (char*)0x0) {
    iVar3 = 1;
    bVar5 = true;
    pcVar2 = param_1;
    pcVar4 = "";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar5 = *pcVar2 == *pcVar4;
      pcVar2 = pcVar2 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (!bVar5) {
      pcVar2 = param_1;
      do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      pcVar2 = (char*)FUN_00533c78((uint32_t)(pcVar2 + (1 - (int)(intptr_t)(param_1 + 1))));
      *(char**)((char*)self + 0x44) = pcVar2;
      do {
        cVar1 = *param_1;
        param_1 = param_1 + 1;
        *pcVar2 = cVar1;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
    }
  }
}

// 0x5bea70 — observed shape
void FUN_005bea70(void* self, char* param_1)
{
  char cVar1;
  char* pcVar2;
  int iVar3;
  char* pcVar4;
  bool bVar5;

  operator_delete__(*(void**)((char*)self + 0x48));
  *(uint32_t*)((char*)self + 0x48) = 0;
  if (param_1 != (char*)0x0) {
    iVar3 = 1;
    bVar5 = true;
    pcVar2 = param_1;
    pcVar4 = "";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar5 = *pcVar2 == *pcVar4;
      pcVar2 = pcVar2 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (!bVar5) {
      pcVar2 = param_1;
      do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      pcVar2 = (char*)FUN_00533c78((uint32_t)(pcVar2 + (1 - (int)(intptr_t)(param_1 + 1))));
      *(char**)((char*)self + 0x48) = pcVar2;
      do {
        cVar1 = *param_1;
        param_1 = param_1 + 1;
        *pcVar2 = cVar1;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
    }
  }
}

// 0x5beae0 — observed shape
void FUN_005beae0(void* self, char* param_1)
{
  char cVar1;
  char* pcVar2;
  int iVar3;
  char* pcVar4;
  bool bVar5;

  operator_delete__(*(void**)((char*)self + 0x54));
  *(uint32_t*)((char*)self + 0x54) = 0;
  if (param_1 != (char*)0x0) {
    iVar3 = 1;
    bVar5 = true;
    pcVar2 = param_1;
    pcVar4 = "";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar5 = *pcVar2 == *pcVar4;
      pcVar2 = pcVar2 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (!bVar5) {
      pcVar2 = param_1;
      do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      pcVar2 = (char*)FUN_00533c78((uint32_t)(pcVar2 + (1 - (int)(intptr_t)(param_1 + 1))));
      *(char**)((char*)self + 0x54) = pcVar2;
      do {
        cVar1 = *param_1;
        param_1 = param_1 + 1;
        *pcVar2 = cVar1;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
    }
  }
}

// 0x5beb50 — observed shape
void FUN_005beb50(void* self, char* param_1)
{
  char cVar1;
  char* pcVar2;
  int iVar3;
  char* pcVar4;
  bool bVar5;

  operator_delete__(*(void**)((char*)self + 0x58));
  *(uint32_t*)((char*)self + 0x58) = 0;
  if (param_1 != (char*)0x0) {
    iVar3 = 1;
    bVar5 = true;
    pcVar2 = param_1;
    pcVar4 = "";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar5 = *pcVar2 == *pcVar4;
      pcVar2 = pcVar2 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (!bVar5) {
      pcVar2 = param_1;
      do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      pcVar2 = (char*)FUN_00533c78((uint32_t)(pcVar2 + (1 - (int)(intptr_t)(param_1 + 1))));
      *(char**)((char*)self + 0x58) = pcVar2;
      do {
        cVar1 = *param_1;
        param_1 = param_1 + 1;
        *pcVar2 = cVar1;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
    }
  }
}

// 0x5bebc0 — observed shape
void FUN_005bebc0(void* self, char* param_1)
{
  char cVar1;
  char* pcVar2;
  int iVar3;
  char* pcVar4;
  bool bVar5;

  operator_delete__(*(void**)((char*)self + 0x5c));
  *(uint32_t*)((char*)self + 0x5c) = 0;
  if (param_1 != (char*)0x0) {
    iVar3 = 1;
    bVar5 = true;
    pcVar2 = param_1;
    pcVar4 = "";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar5 = *pcVar2 == *pcVar4;
      pcVar2 = pcVar2 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (!bVar5) {
      pcVar2 = param_1;
      do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      pcVar2 = (char*)FUN_00533c78((uint32_t)(pcVar2 + (1 - (int)(intptr_t)(param_1 + 1))));
      *(char**)((char*)self + 0x5c) = pcVar2;
      do {
        cVar1 = *param_1;
        param_1 = param_1 + 1;
        *pcVar2 = cVar1;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
    }
  }
}
