// Reconstruction batch mass_0231 — Sid Meier's Pirates! (2004), PE32 i386
//
// Addresses reconstructed from the Ghidra 12.2 pseudocode corpus in
// analysis/pseudocode/functions/. Ghidra "in_ECX" receivers are surfaced as an
// explicit leading "void* self" parameter; the listing's own parameter order is
// kept after it. Helpers whose ECX receiver the listing does not expose are
// declared with the argument list that is actually observed at the call site.
#include <cstdint>
#include <cstddef>
#include <windows.h>

// --- referenced helpers -----------------------------------------------------
extern void* FUN_00533c78(std::size_t n);              // heap allocator
extern void* thunk_FUN_00533c78(std::size_t n);        // allocator thunk
extern void operator_delete(void* p);
extern void operator_delete__(void* p);
extern void FUN_005dd980(void* self);                  // base constructor (this-call)
extern void FUN_005dd9a0(void* self);                  // base destructor (this-call)
extern void FUN_005dd9f0(uint32_t* block, uint32_t value);
extern void FUN_005dda00(void* block);
extern uint32_t FUN_005dda40(int size, uint32_t* out_a, uint32_t* out_b, int mode);
extern void FUN_005d0610(void);
extern uint32_t* FUN_005d8c10(void* memory);           // ctor over allocated 0x48 bytes
extern char FUN_004879c0(void* a, void* b);
extern void FUN_00545310(uint32_t key, void* value);
extern char FUN_005bd960(uint32_t key, int* out);
extern int FUN_005d9360(int a, uint32_t b, uint32_t c, int d, int e);
extern void FUN_005606f0(uint32_t index, void* value);
extern void FUN_006b34a0(uint32_t value);
extern void FUN_005bfa50(int param_1);
extern void FUN_005e1490(void* self);
extern void FUN_005c99a0(void* self);
extern int FUN_005c54e0(void);
extern void FUN_005c99e0(int param_1);
extern void FUN_005c9fb0(void);
extern void FUN_005c9f50(void);
extern void FUN_005c11d0(uint32_t param_1, int param_2);
extern void FUN_005c2c50(uint32_t a, uint32_t b, int c, uint32_t d, int e);
extern void FUN_005c1290(uint32_t a, int b, uint32_t c);
extern void FUN_005cfe70(uint32_t a, uint32_t b, uint32_t c);
extern void FUN_005bf1c0(void);
extern void FUN_005cb730(void);
extern void FUN_005c1730(uint32_t* a, int b, uint32_t c, uint32_t d, uint32_t e, int f);
extern void FUN_005c1a50(uint32_t* a, int b, uint32_t c, uint32_t d, uint32_t e, uint32_t f,
                         int g);
extern void* FUN_005bd940(void);
extern uint32_t FUN_005dbd70(void);
extern void FUN_005ca660(uint32_t value);
extern void FUN_005d3090(uint32_t index, void** out);
extern void FUN_005d3120(void);
extern void FUN_005bf480(void);

// --- referenced globals / vtables -------------------------------------------
extern void* PTR_LAB_006c8d3c;
extern void* PTR_FUN_006c8cc8;
extern void* PTR_FUN_006c8d04;
extern void* PTR_FUN_006c8ce4;
extern void* PTR_FUN_006c8d20;
extern void* PTR_FUN_006c8d00;
extern void* PTR_FUN_006c8c28;
extern void* PTR_FUN_006c8720;
extern void* PTR_FUN_006c86b8;
extern uint32_t* DAT_00728ec4;
extern char DAT_007278d4;
extern char DAT_00727cc8;

// 0x5d9900 — observed shape
// void(int param_1, uint param_2); in_ECX receiver. Lazily creates the 0x48-byte
// (18 dword) stream record hanging off param_1+0x24, zero-fills it, forces its
// descriptor word 0xd to 6, seeds the header from param_2, param_1+0x18 and
// self+8, then registers it through FUN_005dd9f0 and sets param_1+0x20 = 0xffff.
void FUN_005d9900(void* self, uint8_t* param_1, uint32_t param_2)
{
  uint32_t* selfWords = reinterpret_cast<uint32_t*>(self);

  if (*reinterpret_cast<int32_t*>(param_1 + 0x24) == 0) {
    uint32_t* puVar1 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x48));
    if (puVar1 == nullptr) {
      puVar1 = nullptr;
    } else {
      puVar1[0x00] = 0;
      puVar1[0x01] = 0;
      puVar1[0x02] = 0;
      puVar1[0x03] = 0;
      puVar1[0x04] = 0;
      puVar1[0x05] = 0;
      puVar1[0x06] = 0;
      puVar1[0x07] = 0;
      puVar1[0x08] = 0;
      puVar1[0x09] = 0;
      puVar1[0x0a] = 0;
      puVar1[0x0b] = 0;
      puVar1[0x0c] = 0;
      puVar1[0x0d] = 4;
      puVar1[0x0e] = 0;
      puVar1[0x0f] = 0;
      puVar1[0x10] = 0;
      puVar1[0x11] = 0;
    }
    puVar1[0x0d] = 6;
    *reinterpret_cast<uint32_t*>(param_1 + 0x24) = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar1));
    uint32_t uVar2 = (param_2 & 0x7fffff) |
                     static_cast<uint32_t>(*reinterpret_cast<int32_t*>(param_1 + 0x18) != 0) << 0x18 |
                     selfWords[2];
    *puVar1 = uVar2;
    FUN_005dd9f0(puVar1, uVar2);
    *reinterpret_cast<uint16_t*>(param_1 + 0x20) = 0xffff;
  }
  return;
}

