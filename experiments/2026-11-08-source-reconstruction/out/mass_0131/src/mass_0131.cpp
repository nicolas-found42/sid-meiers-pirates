// mass_0131 — Sid Meier's Pirates! (2004), PE32 i386.
// Reconstructions from Ghidra 12.2 pseudocode corpus (0x540de0..0x541ff0).
// Mesh/geometry container family: refcounted child objects, versioned
// serialisation through vtable stream slots, and array comparison helpers.

#include <cstdint>
#include <cstddef>
#include <windows.h>

// Referenced helpers (declared from their corpus definitions where available).
extern void* thunk_FUN_00533c78(std::size_t n);
extern void operator_delete(void* p);
extern void operator_delete__(void* p);
extern void FUN_004127b0(void* param_1, int param_2, int param_3, void* param_4);
extern uint32_t FUN_00428470(float* param_1);
extern uint32_t FUN_004aaef0(void);
extern uint32_t FUN_004c2c00(float* param_1);
extern uint32_t FUN_0050b0f0(float* param_1);
extern int FUN_005dbd70();
extern void FUN_00513ce0(uint32_t param_1);
extern void FUN_0051ac30(uint32_t* param_1);
extern void FUN_005383d0(void* self);
extern void FUN_00538400(void* self);
extern void FUN_00538430(int param_1);
extern uint32_t FUN_00538460(int* param_1);
extern void FUN_00538630(int param_1);
extern void FUN_005386f0(int param_1);
extern void FUN_00540620(uint32_t param_1);
extern uint32_t FUN_00540860(int* param_1);
extern void FUN_00540c20(uint32_t* param_1);
extern int FUN_00541360(uint16_t param_1, uint16_t param_2, uint32_t param_3);
extern void FUN_00548120(int param_1, float* param_2);
extern uint32_t FUN_005480d0(float* param_1);
extern int FUN_00552860(int* list);
extern void FUN_0054bcd0(void);
extern void FUN_00551130();
extern void FUN_0055a250(void);
extern void FUN_005606f0(uint32_t index, void* value);
extern char* FUN_00557b10(char* param_1);
extern char* FUN_00557d80(char* param_1, char* param_2);
extern void FUN_0059ab10(int param_1);
extern void FUN_0059ab40(int param_1);
extern void FUN_00535150(int param_1);
extern void FUN_005351e0(int param_1);
extern void FUN_00551a80(int param_1);
extern void FUN_006b34a0(int param_1);

// Referenced data.
extern void* PTR_FUN_006c1208;
extern char DAT_007275d8;
extern int DAT_007179d8;
extern uint32_t DAT_0071778c;
extern uint32_t DAT_00717790;
extern uint32_t DAT_00717794;
extern uint32_t DAT_00717798;
extern uint8_t DAT_00727cfc;
extern void LAB_005cea70;
extern void LAB_004b1250;

// 0x540de0 — observed shape: rebind child +0x38 (refcounted) and receiver +0x10,
// transferring references in both directions.
void FUN_540de0(void* self, uint32_t* param_1)
{
  char* selfBytes = static_cast<char*>(self);
  if (param_1 == nullptr) return;

  uint32_t* puVar2 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(param_1[0xe]));
  uint32_t* puVar3 = *reinterpret_cast<uint32_t**>(selfBytes + 0x10);
  if (puVar2 != puVar3) {
    if (puVar2 != nullptr) {
      int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
      *piVar1 = *piVar1 - 1;
      if (*piVar1 == 0) {
        (*reinterpret_cast<void (**)(uint32_t)>(static_cast<uintptr_t>(*puVar2)))(1);
      }
    }
    param_1[0xe] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar3));
    if (puVar3 != nullptr) {
      puVar3[1] = puVar3[1] + 1;
    }
  }

  puVar2 = *reinterpret_cast<uint32_t**>(selfBytes + 0x10);
  if (puVar2 != param_1) {
    if (puVar2 != nullptr) {
      int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
      *piVar1 = *piVar1 - 1;
      if (*piVar1 == 0) {
        (*reinterpret_cast<void (**)(uint32_t)>(static_cast<uintptr_t>(*puVar2)))(1);
      }
    }
    *reinterpret_cast<uint32_t**>(selfBytes + 0x10) = param_1;
    param_1[1] = param_1[1] + 1;
  }
}

// 0x540e40 — observed shape: detach param_1 from the +0x10 list and release the
// held reference; head case notifies via 0x51ac30, deeper case via 0x540c20.
void FUN_540e40(void* self, uint32_t* param_1)
{
  char* selfBytes = static_cast<char*>(self);
  int* piVar1;
  if (param_1 == nullptr) return;

  uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(selfBytes + 0x10);
  if (puVar2 == nullptr) return;

  if (puVar2 == param_1) {
    param_1[1] = param_1[1] + 1;
    FUN_0051ac30(reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(param_1[0xe])));
    puVar2 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(param_1[0xe]));
    if (puVar2 != nullptr) {
      piVar1 = reinterpret_cast<int*>(puVar2 + 1);
      *piVar1 = *piVar1 - 1;
      if (*piVar1 == 0) {
        (*reinterpret_cast<void (**)(uint32_t)>(static_cast<uintptr_t>(*puVar2)))(1);
      }
      param_1[0xe] = 0;
    }
    piVar1 = reinterpret_cast<int*>(param_1 + 1);
    *piVar1 = *piVar1 - 1;
    if (*piVar1 == 0) {
      (*reinterpret_cast<void (**)(uint32_t)>(static_cast<uintptr_t>(*param_1)))(1);
    }
    return;
  }

  puVar2 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(puVar2[0xe]));
  if (puVar2 == nullptr) return;
  while (puVar2 != param_1) {
    puVar2 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(puVar2[0xe]));
    if (puVar2 == nullptr) return;
  }
  if (puVar2 != nullptr) {
    param_1[1] = param_1[1] + 1;
    FUN_00540c20(reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(param_1[0xe])));
    puVar2 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(param_1[0xe]));
    if (puVar2 != nullptr) {
      piVar1 = reinterpret_cast<int*>(puVar2 + 1);
      *piVar1 = *piVar1 - 1;
      if (*piVar1 == 0) {
        (*reinterpret_cast<void (**)(uint32_t)>(static_cast<uintptr_t>(*puVar2)))(1);
      }
      param_1[0xe] = 0;
    }
    piVar1 = reinterpret_cast<int*>(param_1 + 1);
    *piVar1 = *piVar1 - 1;
    if (*piVar1 == 0) {
      (*reinterpret_cast<void (**)(uint32_t)>(static_cast<uintptr_t>(*param_1)))(1);
    }
  }
}

