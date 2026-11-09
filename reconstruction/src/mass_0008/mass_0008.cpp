// Reconstruction batch mass_0008 — Sid Meier's Pirates! (2004) PE32 i386
// Source candidates derived from Ghidra 12.2 pseudocode corpus only.
#include <cstdint>
#include <cstddef>
#include <cstring>
#include <windows.h>

// Extern globals used by the supplied listings (addresses from corpus names).
extern int32_t DAT_0086c330;
extern int16_t DAT_0086c1a0[];
extern int16_t DAT_0086c010[];
extern int16_t DAT_0086bb60[];
extern int16_t DAT_0086be80[];
extern int16_t DAT_0086bcf0[];

extern uint32_t DAT_008c84d8;
extern int32_t  DAT_008c84dc;
extern uint8_t  DAT_008c8ba4[];
extern uint8_t  DAT_008c8b24[];

extern int32_t DAT_008dc30c;
extern int32_t DAT_008dc310;
extern int32_t DAT_0072637c;
extern int32_t DAT_00726380;
extern int32_t DAT_0085a0fc;
extern int32_t DAT_0085a164;

// Referenced helpers.
extern uint8_t FUN_004314b0();
extern int32_t FUN_005f0ddc();

// Inline readers for byte-offset globals.
static inline uint32_t ReadU32(const uint8_t* base) {
    uint32_t v; std::memcpy(&v, base, sizeof(v)); return v;
}
static inline float ReadF32(const uint8_t* base) {
    float v; std::memcpy(&v, base, sizeof(v)); return v;
}
static inline uint32_t U32At(uint8_t* base, int byteOff) {
    return ReadU32(base + byteOff);
}
static inline float F32At(uint8_t* base, int byteOff) {
    return ReadF32(base + byteOff);
}
static inline int16_t S16At(int16_t* base, int idx) { return base[idx]; }

// 0x42c5e0 — observed shape
uint32_t FUN_0042c5e0(int in_edx) {
    uint32_t idx = 0;
    if (DAT_0086c330 > 0) {
        do {
            if ((int32_t)S16At(DAT_0086c1a0, (int)idx) == in_edx) {
                return ((idx >> 8) << 8) | 1u;
            }
            idx = idx + 1;
        } while ((int)idx < DAT_0086c330);
    }
    return idx & 0xffffff00u;
}

// 0x42c610 — observed shape
void FUN_0042c610(int in_ecx) {
    int count = DAT_0086c330;
    int idx = 0;
    if (count > 0) {
        while ((int)S16At(DAT_0086c1a0, idx) != in_ecx) {
            idx = idx + 1;
            if (count <= idx) return;
        }
        if (idx < count - 1) {
            std::memmove(DAT_0086c1a0 + idx, DAT_0086c1a0 + idx + 1,
                         (size_t)(count - idx) * 2u - 2u);
            std::memmove(DAT_0086c010 + idx, DAT_0086c010 + idx + 1,
                         (size_t)(DAT_0086c330 - idx) * 2u - 2u);
            std::memmove(DAT_0086be80 + idx, DAT_0086be80 + idx + 1,
                         (size_t)(DAT_0086c330 - idx) * 2u - 2u);
            std::memmove(DAT_0086bcf0 + idx, DAT_0086bcf0 + idx + 1,
                         (size_t)(DAT_0086c330 - idx) * 2u - 2u);
            std::memmove(DAT_0086bb60 + idx, DAT_0086bb60 + idx + 1,
                         (size_t)(DAT_0086c330 - idx) * 2u - 2u);
        }
        DAT_0086c330 = DAT_0086c330 - 1;
    }
}

// 0x42c6f0 — observed shape
int FUN_0042c6f0(int in_edx, int unaff_esi) {
    int idx = 0;
    if (DAT_0086c330 > 0) {
        do {
            if (S16At(DAT_0086c010, idx) <= unaff_esi &&
                unaff_esi < S16At(DAT_0086bcf0, idx) &&
                S16At(DAT_0086be80, idx) <= in_edx &&
                in_edx < S16At(DAT_0086bb60, idx)) {
                return (int)S16At(DAT_0086c1a0, idx);
            }
            idx = idx + 1;
        } while (idx < DAT_0086c330);
    }
    return -1;
}

// 0x42c750 — observed shape
uint32_t FUN_0042c750(const char* in_ecx, const char* in_eax) {
    if (in_ecx != nullptr && in_eax != nullptr) {
        if (_stricmp(in_ecx, in_eax) == 0) return 1;
    }
    return 0;
}

