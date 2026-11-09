#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cmath>

extern long double FUN_00514da0(float a1, float a2, float a3, float a4, float a5, float a6);
extern long double _CIfmod();
extern void FUN_004ea9a0();
extern void FUN_00511f10();
extern void FUN_004ec790();
extern void FUN_00516e10(void* a1, void* a2);
extern void FUN_00511f90(int v);
extern void FUN_004ec0a0(int* p);
extern void FUN_004ece40();

// 0x4e8560 — observed shape
void FUN_004e8560(void* self) {
  std::uintptr_t base = reinterpret_cast<std::uintptr_t>(self);
  std::uint32_t* node = *reinterpret_cast<std::uint32_t**>(base + 0xc0);
  while (node != nullptr) {
    std::uint32_t* second = node + 2;
    node = reinterpret_cast<std::uint32_t*>(*node);
    ::operator delete(reinterpret_cast<void*>(*second));
  }
  node = *reinterpret_cast<std::uint32_t**>(base + 0xc0);
  while (node != nullptr) {
    std::uint32_t* next = reinterpret_cast<std::uint32_t*>(*node);
    using VFn = void (__cdecl*)(std::uint32_t*);
    std::uint32_t vtable = *reinterpret_cast<std::uint32_t*>(base + 0xbc);
    VFn fn = reinterpret_cast<VFn>(*reinterpret_cast<std::uint32_t*>(vtable + 8));
    fn(node);
    node = next;
  }
  *reinterpret_cast<std::uint32_t*>(base + 200) = 0;
  *reinterpret_cast<std::uint32_t*>(base + 0xc0) = 0;
  *reinterpret_cast<std::uint32_t*>(base + 0xc4) = 0;
}

// 0x4e85c0 — observed shape
long double FUN_004e85c0(void* self, float param2, float param3, float param4) {
  std::uintptr_t base = reinterpret_cast<std::uintptr_t>(self);
  float fVar2 = param4 * param4 + 1.0f;
  float fVar3 = param2 / *reinterpret_cast<float*>(base + 0x30);
  float fVar4 = param3 / *reinterpret_cast<float*>(base + 0x34);
  param3 = 0.0f;
  param2 = fVar2;
  if (0 < *reinterpret_cast<int*>(base + 0x58)) {
    int local_28 = 0;
    do {
      std::uint32_t* puVar1 = *reinterpret_cast<std::uint32_t**>(local_28 + 0xec + *reinterpret_cast<int*>(base + 4));
      if (puVar1 != nullptr) {
        int iVar7 = static_cast<int>(puVar1[1]);
        puVar1[1] = static_cast<std::uint32_t>(iVar7 + 1);
        puVar1[1] = static_cast<std::uint32_t>(iVar7);
        if (iVar7 == 0) {
          using VFn = void (__cdecl*)(int);
          VFn fn = reinterpret_cast<VFn>(*puVar1);
          fn(1);
        }
        float fVar5 = fVar3 - static_cast<float>(puVar1[10]);
        float fVar6 = fVar4 - static_cast<float>(puVar1[0xb]);
        fVar6 = fVar6 * fVar6 + fVar5 * fVar5 + -static_cast<float>(puVar1[0xc]) * -static_cast<float>(puVar1[0xc]);
        fVar5 = static_cast<float>(puVar1[0xd]) * static_cast<float>(puVar1[0xd]) + fVar2;
        int innerPtr = local_28 + 0xf8 + *reinterpret_cast<int*>(base + 4);
        if ((((std::isnan(fVar5) || std::isnan(fVar6)) || (fVar5 < fVar6) == (fVar5 == fVar6)) &&
             (innerPtr != 0)) &&
            (*reinterpret_cast<int*>(static_cast<std::uintptr_t>(innerPtr) + 0xc) != 0)) {
          float* pfVar8 = reinterpret_cast<float*>(*reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(innerPtr) + 4) + 8);
          int count = (( *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(innerPtr) + 0xc) - 1U >> 2) + 1);
          do {
            long double fVar9 = FUN_00514da0(fVar3, fVar4, pfVar8[-2] + static_cast<float>(puVar1[0x24]),
                                              pfVar8[-1] + static_cast<float>(puVar1[0x25]),
                                              *pfVar8 + static_cast<float>(puVar1[0x24]),
                                              pfVar8[1] + static_cast<float>(puVar1[0x25]));
            if (fVar9 * fVar9 < static_cast<long double>(param2)) {
              param2 = static_cast<float>(fVar9 * fVar9);
            }
            pfVar8 = pfVar8 + 4;
            count = count + -1;
          } while (count != 0);
        }
      }
      param3 = static_cast<float>(static_cast<int>(param3) + 1);
      local_28 = local_28 + 0x124;
    } while (static_cast<int>(param3) < *reinterpret_cast<int*>(base + 0x58));
  }
  return std::sqrt(static_cast<long double>(param2));
}

// 0x4e8770 — observed shape
int FUN_004e8770(void* self, float param1, float param2, int index) {
  std::uintptr_t base = reinterpret_cast<std::uintptr_t>(self);
  param1 = param1 / *reinterpret_cast<float*>(base + 0x30);
  param2 = param2 / *reinterpret_cast<float*>(base + 0x34);
  if (index < *reinterpret_cast<int*>(base + 0x58)) {
    float* pfVar3 = reinterpret_cast<float*>(index * 0x124 + 0x88 + *reinterpret_cast<int*>(base + 4));
    float* pfVar4 = reinterpret_cast<float*>(index * 0x2cc + 0x2a4 + *reinterpret_cast<int*>(base + 8));
    do {
      float fVar1 = pfVar4[1];
      float fVar2 = static_cast<float>(static_cast<int>(pfVar3[-6]));
      if (static_cast<int>(pfVar3[-6]) < 0) {
        fVar2 = fVar2 + 4.2949673e+09f;
      }
      fVar2 = fVar1 - (fVar2 - 1.0f) * *pfVar3;
      if ((((!std::isnan(fVar2) && !std::isnan(param2)) && (fVar2 < param2) != (fVar2 == param2)) &&
           ((!std::isnan(param2) && !std::isnan(fVar1)) && (param2 < fVar1) != (param2 == fVar1))) &&
          (*pfVar4 <= param1)) {
        fVar1 = static_cast<float>(static_cast<int>(pfVar3[-7]));
        if (static_cast<int>(pfVar3[-7]) < 0) {
          fVar1 = fVar1 + 4.2949673e+09f;
        }
        if (param1 <= (fVar1 - 1.0f) * pfVar3[-1] + *pfVar4) {
          return index;
        }
      }
      index = index + 1;
      pfVar3 = pfVar3 + 0x49;
      pfVar4 = pfVar4 + 0xb3;
    } while (index < *reinterpret_cast<int*>(base + 0x58));
  }
  return -1;
}

