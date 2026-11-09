#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cmath>

extern int FUN_00552c80();
extern void* FUN_00552d20();
extern void* thunk_FUN_00533c78(std::size_t n);
extern void* FUN_005f0ddc();
extern void* FUN_00557e70(void* p);
void* operator_delete(void* p);
void operator_delete__(void* p);

extern int DAT_007177ac;
extern int DAT_007177b0;
extern int DAT_007177b4;
extern int DAT_0071779c;
extern int DAT_007177a0;
extern int DAT_007177a4;
extern int DAT_007177a8;
extern int DAT_00727430;
extern int DAT_00727434;
extern int DAT_00727438;
extern int DAT_00727558;
extern void* PTR_FUN_006c52e0;
extern void* PTR_FUN_006c52d4;

// 0x5a86a0 — observed shape
int FUN_005a86a0_recon(float* param_1, float* param_2, void* self) {
  float fVar3, fVar4, fVar5, fVar6;
  int iVar8;
  float local_20;
  float local_1c;
  float local_c[3];
  float* pfVar7;
  float* pfVar1;
  float* pfVar2;
  uint8_t* s = (uint8_t*)self;

  local_c[0] = std::fabs(*(float*)(s + 0x6c));
  local_c[1] = std::fabs(*(float*)(s + 0x70));
  local_c[2] = std::fabs(*(float*)(s + 0x74));
  local_1c = -3.4028235e+38f;
  local_20 = 3.4028235e+38f;
  pfVar7 = (float*)(s + 0x4c);
  fVar3 = *param_1;
  pfVar1 = param_1 + 1;
  pfVar2 = param_1 + 2;
  iVar8 = 0;
  local_c[0] = local_c[0];
  do {
    fVar4 = (*(float*)(s + 0x3c) - fVar3) * pfVar7[-1] +
            (*(float*)(s + 0x40) - *pfVar1) * (*pfVar7) +
            (*(float*)(s + 0x44) - *pfVar2) * pfVar7[1];
    fVar5 = (*pfVar7) * param_2[1] + (*param_2) * pfVar7[-1] + param_2[2] * pfVar7[1];
    if (std::fabs(fVar5) <= 1e-07f) {
      if (local_c[iVar8] < std::fabs(fVar4)) {
        return 0;
      }
    } else {
      fVar5 = 1.0f / fVar5;
      float fA = (fVar4 + local_c[iVar8]) * fVar5;
      float fB = (fVar4 - local_c[iVar8]) * fVar5;
      fVar4 = fA;
      if (fA < fB) { fVar4 = fA; } else { fVar4 = fB; }
      float fLo = fA < fB ? fA : fB;
      float fHi = fA < fB ? fB : fA;
      if (local_1c < fHi) local_1c = fHi;
      if (fLo < local_20) local_20 = fLo;
      if (local_20 < local_1c || local_20 < 0.0f) return 0;
    }
    iVar8++;
    pfVar7 += 3;
    if (2 < iVar8) return 1;
  } while (true);
}

// 0x5a8990 — observed shape
float FUN_005a8990_recon() {
  int iVar1 = rand();
  return (float)iVar1 * 3.051851e-05f;
}

// 0x5a8a00 — observed shape
void FUN_005a8a00_recon(void* self) {
  int32_t* s = (int32_t*)self;
  FUN_00552c80();
  s[0] = (int32_t)(intptr_t)&PTR_FUN_006c52e0;
  s[0x1b] = 0; s[0x1c] = 0; s[0x1d] = 0; s[0x1e] = 0;
  s[0x2a] = 0; s[0x33] = 0; s[0x34] = 0; s[0x35] = 0;
  s[0x11] = 0; s[0x12] = 0; s[0x13] = 0; s[0x14] = 0; s[0x15] = 0; s[0x16] = 0; s[0x17] = 0;
  s[0x18] = DAT_007177ac;
  s[0x19] = DAT_007177b0;
  s[0x1a] = DAT_007177b4;
  s[0x1b] = DAT_0071779c;
  s[0x1c] = DAT_007177a0;
  s[0x1d] = DAT_007177a4;
  s[0x1e] = DAT_007177a8;
  s[0x1f] = (int32_t)0x3f800000;
  s[0x20] = 0; s[0x21] = 0;
  *(uint8_t*)((uint8_t*)s + 0x88) = 0;
  s[0x23] = 0; s[0x24] = 0; s[0x25] = 0;
  *(uint8_t*)((uint8_t*)s + 0x98) = 0;
  *(uint8_t*)((uint8_t*)s + 0x99) = 0;
  s[0x27] = 0; s[0x28] = 0; s[0x29] = 0;
  {
    void* p = (void*)(intptr_t)s[0x2a];
    if (p != nullptr) {
      int32_t* rc = (int32_t*)p + 1;
      *rc = *rc - 1;
      if (*rc == 0) {
        void** vt = (void**)p;
        void (*fn)(int) = (void(*)(int))*vt;
        fn(1);
      }
      s[0x2a] = 0;
    }
  }
  *(uint16_t*)((uint8_t*)s + 0x2b*4) = 1;
  s[0x2c] = (int32_t)0x3f800000;
  *(uint16_t*)((uint8_t*)s + 0x2d*4) = 0;
  s[0x2e] = 0; s[0x2f] = 0;
  *(uint16_t*)((uint8_t*)s + 0x30*4) = 0;
  *(uint16_t*)((uint8_t*)s + 0xc2) = 0;
  *(uint16_t*)((uint8_t*)s + 0x31*4) = 0;
  s[0x32] = 0;
  for (int idx = 0x33; idx <= 0x35; ++idx) {
    void* p = (void*)(intptr_t)s[idx];
    if (p != nullptr) {
      int32_t* rc = (int32_t*)p + 1;
      *rc = *rc - 1;
      if (*rc == 0) {
        void** vt = (void**)p;
        void (*fn)(int) = (void(*)(int))*vt;
        fn(1);
      }
      s[idx] = 0;
    }
  }
  *(uint8_t*)((uint8_t*)s + 0x36*4) = 1;
  s[0x37] = DAT_00727430;
  s[0x38] = DAT_00727434;
  s[0x39] = DAT_00727438;
  s[0x3a] = 0; s[0x3c] = 0;
  *(uint8_t*)((uint8_t*)s + 0x3b*4) = 1;
}

// 0x5a8c00 — observed shape
void FUN_005a8c00_recon(void* self) {
  int32_t* s = (int32_t*)self;
  s[0] = (int32_t)(intptr_t)&PTR_FUN_006c52e0;
  auto release = [](int32_t* s, int idx, bool clear) {
    void* p = (void*)(intptr_t)s[idx];
    if (p != nullptr) {
      int32_t* rc = (int32_t*)p + 1;
      *rc = *rc - 1;
      if (*rc == 0) {
        void** vt = (void**)p;
        void (*fn)(int) = (void(*)(int))*vt;
        fn(1);
      }
      if (clear) s[idx] = 0;
    }
  };
  release(s, 0x2a, true);
  operator_delete((void*)(intptr_t)s[0x32]);
  release(s, 0x33, true);
  release(s, 0x34, true);
  release(s, 0x35, true);
  release(s, 0x35, false);
  release(s, 0x34, false);
  release(s, 0x33, false);
  release(s, 0x2a, false);
  FUN_00552d20();
}

// 0x5a8d90 — observed shape
void FUN_005a8d90_recon(void* self) {
  int32_t* s = (int32_t*)self;
  float fVar2 = (float)s[7];
  float local_2c = (float)s[6];
  int iVar6 = (int)(intptr_t)FUN_005f0ddc();
  int32_t* piVar3 = (int32_t*)(intptr_t)s[0xd];
  uint32_t uVar10 = (uint32_t)(1 - iVar6);
  uint32_t uVar9 = 0;
  uint32_t local_20 = 0;
  if (piVar3 != nullptr) {
    uint8_t bVar5 = 0;
    void* p = piVar3;
    void* (*firstFn)() = *(void*(**)())((uint8_t*)p + 4);
    void* puVar7 = firstFn();
    while (puVar7 != nullptr) {
      if (puVar7 == (void*)&DAT_00727558) { bVar5 = 1; break; }
      puVar7 = *(void**)((uint8_t*)puVar7 + 4);
    }
    local_20 = (uint32_t)(-(int32_t)bVar5) & (uint32_t)(uintptr_t)piVar3;
  }
  void* local_18 = &PTR_FUN_006c52d4;
  uint32_t local_c = 0;
  uint32_t local_8 = 0;
  uint32_t local_10 = uVar10;
  void* local_14 = (uVar10 == 0) ? nullptr : thunk_FUN_00533c78((size_t)uVar10 * 4);
  int saved_3b = s[0x3b];
  uint16_t uVar1 = *(uint16_t*)((uint8_t*)s + 0x0c);
  *(uint8_t*)((uint8_t*)s + 0x36*4) = 0;
  *(uint16_t*)((uint8_t*)s + 0x0c) = (uint16_t)(uVar1 | 8);
  auto cond = [&]() -> bool {
    return !std::isnan(local_2c) && !std::isnan(fVar2) && ((local_2c < fVar2) != (local_2c == fVar2));
  };
  while (cond()) {
    if (uVar10 <= uVar9) break;
    void** puVar7 = (void**)FUN_00533c78(0x10);
    void** vt = (void**)s[0];
    void (*cb)(float) = (void(*)(float))vt[0x3c/4];
    cb(local_2c);
    int32_t iVar4 = *(int32_t*)(local_20 + 0xbc);
    uint8_t* dst = (uint8_t*)puVar7;
    uint8_t* src = (uint8_t*)(intptr_t)iVar4;
    dst[0] = src[0x10]; dst[1] = src[0x11]; dst[2] = src[0x12]; dst[3] = src[0x13];
    dst[4] = src[0x14]; dst[5] = src[0x15]; dst[6] = src[0x16]; dst[7] = src[0x17];
    dst[8] = src[0x18]; dst[9] = src[0x19]; dst[10] = src[0x1a]; dst[11] = src[0x1b];
    dst[12] = src[0x1c]; dst[13] = src[0x1d]; dst[14] = src[0x1e]; dst[15] = src[0x1f];
    if (uVar9 < local_10) {
      if (uVar9 < local_c) {
        if (*(int32_t*)((uint8_t*)local_14 + uVar9 * 4) == 0) goto LAB_005a8ee4_store;
      } else {
        local_c = uVar9 + 1;
LAB_005a8ee4_store:
        local_8 = local_8 + 1;
      }
      *(void**)((uint8_t*)local_14 + uVar9 * 4) = puVar7;
    }
    uVar9++;
    local_2c += 0.1f;
  }
  FUN_00557e70(&local_18);
  s[0x3a] = (int32_t)((float)s[0x3a] * 1.05f);
  {
    int32_t iVar4 = *(int32_t*)(local_20 + 0xbc);
    *(int32_t*)(iVar4 + 0x10) = s[0x37];
    *(int32_t*)(iVar4 + 0x14) = s[0x38];
    *(int32_t*)(iVar4 + 0x18) = s[0x39];
    *(int32_t*)(iVar4 + 0x1c) = s[0x3a];
  }
  *(uint8_t*)((uint8_t*)s + 0x36*4) = 1;
  if (((uVar1 >> 3) & 1) == 0) {
    *(uint8_t*)((uint8_t*)s + 0x0c) = (uint8_t)(*(uint8_t*)((uint8_t*)s + 0x0c) & 0xf7);
  } else {
    *(uint8_t*)((uint8_t*)s + 0x0c) = (uint8_t)(*(uint8_t*)((uint8_t*)s + 0x0c) | 8);
  }
  uVar10 = 0;
  if (uVar9 != 0) {
    do {
      void* pvVar8;
      if (uVar10 < local_c) {
        pvVar8 = *(void**)((uint8_t*)local_14 + uVar10 * 4);
        *(void**)((uint8_t*)local_14 + uVar10 * 4) = nullptr;
        if (pvVar8 != nullptr) local_8 = local_8 - 1;
        if (uVar10 == local_c - 1) local_c = local_c - 1;
      } else {
        pvVar8 = nullptr;
      }
      operator_delete(pvVar8);
      uVar10++;
    } while (uVar10 < uVar9);
  }
  *(char*)((uint8_t*)s + 0x3b*4) = (char)saved_3b;
  local_18 = &PTR_FUN_006c52d4;
  operator_delete__(local_14);
}

