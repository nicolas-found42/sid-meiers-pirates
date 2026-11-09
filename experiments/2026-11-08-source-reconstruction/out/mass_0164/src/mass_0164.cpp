#include <cstdint>
#include <cstddef>
#include <cmath>
#include <windows.h>

extern void* operator_new(std::size_t);
extern void __cdecl operator_delete(void* p);
extern void __cdecl operator_delete__(void* p);
extern uint32_t FUN_005685b0(void* self);
extern uint32_t FUN_00552d20();
extern void* FUN_00533c78(uint32_t size);
extern void FUN_005383d0();
extern void FUN_00577d90(void* param_2,int param_1,uint32_t param_3);
extern void FUN_00568480(void* self);
extern void* FUN_0054a8f0(void* a,void* b,void* c,void* d,void* e);
extern void FUN_004c2c80(void* p);
extern void FUN_004c2c40(float v);
extern void FUN_004c2ba0(void* p);

// 0x5685b0 — observed shape
uint32_t FUN_005685b0(void* self) {
  auto* s = static_cast<unsigned char*>(self);
  // CONCAT31((int3)(x>>8),1) observed as value != 0 with low byte 1
  if (*reinterpret_cast<int32_t*>(s + 0x4c) != 0) {
    int32_t v = *reinterpret_cast<int32_t*>(s + 0x4c);
    return static_cast<uint32_t>((v & 0xffffff) | 0x01000000);
  }
  int32_t iVar1 = *reinterpret_cast<int32_t*>(s + 0x34);
  if (iVar1 == 0) {
    return 0;
  }
  uint32_t uVar2 = *reinterpret_cast<uint32_t*>(s + 0x54);
  if (s[0x50] == '\0') {
    iVar1 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(reinterpret_cast<char*>(iVar1) + 0x2c) + uVar2 * 4);
    *reinterpret_cast<int32_t*>(s + 0x4c) = iVar1;
    return static_cast<uint32_t>((iVar1 & 0xffffff) | (iVar1 != 0 ? 0x01000000 : 0));
  }
  iVar1 = *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(iVar1) + 0x44);
  if ((iVar1 == 0) || (*reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(iVar1) + 0xc) <= uVar2)) {
    *reinterpret_cast<uint32_t*>(s + 0x4c) = 0;
    return 0;
  }
  iVar1 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(reinterpret_cast<char*>(iVar1) + 4) + uVar2 * 4);
  *reinterpret_cast<int32_t*>(s + 0x4c) = iVar1;
  return static_cast<uint32_t>((iVar1 & 0xffffff) | (iVar1 != 0 ? 0x01000000 : 0));
}

// 0x568640 — observed shape
void FUN_00568640(void* self, uint8_t param_1) {
  auto* s = static_cast<int32_t*>(self);
  *reinterpret_cast<void**>(s) = reinterpret_cast<void*>(0x6c3be0);
  int32_t* puVar2 = *reinterpret_cast<int32_t**>(reinterpret_cast<char*>(s) + 0x48);
  if (puVar2 != nullptr) {
    int32_t* piVar1 = puVar2 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      auto fn = *reinterpret_cast<void(**)(void*,int)>(puVar2);
      fn(puVar2, 1);
    }
  }
  FUN_00552d20();
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x568680 — observed shape
uint32_t FUN_00568680(void* self, int32_t param_1, int32_t param_2) {
  auto* s = static_cast<int32_t*>(self);
  s[0x13] = param_1;
  if (param_1 == 0) {
    return 1;
  }
  if (param_2 == 0) {
    if (s[0xd] == 0) {
      return 0;
    }
  } else if (s[0xd] == 0) {
    using VFn = void(*)(void*,int32_t);
    VFn vf = *reinterpret_cast<VFn*>(reinterpret_cast<char*>(*reinterpret_cast<int32_t**>(s)) + 0x40);
    vf(self, param_2);
  }
  int32_t iVar1 = s[0xd];
  uint32_t uVar2 = 0;
  if (*reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(iVar1) + 0x34) != 0) {
    int32_t* piVar3 = *reinterpret_cast<int32_t**>(reinterpret_cast<char*>(iVar1) + 0x2c);
    do {
      if (*piVar3 == param_1) {
        s[0x15] = static_cast<int32_t>(uVar2);
        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(s) + 0x50) = 0;
        return 1;
      }
      uVar2 = uVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (uVar2 < *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(iVar1) + 0x34));
  }
  iVar1 = *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(iVar1) + 0x44);
  for (uVar2 = 0; (iVar1 != 0 && (uVar2 < *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(iVar1) + 0xc))); uVar2 = uVar2 + 1) {
    if (*reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(reinterpret_cast<char*>(iVar1) + 4) + uVar2 * 4) == param_1) {
      s[0x15] = static_cast<int32_t>(uVar2);
      *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(s) + 0x50) = 1;
      return 1;
    }
  }
  return 0;
}