// 0x5d99a0 — observed shape
// void(int param_1). Releases the record at param_1+0x24: FUN_005dda00, zeroes
// the backing store (count = word[0x14] & 0x3fffffff dwords), FUN_005d0610,
// operator_delete, null the slot.
void FUN_005d99a0(uint8_t* param_1)
{
  void* pvVar1 = reinterpret_cast<void*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(param_1 + 0x24)));
  if (pvVar1 != nullptr) {
    uint8_t* p = reinterpret_cast<uint8_t*>(pvVar1);
    FUN_005dda00(pvVar1);
    if (*reinterpret_cast<uint32_t**>(p + 0x1c) != nullptr) {
      uint32_t* puVar4 = *reinterpret_cast<uint32_t**>(p + 0x1c);
      for (uint32_t uVar2 = *reinterpret_cast<uint32_t*>(p + 0x14) & 0x3fffffff; uVar2 != 0;
           uVar2 = uVar2 - 1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      for (int iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *reinterpret_cast<uint8_t*>(puVar4) = 0;
        puVar4 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar4) + 1);
      }
    }
    FUN_005d0610();
    operator_delete(pvVar1);
    *reinterpret_cast<uint32_t*>(param_1 + 0x24) = 0;
  }
  return;
}

// 0x5d99f0 — observed shape
// void(int param_1, uint param_2); in_ECX receiver. Same lazy creation as
// FUN_005d9900 but on param_1+0x20 with descriptor word 4 and header bit 0x1000000
// always set; finally param_1+0x1c = 0xffff.
void FUN_005d99f0(void* self, uint8_t* param_1, uint32_t param_2)
{
  uint32_t* selfWords = reinterpret_cast<uint32_t*>(self);

  if (*reinterpret_cast<int32_t*>(param_1 + 0x20) == 0) {
    uint32_t* puVar1 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x48));
    if (puVar1 == nullptr) {
      puVar1 = nullptr;
    } else {
      puVar1[0x00] = 0;
      puVar1[0x01] = 0;
      puVar1[0x02] = 0;
      puVar1[0x03] = 0;
      puVar1[0x04] = 0;
      puVar1[0x05] = 0;
      puVar1[0x06] = 0;
      puVar1[0x07] = 0;
      puVar1[0x08] = 0;
      puVar1[0x09] = 0;
      puVar1[0x0a] = 0;
      puVar1[0x0b] = 0;
      puVar1[0x0c] = 0;
      puVar1[0x0d] = 4;
      puVar1[0x0e] = 0;
      puVar1[0x0f] = 0;
      puVar1[0x10] = 0;
      puVar1[0x11] = 0;
    }
    puVar1[0x0d] = 4;
    *reinterpret_cast<uint32_t*>(param_1 + 0x20) = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar1));
    uint32_t uVar2 = (param_2 & 0x7fffff) | selfWords[2] | 0x1000000;
    *puVar1 = uVar2;
    FUN_005dd9f0(puVar1, uVar2);
    *reinterpret_cast<uint16_t*>(param_1 + 0x1c) = 0xffff;
  }
  return;
}

// 0x5d9a80 — observed shape
// void(int param_1). Teardown twin of FUN_005d99f0 for the record at param_1+0x20.
void FUN_005d9a80(uint8_t* param_1)
{
  void* pvVar1 = reinterpret_cast<void*>(static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(param_1 + 0x20)));
  if (pvVar1 != nullptr) {
    uint8_t* p = reinterpret_cast<uint8_t*>(pvVar1);
    FUN_005dda00(pvVar1);
    if (*reinterpret_cast<uint32_t**>(p + 0x1c) != nullptr) {
      uint32_t* puVar4 = *reinterpret_cast<uint32_t**>(p + 0x1c);
      for (uint32_t uVar2 = *reinterpret_cast<uint32_t*>(p + 0x14) & 0x3fffffff; uVar2 != 0;
           uVar2 = uVar2 - 1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      for (int iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *reinterpret_cast<uint8_t*>(puVar4) = 0;
        puVar4 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar4) + 1);
      }
    }
    FUN_005d0610();
    operator_delete(pvVar1);
    *reinterpret_cast<uint32_t*>(param_1 + 0x20) = 0;
  }
  return;
}

// 0x5d9b00 — observed shape
// undefined4*(uint size, int* extra, undefined4 a, undefined4 b). Allocates a
// 0x18-byte (6 dword) block, rounds `size` up to 0x20 alignment when the low nibble
// is set, stores it at word 2, releases a pre-existing word-3 object (dead here: the
// block was just zeroed), then attaches `extra` (with a vtable+4 addref) or stores
// the plain a/b fallbacks.
uint32_t* FUN_005d9b00(uint32_t param_1, int32_t* param_2, uint32_t param_3, uint32_t param_4)
{
  uint32_t* puVar2 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x18));
  if (puVar2 == nullptr) {
    return nullptr;
  }
  puVar2[0] = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = 0;
  if ((param_1 & 0xf) != 0) {
    param_1 = (param_1 & 0xfffffff0) + 0x20;
  }
  puVar2[2] = param_1;
  int32_t* piVar1 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(puVar2[3]));
  if (piVar1 != nullptr) {
    typedef void (*ReleaseFn)(void*);
    ReleaseFn fn = *reinterpret_cast<ReleaseFn*>(static_cast<uintptr_t>(
        *reinterpret_cast<uint32_t*>(piVar1)) + 8);
    fn(reinterpret_cast<void*>(piVar1));
  }
  if (param_2 == nullptr) {
    puVar2[3] = 0;
    puVar2[1] = param_3;
    *puVar2 = param_4;
    return puVar2;
  }
  puVar2[3] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_2));
  typedef void (*AddRefFn)(void*);
  AddRefFn fn = *reinterpret_cast<AddRefFn*>(static_cast<uintptr_t>(
      *reinterpret_cast<uint32_t*>(param_2)) + 4);
  fn(reinterpret_cast<void*>(param_2));
  puVar2[1] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_2));
  *puVar2 = param_3;
  return puVar2;
}

