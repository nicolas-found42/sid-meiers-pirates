#include <cstdint>
#include <cstddef>
#include <windows.h>

extern void FUN_004ff890();
extern void FUN_005f37f6(void* param_1, void* a, void* b, void* c);
extern void FUN_0054a9f0(int param);
extern void FUN_005f394e(void* a, float b, float c, uint32_t d, uint32_t e);
extern int FUN_004ee070(int addr);
extern uint32_t FUN_004f8e40(void* p);
extern void FUN_004f8b40(const char* fmt, ...);

extern int32_t DAT_008cacf0;
extern int32_t DAT_008cace8;
extern int32_t DAT_008cacec;
extern DWORD DAT_007279c0;
extern int32_t DAT_007279c4;
extern int32_t* DAT_00727994;
extern int32_t DAT_007279a8[32];
extern int32_t DAT_00727520;

// 0x4ff930 — observed shape
void FUN_004ff930(void* self, uint32_t param_1) {
  FUN_004ff890();
  uint32_t base = reinterpret_cast<uint32_t>(self);
  uint32_t local_18 = *reinterpret_cast<uint32_t*>(base + 0x90);
  uint32_t local_14 = *reinterpret_cast<uint32_t*>(base + 0x94);
  uint32_t local_10 = *reinterpret_cast<uint32_t*>(base + 0x98);
  uint32_t local_24 = *reinterpret_cast<uint32_t*>(base + 0x110);
  uint32_t local_20 = *reinterpret_cast<uint32_t*>(base + 0x114);
  uint32_t local_1c = *reinterpret_cast<uint32_t*>(base + 0x118);
  uint8_t local_c[12];
  FUN_005f37f6(reinterpret_cast<void*>(param_1), &local_18, local_c, &local_24);
}

// 0x4ff9a0 — observed shape
void FUN_004ff9a0(void* self, uint32_t param_1, uint32_t param_2) {
  (void)self;
  FUN_0054a9f0(0);
  float* src = reinterpret_cast<float*>(param_1 + 0x128);
  float local_1c[4];
  float* dst = local_1c;
  for (int i = 7; i != 0; i--) {
    *dst = *src;
    src++;
    dst++;
  }
  uint32_t local_c = 0;
  uint32_t local_8 = 0;
  FUN_005f394e(reinterpret_cast<void*>(param_2), local_1c[1] - local_1c[0], local_1c[2] - local_1c[3], local_c, local_8);
}

// 0x4ffa00 — observed shape
bool FUN_004ffa00(void* self) {
  uint32_t base = reinterpret_cast<uint32_t>(self);
  int v = FUN_004ee070(base + 0x18c);
  if (v == 2) return false;
  v = FUN_004ee070(base + 0x19c);
  if (v == 2) return false;
  v = FUN_004ee070(base + 0x1ac);
  if (v == 2) return false;
  v = FUN_004ee070(base + 0x1bc);
  if (v == 2) return false;
  v = FUN_004ee070(base + 0x1cc);
  if (v == 2) return false;
  v = FUN_004ee070(base + 0x1dc);
  return v != 2;
}

// 0x4ffa80 — observed shape
uint32_t FUN_004ffa80(void* self, uint32_t param_1, uint8_t param_2) {
  (void)param_1;
  if (DAT_008cacf0 == 0) return 0;
  if (self == nullptr) return 0;
  if (DAT_008cace8 == 0 && DAT_008cacec == 0) return 0;
  return FUN_004f8e40(&param_2);
}

