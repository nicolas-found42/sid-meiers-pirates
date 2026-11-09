#include <cstdint>
#include <cstddef>
#include <windows.h>

extern int* DAT_008ecd7c;
extern int DAT_00727080;
extern float FUN_00531070(unsigned char param);
extern int FUN_005f0ddc();
extern int FUN_004a95b0(int param);

// 0x5310c0 — observed shape
void FUN_005310c0(void* self) {
  int iVar1 = *DAT_008ecd7c;
  if (*(char*)((char*)self + 0x18) == '\0') {
    float fVar2 = FUN_00531070(*(unsigned char*)((char*)self + 0x59));
    auto fn = (void(__cdecl*)(int, int, float))*(void**)(iVar1 + 0x60);
    fn(0, *(int*)((char*)self + 0xc), fVar2);
    return;
  }
  float fVar2 = FUN_00531070(*(unsigned char*)((char*)self + 0x59));
  auto fn = (void(__cdecl*)(int, int, float))*(void**)(iVar1 + 0x60);
  fn(2, *(int*)((char*)self + 0x10), fVar2);
  return;
}

// 0x531220 — observed shape
void FUN_00531220(void* self) {
  int* ecx = (int*)self;
  if (ecx[0x17] == 0) {
    return;
  }
  (*(void(__cdecl**)(void))(*ecx + 0xd8))();
  (*(void(__cdecl**)(void))(*ecx + 0xdc))();
  // WARNING: Could not recover jumptable at 0x00531241. Treating indirect jump as call.
  (*(void(__cdecl**)(void))(*ecx + 0xe0))();
  return;
}

// 0x5314e0 — observed shape
void FUN_005314e0(void* self) {
  int* in_ECX = (int*)self;
  char cVar5 = (*(char(__cdecl**)(int))(*in_ECX + 0x94))(4);
  if (cVar5 == '\0') {
    int iVar7 = in_ECX[0x17];
    bool bVar3 = true;
    bool bVar4 = true;
    if ((*(int*)(iVar7 + 0x1c) == -1) || (*(int*)(iVar7 + 0x20) == -1) || (*(int*)(iVar7 + 0x20) - *(int*)(iVar7 + 0x1c) < 0)) {
      bVar3 = false;
    }
    if ((*(int*)(iVar7 + 0x24) == -1) || (*(int*)(iVar7 + 0x28) == -1) || (*(int*)(iVar7 + 0x28) - *(int*)(iVar7 + 0x24) < 0)) {
      bVar4 = false;
    }
    iVar7 = DAT_00727080;
    float fStack_c = 0.0f;
    float fStack_8 = 0.0f;
    float extraout_ST0 = 0.0f;
    if (bVar3) {
      iVar7 = DAT_00727080 * 0x343fd + 0x269ec3;
      int iVar1 = in_ECX[0x17];
      DAT_00727080 = iVar7;
      int iVar6 = FUN_005f0ddc();
      float fVar2 = (float)iVar6;
      if (iVar6 < 0) {
        fVar2 = fVar2 + 4.2949673e+09f;
      }
      fStack_c = (float)-*(int*)(iVar1 + 0x20);
      fStack_8 = ((float)(int)fStack_c + fVar2 + 100.0f) * 0.005f;
      extraout_ST0 = fStack_8;
    }
    if (bVar4) {
      DAT_00727080 = iVar7 * 0x343fd + 0x269ec3;
      iVar7 = FUN_005f0ddc();
      float fVar8 = (float)iVar7;
      if (iVar7 < 0) {
        fVar8 = fVar8 + 4.2949673e+09f;
      }
      fStack_c = (float)((extraout_ST0 - fVar8) + 100.0f) * 0.005f;
    }
    if (bVar3) {
      if ((bVar4) && (iVar7 = FUN_004a95b0(2), iVar7 != 0)) {
        in_ECX[10] = (int)fStack_c;
        return;
      }
      in_ECX[10] = (int)fStack_8;
      return;
    }
    if (!bVar4) {
      in_ECX[10] = 0x3f000000;
      return;
    }
    in_ECX[10] = (int)fStack_c;
  }
  return;
}

// 0x531830 — observed shape
void FUN_00531830(void* self, uint32_t param_1) {
  *(uint32_t*)((char*)self + 0x34) = param_1;
  return;
}

