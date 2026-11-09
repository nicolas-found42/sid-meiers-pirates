//
// mass_0107.cpp — reconstruction batch mass_0107 (retry)
// Target: Sid Meier's Pirates! (2004), PE32 i386
//
// Clean-room reconstruction from the Ghidra 12.2 pseudocode corpus only. Each
// definition preserves the observed field offsets, constants, call order,
// return shape and conditional structure of its listing in
// analysis/pseudocode/functions/0x*.c. No byte-match claim: MSVC 13.10.3077 is
// absent on this host, so every definition is unverified.
// Corpus labels are kept verbatim: DAT_*/PTR_*/FUN_* are not original names.
// Register receivers (EAX/ECX/EDX/ESI/EDI/EBX) become explicit parameters; no
// `this` is used anywhere in this file.
//
#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---------------------------------------------------------------------------
// External helpers referenced by the assigned listings only.
// ---------------------------------------------------------------------------
extern void*    FUN_00533c78(uint32_t size);
extern void*    thunk_FUN_00533c78(uint32_t size);
extern void*    FUN_00533db0(uint32_t size);
extern int32_t* FUN_0051bf30();
extern void     FUN_0051c040(uint32_t value);
extern void     FUN_00581300(uint32_t index, void** slot);
extern void     FUN_00524e90(void* node);
extern void     FUN_004e6420();
extern void     FUN_004f5670();
extern void     FUN_004effc0(uint16_t value);
extern uint32_t FUN_004f8e40(void* value);
extern void     FUN_004f3350();
extern void     FUN_00412f90();
extern int32_t  FUN_005f0ddc();
extern void     FUN_00551810(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t,
                             uint32_t, uint32_t, uint32_t);
extern void     FUN_005518c0(uint32_t param_1);
extern void     FUN_004a1230();
extern void     FUN_0052fe60();
extern void     FUN_0052f5d0();
extern void     FUN_0052a220();
extern void     FUN_0052a280();
extern void     FUN_0052a2e0();
extern void     FUN_0052c060();
extern void     FUN_0052c0c0();
extern void     FUN_0052bfb0();
extern void     FUN_00530090();
extern int32_t  FUN_004f5480();
extern uint32_t* FUN_0052bf10();
extern int32_t  FUN_00527eb0(void* self, int32_t param_1);
extern char     FUN_0052a4c0(uint32_t a, uint32_t b);
extern void     operator_delete(void* ptr);
extern void     operator_delete__(void* ptr);
extern "C" void* memmove(void* dst, const void* src, size_t count);

// ---------------------------------------------------------------------------
// External globals used by the listings (addresses from the corpus).
// ---------------------------------------------------------------------------
extern uint8_t  DAT_007265e0;
extern uint8_t  DAT_00727598;   // sentinel object compared by address
extern uint8_t  DAT_007275e8;   // sentinel object compared by address
extern uint8_t  DAT_00727cc8;   // sentinel object compared by address
extern int32_t* DAT_008cad3c;
extern char     DAT_008ca540;   // target buffer of the string copy at 0x527d30
extern uint32_t DAT_008cacf0;
extern uint32_t DAT_008cace8;
extern uint32_t DAT_008cacec;
extern uint32_t DAT_008cace0;
extern void*    DAT_008ecd78;

// ---------------------------------------------------------------------------
// Sibling members used below; several are defined later in this file, so the
// whole family is declared once here.
// ---------------------------------------------------------------------------
uint32_t FUN_00527000(const char* param_1 = nullptr, uint8_t param_2 = 0, int32_t in_EAX = 0);
void     FUN_00527300(void* self_in_EDI);
void     FUN_005278a0(void* self);

// ---------------------------------------------------------------------------
// Offset accessors: every observed field access goes through these so the
// original byte offsets stay visible in each definition.
// ---------------------------------------------------------------------------
static inline uint32_t& u32_at(void* base, std::size_t off)
{
    return *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(base) + off);
}

static inline uint8_t& u8_at(void* base, std::size_t off)
{
    return *reinterpret_cast<uint8_t*>(static_cast<uint8_t*>(base) + off);
}

static inline uint16_t& u16_at(void* base, std::size_t off)
{
    return *reinterpret_cast<uint16_t*>(static_cast<uint8_t*>(base) + off);
}

// ---------------------------------------------------------------------------
// Guest-address accessors: the listings address memory by 32-bit PE32 value.
// ---------------------------------------------------------------------------
static inline void* ptr_at(uint32_t addr)
{
    return reinterpret_cast<void*>(static_cast<uintptr_t>(addr));
}

static inline uint32_t& u32_va(uint32_t addr)
{
    return *static_cast<uint32_t*>(ptr_at(addr));
}

static inline uint8_t& u8_va(uint32_t addr)
{
    return *static_cast<uint8_t*>(ptr_at(addr));
}

static inline uint16_t& u16_va(uint32_t addr)
{
    return *static_cast<uint16_t*>(ptr_at(addr));
}

// The listing's CONCAT11(high, low): 16-bit value with `high` in the upper byte.
static inline uint16_t CONCAT11(uint8_t high, uint8_t low)
{
    return static_cast<uint16_t>((static_cast<uint16_t>(high) << 8) | low);
}

