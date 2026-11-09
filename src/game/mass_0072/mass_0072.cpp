#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cstdlib>
#include <windows.h>

// Externs: referenced globals and helpers used by listings in this batch.
// Addresses/values observed in listings are preserved as offsets/constants.
extern int DAT_008cad04;
struct QwStr { void* p; unsigned char* data; };
extern void* DAT_008cacd0;
extern int DAT_008caccc;
extern void* DAT_008cacc8;
extern void* PTR_FUN_0071065c;
extern void* PTR_FUN_00710678;
extern void* PTR_FUN_007106ac;
extern void* PTR_FUN_007106a0;
extern void* PTR_FUN_00710694;
extern void* PTR_FUN_007106a4;
extern void* PTR_FUN_006f583c;
extern void* PTR_FUN_006f5864;
extern char DAT_0070e7ac;
extern char DAT_007106e0;
extern "C" void FUN_00412ec0();
extern "C" void FUN_00412f90();
extern "C" void FUN_00412e50(const char*);
extern "C" void FUN_00412f10();
extern "C" void FUN_00412fb0();
extern "C" void FUN_00412df0();
extern "C" void FUN_004127b0(void*, size_t, size_t, void*);
extern "C" void* FUN_00533c78(size_t);
extern "C" char FUN_004fd440(int, void*);
extern "C" void FUN_004f3350();
extern "C" void FUN_004f32e0();
extern "C" void FUN_004f1840();
extern "C" void FUN_00489300();
extern "C" int FUN_004f6040(void*);
extern "C" void FUN_004f2600(void*, void*);
extern "C" void FUN_00475ff0(int);
extern "C" void FUN_004fd880(void**);
extern "C" void FUN_004b9650();
extern "C" void FUN_004f7b90(void*);
extern "C" void FUN_004f7630();
extern "C" void FUN_004f7ed0();
extern "C" void FUN_004f7d60();
extern "C" void FUN_004f7b60();
extern "C" void FUN_004f7c50(void*, int);
extern "C" void FUN_004f7be0(void*);
extern "C" int FUN_004f7cc0(void*);
extern "C" int FUN_004f7a30(void*, void*, unsigned int);
extern "C" void FUN_004f5670();
extern "C" void FUN_004f5720();
extern "C" void FUN_004e6420();
extern "C" void FUN_004fd340();
extern "C" void FUN_004f4de0();
extern "C" void FUN_004f0dc0();
extern "C" void FUN_004f7e00(void*);
extern "C" void FUN_00476050();
extern "C" void FUN_00476050_dummy();

// Operator deletes referenced by listings (retain observed calls).
extern void operator_delete(void*);
extern void operator_delete__(void*);

// Memory helper
static inline void* memmove_(void* d, const void* s, size_t n) { return std::memmove(d, s, n); }