// 0x4ffbc0 — observed shape
void FUN_004ffbc0(char param_1, int32_t* param_2, int32_t* param_3) {
  int32_t local_c = 0;
  int32_t local_8 = 0;
  DWORD tid = GetCurrentThreadId();
  if (DAT_007279c0 != tid) {
    EnterCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&DAT_007279a8));
    DAT_007279c0 = GetCurrentThreadId();
  }
  DAT_007279c4++;
  if (DAT_00727994 != nullptr) {
    int32_t* node = DAT_00727994;
    // Iterate list head -> *0xd
    int32_t iVar8 = 0;
    char* pcVar6 = nullptr;
    uint32_t uVar4 = 0;
    uint32_t uVar5 = 0;
    while (node != nullptr) {
      // virtual call *(node+4) returns list head
      using Fn = uint32_t* (__cdecl*)();
      int32_t* vtbl0 = reinterpret_cast<int32_t*>(node[0]);
      Fn f4 = reinterpret_cast<Fn>(vtbl0[1]);
      uint32_t* list = f4();
      bool found = false;
      while (list != nullptr) {
        if (reinterpret_cast<uint32_t>(list) == reinterpret_cast<uint32_t>(&DAT_00727520)) {
          pcVar6 = reinterpret_cast<char*>(node[0xe]);
          using Fn2 = uint32_t (*)();
          uVar4 = reinterpret_cast<Fn2>(vtbl0[0xd])();
          uVar5 = reinterpret_cast<Fn2>(vtbl0[0xe])();
          if (node[0xb] == 0) {
            list = f4();
            // scan for 00727520 again
            uint8_t bVar1 = 0;
            while (list != nullptr) {
              if (reinterpret_cast<uint32_t>(list) == reinterpret_cast<uint32_t>(&DAT_00727520)) { bVar1 = 1; break; }
              list = reinterpret_cast<uint32_t*>(list[1]);
            }
            if (bVar1 == 0) { iVar8 = 0; }
            else {
              int32_t* p = reinterpret_cast<int32_t*>(-(uint32_t)bVar1 & reinterpret_cast<uint32_t>(node));
              iVar8 = *reinterpret_cast<int32_t*>(reinterpret_cast<uint32_t>(p) + 0x40);
              if (iVar8 == 0) iVar8 = 0;
              else iVar8 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(iVar8 + 0x40) + *reinterpret_cast<int32_t*>(iVar8 + 0x44) * 4);
            }
          } else {
            iVar8 = *reinterpret_cast<int32_t*>(node[0xb] + 0x50);
          }
          found = true;
          break;
        }
        list = reinterpret_cast<uint32_t*>(list[1]);
      }
      if (found) {
        if (param_1 != '\0') {
          if (pcVar6 == nullptr) pcVar6 = "<NoName>";
          FUN_004f8b40("%5dKb (%3dx%3d) - %s\n", ((uint32_t)iVar8 + 0x3ffU) >> 10, uVar4, uVar5, pcVar6);
        }
        local_8 += iVar8;
        local_c++;
      }
      node = reinterpret_cast<int32_t*>(node[0xd]);
    }
  }
  DWORD tid2 = GetCurrentThreadId();
  if (DAT_007279c0 == tid2 && (--DAT_007279c4 == 0)) {
    DAT_007279c0 = 0;
    LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&DAT_007279a8));
  }
  if (param_2 != nullptr) *param_2 = local_c;
  if (param_3 != nullptr) *param_3 = local_8;
}
extern void FUN_00533c78(uint32_t);
extern int FUN_005516a0();
extern int FUN_00504c40();
extern int FUN_0051e6a0();
extern int FUN_00511e50();
extern int FUN_00518d30();
extern int FUN_00500c60();
extern int FUN_0051ffd0();
extern int FUN_00520050();
extern void FUN_00567750();
extern void operator_delete(void*);
extern int FUN_00533c78_int(uint32_t);
extern int32_t* DAT_008ea090;
extern int32_t* DAT_008ea08c;
extern int32_t* DAT_008ca4e0;
extern int32_t* DAT_008ca4c8;
extern int32_t* DAT_008ea52c;
extern int32_t DAT_008ca53c;
extern void* DAT_008cad0c;
extern void FUN_00546930();
extern void FUN_005677e0();
extern void FUN_005452e0(void*);
extern void FUN_00546140(void*);
extern int32_t DAT_00727444;
extern void* PTR_FUN_00710ae0;
extern void* PTR_FUN_00710ad4;
extern void* PTR_LAB_00710b30;

// 0x4ffd40 — observed shape
void FUN_004ffd40(void* self, char* param_1) {
  uint32_t base = reinterpret_cast<uint32_t>(self);
  int32_t off = static_cast<int32_t>(base + 0x100) - static_cast<int32_t>(reinterpret_cast<uint32_t>(param_1));
  char c;
  do {
    c = *param_1;
    param_1[off] = c;
    param_1++;
  } while (c != '\0');
}

