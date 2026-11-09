#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_00535920(void* self);
extern void FUN_00534cf0(int* param_1, uint32_t* param_2);
extern void FUN_00533fa0(uint32_t param_1, int param_2);
extern void FUN_00548600(int* param_1);
extern void FUN_00548720(void* param_1, void* param_2);
extern int FUN_00533c78(int size);
extern uint32_t* FUN_00557940(void);
extern uint32_t FUN_00534270(uint32_t param_1, uint32_t* param_2, uint32_t param_3);
extern char FUN_00535510(void* self);
extern uint32_t* FUN_00557340(void);
extern void FUN_0051ac30(void* param_1);
extern void FUN_005575c0(int param_1);
extern void FUN_00557530(uint32_t param_1);
extern void FUN_00535670(void* self);
extern int FUN_00533ec0(uint32_t param_1);
extern char FUN_00533f50(uint32_t param_1);
extern void FUN_00534810(int* param_1);
extern char FUN_005348e0(int param_1);
extern void FUN_004127b0(void* dst, int stride, int count, void* fill);
extern void operator_delete(void* ptr);
extern void operator_delete__(void* ptr);
extern void FUN_005349d0(void);
extern void FUN_0053b9c0(int param_1, uint32_t param_2);
extern void FUN_0053b680(int param_1);
extern uint32_t FUN_0053b150(void* self, uint32_t param_1);

extern void* PTR_LAB_006fd148;
extern void* PTR_FUN_006c0ba8;
extern void* PTR_FUN_006c0bd0;
extern void* PTR_FUN_006c0bd8;
extern void* PTR_FUN_006c0bc4;
extern void* LAB_004c2970;
extern int DAT_00727444;

// 0x53ad50 — observed shape: self+0xcc vftable w/ +8 call, self+0xd0 head, self+0xd4 tail, self+0xd8 count, loop pop/delete + FUN_00535920
void FUN_0053ad50(void* self) {
  int32_t* piVar1;
  int32_t iVar2;
  int32_t* sself = (int32_t*)self;
  if (*(int32_t*)((char*)sself + 0xd8) != 0) {
    do {
      piVar1 = *(int32_t**)((char*)sself + 0xd0);
      iVar2 = *piVar1;
      *(int32_t*)((char*)sself + 0xd0) = iVar2;
      if (iVar2 == 0) {
        *(uint32_t*)((char*)sself + 0xd4) = 0;
      } else {
        *(uint32_t*)((char*)iVar2 + 4) = 0;
      }
      {
        void** vtbl = (void**)*(int32_t*)((char*)sself + 0xcc);
        ((void(*)(int32_t*))vtbl[1])(piVar1);
      }
      *(int32_t*)((char*)sself + 0xd8) = *(int32_t*)((char*)sself + 0xd8) + -1;
      FUN_00535920(sself);
    } while (*(int32_t*)((char*)sself + 0xd8) != 0);
  }
}

