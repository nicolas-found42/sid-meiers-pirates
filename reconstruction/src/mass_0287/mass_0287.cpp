#include <cstdint>
#include <cstddef>
#include <windows.h>

// Extern helpers referenced by the reconstructed listings.
extern int FUN_0062d704(int p1, int p2);
extern int FUN_0062d760(int p1, void* p2);
extern void FUN_0062e45b(byte param_1, void* self);
extern void FUN_0062e426_recon(void* self);
extern void FUN_0062e508_recon(void* self);
extern void operator_delete(void* ptr);
extern void FUN_0062a46a(void* param_1);
extern void* FUN_0065aaac(void* ptr, int param_1);
extern void FUN_0060d2b8(void);
extern void FUN_0062a495(int param_1);
extern void FUN_00412770(void* p1, int p2, void* p3, void* p4);

// 0x62d7ba — observed shape: int(int,void*,void*,int); 2D walk capped at min(4,*+0x14)xmin(4,*+0x18), calls FUN_0062d704
int FUN_0062d7ba(uint p1, void* p2, uint* p3, int p4) {
  int local_10 = 0;
  if (p4 != 0) {
    uint uVar1 = *(uint*)((uint8_t*)p1 + 0x14);
    uint uVar2 = *(uint*)((uint8_t*)p1 + 0x18);
    uint local_c = (uVar1 < 5) ? uVar1 : 4;
    uint local_8 = (uVar2 < 5) ? uVar2 : 4;
    int iVar5 = (int)p2;
    do {
      uint row = 0;
      if (local_c != 0) {
        uint* rowBase = p3;
        do {
          uint col = 0;
          if (local_8 != 0) {
            uint* cell = rowBase;
            do {
              local_10 = FUN_0062d704(iVar5, (int)*cell);
              if (local_10 < 0) return local_10;
              iVar5 = *(int*)((uint8_t*)iVar5 + 0xc);
              ++col;
              ++cell;
            } while (col < local_8);
          }
          if (col < uVar2) {
            for (int k = (int)(uVar2 - col); k != 0; --k)
              iVar5 = *(int*)((uint8_t*)iVar5 + 0xc);
          }
          ++row;
          rowBase += 4;
        } while (row < local_c);
      }
      if (row < uVar1) {
        for (int k = (int)(uVar1 - row); k != 0; --k) {
          if (uVar2 != 0)
            for (uint j = uVar2; j != 0; --j)
              iVar5 = *(int*)((uint8_t*)iVar5 + 0xc);
        }
      }
      --p4;
      p3 += 0x10;
    } while (p4 != 0);
  }
  return local_10;
}

// 0x62d88b — observed shape: int(int,void*,void*,uint); zero-fill (param_4&0x3ffffff)<<4 dwords then 2D walk calling FUN_0062d760
int FUN_0062d88b(uint p1, void* p2, uint* p3, uint p4) {
  int local_10 = 0;
  if (p4 != 0) {
    uint uVar1 = *(uint*)((uint8_t*)p1 + 0x14);
    uint uVar2 = *(uint*)((uint8_t*)p1 + 0x18);
    uint local_c = (uVar1 < 5) ? uVar1 : 4;
    uint local_8 = (uVar2 < 5) ? uVar2 : 4;
    uint* pu = p3;
    for (int i = (int)((p4 & 0x3ffffff) << 4); i != 0; --i)
      *pu++ = 0;
    int iVar5 = 0;
    for (int i = 0; (iVar5 = (int)p2), i != 0; --i) {
      *(uint8_t*)pu = 0;
      pu = (uint*)((int)pu + 1);
    }
    do {
      uint row = 0;
      if (local_c != 0) {
        uint* rowBase = p3;
        do {
          uint col = 0;
          if (local_8 != 0) {
            uint* cell = rowBase;
            do {
              local_10 = FUN_0062d760(iVar5, cell);
              if (local_10 < 0) return local_10;
              iVar5 = *(int*)((uint8_t*)iVar5 + 0xc);
              ++col;
              ++cell;
            } while (col < local_8);
          }
          if (col < uVar2) {
            for (int k = (int)(uVar2 - col); k != 0; --k)
              iVar5 = *(int*)((uint8_t*)iVar5 + 0xc);
          }
          ++row;
          rowBase += 4;
        } while (row < local_c);
      }
      if (row < uVar1) {
        for (int k = (int)(uVar1 - row); k != 0; --k) {
          if (uVar2 != 0)
            for (uint j = uVar2; j != 0; --j)
              iVar5 = *(int*)((uint8_t*)iVar5 + 0xc);
        }
      }
      --p4;
      p3 += 0x10;
    } while (p4 != 0);
  }
  return local_10;
}

