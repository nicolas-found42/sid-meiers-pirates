// mass_0286 reconstruction — Sid Meier's Pirates! (2004) PE32 i386
#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// The provider types several HRESULT-returning procedures as float.  These
// helpers keep the exact EAX bit pattern when a float slot carries an HRESULT.
static inline float bits_to_float(int32_t v) { float f; std::memcpy(&f, &v, 4); return f; }
static inline int32_t hr_of(float f) { int32_t v; std::memcpy(&v, &f, 4); return v; }
static inline int32_t as_hr(float f) { return hr_of(f); }

// Out-of-batch helpers and globals (declared; not defined here).
extern void FUN_0062a46a(uint32_t param_1);
extern void FUN_006142c8();
extern int FUN_0062c5a3(void* self, uint32_t param_1);
extern int FUN_0060f68b();
extern int FUN_006253a7(uint32_t a, uint32_t b, uint32_t c, uint32_t d, void* e, uint32_t f, void* g, uint32_t h);
extern int FUN_0060f796();
extern int FUN_005f8091(void* a, void* b);
extern void FUN_0060f728(int param_1);
extern void FUN_00615ccd();
extern void FUN_0060d2b8();
extern void FUN_0060fcd3(void* a, const void* b, void* c, const char* msg);
extern int FUN_0062a64e(void* a, uint32_t b, uint32_t c);
extern uint64_t FUN_0062a5d2(void* self);
extern int FUN_0062542f(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, void* f, void* g);
extern int FUN_006294f9(void* a, void* b);
extern void* FUN_00533c78(uint32_t size);
extern int FUN_0062a802(void* a, void* b);
extern void FUN_0062a62d(int param_1);
extern int FUN_0062f194(uint32_t a, int b);
extern uint32_t FUN_0062aba8(uint32_t a, void* b, void* c);
extern int FUN_0062c50d(void* self, uint32_t param_1);
// 0x62c6a5 observed here as an EDX:EAX pair (low half = node, high half = out buffer).
extern uint64_t FUN_0062c6a5_pair(void* self, uint32_t param_1);
extern uint32_t FUN_0062eccf(uint32_t a, char* b, void* c);
extern uint32_t DAT_006e213c[];

// 0x62c624 — observed shape
int FUN_62c624(void* self, uint8_t* param_1) {
  int iVar2;
  if (reinterpret_cast<uint8_t*>(reinterpret_cast<uint32_t>(param_1) & 0x7fffffffu) == param_1) {
    int head = *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 0x348);
    for (iVar2 = head; iVar2 != 0; iVar2 = *reinterpret_cast<int*>(iVar2 + 0x34)) {
      int iVar3;
      if (param_1 == nullptr) {
        iVar3 = *reinterpret_cast<int*>(iVar2 + 0x20);
        if (iVar3 == 0) return iVar2;
      }
      else {
        uint8_t* pbVar5 = *reinterpret_cast<uint8_t**>(iVar2 + 0x20);
        if (pbVar5 != nullptr) {
          uint8_t* pbVar4 = param_1;
          uint8_t b = 1;
          do {
            uint8_t b1 = *pbVar4;
            bool less1 = b1 < *pbVar5;
            if (b1 != *pbVar5) {
              iVar3 = (1 - (uint32_t)less1) - (uint32_t)(less1 != 0);
              goto LAB_62c68f;
            }
            if (b1 == 0) break;
            uint8_t b2 = pbVar4[1];
            bool less2 = b2 < pbVar5[1];
            if (b2 != pbVar5[1]) {
              iVar3 = (1 - (uint32_t)less2) - (uint32_t)(less2 != 0);
              goto LAB_62c68f;
            }
            pbVar4 = pbVar4 + 2;
            pbVar5 = pbVar5 + 2;
            b = b2;
          } while (b != 0);
          iVar3 = 0;
        LAB_62c68f:
          if (iVar3 == 0) return iVar2;
        }
      }
    }
    iVar2 = 0;
  }
  else if (*reinterpret_cast<int*>(~reinterpret_cast<uint32_t>(param_1)) == 0) {
    iVar2 = reinterpret_cast<int*>(~reinterpret_cast<uint32_t>(param_1))[1];
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}

// 0x62c6a5 — observed shape
int FUN_62c6a5(uint32_t param_1) {
  int iVar1;
  if (((param_1 & 0x7fffffffu) == param_1) || (*reinterpret_cast<int*>(~param_1) != 1)) {
    iVar1 = 0;
  }
  else {
    iVar1 = reinterpret_cast<int*>(~param_1)[1];
  }
  return iVar1;
}

// 0x62c6cb — observed shape
int FUN_62c6cb(int* param_1, int param_2, void* param_3, uint32_t param_4, void** param_5, int param_6, void** param_7) {
  int iVar1;
  int iVar2 = static_cast<int>(reinterpret_cast<intptr_t>(param_1));
  FUN_0062a46a(static_cast<uint32_t>(iVar2) + 0x10);
  param_1 = nullptr;
  int* local_8 = nullptr;
  FUN_006142c8();
  if (param_7 != nullptr) *param_7 = nullptr;
  if (param_5 != nullptr) *param_5 = nullptr;
  iVar1 = FUN_0062c5a3(reinterpret_cast<void*>(static_cast<intptr_t>(iVar2)), static_cast<uint32_t>(param_2));
  if (iVar1 == 0) {
    param_2 = -0x7789f794;
  }
  else {
    param_2 = FUN_0060f68b();
    if (-1 < param_2) {
      param_2 = FUN_006253a7(static_cast<uint32_t>(iVar2) + 0x10,
                             static_cast<uint32_t>(*reinterpret_cast<int*>(iVar2 + 800)),
                             static_cast<uint32_t>(*reinterpret_cast<int*>(iVar1 + 0x20)),
                             0, param_3, param_4 | 0x100u, &param_1, 0);
      if (-1 < param_2) {
        int iVar3 = FUN_0060f796();
        if (iVar3 != 0) param_2 = -0x7789f4a7;
        if (-1 < param_2) {
          using GetBufFn = uint32_t(*)(void*, void*);
          auto getBuf = *reinterpret_cast<GetBufFn*>(*reinterpret_cast<uint32_t*>(param_1) + 0xc);
          uint32_t uVar3 = getBuf(param_1, &local_8);
          param_2 = FUN_005f8091(reinterpret_cast<void*>(uVar3), &local_8);
          if (-1 < param_2) {
            if (param_5 != nullptr) {
              *param_5 = param_1;
              param_1 = nullptr;
            }
            if (param_7 != nullptr) {
              *param_7 = local_8;
              local_8 = nullptr;
            }
          }
        }
      }
    }
  }
  if (param_6 != 0) FUN_0060f728(param_6);
  if (param_1 != nullptr) {
    using RelFn = void(*)(void*);
    auto rel = *reinterpret_cast<RelFn*>(*reinterpret_cast<uint32_t*>(param_1) + 8);
    rel(param_1);
    param_1 = nullptr;
  }
  if (local_8 != nullptr) {
    using RelFn2 = void(*)(void*);
    auto rel2 = *reinterpret_cast<RelFn2*>(*reinterpret_cast<uint32_t*>(local_8) + 8);
    rel2(local_8);
    local_8 = nullptr;
  }
  FUN_00615ccd();
  FUN_0060d2b8();
  return param_2;
}

