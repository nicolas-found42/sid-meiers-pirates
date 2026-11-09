// Reconstruction batch mass_0197 — Sid Meier's Pirates! (2004), PE32 i386
#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_005adf30(int param_1);
extern void FUN_00535110(int param_1);
extern void FUN_005ab6a0();
extern void operator_delete(void *ptr);
extern void FUN_005adcb0(int param_1, uint32_t param_2);
extern void FUN_005adec0();
extern void *DAT_00728b70;

// 0x5ab910 — void(param_1); in_ECX receiver. Calls FUN_005adf30(param_1), then invokes virtual func at **(int**)(param_1+0x15c)+8 with (float*)(self+0x2c), arg 4; squares float at self+0x2c into self+0x30; calls FUN_00535110(param_1).
void FUN_005ab910(int param_1)
{
  void *self = nullptr;
  int in_ECX = (int)(intptr_t)self;
  (void)in_ECX;
  FUN_005adf30(param_1);
  typedef void (*VirtFn)(float *, int);
  int **vt = *(int ***)(param_1 + 0x15c);
  VirtFn fn = *(VirtFn *)(*(intptr_t *)vt + 8);
  float *f = (float *)((char *)self + 0x2c);
  fn(f, 4);
  float fVar1 = *f;
  *(float *)((char *)self + 0x30) = fVar1 * fVar1;
  FUN_00535110(param_1);
}

