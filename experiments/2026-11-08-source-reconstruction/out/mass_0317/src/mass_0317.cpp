// mass_0317 — unverified decompiler-derived candidate definitions.
// Clean-room from Ghidra 12.2 pseudocode (analysis/pseudocode/functions/*).
// No compiler or test has been run; no PASS claim.

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cstdio>
#include <windows.h>

extern int __cdecl _snprintf(char* buffer, size_t count, const char* format, ...);
extern void __cdecl operator_delete(void* p);

extern void __cdecl FUN_0065d65d(void* self);
extern char* __cdecl FUN_0065db7d(int param_1);
extern void __cdecl FUN_0065dba2(void* self);
extern void* __cdecl FUN_00533c78(size_t size);
extern void __cdecl FUN_00614343(int param_1);

extern void* PTR_FUN_006ee24c;
extern void* PTR_FUN_006ee26c;

// ---------------------------------------------------------------------------
// Builds "<name> semantic '<value>'" into the caller buffer; copies the
// 0x3f-byte string at *(*(self+0x68)+0x18), NUL-terminates it, formats with
// _snprintf and forces a trailing NUL. Returns 0.
// 0x65dd0b — observed shape
uint32_t __cdecl FUN_0065dd0b(int param_1, char* param_2, size_t param_3)
{
    char local_44[64];  // corpus: 63-byte buffer + adjacent NUL byte

    strncpy(local_44, *(char**)(*(int*)(param_1 + 0x68) + 0x18), 0x3f);
    char* pcVar2 = local_44;
    local_44[0x3f] = 0;
    char* uVar1 = FUN_0065db7d(param_1);
    _snprintf(param_2, param_3, "%s semantic '%s'", uVar1, pcVar2);
    param_2[param_3 - 1] = '\0';
    return 0;
}

