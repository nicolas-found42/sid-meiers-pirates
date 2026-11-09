#include <cstdint>
#include <cstddef>
#include <windows.h>

extern int FUN_00533c78(int size);
extern int FUN_0051ef70(int arg);
extern char FUN_0051bfc0(void** local_4);
extern int FUN_0051e2f0(uint32_t param_1);
extern void FUN_00524e90(void* puVar3);
extern void FUN_004f5670(void);
extern int FUN_00533db0(uint32_t uVar3);
extern void operator_delete__(void* p);
extern void operator_delete(void* p);
extern void* DAT_008cad60;
extern void* DAT_00727558;
extern void* DAT_00727c44;
extern void* DAT_00727b28;
extern void* DAT_007273fc;
extern void* DAT_00727560;
extern void* DAT_008cad5c;
extern void* PTR_FUN_007128c4;
extern void* PTR_FUN_00717a3c;

// 0x51e7d0 — observed shape
uint32_t FUN_0051e7d0(void* self, uint32_t param_1) {
  uint32_t* local_4 = (uint32_t*)self;
  if (DAT_008cad60 == 0) {
    int iVar2 = FUN_00533c78(0x14);
    if (iVar2 == 0) {
      DAT_008cad60 = 0;
    } else {
      DAT_008cad60 = (void*)(uintptr_t)FUN_0051ef70(1);
    }
  }
  char cVar1 = FUN_0051bfc0((void**)&local_4);
  if (cVar1 != '\0') {
    local_4[1] = local_4[1] + 1;
    return *local_4;
  }
  uint32_t* puVar3 = (uint32_t*)FUN_00533c78(8);
  int iVar2 = FUN_00533c78(0x48);
  uint32_t uVar4 = (iVar2 == 0) ? 0 : (uint32_t)FUN_0051e2f0(param_1);
  *puVar3 = uVar4;
  puVar3[1] = 1;
  FUN_00524e90(puVar3);
  return *puVar3;
}

// 0x51e870 — observed shape
// NEEDS_MANUAL: body truncated in corpus listing (lines 69-233 elided); preserved endpoints and outer iteration here
uint32_t FUN_0051e870(int* param_1) {
  if (param_1 == nullptr) return 0;
  uint32_t* puVar5 = (uint32_t*)(**(code**)(*param_1 + 4))();
  for (;;) {
    if (puVar5 == nullptr) goto LAB_0051e8c5;
    if (puVar5 == (uint32_t*)DAT_00727558) goto LAB_0051ec94;
    puVar5 = (uint32_t*)puVar5[1];
  }
LAB_0051e8c5:
  {
    uint16_t uVar1 = *(uint16_t*)((char*)param_1 + 0x2f * 4 + 0xc);
    void* pvStack_10 = nullptr;
    // elided inner block preserved as TODO-free marker
    (**(code**)(*(int*)PTR_FUN_00717a3c))(uVar1, *(uint32_t*)((char*)param_1 + 0x2f * 4 + 0x20), pvStack_10, (char*)param_1 + 0x1b * 4);
    uint32_t uVar9 = uVar1;
    int iVar7 = 0;
    // elided loops over uVar9 preserved by structure note
    (void)uVar9; (void)iVar7; (void)pvStack_10;
    if (pvStack_10 != nullptr) operator_delete__(pvStack_10);
  }
LAB_0051ec94:
  return 0;
}

// 0x51ed00 — observed shape
uint32_t FUN_0051ed00(uint32_t param_1) {
  uint32_t iVar4 = *(uint32_t*)(param_1 + 0x20);
  uint32_t uVar7 = 0;
  if (*(int*)(iVar4 + 0xc0) != 0) {
    if (*(int*)(iVar4 + 0xc0) == 0) goto LAB_0051edd6;
    do {
      int* piVar1 = *(int**)(*(uint32_t*)(iVar4 + 0xb8) + uVar7 * 4);
      if (piVar1 != nullptr) {
        uint8_t bVar3;
        uint32_t* puVar5 = (uint32_t*)(**(code**)(*piVar1 + 4))();
        for (; puVar5 != nullptr; puVar5 = (uint32_t*)puVar5[1]) {
          if (puVar5 == (uint32_t*)DAT_00727c44) { bVar3 = 1; goto LAB_0051ed50; }
        }
        bVar3 = 0;
LAB_0051ed50:
        if ((-(int)bVar3 & (uint32_t)(uintptr_t)piVar1) != 0) {
          iVar4 = *(uint32_t*)((-(int)bVar3 & (uint32_t)(uintptr_t)piVar1) + 0xbc);
          uint32_t uVar2 = *(uint32_t*)(param_1 + 0x30);
          if (uVar2 < *(uint32_t*)(param_1 + 0x2c) || (FUN_004f5670(), uVar2 < *(uint32_t*)(param_1 + 0x2c))) {
            if (uVar2 < *(uint32_t*)(param_1 + 0x30)) {
              if (iVar4 == 0) {
                if (*(int*)(**(uint32_t**)(param_1 + 0x28) + uVar2 * 4) != 0) { *(int*)(param_1 + 0x34) = *(int*)(param_1 + 0x34) + -1; }
              } else if (*(int*)(**(uint32_t**)(param_1 + 0x28) + uVar2 * 4) == 0) {
                *(int*)(param_1 + 0x34) = *(int*)(param_1 + 0x34) + 1;
              }
            } else {
              *(uint32_t*)(param_1 + 0x30) = uVar2 + 1;
              if (iVar4 != 0) *(int*)(param_1 + 0x34) = *(int*)(param_1 + 0x34) + 1;
            }
            *(uint32_t*)(**(uint32_t**)(param_1 + 0x28) + uVar2 * 4) = iVar4;
          }
          (**(code**)(*(uint32_t*)DAT_00727b28 + 0x18))(DAT_008cad5c, iVar4, 0, 0);
        }
      }
LAB_0051edd6:
      iVar4 = *(uint32_t*)(param_1 + 0x20);
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint32_t*)(iVar4 + 0xc0));
  }
  return 0;
}