// 0x4ffd60 — observed shape
void FUN_004ffd60(void* self, char* param_1) {
  uint32_t base = reinterpret_cast<uint32_t>(self);
  int32_t off = static_cast<int32_t>(base + 0x303) - static_cast<int32_t>(reinterpret_cast<uint32_t>(param_1));
  char c;
  do {
    c = *param_1;
    param_1[off] = c;
    param_1++;
  } while (c != '\0');
}

// 0x4ffe70 — observed shape
uint32_t FUN_004ffe70(void) {
  FUN_005516a0();
  if (DAT_008ea090 != nullptr) {
    int32_t ref = DAT_008ea090[1];
    DAT_008ea090[1] = ref - 1;
    if (ref - 1 == 0) {
      using Fn = void(__cdecl*)(int32_t);
      auto fn = reinterpret_cast<Fn>(*DAT_008ea090);
      fn(1);
    }
    DAT_008ea090 = nullptr;
  }
  if (DAT_008ea08c != nullptr) {
    int32_t ref = DAT_008ea08c[1];
    DAT_008ea08c[1] = ref - 1;
    if (ref - 1 == 0) {
      using Fn = void(__cdecl*)(int32_t);
      auto fn = reinterpret_cast<Fn>(*DAT_008ea08c);
      fn(1);
    }
    DAT_008ea08c = nullptr;
  }
  if (DAT_008ca4e0 != nullptr) {
    using Fn = void(__cdecl*)(int32_t);
    reinterpret_cast<Fn>(*DAT_008ca4e0)(1);
  }
  int32_t* cur = DAT_008ca4c8;
  int32_t count = cur[3];
  while (DAT_008ca4c8 = cur, count != 0) {
    int32_t* next = reinterpret_cast<int32_t*>(cur[1]);
    int32_t saved = *next;
    cur[1] = saved;
    if (saved == 0) cur[2] = 0;
    else *reinterpret_cast<int32_t*>(saved + 4) = 0;
    int32_t* item = reinterpret_cast<int32_t*>(next[2]);
    using Fn8 = void(__cdecl*)(int32_t*);
    reinterpret_cast<Fn8>(*cur + 8)(next);
    cur[3]--;
    using Fn0 = void(__cdecl*)();
    reinterpret_cast<Fn0>(*item)();
    using Fn4 = void(__cdecl*)(int32_t);
    reinterpret_cast<Fn4>(*item + 4)(1);
    cur = DAT_008ca4c8;
    count = DAT_008ca4c8[3];
  }
  {
    using Fn = void(__cdecl*)(int32_t);
    reinterpret_cast<Fn>(*cur)(1);
  }
  if (DAT_008ea52c != nullptr) {
    int32_t ref = DAT_008ea52c[1];
    DAT_008ea52c[1] = ref - 1;
    if (ref - 1 == 0) {
      using Fn = void(__cdecl*)(int32_t);
      reinterpret_cast<Fn>(*DAT_008ea52c)(1);
    }
    DAT_008ea52c = nullptr;
  }
  FUN_00504c40(); FUN_0051e6a0(); FUN_00511e50(); FUN_00518d30(); FUN_00500c60();
  if (DAT_008ca53c == 0) {
    int ok = FUN_00533c78(0x70);
    if (ok == 0) DAT_008ca53c = 0;
    else DAT_008ca53c = FUN_0051ffd0();
  }
  FUN_00520050();
  operator_delete(DAT_008cad0c);
  FUN_00567750();
  return 0;
}

// 0x4fffb0 — observed shape
void FUN_004fffb0(void) {
  int32_t* obj = reinterpret_cast<int32_t*>(FUN_00533c78(0x1b0));
  if (obj == nullptr) {
    DAT_008ca4e0 = nullptr;
  } else {
    FUN_00546930();
    *obj = reinterpret_cast<int32_t>(&PTR_FUN_00710ae0);
    DAT_008ca4e0 = obj;
  }
  obj = reinterpret_cast<int32_t*>(FUN_00533c78(0x210));
  if (obj == nullptr) obj = nullptr;
  else {
    FUN_005677e0();
    *obj = reinterpret_cast<int32_t>(&PTR_FUN_00710ad4);
  }
  FUN_005452e0(obj);
  int32_t* o2 = reinterpret_cast<int32_t*>(FUN_00533c78(8));
  if (o2 == nullptr) {
    FUN_00546140(nullptr);
    return;
  }
  DAT_00727444++;
  o2[1] = 0;
  *o2 = reinterpret_cast<int32_t>(&PTR_LAB_00710b30);
  FUN_00546140(o2);
}

