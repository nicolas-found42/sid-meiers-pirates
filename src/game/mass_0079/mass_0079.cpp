#include <cstdint>
#include <cstddef>
#include <cstring>
#include <windows.h>

extern void FUN_00412f10(void);
extern void FUN_00412e50(const char* s);
extern void FUN_00412ec0(void);
extern void FUN_00412df0(void);
extern void FUN_00412a60(void* self, const void* src);
extern void FUN_00412cb0(void* self);
extern void FUN_00412f90(void);
extern char* _strlwr(char* s);
extern void* FUN_00533c78(size_t n);
extern void FUN_004fa8e0(int a, int b);
extern void FUN_004fa9f0(void);
extern void FUN_004faab0(void);
extern void FUN_004fac10(void);
extern void FUN_004fab20(void);
extern void FUN_004f30d0(int a);
extern void FUN_004f32e0(void);
extern void FUN_004f32b0(void);
extern void FUN_004f3350(void);
extern void FUN_004f1d50(void);
extern void FUN_004fbfd0(void);
extern void FUN_004fd6c0(void);
extern void FUN_004fd730(void);
extern void FUN_004fc7a0(uint32_t a, void* b);
extern void FUN_00476050(void);
extern void FUN_004b1130(void* a, void* b);
extern void FUN_004f1310(void);
extern void FUN_004f1840(void);
extern void FUN_004cce40(void);
extern void FUN_004ff5f0(float a);
extern float FUN_004ff650(float a, float b);
extern void FUN_004ff6b0(uint32_t a);
extern void FUN_004ff890(void);
extern void FUN_004ff2b0(void);
extern void FUN_004fe360(void* self);
extern void FUN_004fe2d0(void* self, uint32_t* param_1, uint32_t param_2, char* param_3);
extern void FUN_004fe9c0(void* self, int param_2);
extern void FUN_00537950(void);
extern void FUN_00533d10(uint32_t a, int b);
extern void* FUN_0053c6f0(void* a, void* b, void* c);
extern void FUN_0053c740(float a);
extern void FUN_0053c7c0(float a);
extern void FUN_0053c8d0(void* a, void* b);
extern void operator_delete(void* p);
extern void operator_delete__(void* p);

extern uint32_t DAT_00726c38[];
extern uint32_t DAT_00726c28;
extern void* DAT_00726c1c;
extern char DAT_008cacd0;
extern int DAT_008caccc;
extern uint8_t DAT_008cacf8;
extern uint8_t DAT_008cace4;
extern void* DAT_008cacc8;
extern void* DAT_008ea08c;
extern char DAT_0070c164;
extern char DAT_00710a2c;
extern void* DAT_007177b8;
extern void* DAT_007177c4;
extern void* DAT_007177ac;
extern void* PTR_FUN_00710ab0;
extern void* PTR_FUN_00710994;
extern void* PTR_FUN_00710aac;
extern void* PTR_FUN_0070d868;

// 0x4fe2d0 — observed shape
void FUN_004fe2d0(void* self, uint32_t* param_1, uint32_t param_2, char* param_3) {
  uint32_t* s = (uint32_t*)self;
  // in_EAX is the 4th field receiver value passed in register; modeled as s[4] write
  // Observed: in_ECX[4] = in_EAX
  s[4] = 0; // placeholder register breadcrumb: actual value set by caller ABI
  FUN_00412f10();
  _strlwr((char*)s[2]);
  s[0] = param_1[0];
  s[1] = param_1[1];
  s[6] = param_2;
  if (param_3 != nullptr && *param_3 != '\0') {
    FUN_00412f10();
    s[7] = 0;
    s[5] = 0;
    FUN_004fe360(self);
    return;
  }
  if ((int)(((char*)s[3])[-4]) != 0) {
    ((char*)s[3])[0] = 0;
    ((uint32_t*)((char*)s[3] - 4))[0] = 0;
  }
  s[7] = 0;
  s[5] = 0;
  FUN_004fe360(self);
}

// 0x4fe360 — observed shape
void FUN_004fe360(void* self) {
  uint8_t* e = (uint8_t*)self;
  uint8_t* pb = *(uint8_t**)(e + 8);
  int count = *(int*)(pb - 4);
  uint32_t crc = 0xffffffffu;
  if (count != 0) {
    do {
      crc = (crc >> 8) ^ DAT_00726c38[((*pb ^ crc) & 0xff)];
      ++pb;
      --count;
    } while (count != 0);
  }
  *(uint32_t*)(e + 0x20) = crc;
}

