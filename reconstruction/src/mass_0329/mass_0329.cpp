// mass_0329 — unverified decompiler-derived candidate definitions.
// Clean-room from Ghidra 12.2 pseudocode (analysis/pseudocode/functions/*).
// No compiler or test has been run; no PASS claim.
//
// Register receivers (in_ECX) are modelled as an explicit `void* self`
// parameter; no `this` is used anywhere.

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <math.h>
#include <xmmintrin.h>
#include <windows.h>

// ---------------------------------------------------------------------------
// External helpers referenced by the listings. Argument lists follow the
// corpus; several decompiled call sites dropped the receiver/arguments, so the
// variadic declaration is intentional.
// ---------------------------------------------------------------------------
extern void __cdecl operator_delete(void* p);
extern int __cdecl _stricmp(const char* a, const char* b);

extern int32_t __cdecl FUN_00682fbc(int32_t param_1);
extern void __cdecl FUN_005f7fa4(const void* guid, int value, void* out8);
extern int32_t __cdecl FUN_006a2b66(...);
extern void __cdecl FUN_006626da(...);
extern int32_t __cdecl FUN_0069f138(int param_1);
extern void __cdecl FUN_006a0238(void);
extern void* __cdecl FUN_00533c78(...);
extern int32_t __cdecl FUN_0067095f(void* param_1);
extern int32_t __cdecl FUN_00695343(uint32_t a, uint32_t b, uint32_t c, uint32_t d, int e);
extern void __cdecl FUN_0065db2e(void);
extern int32_t __cdecl FUN_0065da35(uint32_t type, int a, int b);
extern int32_t __cdecl FUN_0065cc50(void);
extern int32_t __cdecl FUN_0065d0b4(void);
extern void* __cdecl FUN_0065cc1a(void);
extern int32_t __cdecl FUN_0065d0ff(uint32_t a, uint32_t b, int c, int d);
extern void __cdecl FUN_00614343(void);
extern void __cdecl FUN_0065e4f2(void);
extern int32_t __cdecl FUN_006a2cbe(void);
extern int32_t __cdecl FUN_00629497(int size, void** out);

// Globals named by the listings.
extern uint8_t DAT_006dd1cc;
extern void* PTR_FUN_006f0938;
extern int32_t DAT_006f0b14[6];
extern float DAT_007209c0;
extern float _DAT_007209b0;
extern float DAT_00720b50;
extern float _DAT_00720b40;

// Cubic spline coefficient block at 0x720a20..0x720a5f, as named by Ghidra.
extern float _DAT_00720a20;
extern float fRam00720a24;
extern float fRam00720a28;
extern float fRam00720a2c;
extern float _DAT_00720a30;
extern float fRam00720a34;
extern float fRam00720a38;
extern float fRam00720a3c;
extern float _DAT_00720a40;
extern float fRam00720a44;
extern float fRam00720a48;
extern float fRam00720a4c;
extern float _DAT_00720a50;
extern float fRam00720a54;
extern float fRam00720a58;
extern float fRam00720a5c;

// Two-dword out-parameter blob used by FUN_005f7fa4 (local_10[4] + local_c).
struct S8 {
    uint32_t a;
    uint32_t b;
};

// ---------------------------------------------------------------------------
// Node tables: self+0x14 holds node pointers, self+0x18 holds primitive
// pointers. Both are plain 4-byte-element pointer arrays.
// ---------------------------------------------------------------------------
static inline uint8_t* recon_node(void* self, uint32_t index)
{
    return (uint8_t*)(intptr_t)(*(int32_t**)((char*)self + 0x14))[index];
}

static inline uint8_t* recon_prim(void* self, uint32_t index)
{
    return (uint8_t*)(intptr_t)(*(int32_t**)((char*)self + 0x18))[index];
}

// ---------------------------------------------------------------------------
// Resolves the indices listed at *(eax+8) through the node table at self+0x14.
// For the first node whose +8 child index is not -1 the child index is passed
// to FUN_00682fbc; a negative result is returned, otherwise 0.
// 0x683c4e — observed shape
int32_t __cdecl FUN_00683c4e(void* self, void* in_eax)
{
    uint32_t uVar3;
    int32_t* piVar1;
    int32_t iVar2;

    uVar3 = 0;
    if (*(uint32_t*)((char*)in_eax + 4) != 0) {
        piVar1 = *(int32_t**)((char*)in_eax + 8);
        do {
            iVar2 = *(int32_t*)(*(int32_t*)((char*)self + 0x14) + *piVar1 * 4);
            if (*(int32_t*)(iVar2 + 8) != -1) {
                iVar2 = FUN_00682fbc(*(int32_t*)(iVar2 + 8));
                if (iVar2 < 0) {
                    return iVar2;
                }
                return 0;
            }
            uVar3 = uVar3 + 1;
            piVar1 = piVar1 + 1;
        } while (uVar3 < *(uint32_t*)((char*)in_eax + 4));
    }
    return 0;
}

// ---------------------------------------------------------------------------
// Resets the render-state block: queries the device caps blob into a two-dword
// local, clears +0x30, sets bit 1 of +0x71, copies the second queried dword to
// +0x108, sets the 0x40 viewport pair, forces +0x6c to 0x80000202 (clearing
// 0x101) and the +0x38 stride to 0x2000.
// 0x684118 — observed shape
int32_t __cdecl FUN_00684118(void* self)
{
    S8 local_10;

    local_10.a = 0;
    local_10.b = 0;
    FUN_005f7fa4(&DAT_006dd1cc, 0, &local_10);
    *(uint32_t*)((char*)self + 0x30) = 0;
    *(uint8_t*)((char*)self + 0x71) = *(uint8_t*)((char*)self + 0x71) | 2;
    *(uint32_t*)((char*)self + 0x108) = local_10.b;
    *(uint32_t*)((char*)self + 0x28) = 0x40;
    *(uint32_t*)((char*)self + 0x2c) = 0x40;
    *(uint32_t*)((char*)self + 0x6c) =
        (*(uint32_t*)((char*)self + 0x6c) & 0xfffffefe) | 0x80000202;
    *(uint32_t*)((char*)self + 0x38) = 0x2000;
    return 0;
}