// 0x62d96b — observed shape: int(int,void*,void*,int); same 2D walk as 0x62d7ba but cell stride 4
int FUN_0062d96b(uint p1, void* p2, uint* p3, int p4) {
  int local_10 = 0;
  if (p4 != 0) {
    uint uVar1 = *(uint*)((uint8_t*)p1 + 0x14);
    uint uVar2 = *(uint*)((uint8_t*)p1 + 0x18);
    uint local_c = (uVar1 < 5) ? uVar1 : 4;
    uint local_8 = (uVar2 < 5) ? uVar2 : 4;
    int iVar5 = (int)p2;
    do {
      uint row = 0;
      if (local_c != 0) {
        uint* rowBase = p3;
        do {
          uint col = 0;
          if (local_8 != 0) {
            uint* cell = rowBase;
            do {
              local_10 = FUN_0062d704(iVar5, (int)*cell);
              if (local_10 < 0) return local_10;
              iVar5 = *(int*)((uint8_t*)iVar5 + 0xc);
              ++col;
              cell += 4;
            } while (col < local_8);
          }
          if (col < uVar2) {
            for (int k = (int)(uVar2 - col); k != 0; --k)
              iVar5 = *(int*)((uint8_t*)iVar5 + 0xc);
          }
          ++row;
          rowBase += 1;
        } while (row < local_c);
      }
      if (row < uVar1) {
        for (int k = (int)(uVar1 - row); k != 0; --k) {
          if (uVar2 != 0)
            for (uint j = uVar2; j != 0; --j)
              iVar5 = *(int*)((uint8_t*)iVar5 + 0xc);
        }
      }
      --p4;
      p3 += 0x10;
    } while (p4 != 0);
  }
  return local_10;
}

// 0x62da3c — observed shape: int(int,void*,void*,uint); zero-fill then 2D walk with FUN_0062d760, cell stride 4
int FUN_0062da3c(uint p1, void* p2, uint* p3, uint p4) {
  int local_10 = 0;
  if (p4 != 0) {
    uint uVar1 = *(uint*)((uint8_t*)p1 + 0x14);
    uint uVar2 = *(uint*)((uint8_t*)p1 + 0x18);
    uint local_c = (uVar1 < 5) ? uVar1 : 4;
    uint local_8 = (uVar2 < 5) ? uVar2 : 4;
    uint* pu = p3;
    for (int i = (int)((p4 & 0x3ffffff) << 4); i != 0; --i)
      *pu++ = 0;
    int iVar5 = 0;
    for (int i = 0; (iVar5 = (int)p2), i != 0; --i) {
      *(uint8_t*)pu = 0;
      pu = (uint*)((int)pu + 1);
    }
    do {
      uint row = 0;
      if (local_c != 0) {
        uint* rowBase = p3;
        do {
          uint col = 0;
          if (local_8 != 0) {
            uint* cell = rowBase;
            do {
              local_10 = FUN_0062d760(iVar5, cell);
              if (local_10 < 0) return local_10;
              iVar5 = *(int*)((uint8_t*)iVar5 + 0xc);
              ++col;
              cell += 4;
            } while (col < local_8);
          }
          if (col < uVar2) {
            for (int k = (int)(uVar2 - col); k != 0; --k)
              iVar5 = *(int*)((uint8_t*)iVar5 + 0xc);
          }
          ++row;
          rowBase += 1;
        } while (row < local_c);
      }
      if (row < uVar1) {
        for (int k = (int)(uVar1 - row); k != 0; --k) {
          if (uVar2 != 0)
            for (uint j = uVar2; j != 0; --j)
              iVar5 = *(int*)((uint8_t*)iVar5 + 0xc);
        }
      }
      --p4;
      p3 += 0x10;
    } while (p4 != 0);
  }
  return local_10;
}

