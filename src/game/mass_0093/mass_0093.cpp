//
// mass_0093.cpp — reconstruction batch mass_0093
// Target: Sid Meier's Pirates! (2004), PE32 i386
// Image: 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
//
// Each definition preserves the observed field offsets, constants, call
// order, return shape, and conditional structure of the Ghidra 12.2
// pseudocode in analysis/pseudocode/functions/*.c.
//
// This family is FLandscape: a grid of terrain cells (row array at self+0x08,
// dims at self+0x74/0x78, cell pitch at self+0x7c/0x80, terrain extents at
// self+0x6c/0x70), four owned terrain buffers at self+0x54..0x60, a resource
// table at self+0x64, an optional terrain-material object at self+0x68, a
// reference-counted device/asset object at self+0x04, a global 256-entry
// material registry at DAT_008ea110, and flag bytes at self+0x14 and
// self+0xa0..0xa8. Register receivers (in_ECX / in_ESI / in_EDI / in_EBX /
// in_EAX) are modeled as explicit parameters.
//
#include <cstdint>
#include <cstddef>
#include <cstdarg>
#include <windows.h>

// ---------------------------------------------------------------------------
// External helpers and globals referenced by the assigned listings only.
// ---------------------------------------------------------------------------
extern "C" int sprintf(char* buffer, const char* format, ...);
extern "C" char* strtok(char* text, const char* delimiters);
extern "C" char* strrchr(const char* text, int ch);
extern "C" int _stricmp(const char* lhs, const char* rhs);

void     operator_delete(void* ptr);
void     operator_delete__(void* ptr);
void*    FUN_00533c78(int32_t size);
void*    thunk_FUN_00533c78(int32_t size);
uint32_t FUN_004f8e40(void* varargs);
void*    FUN_0053bb30(uint32_t param);
uint32_t FUN_0051a830(const char* name);
uint32_t FUN_004ee430();
uint32_t FUN_00513ed0();
uint32_t FUN_004ee3c0();
uint32_t FUN_00513e60();
uint32_t FUN_00515c30();
void     FUN_00519610(void* self, uintptr_t value);
void     FUN_00513e20();
void     FUN_00519a90(void* object);
void     FUN_0051ab30(void* object);
void     FUN_004e6420(void* object);
void     FUN_00513b00(void* object);
void     FUN_00518d30();
void     FUN_00500c60();
void     FUN_00534130();
void*    FUN_005428c0();
void*    FUN_005426d0();
void     FUN_005606f0(uint32_t index, int32_t* out);
void     FUN_00540460(const char* name);
void*    FUN_00500850();
void     FUN_004aad70(void* object);
void*    FUN_0054aad0();
void     FUN_00513dc0();
void     FUN_005200b0(void* sync);
void     FUN_00520190(void* sync);
void*    FUN_0051ffd0();
void     FUN_005198f0(uint32_t table, int32_t index, void* value);
void     FUN_00519580(int32_t index);
void     FUN_00513d20(uint32_t value);
void     FUN_00513d50(uint32_t value);
void     FUN_00519ae0(uint32_t table);
uint32_t FUN_00513d90();
void     FUN_00533d10(uint32_t a, uint32_t b);
uint32_t FUN_004edfd0();
void     FUN_00513ca0(uint32_t col);
int32_t  FUN_00512b00(int32_t row, int32_t col, uint32_t width, uint32_t height);
void     FUN_00512d70(int32_t row, int32_t col);
void     FUN_00513c00(void* self, void* value);

// Intra-batch members used ahead of their definitions in address order.
uint32_t FUN_005122b0(uint8_t* self, void* param_1);
uint32_t FUN_00512330(uint8_t* self, uint32_t param_2, uint32_t param_3,
                      uint32_t param_4, uint32_t param_5);
void     FUN_00512240(uint8_t* self, uint8_t enable);
uint32_t FUN_005129a0(uint32_t* self, uint32_t row, uint32_t col);

extern uint32_t DAT_008cacf0;
extern uint32_t DAT_008cace8;
extern uint32_t DAT_008cacec;
extern uint32_t DAT_008cad2c;
extern void*    DAT_008cad28;
extern uint32_t DAT_008ea110[0x100];
extern uint32_t DAT_008ca53c;
extern uint32_t DAT_008eddf8;
extern uint32_t DAT_008edcc0;
extern uint32_t _DAT_008edf28;
extern uint32_t _DAT_008edf20;
extern uint32_t DAT_008edf1c;
extern uint32_t _DAT_008eddf0;
extern uint32_t _DAT_008edde8;
extern uint32_t DAT_008edde4;
extern uint32_t PTR_FUN_00711868;
extern uint32_t PTR_FUN_00711860;
extern uint32_t PTR_FUN_0071274c;
extern uint32_t PTR_FUN_00712730;
extern void*    PTR_FUN_00717a84;

// ---------------------------------------------------------------------------
// Shared release idiom observed throughout this family: decrement the
// reference count stored at object[1]; when it reaches zero, invoke the
// virtual destructor through vtable[0] with the deleting flag 1.
// ---------------------------------------------------------------------------
typedef void (*DeletingDtor)(void* self, int32_t flags);

static void release_ref(uint32_t* object)
{
  if (object == nullptr) {
    return;
  }
  int32_t* refcount = reinterpret_cast<int32_t*>(object + 1);
  *refcount = *refcount - 1;
  if (*refcount == 0) {
    DeletingDtor dtor = *reinterpret_cast<DeletingDtor*>(*object);
    dtor(object, 1);
  }
}

// 0x5118c0 — observed shape
// The gate reads the log-enable word DAT_008cacf0 and a recursion guard
// carried in EAX; the variadic tail is forwarded by address to the
// printf-style worker (the listing collapses it to `&param_2`).
uint32_t FUN_005118c0(uint32_t in_EAX, const char* param_1, ...)
{
  (void)param_1;

  if ((DAT_008cacf0 == 0) ||
      ((in_EAX != 0 && (DAT_008cace8 == 0 && DAT_008cacec == 0)))) {
    return 0;
  }
  va_list ap;
  va_start(ap, param_1);
  uint32_t uVar1 = FUN_004f8e40(reinterpret_cast<void*>(ap));
  va_end(ap);
  return uVar1;
}

