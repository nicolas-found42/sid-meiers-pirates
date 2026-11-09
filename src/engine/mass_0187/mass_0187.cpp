#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void* DAT_00727c3c;
extern void* DAT_00727598;
extern void* DAT_00728acc;
extern void* DAT_00727854;
extern void* DAT_00727c44;
extern void* DAT_00727430;
extern void* DAT_007177c4;
extern void* DAT_007177c8;
extern void* DAT_007177cc;
extern void* PTR_FUN_006c509c;
extern void* PTR_FUN_006c50fc;
extern void* PTR_FUN_00717a3c;
extern int thunk_FUN_00533c78(uint32_t);
extern void FUN_004127b0(int, int, uint32_t, void*);
extern char FUN_00549c30(void*);
extern void FUN_0058f270(void* self);
extern void FUN_0058f310(void* self);
extern void FUN_0058f760(uint32_t param_1, void* self);
extern void FUN_0058f000(void*);
extern void thunk_FUN_00538410(int, uint32_t);
extern char FUN_0059aac0(void*);
extern void FUN_00513ce0(uint32_t);
extern void FUN_0059ab10(uint32_t);
extern float* FUN_0053ca60(void*, void*);
extern float FUN_0059ab70(void*, void*, void*, void*);
extern float FUN_0059b000(void*, void*, void*, void*, void*);
extern void* FUN_0059a940(uint16_t, void*, uint32_t, uint32_t, uint32_t);
extern void FUN_00535110(int);
extern void operator_delete__(void*);
extern void operator_delete(void*);
extern void FUN_00491640(void);
extern char FUN_00428470(void*);
extern void* FUN_004760c0(void*, void*);
extern void* FUN_00497ca0(void*, void*);
extern void FUN_0058ff70(int);
extern uint32_t FUN_0058fd80(float, int, float*, int, float*);

// 0x58f270 — observed shape: self->+0xc nonnull gate; find DAT_00727c3c in linked list; if found and +0x44==0 and ushort at linked+0xbc+0xc != 0: set +0x4e, allocate count*0xc via thunk, memcpy via FUN_004127b0, set +0x44/+0x4c/+0x50
void FUN_0058f270(void* self) {
  int* piVar2 = *(int**)((char*)self + 0xc);
  if (piVar2 != nullptr) {
    typedef uint32_t* (*GetFirstFn)(void*);
    GetFirstFn getFirst = *(GetFirstFn*)(*(int*)piVar2 + 4);
    uint32_t* node = getFirst((void*)piVar2);
    uint8_t found = 0;
    while (node != nullptr) {
      if (node == (uint32_t*)&DAT_00727c3c) {
        found = 1;
        break;
      }
      node = (uint32_t*)node[1];
    }
    uint32_t uVar5 = (uint32_t)(-(int32_t)found) & (uint32_t)(intptr_t)piVar2;
    if (uVar5 != 0 && *(int*)((char*)self + 0x44) == 0) {
      uint16_t* member = (uint16_t*)(*(int*)(uVar5 + 0xbc) + 0xc);
      uint16_t uVar1 = *member;
      if (uVar1 != 0) {
        *(uint16_t*)((char*)self + 0x4e) = uVar1;
        int alloc = thunk_FUN_00533c78((uint32_t)uVar1 * 0xc);
        int iVar6;
        if (alloc == 0) {
          iVar6 = 0;
        } else {
          FUN_004127b0(alloc, 0xc, (uint32_t)uVar1, (void*)nullptr);
          iVar6 = alloc;
        }
        *(int*)((char*)self + 0x44) = iVar6;
        *(uint8_t*)((char*)self + 0x4c) = 1;
        *(uint16_t*)((char*)self + 0x50) = *(uint16_t*)(*(int*)(uVar5 + 0xbc) + 0x3c);
      }
    }
  }
}

// 0x58f310 — observed shape: self->+0xc nonnull gate; find DAT_00727598; if found and +0x44!=0 and +0x4c!=0: indirect call via +0xbc+0x38, indirect call via PTR_FUN_00717a3c, clear +0x4c
void FUN_0058f310(void* self) {
  int* piVar1 = *(int**)((char*)self + 0xc);
  if (piVar1 != nullptr) {
    typedef uint32_t* (*GetFirstFn)(void*);
    GetFirstFn getFirst = *(GetFirstFn*)(*(int*)piVar1 + 4);
    uint32_t* node = getFirst((void*)piVar1);
    uint8_t found = 0;
    while (node != nullptr) {
      if (node == (uint32_t*)&DAT_00727598) {
        found = 1;
        break;
      }
      node = (uint32_t*)node[1];
    }
    uint32_t uVar5 = (uint32_t)(-(int32_t)found) & (uint32_t)(intptr_t)piVar1;
    if (uVar5 != 0 && *(int*)((char*)self + 0x44) != 0 && *(int8_t*)((char*)self + 0x4c) != 0) {
      int iVar2 = (*(int**)(uVar5 + 0xbc))[8];
      typedef uint32_t (*CallFn)(void);
      CallFn callFn = *(CallFn*)(**(int**)(uVar5 + 0xbc) + 0x38);
      uint32_t uVar6 = callFn();
      typedef void (*PtrFn)(uint32_t, int, int, void*);
      PtrFn ptrFn = (PtrFn)&PTR_FUN_00717a3c;
      ptrFn(uVar6, iVar2, *(int*)((char*)self + 0x44), (void*)(uVar5 + 0x6c));
      *(uint8_t*)((char*)self + 0x4c) = 0;
    }
  }
}

