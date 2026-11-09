// Reconstruction batch mass_0276 — Sid Meier's Pirates! (2004), PE32 i386
// Candidate definitions translated from Ghidra 12.2 pseudocode. Pseudocode-derived;
// not original source. Receiver registers modeled as explicit void* self parameters.

#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>

using byte = uint8_t;
using undefined4 = uint32_t;

extern void FUN_0060fef7(int, void*);
extern void FUN_0060fcd3(undefined4, void*, int, const char*, ...);
extern void FUN_0060fd9a(undefined4, undefined4, int, const char*, ...);
extern void FUN_00610bd6(void*);
extern int  FUN_0061182b(uint32_t);
extern int  FUN_006117d6(uint32_t);
extern int  FUN_00612061(const void*, const void*);
extern void FUN_00613230();
extern int  FUN_00629497(uint32_t, void**);
extern int  FUN_00610b5f(char*);
extern void FUN_0061239a(void*, undefined4, undefined4, undefined4, undefined4);
extern void FUN_0065c125(uint32_t);
extern void FUN_0065c142();
extern int  FUN_0065c17a(const void*, int, int, const void*);
extern int  FUN_0065c2bf(void*, uint32_t);
extern int  FUN_0065c69a(void*, void*, undefined4, undefined4, undefined4);
extern uint32_t FUN_0065c2b3();
extern void* FUN_00533c78(std::size_t);
extern void operator_delete(void*) noexcept;

extern char DAT_006c7974[];
extern char DAT_006c984c[];
extern char DAT_006e079c[];
extern char DAT_006e07a0[];
extern char DAT_006e07a4[];
extern char DAT_006e07a8[];
extern char DAT_006e07ac[];
extern char DAT_006e07b0[];
extern char DAT_006e07bc[];
extern char DAT_006e0824[];
extern char DAT_006e0828[];
extern char DAT_006e082c[];
extern char DAT_006e0830[];
extern char DAT_006e0834[];
extern char DAT_006e0838[];
extern char DAT_006e083c[];
extern char DAT_006e0840[];
extern char DAT_006e0850[];
extern char DAT_006f5896;
extern const void* PTR_DAT_006de748[];
extern int DAT_006de74c[];
extern int DAT_006de750[];
extern int DAT_006dfda0[];
extern int DAT_006dfde8[];
extern float DAT_006de748_floats[];

// 0x610c00 — observed shape: zero 8 dwords at indices 0,1,2,0xd,0x16,0x17,0x18,0x1e
void FUN_00610c00(void* self) {
    uint32_t* p = static_cast<uint32_t*>(self);
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[0xd] = 0;
    p[0x16] = 0;
    p[0x17] = 0;
    p[0x18] = 0;
    p[0x1e] = 0;
}

// 0x610c1c — observed shape: 13-char "syntax error" gate, then per-version diagnostics
void FUN_00610c1c(void* self, uint32_t* param_1, char* param_2, char param_3) {
    (void)self;
    char local_1004[0xff];
    byte local_f05;
    int iVar2 = 0xd;
    bool bVar5 = true;
    param_1[0x13] = 1;
    char* pcVar3 = param_2;
    const char* pcVar4 = "syntax error";
    do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar5 = *pcVar3 == *pcVar4;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (bVar5) {
        int* piVar1 = reinterpret_cast<int*>(param_1 + 4);
        FUN_0060fef7(2000, piVar1);
        if (*piVar1 == 9) {
            if (param_1[0x15] == 0x7e7) {
                FUN_0060fcd3(param_1[0], piVar1, 0x7e7,
                    "'%s' is not a valid instruction in this shader version", param_1[6]);
            }
            if (param_1[0x15] == 0x7e8) {
                FUN_0060fcd3(param_1[0], piVar1, 0x7e8, "invalid instruction modifiers '%s'", param_1[6]);
            }
        }
    } else {
        _vsnprintf(local_1004, 0x1000, param_2, &param_3);
        local_f05 = 0;
        FUN_0060fcd3(param_1[0], param_1 + 4, 0, DAT_006c7974, local_1004);
    }
}

// 0x610cdc — observed shape: dispatch on param_3 in {1,2,5,6}; always returns 0
undefined4 FUN_00610cdc(undefined4 param_1, undefined4 param_2, int16_t param_3, int param_4,
                        undefined4 param_5, undefined4* param_6) {
    (void)param_1; (void)param_2;
    if (param_3 == 1) {
LAB_00610d23:
        FUN_0060fd9a(param_6[0], param_6[0xc], param_4 + 5000, DAT_006c7974, param_5);
    } else {
        if (param_3 != 2) {
            if (param_3 == 5) goto LAB_00610d23;
            if (param_3 != 6) {
                return 0;
            }
        }
        FUN_0060fcd3(param_6[0], param_6[0xc], param_4 + 5000, DAT_006c7974, param_5);
        param_6[0x13] = 1;
    }
    return 0;
}

// 0x610d4a — observed shape: ECX receiver; on result==0 latch internal error, set index 0x14
int FUN_00610d4a(void* self, int param_1) {
    uint32_t* r = static_cast<uint32_t*>(self);
    if (param_1 == 0) {
        if (r[0x13] == 0) {
            FUN_0060fcd3(r[0], r + 4, 0, "internal error: production failed");
            r[0x13] = 1;
        }
        r[0x14] = 1;
        param_1 = 0;
    }
    return param_1;
}

// 0x610d84 — NEEDS_MANUAL: 0x8e1-byte semantic token parser. Token loop, 0x54-entry
// instruction table at PTR_DAT_006de748 (0x44 stride), variant table DAT_006de750,
// qualifier flag machine and error convergence are preserved; helper token tables are
// expressed through the observed string/constant sets rather than inlined 1000+ lines.
static bool m0276_eq(const char* a, const char* b, int n) {
    for (int i = 0; i < n; ++i) if (a[i] != b[i]) return false;
    return true;
}

