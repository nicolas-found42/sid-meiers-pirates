// Reconstruction batch mass_0044 — Sid Meier's Pirates! (2004) PE32 i386
// image 6e88b90e4e2e30248d9e4de747b521cc03822b7ffeb214fd272b8ad1817447c9
// Source: Ghidra 12.2 pseudocode, one file per function.
#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cstring>
#include <cstdio>
#include <cmath>

// ---- extern globals referenced by the listings below (addresses from corpus names) ----
extern uint8_t DAT_00727598;   // linked-list node marker
extern uint8_t DAT_00727560;   // linked-list node marker (children list)
extern uint8_t DAT_00727854;   // linked-list node marker
extern uint8_t DAT_007273fc;   // linked-list node marker
extern uint8_t DAT_007278a8;   // linked-list node marker
extern uint8_t DAT_007278b0;   // linked-list node marker
extern uint8_t DAT_00728b90;   // linked-list node marker
extern uint8_t DAT_00728b20;   // linked-list node marker
extern uint8_t DAT_00727520;   // lookup table base
extern int32_t DAT_008c9df4;
extern char DAT_008cac29;
extern DWORD DAT_008e8fdc;
extern void* DAT_007268e0;
extern int32_t DAT_007268e8;
extern uint32_t PTR_PTR_007268dc;
extern uint32_t DAT_00727430;
extern uint32_t DAT_00727434;
extern uint32_t DAT_00727438;
extern uint8_t PTR_FUN_0070bed4;
extern char PTR_s_skill_Medicine_dds_00706f5c_0x18_0070d194;

// Null-based absolute references observed in 0x4c0c60 (Ghidra folds a base-0 pointer into
// absolute addresses; the listing states these globals overlap smaller symbols).
extern void** puRam00000020;
extern int32_t iRam00000024;
extern int32_t _DAT_00000004;
extern void** puRam00000000;

// ---- extern helpers ----
extern int32_t FUN_00533db0(uint32_t);
extern int32_t FUN_00449390(void*, uint32_t);
extern char FUN_004bf440(void);
extern void FUN_004bfef0(int32_t*, int32_t);
extern float* FUN_004b1260(uint32_t);
extern int32_t FUN_004bf530(uint32_t, const char*);
extern int32_t FUN_00500850(void);
extern int32_t FUN_00533c78(uint32_t);
extern uint32_t FUN_00542700(int32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern void FUN_00542bf0(uint32_t, uint32_t);
extern void FUN_004aade0(int32_t);
extern void FUN_004c0120(uint32_t, uint32_t);
extern void FUN_00538580(int32_t**);
extern void FUN_005353a0(void);
extern void FUN_00535670(int32_t);
extern void FUN_00540c50(void);
extern void FUN_004aac50(void**);
extern void FUN_00534130(void);
extern uint32_t FUN_004baaa0(void);
extern uint32_t FUN_004ab290(void*, void*, uint32_t, uint32_t, uint32_t, uint32_t,
                              uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
extern uint32_t FUN_005f0ddc(uint32_t, ...);
extern void FUN_0053d510(void*, void*, void*);
extern int32_t FUN_005065b0(void);
extern void FUN_005065e0(int32_t*);
extern void FUN_004ba350(uint32_t);
extern int32_t FUN_00500600(void);
extern void FUN_004c3000(void);
extern void FUN_0050f1e0(void);
extern void operator_delete(void*);
extern void FUN_004bdb30(void);
extern void FUN_004ab3c0(uint32_t*, int32_t);
extern void FUN_00501f40(int32_t, uint32_t);
extern void FUN_00502220(uint32_t);
extern void FUN_004afb90(void*);
extern void FUN_00501e50(void*);
extern void FUN_004bd880(uint32_t);
extern void FUN_004bdbc0(uint32_t);
extern void FUN_004ab180(void*);
extern int _strnicmp(const char*, const char*, size_t);
extern uint8_t FUN_004c0d40(void*, uint32_t, uint32_t, char, uint32_t);
extern void FUN_004c0e60(int32_t*, void*);

// ---- observed-layout helpers ----
static inline uint32_t& U32At(void* p, size_t off) {
    return *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(p) + off);
}
static inline int32_t& S32At(void* p, size_t off) {
    return *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(p) + off);
}
static inline uint16_t& U16At(void* p, size_t off) {
    return *reinterpret_cast<uint16_t*>(static_cast<uint8_t*>(p) + off);
}
static inline uint8_t& U8At(void* p, size_t off) {
    return *reinterpret_cast<uint8_t*>(static_cast<uint8_t*>(p) + off);
}
static inline float& F32At(void* p, size_t off) {
    return *reinterpret_cast<float*>(static_cast<uint8_t*>(p) + off);
}

// Virtual slot at a byte offset from the object's vtable pointer (observed `*obj + off`).
static inline void** SlotAddr(void* obj, size_t off) {
    return reinterpret_cast<void**>(static_cast<uint8_t*>(*reinterpret_cast<void**>(obj)) + off);
}

// `(**(*obj + 4))()` — the child/interface list head, walked through link[1].
static inline void* GetChildList(void* obj) {
    return reinterpret_cast<void*(*)(void*)>(*SlotAddr(obj, 4))(obj);
}
static inline void* NextLink(void* node) {
    return *reinterpret_cast<void**>(static_cast<uint8_t*>(node) + 4);
}

