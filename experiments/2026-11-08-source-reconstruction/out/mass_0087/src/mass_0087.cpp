#include <cstdint>
#include <cstddef>
#include <windows.h>

extern int FUN_00449390(const void* a, uint32_t b);
extern int FUN_00552ec0(uint32_t b);
extern void operator_delete(void* p);
extern int DAT_007273fc;
extern int PTR_FUN_00711328;
extern int PTR_LAB_00711248;
extern int PTR_FUN_0071131c;
extern int PTR_LAB_0071123c;
extern int PTR_FUN_007113e8;
extern int DAT_00727430;
extern int DAT_00727434;
extern int DAT_00727438;
extern void FUN_005071f0(void* self);
extern void FUN_00506e60(uint32_t p1, uint32_t p2, uint32_t p3, float p4, uint32_t p5, float p6, uint32_t p7);
extern void FUN_00506040(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e);
extern void FUN_00507c90(int32_t p1);
extern void FUN_00507d20(int32_t p1);

// NEEDS_MANUAL: float10 extended (80-bit x87) not representable in standard C++; using long double as placeholder for the ABI artifact.
using float10 = long double;

template <typename T> struct StructAt {};
// 0x506aa0 — observed shape
float10 FUN_00506aa0(void* self) {
  uint32_t uVar2 = 0;
  if (*(uint32_t*)((char*)self + 0x38) != 0) {
    int32_t* piVar3 = *(int32_t**)((char*)self + 0x30);
    do {
      int32_t iVar1 = *piVar3;
      if (iVar1 != 0 && (float10)*(float*)((char*)iVar1 + 0x18) != (float10)*(float*)((char*)iVar1 + 0x1c)) {
        return (float10)*(float*)((char*)iVar1 + 0x18);
      }
      uVar2 = uVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (uVar2 < *(uint32_t*)((char*)self + 0x38));
  }
  int32_t* base = *(int32_t*)((char*)self + 0x30);
  int32_t elem = *(int32_t*)((char*)base + (*(int32_t*)((char*)self + 0x9c)) * 4);
  return (float10)*(float*)((char*)elem + 0x18);
}

// 0x506af0 — observed shape
float10 FUN_00506af0(int32_t param_1) {
  uint32_t uVar4 = 0;
  if (*(int32_t*)((char*)param_1 + 0x38) != 0) {
    do {
      int32_t iVar1 = *(int32_t*)(*(int32_t*)((char*)param_1 + 0x30) + uVar4 * 4);
      if (iVar1 != 0 && (*(float*)((char*)iVar1 + 0x18) != *(float*)((char*)iVar1 + 0x1c))) &&
         (((*(unsigned char*)((char*)iVar1 + 0xc) >> 5) & 1) != 0)) {
        int32_t iVar2 = FUN_00449390(&DAT_007273fc, *(uint32_t*)((char*)iVar1 + 0x34));
        if (iVar2 == 0 || (((*(unsigned char*)((char*)iVar2 + 0x20) >> 1) & 1) != 0)) {
          int32_t idx = *(int32_t*)((char*)iVar1 + 0x3c);
          int32_t iVar3 = FUN_00552ec0(*((uint32_t*)((char*)iVar1 + 0x34)));
          if (idx == iVar3) {
            return (float10)*(float*)((char*)iVar1 + 0x24);
          }
        }
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint32_t*)((char*)param_1 + 0x38));
  }
  int32_t* base = *(int32_t*)((char*)param_1 + 0x30);
  int32_t elem = *(int32_t*)((char*)base + (*(int32_t*)((char*)param_1 + 0x9c)) * 4);
  return (float10)*(float*)((char*)elem + 0x24);
}

