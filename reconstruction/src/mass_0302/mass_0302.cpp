// Reconstruction batch mass_0302
// Sid Meier's Pirates! (2004) — PE32 i386
// Candidate definitions derived from Ghidra 12.2 pseudocode (corpus:
// analysis/pseudocode/functions/0x*.c). Pseudocode is provider output, not
// original source; shapes, offsets and call order are preserved.

#include <cstdint>
#include <cstddef>
#include <cstdlib>
#include <windows.h>

// ---- referenced helpers (addresses as observed in the listings) ----
extern void* FUN_00533c78(uint32_t size);                 // allocator
extern void* FUN_006417d1(void);                          // node ctor
extern void  thunk_FUN_005f2399(int32_t dst, const void* src); // element copy ctor
extern void  FUN_00647df7(int32_t mode);
extern void  FUN_00647bbc(int32_t mode);
extern void  FUN_00647b9b(int32_t mode);
extern void  FUN_00647ca9(int32_t mode);
extern void  FUN_004127b0(void* dst, uint32_t elemSize, uint32_t count, void* ctor);
extern int32_t FUN_00412770(void* p, uint32_t size, uint32_t elemSize, void* dtor);
extern int32_t FUN_006294f9(uint32_t size, void** out);
extern int32_t FUN_00641a6c(uint32_t a, void* b, void* c, int32_t* d, int32_t e);
extern void  FUN_00644fe5(int32_t mode);
extern void  FUN_00646ae9(void);
extern int32_t FUN_00647678(uint32_t column, uint32_t row);
extern int32_t FUN_006480e4(uint32_t* a, int32_t* b, int32_t c);
extern int32_t FUN_0063eb76(int32_t a, int32_t* b, int32_t* c);
extern int32_t FUN_00646c95(int32_t a, int32_t b);
extern int32_t FUN_00646df0(int32_t a, int32_t b);
extern int32_t ftol(void);                                // x87 st0 -> int32
extern void  operator_delete(void* p);

// texture/sprite pipeline helpers
extern int32_t FUN_00649a50(void* self, uint32_t index);
extern int32_t FUN_0064a9aa(void* self, uint32_t index);
extern int32_t FUN_0064b919(void* self, int32_t* param_1, uint32_t param_2, uint32_t param_3);
extern int32_t FUN_0064ba56(void* self, int32_t record);
extern int32_t FUN_0064bdfa(void* self, uint32_t param_1, uint32_t param_2);
extern int32_t FUN_0064bedf(void* self, uint32_t param_1, int32_t* param_2, uint32_t param_3);
extern void  FUN_0064d072(void* self);
extern void  FUN_0064d09b(void* self);

extern int32_t FUN_00643e7a(int32_t record);
extern int32_t FUN_00643f6c(int32_t record);
extern int32_t FUN_00643dfb(uint32_t param_1, uint32_t index, uint32_t sub);
extern int32_t FUN_0063e055(uint32_t a, void* b, void* c, void* d, void* e);
extern int32_t FUN_005f7ad0(uint32_t a, uint32_t b, void* c, void* d);
extern int32_t FUN_0063ea6b(int32_t a, int32_t b);
extern int32_t FUN_0063e97c(uint32_t param_1, uint32_t index, int32_t a, uint32_t b, void* c);
extern int32_t FUN_0063e391(void);
extern int32_t FUN_0060afb7(uint32_t a, uint32_t b, uint32_t c);
extern int32_t FUN_00643bf5(uint32_t param_1, uint32_t index, void* rec);
extern uint64_t FUN_0063dcf6(uint32_t** pp);
extern uint32_t FUN_0063dc77(uint32_t** pp, uint32_t align);
extern void  FUN_0063e2a9(void);
extern int32_t FUN_00645033(void* a, void* b, uint32_t c, uint32_t d, void* e, void** f,
                            uint32_t g);
extern int32_t FUN_006453ee(void* a, void* b, uint32_t c, uint32_t d, void* e, void** f,
                            uint32_t g);
extern int32_t FUN_006457f4(void* a, void* b, uint32_t c, uint32_t d, void* e, void** f,
                            uint32_t g);
extern int32_t FUN_0064668b(uint32_t a, uint32_t b);
extern int32_t FUN_0064680a(uint32_t a, uint32_t b);
extern int32_t FUN_0064369b(uint32_t a, uint32_t b);
extern int32_t FUN_0063d6bb(uint32_t a, uint32_t b, uint32_t c, uint16_t d);
extern int32_t FUN_0063db6f(uint32_t a);
extern int32_t FUN_0063da83(uint32_t a, int32_t b, int32_t c);

extern uint8_t LAB_00641a8c[];
extern uint8_t LAB_00646b1e[];
extern uint8_t LAB_0063e2de[];
extern uint8_t DAT_006eacac[];


// 0x64939b — observed shape: allocate a 0x1c node and a 0x40 element, copy the
// element, then link the node at the tail of self->field_0xfc.
uint32_t FUN_0064939b(void* self, uint32_t param_1, uint32_t param_2)
{
  uint32_t local_8 = 0;
  int32_t iVar1;
  uint32_t* puVar2;

  iVar1 = (int32_t)FUN_00533c78(0x1c);
  if (iVar1 == 0) {
    puVar2 = (uint32_t*)0x0;
  }
  else {
    puVar2 = (uint32_t*)FUN_006417d1();
  }
  if (puVar2 == (uint32_t*)0x0) {
    local_8 = 0x8007000e;
  }
  else {
    iVar1 = (int32_t)FUN_00533c78(0x40);
    if (iVar1 == 0) {
      local_8 = 0x8007000e;
    }
    else {
      thunk_FUN_005f2399(iVar1, (void*)param_2);
      puVar2[1] = param_1;
      *puVar2 = 9;
      puVar2[3] = (uint32_t)iVar1;
      *(uint32_t*)(*(int32_t*)((uint8_t*)self + 0xfc) + 0x18) = (uint32_t)puVar2;
      *(int32_t*)((uint8_t*)self + 0xfc) = (int32_t)puVar2;
      puVar2 = (uint32_t*)0x0;
    }
    if (puVar2 != (uint32_t*)0x0) {
      FUN_00647df7(1);
    }
  }
  return local_8;
}