// 0x4e8860 — observed shape
void FUN_004e8860(void* self) {
  std::uintptr_t base = reinterpret_cast<std::uintptr_t>(self);
  std::uint32_t uVar2 = 0;
  std::int32_t* piVar3 = nullptr;
  if (*reinterpret_cast<std::uint32_t*>(base + 0x90) != 0) {
    piVar3 = *reinterpret_cast<std::int32_t**>(base + 0x94);
    do {
      if (*piVar3 != 0) {
        piVar3 = reinterpret_cast<std::int32_t*>(static_cast<std::int32_t*>((*reinterpret_cast<std::int32_t**>(base + 0x94))[uVar2]));
        goto joined_r0x004e8899;
      }
      uVar2 = uVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (uVar2 < *reinterpret_cast<std::uint32_t*>(base + 0x90));
  }
  piVar3 = nullptr;
joined_r0x004e8899:
  do {
    if (piVar3 == nullptr) {
      int iVar6 = 0;
      if (0 < *reinterpret_cast<int*>(base + 0x58)) {
        int iVar4 = 0;
        int local_4 = 0;
        do {
          int iVar7 = *reinterpret_cast<int*>(base + 4) + local_4;
          if (iVar7 != 0) {
            std::uint32_t uVar1 = *reinterpret_cast<std::uint32_t*>(*reinterpret_cast<int*>(base + 8) + 0x2c4 + iVar4);
            long double fVar8 = _CIfmod();
            *reinterpret_cast<float*>(static_cast<std::uintptr_t>(iVar7) + 0x98) = static_cast<float>(fVar8);
            *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iVar7) + 0x90) = uVar1;
            fVar8 = _CIfmod();
            *reinterpret_cast<float*>(static_cast<std::uintptr_t>(iVar7) + 0x9c) = static_cast<float>(fVar8);
            *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iVar7) + 0x94) = uVar1;
            *reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(iVar7) + 0xa4) = 0;
            FUN_004ea9a0();
            FUN_00511f10();
            FUN_004ec790();
          }
          iVar6 = iVar6 + 1;
          local_4 = local_4 + 0x124;
          iVar4 = iVar4 + 0x2cc;
        } while (iVar6 < *reinterpret_cast<int*>(base + 0x58));
      }
      int iVar6b = *reinterpret_cast<int*>(base + 0x88);
      std::uintptr_t iVar6u = static_cast<std::uintptr_t>(iVar6b);
      *reinterpret_cast<std::uint32_t*>(base + 0x5c) = 10;
      *reinterpret_cast<std::uint8_t*>(base + 0x80) = 1;
      *reinterpret_cast<std::uint8_t*>(iVar6u + 0xcd) = 1;
      uVar2 = 0;
      if (*reinterpret_cast<int*>(iVar6u + 0x80) != 0) {
        do {
          int iVar4 = *reinterpret_cast<int*>(*reinterpret_cast<std::uintptr_t*>(iVar6u + 0x78) + uVar2 * 4);
          if (iVar4 != 0) {
            FUN_00516e10(reinterpret_cast<void*>(iVar6u), reinterpret_cast<void*>(static_cast<std::uintptr_t>(iVar4)));
          }
          uVar2 = uVar2 + 1;
        } while (uVar2 < *reinterpret_cast<std::uint32_t*>(iVar6u + 0x80));
      }
      *reinterpret_cast<std::uint8_t*>(base + 0x7f) = 0;
      return;
    }
    int iVar6c = piVar3[1];
    piVar3 = reinterpret_cast<std::int32_t*>(*piVar3);
    if (piVar3 == nullptr) {
      using VFn = int (__cdecl*)(int);
      std::uint32_t vtable = *reinterpret_cast<std::uint32_t*>(base + 0x8c);
      VFn fn = reinterpret_cast<VFn>(*reinterpret_cast<std::uint32_t*>(vtable + 4));
      int iVar4 = fn(static_cast<char>(iVar6c));
      uVar2 = static_cast<std::uint32_t>(iVar4 + 1);
      if (uVar2 < *reinterpret_cast<std::uint32_t*>(base + 0x90)) {
        std::uint32_t* puVar5 = reinterpret_cast<std::uint32_t*>(*reinterpret_cast<std::uintptr_t*>(base + 0x94) + uVar2 * 4);
        do {
          piVar3 = reinterpret_cast<std::int32_t*>(*puVar5);
          if (piVar3 != nullptr) goto LAB_004e88d2;
          uVar2 = uVar2 + 1;
          puVar5 = puVar5 + 1;
        } while (uVar2 < *reinterpret_cast<std::uint32_t*>(base + 0x90));
      }
      piVar3 = nullptr;
    }
LAB_004e88d2:
    FUN_00511f90(static_cast<char>(iVar6c));
  } while( true );
}

// 0x4e8a10 — observed shape
void FUN_004e8a10(void* self) {
  std::uintptr_t base = reinterpret_cast<std::uintptr_t>(self);
  int iVar2 = 0;
  int local_4 = 0;
  if (0 < *reinterpret_cast<int*>(base + 0x58)) {
    int local_8 = 0;
    do {
      std::int32_t* piVar3 = reinterpret_cast<std::int32_t*>(*reinterpret_cast<int*>(base + 4) + iVar2);
      int iVar4 = *reinterpret_cast<int*>(base + 8) + local_8;
      if (piVar3 != nullptr) {
        int iVar1 = *reinterpret_cast<int*>(static_cast<std::uintptr_t>(iVar4) + 0x2c0);
        long double fVar6 = _CIfmod();
        piVar3[0x26] = static_cast<int>(static_cast<float>(fVar6));
        piVar3[0x24] = iVar1;
        fVar6 = _CIfmod();
        piVar3[0x27] = static_cast<int>(static_cast<float>(fVar6));
        piVar3[0x25] = iVar1;
        *(reinterpret_cast<std::uint8_t*>(piVar3) + 0xa4) = 0;
        FUN_004ea9a0();
        using VFn1 = void (__cdecl*)(std::uint32_t);
        using VFn2 = void (__cdecl*)(std::uint32_t);
        VFn1 fn1 = reinterpret_cast<VFn1>(*reinterpret_cast<std::uint32_t*>(*reinterpret_cast<std::uint32_t*>(piVar3) + 0x10));
        fn1(*reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iVar4) + 0x2b8));
        VFn2 fn2 = reinterpret_cast<VFn2>(*reinterpret_cast<std::uint32_t*>(*reinterpret_cast<std::uint32_t*>(piVar3) + 0x14));
        fn2(*reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iVar4) + 700));
        FUN_004ec0a0(piVar3);
        FUN_004ece40();
      }
      local_4 = local_4 + 1;
      local_8 = local_8 + 0x2cc;
      iVar2 = iVar2 + 0x124;
    } while (local_4 < *reinterpret_cast<int*>(base + 0x58));
  }
  FUN_004e8560(self);
  int iVar2b = *reinterpret_cast<int*>(base + 0x88);
  std::uintptr_t iVar2u = static_cast<std::uintptr_t>(iVar2b);
  *reinterpret_cast<std::uint32_t*>(base + 0x5c) = 10;
  *reinterpret_cast<std::uint8_t*>(base + 0x80) = 1;
  *reinterpret_cast<std::uint8_t*>(iVar2u + 0xcd) = 1;
  std::uint32_t uVar5 = 0;
  if (*reinterpret_cast<int*>(iVar2u + 0x80) != 0) {
    do {
      int iVar4 = *reinterpret_cast<int*>(*reinterpret_cast<std::uintptr_t*>(iVar2u + 0x78) + uVar5 * 4);
      if (iVar4 != 0) {
        FUN_00516e10(reinterpret_cast<void*>(iVar2u), reinterpret_cast<void*>(static_cast<std::uintptr_t>(iVar4)));
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *reinterpret_cast<std::uint32_t*>(iVar2u + 0x80));
  }
  *reinterpret_cast<std::uint8_t*>(base + 0x7f) = 1;
}
extern void* thunk_FUN_00533c78(std::size_t n);
extern void FUN_00511900();
extern char FUN_00519880();
extern void* DAT_008cad2c;
extern void FUN_005198f0(void* a, int b, void* c);
extern void FUN_00519a90();
extern void FUN_004e6420();
extern void FUN_005002f0();
extern void FUN_004ee0c0(void** p);
extern std::uint32_t FUN_00449390(void* a, std::uint32_t b);