// 0x568720 — observed shape
void FUN_00568720(void* self, int32_t param_1, uint32_t* param_2, uint32_t param_3) {
  auto* s = static_cast<unsigned char*>(self);
  if (*reinterpret_cast<int32_t*>(s + 0x48) == 0) {
    uint32_t* puVar3 = static_cast<uint32_t*>(FUN_00533c78(0x18));
    if (puVar3 != nullptr) {
      FUN_005383d0();
      puVar3[0] = 0x6fe39c;
      puVar3[3] = 0;
      puVar3[4] = 0;
      puVar3[5] = 0;
    }
    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(s + 0x48);
    if (puVar2 != puVar3) {
      if (puVar2 != nullptr) {
        int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          auto fn = *reinterpret_cast<void(**)(void*,int)>(puVar2);
          fn(puVar2, 1);
        }
      }
      *reinterpret_cast<uint32_t**>(s + 0x48) = puVar3;
      if (puVar3 != nullptr) {
        puVar3[1] = puVar3[1] + 1;
      }
    }
  }
  FUN_00577d90(param_2, param_1, param_3);
  *reinterpret_cast<uint32_t*>(s + 0x44) = 0;
  *reinterpret_cast<uint32_t*>(s + 0x18) = *param_2;
  *reinterpret_cast<uint32_t*>(s + 0x1c) =
       *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(reinterpret_cast<uintptr_t>(param_2)) + static_cast<uint32_t>(*reinterpret_cast<uint8_t*>(reinterpret_cast<uint32_t*>(param_2) + 1)) * static_cast<uint32_t>(param_1 - 1));
  FUN_00568480(self);
}

