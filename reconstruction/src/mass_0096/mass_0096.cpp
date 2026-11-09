#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_00515c30(void);
extern void FUN_004faab0(void);
extern void FUN_004fac10(void);
extern char FUN_005179b0(void* self);
extern char FUN_00517b80(void* self);
extern void FUN_005163c0(void);
extern void FUN_00515cb0(void* self);
extern int FUN_00517710(void* self, int p2, int p3);
extern void FUN_005129a0(uint32_t v);
extern void FUN_00517f90(void);
extern void FUN_004e6420(void);
extern void FUN_005edba0(void);
extern char FUN_00516e10(char* p1, int p2);
extern uint32_t FUN_00515640(const char* fmt, ...);

extern HANDLE DAT_0072705c;
extern DWORD DAT_00726c28;

// 0x516c70 — observed shape
void FUN_00516c70(void* self) {
  int64_t base = (int64_t)(intptr_t)self;
  HANDLE pvVar1;
  char cVar2;
  LPVOID pvVar3;
  DWORD DVar4;
  HANDLE local_8;
  HANDLE local_4;

  FUN_00515c30();
  cVar2 = *(char*)(base + 0x1c);
  pvVar1 = DAT_0072705c;
  do {
    if (cVar2 != '\0') {
      DAT_0072705c = pvVar1;
      return;
    }
    DAT_0072705c = pvVar1;
    if ((DAT_00726c28 == 0xffffffff) || ((pvVar3 = TlsGetValue(DAT_00726c28), pvVar3 == (LPVOID)0x0))) {
      DVar4 = WaitForSingleObject(pvVar1, 0);
    } else {
      local_8 = *(HANDLE*)((int64_t)(intptr_t)pvVar3 + 0x20);
      local_4 = pvVar1;
      int tls_state_14 = *(int*)((int64_t)(intptr_t)pvVar3 + 0x14);
      if ((tls_state_14 == 0) || (tls_state_14 == 3)) {
        DVar4 = WaitForSingleObject(pvVar1, 0);
      } else {
        DVar4 = WaitForMultipleObjects(2, &local_8, 0, 0);
        if (DVar4 == 0) {
          DVar4 = GetCurrentThreadId();
          if (*(DWORD*)((int64_t)(intptr_t)pvVar3 + 0x30) == DVar4) {
            *(uint32_t*)((int64_t)(intptr_t)pvVar3 + 0x14) = 3;
            FUN_004faab0();
          }
          DVar4 = 0;
        } else if (DVar4 == 1) {
          DVar4 = 0;
        }
      }
    }
    if (DVar4 == 0) {
      if (*(char*)(base + 0xcd) != '\0') {
        pvVar1 = *(HANDLE*)(base + 200);
        if ((DAT_00726c28 == 0xffffffff) || ((pvVar3 = TlsGetValue(DAT_00726c28), pvVar3 == (LPVOID)0x0))) {
          WaitForSingleObject(pvVar1, 0xffffffff);
        } else {
          FUN_004fac10();
        }
        *(uint8_t*)(base + 0xcc) = 1;
      }
      FUN_005163c0();
      do {
        cVar2 = FUN_005179b0(self);
      } while (cVar2 != '\0');
      do {
        cVar2 = FUN_00517b80(self);
      } while (cVar2 != '\0');
      if (*(char*)(base + 0xcc) != '\0') {
        ReleaseMutex(*(HANDLE*)(base + 200));
        *(uint8_t*)(base + 0xcc) = 0;
        *(uint8_t*)(base + 0xcd) = 0;
      }
      ReleaseMutex(DAT_0072705c);
    }
    if (*(char*)(base + 0xcd) == '\0') {
      if (((DAT_00726c28 == 0xffffffff) || ((pvVar3 = TlsGetValue(DAT_00726c28), pvVar3 == (LPVOID)0x0))
          || (*(int*)((int64_t)(intptr_t)pvVar3 + 0x14) == 0))
          || (*(int*)((int64_t)(intptr_t)pvVar3 + 0x14) == 3)) {
        SleepEx(100, 0);
      } else {
        DVar4 = WaitForSingleObject(*(HANDLE*)((int64_t)(intptr_t)pvVar3 + 0x20), 100);
        if ((DVar4 == 0) && ((DVar4 = GetCurrentThreadId(), *(DWORD*)((int64_t)(intptr_t)pvVar3 + 0x30) == DVar4))) {
          *(uint32_t*)((int64_t)(intptr_t)pvVar3 + 0x14) = 3;
          FUN_004faab0();
        }
      }
    }
    cVar2 = *(char*)(base + 0x1c);
    pvVar1 = DAT_0072705c;
  } while (true);
}

// 0x516e10 — observed shape
void FUN_00516e10(char* self, int param_2) {
  int64_t param_1 = (int64_t)(intptr_t)self;
  HANDLE pvVar1;
  uint32_t* puVar2;
  int32_t* piVar3;
  LPVOID pvVar4;
  DWORD DVar5;
  int iVar6;
  HANDLE local_8;
  HANDLE local_4;

  *(uint8_t*)(param_1 + 0xcd) = 1;
  do {
    pvVar1 = DAT_0072705c;
    if ((DAT_00726c28 == 0xffffffff) || ((pvVar4 = TlsGetValue(DAT_00726c28), pvVar4 == (LPVOID)0x0))) {
      DVar5 = WaitForSingleObject(pvVar1, 0);
    } else {
      local_8 = *(HANDLE*)((int64_t)(intptr_t)pvVar4 + 0x20);
      local_4 = pvVar1;
      int tls_state_14 = *(int*)((int64_t)(intptr_t)pvVar4 + 0x14);
      if ((tls_state_14 == 0) || (tls_state_14 == 3)) {
        DVar5 = WaitForSingleObject(pvVar1, 0);
      } else {
        DVar5 = WaitForMultipleObjects(2, &local_8, 0, 0);
        if (DVar5 == 0) {
          DVar5 = GetCurrentThreadId();
          if (*(DWORD*)((int64_t)(intptr_t)pvVar4 + 0x30) == DVar5) {
            *(uint32_t*)((int64_t)(intptr_t)pvVar4 + 0x14) = 3;
            FUN_004faab0();
          }
          DVar5 = 0;
        } else if (DVar5 == 1) {
          DVar5 = 0;
        }
      }
    }
    if (DVar5 == 0) {
      pvVar1 = *(HANDLE*)(param_1 + 0xf4);
      if ((DAT_00726c28 == 0xffffffff) || ((pvVar4 = TlsGetValue(DAT_00726c28), pvVar4 == (LPVOID)0x0))) {
        WaitForSingleObject(pvVar1, 0xffffffff);
      } else {
        FUN_004fac10();
      }
      pvVar1 = *(HANDLE*)(param_1 + 0xdc);
      if ((DAT_00726c28 == 0xffffffff) || ((pvVar4 = TlsGetValue(DAT_00726c28), pvVar4 == (LPVOID)0x0))) {
        WaitForSingleObject(pvVar1, 0xffffffff);
      } else {
        FUN_004fac10();
      }
      iVar6 = FUN_00517710(self, 1, 1);
      puVar2 = *(uint32_t**)(param_1 + 0x13c);
      while (puVar2 != (uint32_t*)0x0) {
        piVar3 = (int32_t*)puVar2[2];
        if (piVar3[1] == param_2) {
          local_8 = (HANDLE)(*(int*)(param_2 + 0x7c) - 1);
          FUN_005129a0(*(uint32_t*)(*piVar3 + 0x24) / (uint32_t)local_8);
          *(uint8_t*)((int64_t)(intptr_t)piVar3 + 8) = 0;
          FUN_00517f90();
        } else {
          puVar2 = (uint32_t*)*puVar2;
        }
      }
      FUN_004e6420();
      FUN_005edba0();
      puVar2 = *(uint32_t**)(param_1 + 0x10c);
      while (puVar2 != (uint32_t*)0x0) {
        if (*(int*)(puVar2[2] + 4) == param_2) {
          *(uint8_t*)(puVar2[2] + 8) = 0;
          FUN_00517f90();
        } else {
          puVar2 = (uint32_t*)*puVar2;
        }
      }
      ReleaseMutex(*(HANDLE*)(*(int*)(iVar6 + 0x20) + 0x38));
      ReleaseMutex(*(HANDLE*)(param_1 + 0xdc));
      ReleaseMutex(*(HANDLE*)(param_1 + 0xf4));
      ReleaseMutex(DAT_0072705c);
      FUN_00515cb0(self);
      return;
    }
    FUN_00515cb0(self);
  } while (true);
}

