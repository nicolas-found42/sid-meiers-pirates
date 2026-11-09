#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cmath>

extern void FUN_006126c7(void);
extern int FUN_0060fcd3(int a, int b, int c, const char *fmt, ...);
extern int FUN_00610ba0(void *p);
extern void FUN_0061273f(void *p, int v, int n);
extern int FUN_0065c485(int a, void *b, int c);
extern int FUN_00610918(void *a, void *b, void *c);
extern int FUN_0060f155(int *p);
extern int FUN_00610d84(int p);
extern int FUN_0061288b(int a, int b, int c, void *d, int e, int *f, int *g, int *h);
extern int FUN_0060d19b(int n);
extern int FUN_0065caaa(int a, int b, int c, int d, void *e);
extern int FUN_0065ac0a(void *a, void *b);
extern void FUN_006118e5(void *p);
extern int FUN_00611665(void *p);
extern int FUN_0061171a(void *p);
extern int FUN_0060d19b_2(int n);
extern int FUN_0065ae50(void *p);
extern void FUN_00610d4a(void *p);
extern int FUN_0065ca23(void *a, int b, int c, int d);
extern int FUN_0065ac49(void *a, int b, const char *s);
extern void FUN_0061285e(void);
extern void operator_delete(void *p);
extern int FUN_006126a6(int a);
extern int FUN_00612bfd(int a);
extern void FUN_00610c1c(void *p, const char *s);
extern int FUN_00612c1e(void);
extern int FUN_0061327c(uint32_t a, uint32_t b);
extern int FUN_00613829(void);
extern int FUN_0060bfba(void *p, int v);
extern int FUN_0060bfe9(void *a, void *b);
extern int FUN_0060bf76(int n);
extern int FUN_005f7fa4(int a, int b, void *c);
extern int FUN_0060fd9a(int a, int b, int c, const char *s);
extern int FUN_00533c78(int n);
extern int FUN_006127cf(int n);
extern int FUN_006118bc(int n);
extern int FUN_006117d6(void *p);
extern int FUN_00612128(void);
extern int FUN_006123c0(void);
extern int FUN_0060f796(void);
extern int FUN_006126e6(void *p);
extern void FUN_0060f49b(void);
extern int FUN_006338c7(void);
extern int FUN_0065d0e1(void *p);
extern int FUN_0065aaac(int n, int align);

// 0x61285e — observed shape: void, calls FUN_006126c7 five times
void FUN_0061285e(void) {
  FUN_006126c7();
  FUN_006126c7();
  FUN_006126c7();
  FUN_006126c7();
  FUN_006126c7();
}

// 0x612896 — observed shape: int, register name validation with error returns -0x7fffbffb
int FUN_00612896(void) {
  char cVar1;
  short sVar2;
  uint32_t *puVar3;
  uint32_t *puVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  char *in_EAX;
  int iVar7;
  int iVar8;
  int in_ECX;
  short *unaff_EBX;
  int unaff_EBP;
  int *piVar9;
  char *pcVar10 = nullptr;
  int arg8 = *(int*)(unaff_EBP + 8);
  int arg10 = *(int*)(unaff_EBP + 0x10);
  int arg18 = *(int*)(unaff_EBP + 0x18);
  int arg20 = *(int*)(unaff_EBP + 0x20);
  int arg1c = *(int*)(unaff_EBP + 0x1c);
  int arg24 = *(int*)(unaff_EBP + 0x24);

  pcVar10 = in_EAX + 1;
  do {
    cVar1 = *in_EAX;
    in_EAX = in_EAX + 1;
  } while (cVar1 != '\0');
  if ((uint32_t)((intptr_t)in_EAX - (intptr_t)pcVar10) < 3) {
    FUN_0060fcd3(arg8, arg10, 0x7d5, "invalid register, input, or constant name '%s'");
    return -0x7fffbffb;
  }
  puVar3 = *(uint32_t**)(unaff_EBP + 0x20);
  puVar4 = *(uint32_t**)(unaff_EBP + 0x1c);
  *puVar4 = 0;
  *puVar3 = 0;
  **(uint32_t**)(unaff_EBP + 0x24) = 0;
  if (*unaff_EBX != 0x5f76) {
    if (*unaff_EBX == 0x5f72) {
      *puVar4 = 0;
      iVar7 = FUN_00610ba0(unaff_EBX);
      if (iVar7 == 0) {
        piVar9 = (int*)(in_ECX + 0xa4);
        **(int**)(unaff_EBP + 0x24) = *piVar9;
        FUN_0061273f(unaff_EBX, *piVar9, 1);
        *piVar9 = *piVar9 + 1;
      } else {
        **(int**)(unaff_EBP + 0x24) = *(int*)(iVar7 + 4);
      }
      if (*(int*)(unaff_EBP + 0x18) == 0) {
        return 0;
      }
      pcVar10 = (char*)"addressing operations not allowed on temporary registers '%s'";
    } else {
      sVar2 = *unaff_EBX;
      if ((((sVar2 == 0x5f63) || (sVar2 == 0x5f62)) || (sVar2 == 0x5f69)) || (sVar2 == 0x5f73)) {
        if (*unaff_EBX == 0x5f62) {
          *puVar4 = 0xe;
          iVar7 = 0;
        } else if (*unaff_EBX == 0x5f69) {
          *puVar4 = 7;
          iVar7 = 1;
        } else if (*unaff_EBX == 0x5f73) {
          *puVar4 = 10;
          iVar7 = 2;
        } else {
          *puVar4 = 2;
          iVar7 = 3;
        }
        iVar8 = FUN_00610ba0(unaff_EBX);
        if (iVar8 == 0) {
          iVar8 = FUN_0065c485(*(int*)(unaff_EBP + 0x10), unaff_EBX, unaff_EBP + 0x20);
          if (iVar8 < 0) {
            return iVar8;
          }
          if (*(int*)(unaff_EBP + 0x20) == 0) {
            FUN_0060fcd3(*(int*)(unaff_EBP + 8), *(int*)(unaff_EBP + 0x10), 0x7d5,
                         "constant register '%s' must be defined as a variable '%s'");
            return -0x7fffbffb;
          }
          uVar5 = *(uint32_t*)(unaff_EBP + 0x20);
          piVar9 = (int*)(in_ECX + 0x8c + iVar7 * 4);
          **(int**)(unaff_EBP + 0x24) = *piVar9;
          FUN_0061273f(unaff_EBX, *piVar9, (int)uVar5);
          *piVar9 = *piVar9 + *(int*)(unaff_EBP + 0x20);
          *(int*)(in_ECX + 0xac) = *(int*)(in_ECX + 0xac) + 1;
          piVar9 = *(int**)(unaff_EBP + 0x24);
        } else {
          piVar9 = *(int**)(unaff_EBP + 0x24);
          *piVar9 = *(int*)(iVar8 + 4);
          *(uint32_t*)(unaff_EBP + 0x20) = *(uint32_t*)(iVar8 + 8);
        }
        if (*(int*)(unaff_EBP + 0x18) == 0) {
          return 0;
        }
        uVar6 = *(uint32_t*)(*(int*)(unaff_EBP + 0x18) + 0x18);
        if (*(uint32_t*)(unaff_EBP + 0x20) < uVar6) {
          FUN_0060fcd3(*(int*)(unaff_EBP + 8), *(int*)(unaff_EBP + 0x10), 0x7d5,
                       "constant register address out of bounds on constant '%s', size %d, offset %d");
          return -0x7fffbffb;
        }
        *piVar9 = *piVar9 + (int)uVar6;
        return 0;
      }
      if ((*(int*)(in_ECX + 0xb0) == 0) || (sVar2 != 0x5f6f)) {
        pcVar10 = (char*)"'%s' is not a valid register name.  Registers must start with v_, r_, c_, b_, or i_ depending on the register type. (o_ for vs_3_0 only)";
      } else {
        *puVar4 = 6;
        iVar7 = FUN_00610ba0(unaff_EBX);
        if (iVar7 == 0) {
          iVar7 = FUN_00610918((char*)unaff_EBX + 1, (void*)(unaff_EBP + 0x1f), (void*)(unaff_EBP + 0x17));
          if (iVar7 < 0) {
            pcVar10 = (char*)"Invalid output register '%s' specified";
            goto LAB_0061291b;
          }
          piVar9 = (int*)(in_ECX + 0xa0);
          **(int**)(unaff_EBP + 0x24) = *piVar9;
          FUN_0061273f(unaff_EBX, *piVar9, 1);
          *piVar9 = *piVar9 + 1;
        } else {
          **(uint32_t**)(unaff_EBP + 0x24) = *(uint32_t*)(iVar7 + 4);
        }
        if (*(int*)(unaff_EBP + 0x18) == 0) {
          return 0;
        }
        pcVar10 = (char*)"addressing operations are not allowed on output registers '%s'";
      }
    }
    goto LAB_0061291b;
  }
  if ((*(int*)(in_ECX + 0xb4) < 10) || (0xc < *(int*)(in_ECX + 0xb4))) {
    *puVar4 = 1;
    iVar7 = FUN_00610ba0(unaff_EBX);
    if (iVar7 == 0) {
      iVar7 = FUN_00610918((char*)unaff_EBX + 1, (void*)(unaff_EBP + 0x1f), (void*)(unaff_EBP + 0x17));
      if (iVar7 < 0) goto LAB_00612915;
      piVar9 = (int*)(in_ECX + 0x9c);
      **(int**)(unaff_EBP + 0x24) = *piVar9;
      FUN_0061273f(unaff_EBX, *piVar9, 1);
      *piVar9 = *piVar9 + 1;
    } else {
      **(uint32_t**)(unaff_EBP + 0x24) = *(uint32_t*)(iVar7 + 4);
    }
    if (*(int*)(unaff_EBP + 0x18) == 0) {
      return 0;
    }
    pcVar10 = (char*)"addressing operations are not allowed on input registers '%s'";
  } else {
    iVar7 = FUN_00610918((char*)unaff_EBX + 1, (void*)(unaff_EBP + 0x1b), (void*)(unaff_EBP + 0x17));
    if (-1 < iVar7) {
      if (*(char*)(unaff_EBP + 0x1b) == '\x05') {
        *puVar4 = 3;
      } else {
        if (*(char*)(unaff_EBP + 0x1b) != '\n') {
          pcVar10 = (char*)"Invalid pixel shader input register '%s' specified";
          goto LAB_0061291b;
        }
        *puVar4 = 1;
      }
      **(uint32_t**)(unaff_EBP + 0x24) = (uint32_t)*(uint8_t*)(unaff_EBP + 0x17);
      return 0;
    }
LAB_00612915:
    pcVar10 = (char*)"Invalid input register '%s' specified";
  }
LAB_0061291b:
  FUN_0060fcd3(*(int*)(unaff_EBP + 8), *(int*)(unaff_EBP + 0x10), 0x7d5, pcVar10);
  return -0x7fffbffb;
}

// 0x612bfd — observed shape: void(byte), destructor calling FUN_0061285e then operator_delete via ECX
void FUN_00612bfd(uint8_t param_1) {
  void *in_ECX;
  FUN_0061285e();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
}

