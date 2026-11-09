// Reconstruction batch mass_0061 — Sid Meier's Pirates! (2004), PE32 i386
// Address range 0x4e6480..0x4e855b. Pseudocode corpus Ghidra 12.2.
// Receiver registers in_EAX/in_ECX/in_ESI/in_EBX/in_EDI are explicit leading
// parameters. Globals PTR_*/DAT_* and helpers FUN_* are extern; field offsets
// preserved as observed.
#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cstdio>
#include <windows.h>

typedef long double float10;

// ---- Globals (extern, as used by listed corpus) ----
extern uint32_t PTR_FUN_0070f974;
extern uint32_t PTR_FUN_0070f924;
extern uint32_t PTR_FUN_0070f940;
extern uint32_t PTR_LAB_0070f95c;
extern uint32_t PTR_FUN_0070fd0c;
extern uint32_t PTR_FUN_0070fd28;
extern uint32_t PTR_FUN_0070fd00;
extern uint32_t PTR_FUN_0070fdc4;
extern uint32_t PTR_LAB_0070fe20;
extern uint32_t PTR_LAB_0070fcf4;
extern uint32_t PTR_LAB_0070fe90;
extern uint32_t PTR_LAB_0070fe58;
extern uint32_t PTR_FUN_007108ac;
extern uint8_t DAT_008cacc8[];
extern uint8_t DAT_008cacd0[];
extern int32_t DAT_008cad2c;
extern uint32_t DAT_00726c28;
extern HANDLE DAT_0072705c;
extern uint16_t DAT_007d2168[];
extern uint8_t DAT_007263b8;
extern uint8_t DAT_007101a8[];
extern uint32_t DAT_008ea110[];

// ---- Helpers (extern, as used by listed corpus) ----
void operator_delete(void* p);
void operator_delete__(void* p);

int thunk_FUN_00533c78(int size);
int FUN_00533c78(int size);
void* FUN_0053bb30(int arg);
int FUN_00515c30(void);
void FUN_004e6420(void);
void FUN_004e6ac0(int* param_1);
void FUN_004e8500(void* self);
void FUN_004e8560(void);
void FUN_004ee510(void);
void FUN_004ee4d0(void);
void FUN_004ee250(void);
void FUN_004ebf70(void);
void FUN_004eeff0(void);
void FUN_00511c80(int addr);
void FUN_004ee610(void);
void FUN_004ee5d0(void);
void FUN_004e80c0(int param_1, void* ini);
int FUN_004e7a50(void);
void FUN_004e7db0(int* param_1, int param_2);
void FUN_004e7f00(int* self, void* ini);
void FUN_004e7fe0(int* self, void* ini);
void FUN_004e7a90(int* param_1, int index);
void FUN_004e7c90(int* param_1, int param_2);
void FUN_004127b0(void* dst, int stride, int count, void* fn);
void FUN_004e8ff0(void);
void FUN_005002f0(void);
void* FUN_004ee430(void);
void* FUN_004ee3c0(void);
void FUN_004eee00(void);
void FUN_00511a00(int a1, int a2, int a3, int a4, uint32_t a5, uint32_t a6,
                 uint32_t a7, uint32_t a8, uint32_t a9, int* a10, void* a11,
                 int a12, int a13, int a14, int a15);
extern "C" double _CIfmod(void);
void FUN_004ea9a0(void);
void FUN_004ee360(int a1, int a2);
void FUN_004ec000(void);
void FUN_00512180(int dst, char* src, int count);
void FUN_00533d10(int a1, int a2);
void FUN_004f8f50(void);
char FUN_004f8fa0(void* self, const char* path);
char FUN_004f96a0(void);
char FUN_004f98b0(const char* key, void* out);
char FUN_004f9820(void* out);
char FUN_004f9790(void* out);
char FUN_004f2600(void* ini, const char* section, uint32_t index);
void FUN_004f8bd0(const char* fmt, const char* arg);
void* FUN_00500600(void);
void FUN_004ebe80(char* name, int count);
int FUN_004ee1c0(int a1, uint32_t a2);
void FUN_004ee100(int a1, int a2);
void FUN_004e93b0(uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4);
void FUN_004d02e0(void);
void FUN_004ef080(void);
void FUN_00511f90(int a1);
void FUN_004effc0(uint32_t a1);
uint32_t FUN_00412cb0(void);
void FUN_004e99e0(char* name);
void FUN_004e9a30(int a1);
void FUN_004e9db0(char* name);
void FUN_004e9e00(char* name);
void FUN_004e98d0(int a1, char* name);
float10 FUN_004e9840(float a1, float a2);
char FUN_00512e80(float a1, float a2);
float10 FUN_00512f70(void* out);
void FUN_00519780(int ctx);
char FUN_005196c0(void);
char FUN_00519880(void);
void FUN_00518ed0(const char* fmt, void* arg);
void FUN_004fac10(void);
char FUN_00515cb0(int ctx);
uint32_t FUN_004ed270(void);
void FUN_004ee310(int a1);
int FUN_004ee2b0(void);
void FUN_004eb5b0(void);
int FUN_005f0ddc(void);


// 0x4e6480 — observed shape
void FUN_004e6480(void* self, uint32_t in_eax, void* in_ecx, uint8_t param_1,
                  uint8_t param_2)
{
  uint32_t* o = (uint32_t*)self;
  uint32_t* puVar1;
  uint32_t uVar2;
  int iVar3;

  o[1] = in_eax;
  o[0] = (uint32_t)(uintptr_t)&PTR_FUN_0070f974;
  o[2] = (uint32_t)(uintptr_t)in_ecx;
  *(uint8_t*)(o + 3) = param_1;
  *(uint8_t*)((uint8_t*)o + 0xd) = param_2;
  o[4] = (uint32_t)(uintptr_t)&PTR_FUN_0070f924;
  o[5] = 0x25;
  o[7] = 0;
  puVar1 = (uint32_t*)thunk_FUN_00533c78(0x94);
  o[6] = (uint32_t)(uintptr_t)puVar1;
  for (uVar2 = o[5] & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(uint8_t*)puVar1 = 0;
    puVar1 = (uint32_t*)((uint8_t*)puVar1 + 1);
  }
  o[4] = (uint32_t)(uintptr_t)&PTR_FUN_0070f940;
  FUN_004e6420();
}


// 0x4e64f0 — observed shape
void FUN_004e64f0(void* self, uint8_t param_1)
{
  uint32_t* o = (uint32_t*)self;

  o[4] = (uint32_t)(uintptr_t)&PTR_FUN_0070f940;
  FUN_004e6420();
  o[4] = (uint32_t)(uintptr_t)&PTR_FUN_0070f924;
  FUN_004e6420();
  operator_delete__((void*)o[6]);
  o[0] = (uint32_t)(uintptr_t)&PTR_LAB_0070f95c;
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}


// 0x4e6560 — observed shape
void FUN_004e6560(void* self, uint8_t param_1)
{
  FUN_004ee610();
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}


// 0x4e6580 — observed shape
void FUN_004e6580(void* self, uint8_t param_1)
{
  FUN_004ee5d0();
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}