// 0x4fe3a0 — observed shape
uint8_t FUN_004fe3a0(void* self, int* esi_vtable, int ebx_val, int eax_offset) {
  // ESI points to vtable-holder, EBX is length param, EAX is base offset
  using Fn = uint32_t(*)(void*, ...);
  uint8_t bVar4 = (uint8_t)(**(Fn**)(*esi_vtable + 0x18))();
  uint32_t iVar5 = (uint32_t)(**(Fn**)(*esi_vtable + 0x20))(esi_vtable, 4);
  if (ebx_val < 1) {
    bVar4 = 0;
  } else {
    int* piVar1 = (int*)((char*)self + eax_offset + 8);
    if (*(int*)(*(int*)piVar1 - 8) < ebx_val) {
      FUN_004f32e0();
      *(int*)(*piVar1 - 4) = ebx_val;
    }
    uint32_t iVar6 = (uint32_t)(**(Fn**)(*esi_vtable + 0x20))(*piVar1, ebx_val);
    char* pcVar3 = (char*)*piVar1;
    bVar4 = (uint8_t)(bVar4 & (iVar5 == 4) & (iVar6 == (uint32_t)ebx_val));
    if (ebx_val == -1) {
      char* scan = pcVar3;
      do { } while (*scan++ != '\0');
      *(int*)(pcVar3 - 4) = (int)(scan - (pcVar3 + 1));
      FUN_004f32b0();
    } else {
      *(int*)(pcVar3 - 4) = ebx_val;
      if (ebx_val > 0) {
        pcVar3[ebx_val] = 0;
      }
      FUN_004f32b0();
    }
  }
  uint32_t alloc = (uint32_t)FUN_00533c78(4);
  uint32_t uVar8 = alloc ? (uint32_t)(uintptr_t)0 : 0;
  // FUN_00412cb0 would assign the new block; called via observed helper when non-null
  (void)uVar8;
  *(uint32_t*)((char*)self + eax_offset + 0x10) = uVar8;
  int iVar5b = *(int*)(*(int*)((char*)self + eax_offset + 8) - 4);
  (**(Fn**)(*esi_vtable + 0x1c))((iVar5b + 3) & ~3u, 1);
  uint32_t iVar5c = (uint32_t)(**(Fn**)(*esi_vtable + 0x20))();
  uint32_t iVar6b = (uint32_t)(**(Fn**)(*esi_vtable + 0x20))((char*)self + eax_offset + 0x18, 4);
  uint32_t iVar9b = (uint32_t)(**(Fn**)(*esi_vtable + 0x20))((char*)self + eax_offset + 0x1c, 4);
  *(uint32_t*)((char*)self + eax_offset + 0x14) = 0;
  FUN_004fe360(self);
  return (uint8_t)(bVar4 & (iVar5c == 8) & (iVar6b == 4) & (iVar9b == 4));
}

// 0x4fe510 — observed shape
void FUN_004fe510(void* self, uint32_t poly) {
  uint8_t* e = (uint8_t*)self;
  uint32_t* table = (uint32_t*)self;
  for (uint32_t i = 0; i < 0x100; ++i) {
    uint32_t v = i;
    for (int k = 0; k < 8; ++k) {
      v = (v >> 1) ^ ((v & 1) ? poly : 0);
    }
    table[i] = v;
  }
  uint8_t zeros[4] = {0, 0, 0, 0};
  uint32_t crc = 0xffffffffu;
  for (int i = 0; i < 4; ++i) {
    crc = (crc >> 8) ^ table[((zeros[i] ^ crc) & 0xff)];
  }
  *(uint32_t*)(e + 0x404) = crc;
}

