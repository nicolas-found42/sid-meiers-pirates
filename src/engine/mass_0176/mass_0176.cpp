#include <cstdint>
#include <cstddef>
#include <cstring>

extern void FUN_00582320(uint32_t param_1);
extern uint32_t FUN_00557b10(uint32_t param_1);
extern void FUN_006b34a0(int32_t param_1);
extern void FUN_005606f0(uint32_t param_1, uint32_t* param_2);
extern void* FUN_00533c78(uint32_t size);
extern void FUN_005383d0(void);
extern void FUN_00577d90(uint32_t param_1, uint32_t param_2, uint32_t param_3);
extern void FUN_00582030(void);
extern void operator_delete(void* ptr);
extern void operator_delete__(void* ptr);
extern void thunk_FUN_00553060(uint32_t param_1);
extern void* FUN_00545600(void);
extern int32_t* FUN_00538580(uint32_t** param_1);
extern void FUN_00552ef0(int32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4);
extern int32_t FUN_00538680(void);
extern void FUN_00576320(uint32_t param_1, uint32_t param_2, uint32_t param_3, int32_t param_4, uint32_t param_5, uint32_t param_6, uint32_t* param_7, uint32_t* param_8);
extern void FUN_00576d30(uint32_t param_1, uint32_t param_2, uint32_t param_3);
extern void FUN_00582880(void* param_1, void* param_2, uint32_t param_3, uint32_t param_4);
extern void FUN_00553060(uint32_t param_1);
extern void FUN_00577840(void* self);
extern void FUN_00577450(void* self, uint32_t param_1, uint32_t param_2);
extern void FUN_005778a0(void* self, uint32_t param_1, uint32_t param_2, char param_3);
extern void FUN_00582420(uint32_t param_1, int32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t* param_5, uint32_t* param_6);
extern void FUN_00552d20(void);
extern void FUN_00552c80(void);
extern void FUN_00552aa0(void* param_1, uint32_t param_2);
extern void FUN_005531c0(uint32_t param_1);
extern void FUN_00538400(void);
extern void FUN_00576640(uint32_t param_1, uint32_t param_2, uint32_t* param_3, void* param_4, uint32_t param_5, uint32_t param_6);

extern uint32_t DAT_00728998;
extern uint32_t DAT_007289a8;
extern uint32_t DAT_007289b8;
extern void* PTR_FUN_006fe39c;
extern void* PTR_FUN_006c4530;
extern void* PTR_FUN_006c45b0;
extern void* PTR_FUN_006c4618;
extern void* PTR_FUN_006c4660;
extern void* PTR_FUN_006c46c8;

typedef void (*ReleaseFn)(void*, int);

// 0x576c60 — observed shape
void FUN_00576c60_recon(uint32_t param_1)
{
  uint32_t uVar1;
  int32_t iVar2;

  iVar2 = (int32_t)param_1;
  FUN_00582320(param_1);
  param_1 = FUN_00557b10(DAT_00728998);
  uVar1 = *(uint32_t*)(iVar2 + 0xc);
  if (*(uint32_t*)(iVar2 + 8) <= uVar1) {
    FUN_006b34a0(*(int32_t*)(iVar2 + 0x14) + (int32_t)uVar1);
  }
  FUN_005606f0(uVar1, &param_1);
}

// 0x576d30 — observed shape
void FUN_00576d30_recon(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3)
{
  int32_t* piVar1;
  uint32_t* puVar2;
  int32_t iVar3;
  int32_t iVar4;
  uint32_t* puVar5;
  uint32_t* self_words = (uint32_t*)self;

  if ((int32_t)self_words[0x50 / 4] == 0) {
    puVar5 = (uint32_t*)FUN_00533c78(0x18);
    if (puVar5 == nullptr) {
      puVar5 = nullptr;
    } else {
      FUN_005383d0();
      puVar5[0] = (uint32_t)(uintptr_t)&PTR_FUN_006fe39c;
      puVar5[3] = 0;
      puVar5[4] = 0;
      puVar5[5] = 0;
    }
    puVar2 = *(uint32_t**)((intptr_t)self + 0x50);
    if (puVar2 != puVar5) {
      if (puVar2 != nullptr) {
        piVar1 = (int32_t*)puVar2 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          ((ReleaseFn)puVar2[0])(puVar2, 1);
        }
      }
      *(uint32_t**)((intptr_t)self + 0x50) = puVar5;
      if (puVar5 != nullptr) {
        puVar5[1] = puVar5[1] + 1;
      }
    }
  }
  FUN_00577d90(param_2, param_1, param_3);
  iVar3 = *(int32_t*)((intptr_t)self + 0x50);
  *(uint32_t*)((intptr_t)self + 0x18) = 0x7f7fffff;
  *(uint32_t*)((intptr_t)self + 0x4c) = 0;
  *(uint32_t*)((intptr_t)self + 0x1c) = 0xff7fffff;
  if (iVar3 != 0) {
    iVar4 = *(int32_t*)(iVar3 + 0xc);
    puVar5 = *(uint32_t**)(iVar3 + 0x10);
    if (iVar4 != 0) {
      *(uint32_t*)((intptr_t)self + 0x18) = *puVar5;
      *(uint32_t*)((intptr_t)self + 0x1c) =
           *(uint32_t*)((uint32_t)*(uint8_t*)(puVar5 + 1) * (uint32_t)(iVar4 + -1) + (int32_t)(uintptr_t)puVar5);
    }
  }
}