// 0x612c1e — observed shape: int, token dispatcher returning 0x101/0x111/0x112/0x10e/0x10f etc
int FUN_00612c1e(void) {
  int iVar1;
  int in_ECX;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  while (true) {
    iVar1 = FUN_0060f155((int*)(in_ECX + 0x10));
    if (iVar1 < 0) {
      *(uint32_t*)(in_ECX + 0x4c) = 1;
      *(uint32_t*)(in_ECX + 0x50) = 1;
      return -1;
    }
    iVar1 = *(int*)(in_ECX + 0x10);
    if (iVar1 < 10) break;
    if (iVar1 == 10) {
      return 0x110;
    }
    if (iVar1 != 0xc) {
      if (iVar1 == 0xd) {
        return -1;
      }
      return 0x110;
    }
  }
  if (iVar1 != 9) {
    if (iVar1 == 0) {
      return 0x110;
    }
    if (iVar1 == 1) {
      if (*(char*)(in_ECX + 0x19) == '\0') {
        return (int)*(char*)(in_ECX + 0x18);
      }
      return 0x110;
    }
    if (iVar1 < 2) {
      return 0x110;
    }
    if (iVar1 < 5) {
      return 0x10e;
    }
    if (iVar1 < 9) {
      return 0x10f;
    }
    return 0x110;
  }
  pcVar3 = *(char**)(in_ECX + 0x18);
  iVar1 = 0xb;
  bVar5 = true;
  pcVar2 = pcVar3;
  pcVar4 = (char*)"entrypoint";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar5 = *pcVar2 == *pcVar4;
    pcVar2 = pcVar2 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    iVar1 = 0x101;
  } else {
    iVar1 = 5;
    bVar5 = true;
    pcVar2 = pcVar3;
    pcVar4 = (char*)"true";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar5 = *pcVar2 == *pcVar4;
      pcVar2 = pcVar2 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (bVar5) {
      iVar1 = 0x111;
    } else {
      iVar1 = 6;
      bVar5 = true;
      pcVar2 = (char*)"false";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar5 = *pcVar3 == *pcVar2;
        pcVar3 = pcVar3 + 1;
        pcVar2 = pcVar2 + 1;
      } while (bVar5);
      if (bVar5) {
        iVar1 = 0x112;
      } else if (*(int*)(in_ECX + 0x38) == -1) {
        iVar1 = 0x10d;
      } else {
        iVar1 = FUN_00610d84(in_ECX + 0x10);
      }
    }
  }
  return iVar1;
}

// 0x612cfc — observed shape: int(int,int), shader assembly register parser with locals
int FUN_00612cfc(int param_1, int param_2) {
  uint8_t bVar1;
  uint32_t uVar2;
  int iVar3;
  int iVar4;
  uint32_t *in_ECX;
  uint32_t uVar5;
  uint8_t *pbVar6;
  uint8_t *pbVar7;
  uint8_t *pbVar8;
  bool bVar9;
  char *pcVar10;
  uint8_t local_40[16];
  int local_30;
  uint32_t local_2c;
  int local_28;
  int local_24;
  uint8_t *local_20;
  uint8_t *local_1c;
  uint8_t *local_18;
  uint32_t local_14;
  uint32_t *local_10;
  int local_c;
  uint32_t local_8;
  pbVar6 = *(uint8_t**)(param_1 + 8);
  local_c = 0;
  local_8 = 0;
  local_14 = 0;
  local_2c = 0;
  local_30 = 1;
  local_24 = 0;
  local_28 = 0;
  local_1c = pbVar6;
  local_18 = pbVar6;
  local_20 = pbVar6;
  local_10 = in_ECX;
  if (*pbVar6 != 0) {
    do {
      while ((*pbVar6 != 0 && (*pbVar6 != 0x5f))) {
        pbVar6 = pbVar6 + 1;
        local_18 = pbVar6;
      }
      uVar2 = (intptr_t)pbVar6 - (intptr_t)local_20;
      if (0xf < uVar2) {
LAB_006130d2:
        if (in_ECX[0x1e] != 0) {
          iVar4 = FUN_0061288b(*in_ECX, in_ECX[0x1f], param_1, local_1c, param_2, &local_c, (int*)&local_14, (int*)&local_8);
          if (-1 < iVar4) goto LAB_00613101;
          goto LAB_006131f1;
        }
        if (param_2 == 0) {
          pcVar10 = (char*)"invalid register '%s'";
        } else {
          if (*(int*)(param_2 + 0x28) == 0) {
            FUN_0060fcd3(*in_ECX, param_1, 0x7d5, "invalid register '%s[%u]'", local_1c, *(uint32_t*)(param_2 + 0x18));
            goto LAB_006131f1;
          }
          if (*(int*)(*(int*)(param_2 + 0x28) + 0x10) == -1) goto LAB_006131f1;
          pcVar10 = (char*)"invalid register '%s[...]'";
        }
        FUN_0060fcd3(*in_ECX, param_1, 0x7d5, pcVar10, local_1c);
        goto LAB_006131f1;
      }
      pbVar7 = local_20;
      pbVar8 = local_40;
      for (uVar5 = uVar2 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(uint32_t*)pbVar8 = *(uint32_t*)pbVar7;
        pbVar7 = pbVar7 + 4;
        pbVar8 = pbVar8 + 4;
      }
      bVar1 = *pbVar6;
      for (uVar5 = uVar2 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pbVar8 = *pbVar7;
        pbVar7 = pbVar7 + 1;
        pbVar8 = pbVar8 + 1;
      }
      local_40[uVar2] = 0;
      if (bVar1 != 0) {
        pbVar6 = pbVar6 + 1;
        local_18 = pbVar6;
      }
      local_20 = pbVar6;
      if (local_30 != 0) {
        pbVar6 = local_40;
        if (local_40[0] == 0) {
LAB_00612dfc:
          local_8 = 0xffffffff;
        } else {
          do {
            iVar4 = isalpha((int)(char)*pbVar6);
            if (iVar4 == 0) break;
            pbVar6 = pbVar6 + 1;
          } while (*pbVar6 != 0);
          if (*pbVar6 == 0) goto LAB_00612dfc;
          local_8 = atoi((char*)pbVar6);
        }
        if (*pbVar6 != 0) {
          *pbVar6 = 0;
          pbVar6 = pbVar6 + 1;
        }
        bVar1 = *pbVar6;
        if (bVar1 != 0) {
          do {
            iVar4 = isdigit((int)(char)bVar1);
            if (iVar4 == 0) break;
            pbVar6 = pbVar6 + 1;
            bVar1 = *pbVar6;
          } while (bVar1 != 0);
          if (*pbVar6 != 0) goto LAB_006130cf;
        }
        iVar4 = 0;
        uVar2 = 0;
        do {
          pbVar7 = *(uint8_t**)((intptr_t)&DAT_006dfe28_placeholder + uVar2);
          pbVar6 = local_40;
          do {
            bVar1 = *pbVar6;
            bVar9 = bVar1 < *pbVar7;
            if (bVar1 != *pbVar7) {
LAB_00612e5d:
              iVar3 = (1 - (uint32_t)bVar9) - (uint32_t)(bVar9 != 0);
              goto LAB_00612e64;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar6[1];
            bVar9 = bVar1 < pbVar7[1];
            if (bVar1 != pbVar7[1]) goto LAB_00612e5d;
            pbVar6 = pbVar6 + 2;
            pbVar7 = pbVar7 + 2;
          } while (bVar1 != 0);
          iVar3 = 0;
LAB_00612e64:
          if (iVar3 == 0) break;
          uVar2 = uVar2 + 0x48;
          iVar4 = iVar4 + 1;
        } while (uVar2 < 0x5e8);
        in_ECX = local_10;
        if (iVar4 != 0x15) {
          iVar3 = local_10[0xe];
          uVar2 = *(uint32_t*)((intptr_t)&DAT_006dfe30_placeholder + (iVar3 + iVar4 * 0x12) * 4);
          if (uVar2 != 0xffffffff) {
            if ((int)uVar2 < 0) {
              if (local_8 == 0xffffffff) {
                if (param_2 == 0) goto LAB_006130d2;
                local_8 = *(uint32_t*)(param_2 + 0x18);
              } else if (param_2 != 0) {
                local_8 = local_8 + *(int*)(param_2 + 0x18);
              }
              uVar2 = -uVar2;
            } else if (param_2 != 0) goto LAB_006130d2;
            if (local_8 == 0xffffffff) {
              if (uVar2 == 0) {
                local_8 = 0;
                goto LAB_00612ef7;
              }
            } else if (((param_2 != 0) && (*(int*)(param_2 + 0x28) != 0)) || (local_8 < uVar2)) {
LAB_00612ef7:
              local_c = (int)DAT_006dfe2c_placeholder[iVar4 * 0x12];
              local_2c = DAT_006dfe6c_placeholder[iVar4 * 0x12];
              if (local_c == 2) {
                uVar2 = local_8 & 0x1fff;
                if (uVar2 < 0x800) {
                  local_c = 2;
                } else if (uVar2 < 0x1000) {
                  local_c = 0xb;
                } else if (uVar2 < 0x1800) {
                  local_c = 0xc;
                } else if (uVar2 < 0x2000) {
                  local_c = 0xd;
                }
                local_8 = local_8 & 0x7ff;
              } else if (local_c == -3) {
                local_c = 4;
LAB_00612f74:
                local_8 = 0;
              } else if (local_c == -4) {
                local_c = 4;
                local_8 = 2;
              } else {
                if (local_c == -5) {
                  local_c = 4;
                } else {
                  if (local_c == -6) {
                    local_c = 0x11;
                    goto LAB_00612f74;
                  }
                  if (local_c != -7) goto LAB_00612fb9;
                  local_c = 0x11;
                }
                local_8 = 1;
              }
LAB_00612fb9:
              local_30 = 0;
              if ((5 < iVar3) && (iVar3 < 10)) {
                local_24 = 1;
              }
              if (((3 < iVar3) && (iVar3 < 6)) || ((0xc < iVar3 && (iVar3 < 0xf)))) {
                local_28 = 1;
              }
              pbVar6 = local_18;
              goto LAB_00612feb;
            }
          }
        }
        goto LAB_006130d2;
      }
      if (local_24 == 0) {
LAB_006130a7:
        if (local_28 != 0) {
          iVar4 = 4;
          bVar9 = true;
          pbVar7 = local_40;
          pbVar8 = (uint8_t*)&DAT_006e05f8_placeholder;
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar9 = *pbVar7 == *pbVar8;
            pbVar7 = pbVar7 + 1;
            pbVar8 = pbVar8 + 1;
          } while (bVar9);
          if (bVar9) {
            local_14 = 0xb000000;
            local_28 = 0;
            goto LAB_00612feb;
          }
        }
LAB_006130cf:
        in_ECX = local_10;
        goto LAB_006130d2;
      }
      iVar4 = 5;
      bVar9 = true;
      pbVar7 = local_40;
      pbVar8 = (uint8_t*)&DAT_006e0f5c_placeholder;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar9 = *pbVar7 == *pbVar8;
        pbVar7 = pbVar7 + 1;
        pbVar8 = pbVar8 + 1;
      } while (bVar9);
      if (bVar9) {
        local_14 = 0x2000000;
      } else {
        iVar4 = 4;
        bVar9 = true;
        pbVar7 = local_40;
        pbVar8 = (uint8_t*)&DAT_006e0f58_placeholder;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar9 = *pbVar7 == *pbVar8;
          pbVar7 = pbVar7 + 1;
          pbVar8 = pbVar8 + 1;
        } while (bVar9);
        if (bVar9) {
          local_14 = 0x4000000;
        } else {
          iVar4 = 3;
          bVar9 = true;
          pbVar7 = local_40;
          pbVar8 = (uint8_t*)&DAT_006e0838_placeholder;
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar9 = *pbVar7 == *pbVar8;
            pbVar7 = pbVar7 + 1;
            pbVar8 = pbVar8 + 1;
          } while (bVar9);
          if (bVar9) {
            local_14 = 0x7000000;
          } else {
            iVar4 = 3;
            bVar9 = true;
            pbVar7 = local_40;
            pbVar8 = (uint8_t*)&DAT_006e0f54_placeholder;
            do {
              if (iVar4 == 0) break;
              iVar4 = iVar4 + -1;
              bVar9 = *pbVar7 == *pbVar8;
              pbVar7 = pbVar7 + 1;
              pbVar8 = pbVar8 + 1;
            } while (bVar9);
            if (!bVar9) {
              iVar4 = 3;
              bVar9 = true;
              pbVar7 = local_40;
              pbVar8 = (uint8_t*)&DAT_006e0f50_placeholder;
              do {
                if (iVar4 == 0) break;
                iVar4 = iVar4 + -1;
                bVar9 = *pbVar7 == *pbVar8;
                pbVar7 = pbVar7 + 1;
                pbVar8 = pbVar8 + 1;
              } while (bVar9);
              if (!bVar9) {
                iVar4 = 3;
                bVar9 = true;
                pbVar7 = local_40;
                pbVar8 = (uint8_t*)&DAT_006e0f4c_placeholder;
                do {
                  if (iVar4 == 0) break;
                  iVar4 = iVar4 + -1;
                  bVar9 = *pbVar7 == *pbVar8;
                  pbVar7 = pbVar7 + 1;
                  pbVar8 = pbVar8 + 1;
                } while (bVar9);
                if (!bVar9) {
                  iVar4 = 3;
                  bVar9 = true;
                  pbVar7 = local_40;
                  pbVar8 = (uint8_t*)&DAT_006e0f48_placeholder;
                  do {
                    if (iVar4 == 0) break;
                    iVar4 = iVar4 + -1;
                    bVar9 = *pbVar7 == *pbVar8;
                    pbVar7 = pbVar7 + 1;
                    pbVar8 = pbVar8 + 1;
                  } while (bVar9);
                  if (!bVar9) goto LAB_006130a7;
                }
                local_14 = 0xa000000;
                goto LAB_0061309f;
              }
            }
            local_14 = 0x9000000;
          }
        }
      }
