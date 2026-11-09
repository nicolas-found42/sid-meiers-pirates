// Sid Meier's Pirates! (2004) — PE32 i386 — reconstruction batch mass_0100
// Source: Ghidra 12.2 pseudocode in analysis/pseudocode/functions/0x51*.c
// Candidate definitions only; addresses are provider-normalized image addresses.

#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_004f5670(void);
extern void FUN_004e6420(void);
extern void operator_delete(void* p);
extern void operator_delete__(void* p);

extern void FUN_004127b0(void* dst, uint32_t elem_size, uint32_t count, const void* init);
extern void* FUN_00533c78(uint32_t size);
extern void* thunk_FUN_00533c78(uint32_t size);
extern void* FUN_00533db0(uint32_t size);

extern void FUN_0050be00(uint32_t param_1);
extern void FUN_0050c1d0(uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, int32_t p6);
extern int FUN_0050bf50(int param_1);
extern void FUN_00513730(void** out, uint32_t a, uint32_t b);
extern void FUN_0051cb70(void* self);
extern void FUN_0051c250(void* self = nullptr, uint16_t* in_eax = nullptr, float* in_esi = nullptr);
extern void FUN_00534130(void);
extern void FUN_00540c50(void);
extern void FUN_00542690(void* p);
extern void* FUN_00542700(void* a, int32_t b, int32_t c, int32_t d, int32_t e);
extern void* FUN_005428c0(void);
extern void FUN_00542cb0(uint32_t index, void* p);
extern void FUN_00555340(void* self);
extern void* FUN_005553b0(void* storage);
extern void FUN_005606f0(uint32_t index, void** slot);
extern void FUN_00581300(uint32_t index, uint32_t* out);
extern void* FUN_005c9680(uint32_t count);
extern void FUN_005c96f0(uint32_t index, void* p, uint32_t size);
extern uint32_t FUN_005c9560(uint32_t index, uint8_t* out);

extern void* PTR_LAB_00712790;
extern void* PTR_FUN_00712788;
extern void* PTR_FUN_00711fbc;
extern void* PTR_FUN_007127f0;
extern void* PTR_FUN_007127d4;
extern void* PTR_FUN_00712780;
extern void* PTR_FUN_00712848;
extern void* PTR_FUN_0071289c;
extern void* PTR_FUN_0070bf10;
extern void* PTR_FUN_0070bf4c;
extern void* PTR_FUN_0070d038;
extern uint8_t DAT_00727598;
extern uint8_t DAT_007275e8;
extern uint8_t LAB_005cea70;
extern uint8_t LAB_004c2970;
extern int32_t* DAT_008cad3c;
extern void* DAT_008cad54;
extern uint32_t* DAT_008ea524;


// 0x51aef0 — observed shape (destructor: resets three vtable slots, releases d[2], deletes d[0x16])
void FUN_0051aef0(void* self_in_EDI)
{
  uint32_t* d = (uint32_t*)self_in_EDI;
  uint32_t* p;
  int32_t* ref;

  d[0] = (uint32_t)(uintptr_t)&PTR_LAB_00712790;
  if (d[2] != 0) {
    *(uint32_t*)(d[2] + 0x24) = 0;
    p = (uint32_t*)d[2];
    if (p != nullptr) {
      ref = (int32_t*)(p + 1);
      *ref = *ref - 1;
      if (*ref == 0) {
        (*(void(**)(int32_t))(uintptr_t)*p)(1);
      }
      d[2] = 0;
    }
  }
  FUN_004f5670();
  d[0x15] = (uint32_t)(uintptr_t)&PTR_FUN_00712788;
  operator_delete__((void*)(uintptr_t)d[0x16]);
  d[0] = (uint32_t)(uintptr_t)&PTR_FUN_00711fbc;
  p = (uint32_t*)d[2];
  if (p != nullptr) {
    ref = (int32_t*)(p + 1);
    *ref = *ref - 1;
    if (*ref == 0) {
      (*(void(**)(int32_t))(uintptr_t)*p)(1);
    }
    d[2] = 0;
  }
  p = (uint32_t*)d[2];
  if (p != nullptr) {
    ref = (int32_t*)(p + 1);
    *ref = *ref - 1;
    if (*ref == 0) {
      (*(void(**)(int32_t))(uintptr_t)*p)(1);
    }
  }
}


// 0x51b0d0 — observed shape (walks object array, resolves a linked subclass node, rebuilds a surface)
void FUN_0051b0d0(void* self, void* param_1)
{
  uint8_t* recv = (uint8_t*)self;
  uint8_t* local_c = recv;
  uint32_t local_8 = 0;
  int32_t iVar6 = *(int32_t*)(recv + 8);
  if (*(int32_t*)(iVar6 + 0xc0) < 1) {
    return;
  }
  bool bVar8 = false;
  bool bVar9 = *(int32_t*)(iVar6 + 0xc0) == 0;
  int32_t* piVar4 = nullptr;
  uint32_t* puVar3 = nullptr;
  uint32_t uVar5 = 0;
  void* puStack_4 = nullptr;
  void* puStack_10 = nullptr;

loop_check:
  if (!(bVar8 || bVar9 ||
        ((piVar4 = *(int32_t**)(*(int32_t*)(iVar6 + 0xb8) + local_8 * 4)), piVar4 == nullptr))) {
    goto body;
  }
step_next:
  iVar6 = *(int32_t*)(recv + 8);
  uVar5 = *(uint32_t*)(iVar6 + 0xc0);
  local_8 = local_8 + 1;
  bVar8 = uVar5 < local_8;
  bVar9 = uVar5 == local_8;
  if ((int32_t)uVar5 <= (int32_t)local_8) {
    return;
  }
  goto loop_check;

body:
  puVar3 = (uint32_t*)(*(uint32_t(**)(void))((uintptr_t)*piVar4 + 4))();
joined:
  if (puVar3 == nullptr) {
    goto step_next;
  }
  if (puVar3 != (uint32_t*)&DAT_00727598) {
    puVar3 = (uint32_t*)puVar3[1];
    goto joined;
  }
  for (puVar3 = (uint32_t*)(*(uint32_t(**)(void))((uintptr_t)*piVar4 + 4))();
       (puVar3 != nullptr && puVar3 != (uint32_t*)&DAT_00727598);
       puVar3 = (uint32_t*)puVar3[1]) {
  }
  piVar4 = (int32_t*)FUN_00533db0(8);
  if (piVar4 == nullptr) {
    uVar5 = 0;
  } else {
    uint8_t bVar2 = 0;
    for (puVar3 = (uint32_t*)(*(uint32_t(**)(void))((uintptr_t)*piVar4 + 4))();
         puVar3 != nullptr; puVar3 = (uint32_t*)puVar3[1]) {
      if (puVar3 == (uint32_t*)&DAT_007275e8) {
        bVar2 = 1;
        break;
      }
    }
    uVar5 = (-(uint32_t)bVar2) & (uint32_t)(uintptr_t)piVar4;
  }
  if (param_1 == nullptr) {
    puVar3 = *(uint32_t**)(*(int32_t*)(uVar5 + 0x2c) + 4);
    puStack_10 = param_1;
    if (puVar3 != nullptr) {
      (*(void(**)(int32_t))(uintptr_t)*puVar3)(1);
      FUN_005606f0(1, &puStack_10);
    }
    FUN_00542690(nullptr);
  } else {
    puStack_10 = (void*)(uintptr_t)(*(int32_t*)(*(int32_t*)(recv + 4) + 0x80) - 1);
    FUN_00513730(&puStack_4,
                 *(uint32_t*)(local_c + 0x24) /
                     (uint32_t)(*(int32_t*)(*(int32_t*)(recv + 4) + 0x7c) - 1),
                 *(uint32_t*)(recv + 0x28) / (uint32_t)(uintptr_t)puStack_10);
    if ((uVar5 != 0) &&
        ((iVar6 = *(int32_t*)(*(int32_t*)(uVar5 + 0x2c) + 4),
          iVar6 == 0 || (*(void**)(iVar6 + 4) != puStack_4)))) {
      uint32_t* puVar7;
      int32_t iVarAlloc = (int32_t)FUN_00533c78(0x1c);
      if (iVarAlloc == 0) {
        puVar7 = nullptr;
      } else {
        puVar7 = (uint32_t*)FUN_00542700(puStack_4, 1, 0, 5, 0);
      }
      uint32_t* puVar1 = *(uint32_t**)(*(int32_t*)(uVar5 + 0x2c) + 4);
      puStack_10 = puVar7;
      if (puVar7 != puVar1) {
        if (puVar1 != nullptr) {
          (*(void(**)(int32_t))(uintptr_t)*puVar1)(1);
        }
        FUN_005606f0(1, &puStack_10);
      }
      FUN_00542690(puVar7);
    }
    if (puStack_4 != nullptr) {
      uint32_t* pv = (uint32_t*)puStack_4;
      int32_t* ref = (int32_t*)(pv + 1);
      *ref = *ref - 1;
      if (*ref == 0) {
        (*(void(**)(int32_t))(uintptr_t)*pv)(1);
      }
    }
  }
  goto step_next;
}


