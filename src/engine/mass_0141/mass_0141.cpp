//
// mass_0141.cpp — reconstruction batch mass_0141 (retry)
// Target: Sid Meier's Pirates! (2004), PE32 i386
// Image: 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
//
// Each definition preserves the observed field offsets, constants,
// call order, return shape, and conditional structure of the Ghidra
// 12.2 pseudocode (analysis/pseudocode/functions/*.c).
//
// Register receivers (in_ECX) are modeled as an explicit `void* self`;
// the receiver body is addressed through byte offsets exactly as the
// corpus does. Values the decompiler left in registers (unaff_*) are kept
// as explicit parameters or preserved verbatim with a comment.
//
#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <cmath>
#include <windows.h>

// ---------------------------------------------------------------------------
// Extern declarations: helpers and globals referenced by the assigned corpus
// files. No additional addresses are introduced.
// ---------------------------------------------------------------------------

// Allocator (0x533c78) and its thunk alias used by the corpus.
void* FUN_00533c78(uint32_t size);
void* thunk_FUN_00533c78(uint32_t size);

// Free functions called with explicit arguments in the corpus.
intptr_t FUN_00539210(void* a, void* b, int* table, uint32_t param_4);
void FUN_00538830(int param_1);
void FUN_005676c0(char* param_1);
void thunk_FUN_005675b0(char* param_1);
char FUN_004c2c00(float* param_1);
uint8_t FUN_005f0ddc();

// Methods on the same object (receiver passed in ECX, implicit in Ghidra).
void FUN_0054a3d0(void* self);
void FUN_0054a7e0(void* self);
void FUN_0054ab10(void* self);
void FUN_0055ac40(void* self, int param_1);
void FUN_0055ac70(void* self, int param_1);
void FUN_00551a50(void* self, int param_1);
void FUN_00551a80(void* self, int param_1);
void FUN_0055ad50(void* self);
void FUN_0055adf0(void* self);
void FUN_005edba0(void* self);
void FUN_00497420(void* self);

// Deallocation entry points.
void operator_delete(void* ptr);
void operator_delete__(void* ptr);

// vtables / labels stored into objects.
extern void* PTR_FUN_006c1fb4;
extern void* PTR_LAB_006fd148;
extern void* PTR_FUN_006c2280;
extern void* PTR_LAB_006c221c;
extern void* PTR_FUN_006c2228;

// Module-level mutable data.
extern int DAT_00727444;
extern void* DAT_00727928;
extern uint32_t* DAT_0072792c;

// Packing tables copied by 0x54e050 / compared in 0x54e6c0.
extern int32_t DAT_00727460[9];
extern int32_t DAT_00727484[9];
extern int32_t DAT_0072747c;
extern int32_t DAT_00727480;
extern int32_t DAT_007274a0;
extern int32_t DAT_007274a4;
extern uint8_t DAT_0072745c;

// Channel masks and shift counts used by 0x54d8e0 and 0x54e050.
extern uint32_t DAT_00717834;
extern uint32_t DAT_00717838;
extern uint8_t DAT_0071783c;
extern uint32_t DAT_00717840;
extern uint32_t DAT_00717844;
extern uint32_t _DAT_00717848;
extern uint32_t DAT_0071784c;
extern uint8_t DAT_00717850;
extern uint8_t DAT_00717854;
extern uint8_t DAT_00717858;
extern uint8_t DAT_0071785c;
extern uint32_t DAT_00717860;
extern uint32_t DAT_00717864;
extern uint32_t DAT_00717868;
extern uint32_t DAT_0071786c;
extern uint8_t DAT_00717870;
extern uint8_t DAT_00717874;
extern uint8_t DAT_00717878;
extern uint8_t DAT_0071787c;

namespace {

// Virtual dispatch through the object's vtable at `byte_offset`.
template <typename Fn>
inline Fn vfn(void* object, size_t byte_offset)
{
  uintptr_t vtable = *reinterpret_cast<uintptr_t*>(object);
  return reinterpret_cast<Fn>(*reinterpret_cast<uintptr_t*>(vtable + byte_offset));
}

// Virtual dispatch when the vtable pointer itself is already in hand.
template <typename Fn>
inline Fn vfn_raw(uintptr_t vtable, size_t byte_offset)
{
  return reinterpret_cast<Fn>(*reinterpret_cast<uintptr_t*>(vtable + byte_offset));
}

// (value & mask) >> (shift & 0x1f) — observed bit extraction.
inline uint32_t masked_bits(uint32_t value, uint32_t mask, uint8_t shift)
{
  return (value & mask) >> (shift & 0x1f);
}

// '\b' - extracted bit field — observed 8-minus-bits form.
inline uint8_t inv_bits(uint32_t value, uint32_t mask, uint8_t shift)
{
  return static_cast<uint8_t>(8 - static_cast<int>(masked_bits(value, mask, shift)));
}

} // namespace

// ---------------------------------------------------------------------------
// 0x54a4d0
// ---------------------------------------------------------------------------