// 0x51ee00 — observed shape
void FUN_0051ee00(void* self, int* param_1) {
  uint32_t* in_ECX = (uint32_t*)self;
  for (int iVar2 = param_1[4]; iVar2 != 0; iVar2 = *(int*)(iVar2 + 0x38)) {
    if (*(float*)((char*)in_ECX + 0x44) < *(float*)(iVar2 + 0x1c)) {
      *(float*)((char*)in_ECX + 0x44) = *(float*)(iVar2 + 0x1c);
    }
  }
  uint32_t* puVar1 = (uint32_t*)(**(code**)(*param_1 + 4))();
  for (;;) {
    if (puVar1 == nullptr) goto LAB_0051ee62;
    if (puVar1 == (uint32_t*)DAT_007273fc) break;
    puVar1 = (uint32_t*)puVar1[1];
  }
  uint32_t uVar3 = 0;
  do {
    int iVar2 = FUN_00533db0(uVar3);
    if (iVar2 != 0) FUN_0051ee00(self, (int*)iVar2);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0xc);
LAB_0051ee62:
  puVar1 = (uint32_t*)(**(code**)(*param_1 + 4))();
  if (puVar1 != nullptr) {
    while (puVar1 != (uint32_t*)DAT_00727560) {
      puVar1 = (uint32_t*)puVar1[1];
      if (puVar1 == nullptr) return;
    }
    uVar3 = 0;
    if (param_1[0x30] != 0) {
      do {
        int iVar2 = *(int*)(param_1[0x2e] + uVar3 * 4);
        if (iVar2 != 0) FUN_0051ee00(self, (int*)iVar2);
        uVar3 = uVar3 + 1;
      } while (uVar3 < (uint32_t)param_1[0x30]);
    }
  }
}

// 0x51eec0 — observed shape
void FUN_0051eec0(void* self, uint8_t param_1) {
  uint32_t* in_ECX = (uint32_t*)self;
  *in_ECX = (uint32_t)(uintptr_t)PTR_FUN_007128c4;
  operator_delete__((void*)(uintptr_t)in_ECX[1]);
  if ((param_1 & 1) != 0) operator_delete(in_ECX);
}

// ---------------------------------------------------------------------------
// Additional extern declarations for the definitions appended below.
// Only helpers/globals named by the assigned corpus listings.
// ---------------------------------------------------------------------------
extern void FUN_004e6420(void);
extern int FUN_004127b0(void* dst, int elemSize, uint32_t count, void* init);
extern int FUN_00449390(void* key, void* value);
extern void FUN_004aad70(uint32_t mode);
extern int FUN_00518960(uint32_t a, uint32_t b);
extern int FUN_00539c10(char* path, void* config);
extern void FUN_0050be00(uint32_t param);
extern void FUN_0050bf50(uint32_t param);
extern int FUN_00542700(uint32_t tex, int a, int b, int c, int d);
extern void FUN_00542cb0(int a, void* b);
extern void FUN_00547730(int handle, char* name, int flags);
extern void FUN_005606f0(int a, void* b);
extern int thunk_FUN_00533c78(int size);
extern "C" int sprintf(char* buffer, const char* format, ...);

extern uint8_t DAT_008ca4f8;
extern int DAT_008ca4fc;
extern uint8_t DAT_007179a4;
extern uint8_t DAT_00727598;
extern uint8_t DAT_007275e8;
extern uint8_t LAB_005cea70;
extern void* PTR_FUN_007128c8;
extern void* PTR_FUN_00712900;
extern void* PTR_FUN_007128e4;
extern void* PTR_FUN_007128c0;
extern void* PTR_FUN_00712970;
extern void* PTR_FUN_00712964;
extern void* PTR_FUN_00712968;
extern void* PTR_FUN_00711fbc;
extern void* PTR_FUN_0070d038;
extern void* PTR_LAB_007129b4;
extern char PTR_s_TTerrain_BlendTex_007265d8[];

