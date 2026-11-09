// Clean-room reconstruction from shipped bytes (Ghidra 12.2 corpus only).
// Batch mass_0323. Status: unverified; no byte-match claim.
//
// Receiver convention: the corpus exposes the thiscall ECX/EAX receiver as
// in_ECX / in_EAX. Here it is the explicit `self` parameter and virtual calls
// are function pointers read from the vtable at offset 0 of that object.
// Callee and global labels (FUN_*, PTR_*, DAT_*) are corpus labels; original
// source names are not invented. Observed field offsets, constants, call
// order and conditional structure are preserved.

#include <cstdint>
#include <cstddef>
#include <cstdio>

typedef uint32_t uint;

// thiscall vtable slot: receiver in ECX, stacked arguments vary per slot.
typedef int (*VFn)(void* self, ...);

extern void operator_delete(void* p);

// Callee corpus labels (signatures inferred from call sites; variadic so the
// observed argument lists are preserved verbatim).
extern void* FUN_006a3cac(...);
extern void* FUN_00533c78(...);
extern void* FUN_006a0134(...);

extern int FUN_0061273f(...);
extern int FUN_006a48dd(...);
extern int FUN_006a2b66(...);
extern int FUN_0069fcf5(...);
extern int FUN_006626da(...);
extern int FUN_006a49e3(...);
extern int FUN_0069f930(...);
extern int FUN_0069f1e0(...);
extern int FUN_00662648(...);
extern int FUN_006a0238(...);
extern int FUN_0065cc6f(...);
extern int FUN_0065d9d5(...);
extern int FUN_0065d5bd(...);
extern int FUN_0065da35(...);
extern int FUN_0065cc50(...);
extern int FUN_0069a1bd(...);
extern int FUN_0066254f(...);
extern int FUN_00696ab9(...);
extern int FUN_00662568(...);
extern int FUN_006a114f(...);
extern int FUN_00697497(...);
extern int FUN_006959c5(...);
extern int FUN_00696b3c(...);
extern int FUN_00697138(...);
extern int FUN_006634e9(...);
extern int FUN_0069c4b5(...);
extern int FUN_0069c587(...);
extern int FUN_00696630(...);
extern int FUN_006995be(...);
extern int FUN_0069c3c2(...);
extern int FUN_0069be37(...);
extern int FUN_006a1209(...);
extern int FUN_006a118f(...);
extern int FUN_0069b834(...);
extern int FUN_0069c0f7(...);
extern int FUN_0069cb30(...);
extern int FUN_00699cf5(...);
extern int FUN_00699e43(...);
extern int FUN_0069b36c(...);
extern int FUN_0069b4ba(...);
extern int FUN_00699fa5(...);
extern int FUN_0069b61c(...);
extern int FUN_00699c0e(...);
extern int FUN_0069ab4e(...);
extern int FUN_0069a674(...);
extern int FUN_00695d0c(...);
extern int FUN_006992d0(...);
extern int FUN_006a26b9(...);
extern int FUN_0066be13(...);
extern int FUN_0065e4f2(...);
extern int FUN_00664b28(...);
extern int FUN_006a0152(...);
extern int FUN_006a3d1c(...);
extern int FUN_0066275f(...);
extern int FUN_00694b7c(...);

// Observed global objects (corpus labels).
extern void*   PTR_s_Tessfactor_00720008;
extern uint8_t PTR_FUN_006ee5d0[];   // vtable image for 0x671b5e
extern uint8_t PTR_FUN_006ef628[];   // vtable image for 0x672ecd
extern uint8_t DAT_006ef5d8;

