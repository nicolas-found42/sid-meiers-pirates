#include <cstdint>
#include <cstddef>
#include <windows.h>

extern int FUN_00449390(void* a, void* b);
extern int FUN_00533db0(int a);
extern void FUN_005606f0(int a, void* b);
extern void FUN_00542690(int a);
extern void FUN_004c2fc0(int a);
extern void FUN_00502220(void* a);
extern void FUN_005021e0(void* a);
extern void FUN_00542bf0(int a, int b);
extern void FUN_00542cb0(int a, int b);
extern void* thunk_FUN_00533c78(uint32_t a);
extern void FUN_004127b0(void* a, uint32_t b, uint32_t c, void* d);
extern void FUN_005416e0(uint16_t a, void* b, void* c, void* d, void* e, uint8_t f, int g);
extern void operator_delete__(void* p);
extern void operator_delete(void* p);
extern float* FUN_0053ca60(void* a, uint32_t b);
extern void FUN_00412f90();
extern void FUN_004f3350();
extern void FUN_00545780(const char* a, void* b);
extern int DAT_008ed898;
extern int DAT_008ed890;
extern int DAT_008ed88c;
extern int DAT_008ca53c;
extern void* DAT_008ed768;
extern int FUN_0051ffd0();
extern void FUN_005200b0(void* a);
extern void FUN_00520190(void* a);
extern void FUN_005041a0();
extern uint32_t FUN_005045a0(int a, uint32_t b, uint32_t c);
extern void* DAT_008cad24;
extern void* DAT_008ea08c;
extern int DAT_008ed760;
extern int DAT_008ed758;
extern int DAT_008ed754;
extern void* DAT_008ed630;
extern void FUN_005042a0(uint32_t a);
extern void FUN_005071f0();
extern void FUN_00506e60(int a, int b, int c, int d, int e, uint32_t f, int g);
extern void FUN_00522010();

// 0x501f40 — observed shape
void FUN_00501f40(int* param_1, int param_2)
{
  uint32_t uVar1;
  int iVar2;
  int* piVar3;
  int iVar4;
  uint32_t* puVar5;
  int iVar6;
  uint8_t uStack00000000;

  iVar4 = param_2;
  piVar3 = param_1;
  if (param_1 != (int*)0x0) {
    for (puVar5 = (uint32_t*)(**(void**)(*param_1 + 4))(); puVar5 != (uint32_t*)0x0;
        puVar5 = (uint32_t*)puVar5[1]) {
      if (puVar5 == (uint32_t*)0x727560) {
        iVar6 = FUN_00449390((void*)0x727560, piVar3);
        uVar1 = *(uint32_t*)(iVar6 + 0xc0);
        while (uVar1 = uVar1 - 1, -1 < (int)uVar1) {
          if ((uVar1 < *(uint32_t*)(iVar6 + 0xc0)) &&
             (iVar2 = *(int*)(*(int*)(iVar6 + 0xb8) + uVar1 * 4), iVar2 != 0)) {
            FUN_00501f40((int*)iVar2, iVar4);
          }
        }
        break;
      }
    }
  }
  iVar6 = FUN_00533db0(8);
  if (iVar6 != 0) {
    if (iVar4 == 0) {
      param_1 = (int*)0x0;
      if (*(uint32_t**)*(int**)(iVar6 + 0x2c) != (uint32_t*)0x0) {
        (*(void(**)(int))**(uint32_t**)**(int**)(iVar6 + 0x2c))(1);
        FUN_005606f0(0, &uStack00000000);
        return;
      }
    }
    else {
      if (iVar4 == 1) {
        puVar5 = *(uint32_t**)(*(int*)(iVar6 + 0x2c) + 4);
        param_1 = (int*)0x0;
        if (puVar5 != (uint32_t*)0x0) {
          (**(void(**)(int))*puVar5)(1);
          FUN_005606f0(1, &param_1);
        }
        FUN_00542690(0);
        return;
      }
      if (iVar4 == 2) {
        FUN_004c2fc0(0);
        return;
      }
      if (iVar4 == 3) {
        FUN_00502220(0);
        return;
      }
      if (iVar4 == 4) {
        FUN_005021e0(0);
        return;
      }
      if (iVar4 == 5) {
        FUN_00542bf0(0, 0);
        return;
      }
      if (iVar4 == 6) {
        FUN_00542cb0(0, 0);
      }
    }
  }
  return;
}