// 0x511900 — observed shape
// Object constructor: installs the vtable and clears the whole member block.
void FUN_00511900(uint32_t* self)
{
  self[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00711868);
  self[1] = 0;
  self[2] = 0;
  *reinterpret_cast<uint8_t*>(self + 5) = 0;         // +0x14
  self[0x15] = 0;                                    // +0x54
  self[0x16] = 0;                                    // +0x58
  self[0x17] = 0;                                    // +0x5c
  self[0x18] = 0;                                    // +0x60
  self[0x19] = 0;                                    // +0x64
  self[0x1a] = 0;                                    // +0x68
  self[0x1b] = 0;                                    // +0x6c
  self[0x1c] = 0;                                    // +0x70
  self[0x1d] = 0;                                    // +0x74
  self[0x1e] = 0;                                    // +0x78
  self[0x1f] = 0;                                    // +0x7c
  self[0x20] = 0;                                    // +0x80
  self[0x21] = 0;                                    // +0x84
  self[0x22] = 0;                                    // +0x88
  self[0x23] = 0;                                    // +0x8c
  self[0x24] = 0x3f800000u;                          // +0x90 = 1.0f
  self[0x25] = 0x3f800000u;                          // +0x94 = 1.0f
  self[0x26] = 0;                                    // +0x98
  self[0x27] = 0;                                    // +0x9c
  *reinterpret_cast<uint8_t*>(self + 0x28) = 0;      // +0xa0
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0xa1) = 0;
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0xa2) = 0;
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0xa3) = 0;
  *reinterpret_cast<uint8_t*>(self + 0x29) = 0;      // +0xa4
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0xa6) = 0;
  self[0x2a] = 0;                                    // +0xa8
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0xa5) = 1;
}

// 0x5119c0 — observed shape
// Destructor: reinstalls the vtable, releases the refcounted member at +0x04,
// and optionally frees the object itself.
void FUN_005119c0(uint32_t* self, uint8_t param_1)
{
  self[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00711868);
  uint32_t* puVar2 = reinterpret_cast<uint32_t*>(self[1]);
  release_ref(puVar2);
  if ((param_1 & 1) != 0) {
    operator_delete(self);
  }
}

// 0x511a00 — observed shape
// Initialiser: stores the configuration words, binds a fresh refcounted
// device object, builds the "%s.BHI" resource name, selects the terrain
// provider from the format code, then either loads the file by name or
// delegates to the grid loader.
int32_t FUN_00511a00(uint8_t* self, char* param_1, uint32_t param_2,
                     void* param_3, void* param_4, uint32_t param_5,
                     uint32_t param_6, uint32_t param_7, uint32_t param_8,
                     uint32_t param_9, uint32_t* param_10, uint32_t* param_11,
                     uint32_t param_12, uint32_t param_13, char param_14,
                     uint8_t param_15)
{
  int32_t iVar4;
  uint32_t uVar6;
  uint32_t* puVar3;
  uint32_t* puVar5;
  char acStack_100[256];

  *reinterpret_cast<uint32_t*>(self + 0x10) = param_13;
  *reinterpret_cast<uint32_t*>(self + 0x84) = param_5;
  *reinterpret_cast<uint32_t*>(self + 0x88) = param_6;
  *reinterpret_cast<uint32_t*>(self + 0x8c) = param_7;
  *reinterpret_cast<uint32_t*>(self + 0x7c) = param_8;
  *reinterpret_cast<uint32_t*>(self + 0x0c) = param_12;
  *reinterpret_cast<uint32_t*>(self + 0x80) = param_9;
  *reinterpret_cast<char*>(self + 0xa1) = param_14;
  *reinterpret_cast<uint8_t*>(self + 0xa2) = param_15;

  iVar4 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_00533c78(0xec)));
  if (iVar4 == 0) {
    puVar5 = nullptr;
  } else {
    puVar5 = reinterpret_cast<uint32_t*>(FUN_0053bb30(0));
  }
  puVar3 = *reinterpret_cast<uint32_t**>(self + 4);
  if (puVar3 != puVar5) {
    if (puVar3 != nullptr) {
      release_ref(puVar3);
    }
    *reinterpret_cast<uint32_t**>(self + 4) = puVar5;
    if (puVar5 != nullptr) {
      puVar5[1] = puVar5[1] + 1;
    }
  }

  iVar4 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_00533c78(0x10)));
  if (iVar4 == 0) {
    uVar6 = 0;
  } else {
    sprintf(acStack_100, "%s.BHI", static_cast<const char*>(param_4));
    uVar6 = FUN_0051a830(acStack_100);
  }
  *reinterpret_cast<uint32_t*>(self + 100) = uVar6;

  if (*reinterpret_cast<int32_t*>(self + 0xa8) == 0) {
    switch (param_12) {
    case 0:
      uVar6 = FUN_004ee430();
      break;
    case 1:
      uVar6 = FUN_00513ed0();
      break;
    case 2:
      uVar6 = FUN_004ee3c0();
      break;
    case 3:
      uVar6 = FUN_00513e60();
      break;
    default:
      goto switchD_00511afd_default;
    }
    *reinterpret_cast<uint32_t*>(self + 0xa8) = uVar6;
  }
switchD_00511afd_default:
  *reinterpret_cast<uint8_t*>(self + 0xa0) = 0;

  if (param_14 == '\0') {
    iVar4 = static_cast<int32_t>(FUN_005122b0(self, param_1));
    if (iVar4 != 0) {
      return iVar4;
    }
    if (DAT_008cad2c == 0) {
      DAT_008cad2c = FUN_00515c30();
    }
    FUN_00519610(self, reinterpret_cast<uintptr_t>(param_1));
    FUN_00519610(self, reinterpret_cast<uintptr_t>(param_3));
    FUN_00519610(self, reinterpret_cast<uintptr_t>(param_4));
  } else {
    iVar4 = static_cast<int32_t>(
        FUN_00512330(self, reinterpret_cast<uintptr_t>(param_1), param_2,
                     reinterpret_cast<uintptr_t>(param_3),
                     reinterpret_cast<uintptr_t>(param_4)));
    if (iVar4 != 0) {
      return iVar4;
    }
    *reinterpret_cast<uint32_t*>(self + 0x74) =
        static_cast<uint32_t>(*reinterpret_cast<int32_t*>(self + 0x7c) + -3 +
                              *reinterpret_cast<int32_t*>(self + 0x6c)) /
        (static_cast<uint32_t>(*reinterpret_cast<int32_t*>(self + 0x7c)) - 1u);
    *reinterpret_cast<uint32_t*>(self + 0x78) =
        static_cast<uint32_t>(*reinterpret_cast<int32_t*>(self + 0x80) + -3 +
                              *reinterpret_cast<int32_t*>(self + 0x70)) /
        (static_cast<uint32_t>(*reinterpret_cast<int32_t*>(self + 0x80)) - 1u);
  }

  if (*reinterpret_cast<char*>(self + 0x14) == '\0') {
    intptr_t iVar4neg = -reinterpret_cast<intptr_t>(param_1);
    char cVar2;
    char* pcVar8 = param_1;
    do {
      cVar2 = *pcVar8;
      pcVar8[iVar4neg] = cVar2;
      pcVar8 = pcVar8 + 1;
    } while (cVar2 != '\0');
    char* _Str = strtok(acStack_100, ".");
    char* pcVar7 = strrchr(_Str, 0x5c);
    if (pcVar7 != nullptr) {
      strrchr(_Str, 0x5c);
    }
    FUN_00513e20();
  }

  *param_10 = *reinterpret_cast<uint32_t*>(self + 0x74);
  *param_11 = *reinterpret_cast<uint32_t*>(self + 0x78);
  return 0;
}

