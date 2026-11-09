// UNVERIFIED: no cl 13.10.3077. No PASS claim. Clean-room from shipped bytes + REA pseudocode.
// Band 8 wave3 CRT/ATL teardown leaves + small forwarders.
#include <stddef.h>
#include <stdint.h>

void FUN_0068f6ce(void);

// ATL base module referenced via DAT_00727370 in pseudocode 0x6bf9d7.c.
struct CAtlBaseModuleStub { unsigned char _b[16]; };
extern "C" void AtlBaseModuleDtor(CAtlBaseModuleStub* p);
extern unsigned char DAT_00727370[];

// 0x006bf9d7
void FUN_006bf9d7(void) {
  AtlBaseModuleDtor(reinterpret_cast<CAtlBaseModuleStub*>(DAT_00727370));
}

// 0x0068f924
void FUN_0068f924(void) {
  FUN_0068f6ce();
}

// 0x006b3910 (constructor: vtable install then base init; in_ECX is the this pointer)
extern "C" void* PTR_FUN_006f5310;
void FUN_006b50f0(void);

void FUN_006b3910(void* thisptr) {
  *(void**)thisptr = PTR_FUN_006f5310;
  FUN_006b50f0();
}
