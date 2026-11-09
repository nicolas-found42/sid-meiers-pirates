// mass_0292 — Sid Meier's Pirates! (2004) source reconstruction candidates
// Corpus: analysis/pseudocode/functions/*.c (Ghidra 12.2 pseudocode, PE32 i386)
// Pseudocode is provider output, not original source.

#include <cstdint>
#include <cstddef>

// Ghidra SBORROW4(a,b): signed borrow/overflow flag of (a - b) over 32-bit ints.
#define SBORROW4(a, b) \
  ((((((int32_t)(a) ^ (int32_t)(b)) & ((int32_t)(a) ^ ((int32_t)(a) - (int32_t)(b)))) & 0x80000000) != 0)

typedef uint32_t undefined4;
typedef uint8_t undefined1;

extern int FUN_00632959(undefined4);

// ---------------------------------------------------------------------------

// 0x633174 — observed shape: VARIANT-style decode to double, HRESULT-style status
uint32_t FUN_00633174(double *param_1, int *param_2)
{
  double dVar1;
  int iVar2;

  iVar2 = *param_2;
  if (iVar2 == 0) {
    // VT_EMPTY / VT_NULL-ish: 0.0 unless payload word non-zero
    if (param_2[2] == 0) {
      dVar1 = 0.0;
    }
    else {
      dVar1 = 1.0;
    }
    *param_1 = dVar1;
  }
  else {
    if (iVar2 == 1) {
      // VT_I2-style: direct int payload sign-extended into double
      dVar1 = (double)param_2[2];
    }
    else if (iVar2 == 2) {
      // VT_I4: unsigned reload, corrected to signed by adding 2^32
      dVar1 = (double)param_2[2];
      if (param_2[2] < 0) {
        dVar1 = dVar1 + 4294967296.0;
      }
    }
    else {
      if (iVar2 != 3) {
        return 0x80004005;   // E_FAIL
      }
      // VT_R8: payload holds the double itself
      dVar1 = *(double *)(param_2 + 2);
    }
    *param_1 = dVar1;
  }
  return 0;
}

// 0x6331d2 — observed shape: recursive walk over node tree, bool accept predicate
bool FUN_006331d2(int param_1)
{
  int iVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;

  while (true) {
    while (true) {
      if (param_1 == 0) {
        return false;
      }
      iVar2 = *(int *)(param_1 + 4);
      if (iVar2 != 1) break;
      // node kind 1: sequence — first child decides, else continue on +0xc sibling
      iVar2 = (int)FUN_006331d2(*(undefined4 *)(param_1 + 8));
      if (iVar2 != 0) {
        return true;
      }
      param_1 = *(int *)(param_1 + 0xc);
    }
    if (iVar2 == 0xe) {
      return *(int *)(param_1 + 0x10) != 6;
    }
    if (iVar2 != 0xd) {
      return false;
    }
    // node kind 0xd: dispatch on opcode at +0x1c
    iVar2 = *(int *)(param_1 + 0x1c);
    if (0x17 < iVar2) break;
    if (iVar2 < 0x16) {
      if (iVar2 < 0) {
        return true;
      }
      if (1 < iVar2) {
        if (iVar2 < 0x14) {
          return true;
        }
        bVar4 = SBORROW4(iVar2, 0x15);
        iVar1 = iVar2 + -0x15;
        bVar3 = iVar2 == 0x15;
        goto LAB_0063323f;
      }
    }
    param_1 = *(int *)(param_1 + 0x20);
  }
  if (iVar2 < 0x19) {
    return true;
  }
  bVar4 = SBORROW4(iVar2, 0x1a);
  iVar1 = iVar2 + -0x1a;
  bVar3 = iVar2 == 0x1a;
LAB_0063323f:
  if (bVar3 || bVar4 != (iVar1 < 0)) {
    return false;
  }
  return true;
}

// 0x63324e — observed shape: recursive expression/statement validator
bool FUN_0063324e(int param_1)
{
  int iVar1;
  undefined4 uVar2;

  while (true) {
    while (true) {
      if (param_1 == 0) {
        return true;
      }
      iVar1 = *(int *)(param_1 + 4);
      if (iVar1 != 1) break;
      iVar1 = (int)FUN_0063324e(*(undefined4 *)(param_1 + 8));
      if (iVar1 == 0) {
        return false;
      }
      param_1 = *(int *)(param_1 + 0xc);
    }
    if (iVar1 == 0xe) {
      return *(int *)(param_1 + 0x10) != 6;
    }
    if (iVar1 != 0xd) {
      return true;
    }
    iVar1 = *(int *)(param_1 + 0x1c);
    if (iVar1 < 0x14) break;
    if (iVar1 < 0x16) {
      return false;
    }
    if (iVar1 == 0x19) {
      return false;
    }
    if (iVar1 == 0x1a) {
      // reject specific operator codes on the left operand's kind tag
      iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x20) + 8) + 0x18);
      if (iVar1 < 0x47) {
        if (0x43 < iVar1) {
          return false;
        }
        if (iVar1 == 9) {
          return false;
        }
        if (iVar1 == 0x1a) {
          return false;
        }
        if (iVar1 == 0x28) {
          return false;
        }
        if (iVar1 == 0x3d) {
          return false;
        }
      }
      else if (0x48 < iVar1) {
        if (iVar1 < 0x4c) {
          return false;
        }
        if (0x4d < iVar1) {
          if (iVar1 < 0x51) {
            return false;
          }
          if ((0x52 < iVar1) && (iVar1 < 0x56)) {
            return false;
          }
        }
      }
      iVar1 = (int)FUN_0063324e(*(undefined4 *)(*(int *)(param_1 + 0x24) + 8));
      if (iVar1 == 0) {
        return false;
      }
      uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x24) + 0xc);
      goto LAB_00633354;
    }
    if (iVar1 != 0x1b) break;
    // opcode 0x1b: right operand must be a 0xd node; descend into its +0x24
    iVar1 = *(int *)(param_1 + 0x24);
    if (iVar1 == 0) {
      return false;
    }
    if (*(int *)(iVar1 + 4) != 0xd) {
      return false;
    }
    param_1 = *(int *)(iVar1 + 0x24);
  }
  iVar1 = (int)FUN_0063324e(*(undefined4 *)(param_1 + 0x20));
  if (iVar1 == 0) {
    return false;
  }
  uVar2 = *(undefined4 *)(param_1 + 0x24);
LAB_00633354:
  iVar1 = (int)FUN_0063324e(uVar2);
  if (iVar1 == 0) {
    return false;
  }
  return true;
}

// 0x63336c — observed shape: cache literal operand value into +0x14/+0x18
void FUN_0063336c(int param_1)
{
  int iVar1;
  undefined4 uVar2;

  if ((param_1 != 0) && (*(int *)(param_1 + 4) == 0xd)) {
    iVar1 = *(int *)(param_1 + 0x10);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
    else {
      if (*(int *)(iVar1 + 4) == 9) {
        // literal node: copy its immediate pair verbatim
        *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(iVar1 + 0x18);
        uVar2 = *(undefined4 *)(iVar1 + 0x1c);
      }
      else {
        *(undefined4 *)(param_1 + 0x14) = 1;
        uVar2 = FUN_00632959(iVar1);
      }
      *(undefined4 *)(param_1 + 0x18) = uVar2;
    }
  }
  return;
}

// 0x6333b4 — observed shape: allocate 0x24 node, ctor, capture vtable slot, wrap in "Stmts"
extern void *FUN_0060d19b(uint32_t size);
extern int   FUN_0065b469(void);
extern void *FUN_0065ac49(void *parent, int index, const char *name);

int FUN_006333b4(int *param_1)
{
  int iVar1;
  int iVar2;

  iVar1 = (int)FUN_0060d19b(0x24);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_0065b469();
  }
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0;
    if (param_1 != (int *)0x0) {
      // virtual call through (*param_1)[1], receiver param_1
      iVar2 = ((int (*)(void *)) * (int *)(*param_1 + 4))(param_1);
      *(int *)(iVar1 + 0x14) = iVar2;
      if (iVar2 == 0) {
        return 0;
      }
    }
    iVar2 = (int)FUN_0060d19b(0x14);
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (int)FUN_0065ac49((void *)iVar1, 0, "Stmts");
    }
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  return 0;
}