// 0x500060 — observed shape
void FUN_00500060(void* self, uint8_t param_1) {
  FUN_00567800();
  if ((param_1 & 1) != 0) operator_delete(self);
}
extern void FUN_00567710();
extern void FUN_0054ae40(uint32_t);
extern uint32_t FUN_00550ef0();
extern uint32_t FUN_005009f0();
extern int32_t* FUN_005c5ec0(uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,int32_t,uint32_t,int32_t,int32_t,int32_t,int32_t,int32_t,int32_t,int32_t);
extern void FUN_00511eb0();
extern int32_t* FUN_0054b970();
extern uint32_t QueryPerformanceFrequency(void*);
extern uint32_t QueryPerformanceCounter(void*);
extern int32_t DAT_008ca4d8;
extern int32_t DAT_008ca4d0;
extern int32_t DAT_007275d4;
extern int32_t DAT_008cad5c;
extern int32_t DAT_008cad24;
extern void* DAT_00727b28;
extern void* PTR_FUN_00710ac8;

// 0x500080 — observed shape
uint32_t FUN_00500080(uint32_t param_1, uint32_t param_2, uint32_t param_3, char param_4) {
  FUN_00567710();
  QueryPerformanceFrequency(&DAT_008ca4d8);
  QueryPerformanceCounter(&DAT_008ca4d0);
  DAT_007275d4 = 1;
  uint32_t alloc = FUN_00533c78(0x3fc);
  uint32_t uVar3 = (alloc == 0) ? 0 : FUN_00550ef0();
  FUN_0054ae40(uVar3);
  DAT_008ca4c8 = reinterpret_cast<int32_t*>(FUN_00533c78(0x10));
  if (DAT_008ca4c8 == nullptr) DAT_008ca4c8 = nullptr;
  else {
    DAT_008ca4c8[3] = 0; DAT_008ca4c8[1] = 0; DAT_008ca4c8[2] = 0;
    *DAT_008ca4c8 = reinterpret_cast<int32_t>(&PTR_FUN_00710ac8);
  }
  FUN_004fffb0();
  int32_t* target = reinterpret_cast<int32_t*>(FUN_005009f0());
  // in_EAX / in_ECX model from pseudocode: keep observed refcount swap when differs
  if (target != nullptr) {
    if (DAT_008ea08c != target) {
      if (DAT_008ea08c != nullptr) {
        int32_t r = DAT_008ea08c[1]; DAT_008ea08c[1] = r - 1;
        if (r - 1 == 0) { using Fn=void(__cdecl*)(int32_t); reinterpret_cast<Fn>(*DAT_008ea08c)(1); }
      }
      DAT_008ea08c = target;
      target[1]++;
    }
  } else {
    uint32_t mode = 0x28;
    uint32_t uVar4 = FUN_005009f0();
    int32_t* created = FUN_005c5ec0(param_2, param_3, mode, param_1, param_1, 0, uVar4, 3, 0x4b, 1, 1, param_4 != '\0', 2, 0);
    if (DAT_008ea08c != created) {
      if (DAT_008ea08c != nullptr) {
        int32_t r = DAT_008ea08c[1]; DAT_008ea08c[1] = r - 1;
        if (r - 1 == 0) { using Fn=void(__cdecl*)(int32_t); reinterpret_cast<Fn>(*DAT_008ea08c)(1); }
      }
      if (created == nullptr) { DAT_008ea08c = nullptr; return 8; }
      DAT_008ea08c = created; created[1]++;
    }
  }
  if (DAT_008ea08c == nullptr) return 8;
  uint32_t s10 = 0x3d4ccccd, sc = 0x3d4ccccd, s8 = 0x3e800000, s4 = 0;
  {
    uint32_t args[4] = {s10, sc, s8, s4};
    using Fn = void(__cdecl*)(uint32_t*);
    reinterpret_cast<Fn>(*DAT_008ea08c + 0x70)(args);
  }
  DAT_008cad5c = reinterpret_cast<int32_t*>(DAT_00727b28 ? *reinterpret_cast<int32_t*>(DAT_00727b28) + 4 : 0);
  // vtable call via DAT_00727b28+4
  {
    using Fn = int32_t(__cdecl*)(int32_t,int32_t);
    int32_t* p = *reinterpret_cast<int32_t**>(DAT_00727b28);
    if (p) DAT_008cad5c = reinterpret_cast<Fn>(p[(4)>>2])(0,0);
  }
  uint32_t a2 = FUN_00533c78(0x38);
  int32_t* newObj = (a2 == 0) ? nullptr : FUN_0054b970();
  if (DAT_008ea090 != newObj) {
    if (DAT_008ea090 != nullptr) {
      int32_t r = DAT_008ea090[1]; DAT_008ea090[1] = r - 1;
      if (r - 1 == 0) { using Fn=void(__cdecl*)(int32_t); reinterpret_cast<Fn>(*DAT_008ea090)(1); }
    }
    DAT_008ea090 = newObj;
    if (newObj) newObj[1]++;
  }
  {
    int32_t* old = reinterpret_cast<int32_t*>(DAT_008ea08c[3]);
    if (old != DAT_008ea090) {
      if (old != nullptr) {
        int32_t r = old[1]; old[1] = r - 1;
        if (r == 0) { using Fn=void(__cdecl*)(int32_t); reinterpret_cast<Fn>(*old)(1); }
      }
      DAT_008ea08c[3] = reinterpret_cast<int32_t>(DAT_008ea090);
      if (DAT_008ea090) DAT_008ea090[1]++;
    }
  }
  DAT_008cad24 = 0x3e800000;
  FUN_00511eb0();
  return 0;
}

