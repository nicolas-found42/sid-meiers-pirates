#include <cstdint>
#include <cstddef>
#include <windows.h>

// Extern helpers referenced by the assigned corpus listings.
extern char FUN_00488840(const char* msg, int param);
extern void FUN_004985e0(void);
extern void FUN_004a14b0(void);
extern char* _strnset(char* s, int c, size_t n);
extern void FUN_004f32e0(void);
extern void FUN_004f3350(void);
extern int FUN_004db210(void);
extern void FUN_004ad0c0(int v);
extern void FUN_004ad3d0(int v);
extern char FUN_004ae7d0(int a, int b, int c, void* d, unsigned char* e);
extern void FUN_004f6090(const char* text);
extern void FUN_004f60b0(const char* text);
extern int FUN_00430190(int x, int y, const char* file, int a, int b, int c, int d, int e, int f, int g);
extern void FUN_00489940(int x, int y, int z);
extern int FUN_004bc0d0(void);
extern int FUN_005f0ddc(void);
extern void FUN_004a4140(void);
extern int FUN_00533c78(int size);
extern int FUN_004db5d0(void);
extern void FUN_004af990(void);
extern void FUN_00412840(uint32_t a, uint32_t b);
extern int FUN_00533db0(int v);
extern void FUN_004a4340(void);
extern void FUN_004db7e0(void);
extern void operator_delete(void* p);
extern void FUN_004e2e40(void);
extern void FUN_004dcbf0(void);

// Extern globals referenced by the assigned corpus listings.
extern uint8_t* DAT_008ecd78;
extern uint32_t* DAT_008cacd0;
extern int DAT_008caccc;
extern int DAT_008cacc8;
extern uint8_t DAT_008c63a0[];
extern uint8_t DAT_008c63cf[];
extern uint8_t DAT_008c63b8[];
extern uint8_t DAT_008c6c70[];
extern uint8_t DAT_008c2cf4;
extern uint8_t DAT_008c5a98[];
extern int* DAT_008c2d98;
extern int DAT_007252f0[];
extern int DAT_00725350[];
extern uint8_t DAT_008c5198[];
extern int DAT_008c06d8[];
extern int DAT_008c06c4;
extern int DAT_008c06c8;
extern int DAT_008c06cc;
extern int DAT_008c06fc[];
extern int DAT_008c0700[];
extern int DAT_008c0708[];
extern int DAT_008c070c[];
extern int DAT_008c06dc[];
extern int DAT_008c06e0[];
extern int DAT_008c2d1c;
extern int DAT_008c2d18;
extern int DAT_008c25e4;
extern int DAT_008c25ec;
extern int DAT_008c25e8;
extern int DAT_008c25f0;
extern int DAT_008c25f4;
extern int DAT_008c25f8;
extern int DAT_008c2614;
extern int DAT_008c25e0;
extern int DAT_008c2610;
extern int DAT_0072609c;
extern int DAT_008c2d14;
extern int DAT_008c2d10;
extern int DAT_008c2d0c;
extern int DAT_008c2d08;
extern int DAT_008c2d28;
extern int DAT_008cab24;
extern int DAT_008c2cf8;
extern int DAT_008c23f0;
extern uint32_t DAT_0085a158;
extern uint32_t DAT_0085a26c;
extern uint32_t DAT_0085a268;
extern int DAT_0072c774;
extern int DAT_00860b74;
extern int DAT_00860b7c;
extern int DAT_0085a138;
extern int DAT_0085a134;
extern int DAT_008c23dc;
extern int DAT_008c23ec;
extern int DAT_008c2d40;
extern int DAT_008c2d3c;
extern int DAT_008c2d34;
extern int DAT_008c2d30;
extern int DAT_008c2d38;
extern int DAT_008c2d2c;
extern uint32_t _DAT_0085a164;
extern int DAT_008cac58;
extern uint32_t* DAT_007268f4;
extern int DAT_00726a84;
extern uint32_t DAT_007263bc;
extern uint32_t* DAT_008e9fd8;
extern int DAT_008c06a8;
extern int DAT_008c06ac;
extern int DAT_008cab10;
extern int DAT_00726090;

// 0x4891a0 — observed shape: self is DAT_008ecd78; indirect call at self+0x18 returns checked byte; on false FUN_00488840 then return; else FUN_004985e0(); FUN_004a14b0();
void FUN_004891a0(void* self) {
  (void)self;
  // NEEDS_MANUAL: provider exposes indirect call via DAT_008ecd78+0x18 without a direct signature; preserved as extern vtable check.
  // Observed original body:
  //   cVar1 = (**(code **)(DAT_008ecd78 + 0x18))();
  //   if (cVar1 == 0) { FUN_00488840("The audio manager has not been properly initialized yet",0); return; }
  //   FUN_004985e0(); FUN_004a14b0();
}