// 0x649425 — observed shape: allocate a node then a param_3 x 0x40 element
// array copied by stride, link at self->field_0xfc tail.
uint32_t FUN_00649425(void* self, uint32_t param_1, int32_t param_2, int32_t param_3)
{
  int32_t iVar1;
  int32_t iVar2;
  uint32_t* puVar3;
  uint32_t local_c = 0;
  int32_t local_8 = 0;

  iVar1 = param_3;
  iVar2 = (int32_t)FUN_00533c78(0x1c);
  if (iVar2 == 0) {
    puVar3 = (uint32_t*)0x0;
  }
  else {
    puVar3 = (uint32_t*)FUN_006417d1();
  }
  if (puVar3 == (uint32_t*)0x0) {
    return 0x8007000e;
  }
  if (param_3 != 0) {
    local_8 = (int32_t)FUN_00533c78((uint32_t)param_3 << 6);
    if (local_8 == 0) {
      local_c = 0x8007000e;
      goto LAB_006494d6;
    }
    if (param_3 != 0) {
      iVar2 = param_2 - local_8;
      param_2 = param_3;
      param_3 = local_8;
      do {
        thunk_FUN_005f2399(param_3, (const void*)(iVar2 + param_3));
        param_3 = param_3 + 0x40;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
  }
  puVar3[1] = param_1;
  puVar3[3] = (uint32_t)local_8;
  *puVar3 = 10;
  puVar3[2] = (uint32_t)iVar1;
  *(uint32_t*)(*(int32_t*)((uint8_t*)self + 0xfc) + 0x18) = (uint32_t)puVar3;
  *(int32_t*)((uint8_t*)self + 0xfc) = (int32_t)puVar3;
  puVar3 = (uint32_t*)0x0;
LAB_006494d6:
  if (puVar3 != (uint32_t*)0x0) {
    FUN_00647df7(1);
  }
  return local_c;
}

// 0x6494ec — observed shape: same node link, elements copied from an array of
// pointers (param_2[index]) rather than from a contiguous block.
uint32_t FUN_006494ec(void* self, uint32_t param_1, int32_t param_2, uint32_t param_3)
{
  uint32_t uVar1;
  int32_t iVar2;
  uint32_t* puVar3;
  uint32_t uVar4 = 0;
  uint32_t local_c = 0;
  int32_t local_8 = 0;

  uVar1 = param_3;
  iVar2 = (int32_t)FUN_00533c78(0x1c);
  if (iVar2 == 0) {
    puVar3 = (uint32_t*)0x0;
  }
  else {
    puVar3 = (uint32_t*)FUN_006417d1();
  }
  if (puVar3 == (uint32_t*)0x0) {
    return 0x8007000e;
  }
  if ((param_3 == 0) || (local_8 = (int32_t)FUN_00533c78(param_3 << 6), local_8 != 0)) {
    if (param_3 != 0) {
      param_3 = (uint32_t)local_8;
      do {
        thunk_FUN_005f2399((int32_t)param_3, *(void**)((uint8_t*)param_2 + uVar4 * 4));
        param_3 = param_3 + 0x40;
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar1);
    }
    puVar3[1] = param_1;
    puVar3[3] = (uint32_t)local_8;
    *puVar3 = 10;
    puVar3[2] = uVar1;
    *(uint32_t*)(*(int32_t*)((uint8_t*)self + 0xfc) + 0x18) = (uint32_t)puVar3;
    *(int32_t*)((uint8_t*)self + 0xfc) = (int32_t)puVar3;
    puVar3 = (uint32_t*)0x0;
  }
  else {
    local_c = 0x8007000e;
  }
  if (puVar3 != (uint32_t*)0x0) {
    FUN_00647df7(1);
  }
  return local_c;
}

// 0x6495a9 — observed shape: node + 0xc holder; a NUL-terminated string is
// length-scanned, allocated through FUN_006294f9, byte-copied, and attached.
int32_t FUN_006495a9(void* self, uint32_t param_1, char* param_2)
{
  char cVar1;
  int32_t iVar2;
  uint32_t* puVar3;
  char* pcVar4;
  char* pcVar5;
  uint32_t* puVar6;
  uint32_t* puVar7;
  uint32_t uVar8;
  int32_t local_c = 0;
  int32_t* local_8 = (int32_t*)0x0;

  iVar2 = (int32_t)FUN_00533c78(0x1c);
  if (iVar2 == 0) {
    puVar3 = (uint32_t*)0x0;
  }
  else {
    puVar3 = (uint32_t*)FUN_006417d1();
  }
  if (puVar3 == (uint32_t*)0x0) {
LAB_006495dc:
    local_c = -0x7ff8fff2;
LAB_0064969a:
    if (local_8 == (int32_t*)0x0) goto LAB_006496aa;
    (*(int32_t (**)(int32_t*))(*(uint32_t*)local_8 + 8))(local_8);
  }
  else {
    if (param_2 == (char*)0x0) {
LAB_00649634:
      puVar6 = (uint32_t*)FUN_00533c78(0xc);
      if (puVar6 == (uint32_t*)0x0) {
        puVar7 = (uint32_t*)0x0;
      }
      else {
        puVar7 = puVar6 + 1;
        *puVar6 = 1;
        FUN_004127b0(puVar7, 8, 1, &LAB_00641a8c);
      }
      if (puVar7 == (uint32_t*)0x0) goto LAB_006495dc;
      *puVar7 = 4;
      puVar7[1] = (uint32_t)local_8;
      local_8 = (int32_t*)0x0;
      puVar3[5] = (uint32_t)puVar7;
      *puVar3 = 0xb;
      puVar3[1] = param_1;
      puVar3[4] = 1;
      *(uint32_t*)(*(int32_t*)((uint8_t*)self + 0xfc) + 0x18) = (uint32_t)puVar3;
      *(int32_t*)((uint8_t*)self + 0xfc) = (int32_t)puVar3;
      puVar3 = (uint32_t*)0x0;
      goto LAB_0064969a;
    }
    pcVar4 = param_2;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    pcVar4 = pcVar4 + (1 - (int32_t)(param_2 + 1));
    local_c = FUN_006294f9((uint32_t)pcVar4, (void**)&local_8);
    if (-1 < local_c) {
      pcVar5 = (char*)(*(char* (**)(int32_t*))(*(uint32_t*)local_8 + 0xc))(local_8);
      for (uVar8 = (uint32_t)pcVar4 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(uint32_t*)pcVar5 = *(uint32_t*)param_2;
        param_2 = param_2 + 4;
        pcVar5 = pcVar5 + 4;
      }
      for (uVar8 = (uint32_t)pcVar4 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pcVar5 = *param_2;
        param_2 = param_2 + 1;
        pcVar5 = pcVar5 + 1;
      }
      goto LAB_00649634;
    }
  }
  local_8 = (int32_t*)0x0;
LAB_006496aa:
  if (puVar3 != (uint32_t*)0x0) {
    FUN_00647df7(1);
  }
  return local_c;
}

// 0x6496c1 — observed shape: node + 0xc holder; the caller's object is
// AddRef'd (vtable +4), tagged 5, and linked with node tag 0xc.
uint32_t FUN_006496c1(void* self, uint32_t param_1, int32_t* param_2)
{
  int32_t iVar1;
  uint32_t* puVar2;
  uint32_t* puVar3;
  uint32_t* puVar4 = (uint32_t*)0x0;
  uint32_t local_8 = 0;

  iVar1 = (int32_t)FUN_00533c78(0x1c);
  if (iVar1 == 0) {
    puVar2 = (uint32_t*)0x0;
  }
  else {
    puVar2 = (uint32_t*)FUN_006417d1();
  }
  if (puVar2 == (uint32_t*)0x0) {
    local_8 = 0x8007000e;
  }
  else {
    puVar3 = (uint32_t*)FUN_00533c78(0xc);
    if (puVar3 != (uint32_t*)0x0) {
      puVar4 = puVar3 + 1;
      *puVar3 = 1;
      FUN_004127b0(puVar4, 8, 1, &LAB_00641a8c);
    }
    if (puVar4 == (uint32_t*)0x0) {
      local_8 = 0x8007000e;
      FUN_00647df7(1);
    }
    else {
      if (param_2 != (int32_t*)0x0) {
        (*(int32_t (**)(int32_t*))(*(uint32_t*)param_2 + 4))(param_2);
      }
      puVar4[1] = (uint32_t)param_2;
      *puVar4 = 5;
      puVar2[1] = param_1;
      *puVar2 = 0xc;
      puVar2[4] = 1;
      puVar2[5] = (uint32_t)puVar4;
      *(uint32_t*)(*(int32_t*)((uint8_t*)self + 0xfc) + 0x18) = (uint32_t)puVar2;
      *(int32_t*)((uint8_t*)self + 0xfc) = (int32_t)puVar2;
    }
  }
  return local_8;
}

// 0x649774 — observed shape: node + 0xc holder; caller object AddRef'd,
// holder tagged 0xf, node tagged 0xd.
uint32_t FUN_00649774(void* self, uint32_t param_1, int32_t* param_2)
{
  int32_t iVar1;
  uint32_t* puVar2;
  uint32_t* puVar3;
  uint32_t* puVar4 = (uint32_t*)0x0;
  uint32_t local_8 = 0;

  iVar1 = (int32_t)FUN_00533c78(0x1c);
  if (iVar1 == 0) {
    puVar2 = (uint32_t*)0x0;
  }
  else {
    puVar2 = (uint32_t*)FUN_006417d1();
  }
  if (puVar2 == (uint32_t*)0x0) {
    local_8 = 0x8007000e;
  }
  else {
    puVar3 = (uint32_t*)FUN_00533c78(0xc);
    if (puVar3 != (uint32_t*)0x0) {
      puVar4 = puVar3 + 1;
      *puVar3 = 1;
      FUN_004127b0(puVar4, 8, 1, &LAB_00641a8c);
    }
    if (puVar4 == (uint32_t*)0x0) {
      local_8 = 0x8007000e;
      FUN_00647df7(1);
    }
    else {
      if (param_2 != (int32_t*)0x0) {
        (*(int32_t (**)(int32_t*))(*(uint32_t*)param_2 + 4))(param_2);
      }
      puVar4[1] = (uint32_t)param_2;
      *puVar4 = 0xf;
      puVar2[1] = param_1;
      *puVar2 = 0xd;
      puVar2[4] = 1;
      puVar2[5] = (uint32_t)puVar4;
      *(uint32_t*)(*(int32_t*)((uint8_t*)self + 0xfc) + 0x18) = (uint32_t)puVar2;
      *(int32_t*)((uint8_t*)self + 0xfc) = (int32_t)puVar2;
    }
  }
  return local_8;
}

// 0x649827 — observed shape: node + 0xc holder; caller object AddRef'd,
// holder tagged 0x10, node tagged 0xe.
uint32_t FUN_00649827(void* self, uint32_t param_1, int32_t* param_2)
{
  int32_t iVar1;
  uint32_t* puVar2;
  uint32_t* puVar3;
  uint32_t* puVar4 = (uint32_t*)0x0;
  uint32_t local_8 = 0;

  iVar1 = (int32_t)FUN_00533c78(0x1c);
  if (iVar1 == 0) {
    puVar2 = (uint32_t*)0x0;
  }
  else {
    puVar2 = (uint32_t*)FUN_006417d1();
  }
  if (puVar2 == (uint32_t*)0x0) {
    local_8 = 0x8007000e;
  }
  else {
    puVar3 = (uint32_t*)FUN_00533c78(0xc);
    if (puVar3 != (uint32_t*)0x0) {
      puVar4 = puVar3 + 1;
      *puVar3 = 1;
      FUN_004127b0(puVar4, 8, 1, &LAB_00641a8c);
    }
    if (puVar4 == (uint32_t*)0x0) {
      local_8 = 0x8007000e;
      FUN_00647df7(1);
    }
    else {
      if (param_2 != (int32_t*)0x0) {
        (*(int32_t (**)(int32_t*))(*(uint32_t*)param_2 + 4))(param_2);
      }
      puVar4[1] = (uint32_t)param_2;
      *puVar4 = 0x10;
      puVar2[1] = param_1;
      *puVar2 = 0xe;
      puVar2[4] = 1;
      puVar2[5] = (uint32_t)puVar4;
      *(uint32_t*)(*(int32_t*)((uint8_t*)self + 0xfc) + 0x18) = (uint32_t)puVar2;
      *(int32_t*)((uint8_t*)self + 0xfc) = (int32_t)puVar2;
    }
  }
  return local_8;
}

// 0x6498da — observed shape: clone/copy path into a fresh node; optional
// param_2 buffer of param_3 bytes is copied first, then an 8-byte-element
// array is allocated and filled via FUN_00641a6c.
int32_t FUN_006498da(void* self, uint32_t param_1, uint32_t* param_2, uint32_t param_3)
{
  uint32_t uVar1;
  int32_t iVar2;
  uint32_t* puVar3;
  int32_t* piVar4;
  uint32_t uVar5;
  uint32_t* puVar6;
  int32_t local_10;
  uint32_t* local_c;
  int32_t* local_8;

  local_8 = (int32_t*)0x0;
  local_c = (uint32_t*)0x0;
  iVar2 = (int32_t)FUN_00533c78(0x1c);
  if (iVar2 == 0) {
    puVar3 = (uint32_t*)0x0;
  }
  else {
    puVar3 = (uint32_t*)FUN_006417d1();
  }
  if (puVar3 == (uint32_t*)0x0) {
    return -0x7ff8fff2;
  }
  if (param_3 == 0) {
LAB_00649952:
    uVar5 = ~param_1;
    uVar1 = *(uint32_t*)((uintptr_t)uVar5 + 4);
    local_10 = 0;
    param_2 = (uint32_t*)FUN_00641a6c(uVar1, local_c, 0, &local_10,
                                      *(int32_t*)((uintptr_t)uVar5 + 8) != -1);
    iVar2 = local_10;
    if ((int32_t)param_2 < 0) goto LAB_00649a1d;
    piVar4 = (int32_t*)FUN_00533c78((uint32_t)local_10 * 8 + 4);
    if (piVar4 == (int32_t*)0x0) {
      local_8 = (int32_t*)0x0;
    }
    else {
      *piVar4 = iVar2;
      FUN_004127b0(piVar4 + 1, 8, (uint32_t)iVar2, &LAB_00641a8c);
      local_8 = piVar4 + 1;
    }
    puVar6 = local_c;
    if (local_8 != (int32_t*)0x0) {
      param_2 = (uint32_t*)FUN_00641a6c(uVar1, local_c, local_8, 0,
                                        *(int32_t*)((uintptr_t)uVar5 + 8) != -1);
      if (-1 < (int32_t)param_2) {
        puVar3[1] = param_1;
        puVar3[2] = param_3;
        *puVar3 = 0;
        puVar3[3] = (uint32_t)puVar6;
        puVar3[4] = (uint32_t)local_10;
        puVar3[5] = (uint32_t)local_8;
        *(uint32_t*)(*(int32_t*)((uint8_t*)self + 0xfc) + 0x18) = (uint32_t)puVar3;
        *(int32_t*)((uint8_t*)self + 0xfc) = (int32_t)puVar3;
        local_c = (uint32_t*)0x0;
        local_8 = (int32_t*)0x0;
        puVar3 = (uint32_t*)0x0;
      }
      goto LAB_00649a1d;
    }
  }
  else {
    local_c = (uint32_t*)FUN_00533c78(param_3);
    if (local_c != (uint32_t*)0x0) {
      puVar6 = local_c;
      for (uVar5 = param_3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar6 = *param_2;
        param_2 = param_2 + 1;
        puVar6 = puVar6 + 1;
      }
      for (uVar5 = param_3 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(uint8_t*)puVar6 = *(uint8_t*)param_2;
        param_2 = (uint32_t*)((uint8_t*)param_2 + 1);
        puVar6 = (uint32_t*)((uint8_t*)puVar6 + 1);
      }
      goto LAB_00649952;
    }
  }
  param_2 = (uint32_t*)0x8007000e;
LAB_00649a1d:
  if (local_c != (uint32_t*)0x0) {
    operator_delete(local_c);
  }
  if (local_8 != (int32_t*)0x0) {
    FUN_00644fe5(3);
  }
  if (puVar3 != (uint32_t*)0x0) {
    FUN_00647df7(1);
  }
  return (int32_t)param_2;
}

// 0x64b919 — observed shape: nested 0x64-record walk emitting sprite/region
// draw calls through vtable +0x114 / +0x104; returns the first negative HRESULT.
int32_t FUN_0064b919(void* self, int32_t* param_1, uint32_t param_2, uint32_t param_3)
{
  int32_t iVar1;
  uint16_t* puVar2;
  int32_t* piVar3;
  int32_t* piVar4;
  int32_t* piVar5;
  int32_t local_14;
  uint32_t local_c;
  uint32_t local_8;

  uint8_t* base = (uint8_t*)self;
  do {
    if (param_3 <= param_2) {
      return 0;
    }
    puVar2 = (uint16_t*)(*(int32_t*)((uint8_t*)(uintptr_t)param_2 + 0x48) + *param_1);
    local_c = (uint32_t)*(uint16_t*)((uint8_t*)(uintptr_t)param_2 + 0x54);
    piVar5 = (int32_t*)(((uint32_t)puVar2[1] + (uint32_t)*puVar2) * 100 + -100 +
                        *(int32_t*)(base + 0x2c));
    piVar3 = piVar5 + (uint32_t)*(uint16_t*)((uint8_t*)(uintptr_t)param_2 + 0x56) * 0x19;
    for (; piVar5 < piVar3; piVar5 = piVar5 + 0x19) {
      local_8 = 0;
      piVar4 = (int32_t*)piVar5[1];
      if (*(int16_t*)((uint8_t*)piVar5 + 0x36) != 0) {
        do {
          if (*(char*)((uint8_t*)piVar4 + 0x5b) == '\x03') {
            if (*piVar4 != 0) {
              iVar1 = FUN_00647678((int32_t)(((uintptr_t)piVar5 -
                                              *(int32_t*)(base + 0x2c)) / 100) & 0xffff,
                                   local_8);
              if (iVar1 < 0) {
                return iVar1;
              }
              *piVar4 = piVar4[1];
            }
            local_14 = (*(int32_t (**)(void*, uint32_t, uint32_t, uint32_t))
                        (*(uint32_t*)(*(int32_t*)(base + 8)) + 0x114))
                         (*(void**)(base + 8), local_c, (uint32_t)piVar4[0x16] & 0xffffff,
                          *(uint32_t*)(piVar4[0x12] + *piVar5));
          }
          else if (*(char*)((uint8_t*)piVar4 + 0x5b) == '\t') {
            iVar1 = *(int32_t*)(*(int32_t*)(*(int32_t*)(base + 0xb0) + piVar4[7] * 4) + 0x40);
            if (iVar1 == 0) {
              iVar1 = *(int32_t*)piVar4[2];
            }
            else {
              iVar1 = *(int32_t*)(*(int32_t*)(iVar1 + 8) + *(int32_t*)piVar4[2] * 4);
            }
            local_14 = (*(int32_t (**)(uint32_t, uint32_t, uint32_t))
                        (*(uint32_t*)(*(int32_t*)(base + 8)) + 0x104))
                         (*(uint32_t*)(base + 8), local_c,
                          *(uint32_t*)(*(int32_t*)(base + 0x18) + 4 + iVar1 * 0x18));
          }
          if (local_14 < 0) {
            return local_14;
          }
          local_8 = local_8 + 1;
          piVar4 = piVar4 + 0x19;
        } while (local_8 < *(uint16_t*)((uint8_t*)piVar5 + 0x36));
      }
      local_c = local_c + 1;
    }
    param_2 = param_2 + 100;
  } while (true);
}

// 0x64bdfa — observed shape: dispatch one 0x64 map record; optional
// pre-checks FUN_00646c95/FUN_00646df0, then either the single-record routine
// or a loop over the record's 0x36 sub-count.
int32_t FUN_0064bdfa(void* self, uint32_t param_1, uint32_t param_2)
{
  int32_t iVar1;
  int32_t iVar2;
  uint32_t uVar3;
  int32_t iVar4;

  uint8_t* base = (uint8_t*)self;
  uVar3 = param_1 & 0xffff;
  iVar4 = (int32_t)uVar3 * 100 + *(int32_t*)(base + 0x2c);
  if (((*(uint8_t*)(base + 0x118) & 8) == 0) ||
     ((iVar1 = FUN_00646c95(*(int16_t*)((uint8_t*)(uintptr_t)iVar4 + 0x18) != -1,
                            iVar4 + 0x1c), -1 < iVar1 &&
      (iVar1 = FUN_00646df0(*(int16_t*)((uint8_t*)(uintptr_t)iVar4 + 0x1a) != -1,
                            iVar4 + 0x24), -1 < iVar1)))) {
    if ((*(uint8_t*)((uint8_t*)(uintptr_t)iVar4 + 8) & 8) != 0) {
      if (*(int16_t*)((uint8_t*)(uintptr_t)iVar4 + 0x18) == -1) {
        iVar1 = FUN_0064a9aa(self, uVar3);
      }
      else {
        iVar1 = FUN_00649a50(self, uVar3);
      }
      if (iVar1 < 0) {
        return iVar1;
      }
    }
    if (*(int32_t*)(base + 0x3c) == 4) {
      if ((*(uint8_t*)((uint8_t*)(uintptr_t)iVar4 + 8) & 1) != 0) {
        iVar4 = FUN_0064ba56(self, iVar4);
        return iVar4;
      }
      iVar1 = 0;
      if (*(int16_t*)((uint8_t*)(uintptr_t)iVar4 + 0x36) != 0) {
        do {
          iVar2 = FUN_0064bedf(self, param_1, (int32_t*)(uintptr_t)iVar1, param_2);
          if (iVar2 < 0) {
            return iVar2;
          }
          iVar1 = iVar1 + 1;
        } while ((uint16_t)iVar1 < *(uint16_t*)((uint8_t*)(uintptr_t)iVar4 + 0x36));
      }
    }
    else {
      iVar1 = 0;
      if (*(int16_t*)((uint8_t*)(uintptr_t)iVar4 + 0x36) != 0) {
        do {
          iVar2 = FUN_0064bedf(self, param_1, (int32_t*)(uintptr_t)iVar1, param_2);
          if ((iVar2 < 0) && (*(int32_t*)(base + 0x3c) != 1)) {
            return iVar2;
          }
          iVar1 = iVar1 + 1;
        } while ((uint16_t)iVar1 < *(uint16_t*)((uint8_t*)(uintptr_t)iVar4 + 0x36));
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}

// 0x64ba56 — observed shape: single-record draw path. Emits either the
// 0x170/0x1ac or 0x178/0x1b4 flavour depending on bit 30 of record[2], then
// walks boundary lists at offsets 0x4e/0x54/0x5a/0x60 (100-byte stride) and
// finally dispatches the sub-list through FUN_0064b919.
// Ghidra elided the arguments of the paired vtable calls marked "elided"; the
// variadic casts below preserve the observed receiver-only call.
int32_t FUN_0064ba56(void* self, int32_t* param_1)
{
  int32_t iVar1;
  int32_t iVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  int32_t* piVar5;
  uint32_t* puVar6;
  int32_t* piVar7;
  uint32_t* puVar8;
  int32_t local_10;
  int32_t* local_c;
  int32_t* local_8;

  uint8_t* base = (uint8_t*)self;
  void* savedSelf = self;
  uint8_t* vtObj = *(uint8_t**)(base + 8);
  uint8_t* vt = *(uint8_t**)vtObj;

  piVar7 = (int32_t*)param_1[1];
  iVar1 = param_1[2] << 0x1e;
  if (*piVar7 == 0) {
    iVar2 = *(int32_t*)(*(int32_t*)(*(int32_t*)(base + 0xb0) + piVar7[7] * 4) + 0x40);
    if (iVar1 < 0) {
      if (iVar2 == 0) {
        iVar2 = *(int32_t*)piVar7[2];
      }
      else {
        iVar2 = *(int32_t*)(*(int32_t*)(iVar2 + 8) + *(int32_t*)piVar7[2] * 4);
      }
      iVar2 = (*(int32_t (**)(void*, uint32_t))(vt + 0x170))
               (vtObj, *(uint32_t*)(*(int32_t*)(base + 0x18) + 4 + iVar2 * 0x18));
    }
    else {
      if (iVar2 == 0) {
        iVar2 = *(int32_t*)piVar7[2];
      }
      else {
        iVar2 = *(int32_t*)(*(int32_t*)(iVar2 + 8) + *(int32_t*)piVar7[2] * 4);
      }
      iVar2 = (*(int32_t (**)(void*, uint32_t))(vt + 0x1ac))
               (vtObj, *(uint32_t*)(*(int32_t*)(base + 0x18) + 4 + iVar2 * 0x18));
    }
    if (-1 < iVar2) {
      local_c = piVar7 + 0x19;
      if ((*(uint8_t*)((uint8_t*)param_1 + 8) & 4) != 0) {
        iVar2 = FUN_0064680a((int32_t)(((uintptr_t)param_1 -
                                         *(int32_t*)(base + 0x2c)) / 100) & 0xffff, 1);
        if (iVar2 < 0) {
          return iVar2;
        }
        if ((*(uint8_t*)((uint8_t*)param_1 + 8) & 0x10) != 0) {
          if (((int16_t)param_1[0x14] != 0) &&
             ((int16_t)param_1[0x13] == *(int16_t*)((uint8_t*)param_1 + 0x4e))) {
            if (iVar1 < 0) {
              (*(int32_t (**)(void*, ...))(vt + 0x178))(vtObj);
            }
            else {
              (*(int32_t (**)(void*, uint32_t, uint32_t, int32_t))(vt + 0x1b4))
                (vtObj, 0, (uint32_t)param_1[0x10] + (uint32_t)*param_1,
                 (int16_t)param_1[0x14]);
            }
          }
          if ((*(int16_t*)((uint8_t*)param_1 + 0x56) != 0) &&
             (*(int16_t*)((uint8_t*)param_1 + 0x52) == (int16_t)param_1[0x15])) {
            if (iVar1 < 0) {
              (*(int32_t (**)(void*, ...))(vt + 0x180))(vtObj);
            }
            else {
              (*(int32_t (**)(void*, uint32_t, uint32_t, int16_t))(vt + 0x1bc))
                (vtObj, 0, (uint32_t)param_1[0x11] + (uint32_t)*param_1,
                 *(int16_t*)((uint8_t*)param_1 + 0x56));
            }
          }
          if (((int16_t)param_1[0x17] != 0) &&
             ((int16_t)param_1[0x16] == *(int16_t*)((uint8_t*)param_1 + 0x5a))) {
            if (iVar1 < 0) {
              (*(int32_t (**)(void*, ...))(vt + 0x188))(vtObj);
            }
            else {
              (*(int32_t (**)(void*, uint32_t, uint32_t, int16_t))(vt + 0x1c4))
                (vtObj, 0, (uint32_t)param_1[0x12] + (uint32_t)*param_1,
                 (int16_t)param_1[0x17]);
            }
          }
        }
        local_c = piVar7 + 0x32;
      }
      piVar5 = (int32_t*)((uint32_t)*(uint16_t*)((uint8_t*)param_1 + 0x4e) * 100 + param_1[1]);
      piVar7 = local_c;
      local_8 = piVar5;
      if (local_c < piVar5) {
        do {
          piVar7 = local_c;
          if (*local_c != 0) {
            *local_c = local_c[1];
            if ((*(uint8_t*)((uint8_t*)local_c + 0x30) & 0x10) == 0) {
              FUN_00645033(local_c + 2, (uint32_t*)(local_c[0x12] + *param_1),
                           *(uint16_t*)((uint8_t*)local_c + 0x56), (uint32_t)local_c[0xf],
                           *(void**)(local_c[0xd] + 0x10), (void**)&local_c,
                           *(uint32_t*)(*(int32_t*)(*(int32_t*)(base + 0xb0) +
                                                    local_c[7] * 4) + 0x4c));
              piVar5 = local_8;
            }
            else {
              uVar4 = (uint32_t)local_c[0x18];
              puVar6 = (uint32_t*)local_c[0x17];
              puVar8 = (uint32_t*)(local_c[0x12] + *param_1);
              for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
                *puVar8 = *puVar6;
                puVar6 = puVar6 + 1;
                puVar8 = puVar8 + 1;
              }
              for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
                *(uint8_t*)puVar8 = *(uint8_t*)puVar6;
                puVar6 = (uint32_t*)((uint8_t*)puVar6 + 1);
                puVar8 = (uint32_t*)((uint8_t*)puVar8 + 1);
              }
              self = savedSelf;
            }
          }
          piVar7 = piVar7 + 0x19;
          local_c = piVar7;
        } while (piVar7 < piVar5);
        if (iVar1 < 0) {
          iVar2 = (*(int32_t (**)(void*, ...))(vt + 0x178))(vtObj);
        }
        else {
          iVar2 = (*(int32_t (**)(void*, uint32_t, uint32_t, int16_t))(vt + 0x1b4))
                    (vtObj, 0, (uint32_t)param_1[0x10] + (uint32_t)*param_1,
                     (int16_t)param_1[0x14]);
        }
        if (iVar2 < 0) {
          return iVar2;
        }
      }
      if (*(int16_t*)((uint8_t*)param_1 + 0x4e) != *(int16_t*)((uint8_t*)param_1 + 0x36)) {
        piVar5 = (int32_t*)((uint32_t)*(uint16_t*)((uint8_t*)param_1 + 0x54) * 100 + param_1[1]);
        local_8 = piVar5;
        if (piVar7 < piVar5) {
          do {
            if (*piVar7 != 0) {
              *piVar7 = piVar7[1];
              FUN_006453ee(piVar7 + 2, (uint32_t*)(piVar7[0x12] + *param_1),
                           *(uint16_t*)((uint8_t*)piVar7 + 0x56), (uint32_t)piVar7[0xf],
                           *(void**)(piVar7[0xd] + 0x10), (void**)&local_10,
                           *(uint32_t*)(*(int32_t*)(*(int32_t*)(base + 0xb0) +
                                                    piVar7[7] * 4) + 0x4c));
              piVar5 = local_8;
            }
            piVar7 = piVar7 + 0x19;
          } while (piVar7 < piVar5);
          if (iVar1 < 0) {
            iVar2 = (*(int32_t (**)(void*, ...))(vt + 0x180))(vtObj);
          }
          else {
            iVar2 = (*(int32_t (**)(void*, uint32_t, uint32_t, uint32_t))(vt + 0x1bc))
                      (vtObj, 0, (uint32_t)param_1[0x11] + (uint32_t)*param_1,
                       *(uint16_t*)((uint8_t*)param_1 + 0x56));
          }
          if (iVar2 < 0) {
            return iVar2;
          }
        }
        piVar5 = (int32_t*)((uint32_t)*(uint16_t*)((uint8_t*)param_1 + 0x5a) * 100 + param_1[1]);
        local_8 = piVar5;
        if (piVar7 < piVar5) {
          do {
            if (*piVar7 != 0) {
              *piVar7 = piVar7[1];
              FUN_006457f4(piVar7 + 2, (uint32_t*)(piVar7[0x12] + *param_1),
                           *(uint16_t*)((uint8_t*)piVar7 + 0x56), (uint32_t)piVar7[0xf],
                           *(void**)(piVar7[0xd] + 0x10), (void**)&local_10,
                           *(uint32_t*)(*(int32_t*)(*(int32_t*)(base + 0xb0) +
                                                    piVar7[7] * 4) + 0x4c));
              piVar5 = local_8;
            }
            piVar7 = piVar7 + 0x19;
          } while (piVar7 < piVar5);
          if (iVar1 < 0) {
            iVar1 = (*(int32_t (**)(void*, ...))(vt + 0x188))(vtObj);
          }
          else {
            iVar1 = (*(int32_t (**)(void*, uint32_t, uint32_t, int16_t))(vt + 0x1c4))
                      (vtObj, 0, (uint32_t)param_1[0x12] + (uint32_t)*param_1,
                       (int16_t)param_1[0x17]);
          }
          if (iVar1 < 0) {
            return iVar1;
          }
        }
        piVar5 = (int32_t*)((uint32_t)*(uint16_t*)((uint8_t*)param_1 + 0x60) * 100 + param_1[1]);
        if (piVar7 < piVar5) {
          iVar1 = FUN_0064b919(self, param_1, (uint32_t)(uintptr_t)piVar7,
                               (uint32_t)(uintptr_t)piVar5);
          return iVar1;
        }
      }
      iVar2 = 0;
    }
  }
  else {
    iVar2 = FUN_0064bedf(self, ((int32_t)(intptr_t)param_1 - *(int32_t*)(base + 0x2c)) / 100,
                         0, 0xffff);
  }
  return iVar2;
}

// 0x64ceb8 — observed shape: flush one pending record; tag byte at param_2[0x16]
// high byte selects 0xf (delegate to FUN_0064b919), 0xc/0xd, and the low
// 24 bits (0xc000000/0xd000000/0xc010000/0xd010000/0xc020000/0xd020000)
// select the blit routine FUN_00645033/FUN_006453ee/FUN_006457f4 followed by
// vtable +0x178/+0x1b4, +0x180/+0x1bc, +0x188/+0x1c4 respectively.
uint32_t FUN_0064ceb8(void* self, int32_t* param_1, uint32_t* param_2)
{
  uint16_t* puVar1;
  int32_t iVar2;
  uint8_t* piVar3;
  bool bVar4 = false;
  uint32_t* puVar5;
  uint32_t* puVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  uint32_t* puVar10;
  uint32_t* puVar11;

  uint8_t* base = (uint8_t*)self;
  uint8_t* vtObj = *(uint8_t**)(base + 8);
  uint8_t* vt = *(uint8_t**)vtObj;
  uint32_t* rec = param_2;

  puVar5 = param_2;
  uVar9 = param_2[0x16];
  puVar6 = (uint32_t*)(param_2[0x12] + *param_1);
  *param_2 = param_2[1];
  uVar8 = uVar9 >> 0x18;
  if (uVar8 == 0xc) {
    bVar4 = true;
  }
  else if (uVar8 != 0xd) {
    if (uVar8 == 0xf) {
      puVar10 = param_2 + 0x19;
      rec = puVar6;
      uVar7 = FUN_0064b919(self, param_1, (uint32_t)(uintptr_t)puVar5,
                           (uint32_t)(uintptr_t)puVar10);
      return uVar7;
    }
    return 0x80004005;
  }
  param_1 = *(int32_t**)(param_2[0xd] + 0x10);
  uVar7 = *(uint32_t*)(*(int32_t*)(*(int32_t*)(base + 0xb0) + param_2[7] * 4) + 0x4c);
  if (uVar9 == 0xc000000) {
LAB_0064cff5:
    if ((*(uint8_t*)((uint8_t*)rec + 0x30) & 0x10) == 0) {
      puVar1 = (uint16_t*)((uint8_t*)rec + 0x56);
      puVar10 = rec + 0xf;
      puVar11 = rec + 2;
      rec = puVar6;
      FUN_00645033(puVar11, puVar6, *puVar1, *puVar10, param_1, (void**)&param_1, uVar7);
      uVar9 = (uint32_t)(uintptr_t)param_1;
    }
    else {
      uVar9 = rec[0x18];
      puVar10 = (uint32_t*)rec[0x17];
      puVar11 = puVar6;
      for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *puVar11 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar11 = puVar11 + 1;
      }
      for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(uint8_t*)puVar11 = *(uint8_t*)puVar10;
        puVar10 = (uint32_t*)((uint8_t*)puVar10 + 1);
        puVar11 = (uint32_t*)((uint8_t*)puVar11 + 1);
      }
      uVar9 = (uint32_t)*(uint16_t*)((uint8_t*)rec + 0x56);
      rec = puVar6;
    }
    if (bVar4) {
      uVar7 = (*(uint32_t (**)(void*, uint16_t, uint32_t*, uint32_t))(vt + 0x178))
                (vtObj, *(uint16_t*)((uint8_t*)puVar5 + 0x54), rec, uVar9);
    }
    else {
      uVar7 = (*(uint32_t (**)(void*, uint16_t, uint32_t*, uint16_t))(vt + 0x1b4))
                (vtObj, *(uint16_t*)((uint8_t*)puVar5 + 0x54), rec,
                 *(uint16_t*)((uint8_t*)puVar5 + 0x56));
    }
  }
  else {
    if (uVar9 == 0xc010000) {
LAB_0064cfb0:
      puVar1 = (uint16_t*)((uint8_t*)rec + 0x56);
      puVar10 = rec + 0xf;
      puVar11 = rec + 2;
      rec = puVar6;
      FUN_006457f4(puVar11, puVar6, *puVar1, *puVar10, param_1, (void**)&param_1, uVar7);
      piVar3 = *(uint8_t**)(base + 8);
      (void)piVar3;
      iVar2 = *(int32_t*)vtObj;
      (void)iVar2;
      if (bVar4) {
        uVar7 = (*(uint32_t (**)(void*, uint16_t, uint32_t*, uint32_t))(*(uint8_t**)vtObj + 0x188))
                  (vtObj, *(uint16_t*)((uint8_t*)puVar5 + 0x54), rec,
                   *(uint16_t*)((uint8_t*)puVar5 + 0x56));
        return uVar7;
      }
      uVar7 = (*(uint32_t (**)(void*, uint16_t, uint32_t*, uint16_t))(vt + 0x1c4))
                (vtObj, *(uint16_t*)((uint8_t*)puVar5 + 0x54), rec,
                 *(uint16_t*)((uint8_t*)puVar5 + 0x56));
      return uVar7;
    }
    if (uVar9 != 0xc020000) {
      if (uVar9 == 0xd000000) goto LAB_0064cff5;
      if (uVar9 == 0xd010000) goto LAB_0064cfb0;
      if (uVar9 != 0xd020000) {
        return 0x80004005;
      }
    }
    puVar1 = (uint16_t*)((uint8_t*)rec + 0x56);
    puVar10 = rec + 0xf;
    puVar11 = rec + 2;
    rec = puVar6;
    FUN_006453ee(puVar11, puVar6, *puVar1, *puVar10, param_1, (void**)&param_1, uVar7);
    iVar2 = *(int32_t*)vtObj;
    (void)iVar2;
    if (bVar4) {
      uVar7 = (*(uint32_t (**)(void*, ...))(*(uint8_t**)vtObj + 0x180))(vtObj);
    }
    else {
      uVar7 = (*(uint32_t (**)(void*, uint16_t, uint32_t*, uint16_t))(vt + 0x1bc))
                (vtObj, *(uint16_t*)((uint8_t*)puVar5 + 0x54), rec,
                 *(uint16_t*)((uint8_t*)puVar5 + 0x56));
    }
  }
  return uVar7;
}

// 0x64d072 — observed shape: free field 0, release field 1 through mode 3.
void FUN_0064d072(void* self)
{
  uint32_t* selfv = (uint32_t*)self;

  if ((void*)selfv[0] != (void*)0x0) {
    operator_delete((void*)selfv[0]);
    selfv[0] = 0;
  }
  if (selfv[1] != 0) {
    FUN_00647bbc(3);
    selfv[1] = 0;
  }
}

// 0x64d09b — observed shape: release 0x30/0x38, delete 0x40, Release 0x88,
// then two iterations over {0x8c,0x90} releasing the +8 and +0 objects; final
// FUN_00646ae9.
void FUN_0064d09b(void* self)
{
  int32_t* piVar1;
  int32_t* piVar2;
  int32_t local_8;
  uint8_t* base = (uint8_t*)self;

  if (*(int32_t*)(base + 0x30) != 0) {
    FUN_00647b9b(1);
    *(uint32_t*)(base + 0x30) = 0;
  }
  if (*(int32_t*)(base + 0x38) != 0) {
    FUN_00647ca9(3);
    *(uint32_t*)(base + 0x38) = 0;
  }
  if (*(void**)(base + 0x40) != (void*)0x0) {
    operator_delete(*(void**)(base + 0x40));
    *(uint32_t*)(base + 0x40) = 0;
  }
  piVar2 = *(int32_t**)(base + 0x88);
  if (piVar2 != (int32_t*)0x0) {
    (*(int32_t (**)(int32_t*))(*(uint32_t*)piVar2 + 8))(piVar2);
    *(uint32_t*)(base + 0x88) = 0;
  }
  piVar2 = (int32_t*)(base + 0x8c);
  local_8 = 2;
  do {
    piVar1 = (int32_t*)piVar2[2];
    if (piVar1 != (int32_t*)0x0) {
      (*(int32_t (**)(int32_t*))(*(uint32_t*)piVar1 + 8))(piVar1);
      piVar2[2] = 0;
    }
    piVar1 = (int32_t*)*piVar2;
    if (piVar1 != (int32_t*)0x0) {
      (*(int32_t (**)(int32_t*))(*(uint32_t*)piVar1 + 8))(piVar1);
      *piVar2 = 0;
    }
    piVar2 = piVar2 + 1;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  FUN_00646ae9();
}

// 0x64d12e — observed shape: deleting destructor for a 100-byte object;
// scalar-deleting branch routes through FUN_00412770 with FUN_0064d072.
void FUN_0064d12e(void* self, uint8_t param_1)
{
  if ((param_1 & 2) == 0) {
    FUN_0064d072(self);
    if ((param_1 & 1) != 0) {
      operator_delete(self);
    }
  }
  else {
    FUN_00412770(self, 100, *(uint32_t*)((uint8_t*)self - 4), (void*)&FUN_0064d072);
    if ((param_1 & 1) != 0) {
      operator_delete((uint8_t*)self - 4);
    }
  }
}

// 0x64d17c — observed shape: deleting destructor for a 0xb4 object; routes
// through FUN_00412770 with FUN_0064d09b.
void FUN_0064d17c(void* self, uint8_t param_1)
{
  if ((param_1 & 2) == 0) {
    FUN_0064d09b(self);
    if ((param_1 & 1) != 0) {
      operator_delete(self);
    }
  }
  else {
    FUN_00412770(self, 0xb4, *(uint32_t*)((uint8_t*)self - 4), (void*)&FUN_0064d09b);
    if ((param_1 & 1) != 0) {
      operator_delete((uint8_t*)self - 4);
    }
  }
}

// 0x64d1cd — observed shape: reset header fields, pull two u32 values from the
// parameter vector, then classify the record at self->0x20 + index by its
// +4 field (0/1 vs 2/3 vs 5) and accumulate into self->0x128/0x124/0x12c.
int32_t FUN_0064d1cd(void* self, int32_t param_1, int32_t* param_2, uint32_t* param_3)
{
  uint32_t uVar1;
  uint32_t* puVar2;
  uint32_t uVar3;
  int32_t iVar4;
  int32_t iVar5;
  int32_t local_c;
  int32_t local_8;

  uint8_t* base = (uint8_t*)self;
  puVar2 = param_3;
  iVar5 = param_1;
  *(uint32_t*)((uint8_t*)(uintptr_t)param_1 + 0x28) = 4;
  *(uint32_t*)((uint8_t*)(uintptr_t)param_1 + 0x38) = 0;
  *(uint32_t*)((uint8_t*)(uintptr_t)param_1 + 0x18) = 0;
  *(uint32_t*)((uint8_t*)(uintptr_t)param_1 + 0x1c) = 0;
  if ((param_2 != (int32_t*)0x0) &&
     (uVar3 = (*(uint32_t (**)(int32_t*))(*(uint32_t*)param_2 + 0x10))(param_2),
      *puVar2 + 1 <= uVar3)) {
    iVar4 = (*(int32_t (**)(int32_t*))(*(uint32_t*)param_2 + 0xc))(param_2);
    *(uint32_t*)((uint8_t*)(uintptr_t)iVar5 + 0x2c) = *(uint32_t*)((uint8_t*)(uintptr_t)iVar4 +
                                                                   *puVar2 * 4);
  }
  *puVar2 = *puVar2 + 1;
  if ((param_2 != (int32_t*)0x0) &&
     (uVar3 = (*(uint32_t (**)(int32_t*))(*(uint32_t*)param_2 + 0x10))(param_2),
      *puVar2 + 1 <= uVar3)) {
    iVar4 = (*(int32_t (**)(int32_t*))(*(uint32_t*)param_2 + 0xc))(param_2);
    *(uint32_t*)((uint8_t*)(uintptr_t)iVar5 + 0x30) = *(uint32_t*)((uint8_t*)(uintptr_t)iVar4 +
                                                                   *puVar2 * 4);
  }
  *puVar2 = *puVar2 + 1;
  if ((param_2 == (int32_t*)0x0) ||
     (uVar3 = (*(uint32_t (**)(int32_t*))(*(uint32_t*)param_2 + 0x10))(param_2),
      uVar3 < *puVar2)) {
    return -0x7fffbffb;
  }
  param_2 = (int32_t*)0x0;
  *(int32_t*)(base + 0xa8) = *(int32_t*)(base + 0xa8) + 1;
  param_1 = *(int32_t*)(base + 0x20);
  local_c = *(int32_t*)((uint8_t*)(uintptr_t)iVar5 + 0x2c);
  if ((uint32_t)(*(int32_t*)(base + 0x1c) + param_1) <
      (uint32_t)(param_1 + 0x14 + local_c)) {
    return 0;
  }
  uVar3 = *(uint32_t*)((uint8_t*)(uintptr_t)(param_1 + 4 + local_c));
  uVar1 = *(uint32_t*)((uint8_t*)(uintptr_t)(param_1 + 0x10 + local_c));
  if (uVar3 < 2) {
    uVar3 = 1;
    if (1 < uVar1) {
      uVar3 = uVar1;
    }
    *(int32_t*)(base + 0x128) = *(int32_t*)(base + 0x128) + (int32_t)(uVar3 * 0x10);
    return 0;
  }
  if (uVar3 < 4) {
    uVar3 = 1;
    if (1 < uVar1) {
      uVar3 = uVar1;
    }
    *(int32_t*)(base + 0x124) = *(int32_t*)(base + 0x124) + (int32_t)(uVar3 * 0x40);
    return 0;
  }
  if (uVar3 != 5) {
    return 0;
  }
  local_8 = *(int32_t*)((uint8_t*)(uintptr_t)iVar5 + 0x30);
  param_3 = (uint32_t*)(uintptr_t)(local_c + param_1);
  param_1 = param_1 + local_8;
  param_2 = (int32_t*)FUN_006480e4(param_3, &param_1, 0);
  if ((int32_t)param_2 < 0) {
    return (int32_t)param_2;
  }
  iVar5 = FUN_0063eb76(*(int32_t*)(base + 0x20), &local_c, &local_8);
  *(int32_t*)(base + 300) = *(int32_t*)(base + 300) + iVar5;
  return (int32_t)param_2;
}

// 0x649a50 — observed shape: build/flush the sprite table for map record
// param_1. Validates record flags, iterates existing 0x64 sub-records releasing
// cached surfaces, parses the "PRES"/"PRSI" resource blocks, sizes and fills the
// packed vertex/index buffers (self->0x20 + index), creates sub-records from the
// compressed entry table and finally accumulates the 0x4e/0x54/0x5a/0x60 list
// counts. Returns 0 or a negative HRESULT.
int32_t FUN_00649a50(void* self, uint32_t param_1)
{
  int32_t iVar1;
  int32_t iVar2;
  int32_t iVar4;
  int32_t iVar5;
  int32_t iVar7;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar6;
  uint32_t uVar8;
  int32_t* piVar9;
  int32_t* piVar10;
  int16_t* psVar11;
  uint32_t* puVar12;
  uint8_t cVar13;
  uint32_t* puVar14;
  uint32_t* puVar15;
  int32_t* piVar16;
  uint32_t uVar17;
  uint32_t uVar18;
  uint32_t* puVar19;
  uint32_t* puVar20;
  uint64_t uVar21;
  int32_t* piVar22;
  uint16_t* puVar23;
  uint32_t uVar24;
  uint32_t** ppuVar25;
  uint16_t sVar1;
  uint8_t local_88[4];
  uint32_t* local_84;
  uint32_t* local_80;
  uint32_t* local_7c;
  uint32_t uStack_78;
  uint16_t local_74[4];
  int16_t local_6c[2];
  uint32_t* local_68;
  uint32_t local_64;
  void* local_60;
  uint8_t local_5c[4];
  int32_t* local_58;
  int32_t local_50;
  uint32_t* local_4c;
  int32_t* local_48;
  uint32_t* local_44;
  uint32_t* local_40;
  int32_t* local_3c;
  uint8_t local_38[4];
  uint32_t* local_34;
  uint32_t* local_30;
  int32_t* local_2c;
  uint16_t local_28[4];
  int32_t local_20;
  uint32_t* local_1c;
  int32_t local_18;
  uint32_t* local_14;
  int32_t* local_10;
  int32_t* local_c;
  uint32_t* local_8;

  uint8_t* base = (uint8_t*)self;

  piVar16 = (int32_t*)((uintptr_t)param_1 * 100 + *(int32_t*)(base + 0x2c));
  iVar7 = piVar16[1];
  iVar4 = *(int32_t*)((uint8_t*)(uintptr_t)iVar7 + 0x1c) * 4;
  local_18 = 0;
  local_60 = (void*)0x0;
  if (*(int32_t*)(*(int32_t*)((uint8_t*)(uintptr_t)(iVar4 + *(int32_t*)(base + 0xb0))) + 0x40) == 0) {
    iVar5 = *(int32_t*)(base + 0x20);
  }
  else {
    iVar5 = *(int32_t*)(*(int32_t*)(base + 0x38) + 0x10);
  }
  *(int32_t*)((uint8_t*)(uintptr_t)iVar7 + 8) =
    *(int32_t*)(*(int32_t*)((uint8_t*)(uintptr_t)(iVar4 + *(int32_t*)(base + 0xb0))) + 0x30) +
    *(int32_t*)((uint8_t*)(uintptr_t)iVar7 + 0x24) + iVar5;
  iVar7 = piVar16[1];
  iVar4 = *(int32_t*)((uint8_t*)(uintptr_t)iVar7 + 0x1c) * 4;
  if (*(int32_t*)(*(int32_t*)((uint8_t*)(uintptr_t)(iVar4 + *(int32_t*)(base + 0xb0))) + 0x40) == 0) {
    local_c = (int32_t*)(uintptr_t)*(int32_t*)(base + 0x20);
  }
  else {
    local_c = *(int32_t**)(*(int32_t*)(base + 0x38) + 0x10);
  }
  *(int32_t*)((uint8_t*)(uintptr_t)iVar7 + 0xc) =
    *(int32_t*)(*(int32_t*)((uint8_t*)(uintptr_t)(iVar4 + *(int32_t*)(base + 0xb0))) + 0x2c) +
    *(int32_t*)((uint8_t*)(uintptr_t)iVar7 + 0x20) + (int32_t)(uintptr_t)local_c;
  iVar7 = piVar16[1];
  iVar5 = *(int32_t*)((uint8_t*)(uintptr_t)iVar7 + 0x1c) * 4;
  iVar4 = *(int32_t*)((uint8_t*)(uintptr_t)(iVar5 + *(int32_t*)(base + 0xb0)));
  if (*(int32_t*)(*(int32_t*)((uint8_t*)(uintptr_t)(iVar5 + *(int32_t*)(base + 0xb0))) + 0x40) == 0) {
    if (*(int32_t*)((uint8_t*)(uintptr_t)iVar4 + 0x40) == 0) {
      iVar5 = *(int32_t*)(base + 0x20);
    }
    else {
      iVar5 = *(int32_t*)(*(int32_t*)(base + 0x38) + 0x10);
    }
    iVar7 = *(int32_t*)((uint8_t*)(uintptr_t)(*(int32_t*)((uint8_t*)(uintptr_t)iVar4 + 0x30) +
                                              *(int32_t*)((uint8_t*)(uintptr_t)iVar7 + 0x24) + iVar5));
  }
  else {
    if (*(int32_t*)((uint8_t*)(uintptr_t)iVar4 + 0x40) == 0) {
      local_c = (int32_t*)(uintptr_t)*(int32_t*)(base + 0x20);
    }
    else {
      local_c = *(int32_t**)(*(int32_t*)(base + 0x38) + 0x10);
    }
    iVar4 = *(int32_t*)((uint8_t*)(uintptr_t)(*(int32_t*)(base + 0xb0) +
                                              *(int32_t*)((uint8_t*)(uintptr_t)iVar7 + 0x1c) * 4));
    iVar7 = *(int32_t*)(*(int32_t*)(*(int32_t*)((uint8_t*)(uintptr_t)iVar4 + 0x40) + 8) +
                        *(int32_t*)((uint8_t*)(uintptr_t)(*(int32_t*)((uint8_t*)(uintptr_t)iVar7 + 0x24) +
                                                         *(int32_t*)((uint8_t*)(uintptr_t)iVar4 + 0x30) +
                                                         (int32_t)(uintptr_t)local_c)) * 4);
  }
  iVar7 = *(int32_t*)(base + 0x18) + iVar7 * 0x18;
  if ((*(uint32_t*)((uint8_t*)(uintptr_t)iVar7 + 0x14) & 1) == 0) {
    if ((((*(uint8_t*)((uint8_t*)piVar16 + 8) & 8) != 0) && (*(int32_t*)(base + 0xb4) != 0)) &&
       ((*(uint8_t*)(base + 0x119) & 8) == 0)) {
      local_44 = (uint32_t*)(uintptr_t)(*(int32_t*)(base + 0xac) * *(int32_t*)(base + 0xa0));
      local_1c = (uint32_t*)0x0;
      if (local_44 != (uint32_t*)0x0) {
        do {
          puVar15 = *(uint32_t**)((uintptr_t)local_1c * 4 + *(int32_t*)(base + 0xc0));
          if (puVar15 != (uint32_t*)0x0) {
            local_4c = *(uint32_t**)((uintptr_t)local_1c * 4 + *(int32_t*)(base + 0xb4));
            uVar17 = *puVar15;
            puVar14 = (uint32_t*)0x0;
            local_8 = puVar15;
            if (uVar17 != 0) {
              do {
                if (*(uint16_t*)((uintptr_t)uVar17 + 0x14) == param_1) {
                  if ((puVar14 == (uint32_t*)0x0) && (puVar14 = local_4c, *local_4c != 0)) {
                    do {
                      local_4c = local_4c + 1;
                    } while (*local_4c != 0);
                    puVar14 = local_4c;
                  }
                  *puVar14 = uVar17;
                  puVar14 = puVar14 + 1;
                  *puVar14 = 0;
                }
                local_8 = local_8 + 1;
                uVar17 = *local_8;
              } while (uVar17 != 0);
            }
          }
          local_1c = (uint32_t*)((uintptr_t)local_1c + 1);
        } while (local_1c < local_44);
      }
      piVar16[2] = piVar16[2] & 0xfffffff7;
    }
    local_18 = 0;
    goto LAB_0064a997;
  }
  if (*(int32_t*)((uint8_t*)(uintptr_t)iVar7 + 4) == 0) {
    *(uint32_t*)((uint8_t*)(uintptr_t)iVar7 + 0x14) =
      *(uint32_t*)((uint8_t*)(uintptr_t)iVar7 + 0x14) | 2;
    *(uint32_t*)((uint8_t*)(uintptr_t)iVar7 + 0xc) = 0;
  }
  else {
    local_18 = FUN_00643e7a(iVar7);
    if (local_18 < 0) goto LAB_0064a997;
  }
  *(uint32_t*)((uint8_t*)(uintptr_t)iVar7 + 0x14) =
    *(uint32_t*)((uint8_t*)(uintptr_t)iVar7 + 0x14) & 0xfffffffe;
  local_10 = (int32_t*)0x1;
  if (1 < *(uint16_t*)((uint8_t*)piVar16 + 0x36)) {
    local_8 = (uint32_t*)0x64;
    do {
      local_20 = piVar16[1] + (int32_t)(uintptr_t)local_8;
      if ((*(int16_t*)((uint8_t*)(uintptr_t)local_20 + 0x52) == 0xb4) ||
          (*(int16_t*)((uint8_t*)(uintptr_t)local_20 + 0x52) == 0xb5)) {
        piVar10 = *(int32_t**)((uint8_t*)(uintptr_t)local_20 + 0x38);
        if (piVar10 != (int32_t*)0x0) {
          (*(int32_t (**)(int32_t*))(*(uint32_t*)piVar10 + 8))(piVar10);
          *(uint32_t*)((uint8_t*)(uintptr_t)local_20 + 0x38) = 0;
        }
        local_14 = (uint32_t*)0x0;
        if (*(int16_t*)((uint8_t*)(uintptr_t)local_20 + 0x4e) != 0) {
          do {
            local_18 = FUN_00643dfb(param_1, (uint32_t)(uintptr_t)local_10,
                                    (uint32_t)(uintptr_t)local_14);
            if (local_18 < 0) goto LAB_0064a997;
            local_14 = (uint32_t*)((uintptr_t)local_14 + 1);
          } while (local_14 < (uint32_t*)(uintptr_t)(uint32_t)*(uint16_t*)
                             ((uint8_t*)(uintptr_t)local_20 + 0x4e));
        }
      }
      else if ((*(int16_t*)((uint8_t*)(uintptr_t)local_20 + 0x4e) != 0) &&
              (local_18 = FUN_00643dfb(param_1, (uint32_t)(uintptr_t)local_10, 0), local_18 < 0))
        goto LAB_0064a997;
      local_10 = (int32_t*)((uintptr_t)local_10 + 1);
      local_8 = local_8 + 0x19;
      *(uint16_t*)((uint8_t*)(uintptr_t)local_20 + 0x4e) = 0;
    } while (local_10 < (int32_t*)(uintptr_t)(uint32_t)*(uint16_t*)((uint8_t*)piVar16 + 0x36));
  }
  puVar15 = (uint32_t*)0x0;
  local_84 = (uint32_t*)0x0;
  local_80 = (uint32_t*)0x0;
  local_7c = (uint32_t*)0x0;
  uStack_78 = 0;
  *(uint16_t*)((uint8_t*)piVar16 + 0x36) = 1;
  *(uint16_t*)(piVar16 + 0xd) = 0;
  *(uint16_t*)(piVar16 + 6) = 0;
  piVar16[7] = 0;
  piVar16[8] = 0;
  if ((*(uint8_t*)((uint8_t*)(uintptr_t)iVar7 + 0x14) & 2) == 0) goto LAB_0064a997;
  local_30 = (uint32_t*)0x0;
  local_48 = (int32_t*)0x0;
  local_c = (int32_t*)0x1;
  local_8 = (uint32_t*)0x1;
  if (*(int32_t*)((uint8_t*)(uintptr_t)iVar7 + 4) == 0) {
    piVar10 = (int32_t*)((uint8_t*)(uintptr_t)iVar7 + 0xc);
    *piVar10 = 0;
    uVar17 = 0;
    local_28[0] = 0;
    local_28[1] = 0;
    piVar9 = piVar16 + 7;
    local_28[2] = 0;
    do {
      *(uint8_t*)(uintptr_t)(uVar17 + 0x2c + (uintptr_t)piVar16) = 0;
      *(uint16_t*)piVar9 = 0;
      uVar17 = uVar17 + 1;
      piVar9 = (int32_t*)((uint8_t*)piVar9 + 2);
    } while (uVar17 < 4);
    local_8 = (uint32_t*)0x0;
    local_10 = piVar10;
  }
  else {
    piVar9 = &local_50;
    psVar11 = local_6c;
    puVar23 = local_74;
    piVar10 = (int32_t*)((uint8_t*)(uintptr_t)iVar7 + 0xc);
    piVar22 = piVar10;
    local_10 = piVar10;
    {
      uint8_t* vtObj = *(uint8_t**)((uint8_t*)(uintptr_t)iVar7 + 8);
      uVar6 = (*(uint32_t (**)(void*, int32_t*, uint16_t*, int16_t*, int32_t*))
               (*(uint8_t**)vtObj + 0xc))(vtObj, piVar10, puVar23, psVar11, piVar9);
    }
    local_18 = FUN_0063e055(uVar6, piVar22, puVar23, psVar11, piVar9);
    if (local_18 < 0) goto LAB_0064a997;
    piVar16[7] = local_50;
    piVar16[8] = (int32_t)(uintptr_t)local_4c;
    puVar15 = &local_64;
    ppuVar25 = &local_30;
    uVar24 = 0x53455250;
    {
      uint8_t* vtObj = *(uint8_t**)((uint8_t*)(uintptr_t)iVar7 + 8);
      uVar6 = (*(uint32_t (**)(void*, uint32_t, uint32_t**, uint32_t*))
               (*(uint8_t**)vtObj + 0xc))(vtObj, 0x53455250, ppuVar25, puVar15);
    }
    local_18 = FUN_005f7ad0(uVar6, uVar24, ppuVar25, puVar15);
    if (local_18 < 0) {
      return local_18;
    }
    if (local_18 == 0) {
      local_c = (int32_t*)0x2;
      iVar7 = FUN_005f7ad0((uint32_t)(uintptr_t)local_30, 0x49535250,
                           (uint32_t*)&local_48, local_88);
      if (iVar7 < 0) {
        return iVar7;
      }
      local_18 = FUN_0063e055((uint32_t)(uintptr_t)local_30, (uint32_t*)&local_44, local_5c,
                              local_38, local_28);
      if (local_18 < 0) {
        return local_18;
      }
      uVar17 = 0;
      do {
        uVar8 = uVar17 + 1;
        local_28[uVar17] = (uint16_t)((int16_t)local_48[uVar17 + 3] + (int16_t)local_48[uVar17]);
        uVar17 = uVar8;
      } while (uVar8 < 3);
    }
    else {
      local_28[0] = 0;
      local_28[1] = 0;
      local_28[2] = 0;
      piVar10 = local_10;
    }
    piVar9 = piVar16 + 0xb;
    uVar17 = 0;
    puVar15 = local_8;
    do {
      if ((*(int16_t*)((uintptr_t)local_6c + uVar17) == 0) &&
         (*(int16_t*)((uintptr_t)local_38 + (uVar17 - 0x18)) ==
          *(int16_t*)((uintptr_t)local_74 + uVar17))) {
        cVar13 = '\x01';
      }
      else {
        cVar13 = '\0';
      }
      sVar1 = *(int16_t*)((uintptr_t)local_74 + uVar17);
      *(uint8_t*)piVar9 = cVar13;
      if ((sVar1 != 0) && (cVar13 == '\0')) {
        puVar15 = (uint32_t*)0x0;
      }
      piVar9 = (int32_t*)((uint8_t*)piVar9 + 1);
      uVar17 = uVar17 + 2;
    } while (uVar17 < 8);
  }
  local_28[3] = 0;
  local_20 = *piVar10;
  *(uint16_t*)((uint8_t*)piVar16 + 0x4e) = 1;
  *(uint16_t*)(piVar16 + 0x15) = 1;
  *(uint16_t*)((uint8_t*)piVar16 + 0x5a) = 1;
  *(uint16_t*)(piVar16 + 0x18) = 1;
  *(uint16_t*)(piVar16 + 0x13) = 1;
  *(uint16_t*)((uint8_t*)piVar16 + 0x52) = 1;
  *(uint16_t*)(piVar16 + 0x16) = 1;
  *(uint16_t*)((uint8_t*)piVar16 + 0x5e) = 1;
  *(int16_t*)(piVar16 + 0x14) = (int16_t)piVar16[7];
  uVar17 = piVar16[2] & 0xfffffffaU | (uint32_t)puVar15 & 1;
  *(int16_t*)((uint8_t*)piVar16 + 0x56) = (int16_t)piVar16[8];
  piVar16[2] = uVar17 | 2;
  *(uint16_t*)(piVar16 + 0x17) = *(uint16_t*)((uint8_t*)piVar16 + 0x1e);
  if (*piVar10 == 0) goto LAB_0064a997;
  piVar16[2] = uVar17 | 10;
  uVar17 = (uint32_t)(*(int32_t*)((uint8_t*)(uintptr_t)local_20 + 0xc) +
                      (int32_t)(uintptr_t)local_c);
  if (*(uint16_t*)(piVar16 + 0xe) < uVar17) {
    puVar15 = (uint32_t*)FUN_00533c78(uVar17 * 100 + 4);
    if (puVar15 == (uint32_t*)0x0) {
      local_14 = (uint32_t*)0x0;
    }
    else {
      *puVar15 = uVar17;
      FUN_004127b0(puVar15 + 1, 100, uVar17, &LAB_00646b1e);
      local_14 = puVar15 + 1;
    }
    if (local_14 != (uint32_t*)0x0) {
      uVar3 = *(uint16_t*)((uint8_t*)(uintptr_t)piVar16[1] + 0x52);
      *(uint16_t*)((uint8_t*)local_14 + 0x52) = (uint16_t)uVar3;
      uVar17 = *(uint32_t*)(&DAT_006eacac + (uintptr_t)uVar3 * 0x1c);
      *(uint16_t*)(local_14 + 0x15) = 0xffff;
      local_14[0x16] = uVar17;
      *(uint16_t*)((uint8_t*)local_14 + 0x56) = 1;
      puVar15 = (uint32_t*)(uintptr_t)(piVar16[1] + 8);
      puVar14 = local_14 + 2;
      for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar14 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar14 = puVar14 + 1;
      }
      *local_14 = *(uint32_t*)(uintptr_t)piVar16[1];
      local_14[0xc] =
        local_14[0xc] ^ ((*(int32_t*)((uint8_t*)(uintptr_t)piVar16[1] + 0x30) << 0x1f) >> 0x1f ^
                         local_14[0xc]) & 1;
      local_14[0xc] =
        ((*(int32_t*)((uint8_t*)(uintptr_t)piVar16[1] + 0x30) << 0x1e) >> 0x1e ^ local_14[0xc]) &
        2 ^ local_14[0xc];
      local_14[0xf] = *(uint32_t*)((uint8_t*)(uintptr_t)piVar16[1] + 0x3c);
      local_14[0xd] = *(uint32_t*)((uint8_t*)(uintptr_t)piVar16[1] + 0x34);
      *(uint16_t*)((uint8_t*)local_14 + 0x4e) =
        *(uint16_t*)((uint8_t*)(uintptr_t)piVar16[1] + 0x4e);
      *(uint16_t*)(local_14 + 0x14) = *(uint16_t*)((uint8_t*)(uintptr_t)piVar16[1] + 0x50);
      local_14[0xe] = *(uint32_t*)((uint8_t*)(uintptr_t)piVar16[1] + 0x38);
      *(uint32_t*)((uint8_t*)(uintptr_t)piVar16[1] + 0x34) = 0;
      *(uint16_t*)((uint8_t*)(uintptr_t)piVar16[1] + 0x4e) = 0;
      *(uint16_t*)((uint8_t*)(uintptr_t)piVar16[1] + 0x50) = 0;
      *(uint32_t*)((uint8_t*)(uintptr_t)piVar16[1] + 0x38) = 0;
      if (piVar16[1] != 0) {
        FUN_00647bbc(3);
        piVar16[1] = 0;
      }
      piVar16[1] = (int32_t)(uintptr_t)local_14;
      *(int16_t*)(piVar16 + 0xe) = *(int16_t*)((uint8_t*)(uintptr_t)(*local_10) + 0xc) + 1;
      goto LAB_00649f58;
    }
  }
  else {
LAB_00649f58:
    uVar17 = (uint32_t)*(uint16_t*)(piVar16 + 7);
    piVar16[3] = 0;
    piVar16[0x10] = 0;
    if (*(uint16_t*)(piVar16 + 7) <= local_28[0]) {
      uVar17 = ((uint32_t)local_28[1] << 16) | local_28[0];
    }
    local_4c = (uint32_t*)(uintptr_t)((uVar17 & 0xffff) * 0x10);
    uVar17 = (uint32_t)*(uint16_t*)((uint8_t*)piVar16 + 0x1e);
    piVar16[3] = (int32_t)(uintptr_t)local_4c;
    piVar16[0x12] = (int32_t)(uintptr_t)local_4c;
    if (*(uint16_t*)((uint8_t*)piVar16 + 0x1e) <= local_28[1]) {
      uVar17 = ((uint32_t)local_28[2] << 16) | local_28[1];
    }
    local_68 = local_4c + (uVar17 & 0xffff);
    uVar17 = (uint32_t)*(uint16_t*)(piVar16 + 8);
    piVar16[3] = (int32_t)(uintptr_t)local_68;
    piVar16[0x11] = (int32_t)(uintptr_t)local_68;
    if (*(uint16_t*)(piVar16 + 8) <= local_28[2]) {
      uVar17 = ((uint32_t)local_28[3] << 16) | local_28[2];
    }
    local_44 = local_68 + (uVar17 & 0xffff) * 4;
    piVar16[3] = (int32_t)(uintptr_t)(local_44 +
                                      *(uint16_t*)((uint8_t*)piVar16 + 0x22));
    *(uint16_t*)(piVar16 + 0xd) = *(uint16_t*)((uint8_t*)piVar16 + 0x22);
    if (local_30 != (uint32_t*)0x0) {
      local_8 = (uint32_t*)((uintptr_t)(uint32_t)*(uint16_t*)((uint8_t*)piVar16 + 0x36) * 100 +
                            piVar16[1]);
      *(uint16_t*)((uint8_t*)piVar16 + 0x36) =
        *(uint16_t*)((uint8_t*)piVar16 + 0x36) + 1;
      *local_8 = 1;
      local_8[0xc] = local_8[0xc] & 0xfffffff5 | 1;
      piVar16[2] = piVar16[2] | 4;
      puVar15 = local_8 + 0xe;
      local_18 = FUN_006294f9(local_64 + 0x68, (void**)&puVar15);
      if (local_18 < 0) goto LAB_0064a997;
      piVar10 = (int32_t*)*puVar15;
      local_14 = (uint32_t*)(*(uint32_t (**)(int32_t*))(*(uint32_t*)piVar10 + 0xc))(piVar10);
      local_1c = (uint32_t*)(local_48 + 1);
      local_c = local_48 + 3;
      local_34 = (uint32_t*)(local_48 + 4);
      local_58 = local_48;
      local_2c = local_48 + 5;
      local_3c = local_48 + 2;
      uVar17 = (uint32_t)(*local_c + *local_48) * 4 |
               ((uint32_t)(*local_c + *local_48) & 0x3fffffffU) << 1;
      uVar17 = uVar17 | uVar17 >> 2;
      uVar17 = uVar17 | uVar17 >> 4;
      uVar17 = uVar17 | uVar17 >> 8;
      uVar17 = uVar17 | uVar17 >> 0x10;
      uVar8 = (uint32_t)(*local_1c + *local_34) * 4 |
              ((uint32_t)(*local_1c + *local_34) & 0x3fffffff) << 1;
      uVar8 = uVar8 | uVar8 >> 2;
      uVar8 = uVar8 | uVar8 >> 4;
      uVar8 = uVar8 | uVar8 >> 8;
      uVar8 = uVar8 | uVar8 >> 0x10;
      uVar18 = (uint32_t)(*local_3c + *local_2c) * 4 |
               ((uint32_t)(*local_3c + *local_2c) & 0x3fffffffU) << 1;
      local_14[6] = 0;
      uVar18 = uVar18 | uVar18 >> 2;
      uVar18 = uVar18 | uVar18 >> 4;
      uVar18 = uVar18 | uVar18 >> 8;
      local_40 = (uint32_t*)(uintptr_t)(uVar18 | uVar18 >> 0x10);
      local_14[2] = (uint32_t)(uintptr_t)local_40;
      *local_14 = uVar17;
      local_14[1] = uVar8;
      uVar18 = (uint32_t)(*local_48 + *local_c) * 4;
      local_14[3] = uVar18;
      if (uVar18 != 0) {
        local_14[3] = uVar18 - 1;
      }
      uVar18 = (uint32_t)(*local_34 + *local_1c) * 4;
      local_14[4] = uVar18;
      if (uVar18 != 0) {
        local_14[4] = uVar18 - 1;
      }
      uVar18 = (uint32_t)(*local_2c + *local_3c) * 4;
      local_14[5] = uVar18;
      if (uVar18 != 0) {
        local_14[5] = uVar18 - 1;
      }
      uVar18 = local_14[3] >> 1 | local_14[3];
      uVar18 = uVar18 >> 2 | uVar18;
      uVar18 = uVar18 >> 4 | uVar18;
      uVar18 = uVar18 >> 8 | uVar18;
      local_14[3] = uVar18 >> 0x10 | uVar18;
      uVar18 = local_14[4] >> 1 | local_14[4];
      uVar18 = uVar18 >> 2 | uVar18;
      uVar18 = uVar18 >> 4 | uVar18;
      uVar18 = uVar18 >> 8 | uVar18;
      local_14[4] = uVar18 >> 0x10 | uVar18;
      uVar18 = local_14[5] >> 1 | local_14[5];
      uVar18 = uVar18 >> 2 | uVar18;
      uVar18 = uVar18 >> 4 | uVar18;
      uVar18 = uVar18 >> 8 | uVar18;
      local_14[5] = uVar18 >> 0x10 | uVar18;
      uVar18 = (piVar16[3] & 7U) + (piVar16[3] & 0xfffffff8U);
      piVar16[3] = uVar18;
      local_14[7] = uVar18;
      uVar17 = (uint32_t)piVar16[3] + uVar17 * 8;
      uVar17 = (uVar17 & 7) + (uVar17 & 0xfffffff8);
      piVar16[3] = uVar17;
      local_14[8] = uVar17;
      uVar17 = (uint32_t)piVar16[3] + uVar8 * 8;
      uVar17 = (uVar17 & 7) + (uVar17 & 0xfffffff8);
      piVar16[3] = uVar17;
      local_14[9] = uVar17;
      piVar16[3] = piVar16[3] + (int32_t)(uintptr_t)local_40 * 8;
      uVar17 = 0;
      local_14[10] = 0;
      local_14[0xb] = (uint32_t)(uintptr_t)local_4c;
      local_14[0xc] = (uint32_t)(uintptr_t)local_68;
      *(uint16_t*)((uint8_t*)local_8 + 0x56) = 0;
      *(uint16_t*)(local_8 + 0x15) = 0;
      puVar15 = local_14 + 0x10;
      do {
        puVar15[3] = (uint32_t)local_c[uVar17];
        *puVar15 = (uint32_t)local_48[uVar17];
        uVar17 = uVar17 + 1;
        puVar15 = puVar15 + 1;
      } while (uVar17 < 3);
      local_14[0x17] = (int32_t)(uintptr_t)local_48 + (0x80 - (int32_t)(uintptr_t)local_30);
      uVar17 = (uint32_t)((int32_t)(uintptr_t)local_48 + local_48[6] * 8 +
                          (0x84 - (int32_t)(uintptr_t)local_30));
      local_14[0x18] = uVar17;
      local_14[0x19] = uVar17 + 4 +
                       (uint32_t)*(int32_t*)(((uint8_t*)(uintptr_t)uVar17 - 0x68) +
                                             (uintptr_t)local_30) * 8;
      puVar15 = local_30;
      puVar14 = local_14 + 0x1a;
      for (uVar17 = local_64 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
        *puVar14 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar14 = puVar14 + 1;
      }
      for (uVar17 = local_64 & 3; uVar17 != 0; uVar17 = uVar17 - 1) {
        *(uint8_t*)puVar14 = (uint8_t)*puVar15;
        puVar15 = (uint32_t*)((uint8_t*)puVar15 + 1);
        puVar14 = (uint32_t*)((uint8_t*)puVar14 + 1);
      }
      local_18 = FUN_0060afb7((uint32_t)(uintptr_t)(local_14 + 0x1a),
                              (uint32_t)(uintptr_t)(local_8 + 0x10),
                              (uint32_t)(uintptr_t)(local_8 + 0x11));
      if ((local_18 < 0) ||
         (local_18 = FUN_00643bf5(param_1,
                                  (uint32_t)*(uint16_t*)((uint8_t*)piVar16 + 0x36) - 1,
                                  (uint32_t)(uintptr_t)local_14), local_18 < 0))
        goto LAB_0064a997;
      *(uint16_t*)((uint8_t*)local_8 + 0x52) = 0xb4;
      local_8[0x16] = 0x10000000;
      piVar16[2] = piVar16[2] | 1;
      local_1c = (uint32_t*)(piVar16 + 7);
      local_8 = local_14 + 0x17;
      uVar17 = 0;
      do {
        uVar3 = *(uint16_t*)((uintptr_t)local_28 + uVar17);
        if (uVar3 != 0) {
          piVar10 = (int32_t*)(uintptr_t)(*local_8 + (int32_t)(uintptr_t)local_14);
          iVar4 = 0;
          for (iVar7 = *piVar10; iVar7 != 0; iVar7 = iVar7 + -1) {
            piVar10 = piVar10 + 2;
            iVar4 = iVar4 + *piVar10;
          }
          uVar2 = (uint16_t)*local_1c;
          if ((uint16_t)*local_1c <= uVar3) {
            uVar2 = uVar3;
          }
          if ((uint32_t)*(uint16_t*)((uintptr_t)local_74 + uVar17) + (uint32_t)iVar4 != uVar2) {
            piVar16[2] = piVar16[2] & 0xfffffffe;
            break;
          }
          if ((iVar4 != 0) && (*(uint16_t*)((uintptr_t)local_74 + uVar17) == 0)) {
            piVar16[2] = piVar16[2] | 0x10;
          }
        }
        local_8 = local_8 + 1;
        local_1c = (uint32_t*)((uint8_t*)local_1c + 2);
        uVar17 = uVar17 + 2;
      } while (uVar17 < 6);
      if ((*(uint8_t*)((uint8_t*)piVar16 + 8) & 1) != 0) {
        uVar3 = *(uint16_t*)(piVar16 + 7);
        if (*(uint16_t*)(piVar16 + 7) <= local_28[0]) {
          uVar3 = local_28[0];
        }
        *(uint16_t*)(piVar16 + 0x14) = (uint16_t)uVar3;
        uVar3 = *(uint16_t*)(piVar16 + 8);
        if (*(uint16_t*)(piVar16 + 8) <= local_28[2]) {
          uVar3 = local_28[2];
        }
        *(uint16_t*)((uint8_t*)piVar16 + 0x56) = (uint16_t)uVar3;
        uVar3 = *(uint16_t*)((uint8_t*)piVar16 + 0x1e);
        if (*(uint16_t*)((uint8_t*)piVar16 + 0x1e) <= local_28[1]) {
          uVar3 = local_28[1];
        }
        *(uint16_t*)(piVar16 + 0x17) = (uint16_t)uVar3;
      }
    }
    local_18 = FUN_0063e391();
    iVar7 = local_20;
    if (local_18 < 0) goto LAB_0064a997;
    *(uint16_t*)(piVar16 + 0xd) = 0;
    local_60 = (void*)FUN_00533c78(*(int32_t*)((uint8_t*)(uintptr_t)local_20 + 0xc) << 2);
    if (local_60 != (void*)0x0) {
      uVar17 = 0;
      iVar4 = *(int32_t*)((uint8_t*)(uintptr_t)iVar7 + 0x10) + iVar7;
      if (*(int32_t*)((uint8_t*)(uintptr_t)iVar7 + 0xc) != 0) {
        do {
          *(int32_t*)((uint8_t*)local_60 + uVar17 * 4) = iVar4;
          uVar17 = uVar17 + 1;
          iVar4 = iVar4 + 0x14;
        } while (uVar17 < *(uint32_t*)((uint8_t*)(uintptr_t)iVar7 + 0xc));
      }
      qsort(local_60, (size_t)*(int32_t*)((uint8_t*)(uintptr_t)iVar7 + 0xc), 4,
            (int (*)(const void*, const void*))FUN_0063e2a9);
      iVar4 = 0;
      iVar5 = 0;
      local_2c = (int32_t*)0x0;
      if (*(int32_t**)((uint8_t*)(uintptr_t)iVar7 + 0xc) != (int32_t*)0x0) {
        psVar11 = (int16_t*)(uintptr_t)(*(int32_t*)((uint8_t*)(uintptr_t)iVar7 + 0x10) + iVar7 + 4);
        local_c = *(int32_t**)((uint8_t*)(uintptr_t)iVar7 + 0xc);
        do {
          sVar1 = *psVar11;
          if (sVar1 == 0) {
            iVar5 = iVar5 + 1;
          }
          else if (sVar1 == 1) {
            local_2c = (int32_t*)((uintptr_t)local_2c + 1);
          }
          else if (sVar1 == 2) {
            iVar4 = iVar4 + 1;
          }
          psVar11 = psVar11 + 10;
          local_c = (int32_t*)((uintptr_t)local_c + -1);
        } while (local_c != (int32_t*)0x0);
      }
      local_3c = (int32_t*)0x0;
      uVar3 = *(uint16_t*)((uint8_t*)piVar16 + 0x36);
      local_8 = (uint32_t*)(uintptr_t)uVar3;
      local_1c = (uint32_t*)(uintptr_t)(iVar4 + (int32_t)(uintptr_t)local_8);
      local_2c = (int32_t*)((uintptr_t)local_2c + (uintptr_t)local_1c);
      local_14 = (uint32_t*)(uintptr_t)(iVar5 + (int32_t)(uintptr_t)local_2c);
      *(uint16_t*)((uint8_t*)piVar16 + 0x36) =
        (uint16_t)(*(int16_t*)((uint8_t*)(uintptr_t)iVar7 + 0xc) + uVar3);
      *(uint16_t*)(piVar16 + 0x13) = (uint16_t)uVar3;
      *(int16_t*)((uint8_t*)piVar16 + 0x52) = (int16_t)(uintptr_t)local_1c;
      *(int16_t*)(piVar16 + 0x16) = (int16_t)(uintptr_t)local_2c;
      *(uint16_t*)((uint8_t*)piVar16 + 0x5e) = (uint16_t)(uintptr_t)local_14;
      if (*(int32_t*)((uint8_t*)(uintptr_t)iVar7 + 0xc) != 0) {
        do {
          piVar10 = *(int32_t**)((uint8_t*)local_60 + (uintptr_t)local_3c * 4);
          sVar1 = (int16_t)piVar10[1];
          local_10 = (int32_t*)0x0;
          if (sVar1 == 0) {
            local_10 = (int32_t*)(uintptr_t)((uint32_t)(uintptr_t)local_2c & 0xffff);
            local_2c = (int32_t*)((uintptr_t)local_2c + 1);
          }
          else if (sVar1 == 1) {
            local_10 = (int32_t*)(uintptr_t)((uint32_t)(uintptr_t)local_1c & 0xffff);
            local_1c = (uint32_t*)((uintptr_t)local_1c + 1);
          }
          else if (sVar1 == 2) {
            local_10 = (int32_t*)(uintptr_t)((uint32_t)(uintptr_t)local_8 & 0xffff);
            local_8 = (uint32_t*)((uintptr_t)local_8 + 1);
          }
          else if (sVar1 == 3) {
            local_10 = (int32_t*)(uintptr_t)((uint32_t)(uintptr_t)local_14 & 0xffff);
            local_14 = (uint32_t*)((uintptr_t)local_14 + 1);
          }
          puVar19 = (uint32_t*)(uintptr_t)((uintptr_t)local_10 * 100 + piVar16[1]);
          *(uint16_t*)(puVar19 + 0x15) = *(uint16_t*)((uint8_t*)piVar10 + 6);
          iVar7 = piVar10[2];
          puVar19[0xc] = puVar19[0xc] | 9;
          *(int16_t*)((uint8_t*)puVar19 + 0x56) = (int16_t)iVar7;
          local_58 = piVar10;
          local_40 = puVar19;
          iVar7 = FUN_0063ea6b(*piVar10 + local_20, 10);
          local_28[2] = (uint16_t)iVar7;
          local_28[3] = (uint16_t)((uint32_t)iVar7 >> 0x10);
          if (iVar7 == 0) {
            *puVar19 = 0;
            puVar19 = (uint32_t*)0x0;
          }
          else {
            if (*(int16_t*)(puVar19 + 0x14) == 0) {
              puVar12 = (uint32_t*)FUN_00533c78(0x24);
              if (puVar12 == (uint32_t*)0x0) {
                puVar15 = (uint32_t*)0x0;
              }
              else {
                *puVar12 = 1;
                local_34 = puVar12 + 1;
                FUN_004127b0(local_34, 0x20, 1, &LAB_0063e2de);
                puVar15 = local_34;
              }
              puVar19[0xd] = (uint32_t)(uintptr_t)puVar15;
              if (puVar15 == (uint32_t*)0x0) goto LAB_0064a8e0;
              *(uint16_t*)(puVar19 + 0x14) = 1;
            }
            local_18 = FUN_0063e97c(param_1, (uint32_t)(uintptr_t)local_10, 0,
                                    ((uint32_t)local_28[3] << 16) | local_28[2], piVar10);
            if (local_18 < 0) goto LAB_0064a997;
            /* Ghidra keeps the FUN_0063e97c output offset in local_28[2..3] and
               then reads from it as a base pointer; preserved verbatim. */
            puVar19 = (uint32_t*)(uintptr_t)(((uint32_t)local_28[3] << 16) | local_28[2]);
            *(uint16_t*)((uint8_t*)local_40 + 0x4e) = 1;
            puVar12 = puVar19;
            puVar20 = local_40 + 2;
            for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
              *puVar20 = *puVar12;
              puVar12 = puVar12 + 1;
              puVar20 = puVar20 + 1;
            }
            local_40[10] = 0;
            local_40[0xb] = 0;
            local_40[0xc] = local_40[0xc] & 0xfffffffd;
            *local_40 = 1;
          }
          piVar10 = local_58;
          local_40[0xf] = local_20;
          sVar1 = (int16_t)local_58[1];
          if (sVar1 == 0) {
            *(uint16_t*)((uint8_t*)local_40 + 0x52) = 0x95;
            local_40[0x16] = 0xc010000;
            local_34 = local_4c + *(uint16_t*)((uint8_t*)local_58 + 6);
            local_40[0x12] = (uint32_t)(uintptr_t)local_34;
            uVar17 = (uint32_t)*(uint16_t*)(local_58 + 2);
            if (local_58[4] == 0) {
              puVar19 = (uint32_t*)(uintptr_t)(*piVar16 + (int32_t)(uintptr_t)local_34);
              for (; uVar17 != 0; uVar17 = uVar17 - 1) {
                *puVar19 = 0;
                puVar19 = puVar19 + 1;
              }
              for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                *(uint8_t*)puVar19 = 0;
                puVar19 = (uint32_t*)((uint8_t*)puVar19 + 1);
              }
            }
            else {
              puVar19 = (uint32_t*)(uintptr_t)(local_20 + local_58[4]);
              puVar12 = (uint32_t*)(uintptr_t)(*piVar16 + (int32_t)(uintptr_t)local_34);
              for (; uVar17 != 0; uVar17 = uVar17 - 1) {
                *puVar12 = *puVar19;
                puVar19 = puVar19 + 1;
                puVar12 = puVar12 + 1;
              }
              for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                *(uint8_t*)puVar12 = *(uint8_t*)puVar19;
                puVar19 = (uint32_t*)((uint8_t*)puVar19 + 1);
                puVar12 = (uint32_t*)((uint8_t*)puVar12 + 1);
              }
            }
            if (*(uint8_t*)((uint8_t*)piVar16 + 0x2d) != '\0') {
              if (local_80 != (uint32_t*)0x0) {
                local_80[0xc] = local_80[0xc] & 0xfffffffe;
              }
              local_80 = local_40;
            }
          }
          else if (sVar1 == 1) {
            local_c = (int32_t*)0x0;
            *(uint16_t*)((uint8_t*)local_40 + 0x52) = 0x96;
            local_40[0x16] = 0xc020000;
            local_40[0x12] = (uint32_t)(uintptr_t)(local_68 +
              (uintptr_t)(uint32_t)*(uint16_t*)((uint8_t*)local_58 + 6) * 4);
            if ((int16_t)local_58[2] != 0) {
              iVar7 = 0;
              do {
                *(uint32_t*)(uintptr_t)(*piVar16 + local_40[0x12] + iVar7) = 0;
                iVar7 = iVar7 + 0x10;
                *(uint32_t*)(uintptr_t)(*piVar16 + local_40[0x12] + -0xc + iVar7) = 0;
                *(uint32_t*)(uintptr_t)(*piVar16 + local_40[0x12] + -8 + iVar7) = 1;
                *(uint32_t*)(uintptr_t)(*piVar16 + local_40[0x12] + -4 + iVar7) = 0;
                local_c = (int32_t*)((uintptr_t)local_c + 1);
              } while (local_c < (int32_t*)(uintptr_t)(uint32_t)*(uint16_t*)(local_58 + 2));
            }
            if (local_58[4] != 0) {
              puVar19 = (uint32_t*)(uintptr_t)(local_20 + local_58[4]);
              puVar12 = (uint32_t*)(uintptr_t)(*piVar16 + local_40[0x12]);
              for (iVar7 = (uint32_t)*(uint16_t*)(local_58 + 2) << 2; iVar7 != 0;
                   iVar7 = iVar7 + -1) {
                *puVar12 = *puVar19;
                puVar19 = puVar19 + 1;
                puVar12 = puVar12 + 1;
              }
              for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                *(uint8_t*)puVar12 = *(uint8_t*)puVar19;
                puVar19 = (uint32_t*)((uint8_t*)puVar19 + 1);
                puVar12 = (uint32_t*)((uint8_t*)puVar12 + 1);
              }
            }
            if (*(uint8_t*)((uint8_t*)piVar16 + 0x2e) != '\0') {
              if (local_7c != (uint32_t*)0x0) {
                local_7c[0xc] = local_7c[0xc] & 0xfffffffe;
              }
              local_7c = local_40;
            }
          }
          else if (sVar1 == 2) {
            puVar12 = local_40;
            if (puVar19 != (uint32_t*)0x0) {
              iVar7 = *(int32_t*)(uintptr_t)puVar19[1];
              if (((int32_t*)(uintptr_t)puVar19[1])[4] == 0) {
                local_10 = (int32_t*)0x1;
              }
              else {
                local_10 = *(int32_t**)((uintptr_t)puVar19[1] + 0x10);
              }
              local_c = *(int32_t**)((uintptr_t)puVar19[1] + 0x18);
              iVar4 = *(int32_t*)((uintptr_t)puVar19[1] + 4);
              if (-1 < iVar4) {
                if (iVar4 < 2) {
                  if (iVar7 == 3) {
                    local_40[0xc] = local_40[0xc] | 0x10;
                    local_40[0x17] = *puVar19;
                    piVar9 = (int32_t*)(uintptr_t)(uint32_t)*(uint16_t*)(local_58 + 2);
                    if (local_10 < (int32_t*)(uintptr_t)(uint32_t)*(uint16_t*)(local_58 + 2)) {
                      piVar9 = local_10;
                    }
                    goto LAB_0064a736;
                  }
                }
                else if (iVar4 == 2) {
                  if ((iVar7 == 3) &&
                      (*(int16_t*)((uintptr_t)(local_58[3] + local_20)) == 3)) {
                    if (local_10 == (int32_t*)0x1) {
                      local_40[0xc] = local_40[0xc] | 0x10;
                      local_40[0x17] = *puVar19;
                      piVar9 = (int32_t*)(uintptr_t)(uint32_t)*(uint16_t*)(local_58 + 2);
                      if (local_c < (int32_t*)(uintptr_t)(uint32_t)*(uint16_t*)(local_58 + 2)) {
                        piVar9 = local_c;
                      }
                    }
                    else {
                      if (local_c != (int32_t*)0x4) goto LAB_0064a73c;
                      local_40[0xc] = local_40[0xc] | 0x10;
                      local_40[0x17] = *puVar19;
                      piVar9 = (int32_t*)((uintptr_t)local_10 << 2);
                      if ((int32_t*)(uintptr_t)(uint32_t)*(uint16_t*)(local_58 + 2) <=
                          (int32_t*)((uintptr_t)local_10 << 2)) {
                        piVar9 = (int32_t*)(uintptr_t)(uint32_t)*(uint16_t*)(local_58 + 2);
                      }
                    }
LAB_0064a736:
                    local_40[0x18] = (int32_t)((uintptr_t)piVar9 << 4);
                  }
                }
                else if (iVar4 == 5) {
                  puVar15 = (uint32_t*)(uintptr_t)puVar19[1];
                  local_34 = puVar15;
                  uVar21 = FUN_0063dcf6((uint32_t**)&local_34);
                  puVar12 = (uint32_t*)(uintptr_t)(uVar21 >> 0x20);
                  if ((int32_t)uVar21 != 0) {
                    local_34 = puVar15;
                    uVar8 = FUN_0063dc77((uint32_t**)&local_34, 4);
                    local_40[0xc] = local_40[0xc] | 0x10;
                    local_40[0x17] = ((uint32_t)local_28[3] << 16) | local_28[2];
                    uVar17 = (uint32_t)*(uint16_t*)(local_58 + 2);
                    if (uVar8 < *(uint16_t*)(local_58 + 2)) {
                      uVar17 = uVar8;
                    }
                    local_40[0x18] = uVar17 << 4;
                    puVar12 = local_40;
                    piVar10 = local_58;
                  }
                }
              }
            }
LAB_0064a73c:
            *(uint16_t*)((uint8_t*)puVar12 + 0x52) = 0x94;
            puVar12[0x16] = 0xc000000;
            local_34 = (uint32_t*)(uintptr_t)((uint32_t)*(uint16_t*)
                                             ((uint8_t*)piVar10 + 6) * 0x10);
            puVar12[0x12] = (uint32_t)(uintptr_t)local_34;
            if (piVar10[4] == 0) {
              puVar19 = (uint32_t*)(uintptr_t)(*piVar16 + (int32_t)(uintptr_t)local_34);
              for (iVar7 = (uint32_t)*(uint16_t*)(piVar10 + 2) << 2; iVar7 != 0;
                   iVar7 = iVar7 + -1) {
                *puVar19 = 0;
                puVar19 = puVar19 + 1;
              }
              for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                *(uint8_t*)puVar19 = 0;
                puVar19 = (uint32_t*)((uint8_t*)puVar19 + 1);
              }
            }
            else {
              puVar19 = (uint32_t*)(uintptr_t)(local_20 + piVar10[4]);
              puVar20 = (uint32_t*)(uintptr_t)(*piVar16 + (int32_t)(uintptr_t)local_34);
              for (iVar7 = (uint32_t)*(uint16_t*)(piVar10 + 2) << 2; iVar7 != 0;
                   iVar7 = iVar7 + -1) {
                *puVar20 = *puVar19;
                puVar19 = puVar19 + 1;
                puVar20 = puVar20 + 1;
              }
              for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                *(uint8_t*)puVar20 = *(uint8_t*)puVar19;
                puVar19 = (uint32_t*)((uint8_t*)puVar19 + 1);
                puVar20 = (uint32_t*)((uint8_t*)puVar20 + 1);
              }
            }
            if ((int8_t)piVar16[0xb] != '\0') {
              if (local_84 != (uint32_t*)0x0) {
                local_84[0xc] = local_84[0xc] & 0xfffffffe;
              }
              local_84 = puVar12;
            }
          }
          else if (sVar1 == 3) {
            *(uint16_t*)((uint8_t*)local_40 + 0x52) = 0xb2;
            local_40[0x16] = 0xf000000;
            uVar3 = *(uint16_t*)((uint8_t*)local_58 + 6);
            *(int16_t*)(local_40 + 0x15) = (int16_t)(*(int16_t*)(local_40 + 0x15) + 0x101);
            local_40[0xc] = local_40[0xc] & 0xfffffffd;
            local_40[0x12] = (uint32_t)(uintptr_t)(local_44 + uVar3);
            *local_40 = 0;
            if (puVar19 == (uint32_t*)0x0) {
              *(uint16_t*)(uintptr_t)(*piVar16 + local_40[0x12]) = 0;
              *(uint16_t*)(uintptr_t)(*piVar16 + 2 + local_40[0x12]) = 0;
            }
            else {
              *(int16_t*)(uintptr_t)(*piVar16 + local_40[0x12]) =
                (int16_t)(*(int16_t*)(puVar19 + 0x11) + 1);
              *(uint16_t*)(uintptr_t)(*piVar16 + 2 + local_40[0x12]) = 0;
              uVar3 = *(uint16_t*)((uint8_t*)puVar19 + 0x46);
              if (*(uint16_t*)((uint8_t*)local_40 + 0x56) <
                  *(uint16_t*)((uint8_t*)puVar19 + 0x46)) {
                uVar3 = *(uint16_t*)((uint8_t*)local_40 + 0x56);
              }
              *(uint16_t*)((uint8_t*)local_40 + 0x56) = (uint16_t)uVar3;
            }
            *(uint16_t*)(uintptr_t)(piVar16[5] +
                                    (uint32_t)*(uint16_t*)(piVar16 + 0xd) * 2 + *piVar16) =
              (uint16_t)(uintptr_t)local_10;
            *(int16_t*)(piVar16 + 0xd) = (int16_t)(piVar16[0xd] + 1);
          }
          local_3c = (int32_t*)((uintptr_t)local_3c + 1);
        } while (local_3c < *(int32_t**)((uint8_t*)(uintptr_t)local_20 + 0xc));
        uVar3 = (uint16_t)(uintptr_t)local_8;
      }
      *(uint16_t*)((uint8_t*)piVar16 + 0x4e) = (uint16_t)uVar3;
      *(int16_t*)(piVar16 + 0x15) = (int16_t)(uintptr_t)local_1c;
      *(int16_t*)((uint8_t*)piVar16 + 0x5a) = (int16_t)(uintptr_t)local_2c;
      *(uint16_t*)(piVar16 + 0x18) = (uint16_t)(uintptr_t)local_14;
      goto LAB_0064a997;
    }
  }
