// mass_0070 — reconstruction candidates from Ghidra 12.2 pseudocode corpus.
// Target: Sid Meier's Pirates! (2004), PE32 i386.
// Addresses: 0x4f3e10 0x4f3e30 0x4f3e90 0x4f3ee0 0x4f3f40 0x4f4010
//            0x4f40c0 0x4f40f0 0x4f4210 0x4f4260 0x4f4440 0x4f46e0
//            0x4f47b0 0x4f48a0 0x4f4b20 0x4f4c70 0x4f4de0 0x4f4e80
//            0x4f4ea0 0x4f4ed0

#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---------------------------------------------------------------- externs ---
extern "C" void* memmove(void*, const void*, size_t);
extern "C" char* strchr(const char*, int);
extern "C" char* strrchr(const char*, int);
extern "C" char* strstr(const char*, const char*);
extern "C" void srand(unsigned int);
extern "C" void SHChangeNotify(LONG, UINT, const void*, const void*);

extern void operator_delete__(void*);

// Inline / dynamically allocated string buffer of the FXS string class.
// Length lives at buffer[-4], capacity in DAT_008cacc8, current length in
// DAT_008caccc.
extern char DAT_008cacd0[];
extern int DAT_008cacc8;
extern int DAT_008caccc;

extern void* DAT_008cacd4;          // active FXS application instance
extern char DAT_008cacf8;           // no-path-parse flag
extern int DAT_008cace0;
extern volatile LONG DAT_008cace4;  // live object counter
extern HANDLE DAT_00726c1c;         // global loader mutex
extern DWORD DAT_00726c28;          // loader TLS slot index
extern void* PTR_DAT_00726c14;

extern uint8_t DAT_006c05fc[];
extern uint8_t DAT_006c05ec[];
extern uint8_t DAT_006c060c[];
extern uint8_t DAT_0070c164;
extern uint8_t DAT_007105e8;

extern void FUN_004f3c60();
extern char FUN_004fdbe0(void*);
extern void FUN_004fdc60(void*);
extern void* FUN_004f3050();
extern void FUN_004f30a0();
extern void FUN_004f1840();
extern uint32_t* FUN_00476050();
extern void FUN_00412ec0();
extern void FUN_00412fb0();
extern void FUN_00412f10();
extern void FUN_00412df0();
extern void FUN_00412c90();
extern void FUN_00412e50(const void*);
extern void FUN_004129c0(void*, void*, void*, void*);
extern void FUN_004b1130(void*, void*);
extern void FUN_004f32e0();
extern void FUN_004f3390();
extern char FUN_004f1310();
extern void FUN_004f1e40(int);
extern void FUN_004f1c80();
extern void FUN_004f1930(void*, int, int);
extern void FUN_004fac10();
extern void FUN_004f17c0();
extern void FUN_004f1220();
extern void FUN_004fe220();
extern void FUN_004fe190(uint32_t);
extern void FUN_004f10f0();
extern uint32_t FUN_004f0dc0();
extern uint32_t FUN_004f5550();
extern int FUN_004f0e40(const char*, uint32_t, uint32_t, uint32_t);
extern int FUN_004f5480(const char* = nullptr, int* = nullptr);

extern void FUN_004f3e10(void*);

bool FUN_004f48a0(int param_1, HINSTANCE param_2, LPCSTR param_3, uint32_t param_4,
                  uint32_t param_5, HICON param_6, HICON param_7, bool in_AL);
void FUN_004f4210(void* self, int param_1, int in_EDX, int* out);
extern LRESULT CALLBACK LAB_004f49b0(HWND, UINT, WPARAM, LPARAM);

// ------------------------------------------------------------ definitions ---

// 0x4f3e10 — observed shape
// Clears the length-prefixed wide buffer held at self[0].
void FUN_004f3e10(void* self)
{
  int* slot = (int*)self;
  uint8_t* buf = (uint8_t*)(intptr_t)*slot;
  if (*(int*)(buf - 4) != 0) {
    *(uint16_t*)buf = 0;
    *(uint32_t*)(buf - 4) = 0;
  }
}