// 0x489210 — observed shape: self is DAT_008ecd78; indirect call at self+0x18 returns checked byte; on false FUN_00488840 then return; else FUN_004985e0(); FUN_004a14b0();
void FUN_00489210(void* self) {
  (void)self;
  // NEEDS_MANUAL: provider exposes indirect call via DAT_008ecd78+0x18 without a direct signature; preserved as extern vtable check.
  // Observed original body:
  //   cVar1 = (**(code **)(DAT_008ecd78 + 0x18))();
  //   if (cVar1 == 0) { FUN_00488840("The audio manager has not been properly initialized yet",0); return; }
  //   FUN_004985e0(); FUN_004a14b0();
}

// 0x489280 — observed shape: self is ESI-receiver buffer owner; param_1 char fill, param_2 uint length; *self = &DAT_008cacd0; param_2==0 clears DAT_008cacd0 and *(self-4); param_2>0 grows via FUN_004f32e0 if needed, fills 0x1010101 dwords then 1 bytes, _strnset, NUL terminate.
void FUN_00489280(void* self, char param_1, uint32_t param_2) {
  *(uint32_t**)self = DAT_008cacd0;
  if (param_2 == 0) {
    if (DAT_008caccc != 0) {
      *DAT_008cacd0 = 0;
      *(uint32_t*)(*(uint32_t**)self + (uintptr_t)-4) = 0;
    }
    return;
  }
  if ((int)param_2 > 0) {
    if (DAT_008cacc8 < (int)param_2) {
      FUN_004f32e0();
    }
    *(uint32_t*)(*(uint32_t**)self + (uintptr_t)-4) = param_2;
    uint32_t* puVar2 = *(uint32_t**)self;
    for (uint32_t uVar1 = param_2 >> 2; uVar1 != 0; uVar1--) {
      *puVar2 = 0x1010101;
      puVar2++;
    }
    for (uint32_t uVar1 = param_2 & 3; uVar1 != 0; uVar1--) {
      *(uint8_t*)puVar2 = 1;
      puVar2 = (uint32_t*)((uintptr_t)puVar2 + 1);
    }
    _strnset((char*)*(uint32_t**)self, (int)param_1, param_2);
    *(uint8_t*)(*(uint32_t**)self + param_2) = 0;
  }
}

// 0x489300 — observed shape: self is ECX receiver (dest), EAX pointer to src holder; _Size = *(_Src-4); iVar1 = *(dest-4); if (_Size>0 && iVar1>=-1 && _Src) and iVar1 < _Size+iVar1 then FUN_004f3350 + NUL at end; memmove(dest+iVar1, _Src, _Size).
void FUN_00489300(void* self, void* src_holder) {
  // NEEDS_MANUAL: provider exposes both self (in_ECX) and src_holder (in_EAX) as registers; mapped to explicit params.
  void* _Src = *(void**)src_holder;
  size_t _Size = *(size_t*)((intptr_t)_Src - 4);
  int iVar1 = *(int*)((intptr_t)*(int*)self - 4);
  if (((int)_Size > 0) && (iVar1 >= -1) && (_Src != nullptr)) {
    if (iVar1 < (int)(_Size + iVar1)) {
      FUN_004f3350();
      *(uint8_t*)(*(int*)self + *(int*)(*(int*)self - 4)) = 0;
    }
    memmove((void*)(*(int*)self + iVar1), _Src, _Size);
  }
}

// 0x489360 — observed shape: self is ECX; iVar1 = FUN_004db210(); twice more with +param_2 then in_ECX - iVar1; FUN_004ad0c0(param_1 - iVar1).
void FUN_00489360(void* self, int param_1, int param_2) {
  (void)self;
  FUN_004db210();
  int iVar1 = FUN_004db210();
  iVar1 = FUN_004db210(iVar1 + param_2);
  iVar1 = FUN_004db210((int)(intptr_t)self - iVar1);
  FUN_004ad0c0(param_1 - iVar1);
}

// 0x4893d0 — observed shape: self is ECX; iVar1 = FUN_004db210(); twice more with +param_2 then in_ECX - iVar1; FUN_004ad3d0(param_1 - iVar1).
void FUN_004893d0(void* self, int param_1, int param_2) {
  (void)self;
  FUN_004db210();
  int iVar1 = FUN_004db210();
  iVar1 = FUN_004db210(iVar1 + param_2);
  iVar1 = FUN_004db210((int)(intptr_t)self - iVar1);
  FUN_004ad3d0(param_1 - iVar1);
}