// ---------------------------------------------------------------------------
// Additional declarations for 0x5a8fe0 - 0x5ab6f0.
// Helpers whose receiver/argument register the provider did not print are
// declared with an explicit leading parameter and are passed the method's
// `self` at those call sites.
// ---------------------------------------------------------------------------

extern int32_t FUN_00552aa0(int32_t param_1, uint32_t param_2);
extern int8_t FUN_00552bc0(uint32_t param_1);
extern void FUN_00552f70(void* self);
extern void FUN_00553060(uint32_t param_1);
extern void FUN_005530e0(void* self);
extern void FUN_005531c0(int32_t param_1);
extern void FUN_00535110(void* arg);
extern void FUN_00535150(void* arg);
extern void FUN_00535190(void* self);
extern void FUN_005351e0(void* self);
extern void* FUN_00545600();
extern void FUN_00545cc0(void* self);
extern void FUN_00548120(uint16_t param_1, int32_t param_2);
extern void* FUN_0053c4f0(void* dst, void* src);
extern void* FUN_0053c590(void* dst, void* src);
extern void* FUN_0053c6f0(float* a, float* b, float* c);
extern void* FUN_0053c8d0(void* dst, void* src);
extern void* FUN_0053c9e0(void* dst, float value);
extern void* FUN_0053ca60(float* matrix, float* vec);
extern void* FUN_0053cc20(void* matrix);
extern void* FUN_0053ce40(void* dst, void* src);
extern void FUN_004127b0(void* dst, int32_t elemSize, uint32_t count, void* ctor);
extern int8_t FUN_00428470(int32_t param_1);
extern int8_t FUN_0050b0f0(int32_t param_1);
extern int32_t FUN_00557b10(int32_t param_1);
extern void FUN_005606f0(uint32_t param_1, uint32_t* param_2);
extern void FUN_005651a0(uint32_t param_1, uint32_t param_2);
extern void* FUN_00565310(int32_t param_1, void* param_2, void* param_3, void* param_4, void* param_5);
extern void* FUN_00559050(void* param_1);
extern void* FUN_00559070(void* param_1);
extern void* FUN_005591e0(int32_t param_1, void* param_2, void* param_3, void* param_4, void* param_5);
extern void FUN_00538400(void* self);
extern void FUN_005adec0(void* self);
extern void FUN_006b34a0(int32_t param_1);

extern float _DAT_00727c78;
extern float _DAT_00727c80;
extern uint32_t DAT_007179b0[9];
extern uint32_t DAT_00727d98;
extern int32_t DAT_00728b20;
extern uint32_t DAT_00728b70;
extern void* PTR_FUN_006c5350;
extern uint8_t LAB_005cea70;
extern uint8_t LAB_004b1250;

// 0x5a8fe0 — observed shape
void FUN_005a8fe0_recon(int32_t* param_1, void* self) {
  uint8_t* s = (uint8_t*)self;
  if (*(int16_t*)(s + 0xc2) != 0) {
    *(int16_t*)(s + 0xc2) = (int16_t)(*(int16_t*)(s + 0xc2) - 1);
    int32_t obj = *(int32_t*)(intptr_t)(*(int32_t*)(s + 0x34) + 0xbc);
    void (*fn)(uint16_t) = *(void (**)(uint16_t))(intptr_t)(*(int32_t*)obj + 0x40);
    fn((uint16_t)*(int16_t*)((uint8_t*)param_1 + 0x26));
    int32_t* slot = (int32_t*)(intptr_t)(*(int32_t*)(s + 200) +
                                         (uint32_t)*(uint16_t*)(s + 0xc2) * 0x28);
    if (slot != param_1) {
      param_1[0] = slot[0];
      param_1[1] = slot[1];
      param_1[2] = slot[2];
      param_1[6] = slot[6];
      param_1[7] = slot[7];
      *(int16_t*)(param_1 + 9) = *(int16_t*)(slot + 9);
    }
    *(int16_t*)(s + 0xc4) = (int16_t)(*(int16_t*)(s + 0xc4) - 1);
  }
}

