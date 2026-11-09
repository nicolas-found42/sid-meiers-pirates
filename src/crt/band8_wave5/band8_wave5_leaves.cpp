// UNVERIFIED: no cl 13.10.3077. No PASS claim. Clean-room from shipped bytes + REA pseudocode.
// Band 8 wave5 scalar leaves, setters, closers, and guarded-delete wrappers.
// Evidence: analysis/pseudocode/functions/0x6916d0.c, 0x6ae3b0.c, 0x6a8cb0.c, 0x6beda0.c,
// 0x6923d0.c, 0x69359e.c, 0x6ab890.c, 0x6b5090.c, 0x6a3cfb.c, 0x6b3380.c.
#include <stddef.h>
#include <stdio.h>
extern void FUN_006915b0(void);
extern void FUN_006a8c60(void);
extern void FUN_006a0238(void);
extern void FUN_006b3330(void);
extern "C" void operator_delete(void* p);          // CRT import, declared not defined.
extern unsigned char PTR_LAB_0070c160[];
extern unsigned char PTR_FUN_007109b0[];
extern unsigned char DAT_00726a84[];

// 0x006916d0 — observed purpose: store FUN_006915b0 through double-indirect at this+0x1b8 (span 24)
void FUN_006916d0(int param_1) {
  **(void***)((char*)param_1 + 0x1b8) = FUN_006915b0;
}

// 0x006ae3b0 — observed purpose: fclose FILE* at param_2+0xc (span 24)
void FUN_006ae3b0(unsigned int param_1, int param_2) {
  (void)param_1;
  fclose(*(FILE**)((char*)&param_2 + 0xc));
}

// 0x006a8cb0 — observed purpose: zero dword at param_1+0x98 then call FUN_006a8c60 (span 27)
void FUN_006a8cb0(int param_1) {
  *(unsigned int*)((char*)param_1 + 0x98) = 0;
  FUN_006a8c60();
}

// 0x006beda0 — observed purpose: point global slot to PTR_LAB_0070c160 and zero DAT_00726a84 (span 21)
void FUN_006beda0(void) {
  *(void**)&*(unsigned char*)0x007268f0 = (void*)PTR_LAB_0070c160;
  *(unsigned int*)DAT_00726a84 = 0;
}

// 0x006923d0 — observed purpose: round param_1 down to multiple of param_2: (p1-1+p2) - (p1-1+p2)%p2 (span 30)
int FUN_006923d0(int param_1, int param_2) {
  int v = param_1 + -1 + param_2;
  return v - v % param_2;
}

// 0x0069359e — observed purpose: pack 4 bytes at param_1 into one dword in order (span 41)
unsigned int FUN_0069359e(const unsigned char* param_1) {
  return ((unsigned int)param_1[0]) | ((unsigned int)param_1[1] << 8) |
         ((unsigned int)param_1[2] << 16) | ((unsigned int)param_1[3] << 24);
}

// 0x006ab890 — observed purpose: overwrite *param_4 with param_3 (span 17)
void FUN_006ab890(unsigned int param_1, unsigned int param_2, unsigned int param_3, unsigned int* param_4) {
  (void)param_1; (void)param_2;
  *param_4 = param_3;
}

// 0x006b5090 — observed purpose: call vft version at (*param_1)+8 with (param_2,4); return result==4 (span 23)
int FUN_006b5090(int* param_1, unsigned int param_2) {
  int r = (**(**int***)((char*)*param_1 + 8))(param_2, 4u);
  return r == 4;
}

// 0x006a3cfb — observed purpose: call FUN_006a0238 then guarded operator_delete on in_ECX when flag&1 (span 33)
void FUN_006a3cfb(unsigned char param_1, void* in_ecx) {
  FUN_006a0238();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ecx);
  }
}

// 0x006b3380 — observed purpose: call FUN_006b3330 then guarded operator_delete on in_ECX when flag&1 (span 30)
void FUN_006b3380(unsigned char param_1, void* in_ecx) {
  FUN_006b3330();
  if ((param_1 & 1) != 0) {
    operator_delete(in_ecx);
  }
}