LAB_0061309f:
      local_24 = 0;
LAB_00612feb:
      in_ECX = local_10;
    } while (*pbVar6 != 0);
  }
  if (in_ECX[0x1e] == 0) {
LAB_00613101:
    iVar4 = FUN_0060d19b(0x2c);
    if (iVar4 == 0) {
      iVar4 = 0;
    } else {
      iVar4 = FUN_0065caaa(local_c, (int)local_14, (int)local_8, (int)local_2c, nullptr);
    }
    if (iVar4 != 0) {
      if (param_2 == 0) {
        return iVar4;
      }
      *(uint32_t*)(iVar4 + 0x28) = *(uint32_t*)(param_2 + 0x28);
      *(uint32_t*)(param_2 + 0x28) = 0;
      return iVar4;
    }
  } else {
    if (*(int*)(in_ECX[0x1e] + 0xb0) == 0) {
      if ((((((local_c == 3) || (local_c == 5)) || (local_c == 6)) || ((local_c == 8 || (local_c == 9)))) || ((local_c == 4 || ((local_c == 0xf || (local_c == 0x12)))))) || (local_c == 0x13))
        goto LAB_00613101;
      pcVar10 = (char*)"temporary and constant registers are not allowed in assembly fragments";
    } else {
      if ((((local_c == 3) || (local_c == 0xf)) || (local_c == 0x12)) || (local_c == 0x13))
        goto LAB_00613101;
      pcVar10 = (char*)"temporary, constant, and output registers are not allowed in vs_3_0 assembly fragments";
    }
    FUN_0060fcd3(*in_ECX, param_1, 0x7d5, pcVar10);
LAB_006131f1:
    in_ECX[0x13] = 1;
    iVar4 = FUN_0060d19b(0x2c);
    if (iVar4 != 0) {
      iVar4 = FUN_0065caaa(0xffffffff, 0, 0, 0, nullptr);
      return iVar4;
    }
  }
  return 0;
}

// ---------------------------------------------------------------------------
// Appended reconstructions (mass_0277 retry): shader assembly front end.
// Register receivers become an explicit first parameter. Access follows the
// Ghidra listing's declared receiver type: typed pointers scale, receivers
// declared `int` use byte offsets.
// ---------------------------------------------------------------------------

// Referenced helpers and parser-state globals not declared above.
extern void FUN_00610cdc(void);
extern int FUN_00616086(uint32_t a, void *b);
extern int DAT_0072b238;
extern int DAT_0072b234;
extern int DAT_0072b230;
extern int16_t DAT_00719d50[];
extern int16_t DAT_00719e98[];
extern int16_t DAT_00719fa0[];
extern int16_t DAT_00719cd0[];
extern int16_t DAT_00719c50[];
extern int16_t DAT_00719e58[];
extern int16_t DAT_0071a338[];
extern int16_t DAT_0071a0e8[];
extern int16_t DAT_0071a0a8[];
extern int16_t DAT_0072b21e;
extern int16_t *DAT_0072b22c;
extern uint32_t *DAT_0072b228;
extern uint32_t DAT_0072b220;
extern uint32_t DAT_0072b224;
extern int *DAT_0072b240;
extern int DAT_0072ae38;
extern uint32_t DAT_0072a668[];

// 0x613230 — observed shape: void, frees the leading pointer and resets the helper
void FUN_00613230(uint32_t *self) {
  operator_delete((void *)*self);
  if (self[8] != 0) {
    FUN_006126a6(1);
  }
}

// 0x61324d — observed shape: void, releases a virtual sub-object, a buffer, and helper state
void FUN_0061324d(intptr_t self) {
  int *piVar1;

  piVar1 = *(int **)(self + 8);
  if (piVar1 != (int *)0) {
    (*(void (**)(int *))((intptr_t)*piVar1 + 8))(piVar1);
    *(uint32_t *)(self + 8) = 0;
  }
  operator_delete(*(void **)(self + 0x58));
  if (*(int *)(self + 0x78) != 0) {
    FUN_00612bfd(1);
  }
}

// 0x61327c — observed shape: void(opcode, argcount), expression/parse-stack builder
void FUN_0061327c_recon(uint32_t *self, uint32_t param_1, uint32_t param_2) {
  double dVar1;
  uint32_t *puVar2;
  uint32_t *puVar3;
  uint32_t *puVar4;
  int iVar5;
  uint32_t uVar6;
  uint32_t uVar7;
  uint32_t *puVar8;
  char *pcVar9;
  // apuStack_44 models the register spill slots Ghidra uses for the incoming
  // EDI/ESI values; slots 0/1 are only read back before any store when
  // param_2 == 0 (undefined in the listing).
  uint32_t *apuStack_44[16];

  puVar8 = apuStack_44[1];
  puVar3 = apuStack_44[0];
  uVar6 = param_2;
  if (self[0x14] != 0) {
    return;
  }
  while (true) {
    apuStack_44[0] = puVar3;
    apuStack_44[1] = puVar8;
    if (uVar6 == 0) break;
    iVar5 = (int)self[0xd];
    if (iVar5 == 0) {
      FUN_0060fcd3((int)*self, (int)(intptr_t)(self + 4), 0, "internal error: stack underflow");
      self[0x13] = 1;
      return;
    }
    apuStack_44[uVar6 - 1] = *(uint32_t **)(iVar5 + 8);
    self[0xd] = *(uint32_t *)(iVar5 + 0xc);
    *(uint32_t *)(iVar5 + 8) = 0;
    *(uint32_t *)(iVar5 + 0xc) = 0;
    puVar8 = apuStack_44[1];
    puVar3 = apuStack_44[0];
    uVar6 = uVar6 - 1;
  }
  puVar4 = (uint32_t *)0;
  puVar2 = self;
  switch (param_1) {
  case 0:
  case 6:
    puVar4 = (uint32_t *)0;
    break;
  case 1:
  case 2:
  case 4:
  case 5:
  case 10:
  case 0x17:
  case 0x19:
  case 0x1d:
  case 0x23:
  case 0x29:
  case 0x2a:
  case 0x2f:
  case 0x30:
    puVar4 = puVar3;
    break;
  case 3:
    puVar4 = (uint32_t *)(intptr_t)FUN_0065ac0a(puVar8, puVar3);
    break;
  case 7:
    puVar4 = (uint32_t *)0;
    if (self[0x1d] == 0) {
      self[0x1d] = puVar3[6];
    }
    break;
  case 8:
    goto code_r0x0061334e;
  case 9:
    if (((int)self[0xe] < 6) || (9 < (int)self[0xe])) {
      pcVar9 = "instruction coissue is not supported in this shader version";
      uVar7 = 0x7eb;
      puVar4 = puVar3;
      puVar2 = puVar3;
      goto code_r0x00613528;
    }
    puVar3[0x15] = 1;
code_r0x0061334e:
    FUN_006118e5(puVar3);
    puVar4 = puVar3;
    break;
  case 0xb:
    iVar5 = (int)self[0xe];
    if (((1 < iVar5) && (iVar5 < 6)) || ((10 < iVar5 && (iVar5 < 0xf)))) {
      puVar8[0x10] = puVar3;
      puVar4 = puVar8;
      break;
    }
    pcVar9 = "instruction predication is not supported in this shader version";
    uVar7 = 0x7ec;
    puVar4 = puVar8;
    puVar2 = puVar8;
    goto code_r0x00613528;
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
    apuStack_44[0] = (uint32_t *)0;
    if (1 < param_2) {
      apuStack_44[1] = (uint32_t *)0;
      puVar3[0xf] = puVar8;
    }
    uVar6 = 2;
    puVar4 = puVar3;
    if (2 < param_2) {
      puVar8 = puVar3 + 0x11;
      do {
        puVar2 = apuStack_44[uVar6];
        apuStack_44[uVar6] = (uint32_t *)0;
        *puVar8 = puVar2;
        uVar6 = uVar6 + 1;
        puVar8 = puVar8 + 1;
      } while (uVar6 < param_2);
    }
    break;
  case 0x15:
  case 0x16:
    apuStack_44[0] = (uint32_t *)0;
    uVar6 = 1;
    puVar4 = puVar3;
    if (1 < param_2) {
      puVar8 = puVar3 + 0x11;
      do {
        puVar2 = apuStack_44[uVar6];
        apuStack_44[uVar6] = (uint32_t *)0;
        *puVar8 = puVar2;
        uVar6 = uVar6 + 1;
        puVar8 = puVar8 + 1;
      } while (uVar6 < param_2);
    }
    break;
  case 0x18:
    if (puVar3[7] == 0) {
      uVar7 = (uint32_t)FUN_00611665(puVar8 + 4);
      puVar3[8] = uVar7;
      puVar4 = puVar3;
    } else {
      FUN_0060fcd3((int)*self, (int)(intptr_t)(self + 4), 0x7e6, "scalar registers cannot be masked");
      self[0x13] = 1;
      puVar3[8] = 0xf0000;
      puVar4 = puVar3;
    }
    break;
  case 0x1a:
    if (puVar3[5] == 0) {
      puVar3[5] = 0xd000000;
      puVar4 = puVar3;
      break;
    }
    pcVar9 = "not cannot be used with other modifiers";
    uVar7 = 0x7e2;
    puVar4 = puVar3;
    goto code_r0x00613528;
  case 0x1b:
    iVar5 = (int)puVar3[5];
    if (iVar5 == 0) {
      puVar3[5] = 0x1000000;
      puVar4 = puVar3;
      break;
    }
    if (iVar5 == 0x2000000) {
      puVar3[5] = 0x3000000;
      puVar4 = puVar3;
      break;
    }
    if (iVar5 == 0x4000000) {
      puVar3[5] = 0x5000000;
      puVar4 = puVar3;
      break;
    }
    if (iVar5 == 0x7000000) {
      puVar3[5] = 0x8000000;
      puVar4 = puVar3;
      break;
    }
    if ((iVar5 != 0x9000000) && (iVar5 != 0xa000000)) {
      puVar4 = puVar3;
      if (iVar5 == 0xb000000) {
        puVar3[5] = 0xc000000;
      }
      break;
    }
    pcVar9 = "negate and divide modifiers cannot be combined";
    uVar7 = 0x7db;
    puVar4 = puVar3;
    goto code_r0x00613528;
  case 0x1c:
    if (puVar3[6] == 1) {
      if (((int)self[0xe] < 6) || (9 < (int)self[0xe])) {
        pcVar9 = "complement is not supported in this shader version";
        uVar7 = 0x7ed;
        puVar4 = puVar8;
      } else {
        if (puVar8[5] == 0) {
          puVar8[5] = 0x6000000;
          puVar4 = puVar8;
          break;
        }
        pcVar9 = "complement cannot be used with other modifiers";
        uVar7 = 0x7dc;
        puVar4 = puVar8;
      }
    } else {
      pcVar9 = "invalid complement expression";
      uVar7 = 0x7da;
      puVar4 = puVar8;
    }
    goto code_r0x00613528;
  case 0x1e:
    if (puVar3[7] == 0) {
      uVar7 = (uint32_t)FUN_0061171a(puVar8 + 4);
      puVar3[9] = uVar7;
      puVar4 = puVar3;
    } else {
      FUN_0060fcd3((int)*self, (int)(intptr_t)(self + 4), 0x7e6, "scalar registers cannot be swizzled");
      self[0x13] = 1;
      puVar3[9] = 0xe40000;
      puVar4 = puVar3;
    }
    break;
  case 0x21:
    puVar8 = (uint32_t *)0;
    goto code_r0x0061359e;
  case 0x22:
code_r0x0061359e:
    puVar4 = (uint32_t *)(intptr_t)FUN_00612cfc((int)(intptr_t)(puVar3 + 4), (int)(intptr_t)puVar8);
    goto code_r0x00613722;
  case 0x24:
    puVar3[6] = puVar3[6] + puVar8[6];
    if (puVar3[10] == 0) {
      puVar3[10] = puVar8[10];
      puVar8[10] = 0;
      puVar4 = puVar3;
      break;
    }
    puVar4 = puVar3;
    if (puVar8[10] == 0) break;
    pcVar9 = "only one address register reference allowed in a relative address expression";
    uVar7 = 0x7d9;
code_r0x00613528:
    FUN_0060fcd3((int)*self, (int)(intptr_t)(puVar2 + 4), (int)uVar7, pcVar9);
    self[0x13] = 1;
    break;
  case 0x25:
    iVar5 = FUN_0060d19b(0x2c);
    puVar4 = (uint32_t *)0;
    if (iVar5 != 0) {
      uVar7 = 0;
      puVar8 = apuStack_44[0];
code_r0x00613605:
      puVar4 = (uint32_t *)(intptr_t)FUN_0065caaa(0, 0, (int)uVar7, 0, puVar8);
    }
    goto code_r0x00613722;
  case 0x26:
    iVar5 = FUN_0060d19b(0x2c);
    puVar4 = (uint32_t *)0;
    if (iVar5 != 0) {
      uVar7 = apuStack_44[0][6];
      puVar8 = (uint32_t *)0;
      goto code_r0x00613605;
    }
    goto code_r0x00613722;
  case 0x27:
    iVar5 = FUN_0060d19b(0x30);
    if (iVar5 == 0) {
      puVar4 = (uint32_t *)0;
    } else {
      puVar4 = (uint32_t *)(intptr_t)FUN_0065ae50(self + 4);
    }
    FUN_00610d4a(puVar4);
    puVar4[4] = 2;
    puVar4[6] = 1;
    break;
  case 0x28:
    iVar5 = FUN_0060d19b(0x30);
    if (iVar5 == 0) {
      puVar4 = (uint32_t *)0;
    } else {
      puVar4 = (uint32_t *)(intptr_t)FUN_0065ae50(self + 4);
    }
    FUN_00610d4a(puVar4);
    puVar4[6] = 0;
    puVar4[4] = 2;
    break;
  case 0x2b:
    puVar3[6] = (uint32_t)(-(int)puVar3[6]);
    puVar4 = puVar3;
    break;
  case 0x2c:
  case 0x2d:
    dVar1 = (double)(int)puVar3[6];
    puVar3[4] = 5;
    if ((int)puVar3[6] < 0) {
      dVar1 = dVar1 + 4294967296.0;
    }
    goto code_r0x006136ba;
  case 0x2e:
    dVar1 = (double)(int)puVar3[6];
    puVar3[4] = 5;
    if ((int)puVar3[6] < 0) {
      dVar1 = dVar1 + 4294967296.0;
    }
    goto code_r0x006136e1;
  case 0x31:
    dVar1 = *(double *)(puVar3 + 6);
code_r0x006136e1:
    dVar1 = -dVar1;
code_r0x006136ba:
    *(double *)(puVar3 + 6) = dVar1;
    puVar4 = puVar3;
    break;
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3b:
  case 0x3c:
    iVar5 = FUN_0060d19b(0x60);
    if (iVar5 == 0) {
code_r0x00613720:
      puVar4 = (uint32_t *)0;
    } else {
      puVar4 = (uint32_t *)(intptr_t)FUN_0065ca23(self + 4, (int)self[0x10], (int)self[0x11], (int)self[0x12]);
    }
    goto code_r0x00613722;
  case 0x3d:
  case 0x3e:
  case 0x3f:
    iVar5 = FUN_0060d19b(0x30);
    if (iVar5 == 0) goto code_r0x00613720;
    puVar4 = (uint32_t *)(intptr_t)FUN_0065ae50(self + 4);
code_r0x00613722:
    FUN_00610d4a(puVar4);
  }
  if (self[0x14] == 0) {
    iVar5 = FUN_0060d19b(0x14);
    if (iVar5 == 0) {
      iVar5 = 0;
    } else {
      iVar5 = FUN_0065ac49(puVar4, (int)self[0xd], "Stack");
    }
    if (iVar5 == 0) {
      FUN_0060fcd3((int)*self, (int)(intptr_t)(self + 4), 0, "internal error: out of memory");
      self[0x14] = 1;
      self[0x13] = 1;
    } else {
      self[0xd] = (uint32_t)iVar5;
    }
  }
}