// 0x5a9060 — observed shape
float* FUN_005a9060_recon(float param_1, uint32_t param_2, float* param_3, float* param_4,
                          float unaff_retaddr, void* self) {
  uint8_t* s = (uint8_t*)self;
  int32_t* piVar7 = *(int32_t**)(intptr_t)(*(int32_t*)(s + 0x34) + 0xbc);
  float* pfVar1 = (float*)(intptr_t)(*(int32_t*)(s + 200) +
                                     (uint32_t)*(uint16_t*)(s + 0xc2) * 0x28);
  float (*fnGetId)(void) = *(float (**)(void))(intptr_t)(*piVar7 + 0x38);
  float fVar8 = fnGetId();
  *(int16_t*)((uint8_t*)pfVar1 + 0x26) = (int16_t)fVar8;
  float fStack_16c = fVar8;
  void (*fnSetId)(int32_t) = *(void (**)(int32_t))(intptr_t)(*piVar7 + 0x34);
  fnSetId((int32_t)fVar8 + 1);
  *(int16_t*)(s + 0xc2) = (int16_t)(*(int16_t*)(s + 0xc2) + 1);

  int32_t iStack_148 = piVar7[8];
  int32_t iStack_140 = piVar7[9];
  int32_t iStack_144 = piVar7[10];
  int32_t iStack_14c = piVar7[0x10];
  int32_t iStack_150 = piVar7[0x12];

  float fStack_17c = 0.0f;
  float fStack_178 = 0.0f;
  float fStack_174 = 0.0f;
  float fStack_170 = 0.0f;
  float fStack_168 = 0.0f;
  float fStack_164 = 0.0f;
  float fStack_13c = 0.0f;
  float fStack_138 = 0.0f;
  float uStack_134 = 0.0f;
  float uStack_130 = 0.0f;
  float uStack_12c = 0.0f;
  float fStack_128 = 0.0f;
  float afStack_160[4] = {0.0f, 0.0f, 0.0f, 0.0f};
  uint32_t auStack_124[9];
  uint8_t auStack_dc[36];
  uint8_t auStack_b8[36];
  uint8_t auStack_94[36];
  uint8_t auStack_70[36];
  uint8_t auStack_4c[36];
  uint8_t auStack_28[40];

  uint32_t uVar13;
  float fVar2, fVar3, fVar4, fVar5, fVar6, fVar16, fVar17, fVar18, fVar20;

  if (param_4 == nullptr) {
    int iVar9 = rand();
    fStack_168 = (unaff_retaddr - param_1) * (float)iVar9 * 3.051851e-05f;
    iVar9 = rand();
    fStack_170 = ((float)iVar9 * 3.051851e-05f - 0.5f) * *(float*)(s + 0x4c) +
                 *(float*)(s + 0x48);
    iVar9 = rand();
    fVar20 = ((float)iVar9 * 6.103702e-05f - 1.0f) * *(float*)(s + 0x54) +
             *(float*)(s + 0x50);
    iVar9 = rand();
    fVar16 = ((float)iVar9 * 6.103702e-05f - 1.0f) * *(float*)(s + 0x5c) +
             *(float*)(s + 0x58);
    fVar17 = (float)std::sin((double)fVar20);
    fVar18 = (float)std::cos((double)fVar16);
    afStack_160[0] = fVar18 * fVar17;
    fVar16 = (float)std::sin((double)fVar16);
    fVar18 = (float)std::cos((double)fVar20);
    fStack_17c = afStack_160[0] * fStack_170;
    pfVar1[0] = fStack_17c;
    fStack_178 = fVar16 * fVar17 * fStack_170;
    pfVar1[1] = fStack_178;
    pfVar1[6] = fStack_168;
    fStack_174 = fVar18 * fStack_170;
    pfVar1[2] = fStack_174;
    iVar9 = rand();
    pfVar1[7] = ((float)iVar9 * 3.051851e-05f - 0.5f) * *(float*)(s + 0x94) +
                *(float*)(s + 0x90);
    *(uint16_t*)(pfVar1 + 9) = 0;
    pfVar1[3] = *(float*)&DAT_007177ac;
    pfVar1[4] = *(float*)&DAT_007177b0;
    pfVar1[5] = *(float*)&DAT_007177b4;

    iVar9 = rand();
    afStack_160[3] = (float)iVar9 * 3.051851e-05f;
    iVar9 = rand();
    fStack_168 = (float)iVar9 * 3.051851e-05f;
    iVar9 = rand();
    uVar13 = (uint32_t)fVar8 & 0xffff;
    float* pfVar12 = (float*)(intptr_t)(uVar13 * 0xc + iStack_148);
    fStack_174 = ((float)iVar9 * 3.051851e-05f - 0.5f) * *(float*)(s + 0xa4);
    fStack_17c = (fStack_168 - 0.5f) * *(float*)(s + 0x9c);
    fStack_178 = (afStack_160[3] - 0.5f) * *(float*)(s + 0xa0);
    pfVar12[0] = fStack_17c;
    pfVar12[1] = fStack_178;
    pfVar12[2] = fStack_174;

    if (*(int32_t*)(s + 0xa8) != 0) {
      float* pfVar14 = (float*)FUN_0053ca60(afStack_160, pfVar1);
      pfVar1[0] = pfVar14[0];
      pfVar1[1] = pfVar14[1];
      pfVar1[2] = pfVar14[2];
      pfVar14 = (float*)FUN_0053ca60(afStack_160, pfVar12);
      fStack_17c = pfVar14[0] + param_3[0];
      fStack_178 = pfVar14[1] + param_3[1];
      fStack_174 = pfVar14[2] + param_3[2];
      pfVar12[0] = fStack_17c;
      pfVar12[1] = fStack_178;
      pfVar12[2] = fStack_174;
    }
    if (iStack_140 != 0) {
      int32_t* p = (int32_t*)(intptr_t)(uVar13 * 0xc + iStack_140);
      p[0] = *(int32_t*)(s + 0x60);
      p[1] = *(int32_t*)(s + 100);
      p[2] = *(int32_t*)(s + 0x68);
    }
    if (iStack_144 != 0) {
      int32_t* p = (int32_t*)(intptr_t)(uVar13 * 0x10 + iStack_144);
      p[0] = *(int32_t*)(s + 0x6c);
      p[1] = *(int32_t*)(s + 0x70);
      p[2] = *(int32_t*)(s + 0x74);
      p[3] = *(int32_t*)(s + 0x78);
    }
    if (iStack_14c != 0) {
      *(int32_t*)(intptr_t)(iStack_14c + uVar13 * 4) = *(int32_t*)(s + 0x7c);
    }
    if (iStack_150 != 0) {
      *(int32_t*)(intptr_t)(iStack_150 + uVar13 * 4) = (int32_t)0x3f800000;
    }
    goto LAB_005a9843;
  }

  fStack_164 = (float)std::sqrt((double)(param_4[2] * param_4[2] +
                                         param_4[1] * param_4[1] +
                                         *param_4 * *param_4));
  {
    int iVar9 = rand();
    fStack_168 = ((float)iVar9 * *(float*)(s + 0xb8) * 3.051851e-05f + 1.0f) * fStack_164;
    iVar9 = rand();
    fVar8 = (float)iVar9 * *(float*)(s + 0xbc) * _DAT_00727c78 * 3.051851e-05f;
    iVar9 = rand();
    fVar16 = (float)iVar9 * _DAT_00727c80 * 3.051851e-05f;
  }
  fVar17 = (float)std::sin((double)fVar8);
  fVar18 = (float)std::cos((double)fVar16);
  fStack_17c = fVar18 * fVar17;
  fVar16 = (float)std::sin((double)fVar16);
  fStack_178 = fVar16 * fVar17;
  fVar16 = (float)std::cos((double)fVar8);
  fStack_174 = fVar16;

  fVar8 = *param_4;
  fStack_16c = param_4[1];
  afStack_160[3] = -fVar8;
  fStack_138 = -fStack_16c;
  uStack_134 = 0.0f;
  uStack_130 = 0.0f;
  uStack_12c = 0.0f;
  afStack_160[0] = 0.0f;
  afStack_160[1] = 0.0f;
  afStack_160[2] = fVar8;
  fStack_13c = afStack_160[3];
  fStack_128 = fStack_16c;
  FUN_0053c6f0(afStack_160, &uStack_130, &fStack_13c);

  fVar20 = param_4[2];
  fVar2 = param_4[1];
  fVar3 = *param_4;
  fVar4 = param_4[2];
  fVar5 = param_4[1];
  fVar6 = *param_4;
  for (int k = 0; k < 9; ++k) auStack_124[k] = DAT_007179b0[k];
  fVar20 = (fStack_17c * fVar5 - fStack_178 * fVar6) * 0.0f +
           (fStack_174 * fVar3 - fStack_17c * fVar4) * afStack_160[3] +
           (fStack_178 * fVar20 - fStack_174 * fVar2) * fStack_16c;

  {
    bool doCopy = false;
    uint32_t* puVar11 = nullptr;
    void* puVar19 = nullptr;
    void* uVar10 = nullptr;
    if (fVar20 <= 0.0001f) {
      if (0.0001f < -fVar20) {
        fVar20 = 1.0f / fStack_164;
        puVar19 = auStack_dc;
        uVar10 = FUN_0053c9e0(auStack_70,
                              (fStack_164 - param_4[2]) /
                                  (fVar8 * fVar8 + fStack_16c * fStack_16c));
        uVar10 = FUN_0053c590(auStack_94, uVar10);
        FUN_0053c8d0(auStack_4c, uVar10);
        uVar10 = FUN_0053c9e0(puVar19, fVar20);
        puVar11 = (uint32_t*)FUN_0053c590(auStack_b8, uVar10);
        doCopy = true;
      } else if (param_4[2] < 0.0f) {
        afStack_160[0] = 0.0f;
        afStack_160[1] = 0.0f;
        afStack_160[2] = -1.0f;
        uStack_130 = 0.0f;
        uStack_12c = -1.0f;
        fStack_128 = 0.0f;
        fStack_13c = -1.0f;
        fStack_138 = 0.0f;
        uStack_134 = 0.0f;
        puVar11 = (uint32_t*)FUN_0053c6f0(&fStack_13c, &uStack_130, afStack_160);
        doCopy = true;
      }
    } else {
      fVar20 = 1.0f / fStack_164;
      puVar19 = auStack_b8;
      uVar10 = FUN_0053c9e0(auStack_4c,
                            (fStack_164 - param_4[2]) /
                                (fVar8 * fVar8 + fStack_16c * fStack_16c));
      uVar10 = FUN_0053c4f0(auStack_94, uVar10);
      FUN_0053c8d0(auStack_70, uVar10);
      uVar10 = FUN_0053c9e0(puVar19, fVar20);
      puVar11 = (uint32_t*)FUN_0053c4f0(auStack_dc, uVar10);
      doCopy = true;
    }
    if (doCopy) {
      for (int k = 0; k < 9; ++k) auStack_124[k] = puVar11[k];
    }
  }

  FUN_0053c9e0(auStack_28, fStack_168);
  {
    float* pfVar12 = (float*)FUN_0053ca60(afStack_160, &fStack_17c);
    pfVar1[0] = pfVar12[0];
    pfVar1[1] = pfVar12[1];
    pfVar1[2] = pfVar12[2];
  }
  pfVar1[6] = unaff_retaddr - param_1;
  {
    int iVar9 = rand();
    pfVar1[7] = ((float)iVar9 * 3.051851e-05f - 0.5f) * *(float*)(s + 0x94) +
                *(float*)(s + 0x90);
  }
  *(int16_t*)(pfVar1 + 9) = (int16_t)(*(int16_t*)((uint8_t*)param_4 + 0x26) + 1);
  pfVar1[3] = param_4[3];
  pfVar1[4] = param_4[4];
  pfVar1[5] = param_4[5];

  {
    uint32_t uSrc = (uint32_t)*(uint16_t*)((uint8_t*)param_4 + 0x26);
    uint32_t* puVar11 = (uint32_t*)(intptr_t)(uSrc * 0xc + iStack_148);
    int32_t iDstOff = (int32_t)(((uint32_t)fStack_170 & 0xffff) * 0xc);
    uint32_t* puVar15 = (uint32_t*)(intptr_t)(iStack_148 + iDstOff);
    puVar15[0] = puVar11[0];
    puVar15[1] = puVar11[1];
    puVar15[2] = puVar11[2];
    if (iStack_140 != 0) {
      uint32_t* src = (uint32_t*)(intptr_t)(uSrc * 0xc + iStack_140);
      uint32_t* dst = (uint32_t*)(intptr_t)(iDstOff + iStack_140);
      dst[0] = src[0];
      dst[1] = src[1];
      dst[2] = src[2];
    }
    if (iStack_144 != 0) {
      uint32_t* src = (uint32_t*)(intptr_t)(uSrc * 0x10 + iStack_144);
      uint32_t* dst = (uint32_t*)(intptr_t)(((uint32_t)fStack_170 & 0xffff) * 0x10 + iStack_144);
      dst[0] = src[0];
      dst[1] = src[1];
      dst[2] = src[2];
      dst[3] = src[3];
    }
    if (iStack_14c != 0) {
      *(uint32_t*)(intptr_t)(iStack_14c + ((uint32_t)fStack_170 & 0xffff) * 4) =
          *(uint32_t*)(intptr_t)(iStack_14c + uSrc * 4);
    }
    if (iStack_150 != 0) {
      *(uint32_t*)(intptr_t)(iStack_150 + ((uint32_t)fStack_170 & 0xffff) * 4) =
          *(uint32_t*)(intptr_t)(iStack_150 + uSrc * 4);
    }
  }

LAB_005a9843:
  pfVar1[8] = unaff_retaddr - pfVar1[6];
  if (*(int32_t**)(s + 0xd0) != nullptr) {
    int32_t obj = *(int32_t*)(s + 0xd0);
    void (*cb)(float*) = *(void (**)(float*))(intptr_t)(*(int32_t*)obj + 0x40);
    cb(pfVar1);
  }
  return pfVar1;
}

