// UNVERIFIED: no cl 13.10.3077. No PASS claim. Clean-room from shipped bytes + REA pseudocode.
// Band 8 wave3 DeleteCriticalSection teardown stubs.
#include <stddef.h>
extern "C" int DeleteCriticalSection(void* cs);
extern unsigned char DAT_00727404[];
extern unsigned char DAT_00727538[];
extern unsigned char DAT_00727834[];

// 0x006bfa00
void FUN_006bfa00(void) {
  DeleteCriticalSection(DAT_00727404);
}

// 0x006bfa10
void FUN_006bfa10(void) {
  DeleteCriticalSection(DAT_00727538);
}

// 0x006bfb00
void FUN_006bfb00(void) {
  DeleteCriticalSection(DAT_00727834);
}