int FUN_00610d84(void* self, int param_1) {
    uint32_t* r = static_cast<uint32_t*>(self);
    byte* local_3c = *reinterpret_cast<byte**>(param_1 + 8);
    int local_8 = 0x10d;   // error code, default invalid
    int local_44 = 0;      // current opcode id
    uint32_t local_c = 0;  // caps bitmask
    uint32_t local_10 = 0; // semantic mapping
    int local_40 = 1;      // expecting instruction
    int local_28 = 0, local_30 = 0, local_34 = 0, local_20 = 0;
    int local_2c = 0, local_24 = 0, local_1c = 0, local_38 = 0;
    int iVar8 = 0;
    byte* local_18 = local_3c;
    char tok[16];
    r[0x15] /* +0x54 */ = 0;

    if (*local_3c == 0) {
        r[0x11] = local_c;    // +0x44
        r[0x12] = local_10;   // +0x48
        r[0x10] = (uint32_t)iVar8; // +0x40
        r[0x15] = 0;
        return local_8;
    }
    do {
        iVar8 = 3;
        while (*local_18 != 0 && *local_18 != 0x5f) local_18 = local_18 + 1;
        uint32_t uVar3 = (uint32_t)(local_18 - local_3c);
        if (0xf < uVar3) { local_8 = 0x10d; goto LAB_00611642; }
        memcpy(tok, local_3c, uVar3);
        tok[uVar3] = 0;
        if (*local_18 != 0) local_18 = local_18 + 1;
        local_3c = local_18;

        if (local_40 == 0) {
            // qualifier position: consume pending qualifiers
            if (local_30 != 0 && m0276_eq(tok, DAT_006e0850, 4)) {
                local_c |= 0x100000; local_28 = 0; local_30 = 0; goto LAB_006115e2;
            }
            if (local_34 != 0 && m0276_eq(tok, "centroid", 9)) {
                local_c |= 0x400000; local_34 = 0; goto LAB_006115e2;
            }
            if (local_28 == 0) {
                if (local_20 != 0) {
                    uVar3 = 0;
                    if (m0276_eq(tok, DAT_006e0828, iVar8)) uVar3 = 0x10000000;
                    else if (m0276_eq(tok, DAT_006c984c, 5)) uVar3 = 0x18000000;
                    else if (m0276_eq(tok, "volume", 7)) uVar3 = 0x20000000;
                    local_10 |= uVar3; local_20 = 0;
                    if (uVar3 != 0) { local_2c = 0; local_24 = 0; goto LAB_006115e2; }
                }
                if (local_38 != 0 && m0276_eq(tok, DAT_006e0824, iVar8)) {
                    local_c |= 0x200000; local_38 = 0; goto LAB_006115e2;
                }
                if (local_2c == 0) {
                    if (local_24 == 0) {
                        if (local_1c != 0) {
                            iVar8 = 3;
                            if (m0276_eq(tok, DAT_006e07b0, 3)) local_10 = 1;
                            else if (m0276_eq(tok, DAT_006e07ac, 3)) local_10 = 2;
                            else if (m0276_eq(tok, DAT_006e07a8, 3)) local_10 = 3;
                            else if (m0276_eq(tok, DAT_006e07a4, 3)) local_10 = 4;
                            else if (m0276_eq(tok, DAT_006e07a0, 3)) local_10 = 5;
                            else if (m0276_eq(tok, DAT_006e079c, iVar8)) local_10 = 6;
                            else goto LAB_00611642;
                            local_1c = 0;
                            goto LAB_006115e2;
                        }
                        goto LAB_00611642;
                    }
                    // semantic name [+index] parsing
                    {
                        byte* pbVar4 = reinterpret_cast<byte*>(tok);
                        uint32_t idx = 0;
                        if (*pbVar4 != 0) {
                            while (isalpha((int)(char)*pbVar4)) pbVar4 = pbVar4 + 1;
                            if (*pbVar4 != 0) idx = (uint32_t)atoi(reinterpret_cast<char*>(pbVar4));
                        }
                        if (0xf < idx) { local_8 = 0x10d; goto LAB_00611642; } // falls to LAB_0061137e in listing
                        if (*pbVar4 != 0) { *pbVar4 = 0; pbVar4 = pbVar4 + 1; }
                        byte bVar2 = *pbVar4;
                        if (bVar2 != 0) {
                            while (isdigit((int)(char)bVar2)) { pbVar4 = pbVar4 + 1; bVar2 = *pbVar4; }
                            if (*pbVar4 != 0) { local_8 = 0x10d; goto LAB_00611642; }
                        }
                        uint32_t mask = 0;
                        if (m0276_eq(tok, "position", 9)) mask = 0;
                        else if (m0276_eq(tok, "blendweight", 12)) mask = 1;
                        else if (m0276_eq(tok, "blendindices", 13)) mask = 2;
                        else if (m0276_eq(tok, "normal", 7)) mask = 3;
                        else if (m0276_eq(tok, "psize", 6)) mask = 4;
                        else if (m0276_eq(tok, "texcoord", 9)) mask = 5;
                        else if (m0276_eq(tok, "tangent", 8)) mask = 6;
                        else if (m0276_eq(tok, "binormal", 9)) mask = 7;
                        else if (m0276_eq(tok, "tessfactor", 11)) mask = 8;
                        else if (m0276_eq(tok, "positiont", 10)) mask = 9;
                        else if (m0276_eq(tok, "color", 6)) mask = 10;
                        else if (m0276_eq(tok, DAT_006e07bc, 4)) mask = 0xb;
                        else if (m0276_eq(tok, "depth", 6)) mask = 0xc;
                        else if (m0276_eq(tok, "sample", 7)) mask = 0xd;
                        else { local_8 = 0x10d; goto LAB_00611642; }
                        local_24 = 0;
                        local_10 = (idx & 0xf) << 0x10 | mask;
                    }
                    local_20 = 0;
                    goto LAB_006115e2;
                }
                // swizzle-masked semantic variant
                {
                    byte* pbVar4 = reinterpret_cast<byte*>(tok);
                    uint32_t idx = 0;
                    if (*pbVar4 != 0) {
                        while (isalpha((int)(char)*pbVar4)) pbVar4 = pbVar4 + 1;
                        if (*pbVar4 != 0) idx = (uint32_t)atoi(reinterpret_cast<char*>(pbVar4));
                    }
                    if (0xf < idx) goto LAB_0061137e;
                    byte bVar2 = *pbVar4;
                    if (bVar2 != 0) { *pbVar4 = 0; pbVar4 = pbVar4 + 1; }
                    byte bVar1 = *pbVar4;
                    bool restore = false;
                    if (bVar1 != 0) {
                        while (isdigit((int)(char)bVar1)) { pbVar4 = pbVar4 + 1; bVar1 = *pbVar4; }
                        if (*pbVar4 != 0) restore = true;   // LAB_00611376
                    }
                    {
                        uint32_t mask = 0;
                        bool ok = true;
                        if (m0276_eq(tok, "position", 9)) { if (idx == 0) ok = false; }
                        else if (m0276_eq(tok, "blendweight", 12)) mask = 1;
                        else if (m0276_eq(tok, "blendindices", 13)) mask = 2;
                        else if (m0276_eq(tok, "normal", 7)) mask = 3;
                        else if (m0276_eq(tok, "psize", 6)) mask = 4;
                        else if (m0276_eq(tok, "texcoord", 9)) mask = 5;
                        else if (m0276_eq(tok, "tangent", 8)) mask = 6;
                        else if (m0276_eq(tok, "binormal", 9)) mask = 7;
                        else if (m0276_eq(tok, "tessfactor", 11)) mask = 8;
                        else if (m0276_eq(tok, "positiont", 10)) mask = 9;
                        else if (m0276_eq(tok, "color", 6)) mask = 10;
                        else if (m0276_eq(tok, DAT_006e07bc, 4)) mask = 0xb;
                        else if (m0276_eq(tok, "depth", 6)) mask = 0xc;
                        else if (m0276_eq(tok, "sample", 7)) mask = 0xd;
                        else ok = false;
                        if (!ok || restore) goto LAB_0061137e;
                        local_10 = local_10 | (idx & 0xf) << 0x10 | mask;
                        local_2c = 0;
                        local_20 = 0;
                    }
                }
                goto LAB_006115e2;
            }
            // first-token main instruction table path (LAB from local_40 == 1 below)
            goto LAB_00611642;
        } else {
            // instruction name: linear table scan, 0x44 stride, up to 0x54 entries
            int entry = 0;
            uint32_t off = 0;
            int cmp = 1;
            do {
                const byte* name = static_cast<const byte*>(PTR_DAT_006de748[off / 4]);
                cmp = strcmp(reinterpret_cast<const char*>(tok), reinterpret_cast<const char*>(name));
                if (cmp == 0) break;
                off = off + 0x44;
                entry = entry + 1;
            } while (off < 0x1650);
            if (cmp != 0) { local_8 = 0x10d; goto LAB_00611642; }  // iVar8 == 0x54

            int shaderVer = *reinterpret_cast<int*>(reinterpret_cast<byte*>(r) + 0x38);
            uint32_t xform = DAT_006de750[entry * 0x11 + shaderVer]; // (&DAT_006de750 + (i*0x11+v)*4)
            if (xform < 0xfffffffb) {
                if (xform == 0xfffffffa) local_8 = 0x10c;
                else if (xform == 0) local_8 = 0x102;
                else if (xform == 1) local_8 = 0x103;
                else if (xform == 2) local_8 = 0x104;
                else if (xform == 3) local_8 = 0x105;
                else if (xform == 4) local_8 = 0x106;
                else if (xform == 5) local_8 = 0x107;
            } else {
                if (xform == 0xfffffffb) local_8 = 0x10b;
                else if (xform == 0xfffffffc) local_8 = 0x10a;
                else if (xform == 0xfffffffd) local_8 = 0x108;
                else if (xform == 0xfffffffe) local_8 = 0x109;
                else if (xform == 0xffffffff) {
                    r[0x15] = 0x7e7;
                    local_8 = 0x10d;
                    goto LAB_00611642;
                }
            }
            local_44 = DAT_006de74c[entry * 0x11];
            local_40 = 0;
            if (5 < shaderVer && shaderVer < 10 && 0x102 < local_8 && local_8 < 0x108) local_28 = 1;
            if (((3 < shaderVer && shaderVer < 6) || (5 < shaderVer && shaderVer < 0xf)) &&
                (0x102 < local_8 && local_8 < 0x108) && local_44 != 0x1f) local_30 = 1;
            if (9 < shaderVer) {
                if (shaderVer < 0xf && local_44 == 0x1f) local_34 = 1;
                if (9 < shaderVer && shaderVer < 0xf && 0x102 < local_8 && local_8 < 0x108) local_38 = 1;
            }
            if (((3 < shaderVer && shaderVer < 6) || (9 < shaderVer && shaderVer < 0xf)) &&
                local_44 == 0x1f) local_20 = 1;
            if (0xc < shaderVer && shaderVer < 0xf && local_44 == 0x1f) local_2c = 1;
            if (-1 < shaderVer && shaderVer < 6 && local_44 == 0x1f) local_24 = 1;
            if (local_44 == 0x28 || local_44 == 0x2c || local_44 == 0x5e) local_1c = 1;
            r[0x15] = 0x7e8;
        }
LAB_006115e2:
        ;
    } while (*local_18 != 0);

LAB_0061137e:
    if (local_44 == 0x28) {
        if (local_1c != 0) goto LAB_0061163d;
        if (DAT_006dfda0[r[0xe] /* +0x38 */] != -1) {
            local_44 = 0x29;
            local_8 = 0x10c;
            goto LAB_00611612;
        }
        goto LAB_00611642;
    }
    if (local_44 == 0x2c) {
        if (local_1c != 0) goto LAB_0061163d;
        if (DAT_006dfde8[r[0xe]] == -1) goto LAB_00611642;
        local_44 = 0x2d;
        local_8 = 0x10c;
    }
LAB_00611612:
    if (local_44 == 0x5e && local_1c != 0) {
        goto LAB_00611642;
    }
LAB_0061163d:
    iVar8 = local_44;
    r[0x11] = local_c;
    r[0x12] = local_10;
    r[0x10] = (uint32_t)iVar8;
    r[0x15] = 0;
    return local_8;

LAB_00611642:
    local_8 = 0x10d;
    return local_8;
}