// ---------------------------------------------------------------------------
// 0x005265a0 — observed shape
// Fills the cell table at param_3: clears the element array (count at +0xc) and
// the populated count at +0x10, then for every outer index (receiver slot 5)
// and inner index (slot 6) asks vtable slot +0xc for a key string and four
// dwords. A successful non-empty key whose table is still empty allocates a
// zeroed (slot 0x15 * 16)-byte record and stores it at the index held in the
// byte local_3b. Each key character is then mapped through param_4's vtable
// (slot +4 hash, slot +8 compare); when no table entry matches, a block is
// allocated per (local_3b, local_3a) pair every 4 columns (or every 2 once the
// block index is non-zero), and the four collected dwords are written into the
// record selected by those two bytes at stride 0x10 (block 0) or 0x8.
// ---------------------------------------------------------------------------
void FUN_005265a0(uint32_t param_1, uint32_t* param_2, uint32_t param_3, int32_t* param_4,
                  int32_t* self)
{
    int32_t* ecx = self;                        // in_ECX
    uint32_t iVar3 = param_3;                   // table pointer, saved by the listing
    uint32_t* tbl = reinterpret_cast<uint32_t*>(ptr_at(iVar3));
    uint32_t* cells = reinterpret_cast<uint32_t*>(ptr_at(tbl[1]));
    uint32_t uVar5 = 0;
    uint8_t  local_3b = 0;
    uint8_t  local_3a = 0;
    bool     bVar2 = true;
    uint32_t uStack_30 = 0;
    uint32_t uStack_1c = 0;
    uint32_t uStack_18 = 0;
    char     local_24[8] = {};
    uint32_t local_14[5] = {};
    char     cVar1 = 0;
    char     cVar4 = 0;
    int32_t  iVar6 = 0;
    int32_t  iVar11 = 0;
    int32_t  iVar12 = 0;
    uint32_t uVar13 = 0;
    uint16_t uVar9 = 0;
    uint8_t  bVar10 = 0;
    uint32_t* puVar7 = nullptr;
    uint32_t* puVar8 = nullptr;

    if (tbl[3] != 0) {
        do {
            cells[uVar5] = 0;
            uVar5 = uVar5 + 1;
        } while (uVar5 < tbl[3]);
    }
    tbl[3] = 0;
    tbl[4] = 0;
    FUN_004e6420();
    *param_2 = 0;

    if (ecx[5] != 0) {
        // Ghidra reuses param_2 and param_3 as the two loop indices after
        // *param_2 = 0; they are modelled here as distinct counters.
        uint32_t iOuter = 0;
        do {
            uint32_t iInner = 0;
            if (ecx[6] != 0) {
                do {
                    void** vt = reinterpret_cast<void**>(ptr_at(static_cast<uint32_t>(ecx[0])));
                    uVar5 = reinterpret_cast<uint32_t (*)(uint32_t, uint32_t, char*, uint32_t*,
                                                         uint32_t, int)>(vt[3])(
                        iOuter, iInner, local_24, local_14, param_1, 1);
                    if ((tbl[3] == 0) && (uVar5 != 0) && (local_24[0] != '\0')) {
                        iVar11 = ecx[0x15];
                        iVar6 = static_cast<int32_t>(reinterpret_cast<intptr_t>(
                            thunk_FUN_00533c78(static_cast<uint32_t>(iVar11 << 4))));
                        iVar12 = 0;
                        if (iVar6 != 0) {
                            if (-1 < iVar11 - 1) {
                                puVar7 = reinterpret_cast<uint32_t*>(ptr_at(
                                    static_cast<uint32_t>(iVar6) + 8));
                                do {
                                    puVar7[-2] = 0;
                                    puVar7[-1] = 0;
                                    puVar7[0] = 0;
                                    puVar7[1] = 0;
                                    puVar7 = puVar7 + 4;
                                    iVar11 = iVar11 + -1;
                                } while (iVar11 != 0);
                            }
                            iVar12 = iVar6;
                        }
                        uVar13 = static_cast<uint32_t>(local_3b);
                        if ((uVar13 < tbl[2]) || (FUN_004f5670(), uVar13 < tbl[2])) {
                            if (uVar13 < tbl[3]) {
                                if (iVar12 == 0) {
                                    if (cells[uVar13] != 0) {
                                        iVar11 = static_cast<int32_t>(tbl[4]) - 1;
                                        goto LAB_005266dd;
                                    }
                                } else if (cells[uVar13] == 0) {
                                    iVar11 = static_cast<int32_t>(tbl[4]) + 1;
                                LAB_005266dd:
                                    tbl[4] = static_cast<uint32_t>(iVar11);
                                }
                            } else {
                                tbl[3] = uVar13 + 1;
                                if (iVar12 != 0) {
                                    iVar11 = static_cast<int32_t>(tbl[4]) + 1;
                                    goto LAB_005266dd;
                                }
                            }
                            cells[uVar13] = static_cast<uint32_t>(iVar12);
                        }
                    }
                    uStack_30 = 0;
                    if (uVar5 != 0) {
                        do {
                            cVar1 = local_24[uStack_30];
                            void** mvt = reinterpret_cast<void**>(
                                ptr_at(static_cast<uint32_t>(*param_4)));
                            iVar11 = reinterpret_cast<int32_t (*)(char)>(mvt[1])(cVar1);
                            puVar7 = reinterpret_cast<uint32_t*>(ptr_at(
                                static_cast<uint32_t>(param_4[2]) +
                                static_cast<uint32_t>(iVar11) * 4));
                            for (; puVar7 != nullptr;
                                 puVar7 = reinterpret_cast<uint32_t*>(
                                     ptr_at(static_cast<uint32_t>(*puVar7)))) {
                                cVar4 = reinterpret_cast<char (*)(char, uint8_t)>(mvt[2])(
                                    cVar1, reinterpret_cast<uint8_t*>(puVar7)[4]);
                                if (cVar4 != '\0') {
                                    uVar9 = u16_va(static_cast<uint32_t>(
                                                       reinterpret_cast<uintptr_t>(puVar7)) + 6);
                                    bVar10 = static_cast<uint8_t>(uVar9 >> 8);
                                    goto LAB_00526855;
                                }
                            }
                            if ((!bVar2) &&
                                (((local_3a = static_cast<uint8_t>(local_3a + 1),
                                   3 < local_3a && (local_3b == 0)) ||
                                  ((1 < local_3a && (local_3b != 0)))))) {
                                local_3b = static_cast<uint8_t>(local_3b + 1);
                                local_3a = 0;
                                puVar7 = reinterpret_cast<uint32_t*>(thunk_FUN_00533c78(
                                    static_cast<uint32_t>(ecx[0x15] * 8)));
                                uVar13 = 0;
                                if (ecx[0x15] != 0) {
                                    uStack_1c = 0;
                                    uStack_18 = 0;
                                    puVar8 = puVar7;
                                    do {
                                        puVar8[0] = 0;
                                        puVar8[1] = 0;
                                        uVar13 = uVar13 + 1;
                                        puVar8 = puVar8 + 2;
                                    } while (uVar13 < static_cast<uint32_t>(ecx[0x15]));
                                }
                                uVar13 = tbl[3];
                                if ((uVar13 < tbl[2]) || (FUN_004f5670(), uVar13 < tbl[2])) {
                                    if (uVar13 < tbl[3]) {
                                        if (puVar7 == nullptr) {
                                            if (cells[uVar13] != 0) {
                                                iVar11 = static_cast<int32_t>(tbl[4]) - 1;
                                                goto LAB_00526823;
                                            }
                                        } else if (cells[uVar13] == 0) {
                                            iVar11 = static_cast<int32_t>(tbl[4]) + 1;
                                        LAB_00526823:
                                            tbl[4] = static_cast<uint32_t>(iVar11);
                                        }
                                    } else {
                                        tbl[3] = uVar13 + 1;
                                        if (puVar7 != nullptr) {
                                            iVar11 = static_cast<int32_t>(tbl[4]) + 1;
                                            goto LAB_00526823;
                                        }
                                    }
                                    cells[uVar13] = static_cast<uint32_t>(
                                        reinterpret_cast<uintptr_t>(puVar7));
                                }
                            }
                            bVar2 = false;
                            FUN_004effc0(CONCAT11(local_3b, local_3a));
                            uVar9 = static_cast<uint16_t>(local_3a);
                            bVar10 = local_3b;
                        LAB_00526855:
                            iVar11 = ecx[6] * static_cast<int32_t>(iOuter) +
                                     static_cast<int32_t>(iInner);
                            if (local_24[uStack_30] == '\0') {
                                local_14[uStack_30] = 0;
                            }
                            uVar9 = static_cast<uint16_t>(uVar9 & 0xff);
                            if (bVar10 == 0) {
                                iVar12 = static_cast<int32_t>(cells[0]);
                                switch (uVar9) {
                                case 0:
                                    u32_va(static_cast<uint32_t>(iVar12) +
                                           static_cast<uint32_t>(iVar11) * 0x10) =
                                        local_14[uStack_30];
                                    break;
                                case 1:
                                    u32_va(static_cast<uint32_t>(iVar12) + 4 +
                                           static_cast<uint32_t>(iVar11) * 0x10) =
                                        local_14[uStack_30];
                                    break;
                                case 2:
                                    u32_va(static_cast<uint32_t>(iVar12) + 8 +
                                           static_cast<uint32_t>(iVar11) * 0x10) =
                                        local_14[uStack_30];
                                    break;
                                case 3:
                                    u32_va(static_cast<uint32_t>(iVar12) + 0xc +
                                           static_cast<uint32_t>(iVar11) * 0x10) =
                                        local_14[uStack_30];
                                    break;
                                default:
                                    break;
                                }
                            } else {
                                iVar12 = static_cast<int32_t>(cells[bVar10]);
                                if (uVar9 == 0) {
                                    u32_va(static_cast<uint32_t>(iVar12) +
                                           static_cast<uint32_t>(iVar11) * 8) =
                                        local_14[uStack_30];
                                } else if (uVar9 == 1) {
                                    u32_va(static_cast<uint32_t>(iVar12) + 4 +
                                           static_cast<uint32_t>(iVar11) * 8) =
                                        local_14[uStack_30];
                                }
                            }
                            uStack_30 = uStack_30 + 1;
                        } while (uStack_30 < uVar5);
                    }
                    iInner = iInner + 1;
                } while (iInner < static_cast<uint32_t>(ecx[6]));
            }
            iOuter = iOuter + 1;
        } while (iOuter < static_cast<uint32_t>(ecx[5]));
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x00526940 — observed shape
// Cache/find routine. Lazily creates the DAT_008cad3c container (0x10 bytes,
// then FUN_0051bf30). Walks the object's list at self->[2]+0xb8 (count +0xc0)
// and, for each element, resolves a cast through the element's vtable slot +4
// to the DAT_00727598 interface; the resolved pointer is refcount-released
// before being adopted. A second cast (DAT_007275e8) yields a holder whose
// +0x44 object supplies the starting key, +0x10. Each iteration looks the key
// up in DAT_008cad3c (slot +4 hash, slot +8 compare) and, on miss, allocates a
// 0x18-byte node initialised with vtable 0x712780 + refcount and inserts it
// through FUN_00581300 once capacity (FUN_0051c040) allows. On hit, it takes
// the hit node's +4 vector (count +0xc), scans for the first non-null slot,
// resolves the same DAT_007275e8 holder for that object, and compares the two
// holders' +0x44 key objects slot by slot; a differing +4 field restarts the
// search with the key advanced by 0xe.
// ---------------------------------------------------------------------------
void FUN_00526940(void* self)
{
    int32_t* ecx = static_cast<int32_t*>(self);   // in_ECX
    uint32_t* puVar11 = nullptr;
    uint32_t* local_14 = nullptr;
    int32_t  local_4 = static_cast<int32_t>(reinterpret_cast<intptr_t>(self));
    uint32_t local_8 = 0;
    uint32_t uVar8 = 0;
    uint32_t uStack_c = 0;
    int32_t  iStack_10 = 0;
    int32_t  iVar1 = 0;
    int32_t  iVar4 = 0;
    int32_t  iVar7 = 0;
    int32_t  iVar9 = 0;
    int32_t  iVar10 = 0;
    int32_t* piVar6 = nullptr;
    uint32_t* puVar5 = nullptr;
    char     cVar3 = 0;
    bool     bVar2 = false;

    if (DAT_008cad3c == nullptr) {
        iVar4 = static_cast<int32_t>(reinterpret_cast<intptr_t>(FUN_00533c78(0x10)));
        if (iVar4 == 0) {
            DAT_008cad3c = nullptr;
        } else {
            DAT_008cad3c = FUN_0051bf30();
        }
    }
    iVar4 = ecx[2];
    local_8 = 0;
    if (u32_at(ptr_at(static_cast<uint32_t>(iVar4)), 0xc0) != 0) {
        uVar8 = 0;
        if (u32_at(ptr_at(static_cast<uint32_t>(iVar4)), 0xc0) == 0) {
            goto LAB_00526c0b;
        }
        do {
            uVar8 = local_8;
            piVar6 = reinterpret_cast<int32_t*>(ptr_at(
                u32_at(ptr_at(static_cast<uint32_t>(iVar4)), 0xb8) + local_8 * 4));
            if (piVar6 != nullptr) {
                void** vt = reinterpret_cast<void**>(ptr_at(static_cast<uint32_t>(*piVar6)));
                puVar5 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(
                    reinterpret_cast<void* (*)(void)>(vt[1])()));
                for (; puVar5 != nullptr;
                     puVar5 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(puVar5[1]))) {
                    if (puVar5 == reinterpret_cast<uint32_t*>(&DAT_00727598)) {
                        puVar5 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(
                            reinterpret_cast<void* (*)(void)>(vt[1])()));
                        goto joined_r0x005269e0;
                    }
                }
            }
        LAB_00526c0b:
            iVar4 = u32_at(ptr_at(static_cast<uint32_t>(local_4)), 8);
            local_8 = uVar8 + 1;
        } while (local_8 < u32_at(ptr_at(static_cast<uint32_t>(iVar4)), 0xc0));
        if (puVar11 != nullptr) {
            piVar6 = reinterpret_cast<int32_t*>(puVar11 + 1);
            *piVar6 = *piVar6 + -1;
            if (*piVar6 == 0) {
                void** vt = reinterpret_cast<void**>(ptr_at(*puVar11));
                reinterpret_cast<void (*)(int)>(vt[0])(1);
            }
        }
    }
    return;