// 0x4e65a0 — observed shape
void FUN_004e65a0(void* self, int param_1, float param_2, int param_3, int param_4,
                  int param_5, int param_6, int param_7)
{
  uint32_t* o = (uint32_t*)self;
  int* piVar1;
  uint32_t* puVar2;
  uint32_t uVar3;
  int iVar4;

  *o = 0;
  o[0x23] = (uint32_t)(uintptr_t)&PTR_FUN_0070fd0c;
  o[0x24] = 0x25;
  o[0x26] = 0;
  puVar2 = (uint32_t*)thunk_FUN_00533c78(0x94);
  o[0x25] = (uint32_t)(uintptr_t)puVar2;
  for (uVar3 = o[0x24] & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(uint8_t*)puVar2 = 0;
    puVar2 = (uint32_t*)((uint8_t*)puVar2 + 1);
  }
  o[0x23] = (uint32_t)(uintptr_t)&PTR_FUN_0070fd28;
  o[0x27] = (uint32_t)(uintptr_t)&PTR_FUN_0070fd0c;
  o[0x28] = 0x25;
  o[0x2a] = 0;
  puVar2 = (uint32_t*)thunk_FUN_00533c78(0x94);
  o[0x29] = (uint32_t)(uintptr_t)puVar2;
  for (uVar3 = o[0x28] & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(uint8_t*)puVar2 = 0;
    puVar2 = (uint32_t*)((uint8_t*)puVar2 + 1);
  }
  o[0x27] = (uint32_t)(uintptr_t)&PTR_FUN_0070fd28;
  o[0x2e] = 0;
  o[0x2c] = 0;
  o[0x2d] = 0;
  o[0x2b] = (uint32_t)(uintptr_t)&PTR_FUN_0070fd00;
  o[0x32] = 0;
  o[0x30] = 0;
  o[0x31] = 0;
  o[0x2f] = (uint32_t)(uintptr_t)&PTR_FUN_0070fdc4;
  o[4] = (uint32_t)param_1;
  o[5] = (uint32_t)param_1;
  o[0x18] = 0xc9742400;
  o[0x19] = 0xc9742400;
  o[6] = 0xc9742400;
  o[7] = 0xc9742400;
  o[0x1a] = 0;
  o[8] = (uint32_t)param_3;
  puVar2 = (uint32_t*)*o;
  o[9] = (uint32_t)param_4;
  o[10] = (uint32_t)param_5;
  *(uint8_t*)(o + 0x15) = 0;
  if (puVar2 != (uint32_t*)0x0) {
    piVar1 = (int*)(puVar2 + 1);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (*(void (**)(int))(*puVar2))(1);
    }
    *o = 0;
  }
  param_2 = param_2 * 0.01f;
  o[0x16] = 0;
  o[1] = 0;
  o[0xb] = (uint32_t)(int)param_2;
  o[0xc] = (uint32_t)param_6;
  o[0xd] = (uint32_t)param_7;
  o[0x11] = 0x42ff0000;
  *(uint8_t*)((uint8_t*)o + 0x79) = 0;
  *(uint8_t*)(o + 0x1e) = 1;
  o[8] = (uint32_t)(int)(param_2 * (float)o[8]);
  o[0x17] = 10;
  *(uint8_t*)((uint8_t*)o + 0x7b) = 1;
  *(uint8_t*)(o + 0x1f) = 0;
  *(uint8_t*)((uint8_t*)o + 0x7f) = 1;
  o[9] = (uint32_t)(int)(param_2 * (float)o[9]);
  o[10] = (uint32_t)(int)(param_2 * (float)o[10]);
  iVar4 = FUN_00515c30();
  o[0x22] = (uint32_t)iVar4;
  o[0xe] = 0x3f800000;
  o[0xf] = 0x3f800000;
  *(uint8_t*)((uint8_t*)o + 0x81) = 1;
  FUN_004e6ac0((int*)o);
}


// 0x4e6770 — observed shape
void FUN_004e6770(void* self)
{
  uint32_t* o = (uint32_t*)self;
  int* piVar1;
  uint32_t* puVar2;
  uint32_t uVar3;
  uint32_t* puVar4;
  int* piVar5;
  int iVar6;
  int* piVar7;
  int* piVar8;
  int iVar9;
  void* local_4;

  local_4 = (void*)0x0;
  FUN_004e8560();
  FUN_004e8500(self);
  FUN_004ee510();
  if (*(int8_t*)((uint8_t*)o + 0x7d) != 0) {
    local_4 = *(void**)(o[1] + 0xa8);
  }
  iVar6 = 0;
  if (0 < (int)o[0x16]) {
    iVar9 = 0;
    do {
      FUN_00511c80((int)(o[1] + (uint32_t)iVar9));
      iVar6 = iVar6 + 1;
      iVar9 = iVar9 + 0x124;
    } while (iVar6 < (int)o[0x16]);
  }
  FUN_004ebf70();
  FUN_004eeff0();
  piVar5 = (int*)0x0;
  {
    uVar3 = 0;
    if (o[0x24] != 0) {
      int* pScan = (int*)o[0x25];
      while (uVar3 < o[0x24]) {
        if (*pScan != 0) {
          piVar5 = ((int*)o[0x25])[uVar3];
          break;
        }
        uVar3 = uVar3 + 1;
        pScan = pScan + 1;
      }
    }
  }
  while (piVar5 != (int*)0x0) {
    piVar7 = (int*)*piVar5;
    piVar8 = (int*)piVar5[2];
    if (piVar7 == (int*)0x0) {
      iVar6 = ((int (*)(int))(o[0x23] + 4))((char)piVar5[1]);
      uVar3 = (uint32_t)(iVar6 + 1);
      piVar7 = (int*)0x0;
      if (uVar3 < o[0x24]) {
        puVar4 = (uint32_t*)(o[0x25] + uVar3 * 4);
        for (;;) {
          piVar7 = (int*)*puVar4;
          if (piVar7 != (int*)0x0) break;
          uVar3 = uVar3 + 1;
          puVar4 = puVar4 + 1;
          if (!(uVar3 < o[0x24])) {
            piVar7 = (int*)0x0;
            break;
          }
        }
      }
    }
    piVar5 = piVar7;
    if (piVar8 != (int*)0x0) {
      puVar4 = (uint32_t*)(*piVar8 + -8);
      if ((puVar4 != (uint32_t*)0x0) && (puVar4 != (uint32_t*)&DAT_008cacc8)) {
        operator_delete__((void*)puVar4);
      }
      *piVar8 = (int)(intptr_t)DAT_008cacd0;
      operator_delete(piVar8);
    }
  }
  FUN_004e6420();
  {
    int* piVarTable = (int*)(o + 0x27);
    uVar3 = 0;
    piVar7 = (int*)0x0;
    if (o[0x28] != 0) {
      int* pScan = (int*)o[0x29];
      while (uVar3 < o[0x28]) {
        if (*pScan != 0) {
          piVar7 = ((int*)o[0x29])[uVar3];
          break;
        }
        uVar3 = uVar3 + 1;
        pScan = pScan + 1;
      }
    }
    for (;;) {
      if (piVar7 == (int*)0x0) {
        FUN_004e6420();
        puVar4 = (uint32_t*)*o;
        if (puVar4 != (uint32_t*)0x0) {
          piVar7 = (int*)(puVar4 + 1);
          *piVar7 = *piVar7 + -1;
          if (*piVar7 == 0) {
            (*(void (**)(int))(*puVar4))(1);
          }
          *o = 0;
        }
        *(uint8_t*)(o + 0x1e) = 0;
        if (local_4 != (void*)0x0) {
          operator_delete(local_4);
        }
        puVar4 = (uint32_t*)o[1];
        if (puVar4 != (uint32_t*)0x0) {
          if (puVar4[-1] == 0) {
            operator_delete__(puVar4 + -1);
          }
          else {
            (*(void (**)(int))(*puVar4))(3);
          }
          o[1] = 0;
        }
        if ((void*)o[2] != (void*)0x0) {
          operator_delete__((void*)o[2]);
          o[2] = 0;
        }
        piVar7 = (int*)o[0x21];
        if (piVar7 != (int*)0x0) {
          FUN_004ee4d0();
          FUN_004ee250();
          puVar4 = (uint32_t*)*piVar7;
          if (puVar4 != (uint32_t*)0x0) {
            int* piRef = (int*)(puVar4 + 1);
            *piRef = *piRef + -1;
            if (*piRef == 0) {
              (*(void (**)(int))(*puVar4))(1);
            }
          }
          operator_delete(piVar7);
          o[0x21] = 0;
        }
        if ((uint32_t*)o[0x22] != (uint32_t*)0x0) {
          (*(void (**)(int))(*((uint32_t*)o[0x22])))(1);
          o[0x22] = 0;
        }
        piVar7 = (int*)(o + 0x2f);
        *piVar7 = (int)(intptr_t)&PTR_FUN_0070fdc4;
        puVar4 = (uint32_t*)o[0x30];
        while (puVar4 != (uint32_t*)0x0) {
          puVar2 = (uint32_t*)*puVar4;
          (*(void (**)(void*))(*piVar7 + 8))((void*)puVar4);
          puVar4 = puVar2;
        }
        o[0x32] = 0;
        o[0x30] = 0;
        o[0x31] = 0;
        *piVar7 = (int)(intptr_t)&PTR_LAB_0070fe20;
        piVar7 = (int*)(o + 0x2b);
        *piVar7 = (int)(intptr_t)&PTR_FUN_0070fd00;
        puVar4 = (uint32_t*)o[0x2c];
        while (puVar4 != (uint32_t*)0x0) {
          puVar2 = (uint32_t*)*puVar4;
          (*(void (**)(void*))(*piVar7 + 8))((void*)puVar4);
          puVar4 = puVar2;
        }
        o[0x2e] = 0;
        o[0x2c] = 0;
        o[0x2d] = 0;
        *piVar7 = (int)(intptr_t)&PTR_LAB_0070fcf4;
        *piVarTable = (int)(intptr_t)&PTR_FUN_0070fd28;
        FUN_004e6420();
        *piVarTable = (int)(intptr_t)&PTR_FUN_0070fd0c;
        FUN_004e6420();
        operator_delete__((void*)o[0x29]);
        o[0x23] = (uint32_t)(uintptr_t)&PTR_FUN_0070fd28;
        FUN_004e6420();
        o[0x23] = (uint32_t)(uintptr_t)&PTR_FUN_0070fd0c;
        FUN_004e6420();
        operator_delete__((void*)o[0x25]);
        puVar4 = (uint32_t*)*o;
        if (puVar4 != (uint32_t*)0x0) {
          int* piRef = (int*)(puVar4 + 1);
          *piRef = *piRef + -1;
          if (*piRef == 0) {
            (*(void (**)(int))(*puVar4))(1);
          }
        }
        return;
      }
      piVar8 = (int*)*piVar7;
      piVar1 = (int*)piVar7[2];
      if (piVar8 == (int*)0x0) {
        iVar6 = ((int (*)(int))(*piVarTable + 4))((char)piVar7[1]);
        uVar3 = (uint32_t)(iVar6 + 1);
        piVar8 = (int*)0x0;
        if (uVar3 < o[0x28]) {
          puVar4 = (uint32_t*)(o[0x29] + uVar3 * 4);
          for (;;) {
            piVar8 = (int*)*puVar4;
            if (piVar8 != (int*)0x0) break;
            uVar3 = uVar3 + 1;
            puVar4 = puVar4 + 1;
            if (!(uVar3 < o[0x28])) {
              piVar8 = (int*)0x0;
              break;
            }
          }
        }
      }
      piVar7 = piVar8;
      if (piVar1 != (int*)0x0) {
        puVar4 = (uint32_t*)(*piVar1 + -8);
        if ((puVar4 != (uint32_t*)0x0) && (puVar4 != (uint32_t*)&DAT_008cacc8)) {
          operator_delete__((void*)puVar4);
        }
        *piVar1 = (int)(intptr_t)DAT_008cacd0;
        operator_delete(piVar1);
      }
    }
  }
}