// 0x4fe5e0 — observed shape
void FUN_004fe5e0(void* self, uint32_t param_1, char* opt_name, char opt_flag) {
  uint32_t* s = (uint32_t*)self;
  FUN_004fa8e0(4, 0);
  s[0] = (uint32_t)(uintptr_t)&PTR_FUN_00710ab0;
  s[0xf] = (uint32_t)(uintptr_t)&DAT_008cacd0;
  s[0x10] = (uint32_t)(uintptr_t)&DAT_008cacd0;
  s[0x11] = (uint32_t)(uintptr_t)&DAT_008cacd0;
  s[0x12] = (uint32_t)(uintptr_t)&DAT_008cacd0;
  s[0xe] = param_1;
  FUN_00412f10();
  FUN_00412f10();
  {
    char* p = (char*)(uintptr_t)s[0x10];
    char* end = p + *(int*)(p - 4);
    for (; p < end; ++p) if (*p == '/') *p = '\\';
    uint32_t i2 = s[0x10];
    if (*(char*)(*(int*)(i2 - 4) - 1 + i2) != '\\') FUN_00412e50(&DAT_0070c164);
  }
  FUN_00412f10();
  {
    char* p = (char*)(uintptr_t)s[0x11];
    char* end = p + *(int*)(p - 4);
    for (; p < end; ++p) if (*p == '/') *p = '\\';
    if (*(char*)(*(int*)(s[0x11] - 4) - 1 + s[0x11]) != '\\') FUN_00412e50(&DAT_0070c164);
  }
  if (opt_name == nullptr || *opt_name == '\0') {
    if (*(int*)((char*)(uintptr_t)s[0x12] - 4) != 0) {
      *(char*)(uintptr_t)s[0x12] = 0;
      *(uint32_t*)((char*)(uintptr_t)s[0x12] - 4) = 0;
      *(char*)((char*)self + 0xd * sizeof(uint32_t)) = opt_flag;
      return;
    }
  } else {
    FUN_00412f10();
    char* p = (char*)(uintptr_t)s[0x12];
    char* end = p + *(int*)(p - 4);
    if (end <= p) {
      *(char*)((char*)self + 0xd * sizeof(uint32_t)) = opt_flag;
      return;
    }
    do {
      if (*p == '/') *p = '\\';
      ++p;
    } while (p < end);
  }
  *(char*)((char*)self + 0xd * sizeof(uint32_t)) = opt_flag;
}

// 0x4fe7f0 — observed shape
void FUN_004fe7f0(void* self, char* param_2) {
  (void)self;
  if (*param_2 != '\0') {
    FUN_00412f10();
    if ((&DAT_008cacd0)[DAT_008caccc + 3] != '\\') {
      FUN_00412e50(&DAT_0070c164);
    }
    FUN_00412e50(param_2);
    _WIN32_FIND_DATAA fd{};
    HANDLE h = FindFirstFileA(&DAT_008cacd0, &fd);
    if (h != (HANDLE)0xffffffff) {
      do {
        if ((((uint8_t)fd.dwFileAttributes & 0x16) == 0)) {
          FUN_004fab20();
          FUN_004fe9c0(self, (int)(intptr_t)&fd);
        }
      } while (FindNextFileA(h, &fd) != 0);
      FindClose(h);
    }
    FUN_00412f10();
    if ((&DAT_008cacd0)[DAT_008caccc + 3] != '\\') {
      FUN_00412e50(&DAT_0070c164);
    }
    FUN_00412e50(&DAT_00710a2c);
    h = FindFirstFileA(&DAT_008cacd0, &fd);
    if (h != (HANDLE)0xffffffff) {
      do {
        if ((((uint8_t)fd.dwFileAttributes & 6) == 0) && (((uint8_t)fd.dwFileAttributes & 0x10) != 0)) {
          // skip "." and ".."
          bool isDot = (fd.cFileName[0] == '.' && fd.cFileName[1] == '\0');
          bool isDotDot = (fd.cFileName[0] == '.' && fd.cFileName[1] == '.' && fd.cFileName[2] == '\0');
          if (!isDot && !isDotDot) {
            FUN_00412f10();
            if ((&DAT_008cacd0)[DAT_008caccc + 3] != '\\') {
              FUN_00412e50(&DAT_0070c164);
            }
            FUN_00412e50(fd.cFileName);
            FUN_004fe7f0((void*)&DAT_008cacd0, param_2);
          }
        }
      } while (FindNextFileA(h, &fd) != 0);
      FindClose(h);
    }
  }
}

