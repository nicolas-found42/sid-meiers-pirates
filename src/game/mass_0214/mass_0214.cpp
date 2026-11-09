#include <cstdint>
#include <cstddef>
#include <windows.h>

extern char FUN_005d0790();
extern char FUN_005c1db0(int a, int* b, int c, uint32_t d, uint32_t e);
extern int FUN_00533c78(uint32_t n);
extern char FUN_005bd960(uint32_t a, uint32_t* b);
extern void FUN_00545310(uint32_t a, uint32_t* b);
extern void* FUN_00538d10(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e);
extern void* FUN_005c2130(void* a);
extern void operator_delete(void* p);
extern void FUN_005512b0();
extern void* thunk_FUN_00533c78(uint32_t n);
extern void FUN_005c0210();
extern void FUN_005c2160();
extern void FUN_005c4f90(void* self, int a, uint32_t b, uint32_t c);
extern void FUN_005c0b90();
extern uint32_t FUN_005cc240(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
extern void FUN_0054c780(int* a);
extern void* FUN_00539210(uint32_t a, uint32_t b, void* c, uint32_t d);
extern void* FUN_00539cc0(void* a, uint32_t* b);
extern int FUN_00449390(void* a, int b);
extern uint32_t FUN_005bfb00(uint32_t n);
extern void FUN_005d0510(int a, int* b, int c, int d, uint32_t e, uint32_t f);
extern char FUN_004879c0(void* a, int* b);
extern uint32_t FUN_005c4db0(uint32_t a, uint32_t b, int c, uint32_t d, uint32_t e, uint32_t f, uint32_t g, uint32_t h, uint32_t i);
extern char FUN_005c4c90(uint32_t a, int* b, uint16_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g, uint32_t h, uint32_t i, uint32_t j);
extern void FUN_005c4270(uint32_t a, int* b, int c, void* d, void* e, uint32_t f);
extern void FUN_005c4450(uint32_t a, int* b, int c, void* d, void* e);
extern void FUN_005c1cd0(int a);
extern void FUN_005c9890(uint32_t a);
extern void FUN_00535830(void* a);
extern void FUN_005c4760(int a, uint32_t b);
extern char FUN_005d0670(uint32_t a);
extern void FUN_005d00e0();
extern void FUN_005d0d20();
extern void FUN_005ce370();
extern void FUN_005aead0(int a, void* b, void* c);
extern void FUN_005cf730();
extern uint32_t FUN_005c5740(void* self);
extern char FUN_005c64b0(void* self);
extern uint32_t FUN_005f0ddc();
extern void* FUN_00557940();
extern void FUN_0051ac30(uint32_t a);
extern void* FUN_004aae10();
extern void FUN_0050ba40(int a);
extern void* FUN_004aaea0();
extern void* FUN_004aae60();
extern void FUN_005383d0();
extern void operator_delete__(void* p);
extern void FUN_00538400();
extern uint32_t FUN_005d0790_u();

extern uint32_t DAT_00728d74;
extern uint32_t DAT_00727484;
extern uint32_t DAT_0072749c;
extern uint32_t DAT_00727c3c;
extern uint32_t DAT_00727c44;
extern uint32_t DAT_00727854;
extern uint32_t DAT_00728dfc;
extern uint32_t DAT_007179b0;
extern uint32_t DAT_00727430;
extern uint32_t DAT_00727434;
extern uint32_t DAT_00727438;
extern uint32_t DAT_007275f0;
extern void* PTR_FUN_006c7430;
extern void* PTR_FUN_006c71c8;
extern void* PTR_FUN_006c7278;
extern void* PTR_FUN_006c71e4;
extern void* PTR_FUN_006c7294;
extern void* PTR_FUN_006c7200;
extern void* PTR_FUN_006c72b0;
extern void* PTR_FUN_006c721c;
extern void* PTR_FUN_006c72cc;
extern void* PTR_FUN_006c72e8;
extern void* PTR_FUN_006c7690;
extern uint32_t uRam00000024;

// 0x5c4c90 — observed shape
char FUN_005c4c90(void* self, uint32_t param_1, int* param_2, uint16_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7, uint32_t param_8, uint32_t param_9, uint32_t param_10) {
  (void)self;
  int iVar1 = param_2[0xe];
  char cVar3 = FUN_005d0790();
  if (cVar3 != '\0') {
    return '\x01';
  }
  uint32_t uVar5 = (**(uint32_t(**)())(*(uint32_t*)param_2 + 0x38))();
  *(uint32_t*)(iVar1 + 0x10) = uVar5 & 0xffff;
  *(uint32_t*)(iVar1 + 0x44) = param_4;
  *(uint32_t*)(iVar1 + 0x40) = param_5;
  *(uint32_t*)(iVar1 + 0x38) = (uint32_t)param_3;
  *(uint32_t*)(iVar1 + 0x3c) = param_6 & 0xffff;
  cVar3 = FUN_005c1db0(iVar1, param_2, 0, param_9, param_7);
  if (cVar3 != '\0') {
    param_5 = *(uint32_t*)(iVar1 + 0x14);
    uVar5 = 0;
    if (param_5 != 0) {
      uint32_t saved_ecx = (uint32_t)(uintptr_t)self + 0x2b8;
      (void)saved_ecx;
      do {
        int iVar6;
        if (uVar5 < *(uint32_t*)(iVar1 + 0x14)) {
          iVar6 = *(int*)(*(int*)(iVar1 + 0x1c) + uVar5 * 4);
        } else {
          iVar6 = 0;
        }
        uint32_t uVar2 = *(uint32_t*)(iVar6 + 4);
        uint32_t* puVar7 = (uint32_t*)FUN_00533c78(0x30);
        *puVar7 = (uint32_t)(uintptr_t)param_2;
        puVar7[1] = 0; puVar7[2] = 0; puVar7[3] = param_7;
        puVar7[7] = 0; puVar7[8] = 0;
        puVar7[4] = param_8; puVar7[5] = param_9; puVar7[6] = param_10;
        puVar7[9] = (uint32_t)iVar1; puVar7[10] = uVar5;
        char cVar4 = FUN_005bd960(uVar2, &param_4);
        puVar7[0xb] = (uint32_t)(-(int)(cVar4 != '\0')) & param_4;
        FUN_00545310(uVar2, puVar7);
        uVar5 = uVar5 + 1;
      } while (uVar5 < param_5);
    }
  }
  return cVar3;
}

// 0x5c4db0 — observed shape
uint32_t FUN_005c4db0(void* self, uint32_t param_1, uint32_t param_2, int param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7, uint32_t param_8, uint32_t param_9) {
  int* in_ECX = (int*)self;
  uint32_t in_EAX;
  int iVar6;
  uint8_t bStack_15;
  if ((((param_3 == 0) || (in_EAX = *(uint32_t*)(param_3 + 0xc), in_EAX == 0)) ||
       (*(int*)(in_EAX + 0xc) == 0)) ||
      (in_EAX = (**(uint32_t(**)())(*(uint32_t*)in_ECX + 0x38))(), (in_EAX & 0x200) == 0)) {
    return in_EAX & 0xffffff00;
  }
  if (*(int*)(param_3 + 0xc) == 0) {
    iVar6 = 0;
  } else {
    iVar6 = *(int*)(*(int*)(param_3 + 0xc) + 0xc);
  }
  int iStack_c = *(int*)(iVar6 + 0xc);
  bStack_15 = 1;
  if (iStack_c != 0) {
    uint16_t* puStack_10 = (uint16_t*)(*(int*)(iVar6 + 0x10) + 0x1e);
    do {
      iVar6 = *(int*)(puStack_10 + 5);
      char cVar5 = FUN_005d0790();
      if (cVar5 == '\0') {
        uint16_t uVar1 = puStack_10[2];
        uint16_t uVar2 = *puStack_10;
        uint32_t uVar3 = *(uint32_t*)(puStack_10 + -5);
        uint32_t uVar4 = *(uint32_t*)(puStack_10 + -3);
        *(uint32_t*)(iVar6 + 0x10) = (uint32_t)puStack_10[-1];
        uint32_t uVar7 = (uVar1 == 0) ? 1 : (uint32_t)uVar1;
        *(uint32_t*)(iVar6 + 0x44) = uVar3;
        *(uint32_t*)(iVar6 + 0x3c) = uVar7;
        *(uint32_t*)(iVar6 + 0x38) = (uint32_t)uVar2;
        *(uint32_t*)(iVar6 + 0x40) = uVar4;
        cVar5 = FUN_005c1db0(iVar6, (int*)param_2, (int)(uintptr_t)(puStack_10 + -0xf), param_6, param_4);
        if (cVar5 == '\0') {
          bStack_15 = 0;
        } else {
          uint32_t uStack_4 = *(uint32_t*)(iVar6 + 0x14);
          uint32_t uVar7b = 0;
          if (uStack_4 != 0) {
            do {
              int iVar8;
              if (uVar7b < *(uint32_t*)(iVar6 + 0x14)) {
                iVar8 = *(int*)(*(int*)(iVar6 + 0x1c) + uVar7b * 4);
              } else {
                iVar8 = 0;
              }
              uVar3 = *(uint32_t*)(iVar8 + 4);
              uint32_t* puVar9 = (uint32_t*)FUN_00533c78(0x30);
              *puVar9 = param_2;
              puVar9[1] = (uint32_t)param_3;
              puVar9[3] = param_4;
              puVar9[5] = param_6;
              puVar9[2] = (uint32_t)(uintptr_t)(puStack_10 + -0xf);
              puVar9[6] = param_7;
              puVar9[8] = param_9;
              puVar9[4] = param_5;
              puVar9[7] = param_8;
              puVar9[0xb] = 0;
              puVar9[9] = (uint32_t)iVar6;
              puVar9[10] = uVar7b;
              uint32_t uStack_8 = 0;
              cVar5 = FUN_005bd960(uVar3, &uStack_8);
              puVar9[0xb] = (uint32_t)(-(int)(cVar5 != '\0')) & uStack_8;
              FUN_00545310(uVar3, puVar9);
              uVar7b = uVar7b + 1;
            } while (uVar7b < uStack_4);
          }
        }
      }
      puStack_10 = puStack_10 + 0x16;
      iStack_c = iStack_c + -1;
    } while (iStack_c != 0);
  }
  return (uint32_t)bStack_15;
}

// 0x5c4f90 — observed shape
void FUN_005c4f90(void* self, int param_1, uint32_t param_2, uint32_t param_3) {
  int in_ECX = (int)(uintptr_t)self;
  uint32_t uVar1 = *(uint32_t*)(*(int*)(*(int*)(in_ECX + 0x5a8) + 0x14) + 0x28);
  uint32_t local_c = 0;
  (void)param_2;
  do {
    void* pvVar2; void* pvVar4;
    switch (local_c) {
    case 0: {
      int iVar3 = FUN_00533c78(0x24);
      pvVar2 = (iVar3 == 0) ? (void*)0 : FUN_00538d10(0x7c00, 0x3e0, 0x1f, 0, 0x10);
      iVar3 = FUN_00533c78(0x2c);
      if (iVar3 == 0) { pvVar4 = (void*)0; uRam00000024 = 0; }
      else { pvVar4 = FUN_005c2130(pvVar2); *(uint32_t*)((int)(uintptr_t)pvVar4 + 0x24) = 0; }
      break;
    }
    default: {
      int iVar3 = FUN_00533c78(0x24);
      pvVar2 = (iVar3 == 0) ? (void*)0 : FUN_00538d10(0xf800, 0x7e0, 0x1f, 0, 0x10);
      iVar3 = FUN_00533c78(0x2c);
      if (iVar3 == 0) { pvVar4 = (void*)0; uRam00000024 = 1; }
      else { pvVar4 = FUN_005c2130(pvVar2); *(uint32_t*)((int)(uintptr_t)pvVar4 + 0x24) = 1; }
      break;
    }
    }
    if ((pvVar2 != (void*)0) && (pvVar4 != (void*)0)) {
      operator_delete(*(void**)(param_1 + local_c * 4));
      int iVar3 = (**(int(**)(uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t))(*(uint32_t*)DAT_00728d74 + 0x28))(
        DAT_00728d74, *(uint32_t*)(in_ECX + 0x268), *(uint32_t*)(in_ECX + 0x26c), uVar1, 0, param_3,
        *(uint32_t*)((int)(uintptr_t)pvVar4 + 0x28));
      if (iVar3 != 0) { operator_delete(pvVar4); pvVar4 = (void*)0; }
      *(void**)(param_1 + local_c * 4) = pvVar4;
      operator_delete(pvVar2);
    }
    local_c = local_c + 1;
  } while (local_c < 0xe);
}

// 0x5c54e0 — observed shape
int FUN_005c54e0(void* self) {
  int in_ECX = (int)(uintptr_t)self;
  int iVar1;
  if (*(uint32_t*)(in_ECX + 0x268) < *(uint32_t*)(*(int*)(in_ECX + 0x27c) + 0x10)) {
    iVar1 = *(int*)(*(int*)(*(int*)(in_ECX + 0x27c) + 8) + *(uint32_t*)(in_ECX + 0x268) * 4);
  } else {
// 0x5c5720 — observed shape
void FUN_005c5720(void* self, uint8_t param_1) {
  FUN_005c2160();
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}
// 0x5c5740 — observed shape
uint32_t FUN_005c5740(void* self) {
  int in_ECX = (int)(uintptr_t)self;
  FUN_005c4f90((void*)(in_ECX + 0x468), (int)self, 0, 3);
  FUN_005c4f90((void*)(in_ECX + 0x4a0), (int)self, 1, 3);
  FUN_005c4f90((void*)(in_ECX + 0x4d8), (int)self, 0, 5);
  FUN_005c4f90((void*)(in_ECX + 0x510), (int)self, 1, 5);
  FUN_005c0b90();
  uint32_t uVar10 = 0;
  uint32_t* puVar5 = (uint32_t*)(in_ECX + 0x568);
  do {
    int* piVar2 = (int*)puVar5[-0x32];
    if (piVar2 == (int*)0) {
      *puVar5 = 0;
    } else {
      uint32_t uVar3 = FUN_005cc240(*(uint32_t*)(*(int*)(in_ECX + 0x5a8) + 0x20), piVar2[10], 0x20, 8);
      *puVar5 = uVar3;
      if ((*piVar2 == 0) || (*piVar2 == 1)) {
        FUN_0054c780(piVar2);
        *(uint32_t*)(in_ECX + 0x5a0) = uVar10;
      }
    }
    uVar10 = uVar10 + 1;
    puVar5 = puVar5 + 1;
  } while (uVar10 < 0xe);
  int iVar8 = *(int*)(in_ECX + 0x548);
  int iVar4 = FUN_00533c78(0x50);
  void* puVar5b = (iVar4 == 0) ? (void*)0 : FUN_00539210(2, 1, (void*)(uintptr_t)iVar8, 1);
  uint32_t* puVar5u = (uint32_t*)puVar5b;
  if (puVar5u != (uint32_t*)0) { puVar5u[1] = puVar5u[1] + 1; }
  uint8_t* puVar6 = (uint8_t*)(*(int*)puVar5u[0x10] + puVar5u[0xd]);
  char cVar1 = *(char*)(iVar8 + 0x18);
  if (cVar1 == '\x10') {
    puVar6[3] = 0xff; puVar6[2] = 0xff;
  } else if (cVar1 == ' ') {
    puVar6[3] = 0; puVar6[2] = 0; puVar6[7] = 0xff; puVar6[6] = 0xff; puVar6[5] = 0xff; puVar6[4] = 0xff;
  }
  if (cVar1 == '\x10' || cVar1 == ' ') { puVar6[1] = 0; *puVar6 = 0; }
LAB_005c5869:
  uint32_t local_c = 6; uint32_t local_8 = 0; uint32_t local_4 = 0;
  uint32_t* puVar7 = (uint32_t*)FUN_00539cc0(puVar5u, &local_c);
  uint32_t* puVar9 = *(uint32_t**)(in_ECX + 0x604);
  if (puVar9 != puVar7) {
    if (puVar9 != (uint32_t*)0) {
      int* piVar2 = (int*)(puVar9 + 1);
      *piVar2 = *piVar2 + -1;
      if (*piVar2 == 0) { (**(void(**)(uint32_t))(*puVar9))(1); }
    }
    *(uint32_t**)(in_ECX + 0x604) = puVar7;
    if (puVar7 != (uint32_t*)0) { puVar7[1] = puVar7[1] + 1; }
  }
  iVar8 = FUN_00533c78(0x50);
  void* puVar9b = (iVar8 == 0) ? (void*)0 : FUN_00539210(1, 1, (void*)&DAT_00727484, 1);
  uint32_t* puVar9u = (uint32_t*)puVar9b;
  if (puVar5u != puVar9u) {
    int* piVar2 = (int*)(puVar5u + 1);
    *piVar2 = *piVar2 + -1;
    if (*piVar2 == 0) { (**(void(**)(uint32_t))(*puVar5u))(1); }
    puVar5u = puVar9u;
    if (puVar9u != (uint32_t*)0) { puVar9u[1] = puVar9u[1] + 1; }
  }
  puVar6 = (uint8_t*)(*(int*)puVar5u[0x10] + puVar5u[0xd]);
  if (DAT_0072749c == ' ') {
    puVar6[3] = 0xff; puVar6[2] = 0xff; puVar6[1] = 0xff; *puVar6 = 0xff;
  }
  local_8 = 0; local_4 = 0;
  puVar7 = (uint32_t*)FUN_00539cc0(puVar5u, &local_c);
  puVar9 = *(uint32_t**)(in_ECX + 0x608);
  if (puVar9 != puVar7) {
    if (puVar9 != (uint32_t*)0) {
      int* piVar2 = (int*)(puVar9 + 1);
      *piVar2 = *piVar2 + -1;
      if (*piVar2 == 0) { (**(void(**)(uint32_t))(*puVar9))(1); }
    }
    *(uint32_t**)(in_ECX + 0x608) = puVar7;
    if (puVar7 != (uint32_t*)0) { puVar7[1] = puVar7[1] + 1; }
  }
  int* piVar2 = (int*)(puVar5u + 1);
  *piVar2 = *piVar2 + -1;
  if (*piVar2 == 0) { (**(void(**)(uint32_t))(*puVar5u))(1); }
  return 1;
}
// 0x5c5970 — observed shape
uint8_t FUN_005c5970(void* self, int* param_1, uint32_t param_2, int param_3, uint32_t param_4, uint32_t param_5) {
  int* in_ECX = (int*)self;
  (void)param_2;
  if (param_1 != (int*)0) {
    for (uint32_t* puVar5 = (uint32_t*)(**(uint32_t*(** )())(*param_1 + 4))(); puVar5 != (uint32_t*)0; puVar5 = (uint32_t*)puVar5[1]) {
      if (puVar5 == &DAT_00727c3c) {
        int iVar11 = param_1[0x30];
        int* piVar1 = (int*)param_1[0x2f];
        bool bVar2;
        if (((iVar11 == 0) || (*(int*)(iVar11 + 0xc) == 0)) || (*(int*)(*(int*)(iVar11 + 0xc) + 0xc) == 0)) {
          bVar2 = false;
        } else {
          bVar2 = true;
          uint32_t uVar6 = (**(uint32_t(**)())(*(uint32_t*)in_ECX + 0x38))();
          if ((uVar6 & 0x200) == 0) {
            *(uint16_t*)((int)(uintptr_t)piVar1 + 0x32) = *(uint16_t*)((int)(uintptr_t)piVar1 + 0x32) & 0xfff | 0x8000;
          }
        }
        if ((*(uint16_t*)((int)(uintptr_t)piVar1 + 0x32) & 0xf000) == 0x8000) {
          return 1;
        }
        DWORD DVar7 = GetCurrentThreadId();
        if (in_ECX[0xc] != (int)DVar7) {
          EnterCriticalSection((LPCRITICAL_SECTION)((int*)in_ECX + 6));
          DVar7 = GetCurrentThreadId();
          in_ECX[0xc] = (int)DVar7;
        }
        in_ECX[0xd] = in_ECX[0xd] + 1;
        int iVar12 = 0; uint32_t uStack_10 = 0;
        int* piVar8 = (int*)FUN_00449390((void*)&DAT_00728dfc, param_1[0x32]);
        if (((piVar8 != (int*)0) && (iVar12 = (**(int(**)())(*piVar8 + 0x38))(), iVar12 != 0)) && ((param_3 != 0 && (int iVar9 = FUN_005bfb00(8), iVar9 != 0)))) {
          uStack_10 = *(uint32_t*)(iVar9 + 4);
        }
        FUN_005d0510(in_ECX[0x171], piVar1, iVar11, 0, param_4, param_5);
        uint8_t uVar3 = 0;
        if (bVar2) {
          uVar3 = (uint8_t)FUN_005c4db0((uint32_t)(uintptr_t)param_1, (uint32_t)(uintptr_t)piVar1, iVar11, 0, (uint32_t)param_3, (uint32_t)iVar12, uStack_10, param_4, param_5);
        } else {
          char cVar4 = FUN_004879c0((void*)&DAT_00727c44, param_1);
          uint32_t uVar10; int iVar9b; int iVar11b; uint16_t uVar13;
          if (cVar4 == '\0') {
            cVar4 = FUN_004879c0((void*)&DAT_00727854, param_1);
            if (cVar4 == '\0') goto LAB_005c5b4d;
            uVar10 = (**(uint32_t(**)())(*piVar1 + 0x44))();
            iVar9b = piVar1[0x11]; iVar11b = piVar1[0x12]; uVar13 = (uint16_t)piVar1[0x10];
          } else {
            uVar10 = (**(uint32_t(**)())(*piVar1 + 0x44))();
            iVar11b = piVar1[0x11]; uVar13 = 1; iVar9b = 0;
          }
          uVar3 = (uint8_t)FUN_005c4c90((uint32_t)(uintptr_t)param_1, piVar1, (uint16_t)uVar10, (uint32_t)iVar11b, (uint32_t)iVar9b, uVar13, 0, (uint32_t)param_3, (uint32_t)iVar12, uStack_10);
        }
LAB_005c5b4d:
        DVar7 = GetCurrentThreadId();
        if (in_ECX[0xc] == (int)DVar7) {
          int* piVar1b = in_ECX + 0xd;
          *piVar1b = *piVar1b + -1;
          if (*piVar1b == 0) { in_ECX[0xc] = 0; LeaveCriticalSection((LPCRITICAL_SECTION)((int*)in_ECX + 6)); }
        }
        (void)piVar1;
        return uVar3;
      }
    }
  }
  return 0;
}
// 0x5c5b80 — observed shape
void FUN_005c5b80(void* self, int param_1) {
  int* in_ECX = (int*)self;
  int* piVar1 = *(int**)(param_1 + 0xbc);
  int iVar2 = *(int*)(param_1 + 0xc0);
  uint32_t* puVar6 = (uint32_t*)(param_1 + 0x6c);
  uint32_t local_34[10];
  uint32_t* puVar7 = local_34;
  for (int iVar5 = 0xd; iVar5 != 0; iVar5 = iVar5 + -1) { *puVar7 = *puVar6; puVar6 = puVar6 + 1; puVar7 = puVar7 + 1; }
  uint32_t local_44 = *(uint32_t*)(param_1 + 0x28);
  uint32_t local_40 = *(uint32_t*)(param_1 + 0x2c);
  uint32_t local_3c = *(uint32_t*)(param_1 + 0x30);
  uint32_t local_38 = *(uint32_t*)(param_1 + 0x34);
  (void)local_40; (void)local_3c; (void)local_38;
  if ((char)in_ECX[0x113] == '\0') { return; }
  int16_t sVar3 = (int16_t)(**(int(**)())(*piVar1 + 0x38))();
  if (sVar3 == 0) { return; }
  uint32_t uVar4 = 0;
  int iVar5;
  if (((*(uint16_t*)((int)(uintptr_t)piVar1 + 0x32) & 0xf000) == 0x8000) || ((iVar2 != 0 && (uVar4 = (**(uint32_t(**)())(*(uint32_t*)in_ECX + 0x38))(), (uVar4 & 0x200) == 0)))) {
    iVar5 = in_ECX[0x172];
  } else {
    iVar5 = in_ECX[0x171];
  }
  (**(void(**)(int,int*,int,int))(*(int*)(uint32_t)(uintptr_t)in_ECX[0x170] + 0x18))(iVar5, piVar1, iVar2, 0);
  if ((((iVar2 == 0) || (*(int*)(iVar2 + 0xc) == 0)) || (*(int*)(*(int*)(iVar2 + 0xc) + 0xc) == 0)) || (uVar4 = (**(uint32_t(**)())(*(uint32_t*)in_ECX + 0x38))(), (uVar4 & 0x200) == 0)) {
    uint32_t uStack_c = local_44;
    uint8_t auStack_46[2] = {0,0};
    FUN_005c4270(uStack_c, piVar1, iVar2, &local_44, auStack_46 + -0xe, piVar1[0xe]);
    return;
  }
  uint32_t uStack_c2 = local_44;
  uint8_t auStack_46b[2] = {0,0};
  FUN_005c4450(uStack_c2, piVar1, iVar2, &local_44, auStack_46b + -0xe);
}
// 0x5c5ca0 — observed shape
void FUN_005c5ca0(void* self, int param_1) {
  int in_ECX = (int)(uintptr_t)self;
  int iVar1;
  if ((*(char*)(in_ECX + 0x44c) != '\0') && (*(int16_t*)(param_1 + 0x10) != 0)) {
    *(uint32_t*)(in_ECX + 0x30c) = *(uint32_t*)(in_ECX + 0x31c);
    *(uint32_t*)(in_ECX + 0x310) = *(uint32_t*)(in_ECX + 800);
    *(uint32_t*)(in_ECX + 0x314) = *(uint32_t*)(in_ECX + 0x324);
    *(uint32_t*)(in_ECX + 0x318) = *(uint32_t*)(in_ECX + 0x328);
    uint32_t uStack_60 = *(uint32_t*)(in_ECX + 0x5c4);
    uint32_t uStack_58 = 0;
    int iStack_5c = param_1;
    int iStack_64 = 0x5c5cfd;
    uint32_t uStack_68 = 0;
    (void)uStack_60; (void)uStack_58; (void)iStack_5c; (void)iStack_64; (void)uStack_68; (void)iVar1;
    (**(void(**)())(**(int**)(in_ECX + 0x5c0) + 0x14))();
    iStack_64 = *(uint32_t*)(in_ECX + 0x330);
    uStack_68 = *(uint32_t*)(in_ECX + 0x32c);
    FUN_005c1cd0(param_1);
    iStack_64 = in_ECX + 0x334;
    uStack_68 = 2;
    (**(void(**)(int*))(**(int**)(in_ECX + 0x60) + 0xb0))(*(int**)(in_ECX + 0x60));
    (**(void(**)(int*,int,int*))(**(int**)(in_ECX + 0x60) + 0xb0))(*(int**)(in_ECX + 0x60), 3, (int*)(in_ECX + 0x3b4));
    uint32_t* puVar2 = &DAT_007179b0;
    uint32_t* puVar3 = &uStack_58;
    for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) { *puVar3 = *puVar2; puVar2 = puVar2 + 1; puVar3 = puVar3 + 1; }
    FUN_005c4270(0, 0, 0, &uStack_58, &uStack_68, *(uint32_t*)(param_1 + 0x24));
    (**(void(**)(int*,int,int*))(**(int**)(in_ECX + 0x60) + 0xb0))(*(int**)(in_ECX + 0x60), 2, (int*)(in_ECX + 0x7c0));
    (**(void(**)(int*,int,int*))(**(int**)(in_ECX + 0x60) + 0xb0))(*(int**)(in_ECX + 0x60), 3, (int*)(in_ECX + 0x800));
  }
}
    iVar1 = 0;
  }
  if (*(int*)(in_ECX + 0x26c) == 1) {
    iVar1 = *(int*)(iVar1 + 0x468);
  } else {
    iVar1 = *(int*)(iVar1 + 0x46c);
  }
  if ((*(int*)(iVar1 + 4) == 0) || (iVar1 == 0)) {
    return 0;
  }
  return iVar1 + 4;
}

