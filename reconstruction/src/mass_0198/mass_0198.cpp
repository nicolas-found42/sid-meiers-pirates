// Reconstruction batch mass_0198 — Sid Meier's Pirates! (2004), PE32 i386
#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cmath>

// --- referenced helpers -----------------------------------------------------
extern void FUN_005383d0(void* self);              // base constructor (this-call)
extern void FUN_005e4780(void* self);              // base destructor part
extern void FUN_005ab6a0(void* self);              // base destructor part
extern void operator_delete(void* p);
extern void FUN_0056e040(float* out4, float t, uint32_t a, uint32_t b, uint32_t c, uint32_t* out);
extern void FUN_005ae030(uint32_t param_1, int param_2);
extern void FUN_005ae060(void* self, void* dst, uint32_t param_2);
extern void FUN_005ae010(void* param_1);
extern void FUN_005ae170(void* self, int* param_1);
extern void FUN_00535110(int param_1);
extern uint32_t FUN_005ae1a0(void* self, int param_1);
extern void FUN_00538410(void* dst, uint32_t param_1);
extern int FUN_005bd960(int key, uint32_t* out);
extern void FUN_00513ce0(uint32_t param_1);
extern void* FUN_00545600(void);
extern uint8_t FUN_00538360(uint32_t param_1);
extern void FUN_00538430(void* obj);
extern uint32_t FUN_00538460(int param_1);
extern void FUN_005aa9b0(uint32_t param_1, uint32_t param_2, int param_3);
extern uint32_t FUN_005a8fe0(int param_1);

// --- referenced globals / vtables -------------------------------------------
extern void* PTR_FUN_006c5350;
extern void* PTR_FUN_006c5500;
extern void* PTR_FUN_006c5548;
extern void* PTR_FUN_006c5590;
extern void* PTR_FUN_006c55d8;
extern uint32_t DAT_00727430;
extern uint32_t DAT_00727434;
extern uint32_t DAT_00727438;

typedef void (*Virt2)(void* p, int n);
typedef void (*Virt1)(uint32_t v);
typedef void* (*VirtGet)(uint32_t v);

// 0x5ace80 — observed shape
// void(undefined4* param_1); in_ECX receiver. Refcounted pointer swap into
// self+0x14, then recompute the two cached bounds at self+0x18 / self+0x1c.
void FUN_005ace80(void* self, uint32_t* param_1)
{
  uint8_t* s = (uint8_t*)self;
  uint32_t* puVar2 = *(uint32_t**)(s + 0x14);

  if (puVar2 != param_1) {
    if (puVar2 != nullptr) {
      uint32_t* piVar1 = puVar2 + 1;
      *piVar1 = *piVar1 - 1;
      if (*piVar1 == 0) {
        typedef void (*DtorFn)(int);
        DtorFn fn = *(DtorFn*)(*(void**)puVar2);
        fn(1);
      }
    }
    *(uint32_t**)(s + 0x14) = param_1;
    if (param_1 != nullptr) {
      param_1[1] = param_1[1] + 1;
    }
  }

  uint32_t iVar3 = *(uint32_t*)(s + 0x14);
  *(uint32_t*)(s + 0x18) = 0;
  *(uint32_t*)(s + 0x1c) = 0;
  if (iVar3 != 0) {
    uint32_t iVar4 = *(uint32_t*)(iVar3 + 0xc);
    uint32_t* puVar2b = *(uint32_t**)(iVar3 + 0x10);
    if (iVar4 != 0) {
      *(uint32_t*)(s + 0x18) = *puVar2b;
      *(uint32_t*)(s + 0x1c) =
          *(uint32_t*)((uint32_t)(*(uint8_t*)(puVar2b + 1)) * (iVar4 - 1) + (int)(intptr_t)puVar2b);
    }
  }
}

// 0x5acee0 — observed shape
// void(); in_ECX receiver. Constructor: base init, two vtable stores, clear 3..7.
void FUN_005acee0(void* self)
{
  uint32_t* s = (uint32_t*)self;

  FUN_005383d0(self);
  s[0] = (uint32_t)(intptr_t)&PTR_FUN_006c5350;
  s[3] = 0;
  s[4] = 0;
  s[0] = (uint32_t)(intptr_t)&PTR_FUN_006c5500;
  s[5] = 0;
  s[6] = 0;
  s[7] = 0;
}

