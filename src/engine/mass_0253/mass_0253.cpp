// Reconstruction batch mass_0253
// Target: Sid Meier's Pirates! (2004), PE32 i386.
// Candidate C++ reconstructions from Ghidra 12.2 pseudocode (provider-specific;
// not original source). Addresses 0x005f03d0 through 0x005f0cca.

#include <cstdint>
#include <cstddef>
#include <windows.h>

typedef void _func_4879(void);
typedef void _func_void_void_ptr(void*);

struct _startupinfo {
  int newmode;
};

// Helpers and globals referenced by the observed listings.
extern void* ExceptionList;
extern void operator_delete(void*);
extern uint32_t FUN_005f0160(uint32_t param_1, uint32_t* param_2);
extern uint32_t FUN_005f0340(uint32_t param_1, uint32_t* param_2);
extern void FUN_005edba0();
extern void FUN_005f0810(void* self);
extern void FUN_005f0bbe(void);
extern void FUN_005f0d12();
extern void FUN_005ca890(uint32_t a, uint32_t b);
extern int FUN_005dbe20();
extern char thunk_FUN_005eebb0(void* p);
extern char thunk_FUN_005eec50(void* p);
extern void FUN_00497420();
extern uint8_t PTR_LAB_006d1974[];
extern uint8_t PTR_FUN_006d1980[];
extern uint8_t LAB_006ba068;

// 0x005f03d0 — observed shape
int FUN_005f03d0(uint32_t param_1, uint32_t* param_2) {
  *param_2 = 0;
  uint32_t uVar1 = (param_1 & 0xfffffeffu) >> 8;
  switch (param_1 & 0xfffffeffu) {
  case 0:
    *param_2 = 0;
    break;
  case 1:
    *param_2 = 1;
    break;
  case 2:
    *param_2 = 2;
    break;
  case 3:
    *param_2 = 3;
    break;
  case 4:
    *param_2 = 4;
    break;
  default:
    return static_cast<int>(uVar1 << 8);
  }
  if ((param_1 & 0x100u) != 0) {
    *param_2 = *param_2 | 0x100u;
  }
  return static_cast<int>((uVar1 << 8) | 1u);
}

// 0x005f0440 — observed shape
uint32_t FUN_005f0440(uint32_t param_1, uint32_t* param_2) {
  uint32_t uVar1 = param_1 & 0xf0000000u;
  param_1 = param_1 & 0x0fffffffu;
  if (uVar1 < 0x20000001u) {
    if (uVar1 == 0x20000000u) {
      *param_2 = 0x20000u;
      *param_2 = *param_2 | param_1;
      return 1;
    }
    if ((uVar1 != 0) && (uVar1 == 0x10000000u)) {
      *param_2 = 0x10000u;
      *param_2 = *param_2 | param_1;
      return 1;
    }
  } else {
    if (uVar1 == 0x30000000u) {
      *param_2 = 0x30000u;
      *param_2 = *param_2 | param_1;
      return 1;
    }
    if (uVar1 == 0x40000000u) {
      *param_2 = 0x40000u;
      *param_2 = *param_2 | param_1;
      return 1;
    }
  }
  *param_2 = 0;
  *param_2 = *param_2 | param_1;
  return 1;
}

// 0x005f04c0 — observed shape
uint32_t FUN_005f04c0(uint32_t param_1, uint32_t* param_2) {
  switch (param_1) {
  case 0:
    *param_2 = 1;
    return 1;
  case 1:
    *param_2 = 2;
    return 1;
  case 2:
    *param_2 = 3;
    return 1;
  case 3:
    *param_2 = 4;
    return 1;
  case 4:
    *param_2 = 5;
    return 1;
  default:
    return 0;
  }
}

// 0x005f0530 — observed shape
uint32_t FUN_005f0530(uint32_t param_1, uint32_t* param_2) {
  switch (param_1) {
  case 0:
    *param_2 = 0;
    return 1;
  case 1:
    *param_2 = 1;
    return 1;
  case 2:
    *param_2 = 2;
    return 1;
  case 3:
    *param_2 = 3;
    return 1;
  case 4:
    *param_2 = 6;
    return 1;
  case 5:
    *param_2 = 7;
    return 1;
  default:
    return 0;
  }
}