// 0x506b80 — observed shape
void FUN_00506b80(void* self, uint32_t param_1) {
  uint32_t uVar2 = 0;
  if (*(int32_t*)((char*)self + 0x38) != 0) {
    do {
      int32_t iVar1 = *(int32_t*)(*(int32_t*)((char*)self + 0x30) + uVar2 * 4);
      if (iVar1 != 0) {
        *(uint32_t*)((char*)iVar1 + 0x14) = param_1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint32_t*)((char*)self + 0x38));
  }
}

// 0x506bb0 — observed shape
void FUN_00506bb0(void* self) {
  int32_t* in_ECX = (int32_t*)self;
  *in_ECX = (int32_t)(intptr_t)&PTR_FUN_00711328;
  uint32_t* puVar2 = *(uint32_t**)((char*)in_ECX + 4);
  while (puVar2 != (uint32_t*)0x0) {
    uint32_t* puVar1 = (uint32_t*)*puVar2;
    void (**vtab)(uint32_t*) = (void (**)(uint32_t*))(*(int32_t**)in_ECX + 2);
    (*vtab)(puVar2);
    puVar2 = puVar1;
  }
  in_ECX[3] = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  *in_ECX = (int32_t)(intptr_t)&PTR_LAB_00711248;
}

// 0x506bf0 — observed shape
void FUN_00506bf0(void* self) {
  int32_t* in_ECX = (int32_t*)self;
  *in_ECX = (int32_t)(intptr_t)&PTR_FUN_0071131c;
  uint32_t* puVar2 = *(uint32_t**)((char*)in_ECX + 4);
  while (puVar2 != (uint32_t*)0x0) {
    uint32_t* puVar1 = (uint32_t*)*puVar2;
    void (**vtab)(uint32_t*) = (void (**)(uint32_t*))(*(int32_t**)in_ECX + 2);
    (*vtab)(puVar2);
    puVar2 = puVar1;
  }
  in_ECX[3] = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  *in_ECX = (int32_t)(intptr_t)&PTR_LAB_0071123c;
}
// 0x506c30 — observed shape
void FUN_00506c30(void* self, uint8_t param_1) {
  uint32_t* in_ECX = (uint32_t*)self;
  *in_ECX = (uint32_t)(intptr_t)&PTR_FUN_007113e8;
  FUN_005071f0(self);
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
}

// 0x506c60 — observed shape
void FUN_00506c60(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6) {
  uint32_t* unaff_ESI = (uint32_t*)self;
  FUN_00506e60(param_1, param_2, param_3, *(float*)&param_4, param_5, *(float*)&param_6, (uint32_t)(intptr_t)self);
  *unaff_ESI = (uint32_t)(intptr_t)&PTR_FUN_007113e8;
  if (unaff_ESI[0xa4] != 0) {
    unaff_ESI[0xa4] = 0;
    FUN_00506040(unaff_ESI[0xa5], 0x3f800000, 0, 0, 0x3f800000);
  }
}

// 0x506cd0 — observed shape
void FUN_00506cd0(void* self, int32_t in_ECX) {
  int32_t in_EAX = (int32_t)(intptr_t)self;
  if (*(int32_t*)((char*)self + 0x290) != in_ECX) {
    *(int32_t*)((char*)self + 0x290) = in_ECX;
    FUN_00506040(*(uint32_t*)(in_EAX + 0x294 + in_ECX * 4), 0x3f800000, 0, 0, 0x3f800000);
  }
}

// 0x506d00 — observed shape
void FUN_00506d00(int32_t param_1, int32_t in_ECX) {
  int32_t iVar1 = param_1;
  FUN_00507c90(param_1);
  int32_t vtbl = *(int32_t*)(iVar1 + 0x15c);
  void (**vfunc)(const void*, int) = (void (**)(const void*, int))(*(int32_t**)vtbl + 2);
  (*vfunc)(&param_1, 4);
  (*vfunc)((char*)in_ECX + 0x290, 4);
  (*vfunc)((char*)in_ECX + 0x294, 8);
}

