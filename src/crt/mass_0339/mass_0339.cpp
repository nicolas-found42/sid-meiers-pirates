// Reconstruction batch mass_0339 — Sid Meier's Pirates! (2004), PE32 i386.
// Provider: Ghidra 12.2 pseudocode (provider-specific; not original source).
// Every definition below preserves the observed offsets, constants, call order,
// return shape and conditional structure of its assigned corpus listing.

#include <cstdint>
#include <cstddef>
#include <windows.h>

typedef int32_t (*Vfn)(...);

extern int32_t FUN_006959c5(...);
extern int32_t FUN_006959fc(...);
extern int32_t FUN_0065db7d(...);
extern void    FUN_0065dd0b(...);
extern void    FUN_006626da(...);
extern int32_t FUN_00610ba0(...);
extern int32_t FUN_0061273f(...);
extern int32_t FUN_0065d9d5(...);
extern int32_t FUN_0065d5bd(...);
extern int32_t FUN_0065da35(...);
extern int32_t FUN_0065cc50(...);
extern int32_t FUN_0065db2e(...);
extern void    FUN_00614343(...);
extern int32_t FUN_0069cac0(...);
extern int32_t FUN_0069927f(...);
extern int32_t FUN_0069ea9a(...);
extern void    FUN_0066275f(...);
extern int32_t FUN_006949cb(...);
extern int32_t FUN_00694b7c(...);
extern int32_t FUN_0065d0b4(...);
extern int32_t FUN_0065cc1a(...);
extern int32_t FUN_0065d0ff(...);
extern int32_t FUN_0069c1ed(...);
extern int32_t FUN_0065d35e(...);
extern int32_t FUN_0065d97c(...);
extern int32_t FUN_0069c7d0(...);
extern int32_t FUN_0069dfba(...);
extern void    FUN_0069ced3(...);
extern int32_t FUN_0069d0e1(...);
extern int32_t FUN_00664b28(...);
extern int32_t FUN_0069f138(...);
extern void    FUN_0065c125(...);
extern int32_t FUN_0066b20f(...);
extern int32_t FUN_0065c17a(...);
extern int32_t FUN_0065c2b3(...);
extern int32_t FUN_0065c2bf(...);
extern void    FUN_0065c142(...);
extern int32_t FUN_006a0134(...);
extern void*   FUN_00533c78(...);
extern int32_t FUN_0069e83f(...);
extern int32_t FUN_0065d501(...);
extern int32_t FUN_006a49e3(...);
extern void    operator_delete(void*);
extern void*   memmove(void*, const void*, size_t);

extern uint8_t DAT_006f1740[];
extern uint8_t DAT_006f174c[];
extern uint8_t DAT_006f1758[];
extern uint8_t DAT_006f17a0[];
extern uint8_t DAT_006f17ac[];
extern uint8_t DAT_006f17b8[];
extern uint8_t DAT_006f1800[];
extern uint8_t DAT_006f1860[];
extern uint8_t DAT_006f18c0[];
extern uint8_t DAT_006f1920[];
extern uint8_t DAT_006c3b94[];
extern uint8_t DAT_006d1990[];
extern uint8_t DAT_006e0440[];

// 0x6a0290 — observed shape
uint32_t FUN_006a0290(void* selfv, uint16_t* param_1, int32_t param_2)
{
  int32_t* self = (int32_t*)selfv;
  uint8_t* p1 = (uint8_t*)param_1;
  int16_t* psVar1;
  int16_t sVar2;
  uint32_t uVar3;
  int16_t* psVar4;
  int32_t iVar5;
  uint32_t uVar6;
  uint8_t local_20c[512];
  int32_t local_c;
  uint32_t local_8;

  local_8 = 0;
  if (*(int32_t*)(p1 + 0x68) == 0) {
    *(uint8_t*)(p1 + 3) = *(uint8_t*)(p1 + 3) | 0x40;
    uVar3 = (*(Vfn*)((intptr_t)*self + 0x50))(0, 0);
    *(uint32_t*)(p1 + 0x6c) = uVar3;
    return 0;
  }
  local_c = *(int32_t*)((intptr_t)self[4] + *(int32_t*)(p1 + 4) * 4);
  psVar1 = *(int16_t**)(*(int32_t*)(p1 + 0x68) + 0x18);
  if (*(int32_t*)((uint8_t*)self + 0x158) != 0) {
    psVar4 = psVar1;
    do {
      sVar2 = *psVar4;
      psVar4 = (int16_t*)((uint8_t*)psVar4 + 1);
    } while ((char)sVar2 != '\0');
    if ((2 < (uint32_t)((intptr_t)psVar4 - (intptr_t)((uint8_t*)psVar1 + 1))) &&
        (*psVar1 == 0x5f72)) {
      uVar6 = *(uint32_t*)(p1 + 0x70);
      if (4 < uVar6) {
        FUN_006626da();
      }
      local_8 = (uint32_t)(4 < uVar6);
      iVar5 = FUN_00610ba0(psVar1);
      if (iVar5 == 0) {
        uVar6 = FUN_0061273f(psVar1, *(int32_t*)((uint8_t*)self + 0x1d0), 1);
        if ((int32_t)uVar6 < 0) {
          return uVar6;
        }
        iVar5 = *(int32_t*)((uint8_t*)self + 0x1d0);
        *(int32_t*)((uint8_t*)self + 0x1d0) = iVar5 + 1;
      }
      else {
        iVar5 = *(int32_t*)(iVar5 + 4);
      }
      uVar3 = (*(Vfn*)((intptr_t)*self + 0x50))(0xffff, iVar5);
      *(uint32_t*)(p1 + 0x6c) = uVar3;
      goto LAB_006a037c;
    }
  }
  if (((*(int32_t*)(p1 + 0x6c) == -1) || ((*(uint8_t*)(p1 + 3) & 0x40) == 0)) ||
      (param_2 != 0)) {
    uVar6 = *(uint32_t*)(local_c + 4);
    if ((*(uint8_t*)((uint8_t*)self + 0x1c) & 0x40) == 0) {
      if (((uVar6 & 0x10) != 0) && ((uVar6 & 0x200) == 0)) {
        uVar6 = FUN_006959fc(param_1, self[0x3d], 1, &local_8);
        if ((int32_t)uVar6 < 0) {
          return uVar6;
        }
        if ((self[10] == 2) &&
            (iVar5 = (*(Vfn*)((intptr_t)*self + 0x54))(*(uint32_t*)(p1 + 0x6c)),
             iVar5 == 0xb)) {
          *(uint16_t*)p1 = *(uint16_t*)p1 | 0x114;
          param_1[0x10] = 0;
          param_1[0x11] = 0;
          param_1[0x12] = 0;
          param_1[0x13] = 0;
          param_1[0x14] = 0;
          param_1[0x15] = 0;
          param_1[0x16] = 0;
          param_1[0x17] = 0x3ff0;
        }
        goto LAB_006a037c;
      }
      if ((uVar6 & 0x20) == 0) goto LAB_006a037c;
      uVar3 = 1;
      iVar5 = self[0x3e];
    }
    else {
      if (((uVar6 & 0x10) != 0) && ((uVar6 & 0x200) == 0)) {
        uVar6 = FUN_006959fc(param_1, self[0x3c], 2, &local_8);
        if ((int32_t)uVar6 < 0) {
          return uVar6;
        }
        if ((*(int32_t*)(p1 + 0x6c) != 10) || (*(int32_t*)(p1 + 0x10) != 0)) goto LAB_006a037c;
        FUN_0065db7d(param_1);
        goto LAB_006a03c4;
      }
      if ((uVar6 & 0x20) == 0) goto LAB_006a037c;
      uVar3 = 2;
      iVar5 = self[0x3d];
    }
    uVar6 = FUN_006959fc(param_1, iVar5, uVar3, &local_8);
    if ((int32_t)uVar6 < 0) {
      return uVar6;
    }
  }
  else {
    FUN_0065dd0b(param_1, local_20c, 0x200);
LAB_006a03c4:
    FUN_006626da();
    local_8 = 1;
  }
LAB_006a037c:
  return -(uint32_t)(local_8 != 0) & 0x80004005;
}

