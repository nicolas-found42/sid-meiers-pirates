// Reconstruction batch mass_0145 — Sid Meier's Pirates! (2004) PE32 i386
#include <cstdint>
#include <cmath>
#include <cstddef>
#include <windows.h>

extern void* PTR_FUN_006c2718;
extern uint8_t DAT_007273fc;
extern uint8_t DAT_00727560;

extern void FUN_005383d0(void* self);
extern void FUN_00538400(void* self);
extern void FUN_00540de0(void* self);
extern void FUN_00540e40(void* self);

// 0x552c80 — observed shape
void FUN_00552c80(void* self) {
  int32_t* fields = static_cast<int32_t*>(self);
  FUN_005383d0(self);
  *fields = reinterpret_cast<int32_t>(PTR_FUN_006c2718);
  fields[0xe] = 0;
  *reinterpret_cast<uint16_t*>(&fields[3]) = 0x2c;
  fields[4] = 0x3f800000;
  fields[5] = 0;
  fields[6] = 0x7f7fffff;
  fields[7] = static_cast<int32_t>(0xff7fffff);
  fields[8] = static_cast<int32_t>(0xff7fffff);
  fields[10] = 0;
  fields[9] = static_cast<int32_t>(0xff7fffff);
  fields[0xd] = 0;
  fields[0xb] = static_cast<int32_t>(0xff7fffff);
  int32_t* puVar2 = reinterpret_cast<int32_t*>(fields[0xe]);
  if (puVar2 != nullptr) {
    int32_t* piVar1 = puVar2 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(void(**)(int32_t))(*puVar2))(1);
    }
    fields[0xe] = 0;
  }
  *reinterpret_cast<uint8_t*>(&fields[0x10]) = 0;
  *reinterpret_cast<uint8_t*>(&fields[0xc]) = 1;
  fields[0xf] = 0x80000000;
}

// 0x552d20 — observed shape
void FUN_00552d20(void* self) {
  int32_t* fields = static_cast<int32_t*>(self);
  *fields = reinterpret_cast<int32_t>(PTR_FUN_006c2718);
  int32_t* puVar2 = reinterpret_cast<int32_t*>(fields[0xe]);
  if (puVar2 != nullptr) {
    int32_t* piVar1 = puVar2 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(void(**)(int32_t))(*puVar2))(1);
    }
    fields[0xe] = 0;
  }
  puVar2 = reinterpret_cast<int32_t*>(fields[0xe]);
  if (puVar2 != nullptr) {
    int32_t* piVar1 = puVar2 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(void(**)(int32_t))(*puVar2))(1);
    }
  }
  FUN_00538400(self);
}