// 0x517010 — observed shape
void FUN_00517010(void* self) {
  int64_t base = (int64_t)(intptr_t)self;
  uint32_t uVar2 = 0;
  *(uint8_t*)(base + 0xcd) = 1;
  if (*(int32_t*)(base + 0x80) != 0) {
    do {
      int32_t iVar1 = *(int32_t*)(*(int32_t*)(base + 0x78) + uVar2 * 4);
      if (iVar1 != 0) {
        FUN_00516e10(*(char**)(base + 0x78) + uVar2 * 4, iVar1);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint32_t*)(base + 0x80));
  }
}

// 0x517050 — observed shape
void FUN_00517050(void* self) {
  int64_t param_1 = (int64_t)(intptr_t)self;
  HANDLE hHandle;
  uint32_t* puVar1;
  int32_t* piVar2;
  LPVOID pvVar3;
  int32_t* piVar4;

  hHandle = *(HANDLE*)(param_1 + 0xf4);
  if ((DAT_00726c28 == 0xffffffff) || ((pvVar3 = TlsGetValue(DAT_00726c28), pvVar3 == (LPVOID)0x0))) {
    WaitForSingleObject(hHandle, 0xffffffff);
  } else {
    FUN_004fac10();
  }
  puVar1 = *(uint32_t**)(param_1 + 0x13c);
  while (puVar1 != (uint32_t*)0x0) {
    piVar4 = (int32_t*)puVar1[2];
    puVar1 = (uint32_t*)*puVar1;
    FUN_005129a0(*(uint32_t*)(*piVar4 + 0x24) / (*(int32_t*)(piVar4[1] + 0x7c) - 1U));
    *(uint8_t*)((int64_t)(intptr_t)piVar4 + 8) = 0;
  }
  if (*(int32_t**)(param_1 + 0x13c) != (int32_t*)0x0) {
    piVar4 = *(int32_t**)(param_1 + 0x13c);
    do {
      piVar2 = (int32_t*)*piVar4;
      ((void(*)(int32_t*))*(void**)(*(int32_t*)(param_1 + 0x138) + 8))(piVar4);
      piVar4 = piVar2;
    } while (piVar2 != (int32_t*)0x0);
  }
  *(uint32_t*)(param_1 + 0x144) = 0;
  *(uint32_t*)(param_1 + 0x13c) = 0;
  *(uint32_t*)(param_1 + 0x140) = 0;
  ReleaseMutex(*(HANDLE*)(param_1 + 0xf4));
}

// 0x517120 — observed shape
uint32_t FUN_00517120(void* in_EAX, int64_t param_1, int64_t in_ECX) {
  int64_t rax = (int64_t)(intptr_t)in_EAX;
  float fVar1 = *(float*)(rax + 0x8c) - *(float*)(rax + 0x98);
  float fVar2 = *(float*)(rax + 0x90) - *(float*)(rax + 0x9c);
  float fVar3 = *(float*)(rax + 0x94) - *(float*)(rax + 0xa0);
  if (in_ECX != 0) {
    uint32_t uVar4 = FUN_00515640("Unknown operation mode (%d)", *(uint32_t*)(rax + 0x70));
    return uVar4 & 0xffffff00;
  }
  if (fVar2 * fVar2 + fVar1 * fVar1 + fVar3 * fVar3 < *(float*)(rax + 0xa4 + param_1 * 4)) {
    return 1;
  }
  return 0;
}

// 0x5171a0 — observed shape
uint32_t FUN_005171a0(void* in_EAX, void* in_ECX, int64_t param_1, int64_t in_EDX) {
  int64_t rax = (int64_t)(intptr_t)in_EAX;
  int64_t rcx = (int64_t)(intptr_t)in_ECX;
  if (in_EDX != 0) {
    uint32_t uVar7 = FUN_00515640("Unknown operation mode (%d)", *(uint32_t*)(rcx + 0x70));
    return uVar7 & 0xffffff00;
  }
  float fVar1 = (float)*(int32_t*)(rax + 0x6c);
  if (*(int32_t*)(rax + 0x6c) < 0) fVar1 = fVar1 + 4.2949673e+09f;
  fVar1 = (fVar1 - 1.0f) * *(float*)(rax + 0x84);
  float fVar3 = (float)*(int32_t*)(rax + 0x70);
  if (*(int32_t*)(rax + 0x70) < 0) fVar3 = fVar3 + 4.2949673e+09f;
  float fVar2 = (fVar3 - 1.0f) * *(float*)(rax + 0x88);
  float fVar4 = fVar1 * 0.5f + *(float*)(*(int32_t*)(rax + 4) + 0x90);
  fVar3 = *(float*)(*(int32_t*)(rax + 4) + 0x94) - fVar2 * 0.5f;
  fVar1 = (fVar2 * fVar2 + fVar1 * fVar1) * 0.25f;
  float fVar6 = fVar4 - *(float*)(rcx + 0x8c);
  float fVar5 = fVar3 - *(float*)(rcx + 0x90);
  fVar2 = 0.0f - *(float*)(rcx + 0x94);
  fVar2 = fVar6 * fVar6 + fVar5 * fVar5 + fVar2 * fVar2;
  if (fVar2 < fVar1) return 1;
  fVar4 = fVar4 - *(float*)(rcx + 0x8c);
  fVar3 = fVar3 - *(float*)(rcx + 0x90);
  fVar2 = 0.0f - *(float*)(rcx + 0x94);
  if (sqrtf(fVar4 * fVar4 + fVar3 * fVar3 + fVar2 * fVar2) - sqrtf(fVar1) < *(float*)(rcx + 0xa4 + param_1 * 4)) return 1;
  return 0;
}