// 0x62db1c — observed shape: int(int,int,int*,int); per-element null check, else FUN_0062d704 at row<<4 + *param_3 stride 4
int FUN_0062db1c(uint p1, uint p2, int* p3, int p4) {
  int local_c = 0;
  if (p4 != 0) {
    uint uVar1 = *(uint*)((uint8_t*)p1 + 0x14);
    uint uVar2 = *(uint*)((uint8_t*)p1 + 0x18);
    uint local_8 = (uVar1 < 5) ? uVar1 : 4;
    uint colCap = (uVar2 < 5) ? uVar2 : 4;
    int iVar6 = (int)p2;
    do {
      if (*p3 == 0) {
        if (uVar1 != 0) {
          uint rem = uVar1;
          do {
            if (uVar2 != 0) {
              for (uint j = uVar2; j != 0; --j)
                iVar6 = *(int*)((uint8_t*)iVar6 + 0xc);
            }
            --rem;
          } while (rem != 0);
        }
      } else {
        uint uVar4 = 0;
        uint row = 0;
        if (local_8 != 0) {
          do {
            uVar4 = 0;
            if (colCap != 0) {
              int off = (int)(row << 4);
              do {
                local_c = FUN_0062d704(iVar6, *(uint*)((uint8_t*)*p3 + off));
                if (local_c < 0) return local_c;
                iVar6 = *(int*)((uint8_t*)iVar6 + 0xc);
                ++uVar4;
                off += 4;
              } while (uVar4 < colCap);
            }
            if (uVar4 < uVar2) {
              for (int k = (int)(uVar2 - uVar4); k != 0; --k)
                iVar6 = *(int*)((uint8_t*)iVar6 + 0xc);
            }
            uVar4 = row + 1;
            row = uVar4;
          } while (uVar4 < local_8);
        }
        if (uVar4 < uVar1) {
          for (int k = (int)(uVar1 - uVar4); k != 0; --k) {
            if (uVar2 != 0)
              for (uint j = uVar2; j != 0; --j)
                iVar6 = *(int*)((uint8_t*)iVar6 + 0xc);
          }
        }
      }
      --p4;
      ++p3;
    } while (p4 != 0);
  }
  return local_c;
}

// 0x62dc0a — observed shape: int(int,int,int*,int); null element walks list skipping uVar2 x uVar1 nodes, else zero 16 dwords then FUN_0062d760
int FUN_0062dc0a(uint p1, uint p2, int* p3, int p4) {
  int local_c = 0;
  if (p4 != 0) {
    uint uVar1 = *(uint*)((uint8_t*)p1 + 0x18);
    uint uVar2 = *(uint*)((uint8_t*)p1 + 0x14);
    uint local_8 = (uVar2 < 5) ? uVar2 : 4;
    uint colCap = (uVar1 < 5) ? uVar1 : 4;
    int iVar5 = (int)p2;
    do {
      if ((void*)*p3 == nullptr) {
        if (uVar2 != 0) {
          uint rem = uVar2;
          do {
            if (uVar1 != 0) {
              for (uint j = uVar1; j != 0; --j)
                iVar5 = *(int*)((uint8_t*)iVar5 + 0xc);
            }
            --rem;
          } while (rem != 0);
        }
      } else {
        uint* pu = (uint*)*p3;
        for (int i = 0x10; i != 0; --i)
          *pu++ = 0;
        uint uVar7 = 0;
        uint row = 0;
        if (local_8 != 0) {
          do {
            uVar7 = 0;
            if (colCap != 0) {
              int off = (int)(row << 4);
              do {
                local_c = FUN_0062d760(iVar5, (uint8_t*)(uint)(*p3 + off));
                if (local_c < 0) return local_c;
                iVar5 = *(int*)((uint8_t*)iVar5 + 0xc);
                ++uVar7;
                off += 4;
              } while (uVar7 < colCap);
            }
            if (uVar7 < uVar1) {
              for (int k = (int)(uVar1 - uVar7); k != 0; --k)
                iVar5 = *(int*)((uint8_t*)iVar5 + 0xc);
            }
            uVar7 = row + 1;
            row = uVar7;
          } while (uVar7 < local_8);
        }
        if (uVar7 < uVar2) {
          for (int k = (int)(uVar2 - uVar7); k != 0; --k) {
            if (uVar1 != 0)
              for (uint j = uVar1; j != 0; --j)
                iVar5 = *(int*)((uint8_t*)iVar5 + 0xc);
          }
        }
      }
      --p4;
      ++p3;
    } while (p4 != 0);
  }
  return local_c;
}

