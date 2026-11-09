#include <cstdint>
#include <cstddef>
#include <windows.h>

// 0x4986e0 — observed shape: COM addref/release with DAT_008ecd78+0x38 dispatch; else FUN_004985e0/FUN_004a14b0
extern void* DAT_008ecd78;
extern void FUN_004985e0(void);
extern void FUN_004a14b0(void);
void FUN_004986e0(void* self, uint32_t param_1, uint32_t** param_2, bool in_AL) {
  (void)self; (void)param_1;
  if (!in_AL) {
    if (param_2) param_2[1]++;
    auto vtbl = *(void***)((char*)DAT_008ecd78 + 0x38);
    int i = ((int(*)())*(void***)DAT_008ecd78)();
    if (i) {
      auto* pi = *(int**)((int(*)())*(void***)DAT_008ecd78)();
      if (param_2) param_2[1]++;
      ((void(*)(uint32_t**))*(void**)(*(int*)pi + 8))(param_2);
    }
    if (param_2) {
      int* p = (int*)param_2 + 1; if (!--*p) (**(void(**)(int))param_2)(1);
      int* p2 = (int*)param_2 + 1; if (!--*p2) (**(void(**)(int))param_2)(1);
    }
  } else {
    FUN_004985e0(); FUN_004a14b0();
    if (param_2) { int* p = (int*)param_2 + 1; if (!--*p) (**(void(**)(int))param_2)(1); }
  }
}

// 0x4987a0 — observed shape: if !in_AL dispatch DAT_008ecd78+0x38 result +0x24(&param_2,&param_5); else cleanup pair
extern void* DAT_008ecd78_2;
void FUN_004987a0(void* self, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7, bool in_AL) {
  (void)self; (void)param_3; (void)param_4; (void)param_6; (void)param_7;
  if (!in_AL) {
    int* pi = *(int**)((int(*)())*(void***)DAT_008ecd78)();
    ((void(*)(void*,void*))*(void**)(*(int*)pi + 0x24))(&param_2, &param_5);
    return;
  }
  FUN_004985e0(); FUN_004a14b0();
}

// 0x498850 — observed shape: gated spin on (in_EAX+0x2714)-(in_EAX+0x2718) mod 100, Sleep(0x28), then param_1 switch 0..15 calling 0049af70/0049aed0
extern uint32_t DAT_008ed2c8;
extern uint32_t DAT_008c7354;
extern char DAT_008cac27, DAT_008cac26;
extern void FUN_004a0d90(void);
extern int FUN_0049af70(uint32_t, int);
extern int FUN_0049aed0(int, int);
void FUN_00498850(void* self, int param_1) {
  (void)self;
  bool c = ((bool(*)())*(void***)DAT_008ecd78)();
  if (!(c && (!DAT_008cac27 || DAT_008cac26))) return;
  int* selfBase = (int*)self;
  while (true) {
    int i = selfBase[0x9C5] - selfBase[0x9C6];
    if (i < 0) i += 100;
    if (!i) break;
    Sleep(0x28);
  }
  FUN_004a0d90();
  uint32_t u = *(uint32_t*)DAT_008ed2c8;
  switch (param_1) {
    case 0: FUN_0049af70(u, 0); FUN_0049aed0(1, -2); return;
    case 1: FUN_0049af70(u, 0); FUN_0049aed0(2, -2); return;
    case 2: FUN_0049af70(u, 0); FUN_0049aed0(3, -2); return;
    case 3: case 4: case 5: case 6: case 7: case 8: case 9: {
      FUN_0049af70(u, 0); FUN_0049aed0(param_1 + 1, -2);
      if (DAT_008c7354 != (uint32_t)-1) { FUN_0049aed0(DAT_008c7354 + 0xe, -2); return; }
      break;
    }
    case 10: FUN_0049af70(u, 0); FUN_0049aed0(11, -2); return;
    case 11: FUN_0049af70(u, 0); FUN_0049aed0(12, -2); return;
    case 12: FUN_0049af70(u, 0); FUN_0049aed0(13, -2); return;
    case 13: FUN_0049af70(u, 0); FUN_0049aed0(21, -2); return;
    case 14: FUN_0049af70(u, 0); FUN_0049aed0(24, -2); return;
    case 15: FUN_0049af70(u, 0); FUN_0049aed0(27, -2);
  }
}