// 0x531940 — observed shape
int FUN_00531940(void* self_esi, void* self_edi) {
  int* unaff_ESI = (int*)self_esi;
  int* unaff_EDI = (int*)self_edi;
  int iVar2 = 0;
  if ((uint32_t)unaff_EDI[8] < (uint32_t)unaff_ESI[8]) {
    iVar2 = -1;
  } else if ((uint32_t)unaff_ESI[8] < (uint32_t)unaff_EDI[8]) {
    iVar2 = 1;
  }
  char cVar1 = (*(char(__cdecl**)(void))(*unaff_EDI + 0x40))();
  if (cVar1 != '\0') {
    iVar2 = iVar2 + 1;
  }
  cVar1 = (*(char(__cdecl**)(void))(*unaff_ESI + 0x40))();
  if (cVar1 != '\0') {
    iVar2 = iVar2 + -1;
  }
  float fVar3 = (*(float(__cdecl**)(void))(*unaff_EDI + 0xa8))();
  float fVar4 = (*(float(__cdecl**)(void))(*unaff_ESI + 0xa8))();
  fVar3 = (float)fVar3;
  if (!(fVar4 < fVar3) && !(fVar4 == fVar3)) {
    return (iVar2 + -1 < 0) ? 1 : 0;
  }
  fVar3 = (*(float(__cdecl**)(void))(*unaff_EDI + 0xa8))();
  fVar4 = (*(float(__cdecl**)(void))(*unaff_ESI + 0xa8))();
  fVar3 = (float)fVar3;
  if (fVar4 < fVar3) {
    iVar2 = iVar2 + 1;
  }
  return (iVar2 < 0) ? 1 : 0;
}

// ---------------------------------------------------------------------------
// Shared externs and forward declarations for the appended functions.
// ---------------------------------------------------------------------------
extern uint32_t PTR_LAB_007133c8;
extern uint32_t PTR_LAB_00713268;
extern int DAT_008ecd78;
extern unsigned char DAT_008ed2c0[];
extern void FUN_0052bc70(void);
extern void FUN_0052bd90(void);
extern int FUN_0052ff60(const char* msg);
extern void FUN_00527cc0(void);
extern void FUN_005292e0(void);
extern void FUN_005333e0(uint32_t param);

int FUN_00532290(void* self);
void FUN_00531e50(void* self, const void* src);
void* FUN_00531bb0(void* out, uint32_t which, float scale);

// 0x531a30 — observed shape
void FUN_00531a30(void* self) {
  uint32_t* unaff_EDI = (uint32_t*)self;
  unaff_EDI[0] = (uint32_t)(uintptr_t)&PTR_LAB_007133c8;
  unaff_EDI[0x22] = 0;
  unaff_EDI[0x23] = 0;
  unaff_EDI[0x24] = 0;
  unaff_EDI[0x25] = 0;
  unaff_EDI[0x26] = 0;
  unaff_EDI[0x27] = 0;
  unaff_EDI[0x28] = 0;
  unaff_EDI[0x29] = 0;
  FUN_0052bc70();
  unaff_EDI[0x2b] = 0;
  FUN_0052bd90();
  *(uint8_t*)(unaff_EDI + 0x31) = 0;
  unaff_EDI[2] = 0;
  unaff_EDI[3] = 0xffffffff;
  unaff_EDI[4] = 0xffffffff;
  FUN_0052bd90();
  *(uint8_t*)((char*)unaff_EDI + 199) = 0;
  *(uint8_t*)((char*)unaff_EDI + 0xc6) = 0;
  unaff_EDI[0x32] = 0;
  *(uint8_t*)((char*)unaff_EDI + 0xc5) = 0;
  return;
}

// 0x531ac0 — observed shape
void FUN_00531ac0(void* self) {
  uint32_t* in_ECX = (uint32_t*)self;
  in_ECX[0] = (uint32_t)(uintptr_t)&PTR_LAB_007133c8;
  FUN_00532290(self);
  *(uint8_t*)(in_ECX + 0x31) = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0xffffffff;
  in_ECX[4] = 0xffffffff;
  FUN_0052bd90();
  *(uint8_t*)((char*)in_ECX + 199) = 0;
  *(uint8_t*)((char*)in_ECX + 0xc6) = 0;
  in_ECX[0x32] = 0;
  *(uint8_t*)((char*)in_ECX + 0xc5) = 0;
  uint32_t* puVar2 = (uint32_t*)in_ECX[0x2b];
  if (puVar2 != (uint32_t*)0x0) {
    int* piVar1 = (int*)(puVar2 + 1);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (*(void(__cdecl**)(int))(uintptr_t)(*puVar2))(1);
    }
  }
  in_ECX[0] = (uint32_t)(uintptr_t)&PTR_LAB_00713268;
  return;
}