// 0x5c5530 — observed shape
void FUN_005c5530(void* self) {
  uint32_t* in_ECX = (uint32_t*)self;
  uint32_t uVar2; int iVar3;
  FUN_005512b0();
  *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c7430;
  in_ECX[0xae] = (uint32_t)(uintptr_t)&PTR_FUN_006c71c8;
  in_ECX[0xaf] = 0x25; in_ECX[0xb1] = 0;
  uint32_t* puVar1 = (uint32_t*)thunk_FUN_00533c78(0x94);
  in_ECX[0xb0] = (uint32_t)(uintptr_t)puVar1;
  for (uVar2 = in_ECX[0xaf] & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) { *puVar1 = 0; puVar1 = puVar1 + 1; }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) { *(uint8_t*)puVar1 = 0; puVar1 = (uint32_t*)((int)(uintptr_t)puVar1 + 1); }
  in_ECX[0xae] = (uint32_t)(uintptr_t)&PTR_FUN_006c7278;
  in_ECX[0xb6] = 0; in_ECX[0x156] = 0; in_ECX[0x157] = 0; in_ECX[0x158] = 0; in_ECX[0x159] = 0;
  in_ECX[0x16b] = (uint32_t)(uintptr_t)&PTR_FUN_006c71e4;
  in_ECX[0x16c] = 0x25; in_ECX[0x16e] = 0;
  puVar1 = (uint32_t*)thunk_FUN_00533c78(0x94);
  in_ECX[0x16d] = (uint32_t)(uintptr_t)puVar1;
  for (uVar2 = in_ECX[0x16c] & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) { *puVar1 = 0; puVar1 = puVar1 + 1; }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) { *(uint8_t*)puVar1 = 0; puVar1 = (uint32_t*)((int)(uintptr_t)puVar1 + 1); }
  in_ECX[0x16b] = (uint32_t)(uintptr_t)&PTR_FUN_006c7294;
  in_ECX[0x16f] = 0;
  in_ECX[0x179] = (uint32_t)(uintptr_t)&PTR_FUN_006c7200;
  in_ECX[0x17a] = 0x25; in_ECX[0x17c] = 0;
  puVar1 = (uint32_t*)thunk_FUN_00533c78(0x94);
  in_ECX[0x17b] = (uint32_t)(uintptr_t)puVar1;
  for (uVar2 = in_ECX[0x17a] & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) { *puVar1 = 0; puVar1 = puVar1 + 1; }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) { *(uint8_t*)puVar1 = 0; puVar1 = (uint32_t*)((int)(uintptr_t)puVar1 + 1); }
  in_ECX[0x179] = (uint32_t)(uintptr_t)&PTR_FUN_006c72b0;
  in_ECX[0x17d] = (uint32_t)(uintptr_t)&PTR_FUN_006c721c;
  in_ECX[0x17e] = 0x25; in_ECX[0x180] = 0;
  puVar1 = (uint32_t*)thunk_FUN_00533c78(0x94);
  in_ECX[0x17f] = (uint32_t)(uintptr_t)puVar1;
  for (uVar2 = in_ECX[0x17e] & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) { *puVar1 = 0; puVar1 = puVar1 + 1; }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) { *(uint8_t*)puVar1 = 0; puVar1 = (uint32_t*)((int)(uintptr_t)puVar1 + 1); }
  in_ECX[0x17d] = (uint32_t)(uintptr_t)&PTR_FUN_006c72cc;
  in_ECX[0x181] = 0; in_ECX[0x182] = 0; in_ECX[0x186] = 0; in_ECX[0x184] = 0; in_ECX[0x185] = 0;
  in_ECX[0x183] = (uint32_t)(uintptr_t)&PTR_FUN_006c72e8;
  in_ECX[0x187] = 0; in_ECX[0x188] = 0; in_ECX[0x189] = 0; in_ECX[0x18a] = 0; in_ECX[0x18b] = 0;
  in_ECX[0x18c] = 0; in_ECX[0x18d] = 0; in_ECX[0x18e] = 0;
  in_ECX[399] = 0; in_ECX[400] = 0; in_ECX[0x226] = 0;
  FUN_005c0210();
}