// 0x498a50 — observed shape: same gate/spin; pop stack *(+0x2740)+=-4 when valid; switch EBX 0..15 -> 0049af70(*DAT_008ed2c8,0), 0049aed0(FUN_004a0b70(-2),-2)
extern uint32_t DAT_008ed2c8_2;
extern uint32_t FUN_004a0b70(int);
void FUN_00498a50(void* self, int unaff_EBX) {
  bool c = ((bool(*)())*(void***)DAT_008ecd78)();
  if (!(c && (!DAT_008cac27 || DAT_008cac26))) return;
  int* b = (int*)self;
  while (true) {
    int i = b[0x9C5] - b[0x9C6];
    if (i < 0) i += 100;
    if (!i) break;
    Sleep(0x28);
  }
  if (b[0x9CF] && (((int)b[0x9D0] - b[0x9CF]) >> 2)) b[0x9D0] += -4;
  if (unaff_EBX >= 0 && unaff_EBX <= 15) {
    FUN_0049af70(*(uint32_t*)DAT_008ed2c8, 0);
    FUN_0049aed0(FUN_004a0b70(-2), -2);
  }
}

// 0x498b50 — observed shape: large multi-range CSV loader (713 lines elided); preserve full observed structure per listing
extern uint32_t FUN_00498b50_impl(void);
// NEEDS_MANUAL: listing body 713 lines elided in evidence; full reconstruction requires re-reading ranges 21-735.
uint32_t FUN_00498b50_recon(void) { return FUN_00498b50_impl(); }

// 0x499810 — observed shape: loads Audio2DScripts.csv, maps 0..15 column headers, validates, allocates 0x4d80/0x4dc, parses rows into 0x40 stride
extern int FUN_004fadc0(void);
extern char FUN_004faef0(void*, const char*);
extern int FUN_004fae60(void);
extern void* FUN_004fb1f0(void);
extern int FUN_00529f10(uint32_t);
extern int FUN_00529f60(uint32_t);
extern int FUN_00529fb0(uint32_t);
extern void* thunk_alloc(size_t);
extern uint32_t DAT_008ed4d0, DAT_008ed4a4, DAT_008ed4a0;
uint32_t FUN_00499810(void) { return 0; // NEEDS_MANUAL: full column-map + row-parse body exceeds evidence window; needs full range read
}

// 0x49a010 — observed shape: loads Audio3DScripts.csv, maps 0..21 columns, validates, allocates 0x53e0/0x3d4, parses 0x58-stride rows
uint32_t FUN_0049a010(void) { return 0; // NEEDS_MANUAL: full body requires full-range read; header-map preserved in analysis
}

// 0x49aa50 — observed shape: loads AudioSoundScapeScripts.csv, maps ScriptN ID/Type headers 0..22, allocates 0x564/0x40, parses with FUN_0052a000
uint32_t FUN_0049aa50(void) { return 0; // NEEDS_MANUAL: full body requires full-range read
}

// 0x49aed0 — observed shape: TLS-aware mutex wait on (EDI+0x2720), ReleaseMutex on param_1==-1 or error, else FUN_00527f40 + FUN_004a0d90
extern uint32_t DAT_00726c28;
extern void FUN_004fac10(void);
extern char FUN_00527f40(void*, int, int);
int FUN_0049aed0(void* unaff_EDI, int param_1, int param_2) {
  HANDLE h = *(HANDLE*)((char*)unaff_EDI + 0x2720);
  if (DAT_00726c28 != 0xffffffff) {
    void* v = TlsGetValue(DAT_00726c28);
    if (v) { FUN_004fac10(); goto done; }
  }
  WaitForSingleObject(h, 0xffffffff);
done:
  if (param_1 == -1) { ReleaseMutex(h); return 0; }
  if (!FUN_00527f40(&DAT_008ecd78, param_1, param_2)) { ReleaseMutex(h); return 0; }
  FUN_004a0d90(); ReleaseMutex(h); return 1;
}

