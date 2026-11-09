#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <windows.h>

// ---------------------------------------------------------------------------
// Extern helpers referenced by the observed listings (never defined here).
// ---------------------------------------------------------------------------
extern void* FUN_00533c78(std::size_t n);
extern void* thunk_FUN_00533c78(std::size_t n);
extern char FUN_004f8fa0(void* pLocal25c, uint32_t param_1);
extern void FUN_004f8f50();
extern char FUN_004f96a0();
extern int FUN_0042dc50(const char* s);
extern void FUN_00524e90(void* p);
extern uint32_t FUN_0042e1d0();
extern void FUN_0051bfc0(void* p);
extern void FUN_004b06c0(const char* text, int x, int y, int size, uint32_t color, int flag, uint32_t a, int b);
extern void FUN_004888e0(int kind, int a, int b, uint32_t bits);
extern void FUN_004889c0(void* p, int kind, int a, int b, int c, uint32_t bits, int d);
extern void* FUN_0042e900(void** out, int itemId);
extern void* FUN_0042f100(void** out, int itemId);
extern void FUN_004311e0(int** esiSlot, int** ediSlot);
extern void FUN_004bdca0(uint32_t a, int b, int c, int d, int e, uint32_t f, int g, int h, int i, int j);
extern void* FUN_004baa30(uint32_t dc, const char* name, int a, int b, int c, int d, uint32_t e, int f, int g, int h, int i);
extern void FUN_004bb500(int f);
extern void FUN_004c24e0();
extern void FUN_004bc7e0(int a, int b);
extern void FUN_00412840(uint32_t a, uint32_t b);
extern void FUN_00412900(int a, int b, int c);
extern void FUN_004bba60(void* p, int a, int b, uint32_t c, int d);
extern void FUN_004d9d40(void* p, int a, int b, int c, int d, int e, int f, int g);
extern void FUN_004daa10(uint32_t a, int b, int c, int d);
extern void FUN_004d9f50(int a, int b, int c);
extern int FUN_005f0ddc();
extern void FUN_004bbe10(int a, int b);
extern void FUN_004f6090(const char* s);
extern void FUN_00509500(void* dc, void* p, int a);
extern void FUN_005096b0();
extern void FUN_004baae0(uint32_t dc);
extern void FUN_004be3f0(void* p, int a, int b, int c, int d, int e, uint32_t f, int g, int h, int i, int j, int k);
extern void FUN_004baca0();
extern void* FUN_004cddf0(const char* name, int a, int b, int* w, uint32_t* h);
extern void FUN_004af080(void* p, int a, int b, int c, uint32_t d, int e, int f, int g, int h, uint32_t i, int j);
extern void FUN_004881b0(int x, int y);
extern void FUN_004d0cd0(int a, int b, int c);
extern void FUN_004879f0(int a, int b);
extern void FUN_004f2600(const char* fmt, const char* arg);
extern void FUN_004985e0();
extern void FUN_004a14b0();
extern void FUN_00488840(const char* s, int a);
extern void FUN_004e6420();
extern void FUN_00568200();
extern void operator_delete__(void* p);
extern void operator_delete(void* p);

// Globals referenced by the listings.
extern void* DAT_0086bb5c;
extern void* DAT_0086bb58;
extern uint32_t DAT_0086bb4c;
extern void* DAT_008c8270;
extern void* DAT_008c8278;
extern void* DAT_008c8274;
extern uint32_t DAT_008ea008;
extern int DAT_00727444;
extern int DAT_00725408;
extern void* DAT_008dc314;
extern int DAT_0085a268;
extern int DAT_0085a26c;
extern uint32_t DAT_0085a164;
extern void* DAT_008c9de8;
extern int DAT_008dc30c;
extern int DAT_008dc310;
extern int DAT_00725410;
extern int DAT_008ca954;
extern int DAT_008d3a90;
extern int DAT_00726380;
extern void* DAT_008d3a58;
extern char DAT_0086ab48[];
extern char DAT_00869b48[];
extern int DAT_0085a11c;
extern void* DAT_008c9de0;
extern void* DAT_008c9dd8;
extern int DAT_0086c330;
extern short DAT_0086c010[];
extern short DAT_0086be80[];
extern short DAT_0086c1a0[];
extern short DAT_0086bcf0[];
extern short DAT_0086bb60[];
extern HCURSOR DAT_008cacd8;
extern char DAT_00007f02[];
extern void* DAT_008ecd78;
extern char DAT_008e8eff;
extern char DAT_008cacd0[];
extern char DAT_008d1418[];
extern char DAT_008d1358[];
extern char DAT_006f588c[];
extern char DAT_008cac27;
extern char DAT_0072540c;
extern char DAT_00725404;
extern int DAT_00726b74;
extern const char* PTR_DAT_00726ba0;
extern float DAT_008cac44;
extern int DAT_0086c35c;
extern int DAT_0086c360;
extern uint32_t DAT_008ed61c;
extern DWORD DAT_008ed618;
extern DWORD DAT_0086bb48;
extern char DAT_006fe448[];
extern char DAT_006fe650[];
extern void* PTR_FUN_007108ac;
extern void* PTR_FUN_006fe3d0;
extern void* PTR_FUN_006fe408;
extern void* PTR_FUN_006fe3ec;
extern void* PTR_FUN_006fd14c;

// 0x42df80 — observed shape
// Allocates two 0x14-byte hash-map-like objects (vtable state 0x3d, 0xf4-byte
// zeroed bucket array, flag byte at offset 16 set to 1), stores them to
// DAT_0086bb5c/DAT_0086bb58, then iterates a parsed name list (via
// FUN_004f8fa0) and resolves each entry's "_"-suffixed key.
void FUN_0042df80(uint32_t param_1)
{
  uint32_t* puVar2 = (uint32_t*)FUN_00533c78(0x14);
  if (puVar2 == nullptr) {
    DAT_0086bb5c = nullptr;
  } else {
    *puVar2 = (uint32_t)(uintptr_t)PTR_FUN_006fe3d0;
    puVar2[1] = 0x3d;
    puVar2[3] = 0;
    uint32_t* puVar3 = (uint32_t*)thunk_FUN_00533c78(0xf4);
    puVar2[2] = (uint32_t)(uintptr_t)puVar3;
    for (uint32_t uVar6 = puVar2[1] & 0x3fffffff; uVar6 != 0; uVar6--) {
      *puVar3 = 0;
      puVar3++;
    }
    for (int iVar7 = 0; iVar7 != 0; iVar7--) {
      *(uint8_t*)puVar3 = 0;
      puVar3 = (uint32_t*)((uintptr_t)puVar3 + 1);
    }
    *(uint8_t*)(puVar2 + 4) = 1;
    *puVar2 = (uint32_t)(uintptr_t)PTR_FUN_006fe408;
    DAT_0086bb5c = puVar2;
  }
  puVar2 = (uint32_t*)FUN_00533c78(0x14);
  if (puVar2 == nullptr) {
    DAT_0086bb58 = nullptr;
  } else {
    *puVar2 = (uint32_t)(uintptr_t)PTR_FUN_006fe3d0;
    puVar2[1] = 0x3d;
    puVar2[3] = 0;
    uint32_t* puVar3 = (uint32_t*)thunk_FUN_00533c78(0xf4);
    puVar2[2] = (uint32_t)(uintptr_t)puVar3;
    for (uint32_t uVar6 = puVar2[1] & 0x3fffffff; uVar6 != 0; uVar6--) {
      *puVar3 = 0;
      puVar3++;
    }
    for (int iVar7 = 0; iVar7 != 0; iVar7--) {
      *(uint8_t*)puVar3 = 0;
      puVar3 = (uint32_t*)((uintptr_t)puVar3 + 1);
    }
    *(uint8_t*)(puVar2 + 4) = 1;
    *puVar2 = (uint32_t)(uintptr_t)PTR_FUN_006fe408;
    DAT_0086bb58 = puVar2;
  }
  int local_254 = 0;
  (void)local_254;
  int local_248 = 1;
  int local_250 = 0;
  int local_24c = 0;
  uint32_t local_258 = 0;
  void* ptr = PTR_FUN_007108ac;
  void* local_25c = ptr;
  char local_240[64];
  char local_200[512];
  int local_264 = 0;
  int local_26c = 0;
  uint32_t local_268 = 0;
  int local_244 = 0;
  char cVar1 = FUN_004f8fa0(&local_25c, param_1);
  int iVar7 = local_250;
  if (cVar1 != '\0' && (local_264 = 0, 0 < local_250)) {
    do {
      if ((-1 < local_264) && (local_264 < local_250)) {
        char* pcVar8 = *(char**)(*(uintptr_t*)(intptr_t)(local_258 + local_264 * 4) + 0);
        // deref chain: **(undefined4**)(local_258 + local_264*4)
        char* pcVar9 = local_200;
        char c;
        do {
          c = *pcVar8;
          pcVar8++;
          *pcVar9 = c;
          pcVar9++;
        } while (c != '\0');
      }
      cVar1 = FUN_004f96a0();
      if (cVar1 == '\0') local_26c = 0;
      else local_26c = local_244 + 4;
      local_268 = 0;
      if (*(int*)(intptr_t)(local_26c + 0xc) != 0) {
        do {
          char* pcVar9 = strrchr(*(char**)(*(int*)(intptr_t)(local_26c + 4) + local_268 * 4), 0x5f);
          if (pcVar9 != nullptr) {
            int iVar4 = FUN_0042dc50(local_200);
            int iVar5 = FUN_0042dc50(local_200);
            if ((iVar4 != 0) && (iVar5 != 0)) {
              sprintf(local_240, "%s_%03X", local_200, iVar5);
              FUN_00524e90((void*)(intptr_t)iVar4);
              sprintf(local_240, "%s_%03X", local_200, iVar4);
              FUN_00524e90((void*)(intptr_t)iVar5);
            }
          }
          local_268++;
        } while (local_268 < *(uint32_t*)(intptr_t)(local_26c + 0xc));
      }
      local_264++;
    } while (local_264 < iVar7);
  }
  FUN_004f8f50();
  (void)local_248; (void)local_24c;
}

