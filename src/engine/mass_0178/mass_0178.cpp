// mass_0178 — reconstructed C++ candidates from the Ghidra 12.2 pseudocode corpus
// Target: Sid Meier's Pirates! (2004), PE32 i386
// Source: analysis/pseudocode/functions/0x579070.c .. 0x57a3f0.c (verbatim listings)
#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---- helper / global declarations ----
extern void FUN_005828c0();
extern void operator_delete__(void*);
extern void operator_delete(void*);
extern void FUN_00547d10();
extern void* thunk_FUN_00533c78(size_t);
extern void FUN_00497420(void*);
extern void FUN_005edba0();
extern void FUN_00555f70(void*);
extern void* FUN_00555b90(void*);
extern void FUN_0055ec90(void*, float, void*, void*);
extern void FUN_00520da0(void*);
extern uint32_t FUN_00538360(uint32_t);
extern void FUN_00538430(void*);
extern void FUN_00545950(uint32_t);
extern void FUN_004b1100();
extern void FUN_004b10d0();
extern void FUN_005e1490();
extern void FUN_006b34a0(int);
extern void FUN_005606f0(uint32_t, void*);
extern void FUN_00540e40(void*);
extern void FUN_0057e9b0(void*, void*);
extern void FUN_0057eb00(void*, void*);
extern void FUN_0057ed70(void*, void*);
extern void FUN_0053cc20(void*);
extern void* FUN_0053c9e0(void*, float);
extern void* FUN_0053ca60(void*, void*);
extern void FUN_0053c8d0(void*, void*);
extern void FUN_0056a050(void*, float, int, int, int, void*);
extern uint32_t FUN_00555c50(void*, void*);
extern void FUN_00555bc0(void*, uint32_t);
extern "C" int strncmp(const char*, const char*, size_t);
extern "C" int strcmp(const char*, const char*);

extern void* PTR_FUN_006c47b8;
extern void* PTR_FUN_006c4868;
extern void* PTR_LAB_006c4840;
extern void* PTR_FUN_006c484c;
extern uint32_t DAT_007289e0;
extern uint32_t DAT_00727868;
extern uint8_t DAT_00728a3c;

// Virtual-call shapes observed in this batch (original convention is thiscall;
// receiver is passed explicitly here).
typedef void (__cdecl* FnV_U32)(uint32_t);
typedef void (__cdecl* FnV_PtrU32)(void*, uint32_t);
typedef void* (__cdecl* FnPtr_Void)(void);
typedef uint32_t (__cdecl* FnU32_U32)(uint32_t);
typedef long double (__cdecl* FnF_U32)(uint32_t);

// Ghidra coerces undefined4 fields to float; the listing means bit reinterpretation.
static inline float as_f32(uint32_t v) {
  union { uint32_t u; float f; } x;
  x.u = v;
  return x.f;
}
static inline float abs_f32(float v) { return v < 0.0f ? -v : v; }