// 0x506d50 — observed shape
void FUN_00506d50(int32_t param_1, int32_t in_ECX) {
  int32_t iVar1 = param_1;
  FUN_00507d20(param_1);
  param_1 = 0x3f800000;
  int32_t vtbl = *(int32_t*)(iVar1 + 0x160);
  void (**vfunc)(const void*, int) = (void (**)(const void*, int))(*(int32_t**)vtbl + 3);
  (*vfunc)(&param_1, 4);
  (*vfunc)((char*)in_ECX + 0x290, 4);
  (*vfunc)((char*)in_ECX + 0x294, 8);
}

// ---- appended reconstructions (mass_0087 retry) ----

extern void FUN_0053bb30(int32_t p1);
extern int32_t DAT_008cad0c;
extern int32_t FUN_00533c78(size_t sz);
extern void* DAT_008ea08c;
extern void FUN_00507b90();
extern void FUN_00504070(void* self);
extern void FUN_00540460(uint32_t p1);
extern void FUN_00503fb0(void* self);
extern void FUN_00546930();
extern void* FUN_00504990(void* p1);
extern void FUN_005050f0(uint32_t p1, uint32_t p2, uint32_t p3);
extern char FUN_00545060(char* p1);
extern void FUN_00546ad0();
extern void FUN_00505420(uint32_t p1);
extern void FUN_0053c280(int32_t* p1, int32_t p2);
extern void FUN_00507ac0(int32_t* p1, uint32_t* p2);
extern void FUN_00534130();
extern void FUN_00534350();
extern void FUN_00533d10(uint32_t p1, uint32_t p2);
extern void FUN_00507520(void* self, int32_t* in_EDI);
extern char DAT_00727720;
extern void* PTR_FUN_00717a84;
extern int PTR_FUN_007114b0;
extern void FUN_00504b10(void* p1);
extern void FUN_0053c1d0();
extern void FUN_00504160();
extern int _stricmp(const char* a, const char* b);
extern int sprintf(char* buf, const char* fmt, ...);
extern float fabsf(float x);