// 0x552d60 — observed shape
void FUN_00552d60(int32_t* self, int32_t param_2) {
  for (int32_t* piVar1 = reinterpret_cast<int32_t*>(self[4]); piVar1 != nullptr; piVar1 = reinterpret_cast<int32_t*>(piVar1[0xe])) {
    (**(void(**)(int32_t))(*piVar1 + 0x34))(param_2);
  }
  int32_t* puVar3 = reinterpret_cast<int32_t*>( (**(void*(**)(void))( *self + 4))() );
  while (true) {
    if (puVar3 == nullptr) goto LAB_00552dd0;
    if (puVar3 == reinterpret_cast<int32_t*>(&DAT_007273fc)) break;
    puVar3 = reinterpret_cast<int32_t*>(puVar3[1]);
  }
  puVar3 = reinterpret_cast<int32_t*>(self[0x29]);
  while (puVar3 != nullptr) {
    int32_t iVar2 = puVar3[2];
    puVar3 = reinterpret_cast<int32_t*>(*puVar3);
    if ((iVar2 != 0) && (*reinterpret_cast<int32_t*>(iVar2 + 0x10) != 0)) {
      FUN_00552d60(reinterpret_cast<int32_t*>(iVar2), param_2);
    }
  }
LAB_00552dd0:
  puVar3 = reinterpret_cast<int32_t*>( (**(void*(**)(void))( *self + 4))() );
  if (puVar3 != nullptr) {
    while (puVar3 != reinterpret_cast<int32_t*>(&DAT_00727560)) {
      puVar3 = reinterpret_cast<int32_t*>(puVar3[1]);
      if (puVar3 == nullptr) {
        return;
      }
    }
    uint32_t uVar4 = 0;
    if (self[0x30] != 0) {
      do {
        int32_t iVar2 = *reinterpret_cast<int32_t*>(self[0x2e] + uVar4 * 4);
        if (iVar2 != 0) {
          FUN_00552d60(reinterpret_cast<int32_t*>(iVar2), param_2);
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < static_cast<uint32_t>(self[0x30]));
    }
  }
}

// 0x552e30 — observed shape
void FUN_00552e30(void* self, int32_t param_1) {
  int32_t* fields = static_cast<int32_t*>(self);
  int32_t iVar1 = fields[0xd];
  if (iVar1 != param_1) {
    fields[1] = fields[1] + 1;
    if ((iVar1 != 0) && (*reinterpret_cast<int32_t*>(iVar1 + 0x10) != 0)) {
      FUN_00540e40(self);
    }
    fields[0xd] = param_1;
    if (param_1 != 0) {
      for (int32_t* piVar2 = *reinterpret_cast<int32_t**>(param_1 + 0x10); piVar2 != nullptr; piVar2 = reinterpret_cast<int32_t*>(piVar2[0xe])) {
        if (piVar2 == fields) {
          return;
        }
      }
      FUN_00540de0(self);
      char cVar3 = (**(char(**)(void))(*fields + 0x48))();
      if (cVar3 != '\0') {
        uint16_t* target = reinterpret_cast<uint16_t*>(*reinterpret_cast<int32_t*>(fields[0xd] + 0xbc) + 0x32);
        *target = static_cast<uint16_t>(*target & 0xfff | 0x8000);
      }
    }
    int32_t* piVar2 = fields + 1;
    *piVar2 = *piVar2 + -1;
    if (*piVar2 == 0) {
      (**(void(**)(int32_t))(*fields))(1);
    }
  }
}

// 0x552ec0 — observed shape
int32_t FUN_00552ec0(int32_t param_1) {
  int32_t iVar2 = -0x80000000;
  for (int32_t iVar1 = *reinterpret_cast<int32_t*>(param_1 + 0x10); iVar1 != 0; iVar1 = *reinterpret_cast<int32_t*>(iVar1 + 0x38)) {
    if (iVar2 < *reinterpret_cast<int32_t*>(iVar1 + 0x3c)) {
      iVar2 = *reinterpret_cast<int32_t*>(iVar1 + 0x3c);
    }
  }
  return iVar2;
}

extern uint16_t DAT_00727c5c;
extern void FUN_00538630(void);
extern void FUN_00545cc0(void);
extern int32_t FUN_00545600(void);
extern void FUN_00538430(int32_t* param_1);
extern void operator_delete(void* ptr);

// 0x552ef0 — observed shape
void FUN_00552ef0(int32_t param_1, void* self, float param_2, float param_3, char param_4) {
  uint8_t bVar1 = *reinterpret_cast<uint8_t*>(reinterpret_cast<intptr_t>(self) + 0xc);
  uint16_t uVar3 = static_cast<uint16_t>(bVar1 & 1);
  uint16_t uVar2 = *reinterpret_cast<uint16_t*>(param_1 + 0xc);
  uint16_t uVar4 = static_cast<uint16_t>(uVar2 & 0xfffe | uVar3);
  *reinterpret_cast<uint16_t*>(param_1 + 0xc) = uVar4;
  if ((bVar1 & 1) == 0) {
    uVar4 = static_cast<uint16_t>(uVar4 | 8);
  } else {
    uVar4 = static_cast<uint16_t>(uVar2 & 0xfff6 | uVar3);
  }
  *reinterpret_cast<uint16_t*>(param_1 + 0xc) = uVar4;
  if (param_4 == '\0') {
    *reinterpret_cast<uint16_t*>(param_1 + 0xc) = static_cast<uint16_t>(*reinterpret_cast<uint16_t*>(param_1 + 0xc) & 0xfffd | 4);
  } else {
    *reinterpret_cast<uint8_t*>(param_1 + 0xc) = static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(param_1 + 0xc) & 0xf9);
  }
  *reinterpret_cast<int32_t*>(param_1 + 0x10) = *reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(self) + 0x10);
  *reinterpret_cast<int32_t*>(param_1 + 0x14) = *reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(self) + 0x14);
  *reinterpret_cast<float*>(param_1 + 0x1c) = param_3 - param_2;
  *reinterpret_cast<int32_t*>(param_1 + 0x18) = 0;
}