// 0x5ab9f0 — void(byte param_1); in_ECX receiver. Destructor-like: calls FUN_005ab6a0(), then operator_delete(self) if (param_1 & 1) != 0.
void FUN_005ab9f0(uint8_t param_1)
{
  void *self = nullptr;
  FUN_005ab6a0();
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x5abb00 — void(param_1, param_2); in_ECX receiver (source). Calls FUN_005adcb0(param_1,param_2), then copies 15 fields from self offsets 0x2c,0x30,0x44,0x48,0x4c,0x50,0x54,0x58,0x5c,0x60,100(0x64),0x34,0x38,0x3c,0x40 to param_1+same offsets.
void FUN_005abb00(int param_1, uint32_t param_2)
{
  void *self = nullptr;
  FUN_005adcb0(param_1, param_2);
  *(uint32_t *)(param_1 + 0x2c) = *(uint32_t *)((char *)self + 0x2c);
  *(uint32_t *)(param_1 + 0x30) = *(uint32_t *)((char *)self + 0x30);
  *(uint32_t *)(param_1 + 0x44) = *(uint32_t *)((char *)self + 0x44);
  *(uint32_t *)(param_1 + 0x48) = *(uint32_t *)((char *)self + 0x48);
  *(uint32_t *)(param_1 + 0x4c) = *(uint32_t *)((char *)self + 0x4c);
  *(uint32_t *)(param_1 + 0x50) = *(uint32_t *)((char *)self + 0x50);
  *(uint32_t *)(param_1 + 0x54) = *(uint32_t *)((char *)self + 0x54);
  *(uint32_t *)(param_1 + 0x58) = *(uint32_t *)((char *)self + 0x58);
  *(uint32_t *)(param_1 + 0x5c) = *(uint32_t *)((char *)self + 0x5c);
  *(uint32_t *)(param_1 + 0x60) = *(uint32_t *)((char *)self + 0x60);
  *(uint32_t *)(param_1 + 100) = *(uint32_t *)((char *)self + 100);
  *(uint32_t *)(param_1 + 0x34) = *(uint32_t *)((char *)self + 0x34);
  *(uint32_t *)(param_1 + 0x38) = *(uint32_t *)((char *)self + 0x38);
  *(uint32_t *)(param_1 + 0x3c) = *(uint32_t *)((char *)self + 0x3c);
  *(uint32_t *)(param_1 + 0x40) = *(uint32_t *)((char *)self + 0x40);
}

// 0x5abbb0 — void(float param_1, float* param_2); in_ECX receiver. Computes fVar1 = dot(row[0x34,0x38,0x3c], param_2). If self+0x28==param_1 && fVar1<0.001: param_2 -= fVar1*row, call FUN_005adec0, return. Else reflect param_2 about plane and scale by self+0x14, call FUN_005adec0.
void FUN_005abbb0(float param_1, float *param_2)
{
  void *self = nullptr;
  float fVar1 = param_2[0] * *(float *)((char *)self + 0x34) +
                *(float *)((char *)self + 0x3c) * param_2[2] +
                *(float *)((char *)self + 0x38) * param_2[1];
  float fVar4 = fVar1 * *(float *)((char *)self + 0x34);
  float fVar3 = fVar1 * *(float *)((char *)self + 0x38);
  float fVar2 = fVar1 * *(float *)((char *)self + 0x3c);
  if ((*(float *)((char *)self + 0x28) == param_1) && (fVar1 < 0.001f)) {
    param_2[0] = param_2[0] - fVar4;
    param_2[1] = param_2[1] - fVar3;
    param_2[2] = param_2[2] - fVar2;
    FUN_005adec0();
    return;
  }
  fVar4 = param_2[0] - (fVar4 + fVar4);
  param_2[0] = fVar4;
  fVar3 = param_2[1] - (fVar3 + fVar3);
  param_2[1] = fVar3;
  fVar2 = param_2[2] - (fVar2 + fVar2);
  param_2[2] = fVar2;
  float fVar1b = *(float *)((char *)self + 0x14);
  param_2[0] = fVar4 * fVar1b;
  param_2[1] = fVar3 * fVar1b;
  param_2[2] = fVar2 * fVar1b;
  FUN_005adec0();
}

// 0x5abc90 — uint(float param_1, float* param_2, float* param_3); in_ECX receiver. Plane table lookup via nested pointers + ushort at param_3+0x26 *0xc; 3D plane clip with 0.001 epsilon, iterative 0.001 nudge loop, 0.5-radius squared tests at 0x30/0x2c, linked-list search for &DAT_00728b70, optional func+0x44 callback; returns -(uint)bVar11 & in_ECX (or early in_ECX / uVar13).
uint32_t FUN_005abc90(float param_1, float *param_2, float *param_3)
{
  void *self = nullptr;
  uint32_t in_ECX = (uint32_t)(intptr_t)self;
  float *pfVar1 = (float *)(*(int *)(*(int *)(*(int *)(*(int *)(in_ECX + 0x10) + 0x34) + 0xbc) + 0x20) +
                    (uint32_t)*(uint16_t *)((intptr_t)param_3 + 0x26) * 0xc);
  uint8_t bVar11 = 0;
  float fVar3 = (pfVar1[0] * *(float *)((char *)self + 0x34) +
                 *(float *)((char *)self + 0x3c) * pfVar1[2] +
                 *(float *)((char *)self + 0x38) * pfVar1[1]) - *(float *)((char *)self + 0x40);
  if ((fVar3 < 0.001f) && (-fVar3 < 0.001f)) {
    param_2[0] = param_1;
    *(float *)((char *)self + 0x28) = param_1;
    *(float *)((char *)self + 0x1c) = pfVar1[0];
    *(float *)((char *)self + 0x20) = pfVar1[1];
    *(float *)((char *)self + 0x24) = pfVar1[2];
    return in_ECX;
  }
  float fVar4 = param_2[0] - param_1;
  float fVar5 = fVar4 * param_3[0] * *(float *)((char *)self + 0x34) +
                fVar4 * param_3[1] * *(float *)((char *)self + 0x38) +
                fVar4 * param_3[2] * *(float *)((char *)self + 0x3c);
  if ((fVar3 + fVar5) * fVar3 < 0.0f) {
    float fVar4b = -((fVar4 / fVar5) * fVar3);
    float local_24 = fVar4b * param_3[0] + pfVar1[0];
    float local_20 = fVar4b * param_3[1] + pfVar1[1];
    float local_1c = fVar4b * param_3[2] + pfVar1[2];
    if (((local_24 * *(float *)((char *)self + 0x34) +
         local_20 * *(float *)((char *)self + 0x38) +
         local_1c * *(float *)((char *)self + 0x3c)) - *(float *)((char *)self + 0x40)) * fVar3 < 0.0f) {
      do {
        float fVar5b = *(float *)((char *)self + 0x34) * 0.001f;
        float fVar6b = *(float *)((char *)self + 0x38) * 0.001f;
        if (0.0f <= fVar3) {
          local_24 = fVar5b + local_24;
          local_20 = fVar6b + local_20;
          local_1c = local_1c + *(float *)((char *)self + 0x3c) * 0.001f;
        } else {
          local_24 = local_24 - fVar5b;
          local_20 = local_20 - fVar6b;
          local_1c = local_1c - *(float *)((char *)self + 0x3c) * 0.001f;
        }
      } while (((local_24 * *(float *)((char *)self + 0x34) +
                 local_20 * *(float *)((char *)self + 0x38) +
                 local_1c * *(float *)((char *)self + 0x3c)) - *(float *)((char *)self + 0x40)) * fVar3 < 0.0f);
    }
    float fVar6 = local_24 - *(float *)((char *)self + 0x44);
    float fVar3b = local_20 - *(float *)((char *)self + 0x48);
    float fVar5c = local_1c - *(float *)((char *)self + 0x4c);
    float fVar7 = fVar6 * *(float *)((char *)self + 0x50) +
                  fVar3b * *(float *)((char *)self + 0x54) +
                  fVar5c * *(float *)((char *)self + 0x58);
    float fVar9 = fVar7 * *(float *)((char *)self + 0x50);
    float fVar8 = fVar7 * *(float *)((char *)self + 0x54);
    fVar7 = fVar7 * *(float *)((char *)self + 0x58);
    fVar3b = fVar6 * *(float *)((char *)self + 0x5c) +
             fVar3b * *(float *)((char *)self + 0x60) +
             fVar5c * *(float *)((char *)self + 100);
    float fVar6b = fVar3b * *(float *)((char *)self + 0x5c);
    float fVar5d = fVar3b * *(float *)((char *)self + 0x60);
    fVar3b = fVar3b * *(float *)((char *)self + 100);
    if ((fVar9 * fVar9 + fVar8 * fVar8 + fVar7 * fVar7 <
         *(float *)((char *)self + 0x30) * *(float *)((char *)self + 0x30) * 0.5f) &&
        (fVar6b * fVar6b + fVar5d * fVar5d + fVar3b * fVar3b <
         *(float *)((char *)self + 0x2c) * *(float *)((char *)self + 0x2c) * 0.5f)) {
      bVar11 = 1;
      param_2[0] = fVar4b + param_1;
      *(float *)((char *)self + 0x1c) = local_24;
      *(float *)((char *)self + 0x28) = fVar4b + param_1;
      *(float *)((char *)self + 0x20) = local_20;
      *(float *)((char *)self + 0x24) = local_1c;
    }
  }
  int *piVar2 = *(int **)((char *)self + 0xc);
  if (piVar2 != nullptr) {
    typedef void *(*IterFn)();
    IterFn iter = *(IterFn *)(*(intptr_t *)piVar2 + 4);
    void *puVar12 = iter();
    uint8_t bVar10 = 0;
    bool found = false;
    for (; puVar12 != nullptr; puVar12 = *(void **)((char *)puVar12 + 4)) {
      if (puVar12 == &DAT_00728b70) {
        bVar10 = 1;
        found = true;
        break;
      }
    }
    if (!found) bVar10 = 0;
    (void)found;
    int *masked = (int *)(-(uint32_t)bVar10 & (uint32_t)(intptr_t)piVar2);
    if ((masked != nullptr)) {
      typedef uint32_t (*CBFn)(float, float *, float *);
      CBFn cb = *(CBFn *)(*(intptr_t *)masked + 0x44);
      uint32_t uVar13 = cb(param_1, param_2, param_3);
      if (uVar13 != 0) {
        return uVar13;
      }
    }
  }
  return -(uint32_t)bVar11 & in_ECX;
}

extern void FUN_005add20();
extern void FUN_00558050();
extern void FUN_005383d0();
extern void FUN_00555ea0(float *, void *);
extern void FUN_00555e70(float, int);
extern void FUN_005ae030(float, float);
extern void FUN_005ae050(int);
extern void FUN_005ae0d0(uint32_t);
extern void *PTR_FUN_006c53e0;
extern void *PTR_FUN_006c5350;
extern void *PTR_FUN_006c5428;
extern uint32_t DAT_00727430;
extern uint32_t DAT_00727434;
extern uint32_t DAT_00727438;
extern uint32_t DAT_007177ac;
extern uint32_t DAT_007177b0;
extern uint32_t DAT_007177b4;
extern float _DAT_00728b38;
extern float _DAT_00727c80;
extern float _DAT_00727c78;
extern uint8_t DAT_00728b3c;

// 0x5ac120 — void(); in_ECX receiver. Calls FUN_005add20(), sets *self = &PTR_FUN_006c53e0, calls FUN_00558050(), then initializes self[0x11..0x19] repeating DAT_00727430/34/38 with self[0xb]=self[0xc]=0x3f800000 (1.0f), self[0x10]=0, self[0xd..0xf]=DAT triple.
void FUN_005ac120(void)
{
  uint32_t *self = nullptr;
  FUN_005add20();
  self[0] = (uint32_t)(intptr_t)&PTR_FUN_006c53e0;
  FUN_00558050();
  self[0x11] = DAT_00727430;
  self[0x12] = DAT_00727434;
  self[0x13] = DAT_00727438;
  self[0x14] = DAT_00727430;
  self[0x15] = DAT_00727434;
  self[0x16] = DAT_00727438;
  self[0x17] = DAT_00727430;
  self[0x18] = DAT_00727434;
  uint32_t uVar1 = DAT_00727438;
  self[0xb] = 0x3f800000;
  self[0xc] = 0x3f800000;
  self[0x10] = 0;
  self[0x19] = uVar1;
  self[0xd] = DAT_00727430;
  self[0xe] = DAT_00727434;
  self[0xf] = DAT_00727438;
}

// 0x5ac240 — void(); in_ECX receiver. Calls FUN_005383d0(), *self = &PTR_FUN_006c5350, self[3]=self[4]=0, *(uint8_t*)(self+5)=0, *self = &PTR_FUN_006c5428, self[6]=DAT_007177ac, self[7]=DAT_007177b0, self[8]=DAT_007177b4, self[9]=0.
void FUN_005ac240(void)
{
  uint32_t *self = nullptr;
  FUN_005383d0();
  self[0] = (uint32_t)(intptr_t)&PTR_FUN_006c5350;
  self[3] = 0;
  self[4] = 0;
  *(uint8_t *)((char *)self + 5 * (int)sizeof(uint32_t)) = 0;
  self[0] = (uint32_t)(intptr_t)&PTR_FUN_006c5428;
  self[6] = DAT_007177ac;
  self[7] = DAT_007177b0;
  uint32_t uVar1 = DAT_007177b4;
  self[9] = 0;
  self[8] = uVar1;
}

// 0x5ac2b0 — void(float param_1, float param_2); in_ECX receiver. Table check via nested ptr +0x4c; app-space interp with FUN_00555ea0, self+0x24 scale; lazy-init _DAT_00728b38 = _DAT_00727c78*10.0 guarded by DAT_00728b3c bit0; wrap/subtract _DAT_00727c80 or clamp to 0.0; FUN_00555e70; always FUN_005ae030(param_1, fVar2).
void FUN_005ac2b0(float param_1, float param_2)
{
  void *self = nullptr;
  float fVar2 = param_2;
  int iVar1 = *(int *)(*(int *)(*(int *)(*(intptr_t)self + 0x10) + 0x34) + 0xbc);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x4c) != 0)) {
    uint8_t local_c[12];
    FUN_00555ea0(&param_2, local_c);
    param_2 = (param_1 - *(float *)((intptr_t)fVar2 + 0x20)) * *(float *)((char *)self + 0x24) + param_2;
    if ((DAT_00728b3c & 1) == 0) {
      _DAT_00728b38 = _DAT_00727c78 * 10.0f;
      DAT_00728b3c = DAT_00728b3c | 1;
    }
    if (param_2 <= _DAT_00728b38) {
      if (_DAT_00727c80 < param_2) {
        do {
          param_2 = param_2 - _DAT_00727c80;
        } while (_DAT_00727c80 < param_2);
      }
    } else {
      param_2 = 0.0f;
    }
    FUN_00555e70(param_2, (int)(intptr_t)fVar2 + 0xc);
  }
  FUN_005ae030(param_1, fVar2);
}