// 0x568960 — observed shape
void FUN_00568960(void* self, float param_1, uint32_t param_2, char param_3) {
  (void)param_2;
  char cVar1 = static_cast<char>(FUN_005685b0(self));
  if (cVar1 == '\0') {
    return;
  }
  int32_t* s = static_cast<int32_t*>(self);
  if (s[0x13] == 0) {
    return;
  }
  auto* p13 = reinterpret_cast<char*>(static_cast<uintptr_t>(static_cast<uint32_t>(s[0x13])));
  int32_t* piVar3 = *reinterpret_cast<int32_t**>(p13 + 0x18);
  if (piVar3 == nullptr) {
    int32_t iVar2 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_00533c78(0x48)));
    if (iVar2 == 0) {
      piVar3 = nullptr;
    } else {
      uint32_t local_18 = 0x3f000000;
      uint32_t local_14 = 0x3f000000;
      uint32_t local_10 = 0x3f800000;
      uint32_t local_c = 0x3f800000;
      int32_t* local_8 = piVar3;
      int32_t* local_4 = piVar3;
      (void)local_14;
      (void)local_c;
      piVar3 = reinterpret_cast<int32_t*>(FUN_0054a8f0(&local_8, nullptr, &local_10, &local_18, nullptr));
    }
    *reinterpret_cast<int32_t**>(p13 + 0x18) = piVar3;
  }
  if (param_3 != '\0') {
    int32_t iVar2 = 0;
    bool assign = true;
    switch (s[0x16]) {
      case 0: s[0x17] = piVar3[0]; assign = false; break;
      case 1: s[0x17] = piVar3[1]; assign = false; break;
      case 2: iVar2 = piVar3[2]; break;
      case 3: iVar2 = piVar3[3]; break;
      case 4: iVar2 = piVar3[4]; break;
      default: assign = false; break;
    }
    if (assign) s[0x17] = iVar2;
  }
  *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(s) + 0x10) = 1;
  using VFn = void(*)(void*,float);
  VFn vf = *reinterpret_cast<VFn*>(reinterpret_cast<char*>(*reinterpret_cast<int32_t**>(s)) + 0x3c);
  vf(self, param_1);
  switch (s[0x16]) {
    case 0:
      FUN_004c2c80(nullptr);
      return;
    case 1:
      FUN_004c2c80(nullptr);
      return;
    case 2:
      FUN_004c2c40(param_1 * static_cast<float>(piVar3[2]) + (1.0f - param_1) * static_cast<float>(s[0x17]));
      return;
    case 3:
      FUN_004c2ba0(nullptr);
      return;
    case 4:
      FUN_004c2ba0(nullptr);
      break;
    default:
      break;
  }
}
// 0x568ca0 — observed shape
void FUN_00568ca0(void* self, int32_t param_1, uint32_t param_2) {
  auto* s = static_cast<unsigned char*>(self);
  auto* dst = reinterpret_cast<unsigned char*>(param_1);
  extern void FUN_00552aa0(int32_t, uint32_t);
  FUN_00552aa0(param_1, param_2);
  *reinterpret_cast<uint32_t*>(dst + 0x44) = *reinterpret_cast<uint32_t*>(s + 0x44);
  *(dst + 0x50) = *(s + 0x50);
  *reinterpret_cast<uint32_t*>(dst + 0x54) = *reinterpret_cast<uint32_t*>(s + 0x54);
  *reinterpret_cast<uint32_t*>(dst + 0x58) = *reinterpret_cast<uint32_t*>(s + 0x58);
  if (*reinterpret_cast<int32_t**>(s + 0x48) != nullptr) {
    auto* vtbl = *reinterpret_cast<int32_t**>(s + 0x48);
    using CloneFn = void*(*)(void*,uint32_t);
    CloneFn cloneFn = *reinterpret_cast<CloneFn*>(reinterpret_cast<char*>(*vtbl) + 8);
    // Pseudocode: (**((int**)(in_ECX+0x48) + 8))(param_2) — preserved as vtbl+8 call
    uint32_t* puVar3 = static_cast<uint32_t*>(cloneFn(vtbl, param_2));
    // Fallback matching observed int** dereference if clone returns table ptr
    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(dst + 0x48);
    if (puVar2 != puVar3) {
      if (puVar2 != nullptr) {
        int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          auto fn = *reinterpret_cast<void(**)(void*,int)>(puVar2);
          fn(puVar2, 1);
        }
      }
      *reinterpret_cast<uint32_t**>(dst + 0x48) = puVar3;
      if (puVar3 != nullptr) {
        puVar3[1] = puVar3[1] + 1;
      }
    }
    FUN_00568480(self);
  }
}

// 0x568de0 — observed shape
uint32_t* FUN_00568de0(uint32_t param_1) {
  extern void FUN_00552c80();
  extern void FUN_00552e30(int);
  uint32_t* puVar1 = static_cast<uint32_t*>(FUN_00533c78(0x60));
  if (puVar1 == nullptr) {
    FUN_00568ca0(nullptr, 0, param_1);
    return nullptr;
  }
  FUN_00552c80();
  puVar1[0] = 0x6c3be0;
  puVar1[0x12] = 0;
  puVar1[0x16] = 0;
  puVar1[0x11] = 0;
  *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(puVar1) + 0x50) = 0;
  puVar1[0x15] = 0;
  FUN_00552e30(0);
  puVar1[0x13] = 0;
  FUN_00568480(puVar1);
  FUN_00568ca0(puVar1, static_cast<int32_t>(reinterpret_cast<uintptr_t>(puVar1)), param_1);
  return puVar1;
}

// 0x568eb0 — observed shape
void FUN_00568eb0(int32_t param_1) {
  extern void FUN_005531c0(int32_t);
  extern int32_t FUN_00557b10(uint32_t);
  extern void FUN_006b34a0(int32_t);
  extern void FUN_005606f0(uint32_t, int32_t*);
  extern uint32_t DAT_00728374;
  int32_t iVar2 = param_1;
  FUN_005531c0(param_1);
  int32_t param = FUN_00557b10(DAT_00728374);
  uint32_t uVar1 = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(iVar2) + 0xc);
  if (*reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(iVar2) + 8) <= uVar1) {
    FUN_006b34a0(*reinterpret_cast<int32_t*>(reinterpret_cast<char*>(iVar2) + 0x14) + static_cast<int32_t>(uVar1));
  }
  FUN_005606f0(uVar1, &param);
}