// 0x4f3e30 — observed shape
// Assignment from another FXS string object (src[0]) into self[0].
void FUN_004f3e30(void* self, void* src)
{
  char** pDst = (char**)self;
  *pDst = DAT_008cacd0;
  uint8_t* s = (uint8_t*)(intptr_t)*(int*)src;
  int len = *(int*)(s - 4);
  if (((-1 < len) && (s != nullptr)) && (s != (uint8_t*)DAT_008cacd0)) {
    if (len != 0) {
      FUN_004f3c60();
      memmove((void*)*pDst, s, len * 2);
      *(uint16_t*)((uint8_t*)*pDst + *(int*)((uint8_t*)*pDst - 4) * 2) = 0;
      return;
    }
    FUN_004f3e10(self);
  }
}

// 0x4f3e90 — observed shape
// Assignment from a raw source pointer into self[0], ignoring self-assignment.
void FUN_004f3e90(void* self, void* src)
{
  char** pDst = (char**)self;
  uint8_t* s = (uint8_t*)(intptr_t)*(int*)src;
  int len = *(int*)(s - 4);
  if (((-1 < len) && (s != nullptr)) && (s != (uint8_t*)*pDst)) {
    if (len != 0) {
      FUN_004f3c60();
      memmove((void*)*pDst, s, len * 2);
      *(uint16_t*)((uint8_t*)*pDst + *(int*)((uint8_t*)*pDst - 4) * 2) = 0;
      return;
    }
    FUN_004f3e10(self);
  }
}

// 0x4f3ee0 — observed shape
// Assignment from an explicit (length, buffer) pair into self[0].
void FUN_004f3ee0(void* self, int length, uint8_t* src)
{
  char** pDst = (char**)self;
  *pDst = DAT_008cacd0;
  if (((-1 < length) && (src != nullptr)) && (src != (uint8_t*)DAT_008cacd0)) {
    if (length != 0) {
      FUN_004f3c60();
      memmove((void*)*pDst, src, length * 2);
      *(uint16_t*)((uint8_t*)*pDst + *(int*)((uint8_t*)*pDst - 4) * 2) = 0;
      return;
    }
    FUN_004f3e10(self);
  }
}

// 0x4f3f40 — observed shape
// Application startup: creates the FXS window, registers the session
// notification hook, seeds the CRT RNG and initialises the object.
int FUN_004f3f40(void* self, char* in_EAX, void* param_1, void* param_2, void* param_3,
                 void* param_4_ebx, void* param_5, void* param_6)
{
  int* pSelf = (int*)self;
  if ((in_EAX != nullptr) && (*in_EAX != '\0')) {
    char cVar1 = FUN_004fdbe0((char*)self + 0x34);
    if (cVar1 == '\0') goto LAB_004f3ffb;
  }
  if (DAT_008cacd4 == nullptr) {
    DAT_008cacd4 = self;
    // The window-style flag arrives in AL from the caller; the only evidenced
    // boolean in this frame is the command-line argument test above.
    char cVar1 = (char)FUN_004f48a0((int)(intptr_t)self, (HINSTANCE)param_1,
                                    (LPCSTR)param_4_ebx, (uint32_t)(uintptr_t)param_2,
                                    (uint32_t)(uintptr_t)param_3, (HICON)param_5,
                                    (HICON)param_6, *in_EAX != '\0');
    if (cVar1 != '\0') {
      HMODULE hModule = LoadLibraryA("Wtsapi32.dll");
      pSelf[0x14] = (int)(intptr_t)hModule;
      if (hModule != nullptr) {
        FARPROC pFVar2 = GetProcAddress(hModule, "WTSRegisterSessionNotification");
        if (pFVar2 != nullptr) {
          ((BOOL(WINAPI*)(HWND, DWORD))pFVar2)((HWND)(intptr_t)pSelf[0x15], 0);
        }
      }
      DWORD _Seed = GetTickCount();
      srand(_Seed);
      (*(void(**)(void))(uintptr_t)(*(uint32_t*)self + 0x20))();
      FUN_004fdc60((char*)self + 0x3c);
      return pSelf[0x15];
    }
    DAT_008cacd4 = nullptr;
  }
LAB_004f3ffb:
  return pSelf[0x15];
}

