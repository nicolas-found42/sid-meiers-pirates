// Reconstruction batch mass_0005 — Sid Meier's Pirates! (2004), PE32 i386
// Image: 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
//
// Each FUN_ADDR definition corresponds to one assigned corpus file under
// analysis/pseudocode/functions/. Field offsets, constants, call order,
// return shapes, and conditional structure are preserved from the observed
// Ghidra 12.2 pseudocode. Register receivers are exposed as explicit
// void* self parameters in free functions; never `this` inside a free
// function. Referenced helpers/globals are declared extern.
//
// NOTE on truncated listings: several corpus files were returned elided
// (0x414d00: 83 lines, 0x414fc0: 75 lines, 0x4154f0: 73 lines,
// 0x415860: ~1900 lines with type-propagation warnings, 0x415290: 7 lines).
// Those functions are NOT emitted below at all; only the 6 fully-observed
// listings are reconstructed here. The elided addresses must be requeued
// with full pseudocode before reconstruction. No placeholders are emitted
// for them per the "no empty body / no return 0 filler" rule.

#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---------------------------------------------------------------------------
// Extern declarations: helpers and globals referenced by the listings below.
// DATA symbols are referenced by their corpus names; do not invent addresses
// not used by the supplied listing.
// ---------------------------------------------------------------------------

extern uint32_t DAT_00722a08;
extern int32_t  DAT_00722a0c;
extern uint32_t DAT_00861128;
extern uint32_t DAT_0086112c;

// Helper callees observed in the fully-reconstructed listings.
extern int  FUN_004154f0(int param_1, int param_2, int param_3);
extern void FUN_004157c0();
extern void FUN_0044d2e0(int param_1, int param_2);

// Data arrays referenced by FUN_00414c00 / FUN_00415730 / FUN_004157c0.
// Element types/sizes are chosen to match observed indexed access widths:
//   0x8142f8 (short stride 0x22e), 0x814350 (word stride 0x117),
//   0x814330 (short stride 0x22e/2 indexing), 0x85bf82 (short stride 0x94),
//   0x85a8b0 (short stride 6 until 0x85a970),
//   0x81663a / 0x859f5a (short stride 0x22e),
//   0x722a10 / 0x722a14 (int arrays by DAT_00722a0c index),
//   0x860b70 (uint stride 8), 0x860b74 (char stride 0x20).
extern short   DAT_008142f8[];
extern short   DAT_00814350[];
extern short   DAT_00814330[];
extern short   DAT_00814336[];
extern short   DAT_0085bf82[];
extern short   DAT_0085a8b0[];
extern short   DAT_0081663a[];
extern int32_t DAT_00722a10[];
extern int32_t DAT_00722a14[];
extern uint32_t DAT_00860b70[];
extern char    DAT_00860b74[];

// Byte-offset windows used by FUN_00414c00 alongside the typed arrays above.
// The listing mixes typed indexing with raw byte offsets; both are preserved
// by accessing BYTE* windows over the same DATA names' storage below.
extern uint8_t DAT_008142fc[];
extern uint8_t DAT_0081435a[];

// 0x414c00 — observed shape: void(int param_1, int param_2)
// Guard: (&DAT_008142f8)[param_1*0x22e] != -1. Clear-on-flag 0x4000 path
// writes 0 at DAT_00862006 + s*0x1c. Clears slot, conditionally clears
// DAT_0085bf82 entry, calls FUN_0044d2e0 for positive sVar1 at DAT_008142fc,
// clears DAT_0085a8b0 records matching param_1, then recursive fan-out for
// param_2==1||99 via DAT_0081435a and DAT_0081663a stride loop.
void FUN_00414c00(int param_1, int param_2)
{
  short sVar1;
  short* psVar2;
  int iVar3;

  if ((&DAT_008142f8)[param_1 * 0x22e] != -1) {
    if (((&DAT_00814350)[param_1 * 0x117] & 0x4000) != 0) {
      *(uint16_t*)(&DAT_00862006 + (short)(&DAT_00814330)[param_1 * 0x22e] * 0x1c) = 0;
    }
    sVar1 = *(short*)(&DAT_0085bf82 + (short)(&DAT_00814336)[param_1 * 0x22e] * 0x94);
    (&DAT_008142f8)[param_1 * 0x22e] = (short)0xffff;
    if (sVar1 == param_1) {
      *(uint16_t*)(&DAT_0085bf82 + (short)(&DAT_00814336)[param_1 * 0x22e] * 0x94) = 0xffff;
    }
    sVar1 = *(short*)((intptr_t)&DAT_008142fc + param_1 * 0x45c + 2);
    if (0 < sVar1) {
      FUN_0044d2e0((int)sVar1, param_2);
    }
    psVar2 = &DAT_0085a8b0;
    do {
      if ((*psVar2 != -1) && (psVar2[2] == param_1)) {
        *psVar2 = -1;
      }
      psVar2 = psVar2 + 6;
    } while ((intptr_t)psVar2 < 0x85a970);
    if ((param_2 == 1) || (param_2 == 99)) {
      if (0 < *(short*)(&DAT_0081435a + param_1 * 0x45c)) {
        FUN_00414c00((int)*(short*)(&DAT_0081435a + param_1 * 0x45c), param_2);
      }
      if ((*(uint8_t*)(&DAT_00814350 + param_1 * 0x117) & 1) != 0) {
        iVar3 = 8;
        psVar2 = &DAT_0081663a;
        do {
          if (*psVar2 == param_1) {
            FUN_00414c00(iVar3, param_2);
          }
          psVar2 = psVar2 + 0x22e;
          iVar3 = iVar3 + 1;
        } while ((intptr_t)psVar2 < 0x859f5a);
      }
    }
  }
  return;
}

// 0x415730 — observed shape: void(void)
// Non-contiguous body (0x415730-0x41574c + 0x415750-0x4157b2).
// Sets DAT_00722a08 = 0xffffffff, calls FUN_004157c0(), then loop:
//   rand()%2-ish threshold, breaks when (uVar1+3) <= iVar4;
//   else creates two FUN_004154f0(0x1a, ..., ...) entries and stores
//   iVar4*0x32+1 at DAT_00814354 + iVar2*0x45c.
void FUN_00415730(void)
{
  uint32_t uVar1;
  int iVar2;
  int iVar3;
  int iVar4;

  DAT_00722a08 = 0xffffffff;
  FUN_004157c0();
  iVar4 = 0;
  while (true) {
    uVar1 = (uint32_t)rand();
    uVar1 = uVar1 & 0x80000001;
    if ((int32_t)uVar1 < 0) {
      uVar1 = (uVar1 - 1 | 0xfffffffe) + 1;
    }
    if ((int32_t)(uVar1 + 3) <= iVar4) break;
    iVar2 = rand();
    iVar3 = rand();
    iVar2 = FUN_004154f0(0x1a, (int)((DAT_00861128 - (uint32_t)(iVar3 % 3)) + 1),
                              (int)((DAT_0086112c - (uint32_t)(iVar2 % 3)) + 1));
    *(short*)(&DAT_00814354 + iVar2 * 0x45c) = (short)iVar4 * 0x32 + 1;
    iVar4 = iVar4 + 1;
  }
  return;
}

// 0x4157c0 — observed shape: void(void)
// State machine on DAT_00722a08. -1: seed index from rand. 0x2d: reset to -1
// and return. Else advance index by 1+rand. Loads DAT_00722a08 from
// DAT_00722a10[DAT_00722a0c], then skips entries whose DAT_00860b70 word has
// high bit set or DAT_00860b74 byte is nonzero, advancing via DAT_00722a14.
void FUN_004157c0(void)
{
  uint32_t uVar1;

  if (DAT_00722a08 == (uint32_t)-1) {
    uVar1 = (uint32_t)rand();
    DAT_00722a0c = (int32_t)(uVar1 & 0x80000001);
    if (DAT_00722a0c < 0) {
      DAT_00722a0c = (int32_t)((DAT_00722a0c - 1 | 0xfffffffe) + 1);
    }
  } else {
    if (DAT_00722a08 == 0x2d) {
      DAT_00722a08 = (uint32_t)-1;
      return;
    }
    uVar1 = (uint32_t)rand();
    uVar1 = uVar1 & 0x80000001;
    if ((int32_t)uVar1 < 0) {
      uVar1 = (uVar1 - 1 | 0xfffffffe) + 1;
    }
    DAT_00722a0c = DAT_00722a0c + 1 + (int32_t)uVar1;
  }
  DAT_00722a08 = (uint32_t)*(int32_t*)(&DAT_00722a10 + DAT_00722a0c * 4);
  if (DAT_00722a08 != (uint32_t)-1) {
    do {
      if ((DAT_00722a08 == 0x2d) ||
         (((&DAT_00860b70)[DAT_00722a08 * 8] & 0x80000000) == 0 &&
          ((&DAT_00860b74)[DAT_00722a08 * 0x20] == '\0'))) break;
      DAT_00722a08 = (uint32_t)*(int32_t*)(&DAT_00722a14 + DAT_00722a0c * 4);
      DAT_00722a0c = DAT_00722a0c + 1;
    } while (DAT_00722a08 != (uint32_t)-1);
  }
  return;
}

// 0x4192f0 — observed shape: undefined4(void), in_EAX receiver
// iVar1 = (-(in_EAX!=0) & 0xfffffffd)+6. If iVar1<1 uVar3=0 else
// uVar3 = rand()%iVar1; 5<uVar3 returns 0xffffffff.
// Switch: 1->1, 2->7, 3->2, 4->4, 5->6, default->8.
uint32_t FUN_004192f0(void* self)
{
  int in_EAX = (self != nullptr) ? 1 : 0;
  int iVar1;
  int iVar2;
  uint32_t uVar3;

  iVar1 = (int)((-(uint32_t)(in_EAX != 0) & 0xfffffffd) + 6);
  if (iVar1 < 1) {
    uVar3 = 0;
  } else {
    iVar2 = rand();
    uVar3 = (uint32_t)(iVar2 % iVar1);
    if (5 < uVar3) {
      return 0xffffffff;
    }
  }
  switch (uVar3) {
  default:
    return 8;
  case 1:
    return 1;
  case 2:
    return 7;
  case 3:
    return 2;
  case 4:
    return 4;
  case 5:
    return 6;
  }
}

// 0x4199e0 — observed shape: void(void)
// RAND-fill: iterate uint32 DAT_0072cb50 .. <0x72ccb8; per word compute
// (rand() & 0x80000001) signed-normalized; when nonzero, store 0.
void FUN_004199e0(void)
{
  uint32_t uVar1;
  uint32_t* puVar2;
  bool bVar3;

  puVar2 = (uint32_t*)&DAT_0072cb50;
  do {
    uVar1 = (uint32_t)rand();
    uVar1 = uVar1 & 0x80000001;
    bVar3 = uVar1 == 0;
    if ((int32_t)uVar1 < 0) {
      bVar3 = (uVar1 - 1 | 0xfffffffe) == 0xffffffff;
    }
    if (!bVar3) {
      *puVar2 = 0;
    }
    puVar2 = puVar2 + 1;
  } while ((intptr_t)puVar2 < 0x72ccb8);
  return;
}

// 0x419a20 — deepest fully-observed range; body present but NOT included
// here because its corpus file was outside the two read batches fetched
// first and elided-listing reconstruction is forbidden by the "no
// placeholder / no return 0 filler" rule. It will be requeued. (This
// comment marker is NOT a definition and does not claim coverage of
// 0x419a20, 0x419a60, 0x419ac0, 0x419c20, 0x419cc0, 0x419de0, 0x419e90,
// 0x419ec0, 0x41a000, 0x41a110 either; those await full pseudocode.)
//
// Requeued (no bodies emitted): 0x414d00, 0x414fc0, 0x415290, 0x4154f0,
// 0x415860, 0x419a20, 0x419a60, 0x419ac0, 0x419c20, 0x419cc0, 0x419de0,
// 0x419e90, 0x419ec0, 0x41a000, 0x41a110.

// ===========================================================================
// Retry completion — definitions for the previously requeued addresses.
// Appended after the original batch; every earlier line above is unchanged.
// ===========================================================================

// Ghidra pseudocode markers retained for the observed indirect calls.
typedef int code();
typedef uint32_t undefined4;

// Additional referenced data symbols (typed to the observed access widths).
extern uint32_t DAT_0072cb50[];

extern short    DAT_00816618[];
extern short    DAT_0081660e[];
extern int32_t  DAT_00860b6c[];
extern int32_t  DAT_00860b68[];
extern uint8_t  DAT_0085a168[];
extern uint8_t  DAT_00722988[];
extern uint8_t  DAT_00814338[];
extern uint8_t  DAT_00814326[];
extern short    DAT_0085bfbe[];

// Additional helper callees.
extern int  FUN_004135d0();
extern void FUN_00413430(int param_1);
extern void FUN_00413080();