// 0x42c770 — observed shape
int FUN_0042c770() {
    int iVar3 = DAT_008c84dc;
    uint32_t uVar1 = DAT_008c84d8;
    int iVar5 = (int)(DAT_008c84dc * 0x140);
    if (U32At(DAT_008c8ba4, iVar5) <= DAT_008c84d8) {
        if (DAT_008c84d8 < U32At(DAT_008c8ba4, iVar5 + 0x10)) {
            return 0x1b;
        }
        if (U32At(DAT_008c8ba4, iVar5 - 0x40) <= DAT_008c84d8) {
            if (FUN_004314b0() != 0) return 0x126;
            if (FUN_004314b0() != 0) return 0x128;
            if (FUN_004314b0() != 0) return 0x125;
            if (FUN_004314b0() != 0) return 0x127;
            if (FUN_004314b0() == 0) {
                if (FUN_004314b0() == 0) {
                    int idx = 0;
                    uint32_t* pu = (uint32_t*)(DAT_008c8b24 + iVar3 * 0x50);
                    do {
                        if (uVar1 < *pu) return idx + 0x80;
                        idx += 1;
                        pu += 4;
                    } while (idx < 0x14);
                    iVar3 = 0;
                } else {
                    iVar3 = 0x127;
                    if (F32At(DAT_008c8ba4, iVar5 + 0x7c) <= 0.0f) return 0x125;
                }
            } else {
                iVar3 = 0x126;
                if (F32At(DAT_008c8ba4, iVar5 + 0x8c) <= 0.0f) return 0x128;
            }
            return iVar3;
        }
    }
    return 0xd;
}

// 0x42c880 — observed shape
int FUN_0042c880() {
    int iVar2 = DAT_008c84dc;
    uint32_t uVar1 = DAT_008c84d8;
    int iVar5 = (int)(DAT_008c84dc * 0x140);
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, iVar5)) return 0xd;
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, iVar5 + 0x10)) return 0x1b;
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, iVar5 - 0x40)) return 0x50;
    if (FUN_004314b0() != 0) return 0x123;
    if (FUN_004314b0() != 0) return 0x122;
    if (FUN_004314b0() != 0) return 0x126;
    if (FUN_004314b0() != 0) return 0x128;
    if (FUN_004314b0() != 0) return 0x125;
    if (FUN_004314b0() != 0) return 0x127;
    if (FUN_004314b0() != 0) {
        if (0.5f < F32At(DAT_008c8ba4, iVar5 + 0xac)) return 0x124;
        if (F32At(DAT_008c8ba4, iVar5 + 0xac) < -0.5f) return 0x121;
    }
    if (FUN_004314b0() != 0) {
        if (0.5f < F32At(DAT_008c8ba4, iVar5 + 0x8c)) return 0x126;
        if (F32At(DAT_008c8ba4, iVar5 + 0x8c) < -0.5f) return 0x128;
    }
    if (FUN_004314b0() != 0) {
        if (0.5f < F32At(DAT_008c8ba4, iVar5 + 0x7c)) return 0x127;
        if (F32At(DAT_008c8ba4, iVar5 + 0x7c) < -0.5f) return 0x125;
    }
    int idx = 0;
    uint32_t* pu = (uint32_t*)(DAT_008c8b24 + iVar2 * 0x50);
    do {
        if (uVar1 < *pu) return idx + 0x80;
        idx += 1;
        pu += 4;
    } while (idx < 0x14);
    return 0;
}

// 0x42ca40 — observed shape
int FUN_0042ca40() {
    int iVar3 = DAT_008c84dc;
    uint32_t uVar1 = DAT_008c84d8;
    int iVar5 = (int)(DAT_008c84dc * 0x140);
    if ((DAT_008c84d8 < U32At(DAT_008c8ba4, iVar5)) ||
        (DAT_008c84d8 < U32At(DAT_008c8ba4, iVar5 + 0x10))) return 0x1b;
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, iVar5 - 0x40)) return 0x50;
    if (FUN_004314b0() != 0) return 0x123;
    if (FUN_004314b0() != 0) return 0x122;
    if (FUN_004314b0() != 0) return 0x126;
    if (FUN_004314b0() != 0) return 0x128;
    if (FUN_004314b0() != 0) return 0x125;
    if (FUN_004314b0() != 0) return 0x127;
    if (FUN_004314b0() == 0) {
        if (FUN_004314b0() == 0) {
            int idx = 0;
            uint32_t* pu = (uint32_t*)(DAT_008c8b24 + iVar3 * 0x50);
            do {
                if (uVar1 < *pu) return idx + 0x80;
                idx += 1;
                pu += 4;
            } while (idx < 0x14);
            iVar3 = 0;
        } else {
            iVar3 = 0x127;
            if (F32At(DAT_008c8ba4, iVar5 + 0x7c) <= 0.0f) return 0x125;
        }
    } else {
        iVar3 = 0x126;
        if (F32At(DAT_008c8ba4, iVar5 + 0x8c) <= 0.0f) return 0x128;
    }
    return iVar3;
}

