// Reconstruction batch mass_0021 — Sid Meier's Pirates! (2004), PE32 i386.
// Each definition corresponds to one Ghidra 12.2 pseudocode listing.

#include <cstdint>
#include <windows.h>

// ---------------------------------------------------------------------------
// Extern globals used by the listings (addresses from the corpus).
// ---------------------------------------------------------------------------
extern int32_t DAT_00862110[];
extern int32_t DAT_00862114[];
extern void* DAT_008e66f0;
extern uint8_t DAT_008e67b0[];
extern uint8_t DAT_008e8eff;
extern uint32_t DAT_008cacf0;
extern uint32_t DAT_008cace8;
extern uint32_t DAT_008cacec;
extern uint32_t DAT_008ecd78;

// ---------------------------------------------------------------------------
// Extern helpers referenced by the listings.
// ---------------------------------------------------------------------------
extern uint32_t FUN_004985e0();
extern uint32_t FUN_0049b080(void*, uint32_t, uint32_t, uint32_t, int32_t);
extern uint32_t FUN_0049f930(void*, uint32_t, int32_t);
extern uint32_t FUN_0049fb80(void*, uint32_t, int32_t);
extern uint32_t FUN_004a0560(void*, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, int32_t);
extern uint32_t FUN_004a08b0(void*, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, int32_t);
extern uint32_t FUN_004a14b0();
extern uint32_t FUN_004af080(void*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint32_t, uint32_t);
extern int32_t FUN_004baaa0(void*);
extern uint32_t FUN_004cddf0(void*, int32_t, int32_t, void*, void*);
extern uint32_t FUN_004f8e40(void*);

// ---------------------------------------------------------------------------
// 0x4884a0 — observed shape: 3x3 grid of FUN_004cddf0 + FUN_004af080 blits; in_EAX is the divisor and in_EDX/in_ECX are clamped dimensions (register inputs as explicit params).
// ---------------------------------------------------------------------------
void FUN_004884a0(int32_t param_1, int32_t param_2, int32_t in_EAX, int32_t in_EDX, int32_t in_ECX) {
  int32_t iVar1;
  uint32_t uVar2;
  int32_t iVar3;
  int32_t iVar4;
  int32_t iVar5;
  uint32_t local_14;
  uint32_t local_10;
  int32_t local_c;
  int32_t local_8;
  int32_t local_4;

  local_8 = static_cast<int32_t>(0x20 / static_cast<long long>(in_EAX));
  if (in_EDX < local_8) {
    in_EDX = local_8;
  }
  if (in_ECX < local_8) {
    in_ECX = local_8;
  }
  iVar1 = static_cast<int32_t>(0x10 / static_cast<long long>(in_EAX));
  local_14 = 0x10;
  local_10 = 0x10;
  iVar5 = (iVar1 + -1 + in_EDX & ~(iVar1 - 1U)) - local_8;
  iVar3 = (iVar1 + -1 + in_ECX & ~(iVar1 - 1U)) - local_8;
  param_1 = param_1 + iVar1;
  iVar4 = param_2 + iVar1;
  param_2 = iVar4;
  uVar2 = FUN_004cddf0(DAT_008e66f0, 0, 0, &local_10, &local_14);
  iVar4 = iVar4 - iVar1;
  local_c = param_1 - iVar1;
  local_4 = iVar4;
  FUN_004af080(reinterpret_cast<void*>(uVar2), 0, 0, local_10, local_14, local_c, iVar4, iVar1, iVar1, 0xffffffff, 0);
  local_10 = 0x10;
  local_14 = 0x10;
  uVar2 = FUN_004cddf0(DAT_008e66f0, 0x10, 0, &local_14, &local_10);
  FUN_004af080(reinterpret_cast<void*>(uVar2), 0x10, 0, local_14, local_10, param_1, iVar4, iVar5, iVar1, 0xffffffff, 0);
  local_10 = 0x10;
  local_14 = 0x1f;
  uVar2 = FUN_004cddf0(DAT_008e66f0, 0x20, 0, &local_14, &local_10);
  iVar4 = local_8 + -1;
  local_8 = param_1 + iVar5;
  FUN_004af080(reinterpret_cast<void*>(uVar2), 0x20, 0, local_14, local_10, param_1 + iVar5, local_4, iVar4, iVar1, 0xffffffff, 0);
  local_10 = 0x10;
  local_14 = 0x10;
  uVar2 = FUN_004cddf0(DAT_008e66f0, 0, 0x10, &local_14, &local_10);
  FUN_004af080(reinterpret_cast<void*>(uVar2), 0, 0x10, local_14, local_10, local_c, param_2, iVar1, iVar3, 0xffffffff, 0);
  local_10 = 0x10;
  local_14 = 0x10;
  uVar2 = FUN_004cddf0(DAT_008e66f0, 0x10, 0x10, &local_14, &local_10);
  FUN_004af080(reinterpret_cast<void*>(uVar2), 0x10, 0x10, local_14, local_10, param_1, param_2, iVar5, iVar3, 0xffffffff, 0);
  local_10 = 0x10;
  local_14 = 0x1f;
  uVar2 = FUN_004cddf0(DAT_008e66f0, 0x20, 0x10, &local_14, &local_10);
  FUN_004af080(reinterpret_cast<void*>(uVar2), 0x20, 0x10, local_14, local_10, local_8, param_2, iVar4, iVar3, 0xffffffff, 0);
  local_10 = 0x1f;
  local_14 = 0x10;
  uVar2 = FUN_004cddf0(DAT_008e66f0, 0, 0x20, &local_14, &local_10);
  iVar3 = iVar3 + param_2;
  FUN_004af080(reinterpret_cast<void*>(uVar2), 0, 0x20, local_14, local_10, local_c, iVar3, iVar1, iVar4, 0xffffffff, 0);
  param_2 = 0x1f;
  local_c = 0x10;
  uVar2 = FUN_004cddf0(DAT_008e66f0, 0x10, 0x20, &local_c, &param_2);
  FUN_004af080(reinterpret_cast<void*>(uVar2), 0x10, 0x20, local_c, param_2, param_1, iVar3, iVar5, iVar4, 0xffffffff, 0);
  param_1 = 0x1f;
  param_2 = 0x1f;
  uVar2 = FUN_004cddf0(DAT_008e66f0, 0x20, 0x20, &param_2, &param_1);
  FUN_004af080(reinterpret_cast<void*>(uVar2), 0x20, 0x20, param_2, param_1, local_8, iVar3, iVar4, iVar4, 0xffffffff, 0);
  return;
}

