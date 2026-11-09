// Mass 0011 reconstructions (UNVERIFIED; source-candidate).
// Clean-room transcription of the Ghidra 12.2 listings in
// analysis/pseudocode/functions/0x*.c for addresses 0x435140, 0x439fe0,
// 0x43a240, 0x43a350, 0x43a800, 0x43a940, 0x43a970, 0x436ac0,
// 0x43a420, 0x43aa10, 0x43ca20, 0x43fd70, 0x438e30, 0x433cf0, 0x435260,
// 0x436c30, 0x43b8e0, 0x43cde0, 0x43e550, 0x43ffc0.
// No compiler/PASS claim. Register receivers are explicit parameters, never
// `this`. Field offsets, constants, call order and control flow follow the
// listings; non-contiguous listings are transcribed per reached block.

#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---------------------------------------------------------------------------
// Helpers referenced by the listings below (declared, not defined here).
// ---------------------------------------------------------------------------
extern void     FUN_004e2e40(void);
extern uint32_t FUN_00500600(void);
extern void     FUN_004add70(uint32_t);
extern void     FUN_004e8a10(uint32_t);
extern void     FUN_004e8b60(uint32_t);
extern void     FUN_004e7950(uint32_t, uint32_t, uint32_t);
extern void     FUN_004e9740(void);
extern void     FUN_0043a350(void);
extern void     FUN_00502cd0(int, int, int, int, void *, void *, void *,
                              int, int, int);
extern char     FUN_00502e10(int, int, int, int, int, int);
extern void     FUN_00502c80(void);
extern uint32_t FUN_00431910(void);
extern void     FUN_004a86a0(void);
extern void     FUN_00488840(const char *, int);
extern void     FUN_004985e0(void);
extern void     FUN_004a14b0(void);
extern uint32_t FUN_00533c78(uint32_t);
extern uint32_t FUN_004a96a0(void);
extern void     FUN_004af990(void);
extern void     FUN_004a88d0(void);
extern void     FUN_004a9770(void);
extern void     operator_delete(void *);
extern char     FUN_0043a420(int, int, int *, int *);
extern int      rand(void);
extern void     FUN_004b06c0(uint32_t, uint32_t, uint32_t, uint32_t,
                             uint32_t, int, uint32_t, int);

// Code labels used only as callback addresses by FUN_00502cd0.
extern void LAB_0043a3e0(void);
extern void LAB_0043a3b0(void);
extern void LAB_00439f50(void);
extern void LAB_00439f10(void);

// ---------------------------------------------------------------------------
// Globals referenced by the listings below.
// ---------------------------------------------------------------------------
extern uint8_t  DAT_0086c560;
extern int8_t   DAT_0085a164;
extern int8_t   DAT_0086c458;
extern uint32_t *DAT_008e9fe4;
extern uint32_t DAT_008cabd4;
extern uint32_t DAT_008c9df4;
extern uint32_t DAT_0072cd78;
extern uint32_t DAT_0085a7b0;
extern uint32_t DAT_0085a7d0;
extern int32_t  DAT_008cac38;
extern int      iRam00000020;
extern uint32_t DAT_008ecd78;
extern uint8_t  DAT_008e8eff;
extern void    *DAT_008ca984;
extern uint32_t DAT_007268f4;
extern int32_t  DAT_00726a84;
extern uint32_t DAT_007263bc;
extern uint8_t  DAT_00871978;
extern int32_t  DAT_0085a100;
extern uint32_t DAT_0085a150;
extern uint32_t DAT_00814308;
extern uint32_t DAT_00814304;
extern int      DAT_0086ea8c;
extern uint32_t DAT_0085a11c;
extern uint8_t  DAT_00862d10;
extern uint8_t  DAT_00862d14;
extern uint8_t  DAT_00862d18;
extern uint8_t  DAT_00862d1c;
extern uint8_t  DAT_00862d20;
extern uint8_t  DAT_00862d24;
extern uint8_t  DAT_00862d28;
extern uint8_t  DAT_00862d2c;

// ===========================================================================
// 0x00435140
// ===========================================================================
// 0x00435140 — observed shape
// Resets the pending-frame flag, rebinds the shared state object (refcounted
// handoff from FUN_00500600), marks the scene dirty, reconfigures the render
// object at DAT_0072cd78 (+0x5c = 10, +0x80 = 1), then drains +0x58 entries
// through FUN_004e9740 and leaves DAT_008cac38 = 10.
void FUN_00435140(void) {
    if (DAT_0086c560 == 0) {
        DAT_0086c560 = 0;
        FUN_004e2e40();
    }
    FUN_0043a350();
    DAT_0085a164 = DAT_0086c458;

    uint32_t *puVar2 = reinterpret_cast<uint32_t *>(FUN_00500600());
    uint32_t *puVar1 = DAT_008e9fe4;
    if (DAT_008e9fe4 != puVar2) {
        if (DAT_008e9fe4 != nullptr) {
            int iVar3 = static_cast<int>(puVar1[1]);
            puVar1[1] = static_cast<uint32_t>(iVar3 - 1);
            if (iVar3 - 1 == 0) {
                reinterpret_cast<void (*)(int)>(*reinterpret_cast<void **>(puVar1))(1);
            }
        }
        DAT_008e9fe4 = puVar2;
        if (puVar2 != nullptr) {
            puVar2[1] = puVar2[1] + 1;
        }
    }

    FUN_004add70(DAT_008cabd4);
    DAT_008c9df4 = 1;
    FUN_004e8a10(DAT_0072cd78);

    int iVar3 = static_cast<int>(DAT_0072cd78);
    *reinterpret_cast<uint32_t *>(static_cast<uintptr_t>(iVar3) + 0x5c) = 10;
    *reinterpret_cast<uint8_t *>(static_cast<uintptr_t>(iVar3) + 0x80) = 1;

    if (DAT_0085a164 < 0) {
        FUN_004e8b60(DAT_0072cd78);
        iVar3 = static_cast<int>(DAT_0072cd78);
    }

    FUN_004e7950(static_cast<uint32_t>(iVar3), DAT_0085a7b0, DAT_0085a7d0);

    iVar3 = static_cast<int>(DAT_0072cd78);
    int iVar4 = 0;
    if (*reinterpret_cast<int32_t *>(static_cast<uintptr_t>(DAT_0072cd78) + 0x58) < 1) {
        DAT_008cac38 = 10;
        return;
    }
    do {
        FUN_004e9740();
        iVar4 = iVar4 + 1;
    } while (iVar4 < *reinterpret_cast<int32_t *>(static_cast<uintptr_t>(iVar3) + 0x58));

    DAT_008cac38 = 10;
}

// ===========================================================================
// 0x00439FE0
// ===========================================================================
// 0x00439fe0 — observed shape
// Captures the pressed key pair (in_EAX / unaff_EBX) against param_1 /
// param_2. On a mismatch installs the 0x10 callback set, converts the key
// through FUN_00502e10 and, when a live chain head exists at 0x20, walks it to
// the tail by +0x20 links before returning FUN_00431910's value. Every exit
// runs FUN_00502c80 (callback teardown).
uint32_t FUN_00439fe0(int in_EAX, int unaff_EBX, int param_1, int param_2) {
    if ((unaff_EBX != in_EAX) || (param_1 != param_2)) {
        FUN_00502cd0(0x10, 0, 0, 0,
                     reinterpret_cast<void *>(&LAB_0043a3e0),
                     reinterpret_cast<void *>(&LAB_00439f50),
                     reinterpret_cast<void *>(&LAB_00439f10),
                     0, 0, 0);
        char cVar3 = FUN_00502e10(in_EAX, unaff_EBX, param_1, 0, 0, 0);
        if ((cVar3 != 0) && (iRam00000020 != 0)) {
            int iVar1 = *reinterpret_cast<int *>(static_cast<uintptr_t>(iRam00000020) + 0x20);
            int iVar2 = iRam00000020;
            while (iVar1 != 0) {
                iVar2 = *reinterpret_cast<int *>(static_cast<uintptr_t>(iVar2) + 0x20);
                iVar1 = *reinterpret_cast<int *>(static_cast<uintptr_t>(iVar2) + 0x20);
            }
            uint32_t uVar4 = FUN_00431910();
            FUN_00502c80();
            return uVar4;
        }
    }
    FUN_00502c80();
    return 0xffffffffu;
}

// ===========================================================================
// 0x0043A240
// ===========================================================================
// 0x0043a240 — observed shape
// Audio-manager bring-up. Initializes through FUN_004a86a0, probes the
// manager vtable slot +0x18 and reports the not-initialized message when it
// answers false; otherwise lazily runs the 0x4c80-byte setup once
// (DAT_008e8eff guard). Allocates 0x4c80 bytes and stores the sub-object from
// FUN_004a96a0, then pushes DAT_007263bc on the +4 dword stack at
// DAT_007268f4 and raises DAT_007263bc to 0xfffffff.
void FUN_0043a240(void) {
    FUN_004a86a0();

    char cVar1 = reinterpret_cast<char (*)(void)>(
        *reinterpret_cast<void **>(static_cast<uintptr_t>(DAT_008ecd78) + 0x18))();
    if (cVar1 == 0) {
        FUN_00488840("The audio manager has not been properly initialized yet", 0);
    } else if (DAT_008e8eff == 0) {
        FUN_004985e0();
        FUN_004a14b0();
    }

    uint32_t iVar2 = FUN_00533c78(0x4c80);
    if (iVar2 == 0) {
        DAT_008ca984 = nullptr;
    } else {
        DAT_008ca984 = reinterpret_cast<void *>(FUN_004a96a0());
    }

    FUN_004af990();

    *reinterpret_cast<uint32_t *>(
        reinterpret_cast<uint8_t *>(&DAT_007268f4) + DAT_00726a84 * 4) = DAT_007263bc;
    DAT_00726a84 = DAT_00726a84 + 1;
    DAT_007263bc = DAT_007263bc | 0xfffffffu;
}

// ===========================================================================
// 0x0043A350
// ===========================================================================
// 0x0043a350 — observed shape
// Audio-manager teardown. Without a live object it only pops the +4 dword
// stack at DAT_007268f4; with one it runs FUN_004a9770, deletes the object,
// clears DAT_008ca984 and pops the same slot.
void FUN_0043a350(void) {
    FUN_004a88d0();

    void *pvVar1 = DAT_008ca984;
    if (DAT_008ca984 == nullptr) {
        DAT_00726a84 = DAT_00726a84 + -1;
        DAT_007263bc = *reinterpret_cast<uint32_t *>(
            reinterpret_cast<uint8_t *>(&DAT_007268f4) + DAT_00726a84 * 4);
        return;
    }
    FUN_004a9770();
    operator_delete(pvVar1);
    DAT_00726a84 = DAT_00726a84 + -1;
    DAT_008ca984 = nullptr;
    DAT_007263bc = *reinterpret_cast<uint32_t *>(
        reinterpret_cast<uint8_t *>(&DAT_007268f4) + DAT_00726a84 * 4);
}

// ===========================================================================
// 0x0043A800
// ===========================================================================
// 0x0043a800 — observed shape
// Grid probe. Zeroes a 16-dword probe record (plus its four dword tail),
// installs the 0x10 callback set, then walks the 16x16 byte grid at
// DAT_00871978; for every cell that is neither 2 nor 5 it re-probes with
// FUN_0043a420 and, per FUN_00502e10's answer and the param_1/held-bit gate,
// stamps the chosen cell with the low bit of rand()'s result. Returns the
// held bit.
char FUN_0043a800(char param_1) {
    char cVar1;
    uint32_t uVar2;
    int iVar3;
    int iVar4;
    bool bVar5;
    char local_59;
    uint8_t *local_58;
    int local_54 = 0;
    int local_50[16];
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;
    uint32_t local_4;

    local_50[1] = 0;
    local_50[2] = 0;
    local_50[3] = 0;
    local_50[4] = 0;
    local_50[5] = 0;
    local_50[6] = 0;
    local_50[7] = 0;
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;

    FUN_00502cd0(0x10, 0, 0, 0,
                 reinterpret_cast<void *>(&LAB_0043a3e0), 0,
                 reinterpret_cast<void *>(&LAB_0043a3b0),
                 0, 0, 0);

    local_59 = 0;
    iVar3 = 0;
    local_58 = &DAT_00871978;
    do {
        iVar4 = 0;
        do {
            if ((local_58[iVar4] != 0x02) && (local_58[iVar4] != 0x05)) {
                while (((cVar1 = FUN_00502e10(iVar3, 0xd, 9, 0, 0, 0), cVar1 == 0 ||
                        ((local_59 != 0 && (param_1 == 0)))) &&
                       (local_59 = 1, param_1 != 0))) {
                    cVar1 = FUN_0043a420(iVar3, iVar4, &local_54, local_50);
                    if (cVar1 == 0) {
                        FUN_00502c80();
                        return 1;
                    }
                    uVar2 = static_cast<uint32_t>(rand());
                    uVar2 = uVar2 & 0x80000001u;
                    bVar5 = (uVar2 == 0);
                    if (static_cast<int32_t>(uVar2) < 0) {
                        bVar5 = ((uVar2 - 1) | 0xfffffffeu) == 0xffffffffu;
                    }
                    (&DAT_00871978)[local_50[0] + local_54 * 0x10] = !bVar5;
                }
            }
            iVar4 = iVar4 + 1;
        } while (iVar4 < 0x10);
        local_58 = local_58 + 0x10;
        iVar3 = iVar3 + 1;
    } while (reinterpret_cast<uintptr_t>(local_58) < 0x871a78u);

    FUN_00502c80();
    return local_59;
}

// ===========================================================================
// 0x0043A940
// ===========================================================================
// 0x0043a940 — observed shape
// Pure forwarder: appends DAT_0085a11c as the fourth argument and
// (2, 0xffffffff, 0) as the tail of FUN_004b06c0.
void FUN_0043a940(uint32_t param_1, uint32_t param_2, uint32_t param_3,
                  uint32_t param_4) {
    FUN_004b06c0(param_1, param_2, param_3, DAT_0085a11c, param_4, 2,
                 0xffffffffu, 0);
}

// ===========================================================================
// 0x0043A970
// ===========================================================================
// 0x0043a970 — observed shape
// Appends one 0x1c-byte record at index DAT_0085a100 in the table based at
// DAT_00862d10: clears the seven dwords, stores (param_1..param_4) plus
// DAT_0085a150 / DAT_00814304 / DAT_00814308, then either bumps the count
// (under 999) or memmoves the whole 0x1b51-dword region down by one record
// from DAT_00862d2c and returns the old index.
int FUN_0043a970(uint8_t param_1, uint32_t param_2, uint32_t param_3,
                 uint32_t param_4) {
    int iVar3 = DAT_0085a100;
    int iVar4 = DAT_0085a100 * 0x1c;
    int iVar5 = DAT_0085a100 * 7;

    *reinterpret_cast<uint32_t *>(&DAT_00862d10 + iVar5 * 4) = 0;
    *reinterpret_cast<uint32_t *>(&DAT_00862d14 + iVar3 * 7 * 4) = 0;
    *reinterpret_cast<uint32_t *>(&DAT_00862d18 + iVar3 * 7 * 4) = 0;
    *reinterpret_cast<uint32_t *>(&DAT_00862d1c + iVar3 * 7 * 4) = 0;
    *reinterpret_cast<uint32_t *>(&DAT_00862d20 + iVar4) = 0;
    *reinterpret_cast<uint32_t *>(&DAT_00862d24 + iVar4) = 0;
    *reinterpret_cast<uint32_t *>(&DAT_00862d28 + iVar4) = 0;

    *reinterpret_cast<uint8_t *>(&DAT_00862d10 + iVar5) = param_1;
    *reinterpret_cast<uint32_t *>(&DAT_00862d18 + iVar3 * 7 * 4) = param_3;

    uint32_t uVar1 = DAT_0085a150;
    *reinterpret_cast<uint32_t *>(&DAT_00862d14 + iVar3 * 7 * 4) = param_2;
    *reinterpret_cast<uint32_t *>(&DAT_00862d20 + iVar4) = uVar1;

    uint32_t uVar2 = DAT_00814308;
    *reinterpret_cast<uint32_t *>(&DAT_00862d1c + iVar3 * 7 * 4) = param_4;
    uVar1 = DAT_00814304;
    *reinterpret_cast<uint32_t *>(&DAT_00862d28 + iVar4) = uVar2;
    *reinterpret_cast<uint32_t *>(&DAT_00862d24 + iVar4) = uVar1;

    if (iVar3 < 999) {
        DAT_0085a100 = iVar3 + 1;
        return iVar3;
    }

    uint32_t *puVar6 = reinterpret_cast<uint32_t *>(&DAT_00862d2c);
    uint32_t *puVar7 = reinterpret_cast<uint32_t *>(&DAT_00862d10);
    for (iVar5 = 0x1b51; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
    }
    return iVar3;
}

// ===========================================================================
// 0x00436AC0
// ===========================================================================
// 0x00436ac0 — observed shape
// Pure four-way slot search. Selects the 0x530-byte row DAT_0086ea8c +
// in_EAX*0x530 and visits four entries per pass (indices iVar3-2 .. iVar3+1,
// strides 0x14c dwords) while iVar3+2 < 0x10. An entry is live when its
// (short) tag at -0x29/+0x2a/+0x7d/+0xd0 is not -1; the distance is
// Manhattan-like (min + 2*max) / 2 against param_1 (x at -0xc..) and param_2
// (y at 0..), keeping the smallest in local_4 (init -1, threshold 0xffffff).
int FUN_00436ac0(int in_EAX, int param_1, int param_2) {
    int local_4 = -1;
    int iVar5 = 0xffffff;
    int *piVar4 = &DAT_0086ea8c + in_EAX * 0x530;
    int iVar3 = 2;

    do {
        int iVar1;
        int iVar2;

        if (static_cast<short>(piVar4[-0x29]) != -1) {
            iVar1 = param_2 - *piVar4;
            iVar2 = param_1 - piVar4[-0xc];
            if (iVar2 < 0) iVar2 = -iVar2;
            if (iVar1 < 0) iVar1 = -iVar1;
            if (iVar1 < iVar2) iVar1 = iVar1 + iVar2 * 2;
            else               iVar1 = iVar2 + iVar1 * 2;
            if (iVar1 / 2 < iVar5) {
                local_4 = iVar3 + -2;
                iVar5 = iVar1 / 2;
            }
        }
        if (static_cast<short>(piVar4[0x2a]) != -1) {
            iVar1 = param_2 - piVar4[0x53];
            iVar2 = param_1 - piVar4[0x47];
            if (iVar2 < 0) iVar2 = -iVar2;
            if (iVar1 < 0) iVar1 = -iVar1;
            if (iVar1 < iVar2) iVar1 = iVar1 + iVar2 * 2;
            else               iVar1 = iVar2 + iVar1 * 2;
            if (iVar1 / 2 < iVar5) {
                local_4 = iVar3 + -1;
                iVar5 = iVar1 / 2;
            }
        }
        if (static_cast<short>(piVar4[0x7d]) != -1) {
            iVar1 = param_2 - piVar4[0xa6];
            iVar2 = param_1 - piVar4[0x9a];
            if (iVar2 < 0) iVar2 = -iVar2;
            if (iVar1 < 0) iVar1 = -iVar1;
            if (iVar1 < iVar2) iVar1 = iVar1 + iVar2 * 2;
            else               iVar1 = iVar2 + iVar1 * 2;
            if (iVar1 / 2 < iVar5) {
                iVar5 = iVar1 / 2;
                local_4 = iVar3;
            }
        }
        if (static_cast<short>(piVar4[0xd0]) != -1) {
            iVar1 = param_2 - piVar4[0xf9];
            iVar2 = param_1 - piVar4[0xed];
            if (iVar2 < 0) iVar2 = -iVar2;
            if (iVar1 < 0) iVar1 = -iVar1;
            if (iVar1 < iVar2) iVar1 = iVar1 + iVar2 * 2;
            else               iVar1 = iVar2 + iVar1 * 2;
            if (iVar1 / 2 < iVar5) {
                local_4 = iVar3 + 1;
                iVar5 = iVar1 / 2;
            }
        }

        iVar1 = iVar3 + 2;
        piVar4 = piVar4 + 0x14c;
        iVar3 = iVar3 + 4;
    } while (iVar1 < 0x10);

    return local_4;
}

// ---------------------------------------------------------------------------
// Additional helpers/globals used by the 0x43a420..0x43fd70 group.
// ---------------------------------------------------------------------------
extern void     FUN_0043b8e0(uint32_t, uint32_t, int *);
extern int      FUN_004879f0(int, int);
extern void     FUN_00412f10(void);
extern void     FUN_00412ec0(void);
extern void     FUN_00412fb0(void);
extern void     FUN_004f18c0(int *, int);
extern void     FUN_004b24a0(uint32_t, int);
extern uint32_t FUN_004cddf0(uint32_t, int, int, int *, int *);
extern void     FUN_004af080(uint32_t, int, int, int, int, int, int, int, int,
                             uint32_t, int);
extern void     FUN_00509500(uint32_t, int, int);
extern int      FUN_004b2760(int);
extern void     operator_delete__(void *);
extern int      FUN_0045fcb0(uint32_t, uint32_t, uint32_t, int, uint32_t);
extern void     FUN_004f60b0(const char *, ...);

extern uint32_t DAT_008cacd0;
extern uint32_t DAT_008cacc8;
extern int32_t  DAT_0085a26c;
extern int32_t  DAT_0085a268;
extern uint8_t  DAT_008cac27;
extern uint32_t DAT_008cabe8;
extern uint32_t DAT_008c9de0;
extern uint32_t DAT_008c9dd8;
extern uint32_t DAT_0085c0b8;
extern int32_t  DAT_00869b14;
extern uint32_t DAT_00869a88;
extern uint32_t DAT_00869a8a;
extern uint32_t DAT_00869a8c;
extern uint32_t DAT_00869a8e;
extern uint8_t  DAT_00862018;
extern uint32_t DAT_00860b90;
extern int16_t  DAT_0085bf78;
extern uint32_t DAT_00869b1e;
extern uint32_t DAT_00869b1c;
extern uint32_t DAT_0085a3b8;
extern uint32_t DAT_0085a4c8;
extern uint32_t DAT_0085a500;
extern uint32_t DAT_0085a610;
extern uint32_t DAT_0085a648;
extern uint32_t DAT_0085a758;
extern uint32_t _DAT_0085a164;
extern int32_t  DAT_008e9f5c;
extern uint32_t DAT_008dbd08;
extern uint32_t DAT_008dbd0c;
extern uint32_t DAT_008dbd10;
extern uint32_t DAT_00860b80;
extern uint32_t DAT_008cb100;
extern uint32_t DAT_008cb104;
extern uint32_t DAT_008cb108;
extern uint32_t DAT_0085bf74;
extern uint32_t DAT_00860b68;
extern uint32_t DAT_00860b6c;
extern uint8_t  DAT_00862002;
extern uint32_t DAT_008cb178;
extern uint32_t DAT_008cb17c;
extern uint32_t DAT_008cb180;
extern uint32_t DAT_008cb19c;
extern uint32_t DAT_008cb1a0;
extern uint32_t DAT_008cb1a4;

// ===========================================================================
// 0x0043A420
// ===========================================================================
// 0x0043a420 — observed shape
// Grid distance fit. Walks the 16x16 cell table at DAT_00871979 with a
// 4-column unrolled inner scan (columns -1/0/+1/+2 around local_38), scoring
// only cells equal to 2. Each candidate is evaluated as
// (rowTerm/2 + colTerm/2) with the Manhattan min+2*max fold, and the smallest
// score wins, writing the cell offset into *param_3 / *param_4. Returns true
// iff a cell scored below the 0x7fffffff sentinel.
bool FUN_0043a420(int param_1, int param_2, int *param_3, int *param_4) {
    int iVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    int iVar6;
    int iVar7;
    int iVar8;
    int local_44;
    int local_40;
    int local_3c;
    uint8_t *local_38;
    int local_34;
    int local_30;
    int local_2c;
    int local_28;
    int local_24;
    int local_20;

    iVar3 = 0x7fffffff;
    local_3c = 0x7fffffff;
    iVar7 = -param_1;
    local_40 = 0xd;
    local_38 = &DAT_00871979;
    iVar5 = -0xd;
    do {
        local_44 = param_2 + -2;
        local_20 = 3;
        local_28 = -8;
        local_24 = -0x10;
        local_2c = 0x10;
        iVar6 = 2 - param_2;
        local_34 = param_2 * -2 + 2;
        local_30 = param_2 * 2 + -2;
        do {
            if (local_38[-1] == 0x02) {
                iVar4 = local_34 + -2;
                iVar3 = iVar6 + -2;
                iVar1 = iVar7;
                if (iVar7 < 0) {
                    iVar1 = param_1 + -0xd + local_40;
                }
                if (iVar3 < 0) {
                    iVar3 = local_44 + 2;
                    iVar4 = local_30 + 2;
                }
                iVar8 = iVar3 + iVar1 * 2;
                if (iVar1 <= iVar3) {
                    iVar8 = iVar4 + iVar1;
                }
                iVar1 = local_44 + (0xb - param_2);
                iVar4 = local_2c + 2;
                iVar3 = local_40;
                if (0 < iVar5) {
                    iVar3 = iVar5;
                }
                if (iVar1 < 0) {
                    iVar1 = local_28 + -1;
                    iVar4 = local_24 + -2;
                }
                iVar2 = iVar1 + iVar3 * 2;
                if (iVar3 <= iVar1) {
                    iVar2 = iVar4 + iVar3;
                }
                iVar1 = iVar2 / 2 + iVar8 / 2;
                iVar3 = local_3c;
                if (iVar1 < local_3c) {
                    *param_3 = iVar7 + param_1;
                    *param_4 = param_2 + -2 + iVar6;
                    iVar3 = iVar1;
                    local_3c = iVar1;
                }
            }
            if (*local_38 == 0x02) {
                iVar3 = iVar6 + -1;
                iVar1 = iVar7;
                if (iVar7 < 0) {
                    iVar1 = param_1 + -0xd + local_40;
                }
                iVar4 = local_34;
                if (iVar3 < 0) {
                    iVar3 = local_44 + 1;
                    iVar4 = local_30;
                }
                iVar8 = iVar3 + iVar1 * 2;
                if (iVar1 <= iVar3) {
                    iVar8 = iVar4 + iVar1;
                }
                iVar3 = local_44 + (10 - param_2);
                iVar1 = local_40;
                if (0 < iVar5) {
                    iVar1 = iVar5;
                }
                iVar4 = local_2c;
                if (iVar3 < 0) {
                    iVar3 = local_28;
                    iVar4 = local_24;
                }
                iVar2 = iVar3 + iVar1 * 2;
                if (iVar1 <= iVar3) {
                    iVar2 = iVar4 + iVar1;
                }
                iVar1 = iVar2 / 2 + iVar8 / 2;
                iVar3 = local_3c;
                if (iVar1 < local_3c) {
                    *param_3 = iVar7 + param_1;
                    *param_4 = param_2 + -1 + iVar6;
                    iVar3 = iVar1;
                    local_3c = iVar1;
                }
            }
            if (local_38[1] == 0x02) {
                iVar1 = local_34 + 2;
                iVar3 = iVar7;
                if (iVar7 < 0) {
                    iVar3 = param_1 + -0xd + local_40;
                }
                iVar4 = iVar6;
                if (iVar6 < 0) {
                    iVar1 = local_30 + -2;
                    iVar4 = local_44;
                }
                iVar8 = iVar4 + iVar3 * 2;
                if (iVar3 <= iVar4) {
                    iVar8 = iVar1 + iVar3;
                }
                iVar3 = local_44 + (9 - param_2);
                iVar4 = local_2c + -2;
                iVar1 = local_40;
                if (0 < iVar5) {
                    iVar1 = iVar5;
                }
                if (iVar3 < 0) {
                    iVar3 = local_28 + 1;
                    iVar4 = local_24 + 2;
                }
                iVar2 = iVar3 + iVar1 * 2;
                if (iVar1 <= iVar3) {
                    iVar2 = iVar4 + iVar1;
                }
                iVar1 = iVar2 / 2 + iVar8 / 2;
                iVar3 = local_3c;
                if (iVar1 < local_3c) {
                    *param_3 = iVar7 + param_1;
                    *param_4 = param_2 + iVar6;
                    iVar3 = iVar1;
                    local_3c = iVar1;
                }
            }
            if (local_38[2] == 0x02) {
                iVar4 = local_34 + 4;
                iVar3 = iVar6 + 1;
                iVar1 = iVar7;
                if (iVar7 < 0) {
                    iVar1 = param_1 + -0xd + local_40;
                }
                if (iVar3 < 0) {
                    iVar3 = local_44 + -1;
                    iVar4 = local_30 + -4;
                }
                iVar8 = iVar3 + iVar1 * 2;
                if (iVar1 <= iVar3) {
                    iVar8 = iVar4 + iVar1;
                }
                iVar1 = (8 - param_2) + local_44;
                iVar4 = local_2c + -4;
                iVar3 = local_40;
                if (0 < iVar5) {
                    iVar3 = iVar5;
                }
                if (iVar1 < 0) {
                    iVar1 = local_28 + 2;
                    iVar4 = local_24 + 4;
                }
                iVar2 = iVar1 + iVar3 * 2;
                if (iVar3 <= iVar1) {
                    iVar2 = iVar4 + iVar3;
                }
                iVar1 = iVar2 / 2 + iVar8 / 2;
                iVar3 = local_3c;
                if (iVar1 < local_3c) {
                    *param_3 = iVar7 + param_1;
                    *param_4 = local_20;
                    iVar3 = iVar1;
                    local_3c = iVar1;
                }
            }
            local_44 = local_44 + -4;
            local_28 = local_28 + 4;
            local_38 = local_38 + 4;
            local_34 = local_34 + 8;
            local_30 = local_30 + -8;
            local_2c = local_2c + -8;
            local_24 = local_24 + 8;
            local_20 = local_20 + 4;
            iVar6 = iVar6 + 4;
        } while (param_2 + -2 + iVar6 < 0x10);
        iVar7 = iVar7 + 1;
        local_40 = local_40 + -1;
        iVar5 = iVar5 + 1;
    } while (iVar7 + param_1 < 0x10);
    return iVar3 < 0x7fffffff;
}

// ===========================================================================
// 0x0043AA10
// ===========================================================================
// 0x0043aa10 — observed shape
// Report formatter for one 7-dword event record at DAT_00862d10 + in_ECX*7.
// When the event stream is outside 6..11 it appends " -" to the scratch text
// at 0x869b47. The record type (byte at +0) selects the case, emitting
// FUN_004f60b0 templates with the packed fields uVar8 (+4), uVar11 (+8) and
// uVar3 (+0xc); town/nation lookups index DAT_008dbd08/0c/10 by *3. The tail
// terminates the same scratch text with a newline when the stream is idle.
void FUN_0043aa10(int in_ECX) {
    int iVar1;
    int iVar2;
    uint32_t uVar3;
    uint32_t *puVar4;
    uint16_t *puVar5;
    uint16_t *puVar6;
    char *pcVar7;
    uint32_t uVar8;
    uint32_t uVar9;
    uint32_t uVar10;
    uint32_t uVar11;

    uVar11 = *reinterpret_cast<uint32_t *>(&DAT_00862d18 + in_ECX * 7 * 4);
    uVar3 = *reinterpret_cast<uint32_t *>(&DAT_00862d1c + in_ECX * 7 * 4);
    uVar8 = *reinterpret_cast<uint32_t *>(&DAT_00862d14 + in_ECX * 7 * 4);

    if ((DAT_008e9f5c < 6) || (0xb < DAT_008e9f5c)) {
        puVar6 = reinterpret_cast<uint16_t *>(static_cast<uintptr_t>(0x869b47));
        do {
            puVar5 = puVar6;
            puVar6 = reinterpret_cast<uint16_t *>(reinterpret_cast<uintptr_t>(puVar5) + 1);
        } while (*reinterpret_cast<char *>(reinterpret_cast<uintptr_t>(puVar5) + 1) != 0);
        *reinterpret_cast<uint16_t *>(reinterpret_cast<uintptr_t>(puVar5) + 1) = 0x202d;
        *reinterpret_cast<uint8_t *>(reinterpret_cast<uintptr_t>(puVar5) + 3) = 0;
    }

    if (0x42u < static_cast<uint32_t>(
                    static_cast<int>(*reinterpret_cast<char *>(&DAT_00862d10 + in_ECX * 7)) - 3)) {
        goto switchD_0043aa75_caseD_b;
    }
    iVar1 = static_cast<int>(uVar8) >> 4;
    iVar2 = static_cast<int>(uVar8) >> 8;
    switch (*reinterpret_cast<char *>(&DAT_00862d10 + in_ECX * 7)) {
    case 0x03:
        FUN_004f60b0("immigrants are flocking to @CITYNAME", (&DAT_008dbd08)[uVar8 * 3],
                     (&DAT_008dbd0c)[uVar8 * 3], (&DAT_008dbd10)[uVar8 * 3]);
        break;
    case 0x04:
        FUN_004f60b0("malaria's struck in @CITYNAME", (&DAT_008dbd08)[uVar8 * 3],
                     (&DAT_008dbd0c)[uVar8 * 3], (&DAT_008dbd10)[uVar8 * 3]);
        break;
    case 0x05:
        if (uVar11 == 0xffffffffu) {
            FUN_004f60b0("you intercepted the new Governor of @CITYNAME",
                         (&DAT_008dbd08)[uVar8 * 3], (&DAT_008dbd0c)[uVar8 * 3],
                         (&DAT_008dbd10)[uVar8 * 3]);
        } else {
            FUN_004f60b0("there's a new Governor in @CITYNAME", (&DAT_008dbd08)[uVar8 * 3],
                         (&DAT_008dbd0c)[uVar8 * 3], (&DAT_008dbd10)[uVar8 * 3]);
        }
        break;
    case 0x06:
        FUN_004f60b0("pirates attacked @CITYNAME", (&DAT_008dbd08)[uVar8 * 3],
                     (&DAT_008dbd0c)[uVar8 * 3], (&DAT_008dbd10)[uVar8 * 3]);
        break;
    case 0x07:
        uVar9 = (&DAT_008dbd08)[uVar11 * 3];
        uVar10 = (&DAT_008dbd0c)[uVar11 * 3];
        uVar3 = (&DAT_008dbd10)[uVar11 * 3];
        pcVar7 = "@NATION has captured the city of @CITYNAME";
        goto LAB_0043b733;
    case 0x08:
        FUN_004f60b0("there's a healthy sugar crop in @CITYNAME", (&DAT_008dbd08)[uVar8 * 3],
                     (&DAT_008dbd0c)[uVar8 * 3], (&DAT_008dbd10)[uVar8 * 3]);
        break;
    case 0x09:
        FUN_004f60b0("indians attacked @CITYNAME", (&DAT_008dbd08)[uVar8 * 3],
                     (&DAT_008dbd0c)[uVar8 * 3], (&DAT_008dbd10)[uVar8 * 3]);
        break;
    case 0x0a:
        FUN_004f60b0("reinforcements arrive in @CITYNAME", (&DAT_008dbd08)[uVar8 * 3],
                     (&DAT_008dbd0c)[uVar8 * 3], (&DAT_008dbd10)[uVar8 * 3]);
        break;
    case 0x0c:
        FUN_004f60b0("gold's been discovered in @CITYNAME", (&DAT_008dbd08)[uVar8 * 3],
                     (&DAT_008dbd0c)[uVar8 * 3], (&DAT_008dbd10)[uVar8 * 3]);
        break;
    case 0x0e:
        FUN_004f60b0("there's a price on your head in @CITYNAME", (&DAT_008dbd08)[uVar8 * 3],
                     (&DAT_008dbd0c)[uVar8 * 3], (&DAT_008dbd10)[uVar8 * 3]);
        break;
    case 0x0f:
        FUN_004f60b0("a pirate hunter sails from @CITYNAME", (&DAT_008dbd08)[uVar8 * 3],
                     (&DAT_008dbd0c)[uVar8 * 3], (&DAT_008dbd10)[uVar8 * 3]);
        break;
    case 0x10:
        if (uVar11 == 0) {
            FUN_004f60b0("@NATION is at war with @NATION", uVar8 & 0xf, iVar1);
        } else {
            FUN_004f60b0("you delivered an ultimatum to the @NATIONALITY", iVar1);
        }
        break;
    case 0x11:
        FUN_004f60b0("@NATION is no longer at war with @NATION", uVar8 & 0xf, iVar1);
        break;
    case 0x12:
        if (uVar11 == 0) {
            FUN_004f60b0("@NATION and @NATION have signed a Peace Treaty", uVar8 & 0xf, iVar1);
        } else {
            FUN_004f60b0("you delivered a peace treaty to the @NATIONALITY", iVar1);
        }
        break;
    case 0x13:
        FUN_004f60b0("@NATION and @NATION have canceled their Peace Treaty", uVar8 & 0xf, iVar1);
        break;
    case 0x14:
        FUN_004f60b0("@NATION is offering Pirate Amnesty", uVar8 & 0xf);
        break;
    case 0x15:
        uVar9 = (&DAT_008dbd08)[uVar11 * 3];
        uVar10 = (&DAT_008dbd0c)[uVar11 * 3];
        uVar3 = (&DAT_008dbd10)[uVar11 * 3];
        pcVar7 = "@NATION has captured the settlement of @CITYNAME";
        goto LAB_0043b733;
    case 0x20:
        FUN_004f60b0("you attacked @ANATIONALITY @SHIPTYPE", iVar2, uVar8 & 0xff);
        break;
    case 0x21:
        switch (uVar3) {
        case 6:
            FUN_004f60b0("you captured a band of Pirate raiders");
            break;
        case 7:
        switchD_0043b023_caseD_7:
            FUN_004f60b0("you intercepted @ANATIONALITY invasion force", iVar2);
            break;
        default:
            FUN_004f60b0("you captured @ANATIONALITY @SHIPTYPE", iVar2, uVar8 & 0xff);
            break;
        case 9:
            FUN_004f60b0("you captured an Indian war party");
            break;
        case 0xc:
            FUN_004f60b0("you captured @ANATIONALITY treasure ship", iVar2);
            break;
        case 0xd:
            FUN_004f60b0("you captured @ANATIONALITY payroll courier", iVar2);
            break;
        case 0xe:
            FUN_004f60b0("you captured @ANATIONALITY grain transport", iVar2);
        }
        break;
    case 0x22:
        switch (uVar3) {
        case 6:
            FUN_004f60b0("you intercepted some Pirate raiders");
            break;
        case 7:
            goto switchD_0043b023_caseD_7;
        default:
            FUN_004f60b0("you sank @ANATIONALITY @SHIPTYPE", iVar2, uVar8 & 0xff);
            break;
        case 9:
            FUN_004f60b0("you intercepted an Indian war party");
            break;
        case 0xc:
            FUN_004f60b0("you sank @ANATIONALITY treasure ship", iVar2);
            break;
        case 0xd:
            FUN_004f60b0("you sank @ANATIONALITY payroll courier", iVar2);
            break;
        case 0xe:
            FUN_004f60b0("you sank @ANATIONALITY grain transport", iVar2);
        }
        break;
    case 0x23:
        switch ((&DAT_00860b80)[uVar8 * 8]) {
        case 4:
            FUN_004f60b0("you visited the haven of @CITYNAME", (&DAT_008dbd08)[uVar8 * 3],
                         (&DAT_008dbd0c)[uVar8 * 3], (&DAT_008dbd10)[uVar8 * 3]);
            break;
        case 5:
            FUN_004f60b0("you visited the village of @CITYNAME", (&DAT_008dbd08)[uVar8 * 3],
                         (&DAT_008dbd0c)[uVar8 * 3], (&DAT_008dbd10)[uVar8 * 3]);
            break;
        case 6:
            FUN_004f60b0("you visited the mission of @CITYNAME", (&DAT_008dbd08)[uVar8 * 3],
                         (&DAT_008dbd0c)[uVar8 * 3], (&DAT_008dbd10)[uVar8 * 3]);
            break;
        case 7:
            FUN_004f60b0("you visited the settlement of @CITYNAME", (&DAT_008dbd08)[uVar8 * 3],
                         (&DAT_008dbd0c)[uVar8 * 3], (&DAT_008dbd10)[uVar8 * 3]);
            break;
        default:
            FUN_004f60b0("you visited the town of @CITYNAME", (&DAT_008dbd08)[uVar8 * 3],
                         (&DAT_008dbd0c)[uVar8 * 3], (&DAT_008dbd10)[uVar8 * 3]);
        }
        break;
    case 0x24:
        if ((uVar8 & 0xf) < 2) {
            FUN_004f60b0("you received @ANATIONALITY Letter of Marque", iVar1);
        } else {
            FUN_004f60b0("you were promoted to @NATIONALITY @RANK", iVar1, uVar8 & 0xf);
        }
        break;
    case 0x25:
        if (uVar11 == 0) {
            FUN_004f60b0("you acquired @APROP1", uVar8);
        } else if (uVar11 == 1) {
            FUN_004f60b0("you acquired @APROP2", uVar8);
        }
        break;
    case 0x26:
        FUN_004f60b0("you recruited a skilled @SPEC", uVar8);
        break;
    case 0x27:
        switch (uVar8) {
        case 0x1e:
            FUN_004f60b0("you captured a wanted criminal in @CITYNAME",
                         (&DAT_008dbd08)[uVar11 * 3], (&DAT_008dbd0c)[uVar11 * 3],
                         (&DAT_008dbd10)[uVar11 * 3]);
            break;
        case 0x28:
            FUN_004f60b0("you captured the evil Baron Raymondo");
            break;
        case 0x29:
            FUN_004f60b0("you captured the evil Colonel Mendoza");
            break;
        case 0x2a:
            FUN_004f60b0("you captured the Marquis de la Montalban");
        }
        break;
    case 0x28:
        FUN_004f60b0("you met the Governor of @CITYNAME's daughter",
                     (&DAT_008dbd08)[uVar8 * 3], (&DAT_008dbd0c)[uVar8 * 3],
                     (&DAT_008dbd10)[uVar8 * 3]);
        break;
    case 0x29:
        FUN_004f60b0("you dueled a jealous suitor in @CITYNAME", (&DAT_008dbd08)[uVar8 * 3],
                     (&DAT_008dbd0c)[uVar8 * 3], (&DAT_008dbd10)[uVar8 * 3]);
        break;
    case 0x2a:
        FUN_004f60b0("you rescued the governor of @CITYNAME's daughter",
                     (&DAT_008dbd08)[uVar8 * 3], (&DAT_008dbd0c)[uVar8 * 3],
                     (&DAT_008dbd10)[uVar8 * 3]);
        break;
    case 0x2b:
        uVar3 = (&DAT_0085bf74)[uVar8 * 0x25] & 3;
        uVar9 = (&DAT_008dbd0c)[uVar8 * 3];
        uVar10 = (&DAT_008dbd10)[uVar8 * 3];
        pcVar7 = "you married the governor of @CITYNAME's @BEAUTY daughter";
        uVar8 = (&DAT_008dbd08)[uVar8 * 3];
        goto LAB_0043b733;
    case 0x2c:
        puVar4 = &DAT_008cb100 + uVar8 * 3;
        pcVar7 = "you found @TOP10's treasure worth @NUM gold!";
        goto LAB_0043b723;
    case 0x2d:
        FUN_004f60b0("you rescued your @RELATIVE", uVar8);
        break;
    case 0x2e:
        FUN_004f60b0("you found a great lost treasure!");
        break;
    case 0x2f:
        if (uVar11 == 0xffffffffu) {
            FUN_004f60b0("you sacked the town of @CITYNAME", (&DAT_008dbd08)[uVar8 * 3],
                         (&DAT_008dbd0c)[uVar8 * 3], (&DAT_008dbd10)[uVar8 * 3]);
            break;
        }
        uVar9 = (&DAT_008dbd08)[uVar8 * 3];
        uVar10 = (&DAT_008dbd0c)[uVar8 * 3];
        uVar3 = (&DAT_008dbd10)[uVar8 * 3];
        pcVar7 = "you installed @ANATIONALITY governor in @CITYNAME";
        uVar8 = uVar11;
        goto LAB_0043b733;
    case 0x30:
        FUN_004f60b0("you defeated the notorious pirate @TOP10", (&DAT_008cb100)[uVar8 * 3],
                     (&DAT_008cb104)[uVar8 * 3], (&DAT_008cb108)[uVar8 * 3]);
        break;
    case 0x31:
        if (uVar8 == 0xffffffffu) {
            FUN_004f60b0("you were marooned on an island");
        } else {
            FUN_004f60b0("you were imprisoned in @CITYNAME", (&DAT_008dbd08)[uVar8 * 3],
                         (&DAT_008dbd0c)[uVar8 * 3], (&DAT_008dbd10)[uVar8 * 3]);
        }
        break;
    case 0x32:
        FUN_004f60b0("you defeated an evil captain");
        break;
    case 0x33:
        FUN_004f60b0("you vanquished the Marquis Montalban");
        break;
    case 0x40:
        FUN_004f60b0("the Spanish Treasure fleet is headed for @CITYNAME",
                     (&DAT_008dbd08)[uVar8 * 3], (&DAT_008dbd0c)[uVar8 * 3],
                     (&DAT_008dbd10)[uVar8 * 3]);
        break;
    case 0x41:
        FUN_004f60b0("the Silver train is in @CITYNAME", (&DAT_008dbd08)[uVar8 * 3],
                     (&DAT_008dbd0c)[uVar8 * 3], (&DAT_008dbd10)[uVar8 * 3]);
        break;
    case 0x42:
        uVar9 = (&DAT_008dbd08)[uVar11 * 3];
        uVar10 = (&DAT_008dbd0c)[uVar11 * 3];
        uVar3 = (&DAT_008dbd10)[uVar11 * 3];
        pcVar7 = "@ANATIONALITY smuggler is headed for @CITYNAME";
        goto LAB_0043b733;
    case 0x43:
        iVar1 = static_cast<int>(*reinterpret_cast<int16_t *>(&DAT_00862002 + uVar8 * 0x1c));
        iVar1 = FUN_0045fcb0((&DAT_00860b68)[iVar1 * 8], (&DAT_00860b6c)[iVar1 * 8],
                             0xffffffffu, 9999, 0xc0008000u);
        iVar2 = static_cast<int>(*reinterpret_cast<int16_t *>(&DAT_00862002 + uVar8 * 0x1c));
        FUN_004f60b0("@TOP10 sails out of @CITYNAME near @CITYNAME",
                     (&DAT_008cb100)[uVar8 * 3], (&DAT_008cb104)[uVar8 * 3],
                     (&DAT_008cb108)[uVar8 * 3], (&DAT_008dbd08)[iVar2 * 3],
                     (&DAT_008dbd0c)[iVar2 * 3], (&DAT_008dbd10)[iVar2 * 3],
                     (&DAT_008dbd08)[iVar1 * 3], (&DAT_008dbd0c)[iVar1 * 3],
                     (&DAT_008dbd10)[iVar1 * 3]);
        break;
    case 0x44:
        if (static_cast<int>(uVar11) < 0x28) {
            if (static_cast<int>(uVar11) < 0x1e) {
                FUN_004f60b0("@TOP10 was seen in @CITYNAME", (&DAT_008cb100)[uVar11 * 3],
                             (&DAT_008cb104)[uVar11 * 3], (&DAT_008cb108)[uVar11 * 3],
                             (&DAT_008dbd08)[uVar8 * 3], (&DAT_008dbd0c)[uVar8 * 3],
                             (&DAT_008dbd10)[uVar8 * 3]);
            } else if (uVar3 == 0) {
                iVar1 = uVar11 * 3 + -0x5a;
                FUN_004f60b0("Mr. @NPCNAME was seen in @CITYNAME", (&DAT_008cb19c)[iVar1],
                             (&DAT_008cb1a0)[iVar1], (&DAT_008cb1a4)[iVar1],
                             (&DAT_008dbd08)[uVar8 * 3], (&DAT_008dbd0c)[uVar8 * 3],
                             (&DAT_008dbd10)[uVar8 * 3]);
            } else {
                iVar1 = uVar11 * 3 + -0x5a;
                FUN_004f60b0("Mr. @CHAR. @NPCNAME was seen in @CITYNAME", uVar3,
                             (&DAT_008cb19c)[iVar1], (&DAT_008cb1a0)[iVar1],
                             (&DAT_008cb1a4)[iVar1], (&DAT_008dbd08)[uVar8 * 3],
                             (&DAT_008dbd0c)[uVar8 * 3], (&DAT_008dbd10)[uVar8 * 3]);
            }
        } else {
            iVar1 = uVar11 * 3 + -0x78;
            FUN_004f60b0("@EVILNAME was seen in @CITYNAME", (&DAT_008cb178)[iVar1],
                         (&DAT_008cb17c)[iVar1], (&DAT_008cb180)[iVar1],
                         (&DAT_008dbd08)[uVar8 * 3], (&DAT_008dbd0c)[uVar8 * 3],
                         (&DAT_008dbd10)[uVar8 * 3]);
        }
        break;
    case 0x45:
        if (uVar8 != 2) {
            if (uVar8 == 0x1e) {
                FUN_004f60b0("a wanted criminal is hiding in @CITYNAME",
                             (&DAT_008dbd08)[uVar11 * 3], (&DAT_008dbd0c)[uVar11 * 3],
                             (&DAT_008dbd10)[uVar11 * 3]);
            }
            break;
        }
        puVar4 = &DAT_008dbd08 + uVar11 * 3;
        pcVar7 = "Gov. of @CITYNAME annoyed by @NATIONALITY privateer";
        uVar11 = uVar3 >> 8 & 0xff;
    LAB_0043b723:
        uVar9 = puVar4[1];
        uVar10 = puVar4[2];
        uVar8 = *puVar4;
        uVar3 = uVar11;
    LAB_0043b733:
        FUN_004f60b0(pcVar7, uVar8, uVar9, uVar10, uVar3);
    }

switchD_0043aa75_caseD_b:
    if ((DAT_008e9f5c < 6) || (0xb < DAT_008e9f5c)) {
        puVar6 = reinterpret_cast<uint16_t *>(static_cast<uintptr_t>(0x869b47));
        do {
            pcVar7 = reinterpret_cast<char *>(reinterpret_cast<uintptr_t>(puVar6) + 1);
            puVar6 = reinterpret_cast<uint16_t *>(reinterpret_cast<uintptr_t>(puVar6) + 1);
        } while (*pcVar7 != 0);
        *puVar6 = 10;
    }
}

// ===========================================================================
// 0x0043CA20
// ===========================================================================
// 0x0043ca20 — observed shape
// Event-menu builder/runner. Seeds 0x17 stack triples with a DAT_008cacd0
// sentinel, walks at most 0x17 record slots starting at
// (DAT_0085a100 + 0x3d1 + idx) % 1000, clears the 0x80 "seen" bit for
// masked records, and for records matching param_3 calls FUN_0043b8e0,
// inserting each hit into a sorted triple array (FUN_004879f0 sizing). It
// then renders the menu through FUN_004b24a0 / FUN_004cddf0+FUN_004af080 and
// dispatches entries with FUN_004b06c0 until a 1/0x1b/0x20 key or
// DAT_008cac27, releasing each triple's string and object as it goes.
void FUN_0043ca20(int param_1, uint32_t param_2, uint32_t param_3,
                  uint32_t param_4, int param_5) {
    bool bVar1;
    int *piVar2;
    int iVar3;
    uint32_t *puVar4;
    uint32_t *puVar5;
    uint32_t uVar6;
    int iVar7;
    int iVar8;
    int local_130;
    int local_12c;
    int local_128;
    uint8_t *local_124;
    int local_120;
    uint8_t *local_11c;
    int local_118;
    int local_114[68];
    uint32_t local_4;

    local_120 = 0;
    bVar1 = false;
    piVar2 = local_114 + 1;
    iVar7 = 0x17;
    do {
        piVar2[-2] = static_cast<int>(reinterpret_cast<uintptr_t>(&DAT_008cacd0));
        piVar2[-1] = 0;
        *piVar2 = -1;
        piVar2 = piVar2 + 3;
        iVar7 = iVar7 + -1;
    } while (iVar7 != 0);

    iVar7 = 0x16;
    local_130 = 0x16;
    do {
        if (local_130 < 0) break;
        if (param_5 < 0) {
            local_130 = param_5 + 0x17;
        }
        local_12c = (DAT_0085a100 + 0x3d1 + local_130) % 1000;
        if (param_5 < 0) {
            local_130 = 0;
        }
        uint8_t *cell = &DAT_00862d10 + local_12c * 7;
        if ((param_4 & static_cast<int>(*reinterpret_cast<signed char *>(cell))) != 0) {
            *cell = *cell & 0x7f;
        }
        if ((*reinterpret_cast<signed char *>(cell) > -1) &&
            ((param_3 & static_cast<int>(*reinterpret_cast<signed char *>(cell))) != 0)) {
            FUN_0043b8e0(*reinterpret_cast<uint32_t *>(&DAT_00862d18 + local_12c * 7 * 4),
                         *reinterpret_cast<uint32_t *>(&DAT_00862d1c + local_12c * 7 * 4),
                         &local_120);
            if (param_5 < 0) {
                puVar4 = &local_4;
                iVar7 = 0x17;
                do {
                    piVar2 = puVar4 + -3;
                    puVar4 = puVar4 + -3;
                    puVar5 = reinterpret_cast<uint32_t *>(
                        static_cast<uintptr_t>(*piVar2) - 8);
                    if ((puVar5 != nullptr) &&
                        (puVar5 != reinterpret_cast<uint32_t *>(&DAT_008cacc8))) {
                        operator_delete__(puVar5);
                    }
                    iVar7 = iVar7 + -1;
                    *puVar4 = static_cast<uint32_t>(
                        reinterpret_cast<uintptr_t>(&DAT_008cacd0));
                } while (iVar7 != 0);
                return;
            }
            iVar3 = FUN_004879f0(0x48, 8);
            iVar7 = iVar7 + (1 - iVar3);
            if (iVar7 < 0) break;
            if (iVar3 == 1) {
                FUN_00412f10();
                local_114[iVar7 * 3] = local_120;
                local_114[iVar7 * 3 + 1] = local_12c;
            } else {
                local_124 = &DAT_008cacd0;
                FUN_00412f10();
                local_128 = 0;
                do {
                    iVar8 = iVar7;
                    FUN_004f18c0(&local_128, 10);
                    FUN_00412ec0();
                    // NEEDS_MANUAL: the listing reads local_11c here without
                    // any visible assignment; FUN_00412f10/FUN_00412ec0 own
                    // that slot in the shipped code.
                    puVar4 = reinterpret_cast<uint32_t *>(local_11c - 8);
                    if ((puVar4 != nullptr) &&
                        (puVar4 != reinterpret_cast<uint32_t *>(&DAT_008cacc8))) {
                        operator_delete__(puVar4);
                    }
                    local_11c = &DAT_008cacd0;
                    iVar7 = iVar8 + 1;
                } while (local_128 > -1);
                local_114[iVar8 * 3] = local_120;
                local_114[iVar8 * 3 + 1] = local_12c;
                iVar7 = iVar8 + (1 - iVar3);
                FUN_00412fb0();
            }
        }
        iVar7 = iVar7 + -1;
        local_130 = local_130 + -1;
    } while (iVar7 > -1);

    if (param_5 < 0) {
        puVar4 = &local_4;
        iVar7 = 0x17;
        do {
            piVar2 = puVar4 + -3;
            puVar4 = puVar4 + -3;
            puVar5 = reinterpret_cast<uint32_t *>(static_cast<uintptr_t>(*piVar2) - 8);
            if ((puVar5 != nullptr) &&
                (puVar5 != reinterpret_cast<uint32_t *>(&DAT_008cacc8))) {
                operator_delete__(puVar5);
            }
            iVar7 = iVar7 + -1;
            *puVar4 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&DAT_008cacd0));
        } while (iVar7 != 0);
        return;
    }

    do {
        iVar3 = DAT_0085a26c;
        iVar7 = DAT_0085a268;
        if (DAT_008cac27 != 0) {
            bVar1 = true;
        }
        if (param_1 == 2) {
            FUN_004b24a0(DAT_008cabe8, 0);
        } else {
            local_12c = DAT_0085a268;
            local_128 = DAT_0085a26c;
            uVar6 = FUN_004cddf0(param_2, 0, 0, &local_128, &local_12c);
            FUN_004af080(uVar6, 0, 0, local_128, local_12c, 0, 0, iVar3, iVar7,
                         0xffffffffu, 0);
        }
        iVar3 = 0x41;
        piVar2 = &local_118;
        iVar7 = 0x17;
        do {
            iVar8 = *piVar2;
            if (*reinterpret_cast<int *>(static_cast<uintptr_t>(iVar8) - 4) != 0) {
                DAT_0085a11c = 0x4b;
                DAT_008c9de0 = DAT_008c9dd8;
                FUN_00509500(DAT_008c9dd8, iVar8, 0);
                FUN_004b06c0(static_cast<uint32_t>(iVar8), static_cast<uint32_t>(param_5),
                             static_cast<uint32_t>(iVar3), DAT_0085a11c, 0xffffffffu, 1,
                             0xffffffffu, 0);
                iVar3 = iVar3 + 0xf;
            }
            piVar2 = piVar2 + 3;
            iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        iVar7 = FUN_004b2760(0);
    } while ((iVar7 != 1) && (iVar7 != 0x1b) && (iVar7 != 0x20) && (!bVar1));

    puVar4 = &local_4;
    iVar7 = 0x17;
    do {
        piVar2 = puVar4 + -3;
        puVar4 = puVar4 + -3;
        puVar5 = reinterpret_cast<uint32_t *>(static_cast<uintptr_t>(*piVar2) - 8);
        if ((puVar5 != nullptr) &&
            (puVar5 != reinterpret_cast<uint32_t *>(&DAT_008cacc8))) {
            operator_delete__(puVar5);
        }
        iVar7 = iVar7 + -1;
        *puVar4 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&DAT_008cacd0));
    } while (iVar7 != 0);
}

// ===========================================================================
// 0x0043FD70
// ===========================================================================
// 0x0043fd70 — observed shape
// Threat/garrison score accumulator. Sums four dwords per 0x94-dword slot
// from DAT_0085c0b8 up to 0x85da28, converts that total into a 1000-step
// ladder against DAT_00869b14, adds the four DAT_00869a88..8e counters
// (each -1 + value), scans 0x54-byte records from DAT_00862018 adding one per
// empty/flagged slot, scans 0x128-byte records from DAT_0085bf78/0x860b90
// keeping the best (count + low-2-bits), folds in the 0x869b1c/1e pair, and
// finally adds per-ship-type flags for the 0x85a3b8/0x85a500/0x85a648 groups
// plus 10 when _DAT_0085a164 bit 0x80000 is set.
int FUN_0043fd70(void) {
    uint32_t *piVar1;
    uint32_t *piVar2;
    uint32_t *piVar3;
    uint8_t bVar4;
    uint32_t *piVar5;
    int iVar6;
    uint8_t *pbVar7;
    int16_t *psVar8;
    int iVar9;
    int iVar10;
    int iVar11;
    uint32_t *puVar12;
    int local_4;

    local_4 = 0;
    iVar9 = 0;
    piVar5 = &DAT_0085c0b8;
    do {
        piVar1 = piVar5 + -0x4a;
        piVar2 = piVar5 + -0x25;
        piVar3 = piVar5 + 0x25;
        iVar6 = static_cast<int>(*piVar5);
        piVar5 = piVar5 + 0x94;
        iVar9 = iVar9 + static_cast<int>(*piVar1) + static_cast<int>(*piVar2) +
                static_cast<int>(*piVar3) + iVar6;
    } while (reinterpret_cast<uintptr_t>(piVar5) < 0x85da28u);

    iVar11 = 0;
    iVar10 = 1;
    iVar6 = 1000;
    do {
        iVar11 = iVar11 + iVar6;
        if (iVar11 <= iVar9 * 500 + DAT_00869b14) {
            local_4 = iVar10;
        }
        iVar6 = iVar6 + 1000;
        iVar10 = iVar10 + 1;
    } while (iVar6 < 25000);

    if (DAT_00869a88 != 0) {
        local_4 = local_4 + -1 + static_cast<int>(DAT_00869a88);
    }
    if (DAT_00869a8a != 0) {
        local_4 = local_4 + -1 + static_cast<int>(DAT_00869a8a);
    }
    if (DAT_00869a8c != 0) {
        local_4 = local_4 + -1 + static_cast<int>(DAT_00869a8c);
    }
    if (DAT_00869a8e != 0) {
        local_4 = local_4 + -1 + static_cast<int>(DAT_00869a8e);
    }

    pbVar7 = &DAT_00862018;
    do {
        if (*reinterpret_cast<int *>(pbVar7 - 4) == 0) {
            local_4 = local_4 + 1;
        }
        if ((*pbVar7 & 1) != 0) {
            local_4 = local_4 + 1;
        }
        if (*reinterpret_cast<int *>(pbVar7 + 0x18) == 0) {
            local_4 = local_4 + 1;
        }
        if ((pbVar7[0x1c] & 1) != 0) {
            local_4 = local_4 + 1;
        }
        if (*reinterpret_cast<int *>(pbVar7 + 0x34) == 0) {
            local_4 = local_4 + 1;
        }
        if ((pbVar7[0x38] & 1) != 0) {
            local_4 = local_4 + 1;
        }
        pbVar7 = pbVar7 + 0x54;
    } while (reinterpret_cast<uintptr_t>(pbVar7) < 0x862114u);

    iVar9 = 0;
    puVar12 = &DAT_00860b90;
    psVar8 = &DAT_0085bf78;
    do {
        if (((*psVar8 != 0) && ((puVar12[-8] & 0x80000000u) == 0)) &&
            (iVar6 = static_cast<int>(*psVar8) +
                    (*reinterpret_cast<uint32_t *>(psVar8 - 2) & 3), iVar9 < iVar6)) {
            iVar9 = iVar6;
        }
        if (((psVar8[0x4a] != 0) && ((*puVar12 & 0x80000000u) == 0)) &&
            (iVar6 = static_cast<int>(psVar8[0x4a]) +
                    (*reinterpret_cast<uint32_t *>(psVar8 + 0x48) & 3),
             iVar9 < iVar6)) {
            iVar9 = iVar6;
        }
        if (((psVar8[0x94] != 0) && ((puVar12[8] & 0x80000000u) == 0)) &&
            (iVar6 = static_cast<int>(psVar8[0x94]) +
                    (*reinterpret_cast<uint32_t *>(psVar8 + 0x92) & 3),
             iVar9 < iVar6)) {
            iVar9 = iVar6;
        }
        if (((psVar8[0xde] != 0) && ((puVar12[0x10] & 0x80000000u) == 0)) &&
            (iVar6 = static_cast<int>(psVar8[0xde]) +
                    (*reinterpret_cast<uint32_t *>(psVar8 + 0xdc) & 3),
             iVar9 < iVar6)) {
            iVar9 = iVar6;
        }
        puVar12 = puVar12 + 0x20;
        psVar8 = psVar8 + 0x128;
    } while (reinterpret_cast<uintptr_t>(puVar12) < 0x861110u);

    local_4 = local_4 + iVar9 +
              (static_cast<int>(DAT_00869b1e) + static_cast<int>(DAT_00869b1c)) * 4;

    bVar4 = 8;
    iVar9 = 4;
    do {
        if (((DAT_0085a3b8 != 0) && (static_cast<int>(DAT_0085a4c8) > -1)) &&
            ((DAT_0085a4c8 & (1u << (bVar4 & 0x1f))) == 0)) {
            local_4 = local_4 + 1;
        }
        if (((DAT_0085a500 != 0) && (static_cast<int>(DAT_0085a610) > -1)) &&
            ((DAT_0085a610 & (1u << (bVar4 & 0x1f))) == 0)) {
            local_4 = local_4 + 1;
        }
        if (((DAT_0085a648 != 0) && (static_cast<int>(DAT_0085a758) > -1)) &&
            ((DAT_0085a758 & (1u << (bVar4 & 0x1f))) == 0)) {
            local_4 = local_4 + 2;
        }
        bVar4 = bVar4 + 1;
        iVar9 = iVar9 + -1;
    } while (iVar9 != 0);

    if ((_DAT_0085a164 & 0x80000u) != 0) {
        local_4 = local_4 + 10;
    }
    return local_4;
}

// ---------------------------------------------------------------------------
// Helpers/globals used by 0x438e30.
// ---------------------------------------------------------------------------
extern void     FUN_00431840(void);
extern void     FUN_00433cf0(void);
extern void     FUN_00436c30(int);
extern void     FUN_004337c0(int);
extern void     FUN_00433760(void);
extern void     FUN_00435260(void);
extern void     FUN_004f6090(const char *, ...);
extern int      FUN_0042e1d0(const char *);
extern void     FUN_0051bfc0(int *);
extern char     FUN_004ae900(int, int, int *, int *);
extern void     FUN_004888e0(int, uint32_t, uint32_t, uint32_t);
extern int      FUN_00431930(void);
extern int      FUN_00431970(void);
extern char     FUN_004318c0(void);
extern void     FUN_00432a60(int, int, int);
extern void     FUN_0043a0c0(void);
extern void     FUN_004b21a0(int, int, int, int);
extern void     FUN_004aa230(void);
extern void     FUN_00498570(void);
extern int      sprintf(char *, const char *, ...);

extern uint32_t (*timeGetTime_exref)(void);

extern int32_t  DAT_008ca974;
extern int32_t  DAT_008ca96c;
extern uint32_t DAT_0086c5d4;
extern uint32_t _DAT_008ed61c;
extern uint32_t DAT_008ed618;
extern int32_t  DAT_0086c584;
extern int32_t  DAT_008ca95c;
extern int32_t  DAT_008ca960;
extern uint8_t  DAT_0086fec4;
extern uint8_t  DAT_0086ea02;
extern int16_t  DAT_0086e9ec;
extern int32_t  DAT_0086bb5c;
extern int32_t  DAT_0086c35c;
extern int32_t  DAT_0086c354;
extern int32_t  DAT_0086c358;
extern int32_t  DAT_00725520;
extern int32_t  DAT_00725524;
extern int16_t  DAT_0086e9f8;
extern int16_t  DAT_0086e9fa;
extern uint32_t DAT_0086ea08;
extern int32_t  DAT_00725534;
extern uint8_t  DAT_00869b48;
extern uint8_t  DAT_0086c460;
extern int16_t  DAT_0086feb8;
extern int16_t  DAT_0086feba;
extern int16_t  DAT_0086feac;
extern int32_t  DAT_008ca970;
extern int32_t  DAT_0086c58c;
extern int32_t  DAT_0086c590;
extern int32_t  DAT_0086c588;
extern int32_t  DAT_0085a128;
extern int32_t  DAT_0085a124;
extern int32_t  DAT_0086c578;
extern int32_t  DAT_0086c574;
extern uint8_t  DAT_007263bb;
extern uint32_t DAT_0086c5d0;
extern int16_t  DAT_0086e9ea;
extern int32_t  DAT_008dc30c;
extern int32_t  DAT_008dc310;
extern int32_t  DAT_008ca980;
extern int32_t  DAT_00725530;
extern uint32_t DAT_0086c390;
extern uint32_t DAT_0086c394;
extern uint32_t DAT_0086c398;
extern uint32_t *DAT_0086c450;
extern uint32_t *DAT_0086c454;
extern uint32_t *DAT_0086c384;
extern uint32_t *DAT_0086c388;
extern uint32_t *DAT_0086c380;
extern uint32_t *DAT_0086c378;
extern uint32_t *DAT_0086c37c;
extern uint32_t *DAT_0086c374;
extern uint32_t *DAT_0086c370;
extern uint32_t DAT_00871368;
extern uint32_t DAT_008dc620;
extern int32_t  DAT_0086c36c;
extern int32_t  DAT_0086ea5c;
extern int32_t  DAT_0086ea8c;
extern uint8_t  DAT_0086ea00;
extern uint8_t  DAT_0086ea04;
extern uint8_t  DAT_00725538;

// ===========================================================================
// 0x00438E30
// ===========================================================================
// 0x00438e30 — observed shape
// Land-combat frame loop. Seeds the fight timers, ticks both AI sides
// (FUN_00436c30 0/1) while the pause bit _DAT_0085a164&4 is clear, runs the
// retreat/auto-retreat gates on DAT_008ca974 (-1000..1000), remaps the
// "Fight" keycode block 0x2c8..0x2d0 to command ids, latches Alt
// (GetAsyncKeyState(0x10)) into the 0x8000000 range, then dispatches the
// command through the nested switches (rotate/select/move/attack/pause/speed/
// end-turn). Per-frame pacing spins on timeGetTime until 30 ms elapse and
// stores the delta in DAT_00725530. On DAT_008cac27 it releases every staged
// object/vtable, calls FUN_00435140 and returns (resultFlag, strength, slot2).
uint32_t *FUN_00438e30(uint32_t *param_1, uint32_t in_EAX) {
    uint16_t *puVar1;
    int *piVar2;
    int16_t sVar3;
    uint32_t *puVar4;
    bool bVar5;
    int iVar6;
    char cVar7;
    SHORT SVar8;
    int iVar9;
    int iVar10;
    DWORD DVar11;
    int16_t *psVar12;
    uint32_t uVar13;
    uint32_t (*pcVar14)(void);
    uint32_t uVar15;
    uint32_t uVar17;
    int *piVar16;
    char *pcVar18;
    int iStack_198;
    int iStack_194;
    int iStack_190;
    int iStack_18c;
    int iStack_188;
    int local_184;
    int iStack_180;
    int iStack_17c;
    int aiStack_178[3];
    uint32_t uStack_16c = 0; // NEEDS_MANUAL: listing reads this slot without a store
    uint32_t uStack_168;
    uint8_t *puStack_108;
    char acStack_100[256];

    FUN_00431840();
    DAT_008ca974 = 0;
    DAT_008ca96c = 0;
    DAT_0086c5d4 = in_EAX;
    FUN_00433cf0();
    DAT_008ca974 = 0;

    pcVar14 = timeGetTime_exref;
    do {
        if ((_DAT_008ed61c & 1) == 0) {
            _DAT_008ed61c = _DAT_008ed61c | 1;
            DAT_008ed618 = (*pcVar14)();
        }
        local_184 = static_cast<int>((*pcVar14)());
        local_184 = local_184 - static_cast<int>(DAT_008ed618);
        DAT_008ca964 = 0;
        if ((_DAT_0085a164 & 4) == 0) {
            FUN_00436c30(0);
            FUN_00436c30(1);
            DAT_0086c584 = 0;
        }
        if ((((DAT_008ca95c == -1) ||
              (((DAT_008ca960 == 1 &&
                 (*reinterpret_cast<int16_t *>(
                      &DAT_0086fec4 + static_cast<ptrdiff_t>(DAT_008ca95c) * 0x14c) == 0)) ||
                (iVar9 = DAT_008ca960 * 0x10 + DAT_008ca95c,
                 *reinterpret_cast<int16_t *>(
                     &DAT_0086ea02 + static_cast<ptrdiff_t>(iVar9) * 0x14c) == -99)))) ||
             (99 < (&DAT_0086e9ec)[static_cast<ptrdiff_t>(iVar9) * 0xa6])) &&
            (DAT_008ca964 == 0)) {
            DAT_0086c584 = 1;
            FUN_004337c0(0);
        }
        FUN_00435260();
        if (1000 < DAT_008ca974) {
            pcVar18 = "The broken defenders scatter and run!\n";
        LAB_00439baf:
            FUN_004f6090(pcVar18);
            break;
        }
        if (DAT_008ca974 < -1000) {
            pcVar18 = "You LOSE!\n";
            goto LAB_00439baf;
        }
        iStack_194 = FUN_0042e1d0("Fight");
        if (DAT_0086bb5c != 0) {
            sprintf(acStack_100, "%s_%03X", "Fight", iStack_194);
            FUN_0051bfc0(&iStack_194);
        }
        iStack_198 = iStack_194;
        if ((0x2c7 < iStack_194) && (iStack_194 < 0x2d5)) {
            switch (iStack_194) {
            case 0x2c8: iStack_198 = 0x124; break;
            case 0x2c9: iStack_198 = 0x126; break;
            case 0x2ca: iStack_198 = 0x121; break;
            case 0x2cb: iStack_198 = 0x125; break;
            case 0x2cc: iStack_198 = 0x10c; break;
            case 0x2cd: iStack_198 = 0x127; break;
            case 0x2ce: iStack_198 = 0x123; break;
            case 0x2cf: iStack_198 = 0x128; break;
            case 0x2d0: iStack_198 = 0x122;
            }
            DAT_0086c35c = 0;
        }
        SVar8 = GetAsyncKeyState(0x10);
        if (((SVar8 != 0) && (iStack_198 != 0x50)) &&
            ((iStack_198 != 0x57 &&
              (((iStack_198 != 0x51 && (iStack_198 != 0x21)) && (iStack_198 != 0x54)))))) {
            iStack_198 = iStack_198 + 0x8000000;
        }
        if ((((_DAT_0085a164 & 4) == 0) && (DAT_008ca960 == 0)) &&
            (DAT_0086c35c != 0)) {
            cVar7 = FUN_004ae900(DAT_0086c354, DAT_0086c358, &iStack_180, &iStack_17c);
            iVar6 = iStack_17c;
            iVar9 = iStack_180;
            if (cVar7 == 0) goto LAB_004393ca;
            iStack_190 = DAT_008ca95c;
            iStack_194 = FUN_00436ac0(iStack_180, iStack_17c);
            iVar10 = FUN_00436ac0(iVar9, iVar6);
            uVar15 = static_cast<uint32_t>(
                         (iVar9 + DAT_00725520 * -1000 + 0x2134) / 1000) & 0x8000000fu;
            if (static_cast<int32_t>(uVar15) < 0) {
                uVar15 = ((uVar15 - 1) | 0xfffffff0u) + 1;
            }
            uVar17 = static_cast<uint32_t>(
                         (iVar6 + DAT_00725524 * -1000 + 0x2134) / 1000) & 0x8000000fu;
            if (static_cast<int32_t>(uVar17) < 0) {
                uVar17 = ((uVar17 - 1) | 0xfffffff0u) + 1;
            }
            iStack_18c = iVar10;
            if (DAT_0086c35c == 1) {
                if ((static_cast<int>((&DAT_0086e9f8)[static_cast<ptrdiff_t>(iStack_194) * 0xa6]) ==
                     static_cast<int>(uVar15)) &&
                    (static_cast<int>((&DAT_0086e9fa)[static_cast<ptrdiff_t>(iStack_194) * 0xa6]) ==
                     static_cast<int>(uVar17))) {
                    if ((&DAT_0086e9ec)[static_cast<ptrdiff_t>(iStack_194) * 0xa6] < 100) {
                        if ((static_cast<uint32_t>(
                                 (&DAT_0086ea08)[static_cast<ptrdiff_t>(iStack_194) * 0x53]) &
                             0x1000) == 0) {
                            FUN_004888e0(0xaa, 0xffffffffu, 0xffffffffu, 0xbf800000u);
                            DAT_00725534 = -1;
                            DAT_008ca95c = iStack_194;
                            FUN_00433760();
                        } else {
                            FUN_004f6090("That unit has already moved this turn.\n");
                            FUN_004879f0(0x28, 0);
                            iVar9 = 0;
                            do {
                                pcVar18 = reinterpret_cast<char *>(&DAT_00869b48 + iVar9);
                                (&DAT_0086c460)[iVar9] = *pcVar18;
                                iVar9 = iVar9 + 1;
                            } while (*pcVar18 != 0);
                            DAT_00725534 = 100;
                            FUN_00433760();
                        }
                    } else {
                        FUN_004f6090("That unit has been routed!\n");
                        FUN_004879f0(0x28, 0);
                        iVar9 = 0;
                        do {
                            pcVar18 = reinterpret_cast<char *>(&DAT_00869b48 + iVar9);
                            (&DAT_0086c460)[iVar9] = *pcVar18;
                            iVar9 = iVar9 + 1;
                        } while (*pcVar18 != 0);
                        DAT_00725534 = 100;
                        DAT_008ca95c = -1;
                        FUN_00433760();
                    }
                } else {
                    iVar9 = FUN_00431930();
                    if ((((&DAT_0086feb8)[static_cast<ptrdiff_t>(iVar10) * 0xa6] == iVar9) &&
                         (iVar9 = FUN_00431970(),
                          (&DAT_0086feba)[static_cast<ptrdiff_t>(iVar10) * 0xa6] == iVar9)) &&
                        ((&DAT_0086feac)[static_cast<ptrdiff_t>(iVar10) * 0xa6] < 100)) {
                        FUN_004f6090("That is an enemy unit.\n");
                        FUN_004879f0(0x28, 0);
                        iVar9 = 0;
                        do {
                            pcVar18 = reinterpret_cast<char *>(&DAT_00869b48 + iVar9);
                            (&DAT_0086c460)[iVar9] = *pcVar18;
                            iVar9 = iVar9 + 1;
                        } while (*pcVar18 != 0);
                        DAT_00725534 = 100;
                        DAT_008ca95c = iStack_190;
                    }
                    FUN_00433760();
                }
                goto LAB_004393ca;
            }
            if (DAT_0086c35c != 2) goto LAB_004393ca;
            if (((static_cast<int>((&DAT_0086e9f8)[static_cast<ptrdiff_t>(iStack_194) * 0xa6]) ==
                  static_cast<int>(uVar15)) &&
                 (static_cast<int>((&DAT_0086e9fa)[static_cast<ptrdiff_t>(iStack_194) * 0xa6]) ==
                  static_cast<int>(uVar17))) &&
                (SVar8 = GetAsyncKeyState(0x11), SVar8 == 0))
                goto LAB_004393c1;
            if (((DAT_008ca95c == -1) ||
                 (iVar9 = DAT_008ca960 * 0x10 + DAT_008ca95c,
                  uVar13 = static_cast<uint32_t>(static_cast<int>(
                      static_cast<uint32_t>(
                          static_cast<int>((&DAT_0086e9f8)[static_cast<ptrdiff_t>(iVar9) * 0xa6]) -
                          uVar15)) >> 0x1f),
                  1 < static_cast<int>(
                          ((static_cast<uint32_t>(
                                static_cast<int>(
                                    (&DAT_0086e9f8)[static_cast<ptrdiff_t>(iVar9) * 0xa6]) -
                                uVar15) ^ uVar13) - uVar13))) ||
                (uVar13 = static_cast<uint32_t>(static_cast<int>(
                     static_cast<uint32_t>(
                         static_cast<int>((&DAT_0086e9fa)[static_cast<ptrdiff_t>(iVar9) * 0xa6]) -
                         uVar17)) >> 0x1f),
                 1 < static_cast<int>(
                         ((static_cast<uint32_t>(
                               static_cast<int>(
                                   (&DAT_0086e9fa)[static_cast<ptrdiff_t>(iVar9) * 0xa6]) -
                               uVar17) ^ uVar13) - uVar13))) {
                if ((static_cast<int>(
                         (&DAT_0086feb8)[static_cast<ptrdiff_t>(iStack_18c) * 0xa6]) ==
                     static_cast<int>(uVar15)) &&
                    (static_cast<int>(
                         (&DAT_0086feba)[static_cast<ptrdiff_t>(iStack_18c) * 0xa6]) ==
                     static_cast<int>(uVar17))) {
                    bVar5 = false;
                    if ((DAT_0086c58c != 0) && (iVar9 = 0, 0 < DAT_0086c58c)) {
                        do {
                            if ((&DAT_0086c590)[static_cast<ptrdiff_t>(iVar9)] == iStack_18c) {
                                iStack_198 = 0x66;
                                bVar5 = true;
                            }
                            iVar9 = iVar9 + 1;
                        } while (iVar9 < DAT_0086c58c);
                        if (bVar5) goto LAB_004393ca;
                    }
                LAB_004393c1:
                    FUN_0043a0c0();
                }
                goto LAB_004393ca;
            }
            iVar9 = FUN_00431910();
            goto LAB_004395bf;
        }
    LAB_004393ca:
        iVar6 = DAT_008ca95c;
        iVar9 = DAT_0086c588;
        if (iStack_198 < 0x123) {
            if (iStack_198 == 0x122) {
                iVar9 = 5;
                goto LAB_004395bf;
            }
            if (iStack_198 < 0x67) {
                if (iStack_198 == 0x66) goto switchD_0043948a_caseD_10c;
                switch (iStack_198) {
                case 9:
                switchD_004393fe_caseD_9:
                    if ((((_DAT_0085a164 & 4) == 0) && (DAT_008ca960 == 0)) &&
                        (DAT_008ca95c != -1)) {
                        DAT_0086c588 = DAT_0086c588 + 1;
                        if (DAT_0086c58c <= DAT_0086c588) {
                            DAT_0086c588 = 0;
                        }
                        if ((iVar9 != DAT_0086c588) && (1 < DAT_0086c58c)) {
                            FUN_004888e0(0xad, 0xffffffffu, 0xffffffffu, 0xbf800000u);
                        }
                    }
                    break;
                case 0x1b:
                    piVar16 = reinterpret_cast<int *>(
                        static_cast<uint8_t *>(DAT_008ca984) + 0x4c48);
                    iVar9 = 6;
                    do {
                        if (*piVar16 != 0) {
                            puVar1 = reinterpret_cast<uint16_t *>(
                                static_cast<uintptr_t>(*piVar16) + 0x20);
                            *puVar1 = static_cast<uint16_t>(*puVar1 | 1);
                        }
                        piVar16 = piVar16 + 1;
                        iVar9 = iVar9 + -1;
                    } while (iVar9 != 0);
                    FUN_004b21a0(9, 0, 0, 1);
                    FUN_004aa230();
                    break;
                case 0x20:
                    goto switchD_004393fe_caseD_20;
                case 0x50:
                    goto switchD_004393fe_caseD_50;
                case 0x51:
                switchD_004393fe_caseD_51:
                    if (DAT_008ca974 == 0) {
                        DAT_008ca974 = -1;
                    }
                    break;
                case 0x61:
                    iVar9 = static_cast<int>(*reinterpret_cast<int16_t *>(
                        &DAT_0086ea00 +
                        static_cast<ptrdiff_t>(DAT_008ca960 * 0x10 + DAT_008ca95c) * 0x14c));
                    goto LAB_004395bf;
                case 99:
                switchD_004393fe_caseD_63:
                    if ((((_DAT_0085a164 & 4) == 0) && (DAT_008ca960 == 0)) &&
                        (DAT_008ca95c != -1)) {
                        DAT_0085a128 = (&DAT_0086ea5c)[
                            static_cast<ptrdiff_t>(DAT_008ca95c) * 0x53];
                        DAT_0085a124 = (&DAT_0086ea8c)[
                            static_cast<ptrdiff_t>(DAT_008ca95c) * 0x53];
                    }
                }
            } else {
                switch (iStack_198) {
                case 0x67:
                    goto switchD_0043948a_caseD_67;
                case 0x68:
                    DAT_007263bb = (DAT_007263bb == 0);
                    break;
                case 0x6e:
                    goto switchD_0043948a_caseD_6e;
                case 0x76:
                switchD_0043948a_caseD_76:
                    if (DAT_0085a128 != -1) {
                        DAT_0086c578 = DAT_0085a128;
                        DAT_0086c574 = DAT_0085a124;
                    }
                    _DAT_0085a164 = _DAT_0085a164 ^ 0x40;
                    break;
                case 0x10c:
                switchD_0043948a_caseD_10c:
                    if (((((_DAT_0085a164 & 4) == 0) && (DAT_0086c58c != 0)) &&
                         (DAT_008ca960 == 0)) &&
                        ((DAT_008ca95c != -1 &&
                          (cVar7 = FUN_004318c0(), cVar7 == 0)))) {
                        FUN_00432a60(DAT_008ca970, iVar6, 0xffffffff);
                    }
                    break;
                case 0x113:
                switchD_004393fe_caseD_50:
                    _DAT_0085a164 = _DAT_0085a164 ^ 4;
                    if ((_DAT_0085a164 & 4) == 0) {
                        puStack_108 = &DAT_008cacd0;
                        uStack_168 = 0x32;
                        FUN_004985e0();
                        FUN_004a14b0();
                        puStack_108 = &DAT_008cacd0;
                    } else {
                        FUN_00498570();
                    }
                    break;
                case 0x121:
                    iVar9 = 3;
                    goto LAB_004395bf;
                }
            }
        } else if (iStack_198 < 0x2d3) {
            if (iStack_198 == 0x2d2) {
                DAT_007263bb = 0;
            } else {
                switch (iStack_198) {
                case 0x123: iVar9 = 7; break;
                case 0x124: iVar9 = 1; break;
                case 0x125: iVar9 = 0; break;
                case 0x126: iVar9 = 2; break;
                case 0x127: iVar9 = 4; break;
                case 0x128: iVar9 = 6; break;
                default: goto switchD_004393fe_caseD_a;
                }
            LAB_004395bf:
                if ((((_DAT_0085a164 & 4) == 0) && (DAT_008ca960 == 0)) &&
                    ((DAT_008ca95c != -1 &&
                      (cVar7 = FUN_004318c0(), cVar7 == 0)))) {
                    FUN_00432a60(DAT_008ca970, DAT_008ca95c, iVar9);
                }
            }
        } else if (iStack_198 < 0x8000125) {
            if (iStack_198 == 0x8000124) {
            switchD_0043948a_caseD_6e:
                if ((((_DAT_0085a164 & 4) == 0) && (DAT_008ca960 == 0)) &&
                    (cVar7 = FUN_004318c0(), cVar7 == 0)) {
                    iVar9 = 0;
                    do {
                        DAT_0086c5d0 = DAT_0086c5d0 + 1 & 0x8000000fu;
                        if (static_cast<int32_t>(DAT_0086c5d0) < 0) {
                            DAT_0086c5d0 = (DAT_0086c5d0 - 1 | 0xfffffff0u) + 1;
                        }
                        if (((((&DAT_0086ea08)[static_cast<ptrdiff_t>(DAT_0086c5d0) * 0x53] &
                               0x1000) == 0) &&
                             ((&DAT_0086e9ea)[static_cast<ptrdiff_t>(DAT_0086c5d0) * 0xa6] != 0)) &&
                            ((&DAT_0086e9ec)[static_cast<ptrdiff_t>(DAT_0086c5d0) * 0xa6] < 100)) {
                            FUN_004888e0(0xad, 0xffffffffu, 0xffffffffu, 0xbf800000u);
                            FUN_004337c0(1);
                            break;
                        }
                        iVar9 = iVar9 + 1;
                    } while (iVar9 < 0x10);
                }
            } else if (iStack_198 < 0x8000122) {
                if (iStack_198 == 0x8000121) goto switchD_0043948a_caseD_76;
                if (iStack_198 == 0x2d3) {
                    DAT_007263bb = 1;
                } else if (iStack_198 == 0x800010c) {
                    goto switchD_004393fe_caseD_63;
                }
            } else if (iStack_198 == 0x8000122) {
                goto switchD_004393fe_caseD_51;
            }
        } else if (iStack_198 == 0x8000125) {
        switchD_0043948a_caseD_67:
            DAT_00725538 = (DAT_00725538 == 0);
        } else if (iStack_198 == 0x8000126) {
        switchD_004393fe_caseD_20:
            if (((((_DAT_0085a164 & 4) == 0) && (DAT_008ca960 == 0)) &&
                 (DAT_008ca95c != -1)) &&
                (cVar7 = FUN_004318c0(), cVar7 == 0)) {
                *reinterpret_cast<int16_t *>(&DAT_0086ea04 +
                                             static_cast<ptrdiff_t>(iVar6) * 0x14c) = 0;
                *reinterpret_cast<int16_t *>(&DAT_0086ea02 +
                                             static_cast<ptrdiff_t>(iVar6) * 0x14c) = -99;
                (&DAT_0086ea08)[static_cast<ptrdiff_t>(iVar6) * 0x53] =
                    (&DAT_0086ea08)[static_cast<ptrdiff_t>(iVar6) * 0x53] | 0x80;
                sVar3 = (&DAT_0086e9ec)[static_cast<ptrdiff_t>(iVar6) * 0xa6];
                (&DAT_0086e9ec)[static_cast<ptrdiff_t>(iVar6) * 0xa6] =
                    static_cast<int16_t>(
                        sVar3 - static_cast<int16_t>(
                                    (static_cast<int>(sVar3) +
                                     (static_cast<int>(sVar3) >> 0x1f & 3u)) >> 2));
                (&DAT_0086ea08)[static_cast<ptrdiff_t>(iVar6) * 0x53] =
                    (&DAT_0086ea08)[static_cast<ptrdiff_t>(iVar6) * 0x53] | 0x1000;
                FUN_004337c0(1);
            }
        } else if (iStack_198 == 0x8000127) {
            goto switchD_004393fe_caseD_9;
        }
    switchD_004393fe_caseD_a:
        if ((_DAT_0085a164 & 4) == 0) {
            if (2 >= DAT_008dc30c) {
                DAT_0086c574 = DAT_0086c574 + (DAT_00725530 * 1000) / 500;
                DAT_0085a128 = -1;
            }
            bVar5 = (DAT_0085a26c + -3 <= DAT_008dc30c);
            if (bVar5) {
                DAT_0086c574 = DAT_0086c574 + (DAT_00725530 * -1000) / 500;
                DAT_0085a128 = -1;
            }
            DAT_008ca980 = !bVar5 && 2 < DAT_008dc30c;
            if (DAT_008dc310 < 3) {
                DAT_0086c578 = DAT_0086c578 + (DAT_00725530 * 1000) / 500;
                DAT_0085a128 = -1;
                DAT_008ca980 = 0;
            }
            if (DAT_0085a268 + -3 <= DAT_008dc310) {
                DAT_0086c578 = DAT_0086c578 + (DAT_00725530 * -1000) / 500;
                DAT_0085a128 = -1;
                DAT_008ca980 = 0;
            }
        }
        iVar9 = (DAT_00725520 + -8) * 1000;
        if (DAT_0086c578 < iVar9) {
        LAB_00439a08:
            DAT_0086c578 = iVar9;
        } else {
            iVar9 = (DAT_00725520 + 8) * 1000;
            if (iVar9 < DAT_0086c578) goto LAB_00439a08;
        }
        iVar9 = (DAT_00725524 + -8) * 1000;
        if (DAT_0086c574 < iVar9) {
        LAB_00439a33:
            DAT_0086c574 = iVar9;
        } else {
            iVar9 = (DAT_00725524 + 8) * 1000;
            if (iVar9 < DAT_0086c574) goto LAB_00439a33;
        }
        if (((_DAT_0085a164 & 0x20) != 0) &&
            (cVar7 = FUN_004ae900(DAT_008dc30c, DAT_008dc310, &iStack_188, aiStack_178),
             cVar7 != 0)) {
            uVar15 = static_cast<uint32_t>(
                         (aiStack_178[0] + DAT_00725524 * -1000 + 0x2134) / 1000) & 0x8000000fu;
            if (static_cast<int32_t>(uVar15) < 0) {
                uVar15 = ((uVar15 - 1) | 0xfffffff0u) + 1;
            }
            uVar17 = static_cast<uint32_t>(
                         (iStack_188 + DAT_00725520 * -1000 + 0x2134) / 1000) & 0x8000000fu;
            if (static_cast<int32_t>(uVar17) < 0) {
                uVar17 = ((uVar17 - 1) | 0xfffffff0u) + 1;
            }
            FUN_004f6090("Square (@NUM, @NUM)", uVar17, uVar15);
            FUN_004b06c0(static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&DAT_00869b48)),
                         (static_cast<int>(DAT_0085a26c) +
                          (static_cast<uint32_t>(DAT_0085a26c) >> 0x1f & 3u)) >> 2,
                         (static_cast<int>(DAT_0085a268 * 0xf) +
                          (static_cast<uint32_t>(DAT_0085a268 * 0xf) >> 0x1f & 0xfu)) >> 4,
                         100, 0xffffffffu, 4, 0xffffffffu, 0);
        }
        iVar9 = local_184;
        pcVar14 = timeGetTime_exref;
        if ((_DAT_0085a164 & 4) == 0) {
            DAT_008ca96c = DAT_008ca96c + 1;
        }
        while (true) {
            if ((_DAT_008ed61c & 1) == 0) {
                _DAT_008ed61c = _DAT_008ed61c | 1;
                DAT_008ed618 = timeGetTime();
            }
            DVar11 = timeGetTime();
            if (0x1d < static_cast<int>((DVar11 - DAT_008ed618) - static_cast<uint32_t>(iVar9))) {
                break;
            }
            Sleep(2);
        }
        if ((_DAT_008ed61c & 1) == 0) {
            _DAT_008ed61c = _DAT_008ed61c | 1;
            DAT_008ed618 = timeGetTime();
        }
        DVar11 = timeGetTime();
        DAT_00725530 = static_cast<int32_t>((DVar11 - DAT_008ed618) - static_cast<uint32_t>(iVar9));
    } while (DAT_008cac27 == 0);

    iVar9 = 0;
    do {
        if ((iVar9 != 6) && ((&DAT_0086c390)[static_cast<ptrdiff_t>(iVar9) * 5] != 0)) {
            reinterpret_cast<void (*)(int)>(*reinterpret_cast<void **>(
                static_cast<uintptr_t>(
                    (&DAT_0086c390)[static_cast<ptrdiff_t>(iVar9) * 5])))(1);
        }
        if (((iVar9 == 0) || (iVar9 == 1)) || (iVar9 == 9)) {
            if ((&DAT_0086c394)[static_cast<ptrdiff_t>(iVar9) * 5] != 0) {
                reinterpret_cast<void (*)(int)>(*reinterpret_cast<void **>(
                    static_cast<uintptr_t>(
                        (&DAT_0086c394)[static_cast<ptrdiff_t>(iVar9) * 5])))(1);
            }
            if ((&DAT_0086c398)[static_cast<ptrdiff_t>(iVar9) * 5] != 0) {
                reinterpret_cast<void (*)(int)>(*reinterpret_cast<void **>(
                    static_cast<uintptr_t>(
                        (&DAT_0086c398)[static_cast<ptrdiff_t>(iVar9) * 5])))(1);
            }
            if (iVar9 == 9) {
                if (DAT_0086c450 != nullptr) {
                    reinterpret_cast<void (*)(int)>(*reinterpret_cast<void **>(DAT_0086c450))(1);
                }
                if (DAT_0086c454 != nullptr) {
                    reinterpret_cast<void (*)(int)>(*reinterpret_cast<void **>(DAT_0086c454))(1);
                }
            }
        }
        iVar9 = iVar9 + 1;
    } while (iVar9 < 10);

    piVar16 = reinterpret_cast<int *>(&DAT_00871368);
    do {
        iVar9 = 0x1a;
        do {
            if (*piVar16 != 0) {
                reinterpret_cast<void (*)(int)>(*reinterpret_cast<void **>(
                    static_cast<uintptr_t>(static_cast<uint32_t>(*piVar16))))(1);
                *piVar16 = 0;
            }
            piVar16 = piVar16 + 1;
            iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
    } while (reinterpret_cast<uintptr_t>(piVar16) < 0x871778u);

    if (DAT_0086c384 != nullptr) {
        reinterpret_cast<void (*)(int)>(*reinterpret_cast<void **>(DAT_0086c384))(1);
    }
    if (DAT_0086c388 != nullptr) {
        reinterpret_cast<void (*)(int)>(*reinterpret_cast<void **>(DAT_0086c388))(1);
    }
    if (DAT_0086c380 != nullptr) {
        reinterpret_cast<void (*)(int)>(*reinterpret_cast<void **>(DAT_0086c380))(1);
    }
    if (DAT_0086c378 != nullptr) {
        reinterpret_cast<void (*)(int)>(*reinterpret_cast<void **>(DAT_0086c378))(1);
    }
    if (DAT_0086c37c != nullptr) {
        reinterpret_cast<void (*)(int)>(*reinterpret_cast<void **>(DAT_0086c37c))(1);
    }
    if (DAT_0086c374 != nullptr) {
        reinterpret_cast<void (*)(int)>(*reinterpret_cast<void **>(DAT_0086c374))(1);
    }
    if (DAT_0086c370 != nullptr) {
        reinterpret_cast<void (*)(int)>(*reinterpret_cast<void **>(DAT_0086c370))(1);
    }

    piVar16 = reinterpret_cast<int *>(&DAT_008dc620);
    do {
        iVar9 = 0xc;
        do {
            puVar4 = reinterpret_cast<uint32_t *>(
                static_cast<uintptr_t>(static_cast<uint32_t>(piVar16[-0xc0])));
            if (puVar4 != nullptr) {
                piVar2 = reinterpret_cast<int *>(puVar4 + 1);
                *piVar2 = *piVar2 + -1;
                if (*piVar2 == 0) {
                    reinterpret_cast<void (*)(int)>(*reinterpret_cast<void **>(puVar4))(1);
                }
                piVar16[-0xc0] = 0;
            }
            puVar4 = reinterpret_cast<uint32_t *>(
                static_cast<uintptr_t>(static_cast<uint32_t>(*piVar16)));
            if (puVar4 != nullptr) {
                piVar2 = reinterpret_cast<int *>(puVar4 + 1);
                *piVar2 = *piVar2 + -1;
                if (*piVar2 == 0) {
                    reinterpret_cast<void (*)(int)>(*reinterpret_cast<void **>(puVar4))(1);
                }
                *piVar16 = 0;
            }
            piVar16 = piVar16 + 1;
            iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
    } while (reinterpret_cast<uintptr_t>(piVar16) < 0x8dc920u);

    FUN_00435140();

    uVar15 = 0;
    psVar12 = &DAT_0086e9ea;
    do {
        if (psVar12[-1] != -1) {
            uVar15 = uVar15 + static_cast<uint32_t>(*psVar12) *
                                  static_cast<uint32_t>(DAT_0086c36c);
        }
        psVar12 = psVar12 + 0xa6;
    } while (reinterpret_cast<uintptr_t>(psVar12) < 0x86feaau);

    *param_1 = static_cast<uint32_t>((0 < DAT_008ca974));
    param_1[1] = uVar15;
    param_1[2] = uStack_16c;
    return param_1;
}

// ---------------------------------------------------------------------------
// Helpers/globals used by 0x433cf0.
// ---------------------------------------------------------------------------
extern void     FUN_004e2df0(void);
extern void     FUN_004e8ea0(uint32_t);
extern void     FUN_004e7510(float, float, int);
extern uint16_t FUN_005f0ddc(void);
extern void     FUN_004ed370(float, float, float, uint32_t);
extern void     FUN_004e8860(uint32_t);
extern void     FUN_00412840(uint32_t, uint32_t);
extern void     FUN_004bdca0(int, int, int, int, int, uint32_t, int, int, int, int);
extern uint32_t FUN_004af680(int, const char *, int, int, int, int, uint32_t, int,
                              int, int, int, int);
extern uint32_t FUN_004bb500(int);
extern uint32_t FUN_004baaa0(int, const char *, const char *);
extern void     FUN_004bf760(uint32_t);
extern void     FUN_004c2200(int, int);
extern uint32_t FUN_00533db0(int);
extern void     FUN_00540c50(void);
extern void     FUN_004aac50(uint32_t **);
extern void     FUN_00534130(void);
extern void     FUN_00433ae0(void);
extern void     FUN_004aa950(void);
extern void     FUN_00431ed0(int);
extern void     FUN_00431c80(int, uint32_t, int, void *, uint32_t, int);

extern HCURSOR  DAT_008cacd8;
extern uint8_t  DAT_00007f02;
extern int32_t  DAT_0085a158;
extern uint8_t  DAT_008ca958;
extern uint8_t  DAT_008ca981;
extern uint32_t DAT_0072cd74;
extern int32_t  DAT_0086c5dc;
extern int32_t  DAT_0086c5d8;
extern int32_t  DAT_00725528;
extern int32_t  DAT_0072552c;
extern int32_t  DAT_0086c580;
extern int32_t  DAT_0086c57c;
extern uint32_t DAT_008ea000;
extern uint32_t DAT_0086c3a4;
extern uint32_t DAT_0086c3a8;
extern uint32_t DAT_0086c3ac;
extern uint32_t DAT_0086c3b8;
extern uint32_t DAT_0086c3cc;
extern uint32_t DAT_0086c3e0;
extern uint32_t DAT_0086c3f4;
extern uint32_t DAT_0086c41c;
extern uint32_t DAT_0086c430;
extern uint32_t _DAT_0086c444;
extern uint32_t DAT_0086c448;
extern uint32_t DAT_0086c44c;
extern uint32_t PTR_FUN_006fd14c;
extern uint32_t PTR_FUN_0070bed4;
extern int32_t  DAT_00727444;
extern uint8_t  DAT_00860b74;
extern uint32_t DAT_008e9ffc;
extern DWORD    DAT_008e8fdc;
extern uint32_t DAT_0086e1e0;
extern uint32_t DAT_0086d1e0;
extern uint32_t DAT_0086d9e0;
extern uint32_t DAT_0086c9e0;
extern uint8_t  DAT_0086c5e0;
extern uint16_t DAT_00871778;
extern int32_t  DAT_00869ab0;
extern uint8_t  DAT_00860b76;
extern uint16_t DAT_0086fea8;
extern uint8_t  DAT_00871a18;
extern uint32_t DAT_0086e9e8;

// ===========================================================================
// 0x00433CF0
// ===========================================================================
// 0x00433cf0 — observed shape
// Land-battle scene setup. Loads the battle cursor, tears down/rebuilds the
// refcounted state object, seeds the camera and delays from the +1000 map
// coordinates, allocates the 0xc0-byte battle actors (0x86c390..0x86c454
// block, the 0x871368 tree/model array, the 0x86c370..0x86c388 guards) and
// the land_battle_pc.kfm effect, releases the 0x8dc620/0x871368 pools, emits
// the lb_tree_NN.nif names through FUN_004c2200, primes the 16x16 grid tables
// (0x86e1e0/0x86d9e0/0x86c9e0/0x86c5e0, per-cell heights at 0x871778), then
// runs the spawn loop that fills the unit table at 0x86e9ec using the
// 0x871a18 occupancy grid until the troop budget or 999 slots are exhausted.
// param_1 is the battle-scene index (0x2c selects the "on deck" variant).
void FUN_00433cf0(int param_1) {
    int *piVar1;
    char *pcVar2;
    int iVar3;
    uint16_t uVar4;
    HCURSOR hCursor;
    uint32_t *puVar5;
    int iVar6;
    uint32_t *puVar7;
    uint32_t uVar8;
    DWORD DVar9;
    int16_t *psVar10;
    char cVar11;
    int iVar12;
    uint8_t *puVar13;
    int16_t *psVar14;
    uint32_t uVar15;
    uint16_t *puVar16;
    uint32_t uVar17;
    uint32_t uVar18;
    int iVar19;
    int *piVar20;
    uint32_t uVar21;
    uint32_t uVar22;
    bool bVar23;
    intptr_t puStack_134;
    intptr_t psStack_130;
    uint32_t uStack_12c;
    uint8_t *puStack_128;
    int iStack_124;
    uint32_t puStack_120;
    int iStack_11c;
    uint32_t uStack_118;
    int iStack_114;
    int iStack_110;
    int iStack_10c;
    HCURSOR local_108;
    char acStack_100[256];

    hCursor = DAT_008cacd8;
    if (DAT_008cacd8 == nullptr) {
        hCursor = LoadCursorA(static_cast<HINSTANCE>(nullptr),
                              reinterpret_cast<LPCSTR>(&DAT_00007f02));
    }
    local_108 = GetCursor();
    SetCursor(hCursor);

    FUN_0043a240();
    DAT_0086c458 = static_cast<int8_t>(_DAT_0085a164);

    puVar5 = reinterpret_cast<uint32_t *>(FUN_00500600());
    puVar7 = DAT_008e9fe4;
    if (DAT_008e9fe4 != puVar5) {
        if ((DAT_008e9fe4 != nullptr) &&
            (iVar6 = static_cast<int>(DAT_008e9fe4[1]),
             DAT_008e9fe4[1] = static_cast<uint32_t>(iVar6 - 1), iVar6 - 1 == 0)) {
            reinterpret_cast<void (*)(int)>(*reinterpret_cast<void **>(puVar7))(1);
        }
        DAT_008e9fe4 = puVar5;
        if (puVar5 != nullptr) {
            puVar5[1] = puVar5[1] + 1;
        }
    }

    DAT_00725538 = (DAT_0085a158 == 0);
    DAT_008ca958 = (param_1 == 0x2c);
    DAT_008ca981 = 0;
    DAT_008cabd4 = 0x4b0;
    FUN_004add70(0x4b0);
    DAT_0086c560 = *reinterpret_cast<uint8_t *>(static_cast<uintptr_t>(DAT_0072cd74) + 0xf0);
    DAT_0086c5dc = (DAT_00725520 + -8) * 1000;
    DAT_0086c5d8 = (DAT_00725524 + -8) * 1000;
    DAT_008c9df4 = 1;
    FUN_004e2df0();

    iVar3 = static_cast<int>(DAT_0072cd78);
    iVar19 = DAT_00725528;
    iVar6 = DAT_00725520;
    *reinterpret_cast<uint32_t *>(static_cast<uintptr_t>(DAT_0072cd78) + 0x10) =
        *reinterpret_cast<uint32_t *>(static_cast<uintptr_t>(DAT_0072cd78) + 0x14);
    iVar12 = DAT_0072552c;
    DAT_0086c580 = (iVar19 + -10 + iVar6) * 1000;
    DAT_0086c57c = (DAT_0072552c + -7 + DAT_00725524) * 1000;
    *reinterpret_cast<uint32_t *>(static_cast<uintptr_t>(iVar3) + 0x5c) = 10;
    *reinterpret_cast<uint8_t *>(static_cast<uintptr_t>(iVar3) + 0x80) = 1;
    if (DAT_0085a164 < 0) {
        FUN_004e8ea0(static_cast<uint32_t>(iVar3));
        iVar12 = DAT_0072552c;
    }

    puStack_134 = iVar12 * 1000 + 0x14e + DAT_0086c5d8;
    uStack_118 = static_cast<uint32_t>((DAT_00725528 + 1) * 1000 + DAT_0086c5dc);
    FUN_004e7510(static_cast<float>(static_cast<int>(uStack_118)),
                 static_cast<float>(static_cast<int>(puStack_134)), 1);
    iVar6 = static_cast<int>(FUN_005f0ddc());
    puStack_134 = (DAT_00725528 + 1) * 1000 + DAT_0086c5dc;
    FUN_004ed370(static_cast<float>(static_cast<int>(puStack_134)),
                 static_cast<float>(DAT_0072552c * 1000 + 0x14e + DAT_0086c5d8),
                 static_cast<float>(iVar6), 0x44fa0000u);
    if (DAT_008ca958 != 0) {
        puStack_134 = DAT_00725528 * 1000 + DAT_0086c5dc;
        FUN_004ed370(static_cast<float>(static_cast<int>(puStack_134)),
                     (static_cast<float>(DAT_0072552c) - 2.75f) * 1000.0f +
                         static_cast<float>(DAT_0086c5d8) - 666.0f,
                     static_cast<float>(iVar6), 0x447a0000u);
    }
    FUN_004e8860(DAT_0072cd78);
    FUN_004e7950(DAT_0072cd78, static_cast<uint32_t>(DAT_00725520 * 1000),
                 static_cast<uint32_t>(DAT_00725524 * 1000));

    iVar6 = static_cast<int>(DAT_0072cd78);
    iVar19 = 0;
    if (0 < *reinterpret_cast<int32_t *>(static_cast<uintptr_t>(DAT_0072cd78) + 0x58)) {
        do {
            FUN_004e9740();
            iVar19 = iVar19 + 1;
        } while (iVar19 < *reinterpret_cast<int32_t *>(static_cast<uintptr_t>(iVar6) + 0x58));
    }
    FUN_00412840(0x43fa0000u, 0x47435000u);

    // --- 0xc0-byte battle-actor allocation block (12 instances) ---
#define OMP_ALLOC_ACTOR(dst)                                                   \
    puVar7 = reinterpret_cast<uint32_t *>(FUN_00533c78(0xc0));                 \
    iVar6 = static_cast<int>(DAT_008ea000);                                    \
    if (puVar7 == nullptr) {                                                   \
        dst = 0;                                                               \
    } else {                                                                   \
        puVar7[1] = 0;                                                         \
        *puVar7 = static_cast<uint32_t>(                                       \
            reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c));                   \
        puVar7[7] = 0;                                                         \
        DAT_00727444 = DAT_00727444 + 1;                                       \
        puVar7[0x19] = 0;                                                      \
        puVar7[0x2f] = 0;                                                      \
        FUN_004bdca0(iVar6, 0, 0, 0, 0, 0xffffffffu, 0, 0, 0, 0);              \
        dst = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar7));      \
    }

    OMP_ALLOC_ACTOR(DAT_0086c390)
    OMP_ALLOC_ACTOR(DAT_0086c394)
    OMP_ALLOC_ACTOR(DAT_0086c398)
    OMP_ALLOC_ACTOR(DAT_0086c3a4)
    OMP_ALLOC_ACTOR(DAT_0086c3a8)
    OMP_ALLOC_ACTOR(DAT_0086c3ac)
    OMP_ALLOC_ACTOR(_DAT_0086c3b8)
    OMP_ALLOC_ACTOR(_DAT_0086c3cc)
    OMP_ALLOC_ACTOR(_DAT_0086c3e0)
    OMP_ALLOC_ACTOR(_DAT_0086c3f4)
    OMP_ALLOC_ACTOR(_DAT_0086c41c)
    OMP_ALLOC_ACTOR(_DAT_0086c430)
#undef OMP_ALLOC_ACTOR

    iVar6 = static_cast<int>(DAT_008ea000);
    if (DAT_008ea000 != 0) {
        *reinterpret_cast<int32_t *>(static_cast<uintptr_t>(DAT_008ea000) + 4) =
            *reinterpret_cast<int32_t *>(static_cast<uintptr_t>(DAT_008ea000) + 4) + 1;
    }
    _DAT_0086c444 = FUN_004af680(iVar6, "land_battle_pc.kfm", 0, 0, 0, 0, 0xffffffffu,
                                 0, 0, 0, 0, 0);
    DAT_0086c448 = FUN_004bb500(0);
    DAT_0086c44c = FUN_004bb500(0);
    DAT_0086c450 = reinterpret_cast<uint32_t *>(FUN_004bb500(0));
    DAT_0086c454 = reinterpret_cast<uint32_t *>(FUN_004bb500(0));

    uVar8 = FUN_004baaa0(0, "player_character_low.dds", "player_character_var01.dds");
    FUN_004bf760(uVar8);
    uVar8 = FUN_004baaa0(0, "player_character_low.dds", "player_character_var02.dds");
    FUN_004bf760(uVar8);
    uVar8 = FUN_004baaa0(0, "player_character_low.dds", "player_character_var03.dds");
    FUN_004bf760(uVar8);
    uVar8 = FUN_004baaa0(0, "player_character_low.dds", "player_character_var04.dds");
    FUN_004bf760(uVar8);

    piVar20 = reinterpret_cast<int *>(&DAT_008dc620);
    do {
        iVar6 = 0xc;
        do {
            puVar7 = reinterpret_cast<uint32_t *>(
                static_cast<uintptr_t>(static_cast<uint32_t>(piVar20[-0xc0])));
            if (puVar7 != nullptr) {
                piVar1 = reinterpret_cast<int *>(puVar7 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    reinterpret_cast<void (*)(int)>(*reinterpret_cast<void **>(puVar7))(1);
                }
                piVar20[-0xc0] = 0;
            }
            puVar7 = reinterpret_cast<uint32_t *>(
                static_cast<uintptr_t>(static_cast<uint32_t>(*piVar20)));
            if (puVar7 != nullptr) {
                piVar1 = reinterpret_cast<int *>(puVar7 + 1);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                    reinterpret_cast<void (*)(int)>(*reinterpret_cast<void **>(puVar7))(1);
                }
                *piVar20 = 0;
            }
            piVar20 = piVar20 + 1;
            iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
    } while (reinterpret_cast<uintptr_t>(piVar20) < 0x8dc920u);

    iStack_11c = 0;
    uStack_12c = 0;
    puVar7 = &DAT_00871368;
    puStack_128 = nullptr;
    do {
        iVar6 = 0;
        iStack_11c = iStack_11c + 1;
        do {
            sprintf(acStack_100, "lb_tree_%02d.nif", iStack_11c);
            if (iVar6 == 0) {
                uint32_t *pNew = reinterpret_cast<uint32_t *>(FUN_00533c78(0xc0));
                iVar19 = static_cast<int>(DAT_008ea000);
                if (pNew == nullptr) {
                    *reinterpret_cast<uint32_t *>(
                        reinterpret_cast<uintptr_t>(&DAT_00871368) +
                        reinterpret_cast<uintptr_t>(puStack_128)) = 0;
                } else {
                    pNew[1] = 0;
                    *pNew = static_cast<uint32_t>(
                        reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c));
                    pNew[7] = 0;
                    DAT_00727444 = DAT_00727444 + 1;
                    pNew[0x19] = 0;
                    pNew[0x2f] = 0;
                    FUN_004bdca0(iVar19, 0, 0, 0, 0, 0xffffffffu, 0, 0, 0, 0);
                    *reinterpret_cast<uint32_t *>(
                        reinterpret_cast<uintptr_t>(&DAT_00871368) +
                        reinterpret_cast<uintptr_t>(puStack_128)) =
                        static_cast<uint32_t>(reinterpret_cast<uintptr_t>(pNew));
                }
            } else {
                uVar8 = FUN_004bb500(0);
                (&DAT_00871368)[uStack_12c + static_cast<uint32_t>(iVar6)] = uVar8;
            }
            iVar6 = iVar6 + 1;
        } while (iVar6 < 0x1a);
        iVar6 = 0;
        {
            uint32_t *puVar7b = puVar7;
            do {
                FUN_004c2200(iVar6, 0);
                iVar6 = iVar6 + 4;
                puVar7b = puVar7b + 1;
            } while (iVar6 < 0x68);
            puVar7 = puVar7b;
        }
        puStack_128 = puStack_128 + 0x68;
        uStack_12c = uStack_12c + 0x1a;
    } while (reinterpret_cast<uintptr_t>(puStack_128) < 0x410u);

    puVar7 = reinterpret_cast<uint32_t *>(FUN_00533c78(0xc0));
    iVar6 = static_cast<int>(DAT_008ea000);
    if (puVar7 == nullptr) {
        DAT_0086c384 = nullptr;
    } else {
        puVar7[1] = 0;
        *puVar7 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c));
        puVar7[7] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar7[0x19] = 0;
        puVar7[0x2f] = 0;
        FUN_004bdca0(iVar6, 0, 0, 0, 0, 0xffffffffu, 0, 0, 0, 0);
        DAT_0086c384 = puVar7;
    }

    puVar7 = reinterpret_cast<uint32_t *>(FUN_00533c78(0xc0));
    iVar6 = static_cast<int>(DAT_008ea000);
    if (puVar7 == nullptr) {
        DAT_0086c388 = nullptr;
    } else {
        puVar7[1] = 0;
        *puVar7 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c));
        puVar7[7] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar7[0x19] = 0;
        puVar7[0x2f] = 0;
        FUN_004bdca0(iVar6, 0, 0, 0, 0, 0xffffffffu, 0, 0, 0, 0);
        DAT_0086c388 = puVar7;
    }

    if (DAT_008ca958 == 0) {
        cVar11 = static_cast<char>((&DAT_00860b74)[param_1 * 0x20]);
        if (cVar11 == 1) {
            puVar7 = reinterpret_cast<uint32_t *>(FUN_00533c78(0xc0));
            goto joined_r0x00434876;
        }
        if (cVar11 == 2) {
            puVar7 = reinterpret_cast<uint32_t *>(FUN_00533c78(0xc0));
            goto joined_r0x00434876;
        }
        if (cVar11 == 3) {
            puVar7 = reinterpret_cast<uint32_t *>(FUN_00533c78(0xc0));
            goto joined_r0x00434876;
        }
        puVar7 = reinterpret_cast<uint32_t *>(FUN_00533c78(0xc0));
        if (puVar7 != nullptr) goto LAB_0043488d;
    } else {
        puVar7 = reinterpret_cast<uint32_t *>(FUN_00533c78(0xc0));
    joined_r0x00434876:
        if (puVar7 != nullptr) {
        LAB_0043488d:
            iVar6 = static_cast<int>(DAT_008ea000);
            *puVar7 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c));
            puVar7[1] = 0;
            puVar7[7] = 0;
            puVar7[0x19] = 0;
            DAT_00727444 = DAT_00727444 + 1;
            puVar7[0x2f] = 0;
            FUN_004bdca0(iVar6, 0, 0, 0, 0, 0xffffffffu, 0, 0, 0, 0);
            DAT_0086c380 = puVar7;
            goto LAB_004348c8;
        }
    }
    DAT_0086c380 = nullptr;

LAB_004348c8:
    puVar7 = reinterpret_cast<uint32_t *>(FUN_00533c78(0xc0));
    iVar6 = static_cast<int>(DAT_008ea000);
    if (puVar7 == nullptr) {
        DAT_0086c378 = nullptr;
    } else {
        puVar7[1] = 0;
        *puVar7 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c));
        puVar7[7] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar7[0x19] = 0;
        puVar7[0x2f] = 0;
        FUN_004bdca0(iVar6, 0, 0, 0, 0, 0xffffffffu, 0, 0, 0, 0);
        DAT_0086c378 = puVar7;
    }

    puVar7 = reinterpret_cast<uint32_t *>(FUN_00533c78(0xc0));
    iVar6 = static_cast<int>(DAT_008ea000);
    if (puVar7 == nullptr) {
        DAT_0086c37c = nullptr;
    } else {
        puVar7[1] = 0;
        *puVar7 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c));
        puVar7[7] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar7[0x19] = 0;
        puVar7[0x2f] = 0;
        FUN_004bdca0(iVar6, 0, 0, 0, 0, 0xffffffffu, 0, 0, 0, 0);
        DAT_0086c37c = puVar7;
    }

    puVar7 = reinterpret_cast<uint32_t *>(FUN_00533c78(0xc0));
    iVar6 = static_cast<int>(DAT_008ea000);
    if (puVar7 == nullptr) {
        puVar7 = nullptr;
    } else {
        puVar7[1] = 0;
        *puVar7 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c));
        puVar7[7] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar7[0x19] = 0;
        puVar7[0x2f] = 0;
        FUN_004bdca0(iVar6, 0, 0, 0, 0, 0xffffffffu, 0, 0, 0, 0);
    }
    DAT_0086c374 = puVar7;
    puVar7[8] = puVar7[8] | 0x20000u;

    puVar7 = reinterpret_cast<uint32_t *>(FUN_00533c78(0xc0));
    {
        uint32_t uVar8b = DAT_008e9ffc;
        if (puVar7 == nullptr) {
            puVar7 = nullptr;
        } else {
            puVar7[1] = 0;
            *puVar7 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c));
            puVar7[7] = 0;
            DAT_00727444 = DAT_00727444 + 1;
            puVar7[0x19] = 0;
            puVar7[0x2f] = 0;
            FUN_004bdca0(static_cast<int>(uVar8b), 0, 0, 0, 0, 0xffffffffu, 0, 0, 0, 0);
        }
    }
    DAT_0086c370 = puVar7;

    if ((puVar7[0x14] == 0) ||
        (DVar9 = GetCurrentThreadId(), DAT_008e8fdc != DVar9)) {
        puVar7 = reinterpret_cast<uint32_t *>(FUN_00533db0(0xb));
        if (puVar7 == nullptr) {
            puVar7 = reinterpret_cast<uint32_t *>(FUN_00533c78(0x28));
            if (puVar7 == nullptr) {
                puVar7 = nullptr;
            } else {
                FUN_00540c50();
                *puVar7 = static_cast<uint32_t>(
                    reinterpret_cast<uintptr_t>(&PTR_FUN_0070bed4));
                *reinterpret_cast<uint16_t *>(
                    reinterpret_cast<uint8_t *>(puVar7) + 0x20) = 3;
                puVar7[9] = 3;
            }
            if (puVar7 != nullptr) {
                puVar7[1] = puVar7[1] + 1;
            }
            puStack_134 = static_cast<intptr_t>(reinterpret_cast<uintptr_t>(puVar7));
            FUN_004aac50(reinterpret_cast<uint32_t **>(&puStack_134));
            if (puVar7 != nullptr) {
                piVar20 = reinterpret_cast<int *>(puVar7 + 1);
                *piVar20 = *piVar20 + -1;
                if (*piVar20 == 0) {
                    reinterpret_cast<void (*)(int)>(*reinterpret_cast<void **>(puVar7))(1);
                }
            }
            FUN_00534130();
        }
        reinterpret_cast<uint8_t *>(puVar7)[0x20] =
            reinterpret_cast<uint8_t *>(puVar7)[0x20] & 0xfc;
    }

    FUN_00433ae0();
    FUN_0043a800(1);

    puVar7 = &DAT_0086e1e0;
    for (iVar6 = 0x200; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
    }
    puVar7 = &DAT_0086d1e0;
    for (iVar6 = 0x200; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
    }

    iStack_124 = 0;
    psStack_130 = 0;
    puStack_128 = &DAT_00871978;
    do {
        uStack_12c = 0;
        puVar13 = puStack_128;
        do {
            iVar6 = iStack_124;
            uVar17 = uStack_12c;
            cVar11 = static_cast<char>(puVar13[uStack_12c]);
            if (0 < cVar11) {
                if (cVar11 < 3) {
                    uVar21 = uStack_12c & 1u;
                    (&DAT_0086e1e0)[iStack_124] =
                        ((static_cast<uint32_t>(static_cast<int>(psStack_130)) - 8u) +
                         static_cast<uint32_t>(DAT_00725520)) * 1000u +
                        ((0u - static_cast<uint32_t>(uVar21 != 0)) & 0x8eu) - 0x47u;
                    uVar22 = static_cast<uint32_t>(psStack_130) & 1u;
                    (&DAT_0086d9e0)[iStack_124] =
                        ((uStack_12c - 8) + static_cast<uint32_t>(DAT_00725524)) * 1000u +
                        ((0u - static_cast<uint32_t>(uVar22 != 0)) & 0x8eu) - 0x47u;
                    (&DAT_0086c9e0)[iStack_124] = static_cast<int>(cVar11);
                    iVar19 = rand();
                    *reinterpret_cast<int16_t *>(&DAT_0086c5e0 + iVar6 * 2) =
                        static_cast<int16_t>(iVar19 % 10);
                    iVar6 = static_cast<int>(reinterpret_cast<uintptr_t>(DAT_008ca984));
                    uVar18 = static_cast<uint32_t>(psStack_130) & 0xfu;
                    uVar15 = uVar17 & 0xfu;
                    iVar19 = ((static_cast<uint32_t>(puStack_128[uVar17] != 0x01) * 0x10 +
                               uVar18) * 0x10 + uVar15);
                    *reinterpret_cast<uint16_t *>(
                        static_cast<uint8_t *>(DAT_008ca984) + 0x3448 +
                        static_cast<uintptr_t>(iVar19) * 4) =
                        static_cast<uint16_t>(
                            (0u - static_cast<uint32_t>(uVar21 != 0)) & 0x46u) -
                        static_cast<uint16_t>(0x23);
                    *reinterpret_cast<uint16_t *>(
                        static_cast<uint8_t *>(DAT_008ca984) + 0x344a +
                        static_cast<uintptr_t>(iVar19) * 4) =
                        static_cast<uint16_t>(
                            (0u - static_cast<uint32_t>(uVar22 != 0)) & 0x46u) -
                        static_cast<uint16_t>(0x23);
                    uVar17 = static_cast<uint32_t>(rand());
                    uVar17 = uVar17 & 0x80000001u;
                    if (static_cast<int32_t>(uVar17) < 0) {
                        uVar17 = ((uVar17 - 1) | 0xfffffffeu) + 1;
                    }
                    uVar21 = static_cast<uint32_t>(rand());
                    iVar6 = static_cast<int>(reinterpret_cast<uintptr_t>(DAT_008ca984));
                    uVar21 = uVar21 & 0x80000001u;
                    if (static_cast<int32_t>(uVar21) < 0) {
                        uVar21 = ((uVar21 - 1) | 0xfffffffeu) + 1;
                    }
                    iVar19 = static_cast<int>(uVar18 * 0x10 + uVar15);
                    *reinterpret_cast<int16_t *>(
                        static_cast<uint8_t *>(DAT_008ca984) + 0x1824 +
                        static_cast<uintptr_t>(iVar19) * 4) = static_cast<int16_t>(uVar21);
                    iStack_124 = iStack_124 + 1;
                    *reinterpret_cast<int16_t *>(
                        static_cast<uint8_t *>(DAT_008ca984) + 0x1826 +
                        static_cast<uintptr_t>(iVar19) * 4) = static_cast<int16_t>(uVar17);
                    puVar13 = puStack_128;
                } else if (cVar11 == 5) {
                    puVar13[uStack_12c] = 2;
                }
            }
            uStack_12c = uStack_12c + 1;
        } while (static_cast<int>(uStack_12c) < 0x10);
        puStack_128 = puVar13 + 0x10;
        psStack_130 = psStack_130 + 1;
    } while (static_cast<int>(puStack_128) < 0x871a78);

    psStack_130 = 0;
    puVar16 = &DAT_00871778;
    do {
        iVar6 = 0;
        do {
            puStack_134 = static_cast<intptr_t>(
                (iVar6 + DAT_00725524) * 1000 + -0x2134);
            uStack_118 = static_cast<uint32_t>(
                (static_cast<int>(psStack_130) + DAT_00725520) * 1000 - 0x2134);
            FUN_004e7510(static_cast<float>(static_cast<int>(uStack_118)),
                         static_cast<float>(static_cast<int>(puStack_134)), 0);
            uVar4 = FUN_005f0ddc();
            *puVar16 = uVar4;
            iVar19 = static_cast<int>(reinterpret_cast<uintptr_t>(DAT_008ca984));
            iVar6 = iVar6 + 1;
            puVar16 = puVar16 + 1;
        } while (iVar6 < 0x10);
        psStack_130 = psStack_130 + 1;
    } while (reinterpret_cast<uintptr_t>(puVar16) < 0x871978u);

    iVar6 = DAT_00725520 * 1000;
    *reinterpret_cast<uint16_t *>(static_cast<uint8_t *>(DAT_008ca984) + 0x180c) = 2;
    *reinterpret_cast<uint16_t *>(static_cast<uint8_t *>(DAT_008ca984) + 0x180e) = 2;
    *reinterpret_cast<uint16_t *>(static_cast<uint8_t *>(DAT_008ca984) + 0x1810) = 2;
    *reinterpret_cast<uint16_t *>(static_cast<uint8_t *>(DAT_008ca984) + 0x1812) = 2;
    puStack_134 = static_cast<intptr_t>(DAT_00725524 * 1000 + -0x2134);
    *reinterpret_cast<float *>(static_cast<uint8_t *>(DAT_008ca984) + 0x4c60) =
        static_cast<float>(iVar6 + -0x2134);
    *reinterpret_cast<float *>(static_cast<uint8_t *>(DAT_008ca984) + 0x4c64) =
        static_cast<float>(static_cast<int>(puStack_134));
    FUN_004aa950();

    puVar7 = &DAT_0086e9e8;
    for (iVar6 = 0xa60; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
    }

    iVar6 = (DAT_00869ab0 +
             static_cast<char>((&DAT_00860b76)[param_1 * 0x20]) * 0x14) / 0x50;
    if (iVar6 < 3) {
        iVar6 = 3;
    } else if (0x14 < iVar6) {
        iVar6 = 0x14;
    }
    puStack_128 = reinterpret_cast<uint8_t *>(static_cast<uintptr_t>(iVar6));
    _DAT_0085a164 = _DAT_0085a164 & 0xfffffffbu;
    DAT_0086c36c = iVar6;
    FUN_00431ed0(iVar6);

    iVar6 = DAT_00869ab0;
    iVar19 = rand();
    iStack_11c = static_cast<char>((&DAT_00860b76)[param_1 * 0x20]) * 0x14;
    iStack_124 = 0;
    uStack_12c = 0;
    psStack_130 = static_cast<intptr_t>(reinterpret_cast<uintptr_t>(&DAT_0086fea8));
    iStack_10c = iVar19 % 5 + 8;
    iStack_110 = iVar6 / 0x32 + 2;
    do {
        iVar6 = iStack_110;
        if (iStack_110 < 1) {
            iStack_114 = 0;
        } else {
            iStack_114 = rand();
            iStack_114 = iStack_114 % iVar6;
        }
        iStack_114 = iStack_114 + 4;
        if (iStack_114 < 6) {
            iStack_114 = 6;
        } else if (0xc < iStack_114) {
            iStack_114 = 0xc;
        }
        iVar6 = iStack_114;
        puStack_120 = 0xa;
        uVar17 = ((static_cast<int>(iStack_124 + uStack_12c + 1) / 2) /
                  static_cast<int>(
                      (0u - static_cast<uint32_t>(((iStack_124 + uStack_12c) & 1) != 0)) &
                          0xfffffffeu) +
                  1) +
                 iStack_10c;
        uVar17 = uVar17 & 0x8000000fu;
        if (static_cast<int32_t>(uVar17) < 0) {
            uVar17 = ((uVar17 - 1) | 0xfffffff0u) + 1;
        }
        uStack_118 = uVar17;
        if ((&DAT_00871a18)[uVar17] == 0x02) {
            puStack_134 = static_cast<intptr_t>(
                reinterpret_cast<uintptr_t>(&DAT_00871a18) + uVar17);
            do {
                iVar19 = 0;
                psVar14 = &DAT_0086e9ec;
                do {
                    iVar12 = 0;
                    psVar10 = psVar14;
                    do {
                        if (((psVar10[-1] != 0) && (*psVar10 < 100)) &&
                            (static_cast<uint32_t>(static_cast<int>(psVar10[6])) ==
                             puStack_120) &&
                            (static_cast<int>(psVar10[7]) == static_cast<int>(uVar17))) {
                            if (iVar19 * 0x100 + iVar12 == 0) goto LAB_00434f7b;
                            goto LAB_00434f5f;
                        }
                        iVar12 = iVar12 + 1;
                        psVar10 = psVar10 + 0xa6;
                    } while (iVar12 < 0x10);
                    psVar14 = psVar14 + 0xa60;
                    iVar19 = iVar19 + 1;
                } while (reinterpret_cast<uintptr_t>(psVar14) < 0x87136cu);
            LAB_00434f5f:
                if (static_cast<int32_t>(puStack_120) < 0) break;
                pcVar2 = reinterpret_cast<char *>(puStack_134 - 16);
                puStack_134 = puStack_134 - 16;
                puStack_120 = puStack_120 - 1;
            } while (*pcVar2 == 0x02);
        LAB_00434f7b:
            if (8 < static_cast<int32_t>(puStack_120)) goto LAB_00434f88;
            uStack_12c = uStack_12c + 1;
            cVar11 = static_cast<char>(DAT_008ca958);
        } else {
        LAB_00434f88:
            puVar7 = reinterpret_cast<uint32_t *>(static_cast<uintptr_t>(puStack_120));
            if (DAT_008ca958 == 0) {
                if (((static_cast<int>(psStack_130) < 0x87028c) ||
                     (iVar19 = rand(), iVar19 % 3 != 0)) ||
                    (uVar8 = 3, DAT_0085a158 == 0)) {
                    uVar8 = 2;
                }
            } else {
                if (0x87028b < static_cast<int>(psStack_130)) {
                    uVar15 = static_cast<uint32_t>(rand());
                    uVar15 = uVar15 & 0x80000001u;
                    bVar23 = (uVar15 == 0);
                    if (static_cast<int32_t>(uVar15) < 0) {
                        bVar23 = ((uVar15 - 1) | 0xfffffffeu) == 0xffffffffu;
                    }
                    uVar8 = 5;
                    if (bVar23) goto LAB_00434fe4;
                }
                uVar8 = 7;
            }
        LAB_00434fe4:
            FUN_00431c80(1, uVar8, iVar6, reinterpret_cast<void *>(puVar7), uVar17, 6);
            cVar11 = static_cast<char>(DAT_008ca958);
            iStack_11c = iStack_11c - iVar6 * static_cast<int>(
                                              reinterpret_cast<intptr_t>(puStack_128));
            if (((DAT_008ca958 == 0) && (*reinterpret_cast<int16_t *>(psStack_130) == 2)) &&
                (iStack_124 % (5 - DAT_0085a158) == 0)) {
                *reinterpret_cast<int16_t *>(psStack_130) = 8;
            }
            iStack_124 = iStack_124 + 1;
            psStack_130 = psStack_130 + 0x14c;
        }
        iVar6 = iStack_124;
        if ((iStack_11c / static_cast<int>(reinterpret_cast<intptr_t>(puStack_128)) < 5) ||
            (999 < static_cast<int>(uStack_12c))) {
            if (DAT_0085a158 != 0) {
                DAT_0086fea8 = static_cast<uint16_t>(8 - static_cast<uint16_t>(cVar11 != 0));
            }
            if (3 < iStack_124) {
                iVar19 = rand();
                if (iVar19 % 3 != 0) {
                    uVar17 = static_cast<uint32_t>(rand());
                    uVar17 = uVar17 & 0x80000001u;
                    if (static_cast<int32_t>(uVar17) < 0) {
                        uVar17 = ((uVar17 - 1) | 0xfffffffeu) + 1;
                    }
                    uVar15 = static_cast<uint32_t>(iVar6) - 1u & 0x8000000fu;
                    if (static_cast<int32_t>(uVar15) < 0) {
                        uVar15 = ((uVar15 - 1) | 0xfffffff0u) + 1;
                    }
                    (&DAT_0086fea8)[uVar15 * 0xa6] = static_cast<uint16_t>(
                        (0u - static_cast<uint32_t>(uVar17 != 0)) & 2u) + 5u;
                }
                iVar19 = rand();
                if (iVar19 % 3 != 0) {
                    uVar17 = static_cast<uint32_t>(rand());
                    uVar17 = uVar17 & 0x80000001u;
                    if (static_cast<int32_t>(uVar17) < 0) {
                        uVar17 = ((uVar17 - 1) | 0xfffffffeu) + 1;
                    }
                    uVar15 = static_cast<uint32_t>(iVar6) - 2u & 0x8000000fu;
                    if (static_cast<int32_t>(uVar15) < 0) {
                        uVar15 = ((uVar15 - 1) | 0xfffffff0u) + 1;
                    }
                    (&DAT_0086fea8)[uVar15 * 0xa6] = static_cast<uint16_t>(
                        (0u - static_cast<uint32_t>(uVar17 != 0)) & 2u) + 5u;
                }
            }
            SetCursor(local_108);
            return;
        }
    } while (true);
}


// ===== 0x435260 (delegated part, unified declarations) =====
extern void     FUN_004e43c0(int32_t);
extern void     FUN_004a8a70(int32_t, int32_t);
extern void     FUN_004881b0(int32_t, int32_t);
extern int32_t  FUN_004bbc80(int32_t, int32_t, uint32_t, void *, uint32_t,
                             uint32_t, uint32_t);
extern void     FUN_004aec30(int32_t, int32_t, int32_t, int32_t, uint32_t,
                             uint32_t, int32_t, int32_t, int32_t);
extern void     FUN_004bc950(void *, int32_t);
extern void     FUN_004bf9c0(void *, int32_t);
extern uint64_t FUN_004dadc0(float, int32_t, int32_t);
extern int32_t  FUN_004db210();
extern void     FUN_00432720(int32_t);
extern int32_t  FUN_00431e50(int32_t, int32_t);
extern int32_t  FUN_00431a60(int32_t, int32_t, uint32_t);
extern void     FUN_004aa340(int32_t, int32_t, int32_t, uint32_t);
extern void     FUN_004c1ac0(int32_t, int32_t, int32_t, int32_t, uint32_t,
                             const char *);
extern void     FUN_00431510(void);
extern void     FUN_00473b70(uint32_t, int32_t, int32_t);
extern char     FUN_00535b40(float *, int32_t *, float *);
extern void     FUN_005096b0(void);
extern int32_t  FUN_00489440(int32_t, int32_t, int32_t, int32_t);
extern int32_t  FUN_004953d0(int32_t);
extern void     FUN_004ad0c0(int32_t);
extern void     FUN_00433930(void);
extern void     FUN_004d0cd0(int32_t, int32_t, int32_t);
extern uint32_t  DAT_00726398;
extern int32_t   DAT_008ca97c;
extern int8_t    DAT_006fb6cc;
extern uint8_t   DAT_0086e9f0;       // per-tile int16 array, stride 0x14c
extern int32_t   DAT_0086ea18;       // per-tile int32 array, stride 0x53
extern uint8_t   DAT_0086eaec;       // per-unit int16 array, stride 2
extern uint8_t   DAT_0086ea2c;       // per-unit int32 array, stride 4
extern uint8_t   DAT_0086eabc;       // per-unit int32 array, stride 4
extern uint8_t   DAT_0086eb04;       // per-unit int16 array, stride 2
extern uint8_t   DAT_0086ea1c;       // per-tile byte array, stride 0x53
extern uintptr_t DAT_008dc320;       // array of owning object pointers
extern uint8_t  *PTR_DAT_00725694;   // per-faction object table
extern uint8_t   DAT_0086feb6;       // unit-record array base (stride 0x14c)
extern int8_t    DAT_00725418;       // per-faction char table, stride 7
extern int8_t    DAT_0072541b;       // per-faction char table, stride 7
extern int8_t    DAT_0072541c;       // per-faction char table, stride 7
extern int8_t    DAT_0072541e;       // per-faction char table, stride 7
extern uint8_t   DAT_0086fec8;       // per-unit byte flags, stride 0x14c
extern int32_t   DAT_00725350;       // 8-direction dx table
extern int32_t   DAT_007252f0;       // 8-direction dy table
extern int32_t   DAT_0086c330;
extern int32_t   DAT_0086c568;
extern int32_t   DAT_0086c56c;
extern int32_t   DAT_0086c570;
extern int32_t   DAT_0086c564;
extern int32_t   DAT_008cac18;

// 0x00435260 — observed shape
void FUN_00435260(uint32_t extraout_EDX) {
    // Stack slots of the listing (offsets preserved through the names).
    uint32_t local_1ac = 0;
    int32_t  local_1a8 = 0;
    char     local_1a1 = '\0';
    uint32_t local_1a0 = 0;
    uint32_t local_19c = 0;
    int32_t  local_198 = 0;
    int32_t  local_194 = 0;
    uint32_t local_190 = 0;
    uint32_t local_18c = 0;
    uint32_t local_188 = 0;
    float    local_184 = 0.0f;
    int32_t  local_180 = 0;
    int32_t  local_17c = 0;
    uint8_t  uStack_178 = 0;
    uint8_t  uStack_177 = 0;
    uint8_t  uStack_176 = 0;
    uint8_t  uStack_175 = 0;
    float    fStack_174 = 0.0f;
    float    fStack_170 = 0.0f;
    float    fStack_16c = 0.0f;
    uint8_t  local_168[72] = {};      // tile/scene query output buffer
    uint8_t  local_120[216] = {};     // unit query output buffer
    uint8_t  auStack_48[36] = {};     // displacement result buffer
    uint8_t  auStack_24[36] = {};     // displacement result buffer
    // The listing reads the eight stack bytes at local_168[-0x14..-0xd]; the
    // same slab is written as local_17c = 0x02010003 and uStack_178..175.
    uint8_t  stackDirs[8] = {0x03, 0x00, 0x01, 0x02, 5, 8, 7, 6};

    int32_t  iVar9 = 0;
    int32_t  iVar15 = 0;
    int32_t  iVar16 = 0;
    int32_t  iVar17 = 0;
    int32_t  iVar18 = 0;
    int32_t  iVar20 = 0;
    uint32_t uVar10 = 0;
    uint32_t uVar11 = 0;
    uint32_t uVar21 = 0;
    uint32_t uVar13 = 0;
    uint32_t uVar24 = 0;
    float    fVar2 = 0.0f;
    float    fVar6 = 0.0f;
    int16_t  sVar3 = 0;
    SHORT    SVar8 = 0;
    char     cVar7 = 0;
    bool     bVar22 = false;
    char    *pcVar25 = nullptr;

    local_1a1 = '\0';
    if (DAT_00726398 == 3) {
        FUN_004e43c0(2);
    }
    FUN_004a8a70(DAT_0086c578, DAT_0086c574);
    FUN_004e7950(DAT_0072cd78, DAT_00725520 * 1000, DAT_00725524 * 1000);

    {
        uint8_t *pBase = DAT_008ca984;
        cVar7 = DAT_00725538;
        iVar9 = *reinterpret_cast<int32_t *>(pBase + 0x4c58);
        if (iVar9 != 0) {
            uint8_t *pObj = reinterpret_cast<uint8_t *>(static_cast<intptr_t>(iVar9));
            if (DAT_00725538 == '\0') {
                pObj[0x20] = static_cast<uint8_t>(pObj[0x20] | 1);
            } else {
                pObj[0x20] = static_cast<uint8_t>(pObj[0x20] & 0xfe);
            }
        }
        *reinterpret_cast<bool *>(pBase + 9) = (cVar7 == '\0');
    }

    // ---- turn banner / battle-report text -------------------------------
    if (DAT_008ca974 == 0) {
        if (DAT_008ca960 == 0) {
            FUN_004f6090("Pirate Turn");
        } else {
            if (DAT_008ca958 == '\0') {
                iVar9 = static_cast<int32_t>(static_cast<char>(DAT_00860b74[DAT_0086c5d4 * 0x20]));
            } else {
                iVar9 = 5;
            }
            FUN_004f6090("@NATIONALITY Turn", iVar9);
        }
        if (DAT_008ca97c == 0) {
            iVar9 = DAT_0085a26c / 3;
            if (iVar9 < 0x19) {
                FUN_004af080(0, 0, 0, 0, 0, iVar9, 10, iVar9, 0x18, 0x80000000u, 0);
            } else {
                FUN_004881b0(iVar9, 10);
            }
            iVar9 = 0xc;
            goto LAB_00435453;
        }
    } else {
        FUN_004f6090(reinterpret_cast<const char *>(&DAT_006fb6cc), DAT_008ca974);
        if (DAT_008ca974 < 1) {
            FUN_004f6090("The remnants of your crew withdraw from the battle.");
            DAT_0085a128 = DAT_0086ea5c;
            DAT_0085a124 = DAT_0086ea8c;
        } else if (DAT_008ca981 == '\0') {
            FUN_004f6090("The broken defenders scatter and run!");
        } else {
            FUN_004f6090("You have reached the fort's gates!");
            DAT_0085a128 = DAT_0086c580;
            DAT_0085a124 = DAT_0086c57c;
        }
        _DAT_0085a164 = _DAT_0085a164 | 0x40;
        iVar9 = DAT_0085a268 / 2 + -8;
LAB_00435453:
        FUN_004b06c0(static_cast<uint32_t>(reinterpret_cast<intptr_t>(&DAT_00869b48)),
                     static_cast<uint32_t>(DAT_0085a26c / 2),
                     static_cast<uint32_t>(iVar9),
                     static_cast<uint32_t>(DAT_0085a11c), 0xffffffffu, 4,
                     0xffffffffu, 0);
    }

    // ---- per-tile upkeep (two layers, 16x12 tiles each) -----------------
    local_194 = 0;
    do {
        local_188 = static_cast<uint32_t>(local_194) << 4;
        local_18c = 0;
        do {
            fVar2 = static_cast<float>(local_188 + local_18c);
            iVar9 = static_cast<int32_t>(fVar2) * 0x14c;
            local_184 = fVar2;
            if (DAT_0086e9ea[static_cast<int32_t>(fVar2) * 0xa6] != 0) {
                if (local_194 != 0) {
                    if ((DAT_0086ea08[static_cast<int32_t>(fVar2) * 0x53] & 2) == 0) {
                        if (*reinterpret_cast<int16_t *>(&DAT_0086e9f0 + iVar9) != 0) {
                            uVar10 = static_cast<uint32_t>(rand());
                            uVar10 = uVar10 & 0x80000001u;
                            bVar22 = uVar10 == 0;
                            if (static_cast<int32_t>(uVar10) < 0) {
                                bVar22 = (uVar10 - 1u | 0xfffffffeu) == 0xffffffffu;
                            }
                            if (!bVar22) {
                                *reinterpret_cast<int16_t *>(&DAT_0086e9f0 + iVar9) =
                                    static_cast<int16_t>(
                                        *reinterpret_cast<int16_t *>(&DAT_0086e9f0 + iVar9) + -1);
                            }
                        }
                    } else if (*reinterpret_cast<int16_t *>(&DAT_0086e9f0 + iVar9) < 0xc) {
                        uVar10 = static_cast<uint32_t>(rand());
                        uVar10 = uVar10 & 0x80000001u;
                        bVar22 = uVar10 == 0;
                        if (static_cast<int32_t>(uVar10) < 0) {
                            bVar22 = (uVar10 - 1u | 0xfffffffeu) == 0xffffffffu;
                        }
                        if (!bVar22) {
                            *reinterpret_cast<int16_t *>(&DAT_0086e9f0 + iVar9) =
                                static_cast<int16_t>(
                                    *reinterpret_cast<int16_t *>(&DAT_0086e9f0 + iVar9) + 1);
                        }
                    }
                }
                if ((_DAT_0085a164 & 0x20) != 0) {
                    FUN_004f6090(reinterpret_cast<const char *>(&DAT_006fb6cc), local_18c);
                    uVar10 = DAT_0086ea08[static_cast<int32_t>(fVar2) * 0x53];
                    if ((uVar10 & 0x20) != 0) {
                        uint8_t *puVar19 = reinterpret_cast<uint8_t *>(0x869b47);
                        do {
                            pcVar25 = reinterpret_cast<char *>(puVar19 + 1);
                            puVar19 = puVar19 + 1;
                        } while (*pcVar25 != '\0');
                        *reinterpret_cast<uint16_t *>(puVar19) = 0x43;
                    }
                    if ((uVar10 & 0x10) != 0) {
                        uint8_t *puVar19 = reinterpret_cast<uint8_t *>(0x869b47);
                        do {
                            pcVar25 = reinterpret_cast<char *>(puVar19 + 1);
                            puVar19 = puVar19 + 1;
                        } while (*pcVar25 != '\0');
                        *reinterpret_cast<uint16_t *>(puVar19) = 0x46;
                    }
                    FUN_004aec30((&DAT_0086ea5c)[static_cast<int32_t>(fVar2) * 0x53],
                                 (&DAT_0086ea8c)[static_cast<int32_t>(fVar2) * 0x53],
                                 (&DAT_0086ea18)[static_cast<int32_t>(fVar2) * 0x53] + 400,
                                 0, 0xc0000000u, 0x40000000u, 1000, 0xc, 0);
                }

                local_17c = static_cast<int32_t>(local_184) * 0x53;
                local_180 = 0;
                do {
                    iVar17 = local_17c + local_180;
                    iVar18 = iVar17 * 4;
                    iVar15 = (&DAT_0086ea5c)[iVar17];
                    if ((iVar15 != 0) &&
                        (((local_194 == 0 ||
                           (local_180 < *reinterpret_cast<int16_t *>(&DAT_0086e9f0 + iVar9))) ||
                          (*reinterpret_cast<int16_t *>(
                               &DAT_0086eaec +
                               (static_cast<int32_t>(local_184) * 0xa6 + local_180) * 2) == 0x77)) ||
                         ((*reinterpret_cast<int16_t *>(
                               &DAT_0086eaec +
                               (static_cast<int32_t>(local_184) * 0xa6 + local_180) * 2) == 0x70) ||
                          ((_DAT_0085a164 & 0x20) != 0)))) {
                        local_19c = static_cast<uint32_t>((&DAT_0086ea8c)[iVar17]);
                        local_1a0 = static_cast<uint32_t>(iVar15);
                        FUN_004e7510(static_cast<float>(iVar15),
                                     static_cast<float>(static_cast<int32_t>(local_19c)), 0);
                        local_1a0 = FUN_005f0ddc();
                        if (local_180 == 0) {
                            (&DAT_0086ea18)[static_cast<int32_t>(fVar2) * 0x53] =
                                static_cast<int32_t>(local_1a0);
                        }
                        local_198 = (static_cast<int32_t>(local_184) * 0xa6 + local_180) * 2;
                        sVar3 = *reinterpret_cast<int16_t *>(&DAT_0086eaec + local_198);
                        local_1a8 = static_cast<int32_t>(sVar3);
                        local_190 = static_cast<uint32_t>(sVar3);
                        if ((local_190 == 100) &&
                            ((('\x04' <
                               DAT_00725418[static_cast<int16_t>(
                                                (&DAT_0086e9e8)[static_cast<int32_t>(fVar2) * 0xa6]) *
                                            7]) ||
                              (sVar3 <= (&DAT_0086e9ec)[static_cast<int32_t>(fVar2) * 0xa6])) ||
                             ((DAT_0086ea08[static_cast<int32_t>(fVar2) * 0x53] & 0x40) != 0)) &&
                            ((&DAT_0086e9e8)[static_cast<int32_t>(fVar2) * 0xa6] != 4)) {
                            local_190 = 0x65;
                        }

                        uVar10 = static_cast<uint32_t>(
                                     ((&DAT_0086ea5c)[static_cast<int32_t>(fVar2) * 0x53] +
                                      DAT_00725520 * -1000 + 0x2134) /
                                     1000) &
                                 0x8000000fu;
                        if (static_cast<int32_t>(uVar10) < 0) {
                            uVar10 = (uVar10 - 1u | 0xfffffff0u) + 1u;
                        }
                        uVar11 = static_cast<uint32_t>(
                                     ((&DAT_0086ea8c)[static_cast<int32_t>(fVar2) * 0x53] +
                                      DAT_00725524 * -1000 + 0x2134) /
                                     1000) &
                                 0x8000000fu;
                        if (static_cast<int32_t>(uVar11) < 0) {
                            uVar11 = (uVar11 - 1u | 0xfffffff0u) + 1u;
                        }
                        if (((DAT_00871978[uVar11 + uVar10 * 0x10] == '\x01') &&
                             ((&DAT_0086e9e8)[static_cast<int32_t>(fVar2) * 0xa6] != 4)) &&
                            ((&DAT_0086e9e8)[static_cast<int32_t>(fVar2) * 0xa6] != 3)) {
                            if (local_190 == 100) {
                                local_190 = 200;
                            } else if (local_190 == 0x6e) {
                                local_190 = 0xd2;
                            }
                        }
                        if (((&DAT_0086e9e8)[static_cast<int32_t>(fVar2) * 0xa6] == 3) &&
                            (sVar3 == 100)) {
                            local_190 = 0x65;
                        }

                        if (((local_180 == 0) &&
                             (*reinterpret_cast<int16_t *>(
                                  &DAT_0086eaec + static_cast<int32_t>(local_184) * 0x14c) != 0x77)) &&
                            ((&DAT_0086e9ec)[static_cast<int32_t>(fVar2) * 0xa6] < 100)) {
                            if ((DAT_0086ea08[static_cast<int32_t>(fVar2) * 0x53] & 0x1000) == 0) {
                                local_19c = static_cast<uint32_t>(
                                    (DAT_008ca96c + static_cast<int32_t>(local_18c) * 3) * 0x1e);
                            } else {
                                local_19c = 0;
                            }
                            if ((((local_194 == 0) &&
                                  (static_cast<int32_t>(local_18c) == DAT_008ca95c)) ||
                                 (local_194 == 0)) &&
                                (static_cast<int32_t>(local_18c) == DAT_008ca95c)) {
                                iVar15 = 400;
                            } else {
                                iVar15 = (&DAT_0086e9ec)[static_cast<int32_t>(fVar2) * 0xa6] * -4 + 0xfa;
                            }
                            iVar16 = (&DAT_0086ea8c)[local_17c];
                            iVar20 = (&DAT_0086ea5c)[local_17c];
                            FUN_004dadc0(0x3fc90fdb, 0, 0);
                            iVar15 = FUN_004bbc80(iVar20, iVar16,
                                                  local_1a0 - static_cast<uint32_t>(iVar15),
                                                  local_168, extraout_EDX, 0xffffffffu, local_19c);
                            if (local_194 == 0) {
                                iVar16 = 4;
                            } else {
                                iVar16 = static_cast<int32_t>(
                                    static_cast<char>(DAT_00860b74[DAT_0086c5d4 * 0x20]));
                            }
                            iVar20 = 3 - static_cast<int32_t>(
                                             (&DAT_0086e9ec)[static_cast<int32_t>(fVar2) * 0xa6]) /
                                             0x19;
                            if (iVar20 < 0) {
                                iVar20 = 0;
                            } else if (3 < iVar20) {
                                iVar20 = 3;
                            }
                            uint8_t *puVar4 = (&PTR_DAT_00725694)[iVar16];
                            if (*reinterpret_cast<int32_t *>(static_cast<intptr_t>(iVar15) + 0xbc) != 0) {
                                FUN_004bc950(puVar4, iVar20);
                            }
                            FUN_004bf9c0(puVar4, iVar20);
                        }

                        sVar3 = (&DAT_0086e9e8)[static_cast<int32_t>(fVar2) * 0xa6];
                        if (((local_194 == 0) &&
                             ((&DAT_0086e9e8)[static_cast<int32_t>(local_18c) * 0xa6] == 9)) &&
                            (local_1a1 == '\0')) {
                            local_1a1 = '\x01';
                        }

                        iVar15 = *reinterpret_cast<int32_t *>(
                            reinterpret_cast<uint8_t *>(&DAT_0086ea2c) + iVar18);
                        local_19c = 100u - static_cast<uint32_t>((iVar15 * 5) / 2);
                        local_19c = local_19c &
                                    static_cast<uint32_t>(
                                        (static_cast<int32_t>(local_19c) < 0) - 1);
                        if (iVar15 == 0) {
LAB_00435c05:
                            local_1a8 = static_cast<int32_t>(
                                static_cast<uint32_t>(*reinterpret_cast<int32_t *>(
                                    reinterpret_cast<uint8_t *>(&DAT_0086eabc) + iVar18)) +
                                0x80000000u);
                            FUN_004dadc0(static_cast<float>(local_1a8) * 1.4629181e-09f, 0, 0);
                            uVar10 = local_1a0;
                            FUN_004bbc80((&DAT_0086ea5c)[iVar17], (&DAT_0086ea8c)[iVar17],
                                         local_1a0, local_120,
                                         static_cast<uint32_t>(
                                             (static_cast<int32_t>(DAT_0072541e[sVar3 * 7]) * 100) / 2),
                                         local_190,
                                         static_cast<uint32_t>(*reinterpret_cast<int16_t *>(
                                             &DAT_0086eb04 + local_198)));
                        } else if (static_cast<int32_t>(local_19c) < 1) {
                            if ((iVar15 == 0) || (0 < static_cast<int32_t>(local_19c))) {
                                goto LAB_00435c05;
                            }
                            iVar15 = local_180 + static_cast<int32_t>(local_184) * 0xc;
                            void **puVar5 = reinterpret_cast<void **>((&DAT_008dc320)[iVar15]);
                            if (puVar5 != nullptr) {
                                int32_t *piVar1 = reinterpret_cast<int32_t *>(puVar5) + 1;
                                *piVar1 = *piVar1 + -1;
                                if (*piVar1 == 0) {
                                    (*reinterpret_cast<void (**)(int32_t)>(*puVar5))(1);
                                }
                                (&DAT_008dc320)[iVar15] = 0;
                            }
                            uVar10 = local_1a0;
                        } else {
                            iVar16 = local_180 + static_cast<int32_t>(local_184) * 0xc;
                            iVar20 = static_cast<int32_t>((&DAT_008dc320)[iVar16]);
                            *reinterpret_cast<int32_t *>(
                                reinterpret_cast<uint8_t *>(&DAT_0086ea2c) + iVar18) = iVar15 + 1;
                            if (iVar20 == 0) {
                                void **puVar12 = reinterpret_cast<void **>(FUN_004bb500(0));
                                void **puVar5 = reinterpret_cast<void **>((&DAT_008dc320)[iVar16]);
                                if (puVar5 != puVar12) {
                                    if (puVar5 != nullptr) {
                                        int32_t *piVar1 = reinterpret_cast<int32_t *>(puVar5) + 1;
                                        *piVar1 = *piVar1 + -1;
                                        if (*piVar1 == 0) {
                                            (*reinterpret_cast<void (**)(int32_t)>(*puVar5))(1);
                                        }
                                    }
                                    (&DAT_008dc320)[iVar16] = reinterpret_cast<uintptr_t>(puVar12);
                                    if (puVar12 != nullptr) {
                                        reinterpret_cast<int32_t *>(puVar12)[1] =
                                            reinterpret_cast<int32_t *>(puVar12)[1] + 1;
                                    }
                                }
                            }
                            FUN_004c2200(local_19c, 0);
                            local_1a8 = static_cast<int32_t>(
                                static_cast<uint32_t>(*reinterpret_cast<int32_t *>(
                                    reinterpret_cast<uint8_t *>(&DAT_0086eabc) + iVar18)) +
                                0x80000000u);
                            FUN_004dadc0(static_cast<float>(local_1a8) * 1.4629181e-09f, 0, 0);
                            uVar10 = local_1a0;
                            FUN_004bbc80((&DAT_0086ea5c)[iVar17], (&DAT_0086ea8c)[iVar17],
                                         local_1a0, auStack_24,
                                         static_cast<uint32_t>(
                                             (static_cast<int32_t>(
                                                  DAT_0072541e[static_cast<int16_t>(
                                                                   (&DAT_0086e9e8)[static_cast<int32_t>(fVar2) * 0xa6]) *
                                                               7]) *
                                              100) /
                                             2),
                                         local_190,
                                         static_cast<uint32_t>(*reinterpret_cast<int16_t *>(
                                             &DAT_0086eb04 + local_198)));
                        }

                        iVar15 = local_198;
                        if ((*reinterpret_cast<int16_t *>(&DAT_0086eaec + local_198) != 0x77) &&
                            (0 < static_cast<int32_t>(local_19c))) {
                            local_1a8 = static_cast<int32_t>(
                                static_cast<uint32_t>(*reinterpret_cast<int32_t *>(
                                    reinterpret_cast<uint8_t *>(&DAT_0086eabc) + iVar18)) +
                                0x80000000u);
                            uVar13 = static_cast<uint32_t>(
                                FUN_004dadc0(static_cast<float>(local_1a8) * 1.4629181e-09f, 0, 0));
                            FUN_004bbc80((&DAT_0086ea5c)[iVar17],
                                         (&DAT_0086ea8c)[iVar17] + 0x1e, uVar10, uVar13, 200,
                                         0xffffffffu, 0);
                        }

                        if (((*reinterpret_cast<int16_t *>(&DAT_0086eaec + iVar15) == 0x70) &&
                             ((sVar3 = (&DAT_0086e9e8)[static_cast<int32_t>(fVar2) * 0xa6],
                               DAT_0072541b[sVar3 * 7] != '\0'))) &&
                            (sVar3 != 5)) {
                            local_1a0 = static_cast<uint32_t>(*reinterpret_cast<int32_t *>(
                                reinterpret_cast<uint8_t *>(&DAT_0086eabc) + iVar18));
                            fVar6 = static_cast<float>(static_cast<int32_t>(local_1a0)) *
                                    1.4629181e-09f;
                            uint8_t *puVar14;
                            if (sVar3 == 8) {
                                FUN_004dadc0(fVar6, 0, 0);
                                iVar15 = *reinterpret_cast<int16_t *>(&DAT_0086eb04 + iVar15) * 2 + -0x4d8;
                                puVar14 = auStack_48;
LAB_00435cb8:
                                uVar24 = 0xffffffffu;
                                uVar13 = 0x96;
                                iVar16 = static_cast<int32_t>(uVar10) + 0xbb;
                                iVar18 = FUN_004db210(iVar16, puVar14, 0x96, 0xffffffff, iVar15);
                                iVar18 = iVar18 + (&DAT_0086ea8c)[iVar17];
                            } else {
                                if (sVar3 != 4) {
                                    puVar14 = reinterpret_cast<uint8_t *>(static_cast<uintptr_t>(
                                        FUN_004dadc0(fVar6, 0, 0)));
                                    iVar15 = static_cast<int32_t>(
                                                 *reinterpret_cast<int16_t *>(&DAT_0086eb04 + iVar15))
                                             << 1;
                                    goto LAB_00435cb8;
                                }
                                puVar14 = reinterpret_cast<uint8_t *>(static_cast<uintptr_t>(
                                    FUN_004dadc0(fVar6, 0, 0)));
                                iVar15 = static_cast<int32_t>(
                                    *reinterpret_cast<int16_t *>(&DAT_0086eb04 + iVar15));
                                uVar24 = 0xffffffffu;
                                uVar13 = 300;
                                iVar16 = static_cast<int32_t>(uVar10) + 0x7d;
                                iVar18 = FUN_004db210(iVar16, puVar14, 300, 0xffffffff, iVar15);
                                iVar18 = iVar18 + (&DAT_0086ea8c)[iVar17];
                            }
                            iVar20 = FUN_004db210(iVar18);
                            FUN_004bbc80(iVar20 + (&DAT_0086ea5c)[iVar17], iVar18,
                                         static_cast<uint32_t>(iVar16), puVar14, uVar13, uVar24,
                                         static_cast<uint32_t>(iVar15));
                        }
                    }
                    local_180 = local_180 + 1;
                } while (local_180 < 0xc);
            }
            local_18c = local_18c + 1;
        } while (static_cast<int32_t>(local_18c) < 0x10);
        local_194 = local_194 + 1;
    } while (local_194 < 2);

    // ---- per-object scene pass (0x200 entries) --------------------------
    uVar10 = 0;
    do {
        uVar11 = static_cast<uint32_t>((&DAT_0086e1e0)[uVar10]);
        if (uVar11 != 0) {
            if ((&DAT_0086d1e0)[uVar10] == 0) {
                local_1a8 = (&DAT_0086d9e0)[uVar10];
                local_188 = uVar11;
                FUN_004e7510(static_cast<float>(static_cast<int32_t>(uVar11)),
                             static_cast<float>(local_1a8), 1);
                iVar9 = static_cast<int32_t>(FUN_005f0ddc());
                (&DAT_0086d1e0)[uVar10] = iVar9;
                if (iVar9 == 0) {
                    (&DAT_0086e1e0)[uVar10] = 0;
                    goto LAB_00435fa3;
                }
            }
            if ((&DAT_0086c9e0)[uVar10] == 1) {
                FUN_00432720(0);
                uVar13 = static_cast<uint32_t>(FUN_004dadc0(0x3f490fdb, 0, 0));
                FUN_004bbc80((&DAT_0086e1e0)[uVar10], (&DAT_0086d9e0)[uVar10],
                             static_cast<uint32_t>((&DAT_0086d1e0)[uVar10]), uVar13, 0x57,
                             0xffffffffu, 0);
            }
            if ((&DAT_0086c9e0)[uVar10] == 2) {
                local_1a8 = static_cast<int32_t>(uVar10 << 0x1e);
                uVar13 = static_cast<uint32_t>(FUN_004dadc0(
                    static_cast<float>(local_1a8) * 1.4629181e-09f, 0, 0));
                FUN_004bbc80((&DAT_0086e1e0)[uVar10] + 0xfa, (&DAT_0086d9e0)[uVar10],
                             static_cast<uint32_t>((&DAT_0086d1e0)[uVar10]), uVar13, 0x32,
                             0xffffffffu, 0);
                local_1a8 = static_cast<int32_t>((uVar10 & 3) * 0xc0000000u);
                uVar13 = static_cast<uint32_t>(FUN_004dadc0(
                    static_cast<float>(local_1a8) * 1.4629181e-09f, 0, 0));
                FUN_004bbc80((&DAT_0086e1e0)[uVar10], (&DAT_0086d9e0)[uVar10],
                             static_cast<uint32_t>((&DAT_0086d1e0)[uVar10]), uVar13, 0x32,
                             0xffffffffu, 0);
            }
            iVar9 = (&DAT_0086e1e0)[uVar10];
            if ((iVar9 == DAT_00725528) && ((&DAT_0086d9e0)[uVar10] == DAT_0072552c)) {
                local_1a8 = static_cast<int32_t>(uVar10 * 0x40000000u + 0x20000000u);
                uint64_t uVar23 = FUN_004dadc0(
                    static_cast<float>(local_1a8) * 1.4629181e-09f, 0, 0);
                FUN_004bbc80(iVar9, static_cast<int32_t>(uVar23 >> 0x20),
                             static_cast<uint32_t>((&DAT_0086d1e0)[uVar10] + 10),
                             static_cast<uint32_t>(uVar23), 0x78, 0xffffffffu, 0);
            }
        }
LAB_00435fa3:
        uVar10 = uVar10 + 1;
    } while (static_cast<int32_t>(uVar10) < 0x200);

    uVar13 = static_cast<uint32_t>(FUN_004dadc0(0x40060a92, 0, 0));
    FUN_004bbc80((DAT_00725528 + 1) * 1000 + DAT_0086c5dc,
                 DAT_0072552c * 1000 + 0x14e + DAT_0086c5d8, 0, uVar13, 0x15e, 0xffffffffu, 0);

    // ---- currently selected land unit ----------------------------------
    uVar10 = static_cast<uint32_t>(DAT_008ca95c);
    if ((DAT_008ca95c != -1) && (DAT_008ca974 == 0)) {
        local_188 = static_cast<uint32_t>(DAT_008ca95c);
        local_1a0 = static_cast<uint32_t>(DAT_008ca95c * 0x14c);
        fStack_174 = static_cast<float>((&DAT_0086ea5c)[DAT_008ca95c * 0x53]);
        fStack_170 = static_cast<float>((&DAT_0086ea8c)[DAT_008ca95c * 0x53]);
        fStack_16c = static_cast<float>((&DAT_0086ea18)[DAT_008ca95c * 0x53]);
        local_1a1 = FUN_00535b40(&fStack_174, &local_1a8, &local_184);
        local_184 = 1.0f - local_184;
        uVar13 = FUN_005f0ddc();
        if (local_1a1 == '\0') {
            if (DAT_008ca980 != '\0') {
                DAT_0085a128 = (&DAT_0086ea5c)[uVar10 * 0x53];
                DAT_0085a124 = (&DAT_0086ea8c)[uVar10 * 0x53];
            }
            DAT_008ca980 = '\x01';
        } else {
            iVar9 = static_cast<int32_t>(FUN_005f0ddc());
            FUN_004f6090("@NUM @LAND_PARTY",
                         static_cast<int32_t>(static_cast<int16_t>(
                             DAT_0086e9ea[uVar10 * 0xa6])) *
                             DAT_0086c36c,
                         static_cast<int32_t>(static_cast<int16_t>(
                             (&DAT_0086e9e8)[uVar10 * 0xa6])));
            DAT_0085a11c = 0x50;
            FUN_004b06c0(static_cast<uint32_t>(reinterpret_cast<intptr_t>(&DAT_00869b48)),
                         uVar13, static_cast<uint32_t>(iVar9 - 0x38), 0x50, 0xffffffffu, 4,
                         0xffffffffu, 0);
            switch (static_cast<int32_t>((&DAT_0086e9ec)[uVar10 * 0xa6]) / 0x19) {
            case 0:
                pcVar25 = "";
                break;
            case 1:
                pcVar25 = "Angry, ";
                break;
            case 2:
                pcVar25 = "Wavering, ";
                break;
            case 3:
                pcVar25 = "Panicked, ";
                break;
            default:
                pcVar25 = "Routed, ";
            }
            FUN_004f6090(pcVar25);
            if (*reinterpret_cast<int16_t *>(
                    reinterpret_cast<uint8_t *>(&DAT_0086ea04) +
                    (DAT_008ca960 * 0x10 + DAT_008ca95c) * 0x14c) < 2) {
                FUN_004f60b0("1 move");
            } else {
                FUN_004f60b0("@NUM moves",
                             static_cast<int32_t>(*reinterpret_cast<int16_t *>(
                                 reinterpret_cast<uint8_t *>(&DAT_0086ea04) +
                                 (DAT_008ca960 * 0x10 + DAT_008ca95c) * 0x14c)));
            }
            DAT_0085a11c = 0x43;
            if ((DAT_008ca960 == 0) && (DAT_008ca974 == 0)) {
                FUN_004b06c0(static_cast<uint32_t>(reinterpret_cast<intptr_t>(&DAT_00869b48)),
                             uVar13, static_cast<uint32_t>(iVar9 - 0x2a), 0x43, 0xffffffffu, 4,
                             0xffffffffu, 0);
            }

            // Eight movement directions; bit index comes from the stack slab.
            local_1ac = 0;
            local_190 = 0;
            local_198 = 0;
            local_17c = 0x2010003;
            uStack_178 = 5;
            uStack_177 = 8;
            uStack_176 = 7;
            uStack_175 = 6;
            stackDirs[0] = 0x03;
            stackDirs[1] = 0x00;
            stackDirs[2] = 0x01;
            stackDirs[3] = 0x02;
            stackDirs[4] = uStack_178;
            stackDirs[5] = uStack_177;
            stackDirs[6] = uStack_176;
            stackDirs[7] = uStack_175;
            do {
                iVar17 = static_cast<int32_t>(*reinterpret_cast<int16_t *>(
                             reinterpret_cast<uint8_t *>(&DAT_0086e9fa) + local_1a0)) +
                         (&DAT_00725350)[local_198];
                uVar10 = 1u << (stackDirs[local_198] & 0x1f);
                iVar15 = static_cast<int32_t>(*reinterpret_cast<int16_t *>(
                             reinterpret_cast<uint8_t *>(&DAT_0086e9f8) + local_1a0)) +
                         (&DAT_007252f0)[local_198];
                local_190 = local_190 | uVar10;
                local_19c = uVar10;
                iVar9 = FUN_00431e50(iVar15, iVar17);
                if (iVar9 == -1) {
                    iVar9 = FUN_00431e50(iVar15, iVar17);
                    if ((iVar9 != -1) && ((DAT_0086fec8[iVar9 * 0x14c] & 2) != 0)) {
                        uVar11 = 1u << (stackDirs[local_198] & 0x1f);
                        local_1ac = local_1ac | uVar11;
                        local_190 = local_190 & ~uVar11;
                    }
                    if (DAT_00871978[iVar17 + iVar15 * 0x10] == '\x02') {
                        local_1ac = local_1ac | (1u << (stackDirs[local_198] & 0x1f));
                    }
                } else {
                    local_1ac = local_1ac | (1u << (stackDirs[local_198] & 0x1f));
                }
                if ((iVar15 < 0) || (0xf < iVar15)) {
                    local_1ac = local_1ac | uVar10;
                }
                if ((iVar17 < 0) || (0xf < iVar17)) {
                    local_1ac = local_1ac | uVar10;
                }
                if (((((DAT_008ca960 == 0) && (-1 < iVar15)) && (iVar15 < 0x10)) &&
                     ((-1 < iVar17) && (iVar17 < 0x10))) &&
                    ((DAT_0086ea1c[DAT_008ca95c * 0x53] == 0) &&
                     ((DAT_0086ea08[DAT_008ca95c * 0x53] & 0x70) == 0))) {
                    uint32_t blocked = local_1ac & local_19c;
                    FUN_004aa340(iVar15, iVar17,
                                 static_cast<int32_t>((((0u - blocked) & 0x00ffffffu) << 8) |
                                                      static_cast<uint32_t>(1 - (blocked != 0))),
                                 0x3f800000u);
                    blocked = local_190 & local_19c;
                    FUN_004aa340(iVar15, iVar17,
                                 static_cast<int32_t>((((0u - blocked) & 0x00ffffffu) << 8) |
                                                      static_cast<uint32_t>(1 - (blocked != 0))),
                                 0x3f800000u);
                }
                local_198 = local_198 + 1;
            } while (local_198 < 8);

            // Nearest hostile unit, for the targeting cursor.
            DAT_0086c58c = 0;
            local_19c = 100000;
            local_17c = -1;
            if ((DAT_0086ea08[local_1a0] & 0x60) == 0) {
                short *pScan = reinterpret_cast<short *>(&DAT_0086feb6);
                local_198 = 0;
                do {
                    if (((pScan[-7] != -1) && (*pScan != 0)) &&
                        (((reinterpret_cast<uint8_t *>(pScan)[0x12] & 2) != 0) &&
                         (pScan[-5] < 100))) {
                        iVar17 = *reinterpret_cast<int32_t *>(
                            reinterpret_cast<uint8_t *>(pScan) + 0x96);
                        iVar15 = *reinterpret_cast<int32_t *>(
                            reinterpret_cast<uint8_t *>(pScan) + 0x66);
                        iVar9 = iVar17 - *reinterpret_cast<int32_t *>(
                                              reinterpret_cast<uint8_t *>(&DAT_0086ea8c) +
                                              local_1a0);
                        iVar18 = iVar15 - *reinterpret_cast<int32_t *>(
                                               reinterpret_cast<uint8_t *>(&DAT_0086ea5c) +
                                               local_1a0);
                        if (iVar18 < 0) {
                            iVar18 = -iVar18;
                        }
                        if (iVar9 < 0) {
                            iVar9 = -iVar9;
                        }
                        if (iVar9 < iVar18) {
                            iVar9 = iVar9 + iVar18 * 2;
                        } else {
                            iVar9 = iVar18 + iVar9 * 2;
                        }
                        local_18c = static_cast<uint32_t>(iVar9 / 2);
                        if ((static_cast<int32_t>(local_18c) <=
                             static_cast<int32_t>(
                                 DAT_0072541c[*reinterpret_cast<int16_t *>(
                                     reinterpret_cast<uint8_t *>(&DAT_0086e9e8) +
                                     local_1a0) *
                                              7]) *
                                     1000 +
                                 0x29a) &&
                            (iVar9 = FUN_00431a60(
                                 *reinterpret_cast<int32_t *>(
                                     reinterpret_cast<uint8_t *>(&DAT_0086ea5c) + local_1a0),
                                 0, local_188),
                             iVar9 != 0)) {
                            if ((DAT_0086c588 != DAT_0086c58c) ||
                                ((DAT_008ca96c & 4) != 0)) {
                                FUN_004c1ac0(
                                    DAT_0086c370, iVar15, iVar17,
                                    static_cast<int32_t>(*reinterpret_cast<int16_t *>(
                                        reinterpret_cast<uint8_t *>(&DAT_0086ea00) +
                                        local_1a0)) << 0x1d,
                                    (static_cast<uint32_t>(DAT_0086c588 != DAT_0086c58c) - 1u &
                                     0xfu) +
                                        0x2du,
                                    "lb_target.dds");
                            }
                            if (static_cast<int32_t>(local_18c) <
                                static_cast<int32_t>(local_19c)) {
                                local_19c = local_18c;
                                local_17c = DAT_0086c58c;
                            }
                            (&DAT_0086c590)[DAT_0086c58c] = local_198;
                            DAT_0086c58c = DAT_0086c58c + 1;
                        }
                    }
                    pScan += 0xa6;
                    local_198 = local_198 + 1;
                } while (reinterpret_cast<intptr_t>(pScan) < 0x871376);
            }
            if (DAT_0086c588 == -1) {
                DAT_0086c588 = local_17c;
            }
            DAT_0086c330 = 0;
            FUN_00431510();
            SVar8 = GetAsyncKeyState(0x11);
            if (SVar8 == 0) {
                SVar8 = GetAsyncKeyState(0x10);
                if (SVar8 == 0) {
                    if (DAT_0086c58c == 0) {
                        local_1ac = local_1ac | 0xffef0010u;
                    } else if ((DAT_008ca96c & 4) != 0) {
                        local_1ac = local_1ac | 0xffff0000u;
                    }
                    uVar10 = local_190 | 0x100010u;
                    if ((DAT_008ca96c & 4) != 0) {
                        uVar10 = uVar10 | (~uVar10 << 0x10);
                    }
                    FUN_00473b70(uVar10 & local_1ac, 0, 5);
                } else {
                    uVar13 = 0;
                    if (DAT_0086c58c < 2) {
                        uVar13 = 0x20;
                    }
                    FUN_00473b70(uVar13, 0, 6);
                }
            } else {
                FUN_00473b70(0x10, 0, 7);
            }
        }
    }

    // ---- status line for the current wind / speed readout ---------------
    if (DAT_00725534 != -1) {
        uint32_t adj = static_cast<uint32_t>((DAT_008cac18 * 0x4b) >> 0x1f) & 0x3ffu;
        local_188 = static_cast<uint32_t>(static_cast<int32_t>(
            static_cast<uint32_t>(DAT_008cac18 * 0x4b) + adj) >> 10);
        DAT_0085a11c = 0x4b;
        DAT_008c9de0 = DAT_008c9dd8;
        FUN_00509500(DAT_008c9dd8, &DAT_0086c460, 0);
        iVar17 = static_cast<int32_t>(FUN_005f0ddc());
        iVar15 = DAT_0085a26c / 2;
        iVar9 = 10 - iVar17;
        if (10 - iVar17 < iVar15) {
            iVar9 = iVar15;
        }
        local_1a8 = static_cast<int32_t>(static_cast<int32_t>(
            static_cast<uint32_t>(DAT_008cac18 * 0x4b) + adj) >> 10);
        DAT_0085a11c = 0x4b;
        DAT_008c9de0 = DAT_008c9dd8;
        FUN_005096b0();
        iVar17 = static_cast<int32_t>(FUN_005f0ddc());
        iVar18 = (static_cast<int32_t>(static_cast<uint32_t>(DAT_0085a268) +
                                       (static_cast<uint32_t>(DAT_0085a268 >> 0x1f) & 7u)) >>
                  3) +
                 -8;
        iVar15 = (iVar15 - iVar9 / 2) + -2;
        if (8 - iVar17 < iVar9) {
            FUN_004881b0(iVar15, iVar18);
        } else {
            FUN_004af080(0, 0, 0, 0, 0, iVar15, iVar18, iVar9, 8 - iVar17, 0x80000000u, 0);
        }
        DAT_0085a11c = 0x4b;
        FUN_004b06c0(static_cast<uint32_t>(reinterpret_cast<intptr_t>(&DAT_00869b48)),
                     static_cast<uint32_t>(DAT_0085a26c / 2),
                     static_cast<uint32_t>(static_cast<int32_t>(
                         static_cast<uint32_t>(DAT_0085a268) +
                         (static_cast<uint32_t>(DAT_0085a268 >> 0x1f) & 7u)) >>
                         3),
                     0x4b, 0xffffffffu, 4, 0xffffffffu, 0);
        if ((_DAT_0085a164 & 4) != 0) {
            goto LAB_00436958;
        }
        DAT_00725534 = DAT_00725534 + -1;
    }
    if ((_DAT_0085a164 & 4) != 0) {
        goto LAB_00436958;
    }

    // ---- camera tracking towards the pending destination ----------------
    if (DAT_0085a128 != -1) {
        uVar11 = static_cast<uint32_t>(DAT_0085a128 - DAT_0086c578);
        uVar21 = static_cast<uint32_t>(DAT_0085a124 - DAT_0086c574);
        uVar10 = uVar11;
        if (static_cast<int32_t>(uVar11) < 0) {
            uVar10 = 0u - uVar11;
        }
        local_19c = uVar21;
        if (static_cast<int32_t>(uVar21) < 0) {
            local_19c = 0u - uVar21;
        }
        if (static_cast<int32_t>(local_19c) < static_cast<int32_t>(uVar10)) {
            local_19c = local_19c + uVar10 * 2;
        } else {
            local_19c = uVar10 + local_19c * 2;
        }
        iVar9 = (DAT_0086c56c ^ (DAT_0086c56c >> 0x1f)) - (DAT_0086c56c >> 0x1f);
        local_188 = static_cast<uint32_t>(iVar9 + 10);
        local_1a8 = (static_cast<int32_t>(local_188) / 10) * static_cast<int32_t>(local_188);
        if (local_1a8 < static_cast<int32_t>(local_19c) / 2) {
            DAT_0086c56c = static_cast<int32_t>(local_188);
            if (-1 < static_cast<int32_t>(local_188)) {
                goto LAB_00436850;
            }
LAB_00436aa0:
            DAT_0086c56c = 0;
        } else {
            DAT_0086c56c = iVar9 - 10;
            if (DAT_0086c56c < 0) {
                goto LAB_00436aa0;
            }
LAB_00436850:
            if (400 < DAT_0086c56c) {
                DAT_0086c56c = 400;
            }
        }
        iVar9 = static_cast<int32_t>(
                     ((uVar21 ^ static_cast<uint32_t>(static_cast<int32_t>(uVar21) >> 0x1f)) -
                      static_cast<uint32_t>(static_cast<int32_t>(uVar21) >> 0x1f)) +
                     ((uVar11 ^ static_cast<uint32_t>(static_cast<int32_t>(uVar11) >> 0x1f)) -
                      static_cast<uint32_t>(static_cast<int32_t>(uVar11) >> 0x1f)) +
                     1u);
        DAT_0086c578 = DAT_0086c578 + static_cast<int32_t>(
                                          uVar11 * static_cast<uint32_t>(DAT_0086c56c)) /
                                          iVar9;
        DAT_0086c574 = DAT_0086c574 + static_cast<int32_t>(
                                          uVar21 * static_cast<uint32_t>(DAT_0086c56c)) /
                                          iVar9;
    }
    if (((DAT_0086c56c == 0) && (DAT_0086c568 == 0)) &&
        ((DAT_008ca960 == 0) ||
         ((DAT_0086ea08[(DAT_008ca960 * 0x10 + DAT_0086c5d0) * 0x53] & 2) != 0))) {
        FUN_0043a0c0();
    }
    iVar9 = DAT_0086c570;
    DAT_0086c564 = FUN_00489440(DAT_0086c564, 0x1e, 300, 0);
    DAT_0086c570 = iVar9 + DAT_0086c564;

LAB_00436958:
    local_1a8 = (((DAT_008ca97c != 0) - 1) & DAT_0086ea18) + 500;
    uVar10 = static_cast<uint32_t>(FUN_004db210());
    iVar9 = 1;
    iVar17 = static_cast<int32_t>(
        (uVar10 ^ static_cast<uint32_t>(static_cast<int32_t>(uVar10) >> 0x1f)) -
        static_cast<uint32_t>(static_cast<int32_t>(uVar10) >> 0x1f));
    while (32000 < iVar17) {
        uVar10 = static_cast<uint32_t>(static_cast<int32_t>(uVar10) / 2);
        iVar9 = iVar9 * 2;
        iVar17 = static_cast<int32_t>(
            (uVar10 ^ static_cast<uint32_t>(static_cast<int32_t>(uVar10) >> 0x1f)) -
            static_cast<uint32_t>(static_cast<int32_t>(uVar10) >> 0x1f));
    }
    iVar17 = FUN_004db210(0x40000000, 0x15555555, 0, 0x20000000);
    iVar17 = FUN_004db210(iVar17 + local_1a8);
    iVar17 = FUN_004953d0(DAT_0086c574 - iVar17);
    FUN_004ad0c0(DAT_0086c578 - iVar17 * iVar9);
    FUN_004add70(DAT_008cabd4);
    FUN_00433930();
    if ((_DAT_0085a164 & 4) != 0) {
        FUN_004f6090("Paused");
        FUN_004b06c0(static_cast<uint32_t>(reinterpret_cast<intptr_t>(&DAT_00869b48)),
                     static_cast<uint32_t>(DAT_0085a26c / 2),
                     static_cast<uint32_t>(DAT_0085a268 / 2 + -0xc),
                     static_cast<uint32_t>(DAT_0085a11c), 0xff000000u, 4, 0xffffffffu, 0);
    }
    FUN_004d0cd0(0, 0, 0);
}


// ===== 0x436c30 (delegated part, unified declarations) =====
extern void    FUN_00431bc0(int32_t x, int32_t y, int32_t slot, int32_t* out_x, int32_t* out_y);
extern int32_t FUN_004319b0();
extern int32_t FUN_004db270();
extern void    FUN_004a90a0(int32_t slot, int32_t flag);
extern void    FUN_004a91e0(int32_t index);
extern void    FUN_004a9270(int32_t toggled);
extern void    FUN_004a93b0();
extern void    FUN_004ae7d0(uint32_t x, uint32_t y, uint32_t z, int32_t* out_x, int32_t* out_y);
extern void    FUN_004bc0d0();
extern void    FUN_004127e0(void* canvas, int32_t x, int32_t y, uint32_t color, int32_t mode);
extern void    FUN_0043a940(void* canvas, int32_t x, int32_t y, uint32_t color, int32_t mode);
extern uint8_t  DAT_0086e9ee[];
extern uint8_t  DAT_0086e9f2[];
extern uint8_t  DAT_0086e9f4[];
extern uint8_t  DAT_0086e9f6[];
extern uint8_t  DAT_0086ea06[];
extern uint8_t  DAT_0086ea0c[];
extern uint8_t  DAT_0086ea10[];
extern uint8_t  DAT_0086ea14[];
extern int32_t  DAT_0086ea20[];
extern uint8_t  DAT_0086ea24[];
extern uint8_t  DAT_0086ea28[];
extern uint8_t  DAT_0086eb1c[];
extern int16_t  DAT_0086feaa[];
extern uint8_t  DAT_0086feae[];
extern uint8_t  DAT_0086fec0[];
extern uint8_t  DAT_0086fed0[];
extern uint8_t  DAT_0086fed4[];
extern uint8_t  DAT_0086fed8[];
extern uint8_t  DAT_0086feec[];
extern int32_t  DAT_0086ff1c[];
extern int32_t  DAT_0086ff4c[];
extern uint8_t  DAT_0086ff7c[];
extern uint8_t  DAT_0086ffac[];
extern uint8_t  DAT_0086ffc4[];
extern int8_t   DAT_00725419[];
extern int8_t   DAT_0072541d[];
extern int32_t  DAT_008ca964;
extern int32_t  DAT_008ca968;
extern int32_t  DAT_008ca978;
extern char     DAT_008c7190;

// 0x00436c30 — observed shape
void FUN_00436c30(int32_t param_1)
{
    char*     pcVar1;
    int32_t   iVar2;
    int32_t   pcVar3;
    char      cVar4;
    bool      bVar5;
    int32_t   iVar6;
    int32_t   iVar7;
    uint32_t  uVar8;
    DWORD     DVar9;
    int32_t   iVar10;
    int32_t   uVar11;
    int32_t   iVar12;
    int16_t   sVar13;
    int32_t   iVar14;
    uint32_t  uVar15;
    uint32_t* puVar17;
    int32_t*  piVar18;
    int16_t*  psVar19;
    bool      bVar20;
    int32_t   local_68;
    int32_t   local_64;
    int32_t   local_60;
    uintptr_t local_5c;
    int32_t   local_58;
    uint32_t  local_54;
    int32_t   local_50;
    uint32_t  local_4c;
    int32_t   local_48;
    int32_t*  local_44;
    int32_t   local_40;
    int32_t   local_3c;
    int32_t   local_38;
    int32_t   local_34;
    int32_t*  local_30;
    int32_t   local_2c;
    int32_t   local_28;
    int32_t   local_24;
    int32_t   local_20;
    uint32_t  local_1c;
    int32_t   local_18;
    int32_t   local_14;
    int32_t   local_10;
    int32_t   local_c;
    int32_t   local_8;
    int32_t   local_4;

    local_38 = param_1 << 4;
    bVar5 = false;
    local_54 = 0;
    do {
        uVar11 = DAT_0086c57c;
        if (((param_1 == 0) && (0 < DAT_008ca974)) &&
            (DAT_0086e9ec[local_54 * 0xa6] < 100)) {
            DAT_0086ea1c[local_54 * 0x53] = DAT_0086c580;
            DAT_0086ea20[local_54 * 0x53] = uVar11;
            DAT_0086ea08[local_54 * 0x53] = DAT_0086ea08[local_54 * 0x53] & 0xfffffeff;
        }
        iVar2 = local_38 + static_cast<int32_t>(local_54);
        iVar16 = iVar2 * 0x14c;
        uVar15 = DAT_0086ea08[iVar2 * 0x53];
        sVar13 = DAT_0086e9e8[iVar2 * 0xa6];
        DAT_0086ea08[iVar2 * 0x53] = uVar15 & 0xfffff7ff;
        if ((sVar13 != -1) && (DAT_0086e9ea[iVar2 * 0xa6] != 0)) {
            if (DAT_0086e9ec[iVar2 * 0xa6] < 100) {
                bVar5 = true;
            }
            local_4c = 0;
            local_3c = 0;
            local_30 = nullptr;
            local_34 = 0;
            local_40 = 0;
            local_2c = iVar2;
            if (99 < DAT_0086e9ec[iVar2 * 0xa6]) {
                if (param_1 == 0) {
                    if (DAT_0086c5dc + -1000 < DAT_0086ea5c[local_54 * 0x53]) {
                        DAT_0086ea1c[local_54 * 0x53] = DAT_0086ea5c[local_54 * 0x53] + -1000;
                        DAT_0086ea20[local_54 * 0x53] =
                            ((-static_cast<uint32_t>((local_54 & 1) != 0) & 0x14c) - 0xa6) +
                            DAT_0086ea8c[local_54 * 0x53];
                        if (DAT_0086c584 != 0) {
                            if ((uVar15 & 4) == 0) {
                                DAT_0086ea08[local_54 * 0x53] = uVar15 & 0xfffff7fd;
                            }
                            DAT_0086ea08[local_54 * 0x53] =
                                DAT_0086ea08[local_54 * 0x53] & 0xfffffffb;
                        }
                    }
                }
                else if (DAT_0086ea5c[iVar2 * 0x53] < DAT_0086c5dc + 17000) {
                    DAT_0086ea1c[iVar2 * 0x53] =
                        ((-static_cast<uint32_t>(param_1 != 0) & 2000) - 1000) +
                        DAT_0086ea5c[iVar2 * 0x53];
                    DAT_0086ea20[iVar2 * 0x53] =
                        ((-static_cast<uint32_t>((local_54 & 1) != 0) & 0x14c) - 0xa6) +
                        DAT_0086ea8c[iVar2 * 0x53];
                    if (DAT_0086c584 != 0) {
                        if ((uVar15 & 4) == 0) {
                            DAT_0086ea08[iVar2 * 0x53] = uVar15 & 0xfffff7fd;
                        }
                        DAT_0086ea08[iVar2 * 0x53] = DAT_0086ea08[iVar2 * 0x53] & 0xfffffffb;
                    }
                    puVar17 = reinterpret_cast<uint32_t*>(DAT_0086ea2c + iVar16);
                    iVar6 = 0xc;
                    do {
                        if (*puVar17 == 0) {
                            iVar14 = rand();
                            *puVar17 = static_cast<uint32_t>(iVar14 % 10 == 0);
                        }
                        puVar17 = puVar17 + 1;
                        iVar6 = iVar6 + -1;
                    } while (iVar6 != 0);
                }
            }
            if (DAT_008ca974 != 0) {
                if (DAT_008ca974 < 1) {
                    iVar6 = (-1 < DAT_008ca974) - 1;
                }
                else {
                    iVar6 = 1;
                }
                DAT_008ca974 = DAT_008ca974 + iVar6;
            }
            if ((param_1 == 0) && (DAT_0086e9ec[local_54 * 0xa6] < 100)) {
                iVar6 = static_cast<int16_t>(DAT_0086e9fa[local_54 * 0xa6]) + -9;
                iVar14 = static_cast<int16_t>(DAT_0086e9f8[local_54 * 0xa6]) + -0xd;
                if (iVar14 < 0) {
                    iVar14 = -iVar14;
                }
                if (iVar6 < 0) {
                    iVar6 = -iVar6;
                }
                if (iVar6 < iVar14) {
                    iVar6 = iVar6 + iVar14 * 2;
                }
                else {
                    iVar6 = iVar14 + iVar6 * 2;
                }
                if (iVar6 / 2 < 1) {
                    DAT_008ca974 = DAT_008ca974 + 1;
                    DAT_0086ea08[local_54 * 0x53] = DAT_0086ea08[local_54 * 0x53] | 0x106;
                    uVar11 = DAT_0086ea8c[local_54 * 0x53];
                    DAT_008ca981 = 1;
                    *reinterpret_cast<uint32_t*>(DAT_0086ea24 + local_54 * 0x14c) =
                        DAT_0086ea5c[local_54 * 0x53];
                    *reinterpret_cast<uint32_t*>(DAT_0086ea28 + local_54 * 0x14c) =
                        static_cast<uint32_t>(uVar11);
                }
            }
            if (((*reinterpret_cast<uint8_t*>(&DAT_0086ea08[iVar2 * 0x53]) & 0x30) != 0) ||
                (DAT_0086c584 != 0)) {
                local_20 = param_1 * 0x14c0;
                *reinterpret_cast<int16_t*>(DAT_0086e9f4 + iVar16) = 0x7fff;
                *reinterpret_cast<uint16_t*>(DAT_0086e9f2 + iVar16) = 0xffff;
                local_50 = 0;
                local_44 = DAT_0086ff1c;
                piVar18 = DAT_0086ff4c + param_1 * -0x530;
                do {
                    if ((static_cast<int16_t>(piVar18[-0x29]) != -1) &&
                        (*reinterpret_cast<int16_t*>(reinterpret_cast<uint8_t*>(piVar18) - 0x96) != 0)) {
                        iVar6 = *piVar18;
                        iVar14 = piVar18[-0xc];
                        iVar7 = FUN_00431a60(DAT_0086ea5c[iVar2 * 0x53], param_1,
                                             static_cast<int32_t>(local_54));
                        if ((iVar7 != 0) ||
                            ((*reinterpret_cast<uint8_t*>(piVar18 + -0x21) & 0x10) != 0)) {
                            if (((param_1 == 0) &&
                                 ((*reinterpret_cast<uint8_t*>(local_44 + -0x15) & 2) == 0)) &&
                                (DAT_008c7190 == '\0')) {
                                DAT_008c7190 = '\x01';
                                FUN_004a93b0();
                                if (DAT_008ca960 != 0) {
                                    DAT_0085a128 = *local_44;
                                    DAT_0085a124 = local_44[0xc];
                                }
                            }
                            iVar14 = piVar18[-0xc];
                            piVar18[-0x21] = piVar18[-0x21] | 6;
                            iVar6 = *piVar18;
                            piVar18[-0x1a] = iVar14;
                            local_4c = local_4c | 1 << (static_cast<uint8_t>(local_50) & 0x1f);
                            piVar18[-0x19] = iVar6;
                        }
                        if (static_cast<int16_t>(piVar18[-0x28]) < 100) {
                            if (((piVar18[-0x21] & 2U) == 0) ||
                                (((local_5c = static_cast<uintptr_t>(
                                       static_cast<int32_t>(DAT_0086e9e8[iVar2 * 0xa6]) * 7),
                                   *reinterpret_cast<int8_t*>(local_5c + 0x72541c) != 0 &&
                                   ((local_4c & 1 << (static_cast<uint8_t>(local_50) & 0x1f)) == 0)) &&
                                 ((piVar18[-0x21] & 0x100U) == 0))) {
                                if (piVar18[-0x1a] != 0) {
                                    iVar6 = piVar18[-0x19] - DAT_0086ea8c[iVar2 * 0x53];
                                    iVar14 = piVar18[-0x1a] - DAT_0086ea5c[iVar2 * 0x53];
                                    if (iVar14 < 0) {
                                        iVar14 = -iVar14;
                                    }
                                    if (iVar6 < 0) {
                                        iVar6 = -iVar6;
                                    }
                                    if (iVar6 < iVar14) {
                                        iVar6 = iVar6 + iVar14 * 2;
                                    }
                                    else {
                                        iVar6 = iVar14 + iVar6 * 2;
                                    }
                                    iVar6 = iVar6 / 2 + 2000;
                                    if (iVar6 < *reinterpret_cast<int16_t*>(DAT_0086e9f4 + iVar16)) {
                                        *reinterpret_cast<uint16_t*>(DAT_0086e9f2 + iVar16) =
                                            static_cast<uint16_t>(local_50);
                                        *reinterpret_cast<int16_t*>(DAT_0086e9f4 + iVar16) =
                                            static_cast<int16_t>(iVar6);
                                    }
                                    if (iVar6 < 3000) {
                                        piVar18[-0x1a] = 0;
                                    }
                                }
                            }
                            else {
                                iVar6 = iVar6 - DAT_0086ea8c[iVar2 * 0x53];
                                iVar14 = iVar14 - DAT_0086ea5c[iVar2 * 0x53];
                                if (iVar14 < 0) {
                                    iVar14 = -iVar14;
                                }
                                if (iVar6 < 0) {
                                    iVar6 = -iVar6;
                                }
                                iVar7 = iVar6 + iVar14 * 2;
                                if (iVar14 <= iVar6) {
                                    iVar7 = iVar14 + iVar6 * 2;
                                }
                                iVar7 = iVar7 / 2;
                                if ((piVar18[-0x21] & 0x100U) != 0) {
                                    iVar7 = iVar7 / 2;
                                }
                                if ((*reinterpret_cast<int8_t*>(local_5c + 0x725419) > 4) &&
                                    (iVar6 = FUN_004319b0(), iVar6 == 1) && (1000 < iVar7)) {
                                    iVar7 = iVar7 + 3000;
                                }
                                if (iVar7 < *reinterpret_cast<int16_t*>(DAT_0086e9f4 + iVar16)) {
                                    *reinterpret_cast<uint16_t*>(DAT_0086e9f2 + iVar16) =
                                        static_cast<uint16_t>(local_50);
                                    *reinterpret_cast<int16_t*>(DAT_0086e9f4 + iVar16) =
                                        static_cast<int16_t>(iVar7);
                                }
                            }
                        }
                    }
                    local_44 = local_44 + 0x53;
                    local_50 = local_50 + 1;
                    piVar18 = piVar18 + 0x53;
                } while (static_cast<int32_t>(reinterpret_cast<intptr_t>(local_44)) < 0x8713dc);
                iVar6 = 0xffffff;
                uVar15 = 0;
                psVar19 = reinterpret_cast<int16_t*>(DAT_0086e9f6 + local_20);
                do {
                    if ((((psVar19[-7] != -1) && (*psVar19 != 0)) && (psVar19[-5] < 100)) &&
                        (uVar15 != local_54)) {
                        iVar14 = *reinterpret_cast<int32_t*>(psVar19 + 0x4b) -
                                 DAT_0086ea8c[iVar2 * 0x53];
                        iVar7 = *reinterpret_cast<int32_t*>(psVar19 + 0x33) -
                                DAT_0086ea5c[iVar2 * 0x53];
                        if (iVar7 < 0) {
                            iVar7 = -iVar7;
                        }
                        if (iVar14 < 0) {
                            iVar14 = -iVar14;
                        }
                        if (iVar14 < iVar7) {
                            iVar14 = iVar14 + iVar7 * 2;
                        }
                        else {
                            iVar14 = iVar7 + iVar14 * 2;
                        }
                        if (iVar14 / 2 < iVar6) {
                            iVar6 = iVar14 / 2;
                        }
                    }
                    uVar15 = uVar15 + 1;
                    psVar19 = psVar19 + 0xa6;
                } while (static_cast<int32_t>(uVar15) < 0x10);
                if ((param_1 == 0) &&
                    ((*reinterpret_cast<uint8_t*>(&DAT_0086ea08[local_54 * 0x53]) & 0x10) != 0)) {
                    *reinterpret_cast<uint16_t*>(DAT_0086e9f2 + local_54 * 0x14c) =
                        *reinterpret_cast<uint16_t*>(DAT_0086c590 + DAT_0086c588);
                }
                iVar6 = *reinterpret_cast<int16_t*>(DAT_0086e9f2 + iVar16);
                local_50 = iVar6;
                if (iVar6 != -1) {
                    iVar14 = DAT_0086ff4c[(iVar6 - local_38) * 0x53] -
                             DAT_0086ea8c[iVar2 * 0x53];
                    iVar7 = DAT_0086ff1c[(iVar6 - local_38) * 0x53] -
                            DAT_0086ea5c[iVar2 * 0x53];
                    local_3c = FUN_004db270();
                    if (iVar7 < 0) {
                        iVar7 = -iVar7;
                    }
                    if (iVar14 < 0) {
                        iVar14 = -iVar14;
                    }
                    iVar12 = iVar14 + iVar7 * 2;
                    if (iVar7 <= iVar14) {
                        iVar12 = iVar7 + iVar14 * 2;
                    }
                    local_30 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(iVar12 / 2));
                    *reinterpret_cast<int16_t*>(DAT_0086e9f4 + iVar16) =
                        static_cast<int16_t>(reinterpret_cast<intptr_t>(local_30));
                }
                if ((*reinterpret_cast<uint8_t*>(&DAT_0086ea08[iVar2 * 0x53]) & 0x40) != 0) {
                    iVar6 = FUN_00431e50(
                        static_cast<int32_t>(static_cast<int16_t>(DAT_0086e9f8[iVar2 * 0xa6])) +
                            DAT_007252f0[*reinterpret_cast<int16_t*>(DAT_0086ea00 + iVar16)],
                        static_cast<int32_t>(static_cast<int16_t>(DAT_0086e9fa[iVar2 * 0xa6])) +
                            DAT_00725350[*reinterpret_cast<int16_t*>(DAT_0086ea00 + iVar16)]);
                    local_50 = iVar6;
                    if (iVar6 != -1) {
                        iVar14 = DAT_0086ff4c[(iVar6 - local_38) * 0x53] -
                                 DAT_0086ea8c[iVar2 * 0x53];
                        iVar7 = DAT_0086ff1c[(iVar6 - local_38) * 0x53] -
                                DAT_0086ea5c[iVar2 * 0x53];
                        if (iVar7 < 0) {
                            iVar7 = -iVar7;
                        }
                        if (iVar14 < 0) {
                            iVar14 = -iVar14;
                        }
                        if (iVar14 < iVar7) {
                            iVar14 = iVar14 + iVar7 * 2;
                        }
                        else {
                            iVar14 = iVar7 + iVar14 * 2;
                        }
                        local_30 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(iVar14 / 2));
                        *reinterpret_cast<int16_t*>(DAT_0086e9f4 + iVar16) =
                            static_cast<int16_t>(reinterpret_cast<intptr_t>(local_30));
                        local_3c = FUN_004db270();
                    }
                }
                if (param_1 == 0) {
                    if (iVar6 != -1) goto LAB_0043738f;
                }
                else if (iVar6 == -1) {
                    if ((*reinterpret_cast<uint8_t*>(&DAT_0086ea08[iVar2 * 0x53]) & 0x30) != 0) {
                        *reinterpret_cast<uint16_t*>(DAT_0086ea02 + iVar16) = 0xff9d;
                        *reinterpret_cast<uint16_t*>(DAT_0086ea06 + iVar16) =
                            *reinterpret_cast<uint16_t*>(DAT_0086ea04 + iVar16);
                        *reinterpret_cast<uint16_t*>(DAT_0086ea04 + iVar16) = 0;
                    }
                }
                else {
LAB_0043738f:
                    if ((*reinterpret_cast<uint8_t*>(&DAT_0086ea08[iVar2 * 0x53]) & 0x30) != 0) {
                        sVar13 = DAT_0086e9e8[iVar2 * 0xa6];
                        iVar6 = *reinterpret_cast<int16_t*>(DAT_0086e9f4 + iVar16);
                        cVar4 = DAT_0072541c[sVar13 * 7];
                        DAT_008ca964 = 1;
                        local_48 = 0;
                        if ((cVar4 * 1000 + 0x29a < iVar6) ||
                            ((local_4c & 1 << (static_cast<uint8_t>(local_50) & 0x1f)) == 0)) {
                            if ((param_1 == 0) &&
                                ((*reinterpret_cast<uint8_t*>(&DAT_0086ea08[local_54 * 0x53]) & 0x10) != 0)) {
                                FUN_004888e0(0xab, 0xffffffff, 0xffffffff, 0xbf800000);
                                DAT_008ca968 = 0;
                            }
                            iVar14 = (local_50 - local_38) * 0x14c;
                            DAT_0086ea08[iVar2 * 0x53] = DAT_0086ea08[iVar2 * 0x53] & 0xffffffef;
                            *reinterpret_cast<uint32_t*>(DAT_0086fec8 + iVar14) =
                                *reinterpret_cast<uint32_t*>(DAT_0086fec8 + iVar14) & 0xfffffff7;
                        }
                        else {
                            uVar15 = static_cast<uint32_t>(
                                         local_3c - *reinterpret_cast<int32_t*>(DAT_0086eabc + iVar16)) >>
                                     0x1f;
                            local_34 = 1;
                            if (0x15555555 < static_cast<int32_t>(
                                    ((local_3c - *reinterpret_cast<int32_t*>(DAT_0086eabc + iVar16)) ^
                                     uVar15) - uVar15)) {
                                *reinterpret_cast<int32_t*>(DAT_0086eabc + iVar16) = local_3c;
                            }
                            if ((*reinterpret_cast<uint8_t*>(&DAT_0086ea08[iVar2 * 0x53]) & 0x10) != 0) {
                                *reinterpret_cast<uint16_t*>(DAT_0086ea00 + iVar16) =
                                    static_cast<uint16_t>(((local_3c >> 0x1c) + 1 >> 1) & 7);
                            }
                            if (iVar6 < 1000) {
                                iVar6 = 1000;
                            }
                            else if (9999 < iVar6) {
                                iVar6 = 9999;
                            }
                            iVar14 = (local_50 - local_38) * 0x14c;
                            iVar7 = static_cast<int32_t>(DAT_0072541b[sVar13 * 7]) *
                                    ((cVar4 * 2000) / iVar6);
                            local_48 = iVar7;
                            iVar6 = FUN_004319b0();
                            if (iVar6 != 1) {
                                local_48 = iVar7 * 2;
                            }
                        }
                        if (*reinterpret_cast<int16_t*>(DAT_0086e9f4 + iVar16) < 1000) {
                            if (((local_34 != 0) ||
                                 ((((DAT_0086ea1c[iVar2 * 0x53] == 0 && (param_1 == 0)) &&
                                    (DAT_0072541c[static_cast<int16_t>(DAT_0086e9e8[local_54 * 0xa6]) * 7] != '\0')) &&
                                   ((*reinterpret_cast<uint8_t*>(&DAT_0086ea08[local_54 * 0x53]) & 8) == 0)))) &&
                                ((DAT_0086ea1c[iVar2 * 0x53] == 0 &&
                                  (uVar15 = static_cast<uint32_t>(
                                       local_3c - *reinterpret_cast<int32_t*>(DAT_0086eabc + iVar16)) >>
                                   0x1f,
                                   0x15555555 < static_cast<int32_t>(
                                       ((local_3c - *reinterpret_cast<int32_t*>(DAT_0086eabc + iVar16)) ^
                                        uVar15) - uVar15)))))) {
                                *reinterpret_cast<int32_t*>(DAT_0086eabc + iVar16) = local_3c;
                            }
                            if ((*reinterpret_cast<uint8_t*>(&DAT_0086ea08[iVar2 * 0x53]) & 0x20) != 0) {
                                local_40 = 1;
                                local_34 = 1;
                                uVar15 = static_cast<uint32_t>(
                                             local_3c - *reinterpret_cast<int32_t*>(DAT_0086eabc + iVar16)) >>
                                         0x1f;
                                if (0x15555555 < static_cast<int32_t>(
                                        ((local_3c - *reinterpret_cast<int32_t*>(DAT_0086eabc + iVar16)) ^
                                         uVar15) - uVar15)) {
                                    *reinterpret_cast<int32_t*>(DAT_0086eabc + iVar16) = local_3c;
                                }
                                sVar13 = DAT_0086e9e8[iVar2 * 0xa6];
                                iVar6 = static_cast<int32_t>(DAT_00725419[sVar13 * 7]) << 2;
                                if (*reinterpret_cast<int16_t*>(DAT_0086e9f4 + iVar16) < 0x14d) {
                                    DAT_0086ea1c[iVar2 * 0x53] = 0;
                                }
                                local_48 = iVar6;
                                if ((sVar13 == 3) && (iVar7 = FUN_004319b0(), iVar7 == 1)) {
                                    local_48 = iVar6 / 3;
                                }
                            }
                        }
                        if ((*reinterpret_cast<uint8_t*>(&DAT_0086ea08[iVar2 * 0x53]) & 0x10) != 0) {
                            local_20 = static_cast<int32_t>(
                                           DAT_0072541c[static_cast<int16_t>(DAT_0086e9e8[iVar2 * 0xa6]) * 7]) *
                                           2000 + 500;
                            local_64 = FUN_005f0ddc();
                            if (local_64 < 3) {
                                local_64 = 3;
                            }
                            else if (0x3c < local_64) {
                                local_64 = 0x3c;
                            }
                            FUN_004ae7d0(
                                *reinterpret_cast<uint32_t*>(
                                    reinterpret_cast<uint8_t*>(DAT_0086ff1c) + iVar14),
                                *reinterpret_cast<uint32_t*>(
                                    reinterpret_cast<uint8_t*>(DAT_0086ff4c) + iVar14),
                                *reinterpret_cast<uint32_t*>(DAT_0086fed8 + iVar14),
                                &local_68, &local_58);
                            iVar6 = local_58;
                            uVar15 = static_cast<uint32_t>(
                                         *reinterpret_cast<int16_t*>(DAT_0086feb8 + iVar14)) &
                                     0x8000000f;
                            if (static_cast<int32_t>(uVar15) < 0) {
                                uVar15 = (uVar15 - 1 | 0xfffffff0) + 1;
                            }
                            uVar8 = static_cast<uint32_t>(
                                        *reinterpret_cast<int16_t*>(DAT_0086feba + iVar14)) &
                                    0x8000000f;
                            if (static_cast<int32_t>(uVar8) < 0) {
                                uVar8 = (uVar8 - 1 | 0xfffffff0) + 1;
                            }
                            if (DAT_00871978[uVar8 + uVar15 * 0x10] == '\x01') {
                                local_64 = local_64 / 2;
                                FUN_004f6090("Cover: /2");
                                DAT_0085a11c = 0x4b;
                                FUN_004b06c0(DAT_00869b48, local_68,
                                             (iVar6 - ((-static_cast<uint32_t>((_DAT_0085a164 & 0x40) != 0) & 0xffffffec) + 0x3c)) + 0x10,
                                             0x4b, 0xffff4040, 4, 0xffffffff, 0);
                            }
                            if ((DAT_0086fec8[iVar14] & 8) != 0) {
                                FUN_004f6090("Damage:+@NUM%", local_64);
                                DAT_0085a11c = 0x4b;
                                FUN_004b06c0(DAT_00869b48, local_68,
                                             iVar6 - ((-static_cast<uint32_t>((_DAT_0085a164 & 0x40) != 0) & 0xffffffec) + 0x3c),
                                             0x4b, 0xffff4040, 4, 0xffffffff, 0);
                            }
                            DAT_0085a128 = (DAT_0086ea5c[iVar2 * 0x53] + -1000 +
                                            *reinterpret_cast<int32_t*>(
                                                reinterpret_cast<uint8_t*>(DAT_0086ff1c) + iVar14)) / 2;
                            DAT_0085a124 = (DAT_0086ea8c[iVar2 * 0x53] +
                                            *reinterpret_cast<int32_t*>(
                                                reinterpret_cast<uint8_t*>(DAT_0086ff4c) + iVar14)) / 2;
                        }
                        if ((*reinterpret_cast<uint8_t*>(&DAT_0086ea08[iVar2 * 0x53]) & 0x40) != 0) {
                            local_64 = static_cast<int32_t>(
                                DAT_00725419[static_cast<int16_t>(DAT_0086e9e8[iVar2 * 0xa6]) * 7]);
                            local_60 = static_cast<int32_t>(
                                DAT_00725419[*reinterpret_cast<int16_t*>(DAT_0086fea8 + iVar14) * 7]);
                            if (*reinterpret_cast<int16_t*>(DAT_0086fea8 + iVar14) == 3) {
                                local_60 = local_60 / 2;
                            }
                            local_5c = *reinterpret_cast<uintptr_t*>(DAT_0086ea14 + iVar16);
                            local_44 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(
                                static_cast<int32_t>(DAT_0086e9ec[iVar2 * 0xa6]) -
                                static_cast<int32_t>(*reinterpret_cast<int16_t*>(DAT_0086feac + iVar14))));
                            local_20 = *reinterpret_cast<int32_t*>(DAT_0086fed4 + iVar14);
                            local_4c = *reinterpret_cast<uint32_t*>(DAT_0086fed0 + iVar14);
                            local_1c = *reinterpret_cast<uint32_t*>(DAT_0086ea10 + iVar16);
                            FUN_004e7510(static_cast<float>(static_cast<int32_t>(local_4c)),
                                         static_cast<float>(local_20), 0);
                            local_20 = FUN_005f0ddc();
                            FUN_004e7510(static_cast<float>(static_cast<int32_t>(local_1c)),
                                         static_cast<float>(static_cast<int32_t>(local_5c)), 0);
                            iVar6 = FUN_005f0ddc();
                            local_4c = static_cast<uint32_t>(iVar6 - local_20);
                            FUN_004ae7d0(
                                *reinterpret_cast<uint32_t*>(
                                    reinterpret_cast<uint8_t*>(DAT_0086ff1c) + iVar14),
                                *reinterpret_cast<uint32_t*>(
                                    reinterpret_cast<uint8_t*>(DAT_0086ff4c) + iVar14),
                                *reinterpret_cast<uint32_t*>(DAT_0086fed8 + iVar14),
                                &local_68, &local_58);
                            iVar6 = local_58;
                            if (*reinterpret_cast<int32_t*>(
                                    reinterpret_cast<uint8_t*>(DAT_0086ff4c) + iVar14) <
                                DAT_0086ea8c[iVar2 * 0x53]) {
                                local_5c = reinterpret_cast<uintptr_t>(&FUN_0043a940);
                                local_68 = local_68 + -10;
                            }
                            else {
                                local_5c = reinterpret_cast<uintptr_t>(&FUN_004127e0);
                                local_68 = local_68 + 10;
                            }
                            iVar7 = local_58 + -0x8c;
                            FUN_004f6090("@LAND_PARTY",
                                         static_cast<int32_t>(DAT_0086e9e8[iVar2 * 0xa6]));
                            DAT_0085a11c = 0x4b;
                            reinterpret_cast<void (*)(void*, int32_t, int32_t, uint32_t, int32_t)>(
                                local_5c)(DAT_00869b48, local_68, iVar6 + -0x9c, 0xffffffff, 0);
                            FUN_004f6090("Attack:@NUM", local_64);
                            reinterpret_cast<void (*)(void*, int32_t, int32_t, uint32_t, int32_t)>(
                                local_5c)(DAT_00869b48, local_68, iVar7, 0xffffffff, 0);
                            iVar7 = iVar6 + -0x78;
                            uVar15 = (static_cast<uint32_t>(
                                          *reinterpret_cast<uint16_t*>(DAT_0086ea00 + iVar16)) ^
                                      0xfffffffc) -
                                     static_cast<uint32_t>(
                                         *reinterpret_cast<uint16_t*>(DAT_0086fec0 + iVar14)) & 7;
                            if (3 < uVar15) {
                                uVar15 = uVar15 - 8;
                            }
                            local_58 = iVar7;
                            if (1 < static_cast<int32_t>(
                                        (uVar15 ^ static_cast<uint32_t>(
                                                      static_cast<int32_t>(uVar15) >> 0x1f)) -
                                        static_cast<uint32_t>(
                                            static_cast<int32_t>(uVar15) >> 0x1f))) {
                                FUN_004f6090("Flank Attack! x2");
                                reinterpret_cast<void (*)(void*, int32_t, int32_t, uint32_t, int32_t)>(
                                    local_5c)(DAT_00869b48, local_68, iVar7, 0xffffffff, 0);
                                local_58 = iVar6 + -100;
                                local_64 = local_64 * 2;
                            }
                            iVar6 = local_58;
                            if (static_cast<int32_t>(reinterpret_cast<intptr_t>(local_44)) < -0x18) {
                                iVar7 = static_cast<int32_t>(static_cast<uint64_t>(
                                    static_cast<int64_t>(
                                        static_cast<int32_t>(reinterpret_cast<intptr_t>(local_44))) *
                                    -0x51eb851fLL) >> 0x20);
                                FUN_004f6090("Morale +@NUM", (iVar7 >> 3) - (iVar7 >> 0x1f));
                                reinterpret_cast<void (*)(void*, int32_t, int32_t, uint32_t, int32_t)>(
                                    local_5c)(DAT_00869b48, local_68, iVar6, 0xffffffff, 0);
                                iVar7 = static_cast<int32_t>(static_cast<uint64_t>(
                                    static_cast<int64_t>(
                                        static_cast<int32_t>(reinterpret_cast<intptr_t>(local_44))) *
                                    -0x66666667LL) >> 0x20);
                                local_58 = iVar6 + 0x14;
                                local_64 = local_64 + ((iVar7 >> 3) - (iVar7 >> 0x1f));
                            }
                            iVar6 = local_58;
                            if (100 < static_cast<int32_t>(local_4c)) {
                                local_1c = static_cast<uint32_t>(local_4c / 100);
                                FUN_004f6090("Height +@NUM", static_cast<int32_t>(local_1c));
                                reinterpret_cast<void (*)(void*, int32_t, int32_t, uint32_t, int32_t)>(
                                    local_5c)(DAT_00869b48, local_68, iVar6, 0xffffffff, 0);
                                local_58 = iVar6 + 0x14;
                                local_64 = local_64 + static_cast<int32_t>(local_1c);
                            }
                            iVar6 = local_58;
                            if (DAT_0086e9e8[iVar2 * 0xa6] == 3) {
                                uVar15 = static_cast<uint32_t>(
                                             *reinterpret_cast<int16_t*>(DAT_0086feb8 + iVar14)) &
                                         0x8000000f;
                                if (static_cast<int32_t>(uVar15) < 0) {
                                    uVar15 = (uVar15 - 1 | 0xfffffff0) + 1;
                                }
                                uVar8 = static_cast<uint32_t>(
                                            *reinterpret_cast<int16_t*>(DAT_0086feba + iVar14)) &
                                        0x8000000f;
                                if (static_cast<int32_t>(uVar8) < 0) {
                                    uVar8 = (uVar8 - 1 | 0xfffffff0) + 1;
                                }
                                if (DAT_00871978[uVar8 + uVar15 * 0x10] == '\x01') {
                                    FUN_004f6090("Forest: /3");
                                    reinterpret_cast<void (*)(void*, int32_t, int32_t, uint32_t, int32_t)>(
                                        local_5c)(DAT_00869b48, local_68, iVar6, 0xffff4040, 0);
                                    local_64 = local_64 / 3;
                                    local_58 = iVar6 + 0x14;
                                }
                            }
                            FUN_004ae7d0(
                                *reinterpret_cast<uint32_t*>(
                                    reinterpret_cast<uint8_t*>(DAT_0086ff1c) + iVar14),
                                *reinterpret_cast<uint32_t*>(
                                    reinterpret_cast<uint8_t*>(DAT_0086ff4c) + iVar14),
                                *reinterpret_cast<uint32_t*>(DAT_0086fed8 + iVar14),
                                &local_68, &local_58);
                            iVar6 = local_58;
                            if (*reinterpret_cast<int32_t*>(
                                    reinterpret_cast<uint8_t*>(DAT_0086ff4c) + iVar14) <
                                DAT_0086ea8c[iVar2 * 0x53]) {
                                local_5c = reinterpret_cast<uintptr_t>(&FUN_004127e0);
                                local_68 = local_68 + 10;
                            }
                            else {
                                local_5c = reinterpret_cast<uintptr_t>(&FUN_0043a940);
                                local_68 = local_68 + -10;
                            }
                            iVar7 = local_58 + -0x8c;
                            FUN_004f6090("@LAND_PARTY",
                                         static_cast<int32_t>(
                                             *reinterpret_cast<int16_t*>(DAT_0086fea8 + iVar14)));
                            DAT_0085a11c = 0x4b;
                            reinterpret_cast<void (*)(void*, int32_t, int32_t, uint32_t, int32_t)>(
                                local_5c)(DAT_00869b48, local_68, iVar6 + -0x9c, 0xffffffff, 0);
                            FUN_004f6090("Defend:@NUM", local_60);
                            reinterpret_cast<void (*)(void*, int32_t, int32_t, uint32_t, int32_t)>(
                                local_5c)(DAT_00869b48, local_68, iVar7, 0xffffffff, 0);
                            iVar7 = iVar6 + -0x78;
                            local_58 = iVar7;
                            if ((*reinterpret_cast<uint32_t*>(DAT_0086fec8 + iVar14) & 0x200) != 0) {
                                FUN_004f6090("Ambush! x2");
                                reinterpret_cast<void (*)(void*, int32_t, int32_t, uint32_t, int32_t)>(
                                    local_5c)(DAT_00869b48, local_68, iVar7, 0xffffffff, 0);
                                local_58 = iVar6 + -100;
                                local_60 = local_60 * 2;
                            }
                            iVar6 = local_58;
                            if (0x18 < static_cast<int32_t>(reinterpret_cast<intptr_t>(local_44))) {
                                FUN_004f6090("Morale +@NUM",
                                             static_cast<int32_t>(reinterpret_cast<intptr_t>(local_44)) / 0x19);
                                reinterpret_cast<void (*)(void*, int32_t, int32_t, uint32_t, int32_t)>(
                                    local_5c)(DAT_00869b48, local_68, iVar6, 0xffffffff, 0);
                                local_58 = iVar6 + 0x14;
                                local_60 = local_60 +
                                    static_cast<int32_t>(reinterpret_cast<intptr_t>(local_44)) / 0x14;
                            }
                            iVar6 = local_58;
                            if (static_cast<int32_t>(local_4c) < -100) {
                                iVar7 = static_cast<int32_t>(static_cast<uint64_t>(
                                    static_cast<int64_t>(static_cast<int32_t>(local_4c)) *
                                    -0x51eb851fLL) >> 0x20);
                                FUN_004f6090("Height +@NUM", (iVar7 >> 5) - (iVar7 >> 0x1f));
                                reinterpret_cast<void (*)(void*, int32_t, int32_t, uint32_t, int32_t)>(
                                    local_5c)(DAT_00869b48, local_68, iVar6, 0xffffffff, 0);
                                iVar7 = static_cast<int32_t>(static_cast<uint64_t>(
                                    static_cast<int64_t>(static_cast<int32_t>(local_4c)) *
                                    -0x51eb851fLL) >> 0x20);
                                local_58 = iVar6 + 0x14;
                                local_60 = local_60 + ((iVar7 >> 5) - (iVar7 >> 0x1f));
                            }
                            iVar6 = local_58;
                            if (*reinterpret_cast<int16_t*>(DAT_0086fea8 + iVar14) == 3) {
                                uVar15 = static_cast<uint32_t>(
                                             *reinterpret_cast<int16_t*>(DAT_0086feb8 + iVar14)) &
                                         0x8000000f;
                                if (static_cast<int32_t>(uVar15) < 0) {
                                    uVar15 = (uVar15 - 1 | 0xfffffff0) + 1;
                                }
                                uVar8 = static_cast<uint32_t>(
                                            *reinterpret_cast<int16_t*>(DAT_0086feba + iVar14)) &
                                        0x8000000f;
                                if (static_cast<int32_t>(uVar8) < 0) {
                                    uVar8 = (uVar8 - 1 | 0xfffffff0) + 1;
                                }
                                if (DAT_00871978[uVar8 + uVar15 * 0x10] == '\x01') {
                                    FUN_004f6090("Forest: /3");
                                    reinterpret_cast<void (*)(void*, int32_t, int32_t, uint32_t, int32_t)>(
                                        local_5c)(DAT_00869b48, local_68, iVar6, 0xffff4040, 0);
                                    local_58 = iVar6 + 0x14;
                                    local_60 = local_60 / 2;
                                }
                            }
                            DAT_0085a128 = *reinterpret_cast<int32_t*>(
                                reinterpret_cast<uint8_t*>(DAT_0086ff1c) + iVar14);
                            DAT_0085a124 = *reinterpret_cast<int32_t*>(
                                reinterpret_cast<uint8_t*>(DAT_0086ff4c) + iVar14);
                            if (DAT_008ca968 == 0) {
                                if ((_DAT_008ed61c & 1) == 0) {
                                    _DAT_008ed61c = _DAT_008ed61c | 1;
                                    DAT_008ed618 = timeGetTime();
                                }
                                DVar9 = timeGetTime();
                                uVar15 = static_cast<uint32_t>(local_64 - local_60) >> 0x1f;
                                DAT_008ca968 = static_cast<int32_t>(DVar9) +
                                    (30000 / static_cast<int64_t>(static_cast<int32_t>(
                                        ((local_64 - local_60) ^
                                         static_cast<int32_t>(uVar15)) -
                                        static_cast<int32_t>(uVar15) + 3)) -
                                     static_cast<int32_t>(DAT_008ed618));
                            }
                        }
                        iVar6 = local_64;
                        local_48 = local_48 +
                                   ((DAT_0086ea18[iVar2 * 0x53] -
                                     *reinterpret_cast<int32_t*>(DAT_0086fed8 + iVar14)) *
                                    local_48 * 4) /
                                       static_cast<int32_t>(reinterpret_cast<intptr_t>(local_30 + 0x7d));
                        if (local_48 < 0) {
                            local_48 = 0;
                        }
                        sVar13 = DAT_0086e9ec[iVar2 * 0xa6];
                        if (99 < sVar13) {
                            DAT_0086ea1c[iVar2 * 0x53] =
                                ((-static_cast<uint32_t>(param_1 != 0) & 2000) - 1000) +
                                DAT_0086ea5c[iVar2 * 0x53];
                            DAT_0086ea20[iVar2 * 0x53] =
                                ((-static_cast<uint32_t>((local_54 & 1) != 0) & 500) - 0xfa) +
                                DAT_0086ea8c[iVar2 * 0x53];
                        }
                        if (((DAT_0086ea08[iVar2 * 0x53] & 0x50) != 0) &&
                            ((DAT_0086ea08[iVar2 * 0x53] & 0x400) == 0)) {
                            *reinterpret_cast<int16_t*>(DAT_0086e9ee + iVar16) = sVar13;
                            *reinterpret_cast<uint16_t*>(DAT_0086feae + iVar14) =
                                *reinterpret_cast<uint16_t*>(DAT_0086feac + iVar14);
                            DAT_0086ea08[iVar2 * 0x53] = DAT_0086ea08[iVar2 * 0x53] | 6;
                            *reinterpret_cast<uint32_t*>(DAT_0086fec8 + iVar14) =
                                *reinterpret_cast<uint32_t*>(DAT_0086fec8 + iVar14) | 6;
                            if ((*reinterpret_cast<uint8_t*>(&DAT_0086ea08[iVar2 * 0x53]) & 0x10) != 0) {
                                iVar7 = local_64 / 2;
                                if (iVar7 < 1) {
                                    sVar13 = 0;
                                }
                                else {
                                    iVar12 = rand();
                                    sVar13 = static_cast<int16_t>(iVar12 % iVar7);
                                }
                                *reinterpret_cast<int16_t*>(DAT_0086feae + iVar14) =
                                    *reinterpret_cast<int16_t*>(DAT_0086feae + iVar14) + sVar13 +
                                    static_cast<int16_t>(iVar6);
                            }
                            if ((*reinterpret_cast<uint8_t*>(&DAT_0086ea08[iVar2 * 0x53]) & 0x20) != 0) {
                                local_1c = static_cast<uint32_t>(local_60 * 2 < iVar6);
                                if (iVar6 < local_60) {
                                    iVar6 = iVar6 * 2 - local_60;
                                    local_64 = iVar6;
                                }
                                else {
                                    local_60 = local_60 * 2 - iVar6;
                                }
                                if (iVar6 << 4 < 1) {
                                    local_30 = nullptr;
                                }
                                else {
                                    iVar7 = rand();
                                    local_30 = reinterpret_cast<int32_t*>(
                                        static_cast<intptr_t>(iVar7 % (iVar6 << 4)));
                                }
                                iVar7 = local_60 << 4;
                                if (iVar7 < 1) {
                                    iVar12 = 0;
                                }
                                else {
                                    iVar12 = rand();
                                    iVar12 = iVar12 % iVar7;
                                }
                                if ((static_cast<int32_t>(reinterpret_cast<intptr_t>(local_30)) <
                                     iVar12) &&
                                    ((DAT_0085a158 != 0 || (iVar6 < local_60)))) {
                                    *reinterpret_cast<uint16_t*>(DAT_0086e9ee + iVar16) = 100;
                                }
                                else {
                                    *reinterpret_cast<uint16_t*>(DAT_0086feae + iVar14) = 100;
                                    if (local_1c == 0) {
                                        *reinterpret_cast<int16_t*>(DAT_0086e9ee + iVar16) =
                                            *reinterpret_cast<int16_t*>(DAT_0086e9ee + iVar16) +
                                            static_cast<int16_t>(
                                                static_cast<int32_t>(
                                                    (100 - static_cast<int16_t>(DAT_0086e9ec[iVar2 * 0xa6])) +
                                                    static_cast<int32_t>(
                                                        ((100 - static_cast<int16_t>(DAT_0086e9ec[iVar2 * 0xa6])) >>
                                                         0x1f) &
                                                        3)) >>
                                                2);
                                    }
                                }
                            }
                            DAT_0086ea08[iVar2 * 0x53] = DAT_0086ea08[iVar2 * 0x53] | 0x400;
                        }
                        if ((_DAT_008ed61c & 1) == 0) {
                            _DAT_008ed61c = _DAT_008ed61c | 1;
                            DAT_008ed618 = timeGetTime();
                        }
                        DVar9 = timeGetTime();
                        if ((DAT_008ca968 < static_cast<int32_t>(DVar9 - DAT_008ed618)) &&
                            ((DAT_0086ea08[iVar2 * 0x53] & 0x50) != 0)) {
                            if ((DAT_0086ea08[iVar2 * 0x53] & 0x10) != 0) {
                                *reinterpret_cast<int16_t*>(DAT_0086feac + iVar14) =
                                    *reinterpret_cast<int16_t*>(DAT_0086feae + iVar14);
                                if (99 < *reinterpret_cast<int16_t*>(DAT_0086feae + iVar14)) {
                                    FUN_004a9270(param_1 == 0);
                                }
                                *reinterpret_cast<uint16_t*>(DAT_0086ea02 + iVar16) = 0xff9d;
                                *reinterpret_cast<uint16_t*>(DAT_0086ea04 + iVar16) = 0;
                            }
                            if ((*reinterpret_cast<uint8_t*>(&DAT_0086ea08[iVar2 * 0x53]) & 0x20) != 0) {
                                iVar7 = local_60 * 2;
                                if (iVar6 < local_60) {
                                    local_64 = iVar6 * 2 - local_60;
                                }
                                else {
                                    local_60 = iVar7 - iVar6;
                                }
                                if (*reinterpret_cast<int16_t*>(DAT_0086e9ee + iVar16) == 100) {
                                    DAT_0086e9ec[iVar2 * 0xa6] = 100;
                                    bVar20 = param_1 != 0;
                                    DAT_0086ea1c[iVar2 * 0x53] = 0;
                                    *reinterpret_cast<uint16_t*>(DAT_0086ea04 + iVar16) = 0;
                                    *reinterpret_cast<uint32_t*>(DAT_0086ea10 + iVar16) = 0xffffffff;
                                    *reinterpret_cast<uint16_t*>(DAT_0086ea02 + iVar16) = 0xff9d;
                                }
                                else {
                                    *reinterpret_cast<uint16_t*>(DAT_0086feac + iVar14) = 100;
                                    uVar11 = *reinterpret_cast<int32_t*>(DAT_0086fed0 + iVar14);
                                    DAT_0086ea1c[iVar2 * 0x53] = uVar11;
                                    *reinterpret_cast<uint32_t*>(DAT_0086ea10 + iVar16) =
                                        static_cast<uint32_t>(uVar11);
                                    uVar11 = *reinterpret_cast<int32_t*>(DAT_0086fed4 + iVar14);
                                    DAT_0086ea20[iVar2 * 0x53] = uVar11;
                                    *reinterpret_cast<uint32_t*>(DAT_0086ea14 + iVar16) =
                                        static_cast<uint32_t>(uVar11);
                                    DAT_0086e9f8[iVar2 * 0xa6] =
                                        *reinterpret_cast<int16_t*>(DAT_0086feb8 + iVar14);
                                    iVar12 = 0;
                                    DAT_0086e9fa[iVar2 * 0xa6] =
                                        *reinterpret_cast<int16_t*>(DAT_0086feba + iVar14);
                                    if (iVar7 < iVar6) {
                                        DAT_0086ea08[iVar2 * 0x53] =
                                            DAT_0086ea08[iVar2 * 0x53] & 0xffffffbf;
                                    }
                                    else {
                                        DAT_0086e9ec[iVar2 * 0xa6] =
                                            DAT_0086e9ec[iVar2 * 0xa6] + 0x14;
                                        local_30 = DAT_0086ea5c + iVar2 * 0x53;
                                        *reinterpret_cast<uint16_t*>(DAT_0086ea02 + iVar16) = 0xff9d;
                                        *reinterpret_cast<uint16_t*>(DAT_0086ea04 + iVar16) = 0;
                                        do {
                                            if ((*reinterpret_cast<int32_t*>(local_30) != 0) &&
                                                (iVar6 = (local_2c * 0xa6 + iVar12) * 2,
                                                 *reinterpret_cast<int16_t*>(DAT_0086eaec + iVar6) !=
                                                     0x77)) {
                                                *reinterpret_cast<uint16_t*>(DAT_0086eaec + iVar6) =
                                                    0x76;
                                                iVar7 = rand();
                                                *reinterpret_cast<int16_t*>(DAT_0086eb04 + iVar6) =
                                                    static_cast<int16_t>(iVar7 % 100);
                                            }
                                            iVar12 = iVar12 + 1;
                                            local_30 = local_30 + 1;
                                        } while (iVar12 < 0xc);
                                    }
                                    bVar20 = param_1 == 0;
                                }
                                FUN_004a9270(bVar20);
                            }
                            DAT_0086ea08[iVar2 * 0x53] =
                                DAT_0086ea08[iVar2 * 0x53] & 0xfffffb8f;
                            *reinterpret_cast<uint32_t*>(DAT_0086fec8 + iVar14) =
                                *reinterpret_cast<uint32_t*>(DAT_0086fec8 + iVar14) & 0xfffffdd7;
                        }
                    }
                }
            }
            iVar6 = DAT_0086ea5c[iVar2 * 0x53];
            iVar14 = (static_cast<int32_t>(
                          DAT_00725418[static_cast<int16_t>(DAT_0086e9e8[iVar2 * 0xa6]) * 7]) *
                      1000) / 0x32;
            local_1c = static_cast<uint32_t>((iVar6 + DAT_00725520 * -1000 + 0x2134) / 1000) &
                       0x8000000f;
            if (static_cast<int32_t>(local_1c) < 0) {
                local_1c = (local_1c - 1 | 0xfffffff0) + 1;
            }
            local_1c = local_1c * 0x10;
            uVar15 = static_cast<uint32_t>(
                         (DAT_0086ea8c[iVar2 * 0x53] + DAT_00725524 * -1000 + 0x2134) / 1000) &
                     0x8000000f;
            if (static_cast<int32_t>(uVar15) < 0) {
                uVar15 = (uVar15 - 1 | 0xfffffff0) + 1;
            }
            if (DAT_00871978[uVar15 + local_1c] == '\x01') {
                iVar14 = 0x28;
            }
            local_44 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(iVar14 * 2));
            uVar15 = 0x7d;
            if (*reinterpret_cast<int32_t*>(DAT_0086ea0c + iVar16) < 0) {
                uVar15 = 0xffffff83;
            }
            iVar14 = 1;
            iVar7 = static_cast<int32_t>((uVar15 ^ static_cast<uint32_t>(
                                                      static_cast<int32_t>(uVar15) >> 0x1f)) -
                                         static_cast<uint32_t>(
                                             static_cast<int32_t>(uVar15) >> 0x1f));
            while (32000 < iVar7) {
                uVar15 = static_cast<uint32_t>(static_cast<int32_t>(uVar15) / 2);
                iVar14 = iVar14 * 2;
                iVar7 = static_cast<int32_t>((uVar15 ^ static_cast<uint32_t>(
                                                          static_cast<int32_t>(uVar15) >> 0x1f)) -
                                             static_cast<uint32_t>(
                                                 static_cast<int32_t>(uVar15) >> 0x1f));
            }
            iVar7 = FUN_004953d0();
            local_20 = iVar7 * iVar14 + iVar6;
            uVar15 = 0x7d;
            if (*reinterpret_cast<int32_t*>(DAT_0086ea0c + iVar16) + 0x40000000 < 0) {
                uVar15 = 0xffffff83;
            }
            iVar6 = 1;
            iVar14 = static_cast<int32_t>((uVar15 ^ static_cast<uint32_t>(
                                                      static_cast<int32_t>(uVar15) >> 0x1f)) -
                                         static_cast<uint32_t>(
                                             static_cast<int32_t>(uVar15) >> 0x1f));
            while (32000 < iVar14) {
                uVar15 = static_cast<uint32_t>(static_cast<int32_t>(uVar15) / 2);
                iVar6 = iVar6 * 2;
                iVar14 = static_cast<int32_t>((uVar15 ^ static_cast<uint32_t>(
                                                          static_cast<int32_t>(uVar15) >> 0x1f)) -
                                             static_cast<uint32_t>(
                                                 static_cast<int32_t>(uVar15) >> 0x1f));
            }
            iVar14 = FUN_004953d0();
            local_1c = static_cast<uint32_t>(iVar14 * iVar6) + DAT_0086ea8c[iVar2 * 0x53];
            FUN_004e7510(static_cast<float>(local_20),
                         static_cast<float>(static_cast<int32_t>(local_1c)), 0);
            local_20 = FUN_005f0ddc();
            local_20 = local_20 - DAT_0086ea18[iVar2 * 0x53];
            if (99 < DAT_0086e9ec[iVar2 * 0xa6]) {
                local_44 = reinterpret_cast<int32_t*>(
                    static_cast<intptr_t>(static_cast<int32_t>(reinterpret_cast<intptr_t>(local_44)) +
                                          0x28));
            }
            iVar6 = (static_cast<int32_t>(reinterpret_cast<intptr_t>(local_44)) -
                     (DAT_00725530 * local_20 *
                      static_cast<int32_t>(reinterpret_cast<intptr_t>(local_44))) / 6000) /
                    static_cast<int32_t>((~(DAT_0086ea08[iVar2 * 0x53] >> 5)) & 1 | 2);
            if (iVar6 < 10) {
                iVar6 = 10;
            }
            if (((param_1 == 0) || ((DAT_0086ea08[iVar2 * 0x53] & 2) != 0)) ||
                (*reinterpret_cast<int16_t*>(DAT_0086e9f0 + iVar16) != 0)) {
                local_44 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(iVar6 + iVar6 / 2));
            }
            else {
                local_44 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(iVar6 << 3));
            }
            if (DAT_0086ea1c[iVar2 * 0x53] != 0) {
                iVar14 = DAT_0086ea1c[iVar2 * 0x53] - DAT_0086ea5c[iVar2 * 0x53];
                iVar6 = DAT_0086ea20[iVar2 * 0x53] - DAT_0086ea8c[iVar2 * 0x53];
                if (iVar14 < 0) {
                    iVar14 = -iVar14;
                }
                if (iVar6 < 0) {
                    iVar6 = -iVar6;
                }
                if (iVar6 < iVar14) {
                    iVar6 = iVar6 + iVar14 * 2;
                }
                else {
                    iVar6 = iVar14 + iVar6 * 2;
                }
                if (iVar6 / 2 < static_cast<int32_t>(reinterpret_cast<intptr_t>(local_44))) {
                    DAT_0086ea1c[iVar2 * 0x53] = 0;
                    if (((param_1 == 0) && ((DAT_008ca978 & 0x8000) == 0)) &&
                        ((DAT_0085a158 == 0 && (DAT_008ca97c == 0)))) {
                        DAT_008ca978 = DAT_008ca978 | 0x8000;
                        FUN_004f6090(
                            "Your goal is to defeat the enemy and reach the city gates.\n");
                        FUN_004879f0(0x28, 0);
                        iVar6 = 0;
                        do {
                            pcVar1 = DAT_00869b48 + iVar6;
                            DAT_0086c460[iVar6] = *pcVar1;
                            iVar6 = iVar6 + 1;
                        } while (*pcVar1 != '\0');
                        DAT_00725534 = 0x96;
                    }
                }
                else {
                    uVar11 = FUN_004db270();
                    *reinterpret_cast<uint32_t*>(DAT_0086ea0c + iVar16) =
                        static_cast<uint32_t>(uVar11);
                    *reinterpret_cast<int32_t*>(DAT_0086eabc + iVar16) = uVar11;
                }
                if (DAT_0086e9ec[iVar2 * 0xa6] < 100) {
                    DAT_008ca964 = 1;
                }
            }
            *reinterpret_cast<uint16_t*>(DAT_0086e9f6 + iVar16) = 0;
            local_5c = 0;
            local_1c = static_cast<uint32_t>(local_2c * 0x53);
            do {
                pcVar3 = static_cast<int32_t>(local_5c) + static_cast<int32_t>(local_1c);
                iVar6 = pcVar3 * 4;
                if (DAT_0086ea5c[pcVar3] != 0) {
                    iVar14 = (static_cast<int32_t>(local_5c) + local_2c * 0xa6) * 2;
                    if (*reinterpret_cast<int16_t*>(DAT_0086eaec + iVar14) == 0x77) {
                        local_18 = 0;
                        FUN_004bc0d0();
                        iVar6 = FUN_005f0ddc();
                        iVar6 = iVar6 + -1;
                        iVar7 = *reinterpret_cast<int16_t*>(DAT_0086eb04 + iVar14) + DAT_00725530;
                        if (iVar7 < 0) {
                            iVar7 = 0;
                        }
                        if (iVar6 < iVar7) {
                            iVar7 = iVar6;
                        }
                        *reinterpret_cast<int16_t*>(DAT_0086eb04 + iVar14) =
                            static_cast<int16_t>(iVar7);
                        if (static_cast<int16_t>(iVar7) == iVar6) {
                            DAT_0086ea5c[pcVar3] = 0;
                        }
                    }
                    else {
                        *reinterpret_cast<int16_t*>(DAT_0086e9f6 + iVar16) =
                            *reinterpret_cast<int16_t*>(DAT_0086e9f6 + iVar16) + 1;
                        if (local_5c == 0) {
                            local_28 = DAT_0086ea1c[iVar2 * 0x53];
                            local_24 = DAT_0086ea20[iVar2 * 0x53];
                        }
                        else {
                            FUN_00431bc0(DAT_0086ea5c[iVar2 * 0x53],
                                         DAT_0086ea8c[iVar2 * 0x53],
                                         static_cast<int32_t>(local_5c), &local_28, &local_24);
                        }
                        iVar7 = DAT_00725530;
                        local_10 = local_28 - DAT_0086ea5c[pcVar3];
                        local_14 = local_24 - DAT_0086ea8c[pcVar3];
                        iVar12 = local_10;
                        if (local_10 < 0) {
                            iVar12 = -local_10;
                        }
                        iVar10 = local_14;
                        if (local_14 < 0) {
                            iVar10 = -local_14;
                        }
                        if (iVar10 < iVar12) {
                            iVar10 = iVar10 + iVar12 * 2;
                        }
                        else {
                            iVar10 = iVar12 + iVar10 * 2;
                        }
                        local_30 = reinterpret_cast<int32_t*>(
                            static_cast<intptr_t>(iVar10 / 2));
                        if (local_28 == 0) {
                            local_30 = nullptr;
                        }
                        if (*reinterpret_cast<int16_t*>(DAT_0086eaec + iVar14) == 100) {
                            *reinterpret_cast<int16_t*>(DAT_0086eb04 + iVar14) =
                                *reinterpret_cast<int16_t*>(DAT_0086eb04 + iVar14) +
                                (static_cast<int16_t>((DAT_00725530 * 5) / 2) -
                                 static_cast<int16_t>(
                                     (((DAT_00725530 * 3) / 2 +
                                       static_cast<int32_t>(local_5c) * 3) *
                                      local_20 * 8) /
                                     1000)) +
                                static_cast<int16_t>(local_5c) * 3;
                        }
                        else {
                            *reinterpret_cast<int16_t*>(DAT_0086eb04 + iVar14) =
                                *reinterpret_cast<int16_t*>(DAT_0086eb04 + iVar14) +
                                static_cast<int16_t>(DAT_00725530) +
                                static_cast<int16_t>(local_5c) * 3;
                        }
                        local_4c = static_cast<uint32_t>(
                                       (DAT_0086ea5c[iVar2 * 0x53] + DAT_00725520 * -1000 +
                                        0x2134) /
                                       1000) &
                                   0x8000000f;
                        if (static_cast<int32_t>(local_4c) < 0) {
                            local_4c = (local_4c - 1 | 0xfffffff0) + 1;
                        }
                        local_4c = local_4c * 0x10;
                        uVar15 = static_cast<uint32_t>(
                                     (DAT_0086ea8c[iVar2 * 0x53] + DAT_00725524 * -1000 +
                                      0x2134) /
                                     1000) &
                                 0x8000000f;
                        if (static_cast<int32_t>(uVar15) < 0) {
                            uVar15 = (uVar15 - 1 | 0xfffffff0) + 1;
                        }
                        if (DAT_00871978[uVar15 + local_4c] == '\x01') {
                            *reinterpret_cast<int16_t*>(DAT_0086eb04 + iVar14) =
                                *reinterpret_cast<int16_t*>(DAT_0086eb04 + iVar14) -
                                static_cast<int16_t>(
                                    static_cast<int32_t>(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2);
                        }
                        if (99 < DAT_0086e9ec[iVar2 * 0xa6]) {
                            *reinterpret_cast<int16_t*>(DAT_0086eb04 + iVar14) =
                                *reinterpret_cast<int16_t*>(DAT_0086eb04 + iVar14) +
                                static_cast<int16_t>(iVar7 / 2);
                        }
                        if (*reinterpret_cast<int16_t*>(DAT_0086eb04 + iVar14) < 0) {
                            *reinterpret_cast<uint16_t*>(DAT_0086eb04 + iVar14) = 0;
                        }
                        if ((static_cast<int32_t>(reinterpret_cast<intptr_t>(local_30)) <
                             static_cast<int32_t>(reinterpret_cast<intptr_t>(local_44))) ||
                            (*reinterpret_cast<int16_t*>(DAT_0086eaec + iVar14) == 0x76)) {
                            *reinterpret_cast<uint32_t*>(DAT_0086eabc + iVar6) =
                                *reinterpret_cast<uint32_t*>(DAT_0086eabc + iVar16);
                            iVar7 = static_cast<int32_t>(DAT_0086e9e8[iVar2 * 0xa6]);
                            switch (iVar7) {
                            case 1:
                            case 2:
                            case 5:
                            case 8:
                                if ((local_40 == 0) || (DAT_0072541c[iVar7 * 7] == '\0'))
                                    goto switchD_004388e4_caseD_3;
                                local_4c = 0x71;
                                break;
                            case 3:
switchD_004388e4_caseD_3:
                                local_4c = 0x70;
                                break;
                            default:
                                if ((local_40 == 0) || (DAT_0072541c[iVar7 * 7] == '\0')) {
                                    local_4c = static_cast<uint32_t>(local_5c) & 0x80000003;
                                    if (static_cast<int32_t>(local_4c) < 0) {
                                        local_4c = (local_4c - 1 | 0xfffffffc) + 1;
                                    }
                                    local_4c = local_4c + 0x70;
                                }
                                else {
                                    local_4c = 0x71;
                                }
                            }
                            if (local_34 == 0) {
                                sVar13 = *reinterpret_cast<int16_t*>(DAT_0086eaec + iVar14);
                                if ((sVar13 == 0x6f) || (sVar13 == 0x76)) {
                                    local_4 = 0;
                                    if (sVar13 != -1) {
                                        FUN_004bc0d0();
                                    }
                                    iVar6 = FUN_005f0ddc();
                                    if (iVar6 < *reinterpret_cast<int16_t*>(DAT_0086eb04 + iVar14)) {
                                        *reinterpret_cast<uint16_t*>(DAT_0086eaec + iVar14) = 0x6e;
LAB_00438db3:
                                        *reinterpret_cast<uint16_t*>(DAT_0086eb04 + iVar14) = 0;
                                    }
                                }
                                else {
                                    if (sVar13 != 0x6e) {
                                        *reinterpret_cast<uint16_t*>(DAT_0086eb04 + iVar14) = 0;
                                    }
                                    *reinterpret_cast<uint16_t*>(DAT_0086eaec + iVar14) = 0x6e;
                                    if ((param_1 == 0) && (local_54 == DAT_008ca95c)) {
                                        iVar6 = rand();
                                        uVar15 = local_54;
                                        if ((iVar6 % 0x32 == 0) &&
                                            (iVar6 = FUN_004319b0(), iVar6 != 1)) {
                                            *reinterpret_cast<int16_t*>(
                                                DAT_0086eaec +
                                                (static_cast<int32_t>(local_5c) +
                                                 static_cast<int32_t>(uVar15) * 0xa6) *
                                                    2) = 0x6f;
                                            *reinterpret_cast<int16_t*>(
                                                DAT_0086eb04 +
                                                (static_cast<int32_t>(local_5c) +
                                                 static_cast<int32_t>(uVar15) * 0xa6) *
                                                    2) = 0;
                                        }
                                    }
                                }
                            }
                            else {
                                sVar13 = *reinterpret_cast<int16_t*>(DAT_0086eb1c + iVar14);
                                iVar7 = sVar13 * 0x1e;
                                *reinterpret_cast<int32_t*>(DAT_0086eabc + iVar6) = local_3c;
                                *reinterpret_cast<int16_t*>(DAT_0086eb1c + iVar14) =
                                    static_cast<int16_t>(sVar13 + 1);
                                local_c = 0;
                                FUN_004bc0d0();
                                iVar6 = FUN_005f0ddc();
                                if (iVar7 == 0) {
                                    DAT_0086ea08[iVar2 * 0x53] =
                                        DAT_0086ea08[iVar2 * 0x53] &
                                        ~static_cast<uint32_t>(
                                            0x10000 << (static_cast<uint8_t>(local_5c) & 0x1f));
                                }
                                if (local_40 != 0) {
                                    iVar7 = iVar7 + iVar6;
                                }
                                if (iVar7 < iVar6) {
                                    *reinterpret_cast<uint16_t*>(DAT_0086eaec + iVar14) = 0x74;
                                    *reinterpret_cast<int16_t*>(DAT_0086eb04 + iVar14) =
                                        static_cast<int16_t>(iVar7);
                                }
                                else if (iVar7 <
                                         static_cast<int32_t>(
                                             DAT_0072541d[static_cast<int16_t>(
                                                              DAT_0086e9e8[iVar2 * 0xa6]) *
                                                          7]) *
                                             500) {
                                    *reinterpret_cast<uint16_t*>(DAT_0086eaec + iVar14) = 0x74;
                                    *reinterpret_cast<int16_t*>(DAT_0086eb04 + iVar14) =
                                        static_cast<int16_t>(iVar6) + -1;
                                    if (iVar6 == 0) {
                                        *reinterpret_cast<uint16_t*>(DAT_0086eaec + iVar14) =
                                            static_cast<uint16_t>(local_4c);
                                        goto LAB_00438db3;
                                    }
                                }
                                else {
                                    iVar7 = iVar7 +
                                            static_cast<int32_t>(
                                                DAT_0072541d[static_cast<int16_t>(
                                                                 DAT_0086e9e8[iVar2 * 0xa6]) *
                                                             7]) *
                                                -500;
                                    local_8 = 0;
                                    if (local_4c != 0xffffffff) {
                                        FUN_004bc0d0();
                                    }
                                    iVar12 = FUN_005f0ddc();
                                    if (iVar7 < iVar12) {
                                        *reinterpret_cast<int16_t*>(DAT_0086eb04 + iVar14) =
                                            static_cast<int16_t>(iVar7);
                                        *reinterpret_cast<uint16_t*>(DAT_0086eaec + iVar14) =
                                            static_cast<uint16_t>(local_4c);
                                        iVar6 = local_50 - local_38;
                                        *reinterpret_cast<uint32_t*>(DAT_0086fec8 +
                                                                     iVar6 * 0x14c) =
                                            *reinterpret_cast<uint32_t*>(DAT_0086fec8 +
                                                                         iVar6 * 0x14c) |
                                            8;
                                        uVar15 = static_cast<uint32_t>(
                                            0x10000 << (static_cast<uint8_t>(local_5c) & 0x1f));
                                        if ((uVar15 & DAT_0086ea08[iVar2 * 0x53]) == 0) {
                                            FUN_004a90a0(static_cast<int32_t>(local_5c),
                                                         local_40);
                                            DAT_0086ea08[iVar2 * 0x53] =
                                                DAT_0086ea08[iVar2 * 0x53] | uVar15 | 6;
                                            uVar11 = DAT_0086ea8c[iVar2 * 0x53];
                                            iVar14 = (-static_cast<int32_t>(local_40 != 0) & 0x50) +
                                                     0x14;
                                            DAT_008ca978 = 0xffffffff;
                                            *reinterpret_cast<uint32_t*>(DAT_0086ea24 + iVar16) =
                                                DAT_0086ea5c[iVar2 * 0x53];
                                            *reinterpret_cast<uint32_t*>(DAT_0086ea28 + iVar16) =
                                                static_cast<uint32_t>(uVar11);
                                            if (iVar14 == 0) {
                                                iVar7 = 0;
                                            }
                                            else {
                                                iVar7 = rand();
                                                iVar7 = iVar7 % iVar14;
                                            }
                                            if ((iVar7 < local_48) &&
                                                ((100 - *reinterpret_cast<int16_t*>(
                                                            DAT_0086feae + iVar6 * 0x14c)) /
                                                     0xd +
                                                 1 <
                                                 static_cast<int32_t>(static_cast<int16_t>(
                                                     DAT_0086feaa[iVar6 * 0xa6])))) {
                                                local_30 = nullptr;
                                                do {
                                                    iVar14 = rand();
                                                    iVar14 = iVar14 % 0xc;
                                                    local_30 = reinterpret_cast<int32_t*>(
                                                        static_cast<intptr_t>(
                                                            reinterpret_cast<intptr_t>(local_30) +
                                                            1));
                                                    if (99 < static_cast<int32_t>(
                                                                 reinterpret_cast<intptr_t>(local_30)))
                                                        goto LAB_00438dbc;
                                                } while (
                                                    ((*reinterpret_cast<int16_t*>(
                                                          DAT_0086ffac +
                                                          (iVar6 * 0xa6 + iVar14) * 2) == 0x77) ||
                                                     (DAT_0086ff1c[iVar6 * 0x53 + iVar14] == 0)) ||
                                                    (iVar14 == 0));
                                                iVar7 = (iVar6 * 0xa6 + iVar14) * 2;
                                                iVar12 = (iVar6 * 0x53 + iVar14) * 4;
                                                *reinterpret_cast<uint16_t*>(DAT_0086ffac + iVar7) =
                                                    0x77;
                                                *reinterpret_cast<uint32_t*>(DAT_0086feec + iVar12) =
                                                    1;
                                                *reinterpret_cast<uint16_t*>(DAT_0086ffc4 + iVar7) =
                                                    0;
                                                iVar7 = rand();
                                                *reinterpret_cast<int32_t*>(DAT_0086ff7c + iVar12) =
                                                    (iVar7 % 0x168) * 0xb60b60;
                                                FUN_004a91e0(iVar14);
                                                if (2 < static_cast<int16_t>(
                                                            DAT_0086feaa[iVar6 * 0xa6])) {
                                                    DAT_0086feaa[iVar6 * 0xa6] =
                                                        static_cast<int16_t>(
                                                            DAT_0086feaa[iVar6 * 0xa6] + -1);
                                                }
                                            }
                                        }
                                        else {
                                            iVar7 = iVar7 - iVar12;
                                            if (local_40 != 0) {
                                                *reinterpret_cast<uint16_t*>(DAT_0086eb1c +
                                                                             iVar14) = 0;
                                            }
                                            if (iVar6 <= iVar7) {
                                                if (static_cast<int32_t>(
                                                        DAT_0072541d[static_cast<int16_t>(
                                                                         DAT_0086e9e8[iVar2 * 0xa6]) *
                                                                     7]) *
                                                        800 <=
                                                    iVar7) {
                                                    uVar15 = rand();
                                                    uVar15 = uVar15 & 0x8000000f;
                                                    bVar20 = uVar15 == 0;
                                                    if (static_cast<int32_t>(uVar15) < 0) {
                                                        bVar20 = (uVar15 - 1 | 0xfffffff0) ==
                                                                 0xffffffff;
                                                    }
                                                    if (bVar20) {
                                                        *reinterpret_cast<uint16_t*>(
                                                            DAT_0086eb1c + iVar14) = 0;
                                                        goto LAB_00438dbc;
                                                    }
                                                }
                                                *reinterpret_cast<uint16_t*>(DAT_0086eaec +
                                                                             iVar14) = 0x74;
                                                goto LAB_00438db3;
                                            }
                                            *reinterpret_cast<uint16_t*>(DAT_0086eaec + iVar14) =
                                                0x74;
                                            *reinterpret_cast<int16_t*>(DAT_0086eb04 + iVar14) =
                                                static_cast<int16_t>(
                                                    static_cast<int16_t>(iVar6) -
                                                    static_cast<int16_t>(iVar7)) +
                                                -1;
                                        }
                                    }
                                }
                            }
                        }
                        else if (((*reinterpret_cast<int16_t*>(DAT_0086eaec + iVar14) == 100) ||
                                  (iVar7 = rand(), iVar7 % 6 == 0)) ||
                                 (local_5c == 0)) {
                            uVar11 = FUN_004db270();
                            *reinterpret_cast<uint32_t*>(DAT_0086eabc + iVar6) =
                                static_cast<uint32_t>(uVar11);
                            iVar6 = FUN_004db210();
                            DAT_0086ea5c[pcVar3] = DAT_0086ea5c[pcVar3] + iVar6;
                            iVar6 = FUN_004db210();
                            sVar13 = *reinterpret_cast<int16_t*>(DAT_0086eaec + iVar14);
                            DAT_0086ea8c[pcVar3] = DAT_0086ea8c[pcVar3] + iVar6;
                            if (sVar13 != 100) {
                                *reinterpret_cast<uint16_t*>(DAT_0086eb04 + iVar14) = 0;
                            }
                            *reinterpret_cast<uint16_t*>(DAT_0086eaec + iVar14) = 100;
                            DAT_0086ea08[iVar2 * 0x53] =
                                DAT_0086ea08[iVar2 * 0x53] | 0x800;
                        }
                    }
                }
LAB_00438dbc:
                local_5c = local_5c + 1;
            } while (static_cast<int32_t>(local_5c) < 0xc);
        }
        local_54 = local_54 + 1;
        if (0xf < static_cast<int32_t>(local_54)) {
            if (!bVar5) {
                DAT_008ca974 = DAT_008ca974 +
                               static_cast<int32_t>(static_cast<uint32_t>(param_1 != 0) * 2) + -1;
            }
            return;
        }
    } while (true);
}


// ===== 0x43b8e0 (delegated part, unified declarations) =====
extern int32_t DAT_007253b4;   // year base

// 0x0043b8e0 — observed shape
void FUN_0043b8e0(int in_ECX, char *in_EAX, char *param_1, uint32_t param_2,
                  uint32_t *param_3) {
    int32_t uVar1;
    int32_t iVar2;
    int32_t inEax;
    char *pcVar3;
    char *pcVar4;
    char **ppcVar5 = nullptr;   // set on every path that reaches the tail
    char *pcVar6 = nullptr;     // ditto

    // Message slots. Kept as one array because some cases take &local_1c /
    // &local_20 and write [1]/[2] into the neighbouring slots.
    char *msg_args[4];
    char *&local_20 = msg_args[0];
    char *&local_1c = msg_args[1];
    char *&local_18 = msg_args[2];
    char *&local_14 = msg_args[3];

    *param_3 = 0;

    int32_t *const dateRec =
        reinterpret_cast<int32_t *>(&DAT_00862d20 + in_ECX * 0x1c);
    local_18 = as_ptr((*dateRec / 6000) % 0xc);
    local_14 = as_ptr((*dateRec / 6000) / 0xc + DAT_007253b4);
    local_1c = as_ptr("@MONTH @NUM: ");
    local_20 = as_ptr(0x43b931);
    FUN_004f6090();

    int8_t const tag = *reinterpret_cast<int8_t *>(&DAT_00862d10 + in_ECX * 7);
    if (0x42u < static_cast<uint32_t>(static_cast<int32_t>(tag)) - 3u) {
        return;
    }

    inEax = as_int(in_EAX);
    iVar2 = inEax >> 4;
    pcVar4 = as_ptr(inEax >> 8);

    switch (tag) {
    case 3:  // '\x03'
        local_1c = as_ptr((&DAT_008dbd08)[inEax * 3]);
        local_18 = as_ptr((&DAT_008dbd0c)[inEax * 3]);
        local_14 = as_ptr((&DAT_008dbd10)[inEax * 3]);
        local_20 = as_ptr("Immigrants are flocking to @CITYNAME.");
        FUN_004f60b0();
        return;

    case 4:  // '\x04'
        local_1c = as_ptr((&DAT_008dbd08)[inEax * 3]);
        local_18 = as_ptr((&DAT_008dbd0c)[inEax * 3]);
        local_14 = as_ptr((&DAT_008dbd10)[inEax * 3]);
        local_20 = as_ptr("Malaria strikes @CITYNAME.");
        FUN_004f60b0();
        return;

    case 5:  // '\x05'
        if (param_1 == as_ptr(-1)) {
            local_1c = as_ptr((&DAT_008dbd08)[inEax * 3]);
            local_18 = as_ptr((&DAT_008dbd0c)[inEax * 3]);
            local_14 = as_ptr((&DAT_008dbd10)[inEax * 3]);
            local_20 = as_ptr("New Governor for @CITYNAME disappears.");
            FUN_004f60b0();
            return;
        }
        local_1c = as_ptr((&DAT_008dbd08)[inEax * 3]);
        local_18 = as_ptr((&DAT_008dbd0c)[inEax * 3]);
        local_14 = as_ptr((&DAT_008dbd10)[inEax * 3]);
        local_20 = as_ptr("New Governor in @CITYNAME.");
        FUN_004f60b0();
        return;

    case 6:  // '\x06'
        local_1c = as_ptr((&DAT_008dbd08)[inEax * 3]);
        local_18 = as_ptr((&DAT_008dbd0c)[inEax * 3]);
        local_14 = as_ptr((&DAT_008dbd10)[inEax * 3]);
        local_20 = as_ptr("Pirates attack @CITYNAME.");
        FUN_004f60b0();
        return;

    case 7:  // '\a'
        local_1c = as_ptr((&DAT_008dbd08)[as_int(param_1) * 3]);
        local_18 = as_ptr((&DAT_008dbd0c)[as_int(param_1) * 3]);
        local_14 = as_ptr((&DAT_008dbd10)[as_int(param_1) * 3]);
        FUN_004f60b0("@NATION captures the city of @CITYNAME.");
        return;

    case 8:  // '\b'
        local_1c = as_ptr((&DAT_008dbd08)[inEax * 3]);
        local_18 = as_ptr((&DAT_008dbd0c)[inEax * 3]);
        local_14 = as_ptr((&DAT_008dbd10)[inEax * 3]);
        local_20 = as_ptr("Healthy sugar crop in @CITYNAME.");
        FUN_004f60b0();
        return;

    case 9:  // '\t'
        local_1c = as_ptr((&DAT_008dbd08)[inEax * 3]);
        local_18 = as_ptr((&DAT_008dbd0c)[inEax * 3]);
        local_14 = as_ptr((&DAT_008dbd10)[inEax * 3]);
        local_20 = as_ptr("Indians attack @CITYNAME.");
        FUN_004f60b0();
        return;

    case 10:  // '\n'
        local_1c = as_ptr((&DAT_008dbd08)[inEax * 3]);
        local_18 = as_ptr((&DAT_008dbd0c)[inEax * 3]);
        local_14 = as_ptr((&DAT_008dbd10)[inEax * 3]);
        local_20 = as_ptr("Reinforcements arrive in @CITYNAME.");
        FUN_004f60b0();
        return;

    case 12:  // '\f'
        local_1c = as_ptr((&DAT_008dbd08)[inEax * 3]);
        local_18 = as_ptr((&DAT_008dbd0c)[inEax * 3]);
        local_14 = as_ptr((&DAT_008dbd10)[inEax * 3]);
        local_20 = as_ptr("Gold discovered in @CITYNAME.");
        FUN_004f60b0();
        return;

    case 14:  // '\x0e'
        local_1c = as_ptr((&DAT_008dbd08)[inEax * 3]);
        local_18 = as_ptr((&DAT_008dbd0c)[inEax * 3]);
        local_14 = as_ptr((&DAT_008dbd10)[inEax * 3]);
        local_20 = as_ptr("Price on your head in @CITYNAME.");
        FUN_004f60b0();
        return;

    case 15:  // '\x0f'
        local_1c = as_ptr((&DAT_008dbd08)[inEax * 3]);
        local_18 = as_ptr((&DAT_008dbd0c)[inEax * 3]);
        local_14 = as_ptr((&DAT_008dbd10)[inEax * 3]);
        local_20 = as_ptr("Pirate hunter sails from @CITYNAME.");
        FUN_004f60b0();
        return;

    case 0x10:  // '\x10'
        local_18 = as_ptr(inEax & 0xf);
        local_1c = as_ptr("@NATION at war with @NATION.");
        local_20 = as_ptr(0x43bd0c);
        local_14 = as_ptr(iVar2);
        FUN_004f60b0();
        return;

    case 0x11:  // '\x11'
        local_18 = as_ptr(inEax & 0xf);
        local_1c = as_ptr("@NATION no longer at war with @NATION.");
        local_20 = as_ptr(0x43bd2d);
        local_14 = as_ptr(iVar2);
        FUN_004f60b0();
        return;

    case 0x12:  // '\x12'
        local_18 = as_ptr(inEax & 0xf);
        local_1c = as_ptr("@NATION and @NATION sign Peace Treaty.");
        local_20 = as_ptr(0x43bd4e);
        local_14 = as_ptr(iVar2);
        FUN_004f60b0();
        return;

    case 0x13:  // '\x13'
        local_18 = as_ptr(inEax & 0xf);
        local_1c = as_ptr("@NATION and @NATION cancel Peace Treaty.");
        local_20 = as_ptr(0x43bd6f);
        local_14 = as_ptr(iVar2);
        FUN_004f60b0();
        return;

    case 0x14:  // '\x14'
        local_14 = as_ptr(inEax & 0xf);
        local_18 = as_ptr("@NATION offers Pirate Amnesty.");
        local_1c = as_ptr(0x43bd8a);
        FUN_004f60b0();
        return;

    case 0x15:  // '\x15'
        local_1c = as_ptr((&DAT_008dbd08)[as_int(param_1) * 3]);
        local_18 = as_ptr((&DAT_008dbd0c)[as_int(param_1) * 3]);
        local_14 = as_ptr((&DAT_008dbd10)[as_int(param_1) * 3]);
        FUN_004f60b0("@NATION captures settlement of @CITYNAME.");
        return;

    case 0x20:  // ' '
        local_1c = as_ptr((&DAT_008dbd08)[as_int(param_1) * 3]);
        local_18 = as_ptr((&DAT_008dbd0c)[as_int(param_1) * 3]);
        local_14 = as_ptr((&DAT_008dbd10)[as_int(param_1) * 3]);
        local_20 = as_ptr(inEax & 0xff);
        FUN_004f60b0("Engaged @ANATIONALITY @SHIPTYPE near @CITYNAME.", pcVar4);
        return;

    case 0x21:  // '!'
        switch (param_2) {
        case 6:
            local_1c = as_ptr((&DAT_008dbd08)[as_int(param_1) * 3]);
            local_18 = as_ptr((&DAT_008dbd0c)[as_int(param_1) * 3]);
            local_14 = as_ptr((&DAT_008dbd10)[as_int(param_1) * 3]);
            local_20 = as_ptr("Captured Pirate raiders near @CITYNAME.");
            FUN_004f60b0();
            return;
        case 7:
switchD_0043bfa7_caseD_7:
            local_18 = as_ptr("Intercepted @ANATIONALITY invasion force.");
            local_1c = as_ptr(0x43bfc1);
            local_14 = pcVar4;
            FUN_004f60b0();
            return;
        case 9:
            local_1c = as_ptr((&DAT_008dbd08)[as_int(param_1) * 3]);
            local_18 = as_ptr((&DAT_008dbd0c)[as_int(param_1) * 3]);
            local_14 = as_ptr((&DAT_008dbd10)[as_int(param_1) * 3]);
            local_20 = as_ptr("Captured an Indian war canoe near @CITYNAME.");
            FUN_004f60b0();
            return;
        case 0xc:
            ppcVar5 = &local_1c;
            pcVar6 = as_ptr("Captured @ANATIONALITY treasure ship near @CITYNAME.");
            local_20 = pcVar4;
            break;
        case 0xd:
            local_1c = as_ptr((&DAT_008dbd08)[as_int(param_1) * 3]);
            local_18 = as_ptr((&DAT_008dbd0c)[as_int(param_1) * 3]);
            local_14 = as_ptr((&DAT_008dbd10)[as_int(param_1) * 3]);
            local_20 = pcVar4;
            FUN_004f60b0("Captured @ANATIONALITY payroll courier near @CITYNAME.");
            return;
        case 0xe:
            local_1c = as_ptr((&DAT_008dbd08)[as_int(param_1) * 3]);
            local_18 = as_ptr((&DAT_008dbd0c)[as_int(param_1) * 3]);
            local_14 = as_ptr((&DAT_008dbd10)[as_int(param_1) * 3]);
            local_20 = pcVar4;
            FUN_004f60b0("Captured @ANATIONALITY grain transport near @CITYNAME.");
            return;
        default:
            local_1c = as_ptr((&DAT_008dbd08)[as_int(param_1) * 3]);
            local_18 = as_ptr((&DAT_008dbd0c)[as_int(param_1) * 3]);
            local_14 = as_ptr((&DAT_008dbd10)[as_int(param_1) * 3]);
            local_20 = as_ptr(inEax & 0xff);
            FUN_004f60b0("Captured @ANATIONALITY @SHIPTYPE near @CITYNAME.", pcVar4);
            return;
        }
        break;

    case 0x22:  // '"'
        switch (param_2) {
        case 6:
            local_1c = as_ptr((&DAT_008dbd08)[as_int(param_1) * 3]);
            local_18 = as_ptr((&DAT_008dbd0c)[as_int(param_1) * 3]);
            local_14 = as_ptr((&DAT_008dbd10)[as_int(param_1) * 3]);
            local_20 = as_ptr("Sank Pirate raiders near @CITYNAME.");
            FUN_004f60b0();
            return;
        case 7:
            goto switchD_0043bfa7_caseD_7;
        case 9:
            local_1c = as_ptr((&DAT_008dbd08)[as_int(param_1) * 3]);
            local_18 = as_ptr((&DAT_008dbd0c)[as_int(param_1) * 3]);
            local_14 = as_ptr((&DAT_008dbd10)[as_int(param_1) * 3]);
            local_20 = as_ptr("Sank an Indian war canoe near @CITYNAME.");
            FUN_004f60b0();
            return;
        case 0xc:
            local_1c = as_ptr((&DAT_008dbd08)[as_int(param_1) * 3]);
            local_18 = as_ptr((&DAT_008dbd0c)[as_int(param_1) * 3]);
            local_14 = as_ptr((&DAT_008dbd10)[as_int(param_1) * 3]);
            local_20 = pcVar4;
            FUN_004f60b0("Sank @ANATIONALITY treasure ship near @CITYNAME.");
            return;
        case 0xd:
            ppcVar5 = &local_1c;
            pcVar6 = as_ptr("Sank @ANATIONALITY payroll courier near @CITYNAME.");
            local_20 = pcVar4;
            break;
        case 0xe:
            local_1c = as_ptr((&DAT_008dbd08)[as_int(param_1) * 3]);
            local_18 = as_ptr((&DAT_008dbd0c)[as_int(param_1) * 3]);
            local_14 = as_ptr((&DAT_008dbd10)[as_int(param_1) * 3]);
            local_20 = pcVar4;
            FUN_004f60b0("Sank @ANATIONALITY grain transport near @CITYNAME.");
            return;
        default:
            local_1c = as_ptr((&DAT_008dbd08)[as_int(param_1) * 3]);
            local_18 = as_ptr((&DAT_008dbd0c)[as_int(param_1) * 3]);
            local_14 = as_ptr((&DAT_008dbd10)[as_int(param_1) * 3]);
            local_20 = as_ptr(inEax & 0xff);
            FUN_004f60b0("Sank @ANATIONALITY @SHIPTYPE near @CITYNAME.", pcVar4);
            return;
        }
        break;

    case 0x23:  // '#'
        switch ((&DAT_00860b80)[inEax * 8]) {
        case 4:
            local_1c = as_ptr((&DAT_008dbd08)[inEax * 3]);
            local_18 = as_ptr((&DAT_008dbd0c)[inEax * 3]);
            local_14 = as_ptr((&DAT_008dbd10)[inEax * 3]);
            local_20 = as_ptr("Visited the haven of @CITYNAME.");
            FUN_004f60b0();
            return;
        case 5:
            local_1c = as_ptr((&DAT_008dbd08)[inEax * 3]);
            local_18 = as_ptr((&DAT_008dbd0c)[inEax * 3]);
            local_14 = as_ptr((&DAT_008dbd10)[inEax * 3]);
            local_20 = as_ptr("Visited the village of @CITYNAME.");
            FUN_004f60b0();
            return;
        case 6:
            local_1c = as_ptr((&DAT_008dbd08)[inEax * 3]);
            local_18 = as_ptr((&DAT_008dbd0c)[inEax * 3]);
            local_14 = as_ptr((&DAT_008dbd10)[inEax * 3]);
            local_20 = as_ptr("Visited the mission of @CITYNAME.");
            FUN_004f60b0();
            return;
        case 7:
            local_1c = as_ptr((&DAT_008dbd08)[inEax * 3]);
            local_18 = as_ptr((&DAT_008dbd0c)[inEax * 3]);
            local_14 = as_ptr((&DAT_008dbd10)[inEax * 3]);
            local_20 = as_ptr("Visited the settlement of @CITYNAME.");
            FUN_004f60b0();
            return;
        default:
            local_1c = as_ptr((&DAT_008dbd08)[inEax * 3]);
            local_18 = as_ptr((&DAT_008dbd0c)[inEax * 3]);
            local_14 = as_ptr((&DAT_008dbd10)[inEax * 3]);
            local_20 = as_ptr("Visited the town of @CITYNAME.");
            FUN_004f60b0();
            return;
        }
        // Every nested case returns.
        break;

    case 0x24:  // '$'
        local_14 = as_ptr(inEax & 0xf);
        if (1 < as_int(local_14)) {
            local_1c = as_ptr("Promoted to @NATIONALITY @RANK.");
            *param_3 = 1;
            local_20 = as_ptr(0x43c12c);
            local_18 = as_ptr(iVar2);
            FUN_004f60b0();
            return;
        }
        if (param_1 == nullptr) {
            local_18 = as_ptr("Received @NATIONALITY Letter of Marque.");
            local_1c = as_ptr(0x43c14b);
            local_14 = as_ptr(iVar2);
            FUN_004f60b0();
            return;
        }
        local_14 = as_ptr(-1);
        pcVar4 = as_ptr(-1);
        pcVar6 = as_ptr(-1);
        pcVar3 = as_ptr(0);
        do {
            if ((static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_1)) &
                 (1u << (static_cast<uint8_t>(reinterpret_cast<uintptr_t>(pcVar3)) & 0x1f))) != 0) {
                if (local_14 == as_ptr(-1)) {
                    local_14 = pcVar3;
                } else if (pcVar4 == as_ptr(-1)) {
                    pcVar4 = pcVar3;
                } else {
                    pcVar6 = pcVar3;
                }
            }
            pcVar3 = pcVar3 + 1;
        } while (as_int(pcVar3) < 4);
        if (local_14 != as_ptr(-1)) {
            if (pcVar4 == as_ptr(-1)) {
                local_18 = as_ptr("Governor encourages plundering @NATIONALITY ships.");
                local_1c = as_ptr(0x43c1db);
                FUN_004f60b0();
                return;
            }
            if (pcVar6 == as_ptr(-1)) {
                local_1c = as_ptr("Governor encourages plundering @NATIONALITY and @NATIONALITY ships.");
                local_20 = as_ptr(0x43c1c3);
                local_18 = local_14;
                local_14 = pcVar4;
                FUN_004f60b0();
                return;
            }
            local_20 = as_ptr("Governor encourages plundering @NATIONALITY, @NATIONALITY and @NATIONALITY ships.");
            local_1c = local_14;
            local_18 = pcVar4;
            local_14 = pcVar6;
            FUN_004f60b0();
            return;
        }
        goto switchD_0043b94e_caseD_b;

    case 0x25:  // '%'
        if (param_1 == nullptr) {
            local_18 = as_ptr("Acquired @APROP1.");
            local_1c = as_ptr(0x43c1f7);
            FUN_004f60b0();
            return;
        }
        if (param_1 == as_ptr(1)) {
            local_18 = as_ptr("Acquired @APROP2.");
            local_1c = as_ptr(0x43c218);
            FUN_004f60b0();
            return;
        }
        goto switchD_0043b94e_caseD_b;

    case 0x26:  // '&'
        local_18 = as_ptr("Recruited a skilled @SPEC.");
        local_1c = as_ptr(0x43c230);
        FUN_004f60b0();
        return;

    case 0x27:  // '\''
        switch (as_int(in_EAX)) {
        case 0x1e:
            local_1c = as_ptr((&DAT_008dbd08)[as_int(param_1) * 3]);
            local_18 = as_ptr((&DAT_008dbd0c)[as_int(param_1) * 3]);
            local_14 = as_ptr((&DAT_008dbd10)[as_int(param_1) * 3]);
            local_20 = as_ptr("Captured wanted criminal in @CITYNAME.");
            FUN_004f60b0();
            return;
        case 0x28:
            local_14 = as_ptr("Captured the evil Baron Raymondo.");
            local_18 = as_ptr(0x43c7e2);
            FUN_004f60b0();
            *param_3 = 1;
            return;
        case 0x29:
            local_14 = as_ptr("Captured the evil Colonel Mendoza.");
            local_18 = as_ptr(0x43c803);
            FUN_004f60b0();
            *param_3 = 1;
            return;
        case 0x2a:
            local_14 = as_ptr("Captured the Marquis de la Montalban.");
            local_18 = as_ptr(0x43c824);
            FUN_004f60b0();
            return;
        }
        goto switchD_0043b94e_caseD_b;

    case 0x28:  // '('
        local_14 = as_ptr((&DAT_0085bf74)[inEax * 0x25] & 3);
        local_20 = as_ptr((&DAT_008dbd08)[inEax * 3]);
        local_1c = as_ptr((&DAT_008dbd0c)[inEax * 3]);
        local_18 = as_ptr((&DAT_008dbd10)[inEax * 3]);
        FUN_004f60b0("Met Governor of @CITYNAME's @BEAUTY daughter.");
        return;

    case 0x29:  // ')'
        *param_3 = 1;
        local_1c = as_ptr((&DAT_008dbd08)[inEax * 3]);
        local_18 = as_ptr((&DAT_008dbd0c)[inEax * 3]);
        local_14 = as_ptr((&DAT_008dbd10)[inEax * 3]);
        local_20 = as_ptr("Dueled daughter's jealous suitor in @CITYNAME.");
        FUN_004f60b0();
        return;

    case 0x2a:  // '*'
        *param_3 = 1;
        local_14 = as_ptr((&DAT_0085bf74)[inEax * 0x25] & 3);
        local_20 = as_ptr((&DAT_008dbd08)[inEax * 3]);
        local_1c = as_ptr((&DAT_008dbd0c)[inEax * 3]);
        local_18 = as_ptr((&DAT_008dbd10)[inEax * 3]);
        FUN_004f60b0("Rescued Governor of @CITYNAME's @BEAUTY daughter.");
        return;

    case 0x2b:  // '+'
        *param_3 = 1;
        local_14 = as_ptr((&DAT_0085bf74)[inEax * 0x25] & 3);
        ppcVar5 = &local_20;
        pcVar6 = as_ptr("Married Governor of @CITYNAME's @BEAUTY daughter.");
        param_1 = in_EAX;
        break;

    case 0x2c:  // ','
        *param_3 = 1;
        local_14 = param_1;
        local_20 = as_ptr((&DAT_008cb100)[inEax * 3]);
        local_1c = as_ptr((&DAT_008cb104)[inEax * 3]);
        local_18 = as_ptr((&DAT_008cb108)[inEax * 3]);
        FUN_004f60b0("Found @TOP10's treasure worth @NUM gold!");
        return;

    case 0x2d:  // '-'
        local_18 = as_ptr("Rescued my @RELATIVE.");
        *param_3 = 1;
        local_1c = as_ptr(0x43c4c7);
        FUN_004f60b0();
        return;

    case 0x2e:  // '.'
        local_14 = as_ptr("Found great lost treasure!");
        *param_3 = 1;
        local_18 = as_ptr(0x43c4e8);
        FUN_004f60b0();
        return;

    case 0x2f:  // '/'
        if (param_1 == as_ptr(-1)) {
            local_1c = as_ptr((&DAT_008dbd08)[inEax * 3]);
            local_18 = as_ptr((&DAT_008dbd0c)[inEax * 3]);
            local_14 = as_ptr((&DAT_008dbd10)[inEax * 3]);
            local_20 = as_ptr("Sacked the town of @CITYNAME.");
            FUN_004f60b0();
            return;
        }
        local_1c = as_ptr((&DAT_008dbd08)[inEax * 3]);
        local_18 = as_ptr((&DAT_008dbd0c)[inEax * 3]);
        local_14 = as_ptr((&DAT_008dbd10)[inEax * 3]);
        local_20 = param_1;
        FUN_004f60b0("Installed @ANATIONALITY Governor in @CITYNAME.");
        return;

    case 0x30:  // '0'
        *param_3 = 1;
        local_1c = as_ptr((&DAT_008cb100)[inEax * 3]);
        local_18 = as_ptr((&DAT_008cb104)[inEax * 3]);
        local_14 = as_ptr((&DAT_008cb108)[inEax * 3]);
        local_20 = as_ptr("Defeated notorious pirate @TOP10.");
        FUN_004f60b0();
        return;

    case 0x31:  // '1'
        if (in_EAX == as_ptr(-1)) {
            local_14 = as_ptr("Marooned on a deserted island.");
            local_18 = as_ptr(0x43c5cf);
            FUN_004f60b0();
            return;
        }
        local_1c = as_ptr((&DAT_008dbd08)[inEax * 3]);
        local_18 = as_ptr((&DAT_008dbd0c)[inEax * 3]);
        local_14 = as_ptr((&DAT_008dbd10)[inEax * 3]);
        local_20 = as_ptr("Imprisoned in the city of @CITYNAME.");
        FUN_004f60b0();
        return;

    case 0x32:  // '2'
        local_14 = as_ptr("Took command of a Pirate ship.");
        local_18 = as_ptr(0x43c617);
        FUN_004f60b0();
        return;

    case 0x33:  // '3'
        local_14 = as_ptr("Vanquished the Marquis Montalban!");
        *param_3 = 2;
        local_18 = as_ptr(0x43c5b3);
        FUN_004f60b0();
        return;

    case 0x40:  // '@'
        local_1c = as_ptr((&DAT_008dbd08)[inEax * 3]);
        local_18 = as_ptr((&DAT_008dbd0c)[inEax * 3]);
        local_14 = as_ptr((&DAT_008dbd10)[inEax * 3]);
        local_20 = as_ptr("Treasure fleet headed for @CITYNAME.");
        FUN_004f60b0();
        return;

    case 0x41:  // 'A'
        local_1c = as_ptr((&DAT_008dbd08)[inEax * 3]);
        local_18 = as_ptr((&DAT_008dbd0c)[inEax * 3]);
        local_14 = as_ptr((&DAT_008dbd10)[inEax * 3]);
        local_20 = as_ptr("Silver train in @CITYNAME.");
        FUN_004f60b0();
        return;

    case 0x42:  // 'B'
        local_1c = as_ptr((&DAT_008dbd08)[as_int(param_1) * 3]);
        local_18 = as_ptr((&DAT_008dbd0c)[as_int(param_1) * 3]);
        local_14 = as_ptr((&DAT_008dbd10)[as_int(param_1) * 3]);
        FUN_004f60b0("@NATIONALITY smuggler headed for @CITYNAME.");
        return;

    case 0x43:  // 'C'
        local_14 = as_ptr(static_cast<int32_t>(0xc0008000u));
        local_20 = as_ptr((&DAT_00860b6c)[
            static_cast<int32_t>(*reinterpret_cast<int16_t *>(&DAT_00862002 + inEax * 0x1c)) * 8]);
        local_18 = as_ptr(0x270f);
        local_1c = as_ptr(-1);
        iVar2 = FUN_0045fcb0((&DAT_00860b68)[
            static_cast<int32_t>(*reinterpret_cast<int16_t *>(&DAT_00862002 + inEax * 0x1c)) * 8]);
        local_1c = as_ptr((&DAT_008dbd08)[iVar2 * 3]);
        local_18 = as_ptr((&DAT_008dbd0c)[iVar2 * 3]);
        local_14 = as_ptr((&DAT_008dbd10)[iVar2 * 3]);
        iVar2 = static_cast<int32_t>(*reinterpret_cast<int16_t *>(&DAT_00862002 + inEax * 0x1c));
        local_20 = as_ptr((&DAT_008dbd10)[iVar2 * 3]);
        FUN_004f60b0("@TOP10 sails out of @CITYNAME near @CITYNAME.",
                      (&DAT_008cb100)[inEax * 3], (&DAT_008cb104)[inEax * 3],
                      (&DAT_008cb108)[inEax * 3], (&DAT_008dbd08)[iVar2 * 3],
                      (&DAT_008dbd0c)[iVar2 * 3]);
        return;

    case 0x44:  // 'D'
        if (0x27 < as_int(param_1)) {
            local_1c = as_ptr((&DAT_008dbd08)[inEax * 3]);
            local_18 = as_ptr((&DAT_008dbd0c)[inEax * 3]);
            local_14 = as_ptr((&DAT_008dbd10)[inEax * 3]);
            iVar2 = as_int(param_1) * 3 + -0x78;
            local_20 = as_ptr((&DAT_008cb180)[iVar2]);
            FUN_004f60b0("@EVILNAME seen in @CITYNAME.", (&DAT_008cb178)[iVar2],
                          (&DAT_008cb17c)[iVar2]);
            return;
        }
        if (as_int(param_1) < 0x1e) {
            local_1c = as_ptr((&DAT_008dbd08)[inEax * 3]);
            local_18 = as_ptr((&DAT_008dbd0c)[inEax * 3]);
            local_14 = as_ptr((&DAT_008dbd10)[inEax * 3]);
            local_20 = as_ptr((&DAT_008cb108)[as_int(param_1) * 3]);
            FUN_004f60b0("@TOP10 seen in @CITYNAME.",
                          (&DAT_008cb100)[as_int(param_1) * 3],
                          (&DAT_008cb104)[as_int(param_1) * 3]);
            return;
        }
        if (param_2 == 0) {
            local_1c = as_ptr((&DAT_008dbd08)[inEax * 3]);
            local_18 = as_ptr((&DAT_008dbd0c)[inEax * 3]);
            local_14 = as_ptr((&DAT_008dbd10)[inEax * 3]);
            iVar2 = as_int(param_1) * 3 + -0x5a;
            local_20 = as_ptr((&DAT_008cb1a4)[iVar2]);
            FUN_004f60b0("Mr. @NPCNAME seen in @CITYNAME.", (&DAT_008cb19c)[iVar2],
                          (&DAT_008cb1a0)[iVar2]);
            return;
        }
        local_1c = as_ptr((&DAT_008dbd08)[inEax * 3]);
        local_18 = as_ptr((&DAT_008dbd0c)[inEax * 3]);
        local_14 = as_ptr((&DAT_008dbd10)[inEax * 3]);
        iVar2 = as_int(param_1) * 3 + -0x5a;
        local_20 = as_ptr((&DAT_008cb1a4)[iVar2]);
        FUN_004f60b0("Mr. @CHAR. @NPCNAME seen in @CITYNAME.", param_2,
                      (&DAT_008cb19c)[iVar2], (&DAT_008cb1a0)[iVar2]);
        return;

    case 0x45:  // 'E'
        if (in_EAX != as_ptr(2)) {
            if (in_EAX == as_ptr(0x1e)) {
                local_1c = as_ptr((&DAT_008dbd08)[as_int(param_1) * 3]);
                local_18 = as_ptr((&DAT_008dbd0c)[as_int(param_1) * 3]);
                local_14 = as_ptr((&DAT_008dbd10)[as_int(param_1) * 3]);
                local_20 = as_ptr("Wanted criminal hiding in @CITYNAME.");
                FUN_004f60b0();
                return;
            }
            return;
        }
        local_14 = as_ptr(static_cast<int32_t>((param_2 >> 8) & 0xff));
        ppcVar5 = &local_20;
        pcVar6 = as_ptr("Gov. of @CITYNAME annoyed by @NATIONALITY privateer.");
        break;

    default:
        goto switchD_0043b94e_caseD_b;
    }

    *ppcVar5 = as_ptr((&DAT_008dbd08)[as_int(param_1) * 3]);
    uVar1 = (&DAT_008dbd10)[as_int(param_1) * 3];
    ppcVar5[1] = as_ptr((&DAT_008dbd0c)[as_int(param_1) * 3]);
    ppcVar5[2] = as_ptr(uVar1);
    FUN_004f60b0(pcVar6);

switchD_0043b94e_caseD_b:
    return;
}


// ===== 0x43cde0 (delegated part, unified declarations) =====
extern void        FUN_0043ca20(int, uint32_t, uint32_t, uint32_t, uint32_t);
extern void        FUN_004f2600(const char *, ...);
extern void        FUN_004f3350();
extern void        FUN_004f1840();
extern void       *FUN_00503270(const char *, const char *, const char *, const char *,
                                const char *, float, float, float, float, float, float,
                                int, int);
extern void        FUN_00503fb0(void *);
extern void        FUN_00533d10(int, int);
extern void        FUN_0050c550(int);
extern void        FUN_0050c5d0(int);
extern void        FUN_004bba60(void *, uint32_t, uint32_t, uint32_t, uint32_t);
extern uint32_t    FUN_0042c6f0();
extern void        FUN_004889c0(uint32_t *, int, int, int, int, uint32_t, int);
extern void        FUN_00504070(void *);
extern int32_t     DAT_008caccc;
extern uint32_t    DAT_008ea008;
extern int32_t     DAT_0072553c;
extern int32_t     DAT_0085a0fc;
extern uint8_t     DAT_008ca988;
extern int16_t     DAT_0086c010[];
extern int16_t     DAT_0086be80[];
extern int16_t     DAT_0086c1a0[];
extern int16_t     DAT_0086bcf0[];
extern int16_t     DAT_0086bb60[];
extern uint32_t    DAT_008d8018;
extern uint32_t    DAT_008d7ad8;
extern uint32_t    DAT_0085a168;
extern uint32_t    DAT_008c8278;
extern uint32_t    PTR_DAT_0070002c;
extern uint32_t    PTR_DAT_006fff4c;

// 0x0043cde0 — observed shape
void FUN_0043cde0(int param_1, uint32_t param_2, uint32_t param_3,
                  uint32_t param_4, uint32_t param_5)
{
    void       *_Dst;
    size_t      _Size;
    char        cVar1;
    int16_t     sVar2;
    int16_t     sVar17;
    uint32_t   *puVar5;
    char       *pcVar6;
    uint32_t    uVar7;
    int32_t     iVar8;
    uint32_t    uVar9;
    uint32_t   *puVar10;
    int32_t     iVar11;
    char       *pcVar12;
    int32_t     iVar13;
    uint32_t    uVar14;
    char       *pcVar15;
    int32_t     iVar16;
    int16_t    *psVar18;
    uint8_t    *puVar20;
    bool        bVar21;
    uint32_t    uVar22;
    uint32_t    uVar23;
    int32_t     iStack_72c8;
    char       *local_72c4;
    uint8_t    *pbStack_72c0;
    int32_t     puStack_72bc;
    char       *pcStack_72b8;
    char       *pcStack_72b4;
    char       *local_72b0;
    uint8_t    *pbStack_72ac;
    char        local_72a5;
    int32_t    *local_72a4;
    uint32_t   *local_72a0;
    char       *pcStack_729c;
    uint32_t   *local_7298;
    uint32_t   *local_7294_0;
    int32_t     local_7294_1;
    int32_t     local_728c;
    char       *pcStack_7288;
    int32_t     local_7284;
    int32_t     local_7280;
    uint32_t   *local_727c[16];
    char        acStack_7238[20];
    int16_t     asStack_7224[4608];

    // Scratch row table: 1000 entries of 0x14 bytes each.
    uint8_t local_4e24_[1000 * 0x14];
    uint8_t *const local_4e24 = local_4e24_;

    if (param_1 == 0) {
        FUN_0043ca20(0, param_2, param_3, param_4, param_5);
        return;
    }

    local_72a5 = '\0';

    // Initialize 1000 scratch records: text pointing to static empty string,
    // delta 0, index -1, height 0, y2 0.
    for (int32_t n = 0; n < 1000; ++n) {
        uint8_t *rec = local_4e24 + n * 0x14;
        *reinterpret_cast<uint32_t *>(rec + 0x00) = addr32(&DAT_008cacd0);
        *reinterpret_cast<uint32_t *>(rec + 0x04) = 0u;
        *reinterpret_cast<int32_t  *>(rec + 0x08) = -1;
        *reinterpret_cast<uint32_t *>(rec + 0x0c) = 0u;
        *reinterpret_cast<uint32_t *>(rec + 0x10) = 0u;
    }

    local_7294_1 = -1;
    local_7284 = -1;
    local_728c = -1;
    for (int32_t n = 0; n < 16; ++n) local_727c[n] = nullptr;
    DAT_0072553c = 0;
    local_7280 = DAT_0085a0fc;
    local_7294_0 = nullptr;
    local_7298 = nullptr;
    local_72a0 = nullptr;
    local_72c4 = nullptr;

    // Load flag icons: 4 nationalities x 4 columns.
    do {
        int32_t *slot = reinterpret_cast<int32_t *>(local_727c) +
                        (reinterpret_cast<intptr_t>(local_72c4) / 4);
        iVar11 = 0;
        do {
            local_72b0 = reinterpret_cast<char *>(&DAT_008cacd0);
            const char *side = ((iVar11 == 0) || (iVar11 == 1)) ? "left" : "right";
            const void *kind;
            if ((iVar11 == 0) || (iVar11 == 2)) kind = "treaty";
            else kind = &PTR_DAT_0070002c;

            FUN_004f2600("flag_%s_%s_%s.dds", kind,
                         *reinterpret_cast<uint32_t *>(0x725694 + reinterpret_cast<intptr_t>(local_72c4)),
                         side);

            puVar5 = reinterpret_cast<uint32_t *>(FUN_00533c78(0xc0));
            pcVar12 = local_72b0;
            uVar7 = DAT_008ea008;
            if (puVar5 != nullptr) {
                puVar5[1] = 0;
                *puVar5 = addr32(&PTR_FUN_006fd14c);
                puVar5[7] = 0;
                DAT_00727444 = DAT_00727444 + 1;
                puVar5[0x19] = 0;
                puVar5[0x2f] = 0;
                FUN_004bdca0(uVar7, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
            }

            puVar10 = reinterpret_cast<uint32_t *>(*slot);
            if (puVar10 != puVar5) {
                if (puVar10 != nullptr) {
                    puVar10[1] = puVar10[1] - 1;
                    if (puVar10[1] == 0) {
                        reinterpret_cast<void (*)(int)>(*reinterpret_cast<void **>(puVar10))(1);
                    }
                }
                *slot = static_cast<int32_t>(reinterpret_cast<intptr_t>(puVar5));
                if (puVar5 != nullptr) puVar5[1] = puVar5[1] + 1;
            }

            free_temp_string(pcVar12);
            iVar11 = iVar11 + 1;
            slot = slot + 4;
        } while (iVar11 < 4);
        local_72c4 = local_72c4 + 4;
    } while (static_cast<int32_t>(reinterpret_cast<intptr_t>(local_72c4)) < 0xd);

    // Two shared treaty status icons (0xc0-byte widget objects).
    puVar5 = reinterpret_cast<uint32_t *>(FUN_00533c78(0xc0));
    uVar7 = DAT_008ea008;
    if (puVar5 != nullptr) {
        puVar5[1] = 0;
        *puVar5 = addr32(&PTR_FUN_006fd14c);
        puVar5[7] = 0;
        puVar5[0x19] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar5[0x2f] = 0;
        FUN_004bdca0(uVar7, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    assign_ref(local_7298, puVar5);

    puVar5 = reinterpret_cast<uint32_t *>(FUN_00533c78(0xc0));
    uVar7 = DAT_008ea008;
    if (puVar5 != nullptr) {
        puVar5[1] = 0;
        *puVar5 = addr32(&PTR_FUN_006fd14c);
        puVar5[7] = 0;
        puVar5[0x19] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar5[0x2f] = 0;
        FUN_004bdca0(uVar7, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    assign_ref(local_7294_0, puVar5);

    // Clear icon placement scratch buffer (4608 shorts).
    psVar18 = asStack_7224;
    for (iVar11 = 0x900; iVar11 != 0; iVar11 = iVar11 - 1) {
        psVar18[0] = 0;
        psVar18[1] = 0;
        psVar18 = psVar18 + 2;
    }

    iVar11 = 0;
    DAT_0085a0fc = 0;
    local_72a4 = nullptr;
    pcStack_72b8 = nullptr;

    // Populate relation rows from table at DAT_00862d10.
    if (0 < DAT_0085a100) {
        pcStack_72b4 = reinterpret_cast<char *>(local_4e24);
        pbStack_72ac = reinterpret_cast<uint8_t *>(&DAT_00862d10);
        do {
            pcVar12 = pcStack_72b4;
            if ((static_cast<int32_t>(static_cast<int8_t>(*pbStack_72ac)) & static_cast<int32_t>(param_4)) != 0) {
                *pbStack_72ac = static_cast<uint8_t>(*pbStack_72ac & 0x7f);
            }
            if ((-1 < static_cast<int8_t>(*pbStack_72ac)) &&
                ((static_cast<int32_t>(static_cast<int8_t>(*pbStack_72ac)) & static_cast<int32_t>(param_3)) != 0)) {

                FUN_0043b8e0(*reinterpret_cast<uint32_t *>(pbStack_72ac + 8),
                             *reinterpret_cast<uint32_t *>(pbStack_72ac + 0xc),
                             &iStack_72c8);
                iVar11 = FUN_004879f0(0x4c, 8);

                pcVar15 = reinterpret_cast<char *>(&DAT_00869b48);
                do {
                    pcVar6 = pcVar15;
                    pcVar15 = pcVar6 + 1;
                } while (*pcVar6 != '\0');
                intptr_t textLen = static_cast<intptr_t>(reinterpret_cast<intptr_t>(pcVar6)) - 0x869b48;

                if ((-1 < textLen) &&
                    (puVar20 = *reinterpret_cast<uint8_t **>(pcVar12),
                     puVar20 != reinterpret_cast<uint8_t *>(&DAT_00869b48))) {
                    if (textLen == 0) {
                        if (*reinterpret_cast<int32_t *>(puVar20 - 4) != 0) {
                            *puVar20 = 0;
                            *reinterpret_cast<uint32_t *>(puVar20 - 4) = 0;
                        }
                    } else {
                        FUN_004f3350();
                        _Dst = *reinterpret_cast<void **>(pcVar12);
                        memmove(_Dst, &DAT_00869b48, static_cast<size_t>(textLen));
                        reinterpret_cast<uint8_t *>(_Dst)[*reinterpret_cast<int32_t *>(
                            reinterpret_cast<uint8_t *>(_Dst) - 4)] = 0;
                    }
                }

                DAT_0085a11c = 0x43;
                if (iVar11 - 1 < 1) {
                    puStack_72bc = static_cast<int32_t>(
                        (DAT_008cac18 * 0x43 + ((DAT_008cac18 * 0x43 >> 0x1f) & 0x3ff)) >> 10);
                    DAT_008c9de0 = DAT_008c9dd8;
                    FUN_00509500(DAT_008c9dd8, &DAT_00869b48, 0);
                    uVar7 = FUN_005f0ddc();
                    *reinterpret_cast<uint32_t *>(pcVar12 + 0x10) = uVar7;
                } else {
                    pcVar12 = reinterpret_cast<char *>(&DAT_008cacd0);
                    local_72c4 = reinterpret_cast<char *>(&DAT_008cacd0);
                    pcVar15 = reinterpret_cast<char *>(&DAT_00869b48);
                    do {
                        pcVar6 = pcVar15;
                        pcVar15 = pcVar6 + 1;
                    } while (*pcVar6 != '\0');
                    textLen = static_cast<intptr_t>(reinterpret_cast<intptr_t>(pcVar6)) - 0x869b48;
                    if (-1 < textLen) {
                        if (textLen == 0) {
                            if (DAT_008caccc != 0) {
                                DAT_008cacd0 = 0;
                                DAT_008caccc = 0;
                            }
                        } else {
                            FUN_004f3350();
                            pcVar12 = local_72c4;
                            memmove(local_72c4, &DAT_00869b48, static_cast<size_t>(textLen));
                            pcVar12[*reinterpret_cast<int32_t *>(pcVar12 - 4)] = '\0';
                        }
                    }
                    iVar11 = *reinterpret_cast<int32_t *>(pcVar12 - 4) + -1;
                    if ((iVar11 < *reinterpret_cast<int32_t *>(pcVar12 - 4)) && (-1 < iVar11)) {
                        cVar1 = pcVar12[iVar11];
                        pcVar12[iVar11] = '\0';
                        strrchr(pcVar12, 10);
                        pcVar12[iVar11] = cVar1;
                    }
                    FUN_004f1840();
                    pcVar15 = local_72b0;
                    _Size = static_cast<size_t>(*reinterpret_cast<int32_t *>(local_72b0 - 4));
                    if ((-1 < static_cast<int32_t>(_Size)) && (local_72b0 != pcVar12)) {
                        if (_Size == 0) {
                            if (*reinterpret_cast<int32_t *>(pcVar12 - 4) != 0) {
                                *pcVar12 = '\0';
                                pcVar12[-4] = '\0';
                                pcVar12[-3] = '\0';
                                pcVar12[-2] = '\0';
                                pcVar12[-1] = '\0';
                            }
                        } else {
                            FUN_004f3350();
                            pcVar12 = local_72c4;
                            memmove(local_72c4, pcVar15, _Size);
                            pcVar12[*reinterpret_cast<int32_t *>(pcVar12 - 4)] = '\0';
                        }
                    }
                    free_temp_string(pcVar15);

                    puStack_72bc = static_cast<int32_t>(
                        (DAT_0085a11c * DAT_008cac18 +
                         ((DAT_0085a11c * DAT_008cac18 >> 0x1f) & 0x3ff)) >> 10);
                    local_72b0 = reinterpret_cast<char *>(&DAT_008cacd0);
                    DAT_008c9de0 = DAT_008c9dd8;
                    FUN_00509500(DAT_008c9dd8, pcVar12, 0);
                    uVar7 = FUN_005f0ddc();
                    *reinterpret_cast<uint32_t *>(pcStack_72b4 + 0x10) = uVar7;
                    free_temp_string(pcVar12);
                    pcVar12 = pcStack_72b4;
                }

                puStack_72bc = static_cast<int32_t>(
                    (DAT_0085a11c * DAT_008cac18 +
                     ((DAT_0085a11c * DAT_008cac18 >> 0x1f) & 0x3ff)) >> 10);
                DAT_008c9de0 = DAT_008c9dd8;
                FUN_005096b0();
                iVar11 = static_cast<int32_t>(FUN_005f0ddc());
                *reinterpret_cast<int32_t *>(pcVar12 + 4) = iStack_72c8;
                local_72a4 = reinterpret_cast<int32_t *>(
                    reinterpret_cast<intptr_t>(local_72a4) + static_cast<intptr_t>(iVar11));
                *reinterpret_cast<char **>(pcVar12 + 8) = pcStack_72b8;
                *reinterpret_cast<int32_t *>(pcVar12 + 0xc) = iVar11;
                iVar11 = DAT_0085a0fc;
            }
            pcStack_72b8 = pcStack_72b8 + 1;
            pbStack_72ac = pbStack_72ac + 0x1c;
            pcStack_72b4 = pcVar12 + 0x14;
        } while (static_cast<int32_t>(reinterpret_cast<intptr_t>(pcStack_72b8)) < DAT_0085a100);
    }

    // Scrollbar height threshold check.
    iVar8 = (DAT_0085a268 * 2) / 3;
    iVar16 = static_cast<int32_t>(reinterpret_cast<intptr_t>(local_72a4)) + 0x30;
    local_72a4 = reinterpret_cast<int32_t *>(static_cast<intptr_t>(iVar16));
    if (iVar16 <= iVar8 + -0x14) {
        DAT_0072553c = -0x20;
        goto LAB_0043d655;
    }

    // Allocate and configure LogScroller widget.
    DAT_0072553c = iVar16 - iVar8;
    iVar11 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_00533c78(0x2a0)));
    if (iVar11 != 0) {
        puStack_72bc = static_cast<int32_t>(
            (DAT_0085a26c * 0xf + ((DAT_0085a26c * 0xf >> 0x1f) & 0xf)) >> 4);
        puVar5 = reinterpret_cast<uint32_t *>(FUN_00503270(
            "LogScroller", "ScrollBarTile.tga", "ScrollBarThumb.nif",
            "ScrollBarUP.nif", "ScrollBarDOWN.nif",
            static_cast<float>(puStack_72bc) * 1.6f,
            static_cast<float>(DAT_0085a268 / 2) * 1.6f,
            -10.0f,
            static_cast<float>((DAT_0085a268 * 2) / 3) * 1.6f,
            16.0f,
            -1.0f,
            0, 1));
        if (puVar5 != nullptr) {
            puVar5[1] = puVar5[1] + 1;
            local_72a0 = puVar5;
        }
    }

    puVar5 = local_72a0;
    iVar11 = *reinterpret_cast<int32_t *>(at32(DAT_008cabe8) + 0x10);
    FUN_00503fb0(local_72a0);
    {
        uint32_t objAddr = *reinterpret_cast<uint32_t *>(at32(static_cast<uint32_t>(iVar11)) + 4);
        uint32_t vtblAddr = *reinterpret_cast<uint32_t *>(at32(objAddr));
        reinterpret_cast<void (*)(uint32_t *, int)>(
            *reinterpret_cast<void **>(at32(vtblAddr) + 0x70))(puVar5, 1);
    }
    FUN_00534130();
    FUN_00533d10(0, 1);
    iVar16 = iVar16 - (DAT_0085a268 * 2) / 3;

    {
        uint32_t scrollCtlAddr = puVar5[0xa6];
        uint8_t *scrollCtl = at32(scrollCtlAddr);
        if (*reinterpret_cast<char *>(puVar5 + 0xa7) == '\0') {
            *reinterpret_cast<int32_t  *>(scrollCtl + 0x290) = iVar16;
            *reinterpret_cast<uint32_t *>(scrollCtl + 0x294) = 0;
            if (iVar16 == 0) *reinterpret_cast<uint32_t *>(scrollCtl + 0x290) = 1;
LAB_0043d5f6:
            *reinterpret_cast<uint32_t *>(scrollCtl + 0x294) = 1;
        } else {
            *reinterpret_cast<int32_t  *>(scrollCtl + 0x294) = iVar16;
            *reinterpret_cast<uint32_t *>(scrollCtl + 0x290) = 1;
            if (iVar16 == 0) goto LAB_0043d5f6;
        }

        if (*reinterpret_cast<char *>(puVar5 + 0xa7) == '\0') {
            FUN_0050c550(iVar16);
            iVar11 = DAT_0085a0fc;
        } else {
            FUN_0050c5d0(iVar16);
            iVar11 = DAT_0085a0fc;
        }
    }

LAB_0043d655:
    do {
        puVar5 = local_72a0;
        if (DAT_008cac27 != '\0') {
            local_72a5 = '\x01';
        }
        DAT_0086c330 = 0;
        if (local_72a0 != nullptr) {
            if (0 < iVar11) {
                DAT_0072553c = DAT_0072553c + iVar11 * 0x10;
                cVar1 = '\x01';
            } else {
                cVar1 = static_cast<char>(DAT_008ca988);
                if (iVar11 < 0) {
                    DAT_0072553c = DAT_0072553c + iVar11 * 0x10;
                    cVar1 = '\x01';
                }
            }
            iVar11 = DAT_0072553c;
            DAT_0085a0fc = 0;
            if (cVar1 == '\0') {
                iVar8 = static_cast<int32_t>(local_72a0[0xa6]);
                iVar16 = static_cast<int32_t>(FUN_005f0ddc());
                uVar14 = static_cast<uint32_t>((iVar16 - iVar11) >> 0x1f);
                uint32_t absDiff = static_cast<uint32_t>((iVar16 - iVar11) ^ uVar14) - uVar14;
                if ((static_cast<int32_t>(absDiff) < 0x20) &&
                    (*reinterpret_cast<char *>(at32(static_cast<uint32_t>(iVar8)) + 0xf2) == '\0')) {
                    iVar8 = static_cast<int32_t>(FUN_005f0ddc());
                    if (iVar8 - iVar11 < 1) {
                        DAT_0072553c = iVar11 + ((-1 < (iVar8 - iVar11)) - 1) * 0x20;
                    } else {
                        DAT_0072553c = iVar11 + 0x20;
                    }
                } else {
                    DAT_0072553c = static_cast<int32_t>(FUN_005f0ddc());
                }
            }
            if (DAT_0072553c < 0) {
                DAT_0072553c = 0;
            } else {
                iVar11 = static_cast<int32_t>(reinterpret_cast<intptr_t>(local_72a4)) -
                         (DAT_0085a268 * 2) / 3;
                if (iVar11 < DAT_0072553c) {
                    DAT_0072553c = iVar11;
                }
            }
            DAT_008ca988 = '\0';
            if (*reinterpret_cast<char *>(puVar5 + 0xa7) == '\0') {
                FUN_0050c550(DAT_0072553c);
            } else {
                FUN_0050c5d0(DAT_0072553c);
            }
        }
        FUN_004b24a0(DAT_008cabe8, 0);
        iVar11 = 0;
        iVar8 = 0;
        pcStack_72b8 = nullptr;
        iStack_72c8 = 0;

        // Render visible relation rows.
        if (0 < DAT_0085a100) {
            local_72b0 = nullptr;
            do {
                pcVar12 = local_72b0;
                if ((DAT_0072553c - 0x1c <= iVar8) &&
                    (iVar8 <= (DAT_0085a268 * 2) / 3 + DAT_0072553c)) {
                    FUN_004b06c0(*reinterpret_cast<void **>(local_4e24 + reinterpret_cast<intptr_t>(local_72b0)),
                                 ((DAT_0085a26c + (DAT_0085a26c >> 0x1f & 3)) >> 2) + -0x18,
                                 (((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 7)) >> 3) - DAT_0072553c) + 0x1c + iVar8,
                                 0x43, 0xffffffff, 1, 0xffffffff, 0);

                    bVar21 = *reinterpret_cast<int32_t *>(local_4e24 + reinterpret_cast<intptr_t>(pcVar12) + 4) != 0;
                    pcStack_72b4 = nullptr;
                    if (bVar21) {
                        uVar23 = 0;
                        pbStack_72c0 = reinterpret_cast<uint8_t *>(
                            (((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 7)) >> 3) - DAT_0072553c) +
                            *reinterpret_cast<int32_t *>(local_4e24 + reinterpret_cast<intptr_t>(pcVar12) + 0xc) + iVar8);
                        uVar22 = 0x42700000;
                        uVar7 = FUN_005f0ddc(0x42700000, 0);
                        pbStack_72c0 = reinterpret_cast<uint8_t *>(
                            ((DAT_0085a26c + (DAT_0085a26c >> 0x1f & 3)) >> 2) + -0x1c +
                            *reinterpret_cast<int32_t *>(local_4e24 + reinterpret_cast<intptr_t>(pcVar12) + 0x10));
                        uVar9 = FUN_005f0ddc(uVar7);
                        FUN_004bba60(&DAT_008d8018, uVar9, uVar7, uVar22, uVar23);

                        iVar16 = DAT_0085a26c + (DAT_0085a26c >> 0x1f & 3);
                        pbStack_72c0 = reinterpret_cast<uint8_t *>(
                            static_cast<intptr_t>(static_cast<int16_t>(
                                static_cast<int16_t>(iVar16 >> 2) +
                                *reinterpret_cast<int16_t *>(local_4e24 + reinterpret_cast<intptr_t>(pcVar12) + 0x10))) + -0x1c);
                        sVar2 = static_cast<int16_t>(
                            static_cast<int16_t>((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 7)) >> 3) -
                            static_cast<int16_t>(DAT_0072553c) + static_cast<int16_t>(iVar8) +
                            *reinterpret_cast<int16_t *>(local_4e24 + reinterpret_cast<intptr_t>(pcVar12) + 0xc));
                        asStack_7224[iVar11 * 3 + 1] = sVar2;
                        iVar16 = DAT_0086c330;
                        sVar17 = static_cast<int16_t>(reinterpret_cast<intptr_t>(pbStack_72c0));
                        DAT_0086c010[iVar16] = static_cast<int16_t>(sVar17 + 0xc);
                        DAT_0086be80[iVar16] = static_cast<int16_t>(sVar2 + 0xe);
                        DAT_0086c1a0[iVar16] = static_cast<int16_t>(iVar11 + 6);
                        DAT_0086c330 = DAT_0086c330 + 1;
                        DAT_0086bcf0[iVar16] = static_cast<int16_t>(sVar17 + 0x1a);
                        DAT_0086bb60[iVar16] = static_cast<int16_t>(sVar2 + 0x1c);
                        asStack_7224[iVar11 * 3] = static_cast<int16_t>(sVar17 + 0x10);
                        pcStack_72b8 = reinterpret_cast<char *>(reinterpret_cast<intptr_t>(pcStack_72b8) + 1);
                        asStack_7224[iVar11 * 3 + 2] = 0;
                        iVar11 = static_cast<int32_t>(reinterpret_cast<intptr_t>(pcStack_72b8));
                    }

                    pcStack_72b4 = reinterpret_cast<char *>(static_cast<uintptr_t>(bVar21 ? 1u : 0u));
                    pcStack_7288 = reinterpret_cast<char *>(
                        reinterpret_cast<intptr_t>(&DAT_00862d10) +
                        *reinterpret_cast<int32_t *>(local_4e24 + reinterpret_cast<intptr_t>(pcVar12) + 8) * 0x1c + 1);
                    intptr_t iconDx = static_cast<intptr_t>(bVar21 ? 1u : 0u) << 4;
                    local_72c4 = nullptr;
                    psVar18 = asStack_7224 + iVar11 * 3;
                    do {
                        if ((static_cast<int32_t>(*pcStack_7288) &
                             (1 << (static_cast<int32_t>(reinterpret_cast<intptr_t>(local_72c4)) & 0x1f))) != 0) {
                            iVar16 = static_cast<int32_t>((DAT_0085a26c + (DAT_0085a26c >> 0x1f & 3)) >> 2);
                            *psVar18 = static_cast<int16_t>(
                                (static_cast<int32_t>(reinterpret_cast<intptr_t>(pcStack_72b4)) << 4) +
                                *reinterpret_cast<int16_t *>(local_4e24 + reinterpret_cast<intptr_t>(pcVar12) + 0x10) +
                                -0xf + static_cast<int16_t>(iVar16));
                            pbStack_72c0 = reinterpret_cast<uint8_t *>(
                                local_4e24 + reinterpret_cast<intptr_t>(pcVar12) + 0xc);
                            iVar11 = static_cast<int32_t>((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 7)) >> 3);
                            psVar18[1] = static_cast<int16_t>(
                                (*reinterpret_cast<int16_t *>(local_4e24 + reinterpret_cast<intptr_t>(pcVar12) + 0xc) -
                                 static_cast<int16_t>(DAT_0072553c)) + static_cast<int16_t>(iVar8) + 0x11 +
                                static_cast<int16_t>(iVar11));

                            if (*pcStack_7288 < '\0') {
                                pcStack_729c = reinterpret_cast<char *>(
                                    reinterpret_cast<uint32_t *>(&DAT_008d7ad8) +
                                    reinterpret_cast<intptr_t>(local_72c4) * 0x30);
                                if (pcStack_729c != nullptr) {
                                    pbStack_72c0 = reinterpret_cast<uint8_t *>(
                                        (*reinterpret_cast<int32_t *>(pbStack_72c0) - DAT_0072553c) + iVar8 + 0xc + iVar11);
                                    uVar23 = 0;
                                    uVar22 = 0x42480000;
                                    uVar7 = FUN_005f0ddc(0x42480000, 0);
                                    pcVar15 = pcStack_729c;
                                    pbStack_72c0 = reinterpret_cast<uint8_t *>(
                                        iconDx + iVar16 +
                                        *reinterpret_cast<int32_t *>(local_4e24 + reinterpret_cast<intptr_t>(pcVar12) + 0x10) + -0x10);
                                    uVar9 = FUN_005f0ddc(uVar7);
                                    FUN_004bba60(pcVar15, uVar9, uVar7, uVar22, uVar23);
                                }
                                iVar11 = DAT_0086c330;
                                sVar2 = *psVar18;
                                sVar17 = psVar18[1];
                                psVar18[2] = static_cast<int16_t>(reinterpret_cast<intptr_t>(local_72c4) + 6);
                                DAT_0086c1a0[iVar11] = static_cast<int16_t>(reinterpret_cast<intptr_t>(pcStack_72b8) + 6);
                                DAT_0086c010[iVar11] = sVar2;
                                DAT_0086be80[iVar11] = sVar17;
                                DAT_0086bcf0[iVar11] = static_cast<int16_t>(sVar2 + 0xe);
                                DAT_0086c330 = DAT_0086c330 + 1;
                                DAT_0086bb60[iVar11] = static_cast<int16_t>(sVar17 + 0xe);
                            } else {
                                uint32_t *icon = reinterpret_cast<uint32_t *>(&DAT_008d7ad8) +
                                                 reinterpret_cast<intptr_t>(local_72c4) * 0x30;
                                if (icon != nullptr) {
                                    pbStack_72c0 = reinterpret_cast<uint8_t *>(
                                        (*reinterpret_cast<int32_t *>(pbStack_72c0) - DAT_0072553c) + iVar8 + 0xf + iVar11);
                                    uVar23 = 0;
                                    uVar22 = 0x42200000;
                                    uVar7 = FUN_005f0ddc(0x42200000, 0);
                                    pbStack_72c0 = reinterpret_cast<uint8_t *>(
                                        iconDx + iVar16 +
                                        *reinterpret_cast<int32_t *>(local_4e24 + reinterpret_cast<intptr_t>(local_72b0) + 0x10) + -0x10);
                                    uVar9 = FUN_005f0ddc(uVar7);
                                    FUN_004bba60(icon, uVar9, uVar7, uVar22, uVar23);
                                }
                                sVar2 = *psVar18;
                                sVar17 = psVar18[1];
                                psVar18[2] = static_cast<int16_t>(reinterpret_cast<intptr_t>(local_72c4) + 1);
                                iVar11 = DAT_0086c330;
                                DAT_0086c1a0[iVar11] = static_cast<int16_t>(reinterpret_cast<intptr_t>(pcStack_72b8) + 6);
                                DAT_0086c010[iVar11] = sVar2;
                                DAT_0086be80[iVar11] = sVar17;
                                DAT_0086bcf0[iVar11] = static_cast<int16_t>(sVar2 + 10);
                                DAT_0086c330 = DAT_0086c330 + 1;
                                DAT_0086bb60[iVar11] = static_cast<int16_t>(sVar17 + 10);
                                pcVar12 = local_72b0;
                            }
                            *psVar18 = static_cast<int16_t>(sVar2 + 2);
                            psVar18[1] = static_cast<int16_t>(sVar17 + -0x10);
                            pcStack_72b4 = pcStack_72b4 + 1;
                            iconDx = iconDx + 0x10;
                            iVar11 = static_cast<int32_t>(reinterpret_cast<intptr_t>(pcStack_72b8)) + 1;
                            psVar18 = psVar18 + 3;
                            pcStack_72b8 = reinterpret_cast<char *>(static_cast<intptr_t>(iVar11));
                        }
                        local_72c4 = local_72c4 + 1;
                    } while (static_cast<int32_t>(reinterpret_cast<intptr_t>(local_72c4)) < 5);
                }
                iVar8 = iVar8 + *reinterpret_cast<int32_t *>(local_4e24 + reinterpret_cast<intptr_t>(pcVar12) + 0xc);
                iStack_72c8 = iStack_72c8 + 1;
                local_72b0 = pcVar12 + 0x14;
            } while (iStack_72c8 < DAT_0085a100);
        }

        // Background pedia texture and pause menu title.
        iVar8 = DAT_0085a26c;
        iVar11 = DAT_0085a268;
        int32_t pediaW = 0x400;
        int32_t pediaH = 0x300;
        uVar7 = FUN_004cddf0("PediaAlpha2.dds", 0, 0, &pediaW, &pediaH);
        FUN_004af080(uVar7, 0, 0, pediaW, pediaH, 0, 0, iVar8, iVar11, 0xffffffff, 0);
        FUN_004f6090("@PAUSEMENU", 4);
        DAT_0085a11c = 100;
        FUN_004b06c0(&DAT_00869b48, DAT_0085a26c / 2, 0xc, 100, 0xffffffff, 4, 0xffffffff, 0);

        // 4x4 international relations grid (treaty / war flags).
        iVar16 = 0;
        pcStack_72b8 = nullptr;
        iVar11 = DAT_0085a26c;
        iVar8 = DAT_0085a268;
        do {
            pcVar12 = reinterpret_cast<char *>(reinterpret_cast<intptr_t>(pcStack_72b8) + 1);
            pcStack_72b4 = pcVar12;
            pcStack_729c = pcVar12;
            if (static_cast<int32_t>(reinterpret_cast<intptr_t>(pcVar12)) < 4) {
                local_72b0 = acStack_7238 + iVar16 * 3 + 1;
                local_72c4 = reinterpret_cast<char *>(
                    reinterpret_cast<uint32_t *>(&DAT_0085a168) +
                    (reinterpret_cast<intptr_t>(pcVar12) +
                     reinterpret_cast<intptr_t>(pcStack_72b8) * 8));
                pcVar15 = pcStack_72b8;
                do {
                    int32_t relationKind = *reinterpret_cast<int32_t *>(local_72c4);
                    if ((relationKind == 1) || (relationKind == -1)) {
                        uint32_t *iconA = local_727c[
                            reinterpret_cast<intptr_t>(pcVar15) +
                            static_cast<uint32_t>(relationKind == 1) * 4];
                        if (iconA != nullptr) {
                            iStack_72c8 = ((iVar8 + (iVar8 >> 0x1f & 7)) >> 3) * iVar16 + iVar8 / 0xc;
                            uVar23 = 0;
                            uVar22 = 0x425c0000;
                            uVar7 = FUN_005f0ddc(0x425c0000, 0);
                            iStack_72c8 = (iVar11 + (iVar11 >> 0x1f & 0x3f)) >> 6;
                            uVar9 = FUN_005f0ddc(uVar7);
                            FUN_004bba60(iconA, uVar9, uVar7, uVar22, uVar23);
                            iVar11 = DAT_0085a26c;
                            iVar8 = DAT_0085a268;
                        }

                        uint32_t *iconB = local_727c[
                            reinterpret_cast<intptr_t>(pcStack_72b4) +
                            (3 - static_cast<uint32_t>(relationKind != 1)) * 4];
                        if (iconB != nullptr) {
                            iStack_72c8 = ((iVar8 + (iVar8 >> 0x1f & 7)) >> 3) * iVar16 + iVar8 / 0xc;
                            uVar23 = 0;
                            uVar22 = 0x425c0000;
                            uVar7 = FUN_005f0ddc(0x425c0000, 0);
                            iStack_72c8 = ((iVar11 + (iVar11 >> 0x1f & 0x3f)) >> 6) + iVar11 / 0x14 + 4;
                            uVar9 = FUN_005f0ddc(uVar7);
                            FUN_004bba60(iconB, uVar9, uVar7, uVar22, uVar23);
                            iVar11 = DAT_0085a26c;
                            iVar8 = DAT_0085a268;
                        }

                        puVar10 = local_7294_0;
                        puVar5 = local_7298;
                        bool drawRel = false;
                        if (relationKind == 1) {
                            if (local_7298 != nullptr) {
                                iStack_72c8 = ((iVar8 + (iVar8 >> 0x1f & 7)) >> 3) * iVar16 + iVar8 / 0xc + 0x26;
                                uVar22 = 0;
                                uVar9 = 0x425c0000;
                                uVar7 = FUN_005f0ddc(0x425c0000, 0);
                                iStack_72c8 = ((iVar11 + (iVar11 >> 0x1f & 0x3f)) >> 6) + 10;
                                puVar10 = puVar5;
                                drawRel = true;
                            }
                        } else if (local_7294_0 != nullptr) {
                            iStack_72c8 = ((iVar8 + (iVar8 >> 0x1f & 7)) >> 3) * iVar16 + iVar8 / 0xc + 0x1c;
                            uVar22 = 0;
                            uVar9 = 0x425c0000;
                            uVar7 = FUN_005f0ddc(0x425c0000, 0);
                            iStack_72c8 = ((iVar11 + (iVar11 >> 0x1f & 0x3f)) >> 6) + 0x26;
                            drawRel = true;
                        }
                        if (drawRel) {
                            uVar23 = FUN_005f0ddc(uVar7);
                            FUN_004bba60(puVar10, uVar23, uVar7, uVar9, uVar22);
                            iVar11 = DAT_0085a26c;
                            iVar8 = DAT_0085a268;
                        }

                        local_72b0[-1] = static_cast<char>(reinterpret_cast<intptr_t>(pcStack_72b8));
                        local_72b0[1] = static_cast<char>(relationKind);
                        *local_72b0 = static_cast<char>(reinterpret_cast<intptr_t>(pcStack_72b4));

                        pbStack_72c0 = reinterpret_cast<uint8_t *>(
                            static_cast<intptr_t>((iVar8 + (iVar8 >> 0x1f & 7)) >> 3));
                        iStack_72c8 = iVar16 * static_cast<int32_t>(reinterpret_cast<intptr_t>(pbStack_72c0)) +
                                     iVar8 / 0xc + 0xc;
                        iVar13 = DAT_0086c330;
                        DAT_0086be80[iVar13] = static_cast<int16_t>(iStack_72c8);
                        DAT_0086c330 = DAT_0086c330 + 1;
                        sVar2 = static_cast<int16_t>((iVar11 + (iVar11 >> 0x1f & 0x3f)) >> 6);
                        DAT_0086bcf0[iVar13] = static_cast<int16_t>(
                            ((iVar11 + (iVar11 >> 0x1f & 7)) >> 3) + 0x18 + sVar2);
                        DAT_0086c1a0[iVar13] = static_cast<int16_t>(iVar16);
                        iVar16 = iVar16 + 1;
                        local_72b0 = local_72b0 + 3;
                        DAT_0086bb60[iVar13] = static_cast<int16_t>(
                            static_cast<int16_t>(iStack_72c8) + -4 +
                            static_cast<int16_t>(reinterpret_cast<intptr_t>(pbStack_72c0)));
                        DAT_0086c010[iVar13] = sVar2;
                        pcVar15 = pcStack_72b8;
                        pcVar12 = pcStack_729c;
                    }
                    pcStack_72b4 = pcStack_72b4 + 1;
                    local_72c4 = local_72c4 + 4;
                } while (static_cast<int32_t>(reinterpret_cast<intptr_t>(pcStack_72b4)) < 4);
            }
            pcStack_72b8 = pcVar12;
        } while (static_cast<int32_t>(reinterpret_cast<intptr_t>(pcVar12)) < 4);

        FUN_004f6090("International Relations");
        DAT_0085a11c = 0x4b;
        FUN_004b06c0(&DAT_00869b48, 0x10, DAT_0085a268 / 0xc + -0x14, 0x4b, 0xffffffff, 1, 0xffffffff, 0);

        // Mouse / selection tracking.
        if ((local_7284 != DAT_008dc30c) || (local_728c != DAT_008dc310)) {
            local_7284 = DAT_008dc30c;
            local_728c = DAT_008dc310;
            uint32_t sel = FUN_0042c6f0();
            puStack_72bc = static_cast<int32_t>(sel);
            if ((static_cast<int32_t>(sel) != local_7294_1) && (static_cast<int32_t>(sel) != -1)) {
                FUN_004889c0(&DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
            }
            local_7294_1 = static_cast<int32_t>(sel);
        }

        if (puStack_72bc != -1) {
            if ((local_7294_1 < 0) || (5 < local_7294_1)) {
                iVar11 = local_7294_1 * 3;
                iVar16 = static_cast<int32_t>(asStack_7224[iVar11 + -0x11]);
                iVar8 = (DAT_0085a268 + (DAT_0085a268 >> 0x1f & 7)) >> 3;
                if ((iVar8 <= iVar16) && (iVar16 <= (DAT_0085a268 * 2) / 3 + -0x18 + iVar8)) {
                    if (puStack_72bc != local_7294_1) {
                        FUN_004889c0(&DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000, 0xffffffff);
                    }
                    sVar2 = asStack_7224[iVar11 + -0x10];
                    if (sVar2 == 0) {
                        FUN_004f6090("Gained Fame");
                    } else {
                        const char *msg;
                        if ((sVar2 < 1) || (5 < sVar2)) {
                            iVar8 = sVar2 - 6;
                            if (iVar8 == 4) msg = "Pirates Very Happy";
                            else msg = "@NATIONALITY Very Happy";
                        } else {
                            iVar8 = sVar2 - 1;
                            if (iVar8 == 4) msg = "Pirates Happy";
                            else msg = "@NATIONALITY Happy";
                        }
                        FUN_004f6090(msg, iVar8);
                    }
                    sVar2 = asStack_7224[iVar11 + -0x12];
                    FUN_004b06c0(&DAT_00869b48, sVar2 + 1, iVar16 + 1, 0x3c, 0xff000000, 4, 0xffffffff, 0);
                    FUN_004b06c0(&DAT_00869b48, static_cast<int32_t>(sVar2), iVar16, 0x3c, 0xffffcc00, 4, 0xffffffff, 0);
                }
            } else {
                iVar11 = local_7294_1 * 3;
                FUN_004f6090("@NATIONALITY and @NATIONALITY\n",
                             static_cast<int32_t>(acStack_7238[iVar11]),
                             static_cast<int32_t>(acStack_7238[iVar11 + 1]));
                const void *treatyText;
                if (acStack_7238[iVar11 + 2] == '\x01') {
                    treatyText = &PTR_DAT_006fff4c;
                } else {
                    treatyText = "Treaty";
                }
                FUN_004f60b0(treatyText);
                FUN_004879f0(0x18, 0);
                FUN_004b06c0(&DAT_00869b48,
                             ((DAT_0085a26c + (DAT_0085a26c >> 0x1f & 0x3f)) >> 6) + 0x39,
                             ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 7)) >> 3) * local_7294_1 +
                             DAT_0085a268 / 0xc + 0x19,
                             0x3c, 0xff000000, 4, 0xffffffff, 0);
                FUN_004b06c0(&DAT_00869b48,
                             ((DAT_0085a26c + (DAT_0085a26c >> 0x1f & 0x3f)) >> 6) + 0x38,
                             ((DAT_0085a268 + (DAT_0085a268 >> 0x1f & 7)) >> 3) * local_7294_1 +
                             DAT_0085a268 / 0xc + 0x18,
                             0x3c, 0xffffffff, 4, 0xffffffff, 0);
            }
        }

        // Input polling.
        iVar11 = FUN_004b2760(0);
        puVar5 = local_72a0;
        if (iVar11 < 0x127) {
            if (iVar11 == 0x126) {
                if (local_72a0 != nullptr) {
                    DAT_0072553c = DAT_0072553c + -0x20;
                    DAT_008ca988 = '\x01';
                }
            } else if ((iVar11 == 1) || (iVar11 == 0x1b)) {
                goto LAB_0043e448;
            }
        } else if ((iVar11 == 0x128) && (local_72a0 != nullptr)) {
            DAT_0072553c = DAT_0072553c + 0x20;
            DAT_008ca988 = '\x01';
        }

        if (local_72a5 != '\0') goto LAB_0043e448;
        iVar11 = DAT_0085a0fc;
    } while (true);

LAB_0043e448:
    DAT_0072553c = -1;

    // Detach and release scroller widget.
    if (local_72a0 != nullptr) {
        FUN_00504070(local_72a0);
        uint32_t vobj = local_72a0[9];
        uint32_t vtblAddr = *reinterpret_cast<uint32_t *>(at32(vobj));
        uint32_t *releaseObj = nullptr;
        reinterpret_cast<void (*)(void *, uint32_t *)>(
            *reinterpret_cast<void **>(at32(vtblAddr) + 0x74))(&releaseObj, local_72a0);
        if (releaseObj != nullptr) {
            release_ref(releaseObj);
        }
        release_ref(local_72a0);
    }

    DAT_0085a0fc = local_7280;

    // Release the two treaty icons.
    release_ref(local_7294_0);
    release_ref(local_7298);

    // Release 16 flag icons.
    for (int32_t n = 15; n >= 0; --n) {
        if (local_727c[n] != nullptr) {
            release_ref(local_727c[n]);
        }
    }

    // Teardown 1000 record strings and reset to DAT_008cacd0 empty sentinel.
    for (int32_t r = 999; r >= 0; --r) {
        uint8_t *rec = local_4e24 + r * 0x14;
        char *text = *reinterpret_cast<char **>(rec + 0x00);
        free_temp_string(text);
        *reinterpret_cast<uint32_t *>(rec + 0x00) = addr32(&DAT_008cacd0);
    }
}


// ===== 0x43e550 (delegated part, unified declarations) =====
extern int32_t FUN_004b17f0(uint32_t a, const char* name, int32_t x, int32_t y, uint32_t flags);
extern void FUN_00506040(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e);
extern void FUN_00505920(void);
extern void FUN_00412900(uint32_t a, uint32_t b, uint32_t c);
extern void FUN_005045a0(uint32_t a, uint32_t b, uint32_t c);
extern void FUN_00471120(void);
extern void FUN_0045bbf0(uint32_t a);
extern void FUN_004d1130(uint32_t a);
extern void FUN_004b1940(void);
extern void FUN_0042e730(void);
extern void FUN_00404e50(void);
extern void FUN_00404ca0(void);
extern int32_t FUN_00404910(uint32_t a);
extern int32_t FUN_00430190(uint32_t a, uint32_t b, const char* s, uint32_t c, uint32_t d,
                            uint32_t e, uint32_t f, uint32_t g, uint32_t h, uint32_t i);
extern uint8_t DAT_00723b14[];
extern uint8_t DAT_00723b1c[];
extern int32_t DAT_007261ec;
extern int32_t DAT_007261f0;
extern int16_t DAT_008142f8[];
extern int16_t DAT_00814318[];
extern int16_t DAT_0081431a[];
extern int16_t DAT_0081431e[];
extern uint8_t DAT_00814324[];
extern uint32_t DAT_00869b34;
extern int32_t* DAT_008cac40;
extern uint8_t DAT_008d74d8[];
extern int32_t DAT_008db618[];
extern int32_t DAT_008db61c[];
extern int32_t DAT_008db620[];
extern int32_t* DAT_008ea08c;

// 0x0043e550 — observed shape
void FUN_0043e550(char param_1)
{
    int32_t* piVar1;
    int32_t iVar2;
    int16_t sVar3;
    bool bVar4;
    uint32_t* puVar5;
    int16_t* psVar6;
    int32_t iVar7;
    int32_t iVar8;
    uint32_t uVar9;
    uint32_t uVar10;
    int32_t iVar11;
    int32_t iVar12;
    int16_t sVar13;
    int32_t iVar14;
    uint32_t* puVar15;
    int32_t iVar16;
    int32_t iVar17;
    int16_t sVar18;
    int32_t iVar19;
    int32_t iVar20;
    int32_t* piVar21;
    uint32_t** ppuVar22;
    uint8_t bVar23;
    int32_t iVar24;
    int32_t iVar25;
    uint32_t uVar26;
    uint32_t uVar27;
    uint32_t uStack_e0;
    int32_t iStack_d8;
    int32_t iStack_d4;
    int32_t iStack_d0;
    uint32_t* puStack_b8;
    int32_t local_b4;
    int32_t local_b0;
    uint32_t* local_ac[16];
    // Ghidra splits this frame area into aiStack_6c[4] + aiStack_5c[23]; the two
    // locals are adjacent on the stack and the listing indexes through both.
    int32_t aiStack_6c[27];

    puVar15 = nullptr;
    bVar4 = false;
    local_b0 = -1;
    local_b4 = -1;
    local_ac[8] = nullptr;
    local_ac[0] = nullptr;
    local_ac[1] = nullptr;
    local_ac[2] = nullptr;
    local_ac[3] = nullptr;
    local_ac[4] = nullptr;
    local_ac[5] = nullptr;
    local_ac[6] = nullptr;
    local_ac[7] = nullptr;

    puVar5 = static_cast<uint32_t*>(FUN_00533c78(0xc0));
    uVar9 = DAT_008ea008;
    if (puVar5 == nullptr) {
        puVar5 = nullptr;
    }
    else {
        puVar5[1] = 0;
        *puVar5 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c));
        puVar5[7] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar5[0x19] = 0;
        puVar5[0x2f] = 0;
        FUN_004bdca0(uVar9, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    if ((puVar5 != nullptr) && ((local_ac[0] = puVar5), puVar5 != nullptr)) {
        puVar5[1] = puVar5[1] + 1;
    }

    puVar5 = static_cast<uint32_t*>(FUN_00533c78(0xc0));
    uVar9 = DAT_008ea008;
    if (puVar5 == nullptr) {
        puVar5 = nullptr;
    }
    else {
        puVar5[1] = 0;
        *puVar5 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c));
        puVar5[7] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar5[0x19] = 0;
        puVar5[0x2f] = 0;
        FUN_004bdca0(uVar9, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
        puVar15 = local_ac[1];
    }
    if (puVar15 != puVar5) {
        if (puVar15 != nullptr) {
            piVar21 = reinterpret_cast<int32_t*>(puVar15 + 1);
            *piVar21 = *piVar21 + -1;
            if (*piVar21 == 0) {
                reinterpret_cast<void (*)(int32_t)>(
                    static_cast<uintptr_t>(*puVar15))(1);
            }
        }
        local_ac[1] = puVar5;
        if (puVar5 != nullptr) {
            puVar5[1] = puVar5[1] + 1;
        }
    }

    puVar15 = static_cast<uint32_t*>(FUN_00533c78(0xc0));
    uVar9 = DAT_008ea008;
    if (puVar15 == nullptr) {
        puVar15 = nullptr;
    }
    else {
        puVar15[1] = 0;
        *puVar15 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c));
        puVar15[7] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar15[0x19] = 0;
        puVar15[0x2f] = 0;
        FUN_004bdca0(uVar9, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    if (local_ac[2] != puVar15) {
        if (local_ac[2] != nullptr) {
            piVar21 = reinterpret_cast<int32_t*>(local_ac[2] + 1);
            *piVar21 = *piVar21 + -1;
            if (*piVar21 == 0) {
                reinterpret_cast<void (*)(int32_t)>(
                    static_cast<uintptr_t>(*local_ac[2]))(1);
            }
        }
        local_ac[2] = puVar15;
        if (puVar15 != nullptr) {
            puVar15[1] = puVar15[1] + 1;
        }
    }

    puVar15 = static_cast<uint32_t*>(FUN_00533c78(0xc0));
    uVar9 = DAT_008ea008;
    if (puVar15 == nullptr) {
        puVar15 = nullptr;
    }
    else {
        puVar15[1] = 0;
        *puVar15 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c));
        puVar15[7] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar15[0x19] = 0;
        puVar15[0x2f] = 0;
        FUN_004bdca0(uVar9, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    if (local_ac[3] != puVar15) {
        if (local_ac[3] != nullptr) {
            piVar21 = reinterpret_cast<int32_t*>(local_ac[3] + 1);
            *piVar21 = *piVar21 + -1;
            if (*piVar21 == 0) {
                reinterpret_cast<void (*)(int32_t)>(
                    static_cast<uintptr_t>(*local_ac[3]))(1);
            }
        }
        local_ac[3] = puVar15;
        if (puVar15 != nullptr) {
            puVar15[1] = puVar15[1] + 1;
        }
    }

    puVar15 = static_cast<uint32_t*>(FUN_00533c78(0xc0));
    uVar9 = DAT_008ea008;
    if (puVar15 == nullptr) {
        puVar15 = nullptr;
    }
    else {
        puVar15[1] = 0;
        *puVar15 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c));
        puVar15[7] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar15[0x19] = 0;
        puVar15[0x2f] = 0;
        FUN_004bdca0(uVar9, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    if (local_ac[4] != puVar15) {
        if (local_ac[4] != nullptr) {
            piVar21 = reinterpret_cast<int32_t*>(local_ac[4] + 1);
            *piVar21 = *piVar21 + -1;
            if (*piVar21 == 0) {
                reinterpret_cast<void (*)(int32_t)>(
                    static_cast<uintptr_t>(*local_ac[4]))(1);
            }
        }
        local_ac[4] = puVar15;
        if (puVar15 != nullptr) {
            puVar15[1] = puVar15[1] + 1;
        }
    }

    puVar15 = static_cast<uint32_t*>(FUN_00533c78(0xc0));
    uVar9 = DAT_008ea008;
    if (puVar15 == nullptr) {
        puVar15 = nullptr;
    }
    else {
        puVar15[1] = 0;
        *puVar15 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c));
        puVar15[7] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar15[0x19] = 0;
        puVar15[0x2f] = 0;
        FUN_004bdca0(uVar9, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    if (local_ac[5] != puVar15) {
        if (local_ac[5] != nullptr) {
            piVar21 = reinterpret_cast<int32_t*>(local_ac[5] + 1);
            *piVar21 = *piVar21 + -1;
            if (*piVar21 == 0) {
                reinterpret_cast<void (*)(int32_t)>(
                    static_cast<uintptr_t>(*local_ac[5]))(1);
            }
        }
        local_ac[5] = puVar15;
        if (puVar15 != nullptr) {
            puVar15[1] = puVar15[1] + 1;
        }
    }

    puVar15 = static_cast<uint32_t*>(FUN_00533c78(0xc0));
    uVar9 = DAT_008ea008;
    if (puVar15 == nullptr) {
        puVar15 = nullptr;
    }
    else {
        puVar15[1] = 0;
        *puVar15 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c));
        puVar15[7] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar15[0x19] = 0;
        puVar15[0x2f] = 0;
        FUN_004bdca0(uVar9, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    if (local_ac[6] != puVar15) {
        if (local_ac[6] != nullptr) {
            piVar21 = reinterpret_cast<int32_t*>(local_ac[6] + 1);
            *piVar21 = *piVar21 + -1;
            if (*piVar21 == 0) {
                reinterpret_cast<void (*)(int32_t)>(
                    static_cast<uintptr_t>(*local_ac[6]))(1);
            }
        }
        local_ac[6] = puVar15;
        if (puVar15 != nullptr) {
            puVar15[1] = puVar15[1] + 1;
        }
    }

    puVar15 = static_cast<uint32_t*>(FUN_00533c78(0xc0));
    uVar9 = DAT_008ea008;
    if (puVar15 == nullptr) {
        puVar15 = nullptr;
    }
    else {
        puVar15[1] = 0;
        *puVar15 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c));
        puVar15[7] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar15[0x19] = 0;
        puVar15[0x2f] = 0;
        FUN_004bdca0(uVar9, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    if (local_ac[7] != puVar15) {
        if (local_ac[7] != nullptr) {
            piVar21 = reinterpret_cast<int32_t*>(local_ac[7] + 1);
            *piVar21 = *piVar21 + -1;
            if (*piVar21 == 0) {
                reinterpret_cast<void (*)(int32_t)>(
                    static_cast<uintptr_t>(*local_ac[7]))(1);
            }
        }
        local_ac[7] = puVar15;
        if (puVar15 != nullptr) {
            puVar15[1] = puVar15[1] + 1;
        }
    }

    puVar15 = static_cast<uint32_t*>(FUN_00533c78(0xc0));
    uVar9 = DAT_008ea008;
    if (puVar15 == nullptr) {
        puVar15 = nullptr;
    }
    else {
        puVar15[1] = 0;
        *puVar15 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c));
        puVar15[7] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar15[0x19] = 0;
        puVar15[0x2f] = 0;
        FUN_004bdca0(uVar9, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    if ((puVar15 != nullptr) && ((local_ac[8] = puVar15), puVar15 != nullptr)) {
        puVar15[1] = puVar15[1] + 1;
    }

    aiStack_6c[0] = 0;
    local_ac[9] = nullptr;
    local_ac[10] = nullptr;
    local_ac[0xb] = nullptr;
    local_ac[0xc] = nullptr;
    local_ac[0xd] = nullptr;
    local_ac[0xe] = nullptr;
    local_ac[0xf] = nullptr;

    puVar15 = static_cast<uint32_t*>(FUN_00533c78(0xc0));
    uVar9 = DAT_008ea008;
    if (puVar15 == nullptr) {
        puVar15 = nullptr;
    }
    else {
        puVar15[1] = 0;
        *puVar15 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c));
        puVar15[7] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar15[0x19] = 0;
        puVar15[0x2f] = 0;
        FUN_004bdca0(uVar9, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    if ((puVar15 != nullptr) && ((local_ac[9] = puVar15), puVar15 != nullptr)) {
        puVar15[1] = puVar15[1] + 1;
    }

    puVar15 = static_cast<uint32_t*>(FUN_00533c78(0xc0));
    uVar9 = DAT_008ea008;
    if (puVar15 == nullptr) {
        puVar15 = nullptr;
    }
    else {
        puVar15[1] = 0;
        *puVar15 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c));
        puVar15[7] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar15[0x19] = 0;
        puVar15[0x2f] = 0;
        FUN_004bdca0(uVar9, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    if (local_ac[10] != puVar15) {
        if (local_ac[10] != nullptr) {
            piVar21 = reinterpret_cast<int32_t*>(local_ac[10] + 1);
            *piVar21 = *piVar21 + -1;
            if (*piVar21 == 0) {
                reinterpret_cast<void (*)(int32_t)>(
                    static_cast<uintptr_t>(*local_ac[10]))(1);
            }
        }
        local_ac[10] = puVar15;
        if (puVar15 != nullptr) {
            puVar15[1] = puVar15[1] + 1;
        }
    }

    puVar15 = static_cast<uint32_t*>(FUN_00533c78(0xc0));
    uVar9 = DAT_008ea008;
    if (puVar15 == nullptr) {
        puVar15 = nullptr;
    }
    else {
        puVar15[1] = 0;
        *puVar15 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c));
        puVar15[7] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar15[0x19] = 0;
        puVar15[0x2f] = 0;
        FUN_004bdca0(uVar9, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    if (local_ac[0xb] != puVar15) {
        if (local_ac[0xb] != nullptr) {
            piVar21 = reinterpret_cast<int32_t*>(local_ac[0xb] + 1);
            *piVar21 = *piVar21 + -1;
            if (*piVar21 == 0) {
                reinterpret_cast<void (*)(int32_t)>(
                    static_cast<uintptr_t>(*local_ac[0xb]))(1);
            }
        }
        local_ac[0xb] = puVar15;
        if (puVar15 != nullptr) {
            puVar15[1] = puVar15[1] + 1;
        }
    }

    puVar15 = static_cast<uint32_t*>(FUN_00533c78(0xc0));
    uVar9 = DAT_008ea008;
    if (puVar15 == nullptr) {
        puVar15 = nullptr;
    }
    else {
        puVar15[1] = 0;
        *puVar15 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c));
        puVar15[7] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar15[0x19] = 0;
        puVar15[0x2f] = 0;
        FUN_004bdca0(uVar9, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    if (local_ac[0xc] != puVar15) {
        if (local_ac[0xc] != nullptr) {
            piVar21 = reinterpret_cast<int32_t*>(local_ac[0xc] + 1);
            *piVar21 = *piVar21 + -1;
            if (*piVar21 == 0) {
                reinterpret_cast<void (*)(int32_t)>(
                    static_cast<uintptr_t>(*local_ac[0xc]))(1);
            }
        }
        local_ac[0xc] = puVar15;
        if (puVar15 != nullptr) {
            puVar15[1] = puVar15[1] + 1;
        }
    }

    puVar15 = static_cast<uint32_t*>(FUN_00533c78(0xc0));
    uVar9 = DAT_008ea008;
    if (puVar15 == nullptr) {
        puVar15 = nullptr;
    }
    else {
        puVar15[1] = 0;
        *puVar15 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c));
        puVar15[7] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar15[0x19] = 0;
        puVar15[0x2f] = 0;
        FUN_004bdca0(uVar9, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    if (local_ac[0xd] != puVar15) {
        if (local_ac[0xd] != nullptr) {
            piVar21 = reinterpret_cast<int32_t*>(local_ac[0xd] + 1);
            *piVar21 = *piVar21 + -1;
            if (*piVar21 == 0) {
                reinterpret_cast<void (*)(int32_t)>(
                    static_cast<uintptr_t>(*local_ac[0xd]))(1);
            }
        }
        local_ac[0xd] = puVar15;
        if (puVar15 != nullptr) {
            puVar15[1] = puVar15[1] + 1;
        }
    }

    puVar15 = static_cast<uint32_t*>(FUN_00533c78(0xc0));
    uVar9 = DAT_008ea008;
    if (puVar15 == nullptr) {
        puVar15 = nullptr;
    }
    else {
        puVar15[1] = 0;
        *puVar15 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c));
        puVar15[7] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar15[0x19] = 0;
        puVar15[0x2f] = 0;
        FUN_004bdca0(uVar9, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    if (local_ac[0xe] != puVar15) {
        if (local_ac[0xe] != nullptr) {
            piVar21 = reinterpret_cast<int32_t*>(local_ac[0xe] + 1);
            *piVar21 = *piVar21 + -1;
            if (*piVar21 == 0) {
                reinterpret_cast<void (*)(int32_t)>(
                    static_cast<uintptr_t>(*local_ac[0xe]))(1);
            }
        }
        local_ac[0xe] = puVar15;
        if (puVar15 != nullptr) {
            puVar15[1] = puVar15[1] + 1;
        }
    }

    puVar15 = static_cast<uint32_t*>(FUN_00533c78(0xc0));
    uVar9 = DAT_008ea008;
    if (puVar15 == nullptr) {
        puVar15 = nullptr;
    }
    else {
        puVar15[1] = 0;
        *puVar15 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c));
        puVar15[7] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar15[0x19] = 0;
        puVar15[0x2f] = 0;
        FUN_004bdca0(uVar9, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    if (local_ac[0xf] != puVar15) {
        if (local_ac[0xf] != nullptr) {
            piVar21 = reinterpret_cast<int32_t*>(local_ac[0xf] + 1);
            *piVar21 = *piVar21 + -1;
            if (*piVar21 == 0) {
                reinterpret_cast<void (*)(int32_t)>(
                    static_cast<uintptr_t>(*local_ac[0xf]))(1);
            }
        }
        local_ac[0xf] = puVar15;
        if (puVar15 != nullptr) {
            puVar15[1] = puVar15[1] + 1;
        }
    }

    puVar15 = static_cast<uint32_t*>(FUN_00533c78(0xc0));
    uVar9 = DAT_008ea008;
    if (puVar15 == nullptr) {
        puVar15 = nullptr;
    }
    else {
        puVar15[1] = 0;
        *puVar15 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c));
        puVar15[7] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar15[0x19] = 0;
        puVar15[0x2f] = 0;
        FUN_004bdca0(uVar9, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    if ((puVar15 != nullptr) &&
        ((aiStack_6c[0] = static_cast<int32_t>(reinterpret_cast<intptr_t>(puVar15))),
         puVar15 != nullptr)) {
        puVar15[1] = puVar15[1] + 1;
    }

    puStack_b8 = nullptr;
    puVar15 = static_cast<uint32_t*>(FUN_00533c78(0xc0));
    uVar9 = DAT_008ea008;
    if (puVar15 != nullptr) {
        puVar15[1] = 0;
        *puVar15 = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&PTR_FUN_006fd14c));
        DAT_00727444 = DAT_00727444 + 1;
        puVar15[7] = 0;
        puVar15[0x19] = 0;
        puVar15[0x2f] = 0;
        FUN_004bdca0(uVar9, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
        puVar15[1] = puVar15[1] + 1;
        puStack_b8 = puVar15;
    }

    iVar17 = DAT_007261f0;
    iStack_d0 = 0;
    iStack_d8 = 0;
    psVar6 = &DAT_008142f8[0];
    do {
        if (*psVar6 != -1) {
            iStack_d0 = iStack_d0 + 1;
        }
        psVar6 = psVar6 + 0x22e;
    } while (static_cast<int32_t>(reinterpret_cast<intptr_t>(psVar6)) < 0x8165d8);

    iVar7 = DAT_0085a26c / 2;
    iVar24 = static_cast<int32_t>(static_cast<uint32_t>(DAT_0085a26c) +
                                   static_cast<uint32_t>((DAT_0085a26c >> 0x1f) & 0x1f)) >> 5;
    iVar14 = iVar7 - iVar24;
    iVar2 = iVar7 + iVar24;
    iVar7 = iVar7 + iVar24 * 3;
    aiStack_6c[2] = DAT_0085a26c - DAT_0085a26c / 5;
    iVar24 = static_cast<int32_t>(
        static_cast<uint64_t>(static_cast<int64_t>(DAT_0085a26c) * -0x66666667LL) >> 0x20);
    iVar19 = DAT_007261f0 + -0x20;
    iVar24 = (((iVar24 >> 1) - (iVar24 >> 0x1f)) -
              (static_cast<int32_t>(static_cast<uint32_t>(DAT_0085a26c) +
                                    static_cast<uint32_t>((DAT_0085a26c >> 0x1f) & 0xf)) >> 4)) +
             DAT_0085a26c;

    if (0 < iStack_d0) {
        piVar21 = aiStack_6c + 4;
        iVar25 = 0x10;
        iVar20 = iVar19;
        iStack_d4 = iStack_d0;
        do {
            if (iVar25 != 0x10) {
                iVar8 = FUN_004b17f0(0, "button_makeFlagship.kfm", iVar14, iVar20, 0xfffffff6);
                piVar21[-1] = iVar8;
                if (param_1 == '\0') {
                    FUN_00506040(9, 0x3f800000, 0, 0, 0x3f800000);
                    *reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar8) + 0x290) = 0;
                }
                iVar8 = FUN_004b17f0(0, "button_abandon.kfm", iVar2, iVar20, 0xfffffff6);
                *piVar21 = iVar8;
                if (param_1 == '\0') {
                    FUN_00506040(9, 0x3f800000, 0, 0, 0x3f800000);
                    *reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar8) + 0x290) = 0;
                }
            }
            iVar8 = FUN_004b17f0(0, "button_changeName.kfm", iVar7, iVar20, 0xfffffff6);
            piVar21[1] = iVar8;
            iVar20 = iVar20 + 0x28;
            iVar25 = iVar25 + 3;
            piVar21 = piVar21 + 3;
            iStack_d4 = iStack_d4 + -1;
        } while (iStack_d4 != 0);
    }

    do {
        if (DAT_008cac27 != '\0') {
            bVar4 = true;
        }
        iVar20 = 0;
        FUN_004b24a0(static_cast<uint32_t>(DAT_008cabe8), 0);
        DAT_0086c330 = 0;
        FUN_004f6090("Ships");
        DAT_0085a11c = 100;
        FUN_004b06c0(&DAT_00869b48, 0xaa, DAT_007261ec + -0x1e, 100, 0xffffffff, 4, 0xffffffff, 0);
        FUN_004f6090("Flagship");
        DAT_0085a11c = 0x32;
        FUN_004b06c0(&DAT_00869b48, iVar14, DAT_007261ec + -0xd, 0x32, 0xffc00000, 4, 0xffffffff,
                     0);
        FUN_004f6090("Abandon");
        if ((DAT_008e9f5c < 6) || (0xb < DAT_008e9f5c)) {
            iVar25 = DAT_007261ec + 3;
        }
        else {
            iVar25 = DAT_007261ec + -0xd;
        }
        DAT_0085a11c = 0x32;
        FUN_004b06c0(&DAT_00869b48, iVar2, iVar25, 0x32, 0xffc00000, 4, 0xffffffff, 0);
        FUN_004f6090("Rename");
        DAT_0085a11c = 0x32;
        FUN_004b06c0(&DAT_00869b48, iVar7, DAT_007261ec + -0xd, 0x32, 0xffc00000, 4, 0xffffffff, 0);

        if (puStack_b8 != nullptr) {
            uVar27 = 0;
            uVar26 = 0x42480000;
            uVar9 = FUN_005f0ddc(0x42480000, 0);
            uVar10 = FUN_005f0ddc(uVar9);
            FUN_004bba60(puStack_b8, uVar10, uVar9, uVar26, uVar27);
        }

        do {
            iVar25 = iVar20 * 0x45c;
            if (DAT_008142f8[iVar20 * 0x22e] != -1) {
                iVar8 = iVar19 + iVar20 * 0x28;
                iVar16 = -1;
                if (iStack_d8 == iVar20) {
                    FUN_004af080(0, 0, 0, 0, 0, 0x2c, iVar8 + -0xc, DAT_0085a26c / 2, 0x28,
                                 0xc0204080, 0xa0);
                    iVar16 = -0x3400;
                }
                puVar15 = local_ac[static_cast<int32_t>(DAT_008142f8[iVar20 * 0x22e]) % 9];
                if (puVar15 != nullptr) {
                    uVar27 = 0;
                    uVar26 = 0x42200000;
                    uVar9 = FUN_005f0ddc(0x42200000, 0);
                    uVar10 = FUN_005f0ddc(uVar9);
                    FUN_004bba60(puVar15, uVar10, uVar9, uVar26, uVar27);
                }
                if (iVar20 == 0) {
                    FUN_004f6090("Your flagship...");
                    DAT_0085a11c = 0x32;
                    iVar11 = iVar16;
                    if (iVar16 == 0) {
                        iVar11 = -1;
                    }
                    FUN_004b06c0(&DAT_00869b48, 0x6c, iVar8 + -0x17, 0x32, iVar11, 1, 0xffffffff,
                                 0);
                }
                FUN_004f6090("@SHIPTYPE: ", static_cast<int32_t>(DAT_008142f8[iVar20 * 0x22e]));
                DAT_0085a11c = 0x50;
                iVar11 = iVar16;
                if (iVar16 == 0) {
                    iVar11 = -1;
                }
                FUN_004b06c0(&DAT_00869b48, 0x6c, iVar8 + -0xd, 0x50, iVar11, 1, 0xffffffff, 0);
                DAT_0085a11c = 0x50;
                DAT_008c9de0 = DAT_008c9dd8;
                FUN_00509500(static_cast<uint32_t>(DAT_008c9dd8), &DAT_00869b48, 0);
                iVar12 = static_cast<int32_t>(FUN_005f0ddc());
                FUN_004f6090("'@SHIPNAME'", DAT_008db618[iVar20 * 3], DAT_008db61c[iVar20 * 3],
                             DAT_008db620[iVar20 * 3]);
                DAT_0085a11c = 0x32;
                iVar11 = iVar16;
                if (iVar16 == 0) {
                    iVar11 = -1;
                }
                FUN_004b06c0(&DAT_00869b48, static_cast<uint32_t>(iVar12 + 0x6c), iVar8 + -9,
                             0x32, iVar11, 1, 0xffffffff, 0);
                if ((DAT_00814318[iVar20 * 0x22e] == 0) && (DAT_0081431a[iVar20 * 0x22e] == 0)) {
                    FUN_004f6090(
                        "(@NUM crew, @NUM max)",
                        static_cast<int32_t>(DAT_0081431e[iVar20 * 0x22e]),
                        (static_cast<int32_t>(((DAT_00814324[iVar25] & 4) | 8) >> 2) *
                         *reinterpret_cast<int32_t*>(&DAT_00723b14[
                             static_cast<int32_t>(DAT_008142f8[iVar20 * 0x22e]) * 0x44])) /
                            2);
                }
                else {
                    iVar11 = static_cast<int32_t>(DAT_0081431a[iVar20 * 0x22e]);
                    if (iVar11 < 0) {
                        iVar11 = 0;
                    }
                    else if (100 < iVar11) {
                        iVar11 = 100;
                    }
                    iVar12 = static_cast<int32_t>(DAT_00814318[iVar20 * 0x22e]);
                    if (iVar12 < 0) {
                        iVar12 = 0;
                    }
                    else if (100 < iVar12) {
                        iVar12 = 100;
                    }
                    FUN_004f6090(
                        "(@NUM crew, @NUM max; Damage Sails:@NUM% Hull:@NUM%)",
                        static_cast<int32_t>(DAT_0081431e[iVar20 * 0x22e]),
                        (static_cast<int32_t>(((DAT_00814324[iVar25] & 4) | 8) >> 2) *
                         *reinterpret_cast<int32_t*>(&DAT_00723b14[
                             static_cast<int32_t>(DAT_008142f8[iVar20 * 0x22e]) * 0x44])) /
                            2,
                        static_cast<uint32_t>(iVar12), static_cast<uint32_t>(iVar11));
                }
                DAT_0085a11c = 0x32;
                if (iVar16 == 0) {
                    iVar16 = -1;
                }
                FUN_004b06c0(&DAT_00869b48, 0x6c, iVar8 + 2, 0x32, iVar16, 1, 0xffffffff, 0);
                aiStack_6c[1] = iVar8 + 0x11;
                sVar3 = static_cast<int16_t>(iVar8);
                sVar18 = static_cast<int16_t>(iVar20);
                if ((iVar20 != 0) && (param_1 != '\0')) {
                    iVar8 = DAT_0086c330;
                    DAT_0086bcf0[iVar8] = static_cast<int16_t>(static_cast<int16_t>(iVar14) + 0x14);
                    DAT_0086bb60[iVar8] = static_cast<int16_t>(sVar3 + 0x16);
                    DAT_0086be80[iVar8] = static_cast<int16_t>(sVar3 + -8);
                    DAT_0086c1a0[iVar8] = sVar18;
                    DAT_0086c010[iVar8] = 0x62;
                    sVar13 = static_cast<int16_t>(DAT_0086c330 + 1);
                    DAT_0086c010[sVar13] = static_cast<int16_t>(static_cast<int16_t>(iVar2) + -10);
                    DAT_0086be80[sVar13] = static_cast<int16_t>(sVar3 + -8);
                    DAT_0086c1a0[sVar13] = static_cast<int16_t>(sVar18 + 8);
                    DAT_0086bcf0[sVar13] = static_cast<int16_t>(static_cast<int16_t>(iVar2) + 0x14);
                    DAT_0086bb60[sVar13] = static_cast<int16_t>(sVar3 + 0x16);
                    DAT_0086c330 = DAT_0086c330 + 2;
                }
                DAT_0086be80[DAT_0086c330] = static_cast<int16_t>(sVar3 + -8);
                DAT_0086c010[DAT_0086c330] = static_cast<int16_t>(static_cast<int16_t>(iVar7) + -10);
                DAT_0086c1a0[DAT_0086c330] = static_cast<int16_t>(sVar18 + 0x10);
                DAT_0086bb60[DAT_0086c330] = static_cast<int16_t>(sVar3 + 0x16);
                DAT_0086bcf0[DAT_0086c330] = static_cast<int16_t>(static_cast<int16_t>(iVar7) + 0x14);
                bVar23 = 0;
                puVar15 = reinterpret_cast<uint32_t*>(&DAT_008d74d8[0]);
                DAT_0086c330 = DAT_0086c330 + 1;
                do {
                    if (((static_cast<int32_t>(
                              *reinterpret_cast<int16_t*>(&DAT_00814324[iVar25])) &
                          (1 << (bVar23 & 0x1f))) != 0) &&
                        (puVar15 != nullptr)) {
                        uVar27 = 0;
                        uVar26 = 0x420c0000;
                        uVar9 = FUN_005f0ddc(0x420c0000, 0);
                        uVar10 = FUN_005f0ddc(uVar9);
                        FUN_004bba60(puVar15, uVar10, uVar9, uVar26, uVar27);
                    }
                    puVar15 = puVar15 + 0x30;
                    bVar23 = bVar23 + 1;
                } while (static_cast<int32_t>(reinterpret_cast<intptr_t>(puVar15)) < 0x8d7ad8);
            }
            iVar20 = iVar20 + 1;
        } while (iVar20 < 8);

        if ((local_b0 != DAT_008dc30c) || (local_b4 != DAT_008dc310)) {
            local_b0 = DAT_008dc30c;
            local_b4 = DAT_008dc310;
            if ((0x2b < DAT_008dc30c) &&
                (((DAT_008dc30c < iVar7 + 0x14) && (iVar17 + -0x2c <= DAT_008dc310)) &&
                 (DAT_008dc310 < iVar17 + -0x2c + iStack_d0 * 0x28))) {
                iVar20 = ((DAT_008dc310 - iVar19) + 0xc) / 0x28;
                if (iVar20 != iStack_d8) {
                    iVar25 = iStack_d8 * 3 + 0xf;
                    if (((-1 < iVar25) && (iVar25 < 0x2b)) &&
                        (iVar25 = *reinterpret_cast<int32_t*>(static_cast<intptr_t>(DAT_008cabe8) +
                                                              0x18 + iVar25 * 4),
                         iVar25 != 0)) {
                        FUN_00505920();
                        iVar25 = *reinterpret_cast<int32_t*>(static_cast<intptr_t>(iVar25) + 0x23c);
                        uint8_t* listBase = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(iVar25));
                        puVar15 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(
                            *reinterpret_cast<uint32_t*>(listBase + 0x18)));
                        while (puVar15 != nullptr) {
                            puVar5 = reinterpret_cast<uint32_t*>(
                                static_cast<uintptr_t>(*puVar15));
                            void** vtbl = reinterpret_cast<void**>(static_cast<uintptr_t>(
                                *reinterpret_cast<uint32_t*>(listBase + 0x14)));
                            reinterpret_cast<void (*)(uint32_t*)>(vtbl[2])(puVar15);
                            puVar15 = puVar5;
                        }
                        *reinterpret_cast<uint32_t*>(listBase + 0x20) = 0;
                        *reinterpret_cast<uint32_t*>(listBase + 0x18) = 0;
                        *reinterpret_cast<uint32_t*>(listBase + 0x1c) = 0;
                        FUN_00506040(0, 0x3f800000, 0, 0, 0x3f800000);
                    }
                    FUN_004889c0(&DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000,
                                 0xffffffff);
                    iStack_d8 = iVar20;
                }
            }
        }

        if (((iStack_d8 != -1) && (iVar20 = iStack_d8 * 3 + 0xf, -1 < iVar20)) &&
            ((iVar20 < 0x2b &&
              (iVar20 = *reinterpret_cast<int32_t*>(static_cast<intptr_t>(DAT_008cabe8) + 0x18 +
                                                    iVar20 * 4),
               iVar20 != 0)))) {
            iVar25 = FUN_0042c6f0();
            if (iVar25 < 8) {
                FUN_00505920();
                int32_t listObj = *reinterpret_cast<int32_t*>(static_cast<intptr_t>(iVar20) + 0x23c);
                uint8_t* lb = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(listObj));
                piVar21 = reinterpret_cast<int32_t*>(lb + 0x14);
                puVar15 = reinterpret_cast<uint32_t*>(
                    static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(lb + 0x18)));
                while (puVar15 != nullptr) {
                    puVar5 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(*puVar15));
                    void** vtbl = reinterpret_cast<void**>(static_cast<uintptr_t>(
                        static_cast<uint32_t>(*piVar21)));
                    reinterpret_cast<void (*)(uint32_t*)>(vtbl[2])(puVar15);
                    puVar15 = puVar5;
                }
                uVar9 = 7;
            }
            else {
                FUN_00505920();
                int32_t listObj = *reinterpret_cast<int32_t*>(static_cast<intptr_t>(iVar20) + 0x23c);
                uint8_t* lb = reinterpret_cast<uint8_t*>(static_cast<intptr_t>(listObj));
                piVar21 = reinterpret_cast<int32_t*>(lb + 0x14);
                puVar15 = reinterpret_cast<uint32_t*>(
                    static_cast<uintptr_t>(*reinterpret_cast<uint32_t*>(lb + 0x18)));
                while (puVar15 != nullptr) {
                    puVar5 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(*puVar15));
                    void** vtbl = reinterpret_cast<void**>(static_cast<uintptr_t>(
                        static_cast<uint32_t>(*piVar21)));
                    reinterpret_cast<void (*)(uint32_t*)>(vtbl[2])(puVar15);
                    puVar15 = puVar5;
                }
                uVar9 = 0;
            }
            piVar21[2] = 0;
            piVar21[1] = 0;
            piVar21[3] = 0;
            FUN_00506040(uVar9, 0x3f800000, 0, 0, 0x3f800000);
        }

        FUN_004f6090("Specialists");
        DAT_0085a11c = 100;
        FUN_004b06c0(&DAT_00869b48, aiStack_6c[2], DAT_007261ec + -0x1e, 100, 0xffffffff, 4,
                     0xffffffff, 0);
        iVar25 = 0;
        iVar20 = iVar17 + -0x2f;
        do {
            if ((1 << (static_cast<uint8_t>(iVar25) & 0x1f) & DAT_00869b34) != 0) {
                FUN_004f6090("@SPEC", static_cast<uint32_t>(iVar25));
                DAT_0085a11c = 0x50;
                FUN_004b06c0(&DAT_00869b48, iVar24 + -0x14, iVar20 + 2, 0x50, 0xffffff80, 1,
                             0xffffffff, 0);
                FUN_00412900(iVar24 + -0x3c, iVar20, 0x4b);
                FUN_004f6090("A @SPEC can @SPECED.", static_cast<uint32_t>(iVar25),
                             static_cast<uint32_t>(iVar25));
                DAT_0085a11c = 0x32;
                FUN_004b06c0(&DAT_00869b48, iVar24 + -0x14, iVar20 + 0x12, 0x32, 0xffffffff,
                             0x40000001, static_cast<uint32_t>(((DAT_0085a26c - iVar24) * 0x400) / 0x280),
                             0);
                iVar20 = iVar20 + 0x28;
            }
            iVar25 = iVar25 + 1;
        } while (iVar25 < 8);

        iVar20 = FUN_004b2760(1);
        piVar21 = DAT_008cac40;
        if (((iVar20 == 1) || (iVar20 == 0x1b)) || (iVar20 == 0x20)) {
            bVar4 = true;
        }
        if (iVar20 < 0x73) {
            if (iVar20 == 0x72) {
                if (iStack_d8 < 1) goto LAB_0043fca8;
                iVar20 = iStack_d8 + 0x210;
            }
            else if (iVar20 == 0xd) {
                if ((iStack_d8 < 1) || (param_1 == '\0')) goto LAB_0043fca8;
                iVar20 = iStack_d8 + 0x200;
            }
            else if (iVar20 == 0x2e) {
                if ((iStack_d8 < 1) || (param_1 == '\0')) goto LAB_0043fca8;
                iVar20 = iStack_d8 + 0x208;
            }
        LAB_0043f993:
            if ((0x1ff < iVar20) && (iVar20 < 0x218)) {
                uStack_e0 = static_cast<uint32_t>(iVar20) - 0x200U & 0x80000007U;
                if (static_cast<int32_t>(uStack_e0) < 0) {
                    uStack_e0 = (uStack_e0 - 1 | 0xfffffff8U) + 1;
                }
                if (DAT_008142f8[uStack_e0 * 0x22e] != -1) {
                    if (iVar20 < 0x208) {
                        FUN_0042e730();
                        FUN_00404e50();
                    }
                    else if (iVar20 < 0x210) {
                        FUN_0042e730();
                        sVar3 = DAT_008142f8[uStack_e0 * 0x22e];
                        DAT_007268f4[DAT_00726a84] = DAT_007263bc;
                        DAT_007263bc = DAT_007263bc & 0xfff7ffffU;
                        iVar20 = *reinterpret_cast<int32_t*>(
                            &DAT_00723b1c[static_cast<int32_t>(sVar3) * 0x44]);
                        DAT_00726a84 = DAT_00726a84 + 1;
                        DAT_0086c330 = 0;
                        iVar25 = FUN_00404910(1);
                        if (iVar25 < iVar20) {
                            iVar25 = FUN_00404910(1);
                            FUN_004f6090(
                                "You will discard @NUM tons of cargo if you abandon this ship.\n"
                                " Ooops, never mind.\n No problem.\n",
                                static_cast<uint32_t>(iVar20 - iVar25));
                            FUN_004879f0(0x28, 0);
                        }
                        else {
                            FUN_004f6090(
                                "Are you sure you want to abandon this @SHIPTYPE?\n"
                                " Ooops, never mind.\n Yes, abandon it.\n",
                                static_cast<uint32_t>(sVar3));
                            FUN_004879f0(0x20, 0);
                        }
                        iVar20 = FUN_00430190(static_cast<uint32_t>(DAT_0085a26c / 2),
                                              static_cast<uint32_t>(DAT_0085a268 / 3 | 1),
                                              "snapall", 0, 0xffffffff, 0, 0, 0xffffffff, 0, 0);
                        if (iVar20 != 1) {
                            uStack_e0 = 0xffffffff;
                        }
                        DAT_00726a84 = DAT_00726a84 + -1;
                        DAT_007263bc = DAT_007268f4[DAT_00726a84];
                        if (uStack_e0 != 0xffffffff) {
                            iStack_d0 = iStack_d0 + -1;
                            FUN_004b1940();
                            aiStack_6c[iStack_d0 * 3 + 3] = 0;
                            FUN_004b1940();
                            aiStack_6c[iStack_d0 * 3 + 4] = 0;
                            FUN_004b1940();
                            aiStack_6c[iStack_d0 * 3 + 5] = 0;
                            FUN_00404ca0();
                        }
                    }
                    else {
                        if (DAT_008cac40 != nullptr) {
                            void** vtbl = reinterpret_cast<void**>(static_cast<uintptr_t>(
                                static_cast<uint32_t>(*DAT_008ea08c)));
                            reinterpret_cast<void (*)()>(vtbl[0x58 / 4])();
                            reinterpret_cast<void (*)()>(vtbl[0x5c / 4])();
                            if (*piVar21 != 0) {
                                FUN_005045a0(static_cast<uint32_t>(*piVar21),
                                             static_cast<uint32_t>(local_b0),
                                             static_cast<uint32_t>(local_b4));
                            }
                        }
                        piVar21 = DAT_008cac40;
                        DAT_008cac40 = nullptr;
                        FUN_00471120();
                        DAT_008cac40 = piVar21;
                    }
                    FUN_0045bbf0(1);
                }
            }
        }
        else if (iVar20 == 0x126) {
            if (iStack_d8 != 0) {
                iStack_d8 = iStack_d8 + -1;
                FUN_004889c0(&DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000,
                             0xffffffff);
            }
        }
        else {
            if (iVar20 != 0x128) goto LAB_0043f993;
            if (iStack_d8 < iStack_d0 + -1) {
                FUN_0042e730();
                iStack_d8 = iStack_d8 + 1;
            }
        }
    LAB_0043fca8:
        FUN_004d1130(1);
        if (bVar4) {
            iVar17 = 0x10;
            do {
                FUN_004b1940();
                FUN_004b1940();
                FUN_004b1940();
                iVar17 = iVar17 + 3;
            } while (iVar17 < 0x28);
            if (puStack_b8 != nullptr) {
                piVar21 = reinterpret_cast<int32_t*>(puStack_b8 + 1);
                *piVar21 = *piVar21 + -1;
                if (*piVar21 == 0) {
                    reinterpret_cast<void (*)(int32_t)>(
                        static_cast<uintptr_t>(*puStack_b8))(1);
                }
            }
            piVar21 = aiStack_6c + 1;
            iVar17 = 8;
            do {
                puVar15 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(
                    static_cast<uint32_t>(piVar21[-1])));
                piVar21 = piVar21 + -1;
                if (puVar15 != nullptr) {
                    piVar1 = reinterpret_cast<int32_t*>(puVar15 + 1);
                    *piVar1 = *piVar1 + -1;
                    if (*piVar1 == 0) {
                        reinterpret_cast<void (*)(int32_t)>(
                            static_cast<uintptr_t>(*puVar15))(1);
                    }
                }
                iVar17 = iVar17 + -1;
            } while (iVar17 != 0);
            ppuVar22 = local_ac + 9;
            iVar17 = 9;
            do {
                puVar15 = ppuVar22[-1];
                ppuVar22 = ppuVar22 + -1;
                if (puVar15 != nullptr) {
                    piVar21 = reinterpret_cast<int32_t*>(puVar15 + 1);
                    *piVar21 = *piVar21 + -1;
                    if (*piVar21 == 0) {
                        reinterpret_cast<void (*)(int32_t)>(
                            static_cast<uintptr_t>(*puVar15))(1);
                    }
                }
                iVar17 = iVar17 + -1;
            } while (iVar17 != 0);
            return;
        }
    } while (true);
}


// ===== 0x43ffc0 (delegated part, unified declarations) =====
extern void FUN_0040a610(void);
extern void FUN_00419ac0(void);
extern void FUN_0041a300(uint8_t **out, int a, int b, int c);
extern void FUN_0041a9f0(int a, void *out);
extern void FUN_00425ad0(const char *a, void *b, int c, int d, void *e, void *f,
                         void *g, void *h, void *i);
extern void FUN_00427f80(void *a);
extern void FUN_00428140(void);
extern int FUN_0043fd70(void);
extern void FUN_0044f150(int a, int b);
extern void FUN_0044fa40(int a);
extern void FUN_00451e50(int a, uint32_t b, int c);
extern void FUN_00452890(void);
extern void FUN_00456b20(void);
extern void FUN_00457100(void);
extern void FUN_00481180(void);
extern void FUN_00482e60(int a, int b);
extern void FUN_00483b70(void);
extern void FUN_00483ca0(void);
extern void FUN_004841b0(void);
extern void FUN_00484bd0(void);
extern void FUN_00487e90(void);
extern void FUN_00487fd0(int a, int b);
extern void FUN_00488d90(uint32_t a, int b, int c, int d, uint32_t e, uint32_t f,
                         uint32_t g, int h, int i);
extern void FUN_00488df0(uint32_t a, int b, uint32_t c, int d, uint32_t e,
                         uint32_t f, uint32_t g, int h, int i);
extern void FUN_00488ed0(uint32_t a);
extern void FUN_00489130(void *a);
extern void FUN_00489360(int a, int b, int c, int d, int e);
extern void FUN_0049aed0(int a, uint32_t b);
extern void FUN_0049af70(int a, int b);
extern int FUN_004a0b70(uint32_t a);
extern void FUN_004a0d90(void);
extern void FUN_004a22f0(int a, int b, int c);
extern void FUN_004a24b0(void);
extern void FUN_004a29c0(void);
extern void FUN_004a78a0(int a);
extern void FUN_004a7a40(int a);
extern uintptr_t FUN_004baa30(int a, const char *b, int c, int d, int e, int f,
                              uint32_t g, int h, int i, int j, int k);
extern void FUN_004c08b0(uint32_t a);
extern void FUN_004c0940(void);
extern void FUN_004c1080(void *a, const char *b, int c, uint32_t d);
extern void FUN_004c1150(void *a, const char *b);
extern void FUN_004d96a0(const char *a, uint32_t b);
extern void FUN_004d9af0(int a, uint32_t b);
extern void FUN_004e4580(uint32_t a);
extern void FUN_00535920(int a);
extern void FUN_005be280(const char *a, int b, void *c);
extern uint8_t *DAT_008e8edc;
extern uint8_t *DAT_008e8ee0;
extern uint32_t DAT_00869a74;
extern int DAT_00862014[];
extern int DAT_00860b70[];
extern int DAT_0085bf90[];
extern uint32_t PTR_DAT_007270ac[];
extern uint32_t DAT_008cacd4;
extern void **_DAT_008cacd0;
extern char DAT_008cac26;
extern int DAT_00726638;
extern int DAT_0072663c;
extern void *PTR_DAT_00726640;
extern int DAT_008c9568;
extern int DAT_007261dc;
extern int16_t DAT_00869a98[];
extern int DAT_007261e0;
extern int DAT_007261e4;
extern int DAT_008cb10c[];
extern int DAT_008cb110[];
extern int DAT_008cb114[];
extern uint8_t DAT_008d4718[];
extern uint8_t DAT_008cdc98[];
extern uint8_t DAT_008d4058[];
extern uint8_t DAT_008d5798[];
extern uint8_t DAT_008d4358[];
extern uint8_t DAT_008d5258[];
extern uint8_t DAT_0085bf70[];
extern uint8_t DAT_008cea18[];
extern uint8_t DAT_008d56d8[];
extern char DAT_008c827f;
extern char DAT_008c827e;
extern uint8_t DAT_008c8288[];
extern int DAT_008cb190;
extern int DAT_008cb194;
extern int DAT_008cb198;
extern uint8_t DAT_008c7340[];
extern char DAT_006f5896[];
extern char DAT_008bea80[];
extern uint32_t _DAT_008be9f4;
extern int DAT_008e8ec4;
extern int _DAT_008e8ec8;
extern int *DAT_008ed2c8;
extern int DAT_008e8eec;
extern int DAT_008e8ef0;
extern int DAT_008c9dec;
extern int DAT_007255f8;
extern int DAT_008e9fec;
extern int DAT_008e9fe8;
extern int DAT_0072cb4c;
extern int DAT_0072ccc4;
extern int DAT_0072cb44;
extern char DAT_00725d98;
extern char DAT_00726814[];
extern int DAT_00726820;
extern int DAT_008c97c0;
extern int DAT_008c97c4;
extern uint8_t DAT_00861ffc[];
extern int DAT_008c8200;
extern int DAT_0086c360;

// 0x0043ffc0 — observed shape
void FUN_0043ffc0(void)
{
    int *piVar1;
    int16_t *psVar2;
    int iVar3;
    uint8_t uVar4;
    uint32_t *puVar5;
    bool bVar6;
    char cVar7;
    int16_t sVar8;
    int iVar9;
    int *piVar10;
    uint8_t *pbVar11;
    uint32_t *puVar12;
    uint32_t *puVar13;
    uint32_t uVar14;
    uint32_t uVar15;
    uint32_t uVar16;
    int iVar17;
    DWORD DVar18;
    int iVar19;
    int16_t sVar20;
    int16_t sVar21;
    int16_t *psVar22;
    uint32_t unaff_EBX = 0; // NEEDS_MANUAL: incoming EBX is not modelled by the listing
    uint32_t uVar23;
    int iVar24;
    int iVar25;
    uint32_t **ppuVar26;
    bool bVar27;
    bool bVar28;
    uint32_t uVar29;
    uint32_t uVar30;
    char *pcVar31;
    uint8_t *puStack_348;
    uint32_t *puStack_344 = NULL;
    uint32_t *puStack_340 = NULL;
    uint32_t *puStack_33c = NULL;
    uint8_t *pbStack_338;
    int local_330;
    uint8_t auStack_32c[3];
    uint8_t local_329;
    int iStack_328 = 0;
    uint32_t *local_324;
    uint32_t *local_320 = NULL;
    uint32_t *puStack_31c = NULL;
    uint32_t *apuStack_318[3] = { NULL, NULL, NULL };
    int aiStack_30c[3];
    uint32_t *apuStack_300[6];
    int aiStack_2e8[3];
    uint8_t *puStack_2dc = &DAT_008cacd0;
    uint8_t *puStack_2d8 = &DAT_008cacd0;
    int local_2d4;
    uint8_t *puStack_2d0 = &DAT_008cacd0; // NEEDS_MANUAL: temp string pointer, Ghidra leaves it uninitialised
    uint32_t local_2cc;
    int local_2c8;
    int local_2c4;
    int local_2c0;
    int local_2bc;
    int local_2b8;
    uint32_t local_2b4;
    uint32_t uStack_2b0;
    uint32_t uStack_2ac;
    int aiStack_2a8[21];
    uint8_t *puStack_254;
    uint8_t *puStack_250;
    uint8_t *puStack_24c;
    uint32_t uStack_248;
    uint8_t auStack_23c[8];
    uint32_t uStack_234;
    int iStack_230;
    uint8_t *puStack_22c;
    uint8_t *puStack_228;
    uint8_t *puStack_224;
    uint32_t uStack_220;
    uint32_t local_204[24];
    uint8_t *local_1a4;
    uint8_t auStack_184[128];
    uint8_t auStack_104[128];
    uint8_t auStack_84[132];

    local_324 = NULL;
    bVar6 = false;
    local_2bc = -1;
    if ((DAT_008e8edc == NULL) ||
        ((static_cast<uint32_t>(DAT_008e8ee0 - DAT_008e8edc) >> 2) == 0)) {
        iVar9 = -1;
    }
    else {
        iVar9 = *reinterpret_cast<int *>(DAT_008e8ee0 - 4);
    }
    bVar27 = iVar9 != 3;
    local_329 = static_cast<uint8_t>(_DAT_0085a164 >> 2) & 1;
    _DAT_0085a164 = _DAT_0085a164 & 0xfffffffb;
    if (bVar27) {
        FUN_004a7a40(1);
        local_2cc = 7;
        local_2b4 = 9;
    }
    else {
        FUN_00488ed0(0);
        FUN_004a29c0();
        local_2cc = 0x5f;
        local_2b4 = 0x60;
        local_1a4 = &DAT_008cacd0;
        local_204[0] = 0x32;
        FUN_004985e0();
        FUN_004a14b0();
    }
    iVar9 = static_cast<int>(DAT_00869a74) / 2;
    iVar19 = 0;
    if (-1 < iVar9) {
        do {
            iVar19 = iVar19 + 1;
            iVar9 = iVar9 + (-1 << (static_cast<uint8_t>(iVar19) & 0x1f));
        } while (iVar19 <= iVar9);
    }
    local_2b8 = 0;
    piVar10 = &DAT_00862014[0];
    do {
        if (*piVar10 == 0) {
            local_2b8 = local_2b8 + 1;
        }
        piVar10 = piVar10 + 7;
    } while (reinterpret_cast<intptr_t>(piVar10) < 0x862110);
    local_2c0 = 0;
    pbVar11 = &DAT_00862018[0];
    do {
        if ((*pbVar11 & 1) != 0) {
            local_2c0 = local_2c0 + 1;
        }
        pbVar11 = pbVar11 + 0x1c;
    } while (reinterpret_cast<intptr_t>(pbVar11) < 0x862114);
    local_2c4 = 0;
    local_330 = -1;
    iVar9 = 0;
    psVar22 = &DAT_0085bf78[0];
    piVar10 = &DAT_00860b70[0];
    do {
        if ((*psVar22 != 0) && (-1 < *piVar10)) {
            iVar19 = static_cast<int>(*psVar22);
            if (local_2c4 <
                static_cast<int>((*reinterpret_cast<uint32_t *>(psVar22 + -2) & 3) + iVar19)) {
                if (iVar19 < 0) {
                    iVar19 = 0;
                }
                else if (8 < iVar19) {
                    iVar19 = 8;
                }
                local_2c4 = static_cast<int>(*reinterpret_cast<uint32_t *>(psVar22 + -2) & 3) + iVar19;
                local_330 = iVar9;
            }
        }
        piVar10 = piVar10 + 8;
        iVar9 = iVar9 + 1;
        psVar22 = psVar22 + 0x4a;
    } while (reinterpret_cast<intptr_t>(piVar10) < 0x8610f0);
    iVar9 = 0;
    local_2c8 = 0;
    aiStack_2e8[1] = 0;
    if ((_DAT_0085a164 & 0x80000) == 0) {
        if (DAT_0085a648 != 0) {
            iVar19 = 0;
            do {
                if ((((DAT_0085a758 & 0x80000000) == 0) && (0 < DAT_0085a648)) &&
                    ((DAT_0085a758 & 0x100 << (static_cast<uint8_t>(iVar19) & 0x1f)) == 0)) {
                    iVar9 = iVar9 + 2;
                }
                iVar19 = iVar19 + 1;
            } while (iVar19 < 4);
            aiStack_2e8[1] = iVar9;
        }
    }
    else {
        aiStack_2e8[1] = 10;
    }
    iVar9 = 0;
    aiStack_2e8[2] = 0;
    do {
        if ((((DAT_0085a4c8 & 0x80000000) == 0) && (0 < DAT_0085a3b8)) &&
            ((DAT_0085a4c8 & 0x100 << (static_cast<uint8_t>(iVar9) & 0x1f)) == 0)) {
            aiStack_2e8[2] = aiStack_2e8[2] + 1;
        }
        if ((((DAT_0085a610 & 0x80000000) == 0) && (0 < DAT_0085a500)) &&
            ((DAT_0085a610 & 0x100 << (static_cast<uint8_t>(iVar9) & 0x1f)) == 0)) {
            local_2c8 = local_2c8 + 1;
        }
        iVar9 = iVar9 + 1;
    } while (iVar9 < 4);
    aiStack_2a8[5] = 0;
    local_2d4 = 0;
    piVar10 = &DAT_0085bf90[0];
    do {
        aiStack_2a8[5] = aiStack_2a8[5] + *piVar10;
        iVar24 = 0;
        iVar19 = 1;
        iVar9 = 1000;
        do {
            iVar24 = iVar24 + iVar9;
            if (iVar24 <= aiStack_2a8[5] * 500 + DAT_00869b14) {
                local_2d4 = iVar19;
            }
            iVar9 = iVar9 + 1000;
            iVar19 = iVar19 + 1;
        } while (iVar9 < 25000);
        piVar10 = piVar10 + 0x25;
    } while (reinterpret_cast<intptr_t>(piVar10) < 0x85d900);
    aiStack_2a8[10] = FUN_0043fd70();
    aiStack_2a8[1] = 0;
    aiStack_2a8[2] = 0;
    aiStack_2a8[3] = 0;
    aiStack_2a8[4] = 0;
    iVar9 = 0;
    do {
        local_320 = reinterpret_cast<uint32_t *>(&DAT_008cacd0);
        FUN_004f2600("smallMap_%s.dds",
                     *reinterpret_cast<uint32_t *>(reinterpret_cast<uint8_t *>(PTR_DAT_007270ac) + iVar9));
        puVar12 = reinterpret_cast<uint32_t *>(FUN_00533c78(0xc0));
        puVar13 = local_320;
        uVar14 = DAT_008ea008;
        if (puVar12 == NULL) {
            puVar12 = NULL;
        }
        else {
            puVar12[1] = 0;
            *reinterpret_cast<void **>(puVar12) = &PTR_FUN_006fd14c;
            puVar12[7] = 0;
            DAT_00727444 = DAT_00727444 + 1;
            puVar12[0x19] = 0;
            puVar12[0x2f] = 0;
            FUN_004bdca0(uVar14, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
        }
        puVar5 = *reinterpret_cast<uint32_t **>(reinterpret_cast<uint8_t *>(aiStack_2a8) + iVar9 + 4);
        if (puVar5 != puVar12) {
            if (puVar5 != NULL) {
                piVar10 = reinterpret_cast<int *>(puVar5 + 1);
                *piVar10 = *piVar10 + -1;
                if (*piVar10 == 0) {
                    reinterpret_cast<void (*)(int)>(*reinterpret_cast<void **>(puVar5))(1);
                }
            }
            *reinterpret_cast<uint32_t **>(reinterpret_cast<uint8_t *>(aiStack_2a8) + iVar9 + 4) = puVar12;
            if (puVar12 != NULL) {
                puVar12[1] = puVar12[1] + 1;
            }
        }
        puVar13 = reinterpret_cast<uint32_t *>(reinterpret_cast<uint8_t *>(puVar13) - 8);
        if ((puVar13 != NULL) && (puVar13 != reinterpret_cast<uint32_t *>(&DAT_008cacc8))) {
            operator_delete__(puVar13);
        }
        iVar9 = iVar9 + 4;
    } while (iVar9 < 0x10);
    local_320 = NULL;
    if (local_330 != -1) {
        puVar13 = reinterpret_cast<uint32_t *>(FUN_00533c78(0xc0));
        if (puVar13 != NULL) {
            local_324 = reinterpret_cast<uint32_t *>(0x1);
            FUN_00457100();
            uVar14 = DAT_008ea008;
            puVar13[1] = 0;
            *reinterpret_cast<void **>(puVar13) = &PTR_FUN_006fd14c;
            puVar13[7] = 0;
            DAT_00727444 = DAT_00727444 + 1;
            puVar13[0x19] = 0;
            puVar13[0x2f] = 0;
            FUN_004bdca0(uVar14, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
            puVar13[1] = puVar13[1] + 1;
            local_320 = puVar13;
        }
        if ((reinterpret_cast<uintptr_t>(local_324) & 1) != 0) {
            puVar13 = reinterpret_cast<uint32_t *>(puStack_2d0 - 8);
            if ((puVar13 != NULL) && (puVar13 != reinterpret_cast<uint32_t *>(&DAT_008cacc8))) {
                operator_delete__(puVar13);
            }
            puStack_2d0 = &DAT_008cacd0;
        }
    }
    aiStack_2a8[0xb] = 0;
    aiStack_2a8[0xc] = 0;
    aiStack_2a8[0xd] = 0;
    aiStack_2a8[0xe] = 0;
    aiStack_2a8[0xf] = 0;
    aiStack_2a8[0x10] = 0;
    aiStack_2a8[0x11] = 0;
    aiStack_2a8[0x12] = 0;
    aiStack_2a8[0x13] = 0;
    aiStack_2a8[0x14] = 0;
    iVar9 = 0;
    do {
        puVar12 = reinterpret_cast<uint32_t *>(FUN_00456b20());
        puVar13 = reinterpret_cast<uint32_t *>(aiStack_2a8[iVar9 + 0xb]);
        if (puVar13 != puVar12) {
            if (puVar13 != NULL) {
                piVar10 = reinterpret_cast<int *>(puVar13 + 1);
                *piVar10 = *piVar10 + -1;
                if (*piVar10 == 0) {
                    reinterpret_cast<void (*)(int)>(*reinterpret_cast<void **>(puVar13))(1);
                }
            }
            aiStack_2a8[iVar9 + 0xb] = static_cast<int>(reinterpret_cast<intptr_t>(puVar12));
            if (puVar12 != NULL) {
                puVar12[1] = puVar12[1] + 1;
            }
        }
        iVar9 = iVar9 + 1;
    } while (iVar9 < 10);
    puVar13 = reinterpret_cast<uint32_t *>(FUN_00533c78(0xc0));
    uVar14 = DAT_008ea008;
    if (puVar13 == NULL) {
        puVar13 = NULL;
    }
    else {
        puVar13[1] = 0;
        *reinterpret_cast<void **>(puVar13) = &PTR_FUN_006fd14c;
        puVar13[7] = 0;
        puVar13[0x19] = 0;
        DAT_00727444 = DAT_00727444 + 1;
        puVar13[0x2f] = 0;
        FUN_004bdca0(uVar14, 0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0);
    }
    local_324 = puVar13;
    if (puVar13 != NULL) {
        puVar13[1] = puVar13[1] + 1;
    }
    do {
        if (DAT_008cac27 != '\0')
            break;
        DAT_0086c330 = 0;
        FUN_004b24a0(DAT_008cabe8, 0);
        FUN_004f6090("The Illustrious Captain @PCNAME", DAT_00726638, DAT_0072663c,
                     PTR_DAT_00726640);
        FUN_00487fd0(DAT_0085a26c / 2 + 0x28, DAT_008c9568);
        DAT_0085a11c = 100;
        FUN_004b06c0(&DAT_00869b48, DAT_007261dc + -0x20, DAT_007261ec + -0x1e, 100,
                     0xffffffff, 1, 0xffffffff, 0);
        iVar9 = aiStack_2a8[10];
        FUN_004f6090("Achievement Points: @NUM", aiStack_2a8[10]);
        FUN_00487fd0(((DAT_0085a26c + ((DAT_0085a26c >> 0x1f) & 3)) >> 2) + 0x32,
                     DAT_008c9568);
        DAT_0085a11c = 100;
        FUN_004b06c0(&DAT_00869b48, DAT_0085a26c + -0x20, DAT_007261ec + -0x1e, 100,
                     0xffffffff, 2, 0xffffffff, 0);
        if (1 < iVar9) {
            FUN_004f6090("(click an icon to relive your adventures)");
            FUN_004b06c0(&DAT_00869b48, DAT_0085a26c / 2, DAT_007261ec + -0x20, 0x32,
                         0xffffffff, 4, 0xffffffff, 0);
        }
        FUN_004f6090("Wealth: @NUM gold", DAT_00869b14);
        FUN_004b06c0(&DAT_00869b48, DAT_007261dc + -0x20, DAT_007261ec + 0x20, 0x37,
                     0xffffffff, 1, 0xffffffff, 0);
        FUN_004f6090("Land: @NUM acres", aiStack_2a8[5] * 0x32);
        FUN_004b06c0(&DAT_00869b48, DAT_007261dc + -0x20, DAT_007261ec + 0x30, 0x37,
                     0xffffffff, 1, 0xffffffff, 0);
        FUN_004f6090("Wealth Points: (@NUM/@NUM)", local_2d4, 0x18);
        FUN_004b06c0(&DAT_00869b48, DAT_007261dc + -0x20, DAT_007261ec + 8, 0x4b,
                     0xffffffff, 1, 0xffffffff, 0);
        iVar9 = DAT_0085a268 / 9;
        puStack_340 = NULL;
        puStack_344 = reinterpret_cast<uint32_t *>(DAT_007261ec + 0x66);
        pbStack_338 = &DAT_00869a88[0];
        do {
            iVar19 = *pbStack_338 - 1;
            if (iVar19 < 1) {
                FUN_004f6090("@NATIONALITY: No Rank (@NUM/@NUM)", puStack_340, 0, 8);
            }
            else {
                FUN_004f6090("@NATIONALITY: @RANK (@NUM/@NUM)", puStack_340,
                             static_cast<uint32_t>(*pbStack_338), iVar19);
            }
            FUN_004b06c0(&DAT_00869b48, DAT_007261dc + -0x20,
                         static_cast<int>(reinterpret_cast<intptr_t>(puStack_344)) - 0x10,
                         0x4b, 0xffffffff, 1, 0xffffffff, 0);
            if (*pbStack_338 == 0) {
                if (*reinterpret_cast<int16_t *>(pbStack_338 - 0x10) < 0) {
                    FUN_004f6090("@NUM,000 gold reward ",
                                 -static_cast<int>(*reinterpret_cast<int16_t *>(pbStack_338 - 0x10)));
                    iVar19 = 0;
                    while (true) {
                        iVar24 = static_cast<int>(
                            (3 - *reinterpret_cast<int16_t *>(pbStack_338 - 0x10)) +
                            ((3 - *reinterpret_cast<int16_t *>(pbStack_338 - 0x10)) >> 0x1f & 3)) >> 2;
                        if (0xe < iVar24) {
                            iVar24 = 0xe;
                        }
                        if (iVar24 <= iVar19)
                            break;
                        uVar30 = 0;
                        uVar29 = 0x420c0000;
                        uVar14 = FUN_005f0ddc(0x420c0000, 0);
                        uVar15 = FUN_005f0ddc(uVar14);
                        FUN_004bba60(&DAT_008cdc98, uVar15, uVar14, uVar29, uVar30);
                        iVar19 = iVar19 + 1;
                    }
                }
                else {
                    FUN_004f6090("No Rank");
                    puVar13 = local_324;
                    if (local_324 != NULL) {
                        uVar30 = 0;
                        uVar29 = 0x42340000;
                        uVar14 = FUN_005f0ddc(0x42340000, 0);
                        uVar15 = FUN_005f0ddc(uVar14);
                        // shared tail of the listing's LAB_004408d1
                        FUN_004bba60(puVar13, uVar15, uVar14, uVar29, uVar30);
                    }
                }
            }
            else if (*pbStack_338 == 1) {
                FUN_004f6090("Letter of Marque");
                uVar30 = 0;
                uVar29 = 0x420c0000;
                uVar14 = FUN_005f0ddc(0x420c0000, 0);
                uVar15 = FUN_005f0ddc(uVar14);
                FUN_004bba60(reinterpret_cast<uint32_t *>(&DAT_008d4058), uVar15, uVar14,
                             uVar29, uVar30);
            }
            else {
                if (*reinterpret_cast<int16_t *>(pbStack_338 - 0x10) < 0) {
                    FUN_004f6090("@NUM,000 gold reward ",
                                 -static_cast<int>(*reinterpret_cast<int16_t *>(pbStack_338 - 0x10)));
                    FUN_004b06c0(&DAT_00869b48, DAT_007261dc + -0x20,
                                 static_cast<int>(reinterpret_cast<intptr_t>(puStack_344)), 0x37,
                                 0xffffffff, 1, 0xffffffff, 0);
                }
                DAT_00869b48 = 0;
                iVar19 = 2;
                puStack_348 = reinterpret_cast<uint8_t *>(0x2e);
                while (true) {
                    if (*pbStack_338 < 10) {
                        uVar23 = static_cast<uint32_t>(*pbStack_338);
                    }
                    else {
                        uVar23 = 9;
                    }
                    if (static_cast<int>(uVar23) < iVar19)
                        break;
                    iVar25 = aiStack_2a8[iVar19 + 0xb];
                    iVar24 = static_cast<int>(reinterpret_cast<intptr_t>(puStack_348)) - 0x4e + DAT_007261dc;
                    iStack_328 = iVar24;
                    if (iVar25 != 0) {
                        uVar30 = 0;
                        uVar29 = 0x420c0000;
                        uVar14 = FUN_005f0ddc(0x420c0000, 0);
                        uVar15 = FUN_005f0ddc(uVar14);
                        FUN_004bba60(reinterpret_cast<uint32_t *>(iVar25), uVar15, uVar14,
                                     uVar29, uVar30);
                    }
                    iVar25 = DAT_0086c330;
                    (&DAT_0086c010)[iVar25] = static_cast<int16_t>(iVar24);
                    (&DAT_0086be80)[iVar25] =
                        static_cast<int16_t>(pirates_lo16(reinterpret_cast<intptr_t>(puStack_344)) + 0xc);
                    (&DAT_0086bcf0)[iVar25] = static_cast<int16_t>(iVar24) + 0x18;
                    (&DAT_0086bb60)[iVar25] =
                        static_cast<int16_t>(pirates_lo16(reinterpret_cast<intptr_t>(puStack_344)) + 0x24);
                    (&DAT_0086c1a0)[iVar25] =
                        static_cast<int16_t>(pirates_lo16(reinterpret_cast<intptr_t>(puStack_340)) * -10 +
                                             199 - static_cast<int16_t>(iVar19));
                    DAT_0086c330 = DAT_0086c330 + 1;
                    iVar19 = iVar19 + 1;
                    puStack_348 = puStack_348 + 0x17;
                }
            }
            FUN_004b06c0(&DAT_00869b48, DAT_007261dc + -0x20,
                         static_cast<int>(reinterpret_cast<intptr_t>(puStack_344)) + 0x16, 0x33,
                         0xffffffff, 1, 0xffffffff, 0);
            pbStack_338 = pbStack_338 + 2;
            puStack_340 = reinterpret_cast<uint32_t *>(reinterpret_cast<intptr_t>(puStack_340) + 1);
            puStack_344 = reinterpret_cast<uint32_t *>(reinterpret_cast<intptr_t>(puStack_344) +
                                                       iVar9 + 5);
        } while (reinterpret_cast<intptr_t>(pbStack_338) < 0x869a8f);
        FUN_004f6090("Pirates Defeated: (@NUM/@NUM)", local_2b8, 9);
        FUN_004b06c0(&DAT_00869b48, DAT_007261e0 + -0x10, DAT_007261ec + 8, 0x4b,
                     0xffffffff, 1, 0xffffffff, 0);
        uVar23 = 0;
        puStack_344 = reinterpret_cast<uint32_t *>(&DAT_008cb10c);
        puStack_348 = &DAT_008d4718[0];
        pbStack_338 = reinterpret_cast<uint8_t *>(&DAT_00862014);
        do {
            if (*reinterpret_cast<int *>(pbStack_338) == 0) {
                uVar16 = uVar23 & 0x80000001;
                if (static_cast<int>(uVar16) < 0) {
                    uVar16 = (uVar16 - 1 | 0xfffffffe) + 1;
                }
                iVar9 = static_cast<int>(uVar16 * 0x60) + -0x10 + DAT_007261e0;
                iVar19 = DAT_007261ec + 0x16 + (static_cast<int>(uVar23) / 2) * 0x18;
                if (puStack_348 != NULL) {
                    uVar30 = 0;
                    uVar29 = 0x425c0000;
                    uVar14 = FUN_005f0ddc(0x425c0000, 0);
                    uVar15 = FUN_005f0ddc(uVar14);
                    FUN_004bba60(puStack_348, uVar15, uVar14, uVar29, uVar30);
                }
                FUN_004f6090("@TOP10", puStack_344[0], puStack_344[1], puStack_344[2]);
                DAT_0085a11c = 0x33;
                FUN_004b06c0(&DAT_00869b48, iVar9 + 0x1c, iVar19 + 10, 0x33, 0xffffffff, 1,
                             0xffffffff, 0);
                DAT_0085a11c = 0x33;
                DAT_008c9de0 = DAT_008c9dd8;
                FUN_00509500(DAT_008c9dd8, &DAT_00869b48, 0);
                sVar8 = static_cast<int16_t>(FUN_005f0ddc());
                iVar24 = DAT_0086c330;
                sVar20 = static_cast<int16_t>(iVar19);
                (&DAT_0086be80)[iVar24] = sVar20 + 4;
                sVar21 = static_cast<int16_t>(iVar9);
                DAT_0086c330 = DAT_0086c330 + 1;
                (&DAT_0086bcf0)[iVar24] = sVar21 + 0x1c + sVar8;
                (&DAT_0086c1a0)[iVar24] = static_cast<int16_t>(uVar23) + 9;
                (&DAT_0086c010)[iVar24] = sVar21;
                (&DAT_0086bb60)[iVar24] = sVar20 + 0x16;
                uVar23 = uVar23 + 1;
            }
            pbStack_338 = pbStack_338 + 0x1c;
            puStack_348 = puStack_348 + 0xc0;
            puStack_344 = puStack_344 + 3;
        } while (reinterpret_cast<intptr_t>(pbStack_338) < 0x862110);
        FUN_004f6090("Treasure Found: (@NUM/@NUM)", local_2c0, 9);
        FUN_004b06c0(&DAT_00869b48, DAT_007261e0 + -0x10, DAT_0085a268 / 3 + DAT_007261ec,
                     0x4b, 0xffffffff, 1, 0xffffffff, 0);
        uVar23 = 0;
        puStack_344 = reinterpret_cast<uint32_t *>(&DAT_008cb10c);
        puStack_348 = &DAT_008d5798[0];
        pbStack_338 = &DAT_00862018[0];
        do {
            if ((*pbStack_338 & 1) != 0) {
                uVar16 = uVar23 & 0x80000001;
                if (static_cast<int>(uVar16) < 0) {
                    uVar16 = (uVar16 - 1 | 0xfffffffe) + 1;
                }
                iVar19 = static_cast<int>(uVar16 * 0x60) + -6 + DAT_007261e0;
                iVar9 = DAT_0085a268 / 3 + DAT_007261ec +
                        (static_cast<int>(uVar23) / 2 + 1) * 0x18;
                if (puStack_348 != NULL) {
                    uVar30 = 0;
                    uVar29 = 0x425c0000;
                    uVar14 = FUN_005f0ddc(0x425c0000, 0);
                    uVar15 = FUN_005f0ddc(uVar14);
                    FUN_004bba60(puStack_348, uVar15, uVar14, uVar29, uVar30);
                }
                FUN_004f6090("@TOP10", puStack_344[0], puStack_344[1], puStack_344[2]);
                DAT_0085a11c = 0x33;
                FUN_004b06c0(&DAT_00869b48, iVar19 + 0x12, iVar9 + 2, 0x33, 0xffffffff, 1,
                             0xffffffff, 0);
                DAT_0085a11c = 0x33;
                DAT_008c9de0 = DAT_008c9dd8;
                FUN_00509500(DAT_008c9dd8, &DAT_00869b48, 0);
                sVar8 = static_cast<int16_t>(FUN_005f0ddc());
                sVar21 = static_cast<int16_t>(iVar19);
                iVar19 = DAT_0086c330;
                sVar20 = static_cast<int16_t>(iVar9);
                (&DAT_0086be80)[iVar19] = sVar20 + -2;
                DAT_0086c330 = DAT_0086c330 + 1;
                (&DAT_0086bcf0)[iVar19] = sVar21 + 0x13 + sVar8;
                (&DAT_0086c1a0)[iVar19] = static_cast<int16_t>(uVar23) + 0x12;
                (&DAT_0086c010)[iVar19] = sVar21 + -2;
                (&DAT_0086bb60)[iVar19] = sVar20 + 0x10;
                uVar23 = uVar23 + 1;
            }
            pbStack_338 = pbStack_338 + 0x1c;
            puStack_348 = puStack_348 + 0xc0;
            puStack_344 = puStack_344 + 3;
        } while (reinterpret_cast<intptr_t>(pbStack_338) < 0x862114);
        FUN_004f6090("Lost Relatives Quest: (@NUM/@NUM)", aiStack_2e8[2] + DAT_00869b1c * 4, 0x10);
        iVar9 = DAT_007261e4;
        DAT_0085a11c = 0x4b;
        DAT_008c9de0 = DAT_008c9dd8;
        FUN_00509500(DAT_008c9dd8, &DAT_00869b48, 0);
        iVar19 = static_cast<int>(FUN_005f0ddc());
        if (DAT_0085a26c + -5 < iVar19 + 0x10 + iVar9) {
            DAT_008c9de0 = DAT_008c9dd8;
            FUN_00509500(DAT_008c9dd8, &DAT_00869b48, 0);
            iVar9 = DAT_007261ec;
            iVar19 = static_cast<int>(FUN_005f0ddc());
            iVar19 = (DAT_0085a26c - iVar19) + -10;
        }
        else {
            iVar19 = DAT_007261e4 + 0x10;
            iVar9 = DAT_007261ec;
        }
        FUN_004b06c0(&DAT_00869b48, iVar19, iVar9 + 8, 0x4b, 0xffffffff, 1, 0xffffffff, 0);
        iVar19 = 0;
        iVar9 = 0;
        puStack_344 = reinterpret_cast<uint32_t *>(&DAT_008d4358);
        sVar20 = DAT_00869b1c;
        while (true) {
            iVar24 = 3;
            if (sVar20 < 4) {
                iVar24 = static_cast<int>(sVar20);
            }
            if (iVar24 < iVar19)
                break;
            iVar24 = 0;
            do {
                if (((iVar19 < sVar20) ||
                     (((DAT_0085a4c8 & 0x100 << (static_cast<uint8_t>(iVar24) & 0x1f)) == 0 &&
                       (0 < DAT_0085a3b8)))) &&
                    ((iVar25 = aiStack_2a8[iVar24 + 1]) != 0)) {
                    uVar30 = 0;
                    uVar29 = 0x42820000;
                    uVar14 = FUN_005f0ddc(0x42820000, 0);
                    uVar15 = FUN_005f0ddc(uVar14);
                    FUN_004bba60(reinterpret_cast<uint32_t *>(iVar25), uVar15, uVar14, uVar29,
                                 uVar30);
                    sVar20 = DAT_00869b1c;
                }
                iVar25 = DAT_007261ec;
                iVar24 = iVar24 + 1;
            } while (iVar24 < 4);
            if (iVar19 < sVar20) {
                iVar24 = iVar9 + 0x22 + DAT_007261e4;
                FUN_004bba60(puStack_344, static_cast<uint32_t>(iVar24), DAT_007261ec + 0x2c,
                             0x425c0000, 0);
                FUN_004f6090("@RELATIVE", iVar19);
                FUN_004b06c0(&DAT_00869b48, iVar24, iVar25 + 0x3a, 0x32, 0xffffffff, 4,
                             0xffffffff, 0);
                iVar17 = DAT_0086c330;
                sVar21 = static_cast<int16_t>(iVar25);
                (&DAT_0086be80)[iVar17] = sVar21 + 0x1b;
                (&DAT_0086c010)[iVar17] = static_cast<int16_t>(iVar24) + -0x14;
                DAT_0086c330 = DAT_0086c330 + 1;
                (&DAT_0086c1a0)[iVar17] = static_cast<int16_t>(iVar19) + 5;
                sVar20 = DAT_00869b1c;
                (&DAT_0086bb60)[iVar17] = sVar21 + 0x47;
                (&DAT_0086bcf0)[iVar17] = static_cast<int16_t>(iVar24) + 0x14;
            }
            iVar19 = iVar19 + 1;
            iVar9 = iVar9 + 0x30;
            puStack_344 = puStack_344 + 0x30;
        }
        FUN_004f6090("Lost Cities Quest: (@NUM/@NUM)", local_2c8 + DAT_00869b1e * 4, 0x10);
        iVar9 = DAT_007261e4;
        DAT_0085a11c = 0x4b;
        DAT_008c9de0 = DAT_008c9dd8;
        FUN_00509500(DAT_008c9dd8, &DAT_00869b48, 0);
        iVar19 = static_cast<int>(FUN_005f0ddc());
        if (DAT_0085a26c + -5 < iVar19 + 0x10 + iVar9) {
            DAT_008c9de0 = DAT_008c9dd8;
            FUN_00509500(DAT_008c9dd8, &DAT_00869b48, 0);
            iVar9 = DAT_0085a268 / 7 + 8 + DAT_007261ec;
            iVar19 = static_cast<int>(FUN_005f0ddc());
            iVar19 = (DAT_0085a26c - iVar19) + -10;
        }
        else {
            iVar9 = DAT_0085a268 / 7 + 8 + DAT_007261ec;
            iVar19 = DAT_007261e4 + 0x10;
        }
        FUN_004b06c0(&DAT_00869b48, iVar19, iVar9, 0x4b, 0xffffffff, 1, 0xffffffff, 0);
        iVar19 = 0;
        iVar9 = 0;
        sVar20 = DAT_00869b1e;
        while (true) {
            iVar24 = 3;
            if (sVar20 < 4) {
                iVar24 = static_cast<int>(sVar20);
            }
            if (iVar24 < iVar19)
                break;
            iVar24 = 0;
            do {
                if (((iVar19 < sVar20) ||
                     (((DAT_0085a610 & 0x100 << (static_cast<uint8_t>(iVar24) & 0x1f)) == 0 &&
                       (0 < DAT_0085a500)))) &&
                    ((iVar25 = aiStack_2a8[iVar24 + 1]) != 0)) {
                    uVar30 = 0;
                    uVar29 = 0x42820000;
                    uVar14 = FUN_005f0ddc(0x42820000, 0);
                    uVar15 = FUN_005f0ddc(uVar14);
                    FUN_004bba60(reinterpret_cast<uint32_t *>(iVar25), uVar15, uVar14, uVar29,
                                 uVar30);
                    sVar20 = DAT_00869b1e;
                }
                iVar24 = iVar24 + 1;
            } while (iVar24 < 4);
            if (iVar19 < sVar20) {
                iVar24 = iVar9 + 0x22 + DAT_007261e4;
                iVar25 = DAT_0085a268 / 7 + 0x2c + DAT_007261ec;
                FUN_004bba60(&DAT_008d5258, static_cast<uint32_t>(iVar24),
                             static_cast<uint32_t>(iVar25), 0x425c0000, 0);
                FUN_004f6090("@LOSTCITY", iVar19);
                FUN_004b06c0(&DAT_00869b48, iVar24, iVar25 + 0xe, 0x32, 0xffffffff, 4,
                             0xffffffff, 0);
                iVar17 = DAT_0086c330;
                (&DAT_0086be80)[iVar17] = static_cast<int16_t>(iVar25) + -0x11;
                (&DAT_0086c010)[iVar17] = static_cast<int16_t>(iVar24) + -0x14;
                DAT_0086c330 = DAT_0086c330 + 1;
                (&DAT_0086c1a0)[iVar17] = static_cast<int16_t>(iVar19) + 0x1c;
                sVar20 = DAT_00869b1e;
                (&DAT_0086bb60)[iVar17] = static_cast<int16_t>(iVar25) + 0x1b;
                (&DAT_0086bcf0)[iVar17] = static_cast<int16_t>(iVar24) + 0x14;
            }
            iVar19 = iVar19 + 1;
            iVar9 = iVar9 + 0x30;
        }
        FUN_004f6090("Romance: (@NUM/@NUM)", local_2c4, 10);
        FUN_004b06c0(&DAT_00869b48, DAT_007261e4 + 0x10, (DAT_0085a268 * 2) / 7 + 8 + DAT_007261ec,
                     0x4b, 0xffffffff, 1, 0xffffffff, 0);
        puVar13 = local_320;
        iVar9 = DAT_007261e4;
        if (local_330 != -1) {
            sVar20 = static_cast<int16_t>((DAT_0085a268 * 2) / 7) +
                     static_cast<int16_t>(DAT_007261ec);
            if (local_320 != NULL) {
                uVar30 = 0;
                uVar29 = 0x42480000;
                uVar14 = FUN_005f0ddc(0x42480000, 0);
                uVar15 = FUN_005f0ddc(uVar14);
                FUN_004bba60(puVar13, uVar15, uVar14, uVar29, uVar30);
            }
            FUN_004f6090("City: @CITYNAME", (&DAT_008dbd08)[local_330 * 3],
                         (&DAT_008dbd0c)[local_330 * 3], (&DAT_008dbd10)[local_330 * 3]);
            FUN_004b06c0(&DAT_00869b48, DAT_007261e4 + 0x50,
                         (DAT_0085a268 * 2) / 7 + 0x20 + DAT_007261ec, 0x32, 0xffffffff, 1,
                         0xffffffff, 0);
            DAT_0085a11c = 0x32;
            DAT_008c9de0 = DAT_008c9dd8;
            FUN_00509500(DAT_008c9dd8, &DAT_00869b48, 0);
            iVar24 = static_cast<int>(FUN_005f0ddc());
            FUN_004f6090("Romance: ");
            DAT_0085a11c = 0x32;
            DAT_008c9de0 = DAT_008c9dd8;
            FUN_00509500(DAT_008c9dd8, &DAT_00869b48, 0);
            iVar19 = static_cast<int>(FUN_005f0ddc());
            FUN_004b06c0(&DAT_00869b48, DAT_007261e4 + 0x50,
                         (DAT_0085a268 * 2) / 7 + 0x2e + DAT_007261ec, 0x32, 0xffffffff, 1,
                         0xffffffff, 0);
            iVar25 = 0;
            if (0 < static_cast<int16_t>((&DAT_0085bf78)[local_330 * 0x4a])) {
                iVar17 = iVar19 + 0x58;
                do {
                    FUN_004bba60(&DAT_008cea18, static_cast<uint32_t>(DAT_007261e4 + iVar17),
                                 static_cast<uint32_t>((DAT_0085a268 * 2) / 7 + 0x34 + DAT_007261ec),
                                 0x41f00000, 0);
                    iVar25 = iVar25 + 1;
                    iVar17 = iVar17 + 8;
                } while (iVar25 < static_cast<int16_t>((&DAT_0085bf78)[local_330 * 0x4a]));
            }
            iVar19 = iVar19 +
                     static_cast<int16_t>((&DAT_0085bf78)[local_330 * 0x4a]) * 8;
            if (iVar24 < iVar19) {
                iVar24 = iVar19;
            }
            FUN_004f6090("Attractiveness: @BEAUTY", (&DAT_0085bf74)[local_330 * 0x25]);
            DAT_0085a11c = 0x32;
            FUN_004b06c0(&DAT_00869b48, DAT_007261e4 + 0x50,
                         (DAT_0085a268 * 2) / 7 + 0x3c + DAT_007261ec, 0x32, 0xffffffff, 1,
                         0xffffffff, 0);
            DAT_0085a11c = 0x32;
            DAT_008c9de0 = DAT_008c9dd8;
            FUN_00509500(DAT_008c9dd8, &DAT_00869b48, 0);
            iVar19 = static_cast<int>(FUN_005f0ddc());
            if (iVar24 < iVar19) {
                iVar24 = iVar19;
            }
            if (((_DAT_0085a164 & 0x200000) != 0) &&
                ((*(&DAT_0085bf70 + local_330 * 0x25) & 8) != 0)) {
                FUN_004f6090("(Married)");
                FUN_004b06c0(&DAT_00869b48, DAT_007261e4 + 0x50,
                             (DAT_0085a268 * 2) / 7 + 0x4a + DAT_007261ec, 0x32, 0xffffffff, 1,
                             0xffffffff, 0);
                DAT_0085a11c = 0x32;
                DAT_008c9de0 = DAT_008c9dd8;
                FUN_00509500(DAT_008c9dd8, &DAT_00869b48, 0);
                iVar19 = static_cast<int>(FUN_005f0ddc());
                if (iVar24 < iVar19) {
                    iVar24 = iVar19;
                }
            }
            iVar19 = DAT_0086c330;
            sVar21 = static_cast<int16_t>(iVar9) + 0x14;
            (&DAT_0086be80)[iVar19] = sVar20 + 0x1c;
            (&DAT_0086c010)[iVar19] = sVar21;
            DAT_0086c330 = DAT_0086c330 + 1;
            (&DAT_0086c1a0)[iVar19] = 0x1b;
            (&DAT_0086bcf0)[iVar19] = static_cast<int16_t>(iVar24) + 0x40 + sVar21;
            (&DAT_0086bb60)[iVar19] = sVar20 + 100;
        }
        FUN_004f6090("Villains Avenged: (@NUM/@NUM)", aiStack_2e8[1], 10);
        FUN_004b06c0(&DAT_00869b48, DAT_007261e4 + 0x10, DAT_0085a268 / 2 + 8 + DAT_007261ec,
                     0x4b, 0xffffffff, 1, 0xffffffff, 0);
        iVar24 = 0;
        iVar9 = DAT_007261ec;
        iVar19 = DAT_0085a268;
        do {
            if ((((_DAT_0085a164 & 0x80000) != 0) ||
                 ((0 < DAT_0085a648 &&
                   ((DAT_0085a758 & 0x100 << (static_cast<uint8_t>(iVar24) & 0x1f)) == 0)))) &&
                ((iVar25 = aiStack_2a8[iVar24 + 1]) != 0)) {
                uVar30 = 0;
                uVar29 = 0x42aa0000;
                uVar14 = FUN_005f0ddc(0x42aa0000, 0);
                uVar15 = FUN_005f0ddc(uVar14);
                FUN_004bba60(reinterpret_cast<uint32_t *>(iVar25), uVar15, uVar14, uVar29,
                             uVar30);
                iVar9 = DAT_007261ec;
                iVar19 = DAT_0085a268;
            }
            iVar25 = DAT_007261e4;
            iVar24 = iVar24 + 1;
        } while (iVar24 < 4);
        if ((_DAT_0085a164 & 0x80000) != 0) {
            sVar20 = static_cast<int16_t>(iVar19 / 2) + 0x1a + static_cast<int16_t>(iVar9);
            uVar30 = 0;
            uVar29 = 0x42960000;
            uVar14 = FUN_005f0ddc(0x42960000, 0);
            uVar15 = FUN_005f0ddc(uVar14);
            FUN_004bba60(&DAT_008d56d8, uVar15, uVar14, uVar29, uVar30);
            iVar19 = DAT_0085a268;
            iVar9 = DAT_007261ec;
            iVar24 = DAT_0086c330;
            (&DAT_0086c010)[iVar24] = static_cast<int16_t>(iVar25) + 0x50;
            (&DAT_0086be80)[iVar24] = sVar20 + 2;
            DAT_0086c330 = DAT_0086c330 + 1;
            (&DAT_0086c1a0)[iVar24] = 4;
            (&DAT_0086bcf0)[iVar24] = static_cast<int16_t>(iVar25) + 0x85;
            (&DAT_0086bb60)[iVar24] = sVar20 + 0x2e;
        }
        iVar24 = FUN_0042c6f0();
        DAT_00869b48 = 0;
        if (iVar24 != -1) {
            if (local_2bc != iVar24) {
                FUN_004889c0(&DAT_008c8278, 0x36, 0xffffffff, 0xffffffff, 0xffffffff, 0xbf800000,
                             0xffffffff);
                iVar9 = DAT_007261ec;
                iVar19 = DAT_0085a268;
            }
            iVar25 = DAT_007261e4;
            if ((iVar24 < 0xa0) || (199 < iVar24)) {
                if (iVar24 == 4) {
                    FUN_004f6090("@EVILNAME", DAT_008cb190, DAT_008cb194, DAT_008cb198);
                    FUN_004b06c0(&DAT_00869b48, iVar25 + 0x6c, iVar19 / 2 + iVar9 + 0x45, 0x33,
                                 0xffffcc00, 4, 0xffffffff, 0);
                }
                else if ((5 <= iVar24) && (iVar24 <= 8)) {
                    iVar25 = (iVar24 + -5) * 0x30 + 0x22 + DAT_007261e4;
                    FUN_004f6090("@RELATIVE", iVar24 + -5);
                    DAT_0085a11c = 0x32;
                    DAT_008c9de0 = DAT_008c9dd8;
                    FUN_00509500(DAT_008c9dd8, &DAT_00869b48, 0);
                    iVar9 = iVar9 + 0x3a;
                    DAT_0085a11c = 0x32;
                    DAT_008c9de0 = DAT_008c9dd8;
                    FUN_004b06c0(&DAT_00869b48, iVar25, iVar9, 0x32, 0xffffcc00, 4, 0xffffffff,
                                 0);
                }
                else if ((9 <= iVar24) && (iVar24 <= 0x11)) {
                    uVar23 = 0;
                    iVar19 = 0;
                    piVar10 = &DAT_00862014[0];
                    do {
                        if (*piVar10 == 0) {
                            if (uVar23 == static_cast<uint32_t>(iVar24 - 9))
                                break;
                            uVar23 = uVar23 + 1;
                        }
                        piVar10 = piVar10 + 7;
                        iVar19 = iVar19 + 1;
                    } while (reinterpret_cast<intptr_t>(piVar10) < 0x862110);
                    uVar16 = uVar23 & 0x80000001;
                    if (static_cast<int>(uVar16) < 0) {
                        uVar16 = (uVar16 - 1 | 0xfffffffe) + 1;
                    }
                    iVar25 = static_cast<int>(uVar16 * 0x60) + DAT_007261e0;
                    FUN_004f6090("@TOP10", (&DAT_008cb10c)[iVar19 * 3],
                                 (&DAT_008cb110)[iVar19 * 3], (&DAT_008cb114)[iVar19 * 3]);
                    DAT_0085a11c = 0x32;
                    DAT_008c9de0 = DAT_008c9dd8;
                    FUN_00509500(DAT_008c9dd8, &DAT_00869b48, 0);
                    iVar9 = iVar9 + (static_cast<int>(uVar23) / 2) * 0x18 + 0x20;
                    iVar25 = iVar25 + 0xc;
                    DAT_0085a11c = 0x32;
                    DAT_008c9de0 = DAT_008c9dd8;
                    FUN_004b06c0(&DAT_00869b48, iVar25, iVar9, 0x33, 0xffffcc00, 1, 0xffffffff,
                                 0);
                }
                else if ((0x12 <= iVar24) && (iVar24 <= 0x1a)) {
                    uVar23 = 0;
                    iVar17 = 0;
                    pbVar11 = &DAT_00862018[0];
                    do {
                        if ((*pbVar11 & 1) != 0) {
                            if (uVar23 == static_cast<uint32_t>(iVar24 - 0x12))
                                break;
                            uVar23 = uVar23 + 1;
                        }
                        pbVar11 = pbVar11 + 0x1c;
                        iVar17 = iVar17 + 1;
                    } while (reinterpret_cast<intptr_t>(pbVar11) < 0x862114);
                    uVar16 = uVar23 & 0x80000001;
                    if (static_cast<int>(uVar16) < 0) {
                        uVar16 = (uVar16 - 1 | 0xfffffffe) + 1;
                    }
                    iVar25 = static_cast<int>(uVar16 * 0x60) + DAT_007261e0;
                    FUN_004f6090("@TOP10", (&DAT_008cb10c)[iVar17 * 3],
                                 (&DAT_008cb110)[iVar17 * 3], (&DAT_008cb114)[iVar17 * 3]);
                    DAT_0085a11c = 0x32;
                    DAT_008c9de0 = DAT_008c9dd8;
                    FUN_00509500(DAT_008c9dd8, &DAT_00869b48, 0);
                    iVar9 = iVar19 / 3 + iVar9 + (static_cast<int>(uVar23) / 2 + 1) * 0x18 + 2;
                    DAT_0085a11c = 0x32;
                    DAT_008c9de0 = DAT_008c9dd8;
                    iVar25 = iVar25 + 0xc;
                    FUN_004b06c0(&DAT_00869b48, iVar25, iVar9, 0x33, 0xffffcc00, 1, 0xffffffff,
                                 0);
                }
                else if ((0x1c <= iVar24) && (iVar24 <= 0x1f)) {
                    iVar25 = (iVar24 + -0x1c) * 0x30 + 0x22 + DAT_007261e4;
                    FUN_004f6090("@LOSTCITY", iVar24 + -0x1c);
                    DAT_0085a11c = 0x32;
                    DAT_008c9de0 = DAT_008c9dd8;
                    FUN_00509500(DAT_008c9dd8, &DAT_00869b48, 0);
                    iVar9 = iVar19 / 7 + iVar9 + 0x3a;
                    DAT_0085a11c = 0x32;
                    DAT_008c9de0 = DAT_008c9dd8;
                    FUN_004b06c0(&DAT_00869b48, iVar25, iVar9, 0x32, 0xffffcc00, 4, 0xffffffff,
                                 0);
                }
                else if (iVar24 == 0x1b) {
                    FUN_004f6090("City: @CITYNAME", (&DAT_008dbd08)[local_330 * 3],
                                 (&DAT_008dbd0c)[local_330 * 3], (&DAT_008dbd10)[local_330 * 3]);
                    FUN_004b06c0(&DAT_00869b48, DAT_007261e4 + 0x50,
                                 (DAT_0085a268 * 2) / 7 + 0x20 + DAT_007261ec, 0x32, 0xffffcc00,
                                 1, 0xffffffff, 0);
                    FUN_004f6090("Romance: ");
                    DAT_0085a11c = 0x32;
                    DAT_008c9de0 = DAT_008c9dd8;
                    FUN_00509500(DAT_008c9dd8, &DAT_00869b48, 0);
                    FUN_004b06c0(&DAT_00869b48, DAT_007261e4 + 0x50,
                                 (DAT_0085a268 * 2) / 7 + 0x2e + DAT_007261ec, 0x32, 0xffffcc00,
                                 1, 0xffffffff, 0);
                    FUN_004f6090("Attractiveness: @BEAUTY", (&DAT_0085bf74)[local_330 * 0x25]);
                    FUN_004b06c0(&DAT_00869b48, DAT_007261e4 + 0x50,
                                 (DAT_0085a268 * 2) / 7 + 0x3c + DAT_007261ec, 0x32, 0xffffcc00,
                                 1, 0xffffffff, 0);
                    if (((_DAT_0085a164 & 0x200000) != 0) &&
                        ((*(&DAT_0085bf70 + local_330 * 0x25) & 8) != 0)) {
                        FUN_004f6090("(Married)");
                        FUN_004b06c0(&DAT_00869b48, DAT_007261e4 + 0x50,
                                     (DAT_0085a268 * 2) / 7 + 0x4a + DAT_007261ec, 0x32,
                                     0xffffcc00, 1, 0xffffffff, 0);
                    }
                    cVar7 = (&DAT_00860b74)[local_330 * 0x20];
                    DAT_00869b48 = 0;
                    if (cVar7 == '\0') {
                        pcVar31 = const_cast<char *>("Spanish Daughter");
                    }
                    else if (cVar7 == '\x02') {
                        pcVar31 = const_cast<char *>("French Daughter");
                    }
                    else if (cVar7 == '\x01') {
                        pcVar31 = const_cast<char *>("English Daughter");
                    }
                    else {
                        pcVar31 = const_cast<char *>("Dutch Daughter");
                    }
                    FUN_004f6090(pcVar31);
                    DAT_0085a11c = 0x33;
                    DAT_008c9de0 = DAT_008c9dd8;
                    FUN_00509500(DAT_008c9dd8, &DAT_00869b48, 0);
                    iVar9 = (iVar19 * 2) / 7 + iVar9 + 0x60;
                    iVar25 = iVar25 + 0x30;
                    FUN_004b06c0(&DAT_00869b48, iVar25, iVar9, 0x33, 0xffffcc00, 4, 0xffffffff,
                                 0);
                }
            }
            else {
                iVar25 = (199 - iVar24) % 10;
                if (iVar24 < 0xbe) {
                    if (iVar24 < 0xb4) {
                        iVar17 = (static_cast<int>(iVar24 < 0xaa)) + 2;
                    }
                    else {
                        iVar17 = 1;
                    }
                }
                else {
                    iVar17 = 0;
                }
                iVar3 = iVar25 * 0x17 + DAT_007261dc;
                FUN_004f6090("@RANK", iVar25);
                FUN_004b06c0(&DAT_00869b48, iVar3 + -0x42,
                             (iVar19 / 9 + 5) * iVar17 + 0x83 + iVar9, 0x33, 0xffffcc00, 4,
                             0xffffffff, 0);
            }
        }
        local_2bc = iVar24;
        iVar9 = FUN_004b2760(0);
        if ((0x29f < iVar9) && (iVar9 < 0x2c8)) {
            iVar19 = iVar9 + -0x200;
            if (iVar19 < 0xbe) {
                if (iVar19 < 0xb4) {
                    iVar19 = (static_cast<int>(iVar19 < 0xaa)) + 2;
                }
                else {
                    iVar19 = 1;
                }
            }
            else {
                iVar19 = 0;
            }
            psVar22 = reinterpret_cast<int16_t *>(&DAT_00869a88 + iVar19 * 2);
            if ((&DAT_00869a88)[iVar19 * 2] < 2) {
                FUN_0042e730();
                break;
            }
            FUN_00488ed0(0);
            iStack_328 = static_cast<int>(*psVar22);
            psVar2 = &DAT_00869a98[0] + iVar19;
            uVar4 = (&DAT_00860b74)[*psVar2 * 0x20];
            (&DAT_00860b74)[*psVar2 * 0x20] = static_cast<char>(iVar19);
            bVar28 = DAT_008c827f != '\0';
            *psVar22 = static_cast<int16_t>((0x2c7 - iVar9) % 10);
            if (bVar28) {
                FUN_00489130(&DAT_008c8288);
                DAT_008c827f = '\0';
            }
            if (DAT_008c827e != '\0') {
                DAT_008c827e = '\0';
            }
            FUN_00488ed0(0);
            *reinterpret_cast<uint32_t *>(reinterpret_cast<uint8_t *>(&DAT_007268f4) +
                                          DAT_00726a84 * 4) = static_cast<uint32_t>(DAT_007263bc);
            DAT_00726a84 = DAT_00726a84 + 1;
            DAT_007263bc = 0xff7ffff;
            iVar25 = 0;
            do {
                pcVar31 = &DAT_006f5896[0] + iVar25;
                (&DAT_008bea80)[iVar25] = *pcVar31;
                iVar25 = iVar25 + 1;
            } while (*pcVar31 != '\0');
            _DAT_008be9f4 = 1;
            FUN_00482e60(1, static_cast<int>(*psVar2));
            FUN_004841b0();
            FUN_004f6090("In recognition of your service to the @NATIONALITY crown, I am pleased to promote you to the rank of @RANK, Congratulations! ",
                         iVar19, static_cast<char>(*psVar22));
            FUN_00483b70();
            FUN_004f60b0("(@RANKBONUS in @NATIONALITY ports)\n", static_cast<char>(*psVar22),
                         iVar19);
            FUN_004841b0();
            FUN_004879f0(0x30, 0);
            uVar23 = _DAT_0085a164;
            _DAT_0085a164 = _DAT_0085a164 | 0x100000;
            FUN_004879f0(0x30, 0);
            cVar7 = reinterpret_cast<char (*)()>(
                *reinterpret_cast<void **>(DAT_008ecd78 + 0x18))();
            if ((cVar7 != '\0') && ((DAT_008cac27 == '\0') || (DAT_008cac26 != '\0'))) {
                while (true) {
                    iVar25 = DAT_008e8ec4 - _DAT_008e8ec8;
                    if (iVar25 < 0) {
                        iVar25 = iVar25 + 100;
                    }
                    if (iVar25 == 0)
                        break;
                    Sleep(0x28);
                }
                FUN_004a0d90();
                FUN_0049af70(*DAT_008ed2c8, 0);
                FUN_0049aed0(0x15, 0xfffffffe);
            }
            FUN_0049aed0(0x17, iVar19);
            FUN_00488d90(local_2b4, 1, 0, 0, 0xffffffff, 0xffffffff, 0xffffffff, 0, iVar19);
            FUN_00430190(DAT_0085a26c / 0xc,
                         (DAT_0085a268 + ((DAT_0085a268 >> 0x1f) & 0xf)) >> 4,
                         &DAT_006f5896, 0, 0xffffffff,
                         reinterpret_cast<void *>(&FUN_00484bd0), 0, 0xffffffff, 0, 0);
            FUN_00489130(&DAT_008c7340);
            FUN_00488ed0(0x3f800000);
            cVar7 = reinterpret_cast<char (*)()>(
                *reinterpret_cast<void **>(DAT_008ecd78 + 0x18))();
            if ((cVar7 != '\0') && ((DAT_008cac27 == '\0') || (DAT_008cac26 != '\0'))) {
                while (true) {
                    iVar19 = DAT_008e8ec4 - _DAT_008e8ec8;
                    if (iVar19 < 0) {
                        iVar19 = iVar19 + 100;
                    }
                    if (iVar19 == 0)
                        break;
                    Sleep(0x28);
                }
                if ((DAT_008e8eec != 0) && (((DAT_008e8ef0 - DAT_008e8eec) >> 2) != 0)) {
                    DAT_008e8ef0 = DAT_008e8ef0 + -4;
                }
                FUN_0049af70(*DAT_008ed2c8, 0);
                uVar15 = 0xfffffffe;
                uVar14 = static_cast<uint32_t>(FUN_004a0b70(0xfffffffe));
                FUN_0049aed0(static_cast<int>(uVar14), uVar15);
            }
            FUN_00483ca0();
            DAT_00726a84 = DAT_00726a84 + -1;
            DAT_007263bc = *reinterpret_cast<int *>(reinterpret_cast<uint8_t *>(&DAT_007268f4) +
                                                    DAT_00726a84 * 4);
            (&DAT_00860b74)[*psVar2 * 0x20] = uVar4;
            *psVar22 = static_cast<int16_t>(iStack_328);
            _DAT_0085a164 = uVar23;
        }
        if (iVar9 < 0x212) {
            if (iVar9 < 0x209) {
                if (iVar9 < 0x205) {
                    if (iVar9 == 0x204) {
                        FUN_004a22f0(1, 1, 0);
                        puStack_22c = &DAT_008cacd0;
                        puStack_228 = &DAT_008cacd0;
                        puStack_224 = &DAT_008cacd0;
                        uStack_220 = 0;
                        DAT_0072cb4c = 6;
                        DAT_0072ccc4 = 0x259;
                        DAT_0072cb44 = 5;
                        FUN_004f6090("'You are a master tactician, sir. Truly I have done your family a terrible injustice. ");
                        FUN_004f60b0("I give you 100,000 gold pieces which are rightfully yours. ");
                        FUN_004f60b0("Among my crew are eight specialists of extraordinary skill, henceforth they will serve you. ");
                        FUN_004f60b0("I myself will serve as your cabin steward.'\n");
                        FUN_00487e90();
                        FUN_00412f10();
                        FUN_004f6090("Marquis Montalban");
                        FUN_0041a300(&puStack_2d8, 5, 0x2a, 0);
                        FUN_00412ec0();
                        puVar13 = reinterpret_cast<uint32_t *>(puStack_2d8 - 8);
                        if ((puVar13 != NULL) &&
                            (puVar13 != reinterpret_cast<uint32_t *>(&DAT_008cacc8))) {
                            operator_delete__(puVar13);
                        }
                        apuStack_300[5] = NULL;
                        puStack_2d8 = &DAT_008cacd0;
                        aiStack_2e8[0] = 0;
                        iVar9 = static_cast<int>(FUN_00533c78(0xc0));
                        if (iVar9 == 0) {
                            puVar13 = NULL;
                        }
                        else {
                            puVar13 = reinterpret_cast<uint32_t *>(
                                FUN_004baa30(DAT_008e9ffc, reinterpret_cast<const char *>(&DAT_008cacd0),
                                             0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0));
                        }
                        if (reinterpret_cast<uint32_t *>(aiStack_2e8[0]) != puVar13) {
                            if ((reinterpret_cast<uint32_t *>(aiStack_2e8[0]) != NULL) &&
                                (iVar9 = *reinterpret_cast<int *>(static_cast<intptr_t>(aiStack_2e8[0]) + 4),
                                 *reinterpret_cast<int *>(static_cast<intptr_t>(aiStack_2e8[0]) + 4) = iVar9 + -1,
                                 iVar9 + -1 == 0)) {
                                void *p = reinterpret_cast<void *>(
                                    static_cast<intptr_t>(aiStack_2e8[0]));
                                void *vt = *reinterpret_cast<void **>(p);
                                reinterpret_cast<void (*)(int)>(*reinterpret_cast<void **>(vt))(1);
                            }
                            aiStack_2e8[0] =
                                static_cast<int>(reinterpret_cast<intptr_t>(puVar13));
                            if (puVar13 != NULL) {
                                puVar13[1] = puVar13[1] + 1;
                            }
                        }
                        aiStack_2a8[6] = 0;
                        aiStack_2a8[7] = 0;
                        aiStack_2a8[8] = 0;
                        FUN_0041a9f0(0, aiStack_2a8 + 6);
                        iVar9 = DAT_008e9ffc;
                        if (DAT_008e9ffc != 0) {
                            *reinterpret_cast<int *>(static_cast<intptr_t>(DAT_008e9ffc) + 4) =
                                *reinterpret_cast<int *>(static_cast<intptr_t>(DAT_008e9ffc) + 4) + 1;
                        }
                        puVar13 = reinterpret_cast<uint32_t *>(
                            FUN_004af680(iVar9, &DAT_00869b48, 0, 0, 0, 0, 0xffffffff, 1, 0, 0, 0,
                                         0));
                        pirates_obj_assign(reinterpret_cast<void **>(&apuStack_300[5]), puVar13);
                        iVar9 = static_cast<int>(FUN_00533c78(0xc0));
                        if (iVar9 == 0) {
                            puStack_340 = NULL;
                        }
                        else {
                            puStack_340 = reinterpret_cast<uint32_t *>(
                                FUN_004baa30(DAT_008e9ffc, "uber_sword.kfm", 0, 0, 0, 0,
                                             0xffffffff, 0, 0, 0, 0));
                            if (puStack_340 != NULL) {
                                puStack_340[1] = puStack_340[1] + 1;
                            }
                        }
                        iVar9 = static_cast<int>(FUN_00533c78(0xc0));
                        if (iVar9 == 0) {
                            puStack_344 = NULL;
                        }
                        else {
                            puStack_344 = reinterpret_cast<uint32_t *>(
                                FUN_004baa30(DAT_008e9fec,
                                             reinterpret_cast<const char *>(local_204), 0, 0, 0, 0,
                                             0xffffffff, 0, 0, 0, 0));
                            if (puStack_344 != NULL) {
                                puStack_344[1] = puStack_344[1] + 1;
                            }
                        }
                        iVar9 = static_cast<int>(FUN_00533c78(0xc0));
                        if ((iVar9 != 0) &&
                            (iVar9 = static_cast<int>(FUN_004baa30(
                                 DAT_008e9fec, reinterpret_cast<const char *>(auStack_104), 0, 0,
                                 0, 0, 0xffffffff, 0, 0, 0, 0)),
                             iVar9 != 0)) {
                            *reinterpret_cast<int *>(static_cast<intptr_t>(iVar9) + 4) =
                                *reinterpret_cast<int *>(static_cast<intptr_t>(iVar9) + 4) + 1;
                        }
                        iVar9 = static_cast<int>(FUN_00533c78(0xc0));
                        if (iVar9 == 0) {
                            puVar13 = NULL;
                        }
                        else {
                            puVar13 = reinterpret_cast<uint32_t *>(
                                FUN_004baa30(DAT_008e9fec, "ramparts_01.nif", 0, 0, 0, 0,
                                             0xffffffff, 0, 0, 0, 0));
                            if (puVar13 != NULL) {
                                puVar13[1] = puVar13[1] + 1;
                            }
                        }
                        apuStack_300[2] = NULL;
                        apuStack_300[1] = NULL;
                        aiStack_30c[0] = 0;
                        apuStack_318[2] = NULL;
                        apuStack_318[1] = apuStack_318[2];
                        iVar9 = static_cast<int>(FUN_00533c78(0xc0));
                        if (iVar9 == 0) {
                            puVar12 = NULL;
                        }
                        else {
                            puVar12 = reinterpret_cast<uint32_t *>(
                                FUN_004baa30(DAT_008ea000, "duel_props.kfm", 0, 0, 0, 0,
                                             0xffffffff, 0, 0, 0, 0));
                        }
                        pirates_obj_assign(reinterpret_cast<void **>(&apuStack_300[1]), puVar12);
                        iVar9 = static_cast<int>(FUN_00533c78(0xc0));
                        if (iVar9 == 0) {
                            puVar12 = NULL;
                        }
                        else {
                            puVar12 = reinterpret_cast<uint32_t *>(
                                FUN_004baa30(DAT_008ea000, "duel_props.kfm", 0, 0, 0, 0,
                                             0xffffffff, 0, 0, 0, 0));
                        }
                        pirates_obj_assign(reinterpret_cast<void **>(&apuStack_300[2]), puVar12);
                        FUN_004baaa0();
                        iVar9 = DAT_008c9dec;
                        *reinterpret_cast<uint32_t *>(reinterpret_cast<uint8_t *>(&DAT_007268f4) +
                                                      DAT_00726a84 * 4) =
                            static_cast<uint32_t>(DAT_007263bc);
                        DAT_00726a84 = DAT_00726a84 + 1;
                        DAT_007263bc = 0xff7ffff;
                        _DAT_0085a164 = _DAT_0085a164 & 0xfffffffb;
                        {
                            uint8_t *q = *reinterpret_cast<uint8_t **>(
                                static_cast<uint8_t *>(static_cast<intptr_t>(iVar9)) + 0x14);
                            void *vt = *reinterpret_cast<void **>(q);
                            reinterpret_cast<void (*)(int, int, uint32_t)>(
                                *reinterpret_cast<void **>(static_cast<uint8_t *>(vt) + 0x10))(
                                0, 0, 0xc37a0000);
                            reinterpret_cast<void (*)(int)>(
                                *reinterpret_cast<void **>(static_cast<uint8_t *>(vt) + 0xc))(0);
                        }
                        FUN_004d9af0(DAT_008c9dec, 0x41a00000);
                        uVar14 = DAT_008cabd4;
                        FUN_004add70(0x4b0);
                        FUN_00425ad0(reinterpret_cast<const char *>(&DAT_008cacd0), puVar13,
                                     static_cast<int>(unaff_EBX), 0, apuStack_300 + 1,
                                     reinterpret_cast<void *>(&local_324), aiStack_2a8 + 2,
                                     aiStack_30c, auStack_23c);
                        FUN_004add70(uVar14);
                        puVar12 = reinterpret_cast<uint32_t *>(DAT_008c9dec + 0x14);
                        {
                            uint8_t *q = *reinterpret_cast<uint8_t **>(
                                static_cast<uint8_t *>(static_cast<intptr_t>(DAT_008c9dec)) +
                                0x14);
                            void *vt = *reinterpret_cast<void **>(q);
                            reinterpret_cast<void (*)(int, int, int)>(
                                *reinterpret_cast<void **>(static_cast<uint8_t *>(vt) + 0x10))(
                                0, 0, DAT_007255f8);
                            reinterpret_cast<void (*)(int)>(
                                *reinterpret_cast<void **>(static_cast<uint8_t *>(vt) + 0xc))(0);
                        }
                        FUN_004d9af0(DAT_008c9dec, 0x41a00000);
                        DAT_00726a84 = DAT_00726a84 + -1;
                        DAT_007263bc = *reinterpret_cast<int *>(reinterpret_cast<uint8_t *>(&DAT_007268f4) +
                                                                DAT_00726a84 * 4);
                        ppuVar26 = apuStack_300 + 3;
                        iVar9 = 2;
                        do {
                            puVar12 = ppuVar26[-1];
                            ppuVar26 = ppuVar26 + -1;
                            pirates_obj_release(puVar12);
                            iVar9 = iVar9 + -1;
                        } while (iVar9 != 0);
                        piVar10 = aiStack_30c + 1;
                        iVar9 = 3;
                        do {
                            puVar12 = reinterpret_cast<uint32_t *>(piVar10[-1]);
                            piVar10 = piVar10 + -1;
                            pirates_obj_release(puVar12);
                            iVar9 = iVar9 + -1;
                        } while (iVar9 != 0);
                        pirates_obj_release(puVar13);
                        DAT_008cacd4 = DAT_008cacd4 + -1;
                        if (DAT_008cacd4 == 0) {
                            reinterpret_cast<void (*)(int)>(*_DAT_008cacd0)(1);
                        }
                        pirates_obj_release(puStack_344);
                        pirates_obj_release(puStack_340);
                        piVar10 = aiStack_2a8 + 9;
                        iVar9 = 3;
                        do {
                            puVar13 = reinterpret_cast<uint32_t *>(piVar10[-1]);
                            piVar10 = piVar10 + -1;
                            pirates_obj_release(puVar13);
                            iVar9 = iVar9 + -1;
                        } while (iVar9 != 0);
                        piVar10 = aiStack_2e8 + 1;
                        iVar9 = 2;
                        do {
                            puVar13 = reinterpret_cast<uint32_t *>(piVar10[-1]);
                            piVar10 = piVar10 + -1;
                            pirates_obj_release(puVar13);
                            iVar9 = iVar9 + -1;
                        } while (iVar9 != 0);
                        FUN_0040a610();
                    }
                    else if ((iVar9 == 1) || (iVar9 == 0x1b)) {
                        bVar6 = true;
                    }
                }
                else if ((0x204 < iVar9) && (iVar9 < 0x209)) {
                    FUN_004a22f0(1, 1, 0);
                    FUN_004f6090("You have rescued your long lost @RELATIVE! ", iVar9 + -0x205);
                    FUN_00451e50(iVar9 + -0x205, 0xffffffff, 0);
                }
            }
            else {
                iVar9 = 0;
                iVar19 = 0;
                piVar10 = &DAT_00862014[0];
                do {
                    if (*piVar10 == 0) {
                        if (iVar9 == iVar24 + -9)
                            break;
                        iVar9 = iVar9 + 1;
                    }
                    piVar10 = piVar10 + 7;
                    iVar19 = iVar19 + 1;
                } while (reinterpret_cast<intptr_t>(piVar10) < 0x862110);
                FUN_00488ed0(0);
                FUN_004a22f0(1, 1, 0);
                cVar7 = DAT_00725d98;
                (&DAT_00726814)[DAT_00726820] = DAT_00725d98;
                iVar9 = DAT_008c97c4;
                DAT_00726820 = DAT_00726820 + 1;
                puStack_254 = &DAT_008cacd0;
                puStack_250 = &DAT_008cacd0;
                puStack_24c = &DAT_008cacd0;
                if (cVar7 != '\0') {
                    *reinterpret_cast<uint8_t *>(static_cast<intptr_t>(DAT_008c97c0) + 0xb4) = 0;
                    *reinterpret_cast<uint8_t *>(static_cast<intptr_t>(iVar9) + 0xb4) = 0;
                    FUN_00535920(DAT_008e9fe8);
                    FUN_00535920(DAT_008e9fe8);
                }
                *reinterpret_cast<uint32_t *>(reinterpret_cast<uint8_t *>(&DAT_007268f4) +
                                              DAT_00726a84 * 4) =
                    static_cast<uint32_t>(DAT_007263bc);
                DAT_00726a84 = DAT_00726a84 + 1;
                DAT_00725d98 = '\0';
                DAT_008c9df4 = 1;
                DAT_007263bc = 0xff7ffff;
                FUN_00489360(0, 0, 0, 0, 0x2d);
                uStack_248 = 0;
                FUN_00412f10();
                iStack_230 = iVar19 + 1;
                DAT_0072cb4c = 0;
                DAT_0072cb44 = 5;
                DAT_0072ccc4 = 300;
                if (((&DAT_00861ffc)[iStack_230 * 7] & 0x10) == 0) {
                    uStack_234 = (static_cast<uint32_t>(
                                      static_cast<int8_t>((&DAT_00861ffc)[iStack_230 * 7])) &
                                  8u) >> 2;
                }
                else {
                    uStack_234 = 3;
                }
                FUN_0041a300(&puStack_2dc, 5, iStack_230, 0);
                FUN_00412ec0();
                puVar13 = reinterpret_cast<uint32_t *>(puStack_2dc - 8);
                if ((puVar13 != NULL) &&
                    (puVar13 != reinterpret_cast<uint32_t *>(&DAT_008cacc8))) {
                    operator_delete__(puVar13);
                }
                puStack_2dc = &DAT_008cacd0;
                iVar9 = _strnicmp(reinterpret_cast<const char *>(&DAT_008cacd0), "blackbeard", 10);
                puStack_31c = NULL;
                apuStack_318[0] = NULL;
                iVar24 = static_cast<int>(FUN_00533c78(0xc0));
                if (iVar24 == 0) {
                    puVar13 = NULL;
                }
                else {
                    puVar13 = reinterpret_cast<uint32_t *>(
                        FUN_004baa30(DAT_008e9ffc, reinterpret_cast<const char *>(&DAT_008cacd0),
                                     0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0));
                }
                pirates_obj_assign(reinterpret_cast<void **>(&apuStack_318[0]), puVar13);
                puStack_340 = NULL;
                puStack_344 = NULL;
                if (iVar9 == 0) {
                    iVar24 = static_cast<int>(FUN_00533c78(0xc0));
                    if ((iVar24 != 0) &&
                        (puVar13 = reinterpret_cast<uint32_t *>(
                             FUN_004baa30(DAT_008ea000, "fx_blackbeard_fire.nif", 0, 0, 0, 0,
                                          0xffffffff, 0, 0, 0, 0)),
                         puVar13 != NULL)) {
                        puVar13[1] = puVar13[1] + 1;
                        puStack_340 = puVar13;
                    }
                    puStack_340[8] = puStack_340[8] | 0x4000;
                    if ((puStack_340[0x14] == 0) ||
                        (DVar18 = GetCurrentThreadId(), DAT_008e8fdc != DVar18)) {
                        if (puStack_340[0x2f] != 0) {
                            FUN_004c0940();
                        }
                        FUN_004c08b0(puStack_340[7]);
                    }
                    iVar24 = static_cast<int>(FUN_00533c78(0xc0));
                    if ((iVar24 != 0) &&
                        (puVar13 = reinterpret_cast<uint32_t *>(
                             FUN_004baa30(DAT_008ea000, "fx_blackbeard_smoke.nif", 0, 0, 0, 0,
                                          0xffffffff, 0, 0, 0, 0)),
                         puVar13 != NULL)) {
                        puVar13[1] = puVar13[1] + 1;
                        puStack_344 = puVar13;
                    }
                    FUN_004c1080(apuStack_318[0], "fx_blackbeard_fire", 100, 0xffffffff);
                    FUN_004c1080(apuStack_318[0], "fx_blackbeard_fire", 100, 0xffffffff);
                }
                uStack_2b0 = 0;
                uStack_2ac = 0;
                aiStack_2a8[0] = 0;
                FUN_0041a9f0(4, &uStack_2b0);
                iVar24 = DAT_008e9ffc;
                if (DAT_008e9ffc != 0) {
                    *reinterpret_cast<int *>(static_cast<intptr_t>(DAT_008e9ffc) + 4) =
                        *reinterpret_cast<int *>(static_cast<intptr_t>(DAT_008e9ffc) + 4) + 1;
                }
                puVar13 = reinterpret_cast<uint32_t *>(
                    FUN_004af680(iVar24, &DAT_00869b48, 0, 0, 0, 0, 0xffffffff, 1, 0, 0, 0, 0));
                pirates_obj_assign(reinterpret_cast<void **>(&puStack_31c), puVar13);
                FUN_00419ac0();
                FUN_00419ac0();
                FUN_00419ac0();
                iVar24 = static_cast<int>(FUN_00533c78(0xc0));
                if (iVar24 == 0) {
                    puStack_33c = NULL;
                }
                else {
                    puStack_33c = reinterpret_cast<uint32_t *>(
                        FUN_004baa30(DAT_008e9fec, reinterpret_cast<const char *>(auStack_184),
                                     0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0));
                    if (puStack_33c != NULL) {
                        puStack_33c[1] = puStack_33c[1] + 1;
                    }
                }
                iVar24 = static_cast<int>(FUN_00533c78(0xc0));
                if (iVar24 == 0) {
                    iStack_328 = 0;
                }
                else {
                    iStack_328 = static_cast<int>(FUN_004baa30(
                        DAT_008e9fec, reinterpret_cast<const char *>(auStack_84), 0, 0, 0, 0,
                        0xffffffff, 0, 0, 0, 0));
                    if (iStack_328 != 0) {
                        *reinterpret_cast<int *>(static_cast<intptr_t>(iStack_328) + 4) =
                            *reinterpret_cast<int *>(static_cast<intptr_t>(iStack_328) + 4) + 1;
                    }
                }
                uVar14 = DAT_008cabd4;
                puVar13 = NULL;
                if (static_cast<char>(
                        *reinterpret_cast<uint32_t *>(&DAT_00862018 + iVar19 * 0x1c)) < '\0') {
                    iVar19 = static_cast<int>(FUN_00533c78(0xc0));
                    if ((iVar19 != 0) &&
                        (puVar12 = reinterpret_cast<uint32_t *>(
                             FUN_004baa30(DAT_008e9fec, "Ship_Deck_01n.nif", 0, 0, 0, 0,
                                          0xffffffff, 0, 0, 0, 0)),
                         puVar12 != NULL)) {
                        puVar12[1] = puVar12[1] + 1;
                        puVar13 = puVar12;
                    }
                    FUN_004d96a0("skydome_night.nif", 0x3f266666);
                    uVar15 = 0x8fc;
                }
                else if ((*reinterpret_cast<uint32_t *>(&DAT_00862018 + iVar19 * 0x1c) & 0x40) ==
                         0) {
                    iVar19 = static_cast<int>(FUN_00533c78(0xc0));
                    if ((iVar19 != 0) &&
                        (puVar12 = reinterpret_cast<uint32_t *>(
                             FUN_004baa30(DAT_008e9fec, "Ship_Deck_01.nif", 0, 0, 0, 0,
                                          0xffffffff, 0, 0, 0, 0)),
                         puVar12 != NULL)) {
                        puVar12[1] = puVar12[1] + 1;
                        puVar13 = puVar12;
                    }
                    uVar15 = 0x4b0;
                }
                else {
                    iVar19 = static_cast<int>(FUN_00533c78(0xc0));
                    if ((iVar19 != 0) &&
                        (puVar12 = reinterpret_cast<uint32_t *>(
                             FUN_004baa30(DAT_008e9fec, "Ship_Deck_01s.nif", 0, 0, 0, 0,
                                          0xffffffff, 0, 0, 0, 0)),
                         puVar12 != NULL)) {
                        puVar12[1] = puVar12[1] + 1;
                        puVar13 = puVar12;
                    }
                    FUN_004d96a0("skydome_lateday.nif", 0x3f266666);
                    uVar15 = 0x78a;
                }
                FUN_004add70(uVar15);
                apuStack_300[4] = NULL;
                apuStack_300[3] = NULL;
                apuStack_300[0] = NULL;
                aiStack_30c[2] = 0;
                aiStack_30c[1] = aiStack_30c[2];
                iVar19 = static_cast<int>(FUN_00533c78(0xc0));
                if (iVar19 == 0) {
                    puVar12 = NULL;
                }
                else {
                    puVar12 = reinterpret_cast<uint32_t *>(
                        FUN_004baa30(DAT_008ea000, "duel_props.kfm", 0, 0, 0, 0, 0xffffffff, 0,
                                     0, 0, 0));
                }
                pirates_obj_assign(reinterpret_cast<void **>(&apuStack_300[3]), puVar12);
                iVar19 = static_cast<int>(FUN_00533c78(0xc0));
                if (iVar19 == 0) {
                    puVar12 = NULL;
                }
                else {
                    puVar12 = reinterpret_cast<uint32_t *>(
                        FUN_004baa30(DAT_008ea000, "duel_props.kfm", 0, 0, 0, 0, 0xffffffff, 0,
                                     0, 0, 0));
                }
                pirates_obj_assign(reinterpret_cast<void **>(&apuStack_300[4]), puVar12);
                FUN_004baaa0();
                uVar15 = FUN_005f0ddc();
                FUN_004e4580(100);
                aiStack_2a8[9] = 0x40200000;
                FUN_005be280("fWaterTexScale", 4, aiStack_2a8 + 9);
                _DAT_0085a164 = _DAT_0085a164 & 0xfffffffb;
                puVar12 = reinterpret_cast<uint32_t *>(DAT_008c9dec + 0x14);
                {
                    uint8_t *q = *reinterpret_cast<uint8_t **>(
                        static_cast<uint8_t *>(static_cast<intptr_t>(DAT_008c9dec)) + 0x14);
                    void *vt = *reinterpret_cast<void **>(q);
                    reinterpret_cast<void (*)(int, int, uint32_t)>(
                        *reinterpret_cast<void **>(static_cast<uint8_t *>(vt) + 0x10))(
                        0, 0, 0xc37a0000);
                    reinterpret_cast<void (*)(int)>(
                        *reinterpret_cast<void **>(static_cast<uint8_t *>(vt) + 0xc))(0);
                }
                FUN_004d9af0(DAT_008c9dec, 0x41a00000);
                FUN_00427f80(puVar13);
                FUN_00425ad0(reinterpret_cast<const char *>(&DAT_008cacd0), puVar13, 0, 0,
                             auStack_32c, apuStack_318,
                             reinterpret_cast<void *>(&local_2c0), aiStack_30c + 2,
                             aiStack_2a8 + 0x11);
                FUN_00428140();
                FUN_004d96a0("skydome006.nif", 0x3f266666);
                puVar12 = reinterpret_cast<uint32_t *>(DAT_008c9dec + 0x14);
                {
                    uint8_t *q = *reinterpret_cast<uint8_t **>(
                        static_cast<uint8_t *>(static_cast<intptr_t>(DAT_008c9dec)) + 0x14);
                    void *vt = *reinterpret_cast<void **>(q);
                    reinterpret_cast<void (*)(int, int, int)>(
                        *reinterpret_cast<void **>(static_cast<uint8_t *>(vt) + 0x10))(
                        0, 0, DAT_007255f8);
                    reinterpret_cast<void (*)(int)>(
                        *reinterpret_cast<void **>(static_cast<uint8_t *>(vt) + 0xc))(0);
                }
                FUN_004e4580(uVar15);
                puVar12 = reinterpret_cast<uint32_t *>(DAT_008c9dec + 0x14);
                {
                    uint8_t *q = *reinterpret_cast<uint8_t **>(
                        static_cast<uint8_t *>(static_cast<intptr_t>(DAT_008c9dec)) + 0x14);
                    void *vt = *reinterpret_cast<void **>(q);
                    reinterpret_cast<void (*)(int, int, int)>(
                        *reinterpret_cast<void **>(static_cast<uint8_t *>(vt) + 0x10))(
                        0, 0, DAT_007255f8);
                    reinterpret_cast<void (*)(int)>(
                        *reinterpret_cast<void **>(static_cast<uint8_t *>(vt) + 0xc))(0);
                }
                FUN_004d9af0(DAT_008c9dec, 0x41a00000);
                if (iVar9 == 0) {
                    FUN_004c1150(apuStack_318[0], "fx_blackbeard_fire");
                    FUN_004c1150(apuStack_318[0], "fx_blackbeard_fire");
                }
                FUN_004add70(uVar14);
                FUN_00481180();
                DAT_00726a84 = DAT_00726a84 + -1;
                DAT_007263bc = *reinterpret_cast<int *>(reinterpret_cast<uint8_t *>(&DAT_007268f4) +
                                                        DAT_00726a84 * 4);
                ppuVar26 = apuStack_300 + 5;
                iVar9 = 2;
                do {
                    puVar12 = ppuVar26[-1];
                    ppuVar26 = ppuVar26 + -1;
                    pirates_obj_release(puVar12);
                    iVar9 = iVar9 + -1;
                } while (iVar9 != 0);
                ppuVar26 = apuStack_300 + 1;
                iVar9 = 3;
                do {
                    puVar12 = ppuVar26[-1];
                    ppuVar26 = ppuVar26 + -1;
                    pirates_obj_release(puVar12);
                    iVar9 = iVar9 + -1;
                } while (iVar9 != 0);
                pirates_obj_release(puVar13);
                DAT_008cacd4 = DAT_008cacd4 + -1;
                if (DAT_008cacd4 == 0) {
                    reinterpret_cast<void (*)(int)>(*_DAT_008cacd0)(1);
                }
                pirates_obj_release(puStack_33c);
                piVar10 = aiStack_2a8 + 1;
                iVar9 = 3;
                do {
                    puVar13 = reinterpret_cast<uint32_t *>(piVar10[-1]);
                    piVar10 = piVar10 + -1;
                    pirates_obj_release(puVar13);
                    iVar9 = iVar9 + -1;
                } while (iVar9 != 0);
                pirates_obj_release(puStack_344);
                pirates_obj_release(puStack_340);
                ppuVar26 = apuStack_318 + 1;
                iVar9 = 2;
                do {
                    puVar13 = ppuVar26[-1];
                    ppuVar26 = ppuVar26 + -1;
                    pirates_obj_release(puVar13);
                    iVar9 = iVar9 + -1;
                } while (iVar9 != 0);
                FUN_0040a610();
            }
        }
        else {
            switch (iVar9) {
            case 0x212:
            case 0x213:
            case 0x214:
            case 0x215:
            case 0x216:
            case 0x217:
            case 0x218:
            case 0x219:
            case 0x21a:
                iVar9 = 0;
                iVar19 = 0;
                pbVar11 = &DAT_00862018[0];
                do {
                    if ((*pbVar11 & 1) != 0) {
                        if (iVar9 == iVar24 + -0x12)
                            break;
                        iVar9 = iVar9 + 1;
                    }
                    pbVar11 = pbVar11 + 0x1c;
                    iVar19 = iVar19 + 1;
                } while (reinterpret_cast<intptr_t>(pbVar11) < 0x862114);
                FUN_004a22f0(1, 1, 0);
                FUN_004f6090("A few hours of digging uncovers @TOP10's buried treasure worth @NUM gold pieces!\n",
                             (&DAT_008cb10c)[iVar19 * 3], (&DAT_008cb110)[iVar19 * 3],
                             (&DAT_008cb114)[iVar19 * 3], (10 - iVar19) * 1000);
                FUN_00487e90();
                FUN_00452890();
                break;
            case 0x21b:
                if ((_DAT_0085a164 & 0x200000) != 0) {
                    FUN_004a22f0(1, 1, 0);
                    FUN_004f6090("'I now pronounce you man and wife - you may kiss the bride.'\n");
                    FUN_00487e90();
                    FUN_0044f150(0, 0);
                }
                break;
            case 0x21c:
            case 0x21d:
            case 0x21e:
            case 0x21f:
                FUN_004a22f0(1, 1, 0);
                FUN_004f6090("A thorough search of the legendary lost city of the @LOSTCITY reveals treasure worth over 50,000 gold pieces!\n",
                             iVar9 + -0x21c);
                FUN_00487e90();
                FUN_0044fa40(0);
                break;
            }
        }
        if (bVar27) {
            FUN_00488df0(local_2cc, 1, 0x40000000, 0, 0xffffffff, 0xffffffff, 0xffffffff, 0,
                         DAT_008c8200);
        }
    } while (!bVar6);
    if (bVar27) {
        FUN_004a78a0(1);
    }
    else {
        FUN_00488ed0(0);
        FUN_00498570();
        FUN_004a24b0();
    }
    DAT_0086c330 = 0;
    _DAT_0085a164 = _DAT_0085a164 | ((-static_cast<uint32_t>(local_329 != 0)) & 4);
    do {
        iVar9 = FUN_0042e1d0(0);
    } while (iVar9 != 0);
    DAT_0086c35c = 0;
    DAT_0086c360 = 0;
    pirates_obj_release(local_324);
    piVar10 = aiStack_2a8 + 0x15;
    iVar9 = 10;
    do {
        puVar13 = reinterpret_cast<uint32_t *>(piVar10[-1]);
        piVar10 = piVar10 + -1;
        pirates_obj_release(puVar13);
        iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    pirates_obj_release(local_320);
    piVar10 = aiStack_2a8 + 5;
    iVar9 = 4;
    do {
        puVar13 = reinterpret_cast<uint32_t *>(piVar10[-1]);
        piVar10 = piVar10 + -1;
        pirates_obj_release(puVar13);
        iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    return;
}