// 0x5ac3b0 — void(int param_1); in_ECX receiver. If table ptr +0x4c nonzero: if self+0x14==0 copy self[0x18..0x20] vector to param_1+0xc; else random unit vector via rand(), fcos(length _DAT_00727c78*3.051851e-05), sqrt(1-c^2), angle _DAT_00727c80*3.051851e-05, sin/cos. Then FUN_00555e70(0,param_1+0xc). Always FUN_005ae050(param_1).
void FUN_005ac3b0(int param_1)
{
  void *self = nullptr;
  int iVar2 = *(int *)(*(int *)(*(int *)(*(intptr_t)self + 0x10) + 0x34) + 0xbc);
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x4c) != 0)) {
    if (*(char *)((char *)self + 0x14) == '\0') {
      *(uint32_t *)(param_1 + 0xc) = *(uint32_t *)((char *)self + 0x18);
      *(uint32_t *)(param_1 + 0x10) = *(uint32_t *)((char *)self + 0x1c);
      *(uint32_t *)(param_1 + 0x14) = *(uint32_t *)((char *)self + 0x20);
    } else {
      iVar2 = rand();
      float fVar3 = cosf((float)iVar2 * _DAT_00727c78 * 3.051851e-05f);
      float fVar1 = (float)sqrt((double)(1.0f - fVar3 * fVar3));
      iVar2 = rand();
      float fVar4 = _DAT_00727c80;
      *(float *)(param_1 + 0x14) = fVar3;
      fVar4 = (float)iVar2 * fVar4 * 3.051851e-05f;
      fVar3 = cosf(fVar4);
      *(float *)(param_1 + 0xc) = fVar3 * fVar1;
      fVar4 = sinf(fVar4);
      *(float *)(param_1 + 0x10) = fVar4 * fVar1;
    }
    FUN_00555e70(0.0f, param_1 + 0xc);
  }
  FUN_005ae050(param_1);
}