// ---------------------------------------------------------------------------

extern int  FUN_006328e2(int);
extern void FUN_00632325(void *self, ...);
extern void FUN_006323c8(void);
extern int  FUN_006325ec(int, int);
extern int  FUN_0065abd0(int, undefined4);
extern int  FUN_0065abf1(int);
extern int  FUN_006324b9(undefined4, undefined4);
extern undefined4 FUN_0065ac0a(undefined4, int);
extern void FUN_00610c00(void);
extern void FUN_0061324d(void);
extern int  FUN_00613e10(uint32_t, uint32_t, void *, int **);
extern void *FUN_0065aaac(uint32_t size, int, ...);
extern void *FUN_0065c3ac(void *self, uint32_t value);
extern int  FUN_00533c78(int);
extern int  FUN_0065b822(void *self_field, void *bytes, uint32_t length);
extern int  FUN_0065ae50(int *);
extern void  operator_delete(void *);
extern int _snprintf(char *, size_t, const char *, ...);

// 0x633499 — observed shape: build 0xd statement node from up to three operand nodes
// self = in_ECX receiver (context used by FUN_00632325 diagnostics)
int FUN_00633499(void *self, int *param_1, int *param_2, int param_3, int *param_4)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;

  if ((param_2 != (int *)0x0) &&
     ((param_2[6] * param_2[5] != 1 ||
       (iVar1 = FUN_006328e2(param_2[4]), iVar1 == 0)))) {
    FUN_00632325(self, param_2 + 0xc, 0xbcb, "float expected");
    return 0;
  }
  iVar1 = (int)FUN_0060d19b(0x24);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_0065b469();
  }
  if (iVar1 == 0) {
    return 0;
  }
  *(undefined4 *)(iVar1 + 0x10) = 3;
  if (param_3 == 0) {
    if (param_1 == (int *)0x0) {
      *(undefined4 *)(iVar1 + 0x10) = 4;
      goto LAB_00633544;
    }
    if (param_1 == param_4) {
      *(undefined4 *)(iVar1 + 0x10) = 5;
      param_1 = (int *)0x0;
    }
  }
  if (param_1 != (int *)0x0) {
    // virtual call through (*param_1)[1], receiver param_1
    iVar2 = ((int (*)(void *)) * (int *)(*param_1 + 4))(param_1);
    *(int *)(iVar1 + 0x14) = iVar2;
    if (iVar2 == 0) {
      return 0;
    }
  }
LAB_00633544:
  if (param_2 != (int *)0x0) {
    iVar2 = ((int (*)(void *)) * (int *)(*param_2 + 4))(param_2);
    *(int *)(iVar1 + 0x18) = iVar2;
    if (iVar2 == 0) {
      return 0;
    }
  }
  if (param_4 != (int *)0x0) {
    iVar2 = ((int (*)(void *)) * (int *)(*param_4 + 4))(param_4);
    *(int *)(iVar1 + 0x1c) = iVar2;
    if (iVar2 == 0) {
      return 0;
    }
  }
  if (param_3 != 0) {
    iVar2 = FUN_006333b4(param_3);
    if (iVar2 == 0) {
      return 0;
    }
    uVar3 = FUN_0065ac0a(*(undefined4 *)(iVar1 + 0x1c), iVar2);
    *(undefined4 *)(iVar1 + 0x1c) = uVar3;
  }
  iVar2 = (int)FUN_0060d19b(0x14);
  if (iVar2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)FUN_0065ac49((void *)iVar1, 0, "Stmts");
  }
  if (iVar1 == 0) {
    return 0;
  }
  return iVar1;
}

// 0x6335cf — observed shape: copy a member blob out of a resolved object, wrap as node
// self = in_ECX receiver object (uint32_t fields)
int FUN_006335cf(uint32_t *self, int param_1)
{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  int *local_c;
  void *local_8;

  local_c = (int *)0x0;
  local_8 = (void *)0x0;
  FUN_00610c00();
  if (param_1 == 0) {
LAB_0063361b:
    iVar1 = FUN_00613e10(self[1], *self & 0xc3, local_8, &local_c);
    if (-1 < iVar1) {
      uVar2 = ((uint (*)(void *)) * (int *)(*local_c + 0x10))(local_c);
      puVar3 = (undefined4 *)FUN_0065aaac(uVar2, 1);
      if (puVar3 != (undefined4 *)0x0) {
        puVar4 = (undefined4 *)((void *(*)(void *)) * (int *)(*local_c + 0xc))(local_c);
        puVar6 = puVar3;
        for (uVar5 = uVar2 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar6 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar6 = puVar6 + 1;
        }
        for (uVar5 = uVar2 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(undefined1 *)puVar6 = *(undefined1 *)puVar4;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
          puVar6 = (undefined4 *)((int)puVar6 + 1);
        }
        if (local_c != (int *)0x0) {
          ((void (*)(void *)) * (int *)(*local_c + 8))(local_c);
          local_c = (int *)0x0;
        }
        iVar1 = (int)FUN_0060d19b(0x38);
        if (iVar1 == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = FUN_0065b822(self + 8, puVar3, uVar2);
        }
        if (iVar1 != 0) {
          operator_delete(local_8);
          FUN_0061324d();
          return iVar1;
        }
        FUN_0061324d();
        goto LAB_006336ca;
      }
    }
  }
  else {
    iVar1 = FUN_00533c78(8);
    if (iVar1 == 0) {
      local_8 = (void *)0x0;
    }
    else {
      local_8 = (void *)FUN_0065c3ac(self, self[4]);
    }
    if (local_8 != (void *)0x0) goto LAB_0063361b;
  }
  FUN_0061324d();
LAB_006336ca:
  self[0x10] = 1;
  operator_delete(local_8);
  if (local_c != (int *)0x0) {
    ((void (*)(void *)) * (int *)(*local_c + 8))(local_c);
  }
  return 0;
}