// 0x5a9880 — observed shape
void FUN_005a9880_recon(int32_t param_1, uint32_t param_2, void* self) {
  uint8_t* s = (uint8_t*)self;
  uint8_t* d = (uint8_t*)(intptr_t)param_1;
  FUN_00552aa0(param_1, param_2);

  *(uint32_t*)(d + 0x48) = *(uint32_t*)(s + 0x48);
  *(uint32_t*)(d + 0x4c) = *(uint32_t*)(s + 0x4c);
  *(uint32_t*)(d + 0x50) = *(uint32_t*)(s + 0x50);
  *(uint32_t*)(d + 0x54) = *(uint32_t*)(s + 0x54);
  *(uint32_t*)(d + 0x58) = *(uint32_t*)(s + 0x58);
  *(uint32_t*)(d + 0x5c) = *(uint32_t*)(s + 0x5c);
  *(uint32_t*)(d + 0x60) = *(uint32_t*)(s + 0x60);
  *(uint32_t*)(d + 0x64) = *(uint32_t*)(s + 0x64);
  *(uint32_t*)(d + 0x68) = *(uint32_t*)(s + 0x68);
  *(uint32_t*)(d + 0x6c) = *(uint32_t*)(s + 0x6c);
  *(uint32_t*)(d + 0x70) = *(uint32_t*)(s + 0x70);
  *(uint32_t*)(d + 0x74) = *(uint32_t*)(s + 0x74);
  *(uint32_t*)(d + 0x78) = *(uint32_t*)(s + 0x78);
  *(uint32_t*)(d + 0x7c) = *(uint32_t*)(s + 0x7c);
  *(uint32_t*)(d + 0x80) = *(uint32_t*)(s + 0x80);
  *(uint32_t*)(d + 0x84) = *(uint32_t*)(s + 0x84);
  *(uint8_t*)(d + 0x88) = *(uint8_t*)(s + 0x88);
  *(uint32_t*)(d + 0x8c) = *(uint32_t*)(s + 0x8c);
  *(uint32_t*)(d + 0x90) = *(uint32_t*)(s + 0x90);
  *(uint32_t*)(d + 0x94) = *(uint32_t*)(s + 0x94);
  *(uint8_t*)(d + 0x98) = *(uint8_t*)(s + 0x98);
  *(uint8_t*)(d + 0x99) = *(uint8_t*)(s + 0x99);
  *(uint32_t*)(d + 0x9c) = *(uint32_t*)(s + 0x9c);
  *(uint32_t*)(d + 0xa0) = *(uint32_t*)(s + 0xa0);
  *(uint32_t*)(d + 0xa4) = *(uint32_t*)(s + 0xa4);
  *(uint16_t*)(d + 0xac) = *(uint16_t*)(s + 0xac);
  *(uint32_t*)(d + 0xb0) = *(uint32_t*)(s + 0xb0);
  *(uint16_t*)(d + 0xb4) = *(uint16_t*)(s + 0xb4);
  *(uint32_t*)(d + 0xb8) = *(uint32_t*)(s + 0xb8);
  *(uint32_t*)(d + 0xbc) = *(uint32_t*)(s + 0xbc);
  *(uint16_t*)(d + 0xc0) = *(uint16_t*)(s + 0xc0);
  *(uint16_t*)(d + 0xc2) = *(uint16_t*)(s + 0xc2);
  *(uint16_t*)(d + 0xc4) = *(uint16_t*)(s + 0xc4);

  void* table = thunk_FUN_00533c78((uint32_t)*(uint16_t*)(s + 0xc0) * 0x28);
  *(void**)(d + 200) = table;

  uint32_t uVar4 = 0;
  if (*(int16_t*)(s + 0xc2) != 0) {
    int32_t iVar3 = 0;
    do {
      uint8_t* srcBase = (uint8_t*)(intptr_t)*(int32_t*)(s + 200);
      uint8_t* dstBase = (uint8_t*)(intptr_t)*(int32_t*)(d + 200);
      *(uint32_t*)(dstBase + 0x18 + iVar3) = *(uint32_t*)(srcBase + 0x18 + iVar3);
      *(uint32_t*)(dstBase + 0x20 + iVar3) = *(uint32_t*)(srcBase + 0x20 + iVar3);
      *(uint32_t*)(dstBase + 0x1c + iVar3) = *(uint32_t*)(srcBase + 0x1c + iVar3);
      {
        uint32_t* src = (uint32_t*)(srcBase + 0xc + iVar3);
        uint32_t* dst = (uint32_t*)(dstBase + 0xc + iVar3);
        uint32_t w0 = src[0];
        uint32_t w1 = src[1];
        uint32_t w2 = src[2];
        dst[0] = w0;
        dst[1] = w1;
        dst[2] = w2;
      }
      {
        uint32_t* src = (uint32_t*)(srcBase + iVar3);
        uint32_t* dst = (uint32_t*)(dstBase + iVar3);
        uint32_t w0 = src[0];
        uint32_t w1 = src[1];
        uint32_t w2 = src[2];
        dst[0] = w0;
        dst[1] = w1;
        dst[2] = w2;
      }
      *(uint16_t*)(dstBase + 0x24 + iVar3) = *(uint16_t*)(srcBase + 0x24 + iVar3);
      *(uint16_t*)(dstBase + 0x26 + iVar3) = *(uint16_t*)(srcBase + 0x26 + iVar3);
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + 0x28;
    } while (uVar4 < *(uint16_t*)(s + 0xc2));
  }

  auto assignRef = [&](int32_t off) {
    int32_t* dstSlot = (int32_t*)(d + off);
    if (*(int32_t**)(s + off) == nullptr) {
      int32_t* cur = (int32_t*)(intptr_t)*dstSlot;
      if (cur != nullptr) {
        int32_t* rc = cur + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
          (*(void (**)(int32_t))*(void**)cur)(1);
        }
        *dstSlot = 0;
      }
    } else {
      int32_t srcObj = *(int32_t*)(s + off);
      void* (*cloneFn)(void*, uint32_t) = *(void* (**)(void*, uint32_t))(*(int32_t*)srcObj + 8);
      int32_t* got = (int32_t*)cloneFn((void*)(intptr_t)srcObj, param_2);
      int32_t* cur = (int32_t*)(intptr_t)*dstSlot;
      if (cur != got) {
        if (cur != nullptr) {
          int32_t* rc = cur + 1;
          *rc = *rc - 1;
          if (*rc == 0) {
            (*(void (**)(int32_t))*(void**)cur)(1);
          }
        }
        *dstSlot = (int32_t)(intptr_t)got;
        if (got != nullptr) {
          int32_t* rc = got + 1;
          *rc = *rc + 1;
        }
      }
    }
  };
  assignRef(0xcc);
  assignRef(0xd0);
  assignRef(0xd4);

  *(uint8_t*)(d + 0xd8) = *(uint8_t*)(s + 0xd8);
  *(uint32_t*)(d + 0xdc) = *(uint32_t*)(s + 0xdc);
  *(uint32_t*)(d + 0xe0) = *(uint32_t*)(s + 0xe0);
  *(uint32_t*)(d + 0xe4) = *(uint32_t*)(s + 0xe4);
  *(uint32_t*)(d + 0xe8) = *(uint32_t*)(s + 0xe8);
  return;
}

// 0x5a9d00 — observed shape
void FUN_005a9d00_recon(int32_t param_1, void* self) {
  uint8_t* s = (uint8_t*)self;
  FUN_00552f70(self);

  auto streamVtbl = [&]() -> int32_t {
    return *(int32_t*)*(int32_t*)(intptr_t)(param_1 + 0x15c);
  };
  auto readFn = [&](void* dst, uint32_t n) {
    (*(void (**)(void*, uint32_t))(intptr_t)(streamVtbl() + 8))(dst, n);
  };
  auto readOne = [&](void* dst) {
    (*(void (**)(void*))(intptr_t)(streamVtbl() + 8))(dst);
  };
  auto readNone = [&]() {
    (*(void (**)(void))(intptr_t)(streamVtbl() + 8))();
  };

  readNone();
  readNone();
  readNone();
  readNone();
  readNone();
  readNone();
  FUN_00535110(self);
  FUN_00535190(self);
  readNone();
  readNone();
  readNone();
  readNone();
  *(uint8_t*)(s + 0x88) = 1;
  readNone();
  readNone();
  readNone();
  readNone();
  readNone();

  // The provider modelled both flag bytes from bits of the buffer address
  // expression rather than from a resolved value; preserved verbatim.
  {
    uint32_t addr = (uint32_t)(uintptr_t)(s + 0x94);
    uint8_t cStack_7f = (uint8_t)(addr >> 8);
    uint8_t cStack_7e = (uint8_t)(addr >> 0x10);
    *(uint8_t*)(s + 0x99) = (uint8_t)(cStack_7e != 0);
    *(uint8_t*)(s + 0x98) = (uint8_t)(cStack_7f != 0);
  }

  readNone();
  readNone();
  readNone();
  FUN_00545cc0(self);
  readNone();
  readNone();
  readNone();
  readNone();
  readOne(s + 0xbc);

  uint16_t* puVar1 = (uint16_t*)(s + 0xc0);
  uint16_t* puVar4 = puVar1;
  readFn(puVar1, 2);
  readFn(s + 0xc2, 2);
  void* uVar2 = thunk_FUN_00533c78((uint32_t)*puVar1 * 0x28);
  uint8_t cVar5 = (uint8_t)((uint32_t)(uintptr_t)puVar4 >> 0x18);
  int32_t iVar3 = 0;
  *(void**)(s + 200) = uVar2;
  uint32_t uStack_cc = 0;
  if (*puVar1 != 0) {
    do {
      FUN_00535110((void*)(intptr_t)param_1);
      FUN_00535110((void*)(intptr_t)param_1);
      readFn((void*)(intptr_t)(iVar3 + 0x18 + *(int32_t*)(s + 200)), 4);
      readFn((void*)(intptr_t)(iVar3 + 0x1c + *(int32_t*)(s + 200)), 4);
      readFn((void*)(intptr_t)(iVar3 + 0x20 + *(int32_t*)(s + 200)), 4);
      readFn((void*)(intptr_t)(iVar3 + 0x24 + *(int32_t*)(s + 200)), 2);
      readFn((void*)(intptr_t)(iVar3 + 0x26 + *(int32_t*)(s + 200)), 2);
      cVar5 = (uint8_t)((uint32_t)(uintptr_t)puVar4 >> 0x18);
      uStack_cc = uStack_cc + 1;
      iVar3 = iVar3 + 0x28;
    } while (uStack_cc < *puVar1);
  }
  FUN_00545cc0(self);
  FUN_00545cc0(self);
  FUN_00545cc0(self);
  if (0x303000e < *(uint32_t*)(intptr_t)(param_1 + 0x1c)) {
    // register-relative stack destination the provider could not resolve.
    uint32_t stackAddr = (uint32_t)(uintptr_t)&uStack_cc - 0xcd;
    readFn((void*)(intptr_t)stackAddr, 1);
    *(uint8_t*)(s + 0xd8) = (uint8_t)(cVar5 != 0);
  }
  return;
}