// 0x62c80a — observed shape
int32_t FUN_62c80a(void* self, int param_1, void* param_2, int* param_3, void* param_4) {
  int iVar1;
  int iVar2;
  int local_14;
  int local_10;
  int uVar3;
  float* pfVar4;
  int* local_c;
  float local_8;
  local_8 = 0.0f;
  local_c = nullptr;
  FUN_006142c8();
  {
    int tmp = *reinterpret_cast<int*>(param_1 + 0x2c);
    local_10 = *reinterpret_cast<int*>(tmp + 0x28);
  }
  if (local_10 != 0) {
    if ((*reinterpret_cast<int*>(local_10 + 4) == 0xd) && (*reinterpret_cast<int*>(local_10 + 0x1c) == 0)) {
      do {
        iVar1 = *reinterpret_cast<int*>(local_10 + 0x20);
        if ((iVar1 == 0) || (*reinterpret_cast<int*>(iVar1 + 4) != 1 || (iVar1 = *reinterpret_cast<int*>(iVar1 + 8), iVar1 == 0)) || (*reinterpret_cast<int*>(iVar1 + 4) != 0xd)) break;
        local_10 = iVar1;
      } while (*reinterpret_cast<int*>(iVar1 + 0x1c) == 0);
      if ((*reinterpret_cast<int*>(local_10 + 0x1c) == 0) && ((local_14 = *reinterpret_cast<int*>(local_10 + 0x20), local_14 != 0)) && (*reinterpret_cast<int*>(local_14 + 4) == 1 && (*reinterpret_cast<int*>(local_14 + 8) != 0 && (*reinterpret_cast<int*>(*reinterpret_cast<int*>(local_14 + 8) + 4) == 0xe)))) {
        pfVar4 = reinterpret_cast<float*>(static_cast<intptr_t>(*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 0x344)) + *reinterpret_cast<int*>(param_1 + 0x3c));
        do {
          if ((*reinterpret_cast<int*>(local_14 + 4) != 1) || (iVar1 = *reinterpret_cast<int*>(local_14 + 8), iVar1 == 0) || (*reinterpret_cast<int*>(iVar1 + 4) != 0xe)) goto LAB_62ca33;
          iVar2 = *reinterpret_cast<int*>(iVar1 + 0x10);
          if (iVar2 == 0) {
            *pfVar4 = (float)(uint32_t)(*reinterpret_cast<int*>(iVar1 + 0x18) != 0);
          }
          else {
            if ((iVar2 == 1) || (iVar2 == 2)) {
              *pfVar4 = *reinterpret_cast<float*>(iVar1 + 0x18);
              goto LAB_62ca04;
            }
            if (iVar2 == 3) {
              *pfVar4 = (float)*reinterpret_cast<double*>(iVar1 + 0x18);
              goto LAB_62ca04;
            }
            if (iVar2 != 4) {
              if (iVar2 != 5) {
                FUN_0060fcd3(reinterpret_cast<uint8_t*>(self) + 0x28, reinterpret_cast<void*>(static_cast<intptr_t>(local_10 + 0x30)), nullptr, "ID3DXEffectCompiler::CompileEffect: Unrecognized value type");
                goto LAB_62ca33;
              }
              uVar3 = *reinterpret_cast<int*>(iVar1 + 0x18);
              local_8 = *pfVar4;
              param_1 = *reinterpret_cast<int*>(iVar1 + 0x1c);
            LAB_62c99e:
              local_8 = bits_to_float(FUN_0062a64e(&local_8, 4, 0));
              if ((-1 < hr_of(local_8)) &&
                  (local_8 = bits_to_float(FUN_0062a64e(&param_1, 4, 0)), -1 < hr_of(local_8)) &&
                  (local_8 = bits_to_float(FUN_0062a64e(reinterpret_cast<void*>(static_cast<uint32_t>(uVar3)), static_cast<uint32_t>(param_1), 0)), -1 < hr_of(local_8))) {
                *param_3 = *param_3 + 1;
                goto LAB_62ca04;
              }
              break;
            }
            iVar1 = *reinterpret_cast<int*>(iVar1 + 0x18);
            if ((iVar1 != 0) && (*reinterpret_cast<int*>(iVar1 + 4) == 0xd) && (*reinterpret_cast<int*>(iVar1 + 0x1c) == 0x1b)) {
              if (local_c != nullptr) {
                using RelFn = void(*)(void*);
                auto rel = *reinterpret_cast<RelFn*>(*reinterpret_cast<uint32_t*>(local_c) + 8);
                rel(local_c);
                local_c = nullptr;
              }
              local_8 = bits_to_float(FUN_0062542f(static_cast<uint32_t>(reinterpret_cast<intptr_t>(self) + 0x10), *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 800), static_cast<uint32_t>(iVar1), 0, static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_4)), &local_c, nullptr));
              if (-1 < hr_of(local_8)) {
                if (local_c == nullptr) {
                  uVar3 = 0;
                  param_1 = 0;
                }
                else {
                  using GetFn = uint32_t(*)(void*);
                  auto getBuf = *reinterpret_cast<GetFn*>(*reinterpret_cast<uint32_t*>(local_c) + 0xc);
                  auto getSz = *reinterpret_cast<GetFn*>(*reinterpret_cast<uint32_t*>(local_c) + 0x10);
                  uVar3 = getBuf(local_c);
                  param_1 = getSz(local_c);
                }
                local_8 = *pfVar4;
                goto LAB_62c99e;
              }
              FUN_0060fcd3(reinterpret_cast<uint8_t*>(self) + 0x28, reinterpret_cast<void*>(static_cast<intptr_t>(local_10 + 0x30)), nullptr, "ID3DXEffectCompiler::CompileEffect: There was an error compiling HLL shader parameter");
              break;
            }
          }
        LAB_62ca04:
          pfVar4 = pfVar4 + 1;
          local_14 = *reinterpret_cast<int*>(local_14 + 0xc);
        } while (local_14 != 0);
        goto LAB_62ca3a;
      }
    }
  LAB_62ca33:
    local_8 = -2.29659e-41f;
  }