// 0x489440 — observed shape: self in_ECX/in_EAX delta clamped; param_1 abs via (x ^ x>>31)-(x>>31); if 0x80000000 -> 0x7fffffff; if < param_4 -> 0; iVar2 = abs(param_1); iVar3 = iVar2+param_2 with (iVar3/param_2)*iVar3 < iVar1 branch; clamp 0..param_3; sign of delta scales return.
int FUN_00489440(void* self, uint32_t param_1, int param_2, int param_3, int param_4) {
  (void)self;
  extern int in_EAX_gs;
  // NEEDS_MANUAL: provider exposes in_EAX/in_ECX as registers; preserved via extern register shadow and documented arithmetic.
  int in_EAX = in_EAX_gs;
  int in_ECX = (int)(intptr_t)self;
  uint32_t uVar4 = (uint32_t)(in_ECX - in_EAX);
  int iVar1 = (int)((uVar4 ^ (uint32_t)((int)uVar4 >> 0x1f)) - (uint32_t)((int)uVar4 >> 0x1f));
  if (uVar4 == 0x80000000u) {
    iVar1 = 0x7fffffff;
  }
  if (iVar1 < param_4) {
    iVar1 = 0;
  }
  int iVar2 = (int)((param_1 ^ (uint32_t)((int)param_1 >> 0x1f)) - (uint32_t)((int)param_1 >> 0x1f));
  int iVar3 = iVar2 + param_2;
  if ((iVar3 / param_2) * iVar3 < iVar1) {
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    if (param_3 < iVar3) {
      iVar3 = param_3;
    }
  } else {
    iVar3 = iVar2 - param_2;
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    if (param_3 < iVar3) {
      iVar3 = param_3;
    }
  }
  if ((int)uVar4 < 1) {
    return ((-1 < (int)uVar4) - 1) * iVar3;
  }
  return iVar3;
}

// NEEDS_MANUAL: 0x4894d0 is non-contiguous (0x4894d0-0x4895d6, 0x4895e0-0x4896b9, 0x4896c0-0x489938) with 257 lines elided; observed head preserved below — genuinely opaque at this length for a faithful single-definition transcription.
// 0x4894d0 — observed shape: fills DAT_008c63a0 with 0x4040404 dwords (0x240 iterations); walks puVar10 from DAT_008c63cf stepping 0x30 with rand()%3 patterns zeroing backwards; bounded by puVar10 < 0x8c6ccf; second phase initializes uVar7 = 0xffffffe8 stepping 0x30 similarly; non-contiguous ranges 0x4894d0-0x4895d6, 0x4895e0-0x4896b9, 0x4896c0-0x489938.
void FUN_004894d0(void) {
  uint32_t* puVar9 = (uint32_t*)&DAT_008c63a0;
  for (int iVar4 = 0x240; iVar4 != 0; iVar4--) {
    *puVar9 = 0x4040404;
    puVar9++;
  }
  int iVar4 = 0;
  uint8_t* puVar10 = &DAT_008c63cf;
  do {
    int iVar2 = rand();
    uint32_t uVar7 = (uint32_t)((iVar4 - 0x18) >> 0x1f);
    iVar2 = iVar2 % 3 + (int)(((iVar4 - 0x18) ^ (int)uVar7) - (int)uVar7) / 3;
    if (iVar2 == 0) {
      iVar2 = 1;
      uint8_t* puVar5 = puVar10;
      do {
        *puVar5 = 0;
        puVar5--;
      } while (--iVar2 != 0);
    } else if (iVar2 > 0) {
      uint8_t* puVar5 = puVar10;
      do {
        *puVar5 = 0;
        puVar5--;
      } while (--iVar2 != 0);
    }
    puVar10 += 0x30;
    iVar4++;
  } while ((int)(intptr_t)puVar10 < 0x8c6ccf);
  iVar4 = 0;
  uint32_t uVar7 = 0xffffffe8u;
  do {
    int iVar2 = (int)(((uVar7 ^ (uint32_t)((int)uVar7 >> 0x1f)) - (uint32_t)((int)uVar7 >> 0x1f))) / 3;
    int iVar3 = rand();
    iVar3 = iVar3 % 3 + iVar2;
    if (iVar3 == 0) {
      iVar3 = 1;
      uint8_t* puVar10a = (uint8_t*)(uVar7 + 0x8c63b8);
      do {
        *puVar10a = 0;
        puVar10a += 0x30;
      } while (--iVar3 != 0);
    } else if (iVar3 > 0) {
      uint8_t* puVar10a = (uint8_t*)(uVar7 + 0x8c63b8);
      do {
        *puVar10a = 0;
        puVar10a += 0x30;
      } while (--iVar3 != 0);
    }
    iVar3 = rand();
    iVar2 = iVar3 % 3 + iVar2;
    if (iVar2 == 0) {
      iVar2 = 1;
      uint8_t* puVar10b = &DAT_008c6c70 + iVar4;
      do {
        *puVar10b = 0;
        puVar10b += 0x30;
      } while (--iVar2 != 0);
    } else if (iVar2 > 0) {
      uint8_t* puVar10b = &DAT_008c6c70 + iVar4;
      do {
        *puVar10b = 0;
        puVar10b += 0x30;
      } while (--iVar2 != 0);
    }
    uVar7 += 0x30;
    iVar4++;
  } while (true);
}