// 0x552f70 — observed shape
void FUN_00552f70(int32_t param_1, void* self) {
  uint16_t* selfField = reinterpret_cast<uint16_t*>(reinterpret_cast<intptr_t>(self) + 0xc);
  FUN_00538630();
  FUN_00545cc0();
  (**(void(**)(void))(*reinterpret_cast<int32_t*>(param_1 + 0x15c) + 8))();
  (**(void(**)(void))(*reinterpret_cast<int32_t*>(param_1 + 0x15c) + 8))();
  (**(void(**)(void))(*reinterpret_cast<int32_t*>(param_1 + 0x15c) + 8))();
  int32_t iVar3 = reinterpret_cast<int32_t>(self) + 0x18;
  (**(void(**)(int32_t, int32_t))(*reinterpret_cast<int32_t*>(param_1 + 0x15c) + 8))(iVar3, 4);
  char cVar2 = static_cast<char>(iVar3);
  (**(void(**)(void))(*reinterpret_cast<int32_t*>(param_1 + 0x15c) + 8))();
  FUN_00545cc0();
  if (*reinterpret_cast<uint32_t*>(param_1 + 0x1c) == 0xa000101) {
    (**(void(**)(void))(*reinterpret_cast<int32_t*>(param_1 + 0x15c) + 8))();
    if (cVar2 == '\0') {
      *reinterpret_cast<uint8_t*>(selfField) = static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(selfField) & 0xef);
    } else {
      *reinterpret_cast<uint8_t*>(selfField) = static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(selfField) | 0x10);
    }
  } else if (*reinterpret_cast<uint32_t*>(param_1 + 0x1c) < 0xa000101) {
    *selfField = static_cast<uint16_t>((*selfField & 0xfff0) << 1 | *selfField & 0xf);
  }
  if (*reinterpret_cast<uint32_t*>(param_1 + 0x1c) < 0xa000102) {
    DAT_00727c5c = *selfField;
    *selfField = static_cast<uint16_t>(*selfField & 0x1f);
  }
  if (*reinterpret_cast<uint32_t*>(param_1 + 0x1c) < 0xa000103) {
    *reinterpret_cast<uint8_t*>(selfField) = static_cast<uint8_t>(*reinterpret_cast<uint8_t*>(selfField) | 0x20);
  }
}

// 0x553060 — observed shape
void FUN_00553060(int32_t param_1, void* self) {
  int32_t* fields = static_cast<int32_t*>(self);
  int32_t* puVar4 = reinterpret_cast<int32_t*>(FUN_00545600());
  int32_t* puVar2 = reinterpret_cast<int32_t*>(fields[0xe]);
  if (puVar2 != puVar4) {
    if (puVar2 != nullptr) {
      int32_t* piVar1 = puVar2 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (**(void(**)(int32_t))(*puVar2))(1);
      }
    }
    fields[0xe] = reinterpret_cast<int32_t>(puVar4);
    if (puVar4 != nullptr) {
      puVar4[1] = puVar4[1] + 1;
    }
  }
  int32_t iVar5 = FUN_00545600();
  fields[0xd] = iVar5;
  if (*reinterpret_cast<uint32_t*>(param_1 + 0x1c) < 0xa000110) {
    char cVar3 = (**(char(**)(void))(*fields + 0x48))();
    if ((cVar3 != '\0') && (fields[0xd] != 0)) {
      int32_t iVar5b = *reinterpret_cast<int32_t*>(fields[0xd] + 0xbc);
      *reinterpret_cast<uint16_t*>(iVar5b + 0x32) = static_cast<uint16_t>(*reinterpret_cast<uint16_t*>(iVar5b + 0x32) & 0xfff | 0x8000);
    }
  }
}