// 0x4e8b60 — observed shape
void FUN_004e8b60(void* self) {
  std::uintptr_t base = reinterpret_cast<std::uintptr_t>(self);
  std::uint32_t uVar4 = 0;
  std::int32_t* piVar5 = nullptr;
  if (*reinterpret_cast<std::uint32_t*>(base + 0xa0) != 0) {
    piVar5 = *reinterpret_cast<std::int32_t**>(base + 0xa4);
    do {
      if (*piVar5 != 0) {
        piVar5 = reinterpret_cast<std::int32_t*>(static_cast<std::int32_t*>((*reinterpret_cast<std::int32_t**>(base + 0xa4))[uVar4]));
        goto joined_r0x004e8b99;
      }
      uVar4 = uVar4 + 1;
      piVar5 = piVar5 + 1;
    } while (uVar4 < *reinterpret_cast<std::uint32_t*>(base + 0xa0));
  }
  piVar5 = nullptr;
joined_r0x004e8b99:
  do {
    if (piVar5 == nullptr) {
      extern std::int16_t DAT_007d2168[];
      extern std::uint8_t DAT_0076ef10[];
      extern std::int32_t DAT_0072cd78;
      int local_1c = 0;
      std::int16_t* psVar11 = DAT_007d2168;
      std::uint8_t* pcVar7 = DAT_0076ef10;
      do {
        int local_20 = 0;
        do {
          int iVar10 = DAT_0072cd78;
          char cVar2 = static_cast<char>(*pcVar7);
          if (('\x10' < cVar2) && (cVar2 != '\x12')) {
            int local_24 = 0;
            switch (cVar2) {
              case '\x13': local_24 = 1000; break;
              case '\x16':
              case '\x1a':
              case '\x1b': local_24 = 0xfa; break;
              default: local_24 = 500; break;
            }
            std::int16_t sVar3 = *psVar11;
            float* pfVar8 = static_cast<float*>(thunk_FUN_00533c78(0x24));
            for (int k = 0; k < 9; ++k) pfVar8[k] = 0.0f;
            pfVar8[0] = static_cast<float>(local_1c);
            pfVar8[1] = static_cast<float>(local_20);
            pfVar8[2] = static_cast<float>(static_cast<int>(sVar3));
            pfVar8[3] = static_cast<float>(local_24);
            std::uint32_t vtable = *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iVar10) + 0xbc);
            using Maker = std::uint32_t* (__cdecl*)();
            Maker maker = reinterpret_cast<Maker>(*reinterpret_cast<std::uint32_t*>(vtable + 4));
            std::uint32_t* puVar9 = maker();
            puVar9[2] = reinterpret_cast<std::uint32_t>(pfVar8);
            puVar9[0] = 0;
            puVar9[1] = *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iVar10) + 0xc4);
            if (*reinterpret_cast<std::uint32_t**>(static_cast<std::uintptr_t>(iVar10) + 0xc4) == nullptr) {
              *reinterpret_cast<std::uint32_t**>(static_cast<std::uintptr_t>(iVar10) + 0xc0) = puVar9;
            } else {
              **reinterpret_cast<std::uint32_t**>(static_cast<std::uintptr_t>(iVar10) + 0xc4) = reinterpret_cast<std::uint32_t>(puVar9);
            }
            *reinterpret_cast<std::uint32_t**>(static_cast<std::uintptr_t>(iVar10) + 0xc4) = puVar9;
            *reinterpret_cast<int*>(static_cast<std::uintptr_t>(iVar10) + 200) = *reinterpret_cast<int*>(static_cast<std::uintptr_t>(iVar10) + 200) + 1;
          }
          psVar11 = psVar11 + 1;
          local_20 = local_20 + 1000;
          pcVar7 = pcVar7 + 1;
        } while (local_20 < 0x47888);
        local_1c = local_1c + 1000;
      } while (reinterpret_cast<std::uintptr_t>(pcVar7) < 0x78ffd6);
      int iVar6 = 0;
      int iVar10c = 0;
      if (0 < *reinterpret_cast<int*>(base + 0x58)) {
        int local_1c2 = 0;
        do {
          int iVar12 = *reinterpret_cast<int*>(base + 4) + local_1c2;
          if (iVar12 != 0) {
            std::uint32_t uVar1 = *reinterpret_cast<std::uint32_t*>(*reinterpret_cast<int*>(base + 8) + 0x2c8 + iVar6);
            long double fVar13 = _CIfmod();
            *reinterpret_cast<float*>(static_cast<std::uintptr_t>(iVar12) + 0x98) = static_cast<float>(fVar13);
            *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iVar12) + 0x90) = uVar1;
            fVar13 = _CIfmod();
            *reinterpret_cast<float*>(static_cast<std::uintptr_t>(iVar12) + 0x9c) = static_cast<float>(fVar13);
            *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iVar12) + 0x94) = uVar1;
            *reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(iVar12) + 0xa4) = 0;
            FUN_004ea9a0();
            FUN_00511f10();
            FUN_004ec790();
          }
          iVar10c = iVar10c + 1;
          local_1c2 = local_1c2 + 0x124;
          iVar6 = iVar6 + 0x2cc;
        } while (iVar10c < *reinterpret_cast<int*>(base + 0x58));
      }
      int iVar10d = *reinterpret_cast<int*>(base + 0x88);
      std::uintptr_t iVar10u = static_cast<std::uintptr_t>(iVar10d);
      uVar4 = 0;
      *reinterpret_cast<std::uint8_t*>(iVar10u + 0xcd) = 1;
      if (*reinterpret_cast<int*>(iVar10u + 0x80) != 0) {
        do {
          int iVar6b = *reinterpret_cast<int*>(*reinterpret_cast<std::uintptr_t*>(iVar10u + 0x78) + uVar4 * 4);
          if (iVar6b != 0) {
            FUN_00516e10(reinterpret_cast<void*>(iVar10u), reinterpret_cast<void*>(static_cast<std::uintptr_t>(iVar6b)));
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < *reinterpret_cast<std::uint32_t*>(iVar10u + 0x80));
      }
      *reinterpret_cast<std::uint8_t*>(base + 0x80) = 1;
      *reinterpret_cast<std::uint32_t*>(base + 0x5c) = 10;
      return;
    }
    int iVar10e = piVar5[1];
    piVar5 = reinterpret_cast<std::int32_t*>(*piVar5);
    if (piVar5 == nullptr) {
      using VFn = int (__cdecl*)(int);
      std::uint32_t vtable = *reinterpret_cast<std::uint32_t*>(base + 0x9c);
      VFn fn = reinterpret_cast<VFn>(*reinterpret_cast<std::uint32_t*>(vtable + 4));
      int iVar6c = fn(static_cast<char>(iVar10e));
      uVar4 = static_cast<std::uint32_t>(iVar6c + 1);
      if (uVar4 < *reinterpret_cast<std::uint32_t*>(base + 0xa0)) {
        std::uint32_t* puVar9 = reinterpret_cast<std::uint32_t*>(*reinterpret_cast<std::uintptr_t*>(base + 0xa4) + uVar4 * 4);
        do {
          piVar5 = reinterpret_cast<std::int32_t*>(*puVar9);
          if (piVar5 != nullptr) goto LAB_004e8bd2;
          uVar4 = uVar4 + 1;
          puVar9 = puVar9 + 1;
        } while (uVar4 < *reinterpret_cast<std::uint32_t*>(base + 0xa0));
      }
      piVar5 = nullptr;
    }
LAB_004e8bd2:
    FUN_00511f90(static_cast<char>(iVar10e));
  } while( true );
}

// 0x4e8ea0 — observed shape
void FUN_004e8ea0(void* self) {
  std::uintptr_t base = reinterpret_cast<std::uintptr_t>(self);
  int iVar2 = 0;
  int local_4 = 0;
  if (0 < *reinterpret_cast<int*>(base + 0x58)) {
    int local_8 = 0;
    do {
      std::int32_t* piVar3 = reinterpret_cast<std::int32_t*>(*reinterpret_cast<int*>(base + 4) + iVar2);
      int iVar5 = *reinterpret_cast<int*>(base + 8) + local_8;
      if (piVar3 != nullptr) {
        int iVar1 = *reinterpret_cast<int*>(static_cast<std::uintptr_t>(iVar5) + 0x2c0);
        long double fVar6 = _CIfmod();
        piVar3[0x26] = static_cast<int>(static_cast<float>(fVar6));
        piVar3[0x24] = iVar1;
        fVar6 = _CIfmod();
        piVar3[0x27] = static_cast<int>(static_cast<float>(fVar6));
        piVar3[0x25] = iVar1;
        *(reinterpret_cast<std::uint8_t*>(piVar3) + 0xa4) = 0;
        FUN_004ea9a0();
        using VFn1 = void (__cdecl*)(std::uint32_t);
        using VFn2 = void (__cdecl*)(std::uint32_t);
        VFn1 fn1 = reinterpret_cast<VFn1>(*reinterpret_cast<std::uint32_t*>(*reinterpret_cast<std::uint32_t*>(piVar3) + 0x10));
        fn1(*reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iVar5) + 0x2b8));
        VFn2 fn2 = reinterpret_cast<VFn2>(*reinterpret_cast<std::uint32_t*>(*reinterpret_cast<std::uint32_t*>(piVar3) + 0x14));
        fn2(*reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iVar5) + 700));
        FUN_004ec0a0(piVar3);
        FUN_004ece40();
      }
      local_4 = local_4 + 1;
      local_8 = local_8 + 0x2cc;
      iVar2 = iVar2 + 0x124;
    } while (local_4 < *reinterpret_cast<int*>(base + 0x58));
  }
  FUN_004e8560(self);
  *reinterpret_cast<std::uint32_t*>(base + 0x5c) = 10;
  *reinterpret_cast<std::uint8_t*>(base + 0x80) = 1;
  int iVar2b = *reinterpret_cast<int*>(base + 0x88);
  std::uintptr_t iVar2u = static_cast<std::uintptr_t>(iVar2b);
  *reinterpret_cast<std::uint8_t*>(iVar2u + 0xcd) = 1;
  std::uint32_t uVar4 = 0;
  if (*reinterpret_cast<int*>(iVar2u + 0x80) != 0) {
    do {
      int iVar5 = *reinterpret_cast<int*>(*reinterpret_cast<std::uintptr_t*>(iVar2u + 0x78) + uVar4 * 4);
      if (iVar5 != 0) {
        FUN_00516e10(reinterpret_cast<void*>(iVar2u), reinterpret_cast<void*>(static_cast<std::uintptr_t>(iVar5)));
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *reinterpret_cast<std::uint32_t*>(iVar2u + 0x80));
  }
}