// 0x5aa060 — observed shape
void FUN_005aa060_recon(uint32_t param_1, void* self) {
  uint8_t* s = (uint8_t*)self;
  FUN_00553060(param_1);
  intptr_t iVar3 = (intptr_t)*(int32_t*)(s + 0x34);
  if (*(int16_t*)(intptr_t)(*(int32_t*)(iVar3 + 0xbc) + 0xc) != *(int16_t*)(s + 0xc0)) {
    operator_delete__(*(void**)(s + 200));
    uint16_t uVar2 = *(uint16_t*)(intptr_t)(*(int32_t*)(iVar3 + 0xbc) + 0xc);
    *(uint16_t*)(s + 0xc0) = uVar2;
    int32_t iVar5 = (int32_t)(intptr_t)thunk_FUN_00533c78((uint32_t)uVar2 * 0x28);
    if (iVar5 == 0) {
      iVar5 = 0;
    } else {
      FUN_004127b0((void*)(intptr_t)iVar5, 0x28, (uint32_t)uVar2, &LAB_005cea70);
    }
    *(int32_t*)(s + 200) = iVar5;
    *(int16_t*)(s + 0xc2) = 0;
  }
  {
    int32_t obj = *(int32_t*)(iVar3 + 0xbc);
    void (*fn)(uint16_t) = *(void (**)(uint16_t))(intptr_t)(*(int32_t*)obj + 0x34);
    fn((uint16_t)*(int16_t*)(s + 0xc2));
  }

  auto assignRef = [&](int32_t off) {
    int32_t* pNew = (int32_t*)(intptr_t)FUN_00545600();
    int32_t* cur = *(int32_t**)(s + off);
    if (cur != pNew) {
      if (cur != nullptr) {
        int32_t* rc = cur + 1;
        *rc = *rc - 1;
        if (*rc == 0) {
          (*(void (**)(int32_t))*(void**)cur)(1);
        }
      }
      *(int32_t**)(s + off) = pNew;
      if (pNew != nullptr) {
        int32_t* rc = pNew + 1;
        *rc = *rc + 1;
      }
    }
  };
  assignRef(0xa8);
  assignRef(0xcc);
  assignRef(0xd0);
  assignRef(0xd4);
  return;
}

// 0x5aa280 — observed shape
void FUN_005aa280_recon(int32_t* param_1, void* self) {
  uint8_t* s = (uint8_t*)self;
  FUN_005530e0(self);

  auto writeVtbl = [&]() -> int32_t {
    return *(int32_t*)(intptr_t)param_1[0x58];
  };
  auto writeNone = [&]() {
    (*(void (**)(void))(intptr_t)(writeVtbl() + 0xc))();
  };
  auto writeFn = [&](void* dst, uint32_t n) {
    (*(void (**)(void*, uint32_t))(intptr_t)(writeVtbl() + 0xc))(dst, n);
  };
  auto selfVtbl = [&]() -> int32_t { return *(int32_t*)param_1; };

  writeNone();
  writeNone();
  writeNone();
  writeNone();
  writeNone();
  writeNone();
  FUN_00535150(param_1);
  FUN_005351e0(self);
  writeNone();
  writeNone();
  writeNone();
  writeNone();
  writeNone();
  writeNone();
  writeNone();
  writeNone();
  writeNone();
  writeNone();
  writeNone();
  writeNone();
  (*(void (**)(void))(intptr_t)(selfVtbl() + 0x2c))();
  writeNone();
  writeNone();
  writeNone();
  writeNone();
  writeNone();
  writeNone();
  writeFn(s + 0xc2, 2);

  uint32_t uStack_d0 = 0;
  if (*(uint16_t*)(s + 0xc0) != 0) {
    int32_t iVar1 = 0;
    do {
      FUN_00535150(param_1);
      FUN_00535150(param_1);
      writeFn((void*)(intptr_t)(iVar1 + 0x18 + *(int32_t*)(s + 200)), 4);
      writeFn((void*)(intptr_t)(iVar1 + 0x1c + *(int32_t*)(s + 200)), 4);
      writeFn((void*)(intptr_t)(iVar1 + 0x20 + *(int32_t*)(s + 200)), 4);
      writeFn((void*)(intptr_t)(iVar1 + 0x24 + *(int32_t*)(s + 200)), 2);
      writeFn((void*)(intptr_t)(iVar1 + 0x26 + *(int32_t*)(s + 200)), 2);
      uStack_d0 = uStack_d0 + 1;
      iVar1 = iVar1 + 0x28;
    } while (uStack_d0 < *(uint16_t*)(s + 0xc0));
  }
  {
    void (*writeSelf)(int32_t) = *(void (**)(int32_t))(intptr_t)(selfVtbl() + 0x2c);
    writeSelf(*(int32_t*)(s + 0xcc));
    writeSelf(*(int32_t*)(s + 0xd0));
    writeSelf(*(int32_t*)(s + 0xd4));
  }

  uint8_t auStack_da[10];
  writeFn(auStack_da - 3, 1);
  return;
}

// 0x5aa5c0 — observed shape
uint32_t FUN_005aa5c0_recon(uint32_t param_1, void* self) {
  uint8_t* s = (uint8_t*)self;
  uint8_t* o = (uint8_t*)(intptr_t)param_1;
  uint8_t* iVar2 = o;
  int8_t cVar3 = FUN_00552bc0(param_1);
  if (cVar3 == 0) {
    return 0;
  }
  if (*(float*)(s + 0x48) != *(float*)(o + 0x48)) return 0;
  if (*(float*)(s + 0x4c) != *(float*)(o + 0x4c)) return 0;
  if (*(float*)(s + 0x50) != *(float*)(o + 0x50)) return 0;
  if (*(float*)(s + 0x54) != *(float*)(o + 0x54)) return 0;
  if (*(float*)(s + 0x58) != *(float*)(o + 0x58)) return 0;
  if (*(float*)(s + 0x5c) != *(float*)(o + 0x5c)) return 0;
  cVar3 = FUN_00428470((int32_t)(intptr_t)(o + 0x60));
  if (cVar3 != 0) return 0;
  cVar3 = FUN_0050b0f0((int32_t)(intptr_t)(o + 0x6c));
  if (cVar3 != 0) return 0;
  if (*(float*)(s + 0x7c) != *(float*)(o + 0x7c)) return 0;
  if (*(float*)(s + 0x80) != *(float*)(o + 0x80)) return 0;
  if (*(float*)(s + 0x84) != *(float*)(o + 0x84)) return 0;
  if (*(int8_t*)(s + 0x88) != *(int8_t*)(o + 0x88)) return 0;
  if (*(float*)(s + 0x8c) != *(float*)(o + 0x8c)) return 0;
  if (*(float*)(s + 0x90) != *(float*)(o + 0x90)) return 0;
  if (*(float*)(s + 0x94) != *(float*)(o + 0x94)) return 0;
  if (*(int8_t*)(s + 0x98) != *(int8_t*)(o + 0x98)) return 0;
  if (*(int8_t*)(s + 0x99) != *(int8_t*)(o + 0x99)) return 0;
  if (*(float*)(s + 0x9c) != *(float*)(o + 0x9c)) return 0;
  if (*(float*)(s + 0xa0) != *(float*)(o + 0xa0)) return 0;
  if (*(float*)(s + 0xa4) != *(float*)(o + 0xa4)) return 0;
  if (*(int16_t*)(s + 0xac) != *(int16_t*)(o + 0xac)) return 0;
  if (*(float*)(s + 0xb0) != *(float*)(o + 0xb0)) return 0;
  if (*(int16_t*)(s + 0xb4) != *(int16_t*)(o + 0xb4)) return 0;
  if (*(float*)(s + 0xb8) != *(float*)(o + 0xb8)) return 0;
  if (*(float*)(s + 0xbc) != *(float*)(o + 0xbc)) return 0;
  if (*(int16_t*)(s + 0xc0) != *(int16_t*)(o + 0xc0)) return 0;
  uint16_t uVar1 = *(uint16_t*)(s + 0xc2);
  if (uVar1 != *(uint16_t*)(o + 0xc2)) return 0;
  if (*(int8_t*)(s + 0xd8) != *(int8_t*)(o + 0xd8)) return 0;

  param_1 = 0;
  if (uVar1 != 0) {
    intptr_t iVar6 = (intptr_t)*(int32_t*)(s + 200);
    float* pfVar5 = (float*)(intptr_t)(*(int32_t*)(iVar2 + 200) + 0x18);
    int32_t iVar4 = *(int32_t*)(iVar2 + 200) - (int32_t)iVar6;
    do {
      cVar3 = FUN_00428470(iVar4 + (int32_t)iVar6);
      if (cVar3 != 0) return 0;
      cVar3 = FUN_00428470((int32_t)(intptr_t)(pfVar5 - 3));
      if (cVar3 != 0) return 0;
      if (*(float*)(intptr_t)(iVar6 + 0x18) != pfVar5[0]) return 0;
      if (*(float*)(intptr_t)(iVar6 + 0x1c) != pfVar5[1]) return 0;
      if (*(float*)(intptr_t)(iVar6 + 0x20) != pfVar5[2]) return 0;
      if (*(int16_t*)(intptr_t)(iVar6 + 0x24) != *(int16_t*)(pfVar5 + 3)) return 0;
      if (*(int16_t*)(intptr_t)(iVar6 + 0x26) != *(int16_t*)((uint8_t*)pfVar5 + 0xe)) return 0;
      param_1 = param_1 + 1;
      pfVar5 = pfVar5 + 10;
      iVar6 = iVar6 + 0x28;
    } while (param_1 < uVar1);
  }

  if (*(int32_t*)(s + 0xa8) != 0) {
    if (*(int32_t*)(iVar2 + 0xa8) == 0) return 0;
  } else if (*(int32_t*)(iVar2 + 0xa8) != 0) {
    return 0;
  }

  if (*(int32_t**)(s + 0xcc) != nullptr) {
    int32_t obj = *(int32_t*)(s + 0xcc);
    int8_t (*cmp)(int32_t) = *(int8_t (**)(int32_t))(intptr_t)(*(int32_t*)obj + 0x1c);
    cVar3 = cmp(*(int32_t*)(iVar2 + 0xcc));
    if (cVar3 == 0) return 0;
  }
  if (*(int32_t**)(s + 0xd0) != nullptr) {
    int32_t obj = *(int32_t*)(s + 0xd0);
    int8_t (*cmp)(int32_t) = *(int8_t (**)(int32_t))(intptr_t)(*(int32_t*)obj + 0x1c);
    cVar3 = cmp(*(int32_t*)(iVar2 + 0xd0));
    if (cVar3 == 0) return 0;
  }
  if (*(int32_t**)(s + 0xd4) == nullptr) {
    return 1;
  }
  {
    int32_t obj = *(int32_t*)(s + 0xd4);
    int8_t (*cmp)(int32_t) = *(int8_t (**)(int32_t))(intptr_t)(*(int32_t*)obj + 0x1c);
    cVar3 = cmp(*(int32_t*)(iVar2 + 0xd4));
    if (cVar3 != 0) return 1;
  }
  return 0;
}