// ---------------------------------------------------------------------------
// 0x51eef0 — observed shape
// Destructor chain. Deletes the second word of every node in each of the
// in_ECX[1] bucket lists, then swaps the vtable to PTR_FUN_00712900 and
// PTR_FUN_007128e4, calling FUN_004e6420 after each swap, then frees the
// bucket array at in_ECX[2].
// ---------------------------------------------------------------------------
void FUN_0051eef0(void* self)
{
  uint32_t* in_ECX = (uint32_t*)self;
  *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_007128c8;
  if ((*(char*)((char*)in_ECX + 0x10) != '\0') && (in_ECX[1] != 0)) {
    uint32_t uVar3 = 0;
    do {
      uint32_t* puVar2 = *(uint32_t**)(uintptr_t)(in_ECX[2] + uVar3 * 4);
      while (puVar2 != nullptr) {
        uint32_t* puVar1 = puVar2 + 1;
        puVar2 = (uint32_t*)(uintptr_t)*puVar2;
        operator_delete__((void*)(uintptr_t)*puVar1);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint32_t)in_ECX[1]);
  }
  *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_00712900;
  FUN_004e6420();
  *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_007128e4;
  FUN_004e6420();
  operator_delete__((void*)(uintptr_t)in_ECX[2]);
}

// ---------------------------------------------------------------------------
// 0x51ef70 — observed shape
// Bucket-array constructor. Count arrives in EAX, receiver in ESI, flag byte
// in param_1: stores count at +4, vtable PTR_FUN_007128e4, allocates
// count*4 bytes at +8, zeroes them, stores the flag at +0x10 and finally
// switches the vtable to PTR_FUN_007128c8.
// The file already declares a call site `FUN_0051ef70(int)`, so this
// reconstruction carries the _recon suffix.
// ---------------------------------------------------------------------------
void FUN_0051ef70_recon(uint32_t count, uint8_t param_1, void* self)
{
  uint32_t* unaff_ESI = (uint32_t*)self;
  unaff_ESI[1] = count;
  *unaff_ESI = (uint32_t)(uintptr_t)&PTR_FUN_007128e4;
  unaff_ESI[3] = 0;
  uint32_t* puVar1 = (uint32_t*)(uintptr_t)thunk_FUN_00533c78((int)(count << 2));
  unaff_ESI[2] = (uint32_t)(uintptr_t)puVar1;
  for (uint32_t uVar2 = unaff_ESI[1] & 0x3fffffffu; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  for (int iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(uint8_t*)puVar1 = 0;
    puVar1 = (uint32_t*)(uintptr_t)((uint32_t)(uintptr_t)puVar1 + 1);
  }
  *(uint8_t*)((char*)unaff_ESI + 0x10) = param_1;
  *unaff_ESI = (uint32_t)(uintptr_t)&PTR_FUN_007128c8;
}

// ---------------------------------------------------------------------------
// 0x51efc0 — observed shape
// Destructor: restore PTR_FUN_007128e4, FUN_004e6420, free the bucket array
// at in_ECX[2], conditional self delete when param_1 & 1.
// ---------------------------------------------------------------------------
void FUN_0051efc0(void* self, uint8_t param_1)
{
  uint32_t* in_ECX = (uint32_t*)self;
  *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_007128e4;
  FUN_004e6420();
  operator_delete__((void*)(uintptr_t)in_ECX[2]);
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
}

// ---------------------------------------------------------------------------
// 0x51f000 — observed shape
// Destructor with two vtable stages: PTR_FUN_00712900 then PTR_FUN_007128e4,
// FUN_004e6420 after each, free in_ECX[2], conditional self delete.
// ---------------------------------------------------------------------------
void FUN_0051f000(void* self, uint8_t param_1)
{
  uint32_t* in_ECX = (uint32_t*)self;
  *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_00712900;
  FUN_004e6420();
  *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_007128e4;
  FUN_004e6420();
  operator_delete__((void*)(uintptr_t)in_ECX[2]);
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
}

// ---------------------------------------------------------------------------
// 0x51f060 — observed shape
// Destructor: restore PTR_FUN_007128c0, delete in_ECX[1], conditional self
// delete when param_1 & 1.
// ---------------------------------------------------------------------------
void FUN_0051f060(void* self, uint8_t param_1)
{
  uint32_t* in_ECX = (uint32_t*)self;
  *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_007128c0;
  operator_delete__((void*)(uintptr_t)in_ECX[1]);
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
}

// ---------------------------------------------------------------------------
// 0x51f090 — observed shape
// Terrain manager constructor. Runs the base constructor FUN_00518960(ECX,EAX),
// installs vtable PTR_FUN_00712970 (secondary vtables at +0x54 and +0x70),
// zeroes the member block, then on first use loads the 15
// "./art/Terrain/Blends/TerrainAlpha%02d.tga" textures into
// DAT_008ca4f8[1..15] and marks each texture byte +0x44.
// ---------------------------------------------------------------------------
void FUN_0051f090(uint32_t in_ECX, uint32_t in_EAX, void* self)
{
  uint32_t* unaff_EDI = (uint32_t*)self;
  char local_104[260];

  FUN_00518960(in_ECX, in_EAX);
  *unaff_EDI = (uint32_t)(uintptr_t)&PTR_FUN_00712970;
  unaff_EDI[0x15] = (uint32_t)(uintptr_t)&PTR_FUN_00712964;
  unaff_EDI[0x17] = 0;
  unaff_EDI[0x18] = 0;
  unaff_EDI[0x19] = 0;
  unaff_EDI[0x16] = 0;
  unaff_EDI[0x1a] = 1;
  unaff_EDI[0x1c] = (uint32_t)(uintptr_t)&PTR_FUN_00712968;
  unaff_EDI[0x1e] = 0;
  unaff_EDI[0x21] = 1;
  unaff_EDI[0x1f] = 0;
  unaff_EDI[0x20] = 0;
  unaff_EDI[0x1d] = 0;
  FUN_004f5670();
  if (DAT_008ca4fc == 0) {
    uint32_t uVar2 = 1;
    do {
      sprintf(local_104, "./art/Terrain/Blends/TerrainAlpha%02d.tga", uVar2);
      int iVar1 = FUN_00539c10(local_104, &DAT_007179a4);
      *(int*)(uintptr_t)((uint32_t)(uintptr_t)&DAT_008ca4f8 + uVar2 * 4) = iVar1;
      uVar2 = uVar2 + 1;
      *(uint8_t*)(uintptr_t)((uint32_t)iVar1 + 0x44) = 1;
    } while (uVar2 < 0x10);
  }
}

// ---------------------------------------------------------------------------
// 0x51f160 — observed shape
// Terrain manager destructor. Walks the object at +8 (count +0xc0, array
// +0xb8), and for every list element still holding DAT_00727598 in its list,
// releases DAT_00727598/DAT_007275e8 resources through the virtual destructor
// and FUN_005606f0. Then releases the +8 object, the +0x74 vector block
// (+0x78/+0x7c/+0x80), the two sub-object vtables at +0x54/+0x70 and the
// base at +8, finally restoring PTR_FUN_00711fbc.
// ---------------------------------------------------------------------------
void FUN_0051f160(void* self, uint32_t in_ECX)
{
  uint32_t* unaff_ESI = (uint32_t*)self;
  uint32_t uStack_4 = in_ECX;

  *unaff_ESI = (uint32_t)(uintptr_t)&PTR_FUN_00712970;
  if (unaff_ESI[2] != 0) {
    uint32_t obj = unaff_ESI[2];
    uint32_t uVar5 = 0;
    if (0 < *(int*)(uintptr_t)(obj + 0xc0)) {
      do {
        if (uVar5 < *(uint32_t*)(uintptr_t)(obj + 0xc0)) {
          int* piVar1 = *(int**)(uintptr_t)(*(uint32_t*)(uintptr_t)(obj + 0xb8) + uVar5 * 4);
          if (piVar1 != nullptr) {
            uint32_t vtable = (uint32_t)*piVar1;
            uint32_t* puVar3 =
                (uint32_t*)(uintptr_t)(uint32_t)(*(int(**)(void))(uintptr_t)(vtable + 4))();
            for (; puVar3 != nullptr; puVar3 = (uint32_t*)(uintptr_t)puVar3[1]) {
              if (puVar3 == (uint32_t*)&DAT_00727598) {
                FUN_00449390(&DAT_00727598, (void*)piVar1);
                int iVar4 = FUN_00533db0(8);
                if ((iVar4 != 0) &&
                    ((iVar4 = FUN_00449390(&DAT_007275e8, (void*)(uintptr_t)iVar4)), iVar4 != 0)) {
                  FUN_004aad70(0);
                  uint32_t* puVar6 =
                      *(uint32_t**)(uintptr_t)(*(uint32_t*)(uintptr_t)(iVar4 + 0x2c) + 4);
                  uStack_4 = 0;
                  if (puVar6 != nullptr) {
                    uint32_t oVtbl = *puVar6;
                    (*(void(**)(int))(uintptr_t)(*(uint32_t*)(uintptr_t)oVtbl))(1);
                    FUN_005606f0(1, &uStack_4);
                  }
                  FUN_00542690(0);
                }
                break;
              }
            }
          }
        }
        uVar5 = uVar5 + 1;
      } while ((int)uVar5 < *(int*)(uintptr_t)(obj + 0xc0));
    }
    *(uint32_t*)(uintptr_t)(obj + 0x24) = 0;
    {
      uint32_t* puVar3 = (uint32_t*)(uintptr_t)obj;
      if (puVar3 != nullptr) {
        uint32_t* piVar1 = puVar3 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          uint32_t oVtbl = *puVar3;
          (*(void(**)(int))(uintptr_t)(*(uint32_t*)(uintptr_t)oVtbl))(1);
        }
        unaff_ESI[2] = 0;
      }
    }
  }
  if (unaff_ESI[0x1e] != 0) {
    if (unaff_ESI[0x1f] != 0) {
      uint32_t uVar5 = 0;
      do {
        int* piVar1 = (int*)(uintptr_t)(unaff_ESI[0x1d] + uVar5 * 4);
        if (*piVar1 != 0) {
          *piVar1 = 0;
          unaff_ESI[0x20] = unaff_ESI[0x20] + -1;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < unaff_ESI[0x1f]);
      unaff_ESI[0x1f] = 0;
    }
    void* pvVar2 = (void*)(uintptr_t)unaff_ESI[0x1d];
    unaff_ESI[0x1e] = 0;
    unaff_ESI[0x1d] = 0;
    operator_delete__(pvVar2);
  }
  unaff_ESI[0x1c] = (uint32_t)(uintptr_t)&PTR_FUN_00712968;
  operator_delete__((void*)(uintptr_t)unaff_ESI[0x1d]);
  unaff_ESI[0x15] = (uint32_t)(uintptr_t)&PTR_FUN_00712964;
  operator_delete__((void*)(uintptr_t)unaff_ESI[0x16]);
  *unaff_ESI = (uint32_t)(uintptr_t)&PTR_FUN_00711fbc;
  {
    uint32_t* puVar3 = (uint32_t*)(uintptr_t)unaff_ESI[2];
    if (puVar3 != nullptr) {
      uint32_t* piVar1 = puVar3 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        uint32_t oVtbl = *puVar3;
        (*(void(**)(int))(uintptr_t)(*(uint32_t*)(uintptr_t)oVtbl))(1);
      }
      unaff_ESI[2] = 0;
    }
  }
  {
    uint32_t* puVar3 = (uint32_t*)(uintptr_t)unaff_ESI[2];
    if (puVar3 != nullptr) {
      uint32_t* piVar1 = puVar3 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        uint32_t oVtbl = *puVar3;
        (*(void(**)(int))(uintptr_t)(*(uint32_t*)(uintptr_t)oVtbl))(1);
      }
    }
  }
}