// `(**(*obj))(1)` — releasing virtual destructor with delete flag.
static inline void ReleaseVirtual(void* obj) {
    reinterpret_cast<void(*)(void*, int)>(*reinterpret_cast<void**>(obj))(obj, 1);
}

// 0x4c0240 — observed shape
void FUN_004c0240(int32_t* param_1, int32_t param_2) {
    if (param_1 == nullptr) return;
    for (void* link = GetChildList(param_1); link != nullptr; link = NextLink(link)) {
        if (link == &DAT_00727598) {
            int32_t iVar3 = FUN_00533db0(8);
            if (iVar3 == 0) return;
            uint32_t uVar4;
            if (*reinterpret_cast<int32_t*>(iVar3 + 0x2c) == 0) {
                uVar4 = 0;
            } else {
                uVar4 = *reinterpret_cast<uint32_t*>(
                    *reinterpret_cast<int32_t*>(iVar3 + 0x2c) + 4);
            }
            iVar3 = FUN_00449390(&DAT_00727520, uVar4);
            if (iVar3 == 0) return;
            char* pcVar5 = *reinterpret_cast<char**>(iVar3 + 0x38);
            char cVar1 = FUN_004bf440();
            if (cVar1 == '\0') return;
            pcVar5 = strstr(pcVar5, "ship_sail_");
            pcVar5 = pcVar5 + 10;
            _strnicmp(pcVar5, "main", 4);
            iVar3 = _strnicmp(pcVar5, &PTR_s_skill_Medicine_dds_00706f5c_0x18_0070d194, 3);
            uint32_t uVar6 = static_cast<uint32_t>(iVar3 == 0);
            iVar3 = _strnicmp(pcVar5, "gaff", 4);
            if (iVar3 == 0) {
                uVar6 = 2;
            }
            iVar3 = _strnicmp(pcVar5, "stay", 4);
            if (iVar3 == 0) {
                uVar6 = 3;
            }
            iVar3 = param_2 / 5 + static_cast<int32_t>(uVar6);
            FUN_004bfef0(param_1, (iVar3 + ((iVar3 >> 31) & 3)) >> 2);
            return;
        }
    }
    void* puVar2 = GetChildList(param_1);
    if (puVar2 != nullptr) {
        while (puVar2 != &DAT_00727560) {
            puVar2 = NextLink(puVar2);
            if (puVar2 == nullptr) return;
        }
        uint32_t uVar6 = 0;
        if (param_1[0x30] != 0) {
            if (param_1[0x30] == 0) goto LAB_004c03aa;
            do {
                int32_t iVar3 = *reinterpret_cast<int32_t*>(
                    static_cast<intptr_t>(param_1[0x2e]) + uVar6 * 4);
                if (iVar3 != 0) {
                    FUN_004c0240(reinterpret_cast<int32_t*>(static_cast<intptr_t>(iVar3)),
                                 param_2);
                }
LAB_004c03aa:
                uVar6 = uVar6 + 1;
            } while (uVar6 < static_cast<uint32_t>(param_1[0x30]));
        }
    }
    return;
}

// 0x4c03c0 — observed shape
// NEEDS_MANUAL: the listing reads a live-in EAX (`in_EAX`) as the ship-colour index used in the
// texture name; the corpus file shows no producer for that value, so it is carried as an explicit
// trailing parameter instead of being invented.
void FUN_004c03c0(uint32_t param_1, char param_2, int32_t in_EAX) {
    char local_40[64];
    int32_t iVar1 = FUN_004bf530(param_1, "ship_playercolor_*");
    if (iVar1 != 0) {
        sprintf(local_40, "ship_hull_damage%03d.dds", in_EAX * 0x14);
        int32_t iVar2 = FUN_00500850();
        if (iVar2 != 0) {
            if ((*reinterpret_cast<uint32_t*>(iVar1 + 0x40) < 2) ||
                (*reinterpret_cast<int32_t*>(
                     *reinterpret_cast<int32_t*>(iVar1 + 0x2c) + 0x1c) == 0)) {
                iVar1 = FUN_00533c78(0x1c);
                uint32_t uVar3;
                if (iVar1 == 0) {
                    uVar3 = 0;
                } else {
                    uVar3 = FUN_00542700(iVar2, 1, 3, 1, 0);
                }
                FUN_00542bf0(1, uVar3);
            } else {
                FUN_004aade0(iVar2);
                *reinterpret_cast<uint32_t*>(
                    *reinterpret_cast<int32_t*>(
                        *reinterpret_cast<int32_t*>(iVar1 + 0x2c) + 0x1c) + 0x10) = 1;
            }
            if (param_2 != '\0') {
                FUN_004c0120(param_1, 0);
            }
        }
    }
    return;
}