// 0x4f4010 — observed shape
// Message pump; stops on WM_QUIT.
WPARAM FUN_004f4010(void* self)
{
  uint32_t* pSelf = (uint32_t*)self;
  tagMSG local_1c;
  char cVar1;
  do {
    local_1c.message = 0x400;
    BOOL BVar2 = PeekMessageA(&local_1c, nullptr, 0, 0, 1);
    if (BVar2 == 0) {
      if (*(char*)((char*)self + 5) == '\0') {
        if (*(char*)((char*)self + 6) == '\0') {
          cVar1 = (*(char(**)(void))(uintptr_t)(*(uint32_t*)self + 4))();
          if (cVar1 == '\0') {
            if (*(char*)((char*)self + 5) == '\0') {
              *(uint8_t*)((char*)self + 5) = 1;
              DestroyWindow((HWND)(intptr_t)pSelf[0x15]);
              PostQuitMessage(0);
            }
            DAT_008cacd4 = nullptr;
          }
        }
        else {
          WaitMessage();
        }
      }
    }
    else {
      if (local_1c.message == 0x12) {
        return local_1c.wParam;
      }
      TranslateMessage(&local_1c);
      DispatchMessageA(&local_1c);
    }
  } while (local_1c.message != 0x12);
  return local_1c.wParam;
}

// 0x4f40c0 — observed shape
// Requests application shutdown with the given exit code.
void FUN_004f40c0(void* self, int param_1)
{
  if (*(char*)((char*)self + 5) == '\0') {
    *(uint8_t*)((char*)self + 5) = 1;
    DestroyWindow(*(HWND*)((char*)self + 0x54));
    PostQuitMessage(param_1);
  }
  DAT_008cacd4 = nullptr;
}

// 0x4f40f0 — observed shape
// Resolves the registered URL-scheme handler command for the application and
// normalises it into the string object at self+0x38.
int FUN_004f40f0(void* self)
{
  int* piVar4 = (int*)((char*)self + 0x38);
  if (*(int*)((uint8_t*)(intptr_t)*(int*)((char*)self + 0x38) - 4) == 0) {
    HKEY local_4 = nullptr;
    DWORD local_8 = 0;
    DWORD DVar1 = RegOpenKeyExA((HKEY)(uintptr_t)0x80000000u, "http\\shell\\open\\command",
                                0, 0x20019, &local_4);
    if (DVar1 == 0) {
      local_8 = DVar1;
      LSTATUS LVar2 = RegQueryValueExA(local_4, nullptr, nullptr, nullptr, nullptr, &local_8);
      if ((LVar2 == 0) && (local_8 != 0)) {
        DWORD* lpcbData = &local_8;
        LPBYTE lpData = (LPBYTE)FUN_004f3050();
        RegQueryValueExA(local_4, nullptr, nullptr, nullptr, lpData, lpcbData);
        FUN_004f30a0();
      }
      RegCloseKey(local_4);
    }
    char* pcVar3 = (char*)(intptr_t)*piVar4;
    if (*(int*)(pcVar3 - 4) != 0) {
      if (*pcVar3 == '\"') {
        if (((*(int*)(pcVar3 - 4) < 2) ||
             ((pcVar3 = strchr(pcVar3 + 1, 0x22)) == nullptr)) ||
            ((intptr_t)pcVar3 - *piVar4 < 0)) goto LAB_004f41fa;
        FUN_004f1840();
      }
      else {
        if (((*(int*)(pcVar3 - 4) < 1) ||
             ((pcVar3 = strchr(pcVar3, 0x20)) == nullptr)) ||
            ((intptr_t)pcVar3 - *piVar4 < 0)) goto LAB_004f41fa;
        FUN_00476050();
      }
      FUN_00412ec0();
      FUN_00412fb0();
    }
  }
LAB_004f41fa:
  return *piVar4;
}

// 0x4f4210 — observed shape
// Computes the outer window size for the given client extent and stores
// (width, height) through out.
void FUN_004f4210(void* self, int param_1, int in_EDX, int* out)
{
  tagRECT local_10;
  local_10.bottom = param_1;
  local_10.left = 0;
  local_10.top = 0;
  local_10.right = in_EDX;
  AdjustWindowRectEx(&local_10, *(DWORD*)((char*)self + 8), 0, *(DWORD*)((char*)self + 0xc));
  out[0] = local_10.right - local_10.left;
  out[1] = local_10.bottom - local_10.top;
}