// 0x53adc0 — observed shape: FUN_00534cf0 + loop over self+0xb8[?]*self+0xc0, vftable +8/+0x7c, refcount dec on param_2[1]
void FUN_0053adc0(int* param_1, uint32_t* param_2) {
  int32_t* piVar1;
  int32_t iVar2;
  int32_t* piVar3;
  uint32_t* puVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  void* self = *(void**)&param_1;
  // in_ECX recovered as receiver holder; use param_1 base for self offset math via implicit in_ECX
  // NOTE: pseudocode in_ECX is distinct receiver; observe via *(int*)(in_ECX+0xc0)
  // To preserve offsets, treat self pointer from wrapper: we use param_1 region only for call sequence.
  // Fallback: use global receiver passed via first param's ambient? Keep observed structure with self alias:
  volatile int32_t* ecxp = nullptr;
  // Use derived self storage: self bytes at in_ECX
  // We approximate self as param_1's receiver context via ecxp guard; actual translation below uses offsets on ecxp.
  puVar4 = param_2;
  piVar3 = param_1;
  FUN_00534cf0(param_1, param_2);
  uVar6 = 0;
  // Retrieve receiver pointer: for faithful replay, cast self from a package-local slot
  // This keeps call order and offsets identical to listing.
  int32_t* rself = (int32_t*)self;
  if (*(int32_t*)((char*)rself + 0xc0) != 0) {
    do {
      piVar1 = *(int32_t**)(*(int32_t*)((char*)rself + 0xb8) + uVar6 * 4);
      if (piVar1 != (int32_t*)0) {
        uVar5 = (*(uint32_t(*)(uint32_t*))(*(void**)*piVar1)[1])(puVar4);
        (*(void(*)(int** , uint32_t, uint32_t))(*(void**)*piVar3)[0x1f])(&param_1, uVar6, uVar5);
        if ((param_2 != (uint32_t*)0) && (iVar2 = param_2[1], param_2[1] = iVar2 + -1, iVar2 + -1 == 0)) {
          (*(void(*)(uint32_t*, int))(*(void**)*param_2)[0])(param_2, 1);
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint32_t*)((char*)rself + 0xc0));
  }
}

// 0x53ae40 — observed shape: (char)param_2 gate FUN_00533fa0(param_1,1), vftable+0x6c, word indices 0xd/0x30/0x2e/10..0xd, vftable+0x48, FUN_00548600
void FUN_0053ae40(void* self, uint32_t param_1, uint32_t param_2) {
  int32_t* piVar1;
  int32_t* in_ECX = (int32_t*)self;
  uint32_t uVar2;
  if ((char)param_2 != '\0') {
    FUN_00533fa0(param_1, 1);
  }
  (*(void(*)())(*(void**)*in_ECX)[0x1b])();
  uVar2 = 0;
  in_ECX[0xd] = 0;
  if (in_ECX[0x30] != 0) {
    do {
      piVar1 = *(int32_t**)(in_ECX[0x2e] + uVar2 * 4);
      if ((piVar1 != (int32_t*)0) && ((*(void(*)(uint32_t, uint32_t))(*(void**)*piVar1)[0x12])(param_1, param_2), *(float*)&piVar1[0xd] != 0.0f)) {
        if (*(float*)&in_ECX[0xd] == 0.0f) {
          in_ECX[10] = piVar1[10];
          in_ECX[0xb] = piVar1[0xb];
          in_ECX[0xc] = piVar1[0xc];
          in_ECX[0xd] = piVar1[0xd];
        } else {
          FUN_00548600(piVar1 + 10);
        }
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint32_t)in_ECX[0x30]);
  }
}

// 0x53aef0 — observed shape: like 0x53ae40 but filter (byte)(piVar1+8)&1==0, vftable+0x4c
void FUN_0053aef0(void* self, uint32_t param_1, uint32_t param_2) {
  int32_t* piVar1;
  int32_t* in_ECX = (int32_t*)self;
  uint32_t uVar2;
  if ((char)param_2 != '\0') {
    FUN_00533fa0(param_1, 1);
  }
  (*(void(*)())(*(void**)*in_ECX)[0x1b])();
  uVar2 = 0;
  in_ECX[0xd] = 0;
  if (in_ECX[0x30] != 0) {
    do {
      piVar1 = *(int32_t**)(in_ECX[0x2e] + uVar2 * 4);
      if (((piVar1 != (int32_t*)0) && ((*(uint8_t*)((char*)piVar1 + 8) & 1) == 0)) && ((*(void(*)(uint32_t, uint32_t))(*(void**)*piVar1)[0x13])(param_1, param_2), *(float*)&piVar1[0xd] != 0.0f)) {
        if (*(float*)&in_ECX[0xd] == 0.0f) {
          in_ECX[10] = piVar1[10];
          in_ECX[0xb] = piVar1[0xb];
          in_ECX[0xc] = piVar1[0xc];
          in_ECX[0xd] = piVar1[0xd];
        } else {
          FUN_00548600(piVar1 + 10);
        }
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint32_t)in_ECX[0x30]);
  }
}

// 0x53afa0 — observed shape: flags (byte)(in_ECX+8)>>3&1 / >>2&1, vftable+0x6c, loop piVar1[8]>>1&1 / >>4&1, vftable+0x50/+0x54, piVar1[0xd] float gate
void FUN_0053afa0(void* self, uint32_t param_1) {
  int32_t* piVar1;
  int32_t* in_ECX = (int32_t*)self;
  uint32_t uVar2;
  FUN_00533fa0(param_1, (*(uint8_t*)((char*)in_ECX + 8) >> 3 & 1));
  if ((*(uint8_t*)((char*)in_ECX + 8) >> 2 & 1) != 0) {
    (*(void(*)())(*(void**)*in_ECX)[0x1b])();
  }
  uVar2 = 0;
  in_ECX[0xd] = 0;
  if (in_ECX[0x30] != 0) {
    do {
      piVar1 = *(int32_t**)(in_ECX[0x2e] + uVar2 * 4);
      if (piVar1 != (int32_t*)0) {
        if (((uint8_t)piVar1[8] >> 1 & 1) != 0) {
          if (((uint8_t)piVar1[8] >> 4 & 1) == 0) {
            (*(void(*)(uint32_t))(*(void**)*piVar1)[0x14])(param_1);
          } else {
            (*(void(*)())(*(void**)*piVar1)[0x15])();
          }
        }
        if (*(float*)&piVar1[0xd] != 0.0f) {
          if (*(float*)&in_ECX[0xd] == 0.0f) {
            in_ECX[10] = piVar1[10];
            in_ECX[0xb] = piVar1[0xb];
            in_ECX[0xc] = piVar1[0xc];
            in_ECX[0xd] = piVar1[0xd];
          } else {
            FUN_00548600(piVar1 + 10);
          }
        }
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint32_t)in_ECX[0x30]);
  }
}
// 0x53b080 — observed shape: flags, vftable+0x6c, FUN_00548720(in_ECX+0x37,+0x1b), loop piVar1+8>>1&1 vftable+0x54
void FUN_0053b080(void* self, uint32_t param_1) {
  int32_t* piVar1;
  int32_t* in_ECX = (int32_t*)self;
  uint32_t uVar2;
  FUN_00533fa0(param_1, (*(uint8_t*)((char*)in_ECX + 8) >> 3 & 1));
  if ((*(uint8_t*)((char*)in_ECX + 8) >> 2 & 1) != 0) {
    (*(void(*)())(*(void**)*in_ECX)[0x1b])();
    FUN_00548720(in_ECX + 0x37, in_ECX + 0x1b);
  }
  if (in_ECX[0x30] != 0) {
    uVar2 = 0;
    do {
      piVar1 = *(int32_t**)(in_ECX[0x2e] + uVar2 * 4);
      if ((piVar1 != (int32_t*)0) && ((*(uint8_t*)((char*)piVar1 + 8) >> 1 & 1) != 0)) {
        (*(void(*)(uint32_t))(*(void**)*piVar1)[0x15])(param_1);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint32_t)in_ECX[0x30]);
  }
}

// 0x53b100 — observed shape: FUN_00533fa0(param_1,1), self+0xb8/self+0xc0 loop, vftable+0x34
void FUN_0053b100(void* self, uint32_t param_1) {
  int32_t* piVar1;
  int32_t* sself = (int32_t*)self;
  uint32_t uVar2;
  FUN_00533fa0(param_1, 1);
  uVar2 = 0;
  if (*(int32_t*)((char*)sself + 0xc0) != 0) {
    do {
      piVar1 = *(int32_t**)(*(int32_t*)((char*)sself + 0xb8) + uVar2 * 4);
      if (piVar1 != (int32_t*)0) {
        (*(void(*)(uint32_t))(*(void**)*piVar1)[0xd])(param_1);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint32_t*)((char*)sself + 0xc0));
  }
}

// 0x53b150 — observed shape: in_ECX[9] ? recursive FUN_0053b150 : FUN_00533c78(0x38)+FUN_00557940, refcounts, FUN_00534270(param_1,puVar4,0)
uint32_t FUN_0053b150(void* self, uint32_t param_1) {
  int32_t* piVar1;
  int32_t iVar2;
  uint32_t* puVar3;
  uint32_t* in_ECX = (uint32_t*)self;
  uint32_t* puVar4;
  uint32_t* local_4;
  puVar4 = nullptr;
  if (in_ECX[9] == 0) {
    iVar2 = FUN_00533c78(0x38);
    if (iVar2 != 0) {
      puVar3 = FUN_00557940();
      if (puVar3 != nullptr) {
        puVar3[1] = puVar3[1] + 1;
        puVar4 = puVar3;
      }
    }
  } else {
    local_4 = in_ECX;
    piVar1 = (int32_t*)FUN_0053b150(&local_4, (uint32_t)(uintptr_t)&local_4);
    puVar3 = (uint32_t*)*piVar1;
    if (puVar3 != nullptr) {
      puVar3[1] = puVar3[1] + 1;
      puVar4 = puVar3;
    }
    if ((local_4 != nullptr) && (iVar2 = local_4[1], local_4[1] = iVar2 + -1, iVar2 + -1 == 0)) {
      (*(void(*)(uint32_t*, int))(*(void**)*local_4)[0])(local_4, 1);
    }
  }
  FUN_00534270(param_1, puVar4, 0);
  if (puVar4 != nullptr) {
    uint32_t* piVar1b = puVar4 + 1;
    *piVar1b = *piVar1b + -1;
    if (*piVar1b == 0) {
      (*(void(*)(uint32_t*, int))(*(void**)*puVar4)[0])(puVar4, 1);
    }
  }
  return param_1;
}

// 0x53b1e0 — observed shape: param_2[3..5] linked lists + [6]/[7] singles, FUN_00535510 gate, FUN_00557340/FUN_0051ac30 branch, FUN_005575c0, empty-list early return, param_2==0 0x20 alloc w/ vftable, else FUN_0051ac30/LAB loop self+0xd0 FUN_00557530
uint32_t* FUN_0053b1e0(void* self, uint32_t* param_1, uint32_t* param_2, char param_3) {
  int32_t* piVar1;
  int32_t iVar2;
  int32_t iVar3;
  bool bVar4;
  char cVar5;
  uint32_t* puVar6;
  uint32_t uVar7;
  uint32_t* puVar8;
  int32_t* sself = (int32_t*)self;
  int32_t* piVar9;
  uint32_t* local_8;
  local_8 = param_2;
  if (param_2 != nullptr) {
    param_2[1] = param_2[1] + 1;
  }
  bVar4 = false;
  if (param_2 != nullptr) {
    for (int listIdx = 3; listIdx <= 5; ++listIdx) {
      piVar9 = (int32_t*)param_2[listIdx];
      if (piVar9 != nullptr) {
        do {
          iVar2 = piVar9[1];
          piVar9 = (int32_t*)*piVar9;
          if ((iVar2 != 0) && (cVar5 = FUN_00535510(sself), cVar5 != '\0')) {
            if (!bVar4) {
              puVar6 = FUN_00557340();
              if (local_8 != puVar6) {
                if (local_8 != nullptr) {
                  uint32_t* piVar1b = local_8 + 1;
                  *piVar1b = *piVar1b + -1;
                  if (*piVar1b == 0) (*(void(*)(uint32_t*, int))(*(void**)*local_8)[0])(local_8, 1);
                }
                local_8 = puVar6;
                if (puVar6 != nullptr) puVar6[1] = puVar6[1] + 1;
              }
              bVar4 = true;
            }
            FUN_005575c0(iVar2);
          }
        } while (piVar9 != nullptr);
      }
    }
    iVar2 = param_2[6];
    iVar3 = param_2[7];
    if ((iVar2 != 0) && (cVar5 = FUN_00535510(sself), cVar5 != '\0')) {
      if (!bVar4) { uVar7 = (uint32_t)(uintptr_t)FUN_00557340(); FUN_0051ac30((void*)(uintptr_t)uVar7); bVar4 = true; }
      FUN_005575c0(iVar2);
    }
    if ((iVar3 != 0) && (cVar5 = FUN_00535510(sself), cVar5 != '\0')) {
      if (!bVar4) { uVar7 = (uint32_t)(uintptr_t)FUN_00557340(); FUN_0051ac30((void*)(uintptr_t)uVar7); bVar4 = true; }
      FUN_005575c0(iVar3);
    }
  }
  if (*(int32_t*)((char*)sself + 0xd8) == 0) {
    *param_1 = (uint32_t)(uintptr_t)local_8;
    if (local_8 == nullptr) return param_1;
    iVar2 = local_8[1];
    local_8[1] = iVar2 + 1;
    local_8[1] = iVar2;
    if (iVar2 == 0) { (*(void(*)(uint32_t*, int))(*(void**)*local_8)[0])(local_8, 1); return param_1; }
    return param_1;
  }
  if (param_2 == nullptr) {
    puVar8 = (uint32_t*)(uintptr_t)FUN_00533c78(0x20);
    puVar6 = nullptr;
    if (puVar8 != nullptr) {
      *(void**)*puVar8 = PTR_LAB_006fd148;
      puVar8[1] = 0;
      DAT_00727444 = DAT_00727444 + 1;
      puVar8[3] = 0;
      puVar8[4] = 0;
      puVar8[5] = 0;
      puVar8[6] = 0;
      puVar8[7] = 0;
      *(void**)*puVar8 = PTR_FUN_006c0ba8;
      *(uint8_t*)(puVar8 + 2) = 0;
      puVar6 = puVar8;
    }
    if (local_8 != puVar6) {
      if (local_8 != nullptr) {
        int32_t* piVar9b = (int32_t*)local_8 + 1;
        *piVar9b = *piVar9b + -1;
        if (*piVar9b == 0) (*(void(*)(uint32_t*, int))(*(void**)*local_8)[0])(local_8, 1);
      }
      local_8 = puVar6;
      if (puVar6 != nullptr) puVar6[1] = puVar6[1] + 1;
    }
  } else {
    if (param_3 == '\0') {
      if (bVar4) goto LAB_0053b4a3;
    } else {
      if (bVar4) goto LAB_0053b4a3;
      param_2 = FUN_00557340();
    }
    FUN_0051ac30(param_2);
  }
LAB_0053b4a3:
  puVar6 = *(uint32_t**)((char*)sself + 0xd0);
  while (puVar6 != nullptr) {
    puVar8 = puVar6 + 2;
    puVar6 = (uint32_t*)*puVar6;
    FUN_00557530(*puVar8);
  }
  *param_1 = (uint32_t)(uintptr_t)local_8;
  if (local_8 != nullptr) {
    iVar2 = local_8[1];
    local_8[1] = iVar2 + 1;
    local_8[1] = iVar2;
    if (iVar2 == 0) (*(void(*)(uint32_t*, int))(*(void**)*local_8)[0])(local_8, 1);
  }
  return param_1;
}

// 0x53b680 — observed shape: linked insert-or-find by param_1 at node[2], alloc via vftable+4, +0xcc/+0xd0/+0xd4/+0xd8, FUN_00535670
void FUN_0053b680(void* self, int param_1) {
  uint32_t* puVar1;
  uint32_t* puVar2;
  int32_t* sself = (int32_t*)self;
  puVar2 = *(uint32_t**)((char*)sself + 0xd0);
  do {
    puVar1 = puVar2;
    if (puVar1 == nullptr) goto LAB_0053b6ab;
    puVar2 = (uint32_t*)*puVar1;
  } while (param_1 != (int)puVar1[2]);
  if (puVar1 == nullptr) {
LAB_0053b6ab:
    puVar2 = (uint32_t*)(*(void*(*)())(*(void**)*(int32_t*)((char*)sself + 0xcc))[1])();
    puVar2[2] = param_1;
    puVar2[1] = 0;
    *puVar2 = *(uint32_t*)((char*)sself + 0xd0);
    if (*(int32_t*)((char*)sself + 0xd0) == 0) {
      *(uint32_t**)((char*)sself + 0xd4) = puVar2;
    } else {
      *(uint32_t**)(*(int32_t*)((char*)sself + 0xd0) + 4) = puVar2;
    }
    *(int32_t*)((char*)sself + 0xd8) = *(int32_t*)((char*)sself + 0xd8) + 1;
    *(uint32_t**)((char*)sself + 0xd0) = puVar2;
    FUN_00535670(sself);
  }
}
// 0x53b6f0 — observed shape: FUN_00533ec0 gate, self+0xb8/self+0xc0 loop, vftable+0x40 first-nonzero return
int FUN_0053b6f0(void* self, uint32_t param_1) {
  int32_t* piVar1;
  int iVar2;
  int32_t* sself = (int32_t*)self;
  uint32_t uVar3;
  iVar2 = FUN_00533ec0(param_1);
  if (iVar2 == 0) {
    uVar3 = 0;
    if (*(int32_t*)((char*)sself + 0xc0) != 0) {
      if (*(int32_t*)((char*)sself + 0xc0) == 0) goto LAB_0053b72a;
      do {
        piVar1 = *(int32_t**)(*(int32_t*)((char*)sself + 0xb8) + uVar3 * 4);
        if ((piVar1 != nullptr) && (iVar2 = (*(int(*)(uint32_t))(*(void**)*piVar1)[0x10])(param_1), iVar2 != 0)) {
          return iVar2;
        }
LAB_0053b72a:
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(uint32_t*)((char*)sself + 0xc0));
    }
    iVar2 = 0;
  }
  return iVar2;
}

// 0x53b740 — observed shape: param_1+8/+4 chain, *param_2 vftable +4/+8, piVar2[2][iVar5*4] linked scan, FUN_0053b680
void FUN_0053b740(int param_1, int32_t* param_2) {
  int iVar1;
  int32_t* piVar2;
  uint32_t* puVar3;
  char cVar4;
  int iVar5;
  uint32_t uVar6;
  iVar1 = *(int32_t*)(param_1 + 8);
  do {
    if (iVar1 == 0) return;
    piVar2 = (int32_t*)*param_2;
    uVar6 = *(uint32_t*)(iVar1 + 8);
    iVar1 = *(int32_t*)(iVar1 + 4);
    iVar5 = (*(int(*)(uint32_t))(*(void**)*piVar2)[1])(uVar6);
    for (puVar3 = *(uint32_t**)(piVar2[2] + iVar5 * 4); puVar3 != nullptr; puVar3 = (uint32_t*)*puVar3) {
      cVar4 = (*(char(*)(uint32_t, uint32_t))(*(void**)*piVar2)[2])(uVar6, puVar3[1]);
      if (cVar4 != '\0') { uVar6 = puVar3[2]; break; }
    }
    FUN_0053b680(nullptr, (int)uVar6);
  } while (true);
}

// 0x53b7b0 — observed shape: FUN_00533f50 gate, self+0xb8/self+0xc0 vftable+0x14, self+0xd0 list node+2 ptr vftable+0x14
uint8_t FUN_0053b7b0(void* self, uint32_t param_1) {
  int32_t* piVar1;
  uint32_t* puVar2;
  char cVar3;
  int32_t* sself = (int32_t*)self;
  uint32_t uVar4;
  cVar3 = FUN_00533f50(param_1);
  if (cVar3 == '\0') return 0;
  uVar4 = 0;
  if (*(int32_t*)((char*)sself + 0xc0) != 0) {
    if (*(int32_t*)((char*)sself + 0xc0) == 0) goto LAB_0053b7eb;
    do {
      piVar1 = *(int32_t**)(*(int32_t*)((char*)sself + 0xb8) + uVar4 * 4);
      if (piVar1 != nullptr) (*(void(*)(uint32_t))(*(void**)*piVar1)[5])(param_1);
LAB_0053b7eb:
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint32_t*)((char*)sself + 0xc0));
  }
  puVar2 = *(uint32_t**)((char*)sself + 0xd0);
  while (puVar2 != nullptr) {
    int32_t* piVar1b = (int32_t*)puVar2 + 2;
    puVar2 = (uint32_t*)*puVar2;
    if (*(int32_t**)*piVar1b != nullptr) (*(void(*)(uint32_t))(*(void**)*(int32_t*)*piVar1b)[5])(param_1);
  }
  return 1;
}