// 0x4c0480 — observed shape
// Receiver was EDI in the listing; promoted to `self`. Writes four 4-word vectors into the
// state block reached through self[0x2f] + 0x28 and sets bit 4 of the byte at self[0x2f] + 0x32.
void FUN_004c0480(void* self, uint32_t param_1, uint32_t param_2, uint32_t param_3,
                  uint32_t param_4) {
    if (self == nullptr) return;
    void* link = GetChildList(self);
    if (link == nullptr) return;
    while (link != &DAT_00727854) {
        link = NextLink(link);
        if (link == nullptr) return;
    }
    uint8_t* owner = reinterpret_cast<uint8_t*>(
        static_cast<intptr_t>(*reinterpret_cast<int32_t*>(static_cast<uint8_t*>(self) + 0xbc)));
    float* puVar1 = *reinterpret_cast<float**>(owner + 0x28);
    float* puVar2 = FUN_004b1260(param_1);
    puVar1[4] = puVar2[0];
    puVar1[5] = puVar2[1];
    puVar1[6] = puVar2[2];
    puVar1[7] = puVar2[3];
    puVar2 = FUN_004b1260(param_2);
    puVar1[0] = puVar2[0];
    puVar1[1] = puVar2[1];
    puVar1[2] = puVar2[2];
    puVar1[3] = puVar2[3];
    puVar2 = FUN_004b1260(param_3);
    puVar1[8] = puVar2[0];
    puVar1[9] = puVar2[1];
    puVar1[10] = puVar2[2];
    puVar1[0xb] = puVar2[3];
    puVar2 = FUN_004b1260(param_4);
    puVar1[0xc] = puVar2[0];
    puVar1[0xd] = puVar2[1];
    puVar1[0xe] = puVar2[2];
    puVar1[0xf] = puVar2[3];
    *(owner + 0x32) = static_cast<uint8_t>(*(owner + 0x32) | 4);
    return;
}