// 0x576e20 — observed shape
void FUN_00576e20_recon(void* self, uint8_t param_1)
{
  int32_t* piVar1;
  uint32_t* puVar2;
  uint32_t* self_words = (uint32_t*)self;

  self_words[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c4530;
  puVar2 = (uint32_t*)self_words[0x14];
  if (puVar2 != nullptr) {
    piVar1 = (int32_t*)puVar2 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      ((ReleaseFn)puVar2[0])(puVar2, 1);
    }
  }
  FUN_00582030();
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x577100 — observed shape
uint32_t FUN_00577100_recon(void* self, uint32_t* param_1, uint32_t* param_2)
{
  int32_t iVar1;

  iVar1 = *(int32_t*)((intptr_t)self + 0x50);
  if (iVar1 == 0) {
    *param_1 = 0;
    *param_2 = 0;
    return 0;
  }
  *param_1 = *(uint32_t*)(iVar1 + 0xc);
  *param_2 = *(uint32_t*)(iVar1 + 0x14);
  return *(uint32_t*)(iVar1 + 0x10);
}

// 0x577150 — observed shape
void FUN_00577150_recon(void* self, uint32_t param_1)
{
  int32_t* piVar1;
  uint32_t* puVar2;
  uint32_t* puVar3;

  thunk_FUN_00553060(param_1);
  puVar3 = (uint32_t*)FUN_00545600();
  puVar2 = *(uint32_t**)((intptr_t)self + 0x50);
  if (puVar2 != puVar3) {
    if (puVar2 != nullptr) {
      piVar1 = (int32_t*)puVar2 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        ((ReleaseFn)puVar2[0])(puVar2, 1);
      }
    }
    *(uint32_t**)((intptr_t)self + 0x50) = puVar3;
    if (puVar3 != nullptr) {
      puVar3[1] = puVar3[1] + 1;
    }
  }
}