// 0x5530e0 — observed shape
void FUN_005530e0(int32_t* param_1, void* self) {
  FUN_00538430(param_1);
  (**(void(**)(int32_t))(*param_1 + 0x2c))(*reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(self) + 0x38));
  (**(void(**)(void*, int32_t))(*reinterpret_cast<int32_t*>(param_1[0x58]) + 0xc))(reinterpret_cast<uint8_t*>(self) + 0xc, 2);
  (**(void(**)(void*, int32_t))(*reinterpret_cast<int32_t*>(param_1[0x58]) + 0xc))(reinterpret_cast<uint8_t*>(self) + 0x10, 4);
  (**(void(**)(void*, int32_t))(*reinterpret_cast<int32_t*>(param_1[0x58]) + 0xc))(reinterpret_cast<uint8_t*>(self) + 0x14, 4);
  (**(void(**)(void*, int32_t))(*reinterpret_cast<int32_t*>(param_1[0x58]) + 0xc))(reinterpret_cast<uint8_t*>(self) + 0x18, 4);
  (**(void(**)(void*, int32_t))(*reinterpret_cast<int32_t*>(param_1[0x58]) + 0xc))(reinterpret_cast<uint8_t*>(self) + 0x1c, 4);
  (**(void(**)(int32_t))(*param_1 + 0x2c))(*reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(self) + 0x34));
}

// 0x553160 — observed shape
void FUN_00553160(uint8_t param_1, void* self) {
  int32_t* fields = static_cast<int32_t*>(self);
  *fields = reinterpret_cast<int32_t>(PTR_FUN_006c2718);
  int32_t* puVar2 = reinterpret_cast<int32_t*>(fields[0xe]);
  if (puVar2 != nullptr) {
    int32_t* piVar1 = puVar2 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(void(**)(int32_t))(*puVar2))(1);
    }
    fields[0xe] = 0;
  }
  puVar2 = reinterpret_cast<int32_t*>(fields[0xe]);
  if (puVar2 != nullptr) {
    int32_t* piVar1 = puVar2 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(void(**)(int32_t))(*puVar2))(1);
    }
  }
  FUN_00538400(self);
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

extern int32_t DAT_00727c60;
extern void FUN_006b34a0(int32_t arg);
extern void FUN_005606f0(uint32_t uVar1, int32_t* local_4);
extern void* FUN_00557b10(int32_t arg);
extern void* FUN_00557cf0(const char* name, int32_t value);
extern void* FUN_00557d40(const char* name, int32_t value);
extern void* FUN_00552780(const char* name, int32_t value);
extern void* FUN_005527e0(const char* name, int32_t value);
extern void* FUN_00557b50(const char* name, int32_t value);
extern float DAT_00727c7c;
extern float _DAT_00727c78;
extern void* PTR_FUN_006c2848;
extern void FUN_00556650(int32_t param_10, int32_t param_2, int32_t param_3, int32_t param_4, int32_t param_5, int32_t param_6, int32_t param_7, int32_t param_11, int32_t param_9);
extern void FUN_00556850(void);