// 0x4f4260 — observed shape
// Creates a URL-scheme registration object for param_2, registers the scheme
// and switches the process working directory to it.
unsigned char FUN_004f4260(void* ebxSelf, void* esiSelf, char* param_1, char* param_2)
{
  char* pcVar1;
  char cVar2;
  HRESULT HVar3;
  HRESULT HVar4;
  int iVar5;
  DWORD DVar6;
  char* pcVar7;
  unsigned char uVar8;
  int* piVar9;
  uint32_t uStack_14 = 0;
  int* local_10 = nullptr;
  char* local_c;
  uint32_t uStack_4 = 0;

  if (param_1 == nullptr) return 0;
  if (*param_1 == '\0') return 0;
  if (param_2 == nullptr) return 0;
  if (*param_2 == '\0') return 0;

  uStack_14 = (uint32_t)(uint16_t)uStack_14;
  HVar3 = CoCreateInstance((const IID*)&DAT_006c05fc, nullptr, 1,
                           (const IID*)&DAT_006c05ec, (void**)&local_10);
  if (HVar3 < 0) {
    HVar4 = CoInitialize(nullptr);
    if (HVar4 == 0) {
      HVar3 = CoCreateInstance((const IID*)&DAT_006c05fc, nullptr, 1,
                               (const IID*)&DAT_006c05ec, (void**)&local_10);
      uStack_14 = (uStack_14 & 0x00ffffffu) | 0x01000000u;
    }
    uVar8 = 0;
    if (HVar3 < 0) goto LAB_004f4427;
  }
  local_c = DAT_008cacd0;
  (void)local_c;
  (*(void(**)(void*, char*))(uintptr_t)(*(uint32_t*)local_10 + 0x50))(local_10, param_2);
  FUN_00412f10();
  FUN_00412e50(&uStack_4);
  (*(void(**)(void*, uint32_t))(uintptr_t)(*(uint32_t*)ebxSelf + 0x1c))(ebxSelf, uStack_14);
  iVar5 = (*(int(**)(void*, uint8_t*, uint32_t*))(uintptr_t)(*(uint32_t*)esiSelf))(
      esiSelf, DAT_006c060c, &uStack_14);
  pcVar1 = (char*)(intptr_t)DAT_008caccc;
  piVar9 = local_10;
  if (-1 < iVar5) {
    if (DAT_008cacc8 < 0x104) {
      FUN_004f32e0();
      piVar9 = local_10;
    }
    DAT_008caccc = (int)(intptr_t)pcVar1;
    DVar6 = GetCurrentDirectoryA(0x104, DAT_008cacd0);
    if (DVar6 != 0) {
      pcVar1 = DAT_008cacd0;
      do {
        pcVar7 = pcVar1;
        pcVar1 = pcVar7 + 1;
      } while (*pcVar7 != '\0');
      DAT_008caccc = (int)(pcVar7 - DAT_008cacd0);
      FUN_00412e50(&DAT_0070c164);
      FUN_00412e50(&uStack_4);
      FUN_00412e50(&DAT_007105e8);
      cVar2 = FUN_004f1310();
      if (cVar2 == '\0') {
        FUN_004f3390();
        (*(void(**)(void*, char*, int))(uintptr_t)(*(uint32_t*)esiSelf + 0x18))(
            esiSelf, DAT_008cacd0, 1);
        FUN_00412c90();
      }
    }
    (*(void(**)(void*))(uintptr_t)(*(uint32_t*)esiSelf + 8))(esiSelf);
    FUN_00412fb0();
  }
  (*(void(**)(void*))(uintptr_t)(*(uint32_t*)piVar9 + 8))(piVar9);
  FUN_00412fb0();
  uVar8 = (unsigned char)(uStack_14 >> 16);
LAB_004f4427:
  if ((unsigned char)(uStack_14 >> 24) != 0) {
    CoUninitialize();
  }
  return uVar8;
}