// 0x517320 — observed shape
uint32_t FUN_00517320(void* in_EBX, void* in_EDI, int64_t param_1, int64_t param_2) {
  int64_t ebx = (int64_t)(intptr_t)in_EBX;
  int64_t edi = (int64_t)(intptr_t)in_EDI;
  int32_t* piVar2 = *(int32_t**)(edi + 8);
  if (piVar2 != (int32_t*)0x0) {
    uint8_t bVar9 = 0;
    for (uint32_t* puVar10 = (uint32_t*)((void*(*)(void))*(void**)(*piVar2 + 4))(); puVar10 != (uint32_t*)0x0; puVar10 = (uint32_t*)puVar10[1]) {
      if (puVar10 == &DAT_00727560) { bVar9 = 1; goto check; }
    }
check:
    if ((-(uint8_t)bVar9 & piVar2) != 0) {
      if (param_2 != 0) { FUN_00515640("Unknown operation mode (%d)", *(uint32_t*)(ebx + 0x70)); return 0; }
      int32_t iVar11 = FUN_004edfd0();
      int32_t iVar13 = *(int32_t*)(edi + 4);
      float fVar1 = (*(float*)(iVar13 + 0x84) == *(float*)(iVar13 + 0x88)) ? *(float*)(iVar13 + 0x84) : 0.0f;
      int32_t iVar3 = *(int32_t*)(edi + 4);
      int32_t iVar12 = *(int32_t*)(iVar3 + 0x80) + -1;
      float fVar4 = (float)iVar12;
      if (iVar12 < 0) fVar4 = fVar4 + 4.2949673e+09f;
      fVar4 = fVar4 * fVar1;
      fVar1 = (*(float*)(iVar3 + 0x84) == *(float*)(iVar3 + 0x88)) ? *(float*)(iVar3 + 0x84) : 0.0f;
      iVar13 = *(int32_t*)(iVar13 + 0x7c) + -1;
      float fVar7 = (float)iVar13;
      if (iVar13 < 0) fVar7 = fVar7 + 4.2949673e+09f;
      fVar7 = fVar7 * fVar1;
      float fVar6 = fVar7 * 0.5f + *(float*)(iVar11 + 0x90);
      float fVar5 = *(float*)(iVar11 + 0x94) - fVar4 * 0.5f;
      fVar1 = (fVar4 * fVar4 + fVar7 * fVar7) * 0.25f;
      float fVar8 = fVar6 - *(float*)(ebx + 0x8c);
      fVar7 = fVar5 - *(float*)(ebx + 0x90);
      fVar4 = 0.0f - *(float*)(ebx + 0x94);
      if (fVar1 <= fVar8 * fVar8 + fVar7 * fVar7 + fVar4 * fVar4) {
        fVar6 = fVar6 - *(float*)(ebx + 0x8c);
        fVar5 = fVar5 - *(float*)(ebx + 0x90);
        fVar4 = 0.0f - *(float*)(ebx + 0x94);
        if (sqrtf(fVar6 * fVar6 + fVar5 * fVar5 + fVar4 * fVar4) - sqrtf(fVar1) < *(float*)(ebx + 0xa4 + param_1 * 4)) return 1;
        return 0;
      }
    }
  }
  return 1;
}

// 0x517530 — observed shape
uint32_t FUN_00517530(void* in_ECX, void* in_EDX, int64_t param_1, int64_t param_2, int64_t param_3, int64_t in_EAX) {
  int64_t rcx = (int64_t)(intptr_t)in_ECX;
  int64_t rdx = (int64_t)(intptr_t)in_EDX;
  if (in_EAX != 0) {
    uint32_t uVar7 = FUN_00515640("Unknown operation mode (%d)", *(uint32_t*)(rcx + 0x70));
    return uVar7 & 0xffffff00;
  }
  float fVar1 = (*(float*)(rdx + 0x84) == *(float*)(rdx + 0x88)) ? *(float*)(rdx + 0x84) : 0.0f;
  int32_t iVar8 = *(int32_t*)(rdx + 0x80) + -1;
  float fVar2 = (float)iVar8;
  if (iVar8 < 0) fVar2 = fVar2 + 4.2949673e+09f;
  fVar2 = fVar2 * fVar1;
  fVar1 = (*(float*)(rdx + 0x84) == *(float*)(rdx + 0x88)) ? *(float*)(rdx + 0x84) : 0.0f;
  iVar8 = *(int32_t*)(rdx + 0x7c) + -1;
  float fVar5 = (float)iVar8;
  if (iVar8 < 0) fVar5 = fVar5 + 4.2949673e+09f;
  fVar5 = fVar5 * fVar1;
  fVar1 = (float)param_2;
  if (param_2 < 0) fVar1 = fVar1 + 4.2949673e+09f;
  float fVar3 = (float)param_3;
  if (param_3 < 0) fVar3 = fVar3 + 4.2949673e+09f;
  float fVar4 = fVar5 * 0.5f + fVar1 * fVar5 + *(float*)(*(int32_t*)(rdx + 4) + 0x90);
  fVar3 = (-(fVar3 * fVar2) + *(float*)(*(int32_t*)(rdx + 4) + 0x94)) - fVar2 * 0.5f;
  fVar1 = (fVar2 * fVar2 + fVar5 * fVar5) * 0.25f;
  float fVar6 = fVar4 - *(float*)(rcx + 0x8c);
  fVar5 = fVar3 - *(float*)(rcx + 0x90);
  fVar2 = 0.0f - *(float*)(rcx + 0x94);
  fVar2 = fVar6 * fVar6 + fVar5 * fVar5 + fVar2 * fVar2;
  if (fVar2 < fVar1) return 1;
  fVar4 = fVar4 - *(float*)(rcx + 0x8c);
  fVar3 = fVar3 - *(float*)(rcx + 0x90);
  fVar2 = 0.0f - *(float*)(rcx + 0x94);
  if (sqrtf(fVar4 * fVar4 + fVar3 * fVar3 + fVar2 * fVar2) - sqrtf(fVar1) < *(float*)(rcx + 0xa4 + param_1 * 4)) return 1;
  return 0;
}