joined_r0x005269e0:
    if (puVar5 == nullptr) {
        goto LAB_005269f0;
    }
    if (puVar5 == reinterpret_cast<uint32_t*>(&DAT_00727598)) {
        bVar2 = true;
        goto LAB_005269f2;
    }
    puVar5 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(puVar5[1]));
    goto joined_r0x005269e0;

LAB_005269f0:
    bVar2 = false;
LAB_005269f2:
    puVar5 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(
        (0u - static_cast<uint32_t>(bVar2)) &
        static_cast<uint32_t>(reinterpret_cast<uintptr_t>(piVar6))));
    if (puVar11 != puVar5) {
        if (puVar11 != nullptr) {
            piVar6 = reinterpret_cast<int32_t*>(puVar11 + 1);
            *piVar6 = *piVar6 + -1;
            if (*piVar6 == 0) {
                void** vt = reinterpret_cast<void**>(ptr_at(*puVar11));
                reinterpret_cast<void (*)(int)>(vt[0])(1);
            }
        }
        local_14 = puVar5;
        if (puVar5 != nullptr) {
            puVar5[1] = puVar5[1] + 1;
        }
    }
    piVar6 = reinterpret_cast<int32_t*>(FUN_00533db0(8));
    if (piVar6 == nullptr) {
        uStack_c = 0;
    } else {
        void** vt = reinterpret_cast<void**>(ptr_at(static_cast<uint32_t>(*piVar6)));
        for (puVar11 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(
                 reinterpret_cast<void* (*)(void)>(vt[1])()));
             puVar11 != nullptr;
             puVar11 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(puVar11[1]))) {
            if (puVar11 == reinterpret_cast<uint32_t*>(&DAT_007275e8)) {
                bVar2 = true;
                goto LAB_00526a50;
            }
        }
        bVar2 = false;
    LAB_00526a50:
        uStack_c = (0u - static_cast<uint32_t>(bVar2)) &
                   static_cast<uint32_t>(reinterpret_cast<uintptr_t>(piVar6));
    }
    if (u32_at(ptr_at(uStack_c), 0x44) == 0) {
        iStack_10 = 0;
    } else {
        iStack_10 = static_cast<int32_t>(u32_at(ptr_at(u32_at(ptr_at(uStack_c), 0x44)), 0x10));
    }
    do {
        iVar4 = iStack_10;
        piVar6 = DAT_008cad3c;
        {
            void** vt = reinterpret_cast<void**>(ptr_at(static_cast<uint32_t>(*DAT_008cad3c)));
            iVar7 = reinterpret_cast<int32_t (*)(int32_t)>(vt[1])(iStack_10);
        }
        puVar11 = reinterpret_cast<uint32_t*>(
            ptr_at(static_cast<uint32_t>(piVar6[2]) + static_cast<uint32_t>(iVar7) * 4));
        for (;;) {
            if (puVar11 == nullptr) {
                puVar11 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x18));
                if (puVar11 == nullptr) {
                    puVar11 = nullptr;
                } else {
                    puVar11[0] = 0x00712780;    // &PTR_FUN_00712780
                    puVar11[2] = 0;
                    puVar11[5] = 1;
                    puVar11[3] = 0;
                    puVar11[4] = 0;
                    puVar11[1] = 0;
                }
                uVar8 = puVar11[3];
                puVar11[5] = 5;
                if (puVar11[2] <= uVar8) {
                    FUN_0051c040(uVar8 + 5);
                }
                FUN_00581300(uVar8, reinterpret_cast<void**>(&local_14));
                u8_at(local_14, 0x20) = static_cast<uint8_t>(u8_at(local_14, 0x20) | 1);
                FUN_00524e90(puVar11);
                goto LAB_00526c03;
            }
            {
                void** vt = reinterpret_cast<void**>(ptr_at(static_cast<uint32_t>(*piVar6)));
                cVar3 = reinterpret_cast<char (*)(int32_t, uint32_t)>(vt[2])(iVar4, puVar11[1]);
            }
            if (cVar3 != '\0') {
                break;
            }
            puVar11 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(puVar11[0]));
        }
        iVar4 = static_cast<int32_t>(puVar11[2]);
        uVar8 = 0;
        if (u32_at(ptr_at(static_cast<uint32_t>(iVar4)), 0xc) != 0) {
            piVar6 = reinterpret_cast<int32_t*>(ptr_at(
                u32_at(ptr_at(static_cast<uint32_t>(iVar4)), 4)));
            do {
                if (*piVar6 != 0) {
                    break;
                }
                uVar8 = uVar8 + 1;
                piVar6 = piVar6 + 1;
            } while (uVar8 < u32_at(ptr_at(static_cast<uint32_t>(iVar4)), 0xc));
        }
        piVar6 = reinterpret_cast<int32_t*>(FUN_00533db0(8));
        if (piVar6 == nullptr) {
            uVar8 = 0;
        } else {
            void** vt = reinterpret_cast<void**>(ptr_at(static_cast<uint32_t>(*piVar6)));
            for (puVar11 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(
                     reinterpret_cast<void* (*)(void)>(vt[1])()));
                 puVar11 != nullptr;
                 puVar11 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(puVar11[1]))) {
                if (puVar11 == reinterpret_cast<uint32_t*>(&DAT_007275e8)) {
                    bVar2 = true;
                    goto LAB_00526b30;
                }
            }
            bVar2 = false;
        LAB_00526b30:
            uVar8 = (0u - static_cast<uint32_t>(bVar2)) &
                    static_cast<uint32_t>(reinterpret_cast<uintptr_t>(piVar6));
        }
        iVar7 = static_cast<int32_t>(u32_at(ptr_at(uVar8), 0x44));
        if (iVar7 == 0) {
            iVar10 = 0;
        } else {
            iVar10 = static_cast<int32_t>(u32_at(ptr_at(static_cast<uint32_t>(iVar7)), 0x10));
        }
        iVar1 = static_cast<int32_t>(u32_at(ptr_at(uStack_c), 0x44));
        if (iVar1 == 0) {
            iVar9 = 0;
        } else {
            iVar9 = static_cast<int32_t>(u32_at(ptr_at(static_cast<uint32_t>(iVar1)), 0x10));
        }
        if (iVar10 == iVar9) {
            uVar8 = 0;
        LAB_00526b60:
            if ((iVar7 == 0) ||
                (u32_at(ptr_at(static_cast<uint32_t>(iVar7)), 0x10) <= uVar8)) {
                uVar8 = u32_at(ptr_at(static_cast<uint32_t>(iVar4)), 0xc);
                if (u32_at(ptr_at(static_cast<uint32_t>(iVar4)), 8) <= uVar8) {
                    FUN_0051c040(u32_at(ptr_at(static_cast<uint32_t>(iVar4)), 0x14) + uVar8);
                }
                FUN_00581300(uVar8, reinterpret_cast<void**>(&local_14));
            LAB_00526c03:
                puVar11 = local_14;
                uVar8 = local_8;
                goto LAB_00526c0b;
            }
            if ((iVar1 == 0) ||
                (u32_at(ptr_at(static_cast<uint32_t>(iVar1)), 0xc) <= uVar8)) {
                iVar10 = 0;
            } else {
                iVar10 = static_cast<int32_t>(u32_va(
                    u32_at(ptr_at(static_cast<uint32_t>(iVar1)), 4) + uVar8 * 4));
            }
            if (uVar8 < u32_at(ptr_at(static_cast<uint32_t>(iVar7)), 0xc)) {
                iVar9 = static_cast<int32_t>(u32_va(
                    u32_at(ptr_at(static_cast<uint32_t>(iVar7)), 4) + uVar8 * 4));
            } else {
                iVar9 = 0;
            }
            if (u32_at(ptr_at(static_cast<uint32_t>(iVar10)), 4) ==
                u32_at(ptr_at(static_cast<uint32_t>(iVar9)), 4)) {
                break;
            }
        }
        iStack_10 = iStack_10 + 0xe;
    } while (true);
    uVar8 = uVar8 + 1;
    goto LAB_00526b60;
}