// 0x511c80 — observed shape
// Full teardown: frees every terrain cell and each row, drops the device
// object, releases or frees the four terrain buffers (depending on the
// ownership flag at +0xa1), destroys the +0x64 resource table and the +0x68
// material object.
uint32_t FUN_00511c80(uint8_t* self)
{
  uint32_t uVar5;
  uint32_t uVar6;
  int32_t iVar2;
  void* pvVar3;
  uint32_t* puVar4;

  if (*reinterpret_cast<int32_t*>(self + 8) != 0) {
    if (*reinterpret_cast<int32_t*>(self + 0x74) != 0) {
      uVar6 = 0;
      do {
        uVar5 = 0;
        if (*reinterpret_cast<int32_t*>(self + 0x78) != 0) {
          do {
            iVar2 = *reinterpret_cast<int32_t*>(
                *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(self + 8) +
                                            uVar6 * 4) +
                uVar5 * 4);
            if (iVar2 != 0) {
              FUN_005129a0(
                  reinterpret_cast<uint32_t*>(self),
                  *reinterpret_cast<uint32_t*>(iVar2 + 0x24) /
                      (static_cast<uint32_t>(*reinterpret_cast<int32_t*>(self + 0x7c)) - 1u),
                  uVar5);  // column carried in EBX at this call site
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 < *reinterpret_cast<uint32_t*>(self + 0x78));
        }
        pvVar3 = *reinterpret_cast<void**>(
            *reinterpret_cast<int32_t*>(self + 8) + uVar6 * 4);
        if (pvVar3 != nullptr) {
          operator_delete__(pvVar3);
          *reinterpret_cast<uint32_t*>(*reinterpret_cast<int32_t*>(self + 8) +
                                        uVar6 * 4) = 0;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < *reinterpret_cast<uint32_t*>(self + 0x74));
    }
    if (*reinterpret_cast<void**>(self + 8) != nullptr) {
      operator_delete__(*reinterpret_cast<void**>(self + 8));
      *reinterpret_cast<uint32_t*>(self + 8) = 0;
    }
  }

  if (*reinterpret_cast<int32_t*>(self + 4) != 0) {
    *reinterpret_cast<uint32_t*>(*reinterpret_cast<int32_t*>(self + 4) + 0x24) = 0;
    puVar4 = *reinterpret_cast<uint32_t**>(self + 4);
    if (puVar4 != nullptr) {
      release_ref(puVar4);
      *reinterpret_cast<uint32_t*>(self + 4) = 0;
    }
  }

  pvVar3 = *reinterpret_cast<void**>(self + 0x58);
  if (*reinterpret_cast<char*>(self + 0xa1) == '\0') {
    if (pvVar3 != nullptr) {
      FUN_00519a90(pvVar3);
    }
    if (*reinterpret_cast<int32_t*>(self + 0x54) != 0) {
      FUN_00519a90(*reinterpret_cast<void**>(self + 0x54));
    }
    if (*reinterpret_cast<int32_t*>(self + 0x5c) != 0) {
      FUN_00519a90(*reinterpret_cast<void**>(self + 0x5c));
    }
    if (*reinterpret_cast<int32_t*>(self + 0x60) != 0) {
      FUN_00519a90(*reinterpret_cast<void**>(self + 0x60));
    }
  } else {
    if (pvVar3 != nullptr) {
      operator_delete__(pvVar3);
      *reinterpret_cast<uint32_t*>(self + 0x58) = 0;
    }
    if (*reinterpret_cast<void**>(self + 0x54) != nullptr) {
      operator_delete__(*reinterpret_cast<void**>(self + 0x54));
      *reinterpret_cast<uint32_t*>(self + 0x54) = 0;
    }
    if (*reinterpret_cast<void**>(self + 0x5c) != nullptr) {
      operator_delete__(*reinterpret_cast<void**>(self + 0x5c));
      *reinterpret_cast<uint32_t*>(self + 0x5c) = 0;
    }
    if (*reinterpret_cast<void**>(self + 0x60) != nullptr) {
      operator_delete__(*reinterpret_cast<void**>(self + 0x60));
      *reinterpret_cast<uint32_t*>(self + 0x60) = 0;
    }
  }

  puVar4 = *reinterpret_cast<uint32_t**>(self + 100);
  if (puVar4 != nullptr) {
    FUN_0051ab30(puVar4);
    *puVar4 = reinterpret_cast<uint32_t>(&PTR_FUN_0071274c);
    FUN_004e6420(puVar4);
    *puVar4 = reinterpret_cast<uint32_t>(&PTR_FUN_00712730);
    FUN_004e6420(puVar4);
    operator_delete__(reinterpret_cast<void*>(puVar4[2]));
    operator_delete(puVar4);
    *reinterpret_cast<uint32_t*>(self + 100) = 0;
  }

  pvVar3 = *reinterpret_cast<void**>(self + 0x68);
  if (pvVar3 != nullptr) {
    FUN_00513b00(pvVar3);
    puVar4 = *reinterpret_cast<uint32_t**>(reinterpret_cast<uint8_t*>(pvVar3) + 0xc);
    release_ref(puVar4);
    operator_delete(pvVar3);
    *reinterpret_cast<uint32_t*>(self + 0x68) = 0;
  }
  return 0;
}

// 0x511e50 — observed shape
// Global shutdown: tears down two subsystems, frees the shared render-state
// object and releases every registry entry up to DAT_008ea510.
uint32_t FUN_00511e50(void)
{
  FUN_00518d30();
  FUN_00500c60();
  if (DAT_008cad28 != nullptr) {
    operator_delete(DAT_008cad28);
    DAT_008cad28 = nullptr;
  }
  uint32_t* piVar3 = DAT_008ea110;
  do {
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(*piVar3);
    if (puVar2 != nullptr) {
      release_ref(puVar2);
      *piVar3 = 0;
    }
    piVar3 = piVar3 + 1;
  } while (reinterpret_cast<intptr_t>(piVar3) < 0x8ea510);
  return 0;
}

// 0x511eb0 — observed shape
// Clears the 256-entry material registry and lazily recreates the shared
// render-state object when it is missing.
void FUN_00511eb0(void)
{
  uint32_t uVar3;

  uVar3 = 0;
  do {
    uint32_t* puVar2 = *reinterpret_cast<uint32_t**>(
        reinterpret_cast<uint8_t*>(DAT_008ea110) + uVar3);
    if (puVar2 != nullptr) {
      release_ref(puVar2);
      *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(DAT_008ea110) +
                                    uVar3) = 0;
    }
    uVar3 = uVar3 + 4;
  } while (uVar3 < 0x400);

  if (DAT_008cad28 == nullptr) {
    DAT_008cad28 = FUN_00533c78(4);
    if (DAT_008cad28 != nullptr) {
      *reinterpret_cast<uint32_t*>(DAT_008cad28) =
          reinterpret_cast<uint32_t>(&PTR_FUN_00711860);
      return;
    }
    DAT_008cad28 = nullptr;
  }
}