// ---------------------------------------------------------------------------
// Maps a node's declared usage mask to a semantic enum: bit 0x100 -> 1,
// 0x200 -> 2 (or 9 when the sign bit is clear), 0x10 -> 3, 0x20 -> 4,
// 0x2020 -> 5, 0x40020 -> 6, 1|2 -> 7, 2|4 -> 8. Unknown masks report through
// FUN_006626da when bit 0x10000 is set and return 0x80004005; otherwise the
// enum goes through FUN_006a2b66.
// 0x684169 — observed shape
int32_t __cdecl FUN_00684169(void* self, uint8_t* param_1)
{
    uint32_t uVar1;
    uint32_t uVar2;
    uint32_t* pFlags;

    pFlags = *(uint32_t**)(*(int32_t*)((char*)self + 0x10) + *(int32_t*)(param_1 + 4) * 4);
    uVar1 = *(uint32_t*)((char*)pFlags + 4);
    if ((uVar1 & 0x100) == 0) {
        if (((uVar1 & 0x200) == 0) || (-1 < (char)uVar1)) {
            if ((uVar1 & 0x200) == 0) {
                if ((uVar1 & 0x10) == 0) {
                    if ((uVar1 & 0x2020) == 0x2020) {
                        uVar2 = 5;
                    } else if ((uVar1 & 0x40020) == 0x40020) {
                        uVar2 = 6;
                    } else if ((uVar1 & 0x20) == 0) {
                        if ((uVar1 & 1) == 0) {
                            if (((uVar1 & 2) == 0) || ((uVar1 & 4) == 0)) goto LAB_006841f9;
                            uVar2 = 8;
                        } else {
                            if ((uVar1 & 2) == 0) {
LAB_006841f9:
                                if ((uVar1 & 0x10000) != 0) {
                                    FUN_006626da();
                                }
                                return (int32_t)0x80004005;
                            }
                            uVar2 = 7;
                        }
                    } else {
                        uVar2 = 4;
                    }
                    uVar2 = (uint32_t)FUN_006a2b66(uVar2);
                    return (int32_t)uVar2;
                }
                uVar2 = 3;
            } else {
                uVar2 = 2;
            }
        } else {
            uVar2 = 9;
        }
    } else {
        uVar2 = 1;
    }
    uVar2 = (uint32_t)FUN_006a2b66(uVar2);
    return (int32_t)uVar2;
}

// ---------------------------------------------------------------------------
// Appends one dword pair to the instruction buffer at self+0x10c, advancing the
// write cursor at self+0x110 by two. Only performed when FUN_0069f138(2)
// succeeds.
// 0x68422a — observed shape
int32_t __cdecl FUN_0068422a(void* self, uint32_t param_1, uint32_t param_2)
{
    int32_t iVar3;
    uint8_t* base;
    int32_t* piVar1;
    int32_t iVar2;

    iVar3 = FUN_0069f138(2);
    if (-1 < iVar3) {
        base = (uint8_t*)(intptr_t)*(int32_t*)((char*)self + 0x10c);
        piVar1 = (int32_t*)((char*)self + 0x110);
        iVar2 = *piVar1;
        *(uint32_t*)(base + iVar2 * 4) = param_1;
        *(uint32_t*)(base + 4 + iVar2 * 4) = param_2;
        *piVar1 = *piVar1 + 2;
        iVar3 = 0;
    }
    return iVar3;
}

// ---------------------------------------------------------------------------
// Binds one shader input/output semantic. Packed-format contexts take the id
// straight from the counter at self+0x1f8. Otherwise the descriptor name at
// *(*(param_1+0x68)+0x18) is split into an alphabetic prefix and a decimal
// suffix; the index is that suffix plus *(param_1+0x70)>>2. "position"/"psize"
// select input semantics 2/3 when the usage mask has 0x10 and not 0x200;
// "color" selects output semantic 1. Mismatches with the descriptor's output
// flag report through FUN_006626da. The packed result (semantic|index<<8) is
// stored at param_1+0x6c, and 0x80004005 is returned when validation failed.
// 0x684262 — observed shape
uint32_t __cdecl FUN_00684262(void* self, uint8_t* param_1)
{
    int32_t iVar6 = 0;
    uint32_t local_8 = 0;
    char local_2c[32];
    void* local_c;
    uint32_t uVar7 = 0;
    uint32_t uVar1;
    bool bVar8 = false;
    bool bVar9 = false;
    int32_t iVar4;
    char cVar2;
    char* pcVar5;

    if ((*(uint32_t*)((char*)self + 200) & 0xffff0000) == 0x46580000) {
        if (*(int32_t*)(param_1 + 0x6c) == -1) {
            int32_t* piVar3 = (int32_t*)((char*)self + 0x1f8);
            *(int32_t*)(param_1 + 0x6c) = *piVar3;
            *piVar3 = *piVar3 + 1;
        }
        return 0;
    }
    if (*(int32_t*)(param_1 + 0x6c) != -1) {
        return 0;
    }
    local_c = self;
    strncpy(local_2c, *(char**)(*(int32_t*)(param_1 + 0x68) + 0x18), 0x20);
    local_2c[31] = '\0';   // local_d in the listing
    pcVar5 = local_2c;
    if (local_2c[0] == '\0') {
LAB_006842fa:
        if (*pcVar5 != '\0') {
            *pcVar5 = '\0';
            pcVar5 = pcVar5 + 1;
        }
    } else {
        do {
            iVar4 = isalpha((int)*pcVar5);
            if (iVar4 == 0) break;
            pcVar5 = pcVar5 + 1;
        } while (*pcVar5 != '\0');
        if (*pcVar5 != '\0') {
            iVar6 = atoi(pcVar5);
            goto LAB_006842fa;
        }
    }
    cVar2 = *pcVar5;
    if (cVar2 == '\0') {
LAB_00684328:
        uVar7 = (uint32_t)iVar6 + (*(uint32_t*)(param_1 + 0x70) >> 2);
    } else {
        do {
            iVar4 = isdigit((int)cVar2);
            if (iVar4 == 0) break;
            pcVar5 = pcVar5 + 1;
            cVar2 = *pcVar5;
        } while (cVar2 != '\0');
        if (*pcVar5 == '\0') goto LAB_00684328;
        uVar7 = 0xffffffff;
    }
    uVar1 = *(uint32_t*)(*(int32_t*)(*(int32_t*)((char*)self + 0x10) +
                                    *(int32_t*)(param_1 + 4) * 4) + 4);
    if (((uVar1 & 0x10) == 0) || ((uVar1 & 0x200) != 0)) {
        if ((uVar1 & 0x20) != 0) {
            iVar6 = _stricmp(local_2c, "color");
            bVar9 = iVar6 != 0;
            bVar8 = bVar9 || uVar7 != 0;
            local_8 = (uint32_t)!bVar9;
            if ((bVar9 || uVar7 != 0) && (*(int32_t*)(param_1 + 0x10) == 0)) {
                pcVar5 = (char*)"invalid reference to output semantic '%s%d'";
                goto LAB_006843e3;
            }
            goto LAB_006843f6;
        }
    } else {
        iVar6 = _stricmp(local_2c, "position");
        if (iVar6 == 0) {
            local_8 = 2;
LAB_00684363:
            bVar8 = uVar7 != 0;
        } else {
            iVar6 = _stricmp(local_2c, "psize");
            if (iVar6 == 0) {
                local_8 = 3;
                goto LAB_00684363;
            }
            local_8 = 0;
            bVar8 = true;
        }
        if ((bVar8) && (*(int32_t*)(param_1 + 0x10) == 0)) {
            pcVar5 = (char*)"invalid reference to input semantic '%s%d'";
LAB_006843e3:
            FUN_006626da(local_c, *(uint32_t*)(param_1 + 0x68), 0x1196, pcVar5,
                         local_2c, uVar7);
        }
LAB_006843f6:
        if (local_8 != 0) goto LAB_00684403;
    }
    bVar8 = true;
LAB_00684403:
    if (0xffff < uVar7) {
        bVar8 = true;
    }
    *(uint32_t*)(param_1 + 0x6c) = ((uVar7 | 0xffffff00) << 8) | (local_8 & 0xff);
    return -(uint32_t)bVar8 & 0x80004005;
}