// 0x42cb80 — observed shape
int FUN_0042cb80() {
    int off = (int)(DAT_008c84dc * 0x140);
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, off)) return 0x128;
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, off + 0x10)) return 0x127;
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, off + 0x20)) return 0x125;
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, off + 0x30)) return 0x126;
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, off - 0x40)) return 0x50;
    uint32_t* pu = (uint32_t*)(DAT_008c8b24 + DAT_008c84dc * 0x50);
    if (DAT_008c84d8 < *pu) return 0x126;
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, off - 0x70)) return 0x128;
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, off - 0x60)) return 0x125;
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, off - 0x50)) return 0x127;
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, off + 0x60)) return 0x123;
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, off + 0x70)) return 0x122;
    int idx = 0;
    do {
        if (DAT_008c84d8 < *pu) return idx + 0x80;
        idx += 1;
        pu += 4;
    } while (idx < 0x14);
    return 0;
}

// NEEDS_MANUAL: lines 30-33, 69-73 and loop body 100-106 were elided in the corpus read; below preserves all observed operations and reconstructs the elided loop from the visible header/footer pattern.
// 0x42cc60 — observed shape
int FUN_0042cc60() {
    int iVar4 = DAT_008c84dc;
    int iVar6 = (int)(DAT_008c84dc * 0x140);
    int iVar2 = FUN_005f0ddc();
    iVar2 = DAT_008dc30c + iVar2;
    DAT_008dc30c = iVar2;
    int iVar3 = FUN_005f0ddc();
    DAT_008dc310 = DAT_008dc310 + iVar3;
    if (DAT_008dc310 < 0) DAT_008dc310 = 0;
    if (DAT_0072637c < iVar2) DAT_008dc30c = DAT_0072637c;
    if (DAT_00726380 < DAT_008dc310) DAT_008dc310 = DAT_00726380;
    if ((F32At(DAT_008c8ba4, iVar6 + 0x5c) != 0.0f) &&
        (DAT_0085a0fc = DAT_0085a0fc - 1, DAT_0085a0fc < -0x12)) DAT_0085a0fc = -0x12;
    if ((F32At(DAT_008c8ba4, iVar6 + 0x6c) != 0.0f) &&
        (DAT_0085a0fc = DAT_0085a0fc + 1, DAT_0085a0fc > 10)) DAT_0085a0fc = 10;
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, iVar6 - 0x40)) return 0x50;
    bool bVar1 = !((F32At(DAT_008c8ba4, iVar6 + 0x5c) == 0.0f) &&
                   (F32At(DAT_008c8ba4, iVar6 + 0x6c) == 0.0f));
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, iVar6)) return (int)(char)(((bVar1 ? 0u : 1u) - 1u & 0x56u) + 0x20u);
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, iVar6 + 0x10)) return (int)((-(uint32_t)bVar1 & 0x105u) + 0x70u);
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, iVar6 + 0x20)) return (int)(char)(((bVar1 ? 0u : 1u) - 1u & 0x17u) + 0x61u);
    if (DAT_0085a164 >= 0 && DAT_008c84d8 < U32At(DAT_008c8ba4, iVar6 + 0x30)) return 9;
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, iVar6 + 0x40)) return 0x175;
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, iVar6 + 0x50)) return 0x172;
    uint32_t* pu = (uint32_t*)(DAT_008c8b24 + iVar4 * 0x50);
    if (DAT_008c84d8 < *pu) return 0x126;
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, iVar6 - 0x70)) return 0x128;
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, iVar6 - 0x10)) return 0x73;
    if ((((F32At(DAT_008c8ba4, iVar6 + 0x5c) != 0.0f) &&
          (DAT_008c84d8 < U32At(DAT_008c8ba4, iVar6 + 0x70))) ||
         ((F32At(DAT_008c8ba4, iVar6 + 0x6c) != 0.0f &&
           (DAT_008c84d8 < U32At(DAT_008c8ba4, iVar6 + 0x60))))) return 0x77;
    int idx = 0;
    do {
        if (DAT_008c84d8 < *pu) return idx + 0x80;
        idx += 1;
        pu += 4;
    } while (idx < 0x14);
    return 0;
}