// 0x4c0570 — observed shape
// Recursive maximum scan: node field +0x1c over the +0x38 sibling chain, then the 12 children
// reached through FUN_00533db0 when the DAT_007273fc marker is present, then the child array.
float FUN_004c0570(int32_t* param_1) {
    int32_t* piVar1 = param_1;
    if (param_1 == nullptr) {
        return 0.0f;
    }
    float fBest = 0.0f;
    int32_t iVar3 = param_1[4];
    for (; iVar3 != 0; iVar3 = *reinterpret_cast<int32_t*>(iVar3 + 0x38)) {
        if (fBest <= *reinterpret_cast<float*>(iVar3 + 0x1c)) {
            fBest = *reinterpret_cast<float*>(iVar3 + 0x1c);
        }
    }
    void* puVar2 = GetChildList(piVar1);
    while (true) {
        if (puVar2 == nullptr) goto LAB_004c0602;
        if (puVar2 == &DAT_007273fc) break;
        puVar2 = NextLink(puVar2);
    }
    {
        uint32_t uVar4 = 0;
        do {
            int32_t iVarChild = FUN_00533db0(uVar4);
            if (iVarChild != 0) {
                float fVar5 = FUN_004c0570(
                    reinterpret_cast<int32_t*>(static_cast<intptr_t>(iVarChild)));
                if (fBest <= fVar5) {
                    fBest = fVar5;
                }
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < 0xc);
    }
LAB_004c0602:
    puVar2 = GetChildList(piVar1);
    if (puVar2 != nullptr) {
        while (puVar2 != &DAT_00727560) {
            puVar2 = NextLink(puVar2);
            if (puVar2 == nullptr) {
                return fBest;
            }
        }
        uint32_t uVar4 = 0;
        if (piVar1[0x30] != 0) {
            if (piVar1[0x30] == 0) goto LAB_004c0660;
            do {
                int32_t iVarChild = *reinterpret_cast<int32_t*>(
                    static_cast<intptr_t>(piVar1[0x2e]) + uVar4 * 4);
                if (iVarChild != 0) {
                    float fVar5 = FUN_004c0570(
                        reinterpret_cast<int32_t*>(static_cast<intptr_t>(iVarChild)));
                    if (fBest <= fVar5) {
                        fBest = fVar5;
                    }
                }
LAB_004c0660:
                uVar4 = uVar4 + 1;
            } while (uVar4 < static_cast<uint32_t>(piVar1[0x30]));
        }
    }
    return fBest;
}

// 0x4c0680 — observed shape
// Releases the object behind the DAT_00727598 marker via vtable+0x74, then drops one reference
// from the caller-supplied block (retRef[1]) and runs its virtual destructor at zero.
void FUN_004c0680(int32_t* param_1, int32_t* retRef = nullptr) {
    int32_t* piVar2 = param_1;
    if (param_1 == nullptr) return;
    for (void* puVar3 = GetChildList(param_1); puVar3 != nullptr; puVar3 = NextLink(puVar3)) {
        if (puVar3 == &DAT_00727598) {
            FUN_00538580(&param_1);
            reinterpret_cast<void(*)(void*, void*)>(*SlotAddr(piVar2, 0x74))(piVar2, param_1);
            if (retRef == nullptr) {
                return;
            }
            int32_t iVar1 = retRef[1];
            retRef[1] = iVar1 - 1;
            if (iVar1 - 1 == 0) {
                reinterpret_cast<void(*)(void*, int)>(*reinterpret_cast<void**>(retRef))(retRef, 1);
                return;
            }
            return;
        }
    }
    void* puVar3 = GetChildList(piVar2);
    if (puVar3 != nullptr) {
        while (puVar3 != &DAT_00727560) {
            puVar3 = NextLink(puVar3);
            if (puVar3 == nullptr) return;
        }
        uint32_t uVar4 = 0;
        if (piVar2[0x30] != 0) {
            if (piVar2[0x30] == 0) goto LAB_004c0729;
            do {
                int32_t iVar1 = *reinterpret_cast<int32_t*>(
                    static_cast<intptr_t>(piVar2[0x2e]) + uVar4 * 4);
                if (iVar1 != 0) {
                    FUN_004c0680(reinterpret_cast<int32_t*>(static_cast<intptr_t>(iVar1)),
                                 retRef);
                }
LAB_004c0729:
                uVar4 = uVar4 + 1;
            } while (uVar4 < static_cast<uint32_t>(piVar2[0x30]));
        }
    }
    return;
}

// 0x4c0740 — observed shape
// Scales the +0x44..+0x46 triple by 1/param_3 and applies |param_3| to +0x1a when the
// DAT_007278b0 marker is present; the DAT_007278a8 marker path re-reads the list head.
void FUN_004c0740(int32_t* param_1, int32_t param_2, float param_3) {
    if (param_1 == nullptr) return;
    void* puVar3 = GetChildList(param_1);
    for (; puVar3 != nullptr; puVar3 = NextLink(puVar3)) {
        if (puVar3 == &DAT_007278a8) {
            FUN_005353a0();
            puVar3 = GetChildList(param_1);
            goto joined_r0x004c0799;
        }
    }
    puVar3 = GetChildList(param_1);
    if (puVar3 != nullptr) {
        while (puVar3 != &DAT_00727560) {
            puVar3 = NextLink(puVar3);
            if (puVar3 == nullptr) return;
        }
        uint32_t uVar4 = 0;
        if (param_1[0x30] != 0) {
            if (param_1[0x30] == 0) goto LAB_004c0853;
            do {
                int32_t iVar1 = *reinterpret_cast<int32_t*>(
                    static_cast<intptr_t>(param_1[0x2e]) + uVar4 * 4);
                if (iVar1 != 0) {
                    FUN_004c0740(reinterpret_cast<int32_t*>(static_cast<intptr_t>(iVar1)),
                                 param_2, param_3);
                }
LAB_004c0853:
                uVar4 = uVar4 + 1;
            } while (uVar4 < static_cast<uint32_t>(param_1[0x30]));
        }
    }
    return;
joined_r0x004c0799:
    if (puVar3 == nullptr) {
LAB_004c0807:
        if (param_2 != 0) {
            FUN_00535670(param_2);
        }
        DAT_008c9df4 = 1;
        return;
    }
    if (puVar3 == &DAT_007278b0) {
        float fVar2 = 1.0f / param_3;
        param_1[0x30] = param_1[0x30] + 3;
        param_1[0x44] = static_cast<int32_t>(
            static_cast<float>(param_1[0x44]) * static_cast<float>(param_1[0x1a]) * fVar2);
        param_1[0x45] = static_cast<int32_t>(
            static_cast<float>(param_1[0x45]) * static_cast<float>(param_1[0x1a]) * fVar2);
        param_1[0x46] = static_cast<int32_t>(
            static_cast<float>(param_1[0x46]) * static_cast<float>(param_1[0x1a]) * fVar2);
        param_1[0x1a] = static_cast<int32_t>(fabsf(param_3));
        goto LAB_004c0807;
    }
    puVar3 = NextLink(puVar3);
    goto joined_r0x004c0799;
}

// 0x4c0870 — observed shape
// Propagates the flag down the self+0xbc chain, then sets or clears bit 15 of the +0x20 flags.
void FUN_004c0870(void* self, uint32_t param_1) {
    if (S32At(self, 0xbc) != 0) {
        FUN_004c0870(
            reinterpret_cast<void*>(static_cast<intptr_t>(S32At(self, 0xbc))), param_1);
    }
    if (static_cast<char>(param_1) == '\0') {
        U32At(self, 0x20) = U32At(self, 0x20) & 0xffff7fffu;
        return;
    }
    U32At(self, 0x20) = U32At(self, 0x20) | 0x8000u;
    return;
}

// 0x4c08b0 — observed shape
// Clears the byte at param_1[0x33] when the DAT_00728b90 marker is present, otherwise walks the
// DAT_00727560 child list and recurses into each child.
void FUN_004c08b0(int32_t* param_1) {
    if (param_1 == nullptr) return;
    for (void* puVar2 = GetChildList(param_1); puVar2 != nullptr; puVar2 = NextLink(puVar2)) {
        if (puVar2 == &DAT_00728b90) {
            *reinterpret_cast<uint8_t*>(param_1 + 0x33) = 0;
            return;
        }
    }
    void* puVar2 = GetChildList(param_1);
    if (puVar2 != nullptr) {
        while (puVar2 != &DAT_00727560) {
            puVar2 = NextLink(puVar2);
            if (puVar2 == nullptr) return;
        }
        uint32_t uVar3 = 0;
        if (param_1[0x30] != 0) {
            if (param_1[0x30] == 0) goto LAB_004c0925;
            do {
                int32_t iVar1 = *reinterpret_cast<int32_t*>(
                    static_cast<intptr_t>(param_1[0x2e]) + uVar3 * 4);
                if (iVar1 != 0) {
                    FUN_004c08b0(reinterpret_cast<int32_t*>(static_cast<intptr_t>(iVar1)));
                }
LAB_004c0925:
                uVar3 = uVar3 + 1;
            } while (uVar3 < static_cast<uint32_t>(param_1[0x30]));
        }
    }
    return;
}

// 0x4c0940 — observed shape
// Sets bit 14 of the +0x20 flags, bails out on the owning thread when +0x50 is set, recurses down
// self+0xbc and clears the +0x1c object through FUN_004c08b0.
void FUN_004c0940(void* self) {
    U32At(self, 0x20) = U32At(self, 0x20) | 0x4000u;
    if (S32At(self, 0x50) != 0) {
        DWORD DVar1 = GetCurrentThreadId();
        if (DAT_008e8fdc == DVar1) {
            return;
        }
    }
    if (S32At(self, 0xbc) != 0) {
        FUN_004c0940(
            reinterpret_cast<void*>(static_cast<intptr_t>(S32At(self, 0xbc))));
    }
    FUN_004c08b0(reinterpret_cast<int32_t*>(static_cast<intptr_t>(S32At(self, 0x1c))));
    return;
}

// 0x4c0980 — observed shape
// Lazily creates the 0x28-byte helper (vtable PTR_FUN_0070bed4) when slot 0xb is empty, registers
// it through FUN_004aac50, then sets/clears bits 0 and 1 of the byte at object+0x20.
// Receiver was EDI in the listing; promoted to `self`.
void FUN_004c0980(void* self, char param_1, char param_2) {
    if (S32At(self, 0x50) != 0) {
        DWORD DVar2 = GetCurrentThreadId();
        if (DAT_008e8fdc == DVar2) {
            return;
        }
    }
    void* puVar3 = reinterpret_cast<void*>(static_cast<intptr_t>(FUN_00533db0(0xb)));
    if (puVar3 == nullptr) {
        puVar3 = reinterpret_cast<void*>(static_cast<intptr_t>(FUN_00533c78(0x28)));
        if (puVar3 == nullptr) {
            puVar3 = nullptr;
        } else {
            FUN_00540c50();
            *reinterpret_cast<void**>(puVar3) = &PTR_FUN_0070bed4;
            U16At(puVar3, 0x20) = 3;
            U32At(puVar3, 9 * 4) = 3;
        }
        if (puVar3 != nullptr) {
            U32At(puVar3, 4) = U32At(puVar3, 4) + 1;
        }
        void* local_4 = puVar3;
        FUN_004aac50(&local_4);
        if (puVar3 != nullptr) {
            U32At(puVar3, 4) = U32At(puVar3, 4) - 1;
            if (U32At(puVar3, 4) == 0) {
                ReleaseVirtual(puVar3);
            }
        }
        FUN_00534130();
    }
    if (param_1 == '\0') {
        U8At(puVar3, 0x20) = static_cast<uint8_t>(U8At(puVar3, 0x20) & 0xfe);
    } else {
        U8At(puVar3, 0x20) = static_cast<uint8_t>(U8At(puVar3, 0x20) | 1);
    }
    if (param_2 == '\0') {
        U8At(puVar3, 0x20) = static_cast<uint8_t>(U8At(puVar3, 0x20) & 0xfd);
        return;
    }
    U8At(puVar3, 0x20) = static_cast<uint8_t>(U8At(puVar3, 0x20) | 2);
    return;
}

// 0x4c0a40 — observed shape
// Sets bit 1 of the +0x20 flags, then walks the +4 sibling chain marking byte at +0x88 for every
// node carrying the DAT_00728b20 marker, and recurses into the child array.
void FUN_004c0a40(void* self, int32_t* param_1) {
    U32At(self, 0x20) = U32At(self, 0x20) | 2;
    if (S32At(self, 0x50) == 0) {
        // fall through into the body
    } else {
        DWORD DVar3 = GetCurrentThreadId();
        if (DAT_008e8fdc == DVar3) {
            return;
        }
    }
    if (param_1 == nullptr) {
        if (S32At(self, 0xbc) != 0) {
            FUN_004c0a40(self, nullptr);
        }
        param_1 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(S32At(self, 0x1c)));
    }
    for (int32_t* piVar1 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(param_1[4]));
         piVar1 != nullptr;
         piVar1 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(piVar1[0xe]))) {
        for (void* puVar4 = GetChildList(piVar1); puVar4 != nullptr; puVar4 = NextLink(puVar4)) {
            if (puVar4 == &DAT_00728b20) {
                *reinterpret_cast<uint8_t*>(piVar1 + 0x22) = 1;
                break;
            }
        }
    }
    void* puVar4 = GetChildList(param_1);
    if (puVar4 != nullptr) {
        while (puVar4 != &DAT_00727560) {
            puVar4 = NextLink(puVar4);
            if (puVar4 == nullptr) return;
        }
        uint32_t uVar5 = 0;
        if (param_1[0x30] != 0) {
            if (param_1[0x30] == 0) goto LAB_004c0af9;
            do {
                int32_t iVar2 = *reinterpret_cast<int32_t*>(
                    static_cast<intptr_t>(param_1[0x2e]) + uVar5 * 4);
                if (iVar2 != 0) {
                    FUN_004c0a40(self, reinterpret_cast<int32_t*>(static_cast<intptr_t>(iVar2)));
                }
LAB_004c0af9:
                uVar5 = uVar5 + 1;
            } while (uVar5 < static_cast<uint32_t>(param_1[0x30]));
        }
    }
    return;
}