// 0x5531c0 — observed shape
void FUN_005531c0(int32_t param_1, void* self) {
  int32_t local_4 = reinterpret_cast<int32_t>(FUN_00557b10(DAT_00727c60));
  int32_t iVar2 = param_1;
  uint32_t uVar1 = *reinterpret_cast<uint32_t*>(param_1 + 0xc);
  if (*reinterpret_cast<uint32_t*>(param_1 + 8) <= uVar1) {
    FUN_006b34a0(*reinterpret_cast<int32_t*>(param_1 + 0x14) + static_cast<int32_t>(uVar1));
  }
  FUN_005606f0(uVar1, &local_4);
  param_1 = reinterpret_cast<int32_t>(FUN_00557cf0("m_fFrequency", *reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(self) + 0x10)));
  uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
  if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
    FUN_006b34a0(*reinterpret_cast<int32_t*>(iVar2 + 0x14) + static_cast<int32_t>(uVar1));
  }
  FUN_005606f0(uVar1, &param_1);
  param_1 = reinterpret_cast<int32_t>(FUN_00557cf0("m_fPhase", *reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(self) + 0x14)));
  uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
  if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
    FUN_006b34a0(*reinterpret_cast<int32_t*>(iVar2 + 0x14) + static_cast<int32_t>(uVar1));
  }
  FUN_005606f0(uVar1, &param_1);
  param_1 = reinterpret_cast<int32_t>(FUN_00557cf0("m_fLoKeyTime", *reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(self) + 0x18)));
  uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
  if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
    FUN_006b34a0(*reinterpret_cast<int32_t*>(iVar2 + 0x14) + static_cast<int32_t>(uVar1));
  }
  FUN_005606f0(uVar1, &param_1);
  param_1 = reinterpret_cast<int32_t>(FUN_00557cf0("m_fHiKeyTime", *reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(self) + 0x1c)));
  uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
  if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
    FUN_006b34a0(*reinterpret_cast<int32_t*>(iVar2 + 0x14) + static_cast<int32_t>(uVar1));
  }
  FUN_005606f0(uVar1, &param_1);
  param_1 = reinterpret_cast<int32_t>(FUN_00557cf0("m_fStartTime", *reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(self) + 0x20)));
  uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
  if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
    FUN_006b34a0(*reinterpret_cast<int32_t*>(iVar2 + 0x14) + static_cast<int32_t>(uVar1));
  }
  FUN_005606f0(uVar1, &param_1);
  param_1 = reinterpret_cast<int32_t>(FUN_00557cf0("m_fLastTime", *reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(self) + 0x24)));
  uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
  if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
    FUN_006b34a0(*reinterpret_cast<int32_t*>(iVar2 + 0x14) + static_cast<int32_t>(uVar1));
  }
  FUN_005606f0(uVar1, &param_1);
  param_1 = reinterpret_cast<int32_t>(FUN_00557d40("m_pTarget", *reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(self) + 0x34)));
  uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
  if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
    FUN_006b34a0(*reinterpret_cast<int32_t*>(iVar2 + 0x14) + static_cast<int32_t>(uVar1));
  }
  FUN_005606f0(uVar1, &param_1);
  param_1 = reinterpret_cast<int32_t>(FUN_00552780("anim type", *reinterpret_cast<uint8_t*>(reinterpret_cast<intptr_t>(self) + 0xc) & 1));
  uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
  if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
    FUN_006b34a0(*reinterpret_cast<int32_t*>(iVar2 + 0x14) + static_cast<int32_t>(uVar1));
  }
  FUN_005606f0(uVar1, &param_1);
  param_1 = reinterpret_cast<int32_t>(FUN_005527e0("cycle type", (*reinterpret_cast<uint8_t*>(reinterpret_cast<intptr_t>(self) + 0xc) >> 1) & 3));
  uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
  if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
    FUN_006b34a0(*reinterpret_cast<int32_t*>(iVar2 + 0x14) + static_cast<int32_t>(uVar1));
  }
  FUN_005606f0(uVar1, &param_1);
  param_1 = reinterpret_cast<int32_t>(FUN_00557b50("Play Backwards", (*reinterpret_cast<uint8_t*>(reinterpret_cast<intptr_t>(self) + 0xc) >> 4) & 1));
  uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
  if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
    FUN_006b34a0(*reinterpret_cast<int32_t*>(iVar2 + 0x14) + static_cast<int32_t>(uVar1));
  }
  FUN_005606f0(uVar1, &param_1);
  param_1 = reinterpret_cast<int32_t>(FUN_00557b50("Manager Update", (*reinterpret_cast<uint8_t*>(reinterpret_cast<intptr_t>(self) + 0xc) >> 5) & 1));
  uVar1 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
  if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar1) {
    FUN_006b34a0(*reinterpret_cast<int32_t*>(iVar2 + 0x14) + static_cast<int32_t>(uVar1));
  }
  FUN_005606f0(uVar1, &param_1);
}