// ---------------------------------------------------------------------------
// 0x00526c40 — observed shape
// Mirror of 0x526940's lookup for an existing DAT_008cad3c entry: walks the
// element list at self->[2]+0xb8 (count +0xc0), resolves the DAT_00727598
// interface through the element vtable slot +4, and adopts the pointer after
// releasing the previous reference. The DAT_007275e8 holder of the last
// element supplies the starting key (+0x44 object, +0x10). For each key the
// container is searched (slot +4 hash, slot +8 compare); a hit's +4 vector is
// scanned for an element whose first dword equals the adopted interface, in
// which case FUN_00581300(index, 0) clears that entry and the scan continues
// with the key advanced by 0xe.
// ---------------------------------------------------------------------------
void FUN_00526c40(void* self)
{
    int32_t* ecx = static_cast<int32_t*>(self);   // in_ECX
    int32_t  local_4 = static_cast<int32_t>(reinterpret_cast<intptr_t>(self));
    int32_t  iVar8 = ecx[2];
    uint32_t* puVar9 = nullptr;
    uint32_t* local_10 = nullptr;
    uint32_t local_c = 0;
    uint32_t uVar10 = 0;
    int32_t* piVar4 = nullptr;
    uint32_t* puVar3 = nullptr;
    uint32_t uVar5 = 0;
    uint32_t uVar7 = 0;
    int32_t  iVar6 = 0;
    uint32_t uStack_8 = 0;
    uint8_t  bVar1 = 0;
    char     cVar2 = 0;
    int32_t  ecxCopy = local_4;                   // the listing's local in_ECX copy

    if (u32_at(ptr_at(static_cast<uint32_t>(iVar8)), 0xc0) != 0) {
        uVar10 = 0;
        if (u32_at(ptr_at(static_cast<uint32_t>(iVar8)), 0xc0) == 0) {
            goto LAB_00526d76;
        }
        do {
            piVar4 = reinterpret_cast<int32_t*>(ptr_at(
                u32_at(ptr_at(static_cast<uint32_t>(iVar8)), 0xb8) + local_c * 4));
            uVar10 = local_c;
            if (piVar4 != nullptr) {
                void** vt = reinterpret_cast<void**>(ptr_at(static_cast<uint32_t>(*piVar4)));
                puVar3 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(
                    reinterpret_cast<void* (*)(void)>(vt[1])()));
                for (; puVar3 != nullptr;
                     puVar3 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(puVar3[1]))) {
                    if (puVar3 == reinterpret_cast<uint32_t*>(&DAT_00727598)) {
                        puVar3 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(
                            reinterpret_cast<void* (*)(void)>(vt[1])()));
                        goto joined_r0x00526cae;
                    }
                }
            }
        LAB_00526d76:
            iVar8 = u32_at(ptr_at(static_cast<uint32_t>(local_4)), 8);
            local_c = uVar10 + 1;
        } while (local_c < u32_at(ptr_at(static_cast<uint32_t>(iVar8)), 0xc0));
        if (puVar9 != nullptr) {
            piVar4 = reinterpret_cast<int32_t*>(puVar9 + 1);
            *piVar4 = *piVar4 + -1;
            if (*piVar4 == 0) {
                void** vt = reinterpret_cast<void**>(ptr_at(*puVar9));
                reinterpret_cast<void (*)(int)>(vt[0])(1);
            }
        }
    }
    return;

joined_r0x00526cae:
    if (puVar3 == nullptr) {
        goto LAB_00526cbe;
    }
    if (puVar3 == reinterpret_cast<uint32_t*>(&DAT_00727598)) {
        bVar1 = 1;
        goto LAB_00526cc0;
    }
    puVar3 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(puVar3[1]));
    goto joined_r0x00526cae;

LAB_00526cbe:
    bVar1 = 0;
LAB_00526cc0:
    puVar3 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(
        (0u - static_cast<uint32_t>(bVar1)) &
        static_cast<uint32_t>(reinterpret_cast<uintptr_t>(piVar4))));
    if (puVar9 != puVar3) {
        if (puVar9 != nullptr) {
            piVar4 = reinterpret_cast<int32_t*>(puVar9 + 1);
            *piVar4 = *piVar4 + -1;
            if (*piVar4 == 0) {
                void** vt = reinterpret_cast<void**>(ptr_at(*puVar9));
                reinterpret_cast<void (*)(int)>(vt[0])(1);
            }
        }
        puVar9 = puVar3;
        local_10 = puVar3;
        if (puVar3 != nullptr) {
            puVar3[1] = puVar3[1] + 1;
        }
    }
    piVar4 = reinterpret_cast<int32_t*>(FUN_00533db0(8));
    if (piVar4 == nullptr) {
        uVar5 = 0;
    } else {
        void** vt = reinterpret_cast<void**>(ptr_at(static_cast<uint32_t>(*piVar4)));
        for (puVar3 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(
                 reinterpret_cast<void* (*)(void)>(vt[1])()));
             puVar3 != nullptr;
             puVar3 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(puVar3[1]))) {
            if (puVar3 == reinterpret_cast<uint32_t*>(&DAT_007275e8)) {
                bVar1 = 1;
                goto LAB_00526d20;
            }
        }
        bVar1 = 0;
    LAB_00526d20:
        uVar5 = (0u - static_cast<uint32_t>(bVar1)) &
                static_cast<uint32_t>(reinterpret_cast<uintptr_t>(piVar4));
    }
    if (u32_at(ptr_at(uVar5), 0x44) == 0) {
        iVar8 = 0;
    } else {
        iVar8 = static_cast<int32_t>(u32_at(ptr_at(u32_at(ptr_at(uVar5), 0x44)), 0x10));
    }
    do {
        for (;;) {
            piVar4 = DAT_008cad3c;
            {
                void** vt = reinterpret_cast<void**>(ptr_at(static_cast<uint32_t>(*DAT_008cad3c)));
                iVar6 = reinterpret_cast<int32_t (*)(int32_t)>(vt[1])(iVar8);
            }
            puVar3 = reinterpret_cast<uint32_t*>(
                ptr_at(static_cast<uint32_t>(piVar4[2]) + static_cast<uint32_t>(iVar6) * 4));
            ecxCopy = local_4;
            for (;;) {
                local_4 = ecxCopy;
                if (puVar3 == nullptr) {
                    goto LAB_00526d76;
                }
                {
                    void** vt = reinterpret_cast<void**>(
                        ptr_at(static_cast<uint32_t>(*piVar4)));
                    cVar2 = reinterpret_cast<char (*)(int32_t, uint32_t)>(vt[2])(iVar8, puVar3[1]);
                }
                if (cVar2 != '\0') {
                    break;
                }
                puVar3 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(*puVar3));
                ecxCopy = local_4;
            }
            uVar5 = u32_at(ptr_at(puVar3[2]), 0xc);
            uVar7 = 0;
            puVar9 = local_10;
            if (uVar5 != 0) {
                break;
            }
        LAB_00526de8:
            iVar8 = iVar8 + 0xe;
        }
        puVar3 = reinterpret_cast<uint32_t*>(ptr_at(u32_at(ptr_at(puVar3[2]), 4)));
        do {
            if ((*puVar3 != 0) && (reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(*puVar3)) ==
                                   local_10)) {
                uStack_8 = 0;
                FUN_00581300(uVar7, reinterpret_cast<void**>(&uStack_8));
                goto LAB_00526de8;
            }
            uVar7 = uVar7 + 1;
            puVar3 = puVar3 + 1;
        } while (uVar7 < uVar5);
        iVar8 = iVar8 + 0xe;
    } while (true);
}