// 0x511f10 — observed shape
// Pushes every occupied terrain cell's material index and value into the
// per-cell material object, then flushes the batch.
void FUN_00511f10(uint8_t* self)
{
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t uVar2;
  int32_t iVar1;
  int32_t iVar5;
  int32_t cell;

  if (*reinterpret_cast<int32_t*>(self + 8) == 0) {
    return;
  }
  uVar4 = 0;
  if (*reinterpret_cast<int32_t*>(self + 0x74) != 0) {
    do {
      uVar3 = 0;
      if (*reinterpret_cast<int32_t*>(self + 0x78) != 0) {
        do {
          iVar5 = 0;
          do {
            cell = *reinterpret_cast<int32_t*>(
                *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(self + 8) +
                                            uVar4 * 4) +
                uVar3 * 4);
            if ((cell != 0) && (DAT_008ea110[iVar5] != 0)) {
              int32_t iVar6 =
                  *reinterpret_cast<int32_t*>(DAT_008ea110[iVar5] + 0x2c);
              iVar1 = iVar6 == 0 ? 0 : *reinterpret_cast<int32_t*>(iVar6);
              if (iVar1 == 0) {
                uVar2 = 0;
              } else {
                uVar2 = *reinterpret_cast<uint32_t*>(iVar1 + 4);
              }
              typedef void (*CellMaterialFn)(void* self, int32_t index,
                                             uint32_t value);
              CellMaterialFn fn =
                  *reinterpret_cast<CellMaterialFn*>(*reinterpret_cast<int32_t*>(cell) + 0x18);
              fn(reinterpret_cast<void*>(cell), iVar5, uVar2);
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 < 0x100);
          uVar3 = uVar3 + 1;
        } while (uVar3 < *reinterpret_cast<uint32_t*>(self + 0x78));
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *reinterpret_cast<uint32_t*>(self + 0x74));
  }
  FUN_00534130();
}

// 0x511f90 — observed shape
// Lazily creates the registry entry for slot param_1, marks it loaded, and
// hands the ".dds"-suffixed texture name to the asset layer.
uint32_t FUN_00511f90(char* in_EAX, int32_t param_1)
{
  int32_t iVar3;
  int32_t iVar5;
  uint32_t* puVar4;
  uint32_t* puVar7;
  char cVar2;

  iVar5 = param_1;
  if (DAT_008ea110[param_1] == 0) {
    iVar3 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_00533c78(0x48)));
    if (iVar3 == 0) {
      puVar4 = nullptr;
    } else {
      puVar4 = reinterpret_cast<uint32_t*>(FUN_005428c0());
    }
    puVar7 = reinterpret_cast<uint32_t*>(DAT_008ea110[iVar5]);
    if (puVar7 != puVar4) {
      if (puVar7 != nullptr) {
        release_ref(puVar7);
      }
      DAT_008ea110[iVar5] = reinterpret_cast<uint32_t>(puVar4);
      if (puVar4 != nullptr) {
        puVar4[1] = puVar4[1] + 1;
      }
    }
    int32_t iVar6 = *reinterpret_cast<int32_t*>(DAT_008ea110[iVar5] + 0x2c);
    iVar5 = iVar6 == 0 ? 0 : *reinterpret_cast<int32_t*>(iVar6);
    if (iVar5 == 0) {
      iVar5 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_00533c78(0x1c)));
      if (iVar5 == 0) {
        iVar5 = 0;
      } else {
        iVar5 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_005426d0()));
      }
      param_1 = iVar5;
      FUN_005606f0(0, &param_1);
    }
    *reinterpret_cast<uint32_t*>(iVar5 + 0xc) = 2;
    FUN_00540460(in_EAX);
  }

  char* pcVar6 = in_EAX;
  do {
    cVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar2 != '\0');
  // The folded offset in the listing is pcVar6 - 5: the last four characters
  // immediately before the terminator, compared case-insensitively.
  _stricmp(pcVar6 - 5, ".dds");

  puVar7 = reinterpret_cast<uint32_t*>(FUN_00500850());
  puVar4 = nullptr;
  if (puVar7 != nullptr) {
    puVar7[1] = puVar7[1] + 1;
    puVar4 = puVar7;
  }
  FUN_004aad70(puVar4);
  release_ref(puVar4);
  return 0;
}

// 0x5120c0 — observed shape
// Same lazy registry creation as 0x511f90, but the caller supplies the
// already-built texture object; the index arrives in EBX.
uint32_t FUN_005120c0(uint32_t param_1, int32_t in_ECX, int32_t in_EBX)
{
  int32_t iStack_4;
  int32_t iVar3;
  uint32_t* puVar2;
  uint32_t* puVar4;

  iStack_4 = in_ECX;
  if (DAT_008ea110[in_EBX] == 0) {
    iVar3 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_00533c78(0x48)));
    if (iVar3 == 0) {
      puVar4 = nullptr;
    } else {
      puVar4 = reinterpret_cast<uint32_t*>(FUN_005428c0());
    }
    puVar2 = reinterpret_cast<uint32_t*>(DAT_008ea110[in_EBX]);
    if (puVar2 != puVar4) {
      if (puVar2 != nullptr) {
        release_ref(puVar2);
      }
      DAT_008ea110[in_EBX] = reinterpret_cast<uint32_t>(puVar4);
      if (puVar4 != nullptr) {
        puVar4[1] = puVar4[1] + 1;
      }
    }
    int32_t iVar5 = *reinterpret_cast<int32_t*>(DAT_008ea110[in_EBX] + 0x2c);
    iVar3 = iVar5 == 0 ? 0 : *reinterpret_cast<int32_t*>(iVar5);
    if (iVar3 == 0) {
      iVar3 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_00533c78(0x1c)));
      if (iVar3 == 0) {
        iVar3 = 0;
      } else {
        iVar3 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_005426d0()));
      }
      iStack_4 = iVar3;
      FUN_005606f0(0, &iStack_4);
    }
    *reinterpret_cast<uint32_t*>(iVar3 + 0xc) = 2;
  }
  FUN_004aad70(param_1);
  return 0;
}