// 0x540ef0 — observed shape: notify all children for stream/version param_1,
// drain the +0x14 list when the version predates 0x500000b, then drop matching
// entries (vtable slot +4 returns &DAT_00727cfc).
void FUN_540ef0(void* self, int param_1)
{
  char* selfBytes = static_cast<char*>(self);
  FUN_00513ce0(static_cast<uint32_t>(param_1));

  if (*reinterpret_cast<uint32_t*>(param_1 + 0x1c) < 0x500000b) {
    int iVar4 = *reinterpret_cast<int*>(selfBytes + 0x14);
    if (iVar4 != 0) {
      *reinterpret_cast<uint32_t*>(selfBytes + 0x14) = 0;
      do {
        int iVar2 = FUN_005dbd70();
        FUN_0054bcd0();
        FUN_00540860(reinterpret_cast<int*>(static_cast<intptr_t>(iVar4)));
        iVar4 = iVar2;
      } while (iVar2 != 0);
    }
  }

  uint32_t uVar5 = 0;
  if (*reinterpret_cast<int*>(selfBytes + 0x18) != 0) {
    do {
      int* piVar1 = *reinterpret_cast<int**>(static_cast<intptr_t>(
          *reinterpret_cast<int*>(selfBytes + 0x14)) + uVar5 * 4);
      if (piVar1 != nullptr) {
        uint32_t vt = static_cast<uint32_t>(*piVar1);
        void* puVar3 = (*reinterpret_cast<void* (**)(int*)>(
            static_cast<uintptr_t>(vt) + 4))(piVar1);
        if (puVar3 == static_cast<void*>(&DAT_00727cfc)) {
          if (uVar5 < *reinterpret_cast<uint32_t*>(selfBytes + 0x18)) {
            FUN_00540620(uVar5);
          }
          uVar5 = 0xffffffff;
        }
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *reinterpret_cast<uint32_t*>(selfBytes + 0x18));
  }
}

// 0x540f80 — observed shape: deep equality of two mesh containers: name string,
// element count, per-element vtable slot +0x1c, then child chain walk.
uint32_t FUN_540f80(void* self, int param_1)
{
  char* selfBytes = static_cast<char*>(self);
  if (FUN_00538460(reinterpret_cast<int*>(static_cast<intptr_t>(param_1))) == 0) {
    return 0;
  }

  uint8_t* pbVar4 = *reinterpret_cast<uint8_t**>(selfBytes + 0xc);
  if (pbVar4 == nullptr) {
    if (*reinterpret_cast<int*>(param_1 + 0xc) != 0) return 0;
  } else {
    if (*reinterpret_cast<int*>(param_1 + 0xc) == 0) return 0;
  }

  if (pbVar4 != nullptr) {
    uint8_t* pbVar8 = *reinterpret_cast<uint8_t**>(param_1 + 0xc);
    int iVar5 = 0;
    for (;;) {
      uint8_t bVar1 = *pbVar4;
      bool bVar10 = bVar1 < *pbVar8;
      if (bVar1 != *pbVar8) {
        iVar5 = (1 - static_cast<int>(bVar10)) - static_cast<int>(bVar10 != 0);
        break;
      }
      if (bVar1 == 0) { iVar5 = 0; break; }
      bVar1 = pbVar4[1];
      bVar10 = bVar1 < pbVar8[1];
      if (bVar1 != pbVar8[1]) {
        iVar5 = (1 - static_cast<int>(bVar10)) - static_cast<int>(bVar10 != 0);
        break;
      }
      pbVar4 = pbVar4 + 2;
      pbVar8 = pbVar8 + 2;
      if (bVar1 == 0) { iVar5 = 0; break; }
    }
    if (iVar5 != 0) return 0;
  }

  if (*reinterpret_cast<int*>(selfBytes + 0x18) != *reinterpret_cast<int*>(param_1 + 0x18)) {
    return 0;
  }

  uint32_t uVar9 = 0;
  if (*reinterpret_cast<int*>(selfBytes + 0x18) != 0) {
    do {
      int* piVarA = *reinterpret_cast<int**>(static_cast<intptr_t>(
          *reinterpret_cast<int*>(selfBytes + 0x14)) + uVar9 * 4);
      int* other = *reinterpret_cast<int**>(static_cast<intptr_t>(
          *reinterpret_cast<int*>(param_1 + 0x14)) + uVar9 * 4);
      uint32_t vt = static_cast<uint32_t>(*piVarA);
      uint32_t cVar3 = (*reinterpret_cast<uint32_t (**)(int*)>(
          static_cast<uintptr_t>(vt) + 0x1c))(other);
      if (cVar3 == 0) return 0;
      uVar9 = uVar9 + 1;
    } while (uVar9 < *reinterpret_cast<uint32_t*>(selfBytes + 0x18));
  }

  int* piVar2 = *reinterpret_cast<int**>(selfBytes + 0x10);
  int iVar5b = *reinterpret_cast<int*>(param_1 + 0x10);
  int iVar6 = (piVar2 == nullptr) ? 0 : FUN_00552860(piVar2);
  int iVar7 = (iVar5b == 0) ? 0 : FUN_00552860(reinterpret_cast<int*>(static_cast<intptr_t>(iVar5b)));
  if (iVar6 == iVar7) {
    for (;;) {
      if (piVar2 == nullptr || iVar5b == 0) return 1;
      uint32_t vt = static_cast<uint32_t>(*piVar2);
      uint32_t cVar3 = (*reinterpret_cast<uint32_t (**)(int*)>(
          static_cast<uintptr_t>(vt) + 0x1c))(reinterpret_cast<int*>(static_cast<intptr_t>(iVar5b)));
      if (cVar3 == 0) break;
      piVar2 = reinterpret_cast<int*>(static_cast<intptr_t>(piVar2[0xe]));
      iVar5b = *reinterpret_cast<int*>(iVar5b + 0x38);
    }
  }
  return 0;
}

// 0x541080 — observed shape: base notify, write global name, then "m_pcName",
// then vtable slot +0x20 on each element and each +0x10 chain child.
void FUN_541080(void* self, int param_1)
{
  char* selfBytes = static_cast<char*>(self);
  int iVar2 = param_1;
  FUN_005386f0(param_1);

  void* local = FUN_00557b10(&DAT_007275d8);
  uint32_t uVar3 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
  if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar3) {
    FUN_006b34a0(*reinterpret_cast<int*>(iVar2 + 0x14) + static_cast<int>(uVar3));
  }
  FUN_005606f0(uVar3, &local);

  local = FUN_00557d80(const_cast<char*>("m_pcName"), *reinterpret_cast<char**>(selfBytes + 0xc));
  uVar3 = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
  if (*reinterpret_cast<uint32_t*>(iVar2 + 8) <= uVar3) {
    FUN_006b34a0(*reinterpret_cast<int*>(iVar2 + 0x14) + static_cast<int>(uVar3));
  }
  FUN_005606f0(uVar3, &local);

  uVar3 = 0;
  if (*reinterpret_cast<int*>(selfBytes + 0x18) != 0) {
    do {
      int* obj = *reinterpret_cast<int**>(static_cast<intptr_t>(
          *reinterpret_cast<int*>(selfBytes + 0x14)) + uVar3 * 4);
      uint32_t vt = static_cast<uint32_t>(*obj);
      (*reinterpret_cast<void (**)(int*, int)>(
          static_cast<uintptr_t>(vt) + 0x20))(obj, iVar2);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *reinterpret_cast<uint32_t*>(selfBytes + 0x18));
  }

  for (int* piVar1 = *reinterpret_cast<int**>(selfBytes + 0x10); piVar1 != nullptr;
       piVar1 = reinterpret_cast<int*>(static_cast<intptr_t>(piVar1[0xe]))) {
    uint32_t vt = static_cast<uint32_t>(*piVar1);
    (*reinterpret_cast<void (**)(int*, int)>(
        static_cast<uintptr_t>(vt) + 0x20))(piVar1, iVar2);
  }
}