// 0x633708 — observed shape: decimal literal + string concatenation into a new 3-kind node
int FUN_00633708(int param_1, int param_2)
{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  char local_18[15];
  undefined1 local_9;

  iVar4 = param_1;
  if ((((param_1 != 0) && (*(int *)(param_1 + 4) == 3)) && (*(int *)(param_1 + 0x10) == 2)) &&
     (((param_2 != 0 && (*(int *)(param_2 + 4) == 3)) && (*(int *)(param_2 + 0x10) == 9)))) {
    iVar5 = (int)FUN_0060d19b(0x30);
    if (iVar5 == 0) {
      param_1 = 0;
    }
    else {
      param_1 = FUN_0065ae50((int *)(param_2 + 0x10));
    }
    if (param_1 != 0) {
      uVar2 = *(undefined4 *)(iVar4 + 0x18);
      pcVar3 = *(char **)(param_2 + 0x18);
      _snprintf(local_18, 0x10, "%u", uVar2);
      pcVar6 = local_18;
      local_9 = 0;
      do {
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      pcVar7 = pcVar3;
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      pcVar6 = pcVar6 + (int)(pcVar7 + ((1 - (int)(pcVar3 + 1)) - (int)(local_18 + 1)));
      pcVar7 = (char *)FUN_0065aaac((uint32_t)pcVar6, 1);
      if (pcVar7 != (char *)0x0) {
        _snprintf(pcVar7, (size_t)pcVar6, "%u%s", uVar2, pcVar3);
        pcVar7[(int)(pcVar6 + -1)] = '\0';
        *(char **)(param_1 + 0x18) = pcVar7;
        return param_1;
      }
    }
  }
  return 0;
}

// 0x6337f7 — observed shape: two string operands concatenated into a new 3-kind node
int FUN_006337f7(int param_1, int param_2)
{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;

  iVar4 = param_1;
  if ((((param_1 != 0) && (*(int *)(param_1 + 4) == 3)) && (*(int *)(param_1 + 0x10) == 10)) &&
     (((param_2 != 0 && (*(int *)(param_2 + 4) == 3)) && (*(int *)(param_2 + 0x10) == 10)))) {
    iVar5 = (int)FUN_0060d19b(0x30);
    if (iVar5 == 0) {
      param_1 = 0;
    }
    else {
      param_1 = FUN_0065ae50((int *)(param_1 + 0x10));
    }
    if (param_1 != 0) {
      pcVar2 = *(char **)(iVar4 + 0x18);
      pcVar3 = *(char **)(param_2 + 0x18);
      pcVar6 = pcVar2;
      do {
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      pcVar7 = pcVar3;
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      pcVar6 = pcVar6 + (int)(pcVar7 + ((1 - (int)(pcVar3 + 1)) - (int)(pcVar2 + 1)));
      pcVar7 = (char *)FUN_0065aaac((uint32_t)pcVar6, 1);
      if (pcVar7 != (char *)0x0) {
        _snprintf(pcVar7, (size_t)pcVar6, "%s%s", pcVar2, pcVar3);
        pcVar7[(int)(pcVar6 + -1)] = '\0';
        *(char **)(param_1 + 0x18) = pcVar7;
        return param_1;
      }
    }
  }
  return 0;
}

// 0x63395f — observed shape: append statement/expression into the receiver's active block
// self = in_ECX receiver (context object)
int FUN_0063395f(void *self_ptr, int param_1, int param_2)
{
  int in_ECX = (int)self_ptr;
  int iVar1;
  int iVar2;

  if (*(int *)(in_ECX + 0x10) == 0) {
    FUN_006323c8();
    iVar1 = -0x7fffbffb;   // E_POINTER-ish status
  }
  else {
    iVar2 = *(int *)(param_1 + 0x14) + 0x10;
    for (iVar1 = FUN_006325ec(iVar2, *(int *)(in_ECX + 0x10)); iVar1 != 0;
        iVar1 = *(int *)(iVar1 + 0xc)) {
      if ((*(int *)(*(int *)(iVar1 + 8) + 0x2c) == 0) &&
         ((*(int *)(param_1 + 0x10) != 2 || (*(int *)(*(int *)(iVar1 + 8) + 0x10) != 2)))) {
        if ((param_2 != 0) &&
           (iVar1 = FUN_0065abd0(param_1, *(undefined4 *)(iVar1 + 8)), iVar1 != 0)) {
          return 0;
        }
        goto LAB_006339ea;
      }
    }
    iVar1 = *(int *)(*(int *)(in_ECX + 0x10) + 0x20);
    if ((((iVar1 == 0) || (*(int *)(*(int *)(in_ECX + 0x10) + 0x10) != 3)) ||
        (*(int *)(iVar1 + 0x10) != 2)) ||
       (iVar1 = FUN_006325ec(iVar2, iVar1), iVar1 == 0)) {
      iVar1 = (int)FUN_0060d19b(0x14);
      iVar2 = 0;
      if (iVar1 != 0) {
        iVar2 = (int)FUN_0065ac49(0, 0, "Stmts");
      }
      if (iVar2 != 0) {
        iVar1 = FUN_0065abf1(param_1);
        *(int *)(iVar2 + 8) = iVar1;
        if (iVar1 != 0) {
          *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(*(int *)(in_ECX + 0x10) + 0x14);
          *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(*(int *)(iVar2 + 8) + 0x20);
          *(undefined4 *)(*(int *)(iVar2 + 8) + 0x24) = *(undefined4 *)(in_ECX + 0x4c);
          *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(*(int *)(iVar2 + 8) + 0x24);
          *(int *)(in_ECX + 0x4c) = *(int *)(in_ECX + 0x4c) + 1;
          *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(*(int *)(in_ECX + 0x10) + 0x18);
          *(int *)(*(int *)(in_ECX + 0x10) + 0x18) = iVar2;
          iVar1 = FUN_006324b9(*(undefined4 *)(in_ECX + 0x10), *(undefined4 *)(iVar2 + 8));
          if (iVar1 < 0) {
            return iVar1;
          }
          return 0;
        }
      }
      iVar1 = -0x7ff8fff2;   // E_OUTOFMEMORY
    }
    else {
LAB_006339ea:
      FUN_00632325(self_ptr, 0, 0, 0);
      iVar1 = -0x7fffbffb;
    }
  }
  return iVar1;
}

// ---------------------------------------------------------------------------
// Signature-table data referenced by 0x633aa9; record stride 0x29 pointers (0xa4 bytes).

extern const char *PTR_s_D3DCOLORtoUBYTE4_006e52bc[];
extern uint8_t UNK_006e5218[];
extern uint8_t DAT_006e52b8[];
extern uint8_t UNK_006e52c0[];
extern uint8_t UNK_006e52d4[];
extern uint8_t UNK_006e52dc[];

extern int  FUN_0063284b(int);
extern int  FUN_00632e37(void *, void *, uint *);
extern void FUN_0065b1db(void);
extern int  FUN_0065b27f(void);
extern int  FUN_0065b377(void);
extern int  FUN_0065bc2f(void);
extern int  FUN_0065b01d(int, int, int, int);
extern int  FUN_0065b679(int, int, int);

// 0x633aa9 — observed shape: match a pre-scanned statement list against a name-keyed
// intrinsic signature table (hand-inlined binary search + per-signature operand match),
// then build the "Decls"/"Values" node pair describing the chosen signature.
undefined4 FUN_00633aa9(int param_1, int *param_2, uint *param_3, int *param_4)
{
  uint8_t bVar1;
  uint8_t *pbVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  uint8_t *pbVar13;
  uint8_t *pbVar14;
  undefined4 *puVar15;
  undefined **ppuVar16;
  bool bVar17;
  uint local_14c[10];
  int local_124[29];
  undefined1 local_b0[20];
  undefined4 local_9c;
  undefined1 local_8c[20];
  uint local_78;
  int aiStack_68[5];
  uint local_54[16];
  uint local_14;
  int *local_10;
  uint local_c;
  uint local_8;

  if (param_3 != (uint *)0x0) {
    *param_3 = 0;
  }
  if (param_4 != (int *)0x0) {
    *param_4 = 0;
  }
  uVar10 = 0;
  iVar9 = (int)param_2;
  if (param_2 != (int *)0x0) {
    // pre-scan: every leading node must be kind 0xd with a kind-9 (literal) left payload
    do {
      iVar6 = *(int *)(iVar9 + 8);
      if ((((iVar6 == 0) || (*(int *)(iVar6 + 4) != 0xd)) || (*(int *)(iVar6 + 0x10) == 0)) ||
         (*(int *)(*(int *)(iVar6 + 0x10) + 4) != 9)) break;
      iVar9 = *(int *)(iVar9 + 0xc);
      uVar10 = uVar10 + 1;
    } while (iVar9 != 0);
    if ((iVar9 != 0) || (4 < uVar10)) {
      return 1;
    }
  }
  pbVar2 = *(uint8_t **)(param_1 + 8);
  local_8 = 0x5e;
  uVar10 = 0;
  // hand-inlined lower_bound over the 0x5e signature table, strcmp-inlined byte loop
  do {
    local_14 = local_8 + uVar10 >> 1;
    pbVar13 = (uint8_t *)(&PTR_s_D3DCOLORtoUBYTE4_006e52bc)[local_14 * 0x29];
    pbVar14 = pbVar2;
    do {
      bVar1 = *pbVar14;
      bVar17 = bVar1 < *pbVar13;
      if (bVar1 != *pbVar13) {
LAB_00633b54:
        iVar9 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);
        goto LAB_00633b59;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar14[1];
      bVar17 = bVar1 < pbVar13[1];
      if (bVar1 != pbVar13[1]) goto LAB_00633b54;
      pbVar14 = pbVar14 + 2;
      pbVar13 = pbVar13 + 2;
    } while (bVar1 != 0);
    iVar9 = 0;
LAB_00633b59:
    if (iVar9 < 1) {
      if (-1 < iVar9) {
        local_8 = local_14 + 1;
        if (local_14 == 0) goto LAB_00633bc4;
        puVar15 = (undefined4 *)(&UNK_006e5218 + local_14 * 0xa4);
        goto LAB_00633b89;
      }
      local_8 = local_14;
    }
    else {
      uVar10 = local_14 + 1;
    }
    local_14 = uVar10;
    uVar10 = local_14;
  } while (local_14 < local_8);
  goto LAB_00633c17;
  while (true) {
    local_14 = local_14 - 1;
    puVar15 = puVar15 + -0x29;
    if (local_14 == 0) break;
LAB_00633b89:
    pbVar13 = (uint8_t *)*puVar15;
    pbVar14 = pbVar2;
    do {
      bVar1 = *pbVar14;
      bVar17 = bVar1 < *pbVar13;
      if (bVar1 != *pbVar13) {
LAB_00633bb0:
        iVar9 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);
        goto LAB_00633bb5;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar14[1];
      bVar17 = bVar1 < pbVar13[1];
      if (bVar1 != pbVar13[1]) goto LAB_00633bb0;
      pbVar14 = pbVar14 + 2;
      pbVar13 = pbVar13 + 2;
    } while (bVar1 != 0);
    iVar9 = 0;
LAB_00633bb5:
    if (iVar9 != 0) break;
  }
LAB_00633bc4:
  if (local_8 < 0x5e) {
    ppuVar16 = &PTR_s_D3DCOLORtoUBYTE4_006e52bc + local_8 * 0x29;
    do {
      pbVar13 = (uint8_t *)*ppuVar16;
      pbVar14 = pbVar2;
      do {
        bVar1 = *pbVar14;
        bVar17 = bVar1 < *pbVar13;
        if (bVar1 != *pbVar13) {
LAB_00633bff:
          iVar9 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);
          goto LAB_00633c04;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar14[1];
        bVar17 = bVar1 < pbVar13[1];
        if (bVar1 != pbVar13[1]) goto LAB_00633bff;
        pbVar14 = pbVar14 + 2;
        pbVar13 = pbVar13 + 2;
      } while (bVar1 != 0);
      iVar9 = 0;
LAB_00633c04:
      if (iVar9 != 0) break;
      local_8 = local_8 + 1;
      ppuVar16 = ppuVar16 + 0x29;
    } while (local_8 < 0x5e);
  }
LAB_00633c17:
  if (local_14 == local_8) {
    return 1;
  }
  // walk every candidate signature record, testing the observed operand list against it
  if (local_14 < local_8) {
    local_10 = (int *)(&DAT_006e52b8 + local_14 * 0xa4);
    do {
      piVar12 = local_10;
      local_54[0] = 0xffffffff;
      local_54[1] = 0xffffffff;
      local_54[2] = 0xffffffff;
      local_54[3] = 0xffffffff;
      local_54[4] = 0xffffffff;
      local_54[10] = 0x1e;
      local_54[0xb] = 0x1e;
      local_54[0xc] = 0x1e;
      local_54[0xd] = 0x1e;
      local_54[0xe] = 0x1e;
      local_54[5] = 5;
      local_54[6] = 5;
      local_54[7] = 5;
      local_54[8] = 5;
      local_54[9] = 5;
      FUN_0065b1db();
      FUN_0065b1db();
      local_c = 1;
      if (param_2 == (int *)0x0) {
LAB_00633dc7:
        if (piVar12[2] != 0) {
          if (local_54[piVar12[3] + 5] == 5) {
            local_54[piVar12[3] + 5] = *(uint *)piVar12[4];
          }
          if (local_54[piVar12[5] + 10] == 0x1e) {
            local_54[piVar12[5] + 10] = *(uint *)piVar12[6];
          }
        }
        local_c = 0;
        piVar12 = local_10 + 6;
        do {
          puVar7 = (uint *)piVar12[-2];
          puVar8 = local_54 + local_c + 5;
          uVar10 = *puVar8;
          if (uVar10 == 5) {
            if (puVar7 != (uint *)0x0) {
              *puVar8 = *puVar7;
            }
          }
          else {
            if ((uVar10 == 0) && ((uVar3 = *puVar7, uVar3 == 1 || (uVar3 == 2)))) {
              *puVar8 = uVar3;
            }
            else {
              for (; (*puVar7 != 5 && (uVar10 != *puVar7)); puVar7 = puVar7 + 1) {
              }
            }
            if (*puVar7 == 5) break;
          }
          puVar8 = (uint *)*piVar12;
          uVar10 = local_54[local_c + 10];
          puVar7 = puVar8;
          if (uVar10 == 0x1e) {
            if (puVar8 != (uint *)0x0) {
              uVar10 = *puVar8;
LAB_00633e57:
              local_54[local_c + 10] = uVar10;
            }
          }
          else {
            for (; (*puVar7 != 0x1e && (uVar10 != *puVar7)); puVar7 = puVar7 + 1) {
            }
            if (*puVar7 == 0x1e) {
              uVar10 = *puVar8;
              goto LAB_00633e57;
            }
          }
          if (local_54[local_c] == 0xffffffff) {
            local_54[local_c] = 1;
          }
          local_c = local_c + 1;
          piVar12 = piVar12 + 8;
        } while (local_c < 5);
        if (local_c == 5) break;
      }
      else {
        piVar12 = piVar12 + 0xb;
        iVar9 = (int)param_2;
        do {
          if ((4 < local_c) || (piVar12[-2] == 0)) break;
          iVar6 = *(int *)(*(int *)(iVar9 + 8) + 0x10);
          uVar10 = local_54[*piVar12 + 5];
          if ((uVar10 == 5) ||
             ((uVar10 == 0 && ((*(int *)(iVar6 + 0x10) == 1 || (*(int *)(iVar6 + 0x10) == 2)))))) {
            iVar5 = *piVar12;
            local_54[iVar5 + 5] = *(uint *)(iVar6 + 0x10);
            aiStack_68[iVar5] = piVar12[1];
          }
          else {
            if (*(uint *)(iVar6 + 0x10) == 0) {
              if ((uVar10 == 0) || (uVar10 == 1)) goto LAB_00633cef;
              bVar17 = uVar10 == 2;
            }
            else {
              bVar17 = *(uint *)(iVar6 + 0x10) == uVar10;
            }
            if (!bVar17) break;
          }
LAB_00633cef:
          iVar5 = piVar12[2];
          if (local_54[iVar5 + 10] == 0x1e) {
            local_54[iVar5 + 10] = *(uint *)(iVar6 + 0x14);
            aiStack_68[iVar5] = piVar12[3];
          }
          else {
            local_78 = local_54[iVar5 + 10];
            local_9c = *(undefined4 *)(iVar6 + 0x14);
            iVar5 = FUN_00632e37(local_8c, local_b0, local_54 + piVar12[2] + 10);
            if (iVar5 < 0) break;
          }
          iVar5 = *(int *)(iVar6 + 0x10);
          if (iVar5 != 0) {
            uVar10 = piVar12[4];
            if ((int)uVar10 < 0) {
              if (*(uint *)(iVar6 + 0x18) < local_54[~uVar10]) {
                local_54[~uVar10] = *(uint *)(iVar6 + 0x18);
              }
            }
            else if (*(uint *)(iVar6 + 0x18) < uVar10) break;
            if (iVar5 != 0) {
              uVar10 = piVar12[5];
              if ((int)uVar10 < 0) {
                if (*(uint *)(iVar6 + 0x1c) < local_54[~uVar10]) {
                  local_54[~uVar10] = *(uint *)(iVar6 + 0x1c);
                }
              }
              else if (*(uint *)(iVar6 + 0x1c) < uVar10) break;
            }
          }
          if (((*(uint8_t *)(piVar12 + -1) & 0x20) != 0) && (iVar6 = FUN_0063284b(iVar6), iVar6 != 0))
            break;
          iVar9 = *(int *)(iVar9 + 0xc);
          local_c = local_c + 1;
          piVar12 = piVar12 + 8;
        } while (iVar9 != 0);
        if ((iVar9 == 0) && ((piVar12 = local_10, 4 < local_c || (local_10[local_c * 8 + 1] == 0))))
          goto LAB_00633dc7;
      }
      local_14 = local_14 + 1;
      local_10 = local_10 + 0x29;
    } while (local_14 < local_8);
  }
  if (local_14 == local_8) {
    return 1;
  }
  if (param_3 != (uint *)0x0) {
    iVar9 = 5;
    do {
      FUN_0065b1db();
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    uVar10 = 0;
    iVar9 = local_14 * 0xa4;
    puVar8 = local_14c;
    puVar7 = (uint *)(&UNK_006e52d4 + iVar9);
    do {
      if (puVar7[-6] == 0) break;
      uVar3 = puVar7[-5];
      if (uVar3 != 0) {
        puVar8[-2] = local_54[puVar7[-4] + 5];
        puVar8[-1] = local_54[puVar7[-2] + 10];
        uVar11 = *puVar7;
        if ((int)uVar11 < 0) {
          uVar11 = local_54[~uVar11];
        }
        *puVar8 = uVar11;
        uVar11 = puVar7[1];
        if ((int)uVar11 < 0) {
          uVar11 = local_54[~uVar11];
        }
        puVar8[1] = uVar11;
        puVar8[2] = uVar3 & 0xc00;
        if ((uVar10 == 0) || ((uVar3 & 0x20) == 0)) {
          puVar8[2] = uVar3 & 0xc00 | 0x200;
        }
      }
      uVar10 = uVar10 + 1;
      puVar7 = puVar7 + 8;
      puVar8 = puVar8 + 9;
    } while (uVar10 < 5);
    iVar6 = (int)FUN_0060d19b(0x40);
    if (iVar6 == 0) {
      local_8 = 0;
    }
    else {
      local_8 = FUN_0065b27f();
    }
    uVar10 = local_8;
    if (local_8 == 0) {
      return 0x8007000e;   // E_OUTOFMEMORY
    }
    if (*(int *)(&UNK_006e52c0 + iVar9) != 0) {
      iVar6 = FUN_0065bc2f();
      *(int *)(uVar10 + 0x20) = iVar6;
      if (iVar6 == 0) {
        return 0x8007000e;
      }
    }
    local_10 = (int *)(uVar10 + 0x24);
    param_2 = (int *)(&UNK_006e52dc + iVar9);
    local_c = 1;
    piVar12 = local_124;
    do {
      piVar4 = local_10;
      if (*param_2 == 0) break;
      iVar9 = (int)FUN_0060d19b(0x14);
      if (iVar9 == 0) {
        iVar9 = 0;
      }
      else {
        iVar9 = (int)FUN_0065ac49(0, 0, "Decls");
      }
      *piVar4 = iVar9;
      if (iVar9 == 0) {
        return 0x8007000e;
      }
      iVar9 = (int)FUN_0060d19b(0x30);
      if (iVar9 == 0) {
        iVar9 = 0;
      }
      else {
        iVar9 = FUN_0065b01d(1, 0, 0, 0);
      }
      if (iVar9 == 0) {
        return 0x8007000e;
      }
      *(int *)(*local_10 + 8) = iVar9;
      iVar6 = (int)FUN_0060d19b(0x30);
      if (iVar6 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_0065ae50((int *)param_1);
      }
      *(int *)(iVar9 + 0x14) = iVar6;
      if (iVar6 == 0) {
        return 0x8007000e;
      }
      *(int *)(iVar6 + 0x18) = *param_2;
      iVar6 = (int)FUN_0060d19b(0x40);
      if (iVar6 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_0065b377();
      }
      if (iVar6 == 0) {
        return 0x8007000e;
      }
      *(int *)(iVar9 + 0x18) = iVar6;
      *(undefined4 *)(iVar6 + 0x10) = 0xffffffff;
      *(int *)(iVar6 + 0x14) = piVar12[-1] * *piVar12;
      *(undefined4 *)(iVar6 + 0x18) = 2;
      *(int *)(iVar6 + 0x1c) = param_2[1];
      iVar9 = FUN_0065bc2f();
      *(int *)(iVar6 + 0x20) = iVar9;
      if (iVar9 == 0) {
        return 0x8007000e;
      }
      param_2 = param_2 + 8;
      local_10 = (int *)(*local_10 + 0xc);
      local_c = local_c + 1;
      piVar12 = piVar12 + 9;
    } while (local_c < 5);
    *param_3 = local_8;
  }
  uVar10 = local_14;
  iVar9 = 0;
  if (param_4 == (int *)0x0) {
    return 0;
  }
  iVar6 = (int)FUN_0060d19b(0x14);
  if (iVar6 != 0) {
    iVar9 = (int)FUN_0065ac49(0, 0, "Values");
  }
  if (iVar9 != 0) {
    iVar6 = (int)FUN_0060d19b(0x40);
    if (iVar6 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = FUN_0065b679(2, *(undefined4 *)(&DAT_006e52b8 + uVar10 * 0xa4), param_1);
    }
    *(int *)(iVar9 + 8) = iVar6;
    if (iVar6 != 0) {
      *param_4 = iVar9;
      return 0;
    }
  }
  return 0x8007000e;
}

// ---------------------------------------------------------------------------

extern int  FUN_005f7fa4(undefined4, int, void *);
extern uint64_t FUN_006329e7(undefined4, undefined4);
extern int  FUN_00632d6c(undefined4, uint, void *);
extern int  FUN_00632650(int, int);
extern void FUN_00632729(int, int);

// 0x634161 — observed shape: structural equality test over a "Udt"-style declaration list
undefined4 FUN_00634161(int param_1, int param_2, int param_3)
{
  uint8_t bVar1;
  int iVar2;
  int iVar3;
  uint8_t *pbVar4;
  uint8_t *pbVar5;
  bool bVar6;
  uint64_t uVar7;
  undefined1 local_20[4];
  int local_1c;
  undefined1 local_14[4];
  int local_10;

  if ((param_2 == 0) != (*(int *)(param_1 + 0x1c) == 0)) {
    return 0xffffffff;
  }
  if (param_2 != 0) {
    iVar3 = FUN_005f7fa4(*(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x18), 0, local_14);
    if ((iVar3 < 0) ||
       (iVar3 = FUN_005f7fa4(*(undefined4 *)(param_2 + 0x18), 0, local_20), iVar3 < 0)) {
      // either name could not be resolved: fall back to a raw inline strcmp
      pbVar5 = *(uint8_t **)(*(int *)(param_1 + 0x1c) + 0x18);
      pbVar4 = *(uint8_t **)(param_2 + 0x18);
      do {
        bVar1 = *pbVar4;
        bVar6 = bVar1 < *pbVar5;
        if (bVar1 != *pbVar5) {
LAB_006341f4:
          iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
          goto LAB_006341f9;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar4[1];
        bVar6 = bVar1 < pbVar5[1];
        if (bVar1 != pbVar5[1]) goto LAB_006341f4;
        pbVar4 = pbVar4 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_006341f9:
      if (iVar3 != 0) {
        return 0xffffffff;
      }
    }
    else if (local_10 != local_1c) {
      return 0xffffffff;
    }
  }
  iVar3 = *(int *)(param_1 + 0x24);
  do {
    if (iVar3 == 0) {
LAB_00634261:
      if (param_3 == 0) {
        return 0;
      }
      return 0xffffffff;
    }
    if (param_3 == 0) {
      if (iVar3 != 0) {
        return 0xffffffff;
      }
      goto LAB_00634261;
    }
    iVar3 = *(int *)(*(int *)(iVar3 + 8) + 0x18);
    iVar2 = *(int *)(*(int *)(param_3 + 8) + 0x18);
    if (*(int *)(iVar3 + 0x1c) != *(int *)(iVar2 + 0x1c)) {
      return 0xffffffff;
    }
    // 64-bit result: low word = equality status, high word = first differing member list
    uVar7 = FUN_006329e7(*(undefined4 *)(iVar3 + 0x20), *(undefined4 *)(iVar2 + 0x20));
    iVar3 = (int)((uint64_t)uVar7 >> 0x20);
    if ((int)uVar7 == 0) {
      return 0xffffffff;
    }
    do {
      iVar3 = *(int *)(iVar3 + 0xc);
      if (iVar3 == 0) break;
    } while (*(int *)(*(int *)(iVar3 + 8) + 4) != 6);
    do {
      param_3 = *(int *)(param_3 + 0xc);
      if (param_3 == 0) break;
    } while (*(int *)(*(int *)(param_3 + 8) + 4) != 6);
  } while (true);
}

// 0x634270 — observed shape: lexicographic parameter-list comparison producing flag bits
int FUN_00634270(undefined4 param_1, undefined4 param_2)
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined1 local_60[20];
  undefined4 local_4c;
  undefined1 local_3c[20];
  undefined4 local_28;
  int local_18;
  undefined4 local_14;
  uint local_10;
  uint local_c;
  int local_8;

  uVar3 = 0;
  local_18 = 0;
  local_c = FUN_00632959(param_1);
  local_10 = FUN_00632959(param_2);
  iVar2 = FUN_006329e7(param_1, param_2);
  if (iVar2 == 0) {
    bVar1 = false;
    local_8 = 0;
    FUN_0065b1db();
    FUN_0065b1db();
    if (local_c != 0) {
      while (uVar3 < local_10) {
        iVar2 = FUN_00632d6c(param_1, uVar3, local_3c);
        if (((iVar2 < 0) || (iVar2 = FUN_00632d6c(param_2, uVar3, local_60), iVar2 < 0)) ||
           (iVar2 = FUN_00632e37(local_3c, local_60, (uint *)&local_14), iVar2 < 0)) {
          bVar1 = true;
          local_8 = 1;
        }
        else {
          iVar2 = FUN_00632650(local_28, local_14);
          if (iVar2 != 0) {
            bVar1 = true;
          }
          iVar2 = FUN_00632650(local_14, local_4c);
          if (iVar2 != 0) {
            local_8 = 1;
          }
        }
        if (((bVar1) && (local_8 != 0)) || (uVar3 = uVar3 + 1, local_c <= uVar3)) break;
      }
    }
    if (local_10 < local_c) {
      local_18 = 4;
    }
    if (bVar1) {
      local_18 = local_18 + 0x200;
    }
    if (local_8 != 0) {
      local_18 = local_18 + 0x10000;
    }
    if (local_c < local_10) {
      local_18 = local_18 + 0x800000;
    }
  }
  else {
    local_18 = 0;
  }
  return local_18;
}

// 0x634393 — observed shape: propagate signedness/const flags onto a parameter node
// self = in_ECX receiver (uint32_t fields)
undefined4 FUN_00634393(uint32_t *self, int param_1, int param_2)
{
  uint uVar1;

  uVar1 = *(uint *)(param_1 + 0x10);
  if ((uVar1 & 0x200) != 0) {
    FUN_00632729(param_2, 1);
  }
  if (((param_2 == 0) || (*(int *)(param_2 + 4) != 9)) || (*(int *)(param_2 + 0x10) != 2)) {
    if ((uVar1 & 0xc00) != 0) {
      FUN_00632325(self);
      return 0x80004005;   // E_FAIL
    }
  }
  else {
    if ((uVar1 & 0xc00) == 0) {
      uVar1 = uVar1 | *(uint *)(self[1] + 0x38);
    }
    if ((uVar1 & 0xc00) == 0) {
      if ((*self & 8) == 0) {
        if ((*self & 0x10) != 0) {
          uVar1 = uVar1 | 0x800;
        }
      }
      else {
        uVar1 = uVar1 | 0x400;
      }
    }
    if ((uVar1 & 0x400) != 0) {
      *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffff7ff | 0x400;
    }
    if ((uVar1 & 0x800) != 0) {
      *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffbff | 0x800;
    }
  }
  return 0;
}

// ---------------------------------------------------------------------------

extern int  FUN_00632a99(void *, int, undefined1 *);
extern int  FUN_0065b202(int, int, int, int, uint);
extern int  FUN_0065b52c(int, int, int, int, int, undefined4);
extern int  FUN_0065b6ae(int, uint64_t, undefined4);
extern int  FUN_0065b6e3(int, const char *, const char *, undefined4);

// 0x634446 — observed shape: assignability/compatibility test between two type nodes
undefined4 FUN_00634446(undefined1 *param_1, undefined1 *param_2, int param_3)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined1 *puVar6;
  bool bVar7;
  undefined1 local_50[16];
  undefined4 local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_2c[16];
  undefined4 local_1c;
  undefined4 local_14;
  undefined4 local_10;

  if (param_3 == 0) {
    if (param_1 == (undefined1 *)0x0) {
      if (param_2 == (undefined1 *)0x0) {
        return 1;
      }
      return 0;
    }
  }
  else if (param_1 == (undefined1 *)0x0) {
    return 1;
  }
  if (param_2 == (undefined1 *)0x0) {
    return 0;
  }
  FUN_0065b1db();
  FUN_0065b1db();
  if (*(int *)(param_1 + 4) == 9) {
    puVar6 = param_1;
  }
  else {
    // synthesize an array descriptor for the left operand
    puVar6 = local_50;
    local_40 = 4;
    local_38 = 1;
    local_34 = FUN_00632959(param_1);
    if ((param_3 != 0) && (iVar2 = FUN_006328e2((int)param_1), iVar2 != 0)) {
      local_40 = 1;
    }
  }
  if (*(int *)(param_2 + 4) == 9) {
    puVar4 = param_2;
  }
  else {
    puVar4 = local_2c;
    local_1c = 4;
    local_14 = 1;
    local_10 = FUN_00632959(param_2);
    if ((param_3 != 0) && (iVar2 = FUN_006328e2((int)param_2), iVar2 != 0)) {
      local_1c = 1;
    }
  }
  iVar2 = *(int *)(puVar6 + 0x10);
  if ((iVar2 == 4) || (iVar1 = *(int *)(puVar4 + 0x10), iVar1 == 4)) {
    uVar3 = *(int *)(puVar6 + 0x1c) * *(int *)(puVar6 + 0x18);
    if (param_3 == 0) {
      if (iVar2 != *(int *)(puVar4 + 0x10)) {
        return 0;
      }
      if (uVar3 != *(int *)(puVar4 + 0x1c) * *(int *)(puVar4 + 0x18)) {
        return 0;
      }
      uVar5 = 0;
      if (uVar3 == 0) {
        return 1;
      }
      do {
        iVar2 = FUN_00632d6c((undefined4)(uintptr_t)param_1, uVar5, local_50);
        if (iVar2 < 0) {
          return 0;
        }
        iVar2 = FUN_00632d6c((undefined4)(uintptr_t)param_2, uVar5, local_2c);
        if (iVar2 < 0) {
          return 0;
        }
        iVar2 = (int)FUN_006329e7((undefined4)(uintptr_t)local_50, (undefined4)(uintptr_t)local_2c);
        if (iVar2 == 0) {
          return 0;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar3);
      return 1;
    }
    if ((uint)(*(int *)(puVar4 + 0x1c) * *(int *)(puVar4 + 0x18)) < uVar3) {
      return 0;
    }
    uVar5 = 0;
    if (uVar3 != 0) {
      do {
        iVar2 = FUN_00632d6c((undefined4)(uintptr_t)param_1, uVar5, local_50);
        if (iVar2 < 0) {
          return 0;
        }
        iVar2 = FUN_00632d6c((undefined4)(uintptr_t)param_2, uVar5, local_2c);
        if (iVar2 < 0) {
          return 0;
        }
        iVar2 = (int)FUN_00634446(local_50, local_2c, 1);
        if (iVar2 == 0) {
          return 0;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar3);
    }
    return 1;
  }
  if (iVar2 != 0) {
    if (iVar2 != 1) {
      if (iVar2 == 2) {
        if (iVar1 == 0) {
          return 1;
        }
        if (iVar1 != 1) {
          if (iVar1 == 2) {
            if (*(uint *)(puVar4 + 0x18) < *(uint *)(puVar6 + 0x18)) {
              return 0;
            }
            goto LAB_006345f1;
          }
          goto joined_r0x00634605;
        }
        uVar3 = *(uint *)(puVar6 + 0x18);
        if ((uVar3 == 1) && (*(uint *)(puVar4 + 0x1c) < *(uint *)(puVar6 + 0x1c))) {
          return 0;
        }
        iVar2 = *(int *)(puVar6 + 0x1c);
        if ((iVar2 == 1) && (*(uint *)(puVar4 + 0x1c) < uVar3)) {
          return 0;
        }
        if (uVar3 == 1) {
          return 1;
        }
        if (iVar2 == 1) {
          return 1;
        }
        bVar7 = uVar3 * iVar2 == *(int *)(puVar4 + 0x1c);
      }
      else {
        if (iVar2 != 3) {
          return 1;
        }
        if (iVar1 != 3) {
          return 0;
        }
        iVar2 = *(int *)(puVar4 + 0x14);
        if (iVar2 == 0xd) {
          return 1;
        }
        if (iVar2 == 0xf) {
          iVar2 = *(int *)(puVar6 + 0x14);
          if (iVar2 == 0xf) {
            return 1;
          }
          if (iVar2 == 0x10) {
            return 1;
          }
          if (iVar2 == 0x11) {
            return 1;
          }
          if (iVar2 == 0x12) {
            return 1;
          }
          bVar7 = iVar2 == 0x13;
        }
        else if (iVar2 == 0x14) {
          iVar2 = *(int *)(puVar6 + 0x14);
          if (iVar2 == 0x14) {
            return 1;
          }
          if (iVar2 == 0x15) {
            return 1;
          }
          if (iVar2 == 0x16) {
            return 1;
          }
          if (iVar2 == 0x17) {
            return 1;
          }
          bVar7 = iVar2 == 0x18;
        }
        else {
          bVar7 = *(int *)(puVar6 + 0x14) == iVar2;
        }
      }
LAB_00634690:
      if (bVar7) {
        return 1;
      }
      return 0;
    }
    if (iVar1 == 0) {
      return 1;
    }
    if (iVar1 == 1) {
LAB_006345f1:
      if (*(uint *)(puVar4 + 0x1c) < *(uint *)(puVar6 + 0x1c)) {
        return 0;
      }
      return 1;
    }
    if (iVar1 == 2) {
      uVar3 = *(uint *)(puVar4 + 0x18);
      if ((uVar3 == 1) && (*(uint *)(puVar4 + 0x1c) < *(uint *)(puVar6 + 0x1c))) {
        return 0;
      }
      iVar2 = *(int *)(puVar4 + 0x1c);
      if ((iVar2 == 1) && (uVar3 < *(uint *)(puVar6 + 0x1c))) {
        return 0;
      }
      if (uVar3 == 1) {
        return 1;
      }
      if (iVar2 == 1) {
        return 1;
      }
      bVar7 = uVar3 * iVar2 == *(int *)(puVar6 + 0x1c);
      goto LAB_00634690;
    }
  }
joined_r0x00634605:
  if (iVar1 == 3) {
    return 0;
  }
  return 1;
}

// 0x63477e — observed shape: emit "cannot convert" diagnostic after a narrowing/widening test
// self = in_ECX receiver (diagnostic context)
void FUN_0063477e(void *self, undefined4 param_1, int param_2, undefined1 *param_3,
                  undefined1 *param_4, int param_5)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined1 *puVar6;
  char *pcVar7;
  bool bVar8;
  undefined1 local_250[256];
  undefined1 local_150[256];
  undefined1 local_50[16];
  undefined4 local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_2c[16];
  undefined4 local_1c;
  undefined4 local_14;
  undefined4 local_10;

  if ((param_5 != 0) || (param_3 == (undefined1 *)0x0)) goto LAB_00634a85;
  if (param_4 != (undefined1 *)0x0) {
    FUN_0065b1db();
    FUN_0065b1db();
    puVar4 = param_3;
    if (*(int *)(param_3 + 4) != 9) {
      puVar4 = local_2c;
      local_1c = 4;
      local_14 = 1;
      local_10 = FUN_00632959(param_3);
      iVar2 = FUN_006328e2((int)param_3);
      if (iVar2 != 0) {
        local_1c = 1;
      }
    }
    puVar6 = param_4;
    if (*(int *)(param_4 + 4) != 9) {
      puVar6 = local_50;
      local_40 = 4;
      local_38 = 1;
      local_34 = FUN_00632959(param_4);
      iVar2 = FUN_006328e2((int)param_4);
      if (iVar2 != 0) {
        local_40 = 1;
      }
    }
    iVar2 = *(int *)(puVar4 + 0x10);
    if ((iVar2 == 4) || (iVar1 = *(int *)(puVar6 + 0x10), iVar1 == 4)) {
      uVar3 = *(int *)(puVar4 + 0x1c) * *(int *)(puVar4 + 0x18);
      if (uVar3 <= (uint)(*(int *)(puVar6 + 0x1c) * *(int *)(puVar6 + 0x18))) {
        uVar5 = 0;
        if (uVar3 != 0) {
          do {
            iVar2 = FUN_00632d6c((undefined4)(uintptr_t)param_3, uVar5, local_2c);
            if (((iVar2 < 0) ||
                (iVar2 = FUN_00632d6c((undefined4)(uintptr_t)param_4, uVar5, local_50), iVar2 < 0)) ||
               (iVar2 = (int)FUN_00634446(local_2c, local_50, 1), iVar2 == 0)) goto LAB_0063486f;
            uVar5 = uVar5 + 1;
          } while (uVar5 < uVar3);
        }
        goto LAB_00634a85;
      }
    }
    else {
      if (iVar2 != 0) {
        if (iVar2 == 1) {
          if (iVar1 != 0) {
            if (iVar1 == 1) {
              if (*(uint *)(puVar4 + 0x1c) <= *(uint *)(puVar6 + 0x1c)) goto LAB_00634a85;
            }
            else {
              if (iVar1 != 2) goto LAB_00634988;
              uVar3 = *(uint *)(puVar6 + 0x18);
              if (((uVar3 != 1) || (*(uint *)(puVar4 + 0x1c) <= *(uint *)(puVar6 + 0x1c))) &&
                 ((iVar2 = *(int *)(puVar6 + 0x1c), iVar2 != 1 ||
                  (*(uint *)(puVar4 + 0x1c) <= uVar3)))) {
                if ((uVar3 != 1) && (iVar2 != 1)) {
                  bVar8 = uVar3 * iVar2 == *(int *)(puVar4 + 0x1c);
                  goto LAB_00634a0d;
                }
                goto LAB_00634a85;
              }
            }
            goto LAB_0063486f;
          }
        }
        else if (iVar2 == 2) {
          if (iVar1 != 0) {
            if (iVar1 == 1) {
              uVar3 = *(uint *)(puVar4 + 0x18);
              if (((uVar3 != 1) || (*(uint *)(puVar4 + 0x1c) <= *(uint *)(puVar6 + 0x1c))) &&
                 ((iVar2 = *(int *)(puVar4 + 0x1c), iVar2 != 1 ||
                  (uVar3 <= *(uint *)(puVar6 + 0x1c))))) {
                if ((uVar3 != 1) && (iVar2 != 1)) {
                  bVar8 = uVar3 * iVar2 == *(int *)(puVar6 + 0x1c);
                  goto LAB_00634a0d;
                }
                goto LAB_00634a85;
              }
            }
            else {
              if (iVar1 != 2) goto LAB_00634988;
              if ((*(uint *)(puVar4 + 0x18) <= *(uint *)(puVar6 + 0x18)) &&
                 (*(uint *)(puVar4 + 0x1c) <= *(uint *)(puVar6 + 0x1c))) goto LAB_00634a85;
            }
            goto LAB_0063486f;
          }
        }
        else if (iVar2 == 3) {
          if (iVar1 != 3) goto LAB_0063486f;
          iVar2 = *(int *)(puVar6 + 0x14);
          if (iVar2 != 0xd) {
            if (iVar2 == 0xf) {
              iVar2 = *(int *)(puVar4 + 0x14);
              if (((iVar2 == 0xf) || (iVar2 == 0x10)) || ((iVar2 == 0x11 || (iVar2 == 0x12))))
                goto LAB_00634a85;
              bVar8 = iVar2 == 0x13;
            }
            else if (iVar2 == 0x14) {
              iVar2 = *(int *)(puVar4 + 0x14);
              if (((iVar2 == 0x14) || (iVar2 == 0x15)) || ((iVar2 == 0x16 || (iVar2 == 0x17))))
                goto LAB_00634a85;
              bVar8 = iVar2 == 0x18;
            }
            else {
              bVar8 = *(int *)(puVar4 + 0x14) == iVar2;
            }
LAB_00634a0d:
            if (!bVar8) goto LAB_0063486f;
          }
        }
LAB_00634a85:
        pcVar7 = (char *)"";
        goto LAB_00634874;
      }
LAB_00634988:
      if (iVar1 != 3) goto LAB_00634a85;
    }
  }
LAB_0063486f:
  pcVar7 = (char *)"implicitly ";
LAB_00634874:
  FUN_00632a99(local_150, 0xff, param_3);
  FUN_00632a99(local_250, 0xff, param_4);
  if (param_2 == 0) {
    FUN_00632325(self, param_1, 0xbc9, "cannot %sconvert from '%s' to '%s'", pcVar7, local_250,
                 local_150);
  }
  else {
    FUN_00632325(self, param_1, 0xbc9, "'%s': cannot %sconvert from '%s' to '%s'", param_2, pcVar7,
                 local_250, local_150);
  }
  return;
}

// 0x634aaf — observed shape: coerce one typed value node to another, caching the result
int FUN_00634aaf(int *param_1, int *param_2, undefined4 *param_3, undefined4 *param_4, int *param_5)
{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;

  piVar1 = param_2;
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined4 *)0x0)) {
    return -0x7fffbffb;
  }
  *param_3 = 0;
  *param_4 = 0;
  if (param_5 != (int *)0x0) {
    *param_5 = 0;
  }
  if (param_1 == (int *)0x0) {
    if (param_2 == (int *)0x0) {
      return 0;
    }
    return -0x7fffbffb;
  }
  if (param_2 == (int *)0x0) {
    return -0x7fffbffb;
  }
  uVar2 = FUN_00632959(param_1);
  uVar3 = FUN_00632959(piVar1);
  if ((uVar2 < uVar3) ||
     (iVar4 = (int)FUN_00634446((undefined1 *)param_1, (undefined1 *)piVar1, 0), iVar4 == 0)) {
    iVar4 = (int)FUN_00634446((undefined1 *)piVar1, (undefined1 *)param_1, 0);
    if (iVar4 != 0) {
      piVar5 = piVar1;
      goto LAB_00634b49;
    }
    iVar4 = (int)FUN_00634446((undefined1 *)param_1, (undefined1 *)piVar1, 0);
    if (iVar4 == 0) {
      return -0x7fffbffb;
    }
  }
  piVar5 = param_1;
LAB_00634b49:
  iVar4 = (int)FUN_00632e37(param_1, piVar1, (uint *)&param_2);
  piVar1 = param_2;
  if (iVar4 < 0) {
    return iVar4;
  }
  if ((int *)piVar5[5] != param_2) {
    // virtual clone through (*piVar5)[1]
    piVar5 = (int *)((int *(*)(void *)) * (int *)(*piVar5 + 4))(piVar5);
    if (piVar5 == (int *)0x0) {
      return -0x7ff8fff2;
    }
    piVar5[5] = (int)piVar1;
  }
  piVar1 = param_5;
  if (param_5 != (int *)0x0) {
    iVar4 = ((int (*)(void *)) * (int *)(*piVar5 + 4))(piVar5);
    *piVar1 = iVar4;
    if (iVar4 == 0) {
      return -0x7ff8fff2;
    }
    FUN_00632729(iVar4, 1);
  }
  *param_3 = piVar5;
  *param_4 = piVar5;
  return 0;
}

// 0x634bad — observed shape: build a literal "Value" node for an integer/double constant
int FUN_00634bad(int param_1, undefined4 param_2, uint64_t param_3, undefined4 param_4)
{
  int iVar1;
  int iVar2;
  int local_8;

  local_8 = 2;
  if (param_1 == 0) {
    local_8 = 0;
  }
  else if (0 < param_1) {
    if (param_1 < 5) {
      local_8 = 1;
    }
    else if (param_1 < 9) {
      local_8 = 2;
    }
    else if (param_1 < 0xd) {
      local_8 = 3;
    }
  }
  iVar1 = (int)FUN_0060d19b(0x50);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_0065b52c(0, 0, 0, 0, 1, param_4);
  }
  if (iVar1 == 0) {
    return 0;
  }
  iVar2 = (int)FUN_0060d19b(0x24);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0065b202(0, param_1, 1, 1, 0x200);
  }
  *(int *)(iVar1 + 0x10) = iVar2;
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = (int)FUN_0060d19b(0x40);
  if (local_8 == 3) {
    if (iVar2 != 0) {
      iVar2 = FUN_0065b6ae(3, param_3, param_4);
      goto LAB_00634c82;
    }
  }
  else if (iVar2 != 0) {
    iVar2 = FUN_0065b679(local_8, param_2, param_4);
    goto LAB_00634c82;
  }
  iVar2 = 0;