// ---------------------------------------------------------------------------
// Scalar-deleting destructor: installs the vtable at PTR_FUN_006f0938, runs the
// base teardown, then frees the receiver when bit 0 of the flags word is set.
// 0x684433 — observed shape
void __cdecl FUN_00684433(void* self, uint8_t param_1)
{
    *(void**)self = (void*)&PTR_FUN_006f0938;
    FUN_006a0238();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// ---------------------------------------------------------------------------
// Walks the node chain starting at index param_1: recurses into the +8 child
// (when not -1), validates the node through FUN_00684169, emits its +0x10/+0xc
// reference word through FUN_006a2b66, then bumps the per-semantic counter at
// (self+0x10c)[param_2]. Any negative intermediate result yields 0x8007000e.
// 0x68445a — observed shape
int32_t __cdecl FUN_0068445a(void* self, int32_t param_1, int32_t param_2)
{
    int32_t iVar2;
    int32_t* piVar1;
    int32_t* table;
    uint8_t* node;

    table = *(int32_t**)((char*)self + 0x14);
    node = (uint8_t*)(intptr_t)table[param_1];
    if (((*(int32_t*)(node + 8) == -1) ||
         (iVar2 = FUN_0068445a(self, *(int32_t*)(node + 8), param_2), -1 < iVar2)) &&
        (iVar2 = FUN_00684169(self, node), -1 < iVar2) &&
        (iVar2 = FUN_006a2b66(*(int32_t*)(node + 0x10) +
                              *(int32_t*)(node + 0xc) * 4), -1 < iVar2)) {
        piVar1 = (int32_t*)(*(int32_t*)((char*)self + 0x10c) + param_2 * 4);
        *piVar1 = *piVar1 + 1;
        return 0;
    }
    return (int32_t)0x8007000e;
}

// ---------------------------------------------------------------------------
// Assembles the compiled vertex program. Phase 1 scans the node list to size
// the per-semantic index ranges (self+0x84/0xb4/0xb8) and to find the maximum
// declaration counts. Phase 2 allocates and fills one run list per semantic
// (min/max plus run-length pairs) and copies the per-node 8-byte payload into a
// dense table. Phase 3 walks the primitive list, re-seating shared-vertex
// vertices, retargeting malformed primitives (0x70e00001) and emitting each
// vertex through FUN_0068445a/FUN_00684169/FUN_006a2b66. Phase 4 emits the
// trailer, forwards the packed payloads through FUN_0068422a and, when param_1
// is non-null, copies the instruction buffer into a fresh array and stores it.
// Returns S_OK, or the first failing HRESULT (-0x7ff8fff2 = E_OUTOFMEMORY).
// NOTE: the in-place index swap near LAB_00684a65 is emitted with the byte
// offsets Ghidra produced; kept as observed.
// 0x6844c1 — observed shape
int32_t __cdecl FUN_006844c1(void* self, void** param_1)
{
    int32_t iVar2;
    uint32_t* puVar3;
    int32_t* piVar4;
    uint32_t* puVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    int32_t iVar8;
    uint32_t* puVar10;
    void* auStack_98[4];
    intptr_t local_88;
    uint32_t local_84[5];
    int32_t local_70[3];
    void* local_64[3];
    uint32_t local_58[7];
    int32_t* local_3c;
    int32_t local_38;
    uint32_t local_34;
    uint32_t* local_30;
    intptr_t local_2c;
    uint32_t local_28;
    int32_t local_24;
    int32_t local_20;
    int32_t local_1c;
    intptr_t local_18;
    intptr_t local_14;
    int32_t local_10;
    int32_t local_c;
    uint8_t* local_8;
    uint8_t* node;
    uint8_t* prim;
    uint8_t* counterBase;
    uint32_t* counter;
    int32_t* first;
    int32_t* indexWords;
    int32_t* vertIdx;
    int32_t* newNode;
    int32_t expected;
    int32_t semantic;
    int32_t child;
    int32_t count;
    intptr_t vcount;
    intptr_t step;
    intptr_t off;
    int32_t j;
    int32_t k;
    int32_t primIndex;
    uint32_t uVar12;
    void* outObj;
    int32_t* vtable;
    bool bVar11;

    local_30 = 0;
    local_58[4] = 0;
    local_58[5] = 0;
    local_58[6] = 0;
    local_64[0] = 0;
    local_64[1] = 0;
    local_64[2] = 0;
    if (*(int32_t*)((char*)self + 0xc) == 0) {
        return 1;
    }
    local_c = FUN_0067095f(param_1);
    if (local_c < 0) goto LAB_00685131;
    local_c = FUN_00695343(*(uint32_t*)((char*)self + 0x7c),
                           *(uint32_t*)((char*)self + 0x38), 0x200, 0x42080, 99);
    if (local_c < 0) goto LAB_00685131;
    local_28 = 0;
    local_1c = 0;
    local_58[0] = 0xffffffff;
    local_58[1] = 0xffffffff;
    local_58[2] = 0xffffffff;
    local_58[3] = 0xffffffff;
    local_84[0] = 0;
    local_84[1] = 0;
    local_84[2] = 0;
    local_84[3] = 0;
    if (*(int32_t*)((char*)self + 8) != 0) {
        int32_t* piNodes = *(int32_t**)((char*)self + 0x14);
        int32_t nRemaining = *(int32_t*)((char*)self + 8);
        do {
            node = (uint8_t*)(intptr_t)*piNodes;
            iVar2 = *(int32_t*)(node + 4);
            if ((*(int32_t*)((char*)self + 0x78) == iVar2) &&
                (uVar6 = (uint32_t)(*(int32_t*)(node + 0xc) + 1), local_28 < uVar6)) {
                local_28 = uVar6;
            } else if ((*(int32_t*)((char*)self + 0x88) == iVar2) &&
                       (local_1c < *(int32_t*)(node + 0xc) + 1)) {
                local_1c = *(int32_t*)(node + 0xc) + 1;
            }
            if (*(int32_t*)((char*)self + 0x84) == iVar2) {
                if (local_84[0] < *(uint32_t*)(node + 0xc)) {
                    local_84[0] = *(uint32_t*)(node + 0xc);
                }
                if ((*(int32_t*)((char*)self + 0x84) == iVar2) &&
                    (*(uint32_t*)(node + 0xc) < local_58[0])) {
                    local_58[0] = *(uint32_t*)(node + 0xc);
                }
            }
            if (*(int32_t*)((char*)self + 0xb4) == iVar2) {
                if (local_84[1] < *(uint32_t*)(node + 0xc)) {
                    local_84[1] = *(uint32_t*)(node + 0xc);
                }
                if ((*(int32_t*)((char*)self + 0xb4) == iVar2) &&
                    (*(uint32_t*)(node + 0xc) < local_58[1])) {
                    local_58[1] = *(uint32_t*)(node + 0xc);
                }
            }
            if (*(int32_t*)((char*)self + 0xb8) == iVar2) {
                if (local_84[2] < *(uint32_t*)(node + 0xc)) {
                    local_84[2] = *(uint32_t*)(node + 0xc);
                }
                if ((*(int32_t*)((char*)self + 0xb8) == iVar2) &&
                    (*(uint32_t*)(node + 0xc) < local_58[2])) {
                    local_58[2] = *(uint32_t*)(node + 0xc);
                }
            }
            piNodes = piNodes + 1;
            nRemaining = nRemaining - 1;
        } while (nRemaining != 0);
    }
    local_20 = 0;
    local_70[0] = *(int32_t*)((char*)self + 0x84);
    local_70[1] = *(int32_t*)((char*)self + 0xb4);
    local_70[2] = *(int32_t*)((char*)self + 0xb8);
    do {
        if ((int32_t)local_58[local_20] != -1) {
            uVar6 = (local_84[local_20] - local_58[local_20]) + 1;
            local_8 = (uint8_t*)FUN_00533c78();
            if (local_8 == 0) goto LAB_006847e4;
            piVar4 = (int32_t*)local_8;
            for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
                *piVar4 = 0;
                piVar4 = piVar4 + 1;
            }
            for (uVar7 = uVar6 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
                *(uint8_t*)piVar4 = 0;
                piVar4 = (int32_t*)((intptr_t)piVar4 + 1);
            }
            uVar7 = 0;
            if (*(int32_t*)((char*)self + 8) != 0) {
                iVar8 = local_70[local_20];
                do {
                    node = recon_node(self, uVar7);
                    if (iVar8 == *(int32_t*)(node + 4)) {
                        local_8[*(int32_t*)(node + 0xc) - (int32_t)local_58[local_20]] = 1;
                    }
                    uVar7 = uVar7 + 1;
                } while (uVar7 < *(uint32_t*)((char*)self + 8));
            }
            uVar7 = 0;
            local_10 = 0;
            if (uVar6 != 0) {
                do {
                    if (uVar7 < uVar6) goto LAB_0068469f;
                    do {
                        local_10 = local_10 + 1;
                        for (; uVar7 < uVar6 && local_8[uVar7] != 0; uVar7 = uVar7 + 1) {
                        }
                        uVar7 = uVar7 + 1;
                        if (uVar6 <= uVar7) goto LAB_006846bf;
LAB_0068469f:
                        ;
                    } while (local_8[uVar7] != 0);
                    uVar7 = uVar7 + 1;
                } while (true);
            }
LAB_006846bf:
            piVar4 = (int32_t*)FUN_00533c78();
            local_64[local_20] = piVar4;
            if (piVar4 == 0) {
                operator_delete(local_8);
                goto LAB_006847e4;
            }
            uVar7 = 0;
            if (uVar6 != 0) {
                do {
                    if (uVar7 < uVar6) goto LAB_006846e3;
                    do {
                        *piVar4 = (int32_t)local_58[local_20] + (int32_t)uVar7;
                        for (; uVar7 < uVar6 && local_8[uVar7] != 0; uVar7 = uVar7 + 1) {
                        }
                        piVar4[1] = ((int32_t)local_58[local_20] - *piVar4) + (int32_t)uVar7;
                        piVar4 = piVar4 + 2;
                        uVar7 = uVar7 + 1;
                        if (uVar6 <= uVar7) goto LAB_0068471f;
LAB_006846e3:
                        ;
                    } while (local_8[uVar7] != 0);
                    uVar7 = uVar7 + 1;
                } while (true);
            }
LAB_0068471f:
            operator_delete(local_8);
            local_58[4 + local_20] = (uint32_t)local_10;
        }
        uVar6 = local_28;
        local_20 = local_20 + 1;
    } while (local_20 < 0xc);
    local_30 = (uint32_t*)FUN_00533c78();
    if (local_30 == 0) {
LAB_006847e4:
        local_c = -0x7ff8fff2;
    } else if (local_1c < 0x41) {
        puVar10 = local_30;
        for (iVar8 = (local_28 & 0x7ffffff) << 3; iVar8 != 0; iVar8 = iVar8 - 1) {
            *puVar10 = 0;
            puVar10 = puVar10 + 1;
        }
        for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
            *(uint8_t*)puVar10 = 0;
            puVar10 = (uint32_t*)((intptr_t)puVar10 + 1);
        }
        uVar6 = 0;
        if (*(int32_t*)((char*)self + 8) != 0) {
            do {
                node = recon_node(self, uVar6);
                if ((*(int32_t*)((char*)self + 0x78) == *(int32_t*)(node + 4)) &&
                    (*(int32_t*)(node + 8) == -1)) {
                    *(uint64_t*)((char*)local_30 +
                                (intptr_t)(*(int32_t*)(node + 0x10) +
                                           *(int32_t*)(node + 0xc) * 4) * 2) =
                        *(uint64_t*)(node + 0x20);
                }
                if (*(int32_t*)((char*)self + 200) == 0x54580100) {
                    if (*(int32_t*)((char*)self + 0x80) == *(int32_t*)(node + 4)) {
                        if (*(uint32_t*)(node + 0xc) < 2) {
                            uVar7 = *(uint32_t*)(node + 0x6c) & 0xff;
                            if (uVar7 == 2) {
                                *(uint32_t*)(node + 0xc) = 0;
                            } else if (uVar7 == 3) {
                                *(uint32_t*)(node + 0xc) = 1;
                            }
                            goto LAB_006847fc;
                        }
                    } else {
LAB_006847fc:
                        if ((*(int32_t*)((char*)self + 0x84) != *(int32_t*)(node + 4)) ||
                            (*(int32_t*)(node + 0xc) == 0)) goto LAB_0068480d;
                    }
                    FUN_006626da();
                    goto LAB_00685131;
                }
LAB_0068480d:
                uVar6 = uVar6 + 1;
            } while (uVar6 < *(uint32_t*)((char*)self + 8));
        }
        local_3c = *(int32_t**)((char*)self + 0xc);
        local_1c = 0;
        if (*(int32_t**)((char*)self + 0xc) != 0) {
            do {
                puVar3 = (uint32_t*)(intptr_t)recon_prim(self, (uint32_t)local_1c);
                local_24 = 0;
                puVar3[10] = 0;
                local_34 = *puVar3 & 0xfff00000;
                count = (int32_t)(*puVar3 & 0xfffff);
                if (count == 0) {
LAB_00684ae1:
                    FUN_0065db2e();
                } else {
                    local_10 = 0;
                    vcount = (intptr_t)(puVar3[1] / (uint32_t)count);
                    piVar4 = (int32_t*)(intptr_t)puVar3[4];
                    local_84[4] = *(int32_t*)(recon_node(self, (uint32_t)*piVar4) + 0x10);
                    if (vcount != 0) {
                        local_14 = (intptr_t)puVar3[2];
                        do {
                            vertIdx = (int32_t*)local_14;
                            local_70[local_10] =
                                *(int32_t*)(recon_node(self, (uint32_t)*vertIdx) + 0x10);
                            local_10 = local_10 + 1;
                            local_14 = local_14 + (intptr_t)count * 4;
                        } while ((intptr_t)local_10 < vcount);
                    }
                    if ((count == (int32_t)puVar3[3]) && (1 < count)) {
                        local_10 = (int32_t)local_84[4] + 1;
                        local_18 = (intptr_t)count - 1;
                        do {
                            piVar4 = piVar4 + 1;
                            if (*(int32_t*)(recon_node(self, (uint32_t)*piVar4) + 0x10) ==
                                local_10) {
                                local_84[4] = local_84[4] + 1;
                                local_10 = local_10 + 1;
                            } else {
                                local_24 = 1;
                            }
                            local_18 = local_18 - 1;
                        } while (local_18 != 0);
                    }
                    if ((local_20 == 2) && (local_24 == 0)) {
                        expected = local_70[1] + 1;
                        local_c = 1;
                        if (1 < count) {
                            first = (int32_t*)(intptr_t)puVar3[2];
                            local_38 = *(int32_t*)(recon_node(self, (uint32_t)*first) + 0x10);
                            local_88 = (intptr_t)(first + 1);
                            local_2c = (intptr_t)(first + count + 1);
                            local_14 = local_88;
                            local_18 = local_2c;
                            local_10 = 0;
                            do {
                                if (*(int32_t*)(recon_node(self, *(int32_t*)local_14) + 0x10) !=
                                    local_38) {
                                    local_c = 0;
                                }
                                if (*(int32_t*)(recon_node(self, *(int32_t*)local_18) + 0x10) ==
                                    expected) {
                                    expected = expected + 1;
                                } else {
                                    local_c = 0;
                                }
                                local_14 = local_14 + 4;
                                local_18 = local_18 + 4;
                                local_10 = local_10 + 1;
                            } while (local_10 < count - 1);
                            if (local_c == 0) {
                                expected = local_70[0] + 1;
                                local_38 = *(int32_t*)(recon_node(self, (uint32_t)first[count]) +
                                                       0x10);
                                local_c = 1;
                                local_14 = local_2c;
                                local_18 = local_88;
                                local_10 = 0;
                                do {
                                    if (*(int32_t*)(recon_node(self, *(int32_t*)local_14) + 0x10) !=
                                        local_38) {
                                        local_c = 0;
                                    }
                                    if (*(int32_t*)(recon_node(self, *(int32_t*)local_18) + 0x10) ==
                                        expected) {
                                        expected = expected + 1;
                                    } else {
                                        local_c = 0;
                                    }
                                    local_14 = local_14 + 4;
                                    local_18 = local_18 + 4;
                                    local_10 = local_10 + 1;
                                } while (local_10 < count - 1);
                                if (local_c == 0) goto LAB_00684a65;
                                local_10 = 0;
                                if (count != 0) {
                                    off = (intptr_t)count << 2;
                                    do {
                                        int32_t* slot = (int32_t*)((intptr_t)puVar3[2] +
                                                                   (intptr_t)local_10 * 4);
                                        int32_t tmp = *slot;
                                        *slot = *(int32_t*)((intptr_t)puVar3[2] + off);
                                        *(int32_t*)((intptr_t)puVar3[2] + off) = tmp;
                                        off = off + 4;
                                        local_10 = local_10 + 1;
                                    } while (local_10 < count);
                                }
                            }
                        }
                        puVar3[10] = 1;
                        goto LAB_00684ae1;
                    }
LAB_00684a65:
                    k = 1;
                    if (1 < count) {
                        do {
                            local_10 = 0;
                            if (local_20 != 0) {
                                local_14 = (intptr_t)puVar3[2] + (intptr_t)k * 4;
                                do {
                                    semantic = local_70[local_10] + 1;
                                    if (*(int32_t*)(recon_node(self, *(int32_t*)local_14) + 0x10) ==
                                        semantic) {
                                        local_70[local_10] = semantic;
                                    } else {
                                        local_24 = 1;
                                    }
                                    local_10 = local_10 + 1;
                                    local_14 = local_14 + (intptr_t)count * 4;
                                } while (local_10 < local_20);
                            }
                            k = k + 1;
                        } while (k < count);
                    }
                    if (local_24 == 0) goto LAB_00684ae1;
                    if (local_34 == 0x50000000) {
                        *puVar3 = 0x70e00001;
                        goto LAB_00684ae1;
                    }
                    if (local_34 == 0x50300000) {
                        k = 0;
                        if (count != 0) {
                            do {
                                if (*(int32_t*)(recon_node(self,
                                                           *(int32_t*)((intptr_t)puVar3[4] +
                                                                       k * 4)) + 0x5c) != 0) {
                                    if (k == 0) {
                                        uVar12 = 0x10900001;
                                    } else {
                                        uVar12 = 0x10800001;
                                    }
                                    iVar8 = FUN_0065da35(uVar12, 1, 1);
                                    if (iVar8 == -1) goto LAB_006847e4;
                                    newNode = (int32_t*)(intptr_t)
                                        *(int32_t*)(*(int32_t*)((char*)self + 0x18) + iVar8 * 4);
                                    local_c = FUN_0065cc50();
                                    if (local_c < 0) goto LAB_00685131;
                                    *(uint32_t*)(*(int32_t*)((intptr_t)newNode + 0x10)) =
                                        *(uint32_t*)((intptr_t)puVar3[4] + k * 4);
                                    *(uint32_t*)(*(int32_t*)((intptr_t)newNode + 8)) =
                                        *(uint32_t*)((intptr_t)puVar3[2] + k * 4);
                                }
                                k = k + 1;
                            } while (k < count);
                        }
                    } else {
                        local_10 = 0;
                        if (count != 0) {
                            do {
                                iVar8 = FUN_0065d0b4();
                                if (iVar8 == 0) {
                                    vertIdx = 0;
                                } else {
                                    vertIdx = (int32_t*)FUN_0065cc1a();
                                }
                                bVar11 = vertIdx == 0;
                                auStack_98[local_10] = vertIdx;
                                if (bVar11) goto LAB_006847e4;
                                local_c = FUN_0065d0ff(local_34 | 1, (uint32_t)local_20, 1, 0);
                                if (local_c < 0) goto LAB_00685131;
                                local_c = FUN_0065cc50();
                                if (local_c < 0) goto LAB_00685131;
                                j = 0;
                                *(uint32_t*)(*(int32_t*)((intptr_t)vertIdx + 0x10)) =
                                    *(uint32_t*)((intptr_t)puVar3[4] + local_10 * 4);
                                if (local_20 != 0) {
                                    off = (intptr_t)local_10 * 4;
                                    do {
                                        *(uint32_t*)(*(int32_t*)((intptr_t)vertIdx + 8) +
                                                     j * 4) =
                                            *(uint32_t*)((intptr_t)puVar3[2] + off);
                                        off = off + (intptr_t)count * 4;
                                        j = j + 1;
                                    } while (j < local_20);
                                }
                                FUN_0065db2e();
                                FUN_00614343();
                                local_10 = local_10 + 1;
                            } while (local_10 < count);
                        }
                    }
                }
                *puVar3 = 0;
                local_1c = local_1c + 1;
            } while ((intptr_t)local_1c < (intptr_t)local_3c);
        }
        FUN_0065e4f2();
        local_c = FUN_006a2b66();
        uVar6 = local_58[4];
        if (local_c < 0) goto LAB_00685131;
        if (*(int32_t*)((char*)self + 200) == 0x46580201) {
            FUN_006a2b66();
            local_c = FUN_006a2b66();
            if (local_c < 0) goto LAB_00685131;
            uVar7 = 0;
            do {
                FUN_006a2b66();
                uVar7 = uVar7 + 1;
            } while (uVar7 < 3);
            uVar7 = 0;
            do {
                FUN_006a2b66();
                uVar7 = uVar7 + 4;
            } while (uVar7 < 0xc);
            FUN_006a2b66();
            uVar7 = 0;
            if (uVar6 != 0) {
                do {
                    FUN_006a2b66();
                    FUN_006a2b66();
                    uVar7 = uVar7 + 1;
                } while (uVar7 < uVar6);
            }
            FUN_006a2b66();
            uVar6 = 0;
            if (local_58[5] != 0) {
                do {
                    FUN_006a2b66();
                    FUN_006a2b66();
                    uVar6 = uVar6 + 1;
                } while (uVar6 < local_58[5]);
            }
            FUN_006a2b66();
            uVar6 = 0;
            if (local_58[6] != 0) {
                do {
                    FUN_006a2b66();
                    FUN_006a2b66();
                    uVar6 = uVar6 + 1;
                } while (uVar6 < local_58[6]);
            }
        }
        local_c = FUN_006a2cbe();
        if ((-1 < local_c) && (local_c = FUN_006a2b66(), -1 < local_c) &&
            (local_c = FUN_006a2b66(), -1 < local_c)) {
            uVar6 = local_28 << 2;
            local_c = FUN_006a2b66();
            if (-1 < local_c) {
                uVar7 = 0;
                if (uVar6 != 0) {
                    do {
                        local_c = FUN_0068422a(self, local_30[uVar7 * 2],
                                               local_30[uVar7 * 2 + 1]);
                        if (local_c < 0) goto LAB_00685131;
                        uVar7 = uVar7 + 1;
                    } while (uVar7 < uVar6);
                }
                local_24 = *(int32_t*)((char*)self + 0x110);
                local_c = FUN_006a2b66();
                if ((-1 < local_c) && (local_c = FUN_006a2b66(), -1 < local_c) &&
                    (local_c = FUN_006a2b66(), -1 < local_c)) {
                    local_28 = 0;
                    if (*(int32_t*)((char*)self + 0xc) != 0) {
                        primIndex = 0;
                        do {
                            local_c = FUN_006a2b66();
                            if (local_c < 0) goto LAB_00685131;
                            prim = recon_prim(self, (uint32_t)primIndex);
                            puVar3 = (uint32_t*)(intptr_t)prim;
                            uVar6 = *puVar3 & 0xfffff;
                            vcount = (intptr_t)(puVar3[1] / uVar6);
                            local_c = FUN_006a2b66();
                            if (local_c < 0) goto LAB_00685131;
                            local_1c = 0;
                            counterBase = (uint8_t*)(intptr_t)*(int32_t*)((char*)self + 0x10c);
                            counter = (uint32_t*)(counterBase + local_24 * 4);
                            *counter = *counter + 2;
                            if (vcount != 0) {
                                local_14 = 0;
                                step = (intptr_t)(uVar6 << 2);
                                do {
                                    indexWords = (int32_t*)(intptr_t)*(int32_t*)(prim + 8);
                                    vertIdx = (int32_t*)((intptr_t)indexWords + local_14);
                                    node = recon_node(self, (uint32_t)*vertIdx);
                                    iVar2 = *(int32_t*)((char*)self + 0x110);
                                    local_c = FUN_006a2b66();
                                    if (local_c < 0) goto LAB_00685131;
                                    child = *(int32_t*)(node + 8);
                                    if (child != -1) {
                                        local_c = FUN_0068445a(self, child, iVar2);
                                        if (local_c < 0) goto LAB_00685131;
                                    }
                                    local_c = FUN_00684169(self, node);
                                    if (local_c < 0) goto LAB_00685131;
                                    local_c = FUN_006a2b66();
                                    if (local_c < 0) goto LAB_00685131;
                                    counterBase = (uint8_t*)(intptr_t)*(int32_t*)((char*)self +
                                                                                 0x10c);
                                    counter = (uint32_t*)(counterBase + local_24 * 4);
                                    *counter = *counter +
                                               *(int32_t*)(counterBase + iVar2 * 4) * 2 + 3;
                                    local_1c = local_1c + 1;
                                    local_14 = local_14 + step;
                                } while ((intptr_t)local_1c < vcount);
                            }
                            j = 0;
                            do {
                                indexWords = (int32_t*)(intptr_t)*(int32_t*)(prim + 0x10);
                                vertIdx = indexWords + j;
                                node = recon_node(self, (uint32_t)*vertIdx);
                                iVar2 = *(int32_t*)((char*)self + 0x110);
                                local_c = FUN_006a2b66();
                                if (local_c < 0) goto LAB_00685131;
                                child = *(int32_t*)(node + 8);
                                if (child != -1) {
                                    local_c = FUN_0068445a(self, child, iVar2);
                                    if (local_c < 0) goto LAB_00685131;
                                }
                                local_c = FUN_00684169(self, node);
                                if (local_c < 0) goto LAB_00685131;
                                local_c = FUN_006a2b66();
                                if (local_c < 0) goto LAB_00685131;
                                j = j + 1;
                                counterBase = (uint8_t*)(intptr_t)*(int32_t*)((char*)self + 0x10c);
                                counter = (uint32_t*)(counterBase + local_24 * 4);
                                *counter = *counter +
                                           *(int32_t*)(counterBase + iVar2 * 4) * 2 + 3;
                            } while (j < 4);
                            local_28 = local_28 + 1;
                            primIndex = primIndex + 1;
                        } while (local_28 < *(uint32_t*)((char*)self + 0xc));
                    }
                    local_c = FUN_006a2b66();
                    if ((-1 < local_c) && (local_c = FUN_006a2b66(), -1 < local_c)) {
                        counterBase = (uint8_t*)(intptr_t)*(int32_t*)((char*)self + 0x10c);
                        counter = (uint32_t*)(counterBase + local_24 * 4);
                        *counter = ((*counter + 4) * 0x10000) & 0x7fff0000 | 0xfffe;
                        local_c = FUN_006a2b66();
                        if (-1 < local_c) {
                            if (param_1 != 0) {
                                outObj = 0;
                                local_c = FUN_00629497(*(int32_t*)((char*)self + 0x110) << 2,
                                                       &outObj);
                                if (local_c < 0) goto LAB_00685131;
                                uVar6 = *(uint32_t*)((char*)self + 0x110);
                                puVar10 = (uint32_t*)(intptr_t)*(int32_t*)((char*)self + 0x10c);
                                vtable = *(int32_t**)outObj;
                                puVar5 = (uint32_t*)((void* (__cdecl*)(void))
                                                     (intptr_t)vtable[3])();
                                for (uVar6 = uVar6 & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {
                                    *puVar5 = *puVar10;
                                    puVar10 = puVar10 + 1;
                                    puVar5 = puVar5 + 1;
                                }
                                *param_1 = outObj;
                            }
                            local_c = 0;
                        }
                    }
                }
            }
        }
    }
LAB_00685131:
    operator_delete(local_30);
    operator_delete(local_64[0]);
    operator_delete(local_64[1]);
    operator_delete(local_64[2]);
    return local_c;
}