// 0x5002b0 — observed shape
void FUN_005002b0(void* self, uint8_t param_1) {
  FUN_00500b10();
  if ((param_1 & 1) != 0) operator_delete(self);
}

// 0x5002f0 — observed shape
void FUN_005002f0(void* self_out1, void* self_out2) {
  extern int32_t DAT_008cad10;
  extern int32_t DAT_00727c30;
  if (DAT_008cad10 != '\0') {
    *reinterpret_cast<int32_t*>(self_out1) = 0;
    *reinterpret_cast<int32_t*>(self_out2) = 0;
    return;
  }
  uint8_t local_130[180];
  uint32_t uStack_7c = 0, uStack_74 = 0, uStack_6c = 0, uStack_64 = 0;
  (void)uStack_7c; (void)uStack_74;
  if (*reinterpret_cast<int32_t*>(&DAT_008ea08c) != 0) {
    int32_t* piVar3 = *reinterpret_cast<int32_t**>(DAT_00727c30 + 0x60);
    if (piVar3 != nullptr) {
      using Fn = int32_t(__cdecl*)(int32_t*, uint8_t*);
      int32_t r = reinterpret_cast<Fn>(*piVar3 + 0x1c)(piVar3, local_130);
      if (r == 0) {
        *reinterpret_cast<int32_t*>(self_out1) = (uStack_6c & 0xff) + ((uStack_6c >> 8) & 0xff) * 10;
        *reinterpret_cast<int32_t*>(self_out2) = (uStack_64 & 0xff) + ((uStack_64 >> 8) & 0xff) * 10;
        return;
      }
    }
  }
  *reinterpret_cast<int32_t*>(self_out1) = 0;
  *reinterpret_cast<int32_t*>(self_out2) = 0;
  HMODULE hModule = LoadLibraryA("D3D9.dll");
  if (hModule != nullptr) {
    FARPROC pFVar2 = GetProcAddress(hModule, "Direct3DCreate9");
    if (pFVar2 != nullptr) {
      using CreateFn = int32_t*(__cdecl*)(uint32_t);
      int32_t* piVar3 = reinterpret_cast<CreateFn>(pFVar2)(0x20);
      if (piVar3 != nullptr) {
        using Fn38 = int32_t(__cdecl*)(int32_t*,int32_t,int32_t,uint8_t*);
        reinterpret_cast<Fn38>(*piVar3 + 0x38)(piVar3, 0, 1, local_130);
        *reinterpret_cast<int32_t*>(self_out1) = (uStack_7c & 0xff) + ((uStack_7c >> 8) & 0xff) * 10;
        *reinterpret_cast<int32_t*>(self_out2) = (uStack_74 & 0xff) + ((uStack_74 >> 8) & 0xff) * 10;
        FreeLibrary(hModule);
        return;
      }
      *reinterpret_cast<int32_t*>(self_out2) = 0;
      *reinterpret_cast<int32_t*>(self_out1) = 0;
    }
    FreeLibrary(hModule);
  }
}