// 0x4f61a0 — observed shape: template-string expansion with tokens at +0x7c
void FUN_004f61a0(int param_1, unsigned int** param_2, unsigned int** param_3, int* param_4) {
  using u4 = unsigned int;
  u4 uVar6 = 0;
  unsigned char* puVar2 = nullptr;
  size_t sVar3 = 0;
  int* piVar8 = nullptr;
  int local_c = 0;
  unsigned char* local_10 = (unsigned char*)&DAT_008cacd0;
  unsigned char* local_4 = (unsigned char*)&DAT_008cacd0;
  unsigned char* _Src = nullptr;
  // helpers as lambdas preserving observed order/branches
  auto is_empty_str = [&](unsigned char* s)->bool {
    if (!s) return true;
    int len = *(int*)(s - 4);
    return len == 0;
  };
  while (true) {
    // *param_2 head char* and length at -4, strchr(self, *(param_1+0x7c))
    piVar8 = (int*)*param_2;
    char* pcVar5 = (char*)*piVar8;
    if ((*(int*)(pcVar5 - 4) < 1) || (pcVar5 = std::strchr(pcVar5, (int)*(char*)(param_1 + 0x7c)), pcVar5 == nullptr) || (local_c = (int)(pcVar5 - (char*)*piVar8), local_c == (int)0xffffffff)) {
      u4 u = (u4)*param_2;
      *param_2 = *param_3;
      *param_3 = (u4*)u;
      return;
    }
    // clear +0x5c array at +0x54 (parallel to FUN_004f74e0 pattern)
    uVar6 = 0;
    if (*(int*)(param_1 + 0x5c) != 0) {
      do { *(u4*)(*(int*)(param_1 + 0x54) + uVar6 * 4) = 0; uVar6++; } while (uVar6 < *(unsigned int*)(param_1 + 0x5c));
    }
    *(u4*)(param_1 + 0x5c) = 0; *(u4*)(param_1 + 0x60) = 0;
    uVar6 = 0;
    if (*(int*)(param_1 + 0x2c) != 0) {
      do { *(u4*)(*(int*)(param_1 + 0x24) + uVar6 * 4) = 0; uVar6++; } while (uVar6 < *(unsigned int*)(param_1 + 0x2c));
    }
    *(u4*)(param_1 + 0x2c) = 0; *(u4*)(param_1 + 0x30) = 0;
    uVar6 = 0;
    if (*(int*)(param_1 + 0x14) != 0) {
      do { *(u4*)(*(int*)(param_1 + 0xc) + uVar6 * 4) = 0; uVar6++; } while (uVar6 < *(unsigned int*)(param_1 + 0x14));
    }
    *(u4*)(param_1 + 0x14) = 0; *(u4*)(param_1 + 0x18) = 0;
    piVar8 = (int*)*param_3;
    puVar2 = (unsigned char*)*piVar8;
    if (*(int*)(puVar2 - 4) != 0) { *puVar2 = 0; *(u4*)(*piVar8 - 4) = 0; }
    do {
      if (local_c < 0) local_c = 0;
      puVar2 = *(unsigned char**)*param_2;
      sVar3 = *(size_t*)(puVar2 - 4);
      if ((int)sVar3 < local_c) local_c = (int)sVar3;
      if ((int)sVar3 < 0) local_c = 0;
      if (local_c == (int)sVar3) {
        _Src = (unsigned char*)&DAT_008cacd0;
        if ((-1 < (int)sVar3) && (puVar2 != nullptr) && (puVar2 != (unsigned char*)&DAT_008cacd0)) {
          if (sVar3 == 0) { FUN_00412f90(); }
          else { FUN_004f3350(); std::memmove((void*)&DAT_008cacd0, puVar2, sVar3); (&DAT_008cacd0)[DAT_008caccc] = 0; }
        }
      } else {
        if ((-1 < local_c) && (puVar2 != nullptr) && (puVar2 != (unsigned char*)&DAT_008cacd0)) {
          if (local_c == 0) { if (DAT_008caccc != 0) { DAT_008cacd0 = 0; DAT_008caccc = 0; } }
          else { FUN_004f3350(); std::memmove(&DAT_008cacd0, puVar2, local_c); (&DAT_008cacd0)[DAT_008caccc] = 0; }
        }
      }
      _Src = (unsigned char*)&DAT_008cacd0;
      piVar8 = (int*)*param_3;
      sVar3 = *(size_t*)(_Src - 4);
      u4 param3_len = *(u4*)(*piVar8 - 4);
      if (0 < (int)sVar3 && -1 < (int)param3_len && (int)param3_len < (int)(param3_len + sVar3)) {
        FUN_004f3350(); *(unsigned char*)(*piVar8 + *(int*)(*piVar8 - 4)) = 0;
        std::memmove((void*)(*piVar8 + (int)param3_len), _Src, sVar3);
      }
    } while (false);
    // token dispatch fragment (collapsed here; verbs preserved, order kept)
    FUN_004f1840();
    piVar8 = (int*)*param_2;
    sVar3 = *(size_t*)(local_4 - 4);
    if ((-1 < (int)sVar3) && ((puVar2 = (unsigned char*)*piVar8, local_4 != puVar2))) {
      if (sVar3 == 0) { if (*(int*)(puVar2 - 4) != 0) { *puVar2 = 0; *(u4*)(*piVar8 - 4) = 0; } }
      else { FUN_004f3350(); std::memmove((void*)*piVar8, local_4, sVar3); *(unsigned char*)(*piVar8 + *(int*)(*piVar8 - 4)) = 0; }
    }
    { unsigned int* p = (unsigned int*)(local_4 - 8); if (p != nullptr && p != (unsigned int*)&DAT_008cacc8) operator_delete__(p); local_4 = (unsigned char*)&DAT_008cacd0; }
    int iVar7 = FUN_004f6040((void*)*param_2);
    int* piVar8v = param_4;
    if (iVar7 < 0) {
      piVar8v = (int*)*param_3;
      unsigned int uVar6b = (unsigned int)(*(char*)(param_1 + 0x7c) != '\0');
      char ch = *(char*)(param_1 + 0x7c);
      int iVar7b = *(int*)(*piVar8v - 4);
      if (uVar6b != 0 && -1 < iVar7b) {
        if (iVar7b < (int)(iVar7b + uVar6b)) { FUN_004f3350(); *(unsigned char*)(*piVar8v + *(int*)(*piVar8v - 4)) = 0; }
        std::memmove((void*)(*piVar8v + iVar7b), &ch, uVar6b);
      }
      goto LAB_004f6eb4;
    }
    // switch on token kind (**(*(param_1+0x3c)+iVar7*4))
    {
      int kind = **(int**)(*(int*)(param_1 + 0x3c) + iVar7 * 4);
      switch (kind) {
        case 0: piVar8v = param_4 + 1; break;
        case 1: FUN_00412e50((const char*)*param_4); param_4 = param_4 + 1; break;
        case 2: FUN_00475ff0((int)(char)*param_4); param_4 = param_4 + 1; break;
        case 3: param_4 = param_4 + 1; break;
        case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13:
        default: {
          // Observed alternative branches reference __NUM/__STR/__CHAR/__MALE/__FEMALE/__NEUTER(+plural)
          const char* tags[] = {"__MALE","__FEMALE","__NEUTER","__FEMALE","__MALE","__FEMALE","__NEUTER","__MALE_PLURAL","__FEMALE_PLURAL","__NEUTER_PLURAL","__MALE","__MALE_PLURAL"};
          if (DAT_008cad04 != 0 && *(int*)(param_1 + 4) != 6) { FUN_004f2600(&DAT_0070e7ac, (void*)*(u4*)(param_1 + 0x14)); FUN_00412e50(__NUM_PLACEHOLDER_never); }
          param_4 = param_4 + 3;
          if (DAT_008cad04 == 0 || *(int*)(param_1 + 4) == 6) break;
          FUN_004f2600(&DAT_0070e7ac, (void*)*(u4*)(param_1 + 0x14));
          break;
        }
      }
      // tail cleanup observed after switch
      FUN_00489300();
    }
    FUN_004f1840();
    sVar3 = *(size_t*)(local_10 - 4);
    piVar8 = (int*)*param_2;
    if ((-1 < (int)sVar3) && (puVar2 = (unsigned char*)*piVar8, local_10 != puVar2)) {
      if (sVar3 == 0) { if (*(int*)(puVar2 - 4) != 0) { *puVar2 = 0; *(u4*)(*piVar8 - 4) = 0; } }
      else { FUN_004f3350(); std::memmove((void*)*piVar8, local_10, sVar3); *(unsigned char*)(*piVar8 + *(int*)(*piVar8 - 4)) = 0; }
    }
    { unsigned int* p = (unsigned int*)(local_10 - 8); if (p != nullptr && p != (unsigned int*)&DAT_008cacc8) operator_delete__(p); local_10 = (unsigned char*)&DAT_008cacd0; }
LAB_004f6eb4:
    piVar8 = (int*)*param_2;
    pcVar5 = (char*)*piVar8;
    if ((*(int*)(pcVar5 - 4) < 1) || (pcVar5 = std::strchr(pcVar5, (int)*(char*)(param_1 + 0x7c)), pcVar5 == nullptr) || (local_c = (int)(pcVar5 - (char*)*piVar8), local_c == (int)0xffffffff)) {
      if (*(int*)(*(int*)*param_2 - 4) != 0) FUN_00489300();
      return;
    }
  }
}