// 0x4c0b10 — observed shape
// Snapshot of the +0x90..+0x98 triple and a 9-word copy of the +0x6c block, then a chained
// FUN_005f0ddc expansion forwarded to FUN_004ab290. Receivers: ECX -> self, EBX -> target.
void FUN_004c0b10(void* self, void* target, uint32_t param_1, uint32_t param_2,
                  uint32_t retRef) {
    if (target == nullptr || self == nullptr) return;
    int32_t* piVar1 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(FUN_004baaa0()));
    int32_t iVar2 = reinterpret_cast<int32_t(*)(void*)>(*SlotAddr(piVar1, 0x40))(piVar1);
    if (iVar2 == 0) return;
    uint32_t uStack_34 = *reinterpret_cast<uint32_t*>(iVar2 + 0x90);
    uint32_t uStack_30 = *reinterpret_cast<uint32_t*>(iVar2 + 0x94);
    uint32_t uStack_2c = *reinterpret_cast<uint32_t*>(iVar2 + 0x98);
    uint32_t auStack_28[10];
    uint32_t* puVar10 = reinterpret_cast<uint32_t*>(iVar2 + 0x6c);
    uint32_t* puVar11 = auStack_28;
    for (int32_t iVar9 = 9; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar11 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar11 = puVar11 + 1;
    }
    uint8_t auStack_44[8];
    uint8_t auStack_3c[4];
    uint8_t auStack_38[4];
    FUN_0053d510(auStack_38, auStack_3c, auStack_44 + 4);
    uint32_t uVar12 = 0xffffffff;
    uint32_t uVar3 = FUN_005f0ddc(param_1, retRef, param_2, 0xffffffff);
    uint32_t uVar4 = FUN_005f0ddc(uVar3);
    uint32_t uVar5 = FUN_005f0ddc(uVar4);
    uint32_t uVar6 = FUN_005f0ddc(uVar5);
    uint32_t uVar7 = FUN_005f0ddc(uVar6);
    uint32_t uVar8 = FUN_005f0ddc(uVar7);
    FUN_004ab290(target, nullptr, uVar8, uVar7, uVar6, uVar5, uVar4, uVar3, param_1, retRef,
                 param_2, uVar12);
    return;
}