// 0x4e6ac0 — observed shape
void FUN_004e6ac0(int* param_1)
{
  uint32_t* pfVar1;
  char* pcVar2;
  uint32_t uVar3;
  uint8_t uVar4;
  uint32_t* puVar5;
  int* piVar6;
  char cVar7;
  int iVar8;
  uint32_t* puVar9;
  int* piVar10;
  int iVar11;
  char* pcVar12;
  int iVar13;
  int* piVar14;
  float10 fVar15;
  uint8_t auStack_38[4];
  int iStack_34;
  int iStack_30; /* written by FUN_005002f0 by convention; uninitialized in listing */
  int iStack_2c;
  uint32_t uStack_28;
  uint32_t* local_1c;
  uint32_t local_18;
  uint32_t local_14;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;

  piVar6 = param_1;
  iVar8 = FUN_00515c30();
  param_1[0x22] = iVar8;
  if ((char)param_1[0x15] == '\0') {
    iVar8 = FUN_00533c78(0xec);
    iVar13 = 0;
    if (iVar8 == 0) {
      puVar9 = (uint32_t*)0x0;
    }
    else {
      puVar9 = (uint32_t*)FUN_0053bb30(0);
    }
    puVar5 = (uint32_t*)*param_1;
    if (puVar5 != puVar9) {
      if (puVar5 != (uint32_t*)0x0) {
        piVar10 = (int*)(puVar5 + 1);
        *piVar10 = *piVar10 + -1;
        if (*piVar10 == 0) {
          (*(void (**)(int))(*puVar5))(1);
        }
      }
      *param_1 = (int)(intptr_t)puVar9;
      if (puVar9 != (uint32_t*)0x0) {
        puVar9[1] = puVar9[1] + 1;
      }
    }
    local_14 = 0;
    local_8 = 1;
    local_10 = 0;
    local_c = 0;
    local_18 = 0;
    local_1c = &PTR_FUN_007108ac;
    cVar7 = FUN_004f8fa0(&local_1c, "assets\\data\\Landscape.ini");
    if (cVar7 != '\0') {
      FUN_004e80c0((int)(intptr_t)param_1, &local_1c);
      iVar8 = FUN_004e7a50();
      param_1[0x16] = iVar8;
      piVar10 = (int*)thunk_FUN_00533c78(iVar8 * 0x124 + 4);
      if (piVar10 == (int*)0x0) {
        piVar14 = (int*)0x0;
      }
      else {
        piVar14 = piVar10 + 1;
        *piVar10 = iVar8;
        FUN_004127b0(piVar14, 0x124, iVar8, (void*)&FUN_004e8ff0);
      }
      param_1[1] = (int)(intptr_t)piVar14;
      iVar8 = thunk_FUN_00533c78(param_1[0x16] * 0x2cc);
      param_1[2] = iVar8;
      FUN_005002f0();
      if (((param_1 == (int*)0x0) || (iStack_30 == 0)) || (DAT_007263b8 == '\0')) {
        iStack_30 = 0;
        *(uint8_t*)((intptr_t)param_1 + 0x7e) = 0;
      }
      else {
        *(uint8_t*)((intptr_t)param_1 + 0x7e) = 1;
        *(uint8_t*)(*param_1 + 0x20) = *(uint8_t*)(*param_1 + 0x20) | 1;
        iStack_30 = 2;
      }
      if (iStack_30 == 0) {
        if (*(char*)((intptr_t)param_1 + 0x7a) == '\0') {
          param_1 = (int*)FUN_004ee430();
        }
        else {
          piVar10 = (int*)FUN_00533c78(4);
          if (piVar10 == (int*)0x0) {
            param_1 = (int*)0x0;
            *(uint8_t*)((intptr_t)piVar6 + 0x7d) = 1;
          }
          else {
            *piVar10 = (int)(intptr_t)&PTR_LAB_0070fe90;
            *(uint8_t*)((intptr_t)param_1 + 0x7d) = 1;
            param_1 = piVar10;
          }
        }
      }
      else if (iStack_30 == 2) {
        if (*(char*)((intptr_t)param_1 + 0x7a) == '\0') {
          param_1 = (int*)FUN_004ee3c0();
        }
        else {
          piVar10 = (int*)FUN_00533c78(4);
          if (piVar10 == (int*)0x0) {
            param_1 = (int*)0x0;
            FUN_004eee00();
            *(uint8_t*)((intptr_t)piVar6 + 0x7d) = 1;
          }
          else {
            *piVar10 = (int)(intptr_t)&PTR_LAB_0070fe58;
            FUN_004eee00();
            *(uint8_t*)((intptr_t)param_1 + 0x7d) = 1;
            param_1 = piVar10;
          }
        }
      }
      FUN_004e7db0(piVar6, 0);
      FUN_004e7f00(piVar6, &local_1c);
      FUN_004e7fe0(piVar6, &local_1c);
      iStack_34 = 0;
      if (0 < piVar6[0x16]) {
        iVar8 = 0;
        do {
          FUN_004e7a90(piVar6, iStack_34);
          *(float*)(piVar6[2] + 0x288 + iVar8) =
               *(float*)(piVar6[2] + 0x288 + iVar8) * (float)piVar6[8];
          *(float*)(piVar6[2] + 0x28c + iVar8) =
               *(float*)(piVar6[2] + 0x28c + iVar8) * (float)piVar6[9];
          pfVar1 = (uint32_t*)(piVar6[2] + 0x290 + iVar8);
          *(float*)pfVar1 = (float)piVar6[10] * *(float*)pfVar1;
          *(float*)(piVar6[2] + 0x2a4 + iVar8) =
               *(float*)(piVar6[2] + 0x2a4 + iVar8) * (float)piVar6[8];
          *(float*)(piVar6[2] + 0x2a8 + iVar8) =
               *(float*)(piVar6[2] + 0x2a8 + iVar8) * (float)piVar6[9];
          pfVar1 = (uint32_t*)(piVar6[2] + 0x2ac + iVar8);
          *(float*)pfVar1 = (float)piVar6[10] * *(float*)pfVar1;
          *(float*)(piVar6[2] + iVar8 + 0x2ac) =
               (127.5f - (float)piVar6[0x11]) * (float)piVar6[10] -
               *(float*)(piVar6[2] + iVar8 + 0x290) * 127.5f;
          *(int**)(iVar13 + 0xa8 + piVar6[1]) = param_1;
          iVar11 = piVar6[1];
          uVar4 = *(uint8_t*)(piVar6[2] + 0x2b0 + iVar8);
          *(uint8_t*)(iVar11 + 0xd5 + iVar13) = *(uint8_t*)(piVar6[2] + iVar8 + 0x2b4);
          *(uint8_t*)(iVar11 + 0xd4 + iVar13) = uVar4;
          iVar11 = piVar6[2] + iVar8;
          FUN_00511a00(iVar11, iVar11 + 0x80, iVar11 + 0x100, iVar11 + 0x180,
                       *(uint32_t*)(iVar11 + 0x288), *(uint32_t*)(iVar11 + 0x28c),
                       *(uint32_t*)(iVar11 + 0x290), *(uint32_t*)(iVar11 + 0x284),
                       *(uint32_t*)(iVar11 + 0x280), &iStack_2c, auStack_38, iStack_30, 1, 0, 0);
          FUN_004e7c90(piVar6, iStack_34);
          (*(void (**)(uint32_t))(*(int*)(iVar13 + piVar6[1]) + 0x10))
                    (*(uint32_t*)(piVar6[2] + 0x2b8 + iVar8));
          (*(void (**)(uint32_t))(*(int*)(piVar6[1] + iVar13) + 0x14))
                    (*(uint32_t*)(piVar6[2] + 700 + iVar8));
          uVar3 = *(uint32_t*)(piVar6[2] + 0x2c0 + iVar8);
          iVar11 = piVar6[1] + iVar13;
          fVar15 = (float10)_CIfmod();
          *(float*)(iVar11 + 0x98) = (float)fVar15;
          *(uint32_t*)(iVar11 + 0x90) = uVar3;
          fVar15 = (float10)_CIfmod();
          *(float*)(iVar11 + 0x9c) = (float)fVar15;
          *(uint32_t*)(iVar11 + 0x94) = uVar3;
          *(uint8_t*)(iVar11 + 0xa4) = 0;
          FUN_004ea9a0();
          iStack_30 = *(int*)(piVar6[2] + 0x2a4 + iVar8);
          iVar11 = piVar6[2] + iVar8;
          iStack_2c = *(int*)(iVar11 + 0x2a8);
          uStack_28 = *(uint32_t*)(iVar11 + 0x2ac);
          iVar11 = *(int*)(iVar13 + 4 + piVar6[1]);
          *(int*)(iVar11 + 0x5c) = iStack_30;
          *(int*)(iVar11 + 0x60) = iStack_2c;
          *(uint32_t*)(iVar11 + 100) = uStack_28;
          (*(void (**)(uint32_t, int))(*(int*)*piVar6 + 0x70))
                    (*(uint32_t*)(iVar13 + 4 + piVar6[1]), 1);
          FUN_004ee360(piVar6[0x22], piVar6[1] + iVar13);
          FUN_004ec000();
          iStack_34 = iStack_34 + 1;
          iVar8 = iVar8 + 0x2cc;
          iVar13 = iVar13 + 0x124;
        } while (iStack_34 < piVar6[0x16]);
      }
      iVar8 = 0;
      if (0 < piVar6[0x16]) {
        iVar13 = 0;
        param_1 = (int*)0x0;
        do {
          if (piVar6[0x13] != 0) {
            pcVar2 = (char*)(piVar6[2] + 0x200 + iVar13);
            pcVar12 = pcVar2;
            do {
              cVar7 = *pcVar12;
              pcVar12 = pcVar12 + 1;
            } while (cVar7 != '\0');
            iStack_2c = (int)(pcVar12 - (pcVar2 + 1));
            if (iStack_2c != 0) {
              FUN_00512180(piVar6[1] + (int)(intptr_t)param_1, pcVar2, piVar6[0x14]);
            }
          }
          iVar8 = iVar8 + 1;
          param_1 = (int*)((intptr_t)param_1 + 0x124);
          iVar13 = iVar13 + 0x2cc;
        } while (iVar8 < piVar6[0x16]);
      }
    }
    *(uint8_t*)(piVar6 + 0x15) = 1;
    FUN_00533d10(0, 1);
    FUN_004f8f50();
  }
  iVar8 = piVar6[0x22];
  *(uint32_t*)(iVar8 + 0x18) = 0;
  if ((*(uint8_t*)(iVar8 + 0x24) & 1) == 0) {
    *(uint8_t*)(iVar8 + 0x24) = *(uint8_t*)(iVar8 + 0x24) | 1;
    ResumeThread(*(HANDLE*)(iVar8 + 0x2c));
  }
}