// 0x541140 — observed shape: full constructor; copies geometry pointers, sets
// vtable, count, flag word and allocates the mesh from (count, data).
void FUN_541140(void* self, int16_t param_1, int param_2, uint32_t param_3,
                uint32_t param_4, uint32_t param_5, uint8_t param_6, uint16_t param_7)
{
  uint32_t* in_ECX = static_cast<uint32_t*>(self);
  FUN_005383d0(self);

  in_ECX[9] = param_3;
  in_ECX[10] = param_4;
  in_ECX[0xb] = param_5;
  *in_ECX = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c1208));
  *reinterpret_cast<int16_t*>(in_ECX + 3) = param_1;
  in_ECX[8] = static_cast<uint32_t>(param_2);
  *reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(in_ECX) + 0x32) = 0;
  *reinterpret_cast<uint8_t*>(in_ECX + 0xd) = 0;
  *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(in_ECX) + 0x35) = 0;
  *reinterpret_cast<uint16_t*>(in_ECX + 0xc) =
      static_cast<uint16_t>((param_6 & 0x3f) | param_7);
  if (param_1 != 0 && param_2 != 0) {
    FUN_00548120(param_1, reinterpret_cast<float*>(static_cast<intptr_t>(param_2)));
  }
  in_ECX[0xe] = 0;
  *reinterpret_cast<int16_t*>(reinterpret_cast<char*>(in_ECX) + 0xe) =
      static_cast<int16_t>(DAT_007179d8);
  DAT_007179d8 = DAT_007179d8 + 1;
  *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(in_ECX) + 0x33) =
      *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(in_ECX) + 0x33) & 0xf;
}

// 0x5411f0 — observed shape: default constructor; zero all fields, set vtable,
// stamp the running id from DAT_007179d8 and clear the +0x33 high nibble.
void FUN_5411f0(void* self)
{
  uint32_t* in_ECX = static_cast<uint32_t*>(self);
  FUN_005383d0(self);

  *reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(in_ECX) + 0x32) = 0;
  *reinterpret_cast<uint16_t*>(in_ECX + 3) = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  *reinterpret_cast<uint16_t*>(in_ECX + 0xc) = 0;
  *reinterpret_cast<uint8_t*>(in_ECX + 0xd) = 0;
  *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(in_ECX) + 0x35) = 0;
  in_ECX[0xe] = 0;
  *in_ECX = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c1208));
  *reinterpret_cast<int16_t*>(reinterpret_cast<char*>(in_ECX) + 0xe) =
      static_cast<int16_t>(DAT_007179d8);
  DAT_007179d8 = DAT_007179d8 + 1;
  *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(in_ECX) + 0x33) =
      *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(in_ECX) + 0x33) & 0xf;
}

// 0x541240 — observed shape: lazily allocate the element array at +0x24 with
// stride 0xc (x3 for the high-nibble flag) and optionally clear it.
void FUN_541240(void* self, char param_1)
{
  char* selfBytes = static_cast<char*>(self);
  int iVar3 = 1;
  if ((*reinterpret_cast<uint8_t*>(selfBytes + 0x31) & 0xf0) != 0) {
    iVar3 = 3;
  }
  if (*reinterpret_cast<int*>(selfBytes + 0x24) == 0) {
    int iVar4 = static_cast<int>(*reinterpret_cast<uint16_t*>(selfBytes + 0xc)) * iVar3;
    int iVar1 = static_cast<int>(reinterpret_cast<uintptr_t>(thunk_FUN_00533c78(
        static_cast<std::size_t>(iVar4) * 0xc)));
    if (iVar1 == 0) {
      iVar1 = 0;
    } else {
      FUN_004127b0(reinterpret_cast<void*>(static_cast<intptr_t>(iVar1)), 0xc, iVar4, &LAB_005cea70);
    }
    *reinterpret_cast<int*>(selfBytes + 0x24) = iVar1;
  }
  if (param_1 != 0) {
    uint32_t* puVar5 = reinterpret_cast<uint32_t*>(static_cast<intptr_t>(
        *reinterpret_cast<int*>(selfBytes + 0x24)));
    for (uint32_t uVar2 =
             (static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(selfBytes + 0xc)) *
              static_cast<uint32_t>(iVar3) * 0xc) >> 2;
         uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    // Dead byte-tail left by the decompiler: the loop bound above is already
    // count*stride*0xc/4, so this never iterates.
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *reinterpret_cast<uint8_t*>(puVar5) = 0;
      puVar5 = reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(puVar5) + 1);
    }
  }
}

// 0x5412c0 — observed shape: bounds-checked accessor into the +0x2c array,
// stride 8 per element, limit field +0x30 low 6 bits.
int FUN_5412c0(void* self, uint16_t param_1)
{
  char* selfBytes = static_cast<char*>(self);
  if (*reinterpret_cast<int*>(selfBytes + 0x2c) == 0 ||
      (*reinterpret_cast<uint8_t*>(selfBytes + 0x30) & 0x3f) <= param_1) {
    return 0;
  }
  return *reinterpret_cast<int*>(selfBytes + 0x2c) +
         static_cast<int>(static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(selfBytes + 0xc)) *
                          param_1 * 8);
}