// 0x54a4d0 — observed shape
void FUN_0054a4d0(void* self, int param_1, char unaff_DI)
{
  uint8_t* base = static_cast<uint8_t*>(self);
  // Ghidra frame slot: auStackY_a4 is used only at +0x98 (past its declared size).
  uint8_t auStackY_a4[0xa0];

  FUN_0055ac40(self, param_1);
  uint16_t* puVar1 = reinterpret_cast<uint16_t*>(base + 0x40);
  vfn<void (__cdecl*)(void*, int)>(*reinterpret_cast<void**>(param_1 + 0x15c), 8)(puVar1, 2);
  uint16_t uVar2 = *puVar1;
  if (uVar2 != 0) {
    intptr_t iVar3 = *reinterpret_cast<intptr_t*>(base + 8);
    if (iVar3 == 0) {
      *reinterpret_cast<void**>(base + 0x44) =
          thunk_FUN_00533c78(static_cast<uint32_t>(uVar2) << 1);
    }
    else {
      intptr_t iVar4 = *reinterpret_cast<intptr_t*>(iVar3 + 8);
      *reinterpret_cast<uint32_t*>(iVar3 + 8) =
          static_cast<uint32_t>(iVar4) + static_cast<uint32_t>(uVar2) * 2;
      *reinterpret_cast<int*>(iVar3 + 0xc) = *reinterpret_cast<int*>(iVar3 + 0xc) + 1;
      *reinterpret_cast<intptr_t*>(base + 0x44) = iVar4;
    }
    vfn<void (__cdecl*)(void*, int)>(*reinterpret_cast<void**>(param_1 + 0x15c), 8)(
        *reinterpret_cast<void**>(base + 0x44),
        static_cast<uint32_t>(*puVar1) << 1);

    bool haveSecond;
    if (*reinterpret_cast<uint32_t*>(param_1 + 0x1c) < 0xa000111u) {
      haveSecond = true;
    }
    else {
      vfn<void (__cdecl*)(void*, int)>(*reinterpret_cast<void**>(param_1 + 0x15c), 8)(
          auStackY_a4 + 0x98, 1);
      // unaff_DI: the flag is left in a register the decompiler could not tie
      // to the byte just read; carried as an explicit parameter.
      haveSecond = (unaff_DI != '\0');
    }
    if (haveSecond) {
      intptr_t iVar3 = *reinterpret_cast<intptr_t*>(base + 8);
      int iVar4 = static_cast<int>(
          static_cast<uint16_t>(static_cast<uint16_t>(*puVar1 * 2) +
                                *reinterpret_cast<int16_t*>(base + 0x3c))) *
          2;
      if (iVar3 == 0) {
        *reinterpret_cast<void**>(base + 0x48) =
            thunk_FUN_00533c78(static_cast<uint32_t>(iVar4));
      }
      else {
        intptr_t iVar5 = *reinterpret_cast<intptr_t*>(iVar3 + 8);
        *reinterpret_cast<intptr_t*>(iVar3 + 8) = iVar5 + iVar4;
        *reinterpret_cast<int*>(iVar3 + 0xc) = *reinterpret_cast<int*>(iVar3 + 0xc) + 1;
        *reinterpret_cast<intptr_t*>(base + 0x48) = iVar5;
      }
      vfn<void (__cdecl*)(void*, int)>(*reinterpret_cast<void**>(param_1 + 0x15c), 8)(
          *reinterpret_cast<void**>(base + 0x48), iVar4);
    }
  }
  return;
}

// ---------------------------------------------------------------------------
// 0x54a5c0
// ---------------------------------------------------------------------------

// 0x54a5c0 — observed shape
void FUN_0054a5c0(void* self, int param_1)
{
  uint8_t* base = static_cast<uint8_t*>(self);
  // Ghidra frame slot: read destination at auStackY_ac + 0xa0.
  uint8_t auStackY_ac[0xa4];

  FUN_0055ac70(self, param_1);
  uint16_t* puVar1 = reinterpret_cast<uint16_t*>(base + 0x40);
  uint16_t* puVar3 = puVar1;
  vfn<void (__cdecl*)(void*, int)>(*reinterpret_cast<void**>(param_1 + 0x160), 0xc)(puVar1, 2);
  // Observed as `(char)puVar3`: a register-held flag the decompiler typed as
  // the low byte of the receiver field address.
  char cVar2 = static_cast<char>(reinterpret_cast<uintptr_t>(puVar3) & 0xffu);
  if (*puVar1 != 0) {
    vfn<void (__cdecl*)(void*, int)>(*reinterpret_cast<void**>(param_1 + 0x160), 0xc)(
        *reinterpret_cast<void**>(base + 0x44),
        static_cast<uint32_t>(*puVar1) << 1);
    vfn<void (__cdecl*)(void*, int)>(*reinterpret_cast<void**>(param_1 + 0x160), 0xc)(
        auStackY_ac + 0xa0, 1);
    if (cVar2 != '\0') {
      uint32_t size = static_cast<uint32_t>(
          static_cast<uint16_t>(static_cast<uint16_t>(*puVar1 * 2) +
                                *reinterpret_cast<int16_t*>(base + 0x3c)))
          << 1;
      vfn<void (__cdecl*)(void*, int)>(*reinterpret_cast<void**>(param_1 + 0x160), 0xc)(
          *reinterpret_cast<void**>(base + 0x48), size);
    }
  }
  return;
}

// ---------------------------------------------------------------------------
// 0x54a650
// ---------------------------------------------------------------------------

// 0x54a650 — observed shape
void FUN_0054a650(void* self, uint8_t param_1)
{
  void* in_ECX = self;

  FUN_0054a3d0(self);
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}

// ---------------------------------------------------------------------------
// 0x54a770
// ---------------------------------------------------------------------------

// 0x54a770 — observed shape
uint32_t FUN_0054a770(void* self, float* param_1)
{
  float* in_ECX = static_cast<float*>(self);
  char cVar1;

  if (((in_ECX[2] == param_1[2]) && (*in_ECX == *param_1)) && (in_ECX[1] == param_1[1])) {
    cVar1 = FUN_004c2c00(param_1 + 3);
    if ((cVar1 == '\0') && (in_ECX[0x11] == param_1[0x11])) {
      cVar1 = FUN_004c2c00(param_1 + 5);
      if (cVar1 == '\0') {
        return 0;
      }
    }
  }
  return 1;
}

// ---------------------------------------------------------------------------
// 0x54a7e0
// ---------------------------------------------------------------------------