// 0x6a04c4 — observed shape
int32_t FUN_006a04c4(void* selfv)
{
  int32_t* self = (int32_t*)selfv;
  uint32_t uVar1;
  uint32_t uVar2;
  int32_t iVar3;
  int32_t iVar4;
  uint32_t uVar5;
  int32_t iVar6;
  int32_t* piVar7;
  uint32_t* puVar8;
  uint32_t uVar9;
  uint32_t local_68[8];
  uint32_t local_48;
  uint32_t* local_44;
  int32_t local_40;
  int32_t local_3c;
  uint32_t* local_38;
  int32_t local_34;
  int32_t local_30;
  uint32_t local_2c;
  int32_t local_28;
  int32_t local_24;
  uint32_t local_20;
  uint32_t local_1c;
  uint32_t local_18;
  int32_t* local_14;
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;

  iVar3 = FUN_006959c5();
  if (-1 < iVar3) {
    iVar3 = self[2];
    local_10 = 0;
    if (iVar3 != 0) {
      piVar7 = (int32_t*)(intptr_t)self[5];
      do {
        if ((self[0x22] == *(int32_t*)((intptr_t)*piVar7 + 4)) &&
            (uVar9 = *(uint32_t*)((intptr_t)*piVar7 + 0xc), local_10 <= uVar9)) {
          local_10 = uVar9 + 1;
        }
        piVar7 = piVar7 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    local_48 = self[3];
    local_20 = 0;
    if (local_48 != 0) {
      do {
        puVar8 = *(uint32_t**)((intptr_t)self[6] + local_20 * 4);
        if ((*puVar8 & 0xfff00000) != 0) {
          local_c = *puVar8 & 0xfffff;
          local_2c = puVar8[1] / local_c;
          iVar3 = *(int32_t*)((intptr_t)self[5] +
                              *(int32_t*)(intptr_t)puVar8[4] * 4);
          local_24 = *(int32_t*)(iVar3 + 0x14);
          local_28 = *(int32_t*)(iVar3 + 0x18);
          local_44 = puVar8;
          while ((iVar3 = (*(Vfn*)((intptr_t)*self + 0x20))(puVar8, &local_1c), iVar3 != 0 &&
                 ((*puVar8 & 0xfff00000) != 0x74100000))) {
            local_34 = *(int32_t*)((intptr_t)self[4] +
                                   (*(int32_t*)((intptr_t)self[5] +
                                                *(int32_t*)((intptr_t)puVar8[2] +
                                                            local_1c * local_c * 4) * 4) + 4) * 4);
            if ((*(uint8_t*)(local_34 + 4) & 2) != 0) {
LAB_006a0944:
              FUN_006626da();
              return -0x7fffbffb;
            }
            local_18 = 0;
            local_8 = 0;
            if (local_2c != 0) {
              local_14 = (int32_t*)0x0;
              do {
                iVar3 = *(int32_t*)((intptr_t)self[4] +
                                    (*(int32_t*)((intptr_t)self[5] +
                                                 *(int32_t*)((intptr_t)local_14 +
                                                             puVar8[2]) * 4) + 4) * 4);
                iVar4 = (*(Vfn*)((intptr_t)*self + 0x9c))(puVar8);
                if ((((iVar4 != 1) && (uVar9 = *(uint32_t*)(iVar3 + 4), (uVar9 & 0x40) != 0)) &&
                     (((*(uint32_t*)(local_34 + 4) ^ uVar9) & 0x12bf) == 0)) && (local_c != 0)) {
                  piVar7 = local_14;
                  uVar9 = local_c;
                  do {
                    uVar1 = *(uint32_t*)(*(int32_t*)((intptr_t)self[5] +
                                                     *(int32_t*)((intptr_t)piVar7 +
                                                                 puVar8[2]) * 4) + 0x5c);
                    if (local_18 < uVar1) {
                      local_1c = local_8;
                      local_18 = uVar1;
                    }
                    piVar7 = (int32_t*)((intptr_t)piVar7 + 4);
                    uVar9 = uVar9 - 1;
                  } while (uVar9 != 0);
                }
                local_8 = local_8 + 1;
                local_14 = (int32_t*)((intptr_t)local_14 + local_c * 4);
              } while (local_8 < local_2c);
            }
            iVar3 = *(int32_t*)((intptr_t)self[5] +
                                *(int32_t*)((intptr_t)puVar8[2] +
                                            local_1c * local_c * 4) * 4);
            iVar4 = *(int32_t*)(iVar3 + 4);
            local_34 = *(int32_t*)(iVar3 + 8);
            local_3c = iVar4;
            local_30 = *(int32_t*)(iVar3 + 0xc);
            if ((*(uint8_t*)(*(int32_t*)((intptr_t)self[4] + iVar4 * 4) + 4) & 0x40) == 0)
              goto LAB_006a0944;
            local_68[0] = 0xffffffff;
            local_68[1] = 0xffffffff;
            local_68[2] = 0xffffffff;
            local_68[3] = 0xffffffff;
            local_18 = 0;
            uVar9 = 0;
            if (self[2] != 0) {
              local_14 = (int32_t*)(intptr_t)self[5];
              do {
                uVar1 = local_18;
                iVar3 = *local_14;
                if ((((*(int32_t*)(iVar3 + 4) == iVar4) &&
                     (*(int32_t*)(iVar3 + 0xc) == local_30)) &&
                    ((*(int32_t*)(iVar3 + 8) == local_34 &&
                     ((*(int32_t*)(iVar3 + 0x38) == -1 &&
                      (uVar2 = *(uint32_t*)(iVar3 + 0x58), local_20 <= uVar2)))))) &&
                   (local_68[*(int32_t*)(iVar3 + 0x10)] = uVar9, uVar1 <= uVar2)) {
                  local_18 = uVar2 + 1;
                }
                local_14 = local_14 + 1;
                uVar9 = uVar9 + 1;
              } while (uVar9 < (uint32_t)self[2]);
            }
            uVar9 = 0;
            local_14 = (int32_t*)0x0;
            local_8 = 0;
            do {
              uVar1 = local_8;
              local_38 = (uint32_t*)local_68[local_8];
              if ((uint32_t*)local_68[local_8] != (uint32_t*)0xffffffff) {
                uVar9 = FUN_0065d9d5(self[0x22], local_10, local_8, 0);
                local_68[uVar1 + 4] = uVar9;
                if (uVar9 == 0xffffffff) {
                  return -0x7ff8fff2;
                }
                iVar3 = *(int32_t*)((intptr_t)self[5] + uVar9 * 4);
                iVar4 = FUN_0065d5bd();
                if (iVar4 < 0) {
                  return iVar4;
                }
                *(uint32_t*)(iVar3 + 0x68) = 0;
                *(uint32_t*)(iVar3 + 0x6c) = 0xffffffff;
                *(uint32_t*)(iVar3 + 0x70) = 0;
                uVar9 = (int32_t)local_14 + 1;
                local_14 = (int32_t*)uVar9;
                *(int32_t*)(iVar3 + 0x14) = local_24;
                *(int32_t*)(iVar3 + 0x18) = local_28;
              }
              local_8 = local_8 + 1;
            } while (local_8 < 4);
            iVar3 = FUN_0065da35(uVar9 & 0xfffff | 0x10000000, uVar9, uVar9);
            if (iVar3 == -1) {
              return -0x7ff8fff2;
            }
            iVar3 = *(int32_t*)((intptr_t)self[6] + iVar3 * 4);
            iVar4 = FUN_0065cc50();
            if (iVar4 < 0) {
              return iVar4;
            }
            iVar4 = 0;
            local_8 = 0;
            do {
              if (*(int32_t*)((intptr_t)local_68 + local_8) != -1) {
                *(int32_t*)(iVar4 + *(int32_t*)(iVar3 + 8)) =
                    *(int32_t*)((intptr_t)local_68 + local_8);
                *(uint32_t*)(iVar4 + *(int32_t*)(iVar3 + 0x10)) =
                    *(uint32_t*)((intptr_t)local_68 + local_8 + 0x10);
                iVar4 = iVar4 + 4;
              }
              local_8 = local_8 + 4;
            } while (local_8 < 0x10);
            local_10 = local_10 + 1;
            for (local_8 = local_20; local_8 < local_18; local_8 = local_8 + 1) {
              iVar3 = *(int32_t*)((intptr_t)self[6] + local_8 * 4);
              if ((*(uint16_t*)(iVar3 + 2) & 0xfff0) != 0) {
                iVar4 = *(int32_t*)((intptr_t)self[5] +
                                    *(int32_t*)(*(int32_t*)(iVar3 + 0x10)) * 4);
                iVar6 = *(int32_t*)(iVar4 + 0x14);
                for (iVar4 = *(int32_t*)(iVar4 + 0x18);
                     (iVar6 != -1 && ((iVar6 != local_24 || (iVar4 != local_28))));
                     iVar4 = *(int32_t*)(iVar4 + 0x18)) {
                  iVar4 = *(int32_t*)((intptr_t)self[5] + iVar6 * 4);
                  iVar6 = *(int32_t*)(iVar4 + 0x14);
                }
                if ((((iVar6 == local_24) && (iVar4 == local_28)) &&
                     (iVar4 = (*(Vfn*)((intptr_t)*self + 0x20))(), iVar4 != 0)) &&
                    (local_14 = (int32_t*)0x0, *(int32_t*)(iVar3 + 4) != 0)) {
                  do {
                    iVar4 = (int32_t)local_14 * 4;
                    local_38 = (uint32_t*)(*(int32_t*)(iVar3 + 8) + iVar4);
                    local_40 = *(int32_t*)((intptr_t)self[5] + *local_38 * 4);
                    if (((*(int32_t*)(local_40 + 4) == local_3c) &&
                         (*(int32_t*)(local_40 + 0xc) == local_30)) &&
                        (*(int32_t*)(local_40 + 8) == local_34)) {
                      if (*(int32_t*)(local_40 + 0x38) == -1) {
                        *local_38 = local_68[*(int32_t*)(local_40 + 0x10) + 4];
                      }
                      else {
                        local_38 = *(uint32_t**)((intptr_t)self[5] +
                                                 local_68[*(int32_t*)(local_40 + 0x10) + 4] *
                                                     4);
                        uVar5 = FUN_0065d9d5(self[0x22], local_38[3], local_38[4], 0);
                        *(uint32_t*)(iVar4 + *(int32_t*)(iVar3 + 8)) = uVar5;
                        if (*(int32_t*)(iVar4 + *(int32_t*)(iVar3 + 8)) == -1) {
                          return -0x7ff8fff2;
                        }
                        iVar4 = *(int32_t*)((intptr_t)self[5] +
                                            *(int32_t*)(iVar4 +
                                                        *(int32_t*)(iVar3 + 8)) * 4);
                        iVar6 = FUN_0065d5bd();
                        if (iVar6 < 0) {
                          return iVar6;
                        }
                        *(uint32_t*)(iVar4 + 0x38) =
                            local_68[*(int32_t*)(local_40 + 0x10) + 4];
                        *(uint32_t*)(iVar4 + 0x3c) = *(uint32_t*)(local_40 + 0x3c);
                      }
                    }
                    local_14 = (int32_t*)((intptr_t)local_14 + 1);
                  } while ((intptr_t)local_14 < *(uint32_t*)(iVar3 + 4));
                  puVar8 = local_44;
                }
              }
            }
          }
          iVar3 = FUN_0065db2e();
          if (iVar3 < 0) {
            return iVar3;
          }
          *puVar8 = 0;
        }
        local_20 = local_20 + 1;
      } while (local_20 < local_48);
    }
    iVar3 = 0;
  }
  return iVar3;
}

// 0x6a095e — observed shape
int32_t FUN_006a095e(void* selfv)
{
  int32_t* self = (int32_t*)selfv;
  int32_t iVar1;
  int32_t iVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t* puVar5;
  int32_t* piVar6;
  char* pcVar7;
  int32_t* piVar8;
  char* pcVar9;
  bool bVar10;
  uint32_t local_64[4];
  char local_54[16];
  int32_t local_44[5];
  uint32_t local_30;
  uint32_t local_2c;
  int32_t local_28;
  int32_t local_24;
  uint32_t local_20;
  char* local_1c;
  uint32_t local_18;
  int32_t local_14;
  int32_t local_10;
  uint32_t local_c;
  uint32_t* local_8;

  iVar1 = FUN_006959c5();
  if (-1 < iVar1) {
    local_c = 0;
    uVar3 = (uint32_t)self[3];
    local_2c = uVar3;
    if (uVar3 != 0) {
      do {
        puVar5 = *(uint32_t**)((intptr_t)self[6] + local_c * 4);
        if ((*puVar5 & 0xfff00000) != 0) {
          local_10 = 0;
          local_18 = *puVar5 & 0xfffff;
          local_8 = puVar5;
          iVar1 = (*(Vfn*)((intptr_t)*self + 0x20))(puVar5, &local_28);
          while ((uVar4 = local_18, iVar1 != 0 && ((*puVar5 & 0xfff00000) != 0x74100000))) {
            if ((uint32_t)self[0x53] <= local_c) {
              local_44[0] = -1;
              local_44[1] = 0xffffffff;
              local_44[2] = 0xffffffff;
              local_44[3] = 0xffffffff;
              local_54[0] = -1;
              local_54[1] = -1;
              local_54[2] = -1;
              local_54[3] = -1;
              local_54[4] = -1;
              local_54[5] = -1;
              local_54[6] = -1;
              local_54[7] = -1;
              local_54[8] = -1;
              local_54[9] = -1;
              local_54[10] = -1;
              local_54[0xb] = -1;
              local_54[0xc] = -1;
              local_54[0xd] = -1;
              local_54[0xe] = -1;
              local_54[0xf] = -1;
            }
            local_20 = (-(uint32_t)(local_18 != 1) & 0xfffffffd) + 3;
            iVar1 = local_20 * 4;
            local_1c = (char*)((intptr_t)puVar5[2] + local_28 * local_18 * 4);
            iVar2 = local_18 << 2;
            bVar10 = true;
            pcVar7 = local_1c;
            pcVar9 = local_54 + iVar1;
            do {
              if (iVar2 == 0) break;
              iVar2 = iVar2 + -1;
              bVar10 = *pcVar7 == *pcVar9;
              pcVar7 = pcVar7 + 1;
              pcVar9 = pcVar9 + 1;
            } while (bVar10);
            local_14 = iVar1;
            if ((!bVar10) ||
               ((puVar5 = local_8, local_8[3] != 0 &&
                (*(int32_t*)(*(int32_t*)((intptr_t)self[5] +
                                         *(int32_t*)(intptr_t)local_8[4] * 4) + 0x14) !=
                 -1)))) {
              iVar1 = FUN_0065da35(local_18 & 0xfffff | 0x10000000, 0xffffffff, 0xffffffff);
              if (iVar1 == -1) {
                return -0x7ff8fff2;
              }
              local_24 = *(int32_t*)((intptr_t)self[6] + iVar1 * 4);
              iVar1 = FUN_0065cc50(local_8);
              if (iVar1 < 0) {
                return iVar1;
              }
              piVar6 = (int32_t*)((intptr_t)local_44 + local_14);
              iVar2 = (*(Vfn*)((intptr_t)*self + 0x80))(local_c, piVar6, uVar4, local_64,
                                                        local_10);
              iVar1 = local_24;
              if (iVar2 < 0) {
                return iVar2;
              }
              local_44[4] = *(int32_t*)((intptr_t)self[5] + *piVar6 * 4);
              local_30 = local_20 + uVar4;
              for (; local_20 < local_30; local_20 = local_20 + 1) {
                iVar2 = *(int32_t*)((intptr_t)self[5] + local_44[local_20] * 4);
                if (local_8[3] != 0) {
                  *(uint32_t*)(iVar2 + 0x14) =
                      *(uint32_t*)(*(int32_t*)((intptr_t)self[5] +
                                               *(int32_t*)(intptr_t)local_8[4] * 4) + 0x14);
                  *(uint32_t*)(iVar2 + 0x18) =
                      *(uint32_t*)(*(int32_t*)((intptr_t)self[5] +
                                               *(int32_t*)(intptr_t)local_8[4] * 4) + 0x18);
                }
              }
              local_64[local_10] = *(uint32_t*)(local_44[4] + 0xc);
              puVar5 = local_8;
              piVar8 = *(int32_t**)(iVar1 + 0x10);
              for (uVar3 = uVar4 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
                *piVar8 = *piVar6;
                piVar6 = piVar6 + 1;
                piVar8 = piVar8 + 1;
              }
              for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
                *(char*)piVar8 = (char)*piVar6;
                piVar6 = (int32_t*)((intptr_t)piVar6 + 1);
                piVar8 = (int32_t*)((intptr_t)piVar8 + 1);
              }
              pcVar7 = local_1c;
              pcVar9 = *(char**)((intptr_t)local_24 + 8);
              for (uVar3 = uVar4 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
                *(uint32_t*)pcVar9 = *(uint32_t*)pcVar7;
                pcVar7 = pcVar7 + 4;
                pcVar9 = pcVar9 + 4;
              }
              local_10 = local_10 + 1;
              for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
                *pcVar9 = *pcVar7;
                pcVar7 = pcVar7 + 1;
                pcVar9 = pcVar9 + 1;
              }
              pcVar7 = local_1c;
              pcVar9 = local_54 + local_14;
              for (uVar4 = uVar4 & 0x3fffffff; iVar1 = local_14, uVar4 != 0; uVar4 = uVar4 - 1) {
                *(uint32_t*)pcVar9 = *(uint32_t*)pcVar7;
                pcVar7 = pcVar7 + 4;
                pcVar9 = pcVar9 + 4;
              }
              for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
                *pcVar9 = *pcVar7;
                pcVar7 = pcVar7 + 1;
                pcVar9 = pcVar9 + 1;
              }
            }
            pcVar7 = (char*)((intptr_t)local_44 + iVar1);
            pcVar9 = local_1c;
            for (uVar3 = local_18 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
              *(uint32_t*)pcVar9 = *(uint32_t*)pcVar7;
              pcVar7 = pcVar7 + 4;
              pcVar9 = pcVar9 + 4;
            }
            for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
              *pcVar9 = *pcVar7;
              pcVar7 = pcVar7 + 1;
              pcVar9 = pcVar9 + 1;
            }
            iVar1 = (*(Vfn*)((intptr_t)*self + 0x20))(puVar5, &local_28);
            puVar5 = local_8;
            uVar3 = local_2c;
          }
          iVar1 = FUN_0065db2e(puVar5);
          if (iVar1 == -1) {
            return -0x7ff8fff2;
          }
          FUN_00614343(1);
          *(uint32_t*)((intptr_t)self[6] + local_c * 4) = 0;
        }
        local_c = local_c + 1;
      } while (local_c < uVar3);
    }
    if (uVar3 < (uint32_t)self[3]) {
      iVar1 = 0;
      uVar4 = uVar3;
      do {
        *(uint32_t*)(iVar1 + (intptr_t)self[6]) =
            *(uint32_t*)((intptr_t)self[6] + uVar4 * 4);
        uVar4 = uVar4 + 1;
        iVar1 = iVar1 + 4;
      } while (uVar4 < (uint32_t)self[3]);
    }
    self[3] = self[3] - (int32_t)uVar3;
    iVar1 = 0;
  }
  return iVar1;
}

