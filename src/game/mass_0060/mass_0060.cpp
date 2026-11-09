#include <cstdint>
#include <cstddef>
#include <windows.h>

extern uint32_t DAT_007179b0[];
extern void FUN_005002f0();
extern void FUN_004f8f50();
extern void operator_delete__(void*);
extern void FUN_004f8fa0(void*, int);
extern uint8_t FUN_004f96a0();
extern void FUN_004f8bd0(const char*, int);
extern uint8_t FUN_004f9790(void**);
extern void FUN_004f98b0(const char*, void*);
extern void FUN_004f9820(void*);
extern uint32_t FUN_00500850();
extern void FUN_0051ac30(uint32_t);
extern void* thunk_FUN_00533c78(int);
extern void FUN_004127b0(void*, uint32_t, uint32_t, void*);
extern void FUN_004f2600(void*, int);
extern void FUN_004e0910(void*, void*);
extern uint32_t* FUN_00500600();
extern void FUN_004e6480(int, int);
extern uint32_t* FUN_0057eca0();
extern void FUN_00514f80(void*, void*, int, int);
extern void FUN_004e6320();
extern void FUN_004e6420();
extern void FUN_004e59f0(void*);
extern void operator_delete(void*);
extern uint32_t* DAT_Ptr_008cac80;
extern uint32_t DAT_007264a8;
extern uint8_t DAT_007264a4;
extern uint8_t DAT_008cac84;
extern uint32_t DAT_008cac7c;
extern uint32_t DAT_008cac8c;
extern uint32_t DAT_008cac68;
extern uint32_t DAT_008cac88;
extern uint32_t DAT_008cac6c;
extern uint32_t DAT_008cac60;
extern uint32_t DAT_008cac64;
extern uint32_t DAT_008cac70;
extern uint32_t DAT_008cac74;
extern uint32_t DAT_008cac78;
extern uint32_t DAT_007264b8;
extern uint32_t DAT_008cac94;
extern uint32_t DAT_008cac90;
extern uint32_t DAT_007264ac;
extern uint32_t DAT_007264b0;
extern uint32_t DAT_007264b4;
extern uint32_t DAT_008cac98;
extern uint8_t DAT_007264bc;
extern uint32_t* DAT_008ea06c;
extern uint32_t DAT_008cacc8;
extern void* PTR_FUN_007108ac;
extern void* PTR_LAB_0070f968;
extern void* PTR_FUN_0070f980;
extern void* PTR_FUN_0070f918;
extern void* PTR_LAB_0070f95c;
extern void* PTR_FUN_0070f940;
extern void* PTR_FUN_0070f924;
extern void* PTR_FUN_00717a84;
extern void* LAB_004c2970;
extern uint32_t* DAT_00726bc8;
extern uint32_t* DAT_00726bd4;
extern uint32_t* DAT_00726be0;
extern uint32_t* DAT_008ea064;
extern uint32_t* DAT_008ea068;