// 0x54a7e0 — observed shape
void FUN_0054a7e0(void* self)
{
  float* in_ECX = static_cast<float*>(self);
  float fVar1;
  float fVar2;
  float fVar3 = 0.0f;

  fVar1 = static_cast<float>(std::cos(static_cast<double>(in_ECX[2])));
  fVar2 = static_cast<float>(std::sin(static_cast<double>(in_ECX[2])));

  bool writeMatrix = true;
  if (in_ECX[0x11] == 0.0f) {
    in_ECX[0xe] = 0.0f;
    in_ECX[8] = fVar1 * in_ECX[3];
    in_ECX[0xb] = fVar2 * in_ECX[3];
    in_ECX[0xf] = 0.0f;
    in_ECX[9] = -(fVar2 * in_ECX[4]);
    in_ECX[0xc] = fVar1 * in_ECX[4];
    fVar3 = (in_ECX[1] - in_ECX[6]) * fVar1 + (*in_ECX - in_ECX[5]) * fVar2 + in_ECX[6];
    fVar1 = (*in_ECX - in_ECX[5]) * fVar1 + -((in_ECX[1] - in_ECX[6]) * fVar2);
  }
  else {
    // Ghidra printed 1.4013e-45 here: the stored word is the raw value 1.
    uint32_t kind = *reinterpret_cast<uint32_t*>(&in_ECX[0x11]);
    if (kind != 1u) {
      writeMatrix = false;
    }
    else {
      in_ECX[0xe] = 0.0f;
      in_ECX[8] = fVar1 * in_ECX[3];
      in_ECX[0xb] = -(fVar2 * in_ECX[4]);
      in_ECX[0xf] = 0.0f;
      in_ECX[9] = fVar2 * in_ECX[3];
      in_ECX[0xc] = fVar1 * in_ECX[4];
      fVar3 = (fVar1 * (in_ECX[1] - in_ECX[6]) - (-in_ECX[5] - *in_ECX) * fVar2) * in_ECX[4] +
              in_ECX[6];
      fVar1 = ((in_ECX[1] - in_ECX[6]) * fVar2 + (-in_ECX[5] - *in_ECX) * fVar1) * in_ECX[3];
    }
  }
  if (writeMatrix) {
    in_ECX[10] = fVar1 + in_ECX[5];
    in_ECX[0xd] = fVar3;
    in_ECX[0x10] = 1.0f;
  }
  // LAB_0054a8da: `*(undefined1 *)(in_ECX + 7) = 0` — byte at offset 0x1c.
  *(reinterpret_cast<uint8_t*>(in_ECX) + 0x1c) = 0;
  return;
}

// ---------------------------------------------------------------------------
// 0x54a8f0
// ---------------------------------------------------------------------------

// 0x54a8f0 — observed shape
uint32_t FUN_0054a8f0(void* self, uint32_t* param_1, uint32_t param_2, uint32_t* param_3,
                      uint32_t* param_4, uint32_t param_5)
{
  uint32_t* in_ECX = static_cast<uint32_t*>(self);

  in_ECX[0] = param_1[0];
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_2;
  in_ECX[3] = param_3[0];
  in_ECX[4] = param_3[1];
  in_ECX[5] = param_4[0];
  in_ECX[6] = param_4[1];
  in_ECX[0x11] = param_5;
  FUN_0054a7e0(self);
  // extraout_ECX: the callee leaves ECX undefined; returned verbatim as observed.
  return static_cast<uint32_t>(reinterpret_cast<uintptr_t>(self));
}

// ---------------------------------------------------------------------------
// 0x54a940
// ---------------------------------------------------------------------------

// 0x54a940 — observed shape
void FUN_0054a940(void* self, int param_1)
{
  intptr_t in_ECX = reinterpret_cast<intptr_t>(self);
  // Ghidra frame slot: read destination at auStackY_9c + 0x98.
  uint8_t auStackY_9c[0xa0];

  FUN_00551a50(self, param_1);
  FUN_00551a50(self, param_1);
  uint32_t uVar1 = 4;
  vfn<void (__cdecl*)(void*)>(*reinterpret_cast<void**>(param_1 + 0x15c), 8)(
      reinterpret_cast<void*>(in_ECX + 8));
  vfn<void (__cdecl*)(void*, int)>(*reinterpret_cast<void**>(param_1 + 0x15c), 8)(
      auStackY_9c + 0x98, 4);
  *reinterpret_cast<uint32_t*>(in_ECX + 0x44) = uVar1;
  FUN_00551a50(self, param_1);
  *reinterpret_cast<uint8_t*>(in_ECX + 0x1c) = 1;
  return;
}

// ---------------------------------------------------------------------------
// 0x54a9a0
// ---------------------------------------------------------------------------

// 0x54a9a0 — observed shape
void FUN_0054a9a0(void* self, int param_1)
{
  intptr_t in_ECX = reinterpret_cast<intptr_t>(self);

  FUN_00551a80(self, param_1);
  FUN_00551a80(self, param_1);
  vfn<void (__cdecl*)(void*, int)>(*reinterpret_cast<void**>(param_1 + 0x160), 0xc)(
      reinterpret_cast<void*>(in_ECX + 8), 4);
  vfn<void (__cdecl*)(void*, int)>(*reinterpret_cast<void**>(param_1 + 0x160), 0xc)(
      reinterpret_cast<void*>(in_ECX + 0x44), 4);
  FUN_00551a80(self, param_1);
  return;
}

// ---------------------------------------------------------------------------
// 0x54aa00
// ---------------------------------------------------------------------------