// 0x5d9b80 — observed shape
// void(void); in_ECX receiver. Constructor of the 0x64-byte (0x18 dword + 4) object:
// base ctor, vtable 0x6c8d3c, two 0x94-byte embedded hash tables (0x25 dword capacity
// each at words 6 and 0x0a), vtable subobjects at words 4/8/0xc/0x12 and the scalar
// flags at the tail. Returns self in EAX (the caller stores that into DAT_00728ec4).
void* FUN_005d9b80(void* self)
{
  uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);

  FUN_005dd980(self);
  in_ECX[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(PTR_LAB_006c8d3c));
  in_ECX[4] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(PTR_FUN_006c8cc8));
  in_ECX[5] = 0x25;
  in_ECX[7] = 0;
  uint32_t* puVar1 = reinterpret_cast<uint32_t*>(thunk_FUN_00533c78(0x94));
  in_ECX[6] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar1));
  for (uint32_t uVar2 = in_ECX[5] & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  for (int iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *reinterpret_cast<uint8_t*>(puVar1) = 0;
    puVar1 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar1) + 1);
  }
  in_ECX[4] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(PTR_FUN_006c8d04));
  in_ECX[8] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(PTR_FUN_006c8ce4));
  in_ECX[9] = 0x25;
  in_ECX[0xb] = 0;
  puVar1 = reinterpret_cast<uint32_t*>(thunk_FUN_00533c78(0x94));
  in_ECX[10] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar1));
  for (uint32_t uVar2 = in_ECX[9] & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  for (int iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *reinterpret_cast<uint8_t*>(puVar1) = 0;
    puVar1 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar1) + 1);
  }
  in_ECX[8] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(PTR_FUN_006c8d20));
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xc] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(PTR_FUN_006c8d00));
  in_ECX[0x11] = 1;
  in_ECX[0x14] = 0;
  in_ECX[0x17] = 1;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x12] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(PTR_FUN_006c8c28));
  in_ECX[0x18] = 0;
  return self;
}

// 0x5d9c50 — observed shape
// void(void); in_ECX receiver. Full destructor: re-stamps vtable 0x6c8d3c, drains the
// two hash tables at words 5/6 and 9/10 (bucket walk using each table's vtable+4 hash
// functor, releasing the payload pointers at +0xc/+0x10 through vtable+8 and freeing
// the node), then tears down the container at 0xe..0x10 (payload releases, count
// decrements), the reference-counted slots 0xc/0xb/9 (vtable[0](1) when the refcount
// at +4 falls to zero), clears the singleton if it is this object, and finally calls
// the four FUN_005e1490 sub-object destructors, both operator_delete__ buffers and
// the base destructor.
void FUN_005d9c50(void* self)
{
  uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
  int* piVar4;
  void* pvVar6;
  int iVar1;

  *in_ECX = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(PTR_LAB_006c8d3c));

  uint32_t uVar3 = 0;
  if (in_ECX[5] != 0) {
    piVar4 = reinterpret_cast<int*>(static_cast<uintptr_t>(in_ECX[6]));
    do {
      if (*piVar4 != 0) {
        piVar4 = reinterpret_cast<int*>(static_cast<uintptr_t>(
            reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(in_ECX[6]))[uVar3]));
        goto joined_r0x005d9c86;
      }
      uVar3 = uVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (uVar3 < static_cast<uint32_t>(in_ECX[5]));
  }
  piVar4 = nullptr;
joined_r0x005d9c86:
  while (piVar4 != nullptr) {
    iVar1 = piVar4[1];
    pvVar6 = reinterpret_cast<void*>(static_cast<uintptr_t>(
        static_cast<uint32_t>(piVar4[2])));
    piVar4 = reinterpret_cast<int*>(static_cast<uintptr_t>(
        static_cast<uint32_t>(*piVar4)));
    if (piVar4 == nullptr) {
      int (*hashFn)(int) = *reinterpret_cast<int (**)(int)>(
          static_cast<uintptr_t>(in_ECX[4]) + 4);
      int iVar5 = hashFn(iVar1);
      uVar3 = static_cast<uint32_t>(iVar5) + 1;
      if (uVar3 < static_cast<uint32_t>(in_ECX[5])) {
        uint32_t* puVar7 = reinterpret_cast<uint32_t*>(
            static_cast<uintptr_t>(in_ECX[6])) + uVar3;
        do {
          piVar4 = reinterpret_cast<int*>(static_cast<uintptr_t>(*puVar7));
          if (piVar4 != nullptr) goto LAB_005d9cc0;
          uVar3 = uVar3 + 1;
          puVar7 = puVar7 + 1;
        } while (uVar3 < static_cast<uint32_t>(in_ECX[5]));
      }
      piVar4 = nullptr;
    }
LAB_005d9cc0:
    FUN_005bfa50(iVar1);
    if (pvVar6 != nullptr) {
      int* piVar2 = *reinterpret_cast<int**>(reinterpret_cast<uint8_t*>(pvVar6) + 0x10);
      if (piVar2 != nullptr) {
        typedef void (*ReleaseFn)(void*);
        ReleaseFn fn = *reinterpret_cast<ReleaseFn*>(
            static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(piVar2)) + 8);
        fn(reinterpret_cast<void*>(piVar2));
      }
      piVar2 = *reinterpret_cast<int**>(reinterpret_cast<uint8_t*>(pvVar6) + 0x0c);
      if (piVar2 != nullptr) {
        typedef void (*ReleaseFn2)(void*);
        ReleaseFn2 fn = *reinterpret_cast<ReleaseFn2*>(
            static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(piVar2)) + 8);
        fn(reinterpret_cast<void*>(piVar2));
      }
      operator_delete(pvVar6);
    }
  }

  uVar3 = 0;
  if (in_ECX[9] != 0) {
    piVar4 = reinterpret_cast<int*>(static_cast<uintptr_t>(in_ECX[10]));
    do {
      if (*piVar4 != 0) {
        piVar4 = reinterpret_cast<int*>(static_cast<uintptr_t>(
            reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(in_ECX[10]))[uVar3]));
        goto joined_r0x005d9d1a;
      }
      uVar3 = uVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (uVar3 < static_cast<uint32_t>(in_ECX[9]));
  }
  piVar4 = nullptr;