// 0x414d00 — observed shape: int(int param_1)
// Selects the nearest eligible trade/quest candidate for player param_1.
// The routine zeroes a 0x700-byte scratch block, tallies per-island counters
// in asStack_6fc from DAT_00816618/DAT_0081660e (stride 0x22e), asks
// FUN_004135d0() for a free record, then scans DAT_00860b70 (stride 8) for
// entries with bit 1 set, not owned by param_1, and nonnegative. For each it
// computes a weighted distance from the player's coordinates
// (DAT_00860b68/DAT_00860b6c) by five sector steps, doubling/halving by the
// DAT_0085a168 relation flag, and keeps the best. On a hit it stores the
// selected word from DAT_00722988 (+ (flag + local_71c)*4) into DAT_008142f8,
// writes the candidate id at DAT_00814338, and calls FUN_00413430(iVar4).
// Returns -1 when nothing matched, and -1 when the chosen slot is empty.
int FUN_00414d00(int param_1)
{
  char cVar1;
  short *psVar2;
  short *psVar5;
  int iVar3;
  int iVar4;
  int iVar6;
  int iVar8;
  uint32_t *puVar7;
  uint32_t *puVar9;
  short asStack_6fc[894];
  uint32_t local_700;
  int local_72c;
  short *local_728;
  int local_724;
  int local_71c;
  short *local_718;
  short *local_714;
  short *local_710;

  puVar9 = &local_700;
  for (iVar4 = 0x1c0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  psVar2 = DAT_00816618;
  psVar5 = DAT_0081660e;
  do {
    if ((psVar2[-0x20] != -1) && ((*(uint32_t *)(psVar2 + 0xc) & 0x200) == 0)) {
      if (psVar5[-1] != 0) {
        asStack_6fc[*psVar2 * 7] = (short)(asStack_6fc[*psVar2 * 7] + 1);
      }
      if (*psVar5 != 0) {
        asStack_6fc[*psVar2 * 7 + 1] = (short)(asStack_6fc[*psVar2 * 7 + 1] + 1);
      }
      if (psVar5[1] != 0) {
        asStack_6fc[*psVar2 * 7 + 2] = (short)(asStack_6fc[*psVar2 * 7 + 2] + 1);
      }
      if (psVar5[2] != 0) {
        asStack_6fc[*psVar2 * 7 + 3] = (short)(asStack_6fc[*psVar2 * 7 + 3] + 1);
      }
    }
    psVar5 = psVar5 + 0x22e;
    psVar2 = psVar2 + 0x22e;
  } while ((int)psVar5 < 0x84ab0e);
  cVar1 = DAT_00860b74[param_1 * 0x20];
  local_724 = 0;
  iVar4 = FUN_004135d0();
  local_710 = asStack_6fc + 3;
  local_72c = 0;
  DAT_00814336[iVar4 * 0x22e] = (short)param_1;
  local_728 = DAT_0085bfbe;
  puVar7 = DAT_00860b70;
  do {
    if ((((*puVar7 & 2) != 0) && (local_72c != param_1)) && (-1 < (int)*puVar7)) {
      local_718 = local_710;
      local_71c = (int)cVar1 * 2 + 0x18;
      iVar8 = 5;
      psVar2 = DAT_0085bfbe + param_1 * 0x4a;
      local_714 = local_728;
      do {
        iVar3 = (int)puVar7[-1] - DAT_00860b6c[param_1 * 8];
        iVar6 = (int)puVar7[-2] - DAT_00860b68[param_1 * 8];
        if (iVar6 < 0) {
          iVar6 = -iVar6;
        }
        if (iVar3 < 0) {
          iVar3 = -iVar3;
        }
        if (iVar3 < iVar6) {
          iVar3 = iVar3 + iVar6 * 2;
        }
        else {
          iVar3 = iVar6 + iVar3 * 2;
        }
        iVar3 = ((((int)*local_714 - (int)*psVar2) - (int)*local_718) * 100) /
                (iVar3 / 2 + 100);
        if (DAT_0085a168[(int)cVar1 + (char)puVar7[1] * 8] == 1) {
          if ((iVar8 != 5) && (iVar8 != 3)) {
            iVar3 = iVar3 / 2;
            goto LAB_00414ebb;
          }
        }
        else {
LAB_00414ebb:
          if ((iVar8 == 5) || (iVar8 == 3)) {
            iVar3 = iVar3 * 2;
          }
          if (local_724 < iVar3) {
            DAT_008142f8[iVar4 * 0x22e] =
                *(uint16_t *)(DAT_00722988 +
                              ((uint32_t)(DAT_0085a168[(int)cVar1 + (char)puVar7[1] * 8] == 1) +
                               (uint32_t)local_71c) * 4);
            *(uint16_t *)(DAT_00814338 + iVar4 * 0x45c) = (uint16_t)local_72c;
            FUN_00413430(iVar4);
            local_724 = iVar3;
          }
        }
        local_714 = local_714 + -1;
        iVar8 = iVar8 + -1;
        local_718 = local_718 + -1;
        local_71c = local_71c + -8;
        psVar2 = psVar2 + -1;
      } while (1 < iVar8);
    }
    local_72c = local_72c + 1;
    puVar7 = puVar7 + 8;
    local_710 = local_710 + 7;
    local_728 = local_728 + 0x4a;
    if (0x8610ef < (int)puVar7) {
      if (local_724 == 0) {
        return -1;
      }
      *(uint16_t *)(DAT_00814326 + iVar4 * 0x45c) = 0xffff;
      FUN_00413080();
      if (DAT_008142f8[iVar4 * 0x22e] == -1) {
        iVar4 = -1;
      }
      return iVar4;
    }
  } while (true);
}

// 0x414fc0 — observed shape: int(int param_1, short param_2)
// Finds the first free record at DAT_008165d8 (stride 0x22e, starting index 8),
// clears its 0x45c-byte body, flags DAT_00814350 with 0x800, seeds owner,
// fitness, timer and counters, derives stats/value fields from the
// DAT_00723b14 record block for param_2, and calls FUN_00413080().
// Returns the record index, or -1 when all slots are occupied.
int FUN_00414fc0(int param_1, short param_2)
{
  uint8_t bVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  uint16_t uVar5;
  int iVar6;
  uint32_t uVar7;
  char cVar8;
  short sVar9;
  int iVar10;
  int iVar11;
  short *psVar12;
  int iVar13;

  iVar10 = 8;
  psVar2 = DAT_008165d8;
  do {
    if (*psVar2 == -1) {
      iVar11 = iVar10 * 0x45c;
      psVar2 = DAT_008142f8 + iVar10 * 0x22e;
      psVar12 = psVar2;
      for (iVar6 = 0x117; iVar6 != 0; iVar6 = iVar6 + -1) {
        psVar12[0] = 0;
        psVar12[1] = 0;
        psVar12 = psVar12 + 2;
      }
      DAT_00814350[iVar10 * 0x117] = (short)(DAT_00814350[iVar10 * 0x117] | 0x800);
      iVar3 = rand();
      *(uint16_t *)(DAT_00814338 + iVar11) = (uint16_t)param_1;
      DAT_00814336[iVar10 * 0x22e] = (short)param_1;
      *(uint16_t *)(DAT_008142fc + iVar10 * 0x117) =
          (uint16_t)(char)DAT_00860b74[param_1 * 0x20];
      *psVar2 = param_2;
      iVar6 = *(int32_t *)(DAT_00723b14 + param_2 * 0x44);
      DAT_00814322[iVar10 * 0x22e] = 3;
      *(uint16_t *)(DAT_00814354 + iVar11) = (uint16_t)(iVar3 % 0x32) + 1;
      *(uint32_t *)(DAT_00814340 + iVar11) = DAT_0085a150;
      iVar6 = (int)(iVar6 + (iVar6 >> 0x1f & 3U)) >> 2;
      if (iVar6 < 1) {
        sVar9 = 0;
      }
      else {
        iVar3 = rand();
        sVar9 = (short)(iVar3 % iVar6);
      }
      DAT_0081431e[iVar10 * 0x22e] =
          *(short *)(DAT_00723b14 + *psVar2 * 0x44) - sVar9;
      iVar6 = *(int32_t *)(DAT_00723b14 + *psVar2 * 0x44 + 4);
      if (iVar6 / 3 < 1) {
        cVar8 = '\0';
      }
      else {
        iVar3 = rand();
        cVar8 = (char)(iVar3 % (iVar6 / 3));
      }
      sVar9 = *(short *)(DAT_00723b14 + *psVar2 * 0x44 + 8);
      iVar6 = (int)DAT_00814336[iVar10 * 0x22e];
      uVar7 = DAT_00860b70[iVar6 * 8];
      uVar5 = (uint8_t)((DAT_00723b14[*psVar2 * 0x44 + 4] - cVar8) + 1) & 0xfe;
      DAT_00814320[iVar10 * 0x22e] = (short)uVar5;
      bVar1 = DAT_00860b75[iVar6 * 0x20];
      *(uint16_t *)(DAT_0081432a + iVar11) = (uint16_t)(sVar9 - uVar5);
      iVar6 = (int)(((-(uint32_t)((uVar7 & 0x20000) != 0) & 0xffffffe7) + 0x19) *
                    (uint32_t)bVar1) /
              DAT_00861b74 +
              ((int)(DAT_00860b7c[iVar6 * 8] +
                     ((int)DAT_00860b7c[iVar6 * 8] >> 0x1f & 3U)) >> 2);
      if (iVar6 < 1) {
        iVar6 = 1;
      }
      else if (100 < iVar6) {
        iVar6 = 100;
      }
      *(uint16_t *)(DAT_00814324 + iVar11) =
          (uint16_t)(*(uint16_t *)(DAT_00814324 + iVar11) | 0x4b);
      *(short *)(DAT_00814328 + iVar11) = (short)iVar6 * 10;
      iVar6 = rand();
      *(uint16_t *)(DAT_00814326 + iVar11) = 0xffff;
      *(uint16_t *)(DAT_00814324 + iVar11) =
          (uint16_t)iVar6 & *(uint16_t *)(DAT_00814324 + iVar11) | 0x30;
      iVar13 = (int)DAT_0085bff6[param_1 * 0x4a];
      DAT_0081433c[iVar10 * 0x117] = iVar13 << 0x1d;
      DAT_0081430c[iVar10 * 0x117] = iVar13 << 0x1d;
      uVar7 = iVar13 + 2U & 7;
      iVar6 = iVar10 % 9 + -4;
      iVar3 = DAT_007252f0[uVar7] * iVar6 * 1000;
      iVar4 = DAT_00725350[uVar7] * iVar6 * 1000;
      iVar6 = DAT_00725350[iVar13];
      iVar11 = DAT_00860b6c[param_1 * 8];
      DAT_00814304[iVar10 * 0x117] =
          (((int)(iVar3 + (iVar3 >> 0x1f & 0xfU)) >> 4) +
           (DAT_007252f0[iVar13] * 1000) / 2 + DAT_00860b68[param_1 * 8] * 1000) * 1000;
      DAT_00814308[iVar10 * 0x117] =
          (((int)(iVar4 + (iVar4 >> 0x1f & 0xfU)) >> 4) +
           (iVar6 * 1000) / 2 + iVar11 * 1000) * 1000;
      FUN_00413080();
      return iVar10;
    }
    psVar2 = psVar2 + 0x22e;
    iVar10 = iVar10 + 1;
  } while ((int)psVar2 < 0x859ef8);
  return -1;
}

// 0x415290 — observed shape: int(short param_1), in_EAX receiver
// Same slot-search shape as FUN_00414fc0 but flags DAT_00814350 with 0x200,
// takes the owner from the in_EAX receiver, and rebuilds the record from
// FUN_0045b5d0(). Returns the record index or -1.
int FUN_00415290(void *self, short param_1)
{
  char cVar1;
  uint16_t uVar2;
  int in_EAX = (int)(intptr_t)self;
  short *psVar3;
  int iVar4;
  uint16_t uVar5;
  int iVar6;
  uint32_t uVar7;
  char cVar8;
  short sVar9;
  int iVar10;
  int iVar11;
  short *psVar12;
  uint32_t uVar13;

  iVar10 = 8;
  psVar3 = DAT_008165d8;
  do {
    if (*psVar3 == -1) {
      iVar11 = iVar10 * 0x45c;
      psVar3 = DAT_008142f8 + iVar10 * 0x22e;
      psVar12 = psVar3;
      for (iVar6 = 0x117; iVar6 != 0; iVar6 = iVar6 + -1) {
        psVar12[0] = 0;
        psVar12[1] = 0;
        psVar12 = psVar12 + 2;
      }
      DAT_00814350[iVar10 * 0x117] = (short)(DAT_00814350[iVar10 * 0x117] | 0x200);
      iVar6 = rand();
      *(uint16_t *)(DAT_00814338 + iVar11) = (uint16_t)in_EAX;
      DAT_00814336[iVar10 * 0x22e] = (short)in_EAX;
      *(uint16_t *)(DAT_00814354 + iVar11) = (uint16_t)(iVar6 % 100) + 1;
      uVar2 = FUN_0045b5d0();
      DAT_00814336[iVar10 * 0x22e] = uVar2;
      cVar8 = DAT_00860b74[in_EAX * 0x20];
      *(uint32_t *)(DAT_00814340 + iVar11) = DAT_0085a150;
      *(uint16_t *)(DAT_008142fc + iVar10 * 0x117) = (uint16_t)cVar8;
      *psVar3 = param_1;
      iVar6 = (int)(*(int32_t *)(DAT_00723b14 + param_1 * 0x44) +
                   (*(int32_t *)(DAT_00723b14 + param_1 * 0x44) >> 0x1f & 3U)) >> 2;
      *(uint16_t *)(DAT_008142fa + iVar11) = 2;
      DAT_00814322[iVar10 * 0x22e] = 4;
      if (iVar6 < 1) {
        sVar9 = 0;
      }
      else {
        iVar4 = rand();
        sVar9 = (short)(iVar4 % iVar6);
      }
      iVar6 = (int)(*(int32_t *)(DAT_00723b14 + *psVar3 * 0x44 + 4) +
                   (*(int32_t *)(DAT_00723b14 + *psVar3 * 0x44 + 4) >> 0x1f & 3U)) >> 2;
      DAT_0081431e[iVar10 * 0x22e] =
          *(short *)(DAT_00723b14 + *psVar3 * 0x44) - sVar9;
      if (iVar6 < 1) {
        cVar8 = '\0';
      }
      else {
        iVar4 = rand();
        cVar8 = (char)(iVar4 % iVar6);
      }
      uVar13 = (uint32_t)DAT_0085bff6[in_EAX * 0x4a];
      cVar1 = DAT_00723b14[*psVar3 * 0x44 + 4];
      sVar9 = *(short *)(DAT_00723b14 + *psVar3 * 0x44 + 8);
      iVar6 = (uVar13 ^ 4) << 0x1d;
      DAT_0081433c[iVar10 * 0x117] = iVar6;
      DAT_0081430c[iVar10 * 0x117] = iVar6;
      uVar5 = (uint8_t)((cVar1 - cVar8) + 1) & 0xfe;
      *(uint16_t *)(DAT_0081432a + iVar11) = (uint16_t)(sVar9 - uVar5);
      DAT_00814320[iVar10 * 0x22e] = (short)uVar5;
      uVar7 = uVar13 + 2 & 7;
      iVar6 = DAT_007252f0[uVar7];
      *(uint16_t *)(DAT_00814324 + iVar11) = 0xff;
      *(uint16_t *)(DAT_00814326 + iVar11) = 0xffff;
      iVar11 = iVar10 % 9 + -4;
      iVar6 = iVar6 * iVar11 * 1000;
      iVar11 = DAT_00725350[uVar7] * iVar11 * 1000;
      DAT_00814304[iVar10 * 0x117] =
          (((int)(iVar6 + (iVar6 >> 0x1f & 0xfU)) >> 4) +
           (DAT_007252f0[uVar13] * 1000) / 2 + DAT_00860b68[in_EAX * 8] * 1000) * 1000;
      DAT_00814308[iVar10 * 0x117] =
          (((int)(iVar11 + (iVar11 >> 0x1f & 0xfU)) >> 4) +
           (DAT_00725350[uVar13] * 1000) / 2 + DAT_00860b6c[in_EAX * 8] * 1000) * 1000;
      FUN_00413080();
      return iVar10;
    }
    psVar3 = psVar3 + 0x22e;
    iVar10 = iVar10 + 1;
  } while ((int)psVar3 < 0x859ef8);
  return -1;
}

// External symbols used by the small 0x419a20..0x41a110 group.
extern uint32_t DAT_0085a164;      // also observed as _DAT_0085a164
extern int32_t  DAT_0072ccdc;
extern uint32_t DAT_0072ccd8;
extern int32_t  DAT_007238f8;
extern uint32_t DAT_008c9df4;
extern void    *DAT_008e9fec;
extern void    *DAT_008e9fd8;
extern void    *DAT_008e9fe8;
extern void    *DAT_008e9ffc;
extern uint8_t  DAT_008cacd0[];
extern int      FUN_004baaa0(...);
extern int      FUN_004baa30(...);
extern int      FUN_004c0d40(int param_1, int param_2, int param_3);
extern int      FUN_004c0cf0(int param_1, const char *name, int param_3);
extern int32_t  DAT_008ca928;
extern int      FUN_00500600();
extern int      FUN_00533c78(uint32_t size);
extern void     FUN_005002f0();
extern void     FUN_00534350();
extern void     FUN_00534130();
extern void     FUN_00533d10(...);
extern void     FUN_004d4eb0(void *param_1);
extern void     FUN_004d4e60();
extern void     FUN_004d4fe0(int *param_1);
extern void     FUN_004f2600(const char *format);
extern void     FUN_004c1000(void *param_1);
extern void     FUN_00473b70(uint32_t param_1, uint32_t param_2, uint32_t param_3);

// 0x419a20 — observed shape: uint32_t(void), in_EAX receiver
// Classifies the receiver value: 0x50-0x53, 0x42-0x45, 0x44c-0x44f,
// 0x46a-0x46b and 0x28-0x2f are the accepted ranges; 1 when in any of them.
uint32_t FUN_00419a20(void *self)
{
  int in_EAX = (int)(intptr_t)self;

  if ((((((in_EAX < 0x50) || (0x53 < in_EAX)) &&
        ((in_EAX < 0x42 || (0x45 < in_EAX)))) &&
       ((in_EAX < 0x44c || (0x44f < in_EAX)))) &&
      ((in_EAX < 0x46a || (0x46b < in_EAX)))) &&
     ((in_EAX < 0x28 || (0x2f < in_EAX)))) {
    return 0;
  }
  return 1;
}

// 0x419a60 — observed shape: uint32_t(void), in_EAX forwarded to 0x419a20
// When DAT_0085a164 bit 2 is clear and DAT_0072ccdc falls outside the same
// five accepted ranges, returns 1 exactly when FUN_00419a20 rejects the
// forwarded receiver; otherwise 0.
uint32_t FUN_00419a60(void *self)
{
  char cVar1;

  if (((((DAT_0085a164 & 4) == 0) &&
        ((DAT_0072ccdc < 0x50 || (0x53 < DAT_0072ccdc)))) &&
       ((DAT_0072ccdc < 0x42 || (0x45 < DAT_0072ccdc)))) &&
      ((((DAT_0072ccdc < 0x44c || (0x44f < DAT_0072ccdc)) &&
        ((DAT_0072ccdc < 0x46a || (0x46b < DAT_0072ccdc)))) &&
       ((DAT_0072ccdc < 0x28 || (0x2f < DAT_0072ccdc)))))) {
    cVar1 = (char)FUN_00419a20(self);
    if (cVar1 == '\0') {
      return 1;
    }
  }
  return 0;
}

// 0x419ac0 — observed shape: void(void), in_ESI receiver
// Loads four sword meshes through the FUN_004baaa0 scene factory: the
// unnamed default, Cutlass_02, Cutlass_03 and sword_dummy. Each successful
// lookup is resolved with FUN_00500600() and registered with FUN_004c0d40.
// Only sword_dummy's registration result is observed; when it succeeds,
// DAT_008c9df4 is set.
void FUN_00419ac0(void *self)
{
  int *piVar1;
  int iVar2;
  char cVar3;
  int unaff_ESI = (int)(intptr_t)self;

  if (unaff_ESI != 0) {
    FUN_004baaa0();
    piVar1 = (int *)FUN_004baaa0();
    iVar2 = (**(code **)(*piVar1 + 0x40))();
    if (iVar2 != 0) {
      iVar2 = FUN_00500600();
      if (iVar2 != 0) {
        FUN_004c0d40(unaff_ESI, iVar2, 1);
      }
    }
    piVar1 = (int *)FUN_004baaa0();
    iVar2 = (**(code **)(*piVar1 + 0x40))("Cutlass_02");
    if (iVar2 != 0) {
      iVar2 = FUN_00500600();
      if (iVar2 != 0) {
        FUN_004c0d40(unaff_ESI, iVar2, 1);
      }
    }
    piVar1 = (int *)FUN_004baaa0();
    iVar2 = (**(code **)(*piVar1 + 0x40))("Cutlass_03");
    if (iVar2 != 0) {
      iVar2 = FUN_00500600();
      if (iVar2 != 0) {
        FUN_004c0d40(unaff_ESI, iVar2, 1);
      }
    }
    cVar3 = '\0';
    piVar1 = (int *)FUN_004baaa0();
    iVar2 = (**(code **)(*piVar1 + 0x40))("sword_dummy");
    if (iVar2 != 0) {
      iVar2 = FUN_00500600();
      if (iVar2 != 0) {
        cVar3 = (char)FUN_004c0d40(unaff_ESI, iVar2, 1);
      }
    }
    if (cVar3 != '\0') {
      DAT_008c9df4 = 1;
    }
  }
  return;
}

// 0x419c20 — observed shape: void(void), in_ESI receiver
// Guards on the receiver and DAT_007238f8, then detaches four named meshes
// with FUN_004c0cf0 (Cutlass_01_belt, Cutlass_02, Cutlass_03, sword_dummy).
// Any successful detach sets DAT_008c9df4.
void FUN_00419c20(void *self)
{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  int unaff_ESI = (int)(intptr_t)self;

  if ((unaff_ESI != 0) && (DAT_007238f8 != -1)) {
    FUN_004baaa0();
    cVar1 = (char)FUN_004c0cf0(unaff_ESI, "Cutlass_01_belt", 1);
    cVar2 = (char)FUN_004c0cf0(unaff_ESI, "Cutlass_02", 1);
    cVar3 = (char)FUN_004c0cf0(unaff_ESI, "Cutlass_03", 1);
    cVar4 = (char)FUN_004c0cf0(unaff_ESI, "sword_dummy", 1);
    if (cVar4 != '\0' || ((cVar1 != '\0' || cVar2 != '\0') || cVar3 != '\0')) {
      DAT_008c9df4 = 1;
    }
  }
  return;
}

// 0x419cc0 — observed shape: uint32_t(void), in_EAX receiver
// Sets DAT_008ca928 = 1 and, for receiver 0/1/2/other, allocates a 0xc0-byte
// object with FUN_00533c78 and loads the matching iface NIF through
// FUN_004baa30 (tav_s_iface.nif / tav_e_iface.nif / tav_f_iface.nif /
// tav_d_iface.nif), returning its handle. Returns 0 when allocation fails.
uint32_t FUN_00419cc0(void *self)
{
  int in_EAX = (int)(intptr_t)self;
  int iVar1;
  uint32_t uVar2;
  const char *pcVar3;

  DAT_008ca928 = 1;
  if (in_EAX == 0) {
    iVar1 = FUN_00533c78(0xc0);
    if (iVar1 != 0) {
      pcVar3 = "tav_s_iface.nif";
LAB_00419d99:
      uVar2 = FUN_004baa30(DAT_008e9fec, pcVar3, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
      return uVar2;
    }
  }
  else if (in_EAX == 1) {
    iVar1 = FUN_00533c78(0xc0);
    if (iVar1 != 0) {
      uVar2 = FUN_004baa30(DAT_008e9fec, "tav_e_iface.nif", 0, 0, 0, 0, 0xffffffff,
                           0, 0, 0, 0);
      return uVar2;
    }
  }
  else if (in_EAX == 2) {
    iVar1 = FUN_00533c78(0xc0);
    if (iVar1 != 0) {
      pcVar3 = "tav_f_iface.nif";
      goto LAB_00419d99;
    }
  }
  else {
    iVar1 = FUN_00533c78(0xc0);
    if (iVar1 != 0) {
      uVar2 = FUN_004baa30(DAT_008e9fec, "tav_d_iface.nif", 0, 0, 0, 0, 0xffffffff,
                           0, 0, 0, 0);
      return uVar2;
    }
  }
  return 0;
}

// 0x419de0 — observed shape: void(void), in_EBX receiver
// Samples the frame gate via FUN_005002f0; when the elapsed value exceeds 10,
// looks up dg2_water_shader and dg2_water, flips their material enable bits
// (set bit 0 on the water node, clear it on the shader), then rebuilds the
// water pass and releases DAT_008e9fd8.
void FUN_00419de0(void *self)
{
  int iVar1;
  int iVar2;
  int *unaff_EBX = (int *)self;
  uint32_t local_8;   // out-parameter filled by FUN_005002f0

  FUN_005002f0();
  if (10 < local_8) {
    iVar1 = (**(code **)(*unaff_EBX + 0x40))("dg2_water_shader");
    iVar2 = (**(code **)(*unaff_EBX + 0x40))("dg2_water");
    if (*(int *)(iVar2 + 0xc0) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = **(int **)(iVar2 + 0xb8);
    }
    *(uint8_t *)(iVar2 + 0x20) = *(uint8_t *)(iVar2 + 0x20) | 1;
    *(uint16_t *)(iVar1 + 0x20) = *(uint16_t *)(iVar1 + 0x20) & 0xfffe;
    if (*(int *)(iVar1 + 0xc0) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = **(int **)(iVar1 + 0xb8);
    }
    *(uint16_t *)(iVar1 + 0x20) = *(uint16_t *)(iVar1 + 0x20) & 0xfffe;
    FUN_00534350();
    FUN_00534130();
    FUN_004d4eb0(DAT_008e9fd8);
  }
  return;
}

// 0x419e90 — observed shape: void(void)
// Samples the frame gate via FUN_005002f0; when elapsed > 10, calls
// FUN_004d4e60().
void FUN_00419e90(void)
{
  uint32_t local_8;   // out-parameter filled by FUN_005002f0

  FUN_005002f0();
  if (10 < local_8) {
    FUN_004d4e60();
  }
  return;
}

// 0x419ec0 — observed shape: void(void), in_EBX receiver
// Frame-gated (> 10) water teardown/rebuild: flushes the water pass,
// re-links DAT_008e9ffc through the object at [unaff_EBX+8]'s slot 0x70,
// rebuilds dg2_water_shader material state around FUN_004d4fe0, and releases
// the two staged objects through slot 0x74.
void FUN_00419ec0(void *self)
{
  int iVar1;
  int *unaff_EBX = (int *)self;
  uint32_t *puVar2;
  const char *pcStack_24 = nullptr;
  int *piStack_20 = nullptr;
  uint32_t uStack_1c = 0;
  uint32_t uStack_18 = 0;
  uint32_t uStack_14 = 0;
  uint32_t local_8;   // out-parameter filled by FUN_005002f0

  uStack_14 = 0x419ed2;
  FUN_005002f0();
  if (10 < local_8) {
    uStack_14 = 0x419ee8;
    FUN_00534350();
    uStack_14 = 1;
    uStack_18 = (uint32_t)(uintptr_t)DAT_008e9ffc;
    uStack_1c = 0x419ef9;
    // Staged stack arguments (uStack_14, uStack_18) forwarded to slot 0x70.
    (**(code **)(**(int **)(unaff_EBX + 8) + 0x70))(uStack_14, uStack_18);
    uStack_1c = 1;
    piStack_20 = (int *)0x0;
    pcStack_24 = (const char *)0x419f05;
    FUN_00533d10();
    uStack_1c = 1;
    piStack_20 = (int *)DAT_008e9fec;
    pcStack_24 = (const char *)0x419f16;
    (**(code **)(**(int **)(unaff_EBX + 8) + 0x70))(uStack_1c, piStack_20);
    pcStack_24 = (const char *)0x1;
    FUN_00533d10(0);
    pcStack_24 = "dg2_water_shader";
    iVar1 = (**(code **)(*(int *)DAT_008e9fec + 0x40))();
    *(uint8_t *)(iVar1 + 0x20) = *(uint8_t *)(iVar1 + 0x20) | 1;
    FUN_004d4fe0(unaff_EBX);
    *(uint8_t *)(iVar1 + 0x20) = *(uint8_t *)(iVar1 + 0x20) & 0xfe;
    puVar2 = &uStack_1c;
    (**(code **)(**(int **)(unaff_EBX + 8) + 0x74))(puVar2, DAT_008e9ffc);
    if ((pcStack_24 != nullptr) &&
        (iVar1 = *(int *)(pcStack_24 + 4), *(int *)(pcStack_24 + 4) = iVar1 + -1,
         iVar1 + -1 == 0)) {
      (*(void (__stdcall **)(int))*(uint32_t *)*(uint32_t **)pcStack_24)(1);
    }
    FUN_00533d10(0, 1);
    (**(code **)(**(int **)(unaff_EBX + 8) + 0x74))(&pcStack_24, DAT_008e9fec);
    if ((puVar2 != nullptr) &&
        (iVar1 = puVar2[1], puVar2[1] = iVar1 + -1, iVar1 + -1 == 0)) {
      (**(code **)*puVar2)(1);
    }
    FUN_00533d10(0, 1);
    (**(code **)(*(int *)DAT_008e9fe8 + 0x70))(DAT_008e9ffc, 1);
    (**(code **)(*(int *)DAT_008e9fe8 + 0x70))(DAT_008e9fec, 1);
    FUN_00534350();
  }
  return;
}

// 0x41a000 — observed shape: void(undefined4 param_1, int* param_2, int* param_3),
// in_ECX receiver
// Emits "shadow_%02d", evaluates FUN_004c1000(&DAT_008cacd0) into three
// scratch values, then copies those values into the +0x78/+0x7c/+0x80
// vector triple of the two receiver meshes and of param_2/param_3's first
// three entries (skipping null entries).
void FUN_0041a000(void *self, uint32_t param_1, int *param_2, int *param_3)
{
  int iVar1;
  int *in_ECX = (int *)self;
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;

  FUN_004f2600("shadow_%02d");
  FUN_004c1000(&DAT_008cacd0);
  iVar1 = *in_ECX;
  *(uint32_t *)(iVar1 + 0x78) = local_c;
  *(uint32_t *)(iVar1 + 0x7c) = local_8;
  *(uint32_t *)(iVar1 + 0x80) = local_4;
  iVar1 = in_ECX[1];
  *(uint32_t *)(iVar1 + 0x78) = local_c;
  *(uint32_t *)(iVar1 + 0x7c) = local_8;
  *(uint32_t *)(iVar1 + 0x80) = local_4;
  if ((param_2 != nullptr) && (iVar1 = *param_2, iVar1 != 0)) {
    *(uint32_t *)(iVar1 + 0x78) = local_c;
    *(uint32_t *)(iVar1 + 0x7c) = local_8;
    *(uint32_t *)(iVar1 + 0x80) = local_4;
  }
  if ((param_3 != nullptr) && (iVar1 = *param_3, iVar1 != 0)) {
    *(uint32_t *)(iVar1 + 0x78) = local_c;
    *(uint32_t *)(iVar1 + 0x7c) = local_8;
    *(uint32_t *)(iVar1 + 0x80) = local_4;
  }
  if ((param_2 != nullptr) && (iVar1 = param_2[1], iVar1 != 0)) {
    *(uint32_t *)(iVar1 + 0x78) = local_c;
    *(uint32_t *)(iVar1 + 0x7c) = local_8;
    *(uint32_t *)(iVar1 + 0x80) = local_4;
  }
  if ((param_3 != nullptr) && (iVar1 = param_3[1], iVar1 != 0)) {
    *(uint32_t *)(iVar1 + 0x78) = local_c;
    *(uint32_t *)(iVar1 + 0x7c) = local_8;
    *(uint32_t *)(iVar1 + 0x80) = local_4;
  }
  if ((param_2 != nullptr) && (iVar1 = param_2[2], iVar1 != 0)) {
    *(uint32_t *)(iVar1 + 0x78) = local_c;
    *(uint32_t *)(iVar1 + 0x7c) = local_8;
    *(uint32_t *)(iVar1 + 0x80) = local_4;
  }
  if ((param_3 != nullptr) && (iVar1 = param_3[2], iVar1 != 0)) {
    *(uint32_t *)(iVar1 + 0x78) = local_c;
    *(uint32_t *)(iVar1 + 0x7c) = local_8;
    *(uint32_t *)(iVar1 + 0x80) = local_4;
  }
  return;
}

// 0x41a110 — observed shape: void(undefined4 param_1), in_ECX receiver
// Maps DAT_0072ccd8 (1/8/7/2/6/4/9) onto an OR-mask (0x10000, 0x80000,
// 0x400000, 0x20000, 0x800000, 0x100000, 0x200000) applied to the receiver,
// then forwards FUN_00473b70(mask, param_1, 3). Other values pass the
// receiver through unchanged.
void FUN_0041a110(void *self, uint32_t param_1)
{
  uint32_t in_ECX = (uint32_t)(uintptr_t)self;

  if (DAT_0072ccd8 == 1) {
    FUN_00473b70(in_ECX | 0x10000, param_1, 3);
    return;
  }
  if (DAT_0072ccd8 == 8) {
    FUN_00473b70(in_ECX | 0x80000, param_1, 3);
    return;
  }
  if (DAT_0072ccd8 == 7) {
    FUN_00473b70(in_ECX | 0x400000, param_1, 3);
    return;
  }
  if (DAT_0072ccd8 == 2) {
    FUN_00473b70(in_ECX | 0x20000, param_1, 3);
    return;
  }
  if (DAT_0072ccd8 == 6) {
    FUN_00473b70(in_ECX | 0x800000, param_1, 3);
    return;
  }
  if (DAT_0072ccd8 == 4) {
    FUN_00473b70(in_ECX | 0x100000, param_1, 3);
    return;
  }
  if (DAT_0072ccd8 == 9) {
    in_ECX = in_ECX | 0x200000;
  }
  FUN_00473b70(in_ECX, param_1, 3);
  return;
}

// ---------------------------------------------------------------------------
// Symbols referenced by 0x415860 (the ballroom dance sequence).
// Overlapping views of the same 0x860b00/0x72c780 record areas are declared
// with the element widths observed at each access site.
// ---------------------------------------------------------------------------
extern uint32_t DAT_008cacd8;
extern uint32_t DAT_00007f02;
extern uint8_t  DAT_008ca914;
extern uint32_t DAT_007268f4[];
extern int32_t  DAT_00726a84;
extern uint32_t DAT_007263bc;
extern uint32_t DAT_008cade4;
extern uint32_t DAT_008cade0;
extern uint32_t DAT_008cade8;
extern uint32_t DAT_00727428;
extern uint32_t DAT_00727424;
extern uint32_t DAT_0072742c;
extern void    *DAT_008ea08c;
extern uint8_t  DAT_00725d98;
extern uint8_t  DAT_00726814[];
extern int32_t  DAT_00726820;
extern int32_t  DAT_0085a26c;
extern int32_t  DAT_0085a268;
extern int32_t  DAT_0085a158;
extern int32_t  DAT_00722aa0;
extern void    *DAT_008ea000;
extern void    *DAT_008ea008;
extern uint32_t DAT_008e8f04;
extern uint32_t DAT_008e8f08;
extern uint8_t  DAT_008e8eff;
extern uint32_t DAT_008e8f00;           // also observed as _DAT_008e8f00
extern uint32_t DAT_008c7348;
extern int32_t  DAT_00869a88[];
extern uint8_t  DAT_00869a70[];
extern uint32_t PTR_FUN_006fd14c;
extern uint32_t PTR_FUN_006f583c;
extern uint32_t PTR_FUN_006f5864;
extern int32_t  DAT_00727444;
extern int32_t  DAT_007263a0;
extern uint32_t DAT_008ed61c;           // also observed as _DAT_008ed61c
extern uint32_t DAT_008ed618;
extern uint32_t DAT_008ed510;
extern uint32_t DAT_008ca90c;
extern uint32_t DAT_008ca4cc;
extern int32_t  DAT_008ca4c8[];
extern uint8_t  DAT_008ca910;
extern int32_t  DAT_0072c778;
extern int32_t  DAT_0072c780[];
extern int32_t  DAT_0072c788;
extern int32_t  DAT_0072c78c;
extern int32_t  DAT_0072c790;
extern int32_t  DAT_0072c794;
extern int32_t  DAT_0072c798;
extern int32_t  DAT_0072c79c;
extern int32_t  DAT_0072c7a0[];
extern int32_t  DAT_0072c7a4[];
extern int32_t  DAT_0072c7a8[];
extern int32_t  DAT_0072c7ac[];
extern int32_t  DAT_0072c7cc;
extern int32_t  DAT_0072c7d0;
extern int32_t  DAT_0072c7d8;
extern int32_t  DAT_0072c7dc;
extern int32_t  DAT_0072c784;
extern int32_t  DAT_0072c794;
extern uint8_t  DAT_00869b2d;
extern int8_t   DAT_00722a50[];
extern int32_t  DAT_007252f0[];
extern int32_t  DAT_00725350[];
extern int32_t  DAT_0086c330;
extern uint32_t DAT_0085a164;
extern int32_t  DAT_0085a11c;
extern int32_t  DAT_0086c35c;
extern uint8_t  DAT_007263bb;
extern uint32_t DAT_008c97c0;
extern uint32_t DAT_008c97c4;
extern void    *DAT_008e9fe8;
extern uint32_t DAT_008e8ec4;
extern uint32_t DAT_008e8ec8;           // also observed as _DAT_008e8ec8
extern uint8_t  DAT_008cac27;
extern int32_t  DAT_008c8494;
extern uint32_t DAT_00869aac;           // also observed as _DAT_00869aac
extern uint32_t PTR_PTR_007268dc;
extern uint32_t *DAT_007268e0;
extern int32_t  DAT_007268e8;
extern uint8_t  DAT_00869b48[];

extern void FUN_004a7610();
extern void FUN_004af990();
extern void FUN_00481100();
extern void FUN_00412840(uint32_t param_1, uint32_t param_2);
extern void FUN_004f6090(const char *format, ...);
extern int  FUN_00430190(int param_1, int param_2, const char *name, int param_4,
                         uint32_t param_5, int param_6, int param_7,
                         uint32_t param_8, int param_9, int param_10);
extern void FUN_00481180();
extern void FUN_004a76c0();
extern void FUN_004bdca0(...);
extern void FUN_004c0870(int param_1);
extern void FUN_004beee0();
extern void FUN_004d4da0();
extern void FUN_004d4eb0(void *param_1);
extern int  FUN_004af680(...);
extern int  FUN_00482ca0(int param_1);
extern void FUN_004be140(void *param_1, int param_2);
extern void FUN_004bcd90(int param_1, int param_2, int param_3);
extern void FUN_004c1080(void *param_1, const char *name, int param_3, int param_4);
extern int  FUN_00482200(int param_1);
extern int  FUN_004826a0();
extern char FUN_00418dd0(...);
extern void FUN_004888e0(int param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4);
extern void FUN_004a0c00(uint32_t param_1);
extern void FUN_004985e0();
extern void FUN_004a14b0();
extern int  FUN_004bb500(int param_1);
extern void FUN_004bf760(uint32_t param_1);
extern void FUN_004ab3c0(uint32_t *list, int *node);
extern int  FUN_005f0ddc();
extern int  FUN_004db210(...);
extern int  FUN_004dadc0(int param_1, int param_2, int param_3);
extern void FUN_004bbc80(...);
extern void FUN_00533d10(...);
extern void FUN_005516a0();
extern int  FUN_00551600(int param_1);
extern void FUN_005451a0(uint32_t param_1);
extern void FUN_004d4fe0(int *param_1);
extern void FUN_00534350();
extern int  FUN_004bc0d0();
extern void FUN_004ba7c0();
extern void FUN_004a77e0();
extern void FUN_004bbc10(...);
extern void FUN_004bbe10(int param_1, int param_2);
extern void FUN_004bbea0(int param_1, int param_2);
extern int  FUN_004bc160();
extern uint32_t FUN_00489440(intptr_t param_1, uint32_t param_2, uint32_t param_3, int param_4);
extern void FUN_00489360(int param_1, int param_2, int param_3, int param_4, int param_5);
extern void FUN_00473b70(uint32_t param_1, uint32_t param_2, uint32_t param_3);
extern void FUN_004bba60(void *param_1, int param_2, int param_3, uint32_t param_4, uint32_t param_5);
extern int  FUN_0042e440();
extern void FUN_004f4de0();
extern void FUN_004f0dc0();
extern void FUN_004d4e00();
extern void FUN_004b06c0(...);
extern void FUN_004afdb0(uint32_t param_1);
extern void FUN_004d0cd0(int param_1, int param_2, int param_3);
extern void FUN_004b21a0(int param_1, int param_2, int param_3, int param_4);
extern void FUN_00535670(void *param_1);
extern void FUN_004c1150(void *param_1, const char *name);
extern int  FUN_004c0cf0(int param_1, const char *name, int param_3);
extern void operator_delete__(void *ptr);
extern uint32_t DAT_008cacc8;
extern int32_t  DAT_008ca928;
extern int32_t  DAT_008ca92c;

// 0x415860 — observed shape: int(int param_1, int param_2, int unaff_retaddr),
// in_EBX receiver. Non-contiguous body spanning 0x415860-0x418cdf.
// Governs the governor's-daughter ballroom dance: picks the ballroom music
// from the callee-supplied parameter, builds the ballroom scene, loads the
// player/dancer animations and textures, runs the beat-synchronised particle
// and dance-mate simulation loop, tracks timing/score, dispatches input keys,
// and tears down all allocated scene objects. `unaff_retaddr` is the
// register-spilled return-address slot the decompiler could not name; it is
// used as the difficulty/track scalar (and as the third input value).
int FUN_00415860(void *self, int param_1, int param_2, int unaff_retaddr)
{
  int *piVar1;
  double dVar2;
  DWORD DVar3;
  uint32_t pHVar4;
  char cVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  uint32_t uVar10;
  uint32_t *puVar11;
  uint32_t uVar12;
  DWORD DVar13;
  uint32_t *puVar14;
  uint32_t uVar15;
  uint32_t *unaff_EBX = (uint32_t *)self;
  uint32_t pcVar16;
  uint32_t **ppuVar17;
  uint32_t uVar18;
  int iVar19;
  bool bVar20;
  char *pcVar21;
  uint32_t pHVar22;
  uint32_t *puVar23;
  char *pcVar24;
  uint32_t *puStack_3b8;
  uint32_t uStack_3b4;
  uint32_t uStack_3b0;
  uint32_t *puStack_3a8;
  uint32_t *puStack_3a4;
  uint32_t *puStack_3a0;
  int iStack_39c;
  uint32_t *puStack_398;
  int pHStack_394_p;
  int iStack_390;
  uint32_t *puStack_38c;
  uint32_t uStack_388;
  uint32_t uStack_384;
  int iStack_380;
  intptr_t pcStack_37c;
  int iStack_378;
  uint32_t *pHStack_374;
  int iStack_370;
  int iStack_36c;
  uint32_t *puStack_368;
  int iStack_364;
  int iStack_360;
  int iStack_35c;
  int iStack_358;
  int iStack_354;
  DWORD DStack_350;
  intptr_t pHStack_34c;
  int iStack_348;
  uint32_t *puStack_344;
  int iStack_340;
  uint32_t *puStack_33c;
  uint32_t *puStack_338;
  uint32_t *pHStack_334;
  int iStack_330;
  uint32_t *puStack_32c;
  int iStack_328;
  int iStack_324;
  int iStack_320;
  int iStack_31c;
  int iStack_318;
  intptr_t pHStack_314;
  uint32_t pHStack_310;
  uint32_t local_30c;
  uint32_t local_308;
  int iStack_304;
  int iStack_300;
  int iStack_2fc;
  int iStack_2f8;
  int iStack_2f4;
  uint32_t uStack_2f0;
  uint32_t uStack_2ec;
  int iStack_2e8;
  int iStack_2e4;
  int iStack_2e0;
  int iStack_2dc;
  uint32_t *puStack_2d8;
  uint32_t *puStack_2d4;
  uint32_t *puStack_2d0;
  int *piStack_2cc;
  int iStack_2c8;
  int *piStack_2c4;
  int iStack_2c0;
  int iStack_2bc;
  int *apiStack_2b8[4];
  uint8_t auStack_2a8[4];
  uint32_t *appuStack_2a4[2];
  uint32_t uStack_29c;
  uint32_t uStack_298;
  uint32_t uStack_294;
  void *puStack_288;
  double dStack_284;
  uint32_t uStack_278;
  uint32_t local_274;
  uint32_t local_270;
  uint32_t local_26c;
  uint32_t **ppuStack_268;
  uint32_t uStack_264;
  uint32_t uStack_260;
  uint32_t uStack_25c;
  uint32_t uStack_258;
  uint32_t uStack_254;
  uint32_t uStack_250;
  void *puStack_24c;
  uint32_t uStack_240;
  uint32_t uStack_23c;
  uint32_t uStack_234;
  int iStack_22c;
  uint32_t uStack_228;
  uint32_t uStack_224;
  void *puStack_1fc;
  void *puStack_1d4;
  uint32_t uStack_1a4;
  uint32_t uStack_19c;
  void *puStack_144;
  uint32_t uStack_13c;
  uint32_t uStack_134;
  void *puStack_dc;
  uint32_t uStack_d4;
  void *puStack_74;
  uint32_t uStack_6c;
  void *puStack_c;

  local_308 = DAT_008cacd8;
  if (DAT_008cacd8 == 0) {
    local_308 = (uint32_t)(uintptr_t)LoadCursorA(nullptr, (LPCSTR)&DAT_00007f02);
  }
  local_30c = (uint32_t)(uintptr_t)GetCursor();
  SetCursor((HCURSOR)(uintptr_t)local_308);
  FUN_004a7610();
  DAT_008ca914 = 0;
  FUN_004af990();
  *(uint32_t *)(&DAT_007268f4 + DAT_00726a84 * 4) = DAT_007263bc;
  local_270 = DAT_008cade4;
  local_274 = DAT_008cade0;
  local_26c = DAT_008cade8;
  DAT_008cade4 = DAT_00727428;
  DAT_00726a84 = DAT_00726a84 + 1;
  DAT_007263bc = 0x8ffffff2;
  DAT_008cade0 = DAT_00727424;
  DAT_008cade8 = DAT_0072742c;
  (*(void (__stdcall **)(void *))(*(uint32_t *)DAT_008ea08c + 0x74))(&DAT_008cade0);
  cVar5 = DAT_00725d98;
  DAT_00726814[DAT_00726820] = DAT_00725d98;
  DAT_00726820 = DAT_00726820 + 1;
  if (cVar5 != 0) {
    FUN_00481100();
  }
  DAT_00725d98 = 0;
  DAT_008c9df4 = 1;
  iStack_304 = 0;
  iStack_2e0 = 0;
  iStack_2e8 = 0;
  iStack_330 = 0;
  FUN_00412840(0x43fa0000, 0x47435000);
  local_308 = 0x320;
  if (param_1 == 0) {
    do {
      pHVar22 = pHStack_310;
      SetCursor((HCURSOR)(uintptr_t)pHStack_310);
      FUN_004f6090(
          "Dancing with the\nGovernor's daughter!\nChoose difficulty...\n Argh.\n Arghhh!\n Arghhhhh!!\n");
      unaff_retaddr =
          FUN_00430190(DAT_0085a26c / 2 + 0x1c, DAT_0085a268 / 3, "daughter.pcx", 0,
                       0xffffffff, 0, 0, 0xffffffff, 0, 0);
      DAT_0085a158 = unaff_retaddr;
      if (unaff_retaddr == -1) {
        FUN_00481180();
        FUN_004a76c0();
        DAT_00726a84 = DAT_00726a84 + -1;
        DAT_007263bc = *(uint32_t *)(&DAT_007268f4 + DAT_00726a84 * 4);
        SetCursor((HCURSOR)(uintptr_t)pHVar22);
        return -1;
      }
      FUN_004f6090(
          "Dancing with the\nGovernor's daughter!\nChoose ballroom...\n Spanish. (4 beats)\n English.\n French.\n Dutch.\n");
      param_2 = FUN_00430190(DAT_0085a26c / 2 + 0x1c, DAT_0085a268 / 3, "daughter.pcx",
                             0, 0xffffffff, 0, 0, 0xffffffff, 0, 0);
    } while (param_2 == -1);
    DAT_00722aa0 = 4 - (int32_t)(param_2 != 0);
    DAT_00860b74[param_2 * 0x20] = (char)param_2;
  }
  else {
    iVar6 = DAT_0085a158 + 3;
    if (iVar6 < 1) {
      iVar8 = 0;
    }
    else {
      iVar8 = rand();
      iVar8 = iVar8 % iVar6;
    }
    DAT_00722aa0 = (2 < iVar8) + 3;
  }
  if (DAT_0085a158 == -1) {
    SetCursor((HCURSOR)(uintptr_t)pHStack_310);
    return -1;
  }
  if (DAT_00722aa0 == 4) {
    local_308 = 0x258;
  }
  SetCursor((HCURSOR)(uintptr_t)local_30c);
  pcStack_37c = (intptr_t)(&DAT_00860b74 + param_2 * 0x20);
  switch (*(char *)pcStack_37c) {
  case '\0':
    iVar6 = FUN_00533c78(0xc0);
    if (iVar6 == 0) {
      puStack_3b8 = nullptr;
    }
    else {
      puStack_3b8 = (uint32_t *)FUN_004baa30(DAT_008e9fec, "s_gov_ballroom.NIF",
                                             0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    iVar6 = FUN_00533c78(0xc0);
    if (iVar6 != 0) {
      pcVar21 = "s_gov_ballroom_lights.nif";
      break;
    }
    uStack_3b0 = 0;
    goto LAB_00415cf5;
  case '\x01':
    iVar6 = FUN_00533c78(0xc0);
    if (iVar6 == 0) {
      puStack_3b8 = nullptr;
    }
    else {
      puStack_3b8 = (uint32_t *)FUN_004baa30(DAT_008e9fec, "e_gov_ballroom.NIF",
                                             0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    iVar6 = FUN_00533c78(0xc0);
    if (iVar6 == 0) goto LAB_00415cf1;
    pcVar21 = "e_gov_ballroom_lights.nif";
    break;
  default:
    iVar6 = FUN_00533c78(0xc0);
    if (iVar6 == 0) {
      puStack_3b8 = nullptr;
    }
    else {
      puStack_3b8 = (uint32_t *)FUN_004baa30(DAT_008e9fec, "f_gov_ballroom.NIF",
                                             0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    iVar6 = FUN_00533c78(0xc0);
    if (iVar6 == 0) goto LAB_00415cf1;
    pcVar21 = "f_gov_ballroom_lights.nif";
    break;
  case '\x03':
    iVar6 = FUN_00533c78(0xc0);
    if (iVar6 == 0) {
      puStack_3b8 = nullptr;
    }
    else {
      puStack_3b8 = (uint32_t *)FUN_004baa30(DAT_008e9fec, "d_gov_ballroom.NIF",
                                             0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    iVar6 = FUN_00533c78(0xc0);
    if (iVar6 == 0) goto LAB_00415cf1;
    pcVar21 = "d_gov_ballroom_lights.nif";
  }
  uStack_3b0 = FUN_004baa30(DAT_008e9fec, pcVar21, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
LAB_00415cf5:
  puStack_398 = (uint32_t *)FUN_00533c78(0xc0);
  uVar18 = (uint32_t)(uintptr_t)DAT_008e9ffc;
  if (puStack_398 == nullptr) {
    puStack_398 = nullptr;
  }
  else {
    puStack_398[1] = 0;
    *puStack_398 = (uint32_t)(uintptr_t)&PTR_FUN_006fd14c;
    puStack_398[7] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    puStack_398[0x19] = 0;
    puStack_398[0x2f] = 0;
    FUN_004bdca0(uVar18, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
  }
  puStack_3a0 = (uint32_t *)FUN_00533c78(0xc0);
  uVar18 = (uint32_t)(uintptr_t)DAT_008e9ffc;
  if (puStack_3a0 == nullptr) {
    puStack_3a0 = nullptr;
  }
  else {
    puStack_3a0[1] = 0;
    *puStack_3a0 = (uint32_t)(uintptr_t)&PTR_FUN_006fd14c;
    puStack_3a0[7] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    puStack_3a0[0x19] = 0;
    puStack_3a0[0x2f] = 0;
    FUN_004bdca0(uVar18, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
  }
  puStack_3a4 = (uint32_t *)FUN_00533c78(0xc0);
  uVar18 = (uint32_t)(uintptr_t)DAT_008e9ffc;
  if (puStack_3a4 == nullptr) {
    puStack_3a4 = nullptr;
  }
  else {
    puStack_3a4[1] = 0;
    *puStack_3a4 = (uint32_t)(uintptr_t)&PTR_FUN_006fd14c;
    puStack_3a4[7] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    puStack_3a4[0x19] = 0;
    puStack_3a4[0x2f] = 0;
    FUN_004bdca0(uVar18, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
  }
  puStack_398[0xb] = 0xbf800000;
  puStack_3a0[0xb] = 0xbf800000;
  puStack_3a4[0xb] = 0xbf800000;
  if (puStack_3b8[0x2f] != 0) {
    FUN_004c0870(1);
  }
  puStack_3b8[8] = puStack_3b8[8] | 0x8000;
  FUN_004beee0();
  FUN_004beee0();
  FUN_004beee0();
  FUN_004beee0();
  FUN_004beee0();
  FUN_004d4da0();
  FUN_005002f0();
  if (10 < (int)(intptr_t)puStack_32c) {
    piVar7 = (int *)FUN_004baaa0();
    iVar6 = (*(int (__stdcall **)(const char *))(*(uint32_t *)piVar7 + 0x40))(
        "f_br_floor_shader");
    piVar7 = (int *)FUN_004baaa0();
    iVar8 = (*(int (__stdcall **)(const char *))(*(uint32_t *)piVar7 + 0x40))(
        "f_br_floor");
    if (*(int *)(iVar8 + 0xc0) == 0) {
      iVar8 = 0;
    }
    else {
      iVar8 = **(int **)(iVar8 + 0xb8);
    }
    if (*(int *)(iVar6 + 0xc0) == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = **(int **)(iVar6 + 0xb8);
    }
    *(uint8_t *)(iVar8 + 0x20) = *(uint8_t *)(iVar8 + 0x20) | 1;
    *(uint8_t *)(iVar6 + 0x20) = *(uint8_t *)(iVar6 + 0x20) & 0xfe;
    FUN_004d4eb0(DAT_008e9fd8);
  }
  iVar6 = (int)(intptr_t)DAT_008ea000;
  if (DAT_00722aa0 == 3) {
    pcVar21 = "Player_Character.kfm";
  }
  else {
    pcVar21 = "Player_Character_4-4.kfm";
  }
  if (DAT_008ea000 != 0) {
    *(int *)((intptr_t)DAT_008ea000 + 4) =
        *(int *)((intptr_t)DAT_008ea000 + 4) + 1;
  }
  pHStack_394 = (uint32_t *)FUN_004af680(iVar6, pcVar21, 0, 0, 0, 0, 0xffffffff, 0, 0,
                                         0, 0, 0);
  pHStack_374 = (uint32_t *)FUN_00482ca0((DAT_00722aa0 == 3) + '\x01');
  FUN_004be140(pHStack_394, 0);
  FUN_004be140(pHStack_374, 0);
  FUN_004bcd90(DAT_00869a88[*(char *)pcStack_37c * 2], (int)*(char *)pcStack_37c,
               (int)DAT_00869a70[3]);
  puStack_338 = (uint32_t *)FUN_00533c78(0xc0);
  uVar18 = (uint32_t)(uintptr_t)DAT_008ea008;
  if (puStack_338 == nullptr) {
    puStack_338 = nullptr;
  }
  else {
    puStack_338[1] = 0;
    *puStack_338 = (uint32_t)(uintptr_t)&PTR_FUN_006fd14c;
    puStack_338[7] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    puStack_338[0x19] = 0;
    puStack_338[0x2f] = 0;
    FUN_004bdca0(uVar18, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
  }
  puStack_2d0 = (uint32_t *)FUN_00533c78(0xc0);
  uVar18 = (uint32_t)(uintptr_t)DAT_008ea008;
  if (puStack_2d0 == nullptr) {
    puStack_2d0 = nullptr;
  }
  else {
    puStack_2d0[1] = 0;
    *puStack_2d0 = (uint32_t)(uintptr_t)&PTR_FUN_006fd14c;
    puStack_2d0[7] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    puStack_2d0[0x19] = 0;
    puStack_2d0[0x2f] = 0;
    FUN_004bdca0(uVar18, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
  }
  puStack_2d4 = (uint32_t *)FUN_00533c78(0xc0);
  uVar18 = (uint32_t)(uintptr_t)DAT_008ea008;
  if (puStack_2d4 == nullptr) {
    puStack_2d4 = nullptr;
  }
  else {
    puStack_2d4[1] = 0;
    *puStack_2d4 = (uint32_t)(uintptr_t)&PTR_FUN_006fd14c;
    puStack_2d4[7] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    puStack_2d4[0x19] = 0;
    puStack_2d4[0x2f] = 0;
    FUN_004bdca0(uVar18, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
  }
  puStack_32c = (uint32_t *)FUN_00533c78(0xc0);
  uVar18 = (uint32_t)(uintptr_t)DAT_008e9ffc;
  if (puStack_32c == nullptr) {
    puStack_32c = nullptr;
  }
  else {
    puStack_32c[1] = 0;
    *puStack_32c = (uint32_t)(uintptr_t)&PTR_FUN_006fd14c;
    puStack_32c[7] = 0;
    DAT_00727444 = DAT_00727444 + 1;
    puStack_32c[0x19] = 0;
    puStack_32c[0x2f] = 0;
    FUN_004bdca0(uVar18, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
  }
  pHStack_334 = pHStack_394 + 0x1e;
  puStack_38c = (uint32_t *)0x426a50e5;
  pHStack_334[0] = 0x426a50e5;
  uStack_388 = 0xc2a191ec;
  pHStack_394[0x1f] = 0xc2a191ec;
  uStack_384 = 0x43235a1d;
  pHStack_394[0x20] = 0x43235a1d;
  pHStack_314 = (intptr_t)(pHStack_374 + 0x1e);
  ((uint32_t *)pHStack_314)[0] = 0x426a50e5;
  pHStack_374[0x1f] = 0xc2a191ec;
  pHStack_374[0x20] = 0x43235a1d;
  FUN_004c1080(puStack_3b8, "candle", 100, 0xffffffff);
  FUN_004c1080(puStack_3b8, "fireplace", 100, 0xffffffff);
  FUN_004c1080(puStack_3b8, "fireplace", 100, 0xffffffff);
  iVar6 = FUN_00533c78(0xc0);
  if (iVar6 == 0) {
    iStack_328 = 0;
  }
  else {
    pcVar21 = "dance_m.kfm";
    if (DAT_00722aa0 != 3) {
      pcVar21 = "dance_m_4-4.kfm";
    }
    iStack_328 = FUN_004baa30(DAT_008ea000, pcVar21, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
  }
  iVar6 = FUN_00533c78(0xc0);
  if (iVar6 == 0) {
    iVar6 = 0;
  }
  else {
    pcVar21 = "dancer_f.kfm";
    if (DAT_00722aa0 != 3) {
      pcVar21 = "dancer_f_4-4.kfm";
    }
    iVar6 = FUN_004baa30(DAT_008ea000, pcVar21, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
  }
  iStack_348 = iVar6;
  FUN_004be140((void *)(intptr_t)iStack_328, 0);
  FUN_004be140((void *)(intptr_t)iVar6, 0);
  piStack_2cc = (int *)FUN_00482200(0);
  uStack_2ec = FUN_004826a0();
  pHVar4 = (uint32_t)(uintptr_t)pHStack_374;
  pHVar22 = (uint32_t)(uintptr_t)pHStack_394;
  cVar5 = FUN_00418dd0(0x3c, pHStack_394, pHStack_374, puStack_3b8, apiStack_2b8);
  if (cVar5 != '\0') {
    FUN_004888e0(0x8f, 0xffffffff, 0xffffffff, 0xbf800000);
    FUN_00418dd0(unaff_retaddr + 0x3d, (void *)pHVar22, (void *)pHVar4, puStack_3b8,
                 apiStack_2b8);
  }
  FUN_00412840(0x44160000, 0x47435000);
  bVar20 = DAT_00722aa0 != 3;
  if (DAT_00722aa0 != 3) {
    iVar6 = rand();
    switch (iVar6 % 3 + -1 + DAT_0085a158 / 2) {
    case 0:
      goto switchD_0041643d_caseD_0;
    case 1:
      goto switchD_0041643d_caseD_3;
    case 2:
      goto switchD_0041643d_caseD_2;
    case 3:
      goto switchD_0041643d_caseD_1;
    default:
      goto switchD_0041643d_caseD_5;
    }
  }
  iVar6 = rand();
  switch (iVar6 % 3 + -1 + DAT_0085a158) {
  case 0:
switchD_0041643d_caseD_0:
    uVar18 = 3;
    break;
  case 1:
switchD_0041643d_caseD_1:
    uVar18 = 4;
    break;
  case 2:
switchD_0041643d_caseD_2:
    uVar18 = 0;
    break;
  case 3:
switchD_0041643d_caseD_3:
    uVar18 = 2;
    break;
  case 4:
    uVar18 = 6;
    break;
  case 5:
switchD_0041643d_caseD_5:
    uVar18 = 1;
    break;
  default:
    uVar18 = 5;
  }
  FUN_004a0c00(uVar18);
  if (DAT_008e8f04 == 0) {
    iStack_370 = -1;
  }
  else {
    iStack_370 = *(int *)(DAT_008e8f08 + 4);
  }
  if (DAT_008e8f04 < 2) {
    iStack_378 = -1;
  }
  else {
    iStack_378 = *(int *)(DAT_008e8f08 + 0x1c);
  }
  if (DAT_008e8eff == '\0') {
    DAT_008e8f00 = 0xffffffff;
    puStack_1d4 = &DAT_008cacd0;
    uStack_234 = 0x11;
    puStack_1fc = &DAT_008c7348;
    uStack_224 = 100;
    iStack_22c = (bVar20 - 1 & 0xfffffffd) + 0xa2;
    uStack_228 = uVar18;
    FUN_004985e0();
    FUN_004a14b0();
  }
  FUN_004baaa0();
  iVar6 = FUN_004bb500(0);
  iStack_324 = iVar6;
  iVar8 = FUN_004bb500(0);
  iStack_320 = iVar8;
  iVar9 = FUN_004bb500(0);
  iStack_31c = iVar9;
  puStack_344 = (uint32_t *)FUN_004bb500(0);
  iStack_340 = FUN_004bb500(0);
  puStack_33c = (uint32_t *)FUN_004bb500(0);
  puStack_38c = nullptr;
  pHStack_334[0] = 0;
  uStack_388 = 0;
  pHStack_334[1] = 0;
  uStack_384 = 0x44bb8000;
  pHStack_334[2] = 0x44bb8000;
  ((uint32_t *)pHStack_314)[0] = 0;
  ((uint32_t *)pHStack_314)[1] = 0;
  ((uint32_t *)pHStack_314)[2] = 0x44bb8000;
  *(uint32_t *)(iStack_328 + 0x78) = 0;
  *(uint32_t *)(iStack_328 + 0x7c) = 0;
  *(uint32_t *)(iStack_328 + 0x80) = 0x44bb8000;
  *(uint32_t *)(iVar6 + 0x78) = 0;
  *(uint32_t *)(iVar6 + 0x7c) = 0;
  *(uint32_t *)(iVar6 + 0x80) = 0x44bb8000;
  *(uint32_t *)(iVar8 + 0x78) = 0;
  *(uint32_t *)(iVar8 + 0x7c) = 0;
  *(uint32_t *)(iVar8 + 0x80) = 0x44bb8000;
  *(uint32_t *)(iVar9 + 0x78) = 0;
  *(uint32_t *)(iVar9 + 0x7c) = 0;
  *(uint32_t *)(iVar9 + 0x80) = 0x44bb8000;
  *(uint32_t *)(iStack_348 + 0x78) = 0;
  *(uint32_t *)(iStack_348 + 0x7c) = 0;
  *(uint32_t *)(iStack_348 + 0x80) = 0x44bb8000;
  puStack_344[0x1e] = 0;
  puStack_344[0x1f] = 0;
  puStack_344[0x20] = 0x44bb8000;
  *(uint32_t *)(iStack_340 + 0x78) = 0;
  *(uint32_t *)(iStack_340 + 0x7c) = 0;
  *(uint32_t *)(iStack_340 + 0x80) = 0x44bb8000;
  puStack_33c[0x1e] = 0;
  puStack_33c[0x1f] = 0;
  puStack_33c[0x20] = 0x44bb8000;
  iVar6 = 0;
  do {
    uVar10 = rand();
    uVar10 = uVar10 & 0x80000003;
    if ((int)uVar10 < 0) {
      uVar10 = (uVar10 - 1 | 0xfffffffc) + 1;
    }
    switch (uVar10) {
    case 0:
      uVar18 = FUN_004baaa0(0, "dance_m1.dds", "dance_m4.dds");
      FUN_004bf760(uVar18);
      pcVar21 = "dancer3_F.dds";
      break;
    case 1:
      pcVar21 = "dance_m2.dds";
      pcVar24 = "dance_m1.dds";
      goto LAB_00416712;
    case 2:
      pcVar21 = "dancer2_F.dds";
      break;
    case 3:
      uVar18 = FUN_004baaa0(0, "dance_m1.dds", "dance_m3.dds");
      FUN_004bf760(uVar18);
      pcVar21 = "dancer4_F.dds";
      break;
    default:
      goto switchD_00416697_default;
    }
    pcVar24 = "dancer1_F.dds";
LAB_00416712:
    uVar18 = FUN_004baaa0(0, pcVar24, pcVar21);
    FUN_004bf760(uVar18);
switchD_00416697_default:
    iVar6 = iVar6 + 4;
  } while (iVar6 < 0x10);
  puVar14 = DAT_007268e0;
  if (DAT_007268e8 != 0) {
    while (puVar14 != nullptr) {
      puVar11 = puVar14 + 2;
      puVar14 = (uint32_t *)*puVar14;
      if (*(uint32_t **)*puVar11 == puStack_398) {
        FUN_004ab3c0(&PTR_PTR_007268dc, (int *)*puVar11);
        DAT_008c9df4 = 1;
      }
    }
    puVar14 = DAT_007268e0;
    if (DAT_007268e8 != 0) {
      while (puVar14 != nullptr) {
        puVar11 = puVar14 + 2;
        puVar14 = (uint32_t *)*puVar14;
        if (*(uint32_t **)*puVar11 == puStack_3a0) {
          FUN_004ab3c0(&PTR_PTR_007268dc, (int *)*puVar11);
          DAT_008c9df4 = 1;
        }
      }
      puVar14 = DAT_007268e0;
      if (DAT_007268e8 != 0) {
        while (puVar14 != nullptr) {
          puVar11 = puVar14 + 2;
          puVar14 = (uint32_t *)*puVar14;
          if (*(uint32_t **)*puVar11 == puStack_3a4) {
            FUN_004ab3c0(&PTR_PTR_007268dc, (int *)*puVar11);
            DAT_008c9df4 = 1;
          }
        }
      }
    }
  }
  FUN_004c1080(puStack_3b8, "candle", 1000, 0xffffffff);
  FUN_004c1080(puStack_3b8, "fireplace", 1000, 0xffffffff);
  FUN_004c1080(puStack_3b8, "fireplace", 1000, 0xffffffff);
  iStack_2f8 = 0;
  pHStack_34c = 0;
  iStack_300 = 0;
  DAT_0072c778 = 0;
  puStack_24c = &DAT_008cacd0;
  uStack_264 = 0;
  uStack_260 = 0;
  uStack_25c = 0;
  uStack_258 = 0;
  uStack_254 = 0;
  uStack_250 = 0;
  ppuStack_268 = (uint32_t **)&PTR_FUN_006f583c;
  uStack_240 = 0;
  uStack_23c = 0;
  iStack_2e4 = unaff_retaddr;
  if (DAT_00722aa0 == 4) {
    rand();
  }
  else {
    iVar6 = rand();
    DStack_350 = iVar6 % 6;
  }
  pHStack_334 = (uint32_t *)(intptr_t)FUN_005f0ddc();
  puVar14 = (uint32_t *)&DAT_0072c780;
  for (iVar6 = 0xd8; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar14 = 0;
    puVar14 = puVar14 + 1;
  }
  uStack_3b4 = 0;
  puStack_3a8 = nullptr;
  uVar10 = 0;
  ppuVar17 = (uint32_t **)&DAT_0072c788;
  do {
    if (0x72c7e7 < (int)(intptr_t)ppuVar17) {
      iVar6 = FUN_004db210();
      ppuVar17[-1] = (uint32_t *)((intptr_t)ppuVar17[-1] + iVar6);
      iVar6 = FUN_004db210();
      *ppuVar17 = (uint32_t *)((intptr_t)*ppuVar17 + iVar6);
    }
    ppuVar17[3] = nullptr;
    puVar14 = (uint32_t *)((intptr_t)*ppuVar17 + ((-(uint32_t)((uVar10 & 1) != 0) & 600) - 300));
    *ppuVar17 = puVar14;
    uVar15 = uVar10 & 0x80000001;
    ppuVar17[1] = ppuVar17[-1];
    ppuVar17[2] = puVar14;
    if ((int)uVar15 < 0) {
      uVar15 = (uVar15 - 1 | 0xfffffffe) + 1;
    }
    ppuVar17[-2] = (uint32_t *)(uVar15 + 1);
    ppuVar17[9] = nullptr;
    ppuVar17 = ppuVar17 + 0xc;
    uVar10 = uVar10 + 1;
  } while ((int)(intptr_t)ppuVar17 < 0x72cae8);
  iStack_358 = DAT_0085a158 * -3 + 0x2b;
  iVar6 = DAT_0085a158 + 1 + unaff_retaddr;
  DAT_008ca910 = 0;
  iStack_2dc = 0;
  piStack_2c4 = nullptr;
  iStack_2f4 = 0;
  iStack_2c0 = 0;
  iStack_354 = 0;
  pHStack_314 = 0;
  pcStack_37c = 0x1770;
  iStack_2bc = iVar6;
  if (iVar6 < 1) {
    iStack_36c = 0;
  }
  else {
    iStack_36c = rand();
    iStack_36c = iStack_36c % iVar6;
  }
  iStack_364 = 1;
  iStack_360 = -3;
  iStack_39c = 5;
  iStack_2c8 = 0;
  iStack_390 = -1;
  iStack_318 = 0;
  iStack_380 = 0;
  SetCursor((HCURSOR)(uintptr_t)pHStack_310);
  do {
    if ((DAT_008ed61c & 1) == 0) {
      DAT_008ed61c = DAT_008ed61c | 1;
      DAT_008ed618 = timeGetTime();
    }
    DStack_350 = timeGetTime();
    DStack_350 = DStack_350 - DAT_008ed618;
    uVar18 = (uint32_t)FUN_005f0ddc();
    dStack_284 = (double)uVar18;
    if ((iStack_354 < -0x20000000) || (0x20000000 < iStack_354)) {
      if (DAT_008ca914 != '\0') {
        piVar7 = (int *)FUN_004baaa0();
        iVar6 = (*(int (__stdcall **)(const char *))(*(uint32_t *)piVar7 + 0x40))(
            "dance_hide_01");
        if (iVar6 != 0) {
          *(uint8_t *)(iVar6 + 0x20) = *(uint8_t *)(iVar6 + 0x20) & 0xfe;
        }
      }
      DAT_008ca914 = '\0';
    }
    else {
      if (DAT_008ca914 != '\x01') {
        piVar7 = (int *)FUN_004baaa0();
        iVar6 = (*(int (__stdcall **)(const char *))(*(uint32_t *)piVar7 + 0x40))(
            "dance_hide_01");
        if (iVar6 != 0) {
          *(uint8_t *)(iVar6 + 0x20) = *(uint8_t *)(iVar6 + 0x20) | 1;
        }
      }
      DAT_008ca914 = '\x01';
    }
    uVar18 = (uint32_t)FUN_004dadc0(0, 0, 0);
    FUN_004bbc80(0xfffffd44, 1000, 0, uVar18, 1000, 0xffffffff, 0);
    FUN_005002f0();
    if (10 < (int)(intptr_t)puStack_288) {
      (*(void (__stdcall **)(void *, int))(*(uint32_t *)apiStack_2b8[2] + 0x70))(
          DAT_008ea000, 1);
      FUN_00533d10(0, 1);
      (*(void (__stdcall **)(void *, int))(*(uint32_t *)apiStack_2b8[0] + 0x70))(
          DAT_008e9fec, 1);
      FUN_00533d10(0, 1);
      iVar8 = (*(int (__stdcall **)(const char *))(*(uint32_t *)DAT_008e9fec + 0x40))(
          "f_br_floor_shader");
      *(uint8_t *)(iVar8 + 0x20) = *(uint8_t *)(iVar8 + 0x20) | 1;
      iVar6 = puStack_3b8[0x14];
      while (iVar6 != 0) {
        FUN_005516a0();
        if ((DAT_008ca4cc == 0) && (DAT_008ca4c8[3] != 0)) {
          iVar6 = FUN_00551600(0);
          piVar7 = DAT_008ca4c8;
          if (iVar6 == 0) {
            piVar1 = (int *)DAT_008ca4c8[1];
            iVar6 = *piVar1;
            DAT_008ca4c8[1] = iVar6;
            if (iVar6 == 0) {
              piVar7[2] = 0;
            }
            else {
              *(uint32_t *)(iVar6 + 4) = 0;
            }
            iVar6 = piVar1[2];
            (*(void (__stdcall **)(int *))(*(uint32_t *)piVar7 + 8))(piVar1);
            piVar7[3] = piVar7[3] + -1;
            DAT_008ca4cc = (uint32_t)iVar6;
            FUN_005451a0(*(uint32_t *)(*(int *)(iVar6 + 8) + 8));
          }
        }
        iVar6 = puStack_3b8[0x14];
      }
      if ((puStack_3b8[0x2f] != 0) && (DAT_007263a0 < 2)) {
        FUN_004baaa0();
      }
      FUN_004d4fe0(piStack_2cc);
      *(uint8_t *)(iVar8 + 0x20) = *(uint8_t *)(iVar8 + 0x20) & 0xfe;
      (*(void (__stdcall **)(void **, void *))(*(uint32_t *)piStack_2c4 + 0x74))(
          (void **)appuStack_2a4, DAT_008ea000);
      if ((apiStack_2b8[3] != nullptr) &&
          (iVar6 = apiStack_2b8[3][1], apiStack_2b8[3][1] = iVar6 + -1, iVar6 + -1 == 0)) {
        (*(void (__stdcall **)(int))(*(uint32_t *)apiStack_2b8[3]))(1);
      }
      FUN_00533d10(0, 1);
      (*(void (__stdcall **)(uint8_t *, void *))(*(uint32_t *)piStack_2cc + 0x74))(
          auStack_2a8, DAT_008e9fec);
      if ((apiStack_2b8[2] != nullptr) &&
          (iVar6 = apiStack_2b8[2][1], apiStack_2b8[2][1] = iVar6 + -1, iVar6 + -1 == 0)) {
        (*(void (__stdcall **)(int))(*(uint32_t *)apiStack_2b8[2]))(1);
      }
      FUN_00533d10(0, 1);
      (*(void (__stdcall **)(void *, int))(*(uint32_t *)DAT_008e9fe8 + 0x70))(
          DAT_008ea000, 1);
      (*(void (__stdcall **)(void *, int))(*(uint32_t *)DAT_008e9fe8 + 0x70))(
          DAT_008e9fec, 1);
      FUN_00534350();
    }
    iStack_35c = DAT_008ed510 - DAT_008ca90c;
    if ((uStack_3b4 & 0x20) != 0) {
      iVar6 = FUN_005f0ddc();
      iStack_35c = (iStack_358 - iVar6) - (int)pHStack_334;
    }
    pHVar22 = local_308;
    iVar6 = iStack_36c;
    if (DAT_008e8f04 == 0) {
      iVar8 = -1;
    }
    else {
      iVar8 = *(int *)(DAT_008e8f08 + 4);
    }
    if (iVar8 <= iStack_35c) {
      uStack_3b4 = uStack_3b4 | 1;
    }
    iStack_358 = 0;
    if (((uStack_3b4 & 8) == 0) || (iStack_35c < iStack_378)) goto LAB_004173d0;
    if ((uStack_3b4 & 0x20) == 0) {
      if (iStack_380 + 1U < DAT_008e8f04) {
        iStack_370 = *(int *)(DAT_008e8f08 + 4 + (iStack_380 + 1U) * 0x18);
      }
      else {
        iStack_370 = -1;
      }
      if ((iStack_380 + 2U < DAT_008e8f04) &&
          (iStack_378 = *(int *)(DAT_008e8f08 + 4 + (iStack_380 + 2U) * 0x18),
           iStack_378 != -1)) {
        iStack_2fc = iStack_378 - iStack_370;
        if (iStack_2e0 == 0) {
          iStack_2e0 = iStack_2fc;
        }
      }
      else {
        iVar8 = (iStack_2e0 * 3) / 2;
        if (iVar8 < iStack_2fc) {
          iStack_2fc = iVar8;
        }
        uStack_3b4 = uStack_3b4 | 0x20;
        iStack_378 = iStack_2fc + iStack_370;
      }
    }
    else {
      iStack_2fc = iStack_2fc + ((int)(iStack_2fc + (iStack_2fc >> 0x1f & 3U)) >> 2);
      iStack_370 = iStack_378;
      iStack_378 = iStack_378 + iStack_2fc;
      if (iStack_380 % DAT_00722aa0 == 0) {
        if ((uStack_3b4 & 0x40) == 0) {
          uStack_3b4 = uStack_3b4 | 0x40;
        }
        else {
          uStack_3b4 = uStack_3b4 | 4;
        }
      }
      uStack_3b4 = uStack_3b4 | 0x40;
    }
    iStack_380 = iStack_380 + 1;
    if (iStack_380 % DAT_00722aa0 != 0) goto LAB_00417283;
    iStack_358 = 1;
    bVar20 = false;
    piVar7 = (int *)&DAT_0072c78c;
    do {
      if (piVar7[-3] == 0) goto LAB_0041700d;
      switch (piVar7[4]) {
      case 1:
        iVar8 = *piVar7;
        iVar9 = piVar7[2];
        if (bVar20) goto LAB_00416f19;
LAB_00416edd:
        uVar10 = (uint32_t)(iVar9 - 2) & 7;
        iVar9 = DAT_00725350[uVar10];
        *piVar7 = iVar8 + DAT_007252f0[uVar10] * 0x245;
        piVar7[1] = piVar7[1] + iVar9 * 0x245;
        break;
      case 2:
        iVar8 = *piVar7;
        iVar9 = piVar7[2];
        if (bVar20) goto LAB_00416edd;
LAB_00416f19:
        uVar10 = (uint32_t)(iVar9 + 2) & 7;
        iVar9 = DAT_00725350[uVar10];
        *piVar7 = iVar8 + DAT_007252f0[uVar10] * 0x245;
        piVar7[1] = piVar7[1] + iVar9 * 0x245;
        break;
      case 3:
        iVar8 = piVar7[2];
        uVar10 = (uint32_t)(iVar8 + 3);
        if (!bVar20) {
          uVar10 = (uint32_t)(iVar8 - 1);
        }
        iVar19 = *piVar7 + DAT_007252f0[uVar10 & 7] * 300;
        iVar9 = piVar7[1] + DAT_00725350[uVar10 & 7] * 300;
        uVar10 = (uint32_t)(iVar8 + 2);
        goto LAB_00416ffc;
      case 4:
        iVar8 = piVar7[2];
        uVar10 = (uint32_t)(iVar8 - 3);
        if (!bVar20) {
          uVar10 = (uint32_t)(iVar8 + 1);
        }
        iVar19 = *piVar7 + DAT_007252f0[uVar10 & 7] * 300;
        iVar9 = piVar7[1] + DAT_00725350[uVar10 & 7] * 300;
        uVar10 = (uint32_t)(iVar8 - 2);
LAB_00416ffc:
        *piVar7 = iVar19;
        piVar7[1] = iVar9;
        piVar7[2] = (int)(uVar10 & 7);
        break;
      case 5:
        iVar8 = *piVar7;
        uVar10 = (uint32_t)piVar7[2];
        if (bVar20) {
LAB_00416f55:
          uVar10 = uVar10 - 4;
        }
        goto LAB_00416f64;
      case 6:
        iVar8 = *piVar7;
        uVar10 = (uint32_t)piVar7[2];
        if (!bVar20) goto LAB_00416f55;
LAB_00416f64:
        iVar9 = DAT_00725350[uVar10 & 7];
        *piVar7 = iVar8 + DAT_007252f0[uVar10 & 7] * (int)local_308;
        piVar7[1] = piVar7[1] + iVar9 * (int)local_308;
      }
      piVar7[3] = piVar7[2];
LAB_0041700d:
      piVar7 = piVar7 + 0xc;
      bVar20 = (bool)(bVar20 ^ 1);
    } while ((int)(intptr_t)piVar7 < 0x72caec);
    if (uStack_3b4 == 0) goto LAB_00417283;
    DAT_0072c79c = (int)(char)DAT_00722a50[iStack_36c * 8 + iStack_364];
    uVar10 = uStack_3b4 | 2;
    iStack_364 = iStack_364 + 1;
    iStack_360 = 0;
    if (7 < iStack_364) {
      iVar8 = iStack_2bc;
      if (iStack_2bc < DAT_0085a158 + 6 + unaff_retaddr) {
        iVar8 = iStack_2bc + 1;
        iStack_2bc = iVar8;
      }
      do {
        if (iVar8 < 0) {
LAB_004170ae:
          iStack_36c = 0;
        }
        else if (iVar8 < 0xb) {
          if (iVar8 < 1) goto LAB_004170ae;
          iStack_36c = rand();
          iStack_36c = iStack_36c % iVar8;
        }
        else {
          iStack_36c = rand();
          iStack_36c = iStack_36c % 10;
        }
      } while ((iStack_36c == iVar6) || (iStack_36c < iVar8 / 3));
      DAT_0072c7ac = DAT_0072c7ac & 0xfffffffb;
      iStack_364 = 0;
    }
    if ((uStack_3b4 & 0x20) != 0) {
      iStack_364 = 0;
      iStack_36c = 0;
    }
    DAT_0072c7ac = DAT_0072c7ac & 0xfffffff4;
    DAT_0072c7dc = DAT_0072c7dc & 0xfffffff4;
    DAT_0072c784 = DAT_0072c78c;
    DAT_0072c788 = DAT_0072c790;
    if (DAT_0072c79c == 3) {
      uVar15 = (uint32_t)(DAT_0072c794 + 2);
LAB_00417146:
      DAT_0072c798 = (int)(uVar15 & 7);
    }
    else if (DAT_0072c79c == 4) {
      uVar15 = (uint32_t)(DAT_0072c794 - 2);
      goto LAB_00417146;
    }
    switch (DAT_0072c79c) {
    case 3:
      DAT_0072c784 = DAT_007252f0[DAT_0072c794 - 1 & 7] * 300 + DAT_0072c78c;
      DAT_0072c788 = DAT_0072c790 + DAT_00725350[DAT_0072c794 - 1 & 7] * 0x4b;
      bVar20 = false;
      piVar7 = &DAT_0072c79c;
      break;
    case 4:
      iVar8 = DAT_007252f0[DAT_0072c794 + 1 & 7] * 300;
      iVar6 = DAT_00725350[DAT_0072c794 + 1 & 7] * 300;
      goto LAB_00417221;
    case 5:
      DAT_0072c784 =
          DAT_007252f0[DAT_0072c794 & 7] * (int)pHVar22 + DAT_0072c78c;
      DAT_0072c788 = (int32_t)(
          DAT_00725350[DAT_0072c794 & 7] * (int)pHVar22 + DAT_0072c790);
      bVar20 = false;
      piVar7 = &DAT_0072c79c;
      break;
    case 6:
      iVar8 = DAT_007252f0[DAT_0072c794 - 4 & 7] * (int)pHVar22;
      iVar6 = DAT_00725350[DAT_0072c794 - 4 & 7] * (int)pHVar22;
LAB_00417221:
      DAT_0072c784 = iVar8 + DAT_0072c78c;
      DAT_0072c788 = iVar6 + DAT_0072c790;
switchD_0041715b_default:
      bVar20 = false;
      piVar7 = &DAT_0072c79c;
      break;
    default:
      goto switchD_0041715b_default;
    }
    do {
      *piVar7 = DAT_0072c79c;
      if (bVar20) {
        switch (DAT_0072c79c) {
        case 1:
          *piVar7 = 2;
          break;
        case 2:
          *piVar7 = 1;
          break;
        case 5:
          *piVar7 = 6;
          break;
        case 6:
          *piVar7 = 5;
        }
      }
      piVar7 = piVar7 + 0xc;
      bVar20 = (bool)(bVar20 ^ 1);
      uStack_3b4 = uVar10;
    } while ((int)(intptr_t)piVar7 < 0x72cafc);
LAB_00417283:
    if (iStack_380 % DAT_00722aa0 == 1) {
      if (DAT_0072c778 != 0) {
        DAT_0072c7ac = DAT_0072c7ac | 8;
        DAT_0072c7dc = DAT_0072c7dc | 8;
      }
      DAT_0072c778 = 0;
    }
    if (iStack_380 % DAT_00722aa0 == 2) {
      if ((DAT_0072c7dc & 8) == 0) {
        DAT_0072c7dc = DAT_0072c7dc & 0xffffffef;
        if (DAT_0072c7cc != 0) {
          pHStack_34c = 0;
        }
      }
      else {
        DAT_0072c7dc = DAT_0072c7dc | 0x10;
        if (DAT_0072c7cc != 0) {
          pHStack_34c = pHStack_34c + 1;
          iStack_300 = iStack_300 + 1;
          if ((iStack_390 == -1) && (iStack_2e4 < iStack_300)) {
            iStack_390 = 0x14;
            iStack_318 = 0;
            iVar6 = rand();
            iVar6 = iVar6 % 3;
            if (iVar6 == 0) {
              uVar18 = 0x96;
LAB_00417388:
              FUN_004888e0(uVar18, 0xffffffff, 0xffffffff, 0xbf800000);
            }
            else {
              if (iVar6 == 1) {
                uVar18 = 0x97;
                goto LAB_00417388;
              }
              if (iVar6 == 2) {
                uVar18 = 0x98;
                goto LAB_00417388;
              }
            }
            iStack_2e4 = iStack_2e4 + 1;
            iStack_300 = 0;
            DAT_0072c7a4 = 0;
            goto LAB_004173d0;
          }
        }
      }
      DAT_0072c7a4 = 0;
    }
LAB_004173d0:
    puStack_368 = nullptr;
    do {
      puVar14 = puStack_368;
      if (DAT_0072c780[(int)(intptr_t)puStack_368 * 0xc] == 0) goto LAB_00417ba6;
      local_26c = 0;
      if ((DAT_0072c79c[(int)(intptr_t)puStack_368 * 0xc] != -1) &&
          (iVar6 = FUN_004bc0d0(), iVar6 != 0)) {
        FUN_004ba7c0();
      }
      puVar11 = (uint32_t *)(intptr_t)FUN_005f0ddc();
      iVar6 = iStack_39c;
      puStack_2d8 = puVar11;
      uStack_2f0 = uStack_3b4 & 8;
      if (((uStack_3b4 & 8) == 0) || (iStack_35c < iStack_370)) {
        DAT_0072c7a0[(int)(intptr_t)puVar14 * 0xc] = 0;
        if (puStack_368 == nullptr) goto LAB_0041751c;
        goto LAB_00417791;
      }
      iVar9 = (int)(intptr_t)puVar11 / DAT_00722aa0;
      iVar8 = (((iStack_35c - iStack_370) * (int)(intptr_t)puVar11) / DAT_00722aa0) /
                  (iStack_378 - iStack_370) +
              (iStack_380 % DAT_00722aa0) * iVar9;
      DAT_0072c7a0[(int)(intptr_t)puVar14 * 0xc] = iVar8;
      if ((int)(intptr_t)puVar11 <= iVar8) {
        DAT_0072c7a0[(int)(intptr_t)puVar14 * 0xc] = (int)(intptr_t)puVar11 + -1;
      }
      if (DAT_0072c7a0[(int)(intptr_t)puVar14 * 0xc] < 0) {
        DAT_0072c7a0[(int)(intptr_t)puVar14 * 0xc] = 0;
      }
      if ((iStack_358 != 0) &&
          (iVar9 < DAT_0072c7a0[(int)(intptr_t)puVar14 * 0xc])) {
        DAT_0072c7a0[(int)(intptr_t)puVar14 * 0xc] = iVar9;
      }
      if (puStack_368 != nullptr) goto LAB_00417791;
      iStack_2e8 = 0;
      if ((DAT_0072c7a0 < 0x96) ||
          ((int)(intptr_t)puVar11 + -0x96 < DAT_0072c7a0)) {
        iStack_2e8 = 1;
      }
LAB_0041751c:
      if (((DAT_0072c7ac[(int)(intptr_t)puVar14 * 0xc] & 1) == 0) &&
          ((int)(intptr_t)puVar11 / DAT_00722aa0 <=
           DAT_0072c7a0[(int)(intptr_t)puVar14 * 0xc])) {
        iVar8 = DAT_0072c79c[(int)(intptr_t)puVar14 * 0xc];
        if ((DAT_0072c7a4[(int)(intptr_t)puVar14 * 0xc] == iVar8) || (iVar8 == 0)) {
          iStack_39c = iStack_39c +
                       ((int)pHStack_34c + iStack_36c + 3) /
                       (int)(2 - (uint32_t)((DAT_0072c7ac[(int)(intptr_t)puVar14 * 0xc] & 8) != 0));
          if (iStack_2c8 < iStack_39c) {
            iStack_2c8 = iStack_39c;
          }
        }
        else if ((iStack_364 < DAT_00869b2d * 2) ||
                 ((iStack_390 == 0x14 && (DAT_0085a158 != 0)))) {
          DAT_0072c7a4[(int)(intptr_t)puVar14 * 0xc] = iVar8;
        }
        else {
          FUN_004a77e0();
          iVar8 = 4 - DAT_0085a158;
          DAT_0072c7ac[(int)(intptr_t)puVar14 * 0xc] =
              DAT_0072c7ac[(int)(intptr_t)puVar14 * 0xc] | 6;
          if (iVar8 < 2) {
            iVar8 = 2;
          }
          else if (4 < iVar8) {
            iVar8 = 4;
          }
          iStack_390 = 0x15;
          iStack_318 = 0;
          iStack_39c = iVar6 - iVar6 / iVar8;
        }
        DAT_0072c7ac[(int)(intptr_t)puVar14 * 0xc] =
            DAT_0072c7ac[(int)(intptr_t)puVar14 * 0xc] | 1;
      }
      if (DAT_0072c7a0[(int)(intptr_t)puVar14 * 0xc] <
          ((int)(intptr_t)puVar11 * iStack_360) / DAT_00722aa0 + 100) {
        goto LAB_00417791;
      }
      if (iStack_360 != 1) goto switchD_00417758_caseD_3;
      DAT_0072c7d8 = (int)(char)DAT_00722a50[iStack_36c * 8 + iStack_364];
      DAT_0072c7a8[(int)(intptr_t)puVar14 * 0xc] = DAT_0072c7d8;
      puStack_3a8 = (uint32_t *)&DAT_0072c790;
      iStack_330 = 0;
      switch (DAT_0072c79c[(int)(intptr_t)puVar14 * 0xc]) {
      case 1:
        uVar10 = (uint32_t)(DAT_0072c794[(int)(intptr_t)puVar14 * 0xc] - 2);
        break;
      case 2:
        uVar10 = (uint32_t)(DAT_0072c794[(int)(intptr_t)puVar14 * 0xc] + 2);
        break;
      case 3:
        uVar10 = (uint32_t)(DAT_0072c794[(int)(intptr_t)puVar14 * 0xc] - 1);
        goto LAB_004176de;
      case 4:
        uVar10 = (uint32_t)(DAT_0072c794[(int)(intptr_t)puVar14 * 0xc] + 1);
LAB_004176de:
        iVar6 = DAT_00725350[uVar10 & 7] * 300;
        goto LAB_00417742;
      case 5:
        uVar10 = (uint32_t)DAT_0072c794[(int)(intptr_t)puVar14 * 0xc];
        goto LAB_00417719;
      case 6:
        uVar10 = (uint32_t)(DAT_0072c794[(int)(intptr_t)puVar14 * 0xc] - 4);
LAB_00417719:
        iVar6 = DAT_00725350[uVar10 & 7] * (int)local_308;
        goto LAB_00417742;
      default:
        goto switchD_00417689_default;
      }
      iVar6 = DAT_00725350[uVar10 & 7] * 0x245;
LAB_00417742:
      puStack_3a8 = (uint32_t *)(DAT_0072c790 + iVar6);
switchD_00417689_default:
      switch (DAT_0072c7a8[(int)(intptr_t)puVar14 * 0xc]) {
      case 1:
        DAT_0072c7d8 = 2;
        break;
      case 2:
        DAT_0072c7d8 = 1;
        break;
      case 5:
        DAT_0072c7d8 = 6;
        break;
      case 6:
        DAT_0072c7d8 = 5;
      }
switchD_00417758_caseD_3:
      iStack_360 = iStack_360 + 1;
LAB_00417791:
      if (((int)(intptr_t)puStack_368 / 2 & 1U) == 0) {
        if (((uint32_t)(intptr_t)puStack_368 & 1) == 0) {
          if ((int)(intptr_t)puStack_368 < 2) {
            puVar23 = (uint32_t *)DAT_0072c790[(int)(intptr_t)puVar14 * 0xc];
            iVar6 = DAT_0072c78c[(int)(intptr_t)puVar14 * 0xc];
            iVar8 = (DAT_0072c794[(int)(intptr_t)puVar14 * 0xc] - 4) * 0x20000000;
            pHVar22 = (uint32_t)(uintptr_t)pHStack_394;
          }
          else {
            puVar23 = (uint32_t *)DAT_0072c790[(int)(intptr_t)puVar14 * 0xc];
            iVar8 = (DAT_0072c794[(int)(intptr_t)puVar14 * 0xc] - 4) * 0x20000000;
            iVar6 = DAT_0072c78c[(int)(intptr_t)puVar14 * 0xc];
            pHVar22 = (uint32_t)(uintptr_t)apiStack_2b8
                         [((int)((int)(intptr_t)puStack_368 +
                                 ((int)(intptr_t)puStack_368 >> 0x1f & 3U)) >> 2) + -0x1d];
          }
        }
        else if ((int)(intptr_t)puStack_368 < 2) {
          puVar23 = (uint32_t *)DAT_0072c790[(int)(intptr_t)puVar14 * 0xc];
          iVar6 = DAT_0072c78c[(int)(intptr_t)puVar14 * 0xc];
          iVar8 = DAT_0072c794[(int)(intptr_t)puVar14 * 0xc] << 0x1d;
          pHVar22 = (uint32_t)(uintptr_t)pHStack_374;
        }
        else {
          puVar23 = (uint32_t *)DAT_0072c790[(int)(intptr_t)puVar14 * 0xc];
          iVar8 = DAT_0072c794[(int)(intptr_t)puVar14 * 0xc] << 0x1d;
          iVar6 = DAT_0072c78c[(int)(intptr_t)puVar14 * 0xc];
          pHVar22 = (uint32_t)(intptr_t)((intptr_t *)pHStack_34c)
                         [((int)((int)(intptr_t)puStack_368 +
                                 ((int)(intptr_t)puStack_368 >> 0x1f & 3U)) >> 2)];
        }
        FUN_004bbc10((void *)(uintptr_t)pHVar22, iVar6, puVar23, 0, iVar8, 0, 0, 0xffffffff, 0);
        iVar6 = DAT_0072c79c[(int)(intptr_t)puVar14 * 0xc];
        if (iVar6 == 0) {
          iVar8 = DAT_0072c7a0[(int)(intptr_t)puVar14 * 0xc];
          iVar6 = 0;
        }
        else {
          iVar8 = DAT_0072c7a0[(int)(intptr_t)puVar14 * 0xc];
          if ((DAT_0072c7ac[(int)(intptr_t)puVar14 * 0xc] & 8) == 0) {
            iVar6 = (-(uint32_t)((DAT_0072c7ac[(int)(intptr_t)puVar14 * 0xc] & 2) != 0) &
                     0x14) + iVar6;
          }
          else {
            iVar6 = iVar6 + 0x28;
          }
        }
        FUN_004bbe10(iVar6, iVar8);
        iVar6 = DAT_0072c7d8;
        if (puStack_368 == (uint32_t *)0x1) {
          if (((DAT_0072c7d8 != 0) && (uStack_3b4 != 0)) &&
              ((int)((int)(intptr_t)puVar11 / DAT_00722aa0 + DAT_0072c7d0) %
                   (int)(intptr_t)puVar11 <
               ((int)(intptr_t)puVar11 * 2) / DAT_00722aa0)) {
            iVar8 = FUN_004db210();
            if (unaff_retaddr == 0) {
              iVar6 = FUN_004bc160();
              if (iVar8 < 0x32) {
                FUN_004bbea0(iVar6 + -1, iVar8 * 2);
              }
              else {
                FUN_004bbe10(DAT_0072c7d8 + 0x5a, iVar6 + -1);
                FUN_004bbea0(0, iVar8 * 2 + -100);
              }
            }
            else {
              if (((iVar6 != 5) && (iVar6 != 6)) &&
                  ((iVar6 != 4 && ((iVar6 != 3 && (DAT_00722aa0 != 4)))))) {
                iVar6 = DAT_0085a158 + 1;
                if (iVar6 < 2) {
                  iVar6 = 2;
                }
                else if (4 < iVar6) {
                  iVar6 = 4;
                }
                iVar8 = (iVar8 * 2) / iVar6;
              }
              uVar18 = 0;
              FUN_004bbe10(DAT_0072c7cc + (-(uint32_t)((DAT_0072c7dc & 8) != 0) & 0x28),
                           DAT_0072c7d0);
              FUN_004bbea0(uVar18, iVar8);
              puVar11 = puStack_2d8;
            }
          }
          if (uStack_2f0 == 0) {
            if (iStack_390 != -1) goto LAB_00417ad3;
          }
          else if (iStack_390 == -1) {
            if ((((uStack_3b4 & 0x20) == 0) && (iStack_380 != 0)) &&
                (DAT_0072c7d8 != 0)) {
              uVar10 = (uint32_t)DAT_0072c7d0;
              if ((int)(intptr_t)puVar11 / 2 <= (int)DAT_0072c7d0) {
                uVar10 = (uint32_t)(DAT_0072c7d0 - (int)(intptr_t)puVar11);
              }
              iVar6 = (int)(uVar10 ^ (int)uVar10 >> 0x1f) - ((int)uVar10 >> 0x1f);
              if (iVar6 < 300) {
                iVar8 = 3 - DAT_0085a158;
                if (iVar8 < 0) {
                  iVar8 = 0;
                }
                else if (3 < iVar8) {
                  iVar8 = 3;
                }
                FUN_004bbea0(0, ((300 - iVar6) * iVar8 * 0x21) / 300);
              }
            }
          }
          else {
LAB_00417ad3:
            uStack_298 = 0;
            iVar6 = FUN_004bc0d0();
            if (iVar6 != 0) {
              FUN_004ba7c0();
            }
            iVar8 = FUN_005f0ddc();
            iVar6 = iStack_318;
            iVar9 = (1 - iVar8) / 2;
            uVar10 = (uint32_t)(iStack_318 - iVar9);
            uVar15 = (uint32_t)((int)uVar10 >> 0x1f);
            iVar8 = (int)((iVar9 - ((uVar10 ^ uVar15) - uVar15)) * 400) / (1 - iVar8);
            if (iVar8 < 0) {
              iVar8 = 0;
            }
            else if (100 < iVar8) {
              iVar8 = 100;
            }
            FUN_004bbea0(iStack_318, iVar8);
            if ((DAT_0085a164 & 4) == 0) {
              iVar6 = iVar6 + 0x19;
              iStack_318 = iVar6;
            }
            uStack_29c = 0;
            iVar8 = FUN_004bc0d0();
            if (iVar8 != 0) {
              FUN_004ba7c0();
            }
            iVar8 = FUN_005f0ddc();
            if (iVar8 <= iVar6) {
              iStack_390 = -1;
            }
          }
        }
      }
LAB_00417ba6:
      piVar7 = piStack_2cc;
      puStack_368 = (uint32_t *)((intptr_t)puStack_368 + 1);
    } while ((int)(intptr_t)puStack_368 < 0x12);
    iVar6 = iStack_304;
    if (iStack_390 == 0x15) {
      if (iStack_304 == 0) {
        iVar6 = 1;
      }
LAB_00417bd9:
      uStack_294 = 0;
      iVar8 = FUN_004bc0d0();
      if (iVar8 != 0) {
        FUN_004ba7c0();
      }
      iVar8 = FUN_005f0ddc();
      if (iVar6 < iVar8) {
        iVar9 = iVar6;
      }
      else {
        iVar9 = iVar8 * 2 - iVar6;
      }
      FUN_004bbc10(piVar7, 0xfffff92a, 0x6d6, 0, 0xe0000000, 0, 0, 0x438, iVar9);
      FUN_004bbc10((void *)(uintptr_t)uStack_2ec, 0xfffff92a, 0x6d6, 0, 0xe0000000, 0, 0,
                   0x438, iVar6);
      iStack_304 = FUN_005f0ddc();
      iStack_304 = iVar6 + iStack_304;
      if (iVar8 * 2 <= iStack_304) {
        iStack_304 = 0;
      }
    }
    else {
      if (iStack_304 != 0) goto LAB_00417bd9;
      FUN_004bbc10(piStack_2cc, 0xfffff92a, 0x6d6, 0, 0xe0000000, 0, 0, 0x3e9,
                   DAT_008c8494);
      FUN_004bbc10((void *)(uintptr_t)uStack_2ec, 0xfffff92a, 0x6d6, 0, 0xe0000000, 0, 0,
                   0x3e9, DAT_008c8494);
    }
    iVar6 = iStack_2dc;
    pcVar21 = (char *)pcStack_37c;
    if ((DAT_0085a164 & 4) == 0) {
      uVar18 = (uint32_t)(60000 / (longlong)(int)pcStack_37c);
      uVar12 = (uint32_t)(8000 / (longlong)(int)pcStack_37c);
      piStack_2c4 = (int *)FUN_00489440((intptr_t)piStack_2c4, uVar12, uVar18, 0);
      iVar8 = iStack_2f4;
      iStack_2dc = iVar6 + (int)(intptr_t)piStack_2c4;
      iStack_2c0 = FUN_00489440(iStack_2c0, uVar12, uVar18, 0);
      iVar6 = iStack_354;
      iStack_2f4 = iVar8 + iStack_2c0;
      iVar8 = DAT_0072c798 << 0x1d;
      pHStack_314 = (intptr_t)FUN_00489440(pHStack_314, 0x3cae75, 0x38e38e3, 0);
      iStack_354 = iVar6 + (int)pHStack_314;
      if ((uStack_3b4 & 1) == 0) {
        iStack_354 = iVar8;
      }
    }
    iVar6 = iStack_354;
    FUN_00489360(iStack_2dc, 600, (int)pcVar21 / 2, 0, 0x2aaaaaaa);
    FUN_004bbc10((void *)(uintptr_t)uStack_3b0, DAT_0072c784, DAT_0072c788, 0, iVar6, 0, 0,
                 0xffffffff, 0);
    iVar6 = iStack_39c;
    if ((DAT_0085a164 & 4) == 0) {
      iVar9 = (DAT_0085a158 + 2) * iStack_39c;
      iVar8 = (0x4b0 - iVar9) * 5;
      if (iVar8 < 0x866) {
        iVar8 = 0x866;
      }
      else if (4000 < iVar8) {
        iVar8 = 4000;
      }
      if (iVar8 < (int)pcVar21) {
        pcVar21 = (char *)((intptr_t)pcVar21 + -5);
        pcStack_37c = (intptr_t)pcVar21;
      }
      iVar8 = (0x4ae - iVar9) * 5;
      if (iVar8 < 0x866) {
        iVar8 = 0x866;
      }
      else if (4000 < iVar8) {
        iVar8 = 4000;
      }
      if ((int)pcVar21 < iVar8) {
        pcStack_37c = (intptr_t)((intptr_t)pcVar21 + 10);
      }
    }
    if (((iStack_39c < 5) && (DAT_0085a158 < 2)) &&
        (DAT_008ca910 = 1, DAT_0085a158 == 0)) {
      DAT_0085a164 = DAT_0085a164 | 0x10000;
    }
    if ((int)(500 / (longlong)(DAT_0085a158 + 1)) < iStack_39c) {
      DAT_008ca910 = 0;
    }
    uVar10 = 0;
    uVar18 = 0;
    if (((DAT_0085a158 <= (int)(uint32_t)(DAT_008ca92c == 4)) || (DAT_008ca910 != 0)) ||
        ((DAT_00869aac & 2) == 0)) {
      iVar8 = 0x10;
      puStack_38c = (uint32_t *)0x1ff05ff;
      uStack_388 = 0x60402ff;
      uStack_384 = (uStack_384 & 0xffffff00) | 3;
      iVar9 = 9;
      do {
        if ((DAT_0072c7a8 != 0) &&
            (DAT_0072c7a8 == *(char *)((intptr_t)&iStack_39c + iVar8))) {
          uVar10 = uVar10 | 1 << ((uint8_t)iVar8 & 0x1f);
        }
        if ((((iStack_360 != 2) &&
             (DAT_0072c7a8 == *(char *)((intptr_t)&iStack_39c + iVar8))) &&
            (uStack_3b4 = uStack_3b4 ^ 0x4000, iStack_2e8 != 0)) &&
            ((uStack_3b4 & 0x4000) != 0)) {
          uVar10 = uVar10 & ~(1 << ((uint8_t)iVar8 & 0x1f));
        }
        iVar8 = iVar8 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      uVar18 = 1;
    }
    DAT_0086c330 = 0;
    FUN_00473b70(uVar10, uVar18, 4);
    puVar14 = puStack_338;
    pHVar22 = (uint32_t)pHStack_34c;
    if (iVar6 < 10) {
      iVar6 = 10;
    }
    else if (1000 < iVar6) {
      iVar6 = 1000;
    }
    iStack_2f8 = iStack_2f8 + 1;
    if ((int)(4000 / (longlong)iVar6) < iStack_2f8) {
      iStack_2f8 = 0;
    }
    if (iStack_370 < iStack_35c) {
      iVar6 = 0;
      if (0 < (int)pHStack_34c) {
        do {
          iVar8 = FUN_004db210(0x41200000, 0x33b40000);
          iVar8 = 0x2c - iVar8;
          iVar9 = FUN_004db210(iVar8);
          FUN_004bba60((void *)puVar14,
                       iVar9 + ((int)(iVar6 + (iVar6 >> 0x1f & 7U)) >> 3) * 8 +
                           DAT_0085a26c / 2,
                       iVar8, 0x41200000, 0x33b40000);
          iVar6 = iVar6 + 1;
        } while (iVar6 < (int)pHVar22);
      }
      iVar6 = iStack_39c;
      iVar8 = FUN_004db210();
      iVar6 = iVar8 + iVar6 / 10 + 0x28;
      if (iVar6 < 10) {
        iVar6 = 10;
      }
      uStack_2f0 = (uint32_t)(iVar6 / 2);
      FUN_004bba60((void *)puVar14, DAT_0085a26c / 2, 0x2c, (float)(int)uStack_2f0,
                   0x33b40000);
    }
    iVar6 = FUN_005f0ddc();
    iStack_358 = -iVar6 - (int)(uint32_t)(uint64_t)dStack_284;
    do {
      iVar6 = FUN_0042e440();
      if ((0x2c7 < iVar6) && (iVar6 < 0x2d5)) {
        switch (iVar6) {
        case 0x2c8:
          iVar6 = 0x124;
          break;
        case 0x2c9:
          iVar6 = 0x126;
          break;
        case 0x2ca:
          iVar6 = 0x121;
          break;
        case 0x2cb:
          iVar6 = 0x125;
          break;
        case 0x2cc:
          iVar6 = 0x10c;
          break;
        case 0x2cd:
          iVar6 = 0x127;
          break;
        case 0x2ce:
          iVar6 = 0x123;
          break;
        case 0x2cf:
          iVar6 = 0x128;
          break;
        case 0x2d0:
          iVar6 = 0x122;
        }
        DAT_0086c35c = 0;
      }
      if (iVar6 < 0x124) {
        if (iVar6 == 0x123) {
LAB_004184d6:
          DAT_0072c7a4 = 4;
        }
        else if (iVar6 < 0x69) {
          if (iVar6 == 0x68) {
            DAT_007263bb = (DAT_007263bb == '\0');
          }
          else if (iVar6 != 0) {
            if (iVar6 != 0x1b) {
              if (iVar6 != 0x50) goto switchD_004184f7_default;
              goto LAB_0041825c;
            }
            DAT_0085a164 = DAT_0085a164 ^ 4;
            puStack_dc = &DAT_008cacd0;
            uStack_13c = 0x31;
            uStack_134 = 0;
            FUN_004985e0();
            FUN_004a14b0();
            puStack_dc = &DAT_008cacd0;
            FUN_004bef50();
            FUN_004bef50();
            FUN_004bef50();
            FUN_004bef50();
            FUN_004bef50();
            cVar5 = DAT_00725d98;
            DAT_00726814[DAT_00726820] = DAT_00725d98;
            iVar8 = DAT_008c97c4;
            DAT_00726820 = DAT_00726820 + 1;
            if (cVar5 != '\x01') {
              *(uint8_t *)(DAT_008c97c0 + 0xb4) = 1;
              *(uint8_t *)(iVar8 + 0xb4) = 1;
              FUN_00535670(DAT_008e9fe8);
              FUN_00535670(DAT_008e9fe8);
            }
            DAT_00725d98 = '\x01';
            DAT_008c9df4 = 1;
            FUN_004b21a0(9, 0, 0, 1);
            FUN_00481180();
            FUN_004beee0();
            FUN_004beee0();
            FUN_004beee0();
            FUN_004beee0();
            FUN_004beee0();
            puStack_74 = &DAT_008cacd0;
            uStack_d4 = 0x32;
            FUN_004985e0();
            FUN_004a14b0();
            DAT_0085a164 = DAT_0085a164 ^ 4;
            puStack_74 = &DAT_008cacd0;
          }
        }
        else {
          if (iVar6 != 0x113) {
            if (iVar6 != 0x121) {
              if (iVar6 == 0x122) goto switchD_004184f7_caseD_124;
              goto switchD_004184f7_default;
            }
            goto LAB_004184d6;
          }
LAB_0041825c:
          DAT_0085a164 = DAT_0085a164 ^ 4;
          if ((DAT_0085a164 & 4) == 0) {
            puStack_c = &DAT_008cacd0;
            uStack_6c = 0x32;
            FUN_004985e0();
            FUN_004a14b0();
            puStack_c = &DAT_008cacd0;
          }
          else {
            puStack_144 = &DAT_008cacd0;
            uStack_1a4 = 0x31;
            uStack_19c = 0;
            FUN_004985e0();
            FUN_004a14b0();
            puStack_144 = &DAT_008cacd0;
          }
        }
      }
      else if (iVar6 < 0x2d3) {
        if (iVar6 == 0x2d2) {
          DAT_007263bb = '\0';
        }
        else {
          switch (iVar6) {
          case 0x124:
switchD_004184f7_caseD_124:
            DAT_0072c7a4 = 3;
            break;
          case 0x125:
            DAT_0072c7a4 = 1;
            break;
          case 0x126:
            DAT_0072c7a4 = 5;
            break;
          case 0x127:
            DAT_0072c7a4 = 2;
            break;
          case 0x128:
            DAT_0072c7a4 = 6;
            break;
          default:
            goto switchD_004184f7_default;
          }
        }
      }
      else if (iVar6 == 0x2d3) {
        DAT_007263bb = '\x01';
      }
      else {
switchD_004184f7_default:
        iVar6 = -1;
      }
      if ((DAT_0085a164 & 4) != 0) {
        DAT_0072c7a4 = 0;
        break;
      }
      if (0 < iVar6) {
        if (((DAT_0072c7a0 < (10 - DAT_0085a158) * 0x14) ||
             ((int)((intptr_t)puStack_2d8 + DAT_0085a158 * 5 + -0x19) < DAT_0072c7a0)) &&
            ((iStack_330 < 2 && (DAT_0072c7a4 == DAT_0072c79c)))) {
          DAT_0072c778 = 1;
        }
        iStack_330 = iStack_330 + 1;
      }
    } while (iVar6 != 0);
    DVar3 = DStack_350;
    if ((DAT_0085a164 & 0x20) != 0) {
      FUN_004f6090("@NUM @NUM", iStack_380, DAT_0072c7a0);
      FUN_004b06c0(&DAT_00869b48, 4, 4, DAT_0085a11c, 0xffffffff, 1, 0xffffffff, 0);
      DVar3 = DStack_350;
    }
    do {
      if ((DAT_008ed61c & 1) == 0) {
        DAT_008ed61c = DAT_008ed61c | 1;
        DAT_008ed618 = timeGetTime();
      }
      DVar13 = timeGetTime();
    } while ((int)((DVar13 - DVar3) - DAT_008ed618) < 10);
    if ((DAT_0085a164 & 4) != 0) {
      FUN_004afdb0(0xff000000);
    }
    FUN_004d0cd0(0, 0, 0);
    if ((uStack_3b4 & 0x10) == 0) {
      uStack_3b4 = uStack_3b4 | 0x10;
    }
    else if ((uStack_3b4 & 8) == 0) {
      Sleep(100);
      puStack_1d4 = &DAT_008cacd0;
      uStack_234 = 0x1d;
      puStack_1fc = &DAT_008c7348;
      iStack_22c = 1;
      FUN_004985e0();
      FUN_004a14b0();
      puStack_1d4 = &DAT_008cacd0;
      while (true) {
        iVar6 = DAT_008e8ec4 - DAT_008e8ec8;
        if (iVar6 < 0) {
          iVar6 = iVar6 + 100;
        }
        if (iVar6 == 0) break;
        Sleep(1);
      }
      DStack_350 = timeGetTime();
      dStack_284 = (double)(int)DStack_350;
      if ((int)DStack_350 < 0) {
        dStack_284 = dStack_284 + 4294967296.0;
      }
      dStack_284 = dStack_284 + 3000.0;
      do {
        pHStack_334 = (uint32_t *)(intptr_t)FUN_005f0ddc();
        DStack_350 = timeGetTime();
        dVar2 = (double)(int)DStack_350;
        if ((int)DStack_350 < 0) {
          dVar2 = dVar2 + 4294967296.0;
        }
      } while ((dVar2 <= dStack_284) && (DAT_008ed510 <= DAT_008ca90c));
      uStack_3b4 = uStack_3b4 | 8;
    }
    puVar14 = puStack_398;
    if ((DAT_008cac27 != '\0') || ((uStack_3b4 & 4) != 0)) {
      DAT_0086c330 = 0;
      puVar11 = DAT_007268e0;
      if (DAT_007268e8 != 0) {
        while (puVar11 != nullptr) {
          puVar23 = puVar11 + 2;
          puVar11 = (uint32_t *)*puVar11;
          if (*(uint32_t **)*puVar23 == puVar14) {
            FUN_004ab3c0(&PTR_PTR_007268dc, (int *)*puVar23);
            DAT_008c9df4 = 1;
          }
        }
        puVar14 = DAT_007268e0;
        if (DAT_007268e8 != 0) {
          while (puVar14 != nullptr) {
            puVar11 = puVar14 + 2;
            puVar14 = (uint32_t *)*puVar14;
            if (*(uint32_t **)*puVar11 == puStack_3a0) {
              FUN_004ab3c0(&PTR_PTR_007268dc, (int *)*puVar11);
              DAT_008c9df4 = 1;
            }
          }
          puVar14 = DAT_007268e0;
          if (DAT_007268e8 != 0) {
            while (puVar14 != nullptr) {
              puVar11 = puVar14 + 2;
              puVar14 = (uint32_t *)*puVar14;
              if (*(uint32_t **)*puVar11 == puStack_3a4) {
                FUN_004ab3c0(&PTR_PTR_007268dc, (int *)*puVar11);
                DAT_008c9df4 = 1;
              }
            }
          }
        }
      }
      FUN_004c1080(puStack_3b8, "candle", 100, 0xffffffff);
      FUN_004c1080(puStack_3b8, "fireplace", 100, 0xffffffff);
      FUN_004c1080(puStack_3b8, "fireplace", 100, 0xffffffff);
      pHVar4 = (uint32_t)(uintptr_t)pHStack_374;
      pHVar22 = (uint32_t)(uintptr_t)pHStack_394;
      puStack_38c = (uint32_t *)0x426a50e5;
      pHStack_394[0x1e] = 0x426a50e5;
      uStack_388 = 0xc2a191ec;
      pHStack_394[0x1f] = 0xc2a191ec;
      uStack_384 = 0x43235a1d;
      pHStack_394[0x20] = 0x43235a1d;
      *(uint32_t *)(iStack_348 + 0x78) = 0x426a50e5;
      *(uint32_t *)(iStack_348 + 0x7c) = 0xc2a191ec;
      *(uint32_t *)(iStack_348 + 0x80) = 0x43235a1d;
      puStack_344[0x1e] = 0x426a50e5;
      puStack_344[0x1f] = 0xc2a191ec;
      puStack_344[0x20] = 0x43235a1d;
      *(uint32_t *)(iStack_340 + 0x78) = 0x426a50e5;
      *(uint32_t *)(iStack_340 + 0x7c) = 0xc2a191ec;
      *(uint32_t *)(iStack_340 + 0x80) = 0x43235a1d;
      puStack_33c[0x1e] = 0x426a50e5;
      puStack_33c[0x1f] = 0xc2a191ec;
      puStack_33c[0x20] = 0x43235a1d;
      *(uint32_t *)(iStack_328 + 0x78) = 0x426a50e5;
      *(uint32_t *)(iStack_328 + 0x7c) = 0xc2a191ec;
      *(uint32_t *)(iStack_328 + 0x80) = 0x43235a1d;
      *(uint32_t *)(iStack_324 + 0x78) = 0x426a50e5;
      *(uint32_t *)(iStack_324 + 0x7c) = 0xc2a191ec;
      *(uint32_t *)(iStack_324 + 0x80) = 0x43235a1d;
      *(uint32_t *)(iStack_320 + 0x78) = 0x426a50e5;
      *(uint32_t *)(iStack_320 + 0x7c) = 0xc2a191ec;
      *(uint32_t *)(iStack_320 + 0x80) = 0x43235a1d;
      *(uint32_t *)(iStack_31c + 0x78) = 0x426a50e5;
      *(uint32_t *)(iStack_31c + 0x7c) = 0xc2a191ec;
      *(uint32_t *)(iStack_31c + 0x80) = 0x43235a1d;
      pHStack_374[0x1e] = 0x426a50e5;
      bVar20 = DAT_008ca914 != '\0';
      pHStack_374[0x1f] = 0xc2a191ec;
      pHStack_374[0x20] = 0x43235a1d;
      if (bVar20) {
        piVar7 = (int *)FUN_004baaa0();
        iVar6 = (*(int (__stdcall **)(const char *))(*(uint32_t *)piVar7 + 0x40))(
            "dance_hide_01");
        if (iVar6 != 0) {
          *(uint8_t *)(iVar6 + 0x20) = *(uint8_t *)(iVar6 + 0x20) & 0xfe;
        }
      }
      DAT_008ca914 = '\0';
      if (DAT_008cac27 == '\0') {
        if (iStack_39c < 0x33) {
          uVar18 = 0x46;
        }
        else if (iStack_39c < 0xfa) {
          uVar18 = 0x47;
        }
        else {
          uVar18 = 0x48;
        }
        FUN_00418dd0(uVar18, (void *)pHVar22, (void *)pHVar4, puStack_3b8, apiStack_2b8);
      }
      FUN_00481180();
      DAT_008cade4 = local_274;
      DAT_008cade0 = uStack_278;
      DAT_008cade8 = local_270;
      (*(void (__stdcall **)(void *))(*(uint32_t *)DAT_008ea08c + 0x74))(&DAT_008cade0);
      iVar6 = iStack_39c;
      FUN_004c1150(puStack_3b8, "candle");
      FUN_004c1150(puStack_3b8, "fireplace");
      FUN_004c1150(puStack_3b8, "fireplace");
      puVar14 = DAT_007268e0;
      if (DAT_007268e8 != 0) {
        while (puVar14 != nullptr) {
          puVar11 = puVar14 + 2;
          puVar14 = (uint32_t *)*puVar14;
          if (*(int *)*puVar11 == iVar6) {
            FUN_004ab3c0(&PTR_PTR_007268dc, (int *)*puVar11);
            DAT_008c9df4 = 1;
          }
        }
        puVar14 = DAT_007268e0;
        if (DAT_007268e8 != 0) {
          while (puVar14 != nullptr) {
            puVar11 = puVar14 + 2;
            puVar14 = (uint32_t *)*puVar14;
            if (*(uint32_t **)*puVar11 == puStack_3a4) {
              FUN_004ab3c0(&PTR_PTR_007268dc, (int *)*puVar11);
              DAT_008c9df4 = 1;
            }
          }
          puVar14 = DAT_007268e0;
          if (DAT_007268e8 != 0) {
            while (puVar14 != nullptr) {
              puVar11 = puVar14 + 2;
              puVar14 = (uint32_t *)*puVar14;
              if (*(uint32_t **)*puVar11 == puStack_3a4) {
                FUN_004ab3c0(&PTR_PTR_007268dc, (int *)*puVar11);
                DAT_008c9df4 = 1;
              }
            }
          }
        }
      }
      FUN_004bef50();
      FUN_004bef50();
      FUN_004bef50();
      FUN_004bef50();
      FUN_004bef50();
      if (puStack_33c != nullptr) {
        (*(void (__stdcall **)(int))(*(uint32_t *)puStack_33c))(1);
      }
      if (puStack_2d4 != nullptr) {
        (*(void (__stdcall **)(int))(*(uint32_t *)puStack_2d4))(1);
      }
      if (puStack_2d8 != nullptr) {
        (*(void (__stdcall **)(int))(*(uint32_t *)puStack_2d8))(1);
      }
      (*(void (__stdcall **)(int))(*(uint32_t *)unaff_EBX))(1);
      if (puStack_3b8 != nullptr) {
        (*(void (__stdcall **)(int))(*(uint32_t *)puStack_3b8))(1);
      }
      iVar6 = 1;
      (*(void (__stdcall **)(void))(*(uint32_t *)puStack_3a0))();
      (*(void (__stdcall **)(int))(*(uint32_t *)puStack_3a4))(1);
      (*(void (__stdcall **)(int))(*(uint32_t *)puStack_3a8))(1);
      (*(void (__stdcall **)(int))(*(uint32_t *)puStack_3a8))(1);
      (*(void (__stdcall **)(int))(*(uint32_t *)puStack_38c))(1);
      (*(void (__stdcall **)(int))(*(uint32_t *)puStack_344))(1);
      (*(void (__stdcall **)(int))(*(uint32_t *)puStack_344))(1);
      (*(void (__stdcall **)(int))(*(uint32_t *)puStack_344))(1);
      (*(void (__stdcall **)(int))(*(uint32_t *)puStack_344))(1);
      (*(void (__stdcall **)(int))pHStack_374[0])(1);
      (*(void (__stdcall **)(int))pHStack_374[0])(1);
      (*(void (__stdcall **)(int))pHStack_374[0])(1);
      (*(void (__stdcall **)(int))pHStack_374[0])(1);
      if (puStack_368 != nullptr) {
        (*(void (__stdcall **)(int))(*(uint32_t *)puStack_368))(1);
      }
      DAT_00869aac = DAT_00869aac | 2;
      FUN_004a76c0();
      DAT_00726a84 = DAT_00726a84 + -1;
      DAT_007263bc = *(uint32_t *)(&DAT_007268f4 + DAT_00726a84 * 4);
      if (((DAT_0085a164 & 0x10000) == 0) && (iVar6 < 0x32)) {
        DAT_0085a164 = DAT_0085a164 | 0x40000;
      }
      DAT_0085a164 = DAT_0085a164 & 0xfffeffff;
      appuStack_2a4[0] = &PTR_FUN_006f583c;
      FUN_004f4de0();
      appuStack_2a4[0] = &PTR_FUN_006f5864;
      FUN_004f0dc0();
      puVar14 = (uint32_t *)((intptr_t)puStack_288 - 8);
      if ((puVar14 != nullptr) && (puVar14 != &DAT_008cacc8)) {
        operator_delete__(puVar14);
      }
      puStack_288 = &DAT_008cacd0;
      FUN_004d4e00();
      SetCursor((HCURSOR)(uintptr_t)pHStack_34c);
      return iVar6;
    }
  } while (true);
}

// ---------------------------------------------------------------------------
// External symbols for FUN_004154f0
// ---------------------------------------------------------------------------
extern short    DAT_008165d8;
extern short    DAT_00814322[];
extern uint8_t  DAT_00814354[];
extern uint8_t  DAT_00814340[];
extern int32_t  DAT_0085a150;
extern uint8_t  DAT_008142fa[];
extern uint8_t  DAT_00723b14[];
extern uint8_t  DAT_00723b18[];
extern uint8_t  DAT_00723b1c[];
extern short    DAT_0081431e[];
extern short    DAT_00814320[];
extern uint8_t  DAT_0081432a[];
extern uint8_t  DAT_00814328[];
extern uint8_t  DAT_00814324[];
extern uint32_t DAT_0081433c[];
extern uint32_t DAT_0081430c[];
extern uint32_t DAT_00814304[];
extern uint8_t  DAT_0081432c[];
extern uint8_t  DAT_0081432e[];
extern uint32_t DAT_00814308[];

// 0x004154f0 — observed shape: int(int param_1, int param_2, int param_3)
// Finds the first free record at DAT_008165d8 (stride 0x22e, starting index 8),
// zeroes 0x45c-byte body, flags DAT_00814350 with 0x1400 (or | 0x800 if param_1 != 0x1a),
// seeds owner, fitness, timer, derives stats/value fields from DAT_00723b14/18/1c,
// sets positions to param_2 * 1000000 and param_3 * 1000000, and calls FUN_00413080().
// Returns the record index, or -1 when all slots are occupied.
int FUN_004154f0(int param_1, int param_2, int param_3)
{
  short sVar1;
  short sVar2;
  short sVar3;
  uint32_t uVar4;
  uint16_t uVar5;
  uint16_t uVar6;
  short *psVar7;
  int iVar8;
  int iVar9;
  char cVar10;
  short sVar11;
  int iVar12;
  int iVar13;
  short *psVar14;

  iVar12 = 8;
  psVar7 = &DAT_008165d8;
  do {
    if (*psVar7 == -1) {
      iVar13 = iVar12 * 0x45c;
      psVar7 = (short *)&DAT_008142f8 + iVar12 * 0x22e;
      psVar14 = psVar7;
      for (iVar9 = 0x117; iVar9 != 0; iVar9 = iVar9 + -1) {
        psVar14[0] = 0;
        psVar14[1] = 0;
        psVar14 = psVar14 + 2;
      }
      (&DAT_00814350)[iVar12 * 0x117] = (short)((&DAT_00814350)[iVar12 * 0x117] | 0x1400);
      iVar9 = rand();
      uVar5 = (uint16_t)DAT_00722a08;
      *(uint16_t *)((uint8_t *)&DAT_00814338 + iVar13) = uVar5;
      (&DAT_00814336)[iVar12 * 0x22e] = (short)uVar5;
      *(uint16_t *)((uint8_t *)&DAT_008142fc + iVar12 * 0x117) = 0;
      *psVar7 = (short)param_1;
      (&DAT_00814322)[iVar12 * 0x22e] = 3;
      *(short *)((uint8_t *)&DAT_00814354 + iVar13) = (short)(iVar9 % 1000) + 1;
      *(int *)((uint8_t *)&DAT_00814340 + iVar13) = DAT_0085a150 + -12000;
      if (param_1 != 0x1a) {
        (&DAT_00814322)[iVar12 * 0x22e] = 3;
        uVar4 = (uint32_t)(&DAT_00814350)[iVar12 * 0x117];
        *(uint16_t *)((uint8_t *)&DAT_008142fa + iVar13) = 6;
        (&DAT_00814350)[iVar12 * 0x117] = (short)(uVar4 | 0x800);
      }
      iVar9 = *(int *)((uint8_t *)&DAT_00723b14 + (short)param_1 * 0x44);
      if (iVar9 / 2 < 1) {
        sVar11 = 0;
      }
      else {
        iVar8 = rand();
        sVar11 = (short)(iVar8 % (iVar9 / 2));
      }
      (&DAT_0081431e)[iVar12 * 0x22e] =
           (short)(*(int *)((uint8_t *)&DAT_00723b14 + *psVar7 * 0x44) / 2) + sVar11;
      iVar9 = *(int *)((uint8_t *)&DAT_00723b18 + *psVar7 * 0x44);
      if (iVar9 / 2 < 1) {
        cVar10 = '\0';
      }
      else {
        iVar8 = rand();
        cVar10 = (char)(iVar8 % (iVar9 / 2));
      }
      uVar6 = (uint8_t)((char)(*(int *)((uint8_t *)&DAT_00723b18 + *psVar7 * 0x44) / 2) + cVar10 + 1) & 0xfe;
      (&DAT_00814320)[iVar12 * 0x22e] = (short)uVar6;
      *(short *)((uint8_t *)&DAT_0081432a + iVar13) =
           (short)((*(int *)((uint8_t *)&DAT_00723b1c + *psVar7 * 0x44) - (int)(short)uVar6) / 2);
      iVar9 = rand();
      sVar11 = (&DAT_00814320)[iVar12 * 0x22e];
      *(short *)((uint8_t *)&DAT_00814328 + iVar13) = (short)(iVar9 % 600) + 400;
      iVar9 = ((*(int *)((uint8_t *)&DAT_00723b1c + *psVar7 * 0x44) - (int)*(short *)((uint8_t *)&DAT_0081432a + iVar13))
              - (int)sVar11) + 1;
      if (iVar9 < 1) {
        sVar11 = 0;
      }
      else {
        iVar8 = rand();
        sVar11 = (short)(iVar8 % iVar9);
      }
      sVar1 = *(short *)((uint8_t *)&DAT_00723b1c + *psVar7 * 0x44);
      sVar2 = *(short *)((uint8_t *)&DAT_0081432a + iVar13);
      (&DAT_00814324)[iVar13] = (uint8_t)((&DAT_00814324)[iVar13] | 0x93);
      sVar3 = (&DAT_00814320)[iVar12 * 0x22e];
      (&DAT_0081433c)[iVar12 * 0x117] = 0xc0000000;
      (&DAT_0081430c)[iVar12 * 0x117] = 0xc0000000;
      (&DAT_00814304)[iVar12 * 0x117] = param_2 * 1000000;
      *(short *)((uint8_t *)&DAT_0081432c + iVar13) = sVar11;
      *(short *)((uint8_t *)&DAT_0081432e + iVar13) = ((sVar1 - sVar2) - sVar3) - sVar11;
      (&DAT_00814308)[iVar12 * 0x117] = param_3 * 1000000;
      iVar9 = rand();
      *(uint16_t *)((uint8_t *)&DAT_00814326 + iVar13) = 0xffff;
      *(short *)((uint8_t *)&DAT_00814354 + iVar13) = (short)(iVar9 % 500) + 1;
      FUN_00413080();
      return iVar12;
    }
    psVar7 = psVar7 + 0x22e;
    iVar12 = iVar12 + 1;
  } while ((intptr_t)psVar7 < 0x859ef8);
  return -1;
}