// 0x6a0bf8 — observed shape
uint32_t FUN_006a0bf8(void* selfv, int32_t* param_1, int32_t* param_2, int32_t* param_3,
                      uint32_t param_4, uint32_t param_5, uint32_t param_6)
{
  uint8_t* self = (uint8_t*)selfv;
  uint32_t* puVar1;
  int32_t iVar2;
  uint32_t uVar3;
  uint32_t* puVar4;
  uint32_t* puVar5;
  int32_t iVar6;
  int32_t iVar7;
  int32_t* piVar8;
  uint32_t uVar9;
  uint32_t uVar10;
  uint32_t uVar11;
  bool bVar12;
  uint32_t auStack_a8[4];
  uint32_t auStack_98[4];
  uint32_t auStack_88[4];
  uint32_t auStack_78[4];
  uint32_t auStack_68[4];
  int32_t local_58[4];
  int32_t local_48[4];
  int32_t local_38[4];
  int32_t local_28;
  int32_t local_24;
  uint32_t local_20;
  int32_t* local_1c;
  uint32_t local_18;
  uint32_t local_14;
  uint32_t local_10;
  int32_t* local_c;
  int32_t* local_8;

  if (param_5 == 0) {
    param_5 = *(uint32_t*)(self + 0x100);
  }
  iVar6 = (int32_t)param_5;
  piVar8 = *(int32_t**)((intptr_t)param_5 + 0x10);
  iVar7 = *(int32_t*)(self + 0x14);
  if (*(int32_t*)(self + 0x88) ==
      *(int32_t*)(*(int32_t*)(iVar7 + *piVar8 * 4) + 4)) {
    uVar10 = **(uint32_t**)(self + 0x100);
    uVar9 = (*(uint32_t**)(self + 0x100))[3];
    local_10 = 0;
    if ((uVar10 & 0xfffff) == uVar9) {
      local_8 = (int32_t*)0x0;
      if (uVar9 != 0) {
        local_14 = (uint32_t)((int32_t)param_3 - (int32_t)piVar8);
        local_c = piVar8;
        do {
          iVar7 = *(int32_t*)(iVar7 +
                              *(int32_t*)((intptr_t)((int32_t)param_3 - (int32_t)piVar8) +
                                          (intptr_t)local_c) * 4);
          local_24 = *(int32_t*)(*(int32_t*)(self + 0x10) + *(int32_t*)(iVar7 + 4) * 4);
          if (((*(int32_t*)(self + 0x6c) << 0xe < 0) &&
               ((*(uint8_t*)(iVar7 + 0x3d) & 2) != 0)) &&
              (param_1 == (int32_t*)0x80000)) {
            local_10 = 1;
          }
          if (((*(uint32_t*)(iVar7 + 0x3c) & 0x1f0000) != 0) &&
              ((~(uint32_t)param_2 & *(uint32_t*)(iVar7 + 0x3c) & 0x1f0000) != 0)) {
            if (param_1 != (int32_t*)0x80000) {
              return 1;
            }
            local_10 = 1;
          }
          iVar7 = *(int32_t*)(self + 0x14);
          if ((*(uint8_t*)(*(int32_t*)(iVar7 + *local_c * 4) + 0x3d) & 0xfe) != 0) {
            return 1;
          }
          if (((*(uint8_t*)(self + 0x6c) & 0x10) != 0) &&
              ((*(uint8_t*)(local_24 + 5) & 2) != 0)) {
            if ((uVar10 & 0xfff00000) != 0x10100000) {
              return 1;
            }
            local_10 = 1;
          }
          local_8 = (int32_t*)((intptr_t)local_8 + 1);
          local_c = local_c + 1;
        } while ((intptr_t)local_8 < *(uint32_t*)(*(int32_t*)(self + 0x100) + 0xc));
      }
      param_1 = (int32_t*)0x0;
      if (*(int32_t*)((intptr_t)param_5 + 0xc) != 0) {
        local_18 = (uint32_t)((int32_t)param_3 - (int32_t)local_38);
        do {
          bVar12 = local_10 == 0;
          iVar7 = *(int32_t*)(*(int32_t*)(self + 0x14) +
                              *(int32_t*)((int32_t)param_1 * 4 +
                                          *(int32_t*)((intptr_t)param_5 + 0x10)) * 4);
          iVar2 = *(int32_t*)(*(int32_t*)(self + 0x14) +
                              *(int32_t*)((intptr_t)(local_38 + (int32_t)param_1) +
                                          local_18) * 4);
          local_38[(int32_t)param_1] = *(int32_t*)(iVar7 + 8);
          uVar3 = *(uint32_t*)(iVar7 + 0x48);
          local_58[(int32_t)param_1] = *(int32_t*)(iVar7 + 0xc);
          local_48[(int32_t)param_1] = *(int32_t*)(iVar7 + 0x10);
          auStack_98[(int32_t)param_1] = *(uint32_t*)(iVar7 + 0x14);
          auStack_68[(int32_t)param_1] = *(uint32_t*)(iVar7 + 0x18);
          uVar10 = *(uint32_t*)(iVar7 + 0x3c);
          auStack_88[(int32_t)param_1] = uVar3;
          uVar3 = *(uint32_t*)(iVar7 + 0x68);
          auStack_78[(int32_t)param_1] = uVar10;
          auStack_a8[(int32_t)param_1] = uVar3;
          if (bVar12) {
            *(uint32_t*)(iVar7 + 4) = *(uint32_t*)(iVar2 + 4);
            *(uint32_t*)(iVar7 + 8) = *(uint32_t*)(iVar2 + 8);
            *(uint32_t*)(iVar7 + 0xc) = *(uint32_t*)(iVar2 + 0xc);
            *(uint32_t*)(iVar7 + 0x10) = *(uint32_t*)(iVar2 + 0x10);
            *(uint32_t*)(iVar7 + 0x14) = *(uint32_t*)(iVar2 + 0x14);
            *(uint32_t*)(iVar7 + 0x18) = *(uint32_t*)(iVar2 + 0x18);
            *(uint32_t*)(iVar7 + 0x48) = *(uint32_t*)(iVar2 + 0x48);
            *(uint32_t*)(iVar7 + 0x68) = *(uint32_t*)(iVar2 + 0x68);
            uVar10 = *(uint32_t*)(iVar2 + 0x3c) ^ param_4 |
                     *(uint32_t*)(iVar2 + 0x3c) & ~param_4 | uVar10;
          }
          else {
            uVar10 = uVar10 ^ param_4 | ~param_4 & uVar10;
          }
          param_1 = (int32_t*)((intptr_t)param_1 + 1);
          *(uint32_t*)(iVar7 + 0x3c) = uVar10;
        } while (param_1 < *(uint32_t*)((intptr_t)param_5 + 0xc));
      }
      uVar10 = *(uint32_t*)((intptr_t)param_5 + 0xc);
      param_2 = (int32_t*)0x0;
      local_18 = uVar10;
      if (uVar10 != 0) {
        param_1 = *(int32_t**)((intptr_t)param_5 + 0x10);
        do {
          iVar7 = FUN_0069cac0(*param_1);
          if (iVar7 == 1) goto LAB_006a104f;
          param_2 = (int32_t*)((intptr_t)param_2 + 1);
          param_1 = param_1 + 1;
        } while (param_2 < uVar10);
      }
      local_8 = (int32_t*)0xffffffff;
      param_2 = (int32_t*)0x0;
      param_1 = (int32_t*)0xffffffff;
      if (uVar10 != 0) {
        local_28 = (int32_t)local_38 - (int32_t)param_3;
        local_20 = (uint32_t)((int32_t)local_58 - (int32_t)param_3);
        local_24 = *(int32_t*)((intptr_t)param_5 + 0x10) - (int32_t)param_3;
        local_1c = (int32_t*)((int32_t)local_48 - (int32_t)param_3);
        local_14 = local_18;
        piVar8 = param_3;
        do {
          local_c = *(int32_t**)(*(int32_t*)(self + 0x14) +
                                 *(int32_t*)(local_24 + (int32_t)piVar8) * 4);
          iVar7 = *(int32_t*)(*(int32_t*)(self + 0x14) + *piVar8 * 4);
          if (*(int32_t**)((intptr_t)local_c + 0x54) < local_8) {
            local_8 = *(int32_t**)((intptr_t)local_c + 0x54);
          }
          if (param_2 < *(int32_t**)((intptr_t)local_c + 0x58)) {
            param_2 = *(int32_t**)((intptr_t)local_c + 0x58);
          }
          if ((((*(int32_t*)(self + 0x88) == *(int32_t*)(iVar7 + 4)) &&
               (*(int32_t*)((intptr_t)local_38 + ((int32_t)piVar8 - (int32_t)param_3)) ==
                *(int32_t*)(iVar7 + 8))) &&
              (*(int32_t*)((intptr_t)local_58 + ((int32_t)piVar8 - (int32_t)param_3)) ==
               *(int32_t*)(iVar7 + 0xc))) &&
             (*(int32_t*)((intptr_t)local_48 + ((int32_t)piVar8 - (int32_t)param_3)) ==
              *(int32_t*)(iVar7 + 0x10))) {
            iVar7 = (int32_t)local_c;
          }
          if (*(int32_t**)(iVar7 + 0x50) < param_1) {
            param_1 = *(int32_t**)(iVar7 + 0x50);
          }
          piVar8 = piVar8 + 1;
          local_14 = local_14 - 1;
        } while (local_14 != 0);
      }
      if (((param_6 != 0) || (param_2 <= param_1)) ||
          ((*(uint32_t*)(self + 0x6c) & 0x10000000) != 0)) {
        if (local_10 != 0) {
          **(uint32_t**)(self + 0x100) = **(uint32_t**)(self + 0x100) & 0xfffff | 0x10000000;
          return 0;
        }
        local_c = local_8;
        if (local_8 <= param_2) {
          local_8 = (int32_t*)(*(int32_t*)(self + 0x18) + (int32_t)local_8 * 4);
          do {
            puVar4 = (uint32_t*)*local_8;
            local_10 = *puVar4;
            if (local_10 != 0) {
              uVar10 = puVar4[2];
              local_14 = 0;
              local_20 = uVar10 + puVar4[1] * 4;
              uVar9 = local_10 & 0xfffff;
              if (uVar10 < local_20) {
                do {
                  param_1 = (int32_t*)0x0;
                  param_5 = 0;
                  if (uVar9 != 0) {
                    do {
                      param_6 = 0;
                      if (*(int32_t*)(iVar6 + 0xc) != 0) {
                        piVar8 = *(int32_t**)(iVar6 + 0x10);
                        while (*piVar8 != *(int32_t*)(uVar10 + param_5 * 4)) {
                          param_6 = param_6 + 1;
                          local_1c = piVar8 + 1;
                          if (*(uint32_t*)(iVar6 + 0xc) <= param_6) goto LAB_006a0fa2;
                          piVar8 = local_1c;
                        }
                        param_1 = (int32_t*)((intptr_t)param_1 + 1);
                      }
LAB_006a0fa2:
                      param_5 = param_5 + 1;
                    } while (param_5 < uVar9);
                    if (param_1 != (int32_t*)0x0) {
                      if (((param_1 != (int32_t*)uVar9) ||
                          (uVar11 = local_10 & 0xfff00000, uVar11 == 0x70500000)) ||
                         ((uVar11 == 0x70600000 || (uVar11 == 0x70700000))))
                        goto LAB_006a104f;
                      local_14 = 1;
                    }
                  }
                  uVar10 = uVar10 + uVar9 * 4;
                } while (uVar10 < local_20);
                if (((local_14 != 0) &&
                    (((((local_10 & 0xf0000000) == 0x60000000 ||
                       (uVar10 = local_10 & 0xfff00000, uVar10 == 0x10d00000)) ||
                      (uVar10 == 0x10e00000)) || (uVar10 == 0x11000000)))) &&
                   ((*(uint8_t*)(self + 0x6e) & 0x80) == 0)) goto LAB_006a104f;
              }
            }
            local_c = (int32_t*)((intptr_t)local_c + 1);
            local_8 = local_8 + 1;
          } while (local_c <= param_2);
        }
        if (*(int32_t*)(self + 0x15c) == 0) {
          param_5 = 0;
          if (*(int32_t*)(iVar6 + 0xc) != 0) {
            do {
              puVar4 = *(uint32_t**)(*(int32_t*)(self + 0x14) +
                                     *(int32_t*)(param_5 * 4 +
                                                 *(int32_t*)(iVar6 + 0x10)) * 4);
              puVar5 = *(uint32_t**)(*(int32_t*)(self + 0x14) + param_3[param_5] * 4);
              if (puVar5[0xe] == 0xffffffff) {
                puVar4[0xe] = param_3[param_5];
              }
              else {
                puVar4[0xe] = puVar5[0xe];
              }
              uVar10 = *puVar5;
              *puVar4 = uVar10;
              if (param_4 == 0x80000) {
                if ((uVar10 & 4) != 0) {
                  *puVar4 = uVar10 & 0xfffffffb | 8;
                  goto LAB_006a110c;
                }
              }
              else {
LAB_006a110c:
                if (param_4 == 0x100000) {
                  *puVar4 = *puVar4 | 4;
                }
              }
              FUN_0065d5bd(puVar5);
              param_5 = param_5 + 1;
            } while (param_5 < *(uint32_t*)(iVar6 + 0xc));
          }
          **(uint32_t**)(self + 0x100) = 0;
          return 0;
        }
        *(int32_t*)(self + 0x15c) = 2;
      }
LAB_006a104f:
      uVar10 = 0;
      if (*(int32_t*)(iVar6 + 0xc) != 0) {
        do {
          iVar7 = *(int32_t*)(*(int32_t*)(self + 0x14) +
                              *(int32_t*)(uVar10 * 4 + *(int32_t*)(iVar6 + 0x10)) * 4);
          *(uint32_t*)(iVar7 + 4) = *(uint32_t*)(self + 0x88);
          *(int32_t*)(iVar7 + 8) = local_38[uVar10];
          *(int32_t*)(iVar7 + 0xc) = local_58[uVar10];
          *(int32_t*)(iVar7 + 0x10) = local_48[uVar10];
          *(uint32_t*)(iVar7 + 0x14) = auStack_98[uVar10];
          *(uint32_t*)(iVar7 + 0x18) = auStack_68[uVar10];
          *(uint32_t*)(iVar7 + 0x3c) = auStack_78[uVar10];
          puVar1 = auStack_88 + uVar10;
          uVar3 = auStack_a8[uVar10];
          uVar10 = uVar10 + 1;
          *(uint32_t*)(iVar7 + 0x48) = *puVar1;
          *(uint32_t*)(iVar7 + 0x68) = uVar3;
        } while (uVar10 < *(uint32_t*)(iVar6 + 0xc));
      }
    }
  }
  return 1;
}