// 0x5771b0 — observed shape
void FUN_005771b0_recon(void* self, uint8_t param_1)
{
  int32_t* piVar1;
  uint32_t* puVar2;
  uint32_t* self_words = (uint32_t*)self;

  self_words[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c45b0;
  puVar2 = (uint32_t*)self_words[0x14];
  if (puVar2 != nullptr) {
    piVar1 = (int32_t*)puVar2 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      ((ReleaseFn)puVar2[0])(puVar2, 1);
    }
  }
  FUN_00582030();
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x577250 — observed shape
int32_t FUN_00577250_recon(uint32_t param_1, uint32_t param_2, uint32_t param_3)
{
  uint32_t* puVar1;
  uint32_t* puVar2;
  int32_t iVar3;
  uint32_t uVar4;
  int32_t* piVar5;
  int32_t iVar6;
  uint32_t uStack_c;
  uint32_t uStack_8;
  uint32_t* local_4 = nullptr;

  piVar5 = FUN_00538580(&local_4);
  puVar1 = (uint32_t*)*piVar5;
  if (puVar1 != nullptr) {
    puVar1[1] = puVar1[1] + 1;
  }
  if ((local_4 != nullptr) &&
     (iVar6 = (int32_t)local_4[1], local_4[1] = (uint32_t)(iVar6 + -1), iVar6 + -1 == 0)) {
    ((ReleaseFn)local_4[0])(local_4, 1);
  }
  iVar6 = FUN_00538680();
  FUN_00552ef0(iVar6, param_1, param_2, param_3);
  puVar2 = *(uint32_t**)(iVar6 + 0x50);
  if (puVar2 != puVar1) {
    if (puVar2 != nullptr) {
      piVar5 = (int32_t*)puVar2 + 1;
      *piVar5 = *piVar5 + -1;
      if (*piVar5 == 0) {
        ((ReleaseFn)puVar2[0])(puVar2, 1);
      }
    }
    *(uint32_t**)(iVar6 + 0x50) = puVar1;
    if (puVar1 != nullptr) {
      puVar1[1] = puVar1[1] + 1;
    }
  }
  uStack_8 = 0;
  uStack_c = 0;
  iVar3 = *(int32_t*)(iVar6 + 0x50);
  if (iVar3 != 0) {
    uVar4 = *(uint32_t*)(iVar3 + 0x14);
    if (*(int32_t*)(iVar3 + 0xc) != 0) {
      FUN_00576320(0, uVar4, *(uint32_t*)(iVar3 + 0x10), *(int32_t*)(iVar3 + 0xc), param_1, param_2,
                   &uStack_c, &uStack_8);
      FUN_00576d30(uStack_8, uStack_c, uVar4);
    }
  }
  if (puVar1 != nullptr) {
    piVar5 = (int32_t*)puVar1 + 1;
    *piVar5 = *piVar5 + -1;
    if (*piVar5 == 0) {
      ((ReleaseFn)puVar1[0])(puVar1, 1);
    }
  }
  return iVar6;
}

// 0x577400 — observed shape
void FUN_00577400_recon(uint32_t param_1)
{
  uint32_t uVar1;
  int32_t iVar2;

  iVar2 = (int32_t)param_1;
  FUN_00582320(param_1);
  param_1 = FUN_00557b10(DAT_007289a8);
  uVar1 = *(uint32_t*)(iVar2 + 0xc);
  if (*(uint32_t*)(iVar2 + 8) <= uVar1) {
    FUN_006b34a0(*(int32_t*)(iVar2 + 0x14) + (int32_t)uVar1);
  }
  FUN_005606f0(uVar1, &param_1);
}

// 0x577450 — observed shape
void FUN_00577450_recon(void* self, uint32_t param_1, uint32_t param_2)
{
  operator_delete__(*(void**)((intptr_t)self + 0x10));
  if ((param_1 == 0) || (param_2 == 0)) {
    *(uint32_t*)((intptr_t)self + 0xc) = 0;
    *(uint32_t*)((intptr_t)self + 0x10) = 0;
    return;
  }
  *(int32_t*)((intptr_t)self + 0xc) = (int32_t)param_2;
  *(int32_t*)((intptr_t)self + 0x10) = (int32_t)param_1;
}

// 0x577490 — observed shape
void FUN_00577490_recon(void* self, uint32_t param_1, uint32_t param_2)
{
  FUN_00582880((void*)((intptr_t)self + 0x10), (void*)((intptr_t)self + 0xc), param_1, param_2);
}

// 0x5774c0 — observed shape
void FUN_005774c0_recon(void* self, uint8_t param_1)
{
  uint32_t* self_words = (uint32_t*)self;

  self_words[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c4618;
  operator_delete__((void*)self_words[4]);
  FUN_00538400();
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x577770 — observed shape
void FUN_00577770_recon(void* self, uint32_t param_1)
{
  int32_t* piVar1;
  uint32_t* puVar2;
  uint32_t* puVar3;

  FUN_00553060(param_1);
  puVar3 = (uint32_t*)FUN_00545600();
  puVar2 = *(uint32_t**)((intptr_t)self + 0x44);
  if (puVar2 != puVar3) {
    if (puVar2 != nullptr) {
      piVar1 = (int32_t*)puVar2 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        ((ReleaseFn)puVar2[0])(puVar2, 1);
      }
    }
    *(uint32_t**)((intptr_t)self + 0x44) = puVar3;
    if (puVar3 != nullptr) {
      puVar3[1] = puVar3[1] + 1;
    }
  }
}

// 0x577840 — observed shape
void FUN_00577840_recon(void* self)
{
  int32_t iVar1;
  float* pfVar2;

  iVar1 = *(int32_t*)((intptr_t)self + 0x44);
  *(uint32_t*)((intptr_t)self + 0x18) = 0x7f7fffff;
  *(uint32_t*)((intptr_t)self + 0x1c) = 0xff7fffff;
  if (iVar1 == 0) {
    *(uint32_t*)((intptr_t)self + 0x48) = 0;
    return;
  }
  pfVar2 = *(float**)(iVar1 + 0x10);
  iVar1 = *(int32_t*)(iVar1 + 0xc);
  if (pfVar2 != nullptr) {
    if (*pfVar2 < 3.4028235e+38f) {
      *(float*)((intptr_t)self + 0x18) = *pfVar2;
    }
    if (-3.4028235e+38f < pfVar2[iVar1 * 2 + -2]) {
      *(float*)((intptr_t)self + 0x1c) = pfVar2[iVar1 * 2 + -2];
    }
  }
  *(uint32_t*)((intptr_t)self + 0x48) = 0;
}

// 0x5778a0 — observed shape
void FUN_005778a0_recon(void* self, uint32_t param_1, uint32_t param_2, char param_3)
{
  int32_t* piVar1;
  uint32_t* puVar2;
  uint32_t* puVar3;

  if (*(int32_t*)((intptr_t)self + 0x44) == 0) {
    puVar3 = (uint32_t*)FUN_00533c78(0x14);
    if (puVar3 == nullptr) {
      puVar3 = nullptr;
    } else {
      FUN_005383d0();
      puVar3[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c4618;
      puVar3[3] = 0;
      puVar3[4] = 0;
    }
    puVar2 = *(uint32_t**)((intptr_t)self + 0x44);
    if (puVar2 != puVar3) {
      if (puVar2 != nullptr) {
        piVar1 = (int32_t*)puVar2 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          ((ReleaseFn)puVar2[0])(puVar2, 1);
        }
      }
      *(uint32_t**)((intptr_t)self + 0x44) = puVar3;
      if (puVar3 != nullptr) {
        puVar3[1] = puVar3[1] + 1;
      }
    }
  }
  FUN_00577450(self, param_1, param_2);
  if (param_3 != '\0') {
    FUN_00577840(self);
  }
  *(uint32_t*)((intptr_t)self + 0x48) = 0;
}

// 0x577970 — observed shape
int32_t FUN_00577970_recon(uint32_t param_1, uint32_t param_2, uint32_t param_3)
{
  uint32_t* puVar1;
  uint32_t* puVar2;
  int32_t iVar3;
  int32_t* piVar4;
  int32_t iVar5;
  uint32_t uStack_c;
  uint32_t uStack_8;
  uint32_t* local_4 = nullptr;

  piVar4 = FUN_00538580(&local_4);
  puVar1 = (uint32_t*)*piVar4;
  if (puVar1 != nullptr) {
    puVar1[1] = puVar1[1] + 1;
  }
  if ((local_4 != nullptr) &&
     (iVar5 = (int32_t)local_4[1], local_4[1] = (uint32_t)(iVar5 + -1), iVar5 + -1 == 0)) {
    ((ReleaseFn)local_4[0])(local_4, 1);
  }
  iVar5 = FUN_00538680();
  FUN_00552ef0(iVar5, param_1, param_2, param_3);
  puVar2 = *(uint32_t**)(iVar5 + 0x44);
  if (puVar2 != puVar1) {
    if (puVar2 != nullptr) {
      piVar4 = (int32_t*)puVar2 + 1;
      *piVar4 = *piVar4 + -1;
      if (*piVar4 == 0) {
        ((ReleaseFn)puVar2[0])(puVar2, 1);
      }
    }
    *(uint32_t**)(iVar5 + 0x44) = puVar1;
    if (puVar1 != nullptr) {
      puVar1[1] = puVar1[1] + 1;
    }
  }
  uStack_c = 0;
  uStack_8 = 0;
  iVar3 = *(int32_t*)(iVar5 + 0x44);
  if (iVar3 != 0) {
    if (*(int32_t*)(iVar3 + 0xc) != 0) {
      FUN_00582420(*(uint32_t*)(iVar3 + 0x10), *(int32_t*)(iVar3 + 0xc), param_1, param_2, &uStack_8,
                   &uStack_c);
      FUN_005778a0((void*)iVar5, uStack_8, uStack_c, 1);
    }
  }
  if (puVar1 != nullptr) {
    piVar4 = (int32_t*)puVar1 + 1;
    *piVar4 = *piVar4 + -1;
    if (*piVar4 == 0) {
      ((ReleaseFn)puVar1[0])(puVar1, 1);
    }
  }
  return iVar5;
}

// 0x577aa0 — observed shape
void FUN_00577aa0_recon(void* self, uint8_t param_1)
{
  int32_t* piVar1;
  uint32_t* puVar2;
  uint32_t* self_words = (uint32_t*)self;

  self_words[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c4660;
  puVar2 = (uint32_t*)self_words[0x11];
  if (puVar2 != nullptr) {
    piVar1 = (int32_t*)puVar2 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      ((ReleaseFn)puVar2[0])(puVar2, 1);
    }
    self_words[0x11] = 0;
  }
  puVar2 = (uint32_t*)self_words[0x11];
  if (puVar2 != nullptr) {
    piVar1 = (int32_t*)puVar2 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      ((ReleaseFn)puVar2[0])(puVar2, 1);
    }
  }
  FUN_00552d20();
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x577b00 — observed shape
uint32_t* FUN_00577b00_recon(void* self, uint32_t param_1)
{
  int32_t* piVar1;
  uint32_t* puVar2;
  uint32_t* puVar3;
  uint32_t* puVar4;
  typedef uint32_t* (*GetFn)(void*, uint32_t);

  puVar3 = (uint32_t*)FUN_00533c78(0x4c);
  if (puVar3 == nullptr) {
    puVar3 = nullptr;
  } else {
    FUN_00552c80();
    puVar3[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c4660;
    puVar3[0x11] = 0;
    puVar3[0x12] = 0;
  }
  FUN_00552aa0(puVar3, param_1);
  if (*(int32_t**)((intptr_t)self + 0x44) != nullptr) {
    puVar4 = (uint32_t*)(*(GetFn*)(**(int32_t**)((intptr_t)self + 0x44) + 8))(*(void**)((intptr_t)self + 0x44), param_1);
    puVar2 = (uint32_t*)puVar3[0x11];
    if (puVar2 != puVar4) {
      if (puVar2 != nullptr) {
        piVar1 = (int32_t*)puVar2 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          ((ReleaseFn)puVar2[0])(puVar2, 1);
        }
      }
      puVar3[0x11] = (uint32_t)(uintptr_t)puVar4;
      if (puVar4 != nullptr) {
        puVar4[1] = puVar4[1] + 1;
      }
    }
  }
  return puVar3;
}

// 0x577b80 — observed shape
void FUN_00577b80_recon(uint32_t param_1)
{
  uint32_t uVar1;
  int32_t iVar2;

  iVar2 = (int32_t)param_1;
  FUN_005531c0(param_1);
  param_1 = FUN_00557b10(DAT_007289b8);
  uVar1 = *(uint32_t*)(iVar2 + 0xc);
  if (*(uint32_t*)(iVar2 + 8) <= uVar1) {
    FUN_006b34a0(*(int32_t*)(iVar2 + 0x14) + (int32_t)uVar1);
  }
  FUN_005606f0(uVar1, &param_1);
}

// 0x577bd0 — observed shape
void FUN_00577bd0_recon(void* self)
{
  uint32_t* self_words = (uint32_t*)self;

  FUN_005383d0();
  self_words[3] = 0;
  self_words[4] = 0;
  self_words[5] = 0;
  self_words[6] = 0;
  self_words[7] = 0;
  self_words[8] = 0;
  self_words[9] = 0;
  self_words[10] = 0;
  self_words[0xb] = 0;
  self_words[0xc] = 0;
  self_words[0xd] = 0;
  self_words[0xe] = 0;
  self_words[0xf] = 0;
  self_words[0x10] = 0;
  self_words[0x11] = 0x3f800000;
  self_words[0x12] = 0x3f800000;
  self_words[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c46c8;
}

// 0x577c20 — observed shape
void FUN_00577c20_recon(void* self, uint32_t param_1, uint32_t param_2)
{
  uint32_t uVar1;

  uVar1 = param_2;
  if (*(int32_t*)((intptr_t)self + 0xc) != 0) {
    param_2 = *(uint32_t*)((intptr_t)self + 0x10);
    FUN_00576640(0, *(uint32_t*)((intptr_t)self + 0x14), &param_2, (void*)((intptr_t)self + 0xc), param_1, uVar1);
    *(uint32_t*)((intptr_t)self + 0x10) = param_2;
  }
  if (*(int32_t*)((intptr_t)self + 0x18) != 0) {
    param_2 = *(uint32_t*)((intptr_t)self + 0x1c);
    FUN_00576640(0, *(uint32_t*)((intptr_t)self + 0x20), &param_2, (void*)((intptr_t)self + 0x18), param_1, uVar1);
    *(uint32_t*)((intptr_t)self + 0x1c) = param_2;
  }
  if (*(int32_t*)((intptr_t)self + 0x24) != 0) {
    param_2 = *(uint32_t*)((intptr_t)self + 0x28);
    FUN_00576640(0, *(uint32_t*)((intptr_t)self + 0x2c), &param_2, (void*)((intptr_t)self + 0x24), param_1, uVar1);
    *(uint32_t*)((intptr_t)self + 0x28) = param_2;
  }
  if (*(int32_t*)((intptr_t)self + 0x30) != 0) {
    param_2 = *(uint32_t*)((intptr_t)self + 0x34);
    FUN_00576640(0, *(uint32_t*)((intptr_t)self + 0x38), &param_2, (void*)((intptr_t)self + 0x30), param_1, uVar1);
    *(uint32_t*)((intptr_t)self + 0x34) = param_2;
  }
}