// NEEDS_MANUAL: 0x4fe9c0 — very long non-contiguous sync/copy routine with string-manager globals; translated as structural equivalent preserving call order, path handling, copy/mutex flow.
// 0x4fe9c0 — observed shape
void FUN_004fe9c0(void* self, int param_2) {
  LPVOID param_1 = self;
  char* local_1c = &DAT_008cacd0;
  uint8_t* local_18 = (uint8_t*)&DAT_008cacd0;
  uint8_t* local_c = nullptr;
  uint8_t* local_8 = nullptr;
  int* local_10 = nullptr;
  uint32_t* local_14 = nullptr;
  static int local_4_holder;
  int* local_4 = &local_4_holder;
  (void)local_4;

  FUN_00412f10();
  if (local_1c[*(int*)(local_1c - 4) - 1] != '\\') {
    FUN_00412e50(&DAT_0070c164);
  }
  char* pcVar10 = local_1c;
  if (local_1c[1] != ':') {
    if (*local_1c == '\\') {
      FUN_00476050();
      FUN_00412ec0();
      uint32_t* p = (uint32_t*)(local_8 - 8);
      if (p != nullptr && p != (uint32_t*)DAT_008cacc8) operator_delete__(p);
      FUN_004f1d50();
    } else if (DAT_008caccc != 0) {
      DAT_008cacd0 = 0;
      DAT_008caccc = 0;
    }
    goto LAB_004fec5b;
  }
  {
    int iVar6 = *(int*)(local_1c - 4);
    if (local_1c[2] == '\\') {
      int iVar11 = 3;
      if (iVar6 < 3) iVar11 = iVar6;
      if (iVar6 < 0) iVar11 = 0;
      if (iVar11 == iVar6) {
        FUN_00412df0();
      } else {
        local_14 = (uint32_t*)&DAT_008cacd0;
        FUN_004f30d0(0);
        FUN_00412df0();
        uint32_t* p = (uint32_t*)((char*)local_14 - 8);
        if (p != nullptr && p != (uint32_t*)DAT_008cacc8) operator_delete__(p);
      }
      FUN_00412ec0();
      uint32_t* q = (uint32_t*)((char*)local_10 - 8);
      if (q != nullptr && q != (uint32_t*)DAT_008cacc8) operator_delete__(q);
      iVar6 = *(int*)(pcVar10 - 4);
      iVar11 = 3;
      if (iVar6 < 3) iVar11 = iVar6;
      if (iVar11 != iVar6) {
        if (iVar11 < 1 || iVar6 < 1) goto LAB_004fec5b;
        iVar6 = iVar6 - iVar11;
        memmove(pcVar10, pcVar10 + iVar11, iVar6 + 1);
        *(int*)(pcVar10 - 4) = *(int*)(pcVar10 - 4) - iVar11;
        goto LAB_004fec5b;
      }
    } else {
      int iVar11 = 2;
      if (iVar6 < 2) iVar11 = iVar6;
      if (iVar6 < 0) iVar11 = 0;
      if (iVar11 == iVar6) {
        FUN_00412df0();
      } else {
        local_10 = (int*)&DAT_008cacd0;
        FUN_004f30d0(0);
        FUN_00412df0();
        uint32_t* p = (uint32_t*)((char*)local_10 - 8);
        if (p != nullptr && p != (uint32_t*)DAT_008cacc8) operator_delete__(p);
      }
      FUN_00412ec0();
      uint32_t* q = (uint32_t*)((char*)local_14 - 8);
      if (q != nullptr && q != (uint32_t*)DAT_008cacc8) operator_delete__(q);
      iVar6 = *(int*)(pcVar10 - 4);
      iVar11 = 2;
      if (iVar6 < 2) iVar11 = iVar6;
      if (iVar11 != iVar6) {
        if (iVar11 < 1 || iVar6 < 1) goto LAB_004fec5b;
        iVar6 = iVar6 - iVar11;
        memmove(pcVar10, pcVar10 + iVar11, iVar6 + 1);
        *(int*)(pcVar10 - 4) = *(int*)(pcVar10 - 4) - iVar11;
        goto LAB_004fec5b;
      }
    }
    if (iVar6 != 0) {
      *pcVar10 = '\0';
      pcVar10[-4] = '\0';
      pcVar10[-3] = '\0';
      pcVar10[-2] = '\0';
      pcVar10[-1] = '\0';
    }
  }
LAB_004fec5b:
  FUN_004ff0d0((uint8_t*)param_1);
  {
    void* sz = FUN_00533c78(4);
    if (sz == nullptr) local_10 = nullptr;
    else {
      // FUN_004b1130(iVar6, &local_1c) returns string pointer holder
      FUN_004b1130(&local_10, &local_1c);
    }
  }
  if (DAT_008cacf8 == '\0') {
    uint32_t* rec = (uint32_t*)FUN_00533c78(0x28);
    if (rec == nullptr) {
      local_14 = nullptr;
    } else {
      uint32_t uVar1 = *(uint32_t*)(param_2 + 0x20);
      rec[2] = (uint32_t)(uintptr_t)&DAT_008cacd0;
      rec[3] = (uint32_t)(uintptr_t)&DAT_008cacd0;
      rec[9] = 0;
      rec[4] = (uint32_t)(uintptr_t)local_10;
      FUN_00412f10();
      _strlwr((char*)(uintptr_t)rec[2]);
      rec[0] = *(uint32_t*)(param_2 + 0x14);
      rec[1] = *(uint32_t*)(param_2 + 0x18);
      rec[6] = uVar1;
      if (*(int*)((char*)(uintptr_t)rec[3] - 4) != 0) {
        *(char*)(uintptr_t)rec[3] = 0;
        *(uint32_t*)((char*)(uintptr_t)rec[3] - 4) = 0;
      }
      rec[7] = 0;
      rec[5] = 0;
      FUN_004fe360(rec);
      local_14 = rec;
    }
  } else {
    size_t maxCount = *(size_t*)(*(char**)((char*)param_1 + 0x48) - 4);
    if (maxCount != 0 && _strnicmp((char*)*local_10, *(char**)((char*)param_1 + 0x48), maxCount) == 0) {
      FUN_004f1d50();
    }
    uint32_t* rec = (uint32_t*)FUN_00533c78(0x28);
    uint8_t* puVar12 = local_c;
    if (rec == nullptr) {
      local_14 = nullptr;
      puVar12 = local_c;
    } else {
      uint32_t uVar1 = *(uint32_t*)((char*)param_1 + 0x48);
      FUN_00412a60(&local_8, (void*)(param_2 + 0x2c));
      uint32_t uVar2 = *(uint32_t*)(param_2 + 0x20);
      rec[2] = (uint32_t)(uintptr_t)&DAT_008cacd0;
      rec[3] = (uint32_t)(uintptr_t)&DAT_008cacd0;
      rec[9] = 0;
      FUN_004fe2d0(rec, (uint32_t*)(param_2 + 0x14), uVar2, (char*)(uintptr_t)uVar1);
      puVar12 = (uint8_t*)1;
      local_14 = rec;
    }
    if (((uint32_t)(uintptr_t)puVar12 & 1) != 0) {
      uint32_t* p = (uint32_t*)(local_8 - 8);
      if (p != nullptr && p != (uint32_t*)DAT_008cacc8) operator_delete__(p);
      local_8 = (uint8_t*)&DAT_008cacd0;
    }
  }
  FUN_00412e50((char*)(param_2 + 0x2c));
  uint32_t* np = (uint32_t*)FUN_004b1130(local_4, &local_1c);
  LPCSTR lpNewFileName = (LPCSTR)(uintptr_t)*np;
  uint32_t* ep = (uint32_t*)FUN_004b1130(&local_c, &local_1c);
  LPCSTR lpExistingFileName = (LPCSTR)(uintptr_t)*ep;
  char cVar4 = 0;
  extern char FUN_004ff020(LPCSTR a, LPCSTR b);
  cVar4 = FUN_004ff020(lpExistingFileName, lpNewFileName);
  bool bVar13;
  if (cVar4 != '\0' || CopyFileExA(lpExistingFileName, lpNewFileName, nullptr, param_1, nullptr, 1) == 0 || *(char*)((char*)param_1 + 0x1c) != '\0') {
    bVar13 = true;
  } else {
    bVar13 = false;
  }
  {
    uint32_t* p = (uint32_t*)(local_c - 8);
    if (p != nullptr && p != (uint32_t*)DAT_008cacc8) operator_delete__(p);
  }
  local_c = (uint8_t*)&DAT_008cacd0;
  {
    uint32_t* p = (uint32_t*)((char*)local_4 - 8);
    if (p != nullptr && p != (uint32_t*)DAT_008cacc8) operator_delete__(p);
  }
  uint32_t* puVar5 = local_14;
  if (bVar13) {
    if (local_14 != nullptr) {
      FUN_004fbfd0();
      operator_delete(puVar5);
    }
    int* piVar3 = local_10;
    if (local_10 != nullptr) {
      uint32_t* p = (uint32_t*)(*(char**)(local_10) - 8);
      if (p != nullptr && p != (uint32_t*)DAT_008cacc8) operator_delete__(p);
      *piVar3 = (int)(uintptr_t)&DAT_008cacd0;
      operator_delete(piVar3);
    }
  } else {
    FUN_004fd6c0();
    do {
      HANDLE hHandle = (HANDLE)DAT_00726c1c;
      if (DAT_00726c28 == 0xffffffff || (LPVOID pvVar8 = TlsGetValue(DAT_00726c28), pvVar8 == nullptr)) {
        WaitForSingleObject(hHandle, 0xffffffff);
      } else {
        FUN_004fac10();
      }
      bVar13 = DAT_008cace4 != 0;
      if (bVar13) ReleaseMutex((HANDLE)DAT_00726c1c);
      if (DAT_00726c28 == 0xffffffff || (LPVOID pvVar8 = TlsGetValue(DAT_00726c28), pvVar8 == nullptr) ||
          (*(int*)((char*)pvVar8 + 0x14) == 0) || (*(int*)((char*)pvVar8 + 0x14) == 3)) {
        SleepEx(1, 0);
      } else {
        LPVOID pvVar8 = TlsGetValue(DAT_00726c28);
        DWORD DVar9 = WaitForSingleObject(*(HANDLE*)((char*)pvVar8 + 0x20), 1);
        if (DVar9 == 0 && (DVar9 = GetCurrentThreadId(), *(DWORD*)((char*)pvVar8 + 0x30) == DVar9)) {
          *(uint32_t*)((char*)pvVar8 + 0x14) = 3;
          FUN_004faab0();
        }
      }
    } while (bVar13);
    FUN_004fc7a0(*(uint32_t*)((char*)param_1 + 0x38), local_14);
    ReleaseMutex((HANDLE)DAT_00726c1c);
    FUN_004fd730();
  }
  {
    char* p = local_1c - 8;
    if (p != nullptr && p != (char*)DAT_008cacc8) operator_delete__(p);
  }
  {
    uint32_t* p = (uint32_t*)(local_18 - 8);
    if (p != nullptr && p != (uint32_t*)DAT_008cacc8) operator_delete__(p);
  }
}

