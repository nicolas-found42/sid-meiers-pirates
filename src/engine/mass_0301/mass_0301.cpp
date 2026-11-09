// Clean-room reconstruction from shipped bytes (Ghidra 12.2 corpus only).
// Batch mass_0301 (addresses 0x647ca9..0x6492dc). No byte-match claim.
// Status: unverified. Globals/callees keep their corpus labels; types inferred.
// Register receivers in_ECX/in_EDX appear as an explicit `self` parameter.

#include <cstdint>
#include <cstddef>
#include <windows.h>

// ---- Observed corpus labels ----
extern uint8_t  PTR_FUN_006ec450[];  // vtable label written into self[0]
extern uint8_t  PTR_LAB_006ec270[];  // vtable label written into self[1]
extern uint8_t  DAT_006eac9c[];      // record table, stride 0x1c

// ---- Observed helpers (signatures inferred from call sites) ----
void operator_delete(void* p);
extern void FUN_00412770(void* self, uint32_t size, uint32_t unknown, void* dtor);
extern void FUN_00647c8a(void* self);   // receiver inferred (ECX)
extern void FUN_00647b53(void* self);   // receiver inferred (ECX)
extern void*    FUN_00647b28();         // no-arg ctor, returns the object
extern void FUN_00646c28(void* self);   // receiver inferred (ECX)
extern void*    FUN_006417d1();         // in-place construct, returns the object
extern int32_t  FUN_00647c0a(int32_t mode);
extern int32_t  FUN_006294f9(uint32_t size, int32_t* out);
extern void     FUN_0063e5ce(int32_t* rec);
extern void     FUN_0063e62c(int32_t* rec);

typedef int32_t (*Vfn_ret_int)(void*);
typedef void*   (*Vfn_ret_ptr)(void*);

// 0x647ca9 — observed shape
// Scalar deleting destructor: bit1 selects the in-place base teardown path
// (allocator FUN_00412770 with object size 0x38 and dtor FUN_00647c8a),
// bit0 requests the release.
void FUN_00647ca9(void* self, uint8_t param_1)
{
    if ((param_1 & 2) == 0) {
        FUN_00647c8a(self);
        if ((param_1 & 1) != 0) {
            operator_delete(self);
        }
    }
    else {
        FUN_00412770(self, 0x38, *(uint32_t*)((uint8_t*)self - 4), (void*)&FUN_00647c8a);
        if ((param_1 & 1) != 0) {
            operator_delete((uint8_t*)self - 4);
        }
    }
}

// 0x647cf7 — observed shape
// NEEDS_MANUAL: the provider models the post-call base pointer as extraout_EDX,
// a register leftover of FUN_006417d1 rather than a declared return value; the
// whole field clear-out below is expressed against that pointer.
int32_t FUN_00647cf7(void* self)
{
    uint32_t* obj = (uint32_t*)self;

    obj[0] = (uint32_t)(uintptr_t)&PTR_FUN_006ec450;
    obj[1] = (uint32_t)(uintptr_t)&PTR_LAB_006ec270;
    obj[4] = 0;
    obj[3] = 0;
    obj[2] = 0;
    FUN_00647b28();
    uint8_t* base = (uint8_t*)FUN_006417d1();

    *(uint16_t*)(base + 0x118) = (uint16_t)(*(uint16_t*)(base + 0x118) & 0xe478);
    *(uint32_t*)(base + 0x38) = 0;
    *(uint32_t*)(base + 0x9c) = 0;
    *(uint32_t*)(base + 0xa4) = 0;
    *(uint32_t*)(base + 0x18) = 0;
    *(uint32_t*)(base + 0x20) = 0;
    *(uint32_t*)(base + 0xb0) = 0;
    *(uint32_t*)(base + 0x28) = 0;
    *(uint32_t*)(base + 0xc4) = 0;
    *(uint32_t*)(base + 0x100) = 0;
    *(uint32_t*)(base + 0x104) = 0;
    *(uint32_t*)(base + 0xb4) = 0;
    *(uint32_t*)(base + 0xc0) = 0;
    *(uint32_t*)(base + 0xb8) = 0;
    *(uint32_t*)(base + 0xbc) = 0;
    *(uint32_t*)(base + 200) = 0;
    *(uint32_t*)(base + 0xcc) = 0;
    *(uint16_t*)(base + 0x30) = 0;
    *(uint32_t*)(base + 0x34) = 0;
    *(uint32_t*)(base + 0x2c) = 0;
    *(uint32_t*)(base + 0xd0) = 0;
    *(uint32_t*)(base + 0xd4) = 0;
    *(uint32_t*)(base + 0xd8) = 0;
    *(uint32_t*)(base + 0xdc) = 0;
    *(uint32_t*)(base + 0x114) = 0;
    *(uint32_t*)(base + 0x74) = 0;
    *(uint32_t*)(base + 0x78) = 0;
    *(uint32_t*)(base + 0x60) = 0;
    *(uint32_t*)(base + 100) = 0;
    *(uint32_t*)(base + 0x5c) = 0;
    *(uint32_t*)(base + 0x108) = 0;
    *(uint32_t*)(base + 0x10c) = 0;
    *(uint32_t*)(base + 0x110) = 0;
    *(uint32_t*)(base + 0x128) = 0;
    *(uint32_t*)(base + 0x124) = 0;
    *(uint32_t*)(base + 300) = 0;
    *(uint32_t*)(base + 0x120) = 0;
    *(uint32_t*)(base + 0x11c) = 0;
    *(uint32_t*)(base + 0x3c) = 0;
    *(uint32_t*)(base + 0x24) = 1;
    return (int32_t)(uintptr_t)base;
}

// 0x647df7 — observed shape
// Scalar deleting destructor: unconditional base teardown FUN_00646c28, then
// release only when bit0 is set.
void FUN_00647df7(void* self, uint8_t param_1)
{
    FUN_00646c28(self);
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
}

// 0x647e18 — observed shape
// Scalar deleting destructor, object size 0x50, dtor FUN_00647b53.
void FUN_00647e18(void* self, uint8_t param_1)
{
    if ((param_1 & 2) == 0) {
        FUN_00647b53(self);
        if ((param_1 & 1) != 0) {
            operator_delete(self);
        }
    }
    else {
        FUN_00412770(self, 0x50, *(uint32_t*)((uint8_t*)self - 4), (void*)&FUN_00647b53);
        if ((param_1 & 1) != 0) {
            operator_delete((uint8_t*)self - 4);
        }
    }
}