// 0x58f380 — observed shape: if +0x44!=0 call vtable+0x48 to fill two ushorts; if all distinct return 1 and out params = base + idx*0xc else zeros and 0
uint32_t FUN_0058f380(void* self, uint32_t param_1, int* param_2, int* param_3, int* param_4) {
  if (*(int*)((char*)self + 0x44) != 0) {
    uint16_t local_8[2] = {0, 0};
    uint16_t local_4[2] = {0, 0};
    int vtbl = *(int*)(*(int*)((char*)self + 0xc) + 0xbc);
    typedef void (*CallFn)(uint32_t, void*, uint16_t*, uint16_t*);
    CallFn callFn = *(CallFn*)(vtbl + 0x48);
    callFn(param_1, &param_1, local_8, local_4);
    if (((uint16_t)param_1 != local_8[0]) && ((uint16_t)param_1 != local_4[0]) && (local_8[0] != local_4[0])) {
      *param_2 = *(int*)((char*)self + 0x44) + (param_1 & 0xffff) * 0xc;
      *param_3 = *(int*)((char*)self + 0x44) + (uint32_t)local_8[0] * 0xc;
      int iVar1 = *(int*)((char*)self + 0x44) + (uint32_t)local_4[0] * 0xc;
      *param_4 = iVar1;
      return (uint32_t)((iVar1 & 0xffffff00) | 1);
    }
  }
  *param_2 = 0;
  *param_3 = 0;
  *param_4 = 0;
  return (uint32_t)(uintptr_t)param_3 & 0xffffff00;
}

// 0x58f440 — observed shape: refcount++ then ==0 call(1) for both +0xb0 objects; compare [0xb] fields, 3 yields 10, otherwise iVar5+iVar4*5 switch mapping
uint32_t FUN_0058f440(int param_1, int param_2) {
  uint32_t* puVar1 = *(uint32_t**)(param_1 + 0xb0);
  if (puVar1 != nullptr) {
    int iVar2 = (int)puVar1[1];
    puVar1[1] = (uint32_t)(iVar2 + 1);
    puVar1[1] = (uint32_t)iVar2;
    if (iVar2 == 0) {
      typedef void (*CallFn)(int);
      CallFn callFn = *(CallFn*)*puVar1;
      callFn(1);
    }
  }
  uint32_t* puVar3 = *(uint32_t**)(param_2 + 0xb0);
  if (puVar3 != nullptr) {
    int iVar2 = (int)puVar3[1];
    puVar3[1] = (uint32_t)(iVar2 + 1);
    puVar3[1] = (uint32_t)iVar2;
    if (iVar2 == 0) {
      typedef void (*CallFn)(int);
      CallFn callFn = *(CallFn*)*puVar3;
      callFn(1);
    }
  }
  int iVar2 = (int)puVar1[0xb];
  int iVar5 = (int)puVar3[0xb];
  if (iVar2 == 3 || iVar5 == 3) {
    return 10;
  }
  int iVar4 = iVar2;
  if (iVar5 < iVar2) {
    iVar4 = iVar5;
    iVar5 = iVar2;
  }
  switch ((int32_t)(iVar5 + iVar4 * 5)) {
  case 1: return 1;
  case 2: return 2;
  case 4: return 3;
  case 6: return 4;
  case 7: return 5;
  case 9: return 6;
  case 0xc: return 7;
  case 0xe: return 8;
  case 0x18: return 9;
  default: return 0;
  }
}

