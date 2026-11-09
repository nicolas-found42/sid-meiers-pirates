#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cstdio>
#include <windows.h>

extern void* thunk_FUN_00533c78(std::size_t n);
extern void operator_delete__(void* p);
extern uint32_t FUN_005dbd70();
extern void FUN_00513ce0(uint32_t param_1);
extern uint32_t FUN_00540680(int p);
extern uint32_t FUN_00547d40(const char* s);
extern void FUN_00538630(int p);
extern void FUN_005460e0(void* p);
extern void FUN_00545cc0();
extern void FUN_00545d20();
extern uint32_t FUN_00545600();
extern int FUN_00545630();
extern uint32_t FUN_00540860(int* p);
extern uint32_t FUN_005404c0(int p);
extern char FUN_00538360(uint32_t p);

// 0x540460 — delete old string at +0xc, assign new via alloc+copy or null
void FUN_540460(void* self, char* param_1)
{
  char cVar1;
  char* pcVar2;
  operator_delete__(*reinterpret_cast<void**>(static_cast<char*>(self) + 0xc));
  if (param_1 == nullptr) {
    *reinterpret_cast<void**>(static_cast<char*>(self) + 0xc) = nullptr;
    return;
  }
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2++;
  } while (cVar1 != '\0');
  std::size_t len = static_cast<std::size_t>(pcVar2 - param_1);
  pcVar2 = static_cast<char*>(thunk_FUN_00533c78(len));
  *reinterpret_cast<char**>(static_cast<char*>(self) + 0xc) = pcVar2;
  do {
    cVar1 = *param_1;
    param_1++;
    *pcVar2 = cVar1;
    pcVar2++;
  } while (cVar1 != '\0');
}

// 0x5404c0 — grow/realloc array of DWORDs at +0x14/+0x18, capacity at +0x1c
uint32_t FUN_5404c0(void* self, int param_1)
{
  if (param_1 == 0) return 0;
  int iVar4 = *reinterpret_cast<int*>(static_cast<char*>(self) + 0x1c);
  *reinterpret_cast<int*>(static_cast<char*>(self) + 0x1c) = param_1;
  if (iVar4 == 0) {
    uint32_t uVar1 = reinterpret_cast<uint32_t>(thunk_FUN_00533c78(static_cast<std::size_t>(param_1) << 2));
    *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x14) = uVar1;
    *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18) = 0;
    return 1;
  }
  uint32_t* puVar2 = static_cast<uint32_t*>(thunk_FUN_00533c78(static_cast<std::size_t>(param_1) * 4));
  uint32_t* puVar5 = *reinterpret_cast<uint32_t**>(static_cast<char*>(self) + 0x14);
  uint32_t* puVar6 = puVar2;
  for (uint32_t uVar3 = *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18) & 0x3fffffff; uVar3 != 0; uVar3--) {
    *puVar6 = *puVar5;
    puVar5++;
    puVar6++;
  }
  for (int i = 0; i != 0; i--) {
    *reinterpret_cast<uint8_t*>(puVar6) = *reinterpret_cast<uint8_t*>(puVar5);
    puVar5 = reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(puVar5) + 1);
    puVar6 = reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(puVar6) + 1);
  }
  operator_delete__(*reinterpret_cast<void**>(static_cast<char*>(self) + 0x14));
  *reinterpret_cast<uint32_t**>(static_cast<char*>(self) + 0x14) = puVar2;
  return 1;
}