LAB_62ca3a:
  if (local_c != nullptr) {
    using RelFn = void(*)(void*);
    auto rel = *reinterpret_cast<RelFn*>(*reinterpret_cast<uint32_t*>(local_c) + 8);
    rel(local_c);
    local_c = nullptr;
  }
  FUN_00615ccd();
  return hr_of(local_8);
}

// 0x62ca7a — observed shape
int FUN_62ca7a(uint32_t param_1, uint32_t param_2, void** param_3, int param_4) {
  char cVar1;
  char cVar2;
  int iVar3;
  uint32_t uVar4;
  int iVar8;
  int iVar16;
  int local_30;
  int local_28;
  int local_18;
  int local_14;
  uint32_t uVar13;
  uint32_t uVar12;
  char* pcVar5;
  char* pcVar6;
  char* pcVar7;
  int* piVar15;
  int* piVar10;
  uint32_t* puVar9;
  uint32_t* puVar14;
  uint32_t* puVar17;
  int* local_34;
  int* local_10;
  int* local_2c;
  int* local_24;
  int* local_20;
  int* local_1c;
  int* local_c;
  int* local_8;
  char local_58[36];
  uint32_t iVar11 = param_1;
  FUN_0062a46a(param_1 + 0x10);
  param_1 = 0;
  local_c = nullptr;
  local_20 = nullptr;
  local_2c = nullptr;
  local_24 = nullptr;
  if (param_3 != nullptr) *param_3 = nullptr;
  if (*reinterpret_cast<int*>(iVar11 + 0x324) == 0) {
    local_14 = static_cast<int>(iVar11 + 0x28);
    FUN_0060fcd3(reinterpret_cast<void*>(static_cast<intptr_t>(local_14)), nullptr, nullptr, "ID3DXEffectCompiler: There were no techniques");
    iVar16 = -0x7fffbffb;
  }
  else {
    local_14 = static_cast<int>(iVar11 + 0x28);
    iVar16 = FUN_0060f68b();
    if (-1 < iVar16) {
      void* alloc = FUN_00533c78(0x1c);
      uint64_t uVar18;
      if (alloc == nullptr) uVar18 = 0;
      else uVar18 = FUN_0062a5d2(alloc);
      iVar16 = static_cast<int>(uVar18 >> 32);
      param_1 = static_cast<uint32_t>(uVar18);
      if (static_cast<int>(param_1) == iVar16) {
        iVar16 = -0x7ff8fff2;
      }
      else {
        iVar8 = *reinterpret_cast<int*>(iVar11 + 0x34c);
        local_28 = iVar16;
        if (iVar8 != iVar16) {
          do {
            iVar16 = as_hr(FUN_62c80a(reinterpret_cast<void*>(static_cast<uintptr_t>(iVar11)), iVar8, reinterpret_cast<void*>(static_cast<uintptr_t>(param_1)), &local_28, reinterpret_cast<void*>(static_cast<uintptr_t>(param_2)));
            if (iVar16 < 0) goto LAB_62d0e6;
            for (local_10 = *reinterpret_cast<int**>(iVar8 + 0x30); local_10 != nullptr; local_10 = reinterpret_cast<int*>(local_10[0xd])) {
              iVar16 = as_hr(FUN_62c80a(reinterpret_cast<void*>(static_cast<uintptr_t>(iVar11)), reinterpret_cast<int>(local_10), reinterpret_cast<void*>(static_cast<uintptr_t>(param_1)), &local_28, reinterpret_cast<void*>(static_cast<uintptr_t>(param_2))));
              if (iVar16 < 0) goto LAB_62d0e6;
            }
            iVar8 = *reinterpret_cast<int*>(iVar8 + 0x34);
          } while (iVar8 != 0);
        }
        for (local_10 = *reinterpret_cast<int**>(iVar11 + 0x348); local_10 != nullptr; local_10 = reinterpret_cast<int*>(local_10[0xd])) {
          for (iVar8 = local_10[0xc]; iVar8 != 0; iVar8 = *reinterpret_cast<int*>(iVar8 + 0x34)) {
            iVar16 = as_hr(FUN_62c80a(reinterpret_cast<void*>(static_cast<uintptr_t>(iVar11)), iVar8, reinterpret_cast<void*>(static_cast<uintptr_t>(param_1)), &local_28, reinterpret_cast<void*>(static_cast<uintptr_t>(param_2))));
            if (iVar16 < 0) goto LAB_62d0e6;
          }
          local_8 = local_10;
          while ((local_8 = reinterpret_cast<int*>(local_8[0xb]), local_8 != nullptr)) {
            for (iVar8 = local_8[10]; iVar8 != 0; iVar8 = *reinterpret_cast<int*>(iVar8 + 0x34)) {
              iVar16 = as_hr(FUN_62c80a(reinterpret_cast<void*>(static_cast<uintptr_t>(iVar11)), iVar8, reinterpret_cast<void*>(static_cast<uintptr_t>(param_1)), &local_28, reinterpret_cast<void*>(static_cast<uintptr_t>(param_2))));
              if (iVar16 < 0) goto LAB_62d0e6;
            }
          }
        }
        local_30 = 0;
        local_34 = *reinterpret_cast<int**>(iVar11 + 0x354);
        while (local_34 != nullptr) {
          FUN_006142c8();
          iVar8 = local_34[5];
          if (((*reinterpret_cast<int*>(iVar8 + 0x1c) == 0x17) || (*reinterpret_cast<int*>(iVar8 + 0x1c) == 0x16)) && ((DAT_006e213c[*local_34 * 7] == 0x0a000000 || (DAT_006e213c[*local_34 * 7] == 0x0b000000)))) {
            for (iVar16 = *reinterpret_cast<int*>(iVar8 + 0x20); (*reinterpret_cast<int*>(iVar16 + 4) == 0xd && (*reinterpret_cast<int*>(iVar16 + 0x1c) == 0)); iVar16 = *reinterpret_cast<int*>(iVar16 + 0x20)) {
            }
            if (*reinterpret_cast<int*>(iVar16 + 4) == 1) {
              piVar15 = *reinterpret_cast<int**>(iVar16 + 8);
              local_8 = piVar15;
              if (piVar15[4] == 6) {
                iVar16 = *reinterpret_cast<int*>(iVar8 + 0x24);
                for (iVar3 = iVar16; (*reinterpret_cast<int*>(iVar3 + 4) == 0xd && (*reinterpret_cast<int*>(iVar3 + 0x1c) == 0)); iVar3 = *reinterpret_cast<int*>(iVar3 + 0x20)) {
                }
                if (*reinterpret_cast<int*>(iVar3 + 4) == 0xe) {
                  iVar16 = *reinterpret_cast<int*>(iVar3 + 0x20);
                  if (1 < iVar16) {
                    if (iVar16 < 5) {
                      uVar4 = *reinterpret_cast<uint32_t*>(iVar3 + 0x28);
                    }
                    else {
                      if (8 < iVar16) goto LAB_62d17b;
                      uVar4 = static_cast<uint32_t>(static_cast<int>(*reinterpret_cast<float*>(iVar3 + 0x28)));
                    }
                    sprintf(local_58, "%d", uVar4);
                    pcVar5 = reinterpret_cast<char*>(piVar15[10]);
                    pcVar7 = pcVar5 + 1;
                    do {
                      cVar1 = *pcVar5;
                      pcVar5 = pcVar5 + 1;
                    } while (cVar1 != '\0');
                    pcVar6 = local_58;
                    do {
                      cVar1 = *pcVar6;
                      pcVar6 = pcVar6 + 1;
                    } while (cVar1 != '\0');
                    iVar16 = FUN_006294f9(reinterpret_cast<void*>(pcVar5 + (int)(reinterpret_cast<intptr_t>(pcVar6) + ((3 - (int)reinterpret_cast<intptr_t>(local_58 + 1)) - (int)reinterpret_cast<intptr_t>(pcVar7)))), &local_c);
                    if (-1 < iVar16) {
                      pcVar5 = "%s[%s]";
                      using FmtFn = void*(*)(void*, const char*, ...);
                      auto fmtFn = *reinterpret_cast<FmtFn*>(*reinterpret_cast<uint32_t*>(local_c) + 0xc);
                      pcVar7 = reinterpret_cast<char*>(fmtFn(local_c, "%s[%s]", reinterpret_cast<void*>(static_cast<uint32_t>(piVar15[10])), local_58));
                      sprintf(pcVar7, pcVar5);
                      local_8 = reinterpret_cast<int*>(static_cast<uintptr_t>(0x1));
                      goto LAB_62cec4;
                    }
                    goto LAB_62d198;
                  }
                LAB_62d17b:
                  pcVar7 = "ID3DXEffectCompiler::CompileEffect: Shader arrays index was not float or int";
                }
                else {
                  if (*reinterpret_cast<int*>(iVar16 + 4) == 0xd) {
                    iVar16 = FUN_0062542f(iVar11 + 0x10, *reinterpret_cast<uint32_t*>(iVar11 + 800), static_cast<uint32_t>(iVar16), 0, param_2, &local_c, &local_10);
                    if (iVar16 < 0) goto LAB_62d182;
                    pcVar5 = reinterpret_cast<char*>(static_cast<uint32_t>(local_8[10]));
                    pcVar7 = pcVar5 + 1;
                    pcVar6 = pcVar5;
                    do {
                      cVar1 = *pcVar6;
                      pcVar6 = pcVar6 + 1;
                    } while (cVar1 != '\0');
                    cVar1 = (char)reinterpret_cast<intptr_t>(pcVar5);
                    do {
                      cVar2 = *pcVar5;
                      pcVar5 = pcVar5 + 1;
                    } while (cVar2 != '\0');
                    iVar16 = (int)(((uint32_t)(((char)reinterpret_cast<intptr_t>(pcVar5) - (cVar1 + '\x01') + 1U) & 3) != 0) + ((uint32_t)(reinterpret_cast<intptr_t>(pcVar6) + (1 - (int)reinterpret_cast<intptr_t>(pcVar7))) >> 2)) * 4);
                    local_18 = iVar16;
                    {
                      using GetSzFn = uint32_t(*)(void*);
                      auto getSz = *reinterpret_cast<GetSzFn*>(*reinterpret_cast<uint32_t*>(local_c) + 0x10);
                      iVar8 = static_cast<int>(getSz(local_c));
                    }
                    uVar13 = static_cast<uint32_t>(iVar8) + 4 + static_cast<uint32_t>(iVar16);
                    iVar16 = FUN_006294f9(reinterpret_cast<void*>(static_cast<uintptr_t>(uVar13)), &local_20);
                    if (-1 < iVar16) {
                      using GetFn = void*(*)(void*);
                      auto fmtGet = *reinterpret_cast<GetFn*>(*reinterpret_cast<uint32_t*>(local_20) + 0xc);
                      piVar10 = reinterpret_cast<int*>(fmtGet(local_20));
                      piVar15 = piVar10;
                      for (uVar12 = uVar13 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
                        *piVar15 = 0;
                        piVar15 = piVar15 + 1;
                      }
                      for (uVar12 = uVar13 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
                        *reinterpret_cast<uint8_t*>(piVar15) = 0;
                        piVar15 = reinterpret_cast<int*>(reinterpret_cast<intptr_t>(piVar15) + 1);
                      }
                      local_1c = piVar10 + 1;
                      *piVar10 = local_18;
                      strncpy(reinterpret_cast<char*>(local_1c), reinterpret_cast<char*>(static_cast<uint32_t>(local_8[10])), uVar13 - 4);
                      {
                        using GetSzFn = uint32_t(*)(void*);
                        auto getSz2 = *reinterpret_cast<GetSzFn*>(*reinterpret_cast<uint32_t*>(local_c) + 0x10);
                        local_8 = reinterpret_cast<int*>(static_cast<uintptr_t>(getSz2(local_c)));
                      }
                      {
                        using GetFn = void*(*)(void*);
                        auto fmtGet2 = *reinterpret_cast<GetFn*>(*reinterpret_cast<uint32_t*>(local_c) + 0xc);
                        pcVar7 = reinterpret_cast<char*>(fmtGet2(local_c));
                      }
                      pcVar5 = reinterpret_cast<char*>(reinterpret_cast<intptr_t>(local_1c) + local_18);
                      for (uVar13 = static_cast<uint32_t>(reinterpret_cast<intptr_t>(local_8)) >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
                        *reinterpret_cast<uint32_t*>(pcVar5) = *reinterpret_cast<uint32_t*>(pcVar7);
                        pcVar7 = pcVar7 + 4;
                        pcVar5 = pcVar5 + 4;
                      }
                      for (uVar13 = static_cast<uint32_t>(reinterpret_cast<intptr_t>(local_8)) & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
                        *pcVar5 = *pcVar7;
                        pcVar7 = pcVar7 + 1;
                        pcVar5 = pcVar5 + 1;
                      }
                      if (local_10 != nullptr) {
                        using RelFn = void(*)(void*);
                        auto rel = *reinterpret_cast<RelFn*>(*reinterpret_cast<uint32_t*>(local_10) + 8);
                        rel(local_10);
                        local_10 = nullptr;
                      }
                      if (local_c != nullptr) {
                        using RelFn = void(*)(void*);
                        auto rel = *reinterpret_cast<RelFn*>(*reinterpret_cast<uint32_t*>(local_c) + 8);
                        rel(local_c);
                      }
                      local_c = local_20;
                      local_20 = nullptr;
                      local_8 = reinterpret_cast<int*>(static_cast<uintptr_t>(0x2));
                      goto LAB_62cec4;
                    }
                    goto LAB_62d198;
                  }
                  pcVar7 = "ID3DXEffectCompiler::CompileEffect: Could not compile expression containing shader array";
                }
              }
              else {
                pcVar7 = "ID3DXEffectCompiler::CompileEffect: Shader arrays must be a previously defined parameter";
              }
              piVar15 = piVar15 + 8;
            }
            else {
              pcVar7 = "ID3DXEffectCompiler::CompileEffect: Only 1-d shader arrays allowed";
              piVar15 = reinterpret_cast<int*>(static_cast<intptr_t>(iVar8 + 0x30));
            }
            FUN_0060fcd3(reinterpret_cast<void*>(static_cast<intptr_t>(local_14)), piVar15, nullptr, pcVar7);
            iVar16 = -0x7fffbffb;
            FUN_00615ccd();
            goto LAB_62d0e6;
          }
          iVar16 = FUN_0062542f(iVar11 + 0x10, *reinterpret_cast<uint32_t*>(iVar11 + 800), static_cast<uint32_t>(iVar8), 0, param_2, &local_c, &local_10);
          if (iVar16 < 0) {
          LAB_62d182:
            FUN_0060fcd3(reinterpret_cast<void*>(static_cast<intptr_t>(local_14)), reinterpret_cast<void*>(static_cast<intptr_t>(iVar8 + 0x30)), nullptr, "ID3DXEffectCompiler::CompileEffect: There was an error compiling expression");
          LAB_62d198:
            FUN_00615ccd();
            goto LAB_62d0cb;
          }
          local_8 = reinterpret_cast<int*>(static_cast<uintptr_t>(local_10 == reinterpret_cast<int*>(static_cast<uintptr_t>(0x1))));
          if ((local_10 != reinterpret_cast<int*>(static_cast<uintptr_t>(0x1))) && (local_10 != nullptr)) {
            using RelFn = void(*)(void*);
            auto rel = *reinterpret_cast<RelFn*>(*reinterpret_cast<uint32_t*>(local_10) + 8);
            rel(local_10);
            local_10 = nullptr;
          }
        LAB_62cec4:
          {
            using GetFn = void*(*)(void*);
            auto fmtGet = *reinterpret_cast<GetFn*>(*reinterpret_cast<uint32_t*>(local_c) + 0xc);
            local_1c = reinterpret_cast<int*>(fmtGet(local_c));
          }
          {
            using GetSzFn = uint32_t(*)(void*);
            auto getSz = *reinterpret_cast<GetSzFn*>(*reinterpret_cast<uint32_t*>(local_c) + 0x10);
            local_18 = static_cast<int>(getSz(local_c));
          }
          piVar15 = local_34;
          iVar16 = FUN_0062a64e(local_34 + 1, 4, 0);
          if (((((iVar16 < 0) || (iVar16 = FUN_0062a64e(piVar15 + 2, 4, 0), iVar16 < 0)) || (iVar16 = FUN_0062a64e(piVar15 + 3, 4, 0), iVar16 < 0)) || ((iVar16 = FUN_0062a64e(piVar15 + 4, 4, 0), iVar16 < 0 || (iVar16 = FUN_0062a64e(&local_8, 4, 0), iVar16 < 0)))) || ((iVar16 = FUN_0062a64e(&local_18, 4, 0), iVar16 < 0 || (iVar16 = FUN_0062a64e(local_1c, static_cast<uint32_t>(local_18), 0), iVar16 < 0)))) goto LAB_62d198;
          local_30 = local_30 + 1;
          if (local_c != nullptr) {
            using RelFn = void(*)(void*);
            auto rel = *reinterpret_cast<RelFn*>(*reinterpret_cast<uint32_t*>(local_c) + 8);
            rel(local_c);
            local_c = nullptr;
          }
          FUN_00615ccd();
          local_34 = reinterpret_cast<int*>(piVar15[6]);
        }
        param_2 = 0;
        iVar16 = FUN_0062a802(nullptr, &param_2);
        uVar13 = param_2;
        if (-1 < iVar16) {
          local_24 = reinterpret_cast<int*>(FUN_00533c78(param_2));
          if (local_24 != nullptr) {
            iVar16 = FUN_0062a802(local_24, nullptr);
            if ((iVar16 < 0) || (iVar16 = FUN_006294f9(reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(*reinterpret_cast<int*>(iVar11 + 0x338) + *reinterpret_cast<int*>(iVar11 + 0x340) + 0x10 + uVar13))), &local_2c), local_18 = iVar16, iVar16 < 0)) goto LAB_62d0e6;
            {
              using GetFn = void*(*)(void*);
              auto fmtGet = *reinterpret_cast<GetFn*>(*reinterpret_cast<uint32_t*>(local_2c) + 0xc);
              puVar9 = reinterpret_cast<uint32_t*>(fmtGet(local_2c));
            }
            *puVar9 = 0xfeff0901;
            puVar9[1] = *reinterpret_cast<uint32_t*>(iVar11 + 0x340);
            uVar13 = *reinterpret_cast<uint32_t*>(iVar11 + 0x340);
            puVar14 = *reinterpret_cast<uint32_t**>(iVar11 + 0x344);
            puVar17 = puVar9 + 2;
            for (uVar12 = uVar13 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
              *puVar17 = *puVar14;
              puVar14 = puVar14 + 1;
              puVar17 = puVar17 + 1;
            }
            for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
              *reinterpret_cast<uint8_t*>(puVar17) = *reinterpret_cast<uint8_t*>(puVar14);
              puVar14 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar14) + 1);
              puVar17 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar17) + 1);
            }
            puVar9 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar9 + 2) + *reinterpret_cast<int*>(iVar11 + 0x340));
            uVar13 = *reinterpret_cast<uint32_t*>(iVar11 + 0x338);
            puVar14 = *reinterpret_cast<uint32_t**>(iVar11 + 0x33c);
            puVar17 = puVar9;
            for (uVar12 = uVar13 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
              *puVar17 = *puVar14;
              puVar14 = puVar14 + 1;
              puVar17 = puVar17 + 1;
            }
            for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
              *reinterpret_cast<uint8_t*>(puVar17) = *reinterpret_cast<uint8_t*>(puVar14);
              puVar14 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar14) + 1);
              puVar17 = reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(puVar17) + 1);
            }
            piVar10 = reinterpret_cast<int*>(reinterpret_cast<intptr_t>(puVar9) + *reinterpret_cast<int*>(iVar11 + 0x338));
            *piVar10 = local_28;
            piVar10[1] = local_30;
            piVar15 = local_24;
            piVar10 = piVar10 + 2;
            for (uVar13 = param_2 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
              *piVar10 = *piVar15;
              piVar15 = piVar15 + 1;
              piVar10 = piVar10 + 1;
            }
            for (uVar13 = param_2 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
              *reinterpret_cast<char*>(piVar10) = (char)*piVar15;
              piVar15 = reinterpret_cast<int*>(reinterpret_cast<intptr_t>(piVar15) + 1);
              piVar10 = reinterpret_cast<int*>(reinterpret_cast<intptr_t>(piVar10) + 1);
            }
            if (param_3 != nullptr) {
              *param_3 = local_2c;
              using AddRefFn = uint32_t(*)(void*);
              auto addRef = *reinterpret_cast<AddRefFn*>(*reinterpret_cast<uint32_t*>(local_2c) + 4);
              addRef(local_2c);
            }
            iVar16 = local_18;
          }
        LAB_62d0cb:
          if (-1 < iVar16) {
            uint32_t iVar11b = static_cast<uint32_t>(FUN_0060f796());
            if (iVar11b != 0) iVar16 = -0x7789f4a7;
            if (-1 < iVar16) goto LAB_62d0fa;
          }
        }
      }
    }
  }