// 0x51b2b0 — observed shape (allocates index/vertex buffers, runs registered mesh builders, frees them)
uint32_t FUN_0051b2b0(void* self, uint32_t in_EBX)
{
  uint32_t* r = (uint32_t*)self;
  uint32_t uVar5 = (uint32_t)(*(uint16_t*)(r + 5)) * (uint32_t)(*(uint16_t*)(r + 6));
  void* pvVar2 = (void*)(uintptr_t)((*(uint16_t*)(r + 5) - 1) * (*(uint16_t*)(r + 6) - 1) * 2);
  uint32_t uVar9 = uVar5;
  int32_t iVar3 = (*(int32_t(**)(uint32_t))((uintptr_t)*r + 0x40))(uVar5);
  uint32_t uStack_4; // stack slot read by vtable +0x30, never initialised in the listing

  if (iVar3 < 1) {
    return 8;
  }
  iVar3 = (int32_t)r[1];
  uint8_t bVar1;
  if ((*(char*)(iVar3 + 0xa4) == '\0') ||
      ((0.995 < *(float*)(iVar3 + 0x90) && *(float*)(iVar3 + 0x90) < 1.005) &&
       (0.995 < *(float*)(iVar3 + 0x94) && *(float*)(iVar3 + 0x94) < 1.005))) {
    bVar1 = 0;
  } else {
    bVar1 = 1;
  }
  uVar5 = uVar5 & 0xffff;
  void* pvVar4 = (void*)thunk_FUN_00533c78(uVar5 * 0xc);
  if (pvVar4 == nullptr) {
    pvVar4 = nullptr;
  } else {
    FUN_004127b0(pvVar4, 0xc, uVar5, &LAB_005cea70);
  }
  int32_t iVar6 = (int32_t)(uVar5 * (uint32_t)(bVar1 + 1));
  iVar3 = (int32_t)thunk_FUN_00533c78((uint32_t)iVar6 * 8);
  if (iVar3 != 0) {
    FUN_004127b0((void*)(uintptr_t)iVar3, 8, (uint32_t)iVar6, &LAB_005cea70);
  }
  iVar3 = (int32_t)thunk_FUN_00533c78(uVar5 * 0xc);
  if (iVar3 != 0) {
    FUN_004127b0((void*)(uintptr_t)iVar3, 0xc, uVar5, &LAB_005cea70);
  }
  void* pvVar8 = pvVar4;
  (*(void(**)(void))((uintptr_t)*r + 0x28))();
  (*(void(**)(void))((uintptr_t)*r + 0x2c))();
  (*(void(**)(uint32_t))((uintptr_t)*r + 0x30))(uStack_4);
  (*(void(**)(uint32_t, void*, uint32_t))((uintptr_t)*r + 0x34))(uVar9, pvVar4,
                                                                  (uint32_t)(bVar1 + 1));
  uint32_t uVar7 = 0;
  if (r[0x18] != 0) {
    do {
      uintptr_t slot = (uintptr_t)r[0x16] + (uintptr_t)uVar7 * 4;
      uintptr_t fnPtr = *(uintptr_t*)*(uintptr_t*)slot;
      iVar3 = (*(int32_t(**)(uint32_t, void*, void*, void*, uint32_t, uint32_t))fnPtr)(
          uVar5, pvVar4, pvVar8, pvVar2, in_EBX, uVar9);
      if (iVar3 != 0) {
        (*(void(**)(int32_t, int32_t))((uintptr_t)(*(uint32_t*)(uintptr_t)r[2]) + 0x70))(iVar3, 1);
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < r[0x18]);
  }
  *(uint32_t*)((uintptr_t)r[2] + 0xec) = 1;
  if (pvVar4 != nullptr) {
    operator_delete__(pvVar4);
  }
  if (pvVar2 != nullptr) {
    operator_delete__(pvVar2);
  }
  if (pvVar8 != nullptr) {
    operator_delete__(pvVar8);
  }
  return 0;
}


// 0x51b780 — observed shape (samples heightmap bytes into vertex positions; 3 floats per vertex)
void FUN_0051b780(void* self, uint8_t* param_1)
{
  uint8_t* r = (uint8_t*)self;
  uint32_t iVar10 = 0;
  uint32_t local_14 = 0;

  if (*(int32_t*)(r + 0x14) != 0) {
    uint32_t uVar7 = *(uint32_t*)(r + 0x18);
    do {
      uint32_t uVar11 = 0;
      if (uVar7 != 0) {
        float fVar4 = (float)local_14;
        float* pfVar9 = (float*)(param_1 + iVar10 * 0xc);
        do {
          int32_t iVar6 = *(int32_t*)(r + 0x24) + (int32_t)local_14;
          int32_t iVar8 = *(int32_t*)(r + 0x28) + (int32_t)uVar11;
          if (iVar6 < 0) {
            iVar6 = 0;
          } else {
            int32_t iVar12 = *(int32_t*)(r + 0x2c) - 1;
            if (iVar12 < iVar6) {
              iVar6 = iVar12;
            }
          }
          if (iVar8 < 0) {
            iVar8 = 0;
          } else {
            int32_t iVar12 = *(int32_t*)(r + 0x30) - 1;
            if (iVar12 < iVar8) {
              iVar8 = iVar12;
            }
          }
          float fVar5 = (float)uVar11;
          float fVar1 = *(float*)(r + 0x38);
          uint8_t bVar3 = *(uint8_t*)(uintptr_t)(
              *(int32_t*)(r + 0x2c) * iVar8 + iVar6 + *(int32_t*)(r + 0x40));
          iVar10 = iVar10 + 1;
          uVar11 = uVar11 + 1;
          float fVar2 = *(float*)(r + 0x3c);
          *pfVar9 = fVar4 * *(float*)(r + 0x34);
          pfVar9[1] = -(fVar5 * fVar1);
          pfVar9[2] = (float)bVar3 * fVar2;
          uVar7 = *(uint32_t*)(r + 0x18);
          pfVar9 = pfVar9 + 3;
        } while (uVar11 < uVar7);
      }
      local_14 = local_14 + 1;
    } while (local_14 < *(uint32_t*)(r + 0x14));
  }
}


// 0x51b880 — observed shape (emits two 2-float UV grids from the surface scale offsets)
void FUN_0051b880(void* self, uint8_t* param_1)
{
  uint8_t* r = (uint8_t*)self;
  uint8_t* piBase = (uint8_t*)(uintptr_t)*(uint32_t*)(r + 4);
  float fVar1 = *(float*)(piBase + 0x90);
  float fVar2 = *(float*)(piBase + 0x94);
  float fVar3 = *(float*)(piBase + 0x98);
  float fVar4 = *(float*)(piBase + 0x9c);
  int32_t iVar14 = 0;
  bool bVar9 = !((*(char*)(piBase + 0xa4) == '\0') ||
                 ((0.995 < *(float*)(piBase + 0x90) && *(float*)(piBase + 0x90) < 1.005) &&
                  (0.995 < *(float*)(piBase + 0x94) && *(float*)(piBase + 0x94) < 1.005)));
  uint32_t uVar12 = *(uint32_t*)(r + 0x18);
  uint32_t prod = (uint32_t)(*(int32_t*)(r + 0x14)) * uVar12;
  uint32_t local_20 = 0;

  if (*(int32_t*)(r + 0x14) != 0) {
    do {
      uint32_t uVar15 = 0;
      if (uVar12 != 0) {
        float fVar5 = (float)local_20;
        float* pfVar10 = (float*)(param_1 + (uint32_t)iVar14 * 8);
        float* pfVar16 = (float*)(param_1 + (prod + (uint32_t)iVar14) * 8);
        do {
          int32_t iVar11 = *(int32_t*)(r + 0x1c) - 1;
          float fVar6 = (float)(uint32_t)iVar11;
          float fVar7 = (float)uVar15;
          int32_t iVar11b = *(int32_t*)(r + 0x20) - 1;
          float fVar8 = (float)(uint32_t)iVar11b;
          *pfVar10 = (fVar5 / fVar6) * fVar1 + fVar3;
          pfVar10[1] = (fVar7 / fVar8) * fVar2 + fVar4;
          if (bVar9) {
            int32_t t1 = *(int32_t*)(r + 0x1c) - 1;
            float fa = (float)(uint32_t)t1;
            int32_t t2 = *(int32_t*)(r + 0x20) - 1;
            float fb = (float)(uint32_t)t2;
            *pfVar16 = fVar5 / fa + fVar3;
            pfVar16[1] = fVar7 / fb + fVar4;
          }
          uVar12 = *(uint32_t*)(r + 0x18);
          iVar14 = iVar14 + 1;
          pfVar10 = pfVar10 + 2;
          pfVar16 = pfVar16 + 2;
          uVar15 = uVar15 + 1;
        } while (uVar15 < uVar12);
      }
      local_20 = local_20 + 1;
    } while (local_20 < *(uint32_t*)(r + 0x14));
  }
}


// 0x51bc60 — observed shape (emits one quad per grid cell via vtable +0x38)
void FUN_0051bc60(void* self, uint32_t param_1)
{
  int32_t* r = (int32_t*)self;
  uint32_t uVar4 = 0;

  if (r[5] != 1) {
    uint32_t uVar1 = (uint32_t)(r[6] - 1);
    do {
      uint32_t uVar5 = 0;
      if (uVar1 != 0) {
        do {
          int32_t iVar2 = r[6] * (int32_t)uVar4 + (int32_t)uVar5;
          int32_t iVar3 = r[6] + iVar2;
          (*(void(**)(uint32_t, uint32_t, int32_t, int32_t, int32_t, int32_t, uint32_t))(
              (uintptr_t)*r + 0x38))(uVar4, uVar5, iVar2, iVar2 + 1, iVar3, iVar3 + 1, param_1);
          uVar5 = uVar5 + 1;
          uVar1 = (uint32_t)(r[6] - 1);
        } while (uVar5 < uVar1);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint32_t)(r[5] - 1));
  }
}


// 0x51bcc0 — observed shape (finds the record whose +0x38 byte matches, then rebuilds and re-registers)
void FUN_0051bcc0(void* self, uint32_t param_1, uint32_t param_2, char param_3, uint32_t param_4)
{
  uint8_t* r = (uint8_t*)self;
  uint32_t uVar2 = 0;

  if (*(uint32_t*)(r + 0x60) != 0) {
    int32_t* piVar1 = *(int32_t**)(r + 0x58);
    while (param_3 != *(char*)((uintptr_t)*piVar1 + 0x38)) {
      uVar2 = uVar2 + 1;
      piVar1 = piVar1 + 1;
      if (*(uint32_t*)(r + 0x60) <= uVar2) {
        return;
      }
    }
    (void)FUN_0050bf50((int)param_4);
    // in_EAX (index array) and in_ESI (float weights) arrive as caller register state
    FUN_0051c250(self);
  }
}


// 0x51be10 — observed shape (walks the global token list and re-syncs it against the object array)
void FUN_0051be10(void* self)
{
  uint8_t* r = (uint8_t*)self;
  uint32_t uVar4 = 0;
  int32_t* piVar2 = DAT_008cad3c;
  int32_t* piVar8;
  int32_t iVar5 = 0;

  if (DAT_008cad3c[1] != 0) {
    piVar8 = (int32_t*)(uintptr_t)DAT_008cad3c[2];
    do {
      if (*piVar8 != 0) {
        piVar8 = (int32_t*)((int32_t*)(uintptr_t)DAT_008cad3c[2])[uVar4];
        goto joined;
      }
      uVar4 = uVar4 + 1;
      piVar8 = piVar8 + 1;
    } while (uVar4 < (uint32_t)DAT_008cad3c[1]);
  }
  piVar8 = nullptr;
joined:
  for (;;) {
    if (piVar8 == nullptr) {
      DAT_008cad3c = piVar2;
      return;
    }
    int32_t* piVar9 = (int32_t*)*piVar8;
    int32_t iVar1 = piVar8[2];
    DAT_008cad3c = piVar2;
    if (piVar9 == nullptr) {
      int32_t iVar6 = (*(int32_t(**)(int32_t))((uintptr_t)*piVar2 + 4))(piVar8[1]);
      uint32_t uVar4b = (uint32_t)(iVar6 + 1);
      if (uVar4b < (uint32_t)piVar2[1]) {
        uint32_t* puVar6 = (uint32_t*)((uintptr_t)piVar2[2] + uVar4b * 4);
        do {
          piVar9 = (int32_t*)*puVar6;
          if (piVar9 != nullptr) goto lab90;
          uVar4b = uVar4b + 1;
          puVar6 = puVar6 + 1;
        } while (uVar4b < (uint32_t)piVar2[1]);
      }
      piVar9 = nullptr;
    }
lab90:
    iVar5 = *(int32_t*)(r + 8);
    uVar4 = 0;
    piVar8 = piVar9;
    piVar2 = DAT_008cad3c;
    if (*(int32_t*)(iVar5 + 0xc0) != 0) {
      break;
    }
  }
scan_loop:
  piVar2 = *(int32_t**)(*(int32_t*)(iVar5 + 0xb8) + uVar4 * 4);
  if (piVar2 != nullptr) {
    for (uint32_t* puVar6 = (uint32_t*)(*(uint32_t(**)(void))((uintptr_t)*piVar2 + 4))();
         puVar6 != nullptr; puVar6 = (uint32_t*)puVar6[1]) {
      if (puVar6 == (uint32_t*)&DAT_00727598) {
        uint32_t uVar3 = *(uint32_t*)(iVar1 + 0xc);
        uint32_t uVar7 = 0;
        if (uVar3 != 0) {
          int32_t* piVar9b = *(int32_t**)(*(int32_t*)(iVar1 + 4) + uVar4 * 4);
          do {
            if ((piVar9b != nullptr) && (piVar9b == piVar2)) {
              uint32_t uStack_4 = 0;
              FUN_00581300(uVar4, &uStack_4);
              break;
            }
          } while (uVar7 = uVar7 + 1, uVar7 < uVar3);
        }
        break;
      }
    }
  }
  iVar5 = *(int32_t*)(r + 8);
  uVar4 = uVar4 + 1;
  piVar2 = DAT_008cad3c;
  if (*(uint32_t*)(iVar5 + 0xc0) > uVar4) {
    goto scan_loop;
  }
  goto joined;
}


// 0x51bf30 — observed shape (constructs a small zero-filled object array; in_EAX carries the count)
void FUN_0051bf30(void* self_in_ESI, int32_t in_eax)
{
  uint32_t* r = (uint32_t*)self_in_ESI;

  r[1] = (uint32_t)in_eax;
  r[0] = (uint32_t)(uintptr_t)&PTR_FUN_007127f0;
  r[3] = 0;
  uint32_t* puVar1 = (uint32_t*)thunk_FUN_00533c78((uint32_t)(in_eax << 2));
  r[2] = (uint32_t)(uintptr_t)puVar1;
  for (uint32_t uVar2 = r[1] & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  for (int32_t iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(uint8_t*)puVar1 = 0;
    puVar1 = (uint32_t*)((uint8_t*)puVar1 + 1);
  }
  r[0] = (uint32_t)(uintptr_t)&PTR_FUN_007127d4;
}


// 0x51bf80 — observed shape (destroying delete of the two-vtable object, frees array at +8)
void FUN_0051bf80(void* self, uint8_t param_1)
{
  uint32_t* r = (uint32_t*)self;

  r[0] = (uint32_t)(uintptr_t)&PTR_FUN_007127d4;
  FUN_004e6420();
  r[0] = (uint32_t)(uintptr_t)&PTR_FUN_007127f0;
  FUN_004e6420();
  operator_delete__((void*)(uintptr_t)r[2]);
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}


// 0x51bfc0 — observed shape (walks a hash bucket and hands back the matched node's payload)
uint32_t FUN_0051bfc0(void* self_in_EDI, uint32_t* ret_param)
{
  uint32_t* r = (uint32_t*)self_in_EDI;
  int32_t iVar3 = (*(int32_t(**)(void))((uintptr_t)r[0] + 4))();
  uint32_t* puVar1 = *(uint32_t**)((uintptr_t)r[2] + (uint32_t)iVar3 * 4);

  for (;;) {
    if (puVar1 == nullptr) {
      return 0;
    }
    char cVar2 = (*(char(**)(void))((uintptr_t)r[0] + 8))();
    if (cVar2 != '\0') {
      break;
    }
    puVar1 = (uint32_t*)*puVar1;
  }
  *ret_param = puVar1[2];
  return 1;
}


// 0x51c000 — observed shape (destroying delete, frees array at +8)
void FUN_0051c000(void* self, uint8_t param_1)
{
  uint32_t* r = (uint32_t*)self;

  r[0] = (uint32_t)(uintptr_t)&PTR_FUN_007127f0;
  FUN_004e6420();
  operator_delete__((void*)(uintptr_t)r[2]);
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}


// 0x51c040 — observed shape (resizes the refcounted pointer array, releasing the tail)
void FUN_0051c040(void* self, uint32_t param_1)
{
  uint8_t* r = (uint8_t*)self;
  int32_t iVar2 = 0;

  if (param_1 != *(uint32_t*)(r + 8)) {
    if (param_1 < *(uint32_t*)(r + 0xc)) {
      uint32_t uVar7 = param_1;
      do {
        iVar2 = *(int32_t*)(r + 4);
        uint32_t* puVar3 = *(uint32_t**)((uintptr_t)iVar2 + uVar7 * 4);
        if (puVar3 != nullptr) {
          int32_t* ref = (int32_t*)(puVar3 + 1);
          *ref = *ref - 1;
          if (*ref == 0) {
            (*(void(**)(int32_t))(uintptr_t)*puVar3)(1);
          }
          *(uint32_t*)((uintptr_t)iVar2 + uVar7 * 4) = 0;
          *(int32_t*)(r + 0x10) = *(int32_t*)(r + 0x10) - 1;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < *(uint32_t*)(r + 0xc));
      *(uint32_t*)(r + 0xc) = param_1;
    }
    iVar2 = *(int32_t*)(r + 4);
    *(uint32_t*)(r + 8) = param_1;
    if (param_1 == 0) {
      *(uint32_t*)(r + 4) = 0;
    } else {
      uint32_t* puVar5 = (uint32_t*)thunk_FUN_00533c78(param_1 * 4 + 4);
      uint32_t* puVar8;
      if (puVar5 == nullptr) {
        puVar8 = nullptr;
      } else {
        puVar8 = puVar5 + 1;
        *puVar5 = param_1;
        FUN_004127b0(puVar8, 4, param_1, &LAB_004c2970);
      }
      uint32_t uVar7 = 0;
      *(uint32_t**)(r + 4) = puVar8;
      if (*(int32_t*)(r + 0xc) != 0) {
        do {
          int32_t iVar6 = *(int32_t*)(r + 4);
          int32_t iVar9 = (int32_t)(uVar7 * 4);
          uint32_t* puVar3 = *(uint32_t**)((uintptr_t)iVar6 + (uintptr_t)iVar9);
          if (puVar3 != *(uint32_t**)((uintptr_t)iVar9 + (uintptr_t)iVar2)) {
            if (puVar3 != nullptr) {
              int32_t* ref = (int32_t*)(puVar3 + 1);
              *ref = *ref - 1;
              if (*ref == 0) {
                (*(void(**)(int32_t))(uintptr_t)*puVar3)(1);
              }
            }
            int32_t iVar4 = *(int32_t*)((uintptr_t)iVar9 + (uintptr_t)iVar2);
            *(int32_t*)((uintptr_t)iVar6 + (uintptr_t)iVar9) = iVar4;
            if (iVar4 != 0) {
              *(int32_t*)(iVar4 + 4) = *(int32_t*)(iVar4 + 4) + 1;
            }
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < *(uint32_t*)(r + 0xc));
      }
      uint32_t uVar7b = *(uint32_t*)(r + 0xc);
      if (uVar7b < *(uint32_t*)(r + 8)) {
        do {
          int32_t iVar9 = *(int32_t*)(r + 4);
          uint32_t* puVar3 = *(uint32_t**)((uintptr_t)iVar9 + uVar7b * 4);
          if (puVar3 != nullptr) {
            int32_t* ref = (int32_t*)(puVar3 + 1);
            *ref = *ref - 1;
            if (*ref == 0) {
              (*(void(**)(int32_t))(uintptr_t)*puVar3)(1);
            }
            *(uint32_t*)((uintptr_t)iVar9 + uVar7b * 4) = 0;
          }
          uVar7b = uVar7b + 1;
        } while (uVar7b < *(uint32_t*)(r + 8));
      }
    }
    if (iVar2 != 0) {
      int32_t iVar6 = *(int32_t*)(iVar2 - 4);
      int32_t iVar9 = iVar2 + iVar6 * 4;
      if (-1 < iVar6 - 1) {
        do {
          uint32_t* puVar3 = *(uint32_t**)((uintptr_t)iVar9 - 4);
          iVar9 = iVar9 - 4;
          if (puVar3 != nullptr) {
            int32_t* ref = (int32_t*)(puVar3 + 1);
            *ref = *ref - 1;
            if (*ref == 0) {
              (*(void(**)(int32_t))(uintptr_t)*puVar3)(1);
            }
          }
          iVar6 = iVar6 - 1;
        } while (iVar6 != 0);
      }
      operator_delete__((void*)(uintptr_t)(iVar2 - 4));
    }
  }
}


// 0x51c1b0 — observed shape (destroying delete, frees owner at +4)
void FUN_0051c1b0(void* self, uint8_t param_1)
{
  uint32_t* r = (uint32_t*)self;

  r[0] = (uint32_t)(uintptr_t)&PTR_FUN_00712788;
  operator_delete__((void*)(uintptr_t)r[1]);
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}


// 0x51c200 — observed shape (runs the base teardown then releases the refcounted array at +4)
void FUN_0051c200(void* self)
{
  uint32_t* r = (uint32_t*)self;

  r[0] = (uint32_t)(uintptr_t)&PTR_FUN_00712780;
  int32_t iVar2 = (int32_t)r[1];
  if (iVar2 != 0) {
    int32_t iVar4 = *(int32_t*)(iVar2 - 4);
    int32_t iVar5 = iVar2 + iVar4 * 4;
    if (-1 < iVar4 - 1) {
      do {
        uint32_t* puVar3 = *(uint32_t**)((uintptr_t)iVar5 - 4);
        iVar5 = iVar5 - 4;
        if (puVar3 != nullptr) {
          int32_t* ref = (int32_t*)(puVar3 + 1);
          *ref = *ref - 1;
          if (*ref == 0) {
            (*(void(**)(int32_t))(uintptr_t)*puVar3)(1);
          }
        }
        iVar4 = iVar4 - 1;
      } while (iVar4 != 0);
    }
    operator_delete__((void*)(uintptr_t)(iVar2 - 4));
  }
}


// 0x51c250 — observed shape (registers 4 indices, then raises the per-vertex weights; in_EAX indexes, in_ESI weights)
void FUN_0051c250(void* self, uint16_t* in_eax, float* in_esi)
{
  uint8_t* r = (uint8_t*)self;
  uint16_t uVar3;
  uint32_t* puVar1;
  float* pfVar2;

  uVar3 = in_eax[0];
  puVar1 = (uint32_t*)(uintptr_t)(*(int32_t*)(r + 0xc) + (uint32_t)uVar3 * 4);
  if (*puVar1 == 0xffffffff) {
    *puVar1 = (uint32_t)*(uint16_t*)(r + 0x18);
    *(uint16_t*)(uintptr_t)(*(int32_t*)(r + 0x10) + (uint32_t)*(uint16_t*)(r + 0x18) * 2) = uVar3;
    *(int16_t*)(r + 0x18) = *(int16_t*)(r + 0x18) + 1;
    uVar3 = (uint16_t)(*(int16_t*)(r + 0x18) - 1);
  } else {
    uVar3 = (uint16_t)*puVar1;
  }
  pfVar2 = (float*)(uintptr_t)(*(int32_t*)(r + 0x34) + (uint32_t)uVar3 * 4);
  if (*pfVar2 < in_esi[0]) {
    *pfVar2 = in_esi[0];
  }

  uVar3 = in_eax[1];
  puVar1 = (uint32_t*)(uintptr_t)(*(int32_t*)(r + 0xc) + (uint32_t)uVar3 * 4);
  if (*puVar1 == 0xffffffff) {
    *puVar1 = (uint32_t)*(uint16_t*)(r + 0x18);
    *(uint16_t*)(uintptr_t)(*(int32_t*)(r + 0x10) + (uint32_t)*(uint16_t*)(r + 0x18) * 2) = uVar3;
    *(int16_t*)(r + 0x18) = *(int16_t*)(r + 0x18) + 1;
    uVar3 = (uint16_t)(*(int16_t*)(r + 0x18) - 1);
  } else {
    uVar3 = (uint16_t)*puVar1;
  }
  pfVar2 = (float*)(uintptr_t)(*(int32_t*)(r + 0x34) + (uint32_t)uVar3 * 4);
  if (*pfVar2 < in_esi[1]) {
    *pfVar2 = in_esi[1];
  }

  uVar3 = in_eax[2];
  puVar1 = (uint32_t*)(uintptr_t)(*(int32_t*)(r + 0xc) + (uint32_t)uVar3 * 4);
  if (*puVar1 == 0xffffffff) {
    *puVar1 = (uint32_t)*(uint16_t*)(r + 0x18);
    *(uint16_t*)(uintptr_t)(*(int32_t*)(r + 0x10) + (uint32_t)*(uint16_t*)(r + 0x18) * 2) = uVar3;
    *(int16_t*)(r + 0x18) = *(int16_t*)(r + 0x18) + 1;
    uVar3 = (uint16_t)(*(int16_t*)(r + 0x18) - 1);
  } else {
    uVar3 = (uint16_t)*puVar1;
  }
  pfVar2 = (float*)(uintptr_t)(*(int32_t*)(r + 0x34) + (uint32_t)uVar3 * 4);
  if (*pfVar2 < in_esi[2]) {
    *pfVar2 = in_esi[2];
  }

  uVar3 = in_eax[3];
  puVar1 = (uint32_t*)(uintptr_t)(*(int32_t*)(r + 0xc) + (uint32_t)uVar3 * 4);
  if (*puVar1 == 0xffffffff) {
    *puVar1 = (uint32_t)*(uint16_t*)(r + 0x18);
    *(uint16_t*)(uintptr_t)(*(int32_t*)(r + 0x10) + (uint32_t)*(uint16_t*)(r + 0x18) * 2) = uVar3;
    *(int16_t*)(r + 0x18) = *(int16_t*)(r + 0x18) + 1;
    uVar3 = (uint16_t)(*(int16_t*)(r + 0x18) - 1);
  } else {
    uVar3 = (uint16_t)*puVar1;
  }
  pfVar2 = (float*)(uintptr_t)(*(int32_t*)(r + 0x34) + (uint32_t)uVar3 * 4);
  if (*pfVar2 < in_esi[3]) {
    *pfVar2 = in_esi[3];
  }
}


// 0x51c390 — observed shape (destructor: resets vtable, releases +4, runs base teardown, optional free)
void FUN_0051c390(void* self, uint8_t param_1)
{
  uint32_t* r = (uint32_t*)self;

  r[0] = (uint32_t)(uintptr_t)&PTR_FUN_00712848;
  uint32_t* puVar2 = (uint32_t*)(uintptr_t)r[1];
  if (puVar2 != nullptr) {
    int32_t* ref = (int32_t*)(puVar2 + 1);
    *ref = *ref - 1;
    if (*ref == 0) {
      (*(void(**)(int32_t))(uintptr_t)*puVar2)(1);
    }
  }
  FUN_00555340(self);
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}


// 0x51c3d0 — observed shape (base teardown plus optional free)
void FUN_0051c3d0(void* self, uint8_t param_1)
{
  FUN_00555340(self);
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}


// 0x51c440 — observed shape (constructor: base init, stores the four dwords and the vtable)
void FUN_0051c440(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4,
                  void* self_in_EAX, uint32_t in_EBX, uint32_t in_EDI)
{
  uint32_t* r = (uint32_t*)self_in_EAX;

  FUN_0050be00(param_4);
  r[0x11] = param_2;
  r[0xb] = param_4;
  r[0] = (uint32_t)(uintptr_t)&PTR_FUN_0071289c;
  r[0xd] = param_3;
  r[0xe] = in_EBX;
  r[0xf] = in_EDI;
  r[0x10] = param_1;
  r[0xc] = 0;
}


// 0x51c490 — observed shape (uploads per-band vertex buffers, builds surface/material nodes, registers them)
uint32_t FUN_0051c490(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3,
                      uint32_t param_4, uint32_t param_5, int32_t param_6)
{
  uint8_t* r = (uint8_t*)self;
  uint8_t local_c[4] = {0, 0, 0, 0};
  uint8_t local_8;
  uint8_t bStack_7;
  uint16_t uStack_6;
  uint8_t uStack_4;

  FUN_0051cb70(self);
  FUN_0050c1d0(param_1, param_2, param_3, param_4, param_5, param_6);
  if (*(int16_t*)(r + 0x18) == 0) {
    return 0;
  }
  uint32_t uVar15 = *(uint32_t*)(*(int32_t*)(r + 0x40) + 0xc);
  int32_t* buffers = (int32_t*)thunk_FUN_00533c78(uVar15 * 4);
  param_5 = 0;
  if (uVar15 != 0) {
    uint32_t uVar5 = (uint32_t)*(uint16_t*)(r + 0x18);
    int32_t* piVar8 = buffers;
    do {
      int32_t iVar6 = (int32_t)thunk_FUN_00533c78(uVar5 << 4);
      *piVar8 = iVar6;
      iVar6 = *(int32_t*)(*(int32_t*)(*(int32_t*)(r + 0x40) + 4) + param_5 * 4);
      uint32_t uVar16 = 0;
      uVar5 = 0;
      if (*(int16_t*)(r + 0x18) != 0) {
        int32_t iVar17 = 0;
        do {
          uintptr_t idxAddr = (uintptr_t)(*(int32_t*)(r + 0x10) + (int32_t)(uVar16 * 2));
          uint32_t* puVar7 = (uint32_t*)(uintptr_t)(
              (uint32_t)*(uint16_t*)idxAddr * 0x10 + (uint32_t)iVar6);
          uint32_t* puVar18 = (uint32_t*)(uintptr_t)((uint32_t)*piVar8 + (uint32_t)iVar17);
          puVar18[0] = puVar7[0];
          puVar18[1] = puVar7[1];
          puVar18[2] = puVar7[2];
          puVar18[3] = puVar7[3];
          uVar5 = (uint32_t)*(uint16_t*)(r + 0x18);
          uVar16 = uVar16 + 1;
          iVar17 = iVar17 + 0x10;
        } while (uVar16 < uVar5);
      }
      param_5 = param_5 + 1;
      piVar8 = piVar8 + 1;
    } while (param_5 < uVar15);
  }
  int32_t* surface = (int32_t*)FUN_005c9680(uVar15);
  uint32_t uVar5b = 0;
  if (uVar15 != 0) {
    do {
      FUN_005c96f0(uVar5b, (void*)(uintptr_t)buffers[uVar5b],
                   (uint32_t)*(uint16_t*)(r + 0x18) << 4);
      uint32_t uVar16 = *(uint32_t*)(*(int32_t*)(r + 0x44) + 4);
      uint32_t uVar9 = 0;
      int32_t* piVar10 = nullptr;
      if (uVar16 != 0) {
        int32_t* base10 = *(int32_t**)(*(int32_t*)(r + 0x44) + 8);
        int32_t* piVar19 = base10;
        do {
          if (*piVar19 != 0) {
            piVar10 = (int32_t*)base10[uVar9];
            goto lab5d1;
          }
          uVar9 = uVar9 + 1;
          piVar19 = piVar19 + 1;
        } while (uVar9 < uVar16);
      }
      piVar10 = nullptr;
    lab5d1:
      {
        uint8_t bVar1 = 0;
        for (;;) {
          for (;;) {
            if (piVar10 == nullptr) goto lab64e;
            int32_t* piVar19b = *(int32_t**)(r + 0x44);
            int32_t* piVar11 = (int32_t*)*piVar10;
            local_8 = (uint8_t) * (uint16_t*)((uint8_t*)piVar10 + 6);
            uint8_t bVar3 = local_8;
            bStack_7 = (uint8_t)((uint16_t) * (uint16_t*)((uint8_t*)piVar10 + 6) >> 8);
            uStack_6 = 0;
            if (piVar11 == nullptr) {
              int32_t iVar6b = (*(int32_t(**)(int8_t))((uintptr_t)*piVar19b + 4))(
                  (int8_t)piVar10[1]);
              uint32_t uVar16b = (uint32_t)(iVar6b + 1);
              if (uVar16b < (uint32_t)piVar19b[1]) {
                uint32_t* puVar7b = (uint32_t*)((uintptr_t)piVar19b[2] + uVar16b * 4);
                do {
                  piVar11 = (int32_t*)*puVar7b;
                  if (piVar11 != nullptr) goto lab630;
                  uVar16b = uVar16b + 1;
                  puVar7b = puVar7b + 1;
                } while (uVar16b < (uint32_t)piVar19b[1]);
              }
              piVar11 = nullptr;
            }
          lab630:
            piVar10 = piVar11;
            if (bStack_7 == (uint8_t)uVar5b) break;
          }
          if (bVar1 < bVar3) {
            bVar1 = bVar3;
          }
          if (bVar1 == 3) break;
        }
      lab64e:
        switch (bVar1) {
        case 0:
          param_4 = 1;
          break;
        case 1:
          param_4 = 2;
          break;
        case 2:
          param_4 = 3;
          break;
        case 3:
          param_4 = 4;
          break;
        }
        uint32_t uVar12 = FUN_005c9560(uVar5b, local_c);
        (*(void(**)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t))(
            (uintptr_t)*surface + 0x34))(uVar5b, uVar12, param_4,
                                         (uint32_t)*(uint16_t*)(r + 0x18),
                                         (uint32_t)bVar1 * 4 + 4, 0x10);
      }
      uVar5b = uVar5b + 1;
    } while (uVar5b < uVar15);
  }
  uint32_t uVar5c = 0;
  if (uVar15 != 0) {
    do {
      if ((void*)(uintptr_t)buffers[uVar5c] != nullptr) {
        operator_delete__((void*)(uintptr_t)buffers[uVar5c]);
        buffers[uVar5c] = 0;
      }
      uVar5c = uVar5c + 1;
    } while (uVar5c < uVar15);
  }
  if (buffers != nullptr) {
    operator_delete__(buffers);
  }
  uint32_t* puVar7 = (uint32_t*)FUN_00533c78(8);
  if (puVar7 == nullptr) {
    puVar7 = nullptr;
  } else {
    *puVar7 = (uint32_t)(uintptr_t)&PTR_FUN_00712848;
    puVar7[1] = 0;
  }
  int32_t* piVar4 = (int32_t*)(uintptr_t)puVar7[1];
  if ((piVar4 != surface) && (piVar4 != surface)) {
    if (piVar4 != nullptr) {
      int32_t* ref = (int32_t*)(piVar4 + 1);
      *ref = *ref - 1;
      if (*ref == 0) {
        (*(void(**)(int32_t))(uintptr_t)*piVar4)(1);
      }
    }
    puVar7[1] = (uint32_t)(uintptr_t)surface;
    if (surface != nullptr) {
      surface[1] = surface[1] + 1;
    }
  }
  int32_t iVar6c = (int32_t)FUN_00533c78(0x24);
  uint32_t* puVar18 = nullptr;
  if (iVar6c == 0) {
    puVar18 = nullptr;
  } else {
    puVar18 = (uint32_t*)FUN_005553b0((void*)(uintptr_t)iVar6c);
  }
  uint32_t* puVar13 = (uint32_t*)(uintptr_t)puVar18[8];
  if (puVar7 != puVar13) {
    if (puVar13 != nullptr) {
      (*(void(**)(int32_t))(uintptr_t)*puVar13)(1);
    }
    puVar18[8] = (uint32_t)(uintptr_t)puVar7;
  }
  int32_t iVar6d = (int32_t)FUN_00533c78(0x2c);
  uint32_t* objA;
  if (iVar6d == 0) {
    objA = nullptr;
  } else {
    objA = (uint32_t*)(uintptr_t)iVar6d;
    FUN_00540c50();
    *objA = (uint32_t)(uintptr_t)&PTR_FUN_0070bf10;
    *(uint16_t*)(objA + 8) = 0;
    objA[9] = 0;
    objA[10] = 1;
  }
  objA[9] = 2;
  objA[10] = 1;
  if (DAT_008ea524 == nullptr) {
    int32_t iVar6e = (int32_t)FUN_00533c78(0x24);
    uint32_t* objB;
    if (iVar6e == 0) {
      objB = nullptr;
    } else {
      objB = (uint32_t*)(uintptr_t)iVar6e;
      FUN_00540c50();
      *objB = (uint32_t)(uintptr_t)&PTR_FUN_0070bf4c;
      *(uint16_t*)(objB + 8) = 0xec;
      *(uint8_t*)((uint8_t*)objB + 0x22) = 0;
    }
    uint32_t* prev = DAT_008ea524;
    if (DAT_008ea524 != objB) {
      if ((DAT_008ea524 != nullptr) &&
          (iVar6e = (int32_t)DAT_008ea524[1], DAT_008ea524[1] = (uint32_t)(iVar6e - 1),
           iVar6e - 1 == 0)) {
        (*(void(**)(int32_t))(uintptr_t)*prev)(1);
      }
      DAT_008ea524 = objB;
      if (objB != nullptr) {
        objB[1] = objB[1] + 1;
      }
    }
    *(uint8_t*)((uint8_t*)DAT_008ea524 + 0x21) = *(uint8_t*)((uint8_t*)DAT_008ea524 + 0x21) | 0x20;
  }
  {
    int32_t iVar6 = *(int32_t*)(r + 0x30);
    objA[1] = objA[1] + 1;
    uint32_t* node =
        (uint32_t*)(*(uint32_t(**)(void))((uintptr_t)(*(uint32_t*)(iVar6 + 0xa0)) + 4))();
    uint32_t* child = (uint32_t*)(uintptr_t)node[2];
    if (child != objA) {
      if (child != nullptr) {
        int32_t* ref = (int32_t*)(child + 1);
        *ref = *ref - 1;
        if (*ref == 0) {
          (*(void(**)(int32_t))(uintptr_t)*child)(1);
        }
      }
      node[2] = (uint32_t)(uintptr_t)objA;
      objA[1] = objA[1] + 1;
    }
    node[1] = 0;
    *node = *(uint32_t*)(iVar6 + 0xa4);
    if (*(int32_t*)(iVar6 + 0xa4) == 0) {
      *(uint32_t**)(iVar6 + 0xa8) = node;
    } else {
      *(uint32_t**)(*(int32_t*)(iVar6 + 0xa4) + 4) = node;
    }
    *(uint32_t**)(iVar6 + 0xa4) = node;
    *(int32_t*)(iVar6 + 0xac) = *(int32_t*)(iVar6 + 0xac) + 1;
    int32_t* ref = (int32_t*)(objA + 1);
    *ref = *ref - 1;
    if (*ref == 0) {
      (*(void(**)(int32_t))(uintptr_t)*objA)(1);
    }
  }
  {
    int32_t iVar6 = (int32_t)FUN_00533c78(0x48);
    uint32_t* objC;
    if (iVar6 == 0) {
      objC = nullptr;
    } else {
      objC = (uint32_t*)FUN_005428c0();
    }
    iVar6 = *(int32_t*)(r + 0x30);
    if (objC != nullptr) {
      objC[1] = objC[1] + 1;
    }
    uint32_t* node =
        (uint32_t*)(*(uint32_t(**)(void))((uintptr_t)(*(uint32_t*)(iVar6 + 0xa0)) + 4))();
    uint32_t* child = (uint32_t*)(uintptr_t)node[2];
    if (child != objC) {
      if (child != nullptr) {
        int32_t* ref = (int32_t*)(child + 1);
        *ref = *ref - 1;
        if (*ref == 0) {
          (*(void(**)(int32_t))(uintptr_t)*child)(1);
        }
      }
      node[2] = (uint32_t)(uintptr_t)objC;
      if (objC != nullptr) {
        objC[1] = objC[1] + 1;
      }
    }
    node[1] = 0;
    *node = *(uint32_t*)(iVar6 + 0xa4);
    if (*(int32_t*)(iVar6 + 0xa4) == 0) {
      *(uint32_t**)(iVar6 + 0xa8) = node;
    } else {
      *(uint32_t**)(*(int32_t*)(iVar6 + 0xa4) + 4) = node;
    }
    *(uint32_t**)(iVar6 + 0xa4) = node;
    *(int32_t*)(iVar6 + 0xac) = *(int32_t*)(iVar6 + 0xac) + 1;
    if (objC != nullptr) {
      int32_t* ref = (int32_t*)(objC + 1);
      *ref = *ref - 1;
      if (*ref == 0) {
        (*(void(**)(int32_t))(uintptr_t)*objC)(1);
      }
    }
  }
  {
    int32_t iVar6 = *(int32_t*)(r + 0x30);
    puVar18[1] = puVar18[1] + 1;
    uint32_t* node =
        (uint32_t*)(*(uint32_t(**)(void))((uintptr_t)(*(uint32_t*)(iVar6 + 0xa0)) + 4))();
    uint32_t* child = (uint32_t*)(uintptr_t)node[2];
    if (child != puVar18) {
      if (child != nullptr) {
        int32_t* ref = (int32_t*)(child + 1);
        *ref = *ref - 1;
        if (*ref == 0) {
          (*(void(**)(int32_t))(uintptr_t)*child)(1);
        }
      }
      node[2] = (uint32_t)(uintptr_t)puVar18;
      puVar18[1] = puVar18[1] + 1;
    }
    node[1] = 0;
    *node = *(uint32_t*)(iVar6 + 0xa4);
    if (*(int32_t*)(iVar6 + 0xa4) == 0) {
      *(uint32_t**)(iVar6 + 0xa8) = node;
    } else {
      *(uint32_t**)(*(int32_t*)(iVar6 + 0xa4) + 4) = node;
    }
    *(uint32_t**)(iVar6 + 0xa4) = node;
    *(int32_t*)(iVar6 + 0xac) = *(int32_t*)(iVar6 + 0xac) + 1;
    int32_t* ref = (int32_t*)(puVar18 + 1);
    *ref = *ref - 1;
    if (*ref == 0) {
      (*(void(**)(int32_t))(uintptr_t)*puVar18)(1);
    }
  }
  {
    uint32_t* objD = DAT_008ea524;
    int32_t iVar6 = *(int32_t*)(r + 0x30);
    if (DAT_008ea524 != nullptr) {
      DAT_008ea524[1] = DAT_008ea524[1] + 1;
    }
    uint32_t* node =
        (uint32_t*)(*(uint32_t(**)(void))((uintptr_t)(*(uint32_t*)(iVar6 + 0xa0)) + 4))();
    uint32_t* child = (uint32_t*)(uintptr_t)node[2];
    if (child != objD) {
      if (child != nullptr) {
        int32_t* ref = (int32_t*)(child + 1);
        *ref = *ref - 1;
        if (*ref == 0) {
          (*(void(**)(int32_t))(uintptr_t)*child)(1);
        }
      }
      node[2] = (uint32_t)(uintptr_t)objD;
      if (objD != nullptr) {
        objD[1] = objD[1] + 1;
      }
    }
    node[1] = 0;
    *node = *(uint32_t*)(iVar6 + 0xa4);
    if (*(int32_t*)(iVar6 + 0xa4) == 0) {
      *(uint32_t**)(iVar6 + 0xa8) = node;
    } else {
      *(uint32_t**)(*(int32_t*)(iVar6 + 0xa4) + 4) = node;
    }
    *(uint32_t**)(iVar6 + 0xa4) = node;
    *(int32_t*)(iVar6 + 0xac) = *(int32_t*)(iVar6 + 0xac) + 1;
    if (objD != nullptr) {
      int32_t* ref = (int32_t*)(objD + 1);
      *ref = *ref - 1;
      if (*ref == 0) {
        (*(void(**)(int32_t))(uintptr_t)*objD)(1);
      }
    }
  }
  uint32_t uVar15b = *(uint32_t*)(*(int32_t*)(r + 0x44) + 4);
  int32_t* piVar4b = nullptr;
  {
    uint32_t uVar5d = 0;
    if (uVar15b != 0) {
      int32_t* base10 = *(int32_t**)(*(int32_t*)(r + 0x44) + 8);
      int32_t* piVar8b = base10;
      do {
        if (*piVar8b != 0) {
          piVar4b = (int32_t*)base10[uVar5d];
          goto lab_ca34;
        }
        uVar5d = uVar5d + 1;
        piVar8b = piVar8b + 1;
      } while (uVar5d < uVar15b);
    }
    piVar4b = nullptr;
  }
lab_ca34:
  {
    int32_t* piVar8c = (int32_t*)FUN_00533db0(8);
    if (piVar8c != nullptr) {
      for (uint32_t* puVar7b = (uint32_t*)(*(uint32_t(**)(void))((uintptr_t)*piVar8c + 4))();
           (puVar7b != nullptr && puVar7b != (uint32_t*)&DAT_007275e8);
           puVar7b = (uint32_t*)puVar7b[1]) {
      }
    }
  }
  for (;;) {
    if (piVar4b == nullptr) {
      FUN_00534130();
      return *(uint32_t*)(r + 0x30);
    }
    uint8_t bVar1 = *(uint8_t*)((uint8_t*)piVar4b + 4);
    int32_t* piVar8d = *(int32_t**)(r + 0x44);
    uint16_t uVar2 = *(uint16_t*)((uint8_t*)piVar4b + 6);
    piVar4b = (int32_t*)*piVar4b;
    local_8 = (uint8_t)uVar2;
    bStack_7 = (uint8_t)(uVar2 >> 8);
    uStack_6 = 0;
    if (piVar4b == nullptr) {
      int32_t iVar6 = (*(int32_t(**)(uint8_t))((uintptr_t)*piVar8d + 4))(bVar1);
      uint32_t uVar15c = (uint32_t)(iVar6 + 1);
      if (uVar15c < (uint32_t)piVar8d[1]) {
        uint32_t* puVar7c = (uint32_t*)((uintptr_t)piVar8d[2] + uVar15c * 4);
        do {
          piVar4b = (int32_t*)*puVar7c;
          if (piVar4b != nullptr) goto lab_cac8;
          uVar15c = uVar15c + 1;
          puVar7c = puVar7c + 1;
        } while (uVar15c < (uint32_t)piVar8d[1]);
      }
      piVar4b = nullptr;
    }
  lab_cac8:
    {
      uint32_t packed = (uint32_t)bStack_7 | ((uint32_t)uStack_6 << 8) | ((uint32_t)uStack_4 << 24);
      uint8_t bVar3 =
          (*(uint8_t(**)(uint16_t, uint32_t))((uintptr_t)(*DAT_008cad54) + 0x14))(uVar2, packed);
      uint32_t* objE = (uint32_t*)FUN_00533c78(0x20);
      if (objE == nullptr) {
        objE = nullptr;
      } else {
        int32_t A = *(int32_t*)(param_6 + (uint32_t)bVar1 * 4);
        int32_t* pD = *(int32_t**)(uintptr_t)(A + 0x2c);
        int32_t D = *pD;
        uint32_t uVar12 = (D == 0) ? 0 : *(uint32_t*)(D + 4);
        FUN_00542700((void*)(uintptr_t)uVar12, 0, 3, 0, 0);
        *objE = (uint32_t)(uintptr_t)&PTR_FUN_0070d038;
        objE[7] = (uint32_t)bVar3;
      }
      FUN_00542cb0((uint32_t)bVar3, objE);
    }
  }
}