// 0x647e66 — observed shape
// Deserialiser for one record pair: validates the record type nibble through
// DAT_006eac9c[...] (accepts only 0x10 and 0x0f), consumes an id from the
// reader's element buffer via virtuals +0x10 (count) and +0xc (data base),
// resolves a slot through the 0xb0 table, then either clears the record or
// copies 40 bytes into the freshly allocated entry. Returns 0 on success,
// the negative helper status on failure, and -0x7fffbffb when the reader ran
// out of elements.
int32_t FUN_00647e66(void* self_, uint32_t param_1, int32_t param_2,
                     int32_t* param_3, uint32_t* param_4)
{
    uint8_t* self = (uint8_t*)self_;
    int32_t  iVar4;
    uint32_t uVar5;
    int32_t  iVar6;
    int32_t  iVar7;
    int32_t  iVar9;
    int32_t* piVar2;
    int32_t* piVar3;
    uint32_t* puVar1;
    uint32_t* puVar8;
    uint32_t* puVar10;
    uint32_t* puVar11;

    iVar4 = (int32_t)(param_1 * 100) + *(int32_t*)(self + 0x2c);
    puVar10 = (uint32_t*)((intptr_t)(param_2 * 100) + *(int32_t*)(iVar4 + 4));
    if ((*(int32_t*)(DAT_006eac9c + (uint32_t)*(uint16_t*)((intptr_t)puVar10 + 0x52) * 0x1c) != 0x10) &&
        (*(int32_t*)(DAT_006eac9c + (uint32_t)*(uint16_t*)((intptr_t)puVar10 + 0x52) * 0x1c) != 0x0f)) {
        return 0;
    }
    if ((param_3 != 0) &&
        (uVar5 = (uint32_t)((Vfn_ret_int)(*(void***)param_3)[4])(param_3), *param_4 + 1 <= uVar5)) {
        iVar6 = ((Vfn_ret_int)(*(void***)param_3)[3])(param_3);
        param_1 = *(uint32_t*)(iVar6 + *param_4 * 4);
    }
    *param_4 = *param_4 + 1;
    if ((param_3 != 0) &&
        (uVar5 = (uint32_t)((Vfn_ret_int)(*(void***)param_3)[4])(param_3), *param_4 <= uVar5)) {
        piVar2 = (int32_t*)(*(int32_t*)(self + 0xb0) + puVar10[7] * 4);
        iVar6 = *piVar2;
        if (*(int32_t*)(iVar6 + 0x40) == 0) {
            iVar6 = *(int32_t*)(*(int32_t*)(iVar6 + 0x30) + puVar10[9] + *(int32_t*)(self + 0x20));
        }
        else {
            iVar6 = *piVar2;
            iVar6 = *(int32_t*)(*(int32_t*)(*(int32_t*)(iVar6 + 0x40) + 8) +
                    *(int32_t*)(*(int32_t*)(iVar6 + 0x30) + puVar10[9] +
                                *(int32_t*)(*(int32_t*)(self + 0x38) + 0x10)) * 4);
        }
        piVar2 = (int32_t*)(*(int32_t*)(self + 0x18) + iVar6 * 0x18);
        if ((uint32_t)*(uint16_t*)(self + 0x30) < *(uint32_t*)(self + 0x34)) {
            *(uint16_t*)((uint8_t*)piVar2 + 0x10) = *(uint16_t*)(self + 0x30);
            *(int16_t*)(self + 0x30) = (int16_t)(*(int16_t*)(self + 0x30) + 1);
            iVar6 = FUN_00647c0a(1);
            if (iVar6 < 0) {
                return iVar6;
            }
            iVar9 = *(int32_t*)(DAT_006eac9c + (uint32_t)*(uint16_t*)((intptr_t)puVar10 + 0x52) * 0x1c);
            *piVar2 = iVar9;
            iVar7 = (int32_t)((uint32_t)*(uint16_t*)((uint8_t*)piVar2 + 0x10) * 100) + *(int32_t*)(self + 0x2c);
            if (iVar9 == 0x10) {
                *(uint16_t*)(iVar7 + 0x18) = 0;
                *(uint16_t*)(*(int32_t*)(iVar7 + 4) + 0x52) = 0x92;
                *(uint32_t*)(*(int32_t*)(iVar7 + 4) + 0x58) = 0x0a000000;
            }
            else {
                *(uint16_t*)(iVar7 + 0x1a) = 0;
                *(uint16_t*)(*(int32_t*)(iVar7 + 4) + 0x52) = 0x93;
                *(uint32_t*)(*(int32_t*)(iVar7 + 4) + 0x58) = 0x0b000000;
            }
            *(uint16_t*)(*(int32_t*)(iVar7 + 4) + 0x54) = 0xffff;
            *(uint16_t*)(*(int32_t*)(iVar7 + 4) + 0x56) = 1;
            puVar1 = (uint32_t*)(*(int32_t*)(iVar7 + 4) + 0x30);
            *puVar1 = *puVar1 | 1;
            **(uint32_t**)(iVar7 + 4) = 1;
            puVar8 = puVar10 + 2;
            puVar11 = (uint32_t*)(*(int32_t*)(iVar7 + 4) + 8);
            for (iVar9 = 10; iVar9 != 0; iVar9 = iVar9 + -1) {
                *puVar11 = *puVar8;
                puVar8 = puVar8 + 1;
                puVar11 = puVar11 + 1;
            }
            *(uint32_t*)(*(int32_t*)(iVar7 + 4) + 0x28) = 0;
            *(uint32_t*)(*(int32_t*)(iVar7 + 4) + 0x2c) = 0;
            if (param_1 == 0) {
                return iVar6;
            }
            iVar6 = FUN_006294f9(param_1, piVar2 + 2);
            if (iVar6 < 0) {
                return iVar6;
            }
            piVar3 = (int32_t*)piVar2[2];
            puVar8 = (uint32_t*)((Vfn_ret_ptr)(*(void***)piVar3)[3])(piVar3);
            iVar6 = (int32_t)((uint32_t)((param_1 & 3) != 0) + (param_1 >> 2));
            uVar5 = (uint32_t)((Vfn_ret_int)(*(void***)param_3)[4])(param_3);
            if (*param_4 + (uint32_t)iVar6 <= uVar5) {
                iVar9 = ((Vfn_ret_int)(*(void***)param_3)[3])(param_3);
                puVar11 = (uint32_t*)(iVar9 + *param_4 * 4);
                for (uVar5 = param_1 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                    *puVar8 = *puVar11;
                    puVar11 = puVar11 + 1;
                    puVar8 = puVar8 + 1;
                }
                for (param_1 = param_1 & 3; param_1 != 0; param_1 = param_1 - 1) {
                    *(uint8_t*)puVar8 = *(uint8_t*)puVar11;
                    puVar11 = (uint32_t*)((intptr_t)puVar11 + 1);
                    puVar8 = (uint32_t*)((intptr_t)puVar8 + 1);
                }
            }
            *param_4 = *param_4 + (uint32_t)iVar6;
            uVar5 = (uint32_t)((Vfn_ret_int)(*(void***)param_3)[4])(param_3);
            if (*param_4 <= uVar5) {
                if (*piVar2 == 0x10) {
                    FUN_0063e5ce(piVar2);
                }
                else {
                    FUN_0063e62c(piVar2);
                }
                *(uint16_t*)((uint8_t*)puVar10 + 0x54) = 0xffff;
                *puVar10 = 0;
                *(uint16_t*)((uint8_t*)puVar10 + 0x52) = 0xb3;
                puVar10[0x16] = 0x0e000000;
                *(uint16_t*)((uint8_t*)puVar10 + 0x56) = 1;
                *(int16_t*)(iVar4 + 0x34) = (int16_t)(*(int16_t*)(iVar4 + 0x34) + 1);
                iVar6 = (int32_t)((*(uint32_t*)(iVar4 + 0xc) & 3) + (*(uint32_t*)(iVar4 + 0xc) & 0xfffffffc));
                *(int32_t*)(iVar4 + 0xc) = iVar6;
                puVar10[0x12] = (uint32_t)iVar6;
                *(int32_t*)(iVar4 + 0xc) = *(int32_t*)(iVar4 + 0xc) + 4;
                return 0;
            }
        }
    }
    return -0x7fffbffb;
}

// ---- Additional observed helpers/labels used by the 0x6480e4 block ----
extern uint8_t DAT_006eaca0[];  // DAT_006eac9c + 4
extern uint8_t DAT_006eaca4[];  // DAT_006eac9c + 8
extern uint8_t DAT_006eacac[];  // DAT_006eac9c + 0x10
extern uint8_t LAB_0063e2de[];
extern uint32_t FUN_0063e918(int32_t handle);
extern uint32_t FUN_0063e8bc(int32_t handle);
extern uint32_t FUN_0063e97c(int32_t a, int32_t b, int32_t c, void* d, int32_t e);
extern void*    FUN_00533c78(uint32_t size);
extern void     FUN_004127b0(void* p, int32_t elemSize, int32_t count, void* dtor);