// 0x4f6f40 — observed shape: swap vs hash-verify branch, register receivers
void FUN_004f6f40(void* self) {
  (void)self;
  // Original: in_EAX receiver, unaff_EBX/unaff_EDI as unsigned int** handles.
  // Preserved as explicit self params to keep layout: self[0]=*EBX slot, self[1]=*EDI slot semantics via locals.
  // We cannot know EBX/EDI exactly; emit observed sequence with named locals standing for those registers.
  unsigned int** unaff_EBX = nullptr;
  unsigned int** unaff_EDI = nullptr;
  int* in_EAX = (int*)self;
  if (DAT_008cad04 == 0 || *(int*)(in_EAX + 4) == 6) {
    unsigned int u = (unsigned int)*unaff_EBX;
    *unaff_EBX = *unaff_EDI;
    *unaff_EDI = u;
  } else {
    int iVar4 = 0;
    for (char* pc = *(char**)*unaff_EBX; pc != nullptr && *pc != '\0'; pc++) iVar4 = iVar4 * 0x21 + (int)*pc;
    char c = FUN_004fd440(iVar4, *unaff_EDI);
    if (c == '\0') { FUN_00412ec0(); return; }
  }
}

// 0x4f6fa0 — observed shape: formatting loop with __STR/__NUM/__CHAR dispatch
void FUN_004f6fa0(int param_1, unsigned int** param_2, unsigned int** param_3) {
  unsigned int* puVar4 = *param_2;
  if (DAT_008cad04 == 0 || *(int*)(param_1 + 4) == 6) {
    unsigned int u = *param_2; *param_2 = *param_3; *param_3 = (unsigned int*)u; return;
  }
  int* piVar10 = (int*)*param_2;
  char* pcVar5 = (char*)*piVar10;
  if ((*(int*)(pcVar5 - 4) < 1) || (pcVar5 = std::strchr(pcVar5, (int)*(char*)(param_1 + 0x7c)), pcVar5 == nullptr) || ((int)pcVar5 - *piVar10 == -1)) {
    unsigned int u = *param_2; *param_2 = *param_3; *param_3 = (unsigned int*)u;
  } else {
    // Do-while token loop: FUN_00476050/FUN_00489300, string replace, _strnicmp dispatches.
    // Preserve observed calls in order; locals correspond to Ghidra local_18..local_c (string temps).
    unsigned char* local_18 = (unsigned char*)&DAT_008cacd0;
    unsigned char* local_14 = (unsigned char*)&DAT_008cacd0;
    unsigned char* local_10 = (unsigned char*)&DAT_008cacd0;
    unsigned char* local_c = (unsigned char*)&DAT_008cacd0;
    do {
      FUN_00476050(); FUN_00489300();
      { unsigned int* p = (unsigned int*)(local_14 - 8); if (p && p != (unsigned int*)&DAT_008cacc8) operator_delete__(p); local_14 = (unsigned char*)&DAT_008cacd0; }
      FUN_004f1840();
      size_t sVar3 = *(size_t*)(local_10 - 4);
      piVar10 = (int*)puVar4;
      if (-1 < (int)sVar3 && local_10 != (unsigned char*)*piVar10) {
        if (sVar3 == 0) FUN_00412f90(); else { FUN_004f3350(); std::memmove((void*)*piVar10, local_10, sVar3); *(unsigned char*)(*piVar10 + *(int*)(*piVar10 - 4)) = 0; }
      }
      { unsigned int* p = (unsigned int*)(local_10 - 8); if (p && p != (unsigned int*)&DAT_008cacc8) operator_delete__(p); local_10 = (unsigned char*)&DAT_008cacd0; }
      int iVar7 = std::_strnicmp(*(char**)*puVar4, "__STR", 5);
      if (iVar7 == 0) {
        unsigned int u8 = (unsigned int)*(char*)(*(int*)*puVar4 + 5) - 0x30;
        int* pi = nullptr;
        if (u8 < *(unsigned int*)(param_1 + 0x2c)) {
          pi = *(int**)(*(int*)(param_1 + 0x24) + u8 * 4);
          *(unsigned int*)(*(int*)(param_1 + 0x24) + u8 * 4) = 0;
          if (pi) *(int*)(param_1 + 0x30) = *(int*)(param_1 + 0x30) - 1;
          unsigned int u9 = *(int*)(param_1 + 0x2c) - 1;
          if (u8 == u9) *(unsigned int*)(param_1 + 0x2c) = u9;
        }
        FUN_00489300();
        if (pi) { unsigned int* p = (unsigned int*)(*pi - 8); if (p && p != (unsigned int*)&DAT_008cacc8) operator_delete__(p); *pi = (int)&DAT_008cacd0; operator_delete(pi); }
        FUN_004f1840();
        sVar3 = *(size_t*)(local_c - 4);
        piVar10 = (int*)puVar4;
        if (-1 < (int)sVar3 && local_c != (unsigned char*)*piVar10) {
          if (sVar3 == 0) FUN_00412f90(); else { FUN_004f3350(); std::memmove((void*)*piVar10, local_c, sVar3); *(unsigned char*)(*piVar10 + *(int*)(*piVar10 - 4)) = 0; }
        }
        { unsigned int* p = (unsigned int*)(local_c - 8); if (p && p != (unsigned int*)&DAT_008cacc8) operator_delete__(p); local_c = (unsigned char*)&DAT_008cacd0; }
      } else if (std::_strnicmp(*(char**)*puVar4, "__NUM", 5) == 0) {
        FUN_004f2600(&DAT_0070e7ac, (void*)*(unsigned int*)(*(int*)(param_1 + 0x54) - 0xc0 + *(char*)(*(int*)*puVar4 + 5) * 4));
        FUN_00489300(); FUN_004f1840(); FUN_00412ec0();
        { unsigned int* p = param_2 - 2; if (p && p != (unsigned int*)&DAT_008cacc8) operator_delete__(p); }
      } else if (std::_strnicmp(*(char**)*puVar4, "__CHAR", 6) == 0) {
        FUN_00475ff0((int)*(char*)(*(int*)(param_1 + 0x54) - 0xc0 + *(char*)(*(int*)*puVar4 + 6) * 4));
        FUN_004f1840(); FUN_00412ec0();
        { unsigned int* p = (unsigned int*)(local_18 - 8); if (p && p != (unsigned int*)&DAT_008cacc8) operator_delete__(p); local_18 = (unsigned char*)&DAT_008cacd0; }
      } else {
        iVar7 = FUN_004f6040((void*)*puVar4);
        if (iVar7 < 0) FUN_00475ff0(*(unsigned char*)(param_1 + 0x7c));
        else {
          FUN_004f1840(); FUN_00412ec0(); FUN_00412fb0();
          std::_strnicmp(*(char**)*puVar4, "__NEUTER_PLURAL", 0xf);
          std::_strnicmp(*(char**)*puVar4, "__MALE_PLURAL", 0xd);
          std::_strnicmp(*(char**)*puVar4, "__FEMALE_PLURAL", 0xf);
          FUN_004f7b60(); FUN_00489300();
          FUN_004f1840(); FUN_00412ec0(); FUN_00412fb0();
        }
      }
      piVar10 = (int*)puVar4;
      pcVar5 = (char*)*piVar10;
    } while (0 < *(int*)(pcVar5 - 4) && (pcVar5 = std::strchr(pcVar5, (int)*(char*)(param_1 + 0x7c)), pcVar5 != nullptr) && ((int)pcVar5 - *piVar10 != -1));
    if (*(int*)(*(int*)*puVar4 - 4) != 0) { FUN_00489300(); return; }
  }
}