// 0x502080 — observed shape
void FUN_00502080(int* param_1)
{
  uint16_t uVar1;
  uint32_t* puVar2;
  int iVar3;
  uint32_t uVar4;
  int iVar5;
  uint32_t* puVar6;
  uint32_t* puVar7;

  if (param_1 == (int*)0x0) {
    return;
  }
  puVar2 = (uint32_t*)(**(void**)(*param_1 + 4))();
  while (true) {
    if (puVar2 == (uint32_t*)0x0) goto LAB_005020f1;
    if (puVar2 == (uint32_t*)0x727560) break;
    puVar2 = (uint32_t*)puVar2[1];
  }
  iVar3 = FUN_00449390((void*)0x727560, param_1);
  uVar4 = *(uint32_t*)(iVar3 + 0xc0);
  while (uVar4 = uVar4 - 1, -1 < (int)uVar4) {
    if ((uVar4 < *(uint32_t*)(iVar3 + 0xc0)) &&
       (iVar5 = *(int*)(*(int*)(iVar3 + 0xb8) + uVar4 * 4), iVar5 != 0)) {
      FUN_00502080((int*)iVar5);
    }
  }
LAB_005020f1:
  puVar2 = (uint32_t*)(**(void**)(*param_1 + 4))();
  if (puVar2 == (uint32_t*)0x0) {
    return;
  }
  while (puVar2 != (uint32_t*)0x727598) {
    puVar2 = (uint32_t*)puVar2[1];
    if (puVar2 == (uint32_t*)0x0) {
      return;
    }
  }
  iVar3 = param_1[0x2f];
  if (*(int*)(iVar3 + 0x24) == 0) {
    return;
  }
  if ((*(uint16_t*)(iVar3 + 0x30) & 0xf000) != 0x3000) {
    return;
  }
  uVar1 = *(uint16_t*)(iVar3 + 0xc);
  puVar2 = (uint32_t*)thunk_FUN_00533c78((uint32_t)uVar1 * 0xc);
  if (puVar2 == (uint32_t*)0x0) {
    puVar2 = (uint32_t*)0x0;
  }
  else {
    FUN_004127b0(puVar2, 0xc, (uint32_t)uVar1, (void*)0xcea70);
  }
  puVar6 = *(uint32_t**)(iVar3 + 0x24);
  puVar7 = puVar2;
  for (uVar4 = (uint32_t)*(uint16_t*)(iVar3 + 0xc) * 0xc >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(uint8_t*)puVar7 = *(uint8_t*)puVar6;
    puVar6 = (uint32_t*)((int)puVar6 + 1);
    puVar7 = (uint32_t*)((int)puVar7 + 1);
  }
  FUN_005416e0(*(uint16_t*)(iVar3 + 0xc), *(void**)(iVar3 + 0x20), puVar2,
               *(void**)(iVar3 + 0x28), *(void**)(iVar3 + 0x2c),
               *(uint8_t*)(iVar3 + 0x30) & 0x3f, 0);
  return;
}

// 0x5021b0 — observed shape
void FUN_005021b0(uint8_t param_1, void* self)
{
  uint32_t* in_ECX = (uint32_t*)self;
  *in_ECX = 0x710bf8;
  operator_delete__((void*)in_ECX[1]);
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}

// 0x5021e0 — observed shape
void FUN_005021e0(uint32_t* param_1, void* self)
{
  uint32_t* puVar1;
  uint32_t* puVar2;
  int unaff_ESI = (int)self;

  puVar2 = param_1;
  puVar1 = *(uint32_t**)(*(int*)(unaff_ESI + 0x2c) + 0x10);
  if (param_1 != puVar1) {
    if (puVar1 != (uint32_t*)0x0) {
      (**(void(**)(int))*puVar1)(1);
    }
    FUN_005606f0(4, &param_1);
  }
  FUN_00542690((int)puVar2);
  return;
}

// 0x502220 — observed shape
void FUN_00502220(uint32_t* param_1, void* self)
{
  uint32_t* puVar1;
  uint32_t* puVar2;
  int unaff_ESI = (int)self;

  puVar2 = param_1;
  puVar1 = *(uint32_t**)(*(int*)(unaff_ESI + 0x2c) + 0xc);
  if (param_1 != puVar1) {
    if (puVar1 != (uint32_t*)0x0) {
      (**(void(**)(int))*puVar1)(1);
    }
    FUN_005606f0(3, &param_1);
  }
  FUN_00542690((int)puVar2);
  return;
}

// 0x502260 — observed shape
void FUN_00502260(float* param_1, uint32_t param_2, void* self)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float* pfVar6;
  int in_ECX = (int)self;
  uint8_t local_c[12];

  fVar5 = *(float*)(in_ECX + 0x30);
  pfVar6 = (float*)FUN_0053ca60(local_c, param_2);
  fVar1 = pfVar6[1];
  fVar2 = pfVar6[2];
  fVar3 = *(float*)(in_ECX + 0x2c);
  fVar4 = *(float*)(in_ECX + 0x28);
  *param_1 = fVar5 * *pfVar6 + *(float*)(in_ECX + 0x24);
  param_1[1] = fVar5 * fVar1 + fVar4;
  param_1[2] = fVar5 * fVar2 + fVar3;
  return;
}

