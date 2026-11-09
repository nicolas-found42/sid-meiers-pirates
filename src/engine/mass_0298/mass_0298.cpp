// Sid Meier's Pirates! (2004) — reconstruction batch mass_0298
// PE32 i386; Ghidra 12.2 pseudocode candidates for 0x641a6c .. 0x643e7a.
#include <cstdint>
#include <cstddef>

// ---- referenced helpers and globals (observed in the supplied listings) ----
void FUN_006417e8(void *p1, void *p2, void *p3, uint32_t p4, uint32_t p5);
void FUN_00641ac9(int *param_1, int *param_2, int *param_3, int param_4, uint32_t param_5,
                  uint16_t *param_6, uint32_t param_7);
void FUN_00641ef0(int *param_1, int *param_2, int *param_3, int param_4, uint32_t param_5,
                  uint16_t *param_6, uint32_t param_7);
void FUN_00642362(int *param_1, int *param_2, int *param_3, int param_4, uint32_t param_5,
                  uint16_t *param_6, uint32_t param_7);
void FUN_0064270e(int *param_1, int *param_2, float *param_3, int param_4, uint32_t param_5,
                  uint16_t *param_6, uint32_t param_7);
void FUN_00642b18(int *param_1, int *param_2, int *param_3, int param_4, uint32_t param_5,
                  uint16_t *param_6, uint32_t *param_7);

void *FUN_00533c78(uint32_t size);
void operator_delete(void *p);
int FUN_0063d6bb(uint32_t a, int b, uint32_t c, uint16_t d);
int FUN_0063d772(int a);
int FUN_0063da83(uint16_t a, uint32_t b, int c);
int FUN_0063f27d(int a, int b);
void FUN_005f8ea2(int a);
int FUN_0063e055(uint32_t a, void *b, void *c, void *d, uint16_t *e);
void FUN_004127b0(void *dst, int a, int count, void (*fn)(void));
int FUN_0063ea6b(int a, int b);
int FUN_0063e97c(int a, int b, int c, int d, int *e);
int FUN_0063dd50(void *a, int *b, int *c, uint32_t *d);
void FUN_0063e44e(void);
int FUN_006294f9(uint32_t a, int **b);
void FUN_0063e5ce(uint32_t a);
void FUN_006338c7(void);
void FUN_00412770(void *p, int a, uint32_t b, void (*fn)(void));
int32_t ftol(void); // x87 FISTP helper as rendered by the provider

extern uint32_t UNK_006ec0c8;
extern uint32_t UNK_006ec0c4;
extern uint8_t DAT_006ea468[];
void LAB_0063e2de(void);

// 0x641a6c — observed shape
void FUN_00641a6c(uint8_t param_1, uint8_t param_2, uint8_t param_3, uint32_t param_4,
                  uint32_t param_5)
{
  FUN_006417e8(&param_1, &param_2, &param_3, param_4, param_5);
  return;
}

// 0x641a99 — observed shape
void FUN_00641a99(void *self_)
{
  int *self = (int *)self_;
  int iVar1;
  int *piVar2;

  iVar1 = self[0];
  if (((iVar1 == 4) || ((4 < iVar1 && ((iVar1 < 10 || (iVar1 == 0xf)) || (iVar1 == 0x10))))) &&
      (piVar2 = (int *)self[1], piVar2 != (int *)0x0)) {
    (*(void (**)(void *))(*(uintptr_t *)piVar2 + 8))((void *)piVar2);
    self[1] = 0;
  }
  return;
}

// 0x641ac9 — observed shape
void FUN_00641ac9(int *param_1, int *param_2, int *param_3, int param_4, uint32_t param_5,
                  uint16_t *param_6, uint32_t param_7)
{
  float *pfVar1;
  int *piVar2;
  int *piVar4;
  int *piVar5;
  uint32_t uVar6;
  uint16_t *puVar7;
  int iVar8;
  float *pfVar9;
  uint32_t uVar10;
  float *pfVar11;
  float *pfVar12;
  uint32_t uVar13;
  int iVar14;
  uint32_t *puVar15;
  int iVar16;
  uint32_t *puVar17;
  int local_10;
  uint32_t local_c;
  uint32_t local_8;

  piVar2 = param_3;
  piVar5 = param_2;
  if (param_4 == 0) {
    uVar10 = *(uint32_t *)(*param_1 + 4);
    puVar7 = param_6;
  }
  else {
    uVar10 = (uint32_t)*(uint16_t *)(uintptr_t)(param_5 + param_4);
    puVar7 = (uint16_t *)(uintptr_t)(param_5 + param_4);
  }
  if (param_7 == 0xffffffff) {
    param_5 = *(uint32_t *)(*param_1 + 0x10);
    if (param_5 == 0) {
      param_5 = 1;
    }
  }
  else {
    param_5 = param_7;
  }
  if ((int)uVar10 < 0) {
    return;
  }
  if ((int)uVar10 < 2) {
    goto LAB_00641d60;
  }
  if (uVar10 != 2) {
    if (uVar10 != 3) {
      if (uVar10 != 5) {
        return;
      }
      local_c = 0;
      local_10 = 0;
      if (param_4 != 0) {
        local_10 = *(int *)(puVar7 + 6) + param_4;
      }
      local_8 = 0;
      uVar10 = *(uint32_t *)(*param_1 + 0x14);
      iVar8 = *param_1 + 0x18;
      *param_1 = iVar8;
      if (param_5 == 0) {
        return;
      }
      do {
        if (*(int *)param_6 == 0) {
          return;
        }
        param_7 = 0;
        *param_1 = iVar8;
        if (uVar10 != 0) {
          puVar15 = (uint32_t *)(local_10 + 4);
          do {
            if (*(int *)param_6 == 0) break;
            if (param_4 != 0) {
              local_c = *puVar15;
            }
            FUN_00641ac9(param_1, param_2, param_3, param_4, local_c, param_6, 0xffffffff);
            param_7 = param_7 + 1;
            puVar15 = puVar15 + 2;
          } while (param_7 < uVar10);
        }
        local_8 = local_8 + 1;
        if (param_5 <= local_8) {
          return;
        }
      } while (true);
    }
    goto LAB_00641d60;
  }
  piVar4 = (int *)*param_1;
  uVar10 = piVar4[5];
  uVar6 = piVar4[6];
  iVar8 = *piVar4;
  if (iVar8 == 1) {
    iVar8 = *(int *)param_6;
    param_2 = (int *)*param_2;
    local_c = 0;
    iVar14 = *param_3;
    if (param_5 != 0) {
      do {
        if (iVar8 == 0) break;
        local_8 = 0;
        if (uVar10 != 0) {
          do {
            uVar13 = 0;
            if (iVar8 == 0) break;
            if (uVar6 != 0) {
              iVar16 = local_8 << 2;
              do {
                piVar2 = (int *)(iVar16 + *piVar5);
                iVar16 = iVar16 + 0x10;
                *(float *)(iVar14 + uVar13 * 4) = (float)*piVar2;
                uVar13 = uVar13 + 1;
              } while (uVar13 < uVar6);
            }
            iVar14 = iVar14 + 0x10;
            iVar8 = iVar8 + -1;
            local_8 = local_8 + 1;
          } while (local_8 < uVar10);
        }
        param_2 = (int *)((int)param_2 + 0x40);
        local_c = local_c + 1;
      } while (local_c < param_5);
    }
  }
  else {
    if (iVar8 != 2) {
      if (iVar8 != 3) {
        return;
      }
      local_c = 0;
      iVar8 = *param_3;
      iVar14 = *(int *)param_6;
      puVar15 = (uint32_t *)*param_2;
      if (param_5 != 0) {
        do {
          if (iVar14 == 0) break;
          local_8 = 0;
          if (uVar10 != 0) {
            param_3 = (int *)puVar15;
            do {
              if (iVar14 == 0) break;
              uVar13 = 0;
              if (uVar6 != 0) {
                puVar17 = (uint32_t *)param_3;
                do {
                  uint32_t uVar3 = *puVar17;
                  puVar17 = puVar17 + 4;
                  *(uint32_t *)(iVar8 + uVar13 * 4) = uVar3;
                  uVar13 = uVar13 + 1;
                } while (uVar13 < uVar6);
              }
              param_3 = param_3 + 1;
              iVar8 = iVar8 + 0x10;
              iVar14 = iVar14 + -1;
              local_8 = local_8 + 1;
            } while (local_8 < uVar10);
          }
          puVar15 = puVar15 + 0x10;
          local_c = local_c + 1;
        } while (local_c < param_5);
      }
      *piVar2 = iVar8;
      *(int *)param_6 = iVar14;
      *param_2 = (int)puVar15;
      goto LAB_00641d58;
    }
    iVar8 = *(int *)param_6;
    param_2 = (int *)*param_2;
    local_c = 0;
    iVar14 = *param_3;
    if (param_5 != 0) {
      do {
        if (iVar8 == 0) break;
        local_8 = 0;
        if (uVar10 != 0) {
          do {
            uVar13 = 0;
            if (iVar8 == 0) break;
            if (uVar6 != 0) {
              iVar16 = local_8 << 2;
              do {
                piVar2 = (int *)(iVar16 + *piVar5);
                iVar16 = iVar16 + 0x10;
                *(float *)(iVar14 + uVar13 * 4) = (float)*piVar2;
                uVar13 = uVar13 + 1;
              } while (uVar13 < uVar6);
            }
            iVar14 = iVar14 + 0x10;
            iVar8 = iVar8 + -1;
            local_8 = local_8 + 1;
          } while (local_8 < uVar10);
        }
        param_2 = (int *)((int)param_2 + 0x40);
        local_c = local_c + 1;
      } while (local_c < param_5);
    }
  }
  *param_3 = iVar14;
  *(int *)param_6 = iVar8;
  *piVar5 = (int)param_2;
LAB_00641d58:
  *param_1 = *param_1 + 0x1c;
  return;

LAB_00641d60:
  piVar5 = (int *)*param_1;
  iVar8 = piVar5[5];
  iVar14 = *piVar5;
  uVar6 = piVar5[6];
  param_7 = 0;
  if (uVar10 == 3) {
    param_7 = (4 - uVar6) * 4;
  }
  if (iVar14 == 1) {
    pfVar12 = (float *)*param_3;
    iVar14 = *(int *)param_6;
    pfVar9 = (float *)*param_2;
    local_8 = 0;
    if (param_5 != 0) {
      do {
        if (iVar14 == 0) break;
        local_c = 0;
        if (uVar6 != 0) {
          do {
            if (iVar14 == 0) break;
            if (iVar8 != 0) {
              iVar16 = iVar8;
              pfVar11 = pfVar12;
              do {
                *pfVar11 = (float)*(int *)(((int)pfVar9 - (int)pfVar12) + (int)pfVar11);
                pfVar11 = pfVar11 + 1;
                iVar16 = iVar16 + -1;
              } while (iVar16 != 0);
            }
            pfVar12 = pfVar12 + 4;
            pfVar9 = pfVar9 + 4;
            iVar14 = iVar14 + -1;
            local_c = local_c + 1;
          } while (local_c < uVar6);
        }
        local_8 = local_8 + 1;
        pfVar9 = pfVar9 + param_7;
      } while (local_8 < param_5);
    }
  }
  else if (iVar14 == 2) {
    pfVar12 = (float *)*param_3;
    iVar14 = *(int *)param_6;
    pfVar9 = (float *)*param_2;
    local_8 = 0;
    if (param_5 != 0) {
      do {
        if (iVar14 == 0) break;
        local_c = 0;
        if (uVar6 != 0) {
          do {
            if (iVar14 == 0) break;
            if (iVar8 != 0) {
              iVar16 = iVar8;
              pfVar11 = pfVar12;
              do {
                *pfVar11 = (float)*(int *)(((int)pfVar9 - (int)pfVar12) + (int)pfVar11);
                pfVar11 = pfVar11 + 1;
                iVar16 = iVar16 + -1;
              } while (iVar16 != 0);
            }
            pfVar12 = pfVar12 + 4;
            pfVar9 = pfVar9 + 4;
            iVar14 = iVar14 + -1;
            local_c = local_c + 1;
          } while (local_c < uVar6);
        }
        local_8 = local_8 + 1;
        pfVar9 = pfVar9 + param_7;
      } while (local_8 < param_5);
    }
  }
  else {
    if (iVar14 != 3) {
      return;
    }
    iVar14 = *(int *)param_6;
    pfVar12 = (float *)*param_3;
    pfVar9 = (float *)*param_2;
    param_3 = (int *)0x0;
    if (param_5 != 0) {
      do {
        if (iVar14 == 0) break;
        uVar10 = 0;
        pfVar11 = pfVar12;
        if (uVar6 != 0) {
          do {
            pfVar12 = pfVar11;
            if (iVar14 == 0) break;
            *pfVar11 = *pfVar9;
            pfVar11[1] = pfVar9[1];
            pfVar11[2] = pfVar9[2];
            pfVar1 = pfVar9 + 3;
            pfVar12 = pfVar11 + 4;
            pfVar9 = pfVar9 + 4;
            pfVar11[3] = *pfVar1;
            iVar14 = iVar14 + -1;
            uVar10 = uVar10 + 1;
            pfVar11 = pfVar12;
          } while (uVar10 < uVar6);
        }
        param_3 = (int *)((int)param_3 + 1);
        pfVar9 = pfVar9 + param_7;
      } while ((uintptr_t)param_3 < (uintptr_t)param_5);
    }
  }
  *piVar2 = (int)pfVar12;
  *(int *)param_6 = iVar14;
  *param_2 = (int)pfVar9;
  *param_1 = *param_1 + 0x1c;
  return;
}