LAB_0064a8e0:
  local_18 = -0x7ff8fff2;
LAB_0064a997:
  operator_delete(local_60);
  return local_18;
}

// 0x64bedf — observed shape: execute one pending 0x64 sub-record command.
// The tag byte at record[0x16] (>>24) drives a large dispatch; the low 24 bits
// pick the sub-command. Pre-processing handles tags 0xc..0x11 (blit through
// FUN_00645033/FUN_006453ee/FUN_006457f4 and the 0x94..0x96 chains), then the
// switch at LAB_0064c4b7 issues the renderer vtable calls and the
// 0x7000000/0x800000x parameter writes.
// NEEDS_MANUAL: one x87 `ftol()` conversion (case 0xf/0x10 range) has no
// visible operand in the listing; preserved as an extern call.
int32_t FUN_0064bedf(void* self, uint32_t param_1, int32_t* param_2, uint32_t param_3)
{
  uint16_t uVar1;
  int32_t* piVar2;
  int32_t iVar3;
  int32_t iVar4;
  uint32_t* puVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  int32_t iVar8;
  uint16_t* puVar9;
  int32_t iVar10;
  uint16_t* puVar11;
  int32_t* piVar12;
  uint32_t* puVar13;
  uint32_t* puVar14;
  uint8_t local_15c[61];
  uint8_t local_11f;
  int32_t local_2c;
  uint32_t local_28;
  uint32_t local_24;
  uint32_t local_20;
  uint32_t local_1c;
  uint32_t local_18;
  uint32_t local_14;
  uint32_t local_10;
  int32_t* local_c;
  int32_t local_8;

  uint8_t* base = (uint8_t*)self;
  uint8_t* vtObj = *(uint8_t**)(base + 8);
  uint8_t* vt = *(uint8_t**)vtObj;

  local_8 = 0;
  local_10 = param_1 & 0xffff;
  piVar12 = (int32_t*)((uintptr_t)local_10 * 100 + *(int32_t*)(base + 0x2c));
  local_c = (int32_t*)(((uint32_t)(uintptr_t)param_2 & 0xffff) * 100 + piVar12[1]);
  if ((int16_t)param_3 == -1) {
    param_3 = (param_3 & 0xffff0000) | (uint16_t)local_c[0x15];
  }
  puVar11 = (uint16_t*)(uintptr_t)(local_c[0x12] + *piVar12);
  local_24 = (uint32_t)local_c[0x16];
  if (*local_c != 0) {
    uVar7 = local_24 >> 0x18;
    *local_c = local_c[1];
    if (0xd < uVar7) {
      if (uVar7 < 0xe) {
LAB_0064c49d:
        local_8 = FUN_00647678(local_10, (uint32_t)(uintptr_t)param_2 & 0xffff);
      }
      else {
        if (uVar7 < 0x10) {
          if (local_c[0xe] != 0) {
            local_8 = FUN_0064668b(local_10, (uint32_t)(uintptr_t)param_2 & 0xffff);
            if (local_8 < 0) {
              return local_8;
            }
            {
              int32_t* obj = (int32_t*)local_c[0xe];
              (*(int32_t (**)(int32_t*))(*(uint32_t*)obj + 0xc))(obj);
            }
            param_2 = (int32_t*)(uintptr_t)ftol();
            if (puVar11[1] != (uint16_t)(uintptr_t)param_2) {
              uVar7 = (uint32_t)(uintptr_t)param_2 & 0xffff;
              if (*(uint32_t*)(uintptr_t)(local_c[3] + 0x10) <= uVar7) {
                return -0x7fffbffb;
              }
              if (*(int16_t*)(base + 0x42) == *(int16_t*)(base + 0x40)) {
                iVar4 = -(int32_t)(uint32_t)*(uint16_t*)((uint8_t*)local_c + 0x56);
              }
              else {
                iVar4 = 0;
              }
              local_8 = FUN_0063da83((uint32_t)(puVar11[1] - 1) + (uint32_t)*puVar11,
                                     ((uint32_t)(int32_t)(*(int16_t*)((uint8_t*)local_c + 0x56) >>
                                                          0xf) << 16) |
                                     (uint16_t)(-*(int16_t*)((uint8_t*)local_c + 0x56)),
                                     iVar4);
              if (local_8 < 0) {
                return local_8;
              }
              puVar11[1] = (uint16_t)(uintptr_t)param_2;
              if (*(int16_t*)(base + 0x42) == *(int16_t*)(base + 0x40)) {
                uVar1 = *(uint16_t*)((uint8_t*)local_c + 0x56);
              }
              else {
                uVar1 = 0;
              }
              local_8 = FUN_0063da83((uint32_t)(*puVar11 - 1) + uVar7,
                                     (int32_t)*(int16_t*)((uint8_t*)local_c + 0x56), uVar1);
              goto LAB_0064c4ac;
            }
            if ((*(uint8_t*)(base + 0x118) & 4) != 0) {
              return local_8;
            }
          }
          goto LAB_0064c4b7;
        }
        if ((uVar7 != 0x10) && (uVar7 != 0x11)) goto LAB_0064c49d;
        local_8 = FUN_0064680a(local_10, (uint32_t)(uintptr_t)param_2 & 0xffff);
      }
LAB_0064c4ac:
      if (local_8 < 0) {
        return local_8;
      }
      goto LAB_0064c4b7;
    }
    if (0xb < uVar7) {
      param_1 = 0xffffffff;
      local_2c = 0;
      local_28 = 0;
      if (local_c[0xe] == 0) {
        if (local_c[0xf] != 0) {
          local_28 = *(uint32_t*)(uintptr_t)(local_c[0xd] + 0x10);
          param_1 = *(uint32_t*)(uintptr_t)(*(int32_t*)(*(int32_t*)(base + 0xb0) +
                                                        local_c[7] * 4) + 0x4c);
          local_2c = local_c[0xf];
        }
      }
      else {
        local_8 = FUN_0064668b(local_10, (uint32_t)(uintptr_t)param_2 & 0xffff);
        if (local_8 < 0) {
          return local_8;
        }
        local_8 = FUN_0064369b(local_10, (uint32_t)(uintptr_t)param_2 & 0xffff);
        if (local_8 < 0) {
          return local_8;
        }
      }
      if (local_24 == 0xc000000) {
LAB_0064c359:
        FUN_00645033(local_c + 2, puVar11, *(uint16_t*)((uint8_t*)local_c + 0x56),
                     local_2c, (void*)(uintptr_t)local_28, (void**)&param_2, param_1);
      }
      else if (local_24 == 0xc010000) {
LAB_0064c336:
        FUN_006457f4(local_c + 2, puVar11, *(uint16_t*)((uint8_t*)local_c + 0x56),
                     local_2c, (void*)(uintptr_t)local_28, (void**)&param_2, param_1);
      }
      else {
        if (local_24 != 0xc020000) {
          if (local_24 == 0xd000000) goto LAB_0064c359;
          if (local_24 == 0xd010000) goto LAB_0064c336;
          if (local_24 != 0xd020000) goto LAB_0064c4b7;
        }
        FUN_006453ee(local_c + 2, puVar11, *(uint16_t*)((uint8_t*)local_c + 0x56),
                     local_2c, (void*)(uintptr_t)local_28, (void**)&param_2, param_1);
      }
      goto LAB_0064c4b7;
    }
    if (uVar7 == 3) {
      local_8 = FUN_00647678(local_10, (uint32_t)(uintptr_t)param_2 & 0xffff);
      if (local_8 < 0) {
        return local_8;
      }
      if ((*(int32_t*)(base + 0x3c) == 4) && ((int16_t)param_3 == -1)) {
        iVar4 = *(int32_t*)(uintptr_t)(*(int32_t*)(*(int32_t*)(base + 0xb0) +
                                                   (uint32_t)*(uint16_t*)((uint8_t*)piVar12 + 0x3e) *
                                                   4) + 0x34);
        if (iVar4 == 0) {
          return local_8;
        }
        iVar4 = *(int32_t*)(uintptr_t)(iVar4 + 0x18);
        do {
          iVar4 = *(int32_t*)(uintptr_t)(iVar4 + 0x1c);
          piVar2 = (int32_t*)(uintptr_t)((uint32_t)*(uint16_t*)((uint8_t*)(uintptr_t)iVar4 + 0x14) *
                                        100 + *(int32_t*)(base + 0x2c));
          iVar8 = (uint32_t)*(uint16_t*)((uint8_t*)(uintptr_t)iVar4 + 0x16) * 100 + piVar2[1];
          puVar9 = (uint16_t*)(uintptr_t)(*(int32_t*)((uint8_t*)(uintptr_t)iVar8 + 0x48) + *piVar2);
          if ((int16_t)piVar2[0xf] != 0) {
            param_3 = (uint32_t)puVar9[1];
            param_2 = (int32_t*)(uintptr_t)(uint32_t)*puVar9;
            if (((int32_t)(((uint32_t)(uintptr_t)param_2 - 1U) + param_3) <= (int32_t)local_10) &&
                ((int32_t)local_10 <
                 (int32_t)((uint32_t)*(uint16_t*)((uint8_t*)(uintptr_t)iVar8 + 0x56) +
                           (uint32_t)(uintptr_t)param_2 + -1 + param_3))) {
              local_8 = (*(int32_t (**)(void*, uint32_t, uint32_t, uint32_t))(vt + 0x114))
                          (vtObj,
                           (((uint32_t)*(uint16_t*)((uint8_t*)(uintptr_t)iVar8 + 0x54) -
                             (uint32_t)(uintptr_t)param_2) - param_3) + 1 + local_10,
                           local_24 & 0xffffff, *(uint32_t*)(uintptr_t)puVar11);
              if (local_8 < 0) {
                return local_8;
              }
            }
          }
          if (*(int32_t*)(uintptr_t)(iVar4 + 0x1c) ==
              *(int32_t*)(uintptr_t)(*(int32_t*)(*(int32_t*)(base + 0xb0) +
                                                 (uint32_t)*(uint16_t*)((uint8_t*)piVar12 + 0x3e) *
                                                 4) + 0x34)) {
            return local_8;
          }
        } while (true);
      }
      goto LAB_0064c4b7;
    }
    if (uVar7 == 9) {
      if ((*(int32_t*)(base + 0x3c) == 4) && ((int16_t)param_3 == -1)) {
        iVar4 = *(int32_t*)(uintptr_t)(*(int32_t*)(*(int32_t*)(base + 0xb0) +
                                                   (uint32_t)*(uint16_t*)((uint8_t*)piVar12 + 0x3e) *
                                                   4) + 0x34);
        if (iVar4 == 0) {
          return 0;
        }
        iVar4 = *(int32_t*)(uintptr_t)(iVar4 + 0x18);
        do {
          iVar4 = *(int32_t*)(uintptr_t)(iVar4 + 0x1c);
          piVar2 = (int32_t*)(uintptr_t)((uint32_t)*(uint16_t*)((uint8_t*)(uintptr_t)iVar4 + 0x14) *
                                        100 + *(int32_t*)(base + 0x2c));
          iVar8 = (uint32_t)*(uint16_t*)((uint8_t*)(uintptr_t)iVar4 + 0x16) * 100 + piVar2[1];
          puVar11 = (uint16_t*)(uintptr_t)(*(int32_t*)((uint8_t*)(uintptr_t)iVar8 + 0x48) +
                                          *piVar2);
          if ((int16_t)piVar2[0xf] != 0) {
            param_3 = (uint32_t)puVar11[1];
            param_2 = (int32_t*)(uintptr_t)(uint32_t)*puVar11;
            if (((int32_t)(((uint32_t)(uintptr_t)param_2 - 1U) + param_3) <= (int32_t)local_10) &&
               ((int32_t)local_10 <
                (int32_t)((uint32_t)*(uint16_t*)((uint8_t*)(uintptr_t)iVar8 + 0x56) +
                          (uint32_t)(uintptr_t)param_2 + -1 + param_3))) {
              iVar10 = *(int32_t*)(uintptr_t)(*(int32_t*)(*(int32_t*)(base + 0xb0) +
                                                          local_c[7] * 4) + 0x40);
              iVar3 = *(int32_t*)(uintptr_t)local_c[2];
              if (iVar10 != 0) {
                iVar3 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar10 + 8) + iVar3 * 4);
              }
              local_8 = (*(int32_t (**)(void*, uint32_t, uint32_t))(vt + 0x104))
                          (vtObj,
                           (((uint32_t)*(uint16_t*)((uint8_t*)(uintptr_t)iVar8 + 0x54) -
                             (uint32_t)(uintptr_t)param_2) - param_3) + 1 + local_10,
                           *(uint32_t*)(uintptr_t)(*(int32_t*)(base + 0x18) + 4 + iVar3 * 0x18));
              if (local_8 < 0) {
                return local_8;
              }
            }
          }
          if (*(int32_t*)(uintptr_t)(iVar4 + 0x1c) ==
              *(int32_t*)(uintptr_t)(*(int32_t*)(*(int32_t*)(base + 0xb0) +
                                                 (uint32_t)*(uint16_t*)((uint8_t*)piVar12 + 0x3e) *
                                                 4) + 0x34)) {
            return local_8;
          }
        } while (true);
      }
      goto LAB_0064c4b7;
    }
    if (uVar7 != 10) {
      if (uVar7 != 0xb) goto LAB_0064c49d;
      iVar4 = *(int32_t*)(uintptr_t)(*(int32_t*)(*(int32_t*)(base + 0xb0) + local_c[7] * 4) + 0x40);
      iVar8 = *(int32_t*)(uintptr_t)local_c[2];
      if (iVar4 != 0) {
        iVar8 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar4 + 8) + iVar8 * 4);
      }
      if (*(int32_t*)(uintptr_t)(*(int32_t*)(base + 0x18) + 4 + iVar8 * 0x18) != 0) {
        local_8 = FUN_0063da83(local_10, 0xffffffff,
                               (*(int16_t*)(base + 0x42) != *(int16_t*)(base + 0x40)) - 1);
        if (local_8 < 0) {
          return local_8;
        }
        local_8 = FUN_0064a9aa(self, local_10);
        goto LAB_0064bfca;
      }
      goto LAB_0064c4b7;
    }
    iVar4 = *(int32_t*)(uintptr_t)(*(int32_t*)(*(int32_t*)(base + 0xb0) + local_c[7] * 4) + 0x40);
    iVar8 = *(int32_t*)(uintptr_t)local_c[2];
    if (iVar4 != 0) {
      iVar8 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar4 + 8) + iVar8 * 4);
    }
    if (*(int32_t*)(uintptr_t)(*(int32_t*)(base + 0x18) + 4 + iVar8 * 0x18) == 0) goto LAB_0064c4b7;
    local_8 = FUN_0063da83(local_10, 0xffffffff,
                           (*(int16_t*)(base + 0x42) != *(int16_t*)(base + 0x40)) - 1);
    if (local_8 < 0) {
      return local_8;
    }
    local_8 = FUN_00649a50(self, local_10);
