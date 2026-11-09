// UNVERIFIED: no cl 13.10.3077. No PASS claim. Clean-room from shipped bytes + REA pseudocode.
// Band 8 wave4 terminal-call thunks (JUMP to FUN_004xxxxx transitively; triage marks thunk=false).
// Evidence: analysis/pseudocode/functions/0x6bed50.c, 0x6befd0.c, 0x6bf060.c; 13-byte bodies, span 16.
extern void FUN_00497f10(void);
extern void FUN_004c3410(void);
extern void FUN_004ce670(void);

// 0x006bed50 — observed purpose: single terminal call to FUN_00497f10
void FUN_006bed50(void) {
  FUN_00497f10();
}

// 0x006befd0 — observed purpose: single terminal call to FUN_004c3410
void FUN_006befd0(void) {
  FUN_004c3410();
}

// 0x006bf060 — observed purpose: single terminal call to FUN_004ce670
void FUN_006bf060(void) {
  FUN_004ce670();
}