// 0x517710 — observed shape
int32_t FUN_00517710(void* self, char param_2, uint32_t param_3, uint32_t in_EAX) {
  int32_t local_4 = 0;
  char cVar1 = FUN_0051bfc0(&local_4);
  if ((cVar1 != '\0') && (local_4 != 0)) {
    if ((char)param_3 != '\0') FUN_004fad90();
    return local_4;
  }
  if (param_2 == '\0') { FUN_00515640("Context expected, but not found for 0x%x"); return 0; }
  FUN_00515640("Creating cell context for 0x%x");
  int32_t iVar2 = FUN_00533c78(0x24);
  if (iVar2 == 0) iVar2 = 0;
  else {
    iVar2 = FUN_005177d0();
  }
  uint32_t uVar3 = FUN_00519ca0(in_EAX, 1, param_3);
  *(uint32_t*)(iVar2 + 0x20) = uVar3;
  FUN_00524e90(iVar2);
  return iVar2;
}

// 0x5177d0 — observed shape
void FUN_005177d0(void* self) {
  int64_t base = (int64_t)(intptr_t)self;
  uint32_t* unaff_ESI = (uint32_t*)(intptr_t)base;
  unaff_ESI[3] = 0;
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  unaff_ESI[0] = (uint32_t)0x00711b1c;
  unaff_ESI[4] = (uint32_t)0x007119b4;
  unaff_ESI[5] = 0x25;
  unaff_ESI[7] = 0;
  uint32_t* puVar1 = (uint32_t*)FUN_00533c78(0x94);
  unaff_ESI[6] = (uint32_t)(intptr_t)puVar1;
  for (uint32_t uVar2 = unaff_ESI[5] & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  for (int32_t iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(uint8_t*)puVar1 = 0;
    puVar1 = (uint32_t*)((intptr_t)puVar1 + 1);
  }
  unaff_ESI[4] = (uint32_t)0x007119d0;
}

// 0x517830 — observed shape
void FUN_00517830(void* self, uint8_t param_1) {
  *(uint32_t*)(intptr_t)self = 0x00711b1c;
  FUN_005edba0();
  *(uint32_t*)(intptr_t)self = 0x0071199c;
  if ((param_1 & 1) != 0) operator_delete(self);
}

// 0x517860 — observed shape
void FUN_00517860(void* self, void* tls_ptr, uint32_t in_EAX, HANDLE param_1) {
  int64_t ecx = (int64_t)(intptr_t)self;
  int64_t edx = (int64_t)(intptr_t)tls_ptr;
  uint32_t uVar6 = (uint32_t)((int64_t)(intptr_t)param_1 << 0x10);
  int32_t* piVar3 = (int32_t*)FUN_00517710(tls_ptr, 1, 1, 0);
  if (*(char*)(ecx + 0xa0) == '\0') {
    if (*(char*)((int64_t)(intptr_t)piVar3[8] + 1) == '\0') FUN_00519780(tls_ptr);
    ReleaseMutex(*(HANDLE*)((int64_t)(intptr_t)piVar3[8] + 0x38));
    HANDLE pvVar1 = *(HANDLE*)((int64_t)(intptr_t)piVar3[8] + 0x38);
    if (DAT_00726c28 != 0xffffffff) {
      LPVOID pvVar4 = TlsGetValue(DAT_00726c28);
      if (pvVar4 != (LPVOID)0x0) { FUN_004fac10(); goto LAB2; }
    }
    WaitForSingleObject(pvVar1, 0xffffffff);
  }
LAB2:;
  uint32_t local_4 = 0;
  char cVar2 = FUN_0051bfc0(&local_4);
  if (cVar2 != '\0') goto LAB3;
  HANDLE pvVar1 = *(HANDLE*)(edx + 0x38);
  if (DAT_00726c28 == 0xffffffff) WaitForSingleObject(pvVar1, 0xffffffff);
  else {
    LPVOID pvVar4 = TlsGetValue(DAT_00726c28);
    if (pvVar4 == (LPVOID)0x0) WaitForSingleObject(pvVar1, 0xffffffff);
    else FUN_004fac10();
  }
  uint32_t* puVar5 = (uint32_t*)((void*(*)(void))*(void**)(*(int32_t*)(edx + 0x160) + 4))();
  puVar5[2] = (uint32_t)(intptr_t)piVar3;
  puVar5[1] = 0;
  *puVar5 = *(uint32_t*)(edx + 0x164);
  if (*(int32_t*)(edx + 0x164) == 0) *(uint32_t**)(edx + 0x168) = puVar5;
  else *(uint32_t**)(*(int32_t*)(edx + 0x164) + 4) = puVar5;
  *(uint32_t**)(edx + 0x164) = puVar5;
  *(int32_t*)(edx + 0x16c) = *(int32_t*)(edx + 0x16c) + 1;
  ReleaseMutex(*(HANDLE*)(edx + 0x38));
  puVar5 = (uint32_t*)((void*(*)(void))*(void**)(*piVar3 + 4))();
  puVar5[2] = uVar6 | (in_EAX & 0xffff);
  *puVar5 = 0;
  puVar5[1] = piVar3[2];
  if ((uint32_t*)piVar3[2] == (uint32_t*)0x0) piVar3[1] = (int32_t)(intptr_t)puVar5;
  else *(uint32_t*)piVar3[2] = (uint32_t)(intptr_t)puVar5;
  piVar3[2] = (int32_t)(intptr_t)puVar5;
  piVar3[3] = piVar3[3] + 1;
  FUN_00524e90(0);
LAB3:
  param_1 = *(HANDLE*)((int64_t)(intptr_t)piVar3[8] + 0x38);
  ReleaseMutex(param_1);
}

// 0x5179b0 — observed shape
uint32_t FUN_005179b0(void* self, int64_t unaff_retaddr) {
  int64_t param_1 = (int64_t)(intptr_t)self;
  HANDLE pvVar1 = *(HANDLE*)(param_1 + 0x38);
  if ((DAT_00726c28 == 0xffffffff) || ((*(void**)0 == 0, TlsGetValue(DAT_00726c28) == (LPVOID)0x0))) {
    WaitForSingleObject(pvVar1, 0xffffffff);
  } else {
    FUN_004fac10();
  }
  uint32_t uVar8 = 0;
  if (*(int32_t*)(param_1 + 0x48) == 0) {
    ReleaseMutex(*(HANDLE*)(param_1 + 0x38));
    return 0;
  }
  int32_t* piVar6 = *(int32_t**)(param_1 + 0x40);
  int32_t iVar2 = *piVar6;
  *(int32_t*)(param_1 + 0x40) = iVar2;
  if (iVar2 == 0) *(uint32_t*)(param_1 + 0x44) = 0;
  else *(uint32_t*)(iVar2 + 4) = 0;
  uint8_t* puVar3 = (uint8_t*)piVar6[2];
  ((void(*)(int32_t*))*(void**)(*(int32_t*)(param_1 + 0x3c) + 8))(piVar6);
  *(int32_t*)(param_1 + 0x48) = *(int32_t*)(param_1 + 0x48) + -1;
  ReleaseMutex(*(HANDLE*)(param_1 + 0x38));
  pvVar1 = *(HANDLE*)((int64_t)(intptr_t)puVar3 + 0x38);
  LPVOID pvVar5 = TlsGetValue(DAT_00726c28);
  if ((DAT_00726c28 == 0xffffffff) || (pvVar5 == (LPVOID)0x0)) WaitForSingleObject(pvVar1, 0xffffffff);
  else FUN_004fac10();
  *puVar3 = 0;
  puVar3[1] = 1;
  if (*(int32_t*)((int64_t)(intptr_t)puVar3 + 0x28) != 0) {
    do {
      iVar2 = *(int32_t*)(*(int32_t*)((int64_t)(intptr_t)puVar3 + 0x20) + uVar8 * 4);
      if (iVar2 != 0) {
        piVar6 = (int32_t*)((int32_t*(*)(int32_t))**(void**)(param_1 + 0x4c))(iVar2);
        ((void(*)(void))*(void**)(*piVar6 + 4))();
        if ((uVar8 < *(uint32_t*)((int64_t)(intptr_t)puVar3 + 0xc)) || (FUN_004f5670(), uVar8 < *(uint32_t*)((int64_t)(intptr_t)puVar3 + 0xc))) {
          if (uVar8 < *(uint32_t*)((int64_t)(intptr_t)puVar3 + 0x10)) {
            if (*(int32_t*)(*(int32_t*)((int64_t)(intptr_t)puVar3 + 8) + uVar8 * 4) == 0) goto store;
          } else {
            *(uint32_t*)((int64_t)(intptr_t)puVar3 + 0x10) = uVar8 + 1;
store:
            *(int32_t*)((int64_t)(intptr_t)puVar3 + 0x14) = *(int32_t*)((int64_t)(intptr_t)puVar3 + 0x14) + 1;
          }
          *(int32_t**)(*(int32_t*)((int64_t)(intptr_t)puVar3 + 8) + uVar8 * 4) = piVar6;
        }
        param_1 = unaff_retaddr;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(uint32_t*)((int64_t)(intptr_t)puVar3 + 0x28));
  }
  pvVar1 = *(HANDLE*)(param_1 + 0xe4);
  pvVar5 = TlsGetValue(DAT_00726c28);
  if ((DAT_00726c28 == 0xffffffff) || (pvVar5 == (LPVOID)0x0)) WaitForSingleObject(pvVar1, 0xffffffff);
  else FUN_004fac10();
  FUN_00515640("Landscape (%s) maps are loaded, waiting for aquisition", *(int32_t*)((int64_t)(intptr_t)puVar3 + 0x3c) + 0x14);
  uint32_t uVar4 = *(uint32_t*)((int64_t)(intptr_t)puVar3 + 0x3c);
  uint32_t* puVar7 = (uint32_t*)((void*(*)(void))*(void**)(*(int32_t*)(param_1 + 0x118) + 4))();
  puVar7[2] = uVar4;
  *puVar7 = 0;
  puVar7[1] = *(uint32_t*)(param_1 + 0x120);
  if (*(uint32_t**)(param_1 + 0x120) == (uint32_t*)0x0) *(uint32_t**)(param_1 + 0x11c) = puVar7;
  else **(uint32_t**)(param_1 + 0x120) = (uint32_t)(intptr_t)puVar7;
  *(uint32_t**)(param_1 + 0x120) = puVar7;
  *(int32_t*)(param_1 + 0x124) = *(int32_t*)(param_1 + 0x124) + 1;
  ReleaseMutex(*(HANDLE*)(param_1 + 0xe4));
  ReleaseMutex(*(HANDLE*)((int64_t)(intptr_t)puVar3 + 0x38));
  return 1;
}

// 0x517b80 — observed shape
uint32_t FUN_00517b80(void* self, int64_t unaff_EBP, int64_t unaff_retaddr, int64_t iStack_4) {
  int64_t param_1 = (int64_t)(intptr_t)self;
  HANDLE pvVar1 = *(HANDLE*)(param_1 + 0x38);
  LPVOID pvVar5 = TlsGetValue(DAT_00726c28);
  if ((DAT_00726c28 == 0xffffffff) || (pvVar5 == (LPVOID)0x0)) WaitForSingleObject(pvVar1, 0xffffffff);
  else FUN_004fac10();
  if (*(int32_t*)(param_1 + 0x16c) == 0) {
    ReleaseMutex(*(HANDLE*)(param_1 + 0x38));
    return 0;
  }
  int32_t* piVar2 = *(int32_t**)(param_1 + 0x164);
  int32_t iVar3 = *piVar2;
  *(int32_t*)(param_1 + 0x164) = iVar3;
  if (iVar3 == 0) *(uint32_t*)(param_1 + 0x168) = 0;
  else *(uint32_t*)(iVar3 + 4) = 0;
  int32_t* piVar4 = (int32_t*)piVar2[2];
  ((void(*)(int32_t*))*(void**)(*(int32_t*)(param_1 + 0x160) + 8))(piVar2);
  *(int32_t*)(param_1 + 0x16c) = *(int32_t*)(param_1 + 0x16c) + -1;
  ReleaseMutex(*(HANDLE*)(param_1 + 0x38));
  pvVar1 = *(HANDLE*)((int64_t)(intptr_t)piVar4[8] + 0x38);
  pvVar5 = TlsGetValue(DAT_00726c28);
  if ((DAT_00726c28 == 0xffffffff) || (pvVar5 == (LPVOID)0x0)) WaitForSingleObject(pvVar1, 0xffffffff);
  else FUN_004fac10();
  if (piVar4[3] == 0) {
    ReleaseMutex(*(HANDLE*)((int64_t)(intptr_t)piVar4[8] + 0x38));
    return 1;
  }
LAB_C40:;
  piVar2 = (int32_t*)piVar4[1];
  iVar3 = *piVar2;
  piVar4[1] = iVar3;
  if (iVar3 == 0) piVar4[2] = 0;
  else *(uint32_t*)(iVar3 + 4) = 0;
  uint32_t uVar11 = piVar2[2];
  ((void(*)(int32_t*))*(void**)(*piVar4 + 8))(piVar2);
  piVar4[3] = piVar4[3] + -1;
  uint32_t uVar10 = uVar11 >> 0x10;
  if (*(char*)(*(int32_t*)((int64_t)(intptr_t)piVar4[8] + 0x3c) + 0xa0) == '\0') {
    do {
      ReleaseMutex(*(HANDLE*)((int64_t)(intptr_t)piVar4[8] + 0x38));
      FUN_005179b0(self, 0);
      pvVar5 = TlsGetValue(DAT_00726c28);
      if (((DAT_00726c28 == 0xffffffff) || (pvVar5 == (LPVOID)0x0)) || (*(int32_t*)((int64_t)(intptr_t)pvVar5 + 0x14) == 0) || (*(int32_t*)((int64_t)(intptr_t)pvVar5 + 0x14) == 3)) {
        SleepEx(0x1e, 0);
      } else {
        DWORD DVar6 = WaitForSingleObject(*(HANDLE*)((int64_t)(intptr_t)pvVar5 + 0x20), 0x1e);
        if ((DVar6 == 0) && ((DVar6 = GetCurrentThreadId(), *(DWORD*)((int64_t)(intptr_t)pvVar5 + 0x30) == DVar6))) {
          *(uint32_t*)((int64_t)(intptr_t)pvVar5 + 0x14) = 3;
          FUN_004faab0();
        }
      }
      pvVar1 = *(HANDLE*)((int64_t)(intptr_t)piVar4[8] + 0x38);
      pvVar5 = TlsGetValue(DAT_00726c28);
      if ((DAT_00726c28 == 0xffffffff) || (pvVar5 == (LPVOID)0x0)) {
        WaitForSingleObject(pvVar1, 0xffffffff);
      } else {
        HANDLE pvStack_10 = *(HANDLE*)((int64_t)(intptr_t)pvVar5 + 0x20);
        HANDLE pvStack_c = pvVar1;
        int tls_state = *(int32_t*)((int64_t)(intptr_t)pvVar5 + 0x14);
        if ((tls_state == 0) || (tls_state == 3)) {
          WaitForSingleObject(pvVar1, 0xffffffff);
        } else {
          DWORD DVar6 = WaitForMultipleObjects(2, &pvStack_10, 0, 0xffffffff);
          if ((DVar6 == 0) && ((DVar6 = GetCurrentThreadId(), *(DWORD*)((int64_t)(intptr_t)pvVar5 + 0x30) == DVar6))) {
            *(uint32_t*)((int64_t)(intptr_t)pvVar5 + 0x14) = 3;
            FUN_004faab0();
          }
        }
      }
      if (*(char*)(*(int32_t*)((int64_t)(intptr_t)piVar4[8] + 0x3c) + 0xa0) != '\0') { uVar11 = (uint32_t)unaff_EBP; break; }
      param_1 = iStack_4;
    } while (true);
  }
  uint32_t uVar7 = FUN_00512a90(uVar10);
  FUN_00515640("Landscape (%s) cell (%dx%d) loaded, waiting for aquisition", *(int32_t*)((int64_t)(intptr_t)piVar4[8] + 0x3c) + 0x14, uVar10, uVar11 & 0xffff);
  FUN_00524e90(uVar7);
  iVar3 = (int32_t)iStack_4;
  pvVar1 = *(HANDLE*)(iStack_4 + 0xd4);
  pvVar5 = TlsGetValue(DAT_00726c28);
  if ((DAT_00726c28 == 0xffffffff) || (pvVar5 == (LPVOID)0x0)) WaitForSingleObject(pvVar1, 0xffffffff);
  else FUN_004fac10();
  uint32_t* puVar8 = (uint32_t*)FUN_00517e90();
  puVar8[1] = *(uint32_t*)((int64_t)(intptr_t)piVar4[8] + 0x3c);
  *puVar8 = uVar7;
  uint32_t* puVar9 = (uint32_t*)((void*(*)(void))*(void**)(*(int32_t*)(iVar3 + 0xf8) + 4))();
  puVar9[2] = (uint32_t)(intptr_t)puVar8;
  puVar9[1] = 0;
  *puVar9 = *(uint32_t*)(iVar3 + 0xfc);
  if (*(int32_t*)(iVar3 + 0xfc) == 0) *(uint32_t**)(iVar3 + 0x100) = puVar9;
  else *(uint32_t**)(*(int32_t*)(iVar3 + 0xfc) + 4) = puVar9;
  *(uint32_t**)(iVar3 + 0xfc) = puVar9;
  *(int32_t*)(iVar3 + 0x104) = *(int32_t*)(iVar3 + 0x104) + 1;
  ReleaseMutex(*(HANDLE*)(iVar3 + 0xd4));
  if (piVar4[3] == 0) {
    ReleaseMutex(*(HANDLE*)((int64_t)(intptr_t)piVar4[8] + 0x38));
    return 1;
  }
  param_1 = unaff_retaddr;
  goto LAB_C40;
}

// 0x517e90 — observed shape
uint32_t* FUN_00517e90(void* in_EAX) {
  int64_t rax = (int64_t)(intptr_t)in_EAX;
  uint32_t uVar2 = 0;
  if (*(int32_t*)(rax + 0x154) != 0) {
    do {
      uint32_t* puVar1 = *(uint32_t**)(*(int32_t*)(rax + 0x14c) + uVar2 * 4);
      if (puVar1 == (uint32_t*)0x0) {
        puVar1 = (uint32_t*)FUN_00533c78(0xc);
        *(uint8_t*)((int64_t)(intptr_t)puVar1 + 8) = 1;
        puVar1[1] = 0;
        *puVar1 = 0;
        if (*(uint32_t*)(rax + 0x150) <= uVar2) return puVar1;
        if (uVar2 < *(uint32_t*)(rax + 0x154)) {
          if (*(int32_t*)(*(int32_t*)(rax + 0x14c) + uVar2 * 4) != 0) goto store;
        } else {
          *(uint32_t*)(rax + 0x154) = uVar2 + 1;
        }
        *(int32_t*)(rax + 0x158) = *(int32_t*)(rax + 0x158) + 1;
store:
        *(uint32_t**)(*(int32_t*)(rax + 0x14c) + uVar2 * 4) = puVar1;
        return puVar1;
      }
      if (*(char*)((int64_t)(intptr_t)puVar1 + 8) == '\0') {
        *(uint8_t*)((int64_t)(intptr_t)puVar1 + 8) = 1;
        puVar1[1] = 0;
        *puVar1 = 0;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint32_t*)(rax + 0x154));
  }
  uint32_t* puVar1 = (uint32_t*)FUN_00533c78(0xc);
  *(uint8_t*)((int64_t)(intptr_t)puVar1 + 8) = 1;
  puVar1[1] = 0;
  *puVar1 = 0;
  uVar2 = *(uint32_t*)(rax + 0x154);
  if ((uVar2 < *(uint32_t*)(rax + 0x150)) || (FUN_004f5670(), uVar2 < *(uint32_t*)(rax + 0x150))) {
    if (*(uint32_t*)(rax + 0x154) <= uVar2) {
      *(int32_t*)(rax + 0x158) = *(int32_t*)(rax + 0x158) + 1;
      *(uint32_t*)(rax + 0x154) = uVar2 + 1;
      *(uint32_t**)(*(int32_t*)(rax + 0x14c) + uVar2 * 4) = puVar1;
      return puVar1;
    }
    if (*(int32_t*)(*(int32_t*)(rax + 0x14c) + uVar2 * 4) == 0) *(int32_t*)(rax + 0x158) = *(int32_t*)(rax + 0x158) + 1;
    *(uint32_t**)(*(int32_t*)(rax + 0x14c) + uVar2 * 4) = puVar1;
  }
  return puVar1;
}

// 0x517f90 — observed shape
int32_t FUN_00517f90(void* self, int32_t* in_ECX) {
  int64_t esi_base = (int64_t)(intptr_t)self;
  int32_t* unaff_ESI = (int32_t*)(intptr_t)esi_base;
  int32_t* piVar1 = (int32_t*)*in_ECX;
  if (piVar1 == (int32_t*)unaff_ESI[1]) {
    *in_ECX = *piVar1;
    piVar1 = (int32_t*)unaff_ESI[1];
    int32_t iVar2 = *piVar1;
    unaff_ESI[1] = iVar2;
    if (iVar2 == 0) {
      unaff_ESI[2] = 0;
      iVar2 = piVar1[2];
      ((void(*)(int32_t*))*(void**)(*unaff_ESI + 8))(piVar1);
      unaff_ESI[3] = unaff_ESI[3] + -1;
      return iVar2;
    }
    *(uint32_t*)(iVar2 + 4) = 0;
    iVar2 = piVar1[2];
    ((void(*)(int32_t*))*(void**)(*unaff_ESI + 8))(piVar1);
    unaff_ESI[3] = unaff_ESI[3] + -1;
    return iVar2;
  }
  if (piVar1 != (int32_t*)unaff_ESI[2]) {
    int32_t* piVar5 = (int32_t*)piVar1[1];
    int32_t iVar2 = *piVar1;
    *in_ECX = iVar2;
    if (piVar5 != (int32_t*)0x0) *piVar5 = iVar2;
    if (iVar2 != 0) *(int32_t**)(iVar2 + 4) = piVar5;
    iVar2 = piVar1[2];
    ((void(*)(int32_t*))*(void**)(*unaff_ESI + 8))(piVar1);
    unaff_ESI[3] = unaff_ESI[3] + -1;
    return iVar2;
  }
  *in_ECX = 0;
  int32_t iVar2 = unaff_ESI[2];
  uint32_t* puVar3 = *(uint32_t**)(iVar2 + 4);
  unaff_ESI[2] = (int32_t)(intptr_t)puVar3;
  if (puVar3 == (uint32_t*)0x0) {
    unaff_ESI[1] = 0;
    int32_t iVar4 = *(int32_t*)(iVar2 + 8);
    ((void(*)(int32_t*))*(void**)(*unaff_ESI + 8))((int32_t*)iVar2);
    unaff_ESI[3] = unaff_ESI[3] + -1;
    return iVar4;
  }
  *puVar3 = 0;
  int32_t iVar4 = *(int32_t*)(iVar2 + 8);
  ((void(*)(int32_t*))*(void**)(*unaff_ESI + 8))((int32_t*)iVar2);
  unaff_ESI[3] = unaff_ESI[3] + -1;
  return iVar4;
}

// 0x518050 — observed shape
void FUN_00518050(void* self, uint8_t param_1) {
  uint32_t* in_ECX = (uint32_t*)(intptr_t)self;
  in_ECX[0] = 0x007119b4;
  FUN_004e6420();
  operator_delete((void*)in_ECX[2]);
  if ((param_1 & 1) != 0) operator_delete(in_ECX);
}

// 0x5180b0 — observed shape
void FUN_005180b0(void* self, uint8_t param_1) {
  uint32_t* in_ECX = (uint32_t*)(intptr_t)self;
  in_ECX[0] = 0x007119d0;
  FUN_004e6420();
  in_ECX[0] = 0x007119b4;
  FUN_004e6420();
  operator_delete((void*)in_ECX[2]);
  if ((param_1 & 1) != 0) operator_delete(in_ECX);
}

// 0x5180f0 — observed shape
void FUN_005180f0(void* self) {
  uint32_t* unaff_EBX = (uint32_t*)(intptr_t)self;
  uint32_t* puVar1 = (uint32_t*)FUN_00533c78(4);
  if (puVar1 == (uint32_t*)0x0) puVar1 = (uint32_t*)0x0;
  else puVar1[0] = 0x00711860;
  FUN_00518450(puVar1);
  unaff_EBX[0] = 0x00711a88;
  unaff_EBX[0x1d] = 0x00711a2c;
  unaff_EBX[0x1f] = 0;
  unaff_EBX[0x22] = 1;
  unaff_EBX[0x20] = 0;
  unaff_EBX[0x21] = 0;
  unaff_EBX[0x1e] = 0;
  unaff_EBX[0x2f] = 0x007109b0;
  unaff_EBX[0x30] = 0;
  HANDLE pvVar2 = CreateMutexA((LPSECURITY_ATTRIBUTES)0x0, 0, (LPCSTR)0x0);
  unaff_EBX[0x30] = (uint32_t)(intptr_t)pvVar2;
  if (pvVar2 == (HANDLE)0x0) { uint32_t local_4 = 0xffffffff; _CxxThrowException(&local_4, (void*)&DAT_007149ac); }
  unaff_EBX[0x31] = 0x007109b0;
  unaff_EBX[0x32] = 0;
  pvVar2 = CreateMutexA((LPSECURITY_ATTRIBUTES)0x0, 0, (LPCSTR)0x0);
  unaff_EBX[0x32] = (uint32_t)(intptr_t)pvVar2;
  if (pvVar2 == (HANDLE)0x0) { uint32_t local_4 = 0xffffffff; _CxxThrowException(&local_4, (void*)&DAT_007149ac); }
  unaff_EBX[0x34] = 0x007109b0;
  unaff_EBX[0x35] = 0;
  pvVar2 = CreateMutexA((LPSECURITY_ATTRIBUTES)0x0, 0, (LPCSTR)0x0);
  unaff_EBX[0x35] = (uint32_t)(intptr_t)pvVar2;
  if (pvVar2 == (HANDLE)0x0) { uint32_t local_4 = 0xffffffff; _CxxThrowException(&local_4, (void*)&DAT_007149ac); }
  unaff_EBX[0x36] = 0x007109b0;
  unaff_EBX[0x37] = 0;
  pvVar2 = CreateMutexA((LPSECURITY_ATTRIBUTES)0x0, 0, (LPCSTR)0x0);
  unaff_EBX[0x37] = (uint32_t)(intptr_t)pvVar2;
  if (pvVar2 == (HANDLE)0x0) { uint32_t local_4 = 0xffffffff; _CxxThrowException(&local_4, (void*)&DAT_007149ac); }
  unaff_EBX[0x38] = 0x007109b0;
  unaff_EBX[0x39] = 0;
  pvVar2 = CreateMutexA((LPSECURITY_ATTRIBUTES)0x0, 0, (LPCSTR)0x0);
  unaff_EBX[0x39] = (uint32_t)(intptr_t)pvVar2;
  if (pvVar2 == (HANDLE)0x0) { uint32_t local_4 = 0xffffffff; _CxxThrowException(&local_4, (void*)&DAT_007149ac); }
  unaff_EBX[0x3a] = 0x007109b0;
  unaff_EBX[0x3b] = 0;
  pvVar2 = CreateMutexA((LPSECURITY_ATTRIBUTES)0x0, 0, (LPCSTR)0x0);
  unaff_EBX[0x3b] = (uint32_t)(intptr_t)pvVar2;
  if (pvVar2 == (HANDLE)0x0) { uint32_t local_4 = 0xffffffff; _CxxThrowException(&local_4, (void*)&DAT_007149ac); }
  unaff_EBX[0x3c] = 0x007109b0;
  unaff_EBX[0x3d] = 0;
  pvVar2 = CreateMutexA((LPSECURITY_ATTRIBUTES)0x0, 0, (LPCSTR)0x0);
  unaff_EBX[0x3d] = (uint32_t)(intptr_t)pvVar2;
  if (pvVar2 == (HANDLE)0x0) { uint32_t local_4 = 0xffffffff; _CxxThrowException(&local_4, (void*)&DAT_007149ac); }
  unaff_EBX[0x41] = 0;
  unaff_EBX[0x3f] = 0;
  unaff_EBX[0x40] = 0;
  unaff_EBX[0x3e] = 0x00711aa0;
  unaff_EBX[0x45] = 0;
  unaff_EBX[0x43] = 0;
  unaff_EBX[0x44] = 0;
  unaff_EBX[0x42] = 0x00711aa0;
  unaff_EBX[0x49] = 0;
  unaff_EBX[0x47] = 0;
  unaff_EBX[0x48] = 0;
  unaff_EBX[0x46] = 0x007119ec;
  unaff_EBX[0x4d] = 0;
  unaff_EBX[0x4b] = 0;
  unaff_EBX[0x4c] = 0;
  unaff_EBX[0x4a] = 0x007119ec;
  unaff_EBX[0x51] = 0;
  unaff_EBX[0x4f] = 0;
  unaff_EBX[0x50] = 0;
  unaff_EBX[0x4e] = 0x00711aa0;
  unaff_EBX[0x52] = 0x00711998;
  unaff_EBX[0x54] = 0;
  unaff_EBX[0x57] = 1;
  unaff_EBX[0x55] = 0;
  unaff_EBX[0x56] = 0;
  unaff_EBX[0x53] = 0;
  unaff_EBX[0x5b] = 0;
  unaff_EBX[0x59] = 0;
  unaff_EBX[0x5a] = 0;
  unaff_EBX[0x58] = 0x00711a64;
  unaff_EBX[0x5c] = 0x00711aac;
  unaff_EBX[0x5d] = 0x25;
  unaff_EBX[0x5f] = 0;
  puVar1 = (uint32_t*)FUN_00533c78(0x94);
  unaff_EBX[0x5e] = (uint32_t)(intptr_t)puVar1;
  for (uint32_t uVar4 = unaff_EBX[0x5d] & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
    puVar1[0] = 0;
    puVar1 = puVar1 + 1;
  }
  for (int32_t iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(uint8_t*)puVar1 = 0;
    puVar1 = (uint32_t*)((intptr_t)puVar1 + 1);
  }
  unaff_EBX[0x5c] = 0x00711ae4;
  pvVar2 = (HANDLE)(intptr_t)unaff_EBX[0x30];
  if (DAT_00726c28 != 0xffffffff) {
    LPVOID pvVar3 = TlsGetValue(DAT_00726c28);
    if (pvVar3 != (LPVOID)0x0) { FUN_004fac10(); goto done; }
  }
  WaitForSingleObject(pvVar2, 0xffffffff);
done:
  unaff_EBX[0x1c] = 0;
  unaff_EBX[0x26] = DAT_00727430;
  unaff_EBX[0x27] = DAT_00727434;
  unaff_EBX[0x28] = DAT_00727438;
  unaff_EBX[0x23] = unaff_EBX[0x26];
  unaff_EBX[0x24] = unaff_EBX[0x27];
  unaff_EBX[0x25] = unaff_EBX[0x28];
  ReleaseMutex((HANDLE)(intptr_t)unaff_EBX[0x30]);
  FUN_004f5670();
  unaff_EBX[0x57] = 100;
}

// 0x518450 — observed shape
void FUN_00518450(void* self, uint32_t param_1) {
  uint32_t* in_EAX = (uint32_t*)(intptr_t)self;
  FUN_004fa8e0(0, 0);
  in_EAX[0] = 0x007119f8;
  in_EAX[0xd] = 0x007109b0;
  in_EAX[0xe] = 0;
  HANDLE pvVar1 = CreateMutexA((LPSECURITY_ATTRIBUTES)0x0, 0, (LPCSTR)0x0);
  in_EAX[0xe] = (uint32_t)(intptr_t)pvVar1;
  if (pvVar1 == (HANDLE)0x0) {
    param_1 = 0xffffffff;
    _CxxThrowException(&param_1, (void*)&DAT_007149ac);
  }
  in_EAX[0x12] = 0;
  in_EAX[0x10] = 0;
  in_EAX[0x11] = 0;
  in_EAX[0xf] = 0x00711a70;
  in_EAX[0x14] = 0x00711ac8;
  in_EAX[0x15] = 0x25;
  in_EAX[0x17] = 0;
  uint32_t* puVar2 = (uint32_t*)FUN_00533c78(0x94);
  in_EAX[0x16] = (uint32_t)(intptr_t)puVar2;
  for (uint32_t uVar3 = in_EAX[0x15] & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
    puVar2[0] = 0;
    puVar2 = puVar2 + 1;
  }
  for (int32_t iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(uint8_t*)puVar2 = 0;
    puVar2 = (uint32_t*)((intptr_t)puVar2 + 1);
  }
  in_EAX[0x14] = 0x00711b00;
  in_EAX[0x18] = 0x00711a10;
  in_EAX[0x19] = 0x25;
  in_EAX[0x1b] = 0;
  puVar2 = (uint32_t*)FUN_00533c78(0x94);
  in_EAX[0x1a] = (uint32_t)(intptr_t)puVar2;
  for (uint32_t uVar3 = in_EAX[0x19] & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
    puVar2[0] = 0;
    puVar2 = puVar2 + 1;
  }
  for (int32_t iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(uint8_t*)puVar2 = 0;
    puVar2 = (uint32_t*)((intptr_t)puVar2 + 1);
  }
  in_EAX[0x18] = 0x00711a30;
  in_EAX[0x13] = param_1;
}

