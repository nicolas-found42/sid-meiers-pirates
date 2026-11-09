#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <windows.h>

// Extern helpers referenced by the observed listings.
extern int FUN_00563bd0(int* param_1, uint32_t param_4, int* param_5);
extern int FUN_00563300(uint32_t param_3, int* param_5);
extern void* thunk_FUN_00533c78(uint32_t size);
extern int FUN_00563440(int* param_5, void* p1, uint32_t param_4, void* pvVar3, int flag);
extern void operator_delete__(void* p);
extern void operator_delete(void* p);
extern int FUN_005631f0(uint16_t count, int param_2);
extern char FUN_005635e0(int param_1, uint32_t param_3, uint32_t param_4, int iVar3);
extern void FUN_004127b0(void* dst, uint32_t elemSize, int count, void* init);
extern void FUN_00562b10(uint32_t idx, void* p, uint16_t v);
extern void FUN_00562b70(void* out, uint32_t* entry, int param_1, int iVar3, uint32_t flag, uint32_t param_5, uint32_t param_4, uint32_t v44);
extern void FUN_00551770(void);
extern int FUN_00551a00(int param_1);
extern int FUN_00557b10(uint32_t param_1);
extern void FUN_00567520(void);
extern void FUN_00567540(void);
extern void FUN_006b34a0(int v);
extern void FUN_005606f0(uint32_t uVar1, void* p);
extern void FUN_00536a60(int addr, float* out);
extern uint32_t FUN_005480d0(int addr);
extern void FUN_00565970(void);
extern void FUN_00548600(int addr);
extern void FUN_005579c0(uint8_t* out);
extern void FUN_00548720(int addr, uint8_t* src);
extern void thunk_FUN_00538630(int p);
extern void FUN_0059ab10(int p);
extern void thunk_FUN_00538430(int p);
extern void FUN_0059ab40(int p);
extern uint32_t FUN_00557e10(void);
extern int FUN_00564350(void* self, int n);

extern void* PTR_FUN_006c3528;
extern void* PTR_FUN_006c35b0;
extern void* PTR_FUN_006c3620;
extern uint32_t DAT_00727d80;
extern uint32_t DAT_00727430;
extern uint32_t DAT_00727434;
extern uint32_t DAT_00727438;
extern void LAB_00562150;