// 0x53b820 — observed shape: FUN_00534810, piVar2[0x58] vftable+0xc, self+0xb8/self+0xc0 loop vftable+0x2c, iVar5=4 gate + self+0xd4 chain vftable+0x2c
void FUN_0053b820(int32_t* param_1) {
  uint32_t* puVar1;
  int32_t* piVar2;
  uint32_t uVar3;
  uint32_t count = 0;
  uint32_t uVar4;
  int iVar5;
  uint8_t auStack_2[2];
  void* self = *(void**)&param_1;
  int32_t* rself = (int32_t*)self;
  piVar2 = param_1;
  FUN_00534810(param_1);
  int32_t* param_1_copy = *(int32_t**)((char*)rself + 0xc0);
  iVar5 = 4;
  (*(void(*)(int32_t**))(*(void**)*(int32_t*)piVar2[0x58])[3])(&param_1_copy);
  uVar4 = 0;
  count = *(uint32_t*)((char*)rself + 0xc0);
  if (count != 0) {
    do {
      if (uVar4 < *(uint32_t*)((char*)rself + 0xc0)) {
        uVar3 = *(uint32_t*)(*(int32_t*)((char*)rself + 0xb8) + uVar4 * 4);
      } else {
        uVar3 = 0;
      }
      (*(void(*)(uint32_t))(*(void**)*piVar2)[0xb])(uVar3);
      uVar4 = uVar4 + 1;
    } while (uVar4 < count);
  }
  (*(void(*)(uint8_t*, int))(*(void**)*(int32_t*)piVar2[0x58])[3])(auStack_2 + 2, 4);
  if (0 < iVar5) {
    iVar5 = *(int32_t*)((char*)rself + 0xd4);
    while (iVar5 != 0) {
      puVar1 = (uint32_t*)(iVar5 + 8);
      iVar5 = *(int32_t*)(iVar5 + 4);
      (*(void(*)(uint32_t))(*(void**)*piVar2)[0xb])(*puVar1);
    }
  }
}

