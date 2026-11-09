#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void* thunk_FUN_00533c78(int size);
extern void* CRect_ctor(void* pSelf, int a, int b, int c, int d);
extern void FUN_00569df0(int a, int b);
extern float* FUN_00555b90(void* p);

extern int32_t DAT_007283f8;
extern int32_t DAT_00728920;
extern int32_t DAT_00728650;
extern uint8_t DAT_00728394;
extern int32_t _DAT_007288e0;
extern int32_t _DAT_007287f0;
extern int32_t _DAT_00728778;
extern int32_t _DAT_00728958;
extern int32_t _DAT_00728688;
extern int32_t _DAT_00728610;
extern int32_t _DAT_00728598;
extern int32_t _DAT_00728520;
extern int32_t _DAT_00728868;
extern int32_t _DAT_00728700;
extern int32_t _DAT_00728430;
extern int32_t _DAT_007284a8;

// 0x569bf0 — observed shape: alloc array of 0x4c-sized entries, init header and per-entry CRect + vtable tags
int* FUN_00569bf0(int param_1)
{
  int* piVar1 = (int*)thunk_FUN_00533c78(param_1 * 0x4c + 4);
  if (piVar1 == nullptr) {
    return nullptr;
  }
  *piVar1 = param_1;
  if (-1 < param_1 + -1) {
    int* piVar2 = piVar1 + 2;
    do {
      *(uint8_t*)piVar2 = 8;
      CRect_ctor((void*)(piVar2 + 1), 0, 0, 0, 0);
      *(uint8_t*)piVar2 = 0x4c;
      piVar2[5] = 0;
      piVar2[6] = 0;
      piVar2[7] = 0;
      piVar2[0xb] = 0;
      piVar2[0xc] = 0;
      piVar2[0xd] = 0;
      piVar2[0xe] = 0;
      piVar2[8] = 0;
      piVar2[9] = 0;
      piVar2[10] = 0;
      piVar2[0xf] = 0;
      piVar2[0x10] = 0;
      piVar2[0x11] = 0;
      piVar2 = piVar2 + 0x13;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return piVar1 + 1;
}

// 0x569c70 — observed shape: iterate 3 slots at +0x34, indirect call via DAT_007283f8 table
void FUN_00569c70(int param_1)
{
  int* piVar1 = (int*)(param_1 + 0x34);
  int iVar2 = 3;
  do {
    if (*piVar1 != 0) {
      auto fn = *(void(**)(int, int))((char*)&DAT_007283f8 + piVar1[-4] * 4);
      fn(*piVar1, piVar1[-7]);
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
}

// 0x569d70 — observed shape: in_ECX receiver, vtable call at +0x15c slot 8, then 3-slot loop with DAT_00728920 dispatch
void FUN_00569d70(int param_1, void* self)
{
  int iVar1 = param_1;
  {
    auto vt = *(void***)(*(int*)(param_1 + 0x15c));
    auto fn = vt[2];
    fn(&param_1, 4);
  }
  *(uint32_t*)((char*)self + 0x30) = 0;
  int* piVar4 = (int*)((char*)self + 0x18);
  int iVar3 = 3;
  uint8_t auStackY_a4[128] = {};
  do {
    {
      auto vt = *(void***)(*(int*)(iVar1 + 0x15c));
      vt[2](piVar4, 4);
    }
    if (*piVar4 != 0) {
      {
        auto vt = *(void***)(*(int*)(iVar1 + 0x15c));
        vt[2](auStackY_a4 + 0xa0, 4);
      }
      piVar4[3] = 0;
      auto fn = *(int(*)(int, int))((char*)&DAT_00728920 + 0 * 4);
      int iVar2 = fn(iVar1, *piVar4);
      piVar4[7] = iVar2;
    }
    piVar4 = piVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
}

// 0x569df0 — observed shape: vtable at +0x160 slot 3, 3-slot loop with DAT_00728650 dispatch
void FUN_00569df0(int param_1, int param_2)
{
  {
    auto vt = *(void***)(*(int*)(param_1 + 0x160));
    auto fn = *(void(*)(int, int))( (char*)vt + 0xc );
    fn(param_2 + 0x30, 4);
  }
  int* piVar2 = (int*)(param_2 + 0x18);
  int iVar1 = 3;
  do {
    {
      auto vt = *(void***)(*(int*)(param_1 + 0x160));
      auto fn = *(void(*)(int, int))( (char*)vt + 0xc );
      fn((int)piVar2, 4);
    }
    if (*piVar2 != 0) {
      {
        auto vt = *(void***)(*(int*)(param_1 + 0x160));
        auto fn = *(void(*)(int, int))( (char*)vt + 0xc );
        fn((int)(piVar2 + 3), 4);
      }
      auto fn2 = *(void(*)(int, int, int))((char*)&DAT_00728650 + piVar2[3] * 4);
      fn2(param_1, piVar2[7], *piVar2);
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
}

// 0x569f10 — observed shape: loop calling FUN_00569df0 stride 0x4c
void FUN_00569f10(uint32_t param_1, int param_2, int param_3)
{
  if (param_3 != 0) {
    do {
      FUN_00569df0((int)param_1, param_2);
      param_2 = param_2 + 0x4c;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
}

extern void FUN_00569f10(uint32_t, int, int);
extern uint32_t FUN_00569b40(void);
extern uint32_t FUN_005699a0(void);
extern void FUN_00576700(uint32_t);
extern void FUN_00535190(uint32_t);
extern void FUN_00576720(uint32_t, uint32_t);
extern void FUN_00556150(uint32_t);
extern void FUN_0056a050(float*, float, float*, int, float, int*);

extern int32_t DAT_00728858;
extern float DAT_00728398;
extern float DAT_0072839c;
extern float DAT_007283a0;
extern float DAT_007283a4;

// 0x569f40 — observed shape: one-shot init table via DAT_00728394 guard
uint32_t FUN_00569f40(void)
{
  if (DAT_00728394 == '\0') {
    _DAT_007288e0 = 0;
    _DAT_007287f0 = 0;
    _DAT_00728778 = 0;
    DAT_00728394 = 1;
    _DAT_00728958 = 0x56a9e60;
    _DAT_00728688 = (int32_t)FUN_00569f10;
    _DAT_00728610 = (int32_t)FUN_00569b40;
    _DAT_00728598 = (int32_t)FUN_00569bf0;
    _DAT_00728520 = 0x56b110;
    _DAT_00728868 = (int32_t)FUN_005699a0;
    _DAT_00728700 = 0x569a90;
    _DAT_00728430 = (int32_t)FUN_00569c70;
    _DAT_007284a8 = 0x569cb0;
    return 1;
  }
  return 0;
}

// 0x569fd0 — observed shape: build CRect(1.0f,0,0,0) and copy 4 floats to out stack slot
void FUN_00569fd0(uint32_t* out)
{
  float local[4];
  CRect_ctor((void*)local, 0x3f800000, 0, 0, 0);
  out[0] = *(uint32_t*)&local[0];
  out[1] = *(uint32_t*)&local[1];
  out[2] = *(uint32_t*)&local[2];
  out[3] = *(uint32_t*)&local[3];
}

// 0x56a010 — observed shape: two sequential calls
void FUN_0056a010(uint32_t param_1)
{
  FUN_00576700(param_1);
  FUN_00535190(param_1);
}

// 0x56a030 — observed shape: two sequential calls
void FUN_0056a030(uint32_t param_1, uint32_t param_2)
{
  FUN_00576720(param_1, param_2);
  FUN_00556150(param_1);
}

// 0x56a050 — observed shape: float track interp search; stride = byte at param_3+4; dispatch via DAT_00728858 table
void FUN_0056a050(float* param_1, float param_2, float* param_3, int param_4, float param_5, int* param_6)
{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  uint32_t uVar5;
  uint32_t uVar6;
  int iVar7;
  float local_20[4];
  float local_10[4];

  iVar4 = (int)param_5;
  if (param_5 == 1.4013e-45f) {
    if (param_4 != 4) {
      param_1[0] = param_3[2];
      param_1[1] = param_3[3];
      param_1[2] = param_3[4];
      param_1[3] = param_3[5];
      return;
    }
  } else if (param_4 != 4) {
    uVar5 = (uint32_t)((int)param_5 - 1);
    {
      uint32_t idx = *(uint8_t*)(param_3 + 1) * (uint32_t)(*param_6);
      param_5 = *(float*)((char*)param_3 + idx);
    }
    if (param_2 < param_5) {
      *param_6 = 0;
      param_5 = param_3[0];
    }
    uVar6 = (uint32_t)(*param_6 + 1);
    if (3 < (int)((uVar5 - uVar6) + 1)) {
      iVar7 = *param_6 + 3;
      do {
        fVar1 = *(float*)((char*)param_3 + *(uint8_t*)(param_3 + 1) * uVar6);
        fVar2 = fVar1;
        if (!(param_2 < fVar1)) goto interp;
        iVar3 = *param_6;
        *param_6 = iVar3 + 1;
        param_5 = *(float*)((char*)param_3 + (iVar7 + -1) * (uint32_t)*(uint8_t*)(param_3 + 1));
        if (param_2 < param_5 && param_2 != param_5) {
          uVar6 = uVar6 + 1;
          fVar2 = param_5;
          param_5 = fVar1;
          goto interp;
        }
        *param_6 = iVar3 + 2;
        fVar1 = *(float*)((char*)param_3 + (uint32_t)*(uint8_t*)(param_3 + 1) * iVar7);
        if (param_2 < fVar1 && param_2 != fVar1) {
          uVar6 = uVar6 + 2;
          fVar2 = fVar1;
          goto interp;
        }
        *param_6 = iVar3 + 3;
        param_5 = *(float*)((char*)param_3 + (iVar7 + 1) * (uint32_t)*(uint8_t*)(param_3 + 1));
        if (param_2 < param_5 && param_2 != param_5) {
          uVar6 = uVar6 + 3;
          fVar2 = param_5;
          param_5 = fVar1;
          goto interp;
        }
        *param_6 = iVar3 + 4;
        uVar6 = uVar6 + 4;
        iVar7 = iVar7 + 4;
      } while ((int)uVar6 <= iVar4 - 4);
    }
    while (true) {
      fVar2 = param_5;
      if ((int)uVar5 < (int)uVar6) break;
      fVar2 = *(float*)((char*)param_3 + *(uint8_t*)(param_3 + 1) * uVar6);
      if (!(param_1 - param_2)) break;
      if (param_2 < fVar2 && param_2 == fVar2) break;
      uVar6 = uVar6 + 1;
      *param_6 = *param_6 + 1;
      param_5 = fVar2;
    }
interp:
    {
      auto fn = *(void(*)(float, float*, float*, float*))((char*)&DAT_00728858 + param_4 * 4);
      fn((param_2 - param_5) / (fVar2 - param_5),
         (float*)((char*)param_3 + *param_6 * (uint32_t)*(uint8_t*)(param_3 + 1)),
         (float*)((char*)param_3 + *(uint8_t*)(param_3 + 1) * uVar6),
         local_10);
      param_1[0] = local_10[0];
      param_1[1] = local_10[1];
      param_1[2] = local_10[2];
      param_1[3] = local_10[3];
      return;
    }
  }
  {
    auto fn = *(void(*)(float, float*, void*, float*))((char*)&DAT_00728858 + param_4 * 4);
    fn(param_2, param_3, nullptr, local_20);
    param_1[0] = local_20[0];
    param_1[1] = local_20[1];
    param_1[2] = local_20[2];
    param_1[3] = local_20[3];
  }
}

extern float* FUN_0056a280(float*, float, float*, uint32_t, int);
extern void FUN_0056a340(int, uint32_t);
extern void FUN_0056a5f0(float, float*, int, float, int*);
extern void FUN_0056a790(float, float*, uint32_t, int);
extern void FUN_0056a5b0(int, int);
extern uint32_t FUN_00576290(int, int);

extern uint8_t DAT_00728395;
extern int32_t _DAT_007288d0;
extern int32_t _DAT_007287e0;
extern int32_t _DAT_00728768;
extern int32_t _DAT_00728498;
extern int32_t _DAT_00728948;
extern int32_t _DAT_00728678;
extern int32_t _DAT_00728600;
extern int32_t _DAT_00728588;
extern int32_t _DAT_00728510;
extern int32_t _DAT_007286f0;
extern int32_t _DAT_00728420;

extern uint8_t DAT_007283ac;
extern int32_t _DAT_007288a8;
extern int32_t _DAT_007287b8;
extern int32_t _DAT_00728740;
extern int32_t _DAT_00728470;
extern int32_t _DAT_00728650;
extern int32_t _DAT_007285d8;
extern int32_t _DAT_00728560;
extern int32_t _DAT_007284e8;
extern int32_t _DAT_00728830;
extern int32_t _DAT_007286c8;
extern int32_t _DAT_007283f8;
extern float _DAT_007283a8;

// 0x56a280 — observed shape: clamp float against table bounds, else call FUN_0056a050
float* FUN_0056a280(float* param_1, float param_2, float* param_3, uint32_t param_4, int param_5)
{
  int iVar1 = param_5;
  if (param_5 == 0) {
    param_1[0] = DAT_00728398;
    param_1[1] = DAT_0072839c;
    param_1[2] = DAT_007283a0;
    param_1[3] = DAT_007283a4;
    return param_1;
  }
  if (*param_3 <= param_2) {
    float last = *(float*)((char*)param_3 + (param_5 + -1) * (uint32_t)*(uint8_t*)(param_3 + 1));
    if (param_2 <= last) {
      int hint = 0;
      FUN_0056a050(param_1, param_2, param_3, (int)param_4, (float)iVar1, &hint);
      return param_1;
    }
    param_3 = (float*)((char*)param_3 + (param_5 + -1) * (uint32_t)*(uint8_t*)(param_3 + 1) + 8);
  } else {
    param_3 = param_3 + 2;
  }
  param_1[0] = param_3[0];
  param_1[1] = param_3[1];
  param_1[2] = param_3[2];
  param_1[3] = param_3[3];
  return param_1;
}

// 0x56a340 — observed shape: normalize successive float quads, clamp first component to [-1,1]
void FUN_0056a340(int param_1, uint32_t param_2)
{
  uint32_t uVar6 = 0;
  uint8_t stride = *(uint8_t*)(param_1 + 4);
  if (param_2 != 1) {
    do {
      uint32_t uVar1 = uVar6 + 1;
      int iVar5 = stride * (int)uVar6;
      int iVar3 = uVar1 * stride + param_1;
      float* pfVar4 = (float*)(iVar5 + 8 + param_1);
      float v = pfVar4[0] * *(float*)(iVar3 + 8)
              + pfVar4[1] * *(float*)(iVar3 + 0xc)
              + pfVar4[2] * *(float*)(iVar3 + 0x10)
              + *(float*)(iVar5 + 0x14 + param_1) * *(float*)(iVar3 + 0x14);
      if (v < 0.0f) {
        float* pv = FUN_00555b90(nullptr);
        *(float*)(iVar3 + 8) = pv[0];
        *(float*)(iVar3 + 0xc) = pv[1];
        *(float*)(iVar3 + 0x10) = pv[2];
        *(float*)(iVar3 + 0x14) = pv[3];
      }
      uVar6 = uVar1;
    } while (uVar6 < param_2 - 1);
  }
  uVar6 = 0;
  if (3 < (int)param_2) {
    int iVar3b = 2;
    do {
      for (int k = 0; k < 4; ++k) {
        int idx = (k == 0 ? (int)uVar6 : (k == 1 ? iVar3b - 1 : (k == 2 ? iVar3b : iVar3b + 1)));
        int iVar5 = stride * idx;
        float fVar2 = *(float*)(iVar5 + 8 + param_1);
        int base = iVar5 + param_1;
        if (-1.0f <= fVar2) {
          if (1.0f < fVar2) *(uint32_t*)(base + 8) = 0x3f800000;
        } else {
          *(uint32_t*)(base + 8) = 0xbf800000;
        }
      }
      uVar6 = uVar6 + 4;
      iVar3b = iVar3b + 4;
    } while (uVar6 < param_2 - 3);
  }
  for (; uVar6 < param_2; uVar6 = uVar6 + 1) {
    int iVar3c = stride * (int)uVar6;
    float fVar2 = *(float*)(iVar3c + 8 + param_1);
    int base = iVar3c + param_1;
    if (-1.0f <= fVar2) {
      if (1.0f < fVar2) *(uint32_t*)(base + 8) = 0x3f800000;
    } else {
      *(uint32_t*)(base + 8) = 0xbf800000;
    }
  }
}

// 0x56a530 — observed shape: one-shot init table via DAT_00728395 guard
uint32_t FUN_0056a530(void)
{
  if (DAT_00728395 == '\0') {
    _DAT_007288d0 = 0;
    _DAT_007287e0 = 0;
    _DAT_00728768 = 0;
    _DAT_00728498 = 0;
    DAT_00728395 = 1;
    _DAT_00728948 = 0x4aaef0;
    _DAT_00728678 = 0x497420;
    _DAT_00728600 = 0x497420;
    _DAT_00728588 = 0x4aaef0;
    _DAT_00728510 = 0x497420;
    _DAT_00728858 = 0x569fd0;
    _DAT_007286f0 = 0x56e300;
    _DAT_00728420 = 0x56a340;
    return 1;
  }
  return 0;
}

// 0x56a5b0 — observed shape: call FUN_00576290 then float equality on +8
uint32_t FUN_0056a5b0(int param_1, int param_2)
{
  uint32_t uVar1 = FUN_00576290(param_1, param_2);
  if ((char)uVar1 == '\0') {
    return uVar1;
  }
  if (*(float*)(param_1 + 8) == *(float*)(param_2 + 8)) {
    return 1;
  }
  return 0;
}

// 0x56a5f0 — observed shape: scalar variant of track interp, returns float via DAT_00728830 dispatch
void FUN_0056a5f0(float param_1, float* param_2, int param_3, float param_4, int* param_5)
{
  float fVar2;
  float fVar3;
  int iVar5 = (int)param_4;
  if (param_4 == 1.4013e-45f) {
    param_4 = param_2[2];
    return;
  }
  uint32_t uVar1 = (uint32_t)((int)param_4 - 1);
  param_4 = *(float*)((char*)param_2 + *(uint8_t*)(param_2 + 1) * (uint32_t)(*param_5));
  if (param_1 < param_4) {
    *param_5 = 0;
    param_4 = param_2[0];
  }
  uint32_t uVar6 = (uint32_t)(*param_5 + 1);
  if (3 < (int)((uVar1 - uVar6) + 1)) {
    int iVar7 = *param_5 + 3;
    do {
      fVar2 = *(float*)((char*)param_2 + *(uint8_t*)(param_2 + 1) * uVar6);
      fVar3 = fVar2;
      if (param_1 < fVar2 && param_1 != fVar2) goto interp;
      int iVar4 = *param_5;
      *param_5 = iVar4 + 1;
      param_4 = *(float*)((char*)param_2 + (iVar7 + -1) * (uint32_t)*(uint8_t*)(param_2 + 1));
      if (param_1 < param_4 && param_1 != param_4) {
        uVar6 = uVar6 + 1;
        fVar3 = param_4;
        param_4 = fVar2;
        goto interp;
      }
      *param_5 = iVar4 + 2;
      fVar2 = *(float*)((char*)param_2 + (uint32_t)*(uint8_t*)(param_2 + 1) * iVar7);
      if (param_1 < fVar2 && param_1 != fVar2) {
        uVar6 = uVar6 + 2;
        fVar3 = fVar2;
        goto interp;
      }
      *param_5 = iVar4 + 3;
      param_4 = *(float*)((char*)param_2 + (iVar7 + 1) * (uint32_t)*(uint8_t*)(param_2 + 1));
      if (param_1 < param_4 && param_1 != param_4) {
        uVar6 = uVar6 + 3;
        fVar3 = param_4;
        param_4 = fVar2;
        goto interp;
      }
      *param_5 = iVar4 + 4;
      uVar6 = uVar6 + 4;
      iVar7 = iVar7 + 4;
    } while ((int)uVar6 <= iVar5 - 4);
  }
  while ((fVar3 = param_4, (int)uVar6 <= (int)uVar1 &&
         (fVar3 = *(float*)((char*)param_2 + *(uint8_t*)(param_2 + 1) * uVar6),
         !(param_1 < fVar3)))) {
    uVar6 = uVar6 + 1;
    *param_5 = *param_5 + 1;
    param_4 = fVar3;
  }
interp:
  {
    auto fn = *(void(*)(float, float*, float*, float*))((char*)&DAT_00728830 + param_3 * 4);
    fn((param_1 - param_4) / (fVar3 - param_4),
       (float*)((char*)param_2 + *param_5 * (uint32_t)*(uint8_t*)(param_2 + 1)),
       (float*)((char*)param_2 + *(uint8_t*)(param_2 + 1) * uVar6),
       &param_4);
  }
}

// 0x56a790 — observed shape: clamp float against table bounds, else call FUN_0056a5f0
float FUN_0056a790(float param_1, float* param_2, uint32_t param_3, int param_4)
{
  int iVar1 = param_4;
  if (param_4 == 0) {
    return _DAT_007283a8;
  }
  if (param_1 < *param_2) {
    return param_2[2];
  }
  float last = *(float*)((char*)param_2 + (param_4 + -1) * (uint32_t)*(uint8_t*)(param_2 + 1));
  if (last < param_1) {
    return *(float*)((char*)param_2 + (param_4 + -1) * (uint32_t)*(uint8_t*)(param_2 + 1) + 8);
  }
  int hint = 0;
  float out = 0;
  FUN_0056a5f0(param_1, param_2, (int)param_3, (float)iVar1, &hint);
  return out;
}

// 0x56a800 — observed shape: one-shot init table via DAT_007283ac guard
uint32_t FUN_0056a800(void)
{
  if (DAT_007283ac == '\0') {
    _DAT_007288a8 = 0;
    _DAT_007287b8 = 0;
    _DAT_00728740 = 0;
    _DAT_00728470 = 0;
    DAT_007283ac = 1;
    _DAT_00728920 = 0x4aaef0;
    _DAT_00728650 = 0x497420;
    _DAT_007285d8 = 0x497420;
    _DAT_00728560 = 0x4aaef0;
    _DAT_007284e8 = 0x497420;
    _DAT_00728830 = 0x497420;
    _DAT_007286c8 = 0x56a5b0;
    _DAT_007283f8 = 0x497420;
    return 1;
  }
  return 0;
}

// 0x56a880 — observed shape: call FUN_00576700 then vtable call at +0x15c slot 2 with in_ECX+8
void FUN_0056a880(int param_1, void* self)
{
  FUN_00576700((uint32_t)param_1);
  auto vt = *(void***)(*(int*)(param_1 + 0x15c));
  vt[2]((char*)self + 8, 4);
}

// 0x56a8b0 — observed shape: call FUN_00576720 then vtable call at +0x160 slot 3 with param_2+8
void FUN_0056a8b0(int param_1, int param_2)
{
  FUN_00576720((uint32_t)param_1, (uint32_t)param_2);
  auto vt = *(void***)(*(int*)(param_1 + 0x160));
  auto fn = *(void(*)(int, int))((char*)vt + 0xc);
  fn(param_2 + 8, 4);
}

// 0x56a930 — observed shape: alloc array of 0x14-sized entries, init vtable tag per entry
int* FUN_0056a930(int param_1)
{
  int* piVar1 = (int*)thunk_FUN_00533c78(param_1 * 0x14 + 4);
  if (piVar1 == nullptr) {
    return nullptr;
  }
  *piVar1 = param_1;
  int* piVar2 = piVar1 + 1;
  if (-1 < param_1 + -1) {
    int* p = piVar1 + 2;
    do {
      *(uint8_t*)p = 0x14;
      p = p + 5;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return piVar2;
}