// 0x5022c0 — observed shape
void FUN_005022c0(void* param_1, void* self)
{
  size_t _Size;
  int in_EAX = (int)self;
  uint32_t* puVar1;
  int* piVar2;

  _Size = *(size_t*)((int)param_1 + -4);
  piVar2 = (int*)(in_EAX + 4);
  if ((-1 < (int)_Size) && (param_1 != (void*)*piVar2)) {
    if (_Size == 0) {
      FUN_00412f90();
    }
    else {
      FUN_004f3350();
      memmove((void*)*piVar2, param_1, _Size);
      *(uint8_t*)(*piVar2 + *(int*)(*piVar2 + -4)) = 0;
    }
  }
  puVar1 = (uint32_t*)((int)param_1 + -8);
  if ((puVar1 != (uint32_t*)0x0) && (puVar1 != (uint32_t*)0x8cacc8)) {
    operator_delete__(puVar1);
  }
  return;
}

// 0x502460 — observed shape
void FUN_00502460(void* self)
{
  uint32_t* unaff_ESI = (uint32_t*)self;

  *unaff_ESI = 0;
  FUN_00545780("FxText", (void*)0x502c00);
  FUN_00545780("FxWidget", (void*)0x502bd0);
  FUN_00545780("FxDragWidget", (void*)0x502b50);
  FUN_00545780("FxButton", (void*)0x502b10);
  FUN_00545780("FxCheckBox", (void*)0x502ad0);
  FUN_00545780("FxRadioButton", (void*)0x5029990);
  FUN_00545780("FxEditBox", (void*)0x5029970);
  FUN_00545780("FxListBox", (void*)0x5026820);
  FUN_00545780("FxScrollbar", (void*)0x50267a0);
  FUN_00545780("FxDropDownBox", (void*)0x5026720);
  return;
}