// ---------------------------------------------------------------------------
// 0x4887d0 — observed shape: key/value table at DAT_00862110 (3-int entries at 0x862110, stride 0xc); lookup by (unaff_ESI, in_EDX), insert at the first empty slot, returns 1 on hit/insert else 0. Register inputs as explicit params.
// ---------------------------------------------------------------------------
uint32_t FUN_004887d0(int32_t unaff_ESI, int32_t in_EDX, uint32_t unaff_EDI) {
  int32_t* piVar1;
  int32_t iVar2 = 0;

  piVar1 = &DAT_00862114[0];
  while (piVar1[-1] != unaff_ESI || (*piVar1 != in_EDX)) {
    piVar1 = piVar1 + 3;
    iVar2 = iVar2 + 1;
    if (static_cast<int>(reinterpret_cast<intptr_t>(piVar1)) > 0x862d13) {
      iVar2 = 0;
      piVar1 = &DAT_00862110[0];
      do {
        if (*piVar1 == -1) {
          DAT_00862110[iVar2 * 3] = unaff_ESI;
          DAT_00862114[iVar2 * 3] = in_EDX;
          *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(iVar2) * 0xc + 0x862118) = unaff_EDI;
          return 1;
        }
        piVar1 = piVar1 + 3;
        iVar2 = iVar2 + 1;
      } while (static_cast<int>(reinterpret_cast<intptr_t>(piVar1)) < 0x862d10);
      return 0;
    }
  }
  *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(iVar2) * 0xc + 0x862118) = unaff_EDI;
  return 1;
}

// ---------------------------------------------------------------------------
// 0x488840 — observed shape: audio/log gate; returns 0 when DAT_008cacf0 is clear or in_EAX-gated input is suppressed, else forwards &param_2 to FUN_004f8e40. Called with formatted/varargs-style arguments at the sites below.
// ---------------------------------------------------------------------------
uint32_t FUN_00488840(const char* param_1 = nullptr, uint32_t param_2 = 0, int32_t in_EAX = 0, ...) {
  if ((DAT_008cacf0 == 0) || ((in_EAX != 0 && (DAT_008cace8 == 0 && DAT_008cacec == 0)))) {
    return 0;
  }
  uint32_t uVar1 = FUN_004f8e40(&param_2);
  return uVar1;
}