// 0x62dcfa — observed shape: int(int,int,int*,int); like 0x62db1c but offset row<<2 and stride +0x10
int FUN_0062dcfa(uint p1, uint p2, int* p3, int p4) {
  int local_c = 0;
  if (p4 != 0) {
    uint uVar1 = *(uint*)((uint8_t*)p1 + 0x14);
    uint uVar2 = *(uint*)((uint8_t*)p1 + 0x18);
    uint local_8 = (uVar1 < 5) ? uVar1 : 4;
    uint colCap = (uVar2 < 5) ? uVar2 : 4;
    int iVar5 = (int)p2;
    do {
      if (*p3 == 0) {
        if (uVar1 != 0) {
          uint rem = uVar1;
          do {
            if (uVar2 != 0) {
              for (uint j = uVar2; j != 0; --j)
                iVar5 = *(int*)((uint8_t*)iVar5 + 0xc);
            }
            --rem;
          } while (rem != 0);
        }
      } else {
        uint uVar4 = 0;
        uint row = 0;
        if (local_8 != 0) {
          do {
            uVar4 = 0;
            if (colCap != 0) {
              int off = (int)(row << 2);
              do {
                local_c = FUN_0062d704(iVar5, *(uint*)((uint8_t*)*p3 + off));
                if (local_c < 0) return local_c;
                iVar5 = *(int*)((uint8_t*)iVar5 + 0xc);
                ++uVar4;
                off += 0x10;
              } while (uVar4 < colCap);
            }
            if (uVar4 < uVar2) {
              for (int k = (int)(uVar2 - uVar4); k != 0; --k)
                iVar5 = *(int*)((uint8_t*)iVar5 + 0xc);
            }
            uVar4 = row + 1;
            row = uVar4;
          } while (uVar4 < local_8);
        }
        if (uVar4 < uVar1) {
          for (int k = (int)(uVar1 - uVar4); k != 0; --k) {
            if (uVar2 != 0)
              for (uint j = uVar2; j != 0; --j)
                iVar5 = *(int*)((uint8_t*)iVar5 + 0xc);
          }
        }
      }
      --p4;
      ++p3;
    } while (p4 != 0);
  }
  return local_c;
}