// 0x4e45e0 — observed shape
void FUN_004e45e0(void* self, int in_ECX, int in_EDX, int param_1)
{
  char* base = (char*)self;
  *(int*)(base + 0xfc) = in_ECX;
  *(int*)(base + 0x100) = in_EDX;
  *(int*)(base + 0x104) = param_1;
  if (((in_ECX != 0) || (in_EDX != 0)) || (param_1 != 0)) {
    *(unsigned char*)(base + 0xf8) = 1;
    return;
  }
  if (*(int*)(base + 0x1c) != 0) {
    uint32_t* puVar3 = (uint32_t*)(*(int*)(base + 0x1c) + 0x38);
    uint32_t* puVar2 = DAT_007179b0;
    for (int iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  int iVar1 = 9;
  if (*(int*)(base + 0xf4) == 0) {
    uint32_t* puVar2 = DAT_007179b0;
    uint32_t* puVar3 = (uint32_t*)(*(int*)(base + 0x14) + 0x38);
    for (; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    return;
  }
  {
    uint32_t* puVar2 = DAT_007179b0;
    uint32_t* puVar3 = (uint32_t*)(*(int*)(base + 8) + 0x38);
    for (; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
}

// 0x4e4660 — observed shape
void FUN_004e4660(int param_1)
{
  unsigned char* local_106c = nullptr;
  uint32_t local_1068 = 0;
  uint32_t local_105c = 0;
  uint32_t local_1050 = 1;
  uint32_t local_1058 = 0;
  uint32_t local_1054 = 0;
  uint32_t local_1060 = 0;
  void** local_1064 = (void**)&PTR_FUN_007108ac;
  uint32_t local_1064b = 0;
  (void)local_1064b;
  unsigned char auStack_1000[1024];
  unsigned char local_c00[1024];
  unsigned char local_800[1024];
  unsigned char local_400[1020];
  void* pvStack_1008 = nullptr;
  uint32_t* puStack_1040 = nullptr;
  uint32_t* puStack_103c = nullptr;
  int iStack_1038 = 0;
  (void)puStack_1040; (void)puStack_103c; (void)iStack_1038; (void)pvStack_1008;
  FUN_005002f0();
  if (local_106c < (unsigned char*)0xb) {
    FUN_004f8f50();
    uint32_t* puVar4 = (uint32_t*)(param_1 + -8);
    if (puVar4 == (uint32_t*)0x0) {
      return;
    }
    if (puVar4 == &DAT_008cacc8) {
      return;
    }
    operator_delete__(puVar4);
    return;
  }
  FUN_004f8fa0(&local_1064,param_1);
  uint8_t cVar3 = FUN_004f96a0();
  if (cVar3 == '\0') {
    FUN_004f8bd0("[WaterSparkle] Error, could not read ini file: %s",param_1);
    FUN_004f8f50();
    goto LAB_004e4cda;
  }
  cVar3 = FUN_004f9790((void**)&local_106c);
  if (cVar3 != '\0') {
    DAT_007264a4 = local_106c != (unsigned char*)0x0;
  }
  cVar3 = FUN_004f9790((void**)&local_106c);
  if (cVar3 != '\0') {
    DAT_008cac84 = local_106c != (unsigned char*)0x0;
  }
  FUN_004f9790((void**)&local_106c);
  DAT_007264a8 = (uint32_t)(size_t)local_106c;
  FUN_004f98b0("SparkleTextures",local_800);
  FUN_004f9790((void**)&local_106c);
  DAT_008cac7c = (uint32_t)(size_t)local_106c;
  FUN_004f98b0("SparkleBaseTexture",local_c00);
  FUN_004f98b0("SparkleDetailTexture",local_400);
  FUN_004f9820(&DAT_008cac8c);
  uint32_t* puVar2 = (uint32_t*)(size_t)DAT_007264a8;
  if (DAT_008cac84 == '\0') {
    uint32_t uVar7 = FUN_00500850();
    FUN_0051ac30(uVar7);
    uVar7 = FUN_00500850();
    FUN_0051ac30(uVar7);
  }
  else {
    uint32_t* puVar4 = (uint32_t*)thunk_FUN_00533c78((int)DAT_007264a8 * 4 + 4);
    int iVar8 = 0;
    if (puVar4 == (uint32_t*)0x0) {
      DAT_Ptr_008cac80 = (uint32_t*)0x0;
    }
    else {
      *puVar4 = (uint32_t)(size_t)puVar2;
      FUN_004127b0(puVar4 + 1,4,(uint32_t)(size_t)puVar2,&LAB_004c2970);
      DAT_Ptr_008cac80 = puVar4 + 1;
    }
    if (0 < (int)DAT_007264a8) {
      do {
        local_106c = (unsigned char*)&DAT_008cacc8;
        FUN_004f2600(local_800,iVar8);
        puVar2 = (uint32_t*)local_106c;
        uint32_t* puVar5 = (uint32_t*)FUN_00500850();
        uint32_t* puVar6 = (uint32_t*)DAT_Ptr_008cac80[iVar8];
        uint32_t* puVar4b = DAT_Ptr_008cac80 + iVar8;
        if (puVar6 != puVar5) {
          if (puVar6 != (uint32_t*)0x0) {
            int* piVar1 = (int*)puVar6 + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
              (*(void(**)(uint32_t*))(void*)*puVar6)(1);
            }
          }
          *puVar4b = (uint32_t)(size_t)puVar5;
          if (puVar5 != (uint32_t*)0x0) {
            puVar5[1] = puVar5[1] + 1;
          }
        }
        if (DAT_Ptr_008cac80 == (uint32_t*)0x0) {
          if (PTR_FUN_00717a84 != (void*)0x0) {
            (*(void(*)(uint32_t*, const char*, int))(PTR_FUN_00717a84))(puVar2,"Could not find Sparkle Texture!",0);
          }
          uint32_t* puVar4c = (uint32_t*)((unsigned char*)puVar2 + -8);
          if ((puVar4c != (uint32_t*)0x0) && (puVar4c != &DAT_008cacc8)) {
            operator_delete__(puVar4c);
          }
          FUN_004f8f50();
          goto LAB_004e4cda;
        }
        {
          uint32_t* puVar4d = (uint32_t*)((unsigned char*)puVar2 + -8);
          if ((puVar4d != (uint32_t*)0x0) && (puVar4d != &DAT_008cacc8)) {
            operator_delete__(puVar4d);
          }
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < (int)DAT_007264a8);
    }
  }
  FUN_004f9820(&DAT_008cac68);
  FUN_004f9820(&DAT_008cac88);
  FUN_004f9820(&DAT_008cac6c);
  FUN_004f9820(&DAT_008cac60);
  FUN_004f9820(&DAT_008cac64);
  FUN_004f9820(&DAT_008cac70);
  FUN_004f9820(&DAT_008cac74);
  FUN_004f9820(&DAT_008cac78);
  FUN_004f9820(&DAT_007264b8);
  FUN_004f98b0("SparkleAlphaFunction",auStack_1000);
  FUN_004f9820(&local_106c);
  FUN_004f9820(&local_1068);
  FUN_004e0910(local_106c,&local_1068);
  FUN_004f98b0("SparkleRotationFunction",auStack_1000);
  FUN_004f9820(&local_106c);
  FUN_004f9820(&local_1068);
  FUN_004e0910(local_106c,&local_1068);
  FUN_004f98b0("SparkleScaleFunction",auStack_1000);
  FUN_004f9820(&local_106c);
  FUN_004f9820(&local_1068);
  FUN_004e0910(local_106c,&local_1068);
  FUN_004f98b0("SwirlModel",auStack_1000);
  FUN_004f9820(&DAT_008cac94);
  FUN_004f9820(&DAT_008cac90);
  FUN_004f9820(&DAT_007264ac);
  FUN_004f9820(&DAT_007264b0);
  FUN_004f9820(&DAT_007264b4);
  FUN_004f9820(&DAT_008cac98);
  cVar3 = FUN_004f9790((void**)&local_106c);
  if (cVar3 != '\0') {
    DAT_007264bc = local_106c != (unsigned char*)0x0;
  }
  {
    uint32_t* puVar6 = FUN_00500600();
    uint32_t* puVar4 = DAT_008ea06c;
    if (DAT_008ea06c == puVar6) {
LAB_004e4b0a:
      if (DAT_008ea06c == (uint32_t*)0x0) goto LAB_004e4b0e;
    }
    else {
      if ((DAT_008ea06c != (uint32_t*)0x0) &&
         (cVar3 = (uint8_t)DAT_008ea06c[1], DAT_008ea06c[1] = cVar3 + -1, cVar3 + -1 == 0)) {
        (*(void(**)(uint32_t*))(void*)*puVar4)(1);
      }
      DAT_008ea06c = puVar6;
      if (puVar6 != (uint32_t*)0x0) {
        puVar6[1] = puVar6[1] + 1;
        goto LAB_004e4b0a;
      }
LAB_004e4b0e:
      if (PTR_FUN_00717a84 != (void*)0x0) {
        (*(void(*)(unsigned char*, const char*, int))(PTR_FUN_00717a84))(auStack_1000,"Error loading swirl model",0);
      }
    }
  }
  FUN_004e6480(1,1);
  {
    uint32_t* puVar4 = FUN_0057eca0();
    puVar4[2] = (uint32_t)(size_t)&local_1064;
    *puVar4 = 0;
    puVar4[1] = (uint32_t)(size_t)puStack_103c;
    if (puStack_103c == (uint32_t*)0x0) {
      puStack_1040 = puVar4;
    }
    else {
      *puStack_103c = (uint32_t)(size_t)puVar4;
    }
    iStack_1038 = iStack_1038 + 1;
    puStack_103c = puVar4;
  }
  FUN_00514f80(DAT_008ea06c,&local_1064,0,0);
  FUN_004e6320();
  FUN_004e6420();
  FUN_004e6420();
  operator_delete__(pvStack_1008);
  FUN_004f8f50();
LAB_004e4cda:
  if ((param_1 != 8) && ((uint32_t*)(param_1 + -8) != &DAT_008cacc8)) {
    operator_delete__((uint32_t*)(param_1 + -8));
  }
  (void)local_105c; (void)local_1050; (void)local_1058; (void)local_1054; (void)local_1060;
}

// 0x4e4d00 — observed shape
void FUN_004e4d00(void* self, uint8_t param_1)
{
  FUN_004e6320();
  *(void**)self = PTR_LAB_0070f95c;
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x4e4d30 — observed shape
void FUN_004e4d30(void)
{
  if (DAT_Ptr_008cac80 != 0) {
    uint32_t uVar7 = 0;
    uint32_t* iVar4 = DAT_Ptr_008cac80;
    if (DAT_007264a8 != 0) {
      do {
        uint32_t* puVar3 = *(uint32_t**)(iVar4 + uVar7);
        uint32_t* puVar2 = iVar4 + uVar7;
        if (puVar3 != (uint32_t*)0x0) {
          int* piVar1 = (int*)puVar3 + 1;
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            (*(void(**)(uint32_t*))(void*)*puVar3)(1);
            iVar4 = DAT_Ptr_008cac80;
          }
          *puVar2 = 0;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < DAT_007264a8);
    }
    if (iVar4 != 0) {
      int iVar5 = *(int*)(iVar4 + -1);
      uint32_t* iVar6 = iVar4 + iVar5;
      if (-1 < iVar5 + -1) {
        do {
          uint32_t* puVar2 = *(uint32_t**)(iVar6 + -1);
          iVar6 = iVar6 + -1;
          if (puVar2 != (uint32_t*)0x0) {
            int* piVar1 = (int*)puVar2 + 1;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
              (*(void(**)(uint32_t*))(void*)*puVar2)(1);
            }
          }
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      operator_delete__(iVar4 + -1);
      DAT_Ptr_008cac80 = 0;
    }
  }
  {
    uint32_t* puVar2 = DAT_00726bc8;
    if (DAT_00726bc8 != (uint32_t*)0x0) {
      int iVar4 = DAT_00726bc8[1];
      DAT_00726bc8[1] = iVar4 + -1;
      if (iVar4 + -1 == 0) {
        (*(void(**)(uint32_t*))(void*)*puVar2)(1);
      }
      DAT_00726bc8 = (uint32_t*)0x0;
    }
  }
  {
    uint32_t* puVar2 = DAT_00726bd4;
    if (DAT_00726bd4 != (uint32_t*)0x0) {
      int iVar4 = DAT_00726bd4[1];
      DAT_00726bd4[1] = iVar4 + -1;
      if (iVar4 + -1 == 0) {
        (*(void(**)(uint32_t*))(void*)*puVar2)(1);
      }
      DAT_00726bd4 = (uint32_t*)0x0;
    }
  }
  {
    uint32_t* puVar2 = DAT_00726be0;
    if (DAT_00726be0 != (uint32_t*)0x0) {
      int iVar4 = DAT_00726be0[1];
      DAT_00726be0[1] = iVar4 + -1;
      if (iVar4 + -1 == 0) {
        (*(void(**)(uint32_t*))(void*)*puVar2)(1);
      }
      DAT_00726be0 = (uint32_t*)0x0;
    }
  }
  {
    uint32_t* puVar2 = DAT_008ea064;
    if (DAT_008ea064 != (uint32_t*)0x0) {
      int iVar4 = DAT_008ea064[1];
      DAT_008ea064[1] = iVar4 + -1;
      if (iVar4 + -1 == 0) {
        (*(void(**)(uint32_t*))(void*)*puVar2)(1);
      }
      DAT_008ea064 = (uint32_t*)0x0;
    }
  }
  {
    uint32_t* puVar2 = DAT_008ea068;
    if (DAT_008ea068 != (uint32_t*)0x0) {
      int iVar4 = DAT_008ea068[1];
      DAT_008ea068[1] = iVar4 + -1;
      if (iVar4 + -1 == 0) {
        (*(void(**)(uint32_t*))(void*)*puVar2)(1);
      }
      DAT_008ea068 = (uint32_t*)0x0;
    }
  }
  {
    uint32_t* puVar2 = DAT_008ea06c;
    if (DAT_008ea06c != (uint32_t*)0x0) {
      int iVar4 = DAT_008ea06c[1];
      DAT_008ea06c[1] = iVar4 + -1;
      if (iVar4 + -1 == 0) {
        (*(void(**)(uint32_t*))(void*)*puVar2)(1);
      }
      DAT_008ea06c = (uint32_t*)0x0;
    }
  }
}

// 0x4e4ea0 — observed shape
void FUN_004e4ea0(void* self)
{
  uint32_t* in_ECX = (uint32_t*)self;
  uint32_t* local_4 = in_ECX;
  int iVar2 = (int)(size_t)in_ECX[1];
  if (iVar2 != 0) {
    if (*(uint32_t**)(iVar2 + 0x24) != (uint32_t*)0x0) {
      (*(void(**)(uint32_t**, int))(void*)(**(uint32_t**)(iVar2 + 0x24) + 0x74))(&local_4,iVar2);
      if ((local_4 != (uint32_t*)0x0) &&
         (iVar2 = local_4[1], local_4[1] = iVar2 + -1, iVar2 + -1 == 0)) {
        (*(void(**)(uint32_t*))(void*)*local_4)(1);
      }
    }
    uint32_t* puVar3 = (uint32_t*)(size_t)in_ECX[1];
    if (puVar3 != (uint32_t*)0x0) {
      int* piVar1 = (int*)puVar3 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(void(**)(uint32_t*))(void*)*puVar3)(1);
      }
      in_ECX[1] = 0;
    }
  }
  iVar2 = (int)(size_t)in_ECX[0xd];
  if (iVar2 != 0) {
    if (*(uint32_t**)(iVar2 + 0x24) != (uint32_t*)0x0) {
      (*(void(**)(uint32_t**, int))(void*)(**(uint32_t**)(iVar2 + 0x24) + 0x74))(&local_4,iVar2);
      if ((local_4 != (uint32_t*)0x0) &&
         (iVar2 = local_4[1], local_4[1] = iVar2 + -1, iVar2 + -1 == 0)) {
        (*(void(**)(uint32_t*))(void*)*local_4)(1);
      }
    }
    uint32_t* puVar3 = (uint32_t*)(size_t)in_ECX[0xd];
    if (puVar3 != (uint32_t*)0x0) {
      int* piVar1 = (int*)puVar3 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(void(**)(uint32_t*))(void*)*puVar3)(1);
      }
      in_ECX[0xd] = 0;
    }
  }
  {
    uint32_t* puVar3 = (uint32_t*)(size_t)in_ECX[0xd];
    if (puVar3 != (uint32_t*)0x0) {
      int* piVar1 = (int*)puVar3 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(void(**)(uint32_t*))(void*)*puVar3)(1);
      }
    }
  }
  {
    uint32_t* puVar3 = (uint32_t*)(size_t)in_ECX[1];
    if (puVar3 != (uint32_t*)0x0) {
      int* piVar1 = (int*)puVar3 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(void(**)(uint32_t*))(void*)*puVar3)(1);
      }
    }
  }
}