// 0x502510 — observed shape
void FUN_00502510(int* param_1)
{
  char cVar1;
  char* pcVar2;
  int iVar3;

  if ((DAT_008ed898 & 1) == 0) {
    DAT_008ed898 = DAT_008ed898 | 1;
    pcVar2 = "FInterface::Render";
    do {
      cVar1 = *pcVar2;
      pcVar2[0x1dc638] = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    DAT_008ed890 = 0xffffffff;
    DAT_008ed88c = 0;
  }
  if (DAT_008ca53c == 0) {
    iVar3 = FUN_00533c78(0x70);
    if (iVar3 == 0) {
      DAT_008ca53c = 0;
    }
    else {
      DAT_008ca53c = FUN_0051ffd0();
    }
  }
  FUN_005200b0(&DAT_008ed768);
  if (*param_1 != 0) {
    FUN_005041a0();
  }
  if (DAT_008ca53c == 0) {
    iVar3 = FUN_00533c78(0x70);
    if (iVar3 == 0) {
      DAT_008ca53c = 0;
    }
    else {
      DAT_008ca53c = FUN_0051ffd0();
    }
  }
  FUN_00520190(&DAT_008ed768);
  return;
}

// 0x5025d0 — observed shape
uint32_t FUN_005025d0(int* param_1, uint32_t in_EAX, uint8_t in_CL)
{
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  POINT local_8;

  if (param_1 == (int*)0x0) {
    return in_EAX & 0xffffff00;
  }
  uVar2 = in_EAX & 0xffff;
  uVar3 = in_EAX >> 0x10;
  if ((0x1000 << (in_CL & 0x1f) & 0xc00000U) != 0) {
    local_8.x = (LONG)(in_EAX & 0xffff);
    local_8.y = (LONG)(in_EAX >> 0x10);
    ScreenToClient((HWND)DAT_008cad24, &local_8);
    uVar2 = (uint32_t)local_8.x;
    uVar3 = (uint32_t)local_8.y;
  }
  (**(void(**)())(*DAT_008ea08c + 0x58))();
  uVar1 = (**(uint32_t(**)())(*DAT_008ea08c + 0x5c))();
  uVar1 = uVar1 & 0xffffff00;
  if (*param_1 != 0) {
    uVar1 = FUN_005045a0(*param_1, uVar2, uVar3);
  }
  return uVar1;
}

// 0x502660 — observed shape
void FUN_00502660(int* param_1, uint32_t param_2)
{
  char cVar1;
  char* pcVar2;
  int iVar3;

  if ((DAT_008ed760 & 1) == 0) {
    DAT_008ed760 = DAT_008ed760 | 1;
    pcVar2 = "FInterface::Update";
    do {
      cVar1 = *pcVar2;
      pcVar2[0x1dc514] = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    DAT_008ed758 = 0xffffffff;
    DAT_008ed754 = 0;
  }
  if (DAT_008ca53c == 0) {
    iVar3 = FUN_00533c78(0x70);
    if (iVar3 == 0) {
      DAT_008ca53c = 0;
    }
    else {
      DAT_008ca53c = FUN_0051ffd0();
    }
  }
  FUN_005200b0(&DAT_008ed630);
  if (*param_1 != 0) {
    FUN_005042a0(param_2);
  }
  if (DAT_008ca53c == 0) {
    iVar3 = FUN_00533c78(0x70);
    if (iVar3 == 0) {
      DAT_008ca53c = 0;
    }
    else {
      DAT_008ca53c = FUN_0051ffd0();
    }
  }
  FUN_00520190(&DAT_008ed630);
  return;
}

// 0x502760 — observed shape
void FUN_00502760(uint8_t param_1, void* self)
{
  uint32_t* in_ECX = (uint32_t*)self;

  *in_ECX = 0x710f80;
  FUN_005071f0();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}

// 0x5027e0 — observed shape
void FUN_005027e0(uint8_t param_1, void* self)
{
  uint32_t* in_ECX = (uint32_t*)self;

  *in_ECX = 0x710dd0;
  FUN_005071f0();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}

// 0x502840 — observed shape
void FUN_00502840(void* self)
{
  uint32_t* unaff_ESI = (uint32_t*)self;

  FUN_00506e60(0xffffffff, 0, 0, 0, 0, 0x3f800000, 0);
  *unaff_ESI = 0x710e98;
  unaff_ESI[0xa4] = 0;
  unaff_ESI[0xa5] = 0;
  unaff_ESI[0xa6] = 0;
  unaff_ESI[0xa7] = 0;
  unaff_ESI[0xa8] = 0;
  unaff_ESI[0xa9] = 0;
  unaff_ESI[0xaa] = 0;
  unaff_ESI[0xab] = 0;
  unaff_ESI[0xac] = 0;
  unaff_ESI[0xad] = 0;
  unaff_ESI[0xae] = 0;
  unaff_ESI[0xaf] = 0;
  unaff_ESI[0xb8] = 0;
  unaff_ESI[0xb9] = 0;
  unaff_ESI[0xba] = 0;
  unaff_ESI[0xb7] = 0;
  unaff_ESI[0xb6] = 0x710f60;
  unaff_ESI[0xbb] = 1;
  return;
}

// 0x5028e0 — observed shape
void FUN_005028e0(uint8_t param_1, void* self)
{
  uint32_t* in_ECX = (uint32_t*)self;

  *in_ECX = 0x710e98;
  FUN_00522010();
  in_ECX[0xb6] = 0x710f60;
  operator_delete__((void*)in_ECX[0xb7]);
  FUN_005071f0();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}

// 0x502940 — observed shape
void FUN_00502940(uint8_t param_1, void* self)
{
  uint32_t* in_ECX = (uint32_t*)self;

  *in_ECX = 0x710f60;
  operator_delete__((void*)in_ECX[1]);
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}

// 0x5029b0 — observed shape
void FUN_005029b0(void* self)
{
  uint32_t* unaff_ESI = (uint32_t*)self;

  FUN_00506e60(0xffffffff, 0, 0, 0, 0, 0x3f800000, 0);
  *unaff_ESI = 0x710d08;
  unaff_ESI[0xaa] = 0;
  unaff_ESI[0xa8] = 0;
  unaff_ESI[0xa9] = 0;
  unaff_ESI[0xa7] = 0x710f70;
  return;
}

// 0x502a00 — observed shape
void FUN_00502a00(uint8_t param_1, void* self)
{
  uint32_t* in_ECX = (uint32_t*)self;

  *in_ECX = 0x710d08;
  FUN_00502a90();
  *in_ECX = 0x7113e8;
  FUN_005071f0();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}

// 0x502a70 — observed shape
void FUN_00502a70(uint8_t param_1, void* self)
{
  void* in_ECX = self;

  FUN_00502a90();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}

// 0x502a90 — observed shape
void FUN_00502a90(void* self)
{
  uint32_t* puVar1;
  uint32_t* puVar2;
  int* in_ECX = (int*)self;

  *in_ECX = 0x710f70;
  puVar2 = (uint32_t*)in_ECX[1];
  while (puVar2 != (uint32_t*)0x0) {
    puVar1 = (uint32_t*)*puVar2;
    (**(void(**)(uint32_t*))(*in_ECX + 8))(puVar2);
    puVar2 = puVar1;
  }
  in_ECX[3] = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  *in_ECX = 0x710f64;
  return;
}