// 0x4c0be0 — observed shape
// Same FUN_004ab290 attachment with a zero-middle argument list when the resolved object carries
// the DAT_00727560 marker. Receivers: ECX -> self, EDX -> target.
void FUN_004c0be0(void* self, void* target, uint32_t param_1, uint32_t param_2,
                  uint32_t retRef) {
    if (target == nullptr || self == nullptr) return;
    int32_t* piVar1 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(FUN_004baaa0()));
    piVar1 = reinterpret_cast<int32_t*>(
        static_cast<intptr_t>(
            reinterpret_cast<int32_t(*)(void*)>(*SlotAddr(piVar1, 0x40))(piVar1)));
    if (piVar1 == nullptr) return;
    void* puVar2 = GetChildList(piVar1);
    if (puVar2 == nullptr) return;
    while (puVar2 != &DAT_00727560) {
        puVar2 = NextLink(puVar2);
        if (puVar2 == nullptr) return;
    }
    FUN_004ab290(target, piVar1, 0, 0, 0, 0, 0, 0, param_1, retRef, param_2, 0xffffffff);
    return;
}

// 0x4c0c60 — observed shape
// Drains FUN_005065b0/FUN_005065e0 while gates +0x60 and +0xa4 are set, releasing through the
// null-based globals at 0x20/0x4/0x0 (Ghidra folded a base-0 pointer into absolute addresses).
void FUN_004c0c60(int32_t param_1) {
    int32_t local_8[2];
    if ((*reinterpret_cast<int32_t*>(param_1 + 0x60) == 0) ||
        (*reinterpret_cast<int32_t*>(param_1 + 0xa4) == 0)) {
        return;
    }
    local_8[0] = FUN_005065b0();
    while (local_8[0] != 0) {
        FUN_005065e0(local_8);
        if (puRam00000020 != nullptr && iRam00000024 != 0) {
            reinterpret_cast<void(*)(int)>(*puRam00000020)(1);
            puRam00000020 = nullptr;
            FUN_004ba350(0);
        }
        _DAT_00000004 = _DAT_00000004 + -1;
        if (_DAT_00000004 == 0) {
            reinterpret_cast<void(*)(int)>(*puRam00000000)(1);
        }
    }
    return;
}

// 0x4c0cf0 — observed shape
// Looks the named object up through the vtable+0x40 accessor and routes it into FUN_004c0d40.
// NEEDS_MANUAL: FUN_004c0d40's receiver registers are live-in from this frame; `self` is threaded
// through explicitly because the listing does not name a source for them otherwise.
uint32_t FUN_004c0cf0(void* self, uint32_t param_1, uint32_t param_2) {
    int32_t* piVar1 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(FUN_004baaa0()));
    int32_t iVar2 =
        reinterpret_cast<int32_t(*)(void*, uint32_t)>(*SlotAddr(piVar1, 0x40))(piVar1, param_2);
    if (iVar2 != 0) {
        iVar2 = FUN_00500600();
        if (iVar2 != 0) {
            return FUN_004c0d40(self, param_1, static_cast<uint32_t>(iVar2),
                                static_cast<char>(param_2), 0);
        }
    }
    return 0;
}