// 0x579070 — observed shape
void FUN_00579070(void* self) {
  uint32_t* ecx = (uint32_t*)self;
  int iVar1 = (int)ecx[5];
  ecx[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c47b8;
  if (iVar1 != 0) {
    int iVar2 = *(int*)(iVar1 + -4);
    if (-1 < iVar2 + -1) {
      do {
        FUN_005828c0();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    operator_delete__((void*)(iVar1 + -4));
  }
  FUN_00547d10();
}

// 0x579100 — observed shape
void FUN_00579100(void* self, char* param_1) {
  uint32_t* ecx = (uint32_t*)self;
  char cVar1;
  char* pcVar2;
  operator_delete__(*(void**)((uint8_t*)ecx + 0x10));
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = (char*)thunk_FUN_00533c78((size_t)(pcVar2 + (1 - (int)(param_1 + 1))));
  *(char**)((uint8_t*)ecx + 0x10) = pcVar2;
  do {
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    *pcVar2 = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00497420(*(void**)((uint8_t*)ecx + 0x10));
}

// 0x579160 — observed shape
void FUN_00579160(uint32_t* param_1) {
  *param_1 = DAT_007289e0;
  DAT_007289e0 = (uint32_t)(uintptr_t)param_1;
}

// 0x5791a0 — observed shape
void FUN_005791a0(void* self, uint8_t param_1) {
  uint32_t* ecx = (uint32_t*)self;
  *ecx = (uint32_t)(uintptr_t)&PTR_FUN_006c4868;
  FUN_005edba0();
  *ecx = (uint32_t)(uintptr_t)&PTR_LAB_006c4840;
  if ((param_1 & 1) != 0) {
    operator_delete(ecx);
  }
}

// 0x5791d0 — observed shape
void FUN_005791d0(void* self, float param_1) {
  uint8_t* ecx = (uint8_t*)self;
  float fVar2, fVar3, fVar4, fVar5, fVar6, fVar7, fVar8, fVar9;
  float fVar12 = 1.0f - param_1;
  uint32_t* puVar15 = *(uint32_t**)(*(int*)(ecx + 0x84) + 100);
  uint32_t* puVar13 = *(uint32_t**)(ecx + 100);
  float local_40, local_3c, local_38, local_34;
  float local_30, local_2c, local_28, local_24;
  uint8_t local_20[16];
  uint8_t local_10[16];

  while (puVar15 != 0 && puVar13 != 0) {
    uint32_t* puVar16;
    uint32_t* puVar10;
    int* piVar1;
    if (puVar15 == (uint32_t*)0x0) {
      puVar16 = (uint32_t*)0x0;
      puVar15 = (uint32_t*)0x0;
    } else {
      puVar16 = puVar15 + 2;
      puVar15 = (uint32_t*)*puVar15;
    }
    piVar1 = (int*)(puVar13 + 2);
    puVar10 = (uint32_t*)*puVar13;
    FUN_00555f70(puVar16 + 1);
    FUN_00555f70(puVar13 + 3);
    if (local_30 * local_40 + local_2c * local_3c + local_28 * local_38 + local_24 * local_34 < 0.0f) {
      float* pfVar14 = (float*)FUN_00555b90(local_10);
      local_40 = pfVar14[0];
      local_3c = pfVar14[1];
      local_38 = pfVar14[2];
      local_34 = pfVar14[3];
    }
    FUN_0055ec90(local_20, param_1, &local_40, &local_30);
    fVar2 = as_f32(puVar13[0xc]);
    fVar3 = as_f32(puVar13[0xd]);
    fVar4 = as_f32(puVar13[0xe]);
    fVar5 = as_f32(puVar16[10]);
    fVar6 = as_f32(puVar16[0xb]);
    fVar7 = as_f32(puVar16[0xc]);
    fVar8 = as_f32(puVar13[0xf]);
    fVar9 = as_f32(puVar16[0xd]);
    FUN_00520da0((void*)(*piVar1 + 0x38));
    {
      int iVar11 = *piVar1;
      *(float*)(iVar11 + 0x5c) = fVar12 * fVar5 + param_1 * fVar2;
      *(float*)(iVar11 + 0x60) = fVar12 * fVar6 + param_1 * fVar3;
      *(float*)(iVar11 + 100) = fVar12 * fVar7 + param_1 * fVar4;
      *(float*)(*piVar1 + 0x68) = abs_f32(fVar12 * fVar9 + param_1 * fVar8);
    }
    puVar13 = puVar10;
  }
}

// 0x579370 — observed shape
uint32_t FUN_00579370(void* self, uint32_t param_1) {
  uint8_t* ecx = (uint8_t*)self;
  uint32_t uVar1 = FUN_00538360(param_1);
  if ((char)uVar1 == '\0') {
    return uVar1;
  }
  if (*(uint32_t*)(ecx + 0x70) != 0) {
    uint32_t vtbl = *(uint32_t*)(*(uint32_t*)(ecx + 0x70));
    ((FnV_U32)(*(uint32_t*)(uintptr_t)(vtbl + 0x14)))(param_1);
  }
  uint32_t uVar3 = 0;
  uint32_t uVar2 = 0;
  if (*(int*)(ecx + 0x3c) != 0) {
    do {
      uint32_t obj = *(uint32_t*)(*(int*)(ecx + 0x34) + uVar3 * 4);
      uint32_t vtbl = *(uint32_t*)(uintptr_t)obj;
      ((FnV_U32)(*(uint32_t*)(uintptr_t)(vtbl + 0x14)))(param_1);
      uVar2 = *(uint32_t*)(ecx + 0x3c);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  return (uVar2 & 0xffffff00u) | 1u;
}

// 0x5793c0 — observed shape
void FUN_005793c0(void* self, int* param_1) {
  uint8_t* ecx = (uint8_t*)self;
  uint8_t auStack_a4[128];
  uint32_t uVar1;
  FUN_00538430(param_1);
  FUN_00545950(*(uint32_t*)(ecx + 0xc));
  ((FnV_PtrU32)(*(uint32_t*)(*(uint32_t*)(uintptr_t)param_1[0x58] + 0xc)))(ecx + 0x74, 4);
  ((FnV_U32)(*(uint32_t*)(uintptr_t)(*param_1 + 0x2c)))(*(uint32_t*)(ecx + 0x70));
  ((FnV_PtrU32)(*(uint32_t*)(*(uint32_t*)(uintptr_t)param_1[0x58] + 0xc)))(auStack_a4 + 0x9c, 4);
  uVar1 = 0;
  if (*(int*)(ecx + 0x3c) != 0) {
    do {
      FUN_00545950(*(uint32_t*)(*(int*)(ecx + 0x1c) + uVar1 * 4));
      ((FnV_U32)(*(uint32_t*)(uintptr_t)(*param_1 + 0x2c)))(
          *(uint32_t*)(*(int*)(ecx + 0x34) + uVar1 * 4));
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint32_t*)(ecx + 0x3c));
  }
}

// 0x5795f0 — observed shape
void FUN_005795f0(uint32_t* param_1) {
  *(uint8_t*)(param_1 + 2) = 0;
  FUN_004b1100();
  param_1[1] = 0;
  *param_1 = DAT_00727868;
  DAT_00727868 = (uint32_t)(uintptr_t)param_1;
  FUN_004b10d0();
}

// 0x579630 — observed shape
void FUN_00579630(void* self, uint8_t param_1) {
  uint32_t* ecx = (uint32_t*)self;
  *ecx = (uint32_t)(uintptr_t)&PTR_FUN_006c484c;
  FUN_005e1490();
  operator_delete__((void*)ecx[2]);
  if ((param_1 & 1) != 0) {
    operator_delete(ecx);
  }
}

// 0x579670 — observed shape
uint32_t FUN_00579670(void* self, int* param_1) {
  uint8_t* ecx = (uint8_t*)self;
  int* piVar2;
  FUN_006b34a0(*(int*)(ecx + 0x24));
  piVar2 = param_1;
  uint32_t uVar4 = 0;
  uint32_t uVar3 = 0;
  if (*(int*)(ecx + 0x24) != 0) {
    do {
      int iVar1 = *(int*)(*(int*)(ecx + 0x1c) + uVar4 * 4);
      if (iVar1 != 0) {
        param_1 = (int*)(uintptr_t)((FnU32_U32)(*(uint32_t*)(uintptr_t)(*piVar2 + 0x40)))(iVar1);
        if (param_1 == (int*)0x0) {
          return 0;
        }
        if (*(uint32_t*)(ecx + 0x50) <= uVar4) {
          FUN_006b34a0(*(int*)(ecx + 0x5c) + uVar4);
        }
        FUN_005606f0(uVar4, &param_1);
      }
      uVar3 = *(uint32_t*)(ecx + 0x24);
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar3);
  }
  return (uVar3 & 0xffffff00u) | 1u;
}

// 0x5796f0 — observed shape
void FUN_005796f0(void* self) {
  uint8_t* ecx = (uint8_t*)self;
  if (*(int*)(ecx + 0x54) != 0) {
    uint32_t uVar3 = 0;
    do {
      int* piVar2 = *(int**)(*(int*)(ecx + 0x34) + uVar3 * 4);
      if (piVar2 != (int*)0x0) {
        piVar2[1] = piVar2[1] + 1;
      }
      FUN_00540e40(piVar2);
      ((FnV_U32)(*(uint32_t*)(uintptr_t)(*piVar2 + 0x40)))(0);
      {
        int* piVar1 = piVar2 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          ((FnV_U32)(*(uint32_t*)(uintptr_t)*piVar2))(1);
        }
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint32_t*)(ecx + 0x54));
  }
}

// 0x579740 — observed shape
long double FUN_00579740(float* param_1, uint32_t param_2) {
  uint8_t* obj = (uint8_t*)param_1;
  int* piVar2;
  long double fVar13, fVar14, fVar15;
  float fVar17;
  float* pfVar8;
  float* pfVar6;
  float* pfVar7;
  float* pfArg;
  float* pfVar18;
  float* pfStack_10;
  float* pfStack_c;
  uint32_t uStack_14;
  uint32_t uVar3;
  bool bVar11, bVar12;

  piVar2 = *(int**)(*(int*)(obj + 0x34) + *(int*)(obj + 0x74) * 4);
  fVar13 = (long double)((FnF_U32)(*(uint32_t*)(uintptr_t)(*piVar2 + 0x4c)))(param_2);
  fVar17 = (float)fVar13;
  uStack_14 = *(uint32_t*)(*(int*)(obj + 0x70) + 0x10);
  pfVar8 = *(float**)(*(int*)(obj + 0x70) + 0x14);
  pfVar6 = (float*)0x0;
  pfVar7 = (float*)0x0;
  pfArg = (float*)0x0;
  pfVar18 = (float*)0x0;
  if (uStack_14 != 0) {
    do {
      if ((char*)pfVar8[1] != (char*)0x0) {
        int iVar4 = strncmp((char*)pfVar8[1], "morph:", 6);
        if (iVar4 == 0) {
          if (pfVar6 == (float*)0x0) {
            pfVar6 = pfVar8;
          }
          pfVar7 = pfVar8;
          if (fVar17 <= *pfVar8) {
            if (pfVar18 == (float*)0x0) {
              pfVar18 = pfVar8;
            }
          } else {
            pfArg = pfVar8;
          }
        }
      }
      pfVar8 = pfVar8 + 2;
      uStack_14 = uStack_14 + -1;
    } while (uStack_14 != 0);
    if (pfVar18 != (float*)0x0) {
      if (pfArg == (float*)0x0) {
        fVar13 = ((long double)as_f32((uint32_t)piVar2[6]) - (long double)as_f32((uint32_t)piVar2[7])) +
                 (long double)*pfVar7;
        pfArg = pfVar7;
      } else {
        fVar13 = (long double)*pfArg;
      }
      fVar14 = (long double)fVar17 - fVar13;
      fVar15 = (long double)*pfVar18;
      pfVar6 = pfVar18;
      goto LAB_00579819;
    }
  }
  fVar13 = (long double)*pfArg;
  fVar14 = (long double)fVar17 - fVar13;
  fVar15 = ((long double)as_f32((uint32_t)piVar2[7]) - (long double)as_f32((uint32_t)piVar2[6])) +
           (long double)*pfVar6;

LAB_00579819:
  uVar3 = *(uint32_t*)(*(int*)(obj + 0x70) + 0x10);
  pfVar8 = *(float**)(*(int*)(obj + 0x70) + 0x14);
  bVar11 = pfArg == (float*)0x0;
  bVar12 = pfVar6 == (float*)0x0;
  pfStack_c = (float*)0x0;
  pfStack_10 = (float*)0x0;
  uStack_14 = 0;
  if (uVar3 != 0) {
    do {
      if (bVar11) {
        if (bVar12) break;
        if (strcmp((char*)pfVar8[1], (char*)pfVar6[1]) == 0) {
          bVar12 = true;
          pfStack_10 = pfVar8;
        }
      } else {
        if (strcmp((char*)pfVar8[1], (char*)pfArg[1]) == 0) {
          bVar11 = true;
          pfStack_c = pfVar8;
        }
        if (!bVar12) {
          if (strcmp((char*)pfVar8[1], (char*)pfVar6[1]) == 0) {
            bVar12 = true;
            pfStack_10 = pfVar8;
          }
        }
      }
      uStack_14 = uStack_14 + 1;
      pfVar8 = pfVar8 + 2;
    } while (uStack_14 < uVar3);
  }
  {
    long double fVar16 = (long double)0.0;
    fVar17 = 0.0f;
    if (pfStack_10 != (float*)0x0) {
      fVar16 = (long double)*pfStack_10;
    }
    if (pfStack_c != (float*)0x0) {
      fVar17 = *pfStack_c;
    }
    if (fVar16 < (long double)fVar17) {
      int iVar4 = *(int*)(*(int*)(obj + 0x34) + *(int*)(obj + 0x74) * 4);
      fVar16 = ((long double)*(float*)(iVar4 + 0x1c) - (long double)*(float*)(iVar4 + 0x18)) + fVar16;
    }
    return (fVar16 - (long double)fVar17) * (fVar14 / (fVar15 - fVar13)) + (long double)fVar17;
  }
}

// 0x579960 — observed shape
uint32_t FUN_00579960(void* self, int param_1, int param_2) {
  uint8_t* ecx = (uint8_t*)self;
  int* piVar2 = *(int**)(*(int*)(ecx + 0x34) + param_2 * 4);
  int iVar3;
  int* piVar4;
  int local_b8;
  float fStack_b0, fStack_ac, fStack_a8, fStack_4;
  uint8_t auStack_a4[12];
  uint8_t auStack_98[36];
  uint8_t auStack_74[36];
  uint32_t auStack_50[9];
  uint8_t auStack_2c[40];

  if (piVar2 == (int*)0x0) {
    return 0;
  }
  iVar3 = piVar2[0xd];
  piVar4 = *(int**)(iVar3 + 0x10);
  local_b8 = (int)0x80000000;
  do {
    if (piVar4 == (int*)0x0) {
      if (piVar2[0xf] < local_b8) {
        return 0;
      }
      *(uint8_t*)(piVar2 + 3) = *(uint8_t*)(piVar2 + 3) | 8;
      *(uint8_t*)(piVar2 + 0x10) = 1;
      ((FnV_U32)(*(uint32_t*)(uintptr_t)(*piVar2 + 0x3c)))((uint32_t)param_1);
      *(uint8_t*)(piVar2 + 3) = *(uint8_t*)(piVar2 + 3) & 0xf7;
      if ((*(char*)(ecx + 0x8c) != '\0') && (param_1 == *(int*)(ecx + 0x74))) {
        long double fVar11 = (long double)((FnF_U32)(*(uint32_t*)(uintptr_t)(*piVar2 + 0x4c)))((uint32_t)param_1);
        fStack_4 = (float)fVar11;
        if (*(char*)(ecx + 0x8d) == '\0') {
          if (fStack_4 < *(float*)(ecx + 0x90)) {
            FUN_0057ed70(ecx + 0x98, ecx + 0xbc);
          }
        } else {
          uint8_t* puVar12 = auStack_74;
          float fVar13 = 1.0f / *(float*)(iVar3 + 0x68);
          FUN_0053cc20(auStack_2c);
          FUN_0053c9e0(puVar12, fVar13);
          void* uVar7 = FUN_0053ca60(auStack_a4, auStack_a4 - 0x18);
          FUN_0057ed70(auStack_74, uVar7);
          *(uint8_t*)(ecx + 0x8d) = 0;
        }
        *(float*)(ecx + 0x90) = fStack_4;
        FUN_0057e9b0(auStack_98, &fStack_b0);
        FUN_0053c8d0(auStack_50, (void*)(iVar3 + 0x38));
        {
          float* pfVar8 = (float*)FUN_0053ca60(auStack_a4, (void*)(iVar3 + 0x5c));
          float fVar13 = pfVar8[1];
          float fVar1 = pfVar8[2];
          *(float*)(iVar3 + 0x5c) = fStack_b0 + *pfVar8;
          *(float*)(iVar3 + 0x60) = fStack_ac + fVar13;
          *(float*)(iVar3 + 100) = fStack_a8 + fVar1;
        }
        {
          uint32_t* puVar6 = auStack_50;
          uint32_t* puVar10 = (uint32_t*)(iVar3 + 0x38);
          for (int iVar9 = 9; iVar9 != 0; iVar9 = iVar9 + -1) {
            *puVar10 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar10 = puVar10 + 1;
          }
        }
      }
      return 1;
    }
    {
      uint8_t bVar5;
      uint32_t* puVar6;
      for (puVar6 = (uint32_t*)(uintptr_t)((FnPtr_Void)(*(uint32_t*)(uintptr_t)(*piVar4 + 4)))();
           puVar6 != (uint32_t*)0x0; puVar6 = (uint32_t*)puVar6[1]) {
        if (puVar6 == (uint32_t*)&DAT_00728a3c) {
          bVar5 = 1;
          goto LAB_005799b0;
        }
      }
      bVar5 = 0;
    LAB_005799b0:
      {
        uint32_t masked = (-(uint32_t)bVar5) & (uint32_t)(uintptr_t)piVar4;
        if (masked != 0) {
          int iVar9 = *(int*)((uintptr_t)masked + 0x3c);
          if (local_b8 < iVar9) {
            local_b8 = iVar9;
          }
        }
      }
    }
    piVar4 = (int*)piVar4[0xe];
  } while (true);
}

// 0x579b80 — observed shape
void FUN_00579b80(void* self, uint32_t param_1) {
  uint8_t* ecx = (uint8_t*)self;
  uint32_t uVar1 = 0;
  if (*(int*)(ecx + 0x3c) != 0) {
    do {
      FUN_00579960(self, (int)param_1, (int)uVar1);
      if ((*(char*)(ecx + 0x8c) != '\0') && (uVar1 == *(uint32_t*)(ecx + 0x74))) {
        FUN_0057e9b0(ecx + 200, ecx + 0xec);
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint32_t*)(ecx + 0x3c));
  }
}

// 0x579bd0 — observed shape
void FUN_00579bd0(void* self, uint32_t param_1, uint32_t param_2, float param_3) {
  uint8_t* ecx = (uint8_t*)self;
  float fVar1 = 1.0f - param_3;
  float local_84;
  float local_80, local_7c, local_78, local_74;
  float local_70, local_6c, local_68;
  float local_64, local_60, local_5c, local_58;
  float local_54, local_50, local_4c;
  float local_48, local_44, local_40, local_3c;
  float local_34, local_30, local_24;
  uint8_t local_20[16];
  uint8_t local_10[16];

  if (*(int*)(ecx + 0x3c) != 0) {
    uint32_t uVar6 = 0;
    // Ghidra typed this slot as float; it holds an object pointer (field 0x34).
    uint32_t fVar5 = *(uint32_t*)&local_84;
    do {
      char cVar2, cVar3;
      if ((*(char*)(ecx + 0x8c) != '\0') && (uVar6 == *(uint32_t*)(ecx + 0x74))) {
        FUN_0057eb00(ecx + 200, ecx + 0xec);
      }
      cVar2 = (char)FUN_00579960(self, (int)param_1, (int)uVar6);
      if (cVar2 != '\0') {
        fVar5 = *(uint32_t*)(*(int*)(*(int*)(ecx + 0x34) + uVar6 * 4) + 0x34);
        local_60 = *(float*)(fVar5 + 0x5c);
        local_5c = *(float*)(fVar5 + 0x60);
        local_58 = *(float*)(fVar5 + 100);
        FUN_00555f70((void*)(fVar5 + 0x38));
        local_64 = *(float*)(fVar5 + 0x68);
        if ((*(char*)(ecx + 0x8c) != '\0') && (uVar6 == *(uint32_t*)(ecx + 0x74))) {
          FUN_0057e9b0(ecx + 200, ecx + 0xec);
          FUN_0057eb00(*(int*)(ecx + 0x84) + 200, *(int*)(ecx + 0x84) + 0xec);
        }
      }
      cVar3 = (char)FUN_00579960(self, (int)param_2, (int)uVar6);
      if (cVar3 != '\0') {
        local_54 = *(float*)(fVar5 + 0x5c);
        local_50 = *(float*)(fVar5 + 0x60);
        local_4c = *(float*)(fVar5 + 100);
        FUN_00555f70((void*)(fVar5 + 0x38));
        local_84 = *(float*)(fVar5 + 0x68);
        if ((*(char*)(ecx + 0x8c) != '\0') && (uVar6 == *(uint32_t*)(ecx + 0x74))) {
          FUN_0057e9b0(*(int*)(ecx + 0x84) + 200, *(int*)(ecx + 0x84) + 0xec);
        }
      }
      if ((cVar2 != '\0') && (cVar3 != '\0')) {
        local_24 = local_4c * param_3;
        local_34 = local_5c * fVar1;
        local_30 = local_58 * fVar1;
        local_70 = local_60 * fVar1 + local_54 * param_3;
        local_6c = local_34 + local_50 * param_3;
        local_68 = local_30 + local_24;
        if (local_48 * local_80 + local_44 * local_7c + local_40 * local_78 + local_3c * local_74 < 0.0f) {
          float* pfVar4 = (float*)FUN_00555b90(local_10);
          local_80 = pfVar4[0];
          local_7c = pfVar4[1];
          local_78 = pfVar4[2];
          local_74 = pfVar4[3];
        }
        FUN_0055ec90(local_20, param_3, &local_80, &local_48);
        *(float*)(fVar5 + 0x5c) = local_70;
        *(float*)(fVar5 + 0x60) = local_6c;
        *(float*)(fVar5 + 100) = local_68;
        FUN_00520da0((void*)(fVar5 + 0x38));
        *(float*)(fVar5 + 0x68) = abs_f32(local_84 * param_3 + local_64 * fVar1);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint32_t*)(ecx + 0x3c));
  }
}

// 0x579e80 — observed shape
void FUN_00579e80(void* self, uint32_t param_1) {
  uint8_t* ecx = (uint8_t*)self;
  uint32_t local_8;
  FUN_005edba0();
  local_8 = 0;
  if (*(int*)(ecx + 0x3c) != 0) {
    do {
      if ((*(char*)(ecx + 0x8c) != '\0') && (local_8 == *(uint32_t*)(ecx + 0x74))) {
        FUN_0057eb00(ecx + 200, ecx + 0xec);
      }
      FUN_00579960(self, (int)param_1, (int)local_8);
      {
        int iVar1 = *(int*)(*(int*)(*(int*)(ecx + 0x34) + local_8 * 4) + 0x34);
        uint32_t* puVar2 = (uint32_t*)(uintptr_t)((FnPtr_Void)(*(uint32_t*)(*(int*)(ecx + 0x60) + 4)))();
        *puVar2 = 0;
        puVar2[1] = *(uint32_t*)(ecx + 0x68);
        if (*(uint32_t*)(ecx + 0x68) == 0) {
          *(uint32_t*)(ecx + 100) = (uint32_t)(uintptr_t)puVar2;
        } else {
          **(uint32_t**)(ecx + 0x68) = (uint32_t)(uintptr_t)puVar2;
        }
        *(uint32_t*)(ecx + 0x68) = (uint32_t)(uintptr_t)puVar2;
        *(int*)(ecx + 0x6c) = *(int*)(ecx + 0x6c) + 1;
        puVar2[2] = (uint32_t)iVar1;
        puVar2[0xc] = *(uint32_t*)(iVar1 + 0x5c);
        puVar2[0xd] = *(uint32_t*)(iVar1 + 0x60);
        puVar2[0xe] = *(uint32_t*)(iVar1 + 100);
        {
          uint32_t* puVar4 = (uint32_t*)(iVar1 + 0x38);
          uint32_t* puVar5 = puVar2 + 3;
          for (int iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar5 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar5 = puVar5 + 1;
          }
        }
        puVar2[0xf] = *(uint32_t*)(iVar1 + 0x68);
      }
      if ((*(char*)(ecx + 0x8c) != '\0') && (local_8 == *(uint32_t*)(ecx + 0x74))) {
        FUN_0057e9b0(ecx + 200, ecx + 0xec);
      }
      local_8 = local_8 + 1;
    } while (local_8 < *(uint32_t*)(ecx + 0x3c));
  }
}

// 0x579fa0 — observed shape
void FUN_00579fa0(void* self) {
  uint8_t* ecx = (uint8_t*)self;
  uint32_t local_8;
  FUN_005edba0();
  local_8 = 0;
  if (*(int*)(ecx + 0x3c) != 0) {
    do {
      int iVar1 = *(int*)(*(int*)(*(int*)(ecx + 0x34) + local_8 * 4) + 0x34);
      uint32_t* puVar2 = (uint32_t*)(uintptr_t)((FnPtr_Void)(*(uint32_t*)(*(int*)(ecx + 0x60) + 4)))();
      *puVar2 = 0;
      puVar2[1] = *(uint32_t*)(ecx + 0x68);
      if (*(uint32_t*)(ecx + 0x68) == 0) {
        *(uint32_t*)(ecx + 100) = (uint32_t)(uintptr_t)puVar2;
      } else {
        **(uint32_t**)(ecx + 0x68) = (uint32_t)(uintptr_t)puVar2;
      }
      *(uint32_t*)(ecx + 0x68) = (uint32_t)(uintptr_t)puVar2;
      *(int*)(ecx + 0x6c) = *(int*)(ecx + 0x6c) + 1;
      puVar2[2] = (uint32_t)iVar1;
      puVar2[0xc] = *(uint32_t*)(iVar1 + 0x5c);
      puVar2[0xd] = *(uint32_t*)(iVar1 + 0x60);
      puVar2[0xe] = *(uint32_t*)(iVar1 + 100);
      {
        uint32_t* puVar4 = (uint32_t*)(iVar1 + 0x38);
        uint32_t* puVar5 = puVar2 + 3;
        for (int iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
      }
      puVar2[0xf] = *(uint32_t*)(iVar1 + 0x68);
      local_8 = local_8 + 1;
    } while (local_8 < *(uint32_t*)(ecx + 0x3c));
  }
}

// 0x57a050 — observed shape
void FUN_0057a050(void* self) {
  uint8_t* ecx = (uint8_t*)self;
  int local_7c = *(int*)(*(int*)(ecx + 0x34) + *(int*)(ecx + 0x74) * 4);
  int iVar10 = *(int*)(local_7c + 0x50);
  float local_90;
  uint8_t local_8c[16];
  uint8_t local_78[16];
  uint8_t local_68[16];
  uint8_t local_58[16];
  uint8_t local_48[36];
  uint8_t local_24[36];
  float local_98, local_94;

  if (iVar10 == 0) {
    local_90 = 1.0f;
  } else {
    int iVar5 = *(int*)(iVar10 + 0x28);
    if (*(int*)(iVar10 + 0x24) == 0) {
      local_90 = 1.0f;
    } else {
      local_90 = *(float*)((uint32_t)*(uint8_t*)(iVar5 + 4) * (*(int*)(iVar10 + 0x24) + -1) + 8 + iVar5) /
                 *(float*)(iVar5 + 8);
    }
  }
  if (iVar10 != 0) {
    int iVar5 = *(int*)(iVar10 + 0x10);
    int iVar6 = *(int*)(iVar10 + 0xc);
    if (*(int*)(iVar10 + 0x14) == 4) {
      local_98 = 3.4028235e+38f;
      local_94 = -3.4028235e+38f;
      if (*(int*)(iVar5 + 0x18) != 0) {
        float* pfVar9 = *(float**)(iVar5 + 0x34);
        if (*pfVar9 < 3.4028235e+38f) {
          local_98 = *pfVar9;
        }
        float fVar1 = *(float*)((uint32_t)*(uint8_t*)(pfVar9 + 1) * (*(int*)(iVar5 + 0x18) + -1) +
                                (int)(uintptr_t)pfVar9);
        if (-3.4028235e+38f < fVar1) {
          local_94 = fVar1;
        }
      }
      if (*(int*)(iVar5 + 0x1c) != 0) {
        float* pfVar9 = *(float**)(iVar5 + 0x38);
        if (*pfVar9 < local_98) {
          local_98 = *pfVar9;
        }
        float fVar1 = *(float*)((uint32_t)*(uint8_t*)(pfVar9 + 1) * (*(int*)(iVar5 + 0x1c) + -1) +
                                (int)(uintptr_t)pfVar9);
        if (local_94 < fVar1) {
          local_94 = fVar1;
        }
      }
      if (*(int*)(iVar5 + 0x20) != 0) {
        float* pfVar9 = *(float**)(iVar5 + 0x3c);
        if (*pfVar9 < local_98) {
          local_98 = *pfVar9;
        }
        float fVar1 = *(float*)((uint32_t)*(uint8_t*)(pfVar9 + 1) * (*(int*)(iVar5 + 0x20) + -1) +
                                (int)(uintptr_t)pfVar9);
        if (local_94 < fVar1) {
          local_94 = fVar1;
        }
      }
      FUN_0056a050(local_68, local_98, iVar5, 4, iVar6, &local_98);
      FUN_0056a050(local_8c, local_94, iVar5, 4, iVar6, &local_98);
      {
        uint32_t uVar7 = FUN_00555c50(local_58, local_68);
        FUN_00555bc0(local_78, uVar7);
      }
      FUN_00520da0(local_48);
    } else {
      if (iVar6 == 0) goto LAB_0057a251;
      {
        uint32_t uVar7 = FUN_00555c50(local_58, (void*)(iVar5 + 8));
        FUN_00555bc0(local_78, uVar7);
      }
      FUN_00520da0(local_48);
    }
    {
      uint32_t* puVar8 = (uint32_t*)FUN_0053c9e0(local_24, local_90);
      uint32_t* puVar11 = (uint32_t*)(ecx + 0x98);
      for (iVar10 = 9; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar11 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar11 = puVar11 + 1;
      }
    }
  }
LAB_0057a251:
  iVar10 = *(int*)(local_7c + 0x50);
  if (iVar10 != 0) {
    int iVar5 = *(int*)(iVar10 + 0x1c);
    if (*(int*)(iVar10 + 0x18) != 0) {
      iVar10 = (uint32_t)*(uint8_t*)(iVar5 + 4) * (*(int*)(iVar10 + 0x18) + -1) + iVar5;
      {
        float* pfVar9 = (float*)FUN_0053ca60(local_68, (void*)(iVar5 + 8));
        float fVar1 = *(float*)(iVar10 + 0xc);
        float fVar2 = pfVar9[1];
        float fVar3 = *(float*)(iVar10 + 0x10);
        float fVar4 = pfVar9[2];
        *(float*)(ecx + 0xbc) = *(float*)(iVar10 + 8) - *pfVar9;
        *(float*)(ecx + 0xc0) = fVar1 - fVar2;
        *(float*)(ecx + 0xc4) = fVar3 - fVar4;
      }
    }
  }
}

// 0x57a3b0 — observed shape
void FUN_0057a3b0(void* self, uint8_t param_1) {
  uint32_t* ecx = (uint32_t*)self;
  *ecx = (uint32_t)(uintptr_t)&PTR_FUN_006c484c;
  FUN_005e1490();
  operator_delete__((void*)ecx[2]);
  if ((param_1 & 1) != 0) {
    operator_delete(ecx);
  }
}

// 0x57a3f0 — observed shape
void FUN_0057a3f0(void* self, uint32_t param_1) {
  uint8_t* ecx = (uint8_t*)self;
  int iVar2;
  uint32_t uVar7;
  if (param_1 != *(uint32_t*)(ecx + 8)) {
    if (param_1 < *(uint32_t*)(ecx + 0xc)) {
      uVar7 = param_1;
      iVar2 = *(int*)(ecx + 4);
      do {
        uint32_t* puVar3 = *(uint32_t**)(iVar2 + uVar7 * 4);
        if (puVar3 != (uint32_t*)0x0) {
          int* piVar1 = (int*)(puVar3 + 1);
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            ((FnV_U32)(*(uint32_t*)(uintptr_t)*puVar3))(1);
          }
          *(uint32_t*)(iVar2 + uVar7 * 4) = 0;
          *(int*)(ecx + 0x10) = *(int*)(ecx + 0x10) + -1;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < *(uint32_t*)(ecx + 0xc));
      *(uint32_t*)(ecx + 0xc) = param_1;
    }
    iVar2 = *(int*)(ecx + 4);
    *(uint32_t*)(ecx + 8) = param_1;
    if (param_1 == 0) {
      *(uint32_t*)(ecx + 4) = 0;
    } else {
      uint32_t* puVar5 = (uint32_t*)thunk_FUN_00533c78((size_t)(param_1 * 4 + 4));
      if (puVar5 == (uint32_t*)0x0) {
        puVar5 = (uint32_t*)0x0;
      } else {
        *puVar5 = param_1;
        puVar5 = puVar5 + 1;
        if (-1 < (int)(param_1 - 1)) {
          uint32_t* puVar9 = puVar5;
          for (; param_1 != 0; param_1 = param_1 - 1) {
            *puVar9 = 0;
            puVar9 = puVar9 + 1;
          }
        }
      }
      uVar7 = 0;
      *(uint32_t**)(ecx + 4) = puVar5;
      if (*(int*)(ecx + 0xc) != 0) {
        do {
          int iVar6 = *(int*)(ecx + 4);
          int iVar8 = uVar7 * 4;
          uint32_t* puVar3 = *(uint32_t**)(iVar6 + iVar8);
          if (puVar3 != *(uint32_t**)(iVar8 + iVar2)) {
            if (puVar3 != (uint32_t*)0x0) {
              int* piVar1 = (int*)(puVar3 + 1);
              *piVar1 = *piVar1 + -1;
              if (*piVar1 == 0) {
                ((FnV_U32)(*(uint32_t*)(uintptr_t)*puVar3))(1);
              }
            }
            {
              int iVar4 = *(int*)(iVar8 + iVar2);
              *(int*)(iVar6 + iVar8) = iVar4;
              if (iVar4 != 0) {
                *(int*)(iVar4 + 4) = *(int*)(iVar4 + 4) + 1;
              }
            }
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < *(uint32_t*)(ecx + 0xc));
      }
      uVar7 = *(uint32_t*)(ecx + 0xc);
      if (uVar7 < *(uint32_t*)(ecx + 8)) {
        do {
          int iVar8 = *(int*)(ecx + 4);
          uint32_t* puVar3 = *(uint32_t**)(iVar8 + uVar7 * 4);
          if (puVar3 != (uint32_t*)0x0) {
            int* piVar1 = (int*)(puVar3 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
              ((FnV_U32)(*(uint32_t*)(uintptr_t)*puVar3))(1);
            }
            *(uint32_t*)(iVar8 + uVar7 * 4) = 0;
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < *(uint32_t*)(ecx + 8));
      }
    }
    if (iVar2 != 0) {
      int iVar6 = *(int*)(iVar2 + -4);
      int iVar8 = iVar2 + iVar6 * 4;
      if (-1 < iVar6 + -1) {
        do {
          uint32_t* puVar3 = *(uint32_t**)(iVar8 + -4);
          iVar8 = iVar8 + -4;
          if (puVar3 != (uint32_t*)0x0) {
            int* piVar1 = (int*)(puVar3 + 1);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
              ((FnV_U32)(*(uint32_t*)(uintptr_t)*puVar3))(1);
            }
          }
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      operator_delete__((void*)(iVar2 + -4));
    }
  }
}