// 0x54aa00 — observed shape
void FUN_0054aa00(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3,
                  uint32_t param_4, uint32_t param_5, uint32_t param_6, uint8_t param_7)
{
  uint8_t* base = static_cast<uint8_t*>(self);

  *reinterpret_cast<uint32_t*>(base + 0x00) = param_1;
  *reinterpret_cast<uint32_t*>(base + 0x04) = param_2;
  *reinterpret_cast<uint32_t*>(base + 0x08) = param_3;
  *reinterpret_cast<uint32_t*>(base + 0x0c) = param_4;
  *reinterpret_cast<uint32_t*>(base + 0x10) = param_5;
  *reinterpret_cast<uint32_t*>(base + 0x14) = param_6;
  *reinterpret_cast<uint8_t*>(base + 0x18) = param_7;
  return;
}

// ---------------------------------------------------------------------------
// 0x54aa40
// ---------------------------------------------------------------------------

// 0x54aa40 — observed shape
char* FUN_0054aa40(void* self, char* param_1)
{
  float* in_ECX = static_cast<float*>(self);
  char cVar1;
  char* pcVar2 = param_1;

  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  // pcVar2 now points one past the terminator; allocation size is
  // strlen(param_1) + 0x50 as observed by the subtraction below.
  pcVar2 = static_cast<char*>(thunk_FUN_00533c78(static_cast<uint32_t>(
      pcVar2 + (0x50 - (reinterpret_cast<intptr_t>(param_1) + 1)))));

  sprintf(pcVar2, "%s = (N=%g,F=%g,L=%g,R=%g,T=%g,B=%g,O=%u)", param_1,
          static_cast<double>(in_ECX[4]), static_cast<double>(in_ECX[5]),
          static_cast<double>(*in_ECX), static_cast<double>(in_ECX[1]),
          static_cast<double>(in_ECX[2]), static_cast<double>(in_ECX[3]),
          static_cast<uint32_t>(*(reinterpret_cast<uint8_t*>(in_ECX) + 0x18)));
  return pcVar2;
}

// ---------------------------------------------------------------------------
// 0x54aab0
// ---------------------------------------------------------------------------

// 0x54aab0 — observed shape
uint32_t FUN_0054aab0(void* self, int param_1)
{
  intptr_t in_ECX = reinterpret_cast<intptr_t>(self);

  if ((*reinterpret_cast<int*>(in_ECX + 0x1c) == *reinterpret_cast<int*>(param_1 + 0x1c)) &&
      (*reinterpret_cast<int*>(in_ECX + 0x20) == *reinterpret_cast<int*>(param_1 + 0x20))) {
    return 1;
  }
  return 0;
}

// ---------------------------------------------------------------------------
// 0x54ab10
// ---------------------------------------------------------------------------

// 0x54ab10 — observed shape
void FUN_0054ab10(void* self)
{
  void** in_ECX = static_cast<void**>(self);

  *in_ECX = &PTR_FUN_006c1fb4;
  if (DAT_00727928 != 0) {
    operator_delete__(DAT_00727928);
  }
  DAT_00727928 = 0;
  FUN_0055ad50(self);
  *in_ECX = &PTR_LAB_006fd148;
  DAT_00727444 = DAT_00727444 + -1;
  return;
}

// ---------------------------------------------------------------------------
// 0x54acf0
// ---------------------------------------------------------------------------

// 0x54acf0 — observed shape
char* FUN_0054acf0(char* param_1)
{
  char cVar1;
  char* pcVar2;
  char* pcVar3;
  uint32_t uVar4;
  char* pcVar5;
  char local_101[257];

  if (DAT_00727928 != 0) {
    FUN_005676c0(param_1);
    pcVar2 = static_cast<char*>(DAT_00727928);
    // Byte-wise copy of the global string into local_101; the buffer is not
    // read again in this body (observed dead store).
    intptr_t offset = 0;
    do {
      cVar1 = *pcVar2;
      local_101[offset] = cVar1;
      pcVar2 = pcVar2 + 1;
      offset = offset + 1;
    } while (cVar1 != '\0');
    pcVar2 = static_cast<char*>(thunk_FUN_00533c78(0x104));
    thunk_FUN_005675b0(pcVar2);
    return pcVar2;
  }
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = pcVar2 + (1 - (reinterpret_cast<intptr_t>(param_1) + 1));
  pcVar3 = static_cast<char*>(thunk_FUN_00533c78(
      static_cast<uint32_t>(reinterpret_cast<intptr_t>(pcVar2))));
  pcVar5 = pcVar3;
  for (uVar4 = static_cast<uint32_t>(reinterpret_cast<intptr_t>(pcVar2)) >> 2; uVar4 != 0;
       uVar4 = uVar4 - 1) {
    *reinterpret_cast<uint32_t*>(pcVar5) = *reinterpret_cast<uint32_t*>(param_1);
    param_1 = param_1 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar4 = static_cast<uint32_t>(reinterpret_cast<intptr_t>(pcVar2)) & 3; uVar4 != 0;
       uVar4 = uVar4 - 1) {
    *pcVar5 = *param_1;
    param_1 = param_1 + 1;
    pcVar5 = pcVar5 + 1;
  }
  return pcVar3;
}

// ---------------------------------------------------------------------------
// 0x54ada0
// ---------------------------------------------------------------------------

// 0x54ada0 — observed shape
void FUN_0054ada0(void)
{
  uint32_t* puVar2;
  uint32_t* puVar3;

  puVar3 = static_cast<uint32_t*>(FUN_00533c78(0x1dc));
  if (puVar3 == 0) {
    puVar3 = 0;
  }
  else {
    *reinterpret_cast<void**>(puVar3) = &PTR_LAB_006fd148;
    puVar3[1] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    *reinterpret_cast<void**>(puVar3) = &PTR_FUN_006c1fb4;
    FUN_0055adf0(reinterpret_cast<void*>(puVar3));
  }
  puVar2 = DAT_0072792c;
  if (DAT_0072792c != puVar3) {
    if ((DAT_0072792c != 0) && (puVar2[1] = puVar2[1] - 1, puVar2[1] == 0)) {
      // vtable slot 0 with argument 1 (release).
      vfn<void (__cdecl*)(int)>(puVar2, 0)(1);
    }
    DAT_0072792c = puVar3;
    if (puVar3 != 0) {
      puVar3[1] = puVar3[1] + 1;
    }
  }
  return;
}