// 0x641ef0 — observed shape
void FUN_00641ef0(int *param_1, int *param_2, int *param_3, int param_4, uint32_t param_5,
                  uint16_t *param_6, uint32_t param_7)
{
  int *piVar1;
  int *piVar2;
  uint32_t uVar3;
  uint16_t *puVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  int iVar7;
  uint32_t *puVar8;
  uint32_t uVar9;
  int iVar10;
  int iVar11;
  uint32_t *puVar12;
  uint32_t local_18;
  uint32_t local_14;
  int local_10;
  uint32_t local_8;

  piVar2 = param_2;
  if (param_4 == 0) {
    uVar6 = *(uint32_t *)(*param_1 + 4);
    puVar4 = param_6;
  }
  else {
    uVar6 = (uint32_t)*(uint16_t *)(uintptr_t)(param_5 + param_4);
    puVar4 = (uint16_t *)(uintptr_t)(param_5 + param_4);
  }
  if (param_7 == 0xffffffff) {
    param_5 = *(uint32_t *)(*param_1 + 0x10);
    if (param_5 == 0) {
      param_5 = 1;
    }
  }
  else {
    param_5 = param_7;
  }
  if ((int)uVar6 < 0) {
    return;
  }
  if (1 < (int)uVar6) {
    if (uVar6 == 2) {
      piVar1 = (int *)*param_1;
      uVar6 = piVar1[5];
      uVar3 = piVar1[6];
      iVar11 = *piVar1;
      if (iVar11 == 1) {
        iVar11 = *(int *)param_6;
        param_4 = *param_2;
        local_18 = 0;
        iVar10 = *param_3;
        if (param_5 != 0) {
          do {
            if (iVar11 == 0) break;
            param_2 = (int *)0x0;
            if (uVar6 != 0) {
              do {
                if (iVar11 == 0) break;
                uVar9 = 0;
                if (uVar3 != 0) {
                  iVar7 = (int)param_2 << 2;
                  do {
                    *(uint32_t *)(iVar10 + uVar9 * 4) = *(uint32_t *)(iVar7 + *piVar2);
                    uVar9 = uVar9 + 1;
                    iVar7 = iVar7 + 0x10;
                  } while (uVar9 < uVar3);
                }
                iVar10 = iVar10 + 0x10;
                iVar11 = iVar11 + -1;
                param_2 = (int *)((int)param_2 + 1);
              } while ((uintptr_t)param_2 < (uintptr_t)uVar6);
            }
            param_4 = param_4 + 0x40;
            local_18 = local_18 + 1;
          } while (local_18 < param_5);
        }
      }
      else {
        if (iVar11 != 2) {
          if (iVar11 != 3) {
            return;
          }
          iVar11 = *param_3;
          iVar10 = *(int *)param_6;
          param_4 = *param_2;
          local_18 = 0;
          if (param_5 != 0) {
            do {
              if (iVar10 == 0) break;
              local_14 = 0;
              if (uVar6 != 0) {
                do {
                  if (iVar10 == 0) break;
                  uVar9 = 0;
                  if (uVar3 != 0) {
                    do {
                      uVar5 = (uint32_t)ftol();
                      *(uint32_t *)(iVar11 + uVar9 * 4) = uVar5;
                      uVar9 = uVar9 + 1;
                    } while (uVar9 < uVar3);
                  }
                  iVar11 = iVar11 + 0x10;
                  iVar10 = iVar10 + -1;
                  local_14 = local_14 + 1;
                } while (local_14 < uVar6);
              }
              param_4 = param_4 + 0x40;
              local_18 = local_18 + 1;
            } while (local_18 < param_5);
          }
          *param_3 = iVar11;
          *(int *)param_6 = iVar10;
          goto LAB_00642193;
        }
        iVar11 = *(int *)param_6;
        param_4 = *param_2;
        local_18 = 0;
        iVar10 = *param_3;
        if (param_5 != 0) {
          do {
            if (iVar11 == 0) break;
            param_2 = (int *)0x0;
            if (uVar6 != 0) {
              do {
                if (iVar11 == 0) break;
                uVar9 = 0;
                if (uVar3 != 0) {
                  iVar7 = (int)param_2 << 2;
                  do {
                    *(uint32_t *)(iVar10 + uVar9 * 4) = *(uint32_t *)(iVar7 + *piVar2);
                    uVar9 = uVar9 + 1;
                    iVar7 = iVar7 + 0x10;
                  } while (uVar9 < uVar3);
                }
                iVar10 = iVar10 + 0x10;
                iVar11 = iVar11 + -1;
                param_2 = (int *)((int)param_2 + 1);
              } while ((uintptr_t)param_2 < (uintptr_t)uVar6);
            }
            param_4 = param_4 + 0x40;
            local_18 = local_18 + 1;
          } while (local_18 < param_5);
        }
      }
      *param_3 = iVar10;
      *(int *)param_6 = iVar11;
LAB_00642193:
      *piVar2 = param_4;
      *param_1 = *param_1 + 0x1c;
      return;
    }
    if (uVar6 != 3) {
      if (uVar6 != 5) {
        return;
      }
      local_18 = 0;
      local_14 = 0;
      if (param_4 != 0) {
        local_14 = *(int *)(puVar4 + 6) + param_4;
      }
      local_8 = 0;
      uVar6 = *(uint32_t *)(*param_1 + 0x14);
      iVar11 = *param_1 + 0x18;
      *param_1 = iVar11;
      if (param_5 == 0) {
        return;
      }
      do {
        if (*(int *)param_6 == 0) {
          return;
        }
        param_7 = 0;
        *param_1 = iVar11;
        if (uVar6 != 0) {
          puVar8 = (uint32_t *)(local_14 + 4);
          do {
            if (*(int *)param_6 == 0) break;
            if (param_4 != 0) {
              local_18 = *puVar8;
            }
            FUN_00641ef0(param_1, param_2, param_3, param_4, local_18, param_6, 0xffffffff);
            param_7 = param_7 + 1;
            puVar8 = puVar8 + 2;
          } while (param_7 < uVar6);
        }
        local_8 = local_8 + 1;
        if (param_5 <= local_8) {
          return;
        }
      } while (true);
    }
  }
  piVar2 = (int *)*param_1;
  iVar11 = piVar2[5];
  iVar10 = *piVar2;
  uVar3 = piVar2[6];
  param_7 = 0;
  if (uVar6 == 3) {
    param_7 = (4 - uVar3) * 4;
  }
  if (iVar10 == 1) {
    puVar8 = (uint32_t *)*param_3;
    iVar7 = *(int *)param_6;
    local_14 = 0;
    iVar10 = *param_2;
    if (param_5 != 0) {
      do {
        if (iVar7 == 0) break;
        local_18 = 0;
        if (uVar3 != 0) {
          do {
            if (iVar7 == 0) break;
            if (iVar11 != 0) {
              puVar12 = puVar8;
              local_10 = iVar11;
              do {
                *puVar12 = *(uint32_t *)((iVar10 - (int)puVar8) + (int)puVar12);
                puVar12 = puVar12 + 1;
                local_10 = local_10 + -1;
              } while (local_10 != 0);
            }
            puVar8 = puVar8 + 4;
            iVar10 = iVar10 + 0x10;
            iVar7 = iVar7 + -1;
            local_18 = local_18 + 1;
          } while (local_18 < uVar3);
        }
        local_14 = local_14 + 1;
        iVar10 = iVar10 + param_7 * 4;
      } while (local_14 < param_5);
    }
  }
  else {
    if (iVar10 != 2) {
      if (iVar10 != 3) {
        return;
      }
      puVar8 = (uint32_t *)*param_3;
      iVar10 = *(int *)param_6;
      local_14 = 0;
      iVar11 = *param_2;
      if (param_5 != 0) {
        do {
          if (iVar10 == 0) break;
          local_18 = 0;
          if (uVar3 != 0) {
            do {
              if (iVar10 == 0) break;
              uVar5 = (uint32_t)ftol();
              *puVar8 = uVar5;
              uVar5 = (uint32_t)ftol();
              puVar8[1] = uVar5;
              uVar5 = (uint32_t)ftol();
              puVar8[2] = uVar5;
              uVar5 = (uint32_t)ftol();
              puVar8[3] = uVar5;
              puVar8 = puVar8 + 4;
              iVar11 = iVar11 + 0x10;
              iVar10 = iVar10 + -1;
              local_18 = local_18 + 1;
            } while (local_18 < uVar3);
          }
          local_14 = local_14 + 1;
          iVar11 = iVar11 + param_7 * 4;
        } while (local_14 < param_5);
      }
      *param_3 = (int)puVar8;
      *(int *)param_6 = iVar10;
      *param_2 = iVar11;
      goto LAB_00642355;
    }
    puVar8 = (uint32_t *)*param_3;
    iVar7 = *(int *)param_6;
    local_14 = 0;
    iVar10 = *param_2;
    if (param_5 != 0) {
      do {
        if (iVar7 == 0) break;
        local_18 = 0;
        if (uVar3 != 0) {
          do {
            if (iVar7 == 0) break;
            if (iVar11 != 0) {
              puVar12 = puVar8;
              local_10 = iVar11;
              do {
                *puVar12 = *(uint32_t *)((iVar10 - (int)puVar8) + (int)puVar12);
                puVar12 = puVar12 + 1;
                local_10 = local_10 + -1;
              } while (local_10 != 0);
            }
            puVar8 = puVar8 + 4;
            iVar10 = iVar10 + 0x10;
            iVar7 = iVar7 + -1;
            local_18 = local_18 + 1;
          } while (local_18 < uVar3);
        }
        local_14 = local_14 + 1;
        iVar10 = iVar10 + param_7 * 4;
      } while (local_14 < param_5);
    }
  }
  *param_3 = (int)puVar8;
  *(int *)param_6 = iVar7;
  *param_2 = iVar10;
LAB_00642355:
  *param_1 = *param_1 + 0x1c;
  return;
}