// 0x49af70 — observed shape: TLS mutex pattern, FUN_005280d0, then set/diff-update int list at +0x272c..+0x2730, ReleaseMutex
extern char FUN_005280d0(uint32_t);
int FUN_0049af70(void* unaff_EDI, uint32_t param_1, int* param_2) {
  HANDLE h = *(HANDLE*)((char*)unaff_EDI + 0x2720);
  if (DAT_00726c28 == 0xffffffff || !TlsGetValue(DAT_00726c28))
    WaitForSingleObject(h, 0xffffffff);
  else FUN_004fac10();
  if (!FUN_005280d0(param_1)) { ReleaseMutex(h); return 0; }
  if (!param_2) {
    if (*(void**)((char*)unaff_EDI + 0x272c)) operator_delete(*(void**)((char*)unaff_EDI + 0x272c));
    *(int*)((char*)unaff_EDI + 0x272c) = 0;
    *(int*)((char*)unaff_EDI + 0x2730) = 0;
    *(int*)((char*)unaff_EDI + 0x2734) = 0;
  } else {
    int* cur = *(int**)((char*)unaff_EDI + 0x272c);
    if (cur != *(int**)((char*)unaff_EDI + 0x2730)) {
      while (cur != *(int**)((char*)unaff_EDI + 0x2730)) {
        int find = *param_2; bool found = false;
        if (find != -1) {
          int* s = param_2;
          while (true) {
            if (*cur == find) { cur++; found = true; break; }
            find = s[1]; s++; if (find == -1) break;
          }
        }
        if (found) continue;
        int* end = *(int**)((char*)unaff_EDI + 0x2730);
        int* np = cur + 1;
        if (np != end) { int d = (int)cur - (int)np; do { *(int*)((char*)np + d) = *np; np++; } while (np != end); }
        *(int*)((char*)unaff_EDI + 0x2730) += -4;
        cur = *(int**)((char*)unaff_EDI + 0x272c);
      }
    }
  }
  ReleaseMutex(h); return 1;
}

// 0x49b080 — observed shape: if last count==3 check NAV_GEYSER/HITGROUND/THROWDIRT strings with globals/timing, calls FUN_0049f930
extern int DAT_0085a164, DAT_0085a7d0, DAT_0085a7b0, DAT_008c8218;
extern int FUN_005f0ddc(void);
extern void FUN_0049f930(int, int, int);
void FUN_0049b080(int param_1, char* unaff_EDI) {
  int i3 = *(int*)(*(int*)(param_1 + 0x2730) - 4);
  if (i3 != 3) return;
  char* e = unaff_EDI; while (*e) e++;
  if (_strnicmp(unaff_EDI, "NAV_GEYSER", (int)e - (int)(unaff_EDI + 1)) == 0 && DAT_0085a164 < 0) {
    int v3 = DAT_0085a7d0 / 1000 - FUN_005f0ddc();
    int v4 = DAT_0085a7b0 / 1000 - FUN_005f0ddc();
    if (v4 < 0) v4 = -v4; if (v3 < 0) v3 = -v3;
    int v5 = v3 + v4 * 2; if (v4 <= v3) v5 = v4 + v3 * 2;
    if (v5 / 2 < 5000) FUN_0049f930(param_1, 0x23, 0);
  }
  if (DAT_008c8218 != 0) return;
  e = unaff_EDI; while (*e) e++;
  if (_strnicmp(unaff_EDI, "NAV_HITGROUND", (int)e - (int)(unaff_EDI + 1)) == 0) { FUN_0049f930(param_1, 0x21, 0); return; }
  e = unaff_EDI; while (*e) e++;
  if (_strnicmp(unaff_EDI, "NAV_THROWDIRT", (int)e - (int)(unaff_EDI + 1)) == 0) { FUN_0049f930(param_1, 0x22, 0); return; }
}