// 0x540540 — binary search over ordered byte strings; cmp via strncmp-like inline
uint32_t FUN_540540(void* self, const uint8_t* param_1)
{
  int iVar5 = 0;
  int iVar6 = *reinterpret_cast<int*>(static_cast<char*>(self) + 0x18) - 1;
  if (param_1 == nullptr) return 0;
  if (iVar6 < 0) return 0;
  for (;;) {
    int iVar7 = (iVar5 + iVar6) >> 1;
    const uint8_t* pbVar2 = reinterpret_cast<const uint8_t*>(FUN_005dbd70());
    const uint8_t* pbVar4 = param_1;
    int iVar3;
    for (;;) {
      uint8_t bVar1 = *pbVar4;
      bool bVar8 = bVar1 < *pbVar2;
      if (bVar1 != *pbVar2) {
        iVar3 = static_cast<int>(1 - static_cast<uint32_t>(bVar8)) - static_cast<int>(bVar8 != 0);
        break;
      }
      if (bVar1 == 0) { iVar3 = 0; break; }
      uint8_t b2 = pbVar4[1];
      bool b8 = b2 < pbVar2[1];
      if (b2 != pbVar2[1]) {
        iVar3 = static_cast<int>(1 - static_cast<uint32_t>(b8)) - static_cast<int>(b8 != 0);
        break;
      }
      pbVar4 += 2;
      pbVar2 += 2;
    }
    if (iVar3 == 0) {
      return *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x14) + iVar7 * 4);
    }
    if (iVar3 < 1) iVar6 = iVar7 - 1; else iVar5 = iVar7 + 1;
    if (iVar6 < iVar5) return 0;
  }
}

// 0x5405e0 — notify single +0x10 and each array entry +0x14 via vtable+0x28
void FUN_5405e0(void* self, uint32_t param_1)
{
  FUN_00513ce0(param_1);
  if (*reinterpret_cast<void**>(static_cast<char*>(self) + 0x10) != nullptr) {
    void* v = *reinterpret_cast<void**>(static_cast<char*>(self) + 0x10);
    void* vt = *static_cast<void**>(v);
    auto fn = *reinterpret_cast<void(**)(void*, uint32_t)>(static_cast<char*>(vt) + 0x28);
    fn(v, param_1);
  }
  uint32_t uVar1 = 0;
  if (*reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18) != 0) {
    do {
      void* v = *reinterpret_cast<void**>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x14) + uVar1 * 4);
      void* vt = *static_cast<void**>(v);
      auto fn = *reinterpret_cast<void(**)(void*, uint32_t)>(static_cast<char*>(vt) + 0x28);
      fn(v, param_1);
      uVar1++;
    } while (uVar1 < *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18));
  }
}