// 0x611665 — observed shape: parse "xyzw"/"rgba" mask into 0x10000/0x20000/0x40000/0x80000
uint32_t FUN_00611665(void* self, int param_1) {
    uint32_t* r = static_cast<uint32_t*>(self);
    char* pcVar1 = *reinterpret_cast<char**>(param_1 + 8);
    uint32_t uVar2 = 0;
    char cVar3;
    if (pcVar1 == nullptr || (cVar3 = *pcVar1) == '\0') {
        return 0xf0000;
    }
    char* pcVar5 = pcVar1;
    uint32_t prev = 0;
    do {
        uint32_t cur;
        if (cVar3 < 'x') {
            if (cVar3 == 'w' || cVar3 == 'a') { cur = 3; uVar2 |= 0x80000; }
            else if (cVar3 == 'b') { cur = 2; uVar2 |= 0x40000; }
            else if (cVar3 == 'g') { cur = 1; uVar2 |= 0x20000; }
            else if (cVar3 == 'r') { cur = 0; uVar2 |= 0x10000; }
            else goto LAB_006116ec;
        } else if (cVar3 == 'x') { cur = 0; uVar2 |= 0x10000; }
        else if (cVar3 == 'y') { cur = 1; uVar2 |= 0x20000; }
        else if (cVar3 == 'z') { cur = 2; uVar2 |= 0x40000; }
        else goto LAB_006116ec;

        if (pcVar5 != pcVar1 && cur <= prev) {
LAB_006116ec:
            FUN_0060fcd3(r[0], param_1, 0x7d3, "invalid mask '%s'", pcVar1);
            r[0x13] = 1;
            return 0;
        }
        pcVar5 = pcVar5 + 1;
        cVar3 = *pcVar5;
        prev = cur;
    } while (cVar3 != '\0');
    return uVar2;
}

// 0x61171a — observed shape: parse swizzle into packed 2-bit fields starting at bit 4
uint32_t FUN_0061171a(void* self, int param_1) {
    uint32_t* r = static_cast<uint32_t*>(self);
    char* pcVar3 = *reinterpret_cast<char**>(param_1 + 8);
    int iVar5 = 0;
    uint32_t local_c = 0;
    if (pcVar3 == nullptr || *pcVar3 == '\0') {
        return 0xe40000;
    }
    uint32_t local_8 = 0x10;
    char* pcVar4 = pcVar3;
    do {
        char cVar2 = *pcVar4;
        if (cVar2 != '\0') {
            if (cVar2 < 'x') {
                if (cVar2 == 'w' || cVar2 == 'a') iVar5 = 3;
                else if (cVar2 == 'b') iVar5 = 2;
                else if (cVar2 == 'g') iVar5 = 1;
                else if (cVar2 == 'r') iVar5 = 0;
                else goto LAB_00611789;
            } else if (cVar2 == 'x') iVar5 = 0;
            else if (cVar2 == 'y') iVar5 = 1;
            else if (cVar2 == 'z') iVar5 = 2;
            else goto LAB_00611789;
            pcVar4 = pcVar4 + 1;
        }
        uint32_t uVar1 = local_8 + 2;
        local_c = local_c | (uint32_t)iVar5 << (local_8 & 0x1f);
        local_8 = uVar1;
    } while (local_8 < 0x18);
    if (*pcVar4 != '\0') {
LAB_00611789:
        FUN_0060fcd3(r[0], param_1, 0x7d4, "invalid swizzle '%s'", pcVar3);
        r[0x13] = 1;
        local_c = 0;
    }
    return local_c;
}

// 0x6117d6 — observed shape: append instruction token through vtable[+0x10], latch errors
int FUN_006117d6(void* self, int param_1) {
    uint32_t* ecx = static_cast<uint32_t*>(self);
    int* piVar1 = *reinterpret_cast<int**>(reinterpret_cast<byte*>(ecx) + 8);
    if (piVar1 != nullptr) {
        uint32_t uVar2 = ecx[0x19];              // +100
        if (uVar2 < ecx[0x17]) {                 // +0x5c
            ecx[0xc] = (uint32_t)param_1;        // +0x30
            int iVar3;
            int* vt = piVar1;
            int iVar3_ = (**(int (**)(int*, undefined4, undefined4, int, uint32_t))(*vt + 0x10))(
                piVar1,
                *reinterpret_cast<undefined4*>(param_1 + 0x10),
                *reinterpret_cast<undefined4*>(param_1 + 0x14),
                (int)(ecx[0x16] + uVar2 * 4),    // +0x58
                ecx[0x17] - uVar2);
            iVar3 = iVar3_;
            if (iVar3 < 0) {
                ecx[0x13] = 1;                   // +0x4c
                ecx[0x14] = 1;                   // +0x50
            }
            ecx[0x19] = ecx[0x17];
            return iVar3;
        }
    }
    return 0;
}