// 0x6480e4 — observed shape
// Recursive record-array reader. param_1 and param_2 are cursors held in 32-bit
// words (address values), which is why every advance is a plain integer add.
// Layout probed from the record head: [+0]id [+4]kind [+8]handle [+0xc]handle
// [+0x10]count [+0x14]storedCount [+0x18]stride [,0x1c] then payload. Kind 0..3
// reads one flat payload block; kind 5 recurses width*height times; kind 4 is
// the entry table writer (ids 4..9 flat, 9..0xe virtual-list, 0xf..0x10 flat).
// The corpus encodes each bounds failure as -(uint)(cond) & 0x80004005; that
// idiom is written here as the equivalent ternary so the codes stay visible.
uint32_t FUN_006480e4(void* self_, int32_t* param_1, uint32_t* param_2, int32_t param_3)
{
    uint8_t*  self = (uint8_t*)self_;
    uint32_t* puVar1;
    uint32_t* puVar5;
    uint32_t* puVar8;
    uint32_t* puVar9;
    uint32_t* puVar13;
    uint32_t* puVar16;
    int32_t*  piVar14;
    uint32_t  uVar3;
    uint32_t  uVar6 = 0;
    uint32_t  uVar7;
    uint16_t  uVar2;
    int32_t   iVar4;
    int32_t   iVar10;
    int32_t   iVar11;
    int32_t   iVar12;
    int32_t   iVar15;
    uint32_t  local_10;
    uint32_t  local_c;
    uint32_t  local_8;
    int32_t   entry_off;

    puVar13 = param_2;
    puVar5 = (uint32_t*)(intptr_t)(*(int32_t*)(self + 0x1c) + *(int32_t*)(self + 0x20));
    piVar14 = (int32_t*)(intptr_t)*param_1;
    puVar1 = (uint32_t*)(piVar14 + 5);
    if (puVar5 < puVar1) {
        return 0x80004005u;
    }
    iVar12 = *piVar14;
    local_10 = (uint32_t)piVar14[4];
    uVar6 = FUN_0063e918(piVar14[2]);
    if ((int32_t)uVar6 < 0) {
        return uVar6;
    }
    uVar6 = FUN_0063e8bc(piVar14[3]);
    if ((int32_t)uVar6 < 0) {
        return uVar6;
    }
    if (local_10 == 0) {
        local_10 = 1;
    }
    uVar6 = local_10;
    iVar10 = piVar14[1];
    if (iVar10 < 0) {
        return 0x80004005u;
    }
    if (iVar10 < 4) {
        if (iVar12 < 1) {
            return 0x80004005u;
        }
        if ((2 < iVar12) && (iVar12 != 3)) {
            return 0x80004005u;
        }
        uVar6 = (puVar5 < (uint32_t*)(piVar14 + 7)) ? 0u : 0x80004005u;
        if ((int32_t)uVar6 < 0) {
            return uVar6;
        }
        iVar12 = piVar14[6] * (int32_t)*puVar1 * (int32_t)local_10;
        uVar6 = (puVar5 < (uint32_t*)(piVar14 + iVar12)) ? 0u : 0x80004005u;
        if ((int32_t)uVar6 < 0) {
            return uVar6;
        }
        *param_2 = *param_2 + (uint32_t)iVar12 * 4;
        *param_1 = *param_1 + 0x1c;
        return uVar6;
    }
    if (iVar10 != 4) {
        if (iVar10 != 5) {
            return 0x80004005u;
        }
        if (iVar12 != 0) {
            return 0x80004005u;
        }
        puVar13 = (uint32_t*)(piVar14 + 6);
        uVar7 = (puVar5 < puVar13) ? 0u : 0x80004005u;
        if ((int32_t)uVar7 < 0) {
            return uVar7;
        }
        uVar3 = *puVar1;
        *param_1 = (int32_t)(intptr_t)puVar13;
        local_8 = 0;
        if (local_10 == 0) {
            return uVar7;
        }
        do {
            *param_1 = (int32_t)(intptr_t)puVar13;
            local_10 = 0;
            if (uVar3 != 0) {
                do {
                    uVar7 = FUN_006480e4(self, param_1, param_2, param_3);
                    if ((int32_t)uVar7 < 0) {
                        return uVar7;
                    }
                    local_10 = local_10 + 1;
                } while (local_10 < uVar3);
            }
            local_8 = local_8 + 1;
        } while (local_8 < uVar6);
        return uVar7;
    }
    uVar6 = 0;
    if (iVar12 < 4) {
        return 0x80004005u;
    }
    if (9 < iVar12) {
        if (iVar12 < 0x0f) {
            iVar12 = *(int32_t*)(intptr_t)(*(int32_t*)(self + 0xb0) + param_3 * 4);
            if (*(int16_t*)(iVar12 + 0x46) != 0) {
                return 0x80004005u;
            }
            local_8 = 0;
            *(int16_t*)(iVar12 + 0x46) = (int16_t)local_10;
            *(int16_t*)(self + 0x30) = (int16_t)(*(int16_t*)(self + 0x30) + (int16_t)local_10);
            if (local_10 != 0) {
                do {
                    iVar10 = (int32_t)((uint32_t)*(uint16_t*)(iVar12 + 0x44) + local_8) * 100
                             + *(int32_t*)(self + 0x2c);
                    *(uint16_t*)(iVar10 + 0x3e) = (uint16_t)param_3;
                    piVar14 = (int32_t*)(intptr_t)*puVar13 + 1;
                    uVar6 = ((int32_t*)(intptr_t)(*(int32_t*)(self + 0x1c) + *(int32_t*)(self + 0x20)) < piVar14)
                            ? 0u : 0x80004005u;
                    if ((int32_t)uVar6 < 0) {
                        return uVar6;
                    }
                    iVar15 = *(int32_t*)(intptr_t)*puVar13;
                    *puVar13 = (uint32_t)(intptr_t)piVar14;
                    iVar11 = FUN_00647c0a(iVar15);
                    if (iVar11 < 0) {
                        return 0x8007000eu;
                    }
                    uVar6 = ((uint32_t)(*(int32_t*)(self + 0x1c) + *(int32_t*)(self + 0x20)) <
                             (uint32_t)(iVar15 * 0x10) + *puVar13) ? 0u : 0x80004005u;
                    if ((int32_t)uVar6 < 0) {
                        return uVar6;
                    }
                    local_c = 0;
                    if (*(int16_t*)(iVar10 + 0x36) != 0) {
                        entry_off = 0;
                        do {
                            puVar9 = (uint32_t*)(intptr_t)(*(int32_t*)(iVar10 + 4) + entry_off);
                            puVar9[0xc] = puVar9[0xc] & 0xfffffffd;
                            *puVar9 = 1;
                            *(uint16_t*)((uint8_t*)puVar9 + 0x52) = *(uint16_t*)(intptr_t)*puVar13;
                            *puVar13 = *puVar13 + 4;
                            puVar9[0x16] = *(uint32_t*)(DAT_006eacac +
                                (uint32_t)*(uint16_t*)((uint8_t*)puVar9 + 0x52) * 0x1c);
                            *(uint16_t*)(puVar9 + 0x15) = *(uint16_t*)(intptr_t)*puVar13;
                            *puVar13 = *puVar13 + 4;
                            *(uint16_t*)(puVar9 + 0x15) = 0xffff;
                            puVar9[8] = *(uint32_t*)(intptr_t)*puVar13;
                            *puVar13 = *puVar13 + 4;
                            puVar9[9] = *(uint32_t*)(intptr_t)*puVar13;
                            *puVar13 = *puVar13 + 4;
                            puVar9[7] = 0;
                            puVar9[3] = puVar9[8] + (uint32_t)*(int32_t*)(self + 0x20);
                            puVar9[2] = (uint32_t)*(int32_t*)(self + 0x20) + puVar9[9];
                            uVar2 = *(uint16_t*)((uint8_t*)puVar9 + 0x52);
                            if (0xb5 < uVar2) {
                                return 0x80004005u;
                            }
                            if (puVar9[0x16] == 0x09000000u) {
                                *(uint32_t*)(intptr_t)(*(int32_t*)(self + 0x18) +
                                    *(int32_t*)(intptr_t)(puVar9[9] + (uint32_t)*(int32_t*)(self + 0x20)) * 0x18) =
                                        *(uint32_t*)(DAT_006eac9c + (uint32_t)uVar2 * 0x1c);
                            }
                            else {
                                if ((puVar9[0x16] & 0xff000000u) != 0x03000000u) {
                                    return 0x80004005u;
                                }
                                iVar11 = (int32_t)((uint32_t)uVar2 * 0x1c);
                                iVar15 = *(int32_t*)(DAT_006eac9c + iVar11);
                                if (((iVar15 != 1) && (iVar15 != 2)) && (iVar15 != 3) && (iVar15 != 0x0f20000)) {
                                    return 0x80004005u;
                                }
                                iVar4 = *(int32_t*)(DAT_006eaca4 + iVar11);
                                iVar11 = *(int32_t*)(DAT_006eaca0 + iVar11);
                                uVar7 = (*(uint32_t*)(iVar10 + 0xc) & 3) + (*(uint32_t*)(iVar10 + 0xc) & 0xfffffffc);
                                uVar7 = (uVar7 & 1) + (uVar7 & 0xfffffffe);
                                uVar7 = (uVar7 & 3) + (uVar7 & 0xfffffffc);
                                uVar7 = (uVar7 & 3) + (uVar7 & 0xfffffffc);
                                iVar15 = (int32_t)((uVar7 & 3) + (uVar7 & 0xfffffffc));
                                *(int32_t*)(iVar10 + 0xc) = iVar15;
                                puVar9[0x12] = (uint32_t)iVar15;
                                *(int32_t*)(iVar10 + 0xc) = *(int32_t*)(iVar10 + 0xc) + iVar4 * iVar11 * 4;
                                puVar9[0xc] = puVar9[0xc] & 0xfffffffd;
                                *puVar9 = 1;
                            }
                            local_c = local_c + 1;
                            entry_off = entry_off + 100;
                        } while (local_c < *(uint16_t*)(iVar10 + 0x36));
                    }
                    local_8 = local_8 + 1;
                } while (local_8 < local_10);
            }
            goto LAB_00648607;
        }
        if (0x10 < iVar12) {
            return 0x80004005u;
        }
    }
    uVar6 = (puVar5 < (uint32_t*)(intptr_t)(*param_2 + local_10 * 4)) ? 0u : 0x80004005u;
    if ((int32_t)uVar6 < 0) {
        return uVar6;
    }
    local_8 = 0;
    if (local_10 != 0) {
        do {
            uVar7 = *(uint32_t*)(intptr_t)*param_2;
            if (*(uint32_t*)(self + 0x14) <= uVar7) {
                return 0x80004005u;
            }
            if (uVar7 == 0) {
                return 0x80004005u;
            }
            iVar10 = (int32_t)(uVar7 * 0x18);
            piVar14 = (int32_t*)(intptr_t)(*(int32_t*)(self + 0x18) + iVar10);
            if (*piVar14 != 0x7fffffff) {
                return 0x80004005u;
            }
            *piVar14 = iVar12;
            puVar1 = (uint32_t*)(intptr_t)(iVar10 + 0x14 + *(int32_t*)(self + 0x18));
            *puVar1 = *puVar1 | 1;
            if ((iVar12 == 0x10) || (iVar12 == 0x0f)) {
                puVar9 = (uint32_t*)(intptr_t)(*(int32_t*)(self + 0xb0) + param_3 * 4);
                if (*(uint32_t*)(self + 0x34) <= (uint32_t)*(uint16_t*)(self + 0x30)) {
                    return 0x80004005u;
                }
                *(uint16_t*)(intptr_t)(iVar10 + 0x10 + *(int32_t*)(self + 0x18)) = *(uint16_t*)(self + 0x30);
                *(int16_t*)((uint8_t*)puVar9 + 0x46) = (int16_t)(*(int16_t*)((uint8_t*)puVar9 + 0x46) + 1);
                *(int16_t*)(self + 0x30) = (int16_t)(*(int16_t*)(self + 0x30) + 1);
                iVar10 = (int32_t)(((uint32_t)*(uint16_t*)(puVar9 + 0x11) - 1) +
                                   (uint32_t)*(uint16_t*)((uint8_t*)puVar9 + 0x46));
                iVar15 = iVar10 * 100 + *(int32_t*)(self + 0x2c);
                *(uint16_t*)(iVar15 + 0x3e) = (uint16_t)param_3;
                if (*(int16_t*)(iVar15 + 0x38) != 0) {
                    return 0x80004005u;
                }
                uVar6 = FUN_00647c0a(1);
                if ((int32_t)uVar6 < 0) {
                    return uVar6;
                }
                if (iVar12 == 0x10) {
                    *(uint16_t*)(iVar15 + 0x18) = 0;
                    *(uint16_t*)(intptr_t)(*(int32_t*)(iVar15 + 4) + 0x52) = 0x92;
                    *(uint32_t*)(intptr_t)(*(int32_t*)(iVar15 + 4) + 0x58) = 0x0a000000u;
                }
                else {
                    *(uint16_t*)(iVar15 + 0x1a) = 0;
                    *(uint16_t*)(intptr_t)(*(int32_t*)(iVar15 + 4) + 0x52) = 0x93;
                    *(uint32_t*)(intptr_t)(*(int32_t*)(iVar15 + 4) + 0x58) = 0x0b000000u;
                }
                *(uint16_t*)(intptr_t)(*(int32_t*)(iVar15 + 4) + 0x54) = 0xffff;
                *(uint16_t*)(intptr_t)(*(int32_t*)(iVar15 + 4) + 0x56) = 1;
                **(uint32_t**)(intptr_t)(iVar15 + 4) = 1;
                puVar1 = (uint32_t*)(intptr_t)(*(int32_t*)(iVar15 + 4) + 0x30);
                *puVar1 = *puVar1 | 1;
                *(uint32_t*)(intptr_t)(*(int32_t*)(iVar15 + 4) + 0x3c) = 0;
                puVar8 = puVar9;
                puVar16 = (uint32_t*)(intptr_t)(*(int32_t*)(iVar15 + 4) + 8);
                for (iVar11 = 10; iVar11 != 0; iVar11 = iVar11 + -1) {
                    *puVar16 = *puVar8;
                    puVar8 = puVar8 + 1;
                    puVar16 = puVar16 + 1;
                }
                *(uint32_t*)(intptr_t)(*(int32_t*)(iVar15 + 4) + 0x28) = 0;
                *(uint32_t*)(intptr_t)(*(int32_t*)(iVar15 + 4) + 0x2c) = 0;
                *(uint32_t*)(intptr_t)(*(int32_t*)(iVar15 + 4) + 0x24) = local_8 << 2;
                uVar6 = local_8;
                if (*(int32_t*)(intptr_t)(*param_1 + 0x10) == 0) {
                    uVar6 = 0xffffffffu;
                }
                *(uint32_t*)(intptr_t)(*(int32_t*)(iVar15 + 4) + 0x10) = uVar6;
                *(uint32_t*)(intptr_t)(*(int32_t*)(iVar15 + 4) + 0x14) = 4;
                puVar8 = (uint32_t*)FUN_00533c78(0x24);
                if (puVar8 == 0) {
                    puVar16 = 0;
                }
                else {
                    puVar16 = puVar8 + 1;
                    *puVar8 = 1;
                    FUN_004127b0(puVar16, 0x20, 1, (void*)LAB_0063e2de);
                }
                *(uint32_t**)(intptr_t)(*(int32_t*)(iVar15 + 4) + 0x34) = puVar16;
                if (puVar16 == 0) {
                    return 0x8007000eu;
                }
                *(uint16_t*)(intptr_t)(*(int32_t*)(iVar15 + 4) + 0x50) = 1;
                *(uint16_t*)(intptr_t)(*(int32_t*)(iVar15 + 4) + 0x4e) =
                    *(uint16_t*)(intptr_t)(*(int32_t*)(iVar15 + 4) + 0x50);
                uVar6 = FUN_0063e97c(iVar10, 0, 0, puVar9, 0);
                if ((int32_t)uVar6 < 0) {
                    return uVar6;
                }
            }
            local_8 = local_8 + 1;
            *param_2 = *param_2 + 4;
        } while (local_8 < local_10);
    }
LAB_00648607:
    *param_1 = *param_1 + 0x14;
    return uVar6;
}