// 0x5c5de0 — observed shape
void FUN_005c5de0(uint8_t param_1) {
  FUN_005c9890(0);
  FUN_00535830(&param_1);
}

// 0x5c5e10 — observed shape
void FUN_005c5e10(int* param_1) {
  (**(void(**)())(*(uint32_t*)param_1 + 0x48))();
  FUN_005c9890(0);
  FUN_00535830(&param_1);
}

// 0x5c5e40 — observed shape
void FUN_005c5e40(int param_1) {
  int16_t sVar1;
  uint32_t* puVar2;
  char cVar3;
  uint32_t uVar4;
  uint32_t uVar5;

  if (param_1 == 0) {
    return;
  }
  puVar2 = *(uint32_t**)(param_1 + 0x20);
  cVar3 = FUN_005d0790();
  uVar4 = (*puVar2 & 0x7fffff) | 0x1000000;
  FUN_005d0670(1);
  *puVar2 = uVar4;
  sVar1 = *(int16_t*)(param_1 + 0x1c);
  uVar5 = (uVar4 & 0xffff0000) | (uint16_t)sVar1;
  if (cVar3 == '\0') {
    (**(void(**)(uint32_t*, int))(*(uint32_t*)puVar2[1] + 0x24))(puVar2, 0);
    puVar2[0xb] = 0;
    uVar5 = 0xf;
    FUN_005c4760(param_1, uVar5);
  } else {
    cVar3 = (**(char(**)())(*(uint32_t*)puVar2[1] + 0x28))();
    if (cVar3 != '\0') {
      uVar5 = 0xf;
      FUN_005c4760(param_1, uVar5);
    } else if (sVar1 != 0) {
      FUN_005c4760(param_1, uVar5);
    }
  }
  *(uint16_t*)(param_1 + 0x1c) = 0;
}