// 0x4f74e0 — observed shape: destructor clearing capacity arrays at +0x14/+0x2c/+0x5c, then +0x70
void FUN_004f74e0(void* self) {
  int in_EAX = (int)(intptr_t)self;
  unsigned int uVar5 = 0;
  // +0x14 array at +0xc
  if (*(int*)(in_EAX + 0x14) != 0) {
    if (*(int*)(in_EAX + 0x14) == 0) goto LAB_004f753c;
    do {
      int* pi = *(int**)(*(int*)(in_EAX + 0xc) + uVar5 * 4);
      *(unsigned int*)(*(int*)(in_EAX + 0xc) + uVar5 * 4) = 0;
      if (pi) *(int*)(in_EAX + 0x18) = *(int*)(in_EAX + 0x18) - 1;
      unsigned int u3 = *(int*)(in_EAX + 0x14) - 1;
      if (uVar5 == u3) *(unsigned int*)(in_EAX + 0x14) = u3;
      if (pi) { unsigned int* p = (unsigned int*)(*pi - 8); if (p && p != (unsigned int*)&DAT_008cacc8) operator_delete__(p); *pi = (int)&DAT_008cacd0; operator_delete(pi); }
LAB_004f753c: uVar5++;
    } while (uVar5 < *(unsigned int*)(in_EAX + 0x14));
  }
  uVar5 = 0;
  if (*(int*)(in_EAX + 0x14) != 0) { do { *(unsigned int*)(*(int*)(in_EAX + 0xc) + uVar5 * 4) = 0; uVar5++; } while (uVar5 < *(unsigned int*)(in_EAX + 0x14)); }
  *(unsigned int*)(in_EAX + 0x14) = 0; *(unsigned int*)(in_EAX + 0x18) = 0;
  uVar5 = 0;
  if (*(int*)(in_EAX + 0x2c) != 0) {
    if (*(int*)(in_EAX + 0x2c) == 0) goto LAB_004f75b8;
    do {
      int* pi = *(int**)(*(int*)(in_EAX + 0x24) + uVar5 * 4);
      *(unsigned int*)(*(int*)(in_EAX + 0x24) + uVar5 * 4) = 0;
      if (pi) *(int*)(in_EAX + 0x30) = *(int*)(in_EAX + 0x30) - 1;
      unsigned int u3 = *(int*)(in_EAX + 0x2c) - 1;
      if (uVar5 == u3) *(unsigned int*)(in_EAX + 0x2c) = u3;
      if (pi) { unsigned int* p = (unsigned int*)(*pi - 8); if (p && p != (unsigned int*)&DAT_008cacc8) operator_delete__(p); *pi = (int)&DAT_008cacd0; operator_delete(pi); }
LAB_004f75b8: uVar5++;
    } while (uVar5 < *(unsigned int*)(in_EAX + 0x2c));
  }
  uVar5 = 0;
  if (*(int*)(in_EAX + 0x2c) != 0) { do { *(unsigned int*)(*(int*)(in_EAX + 0x24) + uVar5 * 4) = 0; uVar5++; } while (uVar5 < *(unsigned int*)(in_EAX + 0x2c)); }
  *(unsigned int*)(in_EAX + 0x2c) = 0; *(unsigned int*)(in_EAX + 0x30) = 0;
  FUN_004f7630();
  uVar5 = 0;
  if (*(int*)(in_EAX + 0x5c) != 0) { do { *(unsigned int*)(*(int*)(in_EAX + 0x54) + uVar5 * 4) = 0; uVar5++; } while (uVar5 < *(unsigned int*)(in_EAX + 0x5c)); }
  *(unsigned int*)(in_EAX + 0x5c) = 0; *(unsigned int*)(in_EAX + 0x60) = 0;
  void* pv = *(void**)(in_EAX + 0x70);
  if (pv) { FUN_004f7ed0(); operator_delete(pv); *(unsigned int*)(in_EAX + 0x70) = 0; }
}