// 0x531b30 — observed shape
bool FUN_00531b30(void* self) {
  int unaff_ESI = (int)self;
  char cVar2 = (*(char(__cdecl**)(void))(uintptr_t)(DAT_008ecd78 + 0x18))();
  if (cVar2 != '\0') {
    int* piVar1 = *(int**)(unaff_ESI + 8);
    int iVar3 = (*(int(__cdecl**)(uint32_t))(*piVar1 + 0x10))(*(uint32_t*)(unaff_ESI + 0xc0));
    if (iVar3 != 0) {
      piVar1 = *(int**)(unaff_ESI + 8);
      int iVar3b = *DAT_008ecd7c;
      uint32_t uVar4 = (*(uint32_t(__cdecl**)(uint32_t, int))(*piVar1 + 0x14))(
          *(uint32_t*)(unaff_ESI + 0xc0), 0);
      uVar4 = (*(uint32_t(__cdecl**)(uint32_t, uint32_t))(*piVar1 + 0x10))(
          *(uint32_t*)(unaff_ESI + 0xc0), uVar4);
      iVar3b = (*(int(__cdecl**)(int, uint32_t))(uintptr_t)(iVar3b + 0x10))(1, uVar4);
      *(int*)(unaff_ESI + 0xc) = iVar3b;
      return iVar3b != -1;
    }
  }
  return false;
}

// 0x531bb0 — observed shape
// Ghidra exposes the hidden float3 return buffer as `unaff_retaddr`; the switch
// selector (miss-typed as float* in the listing) is the second argument and the
// recursive calls pass (out, selector, scale) in that observed order.
void* FUN_00531bb0(void* out_param, uint32_t which, float scale) {
  float* unaff_retaddr = (float*)out_param;
  float fStack_1c = 0.0f;
  float fStack_18 = 0.0f;
  float fStack_14 = 0.0f;
  float fStack_10 = 0.0f;
  float fStack_c = 0.0f;

  int iVar1 = (*(int(__cdecl**)(void))(uintptr_t)(DAT_008ecd78 + 0x38))();
  if (iVar1 == 0) {
    unaff_retaddr[0] = 0.0f;
    unaff_retaddr[1] = 0.0f;
    unaff_retaddr[2] = 0.0f;
    return unaff_retaddr;
  }
  int* piVar2 = (int*)(*(int(__cdecl**)(void))(uintptr_t)(DAT_008ecd78 + 0x38))();
  (*(void(__cdecl**)(float*))(*piVar2 + 0x20))(&fStack_18);
  switch (which) {
    case 1: {
      int i = FUN_004a95b0(10);
      return FUN_00531bb0(unaff_retaddr, (uint32_t)(i + 2), scale);
    }
    case 2:
      fStack_10 = 0.0f;
      fStack_c = 0.0f;
      break;
    case 3:
      fStack_10 = 0.0f;
      fStack_c = 1.0f;
      break;
    case 4:
      fStack_10 = 0.0f;
      fStack_c = -1.0f;
      break;
    case 5:
      fStack_10 = -1.0f;
      fStack_c = -1.0f;
      break;
    case 6:
      fStack_10 = 1.0f;
      fStack_c = -1.0f;
      break;
    case 7:
      fStack_10 = -1.0f;
      fStack_c = 0.0f;
      break;
    case 8:
      fStack_10 = 1.0f;
      fStack_c = 0.0f;
      break;
    case 9:
      fStack_10 = -1.0f;
      fStack_c = 1.0f;
      break;
    case 0xa:
      fStack_10 = 1.0f;
      fStack_c = 1.0f;
      break;
    case 0xb: {
      int i = FUN_004a95b0(3);
      return FUN_00531bb0(unaff_retaddr, (uint32_t)(i + 4), scale);
    }
    default:
      unaff_retaddr[0] = fStack_1c;
      unaff_retaddr[1] = fStack_18;
      unaff_retaddr[2] = fStack_14;
      return unaff_retaddr;
  }
  unaff_retaddr[0] = fStack_10 * scale + fStack_1c;
  unaff_retaddr[1] = fStack_18 + fStack_c * scale;
  unaff_retaddr[2] = fStack_14 + scale * 0.0f;
  return unaff_retaddr;
}

// 0x531db0 — observed shape
void FUN_00531db0(void* self, uint32_t param_1) {
  int* in_ECX = (int*)self;
  char cVar1 = (*(char(__cdecl**)(void))(*in_ECX + 0x44))();
  if (cVar1 == '\0') {
    in_ECX[0xc] = in_ECX[9];
    in_ECX[0xd] = in_ECX[10];
    in_ECX[0xe] = in_ECX[0xb];
    (*(void(__cdecl**)(uint32_t))(*in_ECX + 0xf8))(param_1);
    (*(void(__cdecl**)(void))(*in_ECX + 200))();
    FUN_005333e0(param_1);
    (*(void(__cdecl**)(void))(*in_ECX + 0xbc))();
  }
  return;
}