// 0x4f4440 — observed shape
// Registers the application's shell-open command for its file extension.
bool FUN_004f4440(char* in_EAX)
{
  BYTE BVar1;
  uint32_t uVar2;
  BYTE* pBVar3;
  LSTATUS LVar4;
  BYTE* pBVar5;
  char* pCVar6;
  BYTE* pBVar7;
  bool local_21;
  HKEY local_20 = nullptr;
  BYTE* local_1c;
  BYTE* local_18;
  char* local_14;
  BYTE* local_10;
  HKEY local_c = nullptr;
  HKEY local_8 = nullptr;
  HKEY local_4 = nullptr;

  local_21 = false;
  if (in_EAX == nullptr) return false;
  if (*in_EAX == '\0') return false;
  local_14 = DAT_008cacd0;
  local_18 = (BYTE*)DAT_008cacd0;
  FUN_00412f10();
  if (*local_14 != '.') {
    FUN_004f1e40(0x2e);
  }
  FUN_00412f10();
  FUN_004f1c80();
  LVar4 = RegCreateKeyExA((HKEY)(uintptr_t)0x80000000u, local_14, 0, nullptr, 0, 2,
                          nullptr, &local_20, nullptr);
  pBVar7 = local_18;
  if (LVar4 == 0) {
    LVar4 = RegSetValueExA(local_20, nullptr, 0, 1, local_18,
                           *(DWORD*)(local_18 - 4));
    RegCloseKey(local_20);
    local_21 = false;
    if (LVar4 == 0) {
      local_21 = false;
      LVar4 = RegCreateKeyExA((HKEY)(uintptr_t)0x80000000u, (LPCSTR)pBVar7, 0, nullptr, 0, 6,
                              nullptr, &local_20, nullptr);
      if (LVar4 == 0) {
        local_10 = (BYTE*)DAT_008cacd0;
        FUN_00412f10();
        LVar4 = RegSetValueExA(local_20, nullptr, 0, 1, local_10,
                               *(DWORD*)(local_10 - 4));
        if ((LVar4 == 0) &&
            (LVar4 = RegCreateKeyExA(local_20, "shell", 0, nullptr, 0, 6, nullptr,
                                     &local_4, nullptr), LVar4 == 0)) {
          LVar4 = RegCreateKeyExA(local_4, "open", 0, nullptr, 0, 6, nullptr,
                                  &local_8, nullptr);
          if (LVar4 == 0) {
            LVar4 = RegCreateKeyExA(local_8, "command", 0, nullptr, 0, 2, nullptr,
                                    &local_c, nullptr);
            uVar2 = (uint32_t)DAT_008caccc;
            if (LVar4 == 0) {
              local_1c = (BYTE*)DAT_008cacd0;
              if (DAT_008cacc8 < 0x104) {
                FUN_004f32e0();
                *(uint32_t*)(local_1c - 4) = uVar2;
                pBVar7 = local_18;
              }
              pBVar3 = local_1c;
              GetModuleFileNameA(nullptr, (LPSTR)local_1c, 0x104);
              pBVar5 = pBVar3;
              do {
                BVar1 = *pBVar5;
                pBVar5 = pBVar5 + 1;
              } while (BVar1 != '\0');
              *(int*)(pBVar3 - 4) = (int)(pBVar5 - (pBVar3 + 1));
              FUN_00412e50(" /FXSLOAD=\"%1\"");
              LVar4 = RegSetValueExA(local_c, nullptr, 0, 2, local_1c,
                                     *(DWORD*)(local_1c - 4));
              local_21 = LVar4 == 0;
              if (local_21) {
                SHChangeNotify(0x8000000, 0, nullptr, nullptr);
              }
              RegCloseKey(local_c);
              FUN_00412fb0();
            }
            RegCloseKey(local_8);
          }
          RegCloseKey(local_4);
        }
        RegCloseKey(local_20);
        FUN_00412fb0();
      }
    }
  }
  pBVar7 = pBVar7 - 8;
  if ((pBVar7 != nullptr) && ((int*)pBVar7 != &DAT_008cacc8)) {
    operator_delete__(pBVar7);
  }
  pCVar6 = local_14 - 8;
  if ((pCVar6 != nullptr) && ((int*)pCVar6 != &DAT_008cacc8)) {
    operator_delete__(pCVar6);
  }
  return local_21;
}

// 0x4f46e0 — observed shape
// Extracts the /FXSLOAD= argument from the process command line.
void FUN_004f46e0(void)
{
  char* pcVar1;
  uint32_t* puVar2;
  int local_4 = 0;
  intptr_t offset;

  GetCommandLineA();
  FUN_00412f10();
  if ((DAT_008caccc < 1) || ((pcVar1 = strstr(DAT_008cacd0, "/FXSLOAD=")) == nullptr)) {
    offset = -1;
  }
  else {
    offset = (intptr_t)pcVar1 - (intptr_t)DAT_008cacd0;
  }
  if (offset < 0) {
    if (DAT_008caccc != 0) {
      *(uint32_t*)DAT_008cacd0 = 0;
      DAT_008caccc = 0;
    }
  }
  else {
    FUN_004f1930(&local_4, 0x22, 0x22);
    FUN_00412ec0();
    puVar2 = (uint32_t*)((uintptr_t)local_4 - 8);
    if ((puVar2 != nullptr) && (puVar2 != (uint32_t*)&DAT_008cacc8)) {
      operator_delete__(puVar2);
    }
  }
  FUN_00412df0();
}