// 0x4f7630 — observed shape: clear array at +0x3c count +0x44, dec +0x48
void FUN_004f7630(void* self) {
  int EDI = (int)(intptr_t)self;
  unsigned int u = 0;
  if (*(int*)(EDI + 0x44) != 0) {
    if (*(int*)(EDI + 0x44) == 0) goto LAB_004f76ad;
    do {
      void* pv = *(void**)(*(int*)(EDI + 0x3c) + u * 4);
      *(unsigned int*)(*(int*)(EDI + 0x3c) + u * 4) = 0;
      if (pv) *(int*)(EDI + 0x48) = *(int*)(EDI + 0x48) - 1;
      unsigned int u2 = *(int*)(EDI + 0x44) - 1;
      if (u == u2) *(unsigned int*)(EDI + 0x44) = u2;
      if (pv) {
        if (*(int*)((int)pv + 8) != 0) {
          FUN_004b9650();
          if (*(unsigned int**)((int)pv + 8) != nullptr) { (**(void(**)(int))**(unsigned int**)((int)pv + 8))(1); *(unsigned int*)((int)pv + 8) = 0; }
        }
        unsigned int* pu = (unsigned int*)(*(int*)((int)pv + 4) - 8);
        if (pu != nullptr && pu != (unsigned int*)&DAT_008cacc8) operator_delete__(pu);
        *(void**)((int)pv + 4) = &DAT_008cacd0;
        operator_delete(pv);
      }
LAB_004f76ad: u++;
    } while (u < *(unsigned int*)(EDI + 0x44));
  }
  u = 0;
  if (*(int*)(EDI + 0x44) != 0) { do { *(unsigned int*)(*(int*)(EDI + 0x3c) + u * 4) = 0; u++; } while (u < *(unsigned int*)(EDI + 0x44)); }
  *(unsigned int*)(EDI + 0x44) = 0; *(unsigned int*)(EDI + 0x48) = 0;
}

// ---------------------------------------------------------------------------
// Appended reconstructions: 0x4f76e0 .. 0x4f7ed0.
// The listings model QString-like temporaries as a two-word {data,tag} pair;
// the local struct below makes that layout explicit (mirrors the raw
// `undef1* local_N` temporaries shown by the decompiler).
// ---------------------------------------------------------------------------

extern "C" void LAB_004f7bc0();   // array-default-fill routine passed to FUN_004127b0

struct QwTmp {
  unsigned char* data;
  int tag;
};

// Releases the heap block in front of a temporary's data pointer and restores
// the shared empty-buffer representation (observed at every temp teardown).
static inline void qw_free(QwTmp& s) {
  unsigned char* p = s.data;
  if (p != nullptr) {
    unsigned int* blk = (unsigned int*)(p - 8);
    if (blk != (unsigned int*)&DAT_008cacc8) operator_delete__(blk);
  }
  s.data = (unsigned char*)&DAT_008cacd0;
}

// Observed string-assignment core: reserve, copy, terminate, honour length 0.
static inline void qw_assign(unsigned char* dst, const unsigned char* src, int len) {
  if (len < 0 || src == nullptr || src == dst) return;
  if (len == 0) {
    if (*(int*)(dst - 4) != 0) { *dst = 0; *(unsigned int*)(dst - 4) = 0; }
  } else {
    FUN_004f3350();
    std::memmove(dst, src, (size_t)len);
    *(unsigned char*)(dst + *(int*)(dst - 4)) = 0;
  }
}

// 0x4f76e0 — observed shape: vector init with vtable PTR_FUN_0071065c, live
// count at +1, storage at +2, length at +3, zero-fill of count&0x3fffffff
// words, then vtable PTR_FUN_00710678.
void FUN_004f76e0(void* self, int count) {
  unsigned int* obj = (unsigned int*)self;   // receiver arrived in ESI
  unsigned int* puVar1;
  unsigned int uVar2;
  int iVar3;
  obj[1] = (unsigned int)count;
  obj[0] = (unsigned int)(uintptr_t)&PTR_FUN_0071065c;
  obj[3] = 0;
  puVar1 = (unsigned int*)FUN_00533c78((size_t)count << 2);
  obj[2] = (unsigned int)(uintptr_t)puVar1;
  for (uVar2 = obj[1] & 0x3fffffffu; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  // Second zeroing loop is present in the listing with a zero trip count.
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 - 1) {
    *(unsigned char*)puVar1 = 0;
    puVar1 = (unsigned int*)((intptr_t)puVar1 + 1);
  }
  obj[0] = (unsigned int)(uintptr_t)&PTR_FUN_00710678;
}