// 0x53b8d0 — observed shape: FUN_005348e0 gate, self+0xc0==param_1+0xc0, element vftable+0x1c, self+0xd8==param_1+0xd8 list pair walk
uint8_t FUN_0053b8d0(int param_1) {
  int32_t* piVar1;
  uint32_t uVar2;
  uint32_t* puVar3;
  uint32_t* puVar4;
  char cVar5;
  int iVar6;
  int32_t* sself = (int32_t*) *(void**)&param_1;
  int32_t* piVar7;
  uint32_t uVar8;
  cVar5 = FUN_005348e0(param_1);
  if (cVar5 == '\0') return 0;
  uVar2 = *(uint32_t*)((char*)sself + 0xc0);
  if (uVar2 != *(uint32_t*)(param_1 + 0xc0)) return 0;
  uVar8 = 0;
  if (uVar2 != 0) {
    do {
      if (uVar8 < *(uint32_t*)((char*)sself + 0xc0)) {
        piVar7 = *(int32_t**)(*(int32_t*)((char*)sself + 0xb8) + uVar8 * 4);
      } else {
        piVar7 = nullptr;
      }
      if (uVar8 < *(uint32_t*)(param_1 + 0xc0)) {
        iVar6 = *(int32_t*)(*(int32_t*)(param_1 + 0xb8) + uVar8 * 4);
      } else {
        iVar6 = 0;
      }
      if (piVar7 == nullptr) {
        if (iVar6 != 0) return 0;
      } else {
        if (iVar6 == 0) return 0;
        cVar5 = (*(char(*)(int))(*(void**)*piVar7)[7])(iVar6);
        if (cVar5 == '\0') return 0;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < uVar2);
  }
  if (*(int32_t*)((char*)sself + 0xd8) == *(int32_t*)(param_1 + 0xd8)) {
    if (*(int32_t*)((char*)sself + 0xd8) == 0) return 1;
    puVar3 = *(uint32_t**)((char*)sself + 0xd0);
    puVar4 = *(uint32_t**)(param_1 + 0xd0);
    do {
      while (true) {
        if (puVar3 == nullptr) return 1;
        int32_t* piVar7b = (int32_t*)puVar3 + 2;
        puVar3 = (uint32_t*)*puVar3;
        int32_t* piVar1b = (int32_t*)puVar4 + 2;
        puVar4 = (uint32_t*)*puVar4;
        iVar6 = *piVar1b;
        if (*(int32_t**)*piVar7b == nullptr) break;
        if (iVar6 == 0) return 0;
        cVar5 = (*(char(*)(int))(*(void**)*(int32_t*)*piVar7b)[7])(iVar6);
        if (cVar5 == '\0') return 0;
        (void)piVar1;
      }
    } while (iVar6 == 0);
  }
  return 0;
}

// 0x53b9c0 — observed shape: vftable PTR_FUN_006c0bd0, [2]=param_1 [5]=param_2 [3/4]=0, thunk alloc param_1*4+4, fill LAB_004c2970
void FUN_0053b9c0(void* self, int param_1, uint32_t param_2) {
  int32_t* piVar1;
  uint32_t* in_ECX = (uint32_t*)self;
  int32_t* piVar2 = nullptr;
  *(void**)*in_ECX = PTR_FUN_006c0bd0;
  in_ECX[2] = param_1;
  in_ECX[5] = param_2;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  if (param_1 != 0) {
    piVar1 = (int32_t*)(uintptr_t)0;
    // thunk_FUN_00533c78 observed as extern helper via FUN_00533c78
    {
      extern int FUN_00533c78(int);
      piVar1 = (int32_t*)(uintptr_t)FUN_00533c78(param_1 * 4 + 4);
    }
    if (piVar1 != nullptr) {
      piVar2 = piVar1 + 1;
      *piVar1 = param_1;
      FUN_004127b0(piVar2, 4, param_1, LAB_004c2970);
    }
  }
  in_ECX[1] = (uint32_t)(uintptr_t)piVar2;
}

// 0x53ba20 — observed shape: self+0xc<=param_2 early, self+4 array slot puVar3 addref, old slot dec-ref-null, self+0x10--, self+0xc trim, return param_1 out
int32_t* FUN_0053ba20(void* self, int32_t* param_1, uint32_t param_2) {
  int32_t* piVar1 = nullptr;
  int32_t iVar2;
  uint32_t* puVar3;
  int iVar4;
  uint32_t* puVar5;
  uint32_t uVar6;
  int32_t* sself = (int32_t*)self;
  if (*(uint32_t*)((char*)sself + 0xc) <= param_2) {
    *param_1 = 0;
    return param_1;
  }
  iVar2 = param_2 * 4;
  puVar3 = *(uint32_t**)(iVar2 + *(int32_t*)((char*)sself + 4));
  if (puVar3 != nullptr) puVar3[1] = puVar3[1] + 1;
  iVar4 = *(int32_t*)((char*)sself + 4);
  puVar5 = *(uint32_t**)(iVar4 + iVar2);
  if (puVar5 != nullptr) {
    uint32_t* piVar1b = puVar5 + 1;
    *piVar1b = *piVar1b + -1;
    if (*piVar1b == 0) (*(void(*)(uint32_t*, int))(*(void**)*puVar5)[0])(puVar5, 1);
    *(uint32_t*)(iVar4 + iVar2) = 0;
  }
  if (puVar3 != nullptr) *(int32_t*)((char*)sself + 0x10) = *(int32_t*)((char*)sself + 0x10) + -1;
  uVar6 = *(int32_t*)((char*)sself + 0xc) - 1;
  if (param_2 == uVar6) *(uint32_t*)((char*)sself + 0xc) = uVar6;
  *param_1 = (int32_t)(uintptr_t)puVar3;
  if (puVar3 != nullptr) {
    iVar2 = puVar3[1];
    puVar3[1] = iVar2 + 1;
    puVar3[1] = iVar2;
    if (iVar2 == 0) (*(void(*)(uint32_t*, int))(*(void**)*puVar3)[0])(puVar3, 1);
  }
  (void)piVar1; (void)iVar4;
  return param_1;
}

// 0x53bac0 — observed shape: vftable PTR_FUN_006c0bd0, in_ECX[1] tail-back walk release loop, operator_delete__(ptr-4)
void FUN_0053bac0(void* self) {
  int32_t* piVar1;
  int32_t iVar2;
  uint32_t* puVar3;
  uint32_t* in_ECX = (uint32_t*)self;
  int iVar4;
  int iVar5;
  *(void**)*in_ECX = PTR_FUN_006c0bd0;
  iVar2 = in_ECX[1];
  if (iVar2 != 0) {
    iVar4 = *(int32_t*)(iVar2 + -4);
    iVar5 = iVar2 + iVar4 * 4;
    if (-1 < iVar4 + -1) {
      do {
        puVar3 = *(uint32_t**)(iVar5 + -4);
        iVar5 = iVar5 + -4;
        if (puVar3 != nullptr) {
          uint32_t* piVar1b = puVar3 + 1;
          *piVar1b = *piVar1b + -1;
          if (*piVar1b == 0) (*(void(*)(uint32_t*, int))(*(void**)*puVar3)[0])(puVar3, 1);
        }
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    operator_delete__((void*)(iVar2 + -4));
  }
}

// 0x53bb10 — observed shape: FUN_0053bac0 + (param_1&1) operator_delete(self)
void FUN_0053bb10(void* self, uint8_t param_1) {
  FUN_0053bac0(self);
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x53bb30 — observed shape: FUN_005349d0, vftable PTR_FUN_006c0bd8, FUN_0053b9c0(param_1,1), [0x33..0x36] zero + [0x33]=PTR_FUN_006c0bc4
void FUN_0053bb30(void* self, uint32_t param_1) {
  uint32_t* in_ECX = (uint32_t*)self;
  FUN_005349d0();
  *(void**)*in_ECX = PTR_FUN_006c0bd8;
  FUN_0053b9c0((int)param_1, 1);
  in_ECX[0x36] = 0;
  in_ECX[0x34] = 0;
  in_ECX[0x35] = 0;
  in_ECX[0x33] = (uint32_t)(uintptr_t)PTR_FUN_006c0bc4;
}