// 0x540620 — remove index, dec refcount, shift array tail, clear last slot
void FUN_540620(void* self, uint32_t param_1)
{
  if (param_1 < *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18)) {
    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x14) + param_1 * 4);
    if (puVar2 != nullptr) {
      int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
      *piVar1 = *piVar1 - 1;
      if (*piVar1 == 0) {
        auto fn = *reinterpret_cast<void(**)(void*, int)>(*puVar2);
        fn(reinterpret_cast<void*>(puVar2), 1);
      }
    }
    if (param_1 < static_cast<uint32_t>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x18) - 1)) {
      do {
        uint32_t* p = reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x14) + param_1 * 4);
        *p = p[1];
        param_1++;
      } while (param_1 < static_cast<uint32_t>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x18) - 1));
    }
    int iVar3 = *reinterpret_cast<int*>(static_cast<char*>(self) + 0x18) - 1;
    *reinterpret_cast<int*>(static_cast<char*>(self) + 0x18) = iVar3;
    *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x14) + iVar3 * 4) = 0;
  }
}
// 0x540680 — insert sorted at end, bubble-up swap, grow via 2*n+1
uint32_t FUN_540680(void* self, int param_1)
{
  if (param_1 == 0) return 0;
  *reinterpret_cast<int*>(reinterpret_cast<char*>(param_1) + 4) = *reinterpret_cast<int*>(reinterpret_cast<char*>(param_1) + 4) + 1;
  int iVar11 = *reinterpret_cast<int*>(static_cast<char*>(self) + 0x1c);
  if (iVar11 == 0) {
    *reinterpret_cast<int*>(static_cast<char*>(self) + 0x1c) = 1;
    *reinterpret_cast<int*>(static_cast<char*>(self) + 0x18) = 1;
    int* piVar5 = static_cast<int*>(thunk_FUN_00533c78(4));
    *reinterpret_cast<int**>(static_cast<char*>(self) + 0x14) = piVar5;
    *piVar5 = param_1;
    return 1;
  }
  if (*reinterpret_cast<int*>(static_cast<char*>(self) + 0x18) == iVar11) {
    iVar11 = iVar11 * 2 + 1;
    *reinterpret_cast<int*>(static_cast<char*>(self) + 0x1c) = iVar11;
    uint32_t* puVar6 = static_cast<uint32_t*>(thunk_FUN_00533c78(static_cast<std::size_t>(iVar11) * 4));
    uint32_t* puVar12 = *reinterpret_cast<uint32_t**>(static_cast<char*>(self) + 0x14);
    uint32_t* puVar13 = puVar6;
    for (uint32_t uVar10 = *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18) & 0x3fffffff; uVar10 != 0; uVar10--) {
      *puVar13 = *puVar12; puVar12++; puVar13++;
    }
    for (int i = 0; i != 0; i--) {
      *reinterpret_cast<uint8_t*>(puVar13) = *reinterpret_cast<uint8_t*>(puVar12);
      puVar12 = reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(puVar12) + 1);
      puVar13 = reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(puVar13) + 1);
    }
    operator_delete__(*reinterpret_cast<void**>(static_cast<char*>(self) + 0x14));
    *reinterpret_cast<uint32_t**>(static_cast<char*>(self) + 0x14) = puVar6;
  }
  *reinterpret_cast<int*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x14) + *reinterpret_cast<int*>(static_cast<char*>(self) + 0x18) * 4) = param_1;
  uint32_t uVar10 = static_cast<uint32_t>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x18)) + 1;
  *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18) = uVar10;
  if (uVar10 < *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x1c)) {
    do {
      *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x14) + uVar10 * 4) = 0;
      uVar10++;
    } while (uVar10 < *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x1c));
  }
  iVar11 = *reinterpret_cast<int*>(static_cast<char*>(self) + 0x18) - 1;
  for (;;) {
    if (iVar11 == 0) return 1;
    const uint8_t* pbVar7 = reinterpret_cast<const uint8_t*>(FUN_005dbd70());
    const uint8_t* pbVar8 = reinterpret_cast<const uint8_t*>(FUN_005dbd70());
    int iVar9;
    for (;;) {
      uint8_t bVar2 = *pbVar8;
      bool bVar14 = bVar2 < *pbVar7;
      if (bVar2 != *pbVar7) {
        iVar9 = static_cast<int>(1 - static_cast<uint32_t>(bVar14)) - static_cast<int>(bVar14 != 0);
        break;
      }
      if (bVar2 == 0) { iVar9 = 0; break; }
      uint8_t b2 = pbVar8[1];
      bool b14 = b2 < pbVar7[1];
      if (b2 != pbVar7[1]) {
        iVar9 = static_cast<int>(1 - static_cast<uint32_t>(b14)) - static_cast<int>(b14 != 0);
        break;
      }
      pbVar8 += 2; pbVar7 += 2;
    }
    if (iVar9 == 0) { FUN_540620(self, static_cast<uint32_t>(iVar11)); return 0; }
    if (iVar9 < 1) return 1;
    int iVar3 = *reinterpret_cast<int*>(static_cast<char*>(self) + 0x14);
    int iVar9b = iVar11 * 4;
    uint32_t uVar4 = *reinterpret_cast<uint32_t*>(iVar3 + -4 + iVar11 * 4);
    int iVar1 = iVar11 * 4;
    iVar11--;
    *reinterpret_cast<uint32_t*>(iVar3 + iVar1 - 4) = *reinterpret_cast<uint32_t*>(iVar3 + iVar9b);
    *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x14) + 4 + iVar11 * 4) = uVar4;
  }
}