// 0x4e7060 — observed shape
uint32_t FUN_004e7060(uint32_t in_eax, int param_1, int param_2, int param_3,
                      int param_4)
{
  auto is_nan = [](float v) { return v != v; };
  float fVar1;
  float fVar2;
  uint32_t* puVar3;
  HANDLE hHandle;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  char cVar10;
  uint8_t bVar11;
  uint16_t uVar12;
  uint32_t uVar13;
  int iVar14;
  int iVar15;
  LPVOID pvVar16;
  int* piVar17;
  float10 extraout_ST0; /* x87 result leftover at 0x4e73e0; not initialized */
  uint8_t local_4d;
  float local_4c;
  float local_48;
  int local_2c;
  int local_28;
  int local_1c;
  int local_18; /* uninitialized in listing */
  int local_14; /* uninitialized in listing */

  fVar4 = (float)param_2 / *(float*)(param_1 + 0x30);
  uVar13 = in_eax & 0xffffff00;
  local_4d = 0;
  local_1c = 0;
  fVar5 = (float)param_3 / *(float*)(param_1 + 0x34);
  if (0 < *(int*)(param_1 + 0x58)) {
    local_28 = 0;
    local_2c = 0;
    do {
      fVar6 = (float)*(int*)(*(int*)(param_1 + 4) + 0x6c + local_2c);
      iVar14 = *(int*)(param_1 + 8) + local_28;
      fVar1 = *(float*)(iVar14 + 0x2a8);
      piVar17 = (int*)(*(int*)(param_1 + 4) + local_2c);
      fVar2 = *(float*)(iVar14 + 0x2a4);
      if (piVar17[0x1b] < 0) {
        fVar6 = fVar6 + 4.2949673e+09f;
      }
      fVar6 = (fVar6 - 1.0f) * (float)piVar17[0x21] + fVar2;
      fVar7 = (float)piVar17[0x1c];
      if (piVar17[0x1c] < 0) {
        fVar7 = fVar7 + 4.2949673e+09f;
      }
      bVar11 = 0;
      fVar7 = fVar1 - (fVar7 - 1.0f) * (float)piVar17[0x22];
      fVar8 = 1.0f / *(float*)(param_1 + 0x2c);
      if (fVar4 <= fVar8 * *(float*)(param_1 + 0x20) + fVar4) {
        local_48 = fVar4;
        do {
          local_4c = fVar5;
          if (fVar5 <= fVar8 * *(float*)(param_1 + 0x24) + fVar5) {
            do {
              if (((fVar7 <= local_4c) &&
                   ((!is_nan(local_4c) && !is_nan(fVar1)) &&
                    ((local_4c < fVar1) != (local_4c == fVar1)))) &&
                  (fVar2 <= local_48) &&
                  ((!is_nan(local_48) && !is_nan(fVar6)) &&
                   ((local_48 < fVar6) != (local_48 == fVar6)))) {
                cVar10 = (char)piVar17[0x28];
                iVar14 = DAT_008cad2c;
                while (DAT_008cad2c = iVar14, cVar10 == '\0') {
                  iVar15 = ((int (*)(int*))(*(int*)(iVar14 + 0x50) + 4))(piVar17);
                  for (puVar3 = *(uint32_t**)(*(int*)(iVar14 + 0x58) + iVar15 * 4);
                       puVar3 != (uint32_t*)0x0; puVar3 = (uint32_t*)*puVar3) {
                    cVar10 = ((char (*)(int*, uint32_t))(*(int*)(iVar14 + 0x50) + 8))
                                  (piVar17, puVar3[1]);
                    if (cVar10 != '\0') {
                      iVar14 = (int)puVar3[2];
                      if (iVar14 != 0) {
                        hHandle = *(HANDLE*)(iVar14 + 0x38);
                        if ((DAT_00726c28 == 0xffffffff) ||
                            (pvVar16 = TlsGetValue(DAT_00726c28), pvVar16 == (LPVOID)0x0)) {
                          WaitForSingleObject(hHandle, 0xffffffff);
                        }
                        else {
                          FUN_004fac10();
                        }
                        cVar10 = *(char*)(iVar14 + 1);
                        ReleaseMutex(*(HANDLE*)(iVar14 + 0x38));
                        if (cVar10 == '\0') {
                          FUN_00519780(DAT_008cad2c);
                        }
                        else {
                          cVar10 = FUN_005196c0();
                          if (cVar10 != '\0') {
                            (*(void (**)(void))(*piVar17 + 0x28))();
                          }
                        }
                        goto LAB_004e729a;
                      }
                      break;
                    }
                  }
                  FUN_00518ed0("Context expected, but not found for 0x%x", piVar17);
                  FUN_00518ed0("Querying non-existant context (context=0x%x).", piVar17);
                  FUN_00519780(DAT_008cad2c);
LAB_004e729a:
                  Sleep(10);
                  iVar14 = DAT_008cad2c;
                  cVar10 = (char)piVar17[0x28];
                }
                if ((((char)piVar17[0x28] != '\0') &&
                     (cVar10 = FUN_00512e80(local_48, local_4c), cVar10 != '\0')) &&
                    (127.0f <= (float)*(uint8_t*)
                       (piVar17[0x1b] * local_18 + piVar17[0x15] + local_14))) {
                  local_4d = (uint8_t)(local_4d | (1u << (bVar11 & 0x1f)));
                }
              }
              fVar8 = *(float*)(param_1 + 0x24) / *(float*)(param_1 + 0x2c);
              bVar11 = (uint8_t)(bVar11 + 1);
              local_4c = fVar8 / (float)param_4 + local_4c;
              fVar8 = fVar5 + fVar8;
            } while ((!is_nan(local_4c) && !is_nan(fVar8)) &&
                     ((local_4c < fVar8) != (local_4c == fVar8)));
          }
          fVar8 = 1.0f / *(float*)(param_1 + 0x2c);
          fVar9 = fVar8 * *(float*)(param_1 + 0x20);
          local_48 = fVar9 / (float)param_4 + local_48;
          fVar9 = fVar4 + fVar9;
        } while ((!is_nan(local_48) && !is_nan(fVar9)) &&
                 ((local_48 < fVar9) != (local_48 == fVar9)));
      }
      fVar8 = *(float*)(param_1 + 0x20) * 0.5f + fVar4;
      fVar9 = *(float*)(param_1 + 0x24) * 0.5f + fVar5;
      if (((fVar7 <= fVar9) &&
           ((!is_nan(fVar9) && !is_nan(fVar1)) && ((fVar9 < fVar1) != (fVar9 == fVar1)))) &&
          (fVar2 <= fVar8) &&
          ((!is_nan(fVar8) && !is_nan(fVar6)) && ((fVar8 < fVar6) != (fVar8 == fVar6)))) {
        cVar10 = (char)piVar17[0x28];
        while (cVar10 == '\0') {
          cVar10 = FUN_00519880();
          if (cVar10 == '\0') {
            FUN_00519780(DAT_008cad2c);
          }
          else {
            cVar10 = FUN_005196c0();
            if (cVar10 != '\0') {
              (*(void (**)(void))(*piVar17 + 0x28))();
            }
          }
          Sleep(10);
          cVar10 = (char)piVar17[0x28];
        }
        FUN_00512f70((void*)0);
        iVar14 = FUN_005f0ddc();
        iVar15 = FUN_005f0ddc();
        iVar14 = (param_2 / iVar14) * 0x125 + param_3 / iVar15;
        if ((float10)(int)(int16_t)DAT_007d2168[iVar14] < extraout_ST0) {
          uVar12 = (uint16_t)FUN_005f0ddc();
          DAT_007d2168[iVar14] = (int16_t)uVar12;
        }
      }
      local_1c = local_1c + 1;
      local_2c = local_2c + 0x124;
      local_28 = local_28 + 0x2cc;
    } while (local_1c < *(int*)(param_1 + 0x58));
    uVar13 = (((uint32_t)local_1c >> 8) << 8) | local_4d;
  }
  return uVar13;
}