// ---- Additional observed helpers/labels used by the 0x64866e block ----
#include <cstdlib>
extern uint8_t LAB_0063e3eb[];
extern int32_t  FUN_0063ea6b(void* node, int32_t kind);
extern int32_t  FUN_0063f27d(void* node, int32_t kind);
extern int32_t  FUN_0063f23c(void* node, int32_t kind);
extern uint32_t FUN_0063ed81(uint32_t node, uint32_t index, char* out);
extern uint32_t FUN_0064d495(uint32_t node, char* path, char* out);
extern void     FUN_00647b9b(int32_t flags);
extern void     FUN_006440ac(int32_t kind);

// 0x64866e — observed shape
// Path lookup with a slow-path creator. First walks the node list hanging off
// the resolved record (head at +0x30 for one record kind, +0x3c for the other)
// comparing the path segment against each node's name; a full match returns
// ~node. A trailing '.' recurses through FUN_0064d495; a "[n]" index resolves
// through FUN_0063ed81. When nothing matches and bit1 of the flags word at
// self+0x118 is set, it materialises a new node (name copy, 7-dword header
// copy from self+0xc4, hash-bucket rehash at self+0xb0/self+0xa8 and
// self+0x11c/self+0x120) and reports ~newnode. Returns 0 for no match.
// NEEDS_MANUAL: pcVar11 carries both a char* and the (len+1) count in the
// corpus; the integer uses are cast explicitly so the count stays visible.
uint32_t FUN_0064866e(void* self_, void* param_1, char* param_2, char* param_3)
{
    uint8_t*  self = (uint8_t*)self_;
    uint16_t  uVar1;
    int32_t   iVar2;
    int32_t   iVar4;
    int32_t   iVar7;
    int32_t   iVar8;
    int32_t   iVar12;
    int32_t   iVar13;
    char      cVar3;
    uint32_t  uVar14;
    uint32_t  local_24 = 0;
    uint32_t* puVar5;
    int32_t*  piVar6;
    int32_t*  piVar9;
    int32_t*  piVar10;
    char*     pcVar11;
    char*     pcVar16;
    uint32_t* puVar15;
    uint32_t* puVar17;
    uint32_t* newObj;
    void*     local_20;
    void*     local_10;
    int32_t*  local_c;
    void*     local_8;

    if ((param_2 == 0) || (*param_2 == '\0')) {
        return 0;
    }
    iVar4 = FUN_0063ea6b(param_1, 10);
    if (iVar4 == 0) {
        iVar4 = FUN_0063f27d(param_1, 10);
        if ((iVar4 == 0) && (iVar4 = FUN_0063f23c(param_1, 10), iVar4 == 0)) {
            return 0;
        }
        piVar9 = (int32_t*)(intptr_t)(iVar4 + 0x2c);
        puVar5 = (uint32_t*)(intptr_t)(iVar4 + 0x30);
    }
    else {
        piVar9 = (int32_t*)(intptr_t)(iVar4 + 0x38);
        puVar5 = (uint32_t*)(intptr_t)(iVar4 + 0x3c);
    }
    param_1 = (void*)(intptr_t)*puVar5;
    local_20 = 0;
    if (param_1 != 0) {
        do {
            local_20 = param_1;
            uVar14 = ((uint32_t*)local_20)[5];
            iVar4 = ((int32_t*)local_20)[1];
            if (uVar14 < *(uint32_t*)(self + 0xac)) {
                if (*(int32_t*)(intptr_t)(*(int32_t*)(intptr_t)(*(int32_t*)(self + 0xb0) + uVar14 * 4) + 0x40) == 0) {
                    iVar12 = *(int32_t*)(self + 0x20);
                }
                else {
                    iVar12 = *(int32_t*)(intptr_t)(*(int32_t*)(self + 0x38) + 0x10);
                }
            }
            else {
                iVar12 = *(int32_t*)(intptr_t)(*(int32_t*)(self + 0x11c) + (uVar14 - *(uint32_t*)(self + 0xac)) * 4);
            }
            piVar6 = (int32_t*)(intptr_t)(iVar12 + *(int32_t*)(iVar4 + 8));
            piVar10 = 0;
            if (*piVar6 != 0) {
                piVar10 = piVar6 + 1;
            }
            for (pcVar11 = param_2; (*(char*)piVar10 == *pcVar11 && (*pcVar11 != '\0'));
                 pcVar11 = pcVar11 + 1) {
                piVar10 = (int32_t*)((intptr_t)piVar10 + 1);
            }
            cVar3 = *pcVar11;
            if (cVar3 == *(char*)piVar10) {
                return ~(uint32_t)(uintptr_t)local_20;
            }
            if (*(char*)piVar10 == '\0') {
                if (cVar3 == '.') {
                    pcVar11 = pcVar11 + 1;
                    uVar14 = ~(uint32_t)(uintptr_t)local_20;
                    goto LAB_006488a8;
                }
                if (cVar3 == '[') {
                    pcVar11 = pcVar11 + 1;
                    if (*pcVar11 < '0') {
                        return 0;
                    }
                    if ('9' < *pcVar11) {
                        return 0;
                    }
                    uVar14 = (uint32_t)atoi(pcVar11);
                    if (*(uint32_t*)(iVar4 + 0x10) <= uVar14) {
                        return 0;
                    }
                    for (; ('/' < *pcVar11 && (*pcVar11 < ':')); pcVar11 = pcVar11 + 1) {
                    }
                    if (*pcVar11 != ']') {
                        return 0;
                    }
                    uVar14 = FUN_0063ed81(~(uint32_t)(uintptr_t)local_20, uVar14, param_3);
                    if (uVar14 == 0) {
                        return 0;
                    }
                    if (pcVar11[1] == '\0') {
                        return uVar14;
                    }
                    if (pcVar11[1] != '.') {
                        return 0;
                    }
                    pcVar11 = pcVar11 + 2;
LAB_006488a8:
                    uVar14 = FUN_0064d495(uVar14, pcVar11, param_3);
                    return uVar14;
                }
            }
            param_1 = (void*)(intptr_t)((uint32_t*)local_20)[0x0f];
        } while ((void*)(intptr_t)((uint32_t*)local_20)[0x0f] != 0);
        param_1 = 0;
    }
    if ((*(uint8_t*)(self + 0x118) & 2) == 0) {
        return 0;
    }
    iVar4 = *(int32_t*)(self + 0x120);
    cVar3 = *param_2;
    local_24 = 0;
    local_c = 0;
    local_8 = 0;
    local_10 = 0;
    param_3 = 0;
    pcVar11 = param_2;
    do {
        if ((((cVar3 == '.') || (cVar3 == '@')) || (cVar3 == '[')) || (cVar3 == ']')) {
            goto LAB_00648bd9;
        }
        pcVar11 = pcVar11 + 1;
        cVar3 = *pcVar11;
    } while (cVar3 != '\0');
    pcVar11 = param_2;
    do {
        cVar3 = *pcVar11;
        pcVar11 = pcVar11 + 1;
    } while (cVar3 != '\0');
    pcVar11 = (char*)(intptr_t)((intptr_t)pcVar11 + (1 - (intptr_t)(param_2 + 1)));
    iVar12 = (int32_t)((((uint32_t)(uintptr_t)pcVar11 & 3) != 0) +
                       ((uint32_t)(uintptr_t)pcVar11 >> 2));
    iVar13 = iVar12 * 4;
    local_8 = (void*)FUN_00533c78(*(int32_t*)(self + 0xa8) * 4 + 4);
    if ((local_8 != 0) &&
        (local_10 = (void*)FUN_00533c78(*(int32_t*)(self + 0x120) * 4 + 4), local_10 != 0)) {
        iVar7 = (int32_t)(intptr_t)FUN_00533c78(0x50);
        if (iVar7 == 0) {
            param_1 = 0;
        }
        else {
            param_1 = FUN_00647b28();
        }
        if (param_1 == 0) {
            goto LAB_00648be7;
        }
        newObj = (uint32_t*)param_1;
        puVar15 = *(uint32_t**)(self + 0x11c);
        puVar17 = (uint32_t*)local_10;
        for (uVar14 = *(uint32_t*)(self + 0x120) & 0x3fffffff; uVar14 != 0; uVar14 = uVar14 - 1) {
            *puVar17 = *puVar15;
            puVar15 = puVar15 + 1;
            puVar17 = puVar17 + 1;
        }
        for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {   // inert byte tail
            *(uint8_t*)puVar17 = *(uint8_t*)puVar15;
            puVar15 = (uint32_t*)((intptr_t)puVar15 + 1);
            puVar17 = (uint32_t*)((intptr_t)puVar17 + 1);
        }
        ((uint32_t*)local_10)[*(int32_t*)(self + 0x120)] = 0;
        operator_delete(*(void**)(self + 0x11c));
        *(void**)(self + 0x11c) = local_10;
        *(int32_t*)(self + 0x120) = *(int32_t*)(self + 0x120) + 1;
        uVar1 = *(uint16_t*)(self + 0xa8);
        newObj[2] = 0xffffffffu;
        newObj[5] = (uint32_t)uVar1;
        newObj[0xb] = (uint32_t)(iVar13 + 4);
        newObj[10] = 4;
        newObj[6] = 0;
        newObj[7] = 0;
        piVar10 = *(int32_t**)(self + 0xc4);
        iVar7 = piVar10[1];
        iVar8 = *piVar10;
        iVar2 = piVar10[4];
        local_10 = 0;
        if (-1 < iVar7) {
            if (iVar7 < 4) {
                if (((iVar8 == 1) || (iVar8 == 2)) || (iVar8 == 3)) {
                    iVar7 = piVar10[6] * piVar10[5] * 4;
                    newObj[3] = 4;
                    newObj[3] = (uint32_t)iVar7;
                    if (iVar2 != 0) {
                        iVar8 = iVar7 * iVar2;
                        iVar7 = iVar7 * iVar2;
                        newObj[3] = (uint32_t)iVar8;
                    }
                    uVar14 = (uint32_t)(iVar7 + 0x20 + iVar13);
                    param_3 = (char*)FUN_00533c78(uVar14);
                    if (param_3 != 0) {
                        pcVar16 = param_3;
                        for (uVar14 = uVar14 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
                            pcVar16[0] = '\0';
                            pcVar16[1] = '\0';
                            pcVar16[2] = '\0';
                            pcVar16[3] = '\0';
                            pcVar16 = pcVar16 + 4;
                        }
                        for (iVar13 = 0; iVar13 != 0; iVar13 = iVar13 + -1) {
                            *pcVar16 = '\0';
                            pcVar16 = pcVar16 + 1;
                        }
                        puVar15 = *(uint32_t**)(self + 0xc4);
                        pcVar16 = param_3 + (iVar12 + 1) * 4;
                        for (iVar13 = 7; iVar13 != 0; iVar13 = iVar13 + -1) {
                            *(uint32_t*)pcVar16 = *puVar15;
                            puVar15 = puVar15 + 1;
                            pcVar16 = pcVar16 + 4;
                        }
                        newObj[0xc] = newObj[0xb] + 0x1c;
LAB_00648b0e:
                        local_c = 0;
                        *(char**)param_3 = pcVar11;
                        pcVar16 = param_3;
                        for (uVar14 = (uint32_t)(uintptr_t)pcVar11 >> 2;
                             pcVar16 = pcVar16 + 4, uVar14 != 0;
                             uVar14 = uVar14 - 1) {
                            *(uint32_t*)pcVar16 = *(uint32_t*)param_2;
                            param_2 = param_2 + 4;
                        }
                        for (uVar14 = (uint32_t)(uintptr_t)pcVar11 & 3; uVar14 != 0; uVar14 = uVar14 - 1) {
                            *pcVar16 = *param_2;
                            param_2 = param_2 + 1;
                            pcVar16 = pcVar16 + 1;
                        }
                        pcVar11 = param_3 + newObj[0xb] + 8;
                        pcVar11[0] = '\0';
                        pcVar11[1] = '\0';
                        pcVar11[2] = '\0';
                        pcVar11[3] = '\0';
                        pcVar11 = param_3 + newObj[0xb] + 0xc;
                        pcVar11[0] = '\0';
                        pcVar11[1] = '\0';
                        pcVar11[2] = '\0';
                        pcVar11[3] = '\0';
                        puVar15 = *(uint32_t**)(self + 0xb0);
                        puVar17 = (uint32_t*)local_8;
                        for (uVar14 = *(uint32_t*)(self + 0xa8) & 0x3fffffff; uVar14 != 0; uVar14 = uVar14 - 1) {
                            *puVar17 = *puVar15;
                            puVar15 = puVar15 + 1;
                            puVar17 = puVar17 + 1;
                        }
                        for (iVar12 = 0; iVar12 != 0; iVar12 = iVar12 + -1) {  // inert byte tail
                            *(uint8_t*)puVar17 = *(uint8_t*)puVar15;
                            puVar15 = (uint32_t*)((intptr_t)puVar15 + 1);
                            puVar17 = (uint32_t*)((intptr_t)puVar17 + 1);
                        }
                        ((uint32_t*)local_8)[*(int32_t*)(self + 0xa8)] = (uint32_t)(uintptr_t)param_1;
                        if (*(void**)(self + 0xb0) != 0) {
                            operator_delete(*(void**)(self + 0xb0));
                            *(uint32_t*)(self + 0xb0) = 0;
                        }
                        *(int32_t*)(self + 0xa8) = *(int32_t*)(self + 0xa8) + 1;
                        *(void**)(self + 0xb0) = local_8;
                        local_8 = 0;
                        if (local_20 == 0) {
                            *puVar5 = (uint32_t)(uintptr_t)param_1;
                        }
                        else {
                            ((uint32_t*)local_20)[0x0f] = (uint32_t)(uintptr_t)param_1;
                        }
                        *piVar9 = *piVar9 + 1;
                        newObj[1] = (uint32_t)(uintptr_t)(param_3 + newObj[0xb]);
                        *newObj = (uint32_t)(uintptr_t)(param_3 + newObj[0xc]);
                        local_24 = ~(uint32_t)(uintptr_t)param_1;
                        *(char**)(intptr_t)(*(int32_t*)(self + 0x11c) + iVar4 * 4) = param_3;
                        param_3 = 0;
                        param_1 = 0;
                    }
                }
            }
            else if (((iVar7 == 4) && (iVar2 == 0)) && (iVar8 == 4)) {
                param_3 = (char*)FUN_00533c78(iVar13 + 0x1cU);
                if (param_3 != 0) {
                    iVar12 = *(int32_t*)(self + 0x14) + 1;
                    piVar10 = (int32_t*)FUN_00533c78(iVar12 * 0x18 + 4);
                    if (piVar10 == 0) {
                        local_c = 0;
                    }
                    else {
                        local_c = piVar10 + 1;
                        *piVar10 = iVar12;
                        FUN_004127b0(local_c, 0x18, iVar12, (void*)LAB_0063e3eb);
                    }
                    if (local_c != 0) {
                        pcVar16 = param_3;
                        for (uVar14 = (iVar13 + 0x1cU) >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
                            pcVar16[0] = '\0';
                            pcVar16[1] = '\0';
                            pcVar16[2] = '\0';
                            pcVar16[3] = '\0';
                            pcVar16 = pcVar16 + 4;
                        }
                        for (iVar12 = 0; iVar12 != 0; iVar12 = iVar12 + -1) {
                            *pcVar16 = '\0';
                            pcVar16 = pcVar16 + 1;
                        }
                        piVar10 = local_c + *(int32_t*)(self + 0x14) * 6;
                        for (iVar12 = 6; iVar12 != 0; iVar12 = iVar12 + -1) {
                            *piVar10 = 0;
                            piVar10 = piVar10 + 1;
                        }
                        local_c[*(int32_t*)(self + 0x14) * 6] = 4;
                        piVar10 = *(int32_t**)(self + 0x18);
                        piVar6 = local_c;
                        for (uVar14 = (uint32_t)(*(int32_t*)(self + 0x14) * 0x18) >> 2; uVar14 != 0;
                             uVar14 = uVar14 - 1) {
                            *piVar6 = *piVar10;
                            piVar10 = piVar10 + 1;
                            piVar6 = piVar6 + 1;
                        }
                        for (iVar12 = 0; iVar12 != 0; iVar12 = iVar12 + -1) {
                            *(char*)piVar6 = (char)*piVar10;
                            piVar10 = (int32_t*)((intptr_t)piVar10 + 1);
                            piVar6 = (int32_t*)((intptr_t)piVar6 + 1);
                        }
                        newObj[3] = 4;
                        newObj[0xc] = newObj[0xb] + 0x14;
                        puVar15 = *(uint32_t**)(self + 0xc4);
                        pcVar16 = param_3 + newObj[0xb];
                        for (iVar12 = 5; iVar12 != 0; iVar12 = iVar12 + -1) {
                            *(uint32_t*)pcVar16 = *puVar15;
                            puVar15 = puVar15 + 1;
                            pcVar16 = pcVar16 + 4;
                        }
                        *(uint32_t*)(intptr_t)(param_3 + newObj[0xc]) = *(uint32_t*)(self + 0x14);
                        puVar15 = *(uint32_t**)(self + 0x18);
                        for (uVar14 = (uint32_t)(*(int32_t*)(self + 0x14) * 0x18) >> 2; uVar14 != 0;
                             uVar14 = uVar14 - 1) {
                            *puVar15 = 0;
                            puVar15 = puVar15 + 1;
                        }
                        for (iVar12 = 0; iVar12 != 0; iVar12 = iVar12 + -1) {
                            *(uint8_t*)puVar15 = 0;
                            puVar15 = (uint32_t*)((intptr_t)puVar15 + 1);
                        }
                        if (*(int32_t*)(self + 0x18) != 0) {
                            FUN_006440ac(3);
                            *(uint32_t*)(self + 0x18) = 0;
                        }
                        *(int32_t*)(self + 0x14) = *(int32_t*)(self + 0x14) + 1;
                        *(int32_t**)(self + 0x18) = local_c;
                        goto LAB_00648b0e;
                    }
                }
            }
        }
    }
LAB_00648bd9:
    if (param_1 != 0) {
        FUN_00647b9b(1);
    }
LAB_00648be7:
    if (local_8 != 0) {
        operator_delete(local_8);
    }
    if (local_10 != 0) {
        operator_delete(local_10);
    }
    if (local_c != 0) {
        FUN_006440ac(3);
    }
    if (param_3 != 0) {
        operator_delete(param_3);
    }
    return local_24;
}

