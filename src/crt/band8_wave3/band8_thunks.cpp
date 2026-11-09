// UNVERIFIED: no cl 13.10.3077. No PASS claim. Clean-room from shipped bytes + REA pseudocode.
// Band 8 wave3 terminal-call thunks (JUMP to FUN_004xxxx transitively; triage marks thunk=false).
extern void FUN_004baef0(void);
extern void FUN_004d4e00(void);
extern void FUN_004ab7c0(void);
extern void FUN_0045a050(void);
extern void FUN_004c2600(void);
extern void FUN_004d4be0(void);

// 0x006be2f0
void FUN_006be2f0(void) {
  FUN_004baef0();
}

// 0x006be380
void FUN_006be380(void) {
  FUN_004baef0();
}

// 0x006bec20
void FUN_006bec20(void) {
  FUN_004d4e00();
}

// 0x006bed60
void FUN_006bed60(void) {
  FUN_004ab7c0();
}

// 0x006bef00
void FUN_006bef00(void) {
  FUN_0045a050();
}

// 0x006bef10
void FUN_006bef10(void) {
  FUN_0045a050();
}

// 0x006bef80
void FUN_006bef80(void) {
  FUN_004c2600();
}

// 0x006bf3c0
void FUN_006bf3c0(void) {
  FUN_004d4be0();
}