// 0x5ac620 — void(param_1); in_ECX receiver. Calls FUN_005ae0d0(param_1), iterates uVar2 < *(uint*)(self+0x20): piVar1 = *(int**)(*(int*)(self+0x18)+uVar2*4); if nonnull calls virtual (*(code**)(*piVar1+0x28))(param_1).
void FUN_005ac620(uint32_t param_1)
{
  void *self = nullptr;
  FUN_005ae0d0(param_1);
  uint32_t uVar2 = 0;
  if (*(int *)((char *)self + 0x20) != 0) {
    do {
      int *piVar1 = *(int **)(*(intptr_t *)((char *)self + 0x18) + uVar2 * 4);
      if (piVar1 != nullptr) {
        typedef void (*VirtFn)(uint32_t);
        VirtFn fn = *(VirtFn *)(*(intptr_t *)piVar1 + 0x28);
        fn(param_1);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint32_t *)((char *)self + 0x20));
  }
}

extern uint32_t FUN_005ae140(uint32_t param_1);
extern void FUN_005ae170(int *param_1);
extern void FUN_00533d10(uint32_t param_1, int param_2);
extern void FUN_0053ba20(uint32_t **self, uint32_t idx);
extern void FUN_0053bac0();
extern void FUN_00538400();
extern void *PTR_FUN_006c5470;
extern void *PTR_FUN_006c0bd0;