// 0x531e10 — observed shape
void FUN_00531e10(void* self, const void* param_1) {
  int in_ECX = (int)self;
  if (*(char*)(in_ECX + 0xc4) == '\0') {
    // The copy destination of FUN_00531e50 arrives in EBX from the caller;
    // the listing does not materialise it, so the current object is used.
    FUN_00531e50(self, param_1);
    *(uint8_t*)(in_ECX + 0xc4) = 1;
    return;
  }
  FUN_0052ff60("Sound object is already initialized");
  return;
}

// 0x531e50 — observed shape
// EBX is the destination object (copy-assignment of the sound-parameter block).
void FUN_00531e50(void* self, const void* src_param) {
  uint32_t* unaff_EBX = (uint32_t*)self;
  const uint32_t* param_1 = (const uint32_t*)src_param;
  unaff_EBX[0] = param_1[0];
  *(uint8_t*)(unaff_EBX + 1) = *(const uint8_t*)(param_1 + 1);
  unaff_EBX[2] = param_1[2];
  unaff_EBX[3] = param_1[3];
  const uint32_t* puVar3 = param_1 + 4;
  uint32_t* puVar4 = unaff_EBX + 4;
  for (int iVar2 = 0x21; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  *(uint8_t*)(unaff_EBX + 0x25) = *(const uint8_t*)(param_1 + 0x25);
  *(uint8_t*)((int)(uintptr_t)unaff_EBX + 0x95) = *(const uint8_t*)((int)(uintptr_t)param_1 + 0x95);
  uint32_t* puVar5 = (uint32_t*)unaff_EBX[0x26];
  if (puVar5 != (uint32_t*)param_1[0x26]) {
    if (puVar5 != (uint32_t*)0x0) {
      int* piVar1 = (int*)(puVar5 + 1);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(void(__cdecl**)(int))(uintptr_t)(*puVar5))(1);
      }
    }
    int iVar2 = (int)param_1[0x26];
    unaff_EBX[0x26] = (uint32_t)iVar2;
    if (iVar2 != 0) {
      *(int*)(iVar2 + 4) = *(int*)(iVar2 + 4) + 1;
    }
  }
  unaff_EBX[0x27] = param_1[0x27];
  unaff_EBX[0x28] = param_1[0x28];
  unaff_EBX[0x29] = param_1[0x29];
  unaff_EBX[0x2a] = param_1[0x2a];
  unaff_EBX[0x2b] = param_1[0x2b];
  return;
}

// 0x531f10 — observed shape
void FUN_00531f10(void* self) {
  int* in_ECX = (int*)self;
  (*(void(__cdecl**)(void))(*in_ECX + 0xc))();
  *(uint8_t*)(in_ECX + 0x31) = 0;
  in_ECX[2] = 0;
  in_ECX[3] = -1;
  in_ECX[4] = -1;
  FUN_0052bd90();
  *(uint8_t*)((int)(uintptr_t)in_ECX + 199) = 0;
  *(uint8_t*)((int)(uintptr_t)in_ECX + 0xc6) = 0;
  in_ECX[0x32] = 0;
  *(uint8_t*)((int)(uintptr_t)in_ECX + 0xc5) = 0;
  return;
}

// 0x531f90 — observed shape
int FUN_00531f90(void* self, uint32_t param_1) {
  int* in_ECX = (int*)self;
  if ((char)DAT_008ed2c0[in_ECX[5] * 0x4c + 0x48] == '\0') {
    char cVar1 = (*(char(__cdecl**)(void))(uintptr_t)(DAT_008ecd78 + 0x18))();
    if (cVar1 != '\0') {
      cVar1 = (*(char(__cdecl**)(void))(*in_ECX + 0x10))();
      if (cVar1 == '\0') {
        return (*(int(__cdecl**)(uint32_t))(*in_ECX + 0xa4))(param_1);
      }
      return 1;
    }
  }
  return 0;
}