// ---------------------------------------------------------------------------
// 0x54d8c0
// ---------------------------------------------------------------------------

// 0x54d8c0 — observed shape
uint32_t FUN_0054d8c0(void* self)
{
  int* in_ECX = static_cast<int*>(self);

  if ((*in_ECX == 2) || (*in_ECX == 3)) {
    return 1;
  }
  return 0;
}

// ---------------------------------------------------------------------------
// 0x54d8e0
// ---------------------------------------------------------------------------

// 0x54d8e0 — observed shape
void FUN_0054d8e0(void* self, intptr_t param_1)
{
  uint8_t* base = static_cast<uint8_t*>(self);

  *reinterpret_cast<uint32_t*>(base + 0x00) = *reinterpret_cast<uint32_t*>(param_1 + 8);
  *reinterpret_cast<uint8_t*>(base + 0x10) =
      static_cast<uint8_t>(masked_bits(*reinterpret_cast<uint32_t*>(param_1 + 0x20),
                                       DAT_00717860, DAT_00717870));
  *reinterpret_cast<uint8_t*>(base + 0x14) =
      inv_bits(*reinterpret_cast<uint32_t*>(param_1 + 0x1c), DAT_00717840, DAT_00717850);
  *reinterpret_cast<uint32_t*>(base + 0x04) = *reinterpret_cast<uint32_t*>(param_1 + 0xc);
  *reinterpret_cast<uint8_t*>(base + 0x11) =
      static_cast<uint8_t>(masked_bits(*reinterpret_cast<uint32_t*>(param_1 + 0x20),
                                       DAT_00717864, DAT_00717874));
  *reinterpret_cast<uint8_t*>(base + 0x15) =
      inv_bits(*reinterpret_cast<uint32_t*>(param_1 + 0x1c), DAT_00717844, DAT_00717854);
  *reinterpret_cast<uint32_t*>(base + 0x08) = *reinterpret_cast<uint32_t*>(param_1 + 0x10);
  *reinterpret_cast<uint8_t*>(base + 0x12) =
      static_cast<uint8_t>(masked_bits(*reinterpret_cast<uint32_t*>(param_1 + 0x20),
                                       DAT_00717868, DAT_00717878));
  *reinterpret_cast<uint8_t*>(base + 0x16) =
      inv_bits(*reinterpret_cast<uint32_t*>(param_1 + 0x1c), _DAT_00717848, DAT_00717858);
  *reinterpret_cast<uint32_t*>(base + 0x0c) = *reinterpret_cast<uint32_t*>(param_1 + 0x14);
  *reinterpret_cast<uint8_t*>(base + 0x13) =
      static_cast<uint8_t>(masked_bits(*reinterpret_cast<uint32_t*>(param_1 + 0x20),
                                       DAT_0071786c, DAT_0071787c));
  *reinterpret_cast<uint8_t*>(base + 0x17) =
      inv_bits(*reinterpret_cast<uint32_t*>(param_1 + 0x1c), DAT_0071784c, DAT_0071785c);
  return;
}

// ---------------------------------------------------------------------------
// 0x54d9e0
// ---------------------------------------------------------------------------

// 0x54d9e0 — observed shape
void FUN_0054d9e0(void* self, uint8_t param_1)
{
  void** in_ECX = static_cast<void**>(self);

  *in_ECX = &PTR_FUN_006c2280;
  FUN_005edba0(self);
  *in_ECX = &PTR_LAB_006c221c;
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
  return;
}

// ---------------------------------------------------------------------------
// 0x54da10
// ---------------------------------------------------------------------------

// 0x54da10 — observed shape
void FUN_0054da10(void* self)
{
  uint32_t* in_ECX = static_cast<uint32_t*>(self);
  int* piVar1;
  intptr_t iVar2;
  uint32_t* puVar3;

  *reinterpret_cast<void**>(in_ECX) = &PTR_FUN_006c2228;
  if (in_ECX[0xfe] != 0) {
    do {
      piVar1 = reinterpret_cast<int*>(in_ECX[0xfc]);
      iVar2 = *piVar1;
      in_ECX[0xfc] = static_cast<uint32_t>(iVar2);
      if (iVar2 == 0) {
        in_ECX[0xfd] = 0;
      }
      else {
        *reinterpret_cast<intptr_t*>(iVar2 + 4) = 0;
      }
      puVar3 = reinterpret_cast<uint32_t*>(piVar1[2]);
      // vtable held directly in slot 0xfb; call slot +8 with the node.
      vfn_raw<void (__cdecl*)(void*)>(in_ECX[0xfb], 8)(piVar1);
      in_ECX[0xfe] = in_ECX[0xfe] + -1;
      if (puVar3 != 0) {
        vfn<void (__cdecl*)(int)>(puVar3, 0)(1);
      }
    } while (in_ECX[0xfe] != 0);
  }
  *reinterpret_cast<void**>(in_ECX + 0xfb) = &PTR_FUN_006c2280;
  FUN_005edba0(self);
  *reinterpret_cast<void**>(in_ECX + 0xfb) = &PTR_LAB_006c221c;
  FUN_00497420(self);
  FUN_0054ab10(self);
  return;
}

// ---------------------------------------------------------------------------
// 0x54e050
// ---------------------------------------------------------------------------

