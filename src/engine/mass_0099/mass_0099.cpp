#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_00518ed0(const char* fmt, ...);
extern void FUN_00518f10(uint32_t a, int b);
extern void operator_delete(void* p);
extern void operator_delete__(void* p);
extern void FUN_0051a540(void* self);
extern void FUN_004f4de0(void);
extern void FUN_004f0dc0(void);
extern void* thunk_FUN_00533c78(uint32_t n);
extern void FUN_004e6420(void);
extern void FUN_0051a7e0(void);
extern void FUN_0051ab30(void);
extern void FUN_0051a960(void* self);
extern void FUN_0051ab30(void* self);
extern void FUN_004f4b20(void* a, int b, int c, int d);
extern int FUN_004f10f0(void* a, int b);
extern int FUN_004fe190(void* a);
extern void FUN_00412d10(void);
extern void FUN_00524e90(void* a);
extern void FUN_00538830(uint32_t a);

extern void* PTR_FUN_00711fe4;
extern void* PTR_FUN_00711fe0;
extern void* PTR_FUN_0071202c;
extern void* PTR_FUN_006f583c;
extern void* PTR_FUN_006f5864;
extern void* DAT_008cacd0;
extern void* DAT_008cacc8;
extern void* PTR_FUN_00711ffc;
extern void* PTR_FUN_00712014;
extern void* PTR_FUN_00712730;
extern void* PTR_FUN_0071274c;

// 0x51a210 — FTGALoader status query; state in dword[0x10], file name dword[1]
int FUN_0051a210(void* self) {
  int32_t* d = static_cast<int32_t*>(self);
  int iVar1 = d[0x10];
  if (iVar1 == 0) {
    FUN_00518ed0("Warning (performance): thread in FTGALoader has not begun loading (file=%s). Attempting load.\n", reinterpret_cast<char*>(static_cast<uintptr_t>(d[1])));
    using Fn = void (*)();
    Fn f1 = reinterpret_cast<Fn>(*reinterpret_cast<void**>(d[0] + 4));
    f1();
    using FnRet = int (*)();
    FnRet f2 = reinterpret_cast<FnRet>(*reinterpret_cast<void**>(d[0] + 0xc));
    return f2();
  }
  if (iVar1 == 1) {
    reinterpret_cast<uint8_t*>(d)[0x11 * 4] = 1;
    return d[2] + 0x12;
  }
  if (iVar1 == 2) {
    FUN_00518ed0("Error: internal mutex error in FTGALoader (file=%s)\n", reinterpret_cast<char*>(static_cast<uintptr_t>(d[1])));
    return 0;
  }
  FUN_00518ed0("Error: while FTGALoader loading (file=%s)\n", reinterpret_cast<char*>(static_cast<uintptr_t>(d[1])));
  return 0;
}

// 0x51a310 — init vtable and zero dword[0x12], dword[0x13]
void FUN_0051a310(void* self, uint32_t eax) {
  FUN_00518f10(eax, 0);
  uint32_t* d = static_cast<uint32_t*>(self);
  d[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00711fe4);
  d[0x12] = 0;
  d[0x13] = 0;
}

// 0x51a410 — FNIFLoader status query; state in dword[0x10], file name dword[1]
int FUN_0051a410(void* self) {
  int32_t* d = static_cast<int32_t*>(self);
  int iVar1 = d[0x10];
  if (iVar1 == 0) {
    FUN_00518ed0("Warning (performance): thread in FNIFLoader has not begun loading (file=%s). Attempting load.\n", reinterpret_cast<char*>(static_cast<uintptr_t>(d[1])));
    using Fn = void (*)();
    Fn f1 = reinterpret_cast<Fn>(*reinterpret_cast<void**>(d[0] + 4));
    f1();
    using FnRet = int (*)();
    FnRet f2 = reinterpret_cast<FnRet>(*reinterpret_cast<void**>(d[0] + 0xc));
    return f2();
  }
  if (iVar1 == 1) {
    reinterpret_cast<uint8_t*>(d)[0x11 * 4] = 1;
    return d[0x12];
  }
  if (iVar1 == 2) {
    FUN_00518ed0("Error: internal mutex error in FNIFLoader (file=%s)\n", reinterpret_cast<char*>(static_cast<uintptr_t>(d[1])));
    return 0;
  }
  FUN_00518ed0("Error: while FNIFLoader loading (file=%s)\n", reinterpret_cast<char*>(static_cast<uintptr_t>(d[1])));
  return 0;
}