// 0x61182b — observed shape: grow ECX+0x58 dword array to at least count+delta
undefined4 FUN_0061182b(void* self, uint32_t param_1) {
    uint32_t* ecx = static_cast<uint32_t*>(self);
    int iVar3 = param_1;
    uint32_t uVar2 = param_1 + ecx[0x17];
    param_1 = ecx[0x18];
    if (param_1 < uVar2) {
        if (param_1 == 0) param_1 = 0x100;
        if (param_1 < uVar2) {
            do { param_1 = param_1 * 2; } while (param_1 < (uint32_t)(ecx[0x17] + iVar3));
        }
        undefined4* puVar1 = static_cast<undefined4*>(FUN_00533c78((std::size_t)param_1 << 2));
        if (puVar1 == nullptr) return 0x8007000e;
        undefined4* puVar4 = *reinterpret_cast<undefined4**>(reinterpret_cast<byte*>(ecx) + 0x58);
        undefined4* puVar5 = puVar1;
        for (uint32_t n = ecx[0x17] & 0x3fffffff; n != 0; n = n - 1) { *puVar5 = *puVar4; puVar4++; puVar5++; }
        for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
            *reinterpret_cast<byte*>(puVar5) = *reinterpret_cast<byte*>(puVar4);
            puVar4 = reinterpret_cast<undefined4*>(reinterpret_cast<byte*>(puVar4) + 1);
            puVar5 = reinterpret_cast<undefined4*>(reinterpret_cast<byte*>(puVar5) + 1);
        }
        operator_delete(*reinterpret_cast<void**>(reinterpret_cast<byte*>(ecx) + 0x58));
        *reinterpret_cast<undefined4**>(reinterpret_cast<byte*>(ecx) + 0x58) = puVar1;
        ecx[0x18] = param_1;
    }
    return 0;
}

// 0x6118bc — observed shape: grow by 1 then store value and bump count
int FUN_006118bc(void* self, undefined4 param_1) {
    uint32_t* ecx = static_cast<uint32_t*>(self);
    int iVar1 = FUN_0061182b(ecx, 1);
    if (-1 < iVar1) {
        *reinterpret_cast<undefined4*>(
            static_cast<byte*>(*reinterpret_cast<void**>(reinterpret_cast<byte*>(ecx) + 0x58)) +
            ecx[0x17] * 4) = param_1;
        ecx[0x17] = ecx[0x17] + 1;
        iVar1 = 0;
    }
    return iVar1;
}