// 0x5c64b0 — observed shape
char FUN_005c64b0(void* self) {
  int* in_ECX = (int*)self;
  char cVar1;
  uint32_t uVar2;
  int* piVar3;
  int* piVar4;
  int iVar5;
  int* piVar6;
  int iVar7;
  uint32_t* puVar8;
  uint32_t* puVar9;
  int* unaff_EBX = (int*)self;
  uint32_t local_c;
  uint8_t stack_10[0x20];

  local_c = (uint32_t)(uintptr_t)in_ECX;
  FUN_005d00e0();
  FUN_005d0d20();
  FUN_005ce370();
  uVar2 = 0;
  if (in_ECX[0x16c] != 0) {
    piVar3 = (int*)(uintptr_t)in_ECX[0x16d];
    do {
      if (*piVar3 != 0) {
        piVar3 = (int*)((int*)(uintptr_t)in_ECX[0x16d])[uVar2];
        goto joined_r0x005c6505;
      }
      uVar2 = uVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (uVar2 < (uint32_t)in_ECX[0x16c]);
  }
  piVar3 = (int*)0;
joined_r0x005c6505:
  while (piVar3 != (int*)0) {
    piVar4 = (int*)*piVar3;
    piVar6 = (int*)piVar3[2];
    if (piVar4 == (int*)0) {
      iVar7 = (**(int(**)(int))(in_ECX[0x16b] + 4))(piVar3[1]);
      uVar2 = iVar7 + 1;
      if (uVar2 < (uint32_t)in_ECX[0x16c]) {
        puVar8 = (uint32_t*)(uintptr_t)(in_ECX[0x16d] + uVar2 * 4);
        do {
          piVar4 = (int*)*puVar8;
          if (piVar4 != (int*)0) goto LAB_005c6550;
          uVar2 = uVar2 + 1;
          puVar8 = puVar8 + 1;
        } while (uVar2 < (uint32_t)in_ECX[0x16c]);
      }
      piVar4 = (int*)0;
    }
LAB_005c6550:
    (**(void(**)())(*piVar6 + 0xc))();
    piVar3 = piVar4;
  }
  uVar2 = 0;
  piVar3 = (int*)(uintptr_t)local_c;
  if (in_ECX[0x17a] != 0) {
    piVar4 = (int*)(uintptr_t)in_ECX[0x17b];
    do {
      if (*piVar4 != 0) {
        piVar4 = (int*)((int*)(uintptr_t)in_ECX[0x17b])[uVar2];
        goto joined_r0x005c6587;
      }
      uVar2 = uVar2 + 1;
      piVar4 = piVar4 + 1;
    } while (uVar2 < (uint32_t)in_ECX[0x17a]);
  }
  piVar4 = (int*)0;
joined_r0x005c6587:
  while (piVar4 != (int*)0) {
    iVar7 = piVar4[1];
    puVar8 = (uint32_t*)(uintptr_t)piVar4[2];
    piVar4 = (int*)*piVar4;
    local_c = (uint32_t)(uintptr_t)piVar3;
    if (piVar4 == (int*)0) {
      iVar5 = (**(int(**)(int))(in_ECX[0x179] + 4))(iVar7);
      uVar2 = iVar5 + 1;
      if (uVar2 < (uint32_t)in_ECX[0x17a]) {
        puVar9 = (uint32_t*)(uintptr_t)(in_ECX[0x17b] + uVar2 * 4);
        do {
          piVar4 = (int*)*puVar9;
          if (piVar4 != (int*)0) goto LAB_005c65d0;
          uVar2 = uVar2 + 1;
          puVar9 = puVar9 + 1;
        } while (uVar2 < (uint32_t)in_ECX[0x17a]);
      }
      piVar4 = (int*)0;
    }
LAB_005c65d0:
    *(uint32_t*)(iVar7 + 0x2c) = 0;
    if (puVar8 != (uint32_t*)0) {
      (**(void(**)(int))((uint32_t)*puVar8))(1);
    }
    FUN_00545310(iVar7, 0);
    piVar3 = (int*)(uintptr_t)local_c;
  }
  uVar2 = 0;
  piVar4 = piVar3;
  if (piVar3[0x17e] != 0) {
    piVar6 = (int*)(uintptr_t)piVar3[0x17f];
    do {
      if (*piVar6 != 0) {
        piVar6 = (int*)((int*)(uintptr_t)piVar3[0x17f])[uVar2];
        goto joined_r0x005c6627;
      }
      uVar2 = uVar2 + 1;
      piVar6 = piVar6 + 1;
    } while (uVar2 < (uint32_t)piVar3[0x17e]);
  }
  piVar6 = (int*)0;
joined_r0x005c6627:
  while (piVar6 != (int*)0) {
    iVar7 = piVar6[1];
    puVar8 = (uint32_t*)(uintptr_t)piVar6[2];
    piVar6 = (int*)*piVar6;
    local_c = (uint32_t)(uintptr_t)piVar4;
    if (piVar6 == (int*)0) {
      iVar5 = (**(int(**)(int))(piVar3[0x17d] + 4))(iVar7);
      uVar2 = iVar5 + 1;
      if (uVar2 < (uint32_t)piVar3[0x17e]) {
        puVar9 = (uint32_t*)(uintptr_t)(piVar3[0x17f] + uVar2 * 4);
        do {
          piVar6 = (int*)*puVar9;
          if (piVar6 != (int*)0) goto LAB_005c6663;
          uVar2 = uVar2 + 1;
          puVar9 = puVar9 + 1;
        } while (uVar2 < (uint32_t)piVar3[0x17e]);
      }
      piVar6 = (int*)0;
    }
LAB_005c6663:
    *(uint32_t*)(iVar7 + 0x2c) = 0;
    if (puVar8 != (uint32_t*)0) {
      (**(void(**)(int))((uint32_t)*puVar8))(1);
    }
    FUN_00545310(iVar7, 0);
    piVar4 = (int*)(uintptr_t)local_c;
  }
  puVar8 = (uint32_t*)(uintptr_t)piVar4[0x184];
  while (puVar8 != (uint32_t*)0) {
    puVar9 = puVar8 + 2;
    puVar8 = (uint32_t*)(uintptr_t)*puVar8;
    (**(void(**)())(*(uint32_t*)(uintptr_t)*puVar9 + 0x40))();
  }
  (**(void(**)())(*(uint32_t*)(uintptr_t)piVar4[0x172]))();
  iVar7 = (**(int(**)(int*, int))(*(uint32_t*)(uintptr_t)piVar4[0x18] + 0x40))(
      (int*)(uintptr_t)piVar4[0x18], piVar4[0x16a] + 0x18);
  if (iVar7 >= 0) {
    piVar4[0x119] = piVar4[0x119] + 1;
    uVar2 = 0;
    if (piVar4[0x16c] != 0) {
      piVar6 = (int*)(uintptr_t)piVar4[0x16d];
      do {
        if (*piVar6 != 0) {
          iVar7 = ((int*)(uintptr_t)piVar4[0x16d])[uVar2];
          goto joined_r0x005c66f5;
        }
        uVar2 = uVar2 + 1;
        piVar6 = piVar6 + 1;
      } while (uVar2 < (uint32_t)piVar4[0x16c]);
    }
    iVar7 = 0;
joined_r0x005c66f5:
    // NEEDS_MANUAL: provider loop body never advances iVar7; list traversal details unavailable.
    while (iVar7 != 0) {
      FUN_005aead0((int)((uintptr_t)stack_10 - 0x14), (void*)((uintptr_t)stack_10 - 0x10), &local_c);
      (**(void(**)(uint32_t))((uint32_t)*unaff_EBX + 0x10))(piVar4[0x18]);
    }
    piVar4[0x169] = piVar4[0x16a];
    cVar1 = (char)FUN_005c5740(self);
    if (cVar1 != '\0') {
      uVar2 = 0;
      if (piVar4[0x17a] != 0) {
        piVar6 = (int*)(uintptr_t)piVar4[0x17b];
        do {
          if (*piVar6 != 0) {
            iVar7 = ((int*)(uintptr_t)piVar4[0x17b])[uVar2];
            goto joined_r0x005c6789;
          }
          uVar2 = uVar2 + 1;
          piVar6 = piVar6 + 1;
        } while (uVar2 < (uint32_t)piVar4[0x17a]);
      }
      iVar7 = 0;
joined_r0x005c6789:
      while (iVar7 != 0) {
        FUN_005aead0((int)((uintptr_t)stack_10 - 0x14), (void*)((uintptr_t)stack_10 - 0x10), &local_c);
        (**(void(**)(int*))((uint32_t)*piVar4 + 0x104))(unaff_EBX);
      }
      uVar2 = 0;
      if (piVar3[0x17e] != 0) {
        piVar6 = (int*)(uintptr_t)piVar3[0x17f];
        do {
          if (*piVar6 != 0) {
            iVar7 = ((int*)(uintptr_t)piVar3[0x17f])[uVar2];
            goto joined_r0x005c67e9;
          }
          uVar2 = uVar2 + 1;
          piVar6 = piVar6 + 1;
        } while (uVar2 < (uint32_t)piVar3[0x17e]);
      }
      iVar7 = 0;
joined_r0x005c67e9:
      while (iVar7 != 0) {
        FUN_005aead0((int)((uintptr_t)stack_10 - 0x14), (void*)((uintptr_t)stack_10 - 0x10), &local_c);
        (**(void(**)(int*))((uint32_t)*piVar4 + 0x108))(unaff_EBX);
      }
      puVar8 = (uint32_t*)(uintptr_t)piVar4[0x184];
      while (puVar8 != (uint32_t*)0) {
        puVar9 = puVar8 + 2;
        puVar8 = (uint32_t*)(uintptr_t)*puVar8;
        (**(void(**)())(*(uint32_t*)(uintptr_t)*puVar9 + 0x44))();
      }
      (**(void(**)(void))(*(uint32_t*)(uintptr_t)piVar4[0x173] + 0x10c))();
      FUN_005cf730();
      return 1;
    }
  }
  return 0;
}

// 0x5c6870 — observed shape
uint32_t FUN_005c6870(void* self, uint32_t param_1, uint32_t param_2) {
  int in_ECX = (int)(uintptr_t)self;
  char cVar1;
  int iVar2;
  int iVar3;
  uint32_t* puVar4;
  uint32_t* puVar5;
  uint32_t* puVar6;
  uint32_t local_38[14];

  iVar3 = *(int*)(in_ECX + 0x5a8);
  puVar4 = (uint32_t*)(uintptr_t)(iVar3 + 0x18);
  puVar5 = puVar4;
  puVar6 = local_38;
  for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  *(uint32_t*)(iVar3 + 0x1c) = param_2;
  *puVar4 = param_1;
  cVar1 = (char)FUN_005c64b0(self);
  if (cVar1 != '\0') {
    return 2;
  }
  puVar5 = local_38;
  for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar4 = puVar4 + 1;
  }
  cVar1 = (char)FUN_005c64b0(self);
  return cVar1 != '\0';
}

