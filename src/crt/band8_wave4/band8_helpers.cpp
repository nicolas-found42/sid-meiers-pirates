// UNVERIFIED: no cl 13.10.3077. No PASS claim. Clean-room from shipped bytes + REA pseudocode.
// Band 8 wave4 small helpers: 3-arg forwarder, clamped wrapper, two-call sequence, guarded free, chain walker.
// Evidence: analysis/pseudocode/functions/0x693225.c, 0x6a49e3.c, 0x6935e2.c, 0x69252a.c, 0x6a0134.c.
#include <stddef.h>
#include <stdlib.h>
extern void FUN_00693146(int a, int b, int c, int d);
extern int FUN_006a2b66(int a);
extern void FUN_00658adc(int a, int b, int c);
extern void FUN_0065672d(void);

// 0x00693225 — observed purpose: forward (p1,p2,p3) to FUN_00693146 with constant 0xf in position 2 (span 22)
void FUN_00693225(int param_1, int param_2, int param_3) {
  FUN_00693146(param_1, 0xf, param_2, param_3);
}

// 0x006a49e3 — observed purpose: wrap FUN_006a2b66 result to 0 when >= 0 (span 23)
int FUN_006a49e3(int param_1) {
  int r = FUN_006a2b66(param_1);
  if (r >= 0) {
    r = 0;
  }
  return r;
}

// 0x006935e2 — observed purpose: call FUN_00658adc(p1,p2,p3) then terminal FUN_0065672d() (span 25)
void FUN_006935e2(int param_1, int param_2, int param_3) {
  FUN_00658adc(param_1, param_2, param_3);
  FUN_0065672d();
}

// 0x0069252a — observed purpose: free param_2 only when both args non-null (span 30)
void FUN_0069252a(int param_1, void* param_2) {
  if (param_1 != 0 && param_2 != nullptr) {
    free(param_2);
  }
}

// 0x006a0134 — observed purpose: walk 0x24-strided chain from param_1 while +0x10 word is neither -1 nor param_2 (span 30)
void FUN_006a0134(int param_1, int param_2) {
  for (; (*(int*)(param_1 + 0x10) != -1 && (*(int*)(param_1 + 0x10) != param_2));
       param_1 = param_1 + 0x24) {
  }
}