// 0x5407d0 — if key matches FUN_005dbd70 string, insert via FUN_00540680
uint32_t FUN_5407d0(void* self, const uint8_t* param_1, int param_2)
{
  if (param_1 == nullptr) return 0;
  if (param_2 != 0) {
    if (FUN_005dbd70() == 0) {
      FUN_00547d40(reinterpret_cast<const char*>(param_1));
      return FUN_00540680(param_2);
    }
    const uint8_t* pbVar4 = reinterpret_cast<const uint8_t*>(FUN_005dbd70());
    const uint8_t* p = param_1;
    int cmp;
    for (;;) {
      uint8_t bVar1 = *p;
      bool bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) { cmp = static_cast<int>(1 - static_cast<uint32_t>(bVar5)) - static_cast<int>(bVar5 != 0); break; }
      if (bVar1 == 0) { cmp = 0; break; }
      uint8_t b2 = p[1];
      bool b5 = b2 < pbVar4[1];
      if (b2 != pbVar4[1]) { cmp = static_cast<int>(1 - static_cast<uint32_t>(b5)) - static_cast<int>(b5 != 0); break; }
      p += 2; pbVar4 += 2;
    }
    if (cmp == 0) return FUN_00540680(param_2);
  }
  return 0;
}

// 0x540860 — rename ExtraData prefix to ED%03d via formatted buffer, then insert
uint32_t FUN_540860(void* self, int* param_1)
{
  if (param_1 == nullptr) return 0;
  if (FUN_005dbd70() == 0) {
    auto fn = *reinterpret_cast<uint32_t*(**)(void*)>(*reinterpret_cast<void**>(*param_1) + 4);
    uint32_t* puVar3 = fn(reinterpret_cast<void*>(param_1));
    char* pcVar5 = reinterpret_cast<char*>(*puVar3);
    if (pcVar5 != nullptr) {
      char* pcVar4 = pcVar5;
      char cVar1;
      do { cVar1 = *pcVar4; pcVar4++; } while (cVar1 != '\0');
      if (pcVar4 != pcVar5 + 1) {
        char acStack_8[8];
        sprintf(acStack_8, "ED%03d", *reinterpret_cast<int*>(static_cast<char*>(self) + 0x18));
        char* pStr = strstr(pcVar5, "ExtraData");
        std::size_t _Count = 0;
        if (pcVar5 < pStr) _Count = static_cast<std::size_t>(pStr - pcVar5);
        char* p2 = acStack_8;
        do { cVar1 = *p2; p2++; } while (cVar1 != '\0');
        std::size_t total = static_cast<std::size_t>(p2 - acStack_8) + _Count + 1;
        char* pcVar4b = static_cast<char*>(thunk_FUN_00533c78(total));
        strncpy(pcVar4b, pcVar5, _Count);
        pcVar4b[_Count] = '\0';
        strcat(pcVar4b, acStack_8);
        FUN_00547d40(pcVar4b);
        operator_delete__(pcVar4b);
      }
    }
  }
  return FUN_00540680(reinterpret_cast<int>(param_1));
}

// 0x540970 — binary search; on match remove via FUN_00540620, return 1
uint32_t FUN_540970(void* self, const uint8_t* param_1)
{
  int iVar5 = 0;
  int iVar6 = *reinterpret_cast<int*>(static_cast<char*>(self) + 0x18) - 1;
  if (param_1 == nullptr || iVar6 < 0) return 0;
  for (;;) {
    int iVar7 = (iVar5 + iVar6) >> 1;
    const uint8_t* pbVar2 = reinterpret_cast<const uint8_t*>(FUN_005dbd70());
    const uint8_t* pbVar4 = param_1;
    int iVar3;
    for (;;) {
      uint8_t bVar1 = *pbVar4;
      bool bVar8 = bVar1 < *pbVar2;
      if (bVar1 != *pbVar2) { iVar3 = static_cast<int>(1 - static_cast<uint32_t>(bVar8)) - static_cast<int>(bVar8 != 0); break; }
      if (bVar1 == 0) { iVar3 = 0; break; }
      uint8_t b2 = pbVar4[1];
      bool b8 = b2 < pbVar2[1];
      if (b2 != pbVar2[1]) { iVar3 = static_cast<int>(1 - static_cast<uint32_t>(b8)) - static_cast<int>(b8 != 0); break; }
      pbVar4 += 2; pbVar2 += 2;
    }
    if (iVar3 == 0) { FUN_540620(self, static_cast<uint32_t>(iVar7)); return 1; }
    if (iVar3 < 1) iVar6 = iVar7 - 1; else iVar5 = iVar7 + 1;
    if (iVar6 < iVar5) return 0;
  }
}