// 0x613829 — observed shape: int, yacc-style shift/reduce driver for the shader grammar
int FUN_00613829(void) {
  int16_t sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  uint32_t uVar6;
  uint32_t uVar7;

  iVar4 = 0;
  DAT_0072b238 = 0;
  DAT_0072b234 = 0;
  DAT_0072b22c = (int16_t *)&DAT_0072ae38;
  DAT_0072b228 = (uint32_t *)&DAT_0072a668;
  DAT_0072ae38 = 0;
LAB_00613857:
  DAT_0072b230 = -1;
LAB_0061385f:
  iVar2 = (int)DAT_00719d50[iVar4];
  if (iVar2 == 0) {
    if ((DAT_0072b230 < 0) && (DAT_0072b230 = FUN_00612c1e(), DAT_0072b230 < 0)) {
      DAT_0072b230 = 0;
    }
    if (((DAT_00719e98[iVar4] != 0) &&
         (iVar2 = DAT_00719e98[iVar4] + DAT_0072b230, -1 < iVar2)) && (iVar2 < 0x128) &&
       (DAT_0071a338[iVar2] == DAT_0072b230)) {
      if (&DAT_0072b21e <= DAT_0072b22c) goto LAB_00613cff;
      iVar4 = (int)DAT_0071a0e8[iVar2];
      DAT_0072b22c = DAT_0072b22c + 1;
      *DAT_0072b22c = DAT_0071a0e8[iVar2];
      DAT_0072b228 = DAT_0072b228 + 1;
      *DAT_0072b228 = DAT_0072b220;
      DAT_0072b230 = -1;
      if (0 < DAT_0072b234) {
        DAT_0072b234 = DAT_0072b234 + -1;
      }
      goto LAB_0061385f;
    }
    if (((DAT_00719fa0[iVar4] != 0) && (iVar2 = DAT_00719fa0[iVar4] + DAT_0072b230, -1 < iVar2)) &&
       ((iVar2 < 0x128 && (DAT_0071a338[iVar2] == DAT_0072b230)))) {
      iVar2 = (int)DAT_0071a0e8[iVar2];
      goto LAB_00613946;
    }
    if (DAT_0072b234 == 0) {
      FUN_00610c1c(DAT_0072b240, "syntax error");
      DAT_0072b238 = DAT_0072b238 + 1;
    }
    if (2 < DAT_0072b234) goto LAB_00613cf6;
    DAT_0072b234 = 3;
    while (((DAT_00719e98[*DAT_0072b22c] == 0 ||
            (iVar4 = DAT_00719e98[*DAT_0072b22c] + 0x100, iVar4 < 0)) ||
           ((0x127 < iVar4 || (DAT_0071a338[iVar4] != 0x100))))) {
      if (DAT_0072b22c < (int16_t *)0x72ae39) {
        DAT_0072b234 = 3;
        return 1;
      }
      DAT_0072b22c = DAT_0072b22c + -1;
      DAT_0072b228 = DAT_0072b228 + -1;
    }
    if ((int16_t *)0x72b21d < DAT_0072b22c) goto LAB_00613cff;
    sVar1 = DAT_0071a0e8[iVar4];
    DAT_0072b22c = DAT_0072b22c + 1;
    *DAT_0072b22c = sVar1;
    uVar6 = DAT_0072b220;
  } else {
LAB_00613946:
    iVar4 = (int)DAT_00719cd0[iVar2];
    DAT_0072b224 = DAT_0072b228[1 - iVar4];
    switch (iVar2) {
    case 1:
      uVar7 = 0;
      uVar6 = 0;
      break;
    case 2:
      uVar7 = 1;
      uVar6 = 1;
      break;
    case 3:
      uVar7 = 1;
      uVar6 = 2;
      break;
    case 4:
      uVar7 = 2;
      uVar6 = 3;
      break;
    case 5:
      uVar7 = 1;
      uVar6 = 4;
      break;
    case 6:
      uVar7 = 1;
      uVar6 = 5;
      break;
    case 7:
      uVar7 = 0;
      uVar6 = 6;
      break;
    case 8:
      uVar7 = 1;
      uVar6 = 7;
      break;
    case 9:
      uVar7 = 1;
      uVar6 = 8;
      break;
    case 10:
      uVar7 = 1;
      uVar6 = 9;
      break;
    case 0xb:
      uVar7 = 1;
      uVar6 = 10;
      break;
    case 0xc:
      uVar7 = 2;
      uVar6 = 0xb;
      break;
    case 0xd:
      uVar7 = 1;
      uVar6 = 0xc;
      break;
    case 0xe:
      uVar7 = 2;
      uVar6 = 0xd;
      break;
    case 0xf:
      uVar7 = 3;
      uVar6 = 0xe;
      break;
    case 0x10:
      uVar7 = 4;
      uVar6 = 0xf;
      break;
    case 0x11:
      uVar7 = 5;
      uVar6 = 0x10;
      break;
    case 0x12:
      uVar7 = 6;
      uVar6 = 0x11;
      break;
    case 0x13:
      uVar7 = 6;
      uVar6 = 0x12;
      break;
    case 0x14:
      uVar7 = 6;
      uVar6 = 0x13;
      break;
    case 0x15:
      uVar7 = 3;
      uVar6 = 0x14;
      break;
    case 0x16:
      uVar7 = 2;
      uVar6 = 0x15;
      break;
    case 0x17:
      uVar7 = 3;
      uVar6 = 0x16;
      break;
    case 0x18:
      uVar7 = 1;
      uVar6 = 0x17;
      break;
    case 0x19:
      uVar7 = 2;
      uVar6 = 0x18;
      break;
    case 0x1a:
      uVar7 = 1;
      uVar6 = 0x19;
      break;
    case 0x1b:
      uVar7 = 1;
      uVar6 = 0x1a;
      break;
    case 0x1c:
      uVar7 = 1;
      uVar6 = 0x1b;
      break;
    case 0x1d:
      uVar7 = 2;
      uVar6 = 0x1c;
      break;
    case 0x1e:
      uVar7 = 1;
      uVar6 = 0x1d;
      break;
    case 0x1f:
      uVar7 = 2;
      uVar6 = 0x1e;
      break;
    case 0x20:
      uVar7 = 1;
      uVar6 = 0x21;
      break;
    case 0x21:
      uVar7 = 2;
      uVar6 = 0x22;
      break;
    case 0x22:
      uVar7 = 1;
      uVar6 = 0x23;
      break;
    case 0x23:
      uVar7 = 2;
      uVar6 = 0x24;
      break;
    case 0x24:
      uVar7 = 1;
      uVar6 = 0x25;
      break;
    case 0x25:
      uVar7 = 1;
      uVar6 = 0x26;
      break;
    case 0x26:
      uVar7 = 0;
      uVar6 = 0x27;
      break;
    case 0x27:
      uVar7 = 0;
      uVar6 = 0x28;
      break;
    case 0x28:
      uVar7 = 1;
      uVar6 = 0x29;
      break;
    case 0x29:
      uVar7 = 1;
      uVar6 = 0x2a;
      break;
    case 0x2a:
      uVar7 = 1;
      uVar6 = 0x2b;
      break;
    case 0x2b:
      uVar7 = 1;
      uVar6 = 0x2c;
      break;
    case 0x2c:
      uVar7 = 1;
      uVar6 = 0x2d;
      break;
    case 0x2d:
      uVar7 = 1;
      uVar6 = 0x2e;
      break;
    case 0x2e:
      uVar7 = 1;
      uVar6 = 0x2f;
      break;
    case 0x2f:
      uVar7 = 1;
      uVar6 = 0x30;
      break;
    case 0x30:
      uVar7 = 1;
      uVar6 = 0x31;
      break;
    case 0x31:
      uVar7 = 0;
      uVar6 = 0x32;
      break;
    case 0x32:
      uVar7 = 0;
      uVar6 = 0x33;
      break;
    case 0x33:
      uVar7 = 0;
      uVar6 = 0x34;
      break;
    case 0x34:
      uVar7 = 0;
      uVar6 = 0x35;
      break;
    case 0x35:
      uVar7 = 0;
      uVar6 = 0x36;
      break;
    case 0x36:
      uVar7 = 0;
      uVar6 = 0x37;
      break;
    case 0x37:
      uVar7 = 0;
      uVar6 = 0x38;
      break;
    case 0x38:
      uVar7 = 0;
      uVar6 = 0x39;
      break;
    case 0x39:
      uVar7 = 0;
      uVar6 = 0x3a;
      break;
    case 0x3a:
      uVar7 = 0;
      uVar6 = 0x3b;
      break;
    case 0x3b:
      uVar7 = 0;
      uVar6 = 0x3c;
      break;
    case 0x3c:
      uVar7 = 0;
      uVar6 = 0x3d;
      break;
    case 0x3d:
      uVar7 = 0;
      uVar6 = 0x3e;
      break;
    case 0x3e:
      uVar7 = 0;
      uVar6 = 0x3f;
      break;
    default:
      goto switchD_00613970_default;
    }
    FUN_0061327c(uVar6, uVar7);
switchD_00613970_default:
    DAT_0072b22c = DAT_0072b22c + -iVar4;
    iVar3 = (int)*DAT_0072b22c;
    DAT_0072b228 = DAT_0072b228 + -iVar4;
    if ((iVar3 == 0) && (DAT_00719c50[iVar2] == 0)) {
      DAT_0072b22c = DAT_0072b22c + 1;
      iVar4 = 0x10;
      *DAT_0072b22c = 0x10;
      DAT_0072b228 = DAT_0072b228 + 1;
      *DAT_0072b228 = DAT_0072b224;
      bVar5 = DAT_0072b230 == 0;
      if (DAT_0072b230 < 0) {
        DAT_0072b230 = FUN_00612c1e();
        bVar5 = DAT_0072b230 == 0;
        if (DAT_0072b230 < 0) {
          DAT_0072b230 = 0;
          bVar5 = true;
        }
      }
      if (bVar5) {
        return 0;
      }
      goto LAB_0061385f;
    }
    iVar4 = DAT_00719c50[iVar2] * 2;
    if (((*(int16_t *)((uint8_t *)DAT_0071a0a8 + iVar4) == 0) ||
         (iVar2 = *(int16_t *)((uint8_t *)DAT_0071a0a8 + iVar4) + iVar3, iVar2 < 0)) ||
        (0x127 < iVar2) || (DAT_0071a338[iVar2] != iVar3)) {
      sVar1 = *(int16_t *)((uint8_t *)DAT_00719e58 + iVar4);
    } else {
      sVar1 = DAT_0071a0e8[iVar2];
    }
    if ((int16_t *)0x72b21d < DAT_0072b22c) {
LAB_00613cff:
      FUN_00610c1c(DAT_0072b240, "yacc stack overflow");
      return 1;
    }
    DAT_0072b22c = DAT_0072b22c + 1;
    *DAT_0072b22c = sVar1;
    uVar6 = DAT_0072b224;
  }
  iVar4 = (int)sVar1;
  DAT_0072b228 = DAT_0072b228 + 1;
  *DAT_0072b228 = uVar6;
  goto LAB_0061385f;
LAB_00613cf6:
  if (DAT_0072b230 == 0) {
    return 1;
  }
  goto LAB_00613857;
}