// 0x563dc0 — filter/compact list with virtual-object callback at +0x48, sentinel -1, and zero-flag swap-remove
void FUN_00563dc0(void* self, int* param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, int* param_5, int** param_6) {
  uint32_t uVar1 = (uint32_t)*(uint16_t*)((char*)param_1 + 0xf);
  FUN_00563bd0(param_1, param_4, param_5);
  FUN_00563300(param_3, param_5);
  int iVar2 = (int)(intptr_t)thunk_FUN_00533c78(uVar1 * 4);
  *param_6 = (int*)iVar2;
  void* pvVar3 = thunk_FUN_00533c78((uint32_t)param_5[2]);
  uint32_t uVar4 = 0;
  if (param_5[2] != 0) {
    do {
      *(uint8_t*)((char*)pvVar3 + uVar4) = 0;
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint32_t)param_5[2]);
  }
  uVar4 = 0;
  if (uVar1 != 0) {
    do {
      short local_8 = 0;
      uint8_t local_6[2] = {0,0};
      short local_4[2] = {0,0};
      auto vtab = *(void***)param_1;
      auto cb = (void(*)(uint32_t, short*, uint8_t*, short*))vtab[0x48/4];
      cb(uVar4, &local_8, local_6, local_4);
      short s_local_6 = *(short*)local_6;
      if ((local_8 == s_local_6) || (s_local_6 == local_4[0]) || (local_4[0] == local_8)) {
        *(uint32_t*)((char*)*param_6 + uVar4 * 4) = 0xffffffffu;
      } else {
        iVar2 = FUN_00563440(param_5, &local_8, param_4, pvVar3, 1);
        if (iVar2 < 0) {
          iVar2 = FUN_00563440(param_5, &local_8, param_4, pvVar3, 0);
        }
        *(int*)((char*)*param_6 + uVar4 * 4) = iVar2;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  uVar4 = 0;
  if (param_5[2] != 0) {
    do {
      if (*(char*)((char*)pvVar3 + uVar4) == '\0') {
        iVar2 = param_5[2];
        param_5[2] = iVar2 + -1;
        *(uint32_t*)((char*)*param_5 + uVar4 * 4) = *(uint32_t*)((char*)*param_5 + (iVar2 + -1) * 4);
        iVar2 = param_5[2];
        uint32_t uVar5 = 0;
        if (uVar1 != 0) {
          do {
            if (*(int*)((char*)*param_6 + uVar5 * 4) == iVar2) {
              *(uint32_t*)((char*)*param_6 + uVar5 * 4) = uVar4;
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 < uVar1);
        }
      } else {
        uVar4 = uVar4 + 1;
      }
    } while (uVar4 < (uint32_t)param_5[2]);
  }
  *(int*)((char*)self + 0xc) = param_5[2];
  operator_delete__(pvVar3);
}

// 0x563f50 — orchestrates filter, allocates 0x2c-sized table, iterates entries via FUN_00562b10/FUN_00562b70, frees array
char FUN_00563f50(void* self, int param_1, int param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5) {
  int* local_c_ptr = nullptr;
  void* local_20 = nullptr;
  uint32_t local_1c = 0;
  void* local_18 = nullptr;
  uint32_t local_14 = 0;
  uint32_t local_10 = 0;
  int iVar3 = FUN_005631f0(*(uint16_t*)((char*)param_1 + 0xc), param_2);
  char cVar2 = FUN_005635e0(param_1, param_3, param_4, iVar3);
  if (cVar2 != '\0') {
    int local_c_storage[3] = {0,0,0};
    FUN_00563dc0(self, (int*)param_1, 0, param_3, (uint32_t)iVar3, local_c_storage, (int**)&local_20);
    local_c_ptr = (int*)*(intptr_t*)local_c_storage; // not used further except free (observed local_c is ptr)
    // Preserve observed shape: first dword of local_c_storage is the array ptr passed as &local_c equivalent.
    // Re-derive for cleanup consistency:
    // local_c corresponds to local_c_storage[0]
    int iVar4 = *(int*)((char*)self + 0xc);
    int* local_28 = (int*)thunk_FUN_00533c78((uint32_t)(iVar4 * 0x2c + 4));
    if (local_28 == nullptr) {
      local_28 = nullptr;
    } else {
      *local_28 = iVar4;
      local_28 = local_28 + 1;
      FUN_004127b0(local_28, 0x2c, iVar4, &LAB_00562150);
    }
    local_1c = ((uint8_t)param_3 == (uint8_t)param_4) ? 0 : 1;
    local_18 = nullptr;
    local_14 = 0;
    local_10 = 0;
    if (*(int*)((char*)self + 0xc) != 0) {
      uint32_t uVar5 = 0;
      do {
        FUN_00562b10(uVar5, local_20, *(uint16_t*)((char*)param_1 + 0x3c));
        uint32_t* puVar1 = *(uint32_t**)((char*)local_c_storage + uVar5 * 4);
        FUN_00562b70(&local_18, puVar1, param_1, iVar3, local_1c, param_5, param_4, *(uint32_t*)((char*)param_2 + 0x44));
        local_10 = 0;
        if (puVar1 != nullptr) {
          operator_delete__((void*)*puVar1);
          operator_delete(puVar1);
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint32_t*)((char*)self + 0xc));
    }
    operator_delete__(local_20);
    *(int**)((char*)self + 0x10) = local_28;
    operator_delete__(local_18);
  }
  if (iVar3 != 0) {
    int iVar6 = *(int*)((char*)iVar3 + -4);
    int iVar4 = iVar3 + iVar6 * 0xc;
    if (-1 < iVar6 + -1) {
      do {
        uint32_t* puVar1 = (uint32_t*)(iVar4 + -0xc);
        iVar4 = iVar4 + -0xc;
        operator_delete__((void*)*puVar1);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    operator_delete__((void*)(iVar3 + -4));
  }
  // local_c freed: observed operator_delete__(local_c) where local_c was passed to FUN_00563dc0
  operator_delete__(local_c_ptr);
  return cVar2;
}

// 0x564200 — destructor: sets vtable ptr, calls FUN_00551770, conditional operator_delete on flag bit 1
void FUN_00564200(void* self, uint8_t param_1) {
  uint32_t* self32 = (uint32_t*)self;
  *self32 = (uint32_t)(intptr_t)&PTR_FUN_006c3528;
  FUN_00551770();
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x564230 — calls FUN_00551a00, FUN_00557b10(DAT_00727d80), bounds-check push via FUN_006b34a0/FUN_005606f0
void FUN_00564230(void* self, int param_1) {
  int iVar2 = param_1;
  FUN_00551a00(param_1);
  param_1 = FUN_00557b10(DAT_00727d80);
  uint32_t uVar1 = *(uint32_t*)((char*)iVar2 + 0xc);
  if (*(uint32_t*)((char*)iVar2 + 8) <= uVar1) {
    FUN_006b34a0(*(int*)((char*)iVar2 + 0x14) + (int)uVar1);
  }
  FUN_005606f0(uVar1, &param_1);
}

// 0x5642b0 — constructor: calls FUN_00567520, sets vtable, copies DAT_00727430..38 triple twice, zeroes counts
void FUN_005642b0(void* self) {
  FUN_00567520();
  uint32_t* in_ECX = (uint32_t*)self;
  *in_ECX = (uint32_t)(intptr_t)&PTR_FUN_006c35b0;
  in_ECX[3] = DAT_00727430;
  in_ECX[4] = DAT_00727434;
  in_ECX[5] = DAT_00727438;
  in_ECX[6] = 0;
  in_ECX[7] = DAT_00727430;
  in_ECX[8] = DAT_00727434;
  in_ECX[9] = DAT_00727438;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
}

// 0x564310 — destructor: sets vtable, frees in_ECX[0xc], calls FUN_00567540, conditional delete on flag bit 1
void FUN_00564310(void* self, uint8_t param_1) {
  uint32_t* in_ECX = (uint32_t*)self;
  *in_ECX = (uint32_t)(intptr_t)&PTR_FUN_006c35b0;
  operator_delete__((void*)(intptr_t)in_ECX[0xc]);
  FUN_00567540();
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x564350 — resize float array at +0x2c/+0x30: realloc param_1*4, copy min(old,new) entries, free old
void FUN_00564350(void* self, int param_1) {
  int in_ECX = (int)(intptr_t)self;
  if (param_1 != *(int*)(in_ECX + 0x2c)) {
    if (param_1 == 0) {
      operator_delete__(*(void**)(in_ECX + 0x30));
      *(uint32_t*)(in_ECX + 0x30) = 0;
      *(uint32_t*)(in_ECX + 0x2c) = 0;
      return;
    }
    uint32_t* puVar1 = (uint32_t*)thunk_FUN_00533c78((uint32_t)(param_1 * 4));
    if (*(uint32_t**)(in_ECX + 0x30) != nullptr) {
      int iVar2 = *(int*)(in_ECX + 0x2c);
      if (param_1 <= *(int*)(in_ECX + 0x2c)) {
        iVar2 = param_1;
      }
      uint32_t* puVar3 = *(uint32_t**)(in_ECX + 0x30);
      uint32_t* puVar4 = puVar1;
      for (; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
    }
    operator_delete__(*(void**)(in_ECX + 0x30));
    *(uint32_t**)(in_ECX + 0x30) = puVar1;
    *(int*)(in_ECX + 0x2c) = param_1;
  }
}

// 0x5643d0 — lower_bound over float array at +0x2c using * (in_ECX+0x1c) clamp and *(param_1+0x1f0) scale
uint32_t FUN_005643d0(void* self, int param_1) {
  int in_ECX = (int)(intptr_t)self;
  float local_8 = 0, local_4 = 0;
  FUN_00536a60(in_ECX + 0x1c, &local_8);
  if (local_8 <= local_4) {
    local_8 = local_4;
  }
  uint32_t uVar1 = 0;
  if (*(uint32_t*)(in_ECX + 0x2c) != 0) {
    float* pfVar2 = *(float**)(in_ECX + 0x30);
    do {
      if (*pfVar2 <= local_8 * *(float*)(param_1 + 0x1f0)) {
        return uVar1;
      }
      uVar1 = uVar1 + 1;
      pfVar2 = pfVar2 + 1;
    } while (uVar1 < *(uint32_t*)(in_ECX + 0x2c));
  }
  return uVar1;
}

// 0x564460 — equality over float arrays with NaN-aware CONCAT return; checks FUN_005480d0 gates at +0xc/+0x1c
uint32_t FUN_00564460(void* self, int param_1) {
  int in_ECX = (int)(intptr_t)self;
  uint32_t uVar4 = FUN_005480d0(param_1 + 0xc);
  if ((char)uVar4 != '\0') {
    uVar4 = FUN_005480d0(param_1 + 0x1c);
    if ((char)uVar4 != '\0') {
      uint32_t uVar3 = *(uint32_t*)(param_1 + 0x2c);
      uint32_t uVar4b = *(uint32_t*)(in_ECX + 0x2c);
      if (uVar4b != uVar3) {
        return uVar3 & 0xffffff00u;
      }
      uint32_t uVar6 = 0;
      if (uVar4b != 0) {
        float* pfVar5 = *(float**)(in_ECX + 0x30);
        int iVar7 = *(int*)(param_1 + 0x30) - (int)(intptr_t)pfVar5;
        do {
          float fVar1 = *pfVar5;
          float fVar2 = *(float*)(iVar7 + (int)(intptr_t)pfVar5);
          uint32_t cmp = 0;
          bool is_nan = (isnan(fVar2) || isnan(fVar1));
          uint16_t lowbits = (uint16_t)((fVar2 < fVar1) ? (1<<8) : 0) | (uint16_t)((is_nan) ? (1<<10) : 0) | (uint16_t)((fVar2 == fVar1) ? (1<<14) : 0);
          uVar4 = ((uVar4 >> 0x10) << 16) | lowbits;
          if (fVar2 != fVar1) goto LAB_6449a;
          uVar6 = uVar6 + 1;
          pfVar5 = pfVar5 + 1;
        } while (uVar6 < uVar4b);
      }
      return (uVar4 & 0xffffff00u) | 1u;
    LAB_6449a:
      return uVar3 & 0xffffff00u;
    }
  }
  return uVar4 & 0xffffff00u;
}

// 0x5644d0 — clone: alloc 0x34, construct via FUN_005642b0, copy 4 dwords at +0xc, resize+copy float array
int FUN_005644d0(void* self) {
  int in_ECX = (int)(intptr_t)self;
  int iVar1 = (int)(intptr_t)thunk_FUN_00533c78(0x34);
  int saved = iVar1;
  if (iVar1 == 0) {
    iVar1 = 0;
  } else {
    iVar1 = FUN_005642b0(saved ? (void*)(intptr_t)saved : nullptr);
    if (iVar1 == 0) iVar1 = saved;
  }
  *(uint32_t*)(iVar1 + 0xc) = *(uint32_t*)(in_ECX + 0xc);
  *(uint32_t*)(iVar1 + 0x10) = *(uint32_t*)(in_ECX + 0x10);
  *(uint32_t*)(iVar1 + 0x14) = *(uint32_t*)(in_ECX + 0x14);
  *(uint32_t*)(iVar1 + 0x18) = *(uint32_t*)(in_ECX + 0x18);
  FUN_00564350((void*)(intptr_t)iVar1, *(uint32_t*)(in_ECX + 0x2c));
  uint32_t* puVar4 = *(uint32_t**)(in_ECX + 0x30);
  uint32_t* puVar5 = *(uint32_t**)(iVar1 + 0x30);
  for (uint32_t uVar2 = *(uint32_t*)(in_ECX + 0x2c) & 0x3fffffffu; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  return iVar1;
}

// 0x564540 — calls FUN_00565970, zeroes +0x28, iterates param_1 list at +0xb8/+0xc0 via FUN_00548600, then FUN_005579c0/FUN_00548720
void FUN_00564540(void* self, int param_1) {
  int in_ECX = (int)(intptr_t)self;
  uint8_t local_34[52];
  FUN_00565970();
  *(uint32_t*)(in_ECX + 0x28) = 0;
  uint32_t uVar3 = 0;
  if (0 < *(int*)(param_1 + 0xc0)) {
    // Ghidra loop-condition flags: bVar4=(uVar2<uVar3), bVar5=(uVar2==uVar3)
    do {
      uint32_t uVar2 = *(uint32_t*)(param_1 + 0xc0);
      bool bVar4 = uVar2 < uVar3;
      bool bVar5 = uVar2 == uVar3;
      if (!bVar4 && !bVar5) {
        int iVar1 = *(int*)(*(int*)(param_1 + 0xb8) + uVar3 * 4);
        if (iVar1 != 0) {
          FUN_00548600(iVar1 + 0x28);
        }
      }
      uVar2 = *(uint32_t*)(param_1 + 0xc0);
      uVar3 = uVar3 + 1;
      bVar4 = uVar2 < uVar3;
      bVar5 = uVar2 == uVar3;
      if (!(!bVar5 && (int)uVar3 <= (int)uVar2)) break;
    } while (1);
  }
  FUN_005579c0(local_34);
  FUN_00548720(in_ECX + 0x1c, local_34);
}

// 0x5645c0 — clone (same shape as 0x5644d0): alloc 0x34, construct, copy +0xc..+0x18, resize+copy float array
int FUN_005645c0(void* self) {
  int in_ECX = (int)(intptr_t)self;
  int iVar1 = (int)(intptr_t)thunk_FUN_00533c78(0x34);
  if (iVar1 == 0) {
    iVar1 = 0;
  } else {
    iVar1 = FUN_005642b0((void*)(intptr_t)iVar1);
  }
  *(uint32_t*)(iVar1 + 0xc) = *(uint32_t*)(in_ECX + 0xc);
  *(uint32_t*)(iVar1 + 0x10) = *(uint32_t*)(in_ECX + 0x10);
  *(uint32_t*)(iVar1 + 0x14) = *(uint32_t*)(in_ECX + 0x14);
  *(uint32_t*)(iVar1 + 0x18) = *(uint32_t*)(in_ECX + 0x18);
  FUN_00564350((void*)(intptr_t)iVar1, *(uint32_t*)(in_ECX + 0x2c));
  uint32_t* puVar4 = *(uint32_t**)(in_ECX + 0x30);
  uint32_t* puVar5 = *(uint32_t**)(iVar1 + 0x30);
  for (uint32_t uVar2 = *(uint32_t*)(in_ECX + 0x2c) & 0x3fffffffu; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  for (int iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(uint8_t*)puVar5 = *(uint8_t*)puVar4;
    puVar4 = (uint32_t*)((int)(intptr_t)puVar4 + 1);
    puVar5 = (uint32_t*)((int)(intptr_t)puVar5 + 1);
  }
  return iVar1;
}

// 0x564630 — serialize: thunk_FUN_00538630, double FUN_0059ab10, vtable write at +0x15c, resize via FUN_00564350, per-entry write
void FUN_00564630(void* self, int param_1) {
  int in_ECX = (int)(intptr_t)self;
  (void)in_ECX;
  int iVar1 = param_1;
  thunk_FUN_00538630(param_1);
  FUN_0059ab10(iVar1);
  FUN_0059ab10(iVar1);
  {
    void** obj = *(void***)(iVar1 + 0x15c);
    auto fn = (void(*)(void*, int))obj[1]; // +8
    int tmp = param_1;
    fn(&tmp, 4);
  }
  uint32_t unaff_EBX = *(uint32_t*)(in_ECX + 0x2c);
  FUN_00564350(self, unaff_EBX);
  uint32_t uVar2 = 0;
  if (unaff_EBX != 0) {
    do {
      void** obj = *(void***)(iVar1 + 0x15c);
      auto fn = (void(*)(void*, int))obj[1];
      fn((void*)(*(int*)(in_ECX + 0x30) + uVar2 * 4), 4);
      uVar2 = uVar2 + 1;
    } while (uVar2 < unaff_EBX);
  }
}

// 0x5646b0 — deserialize: thunk_FUN_00538430, double FUN_0059ab40, vtable read at +0x160, per-entry read
void FUN_005646b0(void* self, int param_1) {
  int in_ECX = (int)(intptr_t)self;
  thunk_FUN_00538430(param_1);
  FUN_0059ab40(param_1);
  FUN_0059ab40(param_1);
  uint32_t* puVar1 = (uint32_t*)(in_ECX + 0x2c);
  {
    void** obj = *(void***)(param_1 + 0x160);
    auto fn = (void(*)(void*, int))obj[1]; // +0xc
    fn(puVar1, 4);
  }
  uint32_t uVar2 = 0;
  if (*puVar1 != 0) {
    do {
      void** obj = *(void***)(param_1 + 0x160);
      auto fn = (void(*)(void*, int))obj[1];
      fn((void*)(*(int*)(in_ECX + 0x30) + uVar2 * 4), 4);
      uVar2 = uVar2 + 1;
    } while (uVar2 < *puVar1);
  }
}

// 0x564750 — non-contiguous: emits Proportion[i]=%g strings into param_1 buffer; three FUN_00557b10/FUN_00557e10 pushes then loop
void FUN_00564750(void* self, int param_1) {
  int in_ECX = (int)(intptr_t)self;
  uint32_t local_10;
  int local_c = in_ECX;
  local_10 = FUN_00557b10();
  {
    uint32_t uVar1 = *(uint32_t*)(param_1 + 0xc);
    if (*(uint32_t*)(param_1 + 8) <= uVar1) {
      FUN_006b34a0();
    }
    FUN_005606f0(uVar1, &local_10);
  }
  local_10 = FUN_00557e10();
  {
    uint32_t uVar1 = *(uint32_t*)(param_1 + 0xc);
    if (*(uint32_t*)(param_1 + 8) <= uVar1) {
      FUN_006b34a0();
    }
    FUN_005606f0(uVar1, &local_10);
  }
  local_10 = FUN_00557e10();
  {
    uint32_t uVar1 = *(uint32_t*)(param_1 + 0xc);
    if (*(uint32_t*)(param_1 + 8) <= uVar1) {
      FUN_006b34a0();
    }
    FUN_005606f0(uVar1, &local_10);
  }
  local_10 = 0;
  if (*(int*)(in_ECX + 0x2c) != 0) {
    do {
      uint32_t uVar1 = local_10;
      char* _Dest = (char*)thunk_FUN_00533c78();
      sprintf(_Dest, "Proportion[%d] = %g", uVar1,
              (double)*(float*)(*(int*)(local_c + 0x30) + uVar1 * 4));
      uVar1 = *(uint32_t*)(param_1 + 0xc);
      if ((uVar1 < *(uint32_t*)(param_1 + 8)) || (FUN_006b34a0(), uVar1 < *(uint32_t*)(param_1 + 8))) {
        if (uVar1 < *(uint32_t*)(param_1 + 0xc)) {
          if (_Dest == nullptr) {
            if (*(int*)(*(int*)(param_1 + 4) + uVar1 * 4) != 0) {
              int iVar2 = *(int*)(param_1 + 0x10) + -1;
              *(int*)(param_1 + 0x10) = iVar2;
            }
          } else if (*(int*)(*(int*)(param_1 + 4) + uVar1 * 4) == 0) {
            int iVar2 = *(int*)(param_1 + 0x10) + 1;
            *(int*)(param_1 + 0x10) = iVar2;
          }
        } else {
          *(uint32_t*)(param_1 + 0xc) = uVar1 + 1;
          if (_Dest != nullptr) {
            int iVar2 = *(int*)(param_1 + 0x10) + 1;
            *(int*)(param_1 + 0x10) = iVar2;
          }
        }
        *(char**)(*(int*)(param_1 + 4) + uVar1 * 4) = _Dest;
      }
      local_10 = local_10 + 1;
    } while (local_10 < *(uint32_t*)(local_c + 0x2c));
  }
}

// 0x564950 — constructor: FUN_00567520, vtable PTR_FUN_006c3620, copy DAT_00727430..38 at +3..+5, zero +9..+10
void FUN_00564950(void* self) {
  FUN_00567520();
  uint32_t* in_ECX = (uint32_t*)self;
  *in_ECX = (uint32_t)(intptr_t)&PTR_FUN_006c3620;
  in_ECX[3] = DAT_00727430;
  in_ECX[4] = DAT_00727434;
  in_ECX[5] = DAT_00727438;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
}

// 0x564990 — destructor: vtable, free in_ECX[10], FUN_00567540, conditional delete on flag bit 1
void FUN_00564990(void* self, uint8_t param_1) {
  uint32_t* in_ECX = (uint32_t*)self;
  *in_ECX = (uint32_t)(intptr_t)&PTR_FUN_006c3620;
  operator_delete__((void*)(intptr_t)in_ECX[10]);
  FUN_00567540();
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x5649d0 — transform: scale by *(param_1+0x9c), offset via FUN_0053ca60, update +0x18..+0x20, square entries at +0x28
void FUN_005649d0(void* self, int param_1) {
  int in_ECX = (int)(intptr_t)self;
  float local_18, local_14, local_10;
  uint8_t local_c[12];
  local_10 = *(float*)(param_1 + 0x9c);
  local_18 = local_10 * *(float*)(in_ECX + 0xc);
  local_14 = local_10 * *(float*)(in_ECX + 0x10);
  local_10 = local_10 * *(float*)(in_ECX + 0x14);
  float* pfVar5 = (float*)FUN_0053ca60(local_c, &local_18);
  float fVar1 = *(float*)(param_1 + 0x94);
  float fVar2 = pfVar5[1];
  float fVar3 = *(float*)(param_1 + 0x98);
  float fVar4 = pfVar5[2];
  *(float*)(in_ECX + 0x18) = *(float*)(param_1 + 0x90) + *pfVar5;
  *(float*)(in_ECX + 0x1c) = fVar1 + fVar2;
  *(float*)(in_ECX + 0x20) = fVar3 + fVar4;
  uint32_t uVar8 = 0;
  if (*(int*)(in_ECX + 0x24) != 0) {
    int iVar6 = 0;
    do {
      float s = *(float*)(*(int*)(in_ECX + 0x28) + iVar6);
      float w = *(float*)(param_1 + 0x9c);
      *(float*)(*(int*)(in_ECX + 0x28) + iVar6 + 8) = w * w * s * s;
      int iVar7 = *(int*)(in_ECX + 0x28) + iVar6;
      uVar8 = uVar8 + 1;
      float s2 = *(float*)(iVar7 + 4);
      iVar6 = iVar6 + 0x10;
      *(float*)(iVar7 + 0xc) = w * w * s2 * s2;
    } while (uVar8 < *(uint32_t*)(in_ECX + 0x24));
  }
}

// 0x564aa0 — resize 16-byte element array at +0x24/+0x28: alloc param_1<<4, copy min(old,new) with masked loops
void FUN_00564aa0(void* self, uint32_t param_1) {
  int in_ECX = (int)(intptr_t)self;
  if (param_1 != *(uint32_t*)(in_ECX + 0x24)) {
    if (param_1 == 0) {
      operator_delete__(*(void**)(in_ECX + 0x28));
      *(uint32_t*)(in_ECX + 0x28) = 0;
      *(uint32_t*)(in_ECX + 0x24) = 0;
      return;
    }
    uint32_t* puVar1 = (uint32_t*)thunk_FUN_00533c78(param_1 << 4);
    if (*(uint32_t**)(in_ECX + 0x28) != nullptr) {
      uint32_t uVar2 = *(uint32_t*)(in_ECX + 0x24);
      if ((int)param_1 <= (int)*(uint32_t*)(in_ECX + 0x24)) {
        uVar2 = param_1;
      }
      uint32_t* puVar4 = *(uint32_t**)(in_ECX + 0x28);
      uint32_t* puVar5 = puVar1;
      for (int iVar3 = (int)((uVar2 & 0xfffffffu) << 2); iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      for (int iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(uint8_t*)puVar5 = *(uint8_t*)puVar4;
        puVar4 = (uint32_t*)((int)(intptr_t)puVar4 + 1);
        puVar5 = (uint32_t*)((int)(intptr_t)puVar5 + 1);
      }
    }
    operator_delete__(*(void**)(in_ECX + 0x28));
    *(uint32_t**)(in_ECX + 0x28) = puVar1;
    *(uint32_t*)(in_ECX + 0x24) = param_1;
  }
}

// 0x564bc0 — argmin search over 4-wide float groups at +0x28 with clamped param_1; returns best index or -1
int FUN_00564bc0(void* self, int param_1) {
  int in_ECX = (int)(intptr_t)self;
  if (param_1 < 1) {
    param_1 = 0;
  }
  int iVar7 = *(int*)(in_ECX + 0x24);
  if (iVar7 + -1 <= param_1) {
    param_1 = iVar7 + -1;
  }
  int iVar6 = -1;
  float fVar1 = -3.4028235e+38f;
  if (-1 < param_1) {
    param_1 = param_1 + 1;
    do {
      float fVar2 = 3.4028235e+38f;
      int iVar5 = 0;
      if (3 < iVar7) {
        float* pfVar4 = (float*)(*(int*)(in_ECX + 0x28) + 0x20);
        int iVar8 = 0x20;
        int iVar9 = -*(int*)(in_ECX + 0x28);
        do {
          if ((fVar1 < pfVar4[-8]) && (pfVar4[-8] <= fVar2)) {
            fVar1 = *(float*)((int)(intptr_t)pfVar4 + *(int*)(in_ECX + 0x28) + iVar9 + -0x20);
            fVar2 = *(float*)((int)(intptr_t)pfVar4 + *(int*)(in_ECX + 0x28) + iVar9 + -0x20);
            iVar6 = iVar5;
          }
          if ((fVar1 < pfVar4[-4]) && (pfVar4[-4] <= fVar2)) {
            fVar1 = *(float*)((int)(intptr_t)pfVar4 + *(int*)(in_ECX + 0x28) + iVar9 + -0x10);
            fVar2 = *(float*)((int)(intptr_t)pfVar4 + *(int*)(in_ECX + 0x28) + iVar9 + -0x10);
            iVar6 = iVar5 + 1;
          }
          if ((fVar1 < *pfVar4) && (*pfVar4 <= fVar2)) {
            float* pfVar3 = (float*)(*(int*)(in_ECX + 0x28) + iVar8);
            fVar1 = *pfVar3;
            iVar6 = iVar5 + 2;
            fVar2 = *pfVar3;
          }
          if ((fVar1 < pfVar4[4]) && (pfVar4[4] <= fVar2)) {
            fVar1 = *(float*)((int)(intptr_t)pfVar4 + *(int*)(in_ECX + 0x28) + iVar9 + 0x10);
            fVar2 = *(float*)((int)(intptr_t)pfVar4 + *(int*)(in_ECX + 0x28) + iVar9 + 0x10);
            iVar6 = iVar5 + 3;
          }
          iVar5 = iVar5 + 4;
          iVar8 = iVar8 + 0x40;
          pfVar4 = pfVar4 + 0x10;
        } while (iVar5 < iVar7 + -3);
      }
      iVar7 = *(int*)(in_ECX + 0x24);
      if (iVar5 < iVar7) {
        int iVar8 = iVar5 << 4;
        do {
          if ((fVar1 < *(float*)(iVar8 + *(int*)(in_ECX + 0x28))) &&
             (*(float*)(iVar8 + *(int*)(in_ECX + 0x28)) <= fVar2)) {
            float* pfVar4 = (float*)(*(int*)(in_ECX + 0x28) + iVar8);
            fVar1 = *pfVar4;
            fVar2 = *pfVar4;
            iVar6 = iVar5;
          }
          iVar5 = iVar5 + 1;
          iVar8 = iVar8 + 0x10;
        } while (iVar5 < iVar7);
      }
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return iVar6;
}