extern float DAT_007253bc;
extern int32_t DAT_00814304;
extern int32_t DAT_00814308;
extern float _DAT_008cac60;
extern float _DAT_008cac64;
extern float _DAT_008cac70;
extern float _DAT_008cac74;
extern uint32_t* DAT_008e9ff4;
extern void FUN_004e62b0();
extern void FUN_004e5530(uint32_t);
extern int FUN_005f0ddc();
extern void FUN_0053c7c0(float);
extern float FUN_004e0a80(float);
extern void FUN_004e09b0(float);
extern float FUN_004a9600();
extern void FUN_00533db0(int);
extern void FUN_004aad70(void*);
extern void FUN_004e28a0(void*);

// 0x4e4f70 — observed shape
void FUN_004e4f70(char* param_1, char param_2)
{
  if (*param_1 != param_2) {
    FUN_004e59f0(param_1);
    *(unsigned char*)(*(int*)(param_1 + 4) + 0x20) = *(unsigned char*)(*(int*)(param_1 + 4) + 0x20) & 0xfe;
    *param_1 = param_2;
    if (param_2 == '\0') {
      if (*(int*)(param_1 + 4) != 0) {
        uint16_t* puVar1 = (uint16_t*)(*(int*)(param_1 + 4) + 0x20);
        *puVar1 = *puVar1 | 1;
        *(uint16_t*)(*(int*)(param_1 + 0x34) + 0x20) =
             *(uint16_t*)(*(int*)(param_1 + 0x34) + 0x20) | 1;
      }
    }
    else {
      float fVar2 = (float)((long double)DAT_007253bc * (long double)1.4629180792671596e-09);
      long double fVar13 = (long double)sin((long double)DAT_007253bc * (long double)1.4629180792671596e-09);
      *(float*)(param_1 + 0x14) = (float)-fVar13;
      fVar13 = (long double)cos((long double)fVar2);
      *(float*)(param_1 + 0x18) = (float)-fVar13;
      FUN_004e62b0();
      float fVar5 = _DAT_008cac74 + _DAT_008cac70;
      float fVar6 = _DAT_008cac70 - _DAT_008cac74;
      int iVar8 = *(int*)(param_1 + 0x1c) * 0x343fd + 0x269ec3;
      *(int*)(param_1 + 0x1c) = iVar8;
      float fVar7 = (float)iVar8;
      if (iVar8 < 0) {
        fVar7 = fVar7 + 4.2949673e+09f;
      }
      fVar6 = fVar7 * (fVar5 - fVar6) * 2.3283064e-10f + fVar6;
      *(float*)(param_1 + 0x20) = fVar6;
      *(float*)(*(int*)(param_1 + 4) + 0x68) = (fVar6 < 0.0f ? -fVar6 : fVar6);
      FUN_004e5530(DAT_008cac78);
      param_1[0x10] = '\0';
      param_1[0x11] = '\0';
      param_1[0x12] = '\0';
      param_1[0x13] = '\0';
      *(int*)(param_1 + 0x1c) = *(int*)(param_1 + 0x1c) * 0x343fd + 0x269ec3;
      iVar8 = *(int*)(param_1 + 0x1c) * 0x343fd + 0x269ec3;
      *(int*)(param_1 + 0x1c) = iVar8;
      fVar13 = (long double)iVar8;
      if (iVar8 < 0) {
        fVar13 = fVar13 + (long double)4294967296.0;
      }
      cos((double)(fVar13 * (long double)1.462918119976564e-09));
      int iVar9 = FUN_005f0ddc();
      int iVar3 = DAT_00814304 / 1000;
      sin(0.0);
      int iVar10 = FUN_005f0ddc();
      int iVar4 = DAT_00814308 / 1000;
      FUN_0053c7c0(fVar2);
      iVar8 = *(int*)(param_1 + 4);
      *(float*)(iVar8 + 0x5c) = (float)(iVar3 - iVar9);
      *(float*)(iVar8 + 0x60) = (float)(iVar4 - iVar10);
      *(uint32_t*)(iVar8 + 100) = 0;
      {
        uint32_t local_24[9] = {};
        uint32_t* puVar12 = (uint32_t*)(*(int*)(param_1 + 4) + 0x38);
        uint32_t* puVar11 = local_24;
        for (int iVar8b = 9; iVar8b != 0; iVar8b = iVar8b + -1) {
          *puVar12 = *puVar11;
          puVar11 = puVar11 + 1;
          puVar12 = puVar12 + 1;
        }
      }
      {
        float fVar2b = _DAT_008cac64 + _DAT_008cac60;
        float fVar6b = _DAT_008cac60 - _DAT_008cac64;
        int iVar8b = *(int*)(param_1 + 0x1c) * 0x343fd + 0x269ec3;
        *(int*)(param_1 + 0x1c) = iVar8b;
        float fVar5b = (float)iVar8b;
        if (iVar8b < 0) {
          fVar5b = fVar5b + 4.2949673e+09f;
        }
        param_1[0x28] = '\0';
        param_1[0x29] = '\0';
        param_1[0x2a] = '\0';
        param_1[0x2b] = '\0';
        param_1[0x2c] = '\0';
        param_1[0x2d] = '\0';
        param_1[0x2e] = '\0';
        param_1[0x2f] = '\0';
        *(float*)(param_1 + 0xc) = fVar5b * (fVar2b - fVar6b) * 2.3283064e-10f + fVar6b;
      }
      FUN_00533db0(8);
      if (DAT_008cac84 != '\0') {
        FUN_004aad70(*DAT_Ptr_008cac80);
      }
      if (DAT_007264a4 != '\0') {
        int iVar8b = *(int*)(param_1 + 4);
        if (iVar8b != 0) {
          *(int*)(iVar8b + 4) = *(int*)(iVar8b + 4) + 1;
        }
        FUN_004e28a0((void*)(size_t)iVar8b);
        return;
      }
    }
  }
}