// 0x4e8ff0 — observed shape
void FUN_004e8ff0(std::uint32_t* self) {
  static std::uint32_t PTR_LAB_0070fe2c = 0;
  static std::uint32_t PTR_FUN_0070fe10 = 0;
  static std::uint32_t PTR_FUN_0070fd48 = 0;
  static std::uint32_t PTR_FUN_0070fd64 = 0;
  FUN_00511900();
  self[0] = PTR_LAB_0070fe2c;
  self[0x2b] = 0;
  self[0x3a] = 0;
  self[0x3b] = 0;
  self[0x3c] = 0;
  self[0x3d] = 0;
  self[0x3e] = PTR_FUN_0070fe10;
  self[0x40] = 0;
  self[0x43] = 1;
  self[0x41] = 0;
  self[0x42] = 0;
  self[0x3f] = 0;
  self[0x45] = PTR_FUN_0070fd48;
  self[0x46] = 0x25;
  self[0x48] = 0;
  std::uint32_t* puVar2 = static_cast<std::uint32_t*>(thunk_FUN_00533c78(0x94));
  self[0x47] = reinterpret_cast<std::uint32_t>(puVar2);
  for (std::uint32_t uVar3 = self[0x46] & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  for (int iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(reinterpret_cast<std::uint8_t*>(puVar2)) = 0;
    puVar2 = reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uintptr_t>(puVar2) + 1);
  }
  self[0x45] = PTR_FUN_0070fd64;
  self[0x2c] = 0;
  self[0x2d] = 0;
  self[0x2e] = 0;
  self[0x2f] = 0;
  *(reinterpret_cast<std::uint8_t*>(self) + 0xc0) = 0;
  self[0x33] = 0;
  self[0x32] = 0;
  self[0x34] = 0;
  self[0x31] = 0;
  self[0x36] = 0;
  self[0x37] = 0;
  self[0x38] = 0;
  self[0x39] = 0;
  auto release = [](std::uint32_t* p) {
    if (p != nullptr) {
      std::uint32_t* piVar1 = p + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        using VFn = void (__cdecl*)(int);
        VFn fn = reinterpret_cast<VFn>(*p);
        fn(1);
      }
    }
  };
  release(reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(self[0x3b])));
  self[0x3b] = 0;
  release(reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(self[0x3a])));
  self[0x3a] = 0;
  release(reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(self[0x3c])));
  self[0x3c] = 0;
  release(reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(self[0x3d])));
  self[0x3d] = 0;
  self[0x44] = 0;
  *(reinterpret_cast<std::uint8_t*>(self) + 0xc1) = 0;
  *(reinterpret_cast<std::uint8_t*>(self) + 0xa5) = 0;
}

// 0x4e9170 — observed shape
void FUN_004e9170(std::uint32_t* self) {
  static std::uint32_t PTR_LAB_0070fe2c = 0;
  static std::uint32_t PTR_FUN_0070fe10 = 0;
  static std::uint32_t PTR_FUN_0070fd48 = 0;
  static std::uint32_t PTR_FUN_0070fd64 = 0;
  static std::uint32_t PTR_FUN_00711868 = 0;
  self[0] = PTR_LAB_0070fe2c;
  if (self[0x36] != 0) { std::free(reinterpret_cast<void*>(static_cast<std::uintptr_t>(self[0x36]))); self[0x36] = 0; }
  if (self[0x37] != 0) { std::free(reinterpret_cast<void*>(static_cast<std::uintptr_t>(self[0x37]))); self[0x37] = 0; }
  if (self[0x38] != 0) { std::free(reinterpret_cast<void*>(static_cast<std::uintptr_t>(self[0x38]))); self[0x38] = 0; }
  if (self[0x39] != 0) { std::free(reinterpret_cast<void*>(static_cast<std::uintptr_t>(self[0x39]))); self[0x39] = 0; }
  std::uint32_t uVar4 = 0;
  if (self[0x41] != 0) {
    do {
      *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(self[0x3f]) + uVar4 * 4) = 0;
      uVar4 = uVar4 + 1;
    } while (uVar4 < self[0x41]);
  }
  self[0x41] = 0;
  self[0x42] = 0;
  char cVar3 = FUN_00519880();
  if (cVar3 != '\0') {
    char local_4[4] = {};
    FUN_005198f0(DAT_008cad2c, 8, local_4);
    FUN_00519a90();
    FUN_005198f0(DAT_008cad2c, 9, local_4);
    FUN_00519a90();
    FUN_005198f0(DAT_008cad2c, 10, local_4);
    FUN_00519a90();
    FUN_005198f0(DAT_008cad2c, 5, reinterpret_cast<void*>(static_cast<std::uintptr_t>(self[0x33])));
    FUN_005198f0(DAT_008cad2c, 6, reinterpret_cast<void*>(static_cast<std::uintptr_t>(self[0x32])));
    FUN_005198f0(DAT_008cad2c, 7, reinterpret_cast<void*>(static_cast<std::uintptr_t>(self[0x34])));
  }
  FUN_004e6420();
  FUN_004ea360();
  self[0x45] = PTR_FUN_0070fd64;
  FUN_004e6420();
  self[0x45] = PTR_FUN_0070fd48;
  FUN_004e6420();
  ::operator delete(reinterpret_cast<void*>(static_cast<std::uintptr_t>(self[0x47])));
  self[0x3e] = PTR_FUN_0070fe10;
  ::operator delete(reinterpret_cast<void*>(static_cast<std::uintptr_t>(self[0x3f])));
  auto release = [](std::uint32_t* p) {
    if (p != nullptr) {
      std::uint32_t* piVar1 = p + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        using VFn = void (__cdecl*)(int);
        VFn fn = reinterpret_cast<VFn>(*p);
        fn(1);
      }
    }
  };
  release(reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(self[0x3d])));
  release(reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(self[0x3c])));
  release(reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(self[0x3b])));
  release(reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(self[0x3a])));
  release(reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(self[0x2b])));
  self[0] = PTR_FUN_00711868;
  release(reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(self[1])));
}

// 0x4e93b0 — observed shape
void FUN_004e93b0(std::int32_t* param1, std::uint32_t param2, std::uint32_t param3, std::uint32_t* param4) {
  extern std::uint32_t DAT_008caca4;
  extern std::uint32_t DAT_008cac9c;
  extern std::uint32_t DAT_008caca0;
  extern std::int32_t* DAT_008cacac;
  extern std::uint8_t DAT_008caca8;
  extern std::uint32_t DAT_007273fc;
  extern std::uint32_t DAT_00727598;
  DAT_008caca4 = reinterpret_cast<std::uint32_t>(param4);
  DAT_008cac9c = param2;
  DAT_008caca0 = param3;
  DAT_008cacac = param1;
  DAT_008caca8 = '\x01';
  FUN_005002f0();
  if ((param4 < reinterpret_cast<std::uint32_t*>(0xb)) || (param2 < 0xb)) {
    DAT_008caca8 = '\0';
  } else if (DAT_008caca8 != '\0') {
    std::uint32_t* puVar2 = reinterpret_cast<std::uint32_t*>(*param1);
    if (puVar2 != nullptr) {
      puVar2[1] = puVar2[1] + 1;
    }
    std::uint32_t* param4b = puVar2;
    FUN_004ee0c0(reinterpret_cast<void**>(&param4b));
    if (puVar2 != nullptr) {
      std::uint32_t* piVar1 = puVar2 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        using VFn = void (__cdecl*)(int);
        VFn fn = reinterpret_cast<VFn>(*puVar2);
        fn(1);
      }
    }
    std::uint32_t uVar3 = FUN_00449390(&DAT_007273fc, 0);
    FUN_00449390(&DAT_00727598, uVar3);
  }
}
extern void FUN_00533d10(void* a, int b);
extern int FUN_004ee070(int p);
extern int DAT_0072cd78;
extern std::uint8_t DAT_007264bd;
extern std::uint32_t DAT_007253b8;
extern std::uint32_t DAT_0071000c;
extern std::uint32_t DAT_00727898;
extern std::int32_t* FUN_00540540(void* p);
extern void FUN_004add70(void* p);
extern void FUN_004ad820();
extern void FUN_004ed130();
extern int FUN_005f0ddc();
extern void FUN_0051a700(std::uint32_t i);
extern void FUN_00519610(std::uint32_t p, void* buf);
extern void FUN_00533db0(int v);
extern void FUN_004aad70();
extern int DAT_008cacb4;