// 0x540a10 — bounds-checked remove wrapper
uint32_t FUN_540a10(void* self, uint32_t param_1)
{
  if (param_1 < *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18)) {
    FUN_540620(self, param_1);
    return 1;
  }
  return 0;
}
// 0x540a30 — drain all elements via FUN_00540620, free array, zero fields
void FUN_540a30(void* self)
{
  int iVar1 = *reinterpret_cast<int*>(static_cast<char*>(self) + 0x18);
  while ((iVar1 = iVar1 - 1) >= 0) {
    FUN_540620(self, static_cast<uint32_t>(iVar1));
  }
  operator_delete__(*reinterpret_cast<void**>(static_cast<char*>(self) + 0x14));
  *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x14) = 0;
  *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x1c) = 0;
  *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18) = 0;
}

// 0x540a70 — refcounted assign to +0x10
void FUN_540a70(void* self, uint32_t* param_1)
{
  uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(static_cast<char*>(self) + 0x10);
  if (puVar2 != param_1) {
    if (puVar2 != nullptr) {
      int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
      *piVar1 = *piVar1 - 1;
      if (*piVar1 == 0) {
        auto fn = *reinterpret_cast<void(**)(void*, int)>(*puVar2);
        fn(reinterpret_cast<void*>(puVar2), 1);
      }
    }
    *reinterpret_cast<uint32_t**>(static_cast<char*>(self) + 0x10) = param_1;
    if (param_1 != nullptr) {
      param_1[1] = param_1[1] + 1;
    }
  }
}

// 0x540aa0 — delegate to 38630 + 460e0, branch on version < 0x500000b
void FUN_540aa0(void* self, int param_1)
{
  FUN_00538630(param_1);
  FUN_005460e0(static_cast<char*>(self) + 0xc);
  if (*reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_1) + 0x1c) < 0x500000b) {
    FUN_00545cc0();
    FUN_00545cc0();
    return;
  }
  FUN_00545d20();
  FUN_00545cc0();
}

// 0x540af0 — init single or array mode based on version, then assign +0x10
void FUN_540af0(void* self, int param_1)
{
  FUN_00513ce0(static_cast<uint32_t>(param_1));
  if (*reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_1) + 0x1c) < 0x500000b) {
    uint32_t uVar3 = FUN_00545600();
    *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x14) = uVar3;
  } else {
    int iVar4 = FUN_00545630();
    FUN_005404c0(iVar4);
    for (; iVar4 != 0; iVar4--) {
      uint32_t uVar3 = FUN_00545600();
      FUN_00540860(reinterpret_cast<int*>(uVar3));
    }
  }
  uint32_t* puVar5 = reinterpret_cast<uint32_t*>(FUN_00545600());
  uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(static_cast<char*>(self) + 0x10);
  if (puVar2 != puVar5) {
    if (puVar2 != nullptr) {
      int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
      *piVar1 = *piVar1 - 1;
      if (*piVar1 == 0) {
        auto fn = *reinterpret_cast<void(**)(void*, int)>(*puVar2);
        fn(reinterpret_cast<void*>(puVar2), 1);
      }
    }
    *reinterpret_cast<uint32_t**>(static_cast<char*>(self) + 0x10) = puVar5;
    if (puVar5 != nullptr) {
      puVar5[1] = puVar5[1] + 1;
    }
  }
}