// 0x62dde8 — observed shape: int(int,int,int*,int); like 0x62dc0a but offset row<<2 and stride +0x10
int FUN_0062dde8(uint p1, uint p2, int* p3, int p4) {
  int local_c = 0;
  if (p4 != 0) {
    uint uVar1 = *(uint*)((uint8_t*)p1 + 0x18);
    uint uVar2 = *(uint*)((uint8_t*)p1 + 0x14);
    uint local_8 = (uVar2 < 5) ? uVar2 : 4;
    uint colCap = (uVar1 < 5) ? uVar1 : 4;
    int iVar6 = (int)p2;
    do {
      if ((void*)*p3 == nullptr) {
        if (uVar2 != 0) {
          uint rem = uVar2;
          do {
            if (uVar1 != 0) {
              for (uint j = uVar1; j != 0; --j)
                iVar6 = *(int*)((uint8_t*)iVar6 + 0xc);
            }
            --rem;
          } while (rem != 0);
        }
      } else {
        uint* pu = (uint*)*p3;
        for (int i = 0x10; i != 0; --i)
          *pu++ = 0;
        uint uVar5 = 0;
        uint row = 0;
        if (local_8 != 0) {
          do {
            uVar5 = 0;
            if (colCap != 0) {
              int off = (int)(row << 2);
              do {
                local_c = FUN_0062d760(iVar6, (uint8_t*)(uint)(*p3 + off));
                if (local_c < 0) return local_c;
                iVar6 = *(int*)((uint8_t*)iVar6 + 0xc);
                ++uVar5;
                off += 0x10;
              } while (uVar5 < colCap);
            }
            if (uVar5 < uVar1) {
              for (int k = (int)(uVar1 - uVar5); k != 0; --k)
                iVar6 = *(int*)((uint8_t*)iVar6 + 0xc);
            }
            uVar5 = row + 1;
            row = uVar5;
          } while (uVar5 < local_8);
        }
        if (uVar5 < uVar2) {
          for (int k = (int)(uVar2 - uVar5); k != 0; --k) {
            if (uVar1 != 0)
              for (uint j = uVar1; j != 0; --j)
                iVar6 = *(int*)((uint8_t*)iVar6 + 0xc);
          }
        }
      }
      --p4;
      ++p3;
    } while (p4 != 0);
  }
  return local_c;
}

// 0x62deda — observed shape: void(int,int,int,int); 1D walk over columns capped at 4, FUN_0062d704 on *(param_3+uVar3*4)
void FUN_0062deda(uint p1, int p2, int p3, int p4) {
  if (p4 != 0) {
    uint uVar1 = *(uint*)((uint8_t*)p1 + 0x14);
    uint colCap = (uVar1 < 5) ? uVar1 : 4;
    do {
      uint col = 0;
      if (colCap != 0) {
        do {
          int rc = FUN_0062d704(p2, *(uint*)((uint8_t*)p3 + col * 4));
          if (rc < 0) return;
          p2 = *(int*)((uint8_t*)p2 + 0xc);
          ++col;
        } while (col < colCap);
      }
      if (col < uVar1) {
        for (int k = (int)(uVar1 - col); k != 0; --k)
          p2 = *(int*)((uint8_t*)p2 + 0xc);
      }
      --p4;
      p3 += 0x10;
    } while (p4 != 0);
  }
}

// 0x62df4b — observed shape: int(int,int,void*,uint); zero-fill (param_4&0xfffffff)<<2 dwords then 1D walk with FUN_0062d760 stride 1
int FUN_0062df4b(uint p1, int p2, uint* p3, uint p4) {
  int result = 0;
  if (p4 != 0) {
    uint uVar1 = *(uint*)((uint8_t*)p1 + 0x14);
    uint colCap = (uVar1 < 5) ? uVar1 : 4;
    uint* pu = p3;
    for (int i = (int)((p4 & 0xfffffff) << 2); i != 0; --i)
      *pu++ = 0;
    for (int i = 0; i != 0; --i) {
      *(uint8_t*)pu = 0;
      pu = (uint*)((int)pu + 1);
    }
    do {
      uint col = 0;
      if (colCap != 0) {
        uint* cell = p3;
        do {
          result = FUN_0062d760(p2, cell);
          if (result < 0) return result;
          p2 = *(int*)((uint8_t*)p2 + 0xc);
          ++col;
          ++cell;
        } while (col < colCap);
      }
      if (col < uVar1) {
        for (int k = (int)(uVar1 - col); k != 0; --k)
          p2 = *(int*)((uint8_t*)p2 + 0xc);
      }
      --p4;
      p3 += 4;
    } while (p4 != 0);
  }
  return result;
}