// 0x4e5240 — observed shape
void FUN_004e5240(void* self, uint32_t param_1)
{
  int iVar4 = *(int*)((char*)self + 4);
  if (((iVar4 != 0) && (*(int*)(iVar4 + 0xc0) != 0)) && (**(int**)(iVar4 + 0xb8) != 0)) {
    if (*(int*)(iVar4 + 0xc0) == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = **(int**)(iVar4 + 0xb8);
    }
    uint32_t uVar2 = 0;
    if (*(int16_t*)(*(int*)(iVar4 + 0xbc) + 0xc) != 0) {
      uint32_t* puVar3 = (uint32_t*)(*(int*)(*(int*)(iVar4 + 0xbc) + 0x28) + 0xc);
      do {
        *puVar3 = param_1;
        uVar2 = uVar2 + 1;
        puVar3 = puVar3 + 4;
      } while (uVar2 < *(uint16_t*)(*(int*)(iVar4 + 0xbc) + 0xc));
    }
    unsigned char* pbVar1 = (unsigned char*)(*(int*)(iVar4 + 0xbc) + 0x32);
    *pbVar1 = *pbVar1 | 4;
  }
}

// 0x4e52c0 — observed shape
void FUN_004e52c0(void* self, float* in_ECX)
{
  int unaff_EBX = (int)(size_t)self;
  int iVar5 = *(int*)(unaff_EBX + 4);
  if (((iVar5 != 0) && (*(int*)(iVar5 + 0xc0) != 0)) && (**(int**)(iVar5 + 0xb8) != 0)) {
    if (*(int*)(iVar5 + 0xc0) == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = **(int**)(iVar5 + 0xb8);
    }
    uint32_t uVar4 = 0;
    if (*(int16_t*)(*(int*)(iVar5 + 0xbc) + 0xc) != 0) {
      float* pfVar3 = (float*)(*(int*)(*(int*)(iVar5 + 0xbc) + 0x28) + 8);
      do {
        float fVar2;
        if (*in_ECX <= 0.0f) {
          fVar2 = 0.0f;
        }
        else if (1.0f <= *in_ECX) {
          fVar2 = 1.0f;
        }
        else {
          fVar2 = *in_ECX;
        }
        pfVar3[-2] = fVar2;
        if (in_ECX[1] <= 0.0f) {
          fVar2 = 0.0f;
        }
        else if (1.0f <= in_ECX[1]) {
          fVar2 = 1.0f;
        }
        else {
          fVar2 = in_ECX[1];
        }
        pfVar3[-1] = fVar2;
        if (in_ECX[2] <= 0.0f) {
          fVar2 = 0.0f;
        }
        else if (1.0f <= in_ECX[2]) {
          fVar2 = 1.0f;
        }
        else {
          fVar2 = in_ECX[2];
        }
        *pfVar3 = fVar2;
        uVar4 = uVar4 + 1;
        pfVar3 = pfVar3 + 4;
      } while (uVar4 < *(uint16_t*)(*(int*)(iVar5 + 0xbc) + 0xc));
    }
    unsigned char* pbVar1 = (unsigned char*)(*(int*)(iVar5 + 0xbc) + 0x32);
    *pbVar1 = *pbVar1 | 4;
  }
  if (*(int*)(unaff_EBX + 0x34) != 0) {
    float local_c = *in_ECX;
    float local_8 = in_ECX[1];
    float local_4 = in_ECX[2];
    extern void FUN_004c27a0(int, void*);
    FUN_004c27a0(*(int*)(unaff_EBX + 0x34), &local_c);
  }
}