// 0x5ac660 — uint32_t(param_1); in_ECX receiver. uVar2 = FUN_005ae140(param_1); if (char)uVar2==0 return uVar2. Else iterate self+0x20 vec at self+0x18 calling virtual (*piVar1+0x14)(param_1); return CONCAT31((uVar3>>8),1) i.e. low byte 1, rest = count>>8.
uint32_t FUN_005ac660(uint32_t param_1)
{
  void *self = nullptr;
  uint32_t uVar2 = FUN_005ae140(param_1);
  if ((char)uVar2 == '\0') {
    return uVar2;
  }
  uint32_t uVar4 = 0;
  uint32_t uVar3 = 0;
  if (*(int *)((char *)self + 0x20) != 0) {
    do {
      int *piVar1 = *(int **)(*(intptr_t *)((char *)self + 0x18) + uVar4 * 4);
      if (piVar1 != nullptr) {
        typedef void (*VirtFn)(uint32_t);
        VirtFn fn = *(VirtFn *)(*(intptr_t *)piVar1 + 0x14);
        fn(param_1);
      }
      uVar3 = *(uint32_t *)((char *)self + 0x20);
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar3);
  }
  return (uVar3 & 0xFFFFFF00u) | 1u;
}

// 0x5ac6b0 — void(int* param_1); in_ECX receiver, unaff_EBX index bound. piVar1 = param_1; FUN_005ae170(param_1); param_1 = *(int**)(self+0x20); call virtual (*(int*)piVar1[0x58]+0xc)(&param_1,4); if unaff_EBX!=0 iterate calling (*piVar1+0x2c)(vec[i]).
void FUN_005ac6b0(int *param_1)
{
  void *self = nullptr;
  uint32_t unaff_EBX = 0;
  int *piVar1 = param_1;
  FUN_005ae170(param_1);
  int *param_1b = *(int **)((char *)self + 0x20);
  {
    typedef void (*VirtFn)(int **, int);
    VirtFn fn = *(VirtFn *)(*(intptr_t *)piVar1[0x58] + 0xc);
    fn(&param_1b, 4);
  }
  uint32_t uVar2 = 0;
  if (unaff_EBX != 0) {
    do {
      typedef void (*VirtFn)(uint32_t);
      VirtFn fn = *(VirtFn *)(*(intptr_t *)piVar1 + 0x2c);
      fn(*(uint32_t *)(*(intptr_t *)((char *)self + 0x18) + uVar2 * 4));
      uVar2 = uVar2 + 1;
    } while (uVar2 < unaff_EBX);
  }
}