// 0x541300 — observed shape: geometry setter; stores count + three pointers and
// rebuilds the flag word (+0x30) from param_6/param_7.
void FUN_541300(void* self, int16_t param_1, uint32_t param_2, uint32_t param_3,
                uint32_t param_4, uint32_t param_5, uint8_t param_6, uint16_t param_7)
{
  char* selfBytes = static_cast<char*>(self);
  *reinterpret_cast<int16_t*>(selfBytes + 0xc) = param_1;
  *reinterpret_cast<uint32_t*>(selfBytes + 0x20) = param_2;
  *reinterpret_cast<uint32_t*>(selfBytes + 0x24) = param_3;
  if (param_1 != 0) {
    FUN_00548120(param_1, reinterpret_cast<float*>(static_cast<uintptr_t>(param_2)));
  }
  *reinterpret_cast<uint32_t*>(selfBytes + 0x28) = param_4;
  *reinterpret_cast<uint32_t*>(selfBytes + 0x2c) = param_5;
  *reinterpret_cast<uint16_t*>(selfBytes + 0x30) =
      static_cast<uint16_t>((*reinterpret_cast<uint16_t*>(selfBytes + 0x30) & 0xfc0) |
                            (param_6 & 0x3f) | param_7);
}

// 0x541360 — observed shape: lexicographic comparison of two elements over the
// enabled views selected by param_3 bits 0..3 (position/normal/colour/uv).
int FUN_541360(void* self, uint16_t param_1, uint16_t param_2, uint32_t param_3)
{
  char* selfBytes = static_cast<char*>(self);
  uint16_t uVar1 = param_1;

  if ((param_3 & 1) != 0) {
    float* pfVar3 = reinterpret_cast<float*>(static_cast<uintptr_t>(
        *reinterpret_cast<int*>(selfBytes + 0x20)) +
        static_cast<uint32_t>(param_2) * 0xc);
    uint32_t uVar7 = 0;
    int iVar5 = (*reinterpret_cast<int*>(selfBytes + 0x20) +
                  static_cast<uint32_t>(param_1) * 0xc) -
                 static_cast<int>(reinterpret_cast<uintptr_t>(pfVar3));
    do {
      float* other = reinterpret_cast<float*>(reinterpret_cast<char*>(pfVar3) + iVar5);
      if (*other < *pfVar3) return -1;
      if (*pfVar3 < *other) return 1;
      uVar7 = uVar7 + 1;
      pfVar3 = pfVar3 + 1;
    } while (uVar7 < 3);
  }

  int iVar5 = *reinterpret_cast<int*>(selfBytes + 0x24);
  if (iVar5 != 0 && (param_3 & 2) != 0) {
    float* pfVar3 = reinterpret_cast<float*>(static_cast<uintptr_t>(iVar5) +
                                             static_cast<uint32_t>(param_2) * 0xc);
    uint32_t uVar7 = 0;
    iVar5 = (iVar5 + static_cast<uint32_t>(param_1) * 0xc) -
            static_cast<int>(reinterpret_cast<uintptr_t>(pfVar3));
    do {
      float* other = reinterpret_cast<float*>(reinterpret_cast<char*>(pfVar3) + iVar5);
      if (*other < *pfVar3) return -1;
      if (*pfVar3 < *other) return 1;
      uVar7 = uVar7 + 1;
      pfVar3 = pfVar3 + 1;
    } while (uVar7 < 3);
  }

  iVar5 = *reinterpret_cast<int*>(selfBytes + 0x28);
  if (iVar5 != 0 && (param_3 & 4) != 0) {
    float* pfVar3 = reinterpret_cast<float*>(static_cast<uintptr_t>(iVar5) +
                                             static_cast<uint32_t>(param_2) * 0x10);
    uint32_t uVar7 = 0;
    iVar5 = (static_cast<uint32_t>(param_1) * 0x10 + iVar5) -
            static_cast<int>(reinterpret_cast<uintptr_t>(pfVar3));
    do {
      float* other = reinterpret_cast<float*>(reinterpret_cast<char*>(pfVar3) + iVar5);
      if (*other < *pfVar3) return -1;
      if (*pfVar3 < *other) return 1;
      uVar7 = uVar7 + 1;
      pfVar3 = pfVar3 + 1;
    } while (uVar7 < 4);
  }

  iVar5 = *reinterpret_cast<int*>(selfBytes + 0x2c);
  uint32_t uVar7 = 0;
  if (iVar5 != 0 && (param_3 & 8) != 0) {
    uint32_t stride = static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(selfBytes + 0xc));
    uint16_t uVar2 = 0;
    if ((*reinterpret_cast<uint8_t*>(selfBytes + 0x30) & 0x3f) != 0) {
      do {
        float* pfVar3 = reinterpret_cast<float*>(static_cast<uintptr_t>(iVar5) +
                                                 ((uVar7 & 0xffff) + param_2) * 8);
        uint32_t uVar6 = 0;
        int iVar4 = (iVar5 + ((uVar7 & 0xffff) + uVar1) * 8) -
                    static_cast<int>(reinterpret_cast<uintptr_t>(pfVar3));
        do {
          float* other = reinterpret_cast<float*>(reinterpret_cast<char*>(pfVar3) + iVar4);
          if (*other < *pfVar3) return -1;
          if (*pfVar3 < *other) return 1;
          uVar6 = uVar6 + 1;
          pfVar3 = pfVar3 + 1;
        } while (uVar6 < 2);
        uVar7 = uVar7 + stride;
        uVar2 = uVar2 + 1;
      } while (uVar2 < (*reinterpret_cast<uint8_t*>(selfBytes + 0x30) & 0x3f));
    }
  }
  return 0;
}

// 0x541510 — observed shape: total serialised size = base size from 0x4aaef0
// plus the present geometry arrays.
int FUN_541510(void* self)
{
  char* selfBytes = static_cast<char*>(self);
  int iVar2;
  if (*reinterpret_cast<int*>(selfBytes + 0x20) == 0) {
    iVar2 = 0;
  } else {
    iVar2 = static_cast<int>(static_cast<uint32_t>(
        *reinterpret_cast<uint16_t*>(selfBytes + 0xc)) * 0xc);
  }
  if (*reinterpret_cast<int*>(selfBytes + 0x24) != 0) {
    iVar2 = iVar2 + ((-static_cast<int>(
                          (*reinterpret_cast<uint16_t*>(selfBytes + 0x30) & 0xf000) != 0) & 2) + 1) *
                        static_cast<int>(static_cast<uint32_t>(
                            *reinterpret_cast<uint16_t*>(selfBytes + 0xc)) * 0xc);
  }
  if (*reinterpret_cast<int*>(selfBytes + 0x28) != 0) {
    iVar2 = iVar2 + static_cast<int>(static_cast<uint32_t>(
        *reinterpret_cast<uint16_t*>(selfBytes + 0xc)) * 0x10);
  }
  if (*reinterpret_cast<int*>(selfBytes + 0x2c) != 0) {
    iVar2 = iVar2 + static_cast<int>((*reinterpret_cast<uint8_t*>(selfBytes + 0x30) & 0x3f) *
                                     static_cast<uint32_t>(
                                         *reinterpret_cast<uint16_t*>(selfBytes + 0xc)) * 8);
  }
  int iVar1 = static_cast<int>(FUN_004aaef0());
  return iVar1 + iVar2;
}