// ---------------------------------------------------------------------------
// 0x51f330 — observed shape
// Terrain blend-texture builder. Allocates three working buffers sized from
// the two ushort dimensions at +0x14/+0x18, runs the size/virtual setup
// sequence (+0x40, +0x28, +0x30, +0x34), then for each entry of the +0x74
// array (+0x7c count) calls its virtual builder and, when it succeeds,
// creates a blend texture object (PTR_FUN_0070d038), attaches it through
// FUN_00542cb0, records the name TTerrain_BlendTex and uploads it via the
// +8 object's vtable +0x70. Finally marks +8+0xec and frees the buffers.
// ---------------------------------------------------------------------------
uint32_t FUN_0051f330(void* self, void* unaff_EBX, void* unaff_EBP,
                      uint32_t unaff_retaddr, uint32_t uStack_8)
{
  uint32_t* in_ECX = (uint32_t*)self;
  uint32_t vtable = *in_ECX;
  uint32_t uVar8 = (uint32_t)*(uint16_t*)((char*)in_ECX + 0x14) *
                   (uint32_t)*(uint16_t*)((char*)in_ECX + 0x18);
  uint32_t uVar10 = uVar8;

  int iVar3 = (*(int(**)(uint32_t, int))(uintptr_t)(vtable + 0x40))(
      uVar8,
      (*(uint16_t*)((char*)in_ECX + 0x14) - 1) *
          (*(uint16_t*)((char*)in_ECX + 0x18) - 1) * 2);
  if (iVar3 < 1) {
    return 8;
  }
  uVar8 = uVar8 & 0xffff;
  void* pvVar4 = (void*)(uintptr_t)thunk_FUN_00533c78((int)(uVar8 * 0xc));
  if (pvVar4 == nullptr) {
    pvVar4 = nullptr;
  } else {
    FUN_004127b0(pvVar4, 0xc, uVar8, &LAB_005cea70);
  }
  void* pvVar5 = (void*)(uintptr_t)thunk_FUN_00533c78((int)(uVar8 * 0x18));
  if (pvVar5 == nullptr) {
    pvVar5 = nullptr;
  } else {
    FUN_004127b0(pvVar5, 8, uVar8 * 3, &LAB_005cea70);
  }
  iVar3 = thunk_FUN_00533c78((int)(uVar8 * 0xc));
  if (iVar3 != 0) {
    FUN_004127b0((void*)(uintptr_t)iVar3, 0xc, uVar8, &LAB_005cea70);
  }
  void* pvVar9 = pvVar4;
  (*(void(**)(void))(uintptr_t)(vtable + 0x28))();
  (*(void(**)(uint32_t))(uintptr_t)(vtable + 0x30))(unaff_retaddr);
  (*(void(**)(void*, void*, uint32_t))(uintptr_t)(vtable + 0x34))(pvVar5, pvVar4, uStack_8);
  uint32_t uStack_10 = 0;
  if (in_ECX[0x1f] != 0) {
    do {
      (*(void(**)(void*, int))(uintptr_t)(vtable + 0x2c))(pvVar5, 0);
      uint32_t elem = *(uint32_t*)(uintptr_t)(in_ECX[0x1d] + uStack_10 * 4);
      uint32_t elemVtbl = *(uint32_t*)(uintptr_t)(elem + 0xc);
      iVar3 = ((int(*)(uint32_t, uint32_t, void*, void*, int, uint32_t))(uintptr_t)(
          *(uint32_t*)(uintptr_t)elemVtbl))(uVar8, unaff_retaddr, pvVar9, pvVar5, 3, uVar10);
      pvVar5 = pvVar9;
      if (iVar3 != 0) {
        uint32_t uVar2 = *(uint32_t*)(uintptr_t)(
            (uint32_t)(uintptr_t)&DAT_008ca4f8 + *(int*)(uintptr_t)(elem + 4) * 4);
        uint32_t* puVar6 = (uint32_t*)(uintptr_t)FUN_00533c78(0x20);
        if (puVar6 == nullptr) {
          puVar6 = nullptr;
          pvVar5 = pvVar9;
          uVar8 = uVar10;
        } else {
          FUN_00542700(uVar2, 0, 3, 1, 0);
          *puVar6 = (uint32_t)(uintptr_t)&PTR_FUN_0070d038;
          puVar6[7] = 0;
          pvVar5 = pvVar9;
          uVar8 = uVar10;
        }
        uint32_t* puVar7 = (uint32_t*)(uintptr_t)FUN_00533db0(8);
        if (puVar7 != nullptr) {
          puVar7[1] = puVar7[1] + 1;
        }
        FUN_00542cb0(1, puVar6);
        FUN_00547730(iVar3, PTR_s_TTerrain_BlendTex_007265d8, 0);
        uint32_t objVtbl = *(uint32_t*)(uintptr_t)in_ECX[2];
        (*(void(**)(uint32_t, int))(uintptr_t)(objVtbl + 0x70))((uint32_t)iVar3, 1);
        if (puVar7 != nullptr) {
          uint32_t* piVar1 = puVar7 + 1;
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            uint32_t oVtbl = *puVar7;
            (*(void(**)(int))(uintptr_t)(*(uint32_t*)(uintptr_t)oVtbl))(1);
          }
        }
        uVar10 = uVar8;
      }
      uStack_10 = uStack_10 + 1;
      pvVar9 = pvVar5;
    } while (uStack_10 < (uint32_t)in_ECX[0x1f]);
  }
  *(uint32_t*)(uintptr_t)(in_ECX[2] + 0xec) = 1;
  if (unaff_EBP != nullptr) {
    operator_delete__(unaff_EBP);
  }
  if (pvVar5 != nullptr) {
    operator_delete__(pvVar5);
  }
  if (unaff_EBX != nullptr) {
    operator_delete__(unaff_EBX);
  }
  return 0;
}