// 0x42e440 — observed shape
// Resolves the current input token (FUN_0042e1d0) and, when a hash map is
// present, formats "<token>_<hash:03X>" into a 256-byte buffer.
uint32_t FUN_0042e440(int esiValue)
{
  uint32_t local_104 = FUN_0042e1d0();
  char local_100[256];
  if ((esiValue != 0) && (DAT_0086bb5c != nullptr)) {
    sprintf(local_100, "%s_%03X", (const char*)(uintptr_t)local_104, local_104);
    // listing passes the formatted string slot to the allocator helper
    FUN_0051bfc0(&local_104);
  }
  return local_104;
}

// 0x42e4a0 — observed shape
// Varargs-style text draw: vsnprintf into 250-byte buffer, then
// FUN_004b06c0 with fixed color/size parameters.
void FUN_0042e4a0(uint32_t param_1, uint32_t param_2, const char* param_3, char param_4)
{
  char local_100[256];
  vsnprintf(local_100, 0xfa, param_3, &param_4);
  FUN_004b06c0(local_100, (int)param_1, (int)param_2, 100, 0xffffffff, 1, 0xffffffff, 0);
}

// 0x42e730 — observed shape
// Switch on the register selector EAX mapping to audio cue ids
// (0x2c/0x2d/0x2e/0x31/0x2f/0x32/0x34/0x33/0x37) or button ids
// (0x35/0x36/0x30/0x38) played with -1.0f (0xbf800000).
void FUN_0042e730(int in_EAX)
{
  switch (in_EAX) {
    case 0:
    case 1:
      FUN_004888e0(0x2c, 0xffffffff, 0xffffffff, 0xbf800000);
      return;
    case 2:
    case 0xc:
      FUN_004888e0(0x2d, 0xffffffff, 0xffffffff, 0xbf800000);
      return;
    case 3:
      FUN_004888e0(0x2e, 0xffffffff, 0xffffffff, 0xbf800000);
      return;
    case 4:
      FUN_004889c0(&DAT_008c8270, 0x35, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
      return;
    case 5:
      FUN_004889c0(&DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
      return;
    case 6:
      FUN_004888e0(0x31, 0xffffffff, 0xffffffff, 0xbf800000);
      return;
    case 7:
      FUN_004888e0(0x2f, 0xffffffff, 0xffffffff, 0xbf800000);
      return;
    case 8:
      FUN_004889c0(&DAT_008c8278, 0x30, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
      return;
    case 9:
      FUN_004888e0(0x32, 0xffffffff, 0xffffffff, 0xbf800000);
      return;
    case 10:
      FUN_004888e0(0x34, 0xffffffff, 0xffffffff, 0xbf800000);
      return;
    case 0xb:
      FUN_004888e0(0x33, 0xffffffff, 0xffffffff, 0xbf800000);
      return;
    case 0xd:
      FUN_004888e0(0x37, 0xffffffff, 0xffffffff, 0xbf800000);
      return;
    case 0xe:
      FUN_004889c0(&DAT_008c8274, 0x38, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
      break;
    default:
      break;
  }
}

// 0x42e900 — observed shape
// Item-id (EAX) factory: builds a 12-byte model filename per id, then
// allocates a 0xc0-byte reference-counted object (vtable PTR_FUN_006fd14c,
// refcount at [1], zeroed fields at [7]/[0x19]/[0x2f], global counter
// DAT_00727444 incremented), registers it via FUN_004bdca0, stores it to
// *param_1 and addrefs.
uint32_t** FUN_0042e900(uint32_t** param_1, int in_EAX)
{
  char local_80[16];
  uint32_t local_74 = 0;
  uint32_t local_70 = 0;
  uint32_t local_6c = 0;
  switch (in_EAX) {
    case 0:
      strncpy(local_80, "balanced_swo", 0xc);
      local_74 = 'r' | ('d' << 8) | ('.' << 16) | ('n' << 24);
      local_70 = (local_70 & 0xff000000u) | 0x006669u;
      break;
    case 1:
      strncpy(local_80, "one_shot_pis", 0xc);
      local_74 = 't' | ('o' << 8) | ('l' << 16) | ('.' << 24);
      local_70 = (local_70 & 0xff000000u) | ((uint32_t)'n' | ((uint32_t)'i' << 8) | ((uint32_t)'f' << 16));
      break;
    case 2:
      local_80[8] = 'v'; local_80[9] = 'e'; local_80[10] = 's'; local_80[0xb] = 't';
      strncpy(local_80, "leather_", 8);
      goto LAB_42eff5_case2_0b_1b_21;
    case 3: {
      const char* pcVar6 = "fencingshirt_puffy.nif";
      char* pcVar7 = local_80;
      for (int iVar5 = 5; iVar5 != 0; iVar5--) {
        *(uint32_t*)pcVar7 = *(const uint32_t*)pcVar6;
        pcVar6 += 4; pcVar7 += 4;
      }
      *(uint16_t*)pcVar7 = *(const uint16_t*)pcVar6;
      pcVar7[2] = pcVar6[2];
      break;
    }
    case 4:
      strncpy(local_80, "quality_spyg", 0xc);
      local_74 = 'l' | ('a' << 8) | ('s' << 16) | ('s' << 24);
      local_70 = (local_70 & 0xff000000u) | ((uint32_t)'.' | ((uint32_t)'n' << 8) | ((uint32_t)'i' << 16));
      local_6c &= 0xffffff00u;
      break;
    case 5:
      strncpy(local_80, "dutch_rutter", 0xc);
      local_74 = '.' | ('n' << 8) | ('i' << 16) | ('f' << 24);
      local_70 = ((local_70 >> 8) & 0x00ffffffu) << 8;
      break;
    case 6:
      strncpy(local_80, "weather_glas", 0xc);
      local_74 = 's' | ('.' << 8) | ('n' << 16) | ('i' << 24);
      local_70 = ((local_70 >> 16) & 0xffffu) | (0x66u << 16) | (local_70 & 0xff000000u);
      break;
    case 7:
      local_80[8] = '_'; local_80[9] = 'f'; local_80[10] = 'i'; local_80[0xb] = 'd';
      strncpy(local_80 + 4, "ring", 4);
      strncpy(local_80, "3_st", 4);
      local_74 = 'd' | ('l' << 8) | ('e' << 16) | ('.' << 24);
      local_70 = (uint32_t)'n' | ((uint32_t)'i' << 8) | ((uint32_t)'f' << 16) | ((uint32_t)'\0' << 24);
      break;
    case 8:
      strncpy(local_80, "false_mustac", 0xc);
      local_74 = 'h' | ('e' << 8) | ('.' << 16) | ('n' << 24);
      local_70 = (local_70 & 0xff000000u) | 0x006669u;
      break;
    case 9:
      strncpy(local_80, "medicinal_he", 0xc);
      local_74 = 'r' | ('b' << 8) | ('s' << 16) | ('.' << 24);
      local_70 = (uint32_t)'n' | ((uint32_t)'i' << 8) | ((uint32_t)'f' << 16) | ((uint32_t)'\0' << 24);
      break;
    case 10:
      strncpy(local_80, "shrunken_hea", 0xc);
      local_74 = 'd' | ('.' << 8) | ('n' << 16) | ('i' << 24);
      local_70 = ((local_70 >> 16) & 0xffffu) | (0x66u << 16) | (local_70 & 0xff000000u);
      break;
    case 0xb:
      local_80[8] = 'r'; local_80[9] = 'o'; local_80[10] = 's'; local_80[0xb] = 's';
      strncpy(local_80, "golden_c", 8);
      goto LAB_42eff5_case2_0b_1b_21;
    case 0xc:
      strncpy(local_80, "ruby_ring.ni", 0xc);
      local_74 = 'f' | ('\0' << 8);
      break;
    case 0xd:
      strncpy(local_80, "calfskin_boo", 0xc);
      local_74 = 't' | ('s' << 8) | ('.' << 16) | ('n' << 24);
      local_70 = (local_70 & 0xff000000u) | 0x006669u;
      break;
    case 0xe:
      strncpy(local_80, "french_chape", 0xc);
      local_74 = 'a' | ('u' << 8) | ('.' << 16) | ('n' << 24);
      local_70 = (local_70 & 0xff000000u) | 0x006669u;
      break;
    case 0xf:
      strncpy(local_80, "lock_picking", 0xc);
      local_74 = '_' | ('k' << 8) | ('i' << 16) | ('t' << 24);
      local_70 = (uint32_t)'.' | ((uint32_t)'n' << 8) | ((uint32_t)'i' << 16) | ((uint32_t)'f' << 24);
      local_6c = (local_6c & 0xff00u) << 8 | (local_6c & 0xffffff00u);
      break;
    case 0x10:
      strncpy(local_80, "signaling_mi", 0xc);
      local_74 = 'r' | ('r' << 8) | ('o' << 16) | ('r' << 24);
      local_70 = (uint32_t)'.' | ((uint32_t)'n' << 8) | ((uint32_t)'i' << 16) | ((uint32_t)'f' << 24);
      local_6c = (local_6c & 0xff00u) << 8 | (local_6c & 0xffffff00u);
      break;
    case 0x11: {
      const char* pcVar6 = "perfectly_balanced_rapier.nif";
      char* pcVar7 = local_80;
      for (int iVar5 = 7; iVar5 != 0; iVar5--) {
        *(uint32_t*)pcVar7 = *(const uint32_t*)pcVar6;
        pcVar6 += 4; pcVar7 += 4;
      }
      *(uint16_t*)pcVar7 = *(const uint16_t*)pcVar6;
      break;
    }
    case 0x12:
      local_80[8] = 's'; local_80[9] = 't'; local_80[10] = 'o'; local_80[0xb] = 'l';
      strncpy(local_80 + 4, "e_pi", 4);
      strncpy(local_80, "brac", 4);
      local_74 = 's' | ('.' << 8) | ('n' << 16) | ('i' << 24);
      local_70 = ((local_70 >> 16) & 0xffffu) | (0x66u << 16) | (local_70 & 0xff000000u);
      break;
    case 0x13:
      strncpy(local_80, "metal_curais", 0xc);
      local_74 = 's' | ('.' << 8) | ('n' << 16) | ('i' << 24);
      local_70 = ((local_70 >> 16) & 0xffffu) | (0x66u << 16) | (local_70 & 0xff000000u);
      break;
    case 0x14: {
      const char* pcVar6 = "silk_fencing_shirt.nif";
      char* pcVar7 = local_80;
      for (int iVar5 = 5; iVar5 != 0; iVar5--) {
        *(uint32_t*)pcVar7 = *(const uint32_t*)pcVar6;
        pcVar6 += 4; pcVar7 += 4;
      }
      *(uint16_t*)pcVar7 = *(const uint16_t*)pcVar6;
      pcVar7[2] = pcVar6[2];
      break;
    }
    case 0x15:
      strncpy(local_80, "fine_telesco", 0xc);
      local_74 = 'p' | ('e' << 8) | ('.' << 16) | ('n' << 24);
      local_70 = (local_70 & 0xff000000u) | 0x006669u;
      break;
    case 0x16:
      strncpy(local_80, "spanish_rutt", 0xc);
      local_74 = 'e' | ('r' << 8) | ('.' << 16) | ('n' << 24);
      local_70 = (local_70 & 0xff000000u) | 0x006669u;
      break;
    case 0x17:
      strncpy(local_80, "percision_ba", 0xc);
      local_74 = 'r' | ('o' << 8) | ('m' << 16) | ('e' << 24);
      local_70 = (uint32_t)'t' | ((uint32_t)'e' << 8) | ((uint32_t)'r' << 16) | ((uint32_t)'.' << 24);
      local_6c = (uint32_t)'n' | ((uint32_t)'i' << 8) | ((uint32_t)'f' << 16) | ((uint32_t)'\0' << 24);
      break;
    case 0x18:
      strncpy(local_80, "concertina.n", 0xc);
      local_74 = 'i' | ('f' << 8);
      break;
    case 0x19:
      strncpy(local_80, "theatrical_d", 0xc);
      local_74 = 'i' | ('s' << 8) | ('g' << 16) | ('u' << 24);
      local_70 = (uint32_t)'i' | ((uint32_t)'s' << 8) | ((uint32_t)'e' << 16) | ((uint32_t)'.' << 24);
      local_6c = (uint32_t)'n' | ((uint32_t)'i' << 8) | ((uint32_t)'f' << 16) | ((uint32_t)'\0' << 24);
      break;
    case 0x1a: {
      const char* pcVar6 = "incan_mystic_salve.nif";
      char* pcVar7 = local_80;
      for (int iVar5 = 5; iVar5 != 0; iVar5--) {
        *(uint32_t*)pcVar7 = *(const uint32_t*)pcVar6;
        pcVar6 += 4; pcVar7 += 4;
      }
      *(uint16_t*)pcVar7 = *(const uint16_t*)pcVar6;
      pcVar7[2] = pcVar6[2];
      break;
    }
    case 0x1b:
      local_80[8] = 't'; local_80[9] = 'i'; local_80[10] = 'c'; local_80[0xb] = 'k';
      strncpy(local_80, "shaman_s", 8);
      goto LAB_42eff5_case2_0b_1b_21;
    case 0x1c:
      strncpy(local_80, "sacred_relic", 0xc);
      local_74 = '.' | ('n' << 8) | ('i' << 16) | ('f' << 24);
      local_70 = ((local_70 >> 8) & 0x00ffffffu) << 8;
      break;
    case 0x1d:
      strncpy(local_80, "diamond_neck", 0xc);
      local_74 = 'l' | ('a' << 8) | ('c' << 16) | ('e' << 24);
      local_70 = ((uint32_t)'.' | ((uint32_t)'n' << 8) | ((uint32_t)'i' << 16) | ((uint32_t)'f' << 24));
      local_6c = (local_6c & 0xff00u) << 8 | (local_6c & 0xffffff00u);
      break;
    case 0x1e:
      strncpy(local_80, "dancing_slip", 0xc);
      local_74 = 'p' | ('e' << 8) | ('r' << 16) | ('s' << 24);
      local_70 = ((uint32_t)'.' | ((uint32_t)'n' << 8) | ((uint32_t)'i' << 16) | ((uint32_t)'f' << 24));
      local_6c = (local_6c & 0xff00u) << 8 | (local_6c & 0xffffff00u);
      break;
    case 0x1f:
      strncpy(local_80, "ostrich_feat", 0xc);
      local_74 = 'h' | ('e' << 8) | ('r' << 16) | ('_' << 24);
      local_70 = (uint32_t)'h' | ((uint32_t)'a' << 8) | ((uint32_t)'t' << 16) | ((uint32_t)'.' << 24);
      local_6c = (uint32_t)'n' | ((uint32_t)'i' << 8) | ((uint32_t)'f' << 16) | ((uint32_t)'\0' << 24);
      break;
    case 0x20:
      strncpy(local_80, "skeleton_key", 0xc);
      local_74 = '.' | ('n' << 8) | ('i' << 16) | ('f' << 24);
      local_70 = ((local_70 >> 8) & 0x00ffffffu) << 8;
      break;
    case 0x21:
      local_80[8] = 'l'; local_80[9] = 'a'; local_80[10] = 'r'; local_80[0xb] = 'e';
      strncpy(local_80, "signal_f", 8);
      goto LAB_42eff5_case2_0b_1b_21;
    default:
      break;
  LAB_42eff5_case2_0b_1b_21:
    local_74 = '.' | ('n' << 8) | ('i' << 16) | ('f' << 24);
    local_70 = ((local_70 >> 8) & 0x00ffffffu) << 8;
  }
  uint32_t* puVar4 = (uint32_t*)FUN_00533c78(0xc0);
  uint32_t uVar1 = DAT_008ea008;
  if (puVar4 == nullptr) {
    puVar4 = nullptr;
  } else {
    puVar4[1] = 0;
    *puVar4 = (uint32_t)(uintptr_t)PTR_FUN_006fd14c;
    puVar4[7] = 0;
    DAT_00727444++;
    puVar4[0x19] = 0;
    puVar4[0x2f] = 0;
    FUN_004bdca0(uVar1, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
  }
  *param_1 = puVar4;
  if (puVar4 != nullptr) puVar4[1]++;
  (void)local_80; (void)local_74; (void)local_70; (void)local_6c;
  return param_1;
}

// 0x42f100 — observed shape
// Same 0xc0 object factory as 0x42e900 but with an (empty) 0x25..0x41 switch
// on EAX; always allocates the object and returns it via *param_1.
uint32_t** FUN_0042f100(uint32_t** param_1, int in_EAX)
{
  switch (in_EAX) {
    case 0x25: break;
    case 0x26: break;
    case 0x27: break;
    case 0x28: break;
    case 0x29: break;
    case 0x2a: break;
    case 0x2b: break;
    case 0x2c: break;
    case 0x2d: break;
    case 0x2e: break;
    case 0x2f: break;
    case 0x30: break;
    case 0x31: break;
    case 0x32: break;
    case 0x33: break;
    case 0x34: break;
    case 0x35: break;
    case 0x36: break;
    case 0x37: break;
    case 0x38: break;
    case 0x39: break;
    case 0x3a: break;
    case 0x3b: break;
    case 0x3c: break;
    case 0x3d: break;
    case 0x3e: break;
    case 0x3f: break;
    case 0x40: break;
    case 0x41: break;
    default: break;
  }
  uint32_t* puVar2 = (uint32_t*)FUN_00533c78(0xc0);
  uint32_t uVar1 = DAT_008ea008;
  if (puVar2 == nullptr) {
    puVar2 = nullptr;
  } else {
    puVar2[1] = 0;
    *puVar2 = (uint32_t)(uintptr_t)PTR_FUN_006fd14c;
    puVar2[7] = 0;
    DAT_00727444++;
    puVar2[0x19] = 0;
    puVar2[0x2f] = 0;
    FUN_004bdca0(uVar1, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
  }
  *param_1 = puVar2;
  if (puVar2 != nullptr) puVar2[1]++;
  return param_1;
}

// 0x42f7d0 — observed shape
// Dispatch on ECX/100: 300 sets the active texture via FUN_0042e900,
// 0 sets flag 1, 100 loads base, 200 creates via FUN_0042f100+assign
// (FUN_004311e0), 500 switches rank icons, 600 also uses FUN_0042f100.
void FUN_0042f7d0(int in_ECX)
{
  int iVar5 = in_ECX % 100;
  DAT_0086bb4c = 0;
  int iVar4 = in_ECX - iVar5;
  DAT_00725408 = in_ECX;
  uint32_t* local_c = nullptr;
  uint32_t* local_8 = nullptr;
  uint32_t* local_4 = nullptr;
  if (iVar4 < 0x12d) {
    if (iVar4 == 300) {
      int* piVar1 = (int*)FUN_0042e900((void**)&local_8, iVar4);
      uint32_t* puVar3 = (uint32_t*)DAT_008dc314;
      if (DAT_008dc314 != (uint32_t*)*piVar1) {
        if ((DAT_008dc314 != nullptr) &&
            (iVar4 = ((int*)DAT_008dc314)[1], ((int*)DAT_008dc314)[1] = iVar4 - 1, iVar4 - 1 == 0)) {
          (*(void(**)(int))(**(void***)puVar3))(1);
        }
        DAT_008dc314 = (uint32_t*)*piVar1;
        if (DAT_008dc314 != nullptr) ((int*)DAT_008dc314)[1]++;
      }
      if ((local_8 != nullptr) &&
          (iVar4 = ((int*)local_8)[1], ((int*)local_8)[1] = iVar4 - 1, iVar4 - 1 == 0)) {
        (*(void(**)(int))(**(void***)local_8))(1);
        return;
      }
    } else {
      if (in_ECX == iVar5) {
        FUN_004bb500(0);
        FUN_004c24e0();
        DAT_0086bb4c = 1;
        return;
      }
      if (iVar4 == 100) {
        FUN_004bb500(0);
        FUN_004c24e0();
        FUN_004bc7e0(0, 0);
        return;
      }
      if (iVar4 == 200) {
        if ((iVar5 < 0x28) && (iVar5 < 0x1e)) DAT_0086bb4c = 1;
        FUN_0042f100((void**)&local_c, iVar5);
        FUN_004311e0(nullptr, nullptr);
        if ((local_c != nullptr) &&
            (iVar4 = ((int*)local_c)[1], ((int*)local_c)[1] = iVar4 - 1, iVar4 - 1 == 0)) {
          (*(void(**)(int))(**(void***)local_c))(1);
          return;
        }
      }
    }
  } else {
    if (iVar4 == 500) {
      switch (iVar5) {
        case 3:
          if (FUN_00533c78(0xc0) != nullptr) {
            FUN_004baa30(DAT_008ea008, "major_icon.dds", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
            FUN_004c24e0();
            return;
          }
          break;
        case 4:
          if (FUN_00533c78(0xc0) != nullptr) {
            FUN_004baa30(DAT_008ea008, "colonel_icon.dds", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
            FUN_004c24e0();
            return;
          }
          break;
        case 5:
          if (FUN_00533c78(0xc0) != nullptr) {
            FUN_004baa30(DAT_008ea008, "admiral_icon.dds", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
            FUN_004c24e0();
            return;
          }
          break;
        case 6:
          if (FUN_00533c78(0xc0) != nullptr) {
            FUN_004baa30(DAT_008ea008, "baron_icon.dds", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
            FUN_004c24e0();
            return;
          }
          break;
        case 7:
          if (FUN_00533c78(0xc0) != nullptr) {
            FUN_004baa30(DAT_008ea008, "count_icon.dds", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
            FUN_004c24e0();
            return;
          }
          break;
        case 8:
          if (FUN_00533c78(0xc0) != nullptr) {
            FUN_004baa30(DAT_008ea008, "marquis_rank_icon.dds", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
            FUN_004c24e0();
            return;
          }
          break;
        case 9:
          if (FUN_00533c78(0xc0) != nullptr) {
            FUN_004baa30(DAT_008ea008, "duke_icon.dds", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
            FUN_004c24e0();
            return;
          }
          break;
        default: {
          uint32_t* puVar3;
          if (FUN_00533c78(0xc0) == nullptr) puVar3 = nullptr;
          else puVar3 = (uint32_t*)FUN_004baa30(DAT_008ea008, "captain_icon.dds", 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
          uint32_t* puVar2 = (uint32_t*)DAT_008dc314;
          if (DAT_008dc314 == puVar3) return;
          if ((DAT_008dc314 != nullptr) &&
              (iVar4 = ((int*)DAT_008dc314)[1], ((int*)DAT_008dc314)[1] = iVar4 - 1, iVar4 - 1 == 0)) {
            (*(void(**)(int))(**(void***)puVar2))(1);
          }
          if (puVar3 == nullptr) { DAT_008dc314 = nullptr; return; }
          DAT_008dc314 = puVar3;
          puVar3[1]++;
          return;
        }
      }
      FUN_004c24e0();
      return;
    }
    if (iVar4 == 600) {
      uint32_t* puVar2 = (uint32_t*)FUN_0042f100((void**)&local_4, iVar5);
      uint32_t* puVar3 = (uint32_t*)DAT_008dc314;
      if (DAT_008dc314 != (uint32_t*)*puVar2) {
        if ((DAT_008dc314 != nullptr) &&
            (iVar4 = ((int*)DAT_008dc314)[1], ((int*)DAT_008dc314)[1] = iVar4 - 1, iVar4 - 1 == 0)) {
          (*(void(**)(int))(**(void***)puVar3))(1);
        }
        DAT_008dc314 = (uint32_t*)*puVar2;
        if (DAT_008dc314 != nullptr) ((int*)DAT_008dc314)[1]++;
      }
      if ((local_4 != nullptr) &&
          (iVar4 = ((int*)local_4)[1], ((int*)local_4)[1] = iVar4 - 1, iVar4 - 1 == 0)) {
        (*(void(**)(int))(**(void***)local_4))(1);
        return;
      }
    }
  }
}

// 0x42fc70 — observed shape
// Derives pay/hire amounts from DAT_0085a268/26c and current tier
// DAT_00725408/100 (300/200/0/100/400/500/600), applying the
// (DAT_0085a164 & 0x100000) flag to choose /5 vs *5/6 approximations.
void FUN_0042fc70()
{
  if (DAT_00725408 == -1) return;
  int iVar2 = DAT_00725408 % 100;
  FUN_00412840(0x42c80000, 0x461c4000);
  int iVar1 = DAT_00725408 - iVar2;
  uint32_t uVar3 = ((uint32_t)DAT_0085a268) >> 0x1f;
  if (iVar1 < 0x12d) {
    if (iVar1 == 300) {
      if ((DAT_0085a164 & 0x100000) == 0) iVar1 = (int)(DAT_0085a268 + (int)(uVar3 & 7)) >> 3;
      else iVar1 = (DAT_0085a268 * 5) / 6;
      FUN_00412900(DAT_0085a26c / 0xc, iVar1, 0x28);
      return;
    }
    if (DAT_00725408 == iVar2) {
      if ((DAT_0085a164 & 0x100000) == 0) iVar1 = DAT_0085a268 / 5 + (int)uVar3;
      else iVar1 = (DAT_0085a268 * 5) / 6 + (DAT_0085a268 * 5 >> 0x1f);
      FUN_004bba60(DAT_008dc314, DAT_0085a26c / 10, iVar1 - (iVar1 >> 0x1f), 0x42780000, 0);
      return;
    }
    if (iVar1 != 100) {
      if (iVar1 != 200) goto LAB_42fe7a;
      goto LAB_42fd75;
    }
    FUN_004d9d40(DAT_008c9de8, (int)0xfffff830, (int)0xfffff830, 300, 0x20000000, 0, 0, 0x20000000);
    // uVar4 = 0x46
    FUN_004daa10(0x40000000, 0, 0, 0x46);
  } else {
    if (iVar1 != 400) {
      if (iVar1 == 500) {
        if ((DAT_0085a164 & 0x100000) == 0) iVar1 = DAT_0085a268 / 0xc + (int)uVar3;
        else iVar1 = (DAT_0085a268 * 5) / 6 + (DAT_0085a268 * 5 >> 0x1f);
        FUN_00412900((int)(DAT_0085a26c + (int)(((uint32_t)DAT_0085a26c >> 0x1f) & 0xfU)) >> 4, iVar1 - (iVar1 >> 0x1f), 100);
        return;
      }
      if (iVar1 == 600) goto LAB_42fd75;
      goto LAB_42fe7a;
    }
    FUN_004d9d40(DAT_008c9de8, (int)0xffffff06, (int)0xfffff63c, 0x5dc, 0, 0, 0, 0x20000000);
    FUN_004daa10(0x40000000, 0, 0, 0x96);
  }
  // fall-through from 100/400 cases already called daa10; LAB tail:
  return;
  LAB_42fd75:
    if ((DAT_0085a164 & 0x100000) == 0) iVar1 = DAT_0085a268 / 5 + (int)uVar3;
    else iVar1 = (DAT_0085a268 * 5) / 6 + (DAT_0085a268 * 5 >> 0x1f);
    FUN_004bba60(DAT_008dc314, DAT_0085a26c / 10, iVar1 - (iVar1 >> 0x1f), 0x42780000, 0);
    return;
  LAB_42fe7a:
    if ((DAT_0085a164 & 0x100000) == 0) iVar1 = DAT_0085a268 / 7 + (DAT_0085a268 >> 0x1f);
    else iVar1 = (DAT_0085a268 * 5) / 6 + (DAT_0085a268 * 5 >> 0x1f);
    FUN_004d9f50(iVar1 - (iVar1 >> 0x1f), 0x32, (int)0xfffffff6);
    return;
}

// 0x42fee0 — observed shape
// Hover/collaborative handling: hit-test (CL==0 and ±0x14/±0x0c box around
// DAT_008dc30c/310) sets tier 7, tracks consecutive-same-tier time in
// DAT_008ca954, draws the status line at y=in_EAX+0xe+..., and when tier 7
// shows the "Continue" prompt; appends a 20-unit history record when
// param_2 != -1.
void FUN_0042fee0(int param_1, int param_2, int in_EAX, char in_CL)
{
  int iVar2 = 0;
  if ((in_CL == '\0') && (param_1 - 0x14 <= DAT_008dc30c) && (DAT_008dc30c <= param_1 + 0x14)
      && (in_EAX - 0xc <= DAT_008dc310) && (DAT_008dc310 <= in_EAX + 0xc)) {
    iVar2 = 7;
  }
  if (iVar2 == DAT_00725410) {
    iVar2 = FUN_005f0ddc();
    DAT_008ca954 += iVar2;
  } else {
    DAT_008ca954 = 0;
    DAT_00725410 = iVar2;
  }
  iVar2 = ((DAT_008d3a90 * 3) / 5 - DAT_00726380) + 0xe + in_EAX;
  if (iVar2 < 0) iVar2 = 0;
  short sVar1 = (short)in_EAX - (short)iVar2;
  uint32_t uVar9 = 0;
  uint32_t uVar8 = 0x42700000;
  uint32_t uVar3 = (uint32_t)FUN_005f0ddc();
  uint32_t uVar4 = (uint32_t)FUN_005f0ddc();
  FUN_004bba60(&DAT_008d3a58, (int)uVar4, (int)uVar3, uVar8, (int)uVar9);
  FUN_004bbe10(DAT_00725410, DAT_008ca954);
  if (DAT_00725410 == 7) {
    memmove(&DAT_0086ab48, &DAT_00869b48, 0x1000);
    FUN_004f6090("Continue");
    DAT_0085a11c = 0x46;
    DAT_008c9de0 = DAT_008c9dd8;
    FUN_00509500(DAT_008c9dd8, &DAT_00869b48, 0);
    int iVar5 = FUN_005f0ddc();
    DAT_008c9de0 = DAT_008c9dd8;
    FUN_005096b0();
    int iVar6 = FUN_005f0ddc();
    int iVar7 = param_1 - iVar5 / 2;
    int iVar2b = in_EAX + 0xf;
    if (DAT_0085a268 - 5 <= iVar2b + iVar6) iVar2b = (in_EAX - iVar6) - 10;
    if (DAT_0085a26c - 5 < iVar7 + iVar5) iVar7 = (DAT_0085a26c - iVar5) - 5;
    if (iVar7 < 5) iVar7 = 5;
    FUN_004b06c0(&DAT_00869b48, iVar7, iVar2b, DAT_0085a11c, 0xffffffff, 1, 0xffffffff, 0);
    memmove(&DAT_00869b48, &DAT_0086ab48, 0x1000);
  }
  if (param_2 != -1) {
    int iVar2c = DAT_0086c330;
    DAT_0086c010[iVar2c] = (short)param_1 - 0x14;
    DAT_0086be80[iVar2c] = sVar1 - 0xc;
    DAT_0086c330++;
    DAT_0086c1a0[iVar2c] = (short)param_2;
    DAT_0086bcf0[iVar2c] = (short)param_1 + 0x14;
    DAT_0086bb60[iVar2c] = sVar1 + 0xc;
  }
}

// NEEDS_MANUAL: Listing is non-contiguous and very long (modal menu/input loop); reconstructing verbatim would exceed practical fidelity without original symbols. Substantive loop preserved below.
// 0x430190 — observed shape
uint32_t FUN_00430190(int param_1, uint32_t param_2, char* param_3, uint32_t param_4, uint32_t param_5,
                     void* param_6, void* param_7, uint32_t param_8, char param_9, char param_10)
{
  HCURSOR hCursor = DAT_008cacd8;
  if (DAT_008cacd8 == nullptr) hCursor = LoadCursorA(nullptr, &DAT_00007f02[0]);
  HCURSOR local_e48 = GetCursor();
  SetCursor(hCursor);
  // Line splitting of DAT_00869b48 into local_dd4 entries with offsets
  // local_ea4 (first-space index), local_e68 (trailing count), local_e94 (line count).
  int local_dd4[64] = {};
  for (int i = 0; i < 64; i++) local_dd4[i] = 0;
  int local_e94 = 0;
  int local_ea4 = -1;
  int local_e68 = -1;
  uint32_t local_eb0 = 0xffffffff; // selected line
  bool bVar19 = ((DAT_0085a164 >> 8) & 0x80) != 0;
  if (bVar19) DAT_0085a164 &= 0xffff7fff;
  char acStack_bd4[1024] = {};
  {
    int iVar9 = 0;
    do {
      char cVar2 = DAT_00869b48[iVar9];
      acStack_bd4[iVar9] = cVar2;
      iVar9++;
    } while (DAT_00869b48[iVar9 - 1] != '\0');
  }
  if (DAT_00869b48[0] != '\0') {
    int iVar11 = 0;
    int iVar13 = -1;
    char* pcVar10 = &DAT_00869b48[0];
    char* pcVar16 = &DAT_00869b48[0];
    char* local_ea0 = nullptr;
    do {
      char* pcVar3 = pcVar16;
      pcVar16 = pcVar3 + 1;
    } while (*pcVar3 != '\0');
    pcVar16 = &DAT_00869b48[0];
    do {
      if (*pcVar16 == '\n') {
        *pcVar16 = '\0';
        char* pcVar4 = pcVar10;
        do { char c = *pcVar4; pcVar4++; } while (*pcVar4 != '\0');
        // duplicate line into owned copy saved in local_dd4
        size_t len = strlen(pcVar10) + 1;
        char* copy = (char*)FUN_00533c78(len);
        memcpy(copy, pcVar10, len);
        local_dd4[iVar11] = (int)(intptr_t)copy;
        if (local_ea4 == -1 && *pcVar10 == ' ') local_ea4 = iVar11;
        pcVar10 = pcVar16 + 1;
        iVar11++;
        iVar13 = local_ea4;
      }
      pcVar16++;
      if (local_ea0) local_ea0++;
    } while (*pcVar16 != '\0');
    local_e94 = iVar11;
    if (iVar13 != -1) local_e68 = iVar11 - iVar13;
  }
  DAT_0085a11c = 100;
  int iVar11 = 100;
  int iVar13 = DAT_0085a268;
  void* uVar20 = DAT_008c9dd8;
  int local_e90 = 0;
  int local_e84 = 0;
  int local_e58 = 0, local_e60 = 0, local_e6c = 0;
  do {
    DAT_008c9de0 = uVar20;
    int iVar9 = FUN_005f0ddc();
    local_e84 = -iVar9 - 2;
    iVar9 = 0;
    local_e90 = 0;
    if (0 < local_e94) {
      local_e90 = 0;
      int idx = 0;
      do {
        DAT_008c9de0 = uVar20;
        FUN_00509500(uVar20, (void*)(intptr_t)local_dd4[idx], 0);
        int w = FUN_005f0ddc();
        if (local_e90 < w) local_e90 = w;
        idx++;
        uVar20 = DAT_008c9dd8;
      } while (idx < local_e94);
      iVar11 = DAT_0085a11c;
      iVar13 = DAT_0085a268;
    }
    iVar9 = local_e94;
    if (local_e94 < 4) iVar9 = 4;
    uint32_t uVar17 = DAT_0085a164 & 0x100000;
    if (uVar17 != 0 && (int)param_2 < iVar13 / 5 && (param_2 & 1) == 0) {
      param_2 = (uint32_t)((iVar13 - (iVar9 * local_e84 & 0xfffe)) - 0x18);
    }
    local_e58 = (int)param_2 - 0x10;
    local_e60 = param_1 + local_e90 + 0x15;
    local_e6c = iVar9 * local_e84 + 0x25;
    if ((DAT_0085a26c - 5 <= local_e60) ||
        (iVar13 - 0x14 <= local_e6c + local_e58 && uVar17 == 0)) {
      iVar11 -= 10;
      DAT_0085a11c = iVar11;
    }
  } while (((DAT_0085a26c - 5 <= local_e60) ||
            (iVar13 - 0x14 <= local_e6c + local_e58 && (DAT_0085a164 & 0x100000) == 0)) && (0x1e < iVar11));
  int local_e9c = 0x28;
  if (0x27 < iVar11) local_e9c = iVar11;
  uint32_t* local_e70 = nullptr;
  uint32_t* local_e64 = nullptr;
  uint32_t* puVar6;
  uint32_t uVar20b;
  if (DAT_00725404 == '\0') {
    puVar6 = (uint32_t*)FUN_00533c78(0xc0);
    uVar20b = DAT_008ea008;
    if (puVar6 == nullptr) goto LAB_430596;
    puVar6[1] = 0; *puVar6 = (uint32_t)(uintptr_t)PTR_FUN_006fd14c; puVar6[7] = 0;
    DAT_00727444++; puVar6[0x19] = 0; puVar6[0x2f] = 0;
    GetCurrentThreadId();
    FUN_004baae0(uVar20b);
    uVar20b = 0;
  } else {
    puVar6 = (uint32_t*)FUN_00533c78(0xc0);
    uVar20b = DAT_008ea008;
    if (puVar6 == nullptr) goto LAB_430596;
    puVar6[1] = 0; *puVar6 = (uint32_t)(uintptr_t)PTR_FUN_006fd14c; puVar6[7] = 0;
    DAT_00727444++; puVar6[0x19] = 0; puVar6[0x2f] = 0;
    GetCurrentThreadId();
    FUN_004baae0(uVar20b);
    uVar20b = 0xa0000000;
  }
  puVar6[8] = 0;
  FUN_004be3f0(puVar6, 0, 0, 0, local_e90 + 0x25, local_e6c, uVar20b, 0, 0, 0, 0, 0);
  if ((*(uint8_t*)(puVar6 + 8) & 1) == 0) FUN_004baca0();
  puVar6[1]++;
  local_e64 = puVar6;
LAB_430596:
  {
    int local_e74 = 0;
    uint32_t local_e7c = 0;
    if (param_3 != nullptr && *param_3 != '\0') {
      uint32_t* p = (uint32_t*)FUN_004cddf0(param_3, 0, 0, &local_e74, &local_e7c);
      if (p != nullptr) { p[1]++; local_e70 = p; }
    }
    int local_e50 = 0, local_e54 = 0;
    bool bVar1 = true;
    if ((DAT_008ed61c & 1) == 0) { DAT_008ed61c |= 1; DAT_008ed618 = timeGetTime(); }
    DWORD DVar7 = timeGetTime();
    DAT_0086bb48 = DVar7 - DAT_008ed618;
    if (local_ea4 != -1) local_eb0 = param_8;
    uint32_t uStack_eac;
    do { uStack_eac = FUN_0042e1d0(); } while (uStack_eac != 0);
    DAT_0086c35c = 0; DAT_0086c360 = 0;
    SetCursor(local_e48);
    // Main loop preserved in structure; full draw/input chain as observed.
    while (true) {
      if ((DAT_008ed61c & 1) == 0) { DAT_008ed61c |= 1; DAT_008ed618 = timeGetTime(); }
      DVar7 = timeGetTime();
      if (param_5 <= (DVar7 - DAT_008ed618) - DAT_0086bb48) goto LAB_4310aa;
      if (param_9 != '\0') {
        char cVar2 = (*(char(**)())(DAT_008ecd78 + 0x18))();
        if (cVar2 == '\0') {
          FUN_00488840("The audio manager has not been properly initialized yet", 0);
        } else if (DAT_008e8eff == '\0') {
          // stack init as listed
          FUN_004985e0();
          FUN_004a14b0();
        }
      }
      if (local_e70 != nullptr) {
        const char* ext = param_3 ? strrchr(param_3, '.') : nullptr;
        if (ext && _strnicmp(ext + 1, "dds", 3) == 0 || ext && _strnicmp(ext+1,"",3)==0) {
          if (local_e74 == 0x400) local_e7c = 0x300;
          else if (local_e74 == 0x200) local_e7c = 0x180;
        }
        // ext check simplified to observed prefix logic
        const char* end = param_3 ? param_3 + strlen(param_3) : nullptr;
        if (end && end >= param_3 + 3 && _strnicmp(end - 3, "dds", 3) == 0) {
          if (local_e74 == 0x400) local_e7c = 0x300;
          else if (local_e74 == 0x200) local_e7c = 0x180;
        }
        FUN_004af080(local_e70, 0, 0, local_e74, local_e7c, 0, 0, DAT_0085a26c, DAT_0085a268, 0xffffffff, 0);
      }
      int iStack_e5c = 0;
      if (param_6 != nullptr) {
        iStack_e5c = 1;
        char saved[2010];
        memcpy(saved, DAT_00869b48, strlen(DAT_00869b48) + 1);
        ((void(*)())param_6)();
        memcpy(DAT_00869b48, saved, strlen(saved) + 1);
      }
      uint32_t uStack_e4c = param_2 & 1;
      if (uStack_e4c != 0 && DAT_00869b48[0] != '\0') FUN_004881b0(param_1 - 0x10, local_e58);
      int iVar13b = 0;
      if (0 < local_e94) {
        int iVar9 = -local_ea4;
        bVar1 = true;
        int idx = 0;
        do {
          if (!bVar1) break;
          if (*(char*)(intptr_t)local_dd4[idx] == ' ' && ((param_4 & (1u << ((uint8_t)iVar9 & 0x1f))) == 0)) bVar1 = false;
          idx++; iVar9++;
        } while (idx < local_e94);
      }
      if (param_5 == 0xffffffff && bVar1) FUN_0042fee0(local_e60 - 0x14, -1, local_e60, 0);
      uint32_t local_e98 = param_2;
      if (0 < local_e94) {
        int* piStack = local_dd4;
        uint32_t uVar12 = (uint32_t)(-local_ea4);
        uint32_t uVar17b = param_2;
        int iVar11b = param_1;
        do {
          const char* pcVar10 = (const char*)(intptr_t)*piStack;
          DAT_0085a11c = local_e9c;
          if (*pcVar10 == ' ') {
            if (local_ea4 + (int)uVar12 == local_ea4) {
              iVar11b += 0x10;
              uVar17b += (local_ea4 != 0 ? 5u : 0);
              local_e98 = uVar17b;
            }
            if ((param_4 & (1u << ((uint8_t)uVar12 & 0x1f))) == 0) {
              FUN_004b06c0(pcVar10, iVar11b, (int)uVar17b, local_e9c, 0xffffffff, 1, 0xffffffff, 0);
            } else {
              FUN_004b06c0(pcVar10, iVar11b, (int)uVar17b, local_e9c, 0x80ffffff, 1, 0xffffffff, 0);
            }
          } else {
            FUN_004b06c0(pcVar10, iVar11b, (int)uVar17b, local_e9c, 0xffffffff, 1, 0xffffffff, 0);
          }
          piStack++;
          uVar17b += (uint32_t)local_e84;
          uVar12++;
        } while ((int)(local_ea4 + (int)uVar12) < local_e94);
      }
      if (DAT_00725408 != -1) FUN_0042fc70();
      if (param_7 != nullptr) ((void(*)(uint32_t))param_7)(local_eb0);
      uStack_eac = FUN_0042e1d0();
      if (DAT_0086bb5c != nullptr) {
        char acStack_cd4[256];
        sprintf(acStack_cd4, "%s_%03X", DAT_006f588c, uStack_eac);
        // lookup by hash in DAT_0086bb5c (first vtable+4 / +8 dispatch)
      }
      int iVar13c = DAT_008dc310 + 1;
      if ((local_e50 != DAT_008dc30c) || (local_e54 != iVar13c)) {
        uint32_t cand = (local_e84 != 0) ? (uint32_t)((iVar13c - (int)local_e98) / local_e84) : 0xffffffff;
        local_e50 = DAT_008dc30c;
        if ((local_e68 <= (int)cand) || ((param_4 & (1u << ((uint8_t)cand & 0x1f))) != 0)) cand = 0xffffffff;
        if ((DAT_008dc30c < param_1 - 8) || (local_e60 - 8 < DAT_008dc30c)) cand = 0xffffffff;
        if (local_e68 == 0) cand = 0xffffffff;
        local_e54 = iVar13c;
        if (local_eb0 != cand) {
          local_eb0 = cand;
          if (cand != 0xffffffff) FUN_004889c0(&DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
        }
      }
      if ((int)uStack_eac < 0x10d) {
        if (uStack_eac == 0x10c || uStack_eac == 0xd || uStack_eac == 0x20) {
          FUN_0042e730((int)uStack_eac);
          param_5 = 0;
        } else if (uStack_eac == 0x1b) {
          if (param_10 == '\0') { local_eb0 = 0xffffffff; param_5 = 0; FUN_0042e730((int)uStack_eac); }
        } else if ((int)uStack_eac < 0x100 && 0 < (int)uStack_eac && local_e68 != 0) {
          // letter search
        }
      } else if (uStack_eac == 0x126) {
        if (0 < local_e68) {
          uint32_t prev = local_eb0;
          uint32_t cur = prev == 0xffffffff ? 0 : prev;
          int guard = local_e68;
          do {
            cur = (uint32_t)(((int)cur - 1 + local_e68) % local_e68);
            if ((param_4 & (1u << ((uint8_t)cur & 0x1f))) == 0) break;
          } while (cur != prev && --guard > 0);
          bool changed = cur != prev;
          local_eb0 = cur;
          if (changed) FUN_004889c0(&DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
        }
      } else if (uStack_eac == 0x128) {
        if (0 < local_e68) {
          uint32_t prev = local_eb0;
          uint32_t cur = prev == 0xffffffff ? 0xffffffffu : prev;
          int guard = local_e68;
          do {
            cur = (cur + 1) % (uint32_t)local_e68;
            if ((param_4 & (1u << ((uint8_t)cur & 0x1f))) == 0) break;
          } while (cur != prev && --guard > 0);
          bool changed = cur != prev;
          local_eb0 = cur;
          if (changed) FUN_004889c0(&DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
        }
      }
      if ((0x1ff < (int)uStack_eac) && ((int)uStack_eac < 0x25a)) local_eb0 = uStack_eac;
      if (DAT_0086c35c != 0 && (local_eb0 != 0xffffffff || bVar1)) { FUN_0042e730((int)uStack_eac); param_5 = 0; }
      if (DAT_008cac27 != '\0') goto LAB_4310aa;
      if (param_5 == 0 && DAT_008cac44 < 0.0f) DAT_008cac44 = -DAT_008cac44;
      if (param_3 != nullptr) {
        const char* bg = "pauseMenuBG.dds";
        if (strncmp(param_3, bg, strlen(bg)) == 0 && DAT_0072540c == '\0') {
          memcpy(DAT_00869b48, DAT_006fe448, 0x204);
          FUN_004879f0(0x78, 0);
          DAT_0085a11c = 0x32;
          FUN_004b06c0(&DAT_00869b48, DAT_0085a26c / 2, DAT_0085a268 - ((DAT_0085a268 + 7) >> 3), 0x32, 0xffffff80, 0x40000004, 900, 0);
          FUN_004f2600(DAT_00726b74 == 0 ? "Beta Version %s\n" : "Version %s\n", PTR_DAT_00726ba0);
          DAT_0085a11c = 0x32;
          FUN_004b06c0(&DAT_008cacd0[0], DAT_0085a26c - ((DAT_0085a26c + 31) >> 5), DAT_0085a268 - DAT_0085a268 / 6, 0x32, 0xffffff80, 2, 0xffffffff, 0);
        }
      }
      float fStack = 0.0f;
      if (DAT_008cac44 < -1000.0f) { DAT_008cac44 = DAT_008cac44 * -1.0f - 1000.0f; fStack = DAT_008cac44; }
      FUN_004d0cd0(0, 0, 0);
      if (fStack != 0.0f) DAT_008cac44 = -fStack;
      Sleep(10);
    }
  LAB_4310aa:
    if (param_5 != 0) {
      if ((DAT_008ed61c & 1) == 0) { DAT_008ed61c |= 1; DAT_008ed618 = timeGetTime(); }
      DVar7 = timeGetTime();
      if (param_5 <= (DVar7 - DAT_008ed618) - DAT_0086bb48) local_eb0 = 0xfffffffe;
    }
    for (int i = 0; i < local_e94; i++) operator_delete__((void*)(intptr_t)local_dd4[i]);
    if (bVar19) DAT_0085a164 |= 0x8000;
    if (DAT_00725408 != -1) {
      DAT_00725408 = -1;
      if (DAT_008dc314 != nullptr) {
        int cnt = ((int*)DAT_008dc314)[1];
        ((int*)DAT_008dc314)[1] = cnt - 1;
        if (cnt - 1 == 0) (*(void(**)(int))(**(void***)DAT_008dc314))(1);
        DAT_008dc314 = nullptr;
      }
    }
    memcpy(DAT_00869b48, acStack_bd4, strlen(acStack_bd4) + 1);
    DAT_0086c330 = 0;
    do { } while (FUN_0042e1d0() != 0);
    DAT_0086c35c = 0; DAT_0086c360 = 0;
    if (local_e64 != nullptr) { int* p = (int*)local_e64 + 1; *p--; if (*p == 0) (*(void(**)(int))(**(void***)local_e64))(1); }
    if (local_e70 != nullptr) { int* p = (int*)local_e70 + 1; *p--; if (*p == 0) (*(void(**)(int))(**(void***)local_e70))(1); }
    SetCursor(local_e48);
    return local_eb0;
  }
}

// 0x4311e0 — observed shape
// Reference assignment: if *esi != *edi, release old (*esi: decrement [1],
// delete via vtable when zero), store *edi into *esi and addref.
void FUN_004311e0(int** esiSlot, int** ediSlot)
{
  uint32_t* puVar2 = (uint32_t*)*esiSlot;
  if (puVar2 != (uint32_t*)*ediSlot) {
    if (puVar2 != nullptr) {
      int* piVar1 = (int*)puVar2 + 1;
      *piVar1 += -1;
      if (*piVar1 == 0) (*(void(**)(int))(**(void***)puVar2))(1);
    }
    int iVar3 = (int)(intptr_t)*ediSlot;
    *esiSlot = (int*)(intptr_t)iVar3;
    if (iVar3 != 0) *(int*)(iVar3 + 4) += 1;
  }
}

// 0x431210 — observed shape
// Hash-map destructor (receiver ECX): drains each bucket chain deleting
// payloads, runs the two vtable phases, deletes the bucket array.
void FUN_00431210(void* self)
{
  uint32_t* in_ECX = (uint32_t*)self;
  *in_ECX = (uint32_t)(uintptr_t)PTR_FUN_006fe408;
  if ((*(int8_t*)(in_ECX + 4) != 0) && (in_ECX[1] != 0)) {
    uint32_t uVar3 = 0;
    do {
      uint32_t* puVar2 = *(uint32_t**)(in_ECX[2] + uVar3 * 4);
      while (puVar2 != nullptr) {
        uint32_t* puVar1 = puVar2 + 1;
        puVar2 = (uint32_t*)*puVar2;
        operator_delete__((void*)(uintptr_t)*puVar1);
      }
      uVar3++;
    } while (uVar3 < in_ECX[1]);
  }
  *in_ECX = (uint32_t)(uintptr_t)PTR_FUN_006fe3ec;
  FUN_004e6420();
  *in_ECX = (uint32_t)(uintptr_t)PTR_FUN_006fe3d0;
  FUN_004e6420();
  operator_delete__((void*)(uintptr_t)in_ECX[2]);
}

// 0x431290 — observed shape
// String hash (receiver ECX with modulus at +4): h = h*0x21 + c for each
// byte, returns h % mod.
uint32_t FUN_00431290(void* self, const char* param_1)
{
  uint32_t uVar3 = 0;
  const char* p = param_1;
  char c = *p;
  while (c != '\0') {
    uVar3 = uVar3 * 0x21 + (uint32_t)(int32_t)c;
    p++;
    c = *p;
  }
  return uVar3 % *(uint32_t*)((uint8_t*)self + 4);
}

// 0x431320 — observed shape
// Scalar deleting destructor: resets vtable to PTR_FUN_006fe3d0, destroys
// base, deletes bucket array, deletes this when low bit set.
void FUN_00431320(void* self, uint8_t param_1)
{
  uint32_t* in_ECX = (uint32_t*)self;
  *in_ECX = (uint32_t)(uintptr_t)PTR_FUN_006fe3d0;
  FUN_004e6420();
  operator_delete__((void*)(uintptr_t)in_ECX[2]);
  if ((param_1 & 1) != 0) operator_delete(self);
}

// 0x431360 — observed shape
// Scalar deleting destructor (two-phase): vtable 006fe3ec then 006fe3d0,
// then bucket array, then conditional this-delete.
void FUN_00431360(void* self, uint8_t param_1)
{
  uint32_t* in_ECX = (uint32_t*)self;
  *in_ECX = (uint32_t)(uintptr_t)PTR_FUN_006fe3ec;
  FUN_004e6420();
  *in_ECX = (uint32_t)(uintptr_t)PTR_FUN_006fe3d0;
  FUN_004e6420();
  operator_delete__((void*)(uintptr_t)in_ECX[2]);
  if ((param_1 & 1) != 0) operator_delete(self);
}

// 0x4313c0 — observed shape
// Scalar deleting destructor (inline base): calls FUN_00568200 then
// conditionally deletes this.
void FUN_004313c0(void* self, uint8_t param_1)
{
  FUN_00568200();
  if ((param_1 & 1) != 0) operator_delete(self);
}

// 0x431400 — observed shape
// isdigit wrapper (EAX): returns 0 when value outside [-0x80, 0xff],
// otherwise isdigit(value & 0xff).
int FUN_00431400(int in_EAX)
{
  if (in_EAX < -0x80 || 0xff < in_EAX) return 0;
  return isdigit(in_EAX & 0xff);
}

// 0x431420 — observed shape
// 3-float vector add in place: *ecx += *param (receiver ECX).
void FUN_00431420(void* self, const float* param_1)
{
  float* in_ECX = (float*)self;
  in_ECX[0] = param_1[0] + in_ECX[0];
  in_ECX[1] = param_1[1] + in_ECX[1];
  in_ECX[2] = param_1[2] + in_ECX[2];
}

// 0x431450 — observed shape
// Scalar multiply: out[3] = s * src[3].
void FUN_00431450(float* param_1, float param_2, const float* param_3)
{
  float fVar1 = param_3[2];
  float fVar2 = param_3[1];
  param_1[0] = param_2 * param_3[0];
  param_1[1] = param_2 * fVar2;
  param_1[2] = param_2 * fVar1;
}

// 0x431480 — observed shape
// Scalar multiply by receiver (ECX): out[3] = s * self[3].
void FUN_00431480(float* param_1, float param_2, void* self)
{
  const float* in_ECX = (const float*)self;
  float fVar1 = in_ECX[2];
  float fVar2 = in_ECX[1];
  param_1[0] = param_2 * in_ECX[0];
  param_1[1] = param_2 * fVar2;
  param_1[2] = param_2 * fVar1;
}