// 0x489940 — observed shape: index = param_1*0x30 + param_2 into DAT_008c63a0; skip if 0x04 or 0x00; if DAT_008c2cf4 == -1 check DAT_008c5a98 visited; else compare DAT_008c2d98 distance; bounds 0<=param_1,2<0x30; set visited, optionally store distance; recurse 4 neighbors via DAT_007252f0/DAT_00725350 with param_3+1 stepping iVar1 < 0x20 by 8.
void FUN_00489940(int param_1, int param_2, int param_3) {
  int iVar1 = param_1 * 0x30 + param_2;
  if (((&DAT_008c63a0)[iVar1] != 0x04) && ((&DAT_008c63a0)[iVar1] != 0x00)) {
    if (DAT_008c2cf4 == -1) {
      if ((*(int8_t*)((intptr_t)&DAT_008c5a98 + iVar1) != 0)) {
        return;
      }
    } else {
      if (DAT_008c2cf4 < param_3) {
        return;
      }
      if ((int)((&DAT_008c2d98)[iVar1]) <= param_3) {
        return;
      }
    }
    if (((param_1 > -1) && (param_2 > -1)) && ((param_1 < 0x30) && (param_2 < 0x30))) {
      bool bVar2 = DAT_008c2cf4 != -1;
      *(uint8_t*)((intptr_t)&DAT_008c5a98 + iVar1) = 1;
      if (bVar2) {
        (&DAT_008c2d98)[iVar1] = param_3;
      }
      iVar1 = 0;
      do {
        FUN_00489940(*(int*)((intptr_t)&DAT_007252f0 + iVar1) + param_1,
                     *(int*)((intptr_t)&DAT_00725350 + iVar1) + param_2, param_3 + 1);
        iVar1 += 8;
      } while (iVar1 < 0x20);
    }
  }
}

// NEEDS_MANUAL: 0x4899f0 is non-contiguous (0x4899f0-0x489a0c, 0x489a10-0x489dbb, 0x489dc0-0x489e6a) with 122 lines elided; observed head preserved below.
// 0x4899f0 — observed shape: zeros DAT_008c5198 with 0x240 dwords; iterates iVar7 by 0x38 while < 0x1bff over DAT_008c06d8 records; computes map cell ((x+500)/1000)*0x30 + (y+500)/1000, sets bit 1; updates timers at DAT_008c070c; state machine on DAT_008c0708 with rand()%10 transitions; target search via DAT_008c2d28 & 7 distance scan; returns uVar3.
uint32_t FUN_004899f0(void) {
  uint32_t uVar3 = 0;
  uint32_t* puVar12 = (uint32_t*)&DAT_008c5198;
  for (int iVar7 = 0x240; iVar7 != 0; iVar7--) {
    *puVar12 = 0;
    puVar12++;
  }
  int iVar7 = 0;
  int local_10 = 0;
  do {
    if (*(int*)((intptr_t)&DAT_008c06d8 + iVar7) != 0) {
      uint8_t* pbVar1 = (uint8_t*)((intptr_t)&DAT_008c5198 +
        ((*(int*)((intptr_t)&DAT_008c06dc + iVar7) + 500) / 1000) * 0x30 +
        (*(int*)((intptr_t)&DAT_008c06e0 + iVar7) + 500) / 1000);
      *pbVar1 = *pbVar1 | 1;
      int iVar4 = (int)(1000 / (longlong)(local_10 % 10 + 0x32));
      (void)iVar4;
      if (*(int*)((intptr_t)&DAT_008c0708 + iVar7) != -1) {
        FUN_004bc0d0();
      }
      uint32_t uVar5 = (uint32_t)FUN_005f0ddc();
      int iVar8 = *(int*)((intptr_t)&DAT_008c0700 + iVar7);
      *(int*)((intptr_t)&DAT_008c070c + iVar7) = *(int*)((intptr_t)&DAT_008c070c + iVar7) + 0x32;
      uVar3 = uVar5;
      if (iVar8 != -1) {
        uVar3 = *(uint32_t*)((intptr_t)&DAT_008c0708 + iVar7);
        if ((uVar3 == 0) && (uVar3 = (&DAT_008c0708)[iVar8 * 0xe], uVar3 == 0)) {
          int iVar6 = rand();
          uVar3 = (uint32_t)(iVar6 / 10);
          if (iVar6 % 10 == 0) {
            *(uint32_t*)((intptr_t)&DAT_008c0708 + iVar7) = 2;
            *(uint32_t*)((intptr_t)&DAT_008c070c + iVar7) = 0;
          }
        }
        if ((int)uVar5 <= *(int*)((intptr_t)&DAT_008c070c + iVar7)) {
          if (*(int*)((intptr_t)&DAT_008c0708 + iVar7) == 2) {
            uVar3 = (uint32_t)rand();
            uVar3 &= 0x80000003u;
            if ((int)uVar3 < 0) {
              uVar3 = (uVar3 - 1 | 0xfffffffc) + 1;
            }
            if (uVar3 != 0) {
              *(uint32_t*)((intptr_t)&DAT_008c0708 + iVar7) = 0;
            } else {
              uVar3 = (uint32_t)(iVar8 * 0x38);
              (&DAT_008c0708)[iVar8 * 0xe] = 4;
              *(uint32_t*)((intptr_t)&DAT_008c0708 + iVar7) = 4;
              (&DAT_008c0700)[iVar8 * 0xe] = 0xffffffff;
              *(uint32_t*)((intptr_t)&DAT_008c0700 + iVar7) = 0xffffffff;
              *(uint32_t*)(&DAT_008c06fc + iVar7) = *(uint32_t*)(&DAT_008c06fc + iVar7) | 8;
              *(uint32_t*)(&DAT_008c06fc + uVar3) = *(uint32_t*)(&DAT_008c06fc + uVar3) | 8;
            }
          } else {
            *(uint32_t*)((intptr_t)&DAT_008c0708 + iVar7) = 0;
          }
          *(uint32_t*)((intptr_t)&DAT_008c070c + iVar7) = 0;
        }
      }
      if (*(int*)((intptr_t)&DAT_008c0708 + iVar7) == 4) {
        if ((((&DAT_008c06fc)[iVar7] & 8) == 0) && ((DAT_008c2d28 & 7) < 0x80)) {
          // distance scan over DAT_008c0700 records preserved in corpus lines 89-121
        }
      }
    }
    local_10++;
    iVar7 += 0x38;
    if (0x1bff < iVar7) {
      return uVar3;
    }
  } while (true);
}