// 0x42ceb0 — observed shape
int FUN_0042ceb0() {
    int off = (int)(DAT_008c84dc * 0x140);
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, off - 0x40)) return 0x50;
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, off)) return 0x20;
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, off + 0x10)) return 0x51;
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, off + 0x20)) return 0x71;
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, off + 0x30)) return 0x2f;
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, off + 0x40)) return 0x76;
    if (DAT_008c84d8 < U32At(DAT_008c8ba4, off + 0x50)) return 0x78;
    if ((((F32At(DAT_008c8ba4, off + 0x5c) != 0.0f) &&
          (DAT_008c84d8 < U32At(DAT_008c8ba4, off + 0x70))) ||
         ((F32At(DAT_008c8ba4, off + 0x6c) != 0.0f &&
           (DAT_008c84d8 < U32At(DAT_008c8ba4, off + 0x60))))) return 0x77;
    int idx = 0;
    uint32_t* pu = (uint32_t*)(DAT_008c8b24 + DAT_008c84dc * 0x50);
    do {
        if (DAT_008c84d8 < *pu) return idx + 0x80;
        idx += 1;
        pu += 4;
    } while (idx < 0x14);
    return 0;
}

// ---- retry mass_0008: appended definitions for 0x42cf90..0x42dc50 ----
// The 0x140-byte per-element record starts at DAT_008c8ba4; the listings name
// overlapping fields as DAT_008c8bxx / DAT_008c8cxx, expressed below as
// byte offsets from that base (base-relative arithmetic, as above).

// Additional globals referenced by the appended listings.
extern int32_t DAT_0086bb58;
extern int32_t DAT_0086c348;
extern uint8_t DAT_008ee1d4[];
extern int32_t DAT_008ed598;
extern int32_t DAT_008cac00;
extern int32_t DAT_008cabc8;
extern int32_t _DAT_008cabcc;
extern uint8_t* DAT_008e9fd8;
extern int32_t DAT_008ed590;
extern int32_t DAT_008ed594;
extern float   DAT_008e8f7c;
extern float   DAT_008e8f80;
extern float   DAT_008e8f84;
extern int32_t DAT_00726fc4[];
extern void*   PTR_DAT_006fecd8;
extern void*   PTR_DAT_006fecd4;

// Additional helpers referenced by the appended listings.
extern char    FUN_0042c130(int32_t param);
extern int32_t FUN_00431400();
extern void    FUN_0051bfc0(uint32_t* param);
extern void    FUN_004b06c0(const char* text, int32_t a, int32_t b, int32_t c,
                            int32_t d, int32_t e, int32_t f, int32_t g);
extern "C" int   isspace(int ch);
extern "C" int   isprint(int ch);
extern "C" int   atoi(const char* s);
extern "C" char* _itoa(int value, char* buffer, int radix);
extern "C" int   _strnicmp(const char* a, const char* b, size_t n);
extern "C" int   sprintf(char* buffer, const char* format, ...);

// Listings call these with no arguments although the decompiled signatures
// carry parameters; defaults preserve the observed call shape.
int FUN_0042c6f0(int in_edx = 0, int unaff_esi = 0);
float FUN_0042d500(int param_1 = 0, int param_2 = 0);

static inline float AbsF(float v) { return v < 0.0f ? -v : v; }