// ---- Additional observed helpers/labels used by the 0x648c29..0x6492dc block ----
extern "C" unsigned int _controlfp(unsigned int newControl, unsigned int mask);
extern int32_t FUN_00646f4b(uint16_t id, uint32_t mode, bool flag, uint32_t* out);
extern int32_t FUN_00647193(uint16_t id, uint32_t mode, bool flag, uint32_t* out);

// 0x648c29 — observed shape
// Resolves a named resource record (FUN_0063f23c) and fills a 4-word out block:
// [0] record name pointer (or null), [1] record+0x2c, [2] left output,
// [3] right output. Two sub-queries are run with a mode that is 1 only when the
// record's 0x14/0x18 shorts both match the caller's 0x42/0x44 shorts, and a
// flag that is true when the 0x14 short matches the caller's 0x40 short.
// Finally restores the caller's FP control word when bit0 of +0x118 is set.
int32_t FUN_00648c29(int32_t param_1, uint32_t param_2, void* param_3_)
{
    uint32_t* out = (uint32_t*)param_3_;
    uint32_t* puVar1;
    uint32_t* puVar2;
    uint32_t* puVar6;
    int16_t   sVar3;
    int32_t   iVar4;
    int32_t*  piVar5;
    int32_t   iVar7;
    uint32_t  mode;
    bool      bVar8;

    if (param_3_ != 0) {
        iVar4 = FUN_0063f23c((void*)(intptr_t)param_2, 0);
        if (iVar4 != 0) {
            out[0] = 0;
            out[1] = 0;
            out[2] = 0;
            out[3] = 0;
            piVar5 = (int32_t*)(intptr_t)(*(int32_t*)(iVar4 + 0x28) + *(int32_t*)(param_1 + 0x20));
            if (*piVar5 == 0) {
                piVar5 = 0;
            }
            else {
                piVar5 = piVar5 + 1;
            }
            out[0] = (uint32_t)(uintptr_t)piVar5;
            out[1] = *(uint32_t*)(iVar4 + 0x2c);
            puVar1 = out + 2;
            puVar6 = out + 3;
            *puVar1 = 0;
            *puVar6 = 0;
            sVar3 = *(int16_t*)(iVar4 + 0x14);
            if ((sVar3 == *(int16_t*)(param_1 + 0x42)) &&
                (*(int16_t*)(iVar4 + 0x18) == *(int16_t*)(param_1 + 0x44))) {
                mode = 1;
            }
            else {
                mode = 0;
            }
            bVar8 = (sVar3 == *(int16_t*)(param_1 + 0x40));
            iVar7 = FUN_00646f4b(*(uint16_t*)(iVar4 + 0x34), mode, bVar8, puVar1);
            if (-1 < iVar7) {
                iVar7 = FUN_00647193(*(uint16_t*)(iVar4 + 0x34), mode, bVar8, puVar6);
            }
            goto LAB_00648cdf;
        }
    }
    iVar7 = -0x7789f794;
LAB_00648cdf:
    puVar2 = (uint32_t*)(intptr_t)(param_1 + 0x118);
    if ((*(uint8_t*)puVar2 & 1) != 0) {
        _controlfp(*(uint32_t*)(param_1 + 0x114), 0x30000);
        *puVar2 = *puVar2 & 0xfffffffe;
    }
    return iVar7;
}