// 0x4e5440 — observed shape
void FUN_004e5440(int param_1, float param_2)
{
  FUN_0053c7c0(param_2 * 0.017453292f);
  int iVar1 = *(int*)(param_1 + 4);
  if (((iVar1 != 0) && (*(int*)(iVar1 + 0xc0) != 0)) && (**(int**)(iVar1 + 0xb8) != 0)) {
    if (*(int*)(iVar1 + 0xc0) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = **(int**)(iVar1 + 0xb8);
    }
    uint32_t local_24[9] = {};
    uint32_t* puVar4 = (uint32_t*)(iVar1 + 0x38);
    uint32_t* puVar3 = local_24;
    for (int iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
}

// 0x4e54b0 — observed shape
void FUN_004e54b0(void* self, uint32_t param_1)
{
  int unaff_EDI = (int)(size_t)self;
  if (DAT_008cac84 != '\0') {
    param_1 = param_1 % DAT_007264a8;
    int iVar1 = *(int*)(unaff_EDI + 4);
    if ((((iVar1 != 0) && (*(int*)(iVar1 + 0xc0) != 0)) && (**(int**)(iVar1 + 0xb8) != 0)) &&
       (param_1 != *(uint32_t*)(unaff_EDI + 0x28))) {
      FUN_00533db0(8);
      *(uint32_t*)(unaff_EDI + 0x28) = param_1;
      *(uint32_t*)(unaff_EDI + 0x2c) = 0;
      FUN_004aad70(nullptr);
      return;
    }
  }
}

extern uint32_t* FUN_005412c0(int);
extern uint32_t DAT_00717780;
extern uint32_t DAT_00717784;
extern uint32_t DAT_00717788;
extern uint32_t DAT_0071779c;
extern uint32_t DAT_007177a0;
extern uint32_t DAT_007177a4;
extern uint32_t DAT_007177a8;
extern uint32_t DAT_00727424;
extern uint32_t DAT_00727428;
extern uint32_t DAT_0072742c;
extern void* DAT_00727598;
extern void FUN_004aac10(void*);
extern int FUN_00533c78(int);
extern void* FUN_005446d0();
extern void* FUN_004aae10();
extern float _DAT_008cac88;
extern float _DAT_007264b0;
extern float _DAT_007264b4;
extern float _DAT_008cac98;
extern float _DAT_008cac94;
extern float _DAT_007264ac;
extern void FUN_00533d10(float, int);
extern void FUN_004e0a80b(float);
extern void FUN_00540c50();
extern void FUN_004127b0w(void*, uint32_t, uint32_t, void*);
extern void* FUN_0053bb30(int);
extern void* FUN_005473e0(int, void*, void*, void*, void*, int, int, int, int, void*, void*);
extern void FUN_004aac50(void**);
extern uint32_t* FUN_005428c0();
extern uint32_t* FUN_00542700(uint32_t*, int, int, int, int);
extern void FUN_005606f0(int, void**);
extern void FUN_00542690(void*);
extern void FUN_00547730(void*, const char*, int);
extern void FUN_00534130();
extern void FUN_00534350();
extern void FUN_005be280(const char*, int, void*);
extern uint32_t* FUN_00538680();

// 0x4e5530 — observed shape
void FUN_004e5530(void* self, uint32_t param_1)
{
  int iVar6 = *(int*)((char*)self + 4);
  if (((iVar6 != 0) && (*(int*)(iVar6 + 0xc0) != 0)) && (**(int**)(iVar6 + 0xb8) != 0)) {
    if (*(int*)(iVar6 + 0xc0) == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = **(int**)(iVar6 + 0xb8);
    }
    uint32_t* puVar4 = FUN_005412c0(0);
    uint32_t uVar5 = 0;
    do {
      uint32_t uVar2;
      if (uVar5 % 2 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = param_1;
      }
      uint32_t uVar3;
      if (uVar5 / 2 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = param_1;
      }
      *puVar4 = uVar3;
      puVar4[1] = uVar2;
      uVar5 = uVar5 + 1;
      puVar4 = puVar4 + 2;
    } while ((int)uVar5 < 4);
    iVar6 = *(int*)(iVar6 + 0xbc);
    unsigned char* pbVar1 = (unsigned char*)(iVar6 + 0x33);
    *pbVar1 = *pbVar1 & 0xf;
    pbVar1 = (unsigned char*)(iVar6 + 0x32);
    *pbVar1 = *pbVar1 | 8;
  }
}

// 0x4e55f0 — observed shape
void FUN_004e55f0(char* param_1, float param_2)
{
  char* pcVar6 = param_1;
  bool bVar2 = true;
  FUN_005002f0();
  if ((char*)0xa < param_1) {
    if (*pcVar6 == '\0') {
      param_1 = (char*)(size_t)(*(int*)(pcVar6 + 0x1c) * 0x343fd + 0x269ec3);
      *(char**)(pcVar6 + 0x1c) = param_1;
      float fVar3 = (float)(int)(size_t)param_1;
      if ((int)(size_t)param_1 < 0) {
        fVar3 = fVar3 + 4.2949673e+09f;
      }
      if (fVar3 * 2.3283064e-10f <= 1.0f - _DAT_008cac6c) {
        bVar2 = false;
      }
      else {
        FUN_004e4f70(pcVar6,1);
        *(float*)(pcVar6 + 8) = param_2;
      }
    }
    int iVar7 = *(int*)(pcVar6 + 0x34);
    if ((iVar7 != 0) && (*(int*)(iVar7 + 0x24) != 0)) {
      param_1 = (char*)(size_t)((param_2 - *(float*)(pcVar6 + 8)) * *(float*)(pcVar6 + 0xc));
      float local_2c[11] = {};
      local_2c[0] = *(float*)(pcVar6 + 0x18) * (float)(size_t)param_1 * _DAT_007264b4;
      float fVar3b = (float)(size_t)param_1 * 0.0f * _DAT_007264b4;
      *(float*)(iVar7 + 0x5c) =
           *(float*)(pcVar6 + 0x14) * (float)(size_t)param_1 * _DAT_007264b4 + *(float*)(iVar7 + 0x5c);
      *(float*)(iVar7 + 0x60) = local_2c[0] + *(float*)(iVar7 + 0x60);
      *(float*)(iVar7 + 100) = fVar3b + *(float*)(iVar7 + 100);
      FUN_00533d10((param_2 - *(float*)(pcVar6 + 0x30)) * _DAT_007264b0,1);
      if (_DAT_008cac90 < (param_2 - *(float*)(pcVar6 + 0x30)) * _DAT_007264b0) {
        (**(void(**)(void**, int))(void*)(*DAT_008e9ff4 + 0x74))((void**)&param_1,*(uint32_t*)(pcVar6 + 0x34));
        if ((param_1 != (char*)0x0) &&
           (iVar7 = *(int*)(param_1 + 4), *(int*)(param_1 + 4) = iVar7 + -1, iVar7 + -1 == 0)) {
          (*(void(**)(void*))(void*)**(void***)param_1)(1);
        }
      }
    }
    if (bVar2) {
      if (*(float*)(pcVar6 + 0x10) <= _DAT_008cac88) {
        int iVar7b = *(int*)(pcVar6 + 4);
        float fVar3c = (param_2 - *(float*)(pcVar6 + 8)) * *(float*)(pcVar6 + 0xc);
        *(float*)(pcVar6 + 0x10) = fVar3c + *(float*)(pcVar6 + 0x10);
        float local_2c[11] = {};
        local_2c[0] = *(float*)(pcVar6 + 0x18);
        float fVar4 = *(float*)(pcVar6 + 0x14) * fVar3c + *(float*)(iVar7b + 0x5c);
        *(float*)(iVar7b + 0x5c) = fVar4;
        *(float*)(iVar7b + 0x60) = *(float*)(iVar7b + 0x60) + local_2c[0] * fVar3c;
        *(uint32_t*)(iVar7b + 100) = 0;
        param_1 = (char*)(size_t)(*(float*)(pcVar6 + 0x10) / _DAT_008cac88);
        if (0.0f <= (float)(size_t)param_1) {
          if (1.0f < (float)(size_t)param_1) {
            param_1 = (char*)0x3f800000;
          }
        }
        else {
          param_1 = (char*)0x0;
        }
        float fVar3d = (float)(size_t)param_1;
        long double fVar10 = (long double)FUN_004e0a80(fVar3d);
        param_1 = (char*)(size_t)(float)fVar10;
        FUN_004e5240((void*)(size_t)(*(int*)(pcVar6 + 4)), (uint32_t)(size_t)param_1);
        fVar10 = (long double)FUN_004e0a80(fVar3d);
        FUN_004e5440((int)(size_t)pcVar6,(float)fVar10);
        long double fVar11 = (long double)FUN_004e09b0(fVar3d);
        uint32_t uVar5 = DAT_008cac7c;
        *(float*)(*(int*)(pcVar6 + 4) + 0x68) =
             (float)fabsl((long double)*(float*)(pcVar6 + 0x24) * (long double)*(float*)(pcVar6 + 0x20) * fVar11);
        int iVar7c = *(int*)(pcVar6 + 0x2c);
        *(float*)(pcVar6 + 8) = param_2;
        *(uint32_t*)(pcVar6 + 0x2c) = iVar7c + 1U;
        if (uVar5 <= iVar7c + 1U) {
          FUN_004e54b0(pcVar6, *(int*)(pcVar6 + 0x28) + 1);
        }
        FUN_00533d10(param_2,1);
        if (*(int*)(*(int*)(pcVar6 + 0x34) + 0x24) == 0) {
          long double fVar11b = (long double)FUN_004a9600();
          if ((((long double)1.0f - (long double)_DAT_008cac94 < fVar11b) && (_DAT_008cac98 <= (float)(size_t)param_1)
              ) && ((pcVar6[0x38] == '\0' || (DAT_007264bc == '\0')))) {
            (**(void(**)(uint32_t, int))(void*)(*DAT_008e9ff4 + 0x70))(*(uint32_t*)(pcVar6 + 0x34),1);
            float fVar3e = DAT_007253bc;
            int iVar7d = *(int*)(pcVar6 + 0x34);
            *(float*)(iVar7d + 0x5c) = fVar4;
            *(float*)(iVar7d + 0x60) = (float)fVar10;
            *(float*)(iVar7d + 100) = fVar4;
            FUN_0053c7c0(fVar3e * 1.4629181e-09f);
            float* pfVar8 = local_2c;
            float* pfVar9 = (float*)(*(int*)(pcVar6 + 4) + 0x38);
            for (int iVar7e = 9; iVar7e != 0; iVar7e = iVar7e + -1) {
              *pfVar9 = *pfVar8;
              pfVar8 = pfVar8 + 1;
              pfVar9 = pfVar9 + 1;
            }
            pfVar8 = local_2c;
            pfVar9 = (float*)(*(int*)(pcVar6 + 0x34) + 0x38);
            for (int iVar7f = 9; iVar7f != 0; iVar7f = iVar7f + -1) {
              *pfVar9 = *pfVar8;
              pfVar8 = pfVar8 + 1;
              pfVar9 = pfVar9 + 1;
            }
            *(float*)(*(int*)(pcVar6 + 0x34) + 0x68) = (float)fabsl((long double)_DAT_007264ac);
            FUN_00533d10(0,1);
          }
        }
      }
      else if (*pcVar6 != '\0') {
        FUN_004e59f0(pcVar6);
        *(unsigned char*)(*(int*)(pcVar6 + 4) + 0x20) = *(unsigned char*)(*(int*)(pcVar6 + 4) + 0x20) & 0xfe;
        *pcVar6 = '\0';
        if (*(int*)(pcVar6 + 4) != 0) {
          uint16_t* puVar1 = (uint16_t*)(*(int*)(pcVar6 + 4) + 0x20);
          *puVar1 = *puVar1 | 1;
          *(uint16_t*)(*(int*)(pcVar6 + 0x34) + 0x20) =
               *(uint16_t*)(*(int*)(pcVar6 + 0x34) + 0x20) | 1;
          return;
        }
      }
    }
  }
}

// 0x4e59f0 — observed shape
void FUN_004e59f0(uint32_t* param_1)
{
  int iVar3 = (int)(size_t)param_1;
  if (*(int*)((int)(size_t)param_1 + 4) == 0) {
    int local_40 = 0;
    {
      int tmp = thunk_FUN_00533c78(0x30);
      if (tmp == 0) {
        local_40 = 0;
      }
      else {
        FUN_004127b0w((void*)(size_t)tmp,0xc,4,(void*)0x5cea70);
        local_40 = tmp;
      }
    }
    uint32_t* local_44 = nullptr;
    {
      void* tmp = thunk_FUN_00533c78(0x30);
      if (tmp == (void*)0x0) {
        local_44 = (uint32_t*)0x0;
      }
      else {
        FUN_004127b0w(tmp,0xc,4,(void*)0x5cea70);
        local_44 = (uint32_t*)tmp;
      }
    }
    uint32_t* local_48 = nullptr;
    {
      void* tmp = thunk_FUN_00533c78(0x40);
      if (tmp == (void*)0x0) {
        local_48 = (uint32_t*)0x0;
      }
      else {
        FUN_004127b0w(tmp,0x10,4,(void*)0x4b1250);
        local_48 = (uint32_t*)tmp;
      }
    }
    uint8_t cVar2 = (uint8_t)((DAT_008cac84 == '\0') * 4 + 4);
    uint32_t* local_4c = nullptr;
    {
      void* tmp = thunk_FUN_00533c78(cVar2 * 8);
      if (tmp == (void*)0x0) {
        local_4c = (uint32_t*)0x0;
      }
      else {
        FUN_004127b0w(tmp,8,cVar2,(void*)0x5cea70);
        local_4c = (uint32_t*)tmp;
      }
    }
    int local_30 = 0;
    {
      int tmp = thunk_FUN_00533c78(8);
      local_30 = tmp;
    }
    uint32_t* local_2c = (uint32_t*)thunk_FUN_00533c78(2);
    int iVar4 = FUN_00533c78(100);
    uint32_t* puVar5 = nullptr;
    if (iVar4 == 0) {
      puVar5 = (uint32_t*)0x0;
    }
    else {
      puVar5 = (uint32_t*)FUN_005446d0();
      if (puVar5 != (uint32_t*)0x0) {
        puVar5[1] = puVar5[1] + 1;
      }
    }
    uint32_t* local_50 = (uint32_t*)FUN_00533c78(0x2c);
    if (local_50 == (uint32_t*)0x0) {
      local_50 = (uint32_t*)0x0;
    }
    else {
      FUN_00540c50();
      *local_50 = (uint32_t)(size_t)0x70bf10;
      *(uint16_t*)(local_50 + 8) = 0;
      local_50[9] = 0;
      local_50[10] = 1;
      local_50[1] = local_50[1] + 1;
    }
    uint32_t* local_54 = (uint32_t*)FUN_00533c78(0x24);
    if (local_54 == (uint32_t*)0x0) {
      local_54 = (uint32_t*)0x0;
    }
    else {
      FUN_00540c50();
      *local_54 = (uint32_t)(size_t)0x70bf4c;
      *(uint16_t*)(local_54 + 8) = 0xec;
      *(unsigned char*)((int)(size_t)local_54 + 0x22) = 0;
      local_54[1] = local_54[1] + 1;
    }
    uint32_t* local_58 = (uint32_t*)FUN_00533c78(0x28);
    if (local_58 == (uint32_t*)0x0) {
      local_58 = (uint32_t*)0x0;
    }
    else {
      FUN_00540c50();
      *local_58 = (uint32_t)(size_t)0x70bed4;
      *(uint16_t*)(local_58 + 8) = 3;
      local_58[9] = 3;
      local_58[1] = local_58[1] + 1;
    }
    uint32_t* puVar7 = local_2c;
    iVar4 = puVar5[0x17];
    puVar5[0x16] = 0x3f800000;
    puVar5[0x17] = iVar4 + 1;
    puVar5[9] = DAT_00717780;
    puVar5[10] = DAT_00717784;
    puVar5[0xb] = DAT_00717788;
    puVar5[0x17] = iVar4 + 2;
    puVar5[0xc] = DAT_00717780;
    puVar5[0xd] = DAT_00717784;
    puVar5[0xe] = DAT_00717788;
    puVar5[0x17] = iVar4 + 3;
    uint32_t uVar9 = 0;
    local_50[9] = 0;
    local_50[10] = 1;
    uint32_t local_10 = 0;
    uint32_t local_c = 0;
    uint32_t local_8 = 0;
    uint32_t local_4 = 0x3f800000;
    *(uint16_t*)(local_54 + 8) = *(uint16_t*)(local_54 + 8) & 0xfced | 0x20ed;
    *(uint16_t*)(local_58 + 8) = *(uint16_t*)(local_58 + 8) | 3;
    uint32_t* local_34 = local_4c;
    uint32_t* puVar6 = local_44;
    uint32_t* puVar8 = local_48;
    uint32_t local_1c = 0;
    do {
      uint32_t local_3c = uVar9 & 0x80000001;
      if ((int)local_3c < 0) {
        local_3c = (local_3c - 1 | 0xfffffffe) + 1;
      }
      uint32_t local_14 = (local_3c == 0) ? 0xbf800000u : 0x3f800000u;
      int local_38 = (int)uVar9 / 2;
      uint32_t local_18 = (local_38 == 0) ? 0xbf800000u : 0x3f800000u;
      uint32_t* puVar10 = (uint32_t*)((local_40 - (int)(size_t)local_44) + (int)(size_t)puVar6);
      *puVar10 = local_18;
      puVar10[1] = local_14;
      puVar10[2] = 0;
      *puVar6 = 0;
      puVar6[1] = 0;
      puVar6[2] = 0x3f800000;
      *puVar8 = DAT_0071779c;
      puVar8[1] = DAT_007177a0;
      puVar8[2] = DAT_007177a4;
      puVar8[3] = DAT_007177a8;
      uint32_t local_24 = (local_3c == 0) ? 0u : 0x3f800000u;
      uint32_t local_28 = (local_38 == 0) ? 0u : 0x3f800000u;
      *local_34 = local_28;
      local_34[1] = local_24;
      if (DAT_008cac84 == '\0') {
        if (local_3c == 0) {
          local_1c = (uint32_t*)0x0 != nullptr ? 0u : 0u;
          local_1c = 0;
        }
        else {
          local_1c = 0x3f800000;
        }
        uint32_t local_20 = (local_38 == 0) ? 0u : 0x3f800000u;
        local_34[8] = local_20;
        local_34[9] = local_1c;
      }
      *(int16_t*)(local_30 + uVar9 * 2) = (int16_t)uVar9;
      uVar9 = uVar9 + 1;
      local_34 = local_34 + 2;
      puVar6 = puVar6 + 3;
      puVar8 = puVar8 + 4;
    } while ((int)uVar9 < 4);
    *(uint16_t*)local_2c = 4;
    iVar4 = FUN_00533c78(0xec);
    uint32_t* puVar6b = nullptr;
    if (iVar4 == 0) {
      puVar6b = (uint32_t*)0x0;
    }
    else {
      puVar6b = (uint32_t*)FUN_0053bb30(1);
    }
    uint32_t* puVar8b = *(uint32_t**)((int)(size_t)param_1 + 4);
    if (puVar8b != puVar6b) {
      if (puVar8b != (uint32_t*)0x0) {
        int* piVar1 = (int*)puVar8b + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          (*(void(**)(uint32_t*))(void*)*puVar8b)(1);
        }
      }
      *(uint32_t**)((int)(size_t)param_1 + 4) = puVar6b;
      if (puVar6b != (uint32_t*)0x0) {
        puVar6b[1] = puVar6b[1] + 1;
      }
    }
    iVar4 = FUN_00533c78(0xcc);
    uint32_t* param_1b = nullptr;
    if (iVar4 == 0) {
      param_1b = (uint32_t*)0x0;
    }
    else {
      param_1b = (uint32_t*)FUN_005473e0(4,(void*)(size_t)local_40,local_44,local_48,local_4c,(DAT_008cac84 == '\0') + 1,0,2,1,puVar7,(void*)(size_t)local_30);
      if (param_1b != (uint32_t*)0x0) {
        param_1b[1] = param_1b[1] + 1;
      }
    }
    local_2c = local_50;
    local_50[1] = local_50[1] + 1;
    FUN_004aac50((void**)&local_2c);
    {
      int* piVar1 = (int*)local_50 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(void(**)(uint32_t*))(void*)*local_50)(1);
      }
    }
    local_2c = local_54;
    local_54[1] = local_54[1] + 1;
    FUN_004aac50((void**)&local_2c);
    {
      int* piVar1 = (int*)local_54 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(void(**)(uint32_t*))(void*)*local_54)(1);
      }
    }
    puVar5[1] = puVar5[1] + 1;
    local_2c = puVar5;
    FUN_004aac50((void**)&local_2c);
    {
      int* piVar1 = (int*)puVar5 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(void(**)(uint32_t*))(void*)*puVar5)(1);
      }
    }
    local_2c = local_58;
    local_58[1] = local_58[1] + 1;
    FUN_004aac50((void**)&local_2c);
    {
      int* piVar1 = (int*)local_58 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(void(**)(uint32_t*))(void*)*local_58)(1);
      }
    }
    if (DAT_008cac84 == '\0') {
      iVar4 = FUN_00533c78(0x48);
      uint32_t* puVar7b = nullptr;
      if (iVar4 == 0) {
        puVar7b = (uint32_t*)0x0;
      }
      else {
        puVar7b = FUN_005428c0();
      }
      iVar4 = FUN_00533c78(0x1c);
      uint32_t* puVar6c = nullptr;
      if (iVar4 == 0) {
        puVar6c = (uint32_t*)0x0;
      }
      else {
        puVar6c = FUN_00542700(DAT_008ea068,0,0,1,0);
      }
      FUN_004aad70(DAT_008ea064);
      uint32_t* puVar8c = *(uint32_t**)(puVar7b[0xb] + 8);
      local_2c = puVar6c;
      if (puVar6c != puVar8c) {
        if (puVar8c != (uint32_t*)0x0) {
          (*(void(**)(uint32_t*))(void*)*puVar8c)(1);
        }
        FUN_005606f0(2,(void**)&local_2c);
      }
      FUN_00542690(puVar6c);
      puVar7b[1] = puVar7b[1] + 1;
      local_2c = puVar7b;
      FUN_004aac50((void**)&local_2c);
      {
        int* piVar1 = (int*)puVar7b + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          (*(void(**)(uint32_t*))(void*)*puVar7b)(1);
        }
      }
      FUN_00547730(param_1b,"TWaterSparkle_11",0);
    }
    else {
      iVar4 = FUN_00533c78(0x48);
      uint32_t* puVar7c = nullptr;
      if (iVar4 == 0) {
        puVar7c = (uint32_t*)0x0;
      }
      else {
        puVar7c = FUN_005428c0();
      }
      if (puVar7c != (uint32_t*)0x0) {
        puVar7c[1] = puVar7c[1] + 1;
      }
      local_2c = puVar7c;
      FUN_004aac50((void**)&local_2c);
      if (puVar7c != (uint32_t*)0x0) {
        int* piVar1 = (int*)puVar7c + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          (*(void(**)(uint32_t*))(void*)*puVar7c)(1);
        }
      }
    }
    uint32_t* puVar7d = (uint32_t*)DAT_007179b0;
    uint32_t* puVar6d = param_1b + 0xe;
    for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6d = *puVar7d;
      puVar7d = puVar7d + 1;
      puVar6d = puVar6d + 1;
    }
    (**(void(**)(uint32_t*, int))(void*)(**(uint32_t**)(iVar3 + 4) + 0x70))(param_1b,1);
    uint32_t* puVar7e = *(uint32_t**)(iVar3 + 4);
    uint32_t* puVar10b = (uint32_t*)0x1;
    (**(void(**)())(void*)(*DAT_008e9ff4 + 0x70))();
    FUN_00534130();
    FUN_00534350();
    FUN_005be280("fSparkleAnimSpeed",4,&DAT_008cac8c);
    uint32_t* puVar8d = FUN_00538680();
    uint32_t* puVar6e = *(uint32_t**)(iVar3 + 0x34);
    if (puVar6e != puVar8d) {
      if (puVar6e != (uint32_t*)0x0) {
        int* piVar1 = (int*)puVar6e + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          (*(void(**)(uint32_t*))(void*)*puVar6e)(1);
        }
      }
      *(uint32_t**)(iVar3 + 0x34) = puVar8d;
      if (puVar8d != (uint32_t*)0x0) {
        puVar8d[1] = puVar8d[1] + 1;
      }
    }
    (**(void(**)(uint32_t*, int))(void*)(*DAT_008e9ff4 + 0x70))(*(uint32_t**)(iVar3 + 0x34),1);
    FUN_00534350();
    FUN_00534130();
    (**(void(**)(uint32_t**, uint32_t*))(void*)(*DAT_008e9ff4 + 0x74))((uint32_t**)&local_44,*(uint32_t**)(iVar3 + 0x34));
    if ((local_4c != (uint32_t*)0x0) &&
       (iVar3 = local_4c[1], local_4c[1] = iVar3 + -1, iVar3 + -1 == 0)) {
      (*(void(**)(uint32_t*))(void*)*local_4c)(1);
    }
    {
      int* piVar1 = (int*)puVar7e + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(void(**)(uint32_t*))(void*)*puVar7e)(1);
      }
    }
    {
      int* piVar1 = (int*)puVar10b + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(void(**)(uint32_t*))(void*)*puVar10b)(1);
      }
    }
    {
      int* piVar1 = (int*)param_1b + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(void(**)(uint32_t*))(void*)*param_1b)(1);
      }
    }
    {
      int* piVar1 = (int*)puVar5 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (*(void(**)(uint32_t*))(void*)*puVar5)(1);
      }
    }
  }
}