// 0x51a480 — realloc node via vtable+4; append payload at tail
void FUN_0051a480(void* self, uint32_t* param_1) {
  uint32_t* unaff_ESI = static_cast<uint32_t*>(self);
  using Fn = uint32_t* (*)();
  Fn f = reinterpret_cast<Fn>(*reinterpret_cast<void**>(*unaff_ESI + 4));
  uint32_t* puVar1 = f();
  puVar1[2] = *param_1;
  puVar1[0] = 0;
// 0x51a4f0 — destructor: reset vtable, release dword[0x13] via vtable+4, common cleanup
void FUN_0051a4f0(void* self, uint8_t param_1) {
  uint32_t* in_ECX = static_cast<uint32_t*>(self);
  in_ECX[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00711fe4);
  if (static_cast<int32_t*>(reinterpret_cast<uintptr_t>(in_ECX[0x13])) != nullptr) {
    using Fn = void (*)(int);
    Fn f = reinterpret_cast<Fn>(*reinterpret_cast<void**>(in_ECX[0x13] + 4));
    f(1);
    in_ECX[0x13] = 0;
  }
  FUN_0051a540(self);
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
}

// 0x51a540 — common destructor body: reset vtable, release dword[1]/dword[2], dtors, reset trailer
void FUN_0051a540(void* self) {
  uint32_t* in_ECX = static_cast<uint32_t*>(self);
  in_ECX[0] = reinterpret_cast<uint32_t>(&PTR_FUN_0071202c);
  using Fn = void (*)();
  Fn f = reinterpret_cast<Fn>(*reinterpret_cast<void**>(in_ECX[3] + 0xc));
  f();
  if (reinterpret_cast<void*>(static_cast<uintptr_t>(in_ECX[1])) != nullptr) {
    operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(in_ECX[1])));
    in_ECX[1] = 0;
  }
  if (reinterpret_cast<char*>(in_ECX)[0x11 * 4] == '\0' && reinterpret_cast<void*>(static_cast<uintptr_t>(in_ECX[2])) != nullptr) {
    operator_delete(reinterpret_cast<void*>(static_cast<uintptr_t>(in_ECX[2])));
  }
  in_ECX[3] = reinterpret_cast<uint32_t>(&PTR_FUN_006f583c);
  FUN_004f4de0();
  in_ECX[3] = reinterpret_cast<uint32_t>(&PTR_FUN_006f5864);
  FUN_004f0dc0();
  uint32_t* puVar1 = reinterpret_cast<uint32_t*>(in_ECX[10] + -8);
  if (puVar1 != nullptr && puVar1 != static_cast<uint32_t*>(&DAT_008cacc8)) {
    operator_delete__(puVar1);
  }
  in_ECX[10] = reinterpret_cast<uint32_t>(&DAT_008cacd0);
}

// 0x51a5c0 — scalar deleting dtor: reset vtable, common cleanup
void FUN_0051a5c0(void* self, uint8_t param_1) {
  uint32_t* in_ECX = static_cast<uint32_t*>(self);
  in_ECX[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00711ffc);
  FUN_0051a540(self);
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
}

// 0x51a610 — ctor: init refcounted parts, release prior dword[0x14]
void FUN_0051a610(void* self, uint32_t eax) {
  FUN_00518f10(eax, 1);
  uint32_t* in_ECX = static_cast<uint32_t*>(self);
  in_ECX[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00712014);
  in_ECX[0x14] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  uint32_t* puVar2 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(in_ECX[0x14]));
  if (puVar2 != nullptr) {
    int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      using Fn = void (*)(int);
      Fn f = reinterpret_cast<Fn>(*puVar2);
      f(1);
    }
    in_ECX[0x14] = 0;
  }
}