// 0x648d0b — observed shape
// State transition to 3, rejected while the state is already 3 or 4. Drops the
// pending object at +0xf8 and re-arms the list tail to the sentinel at +0xe0.
uint32_t FUN_00648d0b(int32_t param_1)
{
    if ((*(int32_t*)(param_1 + 0x3c) == 4) || (*(int32_t*)(param_1 + 0x3c) == 3)) {
        return 0x8876086cu;
    }
    *(uint32_t*)(param_1 + 0x3c) = 3;
    if (*(int32_t*)(param_1 + 0xf8) != 0) {
        FUN_00647df7((void*)(intptr_t)*(int32_t*)(param_1 + 0xf8), 1);
        *(uint32_t*)(param_1 + 0xf8) = 0;
    }
    *(int32_t*)(param_1 + 0xfc) = param_1 + 0xe0;
    return 0;
}

// 0x648d5c — observed shape
// Builds a 0x1c-byte command node [0]=1, [1]=param_1, [3]=param_2 and links it
// at the tail of the deferred list (chain through +0x18, tail at +0xfc).
uint32_t FUN_00648d5c(void* self_, uint32_t param_1, uint32_t param_2)
{
    uint8_t*  self = (uint8_t*)self_;
    uint32_t  uVar3 = 0;
    int32_t   iVar1;
    uint32_t* puVar2;

    iVar1 = (int32_t)(intptr_t)FUN_00533c78(0x1c);
    if (iVar1 == 0) {
        puVar2 = 0;
    }
    else {
        puVar2 = (uint32_t*)FUN_006417d1();
    }
    if (puVar2 == 0) {
        uVar3 = 0x8007000eu;
    }
    else {
        puVar2[1] = param_1;
        puVar2[3] = param_2;
        *puVar2 = 1;
        *(uint32_t**)(intptr_t)(*(int32_t*)(self + 0xfc) + 0x18) = puVar2;
        *(int32_t*)(self + 0xfc) = (int32_t)(intptr_t)puVar2;
    }
    return uVar3;
}