// 0x62dfd6 — observed shape: int(int*,int*,int*,uint); marshals node list from a descriptor blob (kinds 1..5)
int FUN_0062dfd6_recon(int* param_1, int* param_2, int* param_3, uint param_4, void* self) {
  int* piVar2 = (int*)*param_1;
  int iVar3 = *piVar2;
  int local_8 = piVar2[4];
  uint uVar8 = 0;
  int iVar4 = piVar2[1];
  int local_c = 0;

  if ((param_4 != 0) || (local_8 == 0)) local_8 = 1;
  if (iVar4 < 0) return -0x7fffbffb;
  if (iVar4 >= 4) {
    if (iVar4 == 4) {
      if (iVar3 == 4) {
        while (local_8 != 0 && *param_2 != 0) {
          char* pcVar9 = *(char**)*param_3;
          char* pcVar6 = nullptr;
          int32_t pcVar7 = 0;
          if (pcVar9 != nullptr) {
            FUN_0062a46a((uint8_t*)self + 0x10);
            char* scan = pcVar9;
            char c;
            do { c = *scan; ++scan; } while (c != '\0');
            pcVar7 = (int32_t)((intptr_t)scan + (1 - (intptr_t)(pcVar9 + 1)));
            pcVar6 = (char*)FUN_0065aaac((void*)(uintptr_t)pcVar7, 1);
            if (pcVar6 == nullptr) {
              FUN_0060d2b8();
              return -0x7ff8fff2;
            }
            char* dst = pcVar6;
            for (uVar8 = (uint)pcVar7 >> 2; uVar8 != 0; --uVar8) {
              *(uint32_t*)dst = *(uint32_t*)pcVar9;
              pcVar9 += 4;
              dst += 4;
            }
            for (uVar8 = (uint)pcVar7 & 3; uVar8 != 0; --uVar8) {
              *dst++ = *pcVar9++;
            }
            FUN_0060d2b8();
          }
          *(char**)(*(int*)(*param_2 + 8) + 0x18) = pcVar6;
          *(int32_t*)(*(int*)(*param_2 + 8) + 0x1c) = pcVar7;
          *param_3 = *param_3 + 4;
          --local_8;
          *param_2 = *(int*)(*param_2 + 0xc);
        }
      } else {
        while (local_8 != 0 && *param_2 != 0) {
          *param_3 = *param_3 + 4;
          --local_8;
          *param_2 = *(int*)(*param_2 + 0xc);
        }
      }
      *param_1 = *param_1 + 0x14;
      return 0;
    }
    if (iVar4 == 5) {
      uint uVar5 = piVar2[5];
      *param_1 = (int)(piVar2 + 6);
      for (;;) {
        if (local_8 == 0) return local_c;
        param_4 = 0;
        *param_1 = (int)(piVar2 + 6);
        if (uVar5 != 0) {
          do {
            local_c = FUN_0062dfd6_recon(param_1, param_2, param_3, 0, self);
            if (local_c < 0) return local_c;
            ++param_4;
          } while (param_4 < uVar5);
        }
        --local_8;
      }
    }
    return -0x7fffbffb;
  }

  {
    uint uVar5 = piVar2[6] * piVar2[5] * local_8;
    if (iVar3 == 1) {
      if (uVar5 != 0) {
        do {
          if (*param_2 == 0) break;
          iVar3 = uVar8 * 4;
          ++uVar8;
          *(uint32_t*)(*(int*)(*param_2 + 8) + 0x18) = (uint32_t)(*(int*)(*param_3 + iVar3) != 0);
          *param_2 = *(int*)(*param_2 + 0xc);
        } while (uVar8 < uVar5);
      }
      *param_3 = *param_3 + uVar5 * 4;
    } else if (iVar3 == 2) {
      uVar8 = 0;
      if (uVar5 != 0) {
        do {
          if (*param_2 == 0) break;
          *(uint32_t*)(*(int*)(*param_2 + 8) + 0x18) = *(uint32_t*)(*param_3 + uVar8 * 4);
          ++uVar8;
          *param_2 = *(int*)(*param_2 + 0xc);
        } while (uVar8 < uVar5);
      }
      *param_3 = *param_3 + uVar5 * 4;
    } else {
      if (iVar3 != 3) return -0x7fffbffb;
      uVar8 = 0;
      if (uVar5 != 0) {
        do {
          if (*param_2 == 0) break;
          *(double*)(*(int*)(*param_2 + 8) + 0x18) = (double)*(float*)(*param_3 + uVar8 * 4);
          ++uVar8;
          *param_2 = *(int*)(*param_2 + 0xc);
        } while (uVar8 < uVar5);
      }
      *param_3 = *param_3 + uVar5 * 4;
    }
    *param_1 = *param_1 + 0x1c;
    return 0;
  }
}