// 0x6118e5 — observed shape: instruction encoder; preserves error codes, operand
// encoding shifts, SUB-modifier remap, immediate payloads and size-mismatch check.
int FUN_006118e5(void* self, uint32_t param_1) {
    uint32_t* r = static_cast<uint32_t*>(self);
    int iVar4;
    uint32_t uVar2;
    int iVar3, iVar5, iVar6;
    uint32_t uVar7;
    int* piVar8;
    bool bVar9, bVar10;
    uint32_t uVar11;
    char* pcVar12;

    r[0x16];  // code base
    *reinterpret_cast<undefined4*>(param_1 + 0x58) = r[0x17] << 2;   // +0x58 := code offset
    iVar5 = *reinterpret_cast<int*>(param_1 + 0x30);
    piVar8 = reinterpret_cast<int*>(1);
    bVar9 = false;
    if (iVar5 == 0x1f) piVar8 = reinterpret_cast<int*>(2);

    if (r[0x1e] != 0) {
        if (iVar5 == 0x1a || iVar5 == 0x19 || iVar5 == 0x1c || iVar5 == 0x1e) {
            pcVar12 = const_cast<char*>("call, callnz, label, and ret instructions are not allowed in assembly fragments");
            uVar11 = 0x7e9;
LAB_0061195f:
            FUN_0060fcd3(r[0], param_1 + 0x10, (int)uVar11, pcVar12);
            return -0x7fffbffb;
        }
        if ((iVar5 == 0x14 || iVar5 == 0x15 || iVar5 == 0x16 || iVar5 == 0x17 || iVar5 == 0x18) &&
            *reinterpret_cast<int*>(param_1 + 0x48) != 0 &&
            *reinterpret_cast<int*>(*reinterpret_cast<int*>(param_1 + 0x48) + 0x10) == 0) {
            pcVar12 = const_cast<char*>("Matrices cannot be specified in temp registers with the fragment linker");
            uVar11 = 0x7ea;
            goto LAB_0061195f;
        }
    }

    iVar5 = *reinterpret_cast<int*>(param_1 + 0x3c);
    if (iVar5 != 0 && *reinterpret_cast<int*>(iVar5 + 4) == 0x13) {
        bVar9 = *reinterpret_cast<int*>(iVar5 + 0x10) == -1;
        if (*reinterpret_cast<int*>(iVar5 + 0x14) != 0) {
            FUN_0060fcd3(r[0], param_1 + 0x10, 0x7de,
                "source modifiers are not allowed on destination parameters");
            r[0x13] = 1;
        }
        iVar5 = *reinterpret_cast<int*>(iVar5 + 0x28);
        piVar8 = reinterpret_cast<int*>(reinterpret_cast<intptr_t>(piVar8) + 1);
        if (iVar5 != 0) {
            if ((int)r[0xe] < 4 || 5 < (int)r[0xe]) {
                FUN_0060fcd3(r[0], param_1 + 0x10, 0x7d8,
                    "relative addressing of destination parameters is not supported in this shader version");
                r[0x13] = 1;
            } else {
                bVar9 = *reinterpret_cast<int*>(iVar5 + 0x10) == -1 || bVar9;
                if (*reinterpret_cast<int*>(iVar5 + 0x28) != 0) {
                    FUN_0060fcd3(r[0], param_1 + 0x10, 0x7d9,
                        "only one address register reference is allowed in a relative address expression");
                    r[0x13] = 1;
                }
                piVar8 = reinterpret_cast<int*>(reinterpret_cast<intptr_t>(piVar8) + 2);
            }
        }
    }
    if (*reinterpret_cast<int*>(param_1 + 0x40) != 0 &&
        *reinterpret_cast<int*>(*reinterpret_cast<int*>(param_1 + 0x40) + 4) == 0x13) {
        iVar5 = r[0xe];
        if ((-1 < iVar5 && iVar5 < 2) || (5 < iVar5 && iVar5 < 0xb)) {
            FUN_0060fcd3(r[0], param_1 + 0x10, 0x7e5,
                "predicates are not supported in this shader version");
            r[0x13] = 1;
        }
        iVar5 = *reinterpret_cast<int*>(param_1 + 0x40);
        piVar8 = reinterpret_cast<int*>(reinterpret_cast<intptr_t>(piVar8) + 1);
        if (*reinterpret_cast<int*>(iVar5 + 0x10) == -1) bVar9 = true;
        if (*reinterpret_cast<int*>(iVar5 + 0x14) != 0 && *reinterpret_cast<int*>(iVar5 + 0x14) != 0xd000000) {
            FUN_0060fcd3(r[0], param_1 + 0x10, 0x7e3, "source modifiers are not allowed on predicates");
            r[0x13] = 1;
        }
        if (*reinterpret_cast<int*>(iVar5 + 0x28) != 0) {
            FUN_0060fcd3(r[0], param_1 + 0x10, 0x7e4,
                "relative addressing of predicates is not supported in this shader version");
            r[0x13] = 1;
        }
    }

    {
        int nSrc = 0;
        piVar8 = reinterpret_cast<int*>(param_1 + 0x44);
        do {
            iVar5 = *piVar8;
            if (iVar5 == 0) break;
            iVar6 = *reinterpret_cast<int*>(param_1 + 0x30);
            int* piVar1 = reinterpret_cast<int*>(reinterpret_cast<intptr_t>(piVar8) + 1);
            if (iVar6 != 0x51 && iVar6 != 0x30 && iVar6 != 0x2f) {
                if (*reinterpret_cast<int*>(iVar5 + 0x10) == -1) bVar9 = true;
                iVar5 = *reinterpret_cast<int*>(iVar5 + 0x28);
                if (iVar5 != 0) {
                    if (*reinterpret_cast<int*>(iVar5 + 0x10) == -1) bVar9 = true;
                    if (*reinterpret_cast<int*>(iVar5 + 0x28) != 0) {
                        FUN_0060fcd3(r[0], param_1 + 0x10, 0x7d9,
                            "only one address register reference is allowed in a relative address expression");
                        r[0x13] = 1;
                    }
                    if (r[0xe] != 0) piVar1 = reinterpret_cast<int*>(reinterpret_cast<intptr_t>(piVar8) + 2);
                }
            }
            piVar8 = piVar1;
            nSrc = nSrc + 1;
        } while (nSrc < 4);
        (void)nSrc;
    }

    {
        int opcode = *reinterpret_cast<int*>(param_1 + 0x30);
        int slotCount = (opcode == 0x1f) ? 2 : 1;
        {
            int d = *reinterpret_cast<int*>(param_1 + 0x3c);
            if (d != 0 && *reinterpret_cast<int*>(d + 4) == 0x13) {
                slotCount += 1;
                int rel = *reinterpret_cast<int*>(d + 0x28);
                if (rel != 0) {
                    int v = (int)r[0xe];
                    if (v >= 4 && v <= 5) slotCount += 1;
                }
            }
            if (*reinterpret_cast<int*>(param_1 + 0x40) != 0 &&
                *reinterpret_cast<int*>(*reinterpret_cast<int*>(param_1 + 0x40) + 4) == 0x13) {
                slotCount += 1;
            }
        }
        int iVar5r = FUN_0061182b(r, (uint32_t)slotCount);
        if (iVar5r < 0) return iVar5r;
        int expected = (int)r[0x17] + slotCount;

        uint32_t* code = reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(r[0x16]));
        uint32_t uVar7 = (uint32_t)opcode;

        if (opcode == 3) {
            int ver = (int)r[0xe];
            if ((ver >= 0 && ver <= 5) || (ver >= 10 && ver <= 14)) {
                int base = *reinterpret_cast<int*>(param_1 + 0x48);
                uint32_t* mod = reinterpret_cast<uint32_t*>(base + 0x14);
                uint32_t uVar2 = *mod;
                bool err = false;
                switch (uVar2) {
                    case 0x7000000u: *mod = 0x8000000u; break;
                    case 0x0u:       *mod = 0x1000000u; break;
                    case 0x1000000u: *mod = 0x0u;       break;
                    case 0x2000000u: *mod = 0x3000000u; break;
                    case 0x3000000u: *mod = 0x2000000u; break;
                    case 0x4000000u: *mod = 0x5000000u; break;
                    case 0x5000000u: *mod = 0x4000000u; break;
                    case 0x6000000u: err = true; break;
                    case 0x8000000u: *mod = 0x7000000u; break;
                    case 0x9000000u:
                    case 0xa000000u: err = true; break;
                    case 0xb000000u: *mod = 0xc000000u; break;
                    case 0xc000000u: *mod = 0xb000000u; break;
                    case 0xd000000u: err = true; break;
                    default: break;
                }
                if (err) {
                    FUN_0060fcd3(r[0], param_1 + 0x10, 0x7dd,
                        "source modifiers incompatible with SUB instruction");
                    r[0x13] = 1;
                }
                uVar7 = 2;
            }
        }

        if (*reinterpret_cast<int*>(param_1 + 0x54) != 0) uVar7 |= 0x40000000u;
        if (*reinterpret_cast<int*>(param_1 + 0x40) != 0) uVar7 |= 0x10000000u;
        {
            int ver = (int)r[0xe];
            if ((ver > 0 && ver < 6) || (ver > 9 && ver < 0xf)) {
                uVar7 |= (uint32_t)(slotCount - 1) * 0x1000000u;
            }
        }
        int op2 = *reinterpret_cast<int*>(param_1 + 0x30);
        if (op2 == 0x29 || op2 == 0x2d || op2 == 0x5e) {
            uVar7 |= (*reinterpret_cast<uint32_t*>(param_1 + 0x38) & 7) << 0x10;
        }
        code[r[0x17]] = uVar7;
        r[0x17] = r[0x17] + 1;
        iVar6 = (int)r[0x17];
        if (op2 == 0x1f) {
            code[iVar6] = *reinterpret_cast<uint32_t*>(param_1 + 0x38) | 0x80000000u;
            r[0x17] = r[0x17] + 1;
            iVar6 = (int)r[0x17];
        }

        int iVar3 = *reinterpret_cast<int*>(param_1 + 0x3c);
        if (iVar3 != 0 && *reinterpret_cast<int*>(iVar3 + 4) == 0x13) {
            if ((int)r[0xe] == 0 && *reinterpret_cast<int*>(iVar3 + 0x20) == 0xf0000) {
                int op3 = *reinterpret_cast<int*>(param_1 + 0x30);
                if (op3 == 0x15 || op3 == 0x17) *reinterpret_cast<int*>(iVar3 + 0x20) = 0x70000;
                else if (op3 == 0x18) *reinterpret_cast<int*>(iVar3 + 0x20) = 0x30000;
            }
            uVar7 = (((*reinterpret_cast<uint32_t*>(iVar3 + 0x10) | 0xfffffff8u) << 0x14) |
                     (*reinterpret_cast<uint32_t*>(iVar3 + 0x10) & 0x18)) << 8 |
                    (*reinterpret_cast<uint32_t*>(param_1 + 0x34) & 0xff00000u) |
                    (*reinterpret_cast<uint32_t*>(iVar3 + 0x18) & 0x7ffu) |
                    (*reinterpret_cast<uint32_t*>(iVar3 + 0x20) & 0xf0000u);
            if (*reinterpret_cast<int*>(iVar3 + 0x28) != 0) uVar7 |= 0x2000;
            code[r[0x17]] = uVar7;
            r[0x17] = r[0x17] + 1;
            iVar3 = *reinterpret_cast<int*>(iVar3 + 0x28);
            iVar6 = (int)r[0x17];
            if (iVar3 != 0) {
                code[iVar6] =
                    (((*reinterpret_cast<uint32_t*>(iVar3 + 0x10) | 0xfffffff8u) << 0x14) |
                     (*reinterpret_cast<uint32_t*>(iVar3 + 0x10) & 0x18)) << 8 |
                    (*reinterpret_cast<uint32_t*>(iVar3 + 0x14) & 0xf000000u) |
                    (*reinterpret_cast<uint32_t*>(iVar3 + 0x18) & 0x7ffu) |
                    (*reinterpret_cast<uint32_t*>(iVar3 + 0x24) & 0xff0000u);
                r[0x17] = r[0x17] + 1;
                iVar6 = (int)r[0x17];
            }
        }

        iVar3 = *reinterpret_cast<int*>(param_1 + 0x40);
        if (iVar3 != 0 && *reinterpret_cast<int*>(iVar3 + 4) == 0x13) {
            code[iVar6] =
                (((*reinterpret_cast<uint32_t*>(iVar3 + 0x10) | 0xfffffff8u) << 0x14) |
                 (*reinterpret_cast<uint32_t*>(iVar3 + 0x10) & 0x18)) << 8 |
                (*reinterpret_cast<uint32_t*>(iVar3 + 0x14) & 0xf000000u) |
                (*reinterpret_cast<uint32_t*>(iVar3 + 0x18) & 0x7ffu) |
                (*reinterpret_cast<uint32_t*>(iVar3 + 0x24) & 0xff0000u);
            r[0x17] = r[0x17] + 1;
            iVar6 = (int)r[0x17];
        }

        int opcode2 = *reinterpret_cast<int*>(param_1 + 0x30);
        if (opcode2 == 0x51) {
            for (int n = 0; n < 4; ++n) {
                int t = *(reinterpret_cast<int*>(param_1 + 0x44) + n);
                if (t == 0) break;
                int ty = *reinterpret_cast<int*>(t + 0x10);
                if (4 < ty && ty < 9) {
                    *reinterpret_cast<float*>(code + r[0x17]) =
                        (float)*reinterpret_cast<double*>(t + 0x18);
                }
                r[0x17] = r[0x17] + 1;
                iVar6 = (int)r[0x17];
            }
        } else if (opcode2 == 0x30) {
            for (int n = 0; n < 4; ++n) {
                int t = *(reinterpret_cast<int*>(param_1 + 0x44) + n);
                if (t == 0) break;
                int ty = *reinterpret_cast<int*>(t + 0x10);
                if (ty == 2 || ty == 4) {
                    code[iVar6] = *reinterpret_cast<uint32_t*>(t + 0x18);
                }
                r[0x17] = r[0x17] + 1;
                iVar6 = (int)r[0x17];
            }
        } else if (opcode2 == 0x2f) {
            int t = *reinterpret_cast<int*>(param_1 + 0x44);
            code[iVar6] = (uint32_t)(*reinterpret_cast<int*>(t + 0x18) != 0);
            r[0x17] = r[0x17] + 1;
        } else {
            for (int n = 0; n < 4; ++n) {
                int t = *(reinterpret_cast<int*>(param_1 + 0x44) + n);
                if (t == 0) break;
                int op3 = *reinterpret_cast<int*>(param_1 + 0x30);
                if ((int)r[0xe] == 0 && *reinterpret_cast<int*>(t + 0x24) == 0xe40000 &&
                    (op3 == 6 || op3 == 7 || op3 == 0xe || op3 == 0x4e ||
                     op3 == 0xf || op3 == 0x4f)) {
                    *reinterpret_cast<int*>(t + 0x24) = 0xff0000;
                }
                uVar7 = (((*reinterpret_cast<uint32_t*>(t + 0x10) | 0xfffffff8u) << 0x14) |
                         (*reinterpret_cast<uint32_t*>(t + 0x10) & 0x18)) << 8 |
                        (*reinterpret_cast<uint32_t*>(t + 0x14) & 0xf000000u) |
                        (*reinterpret_cast<uint32_t*>(t + 0x18) & 0x7ffu) |
                        (*reinterpret_cast<uint32_t*>(t + 0x24) & 0xff0000u);
                if (*reinterpret_cast<int*>(t + 0x28) != 0) uVar7 |= 0x2000;
                code[r[0x17]] = uVar7;
                r[0x17] = r[0x17] + 1;
                int rel = *reinterpret_cast<int*>(t + 0x28);
                if (rel != 0) {
                    if ((int)r[0xe] == 0) {
                        if (*reinterpret_cast<int*>(rel + 0x10) != 3 ||
                            *reinterpret_cast<int*>(rel + 0x14) != 0 ||
                            *reinterpret_cast<int*>(rel + 0x18) != 0 ||
                            *reinterpret_cast<int*>(rel + 0x24) != 0) {
                            FUN_0060fcd3(r[0], param_1 + 0x10, 0x7d7,
                                "only a0.x is allowed as a relative address register in vs_1_1");
                            r[0x13] = 1;
                        }
                    } else {
                        code[r[0x17]] =
                            (((*reinterpret_cast<uint32_t*>(rel + 0x10) | 0xfffffff8u) << 0x14) |
                             (*reinterpret_cast<uint32_t*>(rel + 0x10) & 0x18)) << 8 |
                            (*reinterpret_cast<uint32_t*>(rel + 0x14) & 0xf000000u) |
                            (*reinterpret_cast<uint32_t*>(rel + 0x18) & 0x7ffu) |
                            (*reinterpret_cast<uint32_t*>(rel + 0x24) & 0xff0000u);
                        r[0x17] = r[0x17] + 1;
                    }
                }
                iVar6 = (int)r[0x17];
            }
        }

        if ((int)r[0x17] != expected) {
            FUN_0060fcd3(r[0], param_1 + 0x10, 0, "internal error: instruction size mismatch");
            r[0x13] = 1;
        }
        if (bVar9) {
            r[0x19] = r[0x17];
        } else {
            int rc = FUN_006117d6(r, (int)(param_1 + 0x10));
            if (rc < 0) r[0x14] = 1;
        }
    }

    return 0;
}