LAB_62d0e6:
  FUN_0060fcd3(reinterpret_cast<void*>(static_cast<intptr_t>(local_14)), nullptr, nullptr, "ID3DXEffectCompiler: Compilation failed");
LAB_62d0fa:
  if (param_4 != 0) FUN_0060f728(param_4);
  if (local_24 != nullptr) ::operator delete(local_24);
  if (param_1 != 0) FUN_0062a62d(1);
  if (local_2c != nullptr) {
    using RelFn = void(*)(void*);
    auto rel = *reinterpret_cast<RelFn*>(*reinterpret_cast<uint32_t*>(local_2c) + 8);
    rel(local_2c);
    local_2c = nullptr;
  }
  if (local_c != nullptr) {
    using RelFn = void(*)(void*);
    auto rel = *reinterpret_cast<RelFn*>(*reinterpret_cast<uint32_t*>(local_c) + 8);
    rel(local_c);
    local_c = nullptr;
  }
  if (local_20 != nullptr) {
    using RelFn = void(*)(void*);
    auto rel = *reinterpret_cast<RelFn*>(*reinterpret_cast<uint32_t*>(local_20) + 8);
    rel(local_20);
    local_20 = nullptr;
  }
  FUN_0060d2b8();
  return iVar16;
}

// 0x62d1d6 — observed shape
uint32_t FUN_62d1d6(int param_1, uint32_t* param_2) {
  uint32_t uVar1 = 0;
  if (param_2 == nullptr) {
    uVar1 = 0x8876086c;
  }
  else {
    param_2[0] = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    param_2[1] = *reinterpret_cast<uint32_t*>(param_1 + 0x328);
    param_2[2] = *reinterpret_cast<uint32_t*>(param_1 + 0x324);
    param_2[3] = *reinterpret_cast<uint32_t*>(param_1 + 0x32c);
  }
  return uVar1;
}