// 0x5690e0 — observed shape
void FUN_005690e0() {
  extern uint32_t* DAT_007289e4;
  extern uint32_t DAT_007289e0;
  uint32_t* puVar2 = DAT_007289e4;
  while (puVar2 != nullptr) {
    uint32_t* puVar1 = reinterpret_cast<uint32_t*>(*puVar2);
    operator_delete__(puVar2);
    puVar2 = puVar1;
  }
  DAT_007289e4 = nullptr;
  DAT_007289e0 = 0;
}

// 0x5692c0 — observed shape
void FUN_005692c0(uint32_t param_1) {
  extern void FUN_00576700(uint32_t);
  extern void FUN_00535110(uint32_t);
  FUN_00576700(param_1);
  FUN_00535110(param_1);
}
// 0x5692e0 — observed shape
void FUN_005692e0(uint32_t param_1, uint32_t param_2) {
  extern void FUN_00576720(uint32_t, uint32_t);
  extern void FUN_00535150(uint32_t);
  FUN_00576720(param_1, param_2);
  FUN_00535150(param_1);
}

// 0x569330 — observed shape
void FUN_00569330(float* param_1, float param_2, float* param_3, int32_t param_4, float param_5, int32_t* param_6) {
  extern void* DAT_00728844;
  int32_t iVar5 = static_cast<int32_t>(param_5);
  if (param_5 == 1.4013e-45f) {
    param_1[0] = param_3[2];
    param_1[1] = param_3[3];
    param_1[2] = param_3[4];
    return;
  }
  uint32_t uVar1 = static_cast<uint32_t>(static_cast<int32_t>(param_5) - 1);
  float fVar3 = 0.0f; // fVar3 uninitialized until set in path
  uint32_t uVar6;
  float fVar2;
  // param_5 = *(float *)((uint)*(byte *)(param_3+1) * *param_6 + (int)param_3)
  uint8_t stride = *reinterpret_cast<uint8_t*>(reinterpret_cast<uint32_t*>(param_3) + 1);
  float cur = *reinterpret_cast<float*>(static_cast<uintptr_t>(reinterpret_cast<uintptr_t>(param_3)) + static_cast<uint32_t>(stride) * static_cast<uint32_t>(*param_6));
  param_5 = cur;
  if (param_2 < param_5) {
    *param_6 = 0;
    param_5 = *param_3;
  }
  uVar6 = static_cast<uint32_t>(*param_6 + 1);
  // Helper lambda for NAN checks via standard library
  auto is_nan = [](float v){ return v != v; };
  bool done = false;
  if (3 < static_cast<int32_t>((uVar1 - uVar6) + 1)) {
    int32_t iVar7 = *param_6 + 3;
    do {
      fVar2 = *reinterpret_cast<float*>(static_cast<uintptr_t>(reinterpret_cast<uintptr_t>(param_3)) + static_cast<uint32_t>(stride) * uVar6);
      fVar3 = fVar2;
      if (!is_nan(param_2) && !is_nan(fVar2) && ((param_2 < fVar2) != (param_2 == fVar2))) { done = true; break; }
      int32_t iVar4 = *param_6;
      *param_6 = iVar4 + 1;
      param_5 = *reinterpret_cast<float*>(static_cast<uintptr_t>(reinterpret_cast<uintptr_t>(param_3)) + static_cast<uint32_t>(iVar7 - 1) * static_cast<uint32_t>(stride));
      if (!is_nan(param_2) && !is_nan(param_5) && ((param_2 < param_5) != (param_2 == param_5))) {
        uVar6 = uVar6 + 1; fVar3 = param_5; param_5 = fVar2; done = true; break;
      }
      *param_6 = iVar4 + 2;
      fVar2 = *reinterpret_cast<float*>(static_cast<uintptr_t>(reinterpret_cast<uintptr_t>(param_3)) + static_cast<uint32_t>(stride) * static_cast<uint32_t>(iVar7));
      if (!is_nan(param_2) && !is_nan(fVar2) && ((param_2 < fVar2) != (param_2 == fVar2))) {
        uVar6 = uVar6 + 2; fVar3 = fVar2; done = true; break;
      }
      *param_6 = iVar4 + 3;
      param_5 = *reinterpret_cast<float*>(static_cast<uintptr_t>(reinterpret_cast<uintptr_t>(param_3)) + static_cast<uint32_t>(iVar7 + 1) * static_cast<uint32_t>(stride));
      if (!is_nan(param_2) && !is_nan(param_5) && ((param_2 < param_5) != (param_2 == param_5))) {
        uVar6 = uVar6 + 3; fVar3 = param_5; param_5 = fVar2; done = true; break;
      }
      *param_6 = iVar4 + 4;
      uVar6 = uVar6 + 4;
      iVar7 = iVar7 + 4;
    } while (uVar6 <= static_cast<uint32_t>(iVar5 - 4));
  }
  if (!done) {
    while (true) {
      fVar3 = param_5;
      if (!(uVar6 <= uVar1)) break;
      fVar3 = *reinterpret_cast<float*>(static_cast<uintptr_t>(reinterpret_cast<uintptr_t>(param_3)) + static_cast<uint32_t>(stride) * uVar6);
      if (!(is_nan(param_2) || is_nan(fVar3) || ((param_2 < fVar3) == (param_2 == fVar3)))) break;
      uVar6 = uVar6 + 1;
      *param_6 = *param_6 + 1;
      param_5 = fVar3;
    }
  }
  float local_c = 0.0f; float fStack_8 = 0.0f; float fStack_4 = 0.0f;
  // Indirect call table at DAT_00728844 indexed by param_4
  auto* table = reinterpret_cast<void**>(&DAT_00728844);
  using InterpFn = void(*)(float, float*, float*, float*);
  InterpFn fn = reinterpret_cast<InterpFn>(table[param_4]);
  float* pA = reinterpret_cast<float*>(static_cast<uintptr_t>(reinterpret_cast<uintptr_t>(param_3)) + static_cast<uint32_t>(*param_6) * static_cast<uint32_t>(stride));
  float* pB = reinterpret_cast<float*>(static_cast<uintptr_t>(reinterpret_cast<uintptr_t>(param_3)) + static_cast<uint32_t>(stride) * uVar6);
  fn((param_2 - param_5) / (fVar3 - param_5), pA, pB, &local_c);
  param_1[0] = local_c;
  param_1[1] = fStack_8;
  param_1[2] = fStack_4;
}