// 0x49eff0 — observed shape: gate on (ESI+0x274f)/in_AL, float scale param_2/param_3, FUN_005281c0(..,0), optional +0x3c call
extern int* FUN_005281c0(void*, int, float, float, uint32_t, uint32_t, int);
void FUN_0049eff0(void* unaff_ESI, uint32_t in_EDX, uint32_t in_ECX, int param_2, int param_3, uint32_t* param_4, float param_5, bool in_AL) {
  if (!*(char*)((char*)unaff_ESI + 0x274f)) {
    if (in_AL) { FUN_004985e0(); FUN_004a14b0(); return; }
  } else if (in_AL) return;
  float f1 = ((int)param_2 == 0x7fffffff) ? -1.0f : (float)(int)param_2 * 0.01f;
  float f2 = (param_3 == -1) ? -1.0f : ((float)param_3 + 100.0f) * 0.005f;
  int* pi = FUN_005281c0(&DAT_008ecd78, 0, f1, f2, in_EDX, in_ECX, 0);
  if (pi && param_4 && (*param_4 = (uint32_t)pi, param_5 > 0.0f))
    ((void(*)(float,float,int,float))*(void**)(*(int*)pi + 0x3c))(param_5, -1.0f, 0, -1.0f);
}

// 0x49f130 — observed shape: same but FUN_005281c0(..,1), sets DAT_008ed510 -1/-2 on outcomes
extern uint32_t DAT_008ed510;
void FUN_0049f130(void* unaff_ESI, uint32_t in_EDX, uint32_t in_ECX, int param_2, int param_3, uint32_t* param_4, float param_5, bool in_AL) {
  if (*(char*)((char*)unaff_ESI + 0x274f) && in_AL) return;
  DAT_008ed510 = 0xffffffff;
  if (in_AL) { FUN_004985e0(); FUN_004a14b0(); return; }
  float f1 = ((int)param_2 == 0x7fffffff) ? -1.0f : (float)(int)param_2 * 0.01f;
  float f2 = (param_3 == -1) ? -1.0f : ((float)param_3 + 100.0f) * 0.005f;
  int* pi = FUN_005281c0(&DAT_008ecd78, 0, f1, f2, in_EDX, in_ECX, 1);
  if (!pi || !param_4) DAT_008ed510 = 0xfffffffe;
  else {
    *param_4 = (uint32_t)pi;
    if (param_5 > 0.0f) ((void(*)(float,float,int,float))*(void**)(*(int*)pi + 0x3c))(param_5, -1.0f, 0, -1.0f);
  }
}

// 0x49f290 — observed shape: range check 0..0x135, 0x40-stride lookup, EDX/ECX vtbl +0x7c/+0x40/+0x44/+0x1c guards, tail-calls 0049eff0
extern uint32_t DAT_008ed4a0_2;
void FUN_0049f290(void* in_EDX, int* in_ECX, int param_1, int param_2, int param_3, int* param_4, float param_5, bool in_AL) {
  if (!*(char*)((char*)in_EDX + 0x274f)) { if (in_AL) { FUN_004985e0(); FUN_004a14b0(); return; } }
  else if (in_AL) return;
  if (param_1 < 0 || param_1 > 0x135) return;
  int v = *(int*)(param_1 * 0x40 + 4 + DAT_008ed4a0);
  bool same = false;
  if (in_ECX && *in_ECX) {
    if (((int(*)())*(void**)(*(int*)*in_ECX + 0x7c))() == v) same = true;
    char c = ((char(*)())*(void**)(*(int*)*in_ECX + 0x40))();
    if (c && same) return;
    char c2 = ((char(*)())*(void**)(*(int*)*in_ECX + 0x44))();
    if (c2 && same) { ((void(*)())*(void**)(*(int*)*in_ECX + 0x1c))(); return; }
  }
  FUN_0049eff0(in_EDX, 0, (uint32_t)in_ECX, param_2, param_3, (uint32_t*)param_4, param_5, false);
}

// 0x49f3f0 — observed shape: in_AL cleanup; null guards; in_ECX==-1 or +0xcc id match; NAN/neg -> +0x38(vol,-1,0,-1) else +0x5c(1)
void FUN_0049f3f0(int* unaff_ESI, int in_ECX, float param_2, bool in_AL) {
  if (in_AL) { FUN_004985e0(); FUN_004a14b0(); return; }
  if (!unaff_ESI || !*unaff_ESI) return;
  if (in_ECX != -1) {
    int* id = *(int**)((int(*)())*(void**)(*(int*)*unaff_ESI + 0xcc))();
    if (!id || in_ECX != *id) return;
  }
  if (!(param_2 == param_2) || param_2 < 0.0f) {
    ((void(*)(float,float,int,float))*(void**)(*(int*)*unaff_ESI + 0x38))(param_2, -1.0f, 0, -1.0f);
    *unaff_ESI = 0; return;
  }
  ((void(*)(int))*(void**)(*(int*)*unaff_ESI + 0x5c))(1);
  *unaff_ESI = 0;
}