// 0x4f7730 — observed shape: deleting destructor; base teardown then free
// self when the low flag bit is set.
void FUN_004f7730(void* self, unsigned char param_1) {
  FUN_004f7d60(self);   // base destructor; receiver arrived in ECX
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x4f7750 — observed shape: scalar deleting destructor, vtable
// PTR_FUN_007106ac, frees the string slot at +4.
void FUN_004f7750(void* self, unsigned char param_1) {
  unsigned int* in_ECX = (unsigned int*)self;
  in_ECX[0] = (unsigned int)(uintptr_t)&PTR_FUN_007106ac;
  operator_delete__((void*)(uintptr_t)in_ECX[1]);
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
}

// 0x4f7780 — observed shape: scalar deleting destructor, vtable
// PTR_FUN_007106a0, frees the string slot at +4.
void FUN_004f7780(void* self, unsigned char param_1) {
  unsigned int* in_ECX = (unsigned int*)self;
  in_ECX[0] = (unsigned int)(uintptr_t)&PTR_FUN_007106a0;
  operator_delete__((void*)(uintptr_t)in_ECX[1]);
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
}

// 0x4f77b0 — observed shape: resize of an 8-byte {string,tag} element vector.
// Erases the tail elements from the requested size up to the current capacity
// (each erase tears the element string down and decrements the live count),
// then reallocates +4 to new_size*8+4, copies the surviving prefix, initialises
// the new tail from the shared empty buffer, and finally destroys the old
// block along with every element string it still owns.
void FUN_004f77b0(void* self, unsigned int param_2) {
  intptr_t b = (intptr_t)self;
  unsigned int idx;
  int iVar1;
  QwTmp local_10{ (unsigned char*)&DAT_008cacd0, 0 };
  QwTmp local_8{ (unsigned char*)&DAT_008cacd0, 0 };

  idx = param_2;
  if (param_2 != *(unsigned int*)(b + 8)) {
    if (param_2 < *(unsigned int*)(b + 0xc)) {
      idx = param_2;
      do {
        FUN_004f7c50(&local_10, (const unsigned char*)&DAT_008cacd0, 0);
        char cVar4 = (char)FUN_004f7cc0((QwTmp*)(*(int*)(b + 4) + (intptr_t)idx * 8), &local_10);
        qw_free(local_10);
        if (cVar4 == 0) {
          FUN_004f7c50(&local_8, (const unsigned char*)&DAT_008cacd0, 0);
          FUN_004f7be0(&local_10, &local_8);
          qw_free(local_8);
          *(int*)(b + 0x10) = *(int*)(b + 0x10) + -1;
        }
        idx = idx + 1;
      } while (idx < *(unsigned int*)(b + 0xc));
      *(unsigned int*)(b + 0xc) = param_2;
    }
    iVar1 = *(int*)(b + 4);
    QwTmp* puVar10 = nullptr;
    *(unsigned int*)(b + 8) = param_2;
    if (param_2 == 0) {
      *(unsigned int*)(b + 4) = 0;
    } else {
      unsigned int* puVar7 = (unsigned int*)FUN_00533c78((size_t)param_2 * 8 + 4);
      if (puVar7 != nullptr) {
        puVar10 = (QwTmp*)(puVar7 + 1);
        *puVar7 = param_2;
        FUN_004127b0(puVar10, 8, param_2, (void*)&LAB_004f7bc0);
      }
      *(QwTmp**)(b + 4) = puVar10;
      idx = 0;
      if (*(int*)(b + 0xc) != 0) {
        do {
          const unsigned char* srcData = *(const unsigned char**)(iVar1 + (intptr_t)idx * 8);
          size_t _Size = *(size_t*)(srcData - 4);
          QwTmp* dstElem = (QwTmp*)(*(int*)(b + 4) + (intptr_t)idx * 8);
          qw_assign(dstElem->data, srcData, (int)_Size);
          dstElem->tag = *(int*)(iVar1 + 4 + (intptr_t)idx * 8);
          idx = idx + 1;
        } while (idx < *(unsigned int*)(b + 0xc));
      }
      unsigned int uVar9 = *(unsigned int*)(b + 0xc);
      if (uVar9 < *(unsigned int*)(b + 8)) {
        do {
          int _Size_00 = DAT_008caccc;
          QwTmp* dstElem = (QwTmp*)(*(int*)(b + 4) + (intptr_t)uVar9 * 8);
          unsigned char* puVar2 = dstElem->data;
          if ((-1 < DAT_008caccc) && (puVar2 != (unsigned char*)&DAT_008cacd0)) {
            if (DAT_008caccc == 0) {
              if (*(int*)(puVar2 - 4) != 0) {
                *puVar2 = 0;
                *(unsigned int*)(puVar2 - 4) = 0;
              }
            } else {
              if (0 < DAT_008caccc) {
                if (*(int*)(puVar2 - 8) < DAT_008caccc) {
                  FUN_004f32e0();
                }
                *(int*)(puVar2 - 4) = _Size_00;
              }
              std::memmove(puVar2, &DAT_008cacd0, (size_t)_Size_00);
              *(unsigned char*)(puVar2 + *(int*)(puVar2 - 4)) = 0;
            }
          }
          dstElem->tag = 0;
          uVar9 = uVar9 + 1;
        } while (uVar9 < *(unsigned int*)(b + 8));
      }
    }
    if (iVar1 != 0) {
      int iVar12 = *(int*)(iVar1 - 4);
      unsigned int* puVar5 = (unsigned int*)(iVar1 + (intptr_t)iVar12 * 8);
      if (-1 < iVar12 + -1) {
        do {
          int* piVar11 = (int*)(puVar5 - 2);
          puVar5 = puVar5 - 2;
          unsigned int* puVar8 = (unsigned int*)(uintptr_t)(*piVar11 - 8);
          if ((puVar8 != nullptr) && (puVar8 != (unsigned int*)&DAT_008cacc8)) {
            operator_delete__(puVar8);
          }
          iVar12 = iVar12 + -1;
          *puVar5 = (unsigned int)(uintptr_t)&DAT_008cacd0;
        } while (iVar12 != 0);
      }
      operator_delete__((void*)(iVar1 - 4));
    }
  }
}

// 0x4f7a30 — observed shape: move-out/erase of the element at index; the
// element tag at +4 is carried into out->tag, the live count is decremented
// when the moved string compares equal to the element, and the vector size is
// shrunk when the erased element was last.
int FUN_004f7a30(void* self, QwTmp* out, unsigned int param_3) {
  intptr_t b = (intptr_t)self;
  unsigned int uVar1;
  char cVar2;
  int iVar3;
  unsigned int uVar5;
  QwTmp local_10{ (unsigned char*)&DAT_008cacd0, 0 };
  QwTmp local_8{ (unsigned char*)&DAT_008cacd0, 0 };

  if (param_3 < *(unsigned int*)(b + 0xc)) {
    iVar3 = *(int*)(b + 4);
    FUN_00412df0();
    uVar1 = *(unsigned int*)(iVar3 + (intptr_t)param_3 * 8 + 4);
    FUN_004f7c50(&local_8, (const unsigned char*)&DAT_008cacd0, 0);
    FUN_004f7be0(&local_10, &local_8);
    qw_free(local_8);
    FUN_004f7c50(&local_10, (const unsigned char*)&DAT_008cacd0, 0);
    cVar2 = (char)FUN_004f7cc0(&local_10, (QwTmp*)(*(int*)(b + 4) + (intptr_t)param_3 * 8));
    qw_free(local_10);
    if (cVar2 == 0) {
      *(int*)(b + 0x10) = *(int*)(b + 0x10) + -1;
    }
    uVar5 = *(int*)(b + 0xc) - 1;
    if (param_3 == uVar5) {
      *(unsigned int*)(b + 0xc) = uVar5;
    }
    FUN_00412df0();
    out->tag = (int)uVar1;
  } else {
    FUN_004f7c50(&local_10, (const unsigned char*)&DAT_008cacd0, 0);
    FUN_00412df0();
    out->tag = local_10.tag;
  }
  qw_free(local_10);
  return (int)(intptr_t)out;
}

// 0x4f7b60 — observed shape: take the pointer at index out of the +4 array,
// clear the slot, decrement the live count when non-null, and shrink the
// size when the last slot was taken. Returns the taken pointer value.
int FUN_004f7b60(void* self, unsigned int index) {
  intptr_t b = (intptr_t)self;
  if (*(unsigned int*)(b + 0xc) <= index) {
    return 0;
  }
  int* piVar1 = (int*)(*(int*)(b + 4) + (intptr_t)index * 4);
  int iVar2 = *piVar1;
  *piVar1 = 0;
  if (iVar2 != 0) {
    *(int*)(b + 0x10) = *(int*)(b + 0x10) + -1;
  }
  unsigned int uVar3 = *(int*)(b + 0xc) - 1;
  if (index == uVar3) {
    *(unsigned int*)(b + 0xc) = uVar3;
  }
  return iVar2;
}

// 0x4f7b90 — observed shape: bounds check against +8, then forward the
// operation to FUN_004f5720; out-of-range falls into FUN_004f5670.
void FUN_004f7b90(void* self, unsigned int index) {
  intptr_t b = (intptr_t)self;
  if (*(unsigned int*)(b + 8) <= index) {
    FUN_004f5670();
  }
  FUN_004f5720();
}

// 0x4f7be0 — observed shape: assign the source temporary into the destination
// string slot; copies the data block, terminates it, and copies the tag.
void FUN_004f7be0(QwTmp* self, QwTmp* param_1) {
  unsigned char* _Src = param_1->data;
  size_t _Size = *(size_t*)(_Src - 4);
  if ((-1 < (int)_Size) && (_Src != nullptr) && (_Src != self->data)) {
    if (_Size != 0) {
      FUN_004f3350();
      std::memmove(self->data, _Src, _Size);
      *(unsigned char*)(self->data + *(int*)(self->data - 4)) = 0;
      self->tag = param_1->tag;
      return;
    }
    FUN_00412f90();
  }
  self->tag = param_1->tag;
}

// 0x4f7c50 — observed shape: reset the destination temp to the shared empty
// buffer, then copy the source string into it and store the tag; finally
// releases the source's own heap block.
void FUN_004f7c50(QwTmp* self, const unsigned char* param_1, int param_2) {
  size_t _Size;
  self->data = (unsigned char*)&DAT_008cacd0;
  _Size = *(size_t*)(param_1 - 4);
  if ((-1 < (int)_Size) && (param_1 != (const unsigned char*)&DAT_008cacd0)) {
    if (_Size == 0) {
      FUN_00412f90();
    } else {
      FUN_004f3350();
      std::memmove(self->data, param_1, _Size);
      *(unsigned char*)(self->data + *(int*)(self->data - 4)) = 0;
    }
  }
  unsigned int* puVar1 = (unsigned int*)(param_1 - 8);
  self->tag = param_2;
  if ((puVar1 != nullptr) && (puVar1 != (unsigned int*)&DAT_008cacc8)) {
    operator_delete__(puVar1);
  }
}

// 0x4f7cc0 — observed shape: lexicographic byte comparison of two string
// temporaries followed by equality of their tags; 1 when both match, else 0.
int FUN_004f7cc0(QwTmp* self, QwTmp* other) {
  const unsigned char* pbVar2 = self->data;
  const unsigned char* pbVar4 = other->data;
  int iVar3;
  for (;;) {
    unsigned char bVar1 = *pbVar2;
    bool bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
      iVar3 = (1 - (int)bVar5) - (int)(bVar5 != 0);
      goto LAB_004f7cfd;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) {
      iVar3 = (1 - (int)bVar5) - (int)(bVar5 != 0);
      goto LAB_004f7cfd;
    }
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
    if (bVar1 == 0) break;
  }
  iVar3 = 0;
LAB_004f7cfd:
  if ((iVar3 == 0) && (self->tag == other->tag)) {
    return 1;
  }
  return 0;
}

