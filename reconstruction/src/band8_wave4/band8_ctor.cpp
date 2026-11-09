// UNVERIFIED: no cl 13.10.3077. No PASS claim. Clean-room from shipped bytes + REA pseudocode.
// Band 8 wave4 constructor/dtors with vtable install and register-passed this (in_ECX).
// Evidence: analysis/pseudocode/functions/0x6b91f0.c, 0x6949b1.c, 0x6840fd.c.
// Per STYLE.md: in_ECX-only bodies keep observed offsets via reinterpret_cast; no invented field names.
#include <stddef.h>
#include <stdint.h>
extern "C" void FastExitMediaState(void);  // Win32 import, declared not defined.
extern void* PTR_FUN_006f57c8;
extern void* PTR_FUN_006f0938;
void FUN_006b7510(int a);
void FUN_006a0152(void);
void FUN_0068f010(int a, int b, int c);

// 0x006b91f0 — observed purpose: call FUN_006b7510(param_1), then install vtable PTR_FUN_006f57c8 at *in_ECX (span 26).
// Pseudocode exposes only in_ECX (this pointer) and one stack param; recorded as (thisptr, param_1).
void FUN_006b91f0(void* thisptr, int param_1) {
  FUN_006b7510(param_1);
  *(void**)thisptr = PTR_FUN_006f57c8;
}

// 0x006949b1 — observed purpose: extract shifted bitfield word at +0xe8 by count at +0xec (span 26).
// Pseudocode reads in_ECX + 0xe8 / + 0xec; this pointer supplied via in_ECX, no stack entry for the base.
unsigned int FUN_006949b1(const unsigned char* in_ecx_base, unsigned int param_1) {
  unsigned int word = *(const unsigned int*)(in_ecx_base + 0xe8);
  unsigned int count = *(const unsigned int*)(in_ecx_base + 0xec);
  return (word & param_1) >> (count & 0x1f);
}

// 0x006840fd — observed purpose: call FUN_006a0152(), clear word at +0x1f8 (0x7e index), install PTR_FUN_006f0938 (span 27)
void FUN_006840fd(void* thisptr) {
  FUN_006a0152();
  *(unsigned int*)((unsigned char*)thisptr + 0x1f8) = 0;
  *(void**)thisptr = PTR_FUN_006f0938;
}

// 0x0068f346 — observed purpose: FastExitMediaState, call FUN_0068f010, FastExitMediaState again; return param_1 (span 30)
int FUN_0068f346(int param_1, int param_2, int param_3) {
  FastExitMediaState();
  FUN_0068f010(param_1, param_2, param_3);
  FastExitMediaState();
  return param_1;
}