// 0x5ac770 — void(param_1, param_2); in_ECX receiver. If nested ptr *(int*)(*(int*)(*(int*)(self+0x10)+0x34)+0xbc) != 0: FUN_00533d10(*(uint*)(param_2+0x18),1). Then FUN_005ae030(param_1,param_2).
void FUN_005ac770(uint32_t param_1, int param_2)
{
  void *self = nullptr;
  if (*(int *)(*(int *)(*(int *)(*(intptr_t)self + 0x10) + 0x34) + 0xbc) != 0) {
    FUN_00533d10(*(uint32_t *)(param_2 + 0x18), 1);
  }
  FUN_005ae030((float)param_1, (float)param_2);
}

// 0x5ac850 — void(); in_ECX receiver (undefined4*). *self=&PTR_FUN_006c5470; iterate self[8] entries via FUN_0053ba20(&local_4,i), refcount--, if 0 call (*local_4)(1); FUN_0053bac0(); *self=&PTR_FUN_006c5350; release self[3] similarly (set 0), release again without clear; FUN_00538400().
void FUN_005ac850(void)
{
  uint32_t *self = nullptr;
  uint32_t uVar3 = 0;
  self[0] = (uint32_t)(intptr_t)&PTR_FUN_006c5470;
  uint32_t *local_4 = self;
  if (self[8] != 0) {
    do {
      FUN_0053ba20(&local_4, uVar3);
      if (local_4 != nullptr) {
        int *piVar1 = (int *)(local_4 + 1);
        *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) {
          typedef void (*VirtFn)(int);
          VirtFn fn = *(VirtFn *)local_4;
          fn(1);
        }
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < self[8]);
  }
  FUN_0053bac0();
  self[0] = (uint32_t)(intptr_t)&PTR_FUN_006c5350;
  uint32_t *puVar2 = (uint32_t *)(intptr_t)self[3];
  if (puVar2 != nullptr) {
    int *piVar1 = (int *)(puVar2 + 1);
    *piVar1 = *piVar1 - 1;
    if (*piVar1 == 0) {
      typedef void (*VirtFn)(int);
      VirtFn fn = *(VirtFn *)puVar2;
      fn(1);
    }
    self[3] = 0;
  }
  puVar2 = (uint32_t *)(intptr_t)self[3];
  if (puVar2 != nullptr) {
    int *piVar1 = (int *)(puVar2 + 1);
    *piVar1 = *piVar1 - 1;
    if (*piVar1 == 0) {
      typedef void (*VirtFn)(int);
      VirtFn fn = *(VirtFn *)puVar2;
      fn(1);
    }
  }
  FUN_00538400();
}

// 0x5ac970 — void(); in_ECX receiver. Calls FUN_005383d0(), *self=&PTR_FUN_006c5350, self[3]=self[4]=0, *self=&PTR_FUN_006c5470, self[7]=self[8]=self[9]=self[6]=0, self[5]=&PTR_FUN_006c0bd0, self[10]=1.
void FUN_005ac970(void)
{
  uint32_t *self = nullptr;
  FUN_005383d0();
  self[0] = (uint32_t)(intptr_t)&PTR_FUN_006c5350;
  self[3] = 0;
  self[4] = 0;
  self[0] = (uint32_t)(intptr_t)&PTR_FUN_006c5470;
  self[7] = 0;
  self[8] = 0;
  self[9] = 0;
  self[6] = 0;
  self[5] = (uint32_t)(intptr_t)&PTR_FUN_006c0bd0;
  self[10] = 1;
}