// 0x5c68e0 — observed shape
void FUN_005c68e0(void* self, int param_1) {
  int in_ECX = (int)(uintptr_t)self;
  int iVar1;
  uint32_t uVar2;
  uint8_t auStack_4a[10];
  uint32_t auStack_40[9];
  uint32_t uStack_1c;
  uint32_t uStack_18;
  uint32_t uStack_14;
  uint32_t uStack_10;
  // NEEDS_MANUAL: iStack_8, unaff_EDI and unaff_ESI are provider-modelled register/stack slots
  // with no materialized producer in the listing.
  int iStack_8;
  uint32_t unaff_EDI;
  uint32_t unaff_ESI;

  if (((*(char*)(in_ECX + 0x44c) != '\0') && (param_1 != 0)) && (*(int*)(param_1 + 0x14) != 0)) {
    if (*(int*)(in_ECX + 0x5bc) == 0) {
      iVar1 = FUN_00533c78(0x38);
      if (iVar1 == 0) {
        uVar2 = 0;
      } else {
        uVar2 = (uint32_t)(uintptr_t)FUN_00557940();
      }
      FUN_0051ac30(uVar2);
      iVar1 = FUN_00533c78(0x2c);
      if (iVar1 == 0) {
        iVar1 = 0;
      } else {
        iVar1 = (int)(uintptr_t)FUN_004aae10();
      }
      *(uint32_t*)(iVar1 + 0x24) = 1;
      *(uint32_t*)(iVar1 + 0x28) = 0;
      FUN_0050ba40(iVar1);
      iVar1 = FUN_00533c78(0x24);
      if (iVar1 == 0) {
        iVar1 = 0;
      } else {
        iVar1 = (int)(uintptr_t)FUN_004aaea0();
      }
      *(uint16_t*)(iVar1 + 0x20) = (*(uint16_t*)(iVar1 + 0x20) & 0xfeed) | 0xed;
      FUN_0050ba40(iVar1);
      iVar1 = FUN_00533c78(0x28);
      if (iVar1 == 0) {
        iVar1 = 0;
      } else {
        iVar1 = (int)(uintptr_t)FUN_004aae60();
      }
      *(uint8_t*)(iVar1 + 0x20) = *(uint8_t*)(iVar1 + 0x20) & 0xfc;
      FUN_0050ba40(iVar1);
    }
    FUN_0050ba40((int)*(uint32_t*)(param_1 + 0x18));
    *(uint32_t*)(in_ECX + 0x10) = *(uint32_t*)(in_ECX + 0x5bc);
    *(uint32_t*)(in_ECX + 0x14) = 0;
    (**(void(**)(uint32_t, int, int))(*(uint32_t*)(uintptr_t)(*(uint32_t*)(in_ECX + 0x5c0)) + 0x10))(
        *(uint32_t*)(in_ECX + 0x5c4), param_1, 0);
    FUN_005c5e40(param_1);
    uint32_t* puVar3 = &DAT_007179b0;
    uint32_t* puVar4 = auStack_40;
    for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    uStack_1c = DAT_00727430;
    uStack_18 = DAT_00727434;
    uStack_14 = DAT_00727438;
    uStack_10 = 0x3f800000;
    FUN_005c4270(0, 0, 0, auStack_40, (void*)((uintptr_t)auStack_4a - 6),
                 *(uint32_t*)(iStack_8 + 0x20));
    FUN_0050ba40((int)DAT_007275f0);
    *(uint32_t*)(in_ECX + 0x10) = unaff_EDI;
    *(uint32_t*)(in_ECX + 0x14) = unaff_ESI;
  }
}