// 0x612061 — observed shape: qsort comparator special-casing _,v/_r/_o tagged strings
int FUN_00612061(const void* a, const void* b) {
    byte* pbVar8 = *reinterpret_cast<byte* const*>(a);
    byte* pbVar6 = *reinterpret_cast<byte* const*>(b);
    auto tag = [](byte* p) { return *reinterpret_cast<short*>(p); };
    if (tag(pbVar8) == 0x5f76 || tag(pbVar8) == 0x5f72 || tag(pbVar8) == 0x5f6f ||
        tag(pbVar6) == 0x5f76 || tag(pbVar6) == 0x5f72 || tag(pbVar6) == 0x5f6f) {
        byte u;
        bool lt;
        do {
            u = *pbVar8;
            lt = u < *pbVar6;
            if (u != *pbVar6) return (1 - (int)lt) - (int)(lt != 0);
            if (u == 0) break;
            u = pbVar8[1];
            lt = u < pbVar6[1];
            if (u != pbVar6[1]) return (1 - (int)lt) - (int)(lt != 0);
            pbVar8 += 2;
            pbVar6 += 2;
        } while (u != 0);
        return 0;
    }
    byte* pbVar3 = pbVar8;
    byte* pbVar4 = pbVar6;
    byte bVar1, bVar2;
    bool bVar9;
    do {
        bVar1 = pbVar3[2];
        bVar2 = pbVar4[2];
        bVar9 = bVar1 < bVar2;
        if (bVar1 != bVar2) return (1 - (int)bVar9) - (int)(bVar9 != 0);
        if (bVar1 == 0) break;
        bVar1 = pbVar3[3];
        bVar9 = bVar1 < pbVar4[3];
        if (bVar1 != pbVar4[3]) return (1 - (int)bVar9) - (int)(bVar9 != 0);
        pbVar3 += 2;
        pbVar4 += 2;
    } while (bVar1 != 0);
    {
        int iVar7 = 2;
        bool lt = false, eq = true;
        do {
            if (iVar7 == 0) break;
            iVar7 = iVar7 + -1;
            lt = *pbVar8 < *pbVar6;
            eq = *pbVar8 == *pbVar6;
            pbVar8 = pbVar8 + 1;
            pbVar6 = pbVar6 + 1;
        } while (eq);
        if (!eq) return (1 - (int)lt) - (int)(lt != 0);
    }
    return 0;
}