// 0x51a650 — scalar deleting dtor: release dword[0x14] twice, common cleanup
void FUN_0051a650(void* self, uint8_t param_1) {
  uint32_t* in_ECX = static_cast<uint32_t*>(self);
  in_ECX[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00712014);
  uint32_t* puVar2 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(in_ECX[0x14]));
  if (puVar2 != nullptr) {
    int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      using Fn = void (*)(int);
      Fn f = reinterpret_cast<Fn>(*puVar2);
      f(1);
    }
    in_ECX[0x14] = 0;
  }
  puVar2 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(in_ECX[0x14]));
  if (puVar2 != nullptr) {
    int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      using Fn = void (*)(int);
      Fn f = reinterpret_cast<Fn>(*puVar2);
      f(1);
    }
  }
  FUN_0051a540(self);
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
}
  puVar1[1] = unaff_ESI[2];
  if (static_cast<uint32_t*>(reinterpret_cast<uintptr_t>(unaff_ESI[2])) == nullptr) {
    unaff_ESI[1] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar1));
    unaff_ESI[2] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar1));
    unaff_ESI[3] = unaff_ESI[3] + 1;
    return;
  }
  *reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(unaff_ESI[2])) = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar1));
  unaff_ESI[2] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar1));
  unaff_ESI[3] = unaff_ESI[3] + 1;
}

// 0x51a4c0 — scalar deleting dtor: reset vtable, delete dword[1], conditional self-delete
void FUN_0051a4c0(void* self, uint8_t param_1) {
  uint32_t* in_ECX = static_cast<uint32_t*>(self);
  in_ECX[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00711fe0);
  operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(in_ECX[1])));
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
}

// 0x51a700 — observed shape
// in_EAX = source file name, unaff_EBX = destination buffer, param_1 = extension kind.
// Builds "<base><tag><original extension>" where the tag is 'H' for 0, 'C' for 1,
// 'S' for 2, and 'S' otherwise.
void FUN_0051a700(char* src, char* dst, int kind) {
  char* dot = strrchr(src, '.');
  size_t baseLen = static_cast<size_t>(dot - src);
  strncpy(dst, src, baseLen);
  // listing re-reads the dot and clears dst + (dot - src)
  dot = strrchr(src, '.');
  dst[baseLen] = '\0';
  char* end = dst + baseLen;
  if (kind == 0) {
    *reinterpret_cast<uint16_t*>(end) = 0x48;  // 'H' + NUL
  } else if (kind == 1) {
    end[0] = 'C';
    end[1] = '\0';
  } else if (kind == 2) {
    end[0] = 'S';
    end[1] = '\0';
  } else {
    *reinterpret_cast<uint16_t*>(end) = 0x53;  // 'S' + NUL
  }
  const char* ext = strrchr(src, '.');
  size_t extLen = strlen(ext) + 1;  // copies the terminator as well
  char* out = dst + strlen(dst);
  for (size_t i = 0; i < extLen; ++i) {
    out[i] = ext[i];
  }
}

// 0x51a7e0 — observed shape
// constructor: install vtable, allocate a 0x25-dword (0x94-byte) zeroed table
void FUN_0051a7e0_recon(void* self) {
  uint32_t* o = static_cast<uint32_t*>(self);
  o[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00712730);
  o[1] = 0x25;
  o[3] = 0;
  uint32_t* p = static_cast<uint32_t*>(thunk_FUN_00533c78(0x94));
  o[2] = reinterpret_cast<uint32_t>(p);
  for (uint32_t n = o[1] & 0x3fffffff; n != 0; --n) {
    *p = 0;
    ++p;
  }
  // the trailing byte-clear loop in the listing has a zero trip count
  o[0] = reinterpret_cast<uint32_t>(&PTR_FUN_0071274c);
  FUN_004e6420();
}

// 0x51a830 — observed shape
// constructor: same table as 0x51a7e0 then sub-object init, two member ctors and teardown
void FUN_0051a830(void* self) {
  uint32_t* o = static_cast<uint32_t*>(self);
  o[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00712730);
  o[1] = 0x25;
  o[3] = 0;
  uint32_t* p = static_cast<uint32_t*>(thunk_FUN_00533c78(0x94));
  o[2] = reinterpret_cast<uint32_t>(p);
  for (uint32_t n = o[1] & 0x3fffffff; n != 0; --n) {
    *p = 0;
    ++p;
  }
  // the trailing byte-clear loop in the listing has a zero trip count
  o[0] = reinterpret_cast<uint32_t>(&PTR_FUN_0071274c);
  FUN_0051a7e0_recon(o);  // callee object arrives in EAX; base object forwarded
  FUN_0051ab30_recon(o);
  FUN_004e6420();
  FUN_004e6420();
  void* local_8 = nullptr;  // no initialization of local_8 is shown in the listing
  operator_delete__(local_8);
  FUN_0051a960(o);
}