// 0x506e60 — observed shape
// Constructor: installs vtable PTR_FUN_007114b0, clears the state block,
// samples the two getters of DAT_008ea08c's vtable (+0x58/+0x5c), then either
// loads a .kfm/.dds pair named by param_2 or moves the caller's transform into
// +0x5c..+0x64. in_EAX is a copy of param_7 (the object pointer the caller
// passes as the last argument; FUN_00506c60 does exactly that), so param_7 is
// both the receiver and the trailing `param_7 != 0` flag.
void FUN_00506e60(uint32_t param_1, uint32_t param_2, uint32_t param_3, float param_4,
                  uint32_t param_5, float param_6, uint32_t param_7)
{
  uint32_t* in_EAX = (uint32_t*)param_7;
  char* path = (char*)param_2;
  char acStack_200[512];
  int32_t* piStack_268;  // NEEDS_MANUAL: Ghidra reloads stack slot +0x268 after
                         // FUN_00546930 with no visible writer; used as FxWidget receiver.

  FUN_0053bb30(0);
  bool bVar8 = DAT_008cad0c == 0;
  *in_EAX = (uint32_t)(intptr_t)&PTR_FUN_007114b0;
  in_EAX[0x4a] = 0;
  in_EAX[0x4b] = 0;
  in_EAX[0x4c] = 0;
  in_EAX[0x4d] = 0;
  in_EAX[0x3b] = 0xffffffff;
  *(uint8_t*)(in_EAX + 0x3c) = 0;
  in_EAX[0x3e] = 0;
  *(uint8_t*)((char*)in_EAX + 0xf1) = 0;
  *(uint8_t*)((char*)in_EAX + 0xf2) = 0;
  *(uint8_t*)((char*)in_EAX + 0xf3) = 0;
  *(uint8_t*)(in_EAX + 0x4f) = 0;
  in_EAX[0x3f] = 0;
  in_EAX[0x4a] = 0;
  if (bVar8) {
    DAT_008cad0c = FUN_00533c78(1);
  }
  uint32_t devVtbl = *(uint32_t*)DAT_008ea08c;
  int32_t iVar4 = (*(int32_t (**)(void))(devVtbl + 0x58))();
  bVar8 = DAT_008cad0c == 0;
  in_EAX[0x4c] = 0;
  *(float*)(in_EAX + 0x4b) = (float)iVar4;
  if (bVar8) {
    DAT_008cad0c = FUN_00533c78(1);
  }
  iVar4 = (*(int32_t (**)(void))(devVtbl + 0x5c))();
  in_EAX[0x40] = 0;
  in_EAX[0x44] = 0;
  *(float*)(in_EAX + 0x4d) = (float)iVar4;
  in_EAX[0x41] = (uint32_t)DAT_00727430;
  in_EAX[0x42] = (uint32_t)DAT_00727434;
  in_EAX[0x43] = (uint32_t)DAT_00727438;
  in_EAX[0x45] = 0;
  in_EAX[0x49] = 0;
  in_EAX[0x46] = (uint32_t)DAT_00727430;
  in_EAX[0x47] = (uint32_t)DAT_00727434;
  in_EAX[0x48] = (uint32_t)DAT_00727438;
  in_EAX[0x4e] = 0x3f800000;
  uint32_t* puVar7 = in_EAX + 0x90;
  for (iVar4 = 0x14; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = 0xffffffff;
    puVar7 = puVar7 + 1;
  }
  in_EAX[0x3d] = 0xffffffff;
  in_EAX[0x8f] = 0;
  if (param_1 == 0) {
    FUN_00507b90();
  }
  else if (param_1 != 0xffffffff) {
    iVar4 = (int32_t)in_EAX[0x3f];
    if (iVar4 != 0) {
      FUN_00504070(in_EAX);
    }
    FUN_00540460(param_1);
    if (iVar4 != 0) {
      FUN_00503fb0(in_EAX);
    }
  }
  if (path != (char*)0x0) {
    FUN_00546930();
    char* pcVar1 = path + 1;
    char* pcVar5 = path;
    char cVar3;
    do {
      cVar3 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar3 != '\0');
    // Offset of the trailing ".xxx" relative to the path pointer, kept in a
    // register and reused below after the pointer has been advanced.
    int32_t extDelta = (int32_t)((intptr_t)pcVar5 - 4 - (intptr_t)pcVar1);
    iVar4 = _stricmp((char*)((intptr_t)path + extDelta), ".kfm");
    if (iVar4 == 0) {
      char* dst = (char*)in_EAX + 0x13c;
      do {
        cVar3 = *path;
        *dst = cVar3;
        dst = dst + 1;
        path = path + 1;
      } while (cVar3 != '\0');
      iVar4 = FUN_00533c78(0x8c);
      uint32_t uVar6;
      if (iVar4 == 0) {
        uVar6 = 0;
      }
      else {
        uVar6 = (uint32_t)(intptr_t)FUN_00504990((void*)(intptr_t)iVar4);
      }
      in_EAX[0x8f] = uVar6;
      FUN_005050f0(uVar6, 0, 1);
      path = *(char**)((intptr_t)in_EAX[0x8f] + 8);
    }
    char cVar9 = FUN_00545060(path);
    if (cVar9 == '\0') {
      iVar4 = _stricmp((char*)((intptr_t)path + extDelta), ".dds");
      if (iVar4 != 0) {
        sprintf(acStack_200, "Loading NIF.  %s: %s, kfm name:%s", &DAT_00727720, path,
                (char*)(in_EAX + 0x4f));
        if (PTR_FUN_00717a84 != (void*)0x0) {
          ((void (*)(const char*, const char*, int32_t))PTR_FUN_00717a84)(
              acStack_200, "FxWidget::FxWidget", 0);
        }
      }
      FUN_00546ad0();
      return;
    }
    int32_t* piVar2 = (int32_t*)*piStack_268;
    if (in_EAX[0x8f] != 0) {
      uint32_t uVar6 = (*(uint32_t (**)(uint32_t))(*(uint32_t*)piVar2 + 0x40))(
          *(uint32_t*)((intptr_t)(*(int32_t*)((intptr_t)in_EAX[0x8f] + 0x58)) + 0xc));
      FUN_00505420(uVar6);
    }
    FUN_0053c280(piVar2, 1);
    piVar2[0x1a] = (int32_t)fabsf(param_6);
    FUN_00507ac0(piVar2, in_EAX);
    FUN_00546ad0();
  }
  in_EAX[0x17] = param_3;
  in_EAX[0x18] = param_5;
  *(float*)(in_EAX + 0x19) = -param_4;
  FUN_00534130();
  FUN_00534350();
  FUN_00533d10(0, 1);
  if (param_7 != 0) {
    FUN_00507520(in_EAX, (int32_t*)in_EAX);
  }
}