// 0x5534a0 — observed shape
long double FUN_005534a0(float param_1, float param_2) {
  if ((param_2 == 0.0f) && (param_1 == 0.0f)) {
    return static_cast<long double>(0.0);
  }
  float local_4 = 0.0f;
  long double fVar1;
  if ( fabsf(param_1) <= fabsf(param_2)) {
    fVar1 = (long double)param_1 / (long double)param_2;
  } else {
    fVar1 = (long double)param_2 / (long double)param_1;
    if (fVar1 <= (long double)0.0) {
      if (fVar1 < (long double)0.0) {
        local_4 = -DAT_00727c7c;
      }
    } else {
      local_4 = DAT_00727c7c;
    }
  }
  long double fVar2 = fVar1 * fVar1;
  fVar1 = ((((((long double)0.0208351 * fVar2 - (long double)0.085133) * fVar2 + (long double)0.180141) * fVar2 - (long double)0.3302995) * fVar2 + (long double)0.999866) * fVar1;
  if (local_4 != 0.0f) {
    fVar1 = (long double)local_4 - fVar1;
  }
  if ((param_1 < 0.0f) && (param_2 < 0.0f)) {
    fVar1 = fVar1 - (long double)_DAT_00727c78;
  }
  if ((0.0f < param_1) && (param_2 < 0.0f)) {
    fVar1 = fVar1 + (long double)_DAT_00727c78;
  }
  return fVar1;
}

// 0x5535d0 — observed shape
void FUN_005535d0(uint16_t param_1, void* self, int32_t param_2, int32_t param_3, int32_t param_4, int32_t param_5, int32_t param_6, int32_t param_7, uint16_t param_8, int32_t param_9, int32_t param_10, int32_t param_11) {
  int32_t* fields = static_cast<int32_t*>(self);
  FUN_00556650(param_10, param_2, param_3, param_4, param_5, param_6, param_7, param_11, param_9);
  *reinterpret_cast<uint16_t*>(&fields[0xf]) = param_8;
  *reinterpret_cast<int16_t*>(reinterpret_cast<intptr_t>(self) + 0x56) = static_cast<int16_t>(param_11);
  *reinterpret_cast<int16_t*>(&fields[0x15]) = static_cast<int16_t>(param_10);
  *fields = reinterpret_cast<int32_t>(PTR_FUN_006c2848);
  *reinterpret_cast<uint16_t*>(&fields[3]) = param_1;
  fields[0x10] = static_cast<int32_t>(param_8) * 3;
}

// 0x553740 — observed shape
void FUN_00553740(uint8_t param_1, void* self) {
  FUN_00556850();
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x5538c0 — observed shape
void FUN_005538c0(int32_t* param_1, void* self) {
  param_1[4] = *reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(self) + 0xc);
  param_1[5] = 0;
  (**(void(**)(void))(*param_1 + 0xd8))();
}

extern void FUN_00538410(int32_t param_1, int32_t param_2);
extern int32_t FUN_00533c78(int32_t size);
extern void* FUN_00557680(int32_t value);
extern char FUN_00538360(int32_t param_1);
extern void FUN_005511d0(void);
extern void* PTR_FUN_006c28d8;
extern void* FUN_00557940(void);
extern void FUN_004127b0(void* dest, int32_t size, uint32_t count, void* label);
extern void* thunk_FUN_00533c78(int32_t size);
extern void FUN_00538430(void);
extern void FUN_00535150(int32_t* param_1);
extern void FUN_00551a80(int32_t* param_1);
extern void FUN_005351e0(int32_t* param_1);

// 0x5538e0 — observed shape
void FUN_005538e0(int32_t param_1, void* self, int32_t param_2) {
  FUN_00538410(param_1, param_2);
  int32_t iVar3 = FUN_00533c78(0x38);
  int32_t* puVar4;
  if (iVar3 == 0) {
    puVar4 = nullptr;
  } else {
    puVar4 = reinterpret_cast<int32_t*>(FUN_00557680(*reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(self) + 0xc)));
  }
  int32_t* puVar2 = *reinterpret_cast<int32_t**>(param_1 + 0xc);
  if (puVar2 != puVar4) {
    if (puVar2 != nullptr) {
      int32_t* piVar1 = puVar2 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (**(void(**)(int32_t))(*puVar2))(1);
      }
    }
    *reinterpret_cast<int32_t**>(param_1 + 0xc) = puVar4;
    if (puVar4 != nullptr) {
      puVar4[1] = puVar4[1] + 1;
    }
  }
}