// 0x62d21b — observed shape
uint32_t FUN_62d21b(void* self, uint32_t param_1, uint32_t param_2, uint32_t* param_3) {
  int iVar1;
  (void)param_1;
  if (param_3 == nullptr) return 0x8876086c;
  iVar1 = FUN_0062c5a3(self, param_2);
  if (iVar1 == 0) return 0x8876086c;
  param_3[0] = 0;
  param_3[1] = 0;
  param_3[0] = *reinterpret_cast<uint32_t*>(iVar1 + 0x20);
  param_3[1] = 0;
  return 0;
}

// 0x62d25b — observed shape
uint32_t FUN_62d25b(void* self, uint32_t param_1, uint32_t param_2, uint32_t* param_3) {
  int iVar1;
  (void)param_1;
  if (param_3 == nullptr) return 0x8876086c;
  iVar1 = FUN_62c624(self, reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(param_2)));
  if (iVar1 == 0) return 0x8876086c;
  param_3[0] = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  param_3[0] = *reinterpret_cast<uint32_t*>(iVar1 + 0x20);
  param_3[1] = *reinterpret_cast<uint32_t*>(iVar1 + 0x28);
  param_3[2] = *reinterpret_cast<uint32_t*>(iVar1 + 0x24);
  return 0;
}