// 0x49f4c0 — observed shape: DAT_008ecd78+0x18 gate, param_3 cleanup, null/id(+0xcc) guards, +0x38(pan/roll/vol)
void FUN_0049f4c0(int* unaff_ESI, int in_EAX, float param_2, bool param_3) {
  if (!((bool(*)())*(void***)DAT_008ecd78)()) return;
  if (param_3) { FUN_004985e0(); FUN_004a14b0(); return; }
  if (!unaff_ESI || !*unaff_ESI) return;
  if (in_EAX != -1) {
    int* id = *(int**)((int(*)())*(void**)(*(int*)*unaff_ESI + 0xcc))();
    if (!id || in_EAX != *id) return;
  }
  ((void(*)(float,float,int,float))*(void**)(*(int*)*unaff_ESI + 0x38))(param_2, -1.0f, 0, -1.0f);
}

// 0x49f580 — observed shape: same gate/guards, id via +0xf0, +0x78(param_2)
void FUN_0049f580(int* unaff_ESI, int in_EAX, float param_2, bool param_3) {
  if (!((bool(*)())*(void***)DAT_008ecd78)()) return;
  if (param_3) { FUN_004985e0(); FUN_004a14b0(); return; }
  if (!unaff_ESI || !*unaff_ESI) return;
  if (in_EAX != -1) {
    int* id = *(int**)((int(*)())*(void**)(*(int*)*unaff_ESI + 0xf0))();
    if (!id || in_EAX != *id) return;
  }
  ((void(*)(float))*(void**)(*(int*)*unaff_ESI + 0x78))(param_2);
}

// 0x49f630 — observed shape: same gate/guards, id via +0xcc, +0x60(param_2,0)
void FUN_0049f630(int* unaff_ESI, int in_EAX, float param_2, bool param_3) {
  if (!((bool(*)())*(void***)DAT_008ecd78)()) return;
  if (param_3) { FUN_004985e0(); FUN_004a14b0(); return; }
  if (!unaff_ESI || !*unaff_ESI) return;
  if (in_EAX != -1) {
    int* id = *(int**)((int(*)())*(void**)(*(int*)*unaff_ESI + 0xcc))();
    if (!id || in_EAX != *id) return;
  }
  ((void(*)(float,int))*(void**)(*(int*)*unaff_ESI + 0x60))(param_2, 0);
}

// 0x49f6f0 — observed shape: same gate/guards, id via +0xcc, +0x78(param_2)
void FUN_0049f6f0(int* unaff_ESI, int in_EAX, float param_2, bool param_3) {
  if (!((bool(*)())*(void***)DAT_008ecd78)()) return;
  if (param_3) { FUN_004985e0(); FUN_004a14b0(); return; }
  if (!unaff_ESI || !*unaff_ESI) return;
  if (in_EAX != -1) {
    int* id = *(int**)((int(*)())*(void**)(*(int*)*unaff_ESI + 0xcc))();
    if (!id || in_EAX != *id) return;
  }
  ((void(*)(float))*(void**)(*(int*)*unaff_ESI + 0x78))(param_2);
}

// 0x49f7a0 — observed shape: gate, param_2 cleanup, null/id(+0xcc) guards, +0x98(2) then +0x68()
void FUN_0049f7a0(int* unaff_ESI, int in_ECX, bool param_2) {
  if (!((bool(*)())*(void***)DAT_008ecd78)()) return;
  if (param_2) { FUN_004985e0(); FUN_004a14b0(); return; }
  if (!unaff_ESI || !*unaff_ESI) return;
  if (in_ECX != -1) {
    int* id = *(int**)((int(*)())*(void**)(*(int*)*unaff_ESI + 0xcc))();
    if (!id || in_ECX != *id) return;
  }
  ((void(*)(int))*(void**)(*(int*)*unaff_ESI + 0x98))(2);
  ((void(*)())*(void**)(*(int*)*unaff_ESI + 0x68))();
}
