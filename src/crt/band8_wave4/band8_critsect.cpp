// UNVERIFIED: no cl 13.10.3077. No PASS claim. Clean-room from shipped bytes + REA pseudocode.
// Band 8 wave4 DeleteCriticalSection teardown stubs + operator_delete teardown stub.
// Evidence: analysis/pseudocode/functions/0x6bfb10.c, 0x6bfb40.c, 0x6bfb70.c, 0x6bf9f0.c;
// line range 0x6bfb10-0x6bfb5b / 0x6bf9f0-0x6bf9fc; triage: DAT_00727870 / DAT_00727940 / DAT_007279a8 / DAT_007273ec.
#include <stddef.h>
extern "C" int DeleteCriticalSection(void* cs);  // Win32 import, declared not defined.
extern "C" void operator_delete(void* p);        // CRT import, declared not defined.
extern unsigned char DAT_00727870[];
extern unsigned char DAT_00727940[];
extern unsigned char DAT_007279a8[];
extern unsigned char DAT_007273ec[];

// 0x006bfb10 — observed purpose: DeleteCriticalSection on global DAT_00727870 (12-byte body)
void FUN_006bfb10(void) {
  DeleteCriticalSection(DAT_00727870);
}

// 0x006bfb40 — observed purpose: DeleteCriticalSection on global DAT_00727940 (12-byte body)
void FUN_006bfb40(void) {
  DeleteCriticalSection(DAT_00727940);
}

// 0x006bfb70 — observed purpose: DeleteCriticalSection on global DAT_007279a8 (12-byte body)
void FUN_006bfb70(void) {
  DeleteCriticalSection(DAT_007279a8);
}

// 0x006bf9f0 — observed purpose: operator_delete on global DAT_007273ec (13-byte body)
void FUN_006bf9f0(void) {
  operator_delete(DAT_007273ec);
}