// 0x4c0d40 — observed shape
// Detaches the object when the DAT_00727560 marker is present, releases its -0xc0-counted child
// array through FUN_00501f40, then tears down through FUN_004bd880 / FUN_004bdbc0 / FUN_004c0c60.
// Receiver was EAX in the listing; promoted to `self`.
uint8_t FUN_004c0d40(void* self, uint32_t param_1, uint32_t param_2, char param_3,
                     uint32_t retRef = 0) {
    uint8_t uVar7 = 0;
    if (self == nullptr) {
        return 0;
    }
    uint8_t bVar3;
    {
        void* puVar4 = GetChildList(self);
        bVar3 = 0;
        for (; puVar4 != nullptr; puVar4 = NextLink(puVar4)) {
            if (puVar4 == &DAT_00727560) {
                bVar3 = 1;
                break;
            }
        }
    }
    int32_t* piVar5 = reinterpret_cast<int32_t*>(
        static_cast<uintptr_t>(-static_cast<uint32_t>(bVar3)) &
        static_cast<uintptr_t>(reinterpret_cast<uintptr_t>(self)));
    if (piVar5 == nullptr) {
        return uVar7;
    }
    if (param_3 != '\0') {
        FUN_004c0e60(piVar5, self);
    }
    reinterpret_cast<void(*)(void*, uint32_t, uint32_t)>(*SlotAddr(piVar5, 0x70))(piVar5,
                                                                                  param_2, 1);
    if (DAT_008cac29 != '\0') {
        FUN_004afb90(piVar5);
        FUN_00501e50(piVar5);
        void* puVar4 = GetChildList(piVar5);
        if (puVar4 != nullptr) {
            while (true) {
                if (puVar4 == &DAT_00727560) {
                    int32_t iVar6 = FUN_00449390(&DAT_00727560,
                                                 static_cast<uint32_t>(
                                                     reinterpret_cast<uintptr_t>(piVar5)));
                    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(iVar6 + 0xc0);
                    while (uVar1 = uVar1 - 1, -1 < static_cast<int32_t>(uVar1)) {
                        if (uVar1 < *reinterpret_cast<uint32_t*>(iVar6 + 0xc0)) {
                            int32_t iVar2 = *reinterpret_cast<int32_t*>(
                                static_cast<intptr_t>(
                                    *reinterpret_cast<int32_t*>(iVar6 + 0xb8)) +
                                uVar1 * 4);
                            if (iVar2 != 0) {
                                FUN_00501f40(iVar2, 3);
                            }
                        }
                    }
                    break;
                }
                puVar4 = NextLink(puVar4);
                if (puVar4 == nullptr) break;
            }
        }
        {
            int32_t iVar6 = FUN_00533db0(8);
            if (iVar6 != 0) {
                FUN_00502220(0);
            }
        }
    }
    FUN_004bd880(retRef);
    FUN_004bdbc0(param_1);
    uVar7 = 1;
    FUN_004c0c60(static_cast<int32_t>(param_1));
    return uVar7;
}

// 0x4c0e60 — observed shape
// Reverse iteration over the child array calling vtable+0x78; for each surviving node it removes
// the tracker entry matching the node address, destroys the self+0x68 helper when it owns the
// node, dispatches the DAT_00727598 path, recurses through DAT_00727560, then releases the node.
// Receiver was ECX in the listing; promoted to `self`.
void FUN_004c0e60(int32_t* param_1, void* self) {
    int32_t iVar6 = param_1[0x30];
    do {
        do {
            do {
                if (iVar6 == 0) {
                    return;
                }
                iVar6 = iVar6 + -1;
                int32_t local_4 = iVar6;
                int32_t* local_8 = nullptr;
                reinterpret_cast<void(*)(void*, int32_t**, int32_t)>(
                    *SlotAddr(param_1, 0x78))(param_1, &local_8, iVar6);
                int32_t* piVar1 = local_8;
                uint32_t uVar7;
                if (local_8 == nullptr) {
                    uVar7 = 0;
                } else {
                    uint8_t bVar4;
                    {
                        void* puVar5 = GetChildList(local_8);
                        bVar4 = 0;
                        for (; puVar5 != nullptr; puVar5 = NextLink(puVar5)) {
                            if (puVar5 == &DAT_00727560) {
                                bVar4 = 1;
                                break;
                            }
                        }
                    }
                    uVar7 = static_cast<uint32_t>(-static_cast<uint32_t>(bVar4)) &
                            static_cast<uint32_t>(reinterpret_cast<uintptr_t>(piVar1));
                    if (uVar7 != 0) {
                        void* puVar5 = DAT_007268e0;
                        if (DAT_007268e8 != 0) {
                            while (puVar5 != nullptr) {
                                int32_t* piVar1b =
                                    reinterpret_cast<int32_t*>(static_cast<uint8_t*>(puVar5) + 8);
                                puVar5 = *reinterpret_cast<void**>(puVar5);
                                int32_t obj = *piVar1b;
                                if (uVar7 == *reinterpret_cast<uint32_t*>(
                                                 static_cast<intptr_t>(obj) + 8)) {
                                    FUN_004ab3c0(&PTR_PTR_007268dc, obj);
                                    DAT_008c9df4 = 1;
                                }
                            }
                        }
                    }
                }
                int32_t iVar2 = *reinterpret_cast<int32_t*>(static_cast<uint8_t*>(self) + 0x68);
                if (iVar2 != 0 && uVar7 != 0 &&
                    (*reinterpret_cast<uint32_t*>(iVar2 + 0x1c) == uVar7 ||
                     *reinterpret_cast<uint32_t*>(iVar2 + 0x20) == uVar7)) {
                    if ((*reinterpret_cast<char*>(iVar2 + 0x18) != '\0') &&
                        (*reinterpret_cast<char*>(iVar2 + 0x18) != '\0')) {
                        *reinterpret_cast<uint8_t*>(iVar2 + 0x18) = 0;
                    }
                    FUN_004c3000();
                    void* pvVar3 = *reinterpret_cast<void**>(static_cast<uint8_t*>(self) + 0x68);
                    if (pvVar3 != nullptr) {
                        FUN_0050f1e0();
                        operator_delete(pvVar3);
                        *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(self) + 0x68) = 0;
                    }
                    iVar6 = local_4;
                }
            } while (local_8 == nullptr);
            {
                void* puVar5 = GetChildList(local_8);
                for (; puVar5 != nullptr; puVar5 = NextLink(puVar5)) {
                    if (puVar5 == &DAT_00727598) {
                        FUN_004bdb30();
                        goto LAB_004c0fc0;
                    }
                }
            }
        } while (local_8 == nullptr);
        {
            void* puVar5 = GetChildList(local_8);
            for (; puVar5 != nullptr; puVar5 = NextLink(puVar5)) {
                if (puVar5 == &DAT_00727560) {
                    FUN_004c0e60(local_8, self);
                    break;
                }
            }
        }
LAB_004c0fc0:
        if (local_8 != nullptr) {
            int32_t iVar2b = local_8[1];
            local_8[1] = iVar2b + -1;
            if (iVar2b + -1 == 0) {
                ReleaseVirtual(local_8);
            }
        }
    } while (true);
}