// 0x612128 — observed shape: build fragment-info comment 0x464e4946 via D3DX9 callbacks
int FUN_00612128(void* self) {
    uint32_t* r = static_cast<uint32_t*>(self);
    int iVar1;
    int iVar4 = 0;
    FUN_0065c125(0x464e4946);
    iVar1 = (int)r[0x1e];
    void* local_14 = nullptr;
    undefined4* local_8 = nullptr;
    iVar1 = *reinterpret_cast<int*>(iVar1 + 0xac) + *reinterpret_cast<int*>(iVar1 + 0xa8) +
            *reinterpret_cast<int*>(iVar1 + 0xa4) + *reinterpret_cast<int*>(iVar1 + 0xa0) +
            *reinterpret_cast<int*>(iVar1 + 0x9c);
    if (iVar1 != 0) {
        void* _Base = FUN_00533c78((std::size_t)iVar1 * 4);
        local_14 = _Base;
        if (_Base == nullptr) {
            iVar4 = -0x7ff8fff2;
        } else {
            FUN_00610bd6(_Base);
            iVar1 = *reinterpret_cast<int*>(r[0x1e] + 0xac);
            FUN_00610bd6(reinterpret_cast<byte*>(_Base) + iVar1 * 4);
            iVar1 = iVar1 + *reinterpret_cast<int*>(r[0x1e] + 0xa8);
            FUN_00610bd6(reinterpret_cast<byte*>(_Base) + iVar1 * 4);
            iVar1 = iVar1 + *reinterpret_cast<int*>(r[0x1e] + 0x9c);
            FUN_00610bd6(reinterpret_cast<byte*>(_Base) + iVar1 * 4);
            iVar1 = iVar1 + *reinterpret_cast<int*>(r[0x1e] + 0xa0);
            FUN_00610bd6(reinterpret_cast<byte*>(_Base) + iVar1 * 4);
            uint32_t uVar3 = (uint32_t)(iVar1 + *reinterpret_cast<int*>(r[0x1e] + 0xa4));
            qsort(_Base, uVar3, 4, FUN_00612061);
            undefined4* local_10 = reinterpret_cast<undefined4*>((std::size_t)uVar3 * 0x14);
            local_8 = static_cast<undefined4*>(FUN_00533c78((std::size_t)local_10));
            if (local_8 == nullptr) {
                iVar4 = -0x7ff8fff2;
            } else {
                undefined4 local_40[0xe] = {0};
                uint32_t local_34 = uVar3;
                undefined4 local_2c_v = r[0xf] | 4;
                local_40[0] = 0x1c;
                local_40[0] = 0x1c;
                (void)local_2c_v;
                (void)local_34;
                iVar4 = FUN_0065c17a(local_40, 0x1c, 1, nullptr);
                if (-1 < iVar4) {
                    memset(local_8, 0, (std::size_t)local_10);
                    iVar4 = FUN_0065c17a(local_8, (int)(intptr_t)local_10, 1, r + 0xf);
                    if (-1 < iVar4) {
                        uint32_t local_c = 0;
                        if (uVar3 != 0) {
                            undefined4* cur = local_8;
                            do {
                                undefined4* puVar5 = *reinterpret_cast<undefined4**>(
                                    reinterpret_cast<byte*>(local_14) + local_c * 4);
                                iVar4 = FUN_0065c69a(r + 0xa, cur, puVar5[0], puVar5[1], r[0x16]);
                                if (iVar4 < 0) goto LAB_0061237a;
                                local_c = local_c + 1;
                                cur = cur + 5;
                            } while (local_c < uVar3);
                        }
                        iVar4 = FUN_0065c17a("Microsoft (R) D3DX9 Shader Assembler 5.04.00.2904",
                                             0xffffffff, 5, r + 0x9);
                        if (-1 < iVar4) {
                            uVar3 = FUN_0065c2b3();
                            if (uVar3 < 0x8001) {
                                iVar4 = FUN_0061182b(r, uVar3);
                                if (-1 < iVar4) {
                                    memmove(reinterpret_cast<byte*>(r[0x16]) + 4 + uVar3 * 4,
                                            reinterpret_cast<byte*>(r[0x16]) + 4,
                                            r[0x17] * 4 - 4);
                                    iVar4 = FUN_0065c2bf(reinterpret_cast<void*>(r[0x16] + 4), uVar3);
                                    if (-1 < iVar4) {
                                        r[0x17] = r[0x17] + uVar3;
                                        r[0x1a] = r[0x1a] + uVar3;
                                        r[0x19] = r[0x17];
                                        iVar4 = 0;
                                    }
                                }
                            } else {
                                FUN_0060fcd3(r[0], r + 4, 0x7ef, "fragment info exceeds maximum comment size");
                                iVar4 = -0x7fffbffb;
                            }
                        }
                    }
                }
            }
        }
    }
LAB_0061237a:
    operator_delete(local_14);
    operator_delete(local_8);
    FUN_0065c142();
    return iVar4;
}

// 0x61239a — observed shape: store 4 params; zero index 3; index 8 = param_4
void FUN_0061239a(void* self, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4) {
    uint32_t* v = static_cast<uint32_t*>(self);
    v[3] = 0;
    v[0] = param_1;
    v[1] = param_2;
    v[2] = param_3;
    v[8] = param_4;
}