joined_r0x005d9d1a:
  do {
    if (piVar4 == nullptr) {
      uVar3 = 0;
      if (in_ECX[0xe] != 0) {
        do {
          if (uVar3 < static_cast<uint32_t>(in_ECX[0xf])) {
            pvVar6 = *reinterpret_cast<void**>(static_cast<uintptr_t>(
                in_ECX[0xd] + uVar3 * 4));
            *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(
                in_ECX[0xd] + uVar3 * 4)) = 0;
            if (pvVar6 != nullptr) {
              in_ECX[0x10] = in_ECX[0x10] + -1;
            }
            if (uVar3 == in_ECX[0xf] - 1) {
              in_ECX[0xf] = in_ECX[0xf] - 1;
            }
            if (pvVar6 != nullptr) {
              int* piVar2 = *reinterpret_cast<int**>(
                  reinterpret_cast<uint8_t*>(pvVar6) + 0x10);
              if (piVar2 != nullptr) {
                typedef void (*ReleaseFn)(void*);
                ReleaseFn fn = *reinterpret_cast<ReleaseFn*>(
                    static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(piVar2)) + 8);
                fn(reinterpret_cast<void*>(piVar2));
              }
              piVar2 = *reinterpret_cast<int**>(
                  reinterpret_cast<uint8_t*>(pvVar6) + 0x0c);
              if (piVar2 != nullptr) {
                typedef void (*ReleaseFn2)(void*);
                ReleaseFn2 fn = *reinterpret_cast<ReleaseFn2*>(
                    static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(piVar2)) + 8);
                fn(reinterpret_cast<void*>(piVar2));
              }
              operator_delete(pvVar6);
            }
          }
          if (uVar3 < static_cast<uint32_t>(in_ECX[0x15])) {
            int* piVar2 = reinterpret_cast<int*>(static_cast<uintptr_t>(
                in_ECX[0x13] + uVar3 * 4));
            pvVar6 = reinterpret_cast<void*>(static_cast<uintptr_t>(
                static_cast<uint32_t>(*piVar2)));
            *piVar2 = 0;
            if (pvVar6 != nullptr) {
              in_ECX[0x16] = in_ECX[0x16] + -1;
            }
            if (uVar3 == in_ECX[0x15] - 1) {
              in_ECX[0x15] = in_ECX[0x15] - 1;
            }
          } else {
            pvVar6 = nullptr;
          }
          *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(pvVar6) + 8) = 0;
          *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(pvVar6) + 8) = 0;
          operator_delete(pvVar6);
          uVar3 = uVar3 + 1;
        } while (uVar3 < static_cast<uint32_t>(in_ECX[0xe]));
      }
      if (in_ECX == DAT_00728ec4) {
        DAT_00728ec4 = nullptr;
      }
      in_ECX[0x12] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(PTR_FUN_006c8c28));
      operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(in_ECX[0x13])));
      in_ECX[0xc] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(PTR_FUN_006c8d00));
      operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(in_ECX[0xd])));
      in_ECX[8] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(PTR_FUN_006c8d20));
      FUN_005e1490(self);
      in_ECX[8] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(PTR_FUN_006c8ce4));
      FUN_005e1490(self);
      operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(in_ECX[10])));
      in_ECX[4] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(PTR_FUN_006c8d04));
      FUN_005e1490(self);
      in_ECX[4] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(PTR_FUN_006c8cc8));
      FUN_005e1490(self);
      operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(in_ECX[6])));
      FUN_005dd9a0(self);
      return;
    }
    iVar1 = piVar4[1];
    pvVar6 = reinterpret_cast<void*>(static_cast<uintptr_t>(
        static_cast<uint32_t>(piVar4[2])));
    piVar4 = reinterpret_cast<int*>(static_cast<uintptr_t>(
        static_cast<uint32_t>(*piVar4)));
    if (piVar4 == nullptr) {
      int (*hashFn)(int) = *reinterpret_cast<int (**)(int)>(
          static_cast<uintptr_t>(in_ECX[8]) + 4);
      int iVar5 = hashFn(iVar1);
      uVar3 = static_cast<uint32_t>(iVar5) + 1;
      if (uVar3 < static_cast<uint32_t>(in_ECX[9])) {
        uint32_t* puVar7 = reinterpret_cast<uint32_t*>(
            static_cast<uintptr_t>(in_ECX[10])) + uVar3;
        do {
          piVar4 = reinterpret_cast<int*>(static_cast<uintptr_t>(*puVar7));
          if (piVar4 != nullptr) goto LAB_005d9d56;
          uVar3 = uVar3 + 1;
          puVar7 = puVar7 + 1;
        } while (uVar3 < static_cast<uint32_t>(in_ECX[9]));
      }
      piVar4 = nullptr;
    }
LAB_005d9d56:
    FUN_005bfa50(iVar1);
    *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(pvVar6) + 8) = 0;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(pvVar6) + 8) = 0;
    operator_delete(pvVar6);
  } while (true);
}

// 0x5d9eb0 — observed shape
// int(undefined4 param_1). Lazy singleton factory: when DAT_00728ec4 is null a
// 100-byte (0x64) buffer is allocated and FUN_005d9b80 constructs the object in it
// (the allocation result is otherwise unused, and 0x64 is exactly the constructor's
// field extent); the result is published and word +8 is set from param_1.
uint32_t* FUN_005d9eb0(uint32_t param_1)
{
  if (DAT_00728ec4 == nullptr) {
    intptr_t mem = reinterpret_cast<intptr_t>(FUN_00533c78(100));
    if (mem != 0) {
      FUN_005d9b80(reinterpret_cast<void*>(mem));
      DAT_00728ec4 = reinterpret_cast<uint32_t*>(mem);
      *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(DAT_00728ec4) + 8) = param_1;
      return DAT_00728ec4;
    }
    // listing: uRam00000008 = param_1  (store through absolute address 8)
    *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(0x8)) = param_1;
    DAT_00728ec4 = nullptr;
  }
  return DAT_00728ec4;
}