// 0x58f660 — observed shape: FUN_00549c30 gate; find DAT_00728acc; check [0xb] vs self+0x2c, [10] vs self+0x28, [0xc] ptr compare via vtable+0xc; return 1 on match else 0
uint32_t FUN_0058f660(void* self, int* param_1) {
  char cVar3 = FUN_00549c30((void*)param_1);
  if (cVar3 == '\0') {
    return 0;
  }
  if (param_1 != nullptr) {
    typedef uint32_t* (*GetFirstFn)(void*);
    GetFirstFn getFirst = *(GetFirstFn*)(*param_1 + 4);
    uint32_t* node = getFirst(param_1);
    while (node != nullptr) {
      if (node == (uint32_t*)&DAT_00728acc) {
        if (param_1[0xb] != *(int*)((char*)self + 0x2c)) {
          return 0;
        }
        if (param_1[10] != *(int*)((char*)self + 0x28)) {
          return 0;
        }
        int* piVar1 = (int*)param_1[0xc];
        int* piVar2 = *(int**)((char*)self + 0x30);
        if (piVar1 == nullptr || piVar2 == nullptr) {
          if (piVar1 != *(int**)((char*)self + 0x30)) {
            return 0;
          }
        } else {
          typedef int (*CallFn)(void*);
          CallFn f1 = *(CallFn*)(*piVar1 + 0xc);
          CallFn f2 = *(CallFn*)(*piVar2 + 0xc);
          int iVar5 = f1(piVar1);
          int iVar6 = f2(piVar2);
          if (iVar5 != iVar6) {
            return 0;
          }
        }
        return 1;
      }
      node = (uint32_t*)node[1];
    }
  }
  return 0;
}

extern void* DAT_00727c44;
extern void* DAT_00727434;
extern void* DAT_00727438;
extern int FUN_00533c78(uint32_t);
extern "C" float sqrtf(float);

// 0x58f6e0 — observed shape: gate on self; walk the +0xc object's list from vtable+4; if the node equals DAT_00727598 and self+0xbc is nonnull and param_2 is 0 or 1, OR byte +0x34 of that object with 0x33
void FUN_0058f6e0(int* param_1, int param_2) {
  if (param_1 != nullptr) {
    typedef uint32_t* (*GetFirstFn)(void*);
    GetFirstFn getFirst = *(GetFirstFn*)(*param_1 + 4);
    uint32_t* node = getFirst((void*)param_1);
    if (node != nullptr) {
      while (node != (uint32_t*)&DAT_00727598) {
        node = (uint32_t*)node[1];
        if (node == nullptr) {
          return;
        }
      }
      if ((param_1[0x2f] != 0) && ((param_2 == 0) || (param_2 == 1))) {
        uint8_t* flag = (uint8_t*)(param_1[0x2f] + 0x34);
        *flag = (uint8_t)(*flag | 0x33);
      }
    }
  }
}

// 0x58f760 — observed shape: two singleton dispatches on the +0xc list (DAT_00727c44 then DAT_00727854); first allocates 0x54 and builds a child via FUN_0059a940 from the +0xbc header, second scans triples of distinct ushorts with vtable+0x48 and builds the child from the distinct count
void FUN_0058f760(uint32_t param_1, void* self) {
  typedef uint32_t* (*GetFirstFn)(void*);
  if (*(int**)((char*)self + 0xc) != nullptr) {
    int* obj = *(int**)((char*)self + 0xc);
    GetFirstFn getFirst = *(GetFirstFn*)(*obj + 4);
    uint32_t* node = getFirst(obj);
    while (node != nullptr) {
      if (node == (uint32_t*)&DAT_00727c44) {
        if (*(int*)((char*)self + 0x38) != 0) {
          return;
        }
        if (*(int*)((char*)self + 0x44) == 0) {
          FUN_0058f270(self);
          FUN_0058f310(self);
        }
        int* src = *(int**)((char*)self + 0xc);
        int iVar6 = FUN_00533c78(0x54);
        if (iVar6 == 0) {
          *(uint32_t*)((char*)self + 0x38) = 0;
          return;
        }
        int* body = *(int**)((char*)src + 0xbc);
        uint32_t uVar7 = (uint32_t)(uintptr_t)FUN_0059a940(
            *(uint16_t*)((char*)body + 0x3c), *(void**)((char*)body + 0x44),
            *(uint32_t*)((char*)body + 0x20), *(uint32_t*)((char*)self + 0x44), param_1);
        *(uint32_t*)((char*)self + 0x38) = uVar7;
        return;
      }
      node = (uint32_t*)node[1];
    }
  }
  if (*(int**)((char*)self + 0xc) != nullptr) {
    int* obj = *(int**)((char*)self + 0xc);
    GetFirstFn getFirst = *(GetFirstFn*)(*obj + 4);
    uint32_t* node = getFirst(obj);
    if (node != nullptr) {
      while (node != (uint32_t*)&DAT_00727854) {
        node = (uint32_t*)node[1];
        if (node == nullptr) {
          return;
        }
      }
      if (*(int*)((char*)self + 0x38) == 0) {
        if (*(int*)((char*)self + 0x44) == 0) {
          FUN_0058f270(self);
          FUN_0058f310(self);
        }
        int* src = *(int**)((char*)self + 0xc);
        uint32_t uVar8 = *(uint16_t*)(*(int*)((char*)src + 0xbc) + 0x3c);
        void* pvVar5 = (void*)(uintptr_t)thunk_FUN_00533c78(uVar8 * 6);
        int iStack_10 = 0;
        uint32_t uStack_14 = 0;
        if (uVar8 != 0) {
          short* psVar9 = (short*)((char*)pvVar5 + 2);
          do {
            int* body = *(int**)((char*)src + 0xbc);
            typedef void (*FillFn)(uint32_t, short*, short*, short*);
            FillFn fill = *(FillFn*)(*body + 0x48);
            fill(uStack_14, psVar9 - 1, psVar9, psVar9 + 1);
            short sVar1 = psVar9[-1];
            short sVar2 = psVar9[1];
            if ((sVar1 != *psVar9) && (sVar1 != sVar2) && (*psVar9 != sVar2)) {
              psVar9 += 3;
              iStack_10 = iStack_10 + 1;
            }
            uStack_14 = uStack_14 + 1;
          } while (uStack_14 < uVar8);
        }
        int iVar6 = FUN_00533c78(0x54);
        uint32_t uVar7;
        if (iVar6 == 0) {
          uVar7 = 0;
        } else {
          uVar7 = (uint32_t)(uintptr_t)FUN_0059a940(
              (uint16_t)iStack_10, pvVar5, *(uint32_t*)(*(int*)((char*)src + 0xbc) + 0x20),
              *(uint32_t*)((char*)self + 0x44), param_1);
        }
        *(uint32_t*)((char*)self + 0x38) = uVar7;
        operator_delete__(pvVar5);
      }
    }
  }
}