// 0x4e6150 — observed shape
void FUN_004e6150(void* unaff_EBX, int* param_1)
{
  int iVar2 = FUN_00533db0(3);
  int iVar3 = FUN_00533db0(9);
  if ((iVar3 == 0) || (iVar2 == 0)) {
    if (unaff_EBX == (void*)0x0) {
      return;
    }
    uint32_t* puVar4 = (uint32_t*)(*(void(**)())(void*)(*(int*)unaff_EBX + 4))();
    if (puVar4 == (uint32_t*)0x0) {
      return;
    }
    while (puVar4 != (uint32_t*)DAT_00727598) {
      puVar4 = (uint32_t*)(size_t)puVar4[1];
      if (puVar4 == (uint32_t*)0x0) {
        return;
      }
    }
    if (iVar2 == 0) {
      iVar2 = FUN_00533c78(100);
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (int)(size_t)FUN_005446d0();
      }
      FUN_004aac10((void*)(size_t)iVar2);
    }
    if (iVar3 == 0) {
      iVar3 = FUN_00533c78(0x2c);
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (int)(size_t)FUN_004aae10();
      }
      FUN_004aac10((void*)(size_t)iVar3);
    }
  }
  uint32_t* puVar4b = (uint32_t*)(size_t)*param_1;
  *(uint32_t*)(iVar2 + 0x48) = *puVar4b;
  *(uint32_t*)(iVar2 + 0x4c) = puVar4b[1];
  *(uint32_t*)(iVar2 + 0x50) = puVar4b[2];
  int iVar1 = *(int*)(iVar2 + 0x5c);
  *(int*)(iVar2 + 0x5c) = iVar1 + 1;
  *(uint32_t*)(iVar2 + 0x30) = DAT_00727424;
  *(uint32_t*)(iVar2 + 0x34) = DAT_00727428;
  *(uint32_t*)(iVar2 + 0x38) = DAT_0072742c;
  *(int*)(iVar2 + 0x5c) = iVar1 + 2;
  *(uint32_t*)(iVar2 + 0x24) = DAT_00717780;
  *(uint32_t*)(iVar2 + 0x28) = DAT_00717784;
  *(uint32_t*)(iVar2 + 0x2c) = DAT_00717788;
  *(int*)(iVar2 + 0x5c) = iVar1 + 3;
  *(uint32_t*)(iVar3 + 0x28) = 0;
  *(uint32_t*)(iVar3 + 0x24) = 0;
}