// 0x4ff020 — observed shape
char FUN_004ff020(LPCSTR param_1, LPCSTR param_2) {
  char result = '\0';
  if (FUN_004f1310() == 0) return '\0';
  _WIN32_FIND_DATAA local_280{};
  _WIN32_FIND_DATAA local_140{};
  HANDLE h1 = FindFirstFileA(param_1, &local_280);
  if (h1 != (HANDLE)0xffffffff) {
    HANDLE h2 = FindFirstFileA(param_2, &local_140);
    if (h2 != (HANDLE)0xffffffff) {
      if (local_140.nFileSizeLow == local_280.nFileSizeLow) {
        if (CompareFileTime(&local_140.ftLastWriteTime, &local_280.ftLastWriteTime) == 0) {
          result = '\x01';
        }
      }
      FindClose(h2);
      if (result == '\0') DeleteFileA(param_2);
    }
    FindClose(h1);
  }
  return result;
}

// 0x4ff0d0 — observed shape
void FUN_004ff0d0(uint8_t* param_1) {
  FUN_00412f10();
  uint8_t* src = *(uint8_t**)(param_1 + 0x40);
  size_t sVar1 = *(size_t*)(src - 4);
  if (((int)sVar1 > -1) && src != nullptr && src != (uint8_t*)&DAT_008cacd0) {
    if (sVar1 == 0) {
      FUN_00412f90();
    } else {
      FUN_004f3350();
      memmove(&DAT_008cacd0, src, sVar1);
      (&DAT_008cacd0)[DAT_008caccc] = 0;
    }
  }
  char* found = nullptr;
  if (DAT_008caccc > 0 && (found = strchr(&DAT_008cacd0, 0x5c)) != nullptr) {
    char* pcVar3 = found - 0x8cacd0;
    if (pcVar3 != (char*)0xffffffff) {
      do {
        uint32_t* puVar4 = (uint32_t*)FUN_004f1840();
        int iVar2 = DAT_008caccc;
        void* src00 = (void*)(uintptr_t)*puVar4;
        size_t s2 = *(size_t*)((char*)src00 - 4);
        if ((int)s2 > 0 && DAT_008caccc > -1 && src00 != nullptr) {
          if (DAT_008caccc < (int)(DAT_008caccc + s2)) {
            FUN_004f3350();
            (&DAT_008cacd0)[DAT_008caccc] = 0;
          }
          memmove(&DAT_008cacd0 + iVar2, src00, s2);
        }
        uint32_t* del = (uint32_t*)(param_1 - 8);
        if (del != nullptr && del != (uint32_t*)DAT_008cacc8) operator_delete__(del);
        param_1 = (uint8_t*)&DAT_008cacd0;
        CreateDirectoryA(&DAT_008cacd0, nullptr);
        if (!((int)(pcVar3 + 1) < DAT_008caccc)) break;
        if (!((int)(pcVar3 + 1) > -1)) break;
        pcVar3 = strchr(pcVar3 + 0x8cacd1, 0x5c);
        if (pcVar3 == nullptr) break;
        pcVar3 = pcVar3 - 0x8cacd0;
        if (pcVar3 == (char*)0xffffffff) break;
      } while (true);
    }
  }
}