// 0x5d9f00 — observed shape
// void(int* param_1, undefined4 param_2, int param_3, uint param_4); in_ECX receiver.
// param_2 is unused by the listing. Marks the +0x32 flags word (0x8000 | low 12 bits),
// lazily creates the 0x48-byte record at param_1+0xe (or at param_3+0x28), classifies
// it as descriptor 4 / 5 by walking the param_1 virtual list for &DAT_00727cc8 and
// testing FUN_004879c0(&DAT_007278d4, param_1), or derives it from param_3+0x22, then
// packs the header (bit 0x800000 from param_1[9], byte 0x30 & 0x3f, self+8) and
// registers the record.
void FUN_005d9f00(void* self, uint32_t* param_1, uint32_t param_2, int param_3,
                  uint32_t param_4)
{
  uint32_t* selfWords = reinterpret_cast<uint32_t*>(self);
  uint8_t* param_1b = reinterpret_cast<uint8_t*>(param_1);
  uint32_t* puVar3;
  char cVar1;

  (void)param_2;

  *reinterpret_cast<uint16_t*>(param_1b + 0x32) =
      *reinterpret_cast<uint16_t*>(param_1b + 0x32) & 0xfff | 0x8000;
  if (param_3 == 0) {
    if (param_1[0xe] != 0) {
      return;
    }
    intptr_t iVar2 = reinterpret_cast<intptr_t>(FUN_00533c78(0x48));
    if (iVar2 == 0) {
      puVar3 = nullptr;
    } else {
      puVar3 = FUN_005d8c10(reinterpret_cast<void*>(iVar2));
    }
    {
      uint32_t* puVar4 = (*(uint32_t* (**)(void))(static_cast<uintptr_t>(*param_1) + 4))();
      while (puVar4 != nullptr) {
        if (puVar4 == reinterpret_cast<uint32_t*>(&DAT_00727cc8)) {
          puVar3[0xd] = 4;
          goto LAB_005d9fb8;
        }
        puVar4 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(
            static_cast<uint32_t>(puVar4[1])));
      }
    }
    cVar1 = FUN_004879c0(&DAT_007278d4, param_1);
    if (cVar1 != '\0') {
      puVar3[0xd] = 5;
    }
LAB_005d9fb8:
    param_1[0xe] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar3));
  } else {
    if (*reinterpret_cast<int32_t*>(static_cast<uintptr_t>(param_3) + 0x28) != 0) {
      return;
    }
    intptr_t iVar2 = reinterpret_cast<intptr_t>(FUN_00533c78(0x48));
    if (iVar2 == 0) {
      puVar3 = nullptr;
    } else {
      puVar3 = FUN_005d8c10(reinterpret_cast<void*>(iVar2));
    }
    puVar3[0xd] = static_cast<uint32_t>(
        *reinterpret_cast<int16_t*>(static_cast<uintptr_t>(param_3) + 0x22) != 0) + 4;
    *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(param_3) + 0x28) = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar3));
  }
  if (param_1[9] == 0) {
    param_4 = param_4 & 0xff7fffff;
  } else {
    param_4 = param_4 | 0x800000;
  }
  uint32_t uVar5 = (param_4 & 0xffffff) |
                   (static_cast<uint32_t>(param_1b[0x30]) & 0x3f) << 0x18 |
                   selfWords[2];
  *puVar3 = uVar5;
  FUN_005dd9f0(puVar3, uVar5);
  *reinterpret_cast<uint16_t*>(param_1b + 0x32) =
      *reinterpret_cast<uint16_t*>(param_1b + 0x32) | 0xfff;
  return;
}

// 0x5da010 — observed shape
// int(int param_1, uint param_2); in_ECX receiver. Stream-record lookup/creation.
// Computes the record size (param_1+0x10 * element count at param_1+0x18[param_2]),
// then either takes the single-stream path (count < 2: cached block from
// FUN_005d9b00 when FUN_005bd960 misses or yields null, store built by FUN_005dda40,
// lookup again for an existing block and fill/refresh it, then param_1+0x2c = used
// bytes / element count) or the ring path over self+0x34/0x4c slots advanced through
// self+0x60, wrapping at self+0x38 and deferring to FUN_006b34a0 when under-sized.
int FUN_005da010(void* self, int param_1, uint32_t param_2)
{
  uint8_t* selfBytes = reinterpret_cast<uint8_t*>(self);
  uint32_t* selfWords = reinterpret_cast<uint32_t*>(self);

  int iVar4 = param_1;
  uint32_t local_4 = *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(param_1) + 8);
  uint32_t uVar6 = *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(param_1) + 0x14);
  int local_14 = 0;
  uint32_t local_c;

  if (param_2 < uVar6) {
    local_c = *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(
        *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(param_1) + 0x18)) + param_2 * 4);
  } else {
    local_c = 0;
  }
  int iVar5 = *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(param_1) + 0x10) *
              static_cast<int>(local_c);
  param_2 = 0;
  uint32_t local_10 = 0;

  if (uVar6 < 2) {
    int local_8 = 0;
    if (local_4 == 0) {
      uVar6 = local_c | 0x80000000;
    } else {
      uVar6 = local_4;
    }
    char cVar1 = FUN_005bd960(uVar6, &local_8);
    if ((cVar1 == '\0') || (local_8 == 0)) {
      uint32_t* uVar2 = FUN_005d9b00(0x800, reinterpret_cast<int32_t*>(
          static_cast<uintptr_t>(selfWords[3])), local_4, 0);
      FUN_00545310(uVar6, uVar2);
    }
    local_8 = static_cast<int>(FUN_005dda40(iVar5, &param_2, &local_10, 0));
    FUN_005bd960(uVar6, &local_14);
    if (local_14 == 0) {
      iVar4 = FUN_005d9360(0, static_cast<uint32_t>(local_8), param_2, iVar5, 0);
      FUN_00545310(uVar6, reinterpret_cast<void*>(static_cast<uintptr_t>(
          static_cast<uint32_t>(iVar4))));
      local_14 = iVar4;
    } else {
      *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(local_14) + 8) = local_8;
      *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(local_14) + 0x0c) = param_2;
      *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(local_14) + 0x14) = iVar5;
    }
    *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(local_14) + 0x10) = local_10;
    *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(param_1) + 0x2c) = param_2 / local_c;
    return local_14;
  }

  if (*reinterpret_cast<uint32_t*>(selfBytes + 0x38) < uVar6) {
    FUN_006b34a0(uVar6);
    FUN_006b34a0(uVar6);
  }
  if (*reinterpret_cast<uint32_t*>(selfBytes + 0x38) <=
      *reinterpret_cast<uint32_t*>(selfBytes + 0x60)) {
    *reinterpret_cast<uint32_t*>(selfBytes + 0x60) = 0;
  }
  if (*reinterpret_cast<int32_t*>(static_cast<uintptr_t>(
          *reinterpret_cast<int32_t*>(selfBytes + 0x34)) +
          *reinterpret_cast<int32_t*>(selfBytes + 0x60) * 4) == 0) {
    uint32_t* slot = reinterpret_cast<uint32_t*>(FUN_005d9b00(
        0x800, reinterpret_cast<int32_t*>(static_cast<uintptr_t>(selfWords[3])), 0, 0));
    FUN_005606f0(*reinterpret_cast<uint32_t*>(selfBytes + 0x60), &slot);
  }
  uint32_t uVar2 = FUN_005dda40(iVar5, &param_2, &local_10, 1);
  int iVar3 = *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(
      *reinterpret_cast<int32_t*>(selfBytes + 0x4c)) +
      *reinterpret_cast<int32_t*>(selfBytes + 0x60) * 4);
  if (iVar3 == 0) {
    iVar3 = FUN_005d9360(0, uVar2, param_2, iVar5, 0);
    local_14 = iVar3;
    FUN_005606f0(*reinterpret_cast<uint32_t*>(selfBytes + 0x60), &local_14);
  } else {
    *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(iVar3) + 8) = uVar2;
    *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(iVar3) + 0x0c) = param_2;
    *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(iVar3) + 0x14) = iVar5;
  }
  *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(iVar3) + 0x10) = local_10;
  *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(iVar4) + 0x2c) = 0;
  *reinterpret_cast<int32_t*>(selfBytes + 0x60) =
      *reinterpret_cast<int32_t*>(selfBytes + 0x60) + 1;
  return iVar3;
}