// 0x42cf90 — observed shape
int FUN_0042cf90() {
    int off = (int)(DAT_008c84dc * 0x140);
    uint32_t pos = DAT_008c84d8;
    if (pos < U32At(DAT_008c8ba4, off - 0x40)) return 0x50;
    if ((U32At(DAT_008c8ba4, off) <= pos) ||
        ((AbsF(F32At(DAT_008c8ba4, off + 0x7c)) <= 0.5f) &&
         (AbsF(F32At(DAT_008c8ba4, off + 0x8c)) <= 0.5f))) {
        if (pos < U32At(DAT_008c8ba4, off + 0x20)) return 0x66;
        if (pos < U32At(DAT_008c8ba4, off + 0x30)) return 0x20;
        if (((F32At(DAT_008c8ba4, off + 0x5c) != 0.0f) &&
             (pos < U32At(DAT_008c8ba4, off + 0x70))) ||
            ((F32At(DAT_008c8ba4, off + 0x6c) != 0.0f) &&
             (pos < U32At(DAT_008c8ba4, off + 0x60)))) {
            return 0x77;
        }
        int idx = 0;
        uint32_t* pu = (uint32_t*)(DAT_008c8b24 + DAT_008c84dc * 0x50);
        do {
            if (pos < *pu) return idx + 0x80;
            idx = idx + 1;
            pu = pu + 4;
        } while (idx < 0x14);
        return 0;
    }
    float fVar1 = F32At(DAT_008c8ba4, off + 0x8c);
    float fVar2 = F32At(DAT_008c8ba4, off + 0x7c);
    if (fVar2 <= 0.35f) {
        if (-0.35f <= fVar2) {
            if ((fVar1 <= 0.35f) && (fVar1 < -0.35f)) return 0x128;
            return 0x126;
        }
        if (0.35f < fVar1) return 0x124;
        if (-0.35f <= fVar1) return 0x125;
        return 0x123;
    }
    if (0.35f < fVar1) return 0x121;
    if (-0.35f <= fVar1) return 0x127;
    return 0x122;
}

// 0x42d120 — observed shape
int FUN_0042d120() {
    int off = (int)(DAT_008c84dc * 0x140);
    uint32_t pos = DAT_008c84d8;
    if (pos < U32At(DAT_008c8ba4, off - 0x40)) return 0x50;
    bool bVar1 = (F32At(DAT_008c8ba4, off - 0x84) != 0.0f) ||
                 (0.0f < F32At(DAT_008c8ba4, off + 0x8c));
    bool bVar2 = (F32At(DAT_008c8ba4, off - 0x74) != 0.0f) ||
                 (F32At(DAT_008c8ba4, off + 0x8c) < 0.0f);
    if (pos < U32At(DAT_008c8ba4, off)) {
        if (bVar1) return 0x124;
        return (uint32_t)(!bVar2) * 2u + 0x123u;
    }
    if (pos < U32At(DAT_008c8ba4, off + 0x10)) {
        if (bVar1) return 0x126;
        return (-(uint32_t)bVar2 & 0x1cu) + 0x10cu;
    }
    if (pos < U32At(DAT_008c8ba4, off + 0x20)) {
        if (bVar1) return 0x121;
        return (-(uint32_t)bVar2 & 0xfffffffb) + 0x127u;
    }
    if (((F32At(DAT_008c8ba4, off + 0x5c) != 0.0f) &&
         (pos < U32At(DAT_008c8ba4, off + 0x70))) ||
        ((F32At(DAT_008c8ba4, off + 0x6c) != 0.0f) &&
         (pos < U32At(DAT_008c8ba4, off + 0x60)))) {
        return 0x127;
    }
    int idx = 0;
    uint32_t* pu = (uint32_t*)(DAT_008c8b24 + DAT_008c84dc * 0x50);
    do {
        if (pos < *pu) return idx + 0x80;
        idx = idx + 1;
        pu = pu + 4;
    } while (idx < 0x14);
    return 0;
}

// 0x42d270 — observed shape
int FUN_0042d270() {
    int off = (int)(DAT_008c84dc * 0x140);
    uint32_t pos = DAT_008c84d8;
    if (pos < U32At(DAT_008c8ba4, off)) return 0x20;
    if (pos < U32At(DAT_008c8ba4, off + 0x40)) return 0x46;
    if (pos < U32At(DAT_008c8ba4, off + 0x50)) return 0x7a;
    if (pos < U32At(DAT_008c8ba4, off - 0x40)) return 0x50;
    if (((F32At(DAT_008c8ba4, off + 0x5c) != 0.0f) &&
         (pos < U32At(DAT_008c8ba4, off + 0x70))) ||
        ((F32At(DAT_008c8ba4, off + 0x6c) != 0.0f) &&
         (pos < U32At(DAT_008c8ba4, off + 0x60)))) {
        return 0x77;
    }
    int idx = 0;
    uint32_t* pu = (uint32_t*)(DAT_008c8b24 + DAT_008c84dc * 0x50);
    do {
        if (pos < *pu) return idx + 0x80;
        idx = idx + 1;
        pu = pu + 4;
    } while (idx < 0x14);
    return 0;
}

