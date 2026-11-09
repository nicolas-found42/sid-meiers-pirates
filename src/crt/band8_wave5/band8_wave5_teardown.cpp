// UNVERIFIED: no cl 13.10.3077. No PASS claim. Clean-room from shipped bytes + REA pseudocode.
// Band 8 wave5 atexit/CloseHandle/operator_delete teardown group.
// Evidence: analysis/pseudocode/functions/0x6bbe40.c, 0x6bef90.c, 0x6bf650.c, 0x6bf6c0.c,
// 0x6bf780.c, 0x6bf7a0.c, 0x6bef20.c, 0x6bf730.c, 0x6bf830.c, 0x6bf8f0.c.
#include <stddef.h>
extern void FUN_006bf880(void);
extern void FUN_00527040(void);
extern void FUN_00530090(void);
extern "C" void operator_delete(void* p);          // CRT import, declared not defined.
extern "C" int CloseHandle(void* h);               // Win32 import, declared not defined.
extern "C" int atexit(void (*fn)(void));           // CRT import, declared not defined.
extern unsigned char DAT_00726b0c[];
extern unsigned char DAT_00726c1c[];
extern unsigned char DAT_00726c30[];
extern unsigned char DAT_0072705c[];
extern unsigned char DAT_00727064[];
extern unsigned char DAT_00726ac4[];
extern unsigned char DAT_00727044[];
extern unsigned char DAT_0072706c[];
extern void* DAT_008ed540;

// 0x006bbe40 — observed purpose: call FUN_00527040 then atexit-register FUN_006bf880 (span 22)
void FUN_006bbe40(void) {
  FUN_00527040();
  atexit(FUN_006bf880);
}

// 0x006bef90 — observed purpose: point vtable-slot global to PTR_FUN_007109b0 then CloseHandle DAT_00726b0c (span 23)
void FUN_006bef90(void) {
  *(void**)&*(unsigned char*)0x00726b08 = *(void**)&*(unsigned char*)0x007109b0;
  CloseHandle(DAT_00726b0c);
}

// 0x006bf650 — observed purpose: point vtable-slot global to PTR_FUN_007109b0 then CloseHandle DAT_00726c1c (span 23)
void FUN_006bf650(void) {
  *(void**)&*(unsigned char*)0x00726c18 = *(void**)&*(unsigned char*)0x007109b0;
  CloseHandle(DAT_00726c1c);
}

// 0x006bf6c0 — observed purpose: point vtable-slot global to PTR_FUN_007109b0 then CloseHandle DAT_00726c30 (span 23)
void FUN_006bf6c0(void) {
  *(void**)&*(unsigned char*)0x00726c2c = *(void**)&*(unsigned char*)0x007109b0;
  CloseHandle(DAT_00726c30);
}

// 0x006bf780 — observed purpose: point vtable-slot global to PTR_FUN_007109b0 then CloseHandle DAT_0072705c (span 23)
void FUN_006bf780(void) {
  *(void**)&*(unsigned char*)0x00727058 = *(void**)&*(unsigned char*)0x007109b0;
  CloseHandle(DAT_0072705c);
}

// 0x006bf7a0 — observed purpose: point vtable-slot global to PTR_FUN_007109b0 then CloseHandle DAT_00727064 (span 23)
void FUN_006bf7a0(void) {
  *(void**)&*(unsigned char*)0x00727060 = *(void**)&*(unsigned char*)0x007109b0;
  CloseHandle(DAT_00727064);
}

// 0x006bef20 — observed purpose: point vtable-slot global to PTR_FUN_0070d048 then operator_delete DAT_00726ac4 (span 23)
void FUN_006bef20(void) {
  *(void**)&*(unsigned char*)0x00726ac0 = *(void**)&*(unsigned char*)0x0070d048;
  operator_delete(DAT_00726ac4);
}

// 0x006bf730 — observed purpose: point vtable-slot global to PTR_FUN_007115f4 then operator_delete DAT_00727044 (span 23)
void FUN_006bf730(void) {
  *(void**)&*(unsigned char*)0x00727040 = *(void**)&*(unsigned char*)0x007115f4;
  operator_delete(DAT_00727044);
}

// 0x006bf830 — observed purpose: point vtable-slot global to PTR_FUN_007128c4 then operator_delete DAT_0072706c (span 23)
void FUN_006bf830(void) {
  *(void**)&*(unsigned char*)0x00727068 = *(void**)&*(unsigned char*)0x007128c4;
  operator_delete(DAT_0072706c);
}

// 0x006bf8f0 — observed purpose: call FUN_00530090 then operator_delete DAT_008ed540 and null it (span 37)
void FUN_006bf8f0(void) {
  FUN_00530090();
  operator_delete(DAT_008ed540);
  DAT_008ed540 = (void*)0x0;
}