// ---------------------------------------------------------------------------
// Scalar-deleting destructor. Calls the base body FUN_0065dba2 on the
// receiver, then frees the receiver when bit 0 of the flags argument is set.
// Void return.
// 0x65dd61 — observed shape
void __thiscall FUN_0065dd61(void* self, uint8_t param_1)
{
    FUN_0065dba2(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// ---------------------------------------------------------------------------
// Two-index comparator over the pointer table at object+0x14. Orders by uint
// field +4, then by double field +0x20. Returns -1, 0, or 1.
// 0x65dd82 — observed shape
uint32_t __cdecl FUN_0065dd82(int param_1, int param_2, int param_3)
{
    int iVar1;
    int iVar2;
    uint32_t uVar3;

    iVar1 = *(int*)(*(int*)(param_3 + 0x14) + param_2 * 4);
    iVar2 = *(int*)(*(int*)(param_3 + 0x14) + param_1 * 4);
    if (*(uint32_t*)(iVar2 + 4) < *(uint32_t*)(iVar1 + 4)) {
        uVar3 = 0xffffffff;
    }
    else {
        if (*(uint32_t*)(iVar2 + 4) <= *(uint32_t*)(iVar1 + 4)) {
            if (*(double*)(iVar2 + 0x20) < *(double*)(iVar1 + 0x20)) {
                return 0xffffffff;
            }
            if (*(double*)(iVar2 + 0x20) <= *(double*)(iVar1 + 0x20)) {
                return 0;
            }
        }
        uVar3 = 1;
    }
    return uVar3;
}

// ---------------------------------------------------------------------------
// Lexicographic comparator over two table entries at object+0x14, fields
// +0x38, +0x3c, +4, +0xc, +8, +0x10, +0x14, +0x18 (unsigned except +0x18),
// returning 1 when entry(param_2) orders lower, -1 otherwise, 0 when equal.
// 0x65ddd1 — observed shape
uint32_t __cdecl FUN_0065ddd1(int param_1, int param_2, int param_3)
{
    int iVar1;
    int iVar2;

    iVar1 = *(int*)(*(int*)(param_3 + 0x14) + param_1 * 4);
    iVar2 = *(int*)(*(int*)(param_3 + 0x14) + param_2 * 4);
    if (*(uint32_t*)(iVar2 + 0x38) <= *(uint32_t*)(iVar1 + 0x38)) {
        if (*(uint32_t*)(iVar2 + 0x38) < *(uint32_t*)(iVar1 + 0x38)) {
            return 1;
        }
        if (*(uint32_t*)(iVar2 + 0x3c) <= *(uint32_t*)(iVar1 + 0x3c)) {
            if (*(uint32_t*)(iVar2 + 0x3c) < *(uint32_t*)(iVar1 + 0x3c)) {
                return 1;
            }
            if (*(uint32_t*)(iVar2 + 4) <= *(uint32_t*)(iVar1 + 4)) {
                if (*(uint32_t*)(iVar2 + 4) < *(uint32_t*)(iVar1 + 4)) {
                    return 1;
                }
                if (*(uint32_t*)(iVar2 + 0xc) <= *(uint32_t*)(iVar1 + 0xc)) {
                    if (*(uint32_t*)(iVar2 + 0xc) < *(uint32_t*)(iVar1 + 0xc)) {
                        return 1;
                    }
                    if (*(uint32_t*)(iVar2 + 8) <= *(uint32_t*)(iVar1 + 8)) {
                        if (*(uint32_t*)(iVar2 + 8) < *(uint32_t*)(iVar1 + 8)) {
                            return 1;
                        }
                        if (*(uint32_t*)(iVar2 + 0x10) <= *(uint32_t*)(iVar1 + 0x10)) {
                            if (*(uint32_t*)(iVar2 + 0x10) < *(uint32_t*)(iVar1 + 0x10)) {
                                return 1;
                            }
                            if (*(uint32_t*)(iVar2 + 0x14) <= *(uint32_t*)(iVar1 + 0x14)) {
                                if (*(uint32_t*)(iVar2 + 0x14) < *(uint32_t*)(iVar1 + 0x14)) {
                                    return 1;
                                }
                                if (*(int*)(iVar2 + 0x18) <= *(int*)(iVar1 + 0x18)) {
                                    return (uint32_t)(*(int*)(iVar2 + 0x18) < *(int*)(iVar1 + 0x18));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0xffffffff;
}

// ---------------------------------------------------------------------------
// Unsigned three-way compare.
// 0x65de5f — observed shape
uint32_t __cdecl FUN_0065de5f(uint32_t param_1, uint32_t param_2)
{
    uint32_t uVar1;

    if (param_1 < param_2) {
        uVar1 = 0xffffffff;
    }
    else {
        uVar1 = (uint32_t)(param_2 < param_1);
    }
    return uVar1;
}

// ---------------------------------------------------------------------------
// Two-index ordering over the table at object+0x18: compares node key field
// +0x30, then the two indices as unsigned.
// 0x65de79 — observed shape
uint32_t __cdecl FUN_0065de79(uint32_t param_1, uint32_t param_2, int param_3)
{
    int iVar1;
    int iVar2;

    iVar1 = *(int*)(*(int*)(*(int*)(param_3 + 0x18) + param_1 * 4) + 0x30);
    iVar2 = *(int*)(*(int*)(*(int*)(param_3 + 0x18) + param_2 * 4) + 0x30);
    if (iVar2 <= iVar1) {
        if (iVar2 < iVar1) {
            return 1;
        }
        if (param_2 <= param_1) {
            return (uint32_t)(param_2 < param_1);
        }
    }
    return 0xffffffff;
}

// ---------------------------------------------------------------------------
// LCA-style two-index ordering over the forest indexed at object+0x18. Climbs
// parent links through the node table at object+0x14 (node fields +0x34 and
// +0x14), compares the bounding intervals (+0x48 minimum, +0x58 maximum) of
// the unique ancestor chains, then compares the +0x18 key of the aligned
// first children (node+0x10 points at an index list). Falls back to comparing
// the two indices as unsigned.
// 0x65deb4 — observed shape
uint32_t __cdecl FUN_0065deb4(uint32_t param_1, uint32_t param_2, uint32_t param_3)
{
    uint32_t uVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    int iVar6;
    int iVar7;
    int iVar8;
    uint32_t uVar9;
    uint32_t local_10;
    uint32_t local_c;
    uint32_t local_8;

    iVar2 = param_3;
    iVar5 = *(int*)(*(int*)(param_3 + 0x18) + param_1 * 4);
    iVar8 = *(int*)(*(int*)(param_3 + 0x18) + param_2 * 4);
    iVar6 = *(int*)(iVar8 + 0x34);
    iVar7 = *(int*)(iVar5 + 0x34);
    local_c = 0;
    param_3 = 0;
    iVar4 = iVar6;
    uVar1 = param_3;
    if (iVar7 != -1) {
        iVar3 = iVar7;
        do {
            iVar3 = *(int*)(*(int*)(*(int*)(iVar2 + 0x14) + iVar3 * 4) + 0x14);
            local_c = local_c + 1;
        } while (iVar3 != -1);
    }
    for (; iVar4 != -1; iVar4 = *(int*)(*(int*)(*(int*)(iVar2 + 0x14) + iVar4 * 4) + 0x14)) {
        uVar1 = uVar1 + 1;
    }
    uVar9 = local_c;
    if (uVar1 < local_c) {
        iVar4 = local_c - uVar1;
        do {
            iVar7 = *(int*)(*(int*)(*(int*)(iVar2 + 0x14) + iVar7 * 4) + 0x14);
            uVar9 = uVar9 - 1;
            iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
    }
    param_3 = uVar1;
    if (uVar9 < uVar1) {
        iVar4 = uVar1 - uVar9;
        do {
            param_3 = param_3 - 1;
            iVar4 = iVar4 + -1;
            iVar6 = *(int*)(*(int*)(*(int*)(iVar2 + 0x14) + iVar6 * 4) + 0x14);
        } while (iVar4 != 0);
    }
    if (iVar7 != iVar6) {
        do {
            iVar7 = *(int*)(*(int*)(*(int*)(iVar2 + 0x14) + iVar7 * 4) + 0x14);
            iVar6 = *(int*)(*(int*)(*(int*)(iVar2 + 0x14) + iVar6 * 4) + 0x14);
            uVar9 = uVar9 - 1;
            param_3 = param_3 - 1;
        } while (iVar7 != iVar6);
    }
    iVar7 = *(int*)(iVar5 + 0x34);
    iVar6 = *(int*)(iVar8 + 0x34);
    local_8 = param_1;
    local_10 = param_1;
    if (uVar9 < local_c) {
        local_c = local_c - uVar9;
        do {
            iVar7 = *(int*)(*(int*)(iVar2 + 0x14) + iVar7 * 4);
            if (*(uint32_t*)(iVar7 + 0x48) < local_8) {
                local_8 = *(uint32_t*)(iVar7 + 0x48);
            }
            if (local_10 < *(uint32_t*)(iVar7 + 0x58)) {
                local_10 = *(uint32_t*)(iVar7 + 0x58);
            }
            local_c = local_c + -1;
            iVar7 = *(int*)(iVar7 + 0x14);
        } while (local_c != 0);
    }
    local_c = param_2;
    uVar9 = param_2;
    if (param_3 < uVar1) {
        param_3 = uVar1 - param_3;
        do {
            iVar7 = *(int*)(*(int*)(iVar2 + 0x14) + iVar6 * 4);
            if (*(uint32_t*)(iVar7 + 0x48) < uVar9) {
                uVar9 = *(uint32_t*)(iVar7 + 0x48);
            }
            if (local_c < *(uint32_t*)(iVar7 + 0x58)) {
                local_c = *(uint32_t*)(iVar7 + 0x58);
            }
            param_3 = param_3 + -1;
            iVar6 = *(int*)(iVar7 + 0x14);
        } while (param_3 != 0);
    }
    if (((uVar9 <= param_1) && (param_1 <= local_c)) ||
        ((local_8 <= param_2) && (param_2 <= local_10))) {
        if (local_8 < uVar9) {
            return 1;
        }
        if (uVar9 < local_8) {
            return 0xffffffff;
        }
    }
    iVar5 = *(int*)(*(int*)(iVar2 + 0x14) + **(int**)(iVar5 + 0x10) * 4);
    iVar8 = *(int*)(*(int*)(iVar2 + 0x14) + **(int**)(iVar8 + 0x10) * 4);
    iVar6 = *(int*)(iVar8 + 0x18);
    iVar7 = *(int*)(iVar5 + 0x18);
    iVar4 = *(int*)(iVar5 + 0x14);
    local_10 = 0;
    param_3 = 0;
    iVar8 = *(int*)(iVar8 + 0x14);
    for (iVar5 = iVar4; iVar3 = iVar8, iVar5 != -1;
         iVar5 = *(int*)(*(int*)(*(int*)(iVar2 + 0x14) + iVar5 * 4) + 0x14)) {
        local_10 = local_10 + 1;
    }
    for (; iVar3 != -1; iVar3 = *(int*)(*(int*)(*(int*)(iVar2 + 0x14) + iVar3 * 4) + 0x14)) {
        param_3 = param_3 + 1;
    }
    if (param_3 < local_10) {
        iVar5 = local_10 - param_3;
        do {
            iVar4 = *(int*)(*(int*)(iVar2 + 0x14) + iVar4 * 4);
            iVar7 = *(int*)(iVar4 + 0x18);
            iVar4 = *(int*)(iVar4 + 0x14);
            local_10 = local_10 - 1;
            iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
    }
    if (local_10 < param_3) {
        iVar5 = param_3 - local_10;
        do {
            iVar5 = iVar5 + -1;
            iVar8 = *(int*)(*(int*)(iVar2 + 0x14) + iVar8 * 4);
            iVar6 = *(int*)(iVar8 + 0x18);
            iVar8 = *(int*)(iVar8 + 0x14);
        } while (iVar5 != 0);
    }
    if (iVar4 != iVar8) {
        do {
            iVar5 = *(int*)(*(int*)(iVar2 + 0x14) + iVar4 * 4);
            iVar8 = *(int*)(*(int*)(iVar2 + 0x14) + iVar8 * 4);
            iVar7 = *(int*)(iVar5 + 0x18);
            iVar6 = *(int*)(iVar8 + 0x18);
            iVar4 = *(int*)(iVar5 + 0x14);
            iVar8 = *(int*)(iVar8 + 0x14);
        } while (iVar4 != iVar8);
    }
    if (iVar7 == 0) {
        if (iVar6 != 0) {
            return 1;
        }
    }
    else if (iVar6 == 0) {
        return 0xffffffff;
    }
    if (param_1 < param_2) {
        return 0xffffffff;
    }
    return (uint32_t)(param_2 < param_1);
}

// ---------------------------------------------------------------------------
// Two-index comparator over the 0xc-byte record table at *(self+0xbc)+0x58:
// unsigned field +4, then signed field +8. Register receiver in_EAX, indices
// in in_ECX / in_EDX.
// 0x65e0f1 — observed shape
uint32_t __cdecl FUN_0065e0f1(void* self, int param_1, int param_2)
{
    int iVar1;
    int iVar2;
    uint32_t uVar3;
    uint32_t uVar4;

    iVar2 = *(int*)(*(int*)((uint8_t*)self + 0xbc) + 0x58);
    iVar1 = iVar2 + param_1 * 0xc;
    iVar2 = iVar2 + param_2 * 0xc;
    uVar3 = *(uint32_t*)(iVar1 + 4);
    uVar4 = *(uint32_t*)(iVar2 + 4);
    if (uVar4 <= uVar3) {
        if (uVar4 < uVar3) {
            return 1;
        }
        iVar1 = *(int*)(iVar1 + 8);
        iVar2 = *(int*)(iVar2 + 8);
        if (iVar2 <= iVar1) {
            return (uint32_t)(iVar2 < iVar1);
        }
    }
    return 0xffffffff;
}

// ---------------------------------------------------------------------------
// Two-index comparator over the 0xc-byte record table at *(object_arg+0xbc)
// +0x58: compares only the first unsigned field of each record.
// 0x65e132 — observed shape
uint32_t __cdecl FUN_0065e132(int param_1, int param_2, int param_3)
{
    int iVar1;
    uint32_t uVar2;
    uint32_t uVar3;

    iVar1 = *(int*)(*(int*)(param_3 + 0xbc) + 0x58);
    uVar3 = *(uint32_t*)(iVar1 + param_1 * 0xc);
    uVar2 = *(uint32_t*)(iVar1 + param_2 * 0xc);
    if (uVar2 < uVar3) {
        uVar3 = 0xffffffff;
    }
    else {
        uVar3 = (uint32_t)(uVar3 < uVar2);
    }
    return uVar3;
}

// ---------------------------------------------------------------------------
// Terminal comparator adapter: calls 0x65e0f1 with the register triple
// (in_EAX receiver, in_ECX / in_EDX indices) already live in this frame and
// falls through to 0x65e132 when the first comparison returns 0. The provider
// prints both calls without arguments; the casts preserve that call shape.
// 0x65e16a — observed shape
void __cdecl FUN_0065e16a(void)
{
    typedef uint32_t(__cdecl* RegComparator)(void);
    int iVar1;

    iVar1 = ((RegComparator)FUN_0065e0f1)();
    if (iVar1 == 0) {
        ((RegComparator)FUN_0065e132)();
        return;
    }
    return;
}

// ---------------------------------------------------------------------------
// Two-index comparator over the table at object+0x14, comparing only the
// unsigned field +0x40 of each entry.
// 0x65e18b — observed shape
uint32_t __cdecl FUN_0065e18b(int param_1, int param_2, int param_3)
{
    uint32_t uVar1;
    uint32_t uVar2;

    uVar2 = *(uint32_t*)(*(int*)(*(int*)(param_3 + 0x14) + param_1 * 4) + 0x40);
    uVar1 = *(uint32_t*)(*(int*)(*(int*)(param_3 + 0x14) + param_2 * 4) + 0x40);
    if (uVar2 < uVar1) {
        uVar2 = 0xffffffff;
    }
    else {
        uVar2 = (uint32_t)(uVar1 < uVar2);
    }
    return uVar2;
}

// ---------------------------------------------------------------------------
// In-place heap sort of param_3 uint32 elements at param_2 using the
// three-argument comparator param_1 with context param_4: bottom-up sift-down
// build over indices (n>>1)..1, then repeatedly move the root to the shrinking
// tail and sift the saved element back down. Void return.
// 0x65e1b9 — observed shape
typedef int32_t(__cdecl* FUN_0065e1b9_cmp)(uint32_t, uint32_t, uint32_t);

void __cdecl FUN_0065e1b9(FUN_0065e1b9_cmp param_1, uint32_t* param_2, uint32_t param_3,
                          uint32_t param_4)
{
    uint32_t uVar1;
    uint32_t uVar2;
    uint32_t* puVar3;
    int iVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    uint32_t uVar7;
    uint32_t uVar8;
    uint32_t local_c;
    uint32_t local_8;

    puVar3 = param_2;
    if (1 < param_3) {
        uVar5 = param_3 >> 1;
        if (uVar5 != 0) {
            local_8 = uVar5 * 2 + 1;
            do {
                uVar5 = uVar5 - 1;
                uVar1 = puVar3[uVar5];
                local_8 = local_8 - 2;
                uVar8 = local_8;
                param_2 = (uint32_t*)uVar5;
                while (uVar8 < param_3) {
                    local_c = puVar3[uVar8];
                    uVar7 = uVar8;
                    if (uVar8 + 1 < param_3) {
                        uVar6 = puVar3[uVar8 + 1];
                        iVar4 = (*param_1)(uVar6, local_c, param_4);
                        if (0 < iVar4) {
                            uVar7 = uVar8 + 1;
                            local_c = uVar6;
                        }
                    }
                    iVar4 = (*param_1)(local_c, uVar1, param_4);
                    if (iVar4 < 1) {
                        break;
                    }
                    puVar3[(int)param_2] = puVar3[uVar7];
                    param_2 = (uint32_t*)uVar7;
                    uVar8 = uVar7 * 2 + 1;
                }
                puVar3[(int)param_2] = uVar1;
            } while (uVar5 != 0);
        }
        while (param_3 = param_3 - 1, param_3 != 0) {
            param_2 = (uint32_t*)0x0;
            uVar1 = puVar3[param_3];
            uVar5 = 1;
            puVar3[param_3] = *puVar3;
            if (1 < param_3) {
                do {
                    uVar6 = puVar3[uVar5];
                    uVar8 = uVar5;
                    if (uVar5 + 1 < param_3) {
                        uVar2 = puVar3[uVar5 + 1];
                        iVar4 = (*param_1)(uVar2, uVar6, param_4);
                        if (0 < iVar4) {
                            uVar6 = uVar2;
                            uVar8 = uVar5 + 1;
                        }
                    }
                    iVar4 = (*param_1)(uVar6, uVar1, param_4);
                    if (iVar4 < 1) {
                        break;
                    }
                    uVar5 = uVar8 * 2 + 1;
                    puVar3[(int)param_2] = puVar3[uVar8];
                    param_2 = (uint32_t*)uVar8;
                } while (uVar5 < param_3);
            }
            puVar3[(int)param_2] = uVar1;
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// Constructor body. Runs the base initializer 0x65d65d, zeroes dword slots
// 0x30-0x34, 0x36-0x38, stores -1 into dword slots 0x1d-0x28 and 0x2a-0x2e,
// then installs the vtable PTR_FUN_006ee24c. Slot 0x35 and 0x29 are untouched.
// 0x65e2d0 — observed shape
void __thiscall FUN_0065e2d0(void* self)
{
    uint32_t* p = (uint32_t*)self;

    FUN_0065d65d(self);
    p[0x30] = 0;
    p[0x31] = 0;
    p[0x32] = 0;
    p[0x33] = 0;
    p[0x34] = 0;
    p[0x38] = 0;
    p[0x36] = 0;
    p[0x37] = 0;
    p[0x1d] = 0xffffffff;
    p[0x1e] = 0xffffffff;
    p[0x1f] = 0xffffffff;
    p[0x20] = 0xffffffff;
    p[0x21] = 0xffffffff;
    p[0x22] = 0xffffffff;
    p[0x23] = 0xffffffff;
    p[0x24] = 0xffffffff;
    p[0x25] = 0xffffffff;
    p[0x26] = 0xffffffff;
    p[0x27] = 0xffffffff;
    p[0x28] = 0xffffffff;
    p[0x2a] = 0xffffffff;
    p[0x2b] = 0xffffffff;
    p[0x2c] = 0xffffffff;
    p[0x2d] = 0xffffffff;
    p[0x2e] = 0xffffffff;
    p[0] = (uint32_t)&PTR_FUN_006ee24c;
    return;
}

// ---------------------------------------------------------------------------
// Destructor body. Reinstalls the vtable, frees the owned block in dword slot
// 0x34, invokes the first virtual entry of the object in slot 0x38 with
// argument 1 when that slot is non-null, then runs the base teardown
// 0x65dba2. Void return.
// 0x65e376 — observed shape
void __thiscall FUN_0065e376(void* self)
{
    uint32_t* p = (uint32_t*)self;

    p[0] = (uint32_t)&PTR_FUN_006ee24c;
    operator_delete((void*)p[0x34]);
    if (p[0x38] != 0) {
        void** obj = (void**)p[0x38];
        ((void(__cdecl*)(int))obj[0])(1);
    }
    FUN_0065dba2(self);
    return;
}

// ---------------------------------------------------------------------------
// Replaces the string owned in dword slot 0x34 (byte offset 0xd0): computes
// strlen+1, allocates through 0x533c78, copies the argument, frees the old
// pointer and stores the new one. Returns 0x8007000e when allocation fails
// and 0 when the swap completed (including a null argument).
// 0x65e3ad — observed shape
uint32_t __thiscall FUN_0065e3ad(void* self, char* param_1)
{
    char cVar1;
    char* pcVar2;
    uint32_t uVar3;
    char* pcVar4;
    char* pcVar5;

    pcVar4 = (char*)0x0;
    if (param_1 != (char*)0x0) {
        pcVar2 = param_1;
        do {
            cVar1 = *pcVar2;
            pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        pcVar2 = pcVar2 + (1 - (int)(param_1 + 1));
        pcVar4 = (char*)FUN_00533c78((size_t)pcVar2);
        if (pcVar4 == (char*)0x0) {
            return 0x8007000e;
        }
        pcVar5 = pcVar4;
        for (uVar3 = (uint32_t)pcVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(uint32_t*)pcVar5 = *(uint32_t*)param_1;
            param_1 = param_1 + 4;
            pcVar5 = pcVar5 + 4;
        }
        for (uVar3 = (uint32_t)pcVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *pcVar5 = *param_1;
            param_1 = param_1 + 1;
            pcVar5 = pcVar5 + 1;
        }
    }
    operator_delete(*(void**)((uint8_t*)self + 0xd0));
    *(char**)((uint8_t*)self + 0xd0) = pcVar4;
    return 0;
}

// ---------------------------------------------------------------------------
// NEEDS_MANUAL: provider models a void return, but the trailing loop walks the
// union-find parent chain (node field +0x30 of table object+0x14) and only
// leaves the resulting root in a local. The walk is preserved as observed and
// the computed root is discarded; the original almost certainly returned it.
// Selects the starting index either from the row-major cell
// (*(param_1+0xc)*param_2+param_3) at *(param_1+8) when param_4 is 0, or from
// the min/max of two cells when param_4 is non-zero, then resolves the root.
// 0x65e43a — observed shape
void __thiscall FUN_0065e43a(void* self, int param_1, int param_2, int param_3, int param_4)
{
    uint32_t uVar1;
    uint32_t uVar2;

    if (param_4 == 0) {
        uVar2 = *(uint32_t*)(*(int*)(param_1 + 8) + (*(int*)(param_1 + 0xc) * param_2 + param_3) * 4);
    }
    else {
        uVar1 = *(uint32_t*)(*(int*)(param_1 + 8) + param_3 * 4);
        uVar2 = *(uint32_t*)(*(int*)(param_1 + 8) + (*(int*)(param_1 + 0xc) + param_3) * 4);
        if (param_2 == 0) {
            if (uVar2 < uVar1) goto LAB_0065e483;
        }
        else if (uVar1 <= uVar2) goto LAB_0065e483;
        uVar2 = uVar1;
    }
LAB_0065e483:
    while (uVar1 = *(uint32_t*)(*(int*)(*(int*)((uint8_t*)self + 0x14) + uVar2 * 4) + 0x30),
           uVar2 != uVar1) {
        uVar2 = uVar1;
    }
    return;
}

// ---------------------------------------------------------------------------
// Scalar-deleting destructor body: installs the vtable PTR_FUN_006ee26c, then
// frees the receiver when bit 0 of the flags argument is set. Void return.
// 0x65e49f — observed shape
void __thiscall FUN_0065e49f(void* self, uint8_t param_1)
{
    uint32_t* p = (uint32_t*)self;

    p[0] = (uint32_t)&PTR_FUN_006ee26c;
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return;
}

// ---------------------------------------------------------------------------
// Counts the parent-chain length above table entry param_1 (node field +0x14
// of the table at self+0x14) and raises the caller's maximum at *param_2 when
// the chain is longer. No return value.
// 0x65e4c1 — observed shape
void __thiscall FUN_0065e4c1(void* self, int param_1, uint32_t* param_2)
{
    int iVar1;
    uint32_t uVar2;

    iVar1 = *(int*)(*(int*)(*(int*)((uint8_t*)self + 0x14) + param_1 * 4) + 0x14);
    uVar2 = 0;
    if (iVar1 != -1) {
        do {
            iVar1 = *(int*)(*(int*)(*(int*)((uint8_t*)self + 0x14) + iVar1 * 4) + 0x14);
            uVar2 = uVar2 + 1;
        } while (iVar1 != -1);
        if (*param_2 < uVar2) {
            *param_2 = uVar2;
        }
    }
    return;
}

// ---------------------------------------------------------------------------
// Compacts the pointer array at self+0x18 (element count at self+0xc): keeps
// entries whose uint16 field +2, masked with 0xfff0, is non-zero and drops the
// rest after notifying 0x614343 with 1. When nothing was dropped returns 1;
// otherwise zero-fills the freed tail, shrinks the count, and returns 0.
// 0x65e4f2 — observed shape
uint32_t __thiscall FUN_0065e4f2(void* self)
{
    uint32_t uVar1;
    int iVar2;
    int iVar3;
    uint32_t uVar4;
    uint32_t* puVar5;

    uVar4 = 0;
    iVar3 = 0;
    if (*(int*)((uint8_t*)self + 0xc) != 0) {
        do {
            iVar2 = *(int*)(*(int*)((uint8_t*)self + 0x18) + uVar4 * 4);
            if ((*(uint16_t*)(iVar2 + 2) & 0xfff0) == 0) {
                FUN_00614343(1);
            }
            else {
                *(int*)(*(int*)((uint8_t*)self + 0x18) + iVar3 * 4) = iVar2;
                iVar3 = iVar3 + 1;
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < *(uint32_t*)((uint8_t*)self + 0xc));
    }
    if (iVar3 == *(int*)((uint8_t*)self + 0xc)) {
        uVar1 = 1;
    }
    else {
        puVar5 = (uint32_t*)(*(int*)((uint8_t*)self + 0x18) + iVar3 * 4);
        for (uVar4 = *(int*)((uint8_t*)self + 0xc) - iVar3 & 0x3fffffff; uVar4 != 0;
             uVar4 = uVar4 - 1) {
            *puVar5 = 0;
            puVar5 = puVar5 + 1;
        }
        for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
            *(uint8_t*)puVar5 = 0;
            puVar5 = (uint32_t*)((int)puVar5 + 1);
        }
        *(int*)((uint8_t*)self + 0xc) = iVar3;
        uVar1 = 0;
    }
    return uVar1;
}

// ---------------------------------------------------------------------------
// Walks the parent chain from table entry param_1 (table at self+0x14, next
// index at entry field +8) and returns 1 when the entry's first byte has flag
// 0x20 set, or when its parent (field +0x38) is valid and that parent's first
// byte has flag 0x20; otherwise returns 0 at the end of the chain.
// 0x65e551 — observed shape
uint32_t __thiscall FUN_0065e551(void* self, int param_1)
{
    uint8_t* pbVar1;

    if (param_1 != -1) {
        do {
            pbVar1 = *(uint8_t**)(*(int*)((uint8_t*)self + 0x14) + param_1 * 4);
            if (((*pbVar1 & 0x20) != 0) ||
                ((*(int*)(pbVar1 + 0x38) != -1 &&
                  ((**(uint8_t**)(*(int*)((uint8_t*)self + 0x14) +
                                  *(int*)(pbVar1 + 0x38) * 4) & 0x20) != 0)))) {
                return 1;
            }
            param_1 = *(int*)(pbVar1 + 8);
        } while (param_1 != -1);
    }
    return 0;
}