extern void* PTR_FUN_0070f918;
extern void* PTR_LAB_0070f90c;
extern void* PTR_FUN_0070f940;
extern void* PTR_FUN_0070f924;

// 0x4e62b0 — observed shape
long double FUN_004e62b0(float* in_ECX)
{
  long double fVar1 = sqrtl((long double)in_ECX[1] * (long double)in_ECX[1] + (long double)*in_ECX * (long double)*in_ECX);
  if ((long double)1e-06L < fVar1) {
    *in_ECX = (float)(((long double)1.0L / fVar1) * (long double)*in_ECX);
    in_ECX[1] = (float)(((long double)1.0L / fVar1) * (long double)in_ECX[1]);
    return fVar1;
  }
  *in_ECX = 0.0f;
  in_ECX[1] = 0.0f;
  return (long double)0.0f;
}

// 0x4e6300 — observed shape
void FUN_004e6300(void* self, uint8_t param_1)
{
  FUN_004e6320();
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x4e6320 — observed shape
void FUN_004e6320(void* self)
{
  int* in_ECX = (int*)self;
  *in_ECX = (int)(size_t)PTR_FUN_0070f918;
  uint32_t* puVar2 = (uint32_t*)(size_t)in_ECX[1];
  while (puVar2 != (uint32_t*)0x0) {
    uint32_t* puVar1 = (uint32_t*)(size_t)*puVar2;
    (**(void(**)(uint32_t*))(void*)(*in_ECX + 8))(puVar2);
    puVar2 = puVar1;
  }
  in_ECX[3] = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  *in_ECX = (int)(size_t)PTR_LAB_0070f90c;
}

// 0x4e6360 — observed shape
void FUN_004e6360(void* self, uint8_t param_1)
{
  uint32_t* in_ECX = (uint32_t*)self;
  *in_ECX = (uint32_t)(size_t)PTR_FUN_0070f940;
  FUN_004e6420();
  *in_ECX = (uint32_t)(size_t)PTR_FUN_0070f924;
  FUN_004e6420();
  operator_delete__((void*)(size_t)in_ECX[2]);
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x4e63e0 — observed shape
void FUN_004e63e0(void* self, uint8_t param_1)
{
  uint32_t* in_ECX = (uint32_t*)self;
  *in_ECX = (uint32_t)(size_t)PTR_FUN_0070f924;
  FUN_004e6420();
  operator_delete__((void*)(size_t)in_ECX[2]);
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x4e6420 — observed shape
void FUN_004e6420(void* self)
{
  int* unaff_ESI = (int*)self;
  uint32_t uVar3 = 0;
  if (unaff_ESI[1] != 0) {
    do {
      int iVar1 = *(int*)(unaff_ESI[2] + uVar3 * 4);
      while (iVar1 != 0) {
        uint32_t* puVar2 = *(uint32_t**)(unaff_ESI[2] + uVar3 * 4);
        *(uint32_t*)(unaff_ESI[2] + uVar3 * 4) = *puVar2;
        (**(void(**)(uint32_t*))(void*)(*unaff_ESI + 0x10))(puVar2);
        (**(void(**)(uint32_t*))(void*)(*unaff_ESI + 0x18))(puVar2);
        iVar1 = *(int*)(unaff_ESI[2] + uVar3 * 4);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint32_t)unaff_ESI[1]);
  }
  unaff_ESI[3] = 0;
}