// 0x5acf50 — observed shape
// void(undefined4 param_1, float/ptr param_2); in_ECX receiver. param_2 is an
// object pointer (ratio at +0x18/+0x1c, ushort index at +0x26); the decompiler
// retyped it float after spilling it to iVar3.
void FUN_005acf50(void* self, uint32_t param_1, void* param_2)
{
  uint8_t* s = (uint8_t*)self;
  uint8_t* obj = (uint8_t*)param_2;
  int iVar3 = (int)(intptr_t)param_2;
  int iVar1 = *(int*)(*(int*)(*(int*)(s + 0x10) + 0x34) + 0xbc);

  if (iVar1 != 0) {
    iVar1 = *(int*)(iVar1 + 0x28);
    if (iVar1 != 0) {
      float value = *(float*)(obj + 0x18) / *(float*)(obj + 0x1c);
      if (value <= *(float*)(s + 0x18)) value = *(float*)(s + 0x18);
      if (*(float*)(s + 0x1c) <= value) value = *(float*)(s + 0x1c);

      int iVar2 = *(int*)(s + 0x14);
      uint32_t local_14 = 0;
      float local_10, local_c, local_8, local_4;

      FUN_0056e040(&local_10, value,
                   *(uint32_t*)(iVar2 + 0x10),
                   *(uint32_t*)(iVar2 + 0x14),
                   *(uint32_t*)(iVar2 + 0xc),
                   &local_14);

      if (local_10 < 0.0f) local_10 = 0.0f;
      else if (1.0f < local_10) local_10 = 1.0f;

      if (local_c < 0.0f) local_c = 0.0f;
      else if (1.0f < local_c) local_c = 1.0f;

      if (local_8 < 0.0f) local_8 = 0.0f;
      else if (1.0f < local_8) local_8 = 1.0f;

      if (local_4 < 0.0f) local_4 = 0.0f;
      else if (1.0f < local_4) local_4 = 1.0f;

      float* pfVar4 = (float*)((uint32_t)*(uint16_t*)(obj + 0x26) * 0x10 + iVar1);
      pfVar4[0] = local_10;
      pfVar4[1] = local_c;
      pfVar4[2] = local_8;
      pfVar4[3] = local_4;
    }
  }
  FUN_005ae030(param_1, iVar3);
}