// 0x62d2a5 — observed shape
// 0x62c6a5 is observed here as an EDX:EAX pair: low half is the node, high half the out buffer.
uint32_t FUN_62d2a5(void* self, uint32_t param_1, uint32_t param_2, int param_3) {
  int iVar1;
  uint32_t* puVar2;
  (void)param_1;
  if (param_3 != 0) {
    uint64_t uVar3 = FUN_0062c6a5_pair(self, param_2);
    puVar2 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(uVar3 >> 32));
    iVar1 = static_cast<int>(uVar3);
    if (iVar1 != 0) {
      puVar2[0] = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      puVar2[0] = *reinterpret_cast<uint32_t*>(iVar1 + 0x20);
      puVar2[1] = *reinterpret_cast<uint32_t*>(iVar1 + 0x24);
      puVar2[2] = 0;
      puVar2[3] = 0;
      return 0;
    }
  }
  return 0x8876086c;
}

// 0x62d2ee — observed shape
uint32_t FUN_62d2ee(void* self, int param_1, uint32_t param_2, int param_3) {
  uint32_t uVar1;
  int iVar2;
  uint32_t* puVar3;
  uint32_t uVar4;
  uint32_t uVar5 = param_2;
  uint32_t uVar6;
  uint32_t* puVar7;
  uint32_t* prev;
  int local_8;

  if (param_1 == 0) return 0;
  iVar2 = FUN_0062f194(static_cast<uint32_t>(param_1), param_3);
  if (iVar2 == 0) return 0;
  uVar1 = *reinterpret_cast<uint32_t*>(
      *reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar2 + 4) + 0x40) +
      *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 0x344) + 0x10 +
      *reinterpret_cast<int*>(iVar2 + 0x18));
  if (*reinterpret_cast<int*>(iVar2 + 0x10) != -1) return 0;
  if (uVar1 == 0) return 0;
  if (uVar1 <= param_2) return 0;

  prev = nullptr;
  puVar3 = *reinterpret_cast<uint32_t**>(iVar2 + 0xc);
  if (puVar3 != nullptr) {
    do {
      puVar7 = puVar3;
      puVar3 = puVar7;
      if (uVar5 <= puVar7[4]) break;
      puVar3 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(puVar7[3]));
      prev = puVar7;
    } while (puVar3 != nullptr);
    if ((puVar3 != nullptr) && (uVar5 >= puVar3[4])) {
      return ~static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar3));
    }
  }
  // LAB_0062d37b
  puVar3 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x20));
  if (puVar3 == nullptr) {
    puVar3 = nullptr;
  }
  else {
    puVar3[4] = 0xffffffff;
    puVar3[7] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
  }
  if (puVar3 == nullptr) return 0;
  local_8 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar2 + 4) + 0x40) + *reinterpret_cast<int*>(iVar2 + 0x18);
  uVar4 = FUN_0062aba8(*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x344), &local_8, &param_3);
  puVar3[0] = 3;
  puVar3[1] = *reinterpret_cast<uint32_t*>(iVar2 + 4);
  puVar3[6] = *reinterpret_cast<uint32_t*>(iVar2 + 0x18);
  puVar3[4] = uVar5;
  uVar6 = 0;
  puVar3[5] = uVar4 / uVar1;
  puVar3[7] = *reinterpret_cast<uint32_t*>(iVar2 + 0x1c);
  if ((static_cast<uint32_t>(param_3) * uVar5) / uVar1 != 0) {
    do {
      puVar3[7] = *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(puVar3[7]) + 0xc);
      uVar6 = uVar6 + 1;
    } while (uVar6 < (puVar3[4] * static_cast<uint32_t>(param_3)) / uVar1);
  }
  if (prev == nullptr) {
    puVar3[3] = *reinterpret_cast<uint32_t*>(iVar2 + 0xc);
    *reinterpret_cast<uint32_t**>(iVar2 + 0xc) = puVar3;
  }
  else {
    puVar3[3] = prev[3];
    prev[3] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar3));
  }
  return ~static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar3));
}