// 0x512180 — observed shape
// Builds the terrain-material object at +0x68 (dimensions from param_3),
// frees any previous one and rebinds the cell materials.
uint32_t FUN_00512180(uint32_t* self, void* param_2, uint32_t param_3)
{
  int32_t* piVar4;
  uint32_t* puVar2;
  void* pvVar3;
  uint8_t unaff_BL = 0;  // the enable byte carried in BL is not materialised

  piVar4 = reinterpret_cast<int32_t*>(FUN_00533c78(0x14));
  if (piVar4 == nullptr) {
    piVar4 = nullptr;
  } else {
    piVar4[3] = 0;
    piVar4[0] = static_cast<int32_t>(reinterpret_cast<intptr_t>(self));
    piVar4[4] = static_cast<int32_t>(param_3);
    piVar4[1] = 0;
    puVar2 = reinterpret_cast<uint32_t*>(piVar4[3]);
    if (puVar2 != nullptr) {
      release_ref(puVar2);
      piVar4[3] = 0;
    }
    piVar4[2] = 0;
  }

  pvVar3 = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(self) + 0x68);
  if (pvVar3 != nullptr) {
    FUN_00513b00(pvVar3);
    puVar2 = *reinterpret_cast<uint32_t**>(reinterpret_cast<uint8_t*>(pvVar3) + 0xc);
    release_ref(puVar2);
    operator_delete(pvVar3);
    *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x68) = 0;
  }
  *reinterpret_cast<int32_t**>(reinterpret_cast<uint8_t*>(self) + 0x68) = piVar4;

  if (*reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(self) + 0xa1) == '\0') {
    FUN_00519610(self, reinterpret_cast<uintptr_t>(param_2));
    FUN_00512240(reinterpret_cast<uint8_t*>(self), unaff_BL);
    return 0;
  }
  FUN_00513c00(piVar4, param_2);
  FUN_00512240(reinterpret_cast<uint8_t*>(self), unaff_BL);
  return 0;
}

// 0x512240 — observed shape
// Rebinds every terrain cell's material source: zero detaches, non-zero
// attaches the object at +0x68. The flag is also stored at +0xa3.
void FUN_00512240(uint8_t* self, uint8_t enable)
{
  uint32_t uVar2;
  uint32_t uVar3;
  int32_t iVar1;
  int32_t* cell;
  int32_t iVar4;

  *reinterpret_cast<char*>(self + 0xa3) = static_cast<char>(enable);
  if ((*reinterpret_cast<int32_t*>(self + 8) != 0) &&
      (uVar2 = 0, *reinterpret_cast<int32_t*>(self + 0x74) != 0)) {
    do {
      uVar3 = 0;
      if (*reinterpret_cast<int32_t*>(self + 0x78) != 0) {
        do {
          iVar1 = *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(self + 8) +
                                              uVar2 * 4);
          cell = *reinterpret_cast<int32_t**>(iVar1 + uVar3 * 4);
          if (cell != nullptr) {
            typedef void (*CellAttachFn)(void* self, int32_t owner);
            if (enable == '\0') {
              CellAttachFn fn =
                  *reinterpret_cast<CellAttachFn*>(*cell + 8);
              fn(cell, 0);
            } else {
              iVar4 = *reinterpret_cast<int32_t*>(self + 0x68);
              CellAttachFn fn =
                  *reinterpret_cast<CellAttachFn*>(*cell + 8);
              fn(cell, iVar4);
            }
          }
          uVar3 = uVar3 + 1;
        } while (uVar3 < *reinterpret_cast<uint32_t*>(self + 0x78));
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *reinterpret_cast<uint32_t*>(self + 0x74));
  }
}

// 0x5122b0 — observed shape
// Loads the terrain header through the asset interface and derives the cell
// grid dimensions from the returned extents.
uint32_t FUN_005122b0(uint8_t* self, void* param_1)
{
  uint8_t local_2d;
  uint8_t local_2c[4];
  uint8_t local_28[4];
  uint8_t local_24[36];
  uint8_t* puVar3;
  uint8_t* puVar4;
  int32_t* piVar2;
  char cVar1;

  FUN_00513dc0();
  piVar2 = reinterpret_cast<int32_t*>(FUN_0054aad0());
  puVar4 = &local_2d;
  puVar3 = local_24;
  typedef char (*LoadTerrainFn)(void* self, void* name, void* out1, void* out2,
                                void* out3, void* out4);
  LoadTerrainFn fn = *reinterpret_cast<LoadTerrainFn*>(*piVar2 + 4);
  cVar1 = fn(piVar2, param_1, puVar3, puVar4, local_2c, local_28);
  if (cVar1 == '\0') {
    return 9;
  }

  *reinterpret_cast<uint8_t**>(self + 0x6c) = puVar3;
  *reinterpret_cast<uint8_t**>(self + 0x70) = puVar4;
  *reinterpret_cast<uint32_t*>(self + 0x74) =
      static_cast<uint32_t>(reinterpret_cast<intptr_t>(puVar3) +
                            *reinterpret_cast<int32_t*>(self + 0x7c) - 3) /
      (static_cast<uint32_t>(*reinterpret_cast<int32_t*>(self + 0x7c)) - 1u);
  *reinterpret_cast<uint32_t*>(self + 0x78) =
      static_cast<uint32_t>(reinterpret_cast<intptr_t>(puVar4) +
                            *reinterpret_cast<int32_t*>(self + 0x80) - 3) /
      (static_cast<uint32_t>(*reinterpret_cast<int32_t*>(self + 0x80)) - 1u);
  return 0;
}