// ---------------------------------------------------------------------------
// Quaternion product param_1 = param_3 * param_2 (param_3 = left/w, param_2 =
// right), four floats each, written as four scalars.
// 0x68515d — observed shape
float* __cdecl FUN_0068515d(float* param_1, float* param_2, float* param_3)
{
    float fVar5 = param_3[0];
    float fVar6 = param_3[1];
    float fVar7 = param_3[2];
    float fVar8 = param_3[3];
    float fVar1 = param_2[0];
    float fVar2 = param_2[1];
    float fVar3 = param_2[2];
    float fVar4 = param_2[3];

    param_1[0] = fVar8 * fVar1 + -fVar5 * fVar4 + fVar6 * fVar3 + fVar7 * fVar2;
    param_1[1] = fVar8 * fVar2 + -fVar5 * fVar3 + fVar6 * fVar4 + fVar7 * fVar1;
    param_1[2] = fVar8 * fVar3 + fVar5 * fVar2 + -fVar6 * fVar1 + fVar7 * fVar4;
    param_1[3] = fVar8 * fVar4 + -fVar5 * fVar1 + -fVar6 * fVar2 + -fVar7 * fVar3;
    return param_1;
}

// ---------------------------------------------------------------------------
// Normalises a four-float vector. The reciprocal square root is the rsqrtss
// estimate refined by one Newton step scaled by DAT_007209c0 / _DAT_007209b0.
// 0x6851d8 — observed shape
float* __cdecl FUN_006851d8(float* param_1, float* param_2)
{
    float fVar1 = param_2[0];
    float fVar2 = param_2[1];
    float fVar3 = param_2[2];
    float fVar4 = param_2[3];
    float fVar5 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3 + fVar4 * fVar4;
    float fVar6 = _mm_cvtss_f32(_mm_rsqrt_ss(_mm_set_ss(fVar5)));

    fVar6 = (DAT_007209c0 - fVar5 * fVar6 * fVar6) * _DAT_007209b0 * fVar6;
    param_1[0] = fVar1 * fVar6;
    param_1[1] = fVar2 * fVar6;
    param_1[2] = fVar3 * fVar6;
    param_1[3] = fVar4 * fVar6;
    return param_1;
}