// ---------------------------------------------------------------------------
// 0x488880 — observed shape: audio-manager gate; on failure reports via FUN_00488840, else forwards the 3 dwords at param_1+0x90/+0x94/+0x98 to FUN_0049b080 with flag 1.
// ---------------------------------------------------------------------------
void FUN_00488880(uint32_t param_1) {
  char cVar1 = (*reinterpret_cast<char (**)(void)>(DAT_008ecd78 + 0x18))();
  if (cVar1 == '\0') {
    FUN_00488840("The audio manager has not been properly initialized yet", 0);
    return;
  }
  FUN_0049b080(&DAT_008e67b0, *reinterpret_cast<uint32_t*>(param_1 + 0x90), *reinterpret_cast<uint32_t*>(param_1 + 0x94), *reinterpret_cast<uint32_t*>(param_1 + 0x98), 1);
  return;
}

// ---------------------------------------------------------------------------
// 0x4888e0 — observed shape: audio-manager gate; on failure reports via FUN_00488840, else logs the three params and runs the FUN_004985e0/FUN_004a14b0 pair when DAT_008e8eff is clear.
// ---------------------------------------------------------------------------
void FUN_004888e0(uint32_t param_1, uint32_t param_2, uint32_t param_3) {
  char cVar1 = (*reinterpret_cast<char (**)(void)>(DAT_008ecd78 + 0x18))();
  if (cVar1 == '\0') {
    FUN_00488840();
    return;
  }
  FUN_00488840("%d, %d, %d, %d, %p, %f, %d", param_1, param_2, param_3);
  if (DAT_008e8eff == '\0') {
    FUN_004985e0();
    FUN_004a14b0();
  }
  return;
}

// ---------------------------------------------------------------------------
// 0x4889c0 — observed shape: audio-manager gate; on failure reports via FUN_00488840, else runs the FUN_004985e0/FUN_004a14b0 pair when DAT_008e8eff is clear.
// ---------------------------------------------------------------------------
void FUN_004889c0() {
  char cVar1 = (*reinterpret_cast<char (**)(void)>(DAT_008ecd78 + 0x18))();
  if (cVar1 == '\0') {
    FUN_00488840("The audio manager has not been properly initialized yet", 0);
    return;
  }
  if (DAT_008e8eff == '\0') {
    FUN_004985e0();
    FUN_004a14b0();
  }
  return;
}

// ---------------------------------------------------------------------------
// 0x488a80 — observed shape: audio-manager gate; on failure reports via FUN_00488840, else forwards param_1 to FUN_0049f930 with a null handle.
// ---------------------------------------------------------------------------
void FUN_00488a80(uint32_t param_1) {
  char cVar1 = (*reinterpret_cast<char (**)(void)>(DAT_008ecd78 + 0x18))();
  if (cVar1 == '\0') {
    FUN_00488840();
    return;
  }
  FUN_0049f930(&DAT_008e67b0, param_1, 0);
  return;
}

// ---------------------------------------------------------------------------
// 0x488b00 — observed shape: audio-manager gate; on failure reports via FUN_00488840, else forwards param_2 to FUN_0049fb80 with a null handle (param_1 unused, as in the listing).
// ---------------------------------------------------------------------------
void FUN_00488b00(uint32_t param_1, uint32_t param_2) {
  (void)param_1;
  char cVar1 = (*reinterpret_cast<char (**)(void)>(DAT_008ecd78 + 0x18))();
  if (cVar1 == '\0') {
    FUN_00488840();
    return;
  }
  FUN_0049fb80(&DAT_008e67b0, param_2, 0);
  return;
}