// 0x512330 — observed shape
// Loads the four terrain payload files, copies each into a freshly allocated
// buffer at +0x54/+0x58/+0x5c/+0x60, records the extents from the last load,
// and reports a load failure through the error callback (return 0xd).
uint32_t FUN_00512330(uint8_t* self, uint32_t param_2, uint32_t param_3,
                      uint32_t param_4, uint32_t param_5)
{
  char cVar2;
  uint32_t uVar3;
  bool bVar4;
  char* pcVar5;
  int32_t iVar6;
  int32_t* piVar7;
  uint32_t* puVar8;
  uint32_t* puVar9;
  uint32_t uVar10;
  uint32_t uVar11;
  uint32_t uVar12;
  uint32_t* puVar13;
  uint32_t local_220[4];
  int32_t local_210[4];
  char acStack_200[512];

  if ((_DAT_008edf28 & 1) == 0) {
    _DAT_008edf28 = _DAT_008edf28 | 1;
    pcVar5 = const_cast<char*>("FLandscape::LoadFileData");
    do {
      cVar2 = *pcVar5;
      // Copies the literal text into the adjacent .data buffer at +0x1dc48c.
      pcVar5[0x1dc48c] = cVar2;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    _DAT_008edf20 = 0xffffffff;
    DAT_008edf1c = 0;
  }

  if (DAT_008ca53c == 0) {
    iVar6 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_00533c78(0x70)));
    if (iVar6 == 0) {
      DAT_008ca53c = 0;
    } else {
      DAT_008ca53c = reinterpret_cast<uint32_t>(FUN_0051ffd0());
    }
  }
  FUN_005200b0(&DAT_008eddf8);
  piVar7 = reinterpret_cast<int32_t*>(FUN_0054aad0());

  local_210[0] = static_cast<int32_t>(reinterpret_cast<intptr_t>(self + 0x54));
  local_210[1] = static_cast<int32_t>(reinterpret_cast<intptr_t>(self + 0x58));
  local_210[2] = static_cast<int32_t>(reinterpret_cast<intptr_t>(self + 0x5c));
  local_210[3] = static_cast<int32_t>(reinterpret_cast<intptr_t>(self + 0x60));
  local_220[0] = param_2;
  local_220[1] = param_3;
  bVar4 = false;
  local_220[2] = param_4;
  local_220[3] = param_5;
  uVar12 = 0;
  puVar13 = nullptr;
  do {
    uVar3 = *reinterpret_cast<uint32_t*>(
        reinterpret_cast<uint8_t*>(local_220) + uVar12);
    typedef void* (*LoadAssetFn)(void* self, uint32_t name, uint32_t flags);
    LoadAssetFn load = *reinterpret_cast<LoadAssetFn*>(*piVar7 + 8);
    puVar8 = reinterpret_cast<uint32_t*>(load(piVar7, uVar3, 0));
    if (puVar13 == puVar8) {
LAB_00512437:
      puVar8 = puVar13;
      if (puVar8 == nullptr) {
        goto LAB_00512473;
      }
      puVar9 = reinterpret_cast<uint32_t*>(
          thunk_FUN_00533c78(reinterpret_cast<int32_t*>(puVar8[0x10])[1] -
                             *reinterpret_cast<int32_t*>(puVar8[0x10])));
      uint32_t* dest_slot = reinterpret_cast<uint32_t*>(
          *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(local_210) + uVar12));
      *dest_slot = reinterpret_cast<uint32_t>(puVar9);
      iVar6 = *reinterpret_cast<int32_t*>(puVar8[0x10]);
      uVar10 = static_cast<uint32_t>(
          reinterpret_cast<int32_t*>(puVar8[0x10])[1] - iVar6);
      puVar13 = reinterpret_cast<uint32_t*>(puVar8[0xd] + iVar6);
      for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
        *puVar9 = *puVar13;
        puVar13 = puVar13 + 1;
        puVar9 = puVar9 + 1;
      }
      for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
        *reinterpret_cast<uint8_t*>(puVar9) = *reinterpret_cast<uint8_t*>(puVar13);
        puVar13 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar13) + 1);
        puVar9 = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(puVar9) + 1);
      }
    } else {
      if (puVar13 != nullptr) {
        release_ref(puVar13);
      }
      if (puVar8 != nullptr) {
        puVar8[1] = puVar8[1] + 1;
        puVar13 = puVar8;
        goto LAB_00512437;
      }
LAB_00512473:
      sprintf(acStack_200, "Could not load terrain file: %s\n", uVar3);
      if (PTR_FUN_00717a84 != nullptr) {
        typedef void (*ErrorFn)(const char* title, const char* text, uint32_t flags);
        ErrorFn report = *reinterpret_cast<ErrorFn*>(&PTR_FUN_00717a84);
        report("Error loading file!", acStack_200, 0);
      }
      bVar4 = true;
    }
    uVar12 = uVar12 + 4;
    puVar13 = puVar8;
    if (0xf < uVar12) {
      *reinterpret_cast<uint32_t*>(self + 0x6c) =
          *reinterpret_cast<uint32_t*>(puVar8[0xe]);
      *reinterpret_cast<uint32_t*>(self + 0x70) =
          *reinterpret_cast<uint32_t*>(puVar8[0xf]);
      if (!bVar4) {
        *reinterpret_cast<uint8_t*>(self + 0xa0) = 1;
        release_ref(puVar8);
        if (DAT_008ca53c == 0) {
          iVar6 = static_cast<int32_t>(
              reinterpret_cast<intptr_t>(FUN_00533c78(0x70)));
          if (iVar6 == 0) {
            DAT_008ca53c = 0;
          } else {
            DAT_008ca53c = reinterpret_cast<uint32_t>(FUN_0051ffd0());
          }
        }
        FUN_00520190(&DAT_008eddf8);
        return 0;
      }
      *reinterpret_cast<uint8_t*>(self + 0xa0) = 0;
      release_ref(puVar8);
      if (DAT_008ca53c == 0) {
        iVar6 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_00533c78(0x70)));
        if (iVar6 == 0) {
          DAT_008ca53c = 0;
        } else {
          DAT_008ca53c = reinterpret_cast<uint32_t>(FUN_0051ffd0());
        }
      }
      FUN_00520190(&DAT_008eddf8);
      return 0xd;
    }
  } while (true);
}