// 0x541580 — observed shape: destructor; releases the four geometry buffers via
// the shared owner at +8 (refcount at +0xc), else deletes them directly.
void FUN_541580(void* self)
{
  uint32_t* in_ECX = static_cast<uint32_t*>(self);
  *in_ECX = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006c1208));
  FUN_00551130();

  void* pvVar2 = reinterpret_cast<void*>(static_cast<uintptr_t>(in_ECX[2]));
  if (pvVar2 == nullptr) {
    operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(in_ECX[8])));
    operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(in_ECX[9])));
    operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(in_ECX[10])));
    operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(in_ECX[0xb])));
  } else {
    if (in_ECX[8] != 0) {
      int* piVar1 = reinterpret_cast<int*>(reinterpret_cast<char*>(pvVar2) + 0xc);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        FUN_0055a250();
        operator_delete(pvVar2);
      }
    }
    if (in_ECX[9] != 0) {
      pvVar2 = reinterpret_cast<void*>(static_cast<uintptr_t>(in_ECX[2]));
      int* piVar1 = reinterpret_cast<int*>(reinterpret_cast<char*>(pvVar2) + 0xc);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        FUN_0055a250();
        operator_delete(pvVar2);
      }
    }
    if (in_ECX[10] != 0) {
      pvVar2 = reinterpret_cast<void*>(static_cast<uintptr_t>(in_ECX[2]));
      int* piVar1 = reinterpret_cast<int*>(reinterpret_cast<char*>(pvVar2) + 0xc);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        FUN_0055a250();
        operator_delete(pvVar2);
      }
    }
    if (in_ECX[0xb] != 0) {
      pvVar2 = reinterpret_cast<void*>(static_cast<uintptr_t>(in_ECX[2]));
      int* piVar1 = reinterpret_cast<int*>(reinterpret_cast<char*>(pvVar2) + 0xc);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        FUN_0055a250();
        operator_delete(pvVar2);
        FUN_00538400(self);
        return;
      }
    }
  }
  FUN_00538400(self);
}

// 0x541650 — observed shape: lazily allocate the +0x28 colour array, 0x10 bytes
// per element, defaulted from DAT_0071778c..98.
void FUN_541650(void* self, char param_1)
{
  char* selfBytes = static_cast<char*>(self);
  if (*reinterpret_cast<int*>(selfBytes + 0x28) == 0) {
    uint16_t uVar1 = *reinterpret_cast<uint16_t*>(selfBytes + 0xc);
    int iVar2 = static_cast<int>(reinterpret_cast<uintptr_t>(thunk_FUN_00533c78(
        static_cast<std::size_t>(uVar1) << 4)));
    if (iVar2 == 0) {
      iVar2 = 0;
    } else {
      FUN_004127b0(reinterpret_cast<void*>(static_cast<intptr_t>(iVar2)), 0x10, uVar1,
                   &LAB_004b1250);
    }
    *reinterpret_cast<int*>(selfBytes + 0x28) = iVar2;
  }
  if (param_1 != 0) {
    uint16_t uVar1 = 0;
    if (*reinterpret_cast<int16_t*>(selfBytes + 0xc) != 0) {
      do {
        uint32_t* puVar3 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(
            static_cast<uint32_t>(uVar1) * 0x10 +
            *reinterpret_cast<int*>(selfBytes + 0x28)));
        puVar3[0] = DAT_0071778c;
        puVar3[1] = DAT_00717790;
        puVar3[2] = DAT_00717794;
        uVar1 = uVar1 + 1;
        puVar3[3] = DAT_00717798;
      } while (uVar1 < *reinterpret_cast<uint16_t*>(selfBytes + 0xc));
    }
  }
}

// 0x5416e0 — observed shape: geometry replacement; releases/reallocates the old
// owner-held buffers, stores the new pointers, then biases the flag word.
void FUN_5416e0(void* self, uint16_t param_1, void* param_2, void* param_3,
                void* param_4, void* param_5, uint8_t param_6, uint16_t param_7)
{
  char* selfBytes = static_cast<char*>(self);
  void* pvVar2 = *reinterpret_cast<void**>(selfBytes + 8);
  if (pvVar2 == nullptr) {
    if (param_2 != *reinterpret_cast<void**>(selfBytes + 0x20)) {
      operator_delete__(*reinterpret_cast<void**>(selfBytes + 0x20));
    }
    if (param_3 != *reinterpret_cast<void**>(selfBytes + 0x24)) {
      operator_delete__(*reinterpret_cast<void**>(selfBytes + 0x24));
    }
    if (param_4 != *reinterpret_cast<void**>(selfBytes + 0x28)) {
      operator_delete__(*reinterpret_cast<void**>(selfBytes + 0x28));
    }
    if (param_5 != *reinterpret_cast<void**>(selfBytes + 0x2c)) {
      operator_delete__(*reinterpret_cast<void**>(selfBytes + 0x2c));
    }
  } else {
    if (param_2 != *reinterpret_cast<void**>(selfBytes + 0x20)) {
      int* piVar1 = reinterpret_cast<int*>(reinterpret_cast<char*>(pvVar2) + 0xc);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        FUN_0055a250();
        operator_delete(pvVar2);
      }
    }
    if (param_3 != *reinterpret_cast<void**>(selfBytes + 0x24)) {
      pvVar2 = *reinterpret_cast<void**>(selfBytes + 8);
      int* piVar1 = reinterpret_cast<int*>(reinterpret_cast<char*>(pvVar2) + 0xc);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        FUN_0055a250();
        operator_delete(pvVar2);
      }
    }
    if (param_4 != *reinterpret_cast<void**>(selfBytes + 0x28)) {
      pvVar2 = *reinterpret_cast<void**>(selfBytes + 8);
      int* piVar1 = reinterpret_cast<int*>(reinterpret_cast<char*>(pvVar2) + 0xc);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        FUN_0055a250();
        operator_delete(pvVar2);
      }
    }
    if (param_5 != *reinterpret_cast<void**>(selfBytes + 0x2c)) {
      pvVar2 = *reinterpret_cast<void**>(selfBytes + 8);
      int* piVar1 = reinterpret_cast<int*>(reinterpret_cast<char*>(pvVar2) + 0xc);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        FUN_0055a250();
        operator_delete(pvVar2);
      }
    }
  }
  *reinterpret_cast<uint16_t*>(selfBytes + 0xc) = param_1;
  *reinterpret_cast<void**>(selfBytes + 0x20) = param_2;
  *reinterpret_cast<void**>(selfBytes + 0x24) = param_3;
  if (param_2 != nullptr) {
    FUN_00548120(param_1, reinterpret_cast<float*>(param_2));
  }
  *reinterpret_cast<void**>(selfBytes + 0x2c) = param_5;
  *reinterpret_cast<void**>(selfBytes + 0x28) = param_4;
  *reinterpret_cast<uint16_t*>(selfBytes + 0x30) =
      static_cast<uint16_t>((*reinterpret_cast<uint16_t*>(selfBytes + 0x30) & 0xfc0) |
                            (param_6 & 0x3f) | param_7);
}