// 0x42d460 — observed shape
uint32_t FUN_0042d460() {
    float fVar1 = FUN_0042d500();
    if (0.0f == fVar1) return 0;
    return 1;
}

// 0x42d490 — observed shape
uint32_t FUN_0042d490(int32_t self_ecx, uint32_t param_1) {
    char local_100[256];
    if ((self_ecx != 0) && (DAT_0086bb58 != 0)) {
        // The decompiler dropped the sprintf variadic arguments; the analogous
        // block in FUN_0042d500 passes (name string, key code).
        sprintf(local_100, "%s_%03X", (const char*)(intptr_t)self_ecx, param_1);
        FUN_0051bfc0(&param_1);
    }
    if ((int32_t)param_1 < 0x100) {
        param_1 = (uint32_t)VkKeyScanA((CHAR)param_1);
    }
    return param_1 & 0xff;
}

// 0x42d500 — observed shape
float FUN_0042d500(int param_1, int param_2) {
    SHORT uVar1;
    SHORT SVar2;
    uint32_t uVar3;
    int iVar4;
    uint32_t uVar6 = 0;
    uint32_t local_104;
    char local_100[256];
    float fVar5;
    const int off = (int)(DAT_008c84dc * 0x140);

    if (param_1 == 0x186) {
        local_104 = 0x127;
        uVar3 = 0x127;
        if ((param_2 != 0) && (DAT_0086bb58 != 0)) {
            sprintf(local_100, "%s_%03X", (const char*)(intptr_t)param_2, 0x127u);
            FUN_0051bfc0(&local_104);
            uVar3 = local_104;
            if ((int32_t)local_104 < 0x100) {
                uVar1 = VkKeyScanA((CHAR)local_104);
                uVar3 = (uint32_t)uVar1;
            }
        }
        SVar2 = GetAsyncKeyState(uVar3 & 0xff);
        if (SVar2 < 0) goto L_ret_pos;
        local_104 = 0x125;
        uVar3 = 0x125;
        if ((param_2 != 0) && (DAT_0086bb58 != 0)) {
            sprintf(local_100, "%s_%03X", (const char*)(intptr_t)param_2, 0x125u);
            FUN_0051bfc0(&local_104);
            uVar3 = local_104;
            if ((int32_t)local_104 < 0x100) {
                uVar1 = VkKeyScanA((CHAR)local_104);
                uVar3 = (uint32_t)uVar1;
            }
        }
        SVar2 = GetAsyncKeyState(uVar3 & 0xff);
        if (SVar2 < 0) goto L_ret_neg;
        if (DAT_0086c348 != 0) {
            iVar4 = FUN_0042c6f0();
            if (iVar4 == 0xcb) goto L_ret_neg;
            if (iVar4 == 0xcd) goto L_ret_pos;
        }
        return F32At(DAT_008c8ba4, off + 0x7c);
    }
    if (param_1 == 0x187) {
        local_104 = 0x126;
        uVar3 = 0x126;
        if ((param_2 != 0) && (DAT_0086bb58 != 0)) {
            sprintf(local_100, "%s_%03X", (const char*)(intptr_t)param_2, 0x126u);
            FUN_0051bfc0(&local_104);
            uVar3 = local_104;
            if ((int32_t)local_104 < 0x100) {
                uVar1 = VkKeyScanA((CHAR)local_104);
                uVar3 = (uint32_t)uVar1;
            }
        }
        SVar2 = GetAsyncKeyState(uVar3 & 0xff);
        if (SVar2 < 0) goto L_ret_pos;
        iVar4 = (int)FUN_0042d490(0, 0x128);
        SVar2 = GetAsyncKeyState(iVar4);
        if (-1 < SVar2) {
            if (DAT_0086c348 != 0) {
                iVar4 = FUN_0042c6f0();
                if (iVar4 == 0xcf) goto L_ret_neg;
                if (iVar4 == 0xc9) goto L_ret_pos;
            }
            return F32At(DAT_008c8ba4, off + 0x8c);
        }
        goto L_ret_neg;
    }
    if (param_1 == 0x126) {
        uVar6 = 0x187;
    } else {
        if (param_1 != 0x127) {
            if (param_1 == 0x128) {
                uVar6 = 0x187;
            } else {
                if (param_1 != 0x125) {
                    if (param_1 == 0x110) {
                        SVar2 = GetAsyncKeyState(0x10);
                        if ((SVar2 < 0) ||
                            (F32At(DAT_008c8ba4, off + 0x5c) != 0.0f) ||
                            (F32At(DAT_008c8ba4, off + 0x6c) != 0.0f)) {
                            goto L_ret_pos;
                        }
                        goto L_ret_zero;
                    }
                    if (param_1 < 0x80) goto L_ret_zero;
                    if (param_1 < 0x100) {
                        return F32At(DAT_008c8ba4,
                                     (param_1 - 0x80 + DAT_008c84dc * 0x14) * 0x10 - 0x84);
                    }
                    if (0x1ff < param_1) goto L_ret_zero;
                    SVar2 = GetAsyncKeyState(param_1 - 0x100);
                    if (SVar2 < 0) goto L_ret_pos;
                    goto L_ret_zero;
                }
                uVar6 = 0x186;
            }
            fVar5 = FUN_0042d500((int)uVar6, param_2);
            if (fVar5 < 0.0f) return -fVar5;
            goto L_ret_zero;
        }
        uVar6 = 0x186;
    }
    fVar5 = FUN_0042d500((int)uVar6, param_2);
    if (0.0f < fVar5) return fVar5;

L_ret_zero:
    return 0.0f;
L_ret_pos:
    return 1.0f;
L_ret_neg:
    return -1.0f;
}