// 0x4f7d20 — observed shape: deleting destructor for the PTR_FUN_0071065c
// table; base teardown, frees the allocation at +8.
void FUN_004f7d20(void* self, unsigned char param_1) {
  unsigned int* in_ECX = (unsigned int*)self;
  in_ECX[0] = (unsigned int)(uintptr_t)&PTR_FUN_0071065c;
  FUN_004e6420();
  operator_delete__((void*)(uintptr_t)in_ECX[2]);
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
}

// 0x4f7d60 — observed shape: vtable PTR_FUN_007106a4; walks the 8-byte
// element array at +4 backwards releasing every element string, then frees
// the array block itself.
void FUN_004f7d60(void* self) {
  unsigned int* in_ECX = (unsigned int*)self;
  in_ECX[0] = (unsigned int)(uintptr_t)&PTR_FUN_007106a4;
  int iVar2 = (int)in_ECX[1];
  if (iVar2 != 0) {
    int iVar5 = *(int*)(iVar2 - 4);
    unsigned int* puVar4 = (unsigned int*)(iVar2 + (intptr_t)iVar5 * 8);
    if (-1 < iVar5 + -1) {
      do {
        int* piVar1 = (int*)(puVar4 - 2);
        puVar4 = puVar4 - 2;
        unsigned int* puVar3 = (unsigned int*)(uintptr_t)(*piVar1 - 8);
        if ((puVar3 != nullptr) && (puVar3 != (unsigned int*)&DAT_008cacc8)) {
          operator_delete__(puVar3);
        }
        iVar5 = iVar5 + -1;
        *puVar4 = (unsigned int)(uintptr_t)&DAT_008cacd0;
      } while (iVar5 != 0);
    }
    operator_delete__((void*)(iVar2 - 4));
  }
}