// 0x005f05b0 — observed shape
uint32_t FUN_005f05b0(uint32_t param_1, uint32_t param_2, uint32_t* param_3) {
  uint32_t uVar1;

  switch (param_1) {
  case 0:
    uVar1 = FUN_005f0160(param_2, param_3);
    return uVar1;
  case 1:
  case 7:
    uVar1 = FUN_005f0340(param_2, param_3);
    return uVar1;
  case 2:
  case 5:
  case 8:
    uVar1 = FUN_005f0340(param_2, param_3);
    return uVar1;
  case 3:
  case 6:
    uVar1 = FUN_005f0340(param_2, param_3);
    return uVar1;
  case 4:
    uVar1 = FUN_005f0160(param_2, param_3);
    return uVar1;
  default:
    return 0;
  case 10:
  case 0xd:
    *param_3 = param_2;
    return 1;
  case 0xb:
  case 0xe:
    *param_3 = param_2;
    return 1;
  case 0xc:
  case 0xf:
    *param_3 = param_2;
    return 1;
  case 0x10:
    uVar1 = FUN_005f0440(param_2, param_3);
    return uVar1;
  case 0x11:
    uVar1 = FUN_005f03d0(param_2, param_3);
    return uVar1;
  }
}

// 0x005f06c0 — observed shape
uint32_t FUN_005f06c0(uint32_t param_1, uint32_t param_2, uint32_t* param_3) {
  uint32_t uVar1;

  switch (param_1) {
  case 0:
  case 1:
  case 2:
    uVar1 = FUN_005f04c0(param_2, param_3);
    return uVar1;
  case 3:
  case 10:
  case 0xb:
  case 0xc:
    *param_3 = param_2;
    return 1;
  case 4:
  case 5:
  case 6:
    uVar1 = FUN_005f0530(param_2, param_3);
    return uVar1;
  case 7:
  case 8:
  case 9:
    *param_3 = param_2;
    return 1;
  default:
    return 0;
  }
}

// 0x005f0740 — observed shape
uint32_t FUN_005f0740(void* self, uint32_t* param_1) {
  uint8_t* base = static_cast<uint8_t*>(self);
  void* pvVar1;
  char cVar2;
  int iVar3;
  uint32_t* puVar4;
  uint32_t* puVar5;

  *param_1 = *reinterpret_cast<uint32_t*>(base + 4);
  param_1[2] = *reinterpret_cast<uint32_t*>(base + 8);
  FUN_005ca890(*reinterpret_cast<uint32_t*>(base + 0x58),
               *reinterpret_cast<uint32_t*>(base + 0x5c));
  pvVar1 = reinterpret_cast<void*>(static_cast<uintptr_t>(param_1[3]));
  if (*reinterpret_cast<int*>(base + 0xc) != 0) {
    iVar3 = FUN_005dbe20();
    if (iVar3 != 0) {
      cVar2 = thunk_FUN_005eebb0(pvVar1);
      if (cVar2 == 0) goto LAB_005f07a0;
    }
  }
  if (*reinterpret_cast<int*>(base + 0x10) != 0) {
    iVar3 = FUN_005dbe20();
    if (iVar3 != 0) {
      cVar2 = thunk_FUN_005eec50(pvVar1);
      if (cVar2 == 0) {
LAB_005f07a0:
        if (pvVar1 != nullptr) {
          FUN_00497420();
          operator_delete(pvVar1);
        }
        return 0;
      }
    }
  }
  puVar4 = reinterpret_cast<uint32_t*>(base + 0x18);
  puVar5 = param_1 + 8;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 - 1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  return 1;
}

// 0x005f07e0 — observed shape
void FUN_005f07e0(void* self) {
  *reinterpret_cast<void**>(self) = PTR_LAB_006d1974;
}

// 0x005f0810 — observed shape
void FUN_005f0810(void* self) {
  void* local_c;
  uint8_t* puStack_8;
  uint32_t local_4;

  puStack_8 = &LAB_006ba068;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *reinterpret_cast<void**>(self) = PTR_FUN_006d1980;
  local_4 = 0;
  FUN_005edba0();
  *reinterpret_cast<void**>(self) = PTR_LAB_006d1974;
  ExceptionList = local_c;
}

// 0x005f0860 — observed shape
void FUN_005f0860(void* self) {
  uint32_t* fields = static_cast<uint32_t*>(self);

  fields[3] = 0;
  fields[1] = 0;
  fields[2] = 0;
  fields[0] = reinterpret_cast<uint32_t>(PTR_FUN_006d1980);
}