// 0x42d890 — observed shape
void FUN_0042d890(int32_t in_eax) {
    char local_68[5];
    uint8_t auStack_63[98];
    if (FUN_0042c130(0) != '\0') {
        if (in_eax != 0) {
            DAT_008ee1d4[DAT_008ed598] = (uint8_t)in_eax;
            DAT_008ed598 = DAT_008ed598 + 1;
            if (0x13 < DAT_008ed598) {
                DAT_008ed598 = 0;
            }
            DAT_008ee1d4[DAT_008ed598] = 0;
        }
        local_68[4] = 0;
        std::memset(auStack_63, 0, sizeof(auStack_63));
        int iVar4 = 0;
        char* pcVar6 = local_68 + 4;
        do {
            std::memcpy(local_68, "   ", 4);
            if (0xf < DAT_008ee1d4[iVar4]) {
                _itoa((int)DAT_008ee1d4[iVar4], local_68, 0x10);
                local_68[2] = 0x20;
            }
            std::strcpy(pcVar6, local_68);
            iVar4 = iVar4 + 1;
            pcVar6 = pcVar6 + 3;
        } while (iVar4 < 0x14);
        DAT_008cac00 = 100;
        FUN_004b06c0(local_68 + 4, 0x14, 0x14, 100, -1, 1, -1, 0);
        DAT_008cac00 = 0;
    }
}