// 0x512590 — observed shape
// Allocates the row array and the per-row cell arrays, zeroing every entry.
uint32_t FUN_00512590(uint32_t* self)
{
  char cVar1;
  char* pcVar2;
  int32_t iVar3;
  uint32_t uVar4;
  uint32_t uVar5;
  uint32_t uVar6;

  if ((_DAT_008eddf0 & 1) == 0) {
    _DAT_008eddf0 = _DAT_008eddf0 | 1;
    pcVar2 = const_cast<char*>("FLandscape::AllocateTerrainCells");
    do {
      cVar1 = *pcVar2;
      // Copies the literal text into the adjacent .data buffer at +0x1dc3b0.
      pcVar2[0x1dc3b0] = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    _DAT_008edde8 = 0xffffffff;
    DAT_008edde4 = 0;
  }

  if (DAT_008ca53c == 0) {
    iVar3 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_00533c78(0x70)));
    if (iVar3 == 0) {
      DAT_008ca53c = 0;
    } else {
      DAT_008ca53c = reinterpret_cast<uint32_t>(FUN_0051ffd0());
    }
  }
  FUN_005200b0(&DAT_008edcc0);

  self[2] = reinterpret_cast<uint32_t>(
      thunk_FUN_00533c78(*reinterpret_cast<int32_t*>(
                             reinterpret_cast<uint8_t*>(self) + 0x74) << 2));
  uVar6 = 0;
  if (*reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(self) + 0x74) != 0) {
    do {
      uVar4 = reinterpret_cast<uint32_t>(thunk_FUN_00533c78(
          *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(self) + 0x78) << 2));
      *reinterpret_cast<uint32_t*>(self[2] + uVar6 * 4) = uVar4;
      uVar5 = 0;
      if (*reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(self) + 0x78) != 0) {
        do {
          *reinterpret_cast<uint32_t*>(
              *reinterpret_cast<int32_t*>(self[2] + uVar6 * 4) + uVar5 * 4) = 0;
          uVar5 = uVar5 + 1;
        } while (uVar5 < *reinterpret_cast<uint32_t*>(
                              reinterpret_cast<uint8_t*>(self) + 0x78));
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *reinterpret_cast<uint32_t*>(
                          reinterpret_cast<uint8_t*>(self) + 0x74));
  }

  if (DAT_008ca53c == 0) {
    iVar3 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_00533c78(0x70)));
    if (iVar3 == 0) {
      DAT_008ca53c = 0;
    } else {
      DAT_008ca53c = reinterpret_cast<uint32_t>(FUN_0051ffd0());
    }
  }
  FUN_00520190(&DAT_008edcc0);
  return 0;
}

// 0x5126a0 — observed shape
// Releases every remaining terrain cell, logging each still-allocated slot,
// then frees the row array itself.
uint32_t FUN_005126a0(uint8_t* self)
{
  uint32_t uVar3;
  uint32_t uVar4;
  int32_t iVar1;
  void* pvVar2;

  if (*reinterpret_cast<int32_t*>(self + 8) != 0) {
    uVar3 = 0;
    if (*reinterpret_cast<int32_t*>(self + 0x74) != 0) {
      do {
        uVar4 = 0;
        if (*reinterpret_cast<int32_t*>(self + 0x78) != 0) {
          do {
            iVar1 = *reinterpret_cast<int32_t*>(
                *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(self + 8) +
                                            uVar3 * 4) +
                uVar4 * 4);
            if (iVar1 != 0) {
              FUN_005129a0(
                  reinterpret_cast<uint32_t*>(self),
                  *reinterpret_cast<uint32_t*>(iVar1 + 0x24) /
                      (static_cast<uint32_t>(*reinterpret_cast<int32_t*>(self + 0x7c)) - 1u),
                  uVar4);  // column carried in EBX at this call site
              FUN_005118c0(
                  /* in_EAX log gate */ 0u,
                  "[%s:%d] deleting still allocated terrain cell at %d,%d",
                  ".\\FLandscape.cpp", 0x39a, uVar3, uVar4);
            }
            uVar4 = uVar4 + 1;
          } while (uVar4 < *reinterpret_cast<uint32_t*>(self + 0x78));
        }
        pvVar2 = *reinterpret_cast<void**>(
            *reinterpret_cast<int32_t*>(self + 8) + uVar3 * 4);
        if (pvVar2 != nullptr) {
          operator_delete__(pvVar2);
          *reinterpret_cast<uint32_t*>(*reinterpret_cast<int32_t*>(self + 8) +
                                        uVar3 * 4) = 0;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < *reinterpret_cast<uint32_t*>(self + 0x74));
    }
    if (*reinterpret_cast<void**>(self + 8) != nullptr) {
      operator_delete__(*reinterpret_cast<void**>(self + 8));
      *reinterpret_cast<uint32_t*>(self + 8) = 0;
    }
  }
  return 0;
}

// 0x512780 — observed shape
// First-time setup: registers the five terrain material handles with the
// shared material table, marks the object initialised, flushes, and toggles
// the visual state.
uint32_t FUN_00512780(uint32_t* self)
{
  int32_t iVar1;
  uint32_t uVar2;
  int32_t* local_4 = reinterpret_cast<int32_t*>(self);

  if (*reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(self) + 0xa0) == '\0') {
    iVar1 = 0;
    do {
      switch (iVar1) {
      case 0:
        FUN_005198f0(DAT_008cad2c, 0, self + 0x15);
        break;
      case 1:
        FUN_005198f0(DAT_008cad2c, 1, self + 0x17);
        break;
      case 2:
        FUN_005198f0(DAT_008cad2c, 2, self + 0x18);
        break;
      case 4:
        if (self[0x1a] != 0) {
          local_4 = reinterpret_cast<int32_t*>(FUN_00513d90());
          FUN_005198f0(DAT_008cad2c, 4, &local_4);
          FUN_00519580(4);
          uint32_t extraout_ECX = 0;  // ECX left by FUN_00519580
          FUN_00513d20(extraout_ECX);
          FUN_00513d50(extraout_ECX);
        }
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 5);
    *reinterpret_cast<uint8_t*>(self + 0x28) = 1;         // +0xa0
    typedef void (*FlushFn)(void* self);
    FlushFn flush = *reinterpret_cast<FlushFn*>(*self + 0x18);
    flush(self);
    FUN_00519ae0(DAT_008cad2c);
  }
  return 0;
}