// 0x540b70 — predicate via FUN_00538360, then notify array + single via +0x14
uint8_t FUN_540b70(void* self, uint32_t param_1)
{
  char cVar2 = FUN_00538360(param_1);
  if (cVar2 == '\0') return 0;
  uint32_t uVar3 = 0;
  if (*reinterpret_cast<int*>(static_cast<char*>(self) + 0x18) != 0) {
    do {
      int* piVar1 = *reinterpret_cast<int**>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x14) + uVar3 * 4);
      if (piVar1 != nullptr) {
        auto fn = *reinterpret_cast<void(**)(void*, uint32_t)>(*reinterpret_cast<char*>(*piVar1) + 0x14);
        fn(reinterpret_cast<void*>(piVar1), param_1);
      }
      uVar3++;
    } while (uVar3 < *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18));
  }
  if (*reinterpret_cast<int**>(static_cast<char*>(self) + 0x10) != nullptr) {
    auto fn = *reinterpret_cast<void(**)(void*, uint32_t)>(*reinterpret_cast<char*>(**reinterpret_cast<int**>(static_cast<char*>(self) + 0x10)) + 0x14);
    fn(*reinterpret_cast<void**>(static_cast<char*>(self) + 0x10), param_1);
  }
  return 1;
}
extern void FUN_00538430(int* p);
extern void FUN_00545950(uint32_t p);
extern void FUN_005383d0();
extern void FUN_00538400();
extern void FUN_00538410(int p1, uint32_t p2);
extern uint8_t DAT_007275d4;
extern char DAT_007179d4;
extern void* PTR_FUN_006c11bc;
// 0x540bc0 — delegate init then broadcast via +0x2c to array and single
void FUN_540bc0(void* self, int* param_1)
{
  FUN_00538430(param_1);
  FUN_00545950(*reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0xc));
  uint32_t* puVar1 = reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18);
  auto fn1 = *reinterpret_cast<void(**)(void*, uint32_t*, int)>(*reinterpret_cast<char*>(*param_1 + 0x0) + 0x0);
  (void)fn1;
  // (**(code **)(*(int *)param_1[0x58] + 0xc))(puVar1,4);
  auto fnC = *reinterpret_cast<void(**)(void*, uint32_t*, int)>(*reinterpret_cast<char*>(*(reinterpret_cast<int*>(param_1) + 0x58)) + 0xc);
  fnC(reinterpret_cast<void*>(*(reinterpret_cast<int*>(param_1) + 0x58)), puVar1, 4);
  uint32_t uVar2 = 0;
  if (*puVar1 != 0) {
    do {
      auto fn2 = *reinterpret_cast<void(**)(void*, uint32_t)>(*reinterpret_cast<char*>(*param_1) + 0x2c);
      fn2(reinterpret_cast<void*>(param_1), *reinterpret_cast<uint32_t*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x14) + uVar2 * 4));
      uVar2++;
    } while (uVar2 < *puVar1);
  }
  {
    auto fn2 = *reinterpret_cast<void(**)(void*, uint32_t)>(*reinterpret_cast<char*>(*param_1) + 0x2c);
    fn2(reinterpret_cast<void*>(param_1), *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x10));
  }
}

// 0x540c20 — refcounted assign to +0x38
void FUN_540c20(void* self, uint32_t* param_1)
{
  uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(static_cast<char*>(self) + 0x38);
  if (puVar2 != param_1) {
    if (puVar2 != nullptr) {
      int* piVar1 = reinterpret_cast<int*>(puVar2 + 1);
      *piVar1 = *piVar1 - 1;
      if (*piVar1 == 0) {
        auto fn = *reinterpret_cast<void(**)(void*, int)>(*puVar2);
        fn(reinterpret_cast<void*>(puVar2), 1);
      }
    }
    *reinterpret_cast<uint32_t**>(static_cast<char*>(self) + 0x38) = param_1;
    if (param_1 != nullptr) param_1[1] = param_1[1] + 1;
  }
}

// 0x540c50 — ctor: set vtable, zero +0x0c..+0x1c words 3-7
void FUN_540c50(void* self)
{
  FUN_005383d0();
  uint32_t* p = static_cast<uint32_t*>(self);
  p[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c11bc);
  p[4] = 0;
  p[3] = 0;
  p[5] = 0;
  p[7] = 0;
  p[6] = 0;
}