// 0x42d9a0 — observed shape
void FUN_0042d9a0() {
    float fVar1;
    float fVar2;
    SHORT SVar3;
    int iVar4;
    float fVar5;
    float local_4 = 0.0f;

    SVar3 = GetAsyncKeyState(1);
    if (SVar3 != 0) {
        iVar4 = FUN_005f0ddc();
        DAT_008cabc8 = DAT_008cabc8 + iVar4;
        iVar4 = FUN_005f0ddc();
        _DAT_008cabcc = _DAT_008cabcc + iVar4;
    }
    SVar3 = GetAsyncKeyState(2);
    if (SVar3 != 0) {
        fVar5 = (float)(DAT_008dc310 - DAT_008ed590);
        fVar1 = ReadF32(DAT_008e9fd8 + 0x38) * fVar5;
        fVar2 = ReadF32(DAT_008e9fd8 + 0x44) * fVar5;
        fVar5 = ReadF32(DAT_008e9fd8 + 0x50) * fVar5;
        DAT_008e8f7c = DAT_008e8f7c - (fVar1 + fVar1);
        DAT_008e8f80 = DAT_008e8f80 - (fVar2 + fVar2);
        DAT_008e8f84 = DAT_008e8f84 - (fVar5 + fVar5);
    }
    SVar3 = GetAsyncKeyState(0x26);
    if (SVar3 == 0) {
        SVar3 = GetAsyncKeyState(0x28);
        if (SVar3 == 0) {
            SVar3 = GetAsyncKeyState(0x25);
            if (SVar3 == 0) {
                SVar3 = GetAsyncKeyState(0x27);
                if (SVar3 == 0) {
                    DAT_008ed590 = DAT_008dc310;
                    DAT_008ed594 = DAT_008dc30c;
                    return;
                }
                fVar1 = ReadF32(DAT_008e9fd8 + 0x40);
                fVar5 = ReadF32(DAT_008e9fd8 + 0x58);
                fVar2 = ReadF32(DAT_008e9fd8 + 0x4c);
                goto LAB_0042db9c;
            }
            local_4 = ReadF32(DAT_008e9fd8 + 0x58);
            fVar1 = ReadF32(DAT_008e9fd8 + 0x40);
            fVar2 = ReadF32(DAT_008e9fd8 + 0x4c);
        } else {
            SVar3 = GetAsyncKeyState(0x10);
            if (SVar3 != 0) goto LAB_0042dadd;
            fVar1 = ReadF32(DAT_008e9fd8 + 0x38);
            fVar2 = ReadF32(DAT_008e9fd8 + 0x44);
            local_4 = ReadF32(DAT_008e9fd8 + 0x50);
        }
        DAT_008e8f7c = DAT_008e8f7c - (fVar1 * 10.0f + fVar1 * 10.0f);
        DAT_008e8f80 = DAT_008e8f80 - (fVar2 * 10.0f + fVar2 * 10.0f);
        DAT_008e8f84 = DAT_008e8f84 - (local_4 * 10.0f + local_4 * 10.0f);
    } else {
        SVar3 = GetAsyncKeyState(0x10);
        if (SVar3 == 0) {
            fVar1 = ReadF32(DAT_008e9fd8 + 0x38);
            fVar5 = ReadF32(DAT_008e9fd8 + 0x50);
            fVar2 = ReadF32(DAT_008e9fd8 + 0x44);
LAB_0042db9c:
            DAT_008e8f7c = fVar1 * 10.0f + fVar1 * 10.0f + DAT_008e8f7c;
            DAT_008e8f80 = fVar2 * 10.0f + fVar2 * 10.0f + DAT_008e8f80;
            DAT_008e8f84 = fVar5 * 10.0f + fVar5 * 10.0f + DAT_008e8f84;
            goto LAB_0042dbfc;
        }
LAB_0042dadd:
        DAT_008e8f84 = DAT_008e8f84 + 10.0f;
    }
LAB_0042dbfc:
    DAT_008ed594 = DAT_008dc30c;
    DAT_008ed590 = DAT_008dc310;
}

// 0x42dc20 — observed shape
int FUN_0042dc20(int32_t in_eax = 0) {
    if (in_eax == 0) {
        return 1;
    }
    if (((in_eax < -0x80) || (0xff < in_eax)) || (isspace(in_eax & 0xff) == 0)) {
        return 0;
    }
    return 1;
}

// 0x42dc50 — observed shape
int FUN_0042dc50(uint8_t* in_eax) {
    uint8_t bVar1;
    int8_t cVar2;
    int iVar3;

    if ((in_eax == nullptr) || (bVar1 = *in_eax, bVar1 == 0)) {
        return 0;
    }
    if ((-0x81 < (int8_t)bVar1) && ((int8_t)bVar1 < 0x100)) {
        iVar3 = isprint((uint32_t)bVar1);
        if (iVar3 != 0) {
            cVar2 = (int8_t)FUN_0042dc20();
            if (cVar2 != '\0') {
                return (int)(int8_t)*in_eax;
            }
        }
    }
    iVar3 = _strnicmp((char*)in_eax, "space", 5);
    if (iVar3 == 0) {
        cVar2 = (int8_t)FUN_0042dc20();
        if (cVar2 != '\0') {
            return 0x20;
        }
    }
    iVar3 = _strnicmp((char*)in_eax, (const char*)&PTR_DAT_006fecd8, 3);
    if (iVar3 == 0) {
        iVar3 = FUN_00431400();
        if (iVar3 != 0) {
            cVar2 = (int8_t)FUN_0042dc20();
            if (cVar2 != '\0') {
                return DAT_00726fc4[(int)(int8_t)in_eax[3]];
            }
        }
    }
    iVar3 = _strnicmp((char*)in_eax, (const char*)&PTR_DAT_006fecd4, 3);
    if (iVar3 == 0) {
        iVar3 = FUN_00431400();
        if (iVar3 != 0) {
            iVar3 = atoi((char*)(in_eax + 3));
            return iVar3;
        }
    }
    return 0;
}