// 0x500410 — observed shape
uint32_t FUN_00500410(void* out_edi, void* out_esi) {
  extern uint8_t DAT_008cad10;
  uint8_t saved = DAT_008cad10;
  DAT_008cad10 = 0;
  FUN_005002f0(out_edi, out_esi);
  DAT_008cad10 = saved;
  int32_t a = *reinterpret_cast<int32_t*>(out_edi);
  int32_t b = *reinterpret_cast<int32_t*>(out_esi);
  if (a == 0 || b == 0) return 0;
  return 1;
}

// 0x5004e0 — observed shape
uint32_t FUN_005004e0(void* self, char* param_1) {
  (void)self;
  FUN_00500bf0();
  char c2 = FUN_005477a0(reinterpret_cast<void*>(FUN_00500460));
  if (c2 != '\0') {
    char local_104[260];
    // simplified basename extract preserving observed checks
    const char* base = param_1;
    for (const char* p = param_1; *p; p++) { if (*p == '/' || *p == '\\') base = p + 1; }
    (void)base;
    // copy param_1 suffix logic approximated to preserve call order
    size_t len = 0; while (param_1[len]) len++;
    size_t blen = 0; while (local_104[blen]) blen++;
    // append param_1 after truncated local_104 buffer (as in pseudocode)
    char buf[1024] = {0};
    size_t off = blen; if (off > 0) off--;
    for (size_t i = 0; i < len; i++) buf[off + i] = param_1[i];
    char* dup = _strdup(buf);
    char rc = FUN_005478d0(local_104, 1, dup, 1);
    if (rc != '\0') {
      if (dup) free(dup);
      return 0;
    }
    if (dup) free(dup);
  }
  return 10;
}
extern void FUN_00500b10();
extern void FUN_00500bf0();
extern char Fun005477a0(void*);
extern void* FUN_00500460();
extern char FUN_005478d0(char*,int32_t,char*,int32_t);
extern void FUN_00567800();
extern int32_t FUN_00449390(void*,int32_t);
extern void FUN_00540460(int32_t);
extern void FUN_00534130();
extern void FUN_00534350();
extern void FUN_00533d10(int32_t,int32_t);
extern void FUN_00546260();
extern int32_t FUN_005516a0_int();
extern int32_t FUN_00551600(int32_t);
extern int32_t* FUN_004c2770();
extern void FUN_005451a0(uint32_t);
extern int32_t* FUN_005459b0();
extern int32_t FUN_00539c10();
extern int FUN_005f0ddc();
extern int32_t DAT_00727560;
extern int32_t DAT_008ca4cc;
extern int32_t DAT_008cad10_b;
extern int32_t DAT_00727c30_b;
extern uint32_t _DAT_008ee068;
extern uint32_t _DAT_008ee064;