// 0x540c90 — dtor: drain array, release +0x10, call base dtor
void FUN_540c90(void* self)
{
  uint32_t* in_ECX = static_cast<uint32_t*>(self);
  in_ECX[0] = reinterpret_cast<uint32_t>(&PTR_FUN_006c11bc);
  operator_delete__(reinterpret_cast<void*>(in_ECX[3]));
  int iVar2 = static_cast<int>(in_ECX[6]);
  while ((iVar2 = iVar2 - 1) >= 0) {
    FUN_540620(self, static_cast<uint32_t>(iVar2));
  }
  operator_delete__(reinterpret_cast<void*>(in_ECX[5]));
  in_ECX[5] = 0;
  in_ECX[7] = 0;
  in_ECX[6] = 0;
  uint32_t* puVar3 = reinterpret_cast<uint32_t*>(in_ECX[4]);
  if (puVar3 != nullptr) {
    int* piVar1 = reinterpret_cast<int*>(puVar3 + 1);
    *piVar1 = *piVar1 - 1;
    if (*piVar1 == 0) {
      auto fn = *reinterpret_cast<void(**)(void*, int)>(*puVar3);
      fn(reinterpret_cast<void*>(puVar3), 1);
    }
  }
  FUN_00538400();
}

// 0x540cf0 — string mode DAT-based, then broadcast via +8 and assign +0x10
void FUN_540cf0(void* self, int param_1, uint32_t param_2)
{
  FUN_00538410(param_1, param_2);
  if (DAT_007275d4 == 1) {
    FUN_540460(self, reinterpret_cast<char*>(*reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0xc)));
  } else if (DAT_007275d4 == 2) {
    char* pcVar4 = *reinterpret_cast<char**>(static_cast<char*>(self) + 0xc);
    if (pcVar4 != nullptr) {
      char* pcVar8 = pcVar4 + 1;
      char cVar2;
      char* p = pcVar4;
      do { cVar2 = *p; p++; } while (cVar2 != '\0');
      std::size_t sz = static_cast<std::size_t>(p + 2 - static_cast<int>(reinterpret_cast<intptr_t>(pcVar8)));
      char* pcVar5 = static_cast<char*>(thunk_FUN_00533c78(sz));
      char* pcVar9 = pcVar5;
      char* src = *reinterpret_cast<char**>(static_cast<char*>(self) + 0xc);
      char* s = src;
      do { cVar2 = *s; s++; *pcVar9 = cVar2; pcVar9++; } while (cVar2 != '\0');
      pcVar5[sz - 2] = DAT_007179d4;
      pcVar5[sz - 1] = '\0';
      FUN_540460(self, pcVar5);
      operator_delete__(pcVar5);
    }
  }
  uint32_t uVar10 = 0;
  if (*reinterpret_cast<int*>(static_cast<char*>(self) + 0x18) != 0) {
    do {
      void* target = *reinterpret_cast<void**>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x14) + uVar10 * 4);
      auto fn = *reinterpret_cast<uint32_t(**)(void*, uint32_t)>(*reinterpret_cast<char*>(*static_cast<void**>(target)) + 8);
      uint32_t uVar6 = fn(target, param_2);
      FUN_00540860(reinterpret_cast<int*>(uVar6));
      uVar10++;
    } while (uVar10 < *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x18));
  }
  if (*reinterpret_cast<int**>(static_cast<char*>(self) + 0x10) != nullptr) {
    void* single = *reinterpret_cast<void**>(static_cast<char*>(self) + 0x10);
    auto fn = *reinterpret_cast<uint32_t*(**)(void*, uint32_t)>(*reinterpret_cast<char*>(*static_cast<void**>(single)) + 8);
    uint32_t* puVar7 = fn(single, param_2);
    uint32_t* puVar3 = *reinterpret_cast<uint32_t**>(reinterpret_cast<char*>(param_1) + 0x10);
    if (puVar3 != puVar7) {
      if (puVar3 != nullptr) {
        int* piVar1 = reinterpret_cast<int*>(puVar3 + 1);
        *piVar1 = *piVar1 - 1;
        if (*piVar1 == 0) {
          auto fn2 = *reinterpret_cast<void(**)(void*, int)>(*puVar3);
          fn2(reinterpret_cast<void*>(puVar3), 1);
        }
      }
      *reinterpret_cast<uint32_t**>(reinterpret_cast<char*>(param_1) + 0x10) = puVar7;
      if (puVar7 != nullptr) puVar7[1] = puVar7[1] + 1;
    }
  }
}