// 0x4e9480 — observed shape
void FUN_004e9480(void* self, int param_1) {
  std::uintptr_t base = reinterpret_cast<std::uintptr_t>(self);
  if (((*reinterpret_cast<int*>(base + 0xac) != 0) && (*reinterpret_cast<char*>(base + 0xc1) == '\0')) &&
      (*reinterpret_cast<char*>(static_cast<std::uintptr_t>(DAT_0072cd78) + 0x81) != '\0')) {
    if (*reinterpret_cast<char*>(base + 0xc0) != '\0') {
      FUN_00533d10(0, 1);
      *reinterpret_cast<std::uint8_t*>(base + 0xc0) = 0;
    }
    int iVar9 = param_1 + 0x18c;
    std::uint32_t uVar10 = 0;
    do {
      int iVar5 = FUN_004ee070(iVar9);
      if (iVar5 == 2) {
        return;
      }
      uVar10 = uVar10 + 1;
      iVar9 = iVar9 + 0x10;
    } while (uVar10 < 6);
    if (*reinterpret_cast<int*>(base + 0xb0) != 0) {
      float fVar3 = static_cast<float>(*reinterpret_cast<int*>(base + 0xb8));
      int iVar9b = 0;
      if (*reinterpret_cast<int*>(base + 0xb8) < 0) {
        fVar3 = fVar3 + 4.2949673e+09f;
      }
      if (0.0f < fVar3 * 0.125f) {
        do {
          fVar3 = static_cast<float>(*reinterpret_cast<int*>(base + 0xbc));
          int iVar5 = 0;
          if (*reinterpret_cast<int*>(base + 0xbc) < 0) {
            fVar3 = fVar3 + 4.2949673e+09f;
          }
          if (0.0f < fVar3 * 0.125f) {
            do {
              int iVar2 = *reinterpret_cast<int*>(*reinterpret_cast<std::uintptr_t*>(*reinterpret_cast<std::uintptr_t*>(base + 0xb0) + iVar9b * 4) + iVar5 * 4);
              if (iVar2 != 0) {
                fVar3 = -*reinterpret_cast<float*>(static_cast<std::uintptr_t>(iVar2) + 0x34);
                uVar10 = 0;
                float* pfVar8 = reinterpret_cast<float*>(static_cast<std::uintptr_t>(param_1) + 0x194);
                do {
                  float fVar4 = (*reinterpret_cast<float*>(static_cast<std::uintptr_t>(iVar2) + 0x30) * *pfVar8 +
                                 *reinterpret_cast<float*>(static_cast<std::uintptr_t>(iVar2) + 0x28) * pfVar8[-2] +
                                 *reinterpret_cast<float*>(static_cast<std::uintptr_t>(iVar2) + 0x2c) * pfVar8[-1]) - pfVar8[1];
                  if ((!std::isnan(fVar4) && !std::isnan(fVar3)) && (fVar4 < fVar3) != (fVar4 == fVar3)) {
                    goto LAB_004e96b5;
                  }
                  uVar10 = uVar10 + 1;
                  pfVar8 = pfVar8 + 4;
                } while (uVar10 < 6);
                if (DAT_007264bd != '\0') {
                  FUN_004add70(reinterpret_cast<void*>(static_cast<std::uintptr_t>(DAT_007253b8)));
                  FUN_004ad820();
                  DAT_007264bd = '\0';
                }
                std::int32_t* piVar6 = FUN_00540540(reinterpret_cast<void*>(static_cast<std::uintptr_t>(DAT_0071000c)));
                if (piVar6 != nullptr) {
                  using Maker = std::uint32_t* (__cdecl*)();
                  Maker maker = reinterpret_cast<Maker>(*reinterpret_cast<std::uint32_t*>(*reinterpret_cast<std::uint32_t*>(piVar6) + 4));
                  std::uint32_t* puVar7 = maker();
                  while ((puVar7 != nullptr && (puVar7 != &DAT_00727898))) {
                    puVar7 = reinterpret_cast<std::uint32_t*>(puVar7[1]);
                  }
                }
                FUN_004ed130();
                std::uint8_t* pbVar1 = reinterpret_cast<std::uint8_t*>(*reinterpret_cast<std::uintptr_t*>(*reinterpret_cast<std::uintptr_t*>(*reinterpret_cast<std::uintptr_t*>(base + 0xb0) + iVar9b * 4) + iVar5 * 4) + 0x20);
                *pbVar1 = *pbVar1 & 0xfe;
                {
                  int target = *reinterpret_cast<int*>(*reinterpret_cast<std::uintptr_t*>(*reinterpret_cast<std::uintptr_t*>(*reinterpret_cast<std::uintptr_t*>(base + 0xb0) + iVar9b * 4) + iVar5 * 4);
                  std::uint32_t vt = *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(target));
                  using VFn = void (__cdecl*)(int);
                  VFn fn = reinterpret_cast<VFn>(*reinterpret_cast<std::uint32_t*>(vt + 0x60));
                  fn(param_1);
                }
                pbVar1 = reinterpret_cast<std::uint8_t*>(*reinterpret_cast<std::uintptr_t*>(*reinterpret_cast<std::uintptr_t*>(*reinterpret_cast<std::uintptr_t*>(base + 0xb0) + iVar9b * 4) + iVar5 * 4) + 0x20);
                *pbVar1 = *pbVar1 | 1;
              }
LAB_004e96b5:
              iVar5 = iVar5 + 1;
              fVar3 = static_cast<float>(iVar5);
              if (iVar5 < 0) {
                fVar3 = fVar3 + 4.2949673e+09f;
              }
              float fVar4 = static_cast<float>(*reinterpret_cast<int*>(base + 0xbc));
              if (*reinterpret_cast<int*>(base + 0xbc) < 0) {
                fVar4 = fVar4 + 4.2949673e+09f;
              }
            } while (fVar3 < fVar4 * 0.125f);
          }
          iVar9b = iVar9b + 1;
          fVar3 = static_cast<float>(iVar9b);
          if (iVar9b < 0) {
            fVar3 = fVar3 + 4.2949673e+09f;
          }
          float fVar4 = static_cast<float>(*reinterpret_cast<int*>(base + 0xb8));
          if (*reinterpret_cast<int*>(base + 0xb8) < 0) {
            fVar4 = fVar4 + 4.2949673e+09f;
          }
        } while (fVar3 < fVar4 * 0.125f);
      }
    }
  }
}

// 0x4e9740 — observed shape
void FUN_004e9740(void* self, std::uint8_t in_AL) {
  std::uintptr_t base = reinterpret_cast<std::uintptr_t>(self);
  *reinterpret_cast<std::uint8_t*>(base + 0xc1) = in_AL;
  *reinterpret_cast<std::uint8_t*>(base + 0xc0) = 1;
  if (*reinterpret_cast<int*>(base + 0xb0) != 0) {
    float fVar3 = static_cast<float>(*reinterpret_cast<int*>(base + 0xb8));
    int iVar5 = 0;
    if (*reinterpret_cast<int*>(base + 0xb8) < 0) {
      fVar3 = fVar3 + 4.2949673e+09f;
    }
    if (0.0f < fVar3 * 0.125f) {
      do {
        fVar3 = static_cast<float>(*reinterpret_cast<int*>(base + 0xbc));
        int iVar4 = 0;
        if (*reinterpret_cast<int*>(base + 0xbc) < 0) {
          fVar3 = fVar3 + 4.2949673e+09f;
        }
        if (0.0f < fVar3 * 0.125f) {
          do {
            int iVar2 = *reinterpret_cast<int*>(*reinterpret_cast<std::uintptr_t*>(*reinterpret_cast<std::uintptr_t*>(base + 0xb0) + iVar5 * 4) + iVar4 * 4);
            if (iVar2 != 0) {
              std::uint16_t* puVar1 = reinterpret_cast<std::uint16_t*>(static_cast<std::uintptr_t>(iVar2) + 0x20);
              *puVar1 = *puVar1 | 1;
            }
            iVar4 = iVar4 + 1;
            fVar3 = static_cast<float>(*reinterpret_cast<int*>(base + 0xbc));
            if (*reinterpret_cast<int*>(base + 0xbc) < 0) {
              fVar3 = fVar3 + 4.2949673e+09f;
            }
          } while (static_cast<float>(iVar4) < fVar3 * 0.125f);
        }
        iVar5 = iVar5 + 1;
        fVar3 = static_cast<float>(*reinterpret_cast<int*>(base + 0xb8));
        if (*reinterpret_cast<int*>(base + 0xb8) < 0) {
          fVar3 = fVar3 + 4.2949673e+09f;
        }
      } while (static_cast<float>(iVar5) < fVar3 * 0.125f);
    }
  }
}