// 0x613e10 — observed shape: int, top-level shader compilation and validator dispatch
int FUN_00613e10(int *self, int param_1, uint32_t param_2, int param_3, uint32_t *param_4) {
  int iVar1;
  uint32_t uVar2;
  HMODULE hModule;
  FARPROC pFVar3;
  int *piVar4;
  uint32_t uVar5;
  const char *pcVar6;
  uint8_t local_14[4];
  int local_10;
  int local_8;

  if ((param_2 & 0xffffff3c) != 0) {
    return -0x7789f794;
  }
  if (param_4 == (uint32_t *)0) {
    return -0x7789f794;
  }
  *param_4 = 0;
  operator_delete((void *)self[0x16]);
  if (self[0x1e] != 0) {
    FUN_00612bfd(1);
  }
  DAT_0072b240 = self;
  self[0xe] = -1;
  *self = param_1 + 0x18;
  self[0xf] = (int)param_2;
  self[1] = param_1;
  self[2] = 0;
  self[0xc] = 0;
  self[0xd] = 0;
  self[0x16] = 0;
  self[0x17] = 0;
  self[0x18] = 0;
  self[0x19] = 0;
  self[0x1a] = 0;
  self[0x13] = 0;
  self[0x14] = 0;
  self[0x15] = 0;
  self[0x1b] = 0;
  self[0x1c] = 0;
  self[0x1d] = 0;
  FUN_0060bfba(&local_8, 0);
  if (local_8 == 0) {
    FUN_0060bfe9(self + 0x1b, self + 0x1c);
  }
  iVar1 = FUN_0060bf76(2);
  if (iVar1 < 0) {
    return iVar1;
  }
  FUN_00612c1e();
  if ((self[4] == 9) && (iVar1 = FUN_005f7fa4(self[6], 1, local_14), -1 < iVar1)) {
    self[4] = 0;
    self[6] = local_10;
  }
  if (self[4] != 0) {
    pcVar6 = "shader version expected";
    uVar5 = 0x7d1;
LAB_00613f08:
    FUN_0060fcd3((int)*self, (int)(intptr_t)(self + 4), (int)uVar5, pcVar6);
    goto LAB_00613f16;
  }
  if (self[6] == -0x1ff00) {
    FUN_0060fd9a((int)*self, (int)(intptr_t)(self + 4), 0x7df, "vs_1_0 is no longer supported; using vs_1_1");
    self[6] = -0x1feff;
  }
  if (self[6] == -0xff00) {
    FUN_0060fd9a((int)*self, (int)(intptr_t)(self + 4), 0x7df, "ps_1_0 is no longer supported; using ps_1_1");
    self[6] = -0xfeff;
  }
  if (self[6] == -0xfdfe) {
    self[6] = -0xfdff;
  }
  if ((((param_2 & 0x40) != 0) && (((uint32_t)self[6] & 0xffff0000U) == 0xfffe0000)) ||
      (((param_2 & 0x80) != 0) && (((uint32_t)self[6] & 0xffff0000U) == 0xffff0000))) {
    self[0xf] = self[0xf] | 1;
  }
  uVar2 = (uint32_t)self[6];
  if (uVar2 < 0xffff0103) {
    if (uVar2 == 0xffff0102) {
      self[0xe] = 7;
    } else if (uVar2 == 0xfffe0101) {
      self[0xe] = 0;
    } else if (uVar2 == 0xfffe0200) {
      self[0xe] = 1;
    } else if (uVar2 == 0xfffe0201) {
      self[0xe] = 2;
    } else if (uVar2 == 0xfffe02ff) {
      self[0xe] = 3;
    } else if (uVar2 == 0xfffe0300) {
      self[0xe] = 4;
    } else if (uVar2 == 0xfffe03ff) {
      self[0xe] = 5;
    } else {
      if (uVar2 != 0xffff0101) goto LAB_0061407b;
      self[0xe] = 6;
    }
  } else if (uVar2 == 0xffff0103) {
    self[0xe] = 8;
  } else if (uVar2 == 0xffff0104) {
    self[0xe] = 9;
  } else if (uVar2 == 0xffff0200) {
    self[0xe] = 10;
  } else if (uVar2 == 0xffff0201) {
    self[0xe] = 0xb;
  } else if (uVar2 == 0xffff02ff) {
    self[0xe] = 0xc;
  } else if (uVar2 == 0xffff0300) {
    self[0xe] = 0xd;
  } else {
    if (uVar2 != 0xffff03ff) {
LAB_0061407b:
      pcVar6 = "unrecognized shader version";
      uVar5 = 0x7d2;
      goto LAB_00613f08;
    }
    self[0xe] = 0xe;
  }
  if (param_3 != 0) {
    self[0xf] = self[0xf] | 2;
    self[0x1f] = param_3;
    iVar1 = FUN_00533c78(0xb8);
    if (iVar1 == 0) {
      iVar1 = 0;
    } else {
      iVar1 = FUN_006127cf(self[0xe]);
    }
    self[0x1e] = iVar1;
    if (iVar1 == 0) {
      return -0x7ff8fff2;
    }
    iVar1 = self[0xe];
    if ((iVar1 < 0) || (5 < iVar1)) {
      if ((iVar1 < 10) || (0xe < iVar1)) {
        FUN_0060fcd3((int)*self, (int)(intptr_t)(self + 4), 0x7d1,
                     "only vs_1_1, vs_2_0, vs_2_x, vs_2_sw, ps_2_0, ps_2_x, and ps_2_sw are supported for assembly fragments");
        goto LAB_0061415c;
      }
      uVar2 = (uint32_t)*(uint8_t *)((intptr_t)self + 0x19) | 0x7fff00;
    } else {
      uVar2 = (uint32_t)*(uint8_t *)((intptr_t)self + 0x19) | 0x7ffe00;
    }
    self[6] = (int)(uVar2 << 8 | (uint32_t)self[6] & 0xffU);
  }
LAB_0061415c:
  if (((*(uint8_t *)(self + 0xf) & 2) == 0) &&
      (((hModule = GetModuleHandleA("d3d9.dll"), hModule != (HMODULE)0 ||
         (hModule = LoadLibraryA("d3d9.dll"), hModule != (HMODULE)0)) &&
        (pFVar3 = GetProcAddress(hModule, "Direct3DShaderValidatorCreate9"), pFVar3 != (FARPROC)0)))) {
    piVar4 = (int *)(intptr_t)(*pFVar3)();
    self[2] = (int)(intptr_t)piVar4;
    if ((piVar4 == (int *)0) ||
        (iVar1 = (*(int (**)(int *, void *))((intptr_t)*piVar4 + 0xc))(piVar4, (void *)FUN_00610cdc), -1 < iVar1)) {
      goto LAB_006141ad;
    }
  } else {
LAB_006141ad:
    iVar1 = FUN_006118bc(self[6]);
    if ((-1 < iVar1) && (iVar1 = FUN_006117d6(self + 4), -1 < iVar1)) {
      if (self[0x13] == 0) {
        iVar1 = FUN_00613829();
        if (iVar1 != 0) {
          self[0x13] = 1;
        }
        if (self[0x13] == 0) {
          if (self[0x1b] != 0) {
            FUN_0060bfe9(&param_2, (void *)0);
            uVar2 = (uint32_t)self[0x1b];
            if ((uVar2 < param_2) && (param_2 < (uint32_t)self[0x1c] + uVar2)) {
              self[0x1c] = (int)(param_2 - uVar2);
            }
          }
          if (((((self[0x1e] == 0) || (iVar1 = FUN_00612128(), -1 < iVar1)) &&
                (((*(uint8_t *)(self + 0xf) & 1) == 0 || (iVar1 = FUN_006123c0(), -1 < iVar1)))) &&
               ((iVar1 = FUN_006118bc(0xffff), -1 < iVar1 &&
                (iVar1 = FUN_006117d6(self + 4), -1 < iVar1)))) &&
              ((piVar4 = (int *)(intptr_t)self[2], piVar4 == (int *)0 ||
               (iVar1 = (*(int (**)(int *))((intptr_t)*piVar4 + 0x14))(piVar4), -1 < iVar1)))) {
            iVar1 = FUN_0060f796();
            if (iVar1 != 0) goto LAB_00613f16;
            iVar1 = FUN_006126e6(param_4);
            if (-1 < iVar1) {
              iVar1 = 0;
              goto LAB_006142a7;
            }
          }
          goto LAB_0061429c;
        }
      }
LAB_00613f16:
      iVar1 = -0x7789f4a7;
    }
  }
LAB_0061429c:
  self[0x13] = 1;
LAB_006142a7:
  piVar4 = (int *)(intptr_t)self[2];
  if (piVar4 != (int *)0) {
    (*(void (**)(int *))((intptr_t)*piVar4 + 8))(piVar4);
    self[2] = 0;
  }
  FUN_0060f49b();
  return iVar1;
}