// 0x642362 — observed shape
void FUN_00642362(int *param_1, int *param_2, int *param_3, int param_4, uint32_t param_5,
                  uint16_t *param_6, uint32_t param_7)
{
  int *piVar1;
  int *piVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t *puVar5;
  uint16_t *puVar6;
  uint32_t *puVar7;
  int iVar8;
  int iVar9;
  uint32_t uVar10;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;

  piVar2 = param_3;
  piVar1 = param_2;
  if (param_4 == 0) {
    uVar4 = *(uint32_t *)(*param_1 + 4);
    puVar6 = param_6;
  }
  else {
    uVar4 = (uint32_t)*(uint16_t *)(uintptr_t)(param_4 + param_5);
    puVar6 = (uint16_t *)(uintptr_t)(param_4 + param_5);
  }
  if (param_7 == 0xffffffff) {
    param_5 = *(uint32_t *)(*param_1 + 0x10);
    if (param_5 == 0) {
      param_5 = 1;
    }
  }
  else {
    param_5 = param_7;
  }
  if ((int)uVar4 < 0) {
    return;
  }
  if (1 < (int)uVar4) {
    if (uVar4 == 2) {
      uVar4 = ((int *)*param_1)[5];
      iVar9 = *(int *)*param_1;
      if (iVar9 == 1) {
        iVar9 = *(int *)param_6;
        param_2 = (int *)0x0;
        puVar7 = (uint32_t *)*param_3;
        iVar8 = *piVar1;
        if (param_5 != 0) {
          do {
            if (iVar9 == 0) break;
            uVar10 = 0;
            if (uVar4 != 0) {
              do {
                if (iVar9 == 0) break;
                *puVar7 = *(uint32_t *)(*piVar1 + uVar10 * 4);
                puVar7 = puVar7 + 1;
                iVar9 = iVar9 + -1;
                uVar10 = uVar10 + 1;
              } while (uVar10 < uVar4);
            }
            iVar8 = iVar8 + 0x40;
            param_2 = (int *)((int)param_2 + 1);
          } while ((uintptr_t)param_2 < (uintptr_t)param_5);
        }
      }
      else {
        if (iVar9 != 2) {
          if (iVar9 != 3) {
            return;
          }
          puVar7 = (uint32_t *)*param_3;
          iVar9 = *(int *)param_6;
          local_8 = 0;
          iVar8 = *param_2;
          if (param_5 != 0) {
            do {
              if (iVar9 == 0) break;
              param_7 = 0;
              if (uVar4 != 0) {
                do {
                  if (iVar9 == 0) break;
                  uVar3 = (uint32_t)ftol();
                  *puVar7 = uVar3;
                  puVar7 = puVar7 + 1;
                  iVar9 = iVar9 + -1;
                  param_7 = param_7 + 1;
                } while (param_7 < uVar4);
              }
              iVar8 = iVar8 + 0x40;
              local_8 = local_8 + 1;
            } while (local_8 < param_5);
          }
          *param_3 = (int)puVar7;
          *(int *)param_6 = iVar9;
          *param_2 = iVar8;
          goto LAB_00642587;
        }
        iVar9 = *(int *)param_6;
        param_2 = (int *)0x0;
        puVar7 = (uint32_t *)*param_3;
        iVar8 = *piVar1;
        if (param_5 != 0) {
          do {
            if (iVar9 == 0) break;
            uVar10 = 0;
            if (uVar4 != 0) {
              do {
                if (iVar9 == 0) break;
                *puVar7 = *(uint32_t *)(*piVar1 + uVar10 * 4);
                puVar7 = puVar7 + 1;
                iVar9 = iVar9 + -1;
                uVar10 = uVar10 + 1;
              } while (uVar10 < uVar4);
            }
            iVar8 = iVar8 + 0x40;
            param_2 = (int *)((int)param_2 + 1);
          } while ((uintptr_t)param_2 < (uintptr_t)param_5);
        }
      }
      *param_3 = (int)puVar7;
      *(int *)param_6 = iVar9;
      *piVar1 = iVar8;
LAB_00642587:
      *param_1 = *param_1 + 0x1c;
      return;
    }
    if (uVar4 != 3) {
      if (uVar4 != 5) {
        return;
      }
      local_10 = 0;
      local_c = 0;
      if (param_4 != 0) {
        local_c = *(int *)(puVar6 + 6) + param_4;
      }
      local_8 = 0;
      uVar4 = *(uint32_t *)(*param_1 + 0x14);
      iVar9 = *param_1 + 0x18;
      *param_1 = iVar9;
      if (param_5 == 0) {
        return;
      }
      do {
        if (*(int *)param_6 == 0) {
          return;
        }
        param_7 = 0;
        *param_1 = iVar9;
        if (uVar4 != 0) {
          puVar7 = (uint32_t *)(local_c + 4);
          do {
            if (*(int *)param_6 == 0) break;
            if (param_4 != 0) {
              local_10 = *puVar7;
            }
            FUN_00642362(param_1, param_2, param_3, param_4, local_10, param_6, 0xffffffff);
            param_7 = param_7 + 1;
            puVar7 = puVar7 + 2;
          } while (param_7 < uVar4);
        }
        local_8 = local_8 + 1;
        if (param_5 <= local_8) {
          return;
        }
      } while (true);
    }
  }
  uVar10 = ((int *)*param_1)[6];
  iVar9 = *(int *)*param_1;
  local_8 = 0;
  if (uVar4 == 3) {
    local_8 = (4 - uVar10) * 4;
  }
  if (iVar9 == 1) {
    iVar9 = *(int *)param_6;
    puVar5 = (uint32_t *)*param_3;
    puVar7 = (uint32_t *)*param_2;
    param_3 = (int *)0x0;
    if (param_5 != 0) {
      do {
        if (iVar9 == 0) break;
        uVar4 = 0;
        if (uVar10 != 0) {
          do {
            if (iVar9 == 0) break;
            uVar3 = *puVar7;
            puVar7 = puVar7 + 4;
            *puVar5 = uVar3;
            puVar5 = puVar5 + 1;
            iVar9 = iVar9 + -1;
            uVar4 = uVar4 + 1;
          } while (uVar4 < uVar10);
        }
        param_3 = (int *)((int)param_3 + 1);
        puVar7 = puVar7 + local_8;
      } while ((uintptr_t)param_3 < (uintptr_t)param_5);
    }
  }
  else {
    if (iVar9 != 2) {
      if (iVar9 != 3) {
        return;
      }
      puVar7 = (uint32_t *)*param_3;
      param_7 = *(uint32_t *)param_6;
      iVar9 = *param_2;
      local_10 = 0;
      if (param_5 != 0) {
        do {
          if (param_7 == 0) break;
          local_c = 0;
          puVar5 = puVar7;
          if (uVar10 != 0) {
            do {
              puVar7 = puVar5;
              if (param_7 == 0) break;
              uVar3 = (uint32_t)ftol();
              *puVar5 = uVar3;
              puVar7 = puVar5 + 1;
              uVar3 = (uint32_t)ftol();
              *puVar7 = uVar3;
              uVar3 = (uint32_t)ftol();
              puVar5[2] = uVar3;
              uVar3 = (uint32_t)ftol();
              iVar9 = iVar9 + 0x10;
              param_7 = param_7 + -1;
              local_c = local_c + 1;
              puVar5[3] = uVar3;
              puVar5 = puVar7;
            } while (local_c < uVar10);
          }
          local_10 = local_10 + 1;
          iVar9 = iVar9 + local_8 * 4;
        } while (local_10 < param_5);
      }
      *param_3 = (int)puVar7;
      *(uint32_t *)param_6 = param_7;
      *param_2 = iVar9;
      goto LAB_00642704;
    }
    iVar9 = *(int *)param_6;
    puVar5 = (uint32_t *)*param_3;
    puVar7 = (uint32_t *)*param_2;
    param_3 = (int *)0x0;
    if (param_5 != 0) {
      do {
        if (iVar9 == 0) break;
        uVar4 = 0;
        if (uVar10 != 0) {
          do {
            if (iVar9 == 0) break;
            uVar3 = *puVar7;
            puVar7 = puVar7 + 4;
            *puVar5 = uVar3;
            puVar5 = puVar5 + 1;
            iVar9 = iVar9 + -1;
            uVar4 = uVar4 + 1;
          } while (uVar4 < uVar10);
        }
        param_3 = (int *)((int)param_3 + 1);
        puVar7 = puVar7 + local_8;
      } while ((uintptr_t)param_3 < (uintptr_t)param_5);
    }
  }
  *piVar2 = (int)puVar5;
  *(int *)param_6 = iVar9;
  *param_2 = (int)puVar7;
LAB_00642704:
  *param_1 = *param_1 + 0x1c;
  return;
}