// ---------------------------------------------------------------------------
// 0x00526e00 — observed shape
// Destructor: installs vtable 0x712d5c, frees the owned pointer at [1], and
// frees the object itself when bit 0 of the flag byte is set.
// ---------------------------------------------------------------------------
void FUN_00526e00(void* self, uint8_t param_1)
{
    u32_at(self, 0) = 0x00712d5c;                 // &PTR_FUN_00712d5c
    operator_delete__(reinterpret_cast<void*>(u32_at(self, 4)));
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x00526e30 — observed shape
// Destructor: installs vtable 0x712d60, frees the owned pointer at [1], and
// frees the object itself when bit 0 of the flag byte is set.
// ---------------------------------------------------------------------------
void FUN_00526e30(void* self, uint8_t param_1)
{
    u32_at(self, 0) = 0x00712d60;                 // &PTR_FUN_00712d60
    operator_delete__(reinterpret_cast<void*>(u32_at(self, 4)));
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x00526e60 — observed shape
// Constructor: forwards the nine arguments to FUN_00551810 (the seventh stack
// slot comes from EDX), installs vtable 0x712d70, records the CL byte at +0xcd,
// zeroes +0xcc and +0xce, and allocates DAT_007265e0 * CL * 0xc bytes of
// coefficient records at +0xd0. The first record is {0, EAX*EAX,
// (2*EAX-2)*(EAX-1)}; every further record i uses the FUN_005f0ddc() value
// (v-1)/2 with v = i, storing prev*3 + prev2, v*v, and (v-1+v2)*v2 where
// v2 = (i-1)/2+1.
// ---------------------------------------------------------------------------
void FUN_00526e60(uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4,
                  uint32_t param_5, uint32_t param_6, uint32_t param_7, uint32_t param_8,
                  uint32_t in_EDX, int32_t in_EAX, uint8_t in_CL, void* self_in_ESI)
{
    uint32_t* esi = static_cast<uint32_t*>(self_in_ESI);   // unaff_ESI
    FUN_00551810(param_1, param_2, param_3, param_4, param_5, param_6, in_EDX, param_7, param_8);
    uint32_t uVar2 = static_cast<uint32_t>(DAT_007265e0);
    esi[0] = 0x00712d70;                          // &PTR_FUN_00712d70
    u8_at(esi, 0xcd) = in_CL;
    u8_at(esi, 0xcc) = 0;                         // listing's `unaff_ESI + 0x33` dwords
    u8_at(esi, 0xce) = 0;
    uint32_t* puVar3 = reinterpret_cast<uint32_t*>(
        thunk_FUN_00533c78(uVar2 * static_cast<uint32_t>(in_CL) * 0xc));
    esi[0x34] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar3));
    puVar3[0] = 0;
    u32_va(esi[0x34] + 4) = static_cast<uint32_t>(in_EAX * in_EAX);
    u32_va(esi[0x34] + 8) = static_cast<uint32_t>((in_EAX * 2 + -2) * (in_EAX + -1));
    int32_t iVar7 = 1;
    if (1 < static_cast<int32_t>(u8_at(esi, 0xcd))) {
        int32_t iVar6 = 0xc;
        do {
            uint32_t rec = esi[0x34] + static_cast<uint32_t>(iVar6);
            int32_t iVar4 = FUN_005f0ddc();
            iVar4 = (iVar4 + -1) / 2;
            int32_t iVar5 = iVar4 + 1;
            u32_va(rec) = u32_va(rec - 4) * 3 + u32_va(rec - 0xc);
            u32_va(rec + 4) = static_cast<uint32_t>(iVar5 * iVar5);
            u32_va(rec + 8) = static_cast<uint32_t>((iVar4 + -1 + iVar5) * iVar4);
            iVar7 = iVar7 + 1;
            iVar6 = iVar6 + 0xc;
        } while (iVar7 < static_cast<int32_t>(u8_at(esi, 0xcd)));
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x00526f70 — observed shape
// Clamps the selected index at +0xce below the record count at +0xcd, then
// copies the 12-byte record at (base at +0xd0) + index*0xc into the object at
// +0xbc: when that object's +0x38 field is non-null, its vtable is scanned for
// the DAT_00727cc8 interface, whose +0x3c word receives the record's +8 word
// and whose +0x30 field receives the record's first dword; finally forwards
// param_1 to FUN_005518c0.
// ---------------------------------------------------------------------------
void FUN_00526f70(void* self, uint32_t param_1)
{
    if (u8_at(self, 0xcd) <= u8_at(self, 0xce)) {
        u8_at(self, 0xce) = static_cast<uint8_t>(u8_at(self, 0xcd) - 1);
    }
    int32_t* piVar2 = reinterpret_cast<int32_t*>(
        ptr_at(u32_at(self, 0xbc)));
    int32_t iVar3 = piVar2[0xe];
    uint32_t* puVar1 = reinterpret_cast<uint32_t*>(
        ptr_at(u32_at(self, 0xd0) + static_cast<uint32_t>(u8_at(self, 0xce)) * 0xc));
    if (iVar3 != 0) {
        void** vt = reinterpret_cast<void**>(ptr_at(static_cast<uint32_t>(*piVar2)));
        for (uint32_t* puVar4 = reinterpret_cast<uint32_t*>(
                 static_cast<uintptr_t>(reinterpret_cast<void* (*)(void)>(vt[1])()));
             puVar4 != nullptr;
             puVar4 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(puVar4[1]))) {
            if (puVar4 == reinterpret_cast<uint32_t*>(&DAT_00727cc8)) {
                u16_at(piVar2, 0x3c) = u16_at(puVar1, 8);
                break;
            }
        }
        u32_at(ptr_at(static_cast<uint32_t>(iVar3)), 0x30) = *puVar1;
    }
    FUN_005518c0(param_1);
    return;
}

// ---------------------------------------------------------------------------
// 0x00527000 — observed shape
// Audio/log gate: returns 0 when DAT_008cacf0 is clear, or when the in_EAX
// handle is non-zero while both DAT_008cace8 and DAT_008cacec are clear;
// otherwise forwards the address of the byte parameter to FUN_004f8e40.
// The corpus calls this with the message pointer as the only stack argument,
// so the remaining parameters default.
// ---------------------------------------------------------------------------
uint32_t FUN_00527000(const char* param_1, uint8_t param_2, int32_t in_EAX)
{
    (void)param_1;
    if ((DAT_008cacf0 == 0) || ((in_EAX != 0 && (DAT_008cace8 == 0 && DAT_008cacec == 0)))) {
        return 0;
    }
    return FUN_004f8e40(&param_2);
}

// ---------------------------------------------------------------------------
// 0x00527040 — observed shape
// Constructor: installs vtable 0x712e08 and the DAT_008cacd0-owned string
// owner at [0x96], calls FUN_004a1230, zeroes the flag/counter fields listed
// below, and initialises five 0x4c-byte animation slots from [0x170] onwards
// (two emitter blocks released and cleared, unity/negative-unity floats at
// +0x14/+0x18/+0x28/+0x2c and bytes at +0x1c..+0x1e). Finally allocates the
// 0x68-byte helper object, installs vtable 0x713068 and calls
// FUN_00527300 on the same receiver.
// ---------------------------------------------------------------------------
void FUN_00527040(void* self)
{
    uint32_t* p = static_cast<uint32_t*>(self);   // in_EAX
    p[0] = 0x00712e08;                            // &PTR_LAB_00712e08
    p[0x96] = 0x008cacd0;                         // &DAT_008cacd0
    FUN_004a1230();
    u8_at(self, 0x264) = 0;                       // listing's `in_EAX + 0x99` dwords
    u8_at(self, 0x265) = 0;
    p[0x9a] = 0;
    p[0x9b] = 0;
    p[0x9c] = 0;
    p[0x9d] = 0;
    p[0x9e] = 0;
    p[0x9f] = 0;
    p[0xa0] = 0;
    p[0xa1] = 0;
    p[0xa2] = 0;
    p[0xa4] = 0;
    p[0xa5] = 0;
    p[0x158] = 0;
    p[0x159] = 0;
    p[0x15a] = 0;
    p[0x15c] = 0;
    p[0x15d] = 0;
    p[0x15e] = 0;
    p[0x161] = 0;
    p[0x162] = 0;
    p[0x163] = 0;
    p[0x165] = 0;
    p[0x166] = 0;
    p[0x167] = 0;
    uint32_t* puVar1 = p + 0x170;
    int32_t iVar2 = 5;
    do {
        puVar1[-4] = 0;
        puVar1[-3] = 0;
        puVar1[-2] = 0;
        puVar1[0] = 0;
        puVar1[1] = 0;
        puVar1[2] = 0;
        if (reinterpret_cast<void*>(puVar1[-4]) != nullptr) {
            operator_delete(reinterpret_cast<void*>(puVar1[-4]));
        }
        puVar1[-4] = 0;
        puVar1[-3] = 0;
        puVar1[-2] = 0;
        if (reinterpret_cast<void*>(puVar1[0]) != nullptr) {
            operator_delete(reinterpret_cast<void*>(puVar1[0]));
        }
        puVar1[0] = 0;
        puVar1[1] = 0;
        puVar1[2] = 0;
        puVar1[5] = 0x3f800000;
        reinterpret_cast<uint8_t*>(puVar1)[0x1c] = 0;   // listing's `puVar1 + 7` dwords
        reinterpret_cast<uint8_t*>(puVar1)[0x1d] = 0;
        reinterpret_cast<uint8_t*>(puVar1)[0x1e] = 0;
        puVar1[8] = 0;
        puVar1[9] = 0;
        puVar1[10] = 0xbf800000;
        puVar1[0xc] = 0;
        puVar1[6] = 0x3f800000;
        puVar1[0xb] = 0;
        puVar1[0xd] = 0;
        puVar1 = puVar1 + 0x13;
        iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    p[1] = 0;
    puVar1 = reinterpret_cast<uint32_t*>(FUN_00533c78(0x68));
    if (puVar1 == nullptr) {
        p[1] = 0;
        FUN_00527300(self);                       // receiver in EDI
        return;
    }
    puVar1[0] = 0x00713068;                       // &PTR_FUN_00713068
    p[1] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(puVar1));
    FUN_00527300(self);                           // receiver in EDI
    return;
}

// ---------------------------------------------------------------------------
// 0x005271d0 — observed shape
// Destructor: installs vtable 0x712e08, runs FUN_005278a0, releases the helper
// at [1] after installing vtable 0x713150, then walks five 0x4c-byte animation
// slots backwards from [0x1cf] releasing both emitter blocks. Releases the
// four owned vectors at [0x165], [0x161], [0x15c] and [0x158] (pointer plus
// two size fields each), releases [0x96] - 8 unless it is the static
// DAT_008cacd0 owner, and resets [0x96] to 0x008cacd0.
// ---------------------------------------------------------------------------
void FUN_005271d0(void* self)
{
    uint32_t* ecx = static_cast<uint32_t*>(self);   // in_ECX
    ecx[0] = 0x00712e08;                            // &PTR_LAB_00712e08
    FUN_005278a0(self);
    uint32_t* puVar1 = reinterpret_cast<uint32_t*>(ptr_at(ecx[1]));
    if (puVar1 != nullptr) {
        puVar1[0] = 0x00713150;                     // &PTR_FUN_00713150
        operator_delete(puVar1);
    }
    int32_t iVar2 = 5;
    puVar1 = ecx + 0x1cf;
    do {
        if (reinterpret_cast<void*>(puVar1[-0x13]) != nullptr) {
            operator_delete(reinterpret_cast<void*>(puVar1[-0x13]));
        }
        puVar1[-0x13] = 0;
        puVar1[-0x12] = 0;
        puVar1[-0x11] = 0;
        if (reinterpret_cast<void*>(puVar1[-0x17]) != nullptr) {
            operator_delete(reinterpret_cast<void*>(puVar1[-0x17]));
        }
        iVar2 = iVar2 + -1;
        puVar1[-0x17] = 0;
        puVar1[-0x16] = 0;
        puVar1[-0x15] = 0;
        puVar1 = puVar1 + -0x13;
    } while (iVar2 != 0);
    if (reinterpret_cast<void*>(ecx[0x165]) != nullptr) {
        operator_delete(reinterpret_cast<void*>(ecx[0x165]));
    }
    ecx[0x165] = 0;
    ecx[0x166] = 0;
    ecx[0x167] = 0;
    if (reinterpret_cast<void*>(ecx[0x161]) != nullptr) {
        operator_delete(reinterpret_cast<void*>(ecx[0x161]));
    }
    ecx[0x161] = 0;
    ecx[0x162] = 0;
    ecx[0x163] = 0;
    if (reinterpret_cast<void*>(ecx[0x15c]) != nullptr) {
        operator_delete(reinterpret_cast<void*>(ecx[0x15c]));
    }
    ecx[0x15c] = 0;
    ecx[0x15d] = 0;
    ecx[0x15e] = 0;
    if (reinterpret_cast<void*>(ecx[0x158]) != nullptr) {
        operator_delete(reinterpret_cast<void*>(ecx[0x158]));
    }
    ecx[0x158] = 0;
    ecx[0x159] = 0;
    ecx[0x15a] = 0;
    puVar1 = reinterpret_cast<uint32_t*>(
        static_cast<uintptr_t>(static_cast<uint32_t>(ecx[0x96]) - 8));
    if ((puVar1 != nullptr) && (puVar1 != reinterpret_cast<uint32_t*>(ptr_at(0x008cacc8)))) {
        operator_delete__(puVar1);
    }
    ecx[0x96] = 0x008cacd0;                         // &DAT_008cacd0
    return;
}

// ---------------------------------------------------------------------------
// 0x00527300 — observed shape
// Resets the audio helper object (receiver in EDI): clears the byte at +8 and
// the runtime state dwords at +0x518..+0x52c (+0x51c/+0x520/+0x528/+0x52c are
// -1), the byte at +0x538, floats at +0x53c/+0x544 (unity) and +0x540, calls
// FUN_0052fe60, then releases and clears the owned allocations at +0x548,
// +0x550, +0x728, +0x730, +0x738 and the block at +0x744 (deleted from
// pointer - 4). Further bytes at +9, +0x10d, +0x264, +0x265 and dwords at
// +0x268..+0x288 are cleared, +0x5a0/+0x5a4 set to unity, the two owned
// blocks at +0x560 and +0x570 released, FUN_0052c0c0 called, and the
// +0x78c..+0x798 fields reset (last one -1).
// ---------------------------------------------------------------------------
void FUN_00527300(void* self_in_EDI)
{
    uint8_t* s = static_cast<uint8_t*>(self_in_EDI);   // unaff_EDI
    s[8] = 0;
    FUN_004a1230();
    u32_at(self_in_EDI, 0x518) = 0;
    u32_at(self_in_EDI, 0x51c) = 0xffffffff;
    u32_at(self_in_EDI, 0x520) = 0xffffffff;
    u32_at(self_in_EDI, 0x524) = 0;
    u32_at(self_in_EDI, 0x528) = 0xffffffff;
    u32_at(self_in_EDI, 0x52c) = 0xffffffff;
    s[0x538] = 0;
    u32_at(self_in_EDI, 0x53c) = 0x3f800000;
    u32_at(self_in_EDI, 0x540) = 0;
    u32_at(self_in_EDI, 0x544) = 0x3f800000;
    FUN_0052fe60();
    operator_delete__(reinterpret_cast<void*>(u32_at(self_in_EDI, 0x548)));
    operator_delete__(reinterpret_cast<void*>(u32_at(self_in_EDI, 0x550)));
    operator_delete__(reinterpret_cast<void*>(u32_at(self_in_EDI, 0x728)));
    operator_delete__(reinterpret_cast<void*>(u32_at(self_in_EDI, 0x730)));
    operator_delete__(reinterpret_cast<void*>(u32_at(self_in_EDI, 0x738)));
    if (u32_at(self_in_EDI, 0x744) != 0) {
        operator_delete__(reinterpret_cast<void*>(
            static_cast<uintptr_t>(u32_at(self_in_EDI, 0x744) - 4)));
    }
    u32_at(self_in_EDI, 0x548) = 0;
    u32_at(self_in_EDI, 0x54c) = 0;
    u32_at(self_in_EDI, 0x550) = 0;
    u32_at(self_in_EDI, 0x554) = 0;
    u32_at(self_in_EDI, 0x558) = 0;
    u32_at(self_in_EDI, 0x728) = 0;
    u32_at(self_in_EDI, 0x72c) = 0;
    u32_at(self_in_EDI, 0x730) = 0;
    u32_at(self_in_EDI, 0x734) = 0;
    u32_at(self_in_EDI, 0x738) = 0;
    u32_at(self_in_EDI, 0x73c) = 0;
    u32_at(self_in_EDI, 0x740) = 0;
    u32_at(self_in_EDI, 0x744) = 0;
    u32_at(self_in_EDI, 0x748) = 0;
    u32_at(self_in_EDI, 0x74c) = 0;
    u32_at(self_in_EDI, 0x750) = 0;
    u32_at(self_in_EDI, 0x754) = 0;
    u32_at(self_in_EDI, 0x758) = 0;
    u32_at(self_in_EDI, 0x75c) = 0;
    u32_at(self_in_EDI, 0x760) = 0;
    u32_at(self_in_EDI, 0x764) = 0;
    u32_at(self_in_EDI, 0x768) = 0;
    u32_at(self_in_EDI, 0x76c) = 0;
    s[9] = 0;
    s[0x10d] = 0;
    s[0x264] = 0;
    s[0x265] = 0;
    u32_at(self_in_EDI, 0x268) = 0;
    u32_at(self_in_EDI, 0x26c) = 0;
    u32_at(self_in_EDI, 0x270) = 0;
    u32_at(self_in_EDI, 0x274) = 0;
    u32_at(self_in_EDI, 0x278) = 0;
    u32_at(self_in_EDI, 0x27c) = 0;
    u32_at(self_in_EDI, 0x280) = 0;
    u32_at(self_in_EDI, 0x284) = 0;
    u32_at(self_in_EDI, 0x288) = 0;
    u32_at(self_in_EDI, 0x5a0) = 0x3f800000;
    u32_at(self_in_EDI, 0x5a4) = 0x3f800000;
    if (reinterpret_cast<void*>(u32_at(self_in_EDI, 0x560)) != nullptr) {
        operator_delete(reinterpret_cast<void*>(u32_at(self_in_EDI, 0x560)));
    }
    u32_at(self_in_EDI, 0x560) = 0;
    u32_at(self_in_EDI, 0x564) = 0;
    u32_at(self_in_EDI, 0x568) = 0;
    if (reinterpret_cast<void*>(u32_at(self_in_EDI, 0x570)) != nullptr) {
        operator_delete(reinterpret_cast<void*>(u32_at(self_in_EDI, 0x570)));
    }
    u32_at(self_in_EDI, 0x570) = 0;
    u32_at(self_in_EDI, 0x574) = 0;
    u32_at(self_in_EDI, 0x578) = 0;
    u32_at(self_in_EDI, 0x57c) = 0;
    u32_at(self_in_EDI, 0x5a8) = 0;
    FUN_0052c0c0();
    u32_at(self_in_EDI, 0x78c) = 0;
    u32_at(self_in_EDI, 0x790) = 0;
    u32_at(self_in_EDI, 0x794) = 0;
    u32_at(self_in_EDI, 0x798) = 0xffffffff;
    return;
}

// ---------------------------------------------------------------------------
// 0x005276f0 — observed shape
// Copy-assigns the record at param_1 into the receiver: dwords [0..1], the
// seven bytes at +8..+0xf with the odd padding bytes at +9/+0xa/+0xb/+0xd/
// +0xe/+0xf, dwords [4..0x10], then the owned string at [0x11]. The string is
// resized only when the source length (dword at source-4) is non-negative, the
// source is non-null and differs from the target; the copy uses
// FUN_004f3350/memmove and NUL-terminates at target[length]. The trailing
// dword [0x12] and byte [0x13] are assigned on both paths.
// ---------------------------------------------------------------------------
void FUN_005276f0(void* self, uint32_t* param_1)
{
    uint32_t* d = static_cast<uint32_t*>(self);       // unaff_EBX
    d[0] = param_1[0];
    d[1] = param_1[1];
    reinterpret_cast<uint8_t*>(d)[8]  = reinterpret_cast<uint8_t*>(param_1)[8];
    reinterpret_cast<uint8_t*>(d)[9]  = reinterpret_cast<uint8_t*>(param_1)[9];
    reinterpret_cast<uint8_t*>(d)[10] = reinterpret_cast<uint8_t*>(param_1)[10];
    reinterpret_cast<uint8_t*>(d)[0xb] = reinterpret_cast<uint8_t*>(param_1)[0xb];
    reinterpret_cast<uint8_t*>(d)[0xc] = reinterpret_cast<uint8_t*>(param_1)[0xc];
    reinterpret_cast<uint8_t*>(d)[0xd] = reinterpret_cast<uint8_t*>(param_1)[0xd];
    reinterpret_cast<uint8_t*>(d)[0xe] = reinterpret_cast<uint8_t*>(param_1)[0xe];
    reinterpret_cast<uint8_t*>(d)[0xf] = reinterpret_cast<uint8_t*>(param_1)[0xf];
    d[4] = param_1[4];
    d[5] = param_1[5];
    d[6] = param_1[6];
    d[7] = param_1[7];
    d[8] = param_1[8];
    d[9] = param_1[9];
    d[10] = param_1[10];
    d[0xb] = param_1[0xb];
    d[0xc] = param_1[0xc];
    d[0xd] = param_1[0xd];
    d[0xe] = param_1[0xe];
    d[0xf] = param_1[0xf];
    d[0x10] = param_1[0x10];
    void* _Src = reinterpret_cast<void*>(static_cast<uintptr_t>(param_1[0x11]));
    size_t _Size = *reinterpret_cast<size_t*>(static_cast<uint8_t*>(_Src) - 4);
    int32_t* piVar1 = reinterpret_cast<int32_t*>(d + 0x11);
    if (((-1 < static_cast<int32_t>(_Size)) && (_Src != nullptr)) &&
        (_Src != reinterpret_cast<void*>(static_cast<uintptr_t>(*piVar1)))) {
        if (_Size != 0) {
            FUN_004f3350();
            memmove(reinterpret_cast<void*>(static_cast<uintptr_t>(*piVar1)), _Src, _Size);
            *reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(*piVar1) +
                                        static_cast<uintptr_t>(
                                            *reinterpret_cast<int32_t*>(
                                                static_cast<uintptr_t>(*piVar1) - 4))) = 0;
            d[0x12] = param_1[0x12];
            reinterpret_cast<uint8_t*>(d)[0x4c] = reinterpret_cast<uint8_t*>(param_1)[0x4c];
            return;
        }
        FUN_00412f90();
    }
    d[0x12] = param_1[0x12];
    reinterpret_cast<uint8_t*>(d)[0x4c] = reinterpret_cast<uint8_t*>(param_1)[0x4c];
    return;
}