// 0x6a114f — observed shape
void FUN_006a114f(void* selfv, uint32_t param_1)
{
  uint8_t* self = (uint8_t*)selfv;
  int32_t iVar1;

  *(uint32_t*)(self + 0x15c) = 0;
  iVar1 = FUN_006a0bf8(self, (int32_t*)0x80000, (int32_t*)0xe0000,
                       (int32_t*)(intptr_t)*(uint32_t*)(*(int32_t*)(self + 0x100) + 8),
                       0x80000, 0, param_1);
  if (-1 < iVar1) {
    FUN_0069927f();
  }
  return;
}

// 0x6a118f — observed shape
int32_t FUN_006a118f(void* selfv)
{
  uint8_t* self = (uint8_t*)selfv;
  int32_t iVar1;
  int32_t* piVar2;
  uint32_t local_8;

  iVar1 = *(int32_t*)(self + 0x100);
  local_8 = 0;
  if (*(int32_t*)(iVar1 + 4) != 0) {
    piVar2 = *(int32_t**)(iVar1 + 8);
    do {
      if ((*(uint8_t*)(*(int32_t*)(*(int32_t*)(self + 0x10) +
                                   *(int32_t*)(*(int32_t*)(*(int32_t*)(self + 0x14) +
                                                          *piVar2 * 4) + 4) * 4) + 5) & 2) != 0) {
        return 1;
      }
      local_8 = local_8 + 1;
      piVar2 = piVar2 + 1;
    } while (local_8 < *(uint32_t*)(*(int32_t*)(self + 0x100) + 4));
  }
  *(uint32_t*)(self + 0x15c) = 0;
  iVar1 = FUN_006a0bf8(self, (int32_t*)0x100000, (int32_t*)0x0,
                       (int32_t*)(intptr_t)*(uint32_t*)(iVar1 + 8), 0x100000, 0, 0);
  if (-1 < iVar1) {
    iVar1 = FUN_0069927f();
  }
  return iVar1;
}

// 0x6a1209 — observed shape
int32_t FUN_006a1209(void* selfv, int32_t param_1)
{
  uint8_t* self = (uint8_t*)selfv;
  bool bVar1;
  uint32_t* puVar2;
  uint32_t* puVar3;
  int32_t* piVar4;
  int32_t iVar5;
  int32_t iVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  uint32_t* puVar10;
  int32_t local_2c8[40];
  int32_t local_228[40];
  int32_t local_188[40];
  uint32_t local_e8[16];
  uint32_t local_a8[16];
  uint8_t local_68[16];
  int32_t local_58;
  uint32_t local_54[5];
  int32_t local_40;
  uint32_t local_3c;
  int32_t local_38;
  uint32_t local_34;
  uint32_t* local_30;
  uint32_t local_2c;
  uint32_t local_28;
  uint32_t* local_24;
  uint32_t* local_20;
  uint32_t* local_1c;
  uint32_t local_18;
  uint32_t local_14;
  uint32_t* local_10;
  uint32_t* local_c;
  int32_t local_8;

  local_c = *(uint32_t**)(self + 0x100);
  local_28 = *local_c & 0xfffff;
  local_58 = 0;
  local_30 = (uint32_t*)0x0;
  local_54[0] = 0;
  local_54[1] = 1;
  local_54[2] = 2;
  local_54[3] = 3;
  local_40 = 0;
  local_34 = *local_c & 0xfffff;
  if ((local_28 <= (*local_c & 0xfffff)) && ((*local_c & 0xfff00000) == 0x20400000)) {
    local_38 = 0;
LAB_006a1277:
    local_14 = 0;
    do {
      piVar4 = local_228;
      for (iVar6 = 0x28; iVar6 != 0; iVar6 = iVar6 + -1) {
        *piVar4 = -1;
        piVar4 = piVar4 + 1;
      }
      piVar4 = local_2c8;
      for (iVar6 = 0x28; iVar6 != 0; iVar6 = iVar6 + -1) {
        *piVar4 = -1;
        piVar4 = piVar4 + 1;
      }
      local_20 = (uint32_t*)0x0;
      local_8 = 0;
      local_18 = 0;
      local_1c = (uint32_t*)0x0;
      do {
        if (local_14 == 0) {
          uVar9 = local_18;
        }
        else {
          uVar9 = 1 - local_18;
        }
        uVar7 = local_c[2];
        uVar9 = *(uint32_t*)(DAT_006f174c + uVar9 * 4);
        piVar4 = (int32_t*)((intptr_t)uVar7 + (int32_t)local_1c * 4);
        if (uVar9 < 0x10) {
          iVar6 = *(int32_t*)(*(int32_t*)(*(int32_t*)(self + 0x14) + *piVar4 * 4) + 0x48);
          if (iVar6 != -1) {
            local_2c = *(uint32_t*)(*(int32_t*)(self + 0x18) + iVar6 * 4);
            iVar6 = FUN_006949cb(local_2c, piVar4, local_28, local_54, local_68,
                                 *(uint32_t*)(DAT_006f1758 + uVar9 * 0x20), 0);
            if (iVar6 == 0) {
              local_8 = FUN_00694b7c(local_2c, (int32_t*)(DAT_006f1740 + uVar9 * 0x20),
                                     local_a8, &local_20, local_2c8, local_68, local_34, 0);
              goto LAB_006a1378;
            }
          }
          local_8 = 1;
          break;
        }
        uVar8 = 0;
        piVar4 = local_228 + (uVar9 - 0x10) * 4;
        do {
          if (local_54[uVar8] < local_28) {
            *piVar4 = *(int32_t*)((intptr_t)uVar7 + ((int32_t)local_1c + local_54[uVar8]) * 4);
          }
          else {
            *piVar4 = -1;
          }
          uVar8 = uVar8 + 1;
          piVar4 = piVar4 + 1;
        } while (uVar8 < 4);
LAB_006a1378:
        if (local_8 == 1) break;
        local_18 = local_18 + 1;
        local_1c = (uint32_t*)((intptr_t)local_1c + local_28);
      } while (local_18 < 2);
      puVar2 = local_20;
      local_18 = 0;
      local_10 = (uint32_t*)0x0;
      do {
        if (local_14 == 0) {
          uVar9 = local_18;
        }
        else {
          uVar9 = 1 - local_18;
        }
        if ((0xf < *(uint32_t*)(DAT_006f174c + uVar9 * 4)) &&
           (local_24 = (uint32_t*)0x0, local_20 != (uint32_t*)0x0)) {
          do {
            uVar9 = 0;
            if (local_28 != 0) {
              uVar7 = local_a8[(int32_t)local_24];
              puVar10 = *(uint32_t**)((intptr_t)uVar7 + 0xc);
              do {
                local_1c = (uint32_t*)0x0;
                if (puVar10 != (uint32_t*)0x0) {
                  piVar4 = *(int32_t**)((intptr_t)uVar7 + 0x10);
                  do {
                    if (*(int32_t*)((intptr_t)local_c[2] +
                                    ((int32_t)local_10 + uVar9) * 4) == *piVar4) {
                      local_8 = 1;
                      goto LAB_006a1418;
                    }
                    local_1c = (uint32_t*)((intptr_t)local_1c + 1);
                    puVar10 = *(uint32_t**)((intptr_t)uVar7 + 0xc);
                    piVar4 = piVar4 + 1;
                  } while (local_1c < puVar10);
                }
                uVar9 = uVar9 + 1;
              } while (uVar9 < local_28);
            }
LAB_006a1418:
            local_24 = (uint32_t*)((intptr_t)local_24 + 1);
          } while (local_24 < local_20);
        }
        local_18 = local_18 + 1;
        local_10 = (uint32_t*)((intptr_t)local_10 + local_28);
      } while (local_18 < 2);
      if (local_8 == 0) {
        if (local_38 != 0) goto LAB_006a15c1;
        local_24 = (uint32_t*)0x0;
        if (local_20 != (uint32_t*)0x0) {
          do {
            local_3c = *(uint32_t*)((intptr_t)local_a8[(int32_t)local_24] + 0xc);
            local_1c = (uint32_t*)0x0;
            if (local_3c != 0) {
              do {
                if (*(int32_t*)(self + 0xc) != 0) {
                  local_10 = *(uint32_t**)(self + 0x18);
                  local_2c = *(uint32_t*)(self + 0xc);
                  do {
                    puVar10 = (uint32_t*)*local_10;
                    if ((puVar10 != (uint32_t*)0x0) && (*puVar10 != 0)) {
                      local_18 = 0;
                      if (puVar10[1] != 0) {
                        iVar6 = *(int32_t*)(*(int32_t*)((intptr_t)local_a8[(int32_t)local_24] +
                                                        0x10) +
                                            (int32_t)local_1c * 4);
                        piVar4 = (int32_t*)(intptr_t)puVar10[2];
                        local_54[4] = puVar10[1];
                        do {
                          if ((*piVar4 == iVar6) ||
                             (*(int32_t*)(*(int32_t*)(*(int32_t*)(self + 0x14) +
                                                      *piVar4 * 4) + 0x38) == iVar6)) {
                            local_18 = 1;
                          }
                          piVar4 = piVar4 + 1;
                          local_54[4] = local_54[4] - 1;
                        } while (local_54[4] != 0);
                      }
                      if (puVar10 == local_c) {
                        local_18 = 0;
                      }
                      if (local_18 != 0) {
                        puVar3 = (uint32_t*)0x0;
                        do {
                          if (puVar10 == (uint32_t*)(intptr_t)local_a8[(int32_t)puVar3]) {
                            local_18 = 0;
                          }
                          puVar3 = (uint32_t*)((intptr_t)puVar3 + 1);
                        } while (puVar3 < local_20);
                        if (local_18 != 0) {
                          local_8 = 1;
                        }
                      }
                    }
                    local_10 = local_10 + 1;
                    local_2c = local_2c - 1;
                  } while (local_2c != 0);
                }
                local_1c = (uint32_t*)((intptr_t)local_1c + 1);
              } while (local_1c < local_3c);
            }
            local_24 = (uint32_t*)((intptr_t)local_24 + 1);
          } while (local_24 < local_20);
        }
        local_1c = (uint32_t*)0x0;
        do {
          iVar6 = local_228[(int32_t)local_1c];
          if ((iVar6 != -1) && (puVar10 = (uint32_t*)0x0, local_20 != (uint32_t*)0x0)) {
            local_3c = *(uint32_t*)(*(int32_t*)(self + 0x14) + iVar6 * 4);
            do {
              uVar9 = *(uint32_t*)((intptr_t)local_a8[(int32_t)puVar10] + 0xc);
              if (uVar9 != 0) {
                piVar4 = *(int32_t**)((intptr_t)local_a8[(int32_t)puVar10] + 0x10);
                local_2c = uVar9;
                do {
                  if ((iVar6 == *piVar4) || (*(int32_t*)(local_3c + 0x38) == *piVar4)) {
                    local_8 = 1;
                  }
                  piVar4 = piVar4 + 1;
                  local_2c = local_2c - 1;
                } while (local_2c != 0);
              }
              puVar10 = (uint32_t*)((intptr_t)puVar10 + 1);
            } while (puVar10 < local_20);
          }
          local_1c = (uint32_t*)((intptr_t)local_1c + 1);
        } while (local_1c < (uint32_t*)0x28);
        if (local_8 == 0) goto LAB_006a15c1;
      }
      local_14 = local_14 + 1;
    } while (local_14 < 2);
    if (local_8 != 0) goto code_r0x006a15b2;
LAB_006a15c1:
    puVar10 = local_a8;
    puVar3 = local_e8;
    for (uVar9 = (uint32_t)(intptr_t)local_20 & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
      *puVar3 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar3 = puVar3 + 1;
    }
    for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(char*)puVar3 = (char)*puVar10;
      puVar10 = (uint32_t*)((intptr_t)puVar10 + 1);
      puVar3 = (uint32_t*)((intptr_t)puVar3 + 1);
    }
    local_e8[(int32_t)(intptr_t)puVar2] = (uint32_t)(intptr_t)local_c;
    local_30 = (uint32_t*)((intptr_t)local_20 + 1);
    uVar9 = 0;
    do {
      iVar6 = *(int32_t*)((intptr_t)local_228 + uVar9);
      if ((iVar6 != -1) || (iVar6 = *(int32_t*)((intptr_t)local_2c8 + uVar9), iVar6 != -1)) {
        *(int32_t*)((intptr_t)local_188 + uVar9) = iVar6;
      }
      uVar9 = uVar9 + 4;
    } while (uVar9 < 0xa0);
    local_8 = 0;
LAB_006a1623:
    if (local_8 != 0) goto LAB_006a1635;
    goto LAB_006a1d7d;
  }