LAB_0064bfca:
    if (local_8 < 0) {
      return local_8;
    }
    local_8 = FUN_0063da83(local_10, 1,
                           *(int16_t*)(base + 0x42) == *(int16_t*)(base + 0x40));
    if (local_8 < 0) {
      return local_8;
    }
    uVar7 = 0xffff;
LAB_0064c003:
    local_8 = FUN_0064bdfa(self, param_1, uVar7);
    goto switchD_0064c4c9_default;
  }
LAB_0064c4b7:
  switch(local_24 >> 0x18) {
  case 1:
    local_8 = (*(int32_t (**)(void*, uint32_t, uint32_t))(vt + 0xe4))
                (vtObj, local_24 & 0xffffff, *(uint32_t*)(uintptr_t)puVar11);
    break;
  case 2:
    local_8 = (*(int32_t (**)(void*, uint32_t, uint32_t, uint32_t))(vt + 0x10c))
                (vtObj, param_3 & 0xffff, local_24 & 0xffffff,
                 *(uint32_t*)(uintptr_t)puVar11);
    break;
  case 3:
    if (*(int32_t*)(base + 0x3c) == 1) {
      return local_8;
    }
    local_8 = (*(int32_t (**)(void*, uint32_t, uint32_t, uint32_t))(vt + 0x114))
                (vtObj, param_3 & 0xffff, local_24 & 0xffffff,
                 *(uint32_t*)(uintptr_t)puVar11);
    break;
  case 4:
    local_8 = (*(int32_t (**)(void*, uint32_t))(vt + 0x13c))
                (vtObj, *(uint32_t*)(uintptr_t)puVar11);
    break;
  case 5:
    if (*(int32_t*)(base + 0x3c) == 1) {
      uVar6 = 2;
    }
    else {
      uVar6 = *(uint32_t*)(uintptr_t)puVar11;
    }
    local_8 = (*(int32_t (**)(void*, uint32_t))(vt + 0x164))(vtObj, uVar6);
    break;
  case 6:
    if (local_24 == 0x6000000) {
      iVar4 = 3;
    }
    else if (local_24 == 0x6000001) {
      iVar4 = 2;
    }
    else if (local_24 == 0x6000002) {
      iVar4 = (int32_t)(param_3 & 0xffff) + 0x100;
    }
    else {
      if (local_24 != 0x6000003) {
        return local_8;
      }
      iVar4 = (int32_t)(param_3 & 0xffff) + 0x10;
    }
    local_8 = (*(int32_t (**)(void*, int32_t, uint16_t*))(vt + 0xb0))(vtObj, iVar4, puVar11);
    break;
  case 7:
    puVar5 = (uint32_t*)(uintptr_t)((uint32_t)*(uint16_t*)(base + 0x42) * 0xb4 + 0x44 +
                                    *(int32_t*)(base + 0xa4));
    if (local_24 == 0x7000000) {
      puVar13 = puVar5;
LAB_0064c5f3:
      local_20 = *(uint32_t*)(uintptr_t)puVar11;
      local_1c = *(uint32_t*)((uint8_t*)puVar11 + 8);
      local_18 = *(uint32_t*)((uint8_t*)puVar11 + 0x10);
      local_14 = *(uint32_t*)((uint8_t*)puVar11 + 0x18);
      *puVar13 = local_20;
      puVar13[1] = local_1c;
      puVar13[2] = local_18;
      puVar13[3] = local_14;
    }
    else {
      if (local_24 == 0x7000001) {
        puVar13 = puVar5 + 4;
        goto LAB_0064c5f3;
      }
      if (local_24 == 0x7000002) {
        puVar13 = puVar5 + 8;
        goto LAB_0064c5f3;
      }
      if (local_24 == 0x7000003) {
        puVar13 = puVar5 + 0xc;
        goto LAB_0064c5f3;
      }
      if (local_24 == 0x7000004) {
        puVar5[0x10] = *(uint32_t*)(uintptr_t)puVar11;
      }
    }
    if (((*(uint8_t*)((uint8_t*)local_c + 0x30) & 1) == 0) &&
        ((*(uint8_t*)(base + 0x118) & 4) == 0)) {
      return local_8;
    }
    local_8 = (*(int32_t (**)(void*, uint32_t*))(vt + 0xc4))(vtObj, puVar5);
    break;
  case 8:
    if (local_24 == 0x800000d) {
      local_8 = (*(int32_t (**)(void*, uint32_t, uint32_t))(vt + 0xd4))
                  (vtObj, param_3 & 0xffff, *(uint32_t*)(uintptr_t)puVar11);
      break;
    }
    puVar5 = (uint32_t*)(uintptr_t)((uint32_t)*(uint16_t*)((uint8_t*)local_c + 0x26) * 0x68 +
                                    *(int32_t*)(uintptr_t)((uint32_t)*(uint16_t*)(base + 0x42) *
                                                           0xb4 + 0x40 + *(int32_t*)(base + 0xa4)));
    switch(local_24) {
    case 0x8000000:
      *puVar5 = *(uint32_t*)(uintptr_t)puVar11;
      break;
    case 0x8000001:
      puVar14 = puVar5 + 1;
      goto LAB_0064c682;
    case 0x8000002:
      puVar14 = puVar5 + 5;
      goto LAB_0064c682;
    case 0x8000003:
      puVar14 = puVar5 + 9;
LAB_0064c682:
      local_20 = *(uint32_t*)(uintptr_t)puVar11;
      local_1c = *(uint32_t*)((uint8_t*)puVar11 + 8);
      local_18 = *(uint32_t*)((uint8_t*)puVar11 + 0x10);
      local_14 = *(uint32_t*)((uint8_t*)puVar11 + 0x18);
      puVar13 = puVar14 + 1;
      *puVar14 = local_20;
LAB_0064c6c5:
      *puVar13 = local_1c;
      puVar13[1] = local_18;
      puVar13[2] = local_14;
      break;
    case 0x8000004:
      puVar13 = puVar5 + 0xd;
      goto LAB_0064c6b1;
    case 0x8000005:
      puVar13 = puVar5 + 0x10;
LAB_0064c6b1:
      local_1c = *(uint32_t*)(uintptr_t)puVar11;
      local_18 = *(uint32_t*)((uint8_t*)puVar11 + 8);
      local_14 = *(uint32_t*)((uint8_t*)puVar11 + 0x10);
      goto LAB_0064c6c5;
    case 0x8000006:
      puVar5[0x13] = *(uint32_t*)(uintptr_t)puVar11;
      break;
    case 0x8000007:
      puVar5[0x14] = *(uint32_t*)(uintptr_t)puVar11;
      break;
    case 0x8000008:
      puVar5[0x15] = *(uint32_t*)(uintptr_t)puVar11;
      break;
    case 0x8000009:
      puVar5[0x16] = *(uint32_t*)(uintptr_t)puVar11;
      break;
    case 0x800000a:
      puVar5[0x17] = *(uint32_t*)(uintptr_t)puVar11;
      break;
    case 0x800000b:
      puVar5[0x18] = *(uint32_t*)(uintptr_t)puVar11;
      break;
    case 0x800000c:
      puVar5[0x19] = *(uint32_t*)(uintptr_t)puVar11;
    }
    if (((*(uint8_t*)((uint8_t*)local_c + 0x30) & 1) == 0) &&
        ((*(uint8_t*)(base + 0x118) & 4) == 0)) {
      return local_8;
    }
    if (*(int32_t*)(base + 0x3c) == 1) {
      local_1c = 0;
      *puVar5 = 3;
      local_18 = 0;
      local_14 = 0x3f800000;
      puVar5[0x10] = 0;
      puVar5[0x11] = 0;
      puVar5[0x12] = 0x3f800000;
    }
    local_8 = (*(int32_t (**)(void*, uint32_t, uint32_t*))(vt + 0xcc))
                (vtObj, param_3 & 0xffff, puVar5);
    break;
  case 9:
    if (*(int32_t*)(base + 0x3c) == 2) {
      uint8_t* objC = *(uint8_t**)(base + 0xc);
      local_8 = (*(int32_t (**)(void*, uint8_t*))(*(uint8_t**)objC + 0x1c))(objC, local_15c);
      if (local_8 < 0) {
        return local_8;
      }
      if (*(int32_t*)(uintptr_t)local_c[3] == 8) {
        local_11f = local_11f & 0x20;
      }
      else {
        if (*(int32_t*)(uintptr_t)local_c[3] != 9) goto LAB_0064c7ad;
        local_11f = local_11f & 8;
      }
      if (local_11f == 0) {
        return -0x7fffbffb;
      }
    }
LAB_0064c7ad:
    iVar4 = *(int32_t*)(uintptr_t)(*(int32_t*)(*(int32_t*)(base + 0xb0) + local_c[7] * 4) + 0x40);
    iVar8 = *(int32_t*)(uintptr_t)local_c[2];
    if (iVar4 != 0) {
      iVar8 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar4 + 8) + iVar8 * 4);
    }
    local_8 = (*(int32_t (**)(void*, uint32_t, uint32_t))(vt + 0x104))
                (vtObj, param_3 & 0xffff,
                 *(uint32_t*)(uintptr_t)(*(int32_t*)(base + 0x18) + 4 + iVar8 * 0x18));
    break;
  case 10:
    if (*(int32_t*)(base + 0x3c) == 1) {
      return local_8;
    }
    if (*(int32_t*)(base + 0x3c) == 2) {
      iVar4 = *(int32_t*)(uintptr_t)(*(int32_t*)(*(int32_t*)(base + 0xb0) + local_c[7] * 4) + 0x40);
      iVar8 = *(int32_t*)(uintptr_t)local_c[2];
      if (iVar4 == 0) {
        iVar10 = iVar8;
      }
      else {
        iVar10 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar4 + 8) + iVar8 * 4);
      }
      iVar3 = *(int32_t*)(base + 0x18);
      if ((*(uint8_t*)(uintptr_t)(iVar3 + 0x14 + iVar10 * 0x18) & 2) == 0) {
        return -0x7fffbffb;
      }
      if (iVar4 == 0) {
        iVar10 = iVar8;
      }
      else {
        iVar10 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar4 + 8) + iVar8 * 4);
      }
      if (*(int32_t*)(uintptr_t)(iVar3 + 4 + iVar10 * 0x18) == 0) {
LAB_0064c882:
        uVar6 = 0;
      }
      else {
        if (iVar4 == 0) {
          iVar10 = iVar8;
        }
        else {
          iVar10 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar4 + 8) + iVar8 * 4);
        }
        if (*(int32_t*)(uintptr_t)(iVar3 + 8 + iVar10 * 0x18) == 0) goto LAB_0064c882;
        if (iVar4 != 0) {
          iVar8 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar4 + 8) + iVar8 * 4);
        }
        piVar12 = *(int32_t**)(uintptr_t)(*(int32_t*)(base + 0x18) + 8 + iVar8 * 0x18);
        uVar6 = (*(uint32_t (**)(int32_t*))(*(uint32_t*)piVar12 + 0xc))(piVar12);
      }
      local_8 = FUN_0063db6f(uVar6);
      if (local_8 < 0) {
        return local_8;
      }
    }
    iVar4 = *(int32_t*)(uintptr_t)(*(int32_t*)(*(int32_t*)(base + 0xb0) + local_c[7] * 4) + 0x40);
    if (iVar4 == 0) {
      iVar4 = *(int32_t*)(uintptr_t)local_c[2];
    }
    else {
      iVar4 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar4 + 8) +
                                     *(int32_t*)(uintptr_t)local_c[2] * 4);
    }
    local_8 = (*(int32_t (**)(void*, uint32_t))(vt + 0x170))
                (vtObj, *(uint32_t*)(uintptr_t)(*(int32_t*)(base + 0x18) + 4 + iVar4 * 0x18));
    break;
  case 0xb:
    if (*(int32_t*)(base + 0x3c) == 1) {
      return local_8;
    }
    if (*(int32_t*)(base + 0x3c) == 2) {
      iVar4 = *(int32_t*)(uintptr_t)(*(int32_t*)(*(int32_t*)(base + 0xb0) + local_c[7] * 4) + 0x40);
      if (iVar4 == 0) {
        iVar4 = *(int32_t*)(uintptr_t)local_c[2];
      }
      else {
        iVar4 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar4 + 8) +
                                       *(int32_t*)(uintptr_t)local_c[2] * 4);
      }
      if ((*(uint8_t*)(uintptr_t)(*(int32_t*)(base + 0x18) + 0x14 + iVar4 * 0x18) & 2) == 0) {
        return -0x7fffbffb;
      }
    }
    iVar4 = *(int32_t*)(uintptr_t)(*(int32_t*)(*(int32_t*)(base + 0xb0) + local_c[7] * 4) + 0x40);
    iVar8 = *(int32_t*)(uintptr_t)local_c[2];
    if (iVar4 != 0) {
      iVar8 = *(int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar4 + 8) + iVar8 * 4);
    }
    local_8 = (*(int32_t (**)(void*, uint32_t))(vt + 0x1ac))
                (vtObj, *(uint32_t*)(uintptr_t)(*(int32_t*)(base + 0x18) + 4 + iVar8 * 0x18));
    break;
  case 0xc:
    if (*(int32_t*)(base + 0x3c) == 1) {
      return local_8;
    }
    iVar4 = *(int32_t*)(base + 0x118) << 0x1d;
    if ((-1 < iVar4) && ((*(uint8_t*)((uint8_t*)local_c + 0x30) & 1) == 0)) {
      return local_8;
    }
    if (local_24 == 0xc000000) {
      if ((((int8_t)piVar12[0xb] == '\0') || (iVar4 < 0)) ||
          ((*(uint8_t*)((uint8_t*)local_c + 0x30) & 1) == 0)) {
        uVar1 = *(uint16_t*)((uint8_t*)local_c + 0x56);
        uVar7 = param_3 & 0xffff;
      }
      else {
        uVar1 = (uint16_t)piVar12[7];
        puVar11 = puVar11 + (uintptr_t)(uint32_t)*(uint16_t*)((uint8_t*)local_c + 0x54) * -8;
        uVar7 = 0;
      }
      local_8 = (*(int32_t (**)(void*, uint32_t, uint16_t*, uint16_t))(vt + 0x178))
                  (vtObj, uVar7, puVar11, uVar1);
    }
    else if (local_24 == 0xc010000) {
      if (((*(int8_t*)((uint8_t*)piVar12 + 0x2d) == '\0') || (iVar4 < 0)) ||
         ((*(uint8_t*)((uint8_t*)local_c + 0x30) & 1) == 0)) {
        uVar1 = *(uint16_t*)((uint8_t*)local_c + 0x56);
        uVar7 = param_3 & 0xffff;
      }
      else {
        uVar1 = *(uint16_t*)((uint8_t*)piVar12 + 0x1e);
        puVar11 = puVar11 + (uintptr_t)(uint32_t)*(uint16_t*)((uint8_t*)local_c + 0x54) * -2;
        uVar7 = 0;
      }
      local_8 = FUN_0063d6bb(*(uint32_t*)(base + 8), uVar7, (uint32_t)(uintptr_t)puVar11, uVar1);
    }
    else {
      if (local_24 != 0xc020000) {
        return local_8;
      }
      if (((*(int8_t*)((uint8_t*)piVar12 + 0x2e) == '\0') || (iVar4 < 0)) ||
         ((*(uint8_t*)((uint8_t*)local_c + 0x30) & 1) == 0)) {
        uVar1 = *(uint16_t*)((uint8_t*)local_c + 0x56);
        uVar7 = param_3 & 0xffff;
      }
      else {
        uVar1 = (uint16_t)piVar12[8];
        puVar11 = puVar11 + (uintptr_t)(uint32_t)*(uint16_t*)((uint8_t*)local_c + 0x54) * -8;
        uVar7 = 0;
      }
      local_8 = (*(int32_t (**)(void*, uint32_t, uint16_t*, uint16_t))(vt + 0x180))
                  (vtObj, uVar7, puVar11, uVar1);
    }
    break;
  case 0xd:
    if (*(int32_t*)(base + 0x3c) == 1) {
      return local_8;
    }
    iVar4 = *(int32_t*)(base + 0x118) << 0x1d;
    if ((-1 < iVar4) && ((*(uint8_t*)((uint8_t*)local_c + 0x30) & 1) == 0)) {
      return local_8;
    }
    if (local_24 == 0xd000000) {
      if ((((int8_t)piVar12[0xc] == '\0') || (iVar4 < 0)) ||
          ((*(uint8_t*)((uint8_t*)local_c + 0x30) & 1) == 0)) {
        uVar1 = *(uint16_t*)((uint8_t*)local_c + 0x56);
        uVar7 = param_3 & 0xffff;
      }
      else {
        uVar1 = (uint16_t)piVar12[9];
        puVar11 = puVar11 + (uintptr_t)(uint32_t)*(uint16_t*)((uint8_t*)local_c + 0x54) * -8;
        uVar7 = 0;
      }
      local_8 = (*(int32_t (**)(void*, uint32_t, uint16_t*, uint16_t))(vt + 0x1b4))
                  (vtObj, uVar7, puVar11, uVar1);
    }
    else if (local_24 == 0xd010000) {
      if (((*(int8_t*)((uint8_t*)piVar12 + 0x31) == '\0') || (iVar4 < 0)) ||
         ((*(uint8_t*)((uint8_t*)local_c + 0x30) & 1) == 0)) {
        uVar1 = *(uint16_t*)((uint8_t*)local_c + 0x56);
        uVar7 = param_3 & 0xffff;
      }
      else {
        uVar1 = *(uint16_t*)((uint8_t*)piVar12 + 0x26);
        puVar11 = puVar11 + (uintptr_t)(uint32_t)*(uint16_t*)((uint8_t*)local_c + 0x54) * -2;
        uVar7 = 0;
      }
      local_8 = (*(int32_t (**)(void*, uint32_t, uint16_t*, uint16_t))(vt + 0x1c4))
                  (vtObj, uVar7, puVar11, uVar1);
    }
    else {
      if (local_24 != 0xd020000) {
        return local_8;
      }
      if (((*(int8_t*)((uint8_t*)piVar12 + 0x32) == '\0') || (iVar4 < 0)) ||
         ((*(uint8_t*)((uint8_t*)local_c + 0x30) & 1) == 0)) {
        uVar1 = *(uint16_t*)((uint8_t*)local_c + 0x56);
        uVar7 = param_3 & 0xffff;
      }
      else {
        uVar1 = (uint16_t)piVar12[10];
        puVar11 = puVar11 + (uintptr_t)(uint32_t)*(uint16_t*)((uint8_t*)local_c + 0x54) * -8;
        uVar7 = 0;
      }
      local_8 = (*(int32_t (**)(void*, uint32_t, uint16_t*, uint16_t))(vt + 0x1bc))
                  (vtObj, uVar7, puVar11, uVar1);
    }
    break;
  case 0xe:
    if (*puVar11 == 0) {
      return local_8;
    }
    if (*(int32_t*)(base + 0x3c) != 4) {
      iVar4 = FUN_0064bdfa(self, (uint32_t)(uint16_t)(puVar11[1] + *puVar11) - 1, 0xffff);
      return iVar4;
    }
    iVar4 = (int32_t)(puVar11[1] - 1) + (uint32_t)*puVar11;
    iVar8 = iVar4 * 100 + *(int32_t*)(base + 0x2c);
    if ((*(uint8_t*)(uintptr_t)(iVar8 + 8) & 1) == 0) {
      FUN_0064bdfa(self, (uint32_t)iVar4, 0xffff);
      return local_8;
    }
    FUN_0064ba56(self, iVar8);
    return local_8;
  case 0xf:
    if (*puVar11 == 0) {
      return local_8;
    }
    if (*(int32_t*)(base + 0x3c) == 4) {
      local_8 = FUN_0064b919(self, piVar12, (uint32_t)(uintptr_t)local_c,
                             (uint32_t)(uintptr_t)(local_c + 0x19));
      break;
    }
    param_1 = (uint32_t)(uint16_t)(puVar11[1] + *puVar11) - 1;
    uVar7 = param_3;
    goto LAB_0064c003;
  case 0x10:
    {
      int32_t* obj0e = (int32_t*)local_c[0xe];
      iVar4 = (*(int32_t (**)(int32_t*))(*(uint32_t*)obj0e + 0xc))(obj0e);
    }
    if (*(int32_t*)(uintptr_t)(iVar4 + 0x4c) != 0) {
      iVar8 = *(int32_t*)(uintptr_t)(iVar4 + 0x28);
      iVar10 = *piVar12;
      param_2 = (int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar4 + 0x5c) + iVar4);
      param_3 = *(uint32_t*)(uintptr_t)param_2;
      param_2 = param_2 + 1;
      if (param_3 != 0) {
        do {
          local_8 = (*(int32_t (**)(void*, int32_t, uint32_t, int32_t))(vt + 0x178))
                      (vtObj, *param_2, *param_2 * 0x10 + iVar8 + iVar10, param_2[1]);
          param_2 = param_2 + 2;
          param_3 = param_3 + -1;
        } while (param_3 != 0);
      }
    }
    if (*(int32_t*)(uintptr_t)(iVar4 + 0x50) != 0) {
      iVar8 = *(int32_t*)(uintptr_t)(iVar4 + 0x2c);
      iVar10 = *piVar12;
      param_2 = (int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar4 + 0x60) + iVar4);
      param_3 = *(uint32_t*)(uintptr_t)param_2;
      param_2 = param_2 + 1;
      if (param_3 != 0) {
        do {
          local_8 = (*(int32_t (**)(void*, int32_t, uint32_t, int32_t))(vt + 0x188))
                      (vtObj, *param_2, iVar8 + iVar10 + *param_2 * 4, param_2[1]);
          param_2 = param_2 + 2;
          param_3 = param_3 + -1;
        } while (param_3 != 0);
      }
    }
    if (*(int32_t*)(uintptr_t)(iVar4 + 0x54) == 0) {
      return local_8;
    }
    param_3 = (uint32_t)(*(int32_t*)(uintptr_t)(iVar4 + 0x30) + *piVar12);
    piVar12 = (int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar4 + 100) + iVar4);
    param_2 = (int32_t*)(uintptr_t)*piVar12;
    piVar12 = piVar12 + 1;
    if (param_2 == (int32_t*)0x0) {
      return local_8;
    }
    do {
      local_8 = (*(int32_t (**)(void*, int32_t, uint32_t, int32_t))(vt + 0x1bc))
                  (vtObj, *piVar12, *piVar12 * 0x10 + param_3, piVar12[1]);
      piVar12 = piVar12 + 2;
      param_2 = (int32_t*)((uintptr_t)param_2 + -1);
    } while (param_2 != (int32_t*)0x0);
    return local_8;
  case 0x11:
    {
      int32_t* obj0e = (int32_t*)local_c[0xe];
      iVar4 = (*(int32_t (**)(int32_t*))(*(uint32_t*)obj0e + 0xc))(obj0e);
    }
    if (*(int32_t*)(uintptr_t)(iVar4 + 0x4c) != 0) {
      iVar8 = *(int32_t*)(uintptr_t)(iVar4 + 0x28);
      iVar10 = *piVar12;
      param_2 = (int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar4 + 0x5c) + iVar4);
      param_3 = *(uint32_t*)(uintptr_t)param_2;
      param_2 = param_2 + 1;
      if (param_3 != 0) {
        do {
          local_8 = (*(int32_t (**)(void*, int32_t, uint32_t, int32_t))(vt + 0x1b4))
                      (vtObj, *param_2, *param_2 * 0x10 + iVar8 + iVar10, param_2[1]);
          param_2 = param_2 + 2;
          param_3 = param_3 + -1;
        } while (param_3 != 0);
      }
    }
    if (*(int32_t*)(uintptr_t)(iVar4 + 0x50) != 0) {
      iVar8 = *(int32_t*)(uintptr_t)(iVar4 + 0x2c);
      iVar10 = *piVar12;
      param_2 = (int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar4 + 0x60) + iVar4);
      param_3 = *(uint32_t*)(uintptr_t)param_2;
      param_2 = param_2 + 1;
      if (param_3 != 0) {
        do {
          local_8 = (*(int32_t (**)(void*, int32_t, uint32_t, int32_t))(vt + 0x1c4))
                      (vtObj, *param_2, iVar8 + iVar10 + *param_2 * 4, param_2[1]);
          param_2 = param_2 + 2;
          param_3 = param_3 + -1;
        } while (param_3 != 0);
      }
    }
    if (*(int32_t*)(uintptr_t)(iVar4 + 0x54) != 0) {
      param_3 = (uint32_t)(*(int32_t*)(uintptr_t)(iVar4 + 0x30) + *piVar12);
      piVar12 = (int32_t*)(uintptr_t)(*(int32_t*)(uintptr_t)(iVar4 + 100) + iVar4);
      param_2 = (int32_t*)(uintptr_t)*piVar12;
      piVar12 = piVar12 + 1;
      if (param_2 != (int32_t*)0x0) {
        do {
          local_8 = (*(int32_t (**)(void*, int32_t, uint32_t, int32_t))(vt + 0x1bc))
                      (vtObj, *piVar12, *piVar12 * 0x10 + param_3, piVar12[1]);
          piVar12 = piVar12 + 2;
          param_2 = (int32_t*)((uintptr_t)param_2 + -1);
        } while (param_2 != (int32_t*)0x0);
      }
    }
  }