// 0x5da210 — observed shape
// void(byte param_1); in_ECX receiver. Scalar deleting destructor: run
// FUN_005d9c50 on self, then operator_delete(self) when bit 0 of the flags is set.
void FUN_005da210(void* self, uint8_t param_1)
{
  FUN_005d9c50(self);
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
  return;
}

// 0x5da230 — observed shape
// void(void); in_ECX receiver. Pulls the global settings record and mirrors its
// flags into self+0x118 (bit 0x1000) and self+0x11c (0x17 for 0x400000, else 0x16
// for 0x200000).
void FUN_005da230(void* self)
{
  uint8_t* selfBytes = reinterpret_cast<uint8_t*>(self);
  intptr_t iVar1 = static_cast<intptr_t>(FUN_005c54e0());

  *reinterpret_cast<uint8_t*>(selfBytes + 0x118) =
      static_cast<uint8_t>(*reinterpret_cast<uint32_t*>(iVar1 + 0x90) >> 0xc) & 1;
  if ((*reinterpret_cast<uint32_t*>(iVar1 + 0x90) & 0x400000) != 0) {
    *reinterpret_cast<uint32_t*>(selfBytes + 0x11c) = 0x17;
    return;
  }
  if ((*reinterpret_cast<uint32_t*>(iVar1 + 0x90) & 0x200000) != 0) {
    *reinterpret_cast<uint32_t*>(selfBytes + 0x11c) = 0x16;
  }
  return;
}

// 0x5da280 — observed shape
// undefined4(int param_1); in_ECX receiver. Null-guarded attach: forwards to
// FUN_005c99e0, marks self+0x1c = 1 and reports success.
uint32_t FUN_005da280(void* self, int param_1)
{
  if (param_1 == 0) {
    return 0;
  }
  FUN_005c99e0(param_1);
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0x1c) = 1;
  return 1;
}

// 0x5da2b0 — observed shape
// undefined4(undefined4,undefined4,int param_3,undefined4,undefined4,undefined4,
// undefined4); in_ECX receiver. Selects/attaches the param_3 surface: with no
// param_3 it only clears the vtable+0x30 slot and calls FUN_005c11d0(param_6,1) when
// self+0x34 is empty; otherwise (again only while self+0x34 is empty) calls
// FUN_005c2c50, sets the vtable+0x30 slot from the surface's +0x24 word and forwards
// to FUN_005c1290. Always returns 0.
uint32_t FUN_005da2b0(void* self, uint32_t param_1, uint32_t param_2, int param_3,
                      uint32_t param_4, uint32_t param_5, uint32_t param_6,
                      uint32_t param_7)
{
  uint8_t* selfBytes = reinterpret_cast<uint8_t*>(self);
  (void)param_1;
  (void)param_4;
  (void)param_5;

  if (param_3 == 0) {
    if (*reinterpret_cast<int32_t*>(selfBytes + 0x34) == 0) {
      int* p = *reinterpret_cast<int**>(selfBytes + 0x18);
      uint32_t vtbl = static_cast<uint32_t>(*p);
      typedef void (*SetFn)(int);
      SetFn fn = *reinterpret_cast<SetFn*>(static_cast<uintptr_t>(vtbl) + 0x30);
      fn(0);
      FUN_005c11d0(param_6, 1);
    }
    return 0;
  }
  if (*reinterpret_cast<int32_t*>(selfBytes + 0x34) == 0) {
    FUN_005c2c50(param_2, param_7, 0, 4, 0);
  }
  {
    int* p = *reinterpret_cast<int**>(selfBytes + 0x18);
    uint32_t vtbl = static_cast<uint32_t>(*p);
    typedef void (*SetFn)(int);
    SetFn fn = *reinterpret_cast<SetFn*>(static_cast<uintptr_t>(vtbl) + 0x30);
    fn(*reinterpret_cast<uint16_t*>(static_cast<uintptr_t>(param_3) + 0x24));
  }
  FUN_005c1290(param_2, param_3, param_7);
  return 0;
}

// 0x5da330 — observed shape
// undefined4(void); in_ECX receiver. Flushes the attached surface at self+0x28 when
// present; always returns 0.
uint32_t FUN_005da330(void* self)
{
  if (*reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(self) + 0x28) != 0) {
    FUN_005c9fb0();
  }
  return 0;
}

// 0x5da360 — observed shape
// void(void). Two base/graphics teardown calls; no receiver use in the listing.
void FUN_005da360(void)
{
  FUN_005bf1c0();
  FUN_005cb730();
  return;
}