// 0x5c6a80 — observed shape
// NEEDS_MANUAL: unaff_retaddr is a caller-supplied stack argument that the provider modelled as
// the return address; it is exposed here as an explicit third parameter.
void FUN_005c6a80(void* self, uint32_t param_1, uint32_t unaff_retaddr) {
  int in_ECX = (int)(uintptr_t)self;
  char cVar1;
  int iVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  bool bVar5;
  uint8_t auStack_16[2];
  uint32_t* obj = *(uint32_t**)(in_ECX + 0x60);

  iVar2 = (**(int(**)(void))(*obj + 0xc))();
  if (iVar2 == -0x7789f797) {
    cVar1 = (char)FUN_005c64b0(self);
    bVar5 = cVar1 == '\0';
  } else {
    bVar5 = iVar2 == -0x7789f798;
  }
  if (!bVar5) {
    iVar2 = *(int*)(in_ECX + 0x5a4);
    uVar4 = 0;
    if (unaff_retaddr != 0) {
      FUN_005f0ddc();
      FUN_005f0ddc();
      FUN_005f0ddc();
      FUN_005f0ddc();
    }
    if (((param_1 & 4) == 0) || (*(int*)(iVar2 + 0x10) == 0)) {
      uVar3 = 0;
    } else {
      uVar3 = 2;
    }
    if ((((param_1 & 2) != 0) && (*(char*)(in_ECX + 0x294) < '\0')) &&
        (*(int*)(iVar2 + 0x10) != 0)) {
      uVar4 = 4;
    }
    *(uint32_t*)(in_ECX + 0x43c) = *(uint32_t*)(iVar2 + 4);
    *(uint32_t*)(in_ECX + 0x440) = *(uint32_t*)(iVar2 + 8);
    (**(void(**)(uint32_t*, uint32_t*))(*obj + 0xbc))(obj, (uint32_t*)(uintptr_t)(in_ECX + 0x434));
    (**(void(**)(uint32_t*, int, void*, uint32_t, uint32_t, uint32_t, uint32_t))(*obj + 0xac))(
        obj, 1, (void*)((uintptr_t)auStack_16 - 6), uVar4 | (param_1 & 1) | uVar3,
        *(uint32_t*)(in_ECX + 0x288), *(uint32_t*)(in_ECX + 0x28c),
        *(uint32_t*)(in_ECX + 0x290));
  }
}