// 0x4f47b0 — observed shape
// Derives the application directory from the module file name and makes it the
// current directory.
void FUN_004f47b0(void* self)
{
  char cVar1;
  int len;
  DWORD DVar3;
  char* pcVar4;
  uint32_t** puVar5;
  int* piVar6;
  int local_4 = 0;

  len = DAT_008caccc;
  if (DAT_008cacc8 < 0x104) {
    FUN_004f32e0();
  }
  DAT_008caccc = len;
  DVar3 = GetModuleFileNameA(*(HMODULE*)((char*)self + 0x4c), DAT_008cacd0, 0x104);
  if (DVar3 == 0) {
    if (DAT_008caccc != 0) {
      *(uint32_t*)DAT_008cacd0 = 0;
      DAT_008caccc = 0;
    }
  }
  else {
    pcVar4 = DAT_008cacd0;
    do {
      pcVar4 = pcVar4 + 1;
    } while (*(pcVar4 - 1) != '\0');
    DAT_008caccc = (int)(pcVar4 - DAT_008cacd0);
  }
  if ((DAT_008caccc - 1 < DAT_008caccc) && (DAT_008caccc - 1 >= 0)) {
    cVar1 = DAT_008cacd0[DAT_008caccc - 1];
    DAT_008cacd0[DAT_008caccc - 1] = '\0';
    pcVar4 = strrchr(DAT_008cacd0, 0x5c);
    DAT_008cacd0[DAT_008caccc - 1] = cVar1;
    if ((pcVar4 != nullptr) && ((intptr_t)pcVar4 - (intptr_t)DAT_008cacd0 >= 0)) {
      puVar5 = (uint32_t**)FUN_00476050();
      SetCurrentDirectoryA((LPCSTR)*puVar5);
      piVar6 = (int*)((uintptr_t)local_4 - 8);
      if ((piVar6 != nullptr) && (piVar6 != &DAT_008cacc8)) {
        operator_delete__(piVar6);
      }
    }
  }
}

// 0x4f48a0 — observed shape
// Registers the FXS window class and creates the main window for the
// application described by param_1.
bool FUN_004f48a0(int param_1, HINSTANCE param_2, LPCSTR param_3, uint32_t param_4,
                  uint32_t param_5, HICON param_6, HICON param_7, bool in_AL)
{
  WNDCLASSEXA local_30;
  int local_38 = 0;
  int local_34 = 0;

  for (int iVar3 = 0; iVar3 < 0xc; iVar3 = iVar3 + 1) {
    ((uint32_t*)&local_30)[iVar3] = 0;
  }
  local_30.cbSize = 0x30;
  local_30.style = 0x2b;
  local_30.lpfnWndProc = (WNDPROC)&LAB_004f49b0;
  local_30.hInstance = param_2;
  local_30.hIcon = param_6;
  local_30.hCursor = LoadCursorA(nullptr, (LPCSTR)(uintptr_t)0x7f00);
  local_30.hbrBackground = (HBRUSH)GetStockObject(4);
  local_30.lpszClassName = "WinClass_FXS";
  local_30.hIconSm = param_7;
  ATOM AVar1 = RegisterClassExA(&local_30);
  if (AVar1 != 0) {
    *(uint32_t*)((char*)(intptr_t)param_1 + 0xc) = 0x40000;
    *(uint32_t*)((char*)(intptr_t)param_1 + 8) =
        (-(uint32_t)(in_AL ? 1u : 0u) & 0x7f350000u) + 0x10cb0000u;
    // in_EDX/ESI source for the remaining FUN_004f4210 operands is not
    // preserved in the listing; the client extent is taken from param_5.
    FUN_004f4210((void*)(intptr_t)param_1, (int)(intptr_t)param_5, local_34, &local_38);
    HWND pHVar2 = CreateWindowExA(*(DWORD*)((char*)(intptr_t)param_1 + 0xc), "WinClass_FXS",
                                  param_3, *(DWORD*)((char*)(intptr_t)param_1 + 8),
                                  (int)(local_38 + (local_38 >> 0x1f & 7U)) >> 3,
                                  (int)(local_34 + (local_34 >> 0x1f & 7U)) >> 3,
                                  local_38, local_34, nullptr, nullptr, param_2, nullptr);
    *(HWND*)((char*)(intptr_t)param_1 + 0x54) = pHVar2;
    if (pHVar2 != nullptr) {
      *(HINSTANCE*)((char*)(intptr_t)param_1 + 0x4c) = param_2;
    }
  }
  return *(int*)((char*)(intptr_t)param_1 + 0x54) != 0;
}