// 0x541810 — observed shape: median-of-three selection over uint16 indices using
// FUN_00541360 as the ordering predicate. The predicate's mesh receiver arrives in
// ECX from the sort caller and is not materialised by this listing.
uint16_t FUN_541810(int param_1, uint32_t param_2, int param_3, int param_4)
{
  uint16_t uVar1 = *reinterpret_cast<uint16_t*>(param_1 + param_3 * 2);
  uint16_t uVar2 = *reinterpret_cast<uint16_t*>(param_1 + ((param_4 + param_3) >> 1) * 2);
  int iVar4 = FUN_00541360(uVar1, uVar2, param_2);
  if (iVar4 < 0) {
    uint16_t uVar3 = *reinterpret_cast<uint16_t*>(param_1 + param_4 * 2);
    iVar4 = FUN_00541360(uVar2, uVar3, param_2);
    if (-1 < iVar4) {
      iVar4 = FUN_00541360(uVar1, uVar3, param_2);
      if (iVar4 < 0) {
        return uVar3;
      }
      return uVar1;
    }
  } else {
    uint16_t uVar3 = *reinterpret_cast<uint16_t*>(param_1 + param_4 * 2);
    iVar4 = FUN_00541360(uVar1, uVar3, param_2);
    if (iVar4 < 0) {
      return uVar1;
    }
    iVar4 = FUN_00541360(uVar2, uVar3, param_2);
    if (iVar4 < 0) {
      return uVar3;
    }
  }
  return uVar2;
}