// 0x64270e — observed shape
void FUN_0064270e(int *param_1, int *param_2, float *param_3, int param_4, uint32_t param_5,
                  uint16_t *param_6, uint32_t param_7)
{
  int *piVar1;
  float fVar2;
  int *piVar3;
  int *piVar4;
  uint32_t uVar5;
  uint16_t *puVar6;
  float *pfVar7;
  float *pfVar8;
  uint32_t uVar9;
  double *pdVar10;
  double *pdVar11;
  int iVar12;
  uint32_t uVar13;
  int iVar14;
  uint32_t *puVar15;
  uint32_t uVar16;
  int iVar17;
  int local_10;
  uint32_t local_c;
  uint32_t local_8;

  piVar1 = (int *)param_3;
  piVar4 = param_2;
  if (param_4 == 0) {
    uVar9 = *(uint32_t *)(*param_1 + 4);
    puVar6 = param_6;
  }
  else {
    uVar9 = (uint32_t)*(uint16_t *)(uintptr_t)(param_5 + param_4);
    puVar6 = (uint16_t *)(uintptr_t)(param_5 + param_4);
  }
  if (param_7 == 0xffffffff) {
    param_5 = *(uint32_t *)(*param_1 + 0x10);
    if (param_5 == 0) {
      param_5 = 1;
    }
  }
  else {
    param_5 = param_7;
  }
  if ((int)uVar9 < 0) {
    return;
  }
  if (1 < (int)uVar9) {
    if (uVar9 == 2) {
      piVar3 = (int *)*param_1;
      uVar9 = piVar3[5];
      uVar5 = piVar3[6];
      iVar14 = *piVar3;
      if (iVar14 == 1) {
        iVar14 = *(int *)param_6;
        param_2 = (int *)*param_2;
        local_c = 0;
        iVar12 = (int)*param_3;
        if (param_5 != 0) {
          do {
            if (iVar14 == 0) break;
            local_8 = 0;
            if (uVar9 != 0) {
              do {
                uVar13 = 0;
                if (iVar14 == 0) break;
                if (uVar5 != 0) {
                  iVar17 = local_8 << 2;
                  do {
                    piVar1 = (int *)(iVar17 + *piVar4);
                    iVar17 = iVar17 + 0x10;
                    *(double *)(iVar12 + uVar13 * 8) = (double)*piVar1;
                    uVar13 = uVar13 + 1;
                  } while (uVar13 < uVar5);
                }
                iVar12 = iVar12 + 0x20;
                iVar14 = iVar14 + -1;
                local_8 = local_8 + 1;
              } while (local_8 < uVar9);
            }
            param_2 = (int *)((int)param_2 + 0x40);
            local_c = local_c + 1;
          } while (local_c < param_5);
        }
      }
      else {
        if (iVar14 != 2) {
          if (iVar14 != 3) {
            return;
          }
          local_c = 0;
          iVar14 = (int)*param_3;
          iVar12 = *(int *)param_6;
          pfVar8 = (float *)*param_2;
          if (param_5 != 0) {
            do {
              if (iVar12 == 0) break;
              local_8 = 0;
              if (uVar9 != 0) {
                param_3 = pfVar8;
                do {
                  if (iVar12 == 0) break;
                  uVar13 = 0;
                  if (uVar5 != 0) {
                    pfVar7 = param_3;
                    do {
                      fVar2 = *pfVar7;
                      pfVar7 = pfVar7 + 4;
                      *(double *)(iVar14 + uVar13 * 8) = (double)fVar2;
                      uVar13 = uVar13 + 1;
                    } while (uVar13 < uVar5);
                  }
                  param_3 = param_3 + 1;
                  iVar14 = iVar14 + 0x20;
                  iVar12 = iVar12 + -1;
                  local_8 = local_8 + 1;
                } while (local_8 < uVar9);
              }
              pfVar8 = pfVar8 + 0x10;
              local_c = local_c + 1;
            } while (local_c < param_5);
          }
          *piVar1 = iVar14;
          *(int *)param_6 = iVar12;
          *param_2 = (int)pfVar8;
          goto LAB_0064299d;
        }
        iVar14 = *(int *)param_6;
        param_2 = (int *)*param_2;
        local_c = 0;
        iVar12 = (int)*param_3;
        if (param_5 != 0) {
          do {
            if (iVar14 == 0) break;
            local_8 = 0;
            if (uVar9 != 0) {
              do {
                uVar13 = 0;
                if (iVar14 == 0) break;
                if (uVar5 != 0) {
                  iVar17 = local_8 << 2;
                  do {
                    piVar1 = (int *)(iVar17 + *piVar4);
                    iVar17 = iVar17 + 0x10;
                    *(double *)(iVar12 + uVar13 * 8) = (double)*piVar1;
                    uVar13 = uVar13 + 1;
                  } while (uVar13 < uVar5);
                }
                iVar12 = iVar12 + 0x20;
                iVar14 = iVar14 + -1;
                local_8 = local_8 + 1;
              } while (local_8 < uVar9);
            }
            param_2 = (int *)((int)param_2 + 0x40);
            local_c = local_c + 1;
          } while (local_c < param_5);
        }
      }
      *param_3 = (float)iVar12;
      *(int *)param_6 = iVar14;
      *piVar4 = (int)param_2;
LAB_0064299d:
      *param_1 = *param_1 + 0x1c;
      return;
    }
    if (uVar9 != 3) {
      if (uVar9 != 5) {
        return;
      }
      local_c = 0;
      local_10 = 0;
      if (param_4 != 0) {
        local_10 = *(int *)(puVar6 + 6) + param_4;
      }
      local_8 = 0;
      uVar9 = *(uint32_t *)(*param_1 + 0x14);
      iVar14 = *param_1 + 0x18;
      *param_1 = iVar14;
      if (param_5 == 0) {
        return;
      }
      do {
        if (*(int *)param_6 == 0) {
          return;
        }
        param_7 = 0;
        *param_1 = iVar14;
        if (uVar9 != 0) {
          puVar15 = (uint32_t *)(local_10 + 4);
          do {
            if (*(int *)param_6 == 0) break;
            if (param_4 != 0) {
              local_c = *puVar15;
            }
            FUN_0064270e(param_1, param_2, param_3, param_4, local_c, param_6, 0xffffffff);
            param_7 = param_7 + 1;
            puVar15 = puVar15 + 2;
          } while (param_7 < uVar9);
        }
        local_8 = local_8 + 1;
        if (param_5 <= local_8) {
          return;
        }
      } while (true);
    }
  }
  piVar4 = (int *)*param_1;
  uVar5 = piVar4[5];
  iVar14 = *piVar4;
  uVar13 = piVar4[6];
  local_8 = 0;
  if (uVar9 == 3) {
    local_8 = (4 - uVar13) * 4;
  }
  if (iVar14 == 1) {
    iVar14 = *(int *)param_6;
    iVar12 = (int)*param_3;
    pfVar8 = (float *)*param_2;
    local_c = 0;
    if (param_5 != 0) {
      do {
        if (iVar14 == 0) break;
        param_3 = (float *)0x0;
        if (uVar13 != 0) {
          do {
            if (iVar14 == 0) break;
            uVar9 = 0;
            if (uVar5 != 0) {
              do {
                *(double *)(iVar12 + uVar9 * 8) = (double)(int)pfVar8[uVar9];
                uVar9 = uVar9 + 1;
              } while (uVar9 < uVar5);
            }
            iVar12 = iVar12 + 0x20;
            pfVar8 = pfVar8 + 4;
            iVar14 = iVar14 + -1;
            param_3 = (float *)((int)param_3 + 1);
          } while ((uintptr_t)param_3 < (uintptr_t)uVar13);
        }
        local_c = local_c + 1;
        pfVar8 = pfVar8 + local_8;
      } while (local_c < param_5);
    }
  }
  else {
    if (iVar14 != 2) {
      if (iVar14 != 3) {
        return;
      }
      iVar14 = *(int *)param_6;
      pdVar11 = (double *)*param_3;
      pfVar8 = (float *)*param_2;
      param_3 = (float *)0x0;
      if (param_5 != 0) {
        do {
          if (iVar14 == 0) break;
          uVar9 = 0;
          pfVar7 = pfVar8;
          pdVar10 = pdVar11;
          if (uVar13 != 0) {
            do {
              pfVar7 = pfVar8;
              pdVar11 = pdVar10;
              if (iVar14 == 0) break;
              pfVar7 = pfVar8 + 4;
              *pdVar10 = (double)*pfVar8;
              pdVar11 = pdVar10 + 4;
              iVar14 = iVar14 + -1;
              pdVar10[1] = (double)pfVar8[1];
              uVar9 = uVar9 + 1;
              pdVar10[2] = (double)pfVar8[2];
              pdVar10[3] = (double)pfVar8[3];
              pfVar8 = pfVar7;
              pdVar10 = pdVar11;
            } while (uVar9 < uVar13);
          }
          param_3 = (float *)((int)param_3 + 1);
          pfVar8 = pfVar7 + local_8;
        } while ((uintptr_t)param_3 < (uintptr_t)param_5);
      }
      *piVar1 = (int)pdVar11;
      goto LAB_00642b01;
    }
    iVar14 = *(int *)param_6;
    iVar12 = (int)*param_3;
    pfVar8 = (float *)*param_2;
    param_3 = (float *)0x0;
    if (param_5 != 0) {
      do {
        if (iVar14 == 0) break;
        uVar9 = 0;
        if (uVar13 != 0) {
          do {
            if (iVar14 == 0) break;
            uVar16 = 0;
            if (uVar5 != 0) {
              do {
                *(double *)(iVar12 + uVar16 * 8) = (double)(int)pfVar8[uVar16];
                uVar16 = uVar16 + 1;
              } while (uVar16 < uVar5);
            }
            iVar12 = iVar12 + 0x20;
            pfVar8 = pfVar8 + 4;
            iVar14 = iVar14 + -1;
            uVar9 = uVar9 + 1;
          } while (uVar9 < uVar13);
        }
        param_3 = (float *)((int)param_3 + 1);
        pfVar8 = pfVar8 + local_8;
      } while ((uintptr_t)param_3 < (uintptr_t)param_5);
    }
  }
  *piVar1 = iVar12;
LAB_00642b01:
  *(int *)param_6 = iVar14;
  *param_2 = (int)pfVar8;
  *param_1 = *param_1 + 0x1c;
  return;
}