extern void FUN_0057a3f0(int addr);
extern void FUN_00581300(uint32_t idx, uint32_t **p3);
extern void FUN_005ae060(uint32_t param_1, uint32_t *param_2);
extern float _DAT_00717c60;
extern uint32_t *FUN_00533c78(uint32_t size);
extern void FUN_005ae010(uint32_t param_1);
extern void FUN_00545cc0();
extern void *PTR_FUN_006c54b8;

// 0x5ac9e0 — int*(int* param_1, uint param_2, uint32_t* param_3); in_ECX receiver. If *(uint*)(self+0x20) <= param_2: addref param_3 if nonnull, if *(uint*)(self+0x1c)<=param_2 call FUN_0057a3f0(*(int*)(self+0x28)+param_2), FUN_00581300(param_2,&param_3), release old param_3, *param_1=0, return param_1. Else vec lookup puVar2=*(uint32_t**)(*(int*)(self+0x18)+param_2*4), addref both, FUN_00581300, release old, *param_1=puVar2, then decrement-release puVar2, return param_1.
int *FUN_005ac9e0(int *param_1, uint32_t param_2, uint32_t *param_3)
{
  void *self = nullptr;
  uint32_t *puVar4 = param_3;
  if (*(uint32_t *)((char *)self + 0x20) <= param_2) {
    if (param_3 != nullptr) {
      param_3[1] = param_3[1] + 1;
    }
    if (*(uint32_t *)((char *)self + 0x1c) <= param_2) {
      FUN_0057a3f0(*(int *)((char *)self + 0x28) + param_2);
    }
    FUN_00581300(param_2, &param_3);
    if (puVar4 != nullptr) {
      int *piVar1 = (int *)(puVar4 + 1);
      *piVar1 = *piVar1 - 1;
      if (*piVar1 == 0) {
        typedef void (*VirtFn)(int);
        VirtFn fn = *(VirtFn *)puVar4;
        fn(1);
      }
    }
    *param_1 = 0;
    return param_1;
  }
  uint32_t *puVar2 = *(uint32_t **)(*(intptr_t *)((char *)self + 0x18) + param_2 * 4);
  if (puVar2 != nullptr) {
    puVar2[1] = puVar2[1] + 1;
  }
  if (param_3 != nullptr) {
    param_3[1] = param_3[1] + 1;
  }
  FUN_00581300(param_2, &param_3);
  if (puVar4 != nullptr) {
    int *piVar1 = (int *)(puVar4 + 1);
    *piVar1 = *piVar1 - 1;
    if (*piVar1 == 0) {
      typedef void (*VirtFn)(int);
      VirtFn fn = *(VirtFn *)puVar4;
      fn(1);
    }
  }
  *param_1 = (int)(intptr_t)puVar2;
  if (puVar2 != nullptr) {
    int iVar3 = puVar2[1];
    puVar2[1] = iVar3 + 1;
    puVar2[1] = iVar3;
    if (iVar3 == 0) {
      typedef void (*VirtFn)(int);
      VirtFn fn = *(VirtFn *)puVar2;
      fn(1);
    }
  }
  return param_1;
}

// 0x5acab0 — void(param_1, uint32_t* param_2); in_ECX receiver. FUN_005ae060(param_1,param_2); iterate self vec (self+0x20 count, self+0x18 base): for each nonnull piVar1 call virtual (*piVar1+8)(param_2), pass result to FUN_005ac9e0(&param_2, i, result), then release param_2.
void FUN_005acab0(uint32_t param_1, uint32_t *param_2)
{
  void *self = nullptr;
  uint32_t *puVar2 = param_2;
  FUN_005ae060(param_1, param_2);
  uint32_t uVar4 = 0;
  if (*(int *)((char *)self + 0x20) != 0) {
    do {
      int *piVar1 = *(int **)(*(intptr_t *)((char *)self + 0x18) + uVar4 * 4);
      if (piVar1 != nullptr) {
        typedef uint32_t (*VirtFn)(uint32_t *);
        VirtFn fn = *(VirtFn *)(*(intptr_t *)piVar1 + 8);
        uint32_t uVar3 = fn(puVar2);
        FUN_005ac9e0((int *)&param_2, uVar4, (uint32_t *)(intptr_t)uVar3);
        if (param_2 != nullptr) {
          int *pi2 = (int *)(param_2 + 1);
          *pi2 = *pi2 - 1;
          if (*pi2 == 0) {
            typedef void (*VirtFn2)(int);
            VirtFn2 fn2 = *(VirtFn2 *)param_2;
            fn2(1);
          }
        }
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint32_t *)((char *)self + 0x20));
  }
}