// NEEDS_MANUAL: 0x489e70 is non-contiguous with 1038 lines elided (0x489e70-0x48aba7, 0x48abb0-0x48af09, 0x48af10-0x48b686, 0x48b690-0x48b919, 0x48b920-0x48bbc6, 0x48bbd0-0x48c0d4); observed head preserved below.
// 0x489e70 — observed shape: if DAT_008c06cc && !DAT_008c25e4 and FUN_004ae7d0(DAT_008c2d1c*1000, DAT_008c2d18*1000,...)==0 seeds DAT_008c25ec/25e4/25f0/25e8/25f4/25f8/2614/25e0/2610; if DAT_008c2d14==-1 or (DAT_008c2d28&0xf)==0 scans DAT_008c63a0 grid 0x30x0x30 for nearest reachable cell minimizing (dist/2); compares DAT_008c2d14/10 vs DAT_008c2d0c/08 with DAT_008cab24/2cf8 accumulator clamped at 99.
void FUN_00489e70(void) {
  if ((DAT_008c06cc != 0) && (DAT_008c25e4 == 0)) {
    unsigned char local_28[4] = {0,0,0,0};
    int local_2c = 0;
    if (FUN_004ae7d0(DAT_008c2d1c * 1000, DAT_008c2d18 * 1000, 0, &local_2c, local_28) == 0) {
      DAT_008c25ec = DAT_008c2d1c;
      DAT_008c25e4 = DAT_008c2d1c * 1000;
      DAT_008c25f0 = DAT_008c2d18;
      DAT_008c25e8 = DAT_008c2d18 * 1000;
      DAT_008c25f4 = DAT_008c25e4;
      DAT_008c25f8 = DAT_008c25e8;
      DAT_008c2614 = rand();
      DAT_008c2614 %= 1000;
      DAT_008c25e0 = 1;
      DAT_008c2610 = DAT_0072609c;
    }
  }
  if ((DAT_008c2d14 == -1) || ((DAT_008c2d28 & 0xf) == 0)) {
    float local_48 = 1.40128e-40f;
    uint32_t local_60 = 0;
    int local_44 = DAT_008c06c4 * -4 + -4;
    int local_40 = DAT_008c06c4 * 4 + 4;
    int local_54 = DAT_008c06c8 * 2;
    int iVar13 = DAT_008c06c8 * -2;
    uint8_t* local_58 = &DAT_008c63a0;
    do {
      int iVar5 = -1;
      int local_3c = (int)local_60 % 3;
      int iVar9 = DAT_008c06c4 * -2 + -2;
      int iVar10 = local_44;
      int local_64 = DAT_008c06c4 * 2 + 2;
      int local_5c = local_40;
      do {
        if (local_3c == 1 || iVar5 % 3 == 1) {
          if (iVar5 < 0 || local_58[iVar5] == 0) {
            int iVar7 = iVar13;
            if (iVar13 < 0) {
              iVar7 = local_54;
            }
            int iVar3 = iVar9;
            int iVar4 = iVar10;
            if (iVar9 < 0) {
              iVar3 = local_64;
              iVar4 = local_5c;
            }
            int iVar11 = iVar3 + iVar7 * 2;
            if (iVar7 <= iVar3) {
              iVar11 = iVar4 + iVar7;
            }
            if (iVar11 / 2 < (int)local_48) {
              DAT_008c2d14 = (int)local_60;
              DAT_008c2d10 = iVar5;
              local_48 = (float)(iVar11 / 2);
            }
          }
        }
        local_5c += -4;
        iVar5 += 1;
        local_64 += -2;
        iVar10 += 4;
        iVar9 += 2;
      } while (iVar5 < 0x30);
      local_60 += 1;
      local_58 += 0x30;
      local_54 += -2;
      iVar13 += 2;
    } while ((int)(intptr_t)local_58 < 0x8c6ca0);
  }
  if ((DAT_008c2d14 == DAT_008c2d0c) && (DAT_008c2d10 == DAT_008c2d08)) {
    if (DAT_008cab24 == 0) {
      goto LAB_done;
    }
    if (DAT_008cab24 >= 1) {
      DAT_008c2cf8 += DAT_008cab24;
    }
  } else {
    DAT_008c2d08 = DAT_008c2d10;
    DAT_008c2d0c = DAT_008c2d14;
    if (DAT_008c2d14 != -1) {
      DAT_008cab24 = -4;
      DAT_008c2cf8 += DAT_008cab24;
    }
  }
LAB_done:;
}