// 0x4f4b20 — observed shape
// Serialised loader entry; resolves the path against the current application
// before running the load.
int FUN_004f4b20(void* self, char* param_1, uint32_t param_2, uint32_t param_3,
                 uint32_t param_4)
{
  int* piVar1;
  bool bVar2;
  bool bVar3;
  HANDLE hHandle;
  void* pvVar4;
  char* pcVar5;
  int iVar6;
  int iVar7;

  hHandle = DAT_00726c1c;
  if ((DAT_00726c28 == 0xffffffff) ||
      ((pvVar4 = (void*)TlsGetValue(DAT_00726c28)) == nullptr)) {
    WaitForSingleObject(hHandle, 0xffffffff);
  }
  else {
    FUN_004fac10();
  }
  iVar7 = 1;
  bVar2 = false;
  if (param_1 == nullptr) goto LAB_004f4c2a;
  if ((DAT_008cacf8 == '\0') &&
      (((pcVar5 = strchr(param_1, 0x5c)) != nullptr) ||
       ((pcVar5 = strchr(param_1, 0x2f)) != nullptr))) {
    bVar3 = false;
    iVar7 = FUN_004f0e40(param_1, param_2, param_3 | 4, param_4);
    bVar2 = true;
    if (iVar7 != 0) goto LAB_004f4bc6;
  }
  else {
    bVar3 = true;
LAB_004f4bc6:
    if (DAT_008cace0 == 0) {
LAB_004f4c46:
      if (bVar3) {
        iVar7 = FUN_004f0e40(param_1, param_2, param_3, param_4);
      }
      else {
LAB_004f4c0b:
        if (bVar2) {
          if (iVar7 == 0) goto LAB_004f4c23;
          SetLastError(2);
        }
      }
    }
    else {
      piVar1 = (int*)((char*)self + 0x28);
      iVar6 = FUN_004f5480(param_1, piVar1);
      if (iVar6 == 0) goto LAB_004f4c46;
      iVar7 = FUN_004f4c70(self, self, (unsigned char*)(intptr_t)*piVar1, param_2,
                           param_3, param_4, 0);
      if (*piVar1 != 0) {
        FUN_004f17c0();
        goto LAB_004f4c0b;
      }
    }
    if (iVar7 != 0) goto LAB_004f4c2a;
  }
LAB_004f4c23:
  DAT_008cace4 = DAT_008cace4 + 1;
LAB_004f4c2a:
  ReleaseMutex(DAT_00726c1c);
  return iVar7;
}