// 0x62e245 — observed shape: int(int*,int*,int*,uint); inverse marshalling of 0x62dfd6 (kinds 1..5)
int FUN_0062e245_recon(int* param_1, int* param_2, int* param_3, uint param_4, void* self) {
  int* piVar1 = (int*)*param_1;
  int local_8 = 0;
  int iVar2 = piVar1[1];
  int iVar3 = *piVar1;
  int iVar6 = piVar1[4];

  (void)self;
  if ((param_4 != 0) || (iVar6 == 0)) iVar6 = 1;
  if (iVar2 < 0) return -0x7fffbffb;
  if (iVar2 >= 4) {
    if (iVar2 == 4) {
      if (iVar3 == 4) {
        while (iVar6 != 0 && *param_2 != 0) {
          *(uint32_t*)*param_3 = *(uint32_t*)(*(int*)(*param_2 + 8) + 0x18);
          *param_3 = *param_3 + 4;
          --iVar6;
          *param_2 = *(int*)(*param_2 + 0xc);
        }
      } else {
        while (iVar6 != 0 && *param_2 != 0) {
          *(uint32_t*)*param_3 = 0;
          *param_3 = *param_3 + 4;
          --iVar6;
          *param_2 = *(int*)(*param_2 + 0xc);
        }
      }
      *param_1 = *param_1 + 0x14;
      return 0;
    }
    if (iVar2 == 5) {
      uint uVar5 = piVar1[5];
      *param_1 = (int)(piVar1 + 6);
      for (;;) {
        if (iVar6 == 0) return local_8;
        param_4 = 0;
        *param_1 = (int)(piVar1 + 6);
        if (uVar5 != 0) {
          do {
            local_8 = FUN_0062e245_recon(param_1, param_2, param_3, 0, self);
            if (local_8 < 0) return local_8;
            ++param_4;
          } while (param_4 < uVar5);
        }
        --iVar6;
      }
    }
    return -0x7fffbffb;
  }

  {
    uint uVar5 = piVar1[6] * piVar1[5] * iVar6;
    if (iVar3 == 1) {
      uint uVar4 = 0;
      if (uVar5 != 0) {
        do {
          if (*param_2 == 0) break;
          *(uint32_t*)(*param_3 + uVar4 * 4) = (uint32_t)(*(int*)(*(int*)(*param_2 + 8) + 0x18) != 0);
          ++uVar4;
          *param_2 = *(int*)(*param_2 + 0xc);
        } while (uVar4 < uVar5);
      }
      *param_3 = *param_3 + uVar5 * 4;
    } else if (iVar3 == 2) {
      uint uVar4 = 0;
      if (uVar5 != 0) {
        do {
          if (*param_2 == 0) break;
          *(uint32_t*)(*param_3 + uVar4 * 4) = *(uint32_t*)(*(int*)(*param_2 + 8) + 0x18);
          ++uVar4;
          *param_2 = *(int*)(*param_2 + 0xc);
        } while (uVar4 < uVar5);
      }
      *param_3 = *param_3 + uVar5 * 4;
    } else {
      if (iVar3 != 3) return -0x7fffbffb;
      uint uVar4 = 0;
      if (uVar5 != 0) {
        do {
          if (*param_2 == 0) break;
          *(float*)(*param_3 + uVar4 * 4) = (float)*(double*)(*(int*)(*param_2 + 8) + 0x18);
          ++uVar4;
          *param_2 = *(int*)(*param_2 + 0xc);
        } while (uVar4 < uVar5);
      }
      *param_3 = *param_3 + uVar5 * 4;
    }
    *param_1 = *param_1 + 0x1c;
    return 0;
  }
}