LAB_00634c82:
  *(int *)(iVar1 + 0x20) = iVar2;
  if (iVar2 != 0) {
    iVar2 = (int)FUN_0060d19b(0x14);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (int)FUN_0065ac49(*(undefined4 *)(iVar1 + 0x20), 0, "Value");
    }
    if (iVar2 != 0) {
      *(int *)(iVar1 + 0x20) = iVar2;
      FUN_0063336c(iVar1);
      return iVar1;
    }
  }
  return 0;
}

// 0x634cc5 — observed shape: map a literal node kind to an intrinsic index, then construct
// self = in_ECX receiver (node whose +0x20 is the type descriptor slot)
void FUN_00634cc5(void *self, int param_1)
{
  uint64_t uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;

  uVar1 = 0;
  uVar4 = 0;
  piVar3 = (int *)((int)self + 0x20);
  uVar5 = 5;
  if ((param_1 != 0) && (*(int *)(param_1 + 4) == 3)) {
    piVar3 = (int *)(param_1 + 0x10);
    iVar2 = *piVar3;
    if (iVar2 == 2) {
      uVar4 = *(uint *)(param_1 + 0x18);
      uVar5 = (uVar4 & 0xbfffffff | 0x20000000) >> 0x1d;
    }
    else {
      if (iVar2 == 3) {
        uVar5 = 4;
      }
      else {
        if (iVar2 != 4) {
          if (iVar2 == 5) {
            uVar5 = 9;
          }
          else if (iVar2 == 6) {
            uVar5 = 10;
          }
          else if (iVar2 == 7) {
            uVar5 = 0xb;
          }
          else {
            if (iVar2 != 8) goto LAB_00634d36;
            uVar5 = 0xc;
          }
          uVar1 = *(uint64_t *)(param_1 + 0x18);
          goto LAB_00634d36;
        }
        uVar5 = 8;
      }
      uVar4 = *(uint *)(param_1 + 0x18);
    }
  }
LAB_00634d36:
  FUN_00634bad((int)uVar5, uVar4, uVar1, (undefined4)(uintptr_t)piVar3);
  return;
}