// 0x642b18 — observed shape
void FUN_00642b18(int *param_1, int *param_2, int *param_3, int param_4, uint32_t param_5,
                  uint16_t *param_6, uint32_t *param_7)
{
  float fVar1;
  int *piVar2;
  int *piVar3;
  double *pdVar4;
  float *pfVar5;
  float *pfVar6;
  uint32_t uVar7;
  double *pdVar8;
  uint16_t *puVar9;
  uint32_t uVar10;
  uint32_t uVar11;
  int iVar12;
  int iVar13;
  int local_10;
  uint32_t local_c;
  uint32_t local_8;

  piVar3 = param_3;
  piVar2 = param_2;
  if (param_4 == 0) {
    uVar7 = *(uint32_t *)(*param_1 + 4);
    puVar9 = param_6;
  }
  else {
    uVar7 = (uint32_t)*(uint16_t *)(uintptr_t)(param_4 + param_5);
    puVar9 = (uint16_t *)(uintptr_t)(param_4 + param_5);
  }
  if (param_7 == (uint32_t *)0xffffffff) {
    param_5 = *(uint32_t *)(*param_1 + 0x10);
    if (param_5 == 0) {
      param_5 = 1;
    }
  }
  else {
    param_5 = (uint32_t)param_7;
  }
  if ((int)uVar7 < 0) {
    return;
  }
  if ((int)uVar7 < 2) {
    goto LAB_00642d1c;
  }
  if (uVar7 != 2) {
    if (uVar7 != 3) {
      if (uVar7 != 5) {
        return;
      }
      local_c = 0;
      local_10 = 0;
      if (param_4 != 0) {
        local_10 = *(int *)(puVar9 + 6) + param_4;
      }
      local_8 = 0;
      uVar7 = *(uint32_t *)(*param_1 + 0x14);
      iVar13 = *param_1 + 0x18;
      *param_1 = iVar13;
      if (param_5 == 0) {
        return;
      }
      do {
        uVar10 = 0;
        if (*(int *)param_6 == 0) {
          return;
        }
        *param_1 = iVar13;
        if (uVar7 != 0) {
          param_7 = (uint32_t *)(local_10 + 4);
          do {
            if (*(int *)param_6 == 0) break;
            if (param_4 != 0) {
              local_c = *param_7;
            }
            FUN_00642b18(param_1, param_2, param_3, param_4, local_c, param_6,
                         (uint32_t *)0xffffffff);
            param_7 = param_7 + 2;
            uVar10 = uVar10 + 1;
          } while (uVar10 < uVar7);
        }
        local_8 = local_8 + 1;
        if (param_5 <= local_8) {
          return;
        }
      } while (true);
    }
    goto LAB_00642d1c;
  }
  uVar7 = ((int *)*param_1)[5];
  iVar13 = *(int *)*param_1;
  if (iVar13 == 1) {
    iVar13 = *(int *)param_6;
    param_2 = (int *)0x0;
    pdVar4 = (double *)*param_3;
    iVar12 = *piVar2;
    if (param_5 != 0) {
      do {
        if (iVar13 == 0) break;
        uVar10 = 0;
        if (uVar7 != 0) {
          do {
            if (iVar13 == 0) break;
            *pdVar4 = (double)*(int *)(*piVar2 + uVar10 * 4);
            pdVar4 = pdVar4 + 1;
            iVar13 = iVar13 + -1;
            uVar10 = uVar10 + 1;
          } while (uVar10 < uVar7);
        }
        iVar12 = iVar12 + 0x40;
        param_2 = (int *)((int)param_2 + 1);
      } while ((uintptr_t)param_2 < (uintptr_t)param_5);
    }
LAB_00642d0b:
    *param_3 = (int)pdVar4;
    *(int *)param_6 = iVar13;
    *piVar2 = iVar12;
    goto LAB_00642e51;
  }
  if (iVar13 == 2) {
    iVar13 = *(int *)param_6;
    param_2 = (int *)0x0;
    pdVar4 = (double *)*param_3;
    iVar12 = *piVar2;
    if (param_5 != 0) {
      do {
        if (iVar13 == 0) break;
        uVar10 = 0;
        if (uVar7 != 0) {
          do {
            if (iVar13 == 0) break;
            *pdVar4 = (double)*(int *)(*piVar2 + uVar10 * 4);
            pdVar4 = pdVar4 + 1;
            iVar13 = iVar13 + -1;
            uVar10 = uVar10 + 1;
          } while (uVar10 < uVar7);
        }
        iVar12 = iVar12 + 0x40;
        param_2 = (int *)((int)param_2 + 1);
      } while ((uintptr_t)param_2 < (uintptr_t)param_5);
    }
    goto LAB_00642d0b;
  }
  if (iVar13 != 3) {
    return;
  }
  iVar13 = *(int *)param_6;
  pdVar4 = (double *)*param_3;
  pfVar5 = (float *)*param_2;
  uVar10 = 0;
  if (param_5 != 0) {
    do {
      if (iVar13 == 0) break;
      uVar11 = 0;
      if (uVar7 != 0) {
        do {
          if (iVar13 == 0) break;
          *pdVar4 = (double)pfVar5[uVar11];
          pdVar4 = pdVar4 + 1;
          iVar13 = iVar13 + -1;
          uVar11 = uVar11 + 1;
        } while (uVar11 < uVar7);
      }
      pfVar5 = pfVar5 + 0x10;
      uVar10 = uVar10 + 1;
    } while (uVar10 < param_5);
  }
  *param_3 = (int)pdVar4;
LAB_00642e47:
  *(int *)param_6 = iVar13;
LAB_00642e51:
  *param_2 = (int)pfVar5;
  *param_1 = *param_1 + 0x1c;
  return;

LAB_00642d1c:
  uVar10 = ((int *)*param_1)[6];
  iVar13 = *(int *)*param_1;
  param_7 = (uint32_t *)0x0;
  if (uVar7 == 3) {
    param_7 = (uint32_t *)((4 - uVar10) * 4);
  }
  if (iVar13 == 1) {
    iVar13 = *(int *)param_6;
    pdVar4 = (double *)*param_3;
    pfVar5 = (float *)*param_2;
    param_3 = (int *)0x0;
    if (param_5 != 0) {
      do {
        if (iVar13 == 0) break;
        uVar7 = 0;
        if (uVar10 != 0) {
          do {
            if (iVar13 == 0) break;
            fVar1 = *pfVar5;
            pfVar5 = pfVar5 + 4;
            *pdVar4 = (double)(int)fVar1;
            pdVar4 = pdVar4 + 1;
            iVar13 = iVar13 + -1;
            uVar7 = uVar7 + 1;
          } while (uVar7 < uVar10);
        }
        param_3 = (int *)((int)param_3 + 1);
        pfVar5 = pfVar5 + (int)param_7;
      } while ((uintptr_t)param_3 < (uintptr_t)param_5);
    }
LAB_00642e45:
    *piVar3 = (int)pdVar4;
    goto LAB_00642e47;
  }
  if (iVar13 == 2) {
    iVar13 = *(int *)param_6;
    pdVar4 = (double *)*param_3;
    pfVar5 = (float *)*param_2;
    param_3 = (int *)0x0;
    if (param_5 != 0) {
      do {
        if (iVar13 == 0) break;
        uVar7 = 0;
        if (uVar10 != 0) {
          do {
            if (iVar13 == 0) break;
            fVar1 = *pfVar5;
            pfVar5 = pfVar5 + 4;
            *pdVar4 = (double)(int)fVar1;
            pdVar4 = pdVar4 + 1;
            iVar13 = iVar13 + -1;
            uVar7 = uVar7 + 1;
          } while (uVar7 < uVar10);
        }
        param_3 = (int *)((int)param_3 + 1);
        pfVar5 = pfVar5 + (int)param_7;
      } while ((uintptr_t)param_3 < (uintptr_t)param_5);
    }
    goto LAB_00642e45;
  }
  if (iVar13 != 3) {
    return;
  }
  iVar13 = *(int *)param_6;
  pdVar4 = (double *)*param_3;
  pfVar5 = (float *)*param_2;
  param_3 = (int *)0x0;
  if (param_5 != 0) {
    do {
      if (iVar13 == 0) break;
      uVar7 = 0;
      pfVar6 = pfVar5;
      pdVar8 = pdVar4;
      if (uVar10 != 0) {
        do {
          pfVar6 = pfVar5;
          pdVar4 = pdVar8;
          if (iVar13 == 0) break;
          pdVar4 = pdVar8 + 1;
          *pdVar8 = (double)*pfVar5;
          pfVar6 = pfVar5 + 4;
          iVar13 = iVar13 + -1;
          *pdVar4 = (double)pfVar5[1];
          uVar7 = uVar7 + 1;
          pdVar8[2] = (double)pfVar5[2];
          pdVar8[3] = (double)pfVar5[3];
          pfVar5 = pfVar6;
          pdVar8 = pdVar4;
        } while (uVar7 < uVar10);
      }
      param_3 = (int *)((int)param_3 + 1);
      pfVar5 = pfVar6 + (int)param_7;
    } while ((uintptr_t)param_3 < (uintptr_t)param_5);
  }
  *piVar3 = (int)pdVar4;
  *(int *)param_6 = iVar13;
  *param_2 = (int)pfVar5;
  *param_1 = *param_1 + 0x1c;
  return;
}

// 0x642e5e — observed shape
int FUN_00642e5e(void *self_, int param_1, uint16_t *param_2)
{
  uint8_t *b = (uint8_t *)self_;
  uint32_t *puVar1;
  uint32_t uVar2;
  int iVar3;
  uint32_t uVar4;
  uint32_t *puVar5;
  int local_8;
  int *iface;

  local_8 = 0;
  uVar4 = (uint32_t)*param_2 * 0x10;
  if ((uint32_t)*param_2 * 0x10 <= (uint32_t)param_2[1] * 4) {
    uVar4 = (uint32_t)param_2[1] * 4;
  }
  if (uVar4 <= (uint32_t)param_2[2] * 0x10) {
    uVar4 = (uint32_t)param_2[2] * 0x10;
  }
  if (*(uint32_t *)(b + 200) < uVar4) {
    puVar1 = (uint32_t *)FUN_00533c78(uVar4);
    if (puVar1 == (uint32_t *)0x0) {
      return -0x7ff8fff2;
    }
    puVar5 = puVar1;
    for (uVar2 = uVar4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(uint8_t *)puVar5 = 0;
      puVar5 = (uint32_t *)((int)puVar5 + 1);
    }
    puVar5 = (uint32_t *)(b + 0xcc);
    if ((void *)*puVar5 != (void *)0x0) {
      operator_delete((void *)*puVar5);
      *puVar5 = 0;
    }
    *puVar5 = (uint32_t)puVar1;
    *(uint32_t *)(b + 200) = uVar4;
  }
  iface = *(int **)(b + 0xc);
  if ((param_1 != 0) &&
     (local_8 = (*(int (**)(void *, int))(*(uintptr_t *)iface + 0x170))((void *)iface, 0),
     local_8 < 0)) {
    return local_8;
  }
  if ((*param_2 != 0) &&
     (local_8 = (*(int (**)(void *, int, uint32_t, uint16_t))(*(uintptr_t *)iface + 0x178))
                          ((void *)iface, 0, *(uint32_t *)(b + 0xcc), *param_2),
     local_8 < 0)) {
    return local_8;
  }
  if ((param_2[1] != 0) &&
     (local_8 = FUN_0063d6bb(*(uint32_t *)(b + 0xc), 0, *(uint32_t *)(b + 0xcc), param_2[1]),
     local_8 < 0)) {
    return local_8;
  }
  if (param_2[2] != 0) {
    local_8 = (*(int (**)(void *, int, uint32_t, uint16_t))(*(uintptr_t *)iface + 0x180))
                        ((void *)iface, 0, *(uint32_t *)(b + 0xcc), param_2[2]);
  }
  return local_8;
}

// 0x642f7f — observed shape
void FUN_00642f7f(void *self_, uint32_t param_1, int param_2)
{
  uint8_t *b = (uint8_t *)self_;
  int iVar1;
  int iVar2;
  uint32_t uVar3;
  uint32_t local_c;
  uint32_t local_8;
  int *iface;

  local_8 = 0;
  iface = *(int **)(b + 0xc);
  if (*(int16_t *)(param_2 + 6) != 0) {
    iVar2 = 0x101;
    for (;;) {
      iVar1 = (*(int (**)(void *, int, int))(*(uintptr_t *)iface + 0x104))((void *)iface, iVar2, 0);
      if (!(-1 < iVar1)) break;
      uVar3 = 0x1c;
      do {
        if (*(int *)(&UNK_006ec0c8 + uVar3) == 0) {
          local_c = 0;
        }
        else {
          local_c = *(uint32_t *)(*(int *)(&UNK_006ec0c8 + uVar3) + 4);
        }
        iVar1 = (*(int (**)(void *, int, uint32_t, uint32_t))(*(uintptr_t *)iface + 0x114))
                          ((void *)iface, iVar2, *(uint32_t *)(&UNK_006ec0c4 + uVar3) & 0xffffff,
                           local_c);
        if (iVar1 < 0) {
          return;
        }
        uVar3 = uVar3 + 0x1c;
      } while (uVar3 < 0x188);
      local_8 = local_8 + 1;
      iVar2 = iVar2 + 1;
      if (*(uint16_t *)(param_2 + 6) <= local_8) {
        return;
      }
    }
  }
  return;
}

// 0x64300d — observed shape
int FUN_0064300d(void *self_, int param_1, uint16_t *param_2)
{
  uint8_t *b = (uint8_t *)self_;
  uint32_t *puVar1;
  uint32_t uVar2;
  int iVar3;
  uint32_t uVar4;
  uint32_t *puVar5;
  int local_8;
  int *iface;

  local_8 = 0;
  uVar4 = (uint32_t)*param_2 * 0x10;
  if ((uint32_t)*param_2 * 0x10 <= (uint32_t)param_2[1] * 4) {
    uVar4 = (uint32_t)param_2[1] * 4;
  }
  if (uVar4 <= (uint32_t)param_2[2] * 0x10) {
    uVar4 = (uint32_t)param_2[2] * 0x10;
  }
  if (*(uint32_t *)(b + 200) < uVar4) {
    puVar1 = (uint32_t *)FUN_00533c78(uVar4);
    if (puVar1 == (uint32_t *)0x0) {
      return -0x7ff8fff2;
    }
    puVar5 = puVar1;
    for (uVar2 = uVar4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(uint8_t *)puVar5 = 0;
      puVar5 = (uint32_t *)((int)puVar5 + 1);
    }
    puVar5 = (uint32_t *)(b + 0xcc);
    if ((void *)*puVar5 != (void *)0x0) {
      operator_delete((void *)*puVar5);
      *puVar5 = 0;
    }
    *puVar5 = (uint32_t)puVar1;
    *(uint32_t *)(b + 200) = uVar4;
  }
  iface = *(int **)(b + 0xc);
  if ((param_1 != 0) &&
     (local_8 = (*(int (**)(void *, int))(*(uintptr_t *)iface + 0x1ac))((void *)iface, 0),
     local_8 < 0)) {
    return local_8;
  }
  if ((*param_2 != 0) &&
     (local_8 = (*(int (**)(void *, int, uint32_t, uint16_t))(*(uintptr_t *)iface + 0x1b4))
                          ((void *)iface, 0, *(uint32_t *)(b + 0xcc), *param_2),
     local_8 < 0)) {
    return local_8;
  }
  if ((param_2[1] != 0) &&
     (local_8 = (*(int (**)(void *, int, uint32_t, uint16_t))(*(uintptr_t *)iface + 0x1c4))
                          ((void *)iface, 0, *(uint32_t *)(b + 0xcc), param_2[1]),
     local_8 < 0)) {
    return local_8;
  }
  if (param_2[2] != 0) {
    local_8 = (*(int (**)(void *, int, uint32_t, uint16_t))(*(uintptr_t *)iface + 0x1bc))
                        ((void *)iface, 0, *(uint32_t *)(b + 0xcc), param_2[2]);
  }
  return local_8;
}

