// UNVERIFIED: no cl 13.10.3077. No PASS claim. Clean-room from shipped bytes + REA pseudocode.
// Band 8 wave3 D3DX9 shader opcode leaves (third-party bundled; see REPORT.md wave2 for context).
#include <stddef.h>
#include <stdint.h>
extern void FUN_006a629c(int code, int flags);

// 0x006a6863
void FUN_006a6863(void) {
  FUN_006a629c(5, 0);
}

// 0x006a686d
void FUN_006a686d(void) {
  FUN_006a629c(0x11, 0);
}

// 0x006a692a
void FUN_006a692a(void) {
  FUN_006a629c(0x10, 0);
}

// 0x006a6934
void FUN_006a6934(void) {
  FUN_006a629c(0x58, 0);
}

// 0x006a693e
void FUN_006a693e(void) {
  FUN_006a629c(0x50, 0);
}

// 0x006a6948
void FUN_006a6948(void) {
  FUN_006a629c(0x23, 0);
}