// 0x5694f0 — observed shape
float* FUN_005694f0(float* param_1, float param_2, float* param_3, uint32_t param_4, int32_t param_5) {
  extern float DAT_00728388;
  extern float DAT_0072838c;
  extern float DAT_00728390;
  int32_t iVar1 = param_5;
  if (param_5 == 0) {
    param_1[0] = DAT_00728388;
    param_1[1] = DAT_0072838c;
    param_1[2] = DAT_00728390;
    return param_1;
  }
  if (*param_3 <= param_2) {
    uint8_t stride = *reinterpret_cast<uint8_t*>(reinterpret_cast<uint32_t*>(param_3) + 1);
    float end = *reinterpret_cast<float*>(static_cast<uintptr_t>(reinterpret_cast<uintptr_t>(param_3)) + static_cast<uint32_t>(param_5 - 1) * static_cast<uint32_t>(stride));
    if (param_2 <= end) {
      int32_t p5 = 0;
      FUN_00569330(param_1, param_2, param_3, static_cast<int32_t>(param_4), static_cast<float>(iVar1), &p5);
      return param_1;
    }
    param_3 = reinterpret_cast<float*>(static_cast<uintptr_t>(reinterpret_cast<uintptr_t>(param_3)) + static_cast<uint32_t>(param_5 - 1) * static_cast<uint32_t>(stride) + 8);
  } else {
    param_3 = param_3 + 2;
  }
  param_1[0] = *param_3;
  param_1[1] = param_3[1];
  param_1[2] = param_3[2];
  return param_1;
}