// 0x58fb40 — observed shape: base-init then copy +0x28/+0x2c from the receiver object, forward +0x30 through vtable+0x1c into FUN_0058f000, and when the receiver has +0x38 build the target's +0x44 table then its +0x38 child
void FUN_0058fb40(int param_1, uint32_t param_2, void* self) {
  thunk_FUN_00538410(param_1, param_2);
  *(uint32_t*)(param_1 + 0x28) = *(uint32_t*)((char*)self + 0x28);
  *(uint32_t*)(param_1 + 0x2c) = *(uint32_t*)((char*)self + 0x2c);
  if (*(int**)((char*)self + 0x30) != nullptr) {
    int* obj = *(int**)((char*)self + 0x30);
    typedef uint32_t (*CallFn)(void*);
    CallFn callFn = *(CallFn*)(*obj + 0x1c);
    uint32_t uVar1 = callFn(obj);
    FUN_0058f000((void*)(uintptr_t)uVar1);
  }
  if (*(int*)((char*)self + 0x38) != 0) {
    // The listing drops the ECX receiver of these calls; the +0x44 gate just
    // checked belongs to param_1, so param_1 is the receiver.
    if (*(int*)(param_1 + 0x44) == 0) {
      FUN_0058f270((void*)param_1);
      FUN_0058f310((void*)param_1);
    }
    FUN_0058f760(1, (void*)param_1);
  }
}