// 0x532230 — observed shape
// The listing computes the squared distance with x87 float10; the observed
// result is returned here as float. The virtual call at +0x20 receives the
// stack pair it later reads, and the third component subtracts the raw stack
// address exactly as the pseudocode shows.
float FUN_00532230(void* self) {
  int in_ESI = (int)self;
  float fStack_c = 0.0f;
  float fStack_8 = 0.0f;
  int* piVar1 = (int*)(*(int(__cdecl**)(void))(uintptr_t)(DAT_008ecd78 + 0x38))();
  (*(void(__cdecl**)(void*))(*piVar1 + 0x20))(&fStack_c);
  float fVar2 = *(float*)(in_ESI + 0x2c) - fStack_8;
  float fVar3 = *(float*)(in_ESI + 0x28) - fStack_c;
  float fVar4 = *(float*)(in_ESI + 0x24) - (float)(uintptr_t)&fStack_c;
  float fVar5 = fVar2 * fVar2 + fVar3 * fVar3 + fVar4 * fVar4;
  if (fVar5 < 0.0f) {
    fVar5 = fVar5 * -1.0f;
  }
  return fVar5;
}

// 0x532290 — observed shape
int FUN_00532290(void* self) {
  int in_ECX = (int)self;
  char cVar1 = (*(char(__cdecl**)(void))(uintptr_t)(DAT_008ecd78 + 0x18))();
  if ((cVar1 == '\0') || (*(char*)(in_ECX + 0xc5) == '\0')) {
    return 0;
  }
  uint32_t uVar2;
  int uVar1;
  if (*(char*)(in_ECX + 0x18) == '\0') {
    uVar2 = *(uint32_t*)(in_ECX + 0xc);
    uVar1 = 1;
  } else {
    uVar2 = *(uint32_t*)(in_ECX + 0x10);
    uVar1 = 3;
  }
  (*(void(__cdecl**)(int, uint32_t))(uintptr_t)(*DAT_008ecd7c + 0x14))(uVar1, uVar2);
  FUN_00527cc0();
  FUN_005292e0();
  *(uint8_t*)(in_ECX + 0xc5) = 0;
  return 1;
}

// 0x5323f0 — observed shape
int FUN_005323f0(void* self) {
  int* in_ECX = (int*)self;
  char cVar1 = (*(char(__cdecl**)(void))(*in_ECX + 0x40))();
  if ((cVar1 == '\0') && (cVar1 = (*(char(__cdecl**)(void))(*in_ECX + 0x44))(), cVar1 == '\0')) {
    return 1;
  }
  if (in_ECX[2] == 0) {
    return FUN_0052ff60("Cannot play sound, buffer and/or handle is NULL.");
  }
  if ((char)in_ECX[6] == '\0') {
    (*(void(__cdecl**)(int, int))(uintptr_t)(*DAT_008ecd7c + 0x3c))(1, in_ECX[3]);
    return 1;
  }
  (*(void(__cdecl**)(int, int))(uintptr_t)(*DAT_008ecd7c + 0x3c))(3, in_ECX[4]);
  return 1;
}

// 0x532570 — observed shape
void FUN_00532570(void* self) {
  int* in_ECX = (int*)self;
  *(uint8_t*)((int)(uintptr_t)in_ECX + 0xc6) = 0;
  float fVar2 = (*(float(__cdecl**)(void))(uintptr_t)(DAT_008ecd78 + 0x14))();
  in_ECX[0x2e] = (int)fVar2;
  char cVar1 = (*(char(__cdecl**)(void))(*in_ECX + 0x58))();
  if ((cVar1 == '\0') &&
      ((in_ECX[0x2c] == 0 || (*(char*)(in_ECX[0x2c] + 0x1c) == '\0')))) {
    (*(void(__cdecl**)(int))(*in_ECX + 0x5c))(1);
  }
  return;
}

// 0x5325c0 — observed shape
// Ghidra's EAX high-byte shuffles (uint3 / CONCAT31 / <<8) are artefacts of
// the boolean result; the observed flow reduces to the two return paths below.
int FUN_005325c0(void* self) {
  int in_ECX = (int)self;
  if (*(char*)(in_ECX + 0x18) == '\0') {
    if (*(int**)(in_ECX + 8) != (int*)0x0) {
      int* piVar = *(int**)(in_ECX + 8);
      int iVar1 = (*(int(__cdecl**)(uint32_t))(*piVar + 0x10))(*(uint32_t*)(in_ECX + 0xc0));
      if ((iVar1 != 0) && (*(char*)(in_ECX + 0xc6) != '\0')) {
        return 1;
      }
    }
    return 0;
  }
  if (*(char*)(in_ECX + 0xc6) != '\0') {
    return 1;
  }
  return 0;
}

// 0x532690 — observed shape
int FUN_00532690(void* self) {
  FUN_00531e50(self, (const void*)((char*)self + 0x14));
  return 1;
}