// ---------------------------------------------------------------------------
// 0x488b80 — observed shape: audio-manager gate; otherwise builds a 10-dword frame block ([0..7]=uStack_38..uStack_1c, [8]=pcStack_18, [9]=uStack_14) with a 0xbf800000 triplet, refcounts the block returned by FUN_004baaa0, and forwards to FUN_0049f930. unaff_EDI (register) gates the tail.
// ---------------------------------------------------------------------------
void FUN_00488b80(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7, uint32_t param_8, int32_t unaff_EDI) {
  (void)param_3;
  uint32_t frame[10];
  frame[9] = 0x488b91;
  char cVar1 = (*reinterpret_cast<char (**)(void)>(DAT_008ecd78 + 0x18))();
  if (cVar1 == '\0') {
    frame[9] = 0;
    frame[8] = reinterpret_cast<uint32_t>("The audio manager has not been properly initialized yet");
    frame[7] = 0x488ba6;
    FUN_00488840();
    return;
  }
  if (unaff_EDI != 0) {
    frame[9] = 1;
    frame[8] = param_8;
    frame[7] = param_7;
    frame[6] = param_6;
    frame[5] = param_5;
    frame[4] = param_4;
    frame[3] = param_2;
    frame[0] = 0xbf800000;
    frame[1] = 0xbf800000;
    frame[2] = 0xbf800000;
    int32_t iVar2 = FUN_004baaa0(static_cast<void*>(frame));
    if (iVar2 != 0) {
      *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(iVar2) + 4) += 1;
    }
    FUN_0049f930(&DAT_008e67b0, param_1, iVar2);
  }
  return;
}

// ---------------------------------------------------------------------------
// 0x488c30 — observed shape: same frame-block build as 0x488b80 (param_3 in slot [3]); forwards the FUN_004baaa0 block to FUN_0049fb80. unaff_EDI (register) gates the tail.
// ---------------------------------------------------------------------------
void FUN_00488c30(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7, uint32_t param_8, int32_t unaff_EDI) {
  (void)param_1;
  uint32_t frame[10];
  frame[9] = 0x488c41;
  char cVar1 = (*reinterpret_cast<char (**)(void)>(DAT_008ecd78 + 0x18))();
  if (cVar1 == '\0') {
    frame[9] = 0;
    frame[8] = reinterpret_cast<uint32_t>("The audio manager has not been properly initialized yet");
    frame[7] = 0x488c56;
    FUN_00488840();
    return;
  }
  if (unaff_EDI != 0) {
    frame[9] = 1;
    frame[8] = param_8;
    frame[7] = param_7;
    frame[6] = param_6;
    frame[5] = param_5;
    frame[4] = param_4;
    frame[3] = param_3;
    frame[0] = 0xbf800000;
    frame[1] = 0xbf800000;
    frame[2] = 0xbf800000;
    int32_t iVar2 = FUN_004baaa0(static_cast<void*>(frame));
    if (iVar2 != 0) {
      *reinterpret_cast<int32_t*>(static_cast<uintptr_t>(iVar2) + 4) += 1;
    }
    FUN_0049fb80(&DAT_008e67b0, param_2, iVar2);
  }
  return;
}

// ---------------------------------------------------------------------------
// 0x488ce0 — observed shape: audio-manager gate; otherwise bumps the refcount dword at self+4 (register receiver via unaff_ESI, explicit void* self) and forwards to FUN_0049f930.
// ---------------------------------------------------------------------------
void FUN_00488ce0(uint32_t param_1, void* self) {
  char cVar1 = (*reinterpret_cast<char (**)(void)>(DAT_008ecd78 + 0x18))();
  if (cVar1 == '\0') {
    FUN_00488840();
    return;
  }
  if (self != nullptr) {
    *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(self) + 4) += 1;
    FUN_0049f930(&DAT_008e67b0, param_1, reinterpret_cast<int32_t>(self));
  }
  return;
}

// ---------------------------------------------------------------------------
// 0x488d90 — observed shape: audio-manager gate; on failure reports via FUN_00488840, else forwards (param_1, param_3..param_7, 1) to FUN_004a0560 — param_2 is skipped exactly as listed.
// ---------------------------------------------------------------------------
void FUN_00488d90(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7) {
  (void)param_2;
  char cVar1 = (*reinterpret_cast<char (**)(void)>(DAT_008ecd78 + 0x18))();
  if (cVar1 == '\0') {
    FUN_00488840("The audio manager has not been properly initialized yet", 0);
    return;
  }
  FUN_004a0560(&DAT_008e67b0, param_1, param_3, param_4, param_5, param_6, param_7, 1);
  return;
}

// ---------------------------------------------------------------------------
// 0x488df0 — observed shape: audio-manager gate; on failure reports via FUN_00488840, else forwards (param_1, param_3..param_7, 1) to FUN_004a08b0 — param_2 is skipped exactly as listed.
// ---------------------------------------------------------------------------
void FUN_00488df0(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5, uint32_t param_6, uint32_t param_7) {
  (void)param_2;
  char cVar1 = (*reinterpret_cast<char (**)(void)>(DAT_008ecd78 + 0x18))();
  if (cVar1 == '\0') {
    FUN_00488840("The audio manager has not been properly initialized yet", 0);
    return;
  }
  FUN_004a08b0(&DAT_008e67b0, param_1, param_3, param_4, param_5, param_6, param_7, 1);
  return;
}