// 0x5695a0 — observed shape
uint32_t FUN_005695a0(int32_t param_1, int32_t param_2) {
  extern uint32_t FUN_00576290(int32_t, int32_t);
  uint32_t uVar1 = FUN_00576290(param_1, param_2);
  if (static_cast<char>(uVar1) == '\0') {
    return uVar1;
  }
  float a8 = *reinterpret_cast<float*>(reinterpret_cast<char*>(param_1) + 8);
  float b8 = *reinterpret_cast<float*>(reinterpret_cast<char*>(param_2) + 8);
  float ac = *reinterpret_cast<float*>(reinterpret_cast<char*>(param_1) + 0xc);
  float bc = *reinterpret_cast<float*>(reinterpret_cast<char*>(param_2) + 0xc);
  float a10 = *reinterpret_cast<float*>(reinterpret_cast<char*>(param_1) + 0x10);
  float b10 = *reinterpret_cast<float*>(reinterpret_cast<char*>(param_2) + 0x10);
  if ((a8 == b8) && (ac == bc) && (a10 == b10)) {
    return 1;
  }
  return 0;
}

// 0x569600 — observed shape
void FUN_00569600(uint32_t param_1, uint32_t param_2, uint32_t param_3, int32_t param_4, float* param_5, float* param_6, float* param_7, float* param_8) {
  extern void* DAT_00728754;
  extern void* DAT_007287cc;
  using EvalFn = void(*)(uint32_t, uint32_t, uint32_t, float*);
  auto* table1 = reinterpret_cast<EvalFn*>(&DAT_00728754);
  auto* table2 = reinterpret_cast<EvalFn*>(&DAT_007287cc);
  EvalFn pcVar9 = table1[param_4];
  EvalFn fn2 = table2[param_4];
  float local_30 = 0.0f; float fStack_2c = 0.0f; float fStack_28 = 0.0f;
  float fStack_24 = 0.0f; float fStack_20 = 0.0f; float fStack_1c = 0.0f;
  fn2(param_1, param_2, param_3, &local_30);
  pcVar9(param_1, param_2, param_3, &fStack_24);
  // Note: pseudocode stack layout reuses fStack_2c/28 etc. Preserve arithmetic using locals
  float fVar1 = local_30 * local_30 + fStack_2c * fStack_2c + fStack_28 * fStack_28;
  float fVar2 = 1.0f / sqrtf(fVar1);
  float fStack_18 = local_30 * fVar2;
  param_5[0] = fStack_18;
  float fStack_14 = fStack_2c * fVar2;
  param_5[1] = fStack_14;
  float fStack_10 = fStack_28 * fVar2;
  param_5[2] = fStack_10;
  float fVar5 = fStack_1c * fStack_2c - fStack_20 * fStack_28;
  float fVar4 = fStack_28 * fStack_24 - fStack_1c * local_30;
  float fVar3 = fStack_20 * local_30 - fStack_2c * fStack_24;
  fVar2 = sqrtf(fVar5 * fVar5 + fVar4 * fVar4 + fVar3 * fVar3) * fVar2 * fVar2;
  param_8[0] = fVar2;
  if (fabsf(fVar2) <= 1e-06f) {
    param_8[0] = 0.0f;
    if ((1e-06f < fabsf(param_5[0])) || (1e-06f < fabsf(param_5[1]))) {
      param_6[0] = param_5[1];
      fVar1 = param_5[0];
      param_6[2] = 0.0f;
    } else {
      param_6[2] = param_5[1];
      fVar1 = param_5[2];
      param_6[0] = 0.0f;
    }
    param_6[1] = -fVar1;
  } else {
    fVar2 = fStack_24 * local_30 + fStack_20 * fStack_2c + fStack_1c * fStack_28;
    // Stack copies observed as fStack_8/4 etc.
    float fStack_8 = fStack_2c * fVar2;
    float fStack_4 = fStack_28 * fVar2;
    float v20 = fStack_20 * fVar1;
    float v1c = fStack_1c * fVar1;
    fStack_18 = fStack_24 * fVar1 - local_30 * fVar2;
    param_6[0] = fStack_18;
    float fStack_14b = v20 - fStack_8;
    param_6[1] = fStack_14b;
    float fStack_10b = v1c - fStack_4;
    param_6[2] = fStack_10b;
  }
  // FUN_00491640() observed with no args
  // Preserve call
  extern void FUN_00491640();
  FUN_00491640();
  float fVar1b = param_5[2];
  float fVar2b = param_6[0];
  float fVar3b = param_5[0];
  float fVar4b = param_6[2];
  float fVar5b = param_6[1];
  float fVar6b = param_5[0];
  float fVar7b = param_5[1];
  float fVar8b = param_6[0];
  param_7[0] = param_5[1] * param_6[2] - param_5[2] * param_6[1];
  param_7[1] = fVar1b * fVar2b - fVar3b * fVar4b;
  param_7[2] = fVar5b * fVar6b - fVar7b * fVar8b;
}
// 0x569850 — observed shape
void FUN_00569850(int32_t param_1, int32_t param_2) {
  extern void* DAT_007288a8;
  extern void* DAT_00728830;
  extern void* DAT_007287b8;
  extern void* DAT_00728740;
  extern void* DAT_007286c8;
  extern void* DAT_007283f8;
  extern uint32_t DAT_00728470;
  extern void LAB_00569320();
  extern void LAB_00569300();
  extern uint32_t FUN_005695a0(int32_t, int32_t);
  extern uint32_t FUN_00497420();
  int32_t iVar1 = (param_2 + param_1 * 5) * 4;
  *reinterpret_cast<void**>(reinterpret_cast<char*>(&DAT_007288a8) + iVar1) = reinterpret_cast<void*>(&LAB_00569320);
  *reinterpret_cast<void**>(reinterpret_cast<char*>(&DAT_00728830) + iVar1) = reinterpret_cast<void*>(&LAB_00569300);
  *reinterpret_cast<void**>(reinterpret_cast<char*>(&DAT_007287b8) + iVar1) = reinterpret_cast<void*>(&LAB_00569300);
  *reinterpret_cast<void**>(reinterpret_cast<char*>(&DAT_00728740) + iVar1) = reinterpret_cast<void*>(&LAB_00569300);
  *reinterpret_cast<void**>(reinterpret_cast<char*>(&DAT_007286c8) + iVar1) = reinterpret_cast<void*>(&FUN_005695a0);
  *reinterpret_cast<void**>(reinterpret_cast<char*>(&DAT_007283f8) + iVar1) = reinterpret_cast<void*>(&FUN_00497420);
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(&DAT_00728470) + iVar1) = 0;
}