// 0x643132 — observed shape
int FUN_00643132(void *self_, uint32_t param_1, int param_2)
{
  uint8_t *b = (uint8_t *)self_;
  int iVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t local_8;
  int *iface;

  uVar2 = 0;
  iVar1 = 0;
  iface = *(int **)(b + 0xc);
  if (*(int16_t *)(param_2 + 6) != 0) {
    for (;;) {
      iVar1 = (*(int (**)(void *, uint32_t, int))(*(uintptr_t *)iface + 0x104))
                        ((void *)iface, uVar2, 0);
      if (!(-1 < iVar1)) break;
      uVar3 = 0x1c;
      do {
        if (*(int *)(&UNK_006ec0c8 + uVar3) == 0) {
          local_8 = 0;
        }
        else {
          local_8 = *(uint32_t *)(*(int *)(&UNK_006ec0c8 + uVar3) + 4);
        }
        iVar1 = (*(int (**)(void *, uint32_t, uint32_t, uint32_t))(*(uintptr_t *)iface + 0x114))
                          ((void *)iface, uVar2, *(uint32_t *)(&UNK_006ec0c4 + uVar3) & 0xffffff,
                           local_8);
        if (iVar1 < 0) {
          return iVar1;
        }
        uVar3 = uVar3 + 0x1c;
      } while (uVar3 < 0x16c);
      uVar2 = uVar2 + 1;
      if (*(uint16_t *)(param_2 + 6) <= uVar2) {
        return iVar1;
      }
    }
  }
  return iVar1;
}

// 0x6431b5 — observed shape
int FUN_006431b5(void *self_, int param_1)
{
  uint8_t *b = (uint8_t *)self_;
  int *piVar1;
  uint32_t uVar2;
  int iVar3;
  int *piVar4;

  piVar1 = *(int **)(*(int *)(*(int *)(b + 0xb0) + *(int *)(param_1 + 0x14) * 4) + 0x40);
  if (piVar1 == (int *)0x0) {
LAB_00643242:
    iVar3 = FUN_0063d772(param_1);
  }
  else {
    uVar2 = *(uint32_t *)(*(int *)(b + 0x38) + 8);
    if (uVar2 < 2) {
      if (uVar2 != 0) {
        iVar3 = *(int *)(*(int *)(b + 0x38) + 0xc);
        if (iVar3 == (int)(uintptr_t)self_) goto LAB_00643242;
        if (iVar3 != 0) {
          for (piVar4 = (int *)piVar1[4]; piVar4 != piVar1; piVar4 = (int *)piVar4[4]) {
            if (iVar3 == *piVar4) {
              param_1 = piVar4[1];
              goto LAB_00643242;
            }
          }
        }
        goto LAB_00643203;
      }
    }
    else {
LAB_00643203:
      for (piVar4 = (int *)piVar1[4]; piVar4 != piVar1; piVar4 = (int *)piVar4[4]) {
        if (((*piVar4 != 0) && ((*(uint8_t *)(*piVar4 + 0x119) & 1) != 0)) &&
           (iVar3 = FUN_0063d772(piVar4[1]), iVar3 < 0)) {
          return iVar3;
        }
      }
      if ((*(uint8_t *)(b + 0x119) & 1) != 0) goto LAB_00643242;
    }
    iVar3 = 0;
  }
  return iVar3;
}

// 0x64324e — observed shape
int FUN_0064324e(int *param_1, int param_2, uint32_t *param_3)
{
  uint16_t uVar1;
  uint16_t uVar2;
  int iVar3;
  int iVar4;

  uVar1 = *(uint16_t *)((int)param_1 + 0x42);
  iVar4 = 0;
  if ((param_1[0xf] == 0) && (param_3 != (uint32_t *)0x0)) {
    if (*(uint16_t *)(param_1 + 0x11) != 0xffff) {
      iVar4 = FUN_0063da83(*(uint16_t *)
                            (*(int *)((uint32_t)*(uint16_t *)((int)param_1 + 0x42) * 0xb4 + 0x38 +
                                     param_1[0x29]) + 0x34 +
                            (uint32_t)*(uint16_t *)(param_1 + 0x11) * 0x38), 0xffffffff,
                           (*(uint16_t *)(param_1 + 0x10) != *(uint16_t *)((int)param_1 + 0x42)) - 1);
      if (iVar4 < 0) goto LAB_00643355;
    }
    *(uint16_t *)(param_1 + 0x11) = 0xffff;
    if (param_2 == 0) {
      iVar3 = param_1[0x2d];
      *(uint16_t *)((int)param_1 + 0x42) = 0;
    }
    else {
      iVar3 = FUN_0063f27d(param_2, 1);
      if (iVar3 == 0) goto LAB_0064326a;
      uVar2 = (uint16_t)(*(int16_t *)(iVar3 + 0x14) + 1);
      *(uint16_t *)((int)param_1 + 0x42) = uVar2;
      iVar3 = param_1[0x2d] + (uint32_t)uVar2 * param_1[0x2b] * 4;
    }
    param_1[0x2e] = iVar3;
    while ((uint32_t)*(uint16_t *)((int)param_1 + 0x42) < (uint32_t)param_1[0x28]) {
      param_1[0x2e] = param_1[0x2d] + (uint32_t)*(uint16_t *)((int)param_1 + 0x42) * param_1[0x2b] * 4;
      iVar3 = (*(int (**)(void *, int))(*(uintptr_t *)param_1 + 0xf8))((void *)param_1, 0);
      if (-1 < iVar3) {
        *param_3 = ~((uint32_t)*(uint16_t *)((int)param_1 + 0x42) * 0xb4 + param_1[0x29]);
        goto LAB_00643355;
      }
      *(int16_t *)((int)param_1 + 0x42) = *(int16_t *)((int)param_1 + 0x42) + 1;
    }
    *param_3 = 0;
    iVar4 = 1;
  }
  else {
LAB_0064326a:
    iVar4 = -0x7789f794;
  }
LAB_00643355:
  *(uint16_t *)((int)param_1 + 0x42) = uVar1;
  param_1[0x2e] = param_1[0x2d] + (uint32_t)uVar1 * param_1[0x2b] * 4;
  return iVar4;
}

// 0x643397 — observed shape
int FUN_00643397(int *param_1, int param_2)
{
  uint16_t uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint32_t uVar5;
  int iVar6;
  uint8_t local_10[4];
  int local_c;
  uint32_t local_8;
  int *o3;

  uVar1 = *(uint16_t *)((int)param_1 + 0x42);
  piVar2 = (int *)param_1[3];
  local_8 = (uint32_t)(uint16_t)param_1[0x11];
  local_c = param_1[2];
  param_1[2] = (int)piVar2;
  if (param_1[0xf] != 0) {
LAB_006433c6:
    iVar6 = -0x7789f794;
    goto LAB_00643618;
  }
  if (param_2 != 0) {
    iVar6 = FUN_0063f27d(param_2, 1);
    if (iVar6 == 0) goto LAB_006433c6;
    if (*(int16_t *)((int)param_1 + 0x42) != *(int16_t *)(iVar6 + 0x14)) {
      *(uint16_t *)(param_1 + 0x11) = 0xffff;
      *(uint16_t *)((int)param_1 + 0x42) = *(uint16_t *)(iVar6 + 0x14);
    }
    param_1[0x2e] = param_1[0x2d] +
                    (uint32_t)*(uint16_t *)((int)param_1 + 0x42) * param_1[0x2b] * 4;
  }
  piVar3 = param_1 + 0x40;
  if ((*piVar3 == 0) &&
     (iVar6 = (*(int (**)(void *, uint8_t *, int *))(*(uintptr_t *)piVar2 + 0x158))
                        ((void *)piVar2, DAT_006ea468, piVar3), iVar6 < 0))
  goto LAB_00643618;
  if ((param_1[0x41] == 0) && ((*(uint8_t *)((int)param_1 + 0x119) & 2) == 0)) {
    o3 = (int *)param_1[3];
    iVar6 = (*(int (**)(void *))(*(uintptr_t *)o3 + 0xf0))((void *)o3);
    if (iVar6 < 0) goto LAB_00643618;
    iVar6 = (*(int (**)(void *, int *))(*(uintptr_t *)o3 + 0x15c))((void *)o3, (int *)*piVar3);
    if (((iVar6 < 0) ||
        (iVar6 = (*(int (**)(void *, int))(*(uintptr_t *)o3 + 0x170))((void *)o3, 0), iVar6 < 0)) ||
       (iVar6 = (*(int (**)(void *, int))(*(uintptr_t *)o3 + 0x1ac))((void *)o3, 0), iVar6 < 0)) {
      piVar2 = param_1 + 0x41;
      (*(int (**)(void *, int *))(*(uintptr_t *)o3 + 0xf4))((void *)o3, piVar2);
      piVar3 = (int *)*piVar2;
      if (piVar3 != (int *)0x0) {
        (*(void (**)(void *))(*(uintptr_t *)piVar3 + 8))((void *)piVar3);
        *piVar2 = 0;
      }
      goto LAB_00643618;
    }
    iVar6 = (*(int (**)(void *, int *))(*(uintptr_t *)o3 + 0xf4))((void *)o3, param_1 + 0x41);
    if (iVar6 < 0) goto LAB_00643618;
  }
  iVar6 = (*(int (**)(void *))(*(uintptr_t *)param_1[0x41] + 0x10))((void *)param_1[0x41]);
  if (iVar6 < 0) goto LAB_00643618;
  param_2 = 0;
  o3 = (int *)param_1[3];
  iVar6 = (*(int (**)(void *, int *))(*(uintptr_t *)o3 + 0x15c))((void *)o3, (int *)*piVar3);
  if (((iVar6 < 0) ||
      (iVar6 = (*(int (**)(void *, int))(*(uintptr_t *)o3 + 0x170))((void *)o3, 0), iVar6 < 0)) ||
     ((iVar6 = (*(int (**)(void *, int))(*(uintptr_t *)o3 + 0x1ac))((void *)o3, 0), iVar6 < 0 ||
      (iVar6 = (*(int (**)(void *, int, int))(*(uintptr_t *)param_1 + 0x104))
                        ((void *)param_1, 0, 0), iVar6 < 0)))) {
LAB_006435f0:
    param_2 = iVar6;
  }
  else {
    param_1[0xf] = 2;
    FUN_005f8ea2(1);
    uVar5 = 0;
    if (*(int *)((uint32_t)*(uint16_t *)((int)param_1 + 0x42) * 0xb4 + 0x34 + param_1[0x29]) != 0) {
      do {
        iVar6 = (*(int (**)(void *, uint32_t))(*(uintptr_t *)param_1 + 0x108))
                          ((void *)param_1, uVar5);
        if (((iVar6 < 0) ||
            (iVar6 = (*(int (**)(void *, uint8_t *))(*(uintptr_t *)o3 + 0x118))
                              ((void *)o3, local_10), iVar6 < 0)) ||
           (iVar6 = (*(int (**)(void *))(*(uintptr_t *)param_1 + 0x110))((void *)param_1),
            iVar6 < 0)) {
          param_2 = iVar6;
          break;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint32_t *)((uint32_t)*(uint16_t *)((int)param_1 + 0x42) * 0xb4 + 0x34 +
                                     param_1[0x29]));
    }
    FUN_005f8ea2(0);
    param_1[0xf] = 4;
    iVar6 = (*(int (**)(void *))(*(uintptr_t *)param_1 + 0x114))((void *)param_1);
    if ((iVar6 < 0) && (-1 < param_2)) goto LAB_006435f0;
  }
  iVar6 = (*(int (**)(void *))(*(uintptr_t *)param_1[0x41] + 0x14))((void *)param_1[0x41]);
  if (iVar6 < 0) {
    if (-1 < param_2) {
      param_2 = iVar6;
      goto LAB_0064360e;
    }
  }
  else {
LAB_0064360e:
    if (-1 < param_2) goto LAB_00643618;
  }
  iVar6 = param_2;
LAB_00643618:
  *(uint16_t *)((int)param_1 + 0x42) = uVar1;
  *(int16_t *)(param_1 + 0x11) = (int16_t)local_8;
  if ((int16_t)local_8 != -1) {
    iVar4 = FUN_0063da83(*(uint16_t *)
                          (*(int *)((uint32_t)uVar1 * 0xb4 + 0x38 + param_1[0x29]) + 0x34 +
                          (local_8 & 0xffff) * 0x38), 0xffffffff,
                         (*(uint16_t *)(param_1 + 0x10) != uVar1) - 1);
    if ((iVar4 < 0) && (-1 < iVar6)) {
      iVar6 = -0x7fffbffb;
    }
    *(uint16_t *)(param_1 + 0x10) = 0xffff;
  }
  param_1[2] = local_c;
  param_1[0x2e] = param_1[0x2d] +
                  (uint32_t)*(uint16_t *)((int)param_1 + 0x42) * param_1[0x2b] * 4;
  return iVar6;
}