// 0x4e7510 — observed shape
float10 FUN_004e7510(void* self, char in_al, float param_1, float param_2, char param_3)
{
  auto is_nan = [](float v) { return v != v; };
  float fVar1;
  float fVar2;
  int iVar3;
  HANDLE hHandle;
  float fVar4;
  float fVar5;
  LPVOID pvVar6;
  int iVar7;
  int iVar8;
  int iVar8b;
  float10 fVar9;
  int local_3c;
  int local_38;
  int local_2c;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  int unaff_EDI = (int)(intptr_t)self;

  fVar4 = param_1 / *(float*)(unaff_EDI + 0x30);
  param_1 = 0.0f;
  param_2 = param_2 / *(float*)(unaff_EDI + 0x34);
  if (in_al == '\0') {
    param_1 = -3.4028235e+38f;
  }
  local_2c = 0;
  if (0 < *(int*)(unaff_EDI + 0x58)) {
    local_38 = 0;
    local_3c = 0;
    do {
      fVar1 = *(float*)(*(int*)(unaff_EDI + 8) + 0x2a8 + local_38);
      iVar7 = *(int*)(unaff_EDI + 4) + local_3c;
      fVar5 = (float)*(int*)(iVar7 + 0x70);
      iVar8 = *(int*)(unaff_EDI + 8) + local_38;
      fVar2 = *(float*)(iVar8 + 0x2a4);
      if (*(int*)(iVar7 + 0x70) < 0) {
        fVar5 = fVar5 + 4.2949673e+09f;
      }
      fVar5 = fVar1 - (fVar5 - 1.0f) * *(float*)(iVar7 + 0x88);
      if ((((!is_nan(fVar5) && !is_nan(param_2)) &&
            ((fVar5 < param_2) != (fVar5 == param_2))) &&
           ((!is_nan(param_2) && !is_nan(fVar1)) &&
            ((param_2 < fVar1) != (param_2 == fVar1)))) &&
          (fVar2 <= fVar4)) {
        fVar1 = (float)*(int*)(iVar7 + 0x6c);
        if (*(int*)(iVar7 + 0x6c) < 0) {
          fVar1 = fVar1 + 4.2949673e+09f;
        }
        if (fVar4 <= (fVar1 - 1.0f) * *(float*)(iVar7 + 0x84) + fVar2) {
          if (*(char*)(iVar7 + 0xa0) == '\0') {
            do {
              if (param_3 == '\0') break;
              iVar3 = *(int*)(unaff_EDI + 0x88);
              hHandle = *(HANDLE*)(iVar3 + 0xc0);
              if ((DAT_00726c28 == 0xffffffff) ||
                  (pvVar6 = TlsGetValue(DAT_00726c28), pvVar6 == (LPVOID)0x0)) {
                WaitForSingleObject(hHandle, 0xffffffff);
              }
              else {
                FUN_004fac10();
              }
              *(uint32_t*)(iVar3 + 0x70) = 0;
              ReleaseMutex(*(HANDLE*)(iVar3 + 0xc0));
              FUN_00515cb0(*(uint32_t*)(unaff_EDI + 0x88));
              Sleep(10);
            } while (*(char*)(iVar7 + 0xa0) == '\0');
          }
          if (*(char*)(iVar7 + 0xa0) != '\0') {
            fVar9 = (float10)FUN_00512f70(&local_c);
            fVar9 = fVar9 -
                    (float10)*(float*)(iVar8 + 0x290) *
                    (float10)*(float*)(unaff_EDI + 0x44);
            if ((float10)param_1 < fVar9) {
              param_1 = (float)fVar9;
              *(uint32_t*)(unaff_EDI + 0x6c) = local_c;
              *(uint32_t*)(unaff_EDI + 0x70) = local_8;
              *(uint32_t*)(unaff_EDI + 0x74) = local_4;
            }
          }
        }
      }
      local_2c = local_2c + 1;
      local_3c = local_3c + 0x124;
      local_38 = local_38 + 0x2cc;
    } while (local_2c < *(int*)(unaff_EDI + 0x58));
  }
  return (float10)param_1;
}