// 0x5aa9b0 — observed shape
void FUN_005aa9b0_recon(uint32_t param_1, uint32_t param_2, int32_t param_3, void* self) {
  uint8_t* s = (uint8_t*)self;
  uint8_t* psz = (uint8_t*)(intptr_t)param_3;
  if (*(uint16_t*)(psz + 0x24) < *(uint16_t*)(s + 0xac)) {
    int32_t iVar1 = rand();
    if ((float)iVar1 * 3.051851e-05f <= *(float*)(s + 0xb0)) {
      uint32_t local_f0 = (uint32_t)*(uint16_t*)(s + 0xb4);
      if ((uint32_t)*(uint16_t*)(s + 0xc0) <
          (uint32_t)*(uint16_t*)(s + 0xc2) + local_f0) {
        local_f0 = (uint32_t)*(uint16_t*)(s + 0xc0) -
                   (uint32_t)*(uint16_t*)(s + 0xc2);
      }
      float local_ec = 0.0f;
      float local_e8 = 0.0f;
      float local_e4 = 0.0f;
      float local_dc = 0.0f;
      float local_d8 = 0.0f;
      float local_d4 = 0.0f;
      uint8_t local_cc[12];
      uint8_t local_c0[12];
      uint8_t local_b4[36];
      uint32_t local_90[9];
      uint8_t local_6c[36];
      uint32_t local_48[9];
      uint8_t local_24[36];

      if (*(int32_t*)(s + 0xa8) != 0) {
        intptr_t local_d0 = (intptr_t)*(int32_t*)(s + 0x34);
        intptr_t iView = (intptr_t)*(int32_t*)(local_d0 + 0x24);
        intptr_t local_e0 = local_d0 + 0x38;
        FUN_0053c8d0(local_b4, (void*)local_e0);
        {
          uint32_t* src = (uint32_t*)(intptr_t)(*(int32_t*)(s + 0xa8) + 0x6c);
          for (int k = 0; k < 9; ++k) local_90[k] = src[k];
        }
        uint32_t* puVar2 = (uint32_t*)FUN_0053ce40(local_6c, local_90);
        intptr_t iVar5 = (intptr_t)*(int32_t*)(s + 0xa8);
        for (int k = 0; k < 9; ++k) local_48[k] = puVar2[k];
        local_e4 = *(float*)(iVar5 + 0x98) - *(float*)(iView + 0x98);
        local_e8 = *(float*)(iVar5 + 0x94) - *(float*)(iView + 0x94);
        local_ec = *(float*)(iVar5 + 0x90) - *(float*)(iView + 0x90);
        intptr_t iOrigin = local_d0 + 0x5c;
        FUN_0053cc20(local_6c);
        float* pfVar3 = (float*)FUN_0053ca60((float*)local_cc, (float*)iOrigin);
        FUN_0053cc20(local_24);
        float* pfVar4 = (float*)FUN_0053ca60((float*)local_c0, &local_ec);
        local_ec = pfVar4[0] - pfVar3[0];
        local_e8 = pfVar4[1] - pfVar3[1];
        local_e4 = pfVar4[2] - pfVar3[2];
        local_dc = local_ec;
        local_d8 = local_e8;
        local_d4 = local_e4;
      }
      if ((int16_t)local_f0 != 0) {
        local_f0 = local_f0 & 0xffff;
        do {
          FUN_005a9060_recon(param_1, param_2, (float*)local_48, &local_ec,
                             (float)(intptr_t)param_3, self);
          local_f0 = local_f0 - 1;
        } while (local_f0 != 0);
      }
    }
  }
  return;
}