// ---------------------------------------------------------------------------
// 0x005277f0 — observed shape
// Queries the receiver's vtable slot +0x38 for an object, calls that object's
// slot 0 with the address of the 32-byte local block (qa local_28..local_c
// holding 0,0,0,0,0,1.0f,0,1.0f), and releases the smart pointer at local_8
// (refcount at +4, slot 0 with argument 1 when it drops to zero). Returns 1
// when the call succeeded and 0 otherwise; the block is not otherwise used.
// ---------------------------------------------------------------------------
uint32_t FUN_005277f0(void* self)
{
    int32_t* ecx = static_cast<int32_t*>(self);       // in_ECX
    uint32_t local_28 = 0;
    uint32_t local_24 = 0;
    uint32_t local_20 = 0;
    uint32_t local_1c = 0;
    uint32_t local_18 = 0;
    uint32_t local_14 = 0x3f800000;
    uint32_t local_10 = 0;
    uint32_t local_c = 0x3f800000;
    uint32_t* local_8 = nullptr;
    uint32_t local_4 = 0;

    void** vt = reinterpret_cast<void**>(ptr_at(static_cast<uint32_t>(ecx[0])));
    uint32_t* puVar3 = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(
        reinterpret_cast<void* (*)(void)>(vt[0x38 / 4])()));
    void** vt2 = reinterpret_cast<void**>(ptr_at(puVar3[0]));
    char cVar2 = reinterpret_cast<char (*)(uint32_t*)>(vt2[0])(&local_28);
    if (cVar2 == '\0') {
        if (local_8 != nullptr) {
            int32_t iVar1 = static_cast<int32_t>(local_8[1]);
            local_8[1] = static_cast<uint32_t>(iVar1 + -1);
            if (iVar1 + -1 == 0) {
                void** vt3 = reinterpret_cast<void**>(ptr_at(local_8[0]));
                reinterpret_cast<void (*)(int)>(vt3[0])(1);
            }
        }
        return 0;
    }
    if (local_8 != nullptr) {
        int32_t iVar1 = static_cast<int32_t>(local_8[1]);
        local_8[1] = static_cast<uint32_t>(iVar1 + -1);
        if (iVar1 + -1 == 0) {
            void** vt3 = reinterpret_cast<void**>(ptr_at(local_8[0]));
            reinterpret_cast<void (*)(int)>(vt3[0])(1);
        }
    }
    return 1;
}