// 0x5071d0 — observed shape
// Scalar deleting destructor: runs FUN_005071f0 on the same receiver, then frees
// it when the low bit of param_1 is set.
void FUN_005071d0(void* self, uint8_t param_1)
{
  FUN_005071f0(self);
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x5071f0 — observed shape
// Destructor: reinstalls the base vtable, unlinks the owning widget at +0xfc
// from this object, releases/frees the KFM state at +0x23c, then runs the base
// destructor.
void FUN_005071f0(void* self)
{
  int32_t* in_ECX = (int32_t*)self;
  int32_t iVar1 = in_ECX[0x3f];
  *in_ECX = (int32_t)(intptr_t)&PTR_FUN_007114b0;
  if (iVar1 != 0) {
    if (*(int32_t**)((intptr_t)iVar1 + 8) == in_ECX) {
      *(int32_t*)((intptr_t)iVar1 + 8) = 0;
    }
    if (*(int32_t**)((intptr_t)in_ECX[0x3f] + 0xc) == in_ECX) {
      *(int32_t*)((intptr_t)in_ECX[0x3f] + 0xc) = 0;
    }
  }
  void* pvVar2 = (void*)(intptr_t)in_ECX[0x8f];
  if (pvVar2 != (void*)0x0) {
    FUN_00504b10(pvVar2);
    operator_delete(pvVar2);
    in_ECX[0x8f] = 0;
  }
  FUN_0053c1d0();
}

// 0x507290 — observed shape
// Copies param_1[0] and param_1[2] to +0x5c/+0x60 and stores the negated
// param_1[1] at +0x64 (y-axis flip of the input triple).
void FUN_00507290(void* self, float* param_1)
{
  int32_t* in_ECX = (int32_t*)self;
  float fVar1 = param_1[1];
  uint32_t uVar2 = ((uint32_t*)param_1)[2];
  in_ECX[0x17] = ((uint32_t*)param_1)[0];
  in_ECX[0x18] = uVar2;
  *(float*)(in_ECX + 0x19) = -fVar1;
}

// 0x5072d0 — observed shape
// Translates param_1 by (position - camera translation + anchor at param_2+0x90),
// with the same y negation the other transform accessors use, and forwards the
// resulting triple to the virtual setter at vtable+0x9c.
void FUN_005072d0(void* self, float* param_1, int32_t param_2)
{
  float* in_ECX = (float*)self;
  float local_c;
  float local_8;
  float local_4;

  local_c = (in_ECX[0x17] - (in_ECX[0x24] - *(float*)((char*)param_2 + 0x90))) + *param_1;
  local_8 = (-in_ECX[0x19] - (-in_ECX[0x26] - -*(float*)((char*)param_2 + 0x98))) + param_1[1];
  local_4 = (in_ECX[0x18] - (in_ECX[0x25] - *(float*)((char*)param_2 + 0x94))) + param_1[2];
  (*(void (**)(float*))(*(uint32_t*)in_ECX + 0x9c))(&local_c);
}

// 0x507400 — observed shape
// Adds the current local position (+0x5c..+0x64, y negated) to param_1 and
// forwards the sum to the virtual setter at vtable+0x9c.
void FUN_00507400(void* self, float* param_1)
{
  float* in_ECX = (float*)self;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;

  local_c = in_ECX[0x17];
  local_4 = in_ECX[0x18];
  local_8 = -in_ECX[0x19];
  local_18 = local_c + *param_1;
  local_14 = local_8 + param_1[1];
  local_10 = local_4 + param_1[2];
  (*(void (**)(float*))(*(uint32_t*)in_ECX + 0x9c))(&local_18);
}

// 0x507480 — observed shape
// Reads the scale triple at +0x5c..+0x64, negating the y component, into out.
void FUN_00507480(void* self, uint32_t* out)
{
  int32_t in_ECX = (int32_t)(intptr_t)self;
  uint32_t uVar1 = *(uint32_t*)(in_ECX + 0x60);
  float fVar2 = *(float*)(in_ECX + 100);
  out[0] = *(uint32_t*)(in_ECX + 0x5c);
  *(float*)(out + 1) = -fVar2;
  out[2] = uVar1;
}

// 0x5074d0 — observed shape
// Reads the translation triple at +0x90..+0x98, negating the y component, into out.
void FUN_005074d0(void* self, uint32_t* out)
{
  int32_t in_ECX = (int32_t)(intptr_t)self;
  uint32_t uVar1 = *(uint32_t*)(in_ECX + 0x94);
  float fVar2 = *(float*)(in_ECX + 0x98);
  out[0] = *(uint32_t*)(in_ECX + 0x90);
  *(float*)(out + 1) = -fVar2;
  out[2] = uVar1;
}

// 0x507520 — observed shape
// Re-applies the attached mesh when both the resource (+0x24) and the widget
// (+0xfc) exist, calls the virtual refresh slot (+0x70) and rebuilds the
// transform chain. unaff_ESI is the mesh owner, unaff_EDI the widget; both are
// the same FxWidget receiver in the observed call sites.
void FUN_00507520(void* self, int32_t* in_EDI)
{
  int32_t* unaff_ESI = (int32_t*)self;
  if ((*(int32_t*)((char*)unaff_ESI + 0x24) != 0) &&
      (*(int32_t*)((char*)unaff_ESI + 0xfc) != 0)) {
    FUN_00504070(unaff_ESI);
  }
  if (in_EDI[0x3f] != 0) {
    FUN_00503fb0(unaff_ESI);
  }
  (*(void (**)(void))((uint32_t)*in_EDI + 0x70))();
  FUN_00534130();
  FUN_00534350();
  FUN_00533d10(0, 1);
}

// 0x507570 — observed shape
// Returns 0 when no mesh (+0x24) is attached; rebuilds the transform graph and
// returns 1 when a widget (+0xfc) is present, otherwise dispatches the virtual
// slot at vtable+0x74 and forwards a flag byte observed on the stack.
// Ghidra restarted deadcode elimination for the stack frame here; uStack00000000
// is the unwritten local it compares against the constant address 4.
uint32_t FUN_00507570(void* self, uint32_t* in_ECX)
{
  int32_t in_EAX = (int32_t)(intptr_t)self;
  uint8_t uStack00000000;

  if (*(int32_t**)(in_EAX + 0x24) == (int32_t*)0x0) {
    return 0;
  }
  if (*(int32_t*)(in_EAX + 0xfc) != 0) {
    FUN_00504160();
    return 1;
  }
  uint32_t vtable = *(uint32_t*)(*(int32_t*)(in_EAX + 0x24));
  (*(void (**)(void))(vtable + 0x74))();
  if ((intptr_t)&uStack00000000 != 0x4) {
    if (uStack00000000 == 1) {
      (*(void (**)(int32_t))*in_ECX)(1);
    }
  }
  return 1;
}