// 0x54e050 — observed shape
intptr_t FUN_0054e050(void* self, intptr_t param_1)
{
  int32_t aiStack_28[9];
  int32_t* piStack_34;
  uint32_t local_4;
  char cVar3;
  intptr_t iVar7;

  aiStack_28[8] = static_cast<int32_t>(
      (2 << (DAT_0072745c & 0x1f)) & DAT_00717834 |
      (1 << (DAT_0071783c & 0x1f)) & DAT_00717838);
  aiStack_28[7] = 8;
  aiStack_28[6] = 0;
  aiStack_28[5] = 0;
  aiStack_28[4] = 0;
  aiStack_28[3] = 0;
  aiStack_28[1] = 2;
  aiStack_28[2] = 0;
  local_4 = 0;

  cVar3 = vfn<char (__cdecl*)(void*)>(self, 0x20)(
      reinterpret_cast<void*>(param_1 + 0xc));
  int32_t* piVar10;
  if (cVar3 == '\0') {
    cVar3 = vfn<char (__cdecl*)(void*)>(self, 0x1c)(
        reinterpret_cast<void*>(param_1 + 0xc));
    if (cVar3 == '\0') {
      return 0;
    }
    piVar10 = DAT_00727484;
  }
  else {
    piVar10 = DAT_00727460;
  }
  int32_t* piVar12 = aiStack_28;
  for (int iVar9 = 9; iVar9 != 0; iVar9 = iVar9 + -1) {
    *piVar12 = *piVar10;
    piVar10 = piVar10 + 1;
    piVar12 = piVar12 + 1;
  }

  bool rebuild = (param_1 == 0) ||
                 (*reinterpret_cast<int32_t*>(param_1 + 0x28) != aiStack_28[7]) ||
                 (*reinterpret_cast<uint32_t*>(param_1 + 0x2c) !=
                  static_cast<uint32_t>(aiStack_28[8])) ||
                 (*reinterpret_cast<uint32_t*>(param_1 + 0x44) < 2);
  // The corpus assigns iVar7 = param_1 inside the same short-circuit chain.
  iVar7 = param_1;
  if (rebuild) {
    intptr_t iVar4 = reinterpret_cast<intptr_t>(FUN_00533c78(0x50));
    iVar7 = 0;
    if (iVar4 != 0) {
      iVar7 = FUN_00539210(*reinterpret_cast<void**>(param_1 + 0x38),
                           *reinterpret_cast<void**>(param_1 + 0x3c), aiStack_28, 0);
    }
  }

  uint32_t uVar1 = *reinterpret_cast<uint32_t*>(iVar7 + 0x44);
  if (param_1 != iVar7) {
    // Ghidra dispatches slot 0x2c through `piStack_34`, a receiver it never
    // defines (a register lost during analysis); the enclosing object is used
    // here as the only observed candidate receiver.
    // NEEDS_MANUAL: original virtual receiver for the 0x2c comparison.
    cVar3 = vfn<char (__cdecl*)(intptr_t, intptr_t, int)>(self, 0x2c)(iVar7, param_1, 0);
    if (cVar3 == '\0') {
      return 0;
    }
  }

  if ((aiStack_28[7] == DAT_0072747c) && (aiStack_28[8] == DAT_00727480)) {
    // Corpus seeds the reused `piStack_34` slot with 1 and walks it as the
    // plane index; kept as a plain integer index here.
    int idx = 1;
    if (1 < static_cast<int>(uVar1)) {
      do {
        const int32_t* widths = reinterpret_cast<int32_t*>(iVar7 + 0x38);
        const int32_t* heights = reinterpret_cast<int32_t*>(iVar7 + 0x3c);
        const int32_t* offsets = reinterpret_cast<int32_t*>(iVar7 + 0x40);
        int32_t rowBytes = *reinterpret_cast<int32_t*>(iVar7 + 0x34);
        uint8_t* pbVar11 = reinterpret_cast<uint8_t*>(offsets[idx - 1] + rowBytes);
        uint8_t* puVar8 = reinterpret_cast<uint8_t*>(offsets[idx] + rowBytes);
        int iVar4 = widths[idx];
        int32_t* piVar10 = reinterpret_cast<int32_t*>(heights + idx);
        int iVar2 = widths[idx - 1];
        int iVar5 = *piVar10;
        if (iVar2 == 1) {
          for (; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar8 = static_cast<uint8_t>((static_cast<uint32_t>(pbVar11[3]) +
                                            static_cast<uint32_t>(pbVar11[0])) >> 1);
            puVar8[1] = static_cast<uint8_t>((static_cast<uint32_t>(pbVar11[4]) +
                                              static_cast<uint32_t>(pbVar11[1])) >> 1);
            puVar8[2] = static_cast<uint8_t>((static_cast<uint32_t>(pbVar11[5]) +
                                              static_cast<uint32_t>(pbVar11[2])) >> 1);
            puVar8 = puVar8 + 3;
            pbVar11 = pbVar11 + 6;
          }
        }
        else if (piVar10[-1] == 1) {
          for (; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar8 = static_cast<uint8_t>((static_cast<uint32_t>(pbVar11[3]) +
                                            static_cast<uint32_t>(pbVar11[0])) >> 1);
            puVar8[1] = static_cast<uint8_t>((static_cast<uint32_t>(pbVar11[4]) +
                                              static_cast<uint32_t>(pbVar11[1])) >> 1);
            puVar8[2] = static_cast<uint8_t>((static_cast<uint32_t>(pbVar11[5]) +
                                              static_cast<uint32_t>(pbVar11[2])) >> 1);
            puVar8 = puVar8 + 3;
            pbVar11 = pbVar11 + 6;
          }
        }
        else if (iVar5 != 0) {
          do {
            if (iVar4 != 0) {
              uint8_t* pbVar6 = pbVar11 + static_cast<size_t>(iVar2) * 3;
              int iVar13 = iVar2 * -3;
              int iVar9 = iVar4;
              do {
                *puVar8 = static_cast<uint8_t>((static_cast<uint32_t>(pbVar6[iVar13 + 3]) +
                                                static_cast<uint32_t>(pbVar6[3]) +
                                                static_cast<uint32_t>(pbVar6[0]) +
                                                static_cast<uint32_t>(pbVar11[0])) >> 2);
                puVar8[1] = static_cast<uint8_t>((static_cast<uint32_t>(pbVar6[iVar13 + 1]) +
                                                  static_cast<uint32_t>(pbVar6[iVar13 + 4]) +
                                                  static_cast<uint32_t>(pbVar6[4]) +
                                                  static_cast<uint32_t>(pbVar6[1])) >> 2);
                puVar8[2] = static_cast<uint8_t>((static_cast<uint32_t>(pbVar6[iVar13 + 2]) +
                                                  static_cast<uint32_t>(pbVar6[iVar13 + 5]) +
                                                  static_cast<uint32_t>(pbVar6[5]) +
                                                  static_cast<uint32_t>(pbVar6[2])) >> 2);
                puVar8 = puVar8 + 3;
                pbVar11 = pbVar11 + 6;
                pbVar6 = pbVar6 + 6;
                iVar9 = iVar9 + -1;
              } while (iVar9 != 0);
            }
            pbVar11 = pbVar11 + static_cast<size_t>(iVar2) * 3;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        idx = idx + 1;
      } while (idx < static_cast<int>(uVar1));
      return iVar7;
    }
  }
  else if (((aiStack_28[7] == DAT_007274a0) && (aiStack_28[8] == DAT_007274a4)) &&
           (1 < static_cast<int>(uVar1))) {
    uint32_t uVar14 = 1;
    do {
      const int32_t* widths = reinterpret_cast<int32_t*>(iVar7 + 0x38);
      const int32_t* heights = reinterpret_cast<int32_t*>(iVar7 + 0x3c);
      const int32_t* offsets = reinterpret_cast<int32_t*>(iVar7 + 0x40);
      int32_t rowBytes = *reinterpret_cast<int32_t*>(iVar7 + 0x34);
      uint8_t* pbVar11 =
          reinterpret_cast<uint8_t*>(offsets[uVar14 - 1] + rowBytes);
      uint8_t* puVar8 = reinterpret_cast<uint8_t*>(offsets[uVar14] + rowBytes);
      int iVar4 = widths[uVar14];
      piStack_34 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(heights[uVar14]));
      int iVar2 = widths[uVar14 - 1];
      if (iVar2 == 1) {
        if (piStack_34 != 0) {
          do {
            *puVar8 = static_cast<uint8_t>((static_cast<uint32_t>(pbVar11[4]) +
                                            static_cast<uint32_t>(pbVar11[0])) >> 1);
            puVar8[1] = static_cast<uint8_t>((static_cast<uint32_t>(pbVar11[5]) +
                                              static_cast<uint32_t>(pbVar11[1])) >> 1);
            puVar8[2] = static_cast<uint8_t>((static_cast<uint32_t>(pbVar11[6]) +
                                              static_cast<uint32_t>(pbVar11[2])) >> 1);
            puVar8[3] = static_cast<uint8_t>((static_cast<uint32_t>(pbVar11[7]) +
                                              static_cast<uint32_t>(pbVar11[3])) >> 1);
            puVar8 = puVar8 + 4;
            pbVar11 = pbVar11 + 8;
            piStack_34 = reinterpret_cast<int32_t*>(
                reinterpret_cast<intptr_t>(piStack_34) - 1);
          } while (piStack_34 != 0);
        }
      }
      else if (heights[uVar14 - 1] == 1) {
        for (; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar8 = static_cast<uint8_t>((static_cast<uint32_t>(pbVar11[4]) +
                                          static_cast<uint32_t>(pbVar11[0])) >> 1);
          puVar8[1] = static_cast<uint8_t>((static_cast<uint32_t>(pbVar11[5]) +
                                            static_cast<uint32_t>(pbVar11[1])) >> 1);
          puVar8[2] = static_cast<uint8_t>((static_cast<uint32_t>(pbVar11[6]) +
                                            static_cast<uint32_t>(pbVar11[2])) >> 1);
          puVar8[3] = static_cast<uint8_t>((static_cast<uint32_t>(pbVar11[7]) +
                                            static_cast<uint32_t>(pbVar11[3])) >> 1);
          puVar8 = puVar8 + 4;
          pbVar11 = pbVar11 + 8;
        }
      }
      else if (piStack_34 != 0) {
        do {
          if (iVar4 != 0) {
            uint8_t* pbVar6 = pbVar11 + static_cast<size_t>(iVar2) * 4;
            int iVar9 = iVar2 * -4;
            int iVar5 = iVar4;
            do {
              *puVar8 = static_cast<uint8_t>((static_cast<uint32_t>(pbVar6[iVar9 + 4]) +
                                              static_cast<uint32_t>(pbVar6[4]) +
                                              static_cast<uint32_t>(pbVar11[0]) +
                                              static_cast<uint32_t>(pbVar6[0])) >> 2);
              puVar8[1] = static_cast<uint8_t>((static_cast<uint32_t>(pbVar6[iVar9 + 1]) +
                                                static_cast<uint32_t>(pbVar6[iVar9 + 5]) +
                                                static_cast<uint32_t>(pbVar6[5]) +
                                                static_cast<uint32_t>(pbVar6[1])) >> 2);
              puVar8[2] = static_cast<uint8_t>((static_cast<uint32_t>(pbVar6[iVar9 + 2]) +
                                                static_cast<uint32_t>(pbVar6[iVar9 + 6]) +
                                                static_cast<uint32_t>(pbVar6[6]) +
                                                static_cast<uint32_t>(pbVar6[2])) >> 2);
              puVar8[3] = static_cast<uint8_t>((static_cast<uint32_t>(pbVar6[iVar9 + 3]) +
                                                static_cast<uint32_t>(pbVar6[iVar9 + 7]) +
                                                static_cast<uint32_t>(pbVar6[7]) +
                                                static_cast<uint32_t>(pbVar6[3])) >> 2);
              puVar8 = puVar8 + 4;
              pbVar11 = pbVar11 + 8;
              pbVar6 = pbVar6 + 8;
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
          }
          pbVar11 = pbVar11 + static_cast<size_t>(iVar2) * 4;
          piStack_34 = reinterpret_cast<int32_t*>(
              reinterpret_cast<intptr_t>(piStack_34) - 1);
        } while (piStack_34 != 0);
      }
      uVar14 = uVar14 + 1;
    } while (uVar14 < uVar1);
  }
  return iVar7;
}

// ---------------------------------------------------------------------------
// 0x54e6c0
// ---------------------------------------------------------------------------

// 0x54e6c0 — observed shape
intptr_t FUN_0054e6c0(void* self, uint32_t* param_1)
{
  int* in_ECX = static_cast<int*>(self);
  uint32_t* local_50;
  intptr_t iStack_4c;
  int32_t iStack_40;
  uint32_t uStack_3c;
  uint8_t auStack_24[4];
  uint32_t uStack_20;

  if (param_1 != 0) {
    param_1[1] = param_1[1] + 1;
  }
  local_50 = 0;
  if ((static_cast<int32_t>(param_1[10]) == DAT_0072747c) &&
      (static_cast<int32_t>(param_1[0xb]) == DAT_00727480)) {
    if (param_1 != 0) {
      local_50 = param_1;
      param_1[1] = param_1[1] + 1;
    }
  }
  else {
    char cVar4 = vfn<char (__cdecl*)(void*, void*)>(in_ECX, 0xc)(
        param_1 + 3, DAT_00727460);
    if (cVar4 == '\0') {
      if (param_1 != 0) {
        uint32_t* piVar1 = param_1 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          vfn<void (__cdecl*)(int)>(param_1, 0)(1);
        }
      }
      return 0;
    }
    // CONCAT31((int3)(param_1[0x11] >> 8), 1 < param_1[0x11]) — the upper three
    // bytes come from the shifted word, the low byte from the comparison.
    uint32_t arg4 = ((param_1[0x11] >> 8) & 0x00ffffffu) |
                    ((1 < param_1[0x11]) ? 1u : 0u);
    uint32_t* puVar6 = reinterpret_cast<uint32_t*>(
        vfn<void* (__cdecl*)(void*, void*, int, uint32_t)>(in_ECX, 0x10)(
            param_1, DAT_00727460, 0, arg4));
    if (puVar6 != 0) {
      puVar6[1] = puVar6[1] + 1;
      local_50 = puVar6;
    }
  }

  intptr_t iVar7 = reinterpret_cast<intptr_t>(FUN_00533c78(0x50));
  if (iVar7 == 0) {
    iStack_4c = 0;
  }
  else {
    FUN_00538830(7);
    uStack_20 = 0;
    iStack_4c = FUN_00539210(*reinterpret_cast<void**>(local_50 + 0xe),
                             *reinterpret_cast<void**>(local_50 + 0xf), 
                             reinterpret_cast<int*>(auStack_24), local_50[0x11]);
  }

  uStack_3c = 0;
  if (local_50[0x11] != 0) {
    do {
      intptr_t iVar7b = *reinterpret_cast<intptr_t*>(iStack_4c + 0x34);
      int32_t iVar2 = *reinterpret_cast<int32_t*>(
          *reinterpret_cast<intptr_t*>(iStack_4c + 0x40) + uStack_3c * 4);
      int32_t* heights = reinterpret_cast<int32_t*>(param_1[0xf]);
      int32_t* widths = reinterpret_cast<int32_t*>(param_1[0xe]);
      iStack_40 = heights[uStack_3c];
      int32_t iVar3 = widths[uStack_3c];
      int32_t iVar8 = iStack_40 * iVar3;
      int32_t iStack00000008 = 0;
      if (iStack_40 != 0) {
        do {
          if (iVar3 != 0) {
            int32_t iStack_48 = iVar3;
            do {
              uint32_t uVar9 = 0;
              uint8_t* puVar10 = reinterpret_cast<uint8_t*>(
                  static_cast<intptr_t>(iStack00000008) + iVar2 + iVar7b);
              do {
                uint8_t uVar5 = FUN_005f0ddc();
                *puVar10 = uVar5;
                uVar9 = uVar9 + 1;
                puVar10 = puVar10 + iVar8;
              } while (uVar9 < 3);
              iStack00000008 = iStack00000008 + 1;
              if (iStack00000008 == iVar8) {
                iStack00000008 = 0;
              }
              iStack_48 = iStack_48 + -1;
            } while (iStack_48 != 0);
          }
          iStack_40 = iStack_40 + -1;
        } while (iStack_40 != 0);
      }
      uStack_3c = uStack_3c + 1;
    } while (uStack_3c < static_cast<uint32_t>(local_50[0x11]));
  }

  uint32_t* piVar1 = local_50 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    vfn<void (__cdecl*)(int)>(local_50, 0)(1);
  }
  if (param_1 != 0) {
    uint32_t* piVar1b = param_1 + 1;
    *piVar1b = *piVar1b + -1;
    if (*piVar1b == 0) {
      vfn<void (__cdecl*)(int)>(param_1, 0)(1);
    }
  }
  return iStack_4c;
}