// 0x58fc20 — observed shape: virtual +0xc on param_1; only when it returns 0 test FUN_0059aac0 on self+4 and report 1 on a nonzero char
uint32_t FUN_0058fc20(int* param_1, void* self) {
  typedef int (*CallFn)(void*);
  CallFn callFn = *(CallFn*)(*param_1 + 0xc);
  int iVar2 = callFn(param_1);
  if (iVar2 == 0) {
    char cVar1 = FUN_0059aac0((char*)self + 4);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}

// 0x58fc60 — observed shape: relay the single argument to FUN_00513ce0 and FUN_0059ab10
void FUN_0058fc60(uint32_t param_1) {
  FUN_00513ce0(param_1);
  FUN_0059ab10(param_1);
}

// 0x58fca0 — observed shape: store vtable PTR_FUN_006c509c, copy three dwords from param_2, store param_1 in slot 4
void FUN_0058fca0(uint32_t param_1, uint32_t* param_2, void* self) {
  uint32_t* ecx = (uint32_t*)self;
  ecx[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c509c;
  ecx[1] = param_2[0];
  ecx[2] = param_2[1];
  ecx[3] = param_2[2];
  ecx[4] = param_1;
}

// 0x58fd00 — observed shape: transform param_1+4 through FUN_0053ca60, then write self+4..+0x10 from the param_2 frame (+0x24..+0x30) scaled by the transformed components
void FUN_0058fd00(int param_1, int param_2, void* self) {
  uint8_t local_18[24] = {0};
  float* pfVar6 = FUN_0053ca60((void*)local_18, (void*)(param_1 + 4));
  float fVar1 = *(float*)(param_2 + 0x30);
  float fVar2 = pfVar6[1];
  float fVar3 = pfVar6[2];
  float fVar4 = *(float*)(param_2 + 0x28);
  float fVar5 = *(float*)(param_2 + 0x2c);
  *(float*)((char*)self + 4) = fVar1 * *pfVar6 + *(float*)(param_2 + 0x24);
  *(float*)((char*)self + 8) = fVar1 * fVar2 + fVar4;
  *(float*)((char*)self + 0xc) = fVar1 * fVar3 + fVar5;
  *(float*)((char*)self + 0x10) = *(float*)(param_1 + 0x10) * *(float*)(param_2 + 0x30);
}

// 0x58fd80 — observed shape: sphere-vs-sphere sweep of a segment; squared separation and radius sums decide overlap, the projection along the segment decides the ordering, result is the parity of the two compare bits (i.e. separated <= test)
uint32_t FUN_0058fd80(float param_1, int param_2, float* param_3, int param_4, float* param_5) {
  float fVar1 = *param_5 - *param_3;
  float fVar2 = param_5[1] - param_3[1];
  float fVar3 = param_5[2] - param_3[2];
  float fVar4 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
  float fVar5 = *(float*)(param_4 + 4) - *(float*)(param_2 + 4);
  float fVar6 = *(float*)(param_4 + 8) - *(float*)(param_2 + 8);
  float fVar7 = *(float*)(param_4 + 0xc) - *(float*)(param_2 + 0xc);
  float fVar8 = fVar5 * fVar5 + fVar6 * fVar6 + fVar7 * fVar7;
  float fVar9 = *(float*)(param_2 + 0x10) + *(float*)(param_4 + 0x10);
  fVar9 = fVar9 * fVar9;
  uint8_t bVar10 = 0;
  if ((fVar4 <= 0.0f) ||
      (fVar1 = fVar5 * fVar1 + fVar6 * fVar2 + fVar7 * fVar3,
       (fVar1 != fVar1) || ((fVar1 < 0.0f) == (fVar1 == 0.0f)))) {
    bVar10 = (uint8_t)((fVar8 < fVar9) |
                       (uint8_t)((uint16_t)((uint16_t)(fVar8 == fVar9) << 0xe) >> 8));
  } else {
    float fVar2b = -(fVar4 * param_1);
    if ((fVar2b == fVar2b) && (fVar1 == fVar1) &&
        ((fVar2b < fVar1) != (fVar2b == fVar1))) {
      if (fVar9 * fVar4 < fVar8 * fVar4 - fVar1 * fVar1) {
        return 0;
      }
      return 1;
    }
    fVar8 = (fVar1 + fVar1 + fVar4 * param_1) * param_1 + fVar8;
    bVar10 = (uint8_t)((fVar8 < fVar9) |
                       (uint8_t)((uint16_t)((uint16_t)(fVar8 == fVar9) << 0xe) >> 8));
  }
  uint32_t parity = 0;
  for (int i = 0; i < 8; i++) {
    parity ^= ((uint32_t)bVar10 >> i) & 1u;
  }
  if (parity == 0) {
    return 0;
  }
  return 1;
}

// 0x58feb0 — observed shape: scale a point by param_1 along the frame axes (+3/+4/+5) and return FUN_0059ab70 of that point minus the +0x3c scalar
long double FUN_0058feb0(float param_1, float* param_2) {
  float local_4 = param_1 * param_2[5];
  float local_18 = param_1 * param_2[3] + *param_2;
  float local_14 = param_1 * param_2[4] + param_2[1];
  float local_10 = local_4 + param_2[2];
  long double fVar1 = (long double)FUN_0059ab70(&local_18, param_2 + 6, param_2 + 0x10, param_2 + 0x11);
  return fVar1 - (long double)param_2[0xf];
}

// 0x58ff70 — observed shape: store vtable PTR_FUN_006c509c then copy param_1+4..+0x10 into slots 1..4
void FUN_0058ff70(int param_1, void* self) {
  uint32_t* ecx = (uint32_t*)self;
  ecx[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c509c;
  ecx[1] = *(uint32_t*)(param_1 + 4);
  ecx[2] = *(uint32_t*)(param_1 + 8);
  ecx[3] = *(uint32_t*)(param_1 + 0xc);
  ecx[4] = *(uint32_t*)(param_1 + 0x10);
}

// 0x58ffe0 — observed shape: swept-segment vs sphere test (param_3/param_5 segment, param_2/param_4 spheres, param_1 sweep length); on a hit writes the contact point into param_7, the fraction into param_6 and the normal into param_9/param_10, with a recursive 1e-5 retry through FUN_0058fd80 when the near test misses
uint16_t FUN_0058ffe0(float param_1, int param_2, float* param_3, int param_4, float* param_5,
                      float* param_6, float* param_7, uint32_t param_8, float* param_9,
                      float* param_10) {
  // Ghidra folds the FPU register arguments of FUN_00491640() into dead pointer
  // stores (param_5 = (float*)value); those stores are dropped, the calls kept.
  // Stack slots the listing reuses without a dominating write stay zero.
  float local_40 = 0.0f, local_3c = 0.0f;
  float local_30 = 0.0f, local_2c = 0.0f, local_28 = 0.0f;
  float local_20 = 0.0f, local_1c = 0.0f, local_18 = 0.0f, local_14 = 0.0f;
  float local_c = 0.0f, local_8 = 0.0f, local_4 = 0.0f;
  uint8_t local_34[4] = {0, 0, 0, 0};
  float* pfVar16 = param_9;
  float* pfVar15 = param_5;
  int iVar13 = param_4;
  float fVar1 = *param_5 - *param_3;
  float* pfVar18 = (float*)(param_4 + 4);
  float* pfVar19 = (float*)(param_2 + 4);
  float fVar2 = param_5[1] - param_3[1];
  float fVar6 = param_5[2] - param_3[2];
  float fVar3 = fVar2 * fVar2 + fVar6 * fVar6 + fVar1 * fVar1;
  float fVar4 = *pfVar18 - *pfVar19;
  float fVar5 = *(float*)(param_4 + 8) - *(float*)(param_2 + 8);
  float fVar7 = *(float*)(param_4 + 0xc) - *(float*)(param_2 + 0xc);
  float fVar8 = fVar5 * fVar5 + fVar7 * fVar7 + fVar4 * fVar4;
  float fVar10 = *(float*)(param_4 + 0x10) + *(float*)(param_2 + 0x10);
  float fVar9 = fVar10 * fVar10;
  float dot = 0.0f;
  if ((fVar3 <= 0.0f) ||
      ((dot = fVar5 * fVar2 + fVar7 * fVar6 + fVar4 * fVar1,
        (dot != dot) || ((dot < 0.0f) == (dot == 0.0f))))) {
    if ((fVar8 == fVar8) && (fVar9 == fVar9) && ((fVar8 < fVar9) != (fVar8 == fVar9))) {
      *param_6 = 0.0f;
      float fVar1a = *param_3;
      if (param_5[2] * param_5[2] + param_5[1] * param_5[1] + *param_5 * *param_5 <=
          param_3[2] * param_3[2] + param_3[1] * param_3[1] + fVar1a * fVar1a) {
        float fVar5a = param_3[1];
        float fVar2a = *param_3;
        float fVar6a = param_3[2];
        FUN_00491640();
        pfVar15 = param_10;
        int iVar14 = param_4;
        float fVar1b = *(float*)(param_4 + 0x10);
        local_18 = fVar6a + fVar6a;
        local_c = (fVar2a + fVar2a) * fVar1b;
        local_4 = local_18 * fVar1b;
        local_20 = *pfVar19 - local_c;
        float fVar2b = *(float*)(param_2 + 8);
        float fVar6b = *(float*)(param_2 + 0xc);
        float fVar3b = *(float*)(iVar13 + 8);
        float fVar4b = *(float*)(iVar13 + 0xc);
        *param_10 = local_20 - *pfVar18;
        param_10[1] = (fVar2b - (fVar5a + fVar5a) * fVar1b) - fVar3b;
        param_10[2] = (fVar6b - local_4) - fVar4b;
        FUN_00491640();
        float fVar1c = *(float*)(iVar14 + 0x10);
        float fVar2c = pfVar15[1];
        float fVar6c = pfVar15[2];
        float fVar3c = *(float*)(iVar13 + 8);
        float fVar4c = *(float*)(iVar13 + 0xc);
        *param_7 = fVar1c * *pfVar15 + *pfVar18;
        param_7[1] = fVar1c * fVar2c + fVar3c;
        param_7[2] = fVar1c * fVar6c + fVar4c;
        local_40 = *pfVar15;
        local_3c = pfVar15[1];
        float dirZ = pfVar15[2];
        param_10 = param_9;
        local_3c = -local_3c;
        local_40 = -local_40;
        *param_10 = local_40;
        param_10[1] = local_3c;
        param_10[2] = -dirZ;
        return 1;
      }
      float fVar5d = param_5[1];
      float fVar2d = *param_5;
      float fVar6d = param_5[2];
      FUN_00491640();
      pfVar15 = param_9;
      float fVar1d = *(float*)(param_2 + 0x10);
      local_18 = fVar6d + fVar6d;
      local_c = (fVar2d + fVar2d) * fVar1d;
      local_4 = local_18 * fVar1d;
      local_20 = *pfVar18 - local_c;
      float fVar2e = *(float*)(iVar13 + 8);
      float fVar6e = *(float*)(iVar13 + 0xc);
      float fVar3d = *(float*)(param_2 + 8);
      float fVar4d = *(float*)(param_2 + 0xc);
      *param_9 = local_20 - *pfVar19;
      param_9[1] = (fVar2e - (fVar5d + fVar5d) * fVar1d) - fVar3d;
      param_9[2] = (fVar6e - local_4) - fVar4d;
      FUN_00491640();
      float fVar1e = *(float*)(param_2 + 0x10);
      float fVar2f = pfVar15[1];
      float fVar6f = pfVar15[2];
      float fVar3e = *(float*)(param_2 + 8);
      float fVar4e = *(float*)(param_2 + 0xc);
      *param_7 = fVar1e * *pfVar15 + *pfVar19;
      param_7[1] = fVar1e * fVar2f + fVar3e;
      param_7[2] = fVar1e * fVar6f + fVar4e;
      local_40 = *pfVar15;
      local_3c = pfVar15[1];
      float dirZ = pfVar15[2];
      local_3c = -local_3c;
      local_40 = -local_40;
      *param_10 = local_40;
      param_10[1] = local_3c;
      param_10[2] = -dirZ;
      return 1;
    }
  } else {
    float fVar11 = -(fVar3 * param_1);
    if ((((fVar11 != fVar11) || (dot != dot)) || ((fVar11 < dot) == (fVar11 == dot))) &&
        (fVar9 + 1e-05f < (dot + dot + fVar3 * param_1) * param_1 + fVar8)) {
      return 0;
    }
    fVar8 = fVar8 - fVar9;
    fVar9 = dot * dot - fVar8 * fVar3;
    if (0.0f <= fVar9) {
      if ((fVar8 != fVar8) || ((fVar8 < 0.0f) == (fVar8 == 0.0f))) {
        float fVar3f = -((sqrtf(fVar9) + dot) / fVar3);
        *param_6 = fVar3f;
        if (0.0f <= fVar3f) {
          if (param_1 < fVar3f) {
            *param_6 = param_1;
          }
        } else {
          *param_6 = 0.0f;
        }
        float fVar3g = *param_6;
        float fVar4f = fVar1 * fVar3g + fVar4;
        float fVar5e = fVar2 * fVar3g + fVar5;
        float fVar7a = fVar6 * fVar3g + fVar7;
        float fVar10a = *(float*)(param_2 + 0x10) / fVar10;
        local_8 = fVar5e * fVar10a;
        local_4 = fVar7a * fVar10a;
        float fVar1f = *param_6;
        local_30 = fVar1f * param_3[1];
        local_2c = fVar1f * param_3[2];
        local_1c = local_30 + *(float*)(param_2 + 8);
        local_18 = local_2c + *(float*)(param_2 + 0xc);
        *param_7 = fVar1f * *param_3 + *pfVar19 + fVar4f * fVar10a;
        param_7[1] = local_1c + local_8;
        param_7[2] = local_18 + local_4;
        if ((char)param_8 != '\0') {
          *param_9 = fVar4f;
          param_9[1] = fVar5e;
          param_9[2] = fVar7a;
          FUN_00491640();
          float fVar1g = pfVar16[1];
          float fVar2g = pfVar16[2];
          *param_10 = -*pfVar16;
          param_10[1] = -fVar1g;
          param_10[2] = -fVar2g;
        }
        return 1;
      }
      *param_6 = 0.0f;
      FUN_0058ff70(param_2);
      FUN_0058ff70(param_4);
      local_30 = local_30 - param_1 * *param_3;
      local_2c = local_2c - param_1 * param_3[1];
      local_28 = local_28 - param_1 * param_3[2];
      local_4 = param_1 * pfVar15[2];
      local_1c = local_1c - param_1 * *pfVar15;
      local_18 = local_18 - param_1 * pfVar15[1];
      local_14 = local_14 - local_4;
      char cVar17 = (char)FUN_0058fd80(0.0f, (int)(intptr_t)local_34, (float*)&DAT_00727430,
                                       (int)(intptr_t)&local_20, (float*)&DAT_00727430);
      if (cVar17 == '\0') {
        FUN_0058ffe0(param_1 + 1e-05f, (int)(intptr_t)local_34, param_3, (int)(intptr_t)&local_20,
                     pfVar15, (float*)&param_4, param_7, param_8, param_9, param_10);
        return 1;
      }
      pfVar18 = (float*)FUN_00497ca0(&local_c, pfVar18);
      float fVar1h = pfVar18[1];
      float fVar2h = pfVar18[2];
      *param_7 = *pfVar18 * 0.5f;
      param_7[1] = fVar1h * 0.5f;
      param_7[2] = fVar2h * 0.5f;
      if ((char)param_8 != '\0') {
        cVar17 = FUN_00428470(pfVar19);
        if (cVar17 == '\0') {
          *param_9 = *(float*)&DAT_007177c4;
          param_9[1] = *(float*)&DAT_007177c8;
          param_9[2] = *(float*)&DAT_007177cc;
        } else {
          pfVar19 = (float*)FUN_004760c0(&local_c, pfVar19);
          pfVar18 = param_9;
          *param_9 = *pfVar19;
          param_9[1] = pfVar19[1];
          param_9[2] = pfVar19[2];
          FUN_00491640();
          param_9 = pfVar18;
        }
        float fVar1i = param_9[1];
        float fVar2i = param_9[2];
        *param_10 = -*param_9;
        param_10[1] = -fVar1i;
        param_10[2] = -fVar2i;
      }
      return 1;
    }
  }
  return 0;
}

// 0x5907b0 — observed shape: sweep of a point against two candidate spheres (param_4 origin, param_5/param_6 offsets); when param_3 and param_7 differ by the DAT_00727430 triple test FUN_0059ab70 at param_2+4, else scale the delta by param_1 and call FUN_0059b000; compare the squared result against the +0x10 radius squared
uint32_t FUN_005907b0(float param_1, int param_2, float* param_3, float* param_4, float* param_5,
                      float* param_6, float* param_7) {
  int iVar1 = param_2;
  float local_30 = 0.0f;
  uint32_t local_3c = 0, local_38 = 0, local_34 = 0;
  float local_2c = 0.0f, local_28 = 0.0f;
  float local_24 = *param_4;
  float local_20 = param_4[1];
  float local_1c = param_4[2];
  float local_18 = *param_5 - *param_4;
  float local_14 = param_5[1] - param_4[1];
  float local_10 = param_5[2] - param_4[2];
  float local_c = *param_6 - *param_4;
  float local_8 = param_6[1] - param_4[1];
  float local_4 = param_6[2] - param_4[2];
  long double fVar2;
  if (((*param_3 - *param_7 == *(float*)&DAT_00727430) &&
       (param_3[1] - param_7[1] == *(float*)&DAT_00727434)) &&
      (param_3[2] - param_7[2] == *(float*)&DAT_00727438)) {
    fVar2 = (long double)FUN_0059ab70((void*)(uintptr_t)(param_2 + 4), &local_24,
                                      (void*)&param_3, (void*)(uintptr_t)param_2);
  } else {
    local_30 = (*param_3 - *param_7) * param_1;
    local_3c = *(uint32_t*)(param_2 + 4);
    local_38 = *(uint32_t*)(param_2 + 8);
    local_34 = *(uint32_t*)(param_2 + 0xc);
    local_2c = (param_3[1] - param_7[1]) * param_1;
    local_28 = (param_3[2] - param_7[2]) * param_1;
    fVar2 = (long double)FUN_0059b000(&local_3c, &local_24, (void*)&param_7, (void*)&param_3,
                                      (void*)&param_2);
  }
  long double fVar3 =
      (long double)*(float*)(iVar1 + 0x10) * (long double)*(float*)(iVar1 + 0x10);
  if ((fVar2 != fVar2) || (fVar3 != fVar3) || ((fVar2 < fVar3) == (fVar2 == fVar3))) {
    return 0;
  }
  return 1;
}

// 0x590e60 — observed shape: three FUN_00535110 passes on param_1, three vtable+8 reads of the +0x15c reader into a local buffer, then allocate 0x14 and fill the vtable + four slots from those reads
uint32_t* FUN_00590e60(int param_1) {
  uint8_t local_2c[2] = {0, 0};
  uint8_t auStack_2a[22] = {0};
  uint32_t uStack_14 = 0;
  uint8_t local_c[12] = {0};
  FUN_00535110(param_1);
  FUN_00535110(param_1);
  FUN_00535110(param_1);
  uint32_t uVar2 = 4;
  int* reader = *(int**)(param_1 + 0x15c);
  typedef void (*ReadFn)(...);
  ReadFn readFn = *(ReadFn*)(*reader + 8);
  readFn();
  readFn(local_2c - 4);
  readFn(local_c, 4);
  (void)auStack_2a;
  uint32_t* puVar1 = (uint32_t*)(uintptr_t)FUN_00533c78(0x14);
  if (puVar1 == nullptr) {
    return nullptr;
  }
  puVar1[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c509c;
  puVar1[1] = 4;
  puVar1[2] = (uint32_t)(uintptr_t)local_2c;
  puVar1[4] = uStack_14;
  puVar1[3] = uVar2;
  return puVar1;
}

// 0x591020 — observed shape: store vtable PTR_FUN_006c50fc, delete slot 1, and delete self itself when bit 0 of param_1 is set
void FUN_00591020(uint8_t param_1, void* self) {
  uint32_t* ecx = (uint32_t*)self;
  ecx[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c50fc;
  operator_delete__((void*)(uintptr_t)ecx[1]);
  if ((param_1 & 1) != 0) {
    operator_delete(ecx);
  }
}

// 0x591050 — observed shape: two embedded PTR_FUN_006c50fc sub-objects at slot 0 and slot 6, each with a 4-byte heap block in its +1 slot and flag/counter pairs set to 1/0
void FUN_00591050(void* self) {
  uint32_t* ecx = (uint32_t*)self;
  ecx[0] = (uint32_t)(uintptr_t)&PTR_FUN_006c50fc;
  ecx[2] = 1;
  ecx[5] = 1;
  ecx[3] = 0;
  ecx[4] = 0;
  uint32_t uVar1 = (uint32_t)thunk_FUN_00533c78(4);
  ecx[1] = uVar1;
  ecx[6] = (uint32_t)(uintptr_t)&PTR_FUN_006c50fc;
  ecx[8] = 1;
  ecx[0xb] = 1;
  ecx[9] = 0;
  ecx[10] = 0;
  uVar1 = (uint32_t)thunk_FUN_00533c78(4);
  ecx[7] = uVar1;
}