LAB_006a1635:
  local_1c = *(uint32_t**)(self + 0x100);
  uVar9 = **(uint32_t**)(self + 0x100);
  local_28 = uVar9 & 0xfffff;
  if ((local_28 <= local_34) && ((uVar9 & 0xfff00000) == 0x20400000)) {
    local_38 = 0;
LAB_006a1665:
    local_18 = 0;
    do {
      puVar2 = local_30;
      puVar10 = local_e8;
      puVar3 = local_a8;
      for (uVar9 = (uint32_t)(intptr_t)local_30 & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
        *puVar3 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar3 = puVar3 + 1;
      }
      for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
        *(char*)puVar3 = (char)*puVar10;
        puVar10 = (uint32_t*)((intptr_t)puVar10 + 1);
        puVar3 = (uint32_t*)((intptr_t)puVar3 + 1);
      }
      piVar4 = local_228;
      for (iVar6 = 0x28; iVar6 != 0; iVar6 = iVar6 + -1) {
        *piVar4 = -1;
        piVar4 = piVar4 + 1;
      }
      piVar4 = local_2c8;
      for (iVar6 = 0x28; iVar6 != 0; iVar6 = iVar6 + -1) {
        *piVar4 = -1;
        piVar4 = piVar4 + 1;
      }
      local_20 = puVar2;
      local_8 = 0;
      local_14 = 0;
      local_10 = (uint32_t*)0x0;
      do {
        if (local_18 == 0) {
          uVar9 = local_14;
        }
        else {
          uVar9 = 1 - local_14;
        }
        uVar7 = local_1c[2];
        uVar9 = *(uint32_t*)(DAT_006f17ac + uVar9 * 4);
        piVar4 = (int32_t*)((intptr_t)uVar7 + (int32_t)local_10 * 4);
        if (uVar9 < 0x10) {
          iVar6 = *(int32_t*)(*(int32_t*)(*(int32_t*)(self + 0x14) + *piVar4 * 4) + 0x48);
          if (iVar6 != -1) {
            local_3c = *(uint32_t*)(*(int32_t*)(self + 0x18) + iVar6 * 4);
            iVar6 = FUN_006949cb(local_3c, piVar4, local_28, local_54, local_68,
                                 *(uint32_t*)(DAT_006f17b8 + uVar9 * 0x20), 0);
            if (iVar6 == 0) {
              local_8 = FUN_00694b7c(local_3c, (int32_t*)(DAT_006f17a0 + uVar9 * 0x20),
                                     local_a8, &local_20, local_2c8, local_68, local_34, 0);
              goto LAB_006a177a;
            }
          }
          local_8 = 1;
          break;
        }
        uVar8 = 0;
        piVar4 = local_228 + (uVar9 - 0x10) * 4;
        do {
          if (local_54[uVar8] < local_28) {
            *piVar4 = *(int32_t*)((intptr_t)uVar7 +
                                  (local_54[uVar8] + (int32_t)local_10) * 4);
          }
          else {
            *piVar4 = -1;
          }
          uVar8 = uVar8 + 1;
          piVar4 = piVar4 + 1;
        } while (uVar8 < 4);
LAB_006a177a:
        if (local_8 == 1) break;
        local_14 = local_14 + 1;
        local_10 = (uint32_t*)((intptr_t)local_10 + local_28);
      } while (local_14 < 2);
      puVar2 = local_20;
      local_14 = 0;
      local_24 = (uint32_t*)0x0;
      do {
        if (local_18 == 0) {
          uVar9 = local_14;
        }
        else {
          uVar9 = 1 - local_14;
        }
        if ((0xf < *(uint32_t*)(DAT_006f17ac + uVar9 * 4)) &&
           (local_c = (uint32_t*)0x0, local_20 != (uint32_t*)0x0)) {
          do {
            uVar9 = 0;
            if (local_28 != 0) {
              uVar7 = local_a8[(int32_t)local_c];
              puVar10 = *(uint32_t**)((intptr_t)uVar7 + 0xc);
              do {
                local_10 = (uint32_t*)0x0;
                if (puVar10 != (uint32_t*)0x0) {
                  piVar4 = *(int32_t**)((intptr_t)uVar7 + 0x10);
                  do {
                    if (*(int32_t*)((intptr_t)local_1c[2] +
                                    ((int32_t)local_24 + uVar9) * 4) == *piVar4) {
                      local_8 = 1;
                      goto LAB_006a1815;
                    }
                    local_10 = (uint32_t*)((intptr_t)local_10 + 1);
                    puVar10 = *(uint32_t**)((intptr_t)uVar7 + 0xc);
                    piVar4 = piVar4 + 1;
                  } while (local_10 < puVar10);
                }
                uVar9 = uVar9 + 1;
              } while (uVar9 < local_28);
            }
LAB_006a1815:
            local_c = (uint32_t*)((intptr_t)local_c + 1);
          } while (local_c < local_20);
        }
        local_14 = local_14 + 1;
        local_24 = (uint32_t*)((intptr_t)local_24 + local_28);
      } while (local_14 < 2);
      if (local_8 == 0) {
        if (local_38 != 0) goto LAB_006a19c0;
        local_24 = (uint32_t*)0x0;
        if (local_20 != (uint32_t*)0x0) {
          do {
            local_3c = *(uint32_t*)((intptr_t)local_a8[(int32_t)local_24] + 0xc);
            local_c = (uint32_t*)0x0;
            if (local_3c != 0) {
              do {
                if (*(int32_t*)(self + 0xc) != 0) {
                  local_10 = *(uint32_t**)(self + 0x18);
                  local_54[4] = *(uint32_t*)(self + 0xc);
                  do {
                    puVar10 = (uint32_t*)*local_10;
                    if ((puVar10 != (uint32_t*)0x0) && (*puVar10 != 0)) {
                      local_14 = 0;
                      if (puVar10[1] != 0) {
                        iVar6 = *(int32_t*)(*(int32_t*)((intptr_t)local_a8[(int32_t)local_24] +
                                                        0x10) +
                                            (int32_t)local_c * 4);
                        piVar4 = (int32_t*)(intptr_t)puVar10[2];
                        local_2c = puVar10[1];
                        do {
                          if ((*piVar4 == iVar6) ||
                             (*(int32_t*)(*(int32_t*)(*(int32_t*)(self + 0x14) +
                                                      *piVar4 * 4) + 0x38) == iVar6)) {
                            local_14 = 1;
                          }
                          piVar4 = piVar4 + 1;
                          local_2c = local_2c - 1;
                        } while (local_2c != 0);
                      }
                      if (puVar10 == local_1c) {
                        local_14 = 0;
                      }
                      if (local_14 != 0) {
                        puVar3 = (uint32_t*)0x0;
                        do {
                          if (puVar10 == (uint32_t*)(intptr_t)local_a8[(int32_t)puVar3]) {
                            local_14 = 0;
                          }
                          puVar3 = (uint32_t*)((intptr_t)puVar3 + 1);
                        } while (puVar3 < local_20);
                        if (local_14 != 0) {
                          local_8 = 1;
                        }
                      }
                    }
                    local_10 = local_10 + 1;
                    local_54[4] = local_54[4] - 1;
                  } while (local_54[4] != 0);
                }
                local_c = (uint32_t*)((intptr_t)local_c + 1);
              } while (local_c < local_3c);
            }
            local_24 = (uint32_t*)((intptr_t)local_24 + 1);
          } while (local_24 < local_20);
        }
        local_c = (uint32_t*)0x0;
        do {
          iVar6 = local_228[(int32_t)local_c];
          if ((iVar6 != -1) && (puVar10 = (uint32_t*)0x0, local_20 != (uint32_t*)0x0)) {
            local_3c = *(uint32_t*)(*(int32_t*)(self + 0x14) + iVar6 * 4);
            do {
              uVar9 = *(uint32_t*)((intptr_t)local_a8[(int32_t)puVar10] + 0xc);
              if (uVar9 != 0) {
                piVar4 = *(int32_t**)((intptr_t)local_a8[(int32_t)puVar10] + 0x10);
                local_2c = uVar9;
                do {
                  if ((iVar6 == *piVar4) || (*(int32_t*)(local_3c + 0x38) == *piVar4)) {
                    local_8 = 1;
                  }
                  piVar4 = piVar4 + 1;
                  local_2c = local_2c - 1;
                } while (local_2c != 0);
              }
              puVar10 = (uint32_t*)((intptr_t)puVar10 + 1);
            } while (puVar10 < local_20);
          }
          local_c = (uint32_t*)((intptr_t)local_c + 1);
        } while (local_c < (uint32_t*)0x28);
        if (local_8 == 0) goto LAB_006a19c0;
      }
      local_18 = local_18 + 1;
    } while (local_18 < 2);
    if (local_8 != 0) goto code_r0x006a19b1;
LAB_006a19c0:
    puVar10 = local_a8;
    puVar3 = local_e8;
    for (uVar9 = (uint32_t)(intptr_t)local_20 & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
      *puVar3 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar3 = puVar3 + 1;
    }
    for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(char*)puVar3 = (char)*puVar10;
      puVar10 = (uint32_t*)((intptr_t)puVar10 + 1);
      puVar3 = (uint32_t*)((intptr_t)puVar3 + 1);
    }
    local_e8[(int32_t)(intptr_t)puVar2] = (uint32_t)(intptr_t)local_1c;
    local_30 = (uint32_t*)((intptr_t)local_20 + 1);
    uVar9 = 0;
    do {
      iVar6 = *(int32_t*)((intptr_t)local_228 + uVar9);
      if ((iVar6 != -1) || (iVar6 = *(int32_t*)((intptr_t)local_2c8 + uVar9), iVar6 != -1)) {
        *(int32_t*)((intptr_t)local_188 + uVar9) = iVar6;
      }
      uVar9 = uVar9 + 4;
    } while (uVar9 < 0xa0);
    local_8 = 0;
LAB_006a1a22:
    iVar6 = local_8;
    goto LAB_006a1a25;
  }
  iVar6 = 1;