// 0x005f0880 — observed shape
void FUN_005f0880(void* self, uint8_t param_1) {
  FUN_005f0810(self);
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x005f089e — observed shape
// The provider could not recover the jumptable at 0x005f08a7 and treated the
// indirect jump as a call; the observed call shape is preserved verbatim.
// The standalone listing prints a void return, but the observed _atexit caller
// consumes __onexit's result, so the int return is kept here.
extern int _onexit();
extern int __dllonexit(_func_4879* param_1, uint32_t* first, uint32_t* last);
extern uint32_t DAT_008ee20c;
extern uint32_t DAT_008ee208;

int __onexit(_func_4879* param_1) {
  if (DAT_008ee20c == 0xffffffffu) {
    return _onexit();
  }
  return __dllonexit(param_1, &DAT_008ee20c, &DAT_008ee208);
}

// 0x005f08c4 — observed shape
int _atexit(_func_4879* param_1) {
  int iVar1;

  iVar1 = __onexit(param_1);
  return (iVar1 != 0) - 1;
}

// 0x005f09ac — observed shape
extern void __set_app_type(int type);
extern int* __p__fmode();
extern int* __p__commode();
extern void __RTC_Initialize();
extern _func_4879 FUN_005f0f28;
extern void __setusermatherr(_func_4879* fn);
extern void __setdefaultprecision();
extern void initterm(void* first, void* last);
extern int __getmainargs(int* argc, char*** argv, char** envp, int doWildCard,
                         _startupinfo* startupInfo);
extern void _amsg_exit(int code);
extern int _ismbblead(uint32_t c);
extern int FUN_004d3fd0(HMODULE module, uint32_t a1, uint8_t* cmdLine, uint32_t showCmd);
extern void exit(int code);
extern void _cexit();
extern uint32_t _DAT_008ee204;
extern uint32_t _DAT_008ee208;
extern uint32_t* _adjust_fdiv_exref;
extern uint8_t** _acmdln_exref;
extern uint32_t DAT_00729a54;
extern uint32_t DAT_00729a50;
extern uint32_t DAT_00729a4c;
extern uint32_t DAT_00729a48;
extern uint32_t DAT_00718800;
extern uint8_t DAT_00717750;
extern uint8_t DAT_00717754;
extern uint8_t DAT_00717000;
extern uint8_t DAT_0071774c;
extern uint8_t DAT_006da5e8;
extern _func_4879 FUN_005f0ecc;

int entry(void) {
  uint8_t bVar1;
  HMODULE pHVar2;
  uint32_t* puVar3;
  uint32_t uVar4;
  int iVar5;
  int* piVar6;
  uint8_t* pbVar7;
  uint32_t uVar8;
  STARTUPINFOA local_88;
  int local_44;
  int local_40;
  int local_3c;
  char** local_38;
  char** local_34[2];
  _startupinfo local_2c;
  uint8_t* local_28;
  uint32_t local_24;
  uint32_t local_20;
  uint32_t uStack_c;
  void* local_8;

  local_8 = &DAT_006da5e8;
  uStack_c = 0x5f09b8;
  local_24 = 0;
  pHVar2 = GetModuleHandleA(nullptr);
  if ((static_cast<int16_t>(pHVar2->unused) == 0x5a4d) &&
      (piVar6 = reinterpret_cast<int*>(reinterpret_cast<intptr_t>(&pHVar2->unused) +
                                        pHVar2[0xf].unused),
       *piVar6 == 0x4550)) {
    if (static_cast<int16_t>(piVar6[6]) == 0x10b) {
      if (0xe < static_cast<uint32_t>(piVar6[0x1d])) {
        iVar5 = piVar6[0x3a];
        goto LAB_005f0a12;
      }
    } else if ((static_cast<int16_t>(piVar6[6]) == 0x20b) &&
               (0xe < static_cast<uint32_t>(piVar6[0x21]))) {
      iVar5 = piVar6[0x3e];
LAB_005f0a12:
      local_20 = static_cast<uint32_t>(iVar5 != 0);
      goto LAB_005f0a18;
    }
  }
  local_20 = 0;
LAB_005f0a18:
  local_8 = nullptr;
  __set_app_type(2);
  _DAT_008ee208 = 0xffffffffu;
  DAT_008ee20c = 0xffffffffu;
  puVar3 = reinterpret_cast<uint32_t*>(__p__fmode());
  *puVar3 = DAT_00729a54;
  puVar3 = reinterpret_cast<uint32_t*>(__p__commode());
  *puVar3 = DAT_00729a50;
  _DAT_008ee204 = *_adjust_fdiv_exref;
  __RTC_Initialize();
  FUN_005f0f28();
  if (DAT_00718800 == 0) {
    __setusermatherr(FUN_005f0f28);
  }
  __setdefaultprecision();
  initterm(&DAT_00717750, &DAT_00717754);
  _atexit(FUN_005f0ecc);
  local_2c.newmode = static_cast<int>(DAT_00729a4c);
  local_40 = __getmainargs(&local_3c, &local_38, local_34,
                           static_cast<int>(DAT_00729a48), &local_2c);
  if (local_40 < 0) {
    _amsg_exit(8);
  }
  initterm(&DAT_00717000, &DAT_0071774c);
  pbVar7 = *_acmdln_exref;
  while (true) {
    bVar1 = *pbVar7;
    local_28 = pbVar7;
    if ((bVar1 < 0x21) && ((bVar1 == 0) || (local_24 == 0))) break;
    if (bVar1 == 0x22) {
      local_24 = static_cast<uint32_t>(local_24 == 0);
    }
    iVar5 = _ismbblead(bVar1);
    if (iVar5 != 0) {
      pbVar7 = pbVar7 + 1;
    }
    pbVar7 = pbVar7 + 1;
  }
  for (; (pbVar7 = local_28, *local_28 != 0) && (*local_28 < 0x21);
       local_28 = local_28 + 1) {
  }
  local_88.dwFlags = 0;
  GetStartupInfoA(&local_88);
  if ((local_88.dwFlags & 1) == 0) {
    uVar4 = 10;
  } else {
    uVar4 = local_88.wShowWindow;
  }
  uVar8 = 0;
  pHVar2 = GetModuleHandleA(nullptr);
  iVar5 = FUN_004d3fd0(pHVar2, uVar8, pbVar7, uVar4);
  local_44 = iVar5;
  if (local_20 == 0) {
    /* WARNING: Subroutine does not return */
    exit(iVar5);
  }
  _cexit();
  return iVar5;
}

// 0x005f0bbe — observed shape
extern void __security_error_handler(int code, void* data);

void FUN_005f0bbe(void) {
  __security_error_handler(1, 0);
  /* WARNING: Subroutine does not return */
  ExitProcess(3);
}

// 0x005f0bef — observed shape
extern uint32_t DAT_007187f8;

void __security_check_cookie(uint32_t cookie) {
  if (cookie == DAT_007187f8) {
    return;
  }
  FUN_005f0bbe();
  return;
}

// 0x005f0c04 — observed shape
// The saved registers below are read from the caller's frame (provider types
// them unaff_EBX/unaff_ESI/unaff_EDI/unaff_retaddr); this is the standard SEH
// prologue and they are stored back relative to the local frame.
void __SEH_prolog(uint32_t param_1, int param_2) {
  uint32_t unaff_EBX;
  uint32_t unaff_ESI;
  uint32_t unaff_EDI;
  uint32_t unaff_retaddr;
  uint32_t auStack_18[4];
  uint8_t local_8[8];

  param_2 = -param_2;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(auStack_18) + param_2 + 0xc) =
      unaff_EBX;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(auStack_18) + param_2 + 8) =
      unaff_ESI;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(auStack_18) + param_2 + 4) =
      unaff_EDI;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<intptr_t>(auStack_18) + param_2) =
      unaff_retaddr;
  ExceptionList = local_8;
  return;
}

// 0x005f0c3f — observed shape
// unaff_EBP is the caller's frame pointer and unaff_retaddr the saved return
// address read from that frame (provider register/frame leftovers).
void __SEH_epilog(void) {
  uint32_t* unaff_EBP;
  uint32_t unaff_retaddr;

  ExceptionList = reinterpret_cast<void*>(static_cast<uintptr_t>(unaff_EBP[-4]));
  *unaff_EBP = unaff_retaddr;
  return;
}

// 0x005f0c6c — observed shape
// unaff_EDI carries the array element pointer into the destructor callback.
void __ArrayUnwind(void* param_1, uint32_t param_2, int param_3,
                   _func_void_void_ptr* param_4) {
  void* unaff_EDI;

  while (true) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*param_4)(unaff_EDI);
  }
  return;
}

// 0x005f0cca — observed shape
void _eh_vector_destructor_iterator_(void* param_1, uint32_t param_2, int param_3,
                                     _func_void_void_ptr* param_4) {
  void* unaff_EDI;

  while (true) {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    (*param_4)(unaff_EDI);
  }
  FUN_005f0d12();
  return;
}