// 0x4e7760 — observed shape
uint32_t FUN_004e7760(void* self, float param_1, float param_2)
{
  auto is_nan = [](float v) { return v != v; };
  int* piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint32_t in_eax = (uint32_t)(uintptr_t)self;
  uint16_t uVar6;
  uint32_t uVar5;
  int iVar7;
  float* pfVar8;
  int iVar9;
  int base = (int)(intptr_t)self;

  param_1 = param_1 / *(float*)(base + 0x30);
  piVar1 = (int*)(base + 0x58);
  iVar9 = 0;
  param_2 = param_2 / *(float*)(base + 0x34);
  if (0 < *piVar1) {
    iVar7 = *(int*)(base + 4);
    pfVar8 = (float*)(*(int*)(base + 8) + 0x2a4);
    do {
      fVar3 = *pfVar8;
      fVar2 = pfVar8[1];
      fVar4 = (float)*(int*)(iVar7 + 0x70);
      if (*(int*)(iVar7 + 0x70) < 0) {
        fVar4 = fVar4 + 4.2949673e+09f;
      }
      fVar4 = fVar2 - (fVar4 - 1.0f) * *(float*)(iVar7 + 0x88);
      uVar6 = (uint16_t)((uint32_t)*(int*)(iVar7 + 0x70) >> 0x10);
      in_eax = ((uint32_t)uVar6 << 16) |
               ((uint32_t)(fVar4 < param_2) << 8) |
               ((uint32_t)(is_nan(fVar4) || is_nan(param_2)) << 10) |
               ((uint32_t)(fVar4 == param_2) << 0xe);
      if ((((!is_nan(fVar4) && !is_nan(param_2)) &&
            ((fVar4 < param_2) != (fVar4 == param_2))) &&
           (in_eax = ((uint32_t)uVar6 << 16) |
                     ((uint32_t)(param_2 < fVar2) << 8) |
                     ((uint32_t)(is_nan(param_2) || is_nan(fVar2)) << 10) |
                     ((uint32_t)(param_2 == fVar2) << 0xe),
            (!is_nan(param_2) && !is_nan(fVar2)) &&
            ((param_2 < fVar2) != (param_2 == fVar2))) &&
           (in_eax = ((uint32_t)uVar6 << 16) |
                     ((uint32_t)(param_1 < fVar3) << 8) |
                     ((uint32_t)(is_nan(param_1) || is_nan(fVar3)) << 10) |
                     ((uint32_t)(param_1 == fVar3) << 0xe),
            param_1 >= fVar3)) {
        fVar2 = (float)*(int*)(iVar7 + 0x6c);
        if (*(int*)(iVar7 + 0x6c) < 0) {
          fVar2 = fVar2 + 4.2949673e+09f;
        }
        fVar3 = (fVar2 - 1.0f) * *(float*)(iVar7 + 0x84) + fVar3;
        in_eax = ((uint32_t)(uint16_t)((uint32_t)*(int*)(iVar7 + 0x6c) >> 0x10) << 16) |
                 ((uint32_t)(fVar3 < param_1) << 8) |
                 ((uint32_t)(is_nan(fVar3) || is_nan(param_1)) << 10) |
                 ((uint32_t)(fVar3 == param_1) << 0xe);
        if (fVar3 >= param_1) {
          in_eax = (in_eax & 0xffffff00u) | (uint8_t)*(char*)(iVar7 + 0xa0);
          if (*(char*)(iVar7 + 0xa0) != '\0') {
            uVar5 = FUN_004ed270();
            return uVar5;
          }
          break;
        }
      }
      iVar9 = iVar9 + 1;
      iVar7 = iVar7 + 0x124;
      pfVar8 = pfVar8 + 0xb3;
    } while (iVar9 < *piVar1);
  }
  return in_eax & 0xffffff00;
}


// 0x4e7850 — observed shape
float10 FUN_004e7850(void* self, float param_1, float param_2)
{
  auto is_nan = [](float v) { return v != v; };
  float fVar1;
  float fVar2;
  int in_EAX = (int)(intptr_t)self;
  float* pfVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;

  param_1 = param_1 / *(float*)(in_EAX + 0x30);
  iVar4 = 0;
  param_2 = param_2 / *(float*)(in_EAX + 0x34);
  if (0 < *(int*)(in_EAX + 0x58)) {
    iVar5 = *(int*)(in_EAX + 4);
    pfVar3 = (float*)(*(int*)(in_EAX + 8) + 0x2a4);
    do {
      fVar1 = pfVar3[1];
      fVar2 = (float)*(int*)(iVar5 + 0x70);
      if (*(int*)(iVar5 + 0x70) < 0) {
        fVar2 = fVar2 + 4.2949673e+09f;
      }
      fVar2 = fVar1 - (fVar2 - 1.0f) * *(float*)(iVar5 + 0x88);
      if ((((!is_nan(fVar2) && !is_nan(param_2)) &&
            ((fVar2 < param_2) != (fVar2 == param_2))) &&
           ((!is_nan(param_2) && !is_nan(fVar1)) &&
            ((param_2 < fVar1) != (param_2 == fVar1)))) &&
          (*pfVar3 <= param_1)) {
        fVar1 = (float)*(int*)(iVar5 + 0x6c);
        if (*(int*)(iVar5 + 0x6c) < 0) {
          fVar1 = fVar1 + 4.2949673e+09f;
        }
        if (param_1 <= (fVar1 - 1.0f) * *(float*)(iVar5 + 0x84) + *pfVar3) {
          if (*(char*)(iVar5 + 0xa0) != '\0') {
            fVar6 = (float10)FUN_004e9840(param_1, param_2);
            return fVar6;
          }
          break;
        }
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x124;
      pfVar3 = pfVar3 + 0xb3;
    } while (iVar4 < *(int*)(in_EAX + 0x58));
  }
  return (float10)0.0;
}


// 0x4e7950 — observed shape
void FUN_004e7950(int param_1)
{
  char cVar1;
  int iVar2;

  if ((*(char*)(param_1 + 0x78) == '\0') ||
      ((*(uint32_t*)(param_1 + 0x5c) < 10 && (*(char*)(param_1 + 0x80) == '\0')))) {
    *(int*)(param_1 + 0x5c) = *(int*)(param_1 + 0x5c) + 1;
    return;
  }
  if (*(char*)(param_1 + 0x80) != '\0') {
    *(uint8_t*)(*(int*)(param_1 + 0x88) + 0xcd) = 1;
    *(uint8_t*)(param_1 + 0x80) = 0;
  }
  *(uint32_t*)(param_1 + 0x5c) = 0;
  FUN_004ee310(0);
  iVar2 = FUN_004ee2b0();
  if (iVar2 == 0) {
    iVar2 = 0;
    do {
      cVar1 = FUN_00515cb0(*(uint32_t*)(param_1 + 0x88));
      if (cVar1 != '\0') break;
      Sleep(1000);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x1e);
  }
  if (*(char*)(param_1 + 0x7c) != '\0') {
    iVar2 = 0;
    if (0 < *(int*)(param_1 + 0x58)) {
      do {
        FUN_004eb5b0();
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int*)(param_1 + 0x58));
    }
    *(uint8_t*)(param_1 + 0x7c) = 0;
  }
}


// 0x4e7a50 — observed shape
int FUN_004e7a50(void)
{
  char cVar1;
  int iVar2;
  char local_10[16];

  iVar2 = 0;
  do {
    sprintf(local_10, "Terrain%d", iVar2);
    cVar1 = FUN_004f96a0();
    if (cVar1 == '\0') {
      return iVar2;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 100);
  return iVar2;
}


// 0x4e7a90 — observed shape
void FUN_004e7a90(int* param_1, int index)
{
  float fVar1;
  uint32_t uVar2;
  char cVar3;
  int iVar4;
  char local_10[16];

  iVar4 = index * 0x2cc + param_1[2];
  sprintf(local_10, "Terrain%d"); /* listing passes no vararg here */
  *(uint8_t*)(iVar4 + 0x200) = 0;
  cVar3 = FUN_004f96a0();
  if (cVar3 != '\0') {
    FUN_004f98b0("Heightmap", (void*)(iVar4));
    FUN_004f98b0("Terrainmap", (void*)(iVar4 + 0x80));
    FUN_004f98b0("Normalmap", (void*)(iVar4 + 0x100));
    FUN_004f98b0("Blendmap", (void*)(iVar4 + 0x180));
    FUN_004f98b0("Shadowmap", (void*)(iVar4 + 0x200));
    FUN_004f9790((void*)(iVar4 + 0x280));
    FUN_004f9790((void*)(iVar4 + 0x284));
    FUN_004f9820((void*)(iVar4 + 0x288));
    FUN_004f9820((void*)(iVar4 + 0x290));
    FUN_004f9820((void*)(iVar4 + 0x2a4));
    FUN_004f9820((void*)(iVar4 + 0x2a8));
    FUN_004f9820((void*)(iVar4 + 0x2ac));
    FUN_004f9790((void*)(iVar4 + 0x2b0));
    FUN_004f9790((void*)(iVar4 + 0x2b4));
    FUN_004f9820((void*)(iVar4 + 0x2b8));
    FUN_004f9820((void*)(iVar4 + 700));
    FUN_004f9820((void*)(iVar4 + 0x2c0));
    FUN_004f9820((void*)(iVar4 + 0x2c4));
    FUN_004f9820((void*)(iVar4 + 0x2c8));
    uVar2 = *(uint32_t*)(iVar4 + 0x288);
    *(float*)(iVar4 + 0x2c8) = *(float*)((intptr_t)param_1 + 0x38) * *(float*)(iVar4 + 0x2c8);
    *(float*)(iVar4 + 0x2c4) = *(float*)((intptr_t)param_1 + 0x3c) * *(float*)(iVar4 + 0x2c4);
    fVar1 = *(float*)((intptr_t)param_1 + 0x40);
    *(uint32_t*)(iVar4 + 0x28c) = uVar2;
    *(uint32_t*)(iVar4 + 0x294) = uVar2;
    *(float*)(iVar4 + 0x2c0) = fVar1 * *(float*)(iVar4 + 0x2c0);
    *(uint32_t*)(iVar4 + 0x298) = uVar2;
    *(uint32_t*)(iVar4 + 0x29c) = *(uint32_t*)(iVar4 + 0x290);
    *(uint32_t*)(iVar4 + 0x2a0) = *(uint32_t*)(iVar4 + 0x2ac);
  }
}


// 0x4e7c90 — observed shape
void FUN_004e7c90(int* param_1, int param_2)
{
  char cVar1;
  char local_410[16];
  uint8_t local_400[1024];

  sprintf(local_410, "Terrain%d", param_2);
  cVar1 = FUN_004f96a0();
  if (cVar1 != '\0') {
    cVar1 = FUN_004f98b0("Surfmodel", local_400);
    if (cVar1 != '\0') {
      FUN_004e99e0((char*)local_400);
    }
    cVar1 = FUN_004f98b0("Surflines", local_400);
    if (cVar1 != '\0') {
      FUN_004e9a30(param_2 * 0x124 + param_1[1]);
    }
    cVar1 = FUN_004f98b0("Treemodel", local_400);
    if (cVar1 != '\0') {
      FUN_004e9db0((char*)local_400);
    }
    cVar1 = FUN_004f98b0("Causticmodel", local_400);
    if (cVar1 != '\0') {
      FUN_004e9e00((char*)local_400);
    }
    cVar1 = FUN_004f98b0("Canopymap", local_400);
    if (cVar1 != '\0') {
      FUN_004e98d0(param_2 * 0x124 + param_1[1], (char*)local_400);
    }
  }
}


// 0x4e7db0 — observed shape
void FUN_004e7db0(int* param_1, int param_2)
{
  uint32_t* piVar1;
  uint32_t* puVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int local_214;
  char local_210[16];
  uint8_t local_200[256];
  uint8_t local_100[256];

  iVar5 = 0;
  do {
    sprintf(local_210, "Texture%d", iVar5);
    cVar4 = FUN_004f96a0();
    if (cVar4 == '\0') {
      return;
    }
    FUN_004f98b0("TextureMap", local_100);
    FUN_004f9790(&local_214);
    iVar3 = local_214;
    if (param_2 == 0) {
      iVar6 = 0;
      if (0 < param_1[0x58]) {
        do {
          FUN_00511f90(iVar3);
          iVar6 = iVar6 + 1;
        } while (iVar6 < param_1[0x58]);
      }
    }
    else {
      puVar2 = (uint32_t*)DAT_008ea110[local_214];
      if (puVar2 != (uint32_t*)0x0) {
        piVar1 = puVar2 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          (*(void (**)(int))(*puVar2))(1);
        }
        DAT_008ea110[iVar3] = 0;
      }
      FUN_00511f90(iVar3);
    }
    cVar4 = FUN_004f98b0("Color", local_200);
    if ((cVar4 != '\0') && (iVar3 == 0x30)) {
      FUN_004d02e0();
      FUN_004ef080();
    }
    cVar4 = FUN_004f98b0("Color", local_200);
    if ((cVar4 != '\0') && (iVar3 == 0x31)) {
      FUN_004d02e0();
      FUN_004ef080();
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x100);
}


// 0x4e7f00 — observed shape
void FUN_004e7f00(int* self, void* ini)
{
  char cVar1;
  int iVar2;
  uint32_t uVar3;
  uint32_t local_208;
  uint32_t local_204;
  uint8_t local_200[512];

  (void)self;
  (void)ini;
  local_208 = 0;
  do {
    FUN_004f2600(&DAT_007101a8, "LBTexture", local_208);
    cVar1 = FUN_004f96a0();
    if (cVar1 == '\0') {
      return;
    }
    FUN_004f9790(&local_204);
    FUN_004f98b0("TextureMap", local_200);
    iVar2 = FUN_00533c78(4);
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_00412cb0();
    }
    FUN_004effc0(uVar3);
    local_208 = local_208 + 1;
  } while (local_208 < 0x100);
}


// 0x4e7fe0 — observed shape
void FUN_004e7fe0(int* self, void* ini)
{
  char cVar1;
  int iVar2;
  uint32_t uVar3;
  uint32_t local_208;
  uint32_t local_204;
  uint8_t local_200[512];

  (void)self;
  (void)ini;
  local_208 = 0;
  do {
    FUN_004f2600(&DAT_007101a8, "LPTexture", local_208);
    cVar1 = FUN_004f96a0();
    if (cVar1 == '\0') {
      return;
    }
    FUN_004f9790(&local_204);
    FUN_004f98b0("TextureMap", local_200);
    iVar2 = FUN_00533c78(4);
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_00412cb0();
    }
    FUN_004effc0(uVar3);
    local_208 = local_208 + 1;
  } while (local_208 < 0x100);
}