LAB_006a1a25:
  local_40 = 1;
  if (iVar6 == 0) {
LAB_006a1d7d:
    iVar6 = FUN_0065d0b4();
    if (iVar6 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = FUN_0065cc1a();
    }
    uVar9 = local_34;
    if (iVar6 == 0) {
      return -0x7ff8fff2;
    }
    if (local_40 == 0) {
      uVar7 = local_34 & 0xfffff | 0x70300000;
    }
    else {
      uVar7 = local_34 & 0xfffff | 0x70400000;
    }
    local_8 = FUN_0065d0ff(uVar7, local_34 * 3, local_34, 0);
    if (local_8 < 0) goto LAB_006a1c27;
    local_8 = FUN_0065cc50();
    if (local_8 < 0) goto LAB_006a1c27;
    local_2c = 0;
    if (uVar9 != 0) {
      local_c = (uint32_t*)(intptr_t)(uVar9 << 3);
      local_10 = (uint32_t*)(intptr_t)(uVar9 << 2);
      do {
        puVar10 = local_c;
        puVar2 = local_10;
        iVar5 = local_2c * 4;
        *(uint32_t*)(iVar5 + *(int32_t*)(iVar6 + 0x10)) =
            *(uint32_t*)(iVar5 + *(int32_t*)(*(int32_t*)(self + 0x100) + 0x10));
        *(int32_t*)(iVar5 + *(int32_t*)(iVar6 + 8)) = local_188[local_2c];
        iVar5 = local_188[local_2c + 8];
        local_10 = local_10 + 1;
        *(int32_t*)((intptr_t)puVar2 + *(int32_t*)(iVar6 + 8)) = local_188[local_2c + 4];
        local_c = local_c + 1;
        *(int32_t*)((intptr_t)puVar10 + *(int32_t*)(iVar6 + 8)) = iVar5;
        local_2c = local_2c + 1;
      } while (local_2c < local_34);
    }
    if (param_1 == 0) {
      iVar6 = FUN_0069c1ed(iVar6, local_e8, local_30);
      return iVar6;
    }
    local_8 = FUN_0065d35e();
    if (local_8 < 0) goto LAB_006a1c27;
  }
  else {
    if (param_1 != 0) {
      local_40 = 0;
      iVar6 = FUN_00694b7c(*(uint32_t*)(self + 0x100), (int32_t*)DAT_006f1740, local_e8,
                           &local_30, local_188, local_54, local_34, param_1);
      if (iVar6 == 0) goto LAB_006a1d7d;
      iVar6 = FUN_00694b7c(*(uint32_t*)(self + 0x100), (int32_t*)DAT_006f17a0, local_e8,
                           &local_30, local_188, local_54, local_34, param_1);
    }
    uVar9 = local_34;
    local_40 = 1;
    if (iVar6 == 0) goto LAB_006a1d7d;
    local_40 = 0;
    iVar6 = FUN_00694b7c(*(uint32_t*)(self + 0x100), (int32_t*)DAT_006f1800, local_e8,
                         &local_30, local_188, local_54, local_34, param_1);
    uVar7 = 0;
    if (uVar9 != 0) {
      do {
        if (local_188[uVar7] != local_188[uVar7 + 4]) {
          iVar6 = 1;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar9);
    }
    if (iVar6 == 0) {
LAB_006a1c41:
      bVar1 = true;
      uVar7 = 0;
      if (uVar9 != 0) {
        do {
          if (local_188[uVar7] != local_188[uVar7 + 4]) {
            return 1;
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar9);
      }
      if (*(int32_t*)(self + 0x160) == -1) {
        iVar6 = FUN_0065d97c(DAT_006c3b94, 0x311, 1, 4);
        *(int32_t*)(self + 0x170) = iVar6;
        if (iVar6 == -1) {
          return -0x7ff8fff2;
        }
        iVar6 = FUN_0065d9d5(iVar6, 0, 0, 0x4000000000000000);
        *(int32_t*)(self + 0x160) = iVar6;
        if (iVar6 == -1) {
          return -0x7ff8fff2;
        }
      }
      uVar7 = 0;
      if (uVar9 != 0) {
        iVar6 = *(int32_t*)(self + 0x160);
        do {
          local_188[uVar7] = iVar6;
          if (local_188[uVar7 + 8] != local_188[8]) {
            bVar1 = false;
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar9);
      }
      iVar6 = *(int32_t*)(*(int32_t*)(self + 0x14) + local_188[8] * 4);
      if (((*(uint8_t*)(*(int32_t*)(*(int32_t*)(self + 0x10) +
                                    *(int32_t*)(iVar6 + 4) * 4) + 5) & 1) != 0) && (bVar1)) {
        uVar9 = 0;
        piVar4 = (int32_t*)(self + 0x164);
        do {
          if ((*piVar4 == -1) ||
             (*(double*)(*(int32_t*)(*(int32_t*)(self + 0x14) + *piVar4 * 4) + 0x20) ==
              *(double*)(iVar6 + 0x20))) break;
          uVar9 = uVar9 + 1;
          piVar4 = piVar4 + 1;
        } while (uVar9 < 3);
        if (uVar9 != 3) {
          piVar4 = (int32_t*)(self + 0x164 + uVar9 * 4);
          if (*piVar4 == -1) {
            iVar6 = FUN_0065d9d5(*(uint32_t*)(self + 0x170), 0, uVar9 + 1,
                                 *(uint64_t*)(iVar6 + 0x20));
            *piVar4 = iVar6;
            if (iVar6 == -1) {
              return -0x7ff8fff2;
            }
          }
          if (local_34 != 0) {
            iVar6 = *piVar4;
            piVar4 = local_188 + 8;
            for (uVar9 = local_34; uVar9 != 0; uVar9 = uVar9 - 1) {
              *piVar4 = iVar6;
              piVar4 = piVar4 + 1;
            }
          }
        }
      }
      goto LAB_006a1d7d;
    }
    local_30 = (uint32_t*)0x0;
    local_8 = FUN_00694b7c(*(uint32_t*)(self + 0x100), (int32_t*)DAT_006f1860, local_e8,
                           &local_30, local_188, local_54, uVar9, param_1);
    uVar7 = 0;
    local_40 = 1;
    if (uVar9 != 0) {
      do {
        if (local_188[uVar7] != local_188[uVar7 + 4]) {
          local_8 = 1;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar9);
    }
    if (local_8 == 0) goto LAB_006a1c41;
    local_40 = 0;
    local_30 = (uint32_t*)0x0;
    local_8 = FUN_00694b7c(*(uint32_t*)(self + 0x100), (int32_t*)DAT_006f18c0, local_e8,
                           &local_30, local_188, local_54, uVar9, param_1);
    uVar7 = 0;
    if (uVar9 != 0) {
      do {
        if (local_188[uVar7] != local_188[uVar7 + 4]) {
          local_8 = 1;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar9);
    }
    if (local_8 == 0) goto LAB_006a1c41;
    local_30 = (uint32_t*)0x0;
    local_8 = FUN_00694b7c(*(uint32_t*)(self + 0x100), (int32_t*)DAT_006f1920, local_e8,
                           &local_30, local_188, local_54, uVar9, param_1);
    uVar7 = 0;
    local_40 = 1;
    if (uVar9 != 0) {
      do {
        if (local_188[uVar7] != local_188[uVar7 + 4]) {
          local_8 = 1;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar9);
    }
    if (local_8 == 0) goto LAB_006a1c41;
    iVar6 = local_58;
  }
  local_8 = 0;
LAB_006a1c27:
  if (iVar6 != 0) {
    FUN_00614343();
  }
  return local_8;
code_r0x006a15b2:
  local_38 = local_38 + 1;
  if (local_38 != 0) goto LAB_006a1623;
  goto LAB_006a1277;
code_r0x006a19b1:
  local_38 = local_38 + 1;
  if (local_38 != 0) goto LAB_006a1a22;
  goto LAB_006a1665;
}

// 0x6a1e95 — observed shape
int32_t FUN_006a1e95(void* selfv)
{
  uint8_t* self = (uint8_t*)selfv;
  uint8_t* pbVar1;
  int32_t iVar2;
  int32_t iVar3;
  uint32_t uVar4;
  int32_t* piVar5;
  int32_t iVar6;
  int32_t iVar7;
  uint32_t uVar8;
  int32_t* piVar9;
  int32_t idx;
  uint32_t auStack_30[4];
  int32_t local_20[4];
  int32_t* local_10;
  uint32_t local_c;
  int32_t* local_8;

  uVar4 = **(uint32_t**)(self + 0x100);
  if ((uVar4 & 0xfff00000) != 0x20400000) {
    return 1;
  }
  uVar4 = uVar4 & 0xfffff;
  piVar9 = (int32_t*)(*(uint32_t**)(self + 0x100))[2];
  local_8 = piVar9 + uVar4;
  iVar6 = *(int32_t*)(self + 0x14);
  if ((*(uint8_t*)(*(int32_t*)(*(int32_t*)(self + 0x10) +
                               *(int32_t*)(*(int32_t*)(iVar6 + *local_8 * 4) + 4) * 4) + 5) & 1)
      == 0) {
    if ((*(uint8_t*)(*(int32_t*)(*(int32_t*)(self + 0x10) +
                                 *(int32_t*)(*(int32_t*)(iVar6 + *piVar9 * 4) + 4) * 4) + 5) &
         1) == 0) {
      return 1;
    }
    local_20[3] = 1;
    piVar5 = piVar9;
  }
  else {
    local_20[3] = 0;
    piVar5 = local_8;
    local_8 = piVar9;
  }
  *(uint32_t*)(self + 0x15c) = 0;
  local_10 = (int32_t*)0x0;
  if (uVar4 != 0) {
    piVar9 = local_8;
    do {
      idx = *(int32_t*)(((intptr_t)piVar5 - (intptr_t)local_8) + (intptr_t)piVar9);
      if (*(double*)(*(int32_t*)(iVar6 + idx * 4) + 0x20) != -0.5) {
        return 1;
      }
      pbVar1 = *(uint8_t**)(iVar6 + *piVar9 * 4);
      if ((((pbVar1[0x3d] & 2) == 0) && ((*pbVar1 & 4) == 0)) &&
         ((*(uint8_t*)(self + 0x6e) & 4) != 0)) {
        *(uint32_t*)(self + 0x15c) = 1;
      }
      local_10 = (int32_t*)((intptr_t)local_10 + 1);
      piVar9 = piVar9 + 1;
    } while (local_10 < uVar4);
  }
  iVar7 = *(int32_t*)(*(int32_t*)(iVar6 +
                                  **(int32_t**)(*(int32_t*)(self + 0x100) + 0x10) * 4) + 4);
  local_c = uVar4;
  if (iVar7 == *(int32_t*)(self + 0x88)) {
    iVar6 = FUN_006a0bf8(self, (int32_t*)0x20000, (int32_t*)0x0, local_8, 0x20000, 0, 0);
    if (*(int32_t*)(self + 0x15c) == 2) {
      FUN_0066275f();
      return iVar6;
    }
    return iVar6;
  }
  if (iVar7 == *(int32_t*)(self + 0x84)) {
    iVar7 = FUN_0069ea9a(uVar4 | 0x20400000, *(uint32_t**)(self + 0x100), local_20, 2);
    if (iVar7 != 0) {
      return iVar7;
    }
    local_10 = local_20 + local_20[3];
    if (*local_10 != 0) {
      local_8 = (int32_t*)0x0;
      if (uVar4 != 0) {
        piVar9 = *(int32_t**)((intptr_t)*local_10 + 8);
        do {
          pbVar1 = *(uint8_t**)(iVar6 + *piVar9 * 4);
          if ((pbVar1[0x3e] & 0x1f) != 0) break;
          if (((*(uint32_t*)(*(int32_t*)(*(int32_t*)(self + 0x10) +
                                         *(int32_t*)(pbVar1 + 4) * 4) + 4) & 0x200) != 0) ||
             (((*(uint32_t*)(pbVar1 + 0x3c) & 0x200) == 0 && ((*pbVar1 & 4) == 0)))) {
            uVar4 = local_c;
            break;
          }
          local_20[3] = 0;
          local_8 = (int32_t*)((intptr_t)local_8 + 1);
          piVar9 = piVar9 + 1;
          uVar4 = local_c;
        } while (local_8 < local_c);
      }
      if (local_8 == (int32_t*)uVar4) {
        uVar8 = local_20[3];
      }
      else {
        local_8 = (int32_t*)0x0;
        if (uVar4 != 0) {
          piVar9 = (int32_t*)(*(int32_t*)((intptr_t)*local_10 + 8) + uVar4 * 4);
          do {
            pbVar1 = *(uint8_t**)(iVar6 + *piVar9 * 4);
            if ((pbVar1[0x3e] & 0x1f) != 0) break;
            if (((*(uint32_t*)(*(int32_t*)(*(int32_t*)(self + 0x10) +
                                           *(int32_t*)(pbVar1 + 4) * 4) + 4) & 0x200) != 0) ||
               (((*(uint32_t*)(pbVar1 + 0x3c) & 0x200) == 0 && ((*pbVar1 & 4) == 0)))) {
              uVar4 = local_c;
              break;
            }
            local_8 = (int32_t*)((intptr_t)local_8 + 1);
            piVar9 = piVar9 + 1;
            uVar4 = local_c;
          } while (local_8 < local_c);
        }
        if (local_8 == (int32_t*)uVar4) {
          return 1;
        }
        uVar8 = uVar4;
      }
      local_8 = (int32_t*)0x0;
      if (uVar4 != 0) {
        iVar6 = uVar8 << 2;
        do {
          iVar7 = *(int32_t*)(*(int32_t*)(self + 0x14) +
                              *(int32_t*)(iVar6 + *(int32_t*)((intptr_t)*local_10 + 8)) * 4);
          uVar4 = FUN_0065d9d5(*(uint32_t*)(iVar7 + 4), *(uint32_t*)(iVar7 + 0xc),
                               *(uint32_t*)(iVar7 + 0x10), *(uint64_t*)(iVar7 + 0x20));
          local_20[3] = uVar4;
          auStack_30[(int32_t)local_8] = uVar4;
          if (uVar4 == 0xffffffff) {
            return -0x7ff8fff2;
          }
          iVar2 = *(int32_t*)(*(int32_t*)(self + 0x14) + uVar4 * 4);
          iVar3 = *local_10;
          *(uint32_t*)(iVar2 + 0x38) = *(uint32_t*)(iVar6 + *(int32_t*)(iVar3 + 8));
          *(uint32_t*)(iVar2 + 0x48) = *(uint32_t*)(iVar7 + 0x48);
          *(uint32_t*)(iVar2 + 0x50) = *(uint32_t*)(iVar7 + 0x50);
          *(uint32_t*)(iVar2 + 0x54) = *(uint32_t*)(iVar7 + 0x54);
          *(uint32_t*)(iVar2 + 0x58) = *(uint32_t*)(iVar7 + 0x54);
          *(uint32_t*)(iVar2 + 0x3c) = *(uint32_t*)(iVar7 + 0x3c) | 0x20000;
          *(int32_t*)(iVar6 + *(int32_t*)(iVar3 + 8)) = local_20[3];
          *(uint32_t*)(*(int32_t*)(iVar3 + 0x10) + (int32_t)local_8 * 4) =
              *(uint32_t*)(*(int32_t*)(*(int32_t*)(self + 0x100) + 0x10) +
                           (int32_t)local_8 * 4);
          local_8 = (int32_t*)((intptr_t)local_8 + 1);
          iVar6 = iVar6 + 4;
        } while (local_8 < local_c);
      }
      **(uint32_t**)(self + 0x100) = 0;
      return 0;
    }
  }
  return 1;
}

// 0x6a2192 — observed shape
uint32_t FUN_006a2192(void* selfv)
{
  uint8_t* self = (uint8_t*)selfv;
  uint32_t* puVar1;
  int32_t iVar2;
  uint32_t uVar3;
  int32_t* piVar4;
  uint32_t uVar5;
  int32_t* piVar6;
  int32_t* piVar7;
  uint32_t uVar8;
  uint32_t local_c;
  int32_t idx;

  *(uint32_t*)(self + 0x15c) = 0;
  puVar1 = *(uint32_t**)(self + 0x100);
  uVar3 = *puVar1;
  if ((uVar3 & 0xfff00000) == 0x20500000) {
    uVar3 = uVar3 & 0xfffff;
    piVar7 = (int32_t*)puVar1[2];
    piVar6 = piVar7 + uVar3;
    iVar2 = *(int32_t*)(self + 0x14);
    if ((*(uint32_t*)(*(int32_t*)(*(int32_t*)(self + 0x10) +
                                  *(int32_t*)(*(int32_t*)(iVar2 + *piVar7 * 4) + 4) * 4) + 4) &
         0x100) == 0) {
      if ((*(uint32_t*)(*(int32_t*)(*(int32_t*)(self + 0x10) +
                                    *(int32_t*)(*(int32_t*)(iVar2 + *piVar6 * 4) + 4) * 4) + 4) &
           0x100) == 0) {
        return 1;
      }
      piVar4 = piVar7;
    }
    else {
      piVar4 = piVar6;
      piVar6 = piVar7;
    }
    if (uVar3 != 0) {
      uVar8 = 0;
      piVar7 = piVar6;
      do {
        idx = *(int32_t*)(((intptr_t)piVar4 - (intptr_t)piVar6) + (intptr_t)piVar7);
        if (*(double*)(*(int32_t*)(iVar2 + idx * 4) + 0x20) != 2.0) {
          return 1;
        }
        if (((*(uint32_t*)(*(int32_t*)(iVar2 + *piVar7 * 4) + 0x3c) & 0x1f0000) != 0x20000) &&
           ((*(uint8_t*)(self + 0x6e) & 8) != 0)) {
          return 1;
        }
        uVar8 = uVar8 + 1;
        piVar7 = piVar7 + 1;
      } while (uVar8 < uVar3);
    }
  }
  else {
    if ((uVar3 & 0xfff00000) != 0x20400000) {
      return 1;
    }
    piVar6 = (int32_t*)puVar1[2];
    uVar3 = uVar3 & 0xfffff;
    local_c = 0;
    if (uVar3 != 0) {
      piVar7 = piVar6;
      do {
        if (*piVar7 != piVar7[uVar3]) {
          return 1;
        }
        if (((*(uint32_t*)(*(int32_t*)(*(int32_t*)(self + 0x14) + *piVar7 * 4) + 0x3c) &
              0x1f0000) != 0x20000) && ((*(uint8_t*)(self + 0x6e) & 8) != 0)) {
          return 1;
        }
        local_c = local_c + 1;
        piVar7 = piVar7 + 1;
      } while (local_c < uVar3);
    }
  }
  uVar5 = FUN_006a0bf8(self, (int32_t*)0x40000, (int32_t*)0x20000, piVar6, 0x40000, 0, 0);
  return uVar5;
}

// 0x6a22f4 — observed shape
uint32_t FUN_006a22f4(void* selfv, uint32_t* param_1)
{
  uint8_t* self = (uint8_t*)selfv;
  int32_t iVar1;
  int32_t iVar2;
  uint32_t* puVar3;
  uint32_t* puVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  int32_t* piVar7;
  int32_t* piVar8;
  bool bVar9;
  uint32_t uVar10;
  int32_t* local_14;
  uint32_t local_10;

  bVar9 = param_1 == (uint32_t*)0x0;
  if (bVar9) {
    param_1 = *(uint32_t**)(self + 0x100);
  }
  if ((*param_1 & 0xfff00000) == 0x20400000) {
    uVar6 = *param_1 & 0xfffff;
    piVar8 = (int32_t*)(intptr_t)param_1[2];
    local_14 = piVar8 + uVar6;
    iVar2 = *(int32_t*)(self + 0x14);
    if ((*(uint8_t*)(*(int32_t*)(*(int32_t*)(self + 0x10) +
                                 *(int32_t*)(*(int32_t*)(iVar2 + *local_14 * 4) + 4) * 4) + 5) &
         1) == 0) {
      if ((*(uint8_t*)(*(int32_t*)(*(int32_t*)(self + 0x10) +
                                   *(int32_t*)(*(int32_t*)(iVar2 + *piVar8 * 4) + 4) * 4) + 5) &
           1) == 0) {
        return 1;
      }
      piVar7 = piVar8;
    }
    else {
      piVar7 = local_14;
      local_14 = piVar8;
    }
    puVar3 = *(uint32_t**)(self + 0x100);
    piVar8 = local_14;
    if (puVar3 != param_1) {
      piVar8 = (int32_t*)(intptr_t)puVar3[2];
    }
    *(uint32_t*)(self + 0x15c) = 0;
    local_10 = 0;
    if (uVar6 != 0) {
      iVar1 = (int32_t)(intptr_t)piVar7 - (int32_t)(intptr_t)piVar8;
      do {
        if (*(double*)(*(int32_t*)(iVar2 + *(int32_t*)(iVar1 + (intptr_t)piVar8) * 4) + 0x20) !=
            1.0) {
          return 1;
        }
        if ((bVar9) &&
           ((*(uint32_t*)(*(int32_t*)(iVar2 + *piVar8 * 4) + 0x3c) & 0x1f0000) != 0x80000)) {
          return 1;
        }
        puVar4 = *(uint32_t**)(iVar2 + *piVar8 * 4);
        if (((*(uint8_t*)((intptr_t)puVar4 + 0x3d) & 2) == 0) &&
           ((*puVar4 & (uint32_t)bVar9 * 4 + 0x14) == 0)) {
          *(uint32_t*)(self + 0x15c) = 1;
        }
        local_10 = local_10 + 1;
        piVar8 = piVar8 + 1;
      } while (local_10 < uVar6);
    }
    if (bVar9) {
      param_1 = (uint32_t*)0x0;
      uVar10 = 0x90000;
      uVar5 = 0x80000;
    }
    else {
      uVar10 = 0x10000;
      local_14 = (int32_t*)(intptr_t)puVar3[2];
      uVar5 = 0;
    }
    uVar5 = FUN_006a0bf8(self, (int32_t*)0x10000, (int32_t*)(intptr_t)uVar5, local_14, uVar10,
                         (uint32_t)(intptr_t)param_1, 0);
    if (*(int32_t*)(self + 0x15c) == 2) {
      FUN_0066275f();
    }
  }
  else {
    uVar5 = 1;
  }
  return uVar5;
}

// 0x6a247c — observed shape
int32_t FUN_006a247c(void* selfv)
{
  uint8_t* self = (uint8_t*)selfv;
  int32_t iVar1;
  uint32_t* puVar2;
  int32_t local_8;

  local_8 = 1;
  if (((**(uint32_t**)(self + 0x100) & 0xfff00000) == 0x20500000) &&
     ((iVar1 = *(int32_t*)(*(int32_t*)(self + 0x14) +
                           *(int32_t*)((*(uint32_t**)(self + 0x100))[2] +
                                       (**(uint32_t**)(self + 0x100) & 0xfffff) * 4) * 4),
      (*(uint8_t*)(*(int32_t*)(*(int32_t*)(self + 0x10) + *(int32_t*)(iVar1 + 4) * 4) + 5) & 1)
      == 0 || (*(double*)(iVar1 + 0x20) != -1.0)))) {
    return 1;
  }
  puVar2 = (uint32_t*)FUN_0069e83f(**(uint32_t**)(self + 0x100) & 0xfffff | 0x20400000,
                                   *(uint32_t**)(self + 0x100), 0, 2, 1);
  if ((puVar2 != (uint32_t*)0x0) && (local_8 = FUN_006a22f4(self, puVar2), local_8 == 0)) {
    *puVar2 = 0;
  }
  return local_8;
}

// 0x6a251c — observed shape
int32_t FUN_006a251c(void* selfv)
{
  uint8_t* self = (uint8_t*)selfv;
  bool bVar2;
  float fVar1;
  uint32_t* puVar3;
  int32_t* piVar4;
  int32_t iVar5;
  uint32_t uVar6;
  int32_t* piVar7;
  uint32_t* local_14;
  int32_t* local_10;
  uint32_t local_c;

  *(uint32_t*)(self + 0x15c) = 0;
  puVar3 = *(uint32_t**)(self + 0x100);
  if ((*puVar3 & 0xfff00000) == 0x20400000) {
    uVar6 = *puVar3 & 0xfffff;
    bVar2 = true;
    if (uVar6 == 0) {
LAB_006a257f:
      puVar3 = (uint32_t*)FUN_0069e83f(uVar6 | 0x20400000, puVar3, 0, 2, 1);
      fVar1 = -1.0;
      if (puVar3 == (uint32_t*)0x0) goto LAB_006a26b1;
      local_14 = puVar3;
    }
    else {
      piVar4 = (int32_t*)(intptr_t)puVar3[2];
      piVar7 = piVar4 + uVar6;
      local_c = uVar6;
      do {
        if (*piVar4 != *piVar7) {
          bVar2 = false;
        }
        piVar7 = piVar7 + 1;
        piVar4 = piVar4 + 1;
        local_c = local_c - 1;
      } while (local_c != 0);
      if (bVar2) goto LAB_006a257f;
      fVar1 = -0.5;
    }
    piVar7 = (int32_t*)(intptr_t)puVar3[2];
    iVar5 = *(int32_t*)(self + 0x14);
    local_c = *puVar3 & 0xfffff;
    local_10 = piVar7 + local_c;
    if ((*(uint8_t*)(*(int32_t*)(*(int32_t*)(self + 0x10) +
                                 *(int32_t*)(*(int32_t*)(iVar5 + *local_10 * 4) + 4) * 4) + 5) &
         1) == 0) {
      if ((*(uint8_t*)(*(int32_t*)(*(int32_t*)(self + 0x10) +
                                   *(int32_t*)(*(int32_t*)(iVar5 + *piVar7 * 4) + 4) * 4) + 5) &
           1) == 0) goto LAB_006a26b1;
      piVar4 = piVar7;
    }
    else {
      piVar4 = local_10;
      local_10 = piVar7;
    }
    uVar6 = 0;
    if (local_c != 0) {
      do {
        if ((float)*(double*)(*(int32_t*)(iVar5 + piVar4[uVar6] * 4) + 0x20) != fVar1)
          goto LAB_006a26b1;
        uVar6 = uVar6 + 1;
      } while (uVar6 < local_c);
    }
    if (bVar2) {
      local_10 = *(int32_t**)(*(int32_t*)(self + 0x100) + 8);
    }
    else {
      local_14 = (uint32_t*)FUN_0069e83f(**(uint32_t**)(self + 0x100) & 0xfffff | 0x20400000,
                                         *(uint32_t**)(self + 0x100), 0, 2, 2);
      if (local_14 == (uint32_t*)0x0) goto LAB_006a26b1;
      bVar2 = true;
      if (local_c != 0) {
        piVar4 = (int32_t*)(intptr_t)local_14[2];
        piVar7 = piVar4 + local_c;
        do {
          if (*piVar4 != *piVar7) {
            bVar2 = false;
          }
          piVar7 = piVar7 + 1;
          piVar4 = piVar4 + 1;
          local_c = local_c - 1;
        } while (local_c != 0);
        if (!bVar2) goto LAB_006a26b1;
      }
    }
    iVar5 = FUN_006a0bf8(self, (int32_t*)0x60000, (int32_t*)0x0, local_10, 0x60000,
                         (uint32_t)(intptr_t)local_14, 0);
    if (iVar5 == 0) {
      *local_14 = 0;
    }
  }
  else {
LAB_006a26b1:
    iVar5 = 1;
  }
  return iVar5;
}

// 0x6a26b9 — observed shape
uint32_t FUN_006a26b9(void* selfv)
{
  uint8_t* self = (uint8_t*)selfv;
  int32_t iVar1;
  int32_t iVar2;
  int32_t iVar3;
  int32_t iVar4;
  uint32_t uVar5;
  int32_t* piVar6;
  int32_t iVar7;
  int32_t iVar8;
  int32_t* piVar9;
  uint32_t uVar10;
  uint8_t local_1c[8];
  int32_t local_14;
  uint32_t local_10;
  uint32_t local_8;

  uVar10 = **(uint32_t**)(self + 0x100) & 0xfffff;
  if ((**(uint32_t**)(self + 0x100) & 0xfff00000) == 0x70300000) {
    local_8 = *(uint32_t*)(self + 0xfc);
    iVar2 = *(int32_t*)(self + 0x100);
    FUN_0069ea9a(uVar10 | 0x20500000, (uint32_t*)(intptr_t)iVar2, local_1c, 2);
    if (local_14 == 0) {
LAB_006a283a:
      uVar5 = 1;
    }
    else {
      local_10 = 0;
      if (uVar10 != 0) {
        piVar9 = *(int32_t**)((intptr_t)local_14 + 0x10);
        piVar6 = (int32_t*)((intptr_t)*(int32_t*)(iVar2 + 8) + uVar10 * 8);
        do {
          if (*piVar6 != *piVar9) goto LAB_006a283a;
          local_10 = local_10 + 1;
          piVar6 = piVar6 + 1;
          piVar9 = piVar9 + 1;
        } while (local_10 < uVar10);
      }
      iVar3 = *(int32_t*)(iVar2 + 8);
      iVar4 = *(int32_t*)((intptr_t)local_14 + 8);
      iVar1 = (int32_t)(uVar10 * 4) + iVar3;
      iVar7 = (int32_t)(uVar10 * 4) + iVar4;
      iVar8 = FUN_0069c7d0(iVar3, iVar1, iVar4, iVar7, local_14, iVar2, local_8);
      if ((((iVar8 == 0) ||
           (iVar8 = FUN_0069c7d0(iVar1, iVar3, iVar4, iVar7, local_14, iVar2, local_8),
            iVar8 == 0)) ||
          (iVar8 = FUN_0069c7d0(iVar3, iVar1, iVar7, iVar4, local_14, iVar2, local_8),
           iVar8 == 0)) ||
         (((iVar8 = FUN_0069c7d0(iVar1, iVar3, iVar7, iVar4, local_14, iVar2, local_8),
            iVar8 == 0 ||
            (iVar8 = FUN_0069c7d0(iVar4, iVar7, iVar3, iVar1, local_14, iVar2, local_8),
             iVar8 == 0)) ||
           ((iVar8 = FUN_0069c7d0(iVar7, iVar4, iVar3, iVar1, local_14, iVar2, local_8),
             iVar8 == 0 ||
             (iVar8 = FUN_0069c7d0(iVar4, iVar7, iVar1, iVar3, local_14, iVar2, local_8),
              iVar8 == 0)))))) {
        uVar5 = 0;
      }
      else {
        uVar5 = FUN_0069c7d0(iVar7, iVar4, iVar1, iVar3, local_14, iVar2, local_8);
      }
    }
  }
  else {
    uVar5 = 1;
  }
  return uVar5;
}

// 0x6a2842 — observed shape
int32_t FUN_006a2842(void* selfv)
{
  uint8_t* self = (uint8_t*)selfv;
  uint32_t* puVar1;
  uint32_t* puVar2;
  uint32_t uVar3;
  int32_t iVar4;
  int32_t iVar5;
  uint32_t uVar6;
  int32_t iVar7;
  int32_t* piVar8;
  uint32_t uVar9;
  uint8_t local_110[128];
  uint8_t local_90[128];
  uint32_t local_10;
  uint32_t local_c;
  uint32_t local_8;

  uVar9 = 0;
  uVar3 = 0;
  local_10 = 0;
  if (*(int32_t*)(self + 8) != 0) {
    do {
      *(uint32_t*)(*(int32_t*)(*(int32_t*)(self + 0x14) + uVar3 * 4) + 0x30) = 0xffffffff;
      *(uint32_t*)(*(int32_t*)(*(int32_t*)(self + 0x14) + uVar3 * 4) + 0x34) = 0xffffffff;
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint32_t*)(self + 8));
  }
  local_c = *(uint32_t*)(self + 0xc);
  iVar4 = FUN_0069dfba(0xffffffff, 1, &local_10, 0, 0, 0, local_c, 1, 0, 0, 0);
  if (*(int32_t*)(self + 8) != 0) {
    do {
      iVar7 = uVar9 * 4;
      piVar8 = (int32_t*)(*(int32_t*)(self + 0x14) + iVar7);
      iVar5 = *piVar8;
      if ((*(int32_t*)(iVar5 + 0x30) != -1) || (*(int32_t*)(iVar5 + 0x34) != -1)) {
        iVar5 = *piVar8;
        *(uint32_t*)(iVar5 + 0x14) = *(uint32_t*)(iVar5 + 0x30);
        iVar5 = *(int32_t*)(iVar7 + *(int32_t*)(self + 0x14));
        *(uint32_t*)(iVar5 + 0x18) = *(uint32_t*)(iVar5 + 0x34);
      }
      *(uint32_t*)(*(int32_t*)(iVar7 + *(int32_t*)(self + 0x14)) + 0x30) = 0xffffffff;
      *(uint32_t*)(*(int32_t*)(iVar7 + *(int32_t*)(self + 0x14)) + 0x34) = 0xffffffff;
      uVar9 = uVar9 + 1;
    } while (uVar9 < *(uint32_t*)(self + 8));
  }
  uVar3 = 0;
  if (local_c != 0) {
    do {
      iVar5 = uVar3 * 4;
      uVar3 = uVar3 + 1;
      **(uint32_t**)(*(int32_t*)(self + 0x18) + iVar5) = 0;
    } while (uVar3 < local_c);
  }
  if (-1 < iVar4) {
    *(uint32_t*)(self + 0xfc) = 0;
    FUN_0069ced3(local_110, local_90, 0, 0);
    local_c = 0;
    if (*(int32_t*)(self + 0xc) != 0) {
      do {
        puVar2 = *(uint32_t**)(*(int32_t*)(self + 0x18) + local_c * 4);
        uVar3 = *puVar2 & 0xfff00000;
        if ((*puVar2 & 0xfffff) == 1) {
          local_10 = 0xffffffff;
          local_8 = 0xffffffff;
          if ((((uVar3 == 0x73000000) || (uVar3 == 0x73200000)) || (uVar3 == 0x73100000)) ||
             (uVar3 == 0x73300000)) {
            iVar4 = *(int32_t*)(*(int32_t*)(self + 0x14) +
                                *(int32_t*)(intptr_t)puVar2[2] * 4);
            uVar3 = *(uint32_t*)(*(int32_t*)(*(int32_t*)(self + 0x10) +
                                             *(int32_t*)(iVar4 + 4) * 4) + 4);
            if (((uVar3 & 0x200) != 0) && ((uVar3 & 0x2000) == 0)) {
              iVar4 = FUN_0069d0e1(DAT_006d1990, 0x2000, iVar4, &local_10);
              if (iVar4 < 0) {
                return iVar4;
              }
              *(uint32_t*)(intptr_t)puVar2[2] = local_10;
            }
          }
          else if (uVar3 == 0x73b00000) {
            iVar4 = *(int32_t*)(*(int32_t*)(self + 0x14) +
                                *(int32_t*)((intptr_t)puVar2[2] + 4) * 4);
            if ((((*(uint8_t*)(*(int32_t*)(*(int32_t*)(self + 0x10) +
                                           *(int32_t*)(iVar4 + 4) * 4) + 5) & 1) != 0) &&
                 (*(int32_t*)(iVar4 + 8) == -1)) && (*(double*)(iVar4 + 0x20) == 0.0)) {
              local_8 = FUN_0065d9d5(0, 0, 0, 0);
              if (local_8 == 0xffffffff) {
                return -0x7ff8fff2;
              }
              local_10 = *(uint32_t*)(*(int32_t*)(self + 0x14) +
                                      *(int32_t*)(intptr_t)puVar2[2] * 4);
              iVar4 = *(int32_t*)(*(int32_t*)(self + 0x14) + local_8 * 4);
              iVar5 = FUN_0065d501();
              if (iVar5 < 0) {
                return iVar5;
              }
              iVar5 = FUN_0065d5bd();
              if (iVar5 < 0) {
                return iVar5;
              }
              puVar1 = (uint32_t*)(iVar4 + 0x3c);
              *puVar1 = *puVar1 ^ 0x80000;
              *(uint32_t*)(iVar4 + 0x38) = *(uint32_t*)(intptr_t)puVar2[2];
              *(uint32_t*)((intptr_t)puVar2[2] + 4) = local_8;
            }
          }
          else if ((uVar3 == 0x74200000) || (uVar3 == 0x74100000)) {
            iVar4 = *(int32_t*)(*(int32_t*)(self + 0x14) +
                                *(int32_t*)(intptr_t)puVar2[2] * 4);
            uVar3 = *(uint32_t*)(*(int32_t*)(*(int32_t*)(self + 0x10) +
                                             *(int32_t*)(iVar4 + 4) * 4) + 4);
            if (((uVar3 & 0x200) != 0) && ((uVar3 & 0x40000) == 0)) {
              iVar4 = FUN_0069d0e1(DAT_006e0440, 0x40000, iVar4, &local_8);
              if (iVar4 < 0) {
                return iVar4;
              }
              *(uint32_t*)(intptr_t)puVar2[2] = local_8;
              iVar4 = *(int32_t*)(*(int32_t*)(self + 0x14) + local_8 * 4);
              local_8 = 1;
              if (1 < puVar2[1]) {
                do {
                  iVar5 = *(int32_t*)((intptr_t)puVar2[2] + local_8 * 4);
                  if (iVar5 == -1) {
                    iVar5 = iVar4;
                  }
                  else {
                    iVar5 = *(int32_t*)(*(int32_t*)(self + 0x14) + iVar5 * 4);
                  }
                  uVar6 = FUN_0065d9d5(*(uint32_t*)(iVar4 + 4), *(uint32_t*)(iVar4 + 0xc),
                                       local_8, *(uint64_t*)(iVar5 + 0x20));
                  uVar3 = local_8 + 1;
                  *(uint32_t*)((intptr_t)puVar2[2] + local_8 * 4) = uVar6;
                  local_8 = uVar3;
                } while (uVar3 < puVar2[1]);
              }
            }
          }
        }
        local_c = local_c + 1;
      } while (local_c < *(uint32_t*)(self + 0xc));
    }
    iVar4 = FUN_00664b28();
    if (-1 < iVar4) {
      iVar4 = 0;
    }
  }
  return iVar4;
}

// 0x6a2b66 — observed shape
int32_t FUN_006a2b66(void* selfv, uint32_t param_1)
{
  uint8_t* self = (uint8_t*)selfv;
  int32_t* piVar1;
  int32_t iVar2;

  iVar2 = FUN_0069f138(1);
  if (-1 < iVar2) {
    piVar1 = (int32_t*)(self + 0x110);
    *(uint32_t*)(*(int32_t*)(self + 0x10c) + *piVar1 * 4) = param_1;
    *piVar1 = *piVar1 + 1;
    iVar2 = 0;
  }
  return iVar2;
}

// 0x6a2b96 — observed shape
int32_t FUN_006a2b96(void* selfv)
{
  uint8_t* self = (uint8_t*)selfv;
  int32_t iVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  int32_t* piVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  int32_t* local_8;
  uint32_t* obj;

  local_8 = (int32_t*)0x0;
  FUN_0065c125(0x53455250);
  iVar1 = FUN_0066b20f();
  if (-1 < iVar1) {
    obj = *(uint32_t**)(self + 0xe0);
    iVar1 = (*(Vfn*)((intptr_t)*obj + 8))(&local_8);
    if (-1 < iVar1) {
      if (iVar1 == 0) {
        uVar6 = 0;
        uVar5 = 1;
        piVar4 = local_8;
        uVar2 = (*(Vfn*)((intptr_t)*local_8 + 0x10))(local_8, 1, 0);
        uVar2 = (*(Vfn*)((intptr_t)*local_8 + 0xc))(local_8, uVar2);
        iVar1 = FUN_0065c17a(uVar2, piVar4, uVar5, uVar6);
        if (iVar1 < 0) goto LAB_006a2c9f;
      }
      uVar3 = FUN_0065c2b3();
      if (uVar3 < 0x8001) {
        iVar1 = FUN_0069f138(uVar3);
        if (-1 < iVar1) {
          memmove((void*)(*(int32_t*)(self + 0x10c) + 4 + uVar3 * 4),
                  (void*)(*(int32_t*)(self + 0x10c) + 4),
                  *(int32_t*)(self + 0x110) * 4 - 4);
          iVar1 = FUN_0065c2bf(*(int32_t*)(self + 0x10c) + 4, uVar3);
          if (-1 < iVar1) {
            *(int32_t*)(self + 0x110) = *(int32_t*)(self + 0x110) + uVar3;
            *(int32_t*)(self + 0x120) = *(int32_t*)(self + 0x120) + uVar3;
            *(uint32_t*)(self + 0x11c) = *(uint32_t*)(self + 0x110);
            iVar1 = 0;
          }
        }
      }
      else {
        FUN_006626da();
        iVar1 = -0x7fffbffb;
      }
    }
  }
LAB_006a2c9f:
  if (local_8 != (int32_t*)0x0) {
    (*(Vfn*)((intptr_t)*local_8 + 8))(local_8);
    local_8 = (int32_t*)0x0;
  }
  FUN_0065c142();
  return iVar1;
}

// 0x6a3cac — observed shape
int32_t FUN_006a3cac(void* selfv, int32_t param_1)
{
  uint8_t* self = (uint8_t*)selfv;
  int32_t iVar1;
  uint32_t uVar2;
  int32_t local_10[3];

  local_10[0] = *(int32_t*)(self + 0xf4);
  local_10[1] = *(int32_t*)(self + 0xf0);
  local_10[2] = *(int32_t*)(self + 0xf8);
  uVar2 = 0;
  iVar1 = param_1;
  while ((local_10[uVar2] == 0 ||
         (iVar1 = FUN_006a0134(local_10[uVar2], param_1),
          *(int32_t*)(iVar1 + 0x10) == -1))) {
    uVar2 = uVar2 + 1;
    if (2 < uVar2) {
      return iVar1;
    }
  }
  return iVar1;
}

// 0x6a48dd — observed shape
uint32_t FUN_006a48dd(void* selfv, uint32_t param_1)
{
  uint8_t* self = (uint8_t*)selfv;
  uint32_t* puVar1;
  uint32_t uVar2;
  int32_t iVar3;
  uint32_t* puVar4;
  uint32_t* puVar5;

  if (((*(uint8_t*)(self + 0xcc) & 1) != 0) && (*(int32_t*)(self + 0x124) != 0)) {
    if (*(uint32_t*)(self + 300) <= *(uint32_t*)(self + 0x128)) {
      puVar1 = (uint32_t*)FUN_00533c78(*(uint32_t*)(self + 300) * 0x30);
      if (puVar1 == (uint32_t*)0x0) {
        return 0x8007000e;
      }
      puVar4 = *(uint32_t**)(self + 0x124);
      puVar5 = puVar1;
      for (uVar2 = (uint32_t)(*(int32_t*)(self + 0x128) * 0x18) >> 2; uVar2 != 0;
           uVar2 = uVar2 - 1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(uint8_t*)puVar5 = *(uint8_t*)puVar4;
        puVar4 = (uint32_t*)((intptr_t)puVar4 + 1);
        puVar5 = (uint32_t*)((intptr_t)puVar5 + 1);
      }
      operator_delete(*(void**)(self + 0x124));
      *(int32_t*)(self + 300) = *(int32_t*)(self + 300) << 1;
      *(uint32_t**)(self + 0x124) = puVar1;
    }
    *(uint32_t*)(*(int32_t*)(self + 0x124) + *(int32_t*)(self + 0x128) * 0x18) =
        *(uint32_t*)(self + 0x104);
    *(int32_t*)(*(int32_t*)(self + 0x124) + 4 + *(int32_t*)(self + 0x128) * 0x18) =
        *(int32_t*)(self + 0x110) << 2;
    uVar2 = 0;
    do {
      *(uint32_t*)(*(int32_t*)(self + 0x124) + 8 +
                   (uVar2 + *(int32_t*)(self + 0x128) * 6) * 4) = 0xffffffff;
      uVar2 = uVar2 + 1;
    } while (uVar2 < 4);
    *(int32_t*)(self + 0x128) = *(int32_t*)(self + 0x128) + 1;
  }
  *(uint32_t*)(self + 0x118) = *(uint32_t*)(self + 0x110);
  FUN_006a2b66(self, param_1);
  return 0;
}

// 0x6a49fa — observed shape
int32_t FUN_006a49fa(void* selfv, uint32_t param_1, uint32_t param_2, int32_t param_3)
{
  uint8_t* self = (uint8_t*)selfv;
  uint8_t* pbVar1;
  int32_t iVar2;

  iVar2 = FUN_006a49e3(param_1 | param_2);
  if (-1 < iVar2) {
    if (param_3 != 0) {
      iVar2 = FUN_006a49e3(param_3);
      if (iVar2 < 0) {
        return iVar2;
      }
      pbVar1 = (uint8_t*)(*(int32_t*)(self + 0x10c) + *(int32_t*)(self + 0x118) * 4 + 3);
      *pbVar1 = *pbVar1 | 0x10;
    }
    iVar2 = 0;
  }
  return iVar2;
}

// 0x6a4a40 — observed shape
int32_t FUN_006a4a40(void* selfv, uint32_t param_1, uint32_t param_2, int32_t param_3)
{
  uint8_t* self = (uint8_t*)selfv;
  int32_t iVar1;
  int32_t iVar2;
  uint32_t uVar3;
  uint32_t uVar4;

  iVar2 = FUN_006a49e3(param_1 | param_2);
  if (-1 < iVar2) {
    if (((param_1 | param_2) & 0x2000) != 0) {
      iVar2 = *(int32_t*)(*(int32_t*)(self + 0x14) + param_3 * 4);
      iVar1 = *(int32_t*)(iVar2 + 0x10);
      uVar3 = *(uint32_t*)(iVar2 + 0xc) & 0x7ff;
      uVar4 = uVar3 | 0xb0000000;
      if (iVar1 != 0) {
        if (iVar1 == 1) {
          uVar4 = uVar3 | 0xb0550000;
        }
        else if (iVar1 == 2) {
          uVar4 = uVar3 | 0xb0aa0000;
        }
        else if (iVar1 == 3) {
          uVar4 = uVar3 | 0xb0ff0000;
        }
      }
      FUN_006a49e3(uVar4);
    }
    iVar2 = 0;
  }
  return iVar2;
}