// 0x4f4c70 — observed shape
// Worker behind FUN_004f4b20: builds a default path when none is supplied and
// dispatches the actual load.
int FUN_004f4c70(void* eaxSelf, void* ecxSelf, unsigned char* param_1, int param_2,
                 uint32_t param_3, uint32_t param_4, char param_5)
{
  HANDLE hHandle;
  unsigned char* puVar1;
  void* pvVar2;
  uint32_t uVar3;
  void** puVar4;
  void** ppuVar5;
  int iVar6;
  int local_4 = 0;

  puVar1 = param_1;
  hHandle = DAT_00726c1c;
  if (param_5 != '\0') {
    if ((DAT_00726c28 == 0xffffffff) ||
        ((pvVar2 = (void*)TlsGetValue(DAT_00726c28)) == nullptr)) {
      WaitForSingleObject(hHandle, 0xffffffff);
    }
    else {
      FUN_004fac10();
    }
  }
  *(unsigned char**)((char*)ecxSelf + 0x28) = puVar1;
  if (puVar1 == nullptr) {
    uVar3 = FUN_004f5550();
    *(uint32_t*)((char*)ecxSelf + 0x28) = uVar3;
  }
  if (*(int*)((char*)ecxSelf + 0x28) == 0) {
    ppuVar5 = *(void***)((char*)eaxSelf + 0x10);
    if (ppuVar5 == nullptr) {
      ppuVar5 = &PTR_DAT_00726c14;
    }
    iVar6 = (int)(intptr_t)eaxSelf + 8;
    puVar4 = (void**)&param_1;
    FUN_004129c0(&local_4, ppuVar5, puVar4, (void*)(intptr_t)iVar6);
    FUN_004b1130(puVar4, (void*)(intptr_t)iVar6);
    FUN_00412ec0();
    puVar4 = (void**)(param_1 - 8);
    if ((puVar4 != nullptr) && (puVar4 != (void**)&DAT_008cacc8)) {
      operator_delete__(puVar4);
    }
    puVar4 = (void**)((uintptr_t)local_4 - 8);
    param_1 = (unsigned char*)DAT_008cacd0;
    if ((puVar4 != nullptr) && (puVar4 != (void**)&DAT_008cacc8)) {
      operator_delete__(puVar4);
    }
    iVar6 = FUN_004f0e40((const char*)param_1, param_2, param_3, param_4);
    if (iVar6 != 0) goto LAB_004f4da9;
  }
  else {
    if (param_2 != 1) {
      iVar6 = 3;
      goto LAB_004f4da9;
    }
    *(uint32_t*)((char*)ecxSelf + 0x20) = 1;
    FUN_004f17c0();
    *(int*)((char*)eaxSelf + 0x2c) = (int)(intptr_t)eaxSelf;
    iVar6 = 0;
  }
  *(int*)((char*)eaxSelf + 0x24) = *(int*)((char*)eaxSelf + 0x24) + 1;
LAB_004f4da9:
  if (param_5 != '\0') {
    if (iVar6 == 0) {
      DAT_008cace4 = DAT_008cace4 + 1;
    }
    ReleaseMutex(DAT_00726c1c);
  }
  return iVar6;
}

// 0x4f4de0 — observed shape
// Tears down the current load; releases the pending name when one is held.
uint32_t FUN_004f4de0(void* self)
{
  int* pSelf = (int*)self;
  uint32_t uVar2 = 0;
  char cVar1 = (*(char(**)(void))(uintptr_t)(*(uint32_t*)self + 0x18))();
  if (cVar1 == '\0') {
    return 0;
  }
  if (pSelf[0xb] == 0) {
    uVar2 = FUN_004f0dc0();
  }
  else {
    *(uint32_t*)(intptr_t)(pSelf[0xb] + 0x14) = 0;
    pSelf[0xb] = 0;
    pSelf[10] = 0;
    if (*(int*)((uint8_t*)(intptr_t)pSelf[7] - 4) != 0) {
      *(uint8_t*)(intptr_t)pSelf[7] = 0;
      *(uint32_t*)((uint8_t*)(intptr_t)pSelf[7] - 4) = 0;
      InterlockedDecrement(&DAT_008cace4);
      return 0;
    }
  }
  InterlockedDecrement(&DAT_008cace4);
  return uVar2;
}

// 0x4f4e80 — observed shape
// Suspends the loader thread (or its global equivalent).
void FUN_004f4e80(void* self)
{
  if (*(int*)((char*)self + 0x2c) == 0) {
    FUN_004f1220();
    return;
  }
  FUN_004fe220();
}

// 0x4f4ea0 — observed shape
// Resumes the loader thread (or its global equivalent).
void FUN_004f4ea0(void* self, uint32_t param_1)
{
  if (*(int*)((char*)self + 0x2c) == 0) {
    FUN_004f10f0();
    return;
  }
  FUN_004fe190(param_1);
}

// 0x4f4ed0 — observed shape
// Probes the given path, resolving it through the application when it is a
// relative or explicitly rooted path.
char FUN_004f4ed0(char* unaff_ESI)
{
  bool bVar1;
  char extraout_AL;
  char cVar2;
  char* pcVar3;
  int iVar4;

  if ((DAT_008cacf8 == '\0') &&
      (((pcVar3 = strchr(unaff_ESI, 0x5c)) != nullptr) ||
       ((pcVar3 = strchr(unaff_ESI, 0x2f)) != nullptr))) {
    bVar1 = false;
    extraout_AL = FUN_004f1310();
    if (extraout_AL != '\0') {
      return extraout_AL;
    }
  }
  else {
    bVar1 = true;
  }
  if ((DAT_008cace0 != 0) && ((iVar4 = FUN_004f5480()) != 0)) {
    return '\x01';
  }
  if (bVar1) {
    cVar2 = FUN_004f1310();
    return cVar2;
  }
  return '\0';
}