// 0x4e9840 — observed shape
long double FUN_004e9840(void* self) {
  std::uintptr_t base = reinterpret_cast<std::uintptr_t>(self);
  if (*reinterpret_cast<char*>(base + 0xa0) == '\0') {
    return 0.0L;
  }
  int iVar2 = FUN_005f0ddc();
  int iVar1 = *reinterpret_cast<int*>(base + 0xb8);
  int iVar3 = FUN_005f0ddc();
  return static_cast<long double>(*reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(iVar3 - iVar2 * iVar1) + *reinterpret_cast<int*>(base + 0xcc))) * 0.003921569L;
}

// 0x4e98d0 — observed shape
void FUN_004e98d0(std::uint32_t param_1) {
  std::uint32_t uVar1 = 0;
  std::uint8_t local_100[256];
  do {
    FUN_0051a700(uVar1);
    FUN_00519610(param_1, local_100);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 3);
}

// 0x4e9920 — observed shape
void FUN_004e9920(void* self, std::uint32_t param_1) {
  std::uintptr_t base = reinterpret_cast<std::uintptr_t>(self);
  if (*reinterpret_cast<int*>(base + 0xec) != 0) {
    FUN_00533d10(reinterpret_cast<void*>(static_cast<std::uintptr_t>(param_1)), 1);
  }
  if (*reinterpret_cast<int*>(base + 0xf0) != 0) {
    std::uint32_t uVar3 = 1;
    _CIfmod();
    int iVar2 = FUN_005f0ddc();
    float fVar1 = static_cast<float>(iVar2);
    if (iVar2 < 0) {
      fVar1 = fVar1 + 4.2949673e+09f;
    }
    FUN_00533d10(reinterpret_cast<void*>(static_cast<std::uintptr_t>(static_cast<std::uint32_t>(fVar1 * 0.016666668f))), uVar3);
  }
  if (*reinterpret_cast<int*>(base + 0xf4) != 0) {
    *reinterpret_cast<std::uint32_t*>(base + 0x110) = static_cast<std::uint32_t>(( *reinterpret_cast<int*>(base + 0x110) + 1) % (DAT_008cacb4 * 2));
    FUN_00533db0(8);
    if (((*reinterpret_cast<std::uint32_t*>(base + 0x110) & 1) == 0)) {
      FUN_004aad70();
      return;
    }
  }
}
extern char* _strdup(const char* s);
extern void FUN_004f8110(void* p);
extern int FUN_004f1220(int a, int b);
extern void FUN_004f8250(void* p);
extern void FUN_004f85e0(void* a, void* b);
extern void FUN_004f3ee0();
extern void FUN_004f2600(void* a, void* b);
extern void FUN_00412f90();
extern void FUN_004f3350();
extern void FUN_004f84d0(void* p);
extern void FUN_004ed9a0();
extern void FUN_004eda50();
extern void FUN_00412970();
extern void FUN_00412b40();
extern std::uint8_t DAT_008cacd0[];
extern std::uint8_t DAT_008cacc8[];
extern std::uint8_t DAT_00710530[];
extern std::int32_t DAT_008cacac;
extern int FUN_004f4b20(void* self, int a, int b, int c);

// 0x4e99e0 — observed shape
void FUN_004e99e0(void* self, char* param_1) {
  std::uintptr_t base = reinterpret_cast<std::uintptr_t>(self);
  if (*reinterpret_cast<void**>(base + 0xd8) != nullptr) {
    std::free(*reinterpret_cast<void**>(base + 0xd8));
    *reinterpret_cast<std::uint32_t*>(base + 0xd8) = 0;
  }
  char* pcVar1 = _strdup(param_1);
  *reinterpret_cast<char**>(base + 0xd8) = pcVar1;
  FUN_00519610(static_cast<std::uint32_t>(base), pcVar1);
}