// 0x6142c8 — observed shape: void, initializes shader parser limits, epsilon, and infinity sentinels
void FUN_006142c8(uint32_t *self) {
  *(uint64_t *)(self + 0x2c) = 0x3eb0c6f7a0b5ed8dULL;
  *self = 0;
  self[1] = 0;
  self[2] = 0;
  self[6] = 0;
  self[0x13] = 0;
  self[0x14] = 0;
  self[0x15] = 0;
  self[0x16] = 0;
  self[0x17] = 0;
  self[0x18] = 0;
  self[0x19] = 0;
  self[0x21] = 0;
  self[0x22] = 0;
  self[0x23] = 0;
  self[0x24] = 0;
  self[0x25] = 0;
  self[0x26] = 0;
  self[0x27] = 0;
  self[0x28] = 0;
  self[0x29] = 0x7ff00000;
  self[0x2a] = 0;
  self[0x2b] = 0xfff00000;
}

// 0x614343 — observed shape: void(byte), scalarizing destructor invoking base and allocator cleanup
void FUN_00614343(void *self, uint8_t param_1) {
  FUN_006338c7();
  if ((param_1 & 1) != 0) {
    FUN_0065d0e1(self);
  }
}

// 0x614363 — observed shape: undefined4(uint), dynamic token capacity expander
uint32_t FUN_00614363(intptr_t self, uint32_t param_1) {
  int iVar1;
  uint32_t uVar2;

  uVar2 = *(uint32_t *)(self + 0x94);
  if (uVar2 < param_1) {
    if (uVar2 == 0) {
      uVar2 = 0x10;
    } else {
      uVar2 = uVar2 * 2;
    }
    for (; uVar2 < param_1; uVar2 = uVar2 * 2) {
    }
    iVar1 = FUN_00533c78((int)(uVar2 << 2));
    if (iVar1 == 0) {
      return 0;
    }
    operator_delete(*(void **)(self + 0x90));
    *(int *)(self + 0x90) = iVar1;
    *(uint32_t *)(self + 0x94) = uVar2;
  }
  return *(uint32_t *)(self + 0x90);
}

// 0x6143c6 — observed shape: undefined4*(int), dynamic memory block allocator with header
uint32_t *FUN_006143c6(intptr_t self, int param_1) {
  uint32_t *puVar1;
  uint32_t uVar2;
  uint32_t uVar3;

  uVar2 = (uint32_t)(param_1 + 2);
  if (*(uint32_t *)(self + 0x8c) < uVar2) {
    uVar3 = uVar2;
    if (uVar2 < 0x2000) {
      uVar3 = 0x2000;
    }
    puVar1 = (uint32_t *)FUN_00533c78((int)(uVar3 << 2));
    if (puVar1 == (uint32_t *)0) {
      return (uint32_t *)0;
    }
    *puVar1 = *(uint32_t *)(self + 0x88);
    puVar1[1] = (uint32_t)(-*(int *)(self + 0x8c));
    *(uint32_t **)(self + 0x88) = puVar1;
    *(uint32_t *)(self + 0x8c) = uVar3;
  } else {
    puVar1 = *(uint32_t **)(self + 0x88);
    *puVar1 = (uint32_t)(uintptr_t)puVar1;
    puVar1[1] = *(uint32_t *)(self + 0x8c);
  }
  *(int *)(self + 0x8c) = *(int *)(self + 0x8c) - (int)uVar2;
  *(int *)(self + 0x88) = *(int *)(self + 0x88) + (int)(uVar2 * 4);
  return puVar1 + 2;
}

// 0x614447 — observed shape: void(int), pops/restores allocator block state from header
void FUN_00614447(intptr_t self, int param_1) {
  int iVar1;

  if (param_1 != 0) {
    *(uint32_t *)(self + 0x88) = *(uint32_t *)(param_1 + -8);
    iVar1 = *(int *)(param_1 + -4);
    if (iVar1 < 1) {
      *(int *)(self + 0x8c) = -iVar1;
      operator_delete((void *)(param_1 + -8));
    } else {
      *(int *)(self + 0x8c) = iVar1;
    }
  }
}

// 0x614480 — observed shape: undefined4(undefined4*, int), sets array elements to 0xffffffff
uint32_t FUN_00614480(uint32_t *param_1, int param_2) {
  if (param_2 != 0) {
    for (; param_2 != 0; param_2 = param_2 + -1) {
      *param_1 = 0xffffffff;
      param_1 = param_1 + 1;
    }
  }
  return 0;
}

// 0x61449c — observed shape: undefined4(...), matrix/vector register binding layout driver
uint32_t FUN_0061449c(intptr_t self, uint32_t *param_1, uint32_t param_2, uint32_t param_3,
                      uint32_t *param_4, uint32_t *param_5, uint32_t param_6,
                      int *param_7, uint32_t param_8, int *param_9) {
  int iVar1;
  int iVar2;
  bool bVar3;
  uint32_t uVar4;
  int iVar5;
  int iVar6;
  uint32_t uVar7;
  int iVar8;
  uint32_t uVar9;
  uint32_t local_1c;
  int local_c;
  int local_8;

  uVar7 = param_2;
  iVar6 = (int)(param_2 * param_3);
  if (iVar6 != 0) {
    if ((param_1 == (uint32_t *)0x2) && (((uint32_t)(uintptr_t)param_4 & 0x400) == 0)) {
      param_2 = param_3;
      bVar3 = true;
      param_3 = uVar7;
    } else {
      bVar3 = false;
    }
    uVar7 = (param_3 + 3) >> 2;
    iVar8 = (int)(uVar7 * param_2);
    if (param_6 < *(uint32_t *)(*(int *)(self + 8) + 4)) {
      iVar5 = *(int *)(*(int *)(*(int *)(self + 8) + 0x10) + param_6 * 4);
    } else {
      iVar5 = 0;
    }
    if (iVar5 == 0) {
      return 0x80004005;
    }
    iVar2 = *(int *)(iVar5 + 0x10);
    iVar1 = iVar2 + iVar8;
    *(int *)(iVar5 + 0x10) = iVar1;
    if ((*(uint8_t *)(iVar5 + 4) & 0x40) != 0) {
      *(int *)(iVar5 + 8) = iVar1;
    }
    if (param_2 != 0) {
      local_c = 0;
      local_8 = 0;
      param_4 = param_5;
      local_1c = param_2;
      do {
        uVar9 = 0;
        if (param_3 != 0) {
          param_1 = param_4;
          do {
            if (bVar3) {
              uVar4 = *param_1;
            } else {
              uVar4 = param_5[local_8 + uVar9];
            }
            if (uVar4 < *(uint32_t *)(*(int *)(self + 8) + 8)) {
              iVar5 = *(int *)(*(int *)(*(int *)(self + 8) + 0x14) + uVar4 * 4);
            } else {
              iVar5 = 0;
            }
            if (iVar5 != 0) {
              *(uint32_t *)(iVar5 + 4) = param_6;
              iVar1 = (int)(uVar9 >> 2) + local_c + iVar2;
              *(uint32_t *)(iVar5 + 0x68) = param_8;
              *(int *)(iVar5 + 0xc) = iVar1;
              *(uint32_t *)(iVar5 + 0x10) = uVar9 & 3;
              *(uint32_t *)(iVar5 + 0x70) = *param_7 + (iVar1 - iVar2) * 4 + (uVar9 & 3);
            }
            param_1 = param_1 + param_2;
            uVar9 = uVar9 + 1;
          } while (uVar9 < param_3);
        }
        param_4 = param_4 + 1;
        local_8 = local_8 + (int)param_3;
        local_c = local_c + (int)uVar7;
        local_1c = local_1c - 1;
      } while (local_1c != 0);
    }
    *param_7 = *param_7 + iVar8 * 4;
  }
  if (param_9 != (int *)0) {
    *param_9 = iVar6;
  }
  return 0;
}