// 0x5698b0 — observed shape
uint32_t FUN_005698b0() {
  extern uint8_t DAT_00728384;
  extern void* _DAT_00728934;
  extern void* _DAT_00728664;
  extern void* _DAT_007285ec;
  extern void* _DAT_00728574;
  extern void* _DAT_007284fc;
  extern uint32_t FUN_004aaef0();
  extern uint32_t FUN_00497420();
  if (DAT_00728384 == 0) {
    DAT_00728384 = 1;
    _DAT_00728934 = reinterpret_cast<void*>(&FUN_004aaef0);
    _DAT_00728664 = reinterpret_cast<void*>(&FUN_00497420);
    _DAT_007285ec = reinterpret_cast<void*>(&FUN_00497420);
    _DAT_00728574 = reinterpret_cast<void*>(&FUN_004aaef0);
    _DAT_007284fc = reinterpret_cast<void*>(&FUN_00497420);
    FUN_00569850(1, 0);
    return 1;
  }
  return 0;
}

// 0x569960 — observed shape
void FUN_00569960(void* self) {
  extern void* DAT_007284e8;
  int32_t* piVar2 = reinterpret_cast<int32_t*>(reinterpret_cast<char*>(self) + 0x34);
  int32_t iVar1 = 3;
  do {
    if (*piVar2 != 0) {
      using Fn = void(*)(int32_t);
      auto* table = reinterpret_cast<Fn*>(&DAT_007284e8);
      Fn fn = table[piVar2[-4]];
      fn(*piVar2);
    }
    *piVar2 = 0;
    piVar2[-7] = 0;
    piVar2[-4] = 0;
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
}

// 0x5699a0 — observed shape
void FUN_005699a0(uint32_t param_1, int32_t param_2, uint32_t param_3, uint32_t* param_4) {
  extern float FUN_0056a5f0(uint32_t, int32_t, int32_t, int32_t, int32_t*);
  extern void FUN_00555e70(float, void*);
  extern uint32_t* FUN_00555bc0(float*, uint32_t*);
  extern void* DAT_007177ac;
  extern void* DAT_007177b8;
  extern void* DAT_007177c4;
  (void)param_3;
  float local_50[4];
  uint32_t local_40 = 0x3f800000; uint32_t local_3c = 0; uint32_t local_38 = 0; uint32_t local_34 = 0;
  uint32_t uVar2 = 0;
  int32_t* piVar3 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(param_2) + 0x18);
  do {
    if (*piVar3 == 0) {
      local_50[uVar2] = 0.0f;
    } else {
      float fVar4 = FUN_0056a5f0(param_1, piVar3[7], piVar3[3], *piVar3, piVar3 + 10);
      local_50[uVar2] = fVar4;
    }
    uVar2 = uVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (uVar2 < 3);
  FUN_00555e70(local_50[0], &DAT_007177ac);
  FUN_00555e70(local_50[1], &DAT_007177b8);
  FUN_00555e70(local_50[2], &DAT_007177c4);
  // CRect::CRect((CRect *)&local_40,0x3f800000,0,0,0) — observed as four dwords
  // Already set above to 0x3f800000,0,0,0
  uVar2 = 0;
  do {
    uint32_t* puVar1 = FUN_00555bc0(local_50, &local_40);
    local_40 = puVar1[0];
    local_3c = puVar1[1];
    local_38 = puVar1[2];
    local_34 = puVar1[3];
    uVar2 = uVar2 + 1;
  } while (uVar2 < 3);
  param_4[0] = local_40;
  param_4[1] = local_3c;
  param_4[2] = local_38;
  param_4[3] = local_34;
}

// 0x569b40 — observed shape
void FUN_00569b40(int32_t param_1, int32_t param_2) {
  extern void* DAT_00728560;
  extern void* DAT_007285d8;
  *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(param_1) + 0x30) = *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(param_2) + 0x30);
  int32_t* piVar5 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(param_1) + 0x34);
  int32_t iVar3 = param_1 - param_2;
  int32_t* piVar7 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(param_2) + 0x24);
  int32_t n = 3;
  do {
    *reinterpret_cast<int32_t*>(static_cast<intptr_t>(iVar3) + static_cast<intptr_t>(reinterpret_cast<intptr_t>(piVar7)) - 0xc) = piVar7[-3];
    *reinterpret_cast<int32_t*>(static_cast<intptr_t>(iVar3) + static_cast<intptr_t>(reinterpret_cast<intptr_t>(piVar7))) = *piVar7;
    uint32_t uVar1 = static_cast<uint32_t>(piVar7[-3]);
    if (uVar1 != 0) {
      using CloneFn = int32_t(*)(uint32_t);
      using CopyFn = void(*)(int32_t, int32_t);
      auto* t1 = reinterpret_cast<CloneFn*>(&DAT_00728560);
      CloneFn cloneFn = t1[*piVar7];
      int32_t iVar4 = cloneFn(uVar1);
      *piVar5 = iVar4;
      auto* t2 = reinterpret_cast<CopyFn*>(&DAT_007285d8);
      CopyFn pcVar2 = t2[*piVar7];
      uint32_t uVar6 = 0;
      if (uVar1 != 0) {
        do {
          uint8_t strideDst = *reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(*piVar5) + 4);
          int32_t dstAddr = static_cast<int32_t>(static_cast<uintptr_t>(strideDst) * uVar6 + static_cast<uintptr_t>(*piVar5));
          uint8_t strideSrc = *reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(piVar7[4]) + 4);
          int32_t srcAddr = static_cast<int32_t>(static_cast<uintptr_t>(strideSrc) * uVar6 + static_cast<uintptr_t>(piVar7[4]));
          pcVar2(dstAddr, srcAddr);
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar1);
      }
    }
    piVar7 = piVar7 + 1;
    piVar5 = piVar5 + 1;
    n = n + -1;
  } while (n != 0);
}