switchD_0064c4c9_default:
  return local_8;
}

// 0x64a9aa — observed shape: sibling of FUN_00649a50 for the alternate sprite
// bank (counts packed at 0x24/0x26/0x28/0x2a, tags 0x9c..0x9e / 0xd0xxxxxx and
// stage tag 0xb5). Verifies the 0x18-byte descriptor, releases cached surfaces,
// parses the PRES/PRSI resource, fills the packed vertex/index buffers and
// materialises the entry table. Returns 0 or a negative HRESULT.
int32_t FUN_0064a9aa(void* self, uint32_t param_1)
{
  int16_t sVar1;
  uint16_t uVar2;
  uint16_t uVar3;
  int32_t iVar4;
  int32_t iVar5;
  uint32_t uVar6;
  int32_t iVar7;
  uint32_t uVar8;
  int32_t* piVar9;
  int16_t* psVar10;
  uint32_t* puVar11;
  uint32_t* puVar12;
  uint8_t cVar13;
  uint32_t* puVar14;
  int32_t* piVar15;
  uint32_t uVar16;
  uint32_t uVar17;
  uint32_t* puVar18;
  uint32_t* puVar19;
  uint64_t uVar20;
  uint16_t* puVar21;
  uint32_t uVar22;
  uint32_t** ppuVar23;
  uint8_t local_88[4];
  uint32_t* local_84;
  uint32_t* local_80;
  uint32_t* local_7c;
  uint32_t uStack_78;
  uint16_t local_74[4];
  int16_t local_6c[2];
  uint32_t* local_68;
  uint32_t local_64;
  void* local_60;
  uint8_t local_5c[4];
  uint32_t* local_58;
  int32_t local_50;
  uint32_t* local_4c;
  uint32_t* local_48;
  uint32_t* local_44;
  uint32_t* local_40;
  uint32_t* local_3c;
  uint8_t local_38[4];
  uint32_t* local_34;
  uint32_t* local_30;
  uint32_t* local_2c;
  uint16_t local_28[4];
  uint32_t local_20;
  uint32_t* local_1c;
  int32_t local_18;
  uint32_t* local_14;
  uint32_t* local_10;
  uint32_t* local_c;
  uint32_t* local_8;

  uint8_t* base = (uint8_t*)self;

  piVar15 = (int32_t*)((uintptr_t)param_1 * 100 + *(int32_t*)(base + 0x2c));
  iVar7 = piVar15[1];
  iVar4 = *(int32_t*)((uint8_t*)(uintptr_t)iVar7 + 0x1c) * 4;
  local_18 = 0;
  local_60 = (void*)0x0;
  if (*(int32_t*)(*(int32_t*)((uint8_t*)(uintptr_t)(iVar4 + *(int32_t*)(base + 0xb0))) + 0x40) == 0) {
    iVar5 = *(int32_t*)(base + 0x20);
  }
  else {
    iVar5 = *(int32_t*)(*(int32_t*)(base + 0x38) + 0x10);
  }
  *(int32_t*)((uint8_t*)(uintptr_t)iVar7 + 8) =
    *(int32_t*)(*(int32_t*)((uint8_t*)(uintptr_t)(iVar4 + *(int32_t*)(base + 0xb0))) + 0x30) +
    *(int32_t*)((uint8_t*)(uintptr_t)iVar7 + 0x24) + iVar5;
  iVar7 = piVar15[1];
  iVar4 = *(int32_t*)((uint8_t*)(uintptr_t)iVar7 + 0x1c) * 4;
  if (*(int32_t*)(*(int32_t*)((uint8_t*)(uintptr_t)(iVar4 + *(int32_t*)(base + 0xb0))) + 0x40) == 0) {
    local_10 = (uint32_t*)(uintptr_t)*(int32_t*)(base + 0x20);
  }
  else {
    local_10 = *(uint32_t**)(*(int32_t*)(base + 0x38) + 0x10);
  }
  *(int32_t*)((uint8_t*)(uintptr_t)iVar7 + 0xc) =
    *(int32_t*)(*(int32_t*)((uint8_t*)(uintptr_t)(iVar4 + *(int32_t*)(base + 0xb0))) + 0x2c) +
    *(int32_t*)((uint8_t*)(uintptr_t)iVar7 + 0x20) + (int32_t)(uintptr_t)local_10;
  iVar7 = piVar15[1];
  iVar5 = *(int32_t*)((uint8_t*)(uintptr_t)iVar7 + 0x1c) * 4;
  iVar4 = *(int32_t*)((uint8_t*)(uintptr_t)(iVar5 + *(int32_t*)(base + 0xb0)));
  if (*(int32_t*)(*(int32_t*)((uint8_t*)(uintptr_t)(iVar5 + *(int32_t*)(base + 0xb0))) + 0x40) == 0) {
    if (*(int32_t*)((uint8_t*)(uintptr_t)iVar4 + 0x40) == 0) {
      iVar5 = *(int32_t*)(base + 0x20);
    }
    else {
      iVar5 = *(int32_t*)(*(int32_t*)(base + 0x38) + 0x10);
    }
    iVar7 = *(int32_t*)(uintptr_t)(*(int32_t*)((uint8_t*)(uintptr_t)iVar4 + 0x30) +
                                   *(int32_t*)((uint8_t*)(uintptr_t)iVar7 + 0x24) + iVar5);
  }
  else {
    if (*(int32_t*)((uint8_t*)(uintptr_t)iVar4 + 0x40) == 0) {
      local_10 = (uint32_t*)(uintptr_t)*(int32_t*)(base + 0x20);
    }
    else {
      local_10 = *(uint32_t**)(*(int32_t*)(base + 0x38) + 0x10);
    }
    iVar4 = *(int32_t*)(uintptr_t)(*(int32_t*)(base + 0xb0) +
                                   *(int32_t*)((uint8_t*)(uintptr_t)iVar7 + 0x1c) * 4);
    iVar7 = *(int32_t*)(uintptr_t)(*(int32_t*)(*(int32_t*)((uint8_t*)(uintptr_t)iVar4 + 0x40) + 8) +
                                   *(int32_t*)(uintptr_t)(*(int32_t*)((uint8_t*)(uintptr_t)iVar7 +
                                                                     0x24) +
                                                          *(int32_t*)((uint8_t*)(uintptr_t)iVar4 +
                                                                      0x30) +
                                                          (int32_t)(uintptr_t)local_10) * 4);
  }
  iVar7 = *(int32_t*)(base + 0x18) + iVar7 * 0x18;
  if ((*(uint32_t*)((uint8_t*)(uintptr_t)iVar7 + 0x14) & 1) == 0) {
    if ((((*(uint8_t*)((uint8_t*)piVar15 + 8) & 8) != 0) && (*(int32_t*)(base + 0xb4) != 0)) &&
       ((*(uint8_t*)(base + 0x119) & 8) == 0)) {
      local_44 = (uint32_t*)(uintptr_t)(*(int32_t*)(base + 0xac) * *(int32_t*)(base + 0xa0));
      local_1c = (uint32_t*)0x0;
      if (local_44 != (uint32_t*)0x0) {
        do {
          puVar14 = *(uint32_t**)((uintptr_t)local_1c * 4 + *(int32_t*)(base + 0xc0));
          if (puVar14 != (uint32_t*)0x0) {
            local_4c = *(uint32_t**)((uintptr_t)local_1c * 4 + *(int32_t*)(base + 0xb4));
            uVar16 = *puVar14;
            puVar12 = (uint32_t*)0x0;
            local_c = puVar14;
            if (uVar16 != 0) {
              do {
                if (*(uint16_t*)((uintptr_t)uVar16 + 0x14) == param_1) {
                  if ((puVar12 == (uint32_t*)0x0) && (puVar12 = local_4c, *local_4c != 0)) {
                    do {
                      local_4c = local_4c + 1;
                    } while (*local_4c != 0);
                    puVar12 = local_4c;
                  }
                  *puVar12 = uVar16;
                  puVar12 = puVar12 + 1;
                  *puVar12 = 0;
                }
                local_c = local_c + 1;
                uVar16 = *local_c;
              } while (uVar16 != 0);
            }
          }
          local_1c = (uint32_t*)((uintptr_t)local_1c + 1);
        } while (local_1c < local_44);
      }
      piVar15[2] = piVar15[2] & 0xfffffff7;
    }
    local_18 = 0;
    goto LAB_0064b906;
  }
  if (*(int32_t*)((uint8_t*)(uintptr_t)iVar7 + 4) == 0) {
    *(uint32_t*)((uint8_t*)(uintptr_t)iVar7 + 0x14) =
      *(uint32_t*)((uint8_t*)(uintptr_t)iVar7 + 0x14) | 2;
    *(uint32_t*)((uint8_t*)(uintptr_t)iVar7 + 0xc) = 0;
  }
  else {
    local_18 = FUN_00643f6c(iVar7);
    if (local_18 < 0) goto LAB_0064b906;
  }
  *(uint32_t*)((uint8_t*)(uintptr_t)iVar7 + 0x14) =
    *(uint32_t*)((uint8_t*)(uintptr_t)iVar7 + 0x14) & 0xfffffffe;
  local_20 = 1;
  if (1 < *(uint16_t*)((uint8_t*)piVar15 + 0x36)) {
    local_c = (uint32_t*)0x64;
    do {
      local_8 = (uint32_t*)(uintptr_t)(piVar15[1] + (int32_t)(uintptr_t)local_c);
      if ((*(int16_t*)((uint8_t*)local_8 + 0x52) == 0xb4) ||
          (*(int16_t*)((uint8_t*)local_8 + 0x52) == 0xb5)) {
        piVar9 = (int32_t*)local_8[0xe];
        if (piVar9 != (int32_t*)0x0) {
          (*(int32_t (**)(int32_t*))(*(uint32_t*)piVar9 + 8))(piVar9);
          local_8[0xe] = 0;
        }
        local_14 = (uint32_t*)0x0;
        if (*(int16_t*)((uint8_t*)local_8 + 0x4e) != 0) {
          do {
            local_18 = FUN_00643dfb(param_1, local_20, (uint32_t)(uintptr_t)local_14);
            if (local_18 < 0) goto LAB_0064b906;
            local_14 = (uint32_t*)((uintptr_t)local_14 + 1);
          } while (local_14 < (uint32_t*)(uintptr_t)(uint32_t)*(uint16_t*)
                             ((uint8_t*)local_8 + 0x4e));
        }
      }
      else if ((*(int16_t*)((uint8_t*)local_8 + 0x4e) != 0) &&
              (local_18 = FUN_00643dfb(param_1, local_20, 0), local_18 < 0)) goto LAB_0064b906;
      local_20 = local_20 + 1;
      local_c = local_c + 0x19;
      *(uint16_t*)((uint8_t*)local_8 + 0x4e) = 0;
    } while (local_20 < *(uint16_t*)((uint8_t*)piVar15 + 0x36));
  }
  puVar14 = (uint32_t*)0x0;
  local_84 = (uint32_t*)0x0;
  local_80 = (uint32_t*)0x0;
  local_7c = (uint32_t*)0x0;
  uStack_78 = 0;
  *(uint16_t*)((uint8_t*)piVar15 + 0x36) = 1;
  *(uint16_t*)(piVar15 + 0xd) = 0;
  *(uint16_t*)((uint8_t*)piVar15 + 0x1a) = 0;
  piVar15[9] = 0;
  piVar15[10] = 0;
  if ((*(uint8_t*)((uint8_t*)(uintptr_t)iVar7 + 0x14) & 2) == 0) goto LAB_0064b906;
  local_30 = (uint32_t*)0x0;
  local_48 = (uint32_t*)0x0;
  local_10 = (uint32_t*)0x1;
  local_c = (uint32_t*)0x1;
  if (*(int32_t*)((uint8_t*)(uintptr_t)iVar7 + 4) == 0) {
    puVar12 = (uint32_t*)((uint8_t*)(uintptr_t)iVar7 + 0xc);
    *puVar12 = 0;
    uVar16 = 0;
    local_28[0] = 0;
    local_28[1] = 0;
    piVar9 = piVar15 + 9;
    local_28[2] = 0;
    do {
      *(uint8_t*)(uintptr_t)(uVar16 + 0x30 + (uintptr_t)piVar15) = 0;
      *(uint16_t*)piVar9 = 0;
      uVar16 = uVar16 + 1;
      piVar9 = (int32_t*)((uint8_t*)piVar9 + 2);
    } while (uVar16 < 4);
    local_c = (uint32_t*)0x0;
    local_8 = puVar12;
  }
  else {
    piVar9 = &local_50;
    psVar10 = local_6c;
    puVar21 = local_74;
    puVar12 = (uint32_t*)((uint8_t*)(uintptr_t)iVar7 + 0xc);
    puVar14 = puVar12;
    local_8 = puVar12;
    {
      uint8_t* vtObj = *(uint8_t**)((uint8_t*)(uintptr_t)iVar7 + 8);
      uVar6 = (*(uint32_t (**)(void*, uint32_t*, uint16_t*, int16_t*, int32_t*))
               (*(uint8_t**)vtObj + 0xc))(vtObj, puVar12, puVar21, psVar10, piVar9);
    }
    local_18 = FUN_0063e055(uVar6, puVar14, puVar21, psVar10, piVar9);
    if (local_18 < 0) goto LAB_0064b906;
    piVar15[9] = local_50;
    piVar15[10] = (int32_t)(uintptr_t)local_4c;
    puVar14 = &local_64;
    ppuVar23 = &local_30;
    uVar22 = 0x53455250;
    {
      uint8_t* vtObj = *(uint8_t**)((uint8_t*)(uintptr_t)iVar7 + 8);
      uVar6 = (*(uint32_t (**)(void*, uint32_t, uint32_t**, uint32_t*))
               (*(uint8_t**)vtObj + 0xc))(vtObj, 0x53455250, ppuVar23, puVar14);
    }
    local_18 = FUN_005f7ad0(uVar6, uVar22, ppuVar23, puVar14);
    if (local_18 < 0) {
      return local_18;
    }
    if (local_18 == 0) {
      local_10 = (uint32_t*)0x2;
      iVar7 = FUN_005f7ad0((uint32_t)(uintptr_t)local_30, 0x49535250,
                           (uint32_t*)&local_48, local_88);
      if (iVar7 < 0) {
        return iVar7;
      }
      local_18 = FUN_0063e055((uint32_t)(uintptr_t)local_30, (uint32_t*)&local_44, local_5c,
                              local_38, local_28);
      if (local_18 < 0) {
        return local_18;
      }
      uVar16 = 0;
      do {
        uVar8 = uVar16 + 1;
        local_28[uVar16] = (uint16_t)((int16_t)local_48[uVar16 + 3] + (int16_t)local_48[uVar16]);
        uVar16 = uVar8;
      } while (uVar8 < 3);
    }
    else {
      local_28[0] = 0;
      local_28[1] = 0;
      local_28[2] = 0;
      puVar12 = local_8;
    }
    piVar9 = piVar15 + 0xc;
    uVar16 = 0;
    puVar14 = local_c;
    do {
      if ((*(int16_t*)((uintptr_t)local_6c + uVar16) == 0) &&
         (*(int16_t*)((uintptr_t)local_38 + (uVar16 - 0x18)) ==
          *(int16_t*)((uintptr_t)local_74 + uVar16))) {
        cVar13 = '\x01';
      }
      else {
        cVar13 = '\0';
      }
      sVar1 = *(int16_t*)((uintptr_t)local_74 + uVar16);
      *(uint8_t*)piVar9 = cVar13;
      if ((sVar1 != 0) && (cVar13 == '\0')) {
        puVar14 = (uint32_t*)0x0;
      }
      piVar9 = (int32_t*)((uint8_t*)piVar9 + 1);
      uVar16 = uVar16 + 2;
    } while (uVar16 < 8);
  }
  local_28[3] = 0;
  local_20 = *puVar12;
  *(uint16_t*)((uint8_t*)piVar15 + 0x4e) = 1;
  *(uint16_t*)(piVar15 + 0x15) = 1;
  *(uint16_t*)((uint8_t*)piVar15 + 0x5a) = 1;
  *(uint16_t*)((uint8_t*)piVar15 + 0x60) = 1;
  *(uint16_t*)(piVar15 + 0x13) = 1;
  *(uint16_t*)((uint8_t*)piVar15 + 0x52) = 1;
  *(uint16_t*)(piVar15 + 0x16) = 1;
  *(uint16_t*)((uint8_t*)piVar15 + 0x5e) = 1;
  *(int16_t*)(piVar15 + 0x14) = (int16_t)piVar15[9];
  *(int16_t*)((uint8_t*)piVar15 + 0x56) = (int16_t)piVar15[10];
  uVar16 = piVar15[2] & 0xfffffffaU | (uint32_t)puVar14 & 1;
  piVar15[2] = uVar16;
  *(uint16_t*)(piVar15 + 0x17) = *(uint16_t*)((uint8_t*)piVar15 + 0x26);
  if (*puVar12 == 0) goto LAB_0064b906;
  piVar15[2] = uVar16 | 8;
  uVar16 = (uint32_t)(*(int32_t*)((uint8_t*)(uintptr_t)local_20 + 0xc) +
                      (int32_t)(uintptr_t)local_10);
  if (*(uint16_t*)(piVar15 + 0xe) < uVar16) {
    puVar14 = (uint32_t*)FUN_00533c78(uVar16 * 100 + 4);
    if (puVar14 == (uint32_t*)0x0) {
      local_14 = (uint32_t*)0x0;
    }
    else {
      *puVar14 = uVar16;
      FUN_004127b0(puVar14 + 1, 100, uVar16, &LAB_00646b1e);
      local_14 = puVar14 + 1;
    }
    if (local_14 != (uint32_t*)0x0) {
      uVar3 = *(uint16_t*)((uint8_t*)(uintptr_t)piVar15[1] + 0x52);
      *(uint16_t*)((uint8_t*)local_14 + 0x52) = uVar3;
      uVar16 = *(uint32_t*)(&DAT_006eacac + (uintptr_t)uVar3 * 0x1c);
      *(uint16_t*)(local_14 + 0x15) = 0xffff;
      local_14[0x16] = uVar16;
      *(uint16_t*)((uint8_t*)local_14 + 0x56) = 1;
      puVar14 = (uint32_t*)(uintptr_t)(piVar15[1] + 8);
      puVar12 = local_14 + 2;
      for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar12 = *puVar14;
        puVar14 = puVar14 + 1;
        puVar12 = puVar12 + 1;
      }
      *local_14 = *(uint32_t*)(uintptr_t)piVar15[1];
      local_14[0xc] =
        local_14[0xc] ^ ((*(int32_t*)((uint8_t*)(uintptr_t)piVar15[1] + 0x30) << 0x1f) >> 0x1f ^
                         local_14[0xc]) & 1;
      local_14[0xc] =
        ((*(int32_t*)((uint8_t*)(uintptr_t)piVar15[1] + 0x30) << 0x1e) >> 0x1e ^ local_14[0xc]) &
        2 ^ local_14[0xc];
      local_14[0xf] = *(uint32_t*)((uint8_t*)(uintptr_t)piVar15[1] + 0x3c);
      local_14[0xd] = *(uint32_t*)((uint8_t*)(uintptr_t)piVar15[1] + 0x34);
      *(uint16_t*)((uint8_t*)local_14 + 0x4e) =
        *(uint16_t*)((uint8_t*)(uintptr_t)piVar15[1] + 0x4e);
      *(uint16_t*)(local_14 + 0x14) = *(uint16_t*)((uint8_t*)(uintptr_t)piVar15[1] + 0x50);
      local_14[0xe] = *(uint32_t*)((uint8_t*)(uintptr_t)piVar15[1] + 0x38);
      *(uint32_t*)((uint8_t*)(uintptr_t)piVar15[1] + 0x34) = 0;
      *(uint16_t*)((uint8_t*)(uintptr_t)piVar15[1] + 0x4e) = 0;
      *(uint16_t*)((uint8_t*)(uintptr_t)piVar15[1] + 0x50) = 0;
      *(uint32_t*)((uint8_t*)(uintptr_t)piVar15[1] + 0x38) = 0;
      if (piVar15[1] != 0) {
        FUN_00647bbc(3);
        piVar15[1] = 0;
      }
      piVar15[1] = (int32_t)(uintptr_t)local_14;
      *(int16_t*)(piVar15 + 0xe) = *(int16_t*)((uint8_t*)(uintptr_t)(*local_8) + 0xc) + 1;
      goto LAB_0064aeaf;
    }
  }
  else {
LAB_0064aeaf:
    uVar16 = (uint32_t)*(uint16_t*)(piVar15 + 9);
    piVar15[3] = 0;
    piVar15[0x10] = 0;
    if (*(uint16_t*)(piVar15 + 9) <= local_28[0]) {
      uVar16 = ((uint32_t)local_28[1] << 16) | local_28[0];
    }
    local_4c = (uint32_t*)(uintptr_t)((uVar16 & 0xffff) * 0x10);
    uVar16 = (uint32_t)*(uint16_t*)((uint8_t*)piVar15 + 0x26);
    piVar15[3] = (int32_t)(uintptr_t)local_4c;
    piVar15[0x12] = (int32_t)(uintptr_t)local_4c;
    if (*(uint16_t*)((uint8_t*)piVar15 + 0x26) <= local_28[1]) {
      uVar16 = ((uint32_t)local_28[2] << 16) | local_28[1];
    }
    local_68 = local_4c + (uVar16 & 0xffff);
    uVar16 = (uint32_t)*(uint16_t*)(piVar15 + 10);
    piVar15[3] = (int32_t)(uintptr_t)local_68;
    piVar15[0x11] = (int32_t)(uintptr_t)local_68;
    if (*(uint16_t*)(piVar15 + 10) <= local_28[2]) {
      uVar16 = ((uint32_t)local_28[3] << 16) | local_28[2];
    }
    local_44 = local_68 + (uVar16 & 0xffff) * 4;
    piVar15[3] = (int32_t)(uintptr_t)(local_44 + *(uint16_t*)((uint8_t*)piVar15 + 0x2a));
    *(uint16_t*)(piVar15 + 0xd) = *(uint16_t*)((uint8_t*)piVar15 + 0x2a);
    if (local_30 != (uint32_t*)0x0) {
      local_c = (uint32_t*)(uintptr_t)((uint32_t)*(uint16_t*)((uint8_t*)piVar15 + 0x36) * 100 +
                                       piVar15[1]);
      *(uint16_t*)((uint8_t*)piVar15 + 0x36) =
        *(uint16_t*)((uint8_t*)piVar15 + 0x36) + 1;
      *local_c = 1;
      local_c[0xc] = local_c[0xc] & 0xfffffff5 | 1;
      piVar15[2] = piVar15[2] | 4;
      puVar14 = local_c + 0xe;
      local_18 = FUN_006294f9(local_64 + 0x68, (void**)&puVar14);
      if (local_18 < 0) goto LAB_0064b906;
      piVar9 = (int32_t*)*puVar14;
      local_14 = (uint32_t*)(*(uint32_t (**)(int32_t*))(*(uint32_t*)piVar9 + 0xc))(piVar9);
      local_58 = local_48 + 3;
      local_34 = local_48 + 1;
      local_2c = local_48 + 4;
      local_1c = local_48;
      local_3c = local_48 + 5;
      local_10 = local_48 + 2;
      uVar16 = (uint32_t)(*local_48 + *local_58) * 4 |
               ((uint32_t)(*local_48 + *local_58) & 0x3fffffff) << 1;
      uVar16 = uVar16 | uVar16 >> 2;
      uVar16 = uVar16 | uVar16 >> 4;
      uVar16 = uVar16 | uVar16 >> 8;
      uVar16 = uVar16 | uVar16 >> 0x10;
      uVar8 = (uint32_t)(*local_2c + *local_34) * 4 |
              ((uint32_t)(*local_2c + *local_34) & 0x3fffffff) << 1;
      uVar8 = uVar8 | uVar8 >> 2;
      uVar8 = uVar8 | uVar8 >> 4;
      uVar8 = uVar8 | uVar8 >> 8;
      uVar8 = uVar8 | uVar8 >> 0x10;
      uVar17 = (uint32_t)(*local_3c + *local_10) * 4 |
               ((uint32_t)(*local_3c + *local_10) & 0x3fffffff) << 1;
      local_14[6] = 0;
      uVar17 = uVar17 | uVar17 >> 2;
      uVar17 = uVar17 | uVar17 >> 4;
      uVar17 = uVar17 | uVar17 >> 8;
      local_40 = (uint32_t*)(uintptr_t)(uVar17 | uVar17 >> 0x10);
      local_14[2] = (uint32_t)(uintptr_t)local_40;
      *local_14 = uVar16;
      local_14[1] = uVar8;
      uVar17 = (uint32_t)(*local_58 + *local_48) * 4;
      local_14[3] = uVar17;
      if (uVar17 != 0) {
        local_14[3] = uVar17 - 1;
      }
      uVar17 = (uint32_t)(*local_34 + *local_2c) * 4;
      local_14[4] = uVar17;
      if (uVar17 != 0) {
        local_14[4] = uVar17 - 1;
      }
      uVar17 = (uint32_t)(*local_10 + *local_3c) * 4;
      local_14[5] = uVar17;
      if (uVar17 != 0) {
        local_14[5] = uVar17 - 1;
      }
      uVar17 = local_14[3] >> 1 | local_14[3];
      uVar17 = uVar17 >> 2 | uVar17;
      uVar17 = uVar17 >> 4 | uVar17;
      uVar17 = uVar17 >> 8 | uVar17;
      local_14[3] = uVar17 >> 0x10 | uVar17;
      uVar17 = local_14[4] >> 1 | local_14[4];
      uVar17 = uVar17 >> 2 | uVar17;
      uVar17 = uVar17 >> 4 | uVar17;
      uVar17 = uVar17 >> 8 | uVar17;
      local_14[4] = uVar17 >> 0x10 | uVar17;
      uVar17 = local_14[5] >> 1 | local_14[5];
      uVar17 = uVar17 >> 2 | uVar17;
      uVar17 = uVar17 >> 4 | uVar17;
      uVar17 = uVar17 >> 8 | uVar17;
      local_14[5] = uVar17 >> 0x10 | uVar17;
      uVar17 = (piVar15[3] & 7U) + (piVar15[3] & 0xfffffff8U);
      piVar15[3] = uVar17;
      local_14[7] = uVar17;
      uVar16 = (uint32_t)piVar15[3] + uVar16 * 8;
      uVar16 = (uVar16 & 7) + (uVar16 & 0xfffffff8);
      piVar15[3] = uVar16;
      local_14[8] = uVar16;
      uVar16 = (uint32_t)piVar15[3] + uVar8 * 8;
      uVar16 = (uVar16 & 7) + (uVar16 & 0xfffffff8);
      piVar15[3] = uVar16;
      local_14[9] = uVar16;
      piVar15[3] = piVar15[3] + (int32_t)(uintptr_t)local_40 * 8;
      uVar16 = 0;
      local_14[10] = 0;
      local_14[0xb] = (uint32_t)(uintptr_t)local_4c;
      local_14[0xc] = (uint32_t)(uintptr_t)local_68;
      *(uint16_t*)((uint8_t*)local_c + 0x56) = 0;
      *(uint16_t*)(local_c + 0x15) = 0;
      puVar14 = local_14 + 0x10;
      do {
        puVar14[3] = (uint32_t)local_58[uVar16];
        *puVar14 = (uint32_t)local_48[uVar16];
        uVar16 = uVar16 + 1;
        puVar14 = puVar14 + 1;
      } while (uVar16 < 3);
      local_14[0x17] = (int32_t)(uintptr_t)local_48 + (0x80 - (int32_t)(uintptr_t)local_30);
      uVar16 = (uint32_t)((int32_t)(uintptr_t)local_48 + local_48[6] * 8 +
                          (0x84 - (int32_t)(uintptr_t)local_30));
      local_14[0x18] = uVar16;
      local_14[0x19] = uVar16 + 4 +
                       (uint32_t)*(int32_t*)(((uint8_t*)(uintptr_t)uVar16 - 0x68) +
                                             (uintptr_t)local_30) * 8;
      puVar14 = local_30;
      puVar12 = local_14 + 0x1a;
      for (uVar16 = local_64 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
        *puVar12 = *puVar14;
        puVar14 = puVar14 + 1;
        puVar12 = puVar12 + 1;
      }
      for (uVar16 = local_64 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
        *(uint8_t*)puVar12 = (uint8_t)*puVar14;
        puVar14 = (uint32_t*)((uint8_t*)puVar14 + 1);
        puVar12 = (uint32_t*)((uint8_t*)puVar12 + 1);
      }
      local_18 = FUN_0060afb7((uint32_t)(uintptr_t)(local_14 + 0x1a),
                              (uint32_t)(uintptr_t)(local_c + 0x10),
                              (uint32_t)(uintptr_t)(local_c + 0x11));
      if ((local_18 < 0) ||
         (local_18 = FUN_00643bf5(param_1,
                                  (uint32_t)*(uint16_t*)((uint8_t*)piVar15 + 0x36) - 1,
                                  (uint32_t)(uintptr_t)local_14), local_18 < 0))
        goto LAB_0064b906;
      *(uint16_t*)((uint8_t*)local_c + 0x52) = 0xb5;
      local_c[0x16] = 0x11000000;
      piVar15[2] = piVar15[2] | 1;
      local_1c = (uint32_t*)(piVar15 + 9);
      local_c = local_14 + 0x17;
      uVar16 = 0;
      do {
        uVar3 = *(uint16_t*)((uintptr_t)local_28 + uVar16);
        if (uVar3 != 0) {
          piVar9 = (int32_t*)(uintptr_t)(*local_c + (int32_t)(uintptr_t)local_14);
          iVar4 = 0;
          for (iVar7 = *piVar9; iVar7 != 0; iVar7 = iVar7 + -1) {
            piVar9 = piVar9 + 2;
            iVar4 = iVar4 + *piVar9;
          }
          uVar2 = (uint16_t)*local_1c;
          if ((uint16_t)*local_1c <= uVar3) {
            uVar2 = uVar3;
          }
          if ((uint32_t)*(uint16_t*)((uintptr_t)local_74 + uVar16) + (uint32_t)iVar4 != uVar2) {
            piVar15[2] = piVar15[2] & 0xfffffffe;
            break;
          }
          if ((iVar4 != 0) && (*(uint16_t*)((uintptr_t)local_74 + uVar16) == 0)) {
            piVar15[2] = piVar15[2] | 0x10;
          }
        }
        local_c = local_c + 1;
        local_1c = (uint32_t*)((uint8_t*)local_1c + 2);
        uVar16 = uVar16 + 2;
      } while (uVar16 < 6);
      if ((*(uint8_t*)((uint8_t*)piVar15 + 8) & 1) != 0) {
        uVar3 = *(uint16_t*)(piVar15 + 9);
        if (*(uint16_t*)(piVar15 + 9) <= local_28[0]) {
          uVar3 = local_28[0];
        }
        *(uint16_t*)(piVar15 + 0x14) = uVar3;
        uVar3 = *(uint16_t*)(piVar15 + 10);
        if (*(uint16_t*)(piVar15 + 10) <= local_28[2]) {
          uVar3 = local_28[2];
        }
        *(uint16_t*)((uint8_t*)piVar15 + 0x56) = uVar3;
        uVar3 = *(uint16_t*)((uint8_t*)piVar15 + 0x26);
        if (*(uint16_t*)((uint8_t*)piVar15 + 0x26) <= local_28[1]) {
          uVar3 = local_28[1];
        }
        *(uint16_t*)(piVar15 + 0x17) = uVar3;
      }
    }
    local_18 = FUN_0063e391();
    uVar16 = local_20;
    if (local_18 < 0) goto LAB_0064b906;
    *(uint16_t*)(piVar15 + 0xd) = 0;
    local_60 = (void*)FUN_00533c78(*(int32_t*)((uint8_t*)(uintptr_t)local_20 + 0xc) << 2);
    if (local_60 != (void*)0x0) {
      uVar8 = 0;
      iVar7 = *(int32_t*)((uint8_t*)(uintptr_t)uVar16 + 0x10) + (int32_t)uVar16;
      if (*(int32_t*)((uint8_t*)(uintptr_t)uVar16 + 0xc) != 0) {
        do {
          *(int32_t*)((uint8_t*)local_60 + uVar8 * 4) = iVar7;
          uVar8 = uVar8 + 1;
          iVar7 = iVar7 + 0x14;
        } while (uVar8 < *(uint32_t*)((uint8_t*)(uintptr_t)uVar16 + 0xc));
      }
      qsort(local_60, (size_t)*(int32_t*)((uint8_t*)(uintptr_t)uVar16 + 0xc), 4,
            (int (*)(const void*, const void*))FUN_0063e2a9);
      iVar7 = 0;
      iVar4 = 0;
      local_2c = (uint32_t*)0x0;
      if (*(uint32_t**)((uint8_t*)(uintptr_t)uVar16 + 0xc) != (uint32_t*)0x0) {
        psVar10 = (int16_t*)(uintptr_t)(*(int32_t*)((uint8_t*)(uintptr_t)uVar16 + 0x10) +
                                        (int32_t)uVar16 + 4);
        local_10 = *(uint32_t**)((uint8_t*)(uintptr_t)uVar16 + 0xc);
        do {
          sVar1 = *psVar10;
          if (sVar1 == 0) {
            iVar4 = iVar4 + 1;
          }
          else if (sVar1 == 1) {
            local_2c = (uint32_t*)((uintptr_t)local_2c + 1);
          }
          else if (sVar1 == 2) {
            iVar7 = iVar7 + 1;
          }
          psVar10 = psVar10 + 10;
          local_10 = (uint32_t*)((uintptr_t)local_10 + -1);
        } while (local_10 != (uint32_t*)0x0);
      }
      local_3c = (uint32_t*)0x0;
      uVar3 = *(uint16_t*)((uint8_t*)piVar15 + 0x36);
      local_c = (uint32_t*)(uintptr_t)uVar3;
      local_1c = (uint32_t*)(uintptr_t)(iVar7 + (int32_t)(uintptr_t)local_c);
      local_2c = (uint32_t*)((uintptr_t)local_2c + (uintptr_t)local_1c);
      local_14 = (uint32_t*)(uintptr_t)(iVar4 + (int32_t)(uintptr_t)local_2c);
      *(uint16_t*)((uint8_t*)piVar15 + 0x36) =
        (uint16_t)(*(int16_t*)((uint8_t*)(uintptr_t)uVar16 + 0xc) + uVar3);
      *(uint16_t*)(piVar15 + 0x13) = uVar3;
      *(int16_t*)((uint8_t*)piVar15 + 0x52) = (int16_t)(uintptr_t)local_1c;
      *(int16_t*)(piVar15 + 0x16) = (int16_t)(uintptr_t)local_2c;
      *(uint16_t*)((uint8_t*)piVar15 + 0x5e) = (uint16_t)(uintptr_t)local_14;
      if (*(int32_t*)((uint8_t*)(uintptr_t)uVar16 + 0xc) != 0) {
        do {
          puVar14 = *(uint32_t**)((uint8_t*)local_60 + (uintptr_t)local_3c * 4);
          sVar1 = (int16_t)puVar14[1];
          local_8 = (uint32_t*)0x0;
          if (sVar1 == 0) {
            local_8 = (uint32_t*)(uintptr_t)((uint32_t)(uintptr_t)local_2c & 0xffff);
            local_2c = (uint32_t*)((uintptr_t)local_2c + 1);
          }
          else if (sVar1 == 1) {
            local_8 = (uint32_t*)(uintptr_t)((uint32_t)(uintptr_t)local_1c & 0xffff);
            local_1c = (uint32_t*)((uintptr_t)local_1c + 1);
          }
          else if (sVar1 == 2) {
            local_8 = (uint32_t*)(uintptr_t)((uint32_t)(uintptr_t)local_c & 0xffff);
            local_c = (uint32_t*)((uintptr_t)local_c + 1);
          }
          else if (sVar1 == 3) {
            local_8 = (uint32_t*)(uintptr_t)((uint32_t)(uintptr_t)local_14 & 0xffff);
            local_14 = (uint32_t*)((uintptr_t)local_14 + 1);
          }
          puVar18 = (uint32_t*)(uintptr_t)((uintptr_t)local_8 * 100 + piVar15[1]);
          *(uint16_t*)(puVar18 + 0x15) = *(uint16_t*)((uint8_t*)puVar14 + 6);
          uVar16 = puVar14[2];
          puVar18[0xc] = puVar18[0xc] | 9;
          *(int16_t*)((uint8_t*)puVar18 + 0x56) = (int16_t)uVar16;
          local_58 = puVar14;
          local_40 = puVar18;
          iVar7 = FUN_0063ea6b(*puVar14 + local_20, 10);
          local_28[2] = (uint16_t)iVar7;
          local_28[3] = (uint16_t)((uint32_t)iVar7 >> 0x10);
          if (iVar7 == 0) {
            *puVar18 = 0;
            puVar18 = (uint32_t*)0x0;
          }
          else {
            if (*(int16_t*)(puVar18 + 0x14) == 0) {
              puVar11 = (uint32_t*)FUN_00533c78(0x24);
              if (puVar11 == (uint32_t*)0x0) {
                puVar12 = (uint32_t*)0x0;
              }
              else {
                *puVar11 = 1;
                local_34 = puVar11 + 1;
                FUN_004127b0(local_34, 0x20, 1, &LAB_0063e2de);
                puVar12 = local_34;
              }
              puVar18[0xd] = (uint32_t)(uintptr_t)puVar12;
              if (puVar12 == (uint32_t*)0x0) goto LAB_0064b84f;
              *(uint16_t*)(puVar18 + 0x14) = 1;
            }
            local_18 = FUN_0063e97c(param_1, (uint32_t)(uintptr_t)local_8, 0,
                                    ((uint32_t)local_28[3] << 16) | local_28[2], puVar14);
            if (local_18 < 0) goto LAB_0064b906;
            /* FUN_0063e97c output offset used as a base pointer, verbatim. */
            puVar18 = (uint32_t*)(uintptr_t)(((uint32_t)local_28[3] << 16) | local_28[2]);
            *(uint16_t*)((uint8_t*)local_40 + 0x4e) = 1;
            puVar11 = puVar18;
            puVar19 = local_40 + 2;
            for (iVar7 = 10; iVar7 != 0; iVar7 = iVar7 + -1) {
              *puVar19 = *puVar11;
              puVar11 = puVar11 + 1;
              puVar19 = puVar19 + 1;
            }
            local_40[0xc] = local_40[0xc] & 0xfffffffd;
            local_40[10] = 0;
            local_40[0xb] = 0;
            *local_40 = 1;
          }
          puVar14 = local_58;
          local_40[0xf] = local_20;
          sVar1 = (int16_t)local_58[1];
          if (sVar1 == 0) {
            *(uint16_t*)((uint8_t*)local_40 + 0x52) = 0x9d;
            local_40[0x16] = 0xd010000;
            local_34 = local_4c + *(uint16_t*)((uint8_t*)local_58 + 6);
            local_40[0x12] = (uint32_t)(uintptr_t)local_34;
            uVar16 = (uint32_t)(uint16_t)local_58[2];
            if (local_58[4] == 0) {
              puVar18 = (uint32_t*)(uintptr_t)(*piVar15 + (int32_t)(uintptr_t)local_34);
              for (; uVar16 != 0; uVar16 = uVar16 - 1) {
                *puVar18 = 0;
                puVar18 = puVar18 + 1;
              }
              for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                *(uint8_t*)puVar18 = 0;
                puVar18 = (uint32_t*)((uint8_t*)puVar18 + 1);
              }
            }
            else {
              puVar18 = (uint32_t*)(uintptr_t)(local_58[4] + local_20);
              puVar11 = (uint32_t*)(uintptr_t)(*piVar15 + (int32_t)(uintptr_t)local_34);
              for (; uVar16 != 0; uVar16 = uVar16 - 1) {
                *puVar11 = *puVar18;
                puVar18 = puVar18 + 1;
                puVar11 = puVar11 + 1;
              }
              for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                *(uint8_t*)puVar11 = *(uint8_t*)puVar18;
                puVar18 = (uint32_t*)((uint8_t*)puVar18 + 1);
                puVar11 = (uint32_t*)((uint8_t*)puVar11 + 1);
              }
            }
            if (*(int8_t*)((uint8_t*)piVar15 + 0x31) != '\0') {
              if (local_80 != (uint32_t*)0x0) {
                local_80[0xc] = local_80[0xc] & 0xfffffffe;
              }
              local_80 = local_40;
            }
          }
          else if (sVar1 == 1) {
            *(uint16_t*)((uint8_t*)local_40 + 0x52) = 0x9e;
            local_40[0x16] = 0xd020000;
            local_10 = (uint32_t*)0x0;
            local_40[0x12] = (uint32_t)(uintptr_t)(local_68 +
              (uintptr_t)(uint32_t)*(uint16_t*)((uint8_t*)local_58 + 6) * 4);
            if ((int16_t)local_58[2] != 0) {
              local_8 = (uint32_t*)0x0;
              do {
                *(uint32_t*)(uintptr_t)((uintptr_t)local_8 + local_40[0x12] + *piVar15) = 0;
                *(uint32_t*)(uintptr_t)((uintptr_t)local_8 + local_40[0x12] + *piVar15 + 4) = 0;
                *(uint32_t*)(uintptr_t)((uintptr_t)local_8 + local_40[0x12] + *piVar15 + 8) = 1;
                local_10 = (uint32_t*)((uintptr_t)local_10 + 1);
                puVar14 = local_8 + 4;
                *(uint32_t*)(uintptr_t)((uintptr_t)local_8 + local_40[0x12] + *piVar15 + 0xc) = 0;
                local_8 = puVar14;
              } while (local_10 < (uint32_t*)(uintptr_t)(uint32_t)(uint16_t)local_58[2]);
            }
            if (local_58[4] != 0) {
              puVar18 = (uint32_t*)(uintptr_t)(local_20 + local_58[4]);
              puVar11 = (uint32_t*)(uintptr_t)(*piVar15 + local_40[0x12]);
              for (iVar7 = (uint32_t)(uint16_t)local_58[2] << 2; iVar7 != 0;
                   iVar7 = iVar7 + -1) {
                *puVar11 = *puVar18;
                puVar18 = puVar18 + 1;
                puVar11 = puVar11 + 1;
              }
              for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                *(uint8_t*)puVar11 = *(uint8_t*)puVar18;
                puVar18 = (uint32_t*)((uint8_t*)puVar18 + 1);
                puVar11 = (uint32_t*)((uint8_t*)puVar11 + 1);
              }
            }
            if (*(int8_t*)((uint8_t*)piVar15 + 0x32) != '\0') {
              if (local_7c != (uint32_t*)0x0) {
                local_7c[0xc] = local_7c[0xc] & 0xfffffffe;
              }
              local_7c = local_40;
            }
          }
          else if (sVar1 == 2) {
            puVar11 = local_40;
            if (puVar18 != (uint32_t*)0x0) {
              iVar7 = *(int32_t*)(uintptr_t)puVar18[1];
              if (((int32_t*)(uintptr_t)puVar18[1])[4] == 0) {
                local_8 = (uint32_t*)0x1;
              }
              else {
                local_8 = *(uint32_t**)((uintptr_t)puVar18[1] + 0x10);
              }
              local_10 = *(uint32_t**)((uintptr_t)puVar18[1] + 0x18);
              iVar4 = *(int32_t*)((uintptr_t)puVar18[1] + 4);
              if (-1 < iVar4) {
                if (iVar4 < 2) {
                  if (iVar7 == 3) {
                    local_40[0xc] = local_40[0xc] | 0x10;
                    local_40[0x17] = *puVar18;
                    puVar12 = (uint32_t*)(uintptr_t)(uint32_t)(uint16_t)local_58[2];
                    if (local_8 < (uint32_t*)(uintptr_t)(uint32_t)(uint16_t)local_58[2]) {
                      puVar12 = local_8;
                    }
                    goto LAB_0064b689;
                  }
                }
                else if (iVar4 == 2) {
                  if ((iVar7 == 3) &&
                      (*(int16_t*)(uintptr_t)(local_58[3] + local_20) == 3)) {
                    if (local_8 == (uint32_t*)0x1) {
                      local_40[0xc] = local_40[0xc] | 0x10;
                      local_40[0x17] = *puVar18;
                      puVar12 = (uint32_t*)(uintptr_t)(uint32_t)(uint16_t)local_58[2];
                      if (local_10 < (uint32_t*)(uintptr_t)(uint32_t)(uint16_t)local_58[2]) {
                        puVar12 = local_10;
                      }
                    }
                    else {
                      if (local_10 != (uint32_t*)0x4) goto LAB_0064b68f;
                      local_40[0xc] = local_40[0xc] | 0x10;
                      local_40[0x17] = *puVar18;
                      puVar12 = (uint32_t*)((uintptr_t)local_8 << 2);
                      if ((uint32_t*)(uintptr_t)(uint32_t)(uint16_t)local_58[2] <=
                          (uint32_t*)((uintptr_t)local_8 << 2)) {
                        puVar12 = (uint32_t*)(uintptr_t)(uint32_t)(uint16_t)local_58[2];
                      }
                    }
LAB_0064b689:
                    local_40[0x18] = (int32_t)((uintptr_t)puVar12 << 4);
                  }
                }
                else if (iVar4 == 5) {
                  puVar12 = (uint32_t*)(uintptr_t)puVar18[1];
                  local_34 = puVar12;
                  uVar20 = FUN_0063dcf6((uint32_t**)&local_34);
                  puVar11 = (uint32_t*)(uintptr_t)(uVar20 >> 0x20);
                  if ((int32_t)uVar20 != 0) {
                    local_34 = puVar12;
                    uVar8 = FUN_0063dc77((uint32_t**)&local_34, 4);
                    local_40[0xc] = local_40[0xc] | 0x10;
                    local_40[0x17] = ((uint32_t)local_28[3] << 16) | local_28[2];
                    uVar16 = (uint32_t)(uint16_t)local_58[2];
                    if (uVar8 < (uint16_t)local_58[2]) {
                      uVar16 = uVar8;
                    }
                    local_40[0x18] = uVar16 << 4;
                    puVar11 = local_40;
                    puVar14 = local_58;
                  }
                }
              }
            }
LAB_0064b68f:
            *(uint16_t*)((uint8_t*)puVar11 + 0x52) = 0x9c;
            puVar11[0x16] = 0xd000000;
            local_34 = (uint32_t*)(uintptr_t)((uint32_t)*(uint16_t*)((uint8_t*)puVar14 + 6) * 0x10);
            puVar11[0x12] = (uint32_t)(uintptr_t)local_34;
            if (puVar14[4] == 0) {
              puVar18 = (uint32_t*)(uintptr_t)(*piVar15 + (int32_t)(uintptr_t)local_34);
              for (iVar7 = (uint32_t)(uint16_t)puVar14[2] << 2; iVar7 != 0;
                   iVar7 = iVar7 + -1) {
                *puVar18 = 0;
                puVar18 = puVar18 + 1;
              }
              for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                *(uint8_t*)puVar18 = 0;
                puVar18 = (uint32_t*)((uint8_t*)puVar18 + 1);
              }
            }
            else {
              puVar18 = (uint32_t*)(uintptr_t)(local_20 + puVar14[4]);
              puVar19 = (uint32_t*)(uintptr_t)(*piVar15 + (int32_t)(uintptr_t)local_34);
              for (iVar7 = (uint32_t)(uint16_t)puVar14[2] << 2; iVar7 != 0;
                   iVar7 = iVar7 + -1) {
                *puVar19 = *puVar18;
                puVar18 = puVar18 + 1;
                puVar19 = puVar19 + 1;
              }
              for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
                *(uint8_t*)puVar19 = *(uint8_t*)puVar18;
                puVar18 = (uint32_t*)((uint8_t*)puVar18 + 1);
                puVar19 = (uint32_t*)((uint8_t*)puVar19 + 1);
              }
            }
            if ((int8_t)piVar15[0xc] != '\0') {
              if (local_84 != (uint32_t*)0x0) {
                local_84[0xc] = local_84[0xc] & 0xfffffffe;
              }
              local_84 = puVar11;
            }
          }
          else if (sVar1 == 3) {
            *(uint16_t*)((uint8_t*)local_40 + 0x52) = 0xb2;
            local_40[0x16] = 0xf000000;
            uVar3 = *(uint16_t*)((uint8_t*)local_58 + 6);
            local_40[0xc] = local_40[0xc] & 0xfffffffd;
            local_40[0x12] = (uint32_t)(uintptr_t)(local_44 + uVar3);
            *local_40 = 0;
            if (puVar18 == (uint32_t*)0x0) {
              *(uint16_t*)(uintptr_t)(*piVar15 + local_40[0x12]) = 0;
              *(uint16_t*)(uintptr_t)(*piVar15 + 2 + local_40[0x12]) = 0;
            }
            else {
              *(int16_t*)(uintptr_t)(*piVar15 + local_40[0x12]) =
                (int16_t)(*(int16_t*)(puVar18 + 0x11) + 1);
              *(uint16_t*)(uintptr_t)(*piVar15 + 2 + local_40[0x12]) = 0;
              uVar3 = *(uint16_t*)((uint8_t*)puVar18 + 0x46);
              if (*(uint16_t*)((uint8_t*)local_40 + 0x56) <
                  *(uint16_t*)((uint8_t*)puVar18 + 0x46)) {
                uVar3 = *(uint16_t*)((uint8_t*)local_40 + 0x56);
              }
              *(uint16_t*)((uint8_t*)local_40 + 0x56) = uVar3;
            }
            *(uint16_t*)(uintptr_t)(piVar15[5] +
                                    (uint32_t)*(uint16_t*)(piVar15 + 0xd) * 2 + *piVar15) =
              (uint16_t)(uintptr_t)local_8;
            *(int16_t*)(piVar15 + 0xd) = (int16_t)(piVar15[0xd] + 1);
          }
          local_3c = (uint32_t*)((uintptr_t)local_3c + 1);
        } while (local_3c < *(uint32_t**)((uint8_t*)(uintptr_t)local_20 + 0xc));
        uVar3 = (uint16_t)(uintptr_t)local_c;
      }
      *(uint16_t*)((uint8_t*)piVar15 + 0x4e) = uVar3;
      *(int16_t*)(piVar15 + 0x15) = (int16_t)(uintptr_t)local_1c;
      *(int16_t*)((uint8_t*)piVar15 + 0x5a) = (int16_t)(uintptr_t)local_2c;
      *(uint16_t*)((uint8_t*)piVar15 + 0x60) = (uint16_t)(uintptr_t)local_14;
      goto LAB_0064b906;
    }
  }
LAB_0064b84f:
  local_18 = -0x7ff8fff2;
LAB_0064b906:
  operator_delete(local_60);
  return local_18;
}
