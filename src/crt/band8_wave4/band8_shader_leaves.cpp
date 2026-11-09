// UNVERIFIED: no cl 13.10.3077. No PASS claim. Clean-room from shipped bytes + REA pseudocode.
// Band 8 wave4 D3DX9 shader-opcode forwarders: read inner record at this+0x100, forward to FUN_006a6375.
// Evidence: analysis/pseudocode/functions/0x6a67af.c, 0x6a67d7.c, 0x6a67f5.c, 0x6a6813.c; span 30 each.
// Pseudocode exposes only in_ECX (this pointer); base offsets kept as byte arithmetic.
#include <stddef.h>
#include <stdint.h>
extern void FUN_006a6375(int code, unsigned int a, unsigned int b, unsigned int c, unsigned int d, int e, int f);

// 0x006a67af — observed purpose: forward to FUN_006a6375 with opcode 6 and record fields +0x10/+0x08/+0x0c/+0x04
void FUN_006a67af(const unsigned char* in_ecx_base) {
  unsigned int* rec = *(unsigned int**)(in_ecx_base + 0x100);
  FUN_006a6375(6, *(unsigned int*)(rec + 4), *(unsigned int*)(rec + 2),
               *(unsigned int*)(rec + 3), *(unsigned int*)(rec + 1), 0, 0);
}

// 0x006a67d7 — observed purpose: forward to FUN_006a6375 with opcode 0xe; same record field order
void FUN_006a67d7(const unsigned char* in_ecx_base) {
  unsigned int* rec = *(unsigned int**)(in_ecx_base + 0x100);
  FUN_006a6375(0xe, *(unsigned int*)(rec + 4), *(unsigned int*)(rec + 2),
               *(unsigned int*)(rec + 3), *(unsigned int*)(rec + 1), 0, 0);
}

// 0x006a67f5 — observed purpose: forward to FUN_006a6375 with opcode 0xf; same record field order
void FUN_006a67f5(const unsigned char* in_ecx_base) {
  unsigned int* rec = *(unsigned int**)(in_ecx_base + 0x100);
  FUN_006a6375(0xf, *(unsigned int*)(rec + 4), *(unsigned int*)(rec + 2),
               *(unsigned int*)(rec + 3), *(unsigned int*)(rec + 1), 0, 0);
}

// 0x006a6813 — observed purpose: forward to FUN_006a6375 with opcode 7; same record field order
void FUN_006a6813(const unsigned char* in_ecx_base) {
  unsigned int* rec = *(unsigned int**)(in_ecx_base + 0x100);
  FUN_006a6375(7, *(unsigned int*)(rec + 4), *(unsigned int*)(rec + 2),
               *(unsigned int*)(rec + 3), *(unsigned int*)(rec + 1), 0, 0);
}