// ---------------------------------------------------------------------------
// Converts a row-major 4x4 matrix (param_2) into a unit quaternion (param_1).
// The trace path builds w from +0x00/+0x14/+0x28; the other path picks the
// largest of the three diagonal terms, walks the DAT_006f0b14 next-index table
// and builds the three off-diagonal components scaled by 0.25/w.
// 0x6853b7 — observed shape
void __cdecl FUN_006853b7(float* param_1, float* param_2)
{
    float local_18[4];
    float* pfVar4 = param_2;
    float fVar3 = param_2[5] + param_2[0] + param_2[10];
    int32_t idx;
    int32_t iVar2;
    int32_t iVar5;
    int32_t iVar6;
    int32_t local_8;

    if (fVar3 <= 0.0f) {
        local_18[1] = param_2[5];
        local_18[0] = param_2[0];
        local_18[2] = param_2[10];
        idx = (param_2[0] < param_2[5]) ? 1 : 0;
        if (local_18[idx] < param_2[10]) {
            idx = 2;
        }
        iVar5 = idx * 4;
        iVar2 = DAT_006f0b14[idx];
        iVar6 = iVar2 * 4;
        local_8 = DAT_006f0b14[iVar2];
        fVar3 = (float)sqrtf(((local_18[idx] - local_18[iVar2]) - local_18[local_8]) + 1.0f) *
                0.5f;
        param_1[idx] = fVar3;
        fVar3 = 0.25f / fVar3;
        param_1[iVar2] = (pfVar4[idx + iVar6] + pfVar4[iVar2 + iVar5]) * fVar3;
        param_1[local_8] = (pfVar4[idx + local_8 * 4] + pfVar4[iVar5 + local_8]) * fVar3;
        param_1[3] = (pfVar4[iVar6 + local_8] - pfVar4[local_8 * 4 + iVar2]) * fVar3;
    } else {
        fVar3 = (float)sqrtf(fVar3 + 1.0f) * 0.5f;
        param_1[3] = fVar3;
        fVar3 = 0.25f / fVar3;
        param_1[0] = (pfVar4[6] - pfVar4[9]) * fVar3;
        param_1[1] = (pfVar4[8] - pfVar4[2]) * fVar3;
        param_1[2] = (pfVar4[1] - pfVar4[4]) * fVar3;
    }
    return;
}