// 0x4e80c0 — observed shape
void FUN_004e80c0(int param_1, void* ini)
{
  uint32_t* piVar1;
  HANDLE hHandle;
  char* pcVar2;
  char cVar3;
  uint32_t* puVar4;
  int iVar5;
  uint32_t uVar6;
  LPVOID pvVar7;
  uint32_t uVar8;
  char* pcVar9;
  uint32_t local_114;
  uint32_t* local_110;
  uint32_t local_10c;
  uint32_t local_108;
  uint32_t local_104;
  char local_100[8];
  uint32_t local_f8;
  uint16_t local_f4;

  (void)ini;
  local_110 = (uint32_t*)0x0;
  cVar3 = FUN_004f96a0();
  puVar4 = (uint32_t*)0x0;
  if (cVar3 != '\0') {
    FUN_004f9820((void*)(param_1 + 0x44));
    FUN_004f9790((void*)(param_1 + 0x4c));
    FUN_004f9790((void*)(param_1 + 0x50));
    FUN_004f9790((void*)(param_1 + 0x48));
    FUN_004f9790(&local_114);
    *(uint8_t*)(param_1 + 0x7b) = (uint8_t)(local_114 != 0);
    FUN_004f9790(&local_114);
    cVar3 = FUN_004f98b0("CausticImages", local_100);
    if ((cVar3 == '\0') ||
        (cVar3 = FUN_004f9790(&local_114), uVar8 = local_114, cVar3 == '\0')) {
      uVar8 = local_114;
    }
    else if (0 < (int)local_114) {
      FUN_004ebe80(local_100, (int)local_114);
    }
    *(uint8_t*)(param_1 + 0x7a) = (uint8_t)(uVar8 != 0);
    FUN_004f9820((void*)(param_1 + 0x40));
    FUN_004f9820((void*)(param_1 + 0x3c));
    FUN_004f9820((void*)(param_1 + 0x38));
    puVar4 = local_110;
  }
  cVar3 = FUN_004f96a0();
  if (cVar3 != '\0') {
    FUN_004f9790(&local_114);
    FUN_004f98b0("CanopyModel", local_100);
    FUN_004f9820(&local_10c);
    FUN_004f9820(&local_108);
    FUN_004f9820(&local_104);
    puVar4 = (uint32_t*)FUN_00500600();
    if (puVar4 == (uint32_t*)0x0) {
      FUN_004f8bd0("Error loading canopy model: %s", local_100);
    }
    else {
      puVar4[1] = puVar4[1] + 1;
      local_110 = puVar4;
      iVar5 = FUN_00533c78(0x18);
      uVar8 = local_114;
      if (iVar5 == 0) {
        uVar6 = 0;
      }
      else {
        if (puVar4[0x30] == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = *(int*)puVar4[0x2e];
        }
        if (iVar5 != 0) {
          *(int*)(iVar5 + 4) = *(int*)(iVar5 + 4) + 1;
        }
        uVar6 = (uint32_t)FUN_004ee1c0(iVar5, local_114);
      }
      *(uint32_t*)(param_1 + 0x84) = uVar6;
      if (uVar8 == 0) {
        iVar5 = 0x14;
      }
      else {
        iVar5 = (int)uVar8 / 2;
      }
      FUN_004ee100((int)uVar6, iVar5);
      FUN_004e93b0(*(uint32_t*)(param_1 + 0x84), local_10c, local_108, local_104);
    }
    puVar4 = local_110;
  }
  cVar3 = FUN_004f96a0();
  if (cVar3 != '\0') {
    local_114 = 0;
    do {
      uVar8 = local_114;
      switch (local_114) {
      case 0:
        strncpy(local_100, "Recalc_", 8);
        break;
      case 1:
        strncpy(local_100, "Unstream", 8);
        ((uint8_t*)&local_f8)[0] = 'M';
        ((uint8_t*)&local_f8)[1] = 'a';
        ((uint8_t*)&local_f8)[2] = 'p';
        ((uint8_t*)&local_f8)[3] = '_';
        local_f4 = (uint16_t)(local_f4 & 0xff00);
        break;
      case 2:
        strncpy(local_100, "StreamMa", 8);
        ((uint8_t*)&local_f8)[0] = 'p';
        ((uint8_t*)&local_f8)[1] = '_';
        ((uint8_t*)&local_f8)[2] = '\0';
        break;
      case 3:
        strncpy(local_100, "Unstream", 8);
        ((uint8_t*)&local_f8)[0] = 'C';
        ((uint8_t*)&local_f8)[1] = 'e';
        ((uint8_t*)&local_f8)[2] = 'l';
        ((uint8_t*)&local_f8)[3] = 'l';
        local_f4 = 0x5f;
        break;
      case 4:
        strncpy(local_100, "CreateCe", 8);
        ((uint8_t*)&local_f8)[0] = 'l';
        ((uint8_t*)&local_f8)[1] = 'l';
        ((uint8_t*)&local_f8)[2] = '_';
        ((uint8_t*)&local_f8)[3] = '\0';
        break;
      case 5:
        strncpy(local_100, "StreamCe", 8);
        ((uint8_t*)&local_f8)[0] = 'l';
        ((uint8_t*)&local_f8)[1] = 'l';
        ((uint8_t*)&local_f8)[2] = '_';
        ((uint8_t*)&local_f8)[3] = '\0';
        break;
      }
      pcVar2 = (char*)((uintptr_t)&local_104 + 3);
      do {
        pcVar9 = pcVar2;
        pcVar2 = pcVar9 + 1;
      } while (pcVar9[1] != '\0');
      strncpy(pcVar9 + 1, "RADIUS", 7);
      cVar3 = FUN_004f9820(&local_10c);
      hHandle = DAT_0072705c;
      if (cVar3 != '\0') {
        iVar5 = *(int*)(param_1 + 0x88);
        if ((DAT_00726c28 == 0xffffffff) ||
            (pvVar7 = TlsGetValue(DAT_00726c28), pvVar7 == (LPVOID)0x0)) {
          WaitForSingleObject(hHandle, 0xffffffff);
        }
        else {
          FUN_004fac10();
        }
        *(uint32_t*)(iVar5 + 0xa4 + local_114 * 4) = local_10c;
        ReleaseMutex(DAT_0072705c);
        uVar8 = local_114;
      }
      local_114 = uVar8 + 1;
    } while (local_114 < 6);
    puVar4 = local_110;
  }
  if (puVar4 != (uint32_t*)0x0) {
    piVar1 = (uint32_t*)(puVar4 + 1);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (*(void (**)(int))(*puVar4))(1);
    }
  }
}


// 0x4e8500 — observed shape
void FUN_004e8500(void* self)
{
  uint32_t* puVar1;
  uint32_t* puVar2;
  int in_EAX = (int)(intptr_t)self;

  puVar1 = *(uint32_t**)(in_EAX + 0xb0);
  while (puVar1 != (uint32_t*)0x0) {
    puVar2 = puVar1 + 2;
    puVar1 = (uint32_t*)*puVar1;
    operator_delete((void*)*puVar2);
  }
  puVar1 = *(uint32_t**)(in_EAX + 0xb0);
  while (puVar1 != (uint32_t*)0x0) {
    puVar2 = (uint32_t*)*puVar1;
    (*(void (**)(void*))(*(int*)(in_EAX + 0xac) + 8))((void*)puVar1);
    puVar1 = puVar2;
  }
  *(uint32_t*)(in_EAX + 0xb8) = 0;
  *(uint32_t*)(in_EAX + 0xb0) = 0;
  *(uint32_t*)(in_EAX + 0xb4) = 0;
}