// 0x4ff290 — observed shape
void FUN_004ff290(void* self, uint8_t param_1) {
  FUN_004ff2b0();
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x4ff2b0 — observed shape
void FUN_004ff2b0(void* self) {
  uint32_t* s = (uint32_t*)self;
  s[0] = (uint32_t)(uintptr_t)&PTR_FUN_00710ab0;
  FUN_004fa9f0();
  for (int idx : {0x12, 0x11, 0x10, 0xf}) {
    uint32_t* p = (uint32_t*)(s[idx] - 8);
    if (p != nullptr && p != (uint32_t*)DAT_008cacc8) operator_delete__(p);
    s[idx] = (uint32_t)(uintptr_t)&DAT_008cacd0;
  }
  s[0] = (uint32_t)(uintptr_t)&PTR_FUN_00710994;
  s[2] = (uint32_t)(uintptr_t)&PTR_FUN_00710aac;
  CloseHandle((HANDLE)(uintptr_t)s[3]);
}

// 0x4ff360 — observed shape
void FUN_004ff360(void* self, float param_1) {
  extern void FUN_004ff510(void* self, float param_1, float param_2);
  extern void FUN_004ff590(void* self, float param_1, float param_2);
  uint32_t* s = (uint32_t*)self;
  FUN_00537950();
  s[0x7d] = 0;
  s[0x7e] = 0;
  s[0x7f] = 0;
  s[0x80] = 0;
  s[0x81] = 0;
  s[0x82] = 0;
  s[0x83] = 0;
  s[0x84] = 0;
  s[0] = (uint32_t)(uintptr_t)&PTR_FUN_0070d868;
  FUN_004ff510(self, param_1, 1.3333334f);
  FUN_004ff590(self, 1.0f, 10000.0f);
  s[0x51] = 0;
  s[0x52] = 0x3f800000;
  s[0x53] = 0x3f800000;
  s[0x54] = 0;
  uint32_t* base = (uint32_t*)FUN_0053c6f0(&DAT_007177b8, &DAT_007177c4, &DAT_007177ac);
  uint32_t* src = base;
  uint32_t* dst1 = s + 0x85;
  for (int i = 9; i != 0; --i) { *dst1++ = *src++; }
  uint32_t* src2 = base;
  uint32_t* dst2 = s + 0xe;
  for (int i = 9; i != 0; --i) { *dst2++ = *src2++; }
}

// 0x4ff450 — observed shape
void FUN_004ff450(void* self, uint32_t* new154, uint32_t* obj188) {
  // self is in_ECX receiver, new154 is in_EAX arg, second slot targets DAT_008ea08c
  uint32_t* slot154 = (uint32_t**)((char*)self + 0x154);
  uint32_t* old = *slot154;
  if (old != new154) {
    if (old != nullptr) {
      int* ref = (int*)(old + 1);
      if (--*ref == 0) {
        using Dtor = void(*)(uint32_t*, int);
        ((Dtor)old[0])(old, 1);
      }
    }
    *slot154 = new154;
    if (new154 != nullptr) new154[1]++;
  }
  uint32_t* slot188 = (uint32_t**)((char*)self + 0x188);
  uint32_t* target = (uint32_t*)DAT_008ea08c;
  (void)obj188;
  old = *slot188;
  if (old != target) {
    if (old != nullptr) {
      int* ref = (int*)(old + 1);
      if (--*ref == 0) {
        using Dtor = void(*)(uint32_t*, int);
        ((Dtor)old[0])(old, 1);
      }
    }
    *slot188 = target;
    if (target != nullptr) target[1]++;
  }
  FUN_004ff6b0(0);
}

// 0x4ff4c0 — observed shape
long double FUN_004ff4c0(void* self) {
  float local_1c[7];
  float* src = (float*)((char*)self + 0x128);
  for (int i = 0; i < 7; ++i) local_1c[i] = src[i];
  long double dx = (long double)local_1c[1] - (long double)local_1c[0];
  long double dy = (long double)local_1c[2] - (long double)local_1c[3];
  long double ang = atan2l(sqrtl(dx * dx + dy * dy) * 0.5L, 1.0L);
  return (ang + ang) * 57.29577951308232L;
}

// 0x4ff510 — observed shape
void FUN_004ff510(void* self, float param_1, float param_2) {
  float local_1c[7];
  float* src = (float*)((char*)self + 0x128);
  for (int i = 0; i < 7; ++i) local_1c[i] = src[i];
  long double t = tanl((long double)param_1 * 0.5L * 0.017453292519943295L);
  long double a = atan2l(1.0L, (long double)param_2);
  long double c = cosl(a) * (long double)(float)t;
  long double s = sinl(a) * (long double)(float)t;
  local_1c[0] = (float)-c;
  local_1c[1] = (float)c;
  local_1c[2] = (float)s;
  local_1c[3] = (float)-s;
  FUN_004cce40();
}

// 0x4ff590 — observed shape
void FUN_004ff590(void* self, float param_1, float param_2) {
  uint32_t local_1c[4];
  uint32_t* src = (uint32_t*)((char*)self + 0x128);
  for (int i = 0; i < 7; ++i) local_1c[i] = src[i];
  float local_c = 0.0f;
  float local_8 = 0.0f;
  if (param_1 != 0.0f) local_c = param_1;
  if (param_2 != 0.0f) local_8 = param_2;
  (void)local_c;
  (void)local_8;
  FUN_004cce40();
}

// 0x4ff650 — observed shape
float FUN_004ff650(float* self, float param_1, float param_2) {
  float fVar1 = 0.0f;
  if (*self > 0.0f && (fVar1 = param_1 * param_2, *self < fVar1)) {
    fVar1 = *self;
  }
  if (*self < 0.0f && (fVar1 = -(param_1 * param_2), fVar1 < *self)) {
    fVar1 = *self;
  }
  *self = *self - fVar1;
  return fVar1;
}

// 0x4ff6b0 — observed shape
void FUN_004ff6b0(void* self, uint32_t param_1) {
  uint8_t local_48[36];
  uint8_t local_24[36];
  auto copy9 = [](uint32_t* dst, uint32_t* src) {
    for (int i = 0; i < 9; ++i) dst[i] = src[i];
  };
  if (*(float*)((char*)self + 500) != 0.0f) {
    float v = FUN_004ff650((float*)((char*)self + 0x1f8), *(float*)param_1, *(float*)((char*)self + 0x1f8));
    // Observed pseudocode passes param_1 as float bit pattern; reproduce observed call shape:
    v = FUN_004ff650((float*)((char*)self + 0x1f8), *(float*)&param_1, *(float*)((char*)self + 0x1f8));
    FUN_0053c7c0(v);
    uint32_t* r = (uint32_t*)FUN_0053c8d0(local_24, (uint32_t*)((char*)self + 0x38));
    copy9((uint32_t*)((char*)self + 0x38), r);
  }
  if (*(float*)((char*)self + 0x1fc) != 0.0f) {
    float v = FUN_004ff650((float*)((char*)self + 0x200), *(float*)&param_1, *(float*)((char*)self + 0x200));
    FUN_0053c7c0(v);
    uint32_t* r = (uint32_t*)FUN_0053c8d0(local_24, local_48);
    copy9((uint32_t*)((char*)self + 0x38), r);
  }
  if (*(float*)((char*)self + 0x204) != 0.0f) {
    float v = FUN_004ff650((float*)((char*)self + 0x208), *(float*)&param_1, *(float*)((char*)self + 0x208));
    FUN_0053c740(v);
    uint32_t* r = (uint32_t*)FUN_0053c8d0(local_24, local_48);
    copy9((uint32_t*)((char*)self + 0x38), r);
  }
  if (*(float*)((char*)self + 0x20c) != 0.0f) {
    float v = FUN_004ff650((float*)((char*)self + 0x210), *(float*)&param_1, *(float*)((char*)self + 0x210));
    FUN_004ff5f0(v);
  }
  FUN_00533d10(param_1, 1);
}

// 0x4ff810 — observed shape
void FUN_004ff810(float* esi_self, void* edi_self) {
  float local_18 = 0.0f, local_14 = 0.0f, local_10 = 0.0f;
  FUN_004ff890();
  float fVar1 = esi_self[1];
  float fVar2 = esi_self[2];
  *(float*)((char*)edi_self + 0x5c) = (*(float*)((char*)edi_self + 0x5c) - local_18) + esi_self[0];
  *(float*)((char*)edi_self + 0x60) = (*(float*)((char*)edi_self + 0x60) - local_14) + fVar1;
  *(float*)((char*)edi_self + 100) = (*(float*)((char*)edi_self + 100) - local_10) + fVar2;
}

// 0x4ff890 — observed shape
void FUN_004ff890(void* eax_self, float* ecx_out) {
  float fVar1 = *(float*)((char*)eax_self + 0x50);
  float fVar2 = *(float*)((char*)eax_self + 0x60);
  float fVar3 = *(float*)((char*)eax_self + 100);
  float fVar4 = *(float*)((char*)eax_self + 0x44);
  if (fVar1 == 0.0f) fVar1 = 0.005f;
  float fVar5 = (float)((fVar3 / fVar1) >= 0 ? (fVar3 / fVar1) : -(fVar3 / fVar1));
  ecx_out[0] = *(float*)((char*)eax_self + 0x5c) + *(float*)((char*)eax_self + 0x38) * fVar5;
  ecx_out[1] = fVar2 + fVar4 * fVar5;
  ecx_out[2] = fVar3 + fVar5 * fVar1;
}