// 0x5418d0 — observed shape: versioned mesh reader through the stream object at
// +0x15c, vtable slot 2. Decompiler staged the (buffer,size) arguments in stack
// slots; they are restored here as explicit call arguments.
void FUN_5418d0(void* self, int param_1)
{
  char* selfBytes = static_cast<char*>(self);
  void** vt = *reinterpret_cast<void***>(
      static_cast<intptr_t>(*reinterpret_cast<int*>(param_1 + 0x15c)));
  auto io = reinterpret_cast<void (*)(void*, uint32_t)>(vt[2]);

  FUN_00538630(param_1);

  uint16_t* puVar1 = reinterpret_cast<uint16_t*>(selfBytes + 0xc);
  io(puVar1, 2);

  if (0xa00010f < *reinterpret_cast<uint32_t*>(param_1 + 0x1c)) {
    io(selfBytes + 0x34, 1);
    io(selfBytes + 0x35, 1);
  }

  bool hasVertices;
  if (*reinterpret_cast<uint32_t*>(param_1 + 0x1c) < 0x4010000) {
    io(selfBytes + 0x20, 4);
    hasVertices = *reinterpret_cast<int*>(selfBytes + 0x20) != 0;
  } else {
    // One-byte presence flag; reuses the +0x20 slot as a stack temp.
    uint8_t flagByte = 0;
    io(&flagByte, 1);
    hasVertices = flagByte != 0;
  }
  if (hasVertices) {
    int iVar3 = *reinterpret_cast<int*>(selfBytes + 8);
    if (iVar3 == 0) {
      uint16_t uVar2 = *puVar1;
      iVar3 = static_cast<int>(reinterpret_cast<uintptr_t>(
          thunk_FUN_00533c78(static_cast<std::size_t>(uVar2) * 0xc)));
      if (iVar3 == 0) {
        iVar3 = 0;
      } else {
        FUN_004127b0(reinterpret_cast<void*>(static_cast<intptr_t>(iVar3)), 0xc, uVar2,
                     &LAB_005cea70);
      }
      *reinterpret_cast<int*>(selfBytes + 0x20) = iVar3;
    } else {
      int iVar5 = *reinterpret_cast<int*>(iVar3 + 8);
      *reinterpret_cast<uint32_t*>(iVar3 + 8) = iVar5 + static_cast<uint32_t>(*puVar1) * 0xc;
      *reinterpret_cast<int*>(iVar3 + 0xc) = *reinterpret_cast<int*>(iVar3 + 0xc) + 1;
      *reinterpret_cast<int*>(selfBytes + 0x20) = iVar5;
    }
    io(*reinterpret_cast<void**>(selfBytes + 0x20),
       static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(selfBytes + 0xc)) * 0xc);
  }

  uint32_t uVar6 = static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(selfBytes + 0xc));
  if (0xa000001 < *reinterpret_cast<uint32_t*>(param_1 + 0x1c)) {
    io(selfBytes + 0x30, 2);
    if ((*reinterpret_cast<uint8_t*>(selfBytes + 0x31) & 0xf0) != 0) {
      uVar6 = uVar6 * 3;
    }
  }

  bool hasNormals;
  if (*reinterpret_cast<uint32_t*>(param_1 + 0x1c) < 0x4010000) {
    io(selfBytes + 0x24, 4);
    hasNormals = *reinterpret_cast<int*>(selfBytes + 0x24) != 0;
  } else {
    uint8_t flagByte = 0;
    io(&flagByte, 1);
    hasNormals = flagByte != 0;
  }
  if (hasNormals) {
    int iVar3 = *reinterpret_cast<int*>(selfBytes + 8);
    int iVar5 = static_cast<int>(uVar6 * 0xc);
    if (iVar3 == 0) {
      int alloc = static_cast<int>(reinterpret_cast<uintptr_t>(
          thunk_FUN_00533c78(static_cast<std::size_t>(iVar5))));
      if (alloc == 0) {
        iVar3 = 0;
      } else {
        FUN_004127b0(reinterpret_cast<void*>(static_cast<intptr_t>(alloc)), 0xc, uVar6,
                     &LAB_005cea70);
        iVar3 = alloc;
      }
      *reinterpret_cast<int*>(selfBytes + 0x24) = iVar3;
    } else {
      int iVar4 = *reinterpret_cast<int*>(iVar3 + 8);
      *reinterpret_cast<int*>(iVar3 + 8) = iVar5 + iVar4;
      *reinterpret_cast<int*>(iVar3 + 0xc) = *reinterpret_cast<int*>(iVar3 + 0xc) + 1;
      *reinterpret_cast<int*>(selfBytes + 0x24) = iVar4;
    }
    io(*reinterpret_cast<void**>(selfBytes + 0x24), static_cast<uint32_t>(iVar5));
  }

  FUN_0059ab10(param_1);

  bool hasColors;
  if (*reinterpret_cast<uint32_t*>(param_1 + 0x1c) < 0x4010000) {
    io(selfBytes + 0x28, 4);
    hasColors = *reinterpret_cast<int*>(selfBytes + 0x28) != 0;
  } else {
    uint8_t flagByte = 0;
    io(&flagByte, 1);
    hasColors = flagByte != 0;
  }
  if (hasColors) {
    int iVar3 = *reinterpret_cast<int*>(selfBytes + 8);
    if (iVar3 == 0) {
      uint16_t uVar2 = *reinterpret_cast<uint16_t*>(selfBytes + 0xc);
      iVar3 = static_cast<int>(reinterpret_cast<uintptr_t>(
          thunk_FUN_00533c78(static_cast<std::size_t>(uVar2) << 4)));
      if (iVar3 == 0) {
        iVar3 = 0;
      } else {
        FUN_004127b0(reinterpret_cast<void*>(static_cast<intptr_t>(iVar3)), 0x10, uVar2,
                     &LAB_004b1250);
      }
      *reinterpret_cast<int*>(selfBytes + 0x28) = iVar3;
    } else {
      int iVar5 = *reinterpret_cast<int*>(iVar3 + 8);
      *reinterpret_cast<uint32_t*>(iVar3 + 8) =
          static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(selfBytes + 0xc)) * 0x10 + iVar5;
      *reinterpret_cast<int*>(iVar3 + 0xc) = *reinterpret_cast<int*>(iVar3 + 0xc) + 1;
      *reinterpret_cast<int*>(selfBytes + 0x28) = iVar5;
    }
    io(*reinterpret_cast<void**>(selfBytes + 0x28),
       static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(selfBytes + 0xc)) << 4);
  }

  if (*reinterpret_cast<uint32_t*>(param_1 + 0x1c) < 0x500000a) {
    uint16_t flagsRead = 0;
    io(&flagsRead, 2);
    uint16_t cur = *reinterpret_cast<uint16_t*>(selfBytes + 0x30);
    *reinterpret_cast<uint16_t*>(selfBytes + 0x30) = static_cast<uint16_t>(
        cur ^ ((static_cast<uint8_t>(cur) ^ static_cast<uint8_t>(flagsRead)) & 0x3f));
  } else if (*reinterpret_cast<uint32_t*>(param_1 + 0x1c) < 0xa000002) {
    io(selfBytes + 0x30, 2);
  }

  if (*reinterpret_cast<uint32_t*>(param_1 + 0x1c) < 0x4010000) {
    io(selfBytes + 0x2c, 4);
  }

  if ((*reinterpret_cast<uint16_t*>(selfBytes + 0x30) & 0x3f) != 0) {
    int iVar4 = static_cast<int>((*reinterpret_cast<uint16_t*>(selfBytes + 0x30) & 0x3f) *
                                 static_cast<uint32_t>(
                                     *reinterpret_cast<uint16_t*>(selfBytes + 0xc)));
    int iVar5 = *reinterpret_cast<int*>(selfBytes + 8);
    int iVar3 = iVar4 * 8;
    if (iVar5 == 0) {
      int alloc = static_cast<int>(reinterpret_cast<uintptr_t>(
          thunk_FUN_00533c78(static_cast<std::size_t>(iVar3))));
      if (alloc == 0) {
        iVar5 = 0;
      } else {
        FUN_004127b0(reinterpret_cast<void*>(static_cast<intptr_t>(alloc)), 8, iVar4,
                     &LAB_005cea70);
        iVar5 = alloc;
      }
      *reinterpret_cast<int*>(selfBytes + 0x2c) = iVar5;
    } else {
      int base = *reinterpret_cast<int*>(iVar5 + 8);
      *reinterpret_cast<int*>(iVar5 + 8) = base + iVar3;
      *reinterpret_cast<int*>(iVar5 + 0xc) = *reinterpret_cast<int*>(iVar5 + 0xc) + 1;
      *reinterpret_cast<int*>(selfBytes + 0x2c) = base;
    }
    io(*reinterpret_cast<void**>(selfBytes + 0x2c), static_cast<uint32_t>(iVar3));
  }

  if (0x5000009 < *reinterpret_cast<uint32_t*>(param_1 + 0x1c)) {
    io(selfBytes + 0x32, 2);
  }
}

// 0x541c20 — observed shape: legacy (unversioned) mesh writer through the stream
// object at +0x160, vtable slot 3. The decompiler aliased every (buffer,size)
// argument pair into reused stack slots; the restored arguments are noted inline.
void FUN_541c20(void* self, uint32_t param_1)
{
  char* selfBytes = static_cast<char*>(self);
  void** vt = *reinterpret_cast<void***>(
      static_cast<intptr_t>(*reinterpret_cast<int*>(param_1 + 0x160)));
  auto io = reinterpret_cast<void (*)(void*, uint32_t)>(vt[3]);

  FUN_00538430(static_cast<int>(param_1));

  uint16_t* puVar1 = reinterpret_cast<uint16_t*>(selfBytes + 0xc);
  io(puVar1, 2);
  io(selfBytes + 0x34, 1);
  io(selfBytes + 0x35, 1);

  uint8_t hasVertices = 0;
  io(&hasVertices, 1);
  if (hasVertices != 0) {
    for (uint32_t uVar3 = 0; uVar3 < *puVar1; uVar3++) {
      FUN_00535150(static_cast<int>(param_1));
    }
  }

  // The buffer operand of this two-byte write is the flag word at +0x30; the
  // decompiler kept only the staged size.
  io(selfBytes + 0x30, 2);

  uint32_t uVar6 = 0;
  uVar6 = static_cast<uint32_t>(*puVar1);
  if ((*reinterpret_cast<uint8_t*>(selfBytes + 0x31) & 0xf0) != 0) {
    uVar6 = uVar6 * 3;
  }

  uint8_t hasNormals = (*reinterpret_cast<int*>(selfBytes + 0x24) != 0) ? 1 : 0;
  io(&hasNormals, 1);
  if (hasNormals != 0) {
    for (uint32_t i = 0; i < uVar6; i++) {
      FUN_00535150(static_cast<int>(param_1));
    }
  }

  FUN_0059ab40(static_cast<int>(param_1));

  uint8_t hasColors = (*reinterpret_cast<int*>(selfBytes + 0x28) != 0) ? 1 : 0;
  io(&hasColors, 1);
  if (hasColors != 0) {
    for (uint32_t uVar3 = 0; uVar3 < *puVar1; uVar3++) {
      FUN_005351e0(static_cast<int>(param_1));
    }
  }

  uint32_t uVar3 = (*reinterpret_cast<uint8_t*>(selfBytes + 0x30) & 0x3f) *
                   static_cast<uint32_t>(*puVar1);
  for (uint32_t uVar2 = 0; uVar2 < uVar3; uVar2++) {
    FUN_00551a80(static_cast<int>(param_1));
  }

  uint32_t flagsTail = *reinterpret_cast<uint16_t*>(selfBytes + 0x32) & 0xf000;
  io(&flagsTail, 2);
}