// 0x553940 — observed shape
uint8_t FUN_00553940(int32_t param_1, void* self) {
  char cVar1 = FUN_00538360(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  uint32_t uVar2 = 8;
  do {
    (**(void(**)(int32_t))(*reinterpret_cast<int32_t*>(uVar2 + *reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(self) + 0xc)) + 0x14))(param_1);
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x38);
  return 1;
}

// 0x553980 — observed shape
void FUN_00553980(uint8_t param_1, void* self) {
  int32_t* fields = static_cast<int32_t*>(self);
  *fields = reinterpret_cast<int32_t>(PTR_FUN_006c28d8);
  FUN_005511d0();
  operator_delete(reinterpret_cast<void*>(fields[5]));
  operator_delete(reinterpret_cast<void*>(fields[6]));
  operator_delete(reinterpret_cast<void*>(fields[7]));
  int32_t* puVar2 = reinterpret_cast<int32_t*>(fields[3]);
  if (puVar2 != nullptr) {
    int32_t* piVar1 = puVar2 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(void(**)(int32_t))(*puVar2))(1);
    }
  }
  FUN_00538400();
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x5539e0 — observed shape
void FUN_005539e0(uint16_t param_1, void* self, int32_t* param_2, int32_t* param_3, int32_t* param_4);
void FUN_005539e0(uint16_t param_1, void* self, int32_t* param_2, int32_t* param_3, int32_t* param_4) {
  FUN_005383d0();
  uint32_t uVar6 = static_cast<uint32_t>(param_1);
  int32_t* fields = static_cast<int32_t*>(self);
  *fields = reinterpret_cast<int32_t>(PTR_FUN_006c28d8);
  fields[3] = 0;
  *reinterpret_cast<uint16_t*>(&fields[4]) = param_1;
  int32_t* puVar3 = reinterpret_cast<int32_t*>(thunk_FUN_00533c78(static_cast<int32_t>(uVar6 * 0xc)));
  fields[5] = reinterpret_cast<int32_t>(puVar3);
  for (uint32_t uVar4 = uVar6 * 0xc >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar3 = *param_2;
    param_2 = param_2 + 1;
    puVar3 = puVar3 + 1;
  }
  for (int32_t iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
    *reinterpret_cast<uint8_t*>(puVar3) = *reinterpret_cast<uint8_t*>(param_2);
    param_2 = reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(param_2) + 1);
    puVar3 = reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(puVar3) + 1);
  }
  if (param_3 == nullptr) {
    fields[6] = 0;
  } else {
    puVar3 = reinterpret_cast<int32_t*>(thunk_FUN_00533c78(static_cast<int32_t>(uVar6 * 8)));
    if (puVar3 == nullptr) {
      fields[6] = 0;
      puVar3 = nullptr;
      for (int32_t i = static_cast<int32_t>(uVar6) * 2; i != 0; i = i - 1) {
        *puVar3 = *param_3;
        param_3 = param_3 + 1;
        puVar3 = puVar3 + 1;
      }
    } else {
      FUN_004127b0(puVar3, 8, uVar6, nullptr);
      fields[6] = reinterpret_cast<int32_t>(puVar3);
      for (int32_t i = static_cast<int32_t>(uVar6) * 2; i != 0; i = i - 1) {
        *puVar3 = *param_3;
        param_3 = param_3 + 1;
        puVar3 = puVar3 + 1;
      }
    }
  }
  if (param_4 == nullptr) {
    fields[7] = 0;
  } else {
    puVar3 = reinterpret_cast<int32_t*>(thunk_FUN_00533c78(static_cast<int32_t>(uVar6 << 4)));
    if (puVar3 == nullptr) {
      puVar3 = nullptr;
    } else {
      FUN_004127b0(puVar3, 0x10, uVar6, nullptr);
    }
    fields[7] = reinterpret_cast<int32_t>(puVar3);
    for (int32_t i = static_cast<int32_t>(uVar6) << 2; i != 0; i = i - 1) {
      *puVar3 = *param_4;
      param_4 = param_4 + 1;
      puVar3 = puVar3 + 1;
    }
    for (int32_t i = 0; i != 0; i = i - 1) {
      *reinterpret_cast<uint8_t*>(puVar3) = *reinterpret_cast<uint8_t*>(param_4);
      param_4 = reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(param_4) + 1);
      puVar3 = reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(puVar3) + 1);
    }
  }
  int32_t iVar5 = FUN_00533c78(0x38);
  int32_t* puVar3b;
  if (iVar5 == 0) {
    puVar3b = nullptr;
  } else {
    puVar3b = reinterpret_cast<int32_t*>(FUN_00557940());
  }
  int32_t* puVar2 = reinterpret_cast<int32_t*>(fields[3]);
  if (puVar2 != puVar3b) {
    if (puVar2 != nullptr) {
      int32_t* piVar1 = puVar2 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (**(void(**)(int32_t))(*puVar2))(1);
      }
    }
    fields[3] = reinterpret_cast<int32_t>(puVar3b);
    if (puVar3b != nullptr) {
      puVar3b[1] = puVar3b[1] + 1;
    }
  }
  *reinterpret_cast<uint16_t*>(&fields[8]) = 0;
  fields[9] = 0;
}