// 0x5ad140 — observed shape
// void(byte param_1); in_ECX receiver. Destructor pair then conditional delete.
void FUN_005ad140(void* self, uint8_t param_1)
{
  FUN_005e4780(self);
  FUN_005ab6a0(self);
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x5ad1b0 — observed shape
// void(int param_1, undefined4 param_2); in_ECX receiver. Copy-construct:
// FUN_005ae060(dst, param_2) then copy 12 dwords into the destination.
void FUN_005ad1b0(void* self, void* param_1, uint32_t param_2)
{
  uint8_t* s = (uint8_t*)self;
  uint8_t* d = (uint8_t*)param_1;

  FUN_005ae060(self, param_1, param_2);
  *(uint32_t*)(d + 0x14) = *(uint32_t*)(s + 0x14);
  *(uint32_t*)(d + 0x18) = *(uint32_t*)(s + 0x18);
  *(uint32_t*)(d + 0x1c) = *(uint32_t*)(s + 0x1c);
  *(uint32_t*)(d + 0x20) = *(uint32_t*)(s + 0x20);
  *(uint32_t*)(d + 0x24) = *(uint32_t*)(s + 0x24);
  *(uint32_t*)(d + 0x28) = *(uint32_t*)(s + 0x28);
  *(uint32_t*)(d + 0x38) = *(uint32_t*)(s + 0x38);
  *(uint32_t*)(d + 0x3c) = *(uint32_t*)(s + 0x3c);
  *(uint32_t*)(d + 0x40) = *(uint32_t*)(s + 0x40);
  *(uint32_t*)(d + 0x2c) = *(uint32_t*)(s + 0x2c);
  *(uint32_t*)(d + 0x30) = *(uint32_t*)(s + 0x30);
  *(uint32_t*)(d + 0x34) = *(uint32_t*)(s + 0x34);
}

// 0x5ad220 — observed shape
// void(); in_ECX receiver. Constructor: base init, vtable 0x6c5548, 3..0x10 init.
void FUN_005ad220(void* self)
{
  uint32_t* s = (uint32_t*)self;
  uint32_t uVar1;

  FUN_005383d0(self);
  s[0] = (uint32_t)(intptr_t)&PTR_FUN_006c5350;
  s[3] = 0;
  s[4] = 0;
  s[0] = (uint32_t)(intptr_t)&PTR_FUN_006c5548;
  s[0xb] = DAT_00727430;
  s[0xc] = DAT_00727434;
  s[0xd] = DAT_00727438;
  s[0xe] = DAT_00727430;
  s[0xf] = DAT_00727434;
  uVar1 = DAT_00727438;
  s[7] = 0;
  s[8] = 0;
  s[9] = 0;
  s[10] = 0;
  s[5] = 0;
  s[6] = 0;
  s[0x10] = uVar1;
}

// 0x5ad7b0 — observed shape
// void(int param_1, undefined4 param_2); in_ECX receiver. Copy-construct:
// FUN_005ae060(dst, param_2) then copy 9 dwords (0x14..0x34).
void FUN_005ad7b0(void* self, void* param_1, uint32_t param_2)
{
  uint8_t* s = (uint8_t*)self;
  uint8_t* d = (uint8_t*)param_1;

  FUN_005ae060(self, param_1, param_2);
  *(uint32_t*)(d + 0x14) = *(uint32_t*)(s + 0x14);
  *(uint32_t*)(d + 0x18) = *(uint32_t*)(s + 0x18);
  *(uint32_t*)(d + 0x1c) = *(uint32_t*)(s + 0x1c);
  *(uint32_t*)(d + 0x20) = *(uint32_t*)(s + 0x20);
  *(uint32_t*)(d + 0x24) = *(uint32_t*)(s + 0x24);
  *(uint32_t*)(d + 0x28) = *(uint32_t*)(s + 0x28);
  *(uint32_t*)(d + 0x2c) = *(uint32_t*)(s + 0x2c);
  *(uint32_t*)(d + 0x30) = *(uint32_t*)(s + 0x30);
  *(uint32_t*)(d + 0x34) = *(uint32_t*)(s + 0x34);
}

// 0x5ad810 — observed shape
// void(); in_ECX receiver. Constructor: vtable 0x6c5590, 1.0f at self[6].
void FUN_005ad810(void* self)
{
  uint32_t* s = (uint32_t*)self;
  uint32_t uVar1;

  FUN_005383d0(self);
  s[0] = (uint32_t)(intptr_t)&PTR_FUN_006c5350;
  s[3] = 0;
  s[4] = 0;
  s[0] = (uint32_t)(intptr_t)&PTR_FUN_006c5590;
  s[8] = DAT_00727430;
  s[9] = DAT_00727434;
  s[10] = DAT_00727438;
  s[0xb] = DAT_00727430;
  s[0xc] = DAT_00727434;
  uVar1 = DAT_00727438;
  s[7] = 0;
  s[5] = 0;
  s[0xd] = uVar1;
  s[6] = 0x3f800000;  // 1.0f
}

// 0x5adb50 — observed shape
// void(int param_1); in_ECX receiver. Reads 3 dwords through the stream object
// at param_1+0x15c, stores the second in self+0x1c, calls FUN_00535110 twice.
// in_EDI is the incoming register argument assigned to self+0x1c.
void FUN_005adb50(void* self, void* param_1, uint32_t in_EDI)
{
  uint8_t* s = (uint8_t*)self;
  uint32_t in_ECX = (uint32_t)(uintptr_t)self;
  uint8_t* p = (uint8_t*)param_1;
  uint8_t auStack_c[12];
  void** vt;
  Virt2 fn;

  FUN_005ae010(param_1);

  vt = *(void***)(*(int**)(p + 0x15c));
  fn = (Virt2)vt[2];                       // vtable slot +8
  fn((void*)(intptr_t)(in_ECX + 0x14), 4);
  fn((void*)(intptr_t)(in_ECX + 0x18), 4);
  fn(auStack_c, 4);

  *(uint32_t*)(intptr_t)(in_ECX + 0x1c) = in_EDI;

  FUN_00535110((int)(intptr_t)param_1);
  FUN_00535110((int)(intptr_t)param_1);

  // self-assignments preserved from the listing
  *(uint32_t*)(s + 0x2c) = *(uint32_t*)(s + 0x2c);
  *(uint32_t*)(s + 0x30) = *(uint32_t*)(s + 0x30);
  *(uint32_t*)(s + 0x34) = *(uint32_t*)(s + 0x34);
}

// 0x5adcf0 — observed shape
// ushort(int param_1); in_ECX receiver. Equality probe on the float at
// param_1+0x14 vs self+0x14, gated by FUN_005ae1a0.
uint16_t FUN_005adcf0(void* self, int param_1)
{
  uint8_t* s = (uint8_t*)self;
  uint16_t uVar3 = (uint16_t)FUN_005ae1a0(self, param_1);

  if ((uint8_t)uVar3 != 0) {
    float fVar1 = *(float*)(param_1 + 0x14);
    float fVar2 = *(float*)(s + 0x14);

    uVar3 = (uint16_t)((uint16_t)(fVar2 < fVar1) << 8) |
            (uint16_t)((uint16_t)(std::isnan(fVar2) || std::isnan(fVar1)) << 10) |
            (uint16_t)((uint16_t)(fVar2 == fVar1) << 0xe);

    if (fVar2 == fVar1) {
      // CONCAT11((char)(uVar3 >> 8), 1)
      return (uint16_t)((((uVar3 >> 8) & 0xff) << 8) | 1);
    }
  }
  return uVar3 & 0xff00;
}

// 0x5add20 — observed shape
// void(); in_ECX receiver. Constructor: vtable 0x6c55d8, two flag bytes zeroed,
// 1.0f at self[5], 3 constant words at self[7..9], self[10]=0.
void FUN_005add20(void* self)
{
  uint32_t* s = (uint32_t*)self;
  uint32_t uVar1;

  FUN_005383d0(self);
  s[0] = (uint32_t)(intptr_t)&PTR_FUN_006c5350;
  s[3] = 0;
  s[4] = 0;
  *(uint8_t*)((uint8_t*)s + 6) = 0;
  *(uint8_t*)((uint8_t*)s + 0x19) = 0;
  s[0] = (uint32_t)(intptr_t)&PTR_FUN_006c55d8;
  s[5] = 0x3f800000;  // 1.0f
  s[7] = DAT_00727430;
  s[8] = DAT_00727434;
  uVar1 = DAT_00727438;
  s[10] = 0;
  s[9] = uVar1;
}

// 0x5adda0 — observed shape
// void(int param_1); in_ECX receiver (undefined4*). Registers self as the
// listener of param_1 (scan of the +0xd4 list) and installs self in param_1+0xd4.
void FUN_005adda0(void* self, void* param_1)
{
  uint32_t* in_ECX = (uint32_t*)self;
  uint8_t* p = (uint8_t*)param_1;
  uint32_t* puVar2;

  in_ECX[4] = (uint32_t)(intptr_t)param_1;
  puVar2 = *(uint32_t**)(p + 0xd4);
  while (true) {
    if (puVar2 == nullptr) {
      puVar2 = *(uint32_t**)(p + 0xd4);
      uint32_t* puVar3 = (uint32_t*)(intptr_t)in_ECX[3];
      if (puVar3 != puVar2) {
        if (puVar3 != nullptr) {
          uint32_t* piVar1 = puVar3 + 1;
          *piVar1 = *piVar1 - 1;
          if (*piVar1 == 0) {
            typedef void (*DtorFn)(int);
            DtorFn fn = *(DtorFn*)(*(void**)puVar3);
            fn(1);
          }
        }
        in_ECX[3] = (uint32_t)(intptr_t)puVar2;
        if (puVar2 != nullptr) {
          puVar2[1] = puVar2[1] + 1;
        }
      }

      int iVar4 = (int)in_ECX[4];
      puVar2 = *(uint32_t**)((uint8_t*)iVar4 + 0xd4);
      if (puVar2 != in_ECX) {
        if (puVar2 != nullptr) {
          uint32_t* piVar1 = puVar2 + 1;
          *piVar1 = *piVar1 - 1;
          if (*piVar1 == 0) {
            typedef void (*DtorFn)(int);
            DtorFn fn = *(DtorFn*)(*(void**)puVar2);
            fn(1);
          }
        }
        *(uint32_t**)((uint8_t*)iVar4 + 0xd4) = in_ECX;
        in_ECX[1] = in_ECX[1] + 1;
      }
      return;
    }
    if (puVar2 == in_ECX) break;
    puVar2 = (uint32_t*)(intptr_t)puVar2[3];
  }
}

// 0x5adec0 — observed shape
// uint(undefined4 param_1, int param_2); in_ECX receiver. Pushes the 3 floats of
// self+0x1c..0x24 into the per-instance record, optional notify, optional probe.
void FUN_005adec0(void* self, uint32_t param_1, int param_2)
{
  uint8_t* s = (uint8_t*)self;

  uint32_t* puVar1 = (uint32_t*)(*(int*)(*(int*)(*(int*)(*(int*)(s + 0x10) + 0x34) + 0xbc) + 0x20) +
                                 (uint32_t)*(uint16_t*)(param_2 + 0x26) * 0xc);
  puVar1[0] = *(uint32_t*)(s + 0x1c);
  puVar1[1] = *(uint32_t*)(s + 0x20);
  puVar1[2] = *(uint32_t*)(s + 0x24);

  if (*(uint8_t*)(s + 0x18) != 0) {
    FUN_005aa9b0(param_1, *(uint32_t*)(s + 0x28), param_2);
  }
  if (*(uint8_t*)(s + 0x19) == 0) {
    // CONCAT31 leftover-register artifact: the meaningful result is boolean 1
    return 1;
  }
  uint32_t uVar2 = FUN_005a8fe0(param_2);
  return uVar2 & 0xffffff00u;
}

// 0x5adf30 — observed shape
// void(int param_1); in_ECX receiver. Reads self+0x14 (4 bytes) through the
// stream at param_1+0x15c; for streams newer than 0x04020001 reads the two flag
// bytes 0x19 and 0x18.
void FUN_005adf30(void* self, void* param_1)
{
  uint8_t* s = (uint8_t*)self;
  uint32_t in_ECX = (uint32_t)(uintptr_t)self;
  uint8_t* p = (uint8_t*)param_1;
  void** vt;
  Virt2 fn;

  FUN_005ae010(param_1);

  vt = *(void***)(*(int**)(p + 0x15c));
  fn = (Virt2)vt[2];                       // vtable slot +8
  fn((void*)(intptr_t)(in_ECX + 0x14), 4);

  if (0x04020001u < *(uint32_t*)(p + 0x1c)) {
    // Listing seeds the first 1-byte scratch from self+0x18 (CONCAT31) and
    // takes the two read values from aliased stack slots; the two reads feed
    // the 0x19 then 0x18 flag bytes.
    uint8_t b19 = 0;
    fn(&b19, 1);
    *(uint8_t*)(s + 0x19) = (uint8_t)(b19 != 0);

    uint8_t b18 = 0;
    fn(&b18, 1);
    *(uint8_t*)(s + 0x18) = (uint8_t)(b18 != 0);
  }
}

// 0x5adfb0 — observed shape
// void(int param_1); in_ECX receiver. Write counterpart of 0x5adf30: emits
// self+0x14 (4 bytes) then the two flag bytes 0x18, 0x19 via slot +0xc.
void FUN_005adfb0(void* self, void* param_1)
{
  uint8_t* s = (uint8_t*)self;
  uint8_t* p = (uint8_t*)param_1;
  void** vt;
  Virt2 fn;

  // Ghidra prints no arguments here (prototype unknown at the call site); the
  // implementation takes the archive pointer, as at 0x5ac6b0.
  FUN_005ae170(self, (int*)(intptr_t)param_1);

  vt = *(void***)(*(int**)(p + 0x160));
  fn = (Virt2)vt[3];                       // vtable slot +0xc
  fn((void*)(s + 0x14), 4);

  // listing seeds a stack scratch with self+0x18 (CONCAT31) before emitting it
  uint8_t b18 = *(uint8_t*)(s + 0x18);
  fn(&b18, 1);

  // third byte source is an unseeded aliased slot in the listing; 0x19 is the
  // write counterpart of the second flag read in 0x5adf30
  uint8_t b19 = *(uint8_t*)(s + 0x19);
  fn(&b19, 1);
}

// 0x5ae060 — observed shape
// void(int param_1, undefined4 param_2); in_ECX receiver. Shared subobject
// copy: resolve param_2, write it plus the derived self+0xc reference.
void FUN_005ae060(void* self, void* param_1, uint32_t param_2)
{
  uint8_t* s = (uint8_t*)self;
  uint8_t* d = (uint8_t*)param_1;
  uint32_t uVar3 = param_2;
  uint32_t p2 = param_2;

  FUN_00538410(param_1, param_2);

  if (*(int*)(s + 0x10) != 0) {
    FUN_005bd960(*(int*)(s + 0x10), &p2);
    *(uint32_t*)(d + 0x10) = p2;
  }

  if (*(int**)(s + 0xc) != nullptr) {
    void** vt = *(void***)(*(int**)(s + 0xc));
    VirtGet get = (VirtGet)vt[2];          // vtable slot +8
    uint32_t* puVar4 = (uint32_t*)get(uVar3);
    uint32_t* puVar2 = *(uint32_t**)(d + 0xc);
    if (puVar2 != puVar4) {
      if (puVar2 != nullptr) {
        uint32_t* piVar1 = puVar2 + 1;
        *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) {
          typedef void (*DtorFn)(int);
          DtorFn fn = *(DtorFn*)(*(void**)puVar2);
          fn(1);
        }
      }
      *(uint32_t**)(d + 0xc) = puVar4;
      if (puVar4 != nullptr) {
        puVar4[1] = puVar4[1] + 1;
      }
    }
  }
}