// 0x62d43e — observed shape
uint32_t FUN_62d43e(void* self, uint32_t param_1, int param_2, uint32_t param_3) {
  int iVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  (void)param_1;
  if (param_2 == 0) return 0;
  iVar1 = FUN_0062c50d(self, static_cast<uint32_t>(param_2));
  if (iVar1 == 0) {
    iVar1 = FUN_62c624(self, reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(param_2))));
    if (iVar1 == 0) {
      iVar1 = FUN_62c6a5(static_cast<uint32_t>(param_2));
      if (iVar1 == 0) return 0;
      uVar3 = *reinterpret_cast<uint32_t*>(iVar1 + 0x24);
      uVar2 = *reinterpret_cast<uint32_t*>(iVar1 + 0x28);
    }
    else {
      uVar3 = *reinterpret_cast<uint32_t*>(iVar1 + 0x24);
      uVar2 = *reinterpret_cast<uint32_t*>(iVar1 + 0x30);
    }
  }
  else {
    iVar1 = *reinterpret_cast<int*>(iVar1 + 4);
    uVar3 = *reinterpret_cast<uint32_t*>(iVar1 + 0x28);
    uVar2 = *reinterpret_cast<uint32_t*>(iVar1 + 0x30);
  }
  if (uVar3 <= param_3) return 0;
  while ((param_3 = param_3 + 1), param_3 < uVar3) {
    uVar2 = *reinterpret_cast<uint32_t*>(uVar2 + 0x34);
  }
  return ~uVar2;
}

// 0x62d4a2 — observed shape
uint32_t FUN_62d4a2(void* self, uint32_t param_1, char* param_2, uint32_t param_3) {
  char cVar1;
  int iVar2;
  int iVar6;
  uint32_t uVar3;
  uint32_t uVar4;
  char* pcVar5;
  char* pcVar7;

  if (param_2 == nullptr) return 0;
  if (*param_2 == '\0') return 0;
  iVar2 = FUN_0062c50d(self, param_1);
  if (iVar2 == 0) {
    iVar2 = FUN_62c624(self, reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(param_1)));
    if (iVar2 == 0) {
      iVar2 = FUN_62c6a5(param_1);
      if (iVar2 == 0) return 0;
      uVar4 = *reinterpret_cast<uint32_t*>(iVar2 + 0x28);
      goto LAB_62d4f7;
    }
  }
  else {
    iVar2 = *reinterpret_cast<int*>(iVar2 + 4);
  }
  uVar4 = *reinterpret_cast<uint32_t*>(iVar2 + 0x30);
LAB_62d4f7:
  if (uVar4 != 0) {
    do {
      int selfOff = *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 0x344);
      iVar6 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(uVar4 + 4) + 0x40) + *reinterpret_cast<int*>(uVar4 + 0x18) + selfOff;
      iVar2 = *reinterpret_cast<int*>(iVar6 + 8);
      if (*reinterpret_cast<int*>(iVar2 + selfOff) == 0) {
        pcVar5 = nullptr;
      }
      else {
        pcVar5 = reinterpret_cast<char*>(static_cast<intptr_t>(iVar2 + 4 + selfOff));
      }
      cVar1 = *param_2;
      pcVar7 = param_2;
      while ((cVar1 == *pcVar5) && (cVar1 != '\0')) {
        pcVar7 = pcVar7 + 1;
        pcVar5 = pcVar5 + 1;
        cVar1 = *pcVar7;
      }
      cVar1 = *pcVar7;
      if (cVar1 == *pcVar5) return ~uVar4;
      if (*pcVar5 == '\0') {
        if (cVar1 == '.') {
          pcVar7 = pcVar7 + 1;
          uVar4 = ~uVar4;
          goto LAB_62d5bd;
        }
        if (cVar1 == '[') {
          pcVar7 = pcVar7 + 1;
          if (*pcVar7 < '0') return 0;
          if ('9' < *pcVar7) return 0;
          uVar3 = static_cast<uint32_t>(atoi(pcVar7));
          if (*reinterpret_cast<uint32_t*>(iVar6 + 0x10) <= uVar3) return 0;
          for (; ('/' < *pcVar7 && (*pcVar7 < ':')); pcVar7 = pcVar7 + 1) {
          }
          if (*pcVar7 != ']') return 0;
          uVar4 = FUN_62d2ee(self, static_cast<int>(~uVar4), uVar3, static_cast<int>(param_3));
          if (uVar4 == 0) return 0;
          if (pcVar7[1] == '\0') return uVar4;
          if (pcVar7[1] != '.') return 0;
          pcVar7 = pcVar7 + 2;
          goto LAB_62d5bd;
        }
      }
      uVar4 = *reinterpret_cast<uint32_t*>(uVar4 + 0x34);
    } while (uVar4 != 0);
  }
  return 0;