// 0x5aab90 — observed shape
uint32_t FUN_005aab90_recon(uint32_t param_1, uint32_t unaff_retaddr, void* self) {
  uint8_t* s = (uint8_t*)self;
  void* local_18;
  int32_t iVar3 = (int32_t)(intptr_t)thunk_FUN_00533c78(0xf4);
  if (iVar3 == 0) {
    local_18 = nullptr;
  } else {
    FUN_005a8a00_recon((void*)(intptr_t)iVar3);
    local_18 = (void*)(intptr_t)iVar3;
  }
  FUN_005a9880_recon((int32_t)(intptr_t)local_18, param_1, self);
  if (*(int32_t*)(s + 0x34) == 0) {
    return (uint32_t)(uintptr_t)local_18;
  }
  int32_t* piVar1 = *(int32_t**)(intptr_t)(*(int32_t*)(s + 0x34) + 0xbc);
  if (piVar1 == nullptr) {
    return (uint32_t)(uintptr_t)local_18;
  }
  uint32_t uVar4 = (uint32_t)*(uint16_t*)((uint8_t*)piVar1 + 0xc);

  uint32_t* local_14 = (uint32_t*)thunk_FUN_00533c78(uVar4 * 0xc);
  if (local_14 == nullptr) {
    local_14 = nullptr;
  } else {
    FUN_004127b0(local_14, 0xc, uVar4, &LAB_005cea70);
  }
  {
    uint32_t* puVar5 = (uint32_t*)(intptr_t)piVar1[8];
    for (uint32_t k = 0; k < uVar4 * 3; ++k) local_14[k] = puVar5[k];
  }

  uint32_t* local_20 = nullptr;
  if (piVar1[10] != 0) {
    local_20 = (uint32_t*)thunk_FUN_00533c78(uVar4 << 4);
    if (local_20 == nullptr) {
      local_20 = nullptr;
    } else {
      FUN_004127b0(local_20, 0x10, uVar4, &LAB_004b1250);
    }
    uint32_t* puVar5 = (uint32_t*)(intptr_t)piVar1[10];
    for (uint32_t k = 0; k < uVar4 * 4; ++k) local_20[k] = puVar5[k];
  }

  uint32_t* local_1c = nullptr;
  if (piVar1[9] != 0) {
    local_1c = (uint32_t*)thunk_FUN_00533c78(uVar4 * 0xc);
    if (local_1c == nullptr) {
      local_1c = nullptr;
    } else {
      FUN_004127b0(local_1c, 0xc, uVar4, &LAB_005cea70);
    }
    uint32_t* puVar5 = (uint32_t*)(intptr_t)piVar1[9];
    for (uint32_t k = 0; k < uVar4 * 3; ++k) local_1c[k] = puVar5[k];
  }

  uint32_t* local_10 = nullptr;
  if (piVar1[0x13] != 0) {
    local_10 = (uint32_t*)thunk_FUN_00533c78(uVar4 << 4);
    if (local_10 == nullptr) {
      local_10 = nullptr;
    } else {
      FUN_004127b0(local_10, 0x10, uVar4, &LAB_005cea70);
    }
    uint32_t* puVar5 = (uint32_t*)(intptr_t)piVar1[0x13];
    for (uint32_t k = 0; k < uVar4 * 4; ++k) local_10[k] = puVar5[k];
  }

  auto finish = [&](int32_t* piVar6) {
    if (piVar6 == nullptr) {
      return;
    }
    {
      uint32_t* puVar7 = (uint32_t*)thunk_FUN_00533c78(uVar4 << 2);
      uint32_t* puVar5 = (uint32_t*)(intptr_t)piVar1[0x10];
      for (uint32_t k = 0; k < uVar4; ++k) puVar7[k] = puVar5[k];
      FUN_00559050(puVar7);
    }
    int32_t iVtbl = *piVar6;
    uint32_t (*fnGetId)(void) = *(uint32_t (**)(void))(intptr_t)(*piVar1 + 0x38);
    uint32_t uVar8 = fnGetId();
    void (*fnSetId)(uint32_t) = *(void (**)(uint32_t))(intptr_t)(iVtbl + 0x34);
    fnSetId(uVar8);
    {
      uint32_t* puVar7 = (uint32_t*)thunk_FUN_00533c78(unaff_retaddr);
      uint32_t* puVar5 = (uint32_t*)(intptr_t)piVar1[0x12];
      for (uint32_t k = 0; k < (unaff_retaddr >> 2); ++k) puVar7[k] = puVar5[k];
      {
        uint32_t done = unaff_retaddr & ~3u;
        uint8_t* dst = (uint8_t*)puVar7 + done;
        uint8_t* src = (uint8_t*)puVar5 + done;
        for (uint32_t k = 0; k < (unaff_retaddr & 3); ++k) dst[k] = src[k];
      }
      FUN_00559070(puVar7);
    }
    // uVar4 is a decompiler register artifact here, not an object pointer;
    // translated literally as the listing prints it.
    int32_t objp = *(int32_t*)(intptr_t)(uVar4 + 0x34);
    void (*fnAttach)(int32_t*) = *(void (**)(int32_t*))(intptr_t)(*(int32_t*)objp + 0x74);
    fnAttach(piVar6);
  };

  void* puVar5 = (*(void* (**)(void))(intptr_t)(*piVar1 + 4))();
  while (true) {
    if (puVar5 == nullptr) {
      int32_t iVar5 = (int32_t)(intptr_t)thunk_FUN_00533c78(0x50);
      if (iVar5 != 0) {
        finish((int32_t*)FUN_005591e0((int32_t)uVar4, local_14, local_1c, local_20, local_10));
      }
      return (uint32_t)(uintptr_t)local_18;
    }
    if (puVar5 == (void*)&DAT_00727d98) {
      int32_t iVar5 = (int32_t)(intptr_t)thunk_FUN_00533c78(0x58);
      int32_t* piVar6;
      if (iVar5 == 0) {
        piVar6 = nullptr;
      } else {
        piVar6 = (int32_t*)FUN_00565310((int32_t)uVar4, local_14, local_1c, local_20, local_10);
      }
      intptr_t iChild = (intptr_t)piVar1[0x14];
      uint32_t uVar9 = *(uint32_t*)(iChild + 0xc0);
      uint32_t uVar10 = 0;
      if (uVar9 != 0) {
        do {
          if (uVar10 < *(uint32_t*)(iChild + 0xc0)) {
            int32_t* piVar2 = *(int32_t**)(intptr_t)(*(int32_t*)(iChild + 0xb8) + uVar10 * 4);
            if (piVar2 != nullptr) {
              uint32_t (*fn)(uint32_t) = *(uint32_t (**)(uint32_t))(intptr_t)(*piVar2 + 8);
              uint32_t uVar8 = fn(param_1);
              FUN_005651a0(uVar10, uVar8);
            }
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 < uVar9);
      }
      finish(piVar6);
      return (uint32_t)(uintptr_t)local_18;
    }
    puVar5 = *(void**)((uint8_t*)puVar5 + 4);
  }
}

// 0x5aaeb0 — observed shape
void FUN_005aaeb0_recon(int32_t param_1) {
  intptr_t iVar2 = (intptr_t)param_1;
  FUN_005531c0(param_1);
  param_1 = FUN_00557b10(DAT_00728b20);
  uint32_t uVar1 = *(uint32_t*)(iVar2 + 0xc);
  if (*(uint32_t*)(iVar2 + 8) <= uVar1) {
    FUN_006b34a0(*(int32_t*)(iVar2 + 0x14) + (int32_t)uVar1);
  }
  FUN_005606f0(uVar1, (uint32_t*)&param_1);
  return;
}

// 0x5aaf00 — observed shape
void FUN_005aaf00_recon(float param_1, float param_2, float* param_3, int32_t param_4,
                        float param_5, void* self) {
  uint8_t* s = (uint8_t*)self;
  float local_10 = *(float*)(s + 0x44);
  if (((uint8_t*)&param_5)[0] == 0) {
    param_3[6] = (param_1 - local_10) + param_3[6];
  } else {
    local_10 = param_1 - param_3[6];
  }
  if (param_3[6] <= param_3[7]) {
    if (*(int32_t**)(s + 0xd0) != nullptr) {
      int32_t obj = *(int32_t*)(s + 0xd0);
      void (*cb)(float, float*) = *(void (**)(float, float*))(intptr_t)(*(int32_t*)obj + 0x3c);
      cb(param_1 + param_2, param_3);
    }
    param_5 = param_1;
    int32_t* piVar5 = nullptr;
    if (*(int32_t**)(s + 0xd4) != nullptr) {
      int32_t obj = *(int32_t*)(s + 0xd4);
      int32_t* (*query)(float, float*, float*) =
          *(int32_t* (**)(float, float*, float*))(intptr_t)(*(int32_t*)obj + 0x44);
      piVar5 = query(local_10, &param_5, param_3);
    }
    if (piVar5 == nullptr) {
      param_5 = local_10;
    } else {
      int8_t (*cb2)(float, float*) =
          *(int8_t (**)(float, float*))(intptr_t)(*piVar5 + 0x3c);
      int8_t cVar4 = cb2(param_1 + param_2, param_3);
      if (cVar4 == 0) {
        return;
      }
    }
    param_5 = param_1 - param_5;
    float* pfVar1 = (float*)(intptr_t)(*(int32_t*)(param_4 + 0x20) +
                                       (uint32_t)*(uint16_t*)((uint8_t*)param_3 + 0x26) * 0xc);
    float fVar2 = param_3[1];
    float fVar3 = param_3[2];
    pfVar1[0] = param_5 * param_3[0] + pfVar1[0];
    pfVar1[1] = param_5 * fVar2 + pfVar1[1];
    pfVar1[2] = param_5 * fVar3 + pfVar1[2];
    param_3[8] = param_1;
    return;
  }
  if (*(uint8_t*)(s + 0x99) != 0) {
    // The provider passes register-resident values for the first two
    // arguments here; the listing prints the stack slot for the first.
    FUN_005aa9b0_recon((uint32_t)(intptr_t)&param_1, 0, (int32_t)(intptr_t)param_3, self);
  }
  FUN_005a8fe0_recon((int32_t*)(intptr_t)param_3, self);
  return;
}

// 0x5ab040 — observed shape
void FUN_005ab040_recon(float param_1, void* self) {
  uint8_t* s = (uint8_t*)self;
  intptr_t iVar16 = (intptr_t)*(int32_t*)(s + 0x34);
  int32_t* piVar3 = *(int32_t**)(iVar16 + 0xbc);

  if (*(uint8_t*)(s + 0xec) != 0) {
    *(float*)(s + 0x44) = param_1;
    *(float*)(s + 0xf0) = param_1;
  }
  float local_104 = 0.0f;
  int32_t* local_e0 = piVar3;
  if (param_1 < *(float*)(s + 0x44)) {
    local_104 = (*(float*)(s + 0x1c) - *(float*)(s + 0x18)) * *(float*)(s + 0x10);
    if (*(uint8_t*)(s + 0x88) == 0) {
      *(float*)(s + 0x44) = *(float*)(s + 0x44) - local_104;
    } else {
      *(uint32_t*)(s + 0xf0) = 0;
      *(uint32_t*)(s + 0x44) = 0;
      {
        void (*fn)(int32_t) = *(void (**)(int32_t))(intptr_t)(*piVar3 + 0x34);
        fn(0);
      }
      *(int16_t*)(s + 0xc2) = 0;
    }
  }
  *(int16_t*)(s + 0xc4) = 0;
  if (*(int16_t*)(s + 0xc2) != 0) {
    intptr_t iVar15 = (intptr_t)*(int32_t*)(s + 200);
    *(int16_t*)(s + 0xc4) = 1;
    while (iVar15 != 0) {
      FUN_005aaf00_recon(param_1, local_104, (float*)iVar15,
                         (int32_t)(intptr_t)piVar3, 0.0f, self);
      uint16_t uVar5 = *(uint16_t*)(s + 0xc4);
      if (*(uint16_t*)(s + 0xc2) <= uVar5) break;
      *(uint16_t*)(s + 0xc4) = (uint16_t)(uVar5 + 1);
      iVar15 = (intptr_t)(*(int32_t*)(s + 200) + (uint32_t)uVar5 * 0x28);
    }
  }

  float fVar4 = *(float*)(s + 0xf0);
  uint16_t uVar5 = 0;
  if (param_1 < *(float*)(s + 0x80)) {
    local_104 = param_1;
  } else {
    float fVar1 = *(float*)(s + 0x80);
    if (fVar1 < *(float*)(s + 0xf0)) {
      fVar1 = *(float*)(s + 0xf0);
    }
    float fVar2 = param_1;
    if (*(float*)(s + 0x84) < param_1) {
      fVar2 = *(float*)(s + 0x84);
    }
    if (fVar2 <= fVar1) {
      local_104 = param_1;
    } else {
      uVar5 = (uint16_t)(uintptr_t)FUN_005f0ddc();
      uint32_t uStack_dc = (uint32_t)uVar5;
      // NEEDS_MANUAL: the divisor is the residual x87 ST1 value left by
      // FUN_005f0ddc (listing: extraout_ST1); no parameter or return slot
      // exposes it.
      long double extraout_ST1 = 0.0L;
      local_104 = (float)((long double)uStack_dc / extraout_ST1 + (long double)fVar4);
    }
  }

  float fStack_ec = *(float*)&DAT_00727430;
  int32_t iVar15 = *(int32_t*)(s + 0xa8);
  float fStack_e8 = *(float*)&DAT_00727434;
  float fStack_e4 = *(float*)&DAT_00727438;
  uint32_t auStack_cc[9];
  uint8_t auStack_a8[12];
  uint8_t auStack_9c[36];
  uint8_t auStack_78[12];
  uint32_t auStack_6c[9];
  uint8_t auStack_48[36];
  uint8_t auStack_24[36];
  for (int k = 0; k < 9; ++k) auStack_cc[k] = DAT_007179b0[k];

  if (iVar15 != 0) {
    intptr_t iView = (intptr_t)*(int32_t*)(iVar16 + 0x24);
    FUN_0053c8d0(auStack_9c, (void*)(iVar16 + 0x38));
    {
      uint32_t* puVar7 = (uint32_t*)(intptr_t)(*(int32_t*)(s + 0xa8) + 0x6c);
      for (int k = 0; k < 9; ++k) auStack_6c[k] = puVar7[k];
    }
    {
      uint32_t* puVar7 = (uint32_t*)FUN_0053ce40(auStack_48, auStack_6c);
      intptr_t iOwner = (intptr_t)*(int32_t*)(s + 0xa8);
      for (int k = 0; k < 9; ++k) auStack_cc[k] = puVar7[k];
      float fStack_d0 = *(float*)(iOwner + 0x98) - *(float*)(iView + 0x98);
      float fStack_d4 = *(float*)(iOwner + 0x94) - *(float*)(iView + 0x94);
      float fStack_d8 = *(float*)(iOwner + 0x90) - *(float*)(iView + 0x90);
      intptr_t iOrigin = iVar16 + 0x5c;
      FUN_0053cc20(auStack_48);
      float* pfVar8 = (float*)FUN_0053ca60((float*)auStack_a8, (float*)iOrigin);
      FUN_0053cc20(auStack_24);
      float* pfVar9 = (float*)FUN_0053ca60((float*)auStack_78, &fStack_d8);
      fStack_ec = pfVar9[0] - pfVar8[0];
      fStack_e8 = pfVar9[1] - pfVar8[1];
      fStack_e4 = pfVar9[2] - pfVar8[2];
    }
  }

  while (uVar5 != 0) {
    uVar5 = (uint16_t)(uVar5 - 1);
    if (!(*(uint16_t*)(s + 0xc2) + 1 < (uint32_t)*(uint16_t*)(s + 0xc0))) {
      break;
    }
    float* pNew = FUN_005a9060_recon(param_1, *(uint32_t*)(s + 0xf0),
                                     (float*)auStack_cc, &fStack_ec, 0.0f, self);
    FUN_005aaf00_recon(param_1, 0.0f, pNew, (int32_t)(intptr_t)local_e0, 1.0f, self);
  }

  *(float*)(s + 0xf0) = local_104;
  if (*(uint8_t*)(s + 0xd8) == 0) {
    int32_t iSlot = local_e0[8];
    uint16_t (*fn)(int32_t) = *(uint16_t (**)(int32_t))(intptr_t)(*local_e0 + 0x38);
    uint16_t uVar6 = fn(iSlot);
    FUN_00548120(uVar6, iSlot);
  } else {
    *(uint32_t*)(intptr_t)(*(int32_t*)(iVar16 + 0xbc) + 0x1c) = *(uint32_t*)(s + 0xe8);
    intptr_t p = (intptr_t)*(int32_t*)(iVar16 + 0xbc);
    float fVar2 = *(float*)(s + 0xe0);
    float fVar1 = *(float*)(s + 0xe4);
    *(float*)(p + 0x10) = fStack_ec + *(float*)(s + 0xdc);
    *(float*)(p + 0x14) = fStack_e8 + fVar2;
    *(float*)(p + 0x18) = fStack_e4 + fVar1;
  }
  *(float*)(s + 0x44) = param_1;
  *(uint8_t*)(s + 0xec) = 0;
  return;
}

// 0x5ab5d0 — observed shape
void FUN_005ab5d0_recon(uint32_t param_1, float* param_2, void* self) {
  uint8_t* s = (uint8_t*)self;
  float fVar2 = 1.0f / *(float*)(s + 0x2c);
  float fVar1 = fVar2 * (*(float*)(s + 0x1c) - *(float*)(s + 0x34));
  float fVar3 = fVar2 * (*(float*)(s + 0x20) - *(float*)(s + 0x38));
  fVar2 = (*(float*)(s + 0x24) - *(float*)(s + 0x3c)) * fVar2;
  float fVar4 = fVar1 * param_2[0] + fVar3 * param_2[1] + fVar2 * param_2[2];
  fVar1 = fVar1 * fVar4;
  fVar3 = fVar3 * fVar4;
  fVar2 = fVar2 * fVar4;
  fVar4 = param_2[0] - (fVar1 + fVar1);
  param_2[0] = fVar4;
  fVar3 = param_2[1] - (fVar3 + fVar3);
  param_2[1] = fVar3;
  fVar2 = param_2[2] - (fVar2 + fVar2);
  param_2[2] = fVar2;
  fVar1 = *(float*)(s + 0x14);
  param_2[0] = fVar4 * fVar1;
  param_2[1] = fVar3 * fVar1;
  param_2[2] = fVar2 * fVar1;
  FUN_005adec0(self);
  return;
}

// 0x5ab6a0 — observed shape
void FUN_005ab6a0_recon(void* self) {
  void** o = (void**)self;
  *o = &PTR_FUN_006c5350;
  void* p = o[3];
  if (p != nullptr) {
    int32_t* rc = (int32_t*)p + 1;
    *rc = *rc - 1;
    if (*rc == 0) {
      (*(void (**)(int32_t))*(void**)p)(1);
    }
    o[3] = nullptr;
  }
  p = o[3];
  if (p != nullptr) {
    int32_t* rc = (int32_t*)p + 1;
    *rc = *rc - 1;
    if (*rc == 0) {
      (*(void (**)(int32_t))*(void**)p)(1);
    }
  }
  FUN_00538400(self);
  return;
}

// 0x5ab6f0 — observed shape
uint32_t FUN_005ab6f0_recon(float param_1, float* param_2, float* param_3, void* self) {
  uint8_t* s = (uint8_t*)self;
  intptr_t iGrid = (intptr_t)*(int32_t*)(s + 0x10);
  intptr_t iSys = (intptr_t)*(int32_t*)(iGrid + 0x34);
  intptr_t iObj = (intptr_t)*(int32_t*)(iSys + 0xbc);
  float* pfVar1 = (float*)(
      (intptr_t)*(int32_t*)(iObj + 0x20) +
      (uint32_t)*(uint16_t*)((uint8_t*)param_3 + 0x26) * 0xc);
  uint8_t bVar10 = 0;
  float fVar7 = *pfVar1 - *(float*)(s + 0x34);
  float fVar4 = pfVar1[1] - *(float*)(s + 0x38);
  float fVar3 = pfVar1[2] - *(float*)(s + 0x3c);
  float fVar2 = (fVar4 * fVar4 + fVar7 * fVar7 + fVar3 * fVar3) - *(float*)(s + 0x30);
  bool bVar8;
  bool skipTail = false;
  if (-fVar2 <= 0.001f) {
    bVar8 = false;
    if (fVar2 <= 0.001f) {
      skipTail = true;
    }
  } else {
    bVar8 = true;
  }
  if (!skipTail) {
    fVar7 = -(fVar4 * param_3[1] + fVar3 * param_3[2] + fVar7 * param_3[0]);
    if (bVar8 || 0.0f < fVar7) {
      fVar2 = 1.0f / (param_3[0] * param_3[0] + param_3[2] * param_3[2] +
                      param_3[1] * param_3[1]);
      fVar7 = fVar7 * fVar2;
      float fVar5 = (fVar7 * param_3[0] + *pfVar1) - *(float*)(s + 0x34);
      fVar4 = (fVar7 * param_3[1] + pfVar1[1]) - *(float*)(s + 0x38);
      fVar3 = (fVar7 * param_3[2] + pfVar1[2]) - *(float*)(s + 0x3c);
      fVar3 = fVar5 * fVar5 + fVar4 * fVar4 + fVar3 * fVar3;
      if (bVar8 || fVar3 < *(float*)(s + 0x30)) {
        fVar2 = (float)std::sqrt((double)(fVar2 * (*(float*)(s + 0x30) - fVar3)));
        if (bVar8) {
          fVar7 = fVar2 + fVar7;
        } else {
          fVar7 = fVar7 - fVar2;
        }
        if (fVar7 < param_2[0] - param_1) {
          bVar10 = 1;
          param_2[0] = param_1 + fVar7;
          *(float*)(s + 0x28) = param_1 + fVar7;
          float fVar5b = param_3[1];
          float fVar3b = param_3[2];
          float fVar4b = pfVar1[1];
          float fVar5c = pfVar1[2];
          *(float*)(s + 0x1c) = fVar7 * param_3[0] + *pfVar1;
          *(float*)(s + 0x20) = fVar7 * fVar5b + fVar4b;
          *(float*)(s + 0x24) = fVar7 * fVar3b + fVar5c;
        }
      }
    }
  }

  {
    int32_t* piVar6 = *(int32_t**)(s + 0xc);
    if (piVar6 != nullptr) {
      uint8_t* puVar11 = (uint8_t*)(*(void* (**)(void))(intptr_t)(*piVar6 + 4))();
      uint8_t bVar9 = 0;
      while (puVar11 != nullptr) {
        if (puVar11 == (uint8_t*)&DAT_00728b70) {
          bVar9 = 1;
          break;
        }
        puVar11 = *(uint8_t**)(puVar11 + 4);
      }
      int32_t* pTarget = (int32_t*)(intptr_t)(
          (uint32_t)(-(int32_t)bVar9) & (uint32_t)(uintptr_t)piVar6);
      if (pTarget != nullptr) {
        uint32_t (*fn)(float, float*, float*) =
            *(uint32_t (**)(float, float*, float*))(intptr_t)(*pTarget + 0x44);
        uint32_t uVar12 = fn(param_1, param_2, param_3);
        if (uVar12 != 0) {
          return uVar12;
        }
      }
    }
  }
  return (uint32_t)(-(int32_t)bVar10) & (uint32_t)(uintptr_t)s;
}