// 0x5da440 — observed shape
// undefined4(void); in_ECX receiver, two further stack arguments (listing
// in_stack_00000010 / in_stack_00000014, surfaced as explicit parameters). Bails with
// -1 when self+0x1c is clear; otherwise pushes the first argument through the
// self+0x18 object's vtable+4, forwards the second plus arg+0x28/arg+0x2c to
// FUN_005cfe70 when self+0x21 and the receiver's +0x5dc flag are set, flushes the
// self+0x28 surface and returns 0.
int32_t FUN_005da440(void* self, int in_stack_00000010, uint32_t in_stack_00000014)
{
  uint8_t* selfBytes = reinterpret_cast<uint8_t*>(self);

  if (*reinterpret_cast<char*>(selfBytes + 0x1c) == '\0') {
    return 0xffffffff;
  }
  if (*reinterpret_cast<char*>(selfBytes + 0x20) != '\0') {
    int* p = *reinterpret_cast<int**>(selfBytes + 0x18);
    uint32_t vtbl = static_cast<uint32_t>(*p);
    typedef void (*Fn)(int);
    Fn fn = *reinterpret_cast<Fn*>(static_cast<uintptr_t>(vtbl) + 4);
    fn(in_stack_00000010);
  }
  if ((*reinterpret_cast<char*>(selfBytes + 0x21) != '\0') &&
      (*reinterpret_cast<int32_t*>(static_cast<uintptr_t>(
           *reinterpret_cast<int32_t*>(selfBytes + 0x14)) + 0x5dc) != 0)) {
    FUN_005cfe70(in_stack_00000014,
                 *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(in_stack_00000010) + 0x28),
                 *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(in_stack_00000010) + 0x2c));
  }
  if (*reinterpret_cast<int32_t*>(selfBytes + 0x28) != 0) {
    FUN_005c9f50();
  }
  return 0;
}

// 0x5da5a0 — observed shape
// int(int param_1,int param_2,int param_3,int param_4); in_ECX receiver.
// Surface/stream builder. While self+0x34 is empty and param_1 is supplied it takes
// the descriptor at param_4+0x18, probes the object at descriptor+0x20 (vtable+4 must
// report 8) and picks the interface word at +4; then it builds the stream either from
// param_1+0xbc's +0x38 (param_2 == 0, FUN_005c1730) or from param_2+0x28
// (FUN_005c1a50). Finally, when a stream exists, it walks its element arrays
// (element count at +0x14, keys at +0x18, payloads at +0x1c) issuing the container
// vtable+400 per element and vtable+0x1a0 for the stream at +0x28, and returns the
// stream pointer.
int FUN_005da5a0(void* self, int param_1, int param_2, int param_3, int param_4)
{
  uint8_t* selfBytes = reinterpret_cast<uint8_t*>(self);
  uint32_t uVar4 = 0;
  int iVar3;

  if ((param_1 != 0) && (*reinterpret_cast<int32_t*>(selfBytes + 0x34) == 0)) {
    iVar3 = *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(param_4) + 0x18);
    uVar4 = 0;
    if (iVar3 != 0) {
      int* piProbe = *reinterpret_cast<int**>(static_cast<uintptr_t>(iVar3) + 0x20);
      if (piProbe != nullptr) {
        uint32_t probeVt = static_cast<uint32_t>(*piProbe);
        typedef int (*ProbeFn)(void*);
        ProbeFn fn = *reinterpret_cast<ProbeFn*>(static_cast<uintptr_t>(probeVt) + 4);
        int iVar1 = fn(reinterpret_cast<void*>(piProbe));
        if ((iVar1 == 8) &&
            (*reinterpret_cast<int32_t*>(static_cast<uintptr_t>(iVar3) + 0x20) != 0)) {
          uVar4 = *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(
              *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(iVar3) + 0x20)) + 4);
        }
      }
    }
    iVar3 = *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(param_1) + 0xbc);
    if (param_2 == 0) {
      param_3 = *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(iVar3) + 0x38);
      FUN_005c1730(reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(param_3)), iVar3,
                   *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(param_1) + 0xc0),
                   *reinterpret_cast<uint32_t*>(selfBytes + 0x24), uVar4, 0);
    } else {
      param_3 = *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(param_2) + 0x28);
      FUN_005c1a50(reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(param_3)), iVar3,
                   *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(param_1) + 0xc0),
                   static_cast<uint32_t>(param_2),
                   *reinterpret_cast<uint32_t*>(selfBytes + 0x24), uVar4, 0);
    }
  }
  if (param_3 != 0) {
    uint32_t uVar2 = *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(param_3) + 0x14);
    uint32_t uVar5 = 0;
    if (uVar2 != 0) {
      if (uVar2 == 0) {
        uVar4 = 0;
        goto LAB_005da63e;
      }
      do {
        uVar4 = *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(
            *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(param_3) + 0x18)) +
            uVar5 * 4);
LAB_005da63e:
        if (uVar5 < uVar2) {
          iVar3 = *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(
              *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(param_3) + 0x1c)) +
              uVar5 * 4);
        } else {
          iVar3 = 0;
        }
        {
          int* container = *reinterpret_cast<int**>(selfBytes + 0x10);
          uint32_t vtbl = static_cast<uint32_t>(*container);
          typedef void (*EmitFn)(void*, uint32_t, uint32_t, int, uint32_t);
          EmitFn fn = *reinterpret_cast<EmitFn*>(static_cast<uintptr_t>(vtbl) + 400);
          fn(reinterpret_cast<void*>(container), uVar5,
             *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(iVar3) + 8), 0, uVar4);
        }
        uVar2 = *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(param_3) + 0x14);
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar2);
    }
    {
      int* container = *reinterpret_cast<int**>(selfBytes + 0x10);
      uint32_t vtbl = static_cast<uint32_t>(*container);
      typedef void (*FlushFn)(void*, uint32_t);
      FlushFn fn = *reinterpret_cast<FlushFn*>(static_cast<uintptr_t>(vtbl) + 0x1a0);
      fn(reinterpret_cast<void*>(container),
         *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(param_3) + 0x28));
    }
  }
  return param_3;
}