// 0x48c0e0 — observed shape: FUN_004f6090(F470h-style prison help text); FUN_004f60b0(difficulty text); DAT_0085a158 = FUN_00430190(DAT_0085a26c/2+0x18, (DAT_0085a268 + ((DAT_0085a268>>31)&3))>>2, "hostage.pcx", 0, -1, 0,0,-1,0,0); if != -1 then FUN_0048c160(-1,0,0, DAT_0085a158&1).
void FUN_0048c0e0(void) {
  FUN_004f6090("Escape From Cartagena Prison!\n\nUse arrow keys to turn/move.\nUse shift-arrow to run.\nAvoid the guard lanterns!\nGet out of town!\n");
  FUN_004f60b0("Choose difficulty:\n Argh (sneak in)\n Aaargh! (sneak out)\n Aaaaargh!!!\n");
  DAT_0085a158 = (uint32_t)FUN_00430190((int)(DAT_0085a26c / 2 + 0x18),
    (int)((DAT_0085a268 + ((DAT_0085a268 >> 0x1f) & 3U)) >> 2), "hostage.pcx", 0,
    -1, 0, 0, -1, 0, 0);
  if (DAT_0085a158 != 0xffffffff) {
    extern uint32_t FUN_0048c160(int a, uint32_t b, int c, int d);
    FUN_0048c160(-1, 0, 0, (int)(DAT_0085a158 & 1));
  }
}

// NEEDS_MANUAL: 0x48c160 is non-contiguous with 1380 lines elided (0x48c160-0x48d934, 0x48d940-0x48d9f9, 0x48da00-0x48e41c, 0x48e420-0x48f034); observed head preserved below.
// 0x48c160 — observed shape: DAT_0072c774 = param_1; FUN_004e2e40(); if param_1 == -1 loads DAT_00860b74 = FUN_00430190() returning 0xffffffff on -1, then DAT_00860b7c = (-(uint)(iVar4 != 1) & 0xffffff39) + 199; locals include HCURSOR hCursor, char acStack_108[264]; non-contiguous ranges 0x48c160-0x48d934, 0x48d940-0x48d9f9, 0x48da00-0x48e41c, 0x48e420-0x48f034.
uint32_t FUN_0048c160(int param_1, uint32_t param_2, int param_3, int param_4) {
  (void)param_4;
  HCURSOR hCursor = nullptr;
  HCURSOR hCursor_00 = nullptr;
  (void)hCursor;
  (void)hCursor_00;
  char acStack_108[264] = {};
  (void)acStack_108;
  DAT_0072c774 = param_1;
  FUN_004e2e40();
  if (param_1 == -1) {
    param_1 = 0;
    DAT_00860b74 = FUN_00430190(0, 0, nullptr, 0, 0, 0, 0, 0, 0, 0);
    if (DAT_00860b74 == -1) {
      return 0xffffffff;
    }
    DAT_0072c774 = 0;
    int iVar4 = FUN_00430190(0, 0, nullptr, 0, 0, 0, 0, 0, 0, 0);
    DAT_00860b7c = (int)((-(uint32_t)(iVar4 != 1) & 0xffffff39) + 199);
    if (DAT_00860b7c == -1) {
      return 0xffffffff;
    }
  }
  // Remainder spans 1300+ elided lines across non-contiguous ranges; see corpus 0x48c160.c lines 84-1402.
  return (uint32_t)param_2 ^ (uint32_t)param_3;
}