// 0x5acbd0 — void(param_1, float param_2); in_ECX receiver. iVar5=(int)param_2; table check +0x48; psVar1=(short*)(param_2+0x24); clamp param_2 to 1.0 and vs *(in_ECX+0x14) ratio; fVar4 similarly vs *(in_ECX+0x18) and *(in_ECX+0x10)+0xac comparison; fVar4 = min(param_2,fVar4), floor _DAT_00717c60; store *(float*)(iVar2 + *(ushort*)(iVar5+0x26)*4)=fVar4; FUN_005ae030().
void FUN_005acbd0(uint32_t param_1, float param_2)
{
  void *self = nullptr;
  (void)param_1;
  int iVar5 = (int)param_2;
  int iVar2 = *(int *)(*(int *)(*(int *)(*(intptr_t)self + 0x10) + 0x34) + 0xbc);
  if ((iVar2 != 0) && (iVar2 = *(int *)(iVar2 + 0x48), iVar2 != 0)) {
    short *psVar1 = (short *)((intptr_t)param_2 + 0x24);
    param_2 = 1.0f;
    if ((*psVar1 == 0) && (*(float *)(iVar5 + 0x18) < *(float *)((char *)self + 0x14))) {
      param_2 = *(float *)(iVar5 + 0x18) / *(float *)((char *)self + 0x14);
    }
    float fVar4 = 1.0f;
    float fVar3 = *(float *)(iVar5 + 0x1c) - *(float *)(iVar5 + 0x18);
    if ((*psVar1 == *(short *)(*(int *)(*(intptr_t)self + 0x10) + 0xac)) &&
        (fVar3 < *(float *)((char *)self + 0x18))) {
      fVar4 = fVar3 / *(float *)((char *)self + 0x18);
    }
    if (param_2 < fVar4) {
      fVar4 = param_2;
    }
    if (fVar4 < _DAT_00717c60) {
      fVar4 = _DAT_00717c60;
    }
    *(float *)(iVar2 + (uint32_t)*(uint16_t *)(iVar5 + 0x26) * 4) = fVar4;
  }
  FUN_005ae030();
}

// 0x5acc90 — uint32_t*(param_1); in_ECX receiver. puVar1 = FUN_00533c78(0x1c); if nonnull: FUN_005383d0(), *p=&PTR_FUN_006c5350, p[3]=p[4]=0, *p=&PTR_FUN_006c54b8, p[5]=p[6]=0. Then FUN_005ae060(puVar1,param_1), puVar1[5]=*(uint*)(self+0x14), puVar1[6]=*(uint*)(self+0x18); return p.
uint32_t *FUN_005acc90(uint32_t param_1)
{
  void *self = nullptr;
  uint32_t *puVar1 = FUN_00533c78(0x1c);
  if (puVar1 != nullptr) {
    FUN_005383d0();
    puVar1[0] = (uint32_t)(intptr_t)&PTR_FUN_006c5350;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[0] = (uint32_t)(intptr_t)&PTR_FUN_006c54b8;
    puVar1[5] = 0;
    puVar1[6] = 0;
  }
  FUN_005ae060((uint32_t)(intptr_t)puVar1, param_1);
  puVar1[5] = *(uint32_t *)((char *)self + 0x14);
  puVar1[6] = *(uint32_t *)((char *)self + 0x18);
  return puVar1;
}

// 0x5acde0 — void(param_1). Calls FUN_005ae010(param_1) then FUN_00545cc0().
void FUN_005acde0(uint32_t param_1)
{
  FUN_005ae010(param_1);
  FUN_00545cc0();
}