// ---------------------------------------------------------------------------
// Transforms the 2D point (param_2[0], param_2[1]) by the 4x4 matrix param_3
// (rows 0,1 and the +0x30 translation row) and stores four results, keeping the
// matrix's z/w rows rather than dividing.
// 0x6854e3 — observed shape
float* __cdecl FUN_006854e3(float* param_1, float* param_2, float* param_3)
{
    float fVar3 = param_3[1];
    float fVar4 = param_3[2];
    float fVar5 = param_3[3];
    float fVar1 = param_2[0];
    float fVar6 = param_3[5];
    float fVar7 = param_3[6];
    float fVar8 = param_3[7];
    float fVar2 = param_2[1];
    float fVar9 = param_3[0xd];
    float fVar10 = param_3[0xe];
    float fVar11 = param_3[0xf];

    param_1[0] = fVar1 * param_3[0] + param_3[0xc] + fVar2 * param_3[4];
    param_1[1] = fVar1 * fVar3 + fVar9 + fVar2 * fVar6;
    param_1[2] = fVar1 * fVar4 + fVar10 + fVar2 * fVar7;
    param_1[3] = fVar1 * fVar5 + fVar11 + fVar2 * fVar8;
    return param_1;
}

// ---------------------------------------------------------------------------
// Projects the 2D point through param_3, then scales x/y by the reciprocal of
// the resulting w (rcpps estimate refined by one Newton step). The z term is
// computed but never stored.
// 0x685523 — observed shape
float* __cdecl FUN_00685523(float* param_1, float* param_2, float* param_3)
{
    float fVar3 = param_2[0];
    float fVar1 = param_2[1];
    float fVar4 = fVar3 * param_3[0] + param_3[0xc] + fVar1 * param_3[4];
    float fVar5 = fVar3 * param_3[1] + param_3[0xd] + fVar1 * param_3[5];
    float fVarZ = fVar3 * param_3[2] + param_3[0xe] + fVar1 * param_3[6];
    float fVar6 = fVar3 * param_3[3] + param_3[0xf] + fVar1 * param_3[7];
    float inv = _mm_cvtss_f32(_mm_rcp_ss(_mm_set_ss(fVar6)));

    inv = (inv + inv) - inv * inv * fVar6;
    (void)fVarZ;
    param_1[0] = fVar4 * inv;
    param_1[1] = fVar5 * inv;
    return param_1;
}