// 0x51a8d0 — observed shape
// Extracts a 4-bit field selected by in_AL (0..4) from *param_1 and scales it by 1/15.
// Returns an x87 float10 (long double). The default arm is reproduced literally: the
// mask is the full pointer value and the shift is its low byte.
long double FUN_0051a8d0(uint32_t* param_1, uint8_t in_AL) {
  uint32_t mask;
  uint32_t shift;
  switch (in_AL) {
  case 0:
    shift = 0xc;
    mask = 0xf000;
    break;
  case 1:
    shift = 0x10;
    mask = 0xf0000;
    break;
  case 2:
    shift = 0x14;
    mask = 0xf00000;
    break;
  case 3:
    shift = 0x18;
    mask = 0xf000000;
    break;
  case 4:
    shift = 0x1c;
    mask = 0xf0000000;
    break;
  default:
    mask = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_1));
    shift = mask & 0xff;
    break;
  }
  uint32_t uVar3 = (*param_1 & mask) >> (shift & 0x1f);
  long double fVar4 = static_cast<long double>(static_cast<int32_t>(uVar3));
  if (static_cast<int32_t>(uVar3) < 0) {
    fVar4 = fVar4 + 4294967296.0L;
  }
  return fVar4 * 0.06666667L;
}

// 0x51a960 — observed shape
// Opens a stream on self, drains 5-byte records, then releases the local stream objects.
uint32_t FUN_0051a960(void* self) {
  void** local_30 = &PTR_FUN_006f583c;
  uint8_t* local_14 = reinterpret_cast<uint8_t*>(&DAT_008cacd0);
  uint32_t local_38 = 0;  // used as an object base for a vtable call; no init shown
  uint32_t local_2c = 0;
  uint32_t local_28 = 0;
  uint32_t local_24 = 0;
  uint32_t local_20 = 0;
  uint32_t local_1c = 0;
  uint32_t local_18 = 0;
  uint8_t local_34[4];
  uint32_t local_8 = 0;
  int32_t local_4 = 0;
  uint32_t iStack_c = 0;  // stack condition used below; no init shown
  void* unaff_ESI = nullptr;  // object base for a vtable call; no assignment shown
  int32_t iVar1 = FUN_004f4b20(self, 1, 0, 0x8000);  // extern declares void here
  if (iVar1 != 0) {
    local_30 = &PTR_FUN_006f583c;
    FUN_004f4de0();
    local_30 = &PTR_FUN_006f5864;
    FUN_004f0dc0();
    void* puVar2 = reinterpret_cast<void*>(local_14 - 8);
    if (puVar2 != nullptr && puVar2 != static_cast<void*>(&DAT_008cacc8)) {
      operator_delete__(puVar2);
    }
    return 9;
  }
  FUN_0051ab30_recon(self);
  if (local_4 == 0) {
    iVar1 = FUN_004f10f0(local_34, 4);
  } else {
    iVar1 = FUN_004fe190(local_34);
  }
  if (iVar1 == 0) {
    FUN_004f4de0();
    FUN_00412d10();
    return 0xd;
  }
  uint32_t uVar3 = reinterpret_cast<uint32_t (*)(int, int)>(local_30[7])(0, 1);
  uint32_t uVar4 =
      reinterpret_cast<uint32_t (*)()>(*reinterpret_cast<void**>(static_cast<uintptr_t>(local_38) + 0x10))();
  if (uVar3 < uVar4) {
    do {
      void* pvVar5 = thunk_FUN_00533c78(5);
      if (iStack_c == 0) {
        FUN_004f10f0(local_34 - 0xc, 4);
      } else {
        FUN_004fe190(local_34 - 0xc);
      }
      if (iStack_c == 0) {
        iVar1 = FUN_004f10f0(pvVar5, 5);
      } else {
        iVar1 = FUN_004fe190(pvVar5);
      }
      if (iVar1 == 5) {
        FUN_00524e90(pvVar5);
      } else {
        operator_delete__(pvVar5);
      }
      uVar3 = reinterpret_cast<uint32_t (*)(int, int)>(*reinterpret_cast<void**>(static_cast<uintptr_t>(local_38) + 0x1c))(0, 1);
      uVar4 = reinterpret_cast<uint32_t (*)()>(*reinterpret_cast<void**>(reinterpret_cast<uintptr_t>(unaff_ESI) + 0x10))();
    } while (uVar3 < uVar4);
  }
  FUN_004f4de0();
  FUN_00412d10();
  return 0;
}