// 0x634d49 — observed shape: build a string-literal "Value" node from a source token
int FUN_00634d49(int param_1)
{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;

  if (param_1 != 0) {
    iVar3 = (int)FUN_0060d19b(0x50);
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_0065b52c(0, 0, 0, 0, 1, param_1 + 0x10);
    }
    if (iVar3 != 0) {
      iVar4 = (int)FUN_0060d19b(0x24);
      if (iVar4 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_0065b202(3, 0xe, 1, 1, 0x200);
      }
      *(int *)(iVar3 + 0x10) = iVar4;
      if (iVar4 != 0) {
        iVar4 = (int)FUN_0060d19b(0x40);
        if (iVar4 == 0) {
          iVar4 = 0;
        }
        else {
          pcVar2 = *(char **)(param_1 + 0x18);
          pcVar5 = pcVar2;
          do {
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = FUN_0065b6e3(5, pcVar2, pcVar5 + (1 - (int)(pcVar2 + 1)), param_1 + 0x10);
        }
        *(int *)(iVar3 + 0x20) = iVar4;
        if (iVar4 != 0) {
          iVar4 = (int)FUN_0060d19b(0x14);
          if (iVar4 == 0) {
            iVar4 = 0;
          }
          else {
            iVar4 = (int)FUN_0065ac49(*(undefined4 *)(iVar3 + 0x20), 0, "Value");
          }
          if (iVar4 != 0) {
            *(int *)(iVar3 + 0x20) = iVar4;
            FUN_0063336c(iVar3);
            return iVar3;
          }
        }
      }
    }
  }
  return 0;
}