// 0x5da790 — observed shape
// void(void); in_ECX receiver. Destructor. Stamps vtable 0x6c8720, releases the name
// string at self+0x8 through the string-table object when it is non-empty (compare
// against "" then FUN_005bd940's vtable+0x1c with FUN_005dbd70 or -1), releases the
// self+0x14 object through vtable+300, clears the byte at +0x1c, drops the
// self+0x28 buffer, zeroes self+0x34/0x38, drains the self+0x4c table through
// FUN_005d3090, runs FUN_005d3120, resets vtable 0x6c86b8, walks the pointer array at
// self+0x44 freeing each element's refcount at +0x68 (FUN_005bf480 at zero) and
// operator_delete__ on the array, then releases the refcounted slots at 0x3c, 0x2c,
// 0x24 and finally calls the base destructor FUN_005c99a0.
void FUN_005da790(void* self)
{
  uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
  uint8_t* selfBytes = reinterpret_cast<uint8_t*>(self);

  *in_ECX = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(PTR_FUN_006c8720));
  if (reinterpret_cast<char*>(static_cast<uintptr_t>(in_ECX[2])) != nullptr) {
    int iVar4 = 1;
    bool bVar10 = true;
    char* pcVar6 = reinterpret_cast<char*>(static_cast<uintptr_t>(in_ECX[2]));
    char* pcVar9 = const_cast<char*>("");
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar10 = *pcVar6 == *pcVar9;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    } while (bVar10);
    if (!bVar10) {
      int* piVar2 = reinterpret_cast<int*>(FUN_005bd940());
      uint32_t uVar3 = FUN_005dbd70();
      if (*reinterpret_cast<char*>(selfBytes + 0x1d) != '\0') {
        uVar3 = 0xffffffff;
      }
      typedef void (*ReleaseFn)(uint32_t, uint32_t);
      ReleaseFn fn = *reinterpret_cast<ReleaseFn*>(
          static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(piVar2)) + 0x1c);
      fn(in_ECX[2], uVar3);
    }
  }
  if (reinterpret_cast<int*>(static_cast<uintptr_t>(in_ECX[5])) != nullptr) {
    int* p = reinterpret_cast<int*>(static_cast<uintptr_t>(in_ECX[5]));
    typedef void (*FlushFn)(void);
    FlushFn fn = *reinterpret_cast<FlushFn*>(
        static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(p)) + 300);
    fn();
  }
  *reinterpret_cast<uint8_t*>(selfBytes + 0x1c) = 0;
  FUN_005ca660(in_ECX[10]);
  uint32_t uVar7 = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  if (in_ECX[0x13] != 0) {
    void* puStack_4 = nullptr;
    do {
      FUN_005d3090(uVar7, &puStack_4);
      uVar7 = uVar7 + 1;
    } while (uVar7 < static_cast<uint32_t>(in_ECX[0x13]));
  }
  FUN_005d3120();
  in_ECX[0x10] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(PTR_FUN_006c86b8));
  {
    intptr_t iVar4 = static_cast<intptr_t>(in_ECX[0x11]);
    if (iVar4 != 0) {
      int iVar5 = *reinterpret_cast<int32_t*>(iVar4 + -4);
      intptr_t iVar8 = iVar4 + static_cast<intptr_t>(iVar5) * 4;
      if (-1 < iVar5 - 1) {
        do {
          int* piVar2 = reinterpret_cast<int*>(iVar8 - 4);
          iVar8 = iVar8 - 4;
          if (*piVar2 != 0) {
            int32_t* ref = reinterpret_cast<int32_t*>(
                static_cast<uintptr_t>(static_cast<uint32_t>(*piVar2)) + 0x68);
            *ref = *ref + -1;
            if (*ref == 0) {
              FUN_005bf480();
            }
          }
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      operator_delete__(reinterpret_cast<void*>(iVar4 - 4));
    }
  }
  if (in_ECX[0xf] != 0) {
    int32_t* ref = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(in_ECX[0xf]) + 0x68);
    *ref = *ref + -1;
    if (*ref == 0) {
      FUN_005bf480();
    }
  }
  {
    uint32_t* puVar1 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(in_ECX[0xc]));
    if (puVar1 != nullptr) {
      int32_t* ref = reinterpret_cast<int32_t*>(
          reinterpret_cast<uint8_t*>(puVar1) + 4);
      *ref = *ref + -1;
      if (*ref == 0) {
        typedef void (*DtorFn)(int);
        DtorFn fn = *reinterpret_cast<DtorFn*>(static_cast<uintptr_t>(*puVar1));
        fn(1);
      }
    }
  }
  {
    uint32_t* puVar1 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(in_ECX[0xb]));
    if (puVar1 != nullptr) {
      int32_t* ref = reinterpret_cast<int32_t*>(
          reinterpret_cast<uint8_t*>(puVar1) + 4);
      *ref = *ref + -1;
      if (*ref == 0) {
        typedef void (*DtorFn)(int);
        DtorFn fn = *reinterpret_cast<DtorFn*>(static_cast<uintptr_t>(*puVar1));
        fn(1);
      }
    }
  }
  {
    uint32_t* puVar1 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(in_ECX[9]));
    if (puVar1 != nullptr) {
      int32_t* ref = reinterpret_cast<int32_t*>(
          reinterpret_cast<uint8_t*>(puVar1) + 4);
      *ref = *ref + -1;
      if (*ref == 0) {
        typedef void (*DtorFn)(int);
        DtorFn fn = *reinterpret_cast<DtorFn*>(static_cast<uintptr_t>(*puVar1));
        fn(1);
      }
    }
  }
  FUN_005c99a0(self);
  return;
}

// 0x5da960 — observed shape
// void(void); in_ECX receiver. Dispatches vtable slot 0x68 for every index 0..0xff.
void FUN_005da960(void* self)
{
  uint32_t* in_ECX = reinterpret_cast<uint32_t*>(self);
  uint32_t uVar1 = 0;

  do {
    typedef void (*SlotFn)(uint32_t);
    SlotFn fn = *reinterpret_cast<SlotFn*>(
        static_cast<uintptr_t>(static_cast<uint32_t>(*in_ECX)) + 0x68);
    fn(uVar1);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  return;
}