// ---------------------------------------------------------------------------
// 0x671294 — observed shape: reads the reference id at object +0x6c through
// vtable slots 0x54/0x58, formats an asset name ("o_%s%d" or "v_%s%d", plus an
// optional "n_%s" for a small 6/3 object) and loads it, or — when the object's
// +0x158 dword is zero — encodes the id into a 32-bit vstream token and builds
// the resource. Non-contiguous body: 0x6714e6-0x6714f1, 0x671684-0x67168a.
// ---------------------------------------------------------------------------
// 0x671294 — observed shape
int FUN_00671294(void* self, uint param_1, uint* param_2)
{
    int* s = (int*)self;
    int obj = (int)param_1;
    int iVar3 = ((VFn)(*(void**)(*s + 0x54)))(self, *(uint*)(obj + 0x6c));
    uint uVar4 = (uint)((VFn)(*(void**)(*s + 0x58)))(self, *(uint*)(obj + 0x6c));
    int iVar6;
    uint8_t local_50[32];
    uint auStack_30[7];
    uint uStack_14 = 0;
    uint uStack_10;
    uint local_c;
    uint uStack_8;
    char cVar1;
    char* pcVar7;
    char* pcVar10;
    void* uVar11;
    const char* fmt;

    if (s[0x56] != 0) {
        if (*(int*)(obj + 0x6c) == -1)
            return 0;
        if (iVar3 != 0xffff) {
            void** puVar5;
            if ((*(uint8_t*)(*(int*)(s[4] + *(int*)(obj + 4) * 4) + 4) & 0x10) == 0) {
                puVar5 = (void**)FUN_006a3cac(iVar3);
                uVar11 = puVar5[0];
                fmt = "o_%s%d";
            } else {
                puVar5 = (void**)FUN_006a3cac(iVar3);
                uVar11 = puVar5[0];
                fmt = "v_%s%d";
            }
            _snprintf((char*)local_50, 0x20, fmt, uVar11, uVar4);
            local_50[31] = 0;
            iVar6 = FUN_0061273f((const char*)local_50, *(uint*)(obj + 0xc), 1);
            if (iVar6 < 0)
                return iVar6;
            s[0x7c] = s[0x7c] + 1;
            if (((((*(uint8_t*)(s + 0x33) & 1) != 0) &&
                  (iVar6 = *(int*)(obj + 0x60), iVar6 != 0)) &&
                 (*(int*)(iVar6 + 4) == 6)) &&
                (iVar6 = *(int*)(iVar6 + 0x14), *(int*)(iVar6 + 4) == 3)) {
                char* pcVar7b;
                pcVar7 = *(char**)(iVar6 + 0x18);
                pcVar7b = pcVar7 + 1;
                do {
                    cVar1 = *pcVar7;
                    pcVar7 = pcVar7 + 1;
                } while (cVar1 != '\0');
                pcVar10 = (char*)FUN_00533c78(pcVar7 + (3 - (int)pcVar7b));
                if (pcVar10 == (char*)0)
                    return -0x7ff8fff2;
                sprintf(pcVar10, "n_%s", (void*)*(void**)(iVar6 + 0x18));
                iVar6 = FUN_0061273f(pcVar10, *(uint*)(obj + 0xc), 1);
                operator_delete(pcVar10);
                if (iVar6 < 0)
                    return iVar6;
                s[0x7c] = s[0x7c] + 1;
            }
        }
        if (param_2 == nullptr)
            return 0;
        *param_2 = *(uint*)(obj + 0x6c);
        return 0;
    }

    uint code = 0;
    local_c = 0;
    switch (iVar3) {
    case 0: return 1;
    case 1: code = 0; break;
    case 2: code = 1; break;
    case 3: code = 2; break;
    case 4: code = 3; break;
    case 5: code = 4; break;
    case 6: code = 5; break;
    case 7: code = 6; break;
    case 8: code = 7; break;
    case 9:
        code = 8;
        if (uVar4 != 0)
            return -0x7fffbffb;
        goto code_r0x00671408;
    case 10: code = 9; break;
    case 0xb: code = 10; break;
    case 0xc: code = 0xb; break;
    case 0xd: code = 0xc; break;
    case 0xe: code = 0xd; break;
    case 0x11:
        code = 0x80000000;
        local_c = 1;
        break;
    case 0x12:
        code = 0x80000000;
        break;
    default:
        return -0x7fffbffb;
    }
    if (uVar4 > 0xf)
        return -0x7fffbffb;
code_r0x00671408:
    code = code | (uVar4 | 0xffff8000) << 0x10;
    auStack_30[5] = 0;
    if ((*(uint8_t*)(obj + 3) & 1) != 0)
        auStack_30[5] = 0x400000;
    iVar3 = FUN_006a48dd(0x1f);
    if (iVar3 < 0)
        return iVar3;
    iVar3 = FUN_006a2b66(code);
    if (iVar3 < 0)
        return iVar3;
    if ((*(uint8_t*)(*(int*)(s[4] + *(int*)(obj + 4) * 4) + 4) & 0x10) == 0) {
        iVar3 = ((VFn)(*(void**)(*s + 0x84)))(self, obj, auStack_30 + 6, &uStack_14, &local_c);
        if (iVar3 < 0)
            return iVar3;
        local_c = 0;
    } else {
        local_c = local_c | (s[0x1c] << 0x19) >> 0x1f;
        iVar3 = ((VFn)(*(void**)(*s + 0x88)))(self, obj, auStack_30 + 6, &uStack_14);
        if (iVar3 < 0)
            return iVar3;
    }
    auStack_30[4] = 0;
    uStack_10 = 0;
    auStack_30[0] = 0xffffffff;
    auStack_30[1] = 0xffffffff;
    auStack_30[2] = 0xffffffff;
    auStack_30[3] = 0xffffffff;
    if (s[2] != 0) {
        int iVar3b = *(int*)(obj + 4);
        int* piVar8 = (int*)s[5];
        do {
            int iVar2 = *piVar8;
            if (((iVar3b == *(int*)(iVar2 + 4)) &&
                 (*(int*)(obj + 8) == *(int*)(iVar2 + 8))) &&
                (*(int*)(obj + 0xc) == *(int*)(iVar2 + 0xc))) {
                auStack_30[*(int*)(iVar2 + 0x10)] = uStack_10;
            }
            uStack_10 = uStack_10 + 1;
            piVar8 = piVar8 + 1;
        } while (uStack_10 < (uint)s[2]);
    }
    uint uVar9 = 0;
    uVar4 = auStack_30[4];
    do {
        if (auStack_30[uVar9] != 0xffffffff) {
            auStack_30[uVar4] = auStack_30[uVar9];
            uVar4 = uVar4 + 1;
        }
        uVar9 = uVar9 + 1;
    } while (uVar9 < 4);
    iVar3 = ((VFn)(*(void**)(*s + 0x70)))(self, auStack_30, uVar4, &uStack_8, local_c);
    if (iVar3 < 0)
        return iVar3;
    uVar4 = (uint)((VFn)(*(void**)(*s + 0x50)))(self, 4, 0);
    if ((code & 0x7fffffff) == uVar4)
        uStack_8 = uStack_8 | 0xf0000;
    uStack_8 = uStack_8 & 0xffefffff;
    if (((*(uint8_t*)(s + 0x1c) & 0x40) == 0) &&
        (((*(uint8_t*)(s + 0x33) & 0x20) != 0) || ((*(uint8_t*)(obj + 3) & 2) != 0)))
        uStack_8 = uStack_8 | 0x200000;
    iVar6 = ((VFn)(*(void**)(*s + 100)))(
        self,
        (((uStack_14 | 0xfffffff8) << 0x14 | (uStack_14 & 0x18)) << 8) |
            (auStack_30[6] & 0x7ff) | auStack_30[5],
        uStack_8, 0);
    if (iVar6 < 0)
        return iVar6;
    iVar6 = ((VFn)(*(void**)(*s + 0x60)))(self);
    if (iVar6 < 0)
        return iVar6;
    iVar6 = FUN_0069fcf5();
    if (iVar6 < 0)
        return iVar6;
    if (param_2 != nullptr)
        *param_2 = code;
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6716df — observed shape: selects table entry param_1 via +0x14, requires
// the low word of +0xc8 to be >= 0x101 (else emits the shared error), then
// completes the entry's parent chain before encoding it as a 0xb0000000-based
// vstream token and recording it as the last emitted id (+0x138).
// ---------------------------------------------------------------------------
// 0x6716df — observed shape
int FUN_006716df(void* self, int param_1)
{
    int* s = (int*)self;
    int iVar1 = *(int*)(s[5] + param_1 * 4);
    int iVar2;
    uint local_10, local_c, local_8;

    if ((s[0x32] & 0xffff) < 0x101) {
        FUN_006626da();
        iVar2 = -0x7fffbfff;
    } else {
        iVar2 = *(int*)(iVar1 + 8);
        if ((iVar2 == -1) || (iVar2 = FUN_006716df(self, iVar2), -1 < iVar2)) {
            if (s[0x4e] == param_1) {
                iVar2 = 0;
            } else {
                iVar2 = FUN_006a48dd(1);
                if ((((-1 < iVar2) &&
                      (iVar2 = ((VFn)(*(void**)(*s + 100)))(self, 0xb0000000, 0x10000, 0),
                       -1 < iVar2)) &&
                     (iVar2 = ((VFn)(*(void**)(*s + 0x74)))(self, iVar1, &local_10, &local_8),
                      -1 < iVar2)) &&
                    (((iVar2 = ((VFn)(*(void**)(*s + 0x78)))(self, &param_1, 1, 0x10000, &local_c),
                        -1 < iVar2 &&
                       (iVar2 = ((VFn)(*(void**)(*s + 0x68)))(self, local_10, local_c, local_8),
                        -1 < iVar2)) &&
                      ((iVar2 = ((VFn)(*(void**)(*s + 0x60)))(self), -1 < iVar2 &&
                        (iVar2 = FUN_0069fcf5(), -1 < iVar2)))))) {
                    s[0x4e] = param_1;
                    iVar2 = 0;
                }
            }
        }
    }
    return iVar2;
}

// ---------------------------------------------------------------------------
// 0x6717e2 — observed shape: forwards param_1|param_2 to FUN_006a49e3, then
// when the 0x2000 bit is set and the low word of +0xc8 exceeds 0x1ff, re-emits
// a token built from the entry's +0x10 kind (0..3 -> 0xb0/0xb055/0xb0aa/0xb0ff
// tag) and +0xc & 0x7ff, or the fixed 0xf0e40800 when the type flag 0x10 is set.
// ---------------------------------------------------------------------------
// 0x6717e2 — observed shape
int FUN_006717e2(void* self, uint param_1, uint param_2, int param_3)
{
    intptr_t b = (intptr_t)self;
    int iVar2 = FUN_006a49e3(param_1 | param_2);

    if (-1 < iVar2) {
        if ((((param_1 | param_2) & 0x2000) != 0) && (0x1ff < (*(uint*)(b + 200) & 0xffff))) {
            uint uVar3;
            if ((*(uint8_t*)(*(int*)(*(int*)(b + 0x10) +
                                      *(int*)(*(int*)(*(int*)(b + 0x14) + param_3 * 4) + 4) * 4) + 4)
                 & 0x10) == 0) {
                int iVar1 = *(int*)(param_3 * 4 + *(int*)(b + 0x14));
                int kind = *(int*)(iVar1 + 0x10);
                uint uVar4 = *(uint*)(iVar1 + 0xc) & 0x7ff;
                uVar3 = uVar4 | 0xb0000000;
                if (kind != 0) {
                    if (kind == 1)
                        uVar3 = uVar4 | 0xb0550000;
                    else if (kind == 2)
                        uVar3 = uVar4 | 0xb0aa0000;
                    else if (kind == 3)
                        uVar3 = uVar4 | 0xb0ff0000;
                }
            } else {
                uVar3 = 0xf0e40800;
            }
            FUN_006a49e3(uVar3);
        }
        iVar2 = 0;
    }
    return iVar2;
}

// ---------------------------------------------------------------------------
// 0x67187e — observed shape: for a referenced entry whose +0x6c kind is 0x11
// emits the fixed 0xe40000 token into param_4; otherwise delegates to
// FUN_0069f930 unchanged.
// ---------------------------------------------------------------------------
// 0x67187e — observed shape
uint32_t FUN_0067187e(void* self, int* param_1, uint32_t param_2, uint32_t param_3,
                      uint32_t* param_4)
{
    int* s = (int*)self;
    int iVar1 = ((VFn)(*(void**)(*s + 0x54)))(
        self, *(uint*)(*(int*)(s[5] + *param_1 * 4) + 0x6c));
    uint32_t uVar2;

    if (iVar1 == 0x11) {
        *param_4 = 0xe40000;
        uVar2 = 0;
    } else {
        uVar2 = (uint32_t)FUN_0069f930(param_1, param_2, param_3, param_4);
    }
    return uVar2;
}

// ---------------------------------------------------------------------------
// 0x6718c5 — observed shape: delegates to FUN_0069f1e0 and, on success, sets
// *param_4 to 1 when the entry's +0x6c kind is 0x11.
// ---------------------------------------------------------------------------
// 0x6718c5 — observed shape
int FUN_006718c5(void* self, int param_1, uint32_t param_2, uint32_t param_3,
                 uint32_t* param_4)
{
    intptr_t b = (intptr_t)self;
    int iVar1 = FUN_0069f1e0(param_1, param_2, param_3, param_4);

    if (-1 < iVar1) {
        iVar1 = ((VFn)(*(void**)(*(int*)b + 0x54)))(self, *(uint*)(param_1 + 0x6c));
        if (iVar1 == 0x11) {
            *param_4 = 1;
        }
        iVar1 = 0;
    }
    return iVar1;
}

// ---------------------------------------------------------------------------
// 0x671904 — observed shape: accumulates a 0x10000/0x20000/0x40000/0x80000
// type mask across the referenced entries (rejecting duplicates via
// FUN_006626da), then ORs 0x200000 when the 0x40 flag of +0x70 is clear and
// the entry scan at +0x70/+0xcc does not hit a non-matching record. Finally,
// when +0xcc bit 0 is set, copies the ids into the +0x124 table stride
// (+0x128 * 6 - 0x10 dwords).
// ---------------------------------------------------------------------------
// 0x671904 — observed shape
uint32_t FUN_00671904(void* self, int* param_1, uint param_2, uint* param_3, int param_4)
{
    intptr_t b = (intptr_t)self;
    uint uVar4 = 0;
    uint local_8 = 0;

    if (param_4 == 0) {
        if ((*(uint8_t*)(*(int*)(*(int*)(b + 0x14) + *param_1 * 4) + 0x3d) & 2) != 0)
            local_8 = 0x100000;
        if (param_2 != 0) {
            do {
                int iVar2 = *(int*)(*(int*)(*(int*)(b + 0x14) + param_1[uVar4] * 4) + 0x10);
                uint uVar3 = 0;
                if (iVar2 == 0)
                    uVar3 = 0x10000;
                else if (iVar2 == 1)
                    uVar3 = 0x20000;
                else if (iVar2 == 2)
                    uVar3 = 0x40000;
                else if (iVar2 == 3)
                    uVar3 = 0x80000;
                if ((local_8 & uVar3) != 0)
                    FUN_006626da();
                local_8 = local_8 | uVar3;
                uVar4 = uVar4 + 1;
            } while (uVar4 < param_2);
        }
    } else {
        local_8 = 0xf0000;
    }
    if ((*(uint8_t*)(b + 0x70) & 0x40) == 0) {
        if ((*(uint8_t*)(b + 0xcc) & 0x20) == 0) {
            uVar4 = 0;
            bool bVar5 = param_2 == 0;
            if (param_2 != 0) {
                do {
                    int iVar2 = *(int*)(*(int*)(b + 0x14) + param_1[uVar4] * 4);
                    if (((*(uint8_t*)(iVar2 + 3) & 2) == 0) &&
                        (((*(uint8_t*)(*(int*)(*(int*)(b + 0x10) + *(int*)(iVar2 + 4) * 4) + 4)
                           & 1) == 0 ||
                          (*(int*)(iVar2 + 0x48) == -1)) ||
                         (*(int*)(iVar2 + 0x54) != -1)))
                        break;
                    uVar4 = uVar4 + 1;
                } while (uVar4 < param_2);
                bVar5 = uVar4 == param_2;
            }
            if (!bVar5)
                goto LAB_006719f8;
        }
        local_8 = local_8 | 0x200000;
    }
LAB_006719f8:
    if ((((*(uint8_t*)(b + 0xcc) & 1) != 0) &&
         (uVar4 = 0, *(int*)(b + 0x124) != 0)) &&
        (param_2 != 0)) {
        do {
            int* piVar1 = param_1 + uVar4;
            int iVar2 = (int)(uVar4 + *(int*)(b + 0x128) * 6);
            uVar4 = uVar4 + 1;
            *(int*)(*(int*)(b + 0x124) + -0x10 + iVar2 * 4) = *piVar1;
        } while (uVar4 < param_2);
    }
    *param_3 = local_8;
    return 0;
}

// ---------------------------------------------------------------------------
// 0x671a43 — observed shape: for entries whose +4 field matches +0x80/+0x84,
// looks up the "Tessfactor" descriptor through FUN_006a0134 and, when its
// +0x10 dword is not -1, formats "%s%s%u" from the type name table, the
// descriptor's first field and the +0x58 accessor value. Otherwise falls back
// to FUN_00662648.
// ---------------------------------------------------------------------------
// 0x671a43 — observed shape
void FUN_00671a43(void* self, int param_1, char* param_2, size_t param_3)
{
    int* s = (int*)self;

    if ((*(int*)(param_1 + 4) == s[0x20]) || (*(int*)(param_1 + 4) == s[0x21])) {
        uint uVar1 = (uint)((VFn)(*(void**)(*s + 0x54)))(self, *(uint*)(param_1 + 0x6c));
        void** puVar2 = (void**)FUN_006a0134(&PTR_s_Tessfactor_00720008, uVar1);
        if (puVar2[4] != (void*)-1) {
            uVar1 = (uint)((VFn)(*(void**)(*s + 0x58)))(self, *(uint*)(param_1 + 0x6c));
            _snprintf(param_2, param_3, "%s%s%u",
                      (const char*)(uintptr_t)**(uint**)(s[4] + *(int*)(param_1 + 4) * 4),
                      (const char*)puVar2[0], uVar1);
            param_2[param_3 - 1] = '\0';
            return;
        }
    }
    FUN_00662648(param_1, param_2, param_3);
}

// ---------------------------------------------------------------------------
// 0x671acb — observed shape: only for entries whose +0x6c kind is 0x11,
// accepts a set of masked token tags (0x30000000 with a param_2==0 restriction,
// 0x10f00000, and the 0x735..0x738 / 0x744..0x747 families).
// ---------------------------------------------------------------------------
// 0x671acb — observed shape
uint32_t FUN_00671acb(void* self, uint* param_1, int param_2)
{
    intptr_t b = (intptr_t)self;
    uint uVar1 = *param_1 & 0xfff00000;
    bool bVar2;

    if (*(int*)(*(int*)(*(int*)(b + 0x14) +
                         *(int*)(param_1[2] + (*param_1 & 0xfffff) * param_2 * 4) * 4) + 0x6c) == 0x11) {
        if (uVar1 == 0x30000000) {
            if (param_2 == 0)
                return 1;
            return 0;
        }
        if (uVar1 < 0x73800001) {
            if (uVar1 == 0x73800000)
                return 1;
            if (uVar1 == 0x10f00000)
                return 1;
            if (uVar1 == 0x73500000)
                return 1;
            if (uVar1 == 0x73600000)
                return 1;
            bVar2 = uVar1 == 0x73700000;
        } else {
            if (uVar1 == 0x74400000)
                return 1;
            if (uVar1 == 0x74500000)
                return 1;
            if (uVar1 == 0x74600000)
                return 1;
            bVar2 = uVar1 == 0x74700000;
        }
        if (bVar2)
            return 1;
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x671b5e — observed shape: scalar deleting destructor; installs the 0x671b5e
// vtable, runs the base teardown and conditionally frees the object.
// ---------------------------------------------------------------------------
// 0x671b5e — observed shape
void FUN_00671b5e(void* self, uint8_t param_1)
{
    int* s = (int*)self;

    *s = (int)&PTR_FUN_006ee5d0;
    FUN_006a0238();
    if ((param_1 & 1) != 0) {
        operator_delete(s);
    }
}

// ---------------------------------------------------------------------------
// 0x671b9d — observed shape: walks the +0x18 table (count at +0xc), and for
// each non-empty record emits a new vstream id for every referenced entry that
// is not already covered and whose type flags do not end the scan. On first
// need it allocates the id via FUN_0065d9d5 against the +0x88 kind, assigns
// -1 to the source entry's +0x6c, then wraps results into a 0x30000001 record
// with two FUN_0065d9d5-produced constants (1.0 / -1.0) and inserts it at the
// head of the table.
// ---------------------------------------------------------------------------
// 0x671b9d — observed shape
uint32_t FUN_00671b9d(void* self)
{
    int* s = (int*)self;
    int iVar8 = -1;
    uint local_18 = 0;
    uint local_24 = 0;

    if (s[3] != 0) {
        do {
            s[0x3f] = local_18;
            uint* puVar1 = *(uint**)(s[6] + local_18 * 4);
            s[0x40] = (int)puVar1;
            if ((*puVar1 & 0xfff00000) != 0) {
                uint uVar3 = puVar1[1] / (*puVar1 & 0xfffff);
                uint local_8 = 0;
                if (uVar3 != 0) {
                    do {
                        int local_c;
                        uint uVar4 = (uint)FUN_0065cc6f(local_8, &local_c);
                        uint local_10 = 0;
                        if (uVar4 != 0) {
                            do {
                                int iVar9 = (int)(local_10 * 4);
                                uint uVar2 = *(uint*)(*(int*)(s[4] +
                                    *(int*)(*(int*)(s[5] + *(int*)(iVar9 + local_c) * 4) + 4) * 4) + 4);
                                if (((((uVar2 & 0x10) == 0) || ((uVar2 & 0x200) != 0)) ||
                                     (((VFn)(*(void**)(*s + 0x54)))(self) != 0x11)) ||
                                    ((local_8 == 0) &&
                                     ((*(uint*)s[0x40] & 0xfff00000) == 0x30000000)))
                                    break;
                                if (iVar8 == -1) {
                                    uint local_14 = 0;
                                    if (s[2] != 0) {
                                        int* piVar7 = (int*)s[5];
                                        int n = s[2];
                                        do {
                                            if ((s[0x22] == *(int*)(*piVar7 + 4)) &&
                                                (uVar2 = *(uint*)(*piVar7 + 0xc), local_14 <= uVar2))
                                                local_14 = uVar2 + 1;
                                            piVar7 = piVar7 + 1;
                                            n = n + -1;
                                        } while (n != 0);
                                    }
                                    iVar8 = FUN_0065d9d5(s[0x22], local_14, 0, 0);
                                    if (iVar8 == -1)
                                        return 0x8007000e;
                                    FUN_0065d5bd();
                                    *(uint*)(*(int*)(s[5] + iVar8 * 4) + 0x6c) = 0xffffffff;
                                    local_24 = *(uint*)(iVar9 + local_c);
                                }
                                local_10 = local_10 + 1;
                                *(int*)(iVar9 + local_c) = iVar8;
                            } while (local_10 < uVar4);
                        }
                        local_8 = local_8 + 1;
                    } while (local_8 < uVar3);
                }
            }
            local_18 = local_18 + 1;
        } while (local_18 < (uint)s[3]);
        if (iVar8 != -1) {
            int iVar9c = FUN_0065da35(0x30000001, 3, 1);
            if (iVar9c != -1) {
                iVar9c = *(int*)(s[6] + iVar9c * 4);
                FUN_0065cc50();
                **(int**)(iVar9c + 0x10) = iVar8;
                **(uint**)(iVar9c + 8) = local_24;
                uint uVar6 = (uint)FUN_0065d9d5(s[0x1e], 0, 0, 0x3ff0000000000000ULL);
                *(uint*)(*(int*)(iVar9c + 8) + 4) = uVar6;
                uVar6 = (uint)FUN_0065d9d5(s[0x1e], 0, 0, 0xbff0000000000000ULL);
                *(uint*)(*(int*)(iVar9c + 8) + 8) = uVar6;
                if ((*(int*)(*(int*)(iVar9c + 8) + 4) != -1) &&
                    (*(int*)(*(int*)(iVar9c + 8) + 8) != -1)) {
                    uint uVar3b = (uint)s[3];
                    while (1 < uVar3b) {
                        uVar3b = uVar3b - 1;
                        int* piVar7b = (int*)s[6] + uVar3b;
                        *piVar7b = piVar7b[-1];
                    }
                    *(int*)s[6] = iVar9c;
                    return 0;
                }
            }
            return 0x8007000e;
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x671de5 — observed shape: validates a reference batch. Rejects null and the
// 0/0x20700000 tag families, computes the per-entry stride from the low 20
// bits, forces stride 2 for the 0x705/0x706/0x707 families, then counts each
// referenced entry into one of four +0x80/+0x84/+0x88/+0x94 buckets and flags
// the first offending index (or a third +0x7c bucket hit) through param_2.
// A second pass rejects a 0x60000000 record whose kind is 0x12 in the +0x80
// bucket.
// ---------------------------------------------------------------------------
// 0x671de5 — observed shape
uint32_t FUN_00671de5(void* self, uint* param_1, uint* param_2)
{
    int* s = (int*)self;
    uint auStack_ac[18];
    uint auStack_64[18];
    uint local_1c;
    uint local_18;
    uint local_14;
    uint local_c;
    uint local_8;
    int local_10;
    uint uVar7;

    if (param_1 == nullptr)
        return 1;

    uVar7 = *param_1 & 0xfff00000;
    if ((uVar7 != 0) && (uVar7 != 0x20700000)) {
        local_14 = *param_1 & 0xfffff;
        local_c = param_1[1] / local_14;
        if ((uVar7 == 0x70500000) || (uVar7 == 0x70600000) || (uVar7 == 0x70700000))
            local_c = 2;
        if (1 < local_c) {
            int iVar8 = s[0x20];
            int iVar4 = s[0x22];
            int iVar5 = s[0x1f];
            auStack_64[iVar8] = 0;
            auStack_64[iVar4] = 0;
            auStack_64[iVar5] = 0;
            int iVar2 = s[0x25];
            auStack_ac[iVar8] = 1;
            auStack_64[iVar2] = 0;
            auStack_ac[iVar4] = 3;
            auStack_ac[iVar5] = 1;
            bool bVar9 = local_c != 0;
            auStack_ac[iVar2] = 1;
            local_1c = 0;
            local_8 = 0;
            if (bVar9) {
                local_10 = 0;
                do {
                    iVar8 = *(int*)(s[5] + *(int*)(local_10 + (int)param_1[2]) * 4);
                    iVar4 = *(int*)(s[4] + *(int*)(iVar8 + 4) * 4);
                    if ((*(int*)(iVar8 + 0x6c) != 0x11) ||
                        ((*(uint8_t*)(iVar4 + 4) & 0x10) == 0)) {
                        uVar7 = *(uint*)(iVar4 + 4);
                        if ((uVar7 & 0x200) == 0) {
                            if ((signed char)uVar7 < 0)
                                goto LAB_00671f0d;
                            if (((uVar7 & 0x10) == 0) ||
                                (iVar4 = ((VFn)(*(void**)(*s + 0x54)))(
                                     self, *(int*)(iVar8 + 0x6c)),
                                 iVar4 == 0xffff))
                                iVar4 = s[0x22];
                            else
                                iVar4 = s[0x20];
                        } else if ((signed char)uVar7 < 0) {
LAB_00671f0d:
                            iVar4 = s[0x25];
                        } else {
                            iVar4 = s[0x1f];
                        }
                        uVar7 = local_8;
                        local_18 = 0;
                        if (local_8 != 0) {
                            int* piVar6 = (int*)param_1[2];
                            do {
                                iVar5 = *(int*)(s[5] + *piVar6 * 4);
                                if (((*(int*)(iVar8 + 4) == *(int*)(iVar5 + 4)) &&
                                     (*(int*)(iVar8 + 8) == *(int*)(iVar5 + 8))) &&
                                    (*(int*)(iVar8 + 0xc) == *(int*)(iVar5 + 0xc)))
                                    break;
                                local_18 = local_18 + 1;
                                piVar6 = piVar6 + local_14;
                            } while (local_18 < local_8);
                        }
                        if (local_18 == local_8) {
                            uint* puVar1 = auStack_64 + iVar4;
                            *puVar1 = *puVar1 + 1;
                            if (auStack_ac[iVar4] < *puVar1) {
                                if (param_2 == nullptr)
                                    return 1;
                                goto LAB_00672033;
                            }
                        }
                        if ((s[0x1f] == iVar4) && (local_1c = local_1c + 1, 2 < local_1c)) {
                            if (param_2 == nullptr)
                                return 1;
                            uVar7 = local_8;
LAB_00672033:
                            *param_2 = uVar7;
                            return 1;
                        }
                    }
                    local_8 = local_8 + 1;
                    local_10 = (int)(local_10 + local_14 * 4);
                } while (local_8 < local_c);
            }
            local_8 = 0;
            if (local_c != 0) {
                iVar8 = 0;
                local_10 = (int)(local_14 << 2);
                do {
                    if ((*param_1 & 0xf0000000) == 0x60000000) {
                        iVar4 = *(int*)(s[5] + *(int*)(iVar8 + (int)param_1[2]) * 4);
                        iVar5 = ((VFn)(*(void**)(*s + 0x54)))(
                            self, *(uint*)(iVar4 + 0x6c));
                        if ((iVar5 == 0x12) && (*(int*)(iVar4 + 4) == s[0x20])) {
                            if (param_2 != nullptr)
                                *param_2 = local_8;
                            return 1;
                        }
                    }
                    local_8 = local_8 + 1;
                    iVar8 = iVar8 + local_10;
                } while (local_8 < local_c);
            }
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x672056 — observed shape: requires the low word of +0xc8 to be <= 0x1ff and
// the current record's (+0x100) flags word, masked 0xfff0, to be non-zero;
// then recursively completes the parent chain (+8) of the first referenced
// entry and returns that status (0 on success).
// ---------------------------------------------------------------------------
// 0x672056 — observed shape
int FUN_00672056(void* self)
{
    intptr_t b = (intptr_t)self;
    int iVar3;
    int iVar1;

    if ((0x1ff < (*(uint*)(b + 200) & 0xffff)) ||
        (iVar3 = *(int*)(b + 0x100), (*(uint16_t*)(iVar3 + 2) & 0xfff0) == 0)) {
        return 0;
    }
    uint uVar4 = 0;
    if (*(uint*)(iVar3 + 4) != 0) {
        int* piVar2 = *(int**)(iVar3 + 8);
        do {
            iVar1 = *(int*)(*(int*)(b + 0x14) + *piVar2 * 4);
            if (*(int*)(iVar1 + 8) != -1) {
                int iVar3b = FUN_006716df(self, *(uint*)(iVar1 + 8));
                if (iVar3b < 0)
                    return iVar3b;
                return 0;
            }
            uVar4 = uVar4 + 1;
            piVar2 = piVar2 + 1;
        } while (uVar4 < *(uint*)(iVar3 + 4));
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x672079 — observed shape: same parent-chain completion as 0x672056 but the
// record arrives in EAX (explicit argument) instead of being read from +0x100.
// ---------------------------------------------------------------------------
// 0x672079 — observed shape
int FUN_00672079(void* self, intptr_t in_EAX)
{
    intptr_t b = (intptr_t)self;
    uint uVar3 = 0;
    int iVar2;

    if (*(uint*)(in_EAX + 4) != 0) {
        int* piVar1 = *(int**)(in_EAX + 8);
        do {
            iVar2 = *(int*)(*(int*)(b + 0x14) + *piVar1 * 4);
            if (*(int*)(iVar2 + 8) != -1) {
                iVar2 = FUN_006716df(self, *(uint*)(iVar2 + 8));
                if (iVar2 < 0)
                    return iVar2;
                return 0;
            }
            uVar3 = uVar3 + 1;
            piVar1 = piVar1 + 1;
        } while (uVar3 < *(uint*)(in_EAX + 4));
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x6720b2 — observed shape: record dispatcher. Optionally runs the
// 0x30000001 build pass (0x671b9d) first, then walks the +0x18 record array
// (count +0xc) several times, publishing each index to +0xfc and the record to
// +0x100, dispatching on the 0xfff00000 tag to subsystem-specific handlers
// (0x100/0x101/0x103/0x105/0x106/0x107/0x10f/0x114/0x200/0x201/0x204/0x205/
// 0x209/0x300/0x500/0x700/0x703/0x70b/0x735-0x738/0x744-0x747) with the
// observed early-exit on the first negative status.
// ---------------------------------------------------------------------------
// 0x6720b2 — observed shape
int FUN_006720b2(void* self)
{
    intptr_t b = (intptr_t)self;
    int iVar2;
    uint local_8;
    uint local_c;
    uint uVar3;
    uint uVar4;

    if ((*(uint8_t*)(b + 0x70) & 0x40) == 0) {
        iVar2 = FUN_00671b9d(self);
        if (iVar2 < 0)
            return iVar2;
    } else {
        iVar2 = (int)b;
    }
    local_8 = 0;
    if (*(int*)(b + 0xc) != 0) {
        do {
            *(uint*)(b + 0xfc) = local_8;
            uint* puVar1 = *(uint**)(*(int*)(b + 0x18) + local_8 * 4);
            *(uint**)(b + 0x100) = puVar1;
            if ((*puVar1 & 0xfff00000) == 0x11400000) {
                iVar2 = FUN_0069a1bd();
                if (iVar2 < 0)
                    return iVar2;
            } else {
                iVar2 = 1;
            }
            local_8 = local_8 + 1;
        } while (local_8 < *(uint*)(b + 0xc));
    }
    if ((*(uint8_t*)(b + 0xcc) & 4) != 0) {
        FUN_0066254f();
        local_8 = 0;
        if (*(int*)(b + 0xc) != 0) {
            do {
                *(uint*)(b + 0xfc) = local_8;
                uint* puVar1 = *(uint**)(*(int*)(b + 0x18) + local_8 * 4);
                *(uint**)(b + 0x100) = puVar1;
                if ((*puVar1 & 0xfff00000) == 0x10000000) {
                    FUN_00696ab9();
                }
                local_8 = local_8 + 1;
            } while (local_8 < *(uint*)(b + 0xc));
        }
        FUN_00662568();
        if ((*(uint8_t*)(b + 0xcc) & 4) != 0)
            goto LAB_006725be;
    }
    local_8 = 0;
    if (*(int*)(b + 0xc) != 0) {
        do {
            *(uint*)(b + 0xfc) = local_8;
            uint* puVar1 = *(uint**)(*(int*)(b + 0x18) + local_8 * 4);
            *(uint**)(b + 0x100) = puVar1;
            uVar3 = *puVar1 & 0xfff00000;
            if (uVar3 == 0x10100000) {
                iVar2 = FUN_006a114f(1);
LAB_006721e4:
                if (iVar2 < 0)
                    return iVar2;
            } else {
                if (((uVar3 == 0x20000000) || (uVar3 == 0x20100000)) ||
                    (uVar3 == 0x30000000)) {
                    iVar2 = FUN_00697497();
                    FUN_006959c5();
                    goto LAB_006721e4;
                }
                iVar2 = 1;
            }
            local_8 = local_8 + 1;
        } while (local_8 < *(uint*)(b + 0xc));
    }
    if (((*(uint8_t*)(b + 0x6c) & 0x80) != 0) && ((*(uint8_t*)(b + 0x71) & 1) != 0)) {
        local_8 = 0;
        if (*(int*)(b + 0xc) != 0) {
            do {
                *(uint*)(b + 0xfc) = local_8;
                uint* puVar1 = *(uint**)(*(int*)(b + 0x18) + local_8 * 4);
                *(uint**)(b + 0x100) = puVar1;
                if ((*puVar1 & 0xfff00000) == 0x30000000) {
                    if (iVar2 < 0)
                        return iVar2;
                    iVar2 = FUN_00696b3c(0, 0, 0);
                    if (iVar2 < 0)
                        return iVar2;
                    iVar2 = FUN_00697138(0, 0, 0);
                    if (iVar2 < 0)
                        return iVar2;
                } else {
                    iVar2 = 1;
                }
                local_8 = local_8 + 1;
            } while (local_8 < *(uint*)(b + 0xc));
        }
        iVar2 = FUN_006634e9();
        if (iVar2 < 0)
            return iVar2;
        FUN_006959c5();
        local_8 = 0;
        if (*(int*)(b + 0xc) != 0) {
            do {
                *(uint*)(b + 0xfc) = local_8;
                uint* puVar1 = *(uint**)(*(int*)(b + 0x18) + local_8 * 4);
                *(uint**)(b + 0x100) = puVar1;
                uVar3 = *puVar1 & 0xfff00000;
                if (uVar3 == 0x20000000) {
LAB_006722e9:
                    iVar2 = FUN_00697497();
                    FUN_006959c5();
LAB_006722f9:
                    if (iVar2 < 0)
                        return iVar2;
                } else {
                    if (uVar3 == 0x30000000) {
                        iVar2 = FUN_0069c4b5();
                        if (iVar2 < 0)
                            return iVar2;
                        iVar2 = FUN_0069c587();
                        goto LAB_006722f9;
                    }
                    if (uVar3 == 0x70b00000)
                        goto LAB_006722e9;
                    iVar2 = 1;
                }
                local_8 = local_8 + 1;
            } while (local_8 < *(uint*)(b + 0xc));
        }
    }
    local_c = 0;
    if (*(int*)(b + 0xc) != 0) {
        do {
            *(uint*)(b + 0xfc) = local_c;
            uint* puVar1 = *(uint**)(*(int*)(b + 0x18) + local_c * 4);
            *(uint**)(b + 0x100) = puVar1;
            uVar3 = *puVar1 & 0xfff00000;
            if (uVar3 == 0x10500000) {
                if ((*(uint*)(b + 200) & 0xffff) < 0x200)
                    goto LAB_006723bc;
                iVar2 = FUN_00696630();
            } else if (uVar3 == 0x10f00000) {
                iVar2 = FUN_006995be();
            } else if (uVar3 == 0x11400000) {
                iVar2 = FUN_0069a1bd();
            } else if (uVar3 == 0x20100000) {
                if ((*(uint*)(b + 200) & 0xffff) < 0x200)
                    goto LAB_006723bc;
                iVar2 = FUN_0069c3c2();
            } else if (uVar3 == 0x20400000) {
                if ((*(uint8_t*)(b + 0x6c) & 0x20) != 0) {
                    iVar2 = FUN_0069be37();
                }
                if (iVar2 == 1) {
                    iVar2 = FUN_006a1209(1);
                }
            } else {
LAB_006723bc:
                iVar2 = 1;
            }
            local_8 = 0;
            if (*(int*)(b + 0xc) != 0) {
                iVar2 = 1;
                do {
                    *(uint*)(b + 0xfc) = local_8;
                    uint* puVar1b = *(uint**)(*(int*)(b + 0x18) + local_8 * 4);
                    *(uint**)(b + 0x100) = puVar1b;
                    if ((*puVar1b & 0xfff00000) == 0x70000000) {
                        FUN_006a118f();
                    }
                    local_8 = local_8 + 1;
                } while (local_8 < *(uint*)(b + 0xc));
            }
            if (iVar2 < 0)
                return iVar2;
            local_c = local_c + 1;
        } while (local_c < *(uint*)(b + 0xc));
    }
    iVar2 = FUN_006634e9();
    if (iVar2 < 0)
        return iVar2;
    FUN_006959c5();
    local_8 = 0;
    if (*(int*)(b + 0xc) != 0) {
        do {
            *(uint*)(b + 0xfc) = local_8;
            uint* puVar1 = *(uint**)(*(int*)(b + 0x18) + local_8 * 4);
            *(uint**)(b + 0x100) = puVar1;
            uVar3 = *puVar1 & 0xfff00000;
            if (uVar3 == 0x20500000) {
                iVar2 = FUN_0069b834();
LAB_006724e0:
                if (iVar2 < 0)
                    return iVar2;
            } else {
                if (uVar3 == 0x50000000) {
                    if ((*(uint8_t*)(b + 0x6c) & 0x20) != 0) {
                        iVar2 = FUN_0069c0f7();
                    }
                    goto LAB_006724e0;
                }
                if (uVar3 == 0x70300000) {
                    iVar2 = FUN_0069cb30(1);
                    goto LAB_006724e0;
                }
                if ((uVar3 == 0x73500000) || (uVar3 == 0x73600000)) {
                    iVar2 = FUN_00699cf5();
                    if (iVar2 < 0)
                        return iVar2;
                    iVar2 = FUN_00699e43();
                    goto LAB_006724e0;
                }
                if ((uVar3 == 0x74600000) || (uVar3 == 0x74700000)) {
                    iVar2 = FUN_0069b36c();
                    if (iVar2 < 0)
                        return iVar2;
                    iVar2 = FUN_0069b4ba();
                    goto LAB_006724e0;
                }
                iVar2 = 1;
            }
            local_8 = local_8 + 1;
        } while (local_8 < *(uint*)(b + 0xc));
    }
    local_c = 0;
    if (*(int*)(b + 0xc) != 0) {
        do {
            *(uint*)(b + 0xfc) = local_c;
            uint* puVar1 = *(uint**)(*(int*)(b + 0x18) + local_c * 4);
            *(uint**)(b + 0x100) = puVar1;
            uVar3 = *puVar1 & 0xfff00000;
            if (uVar3 < 0x74400001) {
                if (uVar3 == 0x74400000)
                    goto LAB_0067255d;
                if ((((uVar3 != 0x73500000) && (uVar3 != 0x73600000)) &&
                     (uVar3 != 0x73700000)) && (uVar3 != 0x73800000))
                    goto LAB_00672571;
                iVar2 = FUN_00699fa5();
LAB_00672564:
                if (iVar2 < 0)
                    return iVar2;
            } else if (((uVar3 == 0x74500000) || (uVar3 == 0x74600000)) ||
                       (uVar3 == 0x74700000)) {
LAB_0067255d:
                iVar2 = FUN_0069b61c();
                goto LAB_00672564;
            }
LAB_00672571:
            local_c = local_c + 1;
        } while (local_c < *(uint*)(b + 0xc));
    }
    local_c = 0;
    if (*(int*)(b + 0xc) != 0) {
        do {
            *(uint*)(b + 0xfc) = local_c;
            uint* puVar1 = *(uint**)(*(int*)(b + 0x18) + local_c * 4);
            *(uint**)(b + 0x100) = puVar1;
            if (((*puVar1 & 0xfff00000) == 0x73700000) &&
                (iVar2 = FUN_00699c0e(), iVar2 < 0)) {
                return iVar2;
            }
            local_c = local_c + 1;
        } while (local_c < *(uint*)(b + 0xc));
    }
LAB_006725be:
    FUN_006959c5();
    local_c = 0;
    if (*(int*)(b + 0xc) != 0) {
        do {
            *(uint*)(b + 0xfc) = local_c;
            uint* puVar1 = *(uint**)(*(int*)(b + 0x18) + local_c * 4);
            *(uint**)(b + 0x100) = puVar1;
            uVar3 = *puVar1 & 0xfff00000;
            if ((uVar3 == 0x74600000) || (uVar3 == 0x74700000)) {
                iVar2 = FUN_0069b36c();
                if (iVar2 < 0)
                    return iVar2;
                iVar2 = FUN_0069b4ba();
                if (iVar2 < 0)
                    return iVar2;
            }
            local_c = local_c + 1;
        } while (local_c < *(uint*)(b + 0xc));
    }
    uVar3 = 0;
    if (*(int*)(b + 0xc) != 0) {
        do {
            *(uint*)(b + 0xfc) = uVar3;
            uint* puVar1 = *(uint**)(*(int*)(b + 0x18) + uVar3 * 4);
            *(uint**)(b + 0x100) = puVar1;
            uVar4 = *puVar1 & 0xfff00000;
            if ((((uVar4 == 0x74400000) || (uVar4 == 0x74500000)) ||
                 (uVar4 == 0x74600000)) || (uVar4 == 0x74700000)) {
                FUN_0069b61c();
            }
            uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint*)(b + 0xc));
    }
    local_c = 0;
    if (*(int*)(b + 0xc) != 0) {
        do {
            *(uint*)(b + 0xfc) = local_c;
            uint* puVar1 = *(uint**)(*(int*)(b + 0x18) + local_c * 4);
            *(uint**)(b + 0x100) = puVar1;
            if (((*puVar1 & 0xfff00000) == 0x20900000) &&
                (iVar2 = FUN_0069ab4e(), iVar2 < 0)) {
                return iVar2;
            }
            local_c = local_c + 1;
        } while (local_c < *(uint*)(b + 0xc));
    }
    FUN_006959c5();
    local_c = 0;
    if (*(int*)(b + 0xc) != 0) {
        do {
            *(uint*)(b + 0xfc) = local_c;
            uint* puVar1 = *(uint**)(*(int*)(b + 0x18) + local_c * 4);
            *(uint**)(b + 0x100) = puVar1;
            if (((*puVar1 & 0xfff00000) == 0x20900000) &&
                (iVar2 = FUN_0069a674(), iVar2 < 0)) {
                return iVar2;
            }
            local_c = local_c + 1;
        } while (local_c < *(uint*)(b + 0xc));
    }
    local_c = 0;
    if (*(int*)(b + 0xc) != 0) {
        do {
            *(uint*)(b + 0xfc) = local_c;
            uint* puVar1 = *(uint**)(*(int*)(b + 0x18) + local_c * 4);
            *(uint**)(b + 0x100) = puVar1;
            if (((*puVar1 & 0xfff00000) == 0x11400000) &&
                (iVar2 = FUN_00695d0c(), iVar2 < 0)) {
                return iVar2;
            }
            local_c = local_c + 1;
        } while (local_c < *(uint*)(b + 0xc));
    }
    local_c = 0;
    if (*(int*)(b + 0xc) != 0) {
        do {
            *(uint*)(b + 0xfc) = local_c;
            uint* puVar1 = *(uint**)(*(int*)(b + 0x18) + local_c * 4);
            *(uint**)(b + 0x100) = puVar1;
            if (((*puVar1 & 0xfff00000) == 0x70300000) &&
                (iVar2 = FUN_0069cb30(0), iVar2 < 0)) {
                return iVar2;
            }
            local_c = local_c + 1;
        } while (local_c < *(uint*)(b + 0xc));
    }
    FUN_006959c5();
    local_c = 0;
    if (*(int*)(b + 0xc) != 0) {
        do {
            *(uint*)(b + 0xfc) = local_c;
            uint* puVar1 = *(uint**)(*(int*)(b + 0x18) + local_c * 4);
            *(uint**)(b + 0x100) = puVar1;
            uVar3 = *puVar1 & 0xfff00000;
            if ((((uVar3 == 0x10300000) || (uVar3 == 0x10500000)) ||
                 (uVar3 == 0x10600000)) ||
                ((uVar3 == 0x10700000 || (uVar3 == 0x50000000)))) {
                iVar2 = FUN_006992d0();
LAB_006727e1:
                if (iVar2 < 0)
                    return iVar2;
            } else if (uVar3 == 0x70300000) {
                iVar2 = FUN_006a26b9();
                goto LAB_006727e1;
            }
            local_c = local_c + 1;
        } while (local_c < *(uint*)(b + 0xc));
    }
    FUN_006959c5();
    iVar2 = FUN_006634e9();
    if (((-1 < iVar2) && (iVar2 = FUN_0066be13(), -1 < iVar2)) &&
        ((iVar2 = FUN_0065e4f2(), -1 < iVar2) && (iVar2 = FUN_00664b28(), -1 < iVar2))) {
        FUN_006959c5();
        iVar2 = 0;
    }
    return iVar2;
}

// ---------------------------------------------------------------------------
// 0x672ecd — observed shape: constructor. Runs the base init, sets +0x43c to
// -1, installs the 0x672ecd vtable, clears the +0x22c/+0x230 and +0x2b4/+0x2b8
// dwords, clears the 0x10-word array at +0x2c4 and clears +0x404.
// ---------------------------------------------------------------------------
// 0x672ecd — observed shape
void FUN_00672ecd(void* self)
{
    int* s = (int*)self;

    FUN_006a0152();
    s[0x10f] = 0xffffffff;
    *s = (int)&PTR_FUN_006ef628;
    s[0x8b] = 0;
    s[0x8c] = 0;
    s[0x112] = 0;
    s[0xad] = 0;
    s[0xae] = 0;
    s[0xb0] = 0;
    s[0xaf] = 0;
    int* puVar2 = s + 0xb1;
    for (int iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
    }
    s[0x101] = 0;
}

// ---------------------------------------------------------------------------
// 0x672f29 — observed shape: clears the 8-word block at +0x1f8, clears
// +0x218..+0x224, frees and nulls the two pointers at +0x22c/+0x230, then
// forwards the caller argument to FUN_006a3d1c.
// ---------------------------------------------------------------------------
// 0x672f29 — observed shape
void FUN_00672f29(void* self, uint32_t param_1)
{
    intptr_t b = (intptr_t)self;
    uint32_t* puVar2 = (uint32_t*)(b + 0x1f8);

    for (int iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
    }
    *(uint32_t*)(b + 0x218) = 0;
    *(uint32_t*)(b + 0x21c) = 0;
    *(uint32_t*)(b + 0x220) = 0;
    *(uint32_t*)(b + 0x224) = 0;
    operator_delete(*(void**)(b + 0x22c));
    operator_delete(*(void**)(b + 0x230));
    *(uint32_t*)(b + 0x22c) = 0;
    *(uint32_t*)(b + 0x230) = 0;
    FUN_006a3d1c(param_1);
}

// ---------------------------------------------------------------------------
// 0x67303c — observed shape: scans the +0x230 table from index +0x4c up to
// +0x224. For each non-null record with a non-zero count and a tag/first
// reference not matching the +0x84 kind with a 0x10000000 tag, resolves each
// reference to the tail of its +0x38 parent chain and, on finding a kind-3
// tail whose +0x3c flags lack 0x200 (against the head's saved +0x3c), calls
// FUN_0066275f and stops.
// ---------------------------------------------------------------------------
// 0x67303c — observed shape
uint32_t FUN_0067303c(void* self)
{
    intptr_t b = (intptr_t)self;
    uint local_10 = *(uint*)(b + 0x4c);
    uint local_8;
    int iVar3;

    if (local_10 < *(uint*)(b + 0x224)) {
        int* local_c = (int*)(*(int*)(b + 0x230) + local_10 * 4);
        do {
            uint* puVar2 = (uint*)*local_c;
            if (((puVar2 != nullptr) && (*puVar2 != 0)) &&
                ((iVar3 = *(int*)(b + 0x14),
                  *(int*)(*(int*)(iVar3 + *(int*)(uintptr_t)puVar2[4] * 4) + 4) !=
                          *(int*)(b + 0x84) ||
                  ((*puVar2 & 0xfff00000) != 0x10000000))) &&
                (local_8 = 0, puVar2[1] != 0)) {
                int* piVar5 = (int*)puVar2[2];
                do {
                    int iVar4 = *(int*)(iVar3 + *piVar5 * 4);
                    uint* puVar1 = (uint*)(iVar4 + 0x3c);
                    for (; *(int*)(iVar4 + 0x38) != -1;
                         iVar4 = *(int*)(iVar3 + *(int*)(iVar4 + 0x38) * 4)) {
                    }
                    if ((*(signed char*)(iVar4 + 0x6c) == 3) &&
                        (((*(uint*)(iVar4 + 0x3c) | *puVar1) & 0x200) == 0)) {
                        FUN_0066275f();
                        return 0;
                    }
                    local_8 = local_8 + 1;
                    piVar5 = piVar5 + 1;
                } while (local_8 < puVar2[1]);
            }
            local_10 = local_10 + 1;
            local_c = local_c + 1;
        } while (local_10 < *(uint*)(b + 0x224));
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x67311b — observed shape: resolves the current record's (+0x100) +0x1c
// reference through the +0x14 table; when it is a 0x10000000 record, searches
// the +0x100 record's own parent record for an alternate id (local_14), then
// checks whether either id occurs with the same +0x1c value in the current
// reference list. On a hit it rewrites the current record to
// 0x72e00003/count 6 and shifts the +0xc/+0x10/+0x14/+0x18 fields.
// ---------------------------------------------------------------------------
// 0x67311b — observed shape
uint32_t FUN_0067311b(void* self)
{
    intptr_t b = (intptr_t)self;
    uint local_8 = 0;

    int iVar1 = *(int*)(*(int*)(*(int*)(b + 0x14) +
                    *(int*)(*(int*)(*(int*)(b + 0x100) + 8) + 0x1c) * 4) + 0x48);
    if (iVar1 == -1)
        return 1;

    uint* puVar2 = *(uint**)(*(int*)(b + 0x18) + iVar1 * 4);
    if ((*puVar2 & 0xfff00000) == 0x10000000) {
        int local_14 = -1;
        int iVar1b = *(int*)(*(int*)(b + 0x100) + 8);
        int iVar3 = *(int*)(iVar1b + 0x18);
        int iVar7 = *(int*)(*(int*)(b + 0x14) + iVar3 * 4);
        int iVar4 = *(int*)(iVar7 + 0x48);
        uint* puVar5;
        if (((iVar4 != -1) && (*(int*)(iVar7 + 0x3c) == 0)) &&
            (puVar5 = *(uint**)(*(int*)(b + 0x18) + iVar4 * 4),
             (*puVar5 & 0xfff00000) == 0x10000000) &&
            (local_8 = 0, puVar5[1] != 0)) {
            do {
                if (*(int*)((uintptr_t)puVar5[4] + local_8 * 4) == iVar3)
                    local_14 = *(int*)(local_8 * 4 + (uintptr_t)puVar5[2]);
                local_8 = local_8 + 1;
            } while (local_8 < puVar5[1]);
        }
        bool bVar6 = false;
        local_8 = 0;
        if (puVar2[1] != 0) {
            do {
                int iVar7b = (int)(local_8 * 4);
                if ((*(int*)((uintptr_t)puVar2[2] + iVar7b) == iVar3) &&
                    (*(int*)(iVar7b + (uintptr_t)puVar2[4]) == *(int*)(iVar1b + 0x1c)))
                    bVar6 = true;
                if ((*(int*)((uintptr_t)puVar2[2] + iVar7b) == local_14) &&
                    (*(int*)(iVar7b + (uintptr_t)puVar2[4]) == *(int*)(iVar1b + 0x1c)))
                    bVar6 = true;
                local_8 = local_8 + 1;
            } while (local_8 < puVar2[1]);
            if (bVar6) {
                **(uint**)(b + 0x100) = 0x72e00003;
                *(uint*)(*(int*)(b + 0x100) + 4) = 6;
                int p = *(int*)(*(int*)(b + 0x100) + 8);
                *(uint*)(p + 0xc) = *(uint*)(p + 0x10);
                p = *(int*)(*(int*)(b + 0x100) + 8);
                *(uint*)(p + 0x10) = *(uint*)(p + 0x14);
                p = *(int*)(*(int*)(b + 0x100) + 8);
                *(uint*)(p + 0x14) = *(uint*)(p + 0x18);
                return 0;
            }
        }
    }
    return 1;
}

// ---------------------------------------------------------------------------
// 0x673503 — observed shape: for a record whose low 20 tag bits are 3, calls
// FUN_00694b7c with the descriptor at 0x6ef5d8 and the four local seed words
// (0, 1, 2, 3), and on success copies the three returned words into the
// record's +8 data area.
// ---------------------------------------------------------------------------
// 0x673503 — observed shape
int FUN_00673503(void* self)
{
    intptr_t b = (intptr_t)self;
    uint32_t local_f8;
    uint32_t uStack_f4;
    uint32_t uStack_f0;
    uint8_t local_58[64];
    uint32_t local_18;
    uint32_t local_14;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;

    local_8 = 0;
    local_18 = 0;
    int iVar2 = 1;
    local_14 = 1;
    local_10 = 2;
    local_c = 3;
    if ((**(uint**)(b + 0x100) & 0xfffff) == 3) {
        iVar2 = FUN_00694b7c(*(uint**)(b + 0x100), &DAT_006ef5d8, local_58, &local_8,
                             &local_f8, &local_18, 3, 1);
        if (iVar2 == 0) {
            uint32_t* puVar1 = *(uint32_t**)(*(int*)(b + 0x100) + 8);
            puVar1[0] = local_f8;
            puVar1[1] = uStack_f4;
            puVar1[2] = uStack_f0;
            iVar2 = 0;
        }
    }
    return iVar2;
}

// ---------------------------------------------------------------------------
// 0x67357d — observed shape: for a 0x10000000 record and an engine version
// below 0x104, when the first reference's +0x3c is zero, the second reference
// has bit 1 of +0x3d and kind 3, and the second reference's +4 equals +0x88,
// sets +0x3d bit 1 on every referenced record and rewrites every occurrence of
// the record's +0x10 id with its +8 id, then zeroes the current record word.
// ---------------------------------------------------------------------------
// 0x67357d — observed shape
uint32_t FUN_0067357d(void* self)
{
    intptr_t b = (intptr_t)self;

    if (((**(uint**)(b + 0x100) & 0xfff00000) == 0x10000000) &&
        ((*(uint*)(b + 200) & 0xffff) < 0x104)) {
        uint* puVar3 = *(uint**)(b + 0x100);
        uint uVar4 = *puVar3;
        int iVar6 = *(int*)(*(int*)(b + 0x14) + *(int*)(uintptr_t)puVar3[2] * 4);
        int iVar5 = *(int*)(*(int*)(b + 0x14) + *(int*)(uintptr_t)puVar3[4] * 4);
        if ((*(int*)(iVar6 + 0x3c) == 0) &&
            (((*(uint8_t*)(iVar5 + 0x3d) & 2) != 0 &&
              (*(signed char*)(iVar6 + 0x6c) == 3)) &&
             (*(int*)(iVar5 + 4) == *(int*)(b + 0x88)))) {
            uint local_c = 0;
            if ((uVar4 & 0xfffff) != 0) {
                do {
                    int iVar6b = (int)(local_c * 4);
                    uint8_t* pbVar1 = (uint8_t*)(*(int*)(*(int*)(b + 0x14) +
                        *(int*)(iVar6b + *(int*)(*(int*)(b + 0x100) + 8)) * 4) + 0x3d);
                    *pbVar1 = (uint8_t)(*pbVar1 | 2);
                    for (uint uVar7 = *(uint*)(b + 0xfc); uVar7 < *(uint*)(b + 0xc);
                         uVar7 = uVar7 + 1) {
                        int iVar5b = *(int*)(*(int*)(b + 0x18) + uVar7 * 4);
                        uint local_8 = 0;
                        if (*(int*)(iVar5b + 4) != 0) {
                            do {
                                int* piVar2 = (int*)(*(int*)(iVar5b + 8) + local_8 * 4);
                                if (*piVar2 == *(int*)(iVar6b +
                                         *(int*)(*(int*)(b + 0x100) + 0x10)))
                                    *piVar2 = *(int*)(iVar6b +
                                         *(int*)(*(int*)(b + 0x100) + 8));
                                local_8 = local_8 + 1;
                            } while (local_8 < *(uint*)(iVar5b + 4));
                        }
                    }
                    local_c = local_c + 1;
                } while (local_c < (uVar4 & 0xfffff));
            }
            **(uint**)(b + 0x100) = 0;
        }
    }
    return 0;
}