// 0x512870 — observed shape
// Shutdown of the initialised landscape: releases the terrain buffers, drains
// the asset object's live list, and frees the cell grid.
uint32_t FUN_00512870(uint32_t* self)
{
  uint32_t uVar2;
  int32_t iVar1;
  uint32_t* puStack_4;

  if (*reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(self) + 0xa0) != '\0') {
    typedef void (*ShutdownFn)(void* self);
    ShutdownFn shutdown = *reinterpret_cast<ShutdownFn*>(*self + 0x1c);
    shutdown(self);

    if (*reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(self) + 0xa1) == '\0') {
      // The receivers of the unguarded calls are the corresponding member
      // pointers (+0x54, +0x5c, +0x60), elided by the listing.
      FUN_00519a90(reinterpret_cast<void*>(self[0x15]));
      if (self[0x16] != 0) {
        FUN_00519a90(reinterpret_cast<void*>(self[0x16]));
      }
      FUN_00519a90(reinterpret_cast<void*>(self[0x17]));
      FUN_00519a90(reinterpret_cast<void*>(self[0x18]));
    } else {
      if (reinterpret_cast<void*>(self[0x15]) != nullptr) {
        operator_delete__(reinterpret_cast<void*>(self[0x15]));
        self[0x15] = 0;
      }
      if (reinterpret_cast<void*>(self[0x16]) != nullptr) {
        operator_delete__(reinterpret_cast<void*>(self[0x16]));
        self[0x16] = 0;
      }
      if (reinterpret_cast<void*>(self[0x17]) != nullptr) {
        operator_delete__(reinterpret_cast<void*>(self[0x17]));
        self[0x17] = 0;
      }
      if (reinterpret_cast<void*>(self[0x18]) != nullptr) {
        operator_delete__(reinterpret_cast<void*>(self[0x18]));
        self[0x18] = 0;
      }
    }

    uVar2 = 0;
    int32_t* asset = reinterpret_cast<int32_t*>(self[1]);
    if (*reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(asset) + 0xc0) != 0) {
      do {
        typedef void (*AssetAtFn)(void* self, uint32_t** out, uint32_t index);
        AssetAtFn at = *reinterpret_cast<AssetAtFn*>(*asset + 0x78);
        at(asset, &puStack_4, uVar2);
        if (puStack_4 != nullptr) {
          iVar1 = static_cast<int32_t>(puStack_4[1]);
          puStack_4[1] = static_cast<uint32_t>(iVar1 - 1);
          if (iVar1 - 1 == 0) {
            DeletingDtor dtor = *reinterpret_cast<DeletingDtor*>(*puStack_4);
            dtor(puStack_4, 1);
          }
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < *reinterpret_cast<uint32_t*>(
                            reinterpret_cast<uint8_t*>(asset) + 0xc0));
    }
    FUN_00533d10(0, 1);
    if (self[0x1a] != 0) {
      FUN_00513b00(reinterpret_cast<void*>(self[0x1a]));
    }
    FUN_005126a0(reinterpret_cast<uint8_t*>(self));
  }
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0xa0) = 0;
  return 0;
}

// 0x5129a0 — observed shape
// Destroys the cell at (row, col): detaches it from the material object,
// removes it from the asset object's live list, destroys it and clears the
// slot. Out-of-range indices return 5, an empty slot returns 0xe.
uint32_t FUN_005129a0(uint32_t* self, uint32_t row, uint32_t col)
{
  int32_t iVar1;
  uint32_t uVar3;
  uint32_t* puVar2;
  uint32_t* apuStack_8[2];

  if ((self[0x1d] <= row) || (self[0x1e] <= col)) {
    return 5;
  }
  if ((self[2] == 0) ||
      (iVar1 = *reinterpret_cast<int32_t*>(
           *reinterpret_cast<int32_t*>(self[2] + row * 4) + col * 4),
       iVar1 == 0)) {
    return 0xe;
  }

  typedef void (*CellDetachFn)(void* self, int32_t cell);
  CellDetachFn detach = *reinterpret_cast<CellDetachFn*>(*self + 0x24);
  detach(self, iVar1);

  if (reinterpret_cast<int32_t*>(self[1]) != nullptr) {
    int32_t* asset = reinterpret_cast<int32_t*>(self[1]);
    uVar3 = FUN_004edfd0();
    typedef void (*AssetRemoveFn)(void* self, uint32_t** out, uint32_t value);
    AssetRemoveFn remove = *reinterpret_cast<AssetRemoveFn*>(
        *reinterpret_cast<int32_t*>(asset) + 0x74);
    remove(asset, apuStack_8, uVar3);
    if (apuStack_8[0] != nullptr) {
      iVar1 = static_cast<int32_t>(apuStack_8[0][1]);
      apuStack_8[0][1] = static_cast<uint32_t>(iVar1 - 1);
      if (iVar1 - 1 == 0) {
        DeletingDtor dtor = *reinterpret_cast<DeletingDtor*>(*apuStack_8[0]);
        dtor(apuStack_8[0], 1);
      }
    }
    // The listing reloads the row argument from the stack slot (unaff_retaddr)
    // here; its value is the incoming row.
  }

  puVar2 = *reinterpret_cast<uint32_t**>(
      *reinterpret_cast<int32_t*>(self[2] + row * 4) + col * 4);
  if (puVar2 != nullptr) {
    DeletingDtor dtor = *reinterpret_cast<DeletingDtor*>(*puVar2);
    dtor(puVar2, 1);
    *reinterpret_cast<uint32_t*>(
        *reinterpret_cast<int32_t*>(self[2] + row * 4) + col * 4) = 0;
  }
  if (self[0x1a] != 0) {
    FUN_00513ca0(col);
  }
  return 0;
}

// 0x512a90 — observed shape
// Creates the cell at (row, col) with the clamped block dimensions; when the
// landscape owns its cells the new object is stored and its material link is
// established.
int32_t FUN_00512a90(uint8_t* self, int32_t row, int32_t col)
{
  uint32_t uVar1;
  uint32_t uVar2;
  int32_t iVar3;
  int32_t iVar4;
  uint32_t uVar5;

  uVar1 = *reinterpret_cast<uint32_t*>(self + 0x7c);
  uVar2 = *reinterpret_cast<int32_t*>(self + 0x6c) - (uVar1 - 1) * row;
  if (uVar1 < uVar2) {
    uVar2 = uVar1;
  }
  uVar1 = *reinterpret_cast<uint32_t*>(self + 0x80);
  uVar5 = *reinterpret_cast<int32_t*>(self + 0x70) - (uVar1 - 1) * col;
  if (uVar1 < uVar5) {
    uVar5 = uVar1;
  }
  iVar3 = FUN_00512b00(row, col, uVar2, uVar5);
  if ((iVar3 != 0) && (*reinterpret_cast<char*>(self + 0xa1) != '\0')) {
    *reinterpret_cast<int32_t*>(
        *reinterpret_cast<int32_t*>(*reinterpret_cast<int32_t*>(self + 8) + row * 4) +
        col * 4) = iVar3;
    iVar4 = static_cast<int32_t>(FUN_004edfd0());
    if (iVar4 != 0) {
      FUN_00512d70(row, col);
    }
  }
  return iVar3;
}