// 0x541de0 — observed shape: deep equality of the mesh container: count, +0x34/
// +0x35 bytes, element arrays via 0x428470/0x480d0/0x50b0f0/0x4c2c00, flag word.
uint32_t FUN_541de0(void* self, int param_1)
{
  char* selfBytes = static_cast<char*>(self);

  if (FUN_00538460(reinterpret_cast<int*>(static_cast<intptr_t>(param_1))) == 0) {
    return 0;
  }
  uint16_t uVar2 = *reinterpret_cast<uint16_t*>(selfBytes + 0xc);
  if (uVar2 != *reinterpret_cast<uint16_t*>(param_1 + 0xc)) {
    return 0;
  }

  int iVar4 = *reinterpret_cast<int*>(selfBytes + 0x20);
  if (iVar4 == 0) {
    if (*reinterpret_cast<int*>(param_1 + 0x20) != 0) return 0;
  } else {
    if (*reinterpret_cast<int*>(param_1 + 0x20) == 0) return 0;
  }

  if (*reinterpret_cast<char*>(selfBytes + 0x34) != *reinterpret_cast<char*>(param_1 + 0x34) ||
      *reinterpret_cast<char*>(selfBytes + 0x35) != *reinterpret_cast<char*>(param_1 + 0x35)) {
    return 0;
  }

  if (iVar4 != 0) {
    uint32_t uVar5 = 0;
    if (uVar2 != 0) {
      int iVar3 = *reinterpret_cast<int*>(param_1 + 0x20) - iVar4;
      do {
        if (FUN_00428470(reinterpret_cast<float*>(static_cast<intptr_t>(iVar3 + iVar4))) != 0) {
          return 0;
        }
        uVar5 = uVar5 + 1;
        iVar4 = iVar4 + 0xc;
      } while (uVar5 < uVar2);
    }
  }

  iVar4 = *reinterpret_cast<int*>(selfBytes + 0x24);
  if (iVar4 != 0) {
    if (*reinterpret_cast<int*>(param_1 + 0x24) == 0) return 0;
    // LAB_00541e97
    uVar2 = *reinterpret_cast<uint16_t*>(selfBytes + 0x30) & 0xf000;
    if (uVar2 != (*reinterpret_cast<uint16_t*>(param_1 + 0x30) & 0xf000)) {
      return 0;
    }
    uint32_t uVar5;
    if (uVar2 == 0) {
      uVar5 = static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(selfBytes + 0xc));
    } else {
      uVar5 = static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(selfBytes + 0xc)) * 3;
    }
    uint32_t uVar6 = 0;
    if (uVar5 != 0) {
      int iVar3 = *reinterpret_cast<int*>(param_1 + 0x24) - iVar4;
      do {
        if (FUN_00428470(reinterpret_cast<float*>(static_cast<intptr_t>(iVar4 + iVar3))) != 0) {
          return 0;
        }
        uVar6 = uVar6 + 1;
        iVar4 = iVar4 + 0xc;
      } while (uVar6 < uVar5);
    }
  } else {
    if (*reinterpret_cast<int*>(param_1 + 0x24) != 0) return 0;
  }

  if (FUN_005480d0(reinterpret_cast<float*>(static_cast<intptr_t>(param_1 + 0x10))) == 0) {
    return 0;
  }

  iVar4 = *reinterpret_cast<int*>(selfBytes + 0x28);
  if (iVar4 != 0 && *reinterpret_cast<int*>(param_1 + 0x28) == 0) {
    return 0;
  }
  if (*reinterpret_cast<int*>(selfBytes + 0x2c) == 0 &&
      *reinterpret_cast<int*>(param_1 + 0x2c) != 0) {
    return 0;
  }

  if (iVar4 != 0) {
    uVar2 = *reinterpret_cast<uint16_t*>(selfBytes + 0xc);
    uint32_t uVar5 = 0;
    if (uVar2 != 0) {
      int iVar3 = *reinterpret_cast<int*>(param_1 + 0x28) - iVar4;
      do {
        if (FUN_0050b0f0(reinterpret_cast<float*>(static_cast<intptr_t>(iVar3 + iVar4))) != 0) {
          return 0;
        }
        uVar5 = uVar5 + 1;
        iVar4 = iVar4 + 0x10;
      } while (uVar5 < uVar2);
    }
  }

  iVar4 = *reinterpret_cast<int*>(selfBytes + 0x2c);
  if (iVar4 == 0) {
    if (*reinterpret_cast<int*>(param_1 + 0x2c) != 0) return 0;
    return 1;
  }
  if (*reinterpret_cast<int*>(param_1 + 0x2c) == 0) return 0;

  // LAB_00541f93
  if (((*reinterpret_cast<uint8_t*>(param_1 + 0x30) ^
        static_cast<uint8_t>(*reinterpret_cast<uint16_t*>(selfBytes + 0x30))) & 0x3f) != 0) {
    return 0;
  }
  uint32_t uVar5 = (*reinterpret_cast<uint16_t*>(selfBytes + 0x30) & 0x3f) *
                   static_cast<uint32_t>(*reinterpret_cast<uint16_t*>(selfBytes + 0xc));
  uint32_t uVar6 = 0;
  if (uVar5 != 0) {
    int iVar3 = *reinterpret_cast<int*>(param_1 + 0x2c) - iVar4;
    do {
      if (FUN_004c2c00(reinterpret_cast<float*>(static_cast<intptr_t>(iVar4 + iVar3))) != 0) {
        return 0;
      }
      uVar6 = uVar6 + 1;
      iVar4 = iVar4 + 8;
    } while (uVar6 < uVar5);
  }
  return 1;
}

// 0x541ff0 — observed shape: scalar deleting destructor.
void FUN_541ff0(void* self, uint8_t param_1)
{
  FUN_541580(self);
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}