// ---------------------------------------------------------------------------
// Transforms a 2D point by the upper-left 2x2 block of param_3, two floats out.
// 0x68557c — observed shape
float* __cdecl FUN_0068557c(float* param_1, float* param_2, float* param_3)
{
    param_1[0] = param_2[0] * param_3[0] + param_2[1] * param_3[4];
    param_1[1] = param_2[0] * param_3[1] + param_2[1] * param_3[5];
    return param_1;
}

// ---------------------------------------------------------------------------
// Normalises a three-float vector; below 1.4210855e-14 the result is zero.
// The reciprocal square root is the rsqrtss estimate refined with
// (3 - r*sqr(r)) * r * 0.5.
// 0x6855b5 — observed shape
float* __cdecl FUN_006855b5(float* param_1, float* param_2)
{
    float fVar1 = param_2[0];
    float fVar2 = param_2[1];
    float fVar3 = param_2[2];
    float fVar4 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
    float fVar5;

    if (1.4210855e-14f <= fVar4) {
        fVar5 = _mm_cvtss_f32(_mm_rsqrt_ss(_mm_set_ss(fVar4)));
        fVar4 = (3.0f - fVar5 * fVar4 * fVar5) * fVar5 * 0.5f;
        param_1[0] = fVar1 * fVar4;
        param_1[1] = fVar2 * fVar4;
        param_1[2] = fVar3 * fVar4;
    } else {
        param_1[0] = 0.0f;
        param_1[1] = 0.0f;
        param_1[2] = 0.0f;
    }
    return param_1;
}