// 0x64369b — observed shape
int FUN_0064369b(void *self_, int param_1, int param_2)
{
  uint8_t *b = (uint8_t *)self_;
  uint32_t uVar1;
  uint32_t *puVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  uint32_t local_30;
  int *local_2c;
  uint32_t local_28;
  uint32_t local_24;
  uint32_t local_20;
  int local_1c;
  uint32_t local_18;
  uint32_t local_14;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;
  int *iface;

  piVar7 = (int *)(param_1 * 100 + *(int *)(b + 0x2c));
  iVar6 = param_2 * 100 + piVar7[1];
  iface = *(int **)(iVar6 + 0x38);
  puVar2 = (*(uint32_t *(**)(void *))(*(uintptr_t *)iface + 0xc))((void *)iface);
  param_1 = puVar2[3] + *piVar7;
  local_1c = 0;
  uVar5 = *puVar2;
  local_2c = *(int **)(iVar6 + 0xc);
  param_2 = *(int *)(iVar6 + 8);
  local_10 = local_2c[4];
  iVar6 = local_2c[1];
  if (local_10 == 0) {
    local_10 = 1;
  }
  if (-1 < iVar6) {
    local_8 = uVar5;
    if (iVar6 < 4) {
      local_18 = local_2c[5];
      uVar1 = local_2c[6];
      iVar6 = *local_2c;
      local_28 = (uint32_t)((local_18 & 3) != 0) + (local_18 >> 2);
      local_14 = local_18;
      local_c = local_28;
      if (iVar6 == 1) {
        local_20 = 0;
        if (local_10 == 0) {
          return 0;
        }
        do {
          if (uVar5 == 0) {
            return local_1c;
          }
          uVar3 = 0;
          iVar6 = param_1;
          if (uVar1 != 0) {
            do {
              if (uVar5 == 0) break;
              if (uVar5 < local_28) {
                local_14 = uVar5 << 2;
                local_c = uVar5;
              }
              if (local_14 != 0) {
                local_24 = uVar3 << 2;
                local_30 = local_14;
                do {
                  uVar4 = (uint32_t)ftol();
                  *(uint32_t *)(local_24 + param_2) = uVar4;
                  local_24 = local_24 + uVar1 * 4;
                  local_30 = local_30 - 1;
                } while (local_30 != 0);
                iVar6 = param_1;
                uVar5 = local_8;
              }
              uVar5 = uVar5 - local_c;
              uVar3 = uVar3 + 1;
              local_8 = uVar5;
            } while (uVar3 < uVar1);
          }
          local_20 = local_20 + 1;
          param_2 = param_2 + uVar1 * local_18 * 4;
          param_1 = iVar6 + uVar3 * local_c * 8;
          if (local_10 <= local_20) {
            return local_1c;
          }
        } while (true);
      }
      if (iVar6 == 2) {
        local_24 = 0;
        if (local_10 == 0) {
          return 0;
        }
        do {
          if (uVar5 == 0) {
            return local_1c;
          }
          uVar3 = 0;
          iVar6 = param_1;
          if (uVar1 != 0) {
            do {
              if (uVar5 == 0) break;
              if (uVar5 < local_28) {
                local_14 = uVar5 << 2;
                local_c = uVar5;
              }
              if (local_14 != 0) {
                local_20 = uVar3 << 2;
                local_30 = local_14;
                do {
                  uVar4 = (uint32_t)ftol();
                  *(uint32_t *)(local_20 + param_2) = uVar4;
                  local_20 = local_20 + uVar1 * 4;
                  local_30 = local_30 - 1;
                } while (local_30 != 0);
                iVar6 = param_1;
                uVar5 = local_8;
              }
              uVar5 = uVar5 - local_c;
              uVar3 = uVar3 + 1;
              local_8 = uVar5;
            } while (uVar3 < uVar1);
          }
          local_24 = local_24 + 1;
          param_2 = param_2 + uVar1 * local_18 * 4;
          param_1 = iVar6 + uVar3 * local_c * 8;
          if (local_10 <= local_24) {
            return local_1c;
          }
        } while (true);
      }
      if (iVar6 == 3) {
        local_20 = 0;
        if (local_10 == 0) {
          return 0;
        }
        do {
          if (uVar5 == 0) {
            return 0;
          }
          uVar3 = 0;
          if (uVar1 != 0) {
            do {
              if (uVar5 == 0) break;
              if (uVar5 < local_28) {
                local_14 = uVar5 << 2;
                local_c = uVar5;
              }
              if (local_14 != 0) {
                iVar8 = uVar3 << 2;
                iVar6 = uVar3 << 3;
                uVar5 = local_14;
                do {
                  *(float *)(iVar8 + param_2) = (float)*(double *)(iVar6 + param_1);
                  iVar6 = iVar6 + uVar1 * 8;
                  iVar8 = iVar8 + uVar1 * 4;
                  uVar5 = uVar5 - 1;
                } while (uVar5 != 0);
                uVar5 = local_8;
              }
              uVar5 = uVar5 - local_c;
              uVar3 = uVar3 + 1;
              local_8 = uVar5;
            } while (uVar3 < uVar1);
          }
          param_1 = param_1 + uVar3 * local_c * 8;
          local_20 = local_20 + 1;
          param_2 = param_2 + uVar1 * local_18 * 4;
          if (local_10 <= local_20) {
            return 0;
          }
        } while (true);
      }
    }
    else if (iVar6 == 5) {
      local_14 = 0;
      uVar1 = local_2c[5];
      piVar7 = local_2c + 6;
      if (local_10 == 0) {
        return 0;
      }
      do {
        if (uVar5 == 0) {
          return local_1c;
        }
        local_18 = 0;
        local_2c = piVar7;
        if (uVar1 != 0) {
          do {
            if (uVar5 == 0) break;
            local_1c = FUN_0063dd50(&local_2c, &param_2, &param_1, &local_8);
            if (local_1c < 0) {
              return local_1c;
            }
            local_18 = local_18 + 1;
            uVar5 = local_8;
          } while (local_18 < uVar1);
        }
        local_14 = local_14 + 1;
        if (local_10 <= local_14) {
          return local_1c;
        }
      } while (true);
    }
  }
  return -0x7fffbffb;
}

// 0x6439a7 — observed shape
int FUN_006439a7(void *self_, int param_1, int param_2, int param_3)
{
  uint8_t *b = (uint8_t *)self_;
  int16_t sVar1;
  uint32_t uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  uint32_t *puVar9;
  int iVar10;
  uint16_t local_20;
  uint16_t local_1e;
  uint16_t local_1c;
  uint8_t local_14[4];
  int *local_10;
  uint8_t local_c[4];
  int *local_8;

  iVar3 = param_3;
  iVar10 = param_1 * 100 + *(int *)(b + 0x2c);
  puVar9 = (uint32_t *)(param_2 * 100 + *(int *)(iVar10 + 4));
  if ((*(int16_t *)(puVar9 + 0x14) == 0) && (puVar9[0xd] == 0)) {
    puVar9[0xc] = puVar9[0xc] & 0xfffffffd;
    *(uint16_t *)((int)puVar9 + 0x4e) = 0;
    *(uint16_t *)(puVar9 + 0x14) = 0;
    *puVar9 = 1;
    param_3 = FUN_0063e055((uint32_t)(param_3 + 0x20), puVar9 + 0xf, local_c, local_14, &local_20);
    if ((-1 < param_3) && (puVar9[0xf] != 0)) {
      local_10 = (int *)(uintptr_t)*(int *)(puVar9[0xf] + 0xc);
      piVar5 = (int *)FUN_00533c78((int)(intptr_t)local_10 * 0x20 + 4);
      piVar4 = local_10;
      if (piVar5 == (int *)0x0) {
        local_10 = (int *)0x0;
      }
      else {
        *piVar5 = (int)(intptr_t)local_10;
        local_10 = piVar5 + 1;
        FUN_004127b0(local_10, 0x20, (int)(intptr_t)piVar4, &LAB_0063e2de);
      }
      puVar9[0xd] = (uint32_t)(uintptr_t)local_10;
      if (local_10 == (int *)0x0) {
        param_3 = -0x7ff8fff2;
      }
      else {
        iVar6 = (int)puVar9[0xf];
        local_10 = (int *)0x0;
        *(uint16_t *)(puVar9 + 0x14) = *(uint16_t *)(iVar6 + 0xc);
        local_8 = (int *)(uintptr_t)(*(int *)(iVar6 + 0x10) + iVar6);
        if (*(int *)(iVar6 + 0xc) != 0) {
          do {
            iVar6 = FUN_0063ea6b((int)(*local_8 + (int)puVar9[0xf]), 10);
            if (iVar6 == 0) goto LAB_00643b9d;
            sVar1 = *(int16_t *)((int)puVar9 + 0x4e);
            *(int16_t *)((int)puVar9 + 0x4e) = sVar1 + 1;
            param_3 = FUN_0063e97c(param_1, param_2, sVar1, iVar6, local_8);
            if (param_3 < 0) {
              return param_3;
            }
            local_10 = (int *)((int)local_10 + 1);
            local_8 = local_8 + 5;
          } while (local_10 < (int *)(uintptr_t)*(uint32_t *)(puVar9[0xf] + 0xc));
        }
        iVar6 = (uint32_t)local_1e + ((uint32_t)local_20 + (uint32_t)local_1c) * 4;
        *(int *)(iVar3 + 8) = iVar6;
        if (iVar6 != 0) {
          *(int *)(iVar3 + 8) = iVar6 + -1;
        }
        uVar7 = *(uint32_t *)(iVar3 + 8) >> 1 | *(uint32_t *)(iVar3 + 8);
        uVar7 = uVar7 >> 2 | uVar7;
        uVar7 = uVar7 >> 4 | uVar7;
        uVar7 = uVar7 >> 8 | uVar7;
        uVar7 = uVar7 >> 0x10 | uVar7;
        *(uint32_t *)(iVar3 + 8) = uVar7;
        uVar2 = *(uint32_t *)(iVar10 + 0xc) >> 3;
        uVar8 = *(uint32_t *)(iVar10 + 0xc) & 7;
        uVar7 = uVar8 + 8 + (uVar2 + uVar7) * 8;
        iVar6 = (int)(uVar8 + uVar2 * 8);
        *(int *)(iVar10 + 0xc) = iVar6;
        *(int *)(iVar3 + 0x10) = iVar6;
        uVar8 = *(int *)(iVar10 + 0xc) + (uint32_t)local_20 * 0x20;
        iVar6 = (int)((uVar8 & 7) + (uVar8 & 0xfffffff8));
        *(int *)(iVar10 + 0xc) = iVar6;
        *(int *)(iVar3 + 0x14) = iVar6;
        uVar8 = *(int *)(iVar10 + 0xc) + (uint32_t)local_1e * 8;
        iVar6 = (int)((uVar8 & 7) + (uVar8 & 0xfffffff8));
        *(int *)(iVar10 + 0xc) = iVar6;
        *(int *)(iVar3 + 0x18) = iVar6;
        *(int *)(iVar10 + 0xc) = *(int *)(iVar10 + 0xc) + (uint32_t)local_1c * 0x20;
        uVar8 = *(uint32_t *)(iVar10 + 0xc);
        if (*(uint32_t *)(iVar10 + 0xc) <= uVar7) {
          uVar8 = uVar7;
        }
        *(uint32_t *)(iVar10 + 0xc) = uVar8;
      }
    }
  }
  else {
LAB_00643b9d:
    param_3 = -0x7fffbffb;
  }
  return param_3;
}