// 0x6145fe — observed shape: undefined4(uint), allocates and builds per-constant layout tables
uint32_t FUN_006145fe(intptr_t self, uint32_t param_1) {
  uint32_t *puVar1;
  int iVar2;
  int iVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  int iVar6;
  uint32_t uVar7;
  uint32_t *puVar8;

  iVar3 = (int)param_1;
  uVar7 = 0;
  if (((*(int *)(param_1 + 0x14) == 0) || (*(int *)(param_1 + 0x28) == 0)) ||
      (*(int *)(param_1 + 0x38) != 0)) {
LAB_00614738:
    uVar5 = 0;
  } else {
    *(uint32_t *)(param_1 + 0x34) = 0;
    if (*(int *)(param_1 + 0x14) != 0) {
      iVar6 = *(int *)(param_1 + 0x10) << 2;
      do {
        uVar4 = (uint32_t)(*(int *)(*(int *)(*(int *)(*(int *)(self + 8) + 0x14) +
                                             *(int *)(iVar6 + *(int *)(self + 0x18)) * 4) + 0x70) + 1);
        if (*(uint32_t *)(param_1 + 0x34) < uVar4) {
          *(uint32_t *)(param_1 + 0x34) = uVar4;
        }
        uVar7 = uVar7 + 1;
        iVar6 = iVar6 + 4;
      } while (uVar7 < *(uint32_t *)(param_1 + 0x14));
    }
    iVar6 = FUN_0065aaac((int)(*(uint32_t *)(param_1 + 0x34) << 2), 0x10);
    *(int *)(param_1 + 0x38) = iVar6;
    if (iVar6 != 0) {
      iVar6 = FUN_0065aaac((int)(*(uint32_t *)(param_1 + 0x14) << 2), 0x10);
      *(int *)(param_1 + 0x3c) = iVar6;
      if (iVar6 != 0) {
        puVar1 = (uint32_t *)(param_1 + 0x34);
        puVar8 = (uint32_t *)(param_1 + 0x38);
        param_1 = 0;
        puVar8 = (uint32_t *)(intptr_t)*puVar8;
        for (uVar7 = *puVar1 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
          *puVar8 = 0;
          puVar8 = puVar8 + 1;
        }
        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(uint8_t *)puVar8 = 0;
          puVar8 = (uint32_t *)((intptr_t)puVar8 + 1);
        }
        puVar8 = *(uint32_t **)(iVar3 + 0x3c);
        for (uVar7 = *(uint32_t *)(iVar3 + 0x14) & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
          *puVar8 = 0;
          puVar8 = puVar8 + 1;
        }
        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(uint8_t *)puVar8 = 0;
          puVar8 = (uint32_t *)((intptr_t)puVar8 + 1);
        }
        iVar6 = *(int *)(*(int *)(iVar3 + 0x28) + 0x20);
        if (*(int *)(iVar3 + 0x14) != 0) {
          do {
            if (iVar6 == 0) break;
            iVar2 = *(int *)(*(int *)(*(int *)(self + 8) + 0x14) +
                             *(int *)(*(int *)(self + 0x18) +
                                      (*(int *)(iVar3 + 0x10) + (int)param_1) * 4) * 4);
            if ((*(uint8_t *)(*(int *)(*(int *)(*(int *)(self + 8) + 0x10) + *(int *)(iVar2 + 4) * 4) + 4) & 0x80) == 0) {
              *(int *)(*(int *)(iVar3 + 0x38) + *(int *)(iVar2 + 0x70) * 4) =
                  *(int *)(iVar6 + 8) + 0x10;
              *(int *)(*(int *)(iVar3 + 0x3c) + *(int *)(iVar2 + 100) * 4) =
                  *(int *)(iVar6 + 8) + 0x10;
            }
            param_1 = param_1 + 1;
            iVar6 = *(int *)(iVar6 + 0xc);
          } while (param_1 < *(uint32_t *)(iVar3 + 0x14));
        }
        goto LAB_00614738;
      }
    }
    uVar5 = 0x8007000e;
  }
  return uVar5;
}