// 0x62e426 — observed shape: void(); receiver in ECX; frees slot +8 via FUN_0062e45b(3) then drains list at +0xc
void FUN_0062e426_recon(void* self) {
  if (*(int*)((uint8_t*)self + 8) != 0) {
    FUN_0062e45b(3);
    *(uint32_t*)((uint8_t*)self + 8) = 0;
  }
  while (*(int*)((uint8_t*)self + 0xc) != 0) {
    int iVar1 = *(int*)((uint8_t*)self + 0xc);
    *(uint32_t*)((uint8_t*)self + 0xc) = *(uint32_t*)((uint8_t*)iVar1 + 0xc);
    *(uint32_t*)((uint8_t*)iVar1 + 0xc) = 0;
    FUN_0062a495(1);
  }
}

// 0x62e45b — observed shape: void(byte); receiver in ECX; scalar/array deleting destructor
void FUN_0062e45b(byte param_1, void* self) {
  if ((param_1 & 2) == 0) {
    FUN_0062e426_recon(self);
    if ((param_1 & 1) != 0) operator_delete(self);
  } else {
    FUN_00412770(self, 0x20, *(void**)((uint8_t*)self - 4), (void*)&FUN_0062e426_recon);
    if ((param_1 & 1) != 0) operator_delete((uint8_t*)self - 4);
  }
}

// 0x62e4a9 — observed shape: void(); receiver in ECX; init tag 0
void FUN_0062e4a9_recon(uint32_t* in_ECX) {
  in_ECX[4] = 0xffffffff;
  in_ECX[7] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[1] = (uint32_t)(uintptr_t)in_ECX;
  *in_ECX = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xd] = 0;
}

// 0x62e4c9 — observed shape: void(); receiver in ECX; init tag 1
void FUN_0062e4c9_recon(uint32_t* in_ECX) {
  in_ECX[4] = 0xffffffff;
  in_ECX[7] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[1] = (uint32_t)(uintptr_t)in_ECX;
  *in_ECX = 1;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
}

// 0x62e4ea — observed shape: void(); receiver in ECX; init tag 2
void FUN_0062e4ea_recon(uint32_t* in_ECX) {
  in_ECX[4] = 0xffffffff;
  in_ECX[7] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[1] = (uint32_t)(uintptr_t)in_ECX;
  *in_ECX = 2;
  in_ECX[10] = 0;
}

// 0x62e508 — observed shape: void(); receiver in ECX; unlinks children at +0x28 recursively, then FUN_0062e426
void FUN_0062e508_recon(void* self) {
  int iVar1 = *(int*)((uint8_t*)self + 0x28);
  while (iVar1 != 0) {
    void* pvVar2 = *(void**)((uint8_t*)self + 0x28);
    *(uint32_t*)((uint8_t*)self + 0x28) = *(uint32_t*)((uint8_t*)pvVar2 + 0x28);
    *(uint32_t*)((uint8_t*)pvVar2 + 0x28) = 0;
    FUN_0062e508_recon(pvVar2);
    operator_delete(pvVar2);
    iVar1 = *(int*)((uint8_t*)self + 0x28);
  }
  FUN_0062e426_recon(self);
}

// 0x62e53e — observed shape: void(byte); receiver in ECX; deleting destructor forwarding to FUN_0062e508
void FUN_0062e53e_recon(byte param_1, void* self) {
  FUN_0062e508_recon(self);
  if ((param_1 & 1) != 0) operator_delete(self);
}

// 0x62e55f — observed shape: void(); receiver in ECX; init tag 3
void FUN_0062e55f_recon(uint32_t* in_ECX) {
  in_ECX[4] = 0xffffffff;
  in_ECX[7] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[1] = (uint32_t)(uintptr_t)in_ECX;
  *in_ECX = 3;
  in_ECX[6] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
}