// 0x4f7e00 — observed shape: destroy every live element of the collection at
// +4; the element kind at *param_1 selects plain delete (1), array delete (2)
// or reset to the shared empty buffer (3); teardown via FUN_004e6420.
void FUN_004f7e00(void* self) {
  int* param_1 = (int*)self;
  unsigned int uVar4 = 0;
  QwTmp local_8{ (unsigned char*)&DAT_008cacd0, 0 };
  if (param_1[4] != 0) {
    do {
      int* piVar2 = (int*)(intptr_t)FUN_004f7a30(param_1 + 1, &local_8, uVar4);
      int _Size = DAT_008caccc;
      int iVar1 = *param_1;
      if (iVar1 == 1) {
        operator_delete((void*)(uintptr_t)*piVar2);
      } else if (iVar1 == 2) {
        operator_delete__((void*)(uintptr_t)*piVar2);
      } else if ((iVar1 == 3) && (-1 < DAT_008caccc) &&
                 ((unsigned char*)(uintptr_t)*piVar2 != (unsigned char*)&DAT_008cacd0)) {
        if (DAT_008caccc == 0) {
          FUN_00412f90();
        } else {
          FUN_004f3350();
          std::memmove((void*)(uintptr_t)*piVar2, &DAT_008cacd0, (size_t)_Size);
          *(unsigned char*)(*piVar2 + *(int*)(*piVar2 - 4)) = 0;
        }
      }
      qw_free(local_8);
      uVar4 = uVar4 + 1;
      local_8.data = (unsigned char*)&DAT_008cacd0;
    } while (uVar4 < (unsigned int)param_1[4]);
  }
  FUN_004e6420();
}

// 0x4f7ed0 — observed shape: full destructor chain. Installs
// PTR_FUN_00710694, tears down the +0x6c string, resets it to the empty
// buffer, swaps the +0x3c vtable through PTR_FUN_006f583c/FUN_004f4de0 and
// PTR_FUN_006f5864/FUN_004f0dc0, releases +0x58, destroys the collection at
// +0x10, walks the +0x2c vector table through PTR_FUN_00710678 then
// PTR_FUN_0071065c, frees +0x34 and finally calls FUN_004f7d60.
void FUN_004f7ed0(void* self) {
  unsigned int* in_EAX = (unsigned int*)self;
  in_EAX[0] = (unsigned int)(uintptr_t)&PTR_FUN_00710694;
  FUN_004fd340();
  {
    QwTmp t{ (unsigned char*)(uintptr_t)in_EAX[0x1b], 0 };
    qw_free(t);
    in_EAX[0x1b] = (unsigned int)(uintptr_t)&DAT_008cacd0;
  }
  in_EAX[0xf] = (unsigned int)(uintptr_t)&PTR_FUN_006f583c;
  FUN_004f4de0();
  in_EAX[0xf] = (unsigned int)(uintptr_t)&PTR_FUN_006f5864;
  FUN_004f0dc0();
  {
    QwTmp t{ (unsigned char*)(uintptr_t)in_EAX[0x16], 0 };
    qw_free(t);
    in_EAX[0x16] = (unsigned int)(uintptr_t)&DAT_008cacd0;
  }
  FUN_004f7e00(in_EAX + 4);
  in_EAX[0xb] = (unsigned int)(uintptr_t)&PTR_FUN_00710678;
  FUN_004e6420();
  in_EAX[0xb] = (unsigned int)(uintptr_t)&PTR_FUN_0071065c;
  FUN_004e6420();
  operator_delete__((void*)(uintptr_t)in_EAX[0xd]);
  FUN_004f7d60(in_EAX);
}