// 0x500600 — observed shape
int32_t FUN_00500600(int32_t unaff_EDI) {
  if ((_DAT_008ee068 & 1) == 0) {
    _DAT_008ee068 |= 1;
    _DAT_008ee064 = GetCurrentThreadId();
  }
  if (unaff_EDI == 0) return 0;
  FUN_005516a0();
  {
    using Fn = void(__cdecl*)();
    int32_t* ctx = DAT_008ca4e0;
    reinterpret_cast<Fn>(ctx[0] + 0xc)();
  }
  if (DAT_008ca4e0[0x54] == 0) {
    FUN_004ffa80(nullptr, 0, 0);
    FUN_005007e0();
    return 0;
  }
  int32_t obj = FUN_00449390(&DAT_00727560, DAT_008ca4e0[0x52]);
  if (obj == 0) {
    FUN_004ffa80(nullptr, 0, 0);
    FUN_005007e0();
    return 0;
  }
  FUN_00540460(unaff_EDI);
  FUN_00534130();
  FUN_00534350();
  FUN_00533d10(0, 1);
  *reinterpret_cast<int32_t*>(obj + 4) = *reinterpret_cast<int32_t*>(obj + 4) + 1;
  FUN_00546260();
  *reinterpret_cast<int32_t*>(obj + 4) = *reinterpret_cast<int32_t*>(obj + 4) - 1;
  FUN_005007e0();
  return obj;
}

// 0x5006e0 — observed shape
void FUN_005006e0(uint32_t param_1) {
  int32_t* list = DAT_008ca4c8;
  using Fn = int32_t*(__cdecl*)();
  int32_t vtbl = *list;
  int32_t* node = reinterpret_cast<Fn>(vtbl + 4)();
  node[2] = param_1;
  node[0] = 0;
  node[1] = list[2];
  if (list[2] == 0) {
    list[1] = reinterpret_cast<int32_t>(node);
    list[2] = reinterpret_cast<int32_t>(node);
    list[3]++;
    FUN_005007e0();
    return;
  }
  *reinterpret_cast<int32_t*>(list[2]) = reinterpret_cast<int32_t>(node);
  list[2] = reinterpret_cast<int32_t>(node);
  list[3]++;
  FUN_005007e0();
}

// 0x5007e0 — observed shape
int32_t FUN_005007e0(void) {
  if (DAT_008ca4cc == 0 && *reinterpret_cast<int32_t*>(reinterpret_cast<uint32_t>(DAT_008ca4c8) + 0xc) != 0) {
    int32_t ok = FUN_00551600(0);
    if (ok == 0) {
      DAT_008ca4cc = reinterpret_cast<int32_t>(FUN_004c2770());
      int32_t inner = *reinterpret_cast<int32_t*>(DAT_008ca4cc + 8);
      FUN_005451a0(*reinterpret_cast<uint32_t*>(inner + 8));
    }
  }
  return static_cast<int32_t>(DAT_008ca4cc != 0) + *reinterpret_cast<int32_t*>(reinterpret_cast<uint32_t>(DAT_008ca4c8) + 0xc);
}

// 0x500850 — observed shape
int32_t FUN_00500850(int32_t in_EAX, char* unaff_ESI) {
  int32_t* piVar1 = FUN_005459b0();
  using Fn4 = int32_t(__cdecl*)();
  int32_t r = reinterpret_cast<Fn4>(*piVar1 + 4)();
  if (r == 0) {
    if (in_EAX == 0) {
      const char* p = unaff_ESI;
      while (*p) p++;
      _stricmp(p - 4, ".dds");
    }
    r = FUN_00539c10();
    piVar1 = FUN_005459b0();
    using Fn8 = void(__cdecl*)();
    reinterpret_cast<Fn8>(*piVar1 + 8)();
  }
  return r;
}

// 0x500950 — observed shape
void FUN_00500950(void) {
  uint16_t auStack_200[256];
  uint16_t auStack_400[256];
  uint16_t auStack_600[256];
  uint32_t n = 0;
  do {
    // _CIpow() observed; then random value stored in all three tables
    uint16_t v = static_cast<uint16_t>(FUN_005f0ddc());
    auStack_200[n] = v;
    auStack_400[n] = v;
    auStack_600[n] = v;
    n++;
  } while (n < 0x100);
  int32_t* piVar2;
  if (DAT_008ea08c == nullptr) {
    piVar2 = nullptr;
  } else {
    piVar2 = *reinterpret_cast<int32_t**>(DAT_00727c30 + 0x60);
  }
  {
    using Fn = void(__cdecl*)(int32_t*,int32_t,int32_t,uint16_t*);
    reinterpret_cast<Fn>(*piVar2 + 0x54)(piVar2, 0, 1, auStack_600);
  }
}