// 0x6123c0 — observed shape: build debug-info comment 0x47554244 with label table
int FUN_006123c0(void* self) {
    uint32_t* r = static_cast<uint32_t*>(self);
    int iVar1, iVar3, iVar8;
    undefined4* local_10 = nullptr;
    undefined4* local_c = nullptr;
    int local_8;
    uint32_t local_40 = 0;
    uint32_t local_48 = 0;
    int local_1c = 0;
    uint32_t local_14 = 0;
    uint8_t local_54[0x28];

    FUN_0065c125(0x47554244);
    memset(local_54, 0, sizeof(local_54));
    local_8 = FUN_0065c17a(local_54, 0x28, 1, nullptr);
    if (local_8 < 0) goto LAB_00612684;

    iVar3 = 0;
    for (iVar1 = (int)r[0xd]; iVar1 != 0; iVar1 = *reinterpret_cast<int*>(iVar1 + 0xc)) {
        if (*reinterpret_cast<int*>(iVar1 + 8) != 0 &&
            *reinterpret_cast<int*>(*reinterpret_cast<int*>(iVar1 + 8) + 4) == 0x12) {
            iVar3 = *reinterpret_cast<int*>(iVar1 + 8);
            break;
        }
    }
    iVar8 = iVar3;
    for (; iVar3 != 0; iVar3 = *reinterpret_cast<int*>(iVar3 + 0xc)) {
        local_40 = local_40 + 1;
    }

    if (local_40 == 0) {
LAB_00612563:
        if ((r[0x1d] == 0 ||
             (local_8 = FUN_0065c17a(reinterpret_cast<void*>(r[0x1d]), -1, 7, r + 0xc), -1 < local_8)) &&
            (r[0x1b] == 0 ||
             ((iVar3 = FUN_0065c17a(reinterpret_cast<void*>(r[0x1b]), (int)r[0x1c], 5, r + 0x13), -1 < iVar3 &&
               (iVar3 = FUN_0065c17a(&DAT_006f5896, 1, 5, nullptr), -1 < iVar3))))) {
            if (FUN_0065c17a("Microsoft (R) D3DX9 Shader Assembler 5.04.00.2904", 0xffffffff, 5, r + 0x14) < 0) {
                local_8 = -1;
            } else {
                uint32_t uVar4 = FUN_0065c2b3();
                if (uVar4 < 0x8001) {
                    local_8 = FUN_0061182b(r, uVar4);
                    if (local_8 < 0) goto LAB_00612684;
                    memmove(reinterpret_cast<byte*>(r[0x16]) + 4 + uVar4 * 4,
                            reinterpret_cast<byte*>(r[0x16]) + 4,
                            r[0x17] * 4 - 4);
                    uint32_t uVar5 = 0;
                    if (local_40 != 0) {
                        int* piVar2 = reinterpret_cast<int*>(local_c) + 1;
                        do {
                            *piVar2 = *piVar2 + (int)((r[0x1a] + uVar4) * 4);
                            uVar5 = uVar5 + 1;
                            piVar2 = piVar2 + 2;
                        } while (uVar5 < local_40);
                    }
                    local_8 = FUN_0065c2bf(reinterpret_cast<void*>(r[0x16] + 4), uVar4);
                    if (local_8 < 0) goto LAB_00612684;
                    r[0x17] = r[0x17] + uVar4;
                    r[0x1a] = r[0x1a] + uVar4;
                    r[0x19] = r[0x17];
                } else {
                    FUN_0060fd9a(r[0], r + 4, 0x7ee,
                        "debug info exceeds maximum comment size; no debug info emitted");
                }
                local_8 = 0;
            }
        }
    } else {
        local_10 = static_cast<undefined4*>(FUN_00533c78((std::size_t)local_40 << 2));
        if (local_10 != nullptr) {
            memset(local_10, 0, (std::size_t)local_40 << 2);
            local_c = static_cast<undefined4*>(FUN_00533c78((std::size_t)local_40 << 3));
            if (local_c != nullptr) {
                local_1c = (int)(local_40 << 3);
                memset(local_c, 0, (std::size_t)local_1c);
                if (iVar8 != 0) {
                    uint16_t* puVar6 = reinterpret_cast<uint16_t*>(
                        reinterpret_cast<byte*>(local_c) + local_40 * 8 - 6);
                    do {
                        *puVar6 = 0xffff;
                        puVar6[-1] = *reinterpret_cast<uint16_t*>(iVar8 + 0x24);
                        *reinterpret_cast<undefined4*>(puVar6 + 1) = *reinterpret_cast<undefined4*>(iVar8 + 0x58);
                        if (*reinterpret_cast<int*>(iVar8 + 0x20) != 0) {
                            int local_18 = 0;
                            iVar3 = FUN_0065c17a(reinterpret_cast<void*>(*reinterpret_cast<int*>(iVar8 + 0x20)),
                                                 -1, 7, &local_18);
                            if (iVar3 < 0) goto LAB_00612684;
                            local_14 = 0;
                            if (local_48 != 0) {
                                do {
                                    if (local_10[local_14] == (undefined4)local_18) break;
                                    local_14 = local_14 + 1;
                                } while (local_14 < local_48);
                            }
                            if (local_14 == local_48) {
                                local_10[local_48] = (undefined4)local_18;
                                local_48 = local_48 + 1;
                            }
                            *puVar6 = (uint16_t)local_14;
                        }
                        iVar8 = *reinterpret_cast<int*>(iVar8 + 0xc);
                        puVar6 = puVar6 - 4;
                    } while (iVar8 != 0);
                }
                if ((local_48 != 0 &&
                     (local_8 = FUN_0065c17a(local_10, (int)(local_48 << 2), 1, r + 0x11), local_8 < 0)) ||
                    (local_8 = FUN_0065c17a(local_c, local_1c, 1, r + 0xf), local_8 < 0)) {
                    goto LAB_00612684;
                }
                goto LAB_00612563;
            }
        }
        local_8 = -0x7ff8fff2;
    }
LAB_00612684:
    operator_delete(local_10);
    operator_delete(local_c);
    FUN_0065c142();
    return local_8;
}

// 0x6126a6 — observed shape: teardown via FUN_00613230, conditional delete of receiver
void FUN_006126a6(void* self, byte param_1) {
    FUN_00613230();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x6126c7 — observed shape: for 7 slots, tear down each non-null element with flag 1
void FUN_006126c7(void* self) {
    uint32_t* v = static_cast<uint32_t*>(self);
    for (uint32_t i = 0; i < 7; ++i) {
        if (v[i] != 0) {
            FUN_006126a6(reinterpret_cast<void*>(static_cast<uintptr_t>(v[i])), 1);
        }
    }
}

// 0x6126e6 — observed shape: clone code buffer via FUN_00629497, copy through vtable
int FUN_006126e6(void* self, undefined4* param_1) {
    uint32_t* ecx = static_cast<uint32_t*>(self);
    int* local_8 = reinterpret_cast<int*>(self);
    int iVar1 = FUN_00629497(ecx[0x17] << 2, reinterpret_cast<void**>(&local_8));
    if (-1 < iVar1) {
        int* obj = local_8;
        uint32_t uVar2 = (**(uint32_t (**)(int*))(*obj + 0x10))(obj);
        undefined4* puVar5 = reinterpret_cast<undefined4*>(ecx[0x16]);
        undefined4* puVar3 = reinterpret_cast<undefined4*>((**(void* (**)(int*))(*obj + 0xc))(obj));
        for (uint32_t uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar3 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar3 = puVar3 + 1;
        }
        for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
            *reinterpret_cast<byte*>(puVar3) = *reinterpret_cast<byte*>(puVar5);
            puVar5 = reinterpret_cast<undefined4*>(reinterpret_cast<byte*>(puVar5) + 1);
            puVar3 = reinterpret_cast<undefined4*>(reinterpret_cast<byte*>(puVar3) + 1);
        }
        *param_1 = (undefined4)(uintptr_t)local_8;
        iVar1 = 0;
    }
    return iVar1;
}

// 0x61273f — observed shape: duplicate string, allocate 0x24 node, register by slot index
undefined4 FUN_0061273f(void* self, char* param_1, undefined4 param_2, undefined4 param_3) {
    uint32_t* ecx = static_cast<uint32_t*>(self);
    int iVar2 = FUN_00610b5f(param_1);
    char* pcVar3 = param_1;
    do { char cVar1 = *pcVar3; pcVar3 = pcVar3 + 1; if (cVar1 == '\0') break; } while (true);
    std::size_t len = (std::size_t)(pcVar3 - (param_1 + 1));
    char* pcVar4 = static_cast<char*>(FUN_00533c78(len));
    if (pcVar4 != nullptr) {
        memcpy(pcVar4, param_1, len);
        void* node = FUN_00533c78(0x24);
        if (node != nullptr) {
            FUN_0061239a(node, static_cast<undefined4>(reinterpret_cast<uintptr_t>(pcVar4)),
                         param_2, param_3, ecx[iVar2]);
            ecx[iVar2] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(node));
            return 0;
        }
    }
    return 0x8007000e;
}

// 0x6127cf — observed shape: zero five 7-dword blocks then scattered indices, set version
void FUN_006127cf(void* self, int param_1) {
    uint32_t* v = static_cast<uint32_t*>(self);
    const int bases[5] = {0, 7, 0xe, 0x15, 0x1c};
    for (int b = 0; b < 5; ++b) {
        for (int i = 0; i < 7; ++i) v[bases[b] + i] = 0;
    }
    v[0x23] = 0;
    v[0x24] = 0;
    v[0x25] = 0;
    v[0x26] = 0;
    v[0x2b] = 0;
    v[0x27] = 0;
    v[0x28] = 0;
    v[0x29] = 0;
    v[0x2a] = 0;
    v[0x2d] = (uint32_t)param_1;
    v[0x2c] = 0;
    if (3 < param_1 && param_1 < 6) v[0x2c] = 1;
}