// 0x643bae — observed shape
void FUN_00643bae(void *self_, uint8_t param_1)
{
  uint8_t *b = (uint8_t *)self_;

  if ((param_1 & 2) == 0) {
    if ((param_1 & 1) != 0) {
      operator_delete(self_);
    }
  }
  else {
    FUN_00412770(self_, 0x20, *(uint32_t *)(b - 4), FUN_006338c7);
    if ((param_1 & 1) != 0) {
      operator_delete((void *)(b - 4));
    }
  }
  return;
}

// 0x643bf5 — observed shape
int FUN_00643bf5(void *self_, int param_1, int param_2, int *param_3)
{
  uint8_t *b = (uint8_t *)self_;
  int16_t sVar1;
  uint32_t uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  uint32_t *puVar8;
  int iVar9;
  uint16_t local_20;
  uint16_t local_1e;
  uint16_t local_1c;
  uint8_t local_14[4];
  uint32_t local_10;
  uint8_t local_c[4];
  int local_8;

  iVar3 = (int)(intptr_t)param_3;
  iVar9 = param_1 * 100 + *(int *)(b + 0x2c);
  puVar8 = (uint32_t *)(param_2 * 100 + *(int *)(iVar9 + 4));
  if ((*(int16_t *)(puVar8 + 0x14) == 0) && (puVar8[0xd] == 0)) {
    puVar8[0xc] = puVar8[0xc] & 0xfffffffd;
    *(uint16_t *)((int)puVar8 + 0x4e) = 0;
    *(uint16_t *)(puVar8 + 0x14) = 0;
    *puVar8 = 1;
    local_8 = FUN_0063e055((uint32_t)((int)(intptr_t)param_3 + 0x68), puVar8 + 0xf, local_c,
                           local_14, &local_20);
    if ((-1 < local_8) && (puVar8[0xf] != 0)) {
      iVar5 = *(int *)(puVar8[0xf] + 0xc);
      piVar4 = (int *)FUN_00533c78(iVar5 * 0x20 + 4);
      if (piVar4 == (int *)0x0) {
        piVar4 = (int *)0x0;
      }
      else {
        *piVar4 = iVar5;
        piVar4 = piVar4 + 1;
        FUN_004127b0(piVar4, 0x20, iVar5, &LAB_0063e2de);
      }
      puVar8[0xd] = (uint32_t)(uintptr_t)piVar4;
      if (piVar4 == (int *)0x0) {
        local_8 = -0x7ff8fff2;
      }
      else {
        iVar5 = (int)puVar8[0xf];
        local_10 = 0;
        *(int16_t *)(puVar8 + 0x14) = (int16_t)(*(int16_t *)(iVar5 + 0xc) << 1);
        param_3 = (int *)(uintptr_t)(*(int *)(iVar5 + 0x10) + iVar5);
        if (*(int *)(iVar5 + 0xc) != 0) {
          do {
            iVar5 = FUN_0063ea6b((int)(*param_3 + (int)puVar8[0xf]), 10);
            if (iVar5 != 0) {
              sVar1 = *(int16_t *)((int)puVar8 + 0x4e);
              *(int16_t *)((int)puVar8 + 0x4e) = sVar1 + 1;
              local_8 = FUN_0063e97c(param_1, param_2, sVar1, iVar5, param_3);
              if (local_8 < 0) {
                return local_8;
              }
            }
            local_10 = local_10 + 1;
            param_3 = param_3 + 5;
          } while (local_10 < *(uint32_t *)(puVar8[0xf] + 0xc));
        }
        iVar5 = (uint32_t)local_1e + ((uint32_t)local_20 + (uint32_t)local_1c) * 4;
        *(int *)(iVar3 + 0x18) = iVar5;
        if (iVar5 != 0) {
          *(int *)(iVar3 + 0x18) = iVar5 + -1;
        }
        uVar6 = *(uint32_t *)(iVar3 + 0x18) >> 1 | *(uint32_t *)(iVar3 + 0x18);
        uVar6 = uVar6 >> 2 | uVar6;
        uVar6 = uVar6 >> 4 | uVar6;
        uVar6 = uVar6 >> 8 | uVar6;
        uVar6 = uVar6 >> 0x10 | uVar6;
        *(uint32_t *)(iVar3 + 0x18) = uVar6;
        uVar2 = *(uint32_t *)(iVar9 + 0xc) >> 3;
        uVar7 = *(uint32_t *)(iVar9 + 0xc) & 7;
        uVar6 = uVar7 + 8 + (uVar2 + uVar6) * 8;
        iVar5 = (int)(uVar7 + uVar2 * 8);
        *(int *)(iVar9 + 0xc) = iVar5;
        *(int *)(iVar3 + 0x34) = iVar5;
        uVar7 = *(int *)(iVar9 + 0xc) + (uint32_t)local_20 * 0x20;
        iVar5 = (int)((uVar7 & 7) + (uVar7 & 0xfffffff8));
        *(int *)(iVar9 + 0xc) = iVar5;
        *(int *)(iVar3 + 0x38) = iVar5;
        uVar7 = *(int *)(iVar9 + 0xc) + (uint32_t)local_1e * 8;
        iVar5 = (int)((uVar7 & 7) + (uVar7 & 0xfffffff8));
        *(int *)(iVar9 + 0xc) = iVar5;
        *(int *)(iVar3 + 0x3c) = iVar5;
        *(int *)(iVar9 + 0xc) = *(int *)(iVar9 + 0xc) + (uint32_t)local_1c * 0x20;
        uVar7 = *(uint32_t *)(iVar9 + 0xc);
        if (*(uint32_t *)(iVar9 + 0xc) <= uVar6) {
          uVar7 = uVar6;
        }
        *(uint32_t *)(iVar9 + 0xc) = uVar7;
      }
    }
  }
  else {
    local_8 = -0x7fffbffb;
  }
  return local_8;
}

// 0x643dfb — observed shape
uint32_t FUN_00643dfb(void *self_, int param_1, int param_2, int param_3)
{
  uint8_t *b = (uint8_t *)self_;
  int iVar1;
  uint32_t uVar2;

  uVar2 = param_3 * 0x20 +
          *(int *)(*(int *)(param_1 * 100 + 4 + *(int *)(b + 0x2c)) + 0x34 + param_2 * 100);
  *(uint32_t *)(*(int *)(uVar2 + 0x18) + 0x1c) = *(uint32_t *)(uVar2 + 0x1c);
  *(uint32_t *)(*(int *)(uVar2 + 0x1c) + 0x18) = *(uint32_t *)(uVar2 + 0x18);
  iVar1 = *(int *)(*(int *)(b + 0xb0) + *(int *)(*(int *)(uVar2 + 0xc) + 0x14) * 4);
  if (uVar2 == *(uint32_t *)(iVar1 + 0x34)) {
    *(uint32_t *)(iVar1 + 0x34) =
        -(uint32_t)(*(uint32_t *)(uVar2 + 0x1c) != uVar2) & *(uint32_t *)(uVar2 + 0x1c);
  }
  *(uint32_t *)(uVar2 + 0x18) = uVar2;
  *(uint32_t *)(uVar2 + 0x1c) = uVar2;
  if (((*(uint8_t *)(b + 0x119) & 8) == 0) && (*(int *)(b + 0xb4) != 0)) {
    FUN_0063e44e();
  }
  return 0;
}

// 0x643e7a — observed shape
int FUN_00643e7a(void *self_, uint32_t param_1)
{
  uint8_t *b = (uint8_t *)self_;
  int *piVar1;
  uint32_t uVar2;
  int iVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  int *local_c;
  int *local_8;
  void *o4;
  void *o8;

  uVar2 = param_1;
  *(uint32_t *)(param_1 + 0x14) = *(uint32_t *)(param_1 + 0x14) & 0xfffffffe;
  local_8 = (int *)0x0;
  local_c = (int *)0x0;
  o4 = *(void **)(param_1 + 4);
  iVar3 = (*(int (**)(void *, int, uint32_t *))(*(uintptr_t *)o4 + 0x10))(o4, 0, &param_1);
  if (iVar3 < 0) goto LAB_00643f46;
  iVar3 = (*(int (**)(void *, int **))(*(uintptr_t *)o4 + 0xc))(o4, &local_c);
  if (iVar3 < 0) goto LAB_00643f46;
  piVar1 = *(int **)(uVar2 + 8);
  if (piVar1 == (int *)0x0) {
LAB_00643ed8:
    iVar3 = FUN_006294f9(param_1, &local_8);
    if (iVar3 < 0) goto LAB_00643f46;
    piVar1 = *(int **)(uVar2 + 8);
    if (piVar1 != (int *)0x0) {
      (*(void (**)(void *))(*(uintptr_t *)piVar1 + 8))((void *)piVar1);
      *(uint32_t *)(uVar2 + 8) = 0;
    }
    *(int **)(uVar2 + 8) = local_8;
    local_8 = (int *)0x0;
  }
  else {
    uVar4 = (*(uint32_t (**)(void *))(*(uintptr_t *)piVar1 + 0x10))((void *)piVar1);
    if (uVar4 < param_1) goto LAB_00643ed8;
  }
  iVar3 = *(int *)(*(int *)(uVar2 + 4));
  o8 = *(void **)(uVar2 + 8);
  uVar5 = (*(uint32_t (**)(void *, uint32_t *))(*(uintptr_t *)o8 + 0xc))(o8, &param_1);
  iVar3 = (*(int (**)(void *, uint32_t))(iVar3 + 0x10))(*(void **)(uVar2 + 4), uVar5);
  if ((-1 < iVar3) && (local_c != *(int **)(b + 0xc))) {
    piVar1 = *(int **)(uVar2 + 4);
    if (piVar1 != (int *)0x0) {
      (*(void (**)(void *))(*(uintptr_t *)piVar1 + 8))((void *)piVar1);
      *(uint32_t *)(uVar2 + 4) = 0;
    }
    FUN_0063e5ce(uVar2);
  }
LAB_00643f46:
  if (local_8 != (int *)0x0) {
    (*(void (**)(void *))(*(uintptr_t *)local_8 + 8))((void *)local_8);
    local_8 = (int *)0x0;
  }
  if (local_c != (int *)0x0) {
    (*(void (**)(void *))(*(uintptr_t *)local_c + 8))((void *)local_c);
  }
  return iVar3;
}