// 0x648db0 — observed shape
// Same node build/link as 0x648d5c with command tag 5.
uint32_t FUN_00648db0(void* self_, uint32_t param_1, uint32_t param_2)
{
    uint8_t*  self = (uint8_t*)self_;
    uint32_t  uVar3 = 0;
    int32_t   iVar1;
    uint32_t* puVar2;

    iVar1 = (int32_t)(intptr_t)FUN_00533c78(0x1c);
    if (iVar1 == 0) {
        puVar2 = 0;
    }
    else {
        puVar2 = (uint32_t*)FUN_006417d1();
    }
    if (puVar2 == 0) {
        uVar3 = 0x8007000eu;
    }
    else {
        puVar2[1] = param_1;
        puVar2[3] = param_2;
        *puVar2 = 5;
        *(uint32_t**)(intptr_t)(*(int32_t*)(self + 0xfc) + 0x18) = puVar2;
        *(int32_t*)(self + 0xfc) = (int32_t)(intptr_t)puVar2;
    }
    return uVar3;
}

// 0x648e04 — observed shape
// Same node build/link as 0x648d5c with command tag 3.
uint32_t FUN_00648e04(void* self_, uint32_t param_1, uint32_t param_2)
{
    uint8_t*  self = (uint8_t*)self_;
    uint32_t  uVar3 = 0;
    int32_t   iVar1;
    uint32_t* puVar2;

    iVar1 = (int32_t)(intptr_t)FUN_00533c78(0x1c);
    if (iVar1 == 0) {
        puVar2 = 0;
    }
    else {
        puVar2 = (uint32_t*)FUN_006417d1();
    }
    if (puVar2 == 0) {
        uVar3 = 0x8007000eu;
    }
    else {
        puVar2[1] = param_1;
        puVar2[3] = param_2;
        *puVar2 = 3;
        *(uint32_t**)(intptr_t)(*(int32_t*)(self + 0xfc) + 0x18) = puVar2;
        *(int32_t*)(self + 0xfc) = (int32_t)(intptr_t)puVar2;
    }
    return uVar3;
}

// 0x648e58 — observed shape
// Command tag 2: copies param_3 dwords from param_2 into a fresh buffer that
// becomes node word 3. Node allocation failure returns 0x8007000e; buffer
// failure reports 0x8007000e and frees the node.
uint32_t FUN_00648e58(void* self_, uint32_t param_1, uint32_t* param_2, int32_t param_3)
{
    uint8_t*  self = (uint8_t*)self_;
    uint32_t  local_c = 0;
    uint32_t* local_8 = 0;
    uint32_t* puVar2;
    uint32_t* puVar3;
    int32_t   iVar1;

    iVar1 = (int32_t)(intptr_t)FUN_00533c78(0x1c);
    if (iVar1 == 0) {
        puVar2 = 0;
    }
    else {
        puVar2 = (uint32_t*)FUN_006417d1();
    }
    if (puVar2 == 0) {
        return 0x8007000eu;
    }
    if ((param_3 == 0) ||
        (local_8 = (uint32_t*)FUN_00533c78((uint32_t)param_3 << 2), local_8 != 0)) {
        puVar3 = local_8;
        for (iVar1 = param_3; iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
        }
        puVar2[1] = param_1;
        puVar2[2] = (uint32_t)param_3;
        puVar2[3] = (uint32_t)(uintptr_t)local_8;
        *puVar2 = 2;
        *(uint32_t**)(intptr_t)(*(int32_t*)(self + 0xfc) + 0x18) = puVar2;
        *(int32_t*)(self + 0xfc) = (int32_t)(intptr_t)puVar2;
        puVar2 = 0;
    }
    else {
        local_c = 0x8007000eu;
    }
    if (puVar2 != 0) {
        FUN_00647df7(puVar2, 1);
    }
    return local_c;
}

// 0x648f01 — observed shape
// Command tag 4: dword-array payload, otherwise identical to 0x648e58.
uint32_t FUN_00648f01(void* self_, uint32_t param_1, uint32_t* param_2, int32_t param_3)
{
    uint8_t*  self = (uint8_t*)self_;
    uint32_t  local_c = 0;
    uint32_t* local_8 = 0;
    uint32_t* puVar2;
    uint32_t* puVar3;
    int32_t   iVar1;

    iVar1 = (int32_t)(intptr_t)FUN_00533c78(0x1c);
    if (iVar1 == 0) {
        puVar2 = 0;
    }
    else {
        puVar2 = (uint32_t*)FUN_006417d1();
    }
    if (puVar2 == 0) {
        return 0x8007000eu;
    }
    if ((param_3 == 0) ||
        (local_8 = (uint32_t*)FUN_00533c78((uint32_t)param_3 << 2), local_8 != 0)) {
        puVar3 = local_8;
        for (iVar1 = param_3; iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
        }
        puVar2[1] = param_1;
        puVar2[2] = (uint32_t)param_3;
        puVar2[3] = (uint32_t)(uintptr_t)local_8;
        *puVar2 = 4;
        *(uint32_t**)(intptr_t)(*(int32_t*)(self + 0xfc) + 0x18) = puVar2;
        *(int32_t*)(self + 0xfc) = (int32_t)(intptr_t)puVar2;
        puVar2 = 0;
    }
    else {
        local_c = 0x8007000eu;
    }
    if (puVar2 != 0) {
        FUN_00647df7(puVar2, 1);
    }
    return local_c;
}

// 0x648faa — observed shape
// Command tag 6: dword-array payload, otherwise identical to 0x648e58.
uint32_t FUN_00648faa(void* self_, uint32_t param_1, uint32_t* param_2, int32_t param_3)
{
    uint8_t*  self = (uint8_t*)self_;
    uint32_t  local_c = 0;
    uint32_t* local_8 = 0;
    uint32_t* puVar2;
    uint32_t* puVar3;
    int32_t   iVar1;

    iVar1 = (int32_t)(intptr_t)FUN_00533c78(0x1c);
    if (iVar1 == 0) {
        puVar2 = 0;
    }
    else {
        puVar2 = (uint32_t*)FUN_006417d1();
    }
    if (puVar2 == 0) {
        return 0x8007000eu;
    }
    if ((param_3 == 0) ||
        (local_8 = (uint32_t*)FUN_00533c78((uint32_t)param_3 << 2), local_8 != 0)) {
        puVar3 = local_8;
        for (iVar1 = param_3; iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
        }
        puVar2[1] = param_1;
        puVar2[2] = (uint32_t)param_3;
        puVar2[3] = (uint32_t)(uintptr_t)local_8;
        *puVar2 = 6;
        *(uint32_t**)(intptr_t)(*(int32_t*)(self + 0xfc) + 0x18) = puVar2;
        *(int32_t*)(self + 0xfc) = (int32_t)(intptr_t)puVar2;
        puVar2 = 0;
    }
    else {
        local_c = 0x8007000eu;
    }
    if (puVar2 != 0) {
        FUN_00647df7(puVar2, 1);
    }
    return local_c;
}