LAB_62d5bd:
  return FUN_0062eccf(uVar4, pcVar7, param_3);
}

// 0x62d5d1 — observed shape
uint32_t FUN_62d5d1(int param_1, uint32_t param_2) {
  uint32_t uVar1;
  if (param_2 < *reinterpret_cast<uint32_t*>(param_1 + 0x324)) {
    uVar1 = *reinterpret_cast<uint32_t*>(param_1 + 0x348);
    while ((param_2 = param_2 + 1), param_2 < *reinterpret_cast<uint32_t*>(param_1 + 0x324)) {
      uVar1 = *reinterpret_cast<uint32_t*>(uVar1 + 0x34);
    }
    uVar1 = ~uVar1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

// 0x62d600 — observed shape
uint32_t FUN_62d600(void* self, uint32_t param_1, uint32_t param_2) {
  uint32_t uVar1;
  uint32_t uVar2 = 0;
  (void)param_1;
  uVar1 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(FUN_62c624(self, reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(param_2)))));
  if (uVar1 != 0) {
    uVar2 = ~uVar1;
  }
  return uVar2;
}

// 0x62d61a — observed shape
uint32_t FUN_62d61a(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3) {
  uint32_t* puVar1;
  uint32_t uVar2;
  (void)param_1;
  uVar2 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(FUN_62c624(self, reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(param_2)))));
  if ((uVar2 == 0) || (puVar1 = reinterpret_cast<uint32_t*>(uVar2 + 0x28), *puVar1 <= param_3)) {
    return 0;
  }
  do {
    uVar2 = *reinterpret_cast<uint32_t*>(uVar2 + 0x2c);
    param_3 = param_3 + 1;
  } while (param_3 < *puVar1);
  return ~uVar2;
}

// 0x62d64a — observed shape
uint32_t FUN_62d64a(void* self, uint32_t param_1, uint32_t param_2, uint8_t* param_3) {
  uint8_t bVar1;
  int iVar2;
  uint8_t* pbVar3;
  uint8_t* pbVar4;
  uint32_t uVar5;
  bool bVar6;
  (void)param_1;
  iVar2 = FUN_62c624(self, reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(param_2)));
  if (iVar2 != 0) {
    for (uVar5 = *reinterpret_cast<uint32_t*>(iVar2 + 0x2c); uVar5 != 0; uVar5 = *reinterpret_cast<uint32_t*>(uVar5 + 0x2c)) {
      if (param_3 == nullptr) {
        iVar2 = *reinterpret_cast<int*>(uVar5 + 0x20);
        if (iVar2 == 0) return ~uVar5;
      }
      else {
        pbVar4 = *reinterpret_cast<uint8_t**>(uVar5 + 0x20);
        if (pbVar4 != nullptr) {
          pbVar3 = param_3;
          do {
            bVar1 = *pbVar3;
            bVar6 = bVar1 < *pbVar4;
            if (bVar1 != *pbVar4) {
              iVar2 = (1 - static_cast<uint32_t>(bVar6)) - static_cast<uint32_t>(bVar6 != 0);
              goto LAB_62d6a4;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar3[1];
            bVar6 = bVar1 < pbVar4[1];
            if (bVar1 != pbVar4[1]) {
              iVar2 = (1 - static_cast<uint32_t>(bVar6)) - static_cast<uint32_t>(bVar6 != 0);
              goto LAB_62d6a4;
            }
            pbVar3 = pbVar3 + 2;
            pbVar4 = pbVar4 + 2;
          } while (bVar1 != 0);
          iVar2 = 0;
        LAB_62d6a4:
          if (iVar2 == 0) return ~uVar5;
        }
      }
    }
  }
  return 0;
}

// 0x62d6bb — observed shape
uint32_t FUN_62d6bb(int param_1, uint32_t param_2) {
  uint32_t uVar1;
  if (param_2 < *reinterpret_cast<uint32_t*>(param_1 + 0x32c)) {
    uVar1 = *reinterpret_cast<uint32_t*>(param_1 + 0x350);
    while ((param_2 = param_2 + 1), param_2 < *reinterpret_cast<uint32_t*>(param_1 + 0x32c)) {
      uVar1 = *reinterpret_cast<uint32_t*>(uVar1 + 0x28);
    }
    uVar1 = ~uVar1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

// 0x62d6ea — observed shape
uint32_t FUN_62d6ea(void* self, uint32_t param_1, uint32_t param_2) {
  uint32_t uVar1;
  uint32_t uVar2 = 0;
  (void)param_1;
  uVar1 = static_cast<uint32_t>(FUN_0062c5a3(self, param_2));
  if (uVar1 != 0) {
    uVar2 = ~uVar1;
  }
  return uVar2;
}

// 0x62d704 — observed shape
uint32_t FUN_62d704(int param_1, float param_2) {
  int iVar1;
  int iVar2;
  uint32_t uVar3;
  iVar1 = *reinterpret_cast<int*>(param_1 + 8);
  iVar2 = *reinterpret_cast<int*>(iVar1 + 0x10);
  if (iVar2 == 0) {
    uVar3 = (param_2 == 0.0f) ? 0u : 1u;
  }
  else {
    if ((iVar2 != 1) && (iVar2 != 2)) {
      if (iVar2 == 3) {
        *reinterpret_cast<double*>(iVar1 + 0x18) = static_cast<double>(param_2);
        return 0;
      }
      return 0x8876086c;
    }
    uVar3 = static_cast<uint32_t>(static_cast<int32_t>(param_2));
  }
  *reinterpret_cast<uint32_t*>(iVar1 + 0x18) = uVar3;
  return 0;
}

// 0x62d760 — observed shape
uint32_t FUN_62d760(int param_1, float* param_2) {
  int iVar1;
  int iVar2;
  float fVar3;
  iVar1 = *reinterpret_cast<int*>(param_1 + 8);
  iVar2 = *reinterpret_cast<int*>(iVar1 + 0x10);
  if (iVar2 == 0) {
    fVar3 = static_cast<float>(*reinterpret_cast<int*>(iVar1 + 0x18) != 0);
  }
  else if (iVar2 == 1) {
    fVar3 = static_cast<float>(*reinterpret_cast<int*>(iVar1 + 0x18));
  }
  else if (iVar2 == 2) {
    fVar3 = static_cast<float>(*reinterpret_cast<int*>(iVar1 + 0x18));
    if (*reinterpret_cast<int*>(iVar1 + 0x18) < 0) {
      fVar3 = fVar3 + 4.2949673e+09f;
    }
  }
  else {
    if (iVar2 != 3) return 0x8876086c;
    fVar3 = static_cast<float>(*reinterpret_cast<double*>(iVar1 + 0x18));
  }
  *param_2 = fVar3;
  return 0;
}