// 0x5ae0f0 — observed shape
// void(undefined4 param_1); in_ECX receiver. FUN_00513ce0(param_1), then install
// a fresh reference at self+0xc and its raw pointer at self+0x10.
void FUN_005ae0f0(void* self, uint32_t param_1)
{
  uint8_t* s = (uint8_t*)self;

  FUN_00513ce0(param_1);

  uint32_t* puVar3 = (uint32_t*)FUN_00545600();
  uint32_t* puVar2 = *(uint32_t**)(s + 0xc);
  if (puVar2 != puVar3) {
    if (puVar2 != nullptr) {
      uint32_t* piVar1 = puVar2 + 1;
      *piVar1 = *piVar1 - 1;
      if (*piVar1 == 0) {
        typedef void (*DtorFn)(int);
        DtorFn fn = *(DtorFn*)(*(void**)puVar2);
        fn(1);
      }
    }
    *(uint32_t**)(s + 0xc) = puVar3;
    if (puVar3 != nullptr) {
      puVar3[1] = puVar3[1] + 1;
    }
  }

  uint32_t uVar4 = (uint32_t)(intptr_t)FUN_00545600();
  *(uint32_t*)(s + 0x10) = uVar4;
}

// 0x5ae140 — observed shape
// undefined1(undefined4 param_1); in_ECX receiver. Gate on FUN_00538360 then
// forward param_1 to the inner object's vtable slot +0x14.
uint8_t FUN_005ae140(void* self, uint32_t param_1)
{
  uint8_t* s = (uint8_t*)self;
  uint8_t cVar1 = FUN_00538360(param_1);

  if (cVar1 == 0) {
    return 0;
  }
  if (*(int**)(s + 0xc) != nullptr) {
    void** vt = *(void***)(*(int**)(s + 0xc));
    Virt1 fn = (Virt1)vt[5];               // vtable slot +0x14
    fn(param_1);
  }
  return 1;
}