// ---------------------------------------------------------------------------
// Normalises a four-float vector using the xyz length and scales w by the same
// reciprocal square root; below 1.4210855e-14 all four outputs are zero.
// 0x685649 — observed shape
float* __cdecl FUN_00685649(float* param_1, float* param_2)
{
    float fVar1 = param_2[0];
    float fVar2 = param_2[1];
    float fVar3 = param_2[2];
    float fVar4 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
    float fVar5;

    if (1.4210855e-14f <= fVar4) {
        fVar5 = _mm_cvtss_f32(_mm_rsqrt_ss(_mm_set_ss(fVar4)));
        fVar5 = (3.0f - fVar5 * fVar4 * fVar5) * fVar5 * 0.5f;
        fVar4 = param_2[3];
        param_1[0] = fVar1 * fVar5;
        param_1[1] = fVar2 * fVar5;
        param_1[2] = fVar3 * fVar5;
        param_1[3] = fVar5 * fVar4;
    } else {
        param_1[0] = 0.0f;
        param_1[1] = 0.0f;
        param_1[2] = 0.0f;
        param_1[3] = 0.0f;
    }
    return param_1;
}

// ---------------------------------------------------------------------------
// Normalises a four-float vector. Same rsqrtss Newton refinement as
// FUN_006851d8 but scaled by DAT_00720b50 / _DAT_00720b40.
// 0x6857ac — observed shape
float* __cdecl FUN_006857ac(float* param_1, float* param_2)
{
    float fVar1 = param_2[0];
    float fVar2 = param_2[1];
    float fVar3 = param_2[2];
    float fVar4 = param_2[3];
    float fVar5 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3 + fVar4 * fVar4;
    float fVar6 = _mm_cvtss_f32(_mm_rsqrt_ss(_mm_set_ss(fVar5)));

    fVar6 = (DAT_00720b50 - fVar5 * fVar6 * fVar6) * _DAT_00720b40 * fVar6;
    param_1[0] = fVar1 * fVar6;
    param_1[1] = fVar2 * fVar6;
    param_1[2] = fVar3 * fVar6;
    param_1[3] = fVar4 * fVar6;
    return param_1;
}

// ---------------------------------------------------------------------------
// Cubic blend of four three-float samples: the Hermite basis is evaluated from
// the coefficient block at 0x720a20..0x720a5f into four weights, then applied
// component-wise to param_2..param_5. Writes x,y,z.
// 0x685848 — observed shape
float* __cdecl FUN_00685848(float* param_1, float* param_2, float* param_3, float* param_4,
                            float* param_5, float param_6)
{
    float fVar7 = param_6 * param_6;
    float fVar8 = param_6 * fVar7;
    float fVar3 = param_6 * _DAT_00720a40 + _DAT_00720a50 + fVar7 * _DAT_00720a30 +
                  fVar8 * _DAT_00720a20;
    float fVar4 = param_6 * fRam00720a44 + fRam00720a54 + fVar7 * fRam00720a34 +
                  fVar8 * fRam00720a24;
    float fVar5 = param_6 * fRam00720a48 + fRam00720a58 + fVar7 * fRam00720a38 +
                  fVar8 * fRam00720a28;
    float fVar6 = param_6 * fRam00720a4c + fRam00720a5c + fVar7 * fRam00720a3c +
                  fVar8 * fRam00720a2c;

    param_1[0] = param_2[0] * fVar3 + param_3[0] * fVar4 + param_4[0] * fVar5 +
                 param_5[0] * fVar6;
    param_1[1] = param_2[1] * fVar3 + param_3[1] * fVar4 + param_4[1] * fVar5 +
                 param_5[1] * fVar6;
    param_1[2] = param_2[2] * fVar3 + param_3[2] * fVar4 + param_4[2] * fVar5 +
                 param_5[2] * fVar6;
    return param_1;
}

// ---------------------------------------------------------------------------
// Same cubic weights as FUN_00685848, but the samples are summed in the order
// param_2, param_4, param_3, param_5 and only x,y are written.
// 0x6858fc — observed shape
float* __cdecl FUN_006858fc(float* param_1, float* param_2, float* param_3, float* param_4,
                            float* param_5, float param_6)
{
    float fVar4 = param_6 * param_6;
    float fVar5 = param_6 * fVar4;
    float fVar1 = param_6 * _DAT_00720a40 + _DAT_00720a50 + fVar4 * _DAT_00720a30 +
                  fVar5 * _DAT_00720a20;
    float fVar2 = param_6 * fRam00720a44 + fRam00720a54 + fVar4 * fRam00720a34 +
                  fVar5 * fRam00720a24;
    float fVar3 = param_6 * fRam00720a48 + fRam00720a58 + fVar4 * fRam00720a38 +
                  fVar5 * fRam00720a28;

    fVar4 = param_6 * fRam00720a4c + fRam00720a5c + fVar4 * fRam00720a3c +
            fVar5 * fRam00720a2c;
    param_1[0] = param_2[0] * fVar1 + param_4[0] * fVar3 + param_3[0] * fVar2 +
                 param_5[0] * fVar4;
    param_1[1] = param_2[1] * fVar1 + param_4[1] * fVar3 + param_3[1] * fVar2 +
                 param_5[1] * fVar4;
    return param_1;
}

// ---------------------------------------------------------------------------
// Applies the same cubic weights to four four-float samples in column order
// param_2, param_3, param_4, param_5 and writes all four components.
// 0x685983 — observed shape
float* __cdecl FUN_00685983(float* param_1, float* param_2, float* param_3, float* param_4,
                            float* param_5, float param_6)
{
    float fVar15 = param_6 * param_6;
    float fVar16 = param_6 * fVar15;
    float fVar11 = param_6 * _DAT_00720a40 + _DAT_00720a50 + fVar15 * _DAT_00720a30 +
                   fVar16 * _DAT_00720a20;
    float fVar12 = param_6 * fRam00720a44 + fRam00720a54 + fVar15 * fRam00720a34 +
                   fVar16 * fRam00720a24;
    float fVar13 = param_6 * fRam00720a48 + fRam00720a58 + fVar15 * fRam00720a38 +
                   fVar16 * fRam00720a28;
    float fVar14 = param_6 * fRam00720a4c + fRam00720a5c + fVar15 * fRam00720a3c +
                   fVar16 * fRam00720a2c;

    param_1[0] = param_2[0] * fVar11 + param_3[0] * fVar12 + param_4[0] * fVar13 +
                 param_5[0] * fVar14;
    param_1[1] = param_2[1] * fVar11 + param_3[1] * fVar12 + param_4[1] * fVar13 +
                 param_5[1] * fVar14;
    param_1[2] = param_2[2] * fVar11 + param_3[2] * fVar12 + param_4[2] * fVar13 +
                 param_5[2] * fVar14;
    param_1[3] = param_2[3] * fVar11 + param_3[3] * fVar12 + param_4[3] * fVar13 +
                 param_5[3] * fVar14;
    return param_1;
}