// 0x4c1000 — observed shape
// Waits for a non-null FUN_004baaa0 result, resolves the object by name and copies its
// +0x90..+0x98 triple into the caller block, or the DAT_00727430..8 default triple.
// Receiver was EBX in the listing; promoted to `out`.
void FUN_004c1000(uint32_t param_1, uint32_t* out) {
    int32_t iVar1 = static_cast<int32_t>(FUN_004baaa0());
    while (iVar1 == 0) {
        Sleep(10);
        iVar1 = static_cast<int32_t>(FUN_004baaa0());
    }
    int32_t* piVar2 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(FUN_004baaa0()));
    iVar1 = reinterpret_cast<int32_t(*)(void*, uint32_t)>(*SlotAddr(piVar2, 0x40))(piVar2,
                                                                                   param_1);
    if (iVar1 == 0) {
        out[0] = DAT_00727430;
        out[1] = DAT_00727434;
        out[2] = DAT_00727438;
        return;
    }
    out[0] = *reinterpret_cast<uint32_t*>(iVar1 + 0x90);
    out[1] = *reinterpret_cast<uint32_t*>(iVar1 + 0x94);
    out[2] = *reinterpret_cast<uint32_t*>(iVar1 + 0x98);
    return;
}

// 0x4c1080 — observed shape
// Enumerates "dummy_<name>_%02d" (1..99) while lookups succeed, attaching each match through
// FUN_004ab290 and setting bit 0 at +0x30. Receiver was EBX in the listing; promoted to `self`.
void FUN_004c1080(void* self, uint32_t param_1, const char* param_2, uint32_t param_3,
                  uint32_t param_4) {
    if (self == nullptr || param_2 == nullptr) return;
    bool bVar1 = true;
    int32_t iVar5 = 1;
    do {
        if (!bVar1) {
            return;
        }
        char local_80[128];
        sprintf(local_80, "dummy_%s_%02d", param_2, iVar5);
        int32_t* piVar2 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(FUN_004baaa0()));
        piVar2 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(
            reinterpret_cast<int32_t(*)(void*, const char*)>(*SlotAddr(piVar2, 0x40))(piVar2,
                                                                                      local_80)));
        if (piVar2 != nullptr) {
            void* puVar3 = GetChildList(piVar2);
            for (; puVar3 != nullptr; puVar3 = NextLink(puVar3)) {
                if (puVar3 == &DAT_00727560) {
                    int32_t iVar4 = FUN_004ab290(
                        self, piVar2, 0, 0, 0, 0, 0, 0, param_3, 0xffffffff, 100, param_4);
                    if (iVar4 != 0) {
                        *reinterpret_cast<uint32_t*>(iVar4 + 0x30) =
                            *reinterpret_cast<uint32_t*>(iVar4 + 0x30) | 1;
                    }
                    goto LAB_004c1106;
                }
            }
        }
        bVar1 = false;
LAB_004c1106:
        iVar5 = iVar5 + 1;
    } while (iVar5 < 100);
    return;
}

// 0x4c1150 — observed shape
// Enumerates "dummy_<name>_%02d" (1..99) and releases each match through FUN_004ab180.
// Receiver was EAX in the listing; promoted to `self`.
void FUN_004c1150(void* self, uint32_t param_1, const char* param_2) {
    if (self == nullptr || param_2 == nullptr) return;
    bool bVar1 = true;
    int32_t iVar4 = 1;
    do {
        if (!bVar1) {
            return;
        }
        char local_80[128];
        sprintf(local_80, "dummy_%s_%02d", param_2, iVar4);
        int32_t* piVar2 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(FUN_004baaa0()));
        piVar2 = reinterpret_cast<int32_t*>(static_cast<intptr_t>(
            reinterpret_cast<int32_t(*)(void*, const char*)>(*SlotAddr(piVar2, 0x40))(piVar2,
                                                                                      local_80)));
        if (piVar2 != nullptr) {
            void* puVar3 = GetChildList(piVar2);
            for (; puVar3 != nullptr; puVar3 = NextLink(puVar3)) {
                if (puVar3 == &DAT_00727560) {
                    FUN_004ab180(piVar2);
                    goto LAB_004c11e3;
                }
            }
        }
        bVar1 = false;
LAB_004c11e3:
        iVar4 = iVar4 + 1;
    } while (iVar4 < 100);
    return;
}