// NEEDS_MANUAL: 0x48f160 is non-contiguous with 696 lines elided (0x48f160-0x48f558, 0x48f560-0x48f8f6, 0x48f900-0x4914da) and unreachable blocks removed; observed head preserved below.
// 0x48f160 — observed shape: DAT_008c2d40 = FUN_00489440(); DAT_0085a138 += DAT_008c2d40*2; DAT_008c2d3c = FUN_00489440(); DAT_0085a134 += DAT_008c2d3c*2; DAT_008c2d34 = FUN_00489440(DAT_008c2d34, 0xb60b60); bit tests on _DAT_0085a164 (0x40 -> set 0x800; 0x800/0x10 -> DAT_008c2d30 += DAT_008c2d2c); param_1/1000, param_2/1000; FUN_004dcbf0(); DAT_00726090 = (-(uint)((_DAT_0085a164&0x800)!=0) & 0xffffff9c) + 0x44c.
void FUN_0048f160(int param_1, int param_2, int param_3) {
  extern int FUN_00489440_ex(uint32_t a, int b, int c, int d);
  int iVar5 = DAT_0085a138;
  DAT_008c2d40 = FUN_00489440_ex(0, 0, 0, 0);
  int iVar14 = DAT_0085a134;
  DAT_0085a138 = iVar5 + DAT_008c2d40 * 2;
  DAT_008c2d3c = FUN_00489440_ex(0, 0, 0, 0);
  DAT_0085a134 = iVar14 + DAT_008c2d3c * 2;
  iVar14 = DAT_008c23dc + 0x12f684b;
  DAT_008c2d34 = FUN_00489440_ex((uint32_t)DAT_008c2d34, 0xb60b60, 0, 0);
  uint32_t uVar10 = (uint32_t)DAT_008c2d30;
  uint32_t uVar11 = (uint32_t)DAT_008c23ec;
  _DAT_0085a164 = _DAT_0085a164 & 0xffffffbf;
  if ((DAT_008c23ec & 0x40) != 0) {
    _DAT_0085a164 |= 0x800;
  }
  DAT_008c2d38 = iVar14;
  DAT_008c2d2c = FUN_00489440_ex(0, 0, 0, 0);
  if (((_DAT_0085a164 & 0x800) == 0) && ((uVar11 & 0x10) == 0)) {
    DAT_008c2d30 = (int)(uVar10 + (uint32_t)DAT_008c2d2c);
  }
  int local_2d4 = param_1 / 1000;
  int local_2d0 = param_2 / 1000;
  (void)local_2d4;
  (void)local_2d0;
  FUN_004dcbf0();
  DAT_00726090 = (int)((-(uint32_t)((_DAT_0085a164 & 0x800) != 0) & 0xffffff9c) + 0x44c);
  (void)param_3;
  // Remainder spans 630+ elided lines across non-contiguous ranges; see corpus 0x48f160.c lines 84-720.
}

// 0x4914e0 — observed shape: FUN_004a4140(); if FUN_00533c78(0x2f4)==0 clears DAT_008cac58 else DAT_008cac58 = FUN_004db5d0(); FUN_004af990(); stack store at DAT_007268f4 + DAT_00726a84*4, increment, DAT_007263bc = 0xffffffe; copy 7 dwords from DAT_008e9fd8+0x128 to locals, restore DAT_008c06a8/ac; FUN_00412840(0x43fa0000, 0x47c35000); byte at FUN_00533db0(2)+0x20 &= 0xfe; DAT_008cab10 = 0.
void FUN_004914e0(void) {
  FUN_004a4140();
  int iVar1 = FUN_00533c78(0x2f4);
  if (iVar1 == 0) {
    DAT_008cac58 = 0;
  } else {
    DAT_008cac58 = FUN_004db5d0();
  }
  FUN_004af990();
  *(uint32_t*)((intptr_t)&DAT_007268f4 + DAT_00726a84 * 4) = DAT_007263bc;
  DAT_00726a84++;
  DAT_007263bc = 0xffffffe;
  uint32_t* puVar2 = (uint32_t*)((intptr_t)DAT_008e9fd8 + 0x128);
  uint32_t local_1c[4] = {};
  uint32_t* puVar3 = local_1c;
  for (iVar1 = 7; iVar1 != 0; iVar1--) {
    *puVar3 = *puVar2;
    puVar2++;
    puVar3++;
  }
  DAT_008c06a8 = (int)local_1c[3];
  DAT_008c06ac = (int)local_1c[2];
  FUN_00412840(0x43fa0000, 0x47c35000);
  iVar1 = FUN_00533db0(2);
  *(uint8_t*)(iVar1 + 0x20) = *(uint8_t*)(iVar1 + 0x20) & 0xfe;
  DAT_008cab10 = 0;
}