// 0x4e9a30 — observed shape
void FUN_004e9a30(void* self) {
  extern std::uint32_t PTR_FUN_006f5814;
  std::uint8_t* local_28 = DAT_008cacd0;
  std::uint32_t local_40 = 0;
  std::uint32_t local_3c = 0;
  std::uint32_t local_38 = 0;
  std::uint32_t local_34 = 0;
  std::uint32_t local_30 = 0;
  std::uint32_t local_2c = 0;
  int local_1c = 0;
  int local_18 = 0;
  std::uint32_t* local_44 = &PTR_FUN_006f5814;
  std::uint8_t* local_10 = DAT_008cacd0;
  std::uint8_t* local_c = DAT_008cacd0;
  std::uint32_t local_14 = 0;
  std::uint32_t local_8 = 0;
  int local_4 = 0;
  wchar_t* local_64 = reinterpret_cast<wchar_t*>(DAT_008cacd0);
  float local_60 = 0;
  float local_5c = 0;
  float local_58 = 0;
  float local_54 = 0;
  float local_50 = 0;
  int local_4c[2] = {0};
  std::uint32_t local_24 = 0;
  int iVar2 = FUN_004f4b20(self, 1, 0, 0);
  if (iVar2 == 0) {
    FUN_004f8110(&local_44);
    if (local_18 == 0) {
      local_4 = FUN_004f1220(0, 1);
    } else {
      local_4 = *reinterpret_cast<int*>(static_cast<std::uintptr_t>(local_18) + 0x14);
    }
    if (local_24 == 1) {
      FUN_004f8250(&local_44);
    }
    using VFn = std::uint32_t (__cdecl*)(int, int);
    VFn vf = reinterpret_cast<VFn>(local_44[7]);
    std::uint32_t uVar3 = vf(0, 1);
    using VFn0 = std::uint32_t (__cdecl*)();
    VFn0 vf2 = reinterpret_cast<VFn0>(*reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(local_4c[0]) + 0x10));
    std::uint32_t uVar4 = vf2();
    if (uVar3 < uVar4) {
      wchar_t* unaff_EDI = reinterpret_cast<wchar_t*>(reinterpret_cast<std::uintptr_t>(DAT_008cacd0));
      std::uint8_t* unaff_EBX = DAT_008cacd0;
      do {
        if (local_1c == 1) {
          local_64 = reinterpret_cast<wchar_t*>(DAT_008cacd0);
          FUN_004f85e0(local_4c, &local_64);
          wchar_t* pwVar8 = local_64;
          if ((local_64 != nullptr) && (std::wcslen(local_64) >= 0)) {
            FUN_004f3ee0();
            local_64 = reinterpret_cast<wchar_t*>(DAT_008cacd0);
            FUN_004f2600(DAT_00710530, unaff_EBX);
            wchar_t* pwVar9 = local_64;
            std::size_t sVar5 = *reinterpret_cast<std::size_t*>(local_64 + -2);
            if ((sVar5 >= 0) && (local_64 != unaff_EDI)) {
              if (sVar5 == 0) {
                FUN_00412f90();
              } else {
                FUN_004f3350();
                wchar_t* pwVar10 = unaff_EDI;
                std::memmove(unaff_EDI, pwVar9, sVar5);
                *(reinterpret_cast<char*>(unaff_EDI) + *reinterpret_cast<int*>(reinterpret_cast<char*>(unaff_EDI) + -2)) = '\0';
                unaff_EDI = pwVar10;
              }
            }
            wchar_t* pwVar9b = pwVar9 + -4;
            if ((pwVar9b != nullptr) && (pwVar9b != reinterpret_cast<wchar_t*>(DAT_008cacc8))) {
              ::operator delete(pwVar9b);
            }
            std::uint32_t* puVar6 = reinterpret_cast<std::uint32_t*>(unaff_EBX + -8);
            if ((puVar6 != nullptr) && (puVar6 != reinterpret_cast<std::uint32_t*>(DAT_008cacc8))) {
              ::operator delete(puVar6);
            }
            unaff_EBX = DAT_008cacd0;
          }
          wchar_t* pwVar8b = pwVar8 + -4;
          if ((pwVar8b != nullptr) && (pwVar8b != reinterpret_cast<wchar_t*>(DAT_008cacc8))) {
            ::operator delete(pwVar8b);
          }
        } else {
          FUN_004f84d0(local_4c + -8);
        }
        int iVar7 = std::sscanf(reinterpret_cast<const char*>(unaff_EDI), "line = %f , %f , %f , %f", &local_5c, &local_58, &local_54, &local_50);
        int iVar2b = local_4;
        if (iVar7 == 4) {
          float fVar1 = static_cast<float>(*reinterpret_cast<int*>(static_cast<std::uintptr_t>(local_4) + 0x6c));
          if (*reinterpret_cast<int*>(static_cast<std::uintptr_t>(local_4) + 0x6c) < 0) { fVar1 = fVar1 + 4.2949673e+09f; }
          local_64 = *reinterpret_cast<wchar_t**>(static_cast<std::uintptr_t>(local_4) + 0x104);
          local_60 = fVar1 * *reinterpret_cast<float*>(static_cast<std::uintptr_t>(local_4) + 0x84) * local_5c;
          if (*reinterpret_cast<wchar_t**>(static_cast<std::uintptr_t>(local_4) + 0x100) <= local_64) { FUN_004ed9a0(); }
          FUN_004eda50();
          fVar1 = static_cast<float>(*reinterpret_cast<int*>(static_cast<std::uintptr_t>(iVar2b) + 0x70));
          if (*reinterpret_cast<int*>(static_cast<std::uintptr_t>(iVar2b) + 0x70) < 0) { fVar1 = fVar1 + 4.2949673e+09f; }
          local_60 = *reinterpret_cast<float*>(static_cast<std::uintptr_t>(iVar2b) + 0x104);
          local_64 = reinterpret_cast<wchar_t*>(-(fVar1 * *reinterpret_cast<float*>(static_cast<std::uintptr_t>(iVar2b) + 0x88) * local_58));
          if (*reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iVar2b) + 0x100) <= static_cast<std::uint32_t>(local_60)) { FUN_004ed9a0(); }
          FUN_004eda50();
          fVar1 = static_cast<float>(*reinterpret_cast<int*>(static_cast<std::uintptr_t>(iVar2b) + 0x6c));
          if (*reinterpret_cast<int*>(static_cast<std::uintptr_t>(iVar2b) + 0x6c) < 0) { fVar1 = fVar1 + 4.2949673e+09f; }
          local_60 = fVar1 * *reinterpret_cast<float*>(static_cast<std::uintptr_t>(iVar2b) + 0x84) * local_54;
          if (*reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iVar2b) + 0x100) <= *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iVar2b) + 0x104)) { FUN_004ed9a0(); }
          FUN_004eda50();
          fVar1 = static_cast<float>(*reinterpret_cast<int*>(static_cast<std::uintptr_t>(local_4) + 0x70));
          if (*reinterpret_cast<int*>(static_cast<std::uintptr_t>(local_4) + 0x70) < 0) { fVar1 = fVar1 + 4.2949673e+09f; }
          local_60 = -(fVar1 * *reinterpret_cast<float*>(static_cast<std::uintptr_t>(local_4) + 0x88) * local_50);
          if (*reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iVar2b) + 0x100) <= *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iVar2b) + 0x104)) { FUN_004ed9a0(); }
          FUN_004eda50();
        }
        using VFn3 = std::uint32_t (__cdecl*)(int, int);
        VFn3 vf3 = reinterpret_cast<VFn3>(*reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(local_4c[0]) + 0x1c));
        uVar3 = vf3(0, 1);
        VFn3 vf4 = reinterpret_cast<VFn3>(*reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(static_cast<std::uint32_t>(local_54)) + 0x10));
        uVar4 = vf4();
      } while (uVar3 < uVar4);
    }
    FUN_00412970();
  }
  wchar_t* pwVar8 = local_64 + -4;
  if ((pwVar8 != nullptr) && (pwVar8 != reinterpret_cast<wchar_t*>(DAT_008cacc8))) {
    ::operator delete(pwVar8);
  }
  FUN_00412b40();
}

// 0x4e9db0 — observed shape
void FUN_004e9db0(void* self, char* param_1) {
  std::uintptr_t base = reinterpret_cast<std::uintptr_t>(self);
  if (*reinterpret_cast<void**>(base + 0xdc) != nullptr) {
    std::free(*reinterpret_cast<void**>(base + 0xdc));
    *reinterpret_cast<std::uint32_t*>(base + 0xdc) = 0;
  }
  char* pcVar1 = _strdup(param_1);
  *reinterpret_cast<char**>(base + 0xdc) = pcVar1;
  FUN_00519610(static_cast<std::uint32_t>(base), pcVar1);
}

// 0x4e9e00 — observed shape
void FUN_004e9e00(void* self, char* param_1) {
  std::uintptr_t base = reinterpret_cast<std::uintptr_t>(self);
  if (*reinterpret_cast<void**>(base + 0xe4) != nullptr) {
    std::free(*reinterpret_cast<void**>(base + 0xe4));
    *reinterpret_cast<std::uint32_t*>(base + 0xe4) = 0;
  }
  char* pcVar1 = _strdup(param_1);
  *reinterpret_cast<char**>(base + 0xe4) = pcVar1;
  FUN_00519610(static_cast<std::uint32_t>(base), pcVar1);
}