// ---------------------------------------------------------------------------
// 0x005278a0 — observed shape
// Shutdown path guarded by the byte at [2]: calls FUN_0052fe60, reports via
// FUN_00527000 when vtable slot +0x18 says the audio manager is not
// initialised (otherwise FUN_0052f5d0), runs FUN_0052a220/FUN_0052a280/
// FUN_0052a2e0, clears [2], runs FUN_0052c060 twice and FUN_0052bfb0, calls
// vtable slot +0xc when the byte at [0x87] (byte offset 0x21c) is set, forwards
// that byte to the helper at [1] slot +4, and calls FUN_00530090. Always ends
// with FUN_00527300 on the same receiver.
// ---------------------------------------------------------------------------
void FUN_005278a0(void* self)
{
    int32_t* ecx = static_cast<int32_t*>(self);       // in_ECX
    if (static_cast<int8_t>(u8_at(self, 8)) != 0) {    // listing's `(char)in_ECX[2]`
        FUN_0052fe60();
        void** vt = reinterpret_cast<void**>(ptr_at(static_cast<uint32_t>(ecx[0])));
        char cVar1 = reinterpret_cast<char (*)(void)>(vt[6])();   // +0x18
        if (cVar1 == '\0') {
            FUN_00527000("The audio manager has not been properly initialized yet");
        } else {
            FUN_0052f5d0();
        }
        FUN_0052a220();
        FUN_0052a280();
        FUN_0052a2e0();
        u8_at(self, 8) = 0;
        FUN_0052c060();
        FUN_0052c060();
        FUN_0052bfb0();
        if (u8_at(self, 0x21c) != 0) {
            reinterpret_cast<void (*)(void)>(vt[3])();            // +0xc
        }
        void** vtInner = reinterpret_cast<void**>(
            ptr_at(u32_va(static_cast<uint32_t>(ecx[1]))));
        reinterpret_cast<void (*)(int)>(vtInner[1])(
            static_cast<int>(static_cast<int8_t>(u8_at(self, 0x21c))));   // +4
        FUN_00530090();
    }
    FUN_00527300(self);                               // receiver in EDI
    return;
}

// ---------------------------------------------------------------------------
// 0x00527950 — observed shape
// If the object at +0x5a8 exists, calls its vtable slot +4, then slot +0x2c
// with argument 1, and clears the field.
// ---------------------------------------------------------------------------
void FUN_00527950(void* self)
{
    if (u32_at(self, 0x5a8) != 0) {
        void** vt = reinterpret_cast<void**>(ptr_at(u32_va(u32_at(self, 0x5a8))));
        reinterpret_cast<void (*)(void)>(vt[1])();               // +4
        if (u32_at(self, 0x5a8) != 0) {
            void** vt2 = reinterpret_cast<void**>(ptr_at(u32_va(u32_at(self, 0x5a8))));
            reinterpret_cast<void (*)(int)>(vt2[0xb])(1);        // +0x2c
        }
        u32_at(self, 0x5a8) = 0;
    }
    return;
}

// ---------------------------------------------------------------------------
// 0x00527a80 — observed shape
// Reports and returns 0 when vtable slot +0x18 reports the audio manager is
// not initialised; otherwise copies the ten dwords at [0x99] (byte 0x264) to
// param_1 and returns 1.
// ---------------------------------------------------------------------------
uint32_t FUN_00527a80(void* self, int32_t* param_1)
{
    int32_t* ecx = static_cast<int32_t*>(self);       // in_ECX
    void** vt = reinterpret_cast<void**>(ptr_at(static_cast<uint32_t>(ecx[0])));
    char cVar1 = reinterpret_cast<char (*)(void)>(vt[6])();      // +0x18
    if (cVar1 == '\0') {
        FUN_00527000("The audio manager has not been properly initialized yet");
        return 0;
    }
    int32_t* piVar3 = reinterpret_cast<int32_t*>(
        reinterpret_cast<uint8_t*>(self) + 0x264);    // listing's `in_ECX + 0x99`
    for (int32_t iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *param_1 = *piVar3;
        piVar3 = piVar3 + 1;
        param_1 = param_1 + 1;
    }
    return 1;
}

// ---------------------------------------------------------------------------
// 0x00527ac0 — observed shape
// Reports via FUN_00527000 when vtable slot +0x18 says the audio manager is not
// initialised; otherwise invokes the helper at [1] through vtable slot +0x1c
// (the listing warns the jump table could not be recovered, so it is modelled
// as an observed indirect call).
// ---------------------------------------------------------------------------
void FUN_00527ac0(void* self)
{
    int32_t* ecx = static_cast<int32_t*>(self);       // in_ECX
    void** vt = reinterpret_cast<void**>(ptr_at(static_cast<uint32_t>(ecx[0])));
    char cVar1 = reinterpret_cast<char (*)(void)>(vt[6])();      // +0x18
    if (cVar1 == '\0') {
        FUN_00527000("The audio manager has not been properly initialized yet");
        return;
    }
    void** vtInner = reinterpret_cast<void**>(ptr_at(u32_va(static_cast<uint32_t>(ecx[1]))));
    reinterpret_cast<void (*)(void)>(vtInner[7])();              // +0x1c
    return;
}