// 0x5ae170 — observed shape
// void(int* param_1); in_ECX receiver. Stream prologue then emits self+0xc and
// self+0x10 through param_1's vtable slot +0x2c.
void FUN_005ae170(void* self, int* param_1)
{
  uint8_t* s = (uint8_t*)self;

  FUN_00538430(param_1);

  Virt1 fn = *(Virt1*)((uint8_t*)(intptr_t)*param_1 + 0x2c);
  fn(*(uint32_t*)(s + 0xc));
  fn(*(uint32_t*)(s + 0x10));
}

// 0x5ae1a0 — observed shape
// uint(int param_1); in_ECX receiver. Stream probe: FUN_00538460 gate, then
// compare self+0x10 with param_1+0x10, falling through to the inner vtable
// slot +0x1c when the probed value is zero.
uint32_t FUN_005ae1a0(void* self, int param_1)
{
  uint8_t* s = (uint8_t*)self;
  uint32_t uVar1;
  uint32_t uVar2 = 0;

  uVar1 = FUN_00538460(param_1);
  if ((uint8_t)uVar1 != 0) {
    uVar1 = *(uint32_t*)(s + 0x10);
    if (uVar1 != 0) {
      if (*(int*)(param_1 + 0x10) == 0) goto LAB_005ae1cb;
      uVar2 = uVar1;
      if (uVar1 != 0) goto LAB_005ae1d2;
    }
    uVar1 = *(uint32_t*)(param_1 + 0x10);
    uVar2 = 0;
    if (uVar1 == 0) goto LAB_005ae1d2;
  }

LAB_005ae1cb:
  return uVar1 & 0xffffff00u;

LAB_005ae1d2:
  {
    if (*(int**)(s + 0xc) == nullptr) {
      // CONCAT31((int3)(uVar2 >> 8), 1): meaningful result is boolean 1
      return 1;
    }
    void** vt = *(void***)(*(int**)(s + 0xc));
    typedef uint32_t (*Virt0)();
    Virt0 fn = (Virt0)vt[7];               // vtable slot +0x1c
    return fn();
  }
}