// 0x4ea360 — observed shape
void FUN_004ea360(std::uint32_t* self) {
  auto call74 = [](std::uint32_t basePtr) -> std::uint32_t* {
    std::uint32_t* out = nullptr;
    if (basePtr != 0) {
      std::uint32_t vt = *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(basePtr) + 0x24);
      using VFn = std::uint32_t* (__cdecl*)(void*, std::uint32_t);
      VFn fn = reinterpret_cast<VFn>(*reinterpret_cast<std::uint32_t*>(vt + 0x74));
      void* tmp = nullptr;
      out = fn(&tmp, basePtr);
    }
    return out;
  };
  auto release = [](std::uint32_t* p) {
    if (p != nullptr) {
      std::uint32_t* piVar1 = p + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        using VFn = void (__cdecl*)(int);
        VFn fn = reinterpret_cast<VFn>(*p);
        fn(1);
      }
    }
  };
  std::uint32_t* local_18 = nullptr;
  std::uint32_t* local_14 = nullptr;
  std::uint32_t* puStack_10 = nullptr;
  std::uint32_t* puStack_c = nullptr;
  std::uint32_t* puStack_4 = nullptr;
  {
    std::uint32_t iVar2 = self[0xec / 4];
    if ((iVar2 != 0) && (*reinterpret_cast<int*>(static_cast<std::uintptr_t>(iVar2) + 0x24) != 0)) {
      local_18 = call74(iVar2);
      if (local_18 != nullptr) {
        std::uint32_t c = local_18[1];
        local_18[1] = c + -1;
        if (c + -1 == 0) release(local_18);
      }
    }
  }
  {
    std::uint32_t iVar2 = self[0xe8 / 4];
    if ((iVar2 != 0) && (*reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iVar2) + 0x24) != 0)) {
      local_14 = call74(iVar2);
      if (local_14 != nullptr && (local_14[1] + -1 == 0)) release(local_14);
    }
  }
  {
    std::uint32_t iVar2 = self[0xf0 / 4];
    if ((iVar2 != 0) && (*reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iVar2) + 0x24) != 0)) {
      puStack_10 = call74(iVar2);
      if (puStack_10 != nullptr && (puStack_10[1] + -1 == 0)) release(puStack_10);
    }
  }
  {
    std::uint32_t iVar2 = self[0xf4 / 4];
    if ((iVar2 != 0) && (*reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iVar2) + 0x24) != 0)) {
      puStack_c = call74(iVar2);
      if (puStack_c != nullptr && (puStack_c[1] + -1 == 0)) release(puStack_c);
    }
  }
  if (self[0xcc / 4] != 0) FUN_00519a90();
  if (self[200 / 4] != 0) FUN_00519a90();
  if (self[0xd0 / 4] != 0) FUN_00519a90();
  auto freeSlot = [&](int offset) {
    std::uint32_t* puVar3 = reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(self[offset / 4]));
    if (puVar3 != nullptr) {
      release(puVar3);
      self[offset / 4] = 0;
    }
  };
  freeSlot(0xec);
  freeSlot(0xe8);
  freeSlot(0xf0);
  freeSlot(0xf4);
  self[0xcc / 4] = 0;
  self[200 / 4] = 0;
  self[0xd0 / 4] = 0;
  self[0xc4 / 4] = 0;
  if (self[0xac / 4] != 0) {
    puStack_4 = reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(self[0xb8 / 4]));
    int iStack_20 = 0;
    float fVar6 = static_cast<float>(static_cast<int>(reinterpret_cast<std::uintptr_t>(puStack_4)));
    std::uint32_t puStack_4u = reinterpret_cast<std::uint32_t>(puStack_4);
    if (static_cast<int>(puStack_4u) < 0) fVar6 = fVar6 + 4.2949673e+09f;
    if (0.0f < fVar6 * 0.125f + static_cast<float>(((puStack_4u & 7) != 0))) {
      do {
        std::uint32_t uStack_8 = self[0xbc / 4];
        int iStack_1c = 0;
        fVar6 = static_cast<float>(static_cast<int>(uStack_8));
        if (static_cast<int>(uStack_8) < 0) fVar6 = fVar6 + 4.2949673e+09f;
        if (0.0f < fVar6 * 0.125f + static_cast<float>(((uStack_8 & 7) != 0))) {
          do {
            std::uint32_t iVar2 = static_cast<std::uint32_t>(DAT_008cacac);
            if (self[0xb0 / 4] != 0) {
              std::uint32_t* puVar3 = reinterpret_cast<std::uint32_t*>(*reinterpret_cast<std::uintptr_t*>(static_cast<std::uintptr_t>(*reinterpret_cast<std::uintptr_t*>(static_cast<std::uintptr_t>(self[0xb0 / 4]) + iStack_20 * 4)) + iStack_1c * 4));
              if (puVar3 != nullptr) {
                puVar3[1] = puVar3[1] + 1;
                if ((*reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iVar2) + 0x14) < *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iVar2) + 4)) || (*reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iVar2) + 4) == 0)) {
                  using Maker = std::uint32_t* (__cdecl*)();
                  std::uint32_t vt2 = *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iVar2) + 8);
                  Maker maker = reinterpret_cast<Maker>(*reinterpret_cast<std::uint32_t*>(vt2 + 4));
                  std::uint32_t* puVar8 = maker();
                  std::uint32_t* puVar4 = reinterpret_cast<std::uint32_t*>(puVar8[2]);
                  if (puVar4 != puVar3) {
                    release(puVar4);
                    puVar8[2] = reinterpret_cast<std::uint32_t>(puVar3);
                    puVar3[1] = puVar3[1] + 1;
                  }
                  puVar8[1] = 0;
                  puVar8[0] = *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iVar2) + 0xc);
                  if (*reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(iVar2) + 0xc) == 0) {
                    *reinterpret_cast<std::uint32_t**>(static_cast<std::uintptr_t>(iVar2) + 0x10) = puVar8;
                  } else {
                    *reinterpret_cast<std::uint32_t**>(*reinterpret_cast<std::uintptr_t*>(static_cast<std::uintptr_t>(iVar2) + 0xc) + 4) = puVar8;
                  }
                  *reinterpret_cast<std::uint32_t**>(static_cast<std::uintptr_t>(iVar2) + 0xc) = puVar8;
                  *reinterpret_cast<int*>(static_cast<std::uintptr_t>(iVar2) + 0x14) = *reinterpret_cast<int*>(static_cast<std::uintptr_t>(iVar2) + 0x14) + 1;
                }
                release(puVar3);
                std::uint32_t* tmp2 = call74(*reinterpret_cast<std::uint32_t*>(*reinterpret_cast<std::uintptr_t*>(static_cast<std::uintptr_t>(self[0xb0 / 4]) + iStack_20 * 4) + iStack_1c * 4));
                puStack_4 = tmp2;
                if (puStack_4 != nullptr && (puStack_4[1] + -1 == 0)) release(puStack_4);
              }
              std::uint32_t iVar2b = *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(self[0xb0 / 4]) + iStack_20 * 4);
              std::uint32_t* puVar3b = reinterpret_cast<std::uint32_t*>(*reinterpret_cast<std::uintptr_t*>(iVar2b + iStack_1c * 4));
              if (puVar3b != nullptr) {
                release(puVar3b);
                *reinterpret_cast<std::uint32_t*>(iVar2b + iStack_1c * 4) = 0;
              }
              *(reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(iStack_1c) + *reinterpret_cast<std::uintptr_t*>(static_cast<std::uintptr_t>(self[0xb4 / 4]) + iStack_20 * 4))) = 0;
            }
            uStack_8 = self[0xbc / 4];
            iStack_1c = iStack_1c + 1;
            fVar6 = static_cast<float>(iStack_1c);
            if (iStack_1c < 0) fVar6 = fVar6 + 4.2949673e+09f;
            float fVar7 = static_cast<float>(static_cast<int>(uStack_8));
            if (static_cast<int>(uStack_8) < 0) fVar7 = fVar7 + 4.2949673e+09f;
          } while (fVar6 < fVar7 * 0.125f + static_cast<float>(((uStack_8 & 7) != 0)));
        }
        if (self[0xb0 / 4] != 0) {
          std::uint32_t iVar2b = *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(self[0xb0 / 4]) + iStack_20 * 4);
          if (iVar2b != 0) {
            int iStack_1c2 = *reinterpret_cast<int*>(iVar2b + -4);
            std::uint32_t iVar9 = iVar2b + iStack_1c2 * 4;
            if (iStack_1c2 + -1 >= 0) {
              do {
                std::uint32_t* puVar3c = reinterpret_cast<std::uint32_t*>(*reinterpret_cast<std::uintptr_t*>(iVar9 + -4));
                iVar9 = iVar9 + -4;
                release(puVar3c);
                iStack_1c2 = iStack_1c2 + -1;
              } while (iStack_1c2 != 0);
            }
            ::operator delete(reinterpret_cast<void*>(iVar2b + -4));
            *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(self[0xb0 / 4]) + iStack_20 * 4) = 0;
          }
          void* pvVar5 = reinterpret_cast<void*>(*reinterpret_cast<std::uintptr_t*>(static_cast<std::uintptr_t>(self[0xb4 / 4]) + iStack_20 * 4));
          if (pvVar5 != nullptr) {
            ::operator delete(pvVar5);
            *reinterpret_cast<std::uint32_t*>(static_cast<std::uintptr_t>(self[0xb4 / 4]) + iStack_20 * 4) = 0;
          }
        }
        std::uint32_t uStack_8b = self[0xb8 / 4];
        iStack_20 = iStack_20 + 1;
        fVar6 = static_cast<float>(iStack_20);
        if (iStack_20 < 0) fVar6 = fVar6 + 4.2949673e+09f;
        float fVar7 = static_cast<float>(static_cast<int>(uStack_8b));
        if (static_cast<int>(uStack_8b) < 0) fVar7 = fVar7 + 4.2949673e+09f;
      } while (fVar6 < fVar7 * 0.125f + static_cast<float>(((uStack_8b & 7) != 0)));
    }
    if (self[0xb4 / 4] != 0) {
      ::operator delete(reinterpret_cast<void*>(static_cast<std::uintptr_t>(self[0xb4 / 4])));
      self[0xb4 / 4] = 0;
    }
    if (self[0xb0 / 4] != 0) {
      ::operator delete(reinterpret_cast<void*>(static_cast<std::uintptr_t>(self[0xb0 / 4])));
      self[0xb0 / 4] = 0;
    }
    if (self[4 / 4] != 0) {
      puStack_4 = call74(self[0xac / 4]);
      if (puStack_c != nullptr && (puStack_c[1] + -1 == 0)) release(puStack_c);
      freeSlot(0xac);
    }
  }
}