// 0x51ab30 — observed shape
// Walks the 0x25-entry table at dword[2], releasing each entry payload at entry[2];
// entries with a null head are re-chained through the vtable+4 hash result.
void FUN_0051ab30_recon(void* self) {
  uint32_t* in_EAX = static_cast<uint32_t*>(self);
  uint32_t uVar2 = 0;
  int32_t* piVar4 = nullptr;
  if (in_EAX[1] != 0) {
    piVar4 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(in_EAX[2]));
    do {
      if (*piVar4 != 0) {
        piVar4 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(
            reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(in_EAX[2]))[uVar2]));
        goto joined;
      }
      uVar2 = uVar2 + 1;
      ++piVar4;
    } while (uVar2 < in_EAX[1]);
  }
  piVar4 = nullptr;
joined:
  for (;;) {
    if (piVar4 == nullptr) {
      FUN_004e6420();
      return;
    }
    int32_t* piVar6 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(*piVar4)));
    void* pvVar1 = reinterpret_cast<void*>(static_cast<uintptr_t>(static_cast<uint32_t>(piVar4[2])));
    if (piVar6 == nullptr) {
      int32_t iVar3 = reinterpret_cast<int32_t (*)(int32_t)>(
          *reinterpret_cast<void**>(static_cast<uintptr_t>(in_EAX[0]) + 4))(piVar4[1]);
      uVar2 = static_cast<uint32_t>(iVar3) + 1;
      if (uVar2 < in_EAX[1]) {
        uint32_t* puVar5 = reinterpret_cast<uint32_t*>(
            static_cast<uintptr_t>(in_EAX[2]) + uVar2 * 4);
        do {
          piVar6 = reinterpret_cast<int32_t*>(static_cast<uintptr_t>(static_cast<uint32_t>(*puVar5)));
          if (piVar6 != nullptr) goto lab_0051ab93;
          uVar2 = uVar2 + 1;
          ++puVar5;
        } while (uVar2 < in_EAX[1]);
      }
      piVar6 = nullptr;
    }
lab_0051ab93:
    piVar4 = piVar6;
    if (pvVar1 != nullptr) {
      operator_delete__(pvVar1);
    }
  }
}

// 0x51abb0 — observed shape
// scalar deleting dtor: reset vtable, run member dtor, delete dword[2]
void FUN_0051abb0(void* self, uint8_t param_1) {
  uint32_t* in_ECX = static_cast<uint32_t*>(self);
  *in_ECX = reinterpret_cast<uint32_t>(&PTR_FUN_00712730);
  FUN_004e6420();
  operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(in_ECX[2])));
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
}

// 0x51abf0 — observed shape
// scalar deleting dtor: reset both vtables, run both member dtors, delete dword[2]
void FUN_0051abf0(void* self, uint8_t param_1) {
  uint32_t* in_ECX = static_cast<uint32_t*>(self);
  *in_ECX = reinterpret_cast<uint32_t>(&PTR_FUN_0071274c);
  FUN_004e6420();
  *in_ECX = reinterpret_cast<uint32_t>(&PTR_FUN_00712730);
  FUN_004e6420();
  operator_delete__(reinterpret_cast<void*>(static_cast<uintptr_t>(in_ECX[2])));
  if ((param_1 & 1) != 0) {
    operator_delete(in_ECX);
  }
}

// 0x51ac30 — observed shape
// refcounted pointer assignment: release *dword[0], store new value, addref it
void FUN_0051ac30(void* self, uint32_t* param_1) {
  uint32_t* in_ECX = static_cast<uint32_t*>(self);
  uint32_t* puVar2 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(*in_ECX));
  if (puVar2 != param_1) {
    if (puVar2 != nullptr) {
      int32_t* piVar1 = reinterpret_cast<int32_t*>(puVar2 + 1);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        reinterpret_cast<void (*)(int)>(*reinterpret_cast<void**>(puVar2))(1);
      }
    }
    *in_ECX = reinterpret_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_1));
    if (param_1 != nullptr) {
      param_1[1] = param_1[1] + 1;
    }
  }
}

// 0x51ac60 — observed shape
// registers param_1 with 0x538830, then clears dword[1] of the receiver
void FUN_0051ac60(void* self, uint32_t param_1) {
  FUN_00538830(param_1);
  *reinterpret_cast<uint32_t*>(reinterpret_cast<uintptr_t>(self) + 4) = 0;
}