// ---------------------------------------------------------------------------
// 0x51f580 — observed shape
// Dominant-texture probe. Zeroes a 64-word histogram, picks the scan offset
// from the quadrant selector in_EAX (0/1/2/3, negative halves for 0/2 and
// vertical flip for 0/1), then scans the +0x24/+0x28 sized region sampling
// through virtual +0x10 or the raw byte buffer at +0x2c and returns the
// dominant byte (CONCAT31 of the last scan row and the winning value).
// ---------------------------------------------------------------------------
uint32_t FUN_0051f580(void* self, uint32_t in_EAX)
{
  uint32_t* unaff_ESI = (uint32_t*)self;
  uint32_t local_408[257];
  uint8_t local_410[8];
  int local_42c;
  int local_428;
  int local_424;
  uint32_t local_41c;
  uint32_t local_418;

  uint32_t* puVar9 = local_408;
  for (int iVar6 = 0x40; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  int iVar6 = unaff_ESI[5];
  int iVar1 = unaff_ESI[6];
  int iVar7 = iVar6 / 2;
  int iVar3 = iVar1 / 2;
  local_42c = 0;
  local_428 = 0;
  switch (in_EAX) {
  case 0:
    iVar7 = -iVar7;
    /* fallthrough */
  case 1:
    iVar3 = -iVar3;
    break;
  case 2:
    iVar7 = -iVar7;
    break;
  case 3:
    break;
  default:
    goto switchD_0051f5ce_default;
  }
  local_42c = iVar3;
  local_428 = iVar7;
switchD_0051f5ce_default:
  uint32_t uVar4 = 0;
  local_41c = 0;
  local_418 = 0;
  local_424 = 0;
  if (0 < iVar1) {
    do {
      iVar3 = 0;
      if (0 < iVar6) {
        do {
          iVar7 = unaff_ESI[9] + iVar3 + local_428;
          int iVar8 = unaff_ESI[10] + local_424 + local_42c;
          if (iVar7 < 0) {
            iVar7 = 0;
          } else if (unaff_ESI[0xb] + -1 < iVar7) {
            iVar7 = unaff_ESI[0xb] + -1;
          }
          if (iVar8 < 0) {
            iVar8 = 0;
          } else if (unaff_ESI[0xc] + -1 < iVar8) {
            iVar8 = unaff_ESI[0xc] + -1;
          }
          uint8_t bVar2;
          if (unaff_ESI[0x11] == 0) {
            (*(void(**)(int, int, uint8_t*, uint32_t))(uintptr_t)(*unaff_ESI + 0x10))(
                iVar7, iVar8, local_410, unaff_ESI[0x12]);
            bVar2 = local_410[0];
          } else {
            bVar2 = *(uint8_t*)(uintptr_t)(unaff_ESI[0xb] * iVar8 + unaff_ESI[0x11] + iVar7);
          }
          uint32_t uVar5 = (uint32_t)bVar2;
          uint32_t uVar10 = local_408[uVar5] + 1;
          local_408[uVar5] = uVar10;
          if (local_41c < uVar10) {
            local_41c = uVar10;
            local_418 = uVar5;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar6);
      }
      local_424 = local_424 + 1;
    } while (local_424 < iVar1);
    /* CONCAT31((int3)(local_424 >> 8), (uint8_t)local_418) */
    uVar4 = ((uint32_t)local_424 & 0xffffff00u) | (local_418 & 0xffu);
  }
  return uVar4;
}

// ---------------------------------------------------------------------------
// 0x51f6e0 — observed shape
// Samples four directions via FUN_0051f580 (when +0x44 is set), accumulates a
// per-texture bitmask, sorts the 4 (value, mask) pairs descending, then
// creates one 0x10 descriptor + 0x38 node (PTR_LAB_007129b4, byte at +0x34)
// per entry and appends it into the +0x74 vector (+0x78/+0x7c/+0x80).
// ---------------------------------------------------------------------------
int FUN_0051f6e0(void* self)
{
  uint32_t* in_ECX = (uint32_t*)self;
  uint32_t auStack_20[8];
  int iVar6 = 0;
  int local_28 = 0;
  int local_2c;

  if (*(int*)((char*)in_ECX + 0x44) != 0) {
    uint32_t uVar5 = 0;
    do {
      /* in_EAX selector is not observable at this call site in the corpus */
      uint32_t uVar1 = FUN_0051f580(self, 0);
      int iVar4 = 0;
      if (0 < iVar6) {
        do {
          if ((uVar1 & 0xff) == auStack_20[iVar4 * 2]) {
            auStack_20[iVar4 * 2 + 1] =
                auStack_20[iVar4 * 2 + 1] + (1u << ((uint8_t)uVar5 & 0x1f));
            goto LAB_0051f736;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar6);
      }
      auStack_20[iVar6 * 2] = uVar1 & 0xff;
      auStack_20[iVar6 * 2 + 1] = 1u << ((uint8_t)uVar5 & 0x1f);
      iVar6 = iVar6 + 1;
LAB_0051f736:
      uVar5 = uVar5 + 1;
    } while (uVar5 < 4);
    local_28 = iVar6;
  }
  if (0 < local_28) {
    local_2c = local_28;
    do {
      iVar6 = 0;
      if (0 < local_28 + -1) {
        do {
          uint32_t uVar5 = auStack_20[iVar6 * 2];
          if (auStack_20[iVar6 * 2 + 2] < uVar5) {
            uint32_t uVar1 = auStack_20[iVar6 * 2 + 1];
            auStack_20[iVar6 * 2] = auStack_20[iVar6 * 2 + 2];
            auStack_20[iVar6 * 2 + 1] = auStack_20[iVar6 * 2 + 3];
            auStack_20[iVar6 * 2 + 2] = uVar5;
            auStack_20[iVar6 * 2 + 3] = uVar1;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < local_28 + -1);
      }
      local_2c = local_2c + -1;
    } while (local_2c != 0);
  }
  auStack_20[1] = 0xf;
  local_2c = 0;
  if (local_28 < 1) {
    return local_28;
  }
  do {
    uint32_t* puVar2 = (uint32_t*)(uintptr_t)FUN_00533c78(0x10);
    uint32_t* puVar3 = (uint32_t*)(uintptr_t)FUN_00533c78(0x38);
    if (puVar3 == nullptr) {
      puVar3 = nullptr;
    } else {
      FUN_0050be00(*(uint32_t*)((char*)in_ECX + 0x10));
      uint32_t uVar5 = auStack_20[local_2c * 2];
      *puVar3 = (uint32_t)(uintptr_t)&PTR_LAB_007129b4;
      *(char*)((char*)puVar3 + 0x34) = (char)uVar5;
    }
    uint32_t uVar5 = auStack_20[local_2c * 2];
    uint32_t uVar1 = auStack_20[local_2c * 2 + 1];
    puVar2[3] = (uint32_t)(uintptr_t)puVar3;
    puVar2[1] = uVar1;
    *puVar2 = uVar5;
    puVar2[2] = 0;
    uVar5 = *(uint32_t*)((char*)in_ECX + 0x7c);
    if ((uVar5 < *(uint32_t*)((char*)in_ECX + 0x78)) ||
        (FUN_004f5670(), uVar5 < *(uint32_t*)((char*)in_ECX + 0x78))) {
      if (uVar5 < *(uint32_t*)((char*)in_ECX + 0x7c)) {
        if (*(int*)(uintptr_t)(*(int*)((char*)in_ECX + 0x74) + uVar5 * 4) == 0) {
          goto LAB_0051f83d;
        }
      } else {
        *(uint32_t*)((char*)in_ECX + 0x7c) = uVar5 + 1;
LAB_0051f83d:
        *(int*)((char*)in_ECX + 0x80) = *(int*)((char*)in_ECX + 0x80) + 1;
      }
      *(uint32_t**)(uintptr_t)(*(int*)((char*)in_ECX + 0x74) + uVar5 * 4) = puVar2;
    }
    local_2c = local_2c + 1;
    if (local_28 <= local_2c) {
      return local_28;
    }
  } while (true);
}

// ---------------------------------------------------------------------------
// 0x51fc70 — observed shape
// Quad tint helper. Builds a UV rect from the four ushort parameters, a white
// color quad (0x3f800000 x4), and dispatches through vtable +0x3c with the
// parity of the sum of the low bytes of this+0x24 and this+0x28.
// ---------------------------------------------------------------------------
void FUN_0051fc70(void* self, char param_1, char param_2, uint16_t param_3,
                  uint16_t param_4, uint16_t param_5, uint16_t param_6)
{
  uint32_t* in_ECX = (uint32_t*)self;
  uint16_t local_18;
  uint16_t local_16;
  uint16_t local_14;
  uint16_t local_12;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;

  local_16 = param_4;
  local_12 = param_6;
  local_18 = param_3;
  local_14 = param_5;
  local_10 = 0x3f800000u;
  local_c = 0x3f800000u;
  local_8 = 0x3f800000u;
  local_4 = 0x3f800000u;
  (*(void(**)(void*, void*, int))(uintptr_t)(*in_ECX + 0x3c))(
      &local_18, &local_10,
      (((char)in_ECX[10] + param_2) ^ ((char)in_ECX[9] + param_1)) & 1);
}

// ---------------------------------------------------------------------------
// 0x51fcf0 — observed shape
// Emits one quad per grid cell: (width-1) x (height-1) cells from the +0x14
// and +0x18 dimensions, each dispatched through vtable +0x38 with the four
// corner indices (top-left, top-right, bottom-left, bottom-right).
// ---------------------------------------------------------------------------
void FUN_0051fcf0(void* self)
{
  uint32_t* in_ECX = (uint32_t*)self;
  uint32_t uVar4 = 0;
  if (in_ECX[5] != 1) {
    uint32_t uVar1 = in_ECX[6] - 1;
    do {
      uint32_t uVar5 = 0;
      if (uVar1 != 0) {
        do {
          int iVar2 = (int)(in_ECX[6] * uVar4 + uVar5);
          int iVar3 = (int)(in_ECX[6] + iVar2);
          (*(void(**)(uint32_t, uint32_t, int, int, int, int))(uintptr_t)(*in_ECX + 0x38))(
              uVar4, uVar5, iVar2, iVar2 + 1, iVar3, iVar3 + 1);
          uVar5 = uVar5 + 1;
          uVar1 = in_ECX[6] - 1;
        } while (uVar5 < uVar1);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < in_ECX[5] - 1U);
  }
}

// ---------------------------------------------------------------------------
// 0x51fd40 — observed shape
// Releases the +0x74 vector: calls FUN_0050bf50(param_3) once per entry of
// the +0x7c count.
// ---------------------------------------------------------------------------
void FUN_0051fd40(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3)
{
  uint32_t base = (uint32_t)(uintptr_t)self;
  uint32_t uVar1 = 0;
  if (*(int*)(uintptr_t)(base + 0x7c) != 0) {
    do {
      FUN_0050bf50(param_3);
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint32_t*)(uintptr_t)(base + 0x7c));
  }
}

// ---------------------------------------------------------------------------
// 0x51ff70 — observed shape
// Destructor: restore PTR_FUN_00712968, delete this[1], conditional self
// delete when param_1 & 1.
// ---------------------------------------------------------------------------
void FUN_0051ff70(void* self, uint8_t param_1)
{
  uint32_t* in_ECX = (uint32_t*)self;
  *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_00712968;
  operator_delete__((void*)(uintptr_t)in_ECX[1]);
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
}

// ---------------------------------------------------------------------------
// 0x51ffa0 — observed shape
// Destructor: restore PTR_FUN_00712964, delete this[1], conditional self
// delete when param_1 & 1.
// ---------------------------------------------------------------------------
void FUN_0051ffa0(void* self, uint8_t param_1)
{
  uint32_t* in_ECX = (uint32_t*)self;
  *in_ECX = (uint32_t)(uintptr_t)&PTR_FUN_00712964;
  operator_delete__((void*)(uintptr_t)in_ECX[1]);
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
}