// 0x5c6c70 — observed shape
// NEEDS_MANUAL: unaff_retaddr is a caller-supplied stack argument that the provider modelled as
// the return address; it is exposed here as an explicit fifth parameter.
void FUN_005c6c70(void* self, float* param_1, float* param_2, float* param_3, float* unaff_retaddr) {
  int in_ECX = (int)(uintptr_t)self;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  char cVar10;
  int iVar11;
  bool bVar12;
  uint32_t uStack_34;
  int iStack_30;
  float fStack_18;
  float fStack_14;
  uint32_t* obj = *(uint32_t**)(in_ECX + 0x60);
  uint32_t* obj5cc = *(uint32_t**)(in_ECX + 0x5cc);

  iVar11 = (**(int(**)(void))(*obj + 0xc))();
  if (iVar11 == -0x7789f797) {
    cVar10 = (char)FUN_005c64b0(self);
    bVar12 = cVar10 == '\0';
  } else {
    bVar12 = iVar11 == -0x7789f798;
  }
  if (!bVar12) {
    *(float*)(in_ECX + 0x7c0) = *param_3;
    *(float*)(in_ECX + 0x7c4) = *param_2;
    *(float*)(in_ECX + 0x7c8) = *param_1;
    *(uint32_t*)(in_ECX + 0x7cc) = 0;
    *(float*)(in_ECX + 0x7d0) = param_3[1];
    *(float*)(in_ECX + 0x7d4) = param_2[1];
    *(float*)(in_ECX + 0x7d8) = param_1[1];
    *(uint32_t*)(in_ECX + 0x7dc) = 0;
    *(float*)(in_ECX + 0x7e0) = param_3[2];
    *(float*)(in_ECX + 0x7e4) = param_2[2];
    *(float*)(in_ECX + 0x7e8) = param_1[2];
    *(uint32_t*)(in_ECX + 0x7ec) = 0;
    *(float*)(in_ECX + 0x7f0) =
        -(unaff_retaddr[1] * param_3[1] + unaff_retaddr[2] * param_3[2] + *unaff_retaddr * *param_3);
    *(float*)(in_ECX + 0x7f4) =
        -(*unaff_retaddr * *param_2 + unaff_retaddr[2] * param_2[2] + unaff_retaddr[1] * param_2[1]);
    fVar1 = unaff_retaddr[2];
    fVar2 = param_1[2];
    fVar3 = *unaff_retaddr;
    fVar4 = *param_1;
    fVar5 = unaff_retaddr[1];
    fVar6 = param_1[1];
    *(uint32_t*)(in_ECX + 0x7fc) = 0x3f800000;
    *(float*)(in_ECX + 0x7f8) = -(fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2);
    *(float*)(in_ECX + 0x840) = *param_3;
    *(float*)(in_ECX + 0x844) = param_3[1];
    *(float*)(in_ECX + 0x848) = param_3[2];
    *(uint32_t*)(in_ECX + 0x84c) = 0;
    *(float*)(in_ECX + 0x850) = *param_2;
    *(float*)(in_ECX + 0x854) = param_2[1];
    *(float*)(in_ECX + 0x858) = param_2[2];
    *(uint32_t*)(in_ECX + 0x85c) = 0;
    *(float*)(in_ECX + 0x860) = *param_1;
    *(float*)(in_ECX + 0x864) = param_1[1];
    *(float*)(in_ECX + 0x868) = param_1[2];
    *(uint32_t*)(in_ECX + 0x86c) = 0;
    *(float*)(in_ECX + 0x870) = *unaff_retaddr;
    *(float*)(in_ECX + 0x874) = unaff_retaddr[1];
    iStack_30 = in_ECX + 0x7c0;
    uStack_34 = 2;
    *(float*)(in_ECX + 0x878) = unaff_retaddr[2];
    *(uint32_t*)(in_ECX + 0x87c) = 0x3f800000;
    (**(void(**)(uint32_t*))(*obj + 0xb0))(obj);
    *(float*)(in_ECX + 0x2f4) = *param_3;
    *(float*)(in_ECX + 0x2f8) = param_3[1];
    *(float*)(in_ECX + 0x2fc) = param_3[2];
    *(float*)(in_ECX + 0x2dc) = *param_3;
    *(float*)(in_ECX + 0x2e0) = param_3[1];
    *(float*)(in_ECX + 0x2e4) = param_3[2];
    *(float*)(in_ECX + 0x300) = *param_2;
    *(float*)(in_ECX + 0x304) = param_2[1];
    *(float*)(in_ECX + 0x308) = param_2[2];
    *(float*)(in_ECX + 0x2e8) = *param_2;
    *(float*)(in_ECX + 0x2ec) = param_2[1];
    *(float*)(in_ECX + 0x2f0) = param_2[2];
    *(float*)(in_ECX + 0x32c) = param_1[4];
    fVar1 = param_1[5];
    fVar2 = param_1[4];
    *(float*)(in_ECX + 0x330) = fVar1 - fVar2;
    fVar3 = param_1[1];
    fVar4 = *param_1;
    fVar9 = *param_1 + param_1[1];
    fVar5 = param_1[2];
    fVar6 = param_1[3];
    fVar7 = param_1[2];
    fVar8 = param_1[3];
    fVar1 = 1.0 / (fVar1 - fVar2);
    if (*(char*)(param_1 + 6) == '\0') {
      cVar10 = (**(char(**)())(*obj5cc + 0x54))();
      fVar2 = 1.0 / (fVar3 - fVar4);
      *(uint32_t*)(in_ECX + 0x830) = 0;
      *(uint32_t*)(in_ECX + 0x810) = 0;
      if (cVar10 == '\0') {
        *(float*)(in_ECX + 0x800) = fVar2 + fVar2;
        fVar2 = -(fVar2 * fVar9);
      } else {
        *(float*)(in_ECX + 0x800) = fVar2 * -2.0;
        fVar2 = fVar2 * fVar9;
      }
      *(float*)(in_ECX + 0x820) = fVar2;
      *(uint32_t*)(in_ECX + 0x804) = 0;
      *(uint32_t*)(in_ECX + 0x834) = 0;
      fVar2 = 1.0 / (fVar5 - fVar6);
      *(uint32_t*)(in_ECX + 0x808) = 0;
      *(uint32_t*)(in_ECX + 0x818) = 0;
      *(float*)(in_ECX + 0x814) = fVar2 + fVar2;
      *(float*)(in_ECX + 0x824) = -(fVar2 * (fVar7 + fVar8));
      *(float*)(in_ECX + 0x828) = fVar1 * param_1[5];
      fVar2 = param_1[5] * param_1[4];
      *(uint32_t*)(in_ECX + 0x82c) = 0x3f800000;
      *(uint32_t*)(in_ECX + 0x83c) = 0;
    } else {
      cVar10 = (**(char(**)())(*obj5cc + 0x54))();
      fVar2 = 1.0 / (fVar3 - fVar4);
      *(uint32_t*)(in_ECX + 0x820) = 0;
      *(uint32_t*)(in_ECX + 0x810) = 0;
      if (cVar10 == '\0') {
        *(float*)(in_ECX + 0x800) = fVar2 + fVar2;
        fVar2 = -(fVar2 * fVar9);
      } else {
        *(float*)(in_ECX + 0x800) = fVar2 * -2.0;
        fVar2 = fVar2 * fVar9;
      }
      *(float*)(in_ECX + 0x830) = fVar2;
      *(uint32_t*)(in_ECX + 0x804) = 0;
      fVar2 = 1.0 / (fVar5 - fVar6);
      *(uint32_t*)(in_ECX + 0x824) = 0;
      *(uint32_t*)(in_ECX + 0x808) = 0;
      *(uint32_t*)(in_ECX + 0x818) = 0;
      *(float*)(in_ECX + 0x828) = fVar1;
      *(float*)(in_ECX + 0x814) = fVar2 + fVar2;
      *(float*)(in_ECX + 0x834) = -(fVar2 * (fVar7 + fVar8));
      fVar2 = param_1[4];
      *(uint32_t*)(in_ECX + 0x82c) = 0;
      *(uint32_t*)(in_ECX + 0x83c) = 0x3f800000;
    }
    *(float*)(in_ECX + 0x838) = -(fVar1 * fVar2);
    *(uint32_t*)(in_ECX + 0x3dc) = *(uint32_t*)(in_ECX + 0x828);
    *(uint32_t*)(in_ECX + 0x80c) = 0;
    *(uint32_t*)(in_ECX + 0x81c) = 0;
    *(uint32_t*)(in_ECX + 0x3ec) = *(uint32_t*)(in_ECX + 0x838);
    (**(void(**)(uint32_t*, int, uint32_t*))(*obj + 0xb0))(
        obj, 3, (uint32_t*)(uintptr_t)(in_ECX + 0x800));
    uStack_34 = 0;
    iStack_30 = 0;
    uStack_34 = FUN_005f0ddc();
    iStack_30 = (int)FUN_005f0ddc();
    // NEEDS_MANUAL: the provider discards the two following FPU results; fStack_18 and
    // fStack_14 are the unmodelled destination slots read by the 0x374/0x388/0x3a4/0x3a8 math.
    FUN_005f0ddc();
    FUN_005f0ddc();
    (**(void(**)(uint32_t*, uint32_t*))(*obj + 0xbc))(obj, &uStack_34);
    *(float*)(in_ECX + 0x374) = 1.0 / fStack_14;
    *(float*)(in_ECX + 0x388) = -1.0 / fStack_18;
    *(float*)(in_ECX + 0x3a4) = (1.0 / fStack_14) * -0.5;
    *(float*)(in_ECX + 0x3a8) = 1.0 - (-1.0 / fStack_18) * 0.5;
    if (obj5cc != (uint32_t*)0) {
      (**(void(**)(float, float))(*obj5cc + 0x50))(param_1[4], param_1[5]);
    }
  }
}