// 0x649053 — observed shape
// Command tag 7: fixed 0x10-byte (4 dword) payload copied verbatim. A payload
// allocation failure leaves the node alive only for the error path to free.
uint32_t FUN_00649053(void* self_, uint32_t param_1, uint32_t* param_2)
{
    uint8_t*  self = (uint8_t*)self_;
    uint32_t  local_8 = 0;
    uint32_t* puVar2;
    uint32_t* puVar3;
    int32_t   iVar1;

    iVar1 = (int32_t)(intptr_t)FUN_00533c78(0x1c);
    if (iVar1 == 0) {
        puVar2 = 0;
    }
    else {
        puVar2 = (uint32_t*)FUN_006417d1();
    }
    if (puVar2 == 0) {
        local_8 = 0x8007000eu;
    }
    else {
        puVar3 = (uint32_t*)FUN_00533c78(0x10);
        if (puVar3 == 0) {
            local_8 = 0x8007000eu;
        }
        else {
            puVar3[0] = param_2[0];
            puVar3[1] = param_2[1];
            puVar3[2] = param_2[2];
            puVar3[3] = param_2[3];
            puVar2[3] = (uint32_t)(uintptr_t)puVar3;
            *puVar2 = 7;
            puVar2[1] = param_1;
            *(uint32_t**)(intptr_t)(*(int32_t*)(self + 0xfc) + 0x18) = puVar2;
            *(int32_t*)(self + 0xfc) = (int32_t)(intptr_t)puVar2;
            puVar2 = 0;
        }
        if (puVar2 != 0) {
            FUN_00647df7(puVar2, 1);
        }
    }
    return local_8;
}

// 0x6490df — observed shape
// Command tag 8: count param_3 with a 16-byte-per-element payload; the copy
// loop runs (param_3 & 0x0fffffff) << 2 dwords, i.e. the low 28 bits of the
// count at four dwords each. The trailing byte loop is the corpus's zero tail.
uint32_t FUN_006490df(void* self_, uint32_t param_1, uint32_t* param_2, uint32_t param_3)
{
    uint8_t*  self = (uint8_t*)self_;
    uint32_t  local_c = 0;
    uint32_t* local_8 = 0;
    uint32_t* puVar2;
    uint32_t* puVar3;
    int32_t   iVar1;

    iVar1 = (int32_t)(intptr_t)FUN_00533c78(0x1c);
    if (iVar1 == 0) {
        puVar2 = 0;
    }
    else {
        puVar2 = (uint32_t*)FUN_006417d1();
    }
    if (puVar2 == 0) {
        return 0x8007000eu;
    }
    if ((param_3 == 0) ||
        (local_8 = (uint32_t*)FUN_00533c78(param_3 << 4), local_8 != 0)) {
        puVar3 = local_8;
        for (iVar1 = (int32_t)((param_3 & 0x0fffffffu) << 2); iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
        }
        for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {   // inert byte tail
            *(uint8_t*)puVar3 = *(uint8_t*)param_2;
            param_2 = (uint32_t*)((intptr_t)param_2 + 1);
            puVar3 = (uint32_t*)((intptr_t)puVar3 + 1);
        }
        puVar2[1] = param_1;
        puVar2[2] = param_3;
        puVar2[3] = (uint32_t)(uintptr_t)local_8;
        *puVar2 = 8;
        *(uint32_t**)(intptr_t)(*(int32_t*)(self + 0xfc) + 0x18) = puVar2;
        *(int32_t*)(self + 0xfc) = (int32_t)(intptr_t)puVar2;
        puVar2 = 0;
    }
    else {
        local_c = 0x8007000eu;
    }
    if (puVar2 != 0) {
        FUN_00647df7(puVar2, 1);
    }
    return local_c;
}

// 0x649197 — observed shape
// Command tag 9: fixed 0x40-byte (16 dword) payload copied verbatim
// (matrix-sized block).
uint32_t FUN_00649197(void* self_, uint32_t param_1, uint32_t* param_2)
{
    uint8_t*  self = (uint8_t*)self_;
    uint32_t  local_8 = 0;
    uint32_t* puVar2;
    uint32_t* puVar3;
    uint32_t* puVar4;
    int32_t   iVar1;

    iVar1 = (int32_t)(intptr_t)FUN_00533c78(0x1c);
    if (iVar1 == 0) {
        puVar2 = 0;
    }
    else {
        puVar2 = (uint32_t*)FUN_006417d1();
    }
    if (puVar2 == 0) {
        local_8 = 0x8007000eu;
    }
    else {
        puVar3 = (uint32_t*)FUN_00533c78(0x40);
        if (puVar3 == 0) {
            local_8 = 0x8007000eu;
        }
        else {
            puVar4 = puVar3;
            for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
                *puVar4 = *param_2;
                param_2 = param_2 + 1;
                puVar4 = puVar4 + 1;
            }
            puVar2[3] = (uint32_t)(uintptr_t)puVar3;
            *puVar2 = 9;
            puVar2[1] = param_1;
            *(uint32_t**)(intptr_t)(*(int32_t*)(self + 0xfc) + 0x18) = puVar2;
            *(int32_t*)(self + 0xfc) = (int32_t)(intptr_t)puVar2;
            puVar2 = 0;
        }
        if (puVar2 != 0) {
            FUN_00647df7(puVar2, 1);
        }
    }
    return local_8;
}

// 0x649224 — observed shape
// Command tag 10: count param_3 with a 64-byte-per-element payload; copies
// (param_3 & 0x03ffffff) << 4 dwords.
uint32_t FUN_00649224(void* self_, uint32_t param_1, uint32_t* param_2, uint32_t param_3)
{
    uint8_t*  self = (uint8_t*)self_;
    uint32_t  local_c = 0;
    uint32_t* local_8 = 0;
    uint32_t* puVar2;
    uint32_t* puVar3;
    int32_t   iVar1;

    iVar1 = (int32_t)(intptr_t)FUN_00533c78(0x1c);
    if (iVar1 == 0) {
        puVar2 = 0;
    }
    else {
        puVar2 = (uint32_t*)FUN_006417d1();
    }
    if (puVar2 == 0) {
        return 0x8007000eu;
    }
    if ((param_3 == 0) ||
        (local_8 = (uint32_t*)FUN_00533c78(param_3 << 6), local_8 != 0)) {
        puVar3 = local_8;
        for (iVar1 = (int32_t)((param_3 & 0x03ffffffu) << 4); iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
        }
        for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {   // inert byte tail
            *(uint8_t*)puVar3 = *(uint8_t*)param_2;
            param_2 = (uint32_t*)((intptr_t)param_2 + 1);
            puVar3 = (uint32_t*)((intptr_t)puVar3 + 1);
        }
        puVar2[1] = param_1;
        puVar2[2] = param_3;
        puVar2[3] = (uint32_t)(uintptr_t)local_8;
        *puVar2 = 10;
        *(uint32_t**)(intptr_t)(*(int32_t*)(self + 0xfc) + 0x18) = puVar2;
        *(int32_t*)(self + 0xfc) = (int32_t)(intptr_t)puVar2;
        puVar2 = 0;
    }
    else {
        local_c = 0x8007000eu;
    }
    if (puVar2 != 0) {
        FUN_00647df7(puVar2, 1);
    }
    return local_c;
}

// 0x6492dc — observed shape
// Command tag 10 with per-element indirection: param_2 is an array of param_3
// pointers, each pointing at a 0x40-byte (16 dword) block that is copied into
// the contiguous payload.
uint32_t FUN_006492dc(void* self_, uint32_t param_1, int32_t param_2, uint32_t param_3)
{
    uint8_t*  self = (uint8_t*)self_;
    uint32_t  local_c = 0;
    uint32_t* local_8 = 0;
    uint32_t* puVar2;
    uint32_t  uVar3;
    int32_t   iVar1;
    int32_t   iVar4;
    uint32_t* puVar5;
    uint32_t* puVar6;
    uint32_t* puVar7;

    iVar1 = (int32_t)(intptr_t)FUN_00533c78(0x1c);
    if (iVar1 == 0) {
        puVar2 = 0;
    }
    else {
        puVar2 = (uint32_t*)FUN_006417d1();
    }
    if (puVar2 == 0) {
        local_c = 0x8007000eu;
    }
    else {
        if ((param_3 == 0) ||
            (local_8 = (uint32_t*)FUN_00533c78(param_3 << 6), local_8 != 0)) {
            uVar3 = 0;
            if (param_3 != 0) {
                puVar5 = local_8;
                do {
                    iVar1 = (int32_t)(uVar3 * 4);
                    uVar3 = uVar3 + 1;
                    puVar6 = *(uint32_t**)(intptr_t)(param_2 + iVar1);
                    puVar7 = puVar5;
                    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
                        *puVar7 = *puVar6;
                        puVar6 = puVar6 + 1;
                        puVar7 = puVar7 + 1;
                    }
                    puVar5 = puVar5 + 0x10;
                } while (uVar3 < param_3);
            }
            puVar2[1] = param_1;
            puVar2[2] = param_3;
            puVar2[3] = (uint32_t)(uintptr_t)local_8;
            *puVar2 = 10;
            *(uint32_t**)(intptr_t)(*(int32_t*)(self + 0xfc) + 0x18) = puVar2;
            *(int32_t*)(self + 0xfc) = (int32_t)(intptr_t)puVar2;
            puVar2 = 0;
        }
        else {
            local_c = 0x8007000eu;
        }
        if (puVar2 != 0) {
            FUN_00647df7(puVar2, 1);
        }
    }
    return local_c;
}