// 0x553db0 — observed shape
void FUN_00553db0(int32_t* param_1, void* self) {
  FUN_00538430(param_1);
  uint16_t* puVar1 = reinterpret_cast<uint16_t*>(reinterpret_cast<intptr_t>(self) + 0x10);
  (**(void(**)(void))(*reinterpret_cast<int32_t*>(param_1[0x58]) + 0xc))();
  uint16_t uVar4 = 0;
  if (*puVar1 != 0) {
    do {
      FUN_00535150(param_1);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar1);
  }
  uint8_t auStack_4 = static_cast<uint8_t>(*reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(self) + 0x18) != 0);
  uint32_t uVar5 = 1;
  (**(void(**)(uint8_t*))(*reinterpret_cast<int32_t*>(param_1[0x58]) + 0xc))(&auStack_4);
  if ((auStack_4 != '\0') && (uVar4 = 0, *puVar1 != 0)) {
    do {
      FUN_00551a80(param_1);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar1);
  }
  (**(void(**)(uint8_t*, int32_t))(*reinterpret_cast<int32_t*>(param_1[0x58]) + 0xc))(&auStack_4 - 0x11, 1);
  char cStack_1d = static_cast<char>(static_cast<uint32_t>(reinterpret_cast<intptr_t>(puVar1) >> 0x18));
  if ((cStack_1d != '\0') && (uVar4 = 0, *puVar1 != 0)) {
    do {
      FUN_005351e0(param_1);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar1);
  }
  int32_t uStack_1c = 0xc;
  (**(void(**)(int32_t*, int32_t))(*reinterpret_cast<int32_t*>(param_1[0x58]) + 0xc))(&uStack_1c, 4);
  if ((uVar5 != 0)) {
    uint32_t uVar3 = 0;
    uint32_t uVar2 = 0;
    do {
      (**(void(**)(int32_t))(*param_1 + 0x2c))(*reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(reinterpret_cast<intptr_t>(self) + 0xc) + 8 + uVar2 * 4));
      uVar3 = uVar3 + 1;
      uVar2 = uVar3 & 0xffff;
    } while (uVar2 < uVar5);
  }
}