// ---------------------------------------------------------------------------
// 0x00527af0 — observed shape
// Resolves the sound object for the EAX handle. Handle -2 re-enters the last
// element of the vector at +0x564 (object = *(end-4)), asks its vtable slot
// +0x10 with 0 and, when non-zero, calls slot +0x2c and returns the object.
// Otherwise the handle is looked up in the vector at +0x560: for each element
// whose slot +0x1c equals the handle, the caller's *param_1 is clamped to 0
// against the element's +0x108, slot +0x20 chooses between slot +0x10(*param_1)
// and slot +0x28, a zero/failed probe returns null, a table entry equal to 1
// triggers FUN_00527eb0, then slot +0x2c is called and the element returned.
// When the table entry is 2 (or the handle is out of range), the fallback
// probes DAT_008ecd78 slot +0x34 and the caller-supplied object's slot +8
// before calling slot +0x2c and returning that object.
// ---------------------------------------------------------------------------
int32_t* FUN_00527af0(int32_t* param_1, void* self, int32_t in_EAX, int32_t* unaff_EBX,
                      int32_t* unaff_retaddr)
{
    int32_t* ecx = static_cast<int32_t*>(self);       // in_ECX
    int32_t* piVar4 = param_1;
    int32_t  iVar2;
    char     cVar1;
    int32_t* piVar3;

    if (in_EAX == -2) {
        uint32_t vecEnd = u32_at(self, 0x564);
        uint32_t obj = u32_va(vecEnd - 4);
        void** vt = reinterpret_cast<void**>(ptr_at(u32_va(obj)));
        iVar2 = reinterpret_cast<int32_t (*)(int)>(vt[4])(0);    // +0x10
        if (iVar2 != 0) {
            reinterpret_cast<void (*)(void)>(vt[0xb])();         // +0x2c
            return reinterpret_cast<int32_t*>(static_cast<uintptr_t>(obj));
        }
    } else {
        if (((in_EAX < 0) || (ecx[0x153] <= in_EAX)) ||
            (u32_va(u32_at(self, 0x548) + 0x40 + static_cast<uint32_t>(in_EAX) * 0x4c) != 2)) {
            piVar3 = reinterpret_cast<int32_t*>(ptr_at(u32_at(self, 0x560)));
            if (piVar3 != reinterpret_cast<int32_t*>(ptr_at(u32_at(self, 0x564)))) {
                do {
                    uint32_t obj = static_cast<uint32_t>(*piVar3);
                    void** vt = reinterpret_cast<void**>(ptr_at(u32_va(obj)));
                    iVar2 = reinterpret_cast<int32_t (*)(void)>(vt[7])();        // +0x1c
                    if (in_EAX == iVar2) {
                        if (static_cast<int32_t>(u32_at(ptr_at(obj), 0x108)) <= *piVar4) {
                            *piVar4 = 0;
                        }
                        cVar1 = reinterpret_cast<char (*)(void)>(vt[8])();      // +0x20
                        if (cVar1 == '\0') {
                            iVar2 = reinterpret_cast<int32_t (*)(int32_t)>(vt[4])(*piVar4);
                            if (iVar2 == 0) {
                                return nullptr;
                            }
                        } else {
                            iVar2 = reinterpret_cast<int32_t (*)(void)>(vt[10])();  // +0x28
                            if (0 < iVar2) {
                                return nullptr;
                            }
                        }
                        if (((-1 < in_EAX) && (in_EAX < ecx[0x153])) &&
                            (u32_va(u32_at(self, 0x548) + 0x40 +
                                    static_cast<uint32_t>(in_EAX) * 0x4c) == 1)) {
                            FUN_00527eb0(reinterpret_cast<void*>(static_cast<uintptr_t>(obj)),
                                         *piVar3);
                        }
                        reinterpret_cast<void (*)(void)>(vt[0xb])();            // +0x2c
                        return reinterpret_cast<int32_t*>(
                            static_cast<uintptr_t>(static_cast<uint32_t>(*piVar3)));
                    }
                    piVar3 = piVar3 + 1;
                } while (piVar3 != reinterpret_cast<int32_t*>(ptr_at(u32_at(self, 0x564))));
            }
            if (((in_EAX < 0) || (ecx[0x153] <= in_EAX)) ||
                ((u32_va(u32_at(self, 0x548) + 0x40 + static_cast<uint32_t>(in_EAX) * 0x4c) != 1 ||
                  ((cVar1 = reinterpret_cast<char (*)(int32_t**)>(reinterpret_cast<void**>(
                                ptr_at(static_cast<uint32_t>(
                                    reinterpret_cast<uintptr_t>(DAT_008ecd78))))[0xd])(
                        &param_1),
                    cVar1 == '\0' ||
                    (cVar1 = reinterpret_cast<char (*)(void)>(reinterpret_cast<void**>(
                         ptr_at(u32_va(static_cast<uint32_t>(
                             reinterpret_cast<uintptr_t>(unaff_retaddr)))))[2])(),
                     cVar1 == '\0')))))) {
                return nullptr;
            }
            {
                void** vt = reinterpret_cast<void**>(
                    ptr_at(u32_va(static_cast<uint32_t>(
                        reinterpret_cast<uintptr_t>(unaff_EBX)))));
                reinterpret_cast<void (*)(void)>(vt[0xb])();                // +0x2c
            }
            return unaff_EBX;
        }
        piVar4 = reinterpret_cast<int32_t*>(&param_1);
        cVar1 = reinterpret_cast<char (*)(void)>(reinterpret_cast<void**>(
            ptr_at(static_cast<uint32_t>(reinterpret_cast<uintptr_t>(DAT_008ecd78))))[0xd])();
        if ((cVar1 != '\0') &&
            (cVar1 = reinterpret_cast<char (*)(void)>(reinterpret_cast<void**>(
                 ptr_at(u32_va(static_cast<uint32_t>(
                     reinterpret_cast<uintptr_t>(unaff_retaddr)))))[2])(),
             cVar1 != '\0')) {
            {
                void** vt = reinterpret_cast<void**>(
                    ptr_at(static_cast<uint32_t>(*piVar4)));
                reinterpret_cast<void (*)(void)>(vt[0xb])();                // +0x2c
            }
            return piVar4;
        }
    }
    return nullptr;
}

// ---------------------------------------------------------------------------
// 0x00527cc0 — observed shape
// Releases/validates the object supplied in ESI for the EAX handle. A null
// object returns 0. Unless the handle is -2 or names a table entry equal to 2,
// slot +0x30 runs, slot +0x28 is probed (a positive result short-circuits to
// 1), then slot +0x1c is called with the field at +0x558 and the pair is
// checked with FUN_0052a4c0. The object's byte at +0x114 (listing's +0x45
// dwords) is then set and 1 is returned.
// ---------------------------------------------------------------------------
uint32_t FUN_00527cc0(void* self, int32_t in_EAX, int32_t* unaff_ESI)
{
    int32_t* ecx = static_cast<int32_t*>(self);       // in_ECX
    uint32_t uVar3;
    uint32_t uVar4;
    int32_t  iVar2;
    char     cVar1;

    if (unaff_ESI == nullptr) {
        return 0;
    }
    if ((in_EAX != -2) &&
        (((in_EAX < 0) || (ecx[0x153] <= in_EAX)) ||
         (u32_va(u32_at(self, 0x548) + 0x40 + static_cast<uint32_t>(in_EAX) * 0x4c) != 2))) {
        void** vt = reinterpret_cast<void**>(
            ptr_at(u32_va(static_cast<uint32_t>(reinterpret_cast<uintptr_t>(unaff_ESI)))));
        reinterpret_cast<void (*)(void)>(vt[0xc])();                  // +0x30
        iVar2 = reinterpret_cast<int32_t (*)(void)>(vt[10])();        // +0x28
        if (0 < iVar2) {
            return 1;
        }
        uVar4 = u32_at(self, 0x558);
        uVar3 = reinterpret_cast<uint32_t (*)(uint32_t)>(vt[7])(uVar4);   // +0x1c
        cVar1 = FUN_0052a4c0(uVar3, uVar4);
        if (cVar1 != '\0') {
            return 1;
        }
    }
    reinterpret_cast<uint8_t*>(unaff_ESI)[0x114] = 1;               // listing's `unaff_ESI + 0x45`
    return 1;
}

// ---------------------------------------------------------------------------
// 0x00527d30 — observed shape
// Copies the caller's string into the DAT_008ca540 buffer. When
// DAT_008cace0 is clear this is a plain byte loop whose write index is
// dst - src; otherwise FUN_004f5480 must succeed, the string returned by
// FUN_0052bf10() is copied into the buffer, and the receiver's block at
// (self - 8) is released unless it is the static DAT_008cacc8 owner (in which
// case the function returns immediately). The buffer address is returned on
// every non-failure path.
// ---------------------------------------------------------------------------
uint8_t* FUN_00527d30(void* self, char* param_1)
{
    char* in_EAX = param_1;                           // in_EAX
    char cVar1;

    if (in_EAX == nullptr) {
        return nullptr;
    }
    if (DAT_008cace0 == 0) {
        int32_t iVar2 = static_cast<int32_t>(reinterpret_cast<intptr_t>(&DAT_008ca540)) -
                        static_cast<int32_t>(reinterpret_cast<intptr_t>(in_EAX));
        do {
            cVar1 = *in_EAX;
            in_EAX[iVar2] = cVar1;
            in_EAX = in_EAX + 1;
        } while (cVar1 != '\0');
    } else {
        if (FUN_004f5480() == 0) {
            return nullptr;
        }
        uint32_t* puVar3 = FUN_0052bf10();
        char* pcVar4 = reinterpret_cast<char*>(static_cast<uintptr_t>(*puVar3));
        char* pcVar5 = &DAT_008ca540;
        do {
            cVar1 = *pcVar4;
            pcVar4 = pcVar4 + 1;
            *pcVar5 = cVar1;
            pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        puVar3 = reinterpret_cast<uint32_t*>(
            static_cast<uintptr_t>(static_cast<uint32_t>(
                reinterpret_cast<uintptr_t>(self)) - 8));
        if ((puVar3 != nullptr) &&
            (puVar3 != reinterpret_cast<uint32_t*>(ptr_at(0x008cacc8)))) {
            operator_delete__(puVar3);
            return reinterpret_cast<uint8_t*>(&DAT_008ca540);
        }
    }
    return reinterpret_cast<uint8_t*>(&DAT_008ca540);
}