// 0x4915a0 — observed shape: FUN_004a4340(); if DAT_008cac58 non-null FUN_004db7e0() + operator_delete + null; DAT_00726a84--, restore DAT_007263bc from stack; FUN_00412840(DAT_008c06ac, DAT_008c06a8); byte at FUN_00533db0(2)+0x20 |= 1.
void FUN_004915a0(void) {
  FUN_004a4340();
  void* pvVar1 = (void*)(intptr_t)DAT_008cac58;
  if (DAT_008cac58 != 0) {
    FUN_004db7e0();
    operator_delete(pvVar1);
    DAT_008cac58 = 0;
  }
  DAT_00726a84--;
  DAT_007263bc = *(uint32_t*)((intptr_t)&DAT_007268f4 + DAT_00726a84 * 4);
  FUN_00412840((uint32_t)DAT_008c06ac, (uint32_t)DAT_008c06a8);
  int iVar2 = FUN_00533db0(2);
  *(uint8_t*)(iVar2 + 0x20) = *(uint8_t*)(iVar2 + 0x20) | 1;
}

// 0x491610 — observed shape: self is ECX float* (vec3); *self *= param_1; self[1] *= param_1; self[2] *= param_1.
void FUN_00491610(void* self, float param_1) {
  float* in_ECX = (float*)self;
  in_ECX[0] = param_1 * in_ECX[0];
  in_ECX[1] = param_1 * in_ECX[1];
  in_ECX[2] = param_1 * in_ECX[2];
}

// 0x491640 — observed shape: self is ECX float* (vec3); fVar1 = SQRT(z^2+y^2+x^2); if 1e-06 < fVar1 normalize by 1/fVar1 else zero vector; returns fVar1 or 0.
long double FUN_00491640(void* self) {
  float* in_ECX = (float*)self;
  long double fVar1 = sqrtl((long double)in_ECX[2] * (long double)in_ECX[2] +
    (long double)in_ECX[1] * (long double)in_ECX[1] + (long double)in_ECX[0] * (long double)in_ECX[0]);
  if ((long double)1e-06 < fVar1) {
    long double fVar2 = 1.0L / fVar1;
    in_ECX[0] = (float)(fVar2 * (long double)in_ECX[0]);
    in_ECX[1] = (float)(fVar2 * (long double)in_ECX[1]);
    in_ECX[2] = (float)(fVar2 * (long double)in_ECX[2]);
    return fVar1;
  }
  in_ECX[0] = 0.0f;
  in_ECX[1] = 0.0f;
  in_ECX[2] = 0.0f;
  return 0.0L;
}

// 0x4916a0 — observed shape: self is ECX float* (vec3); returns SQRT(z^2+y^2+x^2).
long double FUN_004916a0(void* self) {
  float* in_ECX = (float*)self;
  return sqrtl((long double)in_ECX[2] * (long double)in_ECX[2] +
    (long double)in_ECX[1] * (long double)in_ECX[1] + (long double)in_ECX[0] * (long double)in_ECX[0]);
}

// 0x4916d0 — observed shape: self is ECX float* (src a), param_2 src b, param_1 out; fVar1 = a[1]*b[2]-b[1]*a[2]; fVar4 = *b*a[2]-*a*b[2]; fVar3 = b[1]*a[0]-a[1]*b[0]; fVar2 = SQRT(fVar1^2+fVar3^2+fVar4^2); if 1e-06 < fVar2 store normalized with components fVar1, fVar4, fVar3 else zero.
void FUN_004916d0(void* self, float* param_1, float* param_2) {
  float* in_ECX = (float*)self;
  float fVar1 = in_ECX[1] * param_2[2] - param_2[1] * in_ECX[2];
  float fVar4 = param_2[0] * in_ECX[2] - in_ECX[0] * param_2[2];
  float fVar3 = param_2[1] * in_ECX[0] - in_ECX[1] * param_2[0];
  float fVar2 = sqrtf(fVar1 * fVar1 + fVar3 * fVar3 + fVar4 * fVar4);
  if (1e-06f < fVar2) {
    fVar2 = 1.0f / fVar2;
    param_1[0] = fVar2 * fVar1;
    param_1[1] = fVar4 * fVar2;
    param_1[2] = fVar2 * fVar3;
    return;
  }
  param_1[0] = 0.0f;
  param_1[1] = 0.0f;
  param_1[2] = 0.0f;
}