// 0x614741 — observed shape: void(double*, double*, double*, byte), interval arithmetic multiplication
void FUN_00614741(intptr_t self, double *param_1, double *param_2, double *param_3, uint8_t param_4) {
  double *pdVar1;
  int iVar2;
  uint32_t uVar3;
  double local_24[4];

  local_24[0] = *param_2 * *param_3;
  uVar3 = 0;
  local_24[1] = *param_2 * param_3[1];
  local_24[2] = *param_3 * param_2[1];
  local_24[3] = param_2[1] * param_3[1];
  *param_1 = *(double *)(self + 0xa0);
  param_1[1] = *(double *)(self + 0xa8);
  do {
    pdVar1 = local_24 + uVar3;
    iVar2 = std::isnan(*pdVar1);
    if (iVar2 != 0) {
      if ((param_4 & 0x40) != 0) {
        *param_1 = local_24[uVar3];
        param_1[1] = local_24[uVar3];
        return;
      }
      *pdVar1 = 0.0;
    }
    if (*pdVar1 < *param_1) {
      *param_1 = *pdVar1;
    }
    if (param_1[1] < *pdVar1) {
      param_1[1] = *pdVar1;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 4);
}

// 0x6147e4 — observed shape: undefined4(uint, double*), evaluates expression ranges and propagates min/max intervals
uint32_t FUN_006147e4(intptr_t self, uint32_t param_1, double *param_2) {
  uint32_t *puVar1;
  int iVar2;
  uint32_t *puVar3;
  long double fVar4;
  int iVar5;
  uint32_t uVar6;
  int iVar7;
  int *piVar8;
  uint32_t uVar9;
  uint32_t uVar10;
  uint32_t uVar11;
  long double fVar12;
  double dVar13;
  double local_58;
  double local_50;
  double local_48;
  double local_40;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  double local_18;
  // Scratch union carrying the dual 64-bit float / 32-bit token operand representation
  // modeled in the Ghidra listing by CONCAT44 and ._4_4_ field extraction.
  union {
    double d;
    uint64_t u;
  } local_10;
  int local_8;

  local_10.u = 0;
  iVar5 = *(int *)(self + 8);
  puVar1 = *(uint32_t **)(*(int *)(iVar5 + 0x14) + param_1 * 4);
  if ((*puVar1 & 0x100) != 0) {
    if (param_2 == (double *)0) {
      return 0;
    }
    *param_2 = *(double *)(puVar1 + 8);
    dVar13 = *(double *)(puVar1 + 10);
LAB_0061482a:
    param_2[1] = dVar13;
    return 0;
  }
  if ((int8_t)*puVar1 < 0) {
    if (param_2 == (double *)0) {
      return 0;
    }
    *param_2 = *(double *)(puVar1 + 8);
    dVar13 = *(double *)(puVar1 + 8);
    goto LAB_0061482a;
  }
  local_38 = *(double *)(self + 0xa8);
  local_30 = *(double *)(self + 0xa0);
  local_8 = (int)self;
  if (puVar1[2] == 0xffffffff) {
    if (((*(uint8_t *)(*(int *)(*(int *)(iVar5 + 0x10) + puVar1[1] * 4) + 4) & 2) != 0) &&
        (puVar1[0x12] != 0xffffffff)) {
      puVar3 = *(uint32_t **)(*(int *)(iVar5 + 0x18) + puVar1[0x12] * 4);
      uVar6 = *puVar3;
      uVar10 = puVar1[4];
      if ((uVar6 & 0xf0000000) == 0x10000000) {
        uVar6 = uVar6 & 0xfff00000;
        if (((((uVar6 != 0x10f00000) && (uVar6 != 0x11000000)) && (uVar6 != 0x11100000)) &&
             ((uVar6 != 0x11200000 && (uVar6 != 0x11300000)))) &&
            ((uVar6 != 0x11400000 && (uVar6 != 0x11500000)))) {
          iVar5 = (int)FUN_006147e4(self, *(uint32_t *)(puVar3[2] + uVar10 * 4), &local_28);
          if (iVar5 < 0) goto LAB_006152a2;
          uVar6 = *puVar3 & 0xfff00000;
          if (uVar6 < 0x10700001) {
            if (uVar6 == 0x10700000) {
              if (local_28 < 0.0) goto LAB_0061530a;
              local_38 = 1.0 / std::sqrt(local_20);
              fVar12 = (long double)1.0 / std::sqrt((long double)local_28);
            } else if (uVar6 == 0x10000000) {
LAB_006150ed:
              local_38 = local_28;
LAB_0061513a:
              fVar12 = (long double)local_20;
            } else if (uVar6 == 0x10100000) {
              local_38 = -local_20;
              fVar12 = -(long double)local_28;
            } else if (uVar6 == 0x10200000) {
              if (0.0 <= local_28) {
                if (local_28 == 0.0) {
                  local_38 = 0.0;
                } else {
                  local_38 = local_28 + *(double *)(local_8 + 0xb0);
                }
              } else {
                local_38 = local_28 - *(double *)(local_8 + 0xb0);
              }
              if (0.0 <= local_20) {
                if (local_20 == 0.0) goto LAB_0061527e;
                fVar12 = (long double)local_20 + (long double)*(double *)(local_8 + 0xb0);
              } else {
                fVar12 = (long double)local_20 - (long double)*(double *)(local_8 + 0xb0);
              }
            } else if (uVar6 == 0x10300000) {
              if ((local_28 <= 0.0) && (0.0 <= local_20)) goto LAB_0061530a;
              local_38 = 1.0 / local_20;
              fVar12 = (long double)1 / (long double)local_28;
            } else {
              if (uVar6 == 0x10400000) {
                if (local_28 != local_20) goto LAB_00614e2e;
                iVar5 = std::isfinite(local_28);
                if (iVar5 != 0) {
                  dVar13 = std::floor(local_20);
                  fVar12 = (long double)local_28 - (long double)dVar13;
                  goto LAB_006152ed;
                }
                goto LAB_00614c28;
              }
              if (uVar6 == 0x10500000) {
                // Reconstructed EXP intrinsic (pow with base 2.0)
                fVar12 = (long double)std::pow(2.0, local_28);
LAB_0061522c:
                local_38 = (double)fVar12;
                fVar12 = (long double)std::pow(2.0, local_20);
              } else {
                if (uVar6 != 0x10600000) goto LAB_0061530a;
                if (local_28 <= 0.0) {
                  fVar12 = (long double)*(double *)(local_8 + 0xa8);
                } else {
                  fVar12 = (long double)std::log2((long double)local_28);
                  fVar4 = (long double)std::log2((long double)2.0);
                  fVar12 = ((long double)0.6931471805599453 * fVar12) /
                           ((long double)0.6931471805599453 * fVar4);
                }
                local_38 = (double)fVar12;
                if (0.0 < local_20) {
                  fVar12 = (long double)std::log2((long double)local_20);
                  fVar4 = (long double)std::log2((long double)2.0);
                  fVar12 = ((long double)0.6931471805599453 * fVar12) /
                           ((long double)0.6931471805599453 * fVar4);
                } else {
                  fVar12 = (long double)*(double *)(local_8 + 0xa8);
                }
              }
            }
            goto LAB_00615307;
          }
          if (uVar6 == 0x10800000) {
            if ((local_28 != local_20) || (iVar5 = std::isfinite(local_28), iVar5 == 0)) {
LAB_006152fc:
              local_38 = -1.0;
              goto LAB_00615302;
            }
            dVar13 = local_28;
LAB_006152eb:
            fVar12 = (long double)std::sin((long double)dVar13);
          } else {
            if (uVar6 != 0x10900000) {
              if (uVar6 == 0x10a00000) {
                if ((local_28 < -1.0) || (std::isnan(local_20) || (local_20 < 1.0) == (local_20 == 1.0)))
                  goto LAB_00614cdf;
                fVar12 = (long double)std::asin(local_28);
                local_38 = (double)fVar12;
                fVar12 = (long double)std::asin(local_20);
              } else if (uVar6 == 0x10b00000) {
                if ((local_28 < -1.0) || (std::isnan(local_20) || (local_20 < 1.0) == (local_20 == 1.0))) {
                  local_38 = 0.0;
                  goto LAB_00614f2f;
                }
                fVar12 = (long double)std::acos(local_28);
                local_38 = (double)fVar12;
                fVar12 = (long double)std::acos(local_20);
              } else {
                if (uVar6 != 0x10c00000) {
                  if ((((uVar6 == 0x10d00000) || (uVar6 == 0x10e00000)) && (local_28 == local_20)) &&
                      (iVar5 = std::isfinite(local_28), iVar5 != 0)) goto LAB_00614c28;
                  goto LAB_0061530a;
                }
                if ((local_28 == local_20) && (iVar5 = std::isfinite(local_28), iVar5 != 0)) {
                  fVar12 = (long double)1;
                  local_18 = local_28;
                  goto LAB_00614c61;
                }
LAB_00614cdf:
                local_38 = -1.5707963705062866;
                fVar12 = (long double)1.5707963705062866;
              }
              goto LAB_00615307;
            }
            if ((local_28 != local_20) || (iVar5 = std::isfinite(local_28), iVar5 == 0))
              goto LAB_006152fc;
            dVar13 = local_28;
LAB_006152f8:
            fVar12 = (long double)std::cos((long double)dVar13);
          }
LAB_006152ed:
          local_30 = (double)fVar12;
          local_38 = (double)fVar12;
        }
      } else if ((uVar6 & 0xf0000000) == 0x20000000) {
        if ((uVar6 & 0xfff00000) != 0x20900000) {
          iVar5 = (int)FUN_006147e4(self, *(uint32_t *)(puVar3[2] + uVar10 * 4), &local_18);
          if ((iVar5 < 0) ||
              (iVar5 = (int)FUN_006147e4(self, *(uint32_t *)(puVar3[2] + (puVar3[3] + uVar10) * 4), &local_28),
               iVar5 < 0)) goto LAB_006152a2;
          uVar6 = *puVar3 & 0xfff00000;
          if (uVar6 < 0x20400001) {
            if (uVar6 == 0x20400000) {
              local_38 = local_28 + local_18;
              fVar12 = (long double)local_20 + (long double)local_10.d;
            } else {
              if (uVar6 != 0x20000000) {
                if (uVar6 == 0x20100000) {
                  if (local_18 <= local_28) goto LAB_00614ebb;
                  goto LAB_00614ebe;
                }
                if (uVar6 == 0x20200000) {
                  if (local_18 < local_20) {
                    if (local_10.d < local_28) goto LAB_00614e09;
LAB_00614e2e:
                    local_38 = 0.0;
                    goto LAB_00615302;
                  }
                } else {
                  if (uVar6 != 0x20300000) goto LAB_0061530a;
                  if (local_28 <= local_10.d) {
                    if (local_18 < local_20) goto LAB_00614e2e;
                    goto LAB_00614e09;
                  }
                }
                goto LAB_00614c28;
              }
              if (local_28 <= local_18) {
                local_18 = local_28;
              }
              local_38 = local_18;
              if (local_20 <= local_10.d) goto LAB_0061513a;
LAB_00614ed2:
              fVar12 = (long double)local_10.d;
            }
LAB_00615307:
            local_30 = (double)fVar12;
          } else if (uVar6 == 0x20500000) {
            FUN_00614741(self, &local_38, &local_18, &local_28, (uint8_t)*puVar1);
          } else {
            if (uVar6 == 0x20600000) {
              if ((((local_18 == local_10.d) && (iVar5 = std::isfinite(local_18), iVar5 != 0)) &&
                   (local_28 == local_20)) && (iVar5 = std::isfinite(local_28), iVar5 != 0)) {
                fVar12 = (long double)local_28;
LAB_00614c61:
                fVar12 = (long double)std::atan2((long double)local_18, fVar12);
                goto LAB_006152ed;
              }
              local_38 = -3.1415927410125732;
LAB_00614f2f:
              fVar12 = (long double)3.1415927410125732;
              goto LAB_00615307;
            }
            if ((uVar6 == 0x20700000) || (uVar6 == 0x20800000)) {
              if (local_28 <= local_18) {
LAB_00614ebb:
                local_18 = local_28;
              }
LAB_00614ebe:
              local_38 = local_18;
              if (local_10.d <= local_20) goto LAB_0061513a;
              goto LAB_00614ed2;
            }
          }
        }
      } else {
        uVar9 = uVar6 & 0xfff00000;
        if (uVar9 == 0x50000000) {
          local_38 = 0.0;
          local_10.u = ((((uint64_t)uVar6 << 32) | (uint32_t)local_10.u) & 0xfffffffffffffULL);
          local_30 = 0.0;
          uVar10 = 0;
          if ((uVar6 & 0xfffff) != 0) {
            param_1 = (uVar6 & 0xfffff) << 2;
            do {
              iVar5 = (int)FUN_006147e4(self, *(uint32_t *)(puVar3[2] + uVar10 * 4), &local_28);
              if ((iVar5 < 0) ||
                  (iVar5 = (int)FUN_006147e4(self, *(uint32_t *)(param_1 + puVar3[2]), &local_48), iVar5 < 0))
                goto LAB_006152a2;
              FUN_00614741(self, &local_58, &local_28, &local_48, (uint8_t)*puVar1);
              local_38 = local_58 + local_38;
              param_1 = param_1 + 4;
              uVar10 = uVar10 + 1;
              local_30 = local_50 + local_30;
            } while (uVar10 < (uint32_t)(local_10.u >> 32));
          }
        } else {
          if (uVar9 == 0x30000000) {
            uVar6 = puVar3[2];
            iVar5 = *(int *)(uVar6 + uVar10 * 4);
            iVar2 = *(int *)(uVar6 + (uVar10 + puVar3[3] * 2) * 4);
            local_10.u = ((uint64_t)*(uint32_t *)(uVar6 + (puVar3[3] + uVar10) * 4) << 32) |
                         (uint32_t)local_10.u;
            iVar7 = (int)FUN_006147e4(self, (uint32_t)iVar5, &local_58);
            if (-1 < iVar7) {
              iVar7 = (int)FUN_006147e4(self, (uint32_t)(local_10.u >> 32), &local_28);
              if ((-1 < iVar7) && (iVar7 = (int)FUN_006147e4(self, (uint32_t)iVar2, &local_48), -1 < iVar7)) {
                if ((*puVar3 & 0xfff00000) == 0x30000000) {
                  if (iVar5 == (int)(uint32_t)(local_10.u >> 32)) {
                    if (local_28 < 0.0) {
                      local_28 = 0.0;
                    }
                    if (local_20 < 0.0) {
                      local_20 = 0.0;
                    }
                  }
                  if (iVar5 == iVar2) {
                    if (0.0 < local_48) {
                      local_48 = 0.0;
                    }
                    fVar12 = (long double)local_40;
                    if ((long double)0.0 < fVar12) {
                      fVar12 = (long double)0;
                    }
                  } else {
                    fVar12 = (long double)local_40;
                  }
                  if (0.0 <= local_58) goto LAB_006150ed;
                  if (0.0 <= local_50) {
                    if (local_48 <= local_28) {
                      local_38 = local_48;
                    } else {
                      local_38 = local_28;
                    }
                    if (fVar12 < (long double)local_20) goto LAB_0061513a;
                  } else {
                    local_38 = local_48;
                  }
                  goto LAB_00615307;
                }
                goto LAB_0061530a;
              }
            }
            goto LAB_006152a2;
          }
          if (uVar9 == 0x50100000) {
            if (uVar10 != 0) {
              if (uVar10 == 1) {
                iVar5 = (int)FUN_006147e4(self, *(uint32_t *)puVar3[2], &local_48);
                if (iVar5 < 0) goto LAB_006152a2;
                if (local_48 <= 0.0) {
                  local_38 = 0.0;
                  if (!std::isnan(local_40) && (local_40 < 0.0) != (local_40 == 0.0)) goto LAB_0061527e;
                } else {
                  local_38 = local_48;
                }
                fVar12 = (long double)local_40;
                goto LAB_00615307;
              }
              if (uVar10 == 2) {
                iVar5 = (int)FUN_006147e4(self, *(uint32_t *)puVar3[2], &local_48);
                if (-1 < iVar5) {
                  if (!std::isnan(local_40) && (local_40 < 0.0) != (local_40 == 0.0)) {
LAB_00614c28:
                    local_38 = 0.0;
LAB_0061527e:
                    fVar12 = (long double)0;
                    goto LAB_00615307;
                  }
                  iVar5 = (int)FUN_006147e4(self, *(uint32_t *)(puVar3[2] + 4), &local_28);
                  if (-1 < iVar5) {
                    if (!std::isnan(local_20) && (local_20 < 0.0) != (local_20 == 0.0)) goto LAB_00614c28;
                    iVar5 = (int)FUN_006147e4(self, *(uint32_t *)(puVar3[2] + 0xc), &local_58);
                    if (-1 < iVar5) {
                      fVar12 = (long double)std::pow(2.0, local_48);
                      if (1.0 <= local_20) {
                        local_58 = local_50;
                      }
                      local_10.d = local_58;
                      goto LAB_0061522c;
                    }
                  }
                }
LAB_006152a2:
                local_38 = *(double *)(local_8 + 0xa8);
                uVar11 = 0x80004005;
                local_30 = *(double *)(local_8 + 0xa0);
                goto LAB_0061530c;
              }
              if (uVar10 != 3) goto LAB_0061530a;
            }
LAB_00614e09:
            local_38 = 1.0;
LAB_00615302:
            fVar12 = (long double)1;
            goto LAB_00615307;
          }
          if (uVar9 == 0x50300000) {
            iVar5 = (int)FUN_006147e4(self, *(uint32_t *)puVar3[2], &local_48);
            if (iVar5 < 0) goto LAB_006152a2;
            if ((local_48 != local_40) || (iVar5 = std::isfinite(local_48), iVar5 == 0))
              goto LAB_006152fc;
            if (uVar10 == 0) {
              dVar13 = local_48;
              goto LAB_006152f8;
            }
            if (uVar10 == 1) {
              dVar13 = local_48;
              goto LAB_006152eb;
            }
          }
        }
      }
    }
  } else {
    iVar5 = FUN_00616086(puVar1[2], &local_20);
    if (-1 < iVar5) {
      iVar5 = (int)local_20;
      uVar6 = *(uint32_t *)(*(int *)(self + 8) + 8);
      param_1 = 0;
      local_10.u = ((uint64_t)uVar6 << 32) | (uint32_t)local_10.u;
      if (uVar6 != 0) {
        piVar8 = *(int **)(*(int *)(self + 8) + 0x14);
        do {
          iVar2 = *piVar8;
          if ((((*(uint32_t *)(iVar2 + 4) == puVar1[1]) && (*(int *)(iVar2 + 8) == -1)) &&
               (*(int *)(iVar2 + 0xc) == iVar5 + (int)puVar1[3])) &&
              (*(uint32_t *)(iVar2 + 0x10) == puVar1[4])) {
            iVar5 = (int)FUN_006147e4(self, param_1, &local_38);
            if (iVar5 < 0) goto LAB_006152a2;
            break;
          }
          param_1 = param_1 + 1;
          piVar8 = piVar8 + 1;
        } while (param_1 < uVar6);
      }
    }
  }
LAB_0061530a:
  uVar11 = 0;
LAB_0061530c:
  if ((*puVar1 & 4) == 0) {
    if (0.0 <= local_38) {
      *puVar1 = *puVar1 | 4;
    }
  } else {
    if (0.0 > local_38 || local_38 == 0.0) {
      local_38 = 0.0;
    }
    if (local_30 <= 0.0) {
      local_30 = 0.0;
    }
  }
  if ((*puVar1 & 8) == 0) {
    if (!std::isnan(local_30) && (local_30 < 0.0) != (local_30 == 0.0)) {
      *puVar1 = *puVar1 | 8;
    }
  } else {
    if (0.0 <= local_38) {
      local_38 = 0.0;
    }
    if (0.0 <= local_30) {
      local_30 = 0.0;
    }
  }
  if ((*puVar1 & 0x10) == 0) {
    if ((-1.0 <= local_38) && (!std::isnan(local_30) && (local_30 < 1.0) != (local_30 == 1.0))) {
      *puVar1 = *puVar1 | 0x10;
    }
  } else {
    if (-1.0 > local_38 || local_38 == -1.0) {
      local_38 = -1.0;
    }
    if (local_30 <= -1.0) {
      local_30 = -1.0;
    }
    if (1.0 <= local_38) {
      local_38 = 1.0;
    }
    if (1.0 <= local_30) {
      local_30 = 1.0;
    }
  }
  if ((local_38 == local_30) && (iVar5 = std::isfinite(local_38), iVar5 != 0)) {
    *(uint8_t *)puVar1 = (uint8_t)*puVar1 | 0x80;
    if ((local_38 == 0.0) || (local_38 == 1.0)) {
      *puVar1 = *puVar1 | 1;
    }
    iVar5 = (int)local_38;
    if (std::fabs(local_38 - (double)iVar5) < 1e-06) {
      *puVar1 = *puVar1 | 2;
    }
  }
  *(double *)(puVar1 + 8) = local_38;
  *(uint8_t *)((intptr_t)puVar1 + 1) = *(uint8_t *)((intptr_t)puVar1 + 1) | 1;
  *(double *)(puVar1 + 10) = local_30;
  if (param_2 != (double *)0) {
    *param_2 = local_38;
    param_2[1] = local_30;
  }
  return uVar11;
}