// ---------------------------------------------------------------------------
// 0x488e50 — observed shape: audio-manager gate; on failure reports via FUN_00488840, else runs the FUN_004985e0/FUN_004a14b0 pair unconditionally.
// ---------------------------------------------------------------------------
void FUN_00488e50() {
  char cVar1 = (*reinterpret_cast<char (**)(void)>(DAT_008ecd78 + 0x18))();
  if (cVar1 == '\0') {
    FUN_00488840("The audio manager has not been properly initialized yet", 0);
    return;
  }
  FUN_004985e0();
  FUN_004a14b0();
  return;
}

// ---------------------------------------------------------------------------
// 0x488ed0 — observed shape: audio-manager gate; on failure reports via FUN_00488840, else runs the FUN_004985e0/FUN_004a14b0 pair unconditionally.
// ---------------------------------------------------------------------------
void FUN_00488ed0() {
  char cVar1 = (*reinterpret_cast<char (**)(void)>(DAT_008ecd78 + 0x18))();
  if (cVar1 == '\0') {
    FUN_00488840("The audio manager has not been properly initialized yet", 0);
    return;
  }
  FUN_004985e0();
  FUN_004a14b0();
  return;
}

// ---------------------------------------------------------------------------
// 0x488f40 — observed shape: audio-manager gate; on failure reports via FUN_00488840, else runs the FUN_004985e0/FUN_004a14b0 pair unconditionally.
// ---------------------------------------------------------------------------
void FUN_00488f40() {
  char cVar1 = (*reinterpret_cast<char (**)(void)>(DAT_008ecd78 + 0x18))();
  if (cVar1 == '\0') {
    FUN_00488840("The audio manager has not been properly initialized yet", 0);
    return;
  }
  FUN_004985e0();
  FUN_004a14b0();
  return;
}

// ---------------------------------------------------------------------------
// 0x488fc0 — observed shape: audio-manager gate; on failure reports via FUN_00488840, else runs the FUN_004985e0/FUN_004a14b0 pair unconditionally.
// ---------------------------------------------------------------------------
void FUN_00488fc0() {
  char cVar1 = (*reinterpret_cast<char (**)(void)>(DAT_008ecd78 + 0x18))();
  if (cVar1 == '\0') {
    FUN_00488840("The audio manager has not been properly initialized yet", 0);
    return;
  }
  FUN_004985e0();
  FUN_004a14b0();
  return;
}

// ---------------------------------------------------------------------------
// 0x489040 — observed shape: audio-manager gate; on failure reports via FUN_00488840, else runs the FUN_004985e0/FUN_004a14b0 pair unconditionally.
// ---------------------------------------------------------------------------
void FUN_00489040() {
  char cVar1 = (*reinterpret_cast<char (**)(void)>(DAT_008ecd78 + 0x18))();
  if (cVar1 == '\0') {
    FUN_00488840("The audio manager has not been properly initialized yet", 0);
    return;
  }
  FUN_004985e0();
  FUN_004a14b0();
  return;
}

// ---------------------------------------------------------------------------
// 0x4890c0 — observed shape: audio-manager gate; on failure reports via FUN_00488840, else runs the FUN_004985e0/FUN_004a14b0 pair unconditionally.
// ---------------------------------------------------------------------------
void FUN_004890c0() {
  char cVar1 = (*reinterpret_cast<char (**)(void)>(DAT_008ecd78 + 0x18))();
  if (cVar1 == '\0') {
    FUN_00488840("The audio manager has not been properly initialized yet", 0);
    return;
  }
  FUN_004985e0();
  FUN_004a14b0();
  return;
}

// ---------------------------------------------------------------------------
// 0x489130 — observed shape: audio-manager gate; on failure reports via FUN_00488840, else runs the FUN_004985e0/FUN_004a14b0 pair unconditionally.
// ---------------------------------------------------------------------------
void FUN_00489130() {
  char cVar1 = (*reinterpret_cast<char (**)(void)>(DAT_008ecd78 + 0x18))();
  if (cVar1 == '\0') {
    FUN_00488840("The audio manager has not been properly initialized yet", 0);
    return;
  }
  FUN_004985e0();
  FUN_004a14b0();
  return;
}