// 0x5c7170 — observed shape
void FUN_005c7170(void* self) {
  uint32_t* in_ECX = (uint32_t*)self;

  FUN_005383d0();
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  *(uint8_t*)(in_ECX + 0xb) = 0;
  *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c7690;
}

// 0x5c71a0 — observed shape
void FUN_005c71a0(void* self) {
  uint32_t* in_ECX = (uint32_t*)self;
  uint32_t uVar1;
  int iVar2;

  *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_006c7690;
  if (in_ECX[10] != 0) {
    uVar1 = 0;
    if (in_ECX[9] != 0) {
      iVar2 = 0;
      do {
        if (in_ECX[10] + iVar2 != 0) {
          operator_delete__(*(void**)(uintptr_t)(in_ECX[10] + iVar2 + 8));
        }
        uVar1 = uVar1 + 1;
        iVar2 = iVar2 + 0x10;
      } while (uVar1 < in_ECX[9]);
    }
    operator_delete__((void*)(uintptr_t)in_ECX[10]);
  }
  in_ECX[10] = 0;
  in_ECX[3] = 0;
  (**(void(**)(uint32_t*))(*(uint32_t*)(uintptr_t)in_ECX[5] + 8))(
      (uint32_t*)(uintptr_t)in_ECX[5]);
  in_ECX[5] = 0;
  FUN_00538400();
}
